static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
V_4 = F_2 ( V_3 ) -> V_5 ;
return (struct V_1 * ) V_4 ;
}
static inline void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
T_1 V_12 ;
T_1 V_13 ;
V_13 = ( V_9 -> V_14 * V_11 -> V_9 . V_15 ) & 0x1f ;
V_12 = ( V_11 -> V_9 . V_16 - V_11 -> V_9 . V_17 )
* V_11 -> V_9 . V_15 / 8 ;
V_12 |= V_13 << V_18 ;
F_4 ( V_7 , V_19 , V_12 ) ;
F_4 ( V_7 , V_20 ,
F_5 ( V_7 , V_20 )
| V_21 ) ;
}
static int F_6 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = F_7 ( V_23 ) ;
int V_24 = V_7 -> V_25 ;
int V_26 = V_23 -> V_27 . V_26 ;
if ( V_23 -> V_27 . V_28 != V_7 -> V_25 )
V_24 = V_23 -> V_27 . V_28 ;
else if ( V_23 -> V_27 . V_24 != V_7 -> V_25 )
V_24 = V_23 -> V_27 . V_24 ;
if ( V_26 < 0 && V_24 == V_29 )
V_26 = F_5 ( V_7 , V_30 ) ;
else if ( V_24 != V_29 )
V_26 = 0 ;
F_4 ( V_7 , V_30 , V_26 ) ;
if ( V_31 & V_32 )
F_4 ( V_7 , V_33 ,
V_26 ? V_31 : 0 ) ;
else
F_4 ( V_7 , V_33 , V_31 ) ;
V_23 -> V_27 . V_28 = V_23 -> V_27 . V_24 = V_7 -> V_25 = V_24 ;
return 0 ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = F_7 ( V_23 ) ;
return F_5 ( V_7 , V_30 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_34 V_27 ;
struct V_22 * V_23 ;
V_7 -> V_25 = V_29 ;
if ( V_7 -> V_35 )
return;
memset ( & V_27 , 0 , sizeof( struct V_34 ) ) ;
V_27 . type = V_36 ;
V_27 . V_37 = 0xff ;
V_23 = F_10 ( L_1 , & V_7 -> V_3 -> V_38 , V_7 ,
& V_39 , & V_27 ) ;
if ( F_11 ( V_23 ) ) {
F_12 ( & V_7 -> V_3 -> V_38 , L_2 ,
F_13 ( V_23 ) ) ;
return;
}
V_7 -> V_35 = V_23 ;
V_23 -> V_27 . V_24 = V_29 ;
V_23 -> V_27 . V_28 = V_29 ;
V_23 -> V_27 . V_26 = F_8 ( V_23 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_35 )
return;
if ( V_7 -> V_35 -> V_40 ) {
V_7 -> V_35 -> V_27 . V_24 = V_41 ;
V_7 -> V_35 -> V_40 -> V_42 ( V_7 -> V_35 ) ;
}
F_15 ( V_7 -> V_35 ) ;
}
static void F_9 ( struct V_6 * V_7 )
{
F_16 ( & V_7 -> V_3 -> V_38 , L_3 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = & V_7 -> V_44 ;
if ( V_44 -> V_45 )
V_31 &= ~ ( V_32 ) ;
F_4 ( V_7 , V_33 , V_31 ) ;
F_4 ( V_7 , V_30 , V_46 ) ;
if ( V_44 -> V_47 )
F_9 ( V_7 ) ;
}
static inline void F_18 ( struct V_6 * V_7 , int V_48 )
{
int V_49 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
if ( V_44 -> F_18 )
V_44 -> F_18 ( V_44 , V_48 ) ;
else if ( V_7 -> V_50 ) {
if ( V_48 ) {
V_49 = F_19 ( V_7 -> V_50 ) ;
if ( V_49 )
F_12 ( & V_7 -> V_3 -> V_38 ,
L_4 , V_49 ) ;
} else {
V_49 = F_20 ( V_7 -> V_50 ) ;
if ( V_49 )
F_12 ( & V_7 -> V_3 -> V_38 ,
L_5 , V_49 ) ;
}
}
}
static unsigned long F_21 ( struct V_6 * V_7 ,
unsigned long V_17 )
{
unsigned long V_51 ;
unsigned long V_52 ;
if ( ! V_7 -> V_53 -> V_54 )
return V_17 ;
V_51 = F_5 ( V_7 , V_55 ) ;
V_52 = V_17 ;
if ( ( V_51 & V_56 ) != V_57 ) {
if ( ( V_51 & V_56 ) == V_58 ) {
V_52 *= 3 ;
}
if ( ( V_51 & V_59 ) == V_60
|| ( ( V_51 & V_59 ) == V_61
&& ( V_51 & V_62 ) == V_63 ) )
V_52 = F_22 ( V_52 , 4 ) ;
else
V_52 = F_22 ( V_52 , 8 ) ;
}
return V_52 ;
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = & V_7 -> V_44 ;
F_4 ( V_7 , V_64 ,
V_44 -> V_65 << V_66 ) ;
while ( F_5 ( V_7 , V_64 ) & V_67 )
F_24 ( 10 ) ;
F_4 ( V_7 , V_20 , 0 ) ;
}
static void F_25 ( struct V_6 * V_7 )
{
F_23 ( V_7 ) ;
while ( F_5 ( V_7 , V_20 ) & V_68 )
F_24 ( 10 ) ;
}
static void F_26 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = & V_7 -> V_44 ;
F_4 ( V_7 , V_20 , V_44 -> V_69 ) ;
F_4 ( V_7 , V_64 ,
( V_44 -> V_65 << V_66 )
| V_70 ) ;
}
static void F_27 ( struct V_10 * V_11 ,
struct V_8 * V_9 )
{
struct V_6 * V_7 = V_11 -> V_71 ;
struct V_72 * V_73 = & V_11 -> V_73 ;
unsigned long V_74 ;
V_74 = ( V_73 -> V_75 + V_9 -> V_76 * V_73 -> V_77
+ V_9 -> V_14 * V_11 -> V_9 . V_15 / 8 ) ;
V_74 &= ~ 3UL ;
F_4 ( V_7 , V_78 , V_74 ) ;
F_3 ( V_7 , V_9 , V_11 ) ;
}
static inline void F_28 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
F_29 ( V_11 -> V_79 , V_11 -> V_73 . V_80 ,
V_11 -> V_81 , V_11 -> V_73 . V_75 ) ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_8 * V_9 = & V_11 -> V_9 ;
unsigned int V_80 ;
V_80 = ( V_9 -> V_16 * V_9 -> V_82
* ( ( V_9 -> V_15 + 7 ) / 8 ) ) ;
V_11 -> V_73 . V_80 = F_31 ( V_80 , V_7 -> V_80 ) ;
V_11 -> V_81 = F_32 ( V_11 -> V_79 , V_11 -> V_73 . V_80 ,
( V_83 * ) & V_11 -> V_73 . V_75 , V_84 ) ;
if ( ! V_11 -> V_81 ) {
return - V_85 ;
}
memset ( V_11 -> V_81 , 0 , V_11 -> V_73 . V_80 ) ;
return 0 ;
}
static const struct V_86 * F_33 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_86 V_87 ;
const struct V_86 * V_88 = NULL ;
F_34 ( & V_87 , V_9 ) ;
V_88 = F_35 ( & V_87 , & V_11 -> V_89 ) ;
if ( V_88 )
F_36 ( V_9 , V_88 ) ;
return V_88 ;
}
static int F_37 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_79 * V_38 = V_11 -> V_79 ;
struct V_6 * V_7 = V_11 -> V_71 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
unsigned long V_90 ;
V_90 = F_38 ( V_7 -> V_91 ) / 1000 ;
F_39 ( V_38 , L_6 , V_92 ) ;
if ( ! ( V_9 -> V_93 && V_9 -> V_15 ) ) {
if ( ! F_33 ( V_9 , V_11 ) ) {
F_12 ( V_38 , L_7 ) ;
return - V_94 ;
}
}
F_39 ( V_38 , L_8 , V_9 -> V_17 , V_9 -> V_95 ) ;
F_39 ( V_38 , L_9 , F_40 ( V_9 -> V_93 ) ) ;
F_39 ( V_38 , L_10 , V_9 -> V_15 ) ;
F_39 ( V_38 , L_11 , V_90 ) ;
if ( F_40 ( V_9 -> V_93 ) > V_90 ) {
F_12 ( V_38 , L_12 , F_40 ( V_9 -> V_93 ) ) ;
return - V_94 ;
}
if ( V_9 -> V_17 > V_9 -> V_16 )
V_9 -> V_16 = V_9 -> V_17 ;
if ( V_9 -> V_95 > V_9 -> V_82 )
V_9 -> V_82 = V_9 -> V_95 ;
V_9 -> V_17 = ( V_9 -> V_17 + 3 ) & ~ 3UL ;
V_9 -> V_16 = ( V_9 -> V_16 + 3 ) & ~ 3UL ;
V_9 -> V_96 . V_97 = V_9 -> V_98 . V_97 = V_9 -> V_99 . V_97 = 0 ;
V_9 -> V_100 . V_97 = 0 ;
V_9 -> V_100 . V_101 = V_9 -> V_100 . V_102 = 0 ;
V_9 -> V_14 = V_9 -> V_76 = 0 ;
if ( V_11 -> V_73 . V_80 ) {
unsigned int V_80 = ( V_9 -> V_16 * V_9 -> V_82
* ( ( V_9 -> V_15 + 7 ) / 8 ) ) ;
if ( V_80 > V_11 -> V_73 . V_80 ) {
F_12 ( V_38 , L_13 ,
V_11 -> V_73 . V_80 , V_80 ) ;
return - V_94 ;
}
}
V_9 -> V_103 = F_41 ( T_1 , V_9 -> V_103 ,
( V_104 >> V_105 ) + 1 ) ;
V_9 -> V_106 = F_41 ( T_1 , V_9 -> V_106 ,
V_107 >> V_108 ) ;
V_9 -> V_109 = F_41 ( T_1 , V_9 -> V_109 ,
V_110 ) ;
V_9 -> V_111 = F_41 ( T_1 , V_9 -> V_111 ,
( V_112 >> V_113 ) + 1 ) ;
V_9 -> V_114 = F_41 ( T_1 , V_9 -> V_114 ,
( V_115 >> V_116 ) + 1 ) ;
V_9 -> V_117 = F_41 ( T_1 , V_9 -> V_117 ,
V_118 + 1 ) ;
V_9 -> V_103 = F_42 ( T_1 , V_9 -> V_103 , 1 ) ;
V_9 -> V_111 = F_42 ( T_1 , V_9 -> V_111 , 1 ) ;
V_9 -> V_114 = F_42 ( T_1 , V_9 -> V_114 , 1 ) ;
V_9 -> V_117 = F_42 ( T_1 , V_9 -> V_117 , 1 ) ;
switch ( V_9 -> V_15 ) {
case 1 :
case 2 :
case 4 :
case 8 :
V_9 -> V_96 . V_101 = V_9 -> V_98 . V_101 = V_9 -> V_99 . V_101 = 0 ;
V_9 -> V_96 . V_102 = V_9 -> V_98 . V_102 = V_9 -> V_99 . V_102
= V_9 -> V_15 ;
break;
case 16 :
if ( V_7 -> V_53 -> V_119 )
V_9 -> V_98 . V_102 = 5 ;
else
V_9 -> V_98 . V_102 = 6 ;
if ( V_44 -> V_120 == V_121 ) {
V_9 -> V_96 . V_101 = V_9 -> V_98 . V_102 + 5 ;
V_9 -> V_99 . V_101 = 0 ;
} else {
V_9 -> V_96 . V_101 = 0 ;
V_9 -> V_99 . V_101 = V_9 -> V_98 . V_102 + 5 ;
}
V_9 -> V_98 . V_101 = 5 ;
V_9 -> V_96 . V_102 = V_9 -> V_99 . V_102 = 5 ;
break;
case 32 :
V_9 -> V_100 . V_101 = 24 ;
V_9 -> V_100 . V_102 = 8 ;
case 24 :
if ( V_44 -> V_120 == V_121 ) {
V_9 -> V_96 . V_101 = 16 ;
V_9 -> V_99 . V_101 = 0 ;
} else {
V_9 -> V_96 . V_101 = 0 ;
V_9 -> V_99 . V_101 = 16 ;
}
V_9 -> V_98 . V_101 = 8 ;
V_9 -> V_96 . V_102 = V_9 -> V_98 . V_102 = V_9 -> V_99 . V_102 = 8 ;
break;
default:
F_12 ( V_38 , L_14 ,
V_9 -> V_15 ) ;
return - V_94 ;
}
return 0 ;
}
static void F_43 ( struct V_6 * V_7 )
{
F_44 () ;
F_25 ( V_7 ) ;
F_26 ( V_7 ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_71 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
unsigned long V_122 ;
unsigned long V_52 ;
unsigned long V_90 ;
unsigned long V_123 ;
unsigned long V_124 = 2 ;
F_44 () ;
F_39 ( V_11 -> V_79 , L_6 , V_92 ) ;
F_39 ( V_11 -> V_79 , L_15 ,
V_11 -> V_9 . V_17 , V_11 -> V_9 . V_95 ,
V_11 -> V_9 . V_16 , V_11 -> V_9 . V_82 ) ;
F_23 ( V_7 ) ;
if ( V_11 -> V_9 . V_15 == 1 )
V_11 -> V_73 . V_125 = V_126 ;
else if ( V_11 -> V_9 . V_15 <= 8 )
V_11 -> V_73 . V_125 = V_127 ;
else
V_11 -> V_73 . V_125 = V_128 ;
V_123 = V_11 -> V_9 . V_16 * V_11 -> V_9 . V_15 ;
V_11 -> V_73 . V_77 = F_22 ( V_123 , 8 ) ;
F_39 ( V_11 -> V_79 , L_16 ) ;
F_27 ( V_11 , & V_11 -> V_9 ) ;
V_52 = ( V_11 -> V_9 . V_95 * V_11 -> V_9 . V_17 * V_11 -> V_9 . V_15 ) / 32 ;
V_52 |= ( ( V_129 - 1 ) << V_130 ) ;
F_4 ( V_7 , V_131 , V_52 ) ;
if ( V_7 -> V_53 -> V_132 )
V_124 = 1 ;
V_90 = F_38 ( V_7 -> V_91 ) / 1000 ;
V_52 = F_22 ( V_90 , F_40 ( V_11 -> V_9 . V_93 ) ) ;
if ( V_52 < V_124 ) {
F_46 ( V_11 -> V_79 , L_17 ) ;
F_4 ( V_7 , V_133 , V_134 ) ;
} else {
V_52 = ( V_52 / V_124 ) - 1 ;
F_39 ( V_11 -> V_79 , L_18 ,
V_52 ) ;
F_4 ( V_7 , V_133 ,
V_52 << V_135 ) ;
V_11 -> V_9 . V_93 =
F_47 ( V_90 / ( V_124 * ( V_52 + 1 ) ) ) ;
F_39 ( V_11 -> V_79 , L_19 ,
F_40 ( V_11 -> V_9 . V_93 ) ) ;
}
V_52 = V_44 -> V_136 ;
if ( ! ( V_11 -> V_9 . V_137 & V_138 ) )
V_52 |= V_139 ;
if ( ! ( V_11 -> V_9 . V_137 & V_140 ) )
V_52 |= V_141 ;
switch ( V_11 -> V_9 . V_15 ) {
case 1 : V_52 |= V_142 ; break;
case 2 : V_52 |= V_143 ; break;
case 4 : V_52 |= V_144 ; break;
case 8 : V_52 |= V_145 ; break;
case 15 :
case 16 : V_52 |= V_146 ; break;
case 24 : V_52 |= V_147 ; break;
case 32 : V_52 |= V_148 ; break;
default: F_48 () ; break;
}
F_39 ( V_11 -> V_79 , L_20 , V_52 ) ;
F_4 ( V_7 , V_55 , V_52 ) ;
V_52 = ( V_11 -> V_9 . V_103 - 1 ) << V_105 ;
V_52 |= V_11 -> V_9 . V_106 << V_108 ;
V_52 |= V_11 -> V_9 . V_109 ;
F_39 ( V_11 -> V_79 , L_21 , V_52 ) ;
F_4 ( V_7 , V_149 , V_52 ) ;
V_52 = ( V_11 -> V_9 . V_111 - 1 ) << V_113 ;
V_52 |= ( V_11 -> V_9 . V_114 - 1 ) << V_116 ;
V_52 |= ( V_11 -> V_9 . V_117 - 1 ) ;
F_39 ( V_11 -> V_79 , L_22 , V_52 ) ;
F_4 ( V_7 , V_150 , V_52 ) ;
V_122 = F_21 ( V_7 , V_11 -> V_9 . V_17 ) ;
V_52 = ( V_122 - 1 ) << V_151 ;
V_52 |= V_11 -> V_9 . V_95 - 1 ;
F_39 ( V_11 -> V_79 , L_23 , V_52 ) ;
F_4 ( V_7 , V_152 , V_52 ) ;
V_52 = V_153 - ( 2 * V_129 + 3 ) ;
F_4 ( V_7 , V_154 , V_52 ) ;
F_4 ( V_7 , V_155 , 0 ) ;
F_4 ( V_7 , V_156 , ~ 0UL ) ;
F_4 ( V_7 , V_157 , V_158 | V_159 | V_160 ) ;
while ( F_5 ( V_7 , V_20 ) & V_68 )
F_24 ( 10 ) ;
F_26 ( V_7 ) ;
F_39 ( V_11 -> V_79 , L_24 ) ;
return 0 ;
}
static inline unsigned int F_49 ( unsigned int V_161 , const struct V_162 * V_163 )
{
V_161 &= 0xffff ;
V_161 >>= 16 - V_163 -> V_102 ;
return V_161 << V_163 -> V_101 ;
}
static int F_50 ( unsigned int V_164 , unsigned int V_96 ,
unsigned int V_98 , unsigned int V_99 ,
unsigned int V_100 , struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_71 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
unsigned int V_165 ;
T_1 * V_166 ;
int V_49 = 1 ;
if ( V_11 -> V_9 . V_167 )
V_96 = V_98 = V_99 = ( 19595 * V_96 + 38470 * V_98
+ 7471 * V_99 ) >> 16 ;
switch ( V_11 -> V_73 . V_125 ) {
case V_128 :
if ( V_164 < 16 ) {
V_166 = V_11 -> V_168 ;
V_165 = F_49 ( V_96 , & V_11 -> V_9 . V_96 ) ;
V_165 |= F_49 ( V_98 , & V_11 -> V_9 . V_98 ) ;
V_165 |= F_49 ( V_99 , & V_11 -> V_9 . V_99 ) ;
V_166 [ V_164 ] = V_165 ;
V_49 = 0 ;
}
break;
case V_127 :
if ( V_164 < 256 ) {
if ( V_7 -> V_53 -> V_119 ) {
V_165 = ( ( V_96 >> 11 ) & 0x001f ) ;
V_165 |= ( ( V_98 >> 6 ) & 0x03e0 ) ;
V_165 |= ( ( V_99 >> 1 ) & 0x7c00 ) ;
} else {
if ( V_44 -> V_120 == V_121 ) {
V_165 = ( ( V_99 >> 11 ) & 0x001f ) ;
V_165 |= ( ( V_96 >> 0 ) & 0xf800 ) ;
} else {
V_165 = ( ( V_96 >> 11 ) & 0x001f ) ;
V_165 |= ( ( V_99 >> 0 ) & 0xf800 ) ;
}
V_165 |= ( ( V_98 >> 5 ) & 0x07e0 ) ;
}
F_4 ( V_7 , F_51 ( V_164 ) , V_165 ) ;
V_49 = 0 ;
}
break;
case V_126 :
if ( V_164 < 2 ) {
V_165 = ( V_164 == 0 ) ? 0x00 : 0x1F ;
F_4 ( V_7 , F_51 ( V_164 ) , V_165 ) ;
V_49 = 0 ;
}
break;
}
return V_49 ;
}
static int F_52 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
F_39 ( V_11 -> V_79 , L_25 , V_92 ) ;
F_27 ( V_11 , V_9 ) ;
return 0 ;
}
static int F_53 ( int V_169 , struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_71 ;
switch ( V_169 ) {
case V_29 :
case V_170 :
F_26 ( V_7 ) ;
break;
case V_171 :
case V_172 :
break;
case V_41 :
F_25 ( V_7 ) ;
break;
default:
return - V_94 ;
}
return ( ( V_169 == V_170 ) ? 1 : 0 ) ;
}
static T_2 F_54 ( int V_173 , void * V_174 )
{
struct V_10 * V_11 = V_174 ;
struct V_6 * V_7 = V_11 -> V_71 ;
T_1 V_175 ;
V_175 = F_5 ( V_7 , V_176 ) ;
if ( V_175 & V_158 ) {
F_16 ( V_11 -> V_79 , L_26 , V_175 ) ;
F_55 ( & V_7 -> V_177 ) ;
}
F_4 ( V_7 , V_178 , V_175 ) ;
return V_179 ;
}
static void F_56 ( struct V_180 * V_181 )
{
struct V_6 * V_7 =
F_57 ( V_181 , struct V_6 , V_177 ) ;
F_43 ( V_7 ) ;
}
static int T_3 F_58 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_49 = 0 ;
V_11 -> V_9 . V_182 |= V_183 | V_184 ;
F_59 ( V_11 -> V_79 ,
L_27 ,
( unsigned long ) V_11 -> V_73 . V_80 / 1024 ,
( unsigned long ) V_11 -> V_73 . V_75 ,
V_11 -> V_81 ) ;
V_49 = F_60 ( & V_11 -> V_185 , 256 , 0 ) ;
if ( V_49 < 0 )
F_12 ( V_11 -> V_79 , L_28 ) ;
return V_49 ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_62 ( V_7 -> V_186 ) ;
F_62 ( V_7 -> V_91 ) ;
}
static void F_63 ( struct V_6 * V_7 )
{
F_64 ( V_7 -> V_186 ) ;
F_64 ( V_7 -> V_91 ) ;
}
const int F_65 ( struct V_187 * V_188 )
{
const char * V_189 ;
int V_190 , V_191 ;
V_190 = F_66 ( V_188 , L_29 , & V_189 ) ;
if ( V_190 < 0 )
return V_192 ;
for ( V_191 = 0 ; V_191 < F_67 ( V_193 ) ; V_191 ++ )
if ( ! strcasecmp ( V_189 , V_193 [ V_191 ] ) )
return V_191 ;
return - V_194 ;
}
static void F_68 ( struct V_43 * V_44 , int V_48 )
{
struct V_195 * V_196 ;
F_69 (og, &pdata->pwr_gpios, list)
F_70 ( V_196 -> V_197 , V_48 ) ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
struct V_8 * V_9 = & V_11 -> V_9 ;
struct V_79 * V_38 = & V_7 -> V_3 -> V_38 ;
struct V_187 * V_188 = V_38 -> V_198 ;
struct V_187 * V_199 ;
struct V_187 * V_200 ;
struct V_201 * V_202 ;
enum V_203 V_204 ;
struct V_195 * V_196 ;
bool V_205 = false ;
int V_49 = - V_206 ;
int V_191 , V_197 ;
V_7 -> V_53 = (struct V_1 * )
F_72 ( V_207 , V_38 ) -> V_4 ;
V_199 = F_73 ( V_188 , L_30 , 0 ) ;
if ( ! V_199 ) {
F_12 ( V_38 , L_31 ) ;
return - V_206 ;
}
V_49 = F_74 ( V_199 , L_32 , & V_9 -> V_15 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_33 ) ;
goto V_208;
}
V_49 = F_74 ( V_199 , L_34 , & V_44 -> V_65 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_35 ) ;
goto V_208;
}
V_49 = F_74 ( V_199 , L_36 , & V_44 -> V_136 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_37 ) ;
goto V_208;
}
V_49 = F_74 ( V_199 , L_38 , & V_44 -> V_69 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_33 ) ;
goto V_208;
}
F_75 ( & V_44 -> V_209 ) ;
V_49 = - V_85 ;
for ( V_191 = 0 ; V_191 < F_76 ( V_199 , L_39 ) ; V_191 ++ ) {
V_197 = F_77 ( V_199 , L_39 ,
V_191 , & V_204 ) ;
if ( V_197 < 0 )
continue;
V_196 = F_78 ( V_38 , sizeof( * V_196 ) , V_84 ) ;
if ( ! V_196 )
goto V_208;
V_196 -> V_197 = V_197 ;
V_196 -> V_210 = V_204 & V_211 ;
V_205 = true ;
V_49 = F_79 ( V_38 , V_197 , L_40 ) ;
if ( V_49 ) {
F_12 ( V_38 , L_41 , V_197 ) ;
goto V_208;
}
V_49 = F_80 ( V_197 , V_196 -> V_210 ) ;
if ( V_49 ) {
F_12 ( V_38 , L_42 , V_197 ) ;
goto V_208;
}
F_81 ( & V_196 -> V_212 , & V_44 -> V_209 ) ;
}
if ( V_205 )
V_44 -> F_18 = F_68 ;
V_49 = F_65 ( V_199 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_43 ) ;
goto V_208;
}
V_44 -> V_120 = V_49 ;
V_44 -> V_47 = F_82 ( V_199 , L_44 ) ;
V_44 -> V_45 = F_82 ( V_199 , L_45 ) ;
V_202 = F_83 ( V_199 ) ;
if ( ! V_202 ) {
F_12 ( V_38 , L_46 ) ;
V_49 = - V_94 ;
goto V_208;
}
V_200 = F_84 ( V_199 , L_47 ) ;
if ( ! V_200 ) {
F_12 ( V_38 , L_48 ) ;
V_49 = - V_194 ;
goto V_208;
}
for ( V_191 = 0 ; V_191 < F_85 ( V_200 ) ; V_191 ++ ) {
struct V_213 V_214 ;
struct V_86 V_215 ;
V_49 = F_86 ( V_202 , & V_214 , V_191 ) ;
if ( V_49 < 0 )
goto V_216;
V_49 = F_87 ( & V_214 , & V_215 ) ;
if ( V_49 < 0 )
goto V_216;
F_88 ( & V_215 , & V_11 -> V_89 ) ;
}
return 0 ;
V_216:
F_89 ( V_200 ) ;
V_208:
F_89 ( V_199 ) ;
return V_49 ;
}
static int F_71 ( struct V_6 * V_7 )
{
return 0 ;
}
static int T_3 F_90 ( struct V_2 * V_3 )
{
struct V_79 * V_38 = & V_3 -> V_38 ;
struct V_10 * V_11 ;
struct V_6 * V_7 ;
struct V_43 * V_44 = NULL ;
struct V_217 * V_218 = NULL ;
struct V_217 * V_219 = NULL ;
struct V_220 * V_89 ;
int V_49 ;
F_39 ( V_38 , L_49 , V_92 ) ;
V_49 = - V_85 ;
V_11 = F_91 ( sizeof( struct V_6 ) , V_38 ) ;
if ( ! V_11 ) {
F_12 ( V_38 , L_50 ) ;
goto V_221;
}
V_7 = V_11 -> V_71 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_11 = V_11 ;
F_75 ( & V_11 -> V_89 ) ;
if ( V_3 -> V_38 . V_198 ) {
V_49 = F_71 ( V_7 ) ;
if ( V_49 )
goto V_222;
} else if ( F_92 ( V_38 ) ) {
struct V_223 * V_224 ;
int V_191 ;
V_44 = F_92 ( V_38 ) ;
V_224 = V_44 -> V_225 ;
V_7 -> V_44 = * V_44 ;
for ( V_191 = 0 ; V_191 < V_224 -> V_226 ; V_191 ++ )
F_88 ( & V_224 -> V_227 [ V_191 ] , & V_11 -> V_89 ) ;
V_7 -> V_53 = F_1 ( V_3 ) ;
V_11 -> V_9 . V_15 = V_44 -> V_228 ? V_44 -> V_228 : 16 ;
memcpy ( & V_11 -> V_224 , V_44 -> V_225 , sizeof( V_11 -> V_224 ) ) ;
} else {
F_12 ( V_38 , L_51 ) ;
goto V_222;
}
if ( ! V_7 -> V_53 )
goto V_222;
V_7 -> V_50 = F_93 ( & V_3 -> V_38 , L_52 ) ;
if ( F_11 ( V_7 -> V_50 ) )
V_7 -> V_50 = NULL ;
V_11 -> V_204 = V_229 ;
V_11 -> V_168 = V_7 -> V_168 ;
V_11 -> V_230 = & V_231 ;
V_11 -> V_73 = V_232 ;
strcpy ( V_11 -> V_73 . V_233 , V_7 -> V_3 -> V_234 ) ;
V_7 -> V_186 = F_94 ( V_38 , L_53 ) ;
if ( F_11 ( V_7 -> V_186 ) ) {
V_49 = F_13 ( V_7 -> V_186 ) ;
goto V_222;
}
V_7 -> V_91 = F_94 ( V_38 , L_54 ) ;
if ( F_11 ( V_7 -> V_91 ) ) {
V_49 = F_13 ( V_7 -> V_91 ) ;
goto V_235;
}
F_61 ( V_7 ) ;
V_89 = F_95 ( & V_11 -> V_89 ,
struct V_220 , V_212 ) ;
F_36 ( & V_11 -> V_9 , & V_89 -> V_189 ) ;
F_37 ( & V_11 -> V_9 , V_11 ) ;
V_218 = F_96 ( V_3 , V_236 , 0 ) ;
if ( ! V_218 ) {
F_12 ( V_38 , L_55 ) ;
V_49 = - V_237 ;
goto V_238;
}
V_7 -> V_239 = F_97 ( V_3 , 0 ) ;
if ( V_7 -> V_239 < 0 ) {
F_12 ( V_38 , L_56 ) ;
V_49 = V_7 -> V_239 ;
goto V_238;
}
V_219 = F_96 ( V_3 , V_236 , 1 ) ;
if ( V_219 ) {
V_11 -> V_73 . V_75 = V_219 -> V_240 ;
V_11 -> V_73 . V_80 = F_98 ( V_219 ) ;
if ( ! F_99 ( V_11 -> V_73 . V_75 ,
V_11 -> V_73 . V_80 , V_3 -> V_234 ) ) {
V_49 = - V_241 ;
goto V_238;
}
V_11 -> V_81 = F_100 ( V_11 -> V_73 . V_75 , V_11 -> V_73 . V_80 ) ;
if ( ! V_11 -> V_81 ) {
V_49 = - V_85 ;
goto V_242;
}
} else {
V_49 = F_30 ( V_7 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_57 , V_49 ) ;
goto V_238;
}
}
V_11 -> V_73 . V_243 = V_218 -> V_240 ;
V_11 -> V_73 . V_244 = F_98 ( V_218 ) ;
if ( ! F_99 ( V_11 -> V_73 . V_243 ,
V_11 -> V_73 . V_244 , V_3 -> V_234 ) ) {
V_49 = - V_241 ;
goto V_245;
}
V_7 -> V_246 = F_100 ( V_11 -> V_73 . V_243 , V_11 -> V_73 . V_244 ) ;
if ( ! V_7 -> V_246 ) {
F_12 ( V_38 , L_58 ) ;
V_49 = - V_85 ;
goto V_247;
}
F_17 ( V_7 ) ;
V_49 = F_101 ( V_7 -> V_239 , F_54 , 0 , V_3 -> V_234 , V_11 ) ;
if ( V_49 ) {
F_12 ( V_38 , L_59 , V_49 ) ;
goto V_248;
}
F_102 ( & V_7 -> V_177 , F_56 ) ;
V_49 = F_58 ( V_7 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_60 , V_49 ) ;
goto V_249;
}
V_49 = F_45 ( V_11 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_61 , V_49 ) ;
goto V_249;
}
F_103 ( V_38 , V_11 ) ;
V_49 = F_104 ( V_11 ) ;
if ( V_49 < 0 ) {
F_12 ( V_38 , L_62 , V_49 ) ;
goto V_250;
}
F_18 ( V_7 , 1 ) ;
F_59 ( V_38 , L_63 ,
V_11 -> V_251 , V_11 -> V_73 . V_243 , V_7 -> V_246 , V_7 -> V_239 ) ;
return 0 ;
V_250:
F_103 ( V_38 , NULL ) ;
F_105 ( & V_11 -> V_185 ) ;
V_249:
F_106 ( & V_7 -> V_177 ) ;
F_107 ( V_7 -> V_239 , V_11 ) ;
V_248:
F_14 ( V_7 ) ;
F_108 ( V_7 -> V_246 ) ;
V_247:
F_109 ( V_11 -> V_73 . V_243 , V_11 -> V_73 . V_244 ) ;
V_245:
if ( V_219 )
F_108 ( V_11 -> V_81 ) ;
else
F_28 ( V_7 ) ;
V_242:
if ( V_219 )
F_109 ( V_11 -> V_73 . V_75 , V_11 -> V_73 . V_80 ) ;
V_238:
F_63 ( V_7 ) ;
F_110 ( V_7 -> V_91 ) ;
V_235:
F_110 ( V_7 -> V_186 ) ;
V_222:
F_111 ( V_11 ) ;
V_221:
F_39 ( V_38 , L_64 , V_92 ) ;
return V_49 ;
}
static int T_4 F_112 ( struct V_2 * V_3 )
{
struct V_79 * V_38 = & V_3 -> V_38 ;
struct V_10 * V_11 = F_113 ( V_38 ) ;
struct V_6 * V_7 ;
struct V_43 * V_44 ;
if ( ! V_11 || ! V_11 -> V_71 )
return 0 ;
V_7 = V_11 -> V_71 ;
V_44 = & V_7 -> V_44 ;
F_106 ( & V_7 -> V_177 ) ;
F_14 ( V_7 ) ;
F_18 ( V_7 , 0 ) ;
F_114 ( V_11 ) ;
F_63 ( V_7 ) ;
F_110 ( V_7 -> V_91 ) ;
F_110 ( V_7 -> V_186 ) ;
F_105 ( & V_11 -> V_185 ) ;
F_107 ( V_7 -> V_239 , V_11 ) ;
F_108 ( V_7 -> V_246 ) ;
F_109 ( V_11 -> V_73 . V_243 , V_11 -> V_73 . V_244 ) ;
if ( F_96 ( V_3 , V_236 , 1 ) ) {
F_108 ( V_11 -> V_81 ) ;
F_109 ( V_11 -> V_73 . V_75 , V_11 -> V_73 . V_80 ) ;
} else {
F_28 ( V_7 ) ;
}
F_111 ( V_11 ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 , T_5 V_252 )
{
struct V_10 * V_11 = F_116 ( V_3 ) ;
struct V_6 * V_7 = V_11 -> V_71 ;
F_4 ( V_7 , V_156 , ~ 0UL ) ;
V_7 -> V_253 = F_5 ( V_7 , V_33 ) ;
F_4 ( V_7 , V_33 , 0 ) ;
F_18 ( V_7 , 0 ) ;
F_25 ( V_7 ) ;
F_63 ( V_7 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_116 ( V_3 ) ;
struct V_6 * V_7 = V_11 -> V_71 ;
F_61 ( V_7 ) ;
F_26 ( V_7 ) ;
F_18 ( V_7 , 1 ) ;
F_4 ( V_7 , V_33 , V_7 -> V_253 ) ;
F_4 ( V_7 , V_157 , V_158
| V_159 | V_160 ) ;
return 0 ;
}
