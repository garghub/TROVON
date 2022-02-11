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
unsigned int V_12 , V_13 ;
unsigned char V_14 [ V_15 ] , V_16 [ V_17 ] ;
unsigned int V_18 , V_19 ;
T_1 V_20 ;
memcpy ( V_14 , V_21 , sizeof( V_14 ) ) ;
F_2 ( V_22 , F_3 () , L_3 , V_7 , strlen ( V_7 ) , 1 , V_16 , V_14 ) ;
F_4 ( & V_20 , V_22 , V_16 , V_14 , V_8 ) ;
while( 1 )
{
int V_23 = F_5 ( V_24 , V_9 , sizeof( V_9 ) ) ;
if ( V_23 <= 0 )
{
if ( ! V_23 )
break;
else
{
perror ( L_4 ) ;
exit ( 1 ) ;
}
}
F_6 ( & V_20 , V_11 , & V_12 , V_9 , V_23 ) ;
F_7 ( STDOUT , V_11 , V_12 ) ;
}
F_8 ( & V_20 , V_11 , & V_12 ) ;
F_7 ( STDOUT , V_11 , V_12 ) ;
}
