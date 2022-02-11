static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
void T_2 * V_3 = NULL ;
T_3 V_4 ;
if ( V_5 . V_6 )
V_5 . V_6 ( L_1 , 0 ) ;
#ifdef F_2
F_3 () ;
#endif
F_4 () ;
V_2 = F_5 ( NULL , NULL ,
L_2 ) ;
if ( V_2 ) {
V_3 = F_6 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
}
if ( V_3 ) {
V_4 = F_8 ( V_3 + V_7 ) ;
V_4 |= V_8 | V_9
| V_10 ;
F_9 ( V_4 , V_3 + V_7 ) ;
} else
F_10 ( L_3 ) ;
F_11 ( L_4 ) ;
}
static int T_1 F_12 ( void )
{
unsigned long V_11 = F_13 () ;
return F_14 ( V_11 , L_5 ) ;
}
static void F_15 ( struct V_12 * V_13 )
{
unsigned int V_14 ;
if ( ! F_16 ( V_15 ) )
return;
F_17 ( V_13 , 0xe0 , & V_14 ) ;
F_18 ( V_13 , 0xe0 , ( V_14 & ~ 7 ) | 0x2 ) ;
F_18 ( V_13 , 0xe4 , 1 << 5 ) ;
}
