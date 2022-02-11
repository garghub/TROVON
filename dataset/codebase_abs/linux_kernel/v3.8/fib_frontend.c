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
V_32 . V_57 = V_58 ;
V_32 . V_33 = F_23 ( V_44 ) -> V_55 ;
V_32 . V_55 = 0 ;
V_32 . V_59 = F_27 ( F_23 ( V_44 ) -> V_60 ) ;
V_32 . V_61 = V_49 ;
V_32 . V_62 = F_28 ( V_46 ) ? V_44 -> V_63 : 0 ;
if ( ! F_29 ( V_1 , & V_32 , & V_35 ) )
return F_30 ( V_1 , V_35 ) ;
} else {
V_49 = V_64 ;
}
return F_31 ( V_29 , F_23 ( V_44 ) -> V_55 , V_49 ) ;
}
static int F_32 ( struct V_43 * V_44 , T_3 V_65 , T_3 V_66 ,
T_4 V_60 , int V_67 , struct V_28 * V_29 ,
int V_68 , struct V_45 * V_69 , T_2 * V_70 )
{
int V_36 , V_71 , V_72 ;
struct V_34 V_35 ;
struct V_31 V_32 ;
struct V_1 * V_1 ;
bool V_73 ;
V_32 . V_56 = 0 ;
V_32 . V_57 = V_67 ;
V_32 . V_33 = V_65 ;
V_32 . V_55 = V_66 ;
V_32 . V_59 = V_60 ;
V_32 . V_61 = V_54 ;
V_71 = V_69 -> V_74 == NULL ;
V_72 = F_33 ( V_69 ) ;
V_32 . V_62 = F_28 ( V_69 ) ? V_44 -> V_63 : 0 ;
V_1 = F_26 ( V_29 ) ;
if ( F_29 ( V_1 , & V_32 , & V_35 ) )
goto V_75;
if ( V_35 . type != V_39 ) {
if ( V_35 . type != V_76 || ! V_72 )
goto V_77;
}
F_34 ( V_70 , & V_35 ) ;
V_73 = false ;
#ifdef F_35
for ( V_36 = 0 ; V_36 < V_35 . V_41 -> V_78 ; V_36 ++ ) {
struct V_79 * V_80 = & V_35 . V_41 -> V_79 [ V_36 ] ;
if ( V_80 -> V_81 == V_29 ) {
V_73 = true ;
break;
}
}
#else
if ( F_36 ( V_35 ) == V_29 )
V_73 = true ;
#endif
if ( V_73 ) {
V_36 = F_37 ( V_35 ) . V_82 >= V_83 ;
return V_36 ;
}
if ( V_71 )
goto V_75;
if ( V_68 == 1 )
goto V_84;
V_32 . V_56 = V_29 -> V_85 ;
V_36 = 0 ;
if ( F_29 ( V_1 , & V_32 , & V_35 ) == 0 ) {
if ( V_35 . type == V_39 )
V_36 = F_37 ( V_35 ) . V_82 >= V_83 ;
}
return V_36 ;
V_75:
if ( V_68 )
goto V_84;
* V_70 = 0 ;
return 0 ;
V_77:
return - V_86 ;
V_84:
return - V_87 ;
}
int F_38 ( struct V_43 * V_44 , T_3 V_65 , T_3 V_66 ,
T_4 V_60 , int V_67 , struct V_28 * V_29 ,
struct V_45 * V_69 , T_2 * V_70 )
{
int V_88 = F_39 ( V_44 ) ? 0 : F_40 ( V_69 ) ;
if ( ! V_88 && ! F_41 ( F_26 ( V_29 ) ) &&
( V_29 -> V_85 != V_67 || ! F_42 ( V_69 ) ) ) {
* V_70 = 0 ;
return 0 ;
}
return F_32 ( V_44 , V_65 , V_66 , V_60 , V_67 , V_29 , V_88 , V_69 , V_70 ) ;
}
static inline T_3 F_43 ( struct V_89 * V_30 )
{
return ( (struct V_90 * ) V_30 ) -> V_91 . V_92 ;
}
static int F_44 ( struct V_93 * V_94 , int V_95 , int type , T_2 V_96 )
{
struct V_93 * V_97 ;
V_97 = (struct V_93 * ) ( ( char * ) V_94 + V_95 ) ;
V_97 -> V_98 = type ;
V_97 -> V_99 = F_45 ( 4 ) ;
* ( T_2 * ) F_46 ( V_97 ) = V_96 ;
return V_95 + F_47 ( 4 ) ;
}
static int F_48 ( struct V_1 * V_1 , int V_100 , struct V_101 * V_48 ,
struct V_102 * V_103 )
{
T_3 V_30 ;
int V_104 ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_103 -> V_105 . V_106 = V_1 ;
if ( V_48 -> V_107 . V_108 != V_109 )
return - V_110 ;
V_104 = 32 ;
V_30 = F_43 ( & V_48 -> V_107 ) ;
if ( ! ( V_48 -> V_50 & V_111 ) ) {
T_3 V_112 = F_43 ( & V_48 -> V_113 ) ;
if ( V_48 -> V_113 . V_108 != V_109 ) {
if ( V_112 || V_48 -> V_113 . V_108 )
return - V_110 ;
}
if ( F_49 ( V_112 , V_30 ) )
return - V_86 ;
V_104 = F_50 ( V_112 ) ;
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
V_103 -> V_124 = V_83 ;
V_103 -> V_125 = V_126 ;
return 0 ;
}
V_103 -> V_124 = V_127 ;
V_103 -> V_125 = V_39 ;
if ( V_48 -> V_128 ) {
char * V_129 ;
struct V_28 * V_29 ;
char V_130 [ V_131 ] ;
if ( F_51 ( V_130 , V_48 -> V_128 , V_131 - 1 ) )
return - V_132 ;
V_130 [ V_131 - 1 ] = 0 ;
V_129 = strchr ( V_130 , ':' ) ;
if ( V_129 )
* V_129 = 0 ;
V_29 = F_52 ( V_1 , V_130 ) ;
if ( ! V_29 )
return - V_133 ;
V_103 -> V_134 = V_29 -> V_85 ;
if ( V_129 ) {
struct V_135 * V_136 ;
struct V_45 * V_46 = F_53 ( V_29 ) ;
if ( ! V_46 )
return - V_133 ;
* V_129 = ':' ;
for ( V_136 = V_46 -> V_74 ; V_136 ; V_136 = V_136 -> V_137 )
if ( strcmp ( V_136 -> V_138 , V_130 ) == 0 )
break;
if ( V_136 == NULL )
return - V_133 ;
V_103 -> V_139 = V_136 -> V_140 ;
}
}
V_30 = F_43 ( & V_48 -> V_141 ) ;
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
V_103 -> V_124 = V_64 ;
if ( V_48 -> V_50 & ( V_144 | V_145 | V_146 ) ) {
struct V_93 * V_94 ;
int V_95 = 0 ;
V_94 = F_54 ( 3 * F_47 ( 4 ) , V_147 ) ;
if ( V_94 == NULL )
return - V_6 ;
if ( V_48 -> V_50 & V_144 )
V_95 = F_44 ( V_94 , V_95 , V_148 , V_48 -> V_149 - 40 ) ;
if ( V_48 -> V_50 & V_145 )
V_95 = F_44 ( V_94 , V_95 , V_150 , V_48 -> V_151 ) ;
if ( V_48 -> V_50 & V_146 )
V_95 = F_44 ( V_94 , V_95 , V_152 , V_48 -> V_153 << 3 ) ;
V_103 -> V_154 = V_94 ;
V_103 -> V_155 = V_95 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_1 , unsigned int V_100 , void T_5 * V_156 )
{
struct V_102 V_103 ;
struct V_101 V_48 ;
int V_157 ;
switch ( V_100 ) {
case V_158 :
case V_116 :
if ( ! F_56 ( V_1 -> V_159 , V_160 ) )
return - V_161 ;
if ( F_51 ( & V_48 , V_156 , sizeof( V_48 ) ) )
return - V_132 ;
F_57 () ;
V_157 = F_48 ( V_1 , V_100 , & V_48 , & V_103 ) ;
if ( V_157 == 0 ) {
struct V_2 * V_15 ;
if ( V_100 == V_116 ) {
V_15 = F_6 ( V_1 , V_103 . V_162 ) ;
if ( V_15 )
V_157 = F_58 ( V_15 , & V_103 ) ;
else
V_157 = - V_163 ;
} else {
V_15 = F_5 ( V_1 , V_103 . V_162 ) ;
if ( V_15 )
V_157 = F_59 ( V_15 , & V_103 ) ;
else
V_157 = - V_164 ;
}
F_4 ( V_103 . V_154 ) ;
}
F_60 () ;
return V_157 ;
}
return - V_86 ;
}
static int F_61 ( struct V_1 * V_1 , struct V_43 * V_44 ,
struct V_165 * V_166 , struct V_102 * V_103 )
{
struct V_93 * V_167 ;
int V_157 , V_168 ;
struct V_169 * V_170 ;
V_157 = F_62 ( V_166 , sizeof( * V_170 ) , V_171 , V_172 ) ;
if ( V_157 < 0 )
goto V_173;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_170 = F_63 ( V_166 ) ;
V_103 -> V_114 = V_170 -> V_174 ;
V_103 -> V_175 = V_170 -> V_176 ;
V_103 -> V_162 = V_170 -> V_177 ;
V_103 -> V_119 = V_170 -> V_178 ;
V_103 -> V_124 = V_170 -> V_179 ;
V_103 -> V_125 = V_170 -> V_180 ;
V_103 -> V_181 = V_170 -> V_182 ;
V_103 -> V_117 = V_166 -> V_183 ;
V_103 -> V_105 . V_184 = F_64 ( V_44 ) . V_184 ;
V_103 -> V_105 . V_166 = V_166 ;
V_103 -> V_105 . V_106 = V_1 ;
if ( V_103 -> V_125 > V_185 ) {
V_157 = - V_86 ;
goto V_173;
}
F_65 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_98 ( V_167 ) ) {
case V_186 :
V_103 -> V_115 = F_66 ( V_167 ) ;
break;
case V_187 :
V_103 -> V_134 = F_67 ( V_167 ) ;
break;
case V_188 :
V_103 -> V_142 = F_66 ( V_167 ) ;
break;
case V_189 :
V_103 -> V_122 = F_67 ( V_167 ) ;
break;
case V_190 :
V_103 -> V_139 = F_66 ( V_167 ) ;
break;
case V_191 :
V_103 -> V_154 = F_46 ( V_167 ) ;
V_103 -> V_155 = V_99 ( V_167 ) ;
break;
case V_192 :
V_103 -> V_193 = F_46 ( V_167 ) ;
V_103 -> V_194 = V_99 ( V_167 ) ;
break;
case V_195 :
V_103 -> V_196 = F_67 ( V_167 ) ;
break;
case V_197 :
V_103 -> V_162 = F_67 ( V_167 ) ;
break;
}
}
return 0 ;
V_173:
return V_157 ;
}
static int F_68 ( struct V_43 * V_44 , struct V_165 * V_166 , void * V_156 )
{
struct V_1 * V_1 = F_69 ( V_44 -> V_198 ) ;
struct V_102 V_103 ;
struct V_2 * V_15 ;
int V_157 ;
V_157 = F_61 ( V_1 , V_44 , V_166 , & V_103 ) ;
if ( V_157 < 0 )
goto V_173;
V_15 = F_6 ( V_1 , V_103 . V_162 ) ;
if ( V_15 == NULL ) {
V_157 = - V_163 ;
goto V_173;
}
V_157 = F_58 ( V_15 , & V_103 ) ;
V_173:
return V_157 ;
}
static int F_70 ( struct V_43 * V_44 , struct V_165 * V_166 , void * V_156 )
{
struct V_1 * V_1 = F_69 ( V_44 -> V_198 ) ;
struct V_102 V_103 ;
struct V_2 * V_15 ;
int V_157 ;
V_157 = F_61 ( V_1 , V_44 , V_166 , & V_103 ) ;
if ( V_157 < 0 )
goto V_173;
V_15 = F_5 ( V_1 , V_103 . V_162 ) ;
if ( V_15 == NULL ) {
V_157 = - V_164 ;
goto V_173;
}
V_157 = F_59 ( V_15 , & V_103 ) ;
V_173:
return V_157 ;
}
static int F_71 ( struct V_43 * V_44 , struct V_199 * V_200 )
{
struct V_1 * V_1 = F_69 ( V_44 -> V_198 ) ;
unsigned int V_16 , V_201 ;
unsigned int V_202 = 0 , V_203 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
int V_204 = 0 ;
if ( F_72 ( V_200 -> V_166 ) >= sizeof( struct V_169 ) &&
( (struct V_169 * ) F_63 ( V_200 -> V_166 ) ) -> V_182 & V_205 )
return F_73 ( V_44 , V_200 ) ;
V_201 = V_200 -> args [ 0 ] ;
V_203 = V_200 -> args [ 1 ] ;
for ( V_16 = V_201 ; V_16 < V_21 ; V_16 ++ , V_203 = 0 ) {
V_202 = 0 ;
V_25 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_11 (tb, node, head, tb_hlist) {
if ( V_202 < V_203 )
goto V_206;
if ( V_204 )
memset ( & V_200 -> args [ 2 ] , 0 , sizeof( V_200 -> args ) -
2 * sizeof( V_200 -> args [ 0 ] ) ) ;
if ( F_74 ( V_15 , V_44 , V_200 ) < 0 )
goto V_207;
V_204 = 1 ;
V_206:
V_202 ++ ;
}
}
V_207:
V_200 -> args [ 1 ] = V_202 ;
V_200 -> args [ 0 ] = V_16 ;
return V_44 -> V_95 ;
}
static void F_75 ( int V_100 , int type , T_3 V_66 , int V_208 , struct V_135 * V_136 )
{
struct V_1 * V_1 = F_26 ( V_136 -> V_209 -> V_29 ) ;
struct V_2 * V_15 ;
struct V_102 V_103 = {
. V_119 = V_210 ,
. V_125 = type ,
. V_115 = V_66 ,
. V_114 = V_208 ,
. V_139 = V_136 -> V_140 ,
. V_134 = V_136 -> V_209 -> V_29 -> V_85 ,
. V_117 = V_118 | V_211 ,
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
V_103 . V_162 = V_15 -> V_26 ;
if ( type != V_76 )
V_103 . V_124 = V_64 ;
else
V_103 . V_124 = V_83 ;
if ( V_100 == V_212 )
F_59 ( V_15 , & V_103 ) ;
else
F_58 ( V_15 , & V_103 ) ;
}
void F_76 ( struct V_135 * V_136 )
{
struct V_45 * V_46 = V_136 -> V_209 ;
struct V_28 * V_29 = V_46 -> V_29 ;
struct V_135 * V_213 = V_136 ;
T_3 V_112 = V_136 -> V_214 ;
T_3 V_30 = V_136 -> V_140 ;
T_3 V_215 = V_136 -> V_216 & V_112 ;
if ( V_136 -> V_217 & V_218 ) {
V_213 = F_77 ( V_46 , V_215 , V_112 ) ;
if ( V_213 == NULL ) {
F_78 ( L_1 , V_219 ) ;
return;
}
}
F_75 ( V_212 , V_76 , V_30 , 32 , V_213 ) ;
if ( ! ( V_29 -> V_220 & V_221 ) )
return;
if ( V_136 -> V_222 && V_136 -> V_222 != F_79 ( 0xFFFFFFFF ) )
F_75 ( V_212 , V_37 , V_136 -> V_222 , 32 , V_213 ) ;
if ( ! F_15 ( V_215 ) && ! ( V_136 -> V_217 & V_218 ) &&
( V_215 != V_30 || V_136 -> V_223 < 32 ) ) {
F_75 ( V_212 ,
V_29 -> V_220 & V_224 ? V_76 : V_39 ,
V_215 , V_136 -> V_223 , V_213 ) ;
if ( V_136 -> V_223 < 31 ) {
F_75 ( V_212 , V_37 , V_215 , 32 , V_213 ) ;
F_75 ( V_212 , V_37 , V_215 | ~ V_112 ,
32 , V_213 ) ;
}
}
}
void F_80 ( struct V_135 * V_136 , struct V_135 * V_225 )
{
struct V_45 * V_46 = V_136 -> V_209 ;
struct V_28 * V_29 = V_46 -> V_29 ;
struct V_135 * V_226 ;
struct V_135 * V_213 = V_136 , * V_227 = NULL ;
T_3 V_228 = V_136 -> V_216 | ~ V_136 -> V_214 ;
T_3 V_229 = V_136 -> V_216 & V_136 -> V_214 ;
#define F_81 1
#define F_82 2
#define F_83 4
#define F_84 8
unsigned int V_230 = 0 ;
int V_231 = 0 ;
int V_232 = 1 ;
int V_233 = 0 ;
if ( V_136 -> V_217 & V_218 ) {
V_213 = F_77 ( V_46 , V_229 , V_136 -> V_214 ) ;
if ( V_213 == NULL ) {
F_78 ( L_1 , V_219 ) ;
return;
}
if ( V_225 && V_225 != V_213 ) {
F_78 ( L_2 , V_219 ) ;
return;
}
} else if ( ! F_15 ( V_229 ) &&
( V_229 != V_136 -> V_140 || V_136 -> V_223 < 32 ) ) {
F_75 ( V_234 ,
V_29 -> V_220 & V_224 ? V_76 : V_39 ,
V_229 , V_136 -> V_223 , V_213 ) ;
V_231 = 1 ;
}
for ( V_226 = V_46 -> V_74 ; V_226 ; V_226 = V_226 -> V_137 ) {
if ( V_226 == V_136 ) {
V_232 = 0 ;
continue;
}
if ( V_225 && V_226 -> V_214 == V_225 -> V_214 &&
F_85 ( V_226 -> V_216 , V_225 ) )
continue;
if ( V_226 -> V_217 & V_218 ) {
if ( V_226 -> V_214 == V_213 -> V_214 &&
F_85 ( V_226 -> V_216 , V_213 ) )
V_227 = V_213 ;
else {
if ( ! V_233 )
continue;
if ( ! V_227 ||
V_226 -> V_214 != V_227 -> V_214 ||
! F_85 ( V_226 -> V_216 , V_227 ) )
V_227 = F_77 ( V_46 ,
V_226 -> V_216 ,
V_226 -> V_214 ) ;
if ( ! V_227 )
continue;
if ( V_227 -> V_140 != V_213 -> V_140 )
continue;
}
} else {
if ( V_213 -> V_140 != V_226 -> V_140 )
continue;
V_227 = V_226 ;
if ( V_213 != V_227 )
V_233 = 1 ;
}
if ( V_136 -> V_140 == V_226 -> V_140 )
V_230 |= F_81 ;
if ( V_136 -> V_222 == V_226 -> V_222 )
V_230 |= F_82 ;
if ( V_228 == V_226 -> V_222 )
V_230 |= F_84 ;
if ( V_229 == V_226 -> V_222 )
V_230 |= F_83 ;
if ( V_227 == V_226 && V_226 -> V_223 < 31 ) {
T_3 V_235 = V_226 -> V_216 | ~ V_226 -> V_214 ;
T_3 V_236 = V_226 -> V_216 & V_226 -> V_214 ;
if ( ! F_15 ( V_236 ) ) {
if ( V_136 -> V_222 == V_235 ||
V_136 -> V_222 == V_236 )
V_230 |= F_82 ;
if ( V_228 == V_235 || V_228 == V_236 )
V_230 |= F_84 ;
if ( V_229 == V_235 || V_229 == V_236 )
V_230 |= F_83 ;
}
}
}
if ( ! ( V_230 & F_82 ) )
F_75 ( V_234 , V_37 , V_136 -> V_222 , 32 , V_213 ) ;
if ( V_231 && V_136 -> V_223 < 31 ) {
if ( ! ( V_230 & F_84 ) )
F_75 ( V_234 , V_37 , V_228 , 32 , V_213 ) ;
if ( ! ( V_230 & F_83 ) )
F_75 ( V_234 , V_37 , V_229 , 32 , V_213 ) ;
}
if ( ! ( V_230 & F_81 ) ) {
F_75 ( V_234 , V_76 , V_136 -> V_140 , 32 , V_213 ) ;
if ( V_232 &&
F_19 ( F_26 ( V_29 ) , V_136 -> V_140 ) != V_76 ) {
if ( F_86 ( F_26 ( V_29 ) , V_136 -> V_140 ) )
F_10 ( F_26 ( V_29 ) ) ;
}
}
#undef F_81
#undef F_82
#undef F_83
#undef F_84
}
static void F_87 ( struct V_237 * V_238 , struct V_2 * V_15 )
{
struct V_34 V_35 ;
struct V_31 V_32 = {
. V_62 = V_238 -> V_239 ,
. V_33 = V_238 -> V_240 ,
. V_59 = V_238 -> V_241 ,
. V_61 = V_238 -> V_242 ,
} ;
V_238 -> V_157 = - V_243 ;
if ( V_15 ) {
F_88 () ;
V_238 -> V_26 = V_15 -> V_26 ;
F_7 () ;
V_238 -> V_157 = F_18 ( V_15 , & V_32 , & V_35 , V_40 ) ;
if ( ! V_238 -> V_157 ) {
V_238 -> V_244 = V_35 . V_244 ;
V_238 -> V_245 = V_35 . V_245 ;
V_238 -> type = V_35 . type ;
V_238 -> V_49 = V_35 . V_49 ;
}
F_9 () ;
F_89 () ;
}
}
static void F_90 ( struct V_43 * V_44 )
{
struct V_1 * V_1 ;
struct V_237 * V_238 ;
struct V_165 * V_166 ;
struct V_2 * V_15 ;
T_2 V_184 ;
V_1 = F_69 ( V_44 -> V_198 ) ;
V_166 = F_91 ( V_44 ) ;
if ( V_44 -> V_95 < F_92 ( 0 ) || V_44 -> V_95 < V_166 -> F_72 ||
V_166 -> F_72 < F_93 ( sizeof( * V_238 ) ) )
return;
V_44 = F_94 ( V_44 , V_147 ) ;
if ( V_44 == NULL )
return;
V_166 = F_91 ( V_44 ) ;
V_238 = (struct V_237 * ) F_95 ( V_166 ) ;
V_15 = F_6 ( V_1 , V_238 -> V_246 ) ;
F_87 ( V_238 , V_15 ) ;
V_184 = F_64 ( V_44 ) . V_184 ;
F_64 ( V_44 ) . V_184 = 0 ;
F_64 ( V_44 ) . V_247 = 0 ;
F_96 ( V_1 -> V_10 . V_248 , V_44 , V_184 , V_249 ) ;
}
static int T_1 F_97 ( struct V_1 * V_1 )
{
struct V_250 * V_198 ;
struct V_251 V_103 = {
. V_252 = F_90 ,
} ;
V_198 = F_98 ( V_1 , V_253 , & V_103 ) ;
if ( V_198 == NULL )
return - V_110 ;
V_1 -> V_10 . V_248 = V_198 ;
return 0 ;
}
static void F_99 ( struct V_1 * V_1 )
{
F_100 ( V_1 -> V_10 . V_248 ) ;
V_1 -> V_10 . V_248 = NULL ;
}
static void F_101 ( struct V_28 * V_29 , int V_254 )
{
if ( F_102 ( V_29 , V_254 ) )
F_10 ( F_26 ( V_29 ) ) ;
F_13 ( F_26 ( V_29 ) ) ;
F_103 ( V_29 ) ;
}
static int F_104 ( struct V_255 * V_256 , unsigned long V_257 , void * V_258 )
{
struct V_135 * V_136 = (struct V_135 * ) V_258 ;
struct V_28 * V_29 = V_136 -> V_209 -> V_29 ;
struct V_1 * V_1 = F_26 ( V_29 ) ;
switch ( V_257 ) {
case V_259 :
F_76 ( V_136 ) ;
#ifdef F_35
F_105 ( V_29 ) ;
#endif
F_106 ( & V_1 -> V_10 . V_260 ) ;
F_13 ( F_26 ( V_29 ) ) ;
break;
case V_261 :
F_80 ( V_136 , NULL ) ;
F_106 ( & V_1 -> V_10 . V_260 ) ;
if ( V_136 -> V_209 -> V_74 == NULL ) {
F_101 ( V_29 , 1 ) ;
} else {
F_13 ( F_26 ( V_29 ) ) ;
}
break;
}
return V_262 ;
}
static int F_107 ( struct V_255 * V_256 , unsigned long V_257 , void * V_258 )
{
struct V_28 * V_29 = V_258 ;
struct V_45 * V_46 ;
struct V_1 * V_1 = F_26 ( V_29 ) ;
if ( V_257 == V_263 ) {
F_101 ( V_29 , 2 ) ;
F_108 ( V_29 ) ;
return V_262 ;
}
V_46 = F_53 ( V_29 ) ;
switch ( V_257 ) {
case V_259 :
F_109 (in_dev) {
F_76 ( V_136 ) ;
} F_110 ( V_46 ) ;
#ifdef F_35
F_105 ( V_29 ) ;
#endif
F_106 ( & V_1 -> V_10 . V_260 ) ;
F_13 ( V_1 ) ;
break;
case V_261 :
F_101 ( V_29 , 0 ) ;
break;
case V_264 :
case V_265 :
F_13 ( V_1 ) ;
break;
}
return V_262 ;
}
static int T_1 F_111 ( struct V_1 * V_1 )
{
int V_157 ;
T_6 V_266 = sizeof( struct V_24 ) * V_21 ;
V_266 = F_112 ( T_6 , V_266 , V_267 ) ;
V_1 -> V_10 . V_11 = F_54 ( V_266 , V_147 ) ;
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
static void F_113 ( struct V_1 * V_1 )
{
unsigned int V_268 ;
#ifdef F_114
F_115 ( V_1 ) ;
#endif
F_57 () ;
for ( V_268 = 0 ; V_268 < V_21 ; V_268 ++ ) {
struct V_2 * V_15 ;
struct V_24 * V_25 ;
struct V_22 * V_23 , * V_269 ;
V_25 = & V_1 -> V_10 . V_11 [ V_268 ] ;
F_116 (tb, node, tmp, head, tb_hlist) {
F_117 ( V_23 ) ;
F_12 ( V_15 ) ;
F_118 ( V_15 ) ;
}
}
F_60 () ;
F_4 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_119 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_120
V_1 -> V_10 . F_41 = 0 ;
#endif
error = F_111 ( V_1 ) ;
if ( error < 0 )
goto V_207;
error = F_97 ( V_1 ) ;
if ( error < 0 )
goto V_270;
error = F_121 ( V_1 ) ;
if ( error < 0 )
goto V_271;
V_207:
return error ;
V_271:
F_99 ( V_1 ) ;
V_270:
F_113 ( V_1 ) ;
goto V_207;
}
static void T_7 F_122 ( struct V_1 * V_1 )
{
F_123 ( V_1 ) ;
F_99 ( V_1 ) ;
F_113 ( V_1 ) ;
}
void T_8 F_124 ( void )
{
F_125 ( V_272 , V_212 , F_70 , NULL , NULL ) ;
F_125 ( V_272 , V_234 , F_68 , NULL , NULL ) ;
F_125 ( V_272 , V_273 , NULL , F_71 , NULL ) ;
F_126 ( & V_274 ) ;
F_127 ( & V_275 ) ;
F_128 ( & V_276 ) ;
F_129 () ;
}
