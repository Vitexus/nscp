#include "schedules_handler.hpp"

namespace schedules {

	target_object scheduler::get(int id) {
		boost::mutex::scoped_lock l(tasks.get_mutex());
		return metadata[id];
	}

	void scheduler::start() {
		tasks.set_handler(this);
		tasks.start();
	}
	void scheduler::stop() {
		tasks.stop();
		tasks.unset_handler();
	}

	void scheduler::clear() {
		tasks.clear_tasks();
		{
			boost::mutex::scoped_lock l(tasks.get_mutex());
			metadata.clear();
		}
	}


	boost::posix_time::seconds parse_interval(const std::string &str) {
		if (str.empty())
			return boost::posix_time::seconds(0);
		return boost::posix_time::seconds(strEx::stoui_as_time_sec(str, 1));
	}

	void scheduler::add_task(const target_object target) {
		unsigned int id = -1;
		if (target->duration)
			id = tasks.add_task(target->get_alias(), *target->duration);
		else if (target->schedule)
			id = tasks.add_task(target->get_alias(), cron_parser::parse(*target->schedule));
		else
			id = tasks.add_task(target->get_alias(), parse_interval("5m"));
		if (id == -1)
			return;
		{
			boost::mutex::scoped_lock l(tasks.get_mutex());
			metadata[id] = target;
		}
	}

}