#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = GameOfLife

#--- Inputs ----#
PROJECT_HOME_DIR = ..
CPPUTEST_HOME = $(PROJECT_HOME_DIR)/cpputest

SRC_FILES = $(PROJECT_HOME_DIR)/src/GameOfLife.cpp

TEST_SRC_FILES = AllTests.cpp UT_GameOfLife.cpp

INCLUDE_DIRS =\
	.\
	$(CPPUTEST_HOME)/include/ \
	$(CPPUTEST_HOME)/include/Platforms/Gcc \
	$(PROJECT_HOME_DIR)/src

#CPPUTEST_WARNINGFLAGS = -Wall -Werror -Wswitch-default -Wfatal-errors
#CPPUTEST_CXXFLAGS = -std=c++11
#CPPUTEST_CFLAGS = -std=c99

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
