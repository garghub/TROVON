static int T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_4 ;
V_4 = F_2 ( V_5 , NULL ) ;
if ( ! V_4 )
return - V_6 ;
V_3 = F_2 ( V_7 , V_4 ) ;
if ( ! V_3 )
goto V_8;
F_3 ( & V_3 -> V_9 ,
& V_1 -> V_10 . V_11 [ V_12 ] ) ;
F_3 ( & V_4 -> V_9 ,
& V_1 -> V_10 . V_11 [ V_13 ] ) ;
return 0 ;
V_8:
F_4 ( V_4 ) ;
return - V_6 ;
}
struct V_2 * F_5 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_15 , * V_16 = NULL ;
unsigned int V_17 ;
if ( V_14 == 0 )
V_14 = V_5 ;
V_15 = F_6 ( V_1 , V_14 ) ;
if ( V_15 )
return V_15 ;
if ( V_14 == V_7 && ! V_1 -> V_10 . V_18 )
V_16 = F_5 ( V_1 , V_5 ) ;
V_15 = F_2 ( V_14 , V_16 ) ;
if ( ! V_15 )
return NULL ;
switch ( V_14 ) {
case V_5 :
F_7 ( V_1 -> V_10 . V_19 , V_15 ) ;
break;
case V_20 :
F_7 ( V_1 -> V_10 . V_21 , V_15 ) ;
break;
default:
break;
}
V_17 = V_14 & ( V_22 - 1 ) ;
F_3 ( & V_15 -> V_9 , & V_1 -> V_10 . V_11 [ V_17 ] ) ;
return V_15 ;
}
struct V_2 * F_6 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_15 ;
struct V_23 * V_24 ;
unsigned int V_17 ;
if ( V_14 == 0 )
V_14 = V_5 ;
V_17 = V_14 & ( V_22 - 1 ) ;
V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_15 -> V_25 == V_14 )
return V_15 ;
}
return NULL ;
}
static void F_9 ( struct V_1 * V_1 , struct V_2 * V_26 ,
struct V_2 * V_27 )
{
#ifdef F_10
switch ( V_27 -> V_25 ) {
case V_5 :
F_7 ( V_1 -> V_10 . V_19 , V_27 ) ;
break;
case V_20 :
F_7 ( V_1 -> V_10 . V_21 , V_27 ) ;
break;
default:
break;
}
#endif
F_11 ( & V_26 -> V_9 , & V_27 -> V_9 ) ;
}
int F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_26 , * V_27 , * V_4 ;
V_26 = F_6 ( V_1 , V_7 ) ;
if ( ! V_26 )
return 0 ;
V_27 = F_13 ( V_26 ) ;
if ( ! V_27 )
return - V_6 ;
if ( V_27 == V_26 )
return 0 ;
F_9 ( V_1 , V_26 , V_27 ) ;
F_4 ( V_26 ) ;
V_4 = F_6 ( V_1 , V_5 ) ;
if ( ! V_4 )
return 0 ;
F_14 ( V_4 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_1 )
{
int V_28 = 0 ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
struct V_23 * V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
struct V_29 * V_30 ;
struct V_2 * V_15 ;
F_16 (tb, tmp, head, tb_hlist)
V_28 += F_17 ( V_1 , V_15 ) ;
}
if ( V_28 )
F_18 ( V_1 ) ;
}
static inline unsigned int F_19 ( struct V_1 * V_1 ,
const struct V_31 * V_32 ,
T_3 V_33 , T_2 V_25 )
{
struct V_34 V_35 = { . V_36 = V_33 } ;
struct V_37 V_38 ;
unsigned int V_39 = V_40 ;
struct V_2 * V_41 ;
if ( F_20 ( V_33 ) || F_21 ( V_33 ) )
return V_40 ;
if ( F_22 ( V_33 ) )
return V_42 ;
F_23 () ;
V_41 = F_6 ( V_1 , V_25 ) ;
if ( V_41 ) {
V_39 = V_43 ;
if ( ! F_24 ( V_41 , & V_35 , & V_38 , V_44 ) ) {
if ( ! V_32 || V_32 == V_38 . V_45 -> V_46 )
V_39 = V_38 . type ;
}
}
F_25 () ;
return V_39 ;
}
unsigned int F_26 ( struct V_1 * V_1 , T_3 V_33 , T_2 V_25 )
{
return F_19 ( V_1 , NULL , V_33 , V_25 ) ;
}
unsigned int F_27 ( struct V_1 * V_1 , T_3 V_33 )
{
return F_19 ( V_1 , NULL , V_33 , V_7 ) ;
}
unsigned int F_28 ( struct V_1 * V_1 , const struct V_31 * V_32 ,
T_3 V_33 )
{
T_2 V_47 = F_29 ( V_32 ) ? : V_7 ;
return F_19 ( V_1 , V_32 , V_33 , V_47 ) ;
}
unsigned int F_30 ( struct V_1 * V_1 ,
const struct V_31 * V_32 ,
T_3 V_33 )
{
T_2 V_47 = F_29 ( V_32 ) ? : V_7 ;
return F_19 ( V_1 , NULL , V_33 , V_47 ) ;
}
T_3 F_31 ( struct V_48 * V_49 )
{
struct V_31 * V_32 = V_49 -> V_32 ;
struct V_50 * V_51 ;
struct V_37 V_38 ;
struct V_52 * V_53 ;
struct V_1 * V_1 ;
int V_54 ;
V_53 = F_32 ( V_49 ) ;
if ( ( V_53 -> V_55 & ( V_56 | V_57 | V_58 ) ) ==
V_58 )
return F_33 ( V_49 ) -> V_36 ;
V_51 = F_34 ( V_32 ) ;
F_35 ( ! V_51 ) ;
V_1 = F_36 ( V_32 ) ;
V_54 = V_59 ;
if ( ! F_20 ( F_33 ( V_49 ) -> V_60 ) ) {
struct V_34 V_35 = {
. V_61 = V_62 ,
. V_36 = F_33 ( V_49 ) -> V_60 ,
. V_63 = F_37 ( F_33 ( V_49 ) -> V_64 ) ,
. V_65 = V_54 ,
. V_66 = F_38 ( V_51 ) ? V_49 -> V_67 : 0 ,
} ;
if ( ! F_39 ( V_1 , & V_35 , & V_38 , 0 ) )
return F_40 ( V_1 , V_38 ) ;
} else {
V_54 = V_68 ;
}
return F_41 ( V_32 , F_33 ( V_49 ) -> V_60 , V_54 ) ;
}
static int F_42 ( struct V_48 * V_49 , T_3 V_69 , T_3 V_70 ,
T_4 V_64 , int V_71 , struct V_31 * V_32 ,
int V_72 , struct V_50 * V_73 , T_2 * V_74 )
{
int V_39 , V_75 ;
struct V_37 V_38 ;
struct V_34 V_35 ;
struct V_1 * V_1 = F_36 ( V_32 ) ;
bool V_76 ;
V_35 . V_77 = 0 ;
V_35 . V_61 = F_43 ( V_32 ) ;
if ( ! V_35 . V_61 )
V_35 . V_61 = V_71 ? : V_62 ;
V_35 . V_36 = V_69 ;
V_35 . V_60 = V_70 ;
V_35 . V_63 = V_64 ;
V_35 . V_65 = V_59 ;
V_35 . V_78 . V_79 = 0 ;
V_35 . V_80 = 0 ;
V_35 . V_81 = F_44 ( V_1 , NULL ) ;
V_75 = V_73 -> V_82 == NULL ;
V_35 . V_66 = F_38 ( V_73 ) ? V_49 -> V_67 : 0 ;
F_45 ( V_32 , & V_35 ) ;
if ( F_39 ( V_1 , & V_35 , & V_38 , 0 ) )
goto V_83;
if ( V_38 . type != V_43 &&
( V_38 . type != V_84 || ! F_46 ( V_73 ) ) )
goto V_85;
if ( ! V_72 && ! F_47 ( V_1 ) &&
( V_32 -> V_86 != V_71 || ! F_48 ( V_73 ) ) )
goto V_83;
F_49 ( V_74 , & V_38 ) ;
V_76 = false ;
#ifdef F_50
for ( V_39 = 0 ; V_39 < V_38 . V_45 -> V_87 ; V_39 ++ ) {
struct V_88 * V_89 = & V_38 . V_45 -> V_88 [ V_39 ] ;
if ( V_89 -> V_90 == V_32 ) {
V_76 = true ;
break;
} else if ( F_43 ( V_89 -> V_90 ) == V_32 -> V_86 ) {
V_76 = true ;
break;
}
}
#else
if ( F_51 ( V_38 ) == V_32 )
V_76 = true ;
#endif
if ( V_76 ) {
V_39 = F_52 ( V_38 ) . V_91 >= V_92 ;
return V_39 ;
}
if ( V_75 )
goto V_83;
if ( V_72 == 1 )
goto V_93;
V_35 . V_77 = V_32 -> V_86 ;
V_39 = 0 ;
if ( F_39 ( V_1 , & V_35 , & V_38 , V_94 ) == 0 ) {
if ( V_38 . type == V_43 )
V_39 = F_52 ( V_38 ) . V_91 >= V_92 ;
}
return V_39 ;
V_83:
if ( V_72 )
goto V_93;
* V_74 = 0 ;
return 0 ;
V_85:
return - V_95 ;
V_93:
return - V_96 ;
}
int F_53 ( struct V_48 * V_49 , T_3 V_69 , T_3 V_70 ,
T_4 V_64 , int V_71 , struct V_31 * V_32 ,
struct V_50 * V_73 , T_2 * V_74 )
{
int V_97 = F_54 ( V_49 ) ? 0 : F_55 ( V_73 ) ;
if ( ! V_97 && ! F_47 ( F_36 ( V_32 ) ) &&
F_46 ( V_73 ) &&
( V_32 -> V_86 != V_71 || ! F_48 ( V_73 ) ) ) {
* V_74 = 0 ;
return 0 ;
}
return F_42 ( V_49 , V_69 , V_70 , V_64 , V_71 , V_32 , V_97 , V_73 , V_74 ) ;
}
static inline T_3 F_56 ( struct V_98 * V_33 )
{
return ( (struct V_99 * ) V_33 ) -> V_100 . V_101 ;
}
static int F_57 ( struct V_102 * V_103 , int V_104 , int type , T_2 V_105 )
{
struct V_102 * V_106 ;
V_106 = (struct V_102 * ) ( ( char * ) V_103 + V_104 ) ;
V_106 -> V_107 = type ;
V_106 -> V_108 = F_58 ( 4 ) ;
* ( T_2 * ) F_59 ( V_106 ) = V_105 ;
return V_104 + F_60 ( 4 ) ;
}
static int F_61 ( struct V_1 * V_1 , int V_109 , struct V_110 * V_53 ,
struct V_111 * V_112 )
{
T_3 V_33 ;
int V_113 ;
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
V_112 -> V_114 . V_115 = V_1 ;
if ( V_53 -> V_116 . V_117 != V_118 )
return - V_119 ;
V_113 = 32 ;
V_33 = F_56 ( & V_53 -> V_116 ) ;
if ( ! ( V_53 -> V_55 & V_120 ) ) {
T_3 V_121 = F_56 ( & V_53 -> V_122 ) ;
if ( V_53 -> V_122 . V_117 != V_118 ) {
if ( V_121 || V_53 -> V_122 . V_117 )
return - V_119 ;
}
if ( F_62 ( V_121 , V_33 ) )
return - V_95 ;
V_113 = F_63 ( V_121 ) ;
}
V_112 -> V_123 = V_113 ;
V_112 -> V_124 = V_33 ;
if ( V_109 != V_125 ) {
V_112 -> V_126 = V_127 ;
V_112 -> V_128 = V_129 ;
}
if ( V_53 -> V_130 )
V_112 -> V_131 = V_53 -> V_130 - 1 ;
if ( V_53 -> V_55 & V_132 ) {
V_112 -> V_133 = V_92 ;
V_112 -> V_134 = V_135 ;
return 0 ;
}
V_112 -> V_133 = V_136 ;
V_112 -> V_134 = V_43 ;
if ( V_53 -> V_137 ) {
char * V_138 ;
struct V_31 * V_32 ;
char V_139 [ V_140 ] ;
if ( F_64 ( V_139 , V_53 -> V_137 , V_140 - 1 ) )
return - V_141 ;
V_139 [ V_140 - 1 ] = 0 ;
V_138 = strchr ( V_139 , ':' ) ;
if ( V_138 )
* V_138 = 0 ;
V_32 = F_65 ( V_1 , V_139 ) ;
if ( ! V_32 )
return - V_142 ;
V_112 -> V_143 = V_32 -> V_86 ;
V_112 -> V_144 = F_29 ( V_32 ) ;
if ( V_138 ) {
struct V_145 * V_146 ;
struct V_50 * V_51 = F_66 ( V_32 ) ;
if ( ! V_51 )
return - V_142 ;
* V_138 = ':' ;
for ( V_146 = V_51 -> V_82 ; V_146 ; V_146 = V_146 -> V_147 )
if ( strcmp ( V_146 -> V_148 , V_139 ) == 0 )
break;
if ( ! V_146 )
return - V_142 ;
V_112 -> V_149 = V_146 -> V_150 ;
}
}
V_33 = F_56 ( & V_53 -> V_151 ) ;
if ( V_53 -> V_151 . V_117 == V_118 && V_33 ) {
unsigned int V_152 ;
V_112 -> V_153 = V_33 ;
V_152 = F_26 ( V_1 , V_33 , V_112 -> V_144 ) ;
if ( V_53 -> V_55 & V_154 &&
V_152 == V_43 )
V_112 -> V_133 = V_59 ;
}
if ( V_109 == V_125 )
return 0 ;
if ( V_53 -> V_55 & V_154 && ! V_112 -> V_153 )
return - V_95 ;
if ( V_112 -> V_133 == V_136 )
V_112 -> V_133 = V_68 ;
if ( V_53 -> V_55 & ( V_155 | V_156 | V_157 ) ) {
struct V_102 * V_103 ;
int V_104 = 0 ;
V_103 = F_67 ( 3 * F_60 ( 4 ) , V_158 ) ;
if ( ! V_103 )
return - V_6 ;
if ( V_53 -> V_55 & V_155 )
V_104 = F_57 ( V_103 , V_104 , V_159 , V_53 -> V_160 - 40 ) ;
if ( V_53 -> V_55 & V_156 )
V_104 = F_57 ( V_103 , V_104 , V_161 , V_53 -> V_162 ) ;
if ( V_53 -> V_55 & V_157 )
V_104 = F_57 ( V_103 , V_104 , V_163 , V_53 -> V_164 << 3 ) ;
V_112 -> V_165 = V_103 ;
V_112 -> V_166 = V_104 ;
}
return 0 ;
}
int F_68 ( struct V_1 * V_1 , unsigned int V_109 , void T_5 * V_167 )
{
struct V_111 V_112 ;
struct V_110 V_53 ;
int V_168 ;
switch ( V_109 ) {
case V_169 :
case V_125 :
if ( ! F_69 ( V_1 -> V_170 , V_171 ) )
return - V_172 ;
if ( F_64 ( & V_53 , V_167 , sizeof( V_53 ) ) )
return - V_141 ;
F_70 () ;
V_168 = F_61 ( V_1 , V_109 , & V_53 , & V_112 ) ;
if ( V_168 == 0 ) {
struct V_2 * V_15 ;
if ( V_109 == V_125 ) {
V_15 = F_6 ( V_1 , V_112 . V_144 ) ;
if ( V_15 )
V_168 = F_71 ( V_1 , V_15 , & V_112 ,
NULL ) ;
else
V_168 = - V_173 ;
} else {
V_15 = F_5 ( V_1 , V_112 . V_144 ) ;
if ( V_15 )
V_168 = F_72 ( V_1 , V_15 ,
& V_112 , NULL ) ;
else
V_168 = - V_174 ;
}
F_73 ( V_112 . V_165 ) ;
}
F_74 () ;
return V_168 ;
}
return - V_95 ;
}
static int F_75 ( struct V_1 * V_1 , struct V_48 * V_49 ,
struct V_175 * V_176 , struct V_111 * V_112 ,
struct V_177 * V_178 )
{
struct V_102 * V_179 ;
int V_168 , V_180 ;
struct V_181 * V_182 ;
V_168 = F_76 ( V_176 , sizeof( * V_182 ) , V_183 , V_184 ,
V_178 ) ;
if ( V_168 < 0 )
goto V_185;
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
V_182 = F_77 ( V_176 ) ;
V_112 -> V_123 = V_182 -> V_186 ;
V_112 -> V_187 = V_182 -> V_188 ;
V_112 -> V_144 = V_182 -> V_189 ;
V_112 -> V_128 = V_182 -> V_190 ;
V_112 -> V_133 = V_182 -> V_191 ;
V_112 -> V_134 = V_182 -> V_192 ;
V_112 -> V_193 = V_182 -> V_194 ;
V_112 -> V_126 = V_176 -> V_195 ;
V_112 -> V_114 . V_196 = F_78 ( V_49 ) . V_196 ;
V_112 -> V_114 . V_176 = V_176 ;
V_112 -> V_114 . V_115 = V_1 ;
if ( V_112 -> V_134 > V_197 ) {
F_79 ( V_178 , L_1 ) ;
V_168 = - V_95 ;
goto V_185;
}
F_80 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_107 ( V_179 ) ) {
case V_198 :
V_112 -> V_124 = F_81 ( V_179 ) ;
break;
case V_199 :
V_112 -> V_143 = F_82 ( V_179 ) ;
break;
case V_200 :
V_112 -> V_153 = F_81 ( V_179 ) ;
break;
case V_201 :
V_112 -> V_131 = F_82 ( V_179 ) ;
break;
case V_202 :
V_112 -> V_149 = F_81 ( V_179 ) ;
break;
case V_203 :
V_112 -> V_165 = F_59 ( V_179 ) ;
V_112 -> V_166 = V_108 ( V_179 ) ;
break;
case V_204 :
V_168 = F_83 ( F_59 ( V_179 ) ,
V_108 ( V_179 ) ,
V_178 ) ;
if ( V_168 < 0 )
goto V_185;
V_112 -> V_205 = F_59 ( V_179 ) ;
V_112 -> V_206 = V_108 ( V_179 ) ;
break;
case V_207 :
V_112 -> V_208 = F_82 ( V_179 ) ;
break;
case V_209 :
V_112 -> V_144 = F_82 ( V_179 ) ;
break;
case V_210 :
V_112 -> V_211 = V_179 ;
break;
case V_212 :
V_112 -> V_213 = F_84 ( V_179 ) ;
V_168 = F_85 ( V_112 -> V_213 ,
V_178 ) ;
if ( V_168 < 0 )
goto V_185;
break;
}
}
return 0 ;
V_185:
return V_168 ;
}
static int F_86 ( struct V_48 * V_49 , struct V_175 * V_176 ,
struct V_177 * V_178 )
{
struct V_1 * V_1 = F_87 ( V_49 -> V_214 ) ;
struct V_111 V_112 ;
struct V_2 * V_15 ;
int V_168 ;
V_168 = F_75 ( V_1 , V_49 , V_176 , & V_112 , V_178 ) ;
if ( V_168 < 0 )
goto V_185;
V_15 = F_6 ( V_1 , V_112 . V_144 ) ;
if ( ! V_15 ) {
F_79 ( V_178 , L_2 ) ;
V_168 = - V_173 ;
goto V_185;
}
V_168 = F_71 ( V_1 , V_15 , & V_112 , V_178 ) ;
V_185:
return V_168 ;
}
static int F_88 ( struct V_48 * V_49 , struct V_175 * V_176 ,
struct V_177 * V_178 )
{
struct V_1 * V_1 = F_87 ( V_49 -> V_214 ) ;
struct V_111 V_112 ;
struct V_2 * V_15 ;
int V_168 ;
V_168 = F_75 ( V_1 , V_49 , V_176 , & V_112 , V_178 ) ;
if ( V_168 < 0 )
goto V_185;
V_15 = F_5 ( V_1 , V_112 . V_144 ) ;
if ( ! V_15 ) {
V_168 = - V_174 ;
goto V_185;
}
V_168 = F_72 ( V_1 , V_15 , & V_112 , V_178 ) ;
V_185:
return V_168 ;
}
static int F_89 ( struct V_48 * V_49 , struct V_215 * V_216 )
{
struct V_1 * V_1 = F_87 ( V_49 -> V_214 ) ;
unsigned int V_17 , V_217 ;
unsigned int V_218 = 0 , V_219 ;
struct V_2 * V_15 ;
struct V_23 * V_24 ;
int V_220 = 0 , V_168 ;
if ( F_90 ( V_216 -> V_176 ) >= sizeof( struct V_181 ) &&
( (struct V_181 * ) F_77 ( V_216 -> V_176 ) ) -> V_194 & V_221 )
return V_49 -> V_104 ;
V_217 = V_216 -> args [ 0 ] ;
V_219 = V_216 -> args [ 1 ] ;
F_23 () ;
for ( V_17 = V_217 ; V_17 < V_22 ; V_17 ++ , V_219 = 0 ) {
V_218 = 0 ;
V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_218 < V_219 )
goto V_222;
if ( V_220 )
memset ( & V_216 -> args [ 2 ] , 0 , sizeof( V_216 -> args ) -
2 * sizeof( V_216 -> args [ 0 ] ) ) ;
V_168 = F_91 ( V_15 , V_49 , V_216 ) ;
if ( V_168 < 0 ) {
if ( F_92 ( V_49 -> V_104 ) )
goto V_223;
goto V_224;
}
V_220 = 1 ;
V_222:
V_218 ++ ;
}
}
V_223:
V_168 = V_49 -> V_104 ;
V_224:
F_25 () ;
V_216 -> args [ 1 ] = V_218 ;
V_216 -> args [ 0 ] = V_17 ;
return V_168 ;
}
static void F_93 ( int V_109 , int type , T_3 V_70 , int V_225 , struct V_145 * V_146 )
{
struct V_1 * V_1 = F_36 ( V_146 -> V_226 -> V_32 ) ;
T_2 V_25 = F_29 ( V_146 -> V_226 -> V_32 ) ;
struct V_2 * V_15 ;
struct V_111 V_112 = {
. V_128 = V_227 ,
. V_134 = type ,
. V_124 = V_70 ,
. V_123 = V_225 ,
. V_149 = V_146 -> V_150 ,
. V_143 = V_146 -> V_226 -> V_32 -> V_86 ,
. V_126 = V_127 | V_228 ,
. V_114 = {
. V_115 = V_1 ,
} ,
} ;
if ( ! V_25 )
V_25 = ( type == V_43 ) ? V_5 : V_7 ;
V_15 = F_5 ( V_1 , V_25 ) ;
if ( ! V_15 )
return;
V_112 . V_144 = V_15 -> V_25 ;
if ( type != V_84 )
V_112 . V_133 = V_68 ;
else
V_112 . V_133 = V_92 ;
if ( V_109 == V_229 )
F_72 ( V_1 , V_15 , & V_112 , NULL ) ;
else
F_71 ( V_1 , V_15 , & V_112 , NULL ) ;
}
void F_94 ( struct V_145 * V_146 )
{
struct V_50 * V_51 = V_146 -> V_226 ;
struct V_31 * V_32 = V_51 -> V_32 ;
struct V_145 * V_230 = V_146 ;
T_3 V_121 = V_146 -> V_231 ;
T_3 V_33 = V_146 -> V_150 ;
T_3 V_232 = V_146 -> V_233 & V_121 ;
if ( V_146 -> V_234 & V_235 ) {
V_230 = F_95 ( V_51 , V_232 , V_121 ) ;
if ( ! V_230 ) {
F_96 ( L_3 , V_236 ) ;
return;
}
}
F_93 ( V_229 , V_84 , V_33 , 32 , V_230 ) ;
if ( ! ( V_32 -> V_237 & V_238 ) )
return;
if ( V_146 -> V_239 && V_146 -> V_239 != F_97 ( 0xFFFFFFFF ) )
F_93 ( V_229 , V_40 , V_146 -> V_239 , 32 , V_230 ) ;
if ( ! F_20 ( V_232 ) && ! ( V_146 -> V_234 & V_235 ) &&
( V_232 != V_33 || V_146 -> V_240 < 32 ) ) {
if ( ! ( V_146 -> V_234 & V_241 ) )
F_93 ( V_229 ,
V_32 -> V_237 & V_242 ? V_84 : V_43 ,
V_232 , V_146 -> V_240 , V_230 ) ;
if ( V_146 -> V_240 < 31 ) {
F_93 ( V_229 , V_40 , V_232 , 32 , V_230 ) ;
F_93 ( V_229 , V_40 , V_232 | ~ V_121 ,
32 , V_230 ) ;
}
}
}
void F_98 ( struct V_145 * V_146 , struct V_145 * V_243 )
{
struct V_50 * V_51 = V_146 -> V_226 ;
struct V_31 * V_32 = V_51 -> V_32 ;
struct V_145 * V_244 ;
struct V_145 * V_230 = V_146 , * V_245 = NULL ;
T_3 V_246 = V_146 -> V_233 | ~ V_146 -> V_231 ;
T_3 V_247 = V_146 -> V_233 & V_146 -> V_231 ;
#define F_99 1
#define F_100 2
#define F_101 4
#define F_102 8
unsigned int V_248 = 0 ;
int V_249 = 0 ;
int V_250 = 1 ;
int V_251 = 0 ;
if ( V_146 -> V_234 & V_235 ) {
V_230 = F_95 ( V_51 , V_247 , V_146 -> V_231 ) ;
if ( ! V_230 ) {
if ( ! V_51 -> V_252 )
F_96 ( L_3 , V_236 ) ;
return;
}
if ( V_243 && V_243 != V_230 ) {
F_96 ( L_4 , V_236 ) ;
return;
}
} else if ( ! F_20 ( V_247 ) &&
( V_247 != V_146 -> V_150 || V_146 -> V_240 < 32 ) ) {
if ( ! ( V_146 -> V_234 & V_241 ) )
F_93 ( V_253 ,
V_32 -> V_237 & V_242 ? V_84 : V_43 ,
V_247 , V_146 -> V_240 , V_230 ) ;
V_249 = 1 ;
}
if ( V_51 -> V_252 )
goto V_254;
for ( V_244 = V_51 -> V_82 ; V_244 ; V_244 = V_244 -> V_147 ) {
if ( V_244 == V_146 ) {
V_250 = 0 ;
continue;
}
if ( V_243 && V_244 -> V_231 == V_243 -> V_231 &&
F_103 ( V_244 -> V_233 , V_243 ) )
continue;
if ( V_244 -> V_234 & V_235 ) {
if ( V_244 -> V_231 == V_230 -> V_231 &&
F_103 ( V_244 -> V_233 , V_230 ) )
V_245 = V_230 ;
else {
if ( ! V_251 )
continue;
if ( ! V_245 ||
V_244 -> V_231 != V_245 -> V_231 ||
! F_103 ( V_244 -> V_233 , V_245 ) )
V_245 = F_95 ( V_51 ,
V_244 -> V_233 ,
V_244 -> V_231 ) ;
if ( ! V_245 )
continue;
if ( V_245 -> V_150 != V_230 -> V_150 )
continue;
}
} else {
if ( V_230 -> V_150 != V_244 -> V_150 )
continue;
V_245 = V_244 ;
if ( V_230 != V_245 )
V_251 = 1 ;
}
if ( V_146 -> V_150 == V_244 -> V_150 )
V_248 |= F_99 ;
if ( V_146 -> V_239 == V_244 -> V_239 )
V_248 |= F_100 ;
if ( V_246 == V_244 -> V_239 )
V_248 |= F_102 ;
if ( V_247 == V_244 -> V_239 )
V_248 |= F_101 ;
if ( V_245 == V_244 && V_244 -> V_240 < 31 ) {
T_3 V_255 = V_244 -> V_233 | ~ V_244 -> V_231 ;
T_3 V_256 = V_244 -> V_233 & V_244 -> V_231 ;
if ( ! F_20 ( V_256 ) ) {
if ( V_146 -> V_239 == V_255 ||
V_146 -> V_239 == V_256 )
V_248 |= F_100 ;
if ( V_246 == V_255 || V_246 == V_256 )
V_248 |= F_102 ;
if ( V_247 == V_255 || V_247 == V_256 )
V_248 |= F_101 ;
}
}
}
V_254:
if ( ! ( V_248 & F_100 ) )
F_93 ( V_253 , V_40 , V_146 -> V_239 , 32 , V_230 ) ;
if ( V_249 && V_146 -> V_240 < 31 ) {
if ( ! ( V_248 & F_102 ) )
F_93 ( V_253 , V_40 , V_246 , 32 , V_230 ) ;
if ( ! ( V_248 & F_101 ) )
F_93 ( V_253 , V_40 , V_247 , 32 , V_230 ) ;
}
if ( ! ( V_248 & F_99 ) ) {
unsigned int V_152 ;
F_93 ( V_253 , V_84 , V_146 -> V_150 , 32 , V_230 ) ;
V_152 = F_30 ( F_36 ( V_32 ) , V_32 ,
V_146 -> V_150 ) ;
if ( V_250 && V_152 != V_84 ) {
if ( F_104 ( V_32 , V_146 -> V_150 ) )
F_15 ( F_36 ( V_32 ) ) ;
}
}
#undef F_99
#undef F_100
#undef F_101
#undef F_102
}
static void F_105 ( struct V_1 * V_1 , struct V_257 * V_258 )
{
struct V_37 V_38 ;
struct V_34 V_35 = {
. V_66 = V_258 -> V_259 ,
. V_36 = V_258 -> V_260 ,
. V_63 = V_258 -> V_261 ,
. V_65 = V_258 -> V_262 ,
} ;
struct V_2 * V_15 ;
F_23 () ;
V_15 = F_6 ( V_1 , V_258 -> V_263 ) ;
V_258 -> V_168 = - V_264 ;
if ( V_15 ) {
F_106 () ;
V_258 -> V_25 = V_15 -> V_25 ;
V_258 -> V_168 = F_24 ( V_15 , & V_35 , & V_38 , V_44 ) ;
if ( ! V_258 -> V_168 ) {
V_258 -> V_265 = V_38 . V_265 ;
V_258 -> V_266 = V_38 . V_266 ;
V_258 -> type = V_38 . type ;
V_258 -> V_54 = V_38 . V_54 ;
}
F_107 () ;
}
F_25 () ;
}
static void F_108 ( struct V_48 * V_49 )
{
struct V_1 * V_1 ;
struct V_257 * V_258 ;
struct V_175 * V_176 ;
T_2 V_196 ;
V_1 = F_87 ( V_49 -> V_214 ) ;
V_176 = F_109 ( V_49 ) ;
if ( V_49 -> V_104 < F_110 ( sizeof( * V_258 ) ) ||
V_49 -> V_104 < V_176 -> F_90 ||
F_90 ( V_176 ) < sizeof( * V_258 ) )
return;
V_49 = F_111 ( V_49 , V_158 ) ;
if ( ! V_49 )
return;
V_176 = F_109 ( V_49 ) ;
V_258 = (struct V_257 * ) F_77 ( V_176 ) ;
F_105 ( V_1 , V_258 ) ;
V_196 = F_78 ( V_49 ) . V_196 ;
F_78 ( V_49 ) . V_196 = 0 ;
F_78 ( V_49 ) . V_267 = 0 ;
F_112 ( V_1 -> V_10 . V_268 , V_49 , V_196 , V_269 ) ;
}
static int T_1 F_113 ( struct V_1 * V_1 )
{
struct V_270 * V_214 ;
struct V_271 V_112 = {
. V_272 = F_108 ,
} ;
V_214 = F_114 ( V_1 , V_273 , & V_112 ) ;
if ( ! V_214 )
return - V_119 ;
V_1 -> V_10 . V_268 = V_214 ;
return 0 ;
}
static void F_115 ( struct V_1 * V_1 )
{
F_116 ( V_1 -> V_10 . V_268 ) ;
V_1 -> V_10 . V_268 = NULL ;
}
static void F_117 ( struct V_31 * V_32 , unsigned long V_274 ,
bool V_275 )
{
if ( F_118 ( V_32 , V_274 , V_275 ) )
F_15 ( F_36 ( V_32 ) ) ;
else
F_18 ( F_36 ( V_32 ) ) ;
F_119 ( V_32 ) ;
}
static int F_120 ( struct V_276 * V_277 , unsigned long V_274 , void * V_278 )
{
struct V_145 * V_146 = (struct V_145 * ) V_278 ;
struct V_31 * V_32 = V_146 -> V_226 -> V_32 ;
struct V_1 * V_1 = F_36 ( V_32 ) ;
switch ( V_274 ) {
case V_279 :
F_94 ( V_146 ) ;
#ifdef F_50
F_121 ( V_32 , V_280 ) ;
#endif
F_122 ( & V_1 -> V_10 . V_281 ) ;
F_18 ( F_36 ( V_32 ) ) ;
break;
case V_282 :
F_98 ( V_146 , NULL ) ;
F_122 ( & V_1 -> V_10 . V_281 ) ;
if ( ! V_146 -> V_226 -> V_82 ) {
F_117 ( V_32 , V_274 , true ) ;
} else {
F_18 ( F_36 ( V_32 ) ) ;
}
break;
}
return V_283 ;
}
static int F_123 ( struct V_276 * V_277 , unsigned long V_274 , void * V_278 )
{
struct V_31 * V_32 = F_124 ( V_278 ) ;
struct V_284 * V_285 ;
struct V_50 * V_51 ;
struct V_1 * V_1 = F_36 ( V_32 ) ;
unsigned int V_237 ;
if ( V_274 == V_286 ) {
F_117 ( V_32 , V_274 , true ) ;
F_125 ( V_32 ) ;
return V_283 ;
}
V_51 = F_66 ( V_32 ) ;
if ( ! V_51 )
return V_283 ;
switch ( V_274 ) {
case V_279 :
F_126 (in_dev) {
F_94 ( V_146 ) ;
} F_127 ( V_51 ) ;
#ifdef F_50
F_121 ( V_32 , V_280 ) ;
#endif
F_122 ( & V_1 -> V_10 . V_281 ) ;
F_18 ( V_1 ) ;
break;
case V_282 :
F_117 ( V_32 , V_274 , false ) ;
break;
case V_287 :
V_237 = F_128 ( V_32 ) ;
if ( V_237 & ( V_288 | V_289 ) )
F_121 ( V_32 , V_290 ) ;
else
F_118 ( V_32 , V_274 , false ) ;
case V_291 :
F_18 ( V_1 ) ;
break;
case V_292 :
V_285 = V_278 ;
if ( V_285 -> V_293 && F_129 ( V_285 -> V_293 ) )
F_117 ( V_32 , V_282 , true ) ;
break;
}
return V_283 ;
}
static int T_1 F_130 ( struct V_1 * V_1 )
{
int V_168 ;
T_6 V_294 = sizeof( struct V_23 ) * V_22 ;
V_1 -> V_10 . V_295 = 0 ;
V_294 = F_131 ( T_6 , V_294 , V_296 ) ;
V_1 -> V_10 . V_11 = F_67 ( V_294 , V_158 ) ;
if ( ! V_1 -> V_10 . V_11 )
return - V_6 ;
V_168 = F_1 ( V_1 ) ;
if ( V_168 < 0 )
goto V_8;
return 0 ;
V_8:
F_73 ( V_1 -> V_10 . V_11 ) ;
return V_168 ;
}
static void F_132 ( struct V_1 * V_1 )
{
unsigned int V_297 ;
F_70 () ;
#ifdef F_10
F_133 ( V_1 -> V_10 . V_19 , NULL ) ;
F_133 ( V_1 -> V_10 . V_21 , NULL ) ;
#endif
for ( V_297 = 0 ; V_297 < V_22 ; V_297 ++ ) {
struct V_23 * V_24 = & V_1 -> V_10 . V_11 [ V_297 ] ;
struct V_29 * V_30 ;
struct V_2 * V_15 ;
F_16 (tb, tmp, head, tb_hlist) {
F_134 ( & V_15 -> V_9 ) ;
F_17 ( V_1 , V_15 ) ;
F_4 ( V_15 ) ;
}
}
#ifdef F_10
F_135 ( V_1 ) ;
#endif
F_74 () ;
F_73 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_136 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_137
V_1 -> V_10 . F_47 = 0 ;
#endif
error = F_130 ( V_1 ) ;
if ( error < 0 )
goto V_223;
error = F_113 ( V_1 ) ;
if ( error < 0 )
goto V_298;
error = F_138 ( V_1 ) ;
if ( error < 0 )
goto V_299;
V_223:
return error ;
V_299:
F_115 ( V_1 ) ;
V_298:
F_132 ( V_1 ) ;
goto V_223;
}
static void T_7 F_139 ( struct V_1 * V_1 )
{
F_140 ( V_1 ) ;
F_115 ( V_1 ) ;
F_132 ( V_1 ) ;
}
void T_8 F_141 ( void )
{
F_142 () ;
F_143 ( & V_300 ) ;
F_144 ( & V_301 ) ;
F_145 ( & V_302 ) ;
F_146 ( V_303 , V_229 , F_88 , NULL , NULL ) ;
F_146 ( V_303 , V_253 , F_86 , NULL , NULL ) ;
F_146 ( V_303 , V_304 , NULL , F_89 , NULL ) ;
}
