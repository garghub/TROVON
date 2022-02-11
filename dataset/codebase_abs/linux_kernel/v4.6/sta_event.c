void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 ( V_5 , V_7 ,
L_1 ) ;
V_2 -> V_6 = false ;
V_2 -> V_8 = false ;
V_2 -> V_9 = false ;
if ( ( F_3 ( V_2 ) == V_10 ) &&
F_4 ( V_2 -> V_5 -> V_11 ) ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_5 -> V_12 )
F_6 ( V_2 ) ;
}
F_7 ( V_2 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 . V_24 = false ;
V_2 -> V_23 . V_25 = false ;
V_2 -> V_26 = 0 ;
V_2 -> V_23 . V_27 = false ;
V_2 -> V_28 = 0 ;
V_2 -> V_23 . V_29 = false ;
V_2 -> V_23 . V_30 = 0 ;
V_2 -> V_31 = true ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_34 = false ;
if ( ( F_3 ( V_2 ) == V_10 ||
F_3 ( V_2 ) == V_35 ) && V_2 -> V_36 )
F_8 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 ) {
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = false ;
}
F_2 ( V_5 , V_7 ,
L_2 ,
V_2 -> V_42 . V_43 , V_2 -> V_42 . V_44 ) ;
F_2 ( V_5 , V_7 ,
L_3 ,
V_2 -> V_45 . V_46 . V_43 . V_43 ,
V_2 -> V_45 . V_46 . V_43 . V_44 ) ;
memcpy ( & V_2 -> V_42 ,
& V_2 -> V_45 . V_46 . V_43 ,
sizeof( struct V_47 ) ) ;
memcpy ( V_2 -> V_48 ,
V_2 -> V_45 . V_46 . V_49 , V_50 ) ;
memset ( & V_2 -> V_45 , 0x00 , sizeof( V_2 -> V_45 ) ) ;
V_5 -> V_51 = false ;
V_5 -> V_52 = false ;
if ( V_5 -> V_53 && V_5 -> V_54 )
return;
V_2 -> V_6 = false ;
F_2 ( V_5 , V_55 ,
L_4 ,
V_2 -> V_56 , V_3 ) ;
if ( V_2 -> V_37 == V_57 ||
V_2 -> V_37 == V_58 ) {
F_9 ( V_2 -> V_59 , V_3 , NULL , 0 ,
false , V_60 ) ;
}
F_10 ( V_2 -> V_56 ) ;
F_11 ( V_2 -> V_59 , V_5 ) ;
if ( F_12 ( V_2 -> V_59 ) )
F_13 ( V_2 -> V_59 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
int V_63 = 0 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_64 * V_65 ;
struct V_66 * V_67 =
( void * ) V_62 -> V_68 + sizeof( V_5 -> V_69 ) ;
T_2 * V_70 = V_67 -> V_71 ;
if ( V_62 -> V_72 < ( sizeof( struct V_66 ) -
sizeof( T_1 ) - sizeof( V_5 -> V_69 ) ) ) {
F_2 ( V_5 , ERROR , L_5 ) ;
return - 1 ;
}
V_65 = F_15 ( V_2 , V_67 -> V_71 ) ;
if ( ! V_65 ) {
F_2 ( V_5 , ERROR , L_6 ) ;
return - 1 ;
}
switch ( F_16 ( V_67 -> type ) ) {
case V_73 :
F_17 ( V_2 -> V_59 ,
V_67 -> V_71 ,
V_74 ,
F_16 ( V_67 -> V_75 . V_3 ) ,
V_60 ) ;
break;
case V_76 :
F_2 ( V_5 , V_77 , L_7 ) ;
F_2 ( V_5 , V_77 ,
L_8 ,
V_67 -> V_75 . V_78 . V_79 ,
V_67 -> V_75 . V_78 . V_80 ,
V_67 -> V_75 . V_78 . V_81 ) ;
if ( V_67 -> V_75 . V_78 . V_79 != 0 ) {
switch ( V_67 -> V_75 . V_78 . V_81 ) {
case V_82 :
V_65 -> V_83 = V_84 ;
break;
case V_85 :
V_65 -> V_83 = V_86 ;
break;
default:
break;
}
return V_63 ;
}
switch ( V_67 -> V_75 . V_78 . V_81 ) {
case V_82 :
if ( V_65 -> V_83 == V_84 )
break;
F_18 ( V_2 , V_70 ,
false ) ;
V_65 -> V_83 = V_84 ;
break;
case V_85 :
if ( V_65 -> V_83 == V_86 )
break;
F_18 ( V_2 , V_70 ,
true ) ;
V_65 -> V_83 = V_86 ;
break;
default:
break;
}
break;
case V_87 :
F_2 ( V_5 , V_77 , L_9 ) ;
V_65 -> V_83 = V_88 ;
break;
case V_89 :
F_2 ( V_5 , V_77 ,
L_10 ,
V_67 -> V_75 . V_90 ) ;
break;
default:
break;
}
return V_63 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_93 * V_94 ;
struct V_64 * V_65 ;
unsigned long V_95 ;
V_94 = ( void * ) V_92 ;
F_2 ( V_2 -> V_5 , V_77 ,
L_11 ,
V_94 -> V_96 , V_94 -> V_97 ,
V_94 -> V_98 ) ;
if ( F_20 ( V_94 -> V_96 , V_2 -> V_59 -> V_99 ) ) {
if ( V_94 -> V_97 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else if ( F_21 ( V_94 -> V_96 ) ) {
F_22 ( V_2 , V_94 -> V_96 , V_94 -> V_97 ) ;
} else {
F_23 ( & V_2 -> V_100 , V_95 ) ;
V_65 = F_15 ( V_2 , V_94 -> V_96 ) ;
F_24 ( & V_2 -> V_100 , V_95 ) ;
if ( V_65 && V_65 -> V_97 != V_94 -> V_97 ) {
V_65 -> V_97 = V_94 -> V_97 ;
F_22 ( V_2 , V_94 -> V_96 ,
V_94 -> V_97 ) ;
}
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_93 * V_94 ;
struct V_64 * V_65 ;
int V_79 ;
unsigned long V_95 ;
V_94 = ( void * ) V_92 ;
F_2 ( V_2 -> V_5 , V_77 ,
L_12 ,
V_94 -> V_96 , V_94 -> V_97 ,
V_94 -> V_98 ) ;
if ( F_20 ( V_94 -> V_96 , V_2 -> V_56 ) ) {
if ( V_94 -> V_97 )
V_2 -> V_9 = false ;
else
V_2 -> V_9 = true ;
} else {
if ( ! F_4 ( V_2 -> V_5 -> V_11 ) )
return;
V_79 = F_26 ( V_2 , V_94 -> V_96 ) ;
if ( F_27 ( V_79 ) ) {
F_23 ( & V_2 -> V_100 , V_95 ) ;
V_65 = F_15 ( V_2 , V_94 -> V_96 ) ;
F_24 ( & V_2 -> V_100 , V_95 ) ;
if ( V_65 && V_65 -> V_97 != V_94 -> V_97 ) {
V_65 -> V_97 = V_94 -> V_97 ;
F_22 ( V_2 ,
V_94 -> V_96 ,
V_94 -> V_97 ) ;
}
}
}
}
void F_28 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_91 * V_92 ;
T_1 V_105 , V_106 , V_107 ;
int V_108 , V_109 , V_110 , V_111 ;
struct V_1 * V_112 ;
V_105 = V_62 -> V_72 - sizeof( V_113 ) ;
V_102 = ( void * ) V_62 -> V_68 + sizeof( V_113 ) ;
if ( F_16 ( V_102 -> V_114 . type ) != V_115 ||
V_105 < sizeof( struct V_101 ) ) {
F_2 ( V_5 , ERROR ,
L_13 ) ;
return;
}
V_5 -> V_116 = F_16 ( V_102 -> V_79 ) ;
F_2 ( V_5 , V_77 , L_14 ,
V_5 -> V_116 ? L_15 : L_16 ) ;
V_105 -= sizeof( struct V_101 ) ;
V_92 = (struct V_91 * ) V_102 -> V_117 ;
while ( V_105 >= ( int ) sizeof( struct V_91 ) ) {
V_106 = F_16 ( V_92 -> type ) ;
V_107 = F_16 ( V_92 -> V_72 ) ;
if ( ( sizeof( struct V_91 ) + V_107 ) >
V_105 ) {
F_2 ( V_5 , ERROR , L_17
L_18 , V_107 , V_105 ) ;
break;
}
if ( V_106 != V_118 ) {
F_2 ( V_5 , ERROR , L_19 ,
V_106 ) ;
break;
}
V_104 = (struct V_103 * ) V_92 ;
V_108 = V_104 -> V_108 ;
for ( V_111 = 0 ; V_111 < V_108 ; V_111 ++ ) {
V_109 = V_104 -> V_119 [ V_111 ] >> 4 ;
V_110 = V_104 -> V_119 [ V_111 ] & V_120 ;
V_112 = F_29 ( V_5 , V_110 ,
V_109 ) ;
if ( ! V_112 ) {
F_2 ( V_5 , ERROR ,
L_20
L_21 ) ;
continue;
}
if ( V_5 -> V_121 == V_122 ) {
T_2 V_123 ;
V_123 = V_104 -> V_124 . V_125 ;
if ( V_123 == V_126 ||
V_123 == V_127 )
V_112 -> V_128 = V_123 ;
}
}
V_105 -= sizeof( struct V_91 ) +
V_107 ;
V_92 = ( void * ) ( ( T_2 * ) V_92 + V_107 +
sizeof( struct V_91 ) ) ;
}
if ( V_5 -> V_121 == V_122 ) {
V_5 -> V_51 = true ;
V_5 -> V_129 = true ;
F_30 ( V_5 ) ;
}
}
void F_31 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_91 * V_92 ;
T_1 V_106 , V_107 ;
int V_105 ;
if ( ! V_2 -> V_6 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_22 ,
V_2 -> V_130 ) ;
return;
}
V_105 = V_62 -> V_72 - sizeof( V_113 ) ;
V_92 = ( void * ) V_62 -> V_68 + sizeof( V_113 ) ;
while ( V_105 >= ( int ) sizeof( struct V_91 ) ) {
V_106 = F_16 ( V_92 -> type ) ;
V_107 = F_16 ( V_92 -> V_72 ) ;
if ( ( sizeof( struct V_91 ) + V_107 ) >
V_105 ) {
F_2 ( V_2 -> V_5 , ERROR ,
L_23 ,
V_107 , V_105 ) ;
break;
}
if ( V_106 == V_131 ) {
if ( F_3 ( V_2 ) == V_10 )
F_25 ( V_2 , V_92 ) ;
else
F_19 ( V_2 , V_92 ) ;
}
V_105 -= sizeof( struct V_91 ) +
V_107 ;
V_92 = ( void * ) ( ( T_2 * ) V_92 + V_107 +
sizeof( struct V_91 ) ) ;
}
}
void F_32 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_91 * V_92 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
T_3 V_72 = V_62 -> V_72 - sizeof( V_113 ) ;
T_2 * V_136 = V_62 -> V_68 + sizeof( V_113 ) ;
T_1 V_106 , V_107 ;
while ( V_72 >= sizeof( struct V_91 ) ) {
V_92 = (struct V_91 * ) V_136 ;
V_107 = F_16 ( V_92 -> V_72 ) ;
V_106 = F_16 ( V_92 -> type ) ;
if ( ( V_107 + sizeof( struct V_91 ) ) > V_72 )
break;
switch ( V_106 ) {
case V_137 :
V_133 =
(struct V_132 * ) V_92 ;
V_5 -> V_138 = V_133 -> V_138 ;
V_5 -> V_139 =
V_133 -> V_140 ;
V_5 -> V_141 =
V_133 -> V_142 ;
F_33 ( V_5 ) ;
F_34 ( V_5 ) ;
break;
case V_143 :
V_135 =
(struct V_134 * ) V_92 ;
V_5 -> V_144 = V_135 -> V_144 ;
V_5 -> V_145 = V_135 -> V_146 ;
V_5 -> V_147 = V_135 -> V_148 ;
break;
default:
break;
}
V_72 -= V_107 + sizeof( struct V_91 ) ;
V_136 += V_107 +
sizeof( struct V_91 ) ;
}
F_35 ( V_5 -> V_149 , L_24 ,
V_5 -> V_144 , V_5 -> V_145 ,
V_5 -> V_138 , V_5 -> V_139 ,
V_5 -> V_141 ) ;
}
int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_63 = 0 ;
V_113 V_150 = V_5 -> V_69 ;
T_1 V_151 , V_3 ;
switch ( V_150 ) {
case V_152 :
F_2 ( V_5 , ERROR ,
L_25 ) ;
break;
case V_153 :
F_2 ( V_5 , V_77 , L_26 ) ;
if ( ! F_12 ( V_2 -> V_59 ) )
F_37 ( V_2 -> V_59 ) ;
F_38 ( V_2 -> V_59 , V_5 ) ;
break;
case V_154 :
F_2 ( V_5 , V_77 , L_27 ) ;
if ( V_2 -> V_155 . V_156 ) {
F_2 ( V_5 , V_7 ,
L_28 ) ;
break;
}
V_5 -> V_157 . V_158 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_159 * ) V_5 -> V_160 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_161 :
F_2 ( V_5 , V_77 , L_29 ) ;
if ( V_2 -> V_155 . V_156 ) {
F_2 ( V_5 , V_7 ,
L_30 ) ;
break;
}
V_5 -> V_157 . V_162 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_159 * ) V_5 -> V_160 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_163 :
F_2 ( V_5 , V_77 , L_31 ) ;
V_5 -> V_157 . V_164 ++ ;
if ( V_2 -> V_6 ) {
V_3 =
F_16 ( * ( V_159 * ) V_5 -> V_160 ) ;
F_1 ( V_2 , V_3 ) ;
}
break;
case V_165 :
F_2 ( V_5 , V_77 , L_32 ) ;
V_5 -> V_166 = V_167 ;
F_39 ( V_5 ) ;
break;
case V_168 :
F_2 ( V_5 , V_77 , L_33 ) ;
if ( ! V_5 -> V_52 &&
( V_2 -> V_9 ||
( V_2 -> V_37 == V_38 ) ) &&
V_2 -> V_6 && V_5 -> V_169 . V_170 ) {
V_5 -> V_52 = true ;
F_2 ( V_5 , V_77 ,
L_34 ) ;
}
V_5 -> V_51 = false ;
if ( V_5 -> V_52 && V_5 -> V_171 ) {
if ( F_40 ( V_2 ) ) {
if ( V_5 -> V_172 ||
( V_5 -> V_173 . V_174 &&
! V_5 -> V_173 . V_174 ( V_2 ) ) ) {
V_5 -> V_166 = V_175 ;
V_5 -> V_176 = false ;
V_5 -> V_177 = false ;
F_41 ( & V_5 -> V_178 ) ;
break;
}
if ( ! F_42
( V_2 ,
V_179 |
V_180 ) )
V_5 -> V_166 =
V_181 ;
return 0 ;
}
}
V_5 -> V_166 = V_175 ;
V_5 -> V_176 = false ;
V_5 -> V_177 = false ;
F_41 ( & V_5 -> V_178 ) ;
break;
case V_182 :
V_5 -> V_173 . V_183 ( V_5 ) ;
F_2 ( V_5 , V_77 , L_35 ) ;
if ( V_5 -> V_184 )
V_5 -> V_184 = false ;
break;
case V_185 :
F_2 ( V_5 , V_77 , L_36 ) ;
V_63 = F_43 ( V_2 , V_186 ,
0 , 0 , NULL , false ) ;
break;
case V_187 :
F_2 ( V_5 , V_77 , L_37 ) ;
F_44 ( V_2 -> V_59 , V_2 -> V_56 ,
V_188 ,
- 1 , NULL , V_60 ) ;
break;
case V_189 :
F_2 ( V_5 , V_77 , L_38 ) ;
F_44 ( V_2 -> V_59 , V_2 -> V_56 ,
V_190 ,
- 1 , NULL , V_60 ) ;
break;
case V_191 :
case V_192 :
break;
case V_193 :
F_2 ( V_5 , V_77 , L_39 ) ;
V_2 -> V_41 = false ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_59 , V_5 ) ;
if ( F_12 ( V_2 -> V_59 ) )
F_13 ( V_2 -> V_59 ) ;
break;
case V_194 :
F_2 ( V_5 , V_77 , L_40 ) ;
V_63 = F_43 ( V_2 , V_195 ,
V_196 , 0 , NULL , false ) ;
break;
case V_197 :
F_35 ( V_5 -> V_149 , L_41 ) ;
F_45 ( V_2 -> V_198 . V_199 ) ;
if ( V_2 -> V_200 )
V_2 -> V_200 = false ;
break;
case V_201 :
F_2 ( V_5 , V_77 , L_42 ) ;
V_2 -> V_9 = true ;
break;
case V_202 :
F_2 ( V_5 , V_77 , L_43 ) ;
if ( V_5 -> V_203 )
V_63 = F_46 ( V_2 ,
V_5 -> V_62 -> V_68 ) ;
break;
case V_204 :
F_2 ( V_5 , V_77 , L_44 ) ;
V_63 = F_43 ( V_2 , V_205 ,
0 , 0 , NULL , false ) ;
break;
case V_206 :
F_47 ( V_2 -> V_59 ,
V_207 ,
V_60 ) ;
F_43 ( V_2 , V_208 ,
V_196 , 0 , NULL , false ) ;
V_2 -> V_209 = V_210 ;
F_2 ( V_5 , V_77 , L_45 ) ;
break;
case V_211 :
F_2 ( V_5 , V_77 , L_46 ) ;
break;
case V_212 :
F_2 ( V_5 , V_77 , L_47 ) ;
break;
case V_213 :
F_47 ( V_2 -> V_59 ,
V_214 ,
V_60 ) ;
F_43 ( V_2 , V_208 ,
V_196 , 0 , NULL , false ) ;
V_2 -> V_209 = V_215 ;
F_2 ( V_5 , V_77 , L_48 ) ;
break;
case V_216 :
F_2 ( V_5 , V_77 , L_49 ) ;
break;
case V_217 :
F_2 ( V_5 , V_77 , L_50 ) ;
break;
case V_218 :
F_2 ( V_5 , V_77 , L_51 ) ;
break;
case V_219 :
F_2 ( V_5 , V_77 , L_52 ) ;
break;
case V_220 :
F_2 ( V_5 , V_77 , L_53 ) ;
break;
case V_221 :
F_2 ( V_5 , V_77 , L_54 ) ;
break;
case V_222 :
F_2 ( V_5 , V_77 , L_55 ) ;
break;
case V_223 :
F_2 ( V_5 , V_77 , L_56 ) ;
V_63 = F_43 ( V_2 ,
V_224 ,
V_196 , 0 , NULL , false ) ;
break;
case V_225 :
F_2 ( V_5 , V_77 , L_57 ) ;
F_43 ( V_2 , V_226 ,
V_227 , 0 ,
V_5 -> V_160 , false ) ;
break;
case V_228 :
F_2 ( V_5 , V_77 , L_58 ) ;
F_48 ( V_2 , V_5 -> V_160 ) ;
break;
case V_229 :
F_2 ( V_5 , V_77 , L_59 ) ;
F_49 ( V_2 ,
(struct V_230
* )
V_5 -> V_160 ) ;
break;
case V_231 :
V_151 = F_16 ( * ( V_159 * ) V_5 -> V_160 ) ;
F_2 ( V_5 , V_77 ,
L_60 , V_151 ) ;
V_5 -> V_232 =
F_50 ( T_1 , V_5 -> V_233 , V_151 ) ;
F_2 ( V_5 , V_77 , L_61 ,
V_5 -> V_232 ) ;
break;
case V_234 :
F_2 ( V_5 , V_77 , L_62 ) ;
break;
case V_235 :
F_2 ( V_5 , V_77 , L_63 ) ;
break;
case V_236 :
F_2 ( V_5 , V_77 ,
L_64 , V_150 ) ;
break;
case V_237 :
F_2 ( V_5 , V_77 ,
L_65 ) ;
F_51 ( & V_2 -> V_198 ,
V_2 -> V_238 . V_239 ,
& V_2 -> V_238 . V_240 ,
V_241 ) ;
memset ( & V_2 -> V_238 , 0x00 , sizeof( struct V_242 ) ) ;
break;
case V_243 :
F_2 ( V_5 , V_77 , L_66 ) ;
V_2 -> V_244 =
V_245 + F_52 ( V_246 ) ;
V_2 -> V_247 = V_2 -> V_45 . V_46 . V_248 ;
V_63 = F_43 ( V_2 , V_249 ,
V_227 , 0 ,
V_2 -> V_45 . V_46 . V_49 ,
false ) ;
break;
case V_250 :
V_63 = F_14 ( V_2 , V_5 -> V_62 ) ;
break;
case V_251 :
F_2 ( V_5 , V_77 , L_67 ) ;
F_31 ( V_2 , V_5 -> V_62 ) ;
break;
case V_252 :
F_2 ( V_5 , V_77 , L_68 ) ;
F_28 ( V_2 , V_5 -> V_62 ) ;
break;
case V_253 :
F_2 ( V_5 , V_77 , L_69 ) ;
F_53 ( V_2 , V_5 -> V_160 ) ;
break;
case V_254 :
F_2 ( V_5 , V_77 , L_70 ) ;
V_63 = F_54 ( V_2 ,
V_5 -> V_62 ) ;
break;
case V_255 :
F_2 ( V_5 , V_77 , L_71 ) ;
V_63 = F_55 ( V_2 ,
V_5 -> V_62 ) ;
break;
case V_256 :
F_35 ( V_5 -> V_149 , L_72 ) ;
F_32 ( V_2 ,
V_5 -> V_62 ) ;
break;
default:
F_2 ( V_5 , ERROR , L_73 ,
V_150 ) ;
break;
}
return V_63 ;
}
