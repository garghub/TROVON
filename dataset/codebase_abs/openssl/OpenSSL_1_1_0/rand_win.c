int F_1 ( void )
{
T_1 V_1 ;
# ifndef F_2
T_2 V_2 ;
# endif
T_3 V_3 ;
T_4 V_4 [ 64 ] ;
# ifdef F_2
if ( F_3 ( NULL , V_4 , ( V_5 ) sizeof( V_4 ) , V_6 ) == V_7 ) {
F_4 ( V_4 , sizeof( V_4 ) , sizeof( V_4 ) ) ;
}
# else
if ( F_5 ( & V_2 , NULL , NULL , V_8 , V_9 | V_10 ) ) {
if ( F_6 ( V_2 , ( T_3 ) sizeof( V_4 ) , V_4 ) != 0 ) {
F_4 ( V_4 , sizeof( V_4 ) , sizeof( V_4 ) ) ;
}
F_7 ( V_2 , 0 ) ;
}
if ( F_5 ( & V_2 , NULL , V_11 , V_12 , V_9 | V_10 ) ) {
if ( F_6 ( V_2 , ( T_3 ) sizeof( V_4 ) , V_4 ) != 0 ) {
F_4 ( V_4 , sizeof( V_4 ) , sizeof( V_4 ) ) ;
}
F_7 ( V_2 , 0 ) ;
}
# endif
F_8 () ;
F_9 ( & V_1 ) ;
F_4 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_3 = F_10 () ;
F_4 ( & V_3 , sizeof( V_3 ) , 1 ) ;
return ( 1 ) ;
}
int F_11 ( T_5 V_13 , T_6 V_14 , T_7 V_15 )
{
F_1 () ;
return F_12 () ;
}
void F_13 ( void )
{
F_1 () ;
}
static void F_8 ( void )
{
T_3 V_3 ;
T_8 V_16 ;
static int V_17 = 1 ;
# if F_14 ( V_18 ) && F_14 ( V_19 )
static int V_20 = 1 ;
T_3 V_21 ;
if ( V_20 ) {
F_15 {
__asm {
_emit 0x0f _emit 0x31 mov cyclecount, eax}
F_4 ( & V_21 , sizeof( V_21 ) , 1 ) ;
}
F_16 (EXCEPTION_EXECUTE_HANDLER) {
V_20 = 0 ;
}
}
# else
# define V_20 0
# endif
if ( V_17 ) {
if ( F_17 ( & V_16 ) == 0 )
V_17 = 0 ;
else
F_4 ( & V_16 , sizeof( V_16 ) , 0 ) ;
}
if ( ! V_20 && ! V_17 ) {
V_3 = F_18 () ;
F_4 ( & V_3 , sizeof( V_3 ) , 0 ) ;
}
}
