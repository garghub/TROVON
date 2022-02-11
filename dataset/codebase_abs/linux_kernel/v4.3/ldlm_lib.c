static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL , * V_11 ;
int V_12 = 0 ;
if ( ! V_6 && ! V_5 ) {
F_2 ( V_13 , L_1 ) ;
return - V_14 ;
}
V_8 = F_3 ( V_4 ) ;
if ( ! V_8 ) {
F_2 ( V_13 , L_2 , V_4 -> V_4 ) ;
return - V_15 ;
}
if ( V_6 ) {
V_10 = F_4 ( sizeof( * V_10 ) , V_16 ) ;
if ( ! V_10 ) {
V_12 = - V_17 ;
goto V_18;
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
F_2 ( V_13 , L_3 ,
V_2 , V_2 -> V_24 -> V_25 , V_4 -> V_4 ,
( V_5 ? L_4 : L_5 ) ) ;
F_10 ( & V_2 -> V_19 ) ;
V_12 = 0 ;
goto V_26;
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
F_2 ( V_13 , L_6 ,
V_2 , V_2 -> V_24 -> V_25 , V_4 -> V_4 ,
( V_5 ? L_7 : L_8 ) ) ;
} else {
F_10 ( & V_2 -> V_19 ) ;
V_12 = - V_15 ;
goto V_26;
}
F_10 ( & V_2 -> V_19 ) ;
return 0 ;
V_26:
F_12 ( V_10 ) ;
V_18:
F_13 ( V_8 ) ;
return V_12 ;
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
int V_12 = - V_15 ;
F_5 ( & V_2 -> V_19 ) ;
if ( F_17 ( & V_2 -> V_22 ) ) {
F_18 ( ! V_2 -> V_30 ) ;
goto V_31;
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
V_12 = - V_36 ;
goto V_31;
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
F_12 ( V_10 ) ;
F_2 ( V_13 , L_10 ,
V_2 , V_2 -> V_24 -> V_25 , V_4 -> V_4 ) ;
V_12 = 0 ;
break;
}
V_31:
F_10 ( & V_2 -> V_19 ) ;
if ( V_12 == - V_15 )
F_19 ( L_11 , V_4 -> V_4 ) ;
return V_12 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_39 ,
struct V_3 * V_4 )
{
struct V_9 * V_40 ;
int V_12 = - V_15 ;
F_5 ( & V_2 -> V_19 ) ;
F_6 (conn, &imp->imp_conn_list, oic_item) {
if ( F_22 ( & V_40 -> V_20 , V_39 ) ) {
* V_4 = V_40 -> V_20 ;
V_12 = 0 ;
break;
}
}
F_10 ( & V_2 -> V_19 ) ;
return V_12 ;
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
if ( ! strcmp ( V_54 , V_59 ) ) {
V_51 = V_60 ;
V_52 = V_61 ;
V_53 = V_62 ;
V_48 -> V_63 = V_64 ;
V_48 -> V_65 = V_66 ;
V_57 = V_67 ;
} else if ( ! strcmp ( V_54 , V_68 ) ||
! strcmp ( V_54 , V_69 ) ) {
V_51 = V_70 ;
V_52 = V_71 ;
V_53 = V_72 ;
V_48 -> V_63 = V_64 ;
V_48 -> V_65 = V_73 ;
V_57 = V_74 ;
} else if ( ! strcmp ( V_54 , V_75 ) ) {
if ( strstr ( F_30 ( V_46 , 1 ) , L_13 ) == NULL ) {
V_53 = V_72 ;
V_48 -> V_65 = V_73 ;
V_57 = V_74 ;
V_51 = V_76 ;
} else {
V_53 = V_62 ;
V_48 -> V_65 = V_66 ;
V_57 = V_67 ;
V_51 = V_60 ;
}
V_52 = V_61 ;
V_48 -> V_63 = V_64 ;
} else if ( ! strcmp ( V_54 , V_77 ) ) {
V_51 = V_78 ;
V_52 = V_79 ;
V_53 = V_80 ;
V_48 -> V_63 = V_81 ;
V_48 -> V_65 = V_82 ;
V_48 -> V_83 . V_84 = V_85 ;
V_57 = V_86 ;
} else {
F_19 ( L_14 ,
V_54 ) ;
return - V_14 ;
}
if ( F_31 ( V_46 , 1 ) < 1 ) {
F_19 ( L_15 ) ;
return - V_14 ;
}
if ( F_31 ( V_46 , 1 ) > 37 ) {
F_19 ( L_16 ) ;
return - V_14 ;
}
if ( F_31 ( V_46 , 2 ) < 1 ) {
F_19 ( L_17 ) ;
return - V_14 ;
}
if ( F_31 ( V_46 , 2 ) > 37 ) {
F_19 ( L_18 ) ;
return - V_14 ;
}
F_32 ( & V_48 -> V_87 ) ;
F_33 ( & V_48 -> V_88 ) ;
V_48 -> V_89 = 0 ;
memcpy ( V_50 . V_4 , F_30 ( V_46 , 2 ) ,
F_34 (unsigned int, LUSTRE_CFG_BUFLEN(lcfg, 2),
sizeof(server_uuid)) ) ;
V_48 -> V_90 = 0 ;
V_48 -> V_91 = 0 ;
V_48 -> V_92 = V_93 * 1024 * 1024 ;
if ( V_48 -> V_92 >> V_94 > V_95 / 8 )
V_48 -> V_92 = V_95 << ( V_94 - 3 ) ;
F_35 ( & V_48 -> V_96 ) ;
F_35 ( & V_48 -> V_97 ) ;
F_35 ( & V_48 -> V_98 ) ;
F_35 ( & V_48 -> V_99 ) ;
F_35 ( & V_48 -> V_100 ) ;
F_36 ( & V_48 -> V_101 ) ;
F_37 ( & V_48 -> V_102 , 0 ) ;
F_37 ( & V_48 -> V_103 , 0 ) ;
V_48 -> V_104 = 0 ;
V_48 -> V_105 = 0 ;
F_38 ( & V_48 -> V_106 . V_107 ) ;
F_38 ( & V_48 -> V_108 . V_107 ) ;
F_38 ( & V_48 -> V_109 . V_107 ) ;
F_38 ( & V_48 -> V_110 . V_107 ) ;
F_38 ( & V_48 -> V_111 . V_107 ) ;
F_38 ( & V_48 -> V_112 . V_107 ) ;
F_35 ( & V_48 -> V_113 ) ;
F_37 ( & V_48 -> V_114 , 0 ) ;
F_37 ( & V_48 -> V_115 , 0 ) ;
F_37 ( & V_48 -> V_116 , 0 ) ;
F_35 ( & V_48 -> V_117 ) ;
F_36 ( & V_48 -> V_118 ) ;
F_39 ( & V_48 -> V_119 ) ;
F_37 ( & V_48 -> V_120 , 0 ) ;
V_48 -> V_121 = 1 ;
V_48 -> V_122 = V_48 -> V_123 = V_124 ;
F_37 ( & V_48 -> V_125 , V_126 ) ;
V_48 -> V_127 = F_34 ( int , V_128 ,
V_129 >> V_94 ) ;
if ( ! strcmp ( V_54 , V_68 ) ) {
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
V_12 = F_40 () ;
if ( V_12 ) {
F_19 ( L_19 , V_12 ) ;
goto V_134;
}
F_41 ( V_51 , V_52 , V_54 ,
& V_44 -> V_135 ) ;
V_2 = F_42 ( V_44 ) ;
if ( V_2 == NULL ) {
V_12 = - V_15 ;
goto V_136;
}
V_2 -> V_137 = & V_44 -> V_135 ;
V_2 -> V_138 = V_53 ;
memcpy ( V_48 -> V_139 . V_4 , F_30 ( V_46 , 1 ) ,
F_31 ( V_46 , 1 ) ) ;
F_27 ( V_2 ) ;
V_12 = F_15 ( V_2 , & V_50 , 1 ) ;
if ( V_12 ) {
F_19 ( L_20 ) ;
goto V_140;
}
V_48 -> V_141 = V_2 ;
V_48 -> V_142 = sizeof( struct V_143 ) ;
V_48 -> V_144 = sizeof( struct V_145 ) ;
if ( F_31 ( V_46 , 3 ) > 0 ) {
if ( ! strcmp ( F_43 ( V_46 , 3 ) , L_21 ) ) {
F_2 ( V_13 , L_22 ,
V_54 , V_44 -> V_25 ,
V_48 -> V_139 . V_4 ) ;
F_5 ( & V_2 -> V_19 ) ;
V_2 -> V_146 = 1 ;
F_10 ( & V_2 -> V_19 ) ;
}
}
V_44 -> V_147 = F_44 ( V_44 , V_44 -> V_25 ,
V_148 ,
V_149 ,
V_57 ) ;
if ( V_44 -> V_147 == NULL ) {
F_19 ( L_23 ,
V_44 -> V_25 ) ;
V_12 = - V_17 ;
goto V_140;
}
V_48 -> V_150 = V_151 ;
return V_12 ;
V_140:
F_25 ( V_2 ) ;
V_136:
F_45 () ;
V_134:
return V_12 ;
}
int F_46 ( struct V_43 * V_44 )
{
F_47 ( V_44 -> V_147 ) ;
V_44 -> V_147 = NULL ;
F_18 ( V_44 -> V_49 . V_48 . V_141 == NULL ) ;
F_45 () ;
return 0 ;
}
int F_48 ( const struct V_152 * V_153 ,
struct V_28 * * exp ,
struct V_43 * V_154 , struct V_3 * V_155 ,
struct V_156 * V_157 , void * V_158 )
{
struct V_47 * V_48 = & V_154 -> V_49 . V_48 ;
struct V_1 * V_2 = V_48 -> V_141 ;
struct V_156 * V_159 ;
struct V_160 V_40 = { 0 } ;
int V_12 ;
* exp = NULL ;
F_49 ( & V_48 -> V_87 ) ;
if ( V_48 -> V_89 > 0 ) {
V_12 = - V_161 ;
goto V_162;
}
V_12 = F_50 ( & V_40 , V_154 , V_155 ) ;
if ( V_12 )
goto V_162;
V_48 -> V_89 ++ ;
* exp = F_20 ( & V_40 ) ;
F_18 ( V_154 -> V_147 ) ;
V_2 -> V_37 = V_40 ;
V_12 = F_51 ( V_2 ) ;
if ( V_12 != 0 )
goto V_163;
V_159 = & V_2 -> V_164 ;
if ( V_157 ) {
* V_159 = * V_157 ;
V_2 -> V_165 = V_157 -> V_166 ;
}
V_12 = F_52 ( V_2 ) ;
if ( V_12 != 0 ) {
F_18 ( V_2 -> V_33 == V_35 ) ;
goto V_163;
}
F_18 ( * exp != NULL && ( * exp ) -> V_38 ) ;
if ( V_157 ) {
F_53 ( ( V_159 -> V_166 & V_157 -> V_166 ) ==
V_159 -> V_166 , L_24 ,
V_157 -> V_166 , V_159 -> V_166 ) ;
V_157 -> V_166 = V_159 -> V_166 ;
}
F_54 ( V_2 ) ;
if ( V_12 ) {
V_163:
V_48 -> V_89 -- ;
F_55 ( * exp ) ;
* exp = NULL ;
}
V_162:
F_56 ( & V_48 -> V_87 ) ;
return V_12 ;
}
int F_57 ( struct V_28 * exp )
{
struct V_43 * V_154 = F_58 ( exp ) ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
int V_12 = 0 , V_134 ;
if ( ! V_154 ) {
F_19 ( L_25 ,
exp , exp ? exp -> V_167 . V_168 : - 1 ) ;
return - V_14 ;
}
V_48 = & V_154 -> V_49 . V_48 ;
V_2 = V_48 -> V_141 ;
F_49 ( & V_48 -> V_87 ) ;
F_2 ( V_169 , L_26 , V_154 -> V_25 ,
V_48 -> V_89 ) ;
if ( ! V_48 -> V_89 ) {
F_19 ( L_27 ,
V_154 -> V_25 ) ;
V_12 = - V_14 ;
goto V_170;
}
V_48 -> V_89 -- ;
if ( V_48 -> V_89 ) {
V_12 = 0 ;
goto V_170;
}
F_5 ( & V_2 -> V_19 ) ;
V_2 -> V_146 = 1 ;
F_10 ( & V_2 -> V_19 ) ;
( void ) F_59 ( V_2 ) ;
if ( V_154 -> V_147 != NULL ) {
F_60 ( V_154 -> V_147 , NULL ,
V_154 -> V_171 ? V_172 : 0 , NULL ) ;
F_61 ( V_154 -> V_147 , V_2 ,
V_154 -> V_171 ) ;
}
F_56 ( & V_48 -> V_87 ) ;
V_12 = F_62 ( V_2 , 0 ) ;
F_49 ( & V_48 -> V_87 ) ;
F_63 ( V_2 ) ;
V_170:
V_134 = F_55 ( exp ) ;
if ( ! V_12 && V_134 )
V_12 = V_134 ;
F_56 ( & V_48 -> V_87 ) ;
return V_12 ;
}
int F_64 ( struct V_173 * V_174 )
{
struct V_43 * V_154 ;
if ( F_65 ( ! V_174 -> V_175 || ! V_174 -> V_175 -> V_176 ||
! F_66 ( V_174 -> V_175 ) ) ) {
F_67 ( V_174 -> V_177 , 0 ) ;
F_68 ( V_174 -> V_177 , 0 ) ;
return 0 ;
}
V_154 = V_174 -> V_175 -> V_176 ;
F_69 ( & V_154 -> V_178 ) ;
F_67 ( V_174 -> V_177 , V_154 -> V_179 ) ;
F_68 ( V_174 -> V_177 , V_154 -> V_180 ) ;
F_70 ( & V_154 -> V_178 ) ;
return 0 ;
}
static int
F_71 ( struct V_173 * V_174 , int V_12 , int V_181 )
{
if ( F_72 ( V_181 & ~ V_182 , V_182 ) ) {
F_73 ( V_183 , V_174 , L_28 ) ;
return - V_184 ;
}
if ( F_65 ( V_12 ) ) {
F_73 ( V_185 , V_174 , L_29 , V_12 ) ;
V_174 -> V_186 = V_12 ;
return F_74 ( V_174 , 1 ) ;
}
F_73 ( V_185 , V_174 , L_30 ) ;
return F_75 ( V_174 , V_187 ) ;
}
void F_76 ( struct V_173 * V_174 , int V_12 , int V_181 )
{
struct V_188 * V_189 ;
int V_190 ;
struct V_191 * V_192 ;
struct V_28 * exp ;
if ( V_174 -> V_193 )
return;
V_189 = V_174 -> V_194 -> V_195 ;
V_192 = V_174 -> V_196 ;
if ( V_192 == NULL || ! V_192 -> V_197 ) {
F_71 ( V_174 , V_12 , V_181 ) ;
return;
}
F_18 ( V_174 -> V_175 != NULL ) ;
F_18 ( V_192 -> V_198 == V_189 ) ;
F_18 ( ! V_192 -> V_199 ) ;
F_18 ( ! V_192 -> V_200 ) ;
F_18 ( ! V_192 -> V_201 ) ;
F_18 ( ! V_192 -> V_202 ) ;
F_18 ( V_192 -> V_203 == NULL ) ;
F_18 ( F_17 ( & V_192 -> V_204 ) ) ;
F_18 ( F_17 ( & V_192 -> V_205 ) ) ;
exp = F_77 ( V_174 -> V_175 ) ;
V_192 -> V_199 = 1 ;
V_192 -> V_202 = 1 ;
V_192 -> V_206 = V_174 -> V_207 ;
V_192 -> V_208 = V_174 -> V_209 ;
V_192 -> V_203 = exp ;
V_192 -> V_210 = F_78 ( V_174 -> V_211 ) ;
F_5 ( & exp -> V_212 ) ;
F_2 ( V_185 , L_31 ,
V_192 -> V_208 , exp -> V_213 ) ;
if ( V_192 -> V_208 > exp -> V_213 ) {
F_11 ( & V_192 -> V_204 ,
& exp -> V_214 ) ;
}
F_10 ( & exp -> V_212 ) ;
F_5 ( & exp -> V_215 ) ;
F_11 ( & V_192 -> V_205 , & exp -> V_216 ) ;
F_10 ( & exp -> V_215 ) ;
V_190 = F_71 ( V_174 , V_12 , V_181 ) ;
F_5 ( & V_189 -> V_217 ) ;
F_79 ( & V_189 -> V_218 ) ;
if ( V_190 != 0 ) {
V_192 -> V_202 = 0 ;
F_80 ( V_192 ) ;
}
F_5 ( & V_192 -> V_219 ) ;
if ( V_192 -> V_208 <= exp -> V_213 ||
( ! V_192 -> V_202 && ! V_192 -> V_220 ) ||
F_17 ( & V_192 -> V_205 ) ||
F_17 ( & V_192 -> V_204 ) ) {
F_2 ( V_13 , L_32 ) ;
F_81 ( V_192 ) ;
} else {
F_9 ( & V_192 -> V_221 , & V_189 -> V_222 ) ;
V_192 -> V_199 = 0 ;
}
F_10 ( & V_192 -> V_219 ) ;
F_10 ( & V_189 -> V_217 ) ;
}
int F_82 ( T_3 error )
{
int V_223 ;
switch ( error ) {
case V_224 :
V_223 = 0 ;
break;
case V_225 :
V_223 = - V_226 ;
break;
case V_227 :
V_223 = - V_228 ;
break;
case V_229 :
V_223 = - V_230 ;
break;
case V_231 :
V_223 = - V_15 ;
break;
case V_232 :
V_223 = - V_233 ;
break;
case V_234 :
V_223 = - V_235 ;
break;
default:
if ( ( ( int ) error ) < 0 )
V_223 = error ;
else {
F_19 ( L_33 , error ) ;
V_223 = - V_236 ;
}
}
return V_223 ;
}
T_3 F_83 ( int V_237 )
{
int error ;
switch ( V_237 ) {
case 0 :
error = V_224 ;
break;
case - V_226 :
error = V_225 ;
break;
case - V_228 :
error = V_227 ;
break;
case - V_230 :
error = V_229 ;
break;
case - V_15 :
error = V_231 ;
break;
case - V_233 :
error = V_232 ;
break;
case - V_235 :
error = V_234 ;
break;
default:
error = V_237 ;
}
return error ;
}
void F_84 ( struct V_28 * exp )
{
F_5 ( & exp -> V_238 ) ;
if ( ! F_17 ( & exp -> V_239 ) ) {
struct V_240 * V_241 ;
F_19 ( L_34 ,
exp ) ;
F_6 (lock, &exp->exp_locks_list,
l_exp_refs_link)
F_85 ( V_241 , L_35 ) ;
}
F_10 ( & exp -> V_238 ) ;
}
