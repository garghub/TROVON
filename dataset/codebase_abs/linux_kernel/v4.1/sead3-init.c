static void T_1 F_1 ( void )
{
char V_1 [ 40 ] ;
int V_2 = 0 ;
char V_3 = '\0' , V_4 = '\0' , V_5 = '\0' ;
char * V_6 ;
if ( ( strstr ( F_2 () , L_1 ) ) == NULL ) {
V_6 = F_3 ( L_2 ) ;
if ( V_6 ) {
while ( * V_6 >= '0' && * V_6 <= '9' )
V_2 = V_2 * 10 + * V_6 ++ - '0' ;
if ( * V_6 == ',' )
V_6 ++ ;
if ( * V_6 )
V_3 = * V_6 ++ ;
if ( * V_6 == ',' )
V_6 ++ ;
if ( * V_6 )
V_4 = * V_6 ++ ;
if ( * V_6 == ',' )
V_6 ++ ;
if ( * V_6 == 'h' )
V_5 = 'r' ;
}
if ( V_2 == 0 )
V_2 = 38400 ;
if ( V_3 != 'n' && V_3 != 'o' && V_3 != 'e' )
V_3 = 'n' ;
if ( V_4 != '7' && V_4 != '8' )
V_4 = '8' ;
if ( V_5 == '\0' )
V_5 = 'r' ;
sprintf ( V_1 , L_3 , V_2 ,
V_3 , V_4 , V_5 ) ;
strcat ( F_2 () , V_1 ) ;
}
}
static void T_1 F_4 ( void )
{
void * V_7 ;
V_7 = V_8 ?
( void * ) ( V_9 + 0xa80 ) :
( void * ) ( V_9 + 0x380 ) ;
#ifdef F_5
memcpy ( V_7 , ( & V_10 - 1 ) , 0x80 ) ;
if ( ! V_8 ) {
void * V_11 = ( void * ) ( V_9 + 0xa80 ) ;
* ( ( unsigned int * ) V_11 ) = 0x3c1a8000 ;
* ( ( unsigned int * ) V_11 + 1 ) = 0x375a0381 ;
* ( ( unsigned int * ) V_11 + 2 ) = 0x03400008 ;
* ( ( unsigned int * ) V_11 + 3 ) = 0x00000000 ;
F_6 ( ( unsigned long ) V_11 ,
( unsigned long ) V_11 + 0x10 ) ;
}
#else
memcpy ( V_7 , & V_10 , 0x80 ) ;
#endif
F_6 ( ( unsigned long ) V_7 , ( unsigned long ) V_7 + 0x80 ) ;
}
static void T_1 F_7 ( void )
{
void * V_7 ;
V_7 = V_8 ?
( void * ) ( V_9 + 0xa00 ) :
( void * ) ( V_9 + 0x300 ) ;
#ifdef F_5
memcpy ( V_7 , ( & V_12 - 1 ) , 0x80 ) ;
if ( ! V_8 ) {
void * V_11 = ( void * ) ( V_9 + 0xa00 ) ;
* ( ( unsigned int * ) V_11 ) = 0x3c1a8000 ;
* ( ( unsigned int * ) V_11 + 1 ) = 0x375a0301 ;
* ( ( unsigned int * ) V_11 + 2 ) = 0x03400008 ;
* ( ( unsigned int * ) V_11 + 3 ) = 0x00000000 ;
F_6 ( ( unsigned long ) V_11 ,
( unsigned long ) V_11 + 0x10 ) ;
}
#else
memcpy ( V_7 , & V_12 , 0x80 ) ;
#endif
F_6 ( ( unsigned long ) V_7 , ( unsigned long ) V_7 + 0x80 ) ;
}
void T_1 F_8 ( void )
{
V_13 = F_4 ;
V_14 = F_7 ;
F_9 () ;
#ifdef F_10
if ( ( strstr ( F_2 () , L_4 ) ) != NULL )
F_11 ( 0 ) ;
else if ( ( strstr ( F_2 () , L_5 ) ) != NULL )
F_11 ( 1 ) ;
#endif
#ifdef F_12
if ( ( strstr ( F_2 () , L_1 ) ) == NULL )
strcat ( F_2 () , L_6 ) ;
F_1 () ;
#endif
}
void T_1 F_13 ( void )
{
}
