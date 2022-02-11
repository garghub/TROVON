static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
T_2 T_3 * V_3 = NULL ;
if ( V_4 . V_5 )
V_4 . V_5 ( L_1 , 0 ) ;
V_2 = F_2 ( NULL , L_2 ) ;
if ( V_2 ) {
struct V_6 V_7 ;
F_3 ( V_2 , 0 , & V_7 ) ;
V_3 = F_4 ( V_7 . V_8 , F_5 ( & V_7 ) ) ;
F_6 ( V_2 ) ;
}
F_7 () ;
#ifdef F_8
F_9 () ;
if ( ( V_2 = F_2 ( NULL , L_3 ) ) != NULL ) {
F_10 ( V_2 ) ;
F_6 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_2 ( V_2 , L_4 ) ) != NULL ; )
F_11 ( V_2 ) ;
}
if ( ( V_2 = F_12 ( NULL , L_5 , L_6 ) )
!= NULL ) {
#define F_13 0x50
F_14 ( & V_3 [ 8 ] , F_13 ) ;
F_15 ( 1000 ) ;
F_16 ( & V_3 [ 8 ] , F_13 ) ;
F_17 ( V_3 ) ;
F_6 ( V_2 ) ;
}
#endif
}
static int T_1 F_18 ( void )
{
unsigned long V_9 = F_19 () ;
return F_20 ( V_9 , L_7 ) ;
}
