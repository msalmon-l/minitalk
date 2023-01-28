# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 00:56:47 by msalmon-          #+#    #+#              #
#    Updated: 2023/01/28 17:55:39 by msalmon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

SRCS_C	= ft_putnbr_fd.c client.c ft_atoi.c
SRCS_S	= server.c ft_putnbr_fd.c

OBJS_C	= ${SRCS_C:.c=.o}
OBJS_S	= ${SRCS_S:.c=.o}

CLIENT	= client
SERVER	= server

all:	${CLIENT} ${SERVER}
${CLIENT}:	${OBJS_C}
			${CC} ${CFLAGS} ${OBJS_C} -o ${CLIENT}

${SERVER}:	${OBJS_S}
			${CC} ${CFLAGS} ${OBJS_S} -o ${SERVER}


clean:
			${RM} ${OBJS_C} ${OBJS_S}

fclean:		clean
			${RM} ${SERVER} ${CLIENT}

re:			fclean all

.PHONY:		clean fclean re all
