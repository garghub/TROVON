static inline void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
V_2 -> V_3 = F_3 ( F_4 ( V_2 -> V_4 ) , L_1 ) ;
if ( F_5 ( V_2 -> V_3 ) )
V_2 -> V_3 = NULL ;
else {
V_2 -> V_4 -> V_5 = F_6 ( V_2 -> V_3 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> V_7 )
F_7 ( F_4 ( V_2 -> V_4 ) ,
L_2 ) ;
}
#endif
if ( V_2 -> V_3 == NULL ) {
V_2 -> V_4 -> V_5 = V_2 -> V_6 ?
V_2 -> V_6 -> V_7 :
V_8 | V_9 ;
}
}
static inline int F_8 ( struct V_1 * V_2 ,
unsigned char V_10 ,
unsigned int V_11 )
{
int V_12 ;
if ( V_2 -> V_3 ) {
int V_13 ;
if ( V_10 == V_14 ) {
V_13 = F_9 ( V_2 -> V_4 , V_2 -> V_3 , V_11 ) ;
if ( V_13 )
return V_13 ;
} else if ( V_10 == V_15 ) {
V_13 = F_9 ( V_2 -> V_4 , V_2 -> V_3 , 0 ) ;
if ( V_13 )
return V_13 ;
}
}
if ( ! V_2 -> V_3 && V_2 -> V_6 &&
F_10 ( V_2 -> V_6 -> V_16 ) ) {
V_12 = ( ( 1 << V_11 ) & V_2 -> V_6 -> V_7 ) ;
F_11 ( V_2 -> V_6 -> V_16 ,
! ! V_12 ^ V_2 -> V_6 -> V_17 ) ;
}
if ( ! V_2 -> V_3 && V_2 -> V_6 && V_2 -> V_6 -> V_18 )
return V_2 -> V_6 -> V_18 ( F_4 ( V_2 -> V_4 ) , V_11 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 -> V_19 + V_20 ) & V_21 ) {
unsigned long V_22 = 10000 ;
unsigned int V_23 ;
F_14 ( V_24 , V_2 -> V_19 + V_25 ) ;
do {
V_23 = F_13 ( V_2 -> V_19 + V_20 ) ;
if ( ! ( V_23 & V_21 ) )
break;
F_15 ( 1 ) ;
} while ( V_22 -- );
if ( V_23 & V_21 )
F_16 ( F_4 ( V_2 -> V_4 ) , L_3 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_26 )
{
unsigned long V_27 ;
F_18 ( & V_2 -> V_28 , V_27 ) ;
V_2 -> V_29 &= ~ V_26 ;
F_14 ( V_2 -> V_29 , V_2 -> V_19 + V_30 ) ;
F_19 ( & V_2 -> V_28 , V_27 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_26 )
{
unsigned long V_27 ;
F_18 ( & V_2 -> V_28 , V_27 ) ;
V_2 -> V_29 |= V_26 ;
F_14 ( V_2 -> V_29 , V_2 -> V_19 + V_30 ) ;
F_19 ( & V_2 -> V_28 , V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_33 * V_34 ;
enum V_35 V_36 ;
struct V_37 V_38 ;
struct V_39 * V_40 ;
unsigned int V_41 = V_32 -> V_42 ;
unsigned long long V_43 ;
unsigned int V_22 ;
int V_13 ;
V_2 -> V_32 = V_32 ;
if ( V_32 -> V_27 & V_44 )
V_41 = 0xffff ;
F_14 ( V_41 , V_2 -> V_19 + V_45 ) ;
F_14 ( V_32 -> V_46 , V_2 -> V_19 + V_47 ) ;
V_43 = ( unsigned long long ) V_32 -> V_48 * V_2 -> V_49 ;
F_22 ( V_43 , 1000000000UL ) ;
V_22 = ( unsigned int ) V_43 + ( V_32 -> V_50 << V_2 -> V_51 ) ;
F_14 ( ( V_22 + 255 ) / 256 , V_2 -> V_19 + V_52 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_53 = V_54 ;
V_38 . V_55 = V_54 ;
V_38 . V_56 = V_2 -> V_57 -> V_58 + V_59 ;
V_38 . V_60 = V_2 -> V_57 -> V_58 + V_61 ;
V_38 . V_62 = 32 ;
V_38 . V_63 = 32 ;
if ( V_32 -> V_27 & V_64 ) {
V_2 -> V_65 = V_66 ;
V_36 = V_67 ;
V_40 = V_2 -> V_68 ;
} else {
V_2 -> V_65 = V_69 ;
V_36 = V_70 ;
V_40 = V_2 -> V_71 ;
}
V_38 . V_36 = V_36 ;
V_13 = F_23 ( V_40 , & V_38 ) ;
if ( V_13 < 0 ) {
F_16 ( F_4 ( V_2 -> V_4 ) , L_4 ) ;
return;
}
V_2 -> V_72 = F_24 ( V_40 -> V_73 -> V_74 , V_32 -> V_75 , V_32 -> V_76 ,
V_2 -> V_65 ) ;
V_34 = F_25 ( V_40 , V_32 -> V_75 , V_2 -> V_72 , V_36 ,
V_77 ) ;
if ( ! V_34 ) {
F_16 ( F_4 ( V_2 -> V_4 ) , L_5 ) ;
return;
}
if ( ! ( V_32 -> V_27 & V_64 ) ) {
V_34 -> V_78 = V_79 ;
V_34 -> V_80 = V_2 ;
}
V_2 -> V_81 = F_26 ( V_34 ) ;
if ( ! F_27 () || V_32 -> V_27 & V_64 )
F_28 ( V_40 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_82 * V_83 , unsigned int V_84 )
{
F_30 ( V_2 -> V_83 != NULL ) ;
V_2 -> V_83 = V_83 ;
if ( V_83 -> V_27 & V_85 )
V_84 |= V_86 ;
#define F_31 ( T_1 ) ((x) & ~(MMC_RSP_BUSY|MMC_RSP_OPCODE))
switch ( F_31 ( F_32 ( V_83 ) ) ) {
case F_31 ( V_87 ) :
V_84 |= V_88 ;
break;
case F_31 ( V_89 ) :
V_84 |= V_90 ;
break;
case F_31 ( V_91 ) :
V_84 |= V_92 ;
break;
default:
break;
}
F_14 ( V_83 -> V_93 , V_2 -> V_19 + V_94 ) ;
F_14 ( V_83 -> V_95 >> 16 , V_2 -> V_19 + V_96 ) ;
F_14 ( V_83 -> V_95 & 0xffff , V_2 -> V_19 + V_97 ) ;
F_14 ( V_84 , V_2 -> V_19 + V_98 ) ;
F_14 ( V_2 -> V_51 , V_2 -> V_19 + V_99 ) ;
F_14 ( V_100 , V_2 -> V_19 + V_25 ) ;
F_17 ( V_2 , V_101 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
V_2 -> V_103 = NULL ;
V_2 -> V_83 = NULL ;
V_2 -> V_32 = NULL ;
F_34 ( V_2 -> V_4 , V_103 ) ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_104 )
{
struct V_82 * V_83 = V_2 -> V_83 ;
int V_105 ;
T_2 V_23 ;
if ( ! V_83 )
return 0 ;
V_2 -> V_83 = NULL ;
V_23 = F_13 ( V_2 -> V_19 + V_106 ) & 0xffff ;
for ( V_105 = 0 ; V_105 < 4 ; V_105 ++ ) {
T_2 V_107 = F_13 ( V_2 -> V_19 + V_106 ) & 0xffff ;
T_2 V_108 = F_13 ( V_2 -> V_19 + V_106 ) & 0xffff ;
V_83 -> V_109 [ V_105 ] = V_23 << 24 | V_107 << 8 | V_108 >> 8 ;
V_23 = V_108 ;
}
if ( V_104 & V_110 ) {
V_83 -> error = - V_111 ;
} else if ( V_104 & V_112 && V_83 -> V_27 & V_113 ) {
if ( F_27 () &&
( V_83 -> V_27 & V_114 && V_83 -> V_109 [ 0 ] & 0x80000000 ) )
F_36 ( L_6 , V_83 -> V_93 ) ;
else
V_83 -> error = - V_115 ;
}
F_20 ( V_2 , V_101 ) ;
if ( V_2 -> V_32 && ! V_83 -> error ) {
F_17 ( V_2 , V_116 ) ;
if ( F_27 () && V_2 -> V_32 -> V_27 & V_117 )
F_28 ( V_2 -> V_71 ) ;
} else {
F_33 ( V_2 , V_2 -> V_103 ) ;
}
return 1 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_104 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_39 * V_40 ;
if ( ! V_32 )
return 0 ;
if ( V_32 -> V_27 & V_64 )
V_40 = V_2 -> V_68 ;
else
V_40 = V_2 -> V_71 ;
F_38 ( V_40 -> V_73 -> V_74 ,
V_32 -> V_75 , V_32 -> V_76 , V_2 -> V_65 ) ;
if ( V_104 & V_118 )
V_32 -> error = - V_111 ;
else if ( V_104 & ( V_119 | V_120 ) )
V_32 -> error = - V_115 ;
if ( ! V_32 -> error )
V_32 -> V_121 = V_32 -> V_42 * V_32 -> V_46 ;
else
V_32 -> V_121 = 0 ;
F_20 ( V_2 , V_116 ) ;
V_2 -> V_32 = NULL ;
if ( V_2 -> V_103 -> V_122 ) {
F_12 ( V_2 ) ;
F_29 ( V_2 , V_2 -> V_103 -> V_122 , V_2 -> V_84 ) ;
} else {
F_33 ( V_2 , V_2 -> V_103 ) ;
}
return 1 ;
}
static T_3 F_39 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = V_124 ;
unsigned int V_125 ;
int V_126 = 0 ;
V_125 = F_13 ( V_2 -> V_19 + V_127 ) & ~ F_13 ( V_2 -> V_19 + V_30 ) ;
if ( V_125 ) {
unsigned V_104 = F_13 ( V_2 -> V_19 + V_20 ) ;
F_36 ( L_7 , V_125 , V_104 ) ;
if ( V_125 & V_101 )
V_126 |= F_35 ( V_2 , V_104 ) ;
if ( V_125 & V_116 )
V_126 |= F_37 ( V_2 , V_104 ) ;
if ( V_125 & V_128 ) {
F_40 ( V_2 -> V_4 ) ;
V_126 = 1 ;
}
}
return F_41 ( V_126 ) ;
}
static void F_42 ( struct V_129 * V_4 , struct V_102 * V_103 )
{
struct V_1 * V_2 = F_43 ( V_4 ) ;
unsigned int V_84 ;
F_30 ( V_2 -> V_103 != NULL ) ;
V_2 -> V_103 = V_103 ;
F_12 ( V_2 ) ;
V_84 = V_2 -> V_84 ;
V_2 -> V_84 &= ~ V_130 ;
if ( V_103 -> V_32 ) {
F_21 ( V_2 , V_103 -> V_32 ) ;
V_84 &= ~ V_86 ;
V_84 |= V_131 | V_132 ;
if ( V_103 -> V_32 -> V_27 & V_117 )
V_84 |= V_133 ;
if ( V_103 -> V_32 -> V_27 & V_44 )
V_84 |= V_134 ;
}
F_29 ( V_2 , V_103 -> V_83 , V_84 ) ;
}
static int F_44 ( struct V_129 * V_4 )
{
struct V_1 * V_2 = F_43 ( V_4 ) ;
if ( V_2 -> V_6 && F_10 ( V_2 -> V_6 -> V_135 ) )
return F_45 ( V_4 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> V_136 )
return ! ! V_2 -> V_6 -> V_136 ( F_4 ( V_4 ) ) ;
return - V_137 ;
}
static void F_46 ( struct V_129 * V_4 , struct V_138 * V_139 )
{
struct V_1 * V_2 = F_43 ( V_4 ) ;
if ( V_139 -> clock ) {
unsigned long V_140 = V_2 -> V_49 ;
unsigned int V_141 = V_140 / V_139 -> clock ;
if ( V_2 -> V_51 == V_142 )
F_47 ( V_2 -> V_141 ) ;
if ( V_139 -> clock == 26000000 ) {
V_2 -> V_51 = 7 ;
} else {
if ( ! V_141 )
V_141 = 1 ;
if ( V_140 / V_141 > V_139 -> clock )
V_141 <<= 1 ;
V_2 -> V_51 = F_48 ( V_141 ) - 1 ;
}
} else {
F_12 ( V_2 ) ;
if ( V_2 -> V_51 != V_142 ) {
V_2 -> V_51 = V_142 ;
F_49 ( V_2 -> V_141 ) ;
}
}
if ( V_2 -> V_10 != V_139 -> V_10 ) {
int V_13 ;
V_2 -> V_10 = V_139 -> V_10 ;
V_13 = F_8 ( V_2 , V_139 -> V_10 , V_139 -> V_11 ) ;
if ( V_13 ) {
F_16 ( F_4 ( V_4 ) , L_8 ) ;
return;
}
if ( V_139 -> V_10 == V_143 )
V_2 -> V_84 |= V_130 ;
}
if ( V_139 -> V_144 == V_145 )
V_2 -> V_84 |= V_146 ;
else
V_2 -> V_84 &= ~ V_146 ;
F_50 ( F_4 ( V_4 ) , L_9 ,
V_2 -> V_51 , V_2 -> V_84 ) ;
}
static void F_51 ( struct V_129 * V_2 , int V_147 )
{
struct V_1 * V_148 = F_43 ( V_2 ) ;
if ( V_147 )
F_17 ( V_148 , V_128 ) ;
else
F_20 ( V_148 , V_128 ) ;
}
static void V_79 ( void * V_149 )
{
struct V_1 * V_2 = V_149 ;
struct V_150 V_151 ;
enum V_152 V_153 ;
struct V_39 * V_40 ;
unsigned long V_27 ;
F_18 ( & V_2 -> V_28 , V_27 ) ;
if ( ! V_2 -> V_32 )
goto V_154;
if ( V_2 -> V_32 -> V_27 & V_64 )
V_40 = V_2 -> V_68 ;
else
V_40 = V_2 -> V_71 ;
V_153 = F_52 ( V_40 , V_2 -> V_81 , & V_151 ) ;
if ( F_53 ( V_153 == V_155 ) ) {
F_14 ( V_156 , V_2 -> V_19 + V_157 ) ;
} else {
F_54 ( L_10 , F_55 ( V_2 -> V_4 ) ,
V_2 -> V_32 -> V_27 & V_64 ? L_11 : L_12 ) ;
V_2 -> V_32 -> error = - V_158 ;
F_37 ( V_2 , 0 ) ;
}
V_154:
F_19 ( & V_2 -> V_28 , V_27 ) ;
}
static T_3 F_56 ( int V_123 , void * V_124 )
{
struct V_1 * V_2 = F_43 ( V_124 ) ;
F_57 ( V_124 , F_58 ( V_2 -> V_6 -> V_159 ) ) ;
return V_160 ;
}
static int F_59 ( struct V_161 * V_162 )
{
struct V_163 * V_164 = V_162 -> V_74 . V_165 ;
struct V_166 * V_6 ;
T_2 V_167 ;
if ( ! V_164 )
return 0 ;
V_6 = F_60 ( & V_162 -> V_74 , sizeof( * V_6 ) , V_168 ) ;
if ( ! V_6 )
return - V_169 ;
V_6 -> V_170 =
F_61 ( V_164 , L_13 , 0 ) ;
V_6 -> V_135 =
F_61 ( V_164 , L_14 , 0 ) ;
V_6 -> V_16 =
F_61 ( V_164 , L_15 , 0 ) ;
if ( F_62 ( V_164 , L_16 , & V_167 ) == 0 )
V_6 -> V_159 = V_167 ;
V_162 -> V_74 . V_171 = V_6 ;
return 0 ;
}
static int F_59 ( struct V_161 * V_162 )
{
return 0 ;
}
static int F_63 ( struct V_161 * V_162 )
{
struct V_129 * V_4 ;
struct V_1 * V_2 = NULL ;
struct V_172 * V_173 , * V_174 , * V_175 ;
struct V_176 V_177 , V_178 ;
int V_13 , V_123 , V_179 = - 1 , V_180 = - 1 , V_16 = - 1 ;
T_4 V_26 ;
V_13 = F_59 ( V_162 ) ;
if ( V_13 )
return V_13 ;
V_173 = F_64 ( V_162 , V_181 , 0 ) ;
V_123 = F_65 ( V_162 , 0 ) ;
if ( ! V_173 || V_123 < 0 )
return - V_182 ;
V_173 = F_66 ( V_173 -> V_58 , V_183 , V_184 ) ;
if ( ! V_173 )
return - V_185 ;
V_4 = F_67 ( sizeof( struct V_1 ) , & V_162 -> V_74 ) ;
if ( ! V_4 ) {
V_13 = - V_169 ;
goto V_186;
}
V_4 -> V_187 = & V_188 ;
V_4 -> V_189 = V_190 ;
V_4 -> V_191 = V_192 ;
V_4 -> V_193 = F_68 () ? 1023 : 2048 ;
V_4 -> V_194 = 65535 ;
V_2 = F_43 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_162 -> V_74 . V_171 ;
V_2 -> V_51 = V_142 ;
V_2 -> V_141 = F_69 ( & V_162 -> V_74 , NULL ) ;
if ( F_5 ( V_2 -> V_141 ) ) {
V_13 = F_70 ( V_2 -> V_141 ) ;
V_2 -> V_141 = NULL ;
goto V_186;
}
V_2 -> V_49 = F_71 ( V_2 -> V_141 ) ;
V_4 -> V_195 = ( V_2 -> V_49 + 63 ) / 64 ;
V_4 -> V_196 = ( F_72 () ) ? 26000000 : V_2 -> V_49 ;
F_1 ( V_2 ) ;
V_4 -> V_197 = 0 ;
V_2 -> V_84 = 0 ;
if ( ! F_68 () ) {
V_4 -> V_197 |= V_198 | V_199 ;
V_2 -> V_84 |= V_200 ;
if ( F_72 () )
V_4 -> V_197 |= V_201 |
V_202 ;
}
F_73 ( & V_2 -> V_28 ) ;
V_2 -> V_57 = V_173 ;
V_2 -> V_123 = V_123 ;
V_2 -> V_29 = V_203 ;
V_2 -> V_19 = F_74 ( V_173 -> V_58 , V_183 ) ;
if ( ! V_2 -> V_19 ) {
V_13 = - V_169 ;
goto V_186;
}
F_12 ( V_2 ) ;
F_14 ( 0 , V_2 -> V_19 + V_204 ) ;
F_14 ( 64 , V_2 -> V_19 + V_205 ) ;
F_14 ( V_2 -> V_29 , V_2 -> V_19 + V_30 ) ;
V_13 = F_75 ( V_2 -> V_123 , F_39 , 0 , V_184 , V_2 ) ;
if ( V_13 )
goto V_186;
F_76 ( V_162 , V_4 ) ;
if ( ! V_162 -> V_74 . V_165 ) {
V_174 = F_64 ( V_162 , V_206 , 0 ) ;
V_175 = F_64 ( V_162 , V_206 , 1 ) ;
if ( ! V_174 || ! V_175 ) {
V_13 = - V_182 ;
goto V_186;
}
V_177 . V_207 = V_208 ;
V_177 . V_209 = V_174 -> V_58 ;
V_178 . V_207 = V_208 ;
V_178 . V_209 = V_175 -> V_58 ;
}
F_77 ( V_26 ) ;
F_78 ( V_210 , V_26 ) ;
V_2 -> V_68 =
F_79 ( V_26 , V_211 ,
& V_177 , & V_162 -> V_74 , L_11 ) ;
if ( V_2 -> V_68 == NULL ) {
F_16 ( & V_162 -> V_74 , L_17 ) ;
V_13 = - V_212 ;
goto V_186;
}
V_2 -> V_71 =
F_79 ( V_26 , V_211 ,
& V_178 , & V_162 -> V_74 , L_12 ) ;
if ( V_2 -> V_71 == NULL ) {
F_16 ( & V_162 -> V_74 , L_18 ) ;
V_13 = - V_212 ;
goto V_186;
}
if ( V_2 -> V_6 ) {
V_179 = V_2 -> V_6 -> V_170 ;
V_180 = V_2 -> V_6 -> V_135 ;
V_16 = V_2 -> V_6 -> V_16 ;
}
if ( F_10 ( V_16 ) ) {
V_13 = F_80 ( & V_162 -> V_74 , V_16 ,
L_19 ) ;
if ( V_13 ) {
F_16 ( & V_162 -> V_74 , L_20 ,
V_16 ) ;
goto V_186;
}
F_81 ( V_16 ,
V_2 -> V_6 -> V_17 ) ;
}
if ( F_10 ( V_180 ) )
V_13 = F_82 ( V_4 , V_180 ) ;
if ( V_13 ) {
F_16 ( & V_162 -> V_74 , L_21 , V_180 ) ;
goto V_186;
} else {
V_4 -> V_197 |= V_2 -> V_6 -> V_213 ?
0 : V_214 ;
}
if ( F_10 ( V_179 ) )
V_13 = F_83 ( V_4 , V_179 , 0 ) ;
if ( V_13 ) {
F_16 ( & V_162 -> V_74 , L_22 , V_179 ) ;
goto V_186;
}
if ( V_2 -> V_6 && V_2 -> V_6 -> V_215 )
V_2 -> V_6 -> V_215 ( & V_162 -> V_74 , F_56 , V_4 ) ;
if ( F_10 ( V_16 ) && V_2 -> V_6 -> V_18 )
F_7 ( & V_162 -> V_74 , L_23 ) ;
if ( F_10 ( V_180 ) && V_2 -> V_6 -> V_136 )
F_7 ( & V_162 -> V_74 , L_24 ) ;
F_84 ( V_4 ) ;
return 0 ;
V_186:
if ( V_2 ) {
if ( V_2 -> V_68 )
F_85 ( V_2 -> V_68 ) ;
if ( V_2 -> V_71 )
F_85 ( V_2 -> V_71 ) ;
if ( V_2 -> V_19 )
F_86 ( V_2 -> V_19 ) ;
if ( V_2 -> V_141 )
F_87 ( V_2 -> V_141 ) ;
}
if ( V_4 )
F_88 ( V_4 ) ;
F_89 ( V_173 ) ;
return V_13 ;
}
static int F_90 ( struct V_161 * V_162 )
{
struct V_129 * V_4 = F_91 ( V_162 ) ;
int V_179 = - 1 , V_180 = - 1 , V_16 = - 1 ;
if ( V_4 ) {
struct V_1 * V_2 = F_43 ( V_4 ) ;
F_92 ( V_4 ) ;
if ( V_2 -> V_6 ) {
V_179 = V_2 -> V_6 -> V_170 ;
V_180 = V_2 -> V_6 -> V_135 ;
V_16 = V_2 -> V_6 -> V_16 ;
}
if ( V_2 -> V_3 )
F_93 ( V_2 -> V_3 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> exit )
V_2 -> V_6 -> exit ( & V_162 -> V_74 , V_4 ) ;
F_12 ( V_2 ) ;
F_14 ( V_216 | V_217 | V_218 | V_219 |
V_101 | V_220 | V_116 ,
V_2 -> V_19 + V_30 ) ;
F_94 ( V_2 -> V_123 , V_2 ) ;
F_95 ( V_2 -> V_68 ) ;
F_95 ( V_2 -> V_71 ) ;
F_85 ( V_2 -> V_68 ) ;
F_85 ( V_2 -> V_71 ) ;
F_86 ( V_2 -> V_19 ) ;
F_87 ( V_2 -> V_141 ) ;
F_89 ( V_2 -> V_57 ) ;
F_88 ( V_4 ) ;
}
return 0 ;
}
