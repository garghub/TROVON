int main ( int V_1 , char * V_2 [] )
{
if ( ( V_1 == 2 ) )
{
F_1 ( V_2 [ 1 ] , V_3 ) ;
}
else if ( ( V_1 == 3 ) && ! strcmp ( V_2 [ 1 ] , L_1 ) )
{
F_1 ( V_2 [ 2 ] , V_4 ) ;
}
else
{
fprintf ( V_5 , L_2 , V_6 ) ;
exit ( 1 ) ;
}
return 0 ;
}
void F_1 ( char * V_7 , int V_8 )
{
char V_9 [ V_10 ] ;
char V_11 [ V_10 + 8 ] ;
unsigned int V_12 ;
unsigned char V_13 [ V_14 ] , V_15 [ V_16 ] ;
T_1 V_17 ;
memcpy ( V_13 , V_18 , sizeof( V_13 ) ) ;
F_2 ( V_19 , F_3 () , L_3 , V_7 , strlen ( V_7 ) , 1 , V_15 , V_13 ) ;
F_4 ( & V_17 ) ;
F_5 ( & V_17 , V_19 , NULL , V_15 , V_13 , V_8 ) ;
while( 1 )
{
int V_20 = F_6 ( V_21 , V_9 , sizeof( V_9 ) ) ;
if ( V_20 <= 0 )
{
if ( ! V_20 )
break;
else
{
perror ( L_4 ) ;
exit ( 1 ) ;
}
}
F_7 ( & V_17 , V_11 , & V_12 , V_9 , V_20 ) ;
F_8 ( STDOUT , V_11 , V_12 ) ;
}
F_9 ( & V_17 , V_11 , & V_12 ) ;
F_10 ( & V_17 ) ;
F_8 ( STDOUT , V_11 , V_12 ) ;
}
