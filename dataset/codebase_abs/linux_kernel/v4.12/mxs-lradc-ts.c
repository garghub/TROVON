static bool F_1 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_3 + V_4 ) &
V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_7 )
{
F_4 ( F_5 ( V_6 ) ,
V_2 -> V_3 + V_8 + V_9 ) ;
F_4 ( F_6 ( V_6 , V_7 ) ,
V_2 -> V_3 + V_8 + V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_7 )
{
F_4 ( V_11 |
F_8 ( V_2 -> V_12 - 1 ) ,
V_2 -> V_3 + F_9 ( V_7 ) ) ;
F_4 ( V_13 ,
V_2 -> V_3 + F_9 ( V_7 ) + V_9 ) ;
F_4 ( F_10 ( 1 << V_7 ) | F_11 ( 0 ) |
F_12 ( V_2 -> V_12 - 1 ) |
F_13 ( V_2 -> V_14 - 1 ) ,
V_2 -> V_3 + F_14 ( 3 ) ) ;
F_4 ( F_15 ( V_7 ) ,
V_2 -> V_3 + V_15 + V_9 ) ;
F_4 ( F_10 ( 0 ) | F_11 ( F_16 ( 3 ) ) |
V_16 | F_13 ( V_2 -> V_17 ) ,
V_2 -> V_3 + F_14 ( 2 ) ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned int V_18 , unsigned int V_19 )
{
T_1 V_20 ;
V_20 = V_11 |
F_8 ( V_2 -> V_12 - 1 ) ;
F_4 ( V_20 , V_2 -> V_3 + F_9 ( V_18 ) ) ;
F_4 ( V_20 , V_2 -> V_3 + F_9 ( V_19 ) ) ;
F_4 ( V_13 ,
V_2 -> V_3 + F_9 ( V_18 ) + V_9 ) ;
F_4 ( V_13 ,
V_2 -> V_3 + F_9 ( V_19 ) + V_9 ) ;
F_4 ( F_10 ( 1 << V_18 ) | F_10 ( 1 << V_19 ) |
F_11 ( 0 ) |
F_12 ( V_2 -> V_12 - 1 ) |
F_13 ( V_2 -> V_14 - 1 ) ,
V_2 -> V_3 + F_14 ( 3 ) ) ;
F_4 ( F_15 ( V_19 ) ,
V_2 -> V_3 + V_15 + V_9 ) ;
F_4 ( F_10 ( 0 ) | F_11 ( F_16 ( 3 ) ) |
V_16 | F_13 ( V_2 -> V_17 ) ,
V_2 -> V_3 + F_14 ( 2 ) ) ;
}
static unsigned int F_18 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
T_1 V_20 ;
unsigned int V_22 , V_23 ;
V_20 = F_2 ( V_2 -> V_3 + F_9 ( V_21 ) ) ;
if ( V_20 & V_11 )
V_22 = V_2 -> V_12 ;
else
V_22 = 1 ;
V_23 = ( V_20 & V_13 ) >> V_24 ;
return V_23 / V_22 ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
unsigned int V_18 , unsigned int V_19 )
{
T_1 V_20 , V_25 ;
unsigned int V_26 , V_27 , V_28 ;
V_25 = F_15 ( V_18 ) | F_15 ( V_19 ) ;
V_20 = F_2 ( V_2 -> V_3 + V_15 ) & V_25 ;
while ( V_20 != V_25 ) {
V_20 = F_2 ( V_2 -> V_3 + V_15 ) & V_25 ;
F_20 ( V_2 -> V_29 , L_1 , V_20 ) ;
}
V_27 = F_18 ( V_2 , V_18 ) ;
V_28 = F_18 ( V_2 , V_19 ) ;
if ( V_28 == 0 ) {
F_21 ( V_2 -> V_29 , L_2 ) ;
return 1 << ( V_30 - 1 ) ;
}
V_26 = V_27 ;
V_26 *= ( 1 << V_30 ) ;
V_26 /= V_28 ;
F_20 ( V_2 -> V_29 , L_3 , V_26 ) ;
return V_26 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_25 ,
V_2 -> V_3 + V_35 + V_9 ) ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_36 ,
V_2 -> V_3 + V_35 + V_10 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_25 ,
V_2 -> V_3 + V_35 + V_9 ) ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_37 ,
V_2 -> V_3 + V_35 + V_10 ) ;
V_2 -> V_38 = V_39 ;
F_3 ( V_2 , V_40 , V_41 ) ;
F_7 ( V_2 , V_40 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_25 ,
V_2 -> V_3 + V_35 + V_9 ) ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_42 ,
V_2 -> V_3 + V_35 + V_10 ) ;
V_2 -> V_38 = V_43 ;
F_3 ( V_2 , V_40 , V_44 ) ;
F_7 ( V_2 , V_40 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_25 ,
V_2 -> V_3 + V_35 + V_9 ) ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_26 ,
V_2 -> V_3 + V_35 + V_10 ) ;
V_2 -> V_38 = V_45 ;
F_3 ( V_2 , V_40 , V_46 ) ;
F_3 ( V_2 , V_47 , V_48 ) ;
F_17 ( V_2 , V_47 ,
V_40 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
V_2 -> V_38 = V_49 ;
F_4 ( V_50 | V_51 ,
V_2 -> V_3 + V_15 + V_9 ) ;
F_4 ( V_51 ,
V_2 -> V_3 + V_15 + V_10 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_4 ( V_51 ,
V_2 -> V_3 + V_15 + V_9 ) ;
F_4 ( F_28 ( V_40 ) ,
V_2 -> V_3 + V_15 + V_10 ) ;
F_24 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_52 , V_53 , V_2 -> V_54 ) ;
F_30 ( V_2 -> V_52 , V_55 , V_2 -> V_56 ) ;
F_30 ( V_2 -> V_52 , V_57 , V_2 -> V_58 ) ;
F_31 ( V_2 -> V_52 , V_59 , 1 ) ;
F_32 ( V_2 -> V_52 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
V_2 -> V_38 = V_60 ;
F_4 ( 0 , V_2 -> V_3 + F_9 ( V_40 ) ) ;
F_4 ( F_15 ( V_40 ) |
F_15 ( V_47 ) ,
V_2 -> V_3 + V_15 + V_9 ) ;
F_4 ( F_10 ( 1 << V_40 ) |
V_16 | F_13 ( 10 ) ,
V_2 -> V_3 + F_14 ( 2 ) ) ;
}
static void F_34 ( struct V_1 * V_2 , bool V_61 )
{
if ( V_61 && F_1 ( V_2 ) ) {
V_2 -> V_62 = true ;
F_29 ( V_2 ) ;
}
if ( F_1 ( V_2 ) ) {
F_24 ( V_2 ) ;
return;
}
if ( V_2 -> V_62 ) {
V_2 -> V_62 = false ;
F_31 ( V_2 -> V_52 , V_59 , 0 ) ;
F_32 ( V_2 -> V_52 ) ;
}
V_2 -> V_38 = V_49 ;
F_4 ( 0 , V_2 -> V_3 + F_14 ( 2 ) ) ;
F_4 ( 0 , V_2 -> V_3 + F_14 ( 3 ) ) ;
F_4 ( V_50 |
F_28 ( V_40 ) |
F_15 ( V_40 ) ,
V_2 -> V_3 + V_15 + V_9 ) ;
F_4 ( V_51 ,
V_2 -> V_3 + V_15 + V_10 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_38 ) {
case V_49 :
if ( F_1 ( V_2 ) )
F_27 ( V_2 ) ;
F_4 ( V_50 ,
V_2 -> V_3 + V_15 + V_9 ) ;
return;
case V_43 :
V_2 -> V_56 =
F_18 ( V_2 , V_40 ) ;
F_23 ( V_2 ) ;
return;
case V_39 :
V_2 -> V_54 =
F_18 ( V_2 , V_40 ) ;
F_25 ( V_2 ) ;
return;
case V_45 :
V_2 -> V_58 =
F_19 ( V_2 ,
V_47 ,
V_40 ) ;
F_33 ( V_2 ) ;
return;
case V_60 :
F_34 ( V_2 , 1 ) ;
break;
}
}
static T_2 F_36 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
struct V_31 * V_32 = V_2 -> V_32 ;
unsigned long V_20 = F_2 ( V_2 -> V_3 + V_15 ) ;
T_1 V_65 = F_37 ( V_32 ) ;
const T_1 V_66 =
V_50 |
F_15 ( V_40 ) |
F_15 ( V_47 ) ;
unsigned long V_67 ;
if ( ! ( V_20 & F_37 ( V_32 ) ) )
return V_68 ;
if ( V_20 & V_66 ) {
F_38 ( & V_2 -> V_69 , V_67 ) ;
F_35 ( V_2 ) ;
F_39 ( & V_2 -> V_69 , V_67 ) ;
V_65 &= ~ ( F_15 ( V_40 ) |
F_15 ( V_47 ) ) ;
F_4 ( V_20 & V_65 ,
V_2 -> V_3 + V_15 + V_9 ) ;
}
return V_70 ;
}
static int F_40 ( struct V_71 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_72 ;
struct V_31 * V_32 = V_2 -> V_32 ;
F_4 ( V_51 |
F_28 ( V_40 ) |
F_28 ( V_47 ) ,
V_2 -> V_3 + V_15 + V_9 ) ;
F_4 ( V_33 [ V_32 -> V_34 ] . V_25 ,
V_2 -> V_3 + V_35 + V_9 ) ;
F_4 ( V_32 -> V_73 << V_74 ,
V_2 -> V_3 + V_15 + V_9 ) ;
for ( V_72 = 1 ; V_72 < V_75 ; V_72 ++ )
F_4 ( 0 , V_2 -> V_3 + F_14 ( V_72 ) ) ;
}
static void F_43 ( struct V_71 * V_29 )
{
struct V_1 * V_2 = F_41 ( V_29 ) ;
F_42 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
if ( V_32 -> V_34 == V_76 ) {
F_4 ( V_77 ,
V_2 -> V_3 + V_35 + V_9 ) ;
if ( V_32 -> V_78 == V_79 )
F_4 ( V_77 ,
V_2 -> V_3 + V_35 + V_10 ) ;
}
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_71 * V_80 = V_2 -> V_52 ;
struct V_81 * V_29 = V_2 -> V_29 ;
V_80 = F_46 ( V_29 ) ;
if ( ! V_80 )
return - V_82 ;
V_80 -> V_83 = L_4 ;
V_80 -> V_84 . V_85 = V_86 ;
V_80 -> V_87 = F_40 ;
V_80 -> V_88 = F_43 ;
F_47 ( V_89 , V_80 -> V_90 ) ;
F_48 ( V_80 , V_91 , V_59 ) ;
F_49 ( V_80 , V_53 , 0 , V_92 , 0 , 0 ) ;
F_49 ( V_80 , V_55 , 0 , V_92 , 0 , 0 ) ;
F_49 ( V_80 , V_57 , 0 , V_92 ,
0 , 0 ) ;
V_2 -> V_52 = V_80 ;
F_50 ( V_80 , V_2 ) ;
return F_51 ( V_80 ) ;
}
static int F_52 ( struct V_93 * V_94 )
{
struct V_81 * V_29 = & V_94 -> V_29 ;
struct V_95 * V_96 = V_29 -> V_97 -> V_98 ;
struct V_31 * V_32 = F_53 ( V_29 -> V_97 ) ;
struct V_1 * V_2 ;
struct V_99 * V_100 ;
int V_101 , V_63 , V_102 , V_72 ;
T_1 V_103 = 0 , V_104 ;
V_2 = F_54 ( V_29 , sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 )
return - V_82 ;
F_55 ( V_94 , V_2 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_29 = V_29 ;
F_56 ( & V_2 -> V_69 ) ;
V_100 = F_57 ( V_94 , V_106 , 0 ) ;
V_2 -> V_3 = F_58 ( V_29 , V_100 -> V_107 , F_59 ( V_100 ) ) ;
if ( F_60 ( V_2 -> V_3 ) )
return F_61 ( V_2 -> V_3 ) ;
V_101 = F_62 ( V_96 , L_5 ,
& V_103 ) ;
if ( V_101 )
return V_101 ;
if ( F_62 ( V_96 , L_6 , & V_104 ) ) {
V_2 -> V_12 = 4 ;
} else {
if ( V_104 >= 1 && V_104 <= 32 ) {
V_2 -> V_12 = V_104 ;
} else {
F_63 ( V_2 -> V_29 , L_7 ,
V_104 ) ;
return - V_108 ;
}
}
if ( F_62 ( V_96 , L_8 , & V_104 ) ) {
V_2 -> V_14 = 2 ;
} else {
if ( V_104 >= 2 && V_104 <= V_109 + 1 ) {
V_2 -> V_14 = V_104 ;
} else {
F_63 ( V_2 -> V_29 , L_9 ,
V_104 ) ;
return - V_108 ;
}
}
if ( F_62 ( V_96 , L_10 , & V_104 ) ) {
V_2 -> V_17 = 10 ;
} else {
if ( V_104 >= 1 && V_104 <= V_109 ) {
V_2 -> V_17 = V_104 ;
} else {
F_63 ( V_2 -> V_29 , L_11 ,
V_104 ) ;
return - V_108 ;
}
}
V_101 = F_64 ( V_2 -> V_3 ) ;
if ( V_101 )
return V_101 ;
F_44 ( V_2 ) ;
for ( V_72 = 0 ; V_72 < 3 ; V_72 ++ ) {
V_63 = F_65 ( V_94 , V_110 [ V_72 ] ) ;
if ( V_63 < 0 )
return V_63 ;
V_102 = F_66 ( V_96 , V_63 ) ;
F_42 ( V_2 ) ;
V_101 = F_67 ( V_29 , V_102 ,
F_36 ,
0 , V_110 [ V_72 ] , V_2 ) ;
if ( V_101 )
return V_101 ;
}
return F_45 ( V_2 ) ;
}
