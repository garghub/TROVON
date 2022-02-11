static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 T_3 * V_3 = NULL ;
F_2 () ;
V_2 = F_3 ( NULL , L_1 ) ;
if ( V_2 ) {
struct V_4 V_5 ;
F_4 ( V_2 , 0 , & V_5 ) ;
V_3 = F_5 ( V_5 . V_6 , F_6 ( & V_5 ) ) ;
F_7 ( V_2 ) ;
}
#ifdef F_8
if ( ( V_2 = F_3 ( NULL , L_2 ) ) != NULL ) {
F_9 ( V_2 ) ;
F_7 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_3 ( V_2 , L_3 ) ) != NULL ; )
F_10 ( V_2 ) ;
}
if ( ( V_2 = F_11 ( NULL , L_4 , L_5 ) )
!= NULL ) {
#define F_12 0x50
F_13 ( & V_3 [ 8 ] , F_12 ) ;
F_14 ( 1000 ) ;
F_15 ( & V_3 [ 8 ] , F_12 ) ;
F_16 ( V_3 ) ;
F_7 ( V_2 ) ;
}
#endif
}
static int T_1 F_17 ( void )
{
return F_18 ( L_6 ) ;
}
