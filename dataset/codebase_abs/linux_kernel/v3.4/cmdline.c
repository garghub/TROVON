static char * T_1 F_1 ( char * V_1 )
{
char * V_2 ;
int V_3 , V_4 ;
V_3 = 1 ;
while ( V_3 < V_5 ) {
for( V_4 = 0 ; V_4 < F_2 ( V_6 ) ; V_4 ++ ) {
int V_7 = strlen ( V_6 [ V_4 ] [ 0 ] ) ;
if ( ! strncmp ( F_3 ( V_3 ) , V_6 [ V_4 ] [ 0 ] , V_7 ) ) {
strcat ( V_1 , V_6 [ V_4 ] [ 1 ] ) ;
V_1 += strlen ( V_6 [ V_4 ] [ 1 ] ) ;
V_2 = strchr ( F_3 ( V_3 ) , '=' ) ;
if ( V_2 ) {
V_2 ++ ;
strcpy ( V_1 , V_2 ) ;
V_1 += strlen ( V_2 ) ;
}
* V_1 ++ = ' ' ;
break;
}
}
V_3 ++ ;
}
return V_1 ;
}
void T_1 F_4 ( void )
{
char * V_1 ;
int V_3 , V_4 ;
V_3 = 1 ;
V_1 = V_8 ;
V_1 = F_1 ( V_1 ) ;
while ( V_3 < V_5 ) {
for ( V_4 = 0 ; V_4 < F_2 ( V_9 ) ; V_4 ++ ) {
int V_7 = strlen ( V_9 [ V_4 ] ) ;
if ( ! strncmp ( F_3 ( V_3 ) , V_9 [ V_4 ] , V_7 ) )
goto V_10;
}
strcpy ( V_1 , F_3 ( V_3 ) ) ;
V_1 += strlen ( F_3 ( V_3 ) ) ;
* V_1 ++ = ' ' ;
V_10:
V_3 ++ ;
}
if ( V_1 != V_8 )
-- V_1 ;
* V_1 = '\0' ;
#ifdef F_5
F_6 ( V_11 L_1 , V_8 ) ;
#endif
}
