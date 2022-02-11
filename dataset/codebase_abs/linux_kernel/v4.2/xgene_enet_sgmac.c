static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_7 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_8 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_9 = V_8 -> V_10 + V_3 ;
F_2 ( V_4 , V_9 ) ;
}
static bool F_6 ( struct V_11 * V_12 ,
T_1 V_13 , T_1 V_14 )
{
int V_15 ;
F_2 ( V_13 , V_12 -> V_9 ) ;
F_2 ( V_14 , V_12 -> V_12 ) ;
F_2 ( V_16 , V_12 -> V_17 ) ;
for ( V_15 = 0 ; V_15 < 10 ; V_15 ++ ) {
if ( F_7 ( V_12 -> V_18 ) ) {
F_2 ( 0 , V_12 -> V_17 ) ;
return true ;
}
F_8 ( 1 ) ;
}
return false ;
}
static void F_9 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_14 )
{
struct V_11 V_12 = {
. V_9 = V_2 -> V_19 + V_20 ,
. V_12 = V_2 -> V_19 + V_21 ,
. V_17 = V_2 -> V_19 + V_22 ,
. V_18 = V_2 -> V_19 + V_23
} ;
if ( ! F_6 ( & V_12 , V_13 , V_14 ) )
F_10 ( V_2 -> V_24 , L_1 , V_13 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_7 ( V_2 -> V_5 + V_3 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_7 ( V_2 -> V_7 + V_3 ) ;
}
static T_1 F_13 ( struct V_11 * V_12 , T_1 V_25 )
{
T_1 V_26 ;
int V_15 ;
F_2 ( V_25 , V_12 -> V_9 ) ;
F_2 ( V_27 , V_12 -> V_17 ) ;
for ( V_15 = 0 ; V_15 < 10 ; V_15 ++ ) {
if ( F_7 ( V_12 -> V_18 ) ) {
V_26 = F_7 ( V_12 -> V_12 ) ;
F_2 ( 0 , V_12 -> V_17 ) ;
return V_26 ;
}
F_8 ( 1 ) ;
}
F_14 ( L_2 , V_28 , V_25 ) ;
return 0 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_1 V_25 )
{
struct V_11 V_12 = {
. V_9 = V_2 -> V_19 + V_20 ,
. V_12 = V_2 -> V_19 + V_29 ,
. V_17 = V_2 -> V_19 + V_22 ,
. V_18 = V_2 -> V_19 + V_23
} ;
return F_13 ( & V_12 , V_25 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_30 * V_24 = V_2 -> V_24 ;
T_1 V_31 ;
int V_15 = 0 ;
F_4 ( V_2 , V_32 , 0 ) ;
do {
F_17 ( 100 , 110 ) ;
V_31 = F_12 ( V_2 , V_33 ) ;
if ( V_31 == ~ 0U )
return 0 ;
} while ( ++ V_15 < 10 );
F_10 ( V_24 , L_3 ) ;
return - V_34 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_35 == V_36 ) ? 0xffffffff : 0 ;
F_3 ( V_2 , V_37 , V_4 ) ;
F_3 ( V_2 , V_38 , V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_3 V_39 ,
T_1 V_40 , T_4 V_31 )
{
T_1 V_9 , V_14 , V_41 ;
int V_15 ;
V_9 = F_20 ( V_39 ) | F_21 ( V_40 ) ;
F_9 ( V_2 , V_42 , V_9 ) ;
V_14 = F_22 ( V_31 ) ;
F_9 ( V_2 , V_43 , V_14 ) ;
for ( V_15 = 0 ; V_15 < 10 ; V_15 ++ ) {
V_41 = F_15 ( V_2 , V_44 ) ;
if ( ! ( V_41 & V_45 ) )
return;
F_17 ( 10 , 20 ) ;
}
F_10 ( V_2 -> V_24 , L_4 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_3 V_39 , T_1 V_40 )
{
T_1 V_9 , V_31 , V_41 ;
int V_15 ;
V_9 = F_20 ( V_39 ) | F_21 ( V_40 ) ;
F_9 ( V_2 , V_42 , V_9 ) ;
F_9 ( V_2 , V_46 , V_47 ) ;
for ( V_15 = 0 ; V_15 < 10 ; V_15 ++ ) {
V_41 = F_15 ( V_2 , V_44 ) ;
if ( ! ( V_41 & V_45 ) ) {
V_31 = F_15 ( V_2 , V_48 ) ;
F_9 ( V_2 , V_46 , 0 ) ;
return V_31 ;
}
F_17 ( 10 , 20 ) ;
}
F_10 ( V_2 -> V_24 , L_5 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_49 , V_50 ) ;
F_9 ( V_2 , V_49 , 0 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_51 , V_52 ;
T_3 * V_53 = V_2 -> V_24 -> V_53 ;
V_51 = ( V_53 [ 3 ] << 24 ) | ( V_53 [ 2 ] << 16 ) |
( V_53 [ 1 ] << 8 ) | V_53 [ 0 ] ;
F_9 ( V_2 , V_54 , V_51 ) ;
V_52 = F_15 ( V_2 , V_55 ) ;
V_52 |= ( V_53 [ 5 ] << 24 ) | ( V_53 [ 4 ] << 16 ) ;
F_9 ( V_2 , V_55 , V_52 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 )
{
T_1 V_31 ;
V_31 = F_23 ( V_2 , V_56 ,
V_57 >> 2 ) ;
return V_31 & V_58 ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_31 , V_59 = 10 ;
T_1 V_3 = V_2 -> V_60 * 4 ;
T_1 V_61 , V_62 ;
T_1 V_63 , V_64 ;
F_24 ( V_2 ) ;
F_19 ( V_2 , V_56 , V_65 >> 2 , 0x1000 ) ;
F_19 ( V_2 , V_56 , V_66 >> 2 , 0 ) ;
while ( V_59 -- ) {
V_31 = F_23 ( V_2 , V_56 ,
V_67 >> 2 ) ;
if ( ( V_31 & V_68 ) && ( V_31 & V_69 ) )
break;
F_17 ( 1000 , 2000 ) ;
}
if ( ! ( V_31 & V_68 ) || ! ( V_31 & V_69 ) )
F_10 ( V_2 -> V_24 , L_6 ) ;
V_31 = F_15 ( V_2 , V_70 ) ;
F_28 ( & V_31 , 2 ) ;
F_9 ( V_2 , V_70 , V_31 | V_71 ) ;
F_9 ( V_2 , V_72 , V_73 ) ;
if ( V_2 -> V_35 == V_36 ) {
V_61 = V_74 ;
V_62 = V_75 ;
V_63 = V_76 ;
V_64 = V_77 ;
} else {
V_61 = V_78 ;
V_62 = V_79 ;
V_63 = V_80 ;
V_64 = V_81 ;
}
V_31 = F_11 ( V_2 , V_61 ) ;
V_31 |= V_82 ;
F_1 ( V_2 , V_61 , V_31 ) ;
F_25 ( V_2 ) ;
V_31 = F_15 ( V_2 , V_83 ) ;
F_29 ( & V_31 , 7 ) ;
F_9 ( V_2 , V_83 , V_31 ) ;
V_31 = F_11 ( V_2 , V_62 ) ;
V_31 |= V_84 ;
F_1 ( V_2 , V_62 , V_31 ) ;
F_1 ( V_2 , V_85 , 0x84 ) ;
F_1 ( V_2 , V_63 , V_86 ) ;
F_5 ( V_2 , V_64 + V_3 , V_87 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_88 , bool V_89 )
{
T_1 V_31 ;
V_31 = F_15 ( V_2 , V_49 ) ;
if ( V_89 )
V_31 |= V_88 ;
else
V_31 &= ~ V_88 ;
F_9 ( V_2 , V_49 , V_31 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_90 , true ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_91 , true ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_90 , false ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_91 , false ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
if ( ! F_36 ( V_2 ) )
return - V_34 ;
if ( ! F_37 ( V_2 -> V_92 ) ) {
F_38 ( V_2 -> V_92 ) ;
F_39 ( V_2 -> V_92 ) ;
F_38 ( V_2 -> V_92 ) ;
}
F_16 ( V_2 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
T_1 V_93 , T_4 V_94 )
{
T_1 V_31 , V_95 ;
T_1 V_96 , V_97 ;
T_1 V_3 = V_2 -> V_60 * V_98 ;
if ( V_2 -> V_35 == V_36 ) {
V_96 = V_99 ;
V_97 = V_100 ;
} else {
V_96 = V_101 ;
V_97 = V_102 ;
}
V_31 = V_103 ;
F_1 ( V_2 , V_96 + V_3 , V_31 ) ;
V_95 = F_41 ( V_94 ) - 0x20 ;
V_31 = F_42 ( V_93 ) | F_43 ( V_95 ) ;
F_1 ( V_2 , V_97 + V_3 , V_31 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ! F_37 ( V_2 -> V_92 ) )
F_39 ( V_2 -> V_92 ) ;
}
static void F_45 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_46 ( F_47 ( V_105 ) ,
struct V_1 , V_106 ) ;
struct V_30 * V_24 = V_2 -> V_24 ;
T_1 V_107 , V_108 ;
V_107 = F_26 ( V_2 ) ;
if ( V_107 ) {
if ( ! F_48 ( V_24 ) ) {
F_49 ( V_24 ) ;
F_27 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_50 ( V_24 , L_7 ) ;
}
V_108 = V_109 ;
} else {
if ( F_48 ( V_24 ) ) {
F_33 ( V_2 ) ;
F_34 ( V_2 ) ;
F_51 ( V_24 ) ;
F_50 ( V_24 , L_8 ) ;
}
V_108 = V_110 ;
}
F_52 ( & V_2 -> V_106 , V_108 ) ;
}
