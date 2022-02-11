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
V_168 = F_71 ( V_1 , V_15 , & V_112 ) ;
else
V_168 = - V_173 ;
} else {
V_15 = F_5 ( V_1 , V_112 . V_144 ) ;
if ( V_15 )
V_168 = F_72 ( V_1 , V_15 , & V_112 ) ;
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
struct V_175 * V_176 , struct V_111 * V_112 )
{
struct V_102 * V_177 ;
int V_168 , V_178 ;
struct V_179 * V_180 ;
V_168 = F_76 ( V_176 , sizeof( * V_180 ) , V_181 , V_182 ) ;
if ( V_168 < 0 )
goto V_183;
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
V_180 = F_77 ( V_176 ) ;
V_112 -> V_123 = V_180 -> V_184 ;
V_112 -> V_185 = V_180 -> V_186 ;
V_112 -> V_144 = V_180 -> V_187 ;
V_112 -> V_128 = V_180 -> V_188 ;
V_112 -> V_133 = V_180 -> V_189 ;
V_112 -> V_134 = V_180 -> V_190 ;
V_112 -> V_191 = V_180 -> V_192 ;
V_112 -> V_126 = V_176 -> V_193 ;
V_112 -> V_114 . V_194 = F_78 ( V_49 ) . V_194 ;
V_112 -> V_114 . V_176 = V_176 ;
V_112 -> V_114 . V_115 = V_1 ;
if ( V_112 -> V_134 > V_195 ) {
V_168 = - V_95 ;
goto V_183;
}
F_79 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_107 ( V_177 ) ) {
case V_196 :
V_112 -> V_124 = F_80 ( V_177 ) ;
break;
case V_197 :
V_112 -> V_143 = F_81 ( V_177 ) ;
break;
case V_198 :
V_112 -> V_153 = F_80 ( V_177 ) ;
break;
case V_199 :
V_112 -> V_131 = F_81 ( V_177 ) ;
break;
case V_200 :
V_112 -> V_149 = F_80 ( V_177 ) ;
break;
case V_201 :
V_112 -> V_165 = F_59 ( V_177 ) ;
V_112 -> V_166 = V_108 ( V_177 ) ;
break;
case V_202 :
V_168 = F_82 ( F_59 ( V_177 ) ,
V_108 ( V_177 ) ) ;
if ( V_168 < 0 )
goto V_183;
V_112 -> V_203 = F_59 ( V_177 ) ;
V_112 -> V_204 = V_108 ( V_177 ) ;
break;
case V_205 :
V_112 -> V_206 = F_81 ( V_177 ) ;
break;
case V_207 :
V_112 -> V_144 = F_81 ( V_177 ) ;
break;
case V_208 :
V_112 -> V_209 = V_177 ;
break;
case V_210 :
V_112 -> V_211 = F_83 ( V_177 ) ;
V_168 = F_84 ( V_112 -> V_211 ) ;
if ( V_168 < 0 )
goto V_183;
break;
}
}
return 0 ;
V_183:
return V_168 ;
}
static int F_85 ( struct V_48 * V_49 , struct V_175 * V_176 )
{
struct V_1 * V_1 = F_86 ( V_49 -> V_212 ) ;
struct V_111 V_112 ;
struct V_2 * V_15 ;
int V_168 ;
V_168 = F_75 ( V_1 , V_49 , V_176 , & V_112 ) ;
if ( V_168 < 0 )
goto V_183;
V_15 = F_6 ( V_1 , V_112 . V_144 ) ;
if ( ! V_15 ) {
V_168 = - V_173 ;
goto V_183;
}
V_168 = F_71 ( V_1 , V_15 , & V_112 ) ;
V_183:
return V_168 ;
}
static int F_87 ( struct V_48 * V_49 , struct V_175 * V_176 )
{
struct V_1 * V_1 = F_86 ( V_49 -> V_212 ) ;
struct V_111 V_112 ;
struct V_2 * V_15 ;
int V_168 ;
V_168 = F_75 ( V_1 , V_49 , V_176 , & V_112 ) ;
if ( V_168 < 0 )
goto V_183;
V_15 = F_5 ( V_1 , V_112 . V_144 ) ;
if ( ! V_15 ) {
V_168 = - V_174 ;
goto V_183;
}
V_168 = F_72 ( V_1 , V_15 , & V_112 ) ;
V_183:
return V_168 ;
}
static int F_88 ( struct V_48 * V_49 , struct V_213 * V_214 )
{
struct V_1 * V_1 = F_86 ( V_49 -> V_212 ) ;
unsigned int V_17 , V_215 ;
unsigned int V_216 = 0 , V_217 ;
struct V_2 * V_15 ;
struct V_23 * V_24 ;
int V_218 = 0 ;
if ( F_89 ( V_214 -> V_176 ) >= sizeof( struct V_179 ) &&
( (struct V_179 * ) F_77 ( V_214 -> V_176 ) ) -> V_192 & V_219 )
return V_49 -> V_104 ;
V_215 = V_214 -> args [ 0 ] ;
V_217 = V_214 -> args [ 1 ] ;
F_23 () ;
for ( V_17 = V_215 ; V_17 < V_22 ; V_17 ++ , V_217 = 0 ) {
V_216 = 0 ;
V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_216 < V_217 )
goto V_220;
if ( V_218 )
memset ( & V_214 -> args [ 2 ] , 0 , sizeof( V_214 -> args ) -
2 * sizeof( V_214 -> args [ 0 ] ) ) ;
if ( F_90 ( V_15 , V_49 , V_214 ) < 0 )
goto V_221;
V_218 = 1 ;
V_220:
V_216 ++ ;
}
}
V_221:
F_25 () ;
V_214 -> args [ 1 ] = V_216 ;
V_214 -> args [ 0 ] = V_17 ;
return V_49 -> V_104 ;
}
static void F_91 ( int V_109 , int type , T_3 V_70 , int V_222 , struct V_145 * V_146 )
{
struct V_1 * V_1 = F_36 ( V_146 -> V_223 -> V_32 ) ;
T_2 V_25 = F_29 ( V_146 -> V_223 -> V_32 ) ;
struct V_2 * V_15 ;
struct V_111 V_112 = {
. V_128 = V_224 ,
. V_134 = type ,
. V_124 = V_70 ,
. V_123 = V_222 ,
. V_149 = V_146 -> V_150 ,
. V_143 = V_146 -> V_223 -> V_32 -> V_86 ,
. V_126 = V_127 | V_225 ,
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
if ( V_109 == V_226 )
F_72 ( V_1 , V_15 , & V_112 ) ;
else
F_71 ( V_1 , V_15 , & V_112 ) ;
}
void F_92 ( struct V_145 * V_146 )
{
struct V_50 * V_51 = V_146 -> V_223 ;
struct V_31 * V_32 = V_51 -> V_32 ;
struct V_145 * V_227 = V_146 ;
T_3 V_121 = V_146 -> V_228 ;
T_3 V_33 = V_146 -> V_150 ;
T_3 V_229 = V_146 -> V_230 & V_121 ;
if ( V_146 -> V_231 & V_232 ) {
V_227 = F_93 ( V_51 , V_229 , V_121 ) ;
if ( ! V_227 ) {
F_94 ( L_1 , V_233 ) ;
return;
}
}
F_91 ( V_226 , V_84 , V_33 , 32 , V_227 ) ;
if ( ! ( V_32 -> V_234 & V_235 ) )
return;
if ( V_146 -> V_236 && V_146 -> V_236 != F_95 ( 0xFFFFFFFF ) )
F_91 ( V_226 , V_40 , V_146 -> V_236 , 32 , V_227 ) ;
if ( ! F_20 ( V_229 ) && ! ( V_146 -> V_231 & V_232 ) &&
( V_229 != V_33 || V_146 -> V_237 < 32 ) ) {
if ( ! ( V_146 -> V_231 & V_238 ) )
F_91 ( V_226 ,
V_32 -> V_234 & V_239 ? V_84 : V_43 ,
V_229 , V_146 -> V_237 , V_227 ) ;
if ( V_146 -> V_237 < 31 ) {
F_91 ( V_226 , V_40 , V_229 , 32 , V_227 ) ;
F_91 ( V_226 , V_40 , V_229 | ~ V_121 ,
32 , V_227 ) ;
}
}
}
void F_96 ( struct V_145 * V_146 , struct V_145 * V_240 )
{
struct V_50 * V_51 = V_146 -> V_223 ;
struct V_31 * V_32 = V_51 -> V_32 ;
struct V_145 * V_241 ;
struct V_145 * V_227 = V_146 , * V_242 = NULL ;
T_3 V_243 = V_146 -> V_230 | ~ V_146 -> V_228 ;
T_3 V_244 = V_146 -> V_230 & V_146 -> V_228 ;
#define F_97 1
#define F_98 2
#define F_99 4
#define F_100 8
unsigned int V_245 = 0 ;
int V_246 = 0 ;
int V_247 = 1 ;
int V_248 = 0 ;
if ( V_146 -> V_231 & V_232 ) {
V_227 = F_93 ( V_51 , V_244 , V_146 -> V_228 ) ;
if ( ! V_227 ) {
if ( ! V_51 -> V_249 )
F_94 ( L_1 , V_233 ) ;
return;
}
if ( V_240 && V_240 != V_227 ) {
F_94 ( L_2 , V_233 ) ;
return;
}
} else if ( ! F_20 ( V_244 ) &&
( V_244 != V_146 -> V_150 || V_146 -> V_237 < 32 ) ) {
if ( ! ( V_146 -> V_231 & V_238 ) )
F_91 ( V_250 ,
V_32 -> V_234 & V_239 ? V_84 : V_43 ,
V_244 , V_146 -> V_237 , V_227 ) ;
V_246 = 1 ;
}
if ( V_51 -> V_249 )
goto V_251;
for ( V_241 = V_51 -> V_82 ; V_241 ; V_241 = V_241 -> V_147 ) {
if ( V_241 == V_146 ) {
V_247 = 0 ;
continue;
}
if ( V_240 && V_241 -> V_228 == V_240 -> V_228 &&
F_101 ( V_241 -> V_230 , V_240 ) )
continue;
if ( V_241 -> V_231 & V_232 ) {
if ( V_241 -> V_228 == V_227 -> V_228 &&
F_101 ( V_241 -> V_230 , V_227 ) )
V_242 = V_227 ;
else {
if ( ! V_248 )
continue;
if ( ! V_242 ||
V_241 -> V_228 != V_242 -> V_228 ||
! F_101 ( V_241 -> V_230 , V_242 ) )
V_242 = F_93 ( V_51 ,
V_241 -> V_230 ,
V_241 -> V_228 ) ;
if ( ! V_242 )
continue;
if ( V_242 -> V_150 != V_227 -> V_150 )
continue;
}
} else {
if ( V_227 -> V_150 != V_241 -> V_150 )
continue;
V_242 = V_241 ;
if ( V_227 != V_242 )
V_248 = 1 ;
}
if ( V_146 -> V_150 == V_241 -> V_150 )
V_245 |= F_97 ;
if ( V_146 -> V_236 == V_241 -> V_236 )
V_245 |= F_98 ;
if ( V_243 == V_241 -> V_236 )
V_245 |= F_100 ;
if ( V_244 == V_241 -> V_236 )
V_245 |= F_99 ;
if ( V_242 == V_241 && V_241 -> V_237 < 31 ) {
T_3 V_252 = V_241 -> V_230 | ~ V_241 -> V_228 ;
T_3 V_253 = V_241 -> V_230 & V_241 -> V_228 ;
if ( ! F_20 ( V_253 ) ) {
if ( V_146 -> V_236 == V_252 ||
V_146 -> V_236 == V_253 )
V_245 |= F_98 ;
if ( V_243 == V_252 || V_243 == V_253 )
V_245 |= F_100 ;
if ( V_244 == V_252 || V_244 == V_253 )
V_245 |= F_99 ;
}
}
}
V_251:
if ( ! ( V_245 & F_98 ) )
F_91 ( V_250 , V_40 , V_146 -> V_236 , 32 , V_227 ) ;
if ( V_246 && V_146 -> V_237 < 31 ) {
if ( ! ( V_245 & F_100 ) )
F_91 ( V_250 , V_40 , V_243 , 32 , V_227 ) ;
if ( ! ( V_245 & F_99 ) )
F_91 ( V_250 , V_40 , V_244 , 32 , V_227 ) ;
}
if ( ! ( V_245 & F_97 ) ) {
unsigned int V_152 ;
F_91 ( V_250 , V_84 , V_146 -> V_150 , 32 , V_227 ) ;
V_152 = F_30 ( F_36 ( V_32 ) , V_32 ,
V_146 -> V_150 ) ;
if ( V_247 && V_152 != V_84 ) {
if ( F_102 ( V_32 , V_146 -> V_150 ) )
F_15 ( F_36 ( V_32 ) ) ;
}
}
#undef F_97
#undef F_98
#undef F_99
#undef F_100
}
static void F_103 ( struct V_1 * V_1 , struct V_254 * V_255 )
{
struct V_37 V_38 ;
struct V_34 V_35 = {
. V_66 = V_255 -> V_256 ,
. V_36 = V_255 -> V_257 ,
. V_63 = V_255 -> V_258 ,
. V_65 = V_255 -> V_259 ,
} ;
struct V_2 * V_15 ;
F_23 () ;
V_15 = F_6 ( V_1 , V_255 -> V_260 ) ;
V_255 -> V_168 = - V_261 ;
if ( V_15 ) {
F_104 () ;
V_255 -> V_25 = V_15 -> V_25 ;
V_255 -> V_168 = F_24 ( V_15 , & V_35 , & V_38 , V_44 ) ;
if ( ! V_255 -> V_168 ) {
V_255 -> V_262 = V_38 . V_262 ;
V_255 -> V_263 = V_38 . V_263 ;
V_255 -> type = V_38 . type ;
V_255 -> V_54 = V_38 . V_54 ;
}
F_105 () ;
}
F_25 () ;
}
static void F_106 ( struct V_48 * V_49 )
{
struct V_1 * V_1 ;
struct V_254 * V_255 ;
struct V_175 * V_176 ;
T_2 V_194 ;
V_1 = F_86 ( V_49 -> V_212 ) ;
V_176 = F_107 ( V_49 ) ;
if ( V_49 -> V_104 < F_108 ( sizeof( * V_255 ) ) ||
V_49 -> V_104 < V_176 -> F_89 ||
F_89 ( V_176 ) < sizeof( * V_255 ) )
return;
V_49 = F_109 ( V_49 , V_158 ) ;
if ( ! V_49 )
return;
V_176 = F_107 ( V_49 ) ;
V_255 = (struct V_254 * ) F_77 ( V_176 ) ;
F_103 ( V_1 , V_255 ) ;
V_194 = F_78 ( V_49 ) . V_194 ;
F_78 ( V_49 ) . V_194 = 0 ;
F_78 ( V_49 ) . V_264 = 0 ;
F_110 ( V_1 -> V_10 . V_265 , V_49 , V_194 , V_266 ) ;
}
static int T_1 F_111 ( struct V_1 * V_1 )
{
struct V_267 * V_212 ;
struct V_268 V_112 = {
. V_269 = F_106 ,
} ;
V_212 = F_112 ( V_1 , V_270 , & V_112 ) ;
if ( ! V_212 )
return - V_119 ;
V_1 -> V_10 . V_265 = V_212 ;
return 0 ;
}
static void F_113 ( struct V_1 * V_1 )
{
F_114 ( V_1 -> V_10 . V_265 ) ;
V_1 -> V_10 . V_265 = NULL ;
}
static void F_115 ( struct V_31 * V_32 , unsigned long V_271 ,
bool V_272 )
{
if ( F_116 ( V_32 , V_271 , V_272 ) )
F_15 ( F_36 ( V_32 ) ) ;
F_18 ( F_36 ( V_32 ) ) ;
F_117 ( V_32 ) ;
}
static int F_118 ( struct V_273 * V_274 , unsigned long V_271 , void * V_275 )
{
struct V_145 * V_146 = (struct V_145 * ) V_275 ;
struct V_31 * V_32 = V_146 -> V_223 -> V_32 ;
struct V_1 * V_1 = F_36 ( V_32 ) ;
switch ( V_271 ) {
case V_276 :
F_92 ( V_146 ) ;
#ifdef F_50
F_119 ( V_32 , V_277 ) ;
#endif
F_120 ( & V_1 -> V_10 . V_278 ) ;
F_18 ( F_36 ( V_32 ) ) ;
break;
case V_279 :
F_96 ( V_146 , NULL ) ;
F_120 ( & V_1 -> V_10 . V_278 ) ;
if ( ! V_146 -> V_223 -> V_82 ) {
F_115 ( V_32 , V_271 , true ) ;
} else {
F_18 ( F_36 ( V_32 ) ) ;
}
break;
}
return V_280 ;
}
static int F_121 ( struct V_273 * V_274 , unsigned long V_271 , void * V_275 )
{
struct V_31 * V_32 = F_122 ( V_275 ) ;
struct V_281 * V_282 ;
struct V_50 * V_51 ;
struct V_1 * V_1 = F_36 ( V_32 ) ;
unsigned int V_234 ;
if ( V_271 == V_283 ) {
F_115 ( V_32 , V_271 , true ) ;
F_123 ( V_32 ) ;
return V_280 ;
}
V_51 = F_66 ( V_32 ) ;
if ( ! V_51 )
return V_280 ;
switch ( V_271 ) {
case V_276 :
F_124 (in_dev) {
F_92 ( V_146 ) ;
} F_125 ( V_51 ) ;
#ifdef F_50
F_119 ( V_32 , V_277 ) ;
#endif
F_120 ( & V_1 -> V_10 . V_278 ) ;
F_18 ( V_1 ) ;
break;
case V_279 :
F_115 ( V_32 , V_271 , false ) ;
break;
case V_284 :
V_234 = F_126 ( V_32 ) ;
if ( V_234 & ( V_285 | V_286 ) )
F_119 ( V_32 , V_287 ) ;
else
F_116 ( V_32 , V_271 , false ) ;
case V_288 :
F_18 ( V_1 ) ;
break;
case V_289 :
V_282 = V_275 ;
if ( V_282 -> V_290 && F_127 ( V_282 -> V_290 ) )
F_115 ( V_32 , V_279 , true ) ;
break;
}
return V_280 ;
}
static int T_1 F_128 ( struct V_1 * V_1 )
{
int V_168 ;
T_6 V_291 = sizeof( struct V_23 ) * V_22 ;
V_1 -> V_10 . V_292 = 0 ;
V_291 = F_129 ( T_6 , V_291 , V_293 ) ;
V_1 -> V_10 . V_11 = F_67 ( V_291 , V_158 ) ;
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
static void F_130 ( struct V_1 * V_1 )
{
unsigned int V_294 ;
F_70 () ;
#ifdef F_10
F_131 ( V_1 -> V_10 . V_19 , NULL ) ;
F_131 ( V_1 -> V_10 . V_21 , NULL ) ;
#endif
for ( V_294 = 0 ; V_294 < V_22 ; V_294 ++ ) {
struct V_23 * V_24 = & V_1 -> V_10 . V_11 [ V_294 ] ;
struct V_29 * V_30 ;
struct V_2 * V_15 ;
F_16 (tb, tmp, head, tb_hlist) {
F_132 ( & V_15 -> V_9 ) ;
F_17 ( V_1 , V_15 ) ;
F_4 ( V_15 ) ;
}
}
#ifdef F_10
F_133 ( V_1 ) ;
#endif
F_74 () ;
F_73 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_134 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_135
V_1 -> V_10 . F_47 = 0 ;
#endif
error = F_128 ( V_1 ) ;
if ( error < 0 )
goto V_221;
error = F_111 ( V_1 ) ;
if ( error < 0 )
goto V_295;
error = F_136 ( V_1 ) ;
if ( error < 0 )
goto V_296;
V_221:
return error ;
V_296:
F_113 ( V_1 ) ;
V_295:
F_130 ( V_1 ) ;
goto V_221;
}
static void T_7 F_137 ( struct V_1 * V_1 )
{
F_138 ( V_1 ) ;
F_113 ( V_1 ) ;
F_130 ( V_1 ) ;
}
void T_8 F_139 ( void )
{
F_140 ( V_297 , V_226 , F_87 , NULL , NULL ) ;
F_140 ( V_297 , V_250 , F_85 , NULL , NULL ) ;
F_140 ( V_297 , V_298 , NULL , F_88 , NULL ) ;
F_141 ( & V_299 ) ;
F_142 ( & V_300 ) ;
F_143 ( & V_301 ) ;
F_144 () ;
}
