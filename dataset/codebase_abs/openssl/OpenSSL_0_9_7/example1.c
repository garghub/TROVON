int main ( int V_1 , char * V_2 [] )
{
F_1 () ;
if ( ( V_1 == 1 ) )
{
F_2 () ;
}
else if ( ( V_1 == 2 ) && ! strcmp ( V_2 [ 1 ] , L_1 ) )
{
F_3 () ;
}
else
{
printf ( L_2 , V_3 ) ;
exit ( 1 ) ;
}
return 0 ;
}
void F_2 ( void )
{
unsigned int V_4 ;
T_1 V_5 ;
unsigned char V_6 [ V_7 ] ;
unsigned char * V_8 [ 1 ] ;
int V_9 ;
int V_10 , V_11 ;
T_2 * V_12 [ 1 ] ;
char V_13 [ 512 ] ;
char V_14 [ 512 ] ;
memset ( V_6 , '\0' , sizeof( V_6 ) ) ;
V_12 [ 0 ] = F_4 ( V_15 ) ;
if( ! V_12 [ 0 ] )
{
fprintf ( V_16 , L_3 ) ;
exit ( 1 ) ;
}
V_8 [ 0 ] = malloc ( F_5 ( V_12 [ 0 ] ) ) ;
if ( ! V_8 [ 0 ] )
{
F_6 ( V_12 [ 0 ] ) ;
perror ( L_4 ) ;
exit ( 1 ) ;
}
F_7 ( & V_5 ,
F_8 () ,
V_8 ,
& V_10 ,
V_6 ,
V_12 ,
1 ) ;
V_11 = F_9 ( V_10 ) ;
F_10 ( STDOUT , ( char * ) & V_11 , sizeof( V_11 ) ) ;
F_10 ( STDOUT , V_8 [ 0 ] , V_10 ) ;
F_10 ( STDOUT , V_6 , sizeof( V_6 ) ) ;
while( 1 )
{
V_9 = F_11 ( V_17 , V_13 , sizeof( V_13 ) ) ;
if ( V_9 <= 0 )
{
if ( V_9 < 0 )
perror ( L_5 ) ;
break;
}
F_12 ( & V_5 , V_14 , & V_4 , V_13 , V_9 ) ;
F_10 ( STDOUT , V_14 , V_4 ) ;
}
F_13 ( & V_5 , V_14 , & V_4 ) ;
F_10 ( STDOUT , V_14 , V_4 ) ;
F_6 ( V_12 [ 0 ] ) ;
free ( V_8 [ 0 ] ) ;
}
void F_3 ( void )
{
char V_13 [ 520 ] ;
char V_14 [ 512 ] ;
unsigned int V_18 ;
T_1 V_5 ;
unsigned char V_6 [ V_7 ] ;
unsigned char * V_19 ;
unsigned int V_10 ;
T_2 * V_20 ;
memset ( V_6 , '\0' , sizeof( V_6 ) ) ;
V_20 = F_14 ( V_21 ) ;
if ( ! V_20 )
{
fprintf ( V_16 , L_6 ) ;
exit ( 1 ) ;
}
F_11 ( V_17 , & V_10 , sizeof( V_10 ) ) ;
V_10 = F_15 ( V_10 ) ;
if ( V_10 != F_5 ( V_20 ) )
{
F_6 ( V_20 ) ;
fprintf ( V_16 , L_7 ) ;
exit ( 1 ) ;
}
V_19 = malloc ( sizeof( char ) * V_10 ) ;
if ( ! V_19 )
{
F_6 ( V_20 ) ;
perror ( L_4 ) ;
exit ( 1 ) ;
}
F_11 ( V_17 , V_19 , V_10 ) ;
F_11 ( V_17 , V_6 , sizeof( V_6 ) ) ;
F_16 ( & V_5 ,
F_8 () ,
V_19 ,
V_10 ,
V_6 ,
V_20 ) ;
while( 1 )
{
int V_9 = F_11 ( V_17 , V_14 , sizeof( V_14 ) ) ;
if ( V_9 <= 0 )
{
if ( V_9 < 0 )
perror ( L_5 ) ;
break;
}
F_17 ( & V_5 , V_13 , & V_18 , V_14 , V_9 ) ;
F_10 ( STDOUT , V_13 , V_18 ) ;
}
F_18 ( & V_5 , V_13 , & V_18 ) ;
F_10 ( STDOUT , V_13 , V_18 ) ;
F_6 ( V_20 ) ;
free ( V_19 ) ;
}
