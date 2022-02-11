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
static bool F_5 ( struct V_8 * V_9 ,
T_1 V_10 , T_1 V_11 )
{
int V_12 ;
F_2 ( V_10 , V_9 -> V_13 ) ;
F_2 ( V_11 , V_9 -> V_9 ) ;
F_2 ( V_14 , V_9 -> V_15 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
if ( F_6 ( V_9 -> V_16 ) ) {
F_2 ( 0 , V_9 -> V_15 ) ;
return true ;
}
F_7 ( 1 ) ;
}
return false ;
}
static void F_8 ( struct V_1 * V_2 ,
T_1 V_10 , T_1 V_11 )
{
struct V_8 V_9 = {
. V_13 = V_2 -> V_17 + V_18 ,
. V_9 = V_2 -> V_17 + V_19 ,
. V_15 = V_2 -> V_17 + V_20 ,
. V_16 = V_2 -> V_17 + V_21
} ;
if ( ! F_5 ( & V_9 , V_10 , V_11 ) )
F_9 ( V_2 -> V_22 , L_1 , V_10 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 -> V_5 + V_3 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 -> V_7 + V_3 ) ;
}
static T_1 F_12 ( struct V_8 * V_9 , T_1 V_23 )
{
T_1 V_24 ;
int V_12 ;
F_2 ( V_23 , V_9 -> V_13 ) ;
F_2 ( V_25 , V_9 -> V_15 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
if ( F_6 ( V_9 -> V_16 ) ) {
V_24 = F_6 ( V_9 -> V_9 ) ;
F_2 ( 0 , V_9 -> V_15 ) ;
return V_24 ;
}
F_7 ( 1 ) ;
}
F_13 ( L_2 , V_26 , V_23 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 V_23 )
{
struct V_8 V_9 = {
. V_13 = V_2 -> V_17 + V_18 ,
. V_9 = V_2 -> V_17 + V_27 ,
. V_15 = V_2 -> V_17 + V_20 ,
. V_16 = V_2 -> V_17 + V_21
} ;
return F_12 ( & V_9 , V_23 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_22 = V_2 -> V_22 ;
T_1 V_29 ;
int V_12 = 0 ;
F_4 ( V_2 , V_30 , 0 ) ;
do {
F_16 ( 100 , 110 ) ;
V_29 = F_11 ( V_2 , V_31 ) ;
if ( V_29 == ~ 0U )
return 0 ;
} while ( ++ V_12 < 10 );
F_9 ( V_22 , L_3 ) ;
return - V_32 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_4 = 0xffffffff ;
F_3 ( V_2 , V_33 , V_4 ) ;
F_3 ( V_2 , V_34 , V_4 ) ;
}
static void F_18 ( struct V_1 * V_2 , T_2 V_35 ,
T_1 V_36 , T_3 V_29 )
{
T_1 V_13 , V_11 , V_37 ;
int V_12 ;
V_13 = F_19 ( V_35 ) | F_20 ( V_36 ) ;
F_8 ( V_2 , V_38 , V_13 ) ;
V_11 = F_21 ( V_29 ) ;
F_8 ( V_2 , V_39 , V_11 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_37 = F_14 ( V_2 , V_40 ) ;
if ( ! ( V_37 & V_41 ) )
return;
F_16 ( 10 , 20 ) ;
}
F_9 ( V_2 -> V_22 , L_4 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_2 V_35 , T_1 V_36 )
{
T_1 V_13 , V_29 , V_37 ;
int V_12 ;
V_13 = F_19 ( V_35 ) | F_20 ( V_36 ) ;
F_8 ( V_2 , V_38 , V_13 ) ;
F_8 ( V_2 , V_42 , V_43 ) ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_37 = F_14 ( V_2 , V_40 ) ;
if ( ! ( V_37 & V_41 ) ) {
V_29 = F_14 ( V_2 , V_44 ) ;
F_8 ( V_2 , V_42 , 0 ) ;
return V_29 ;
}
F_16 ( 10 , 20 ) ;
}
F_9 ( V_2 -> V_22 , L_5 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_45 , V_46 ) ;
F_8 ( V_2 , V_45 , 0 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_47 , V_48 ;
T_2 * V_49 = V_2 -> V_22 -> V_49 ;
V_47 = ( V_49 [ 3 ] << 24 ) | ( V_49 [ 2 ] << 16 ) |
( V_49 [ 1 ] << 8 ) | V_49 [ 0 ] ;
F_8 ( V_2 , V_50 , V_47 ) ;
V_48 = F_14 ( V_2 , V_51 ) ;
V_48 |= ( V_49 [ 5 ] << 24 ) | ( V_49 [ 4 ] << 16 ) ;
F_8 ( V_2 , V_51 , V_48 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 )
{
T_1 V_29 ;
V_29 = F_22 ( V_2 , V_52 ,
V_53 >> 2 ) ;
return V_29 & V_54 ;
}
static void F_26 ( struct V_1 * V_2 )
{
T_1 V_29 , V_55 = 10 ;
T_1 V_3 = V_2 -> V_56 * 4 ;
F_23 ( V_2 ) ;
F_18 ( V_2 , V_52 , V_57 >> 2 , 0x1000 ) ;
F_18 ( V_2 , V_52 , V_58 >> 2 , 0 ) ;
while ( V_55 -- ) {
V_29 = F_22 ( V_2 , V_52 ,
V_59 >> 2 ) ;
if ( ( V_29 & V_60 ) && ( V_29 & V_61 ) )
break;
F_16 ( 10 , 20 ) ;
}
if ( ! ( V_29 & V_60 ) || ! ( V_29 & V_61 ) )
F_9 ( V_2 -> V_22 , L_6 ) ;
V_29 = F_14 ( V_2 , V_62 ) ;
F_27 ( & V_29 , 2 ) ;
F_8 ( V_2 , V_62 , V_29 | V_63 ) ;
F_8 ( V_2 , V_64 , V_65 ) ;
V_29 = F_10 ( V_2 , V_66 ) ;
V_29 |= V_67 ;
F_1 ( V_2 , V_66 , V_29 ) ;
F_24 ( V_2 ) ;
V_29 = F_10 ( V_2 , V_68 ) ;
V_29 |= V_69 | V_70 ;
F_1 ( V_2 , V_68 , V_29 ) ;
V_29 = F_14 ( V_2 , V_71 ) ;
F_28 ( & V_29 , 7 ) ;
F_8 ( V_2 , V_71 , V_29 ) ;
V_29 = F_10 ( V_2 , V_72 ) ;
V_29 |= V_73 ;
F_1 ( V_2 , V_72 , V_29 ) ;
F_1 ( V_2 , V_74 , 0 ) ;
F_1 ( V_2 , V_75 + V_3 , V_76 ) ;
F_1 ( V_2 , V_77 , V_78 ) ;
F_1 ( V_2 , V_79 + V_3 , V_80 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_81 , bool V_82 )
{
T_1 V_29 ;
V_29 = F_14 ( V_2 , V_45 ) ;
if ( V_82 )
V_29 |= V_81 ;
else
V_29 &= ~ V_81 ;
F_8 ( V_2 , V_45 , V_29 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_83 , true ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_84 , true ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_83 , false ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_84 , false ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
if ( ! F_35 ( V_2 ) )
return - V_32 ;
F_36 ( V_2 -> V_85 ) ;
F_37 ( V_2 -> V_85 ) ;
F_36 ( V_2 -> V_85 ) ;
F_15 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 ,
T_1 V_86 , T_3 V_87 )
{
T_1 V_29 , V_88 ;
T_1 V_3 = V_2 -> V_56 * V_89 ;
V_29 = V_90 ;
F_1 ( V_2 , V_91 + V_3 , V_29 ) ;
V_88 = F_39 ( V_87 ) - 0x20 ;
V_29 = F_40 ( V_86 ) | F_41 ( V_88 ) ;
F_1 ( V_2 , V_92 + V_3 , V_29 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_85 ) ;
}
static void F_43 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_44 ( F_45 ( V_94 ) ,
struct V_1 , V_95 ) ;
struct V_28 * V_22 = V_2 -> V_22 ;
T_1 V_96 , V_97 ;
V_96 = F_25 ( V_2 ) ;
if ( V_96 ) {
if ( ! F_46 ( V_22 ) ) {
F_47 ( V_22 ) ;
F_26 ( V_2 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_48 ( V_22 , L_7 ) ;
}
V_97 = V_98 ;
} else {
if ( F_46 ( V_22 ) ) {
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
F_49 ( V_22 ) ;
F_48 ( V_22 , L_8 ) ;
}
V_97 = V_99 ;
}
F_50 ( & V_2 -> V_95 , V_97 ) ;
}
