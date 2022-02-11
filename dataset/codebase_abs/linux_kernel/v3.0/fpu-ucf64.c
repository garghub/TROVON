void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
T_1 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_5 = V_6 ;
V_4 . V_7 = V_1 ;
V_4 . V_8 = ( void V_9 * ) ( F_2 ( V_3 ) - 4 ) ;
V_10 -> V_11 . V_12 = 0 ;
V_10 -> V_11 . V_13 = 6 ;
F_3 ( V_6 , & V_4 , V_10 ) ;
}
void F_4 ( T_2 V_14 , T_2 V_15 , struct V_2 * V_3 )
{
T_2 V_16 = V_15 ;
T_2 V_17 = V_18 & V_15 ;
F_5 ( L_1 ,
V_14 , V_15 ) ;
if ( V_17 & V_19 ) {
if ( V_17 & V_20 )
V_16 |= V_20 ;
else
V_16 &= ~ ( V_20 ) ;
V_17 &= ~ ( V_19 | V_20 ) ;
} else {
F_5 ( V_21 L_2 ) ;
F_5 ( V_21 L_3 ,
F_6 ( V_22 ) , V_14 ) ;
F_1 ( 0 , V_3 ) ;
return;
}
V_16 &= ~ ( V_23 | V_24 | V_25 | V_26 |
V_27 | V_28 | V_29 | V_30 |
V_31 | V_32 | V_33 ) ;
V_16 |= V_17 ;
F_7 ( V_22 , V_16 ) ;
}
static int T_3 F_8 ( void )
{
F_7 ( V_22 , 0x0 ) ;
F_9 ( V_34 L_4 ) ;
return 0 ;
}
