static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 ) {
V_4 = V_5 ;
V_6 |= V_7 | V_8 | V_9 ;
} else {
V_6 &= ~ ( V_7 | V_8 | V_9 ) ;
V_4 = 0 ;
}
}
static void F_2 ( int V_10 )
{
if ( V_10 )
V_6 |= V_11 ;
else
V_6 = 0 ;
}
static void T_1
F_3 ( struct V_12 * V_12 , char * * V_13 , struct V_14 * V_15 )
{
if ( V_12 -> V_16 . V_12 != V_17 ) {
V_12 -> V_16 . V_12 = V_17 ;
V_12 -> V_16 . V_18 = F_4 ( V_19 ) ;
V_12 -> V_20 . V_21 . V_22 = 0 ;
V_12 -> V_20 . V_21 . V_23 = V_24 ;
V_12 -> V_20 . V_21 . V_25 = 0x0100 ;
V_12 = F_5 ( V_12 ) ;
V_12 -> V_16 . V_12 = V_26 ;
V_12 -> V_16 . V_18 = F_4 ( V_27 ) ;
V_12 -> V_20 . V_28 . V_18 = 4096 ;
V_12 -> V_20 . V_28 . V_29 = V_30 ;
V_12 = F_5 ( V_12 ) ;
V_12 -> V_16 . V_12 = V_31 ;
V_12 -> V_16 . V_18 = 0 ;
}
}
static void T_1 F_6 ( void )
{
F_7 () ;
F_8 ( V_32 , F_9 ( V_32 ) ) ;
}
static void T_1 F_10 ( void )
{
V_4 = 0 ;
V_6 &= ~ ( V_7 | V_11 | V_8 | V_9 ) ;
V_33 = 0 ;
V_34 = 0 ;
V_35 = 0 ;
V_36 = 0 ;
V_37 = 0 ;
V_38 = 0 ;
if ( ! F_11 ( V_39 ) ) {
V_40 = 0 ;
V_41 = 0 ;
}
}
static void T_1 F_12 ( void )
{
F_13 ( & V_42 ) ;
F_14 ( & V_43 , L_1 , 0 ,
& V_44 ,
sizeof( V_44 ) ) ;
F_14 ( & V_43 , L_2 , 0 ,
& V_45 ,
sizeof( V_45 ) ) ;
F_15 ( L_3 , 0 , NULL , 0 ) ;
}
static void T_1 F_16 ( void )
{
F_14 ( & V_43 , L_4 , 0 ,
& V_46 ,
sizeof( V_46 ) ) ;
}
