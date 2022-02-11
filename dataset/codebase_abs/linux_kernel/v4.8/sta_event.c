void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! V_2 -> V_7 )
return;
F_2 ( V_6 , V_8 ,
L_1 ) ;
V_2 -> V_7 = false ;
V_2 -> V_9 = false ;
V_2 -> V_10 = false ;
if ( ( F_3 ( V_2 ) == V_11 ) &&
F_4 ( V_2 -> V_6 -> V_12 ) ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_6 -> V_13 )
F_6 ( V_2 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 . V_25 = false ;
V_2 -> V_24 . V_26 = false ;
V_2 -> V_27 = 0 ;
V_2 -> V_24 . V_28 = false ;
V_2 -> V_29 = 0 ;
V_2 -> V_24 . V_30 = false ;
V_2 -> V_24 . V_31 = 0 ;
V_2 -> V_32 = true ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = 0 ;
V_2 -> V_35 = false ;
if ( ( F_3 ( V_2 ) == V_11 ||
F_3 ( V_2 ) == V_36 ) && V_2 -> V_37 )
F_8 ( V_2 ) ;
if ( V_2 -> V_38 == V_39 ) {
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = false ;
}
F_2 ( V_6 , V_8 ,
L_2 ,
V_2 -> V_43 . V_44 , V_2 -> V_43 . V_45 ) ;
F_2 ( V_6 , V_8 ,
L_3 ,
V_2 -> V_46 . V_47 . V_44 . V_44 ,
V_2 -> V_46 . V_47 . V_44 . V_45 ) ;
memcpy ( & V_2 -> V_43 ,
& V_2 -> V_46 . V_47 . V_44 ,
sizeof( struct V_48 ) ) ;
memcpy ( V_2 -> V_49 ,
V_2 -> V_46 . V_47 . V_50 , V_51 ) ;
memset ( & V_2 -> V_46 , 0x00 , sizeof( V_2 -> V_46 ) ) ;
V_6 -> V_52 = false ;
V_6 -> V_53 = false ;
if ( V_6 -> V_54 && V_6 -> V_55 )
return;
V_2 -> V_7 = false ;
F_2 ( V_6 , V_56 ,
L_4 ,
V_2 -> V_57 , V_3 ) ;
if ( V_2 -> V_38 == V_58 ||
V_2 -> V_38 == V_59 ) {
F_9 ( V_2 -> V_60 , V_3 , NULL , 0 ,
! V_4 , V_61 ) ;
}
F_10 ( V_2 -> V_57 ) ;
F_11 ( V_2 -> V_60 , V_6 ) ;
if ( F_12 ( V_2 -> V_60 ) )
F_13 ( V_2 -> V_60 ) ;
F_14 ( V_2 , V_62 ,
V_63 , 0 , NULL , false ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
int V_66 = 0 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_67 * V_68 ;
struct V_69 * V_70 =
( void * ) V_65 -> V_71 + sizeof( V_6 -> V_72 ) ;
T_2 * V_73 = V_70 -> V_74 ;
if ( V_65 -> V_75 < ( sizeof( struct V_69 ) -
sizeof( T_1 ) - sizeof( V_6 -> V_72 ) ) ) {
F_2 ( V_6 , ERROR , L_5 ) ;
return - 1 ;
}
V_68 = F_16 ( V_2 , V_70 -> V_74 ) ;
if ( ! V_68 ) {
F_2 ( V_6 , ERROR , L_6 ) ;
return - 1 ;
}
switch ( F_17 ( V_70 -> type ) ) {
case V_76 :
F_18 ( V_2 -> V_60 ,
V_70 -> V_74 ,
V_77 ,
F_17 ( V_70 -> V_78 . V_3 ) ,
V_61 ) ;
break;
case V_79 :
F_2 ( V_6 , V_80 , L_7 ) ;
F_2 ( V_6 , V_80 ,
L_8 ,
V_70 -> V_78 . V_81 . V_82 ,
V_70 -> V_78 . V_81 . V_83 ,
V_70 -> V_78 . V_81 . V_84 ) ;
if ( V_70 -> V_78 . V_81 . V_82 != 0 ) {
switch ( V_70 -> V_78 . V_81 . V_84 ) {
case V_85 :
V_68 -> V_86 = V_87 ;
break;
case V_88 :
V_68 -> V_86 = V_89 ;
break;
default:
break;
}
return V_66 ;
}
switch ( V_70 -> V_78 . V_81 . V_84 ) {
case V_85 :
if ( V_68 -> V_86 == V_87 )
break;
F_19 ( V_2 , V_73 ,
false ) ;
V_68 -> V_86 = V_87 ;
break;
case V_88 :
if ( V_68 -> V_86 == V_89 )
break;
F_19 ( V_2 , V_73 ,
true ) ;
V_68 -> V_86 = V_89 ;
break;
default:
break;
}
break;
case V_90 :
F_2 ( V_6 , V_80 , L_9 ) ;
V_68 -> V_86 = V_91 ;
break;
case V_92 :
F_2 ( V_6 , V_80 ,
L_10 ,
V_70 -> V_78 . V_93 ) ;
break;
default:
break;
}
return V_66 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 ;
struct V_67 * V_68 ;
unsigned long V_98 ;
V_97 = ( void * ) V_95 ;
F_2 ( V_2 -> V_6 , V_80 ,
L_11 ,
V_97 -> V_99 , V_97 -> V_100 ,
V_97 -> V_101 ) ;
if ( F_21 ( V_97 -> V_99 , V_2 -> V_60 -> V_102 ) ) {
if ( V_97 -> V_100 )
V_2 -> V_10 = false ;
else
V_2 -> V_10 = true ;
} else if ( F_22 ( V_97 -> V_99 ) ) {
F_23 ( V_2 , V_97 -> V_99 , V_97 -> V_100 ) ;
} else {
F_24 ( & V_2 -> V_103 , V_98 ) ;
V_68 = F_16 ( V_2 , V_97 -> V_99 ) ;
F_25 ( & V_2 -> V_103 , V_98 ) ;
if ( V_68 && V_68 -> V_100 != V_97 -> V_100 ) {
V_68 -> V_100 = V_97 -> V_100 ;
F_23 ( V_2 , V_97 -> V_99 ,
V_97 -> V_100 ) ;
}
}
}
static void F_26 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 ;
struct V_67 * V_68 ;
int V_82 ;
unsigned long V_98 ;
V_97 = ( void * ) V_95 ;
F_2 ( V_2 -> V_6 , V_80 ,
L_12 ,
V_97 -> V_99 , V_97 -> V_100 ,
V_97 -> V_101 ) ;
if ( F_21 ( V_97 -> V_99 , V_2 -> V_57 ) ) {
if ( V_97 -> V_100 )
V_2 -> V_10 = false ;
else
V_2 -> V_10 = true ;
} else {
if ( ! F_4 ( V_2 -> V_6 -> V_12 ) )
return;
V_82 = F_27 ( V_2 , V_97 -> V_99 ) ;
if ( F_28 ( V_82 ) ) {
F_24 ( & V_2 -> V_103 , V_98 ) ;
V_68 = F_16 ( V_2 , V_97 -> V_99 ) ;
F_25 ( & V_2 -> V_103 , V_98 ) ;
if ( V_68 && V_68 -> V_100 != V_97 -> V_100 ) {
V_68 -> V_100 = V_97 -> V_100 ;
F_23 ( V_2 ,
V_97 -> V_99 ,
V_97 -> V_100 ) ;
}
}
}
}
void F_29 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_94 * V_95 ;
T_1 V_108 , V_109 , V_110 ;
int V_111 , V_112 , V_113 , V_114 ;
struct V_1 * V_115 ;
V_108 = V_65 -> V_75 - sizeof( V_116 ) ;
V_105 = ( void * ) V_65 -> V_71 + sizeof( V_116 ) ;
if ( F_17 ( V_105 -> V_117 . type ) != V_118 ||
V_108 < sizeof( struct V_104 ) ) {
F_2 ( V_6 , ERROR ,
L_13 ) ;
return;
}
V_6 -> V_119 = F_17 ( V_105 -> V_82 ) ;
F_2 ( V_6 , V_80 , L_14 ,
V_6 -> V_119 ? L_15 : L_16 ) ;
V_108 -= sizeof( struct V_104 ) ;
V_95 = (struct V_94 * ) V_105 -> V_120 ;
while ( V_108 >= ( int ) sizeof( struct V_94 ) ) {
V_109 = F_17 ( V_95 -> type ) ;
V_110 = F_17 ( V_95 -> V_75 ) ;
if ( ( sizeof( struct V_94 ) + V_110 ) >
V_108 ) {
F_2 ( V_6 , ERROR , L_17
L_18 , V_110 , V_108 ) ;
break;
}
if ( V_109 != V_121 ) {
F_2 ( V_6 , ERROR , L_19 ,
V_109 ) ;
break;
}
V_107 = (struct V_106 * ) V_95 ;
V_111 = V_107 -> V_111 ;
for ( V_114 = 0 ; V_114 < V_111 ; V_114 ++ ) {
V_112 = V_107 -> V_122 [ V_114 ] >> 4 ;
V_113 = V_107 -> V_122 [ V_114 ] & V_123 ;
V_115 = F_30 ( V_6 , V_113 ,
V_112 ) ;
if ( ! V_115 ) {
F_2 ( V_6 , ERROR ,
L_20
L_21 ) ;
continue;
}
if ( V_6 -> V_124 == V_125 ) {
T_2 V_126 ;
V_126 = V_107 -> V_127 . V_128 ;
if ( V_126 == V_129 ||
V_126 == V_130 )
V_115 -> V_131 = V_126 ;
}
}
V_108 -= sizeof( struct V_94 ) +
V_110 ;
V_95 = ( void * ) ( ( T_2 * ) V_95 + V_110 +
sizeof( struct V_94 ) ) ;
}
if ( V_6 -> V_124 == V_125 ) {
V_6 -> V_52 = true ;
V_6 -> V_132 = true ;
F_31 ( V_6 ) ;
}
}
void F_32 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_94 * V_95 ;
T_1 V_109 , V_110 ;
int V_108 ;
if ( ! V_2 -> V_7 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_22 ,
V_2 -> V_133 ) ;
return;
}
V_108 = V_65 -> V_75 - sizeof( V_116 ) ;
V_95 = ( void * ) V_65 -> V_71 + sizeof( V_116 ) ;
while ( V_108 >= ( int ) sizeof( struct V_94 ) ) {
V_109 = F_17 ( V_95 -> type ) ;
V_110 = F_17 ( V_95 -> V_75 ) ;
if ( ( sizeof( struct V_94 ) + V_110 ) >
V_108 ) {
F_2 ( V_2 -> V_6 , ERROR ,
L_23 ,
V_110 , V_108 ) ;
break;
}
if ( V_109 == V_134 ) {
if ( F_3 ( V_2 ) == V_11 )
F_26 ( V_2 , V_95 ) ;
else
F_20 ( V_2 , V_95 ) ;
}
V_108 -= sizeof( struct V_94 ) +
V_110 ;
V_95 = ( void * ) ( ( T_2 * ) V_95 + V_110 +
sizeof( struct V_94 ) ) ;
}
}
void F_33 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_94 * V_95 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
T_3 V_75 = V_65 -> V_75 - sizeof( V_116 ) ;
T_2 * V_139 = V_65 -> V_71 + sizeof( V_116 ) ;
T_1 V_109 , V_110 ;
while ( V_75 >= sizeof( struct V_94 ) ) {
V_95 = (struct V_94 * ) V_139 ;
V_110 = F_17 ( V_95 -> V_75 ) ;
V_109 = F_17 ( V_95 -> type ) ;
if ( ( V_110 + sizeof( struct V_94 ) ) > V_75 )
break;
switch ( V_109 ) {
case V_140 :
V_136 =
(struct V_135 * ) V_95 ;
V_6 -> V_141 = V_136 -> V_141 ;
V_6 -> V_142 =
V_136 -> V_143 ;
V_6 -> V_144 =
V_136 -> V_145 ;
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
break;
case V_146 :
V_138 =
(struct V_137 * ) V_95 ;
V_6 -> V_147 = V_138 -> V_147 ;
V_6 -> V_148 = F_17 ( V_138 -> V_149 ) ;
V_6 -> V_150 = F_17 ( V_138 -> V_151 ) ;
break;
default:
break;
}
V_75 -= V_110 + sizeof( struct V_94 ) ;
V_139 += V_110 +
sizeof( struct V_94 ) ;
}
F_36 ( V_6 -> V_152 , L_24 ,
V_6 -> V_147 , V_6 -> V_148 ,
V_6 -> V_141 , V_6 -> V_142 ,
V_6 -> V_144 ) ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_66 = 0 ;
V_116 V_153 = V_6 -> V_72 ;
T_1 V_154 , V_3 ;
switch ( V_153 ) {
case V_155 :
F_2 ( V_6 , ERROR ,
L_25 ) ;
break;
case V_156 :
F_2 ( V_6 , V_80 , L_26 ) ;
if ( ! F_12 ( V_2 -> V_60 ) )
F_38 ( V_2 -> V_60 ) ;
F_39 ( V_2 -> V_60 , V_6 ) ;
break;
case V_157 :
F_2 ( V_6 , V_80 , L_27 ) ;
if ( V_2 -> V_158 . V_159 ) {
F_2 ( V_6 , V_8 ,
L_28 ) ;
break;
}
V_6 -> V_160 . V_161 ++ ;
if ( V_2 -> V_7 ) {
V_3 =
F_17 ( * ( V_162 * ) V_6 -> V_163 ) ;
F_1 ( V_2 , V_3 , true ) ;
}
break;
case V_164 :
F_2 ( V_6 , V_80 , L_29 ) ;
if ( V_2 -> V_158 . V_159 ) {
F_2 ( V_6 , V_8 ,
L_30 ) ;
break;
}
V_6 -> V_160 . V_165 ++ ;
if ( V_2 -> V_7 ) {
V_3 =
F_17 ( * ( V_162 * ) V_6 -> V_163 ) ;
F_1 ( V_2 , V_3 , true ) ;
}
break;
case V_166 :
F_2 ( V_6 , V_80 , L_31 ) ;
V_6 -> V_160 . V_167 ++ ;
if ( V_2 -> V_7 ) {
V_3 =
F_17 ( * ( V_162 * ) V_6 -> V_163 ) ;
F_1 ( V_2 , V_3 , true ) ;
}
break;
case V_168 :
F_2 ( V_6 , V_80 , L_32 ) ;
V_6 -> V_169 = V_170 ;
F_40 ( V_6 ) ;
break;
case V_171 :
F_2 ( V_6 , V_80 , L_33 ) ;
if ( ! V_6 -> V_53 &&
( V_2 -> V_10 ||
( V_2 -> V_38 == V_39 ) ) &&
V_2 -> V_7 && V_6 -> V_172 . V_173 ) {
V_6 -> V_53 = true ;
F_2 ( V_6 , V_80 ,
L_34 ) ;
}
V_6 -> V_52 = false ;
if ( V_6 -> V_53 && V_6 -> V_174 ) {
if ( F_41 ( V_2 ) ) {
if ( V_6 -> V_175 ||
( V_6 -> V_176 . V_177 &&
! V_6 -> V_176 . V_177 ( V_2 ) ) ) {
V_6 -> V_169 = V_178 ;
V_6 -> V_179 = false ;
V_6 -> V_180 = false ;
F_42 ( & V_6 -> V_181 ) ;
break;
}
if ( ! F_43
( V_2 ,
V_182 |
V_183 ) )
V_6 -> V_169 =
V_184 ;
return 0 ;
}
}
V_6 -> V_169 = V_178 ;
V_6 -> V_179 = false ;
V_6 -> V_180 = false ;
F_42 ( & V_6 -> V_181 ) ;
break;
case V_185 :
V_6 -> V_176 . V_186 ( V_6 ) ;
F_2 ( V_6 , V_80 , L_35 ) ;
if ( V_6 -> V_187 )
V_6 -> V_187 = false ;
break;
case V_188 :
F_2 ( V_6 , V_80 , L_36 ) ;
V_66 = F_14 ( V_2 , V_189 ,
0 , 0 , NULL , false ) ;
break;
case V_190 :
F_2 ( V_6 , V_80 , L_37 ) ;
F_44 ( V_2 -> V_60 , V_2 -> V_57 ,
V_191 ,
- 1 , NULL , V_61 ) ;
break;
case V_192 :
F_2 ( V_6 , V_80 , L_38 ) ;
F_44 ( V_2 -> V_60 , V_2 -> V_57 ,
V_193 ,
- 1 , NULL , V_61 ) ;
break;
case V_194 :
case V_195 :
break;
case V_196 :
F_2 ( V_6 , V_80 , L_39 ) ;
V_2 -> V_42 = false ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_60 , V_6 ) ;
if ( F_12 ( V_2 -> V_60 ) )
F_13 ( V_2 -> V_60 ) ;
break;
case V_197 :
F_2 ( V_6 , V_80 , L_40 ) ;
V_66 = F_14 ( V_2 , V_198 ,
V_199 , 0 , NULL , false ) ;
break;
case V_200 :
F_36 ( V_6 -> V_152 , L_41 ) ;
F_45 ( V_2 -> V_201 . V_202 ) ;
if ( V_2 -> V_203 )
V_2 -> V_203 = false ;
break;
case V_204 :
F_2 ( V_6 , V_80 , L_42 ) ;
V_2 -> V_10 = true ;
break;
case V_205 :
F_2 ( V_6 , V_80 , L_43 ) ;
if ( V_6 -> V_206 && ! V_2 -> V_207 )
V_66 = F_46 ( V_2 ,
V_6 -> V_65 -> V_71 ) ;
break;
case V_208 :
F_2 ( V_6 , V_80 , L_44 ) ;
V_66 = F_14 ( V_2 , V_209 ,
0 , 0 , NULL , false ) ;
break;
case V_210 :
F_47 ( V_2 -> V_60 ,
V_211 ,
V_61 ) ;
F_14 ( V_2 , V_212 ,
V_199 , 0 , NULL , false ) ;
V_2 -> V_213 = V_214 ;
F_2 ( V_6 , V_80 , L_45 ) ;
break;
case V_215 :
F_2 ( V_6 , V_80 , L_46 ) ;
break;
case V_216 :
F_2 ( V_6 , V_80 , L_47 ) ;
break;
case V_217 :
F_47 ( V_2 -> V_60 ,
V_218 ,
V_61 ) ;
F_14 ( V_2 , V_212 ,
V_199 , 0 , NULL , false ) ;
V_2 -> V_213 = V_219 ;
F_2 ( V_6 , V_80 , L_48 ) ;
break;
case V_220 :
F_2 ( V_6 , V_80 , L_49 ) ;
break;
case V_221 :
F_2 ( V_6 , V_80 , L_50 ) ;
break;
case V_222 :
F_2 ( V_6 , V_80 , L_51 ) ;
break;
case V_223 :
F_2 ( V_6 , V_80 , L_52 ) ;
break;
case V_224 :
F_2 ( V_6 , V_80 , L_53 ) ;
break;
case V_225 :
F_2 ( V_6 , V_80 , L_54 ) ;
break;
case V_226 :
F_2 ( V_6 , V_80 , L_55 ) ;
break;
case V_227 :
F_2 ( V_6 , V_80 , L_56 ) ;
V_66 = F_14 ( V_2 ,
V_228 ,
V_199 , 0 , NULL , false ) ;
break;
case V_229 :
F_2 ( V_6 , V_80 , L_57 ) ;
F_14 ( V_2 , V_230 ,
V_231 , 0 ,
V_6 -> V_163 , false ) ;
break;
case V_232 :
F_2 ( V_6 , V_80 , L_58 ) ;
F_48 ( V_2 , V_6 -> V_163 ) ;
break;
case V_233 :
F_2 ( V_6 , V_80 , L_59 ) ;
F_49 ( V_2 ,
(struct V_234
* )
V_6 -> V_163 ) ;
break;
case V_235 :
V_154 = F_17 ( * ( V_162 * ) V_6 -> V_163 ) ;
F_2 ( V_6 , V_80 ,
L_60 , V_154 ) ;
V_6 -> V_236 =
F_50 ( T_1 , V_6 -> V_237 , V_154 ) ;
F_2 ( V_6 , V_80 , L_61 ,
V_6 -> V_236 ) ;
break;
case V_238 :
F_2 ( V_6 , V_80 , L_62 ) ;
break;
case V_239 :
F_2 ( V_6 , V_80 , L_63 ) ;
break;
case V_240 :
F_2 ( V_6 , V_80 ,
L_64 , V_153 ) ;
break;
case V_241 :
F_2 ( V_6 , V_80 ,
L_65 ) ;
F_51 ( & V_2 -> V_201 ,
V_2 -> V_242 . V_243 ,
& V_2 -> V_242 . V_244 ,
V_245 ) ;
memset ( & V_2 -> V_242 , 0x00 , sizeof( struct V_246 ) ) ;
break;
case V_247 :
F_2 ( V_6 , V_80 , L_66 ) ;
V_2 -> V_248 =
V_249 + F_52 ( V_250 ) ;
V_2 -> V_251 = V_2 -> V_46 . V_47 . V_252 ;
V_66 = F_14 ( V_2 , V_253 ,
V_231 , 0 ,
V_2 -> V_46 . V_47 . V_50 ,
false ) ;
break;
case V_254 :
V_66 = F_15 ( V_2 , V_6 -> V_65 ) ;
break;
case V_255 :
F_2 ( V_6 , V_80 , L_67 ) ;
F_32 ( V_2 , V_6 -> V_65 ) ;
break;
case V_256 :
F_2 ( V_6 , V_80 , L_68 ) ;
F_29 ( V_2 , V_6 -> V_65 ) ;
break;
case V_257 :
F_2 ( V_6 , V_80 , L_69 ) ;
F_53 ( V_2 , V_6 -> V_163 ) ;
break;
case V_258 :
F_2 ( V_6 , V_80 , L_70 ) ;
V_66 = F_54 ( V_2 ,
V_6 -> V_65 ) ;
break;
case V_259 :
F_2 ( V_6 , V_80 , L_71 ) ;
V_66 = F_55 ( V_2 ,
V_6 -> V_65 ) ;
break;
case V_260 :
F_36 ( V_6 -> V_152 , L_72 ) ;
F_33 ( V_2 ,
V_6 -> V_65 ) ;
break;
default:
F_2 ( V_6 , ERROR , L_73 ,
V_153 ) ;
break;
}
return V_66 ;
}
