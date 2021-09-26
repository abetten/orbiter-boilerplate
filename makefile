all: 
	cd cs1; $(MAKE) all
	cd ff1; $(MAKE) all
	cd grp1; $(MAKE) all
	

clean: 
	cd cs1; $(MAKE) clean
	cd ff1; $(MAKE) clean
	cd grp1; $(MAKE) clean

install: 
	cd cs1; $(MAKE) install
	cd ff1; $(MAKE) install
	cd grp1; $(MAKE) install
