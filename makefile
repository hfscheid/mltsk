tmin: time_logger time_interval
	g++ time_logging/tmin.cpp time_logging/time_logger.o time_logging/time_interval.o -o tmin

tmout: time_logger time_interval
	g++ time_logging/tmout.cpp time_logging/time_logger.o time_logging/time_interval.o -o tmout

time_logger: time_interval
	g++ -c time_logging/time_logger.cpp time_logging/time_interval.o -o time_logging/time_logger.o

time_interval:
	g++ -c time_logging/time_interval.cpp -o time_logging/time_interval.o

test: tmin tmout
	rm time_logging/*.o

cleanup:
	rm ./tmin ./tmout

install: tmin tmout
	mkdir ~/.mtsk
	mv tmin $(HOME)/.local/bin/
	mv tmout $(HOME)/.local/bin/
