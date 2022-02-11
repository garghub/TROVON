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
F_4 ( V_10 , sizeof( * V_10 ) ) ;
if ( ! V_10 ) {
V_12 = - V_16 ;
goto V_17;
}
}
F_5 ( & V_2 -> V_18 ) ;
F_6 (item, &imp->imp_conn_list, oic_item) {
if ( F_7 ( V_4 , & V_11 -> V_19 ) ) {
if ( V_5 ) {
F_8 ( & V_11 -> V_20 ) ;
F_9 ( & V_11 -> V_20 ,
& V_2 -> V_21 ) ;
V_11 -> V_22 = 0 ;
}
F_2 ( V_13 , L_3 ,
V_2 , V_2 -> V_23 -> V_24 , V_4 -> V_4 ,
( V_5 ? L_4 : L_5 ) ) ;
F_10 ( & V_2 -> V_18 ) ;
V_12 = 0 ;
goto V_25;
}
}
if ( V_6 ) {
V_10 -> V_26 = V_8 ;
V_10 -> V_19 = * V_4 ;
V_10 -> V_22 = 0 ;
if ( V_5 )
F_9 ( & V_10 -> V_20 , & V_2 -> V_21 ) ;
else
F_11 ( & V_10 -> V_20 ,
& V_2 -> V_21 ) ;
F_2 ( V_13 , L_6 ,
V_2 , V_2 -> V_23 -> V_24 , V_4 -> V_4 ,
( V_5 ? L_7 : L_8 ) ) ;
} else {
F_10 ( & V_2 -> V_18 ) ;
V_12 = - V_15 ;
goto V_25;
}
F_10 ( & V_2 -> V_18 ) ;
return 0 ;
V_25:
if ( V_10 )
F_12 ( V_10 , sizeof( * V_10 ) ) ;
V_17:
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
struct V_27 * V_28 ;
int V_12 = - V_15 ;
F_5 ( & V_2 -> V_18 ) ;
if ( F_17 ( & V_2 -> V_21 ) ) {
F_18 ( ! V_2 -> V_29 ) ;
goto V_30;
}
F_6 (imp_conn, &imp->imp_conn_list, oic_item) {
if ( ! F_7 ( V_4 , & V_10 -> V_19 ) )
continue;
F_18 ( V_10 -> V_26 ) ;
if ( V_10 == V_2 -> V_31 ) {
F_18 ( V_10 -> V_26 == V_2 -> V_29 ) ;
if ( V_2 -> V_32 != V_33 &&
V_2 -> V_32 != V_34 ) {
F_19 ( L_9 ) ;
V_12 = - V_35 ;
goto V_30;
}
F_13 ( V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
V_28 = F_20 ( & V_2 -> V_36 ) ;
if ( V_28 && V_28 -> V_37 ) {
F_18 ( V_28 -> V_37 ==
V_10 -> V_26 ) ;
F_13 ( V_28 -> V_37 ) ;
V_28 -> V_37 = NULL ;
}
}
F_8 ( & V_10 -> V_20 ) ;
F_13 ( V_10 -> V_26 ) ;
F_12 ( V_10 , sizeof( * V_10 ) ) ;
F_2 ( V_13 , L_10 ,
V_2 , V_2 -> V_23 -> V_24 , V_4 -> V_4 ) ;
V_12 = 0 ;
break;
}
V_30:
F_10 ( & V_2 -> V_18 ) ;
if ( V_12 == - V_15 )
F_19 ( L_11 , V_4 -> V_4 ) ;
return V_12 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_38 ,
struct V_3 * V_4 )
{
struct V_9 * V_39 ;
int V_12 = - V_15 ;
F_5 ( & V_2 -> V_18 ) ;
F_6 (conn, &imp->imp_conn_list, oic_item) {
if ( F_22 ( & V_39 -> V_19 , V_38 ) ) {
* V_4 = V_39 -> V_19 ;
V_12 = 0 ;
break;
}
}
F_10 ( & V_2 -> V_18 ) ;
return V_12 ;
}
void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static int F_28 ( char * V_40 )
{
char * V_41 ;
V_41 = strrchr ( V_40 , '-' ) ;
if ( V_41 == NULL )
return 0 ;
if ( strncmp ( V_41 + 1 , L_12 , 3 ) == 0 )
return 1 ;
return 0 ;
}
int F_29 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_46 * V_47 = & V_43 -> V_48 . V_47 ;
struct V_1 * V_2 ;
struct V_3 V_49 ;
int V_50 , V_51 , V_52 ;
char * V_53 = V_43 -> V_54 -> V_55 ;
T_2 V_56 = V_57 ;
int V_12 ;
if ( ! strcmp ( V_53 , V_58 ) ) {
V_50 = V_59 ;
V_51 = V_60 ;
V_52 = V_61 ;
V_47 -> V_62 = V_63 ;
V_47 -> V_64 = V_65 ;
V_56 = V_66 ;
} else if ( ! strcmp ( V_53 , V_67 ) ||
! strcmp ( V_53 , V_68 ) ) {
V_50 = V_69 ;
V_51 = V_70 ;
V_52 = V_71 ;
V_47 -> V_62 = V_63 ;
V_47 -> V_64 = V_72 ;
V_56 = V_73 ;
} else if ( ! strcmp ( V_53 , V_74 ) ) {
if ( strstr ( F_30 ( V_45 , 1 ) , L_13 ) == NULL ) {
V_52 = V_71 ;
V_47 -> V_64 = V_72 ;
V_56 = V_73 ;
V_50 = V_75 ;
} else {
V_52 = V_61 ;
V_47 -> V_64 = V_65 ;
V_56 = V_66 ;
V_50 = V_59 ;
}
V_51 = V_60 ;
V_47 -> V_62 = V_63 ;
} else if ( ! strcmp ( V_53 , V_76 ) ) {
V_50 = V_77 ;
V_51 = V_78 ;
V_52 = V_79 ;
V_47 -> V_62 = V_80 ;
V_47 -> V_64 = V_81 ;
V_47 -> V_82 . V_83 = V_84 ;
V_56 = V_85 ;
} else {
F_19 ( L_14 ,
V_53 ) ;
return - V_14 ;
}
if ( F_31 ( V_45 , 1 ) < 1 ) {
F_19 ( L_15 ) ;
return - V_14 ;
}
if ( F_31 ( V_45 , 1 ) > 37 ) {
F_19 ( L_16 ) ;
return - V_14 ;
}
if ( F_31 ( V_45 , 2 ) < 1 ) {
F_19 ( L_17 ) ;
return - V_14 ;
}
if ( F_31 ( V_45 , 2 ) > 37 ) {
F_19 ( L_18 ) ;
return - V_14 ;
}
F_32 ( & V_47 -> V_86 ) ;
F_33 ( & V_47 -> V_87 ) ;
V_47 -> V_88 = 0 ;
memcpy ( V_49 . V_4 , F_30 ( V_45 , 2 ) ,
F_34 (unsigned int, LUSTRE_CFG_BUFLEN(lcfg, 2),
sizeof(server_uuid)) ) ;
V_47 -> V_89 = 0 ;
V_47 -> V_90 = 0 ;
V_47 -> V_91 = V_92 * 1024 * 1024 ;
if ( V_47 -> V_91 >> V_93 > V_94 / 8 )
V_47 -> V_91 = V_94 << ( V_93 - 3 ) ;
F_35 ( & V_47 -> V_95 ) ;
F_35 ( & V_47 -> V_96 ) ;
F_35 ( & V_47 -> V_97 ) ;
F_35 ( & V_47 -> V_98 ) ;
F_35 ( & V_47 -> V_99 ) ;
F_36 ( & V_47 -> V_100 ) ;
F_37 ( & V_47 -> V_101 , 0 ) ;
F_37 ( & V_47 -> V_102 , 0 ) ;
V_47 -> V_103 = 0 ;
V_47 -> V_104 = 0 ;
F_38 ( & V_47 -> V_105 . V_106 ) ;
F_38 ( & V_47 -> V_107 . V_106 ) ;
F_38 ( & V_47 -> V_108 . V_106 ) ;
F_38 ( & V_47 -> V_109 . V_106 ) ;
F_38 ( & V_47 -> V_110 . V_106 ) ;
F_38 ( & V_47 -> V_111 . V_106 ) ;
F_35 ( & V_47 -> V_112 ) ;
F_37 ( & V_47 -> V_113 , 0 ) ;
F_37 ( & V_47 -> V_114 , 0 ) ;
F_37 ( & V_47 -> V_115 , 0 ) ;
F_35 ( & V_47 -> V_116 ) ;
F_36 ( & V_47 -> V_117 ) ;
F_39 ( & V_47 -> V_118 ) ;
F_37 ( & V_47 -> V_119 , 0 ) ;
V_47 -> V_120 = 1 ;
V_47 -> V_121 = V_47 -> V_122 = V_123 ;
F_37 ( & V_47 -> V_124 , V_125 ) ;
V_47 -> V_126 = F_34 ( int , V_127 ,
V_128 >> V_93 ) ;
if ( ! strcmp ( V_53 , V_67 ) ) {
V_47 -> V_129 = V_130 ;
} else if ( V_94 >> ( 20 - V_93 ) <= 128 ) {
V_47 -> V_129 = 2 ;
} else if ( V_94 >> ( 20 - V_93 ) <= 256 ) {
V_47 -> V_129 = 3 ;
} else if ( V_94 >> ( 20 - V_93 ) <= 512 ) {
V_47 -> V_129 = 4 ;
} else {
if ( F_28 ( V_43 -> V_24 ) )
V_47 -> V_129 = V_131 ;
else
V_47 -> V_129 = V_132 ;
}
V_12 = F_40 () ;
if ( V_12 ) {
F_19 ( L_19 , V_12 ) ;
goto V_133;
}
F_41 ( V_50 , V_51 , V_53 ,
& V_43 -> V_134 ) ;
V_2 = F_42 ( V_43 ) ;
if ( V_2 == NULL ) {
V_12 = - V_15 ;
goto V_135;
}
V_2 -> V_136 = & V_43 -> V_134 ;
V_2 -> V_137 = V_52 ;
memcpy ( V_47 -> V_138 . V_4 , F_30 ( V_45 , 1 ) ,
F_31 ( V_45 , 1 ) ) ;
F_27 ( V_2 ) ;
V_12 = F_15 ( V_2 , & V_49 , 1 ) ;
if ( V_12 ) {
F_19 ( L_20 ) ;
goto V_139;
}
V_47 -> V_140 = V_2 ;
V_47 -> V_141 = sizeof( struct V_142 ) ;
V_47 -> V_143 = sizeof( struct V_144 ) ;
if ( F_31 ( V_45 , 3 ) > 0 ) {
if ( ! strcmp ( F_43 ( V_45 , 3 ) , L_21 ) ) {
F_2 ( V_13 , L_22 ,
V_53 , V_43 -> V_24 ,
V_47 -> V_138 . V_4 ) ;
F_5 ( & V_2 -> V_18 ) ;
V_2 -> V_145 = 1 ;
F_10 ( & V_2 -> V_18 ) ;
}
}
V_43 -> V_146 = F_44 ( V_43 , V_43 -> V_24 ,
V_147 ,
V_148 ,
V_56 ) ;
if ( V_43 -> V_146 == NULL ) {
F_19 ( L_23 ,
V_43 -> V_24 ) ;
V_12 = - V_16 ;
goto V_139;
}
V_47 -> V_149 = V_150 ;
return V_12 ;
V_139:
F_25 ( V_2 ) ;
V_135:
F_45 () ;
V_133:
return V_12 ;
}
int F_46 ( struct V_42 * V_43 )
{
F_47 ( V_43 -> V_146 ) ;
V_43 -> V_146 = NULL ;
F_18 ( V_43 -> V_48 . V_47 . V_140 == NULL ) ;
F_45 () ;
return 0 ;
}
int F_48 ( const struct V_151 * V_152 ,
struct V_27 * * exp ,
struct V_42 * V_153 , struct V_3 * V_154 ,
struct V_155 * V_156 , void * V_157 )
{
struct V_46 * V_47 = & V_153 -> V_48 . V_47 ;
struct V_1 * V_2 = V_47 -> V_140 ;
struct V_155 * V_158 ;
struct V_159 V_39 = { 0 } ;
int V_12 ;
* exp = NULL ;
F_49 ( & V_47 -> V_86 ) ;
if ( V_47 -> V_88 > 0 ) {
V_12 = - V_160 ;
goto V_161;
}
V_12 = F_50 ( & V_39 , V_153 , V_154 ) ;
if ( V_12 )
goto V_161;
V_47 -> V_88 ++ ;
* exp = F_20 ( & V_39 ) ;
F_18 ( V_153 -> V_146 ) ;
V_2 -> V_36 = V_39 ;
V_12 = F_51 ( V_2 ) ;
if ( V_12 != 0 )
goto V_162;
V_158 = & V_2 -> V_163 ;
if ( V_156 ) {
* V_158 = * V_156 ;
V_2 -> V_164 = V_156 -> V_165 ;
}
V_12 = F_52 ( V_2 ) ;
if ( V_12 != 0 ) {
F_18 ( V_2 -> V_32 == V_34 ) ;
goto V_162;
}
F_18 ( * exp != NULL && ( * exp ) -> V_37 ) ;
if ( V_156 ) {
F_53 ( ( V_158 -> V_165 & V_156 -> V_165 ) ==
V_158 -> V_165 , L_24 ,
V_156 -> V_165 , V_158 -> V_165 ) ;
V_156 -> V_165 = V_158 -> V_165 ;
}
F_54 ( V_2 ) ;
if ( V_12 ) {
V_162:
V_47 -> V_88 -- ;
F_55 ( * exp ) ;
* exp = NULL ;
}
V_161:
F_56 ( & V_47 -> V_86 ) ;
return V_12 ;
}
int F_57 ( struct V_27 * exp )
{
struct V_42 * V_153 = F_58 ( exp ) ;
struct V_46 * V_47 ;
struct V_1 * V_2 ;
int V_12 = 0 , V_133 ;
if ( ! V_153 ) {
F_19 ( L_25 ,
exp , exp ? exp -> V_166 . V_167 : - 1 ) ;
return - V_14 ;
}
V_47 = & V_153 -> V_48 . V_47 ;
V_2 = V_47 -> V_140 ;
F_49 ( & V_47 -> V_86 ) ;
F_2 ( V_168 , L_26 , V_153 -> V_24 ,
V_47 -> V_88 ) ;
if ( ! V_47 -> V_88 ) {
F_19 ( L_27 ,
V_153 -> V_24 ) ;
V_12 = - V_14 ;
goto V_169;
}
V_47 -> V_88 -- ;
if ( V_47 -> V_88 ) {
V_12 = 0 ;
goto V_169;
}
F_5 ( & V_2 -> V_18 ) ;
V_2 -> V_145 = 1 ;
F_10 ( & V_2 -> V_18 ) ;
( void ) F_59 ( V_2 ) ;
if ( V_153 -> V_146 != NULL ) {
F_60 ( V_153 -> V_146 , NULL ,
V_153 -> V_170 ? V_171 : 0 , NULL ) ;
F_61 ( V_153 -> V_146 , V_2 ,
V_153 -> V_170 ) ;
}
F_56 ( & V_47 -> V_86 ) ;
V_12 = F_62 ( V_2 , 0 ) ;
F_49 ( & V_47 -> V_86 ) ;
F_63 ( V_2 ) ;
V_169:
V_133 = F_55 ( exp ) ;
if ( ! V_12 && V_133 )
V_12 = V_133 ;
F_56 ( & V_47 -> V_86 ) ;
return V_12 ;
}
int F_64 ( struct V_172 * V_173 )
{
struct V_42 * V_153 ;
if ( F_65 ( ! V_173 -> V_174 || ! V_173 -> V_174 -> V_175 ||
! F_66 ( V_173 -> V_174 ) ) ) {
F_67 ( V_173 -> V_176 , 0 ) ;
F_68 ( V_173 -> V_176 , 0 ) ;
return 0 ;
}
V_153 = V_173 -> V_174 -> V_175 ;
F_69 ( & V_153 -> V_177 ) ;
F_67 ( V_173 -> V_176 , V_153 -> V_178 ) ;
F_68 ( V_173 -> V_176 , V_153 -> V_179 ) ;
F_70 ( & V_153 -> V_177 ) ;
return 0 ;
}
int F_71 ( struct V_172 * V_173 , int V_12 , int V_180 )
{
if ( F_72 ( V_180 & ~ V_181 , V_181 ) ) {
F_73 ( V_182 , V_173 , L_28 ) ;
return - V_183 ;
}
if ( F_65 ( V_12 ) ) {
F_73 ( V_184 , V_173 , L_29 , V_12 ) ;
V_173 -> V_185 = V_12 ;
return F_74 ( V_173 , 1 ) ;
} else {
F_73 ( V_184 , V_173 , L_30 ) ;
}
return F_75 ( V_173 , V_186 ) ;
}
void F_76 ( struct V_172 * V_173 , int V_12 , int V_180 )
{
struct V_187 * V_188 ;
int V_189 ;
struct V_190 * V_191 ;
struct V_27 * exp ;
if ( V_173 -> V_192 )
return;
V_188 = V_173 -> V_193 -> V_194 ;
V_191 = V_173 -> V_195 ;
if ( V_191 == NULL || ! V_191 -> V_196 ) {
F_71 ( V_173 , V_12 , V_180 ) ;
return;
}
F_18 ( V_173 -> V_174 != NULL ) ;
F_18 ( V_191 -> V_197 == V_188 ) ;
F_18 ( ! V_191 -> V_198 ) ;
F_18 ( ! V_191 -> V_199 ) ;
F_18 ( ! V_191 -> V_200 ) ;
F_18 ( ! V_191 -> V_201 ) ;
F_18 ( V_191 -> V_202 == NULL ) ;
F_18 ( F_17 ( & V_191 -> V_203 ) ) ;
F_18 ( F_17 ( & V_191 -> V_204 ) ) ;
exp = F_77 ( V_173 -> V_174 ) ;
V_191 -> V_198 = 1 ;
V_191 -> V_201 = 1 ;
V_191 -> V_205 = V_173 -> V_206 ;
V_191 -> V_207 = V_173 -> V_208 ;
V_191 -> V_202 = exp ;
V_191 -> V_209 = F_78 ( V_173 -> V_210 ) ;
F_5 ( & exp -> V_211 ) ;
F_2 ( V_184 , L_31 ,
V_191 -> V_207 , exp -> V_212 ) ;
if ( V_191 -> V_207 > exp -> V_212 ) {
F_11 ( & V_191 -> V_203 ,
& exp -> V_213 ) ;
}
F_10 ( & exp -> V_211 ) ;
F_5 ( & exp -> V_214 ) ;
F_11 ( & V_191 -> V_204 , & exp -> V_215 ) ;
F_10 ( & exp -> V_214 ) ;
V_189 = F_71 ( V_173 , V_12 , V_180 ) ;
F_5 ( & V_188 -> V_216 ) ;
F_79 ( & V_188 -> V_217 ) ;
if ( V_189 != 0 ) {
V_191 -> V_201 = 0 ;
F_80 ( V_191 ) ;
}
F_5 ( & V_191 -> V_218 ) ;
if ( V_191 -> V_207 <= exp -> V_212 ||
( ! V_191 -> V_201 && ! V_191 -> V_219 ) ||
F_17 ( & V_191 -> V_204 ) ||
F_17 ( & V_191 -> V_203 ) ) {
F_2 ( V_13 , L_32 ) ;
F_81 ( V_191 ) ;
} else {
F_9 ( & V_191 -> V_220 , & V_188 -> V_221 ) ;
V_191 -> V_198 = 0 ;
}
F_10 ( & V_191 -> V_218 ) ;
F_10 ( & V_188 -> V_216 ) ;
}
int F_82 ( T_3 error )
{
int V_222 ;
switch ( error ) {
case V_223 :
V_222 = 0 ;
break;
case V_224 :
V_222 = - V_225 ;
break;
case V_226 :
V_222 = - V_227 ;
break;
case V_228 :
V_222 = - V_229 ;
break;
case V_230 :
V_222 = - V_15 ;
break;
case V_231 :
V_222 = - V_232 ;
break;
case V_233 :
V_222 = - V_234 ;
break;
default:
if ( ( ( int ) error ) < 0 )
V_222 = error ;
else {
F_19 ( L_33 , error ) ;
V_222 = - V_235 ;
}
}
return V_222 ;
}
T_3 F_83 ( int V_236 )
{
int error ;
switch ( V_236 ) {
case 0 :
error = V_223 ;
break;
case - V_225 :
error = V_224 ;
break;
case - V_227 :
error = V_226 ;
break;
case - V_229 :
error = V_228 ;
break;
case - V_15 :
error = V_230 ;
break;
case - V_232 :
error = V_231 ;
break;
case - V_234 :
error = V_233 ;
break;
default:
error = V_236 ;
}
return error ;
}
void F_84 ( struct V_27 * exp )
{
F_5 ( & exp -> V_237 ) ;
if ( ! F_17 ( & exp -> V_238 ) ) {
struct V_239 * V_240 ;
F_19 ( L_34 ,
exp ) ;
F_6 (lock, &exp->exp_locks_list,
l_exp_refs_link)
F_85 ( V_240 , L_35 ) ;
}
F_10 ( & exp -> V_237 ) ;
}
