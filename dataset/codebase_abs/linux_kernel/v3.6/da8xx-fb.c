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
F_3 ( V_7 , V_8 ) ;
F_6 ( 1 ) ;
if ( V_5 == V_6 )
F_3 ( 0 , V_8 ) ;
F_6 ( 1 ) ;
V_4 = F_1 ( V_9 ) ;
if ( ! ( V_4 & V_10 ) )
F_3 ( V_4 | V_10 , V_9 ) ;
}
static inline void F_7 ( void )
{
T_1 V_4 ;
V_4 = F_1 ( V_9 ) ;
if ( V_4 & V_10 )
F_3 ( V_4 & ~ V_10 , V_9 ) ;
}
static void F_8 ( int V_11 , struct V_12 * V_13 )
{
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
T_1 V_18 ;
V_16 = F_1 ( V_9 ) ;
V_16 &= ~ ( 3 << 20 ) ;
V_17 = F_1 ( V_19 ) ;
if ( V_11 == V_20 ) {
V_14 = V_13 -> V_21 ;
V_15 = V_13 -> V_22 ;
V_16 |= F_9 ( V_23 ) ;
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
V_16 |= F_9 ( V_37 ) ;
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
F_3 ( V_16 , V_9 ) ;
F_5 () ;
}
static int F_10 ( int V_40 , int V_41 )
{
T_1 V_4 ;
V_4 = F_1 ( V_19 ) & 0x00000001 ;
switch ( V_40 ) {
case 1 :
V_4 |= F_11 ( V_42 ) ;
break;
case 2 :
V_4 |= F_11 ( V_43 ) ;
break;
case 4 :
V_4 |= F_11 ( V_44 ) ;
break;
case 8 :
V_4 |= F_11 ( V_45 ) ;
break;
case 16 :
V_4 |= F_11 ( V_46 ) ;
break;
default:
return - V_47 ;
}
V_4 |= ( V_41 << 8 ) ;
F_3 ( V_4 , V_19 ) ;
return 0 ;
}
static void F_12 ( int V_48 , int V_49 )
{
T_1 V_4 ;
V_4 = F_1 ( V_50 ) & 0xFFF00000 ;
V_4 |= F_13 ( V_48 ) |
F_14 ( V_49 ) ;
F_3 ( V_4 , V_50 ) ;
}
static void F_15 ( int V_51 , int V_52 ,
int V_53 )
{
T_1 V_4 ;
V_4 = F_1 ( V_54 ) & 0xf ;
V_4 |= ( ( V_51 & 0xff ) << 24 )
| ( ( V_53 & 0xff ) << 16 )
| ( ( V_52 & 0x3f ) << 10 ) ;
F_3 ( V_4 , V_54 ) ;
}
static void F_16 ( int V_51 , int V_52 ,
int V_53 )
{
T_1 V_4 ;
V_4 = F_1 ( V_55 ) & 0x3ff ;
V_4 |= ( ( V_51 & 0xff ) << 24 )
| ( ( V_53 & 0xff ) << 16 )
| ( ( V_52 & 0x3f ) << 10 ) ;
F_3 ( V_4 , V_55 ) ;
}
static int F_17 ( const struct V_56 * V_57 )
{
T_1 V_4 ;
T_1 V_18 ;
V_4 = F_1 ( V_9 ) & ~ ( V_58 |
V_59 |
V_60 ) ;
switch ( V_57 -> V_61 -> V_62 ) {
case V_63 :
V_4 |= V_60 ;
if ( V_57 -> V_64 )
V_4 |= V_59 ;
break;
case V_65 :
V_4 |= V_58 ;
if ( V_57 -> V_66 )
V_4 |= V_67 ;
break;
case V_68 :
if ( V_57 -> V_69 )
V_4 |= V_70 ;
break;
default:
return - V_47 ;
}
if ( V_5 == V_24 ) {
V_4 |= V_71 ;
} else {
V_18 = F_1 ( V_26 ) |
V_72 ;
F_3 ( V_18 , V_26 ) ;
}
F_3 ( V_4 , V_9 ) ;
V_4 = F_1 ( V_50 ) ;
if ( V_57 -> V_73 )
V_4 |= V_74 ;
else
V_4 &= ~ V_74 ;
if ( V_57 -> V_75 )
V_4 |= V_76 ;
else
V_4 &= ~ V_76 ;
if ( V_57 -> V_77 )
V_4 |= V_78 ;
else
V_4 &= ~ V_78 ;
if ( V_57 -> V_79 )
V_4 |= V_80 ;
else
V_4 &= ~ V_80 ;
F_3 ( V_4 , V_50 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 , T_1 V_81 , T_1 V_82 ,
T_1 V_83 , T_1 V_84 )
{
T_1 V_4 ;
if ( V_5 == V_24 ) {
V_81 &= 0x3f0 ;
} else {
V_81 &= 0x7f0 ;
}
V_4 = F_1 ( V_54 ) ;
V_4 &= 0xfffffc00 ;
if ( V_5 == V_24 ) {
V_4 |= ( ( V_81 >> 4 ) - 1 ) << 4 ;
} else {
V_81 = ( V_81 >> 4 ) - 1 ;
V_4 |= ( ( V_81 & 0x3f ) << 4 ) | ( ( V_81 & 0x40 ) >> 3 ) ;
}
F_3 ( V_4 , V_54 ) ;
V_4 = F_1 ( V_55 ) ;
V_4 = ( ( V_82 - 1 ) & 0x3ff ) | ( V_4 & 0xfffffc00 ) ;
F_3 ( V_4 , V_55 ) ;
if ( V_5 == V_6 ) {
V_4 = F_1 ( V_50 ) ;
V_4 |= ( ( V_82 - 1 ) & 0x400 ) << 16 ;
F_3 ( V_4 , V_50 ) ;
}
V_4 = F_1 ( V_9 ) & ~ ( 1 << 8 ) ;
if ( V_84 )
V_4 |= V_85 ;
F_3 ( V_4 , V_9 ) ;
switch ( V_83 ) {
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
return - V_47 ;
}
return 0 ;
}
static int F_19 ( unsigned V_86 , unsigned V_87 , unsigned V_88 ,
unsigned V_89 , unsigned V_90 ,
struct V_91 * V_92 )
{
struct V_12 * V_13 = V_92 -> V_13 ;
unsigned short * V_93 = ( unsigned short * ) V_13 -> V_94 ;
T_2 V_95 ;
int V_96 = 0 ;
if ( V_86 > 255 )
return 1 ;
if ( V_92 -> V_97 . V_98 == V_99 )
return 1 ;
if ( V_92 -> V_100 . V_101 == 4 ) {
if ( V_86 > 15 )
return 1 ;
if ( V_92 -> V_100 . V_102 ) {
V_95 = V_86 ;
} else {
V_87 >>= 4 ;
V_88 >>= 8 ;
V_89 >>= 12 ;
V_95 = ( V_87 & 0x0f00 ) ;
V_95 |= ( V_88 & 0x00f0 ) ;
V_95 |= ( V_89 & 0x000f ) ;
}
if ( V_86 == 0 )
V_95 |= 0x2000 ;
V_93 [ V_86 ] = V_95 ;
} else if ( V_92 -> V_100 . V_101 == 8 ) {
V_87 >>= 4 ;
V_88 >>= 8 ;
V_89 >>= 12 ;
V_95 = ( V_87 & 0x0f00 ) ;
V_95 |= ( V_88 & 0x00f0 ) ;
V_95 |= ( V_89 & 0x000f ) ;
if ( V_93 [ V_86 ] != V_95 ) {
V_96 = 1 ;
V_93 [ V_86 ] = V_95 ;
}
} else if ( ( V_92 -> V_100 . V_101 == 16 ) && V_86 < 16 ) {
V_87 >>= ( 16 - V_92 -> V_100 . V_87 . V_103 ) ;
V_87 <<= V_92 -> V_100 . V_87 . V_104 ;
V_88 >>= ( 16 - V_92 -> V_100 . V_88 . V_103 ) ;
V_88 <<= V_92 -> V_100 . V_88 . V_104 ;
V_89 >>= ( 16 - V_92 -> V_100 . V_89 . V_103 ) ;
V_89 <<= V_92 -> V_100 . V_89 . V_104 ;
V_13 -> V_105 [ V_86 ] = V_87 | V_88 | V_89 ;
if ( V_93 [ 0 ] != 0x4000 ) {
V_96 = 1 ;
V_93 [ 0 ] = 0x4000 ;
}
}
if ( V_96 )
F_8 ( V_34 , V_13 ) ;
return 0 ;
}
static void F_20 ( struct V_12 * V_13 )
{
F_7 () ;
F_3 ( 0 , V_19 ) ;
F_3 ( 0 , V_9 ) ;
if ( V_5 == V_6 ) {
F_3 ( 0 , V_26 ) ;
F_3 ( V_7 , V_8 ) ;
F_3 ( 0 , V_8 ) ;
}
}
static void F_21 ( struct V_12 * V_13 )
{
unsigned int V_106 , div ;
V_106 = F_22 ( V_13 -> V_107 ) ;
div = V_106 / V_13 -> V_108 ;
F_3 ( F_23 ( div ) |
( V_109 & 0x1 ) , V_110 ) ;
if ( V_5 == V_6 )
F_3 ( V_111 | V_112 |
V_113 , V_114 ) ;
}
static int F_24 ( struct V_12 * V_13 , const struct V_56 * V_57 ,
struct V_115 * V_116 )
{
T_1 V_83 ;
int V_117 = 0 ;
F_20 ( V_13 ) ;
F_21 ( V_13 ) ;
if ( V_116 -> V_118 )
F_3 ( ( F_1 ( V_50 ) |
V_119 ) , V_50 ) ;
else
F_3 ( ( F_1 ( V_50 ) &
~ V_119 ) , V_50 ) ;
V_117 = F_10 ( V_57 -> V_120 , V_57 -> V_41 ) ;
if ( V_117 < 0 )
return V_117 ;
F_12 ( V_57 -> V_121 , V_57 -> V_122 ) ;
F_16 ( V_116 -> V_123 , V_116 -> V_124 , V_116 -> V_125 ) ;
F_15 ( V_116 -> V_126 , V_116 -> V_127 , V_116 -> V_128 ) ;
V_117 = F_17 ( V_57 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_129 != V_57 -> V_61 -> V_130 )
return - V_47 ;
if ( V_57 -> V_83 <= V_57 -> V_61 -> V_131 &&
V_57 -> V_83 >= V_57 -> V_61 -> V_132 )
V_83 = V_57 -> V_83 ;
else
V_83 = V_57 -> V_61 -> V_131 ;
if ( V_83 == 12 )
V_83 = 16 ;
V_117 = F_18 ( V_13 , ( unsigned int ) V_116 -> V_81 ,
( unsigned int ) V_116 -> V_82 , V_83 ,
V_57 -> V_84 ) ;
if ( V_117 < 0 )
return V_117 ;
F_3 ( ( F_1 ( V_9 ) & 0xfff00fff ) |
( V_57 -> V_133 << 12 ) , V_9 ) ;
return 0 ;
}
static T_3 F_25 ( int V_134 , void * V_135 )
{
struct V_12 * V_13 = V_135 ;
T_1 V_136 = F_1 ( V_137 ) ;
if ( ( V_136 & V_138 ) && ( V_136 & V_139 ) ) {
F_7 () ;
F_3 ( V_136 , V_137 ) ;
F_5 () ;
} else if ( V_136 & V_140 ) {
F_7 () ;
F_3 ( V_136 , V_137 ) ;
F_3 ( V_39 , V_141 ) ;
F_8 ( V_20 , V_13 ) ;
} else {
F_3 ( V_136 , V_137 ) ;
if ( V_136 & V_142 ) {
V_13 -> V_143 = 0 ;
F_3 ( V_13 -> V_21 ,
V_30 ) ;
F_3 ( V_13 -> V_22 ,
V_31 ) ;
V_13 -> V_144 = 1 ;
F_26 ( & V_13 -> V_145 ) ;
}
if ( V_136 & V_146 ) {
V_13 -> V_143 = 1 ;
F_3 ( V_13 -> V_21 ,
V_32 ) ;
F_3 ( V_13 -> V_22 ,
V_33 ) ;
V_13 -> V_144 = 1 ;
F_26 ( & V_13 -> V_145 ) ;
}
}
F_3 ( 0 , V_147 ) ;
return V_148 ;
}
static T_3 F_27 ( int V_134 , void * V_135 )
{
struct V_12 * V_13 = V_135 ;
T_1 V_136 = F_1 ( V_149 ) ;
T_1 V_16 ;
if ( ( V_136 & V_138 ) && ( V_136 & V_139 ) ) {
F_7 () ;
F_3 ( V_136 , V_149 ) ;
F_5 () ;
} else if ( V_136 & V_140 ) {
F_7 () ;
F_3 ( V_136 , V_149 ) ;
V_16 = F_1 ( V_9 ) ;
V_16 &= ~ V_38 ;
F_3 ( V_16 , V_9 ) ;
F_8 ( V_20 , V_13 ) ;
} else {
F_3 ( V_136 , V_149 ) ;
if ( V_136 & V_142 ) {
V_13 -> V_143 = 0 ;
F_3 ( V_13 -> V_21 ,
V_30 ) ;
F_3 ( V_13 -> V_22 ,
V_31 ) ;
V_13 -> V_144 = 1 ;
F_26 ( & V_13 -> V_145 ) ;
}
if ( V_136 & V_146 ) {
V_13 -> V_143 = 1 ;
F_3 ( V_13 -> V_21 ,
V_32 ) ;
F_3 ( V_13 -> V_22 ,
V_33 ) ;
V_13 -> V_144 = 1 ;
F_26 ( & V_13 -> V_145 ) ;
}
}
return V_148 ;
}
static int F_28 ( struct V_150 * V_100 ,
struct V_91 * V_92 )
{
int V_151 = 0 ;
switch ( V_100 -> V_101 ) {
case 1 :
case 8 :
V_100 -> V_87 . V_104 = 0 ;
V_100 -> V_87 . V_103 = 8 ;
V_100 -> V_88 . V_104 = 0 ;
V_100 -> V_88 . V_103 = 8 ;
V_100 -> V_89 . V_104 = 0 ;
V_100 -> V_89 . V_103 = 8 ;
V_100 -> V_90 . V_104 = 0 ;
V_100 -> V_90 . V_103 = 0 ;
V_100 -> V_152 = 0 ;
break;
case 4 :
V_100 -> V_87 . V_104 = 0 ;
V_100 -> V_87 . V_103 = 4 ;
V_100 -> V_88 . V_104 = 0 ;
V_100 -> V_88 . V_103 = 4 ;
V_100 -> V_89 . V_104 = 0 ;
V_100 -> V_89 . V_103 = 4 ;
V_100 -> V_90 . V_104 = 0 ;
V_100 -> V_90 . V_103 = 0 ;
V_100 -> V_152 = V_153 ;
break;
case 16 :
V_100 -> V_87 . V_104 = 11 ;
V_100 -> V_87 . V_103 = 5 ;
V_100 -> V_88 . V_104 = 5 ;
V_100 -> V_88 . V_103 = 6 ;
V_100 -> V_89 . V_104 = 0 ;
V_100 -> V_89 . V_103 = 5 ;
V_100 -> V_90 . V_104 = 0 ;
V_100 -> V_90 . V_103 = 0 ;
V_100 -> V_152 = 0 ;
break;
default:
V_151 = - V_47 ;
}
V_100 -> V_87 . V_154 = 0 ;
V_100 -> V_88 . V_154 = 0 ;
V_100 -> V_89 . V_154 = 0 ;
V_100 -> V_90 . V_154 = 0 ;
return V_151 ;
}
static int F_29 ( struct V_155 * V_156 ,
unsigned long V_3 , void * V_157 )
{
struct V_12 * V_13 ;
V_13 = F_30 ( V_156 , struct V_12 , V_158 ) ;
if ( V_3 == V_159 ) {
if ( V_13 -> V_160 != F_22 ( V_13 -> V_107 ) ) {
V_13 -> V_160 = F_22 ( V_13 -> V_107 ) ;
F_7 () ;
F_21 ( V_13 ) ;
F_5 () ;
}
}
return 0 ;
}
static inline int F_31 ( struct V_12 * V_13 )
{
V_13 -> V_158 . V_161 = F_29 ;
return F_32 ( & V_13 -> V_158 ,
V_162 ) ;
}
static inline void F_33 ( struct V_12 * V_13 )
{
F_34 ( & V_13 -> V_158 ,
V_162 ) ;
}
static int T_4 F_35 ( struct V_163 * V_164 )
{
struct V_91 * V_92 = F_36 ( & V_164 -> V_164 ) ;
if ( V_92 ) {
struct V_12 * V_13 = V_92 -> V_13 ;
#ifdef F_37
F_33 ( V_13 ) ;
#endif
if ( V_13 -> V_165 )
V_13 -> V_165 ( 0 ) ;
F_7 () ;
F_3 ( 0 , V_9 ) ;
F_3 ( 0 , V_19 ) ;
F_38 ( V_92 ) ;
F_39 ( & V_92 -> V_166 ) ;
F_40 ( NULL , V_167 , V_13 -> V_94 ,
V_13 -> V_35 ) ;
F_40 ( NULL , V_13 -> V_168 , V_13 -> V_169 ,
V_13 -> V_170 ) ;
F_41 ( V_13 -> V_134 , V_13 ) ;
F_42 ( V_13 -> V_107 ) ;
F_43 ( V_13 -> V_107 ) ;
F_44 ( V_92 ) ;
F_45 ( ( void V_171 * ) V_2 ) ;
F_46 ( V_172 -> V_14 , F_47 ( V_172 ) ) ;
}
return 0 ;
}
static int F_48 ( struct V_91 * V_92 )
{
struct V_12 * V_13 = V_92 -> V_13 ;
int V_117 ;
V_13 -> V_144 = 0 ;
V_117 = F_49 ( V_13 -> V_145 ,
V_13 -> V_144 != 0 ,
V_13 -> V_173 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_117 == 0 )
return - V_174 ;
return 0 ;
}
static int F_50 ( struct V_91 * V_92 , unsigned int V_175 ,
unsigned long V_135 )
{
struct V_176 V_177 ;
switch ( V_175 ) {
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
return - V_184 ;
case V_185 :
if ( F_51 ( & V_177 , ( char * ) V_135 ,
sizeof( struct V_176 ) ) )
return - V_186 ;
F_15 ( V_177 . V_51 ,
V_177 . V_52 ,
V_177 . V_53 ) ;
break;
case V_187 :
if ( F_51 ( & V_177 , ( char * ) V_135 ,
sizeof( struct V_176 ) ) )
return - V_186 ;
F_16 ( V_177 . V_51 ,
V_177 . V_52 ,
V_177 . V_53 ) ;
break;
case V_188 :
return F_48 ( V_92 ) ;
default:
return - V_47 ;
}
return 0 ;
}
static int F_52 ( int V_189 , struct V_91 * V_92 )
{
struct V_12 * V_13 = V_92 -> V_13 ;
int V_117 = 0 ;
if ( V_13 -> V_189 == V_189 )
return 0 ;
V_13 -> V_189 = V_189 ;
switch ( V_189 ) {
case V_190 :
F_5 () ;
if ( V_13 -> V_165 )
V_13 -> V_165 ( 1 ) ;
break;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
if ( V_13 -> V_165 )
V_13 -> V_165 ( 0 ) ;
F_7 () ;
break;
default:
V_117 = - V_47 ;
}
return V_117 ;
}
static int F_53 ( struct V_150 * V_100 ,
struct V_91 * V_195 )
{
int V_117 = 0 ;
struct V_150 V_196 ;
struct V_12 * V_13 = V_195 -> V_13 ;
struct V_197 * V_97 = & V_195 -> V_97 ;
unsigned int V_15 ;
unsigned int V_14 ;
unsigned long V_198 ;
if ( V_100 -> V_199 != V_195 -> V_100 . V_199 ||
V_100 -> V_200 != V_195 -> V_100 . V_200 ) {
memcpy ( & V_196 , & V_195 -> V_100 , sizeof( V_196 ) ) ;
V_196 . V_199 = V_100 -> V_199 ;
V_196 . V_200 = V_100 -> V_200 ;
if ( F_28 ( & V_196 , V_195 ) )
V_117 = - V_47 ;
else {
memcpy ( & V_195 -> V_100 , & V_196 , sizeof( V_196 ) ) ;
V_14 = V_97 -> V_201 +
V_196 . V_200 * V_97 -> V_202 +
V_196 . V_199 * V_195 -> V_100 . V_101 / 8 ;
V_15 = V_14 + V_195 -> V_100 . V_203 * V_97 -> V_202 - 1 ;
V_13 -> V_21 = V_14 ;
V_13 -> V_22 = V_15 ;
F_54 ( & V_13 -> V_204 ,
V_198 ) ;
if ( V_13 -> V_143 == 0 ) {
F_3 ( V_13 -> V_21 ,
V_30 ) ;
F_3 ( V_13 -> V_22 ,
V_31 ) ;
} else if ( V_13 -> V_143 == 1 ) {
F_3 ( V_13 -> V_21 ,
V_32 ) ;
F_3 ( V_13 -> V_22 ,
V_33 ) ;
}
F_55 ( & V_13 -> V_204 ,
V_198 ) ;
}
}
return V_117 ;
}
static unsigned int F_56 ( struct V_12 * V_13 )
{
unsigned int V_106 , div ;
unsigned int V_205 ;
unsigned long long V_206 = 1000000000000ULL ;
V_106 = F_22 ( V_13 -> V_107 ) ;
div = V_106 / V_13 -> V_108 ;
V_205 = ( V_106 / div ) ;
F_57 ( V_206 , V_205 ) ;
return V_206 ;
}
static int T_5 F_58 ( struct V_163 * V_207 )
{
struct V_208 * V_209 =
V_207 -> V_164 . V_210 ;
struct V_56 * V_211 ;
struct V_115 * V_212 ;
struct V_91 * V_213 ;
struct V_214 * V_215 = NULL ;
struct V_12 * V_13 ;
T_6 V_216 ;
int V_117 , V_217 ;
unsigned long V_218 ;
if ( V_209 == NULL ) {
F_59 ( & V_207 -> V_164 , L_1 ) ;
return - V_219 ;
}
V_172 = F_60 ( V_207 , V_220 , 0 ) ;
if ( ! V_172 ) {
F_59 ( & V_207 -> V_164 ,
L_2 ) ;
return - V_219 ;
}
V_216 = F_47 ( V_172 ) ;
V_172 = F_61 ( V_172 -> V_14 , V_216 , V_172 -> V_221 ) ;
if ( ! V_172 )
return - V_222 ;
V_2 = ( T_6 ) F_62 ( V_172 -> V_14 , V_216 ) ;
if ( ! V_2 ) {
V_117 = - V_222 ;
goto V_223;
}
V_215 = F_63 ( & V_207 -> V_164 , NULL ) ;
if ( F_64 ( V_215 ) ) {
F_59 ( & V_207 -> V_164 , L_3 ) ;
V_117 = - V_224 ;
goto V_225;
}
V_117 = F_65 ( V_215 ) ;
if ( V_117 )
goto V_226;
switch ( F_1 ( V_227 ) ) {
case 0x4C100102 :
V_5 = V_24 ;
break;
case 0x4F200800 :
V_5 = V_6 ;
break;
default:
F_66 ( & V_207 -> V_164 , L_4
L_5 ,
F_1 ( V_227 ) ) ;
V_5 = V_24 ;
break;
}
for ( V_217 = 0 , V_212 = V_228 ;
V_217 < F_67 ( V_228 ) ;
V_217 ++ , V_212 ++ ) {
if ( strcmp ( V_209 -> type , V_212 -> V_221 ) == 0 )
break;
}
if ( V_217 == F_67 ( V_228 ) ) {
F_59 ( & V_207 -> V_164 , L_6 ) ;
V_117 = - V_224 ;
goto V_229;
} else
F_68 ( & V_207 -> V_164 , L_7 ,
V_209 -> type ) ;
V_211 = (struct V_56 * ) V_209 -> V_230 ;
V_213 = F_69 ( sizeof( struct V_12 ) ,
& V_207 -> V_164 ) ;
if ( ! V_213 ) {
F_70 ( & V_207 -> V_164 , L_8 ) ;
V_117 = - V_231 ;
goto V_229;
}
V_13 = V_213 -> V_13 ;
V_13 -> V_107 = V_215 ;
#ifdef F_37
V_13 -> V_160 = F_22 ( V_215 ) ;
#endif
V_13 -> V_108 = V_212 -> V_108 ;
if ( V_209 -> V_165 ) {
V_13 -> V_165 = V_209 -> V_165 ;
V_13 -> V_165 ( 1 ) ;
}
if ( F_24 ( V_13 , V_211 , V_212 ) < 0 ) {
F_59 ( & V_207 -> V_164 , L_9 ) ;
V_117 = - V_186 ;
goto V_232;
}
V_13 -> V_168 = V_212 -> V_81 * V_212 -> V_82 * V_211 -> V_83 ;
V_218 = F_71 ( ( V_212 -> V_81 * V_211 -> V_83 ) / 8 , V_233 ) ;
V_13 -> V_168 = F_72 ( V_13 -> V_168 / 8 , V_218 ) ;
V_13 -> V_168 = V_13 -> V_168 * V_234 ;
V_13 -> V_169 = F_73 ( NULL ,
V_13 -> V_168 ,
( T_6 * ) & V_13 -> V_170 ,
V_235 | V_236 ) ;
if ( ! V_13 -> V_169 ) {
F_59 ( & V_207 -> V_164 ,
L_10 ) ;
V_117 = - V_47 ;
goto V_232;
}
V_213 -> V_237 = ( char V_171 * ) V_13 -> V_169 ;
V_238 . V_201 = V_13 -> V_170 ;
V_238 . V_239 = V_13 -> V_168 ;
V_238 . V_202 = ( V_212 -> V_81 * V_211 -> V_83 ) / 8 ;
V_13 -> V_21 = V_13 -> V_170 ;
V_13 -> V_22 = V_13 -> V_21 + V_212 -> V_82 *
V_238 . V_202 - 1 ;
V_13 -> V_94 = F_73 ( NULL ,
V_167 ,
( T_6 * )
& V_13 -> V_35 ,
V_235 | V_236 ) ;
if ( ! V_13 -> V_94 ) {
F_59 ( & V_207 -> V_164 ,
L_11 ) ;
V_117 = - V_47 ;
goto V_240;
}
memset ( V_13 -> V_94 , 0 , V_167 ) ;
V_13 -> V_134 = F_74 ( V_207 , 0 ) ;
if ( V_13 -> V_134 < 0 ) {
V_117 = - V_219 ;
goto V_241;
}
V_213 -> V_100 . V_101 = V_211 -> V_83 ;
V_242 . V_243 = V_212 -> V_81 ;
V_242 . V_244 = V_212 -> V_81 ;
V_242 . V_203 = V_212 -> V_82 ;
V_242 . V_245 = V_212 -> V_82 * V_234 ;
V_242 . V_102 =
V_211 -> V_61 -> V_62 == V_63 ? 1 : 0 ;
V_242 . V_101 = V_211 -> V_83 ;
V_242 . V_246 = V_212 -> V_127 ;
V_242 . V_247 = V_212 -> V_124 ;
V_242 . V_248 = V_212 -> V_128 ;
V_242 . V_249 = V_212 -> V_126 ;
V_242 . V_250 = V_212 -> V_125 ;
V_242 . V_251 = V_212 -> V_123 ;
V_242 . V_252 = F_56 ( V_13 ) ;
V_213 -> V_253 = V_254 ;
V_213 -> V_97 = V_238 ;
V_213 -> V_100 = V_242 ;
V_213 -> V_255 = & V_256 ;
V_213 -> V_105 = V_13 -> V_105 ;
V_213 -> V_97 . V_98 = ( V_213 -> V_100 . V_101 <= 8 ) ?
V_257 : V_258 ;
V_117 = F_75 ( & V_213 -> V_166 , V_167 , 0 ) ;
if ( V_117 )
goto V_241;
V_213 -> V_166 . V_216 = V_13 -> V_36 ;
V_242 . V_259 = V_260 ;
F_76 ( V_213 , & V_242 ) ;
F_77 ( & V_207 -> V_164 , V_213 ) ;
F_78 ( & V_13 -> V_145 ) ;
V_13 -> V_173 = V_261 / 5 ;
V_13 -> V_143 = - 1 ;
F_79 ( & V_13 -> V_204 ) ;
if ( F_80 ( V_213 ) < 0 ) {
F_59 ( & V_207 -> V_164 ,
L_12 ) ;
V_117 = - V_47 ;
goto V_262;
}
#ifdef F_37
V_117 = F_31 ( V_13 ) ;
if ( V_117 ) {
F_59 ( & V_207 -> V_164 , L_13 ) ;
goto V_263;
}
#endif
if ( V_5 == V_24 )
V_264 = F_27 ;
else
V_264 = F_25 ;
V_117 = F_81 ( V_13 -> V_134 , V_264 , 0 ,
V_265 , V_13 ) ;
if ( V_117 )
goto V_266;
return 0 ;
V_266:
#ifdef F_37
F_33 ( V_13 ) ;
V_263:
#endif
F_38 ( V_213 ) ;
V_262:
F_39 ( & V_213 -> V_166 ) ;
V_241:
F_40 ( NULL , V_167 , V_13 -> V_94 ,
V_13 -> V_35 ) ;
V_240:
F_40 ( NULL , V_13 -> V_168 , V_13 -> V_169 , V_13 -> V_170 ) ;
V_232:
F_44 ( V_213 ) ;
V_229:
F_42 ( V_215 ) ;
V_226:
F_43 ( V_215 ) ;
V_225:
F_45 ( ( void V_171 * ) V_2 ) ;
V_223:
F_46 ( V_172 -> V_14 , V_216 ) ;
return V_117 ;
}
static int F_82 ( struct V_163 * V_164 , T_7 V_267 )
{
struct V_91 * V_92 = F_83 ( V_164 ) ;
struct V_12 * V_13 = V_92 -> V_13 ;
F_84 () ;
if ( V_13 -> V_165 )
V_13 -> V_165 ( 0 ) ;
F_85 ( V_92 , 1 ) ;
F_7 () ;
F_42 ( V_13 -> V_107 ) ;
F_86 () ;
return 0 ;
}
static int F_87 ( struct V_163 * V_164 )
{
struct V_91 * V_92 = F_83 ( V_164 ) ;
struct V_12 * V_13 = V_92 -> V_13 ;
F_84 () ;
F_65 ( V_13 -> V_107 ) ;
F_5 () ;
if ( V_13 -> V_165 )
V_13 -> V_165 ( 1 ) ;
F_85 ( V_92 , 0 ) ;
F_86 () ;
return 0 ;
}
static int T_8 F_88 ( void )
{
return F_89 ( & V_268 ) ;
}
static void T_9 F_90 ( void )
{
F_91 ( & V_268 ) ;
}
