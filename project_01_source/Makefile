# GNU Make: Linux / WSL, C++14; building this starter does NOT prove Lab01 algorithms.
CXX ?= g++
CXXFLAGS ?= -std=c++14 -O2 -Wall -Wextra -Wpedantic
CPPFLAGS ?= -I. -Ilib/fips202

SOURCES = u512.cpp modular.cpp prime.cpp dh.cpp
PRNG_SOURCES = lib/fips202/prng.cpp lib/fips202/fips202.c
BIN_DIR = bin
BIN = $(BIN_DIR)/lab01
TEST_BIN = $(BIN_DIR)/test_scaffold

.PHONY: all run test clean
all: $(BIN)

$(BIN): $(SOURCES) main.cpp $(PRNG_SOURCES) u512_sample.h dh_sample.h u512_utils.h modular.h prime.h dh.h
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) main.cpp $(PRNG_SOURCES) -o $(BIN)

$(TEST_BIN): $(SOURCES) tests/test_scaffold.cpp $(PRNG_SOURCES) u512_sample.h dh_sample.h u512_utils.h modular.h prime.h dh.h
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) tests/test_scaffold.cpp $(PRNG_SOURCES) -o $(TEST_BIN)

run: $(BIN)
	./$(BIN) --help

test: $(BIN) $(TEST_BIN)
	./$(TEST_BIN)
	./$(BIN) --help > /dev/null
	./$(BIN) --check-prng > /dev/null
	@echo 'PASS: starter smoke checks (NOT a completed crypto implementation)'

clean:
	rm -rf $(BIN_DIR)
