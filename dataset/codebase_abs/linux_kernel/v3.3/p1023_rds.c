static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
if ( V_3 . V_4 )
V_3 . V_4 ( L_1 , 0 ) ;
V_2 = F_2 ( NULL , L_2 ) ;
if ( V_2 != NULL ) {
static T_2 T_3 * V_5 ;
V_5 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_5 ) {
F_5 ( V_6
L_3 ) ;
return;
} else {
#define F_6 0x07
#define F_7 0x02
#ifdef F_8
F_9 ( & V_5 [ 15 ] , F_6 ) ;
F_10 ( & V_5 [ 15 ] , F_7 ) ;
#endif
F_11 ( V_5 ) ;
}
}
#ifdef F_12
F_13 (np, L_4 , L_5 )
F_14 ( V_2 , 0 ) ;
#endif
F_15 () ;
}
static void T_1 F_16 ( void )
{
struct V_7 * V_7 = F_17 ( NULL , 0 ,
V_8 | V_9 |
V_10 | V_11 ,
0 , 256 , L_6 ) ;
F_18 ( V_7 == NULL ) ;
F_19 ( V_7 ) ;
}
static int T_1 F_20 ( void )
{
unsigned long V_12 = F_21 () ;
return F_22 ( V_12 , L_7 ) ;
}
