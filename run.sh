#!/bin/bash

green="\033[0;32m"
red="\033[0;31m"
reset="\033[0m"

echo -e "${green}==> Cleaning previous builds...${reset}"
make clean

echo -e "${green}==> Compiling project...${reset}"
make

if [[ $? -ne 0 ]]; then
echo -e "${red}❌ Compilation failed. Check the source code.${reset}"
exit 1
fi

echo -e "${green}==> Running THREAD version...${reset}"
./thread | tee results/thread_output.txt

echo -e "${green}==> Running PROCESS version...${reset}"
./process | tee results/process_output.txt

echo -e "${green}✅ Execution finished.${reset}"
echo -e "${green}📄 Results saved to 'results/' directory${reset}"
echo -e "${green} - thread_output.txt (thread console output)${reset}"
echo -e "${green} - process_output.txt (process console output)${reset}"