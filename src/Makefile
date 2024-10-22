CC=g++ 
STRICT_CFLAGS= -Wall -std=c++17 -Wextra -pedantic -Werror 


GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
GCOVR_LFLAGS=-lgcov


GTEST_LFLAGS=-lgtest -lgtest_main

REPORT_DIRECTORY=report

all: Vector3D.a Segment3D.a test gcov_report

Vector3D.a: Vector3D.oa 
		ar rcs $@ $^

Segment3D.a: Segment3D.oa 
		ar rcs $@ $^

tests/test.o: tests/test.cc Vector3D.h Segment3D.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
test: tests/tests_main.exe
		./tests/tests_main.exe

gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details --exclude-lines-by-pattern '.*assert.*' -o $(REPORT_DIRECTORY)/coverage_report.html
		xdg-open $(REPORT_DIRECTORY)/coverage_report.html || open $(REPORT_DIRECTORY)/coverage_report.html  

tests/tests_main.exe: Vector3D.o Segment3D.o tests/test.o
		$(CC) -o $@ $^ $(GTEST_LFLAGS) $(GCOVR_LFLAGS)

Vector3D.o: Vector3D.cc Vector3D.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

Vector3D.oa: Vector3D.cc Vector3D.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@

Segment3D.o: Segment3D.cc Segment3D.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

Segment3D.oa: Segment3D.cc Segment3D.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@

clean:
		rm -rf *.o *.exe *.out *.oa *.a
		rm -rf tests/*.o tests/*.exe tests/*.out
		rm -rf *.gcno *.gcda
		rm -rf $(REPORT_DIRECTORY)/*.css $(REPORT_DIRECTORY)/*.html $(REPORT_DIRECTORY)
