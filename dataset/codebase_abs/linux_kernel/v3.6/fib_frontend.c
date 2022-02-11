static int T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 , * V_4 ;
V_3 = F_2 ( V_5 ) ;
if ( V_3 == NULL )
return - V_6 ;
V_4 = F_2 ( V_7 ) ;
if ( V_4 == NULL )
goto V_8;
F_3 ( & V_3 -> V_9 ,
& V_1 -> V_10 . V_11 [ V_12 ] ) ;
F_3 ( & V_4 -> V_9 ,
& V_1 -> V_10 . V_11 [ V_13 ] ) ;
return 0 ;
V_8:
F_4 ( V_3 ) ;
return - V_6 ;
}
struct V_2 * F_5 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_15 ;
unsigned int V_16 ;
if ( V_14 == 0 )
V_14 = V_7 ;
V_15 = F_6 ( V_1 , V_14 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_2 ( V_14 ) ;
if ( ! V_15 )
return NULL ;
switch ( V_14 ) {
case V_5 :
V_1 -> V_10 . V_17 = V_15 ;
break;
case V_7 :
V_1 -> V_10 . V_18 = V_15 ;
break;
case V_19 :
V_1 -> V_10 . V_20 = V_15 ;
break;
default:
break;
}
V_16 = V_14 & ( V_21 - 1 ) ;
F_3 ( & V_15 -> V_9 , & V_1 -> V_10 . V_11 [ V_16 ] ) ;
return V_15 ;
}
struct V_2 * F_6 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_15 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_16 ;
if ( V_14 == 0 )
V_14 = V_7 ;
V_16 = V_14 & ( V_21 - 1 ) ;
F_7 () ;
V_25 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_8 (tb, node, head, tb_hlist) {
if ( V_15 -> V_26 == V_14 ) {
F_9 () ;
return V_15 ;
}
}
F_9 () ;
return NULL ;
}
static void F_10 ( struct V_1 * V_1 )
{
int V_27 = 0 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ ) {
V_25 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_11 (tb, node, head, tb_hlist)
V_27 += F_12 ( V_15 ) ;
}
if ( V_27 )
F_13 ( V_1 ) ;
}
static inline unsigned int F_14 ( struct V_1 * V_1 ,
const struct V_28 * V_29 ,
T_3 V_30 )
{
struct V_31 V_32 = { . V_33 = V_30 } ;
struct V_34 V_35 ;
unsigned int V_36 = V_37 ;
struct V_2 * V_3 ;
if ( F_15 ( V_30 ) || F_16 ( V_30 ) )
return V_37 ;
if ( F_17 ( V_30 ) )
return V_38 ;
V_3 = F_6 ( V_1 , V_5 ) ;
if ( V_3 ) {
V_36 = V_39 ;
F_7 () ;
if ( ! F_18 ( V_3 , & V_32 , & V_35 , V_40 ) ) {
if ( ! V_29 || V_29 == V_35 . V_41 -> V_42 )
V_36 = V_35 . type ;
}
F_9 () ;
}
return V_36 ;
}
unsigned int F_19 ( struct V_1 * V_1 , T_3 V_30 )
{
return F_14 ( V_1 , NULL , V_30 ) ;
}
unsigned int F_20 ( struct V_1 * V_1 , const struct V_28 * V_29 ,
T_3 V_30 )
{
return F_14 ( V_1 , V_29 , V_30 ) ;
}
T_3 F_21 ( struct V_43 * V_44 )
{
struct V_28 * V_29 = V_44 -> V_29 ;
struct V_45 * V_46 ;
struct V_34 V_35 ;
struct V_47 * V_48 ;
struct V_31 V_32 ;
struct V_1 * V_1 ;
int V_49 ;
V_48 = F_22 ( V_44 ) ;
if ( ( V_48 -> V_50 & ( V_51 | V_52 | V_53 ) ) ==
V_53 )
return F_23 ( V_44 ) -> V_33 ;
V_46 = F_24 ( V_29 ) ;
F_25 ( ! V_46 ) ;
V_1 = F_26 ( V_29 ) ;
V_49 = V_54 ;
if ( ! F_15 ( F_23 ( V_44 ) -> V_55 ) ) {
V_32 . V_56 = 0 ;
V_32 . V_57 = V_1 -> V_58 -> V_59 ;
V_32 . V_33 = F_23 ( V_44 ) -> V_55 ;
V_32 . V_55 = 0 ;
V_32 . V_60 = F_27 ( F_23 ( V_44 ) -> V_61 ) ;
V_32 . V_62 = V_49 ;
V_32 . V_63 = F_28 ( V_46 ) ? V_44 -> V_64 : 0 ;
if ( ! F_29 ( V_1 , & V_32 , & V_35 ) )
return F_30 ( V_1 , V_35 ) ;
} else {
V_49 = V_65 ;
}
return F_31 ( V_29 , F_23 ( V_44 ) -> V_55 , V_49 ) ;
}
static int F_32 ( struct V_43 * V_44 , T_3 V_66 , T_3 V_67 ,
T_4 V_61 , int V_68 , struct V_28 * V_29 ,
int V_69 , struct V_45 * V_70 , T_2 * V_71 )
{
int V_36 , V_72 , V_73 ;
struct V_34 V_35 ;
struct V_31 V_32 ;
struct V_1 * V_1 ;
bool V_74 ;
V_32 . V_56 = 0 ;
V_32 . V_57 = V_68 ;
V_32 . V_33 = V_66 ;
V_32 . V_55 = V_67 ;
V_32 . V_60 = V_61 ;
V_32 . V_62 = V_54 ;
V_72 = V_70 -> V_75 == NULL ;
V_73 = F_33 ( V_70 ) ;
V_32 . V_63 = F_28 ( V_70 ) ? V_44 -> V_64 : 0 ;
V_1 = F_26 ( V_29 ) ;
if ( F_29 ( V_1 , & V_32 , & V_35 ) )
goto V_76;
if ( V_35 . type != V_39 ) {
if ( V_35 . type != V_77 || ! V_73 )
goto V_78;
}
F_34 ( V_71 , & V_35 ) ;
V_74 = false ;
#ifdef F_35
for ( V_36 = 0 ; V_36 < V_35 . V_41 -> V_79 ; V_36 ++ ) {
struct V_80 * V_81 = & V_35 . V_41 -> V_80 [ V_36 ] ;
if ( V_81 -> V_82 == V_29 ) {
V_74 = true ;
break;
}
}
#else
if ( F_36 ( V_35 ) == V_29 )
V_74 = true ;
#endif
if ( V_74 ) {
V_36 = F_37 ( V_35 ) . V_83 >= V_84 ;
return V_36 ;
}
if ( V_72 )
goto V_76;
if ( V_69 == 1 )
goto V_85;
V_32 . V_56 = V_29 -> V_59 ;
V_36 = 0 ;
if ( F_29 ( V_1 , & V_32 , & V_35 ) == 0 ) {
if ( V_35 . type == V_39 )
V_36 = F_37 ( V_35 ) . V_83 >= V_84 ;
}
return V_36 ;
V_76:
if ( V_69 )
goto V_85;
* V_71 = 0 ;
return 0 ;
V_78:
return - V_86 ;
V_85:
return - V_87 ;
}
int F_38 ( struct V_43 * V_44 , T_3 V_66 , T_3 V_67 ,
T_4 V_61 , int V_68 , struct V_28 * V_29 ,
struct V_45 * V_70 , T_2 * V_71 )
{
int V_88 = F_39 ( V_44 ) ? 0 : F_40 ( V_70 ) ;
if ( ! V_88 && ! F_41 ( F_26 ( V_29 ) ) ) {
* V_71 = 0 ;
return 0 ;
}
return F_32 ( V_44 , V_66 , V_67 , V_61 , V_68 , V_29 , V_88 , V_70 , V_71 ) ;
}
static inline T_3 F_42 ( struct V_89 * V_30 )
{
return ( (struct V_90 * ) V_30 ) -> V_91 . V_92 ;
}
static int F_43 ( struct V_93 * V_94 , int V_95 , int type , T_2 V_96 )
{
struct V_93 * V_97 ;
V_97 = (struct V_93 * ) ( ( char * ) V_94 + V_95 ) ;
V_97 -> V_98 = type ;
V_97 -> V_99 = F_44 ( 4 ) ;
* ( T_2 * ) F_45 ( V_97 ) = V_96 ;
return V_95 + F_46 ( 4 ) ;
}
static int F_47 ( struct V_1 * V_1 , int V_100 , struct V_101 * V_48 ,
struct V_102 * V_103 )
{
T_3 V_30 ;
int V_104 ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_103 -> V_105 . V_106 = V_1 ;
if ( V_48 -> V_107 . V_108 != V_109 )
return - V_110 ;
V_104 = 32 ;
V_30 = F_42 ( & V_48 -> V_107 ) ;
if ( ! ( V_48 -> V_50 & V_111 ) ) {
T_3 V_112 = F_42 ( & V_48 -> V_113 ) ;
if ( V_48 -> V_113 . V_108 != V_109 ) {
if ( V_112 || V_48 -> V_113 . V_108 )
return - V_110 ;
}
if ( F_48 ( V_112 , V_30 ) )
return - V_86 ;
V_104 = F_49 ( V_112 ) ;
}
V_103 -> V_114 = V_104 ;
V_103 -> V_115 = V_30 ;
if ( V_100 != V_116 ) {
V_103 -> V_117 = V_118 ;
V_103 -> V_119 = V_120 ;
}
if ( V_48 -> V_121 )
V_103 -> V_122 = V_48 -> V_121 - 1 ;
if ( V_48 -> V_50 & V_123 ) {
V_103 -> V_124 = V_84 ;
V_103 -> V_125 = V_126 ;
return 0 ;
}
V_103 -> V_124 = V_127 ;
V_103 -> V_125 = V_39 ;
if ( V_48 -> V_128 ) {
char * V_129 ;
struct V_28 * V_29 ;
char V_130 [ V_131 ] ;
if ( F_50 ( V_130 , V_48 -> V_128 , V_131 - 1 ) )
return - V_132 ;
V_130 [ V_131 - 1 ] = 0 ;
V_129 = strchr ( V_130 , ':' ) ;
if ( V_129 )
* V_129 = 0 ;
V_29 = F_51 ( V_1 , V_130 ) ;
if ( ! V_29 )
return - V_133 ;
V_103 -> V_134 = V_29 -> V_59 ;
if ( V_129 ) {
struct V_135 * V_136 ;
struct V_45 * V_46 = F_52 ( V_29 ) ;
if ( ! V_46 )
return - V_133 ;
* V_129 = ':' ;
for ( V_136 = V_46 -> V_75 ; V_136 ; V_136 = V_136 -> V_137 )
if ( strcmp ( V_136 -> V_138 , V_130 ) == 0 )
break;
if ( V_136 == NULL )
return - V_133 ;
V_103 -> V_139 = V_136 -> V_140 ;
}
}
V_30 = F_42 ( & V_48 -> V_141 ) ;
if ( V_48 -> V_141 . V_108 == V_109 && V_30 ) {
V_103 -> V_142 = V_30 ;
if ( V_48 -> V_50 & V_143 &&
F_19 ( V_1 , V_30 ) == V_39 )
V_103 -> V_124 = V_54 ;
}
if ( V_100 == V_116 )
return 0 ;
if ( V_48 -> V_50 & V_143 && ! V_103 -> V_142 )
return - V_86 ;
if ( V_103 -> V_124 == V_127 )
V_103 -> V_124 = V_65 ;
if ( V_48 -> V_50 & ( V_144 | V_145 | V_146 ) ) {
struct V_93 * V_94 ;
int V_95 = 0 ;
V_94 = F_53 ( 3 * F_46 ( 4 ) , V_147 ) ;
if ( V_94 == NULL )
return - V_6 ;
if ( V_48 -> V_50 & V_144 )
V_95 = F_43 ( V_94 , V_95 , V_148 , V_48 -> V_149 - 40 ) ;
if ( V_48 -> V_50 & V_145 )
V_95 = F_43 ( V_94 , V_95 , V_150 , V_48 -> V_151 ) ;
if ( V_48 -> V_50 & V_146 )
V_95 = F_43 ( V_94 , V_95 , V_152 , V_48 -> V_153 << 3 ) ;
V_103 -> V_154 = V_94 ;
V_103 -> V_155 = V_95 ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_1 , unsigned int V_100 , void T_5 * V_156 )
{
struct V_102 V_103 ;
struct V_101 V_48 ;
int V_157 ;
switch ( V_100 ) {
case V_158 :
case V_116 :
if ( ! F_55 ( V_159 ) )
return - V_160 ;
if ( F_50 ( & V_48 , V_156 , sizeof( V_48 ) ) )
return - V_132 ;
F_56 () ;
V_157 = F_47 ( V_1 , V_100 , & V_48 , & V_103 ) ;
if ( V_157 == 0 ) {
struct V_2 * V_15 ;
if ( V_100 == V_116 ) {
V_15 = F_6 ( V_1 , V_103 . V_161 ) ;
if ( V_15 )
V_157 = F_57 ( V_15 , & V_103 ) ;
else
V_157 = - V_162 ;
} else {
V_15 = F_5 ( V_1 , V_103 . V_161 ) ;
if ( V_15 )
V_157 = F_58 ( V_15 , & V_103 ) ;
else
V_157 = - V_163 ;
}
F_4 ( V_103 . V_154 ) ;
}
F_59 () ;
return V_157 ;
}
return - V_86 ;
}
static int F_60 ( struct V_1 * V_1 , struct V_43 * V_44 ,
struct V_164 * V_165 , struct V_102 * V_103 )
{
struct V_93 * V_166 ;
int V_157 , V_167 ;
struct V_168 * V_169 ;
V_157 = F_61 ( V_165 , sizeof( * V_169 ) , V_170 , V_171 ) ;
if ( V_157 < 0 )
goto V_172;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_169 = F_62 ( V_165 ) ;
V_103 -> V_114 = V_169 -> V_173 ;
V_103 -> V_174 = V_169 -> V_175 ;
V_103 -> V_161 = V_169 -> V_176 ;
V_103 -> V_119 = V_169 -> V_177 ;
V_103 -> V_124 = V_169 -> V_178 ;
V_103 -> V_125 = V_169 -> V_179 ;
V_103 -> V_180 = V_169 -> V_181 ;
V_103 -> V_117 = V_165 -> V_182 ;
V_103 -> V_105 . V_183 = F_63 ( V_44 ) . V_183 ;
V_103 -> V_105 . V_165 = V_165 ;
V_103 -> V_105 . V_106 = V_1 ;
if ( V_103 -> V_125 > V_184 ) {
V_157 = - V_86 ;
goto V_172;
}
F_64 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_98 ( V_166 ) ) {
case V_185 :
V_103 -> V_115 = F_65 ( V_166 ) ;
break;
case V_186 :
V_103 -> V_134 = F_66 ( V_166 ) ;
break;
case V_187 :
V_103 -> V_142 = F_65 ( V_166 ) ;
break;
case V_188 :
V_103 -> V_122 = F_66 ( V_166 ) ;
break;
case V_189 :
V_103 -> V_139 = F_65 ( V_166 ) ;
break;
case V_190 :
V_103 -> V_154 = F_45 ( V_166 ) ;
V_103 -> V_155 = V_99 ( V_166 ) ;
break;
case V_191 :
V_103 -> V_192 = F_45 ( V_166 ) ;
V_103 -> V_193 = V_99 ( V_166 ) ;
break;
case V_194 :
V_103 -> V_195 = F_66 ( V_166 ) ;
break;
case V_196 :
V_103 -> V_161 = F_66 ( V_166 ) ;
break;
}
}
return 0 ;
V_172:
return V_157 ;
}
static int F_67 ( struct V_43 * V_44 , struct V_164 * V_165 , void * V_156 )
{
struct V_1 * V_1 = F_68 ( V_44 -> V_197 ) ;
struct V_102 V_103 ;
struct V_2 * V_15 ;
int V_157 ;
V_157 = F_60 ( V_1 , V_44 , V_165 , & V_103 ) ;
if ( V_157 < 0 )
goto V_172;
V_15 = F_6 ( V_1 , V_103 . V_161 ) ;
if ( V_15 == NULL ) {
V_157 = - V_162 ;
goto V_172;
}
V_157 = F_57 ( V_15 , & V_103 ) ;
V_172:
return V_157 ;
}
static int F_69 ( struct V_43 * V_44 , struct V_164 * V_165 , void * V_156 )
{
struct V_1 * V_1 = F_68 ( V_44 -> V_197 ) ;
struct V_102 V_103 ;
struct V_2 * V_15 ;
int V_157 ;
V_157 = F_60 ( V_1 , V_44 , V_165 , & V_103 ) ;
if ( V_157 < 0 )
goto V_172;
V_15 = F_5 ( V_1 , V_103 . V_161 ) ;
if ( V_15 == NULL ) {
V_157 = - V_163 ;
goto V_172;
}
V_157 = F_58 ( V_15 , & V_103 ) ;
V_172:
return V_157 ;
}
static int F_70 ( struct V_43 * V_44 , struct V_198 * V_199 )
{
struct V_1 * V_1 = F_68 ( V_44 -> V_197 ) ;
unsigned int V_16 , V_200 ;
unsigned int V_201 = 0 , V_202 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_203 = 0 ;
if ( F_71 ( V_199 -> V_165 ) >= sizeof( struct V_168 ) &&
( (struct V_168 * ) F_62 ( V_199 -> V_165 ) ) -> V_181 & V_204 )
return F_72 ( V_44 , V_199 ) ;
V_200 = V_199 -> args [ 0 ] ;
V_202 = V_199 -> args [ 1 ] ;
for ( V_16 = V_200 ; V_16 < V_21 ; V_16 ++ , V_202 = 0 ) {
V_201 = 0 ;
V_25 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_11 (tb, node, head, tb_hlist) {
if ( V_201 < V_202 )
goto V_205;
if ( V_203 )
memset ( & V_199 -> args [ 2 ] , 0 , sizeof( V_199 -> args ) -
2 * sizeof( V_199 -> args [ 0 ] ) ) ;
if ( F_73 ( V_15 , V_44 , V_199 ) < 0 )
goto V_206;
V_203 = 1 ;
V_205:
V_201 ++ ;
}
}
V_206:
V_199 -> args [ 1 ] = V_201 ;
V_199 -> args [ 0 ] = V_16 ;
return V_44 -> V_95 ;
}
static void F_74 ( int V_100 , int type , T_3 V_67 , int V_207 , struct V_135 * V_136 )
{
struct V_1 * V_1 = F_26 ( V_136 -> V_208 -> V_29 ) ;
struct V_2 * V_15 ;
struct V_102 V_103 = {
. V_119 = V_209 ,
. V_125 = type ,
. V_115 = V_67 ,
. V_114 = V_207 ,
. V_139 = V_136 -> V_140 ,
. V_134 = V_136 -> V_208 -> V_29 -> V_59 ,
. V_117 = V_118 | V_210 ,
. V_105 = {
. V_106 = V_1 ,
} ,
} ;
if ( type == V_39 )
V_15 = F_5 ( V_1 , V_7 ) ;
else
V_15 = F_5 ( V_1 , V_5 ) ;
if ( V_15 == NULL )
return;
V_103 . V_161 = V_15 -> V_26 ;
if ( type != V_77 )
V_103 . V_124 = V_65 ;
else
V_103 . V_124 = V_84 ;
if ( V_100 == V_211 )
F_58 ( V_15 , & V_103 ) ;
else
F_57 ( V_15 , & V_103 ) ;
}
void F_75 ( struct V_135 * V_136 )
{
struct V_45 * V_46 = V_136 -> V_208 ;
struct V_28 * V_29 = V_46 -> V_29 ;
struct V_135 * V_212 = V_136 ;
T_3 V_112 = V_136 -> V_213 ;
T_3 V_30 = V_136 -> V_140 ;
T_3 V_214 = V_136 -> V_215 & V_112 ;
if ( V_136 -> V_216 & V_217 ) {
V_212 = F_76 ( V_46 , V_214 , V_112 ) ;
if ( V_212 == NULL ) {
F_77 ( L_1 , V_218 ) ;
return;
}
}
F_74 ( V_211 , V_77 , V_30 , 32 , V_212 ) ;
if ( ! ( V_29 -> V_219 & V_220 ) )
return;
if ( V_136 -> V_221 && V_136 -> V_221 != F_78 ( 0xFFFFFFFF ) )
F_74 ( V_211 , V_37 , V_136 -> V_221 , 32 , V_212 ) ;
if ( ! F_15 ( V_214 ) && ! ( V_136 -> V_216 & V_217 ) &&
( V_214 != V_30 || V_136 -> V_222 < 32 ) ) {
F_74 ( V_211 ,
V_29 -> V_219 & V_223 ? V_77 : V_39 ,
V_214 , V_136 -> V_222 , V_212 ) ;
if ( V_136 -> V_222 < 31 ) {
F_74 ( V_211 , V_37 , V_214 , 32 , V_212 ) ;
F_74 ( V_211 , V_37 , V_214 | ~ V_112 ,
32 , V_212 ) ;
}
}
}
void F_79 ( struct V_135 * V_136 , struct V_135 * V_224 )
{
struct V_45 * V_46 = V_136 -> V_208 ;
struct V_28 * V_29 = V_46 -> V_29 ;
struct V_135 * V_225 ;
struct V_135 * V_212 = V_136 , * V_226 = NULL ;
T_3 V_227 = V_136 -> V_215 | ~ V_136 -> V_213 ;
T_3 V_228 = V_136 -> V_215 & V_136 -> V_213 ;
#define F_80 1
#define F_81 2
#define F_82 4
#define F_83 8
unsigned int V_229 = 0 ;
int V_230 = 0 ;
int V_231 = 1 ;
int V_232 = 0 ;
if ( V_136 -> V_216 & V_217 ) {
V_212 = F_76 ( V_46 , V_228 , V_136 -> V_213 ) ;
if ( V_212 == NULL ) {
F_77 ( L_1 , V_218 ) ;
return;
}
if ( V_224 && V_224 != V_212 ) {
F_77 ( L_2 , V_218 ) ;
return;
}
} else if ( ! F_15 ( V_228 ) &&
( V_228 != V_136 -> V_140 || V_136 -> V_222 < 32 ) ) {
F_74 ( V_233 ,
V_29 -> V_219 & V_223 ? V_77 : V_39 ,
V_228 , V_136 -> V_222 , V_212 ) ;
V_230 = 1 ;
}
for ( V_225 = V_46 -> V_75 ; V_225 ; V_225 = V_225 -> V_137 ) {
if ( V_225 == V_136 ) {
V_231 = 0 ;
continue;
}
if ( V_224 && V_225 -> V_213 == V_224 -> V_213 &&
F_84 ( V_225 -> V_215 , V_224 ) )
continue;
if ( V_225 -> V_216 & V_217 ) {
if ( V_225 -> V_213 == V_212 -> V_213 &&
F_84 ( V_225 -> V_215 , V_212 ) )
V_226 = V_212 ;
else {
if ( ! V_232 )
continue;
if ( ! V_226 ||
V_225 -> V_213 != V_226 -> V_213 ||
! F_84 ( V_225 -> V_215 , V_226 ) )
V_226 = F_76 ( V_46 ,
V_225 -> V_215 ,
V_225 -> V_213 ) ;
if ( ! V_226 )
continue;
if ( V_226 -> V_140 != V_212 -> V_140 )
continue;
}
} else {
if ( V_212 -> V_140 != V_225 -> V_140 )
continue;
V_226 = V_225 ;
if ( V_212 != V_226 )
V_232 = 1 ;
}
if ( V_136 -> V_140 == V_225 -> V_140 )
V_229 |= F_80 ;
if ( V_136 -> V_221 == V_225 -> V_221 )
V_229 |= F_81 ;
if ( V_227 == V_225 -> V_221 )
V_229 |= F_83 ;
if ( V_228 == V_225 -> V_221 )
V_229 |= F_82 ;
if ( V_226 == V_225 && V_225 -> V_222 < 31 ) {
T_3 V_234 = V_225 -> V_215 | ~ V_225 -> V_213 ;
T_3 V_235 = V_225 -> V_215 & V_225 -> V_213 ;
if ( ! F_15 ( V_235 ) ) {
if ( V_136 -> V_221 == V_234 ||
V_136 -> V_221 == V_235 )
V_229 |= F_81 ;
if ( V_227 == V_234 || V_227 == V_235 )
V_229 |= F_83 ;
if ( V_228 == V_234 || V_228 == V_235 )
V_229 |= F_82 ;
}
}
}
if ( ! ( V_229 & F_81 ) )
F_74 ( V_233 , V_37 , V_136 -> V_221 , 32 , V_212 ) ;
if ( V_230 && V_136 -> V_222 < 31 ) {
if ( ! ( V_229 & F_83 ) )
F_74 ( V_233 , V_37 , V_227 , 32 , V_212 ) ;
if ( ! ( V_229 & F_82 ) )
F_74 ( V_233 , V_37 , V_228 , 32 , V_212 ) ;
}
if ( ! ( V_229 & F_80 ) ) {
F_74 ( V_233 , V_77 , V_136 -> V_140 , 32 , V_212 ) ;
if ( V_231 &&
F_19 ( F_26 ( V_29 ) , V_136 -> V_140 ) != V_77 ) {
if ( F_85 ( F_26 ( V_29 ) , V_136 -> V_140 ) )
F_10 ( F_26 ( V_29 ) ) ;
}
}
#undef F_80
#undef F_81
#undef F_82
#undef F_83
}
static void F_86 ( struct V_236 * V_237 , struct V_2 * V_15 )
{
struct V_34 V_35 ;
struct V_31 V_32 = {
. V_63 = V_237 -> V_238 ,
. V_33 = V_237 -> V_239 ,
. V_60 = V_237 -> V_240 ,
. V_62 = V_237 -> V_241 ,
} ;
V_237 -> V_157 = - V_242 ;
if ( V_15 ) {
F_87 () ;
V_237 -> V_26 = V_15 -> V_26 ;
F_7 () ;
V_237 -> V_157 = F_18 ( V_15 , & V_32 , & V_35 , V_40 ) ;
if ( ! V_237 -> V_157 ) {
V_237 -> V_243 = V_35 . V_243 ;
V_237 -> V_244 = V_35 . V_244 ;
V_237 -> type = V_35 . type ;
V_237 -> V_49 = V_35 . V_49 ;
}
F_9 () ;
F_88 () ;
}
}
static void F_89 ( struct V_43 * V_44 )
{
struct V_1 * V_1 ;
struct V_236 * V_237 ;
struct V_164 * V_165 ;
struct V_2 * V_15 ;
T_2 V_183 ;
V_1 = F_68 ( V_44 -> V_197 ) ;
V_165 = F_90 ( V_44 ) ;
if ( V_44 -> V_95 < F_91 ( 0 ) || V_44 -> V_95 < V_165 -> F_71 ||
V_165 -> F_71 < F_92 ( sizeof( * V_237 ) ) )
return;
V_44 = F_93 ( V_44 , V_147 ) ;
if ( V_44 == NULL )
return;
V_165 = F_90 ( V_44 ) ;
V_237 = (struct V_236 * ) F_94 ( V_165 ) ;
V_15 = F_6 ( V_1 , V_237 -> V_245 ) ;
F_86 ( V_237 , V_15 ) ;
V_183 = F_63 ( V_44 ) . V_183 ;
F_63 ( V_44 ) . V_183 = 0 ;
F_63 ( V_44 ) . V_246 = 0 ;
F_95 ( V_1 -> V_10 . V_247 , V_44 , V_183 , V_248 ) ;
}
static int T_1 F_96 ( struct V_1 * V_1 )
{
struct V_249 * V_197 ;
struct V_250 V_103 = {
. V_251 = F_89 ,
} ;
V_197 = F_97 ( V_1 , V_252 , V_253 , & V_103 ) ;
if ( V_197 == NULL )
return - V_110 ;
V_1 -> V_10 . V_247 = V_197 ;
return 0 ;
}
static void F_98 ( struct V_1 * V_1 )
{
F_99 ( V_1 -> V_10 . V_247 ) ;
V_1 -> V_10 . V_247 = NULL ;
}
static void F_100 ( struct V_28 * V_29 , int V_254 )
{
if ( F_101 ( V_29 , V_254 ) )
F_10 ( F_26 ( V_29 ) ) ;
F_13 ( F_26 ( V_29 ) ) ;
F_102 ( V_29 ) ;
}
static int F_103 ( struct V_255 * V_256 , unsigned long V_257 , void * V_258 )
{
struct V_135 * V_136 = (struct V_135 * ) V_258 ;
struct V_28 * V_29 = V_136 -> V_208 -> V_29 ;
struct V_1 * V_1 = F_26 ( V_29 ) ;
switch ( V_257 ) {
case V_259 :
F_75 ( V_136 ) ;
#ifdef F_35
F_104 ( V_29 ) ;
#endif
F_105 ( & V_1 -> V_10 . V_260 ) ;
F_13 ( F_26 ( V_29 ) ) ;
break;
case V_261 :
F_79 ( V_136 , NULL ) ;
F_105 ( & V_1 -> V_10 . V_260 ) ;
if ( V_136 -> V_208 -> V_75 == NULL ) {
F_100 ( V_29 , 1 ) ;
} else {
F_13 ( F_26 ( V_29 ) ) ;
}
break;
}
return V_262 ;
}
static int F_106 ( struct V_255 * V_256 , unsigned long V_257 , void * V_258 )
{
struct V_28 * V_29 = V_258 ;
struct V_45 * V_46 = F_52 ( V_29 ) ;
struct V_1 * V_1 = F_26 ( V_29 ) ;
if ( V_257 == V_263 ) {
F_100 ( V_29 , 2 ) ;
F_107 ( V_29 ) ;
return V_262 ;
}
if ( ! V_46 )
return V_262 ;
switch ( V_257 ) {
case V_259 :
F_108 (in_dev) {
F_75 ( V_136 ) ;
} F_109 ( V_46 ) ;
#ifdef F_35
F_104 ( V_29 ) ;
#endif
F_105 ( & V_1 -> V_10 . V_260 ) ;
F_13 ( F_26 ( V_29 ) ) ;
break;
case V_261 :
F_100 ( V_29 , 0 ) ;
break;
case V_264 :
case V_265 :
F_13 ( F_26 ( V_29 ) ) ;
break;
case V_266 :
break;
}
return V_262 ;
}
static int T_1 F_110 ( struct V_1 * V_1 )
{
int V_157 ;
T_6 V_267 = sizeof( struct V_24 ) * V_21 ;
V_267 = F_111 ( T_6 , V_267 , V_268 ) ;
V_1 -> V_10 . V_11 = F_53 ( V_267 , V_147 ) ;
if ( V_1 -> V_10 . V_11 == NULL )
return - V_6 ;
V_157 = F_1 ( V_1 ) ;
if ( V_157 < 0 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_1 -> V_10 . V_11 ) ;
return V_157 ;
}
static void F_112 ( struct V_1 * V_1 )
{
unsigned int V_269 ;
#ifdef F_113
F_114 ( V_1 ) ;
#endif
F_56 () ;
for ( V_269 = 0 ; V_269 < V_21 ; V_269 ++ ) {
struct V_2 * V_15 ;
struct V_24 * V_25 ;
struct V_22 * V_23 , * V_270 ;
V_25 = & V_1 -> V_10 . V_11 [ V_269 ] ;
F_115 (tb, node, tmp, head, tb_hlist) {
F_116 ( V_23 ) ;
F_12 ( V_15 ) ;
F_117 ( V_15 ) ;
}
}
F_59 () ;
F_4 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_118 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_119
V_1 -> V_10 . F_41 = 0 ;
#endif
error = F_110 ( V_1 ) ;
if ( error < 0 )
goto V_206;
error = F_96 ( V_1 ) ;
if ( error < 0 )
goto V_271;
error = F_120 ( V_1 ) ;
if ( error < 0 )
goto V_272;
V_206:
return error ;
V_272:
F_98 ( V_1 ) ;
V_271:
F_112 ( V_1 ) ;
goto V_206;
}
static void T_7 F_121 ( struct V_1 * V_1 )
{
F_122 ( V_1 ) ;
F_98 ( V_1 ) ;
F_112 ( V_1 ) ;
}
void T_8 F_123 ( void )
{
F_124 ( V_273 , V_211 , F_69 , NULL , NULL ) ;
F_124 ( V_273 , V_233 , F_67 , NULL , NULL ) ;
F_124 ( V_273 , V_274 , NULL , F_70 , NULL ) ;
F_125 ( & V_275 ) ;
F_126 ( & V_276 ) ;
F_127 ( & V_277 ) ;
F_128 () ;
}
