static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 == V_6 )
return V_5 -> V_7 ;
else
return F_3 ( V_5 -> V_5 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 == V_6 ) {
V_5 -> V_7 = V_8 ;
return 0 ;
} else
return F_5 ( V_5 -> V_5 , V_3 , 0xffff , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_7 ( V_5 -> V_5 ) ;
}
static int F_8 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_10 ) ;
struct V_13 * V_14 =
(struct V_13 * ) V_10 -> V_15 ;
int V_3 = V_14 -> V_3 ;
int V_16 ;
T_1 V_17 ;
V_16 = F_10 ( V_10 , V_12 ) ;
if ( V_16 < 0 )
return V_16 ;
V_17 = F_1 ( V_2 , V_3 ) ;
return F_4 ( V_2 , V_3 , V_17 | 0x0100 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_18 ,
F_13 ( V_18 ) ) ;
}
static int F_14 ( struct V_19 * V_20 ,
struct V_9 * V_10 , int V_21 )
{
T_1 V_3 , V_22 ;
V_3 = F_1 ( V_20 -> V_2 , V_23 ) ;
V_22 = F_1 ( V_20 -> V_2 , V_6 ) ;
if ( V_22 & ( ( 1 << V_24 ) |
( 1 << V_25 ) ) ) {
V_3 |= V_26 ;
} else {
V_3 &= ~ V_26 ;
}
if ( V_22 & ( ( 1 << V_27 ) |
( 1 << V_28 ) ) ) {
V_3 |= V_29 ;
} else {
V_3 &= ~ V_29 ;
}
F_4 ( V_20 -> V_2 , V_23 , V_3 ) ;
return 0 ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_9 * V_10 , int V_21 )
{
struct V_13 * V_14 =
(struct V_13 * ) V_10 -> V_15 ;
T_2 V_30 = V_14 -> V_31 ;
int V_16 = 0 ;
T_1 V_3 ;
switch ( V_30 ) {
case V_32 | ( V_33 << 8 ) :
V_3 = F_1 ( V_20 -> V_2 , V_34 ) ;
if ( V_3 & V_35 ) {
F_16 ( V_36
L_1 ) ;
V_16 = - 1 ;
}
break;
case V_32 | ( V_37 << 8 ) :
V_3 = F_1 ( V_20 -> V_2 , V_38 ) ;
if ( V_3 & V_39 ) {
F_16 ( V_36
L_2 ) ;
V_16 = - 1 ;
}
break;
case V_34 | ( V_35 << 8 ) :
V_3 = F_1 ( V_20 -> V_2 , V_32 ) ;
if ( V_3 & V_33 ) {
F_16 ( V_36
L_3 ) ;
V_16 = - 1 ;
}
break;
case V_38 | ( V_39 << 8 ) :
V_3 = F_1 ( V_20 -> V_2 , V_32 ) ;
if ( V_3 & V_37 ) {
F_16 ( V_36
L_4 ) ;
V_16 = - 1 ;
}
break;
}
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_41 ;
F_18 ( V_41 , V_42 ,
F_13 ( V_42 ) ) ;
F_19 ( V_41 , V_43 , F_13 ( V_43 ) ) ;
return 0 ;
}
static int F_20 ( struct V_44 * V_45 ,
int V_46 , unsigned int V_47 , int V_48 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_49 = V_47 ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 , struct F_21 * V_50 ,
unsigned int V_51 , unsigned int V_52 )
{
T_3 V_53 ;
unsigned int V_54 , V_55 , V_56 ;
V_50 -> V_57 = 2 ;
while ( V_52 * V_50 -> V_57 < 90000000 ||
V_52 * V_50 -> V_57 > 100000000 ) {
V_50 -> V_57 *= 2 ;
if ( V_50 -> V_57 > 32 ) {
F_22 ( V_5 -> V_5 -> V_58 ,
L_5 ,
V_52 ) ;
return - V_59 ;
}
}
V_56 = V_52 * V_50 -> V_57 ;
V_50 -> V_57 = V_50 -> V_57 >> 2 ;
if ( V_51 < 48000 )
V_50 -> V_60 = 1 ;
else
V_50 -> V_60 = 0 ;
if ( V_51 < 1000000 )
V_50 -> V_61 = 9 ;
else
V_50 -> V_61 = 0 ;
do {
if ( V_51 < 1000000 )
V_50 -> V_61 -- ;
else
V_50 -> V_61 ++ ;
if ( V_50 -> V_61 < 1 || V_50 -> V_61 > 8 ) {
F_22 ( V_5 -> V_5 -> V_58 ,
L_6 ) ;
return - V_59 ;
}
V_50 -> V_62 = V_56 / ( V_51 * V_50 -> V_61 ) ;
V_55 = V_56 % ( V_51 * V_50 -> V_61 ) ;
} while ( V_55 == 0 );
V_53 = V_63 * ( long long ) V_55 ;
F_23 ( V_53 , ( V_51 * V_50 -> V_61 ) ) ;
V_54 = V_53 & 0xFFFFFFFF ;
if ( ( V_54 % 10 ) >= 5 )
V_54 += 5 ;
V_50 -> V_64 = V_54 / 10 ;
F_24 ( V_5 -> V_5 -> V_58 ,
L_7 ,
V_51 , V_52 ,
V_50 -> V_62 , V_50 -> V_64 , V_50 -> V_61 , V_50 -> V_57 ) ;
return 0 ;
}
static int F_25 ( struct V_44 * V_45 , int V_65 ,
int V_66 , unsigned int V_67 ,
unsigned int V_68 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct F_21 V_50 ;
int V_16 ;
T_1 V_3 ;
if ( V_67 == V_5 -> V_69 && V_68 == V_5 -> V_70 )
return 0 ;
if ( V_68 ) {
V_16 = F_21 ( V_5 , & V_50 , V_67 , V_68 ) ;
if ( V_16 != 0 )
return V_16 ;
} else {
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
}
V_5 -> V_70 = V_68 ;
V_5 -> V_69 = V_67 ;
V_3 = F_1 ( V_2 , V_23 ) ;
V_3 &= ~ V_71 ;
F_4 ( V_2 , V_23 , V_3 ) ;
V_3 = F_1 ( V_2 , V_72 ) ;
V_3 &= ~ V_73 ;
F_4 ( V_2 , V_72 , V_3 ) ;
if ( ! V_68 )
return 0 ;
V_3 &= ~ ( V_74 | V_75 ) ;
V_3 |= V_76 | V_50 . V_61 ;
V_3 |= V_50 . V_60 << V_77 ;
F_4 ( V_2 , V_72 , V_3 ) ;
F_4 ( V_2 , V_78 , V_50 . V_64 ) ;
F_4 ( V_2 , V_79 , V_50 . V_62 ) ;
V_3 = F_1 ( V_2 , V_80 ) ;
V_3 &= V_81 ;
V_3 |= V_50 . V_57 ;
F_4 ( V_2 , V_80 , V_3 ) ;
return 0 ;
}
static int F_26 ( struct V_44 * V_45 ,
unsigned int V_82 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
T_1 V_83 , V_84 ;
V_83 = F_1 ( V_2 , V_85 ) ;
V_84 = F_1 ( V_2 , V_86 ) ;
switch ( V_82 & V_87 ) {
case V_88 :
V_84 &= ~ V_89 ;
break;
case V_90 :
V_84 |= V_89 ;
break;
default:
return - V_59 ;
}
V_83 &= ~ V_91 ;
switch ( V_82 & V_92 ) {
case V_93 :
V_83 |= V_94 ;
V_83 &= ~ V_95 ;
break;
case V_96 :
V_83 |= V_97 ;
V_83 &= ~ V_95 ;
break;
case V_98 :
V_83 |= V_99 ;
V_83 &= ~ V_95 ;
break;
case V_100 :
V_83 |= V_101 ;
V_83 &= ~ V_95 ;
break;
case V_102 :
V_83 |= V_101 | V_95 ;
break;
default:
return - V_59 ;
}
F_4 ( V_2 , V_85 , V_83 ) ;
F_4 ( V_2 , V_86 , V_84 ) ;
return 0 ;
}
static int F_27 ( struct V_44 * V_45 ,
int V_103 , int div )
{
struct V_1 * V_2 = V_45 -> V_2 ;
T_1 V_3 ;
switch ( V_103 ) {
case V_104 :
V_3 = F_1 ( V_2 , V_105 ) &
~ V_106 ;
F_4 ( V_2 , V_105 , V_3 | div ) ;
break;
case V_107 :
V_3 = F_1 ( V_2 , V_105 ) &
~ V_108 ;
F_4 ( V_2 , V_105 , V_3 | div ) ;
break;
case V_109 :
V_3 = F_1 ( V_2 , V_105 ) &
~ V_110 ;
F_4 ( V_2 , V_105 , V_3 | div ) ;
break;
case V_111 :
V_3 = F_1 ( V_2 , V_112 ) &
~ V_113 ;
F_4 ( V_2 , V_112 , V_3 | div ) ;
break;
default:
return - V_59 ;
}
return 0 ;
}
static int F_28 ( struct V_114 * V_115 ,
struct V_116 * V_117 ,
struct V_44 * V_118 )
{
struct V_119 * V_120 = V_115 -> V_121 ;
struct V_1 * V_2 = V_120 -> V_2 ;
T_1 V_83 = F_1 ( V_2 , V_85 ) ;
V_83 &= ~ V_122 ;
switch ( F_29 ( V_117 ) ) {
case V_123 :
break;
case V_124 :
V_83 |= V_125 ;
break;
case V_126 :
V_83 |= V_127 ;
break;
case V_128 :
V_83 |= V_129 ;
break;
}
F_4 ( V_2 , V_85 , V_83 ) ;
return 0 ;
}
static int F_30 ( struct V_44 * V_118 , int V_130 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
T_1 V_17 = F_1 ( V_2 , V_131 ) & ~ V_132 ;
if ( V_130 )
F_4 ( V_2 , V_131 , V_17 | V_132 ) ;
else
F_4 ( V_2 , V_131 , V_17 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_133 V_134 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_17 ;
int V_16 ;
switch ( V_134 ) {
case V_135 :
break;
case V_136 :
V_17 = F_1 ( V_2 , V_137 ) &
~ V_138 ;
F_4 ( V_2 , V_137 , V_17 | 0x2 ) ;
break;
case V_139 :
if ( V_2 -> V_41 . V_140 == V_141 ) {
V_16 = F_32 ( F_13 ( V_142 ) ,
& V_142 [ 0 ] ) ;
if ( V_16 != 0 ) {
F_22 ( V_5 -> V_5 -> V_58 ,
L_8 ,
V_16 ) ;
return V_16 ;
}
F_4 ( V_2 , V_137 ,
V_143 | V_144 ) ;
F_4 ( V_2 , V_145 , V_146 |
V_147 | V_148 ) ;
F_33 ( 50 ) ;
V_17 = F_1 ( V_2 , V_137 ) ;
V_17 |= 0x2 | V_149 ;
F_4 ( V_2 , V_137 , V_17 ) ;
F_4 ( V_2 , V_145 , V_146 |
V_147 | V_148 |
V_150 ) ;
F_4 ( V_2 , V_145 , V_150 ) ;
}
V_17 = F_1 ( V_2 , V_137 ) &
~ V_138 ;
F_4 ( V_2 , V_137 , V_17 | 0x4 ) ;
break;
case V_141 :
F_4 ( V_2 , V_145 , V_146 |
V_148 | V_150 ) ;
F_4 ( V_2 , V_145 , V_146 |
V_147 | V_148 |
V_150 ) ;
V_17 = F_1 ( V_2 , V_131 ) ;
F_4 ( V_2 , V_131 , V_17 | V_132 ) ;
V_17 = F_1 ( V_2 , V_137 ) ;
V_17 |= V_151 | V_152 |
V_153 | V_154 |
V_155 ;
F_4 ( V_2 , V_137 , V_17 ) ;
V_17 &= ~ V_138 ;
F_4 ( V_2 , V_137 , V_17 ) ;
F_33 ( 300 ) ;
F_4 ( V_2 , V_156 , V_157 |
V_158 | V_159 |
V_160 | V_161 |
V_162 ) ;
V_17 &= ~ V_149 ;
F_4 ( V_2 , V_137 , V_17 ) ;
F_4 ( V_2 , V_145 , 0x0 ) ;
V_16 = F_34 ( F_13 ( V_142 ) ,
& V_142 [ 0 ] ) ;
if ( V_16 != 0 )
return V_16 ;
break;
}
V_2 -> V_41 . V_140 = V_134 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_4 V_163 )
{
F_31 ( V_2 , V_141 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_139 ) ;
return 0 ;
}
static void F_37 ( struct V_164 * V_165 )
{
struct V_4 * V_166 = F_38 ( V_165 , struct V_4 ,
V_165 ) ;
struct V_1 * V_2 = V_166 -> V_2 ;
F_31 ( V_2 , V_139 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_40 ( V_2 -> V_58 ) ;
struct V_4 * V_166 ;
int V_16 ;
T_1 V_3 ;
V_166 = F_41 ( sizeof( struct V_4 ) , V_167 ) ;
if ( V_166 == NULL )
return - V_168 ;
F_42 ( V_2 , V_166 ) ;
V_2 -> V_169 = V_166 -> V_5 = V_5 ;
V_166 -> V_2 = V_2 ;
V_16 = F_43 ( V_5 -> V_58 ,
F_13 ( V_142 ) , & V_142 [ 0 ] ) ;
if ( V_16 != 0 ) {
F_22 ( V_2 -> V_58 , L_9 , V_16 ) ;
goto V_170;
}
F_44 ( & V_166 -> V_165 , F_37 ) ;
F_6 ( V_2 ) ;
V_3 = F_1 ( V_2 , V_137 ) ;
F_4 ( V_2 , V_137 , V_3 | V_143 ) ;
V_3 = F_1 ( V_2 , V_171 ) ;
F_4 ( V_2 , V_171 ,
V_3 & V_172 ) ;
V_3 = F_1 ( V_2 , V_173 ) ;
F_4 ( V_2 , V_173 ,
V_3 & V_172 ) ;
F_4 ( V_2 , V_174 , 0x50 | ( 1 << 8 ) ) ;
F_4 ( V_2 , V_175 , 0x50 | ( 1 << 8 ) ) ;
if ( ! F_45 ( & V_166 -> V_165 ) ) {
V_16 = - V_59 ;
goto V_176;
}
F_11 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
V_176:
F_46 ( F_13 ( V_142 ) , V_142 ) ;
V_170:
F_47 ( V_166 ) ;
return V_16 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_166 = F_2 ( V_2 ) ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_137 ) ;
F_4 ( V_2 , V_137 ,
V_3 & ( ~ V_143 ) ) ;
F_46 ( F_13 ( V_142 ) , V_142 ) ;
F_47 ( V_166 ) ;
return 0 ;
}
static int T_5 F_49 ( struct V_177 * V_178 )
{
return F_50 ( & V_178 -> V_58 , & V_179 ,
& V_180 , 1 ) ;
}
static int T_6 F_51 ( struct V_177 * V_178 )
{
F_52 ( & V_178 -> V_58 ) ;
return 0 ;
}
static T_7 int F_53 ( void )
{
return F_54 ( & V_181 ) ;
}
static T_8 void F_55 ( void )
{
F_56 ( & V_181 ) ;
}
