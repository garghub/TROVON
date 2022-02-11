static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 [ 6 ] = { 3 , 3 , 1 , 1 , 1 , 8 } ;
F_2 ( V_2 , V_5 , V_6 ) ;
F_3 ( & V_2 -> V_7 -> V_8 , L_1 ,
F_4 ( V_2 , V_6 ) ) ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
F_2 ( V_2 , 0 , F_5 ( V_3 ) ) ;
F_2 ( V_2 , V_4 [ V_3 ] , F_6 ( V_3 ) ) ;
F_3 ( & V_2 -> V_7 -> V_8 , L_2 , V_3 ,
F_4 ( V_2 , F_6 ( V_3 ) ) ) ;
}
F_2 ( V_2 , 1 , V_9 ) ;
F_3 ( & V_2 -> V_7 -> V_8 , L_3 ,
F_4 ( V_2 , V_9 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
T_2 V_13 , V_14 , V_15 ;
V_13 = F_10 ( V_2 , V_16 ) ;
V_15 = F_11 ( F_12 ( V_2 , V_17 , V_18 ) ) ;
V_14 = F_10 ( V_2 , V_19 ) ;
V_14 &= 0xffffffffff00ffffULL ;
V_14 |= V_15 << 16 ;
F_13 ( V_2 , V_19 , V_14 ) ;
if ( F_14 ( V_11 -> V_18 ) )
V_13 |= 0xF ;
else
V_13 &= ~ 0xF ;
F_13 ( V_2 , V_16 , V_13 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_20 ) ;
F_17 ( V_2 , V_21 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_9 ( V_2 ) ;
F_20 ( V_2 ) ;
F_13 ( V_2 , V_22 , 0x200000ULL ) ;
return 0 ;
}
static inline void F_21 ( struct V_1 * V_2 )
{
T_1 V_23 = 0 ;
F_22 ( V_2 -> V_7 , V_24 , & V_23 ) ;
V_23 |= 0x3 ;
F_23 ( V_2 -> V_7 , V_24 , V_23 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_2 V_25 = F_4 ( V_2 , V_26 ) ;
return ( ( V_25 & V_27 ) == 0 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
T_3 V_28 = V_29 ;
if ( F_26 ( V_2 , 0 , 0 ) )
return 1 ;
if ( F_26 ( V_2 , 1 , V_30 ) ) {
F_27 ( & V_2 -> V_7 -> V_8 , L_4 ,
V_31 ) ;
F_28 ( V_2 , 0 ) ;
return 1 ;
}
F_29 ( & V_11 -> V_32 ) ;
V_2 -> V_33 . V_34 = V_35 ;
V_2 -> V_33 . V_36 = V_37 ;
V_2 -> V_33 . V_38 = V_39 ;
V_2 -> V_33 . V_40 = F_7 ;
V_2 -> V_33 . V_41 = F_15 ;
V_2 -> V_33 . V_42 = V_43 ;
V_2 -> V_33 . V_44 = V_45 ;
V_2 -> V_33 . V_46 = V_47 ;
V_2 -> V_33 . V_48 = V_49 ;
V_2 -> V_33 . V_50 = V_51 ;
V_2 -> V_33 . V_52 = V_53 ;
V_2 -> V_33 . V_54 = V_55 ;
V_2 -> V_33 . V_56 = V_57 ;
F_30 ( V_2 , V_2 -> V_12 , & V_2 -> V_58 ) ;
if ( F_24 ( V_2 ) )
V_28 = V_59 ;
V_11 -> V_18 = (struct V_60 * )
F_31 ( V_2 , V_28 ) ;
if ( ! V_11 -> V_18 ) {
F_27 ( & V_2 -> V_7 -> V_8 , L_5 ,
V_31 ,
( V_28 == V_29 ) ? V_61 :
V_62 ) ;
F_28 ( V_2 , 0 ) ;
F_28 ( V_2 , 1 ) ;
return 1 ;
}
V_2 -> V_63 = 1000000ULL * F_32 ( V_2 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
