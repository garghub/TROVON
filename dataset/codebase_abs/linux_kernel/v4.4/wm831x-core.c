static int F_1 ( struct V_1 * V_1 , unsigned short V_2 )
{
if ( ! V_1 -> V_3 )
return 0 ;
switch ( V_2 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
return 1 ;
default:
return 0 ;
}
}
void F_2 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_3 ( V_1 , V_11 , 0 ) ;
if ( V_10 == 0 ) {
F_4 ( V_1 -> V_12 , L_1 ) ;
F_5 ( & V_1 -> V_13 ) ;
F_6 ( V_1 -> V_3 ) ;
V_1 -> V_3 = 1 ;
F_7 ( & V_1 -> V_13 ) ;
} else {
F_8 ( V_1 -> V_12 , L_2 , V_10 ) ;
}
}
int F_9 ( struct V_1 * V_1 )
{
int V_10 ;
V_10 = F_3 ( V_1 , V_11 , 0x9716 ) ;
if ( V_10 == 0 ) {
F_4 ( V_1 -> V_12 , L_3 ) ;
F_5 ( & V_1 -> V_13 ) ;
F_6 ( ! V_1 -> V_3 ) ;
V_1 -> V_3 = 0 ;
F_7 ( & V_1 -> V_13 ) ;
}
return V_10 ;
}
static bool F_10 ( struct V_14 * V_12 , unsigned int V_2 )
{
switch ( V_2 ) {
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_4 :
case V_6 :
case V_21 :
case V_22 :
case V_11 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_8 :
case V_9 :
case V_78 :
case V_7 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_5 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
return true ;
default:
return false ;
}
}
static bool F_11 ( struct V_14 * V_12 , unsigned int V_2 )
{
struct V_1 * V_1 = F_12 ( V_12 ) ;
if ( F_1 ( V_1 , V_2 ) )
return false ;
switch ( V_2 ) {
case V_18 :
case V_19 :
case V_20 :
case V_4 :
case V_6 :
case V_21 :
case V_22 :
case V_11 :
case V_23 :
case V_24 :
case V_25 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_8 :
case V_9 :
case V_78 :
case V_7 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_5 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
return true ;
default:
return false ;
}
}
static bool F_13 ( struct V_14 * V_12 , unsigned int V_2 )
{
switch ( V_2 ) {
case V_26 :
case V_27 :
case V_28 :
case V_25 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_43 :
case V_44 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_78 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
return true ;
default:
return false ;
}
}
int F_14 ( struct V_1 * V_1 , unsigned short V_2 )
{
unsigned int V_178 ;
int V_10 ;
V_10 = F_15 ( V_1 -> V_179 , V_2 , & V_178 ) ;
if ( V_10 < 0 )
return V_10 ;
else
return V_178 ;
}
int F_16 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_180 , T_1 * V_181 )
{
return F_17 ( V_1 -> V_179 , V_2 , V_181 , V_180 ) ;
}
static int F_18 ( struct V_1 * V_1 , unsigned short V_2 ,
int V_182 , void * V_183 )
{
T_1 * V_181 = V_183 ;
int V_184 , V_10 ;
F_19 ( V_182 % 2 ) ;
F_19 ( V_182 <= 0 ) ;
for ( V_184 = 0 ; V_184 < V_182 / 2 ; V_184 ++ ) {
if ( F_1 ( V_1 , V_2 ) )
return - V_185 ;
F_4 ( V_1 -> V_12 , L_4 ,
V_181 [ V_184 ] , V_2 + V_184 , V_2 + V_184 ) ;
V_10 = F_20 ( V_1 -> V_179 , V_2 + V_184 , V_181 [ V_184 ] ) ;
if ( V_10 != 0 )
return V_10 ;
}
return 0 ;
}
int F_3 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_178 )
{
int V_10 ;
F_5 ( & V_1 -> V_13 ) ;
V_10 = F_18 ( V_1 , V_2 , 2 , & V_178 ) ;
F_7 ( & V_1 -> V_13 ) ;
return V_10 ;
}
int F_21 ( struct V_1 * V_1 , unsigned short V_2 ,
unsigned short V_186 , unsigned short V_178 )
{
int V_10 ;
F_5 ( & V_1 -> V_13 ) ;
if ( ! F_1 ( V_1 , V_2 ) )
V_10 = F_22 ( V_1 -> V_179 , V_2 , V_186 , V_178 ) ;
else
V_10 = - V_185 ;
F_7 ( & V_1 -> V_13 ) ;
return V_10 ;
}
int F_23 ( struct V_1 * V_1 , unsigned long V_187 , int V_188 )
{
struct V_189 * V_190 = F_24 ( V_1 -> V_12 ) ;
int V_191 , V_192 ;
enum V_193 V_194 ;
int V_10 , V_184 ;
F_25 ( & V_1 -> V_13 ) ;
F_25 ( & V_1 -> V_195 ) ;
F_26 ( V_1 -> V_12 , V_1 ) ;
if ( V_190 )
V_1 -> V_196 = V_190 -> V_196 ;
V_10 = F_14 ( V_1 , V_17 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_5 , V_10 ) ;
goto V_197;
}
switch ( V_10 ) {
case 0x6204 :
case 0x6246 :
break;
default:
F_8 ( V_1 -> V_12 , L_6 , V_10 ) ;
V_10 = - V_198 ;
goto V_197;
}
V_10 = F_14 ( V_1 , V_16 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_7 , V_10 ) ;
goto V_197;
}
V_191 = ( V_10 & V_199 ) >> V_200 ;
V_10 = F_14 ( V_1 , V_15 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_8 , V_10 ) ;
goto V_197;
}
if ( V_10 == 0 ) {
F_27 ( V_1 -> V_12 , L_9 ) ;
V_10 = V_187 ;
}
switch ( V_10 ) {
case V_201 :
V_194 = V_201 ;
V_1 -> V_202 = 16 ;
V_1 -> V_203 = 1 ;
if ( V_191 > 0 ) {
V_1 -> V_204 = 1 ;
V_1 -> V_205 = 1 ;
}
F_27 ( V_1 -> V_12 , L_10 , 'A' + V_191 ) ;
break;
case V_206 :
V_194 = V_206 ;
V_1 -> V_202 = 16 ;
V_1 -> V_203 = 1 ;
if ( V_191 > 0 ) {
V_1 -> V_204 = 1 ;
V_1 -> V_205 = 1 ;
}
F_27 ( V_1 -> V_12 , L_11 , 'A' + V_191 ) ;
break;
case V_207 :
V_194 = V_207 ;
V_1 -> V_202 = 16 ;
V_1 -> V_203 = 1 ;
if ( V_191 > 0 ) {
V_1 -> V_204 = 1 ;
V_1 -> V_205 = 1 ;
}
F_27 ( V_1 -> V_12 , L_12 , 'A' + V_191 ) ;
break;
case V_208 :
V_194 = V_208 ;
V_1 -> V_202 = 12 ;
F_27 ( V_1 -> V_12 , L_13 , 'A' + V_191 ) ;
break;
case V_209 :
V_194 = V_209 ;
V_1 -> V_202 = 12 ;
F_27 ( V_1 -> V_12 , L_14 , 'A' + V_191 ) ;
break;
case V_210 :
V_194 = V_210 ;
V_1 -> V_202 = 12 ;
F_27 ( V_1 -> V_12 , L_15 , 'A' + V_191 ) ;
break;
case V_211 :
V_194 = V_211 ;
V_1 -> V_202 = 12 ;
F_27 ( V_1 -> V_12 , L_16 , 'A' + V_191 ) ;
break;
default:
F_8 ( V_1 -> V_12 , L_17 , V_10 ) ;
V_10 = - V_198 ;
goto V_197;
}
if ( V_194 != V_187 )
F_28 ( V_1 -> V_12 , L_18 ,
V_187 ) ;
V_10 = F_14 ( V_1 , V_11 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_19 , V_10 ) ;
goto V_197;
}
if ( V_10 != 0 ) {
F_28 ( V_1 -> V_12 , L_20 ,
V_10 ) ;
F_3 ( V_1 , V_11 , 0 ) ;
}
V_1 -> V_3 = 1 ;
if ( V_190 && V_190 -> V_212 ) {
V_10 = V_190 -> V_212 ( V_1 ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_21 , V_10 ) ;
goto V_197;
}
}
if ( V_190 ) {
for ( V_184 = 0 ; V_184 < F_29 ( V_190 -> V_213 ) ; V_184 ++ ) {
if ( ! V_190 -> V_213 [ V_184 ] )
continue;
F_3 ( V_1 ,
V_62 + V_184 ,
V_190 -> V_213 [ V_184 ] & 0xffff ) ;
}
}
if ( V_190 && V_190 -> V_192 )
V_192 = V_190 -> V_192 * 10 ;
else
V_192 = - 1 ;
V_10 = F_30 ( V_1 , V_188 ) ;
if ( V_10 != 0 )
goto V_197;
F_31 ( V_1 ) ;
switch ( V_194 ) {
case V_201 :
V_10 = F_32 ( V_1 -> V_12 , V_192 ,
V_214 , F_29 ( V_214 ) ,
NULL , 0 , NULL ) ;
break;
case V_206 :
V_10 = F_32 ( V_1 -> V_12 , V_192 ,
V_215 , F_29 ( V_215 ) ,
NULL , 0 , NULL ) ;
if ( ! V_190 || ! V_190 -> V_216 )
F_32 ( V_1 -> V_12 , V_192 ,
V_217 , F_29 ( V_217 ) ,
NULL , 0 , NULL ) ;
break;
case V_207 :
V_10 = F_32 ( V_1 -> V_12 , V_192 ,
V_218 , F_29 ( V_218 ) ,
NULL , 0 , NULL ) ;
if ( ! V_190 || ! V_190 -> V_216 )
F_32 ( V_1 -> V_12 , V_192 ,
V_217 , F_29 ( V_217 ) ,
NULL , 0 , NULL ) ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
V_10 = F_32 ( V_1 -> V_12 , V_192 ,
V_219 , F_29 ( V_219 ) ,
NULL , 0 , NULL ) ;
break;
default:
F_33 () ;
}
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_22 ) ;
goto V_220;
}
V_10 = F_14 ( V_1 , V_141 ) ;
if ( V_10 < 0 ) {
F_8 ( V_1 -> V_12 , L_23 , V_10 ) ;
goto V_220;
}
if ( V_10 & V_221 ) {
V_10 = F_32 ( V_1 -> V_12 , V_192 ,
V_222 , F_29 ( V_222 ) ,
NULL , 0 , NULL ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_24 , V_10 ) ;
goto V_220;
}
} else {
F_27 ( V_1 -> V_12 , L_25 ) ;
}
if ( V_190 && V_190 -> V_223 ) {
V_10 = F_32 ( V_1 -> V_12 , V_192 , V_224 ,
F_29 ( V_224 ) , NULL ,
0 , NULL ) ;
if ( V_10 < 0 )
F_8 ( V_1 -> V_12 , L_26 ,
V_10 ) ;
}
F_34 ( V_1 ) ;
if ( V_190 && V_190 -> V_225 ) {
V_10 = V_190 -> V_225 ( V_1 ) ;
if ( V_10 != 0 ) {
F_8 ( V_1 -> V_12 , L_27 , V_10 ) ;
goto V_220;
}
}
return 0 ;
V_220:
F_35 ( V_1 ) ;
V_197:
F_36 ( V_1 -> V_12 ) ;
return V_10 ;
}
void F_37 ( struct V_1 * V_1 )
{
F_38 ( V_1 ) ;
F_36 ( V_1 -> V_12 ) ;
F_39 ( F_40 ( V_1 , V_226 ) , V_1 ) ;
F_35 ( V_1 ) ;
}
int F_41 ( struct V_1 * V_1 )
{
int V_2 , V_186 ;
if ( V_1 -> V_203 ) {
V_2 = F_14 ( V_1 , V_38 ) ;
V_186 = V_227 |
V_228 |
V_229 |
V_230 | V_231 |
V_232 | V_233 |
V_234 ;
if ( V_2 & V_186 )
V_2 = F_14 ( V_1 ,
V_31 ) ;
if ( V_2 & V_186 ) {
F_27 ( V_1 -> V_12 ,
L_28 ,
V_2 & V_186 ) ;
F_3 ( V_1 , V_31 ,
V_2 & V_186 ) ;
}
}
return 0 ;
}
void F_42 ( struct V_1 * V_1 )
{
if ( V_1 -> V_196 ) {
F_27 ( V_1 -> V_12 , L_29 ) ;
F_21 ( V_1 , V_20 , V_235 , 0 ) ;
}
}
