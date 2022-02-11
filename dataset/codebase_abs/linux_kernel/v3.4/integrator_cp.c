static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
T_2 V_2 , V_3 ;
V_2 = ~ ( ( ~ 0u ) << ( 11 - V_4 ) ) ;
V_2 |= ( ~ ( ( ~ 0u ) << ( 29 - 22 ) ) ) << 22 ;
V_3 = ~ ( ( ~ 0u ) << ( 1 + V_5 - V_6 ) ) ;
F_5 ( 0xffffffff , V_7 + V_8 ) ;
F_5 ( 0xffffffff , V_7 + V_9 ) ;
F_5 ( 0xffffffff , V_10 + V_8 ) ;
F_5 ( 0xffffffff , V_10 + V_9 ) ;
F_5 ( V_3 , V_11 + V_8 ) ;
F_5 ( V_3 , V_11 + V_9 ) ;
F_6 ( - 1 , V_2 , & V_12 ) ;
F_6 ( - 1 , ~ ( ( ~ 0u ) << ( 1 + V_13 - V_14 ) ) ,
& V_15 ) ;
F_6 ( V_16 , V_3 , & V_17 ) ;
}
static void F_7 ( struct V_18 * V_18 , struct V_19 V_20 )
{
T_2 V_21 ;
V_21 = F_8 ( V_18 -> V_22 ) & ~ 0x7ffff ;
V_21 |= V_20 . V_23 | ( V_20 . V_24 << 9 ) | ( V_20 . V_25 << 16 ) ;
F_5 ( 0xa05f , V_26 ) ;
F_5 ( V_21 , V_18 -> V_22 ) ;
F_5 ( 0 , V_26 ) ;
}
static int F_9 ( struct V_27 * V_28 )
{
T_2 V_21 ;
V_21 = F_8 ( V_29 + V_30 ) ;
V_21 |= V_31 ;
F_5 ( V_21 , V_29 + V_30 ) ;
return 0 ;
}
static void F_10 ( struct V_27 * V_28 )
{
T_2 V_21 ;
V_21 = F_8 ( V_29 + V_30 ) ;
V_21 &= ~ ( V_32 | V_31 ) ;
F_5 ( V_21 , V_29 + V_30 ) ;
}
static void F_11 ( struct V_27 * V_33 , int V_34 )
{
T_2 V_21 ;
V_21 = F_8 ( V_29 + V_30 ) ;
if ( V_34 )
V_21 |= V_32 ;
else
V_21 &= ~ V_32 ;
F_5 ( V_21 , V_29 + V_30 ) ;
}
static unsigned int F_12 ( struct V_35 * V_28 )
{
unsigned int V_36 = F_8 ( F_13 ( 0xca000000 + 4 ) ) ;
F_5 ( 8 , F_13 ( V_37 + 8 ) ) ;
return V_36 & 8 ;
}
static void F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = & V_39 -> V_39 . V_41 ;
T_2 V_21 = V_42 | V_43 ;
if ( V_41 -> V_44 <= 8 ||
( V_41 -> V_44 == 16 && V_41 -> V_45 . V_46 == 5 ) )
V_21 |= V_47 ;
else if ( V_39 -> V_39 . V_41 . V_44 <= 16 )
V_21 |= V_48 ;
else
V_21 = 0 ;
F_15 ( V_49 |
V_50 |
V_51 |
V_42 |
V_43 |
V_52 |
V_53 , V_21 ) ;
}
static int F_16 ( struct V_38 * V_39 )
{
V_39 -> V_54 = F_17 ( L_1 ) ;
if ( ! V_39 -> V_54 )
return - V_55 ;
return F_18 ( V_39 , V_56 ) ;
}
static void T_1 F_19 ( void )
{
F_20 ( V_57 , F_3 ( V_57 ) ) ;
F_21 () ;
#ifdef F_22
F_23 ( V_58 , 24000000 ) ;
#endif
}
static void T_1 F_24 ( void )
{
int V_59 ;
F_25 ( V_60 , F_3 ( V_60 ) ) ;
for ( V_59 = 0 ; V_59 < F_3 ( V_61 ) ; V_59 ++ ) {
struct V_62 * V_63 = V_61 [ V_59 ] ;
F_26 ( V_63 , & V_64 ) ;
}
}
static void T_1 F_27 ( void )
{
F_5 ( 0 , V_65 + V_66 ) ;
F_5 ( 0 , V_67 + V_66 ) ;
F_5 ( 0 , V_68 + V_66 ) ;
F_28 ( V_68 , L_2 ) ;
F_29 ( V_67 , V_69 , L_3 ) ;
}
