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
F_7 ( true ) ;
}
static int F_8 ( struct V_16 * V_17 )
{
T_2 V_18 ;
V_18 = F_9 ( V_19 + V_20 ) ;
V_18 |= V_21 ;
F_5 ( V_18 , V_19 + V_20 ) ;
return 0 ;
}
static void F_10 ( struct V_16 * V_17 )
{
T_2 V_18 ;
V_18 = F_9 ( V_19 + V_20 ) ;
V_18 &= ~ ( V_22 | V_21 ) ;
F_5 ( V_18 , V_19 + V_20 ) ;
}
static void F_11 ( struct V_16 * V_23 , int V_24 )
{
T_2 V_18 ;
V_18 = F_9 ( V_19 + V_20 ) ;
if ( V_24 )
V_18 |= V_22 ;
else
V_18 &= ~ V_22 ;
F_5 ( V_18 , V_19 + V_20 ) ;
}
static unsigned int F_12 ( struct V_25 * V_17 )
{
unsigned int V_26 = F_9 ( F_13 ( 0xca000000 + 4 ) ) ;
F_5 ( 8 , F_13 ( V_27 + 8 ) ) ;
return V_26 & 8 ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = & V_29 -> V_29 . V_31 ;
T_2 V_18 = V_32 | V_33 ;
if ( V_31 -> V_34 <= 8 ||
( V_31 -> V_34 == 16 && V_31 -> V_35 . V_36 == 5 ) )
V_18 |= V_37 ;
else if ( V_29 -> V_29 . V_31 . V_34 <= 16 )
V_18 |= V_38 ;
else
V_18 = 0 ;
F_15 ( V_39 |
V_40 |
V_41 |
V_32 |
V_33 |
V_42 |
V_43 , V_18 ) ;
}
static int F_16 ( struct V_28 * V_29 )
{
V_29 -> V_44 = F_17 ( L_4 ) ;
if ( ! V_29 -> V_44 )
return - V_45 ;
return F_18 ( V_29 , V_46 ) ;
}
static void T_1 F_19 ( void )
{
#ifdef F_20
F_21 ( V_47 , 24000000 ) ;
#endif
}
static void T_1 F_22 ( void )
{
int V_48 ;
F_23 ( V_49 , F_3 ( V_49 ) ) ;
for ( V_48 = 0 ; V_48 < F_3 ( V_50 ) ; V_48 ++ ) {
struct V_51 * V_52 = V_50 [ V_48 ] ;
F_24 ( V_52 , & V_53 ) ;
}
}
static void T_1 F_25 ( void )
{
F_5 ( 0 , V_54 + V_55 ) ;
F_5 ( 0 , V_56 + V_55 ) ;
F_5 ( 0 , V_57 + V_55 ) ;
F_26 ( V_57 , L_5 ) ;
F_27 ( V_56 , V_58 , L_6 ) ;
}
