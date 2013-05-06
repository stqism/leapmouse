OS := $(shell uname)
ARCH := $(shell uname -m)

ifeq ($(OS), Linux)
  ifeq ($(ARCH), x86_64)
    LEAP_LIBRARY := libLeap.so
  else
    LEAP_LIBRARY := x86/libLeap.so
  endif

LeapMouse: main.cpp
	$(CXX) -lX11 main.cpp -o LeapMouse $(LEAP_LIBRARY)
endif
