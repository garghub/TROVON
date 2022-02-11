static int F_1 ( int V_1 , int V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
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
return V_5 [ V_7 ] ;
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
V_7 | V_11 -> V_19 . V_69 ) ;
break;
case V_53 :
V_7 = F_10 ( V_11 , V_65 )
& ~ V_68 ;
F_11 ( V_11 , V_65 ,
V_7 | V_11 -> V_19 . V_70 ) ;
break;
case V_55 :
V_7 = F_10 ( V_11 , V_66 )
& ~ V_68 ;
F_11 ( V_11 , V_66 ,
V_7 | V_11 -> V_19 . V_71 ) ;
break;
case V_57 :
V_7 = F_10 ( V_11 , V_67 )
& ~ V_68 ;
F_11 ( V_11 , V_67 ,
V_7 | V_11 -> V_19 . V_72 ) ;
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
V_7 | V_73 ) ;
break;
case V_53 :
V_7 = F_10 ( V_11 , V_65 ) ;
V_11 -> V_19 . V_70 = V_7 & V_68 ;
F_11 ( V_11 , V_65 ,
V_7 | V_73 ) ;
break;
case V_55 :
V_7 = F_10 ( V_11 , V_66 ) ;
V_11 -> V_19 . V_71 = V_7 & V_68 ;
F_11 ( V_11 , V_66 ,
V_7 | V_73 ) ;
break;
case V_57 :
V_7 = F_10 ( V_11 , V_67 ) ;
V_11 -> V_19 . V_72 = V_7 & V_68 ;
F_11 ( V_11 , V_67 ,
V_7 | V_73 ) ;
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
( V_76 << V_77 ) ) ;
break;
case V_22 :
V_7 = F_10 ( V_11 , V_78 )
& ~ V_79 ;
F_11 ( V_11 , V_78 , V_7 |
( V_80 << V_81 ) ) ;
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
( V_82 << V_77 ) ) ;
break;
case V_22 :
V_7 = F_10 ( V_11 , V_78 )
& ~ V_79 ;
F_11 ( V_11 , V_78 , V_7 |
( V_83 << V_81 ) ) ;
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
T_1 * V_84 ;
switch ( V_49 ) {
case V_28 :
V_84 = & V_11 -> V_19 . V_69 ;
break;
case V_53 :
V_84 = & V_11 -> V_19 . V_70 ;
break;
case V_55 :
V_84 = & V_11 -> V_19 . V_71 ;
break;
case V_57 :
V_84 = & V_11 -> V_19 . V_72 ;
break;
case V_21 :
case V_22 :
default:
return - V_6 ;
}
switch ( V_36 ) {
case V_85 :
* V_84 = V_86 ;
break;
case V_87 :
* V_84 = V_88 ;
break;
case V_89 :
* V_84 = V_90 ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_32 ( struct V_9 * V_10 , int V_61 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_8 = V_61 / 1000 , V_91 = F_9 ( V_10 ) ;
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_1 , V_63 , V_91 , V_8 ) ;
if ( V_8 < 900 || V_8 > 3300 ) {
F_26 ( V_11 -> V_62 , L_3 ,
V_91 , V_8 ) ;
return - V_6 ;
}
switch ( V_91 ) {
case V_92 :
V_48 = V_93 ;
break;
case V_94 :
V_48 = V_95 ;
break;
case V_96 :
V_48 = V_97 ;
break;
case V_98 :
V_48 = V_99 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_48 ) & ~ V_100 ;
F_11 ( V_11 , V_48 ,
V_7 | F_4 ( V_8 ) ) ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_91 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_91 ) {
case V_92 :
V_48 = V_93 ;
break;
case V_94 :
V_48 = V_95 ;
break;
case V_96 :
V_48 = V_97 ;
break;
case V_98 :
V_48 = V_99 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_48 ) & ~ V_101 ;
F_11 ( V_11 , V_48 , V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_91 = F_9 ( V_10 ) ;
T_1 V_7 ;
switch ( V_91 ) {
case V_92 :
V_48 = V_93 ;
break;
case V_94 :
V_48 = V_95 ;
break;
case V_96 :
V_48 = V_97 ;
break;
case V_98 :
V_48 = V_99 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_48 ) & ~ V_101 ;
F_11 ( V_11 , V_48 , V_7 | V_102 ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 , int V_45 ,
int V_46 , unsigned * V_47 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_91 = F_9 ( V_10 ) , V_8 , V_50 = V_45 / 1000 ,
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
switch ( V_91 ) {
case V_92 :
V_48 = V_103 ;
break;
case V_94 :
V_48 = V_104 ;
break;
case V_96 :
V_48 = V_105 ;
break;
case V_98 :
V_48 = V_106 ;
break;
default:
return - V_6 ;
}
* V_47 = V_8 ;
V_7 = F_10 ( V_11 , V_48 ) & ~ V_100 ;
F_11 ( V_11 , V_48 , V_7 | V_8 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_48 , V_91 = F_9 ( V_10 ) ;
switch ( V_91 ) {
case V_92 :
V_48 = V_103 ;
break;
case V_94 :
V_48 = V_104 ;
break;
case V_96 :
V_48 = V_105 ;
break;
case V_98 :
V_48 = V_106 ;
break;
default:
return - V_6 ;
}
return F_10 ( V_11 , V_48 ) & V_100 ;
}
static int F_37 ( struct V_9 * V_10 ,
unsigned V_47 )
{
if ( V_47 > V_100 )
return - V_6 ;
return F_3 ( V_47 ) * 1000 ;
}
int F_38 ( struct V_11 * V_11 , int V_49 , T_1 V_107 ,
T_1 V_108 , T_1 V_109 )
{
int V_110 ;
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_4 ,
V_63 , V_49 , V_107 , V_108 ) ;
if ( V_107 > 15 || V_108 > 15 )
return - V_6 ;
switch ( V_49 ) {
case V_28 :
V_110 = V_111 ;
break;
case V_21 :
V_110 = V_112 ;
break;
case V_53 :
V_110 = V_113 ;
break;
case V_55 :
V_110 = V_114 ;
break;
case V_22 :
V_110 = V_115 ;
break;
case V_57 :
V_110 = V_116 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_110 ) &
~ ( V_117 | V_118 |
V_119 ) ;
F_11 ( V_11 , V_110 ,
V_7 | ( V_107 << V_120 ) |
( V_108 << V_121 ) |
( V_109 << V_122 ) ) ;
return 0 ;
}
int F_39 ( struct V_11 * V_11 , int V_91 , T_1 V_107 , T_1 V_108 )
{
int V_110 ;
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_4 ,
V_63 , V_91 , V_107 , V_108 ) ;
if ( V_107 > 15 || V_108 > 15 )
return - V_6 ;
switch ( V_91 ) {
case V_92 :
V_110 = V_123 ;
break;
case V_94 :
V_110 = V_124 ;
break;
case V_96 :
V_110 = V_125 ;
break;
case V_98 :
V_110 = V_126 ;
break;
default:
return - V_6 ;
}
V_7 = F_10 ( V_11 , V_110 ) & ~ V_127 ;
F_11 ( V_11 , V_110 , V_7 | ( ( V_107 << 10 ) | ( V_108 << 6 ) ) ) ;
return 0 ;
}
int F_40 ( struct V_11 * V_11 , int V_49 , T_1 V_36 ,
T_1 V_128 , T_1 V_129 , T_1 V_130 )
{
T_1 V_7 ;
F_25 ( V_11 -> V_62 , L_5 , V_63 , V_49 ,
V_36 ? L_6 : L_7 , V_128 ? L_8 : L_6 ) ;
switch ( V_49 ) {
case V_21 :
V_7 = F_10 ( V_11 , V_74 )
& ~ ( V_131 | V_132 |
V_133 | V_134 ) ;
F_11 ( V_11 , V_74 , V_7 |
( V_36 << V_135 ) |
( V_128 << V_136 ) |
( V_129 << V_137 ) |
( V_130 << V_138 ) ) ;
break;
case V_22 :
V_7 = F_10 ( V_11 , V_78 )
& ~ ( V_139 | V_140 |
V_141 | V_142 ) ;
F_11 ( V_11 , V_78 , V_7 |
( V_36 << V_143 ) |
( V_128 << V_144 ) |
( V_129 << V_145 ) |
( V_130 << V_146 ) ) ;
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
T_1 V_147 ;
if ( V_49 < V_28 || V_49 > V_57 )
return - V_6 ;
V_147 = V_49 - V_28 ;
F_14 ( V_11 , V_27 , 1 << V_147 ) ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_147 ;
if ( V_49 < V_28 || V_49 > V_57 )
return - V_6 ;
V_147 = V_49 - V_28 ;
F_16 ( V_11 , V_27 , 1 << V_147 ) ;
return 0 ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_91 = F_9 ( V_10 ) ;
T_1 V_147 ;
if ( V_91 < V_92 || V_91 > V_98 )
return - V_6 ;
V_147 = ( V_91 - V_92 ) + 8 ;
F_14 ( V_11 , V_27 , 1 << V_147 ) ;
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_91 = F_9 ( V_10 ) ;
T_1 V_147 ;
if ( V_91 < V_92 || V_91 > V_98 )
return - V_6 ;
V_147 = ( V_91 - V_92 ) + 8 ;
F_16 ( V_11 , V_27 , 1 << V_147 ) ;
return 0 ;
}
static int F_45 ( struct V_11 * V_11 , int V_49 , int V_148 )
{
int V_33 = 0 , V_13 ;
switch ( V_49 ) {
case V_28 :
V_33 = V_149 ;
break;
case V_53 :
V_33 = V_150 ;
break;
case V_55 :
V_33 = V_151 ;
break;
case V_57 :
V_33 = V_152 ;
break;
default:
return - V_6 ;
}
if ( V_148 )
V_13 = F_14 ( V_11 , V_33 ,
V_153 ) ;
else
V_13 = F_16 ( V_11 , V_33 ,
V_153 ) ;
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
case V_154 :
F_14 ( V_11 , V_155 , V_7 ) ;
F_16 ( V_11 , V_156 , V_7 ) ;
F_45 ( V_11 , V_49 , 1 ) ;
break;
case V_85 :
F_14 ( V_11 , V_155 , V_7 ) ;
F_16 ( V_11 , V_156 , V_7 ) ;
F_45 ( V_11 , V_49 , 0 ) ;
break;
case V_87 :
F_45 ( V_11 , V_49 , 0 ) ;
F_16 ( V_11 , V_156 , V_7 ) ;
F_16 ( V_11 , V_155 , V_7 ) ;
break;
case V_89 :
F_45 ( V_11 , V_49 , 0 ) ;
F_14 ( V_11 , V_156 , V_7 ) ;
break;
}
return 0 ;
}
static unsigned int F_47 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) ;
T_1 V_157 , V_158 , V_159 , V_160 ;
int V_36 = V_85 ;
int V_33 ;
switch ( V_49 ) {
case V_28 :
V_33 = V_149 ;
break;
case V_53 :
V_33 = V_150 ;
break;
case V_55 :
V_33 = V_151 ;
break;
case V_57 :
V_33 = V_152 ;
break;
default:
return - V_6 ;
}
V_157 = 1 << ( V_49 - V_28 ) ;
V_159 = F_10 ( V_11 , V_155 ) & V_157 ;
V_160 = F_10 ( V_11 , V_33 ) & V_153 ;
V_158 = F_10 ( V_11 , V_156 ) & V_157 ;
F_25 ( V_11 -> V_62 , L_9 ,
V_157 , V_159 , V_158 , V_160 ) ;
if ( V_159 && ! V_158 ) {
if ( V_160 )
V_36 = V_154 ;
else
V_36 = V_85 ;
} else if ( ! V_159 && ! V_158 )
V_36 = V_87 ;
else if ( V_158 )
V_36 = V_89 ;
return V_36 ;
}
static unsigned int F_48 ( struct V_9 * V_10 )
{
return V_85 ;
}
static unsigned int F_49 ( int V_161 , const struct V_162 * V_163 )
{
int V_4 = 0 ;
while ( V_163 [ V_4 ] . V_164 != - 1 ) {
if ( V_161 >= V_163 [ V_4 ] . V_164 && V_161 <= V_163 [ V_4 ] . V_165 )
return V_163 [ V_4 ] . V_36 ;
}
return V_85 ;
}
static unsigned int F_50 ( struct V_9 * V_10 ,
int V_166 , int V_167 ,
int V_168 )
{
int V_49 = F_9 ( V_10 ) , V_36 ;
switch ( V_49 ) {
case V_28 :
case V_57 :
V_36 = F_49 ( V_168 , V_169 ) ;
break;
case V_53 :
case V_55 :
V_36 = F_49 ( V_168 , V_170 ) ;
break;
default:
V_36 = V_85 ;
break;
}
return V_36 ;
}
static int F_51 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_49 = F_9 ( V_10 ) , V_147 ;
if ( V_49 < V_28 || V_49 > V_57 )
return - V_6 ;
V_147 = V_49 - V_28 ;
return F_10 ( V_11 , V_27 )
& ( 1 << V_147 ) ;
}
static int F_52 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 ) ;
int V_91 = F_9 ( V_10 ) , V_147 ;
if ( V_91 < V_92 || V_91 > V_98 )
return - V_6 ;
V_147 = ( V_91 - V_92 ) + 8 ;
return F_10 ( V_11 , V_27 )
& ( 1 << V_147 ) ;
}
static T_2 F_53 ( int V_171 , void * V_172 )
{
struct V_9 * V_10 = (struct V_9 * ) V_172 ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
F_54 ( & V_10 -> V_173 ) ;
if ( V_171 == V_174 || V_171 == V_175 )
F_55 ( V_10 ,
V_176 ,
V_11 ) ;
else
F_55 ( V_10 ,
V_177 ,
V_11 ) ;
F_56 ( & V_10 -> V_173 ) ;
return V_178 ;
}
static int F_57 ( struct V_179 * V_180 )
{
struct V_11 * V_11 = F_58 ( & V_180 -> V_62 ) ;
struct V_181 V_182 = { } ;
struct V_9 * V_10 ;
int V_13 ;
T_1 V_7 ;
if ( V_180 -> V_183 < V_28 || V_180 -> V_183 > V_17 )
return - V_184 ;
switch ( V_180 -> V_183 ) {
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
V_182 . V_62 = & V_180 -> V_62 ;
V_182 . V_185 = V_180 -> V_62 . V_186 ;
V_182 . V_187 = F_58 ( & V_180 -> V_62 ) ;
V_10 = F_59 ( & V_188 [ V_180 -> V_183 ] , & V_182 ) ;
if ( F_60 ( V_10 ) ) {
F_26 ( & V_180 -> V_62 , L_10 ,
V_188 [ V_180 -> V_183 ] . V_189 ) ;
return F_61 ( V_10 ) ;
}
V_13 = F_62 ( V_11 , V_188 [ V_180 -> V_183 ] . V_171 ,
F_53 , 0 , L_11 , V_10 ) ;
if ( V_13 < 0 ) {
F_63 ( V_10 ) ;
F_26 ( & V_180 -> V_62 , L_12 ,
V_188 [ V_180 -> V_183 ] . V_189 ) ;
return V_13 ;
}
return 0 ;
}
static int F_64 ( struct V_179 * V_180 )
{
struct V_9 * V_10 = F_65 ( V_180 ) ;
struct V_11 * V_11 = F_8 ( V_10 ) ;
F_66 ( V_11 , V_188 [ V_180 -> V_183 ] . V_171 , V_10 ) ;
F_63 ( V_10 ) ;
return 0 ;
}
int F_67 ( struct V_11 * V_11 , int V_33 ,
struct V_190 * V_191 )
{
struct V_179 * V_180 ;
int V_13 ;
if ( V_33 < 0 || V_33 >= V_192 )
return - V_6 ;
if ( V_11 -> V_19 . V_180 [ V_33 ] )
return - V_193 ;
if ( V_33 >= V_28 && V_33 <= V_57 &&
V_33 > V_11 -> V_19 . V_194 )
return - V_184 ;
if ( V_33 >= V_14 && V_33 <= V_17 &&
V_33 > V_11 -> V_19 . V_195 )
return - V_184 ;
V_180 = F_68 ( L_13 , V_33 ) ;
if ( ! V_180 )
return - V_196 ;
V_11 -> V_19 . V_180 [ V_33 ] = V_180 ;
V_191 -> V_187 = V_11 ;
V_180 -> V_62 . V_186 = V_191 ;
V_180 -> V_62 . V_197 = V_11 -> V_62 ;
F_69 ( V_180 , V_11 ) ;
V_13 = F_70 ( V_180 ) ;
if ( V_13 != 0 ) {
F_26 ( V_11 -> V_62 , L_14 ,
V_33 , V_13 ) ;
F_71 ( V_180 ) ;
V_11 -> V_19 . V_180 [ V_33 ] = NULL ;
}
return V_13 ;
}
int F_72 ( struct V_11 * V_11 , int V_198 , int V_49 , int V_12 ,
struct V_199 * V_200 )
{
struct V_201 * V_202 ;
struct V_179 * V_180 ;
int V_13 ;
if ( V_198 >= F_2 ( V_11 -> V_19 . V_202 ) || V_198 < 0 ) {
F_26 ( V_11 -> V_62 , L_15 , V_198 ) ;
return - V_184 ;
}
V_202 = & V_11 -> V_19 . V_202 [ V_198 ] ;
if ( V_202 -> V_180 ) {
F_26 ( V_11 -> V_62 , L_16 , V_198 ) ;
return - V_6 ;
}
V_180 = F_68 ( L_17 , V_198 ) ;
if ( V_180 == NULL ) {
F_26 ( V_11 -> V_62 , L_18 , V_198 ) ;
return - V_196 ;
}
V_202 -> V_203 . V_204 = V_204 ( & V_180 -> V_62 ) ;
V_202 -> V_203 . V_205 = L_19 ;
V_202 -> V_206 . V_207 = 1 ;
V_202 -> V_206 . V_208 = & V_202 -> V_203 ;
V_202 -> V_206 . V_209 . V_1 = 0 ;
V_202 -> V_206 . V_209 . V_2 = V_200 -> V_2 ;
V_202 -> V_206 . V_209 . V_210
= V_211 | V_212 ;
V_202 -> V_206 . V_209 . V_213 = V_85 ;
V_13 = F_67 ( V_11 , V_12 , & V_202 -> V_206 ) ;
if ( V_13 != 0 ) {
F_71 ( V_180 ) ;
return V_13 ;
}
V_202 -> V_214 . V_204 = V_204 ( & V_180 -> V_62 ) ;
V_202 -> V_214 . V_205 = L_20 ;
V_202 -> V_215 . V_207 = 1 ;
V_202 -> V_215 . V_208 = & V_202 -> V_214 ;
V_202 -> V_215 . V_209 . V_213 = V_85 ;
V_202 -> V_215 . V_209 . V_210 = V_212 ;
V_13 = F_67 ( V_11 , V_49 , & V_202 -> V_215 ) ;
if ( V_13 != 0 ) {
F_71 ( V_180 ) ;
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
V_180 -> V_62 . V_186 = V_200 ;
V_180 -> V_62 . V_197 = V_11 -> V_62 ;
V_13 = F_70 ( V_180 ) ;
if ( V_13 != 0 ) {
F_26 ( V_11 -> V_62 , L_21 ,
V_198 , V_13 ) ;
F_71 ( V_180 ) ;
return V_13 ;
}
V_202 -> V_180 = V_180 ;
return 0 ;
}
static int T_3 F_73 ( void )
{
return F_74 ( & V_216 ) ;
}
static void T_4 F_75 ( void )
{
F_76 ( & V_216 ) ;
}
