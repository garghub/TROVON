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
if ( V_7 -> V_43 )
V_31 &= ~ ( V_32 ) ;
F_4 ( V_7 , V_33 , V_31 ) ;
F_4 ( V_7 , V_30 , V_44 ) ;
if ( V_7 -> V_45 )
F_9 ( V_7 ) ;
}
static unsigned long F_18 ( struct V_6 * V_7 ,
unsigned long V_17 )
{
unsigned long V_46 ;
unsigned long V_47 ;
if ( ! V_7 -> V_48 -> V_49 )
return V_17 ;
V_46 = F_5 ( V_7 , V_50 ) ;
V_47 = V_17 ;
if ( ( V_46 & V_51 ) != V_52 ) {
if ( ( V_46 & V_51 ) == V_53 ) {
V_47 *= 3 ;
}
if ( ( V_46 & V_54 ) == V_55
|| ( ( V_46 & V_54 ) == V_56
&& ( V_46 & V_57 ) == V_58 ) )
V_47 = F_19 ( V_47 , 4 ) ;
else
V_47 = F_19 ( V_47 , 8 ) ;
}
return V_47 ;
}
static void F_20 ( struct V_6 * V_7 )
{
F_4 ( V_7 , V_59 ,
V_7 -> V_60 << V_61 ) ;
while ( F_5 ( V_7 , V_59 ) & V_62 )
F_21 ( 10 ) ;
F_4 ( V_7 , V_20 , 0 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
F_20 ( V_7 ) ;
while ( F_5 ( V_7 , V_20 ) & V_63 )
F_21 ( 10 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
F_4 ( V_7 , V_20 , V_7 -> V_64 ) ;
F_4 ( V_7 , V_59 ,
( V_7 -> V_60 << V_61 )
| V_65 ) ;
}
static void F_24 ( struct V_10 * V_11 ,
struct V_8 * V_9 )
{
struct V_6 * V_7 = V_11 -> V_66 ;
struct V_67 * V_68 = & V_11 -> V_68 ;
unsigned long V_69 ;
V_69 = ( V_68 -> V_70 + V_9 -> V_71 * V_68 -> V_72
+ V_9 -> V_14 * V_11 -> V_9 . V_15 / 8 ) ;
V_69 &= ~ 3UL ;
F_4 ( V_7 , V_73 , V_69 ) ;
F_3 ( V_7 , V_9 , V_11 ) ;
}
static inline void F_25 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
F_26 ( V_11 -> V_74 , V_11 -> V_68 . V_75 ,
V_11 -> V_76 , V_11 -> V_68 . V_70 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_8 * V_9 = & V_11 -> V_9 ;
unsigned int V_75 ;
V_75 = ( V_9 -> V_16 * V_9 -> V_77
* ( ( V_9 -> V_15 + 7 ) / 8 ) ) ;
V_11 -> V_68 . V_75 = F_28 ( V_75 , V_7 -> V_75 ) ;
V_11 -> V_76 = F_29 ( V_11 -> V_74 , V_11 -> V_68 . V_75 ,
( V_78 * ) & V_11 -> V_68 . V_70 , V_79 ) ;
if ( ! V_11 -> V_76 ) {
return - V_80 ;
}
memset ( V_11 -> V_76 , 0 , V_11 -> V_68 . V_75 ) ;
return 0 ;
}
static const struct V_81 * F_30 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_81 V_82 ;
const struct V_81 * V_83 = NULL ;
F_31 ( & V_82 , V_9 ) ;
V_83 = F_32 ( & V_82 , & V_11 -> V_84 ) ;
if ( V_83 )
F_33 ( V_9 , V_83 ) ;
return V_83 ;
}
static int F_34 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_74 * V_38 = V_11 -> V_74 ;
struct V_6 * V_7 = V_11 -> V_66 ;
unsigned long V_85 ;
V_85 = F_35 ( V_7 -> V_86 ) / 1000 ;
F_36 ( V_38 , L_4 , V_87 ) ;
if ( ! ( V_9 -> V_88 && V_9 -> V_15 ) ) {
if ( ! F_30 ( V_9 , V_11 ) ) {
F_12 ( V_38 , L_5 ) ;
return - V_89 ;
}
}
F_36 ( V_38 , L_6 , V_9 -> V_17 , V_9 -> V_90 ) ;
F_36 ( V_38 , L_7 , F_37 ( V_9 -> V_88 ) ) ;
F_36 ( V_38 , L_8 , V_9 -> V_15 ) ;
F_36 ( V_38 , L_9 , V_85 ) ;
if ( F_37 ( V_9 -> V_88 ) > V_85 ) {
F_12 ( V_38 , L_10 , F_37 ( V_9 -> V_88 ) ) ;
return - V_89 ;
}
if ( V_9 -> V_17 > V_9 -> V_16 )
V_9 -> V_16 = V_9 -> V_17 ;
if ( V_9 -> V_90 > V_9 -> V_77 )
V_9 -> V_77 = V_9 -> V_90 ;
V_9 -> V_17 = ( V_9 -> V_17 + 3 ) & ~ 3UL ;
V_9 -> V_16 = ( V_9 -> V_16 + 3 ) & ~ 3UL ;
V_9 -> V_91 . V_92 = V_9 -> V_93 . V_92 = V_9 -> V_94 . V_92 = 0 ;
V_9 -> V_95 . V_92 = 0 ;
V_9 -> V_95 . V_96 = V_9 -> V_95 . V_97 = 0 ;
V_9 -> V_14 = V_9 -> V_71 = 0 ;
if ( V_11 -> V_68 . V_75 ) {
unsigned int V_75 = ( V_9 -> V_16 * V_9 -> V_77
* ( ( V_9 -> V_15 + 7 ) / 8 ) ) ;
if ( V_75 > V_11 -> V_68 . V_75 ) {
F_12 ( V_38 , L_11 ,
V_11 -> V_68 . V_75 , V_75 ) ;
return - V_89 ;
}
}
V_9 -> V_98 = F_38 ( T_1 , V_9 -> V_98 ,
( V_99 >> V_100 ) + 1 ) ;
V_9 -> V_101 = F_38 ( T_1 , V_9 -> V_101 ,
V_102 >> V_103 ) ;
V_9 -> V_104 = F_38 ( T_1 , V_9 -> V_104 ,
V_105 ) ;
V_9 -> V_106 = F_38 ( T_1 , V_9 -> V_106 ,
( V_107 >> V_108 ) + 1 ) ;
V_9 -> V_109 = F_38 ( T_1 , V_9 -> V_109 ,
( V_110 >> V_111 ) + 1 ) ;
V_9 -> V_112 = F_38 ( T_1 , V_9 -> V_112 ,
V_113 + 1 ) ;
V_9 -> V_98 = F_39 ( T_1 , V_9 -> V_98 , 1 ) ;
V_9 -> V_106 = F_39 ( T_1 , V_9 -> V_106 , 1 ) ;
V_9 -> V_109 = F_39 ( T_1 , V_9 -> V_109 , 1 ) ;
V_9 -> V_112 = F_39 ( T_1 , V_9 -> V_112 , 1 ) ;
switch ( V_9 -> V_15 ) {
case 1 :
case 2 :
case 4 :
case 8 :
V_9 -> V_91 . V_96 = V_9 -> V_93 . V_96 = V_9 -> V_94 . V_96 = 0 ;
V_9 -> V_91 . V_97 = V_9 -> V_93 . V_97 = V_9 -> V_94 . V_97
= V_9 -> V_15 ;
break;
case 16 :
if ( V_7 -> V_48 -> V_114 )
V_9 -> V_93 . V_97 = 5 ;
else
V_9 -> V_93 . V_97 = 6 ;
if ( V_7 -> V_115 == V_116 ) {
V_9 -> V_91 . V_96 = V_9 -> V_93 . V_97 + 5 ;
V_9 -> V_94 . V_96 = 0 ;
} else {
V_9 -> V_91 . V_96 = 0 ;
V_9 -> V_94 . V_96 = V_9 -> V_93 . V_97 + 5 ;
}
V_9 -> V_93 . V_96 = 5 ;
V_9 -> V_91 . V_97 = V_9 -> V_94 . V_97 = 5 ;
break;
case 32 :
V_9 -> V_95 . V_96 = 24 ;
V_9 -> V_95 . V_97 = 8 ;
case 24 :
if ( V_7 -> V_115 == V_116 ) {
V_9 -> V_91 . V_96 = 16 ;
V_9 -> V_94 . V_96 = 0 ;
} else {
V_9 -> V_91 . V_96 = 0 ;
V_9 -> V_94 . V_96 = 16 ;
}
V_9 -> V_93 . V_96 = 8 ;
V_9 -> V_91 . V_97 = V_9 -> V_93 . V_97 = V_9 -> V_94 . V_97 = 8 ;
break;
default:
F_12 ( V_38 , L_12 ,
V_9 -> V_15 ) ;
return - V_89 ;
}
return 0 ;
}
static void F_40 ( struct V_6 * V_7 )
{
F_41 () ;
F_22 ( V_7 ) ;
F_23 ( V_7 ) ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_66 ;
unsigned long V_117 ;
unsigned long V_47 ;
unsigned long V_85 ;
unsigned long V_118 ;
unsigned long V_119 = 2 ;
F_41 () ;
F_36 ( V_11 -> V_74 , L_4 , V_87 ) ;
F_36 ( V_11 -> V_74 , L_13 ,
V_11 -> V_9 . V_17 , V_11 -> V_9 . V_90 ,
V_11 -> V_9 . V_16 , V_11 -> V_9 . V_77 ) ;
F_20 ( V_7 ) ;
if ( V_11 -> V_9 . V_15 == 1 )
V_11 -> V_68 . V_120 = V_121 ;
else if ( V_11 -> V_9 . V_15 <= 8 )
V_11 -> V_68 . V_120 = V_122 ;
else
V_11 -> V_68 . V_120 = V_123 ;
V_118 = V_11 -> V_9 . V_16 * V_11 -> V_9 . V_15 ;
V_11 -> V_68 . V_72 = F_19 ( V_118 , 8 ) ;
F_36 ( V_11 -> V_74 , L_14 ) ;
F_24 ( V_11 , & V_11 -> V_9 ) ;
V_47 = ( V_11 -> V_9 . V_90 * V_11 -> V_9 . V_17 * V_11 -> V_9 . V_15 ) / 32 ;
V_47 |= ( ( V_124 - 1 ) << V_125 ) ;
F_4 ( V_7 , V_126 , V_47 ) ;
if ( V_7 -> V_48 -> V_127 )
V_119 = 1 ;
V_85 = F_35 ( V_7 -> V_86 ) / 1000 ;
V_47 = F_19 ( V_85 , F_37 ( V_11 -> V_9 . V_88 ) ) ;
if ( V_47 < V_119 ) {
F_43 ( V_11 -> V_74 , L_15 ) ;
F_4 ( V_7 , V_128 , V_129 ) ;
} else {
V_47 = ( V_47 / V_119 ) - 1 ;
F_36 ( V_11 -> V_74 , L_16 ,
V_47 ) ;
F_4 ( V_7 , V_128 ,
V_47 << V_130 ) ;
V_11 -> V_9 . V_88 =
F_44 ( V_85 / ( V_119 * ( V_47 + 1 ) ) ) ;
F_36 ( V_11 -> V_74 , L_17 ,
F_37 ( V_11 -> V_9 . V_88 ) ) ;
}
V_47 = V_7 -> V_131 ;
if ( ! ( V_11 -> V_9 . V_132 & V_133 ) )
V_47 |= V_134 ;
if ( ! ( V_11 -> V_9 . V_132 & V_135 ) )
V_47 |= V_136 ;
switch ( V_11 -> V_9 . V_15 ) {
case 1 : V_47 |= V_137 ; break;
case 2 : V_47 |= V_138 ; break;
case 4 : V_47 |= V_139 ; break;
case 8 : V_47 |= V_140 ; break;
case 15 :
case 16 : V_47 |= V_141 ; break;
case 24 : V_47 |= V_142 ; break;
case 32 : V_47 |= V_143 ; break;
default: F_45 () ; break;
}
F_36 ( V_11 -> V_74 , L_18 , V_47 ) ;
F_4 ( V_7 , V_50 , V_47 ) ;
V_47 = ( V_11 -> V_9 . V_98 - 1 ) << V_100 ;
V_47 |= V_11 -> V_9 . V_101 << V_103 ;
V_47 |= V_11 -> V_9 . V_104 ;
F_36 ( V_11 -> V_74 , L_19 , V_47 ) ;
F_4 ( V_7 , V_144 , V_47 ) ;
V_47 = ( V_11 -> V_9 . V_106 - 1 ) << V_108 ;
V_47 |= ( V_11 -> V_9 . V_109 - 1 ) << V_111 ;
V_47 |= ( V_11 -> V_9 . V_112 - 1 ) ;
F_36 ( V_11 -> V_74 , L_20 , V_47 ) ;
F_4 ( V_7 , V_145 , V_47 ) ;
V_117 = F_18 ( V_7 , V_11 -> V_9 . V_17 ) ;
V_47 = ( V_117 - 1 ) << V_146 ;
V_47 |= V_11 -> V_9 . V_90 - 1 ;
F_36 ( V_11 -> V_74 , L_21 , V_47 ) ;
F_4 ( V_7 , V_147 , V_47 ) ;
V_47 = V_148 - ( 2 * V_124 + 3 ) ;
F_4 ( V_7 , V_149 , V_47 ) ;
F_4 ( V_7 , V_150 , 0 ) ;
F_4 ( V_7 , V_151 , ~ 0UL ) ;
F_4 ( V_7 , V_152 , V_153 | V_154 | V_155 ) ;
while ( F_5 ( V_7 , V_20 ) & V_63 )
F_21 ( 10 ) ;
F_23 ( V_7 ) ;
F_36 ( V_11 -> V_74 , L_22 ) ;
return 0 ;
}
static inline unsigned int F_46 ( unsigned int V_156 , const struct V_157 * V_158 )
{
V_156 &= 0xffff ;
V_156 >>= 16 - V_158 -> V_97 ;
return V_156 << V_158 -> V_96 ;
}
static int F_47 ( unsigned int V_159 , unsigned int V_91 ,
unsigned int V_93 , unsigned int V_94 ,
unsigned int V_95 , struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_66 ;
unsigned int V_160 ;
T_1 * V_161 ;
int V_162 = 1 ;
if ( V_11 -> V_9 . V_163 )
V_91 = V_93 = V_94 = ( 19595 * V_91 + 38470 * V_93
+ 7471 * V_94 ) >> 16 ;
switch ( V_11 -> V_68 . V_120 ) {
case V_123 :
if ( V_159 < 16 ) {
V_161 = V_11 -> V_164 ;
V_160 = F_46 ( V_91 , & V_11 -> V_9 . V_91 ) ;
V_160 |= F_46 ( V_93 , & V_11 -> V_9 . V_93 ) ;
V_160 |= F_46 ( V_94 , & V_11 -> V_9 . V_94 ) ;
V_161 [ V_159 ] = V_160 ;
V_162 = 0 ;
}
break;
case V_122 :
if ( V_159 < 256 ) {
if ( V_7 -> V_48 -> V_114 ) {
V_160 = ( ( V_91 >> 11 ) & 0x001f ) ;
V_160 |= ( ( V_93 >> 6 ) & 0x03e0 ) ;
V_160 |= ( ( V_94 >> 1 ) & 0x7c00 ) ;
} else {
if ( V_7 -> V_115 ==
V_116 ) {
V_160 = ( ( V_94 >> 11 ) & 0x001f ) ;
V_160 |= ( ( V_91 >> 0 ) & 0xf800 ) ;
} else {
V_160 = ( ( V_91 >> 11 ) & 0x001f ) ;
V_160 |= ( ( V_94 >> 0 ) & 0xf800 ) ;
}
V_160 |= ( ( V_93 >> 5 ) & 0x07e0 ) ;
}
F_4 ( V_7 , F_48 ( V_159 ) , V_160 ) ;
V_162 = 0 ;
}
break;
case V_121 :
if ( V_159 < 2 ) {
V_160 = ( V_159 == 0 ) ? 0x00 : 0x1F ;
F_4 ( V_7 , F_48 ( V_159 ) , V_160 ) ;
V_162 = 0 ;
}
break;
}
return V_162 ;
}
static int F_49 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
F_36 ( V_11 -> V_74 , L_23 , V_87 ) ;
F_24 ( V_11 , V_9 ) ;
return 0 ;
}
static int F_50 ( int V_165 , struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_66 ;
switch ( V_165 ) {
case V_29 :
case V_166 :
F_23 ( V_7 ) ;
break;
case V_167 :
case V_168 :
break;
case V_41 :
F_22 ( V_7 ) ;
break;
default:
return - V_89 ;
}
return ( ( V_165 == V_166 ) ? 1 : 0 ) ;
}
static T_2 F_51 ( int V_169 , void * V_170 )
{
struct V_10 * V_11 = V_170 ;
struct V_6 * V_7 = V_11 -> V_66 ;
T_1 V_171 ;
V_171 = F_5 ( V_7 , V_172 ) ;
if ( V_171 & V_153 ) {
F_16 ( V_11 -> V_74 , L_24 , V_171 ) ;
F_52 ( & V_7 -> V_173 ) ;
}
F_4 ( V_7 , V_174 , V_171 ) ;
return V_175 ;
}
static void F_53 ( struct V_176 * V_177 )
{
struct V_6 * V_7 =
F_54 ( V_177 , struct V_6 , V_173 ) ;
F_40 ( V_7 ) ;
}
static int T_3 F_55 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_162 = 0 ;
V_11 -> V_9 . V_178 |= V_179 | V_180 ;
F_56 ( V_11 -> V_74 ,
L_25 ,
( unsigned long ) V_11 -> V_68 . V_75 / 1024 ,
( unsigned long ) V_11 -> V_68 . V_70 ,
V_11 -> V_76 ) ;
V_162 = F_57 ( & V_11 -> V_181 , 256 , 0 ) ;
if ( V_162 < 0 )
F_12 ( V_11 -> V_74 , L_26 ) ;
return V_162 ;
}
static void F_58 ( struct V_6 * V_7 )
{
F_59 ( V_7 -> V_182 ) ;
F_59 ( V_7 -> V_86 ) ;
}
static void F_60 ( struct V_6 * V_7 )
{
F_61 ( V_7 -> V_182 ) ;
F_61 ( V_7 -> V_86 ) ;
}
static int T_3 F_62 ( struct V_2 * V_3 )
{
struct V_74 * V_38 = & V_3 -> V_38 ;
struct V_10 * V_11 ;
struct V_6 * V_7 ;
struct V_6 * V_183 ;
struct V_81 V_83 ;
struct V_184 * V_185 = NULL ;
struct V_184 * V_186 = NULL ;
int V_162 ;
F_36 ( V_38 , L_27 , V_87 ) ;
V_162 = - V_80 ;
V_11 = F_63 ( sizeof( struct V_6 ) , V_38 ) ;
if ( ! V_11 ) {
F_12 ( V_38 , L_28 ) ;
goto V_187;
}
V_7 = V_11 -> V_66 ;
if ( V_38 -> V_188 ) {
V_183 = (struct V_6 * ) V_38 -> V_188 ;
V_7 -> V_189 = V_183 -> V_189 ;
V_7 -> V_64 = V_183 -> V_64 ;
V_7 -> V_131 = V_183 -> V_131 ;
V_7 -> V_190 = V_183 -> V_190 ;
V_7 -> V_191 = V_183 -> V_191 ;
V_7 -> V_60 = V_183 -> V_60 ;
V_7 -> V_75 = V_183 -> V_75 ;
V_7 -> V_45 = V_183 -> V_45 ;
V_7 -> V_43 = V_183 -> V_43 ;
V_7 -> V_115 = V_183 -> V_115 ;
} else {
F_12 ( V_38 , L_29 ) ;
goto V_192;
}
V_7 -> V_11 = V_11 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_48 = F_1 ( V_3 ) ;
if ( ! V_7 -> V_48 )
goto V_192;
strcpy ( V_11 -> V_68 . V_193 , V_7 -> V_3 -> V_194 ) ;
V_11 -> V_195 = V_196 ;
V_11 -> V_164 = V_7 -> V_164 ;
V_11 -> V_197 = & V_198 ;
memcpy ( & V_11 -> V_199 , V_7 -> V_190 , sizeof( V_11 -> V_199 ) ) ;
V_11 -> V_68 = V_200 ;
V_7 -> V_182 = F_64 ( V_38 , L_30 ) ;
if ( F_11 ( V_7 -> V_182 ) ) {
V_162 = F_13 ( V_7 -> V_182 ) ;
goto V_192;
}
V_7 -> V_86 = F_64 ( V_38 , L_31 ) ;
if ( F_11 ( V_7 -> V_86 ) ) {
V_162 = F_13 ( V_7 -> V_86 ) ;
goto V_201;
}
F_58 ( V_7 ) ;
V_162 = F_65 ( & V_11 -> V_9 , V_11 , NULL , V_11 -> V_199 . V_202 ,
V_11 -> V_199 . V_203 , V_11 -> V_199 . V_202 ,
V_7 -> V_189 ) ;
if ( ! V_162 ) {
F_12 ( V_38 , L_32 ) ;
goto V_204;
}
V_185 = F_66 ( V_3 , V_205 , 0 ) ;
if ( ! V_185 ) {
F_12 ( V_38 , L_33 ) ;
V_162 = - V_206 ;
goto V_204;
}
V_7 -> V_207 = F_67 ( V_3 , 0 ) ;
if ( V_7 -> V_207 < 0 ) {
F_12 ( V_38 , L_34 ) ;
V_162 = V_7 -> V_207 ;
goto V_204;
}
V_186 = F_66 ( V_3 , V_205 , 1 ) ;
if ( V_186 ) {
V_11 -> V_68 . V_70 = V_186 -> V_208 ;
V_11 -> V_68 . V_75 = F_68 ( V_186 ) ;
if ( ! F_69 ( V_11 -> V_68 . V_70 ,
V_11 -> V_68 . V_75 , V_3 -> V_194 ) ) {
V_162 = - V_209 ;
goto V_204;
}
V_11 -> V_76 = F_70 ( V_11 -> V_68 . V_70 , V_11 -> V_68 . V_75 ) ;
if ( ! V_11 -> V_76 ) {
V_162 = - V_80 ;
goto V_210;
}
} else {
V_162 = F_27 ( V_7 ) ;
if ( V_162 < 0 ) {
F_12 ( V_38 , L_35 , V_162 ) ;
goto V_204;
}
}
V_11 -> V_68 . V_211 = V_185 -> V_208 ;
V_11 -> V_68 . V_212 = F_68 ( V_185 ) ;
if ( ! F_69 ( V_11 -> V_68 . V_211 ,
V_11 -> V_68 . V_212 , V_3 -> V_194 ) ) {
V_162 = - V_209 ;
goto V_213;
}
V_7 -> V_214 = F_70 ( V_11 -> V_68 . V_211 , V_11 -> V_68 . V_212 ) ;
if ( ! V_7 -> V_214 ) {
F_12 ( V_38 , L_36 ) ;
V_162 = - V_80 ;
goto V_215;
}
F_17 ( V_7 ) ;
V_162 = F_71 ( V_7 -> V_207 , F_51 , 0 , V_3 -> V_194 , V_11 ) ;
if ( V_162 ) {
F_12 ( V_38 , L_37 , V_162 ) ;
goto V_216;
}
F_72 ( & V_7 -> V_173 , F_53 ) ;
V_162 = F_55 ( V_7 ) ;
if ( V_162 < 0 ) {
F_12 ( V_38 , L_38 , V_162 ) ;
goto V_217;
}
F_34 ( & V_11 -> V_9 , V_11 ) ;
V_162 = F_73 ( V_11 , & V_11 -> V_9 ) ;
if ( V_162 ) {
F_16 ( V_38 , L_39 ) ;
goto V_218;
}
F_74 ( V_38 , V_11 ) ;
V_162 = F_75 ( V_11 ) ;
if ( V_162 < 0 ) {
F_12 ( V_38 , L_40 , V_162 ) ;
goto V_219;
}
F_31 ( & V_83 , & V_11 -> V_9 ) ;
F_76 ( & V_83 , & V_11 -> V_84 ) ;
if ( V_7 -> V_191 )
V_7 -> V_191 ( 1 ) ;
F_56 ( V_38 , L_41 ,
V_11 -> V_220 , V_11 -> V_68 . V_211 , V_7 -> V_214 , V_7 -> V_207 ) ;
return 0 ;
V_219:
F_74 ( V_38 , NULL ) ;
V_218:
F_77 ( & V_11 -> V_181 ) ;
V_217:
F_78 ( & V_7 -> V_173 ) ;
F_79 ( V_7 -> V_207 , V_11 ) ;
V_216:
F_14 ( V_7 ) ;
F_80 ( V_7 -> V_214 ) ;
V_215:
F_81 ( V_11 -> V_68 . V_211 , V_11 -> V_68 . V_212 ) ;
V_213:
if ( V_186 )
F_80 ( V_11 -> V_76 ) ;
else
F_25 ( V_7 ) ;
V_210:
if ( V_186 )
F_81 ( V_11 -> V_68 . V_70 , V_11 -> V_68 . V_75 ) ;
V_204:
F_60 ( V_7 ) ;
F_82 ( V_7 -> V_86 ) ;
V_201:
F_82 ( V_7 -> V_182 ) ;
V_192:
F_83 ( V_11 ) ;
V_187:
F_36 ( V_38 , L_42 , V_87 ) ;
return V_162 ;
}
static int T_4 F_84 ( struct V_2 * V_3 )
{
struct V_74 * V_38 = & V_3 -> V_38 ;
struct V_10 * V_11 = F_85 ( V_38 ) ;
struct V_6 * V_7 ;
if ( ! V_11 || ! V_11 -> V_66 )
return 0 ;
V_7 = V_11 -> V_66 ;
F_78 ( & V_7 -> V_173 ) ;
F_14 ( V_7 ) ;
if ( V_7 -> V_191 )
V_7 -> V_191 ( 0 ) ;
F_86 ( V_11 ) ;
F_60 ( V_7 ) ;
F_82 ( V_7 -> V_86 ) ;
F_82 ( V_7 -> V_182 ) ;
F_77 ( & V_11 -> V_181 ) ;
F_79 ( V_7 -> V_207 , V_11 ) ;
F_80 ( V_7 -> V_214 ) ;
F_81 ( V_11 -> V_68 . V_211 , V_11 -> V_68 . V_212 ) ;
if ( F_66 ( V_3 , V_205 , 1 ) ) {
F_80 ( V_11 -> V_76 ) ;
F_81 ( V_11 -> V_68 . V_70 , V_11 -> V_68 . V_75 ) ;
} else {
F_25 ( V_7 ) ;
}
F_74 ( V_38 , NULL ) ;
F_83 ( V_11 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_3 , T_5 V_221 )
{
struct V_10 * V_11 = F_88 ( V_3 ) ;
struct V_6 * V_7 = V_11 -> V_66 ;
F_4 ( V_7 , V_151 , ~ 0UL ) ;
V_7 -> V_222 = F_5 ( V_7 , V_33 ) ;
F_4 ( V_7 , V_33 , 0 ) ;
if ( V_7 -> V_191 )
V_7 -> V_191 ( 0 ) ;
F_22 ( V_7 ) ;
F_60 ( V_7 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_88 ( V_3 ) ;
struct V_6 * V_7 = V_11 -> V_66 ;
F_58 ( V_7 ) ;
F_23 ( V_7 ) ;
if ( V_7 -> V_191 )
V_7 -> V_191 ( 1 ) ;
F_4 ( V_7 , V_33 , V_7 -> V_222 ) ;
F_4 ( V_7 , V_152 , V_153
| V_154 | V_155 ) ;
return 0 ;
}
