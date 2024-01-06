/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:49:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/06 16:01:26 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int main()
{
	char *c = "hello";
	char *d = "hello2";
	char *b = strdup("hello");
	char *b2 = strdup("hello");
	char *b3 = strdup("hello");
	char *b4 = strdup("hello");
	printf("%p\n%p\n%p\n", c,b,d);
	printf("%p\n%p\n%p", b2,b3,b4);
	free(b);
	free(b2);
	free(b3);
	free(b4);
}