static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 , V_7 ;
struct V_8 V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
V_11 = & F_2 ( V_2 -> V_16 . V_17 ) -> V_18 . V_19 ;
V_13 = F_3 ( V_2 -> V_16 . V_20 ? V_2 -> V_16 . V_20 -> V_13 : V_2 -> V_16 . V_13 ) ;
V_15 = & V_2 -> V_21 ;
V_15 -> V_22 = V_2 -> V_23 ;
V_2 -> V_24 = 0 ;
for ( V_5 = V_6 = 0 ; V_5 < V_4 -> V_25 ; V_5 ++ ) {
if ( V_4 -> V_22 [ V_5 ] . V_26 == 0 )
continue;
if ( ! F_4 ( V_11 , V_13 , V_6 ? & V_15 -> V_22 [ V_6 - 1 ] : & V_15 -> V_27 ,
& V_4 -> V_22 [ V_5 ] , V_28 ) )
goto V_29;
V_2 -> V_24 += V_4 -> V_22 [ V_5 ] . V_26 ;
V_6 ++ ;
}
V_15 -> V_25 = V_6 ;
V_15 -> V_30 = V_2 -> V_24 ;
V_7 = 1 ;
goto V_31;
V_29:
while ( V_6 ) {
struct V_32 * V_27 = -- V_6 ? & V_15 -> V_22 [ V_6 - 1 ] : & V_15 -> V_27 ;
F_5 ( V_27 -> V_33 ) ;
}
V_15 -> V_25 = 0 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_34 = V_4 -> V_34 ;
V_9 . V_35 = V_36 ;
V_9 . V_37 = V_38 ;
V_9 . V_2 = & V_2 -> V_16 ;
F_6 ( F_7 ( V_2 -> V_16 . V_39 ) , & V_9 , 1 ) ;
V_7 = 0 ;
V_31:
return V_7 ;
}
int F_8 ( struct V_1 * V_2 , int V_40 )
{
unsigned long V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_20 ;
struct V_3 * V_4 ;
void (* F_9)( struct V_47 * , void * );
T_1 V_48 ;
int V_7 ;
if ( V_2 -> V_16 . V_20 ) {
V_20 = F_10 ( V_2 -> V_16 . V_20 ) ;
F_9 = V_20 -> V_49 . V_50 ;
V_43 = & V_20 -> V_43 ;
} else {
V_20 = NULL ;
F_9 = NULL ;
V_43 = & V_2 -> V_51 ;
}
F_11 ( & V_43 -> V_52 , V_41 ) ;
if ( ! ( V_53 [ V_2 -> V_54 ] & V_55 ) ) {
V_7 = 0 ;
goto V_56;
}
V_45 = V_43 -> V_45 ;
V_48 = V_45 -> V_48 ;
if ( V_48 >= V_43 -> V_57 )
V_48 = 0 ;
if ( F_12 ( V_48 == V_45 -> V_58 ) ) {
V_7 = 0 ;
goto V_56;
}
F_13 () ;
V_4 = F_14 ( V_43 , V_48 ) ;
if ( ++ V_48 >= V_43 -> V_57 )
V_48 = 0 ;
V_45 -> V_48 = V_48 ;
if ( ! V_40 && ! F_1 ( V_2 , V_4 ) ) {
V_7 = - 1 ;
goto V_56;
}
V_2 -> V_59 = V_4 -> V_34 ;
V_7 = 1 ;
F_15 ( V_60 , & V_2 -> V_61 ) ;
if ( F_9 ) {
T_1 V_62 ;
V_62 = V_45 -> V_58 ;
if ( V_62 >= V_43 -> V_57 )
V_62 = 0 ;
if ( V_62 < V_48 )
V_62 += V_43 -> V_57 - V_48 ;
else
V_62 -= V_48 ;
if ( V_62 < V_20 -> V_63 ) {
struct V_47 V_64 ;
V_20 -> V_63 = 0 ;
F_16 ( & V_43 -> V_52 , V_41 ) ;
V_64 . V_17 = V_2 -> V_16 . V_17 ;
V_64 . V_65 . V_20 = V_2 -> V_16 . V_20 ;
V_64 . V_66 = V_67 ;
F_9 ( & V_64 , V_20 -> V_49 . V_68 ) ;
goto V_31;
}
}
V_56:
F_16 ( & V_43 -> V_52 , V_41 ) ;
V_31:
return V_7 ;
}
static int F_17 ( union V_69 * V_70 , T_2 V_71 , T_2 V_72 )
{
return ( V_70 -> V_73 . V_74 == V_72 &&
( V_70 -> V_73 . V_75 == V_71 ||
V_70 -> V_73 . V_75 == V_76 ) ) ;
}
int F_18 ( struct V_77 * V_78 , struct V_79 * V_80 ,
int V_81 , struct V_1 * V_2 , T_1 V_82 )
{
T_2 V_83 ;
unsigned long V_41 ;
T_3 V_84 = V_78 -> V_85 [ V_2 -> V_86 . V_87 ] ;
if ( V_2 -> V_88 == V_89 && ( V_82 & V_90 ) ) {
if ( ! V_81 ) {
if ( V_2 -> V_91 . V_92 & V_93 )
goto V_94;
} else {
if ( ! ( V_2 -> V_91 . V_92 & V_93 ) )
goto V_94;
V_83 = F_19 ( V_78 , V_2 -> V_91 . V_95 . V_96 ) ;
if ( ! F_17 ( & V_80 -> V_97 . V_98 . V_95 . V_99 , V_78 -> V_100 . V_71 ,
V_83 ) )
goto V_94;
if ( ! F_17 (
& V_80 -> V_97 . V_98 . V_95 . V_101 ,
V_2 -> V_91 . V_95 . V_99 . V_73 . V_75 ,
V_2 -> V_91 . V_95 . V_99 . V_73 . V_74 ) )
goto V_94;
}
if ( F_12 ( F_20 ( F_21 ( V_78 ) , ( V_102 ) V_82 ,
V_84 , F_22 ( V_80 -> V_103 [ 3 ] ) ) ) ) {
F_23 ( V_78 , V_104 ,
( V_102 ) V_82 ,
( F_22 ( V_80 -> V_103 [ 0 ] ) >> 4 ) & 0xF ,
0 , V_2 -> V_16 . V_105 ,
F_22 ( V_80 -> V_103 [ 3 ] ) ,
F_22 ( V_80 -> V_103 [ 1 ] ) ) ;
goto V_94;
}
if ( F_22 ( V_80 -> V_103 [ 3 ] ) != V_2 -> V_91 . V_106 ||
F_21 ( V_78 ) -> V_107 != V_2 -> V_91 . V_108 )
goto V_94;
F_11 ( & V_2 -> V_109 , V_41 ) ;
F_24 ( V_2 ) ;
F_16 ( & V_2 -> V_109 , V_41 ) ;
} else {
if ( ! V_81 ) {
if ( V_2 -> V_86 . V_92 & V_93 )
goto V_94;
} else {
if ( ! ( V_2 -> V_86 . V_92 & V_93 ) )
goto V_94;
V_83 = F_19 ( V_78 ,
V_2 -> V_86 . V_95 . V_96 ) ;
if ( ! F_17 ( & V_80 -> V_97 . V_98 . V_95 . V_99 , V_78 -> V_100 . V_71 ,
V_83 ) )
goto V_94;
if ( ! F_17 (
& V_80 -> V_97 . V_98 . V_95 . V_101 ,
V_2 -> V_86 . V_95 . V_99 . V_73 . V_75 ,
V_2 -> V_86 . V_95 . V_99 . V_73 . V_74 ) )
goto V_94;
}
if ( F_12 ( F_20 ( F_21 ( V_78 ) , ( V_102 ) V_82 ,
V_84 , F_22 ( V_80 -> V_103 [ 3 ] ) ) ) ) {
F_23 ( V_78 , V_104 ,
( V_102 ) V_82 ,
( F_22 ( V_80 -> V_103 [ 0 ] ) >> 4 ) & 0xF ,
0 , V_2 -> V_16 . V_105 ,
F_22 ( V_80 -> V_103 [ 3 ] ) ,
F_22 ( V_80 -> V_103 [ 1 ] ) ) ;
goto V_94;
}
if ( F_22 ( V_80 -> V_103 [ 3 ] ) != V_2 -> V_86 . V_106 ||
F_21 ( V_78 ) -> V_107 != V_2 -> V_108 )
goto V_94;
if ( V_2 -> V_88 == V_110 &&
! ( V_82 & V_90 ) )
V_2 -> V_88 = V_89 ;
}
return 0 ;
V_94:
return 1 ;
}
static void F_25 ( struct V_1 * V_111 )
{
struct V_77 * V_78 = F_26 ( V_111 -> V_16 . V_17 , V_111 -> V_108 ) ;
struct V_1 * V_2 ;
struct V_112 * V_4 ;
struct V_32 * V_27 ;
unsigned long V_41 ;
struct V_8 V_9 ;
T_4 V_113 ;
T_5 * V_114 ;
enum V_115 V_116 ;
int V_117 ;
int V_7 ;
int V_118 = 0 ;
T_1 V_119 ;
int V_120 = 0 ;
F_27 () ;
V_2 = F_28 ( F_29 ( V_111 -> V_16 . V_17 ) , & V_78 -> V_100 ,
V_111 -> V_121 ) ;
F_11 ( & V_111 -> V_109 , V_41 ) ;
if ( ( V_111 -> V_122 & ( V_123 | V_124 ) ) ||
! ( V_53 [ V_111 -> V_54 ] & V_125 ) )
goto V_56;
V_111 -> V_122 |= V_123 ;
V_126:
F_30 () ;
if ( V_111 -> V_127 == F_31 ( V_111 -> V_128 ) )
goto V_129;
V_4 = F_32 ( V_111 , V_111 -> V_127 ) ;
if ( ! ( V_53 [ V_111 -> V_54 ] & V_130 ) ) {
if ( ! ( V_53 [ V_111 -> V_54 ] & V_131 ) )
goto V_129;
V_116 = V_132 ;
goto V_133;
}
if ( V_111 -> V_127 == V_111 -> V_134 ) {
if ( ++ V_111 -> V_134 >= V_111 -> V_135 )
V_111 -> V_134 = 0 ;
}
F_16 ( & V_111 -> V_109 , V_41 ) ;
if ( ! V_2 || ! ( V_53 [ V_2 -> V_54 ] & V_55 ) ||
V_2 -> V_16 . V_136 != V_111 -> V_16 . V_136 ) {
V_78 -> V_100 . V_137 ++ ;
if ( V_111 -> V_16 . V_136 == V_138 )
V_116 = V_139 ;
else
V_116 = V_140 ;
goto V_141;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_116 = V_140 ;
V_117 = 1 ;
V_111 -> V_142 . V_27 = V_4 -> V_22 [ 0 ] ;
V_111 -> V_142 . V_22 = V_4 -> V_22 + 1 ;
V_111 -> V_142 . V_25 = V_4 -> V_143 . V_25 ;
V_111 -> V_144 = V_4 -> V_26 ;
switch ( V_4 -> V_143 . V_37 ) {
case V_145 :
goto V_146;
case V_147 :
if ( ! ( V_4 -> V_143 . V_148 & V_149 ) ) {
if ( F_33 ( V_111 ,
V_4 -> V_143 . V_150 . V_151 ) )
V_116 = V_36 ;
V_120 = 1 ;
}
goto V_146;
case V_152 :
if ( ! F_33 ( V_2 , V_4 -> V_143 . V_150 . V_151 ) ) {
V_9 . V_153 = V_154 ;
V_9 . V_150 . V_151 = V_4 -> V_143 . V_150 . V_151 ;
}
goto V_155;
case V_156 :
V_9 . V_153 = V_157 ;
V_9 . V_150 . V_158 = V_4 -> V_143 . V_150 . V_158 ;
case V_159 :
V_155:
V_7 = F_8 ( V_2 , 0 ) ;
if ( V_7 < 0 )
goto V_160;
if ( ! V_7 )
goto V_161;
break;
case V_162 :
if ( F_12 ( ! ( V_2 -> V_163 & V_164 ) ) )
goto V_165;
V_9 . V_153 = V_157 ;
V_9 . V_150 . V_158 = V_4 -> V_143 . V_150 . V_158 ;
V_7 = F_8 ( V_2 , 1 ) ;
if ( V_7 < 0 )
goto V_160;
if ( ! V_7 )
goto V_161;
goto V_166;
case V_167 :
V_118 = F_3 ( V_2 -> V_16 . V_13 ) -> V_168 ;
if ( F_12 ( ! ( V_2 -> V_163 & V_164 ) ) )
goto V_165;
V_166:
if ( V_4 -> V_26 == 0 )
break;
if ( F_12 ( ! F_34 ( V_2 , & V_2 -> V_21 . V_27 , V_4 -> V_26 ,
V_4 -> V_169 . V_170 ,
V_4 -> V_169 . V_171 ,
V_164 ) ) )
goto V_172;
V_2 -> V_21 . V_22 = NULL ;
V_2 -> V_21 . V_25 = 1 ;
V_2 -> V_21 . V_30 = V_4 -> V_26 ;
break;
case V_173 :
if ( F_12 ( ! ( V_2 -> V_163 & V_174 ) ) )
goto V_165;
if ( F_12 ( ! F_34 ( V_2 , & V_111 -> V_142 . V_27 , V_4 -> V_26 ,
V_4 -> V_169 . V_170 ,
V_4 -> V_169 . V_171 ,
V_174 ) ) )
goto V_172;
V_117 = 0 ;
V_111 -> V_142 . V_22 = NULL ;
V_111 -> V_142 . V_25 = 1 ;
V_2 -> V_21 . V_27 = V_4 -> V_22 [ 0 ] ;
V_2 -> V_21 . V_22 = V_4 -> V_22 + 1 ;
V_2 -> V_21 . V_25 = V_4 -> V_143 . V_25 ;
V_2 -> V_21 . V_30 = V_4 -> V_26 ;
break;
case V_175 :
case V_176 :
if ( F_12 ( ! ( V_2 -> V_163 & V_177 ) ) )
goto V_165;
if ( F_12 ( ! F_34 ( V_2 , & V_2 -> V_21 . V_27 , sizeof( T_4 ) ,
V_4 -> V_178 . V_170 ,
V_4 -> V_178 . V_171 ,
V_177 ) ) )
goto V_172;
V_114 = ( T_5 * ) V_2 -> V_21 . V_27 . V_179 ;
V_113 = V_4 -> V_178 . V_180 ;
* ( T_4 * ) V_111 -> V_142 . V_27 . V_179 =
( V_4 -> V_143 . V_37 == V_176 ) ?
( T_4 ) F_35 ( V_113 , V_114 ) - V_113 :
( T_4 ) F_36 ( ( T_4 * ) V_2 -> V_21 . V_27 . V_179 ,
V_113 , V_4 -> V_178 . V_181 ) ;
F_5 ( V_2 -> V_21 . V_27 . V_33 ) ;
V_2 -> V_21 . V_25 = 0 ;
goto V_146;
default:
V_116 = V_182 ;
goto V_141;
}
V_27 = & V_111 -> V_142 . V_27 ;
while ( V_111 -> V_144 ) {
T_1 V_183 = V_111 -> V_144 ;
if ( V_183 > V_27 -> V_26 )
V_183 = V_27 -> V_26 ;
if ( V_183 > V_27 -> V_184 )
V_183 = V_27 -> V_184 ;
F_37 ( V_183 == 0 ) ;
F_38 ( & V_2 -> V_21 , V_27 -> V_179 , V_183 , V_117 , V_118 ) ;
V_27 -> V_179 += V_183 ;
V_27 -> V_26 -= V_183 ;
V_27 -> V_184 -= V_183 ;
if ( V_27 -> V_184 == 0 ) {
if ( ! V_117 )
F_5 ( V_27 -> V_33 ) ;
if ( -- V_111 -> V_142 . V_25 )
* V_27 = * V_111 -> V_142 . V_22 ++ ;
} else if ( V_27 -> V_26 == 0 && V_27 -> V_33 -> V_185 ) {
if ( ++ V_27 -> V_62 >= V_186 ) {
if ( ++ V_27 -> V_187 >= V_27 -> V_33 -> V_188 )
break;
V_27 -> V_62 = 0 ;
}
V_27 -> V_179 =
V_27 -> V_33 -> V_189 [ V_27 -> V_187 ] -> V_190 [ V_27 -> V_62 ] . V_179 ;
V_27 -> V_26 =
V_27 -> V_33 -> V_189 [ V_27 -> V_187 ] -> V_190 [ V_27 -> V_62 ] . V_26 ;
}
V_111 -> V_144 -= V_183 ;
}
if ( V_117 )
F_39 ( & V_2 -> V_21 ) ;
if ( ! F_40 ( V_60 , & V_2 -> V_61 ) )
goto V_146;
if ( V_4 -> V_143 . V_37 == V_162 )
V_9 . V_37 = V_191 ;
else
V_9 . V_37 = V_38 ;
V_9 . V_34 = V_2 -> V_59 ;
V_9 . V_35 = V_140 ;
V_9 . V_192 = V_4 -> V_26 ;
V_9 . V_2 = & V_2 -> V_16 ;
V_9 . V_193 = V_2 -> V_121 ;
V_9 . V_194 = V_2 -> V_86 . V_106 ;
V_9 . V_87 = V_2 -> V_86 . V_87 ;
V_9 . V_108 = 1 ;
F_6 ( F_7 ( V_2 -> V_16 . V_39 ) , & V_9 ,
V_4 -> V_143 . V_148 & V_195 ) ;
V_146:
F_11 ( & V_111 -> V_109 , V_41 ) ;
V_78 -> V_100 . V_196 ++ ;
V_133:
V_111 -> V_197 = V_111 -> V_198 ;
F_41 ( V_111 , V_4 , V_116 ) ;
if ( V_120 ) {
F_42 ( & V_111 -> V_199 ) ;
V_120 = 0 ;
}
goto V_126;
V_161:
if ( V_2 -> V_16 . V_136 == V_200 )
goto V_146;
V_78 -> V_100 . V_201 ++ ;
if ( V_111 -> V_197 == 0 ) {
V_116 = V_202 ;
goto V_141;
}
if ( V_111 -> V_198 < 7 )
V_111 -> V_197 -- ;
F_11 ( & V_111 -> V_109 , V_41 ) ;
if ( ! ( V_53 [ V_111 -> V_54 ] & V_55 ) )
goto V_129;
V_119 = V_203 [ V_2 -> V_204 ] ;
F_43 ( V_111 , V_119 ) ;
goto V_129;
V_160:
V_116 = V_205 ;
V_9 . V_35 = V_182 ;
goto V_94;
V_165:
V_116 = V_206 ;
V_9 . V_35 = V_182 ;
goto V_94;
V_172:
V_116 = V_207 ;
V_9 . V_35 = V_36 ;
V_94:
F_44 ( V_2 , V_9 . V_35 ) ;
V_141:
F_11 ( & V_111 -> V_109 , V_41 ) ;
F_41 ( V_111 , V_4 , V_116 ) ;
if ( V_111 -> V_16 . V_136 == V_138 ) {
int V_208 = F_45 ( V_111 , V_132 ) ;
V_111 -> V_122 &= ~ V_123 ;
F_16 ( & V_111 -> V_109 , V_41 ) ;
if ( V_208 ) {
struct V_47 V_64 ;
V_64 . V_17 = V_111 -> V_16 . V_17 ;
V_64 . V_65 . V_2 = & V_111 -> V_16 ;
V_64 . V_66 = V_209 ;
V_111 -> V_16 . V_50 ( & V_64 , V_111 -> V_16 . V_210 ) ;
}
goto V_211;
}
V_129:
V_111 -> V_122 &= ~ V_123 ;
V_56:
F_16 ( & V_111 -> V_109 , V_41 ) ;
V_211:
F_46 () ;
}
T_1 F_47 ( struct V_77 * V_78 , struct V_212 * V_80 ,
struct V_213 * V_95 , T_1 V_214 , T_1 V_215 )
{
V_80 -> V_216 =
F_48 ( ( V_217 << V_218 ) |
( V_95 -> V_219 << V_220 ) |
( V_95 -> V_221 << V_222 ) ) ;
V_80 -> V_223 = F_49 ( ( V_214 - 2 + V_215 + V_224 ) << 2 ) ;
V_80 -> V_225 = V_226 ;
V_80 -> V_227 = V_95 -> V_227 ;
V_80 -> V_101 . V_73 . V_75 = V_78 -> V_100 . V_71 ;
V_80 -> V_101 . V_73 . V_74 =
V_95 -> V_96 < V_228 ?
F_19 ( V_78 , V_95 -> V_96 ) :
F_19 ( V_78 , V_229 ) ;
V_80 -> V_99 = V_95 -> V_99 ;
return sizeof( struct V_212 ) / sizeof( T_1 ) ;
}
static inline void F_50 ( struct V_1 * V_2 , T_1 V_230 )
{
struct V_231 * V_232 = V_2 -> V_232 ;
if ( F_12 ( V_2 -> V_122 & V_233 ) )
F_51 ( V_2 ) ;
if ( ! ( V_2 -> V_122 & V_234 ) ) {
if ( V_2 -> V_235 < 0 )
V_2 -> V_235 = F_52 ( V_232 -> V_236 ) ;
if ( V_2 -> V_235 >= 0 ) {
V_2 -> V_237 = V_230 ;
V_232 -> V_238 -> V_239 |= V_240 ;
V_232 -> V_238 -> V_241 = V_2 -> V_235 ;
V_2 -> V_122 |= V_234 ;
}
} else {
if ( V_2 -> V_235 >= 0 ) {
V_232 -> V_238 -> V_239 |= V_242 ;
V_232 -> V_238 -> V_241 = V_2 -> V_235 ;
V_232 -> V_238 -> V_243 ++ ;
V_232 -> V_238 -> V_244 [ 0 ] =
F_53 (
( V_245 V_102 ) F_49 ( ( V_102 ) V_230 ) ,
V_246 ,
16 ,
16 ) ;
if ( ( V_230 & 0xffff0000 ) !=
( V_2 -> V_237 & 0xffff0000 ) ) {
V_232 -> V_238 -> V_243 ++ ;
V_232 -> V_238 -> V_244 [ 1 ] =
F_53 (
( V_245 V_102 ) F_49 (
( V_102 ) ( V_230 >> 16 ) ) ,
V_246 ,
0 ,
16 ) ;
}
}
}
}
void F_54 ( struct V_1 * V_2 , struct V_247 * V_248 ,
T_1 V_82 , T_1 V_249 , int V_250 ,
struct V_251 * V_252 )
{
struct V_231 * V_232 = V_2 -> V_232 ;
struct V_77 * V_78 = V_252 -> V_78 ;
V_102 V_253 ;
T_1 V_215 ;
T_1 V_254 ;
T_1 V_255 ;
V_254 = - V_252 -> V_256 -> V_257 & 3 ;
V_215 = ( V_252 -> V_256 -> V_257 + V_254 ) >> 2 ;
V_253 = V_258 ;
if ( F_12 ( V_2 -> V_86 . V_92 & V_93 ) ) {
V_2 -> V_259 += F_47 ( V_78 ,
& V_252 -> V_256 -> V_260 . V_80 . V_97 . V_98 . V_95 ,
& V_2 -> V_86 . V_95 ,
V_2 -> V_259 , V_215 ) ;
V_253 = V_261 ;
V_250 = 0 ;
}
V_253 |= ( V_232 -> V_262 & 0xf ) << 12 | ( V_2 -> V_86 . V_87 & 0xf ) << 4 ;
V_232 -> V_238 -> V_239 = 0 ;
V_232 -> V_238 -> V_243 = 0 ;
V_232 -> V_238 -> V_241 = 0 ;
if ( V_2 -> V_88 == V_263 )
V_82 |= V_90 ;
else
V_250 = 0 ;
if ( V_250 )
F_50 ( V_2 , V_249 ) ;
else
V_2 -> V_122 &= ~ V_234 ;
V_252 -> V_256 -> V_260 . V_80 . V_103 [ 0 ] = F_49 ( V_253 ) ;
V_252 -> V_256 -> V_260 . V_80 . V_103 [ 1 ] = F_49 ( V_2 -> V_86 . V_106 ) ;
V_252 -> V_256 -> V_260 . V_80 . V_103 [ 2 ] =
F_49 ( V_2 -> V_259 + V_215 + V_224 ) ;
V_252 -> V_256 -> V_260 . V_80 . V_103 [ 3 ] = F_49 ( F_21 ( V_78 ) -> V_264 |
V_2 -> V_86 . V_265 ) ;
V_82 |= F_55 ( V_78 , V_2 -> V_266 ) ;
V_82 |= V_254 << 20 ;
V_248 -> V_267 [ 0 ] = F_48 ( V_82 ) ;
V_255 = V_2 -> V_121 ;
if ( V_2 -> V_122 & V_268 ) {
V_2 -> V_122 &= ~ V_268 ;
V_255 |= ( V_269 << V_270 ) ;
}
V_248 -> V_267 [ 1 ] = F_48 ( V_255 ) ;
V_248 -> V_267 [ 2 ] = F_48 ( V_249 ) ;
}
void F_56 ( struct V_271 * V_272 )
{
struct V_273 * V_274 = F_57 ( V_272 , struct V_273 , V_275 ) ;
struct V_1 * V_2 = F_58 ( V_274 ) ;
F_59 ( V_2 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_251 V_252 ;
struct V_231 * V_232 = V_2 -> V_232 ;
int (* F_60)( struct V_1 * V_2 , struct V_251 * V_252 );
unsigned long V_276 ;
unsigned long V_277 ;
int V_278 ;
V_252 . V_279 = F_2 ( V_2 -> V_16 . V_17 ) ;
V_252 . V_78 = F_26 ( V_2 -> V_16 . V_17 , V_2 -> V_108 ) ;
V_252 . V_280 = F_21 ( V_252 . V_78 ) ;
switch ( V_2 -> V_16 . V_136 ) {
case V_138 :
if ( ! V_281 && ( ( V_2 -> V_86 . V_106 & ~ ( ( 1 << V_252 . V_280 -> V_282
) - 1 ) ) ==
V_252 . V_280 -> V_264 ) ) {
F_25 ( V_2 ) ;
return;
}
F_60 = V_283 ;
V_277 = ( V_2 -> V_284 ) ;
break;
case V_200 :
if ( ! V_281 && ( ( V_2 -> V_86 . V_106 & ~ ( ( 1 << V_252 . V_280 -> V_282
) - 1 ) ) ==
V_252 . V_280 -> V_264 ) ) {
F_25 ( V_2 ) ;
return;
}
F_60 = V_285 ;
V_277 = V_286 ;
break;
default:
F_60 = V_287 ;
V_277 = V_286 ;
}
F_11 ( & V_2 -> V_109 , V_252 . V_41 ) ;
if ( ! F_61 ( V_2 ) ) {
F_16 ( & V_2 -> V_109 , V_252 . V_41 ) ;
return;
}
V_2 -> V_122 |= V_123 ;
V_276 = V_288 + ( V_277 ) / 8 ;
V_278 = V_232 -> V_236 ? V_232 -> V_236 -> V_278 :
F_62 ( F_63 ( V_252 . V_280 -> V_289 -> V_290 ) ) ;
V_252 . V_256 = F_64 ( V_2 ) ;
do {
if ( V_2 -> V_259 != 0 ) {
F_16 ( & V_2 -> V_109 , V_252 . V_41 ) ;
if ( F_65 ( V_2 , & V_252 ) )
return;
V_2 -> V_259 = 0 ;
if ( F_12 ( F_66 ( V_288 , V_276 ) ) ) {
if ( F_67 ( V_278 ,
V_252 . V_280 -> V_291 ) ) {
F_11 (
& V_2 -> V_109 ,
V_252 . V_41 ) ;
V_2 -> V_122 &= ~ V_123 ;
F_68 ( V_2 ) ;
F_16 (
& V_2 -> V_109 ,
V_252 . V_41 ) ;
F_69 (
* V_252 . V_280 -> V_289 -> V_292 ) ;
return;
}
if ( ! F_70 () ) {
F_71 () ;
F_69 (
* V_252 . V_280 -> V_289 -> V_292 ) ;
}
V_276 = V_288 + ( V_277 ) / 8 ;
}
F_11 ( & V_2 -> V_109 , V_252 . V_41 ) ;
}
} while ( F_60 ( V_2 , & V_252 ) );
F_16 ( & V_2 -> V_109 , V_252 . V_41 ) ;
}
void F_41 ( struct V_1 * V_2 , struct V_112 * V_4 ,
enum V_115 V_35 )
{
T_1 V_293 , V_294 ;
if ( ! ( V_53 [ V_2 -> V_54 ] & V_125 ) )
return;
V_294 = V_2 -> V_127 ;
V_293 = V_294 ;
if ( ++ V_294 >= V_2 -> V_135 )
V_294 = 0 ;
V_2 -> V_127 = V_294 ;
F_72 () ;
F_73 ( V_4 ) ;
if ( V_2 -> V_16 . V_136 == V_295 ||
V_2 -> V_16 . V_136 == V_296 ||
V_2 -> V_16 . V_136 == V_297 )
F_42 ( & F_74 ( V_4 -> V_298 . V_299 ) -> V_300 ) ;
F_75 ( V_2 , V_4 , V_35 ) ;
if ( V_2 -> V_301 == V_293 )
V_2 -> V_301 = V_294 ;
if ( V_2 -> V_134 == V_293 )
V_2 -> V_134 = V_294 ;
if ( V_2 -> V_302 == V_293 )
V_2 -> V_302 = V_294 ;
if ( V_2 -> V_54 == V_303 && V_294 == V_2 -> V_134 )
V_2 -> V_304 = 0 ;
}
