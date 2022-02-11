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
if ( V_91 -> V_99 . V_100 == 4 ) {
if ( V_85 > 15 )
return 1 ;
if ( V_91 -> V_99 . V_101 ) {
V_94 = V_85 ;
} else {
V_86 >>= 4 ;
V_87 >>= 8 ;
V_88 >>= 12 ;
V_94 = ( V_86 & 0x0f00 ) ;
V_94 |= ( V_87 & 0x00f0 ) ;
V_94 |= ( V_88 & 0x000f ) ;
}
if ( V_85 == 0 )
V_94 |= 0x2000 ;
V_92 [ V_85 ] = V_94 ;
} else if ( V_91 -> V_99 . V_100 == 8 ) {
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
V_86 >>= ( 16 - V_91 -> V_99 . V_86 . V_102 ) ;
V_86 <<= V_91 -> V_99 . V_86 . V_103 ;
V_87 >>= ( 16 - V_91 -> V_99 . V_87 . V_102 ) ;
V_87 <<= V_91 -> V_99 . V_87 . V_103 ;
V_88 >>= ( 16 - V_91 -> V_99 . V_88 . V_102 ) ;
V_88 <<= V_91 -> V_99 . V_88 . V_103 ;
V_13 -> V_104 [ V_85 ] = V_86 | V_87 | V_88 ;
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
unsigned int V_105 , div ;
V_105 = F_21 ( V_13 -> V_106 ) ;
div = V_105 / V_13 -> V_107 ;
F_3 ( F_22 ( div ) |
( V_108 & 0x1 ) , V_109 ) ;
if ( V_5 == V_6 )
F_3 ( V_110 | V_111 |
V_112 , V_113 ) ;
}
static int F_23 ( struct V_12 * V_13 , const struct V_55 * V_56 ,
struct V_114 * V_115 )
{
T_1 V_82 ;
int V_116 = 0 ;
F_19 ( V_13 ) ;
F_20 ( V_13 ) ;
if ( V_115 -> V_117 )
F_3 ( ( F_1 ( V_49 ) |
V_118 ) , V_49 ) ;
else
F_3 ( ( F_1 ( V_49 ) &
~ V_118 ) , V_49 ) ;
V_116 = F_9 ( V_56 -> V_119 ) ;
if ( V_116 < 0 )
return V_116 ;
F_11 ( V_56 -> V_120 , V_56 -> V_121 ) ;
F_15 ( V_115 -> V_122 , V_115 -> V_123 , V_115 -> V_124 ) ;
F_14 ( V_115 -> V_125 , V_115 -> V_126 , V_115 -> V_127 ) ;
V_116 = F_16 ( V_56 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_128 != V_56 -> V_60 -> V_129 )
return - V_46 ;
if ( V_56 -> V_82 <= V_56 -> V_60 -> V_130 &&
V_56 -> V_82 >= V_56 -> V_60 -> V_131 )
V_82 = V_56 -> V_82 ;
else
V_82 = V_56 -> V_60 -> V_130 ;
if ( V_82 == 12 )
V_82 = 16 ;
V_116 = F_17 ( V_13 , ( unsigned int ) V_115 -> V_80 ,
( unsigned int ) V_115 -> V_81 , V_82 ,
V_56 -> V_83 ) ;
if ( V_116 < 0 )
return V_116 ;
F_3 ( ( F_1 ( V_8 ) & 0xfff00fff ) |
( V_56 -> V_132 << 12 ) , V_8 ) ;
return 0 ;
}
static T_3 F_24 ( int V_133 , void * V_134 )
{
struct V_12 * V_13 = V_134 ;
T_1 V_135 = F_1 ( V_136 ) ;
T_1 V_18 ;
if ( ( V_135 & V_137 ) && ( V_135 & V_138 ) ) {
F_6 () ;
F_3 ( V_135 , V_136 ) ;
F_5 () ;
} else if ( V_135 & V_139 ) {
F_6 () ;
F_3 ( V_135 , V_136 ) ;
V_18 = F_1 ( V_140 ) |
( V_39 ) ;
F_3 ( V_18 , V_140 ) ;
F_7 ( V_20 , V_13 ) ;
} else {
F_3 ( V_135 , V_136 ) ;
if ( V_135 & V_141 ) {
F_3 ( V_13 -> V_21 ,
V_30 ) ;
F_3 ( V_13 -> V_22 ,
V_31 ) ;
V_13 -> V_142 = 1 ;
F_25 ( & V_13 -> V_143 ) ;
}
if ( V_135 & V_144 ) {
F_3 ( V_13 -> V_21 ,
V_32 ) ;
F_3 ( V_13 -> V_22 ,
V_33 ) ;
V_13 -> V_142 = 1 ;
F_25 ( & V_13 -> V_143 ) ;
}
}
F_3 ( 0 , V_145 ) ;
return V_146 ;
}
static T_3 F_26 ( int V_133 , void * V_134 )
{
struct V_12 * V_13 = V_134 ;
T_1 V_135 = F_1 ( V_147 ) ;
T_1 V_16 ;
if ( ( V_135 & V_137 ) && ( V_135 & V_138 ) ) {
F_6 () ;
F_3 ( V_135 , V_147 ) ;
F_5 () ;
} else if ( V_135 & V_139 ) {
F_6 () ;
F_3 ( V_135 , V_147 ) ;
V_16 = F_1 ( V_8 ) ;
V_16 &= ~ V_38 ;
F_3 ( V_16 , V_8 ) ;
F_7 ( V_20 , V_13 ) ;
} else {
F_3 ( V_135 , V_147 ) ;
if ( V_135 & V_141 ) {
F_3 ( V_13 -> V_21 ,
V_30 ) ;
F_3 ( V_13 -> V_22 ,
V_31 ) ;
V_13 -> V_142 = 1 ;
F_25 ( & V_13 -> V_143 ) ;
}
if ( V_135 & V_144 ) {
F_3 ( V_13 -> V_21 ,
V_32 ) ;
F_3 ( V_13 -> V_22 ,
V_33 ) ;
V_13 -> V_142 = 1 ;
F_25 ( & V_13 -> V_143 ) ;
}
}
return V_146 ;
}
static int F_27 ( struct V_148 * V_99 ,
struct V_90 * V_91 )
{
int V_149 = 0 ;
switch ( V_99 -> V_100 ) {
case 1 :
case 8 :
V_99 -> V_86 . V_103 = 0 ;
V_99 -> V_86 . V_102 = 8 ;
V_99 -> V_87 . V_103 = 0 ;
V_99 -> V_87 . V_102 = 8 ;
V_99 -> V_88 . V_103 = 0 ;
V_99 -> V_88 . V_102 = 8 ;
V_99 -> V_89 . V_103 = 0 ;
V_99 -> V_89 . V_102 = 0 ;
V_99 -> V_150 = 0 ;
break;
case 4 :
V_99 -> V_86 . V_103 = 0 ;
V_99 -> V_86 . V_102 = 4 ;
V_99 -> V_87 . V_103 = 0 ;
V_99 -> V_87 . V_102 = 4 ;
V_99 -> V_88 . V_103 = 0 ;
V_99 -> V_88 . V_102 = 4 ;
V_99 -> V_89 . V_103 = 0 ;
V_99 -> V_89 . V_102 = 0 ;
V_99 -> V_150 = V_151 ;
break;
case 16 :
V_99 -> V_86 . V_103 = 11 ;
V_99 -> V_86 . V_102 = 5 ;
V_99 -> V_87 . V_103 = 5 ;
V_99 -> V_87 . V_102 = 6 ;
V_99 -> V_88 . V_103 = 0 ;
V_99 -> V_88 . V_102 = 5 ;
V_99 -> V_89 . V_103 = 0 ;
V_99 -> V_89 . V_102 = 0 ;
V_99 -> V_150 = 0 ;
break;
default:
V_149 = - V_46 ;
}
V_99 -> V_86 . V_152 = 0 ;
V_99 -> V_87 . V_152 = 0 ;
V_99 -> V_88 . V_152 = 0 ;
V_99 -> V_89 . V_152 = 0 ;
return V_149 ;
}
static int F_28 ( struct V_153 * V_154 ,
unsigned long V_3 , void * V_155 )
{
struct V_12 * V_13 ;
V_13 = F_29 ( V_154 , struct V_12 , V_156 ) ;
if ( V_3 == V_157 ) {
if ( V_13 -> V_158 != F_21 ( V_13 -> V_106 ) ) {
V_13 -> V_158 = F_21 ( V_13 -> V_106 ) ;
F_6 () ;
F_20 ( V_13 ) ;
F_5 () ;
}
}
return 0 ;
}
static inline int F_30 ( struct V_12 * V_13 )
{
V_13 -> V_156 . V_159 = F_28 ;
return F_31 ( & V_13 -> V_156 ,
V_160 ) ;
}
static inline void F_32 ( struct V_12 * V_13 )
{
F_33 ( & V_13 -> V_156 ,
V_160 ) ;
}
static int T_4 F_34 ( struct V_161 * V_162 )
{
struct V_90 * V_91 = F_35 ( & V_162 -> V_162 ) ;
if ( V_91 ) {
struct V_12 * V_13 = V_91 -> V_13 ;
#ifdef F_36
F_32 ( V_13 ) ;
#endif
if ( V_13 -> V_163 )
V_13 -> V_163 ( 0 ) ;
F_6 () ;
F_3 ( 0 , V_8 ) ;
F_3 ( 0 , V_19 ) ;
F_37 ( V_91 ) ;
F_38 ( & V_91 -> V_164 ) ;
F_39 ( NULL , V_165 , V_13 -> V_93 ,
V_13 -> V_35 ) ;
F_39 ( NULL , V_13 -> V_166 , V_13 -> V_167 ,
V_13 -> V_168 ) ;
F_40 ( V_13 -> V_133 , V_13 ) ;
F_41 ( V_13 -> V_106 ) ;
F_42 ( V_13 -> V_106 ) ;
F_43 ( V_91 ) ;
F_44 ( ( void V_169 * ) V_2 ) ;
F_45 ( V_170 -> V_14 , F_46 ( V_170 ) ) ;
}
return 0 ;
}
static int F_47 ( struct V_90 * V_91 )
{
struct V_12 * V_13 = V_91 -> V_13 ;
int V_116 ;
V_13 -> V_142 = 0 ;
V_116 = F_48 ( V_13 -> V_143 ,
V_13 -> V_142 != 0 ,
V_13 -> V_171 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_116 == 0 )
return - V_172 ;
return 0 ;
}
static int F_49 ( struct V_90 * V_91 , unsigned int V_173 ,
unsigned long V_134 )
{
struct V_174 V_175 ;
switch ( V_173 ) {
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
return - V_182 ;
case V_183 :
if ( F_50 ( & V_175 , ( char * ) V_134 ,
sizeof( struct V_174 ) ) )
return - V_184 ;
F_14 ( V_175 . V_50 ,
V_175 . V_51 ,
V_175 . V_52 ) ;
break;
case V_185 :
if ( F_50 ( & V_175 , ( char * ) V_134 ,
sizeof( struct V_174 ) ) )
return - V_184 ;
F_15 ( V_175 . V_50 ,
V_175 . V_51 ,
V_175 . V_52 ) ;
break;
case V_186 :
return F_47 ( V_91 ) ;
default:
return - V_46 ;
}
return 0 ;
}
static int F_51 ( int V_187 , struct V_90 * V_91 )
{
struct V_12 * V_13 = V_91 -> V_13 ;
int V_116 = 0 ;
if ( V_13 -> V_187 == V_187 )
return 0 ;
V_13 -> V_187 = V_187 ;
switch ( V_187 ) {
case V_188 :
if ( V_13 -> V_163 )
V_13 -> V_163 ( 1 ) ;
F_5 () ;
break;
case V_189 :
if ( V_13 -> V_163 )
V_13 -> V_163 ( 0 ) ;
F_6 () ;
break;
default:
V_116 = - V_46 ;
}
return V_116 ;
}
static int F_52 ( struct V_148 * V_99 ,
struct V_90 * V_190 )
{
int V_116 = 0 ;
struct V_148 V_191 ;
struct V_12 * V_13 = V_190 -> V_13 ;
struct V_192 * V_96 = & V_190 -> V_96 ;
unsigned int V_15 ;
unsigned int V_14 ;
if ( V_99 -> V_193 != V_190 -> V_99 . V_193 ||
V_99 -> V_194 != V_190 -> V_99 . V_194 ) {
memcpy ( & V_191 , & V_190 -> V_99 , sizeof( V_191 ) ) ;
V_191 . V_193 = V_99 -> V_193 ;
V_191 . V_194 = V_99 -> V_194 ;
if ( F_27 ( & V_191 , V_190 ) )
V_116 = - V_46 ;
else {
memcpy ( & V_190 -> V_99 , & V_191 , sizeof( V_191 ) ) ;
V_14 = V_96 -> V_195 +
V_191 . V_194 * V_96 -> V_196 +
V_191 . V_193 * V_190 -> V_99 . V_100 / 8 ;
V_15 = V_14 + V_190 -> V_99 . V_197 * V_96 -> V_196 - 1 ;
V_13 -> V_21 = V_14 ;
V_13 -> V_22 = V_15 ;
}
}
return V_116 ;
}
static unsigned int F_53 ( struct V_12 * V_13 )
{
unsigned int V_105 , div ;
unsigned int V_198 ;
unsigned long long V_199 = 1000000000000ULL ;
V_105 = F_21 ( V_13 -> V_106 ) ;
div = V_105 / V_13 -> V_107 ;
V_198 = ( V_105 / div ) ;
F_54 ( V_199 , V_198 ) ;
return V_199 ;
}
static int T_5 F_55 ( struct V_161 * V_200 )
{
struct V_201 * V_202 =
V_200 -> V_162 . V_203 ;
struct V_55 * V_204 ;
struct V_114 * V_205 ;
struct V_90 * V_206 ;
struct V_207 * V_208 = NULL ;
struct V_12 * V_13 ;
T_6 V_209 ;
int V_116 , V_210 ;
if ( V_202 == NULL ) {
F_56 ( & V_200 -> V_162 , L_1 ) ;
return - V_211 ;
}
V_170 = F_57 ( V_200 , V_212 , 0 ) ;
if ( ! V_170 ) {
F_56 ( & V_200 -> V_162 ,
L_2 ) ;
return - V_211 ;
}
V_209 = F_46 ( V_170 ) ;
V_170 = F_58 ( V_170 -> V_14 , V_209 , V_170 -> V_213 ) ;
if ( ! V_170 )
return - V_214 ;
V_2 = ( T_6 ) F_59 ( V_170 -> V_14 , V_209 ) ;
if ( ! V_2 ) {
V_116 = - V_214 ;
goto V_215;
}
V_208 = F_60 ( & V_200 -> V_162 , NULL ) ;
if ( F_61 ( V_208 ) ) {
F_56 ( & V_200 -> V_162 , L_3 ) ;
V_116 = - V_216 ;
goto V_217;
}
V_116 = F_62 ( V_208 ) ;
if ( V_116 )
goto V_218;
switch ( F_1 ( V_219 ) ) {
case 0x4C100102 :
V_5 = V_24 ;
break;
case 0x4F200800 :
V_5 = V_6 ;
break;
default:
F_63 ( & V_200 -> V_162 , L_4
L_5 ,
F_1 ( V_219 ) ) ;
V_5 = V_24 ;
break;
}
for ( V_210 = 0 , V_205 = V_220 ;
V_210 < F_64 ( V_220 ) ;
V_210 ++ , V_205 ++ ) {
if ( strcmp ( V_202 -> type , V_205 -> V_213 ) == 0 )
break;
}
if ( V_210 == F_64 ( V_220 ) ) {
F_56 ( & V_200 -> V_162 , L_6 ) ;
V_116 = - V_216 ;
goto V_221;
} else
F_65 ( & V_200 -> V_162 , L_7 ,
V_202 -> type ) ;
V_204 = (struct V_55 * ) V_202 -> V_222 ;
V_206 = F_66 ( sizeof( struct V_12 ) ,
& V_200 -> V_162 ) ;
if ( ! V_206 ) {
F_67 ( & V_200 -> V_162 , L_8 ) ;
V_116 = - V_223 ;
goto V_221;
}
V_13 = V_206 -> V_13 ;
V_13 -> V_106 = V_208 ;
#ifdef F_36
V_13 -> V_158 = F_21 ( V_208 ) ;
#endif
V_13 -> V_107 = V_205 -> V_107 ;
if ( V_202 -> V_163 ) {
V_13 -> V_163 = V_202 -> V_163 ;
V_13 -> V_163 ( 1 ) ;
}
if ( F_23 ( V_13 , V_204 , V_205 ) < 0 ) {
F_56 ( & V_200 -> V_162 , L_9 ) ;
V_116 = - V_184 ;
goto V_224;
}
V_13 -> V_166 = V_205 -> V_80 * V_205 -> V_81 * V_204 -> V_82 ;
V_13 -> V_166 = F_68 ( V_13 -> V_166 / 8 ) ;
V_13 -> V_166 = V_13 -> V_166 * V_225 ;
V_13 -> V_167 = F_69 ( NULL ,
V_13 -> V_166 ,
( T_6 * ) & V_13 -> V_168 ,
V_226 | V_227 ) ;
if ( ! V_13 -> V_167 ) {
F_56 ( & V_200 -> V_162 ,
L_10 ) ;
V_116 = - V_46 ;
goto V_224;
}
V_206 -> V_228 = ( char V_169 * ) V_13 -> V_167 ;
V_229 . V_195 = V_13 -> V_168 ;
V_229 . V_230 = V_13 -> V_166 ;
V_229 . V_196 = ( V_205 -> V_80 * V_204 -> V_82 ) / 8 ;
V_13 -> V_21 = V_13 -> V_168 ;
V_13 -> V_22 = V_13 -> V_21 + V_205 -> V_81 *
V_229 . V_196 - 1 ;
V_13 -> V_93 = F_69 ( NULL ,
V_165 ,
( T_6 * )
& V_13 -> V_35 ,
V_226 | V_227 ) ;
if ( ! V_13 -> V_93 ) {
F_56 ( & V_200 -> V_162 ,
L_11 ) ;
V_116 = - V_46 ;
goto V_231;
}
memset ( V_13 -> V_93 , 0 , V_165 ) ;
V_13 -> V_133 = F_70 ( V_200 , 0 ) ;
if ( V_13 -> V_133 < 0 ) {
V_116 = - V_211 ;
goto V_232;
}
V_206 -> V_99 . V_100 = V_204 -> V_82 ;
V_233 . V_234 = V_205 -> V_80 ;
V_233 . V_235 = V_205 -> V_80 ;
V_233 . V_197 = V_205 -> V_81 ;
V_233 . V_236 = V_205 -> V_81 * V_225 ;
V_233 . V_101 =
V_204 -> V_60 -> V_61 == V_62 ? 1 : 0 ;
V_233 . V_100 = V_204 -> V_82 ;
V_233 . V_237 = V_205 -> V_126 ;
V_233 . V_238 = V_205 -> V_123 ;
V_233 . V_239 = V_205 -> V_127 ;
V_233 . V_240 = V_205 -> V_125 ;
V_233 . V_241 = V_205 -> V_124 ;
V_233 . V_242 = V_205 -> V_122 ;
V_233 . V_243 = F_53 ( V_13 ) ;
V_206 -> V_244 = V_245 ;
V_206 -> V_96 = V_229 ;
V_206 -> V_99 = V_233 ;
V_206 -> V_246 = & V_247 ;
V_206 -> V_104 = V_13 -> V_104 ;
V_206 -> V_96 . V_97 = ( V_206 -> V_99 . V_100 <= 8 ) ?
V_248 : V_249 ;
V_116 = F_71 ( & V_206 -> V_164 , V_165 , 0 ) ;
if ( V_116 )
goto V_232;
V_206 -> V_164 . V_209 = V_13 -> V_36 ;
V_233 . V_250 = V_251 ;
F_72 ( V_206 , & V_233 ) ;
F_73 ( & V_200 -> V_162 , V_206 ) ;
F_74 ( & V_13 -> V_143 ) ;
V_13 -> V_171 = V_252 / 5 ;
if ( F_75 ( V_206 ) < 0 ) {
F_56 ( & V_200 -> V_162 ,
L_12 ) ;
V_116 = - V_46 ;
goto V_253;
}
#ifdef F_36
V_116 = F_30 ( V_13 ) ;
if ( V_116 ) {
F_56 ( & V_200 -> V_162 , L_13 ) ;
goto V_254;
}
#endif
if ( V_5 == V_24 )
V_255 = F_26 ;
else
V_255 = F_24 ;
V_116 = F_76 ( V_13 -> V_133 , V_255 , 0 ,
V_256 , V_13 ) ;
if ( V_116 )
goto V_257;
return 0 ;
V_257:
#ifdef F_36
F_32 ( V_13 ) ;
V_254:
#endif
F_37 ( V_206 ) ;
V_253:
F_38 ( & V_206 -> V_164 ) ;
V_232:
F_39 ( NULL , V_165 , V_13 -> V_93 ,
V_13 -> V_35 ) ;
V_231:
F_39 ( NULL , V_13 -> V_166 , V_13 -> V_167 , V_13 -> V_168 ) ;
V_224:
F_43 ( V_206 ) ;
V_221:
F_41 ( V_208 ) ;
V_218:
F_42 ( V_208 ) ;
V_217:
F_44 ( ( void V_169 * ) V_2 ) ;
V_215:
F_45 ( V_170 -> V_14 , V_209 ) ;
return V_116 ;
}
static int F_77 ( struct V_161 * V_162 , T_7 V_258 )
{
struct V_90 * V_91 = F_78 ( V_162 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_79 () ;
if ( V_13 -> V_163 )
V_13 -> V_163 ( 0 ) ;
F_80 ( V_91 , 1 ) ;
F_6 () ;
F_41 ( V_13 -> V_106 ) ;
F_81 () ;
return 0 ;
}
static int F_82 ( struct V_161 * V_162 )
{
struct V_90 * V_91 = F_78 ( V_162 ) ;
struct V_12 * V_13 = V_91 -> V_13 ;
F_79 () ;
if ( V_13 -> V_163 )
V_13 -> V_163 ( 1 ) ;
F_62 ( V_13 -> V_106 ) ;
F_5 () ;
F_80 ( V_91 , 0 ) ;
F_81 () ;
return 0 ;
}
static int T_8 F_83 ( void )
{
return F_84 ( & V_259 ) ;
}
static void T_9 F_85 ( void )
{
F_86 ( & V_259 ) ;
}
