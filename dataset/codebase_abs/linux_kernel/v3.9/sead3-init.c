char * F_1 ( char * V_1 )
{
int V_2 , V_3 = 0 ;
V_2 = strlen ( V_1 ) ;
while ( F_2 ( V_3 ) ) {
if ( strncmp ( V_1 , F_2 ( V_3 ) , V_2 ) == 0 )
return F_2 ( V_3 + 1 ) ;
V_3 += 2 ;
}
return NULL ;
}
static void T_1 F_3 ( void )
{
void * V_4 ;
V_4 = V_5 ?
( void * ) ( V_6 + 0xa80 ) :
( void * ) ( V_6 + 0x380 ) ;
memcpy ( V_4 , & V_7 , 0x80 ) ;
F_4 ( ( unsigned long ) V_4 , ( unsigned long ) V_4 + 0x80 ) ;
}
static void T_1 F_5 ( void )
{
void * V_4 ;
V_4 = V_5 ?
( void * ) ( V_6 + 0xa00 ) :
( void * ) ( V_6 + 0x300 ) ;
memcpy ( V_4 , & V_8 , 0x80 ) ;
F_4 ( ( unsigned long ) V_4 , ( unsigned long ) V_4 + 0x80 ) ;
}
void T_1 F_6 ( void )
{
V_9 = V_10 ;
V_11 = ( int * ) V_12 ;
V_13 = ( int * ) V_14 ;
V_15 = F_3 ;
V_16 = F_5 ;
F_7 () ;
#ifdef F_8
if ( ( strstr ( F_9 () , L_1 ) ) != NULL )
F_10 ( 0 ) ;
else if ( ( strstr ( F_9 () , L_2 ) ) != NULL )
F_10 ( 1 ) ;
#endif
#ifdef F_11
if ( ( strstr ( F_9 () , L_3 ) ) == NULL )
strcat ( F_9 () , L_4 ) ;
#endif
}
void F_12 ( void )
{
}
