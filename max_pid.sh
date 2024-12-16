#!/bin/bash
# Script pour afficher la valeur maximale d'un PID
pid_max=$(cat /proc/sys/kernel/pid_max)
echo "La valeur maximale qu'un PID peut atteindre est : $pid_max"
