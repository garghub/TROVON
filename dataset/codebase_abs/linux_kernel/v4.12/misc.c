unsigned int
F_1 ( void )
{
unsigned int V_1 ;
F_2 ( & V_2 ) ;
V_3 ++ ;
if ( V_3 > V_4 )
V_4 = V_3 ;
if ( V_3 > 65000 )
F_3 ( V_5 , L_1 ) ;
V_1 = V_6 ++ ;
F_4 ( & V_2 ) ;
return V_1 ;
}
void
F_5 ( unsigned int V_1 )
{
F_2 ( & V_2 ) ;
V_3 -- ;
F_4 ( & V_2 ) ;
}
struct V_7 *
F_6 ( void )
{
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( struct V_7 ) , V_9 ) ;
if ( V_8 ) {
F_8 ( & V_10 ) ;
V_8 -> V_11 = V_12 ;
++ V_8 -> V_13 ;
F_9 ( & V_8 -> V_14 ) ;
F_9 ( & V_8 -> V_15 ) ;
F_10 ( & V_8 -> V_16 ) ;
}
return V_8 ;
}
void
F_11 ( struct V_7 * V_17 )
{
if ( V_17 == NULL ) {
F_3 ( V_5 , L_2 ) ;
return;
}
F_12 ( & V_10 ) ;
F_13 ( V_17 -> V_18 ) ;
F_13 ( V_17 -> V_19 ) ;
F_13 ( V_17 -> V_20 ) ;
if ( V_17 -> V_21 ) {
memset ( V_17 -> V_21 , 0 , strlen ( V_17 -> V_21 ) ) ;
F_13 ( V_17 -> V_21 ) ;
}
F_13 ( V_17 -> V_22 ) ;
F_13 ( V_17 -> V_23 ) ;
F_13 ( V_17 -> V_24 . V_25 ) ;
F_13 ( V_17 ) ;
}
struct V_26 *
F_14 ( void )
{
struct V_26 * V_8 ;
V_8 = F_7 ( sizeof( struct V_26 ) , V_9 ) ;
if ( V_8 ) {
F_8 ( & V_27 ) ;
V_8 -> V_28 = V_12 ;
++ V_8 -> V_29 ;
F_9 ( & V_8 -> V_30 ) ;
F_9 ( & V_8 -> V_15 ) ;
F_15 ( & V_8 -> V_31 ) ;
#ifdef F_16
F_15 ( & V_8 -> V_32 ) ;
#endif
}
return V_8 ;
}
void
F_17 ( struct V_26 * V_17 )
{
if ( V_17 == NULL ) {
F_3 ( V_5 , L_3 ) ;
return;
}
F_12 ( & V_27 ) ;
F_13 ( V_17 -> V_33 ) ;
if ( V_17 -> V_21 ) {
memset ( V_17 -> V_21 , 0 , strlen ( V_17 -> V_21 ) ) ;
F_13 ( V_17 -> V_21 ) ;
}
F_13 ( V_17 ) ;
}
struct V_34 *
F_18 ( void )
{
struct V_34 * V_8 = NULL ;
T_1 V_35 = sizeof( struct V_34 ) ;
#ifdef F_19
V_35 = sizeof( struct V_36 ) ;
#endif
V_8 = F_20 ( V_37 , V_38 ) ;
memset ( V_8 , 0 , V_35 + 3 ) ;
F_8 ( & V_39 ) ;
#ifdef F_21
F_8 ( & V_40 ) ;
#endif
return V_8 ;
}
void
F_22 ( void * V_17 )
{
if ( V_17 == NULL ) {
return;
}
F_23 ( V_17 , V_37 ) ;
F_12 ( & V_39 ) ;
return;
}
struct V_34 *
F_24 ( void )
{
struct V_34 * V_8 = NULL ;
V_8 = F_20 ( V_41 , V_38 ) ;
F_8 ( & V_42 ) ;
#ifdef F_21
F_8 ( & V_43 ) ;
#endif
return V_8 ;
}
void
F_25 ( void * V_17 )
{
if ( V_17 == NULL ) {
F_3 ( V_5 , L_4 ) ;
return;
}
F_23 ( V_17 , V_41 ) ;
F_12 ( & V_42 ) ;
return;
}
void
F_26 ( int V_44 , void * V_45 )
{
if ( V_44 == V_46 )
F_25 ( V_45 ) ;
else if ( V_44 == V_47 )
F_22 ( V_45 ) ;
}
void
F_27 ( struct V_34 * V_48 , char V_49 ,
const struct V_26 * V_50 , int V_51
)
{
char * V_52 = ( char * ) V_48 ;
memset ( V_52 , 0 , 256 ) ;
V_48 -> V_53 = F_28 (
( 2 * V_51 ) + sizeof( struct V_34 ) -
4 +
2 ) ;
V_48 -> V_54 [ 0 ] = 0xFF ;
V_48 -> V_54 [ 1 ] = 'S' ;
V_48 -> V_54 [ 2 ] = 'M' ;
V_48 -> V_54 [ 3 ] = 'B' ;
V_48 -> V_55 = V_49 ;
V_48 -> V_56 = 0x00 ;
V_48 -> V_57 = V_58 ;
V_48 -> V_59 = F_29 ( ( V_60 ) V_61 -> V_62 ) ;
V_48 -> V_63 = F_29 ( ( V_60 ) ( V_61 -> V_62 >> 16 ) ) ;
if ( V_50 ) {
V_48 -> V_64 = V_50 -> V_65 ;
if ( V_50 -> V_66 ) {
if ( V_50 -> V_66 -> V_67 & V_68 )
V_48 -> V_57 |= V_69 ;
if ( V_50 -> V_66 -> V_67 & V_70 )
V_48 -> V_57 |= V_71 ;
V_48 -> V_72 = V_50 -> V_66 -> V_73 ;
V_48 -> V_74 = F_30 ( V_50 -> V_66 -> V_75 ) ;
}
if ( V_50 -> V_56 & V_76 )
V_48 -> V_57 |= V_77 ;
if ( V_50 -> V_78 )
V_48 -> V_56 |= V_79 ;
if ( ( V_50 -> V_66 ) && ( V_50 -> V_66 -> V_75 ) )
if ( V_50 -> V_66 -> V_75 -> V_80 )
V_48 -> V_57 |= V_81 ;
}
V_48 -> V_82 = ( char ) V_51 ;
return;
}
static int
F_31 ( struct V_34 * V_83 )
{
if ( * ( V_84 * ) V_83 -> V_54 != F_32 ( 0x424d53ff ) ) {
F_3 ( V_85 , L_5 ,
* ( unsigned int * ) V_83 -> V_54 ) ;
return 1 ;
}
if ( V_83 -> V_56 & V_86 )
return 0 ;
if ( V_83 -> V_55 == V_87 )
return 0 ;
F_3 ( V_85 , L_6 ,
F_33 ( V_83 ) ) ;
return 1 ;
}
int
F_34 ( char * V_88 , unsigned int V_89 , struct V_90 * V_75 )
{
struct V_34 * V_83 = (struct V_34 * ) V_88 ;
T_2 V_91 = F_35 ( V_83 -> V_53 ) ;
T_2 V_92 ;
F_3 ( V_5 , L_7 ,
V_89 , V_91 ) ;
if ( V_89 < 2 + sizeof( struct V_34 ) ) {
if ( ( V_89 >= sizeof( struct V_34 ) - 1 )
&& ( V_83 -> V_93 . V_94 != 0 ) ) {
V_83 -> V_82 = 0 ;
return 0 ;
} else if ( ( V_89 == sizeof( struct V_34 ) + 1 ) &&
( V_83 -> V_82 == 0 ) ) {
char * V_95 = ( char * ) V_83 ;
if ( V_95 [ sizeof( struct V_34 ) ] == 0 ) {
V_95 [ sizeof( struct V_34 ) + 1 ] = 0 ;
return 0 ;
}
F_3 ( V_85 , L_8 ) ;
} else {
F_3 ( V_85 , L_9 ) ;
}
return - V_96 ;
}
if ( F_31 ( V_83 ) )
return - V_96 ;
V_92 = F_36 ( V_83 ) ;
if ( 4 + V_91 != V_89 ) {
F_3 ( V_85 , L_10 ,
V_91 ) ;
return - V_96 ;
}
if ( 4 + V_91 != V_92 ) {
V_60 V_97 = F_33 ( V_83 ) ;
if ( ( V_91 > 64 * 1024 ) && ( V_91 > V_92 ) ) {
if ( ( ( 4 + V_91 ) & 0xFFFF ) == ( V_92 & 0xFFFF ) )
return 0 ;
}
F_3 ( V_5 , L_11 ,
V_92 , 4 + V_91 , V_97 ) ;
if ( 4 + V_91 < V_92 ) {
F_3 ( V_85 , L_12 ,
V_91 , V_97 ) ;
return - V_96 ;
} else if ( V_91 > V_92 + 512 ) {
F_3 ( V_85 , L_13 ,
V_91 , V_97 ) ;
return - V_96 ;
}
}
return 0 ;
}
bool
F_37 ( char * V_48 , struct V_90 * V_98 )
{
struct V_34 * V_88 = (struct V_34 * ) V_48 ;
struct V_99 * V_100 = (struct V_99 * ) V_88 ;
struct V_101 * V_95 , * V_102 , * V_103 ;
struct V_7 * V_66 ;
struct V_26 * V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
F_3 ( V_5 , L_14 ) ;
if ( ( V_100 -> V_109 . V_55 == V_110 ) &&
( V_100 -> V_109 . V_56 & V_86 ) ) {
struct V_111 * V_112 =
(struct V_111 * ) V_88 ;
struct V_113 * V_114 ;
T_2 V_115 = 0 ;
if ( F_38 ( V_88 ) > sizeof( struct V_113 ) ) {
V_115 = F_39 ( V_112 -> V_116 ) ;
V_114 = (struct V_113 * )
( ( char * ) & V_112 -> V_109 . V_54 + V_115 ) ;
F_3 ( V_5 , L_15 ,
V_114 -> V_117 , V_114 -> V_118 ) ;
return true ;
}
if ( V_112 -> V_109 . V_93 . V_94 ) {
F_3 ( V_5 , L_16 ,
V_112 -> V_109 . V_93 . V_94 ) ;
return true ;
}
return false ;
}
if ( V_100 -> V_109 . V_55 != V_87 )
return false ;
if ( V_100 -> V_109 . V_56 & V_86 ) {
if ( ( V_119 ) ==
F_39 ( V_100 -> V_109 . V_93 . V_94 ) ) {
F_3 ( V_5 , L_17 ) ;
return true ;
} else if ( V_120 ==
F_40 ( V_100 -> V_109 . V_93 . V_121 . Error ) ) {
return true ;
} else {
return false ;
}
}
if ( V_100 -> V_109 . V_82 != 8 )
return false ;
F_3 ( V_5 , L_18 ,
V_100 -> V_122 , V_100 -> V_123 ) ;
if ( ! ( V_100 -> V_122 & V_124 ) )
return false ;
F_2 ( & V_125 ) ;
F_41 (tmp, &srv->smb_ses_list) {
V_66 = F_42 ( V_95 , struct V_7 , V_14 ) ;
F_41 (tmp1, &ses->tcon_list) {
V_104 = F_42 ( V_102 , struct V_26 , V_15 ) ;
if ( V_104 -> V_65 != V_88 -> V_64 )
continue;
F_43 ( & V_104 -> V_126 . V_127 . V_128 ) ;
F_2 ( & V_104 -> V_31 ) ;
F_41 (tmp2, &tcon->openFileList) {
V_108 = F_42 ( V_103 , struct V_107 ,
V_129 ) ;
if ( V_100 -> V_130 != V_108 -> V_131 . V_132 )
continue;
F_3 ( V_5 , L_19 ) ;
V_106 = F_44 ( F_45 ( V_108 -> V_133 ) ) ;
F_46 ( V_134 ,
& V_106 -> V_135 ) ;
if ( V_100 -> V_123 )
F_46 (
V_136 ,
& V_106 -> V_135 ) ;
else
F_47 (
V_136 ,
& V_106 -> V_135 ) ;
F_48 ( V_137 ,
& V_108 -> V_138 ) ;
V_108 -> V_139 = false ;
F_4 ( & V_104 -> V_31 ) ;
F_4 ( & V_125 ) ;
return true ;
}
F_4 ( & V_104 -> V_31 ) ;
F_4 ( & V_125 ) ;
F_3 ( V_5 , L_20 ) ;
return true ;
}
}
F_4 ( & V_125 ) ;
F_3 ( V_5 , L_21 ) ;
return true ;
}
void
F_49 ( void * V_88 , int V_53 )
{
if ( V_140 == 0 )
return;
F_50 ( V_141 , L_22 , V_142 , 8 , 2 , V_88 ,
V_53 , true ) ;
}
void
F_51 ( struct V_143 * V_144 )
{
if ( V_144 -> V_145 & V_146 ) {
V_144 -> V_145 &= ~ V_146 ;
F_3 ( V_85 , L_23 ,
F_52 ( V_144 ) -> V_147 ) ;
}
}
void F_53 ( struct V_105 * V_148 , T_2 V_149 )
{
V_149 &= 0xF ;
if ( V_149 == V_150 ) {
V_148 -> V_149 = V_151 | V_152 ;
F_3 ( V_5 , L_24 ,
& V_148 -> V_153 ) ;
} else if ( V_149 == V_154 ) {
V_148 -> V_149 = V_152 ;
F_3 ( V_5 , L_25 ,
& V_148 -> V_153 ) ;
} else
V_148 -> V_149 = 0 ;
}
int F_54 ( struct V_105 * V_148 )
{
int V_155 ;
V_156:
V_155 = F_55 ( & V_148 -> V_135 , V_134 ,
V_157 ) ;
if ( V_155 )
return V_155 ;
F_2 ( & V_148 -> V_158 ) ;
if ( ! V_148 -> V_159 )
F_46 ( V_160 , & V_148 -> V_135 ) ;
V_148 -> V_159 ++ ;
if ( F_56 ( V_134 , & V_148 -> V_135 ) ) {
V_148 -> V_159 -- ;
if ( V_148 -> V_159 == 0 ) {
F_47 ( V_160 , & V_148 -> V_135 ) ;
F_57 ( & V_148 -> V_135 , V_160 ) ;
}
F_4 ( & V_148 -> V_158 ) ;
goto V_156;
}
F_4 ( & V_148 -> V_158 ) ;
return 0 ;
}
void F_58 ( struct V_105 * V_148 )
{
F_2 ( & V_148 -> V_158 ) ;
V_148 -> V_159 -- ;
if ( V_148 -> V_159 == 0 ) {
F_47 ( V_160 , & V_148 -> V_135 ) ;
F_57 ( & V_148 -> V_135 , V_160 ) ;
}
F_4 ( & V_148 -> V_158 ) ;
}
void F_59 ( struct V_105 * V_148 )
{
F_47 ( V_134 , & V_148 -> V_135 ) ;
F_57 ( & V_148 -> V_135 , V_134 ) ;
}
bool
F_60 ( struct V_143 * V_144 )
{
if ( V_144 -> V_145 & V_161 ) {
if ( F_61 ( V_144 -> V_162 , F_62 () ) )
return true ;
}
if ( V_144 -> V_145 & V_163 ) {
if ( F_63 ( V_144 -> V_164 ) )
return true ;
}
return false ;
}
void
F_64 ( struct V_165 * V_166 )
{
F_2 ( & F_65 ( V_166 -> V_167 ) -> V_31 ) ;
F_66 ( & V_166 -> V_168 ) ;
F_4 ( & F_65 ( V_166 -> V_167 ) -> V_31 ) ;
}
void
F_67 ( struct V_169 * V_131 , struct V_170 * V_167 ,
struct V_165 * V_166 )
{
#ifdef F_19
memcpy ( V_166 -> V_171 , V_131 -> V_171 , V_172 ) ;
#endif
V_166 -> V_149 = V_173 ;
V_166 -> V_167 = V_167 ;
V_131 -> V_174 = V_166 ;
F_68 ( & V_166 -> V_168 , & F_65 ( V_167 ) -> V_175 ) ;
}
void
F_69 ( struct V_169 * V_131 , struct V_170 * V_167 ,
struct V_165 * V_166 )
{
F_2 ( & F_65 ( V_167 ) -> V_31 ) ;
F_67 ( V_131 , V_167 , V_166 ) ;
F_4 ( & F_65 ( V_166 -> V_167 ) -> V_31 ) ;
}
int
F_70 ( struct V_176 * V_45 , T_3 V_177 ,
unsigned int * V_178 ,
struct V_179 * * V_180 ,
const struct V_181 * V_182 , int V_183 ,
const char * V_184 , bool V_185 )
{
int V_186 , V_155 = 0 ;
char * V_187 ;
struct V_188 * V_189 ;
* V_178 = F_40 ( V_45 -> V_190 ) ;
if ( * V_178 < 1 ) {
F_3 ( V_85 , L_26 ,
* V_178 ) ;
V_155 = - V_191 ;
goto V_192;
}
V_189 = (struct V_188 * ) & ( V_45 -> V_193 ) ;
if ( V_189 -> V_194 != F_29 ( 3 ) ) {
F_3 ( V_85 , L_27 ,
F_40 ( V_189 -> V_194 ) ) ;
V_155 = - V_191 ;
goto V_192;
}
V_187 = ( char * ) V_45 + V_177 ;
F_3 ( V_5 , L_28 ,
* V_178 , F_39 ( V_45 -> V_195 ) ) ;
* V_180 = F_71 ( * V_178 , sizeof( struct V_179 ) ,
V_9 ) ;
if ( * V_180 == NULL ) {
V_155 = - V_196 ;
goto V_192;
}
for ( V_186 = 0 ; V_186 < * V_178 ; V_186 ++ ) {
char * V_52 ;
int V_197 ;
struct V_179 * V_198 = ( * V_180 ) + V_186 ;
V_198 -> V_135 = F_39 ( V_45 -> V_195 ) ;
if ( V_185 ) {
T_4 * V_95 = F_72 ( strlen ( V_184 ) * 2 + 2 ,
V_9 ) ;
if ( V_95 == NULL ) {
V_155 = - V_196 ;
goto V_192;
}
F_73 ( ( T_4 * ) V_95 , V_184 ,
V_199 , V_182 , V_183 ) ;
V_198 -> V_200 = F_74 ( V_95 ,
F_40 ( V_45 -> V_201 ) ,
V_182 ) ;
F_13 ( V_95 ) ;
} else
V_198 -> V_200 = F_40 ( V_45 -> V_201 ) ;
V_198 -> V_202 = F_40 ( V_189 -> V_203 ) ;
V_198 -> V_204 = F_40 ( V_189 -> V_205 ) ;
V_52 = ( char * ) V_189 + F_40 ( V_189 -> V_206 ) ;
V_197 = V_187 - V_52 ;
V_198 -> V_207 = F_75 ( V_52 , V_197 ,
V_185 , V_182 ) ;
if ( ! V_198 -> V_207 ) {
V_155 = - V_196 ;
goto V_192;
}
V_52 = ( char * ) V_189 + F_40 ( V_189 -> V_208 ) ;
V_197 = V_187 - V_52 ;
V_198 -> V_209 = F_75 ( V_52 , V_197 ,
V_185 , V_182 ) ;
if ( ! V_198 -> V_209 ) {
V_155 = - V_196 ;
goto V_192;
}
V_189 ++ ;
}
V_192:
if ( V_155 ) {
F_76 ( * V_180 , * V_178 ) ;
* V_180 = NULL ;
* V_178 = 0 ;
}
return V_155 ;
}
struct V_210 *
F_77 ( void )
{
struct V_210 * V_211 ;
V_211 = F_7 ( sizeof( struct V_210 ) , V_9 ) ;
if ( ! V_211 )
return NULL ;
F_9 ( & V_211 -> V_212 ) ;
F_10 ( & V_211 -> V_213 ) ;
F_78 ( & V_211 -> V_214 ) ;
F_79 ( & V_211 -> V_215 ) ;
return V_211 ;
}
void
F_80 ( struct V_216 * V_215 )
{
struct V_210 * V_211 = F_81 ( V_215 ,
struct V_210 , V_215 ) ;
F_82 ( V_211 -> V_217 ) ;
F_83 ( V_211 -> V_218 ) ;
F_13 ( V_211 ) ;
}
int
F_84 ( struct V_210 * V_211 , struct V_219 * V_220 , int V_221 )
{
T_5 V_155 ;
unsigned int V_222 ;
unsigned int V_223 = 0 ;
unsigned int V_186 ;
T_1 V_224 ;
T_1 V_225 = F_85 ( V_220 ) ;
unsigned int V_226 ;
T_1 V_156 ;
unsigned int V_227 = F_86 ( V_220 , V_228 ) ;
struct V_229 * * V_230 = NULL ;
struct V_231 * V_218 = NULL ;
if ( V_220 -> type & V_232 ) {
memcpy ( & V_211 -> V_220 , V_220 , sizeof( struct V_219 ) ) ;
V_211 -> V_224 = V_225 ;
F_87 ( V_220 , V_225 ) ;
return 0 ;
}
if ( V_227 * sizeof( struct V_231 ) <= V_233 )
V_218 = F_88 ( V_227 , sizeof( struct V_231 ) ,
V_9 ) ;
if ( ! V_218 ) {
V_218 = F_89 ( V_227 * sizeof( struct V_231 ) ) ;
if ( ! V_218 )
return - V_196 ;
}
if ( V_227 * sizeof( struct V_229 * ) <= V_233 )
V_230 = F_88 ( V_227 , sizeof( struct V_229 * ) ,
V_9 ) ;
if ( ! V_230 ) {
V_230 = F_89 ( V_227 * sizeof( struct V_229 * ) ) ;
if ( ! V_230 ) {
F_83 ( V_218 ) ;
return - V_196 ;
}
}
V_226 = V_225 ;
while ( V_225 && V_223 < V_227 ) {
V_155 = F_90 ( V_220 , V_230 , V_225 , V_227 , & V_156 ) ;
if ( V_155 < 0 ) {
F_3 ( V_85 , L_29 , V_155 ) ;
break;
}
if ( V_155 > V_225 ) {
F_3 ( V_85 , L_30 , V_155 ,
V_225 ) ;
break;
}
F_87 ( V_220 , V_155 ) ;
V_225 -= V_155 ;
V_155 += V_156 ;
V_222 = F_91 ( V_155 , V_234 ) ;
if ( V_223 + V_222 > V_227 ) {
F_3 ( V_85 , L_31 ,
V_223 + V_222 , V_227 ) ;
break;
}
for ( V_186 = 0 ; V_186 < V_222 ; V_186 ++ ) {
V_224 = V_155 > V_234 ? V_234 : V_155 ;
V_218 [ V_223 + V_186 ] . V_235 = V_230 [ V_186 ] ;
V_218 [ V_223 + V_186 ] . V_236 = V_156 ;
V_218 [ V_223 + V_186 ] . V_237 = V_224 - V_156 ;
V_155 -= V_224 ;
V_156 = 0 ;
}
V_223 += V_222 ;
}
F_83 ( V_230 ) ;
V_211 -> V_218 = V_218 ;
V_211 -> V_224 = V_226 - V_225 ;
V_211 -> V_223 = V_223 ;
F_92 ( & V_211 -> V_220 , V_238 | V_221 , V_211 -> V_218 , V_223 , V_211 -> V_224 ) ;
return 0 ;
}
