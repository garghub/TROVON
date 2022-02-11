static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void T_1 F_4 ( void )
{
T_2 V_2 , V_3 , V_4 ;
V_2 = ~ ( ( ~ 0u ) << ( 11 - V_5 ) ) ;
V_2 |= ( ~ ( ( ~ 0u ) << ( 29 - 22 ) ) ) << 22 ;
V_3 = ~ ( ( ~ 0u ) << ( 1 + V_6 - V_7 ) ) ;
V_4 = ~ ( ( ~ 0u ) << ( 1 + V_8 - V_9 ) ) ;
F_5 ( 0xffffffff , V_10 + V_11 ) ;
F_5 ( 0xffffffff , V_10 + V_12 ) ;
F_5 ( 0xffffffff , V_13 + V_11 ) ;
F_5 ( 0xffffffff , V_13 + V_12 ) ;
F_5 ( V_4 , V_14 + V_11 ) ;
F_5 ( V_4 , V_14 + V_12 ) ;
F_6 ( V_10 , L_1 , V_5 ,
- 1 , V_2 , NULL ) ;
F_6 ( V_13 , L_2 , V_7 ,
- 1 , V_3 , NULL ) ;
F_6 ( V_14 , L_3 , V_9 ,
V_15 , V_4 , NULL ) ;
}
static void F_7 ( struct V_16 * V_16 , struct V_17 V_18 )
{
T_2 V_19 ;
V_19 = F_8 ( V_16 -> V_20 ) & ~ 0x7ffff ;
V_19 |= V_18 . V_21 | ( V_18 . V_22 << 9 ) | ( V_18 . V_23 << 16 ) ;
F_5 ( 0xa05f , V_24 ) ;
F_5 ( V_19 , V_16 -> V_20 ) ;
F_5 ( 0 , V_24 ) ;
}
static int F_9 ( struct V_25 * V_26 )
{
T_2 V_19 ;
V_19 = F_8 ( V_27 + V_28 ) ;
V_19 |= V_29 ;
F_5 ( V_19 , V_27 + V_28 ) ;
return 0 ;
}
static void F_10 ( struct V_25 * V_26 )
{
T_2 V_19 ;
V_19 = F_8 ( V_27 + V_28 ) ;
V_19 &= ~ ( V_30 | V_29 ) ;
F_5 ( V_19 , V_27 + V_28 ) ;
}
static void F_11 ( struct V_25 * V_31 , int V_32 )
{
T_2 V_19 ;
V_19 = F_8 ( V_27 + V_28 ) ;
if ( V_32 )
V_19 |= V_30 ;
else
V_19 &= ~ V_30 ;
F_5 ( V_19 , V_27 + V_28 ) ;
}
static unsigned int F_12 ( struct V_33 * V_26 )
{
unsigned int V_34 = F_8 ( F_13 ( 0xca000000 + 4 ) ) ;
F_5 ( 8 , F_13 ( V_35 + 8 ) ) ;
return V_34 & 8 ;
}
static void F_14 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = & V_37 -> V_37 . V_39 ;
T_2 V_19 = V_40 | V_41 ;
if ( V_39 -> V_42 <= 8 ||
( V_39 -> V_42 == 16 && V_39 -> V_43 . V_44 == 5 ) )
V_19 |= V_45 ;
else if ( V_37 -> V_37 . V_39 . V_42 <= 16 )
V_19 |= V_46 ;
else
V_19 = 0 ;
F_15 ( V_47 |
V_48 |
V_49 |
V_40 |
V_41 |
V_50 |
V_51 , V_19 ) ;
}
static int F_16 ( struct V_36 * V_37 )
{
V_37 -> V_52 = F_17 ( L_4 ) ;
if ( ! V_37 -> V_52 )
return - V_53 ;
return F_18 ( V_37 , V_54 ) ;
}
static void T_1 F_19 ( void )
{
F_20 ( V_55 , F_3 ( V_55 ) ) ;
F_21 () ;
#ifdef F_22
F_23 ( V_56 , 24000000 ) ;
#endif
}
static void T_1 F_24 ( void )
{
int V_57 ;
F_25 ( V_58 , F_3 ( V_58 ) ) ;
for ( V_57 = 0 ; V_57 < F_3 ( V_59 ) ; V_57 ++ ) {
struct V_60 * V_61 = V_59 [ V_57 ] ;
F_26 ( V_61 , & V_62 ) ;
}
}
static void T_1 F_27 ( void )
{
F_5 ( 0 , V_63 + V_64 ) ;
F_5 ( 0 , V_65 + V_64 ) ;
F_5 ( 0 , V_66 + V_64 ) ;
F_28 ( V_66 , L_5 ) ;
F_29 ( V_65 , V_67 , L_6 ) ;
}
