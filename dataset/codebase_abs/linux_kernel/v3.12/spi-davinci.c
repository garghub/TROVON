static void F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
if ( V_3 -> V_4 ) {
T_2 * V_4 = V_3 -> V_4 ;
* V_4 ++ = ( T_2 ) V_1 ;
V_3 -> V_4 = V_4 ;
}
}
static void F_2 ( T_1 V_1 , struct V_2 * V_3 )
{
if ( V_3 -> V_4 ) {
T_3 * V_4 = V_3 -> V_4 ;
* V_4 ++ = ( T_3 ) V_1 ;
V_3 -> V_4 = V_4 ;
}
}
static T_1 F_3 ( struct V_2 * V_3 )
{
T_1 V_1 = 0 ;
if ( V_3 -> V_5 ) {
const T_2 * V_5 = V_3 -> V_5 ;
V_1 = * V_5 ++ ;
V_3 -> V_5 = V_5 ;
}
return V_1 ;
}
static T_1 F_4 ( struct V_2 * V_3 )
{
T_1 V_1 = 0 ;
if ( V_3 -> V_5 ) {
const T_3 * V_5 = V_3 -> V_5 ;
V_1 = * V_5 ++ ;
V_3 -> V_5 = V_5 ;
}
return V_1 ;
}
static inline void F_5 ( void T_4 * V_6 , T_1 V_7 )
{
T_1 V_8 = F_6 ( V_6 ) ;
V_8 |= V_7 ;
F_7 ( V_8 , V_6 ) ;
}
static inline void F_8 ( void T_4 * V_6 , T_1 V_7 )
{
T_1 V_8 = F_6 ( V_6 ) ;
V_8 &= ~ V_7 ;
F_7 ( V_8 , V_6 ) ;
}
static void F_9 ( struct V_9 * V_10 , int V_11 )
{
struct V_2 * V_3 ;
struct V_12 * V_13 ;
T_2 V_14 = V_10 -> V_15 ;
T_3 V_16 = V_17 ;
bool V_18 = false ;
V_3 = F_10 ( V_10 -> V_19 ) ;
V_13 = & V_3 -> V_13 ;
if ( V_13 -> V_14 && V_14 < V_13 -> V_20 &&
V_13 -> V_14 [ V_14 ] != V_21 )
V_18 = true ;
if ( V_18 ) {
if ( V_11 == V_22 )
F_11 ( V_13 -> V_14 [ V_14 ] , 0 ) ;
else
F_11 ( V_13 -> V_14 [ V_14 ] , 1 ) ;
} else {
if ( V_11 == V_22 ) {
V_16 |= V_23 ;
V_16 &= ~ ( 0x1 << V_14 ) ;
}
F_12 ( V_16 , V_3 -> V_24 + V_25 + 2 ) ;
}
}
static inline int F_13 ( struct V_2 * V_3 ,
T_1 V_26 )
{
int V_27 ;
V_27 = F_14 ( F_15 ( V_3 -> V_28 ) , V_26 ) ;
if ( V_27 < 3 || V_27 > 256 )
return - V_29 ;
return V_27 - 1 ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_30 * V_31 )
{
struct V_2 * V_3 ;
struct V_32 * V_33 ;
T_2 V_34 = 0 ;
T_1 V_35 = 0 , V_36 = 0 , V_37 = 0 ;
V_3 = F_10 ( V_10 -> V_19 ) ;
V_33 = (struct V_32 * ) V_10 -> V_38 ;
if ( ! V_33 )
V_33 = & V_39 ;
if ( V_31 ) {
V_34 = V_31 -> V_34 ;
V_35 = V_31 -> V_40 ;
}
if ( ! V_34 )
V_34 = V_10 -> V_34 ;
if ( V_34 <= 8 ) {
V_3 -> V_41 = F_1 ;
V_3 -> V_42 = F_3 ;
V_3 -> V_43 [ V_10 -> V_15 ] = 1 ;
} else {
V_3 -> V_41 = F_2 ;
V_3 -> V_42 = F_4 ;
V_3 -> V_43 [ V_10 -> V_15 ] = 2 ;
}
if ( ! V_35 )
V_35 = V_10 -> V_26 ;
V_37 = F_13 ( V_3 , V_35 ) ;
if ( V_37 < 0 )
return V_37 ;
V_36 = ( V_37 << V_44 ) | ( V_34 & 0x1f ) ;
if ( V_10 -> V_45 & V_46 )
V_36 |= V_47 ;
if ( V_10 -> V_45 & V_48 )
V_36 |= V_49 ;
if ( ! ( V_10 -> V_45 & V_50 ) )
V_36 |= V_51 ;
if ( V_3 -> V_52 == V_53 ) {
T_1 V_54 = 0 ;
V_36 |= ( ( V_33 -> V_55 << V_56 )
& V_57 ) ;
if ( V_33 -> V_58 )
V_36 |= V_59 ;
if ( V_33 -> V_60 )
V_36 |= V_61 ;
if ( V_33 -> V_62 ) {
V_36 |= V_63 ;
} else {
V_54 |= ( V_33 -> V_64 << V_65 )
& V_66 ;
V_54 |= ( V_33 -> V_67 << V_68 )
& V_69 ;
}
if ( V_10 -> V_45 & V_70 ) {
V_36 |= V_71 ;
V_54 |= ( V_33 -> V_72 << V_73 )
& V_74 ;
V_54 |= ( V_33 -> V_75 << V_76 )
& V_77 ;
}
F_7 ( V_54 , V_3 -> V_24 + V_78 ) ;
}
F_7 ( V_36 , V_3 -> V_24 + V_79 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 )
{
int V_80 = 0 ;
struct V_2 * V_3 ;
struct V_12 * V_13 ;
V_3 = F_10 ( V_10 -> V_19 ) ;
V_13 = & V_3 -> V_13 ;
if ( ! V_10 -> V_34 )
V_10 -> V_34 = 8 ;
if ( ! ( V_10 -> V_45 & V_81 ) ) {
if ( ( V_13 -> V_14 == NULL ) ||
( V_13 -> V_14 [ V_10 -> V_15 ] == V_21 ) )
F_5 ( V_3 -> V_24 + V_82 , 1 << V_10 -> V_15 ) ;
}
if ( V_10 -> V_45 & V_70 )
F_5 ( V_3 -> V_24 + V_82 , V_83 ) ;
if ( V_10 -> V_45 & V_84 )
F_5 ( V_3 -> V_24 + V_85 , V_86 ) ;
else
F_8 ( V_3 -> V_24 + V_85 , V_86 ) ;
return V_80 ;
}
static int F_18 ( struct V_2 * V_3 , int V_87 )
{
struct V_88 * V_89 = V_3 -> V_90 . V_19 -> V_91 . V_92 ;
if ( V_87 & V_93 ) {
F_19 ( V_89 , L_1 ) ;
return - V_94 ;
}
if ( V_87 & V_95 ) {
F_19 ( V_89 , L_2 ) ;
return - V_96 ;
}
if ( V_87 & V_97 ) {
F_19 ( V_89 , L_3 ) ;
return - V_96 ;
}
if ( V_3 -> V_52 == V_53 ) {
if ( V_87 & V_98 ) {
F_19 ( V_89 , L_4 ) ;
return - V_96 ;
}
if ( V_87 & V_99 ) {
F_19 ( V_89 , L_5 ) ;
return - V_96 ;
}
if ( V_87 & V_100 ) {
F_19 ( V_89 , L_6 ) ;
return - V_96 ;
}
if ( V_87 & V_101 ) {
F_19 ( V_89 , L_7 ) ;
return - V_102 ;
}
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
T_1 V_103 , V_104 , V_105 = 0 , V_16 ;
V_103 = F_6 ( V_3 -> V_24 + V_106 ) ;
if ( V_3 -> V_107 > 0 && ! ( V_103 & V_108 ) ) {
V_3 -> V_41 ( V_103 & 0xFFFF , V_3 ) ;
V_3 -> V_107 -- ;
}
V_104 = F_6 ( V_3 -> V_24 + V_109 ) ;
if ( F_21 ( V_104 & V_110 ) ) {
V_105 = V_104 & V_110 ;
goto V_111;
}
if ( V_3 -> V_112 > 0 && ! ( V_103 & V_113 ) ) {
V_16 = F_6 ( V_3 -> V_24 + V_25 ) ;
V_3 -> V_112 -- ;
V_16 &= ~ 0xFFFF ;
V_16 |= 0xFFFF & V_3 -> V_42 ( V_3 ) ;
F_7 ( V_16 , V_3 -> V_24 + V_25 ) ;
}
V_111:
return V_105 ;
}
static void F_22 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_107 = 0 ;
if ( ! V_3 -> V_112 && ! V_3 -> V_107 )
F_23 ( & V_3 -> V_114 ) ;
}
static void F_24 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_112 = 0 ;
if ( ! V_3 -> V_112 && ! V_3 -> V_107 )
F_23 ( & V_3 -> V_114 ) ;
}
static int F_25 ( struct V_9 * V_10 , struct V_30 * V_31 )
{
struct V_2 * V_3 ;
int V_115 , V_27 = - V_116 ;
T_1 V_117 , V_16 ;
T_1 V_105 = 0 ;
struct V_32 * V_33 ;
struct V_12 * V_13 ;
unsigned V_118 ( V_119 ) ;
void * V_120 = NULL ;
struct V_121 V_122 , V_123 ;
V_3 = F_10 ( V_10 -> V_19 ) ;
V_13 = & V_3 -> V_13 ;
V_33 = (struct V_32 * ) V_10 -> V_38 ;
if ( ! V_33 )
V_33 = & V_39 ;
V_115 = V_3 -> V_43 [ V_10 -> V_15 ] ;
V_3 -> V_5 = V_31 -> V_124 ;
V_3 -> V_4 = V_31 -> V_125 ;
V_3 -> V_112 = V_31 -> V_126 / V_115 ;
V_3 -> V_107 = V_3 -> V_112 ;
V_16 = F_6 ( V_3 -> V_24 + V_25 ) ;
F_8 ( V_3 -> V_24 + V_85 , V_127 ) ;
F_5 ( V_3 -> V_24 + V_85 , V_128 ) ;
F_26 ( V_3 -> V_114 ) ;
if ( V_33 -> V_129 == V_130 )
F_5 ( V_3 -> V_24 + V_131 , V_132 ) ;
if ( V_33 -> V_129 != V_133 ) {
V_3 -> V_112 -- ;
V_117 = V_3 -> V_42 ( V_3 ) ;
V_16 &= 0xFFFF0000 ;
V_16 |= V_117 & 0xFFFF ;
F_7 ( V_16 , V_3 -> V_24 + V_25 ) ;
} else {
struct V_134 V_135 = {
. V_136 = V_137 ,
. V_138 = ( unsigned long ) V_3 -> V_139 + V_106 ,
. V_140 = V_115 ,
. V_141 = 1 ,
} ;
struct V_134 V_142 = {
. V_136 = V_143 ,
. V_144 = ( unsigned long ) V_3 -> V_139 + V_25 ,
. V_145 = V_115 ,
. V_146 = 1 ,
} ;
struct V_147 * V_148 ;
struct V_147 * V_149 ;
void * V_103 ;
V_120 = F_27 ( V_31 -> V_126 , V_150 ) ;
if ( ! V_120 )
goto V_151;
F_28 ( V_3 -> V_152 , & V_135 ) ;
F_28 ( V_3 -> V_153 , & V_142 ) ;
F_29 ( & V_122 , 1 ) ;
if ( ! V_31 -> V_125 )
V_103 = V_120 ;
else
V_103 = V_31 -> V_125 ;
V_31 -> V_154 = F_30 ( & V_10 -> V_91 , V_103 ,
V_31 -> V_126 , V_155 ) ;
if ( ! V_31 -> V_154 ) {
V_27 = - V_156 ;
goto V_157;
}
F_31 ( & V_122 ) = V_31 -> V_154 ;
F_32 ( & V_122 ) = V_31 -> V_126 ;
F_29 ( & V_123 , 1 ) ;
if ( ! V_31 -> V_124 )
V_103 = V_120 ;
else
V_103 = ( void * ) V_31 -> V_124 ;
V_31 -> V_158 = F_30 ( & V_10 -> V_91 , V_103 ,
V_31 -> V_126 , V_159 ) ;
if ( ! V_31 -> V_158 ) {
V_27 = - V_156 ;
goto V_160;
}
F_31 ( & V_123 ) = V_31 -> V_158 ;
F_32 ( & V_123 ) = V_31 -> V_126 ;
V_148 = F_33 ( V_3 -> V_152 ,
& V_122 , 1 , V_137 ,
V_161 | V_162 ) ;
if ( ! V_148 )
goto V_163;
V_149 = F_33 ( V_3 -> V_153 ,
& V_123 , 1 , V_143 ,
V_161 | V_162 ) ;
if ( ! V_149 )
goto V_163;
V_148 -> V_164 = F_22 ;
V_148 -> V_165 = ( void * ) V_3 ;
V_149 -> V_164 = F_24 ;
V_149 -> V_165 = ( void * ) V_3 ;
if ( V_13 -> V_166 )
F_12 ( V_16 >> 16 , V_3 -> V_24 + V_25 + 2 ) ;
F_34 ( V_148 ) ;
F_34 ( V_149 ) ;
F_35 ( V_3 -> V_152 ) ;
F_35 ( V_3 -> V_153 ) ;
F_5 ( V_3 -> V_24 + V_131 , V_167 ) ;
}
if ( V_33 -> V_129 != V_168 ) {
F_36 ( & ( V_3 -> V_114 ) ) ;
} else {
while ( V_3 -> V_107 > 0 || V_3 -> V_112 > 0 ) {
V_105 = F_20 ( V_3 ) ;
if ( V_105 )
break;
F_37 () ;
}
}
F_8 ( V_3 -> V_24 + V_131 , V_169 ) ;
if ( V_33 -> V_129 == V_133 ) {
F_8 ( V_3 -> V_24 + V_131 , V_167 ) ;
F_38 ( & V_10 -> V_91 , V_31 -> V_154 ,
V_31 -> V_126 , V_155 ) ;
F_38 ( & V_10 -> V_91 , V_31 -> V_158 ,
V_31 -> V_126 , V_159 ) ;
F_39 ( V_120 ) ;
}
F_8 ( V_3 -> V_24 + V_85 , V_128 ) ;
F_5 ( V_3 -> V_24 + V_85 , V_127 ) ;
if ( V_105 ) {
V_27 = F_18 ( V_3 , V_105 ) ;
F_40 ( ! V_27 , L_8 ,
F_41 ( & V_10 -> V_91 ) ) ;
return V_27 ;
}
if ( V_3 -> V_107 != 0 || V_3 -> V_112 != 0 ) {
F_42 ( & V_10 -> V_91 , L_9 ) ;
return - V_96 ;
}
return V_31 -> V_126 ;
V_163:
F_38 ( & V_10 -> V_91 , V_31 -> V_158 , V_31 -> V_126 , V_159 ) ;
V_160:
F_38 ( & V_10 -> V_91 , V_31 -> V_154 , V_31 -> V_126 , V_155 ) ;
V_157:
F_39 ( V_120 ) ;
V_151:
return V_27 ;
}
static T_5 F_43 ( T_6 V_170 , void * V_1 )
{
return V_171 ;
}
static T_5 F_44 ( T_6 V_170 , void * V_1 )
{
struct V_2 * V_3 = V_1 ;
int V_104 ;
V_104 = F_20 ( V_3 ) ;
if ( F_21 ( V_104 != 0 ) )
F_8 ( V_3 -> V_24 + V_131 , V_132 ) ;
if ( ( ! V_3 -> V_107 && ! V_3 -> V_112 ) || V_104 )
F_23 ( & V_3 -> V_114 ) ;
return V_171 ;
}
static int F_45 ( struct V_2 * V_3 )
{
T_7 V_172 ;
struct V_88 * V_89 = V_3 -> V_90 . V_19 -> V_91 . V_92 ;
int V_173 ;
F_46 ( V_172 ) ;
F_47 ( V_174 , V_172 ) ;
V_3 -> V_152 = F_48 ( V_172 , V_175 ,
& V_3 -> V_176 ) ;
if ( ! V_3 -> V_152 ) {
F_42 ( V_89 , L_10 ) ;
V_173 = - V_177 ;
goto V_178;
}
V_3 -> V_153 = F_48 ( V_172 , V_175 ,
& V_3 -> V_179 ) ;
if ( ! V_3 -> V_153 ) {
F_42 ( V_89 , L_11 ) ;
V_173 = - V_177 ;
goto V_180;
}
return 0 ;
V_180:
F_49 ( V_3 -> V_152 ) ;
V_178:
return V_173 ;
}
static int F_50 ( struct V_181 * V_182 ,
struct V_2 * V_3 )
{
struct V_183 * V_184 = V_182 -> V_91 . V_185 ;
struct V_12 * V_13 ;
unsigned int V_186 , V_187 = 0 ;
const struct V_188 * V_189 ;
V_13 = & V_3 -> V_13 ;
V_13 -> V_52 = V_190 ;
V_189 = F_51 ( F_52 ( V_191 ) ,
& V_182 -> V_91 ) ;
if ( ! V_189 )
return - V_177 ;
if ( V_189 -> V_1 == ( void * ) V_53 )
V_13 -> V_52 = V_53 ;
V_186 = 1 ;
F_53 ( V_184 , L_12 , & V_186 ) ;
V_13 -> V_20 = V_186 ;
F_53 ( V_184 , L_13 , & V_187 ) ;
V_13 -> V_187 = V_187 ;
return 0 ;
}
static struct V_12
* F_50 ( struct V_181 * V_182 ,
struct V_2 * V_3 )
{
return - V_177 ;
}
static int F_54 ( struct V_181 * V_182 )
{
struct V_192 * V_19 ;
struct V_2 * V_3 ;
struct V_12 * V_13 ;
struct V_193 * V_173 , * V_194 ;
T_8 V_195 = V_196 ;
T_8 V_197 = V_196 ;
int V_198 = 0 , V_27 = 0 ;
T_1 V_199 ;
V_19 = F_55 ( & V_182 -> V_91 , sizeof( struct V_2 ) ) ;
if ( V_19 == NULL ) {
V_27 = - V_116 ;
goto V_200;
}
F_56 ( V_182 , V_19 ) ;
V_3 = F_10 ( V_19 ) ;
if ( V_3 == NULL ) {
V_27 = - V_201 ;
goto V_202;
}
if ( F_57 ( & V_182 -> V_91 ) ) {
V_13 = F_57 ( & V_182 -> V_91 ) ;
V_3 -> V_13 = * V_13 ;
} else {
V_27 = F_50 ( V_182 , V_3 ) ;
if ( V_27 < 0 )
goto V_202;
}
V_13 = & V_3 -> V_13 ;
V_173 = F_58 ( V_182 , V_203 , 0 ) ;
if ( V_173 == NULL ) {
V_27 = - V_201 ;
goto V_202;
}
V_3 -> V_139 = V_173 -> V_204 ;
V_194 = F_59 ( V_173 -> V_204 , F_60 ( V_173 ) , V_182 -> V_205 ) ;
if ( V_194 == NULL ) {
V_27 = - V_102 ;
goto V_202;
}
V_3 -> V_24 = F_61 ( V_173 -> V_204 , F_60 ( V_173 ) ) ;
if ( V_3 -> V_24 == NULL ) {
V_27 = - V_116 ;
goto V_206;
}
V_3 -> V_170 = F_62 ( V_182 , 0 ) ;
if ( V_3 -> V_170 <= 0 ) {
V_27 = - V_29 ;
goto V_207;
}
V_27 = F_63 ( V_3 -> V_170 , F_44 , F_43 ,
0 , F_41 ( & V_182 -> V_91 ) , V_3 ) ;
if ( V_27 )
goto V_207;
V_3 -> V_90 . V_19 = F_64 ( V_19 ) ;
if ( V_3 -> V_90 . V_19 == NULL ) {
V_27 = - V_177 ;
goto V_208;
}
V_3 -> V_28 = F_65 ( & V_182 -> V_91 , NULL ) ;
if ( F_66 ( V_3 -> V_28 ) ) {
V_27 = - V_177 ;
goto V_209;
}
F_67 ( V_3 -> V_28 ) ;
V_19 -> V_91 . V_185 = V_182 -> V_91 . V_185 ;
V_19 -> V_210 = V_182 -> V_211 ;
V_19 -> V_20 = V_13 -> V_20 ;
V_19 -> V_212 = F_68 ( 2 , 16 ) ;
V_19 -> V_213 = F_17 ;
V_3 -> V_90 . V_214 = F_9 ;
V_3 -> V_90 . V_215 = F_16 ;
V_3 -> V_52 = V_13 -> V_52 ;
V_3 -> V_90 . V_216 = V_81 | V_46 | V_84 ;
if ( V_3 -> V_52 == V_53 )
V_3 -> V_90 . V_216 |= V_70 ;
V_173 = F_58 ( V_182 , V_217 , 0 ) ;
if ( V_173 )
V_195 = V_173 -> V_204 ;
V_173 = F_58 ( V_182 , V_217 , 1 ) ;
if ( V_173 )
V_197 = V_173 -> V_204 ;
V_3 -> V_90 . V_218 = F_25 ;
if ( V_195 != V_196 &&
V_197 != V_196 ) {
V_3 -> V_176 = V_195 ;
V_3 -> V_179 = V_197 ;
V_27 = F_45 ( V_3 ) ;
if ( V_27 )
goto V_219;
F_69 ( & V_182 -> V_91 , L_14 ) ;
F_69 ( & V_182 -> V_91 , L_15
L_16 , V_195 , V_197 ,
V_13 -> V_220 ) ;
}
V_3 -> V_41 = F_1 ;
V_3 -> V_42 = F_3 ;
F_70 ( & V_3 -> V_114 ) ;
F_7 ( 0 , V_3 -> V_24 + V_221 ) ;
F_71 ( 100 ) ;
F_7 ( 1 , V_3 -> V_24 + V_221 ) ;
V_199 = V_222 | V_223 | V_224 ;
F_7 ( V_199 , V_3 -> V_24 + V_82 ) ;
if ( V_13 -> V_14 ) {
for ( V_198 = 0 ; V_198 < V_13 -> V_20 ; V_198 ++ ) {
if ( V_13 -> V_14 [ V_198 ] != V_21 )
F_72 ( V_13 -> V_14 [ V_198 ] , 1 ) ;
}
}
if ( V_13 -> V_187 )
F_7 ( V_225 , V_3 -> V_24 + V_226 ) ;
else
F_7 ( V_227 , V_3 -> V_24 + V_226 ) ;
F_7 ( V_17 , V_3 -> V_24 + V_228 ) ;
F_5 ( V_3 -> V_24 + V_85 , V_229 ) ;
F_5 ( V_3 -> V_24 + V_85 , V_230 ) ;
F_5 ( V_3 -> V_24 + V_85 , V_127 ) ;
V_27 = F_73 ( & V_3 -> V_90 ) ;
if ( V_27 )
goto V_231;
F_69 ( & V_182 -> V_91 , L_17 , V_3 -> V_24 ) ;
return V_27 ;
V_231:
F_49 ( V_3 -> V_152 ) ;
F_49 ( V_3 -> V_153 ) ;
V_219:
F_74 ( V_3 -> V_28 ) ;
F_75 ( V_3 -> V_28 ) ;
V_209:
F_76 ( V_19 ) ;
V_208:
F_77 ( V_3 -> V_170 , V_3 ) ;
V_207:
F_78 ( V_3 -> V_24 ) ;
V_206:
F_79 ( V_3 -> V_139 , F_60 ( V_173 ) ) ;
V_202:
F_39 ( V_19 ) ;
V_200:
return V_27 ;
}
static int F_80 ( struct V_181 * V_182 )
{
struct V_2 * V_3 ;
struct V_192 * V_19 ;
struct V_193 * V_173 ;
V_19 = F_81 ( V_182 ) ;
V_3 = F_10 ( V_19 ) ;
F_82 ( & V_3 -> V_90 ) ;
F_74 ( V_3 -> V_28 ) ;
F_75 ( V_3 -> V_28 ) ;
F_76 ( V_19 ) ;
F_77 ( V_3 -> V_170 , V_3 ) ;
F_78 ( V_3 -> V_24 ) ;
V_173 = F_58 ( V_182 , V_203 , 0 ) ;
F_79 ( V_3 -> V_139 , F_60 ( V_173 ) ) ;
return 0 ;
}
