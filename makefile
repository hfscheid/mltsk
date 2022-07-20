tmin: time_logger time_interval
	g++ time_logging/tmin.cpp time_logging/time_logger.o time_logging/time_interval.o -o tmin

tmon: time_logger time_interval
	g++ time_logging/tmon.cpp time_logging/time_logger.o time_logging/time_interval.o -o tmon

tmout: time_logger time_interval
	g++ time_logging/tmout.cpp time_logging/time_logger.o time_logging/time_interval.o -o tmout

tmall: time_logger time_interval
	g++ time_logging/tmall.cpp time_logging/time_logger.o time_logging/time_interval.o -o tmall

time_logger: time_interval
	g++ -c time_logging/time_logger.cpp time_logging/time_interval.o -o time_logging/time_logger.o

time_interval:
	g++ -c time_logging/time_interval.cpp -o time_logging/time_interval.o

test: tmin tmon tmout tmall
	rm time_logging/*.o

cleanup:
	rm ./tmin ./tmon ./tmout ./tmall

install: tmin tmon
	mkdir ~/.mtsk
	mv tmin $(HOME)/.local/bin/
	mv tmon $(HOME)/.local/bin/
