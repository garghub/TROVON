static struct V_1 F_1 ( const struct V_2 * V_3 , int V_4 )
{
struct V_1 V_5 ;
T_1 V_6 = V_3 -> V_7 . V_8 . V_9 . V_1 [ F_2 ( V_4 ) ] ;
if ( V_3 -> V_10 -> V_7 . V_11 . V_12 == V_13 )
V_5 . V_14 = V_6 & V_15 ;
else
V_5 . V_14 = V_6 & V_16 ;
V_5 . V_17 = 0 ;
if ( V_5 . V_14 <= 15 &&
V_3 -> V_10 -> V_7 . V_11 . V_12 == V_18 )
V_5 . V_17 = ( V_6 >> V_19 ) & 0x7 ;
V_5 . V_20 = 0 ;
if ( V_6 & V_21 )
V_5 . V_20 |= V_22 ;
if ( V_6 & V_23 )
V_5 . V_20 |= V_24 ;
if ( V_6 & V_25 )
V_5 . V_20 |= V_26 ;
return V_5 ;
}
static void F_3 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
T_1 V_27 ;
V_27 = V_5 . V_14 ;
if ( V_3 -> V_10 -> V_7 . V_11 . V_12 == V_13 )
V_27 |= V_28 ;
else
V_27 |= ( V_29 ) V_5 . V_17 << V_19 ;
if ( V_5 . V_20 & V_22 )
V_27 |= V_21 ;
if ( V_5 . V_20 & V_24 )
V_27 |= V_23 ;
if ( V_5 . V_20 & V_26 )
V_27 |= V_25 ;
V_3 -> V_7 . V_8 . V_9 . V_1 [ F_2 ( V_4 ) ] = V_27 ;
}
static void F_4 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
if ( ! ( V_5 . V_20 & V_30 ) )
V_3 -> V_7 . V_8 . V_9 . V_31 |= ( 1U << V_4 ) ;
else
V_3 -> V_7 . V_8 . V_9 . V_31 &= ~ ( 1U << V_4 ) ;
}
static T_1 F_5 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_31 ;
}
static T_1 F_6 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_32 ;
}
static void F_7 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_32 = 0 ;
}
static V_29 F_8 ( const struct V_2 * V_3 )
{
V_29 V_33 = V_3 -> V_7 . V_8 . V_9 . V_34 ;
V_29 V_35 = 0 ;
if ( V_33 & V_36 )
V_35 |= V_37 ;
if ( V_33 & V_38 )
V_35 |= V_39 ;
return V_35 ;
}
static void F_9 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
V_29 V_42 = V_3 -> V_7 . V_8 . V_9 . V_40 ;
V_41 -> V_43 = ( V_42 & V_44 ) >> V_45 ;
V_41 -> V_46 = ( V_42 & V_47 ) >> V_48 ;
V_41 -> V_49 = ( V_42 & V_50 ) >> V_51 ;
V_41 -> V_52 = ( V_42 & V_53 ) >> V_54 ;
}
static void F_10 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_55 |= V_56 ;
}
static void F_11 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_55 &= ~ V_56 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_40 * V_41 )
{
V_29 V_42 ;
V_42 = ( V_41 -> V_43 << V_45 ) & V_44 ;
V_42 |= ( V_41 -> V_46 << V_48 ) & V_47 ;
V_42 |= ( V_41 -> V_49 << V_51 ) & V_50 ;
V_42 |= ( V_41 -> V_52 << V_54 ) & V_53 ;
V_3 -> V_7 . V_8 . V_9 . V_40 = V_42 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_57 * V_9 = & V_3 -> V_7 . V_8 . V_9 ;
V_9 -> V_40 = 0 ;
if ( V_3 -> V_10 -> V_7 . V_11 . V_12 == V_13 )
V_9 -> V_58 = V_59 ;
else
V_9 -> V_58 = 0 ;
V_9 -> V_55 = V_60 ;
}
int F_14 ( struct V_61 * V_62 ,
const struct V_63 * * V_64 ,
const struct V_65 * * V_66 )
{
int V_35 = 0 ;
V_29 V_67 ;
struct V_68 V_69 ;
struct V_65 * V_11 = & V_70 ;
V_11 -> V_71 = F_15 ( V_62 , 0 ) ;
if ( ! V_11 -> V_71 ) {
F_16 ( L_1 ) ;
V_35 = - V_72 ;
goto V_73;
}
V_74 = F_17 ( V_75 ) ;
V_11 -> V_76 = ( V_74 & 0xf ) + 1 ;
V_11 -> V_77 = false ;
if ( F_18 ( V_62 , L_2 , & V_67 ) )
V_67 = 1 ;
V_67 += 3 ;
if ( F_19 ( V_62 , V_67 , & V_69 ) ) {
F_20 ( L_3 ) ;
V_11 -> V_78 = 0 ;
} else if ( ! F_21 ( V_69 . V_79 ) ) {
F_22 ( L_4 ,
( unsigned long long ) V_69 . V_79 ) ;
V_11 -> V_78 = 0 ;
} else if ( ! F_21 ( F_23 ( & V_69 ) ) ) {
F_22 ( L_5 ,
( unsigned long long ) F_23 ( & V_69 ) ,
V_80 ) ;
V_11 -> V_78 = 0 ;
} else {
V_11 -> V_78 = V_69 . V_79 ;
V_11 -> V_77 = true ;
F_24 ( & V_81 ,
V_18 ) ;
}
if ( V_11 -> V_78 == 0 )
F_20 ( L_6 ) ;
F_24 ( & V_82 , V_13 ) ;
V_11 -> V_83 = NULL ;
V_11 -> type = V_84 ;
V_11 -> V_85 = V_86 ;
F_20 ( L_7 , V_62 -> V_87 ,
V_69 . V_79 , V_11 -> V_71 ) ;
* V_64 = & V_88 ;
* V_66 = V_11 ;
V_73:
F_25 ( V_62 ) ;
return V_35 ;
}
