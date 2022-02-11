static int F_1 ( int V_1 , int V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = F_2 ( V_5 ) - 1 ; V_4 >= 0 ; V_4 -- ) {
if ( V_1 <= V_5 [ V_4 ] && V_2 >= V_5 [ V_4 ] ) {
* V_3 = V_4 ;
return 0 ;
}
}
return - V_6 ;
}
static inline int F_3 ( unsigned int V_7 )
{
if ( V_7 < 16 )
return ( V_7 * 50 ) + 900 ;
else
return ( ( V_7 - 16 ) * 100 ) + 1800 ;
}
static inline unsigned int F_4 ( int V_8 )
{
if ( V_8 < 1800 )
return ( V_8 - 900 ) / 50 ;
else
return ( ( V_8 - 1800 ) / 100 ) + 16 ;
}
static inline int F_5 ( unsigned int V_7 )
{
return ( V_7 * 25 ) + 850 ;
}
static inline unsigned int F_6 ( int V_8 )
{
return ( V_8 - 850 ) / 25 ;
}
static int F_7 ( struct V_9 * V_10 , int V_1 ,
int V_2 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_12 = F_9 ( V_10 ) ;
T_1 V_7 , V_3 ;
int V_13 ;
V_13 = F_1 ( V_1 , V_2 , & V_3 ) ;
if ( V_13 != 0 )
return V_13 ;
switch ( V_12 ) {
case V_14 :
V_7 = F_10 ( V_11 , V_15 ) &
~ V_16 ;
F_11 ( V_11 , V_15 ,
V_7 | V_3 ) ;
break;
case V_17 :
V_7 = F_10 ( V_11 , V_18 ) &
~ V_16 ;
F_11 ( V_11 , V_18 ,
V_7 | V_3 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_12 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_12 ) {
case V_14 :
V_7 = F_10 ( V_11 , V_15 ) &
V_16 ;
break;
case V_17 :
V_7 = F_10 ( V_11 , V_18 ) &
V_16 ;
break;
default:
return 0 ;
}
return ( V_5 [ V_7 ] + 50 ) / 100 ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_12 = F_9 ( V_10 ) ;
switch ( V_12 ) {
case V_14 :
switch ( V_11 -> V_19 . V_20 ) {
case V_21 :
case V_22 :
F_14 ( V_11 , V_23 ,
V_24 ) ;
F_14 ( V_11 , V_25 ,
V_26 ) ;
F_14 ( V_11 , V_27 ,
1 << ( V_11 -> V_19 . V_20 -
V_28 ) ) ;
break;
default:
return - V_6 ;
}
break;
case V_17 :
switch ( V_11 -> V_19 . V_29 ) {
case V_21 :
case V_22 :
F_14 ( V_11 , V_23 ,
V_30 ) ;
F_14 ( V_11 , V_31 ,
V_32 ) ;
F_14 ( V_11 , V_27 ,
1 << ( V_11 -> V_19 . V_29 -
V_28 ) ) ;
break;
default:
return - V_6 ;
}
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_15 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_12 = F_9 ( V_10 ) ;
switch ( V_12 ) {
case V_14 :
switch ( V_11 -> V_19 . V_20 ) {
case V_21 :
case V_22 :
F_16 ( V_11 , V_27 ,
1 << ( V_11 -> V_19 . V_20 -
V_28 ) ) ;
F_16 ( V_11 , V_23 ,
V_24 ) ;
break;
default:
return - V_6 ;
}
break;
case V_17 :
switch ( V_11 -> V_19 . V_29 ) {
case V_21 :
case V_22 :
F_16 ( V_11 , V_27 ,
1 << ( V_11 -> V_19 . V_29 -
V_28 ) ) ;
F_16 ( V_11 , V_23 ,
V_30 ) ;
break;
default:
return - V_6 ;
}
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_17 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_12 = F_9 ( V_10 ) ;
switch ( V_12 ) {
case V_14 :
return F_10 ( V_11 , V_15 ) &
0x8000 ;
case V_17 :
return F_10 ( V_11 , V_18 ) &
0x8000 ;
}
return - V_6 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_12 = F_9 ( V_10 ) ;
int V_33 ;
switch ( V_12 ) {
case V_14 :
V_33 = F_10 ( V_11 , V_25 ) ;
break;
case V_17 :
V_33 = F_10 ( V_11 , V_31 ) ;
break;
default:
return - V_6 ;
}
if ( V_33 & V_34 ) {
switch ( V_33 & V_35 ) {
case 0 :
return 0 ;
case 1 :
return 1950 ;
case 2 :
return 3910 ;
case 3 :
return 7800 ;
}
} else {
switch ( V_33 & V_35 ) {
case 0 :
return 0 ;
case 1 :
return 250000 ;
case 2 :
return 500000 ;
case 3 :
return 1000000 ;
}
}
return - V_6 ;
}
int F_19 ( struct V_11 * V_11 , int V_12 , T_1 V_36 ,
T_1 V_37 , T_1 V_38 , T_1 V_39 , T_1 V_40 ,
T_1 V_41 )
{
switch ( V_12 ) {
case V_14 :
F_11 ( V_11 , V_25 ,
( V_36 ? V_34 : 0 ) |
( V_37 ? V_42 : 0 ) |
V_38 | V_39 | V_40 | V_41 ) ;
break;
case V_17 :
F_11 ( V_11 , V_31 ,
( V_36 ? V_43 : 0 ) |
( V_37 ? V_44 : 0 ) |
V_38 | V_39 | V_40 | V_41 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_20 ( struct V_9 * V_10 , int V_45 ,
int V_46 , unsigned * V_47 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_49 = F_9 ( V_10 ) , V_8 ,
V_50 = V_45 / 1000 , V_51 = V_46 / 1000 ;
T_1 V_7 ;
if ( V_50 < 850 || V_50 > 4025 )
return - V_6 ;
if ( V_51 < 850 || V_51 > 4025 )
return - V_6 ;
V_8 = ( V_50 - 826 ) / 25 ;
if ( F_5 ( V_8 ) > V_51 )
return - V_6 ;
F_21 ( F_5 ( V_8 ) < V_50 ) ;
switch ( V_49 ) {
case V_28 :
V_48 = V_52 ;
break;
case V_53 :
V_48 = V_54 ;
break;
case V_55 :
V_48 = V_56 ;
break;
case V_57 :
V_48 = V_58 ;
break;
case V_21 :
case V_22 :
default:
return - V_6 ;
}
* V_47 = V_8 ;
V_7 = F_10 ( V_11 , V_48 ) & ~ V_59 ;
F_11 ( V_11 , V_48 , V_7 | V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_49 = F_9 ( V_10 ) ;
switch ( V_49 ) {
case V_28 :
V_48 = V_52 ;
break;
case V_53 :
V_48 = V_54 ;
break;
case V_55 :
V_48 = V_56 ;
break;
case V_57 :
V_48 = V_58 ;
break;
case V_21 :
case V_22 :
default:
return - V_6 ;
}
return F_10 ( V_11 , V_48 ) & V_59 ;
}
static int F_23 ( struct V_9 * V_10 ,
unsigned V_47 )
{
if ( V_47 > V_60 )
return - V_6 ;
return F_5 ( V_47 ) * 1000 ;
}
static int F_24 ( struct V_9 * V_10 , int V_61 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_8 = V_61 / 1000 , V_49 = F_9 ( V_10 ) ;
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_1 , V_63 , V_49 , V_8 ) ;
if ( V_8 && ( V_8 < 850 || V_8 > 4025 ) ) {
F_26 ( V_11 -> V_62 ,
L_2 ,
V_49 , V_8 ) ;
return - V_6 ;
}
if ( V_8 == 0 )
V_8 = 850 ;
switch ( V_49 ) {
case V_28 :
V_48 = V_64 ;
break;
case V_53 :
V_48 = V_65 ;
break;
case V_55 :
V_48 = V_66 ;
break;
case V_57 :
V_48 = V_67 ;
break;
case V_21 :
case V_22 :
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_48 ) & ~ V_59 ;
F_11 ( V_11 , V_48 ,
V_7 | F_6 ( V_8 ) ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_49 ) {
case V_28 :
V_7 = F_10 ( V_11 , V_64 )
& ~ V_68 ;
F_11 ( V_11 , V_64 ,
V_11 -> V_19 . V_69 ) ;
break;
case V_53 :
V_7 = F_10 ( V_11 , V_65 )
& ~ V_68 ;
F_11 ( V_11 , V_65 ,
V_11 -> V_19 . V_70 ) ;
break;
case V_55 :
V_7 = F_10 ( V_11 , V_66 )
& ~ V_68 ;
F_11 ( V_11 , V_66 ,
V_11 -> V_19 . V_71 ) ;
break;
case V_57 :
V_7 = F_10 ( V_11 , V_67 )
& ~ V_68 ;
F_11 ( V_11 , V_67 ,
V_11 -> V_19 . V_72 ) ;
break;
case V_21 :
case V_22 :
default:
return - V_6 ;
}
return 0 ;
}
static int F_28 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_49 ) {
case V_28 :
V_7 = F_10 ( V_11 , V_64 ) ;
V_11 -> V_19 . V_69 = V_7 & V_68 ;
F_11 ( V_11 , V_64 ,
V_73 ) ;
break;
case V_53 :
V_7 = F_10 ( V_11 , V_65 ) ;
V_11 -> V_19 . V_70 = V_7 & V_68 ;
F_11 ( V_11 , V_65 ,
V_73 ) ;
break;
case V_55 :
V_7 = F_10 ( V_11 , V_66 ) ;
V_11 -> V_19 . V_71 = V_7 & V_68 ;
F_11 ( V_11 , V_66 ,
V_73 ) ;
break;
case V_57 :
V_7 = F_10 ( V_11 , V_67 ) ;
V_11 -> V_19 . V_72 = V_7 & V_68 ;
F_11 ( V_11 , V_67 ,
V_73 ) ;
break;
case V_21 :
case V_22 :
default:
return - V_6 ;
}
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_49 ) {
case V_21 :
V_7 = F_10 ( V_11 , V_74 )
& ~ V_75 ;
F_11 ( V_11 , V_74 , V_7 |
V_76 ) ;
break;
case V_22 :
V_7 = F_10 ( V_11 , V_77 )
& ~ V_75 ;
F_11 ( V_11 , V_77 , V_7 |
V_78 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_49 ) {
case V_21 :
V_7 = F_10 ( V_11 , V_74 )
& ~ V_75 ;
F_11 ( V_11 , V_74 , V_7 |
V_79 ) ;
break;
case V_22 :
V_7 = F_10 ( V_11 , V_77 )
& ~ V_75 ;
F_11 ( V_11 , V_77 , V_7 |
V_79 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_31 ( struct V_9 * V_10 ,
unsigned int V_36 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 * V_80 ;
switch ( V_49 ) {
case V_28 :
V_80 = & V_11 -> V_19 . V_69 ;
break;
case V_53 :
V_80 = & V_11 -> V_19 . V_70 ;
break;
case V_55 :
V_80 = & V_11 -> V_19 . V_71 ;
break;
case V_57 :
V_80 = & V_11 -> V_19 . V_72 ;
break;
case V_21 :
case V_22 :
default:
return - V_6 ;
}
switch ( V_36 ) {
case V_81 :
* V_80 = V_82 ;
break;
case V_83 :
* V_80 = V_84 ;
break;
case V_85 :
* V_80 = V_86 ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_32 ( struct V_9 * V_10 , int V_61 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_8 = V_61 / 1000 , V_87 = F_9 ( V_10 ) ;
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_1 , V_63 , V_87 , V_8 ) ;
if ( V_8 < 900 || V_8 > 3300 ) {
F_26 ( V_11 -> V_62 , L_3 ,
V_87 , V_8 ) ;
return - V_6 ;
}
switch ( V_87 ) {
case V_88 :
V_48 = V_89 ;
break;
case V_90 :
V_48 = V_91 ;
break;
case V_92 :
V_48 = V_93 ;
break;
case V_94 :
V_48 = V_95 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_48 ) & ~ V_96 ;
F_11 ( V_11 , V_48 ,
V_7 | F_4 ( V_8 ) ) ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_87 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_87 ) {
case V_88 :
V_48 = V_89 ;
break;
case V_90 :
V_48 = V_91 ;
break;
case V_92 :
V_48 = V_93 ;
break;
case V_94 :
V_48 = V_95 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_48 ) & ~ V_97 ;
F_11 ( V_11 , V_48 , V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_87 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_87 ) {
case V_88 :
V_48 = V_89 ;
break;
case V_90 :
V_48 = V_91 ;
break;
case V_92 :
V_48 = V_93 ;
break;
case V_94 :
V_48 = V_95 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_48 ) & ~ V_97 ;
F_11 ( V_11 , V_48 , V_98 ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 , int V_45 ,
int V_46 , unsigned * V_47 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_87 = F_9 ( V_10 ) , V_8 , V_50 = V_45 / 1000 ,
V_51 = V_46 / 1000 ;
T_1 V_7 ;
if ( V_50 < 900 || V_50 > 3300 )
return - V_6 ;
if ( V_51 < 900 || V_51 > 3300 )
return - V_6 ;
if ( V_50 < 1800 ) {
V_8 = ( V_50 - 851 ) / 50 ;
if ( F_3 ( V_8 ) > V_51 )
return - V_6 ;
F_21 ( F_3 ( V_8 ) < V_50 ) ;
} else {
V_8 = ( ( V_50 - 1701 ) / 100 ) + 16 ;
if ( F_3 ( V_8 ) > V_51 )
return - V_6 ;
F_21 ( F_3 ( V_8 ) < V_50 ) ;
}
switch ( V_87 ) {
case V_88 :
V_48 = V_99 ;
break;
case V_90 :
V_48 = V_100 ;
break;
case V_92 :
V_48 = V_101 ;
break;
case V_94 :
V_48 = V_102 ;
break;
default:
return - V_6 ;
}
* V_47 = V_8 ;
V_7 = F_10 ( V_11 , V_48 ) & ~ V_96 ;
F_11 ( V_11 , V_48 , V_7 | V_8 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_87 = F_9 ( V_10 ) ;
switch ( V_87 ) {
case V_88 :
V_48 = V_99 ;
break;
case V_90 :
V_48 = V_100 ;
break;
case V_92 :
V_48 = V_101 ;
break;
case V_94 :
V_48 = V_102 ;
break;
default:
return - V_6 ;
}
return F_10 ( V_11 , V_48 ) & V_96 ;
}
static int F_37 ( struct V_9 * V_10 ,
unsigned V_47 )
{
if ( V_47 > V_96 )
return - V_6 ;
return F_3 ( V_47 ) * 1000 ;
}
int F_38 ( struct V_11 * V_11 , int V_49 , T_1 V_103 ,
T_1 V_104 , T_1 V_105 )
{
int V_106 ;
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_4 ,
V_63 , V_49 , V_103 , V_104 ) ;
if ( V_103 > 15 || V_104 > 15 )
return - V_6 ;
switch ( V_49 ) {
case V_28 :
V_106 = V_107 ;
break;
case V_21 :
V_106 = V_108 ;
break;
case V_53 :
V_106 = V_109 ;
break;
case V_55 :
V_106 = V_110 ;
break;
case V_22 :
V_106 = V_111 ;
break;
case V_57 :
V_106 = V_112 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_106 ) &
~ ( V_113 | V_114 |
V_115 ) ;
F_11 ( V_11 , V_106 ,
V_7 | ( V_103 << V_116 ) |
( V_104 << V_117 ) |
( V_105 << V_118 ) ) ;
return 0 ;
}
int F_39 ( struct V_11 * V_11 , int V_87 , T_1 V_103 , T_1 V_104 )
{
int V_106 ;
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_4 ,
V_63 , V_87 , V_103 , V_104 ) ;
if ( V_103 > 15 || V_104 > 15 )
return - V_6 ;
switch ( V_87 ) {
case V_88 :
V_106 = V_119 ;
break;
case V_90 :
V_106 = V_120 ;
break;
case V_92 :
V_106 = V_121 ;
break;
case V_94 :
V_106 = V_122 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_106 ) & ~ V_123 ;
F_11 ( V_11 , V_106 , V_7 | ( ( V_103 << 10 ) | ( V_104 << 6 ) ) ) ;
return 0 ;
}
int F_40 ( struct V_11 * V_11 , int V_49 , T_1 V_36 ,
T_1 V_124 , T_1 V_125 , T_1 V_126 )
{
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_5 , V_63 , V_49 ,
V_36 ? L_6 : L_7 , V_124 ? L_8 : L_6 ) ;
switch ( V_49 ) {
case V_21 :
V_7 = F_10 ( V_11 , V_74 )
& ~ ( V_127 | V_128 |
V_129 | V_130 ) ;
F_11 ( V_11 , V_74 , V_7 |
( V_36 << V_131 ) |
( V_124 << V_132 ) |
( V_125 << V_133 ) |
( V_126 << V_134 ) ) ;
break;
case V_22 :
V_7 = F_10 ( V_11 , V_77 )
& ~ ( V_135 | V_136 |
V_137 | V_138 ) ;
F_11 ( V_11 , V_77 , V_7 |
( V_36 << V_139 ) |
( V_124 << V_140 ) |
( V_125 << V_141 ) |
( V_126 << V_142 ) ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_143 ;
if ( V_49 < V_28 || V_49 > V_57 )
return - V_6 ;
V_143 = V_49 - V_28 ;
F_14 ( V_11 , V_27 , 1 << V_143 ) ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_143 ;
if ( V_49 < V_28 || V_49 > V_57 )
return - V_6 ;
V_143 = V_49 - V_28 ;
F_16 ( V_11 , V_27 , 1 << V_143 ) ;
return 0 ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_87 = F_9 ( V_10 ) ;
T_1 V_143 ;
if ( V_87 < V_88 || V_87 > V_94 )
return - V_6 ;
V_143 = ( V_87 - V_88 ) + 8 ;
F_14 ( V_11 , V_27 , 1 << V_143 ) ;
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_87 = F_9 ( V_10 ) ;
T_1 V_143 ;
if ( V_87 < V_88 || V_87 > V_94 )
return - V_6 ;
V_143 = ( V_87 - V_88 ) + 8 ;
F_16 ( V_11 , V_27 , 1 << V_143 ) ;
return 0 ;
}
static int F_45 ( struct V_11 * V_11 , int V_49 , int V_144 )
{
int V_33 = 0 , V_13 ;
switch ( V_49 ) {
case V_28 :
V_33 = V_145 ;
break;
case V_53 :
V_33 = V_146 ;
break;
case V_55 :
V_33 = V_147 ;
break;
case V_57 :
V_33 = V_148 ;
break;
default:
return - V_6 ;
}
if ( V_144 )
V_13 = F_14 ( V_11 , V_33 ,
V_149 ) ;
else
V_13 = F_16 ( V_11 , V_33 ,
V_149 ) ;
return V_13 ;
}
static int F_46 ( struct V_9 * V_10 , unsigned int V_36 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_7 ;
if ( V_49 < V_28 || V_49 > V_57 )
return - V_6 ;
if ( V_49 == V_21 || V_49 == V_22 )
return - V_6 ;
V_7 = 1 << ( V_49 - V_28 ) ;
switch ( V_36 ) {
case V_150 :
F_14 ( V_11 , V_151 , V_7 ) ;
F_16 ( V_11 , V_152 , V_7 ) ;
F_45 ( V_11 , V_49 , 1 ) ;
break;
case V_81 :
F_14 ( V_11 , V_151 , V_7 ) ;
F_16 ( V_11 , V_152 , V_7 ) ;
F_45 ( V_11 , V_49 , 0 ) ;
break;
case V_83 :
F_45 ( V_11 , V_49 , 0 ) ;
F_16 ( V_11 , V_152 , V_7 ) ;
F_16 ( V_11 , V_151 , V_7 ) ;
break;
case V_85 :
F_45 ( V_11 , V_49 , 0 ) ;
F_14 ( V_11 , V_152 , V_7 ) ;
break;
}
return 0 ;
}
static unsigned int F_47 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_153 , V_154 , V_155 , V_156 ;
int V_36 = V_81 ;
int V_33 ;
switch ( V_49 ) {
case V_28 :
V_33 = V_145 ;
break;
case V_53 :
V_33 = V_146 ;
break;
case V_55 :
V_33 = V_147 ;
break;
case V_57 :
V_33 = V_148 ;
break;
default:
return - V_6 ;
}
V_153 = 1 << ( V_49 - V_28 ) ;
V_155 = F_10 ( V_11 , V_151 ) & V_153 ;
V_156 = F_10 ( V_11 , V_33 ) & V_149 ;
V_154 = F_10 ( V_11 , V_152 ) & V_153 ;
F_25 ( V_11 -> V_62 , L_9 ,
V_153 , V_155 , V_154 , V_156 ) ;
if ( V_155 && ! V_154 ) {
if ( V_156 )
V_36 = V_150 ;
else
V_36 = V_81 ;
} else if ( ! V_155 && ! V_154 )
V_36 = V_83 ;
else if ( V_154 )
V_36 = V_85 ;
return V_36 ;
}
static unsigned int F_48 ( struct V_9 * V_10 )
{
return V_81 ;
}
static unsigned int F_49 ( int V_157 , const struct V_158 * V_159 )
{
int V_4 = 0 ;
while ( V_159 [ V_4 ] . V_160 != - 1 ) {
if ( V_157 >= V_159 [ V_4 ] . V_160 && V_157 <= V_159 [ V_4 ] . V_161 )
return V_159 [ V_4 ] . V_36 ;
}
return V_81 ;
}
static unsigned int F_50 ( struct V_9 * V_10 ,
int V_162 , int V_163 ,
int V_164 )
{
int V_49 = F_9 ( V_10 ) , V_36 ;
switch ( V_49 ) {
case V_28 :
case V_57 :
V_36 = F_49 ( V_164 , V_165 ) ;
break;
case V_53 :
case V_55 :
V_36 = F_49 ( V_164 , V_166 ) ;
break;
default:
V_36 = V_81 ;
break;
}
return V_36 ;
}
static int F_51 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) , V_143 ;
if ( V_49 < V_28 || V_49 > V_57 )
return - V_6 ;
V_143 = V_49 - V_28 ;
return F_10 ( V_11 , V_27 )
& ( 1 << V_143 ) ;
}
static int F_52 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_87 = F_9 ( V_10 ) , V_143 ;
if ( V_87 < V_88 || V_87 > V_94 )
return - V_6 ;
V_143 = ( V_87 - V_88 ) + 8 ;
return F_10 ( V_11 , V_27 )
& ( 1 << V_143 ) ;
}
static T_2 F_53 ( int V_167 , void * V_168 )
{
struct V_9 * V_10 = (struct V_9 * ) V_168 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
F_54 ( & V_10 -> V_169 ) ;
if ( V_167 == V_170 || V_167 == V_171 )
F_55 ( V_10 ,
V_172 ,
V_11 ) ;
else
F_55 ( V_10 ,
V_173 ,
V_11 ) ;
F_56 ( & V_10 -> V_169 ) ;
return V_174 ;
}
static int F_57 ( struct V_175 * V_176 )
{
struct V_11 * V_11 = F_58 ( & V_176 -> V_62 ) ;
struct V_9 * V_10 ;
int V_13 ;
T_1 V_7 ;
if ( V_176 -> V_177 < V_28 || V_176 -> V_177 > V_17 )
return - V_178 ;
switch ( V_176 -> V_177 ) {
case V_28 :
V_7 = F_10 ( V_11 , V_64 ) ;
V_11 -> V_19 . V_69 = V_7 & V_68 ;
break;
case V_53 :
V_7 = F_10 ( V_11 , V_65 ) ;
V_11 -> V_19 . V_70 = V_7 & V_68 ;
break;
case V_55 :
V_7 = F_10 ( V_11 , V_66 ) ;
V_11 -> V_19 . V_71 = V_7 & V_68 ;
break;
case V_57 :
V_7 = F_10 ( V_11 , V_67 ) ;
V_11 -> V_19 . V_72 = V_7 & V_68 ;
break;
}
V_10 = F_59 ( & V_179 [ V_176 -> V_177 ] , & V_176 -> V_62 ,
V_176 -> V_62 . V_180 ,
F_58 ( & V_176 -> V_62 ) ) ;
if ( F_60 ( V_10 ) ) {
F_26 ( & V_176 -> V_62 , L_10 ,
V_179 [ V_176 -> V_177 ] . V_181 ) ;
return F_61 ( V_10 ) ;
}
V_13 = F_62 ( V_11 , V_179 [ V_176 -> V_177 ] . V_167 ,
F_53 , 0 , L_11 , V_10 ) ;
if ( V_13 < 0 ) {
F_63 ( V_10 ) ;
F_26 ( & V_176 -> V_62 , L_12 ,
V_179 [ V_176 -> V_177 ] . V_181 ) ;
return V_13 ;
}
return 0 ;
}
static int F_64 ( struct V_175 * V_176 )
{
struct V_9 * V_10 = F_65 ( V_176 ) ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
F_66 ( V_11 , V_179 [ V_176 -> V_177 ] . V_167 , V_10 ) ;
F_63 ( V_10 ) ;
return 0 ;
}
int F_67 ( struct V_11 * V_11 , int V_33 ,
struct V_182 * V_183 )
{
struct V_175 * V_176 ;
int V_13 ;
if ( V_33 < 0 || V_33 >= V_184 )
return - V_6 ;
if ( V_11 -> V_19 . V_176 [ V_33 ] )
return - V_185 ;
if ( V_33 >= V_28 && V_33 <= V_57 &&
V_33 > V_11 -> V_19 . V_186 )
return - V_178 ;
if ( V_33 >= V_14 && V_33 <= V_17 &&
V_33 > V_11 -> V_19 . V_187 )
return - V_178 ;
V_176 = F_68 ( L_13 , V_33 ) ;
if ( ! V_176 )
return - V_188 ;
V_11 -> V_19 . V_176 [ V_33 ] = V_176 ;
V_183 -> V_189 = V_11 ;
V_176 -> V_62 . V_180 = V_183 ;
V_176 -> V_62 . V_190 = V_11 -> V_62 ;
F_69 ( V_176 , V_11 ) ;
V_13 = F_70 ( V_176 ) ;
if ( V_13 != 0 ) {
F_26 ( V_11 -> V_62 , L_14 ,
V_33 , V_13 ) ;
F_71 ( V_176 ) ;
V_11 -> V_19 . V_176 [ V_33 ] = NULL ;
}
return V_13 ;
}
int F_72 ( struct V_11 * V_11 , int V_191 , int V_49 , int V_12 ,
struct V_192 * V_193 )
{
struct V_194 * V_195 ;
struct V_175 * V_176 ;
int V_13 ;
if ( V_191 >= F_2 ( V_11 -> V_19 . V_195 ) || V_191 < 0 ) {
F_26 ( V_11 -> V_62 , L_15 , V_191 ) ;
return - V_178 ;
}
V_195 = & V_11 -> V_19 . V_195 [ V_191 ] ;
if ( V_195 -> V_176 ) {
F_26 ( V_11 -> V_62 , L_16 , V_191 ) ;
return - V_6 ;
}
V_176 = F_68 ( L_17 , V_191 ) ;
if ( V_176 == NULL ) {
F_26 ( V_11 -> V_62 , L_18 , V_191 ) ;
return - V_188 ;
}
V_195 -> V_196 . V_62 = & V_176 -> V_62 ;
V_195 -> V_196 . V_197 = L_19 ;
V_195 -> V_198 . V_199 = 1 ;
V_195 -> V_198 . V_200 = & V_195 -> V_196 ;
V_195 -> V_198 . V_201 . V_1 = 0 ;
V_195 -> V_198 . V_201 . V_2 = V_193 -> V_2 ;
V_195 -> V_198 . V_201 . V_202
= V_203 | V_204 ;
V_195 -> V_198 . V_201 . V_205 = V_81 ;
V_13 = F_67 ( V_11 , V_12 , & V_195 -> V_198 ) ;
if ( V_13 != 0 ) {
F_71 ( V_176 ) ;
return V_13 ;
}
V_195 -> V_206 . V_62 = & V_176 -> V_62 ;
V_195 -> V_206 . V_197 = L_20 ;
V_195 -> V_207 . V_199 = 1 ;
V_195 -> V_207 . V_200 = & V_195 -> V_206 ;
V_195 -> V_207 . V_201 . V_205 = V_81 ;
V_195 -> V_207 . V_201 . V_202 = V_204 ;
V_13 = F_67 ( V_11 , V_49 , & V_195 -> V_207 ) ;
if ( V_13 != 0 ) {
F_71 ( V_176 ) ;
return V_13 ;
}
switch ( V_12 ) {
case V_14 :
V_11 -> V_19 . V_20 = V_49 ;
break;
case V_17 :
V_11 -> V_19 . V_29 = V_49 ;
break;
}
V_176 -> V_62 . V_180 = V_193 ;
V_176 -> V_62 . V_190 = V_11 -> V_62 ;
V_13 = F_70 ( V_176 ) ;
if ( V_13 != 0 ) {
F_26 ( V_11 -> V_62 , L_21 ,
V_191 , V_13 ) ;
F_71 ( V_176 ) ;
return V_13 ;
}
V_195 -> V_176 = V_176 ;
return 0 ;
}
static int T_3 F_73 ( void )
{
return F_74 ( & V_208 ) ;
}
static void T_4 F_75 ( void )
{
F_76 ( & V_208 ) ;
}
