int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 = NULL ;
T_3 V_5 ;
unsigned int V_6 = 0 , V_7 , V_8 ;
unsigned char V_9 [ 1024 * 15 ] ;
char * V_10 , * V_11 = NULL , * V_12 = NULL , * V_13 = NULL ;
int V_14 = 0 ;
F_1 () ;
V_10 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_15;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_15;
V_11 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_15;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
V_6 = 1 ;
else
{
F_2 ( V_16 , L_5 , * V_2 ) ;
V_14 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_14 )
{
V_15:
F_2 ( V_16 , L_6 , V_10 ) ;
F_2 ( V_16 , L_7 ) ;
EXIT ( 1 ) ;
}
if ( V_13 == NULL )
{ F_2 ( V_16 , L_8 ) ; EXIT ( 1 ) ; }
V_3 = fopen ( V_13 , L_9 ) ;
if ( V_3 == NULL ) { perror ( V_13 ) ; EXIT ( 1 ) ; }
V_4 = F_3 ( V_3 , NULL , NULL ) ;
if ( V_4 == NULL )
{
F_2 ( V_16 , L_10 ) ;
F_4 ( V_16 ) ;
EXIT ( 1 ) ;
}
fclose ( V_3 ) ;
F_5 ( & V_5 , F_6 () ) ;
for (; ; )
{
V_7 = fread ( V_9 , 1 , 1024 * 10 , V_17 ) ;
if ( V_7 <= 0 ) break;
F_7 ( & V_5 , V_9 , V_7 ) ;
}
if ( ! F_8 ( & V_5 , V_9 , & V_8 , V_4 ) ) goto V_18;
F_2 ( V_16 , L_11 , V_9 ) ;
EXIT ( 0 ) ;
V_18:
F_4 ( V_16 ) ;
EXIT ( 1 ) ;
}
