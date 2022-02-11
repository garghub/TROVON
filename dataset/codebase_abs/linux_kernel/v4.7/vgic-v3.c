static struct V_1 F_1 ( const struct V_2 * V_3 , int V_4 )
{
struct V_1 V_5 ;
T_1 V_6 = V_3 -> V_7 . V_8 . V_9 . V_1 [ V_4 ] ;
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
if ( V_6 & V_27 ) {
V_5 . V_20 |= V_28 ;
V_5 . V_29 = ( V_6 >> V_30 ) & F_2 ( 9 , 0 ) ;
}
return V_5 ;
}
static void F_3 ( struct V_2 * V_3 , int V_4 ,
struct V_1 V_5 )
{
T_1 V_31 ;
V_31 = V_5 . V_14 ;
switch ( V_3 -> V_10 -> V_7 . V_11 . V_12 ) {
case V_13 :
V_31 |= V_32 ;
break;
case V_18 :
if ( V_5 . V_14 < V_33 )
V_31 |= ( V_34 ) V_5 . V_17 << V_19 ;
break;
default:
F_4 () ;
}
if ( V_5 . V_20 & V_22 )
V_31 |= V_21 ;
if ( V_5 . V_20 & V_24 )
V_31 |= V_23 ;
if ( V_5 . V_20 & V_26 )
V_31 |= V_25 ;
if ( V_5 . V_20 & V_28 ) {
V_31 |= V_27 ;
V_31 |= ( ( T_1 ) V_5 . V_29 ) << V_30 ;
}
V_3 -> V_7 . V_8 . V_9 . V_1 [ V_4 ] = V_31 ;
if ( ! ( V_5 . V_20 & V_35 ) )
V_3 -> V_7 . V_8 . V_9 . V_36 |= ( 1U << V_4 ) ;
else
V_3 -> V_7 . V_8 . V_9 . V_36 &= ~ ( 1U << V_4 ) ;
}
static T_1 F_5 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_36 ;
}
static T_1 F_6 ( const struct V_2 * V_3 )
{
return V_3 -> V_7 . V_8 . V_9 . V_37 ;
}
static void F_7 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_37 = 0 ;
}
static V_34 F_8 ( const struct V_2 * V_3 )
{
V_34 V_38 = V_3 -> V_7 . V_8 . V_9 . V_39 ;
V_34 V_40 = 0 ;
if ( V_38 & V_41 )
V_40 |= V_42 ;
if ( V_38 & V_43 )
V_40 |= V_44 ;
return V_40 ;
}
static void F_9 ( struct V_2 * V_3 , struct V_45 * V_46 )
{
V_34 V_47 = V_3 -> V_7 . V_8 . V_9 . V_45 ;
V_46 -> V_48 = ( V_47 & V_49 ) >> V_50 ;
V_46 -> V_51 = ( V_47 & V_52 ) >> V_53 ;
V_46 -> V_54 = ( V_47 & V_55 ) >> V_56 ;
V_46 -> V_57 = ( V_47 & V_58 ) >> V_59 ;
}
static void F_10 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_60 |= V_61 ;
}
static void F_11 ( struct V_2 * V_3 )
{
V_3 -> V_7 . V_8 . V_9 . V_60 &= ~ V_61 ;
}
static void F_12 ( struct V_2 * V_3 , struct V_45 * V_46 )
{
V_34 V_47 ;
V_47 = ( V_46 -> V_48 << V_50 ) & V_49 ;
V_47 |= ( V_46 -> V_51 << V_53 ) & V_52 ;
V_47 |= ( V_46 -> V_54 << V_56 ) & V_55 ;
V_47 |= ( V_46 -> V_57 << V_59 ) & V_58 ;
V_3 -> V_7 . V_8 . V_9 . V_45 = V_47 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_62 * V_9 = & V_3 -> V_7 . V_8 . V_9 ;
V_9 -> V_45 = 0 ;
V_9 -> V_36 = ~ 0 ;
if ( V_3 -> V_10 -> V_7 . V_11 . V_12 == V_13 )
V_9 -> V_63 = V_64 ;
else
V_9 -> V_63 = 0 ;
V_9 -> V_60 = V_65 ;
}
static void F_14 ( void * V_66 )
{
F_15 ( V_67 ) ;
}
int F_16 ( const struct V_68 * V_68 ,
const struct V_69 * * V_70 ,
const struct V_71 * * V_66 )
{
int V_40 = 0 ;
struct V_71 * V_11 = & V_72 ;
const struct V_73 * V_74 = & V_68 -> V_3 ;
V_11 -> V_75 = V_68 -> V_75 ;
V_76 = F_15 ( V_77 ) ;
V_11 -> V_78 = ( V_76 & 0xf ) + 1 ;
V_11 -> V_79 = false ;
if ( ! V_74 -> V_80 ) {
F_17 ( L_1 ) ;
V_11 -> V_81 = 0 ;
} else if ( ! F_18 ( V_74 -> V_80 ) ) {
F_19 ( L_2 ,
( unsigned long long ) V_74 -> V_80 ) ;
V_11 -> V_81 = 0 ;
} else if ( ! F_18 ( F_20 ( V_74 ) ) ) {
F_19 ( L_3 ,
( unsigned long long ) F_20 ( V_74 ) ,
V_82 ) ;
} else {
V_11 -> V_81 = V_74 -> V_80 ;
V_11 -> V_79 = true ;
F_21 ( & V_83 ,
V_18 ) ;
}
if ( V_11 -> V_81 == 0 )
F_17 ( L_4 ) ;
F_21 ( & V_84 , V_13 ) ;
V_11 -> V_85 = NULL ;
V_11 -> type = V_86 ;
V_11 -> V_87 = V_88 ;
F_17 ( L_5 ,
V_11 -> V_81 , V_11 -> V_75 ) ;
F_22 ( F_14 , V_11 , 1 ) ;
* V_70 = & V_89 ;
* V_66 = V_11 ;
return V_40 ;
}
