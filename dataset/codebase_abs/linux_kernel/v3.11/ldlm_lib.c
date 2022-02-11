static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL , * V_11 ;
int V_12 = 0 ;
V_13 ;
if ( ! V_6 && ! V_5 ) {
F_2 ( V_14 , L_1 ) ;
RETURN ( - V_15 ) ;
}
V_8 = F_3 ( V_4 ) ;
if ( ! V_8 ) {
F_2 ( V_14 , L_2 , V_4 -> V_4 ) ;
RETURN ( - V_16 ) ;
}
if ( V_6 ) {
F_4 ( V_10 , sizeof( * V_10 ) ) ;
if ( ! V_10 ) {
GOTO ( V_17 , V_12 = - V_18 ) ;
}
}
F_5 ( & V_2 -> V_19 ) ;
F_6 (item, &imp->imp_conn_list, oic_item) {
if ( F_7 ( V_4 , & V_11 -> V_20 ) ) {
if ( V_5 ) {
F_8 ( & V_11 -> V_21 ) ;
F_9 ( & V_11 -> V_21 ,
& V_2 -> V_22 ) ;
V_11 -> V_23 = 0 ;
}
F_2 ( V_14 , L_3 ,
V_2 , V_2 -> V_24 -> V_25 , V_4 -> V_4 ,
( V_5 ? L_4 : L_5 ) ) ;
F_10 ( & V_2 -> V_19 ) ;
GOTO ( V_26 , V_12 = 0 ) ;
}
}
if ( V_6 ) {
V_10 -> V_27 = V_8 ;
V_10 -> V_20 = * V_4 ;
V_10 -> V_23 = 0 ;
if ( V_5 )
F_9 ( & V_10 -> V_21 , & V_2 -> V_22 ) ;
else
F_11 ( & V_10 -> V_21 ,
& V_2 -> V_22 ) ;
F_2 ( V_14 , L_6 ,
V_2 , V_2 -> V_24 -> V_25 , V_4 -> V_4 ,
( V_5 ? L_7 : L_8 ) ) ;
} else {
F_10 ( & V_2 -> V_19 ) ;
GOTO ( V_26 , V_12 = - V_16 ) ;
}
F_10 ( & V_2 -> V_19 ) ;
RETURN ( 0 ) ;
V_26:
if ( V_10 )
F_12 ( V_10 , sizeof( * V_10 ) ) ;
V_17:
F_13 ( V_8 ) ;
RETURN ( V_12 ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_1 ( V_2 , V_4 , 1 , 0 ) ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , 1 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_9 * V_10 ;
struct V_28 * V_29 ;
int V_12 = - V_16 ;
V_13 ;
F_5 ( & V_2 -> V_19 ) ;
if ( F_17 ( & V_2 -> V_22 ) ) {
F_18 ( ! V_2 -> V_30 ) ;
GOTO ( V_31 , V_12 ) ;
}
F_6 (imp_conn, &imp->imp_conn_list, oic_item) {
if ( ! F_7 ( V_4 , & V_10 -> V_20 ) )
continue;
F_18 ( V_10 -> V_27 ) ;
if ( V_10 == V_2 -> V_32 ) {
F_18 ( V_10 -> V_27 == V_2 -> V_30 ) ;
if ( V_2 -> V_33 != V_34 &&
V_2 -> V_33 != V_35 ) {
F_19 ( L_9 ) ;
GOTO ( V_31 , V_12 = - V_36 ) ;
}
F_13 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
V_29 = F_20 ( & V_2 -> V_37 ) ;
if ( V_29 && V_29 -> V_38 ) {
F_18 ( V_29 -> V_38 ==
V_10 -> V_27 ) ;
F_13 ( V_29 -> V_38 ) ;
V_29 -> V_38 = NULL ;
}
}
F_8 ( & V_10 -> V_21 ) ;
F_13 ( V_10 -> V_27 ) ;
F_12 ( V_10 , sizeof( * V_10 ) ) ;
F_2 ( V_14 , L_10 ,
V_2 , V_2 -> V_24 -> V_25 , V_4 -> V_4 ) ;
V_12 = 0 ;
break;
}
V_31:
F_10 ( & V_2 -> V_19 ) ;
if ( V_12 == - V_16 )
F_19 ( L_11 , V_4 -> V_4 ) ;
RETURN ( V_12 ) ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_39 ,
struct V_3 * V_4 )
{
struct V_9 * V_40 ;
int V_12 = - V_16 ;
V_13 ;
F_5 ( & V_2 -> V_19 ) ;
F_6 (conn, &imp->imp_conn_list, oic_item) {
if ( F_22 ( & V_40 -> V_20 , V_39 ) ) {
* V_4 = V_40 -> V_20 ;
V_12 = 0 ;
break;
}
}
F_10 ( & V_2 -> V_19 ) ;
RETURN ( V_12 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static int F_28 ( char * V_41 )
{
char * V_42 ;
V_42 = strrchr ( V_41 , '-' ) ;
if ( V_42 == NULL )
return 0 ;
if ( strncmp ( V_42 + 1 , L_12 , 3 ) == 0 )
return 1 ;
return 0 ;
}
int F_29 ( struct V_43 * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = & V_44 -> V_49 . V_48 ;
struct V_1 * V_2 ;
struct V_3 V_50 ;
int V_51 , V_52 , V_53 ;
char * V_54 = V_44 -> V_55 -> V_56 ;
T_2 V_57 = V_58 ;
int V_12 ;
char * V_59 = F_30 ( V_46 , 0 ) ;
V_13 ;
if ( ! strcmp ( V_54 , V_60 ) ||
( ! ( strcmp ( V_54 , V_61 ) ) &&
( F_31 ( V_59 ) &&
strstr ( F_30 ( V_46 , 1 ) , L_13 ) != NULL ) ) ) {
V_51 = V_62 ;
V_52 = V_63 ;
V_53 = V_64 ;
V_48 -> V_65 = V_66 ;
V_48 -> V_67 = V_68 ;
V_57 = V_69 ;
} else if ( ! strcmp ( V_54 , V_70 ) ||
! strcmp ( V_54 , V_71 ) ||
( ! strcmp ( V_54 , V_61 ) &&
( F_31 ( V_59 ) &&
strstr ( F_30 ( V_46 , 1 ) , L_13 ) == NULL ) ) ) {
V_51 = V_72 ;
V_52 = V_73 ;
V_53 = V_74 ;
V_48 -> V_65 = V_66 ;
V_48 -> V_67 = V_75 ;
V_57 = V_76 ;
} else if ( ! strcmp ( V_54 , V_77 ) ) {
V_51 = V_78 ;
V_52 = V_79 ;
V_53 = V_80 ;
V_48 -> V_65 = V_81 ;
V_48 -> V_67 = V_82 ;
V_48 -> V_83 . V_84 = V_85 ;
V_57 = V_86 ;
} else {
F_19 ( L_14 ,
V_54 ) ;
RETURN ( - V_15 ) ;
}
if ( F_32 ( V_46 , 1 ) < 1 ) {
F_19 ( L_15 ) ;
RETURN ( - V_15 ) ;
}
if ( F_32 ( V_46 , 1 ) > 37 ) {
F_19 ( L_16 ) ;
RETURN ( - V_15 ) ;
}
if ( F_32 ( V_46 , 2 ) < 1 ) {
F_19 ( L_17 ) ;
RETURN ( - V_15 ) ;
}
if ( F_32 ( V_46 , 2 ) > 37 ) {
F_19 ( L_18 ) ;
RETURN ( - V_15 ) ;
}
F_33 ( & V_48 -> V_87 ) ;
F_34 ( & V_48 -> V_88 , 1 ) ;
V_48 -> V_89 = 0 ;
memcpy ( V_50 . V_4 , F_30 ( V_46 , 2 ) ,
F_35 (unsigned int, LUSTRE_CFG_BUFLEN(lcfg, 2),
sizeof(server_uuid)) ) ;
V_48 -> V_90 = 0 ;
V_48 -> V_91 = 0 ;
V_48 -> V_92 = V_93 * 1024 * 1024 ;
if ( V_48 -> V_92 >> V_94 > V_95 / 8 )
V_48 -> V_92 = V_95 << ( V_94 - 3 ) ;
F_36 ( & V_48 -> V_96 ) ;
F_36 ( & V_48 -> V_97 ) ;
F_36 ( & V_48 -> V_98 ) ;
F_36 ( & V_48 -> V_99 ) ;
F_36 ( & V_48 -> V_100 ) ;
F_37 ( & V_48 -> V_101 ) ;
F_38 ( & V_48 -> V_102 , 0 ) ;
F_38 ( & V_48 -> V_103 , 0 ) ;
V_48 -> V_104 = 0 ;
V_48 -> V_105 = 0 ;
F_39 ( & V_48 -> V_106 . V_107 ) ;
F_39 ( & V_48 -> V_108 . V_107 ) ;
F_39 ( & V_48 -> V_109 . V_107 ) ;
F_39 ( & V_48 -> V_110 . V_107 ) ;
F_39 ( & V_48 -> V_111 . V_107 ) ;
F_39 ( & V_48 -> V_112 . V_107 ) ;
F_36 ( & V_48 -> V_113 ) ;
F_38 ( & V_48 -> V_114 , 0 ) ;
F_38 ( & V_48 -> V_115 , 0 ) ;
F_38 ( & V_48 -> V_116 , 0 ) ;
F_36 ( & V_48 -> V_117 ) ;
F_37 ( & V_48 -> V_118 ) ;
F_40 ( & V_48 -> V_119 ) ;
F_38 ( & V_48 -> V_120 , 0 ) ;
V_48 -> V_121 = 1 ;
V_48 -> V_122 = V_48 -> V_123 = V_124 ;
F_38 ( & V_48 -> V_125 , V_126 ) ;
V_48 -> V_127 = F_35 ( int , V_128 ,
V_129 >> V_94 ) ;
if ( ! strcmp ( V_54 , V_70 ) ) {
V_48 -> V_130 = V_131 ;
} else if ( V_95 >> ( 20 - V_94 ) <= 128 ) {
V_48 -> V_130 = 2 ;
} else if ( V_95 >> ( 20 - V_94 ) <= 256 ) {
V_48 -> V_130 = 3 ;
} else if ( V_95 >> ( 20 - V_94 ) <= 512 ) {
V_48 -> V_130 = 4 ;
} else {
if ( F_28 ( V_44 -> V_25 ) )
V_48 -> V_130 = V_132 ;
else
V_48 -> V_130 = V_133 ;
}
V_12 = F_41 () ;
if ( V_12 ) {
F_19 ( L_19 , V_12 ) ;
GOTO ( V_134 , V_12 ) ;
}
F_42 ( V_51 , V_52 , V_54 ,
& V_44 -> V_135 ) ;
V_2 = F_43 ( V_44 ) ;
if ( V_2 == NULL )
GOTO ( V_136 , V_12 = - V_16 ) ;
V_2 -> V_137 = & V_44 -> V_135 ;
V_2 -> V_138 = V_53 ;
memcpy ( V_48 -> V_139 . V_4 , F_30 ( V_46 , 1 ) ,
F_32 ( V_46 , 1 ) ) ;
F_27 ( V_2 ) ;
V_12 = F_15 ( V_2 , & V_50 , 1 ) ;
if ( V_12 ) {
F_19 ( L_20 ) ;
GOTO ( V_140 , V_12 ) ;
}
V_48 -> V_141 = V_2 ;
V_48 -> V_142 = sizeof( struct V_143 ) ;
V_48 -> V_144 = sizeof( struct V_145 ) ;
if ( F_32 ( V_46 , 3 ) > 0 ) {
if ( ! strcmp ( F_44 ( V_46 , 3 ) , L_21 ) ) {
F_2 ( V_14 , L_22 ,
V_54 , V_44 -> V_25 ,
V_48 -> V_139 . V_4 ) ;
F_5 ( & V_2 -> V_19 ) ;
V_2 -> V_146 = 1 ;
F_10 ( & V_2 -> V_19 ) ;
}
}
V_44 -> V_147 = F_45 ( V_44 , V_44 -> V_25 ,
V_148 ,
V_149 ,
V_57 ) ;
if ( V_44 -> V_147 == NULL ) {
F_19 ( L_23 ,
V_44 -> V_25 ) ;
GOTO ( V_140 , V_12 = - V_18 ) ;
}
V_48 -> V_150 = V_151 ;
RETURN ( V_12 ) ;
V_140:
F_25 ( V_2 ) ;
V_136:
F_46 () ;
V_134:
RETURN ( V_12 ) ;
}
int F_47 ( struct V_43 * V_44 )
{
V_13 ;
F_48 ( V_44 -> V_147 ) ;
V_44 -> V_147 = NULL ;
F_18 ( V_44 -> V_49 . V_48 . V_141 == NULL ) ;
F_46 () ;
RETURN ( 0 ) ;
}
int F_49 ( const struct V_152 * V_153 ,
struct V_28 * * exp ,
struct V_43 * V_154 , struct V_3 * V_155 ,
struct V_156 * V_157 , void * V_158 )
{
struct V_47 * V_48 = & V_154 -> V_49 . V_48 ;
struct V_1 * V_2 = V_48 -> V_141 ;
struct V_156 * V_159 ;
struct V_160 V_40 = { 0 } ;
int V_12 ;
V_13 ;
* exp = NULL ;
F_50 ( & V_48 -> V_87 ) ;
if ( V_48 -> V_89 > 0 )
GOTO ( V_161 , V_12 = - V_162 ) ;
V_12 = F_51 ( & V_40 , V_154 , V_155 ) ;
if ( V_12 )
GOTO ( V_161 , V_12 ) ;
V_48 -> V_89 ++ ;
* exp = F_20 ( & V_40 ) ;
F_18 ( V_154 -> V_147 ) ;
V_2 -> V_37 = V_40 ;
V_12 = F_52 ( V_2 ) ;
if ( V_12 != 0 )
GOTO ( V_163 , V_12 ) ;
V_159 = & V_2 -> V_164 ;
if ( V_157 ) {
* V_159 = * V_157 ;
V_2 -> V_165 = V_157 -> V_166 ;
}
V_12 = F_53 ( V_2 ) ;
if ( V_12 != 0 ) {
F_18 ( V_2 -> V_33 == V_35 ) ;
GOTO ( V_163 , V_12 ) ;
}
F_18 ( ( * exp ) -> V_38 ) ;
if ( V_157 ) {
F_54 ( ( V_159 -> V_166 & V_157 -> V_166 ) ==
V_159 -> V_166 , L_24 V_167 L_25 V_167 L_26 ,
V_157 -> V_166 , V_159 -> V_166 ) ;
V_157 -> V_166 = V_159 -> V_166 ;
}
F_55 ( V_2 ) ;
EXIT ;
if ( V_12 ) {
V_163:
V_48 -> V_89 -- ;
F_56 ( * exp ) ;
* exp = NULL ;
}
V_161:
F_57 ( & V_48 -> V_87 ) ;
return V_12 ;
}
int F_58 ( struct V_28 * exp )
{
struct V_43 * V_154 = F_59 ( exp ) ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
int V_12 = 0 , V_134 ;
V_13 ;
if ( ! V_154 ) {
F_19 ( L_27 V_167 L_26 ,
exp , exp ? exp -> V_168 . V_169 : - 1 ) ;
RETURN ( - V_15 ) ;
}
V_48 = & V_154 -> V_49 . V_48 ;
V_2 = V_48 -> V_141 ;
F_50 ( & V_48 -> V_87 ) ;
F_2 ( V_170 , L_28 , V_154 -> V_25 ,
V_48 -> V_89 ) ;
if ( ! V_48 -> V_89 ) {
F_19 ( L_29 ,
V_154 -> V_25 ) ;
GOTO ( V_171 , V_12 = - V_15 ) ;
}
V_48 -> V_89 -- ;
if ( V_48 -> V_89 )
GOTO ( V_171 , V_12 = 0 ) ;
F_5 ( & V_2 -> V_19 ) ;
V_2 -> V_146 = 1 ;
F_10 ( & V_2 -> V_19 ) ;
( void ) F_60 ( V_2 ) ;
if ( V_154 -> V_147 != NULL ) {
F_61 ( V_154 -> V_147 , NULL ,
V_154 -> V_172 ? V_173 : 0 , NULL ) ;
F_62 ( V_154 -> V_147 , V_2 , V_154 -> V_172 ) ;
}
F_57 ( & V_48 -> V_87 ) ;
V_12 = F_63 ( V_2 , 0 ) ;
F_50 ( & V_48 -> V_87 ) ;
F_64 ( V_2 ) ;
EXIT ;
V_171:
V_134 = F_56 ( exp ) ;
if ( ! V_12 && V_134 )
V_12 = V_134 ;
F_57 ( & V_48 -> V_87 ) ;
RETURN ( V_12 ) ;
}
int F_65 ( struct V_174 * V_175 )
{
struct V_43 * V_154 ;
V_13 ;
if ( F_66 ( ! V_175 -> V_176 || ! V_175 -> V_176 -> V_177 ||
! F_67 ( V_175 -> V_176 ) ) ) {
F_68 ( V_175 -> V_178 , 0 ) ;
F_69 ( V_175 -> V_178 , 0 ) ;
RETURN ( 0 ) ;
}
V_154 = V_175 -> V_176 -> V_177 ;
F_70 ( & V_154 -> V_179 ) ;
F_68 ( V_175 -> V_178 , V_154 -> V_180 ) ;
F_69 ( V_175 -> V_178 , V_154 -> V_181 ) ;
F_71 ( & V_154 -> V_179 ) ;
RETURN ( 0 ) ;
}
int F_72 ( struct V_174 * V_175 , int V_12 , int V_182 )
{
if ( F_73 ( V_182 & ~ V_183 , V_183 ) ) {
F_74 ( V_184 , V_175 , L_30 ) ;
return ( - V_185 ) ;
}
if ( F_66 ( V_12 ) ) {
F_74 ( V_186 , V_175 , L_31 , V_12 ) ;
V_175 -> V_187 = V_12 ;
return ( F_75 ( V_175 , 1 ) ) ;
} else {
F_74 ( V_186 , V_175 , L_32 ) ;
}
return ( F_76 ( V_175 , V_188 ) ) ;
}
void F_77 ( struct V_174 * V_175 , int V_12 , int V_182 )
{
struct V_189 * V_190 ;
int V_191 ;
struct V_192 * V_193 ;
struct V_28 * exp ;
V_13 ;
if ( V_175 -> V_194 ) {
EXIT ;
return;
}
V_190 = V_175 -> V_195 -> V_196 ;
V_193 = V_175 -> V_197 ;
if ( V_193 == NULL || ! V_193 -> V_198 ) {
F_72 ( V_175 , V_12 , V_182 ) ;
EXIT ;
return;
}
F_18 ( V_175 -> V_176 != NULL ) ;
F_18 ( V_193 -> V_199 == V_190 ) ;
F_18 ( ! V_193 -> V_200 ) ;
F_18 ( ! V_193 -> V_201 ) ;
F_18 ( ! V_193 -> V_202 ) ;
F_18 ( ! V_193 -> V_203 ) ;
F_18 ( V_193 -> V_204 == NULL ) ;
F_18 ( F_17 ( & V_193 -> V_205 ) ) ;
F_18 ( F_17 ( & V_193 -> V_206 ) ) ;
exp = F_78 ( V_175 -> V_176 ) ;
V_193 -> V_200 = 1 ;
V_193 -> V_203 = 1 ;
V_193 -> V_207 = V_175 -> V_208 ;
V_193 -> V_209 = V_175 -> V_210 ;
V_193 -> V_204 = exp ;
V_193 -> V_211 = F_79 ( V_175 -> V_212 ) ;
F_5 ( & exp -> V_213 ) ;
F_2 ( V_186 , L_33 V_214 L_34 V_214 L_26 ,
V_193 -> V_209 , exp -> V_215 ) ;
if ( V_193 -> V_209 > exp -> V_215 ) {
F_11 ( & V_193 -> V_205 ,
& exp -> V_216 ) ;
}
F_10 ( & exp -> V_213 ) ;
F_5 ( & exp -> V_217 ) ;
F_11 ( & V_193 -> V_206 , & exp -> V_218 ) ;
F_10 ( & exp -> V_217 ) ;
V_191 = F_72 ( V_175 , V_12 , V_182 ) ;
F_5 ( & V_190 -> V_219 ) ;
F_80 ( & V_190 -> V_220 ) ;
if ( V_191 != 0 ) {
V_193 -> V_203 = 0 ;
F_81 ( V_193 ) ;
}
F_5 ( & V_193 -> V_221 ) ;
if ( V_193 -> V_209 <= exp -> V_215 ||
( ! V_193 -> V_203 && ! V_193 -> V_222 ) ||
F_17 ( & V_193 -> V_206 ) ||
F_17 ( & V_193 -> V_205 ) ) {
F_2 ( V_14 , L_35 ) ;
F_82 ( V_193 ) ;
} else {
F_9 ( & V_193 -> V_223 , & V_190 -> V_224 ) ;
V_193 -> V_200 = 0 ;
}
F_10 ( & V_193 -> V_221 ) ;
F_10 ( & V_190 -> V_219 ) ;
EXIT ;
}
int F_83 ( T_3 error )
{
int V_225 ;
switch ( error ) {
case V_226 :
V_225 = 0 ;
break;
case V_227 :
V_225 = - V_228 ;
break;
case V_229 :
V_225 = - V_230 ;
break;
case V_231 :
V_225 = - V_232 ;
break;
case V_233 :
V_225 = - V_16 ;
break;
case V_234 :
V_225 = - V_235 ;
break;
case V_236 :
V_225 = - V_237 ;
break;
default:
if ( ( ( int ) error ) < 0 )
V_225 = error ;
else {
F_19 ( L_36 , error ) ;
V_225 = - V_238 ;
}
}
return V_225 ;
}
T_3 F_84 ( int V_239 )
{
int error ;
switch ( V_239 ) {
case 0 :
error = V_226 ;
break;
case - V_228 :
error = V_227 ;
break;
case - V_230 :
error = V_229 ;
break;
case - V_232 :
error = V_231 ;
break;
case - V_16 :
error = V_233 ;
break;
case - V_235 :
error = V_234 ;
break;
case - V_237 :
error = V_236 ;
break;
default:
error = V_239 ;
}
return error ;
}
void F_85 ( struct V_28 * exp )
{
F_5 ( & exp -> V_240 ) ;
if ( ! F_17 ( & exp -> V_241 ) ) {
struct V_242 * V_243 ;
F_19 ( L_37
L_38 , exp ) ;
F_6 (lock, &exp->exp_locks_list,
l_exp_refs_link)
F_86 ( V_243 , L_39 ) ;
}
F_10 ( & exp -> V_240 ) ;
}
