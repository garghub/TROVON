void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 ( 12 << 20 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
void T_2 * V_6 ;
V_5 = F_6 ( V_3 , V_7 , 0 ) ;
if ( F_7 ( ! V_5 ) ) {
F_8 ( L_1 ) ;
return;
}
V_6 = F_9 ( V_5 -> V_8 , F_10 ( V_5 ) ) ;
if ( F_7 ( ! V_6 ) ) {
F_8 ( L_2 ) ;
return;
}
F_11 ( V_6 , V_9 , F_12 ( V_6 , V_9 ) | 0x80 ) ;
F_12 ( V_6 , V_9 ) ;
F_11 ( V_6 , V_10 , F_12 ( V_6 , V_10 ) | 0x10 ) ;
F_12 ( V_6 , V_10 ) ;
F_13 ( 10 ) ;
F_11 ( V_6 , V_9 , 0x01 ) ;
F_11 ( V_6 , V_10 , 0x00 ) ;
F_13 ( 10 ) ;
F_11 ( V_6 , V_9 , 0x10 ) ;
F_13 ( 10 ) ;
F_11 ( V_6 , V_9 , 0x00 ) ;
F_13 ( 10 ) ;
F_11 ( V_6 , V_9 , 0x10 ) ;
F_13 ( 10 ) ;
F_14 ( V_6 ) ;
}
void T_1 F_15 ( void )
{
F_5 ( & V_11 ) ;
F_5 ( & V_12 ) ;
F_16 ( V_13 ,
F_3 ( V_13 ) ) ;
F_16 ( V_14 ,
F_3 ( V_14 ) ) ;
}
static void T_1 F_17 ( void )
{
F_18 ( 0 ) ;
F_19 () ;
}
void T_1 F_20 ( void )
{
F_21 ( V_13 ,
F_3 ( V_13 ) ) ;
F_22 () ;
V_15 . V_16 = F_17 ;
}
