static void T_1 F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_2 ( V_2 ) ; V_1 ++ ) {
struct V_3 * V_4 = & V_2 [ V_1 ] ;
F_3 ( V_4 -> V_5 , V_4 -> V_4 , V_4 -> V_6 ) ;
}
F_4 ( V_7 , V_8 , V_9 ) ;
F_4 ( V_10 , V_11 , V_9 ) ;
F_4 ( V_12 , V_13 , V_14 ) ;
F_4 ( V_12 , V_15 , V_16 ) ;
F_5 ( & V_17 -> V_18 . V_19 , 0x00000180 ) ;
}
static void T_1 F_6 ( void )
{
struct V_20 * V_21 ;
T_2 T_3 * V_22 ;
F_7 () ;
F_1 () ;
V_21 = F_8 ( NULL , NULL , L_1 ) ;
if ( ! V_21 ) {
F_9 ( V_23 L_2 ) ;
return;
}
V_22 = F_10 ( V_21 , 0 ) ;
F_11 ( V_21 ) ;
if ( V_22 == NULL ) {
F_9 ( V_23 L_3 ) ;
return;
}
F_5 ( V_22 , V_24 | V_25 | V_26 ) ;
F_12 ( V_22 ) ;
}
static int T_1 F_13 ( void )
{
unsigned long V_27 = F_14 () ;
return F_15 ( V_27 , L_4 ) ;
}
static int T_1 F_16 ( void )
{
F_17 ( NULL , V_28 , NULL ) ;
return 0 ;
}
