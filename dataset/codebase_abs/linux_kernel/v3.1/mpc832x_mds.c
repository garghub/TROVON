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
#ifdef F_7
F_8 (np, L_3 , L_4 )
F_9 ( V_2 ) ;
#endif
#ifdef F_10
F_11 () ;
if ( ( V_2 = F_2 ( NULL , L_5 ) ) != NULL ) {
F_12 ( V_2 ) ;
F_6 ( V_2 ) ;
for ( V_2 = NULL ; ( V_2 = F_2 ( V_2 , L_6 ) ) != NULL ; )
F_13 ( V_2 ) ;
}
if ( ( V_2 = F_14 ( NULL , L_7 , L_8 ) )
!= NULL ) {
#define F_15 0x50
F_16 ( & V_3 [ 8 ] , F_15 ) ;
F_17 ( 1000 ) ;
F_18 ( & V_3 [ 8 ] , F_15 ) ;
F_19 ( V_3 ) ;
F_6 ( V_2 ) ;
}
#endif
}
static int T_1 F_20 ( void )
{
F_21 ( NULL , V_9 , NULL ) ;
return 0 ;
}
static void T_1 F_22 ( void )
{
struct V_1 * V_2 ;
V_2 = F_23 ( NULL , L_9 ) ;
if ( ! V_2 )
return;
F_24 ( V_2 , 0 ) ;
F_25 () ;
F_6 ( V_2 ) ;
#ifdef F_10
V_2 = F_14 ( NULL , NULL , L_10 ) ;
if ( ! V_2 ) {
V_2 = F_23 ( NULL , L_11 ) ;
if ( ! V_2 )
return;
}
F_26 ( V_2 , 0 , V_10 , V_11 ) ;
F_6 ( V_2 ) ;
#endif
}
static int T_1 F_27 ( void )
{
unsigned long V_12 = F_28 () ;
return F_29 ( V_12 , L_12 ) ;
}
