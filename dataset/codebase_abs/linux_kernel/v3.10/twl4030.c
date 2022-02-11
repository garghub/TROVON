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
if ( F_5 ( V_3 < V_12 ) ) {
switch ( V_3 ) {
case V_13 :
if ( V_10 -> V_14 )
V_11 = 1 ;
break;
case V_15 :
if ( V_10 -> V_16 )
V_11 = 1 ;
break;
case V_17 :
if ( V_10 -> V_18 )
V_11 = 1 ;
break;
case V_19 :
if ( V_10 -> V_20 )
V_11 = 1 ;
break;
case V_21 :
if ( V_10 -> V_22 )
V_11 = 1 ;
break;
case V_23 :
if ( V_10 -> V_24 || V_10 -> V_25 )
V_11 = 1 ;
break;
default:
V_11 = 1 ;
break;
}
if ( V_11 )
return F_6 ( V_26 ,
V_8 , V_3 ) ;
}
return 0 ;
}
static inline void F_7 ( int time )
{
if ( time < 60 ) {
time *= 1000 ;
F_8 ( time , time + 500 ) ;
} else {
F_9 ( time ) ;
}
}
static void F_10 ( struct V_1 * V_2 , int V_27 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_28 ;
if ( V_27 == V_10 -> V_29 )
return;
if ( V_27 )
V_28 = F_11 ( V_30 ) ;
else
V_28 = F_12 ( V_30 ) ;
if ( V_28 >= 0 ) {
F_2 ( V_2 , V_31 , V_28 ) ;
V_10 -> V_29 = V_27 ;
}
F_13 ( 10 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
int V_32 , V_33 = 0 ;
T_1 V_34 ;
F_15 ( V_2 -> V_35 , L_1 ) ;
for ( V_32 = 1 ; V_32 <= V_36 ; V_32 ++ ) {
F_16 ( V_26 , & V_34 , V_32 ) ;
if ( V_34 != V_37 [ V_32 ] ) {
V_33 ++ ;
F_15 ( V_2 -> V_35 ,
L_2 ,
V_32 , V_34 , V_37 [ V_32 ] ) ;
}
}
F_15 ( V_2 -> V_35 , L_3 ,
V_33 , V_33 ? L_4 : L_5 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
int V_32 ;
for ( V_32 = V_38 ; V_32 <= V_36 ; V_32 ++ )
if ( V_32 != V_39 )
F_3 ( V_2 , V_32 , V_37 [ V_32 ] ) ;
}
static void F_18 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
int V_8 ;
F_19 ( V_43 , L_6 ,
& V_41 -> V_44 ) ;
F_19 ( V_43 , L_7 ,
& V_41 -> V_45 ) ;
F_19 ( V_43 , L_8 ,
& V_41 -> V_46 ) ;
if ( ! F_19 ( V_43 , L_9 , & V_8 ) )
V_41 -> V_47 = V_8 ;
V_41 -> V_48 = F_20 ( V_43 ,
L_10 , 0 ) ;
if ( F_21 ( V_41 -> V_48 ) )
V_41 -> V_47 = 1 ;
}
static struct V_40 * F_22 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_23 ( V_2 -> V_35 ) ;
struct V_42 * V_49 = NULL ;
V_49 = F_24 ( V_2 -> V_35 -> V_50 -> V_51 ,
L_11 ) ;
if ( ! V_41 && V_49 ) {
V_41 = F_25 ( V_2 -> V_35 ,
sizeof( struct V_40 ) ,
V_52 ) ;
if ( ! V_41 ) {
F_26 ( V_2 -> V_35 , L_12 ) ;
return NULL ;
}
F_18 ( V_41 , V_49 ) ;
}
return V_41 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_40 * V_41 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_3 , V_53 ;
int V_32 = 0 ;
V_41 = F_22 ( V_2 ) ;
if ( V_41 && V_41 -> V_47 ) {
if ( F_21 ( V_41 -> V_48 ) ) {
int V_54 ;
if ( ! V_41 -> V_48 )
F_28 ( V_2 -> V_35 ,
L_13 ) ;
V_54 = F_29 ( V_41 -> V_48 ,
V_55 ,
L_14 ) ;
if ( V_54 ) {
F_26 ( V_2 -> V_35 ,
L_15 ) ;
V_41 -> V_48 = - 1 ;
}
} else {
T_1 V_56 ;
F_16 ( V_57 , & V_56 ,
V_58 ) ;
V_56 &= ~ F_30 ( 0x03 ) ;
V_56 |= F_30 ( 0x02 ) ;
F_6 ( V_57 , V_56 ,
V_58 ) ;
}
}
if ( V_41 && V_41 -> V_59 )
F_14 ( V_2 ) ;
if ( ! V_41 || ( V_41 && V_41 -> V_60 ) )
F_17 ( V_2 ) ;
F_16 ( V_26 , & V_53 ,
V_39 ) ;
F_2 ( V_2 , V_39 , V_53 ) ;
V_3 = F_1 ( V_2 , V_61 ) ;
F_3 ( V_2 , V_61 ,
V_3 | V_62 ) ;
F_3 ( V_2 , V_38 ,
V_63 | V_64 |
V_65 | V_66 ) ;
F_3 ( V_2 , V_67 , 0x32 ) ;
if ( ! V_41 )
return;
V_10 -> V_41 = V_41 ;
V_3 = F_1 ( V_2 , V_68 ) ;
V_3 &= ~ V_69 ;
V_3 |= ( V_41 -> V_45 << 2 ) ;
F_2 ( V_2 , V_68 , V_3 ) ;
F_10 ( V_2 , 1 ) ;
V_3 = F_1 ( V_2 , V_70 ) ;
V_3 &= ~ V_71 ;
V_3 |= V_41 -> V_46 ;
F_3 ( V_2 , V_70 ,
V_3 | V_72 ) ;
F_9 ( 20 ) ;
do {
F_8 ( 1000 , 2000 ) ;
F_16 ( V_26 , & V_53 ,
V_70 ) ;
} while ( ( V_32 ++ < 100 ) &&
( ( V_53 & V_72 ) ==
V_72 ) );
F_2 ( V_2 , V_70 , V_53 ) ;
F_10 ( V_2 , 0 ) ;
}
static void F_31 ( struct V_1 * V_2 , int V_27 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
int V_73 = - 1 ;
if ( V_27 ) {
V_10 -> V_74 ++ ;
if ( V_10 -> V_74 == 1 )
V_73 = F_11 (
V_75 ) ;
} else {
V_10 -> V_74 -- ;
if ( ! V_10 -> V_74 )
V_73 = F_12 (
V_75 ) ;
}
if ( V_73 >= 0 )
F_2 ( V_2 , V_39 , V_73 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_3 , int V_76 )
{
unsigned char V_77 ;
V_77 = F_1 ( V_2 , V_3 ) ;
if ( V_76 ) {
V_77 |= V_78 ;
F_3 ( V_2 , V_3 , V_77 ) ;
F_13 ( 10 ) ;
V_77 |= V_79 ;
F_3 ( V_2 , V_3 , V_77 ) ;
F_13 ( 40 ) ;
V_77 |= V_80 ;
V_77 |= V_81 ;
F_3 ( V_2 , V_3 , V_77 ) ;
} else {
V_77 &= ~ V_80 ;
V_77 &= ~ V_81 ;
F_3 ( V_2 , V_3 , V_77 ) ;
V_77 &= ~ V_79 ;
F_3 ( V_2 , V_3 , V_77 ) ;
F_13 ( 40 ) ;
V_77 &= ~ V_78 ;
F_3 ( V_2 , V_3 , V_77 ) ;
}
}
static int F_33 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
switch ( V_86 ) {
case V_87 :
F_32 ( V_83 -> V_2 , V_88 , 1 ) ;
break;
case V_89 :
F_32 ( V_83 -> V_2 , V_88 , 0 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
switch ( V_86 ) {
case V_87 :
F_32 ( V_83 -> V_2 , V_90 , 1 ) ;
break;
case V_89 :
F_32 ( V_83 -> V_2 , V_90 , 0 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
F_3 ( V_83 -> V_2 , V_91 , 0xff ) ;
return 0 ;
}
static int F_36 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
switch ( V_86 ) {
case V_92 :
F_31 ( V_83 -> V_2 , 1 ) ;
break;
case V_89 :
F_31 ( V_83 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static int F_37 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
T_1 V_93 ;
V_93 = F_1 ( V_83 -> V_2 , V_94 ) ;
switch ( V_86 ) {
case V_92 :
F_31 ( V_83 -> V_2 , 1 ) ;
F_3 ( V_83 -> V_2 , V_94 ,
V_93 | V_95 ) ;
break;
case V_89 :
F_3 ( V_83 -> V_2 , V_94 ,
V_93 & ~ V_95 ) ;
F_31 ( V_83 -> V_2 , 0 ) ;
break;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_76 )
{
unsigned char V_96 , V_97 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_40 * V_41 = V_10 -> V_41 ;
unsigned int V_98 [] = { 524288 , 1048576 , 2097152 , 4194304 ,
8388608 , 16777216 , 33554432 , 67108864 } ;
unsigned int V_99 ;
V_96 = F_1 ( V_2 , V_23 ) ;
V_97 = F_1 ( V_2 , V_68 ) ;
V_99 = ( V_98 [ ( V_97 & V_69 ) >> 2 ] /
V_10 -> V_100 ) + 1 ;
if ( V_41 && V_41 -> V_47 ) {
if ( F_21 ( V_41 -> V_48 ) ) {
F_39 ( V_41 -> V_48 , 1 ) ;
} else {
V_97 |= V_101 ;
F_3 ( V_2 , V_68 , V_97 ) ;
}
}
if ( V_76 ) {
V_97 |= V_102 ;
F_3 ( V_2 , V_68 , V_97 ) ;
F_6 ( V_26 ,
V_96 ,
V_23 ) ;
V_97 |= V_103 ;
F_3 ( V_2 , V_68 , V_97 ) ;
F_7 ( V_99 ) ;
} else {
V_97 &= ~ V_103 ;
F_3 ( V_2 , V_68 , V_97 ) ;
F_7 ( V_99 ) ;
F_6 ( V_26 ,
V_96 & ( ~ 0x0f ) ,
V_23 ) ;
V_97 &= ~ V_102 ;
F_3 ( V_2 , V_68 , V_97 ) ;
}
if ( V_41 && V_41 -> V_47 ) {
if ( F_21 ( V_41 -> V_48 ) ) {
F_39 ( V_41 -> V_48 , 0 ) ;
} else {
V_97 &= ~ V_101 ;
F_3 ( V_2 , V_68 , V_97 ) ;
}
}
}
static int F_40 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
struct V_9 * V_10 = F_4 ( V_83 -> V_2 ) ;
switch ( V_86 ) {
case V_87 :
if ( ! V_10 -> V_25 )
F_38 ( V_83 -> V_2 , 1 ) ;
V_10 -> V_24 = 1 ;
break;
case V_89 :
if ( ! V_10 -> V_25 )
F_38 ( V_83 -> V_2 , 0 ) ;
V_10 -> V_24 = 0 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
struct V_9 * V_10 = F_4 ( V_83 -> V_2 ) ;
switch ( V_86 ) {
case V_87 :
if ( ! V_10 -> V_24 )
F_38 ( V_83 -> V_2 , 1 ) ;
V_10 -> V_25 = 1 ;
break;
case V_89 :
if ( ! V_10 -> V_24 )
F_38 ( V_83 -> V_2 , 0 ) ;
V_10 -> V_25 = 0 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_82 * V_83 ,
struct V_84 * V_85 , int V_86 )
{
struct V_9 * V_10 = F_4 ( V_83 -> V_2 ) ;
struct V_40 * V_41 = V_10 -> V_41 ;
if ( V_41 && V_41 -> V_44 )
F_7 ( V_41 -> V_44 ) ;
return 0 ;
}
static int F_43 ( struct V_84 * V_85 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_85 -> V_108 ;
struct V_1 * V_2 = F_44 ( V_85 ) ;
unsigned int V_3 = V_107 -> V_3 ;
unsigned int V_109 = V_107 -> V_109 ;
unsigned int V_110 = V_107 -> V_110 ;
int V_111 = V_107 -> V_111 ;
int V_112 = ( 1 << F_45 ( V_111 ) ) - 1 ;
V_105 -> V_8 . integer . V_8 [ 0 ] =
( F_46 ( V_2 , V_3 ) >> V_109 ) & V_112 ;
if ( V_105 -> V_8 . integer . V_8 [ 0 ] )
V_105 -> V_8 . integer . V_8 [ 0 ] =
V_111 + 1 - V_105 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_109 != V_110 ) {
V_105 -> V_8 . integer . V_8 [ 1 ] =
( F_46 ( V_2 , V_3 ) >> V_110 ) & V_112 ;
if ( V_105 -> V_8 . integer . V_8 [ 1 ] )
V_105 -> V_8 . integer . V_8 [ 1 ] =
V_111 + 1 - V_105 -> V_8 . integer . V_8 [ 1 ] ;
}
return 0 ;
}
static int F_47 ( struct V_84 * V_85 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_85 -> V_108 ;
struct V_1 * V_2 = F_44 ( V_85 ) ;
unsigned int V_3 = V_107 -> V_3 ;
unsigned int V_109 = V_107 -> V_109 ;
unsigned int V_110 = V_107 -> V_110 ;
int V_111 = V_107 -> V_111 ;
int V_112 = ( 1 << F_45 ( V_111 ) ) - 1 ;
unsigned short V_34 , V_113 , V_114 ;
V_34 = ( V_105 -> V_8 . integer . V_8 [ 0 ] & V_112 ) ;
V_114 = V_112 << V_109 ;
if ( V_34 )
V_34 = V_111 + 1 - V_34 ;
V_34 = V_34 << V_109 ;
if ( V_109 != V_110 ) {
V_113 = ( V_105 -> V_8 . integer . V_8 [ 1 ] & V_112 ) ;
V_114 |= V_112 << V_110 ;
if ( V_113 )
V_113 = V_111 + 1 - V_113 ;
V_34 |= V_113 << V_110 ;
}
return F_48 ( V_2 , V_3 , V_114 , V_34 ) ;
}
static int F_49 ( struct V_84 * V_85 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_85 -> V_108 ;
struct V_1 * V_2 = F_44 ( V_85 ) ;
unsigned int V_3 = V_107 -> V_3 ;
unsigned int V_115 = V_107 -> V_116 ;
unsigned int V_109 = V_107 -> V_109 ;
int V_111 = V_107 -> V_111 ;
int V_112 = ( 1 << F_45 ( V_111 ) ) - 1 ;
V_105 -> V_8 . integer . V_8 [ 0 ] =
( F_46 ( V_2 , V_3 ) >> V_109 ) & V_112 ;
V_105 -> V_8 . integer . V_8 [ 1 ] =
( F_46 ( V_2 , V_115 ) >> V_109 ) & V_112 ;
if ( V_105 -> V_8 . integer . V_8 [ 0 ] )
V_105 -> V_8 . integer . V_8 [ 0 ] =
V_111 + 1 - V_105 -> V_8 . integer . V_8 [ 0 ] ;
if ( V_105 -> V_8 . integer . V_8 [ 1 ] )
V_105 -> V_8 . integer . V_8 [ 1 ] =
V_111 + 1 - V_105 -> V_8 . integer . V_8 [ 1 ] ;
return 0 ;
}
static int F_50 ( struct V_84 * V_85 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_85 -> V_108 ;
struct V_1 * V_2 = F_44 ( V_85 ) ;
unsigned int V_3 = V_107 -> V_3 ;
unsigned int V_115 = V_107 -> V_116 ;
unsigned int V_109 = V_107 -> V_109 ;
int V_111 = V_107 -> V_111 ;
int V_112 = ( 1 << F_45 ( V_111 ) ) - 1 ;
int V_117 ;
unsigned short V_34 , V_113 , V_114 ;
V_114 = V_112 << V_109 ;
V_34 = ( V_105 -> V_8 . integer . V_8 [ 0 ] & V_112 ) ;
V_113 = ( V_105 -> V_8 . integer . V_8 [ 1 ] & V_112 ) ;
if ( V_34 )
V_34 = V_111 + 1 - V_34 ;
if ( V_113 )
V_113 = V_111 + 1 - V_113 ;
V_34 = V_34 << V_109 ;
V_113 = V_113 << V_109 ;
V_117 = F_48 ( V_2 , V_3 , V_114 , V_34 ) ;
if ( V_117 < 0 )
return V_117 ;
V_117 = F_48 ( V_2 , V_115 , V_114 , V_113 ) ;
return V_117 ;
}
static int F_51 ( struct V_84 * V_85 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_44 ( V_85 ) ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_118 * V_119 = (struct V_118 * ) V_85 -> V_108 ;
unsigned short V_34 ;
unsigned short V_112 ;
if ( V_10 -> V_120 ) {
F_26 ( V_2 -> V_35 ,
L_16 ) ;
return - V_121 ;
}
if ( V_105 -> V_8 . V_122 . V_123 [ 0 ] > V_119 -> V_111 - 1 )
return - V_124 ;
V_34 = V_105 -> V_8 . V_122 . V_123 [ 0 ] << V_119 -> V_125 ;
V_112 = V_119 -> V_112 << V_119 -> V_125 ;
if ( V_119 -> V_125 != V_119 -> V_126 ) {
if ( V_105 -> V_8 . V_122 . V_123 [ 1 ] > V_119 -> V_111 - 1 )
return - V_124 ;
V_34 |= V_105 -> V_8 . V_122 . V_123 [ 1 ] << V_119 -> V_126 ;
V_112 |= V_119 -> V_112 << V_119 -> V_126 ;
}
return F_48 ( V_2 , V_119 -> V_3 , V_112 , V_34 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
enum V_127 V_128 )
{
switch ( V_128 ) {
case V_129 :
break;
case V_130 :
break;
case V_131 :
if ( V_2 -> V_132 . V_133 == V_134 )
F_10 ( V_2 , 1 ) ;
break;
case V_134 :
F_10 ( V_2 , 0 ) ;
break;
}
V_2 -> V_132 . V_133 = V_128 ;
return 0 ;
}
static void F_53 ( struct V_9 * V_10 ,
struct V_135 * V_136 )
{
struct V_135 * V_137 ;
if ( V_136 == V_10 -> V_138 )
V_137 = V_10 -> V_139 ;
else if ( V_136 == V_10 -> V_139 )
V_137 = V_10 -> V_138 ;
else
return;
F_54 ( V_137 -> V_140 ,
V_141 ,
V_10 -> V_142 ,
V_10 -> V_142 ) ;
F_54 ( V_137 -> V_140 ,
V_143 ,
V_10 -> V_144 ,
V_10 -> V_144 ) ;
F_54 ( V_137 -> V_140 ,
V_145 ,
V_10 -> V_146 ,
V_10 -> V_146 ) ;
}
static void F_55 ( struct V_1 * V_2 , int V_147 ,
int V_27 )
{
T_1 V_3 , V_112 ;
V_3 = F_1 ( V_2 , V_38 ) ;
if ( V_147 == V_148 )
V_112 = V_149 | V_150 ;
else
V_112 = V_151 | V_152 ;
if ( V_27 )
V_3 |= V_112 ;
else
V_3 &= ~ V_112 ;
F_3 ( V_2 , V_38 , V_3 ) ;
}
static int F_56 ( struct V_135 * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_138 ) {
V_10 -> V_139 = V_153 ;
if ( V_10 -> V_120 )
F_53 ( V_10 , V_10 -> V_138 ) ;
} else {
if ( ! ( F_1 ( V_2 , V_31 ) &
V_156 ) ) {
F_54 ( V_153 -> V_140 ,
V_145 ,
2 , 2 ) ;
}
V_10 -> V_138 = V_153 ;
}
return 0 ;
}
static void F_57 ( struct V_135 * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_10 -> V_138 == V_153 )
V_10 -> V_138 = V_10 -> V_139 ;
V_10 -> V_139 = NULL ;
if ( ! V_10 -> V_138 )
V_10 -> V_120 = 0 ;
else if ( ! V_10 -> V_138 -> V_140 -> V_146 )
V_10 -> V_120 = 0 ;
if ( V_153 -> V_140 -> V_146 == 4 )
F_55 ( V_2 , V_153 -> V_157 , 0 ) ;
}
static int F_58 ( struct V_135 * V_153 ,
struct V_158 * V_159 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_28 , V_160 , V_161 , V_162 ;
if ( F_59 ( V_159 ) == 4 ) {
V_161 = F_1 ( V_2 , V_94 ) ;
V_28 = F_1 ( V_2 , V_31 ) ;
if ( ( V_28 & V_156 ) &&
( ( V_161 & V_163 ) == V_164 ) )
F_55 ( V_2 , V_153 -> V_157 , 1 ) ;
else
return - V_124 ;
}
if ( V_10 -> V_120 )
return 0 ;
V_160 = F_1 ( V_2 ,
V_31 ) & ~ V_165 ;
V_28 = V_160 & ~ V_166 ;
switch ( F_60 ( V_159 ) ) {
case 8000 :
V_28 |= V_167 ;
break;
case 11025 :
V_28 |= V_168 ;
break;
case 12000 :
V_28 |= V_169 ;
break;
case 16000 :
V_28 |= V_170 ;
break;
case 22050 :
V_28 |= V_171 ;
break;
case 24000 :
V_28 |= V_172 ;
break;
case 32000 :
V_28 |= V_173 ;
break;
case 44100 :
V_28 |= V_174 ;
break;
case 48000 :
V_28 |= V_175 ;
break;
case 96000 :
V_28 |= V_176 ;
break;
default:
F_26 ( V_2 -> V_35 , L_17 , V_177 ,
F_60 ( V_159 ) ) ;
return - V_124 ;
}
V_162 = F_1 ( V_2 , V_94 ) ;
V_161 = V_162 ;
V_161 &= ~ V_178 ;
switch ( F_61 ( V_159 ) ) {
case V_179 :
V_161 |= V_180 ;
break;
case V_181 :
V_161 |= V_182 ;
break;
default:
F_26 ( V_2 -> V_35 , L_18 , V_177 ,
F_61 ( V_159 ) ) ;
return - V_124 ;
}
if ( V_161 != V_162 || V_28 != V_160 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_31 , V_28 ) ;
F_3 ( V_2 , V_94 , V_161 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_31 , V_28 ) ;
F_3 ( V_2 , V_94 , V_161 ) ;
}
}
V_10 -> V_120 = 1 ;
V_10 -> V_142 = F_60 ( V_159 ) ;
V_10 -> V_144 = F_62 ( V_159 ,
V_143 ) -> V_183 ;
V_10 -> V_146 = F_59 ( V_159 ) ;
if ( V_10 -> V_139 )
F_53 ( V_10 , V_153 ) ;
return 0 ;
}
static int F_63 ( struct V_154 * V_184 ,
int V_185 , unsigned int V_186 , int V_187 )
{
struct V_1 * V_2 = V_184 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
switch ( V_186 ) {
case 19200000 :
case 26000000 :
case 38400000 :
break;
default:
F_26 ( V_2 -> V_35 , L_19 , V_186 ) ;
return - V_124 ;
}
if ( ( V_186 / 1000 ) != V_10 -> V_100 ) {
F_26 ( V_2 -> V_35 ,
L_20 ,
V_186 , V_10 -> V_100 * 1000 ) ;
return - V_124 ;
}
return 0 ;
}
static int F_64 ( struct V_154 * V_184 ,
unsigned int V_188 )
{
struct V_1 * V_2 = V_184 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_162 , V_161 ;
V_162 = F_1 ( V_2 , V_94 ) ;
V_161 = V_162 ;
switch ( V_188 & V_189 ) {
case V_190 :
V_161 &= ~ ( V_191 ) ;
V_161 &= ~ ( V_192 ) ;
break;
case V_193 :
V_161 |= V_191 ;
V_161 |= V_192 ;
break;
default:
return - V_124 ;
}
V_161 &= ~ V_163 ;
switch ( V_188 & V_194 ) {
case V_195 :
V_161 |= V_196 ;
break;
case V_197 :
V_161 |= V_164 ;
break;
default:
return - V_124 ;
}
if ( V_161 != V_162 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_94 , V_161 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_94 , V_161 ) ;
}
}
return 0 ;
}
static int F_65 ( struct V_154 * V_155 , int V_198 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_94 ) ;
if ( V_198 )
V_3 |= V_199 ;
else
V_3 &= ~ V_199 ;
return F_3 ( V_2 , V_94 , V_3 ) ;
}
static void F_66 ( struct V_1 * V_2 , int V_147 ,
int V_27 )
{
T_1 V_3 , V_112 ;
V_3 = F_1 ( V_2 , V_38 ) ;
if ( V_147 == V_148 )
V_112 = V_149 ;
else
V_112 = V_151 | V_152 ;
if ( V_27 )
V_3 |= V_112 ;
else
V_3 &= ~ V_112 ;
F_3 ( V_2 , V_38 , V_3 ) ;
}
static int F_67 ( struct V_135 * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_28 ;
if ( V_10 -> V_100 != 26000 ) {
F_26 ( V_2 -> V_35 ,
L_21 ,
V_177 , V_10 -> V_100 ) ;
return - V_124 ;
}
V_28 = F_1 ( V_2 , V_31 )
& V_200 ;
if ( V_28 != V_201 ) {
F_26 ( V_2 -> V_35 , L_22 ,
V_177 ) ;
return - V_124 ;
}
return 0 ;
}
static void F_68 ( struct V_135 * V_153 ,
struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
F_66 ( V_2 , V_153 -> V_157 , 0 ) ;
}
static int F_69 ( struct V_135 * V_153 ,
struct V_158 * V_159 , struct V_154 * V_155 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_160 , V_28 ;
F_66 ( V_2 , V_153 -> V_157 , 1 ) ;
V_160 = F_1 ( V_2 , V_31 )
& ~ ( V_165 ) ;
V_28 = V_160 ;
switch ( F_60 ( V_159 ) ) {
case 8000 :
V_28 &= ~ ( V_202 ) ;
break;
case 16000 :
V_28 |= V_202 ;
break;
default:
F_26 ( V_2 -> V_35 , L_17 , V_177 ,
F_60 ( V_159 ) ) ;
return - V_124 ;
}
if ( V_28 != V_160 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_31 , V_28 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_31 , V_28 ) ;
}
}
return 0 ;
}
static int F_70 ( struct V_154 * V_184 ,
int V_185 , unsigned int V_186 , int V_187 )
{
struct V_1 * V_2 = V_184 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
if ( V_186 != 26000000 ) {
F_26 ( V_2 -> V_35 ,
L_21 ,
V_177 , V_186 / 1000 ) ;
return - V_124 ;
}
if ( ( V_186 / 1000 ) != V_10 -> V_100 ) {
F_26 ( V_2 -> V_35 ,
L_20 ,
V_186 , V_10 -> V_100 * 1000 ) ;
return - V_124 ;
}
return 0 ;
}
static int F_71 ( struct V_154 * V_184 ,
unsigned int V_188 )
{
struct V_1 * V_2 = V_184 -> V_2 ;
struct V_9 * V_10 = F_4 ( V_2 ) ;
T_1 V_162 , V_161 ;
V_162 = F_1 ( V_2 , V_203 ) ;
V_161 = V_162 ;
switch ( V_188 & V_189 ) {
case V_190 :
V_161 &= ~ ( V_204 ) ;
break;
case V_193 :
V_161 |= V_204 ;
break;
default:
return - V_124 ;
}
switch ( V_188 & V_205 ) {
case V_206 :
V_161 &= ~ ( V_207 ) ;
break;
case V_208 :
V_161 |= V_207 ;
break;
default:
return - V_124 ;
}
if ( V_161 != V_162 ) {
if ( V_10 -> V_29 ) {
F_10 ( V_2 , 0 ) ;
F_3 ( V_2 , V_203 , V_161 ) ;
F_10 ( V_2 , 1 ) ;
} else {
F_3 ( V_2 , V_203 , V_161 ) ;
}
}
return 0 ;
}
static int F_72 ( struct V_154 * V_155 , int V_198 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_203 ) ;
if ( V_198 )
V_3 |= V_209 ;
else
V_3 &= ~ V_209 ;
return F_3 ( V_2 , V_203 , V_3 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_25 ( V_2 -> V_35 , sizeof( struct V_9 ) ,
V_52 ) ;
if ( V_10 == NULL ) {
F_26 ( V_2 -> V_35 , L_12 ) ;
return - V_210 ;
}
F_74 ( V_2 , V_10 ) ;
V_10 -> V_100 = F_75 () / 1000 ;
F_27 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_4 ( V_2 ) ;
struct V_40 * V_41 = V_10 -> V_41 ;
F_17 ( V_2 ) ;
F_52 ( V_2 , V_134 ) ;
if ( V_41 && V_41 -> V_47 && F_21 ( V_41 -> V_48 ) )
F_77 ( V_41 -> V_48 ) ;
return 0 ;
}
static int F_78 ( struct V_211 * V_212 )
{
return F_79 ( & V_212 -> V_35 , & V_213 ,
V_214 , F_80 ( V_214 ) ) ;
}
static int F_81 ( struct V_211 * V_212 )
{
F_82 ( & V_212 -> V_35 ) ;
return 0 ;
}
