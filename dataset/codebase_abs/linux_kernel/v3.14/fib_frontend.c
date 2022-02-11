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
unsigned int V_16 ;
if ( V_14 == 0 )
V_14 = V_7 ;
V_16 = V_14 & ( V_21 - 1 ) ;
F_7 () ;
V_23 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_15 -> V_24 == V_14 ) {
F_9 () ;
return V_15 ;
}
}
F_9 () ;
return NULL ;
}
static void F_10 ( struct V_1 * V_1 )
{
int V_25 = 0 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ ) {
V_23 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_11 (tb, head, tb_hlist)
V_25 += F_12 ( V_15 ) ;
}
if ( V_25 )
F_13 ( V_1 ) ;
}
static inline unsigned int F_14 ( struct V_1 * V_1 ,
const struct V_26 * V_27 ,
T_3 V_28 )
{
struct V_29 V_30 = { . V_31 = V_28 } ;
struct V_32 V_33 ;
unsigned int V_34 = V_35 ;
struct V_2 * V_3 ;
if ( F_15 ( V_28 ) || F_16 ( V_28 ) )
return V_35 ;
if ( F_17 ( V_28 ) )
return V_36 ;
V_3 = F_6 ( V_1 , V_5 ) ;
if ( V_3 ) {
V_34 = V_37 ;
F_7 () ;
if ( ! F_18 ( V_3 , & V_30 , & V_33 , V_38 ) ) {
if ( ! V_27 || V_27 == V_33 . V_39 -> V_40 )
V_34 = V_33 . type ;
}
F_9 () ;
}
return V_34 ;
}
unsigned int F_19 ( struct V_1 * V_1 , T_3 V_28 )
{
return F_14 ( V_1 , NULL , V_28 ) ;
}
unsigned int F_20 ( struct V_1 * V_1 , const struct V_26 * V_27 ,
T_3 V_28 )
{
return F_14 ( V_1 , V_27 , V_28 ) ;
}
T_3 F_21 ( struct V_41 * V_42 )
{
struct V_26 * V_27 = V_42 -> V_27 ;
struct V_43 * V_44 ;
struct V_32 V_33 ;
struct V_45 * V_46 ;
struct V_29 V_30 ;
struct V_1 * V_1 ;
int V_47 ;
V_46 = F_22 ( V_42 ) ;
if ( ( V_46 -> V_48 & ( V_49 | V_50 | V_51 ) ) ==
V_51 )
return F_23 ( V_42 ) -> V_31 ;
V_44 = F_24 ( V_27 ) ;
F_25 ( ! V_44 ) ;
V_1 = F_26 ( V_27 ) ;
V_47 = V_52 ;
if ( ! F_15 ( F_23 ( V_42 ) -> V_53 ) ) {
V_30 . V_54 = 0 ;
V_30 . V_55 = V_56 ;
V_30 . V_31 = F_23 ( V_42 ) -> V_53 ;
V_30 . V_53 = 0 ;
V_30 . V_57 = F_27 ( F_23 ( V_42 ) -> V_58 ) ;
V_30 . V_59 = V_47 ;
V_30 . V_60 = F_28 ( V_44 ) ? V_42 -> V_61 : 0 ;
if ( ! F_29 ( V_1 , & V_30 , & V_33 ) )
return F_30 ( V_1 , V_33 ) ;
} else {
V_47 = V_62 ;
}
return F_31 ( V_27 , F_23 ( V_42 ) -> V_53 , V_47 ) ;
}
static int F_32 ( struct V_41 * V_42 , T_3 V_63 , T_3 V_64 ,
T_4 V_58 , int V_65 , struct V_26 * V_27 ,
int V_66 , struct V_43 * V_67 , T_2 * V_68 )
{
int V_34 , V_69 , V_70 ;
struct V_32 V_33 ;
struct V_29 V_30 ;
struct V_1 * V_1 ;
bool V_71 ;
V_30 . V_54 = 0 ;
V_30 . V_55 = V_65 ;
V_30 . V_31 = V_63 ;
V_30 . V_53 = V_64 ;
V_30 . V_57 = V_58 ;
V_30 . V_59 = V_52 ;
V_69 = V_67 -> V_72 == NULL ;
V_70 = F_33 ( V_67 ) ;
V_30 . V_60 = F_28 ( V_67 ) ? V_42 -> V_61 : 0 ;
V_1 = F_26 ( V_27 ) ;
if ( F_29 ( V_1 , & V_30 , & V_33 ) )
goto V_73;
if ( V_33 . type != V_37 ) {
if ( V_33 . type != V_74 || ! V_70 )
goto V_75;
}
F_34 ( V_68 , & V_33 ) ;
V_71 = false ;
#ifdef F_35
for ( V_34 = 0 ; V_34 < V_33 . V_39 -> V_76 ; V_34 ++ ) {
struct V_77 * V_78 = & V_33 . V_39 -> V_77 [ V_34 ] ;
if ( V_78 -> V_79 == V_27 ) {
V_71 = true ;
break;
}
}
#else
if ( F_36 ( V_33 ) == V_27 )
V_71 = true ;
#endif
if ( V_71 ) {
V_34 = F_37 ( V_33 ) . V_80 >= V_81 ;
return V_34 ;
}
if ( V_69 )
goto V_73;
if ( V_66 == 1 )
goto V_82;
V_30 . V_54 = V_27 -> V_83 ;
V_34 = 0 ;
if ( F_29 ( V_1 , & V_30 , & V_33 ) == 0 ) {
if ( V_33 . type == V_37 )
V_34 = F_37 ( V_33 ) . V_80 >= V_81 ;
}
return V_34 ;
V_73:
if ( V_66 )
goto V_82;
* V_68 = 0 ;
return 0 ;
V_75:
return - V_84 ;
V_82:
return - V_85 ;
}
int F_38 ( struct V_41 * V_42 , T_3 V_63 , T_3 V_64 ,
T_4 V_58 , int V_65 , struct V_26 * V_27 ,
struct V_43 * V_67 , T_2 * V_68 )
{
int V_86 = F_39 ( V_42 ) ? 0 : F_40 ( V_67 ) ;
if ( ! V_86 && ! F_41 ( F_26 ( V_27 ) ) &&
( V_27 -> V_83 != V_65 || ! F_42 ( V_67 ) ) ) {
* V_68 = 0 ;
return 0 ;
}
return F_32 ( V_42 , V_63 , V_64 , V_58 , V_65 , V_27 , V_86 , V_67 , V_68 ) ;
}
static inline T_3 F_43 ( struct V_87 * V_28 )
{
return ( (struct V_88 * ) V_28 ) -> V_89 . V_90 ;
}
static int F_44 ( struct V_91 * V_92 , int V_93 , int type , T_2 V_94 )
{
struct V_91 * V_95 ;
V_95 = (struct V_91 * ) ( ( char * ) V_92 + V_93 ) ;
V_95 -> V_96 = type ;
V_95 -> V_97 = F_45 ( 4 ) ;
* ( T_2 * ) F_46 ( V_95 ) = V_94 ;
return V_93 + F_47 ( 4 ) ;
}
static int F_48 ( struct V_1 * V_1 , int V_98 , struct V_99 * V_46 ,
struct V_100 * V_101 )
{
T_3 V_28 ;
int V_102 ;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_101 -> V_103 . V_104 = V_1 ;
if ( V_46 -> V_105 . V_106 != V_107 )
return - V_108 ;
V_102 = 32 ;
V_28 = F_43 ( & V_46 -> V_105 ) ;
if ( ! ( V_46 -> V_48 & V_109 ) ) {
T_3 V_110 = F_43 ( & V_46 -> V_111 ) ;
if ( V_46 -> V_111 . V_106 != V_107 ) {
if ( V_110 || V_46 -> V_111 . V_106 )
return - V_108 ;
}
if ( F_49 ( V_110 , V_28 ) )
return - V_84 ;
V_102 = F_50 ( V_110 ) ;
}
V_101 -> V_112 = V_102 ;
V_101 -> V_113 = V_28 ;
if ( V_98 != V_114 ) {
V_101 -> V_115 = V_116 ;
V_101 -> V_117 = V_118 ;
}
if ( V_46 -> V_119 )
V_101 -> V_120 = V_46 -> V_119 - 1 ;
if ( V_46 -> V_48 & V_121 ) {
V_101 -> V_122 = V_81 ;
V_101 -> V_123 = V_124 ;
return 0 ;
}
V_101 -> V_122 = V_125 ;
V_101 -> V_123 = V_37 ;
if ( V_46 -> V_126 ) {
char * V_127 ;
struct V_26 * V_27 ;
char V_128 [ V_129 ] ;
if ( F_51 ( V_128 , V_46 -> V_126 , V_129 - 1 ) )
return - V_130 ;
V_128 [ V_129 - 1 ] = 0 ;
V_127 = strchr ( V_128 , ':' ) ;
if ( V_127 )
* V_127 = 0 ;
V_27 = F_52 ( V_1 , V_128 ) ;
if ( ! V_27 )
return - V_131 ;
V_101 -> V_132 = V_27 -> V_83 ;
if ( V_127 ) {
struct V_133 * V_134 ;
struct V_43 * V_44 = F_53 ( V_27 ) ;
if ( ! V_44 )
return - V_131 ;
* V_127 = ':' ;
for ( V_134 = V_44 -> V_72 ; V_134 ; V_134 = V_134 -> V_135 )
if ( strcmp ( V_134 -> V_136 , V_128 ) == 0 )
break;
if ( V_134 == NULL )
return - V_131 ;
V_101 -> V_137 = V_134 -> V_138 ;
}
}
V_28 = F_43 ( & V_46 -> V_139 ) ;
if ( V_46 -> V_139 . V_106 == V_107 && V_28 ) {
V_101 -> V_140 = V_28 ;
if ( V_46 -> V_48 & V_141 &&
F_19 ( V_1 , V_28 ) == V_37 )
V_101 -> V_122 = V_52 ;
}
if ( V_98 == V_114 )
return 0 ;
if ( V_46 -> V_48 & V_141 && ! V_101 -> V_140 )
return - V_84 ;
if ( V_101 -> V_122 == V_125 )
V_101 -> V_122 = V_62 ;
if ( V_46 -> V_48 & ( V_142 | V_143 | V_144 ) ) {
struct V_91 * V_92 ;
int V_93 = 0 ;
V_92 = F_54 ( 3 * F_47 ( 4 ) , V_145 ) ;
if ( V_92 == NULL )
return - V_6 ;
if ( V_46 -> V_48 & V_142 )
V_93 = F_44 ( V_92 , V_93 , V_146 , V_46 -> V_147 - 40 ) ;
if ( V_46 -> V_48 & V_143 )
V_93 = F_44 ( V_92 , V_93 , V_148 , V_46 -> V_149 ) ;
if ( V_46 -> V_48 & V_144 )
V_93 = F_44 ( V_92 , V_93 , V_150 , V_46 -> V_151 << 3 ) ;
V_101 -> V_152 = V_92 ;
V_101 -> V_153 = V_93 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_1 , unsigned int V_98 , void T_5 * V_154 )
{
struct V_100 V_101 ;
struct V_99 V_46 ;
int V_155 ;
switch ( V_98 ) {
case V_156 :
case V_114 :
if ( ! F_56 ( V_1 -> V_157 , V_158 ) )
return - V_159 ;
if ( F_51 ( & V_46 , V_154 , sizeof( V_46 ) ) )
return - V_130 ;
F_57 () ;
V_155 = F_48 ( V_1 , V_98 , & V_46 , & V_101 ) ;
if ( V_155 == 0 ) {
struct V_2 * V_15 ;
if ( V_98 == V_114 ) {
V_15 = F_6 ( V_1 , V_101 . V_160 ) ;
if ( V_15 )
V_155 = F_58 ( V_15 , & V_101 ) ;
else
V_155 = - V_161 ;
} else {
V_15 = F_5 ( V_1 , V_101 . V_160 ) ;
if ( V_15 )
V_155 = F_59 ( V_15 , & V_101 ) ;
else
V_155 = - V_162 ;
}
F_4 ( V_101 . V_152 ) ;
}
F_60 () ;
return V_155 ;
}
return - V_84 ;
}
static int F_61 ( struct V_1 * V_1 , struct V_41 * V_42 ,
struct V_163 * V_164 , struct V_100 * V_101 )
{
struct V_91 * V_165 ;
int V_155 , V_166 ;
struct V_167 * V_168 ;
V_155 = F_62 ( V_164 , sizeof( * V_168 ) , V_169 , V_170 ) ;
if ( V_155 < 0 )
goto V_171;
memset ( V_101 , 0 , sizeof( * V_101 ) ) ;
V_168 = F_63 ( V_164 ) ;
V_101 -> V_112 = V_168 -> V_172 ;
V_101 -> V_173 = V_168 -> V_174 ;
V_101 -> V_160 = V_168 -> V_175 ;
V_101 -> V_117 = V_168 -> V_176 ;
V_101 -> V_122 = V_168 -> V_177 ;
V_101 -> V_123 = V_168 -> V_178 ;
V_101 -> V_179 = V_168 -> V_180 ;
V_101 -> V_115 = V_164 -> V_181 ;
V_101 -> V_103 . V_182 = F_64 ( V_42 ) . V_182 ;
V_101 -> V_103 . V_164 = V_164 ;
V_101 -> V_103 . V_104 = V_1 ;
if ( V_101 -> V_123 > V_183 ) {
V_155 = - V_84 ;
goto V_171;
}
F_65 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_96 ( V_165 ) ) {
case V_184 :
V_101 -> V_113 = F_66 ( V_165 ) ;
break;
case V_185 :
V_101 -> V_132 = F_67 ( V_165 ) ;
break;
case V_186 :
V_101 -> V_140 = F_66 ( V_165 ) ;
break;
case V_187 :
V_101 -> V_120 = F_67 ( V_165 ) ;
break;
case V_188 :
V_101 -> V_137 = F_66 ( V_165 ) ;
break;
case V_189 :
V_101 -> V_152 = F_46 ( V_165 ) ;
V_101 -> V_153 = V_97 ( V_165 ) ;
break;
case V_190 :
V_101 -> V_191 = F_46 ( V_165 ) ;
V_101 -> V_192 = V_97 ( V_165 ) ;
break;
case V_193 :
V_101 -> V_194 = F_67 ( V_165 ) ;
break;
case V_195 :
V_101 -> V_160 = F_67 ( V_165 ) ;
break;
}
}
return 0 ;
V_171:
return V_155 ;
}
static int F_68 ( struct V_41 * V_42 , struct V_163 * V_164 )
{
struct V_1 * V_1 = F_69 ( V_42 -> V_196 ) ;
struct V_100 V_101 ;
struct V_2 * V_15 ;
int V_155 ;
V_155 = F_61 ( V_1 , V_42 , V_164 , & V_101 ) ;
if ( V_155 < 0 )
goto V_171;
V_15 = F_6 ( V_1 , V_101 . V_160 ) ;
if ( V_15 == NULL ) {
V_155 = - V_161 ;
goto V_171;
}
V_155 = F_58 ( V_15 , & V_101 ) ;
V_171:
return V_155 ;
}
static int F_70 ( struct V_41 * V_42 , struct V_163 * V_164 )
{
struct V_1 * V_1 = F_69 ( V_42 -> V_196 ) ;
struct V_100 V_101 ;
struct V_2 * V_15 ;
int V_155 ;
V_155 = F_61 ( V_1 , V_42 , V_164 , & V_101 ) ;
if ( V_155 < 0 )
goto V_171;
V_15 = F_5 ( V_1 , V_101 . V_160 ) ;
if ( V_15 == NULL ) {
V_155 = - V_162 ;
goto V_171;
}
V_155 = F_59 ( V_15 , & V_101 ) ;
V_171:
return V_155 ;
}
static int F_71 ( struct V_41 * V_42 , struct V_197 * V_198 )
{
struct V_1 * V_1 = F_69 ( V_42 -> V_196 ) ;
unsigned int V_16 , V_199 ;
unsigned int V_200 = 0 , V_201 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
int V_202 = 0 ;
if ( F_72 ( V_198 -> V_164 ) >= sizeof( struct V_167 ) &&
( (struct V_167 * ) F_63 ( V_198 -> V_164 ) ) -> V_180 & V_203 )
return F_73 ( V_42 , V_198 ) ;
V_199 = V_198 -> args [ 0 ] ;
V_201 = V_198 -> args [ 1 ] ;
for ( V_16 = V_199 ; V_16 < V_21 ; V_16 ++ , V_201 = 0 ) {
V_200 = 0 ;
V_23 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_11 (tb, head, tb_hlist) {
if ( V_200 < V_201 )
goto V_204;
if ( V_202 )
memset ( & V_198 -> args [ 2 ] , 0 , sizeof( V_198 -> args ) -
2 * sizeof( V_198 -> args [ 0 ] ) ) ;
if ( F_74 ( V_15 , V_42 , V_198 ) < 0 )
goto V_205;
V_202 = 1 ;
V_204:
V_200 ++ ;
}
}
V_205:
V_198 -> args [ 1 ] = V_200 ;
V_198 -> args [ 0 ] = V_16 ;
return V_42 -> V_93 ;
}
static void F_75 ( int V_98 , int type , T_3 V_64 , int V_206 , struct V_133 * V_134 )
{
struct V_1 * V_1 = F_26 ( V_134 -> V_207 -> V_27 ) ;
struct V_2 * V_15 ;
struct V_100 V_101 = {
. V_117 = V_208 ,
. V_123 = type ,
. V_113 = V_64 ,
. V_112 = V_206 ,
. V_137 = V_134 -> V_138 ,
. V_132 = V_134 -> V_207 -> V_27 -> V_83 ,
. V_115 = V_116 | V_209 ,
. V_103 = {
. V_104 = V_1 ,
} ,
} ;
if ( type == V_37 )
V_15 = F_5 ( V_1 , V_7 ) ;
else
V_15 = F_5 ( V_1 , V_5 ) ;
if ( V_15 == NULL )
return;
V_101 . V_160 = V_15 -> V_24 ;
if ( type != V_74 )
V_101 . V_122 = V_62 ;
else
V_101 . V_122 = V_81 ;
if ( V_98 == V_210 )
F_59 ( V_15 , & V_101 ) ;
else
F_58 ( V_15 , & V_101 ) ;
}
void F_76 ( struct V_133 * V_134 )
{
struct V_43 * V_44 = V_134 -> V_207 ;
struct V_26 * V_27 = V_44 -> V_27 ;
struct V_133 * V_211 = V_134 ;
T_3 V_110 = V_134 -> V_212 ;
T_3 V_28 = V_134 -> V_138 ;
T_3 V_213 = V_134 -> V_214 & V_110 ;
if ( V_134 -> V_215 & V_216 ) {
V_211 = F_77 ( V_44 , V_213 , V_110 ) ;
if ( V_211 == NULL ) {
F_78 ( L_1 , V_217 ) ;
return;
}
}
F_75 ( V_210 , V_74 , V_28 , 32 , V_211 ) ;
if ( ! ( V_27 -> V_218 & V_219 ) )
return;
if ( V_134 -> V_220 && V_134 -> V_220 != F_79 ( 0xFFFFFFFF ) )
F_75 ( V_210 , V_35 , V_134 -> V_220 , 32 , V_211 ) ;
if ( ! F_15 ( V_213 ) && ! ( V_134 -> V_215 & V_216 ) &&
( V_213 != V_28 || V_134 -> V_221 < 32 ) ) {
F_75 ( V_210 ,
V_27 -> V_218 & V_222 ? V_74 : V_37 ,
V_213 , V_134 -> V_221 , V_211 ) ;
if ( V_134 -> V_221 < 31 ) {
F_75 ( V_210 , V_35 , V_213 , 32 , V_211 ) ;
F_75 ( V_210 , V_35 , V_213 | ~ V_110 ,
32 , V_211 ) ;
}
}
}
void F_80 ( struct V_133 * V_134 , struct V_133 * V_223 )
{
struct V_43 * V_44 = V_134 -> V_207 ;
struct V_26 * V_27 = V_44 -> V_27 ;
struct V_133 * V_224 ;
struct V_133 * V_211 = V_134 , * V_225 = NULL ;
T_3 V_226 = V_134 -> V_214 | ~ V_134 -> V_212 ;
T_3 V_227 = V_134 -> V_214 & V_134 -> V_212 ;
#define F_81 1
#define F_82 2
#define F_83 4
#define F_84 8
unsigned int V_228 = 0 ;
int V_229 = 0 ;
int V_230 = 1 ;
int V_231 = 0 ;
if ( V_134 -> V_215 & V_216 ) {
V_211 = F_77 ( V_44 , V_227 , V_134 -> V_212 ) ;
if ( V_211 == NULL ) {
F_78 ( L_1 , V_217 ) ;
return;
}
if ( V_223 && V_223 != V_211 ) {
F_78 ( L_2 , V_217 ) ;
return;
}
} else if ( ! F_15 ( V_227 ) &&
( V_227 != V_134 -> V_138 || V_134 -> V_221 < 32 ) ) {
F_75 ( V_232 ,
V_27 -> V_218 & V_222 ? V_74 : V_37 ,
V_227 , V_134 -> V_221 , V_211 ) ;
V_229 = 1 ;
}
for ( V_224 = V_44 -> V_72 ; V_224 ; V_224 = V_224 -> V_135 ) {
if ( V_224 == V_134 ) {
V_230 = 0 ;
continue;
}
if ( V_223 && V_224 -> V_212 == V_223 -> V_212 &&
F_85 ( V_224 -> V_214 , V_223 ) )
continue;
if ( V_224 -> V_215 & V_216 ) {
if ( V_224 -> V_212 == V_211 -> V_212 &&
F_85 ( V_224 -> V_214 , V_211 ) )
V_225 = V_211 ;
else {
if ( ! V_231 )
continue;
if ( ! V_225 ||
V_224 -> V_212 != V_225 -> V_212 ||
! F_85 ( V_224 -> V_214 , V_225 ) )
V_225 = F_77 ( V_44 ,
V_224 -> V_214 ,
V_224 -> V_212 ) ;
if ( ! V_225 )
continue;
if ( V_225 -> V_138 != V_211 -> V_138 )
continue;
}
} else {
if ( V_211 -> V_138 != V_224 -> V_138 )
continue;
V_225 = V_224 ;
if ( V_211 != V_225 )
V_231 = 1 ;
}
if ( V_134 -> V_138 == V_224 -> V_138 )
V_228 |= F_81 ;
if ( V_134 -> V_220 == V_224 -> V_220 )
V_228 |= F_82 ;
if ( V_226 == V_224 -> V_220 )
V_228 |= F_84 ;
if ( V_227 == V_224 -> V_220 )
V_228 |= F_83 ;
if ( V_225 == V_224 && V_224 -> V_221 < 31 ) {
T_3 V_233 = V_224 -> V_214 | ~ V_224 -> V_212 ;
T_3 V_234 = V_224 -> V_214 & V_224 -> V_212 ;
if ( ! F_15 ( V_234 ) ) {
if ( V_134 -> V_220 == V_233 ||
V_134 -> V_220 == V_234 )
V_228 |= F_82 ;
if ( V_226 == V_233 || V_226 == V_234 )
V_228 |= F_84 ;
if ( V_227 == V_233 || V_227 == V_234 )
V_228 |= F_83 ;
}
}
}
if ( ! ( V_228 & F_82 ) )
F_75 ( V_232 , V_35 , V_134 -> V_220 , 32 , V_211 ) ;
if ( V_229 && V_134 -> V_221 < 31 ) {
if ( ! ( V_228 & F_84 ) )
F_75 ( V_232 , V_35 , V_226 , 32 , V_211 ) ;
if ( ! ( V_228 & F_83 ) )
F_75 ( V_232 , V_35 , V_227 , 32 , V_211 ) ;
}
if ( ! ( V_228 & F_81 ) ) {
F_75 ( V_232 , V_74 , V_134 -> V_138 , 32 , V_211 ) ;
if ( V_230 &&
F_19 ( F_26 ( V_27 ) , V_134 -> V_138 ) != V_74 ) {
if ( F_86 ( F_26 ( V_27 ) , V_134 -> V_138 ) )
F_10 ( F_26 ( V_27 ) ) ;
}
}
#undef F_81
#undef F_82
#undef F_83
#undef F_84
}
static void F_87 ( struct V_235 * V_236 , struct V_2 * V_15 )
{
struct V_32 V_33 ;
struct V_29 V_30 = {
. V_60 = V_236 -> V_237 ,
. V_31 = V_236 -> V_238 ,
. V_57 = V_236 -> V_239 ,
. V_59 = V_236 -> V_240 ,
} ;
V_236 -> V_155 = - V_241 ;
if ( V_15 ) {
F_88 () ;
V_236 -> V_24 = V_15 -> V_24 ;
V_236 -> V_155 = F_18 ( V_15 , & V_30 , & V_33 , V_38 ) ;
if ( ! V_236 -> V_155 ) {
V_236 -> V_242 = V_33 . V_242 ;
V_236 -> V_243 = V_33 . V_243 ;
V_236 -> type = V_33 . type ;
V_236 -> V_47 = V_33 . V_47 ;
}
F_89 () ;
}
}
static void F_90 ( struct V_41 * V_42 )
{
struct V_1 * V_1 ;
struct V_235 * V_236 ;
struct V_163 * V_164 ;
struct V_2 * V_15 ;
T_2 V_182 ;
V_1 = F_69 ( V_42 -> V_196 ) ;
V_164 = F_91 ( V_42 ) ;
if ( V_42 -> V_93 < V_244 || V_42 -> V_93 < V_164 -> F_72 ||
F_72 ( V_164 ) < sizeof( * V_236 ) )
return;
V_42 = F_92 ( V_42 , V_145 ) ;
if ( V_42 == NULL )
return;
V_164 = F_91 ( V_42 ) ;
V_236 = (struct V_235 * ) F_63 ( V_164 ) ;
V_15 = F_6 ( V_1 , V_236 -> V_245 ) ;
F_87 ( V_236 , V_15 ) ;
V_182 = F_64 ( V_42 ) . V_182 ;
F_64 ( V_42 ) . V_182 = 0 ;
F_64 ( V_42 ) . V_246 = 0 ;
F_93 ( V_1 -> V_10 . V_247 , V_42 , V_182 , V_248 ) ;
}
static int T_1 F_94 ( struct V_1 * V_1 )
{
struct V_249 * V_196 ;
struct V_250 V_101 = {
. V_251 = F_90 ,
} ;
V_196 = F_95 ( V_1 , V_252 , & V_101 ) ;
if ( V_196 == NULL )
return - V_108 ;
V_1 -> V_10 . V_247 = V_196 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_1 )
{
F_97 ( V_1 -> V_10 . V_247 ) ;
V_1 -> V_10 . V_247 = NULL ;
}
static void F_98 ( struct V_26 * V_27 , int V_253 )
{
if ( F_99 ( V_27 , V_253 ) )
F_10 ( F_26 ( V_27 ) ) ;
F_13 ( F_26 ( V_27 ) ) ;
F_100 ( V_27 ) ;
}
static int F_101 ( struct V_254 * V_255 , unsigned long V_256 , void * V_257 )
{
struct V_133 * V_134 = (struct V_133 * ) V_257 ;
struct V_26 * V_27 = V_134 -> V_207 -> V_27 ;
struct V_1 * V_1 = F_26 ( V_27 ) ;
switch ( V_256 ) {
case V_258 :
F_76 ( V_134 ) ;
#ifdef F_35
F_102 ( V_27 ) ;
#endif
F_103 ( & V_1 -> V_10 . V_259 ) ;
F_13 ( F_26 ( V_27 ) ) ;
break;
case V_260 :
F_80 ( V_134 , NULL ) ;
F_103 ( & V_1 -> V_10 . V_259 ) ;
if ( V_134 -> V_207 -> V_72 == NULL ) {
F_98 ( V_27 , 1 ) ;
} else {
F_13 ( F_26 ( V_27 ) ) ;
}
break;
}
return V_261 ;
}
static int F_104 ( struct V_254 * V_255 , unsigned long V_256 , void * V_257 )
{
struct V_26 * V_27 = F_105 ( V_257 ) ;
struct V_43 * V_44 ;
struct V_1 * V_1 = F_26 ( V_27 ) ;
if ( V_256 == V_262 ) {
F_98 ( V_27 , 2 ) ;
F_106 ( V_27 ) ;
return V_261 ;
}
V_44 = F_53 ( V_27 ) ;
if ( ! V_44 )
return V_261 ;
switch ( V_256 ) {
case V_258 :
F_107 (in_dev) {
F_76 ( V_134 ) ;
} F_108 ( V_44 ) ;
#ifdef F_35
F_102 ( V_27 ) ;
#endif
F_103 ( & V_1 -> V_10 . V_259 ) ;
F_13 ( V_1 ) ;
break;
case V_260 :
F_98 ( V_27 , 0 ) ;
break;
case V_263 :
case V_264 :
F_13 ( V_1 ) ;
break;
}
return V_261 ;
}
static int T_1 F_109 ( struct V_1 * V_1 )
{
int V_155 ;
T_6 V_265 = sizeof( struct V_22 ) * V_21 ;
V_265 = F_110 ( T_6 , V_265 , V_266 ) ;
V_1 -> V_10 . V_11 = F_54 ( V_265 , V_145 ) ;
if ( V_1 -> V_10 . V_11 == NULL )
return - V_6 ;
V_155 = F_1 ( V_1 ) ;
if ( V_155 < 0 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_1 -> V_10 . V_11 ) ;
return V_155 ;
}
static void F_111 ( struct V_1 * V_1 )
{
unsigned int V_267 ;
#ifdef F_112
F_113 ( V_1 ) ;
#endif
F_57 () ;
for ( V_267 = 0 ; V_267 < V_21 ; V_267 ++ ) {
struct V_2 * V_15 ;
struct V_22 * V_23 ;
struct V_268 * V_269 ;
V_23 = & V_1 -> V_10 . V_11 [ V_267 ] ;
F_114 (tb, tmp, head, tb_hlist) {
F_115 ( & V_15 -> V_9 ) ;
F_12 ( V_15 ) ;
F_116 ( V_15 ) ;
}
}
F_60 () ;
F_4 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_117 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_118
V_1 -> V_10 . F_41 = 0 ;
#endif
error = F_109 ( V_1 ) ;
if ( error < 0 )
goto V_205;
error = F_94 ( V_1 ) ;
if ( error < 0 )
goto V_270;
error = F_119 ( V_1 ) ;
if ( error < 0 )
goto V_271;
V_205:
return error ;
V_271:
F_96 ( V_1 ) ;
V_270:
F_111 ( V_1 ) ;
goto V_205;
}
static void T_7 F_120 ( struct V_1 * V_1 )
{
F_121 ( V_1 ) ;
F_96 ( V_1 ) ;
F_111 ( V_1 ) ;
}
void T_8 F_122 ( void )
{
F_123 ( V_272 , V_210 , F_70 , NULL , NULL ) ;
F_123 ( V_272 , V_232 , F_68 , NULL , NULL ) ;
F_123 ( V_272 , V_273 , NULL , F_71 , NULL ) ;
F_124 ( & V_274 ) ;
F_125 ( & V_275 ) ;
F_126 ( & V_276 ) ;
F_127 () ;
}
