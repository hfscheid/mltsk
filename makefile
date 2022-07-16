tmin: time_logger
	g++ time_logging/tmin.cpp time_logging/time_logger.o -o tmin

tmout: time_logger
	g++ time_logging/tmout.cpp time_logging/time_logger.o -o tmout

time_logger:
	g++ -c time_logging/time_logger.cpp -o time_logging/time_logger.o

test: tmin tmout
	rm time_logging/time_logger.o

cleanup:
	rm ./tmin ./tmout

install: tmin tmout
	mkdir ~/.mtsk
	mv tmin $(HOME)/.local/bin/
	mv tmout $(HOME)/.local/bin/
