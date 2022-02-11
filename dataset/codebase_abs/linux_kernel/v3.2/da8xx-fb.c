static inline unsigned int F_1 ( unsigned int V_1 )
{
return ( unsigned int ) F_2 ( V_2 + ( V_1 ) ) ;
}
static inline void F_3 ( unsigned int V_3 , unsigned int V_1 )
{
F_4 ( V_3 , V_2 + ( V_1 ) ) ;
}
static inline void F_5 ( void )
{
T_1 V_4 ;
if ( V_5 == V_6 )
F_3 ( 0 , V_7 ) ;
V_4 = F_1 ( V_8 ) ;
if ( ! ( V_4 & V_9 ) )
F_3 ( V_4 | V_9 , V_8 ) ;
}
static inline void F_6 ( void )
{
T_1 V_4 ;
V_4 = F_1 ( V_8 ) ;
if ( V_4 & V_9 )
F_3 ( V_4 & ~ V_9 , V_8 ) ;
if ( V_5 == V_6 )
F_3 ( V_10 , V_7 ) ;
}
static void F_7 ( int V_11 , struct V_12 * V_13 )
{
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
V_16 = F_1 ( V_8 ) ;
V_16 &= ~ ( 3 << 20 ) ;
V_17 = F_1 ( V_19 ) ;
if ( V_11 == V_20 ) {
V_14 = V_13 -> V_21 ;
V_15 = V_13 -> V_22 ;
V_16 |= F_8 ( V_23 ) ;
if ( V_5 == V_24 ) {
V_17 |= V_25 ;
} else {
V_18 = F_1 ( V_26 ) |
V_27 |
V_28 ;
F_3 ( V_18 , V_26 ) ;
}
V_17 |= V_29 ;
F_3 ( V_14 , V_30 ) ;
F_3 ( V_15 , V_31 ) ;
F_3 ( V_14 , V_32 ) ;
F_3 ( V_15 , V_33 ) ;
} else if ( V_11 == V_34 ) {
V_14 = V_13 -> V_35 ;
V_15 = V_14 + V_13 -> V_36 - 1 ;
V_16 |= F_8 ( V_37 ) ;
if ( V_5 == V_24 ) {
V_16 |= V_38 ;
} else {
V_18 = F_1 ( V_26 ) |
V_39 ;
F_3 ( V_18 , V_26 ) ;
}
F_3 ( V_14 , V_30 ) ;
F_3 ( V_15 , V_31 ) ;
}
F_3 ( V_17 , V_19 ) ;
F_3 ( V_16 , V_8 ) ;
F_5 () ;
}
static int F_9 ( int V_40 )
{
T_1 V_4 ;
V_4 = F_1 ( V_19 ) & 0x00000001 ;
switch ( V_40 ) {
case 1 :
V_4 |= F_10 ( V_41 ) ;
break;
case 2 :
V_4 |= F_10 ( V_42 ) ;
break;
case 4 :
V_4 |= F_10 ( V_43 ) ;
break;
case 8 :
V_4 |= F_10 ( V_44 ) ;
break;
case 16 :
V_4 |= F_10 ( V_45 ) ;
break;
default:
return - V_46 ;
}
F_3 ( V_4 , V_19 ) ;
return 0 ;
}
static void F_11 ( int V_47 , int V_48 )
{
T_1 V_4 ;
V_4 = F_1 ( V_49 ) & 0xFFF00000 ;
V_4 |= F_12 ( V_47 ) |
F_13 ( V_48 ) ;
F_3 ( V_4 , V_49 ) ;
}
static void F_14 ( int V_50 , int V_51 ,
int V_52 )
{
T_1 V_4 ;
V_4 = F_1 ( V_53 ) & 0xf ;
V_4 |= ( ( V_50 & 0xff ) << 24 )
| ( ( V_52 & 0xff ) << 16 )
| ( ( V_51 & 0x3f ) << 10 ) ;
F_3 ( V_4 , V_53 ) ;
}
static void F_15 ( int V_50 , int V_51 ,
int V_52 )
{
T_1 V_4 ;
V_4 = F_1 ( V_54 ) & 0x3ff ;
V_4 |= ( ( V_50 & 0xff ) << 24 )
| ( ( V_52 & 0xff ) << 16 )
| ( ( V_51 & 0x3f ) << 10 ) ;
F_3 ( V_4 , V_54 ) ;
}
static int F_16 ( const struct V_55 * V_56 )
{
T_1 V_4 ;
T_1 V_18 ;
V_4 = F_1 ( V_8 ) & ~ ( V_57 |
V_58 |
V_59 ) ;
switch ( V_56 -> V_60 -> V_61 ) {
case V_62 :
V_4 |= V_59 ;
if ( V_56 -> V_63 )
V_4 |= V_58 ;
break;
case V_64 :
V_4 |= V_57 ;
if ( V_56 -> V_65 )
V_4 |= V_66 ;
break;
case V_67 :
if ( V_56 -> V_68 )
V_4 |= V_69 ;
break;
default:
return - V_46 ;
}
if ( V_5 == V_24 ) {
V_4 |= V_70 ;
} else {
V_18 = F_1 ( V_26 ) |
V_71 ;
F_3 ( V_18 , V_26 ) ;
}
F_3 ( V_4 , V_8 ) ;
V_4 = F_1 ( V_49 ) ;
if ( V_56 -> V_72 )
V_4 |= V_73 ;
else
V_4 &= ~ V_73 ;
if ( V_56 -> V_74 )
V_4 |= V_75 ;
else
V_4 &= ~ V_75 ;
if ( V_56 -> V_76 )
V_4 |= V_77 ;
else
V_4 &= ~ V_77 ;
if ( V_56 -> V_78 )
V_4 |= V_79 ;
else
V_4 &= ~ V_79 ;
F_3 ( V_4 , V_49 ) ;
return 0 ;
}
static int F_17 ( struct V_12 * V_13 , T_1 V_80 , T_1 V_81 ,
T_1 V_82 , T_1 V_83 )
{
T_1 V_4 ;
if ( V_5 == V_24 ) {
V_80 &= 0x3f0 ;
} else {
V_80 &= 0x7f0 ;
}
V_4 = F_1 ( V_53 ) ;
V_4 &= 0xfffffc00 ;
if ( V_5 == V_24 ) {
V_4 |= ( ( V_80 >> 4 ) - 1 ) << 4 ;
} else {
V_80 = ( V_80 >> 4 ) - 1 ;
V_4 |= ( ( V_80 & 0x3f ) << 4 ) | ( ( V_80 & 0x40 ) >> 3 ) ;
}
F_3 ( V_4 , V_53 ) ;
V_4 = F_1 ( V_54 ) ;
V_4 = ( ( V_81 - 1 ) & 0x3ff ) | ( V_4 & 0xfffffc00 ) ;
F_3 ( V_4 , V_54 ) ;
if ( V_5 == V_6 ) {
V_4 = F_1 ( V_49 ) ;
V_4 |= ( ( V_81 - 1 ) & 0x400 ) << 16 ;
F_3 ( V_4 , V_49 ) ;
}
V_4 = F_1 ( V_8 ) & ~ ( 1 << 8 ) ;
if ( V_83 )
V_4 |= V_84 ;
F_3 ( V_4 , V_8 ) ;
switch ( V_82 ) {
case 1 :
case 2 :
case 4 :
case 16 :
V_13 -> V_36 = 16 * 2 ;
break;
case 8 :
V_13 -> V_36 = 256 * 2 ;
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_18 ( unsigned V_85 , unsigned V_86 , unsigned V_87 ,
unsigned V_88 , unsigned V_89 ,
struct V_90 * V_91 )
{
struct V_12 * V_13 = V_91 -> V_13 ;
unsigned short * V_92 = ( unsigned short * ) V_13 -> V_93 ;
T_2 V_94 ;
int V_95 = 0 ;
if ( V_85 > 255 )
return 1 ;
if ( V_91 -> V_96 . V_97 == V_98 )
return 1 ;
if ( V_91 -> V_99 . V_100 == 8 ) {
V_86 >>= 4 ;
V_87 >>= 8 ;
V_88 >>= 12 ;
V_94 = ( V_86 & 0x0f00 ) ;
V_94 |= ( V_87 & 0x00f0 ) ;
V_94 |= ( V_88 & 0x000f ) ;
if ( V_92 [ V_85 ] != V_94 ) {
V_95 = 1 ;
V_92 [ V_85 ] = V_94 ;
}
} else if ( ( V_91 -> V_99 . V_100 == 16 ) && V_85 < 16 ) {
V_86 >>= ( 16 - V_91 -> V_99 . V_86 . V_101 ) ;
V_86 <<= V_91 -> V_99 . V_86 . V_102 ;
V_87 >>= ( 16 - V_91 -> V_99 . V_87 . V_101 ) ;
V_87 <<= V_91 -> V_99 . V_87 . V_102 ;
V_88 >>= ( 16 - V_91 -> V_99 . V_88 . V_101 ) ;
V_88 <<= V_91 -> V_99 . V_88 . V_102 ;
V_13 -> V_103 [ V_85 ] = V_86 | V_87 | V_88 ;
if ( V_92 [ 0 ] != 0x4000 ) {
V_95 = 1 ;
V_92 [ 0 ] = 0x4000 ;
}
}
if ( V_95 )
F_7 ( V_34 , V_13 ) ;
return 0 ;
}
static void F_19 ( struct V_12 * V_13 )
{
F_6 () ;
F_3 ( 0 , V_19 ) ;
F_3 ( 0 , V_8 ) ;
if ( V_5 == V_6 ) {
F_3 ( 0 , V_26 ) ;
F_3 ( V_10 , V_7 ) ;
F_3 ( 0 , V_7 ) ;
}
}
static void F_20 ( struct V_12 * V_13 )
{
unsigned int V_104 , div ;
V_104 = F_21 ( V_13 -> V_105 ) ;
div = V_104 / V_13 -> V_106 ;
F_3 ( F_22 ( div ) |
( V_107 & 0x1 ) , V_108 ) ;
if ( V_5 == V_6 )
F_3 ( V_109 | V_110 |
V_111 , V_112 ) ;
}
static int F_23 ( struct V_12 * V_13 , const struct V_55 * V_56 ,
struct V_113 * V_114 )
{
T_1 V_82 ;
int V_115 = 0 ;
F_19 ( V_13 ) ;
F_20 ( V_13 ) ;
if ( V_114 -> V_116 )
F_3 ( ( F_1 ( V_49 ) |
V_117 ) , V_49 ) ;
else
F_3 ( ( F_1 ( V_49 ) &
~ V_117 ) , V_49 ) ;
V_115 = F_9 ( V_56 -> V_118 ) ;
if ( V_115 < 0 )
return V_115 ;
F_11 ( V_56 -> V_119 , V_56 -> V_120 ) ;
F_15 ( V_114 -> V_121 , V_114 -> V_122 , V_114 -> V_123 ) ;
F_14 ( V_114 -> V_124 , V_114 -> V_125 , V_114 -> V_126 ) ;
V_115 = F_16 ( V_56 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( V_127 != V_56 -> V_60 -> V_128 )
return - V_46 ;
if ( V_56 -> V_82 <= V_56 -> V_60 -> V_129 &&
V_56 -> V_82 >= V_56 -> V_60 -> V_130 )
V_82 = V_56 -> V_82 ;
else
V_82 = V_56 -> V_60 -> V_129 ;
if ( V_82 == 12 )
V_82 = 16 ;
V_115 = F_17 ( V_13 , ( unsigned int ) V_114 -> V_80 ,
( unsigned int ) V_114 -> V_81 , V_82 ,
V_56 -> V_83 ) ;
if ( V_115 < 0 )
return V_115 ;
F_3 ( ( F_1 ( V_8 ) & 0xfff00fff ) |
( V_56 -> V_131 << 12 ) , V_8 ) ;
return 0 ;
}
static T_3 F_24 ( int V_132 , void * V_133 )
{
struct V_12 * V_13 = V_133 ;
T_1 V_134 = F_1 ( V_135 ) ;
T_1 V_18 ;
if ( ( V_134 & V_136 ) && ( V_134 & V_137 ) ) {
F_6 () ;
F_3 ( V_134 , V_135 ) ;
F_5 () ;
} else if ( V_134 & V_138 ) {
F_6 () ;
F_3 ( V_134 , V_135 ) ;
V_18 = F_1 ( V_139 ) |
( V_39 ) ;
F_3 ( V_18 , V_139 ) ;
F_7 ( V_20 , V_13 ) ;
} else {
F_3 ( V_134 , V_135 ) ;
if ( V_134 & V_140 ) {
F_3 ( V_13 -> V_21 ,
V_30 ) ;
F_3 ( V_13 -> V_22 ,
V_31 ) ;
V_13 -> V_141 = 1 ;
F_25 ( & V_13 -> V_142 ) ;
}
if ( V_134 & V_143 ) {
F_3 ( V_13 -> V_21 ,
V_32 ) ;
F_3 ( V_13 -> V_22 ,
V_33 ) ;
V_13 -> V_141 = 1 ;
F_25 ( & V_13 -> V_142 ) ;
}
}
F_3 ( 0 , V_144 ) ;
return V_145 ;
}
static T_3 F_26 ( int V_132 , void * V_133 )
{
struct V_12 * V_13 = V_133 ;
T_1 V_134 = F_1 ( V_146 ) ;
T_1 V_16 ;
if ( ( V_134 & V_136 ) && ( V_134 & V_137 ) ) {
F_6 () ;
F_3 ( V_134 , V_146 ) ;
F_5 () ;
} else if ( V_134 & V_138 ) {
F_6 () ;
F_3 ( V_134 , V_146 ) ;
V_16 = F_1 ( V_8 ) ;
V_16 &= ~ V_38 ;
F_3 ( V_16 , V_8 ) ;
F_7 ( V_20 , V_13 ) ;
} else {
F_3 ( V_134 , V_146 ) ;
if ( V_134 & V_140 ) {
F_3 ( V_13 -> V_21 ,
V_30 ) ;
F_3 ( V_13 -> V_22 ,
V_31 ) ;
V_13 -> V_141 = 1 ;
F_25 ( & V_13 -> V_142 ) ;
}
if ( V_134 & V_143 ) {
F_3 ( V_13 -> V_21 ,
V_32 ) ;
F_3 ( V_13 -> V_22 ,
V_33 ) ;
V_13 -> V_141 = 1 ;
F_25 ( & V_13 -> V_142 ) ;
}
}
return V_145 ;
}
static int F_27 ( struct V_147 * V_99 ,
struct V_90 * V_91 )
{
int V_148 = 0 ;
switch ( V_99 -> V_100 ) {
case 1 :
case 8 :
V_99 -> V_86 . V_102 = 0 ;
V_99 -> V_86 . V_101 = 8 ;
V_99 -> V_87 . V_102 = 0 ;
V_99 -> V_87 . V_101 = 8 ;
V_99 -> V_88 . V_102 = 0 ;
V_99 -> V_88 . V_101 = 8 ;
V_99 -> V_89 . V_102 = 0 ;
V_99 -> V_89 . V_101 = 0 ;
break;
case 4 :
V_99 -> V_86 . V_102 = 0 ;
V_99 -> V_86 . V_101 = 4 ;
V_99 -> V_87 . V_102 = 0 ;
V_99 -> V_87 . V_101 = 4 ;
V_99 -> V_88 . V_102 = 0 ;
V_99 -> V_88 . V_101 = 4 ;
V_99 -> V_89 . V_102 = 0 ;
V_99 -> V_89 . V_101 = 0 ;
break;
case 16 :
V_99 -> V_86 . V_102 = 11 ;
V_99 -> V_86 . V_101 = 5 ;
V_99 -> V_87 . V_102 = 5 ;
V_99 -> V_87 . V_101 = 6 ;
V_99 -> V_88 . V_102 = 0 ;
V_99 -> V_88 . V_101 = 5 ;
V_99 -> V_89 . V_102 = 0 ;
V_99 -> V_89 . V_101 = 0 ;
break;
default:
V_148 = - V_46 ;
}
V_99 -> V_86 . V_149 = 0 ;
V_99 -> V_87 . V_149 = 0 ;
V_99 -> V_88 . V_149 = 0 ;
V_99 -> V_89 . V_149 = 0 ;
return V_148 ;
}
static int F_28 ( struct V_150 * V_151 ,
unsigned long V_3 , void * V_152 )
{
struct V_12 * V_13 ;
V_13 = F_29 ( V_151 , struct V_12 , V_153 ) ;
if ( V_3 == V_154 ) {
F_6 () ;
} else if ( V_3 == V_155 ) {
F_20 ( V_13 ) ;
F_5 () ;
}
return 0 ;
}
static inline int F_30 ( struct V_12 * V_13 )
{
V_13 -> V_153 . V_156 = F_28 ;
return F_31 ( & V_13 -> V_153 ,
V_157 ) ;
}
static inline void F_32 ( struct V_12 * V_13 )
{
F_33 ( & V_13 -> V_153 ,
V_157 ) ;
}
static int T_4 F_34 ( struct V_158 * V_159 )
{
struct V_90 * V_91 = F_35 ( & V_159 -> V_159 ) ;
if ( V_91 ) {
struct V_12 * V_13 = V_91 -> V_13 ;
#ifdef F_36
F_32 ( V_13 ) ;
#endif
if ( V_13 -> V_160 )
V_13 -> V_160 ( 0 ) ;
F_6 () ;
F_3 ( 0 , V_8 ) ;
F_3 ( 0 , V_19 ) ;
F_37 ( V_91 ) ;
F_38 ( & V_91 -> V_161 ) ;
F_39 ( NULL , V_162 , V_13 -> V_93 ,
V_13 -> V_35 ) ;
F_39 ( NULL , V_13 -> V_163 , V_13 -> V_164 ,
V_13 -> V_165 ) ;
F_40 ( V_13 -> V_132 , V_13 ) ;
F_41 ( V_13 -> V_105 ) ;
F_42 ( V_13 -> V_105 ) ;
F_43 ( V_91 ) ;
F_44 ( ( void V_166 * ) V_2 ) ;
F_45 ( V_167 -> V_14 , F_46 ( V_167 ) ) ;
}
return 0 ;
}
static int F_47 ( struct V_90 * V_91 )
{
struct V_12 * V_13 = V_91 -> V_13 ;
int V_115 ;
V_13 -> V_141 = 0 ;
V_115 = F_48 ( V_13 -> V_142 ,
V_13 -> V_141 != 0 ,
V_13 -> V_168 ) ;
if ( V_115 < 0 )
return V_115 ;
if ( V_115 == 0 )
return - V_169 ;
return 0 ;
}
static int F_49 ( struct V_90 * V_91 , unsigned int V_170 ,
unsigned long V_133 )
{
struct V_171 V_172 ;
switch ( V_170 ) {
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
return - V_179 ;
case V_180 :
if ( F_50 ( & V_172 , ( char * ) V_133 ,
sizeof( struct V_171 ) ) )
return - V_181 ;
F_14 ( V_172 . V_50 ,
V_172 . V_51 ,
V_172 . V_52 ) ;
break;
case V_182 :
if ( F_50 ( & V_172 , ( char * ) V_133 ,
sizeof( struct V_171 ) ) )
return - V_181 ;
F_15 ( V_172 . V_50 ,
V_172 . V_51 ,
V_172 . V_52 ) ;
break;
case V_183 :
return F_47 ( V_91 ) ;
default:
return - V_46 ;
}
return 0 ;
}
static int F_51 ( int V_184 , struct V_90 * V_91 )
{
struct V_12 * V_13 = V_91 -> V_13 ;
int V_115 = 0 ;
if ( V_13 -> V_184 == V_184 )
return 0 ;
V_13 -> V_184 = V_184 ;
switch ( V_184 ) {
case V_185 :
if ( V_13 -> V_160 )
V_13 -> V_160 ( 1 ) ;
F_5 () ;
break;
case V_186 :
if ( V_13 -> V_160 )
V_13 -> V_160 ( 0 ) ;
F_6 () ;
break;
default:
V_115 = - V_46 ;
}
return V_115 ;
}
static int F_52 ( struct V_147 * V_99 ,
struct V_90 * V_187 )
{
int V_115 = 0 ;
struct V_147 V_188 ;
struct V_12 * V_13 = V_187 -> V_13 ;
struct V_189 * V_96 = & V_187 -> V_96 ;
unsigned int V_15 ;
unsigned int V_14 ;
if ( V_99 -> V_190 != V_187 -> V_99 . V_190 ||
V_99 -> V_191 != V_187 -> V_99 . V_191 ) {
memcpy ( & V_188 , & V_187 -> V_99 , sizeof( V_188 ) ) ;
V_188 . V_190 = V_99 -> V_190 ;
V_188 . V_191 = V_99 -> V_191 ;
if ( F_27 ( & V_188 , V_187 ) )
V_115 = - V_46 ;
else {
memcpy ( & V_187 -> V_99 , & V_188 , sizeof( V_188 ) ) ;
V_14 = V_96 -> V_192 +
V_188 . V_191 * V_96 -> V_193 +
V_188 . V_190 * V_187 -> V_99 . V_100 / 8 ;
V_15 = V_14 + V_187 -> V_99 . V_194 * V_96 -> V_193 - 1 ;
V_13 -> V_21 = V_14 ;
V_13 -> V_22 = V_15 ;
}
}
return V_115 ;
}
static int T_5 F_53 ( struct V_158 * V_195 )
{
struct V_196 * V_197 =
V_195 -> V_159 . V_198 ;
struct V_55 * V_199 ;
struct V_113 * V_200 ;
struct V_90 * V_201 ;
struct V_202 * V_203 = NULL ;
struct V_12 * V_13 ;
T_6 V_204 ;
int V_115 , V_205 ;
if ( V_197 == NULL ) {
F_54 ( & V_195 -> V_159 , L_1 ) ;
return - V_206 ;
}
V_167 = F_55 ( V_195 , V_207 , 0 ) ;
if ( ! V_167 ) {
F_54 ( & V_195 -> V_159 ,
L_2 ) ;
return - V_206 ;
}
V_204 = F_46 ( V_167 ) ;
V_167 = F_56 ( V_167 -> V_14 , V_204 , V_167 -> V_208 ) ;
if ( ! V_167 )
return - V_209 ;
V_2 = ( T_6 ) F_57 ( V_167 -> V_14 , V_204 ) ;
if ( ! V_2 ) {
V_115 = - V_209 ;
goto V_210;
}
V_203 = F_58 ( & V_195 -> V_159 , NULL ) ;
if ( F_59 ( V_203 ) ) {
F_54 ( & V_195 -> V_159 , L_3 ) ;
V_115 = - V_211 ;
goto V_212;
}
V_115 = F_60 ( V_203 ) ;
if ( V_115 )
goto V_213;
switch ( F_1 ( V_214 ) ) {
case 0x4C100102 :
V_5 = V_24 ;
break;
case 0x4F200800 :
V_5 = V_6 ;
break;
default:
F_61 ( & V_195 -> V_159 , L_4
L_5 ,
F_1 ( V_214 ) ) ;
V_5 = V_24 ;
break;
}
for ( V_205 = 0 , V_200 = V_215 ;
V_205 < F_62 ( V_215 ) ;
V_205 ++ , V_200 ++ ) {
if ( strcmp ( V_197 -> type , V_200 -> V_208 ) == 0 )
break;
}
if ( V_205 == F_62 ( V_215 ) ) {
F_54 ( & V_195 -> V_159 , L_6 ) ;
V_115 = - V_211 ;
goto V_216;
} else
F_63 ( & V_195 -> V_159 , L_7 ,
V_197 -> type ) ;
V_199 = (struct V_55 * ) V_197 -> V_217 ;
V_201 = F_64 ( sizeof( struct V_12 ) ,
& V_195 -> V_159 ) ;
if ( ! V_201 ) {
F_65 ( & V_195 -> V_159 , L_8 ) ;
V_115 = - V_218 ;
goto V_216;
}
V_13 = V_201 -> V_13 ;
V_13 -> V_105 = V_203 ;
V_13 -> V_106 = V_200 -> V_106 ;
if ( V_197 -> V_160 ) {
V_13 -> V_160 = V_197 -> V_160 ;
V_13 -> V_160 ( 1 ) ;
}
if ( F_23 ( V_13 , V_199 , V_200 ) < 0 ) {
F_54 ( & V_195 -> V_159 , L_9 ) ;
V_115 = - V_181 ;
goto V_219;
}
V_13 -> V_163 = V_200 -> V_80 * V_200 -> V_81 * V_199 -> V_82 ;
V_13 -> V_163 = F_66 ( V_13 -> V_163 / 8 ) ;
V_13 -> V_163 = V_13 -> V_163 * V_220 ;
V_13 -> V_164 = F_67 ( NULL ,
V_13 -> V_163 ,
( T_6 * ) & V_13 -> V_165 ,
V_221 | V_222 ) ;
if ( ! V_13 -> V_164 ) {
F_54 ( & V_195 -> V_159 ,
L_10 ) ;
V_115 = - V_46 ;
goto V_219;
}
V_201 -> V_223 = ( char V_166 * ) V_13 -> V_164 ;
V_224 . V_192 = V_13 -> V_165 ;
V_224 . V_225 = V_13 -> V_163 ;
V_224 . V_193 = ( V_200 -> V_80 * V_199 -> V_82 ) / 8 ;
V_13 -> V_21 = V_13 -> V_165 ;
V_13 -> V_22 = V_13 -> V_21 + V_200 -> V_81 *
V_224 . V_193 - 1 ;
V_13 -> V_93 = F_67 ( NULL ,
V_162 ,
( T_6 * )
& V_13 -> V_35 ,
V_221 | V_222 ) ;
if ( ! V_13 -> V_93 ) {
F_54 ( & V_195 -> V_159 ,
L_11 ) ;
V_115 = - V_46 ;
goto V_226;
}
memset ( V_13 -> V_93 , 0 , V_162 ) ;
V_13 -> V_132 = F_68 ( V_195 , 0 ) ;
if ( V_13 -> V_132 < 0 ) {
V_115 = - V_206 ;
goto V_227;
}
V_201 -> V_99 . V_100 = V_199 -> V_82 ;
V_228 . V_229 = V_200 -> V_80 ;
V_228 . V_230 = V_200 -> V_80 ;
V_228 . V_194 = V_200 -> V_81 ;
V_228 . V_231 = V_200 -> V_81 * V_220 ;
V_228 . V_232 =
V_199 -> V_60 -> V_61 == V_62 ? 1 : 0 ;
V_228 . V_100 = V_199 -> V_82 ;
V_228 . V_233 = V_200 -> V_125 ;
V_228 . V_234 = V_200 -> V_122 ;
V_201 -> V_235 = V_236 ;
V_201 -> V_96 = V_224 ;
V_201 -> V_99 = V_228 ;
V_201 -> V_237 = & V_238 ;
V_201 -> V_103 = V_13 -> V_103 ;
V_201 -> V_96 . V_97 = ( V_201 -> V_99 . V_100 <= 8 ) ?
V_239 : V_240 ;
V_115 = F_69 ( & V_201 -> V_161 , V_162 , 0 ) ;
if ( V_115 )
goto V_227;
V_201 -> V_161 . V_204 = V_13 -> V_36 ;
V_228 . V_241 = V_242 ;
F_70 ( V_201 , & V_228 ) ;
F_71 ( & V_195 -> V_159 , V_201 ) ;
F_72 ( & V_13 -> V_142 ) ;
V_13 -> V_168 = V_243 / 5 ;
if ( F_73 ( V_201 ) < 0 ) {
F_54 ( & V_195 -> V_159 ,
L_12 ) ;
V_115 = - V_46 ;
goto V_244;
}
#ifdef F_36
V_115 = F_30 ( V_13 ) ;
if ( V_115 ) {
F_54 ( & V_195 -> V_159 , L_13 ) ;
goto V_245;
}
#endif
if ( V_5 == V_24 )
V_246 = F_26 ;
else
V_246 = F_24 ;
V_115 = F_74 ( V_13 -> V_132 , V_246 , 0 ,
V_247 , V_13 ) ;
if ( V_115 )
goto V_248;
return 0 ;
V_248:
#ifdef F_36
F_32 ( V_13 ) ;
#endif
V_245:
F_37 ( V_201 ) ;
V_244:
F_38 ( & V_201 -> V_161 ) ;
V_227:
F_39 ( NULL , V_162 , V_13 -> V_93 ,
V_13 -> V_35 ) ;
V_226:
F_39 ( NULL , V_13 -> V_163 , V_13 -> V_164 , V_13 -> V_165 ) ;
V_219:
F_43 ( V_201 ) ;
V_216:
F_41 ( V_203 ) ;
V_213:
F_42 ( V_203 ) ;
V_212:
F_44 ( ( void V_166 * ) V_2 ) ;
V_210:
F_45 ( V_167 -> V_14 , V_204 ) ;
return V_115 ;
}
static int F_75 ( struct V_158 * V_159 , T_7 V_249 )
{
struct V_90 * V_91 = F_76 ( V_159 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_77 () ;
if ( V_13 -> V_160 )
V_13 -> V_160 ( 0 ) ;
F_78 ( V_91 , 1 ) ;
F_6 () ;
F_41 ( V_13 -> V_105 ) ;
F_79 () ;
return 0 ;
}
static int F_80 ( struct V_158 * V_159 )
{
struct V_90 * V_91 = F_76 ( V_159 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_77 () ;
if ( V_13 -> V_160 )
V_13 -> V_160 ( 1 ) ;
F_60 ( V_13 -> V_105 ) ;
F_5 () ;
F_78 ( V_91 , 0 ) ;
F_79 () ;
return 0 ;
}
static int T_8 F_81 ( void )
{
return F_82 ( & V_250 ) ;
}
static void T_9 F_83 ( void )
{
F_84 ( & V_250 ) ;
}
