#!/bin/bash

#compile and run reports
make run-reports

# Compile and run daemon
make run-daemon

# Compile and run collect
make run-collect

# Compile and run backup
make run-backup

# Compile and run lock
make run-lock

#compile and run reports to check for lock function
make run-reports

# Compile and run unlock
make run-unlock

#compile and run reports to check for lock function
make run-reports

# Compile and run check
make run-check


