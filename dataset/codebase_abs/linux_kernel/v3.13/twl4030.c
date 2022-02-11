static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return - V_7 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_11 = 0 ;
F_2 ( V_2 , V_3 , V_8 ) ;
switch ( V_3 ) {
case V_12 :
if ( V_10 -> V_13 )
V_11 = 1 ;
break;
case V_14 :
if ( V_10 -> V_15 )
V_11 = 1 ;
break;
case V_16 :
if ( V_10 -> V_17 )
V_11 = 1 ;
break;
case V_18 :
if ( V_10 -> V_19 )
V_11 = 1 ;
break;
case V_20 :
if ( V_10 -> V_21 )
V_11 = 1 ;
break;
case V_22 :
if ( V_10 -> V_23 || V_10 -> V_24 )
V_11 = 1 ;
break;
default:
V_11 = 1 ;
break;
}
if ( V_11 )
return F_5 ( V_25 ,
V_8 , V_3 ) ;
return 0 ;
}
static inline void F_6 ( int time )
{
if ( time < 60 ) {
time *= 1000 ;
F_7 ( time , time + 500 ) ;
} else {
F_8 ( time ) ;
}
}
static void F_9 ( struct V_1 * V_2 , int V_26 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_27 ;
if ( V_26 == V_10 -> V_28 )
return;
if ( V_26 )
V_27 = F_10 ( V_29 ) ;
else
V_27 = F_11 ( V_29 ) ;
if ( V_27 >= 0 ) {
F_2 ( V_2 , V_30 , V_27 ) ;
V_10 -> V_28 = V_26 ;
}
F_12 ( 10 ) ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
int V_31 , V_32 = 0 ;
T_1 V_33 ;
F_14 ( V_2 -> V_34 , L_1 ) ;
for ( V_31 = 1 ; V_31 <= V_35 ; V_31 ++ ) {
F_15 ( V_25 , & V_33 , V_31 ) ;
if ( V_33 != V_36 [ V_31 ] ) {
V_32 ++ ;
F_14 ( V_2 -> V_34 ,
L_2 ,
V_31 , V_33 , V_36 [ V_31 ] ) ;
}
}
F_14 ( V_2 -> V_34 , L_3 ,
V_32 , V_32 ? L_4 : L_5 ) ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
int V_31 ;
for ( V_31 = V_37 ; V_31 <= V_35 ; V_31 ++ )
if ( V_31 != V_38 )
F_3 ( V_2 , V_31 , V_36 [ V_31 ] ) ;
}
static void F_17 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
int V_8 ;
F_18 ( V_42 , L_6 ,
& V_40 -> V_43 ) ;
F_18 ( V_42 , L_7 ,
& V_40 -> V_44 ) ;
F_18 ( V_42 , L_8 ,
& V_40 -> V_45 ) ;
if ( ! F_18 ( V_42 , L_9 , & V_8 ) )
V_40 -> V_46 = V_8 ;
V_40 -> V_47 = F_19 ( V_42 ,
L_10 , 0 ) ;
if ( F_20 ( V_40 -> V_47 ) )
V_40 -> V_46 = 1 ;
}
static struct V_39 * F_21 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_22 ( V_2 -> V_34 ) ;
struct V_41 * V_48 = NULL ;
V_48 = F_23 ( V_2 -> V_34 -> V_49 -> V_50 ,
L_11 ) ;
if ( ! V_40 && V_48 ) {
V_40 = F_24 ( V_2 -> V_34 ,
sizeof( struct V_39 ) ,
V_51 ) ;
if ( ! V_40 ) {
F_25 ( V_2 -> V_34 , L_12 ) ;
return NULL ;
}
F_17 ( V_40 , V_48 ) ;
}
return V_40 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_3 , V_52 ;
int V_31 = 0 ;
V_40 = F_21 ( V_2 ) ;
if ( V_40 && V_40 -> V_46 ) {
if ( F_20 ( V_40 -> V_47 ) ) {
int V_53 ;
if ( ! V_40 -> V_47 )
F_27 ( V_2 -> V_34 ,
L_13 ) ;
V_53 = F_28 ( V_40 -> V_47 ,
V_54 ,
L_14 ) ;
if ( V_53 ) {
F_25 ( V_2 -> V_34 ,
L_15 ) ;
V_40 -> V_47 = - 1 ;
}
} else {
T_1 V_55 ;
F_15 ( V_56 , & V_55 ,
V_57 ) ;
V_55 &= ~ F_29 ( 0x03 ) ;
V_55 |= F_29 ( 0x02 ) ;
F_5 ( V_56 , V_55 ,
V_57 ) ;
}
}
if ( V_40 && V_40 -> V_58 )
F_13 ( V_2 ) ;
if ( ! V_40 || ( V_40 && V_40 -> V_59 ) )
F_16 ( V_2 ) ;
F_15 ( V_25 , & V_52 ,
V_38 ) ;
F_2 ( V_2 , V_38 , V_52 ) ;
V_3 = F_1 ( V_2 , V_60 ) ;
F_3 ( V_2 , V_60 ,
V_3 | V_61 ) ;
F_3 ( V_2 , V_37 ,
V_62 | V_63 |
V_64 | V_65 ) ;
F_3 ( V_2 , V_66 , 0x32 ) ;
if ( ! V_40 )
return;
V_10 -> V_40 = V_40 ;
V_3 = F_1 ( V_2 , V_67 ) ;
V_3 &= ~ V_68 ;
V_3 |= ( V_40 -> V_44 << 2 ) ;
F_2 ( V_2 , V_67 , V_3 ) ;
F_9 ( V_2 , 1 ) ;
V_3 = F_1 ( V_2 , V_69 ) ;
V_3 &= ~ V_70 ;
V_3 |= V_40 -> V_45 ;
F_3 ( V_2 , V_69 ,
V_3 | V_71 ) ;
F_8 ( 20 ) ;
do {
F_7 ( 1000 , 2000 ) ;
F_15 ( V_25 , & V_52 ,
V_69 ) ;
} while ( ( V_31 ++ < 100 ) &&
( ( V_52 & V_71 ) ==
V_71 ) );
F_2 ( V_2 , V_69 , V_52 ) ;
F_9 ( V_2 , 0 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_26 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_72 = - 1 ;
if ( V_26 ) {
V_10 -> V_73 ++ ;
if ( V_10 -> V_73 == 1 )
V_72 = F_10 (
V_74 ) ;
} else {
V_10 -> V_73 -- ;
if ( ! V_10 -> V_73 )
V_72 = F_11 (
V_74 ) ;
}
if ( V_72 >= 0 )
F_2 ( V_2 , V_38 , V_72 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_3 , int V_75 )
{
unsigned char V_76 ;
V_76 = F_1 ( V_2 , V_3 ) ;
if ( V_75 ) {
V_76 |= V_77 ;
F_3 ( V_2 , V_3 , V_76 ) ;
F_12 ( 10 ) ;
V_76 |= V_78 ;
F_3 ( V_2 , V_3 , V_76 ) ;
F_12 ( 40 ) ;
V_76 |= V_79 ;
V_76 |= V_80 ;
F_3 ( V_2 , V_3 , V_76 ) ;
} else {
V_76 &= ~ V_79 ;
V_76 &= ~ V_80 ;
F_3 ( V_2 , V_3 , V_76 ) ;
V_76 &= ~ V_78 ;
F_3 ( V_2 , V_3 , V_76 ) ;
F_12 ( 40 ) ;
V_76 &= ~ V_77 ;
F_3 ( V_2 , V_3 , V_76 ) ;
}
}
static int F_32 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
switch ( V_85 ) {
case V_86 :
F_31 ( V_82 -> V_2 , V_87 , 1 ) ;
break;
case V_88 :
F_31 ( V_82 -> V_2 , V_87 , 0 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
switch ( V_85 ) {
case V_86 :
F_31 ( V_82 -> V_2 , V_89 , 1 ) ;
break;
case V_88 :
F_31 ( V_82 -> V_2 , V_89 , 0 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
F_3 ( V_82 -> V_2 , V_90 , 0xff ) ;
return 0 ;
}
static int F_35 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
switch ( V_85 ) {
case V_91 :
F_30 ( V_82 -> V_2 , 1 ) ;
break;
case V_88 :
F_30 ( V_82 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
T_1 V_92 ;
V_92 = F_1 ( V_82 -> V_2 , V_93 ) ;
switch ( V_85 ) {
case V_91 :
F_30 ( V_82 -> V_2 , 1 ) ;
F_3 ( V_82 -> V_2 , V_93 ,
V_92 | V_94 ) ;
break;
case V_88 :
F_3 ( V_82 -> V_2 , V_93 ,
V_92 & ~ V_94 ) ;
F_30 ( V_82 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , int V_75 )
{
unsigned char V_95 , V_96 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_39 * V_40 = V_10 -> V_40 ;
unsigned int V_97 [] = { 524288 , 1048576 , 2097152 , 4194304 ,
8388608 , 16777216 , 33554432 , 67108864 } ;
unsigned int V_98 ;
V_95 = F_1 ( V_2 , V_22 ) ;
V_96 = F_1 ( V_2 , V_67 ) ;
V_98 = ( V_97 [ ( V_96 & V_68 ) >> 2 ] /
V_10 -> V_99 ) + 1 ;
if ( V_40 && V_40 -> V_46 ) {
if ( F_20 ( V_40 -> V_47 ) ) {
F_38 ( V_40 -> V_47 , 1 ) ;
} else {
V_96 |= V_100 ;
F_3 ( V_2 , V_67 , V_96 ) ;
}
}
if ( V_75 ) {
V_96 |= V_101 ;
F_3 ( V_2 , V_67 , V_96 ) ;
F_5 ( V_25 ,
V_95 ,
V_22 ) ;
V_96 |= V_102 ;
F_3 ( V_2 , V_67 , V_96 ) ;
F_6 ( V_98 ) ;
} else {
V_96 &= ~ V_102 ;
F_3 ( V_2 , V_67 , V_96 ) ;
F_6 ( V_98 ) ;
F_5 ( V_25 ,
V_95 & ( ~ 0x0f ) ,
V_22 ) ;
V_96 &= ~ V_101 ;
F_3 ( V_2 , V_67 , V_96 ) ;
}
if ( V_40 && V_40 -> V_46 ) {
if ( F_20 ( V_40 -> V_47 ) ) {
F_38 ( V_40 -> V_47 , 0 ) ;
} else {
V_96 &= ~ V_100 ;
F_3 ( V_2 , V_67 , V_96 ) ;
}
}
}
static int F_39 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
struct V_9 * V_10 = F_4 ( V_82 -> V_2 ) ;
switch ( V_85 ) {
case V_86 :
if ( ! V_10 -> V_24 )
F_37 ( V_82 -> V_2 , 1 ) ;
V_10 -> V_23 = 1 ;
break;
case V_88 :
if ( ! V_10 -> V_24 )
F_37 ( V_82 -> V_2 , 0 ) ;
V_10 -> V_23 = 0 ;
break;
}
return 0 ;
}
static int F_40 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
struct V_9 * V_10 = F_4 ( V_82 -> V_2 ) ;
switch ( V_85 ) {
case V_86 :
if ( ! V_10 -> V_23 )
F_37 ( V_82 -> V_2 , 1 ) ;
V_10 -> V_24 = 1 ;
break;
case V_88 :
if ( ! V_10 -> V_23 )
F_37 ( V_82 -> V_2 , 0 ) ;
V_10 -> V_24 = 0 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_81 * V_82 ,
struct V_83 * V_84 , int V_85 )
{
struct V_9 * V_10 = F_4 ( V_82 -> V_2 ) ;
struct V_39 * V_40 = V_10 -> V_40 ;
if ( V_40 && V_40 -> V_43 )
F_6 ( V_40 -> V_43 ) ;
return 0 ;
}
static int F_42 ( struct V_83 * V_84 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 =
(struct V_105 * ) V_84 -> V_107 ;
struct V_1 * V_2 = F_43 ( V_84 ) ;
unsigned int V_3 = V_106 -> V_3 ;
unsigned int V_108 = V_106 -> V_108 ;
unsigned int V_109 = V_106 -> V_109 ;
int V_110 = V_106 -> V_110 ;
int V_111 = ( 1 << F_44 ( V_110 ) ) - 1 ;
V_104 -> V_8 . integer . V_8 [ 0 ] =
( F_45 ( V_2 , V_3 ) >> V_108 ) & V_111 ;
if ( V_104 -> V_8 . integer . V_8 [ 0 ] )
V_104 -> V_8 . integer . V_8 [ 0 ] =
V_110 + 1 - V_104 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_108 != V_109 ) {
V_104 -> V_8 . integer . V_8 [ 1 ] =
( F_45 ( V_2 , V_3 ) >> V_109 ) & V_111 ;
if ( V_104 -> V_8 . integer . V_8 [ 1 ] )
V_104 -> V_8 . integer . V_8 [ 1 ] =
V_110 + 1 - V_104 -> V_8 . integer . V_8 [ 1 ] ;
}
return 0 ;
}
static int F_46 ( struct V_83 * V_84 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 =
(struct V_105 * ) V_84 -> V_107 ;
struct V_1 * V_2 = F_43 ( V_84 ) ;
unsigned int V_3 = V_106 -> V_3 ;
unsigned int V_108 = V_106 -> V_108 ;
unsigned int V_109 = V_106 -> V_109 ;
int V_110 = V_106 -> V_110 ;
int V_111 = ( 1 << F_44 ( V_110 ) ) - 1 ;
unsigned short V_33 , V_112 , V_113 ;
V_33 = ( V_104 -> V_8 . integer . V_8 [ 0 ] & V_111 ) ;
V_113 = V_111 << V_108 ;
if ( V_33 )
V_33 = V_110 + 1 - V_33 ;
V_33 = V_33 << V_108 ;
if ( V_108 != V_109 ) {
V_112 = ( V_104 -> V_8 . integer . V_8 [ 1 ] & V_111 ) ;
V_113 |= V_111 << V_109 ;
if ( V_112 )
V_112 = V_110 + 1 - V_112 ;
V_33 |= V_112 << V_109 ;
}
return F_47 ( V_2 , V_3 , V_113 , V_33 ) ;
}
static int F_48 ( struct V_83 * V_84 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 =
(struct V_105 * ) V_84 -> V_107 ;
struct V_1 * V_2 = F_43 ( V_84 ) ;
unsigned int V_3 = V_106 -> V_3 ;
unsigned int V_114 = V_106 -> V_115 ;
unsigned int V_108 = V_106 -> V_108 ;
int V_110 = V_106 -> V_110 ;
int V_111 = ( 1 << F_44 ( V_110 ) ) - 1 ;
V_104 -> V_8 . integer . V_8 [ 0 ] =
( F_45 ( V_2 , V_3 ) >> V_108 ) & V_111 ;
V_104 -> V_8 . integer . V_8 [ 1 ] =
( F_45 ( V_2 , V_114 ) >> V_108 ) & V_111 ;
if ( V_104 -> V_8 . integer . V_8 [ 0 ] )
V_104 -> V_8 . integer . V_8 [ 0 ] =
V_110 + 1 - V_104 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_104 -> V_8 . integer . V_8 [ 1 ] )
V_104 -> V_8 . integer . V_8 [ 1 ] =
V_110 + 1 - V_104 -> V_8 . integer . V_8 [ 1 ] ;
return 0 ;
}
static int F_49 ( struct V_83 * V_84 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 =
(struct V_105 * ) V_84 -> V_107 ;
struct V_1 * V_2 = F_43 ( V_84 ) ;
unsigned int V_3 = V_106 -> V_3 ;
unsigned int V_114 = V_106 -> V_115 ;
unsigned int V_108 = V_106 -> V_108 ;
int V_110 = V_106 -> V_110 ;
int V_111 = ( 1 << F_44 ( V_110 ) ) - 1 ;
int V_116 ;
unsigned short V_33 , V_112 , V_113 ;
V_113 = V_111 << V_108 ;
V_33 = ( V_104 -> V_8 . integer . V_8 [ 0 ] & V_111 ) ;
V_112 = ( V_104 -> V_8 . integer . V_8 [ 1 ] & V_111 ) ;
if ( V_33 )
V_33 = V_110 + 1 - V_33 ;
if ( V_112 )
V_112 = V_110 + 1 - V_112 ;
V_33 = V_33 << V_108 ;
V_112 = V_112 << V_108 ;
V_116 = F_47 ( V_2 , V_3 , V_113 , V_33 ) ;
if ( V_116 < 0 )
return V_116 ;
V_116 = F_47 ( V_2 , V_114 , V_113 , V_112 ) ;
return V_116 ;
}
static int F_50 ( struct V_83 * V_84 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = F_43 ( V_84 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_117 * V_118 = (struct V_117 * ) V_84 -> V_107 ;
unsigned short V_33 ;
unsigned short V_111 ;
if ( V_10 -> V_119 ) {
F_25 ( V_2 -> V_34 ,
L_16 ) ;
return - V_120 ;
}
if ( V_104 -> V_8 . V_121 . V_122 [ 0 ] > V_118 -> V_110 - 1 )
return - V_123 ;
V_33 = V_104 -> V_8 . V_121 . V_122 [ 0 ] << V_118 -> V_124 ;
V_111 = V_118 -> V_111 << V_118 -> V_124 ;
if ( V_118 -> V_124 != V_118 -> V_125 ) {
if ( V_104 -> V_8 . V_121 . V_122 [ 1 ] > V_118 -> V_110 - 1 )
return - V_123 ;
V_33 |= V_104 -> V_8 . V_121 . V_122 [ 1 ] << V_118 -> V_125 ;
V_111 |= V_118 -> V_111 << V_118 -> V_125 ;
}
return F_47 ( V_2 , V_118 -> V_3 , V_111 , V_33 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
enum V_126 V_127 )
{
switch ( V_127 ) {
case V_128 :
break;
case V_129 :
break;
case V_130 :
if ( V_2 -> V_131 . V_132 == V_133 )
F_9 ( V_2 , 1 ) ;
break;
case V_133 :
F_9 ( V_2 , 0 ) ;
break;
}
V_2 -> V_131 . V_132 = V_127 ;
return 0 ;
}
static void F_52 ( struct V_9 * V_10 ,
struct V_134 * V_135 )
{
struct V_134 * V_136 ;
if ( V_135 == V_10 -> V_137 )
V_136 = V_10 -> V_138 ;
else if ( V_135 == V_10 -> V_138 )
V_136 = V_10 -> V_137 ;
else
return;
F_53 ( V_136 -> V_139 ,
V_140 ,
V_10 -> V_141 ,
V_10 -> V_141 ) ;
F_53 ( V_136 -> V_139 ,
V_142 ,
V_10 -> V_143 ,
V_10 -> V_143 ) ;
F_53 ( V_136 -> V_139 ,
V_144 ,
V_10 -> V_145 ,
V_10 -> V_145 ) ;
}
static void F_54 ( struct V_1 * V_2 , int V_146 ,
int V_26 )
{
T_1 V_3 , V_111 ;
V_3 = F_1 ( V_2 , V_37 ) ;
if ( V_146 == V_147 )
V_111 = V_148 | V_149 ;
else
V_111 = V_150 | V_151 ;
if ( V_26 )
V_3 |= V_111 ;
else
V_3 &= ~ V_111 ;
F_3 ( V_2 , V_37 , V_3 ) ;
}
static int F_55 ( struct V_134 * V_152 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_137 ) {
V_10 -> V_138 = V_152 ;
if ( V_10 -> V_119 )
F_52 ( V_10 , V_10 -> V_137 ) ;
} else {
if ( ! ( F_1 ( V_2 , V_30 ) &
V_155 ) ) {
F_53 ( V_152 -> V_139 ,
V_144 ,
2 , 2 ) ;
}
V_10 -> V_137 = V_152 ;
}
return 0 ;
}
static void F_56 ( struct V_134 * V_152 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_137 == V_152 )
V_10 -> V_137 = V_10 -> V_138 ;
V_10 -> V_138 = NULL ;
if ( ! V_10 -> V_137 )
V_10 -> V_119 = 0 ;
else if ( ! V_10 -> V_137 -> V_139 -> V_145 )
V_10 -> V_119 = 0 ;
if ( V_152 -> V_139 -> V_145 == 4 )
F_54 ( V_2 , V_152 -> V_156 , 0 ) ;
}
static int F_57 ( struct V_134 * V_152 ,
struct V_157 * V_158 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_27 , V_159 , V_160 , V_161 ;
if ( F_58 ( V_158 ) == 4 ) {
V_160 = F_1 ( V_2 , V_93 ) ;
V_27 = F_1 ( V_2 , V_30 ) ;
if ( ( V_27 & V_155 ) &&
( ( V_160 & V_162 ) == V_163 ) )
F_54 ( V_2 , V_152 -> V_156 , 1 ) ;
else
return - V_123 ;
}
if ( V_10 -> V_119 )
return 0 ;
V_159 = F_1 ( V_2 ,
V_30 ) & ~ V_164 ;
V_27 = V_159 & ~ V_165 ;
switch ( F_59 ( V_158 ) ) {
case 8000 :
V_27 |= V_166 ;
break;
case 11025 :
V_27 |= V_167 ;
break;
case 12000 :
V_27 |= V_168 ;
break;
case 16000 :
V_27 |= V_169 ;
break;
case 22050 :
V_27 |= V_170 ;
break;
case 24000 :
V_27 |= V_171 ;
break;
case 32000 :
V_27 |= V_172 ;
break;
case 44100 :
V_27 |= V_173 ;
break;
case 48000 :
V_27 |= V_174 ;
break;
case 96000 :
V_27 |= V_175 ;
break;
default:
F_25 ( V_2 -> V_34 , L_17 , V_176 ,
F_59 ( V_158 ) ) ;
return - V_123 ;
}
V_161 = F_1 ( V_2 , V_93 ) ;
V_160 = V_161 ;
V_160 &= ~ V_177 ;
switch ( F_60 ( V_158 ) ) {
case V_178 :
V_160 |= V_179 ;
break;
case V_180 :
V_160 |= V_181 ;
break;
default:
F_25 ( V_2 -> V_34 , L_18 , V_176 ,
F_60 ( V_158 ) ) ;
return - V_123 ;
}
if ( V_160 != V_161 || V_27 != V_159 ) {
if ( V_10 -> V_28 ) {
F_9 ( V_2 , 0 ) ;
F_3 ( V_2 , V_30 , V_27 ) ;
F_3 ( V_2 , V_93 , V_160 ) ;
F_9 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_30 , V_27 ) ;
F_3 ( V_2 , V_93 , V_160 ) ;
}
}
V_10 -> V_119 = 1 ;
V_10 -> V_141 = F_59 ( V_158 ) ;
V_10 -> V_143 = F_61 ( V_158 ,
V_142 ) -> V_182 ;
V_10 -> V_145 = F_58 ( V_158 ) ;
if ( V_10 -> V_138 )
F_52 ( V_10 , V_152 ) ;
return 0 ;
}
static int F_62 ( struct V_153 * V_183 ,
int V_184 , unsigned int V_185 , int V_186 )
{
struct V_1 * V_2 = V_183 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
switch ( V_185 ) {
case 19200000 :
case 26000000 :
case 38400000 :
break;
default:
F_25 ( V_2 -> V_34 , L_19 , V_185 ) ;
return - V_123 ;
}
if ( ( V_185 / 1000 ) != V_10 -> V_99 ) {
F_25 ( V_2 -> V_34 ,
L_20 ,
V_185 , V_10 -> V_99 * 1000 ) ;
return - V_123 ;
}
return 0 ;
}
static int F_63 ( struct V_153 * V_183 ,
unsigned int V_187 )
{
struct V_1 * V_2 = V_183 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_161 , V_160 ;
V_161 = F_1 ( V_2 , V_93 ) ;
V_160 = V_161 ;
switch ( V_187 & V_188 ) {
case V_189 :
V_160 &= ~ ( V_190 ) ;
V_160 &= ~ ( V_191 ) ;
break;
case V_192 :
V_160 |= V_190 ;
V_160 |= V_191 ;
break;
default:
return - V_123 ;
}
V_160 &= ~ V_162 ;
switch ( V_187 & V_193 ) {
case V_194 :
V_160 |= V_195 ;
break;
case V_196 :
V_160 |= V_163 ;
break;
default:
return - V_123 ;
}
if ( V_160 != V_161 ) {
if ( V_10 -> V_28 ) {
F_9 ( V_2 , 0 ) ;
F_3 ( V_2 , V_93 , V_160 ) ;
F_9 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_93 , V_160 ) ;
}
}
return 0 ;
}
static int F_64 ( struct V_153 * V_154 , int V_197 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_93 ) ;
if ( V_197 )
V_3 |= V_198 ;
else
V_3 &= ~ V_198 ;
return F_3 ( V_2 , V_93 , V_3 ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_146 ,
int V_26 )
{
T_1 V_3 , V_111 ;
V_3 = F_1 ( V_2 , V_37 ) ;
if ( V_146 == V_147 )
V_111 = V_148 ;
else
V_111 = V_150 | V_151 ;
if ( V_26 )
V_3 |= V_111 ;
else
V_3 &= ~ V_111 ;
F_3 ( V_2 , V_37 , V_3 ) ;
}
static int F_66 ( struct V_134 * V_152 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_27 ;
if ( V_10 -> V_99 != 26000 ) {
F_25 ( V_2 -> V_34 ,
L_21 ,
V_176 , V_10 -> V_99 ) ;
return - V_123 ;
}
V_27 = F_1 ( V_2 , V_30 )
& V_199 ;
if ( V_27 != V_200 ) {
F_25 ( V_2 -> V_34 , L_22 ,
V_176 ) ;
return - V_123 ;
}
return 0 ;
}
static void F_67 ( struct V_134 * V_152 ,
struct V_153 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
F_65 ( V_2 , V_152 -> V_156 , 0 ) ;
}
static int F_68 ( struct V_134 * V_152 ,
struct V_157 * V_158 , struct V_153 * V_154 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_159 , V_27 ;
F_65 ( V_2 , V_152 -> V_156 , 1 ) ;
V_159 = F_1 ( V_2 , V_30 )
& ~ ( V_164 ) ;
V_27 = V_159 ;
switch ( F_59 ( V_158 ) ) {
case 8000 :
V_27 &= ~ ( V_201 ) ;
break;
case 16000 :
V_27 |= V_201 ;
break;
default:
F_25 ( V_2 -> V_34 , L_17 , V_176 ,
F_59 ( V_158 ) ) ;
return - V_123 ;
}
if ( V_27 != V_159 ) {
if ( V_10 -> V_28 ) {
F_9 ( V_2 , 0 ) ;
F_3 ( V_2 , V_30 , V_27 ) ;
F_9 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_30 , V_27 ) ;
}
}
return 0 ;
}
static int F_69 ( struct V_153 * V_183 ,
int V_184 , unsigned int V_185 , int V_186 )
{
struct V_1 * V_2 = V_183 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_185 != 26000000 ) {
F_25 ( V_2 -> V_34 ,
L_21 ,
V_176 , V_185 / 1000 ) ;
return - V_123 ;
}
if ( ( V_185 / 1000 ) != V_10 -> V_99 ) {
F_25 ( V_2 -> V_34 ,
L_20 ,
V_185 , V_10 -> V_99 * 1000 ) ;
return - V_123 ;
}
return 0 ;
}
static int F_70 ( struct V_153 * V_183 ,
unsigned int V_187 )
{
struct V_1 * V_2 = V_183 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_161 , V_160 ;
V_161 = F_1 ( V_2 , V_202 ) ;
V_160 = V_161 ;
switch ( V_187 & V_188 ) {
case V_189 :
V_160 &= ~ ( V_203 ) ;
break;
case V_192 :
V_160 |= V_203 ;
break;
default:
return - V_123 ;
}
switch ( V_187 & V_204 ) {
case V_205 :
V_160 &= ~ ( V_206 ) ;
break;
case V_207 :
V_160 |= V_206 ;
break;
default:
return - V_123 ;
}
if ( V_160 != V_161 ) {
if ( V_10 -> V_28 ) {
F_9 ( V_2 , 0 ) ;
F_3 ( V_2 , V_202 , V_160 ) ;
F_9 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_202 , V_160 ) ;
}
}
return 0 ;
}
static int F_71 ( struct V_153 * V_154 , int V_197 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_202 ) ;
if ( V_197 )
V_3 |= V_208 ;
else
V_3 &= ~ V_208 ;
return F_3 ( V_2 , V_202 , V_3 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_24 ( V_2 -> V_34 , sizeof( struct V_9 ) ,
V_51 ) ;
if ( V_10 == NULL ) {
F_25 ( V_2 -> V_34 , L_12 ) ;
return - V_209 ;
}
F_73 ( V_2 , V_10 ) ;
V_10 -> V_99 = F_74 () / 1000 ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_39 * V_40 = V_10 -> V_40 ;
F_16 ( V_2 ) ;
F_51 ( V_2 , V_133 ) ;
if ( V_40 && V_40 -> V_46 && F_20 ( V_40 -> V_47 ) )
F_76 ( V_40 -> V_47 ) ;
return 0 ;
}
static int F_77 ( struct V_210 * V_211 )
{
return F_78 ( & V_211 -> V_34 , & V_212 ,
V_213 , F_79 ( V_213 ) ) ;
}
static int F_80 ( struct V_210 * V_211 )
{
F_81 ( & V_211 -> V_34 ) ;
return 0 ;
}
