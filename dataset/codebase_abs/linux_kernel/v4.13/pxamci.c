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
F_14 ( V_41 , V_2 -> V_19 + V_44 ) ;
F_14 ( V_32 -> V_45 , V_2 -> V_19 + V_46 ) ;
V_43 = ( unsigned long long ) V_32 -> V_47 * V_2 -> V_48 ;
F_22 ( V_43 , 1000000000UL ) ;
V_22 = ( unsigned int ) V_43 + ( V_32 -> V_49 << V_2 -> V_50 ) ;
F_14 ( ( V_22 + 255 ) / 256 , V_2 -> V_19 + V_51 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_52 = V_53 ;
V_38 . V_54 = V_53 ;
V_38 . V_55 = V_2 -> V_56 -> V_57 + V_58 ;
V_38 . V_59 = V_2 -> V_56 -> V_57 + V_60 ;
V_38 . V_61 = 32 ;
V_38 . V_62 = 32 ;
if ( V_32 -> V_27 & V_63 ) {
V_2 -> V_64 = V_65 ;
V_36 = V_66 ;
V_40 = V_2 -> V_67 ;
} else {
V_2 -> V_64 = V_68 ;
V_36 = V_69 ;
V_40 = V_2 -> V_70 ;
}
V_38 . V_36 = V_36 ;
V_13 = F_23 ( V_40 , & V_38 ) ;
if ( V_13 < 0 ) {
F_16 ( F_4 ( V_2 -> V_4 ) , L_4 ) ;
return;
}
V_2 -> V_71 = F_24 ( V_40 -> V_72 -> V_73 , V_32 -> V_74 , V_32 -> V_75 ,
V_2 -> V_64 ) ;
V_34 = F_25 ( V_40 , V_32 -> V_74 , V_2 -> V_71 , V_36 ,
V_76 ) ;
if ( ! V_34 ) {
F_16 ( F_4 ( V_2 -> V_4 ) , L_5 ) ;
return;
}
if ( ! ( V_32 -> V_27 & V_63 ) ) {
V_34 -> V_77 = V_78 ;
V_34 -> V_79 = V_2 ;
}
V_2 -> V_80 = F_26 ( V_34 ) ;
if ( ! F_27 () || V_32 -> V_27 & V_63 )
F_28 ( V_40 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_81 * V_82 , unsigned int V_83 )
{
F_30 ( V_2 -> V_82 != NULL ) ;
V_2 -> V_82 = V_82 ;
if ( V_82 -> V_27 & V_84 )
V_83 |= V_85 ;
#define F_31 ( T_1 ) ((x) & ~(MMC_RSP_BUSY|MMC_RSP_OPCODE))
switch ( F_31 ( F_32 ( V_82 ) ) ) {
case F_31 ( V_86 ) :
V_83 |= V_87 ;
break;
case F_31 ( V_88 ) :
V_83 |= V_89 ;
break;
case F_31 ( V_90 ) :
V_83 |= V_91 ;
break;
default:
break;
}
F_14 ( V_82 -> V_92 , V_2 -> V_19 + V_93 ) ;
F_14 ( V_82 -> V_94 >> 16 , V_2 -> V_19 + V_95 ) ;
F_14 ( V_82 -> V_94 & 0xffff , V_2 -> V_19 + V_96 ) ;
F_14 ( V_83 , V_2 -> V_19 + V_97 ) ;
F_14 ( V_2 -> V_50 , V_2 -> V_19 + V_98 ) ;
F_14 ( V_99 , V_2 -> V_19 + V_25 ) ;
F_17 ( V_2 , V_100 ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
V_2 -> V_102 = NULL ;
V_2 -> V_82 = NULL ;
V_2 -> V_32 = NULL ;
F_34 ( V_2 -> V_4 , V_102 ) ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_103 )
{
struct V_81 * V_82 = V_2 -> V_82 ;
int V_104 ;
T_2 V_23 ;
if ( ! V_82 )
return 0 ;
V_2 -> V_82 = NULL ;
V_23 = F_13 ( V_2 -> V_19 + V_105 ) & 0xffff ;
for ( V_104 = 0 ; V_104 < 4 ; V_104 ++ ) {
T_2 V_106 = F_13 ( V_2 -> V_19 + V_105 ) & 0xffff ;
T_2 V_107 = F_13 ( V_2 -> V_19 + V_105 ) & 0xffff ;
V_82 -> V_108 [ V_104 ] = V_23 << 24 | V_106 << 8 | V_107 >> 8 ;
V_23 = V_107 ;
}
if ( V_103 & V_109 ) {
V_82 -> error = - V_110 ;
} else if ( V_103 & V_111 && V_82 -> V_27 & V_112 ) {
if ( F_27 () &&
( V_82 -> V_27 & V_113 && V_82 -> V_108 [ 0 ] & 0x80000000 ) )
F_36 ( L_6 , V_82 -> V_92 ) ;
else
V_82 -> error = - V_114 ;
}
F_20 ( V_2 , V_100 ) ;
if ( V_2 -> V_32 && ! V_82 -> error ) {
F_17 ( V_2 , V_115 ) ;
if ( F_27 () && V_2 -> V_32 -> V_27 & V_116 )
F_28 ( V_2 -> V_70 ) ;
} else {
F_33 ( V_2 , V_2 -> V_102 ) ;
}
return 1 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_103 )
{
struct V_31 * V_32 = V_2 -> V_32 ;
struct V_39 * V_40 ;
if ( ! V_32 )
return 0 ;
if ( V_32 -> V_27 & V_63 )
V_40 = V_2 -> V_67 ;
else
V_40 = V_2 -> V_70 ;
F_38 ( V_40 -> V_72 -> V_73 ,
V_32 -> V_74 , V_32 -> V_75 , V_2 -> V_64 ) ;
if ( V_103 & V_117 )
V_32 -> error = - V_110 ;
else if ( V_103 & ( V_118 | V_119 ) )
V_32 -> error = - V_114 ;
if ( ! V_32 -> error )
V_32 -> V_120 = V_32 -> V_42 * V_32 -> V_45 ;
else
V_32 -> V_120 = 0 ;
F_20 ( V_2 , V_115 ) ;
V_2 -> V_32 = NULL ;
if ( V_2 -> V_102 -> V_121 ) {
F_12 ( V_2 ) ;
F_29 ( V_2 , V_2 -> V_102 -> V_121 , V_2 -> V_83 ) ;
} else {
F_33 ( V_2 , V_2 -> V_102 ) ;
}
return 1 ;
}
static T_3 F_39 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
unsigned int V_124 ;
int V_125 = 0 ;
V_124 = F_13 ( V_2 -> V_19 + V_126 ) & ~ F_13 ( V_2 -> V_19 + V_30 ) ;
if ( V_124 ) {
unsigned V_103 = F_13 ( V_2 -> V_19 + V_20 ) ;
F_36 ( L_7 , V_124 , V_103 ) ;
if ( V_124 & V_100 )
V_125 |= F_35 ( V_2 , V_103 ) ;
if ( V_124 & V_115 )
V_125 |= F_37 ( V_2 , V_103 ) ;
if ( V_124 & V_127 ) {
F_40 ( V_2 -> V_4 ) ;
V_125 = 1 ;
}
}
return F_41 ( V_125 ) ;
}
static void F_42 ( struct V_128 * V_4 , struct V_101 * V_102 )
{
struct V_1 * V_2 = F_43 ( V_4 ) ;
unsigned int V_83 ;
F_30 ( V_2 -> V_102 != NULL ) ;
V_2 -> V_102 = V_102 ;
F_12 ( V_2 ) ;
V_83 = V_2 -> V_83 ;
V_2 -> V_83 &= ~ V_129 ;
if ( V_102 -> V_32 ) {
F_21 ( V_2 , V_102 -> V_32 ) ;
V_83 &= ~ V_85 ;
V_83 |= V_130 | V_131 ;
if ( V_102 -> V_32 -> V_27 & V_116 )
V_83 |= V_132 ;
}
F_29 ( V_2 , V_102 -> V_82 , V_83 ) ;
}
static int F_44 ( struct V_128 * V_4 )
{
struct V_1 * V_2 = F_43 ( V_4 ) ;
if ( V_2 -> V_6 && F_10 ( V_2 -> V_6 -> V_133 ) )
return F_45 ( V_4 ) ;
if ( V_2 -> V_6 && V_2 -> V_6 -> V_134 )
return ! ! V_2 -> V_6 -> V_134 ( F_4 ( V_4 ) ) ;
return - V_135 ;
}
static void F_46 ( struct V_128 * V_4 , struct V_136 * V_137 )
{
struct V_1 * V_2 = F_43 ( V_4 ) ;
if ( V_137 -> clock ) {
unsigned long V_138 = V_2 -> V_48 ;
unsigned int V_139 = V_138 / V_137 -> clock ;
if ( V_2 -> V_50 == V_140 )
F_47 ( V_2 -> V_139 ) ;
if ( V_137 -> clock == 26000000 ) {
V_2 -> V_50 = 7 ;
} else {
if ( ! V_139 )
V_139 = 1 ;
if ( V_138 / V_139 > V_137 -> clock )
V_139 <<= 1 ;
V_2 -> V_50 = F_48 ( V_139 ) - 1 ;
}
} else {
F_12 ( V_2 ) ;
if ( V_2 -> V_50 != V_140 ) {
V_2 -> V_50 = V_140 ;
F_49 ( V_2 -> V_139 ) ;
}
}
if ( V_2 -> V_10 != V_137 -> V_10 ) {
int V_13 ;
V_2 -> V_10 = V_137 -> V_10 ;
V_13 = F_8 ( V_2 , V_137 -> V_10 , V_137 -> V_11 ) ;
if ( V_13 ) {
F_16 ( F_4 ( V_4 ) , L_8 ) ;
return;
}
if ( V_137 -> V_10 == V_141 )
V_2 -> V_83 |= V_129 ;
}
if ( V_137 -> V_142 == V_143 )
V_2 -> V_83 |= V_144 ;
else
V_2 -> V_83 &= ~ V_144 ;
F_50 ( F_4 ( V_4 ) , L_9 ,
V_2 -> V_50 , V_2 -> V_83 ) ;
}
static void F_51 ( struct V_128 * V_2 , int V_145 )
{
struct V_1 * V_146 = F_43 ( V_2 ) ;
if ( V_145 )
F_17 ( V_146 , V_127 ) ;
else
F_20 ( V_146 , V_127 ) ;
}
static void V_78 ( void * V_147 )
{
struct V_1 * V_2 = V_147 ;
struct V_148 V_149 ;
enum V_150 V_151 ;
struct V_39 * V_40 ;
unsigned long V_27 ;
F_18 ( & V_2 -> V_28 , V_27 ) ;
if ( ! V_2 -> V_32 )
goto V_152;
if ( V_2 -> V_32 -> V_27 & V_63 )
V_40 = V_2 -> V_67 ;
else
V_40 = V_2 -> V_70 ;
V_151 = F_52 ( V_40 , V_2 -> V_80 , & V_149 ) ;
if ( F_53 ( V_151 == V_153 ) ) {
F_14 ( V_154 , V_2 -> V_19 + V_155 ) ;
} else {
F_54 ( L_10 , F_55 ( V_2 -> V_4 ) ,
V_2 -> V_32 -> V_27 & V_63 ? L_11 : L_12 ) ;
V_2 -> V_32 -> error = - V_156 ;
F_37 ( V_2 , 0 ) ;
}
V_152:
F_19 ( & V_2 -> V_28 , V_27 ) ;
}
static T_3 F_56 ( int V_122 , void * V_123 )
{
struct V_1 * V_2 = F_43 ( V_123 ) ;
F_57 ( V_123 , F_58 ( V_2 -> V_6 -> V_157 ) ) ;
return V_158 ;
}
static int F_59 ( struct V_159 * V_160 )
{
struct V_161 * V_162 = V_160 -> V_73 . V_163 ;
struct V_164 * V_6 ;
T_2 V_165 ;
if ( ! V_162 )
return 0 ;
V_6 = F_60 ( & V_160 -> V_73 , sizeof( * V_6 ) , V_166 ) ;
if ( ! V_6 )
return - V_167 ;
V_6 -> V_168 =
F_61 ( V_162 , L_13 , 0 ) ;
V_6 -> V_133 =
F_61 ( V_162 , L_14 , 0 ) ;
V_6 -> V_16 =
F_61 ( V_162 , L_15 , 0 ) ;
if ( F_62 ( V_162 , L_16 , & V_165 ) == 0 )
V_6 -> V_157 = V_165 ;
V_160 -> V_73 . V_169 = V_6 ;
return 0 ;
}
static int F_59 ( struct V_159 * V_160 )
{
return 0 ;
}
static int F_63 ( struct V_159 * V_160 )
{
struct V_128 * V_4 ;
struct V_1 * V_2 = NULL ;
struct V_170 * V_171 , * V_172 , * V_173 ;
struct V_174 V_175 , V_176 ;
int V_13 , V_122 , V_177 = - 1 , V_178 = - 1 , V_16 = - 1 ;
T_4 V_26 ;
V_13 = F_59 ( V_160 ) ;
if ( V_13 )
return V_13 ;
V_171 = F_64 ( V_160 , V_179 , 0 ) ;
V_122 = F_65 ( V_160 , 0 ) ;
if ( V_122 < 0 )
return V_122 ;
V_4 = F_66 ( sizeof( struct V_1 ) , & V_160 -> V_73 ) ;
if ( ! V_4 ) {
V_13 = - V_167 ;
goto V_180;
}
V_4 -> V_181 = & V_182 ;
V_4 -> V_183 = V_184 ;
V_4 -> V_185 = V_186 ;
V_4 -> V_187 = F_67 () ? 1023 : 2048 ;
V_4 -> V_188 = 65535 ;
V_2 = F_43 ( V_4 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_160 -> V_73 . V_169 ;
V_2 -> V_50 = V_140 ;
V_2 -> V_139 = F_68 ( & V_160 -> V_73 , NULL ) ;
if ( F_5 ( V_2 -> V_139 ) ) {
V_13 = F_69 ( V_2 -> V_139 ) ;
V_2 -> V_139 = NULL ;
goto V_180;
}
V_2 -> V_48 = F_70 ( V_2 -> V_139 ) ;
V_4 -> V_189 = ( V_2 -> V_48 + 63 ) / 64 ;
V_4 -> V_190 = ( F_71 () ) ? 26000000 : V_2 -> V_48 ;
F_1 ( V_2 ) ;
V_4 -> V_191 = V_192 ;
V_2 -> V_83 = 0 ;
if ( ! F_67 () ) {
V_4 -> V_191 |= V_193 | V_194 ;
V_2 -> V_83 |= V_195 ;
if ( F_71 () )
V_4 -> V_191 |= V_196 |
V_197 ;
}
F_72 ( & V_2 -> V_28 ) ;
V_2 -> V_56 = V_171 ;
V_2 -> V_122 = V_122 ;
V_2 -> V_29 = V_198 ;
V_2 -> V_19 = F_73 ( & V_160 -> V_73 , V_171 ) ;
if ( F_5 ( V_2 -> V_19 ) ) {
V_13 = F_69 ( V_2 -> V_19 ) ;
goto V_180;
}
F_12 ( V_2 ) ;
F_14 ( 0 , V_2 -> V_19 + V_199 ) ;
F_14 ( 64 , V_2 -> V_19 + V_200 ) ;
F_14 ( V_2 -> V_29 , V_2 -> V_19 + V_30 ) ;
V_13 = F_74 ( & V_160 -> V_73 , V_2 -> V_122 , F_39 , 0 ,
V_201 , V_2 ) ;
if ( V_13 )
goto V_180;
F_75 ( V_160 , V_4 ) ;
if ( ! V_160 -> V_73 . V_163 ) {
V_172 = F_64 ( V_160 , V_202 , 0 ) ;
V_173 = F_64 ( V_160 , V_202 , 1 ) ;
if ( ! V_172 || ! V_173 ) {
V_13 = - V_203 ;
goto V_180;
}
V_175 . V_204 = V_205 ;
V_175 . V_206 = V_172 -> V_57 ;
V_176 . V_204 = V_205 ;
V_176 . V_206 = V_173 -> V_57 ;
}
F_76 ( V_26 ) ;
F_77 ( V_207 , V_26 ) ;
V_2 -> V_67 =
F_78 ( V_26 , V_208 ,
& V_175 , & V_160 -> V_73 , L_11 ) ;
if ( V_2 -> V_67 == NULL ) {
F_16 ( & V_160 -> V_73 , L_17 ) ;
V_13 = - V_209 ;
goto V_180;
}
V_2 -> V_70 =
F_78 ( V_26 , V_208 ,
& V_176 , & V_160 -> V_73 , L_12 ) ;
if ( V_2 -> V_70 == NULL ) {
F_16 ( & V_160 -> V_73 , L_18 ) ;
V_13 = - V_209 ;
goto V_180;
}
if ( V_2 -> V_6 ) {
V_177 = V_2 -> V_6 -> V_168 ;
V_178 = V_2 -> V_6 -> V_133 ;
V_16 = V_2 -> V_6 -> V_16 ;
}
if ( F_10 ( V_16 ) ) {
V_13 = F_79 ( & V_160 -> V_73 , V_16 ,
L_19 ) ;
if ( V_13 ) {
F_16 ( & V_160 -> V_73 , L_20 ,
V_16 ) ;
goto V_180;
}
F_80 ( V_16 ,
V_2 -> V_6 -> V_17 ) ;
}
if ( F_10 ( V_178 ) ) {
V_13 = F_81 ( V_4 , V_178 ) ;
if ( V_13 ) {
F_16 ( & V_160 -> V_73 , L_21 ,
V_178 ) ;
goto V_180;
} else {
V_4 -> V_210 |= V_2 -> V_6 -> V_211 ?
0 : V_212 ;
}
}
if ( F_10 ( V_177 ) )
V_13 = F_82 ( V_4 , V_177 , 0 ) ;
if ( V_13 ) {
F_16 ( & V_160 -> V_73 , L_22 , V_177 ) ;
goto V_180;
}
if ( V_2 -> V_6 && V_2 -> V_6 -> V_213 )
V_2 -> V_6 -> V_213 ( & V_160 -> V_73 , F_56 , V_4 ) ;
if ( F_10 ( V_16 ) && V_2 -> V_6 -> V_18 )
F_7 ( & V_160 -> V_73 , L_23 ) ;
if ( F_10 ( V_178 ) && V_2 -> V_6 -> V_134 )
F_7 ( & V_160 -> V_73 , L_24 ) ;
F_83 ( V_4 ) ;
return 0 ;
V_180:
if ( V_2 ) {
if ( V_2 -> V_67 )
F_84 ( V_2 -> V_67 ) ;
if ( V_2 -> V_70 )
F_84 ( V_2 -> V_70 ) ;
}
if ( V_4 )
F_85 ( V_4 ) ;
return V_13 ;
}
static int F_86 ( struct V_159 * V_160 )
{
struct V_128 * V_4 = F_87 ( V_160 ) ;
int V_177 = - 1 , V_178 = - 1 , V_16 = - 1 ;
if ( V_4 ) {
struct V_1 * V_2 = F_43 ( V_4 ) ;
F_88 ( V_4 ) ;
if ( V_2 -> V_6 ) {
V_177 = V_2 -> V_6 -> V_168 ;
V_178 = V_2 -> V_6 -> V_133 ;
V_16 = V_2 -> V_6 -> V_16 ;
}
if ( V_2 -> V_6 && V_2 -> V_6 -> exit )
V_2 -> V_6 -> exit ( & V_160 -> V_73 , V_4 ) ;
F_12 ( V_2 ) ;
F_14 ( V_214 | V_215 | V_216 | V_217 |
V_100 | V_218 | V_115 ,
V_2 -> V_19 + V_30 ) ;
F_89 ( V_2 -> V_67 ) ;
F_89 ( V_2 -> V_70 ) ;
F_84 ( V_2 -> V_67 ) ;
F_84 ( V_2 -> V_70 ) ;
F_85 ( V_4 ) ;
}
return 0 ;
}
