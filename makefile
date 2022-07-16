tmin:
	g++ tmin.cpp -o tmin
	mv tmin $(HOME)/.local/bin/

tmout:
	g++ tmout.cpp -o tmout
	mv tmout $(HOME)/.local/bin/

install: tmin tmout
