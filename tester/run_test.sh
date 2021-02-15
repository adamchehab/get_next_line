# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_test.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abronn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 11:27:00 by jvan-sni          #+#    #+#              #
#    Updated: 2021/02/15 15:52:38 by abronn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# config
TESTFOLDER="tests/normal/"
ADVANCEDFOLDER="tests/bonus/"
ADVANCEDTEST="1.txt 2.txt"
ANSWERFOLDER="../../answers/normal/"
ADVANCEDANSWERFOLDER="../../answers/bonus/"

# colors
GREEN="\033[92m"
MUTED="\033[1;30m"
RESET="\033[0m"
BOLD="\033[1m"

echo "$1"

# normal tests
echo "${MUTED}-----------------------------------${RESET}"
cd $TESTFOLDER
for FILE in *; do
	if [ -f "${FILE}" ]; then
		# run single test with open()
		printf "${GREEN}▹ Test \"${RESET}${BOLD}${FILE}${GREEN}\":${RESET}\n\n"
		../../a.out ${FILE} > temp
		sh ../../test.sh ${FILE} ${ANSWERFOLDER}${FILE}
		
		if [ "${FILE}" != "INVALID_FD" ]; then
			# run single test with stdin
			cat ${FILE} | ../../a.out > temp
			sh ../../test.sh ${FILE} ${ANSWERFOLDER}${FILE}
			echo ""
		fi
	fi
done
cd ../../

