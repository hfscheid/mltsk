tmin: time_logger
	g++ tmin.cpp time_logger.o -o tmin

tmout: time_logger
	g++ tmout.cpp time_logger.o -o tmout

time_logger:
	g++ -c time_logger.cpp

test: tmin tmout
	rm time_logger.o

cleanup:
	rm ./tmin ./tmout

install: tmin tmout
	mv tmin $(HOME)/.local/bin/
	mv tmout $(HOME)/.local/bin/
