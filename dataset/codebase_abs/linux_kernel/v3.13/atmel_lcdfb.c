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
struct V_43 * V_44 = & V_7 -> V_44 ;
if ( V_44 -> F_18 )
V_44 -> F_18 ( V_44 , V_48 ) ;
}
static unsigned long F_19 ( struct V_6 * V_7 ,
unsigned long V_17 )
{
unsigned long V_49 ;
unsigned long V_50 ;
if ( ! V_7 -> V_51 -> V_52 )
return V_17 ;
V_49 = F_5 ( V_7 , V_53 ) ;
V_50 = V_17 ;
if ( ( V_49 & V_54 ) != V_55 ) {
if ( ( V_49 & V_54 ) == V_56 ) {
V_50 *= 3 ;
}
if ( ( V_49 & V_57 ) == V_58
|| ( ( V_49 & V_57 ) == V_59
&& ( V_49 & V_60 ) == V_61 ) )
V_50 = F_20 ( V_50 , 4 ) ;
else
V_50 = F_20 ( V_50 , 8 ) ;
}
return V_50 ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = & V_7 -> V_44 ;
F_4 ( V_7 , V_62 ,
V_44 -> V_63 << V_64 ) ;
while ( F_5 ( V_7 , V_62 ) & V_65 )
F_22 ( 10 ) ;
F_4 ( V_7 , V_20 , 0 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
F_21 ( V_7 ) ;
while ( F_5 ( V_7 , V_20 ) & V_66 )
F_22 ( 10 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = & V_7 -> V_44 ;
F_4 ( V_7 , V_20 , V_44 -> V_67 ) ;
F_4 ( V_7 , V_62 ,
( V_44 -> V_63 << V_64 )
| V_68 ) ;
}
static void F_25 ( struct V_10 * V_11 ,
struct V_8 * V_9 )
{
struct V_6 * V_7 = V_11 -> V_69 ;
struct V_70 * V_71 = & V_11 -> V_71 ;
unsigned long V_72 ;
V_72 = ( V_71 -> V_73 + V_9 -> V_74 * V_71 -> V_75
+ V_9 -> V_14 * V_11 -> V_9 . V_15 / 8 ) ;
V_72 &= ~ 3UL ;
F_4 ( V_7 , V_76 , V_72 ) ;
F_3 ( V_7 , V_9 , V_11 ) ;
}
static inline void F_26 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
F_27 ( V_11 -> V_77 , V_11 -> V_71 . V_78 ,
V_11 -> V_79 , V_11 -> V_71 . V_73 ) ;
}
static int F_28 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_8 * V_9 = & V_11 -> V_9 ;
unsigned int V_78 ;
V_78 = ( V_9 -> V_16 * V_9 -> V_80
* ( ( V_9 -> V_15 + 7 ) / 8 ) ) ;
V_11 -> V_71 . V_78 = F_29 ( V_78 , V_7 -> V_78 ) ;
V_11 -> V_79 = F_30 ( V_11 -> V_77 , V_11 -> V_71 . V_78 ,
( V_81 * ) & V_11 -> V_71 . V_73 , V_82 ) ;
if ( ! V_11 -> V_79 ) {
return - V_83 ;
}
memset ( V_11 -> V_79 , 0 , V_11 -> V_71 . V_78 ) ;
return 0 ;
}
static const struct V_84 * F_31 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_84 V_85 ;
const struct V_84 * V_86 = NULL ;
F_32 ( & V_85 , V_9 ) ;
V_86 = F_33 ( & V_85 , & V_11 -> V_87 ) ;
if ( V_86 )
F_34 ( V_9 , V_86 ) ;
return V_86 ;
}
static int F_35 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_77 * V_38 = V_11 -> V_77 ;
struct V_6 * V_7 = V_11 -> V_69 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
unsigned long V_88 ;
V_88 = F_36 ( V_7 -> V_89 ) / 1000 ;
F_37 ( V_38 , L_4 , V_90 ) ;
if ( ! ( V_9 -> V_91 && V_9 -> V_15 ) ) {
if ( ! F_31 ( V_9 , V_11 ) ) {
F_12 ( V_38 , L_5 ) ;
return - V_92 ;
}
}
F_37 ( V_38 , L_6 , V_9 -> V_17 , V_9 -> V_93 ) ;
F_37 ( V_38 , L_7 , F_38 ( V_9 -> V_91 ) ) ;
F_37 ( V_38 , L_8 , V_9 -> V_15 ) ;
F_37 ( V_38 , L_9 , V_88 ) ;
if ( F_38 ( V_9 -> V_91 ) > V_88 ) {
F_12 ( V_38 , L_10 , F_38 ( V_9 -> V_91 ) ) ;
return - V_92 ;
}
if ( V_9 -> V_17 > V_9 -> V_16 )
V_9 -> V_16 = V_9 -> V_17 ;
if ( V_9 -> V_93 > V_9 -> V_80 )
V_9 -> V_80 = V_9 -> V_93 ;
V_9 -> V_17 = ( V_9 -> V_17 + 3 ) & ~ 3UL ;
V_9 -> V_16 = ( V_9 -> V_16 + 3 ) & ~ 3UL ;
V_9 -> V_94 . V_95 = V_9 -> V_96 . V_95 = V_9 -> V_97 . V_95 = 0 ;
V_9 -> V_98 . V_95 = 0 ;
V_9 -> V_98 . V_99 = V_9 -> V_98 . V_100 = 0 ;
V_9 -> V_14 = V_9 -> V_74 = 0 ;
if ( V_11 -> V_71 . V_78 ) {
unsigned int V_78 = ( V_9 -> V_16 * V_9 -> V_80
* ( ( V_9 -> V_15 + 7 ) / 8 ) ) ;
if ( V_78 > V_11 -> V_71 . V_78 ) {
F_12 ( V_38 , L_11 ,
V_11 -> V_71 . V_78 , V_78 ) ;
return - V_92 ;
}
}
V_9 -> V_101 = F_39 ( T_1 , V_9 -> V_101 ,
( V_102 >> V_103 ) + 1 ) ;
V_9 -> V_104 = F_39 ( T_1 , V_9 -> V_104 ,
V_105 >> V_106 ) ;
V_9 -> V_107 = F_39 ( T_1 , V_9 -> V_107 ,
V_108 ) ;
V_9 -> V_109 = F_39 ( T_1 , V_9 -> V_109 ,
( V_110 >> V_111 ) + 1 ) ;
V_9 -> V_112 = F_39 ( T_1 , V_9 -> V_112 ,
( V_113 >> V_114 ) + 1 ) ;
V_9 -> V_115 = F_39 ( T_1 , V_9 -> V_115 ,
V_116 + 1 ) ;
V_9 -> V_101 = F_40 ( T_1 , V_9 -> V_101 , 1 ) ;
V_9 -> V_109 = F_40 ( T_1 , V_9 -> V_109 , 1 ) ;
V_9 -> V_112 = F_40 ( T_1 , V_9 -> V_112 , 1 ) ;
V_9 -> V_115 = F_40 ( T_1 , V_9 -> V_115 , 1 ) ;
switch ( V_9 -> V_15 ) {
case 1 :
case 2 :
case 4 :
case 8 :
V_9 -> V_94 . V_99 = V_9 -> V_96 . V_99 = V_9 -> V_97 . V_99 = 0 ;
V_9 -> V_94 . V_100 = V_9 -> V_96 . V_100 = V_9 -> V_97 . V_100
= V_9 -> V_15 ;
break;
case 16 :
if ( V_7 -> V_51 -> V_117 )
V_9 -> V_96 . V_100 = 5 ;
else
V_9 -> V_96 . V_100 = 6 ;
if ( V_44 -> V_118 == V_119 ) {
V_9 -> V_94 . V_99 = V_9 -> V_96 . V_100 + 5 ;
V_9 -> V_97 . V_99 = 0 ;
} else {
V_9 -> V_94 . V_99 = 0 ;
V_9 -> V_97 . V_99 = V_9 -> V_96 . V_100 + 5 ;
}
V_9 -> V_96 . V_99 = 5 ;
V_9 -> V_94 . V_100 = V_9 -> V_97 . V_100 = 5 ;
break;
case 32 :
V_9 -> V_98 . V_99 = 24 ;
V_9 -> V_98 . V_100 = 8 ;
case 24 :
if ( V_44 -> V_118 == V_119 ) {
V_9 -> V_94 . V_99 = 16 ;
V_9 -> V_97 . V_99 = 0 ;
} else {
V_9 -> V_94 . V_99 = 0 ;
V_9 -> V_97 . V_99 = 16 ;
}
V_9 -> V_96 . V_99 = 8 ;
V_9 -> V_94 . V_100 = V_9 -> V_96 . V_100 = V_9 -> V_97 . V_100 = 8 ;
break;
default:
F_12 ( V_38 , L_12 ,
V_9 -> V_15 ) ;
return - V_92 ;
}
return 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
F_42 () ;
F_23 ( V_7 ) ;
F_24 ( V_7 ) ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_69 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
unsigned long V_120 ;
unsigned long V_50 ;
unsigned long V_88 ;
unsigned long V_121 ;
unsigned long V_122 = 2 ;
F_42 () ;
F_37 ( V_11 -> V_77 , L_4 , V_90 ) ;
F_37 ( V_11 -> V_77 , L_13 ,
V_11 -> V_9 . V_17 , V_11 -> V_9 . V_93 ,
V_11 -> V_9 . V_16 , V_11 -> V_9 . V_80 ) ;
F_21 ( V_7 ) ;
if ( V_11 -> V_9 . V_15 == 1 )
V_11 -> V_71 . V_123 = V_124 ;
else if ( V_11 -> V_9 . V_15 <= 8 )
V_11 -> V_71 . V_123 = V_125 ;
else
V_11 -> V_71 . V_123 = V_126 ;
V_121 = V_11 -> V_9 . V_16 * V_11 -> V_9 . V_15 ;
V_11 -> V_71 . V_75 = F_20 ( V_121 , 8 ) ;
F_37 ( V_11 -> V_77 , L_14 ) ;
F_25 ( V_11 , & V_11 -> V_9 ) ;
V_50 = ( V_11 -> V_9 . V_93 * V_11 -> V_9 . V_17 * V_11 -> V_9 . V_15 ) / 32 ;
V_50 |= ( ( V_127 - 1 ) << V_128 ) ;
F_4 ( V_7 , V_129 , V_50 ) ;
if ( V_7 -> V_51 -> V_130 )
V_122 = 1 ;
V_88 = F_36 ( V_7 -> V_89 ) / 1000 ;
V_50 = F_20 ( V_88 , F_38 ( V_11 -> V_9 . V_91 ) ) ;
if ( V_50 < V_122 ) {
F_44 ( V_11 -> V_77 , L_15 ) ;
F_4 ( V_7 , V_131 , V_132 ) ;
} else {
V_50 = ( V_50 / V_122 ) - 1 ;
F_37 ( V_11 -> V_77 , L_16 ,
V_50 ) ;
F_4 ( V_7 , V_131 ,
V_50 << V_133 ) ;
V_11 -> V_9 . V_91 =
F_45 ( V_88 / ( V_122 * ( V_50 + 1 ) ) ) ;
F_37 ( V_11 -> V_77 , L_17 ,
F_38 ( V_11 -> V_9 . V_91 ) ) ;
}
V_50 = V_44 -> V_134 ;
if ( ! ( V_11 -> V_9 . V_135 & V_136 ) )
V_50 |= V_137 ;
if ( ! ( V_11 -> V_9 . V_135 & V_138 ) )
V_50 |= V_139 ;
switch ( V_11 -> V_9 . V_15 ) {
case 1 : V_50 |= V_140 ; break;
case 2 : V_50 |= V_141 ; break;
case 4 : V_50 |= V_142 ; break;
case 8 : V_50 |= V_143 ; break;
case 15 :
case 16 : V_50 |= V_144 ; break;
case 24 : V_50 |= V_145 ; break;
case 32 : V_50 |= V_146 ; break;
default: F_46 () ; break;
}
F_37 ( V_11 -> V_77 , L_18 , V_50 ) ;
F_4 ( V_7 , V_53 , V_50 ) ;
V_50 = ( V_11 -> V_9 . V_101 - 1 ) << V_103 ;
V_50 |= V_11 -> V_9 . V_104 << V_106 ;
V_50 |= V_11 -> V_9 . V_107 ;
F_37 ( V_11 -> V_77 , L_19 , V_50 ) ;
F_4 ( V_7 , V_147 , V_50 ) ;
V_50 = ( V_11 -> V_9 . V_109 - 1 ) << V_111 ;
V_50 |= ( V_11 -> V_9 . V_112 - 1 ) << V_114 ;
V_50 |= ( V_11 -> V_9 . V_115 - 1 ) ;
F_37 ( V_11 -> V_77 , L_20 , V_50 ) ;
F_4 ( V_7 , V_148 , V_50 ) ;
V_120 = F_19 ( V_7 , V_11 -> V_9 . V_17 ) ;
V_50 = ( V_120 - 1 ) << V_149 ;
V_50 |= V_11 -> V_9 . V_93 - 1 ;
F_37 ( V_11 -> V_77 , L_21 , V_50 ) ;
F_4 ( V_7 , V_150 , V_50 ) ;
V_50 = V_151 - ( 2 * V_127 + 3 ) ;
F_4 ( V_7 , V_152 , V_50 ) ;
F_4 ( V_7 , V_153 , 0 ) ;
F_4 ( V_7 , V_154 , ~ 0UL ) ;
F_4 ( V_7 , V_155 , V_156 | V_157 | V_158 ) ;
while ( F_5 ( V_7 , V_20 ) & V_66 )
F_22 ( 10 ) ;
F_24 ( V_7 ) ;
F_37 ( V_11 -> V_77 , L_22 ) ;
return 0 ;
}
static inline unsigned int F_47 ( unsigned int V_159 , const struct V_160 * V_161 )
{
V_159 &= 0xffff ;
V_159 >>= 16 - V_161 -> V_100 ;
return V_159 << V_161 -> V_99 ;
}
static int F_48 ( unsigned int V_162 , unsigned int V_94 ,
unsigned int V_96 , unsigned int V_97 ,
unsigned int V_98 , struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_69 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
unsigned int V_163 ;
T_1 * V_164 ;
int V_165 = 1 ;
if ( V_11 -> V_9 . V_166 )
V_94 = V_96 = V_97 = ( 19595 * V_94 + 38470 * V_96
+ 7471 * V_97 ) >> 16 ;
switch ( V_11 -> V_71 . V_123 ) {
case V_126 :
if ( V_162 < 16 ) {
V_164 = V_11 -> V_167 ;
V_163 = F_47 ( V_94 , & V_11 -> V_9 . V_94 ) ;
V_163 |= F_47 ( V_96 , & V_11 -> V_9 . V_96 ) ;
V_163 |= F_47 ( V_97 , & V_11 -> V_9 . V_97 ) ;
V_164 [ V_162 ] = V_163 ;
V_165 = 0 ;
}
break;
case V_125 :
if ( V_162 < 256 ) {
if ( V_7 -> V_51 -> V_117 ) {
V_163 = ( ( V_94 >> 11 ) & 0x001f ) ;
V_163 |= ( ( V_96 >> 6 ) & 0x03e0 ) ;
V_163 |= ( ( V_97 >> 1 ) & 0x7c00 ) ;
} else {
if ( V_44 -> V_118 == V_119 ) {
V_163 = ( ( V_97 >> 11 ) & 0x001f ) ;
V_163 |= ( ( V_94 >> 0 ) & 0xf800 ) ;
} else {
V_163 = ( ( V_94 >> 11 ) & 0x001f ) ;
V_163 |= ( ( V_97 >> 0 ) & 0xf800 ) ;
}
V_163 |= ( ( V_96 >> 5 ) & 0x07e0 ) ;
}
F_4 ( V_7 , F_49 ( V_162 ) , V_163 ) ;
V_165 = 0 ;
}
break;
case V_124 :
if ( V_162 < 2 ) {
V_163 = ( V_162 == 0 ) ? 0x00 : 0x1F ;
F_4 ( V_7 , F_49 ( V_162 ) , V_163 ) ;
V_165 = 0 ;
}
break;
}
return V_165 ;
}
static int F_50 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
F_37 ( V_11 -> V_77 , L_23 , V_90 ) ;
F_25 ( V_11 , V_9 ) ;
return 0 ;
}
static int F_51 ( int V_168 , struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_69 ;
switch ( V_168 ) {
case V_29 :
case V_169 :
F_24 ( V_7 ) ;
break;
case V_170 :
case V_171 :
break;
case V_41 :
F_23 ( V_7 ) ;
break;
default:
return - V_92 ;
}
return ( ( V_168 == V_169 ) ? 1 : 0 ) ;
}
static T_2 F_52 ( int V_172 , void * V_173 )
{
struct V_10 * V_11 = V_173 ;
struct V_6 * V_7 = V_11 -> V_69 ;
T_1 V_174 ;
V_174 = F_5 ( V_7 , V_175 ) ;
if ( V_174 & V_156 ) {
F_16 ( V_11 -> V_77 , L_24 , V_174 ) ;
F_53 ( & V_7 -> V_176 ) ;
}
F_4 ( V_7 , V_177 , V_174 ) ;
return V_178 ;
}
static void F_54 ( struct V_179 * V_180 )
{
struct V_6 * V_7 =
F_55 ( V_180 , struct V_6 , V_176 ) ;
F_41 ( V_7 ) ;
}
static int T_3 F_56 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
int V_165 = 0 ;
V_11 -> V_9 . V_181 |= V_182 | V_183 ;
F_57 ( V_11 -> V_77 ,
L_25 ,
( unsigned long ) V_11 -> V_71 . V_78 / 1024 ,
( unsigned long ) V_11 -> V_71 . V_73 ,
V_11 -> V_79 ) ;
V_165 = F_58 ( & V_11 -> V_184 , 256 , 0 ) ;
if ( V_165 < 0 )
F_12 ( V_11 -> V_77 , L_26 ) ;
return V_165 ;
}
static void F_59 ( struct V_6 * V_7 )
{
F_60 ( V_7 -> V_185 ) ;
F_60 ( V_7 -> V_89 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_62 ( V_7 -> V_185 ) ;
F_62 ( V_7 -> V_89 ) ;
}
const int F_63 ( struct V_186 * V_187 )
{
const char * V_188 ;
int V_189 , V_190 ;
V_189 = F_64 ( V_187 , L_27 , & V_188 ) ;
if ( V_189 < 0 )
return V_191 ;
for ( V_190 = 0 ; V_190 < F_65 ( V_192 ) ; V_190 ++ )
if ( ! strcasecmp ( V_188 , V_192 [ V_190 ] ) )
return V_190 ;
return - V_193 ;
}
static void F_66 ( struct V_43 * V_44 , int V_48 )
{
struct V_194 * V_195 ;
F_67 (og, &pdata->pwr_gpios, list)
F_68 ( V_195 -> V_196 , V_48 ) ;
}
static int F_69 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_43 * V_44 = & V_7 -> V_44 ;
struct V_8 * V_9 = & V_11 -> V_9 ;
struct V_77 * V_38 = & V_7 -> V_3 -> V_38 ;
struct V_186 * V_187 = V_38 -> V_197 ;
struct V_186 * V_198 ;
struct V_186 * V_199 ;
struct V_200 * V_201 ;
enum V_202 V_203 ;
struct V_194 * V_195 ;
bool V_204 = false ;
int V_165 = - V_205 ;
int V_190 , V_196 ;
V_7 -> V_51 = (struct V_1 * )
F_70 ( V_206 , V_38 ) -> V_4 ;
V_198 = F_71 ( V_187 , L_28 , 0 ) ;
if ( ! V_198 ) {
F_12 ( V_38 , L_29 ) ;
return - V_205 ;
}
V_165 = F_72 ( V_198 , L_30 , & V_9 -> V_15 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_31 ) ;
goto V_207;
}
V_165 = F_72 ( V_198 , L_32 , & V_44 -> V_63 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_33 ) ;
goto V_207;
}
V_165 = F_72 ( V_198 , L_34 , & V_44 -> V_134 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_35 ) ;
goto V_207;
}
V_165 = F_72 ( V_198 , L_36 , & V_44 -> V_67 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_31 ) ;
goto V_207;
}
V_165 = - V_83 ;
for ( V_190 = 0 ; V_190 < F_73 ( V_198 , L_37 ) ; V_190 ++ ) {
V_196 = F_74 ( V_198 , L_37 ,
V_190 , & V_203 ) ;
if ( V_196 < 0 )
continue;
V_195 = F_75 ( V_38 , sizeof( * V_195 ) , V_82 ) ;
if ( ! V_195 )
goto V_207;
V_195 -> V_196 = V_196 ;
V_195 -> V_208 = V_203 & V_209 ;
V_204 = true ;
V_165 = F_76 ( V_38 , V_196 , L_38 ) ;
if ( V_165 ) {
F_12 ( V_38 , L_39 , V_196 ) ;
goto V_207;
}
V_165 = F_77 ( V_196 , V_195 -> V_208 ) ;
if ( V_165 ) {
F_12 ( V_38 , L_40 , V_196 ) ;
goto V_207;
}
}
if ( V_204 )
V_44 -> F_18 = F_66 ;
V_165 = F_63 ( V_198 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_41 ) ;
goto V_207;
}
V_44 -> V_118 = V_165 ;
V_44 -> V_47 = F_78 ( V_198 , L_42 ) ;
V_201 = F_79 ( V_198 ) ;
if ( ! V_201 ) {
F_12 ( V_38 , L_43 ) ;
goto V_207;
}
V_199 = F_80 ( V_198 , L_44 ) ;
if ( ! V_199 ) {
F_12 ( V_38 , L_45 ) ;
goto V_207;
}
for ( V_190 = 0 ; V_190 < F_81 ( V_199 ) ; V_190 ++ ) {
struct V_210 V_211 ;
struct V_84 V_212 ;
V_165 = F_82 ( V_201 , & V_211 , V_190 ) ;
if ( V_165 < 0 )
goto V_213;
V_165 = F_83 ( & V_211 , & V_212 ) ;
if ( V_165 < 0 )
goto V_213;
F_84 ( & V_212 , & V_11 -> V_87 ) ;
}
return 0 ;
V_213:
F_85 ( V_199 ) ;
V_207:
F_85 ( V_198 ) ;
return V_165 ;
}
static int F_69 ( struct V_6 * V_7 )
{
return 0 ;
}
static int T_3 F_86 ( struct V_2 * V_3 )
{
struct V_77 * V_38 = & V_3 -> V_38 ;
struct V_10 * V_11 ;
struct V_6 * V_7 ;
struct V_43 * V_44 = NULL ;
struct V_214 * V_215 = NULL ;
struct V_214 * V_216 = NULL ;
struct V_217 * V_87 ;
int V_165 ;
F_37 ( V_38 , L_46 , V_90 ) ;
V_165 = - V_83 ;
V_11 = F_87 ( sizeof( struct V_6 ) , V_38 ) ;
if ( ! V_11 ) {
F_12 ( V_38 , L_47 ) ;
goto V_218;
}
V_7 = V_11 -> V_69 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_11 = V_11 ;
F_88 ( & V_11 -> V_87 ) ;
if ( V_3 -> V_38 . V_197 ) {
V_165 = F_69 ( V_7 ) ;
if ( V_165 )
goto V_219;
} else if ( F_89 ( V_38 ) ) {
struct V_220 * V_221 ;
int V_190 ;
V_44 = F_89 ( V_38 ) ;
V_221 = V_44 -> V_222 ;
V_7 -> V_44 = * V_44 ;
for ( V_190 = 0 ; V_190 < V_221 -> V_223 ; V_190 ++ )
F_84 ( & V_221 -> V_224 [ V_190 ] , & V_11 -> V_87 ) ;
V_7 -> V_51 = F_1 ( V_3 ) ;
V_11 -> V_9 . V_15 = V_44 -> V_225 ? V_44 -> V_225 : 16 ;
memcpy ( & V_11 -> V_221 , V_44 -> V_222 , sizeof( V_11 -> V_221 ) ) ;
} else {
F_12 ( V_38 , L_48 ) ;
goto V_219;
}
if ( ! V_7 -> V_51 )
goto V_219;
strcpy ( V_11 -> V_71 . V_226 , V_7 -> V_3 -> V_227 ) ;
V_11 -> V_203 = V_228 ;
V_11 -> V_167 = V_7 -> V_167 ;
V_11 -> V_229 = & V_230 ;
V_11 -> V_71 = V_231 ;
V_7 -> V_185 = F_90 ( V_38 , L_49 ) ;
if ( F_11 ( V_7 -> V_185 ) ) {
V_165 = F_13 ( V_7 -> V_185 ) ;
goto V_219;
}
V_7 -> V_89 = F_90 ( V_38 , L_50 ) ;
if ( F_11 ( V_7 -> V_89 ) ) {
V_165 = F_13 ( V_7 -> V_89 ) ;
goto V_232;
}
F_59 ( V_7 ) ;
V_87 = F_91 ( & V_11 -> V_87 ,
struct V_217 , V_233 ) ;
F_34 ( & V_11 -> V_9 , & V_87 -> V_188 ) ;
F_35 ( & V_11 -> V_9 , V_11 ) ;
V_215 = F_92 ( V_3 , V_234 , 0 ) ;
if ( ! V_215 ) {
F_12 ( V_38 , L_51 ) ;
V_165 = - V_235 ;
goto V_236;
}
V_7 -> V_237 = F_93 ( V_3 , 0 ) ;
if ( V_7 -> V_237 < 0 ) {
F_12 ( V_38 , L_52 ) ;
V_165 = V_7 -> V_237 ;
goto V_236;
}
V_216 = F_92 ( V_3 , V_234 , 1 ) ;
if ( V_216 ) {
V_11 -> V_71 . V_73 = V_216 -> V_238 ;
V_11 -> V_71 . V_78 = F_94 ( V_216 ) ;
if ( ! F_95 ( V_11 -> V_71 . V_73 ,
V_11 -> V_71 . V_78 , V_3 -> V_227 ) ) {
V_165 = - V_239 ;
goto V_236;
}
V_11 -> V_79 = F_96 ( V_11 -> V_71 . V_73 , V_11 -> V_71 . V_78 ) ;
if ( ! V_11 -> V_79 ) {
V_165 = - V_83 ;
goto V_240;
}
} else {
V_165 = F_28 ( V_7 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_53 , V_165 ) ;
goto V_236;
}
}
V_11 -> V_71 . V_241 = V_215 -> V_238 ;
V_11 -> V_71 . V_242 = F_94 ( V_215 ) ;
if ( ! F_95 ( V_11 -> V_71 . V_241 ,
V_11 -> V_71 . V_242 , V_3 -> V_227 ) ) {
V_165 = - V_239 ;
goto V_243;
}
V_7 -> V_244 = F_96 ( V_11 -> V_71 . V_241 , V_11 -> V_71 . V_242 ) ;
if ( ! V_7 -> V_244 ) {
F_12 ( V_38 , L_54 ) ;
V_165 = - V_83 ;
goto V_245;
}
F_17 ( V_7 ) ;
V_165 = F_97 ( V_7 -> V_237 , F_52 , 0 , V_3 -> V_227 , V_11 ) ;
if ( V_165 ) {
F_12 ( V_38 , L_55 , V_165 ) ;
goto V_246;
}
F_98 ( & V_7 -> V_176 , F_54 ) ;
V_165 = F_56 ( V_7 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_56 , V_165 ) ;
goto V_247;
}
F_99 ( V_38 , V_11 ) ;
V_165 = F_100 ( V_11 ) ;
if ( V_165 < 0 ) {
F_12 ( V_38 , L_57 , V_165 ) ;
goto V_248;
}
F_18 ( V_7 , 1 ) ;
F_57 ( V_38 , L_58 ,
V_11 -> V_249 , V_11 -> V_71 . V_241 , V_7 -> V_244 , V_7 -> V_237 ) ;
return 0 ;
V_248:
F_99 ( V_38 , NULL ) ;
F_101 ( & V_11 -> V_184 ) ;
V_247:
F_102 ( & V_7 -> V_176 ) ;
F_103 ( V_7 -> V_237 , V_11 ) ;
V_246:
F_14 ( V_7 ) ;
F_104 ( V_7 -> V_244 ) ;
V_245:
F_105 ( V_11 -> V_71 . V_241 , V_11 -> V_71 . V_242 ) ;
V_243:
if ( V_216 )
F_104 ( V_11 -> V_79 ) ;
else
F_26 ( V_7 ) ;
V_240:
if ( V_216 )
F_105 ( V_11 -> V_71 . V_73 , V_11 -> V_71 . V_78 ) ;
V_236:
F_61 ( V_7 ) ;
F_106 ( V_7 -> V_89 ) ;
V_232:
F_106 ( V_7 -> V_185 ) ;
V_219:
F_107 ( V_11 ) ;
V_218:
F_37 ( V_38 , L_59 , V_90 ) ;
return V_165 ;
}
static int T_4 F_108 ( struct V_2 * V_3 )
{
struct V_77 * V_38 = & V_3 -> V_38 ;
struct V_10 * V_11 = F_109 ( V_38 ) ;
struct V_6 * V_7 ;
struct V_43 * V_44 ;
if ( ! V_11 || ! V_11 -> V_69 )
return 0 ;
V_7 = V_11 -> V_69 ;
V_44 = & V_7 -> V_44 ;
F_102 ( & V_7 -> V_176 ) ;
F_14 ( V_7 ) ;
F_18 ( V_7 , 0 ) ;
F_110 ( V_11 ) ;
F_61 ( V_7 ) ;
F_106 ( V_7 -> V_89 ) ;
F_106 ( V_7 -> V_185 ) ;
F_101 ( & V_11 -> V_184 ) ;
F_103 ( V_7 -> V_237 , V_11 ) ;
F_104 ( V_7 -> V_244 ) ;
F_105 ( V_11 -> V_71 . V_241 , V_11 -> V_71 . V_242 ) ;
if ( F_92 ( V_3 , V_234 , 1 ) ) {
F_104 ( V_11 -> V_79 ) ;
F_105 ( V_11 -> V_71 . V_73 , V_11 -> V_71 . V_78 ) ;
} else {
F_26 ( V_7 ) ;
}
F_107 ( V_11 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 , T_5 V_250 )
{
struct V_10 * V_11 = F_112 ( V_3 ) ;
struct V_6 * V_7 = V_11 -> V_69 ;
F_4 ( V_7 , V_154 , ~ 0UL ) ;
V_7 -> V_251 = F_5 ( V_7 , V_33 ) ;
F_4 ( V_7 , V_33 , 0 ) ;
F_18 ( V_7 , 0 ) ;
F_23 ( V_7 ) ;
F_61 ( V_7 ) ;
return 0 ;
}
static int F_113 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_112 ( V_3 ) ;
struct V_6 * V_7 = V_11 -> V_69 ;
F_59 ( V_7 ) ;
F_24 ( V_7 ) ;
F_18 ( V_7 , 1 ) ;
F_4 ( V_7 , V_33 , V_7 -> V_251 ) ;
F_4 ( V_7 , V_155 , V_156
| V_157 | V_158 ) ;
return 0 ;
}
