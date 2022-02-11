int main ( int V_1 , char * V_2 [] )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
char * V_5 = NULL , * V_6 = NULL , * V_7 = NULL ;
T_2 V_8 ;
char V_9 [ V_10 ] ;
int V_11 = 0 , V_12 ;
char * * V_13 ;
unsigned char V_14 [ V_15 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_16;
V_5 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_16;
V_6 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_16;
V_7 = * ( ++ V_2 ) ;
}
else
{
fprintf ( V_17 , L_4 , * V_2 ) ;
V_11 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_11 )
{
V_16:
for ( V_13 = V_18 ; ( * V_13 != NULL ) ; V_13 ++ )
fprintf ( V_17 , L_5 , * V_13 ) ;
exit ( 1 ) ;
}
if ( V_5 == NULL )
V_3 = V_19 ;
else
{
V_3 = fopen ( V_5 , L_6 ) ;
if ( V_3 == NULL )
{
perror ( L_7 ) ;
exit ( 1 ) ;
}
}
if ( V_6 == NULL )
V_4 = stdout ;
else
{
V_4 = fopen ( V_6 , L_8 ) ;
if ( V_4 == NULL )
{
perror ( L_7 ) ;
exit ( 1 ) ;
}
}
#ifdef F_1
{
#include <fcntl.h>
F_2 ( fileno ( V_3 ) , V_20 ) ;
F_2 ( fileno ( V_4 ) , V_20 ) ;
}
#endif
if ( V_7 == NULL )
{
V_12 = F_3 ( V_9 , V_10 , L_9 , 0 ) ;
if ( V_12 != 0 )
{
F_4 ( V_9 , V_10 ) ;
fprintf ( V_17 , L_10 ) ;
exit ( 1 ) ;
}
V_7 = V_9 ;
}
F_5 ( ( unsigned char * ) V_7 , ( unsigned long ) strlen ( V_7 ) , V_14 , NULL , F_6 () ) ;
F_4 ( V_7 , strlen ( V_7 ) ) ;
F_7 ( & V_8 , V_15 , V_14 ) ;
for(; ; )
{
V_12 = fread ( V_9 , 1 , V_10 , V_3 ) ;
if ( V_12 == 0 ) break;
if ( V_12 < 0 )
{
perror ( L_11 ) ;
exit ( 1 ) ;
}
F_8 ( & V_8 , ( unsigned int ) V_12 , ( unsigned char * ) V_9 ,
( unsigned char * ) V_9 ) ;
V_12 = fwrite ( V_9 , ( unsigned int ) V_12 , 1 , V_4 ) ;
if ( V_12 != 1 )
{
perror ( L_12 ) ;
exit ( 1 ) ;
}
}
fclose ( V_4 ) ;
fclose ( V_3 ) ;
exit ( 0 ) ;
return ( 1 ) ;
}
