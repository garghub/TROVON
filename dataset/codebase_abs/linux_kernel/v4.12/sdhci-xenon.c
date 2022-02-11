static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_2 , V_5 ) ;
V_3 |= V_6 ;
F_3 ( V_2 , V_3 , V_5 ) ;
V_4 = F_4 ( F_5 () , 20 ) ;
while ( ! ( ( V_3 = F_6 ( V_2 , V_5 ) )
& V_7 ) ) {
if ( F_7 ( F_5 () , V_4 ) ) {
F_8 ( F_9 ( V_2 -> V_8 ) , L_1 ) ;
return - V_9 ;
}
F_10 ( 900 , 1100 ) ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned char V_10 , bool V_11 )
{
T_1 V_3 ;
T_1 V_12 ;
V_3 = F_2 ( V_2 , V_13 ) ;
V_12 = ( 0x1 << ( V_14 + V_10 ) ) ;
if ( V_11 )
V_3 |= V_12 ;
else
V_3 &= ~ V_12 ;
F_3 ( V_2 , V_3 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 , bool V_11 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_13 ) ;
if ( V_11 )
V_3 &= ~ V_15 ;
else
V_3 |= V_15 ;
F_3 ( V_2 , V_3 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned char V_10 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_13 ) ;
V_3 |= ( F_14 ( V_10 ) << V_16 ) ;
F_3 ( V_2 , V_3 , V_13 ) ;
V_2 -> V_8 -> V_17 |= V_18 ;
V_2 -> V_8 -> V_17 &= ~ V_19 ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned char V_10 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_13 ) ;
V_3 &= ~ ( F_14 ( V_10 ) << V_16 ) ;
F_3 ( V_2 , V_3 , V_13 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned char V_10 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_20 ) ;
V_3 |= F_14 ( V_10 ) ;
F_3 ( V_2 , V_3 , V_20 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_20 ) ;
V_3 |= V_21 ;
F_3 ( V_2 , V_3 , V_20 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_26 ) ;
V_3 &= ~ V_27 ;
F_3 ( V_2 , V_3 , V_26 ) ;
V_3 = F_2 ( V_2 , V_28 ) ;
V_3 &= ~ V_29 ;
F_3 ( V_2 , V_3 , V_28 ) ;
V_3 = F_2 ( V_2 , V_30 ) ;
V_3 &= ~ V_29 ;
F_3 ( V_2 , V_3 , V_30 ) ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = 1 << ( V_25 -> V_33 - 1 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned char V_10 , T_3 V_12 )
{
if ( ! ( V_12 & V_34 ) )
return;
F_18 ( V_2 ) ;
F_12 ( V_2 , true ) ;
F_11 ( V_2 , V_10 , false ) ;
F_17 ( V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_3 V_12 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
F_23 ( V_2 , V_12 ) ;
F_21 ( V_2 , V_25 -> V_10 , V_12 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned int V_35 )
{
T_4 V_36 ;
V_36 = F_6 ( V_2 , V_37 ) ;
V_36 &= ~ V_38 ;
if ( V_35 == V_39 )
V_36 |= V_40 ;
else if ( V_35 == V_41 )
V_36 |= V_42 ;
else if ( V_35 == V_43 )
V_36 |= V_44 ;
else if ( V_35 == V_45 )
V_36 |= V_46 ;
else if ( V_35 == V_47 )
V_36 |= V_48 ;
else if ( ( V_35 == V_49 ) ||
( V_35 == V_50 ) )
V_36 |= V_51 ;
else if ( V_35 == V_52 )
V_36 |= V_53 ;
F_25 ( V_2 , V_36 , V_37 ) ;
}
static void F_26 ( struct V_54 * V_8 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_27 ( V_8 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_3 ;
if ( ( V_56 -> V_35 == V_52 ) ||
( V_56 -> V_35 == V_39 ) ||
( V_56 -> V_35 == V_57 ) ) {
V_2 -> V_58 = false ;
V_2 -> V_59 |= V_60 ;
V_2 -> V_61 &= ~ V_62 ;
V_3 = F_6 ( V_2 , V_37 ) ;
V_3 &= ~ V_63 ;
F_25 ( V_2 , V_3 , V_37 ) ;
} else {
V_2 -> V_59 &= ~ V_60 ;
}
F_28 ( V_8 , V_56 ) ;
F_29 ( V_2 , V_56 ) ;
if ( V_2 -> clock > V_64 )
F_11 ( V_2 , V_25 -> V_10 , true ) ;
}
static int F_30 ( struct V_54 * V_8 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_27 ( V_8 ) ;
F_1 ( V_2 ) ;
F_31 ( V_2 , V_56 -> V_65 ) ;
if ( F_32 ( V_8 -> V_66 . V_67 ) == - V_68 )
return 0 ;
return F_33 ( V_8 , V_56 ) ;
}
static void F_34 ( struct V_54 * V_8 , struct V_69 * V_70 )
{
struct V_1 * V_2 = F_27 ( V_8 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
V_25 -> V_71 = V_70 -> type ;
}
static int F_35 ( struct V_54 * V_8 , T_1 V_72 )
{
struct V_1 * V_2 = F_27 ( V_8 ) ;
if ( V_2 -> V_35 == V_49 )
return 0 ;
if ( V_2 -> V_31 != V_32 )
F_18 ( V_2 ) ;
return F_36 ( V_8 , V_72 ) ;
}
static void F_37 ( struct V_54 * V_8 , int V_11 )
{
struct V_1 * V_2 = F_27 ( V_8 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_3 ;
T_3 V_10 = V_25 -> V_10 ;
F_38 ( V_8 , V_11 ) ;
if ( V_11 ) {
V_3 = F_2 ( V_2 , V_73 ) ;
V_3 |= ( 1 << ( V_10 + V_74 ) ) ;
F_3 ( V_2 , V_3 , V_73 ) ;
} else {
V_3 = F_2 ( V_2 , V_73 ) ;
V_3 &= ~ ( 1 << ( V_10 + V_74 ) ) ;
F_3 ( V_2 , V_3 , V_73 ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
V_2 -> V_75 . V_76 = F_26 ;
V_2 -> V_75 . V_77 =
F_30 ;
V_2 -> V_75 . V_78 = F_34 ;
V_2 -> V_75 . V_79 = F_35 ;
V_2 -> V_75 . V_80 = F_37 ;
}
static int F_40 ( struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 . V_86 ;
struct V_1 * V_2 = F_41 ( V_82 ) ;
struct V_54 * V_8 = V_2 -> V_8 ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_1 V_10 , V_87 ;
T_1 V_33 ;
if ( F_42 ( V_84 , L_2 ) )
V_2 -> V_59 |= V_88 ;
V_10 = 0x0 ;
if ( ! F_43 ( V_84 , L_3 , & V_10 ) ) {
V_87 = F_2 ( V_2 , V_73 ) ;
V_87 &= V_89 ;
if ( F_44 ( V_10 > V_87 ) ) {
F_8 ( F_9 ( V_8 ) , L_4 ,
V_10 , V_87 ) ;
return - V_90 ;
}
}
V_25 -> V_10 = V_10 ;
V_33 = V_91 ;
if ( ! F_43 ( V_84 , L_5 ,
& V_33 ) ) {
if ( F_44 ( V_33 >= V_92 ) ) {
F_8 ( F_9 ( V_8 ) , L_6 ,
V_91 ) ;
V_33 = V_91 ;
}
}
V_25 -> V_33 = V_33 ;
return F_45 ( V_84 , V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_3 V_10 = V_25 -> V_10 ;
F_13 ( V_2 , V_10 ) ;
F_12 ( V_2 , true ) ;
F_16 ( V_2 , V_10 ) ;
F_11 ( V_2 , V_10 , false ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_19 ( V_2 ) ;
struct V_24 * V_25 = F_20 ( V_23 ) ;
T_3 V_10 = V_25 -> V_10 ;
F_15 ( V_2 , V_10 ) ;
}
static int F_48 ( struct V_81 * V_82 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
int V_93 ;
V_2 = F_49 ( V_82 , & V_94 ,
sizeof( struct V_24 ) ) ;
if ( F_50 ( V_2 ) )
return F_32 ( V_2 ) ;
V_23 = F_19 ( V_2 ) ;
V_25 = F_20 ( V_23 ) ;
F_39 ( V_2 ) ;
V_23 -> V_95 = F_51 ( & V_82 -> V_85 , L_7 ) ;
if ( F_50 ( V_23 -> V_95 ) ) {
V_93 = F_32 ( V_23 -> V_95 ) ;
F_8 ( & V_82 -> V_85 , L_8 , V_93 ) ;
goto V_96;
}
V_93 = F_52 ( V_23 -> V_95 ) ;
if ( V_93 )
goto V_96;
V_93 = F_53 ( V_2 -> V_8 ) ;
if ( V_93 )
goto V_97;
F_54 ( V_82 ) ;
F_12 ( V_2 , false ) ;
V_93 = F_40 ( V_82 ) ;
if ( V_93 )
goto V_97;
V_93 = F_46 ( V_2 ) ;
if ( V_93 )
goto V_97;
V_93 = F_55 ( V_2 ) ;
if ( V_93 )
goto V_98;
return 0 ;
V_98:
F_47 ( V_2 ) ;
V_97:
F_56 ( V_23 -> V_95 ) ;
V_96:
F_57 ( V_82 ) ;
return V_93 ;
}
static int F_58 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_41 ( V_82 ) ;
struct V_22 * V_23 = F_19 ( V_2 ) ;
F_59 ( V_2 , 0 ) ;
F_47 ( V_2 ) ;
F_56 ( V_23 -> V_95 ) ;
F_57 ( V_82 ) ;
return 0 ;
}
