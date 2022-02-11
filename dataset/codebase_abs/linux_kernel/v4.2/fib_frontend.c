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
if ( V_14 == V_7 )
V_16 = F_5 ( V_1 , V_5 ) ;
V_15 = F_2 ( V_14 , V_16 ) ;
if ( ! V_15 )
return NULL ;
switch ( V_14 ) {
case V_7 :
F_7 ( V_1 -> V_10 . V_18 , V_15 ) ;
break;
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
case V_7 :
F_7 ( V_1 -> V_10 . V_18 , V_27 ) ;
break;
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
struct V_2 * V_26 , * V_27 ;
V_26 = F_6 ( V_1 , V_7 ) ;
if ( ! V_26 )
return 0 ;
V_27 = F_13 ( V_26 ) ;
if ( ! V_27 )
return - V_6 ;
if ( V_27 != V_26 ) {
F_9 ( V_1 , V_26 , V_27 ) ;
F_4 ( V_26 ) ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_1 )
{
int V_28 = 0 ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
struct V_23 * V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
struct V_29 * V_30 ;
struct V_2 * V_15 ;
F_15 (tb, tmp, head, tb_hlist)
V_28 += F_16 ( V_15 ) ;
}
if ( V_28 )
F_17 ( V_1 ) ;
}
void F_18 ( struct V_1 * V_1 )
{
struct V_2 * V_15 ;
struct V_23 * V_24 ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_19 (tb, head, tb_hlist)
F_20 ( V_15 ) ;
}
}
static inline unsigned int F_21 ( struct V_1 * V_1 ,
const struct V_31 * V_32 ,
T_3 V_33 )
{
struct V_34 V_35 = { . V_36 = V_33 } ;
struct V_37 V_38 ;
unsigned int V_39 = V_40 ;
struct V_2 * V_3 ;
if ( F_22 ( V_33 ) || F_23 ( V_33 ) )
return V_40 ;
if ( F_24 ( V_33 ) )
return V_41 ;
F_25 () ;
V_3 = F_6 ( V_1 , V_7 ) ;
if ( V_3 ) {
V_39 = V_42 ;
if ( ! F_26 ( V_3 , & V_35 , & V_38 , V_43 ) ) {
if ( ! V_32 || V_32 == V_38 . V_44 -> V_45 )
V_39 = V_38 . type ;
}
}
F_27 () ;
return V_39 ;
}
unsigned int F_28 ( struct V_1 * V_1 , T_3 V_33 )
{
return F_21 ( V_1 , NULL , V_33 ) ;
}
unsigned int F_29 ( struct V_1 * V_1 , const struct V_31 * V_32 ,
T_3 V_33 )
{
return F_21 ( V_1 , V_32 , V_33 ) ;
}
T_3 F_30 ( struct V_46 * V_47 )
{
struct V_31 * V_32 = V_47 -> V_32 ;
struct V_48 * V_49 ;
struct V_37 V_38 ;
struct V_50 * V_51 ;
struct V_34 V_35 ;
struct V_1 * V_1 ;
int V_52 ;
V_51 = F_31 ( V_47 ) ;
if ( ( V_51 -> V_53 & ( V_54 | V_55 | V_56 ) ) ==
V_56 )
return F_32 ( V_47 ) -> V_36 ;
V_49 = F_33 ( V_32 ) ;
F_34 ( ! V_49 ) ;
V_1 = F_35 ( V_32 ) ;
V_52 = V_57 ;
if ( ! F_22 ( F_32 ( V_47 ) -> V_58 ) ) {
V_35 . V_59 = 0 ;
V_35 . V_60 = V_61 ;
V_35 . V_36 = F_32 ( V_47 ) -> V_58 ;
V_35 . V_58 = 0 ;
V_35 . V_62 = F_36 ( F_32 ( V_47 ) -> V_63 ) ;
V_35 . V_64 = V_52 ;
V_35 . V_65 = F_37 ( V_49 ) ? V_47 -> V_66 : 0 ;
if ( ! F_38 ( V_1 , & V_35 , & V_38 , 0 ) )
return F_39 ( V_1 , V_38 ) ;
} else {
V_52 = V_67 ;
}
return F_40 ( V_32 , F_32 ( V_47 ) -> V_58 , V_52 ) ;
}
static int F_41 ( struct V_46 * V_47 , T_3 V_68 , T_3 V_69 ,
T_4 V_63 , int V_70 , struct V_31 * V_32 ,
int V_71 , struct V_48 * V_72 , T_2 * V_73 )
{
int V_39 , V_74 ;
struct V_37 V_38 ;
struct V_34 V_35 ;
struct V_1 * V_1 ;
bool V_75 ;
V_35 . V_59 = 0 ;
V_35 . V_60 = V_70 ? : V_61 ;
V_35 . V_36 = V_68 ;
V_35 . V_58 = V_69 ;
V_35 . V_62 = V_63 ;
V_35 . V_64 = V_57 ;
V_74 = V_72 -> V_76 == NULL ;
V_35 . V_65 = F_37 ( V_72 ) ? V_47 -> V_66 : 0 ;
V_1 = F_35 ( V_32 ) ;
if ( F_38 ( V_1 , & V_35 , & V_38 , 0 ) )
goto V_77;
if ( V_38 . type != V_42 &&
( V_38 . type != V_78 || ! F_42 ( V_72 ) ) )
goto V_79;
if ( ! V_71 && ! F_43 ( F_35 ( V_32 ) ) &&
( V_32 -> V_80 != V_70 || ! F_44 ( V_72 ) ) )
goto V_77;
F_45 ( V_73 , & V_38 ) ;
V_75 = false ;
#ifdef F_46
for ( V_39 = 0 ; V_39 < V_38 . V_44 -> V_81 ; V_39 ++ ) {
struct V_82 * V_83 = & V_38 . V_44 -> V_82 [ V_39 ] ;
if ( V_83 -> V_84 == V_32 ) {
V_75 = true ;
break;
}
}
#else
if ( F_47 ( V_38 ) == V_32 )
V_75 = true ;
#endif
if ( V_75 ) {
V_39 = F_48 ( V_38 ) . V_85 >= V_86 ;
return V_39 ;
}
if ( V_74 )
goto V_77;
if ( V_71 == 1 )
goto V_87;
V_35 . V_59 = V_32 -> V_80 ;
V_39 = 0 ;
if ( F_38 ( V_1 , & V_35 , & V_38 , V_88 ) == 0 ) {
if ( V_38 . type == V_42 )
V_39 = F_48 ( V_38 ) . V_85 >= V_86 ;
}
return V_39 ;
V_77:
if ( V_71 )
goto V_87;
* V_73 = 0 ;
return 0 ;
V_79:
return - V_89 ;
V_87:
return - V_90 ;
}
int F_49 ( struct V_46 * V_47 , T_3 V_68 , T_3 V_69 ,
T_4 V_63 , int V_70 , struct V_31 * V_32 ,
struct V_48 * V_72 , T_2 * V_73 )
{
int V_91 = F_50 ( V_47 ) ? 0 : F_51 ( V_72 ) ;
if ( ! V_91 && ! F_43 ( F_35 ( V_32 ) ) &&
F_42 ( V_72 ) &&
( V_32 -> V_80 != V_70 || ! F_44 ( V_72 ) ) ) {
* V_73 = 0 ;
return 0 ;
}
return F_41 ( V_47 , V_68 , V_69 , V_63 , V_70 , V_32 , V_91 , V_72 , V_73 ) ;
}
static inline T_3 F_52 ( struct V_92 * V_33 )
{
return ( (struct V_93 * ) V_33 ) -> V_94 . V_95 ;
}
static int F_53 ( struct V_96 * V_97 , int V_98 , int type , T_2 V_99 )
{
struct V_96 * V_100 ;
V_100 = (struct V_96 * ) ( ( char * ) V_97 + V_98 ) ;
V_100 -> V_101 = type ;
V_100 -> V_102 = F_54 ( 4 ) ;
* ( T_2 * ) F_55 ( V_100 ) = V_99 ;
return V_98 + F_56 ( 4 ) ;
}
static int F_57 ( struct V_1 * V_1 , int V_103 , struct V_104 * V_51 ,
struct V_105 * V_106 )
{
T_3 V_33 ;
int V_107 ;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_106 -> V_108 . V_109 = V_1 ;
if ( V_51 -> V_110 . V_111 != V_112 )
return - V_113 ;
V_107 = 32 ;
V_33 = F_52 ( & V_51 -> V_110 ) ;
if ( ! ( V_51 -> V_53 & V_114 ) ) {
T_3 V_115 = F_52 ( & V_51 -> V_116 ) ;
if ( V_51 -> V_116 . V_111 != V_112 ) {
if ( V_115 || V_51 -> V_116 . V_111 )
return - V_113 ;
}
if ( F_58 ( V_115 , V_33 ) )
return - V_89 ;
V_107 = F_59 ( V_115 ) ;
}
V_106 -> V_117 = V_107 ;
V_106 -> V_118 = V_33 ;
if ( V_103 != V_119 ) {
V_106 -> V_120 = V_121 ;
V_106 -> V_122 = V_123 ;
}
if ( V_51 -> V_124 )
V_106 -> V_125 = V_51 -> V_124 - 1 ;
if ( V_51 -> V_53 & V_126 ) {
V_106 -> V_127 = V_86 ;
V_106 -> V_128 = V_129 ;
return 0 ;
}
V_106 -> V_127 = V_130 ;
V_106 -> V_128 = V_42 ;
if ( V_51 -> V_131 ) {
char * V_132 ;
struct V_31 * V_32 ;
char V_133 [ V_134 ] ;
if ( F_60 ( V_133 , V_51 -> V_131 , V_134 - 1 ) )
return - V_135 ;
V_133 [ V_134 - 1 ] = 0 ;
V_132 = strchr ( V_133 , ':' ) ;
if ( V_132 )
* V_132 = 0 ;
V_32 = F_61 ( V_1 , V_133 ) ;
if ( ! V_32 )
return - V_136 ;
V_106 -> V_137 = V_32 -> V_80 ;
if ( V_132 ) {
struct V_138 * V_139 ;
struct V_48 * V_49 = F_62 ( V_32 ) ;
if ( ! V_49 )
return - V_136 ;
* V_132 = ':' ;
for ( V_139 = V_49 -> V_76 ; V_139 ; V_139 = V_139 -> V_140 )
if ( strcmp ( V_139 -> V_141 , V_133 ) == 0 )
break;
if ( ! V_139 )
return - V_136 ;
V_106 -> V_142 = V_139 -> V_143 ;
}
}
V_33 = F_52 ( & V_51 -> V_144 ) ;
if ( V_51 -> V_144 . V_111 == V_112 && V_33 ) {
V_106 -> V_145 = V_33 ;
if ( V_51 -> V_53 & V_146 &&
F_28 ( V_1 , V_33 ) == V_42 )
V_106 -> V_127 = V_57 ;
}
if ( V_103 == V_119 )
return 0 ;
if ( V_51 -> V_53 & V_146 && ! V_106 -> V_145 )
return - V_89 ;
if ( V_106 -> V_127 == V_130 )
V_106 -> V_127 = V_67 ;
if ( V_51 -> V_53 & ( V_147 | V_148 | V_149 ) ) {
struct V_96 * V_97 ;
int V_98 = 0 ;
V_97 = F_63 ( 3 * F_56 ( 4 ) , V_150 ) ;
if ( ! V_97 )
return - V_6 ;
if ( V_51 -> V_53 & V_147 )
V_98 = F_53 ( V_97 , V_98 , V_151 , V_51 -> V_152 - 40 ) ;
if ( V_51 -> V_53 & V_148 )
V_98 = F_53 ( V_97 , V_98 , V_153 , V_51 -> V_154 ) ;
if ( V_51 -> V_53 & V_149 )
V_98 = F_53 ( V_97 , V_98 , V_155 , V_51 -> V_156 << 3 ) ;
V_106 -> V_157 = V_97 ;
V_106 -> V_158 = V_98 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_1 , unsigned int V_103 , void T_5 * V_159 )
{
struct V_105 V_106 ;
struct V_104 V_51 ;
int V_160 ;
switch ( V_103 ) {
case V_161 :
case V_119 :
if ( ! F_65 ( V_1 -> V_162 , V_163 ) )
return - V_164 ;
if ( F_60 ( & V_51 , V_159 , sizeof( V_51 ) ) )
return - V_135 ;
F_66 () ;
V_160 = F_57 ( V_1 , V_103 , & V_51 , & V_106 ) ;
if ( V_160 == 0 ) {
struct V_2 * V_15 ;
if ( V_103 == V_119 ) {
V_15 = F_6 ( V_1 , V_106 . V_165 ) ;
if ( V_15 )
V_160 = F_67 ( V_15 , & V_106 ) ;
else
V_160 = - V_166 ;
} else {
V_15 = F_5 ( V_1 , V_106 . V_165 ) ;
if ( V_15 )
V_160 = F_68 ( V_15 , & V_106 ) ;
else
V_160 = - V_167 ;
}
F_69 ( V_106 . V_157 ) ;
}
F_70 () ;
return V_160 ;
}
return - V_89 ;
}
static int F_71 ( struct V_1 * V_1 , struct V_46 * V_47 ,
struct V_168 * V_169 , struct V_105 * V_106 )
{
struct V_96 * V_170 ;
int V_160 , V_171 ;
struct V_172 * V_173 ;
V_160 = F_72 ( V_169 , sizeof( * V_173 ) , V_174 , V_175 ) ;
if ( V_160 < 0 )
goto V_176;
memset ( V_106 , 0 , sizeof( * V_106 ) ) ;
V_173 = F_73 ( V_169 ) ;
V_106 -> V_117 = V_173 -> V_177 ;
V_106 -> V_178 = V_173 -> V_179 ;
V_106 -> V_165 = V_173 -> V_180 ;
V_106 -> V_122 = V_173 -> V_181 ;
V_106 -> V_127 = V_173 -> V_182 ;
V_106 -> V_128 = V_173 -> V_183 ;
V_106 -> V_184 = V_173 -> V_185 ;
V_106 -> V_120 = V_169 -> V_186 ;
V_106 -> V_108 . V_187 = F_74 ( V_47 ) . V_187 ;
V_106 -> V_108 . V_169 = V_169 ;
V_106 -> V_108 . V_109 = V_1 ;
if ( V_106 -> V_128 > V_188 ) {
V_160 = - V_89 ;
goto V_176;
}
F_75 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_101 ( V_170 ) ) {
case V_189 :
V_106 -> V_118 = F_76 ( V_170 ) ;
break;
case V_190 :
V_106 -> V_137 = F_77 ( V_170 ) ;
break;
case V_191 :
V_106 -> V_145 = F_76 ( V_170 ) ;
break;
case V_192 :
V_106 -> V_125 = F_77 ( V_170 ) ;
break;
case V_193 :
V_106 -> V_142 = F_76 ( V_170 ) ;
break;
case V_194 :
V_106 -> V_157 = F_55 ( V_170 ) ;
V_106 -> V_158 = V_102 ( V_170 ) ;
break;
case V_195 :
V_106 -> V_196 = F_55 ( V_170 ) ;
V_106 -> V_197 = V_102 ( V_170 ) ;
break;
case V_198 :
V_106 -> V_199 = F_77 ( V_170 ) ;
break;
case V_200 :
V_106 -> V_165 = F_77 ( V_170 ) ;
break;
}
}
return 0 ;
V_176:
return V_160 ;
}
static int F_78 ( struct V_46 * V_47 , struct V_168 * V_169 )
{
struct V_1 * V_1 = F_79 ( V_47 -> V_201 ) ;
struct V_105 V_106 ;
struct V_2 * V_15 ;
int V_160 ;
V_160 = F_71 ( V_1 , V_47 , V_169 , & V_106 ) ;
if ( V_160 < 0 )
goto V_176;
V_15 = F_6 ( V_1 , V_106 . V_165 ) ;
if ( ! V_15 ) {
V_160 = - V_166 ;
goto V_176;
}
V_160 = F_67 ( V_15 , & V_106 ) ;
V_176:
return V_160 ;
}
static int F_80 ( struct V_46 * V_47 , struct V_168 * V_169 )
{
struct V_1 * V_1 = F_79 ( V_47 -> V_201 ) ;
struct V_105 V_106 ;
struct V_2 * V_15 ;
int V_160 ;
V_160 = F_71 ( V_1 , V_47 , V_169 , & V_106 ) ;
if ( V_160 < 0 )
goto V_176;
V_15 = F_5 ( V_1 , V_106 . V_165 ) ;
if ( ! V_15 ) {
V_160 = - V_167 ;
goto V_176;
}
V_160 = F_68 ( V_15 , & V_106 ) ;
V_176:
return V_160 ;
}
static int F_81 ( struct V_46 * V_47 , struct V_202 * V_203 )
{
struct V_1 * V_1 = F_79 ( V_47 -> V_201 ) ;
unsigned int V_17 , V_204 ;
unsigned int V_205 = 0 , V_206 ;
struct V_2 * V_15 ;
struct V_23 * V_24 ;
int V_207 = 0 ;
if ( F_82 ( V_203 -> V_169 ) >= sizeof( struct V_172 ) &&
( (struct V_172 * ) F_73 ( V_203 -> V_169 ) ) -> V_185 & V_208 )
return V_47 -> V_98 ;
V_204 = V_203 -> args [ 0 ] ;
V_206 = V_203 -> args [ 1 ] ;
F_25 () ;
for ( V_17 = V_204 ; V_17 < V_22 ; V_17 ++ , V_206 = 0 ) {
V_205 = 0 ;
V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_205 < V_206 )
goto V_209;
if ( V_207 )
memset ( & V_203 -> args [ 2 ] , 0 , sizeof( V_203 -> args ) -
2 * sizeof( V_203 -> args [ 0 ] ) ) ;
if ( F_83 ( V_15 , V_47 , V_203 ) < 0 )
goto V_210;
V_207 = 1 ;
V_209:
V_205 ++ ;
}
}
V_210:
F_27 () ;
V_203 -> args [ 1 ] = V_205 ;
V_203 -> args [ 0 ] = V_17 ;
return V_47 -> V_98 ;
}
static void F_84 ( int V_103 , int type , T_3 V_69 , int V_211 , struct V_138 * V_139 )
{
struct V_1 * V_1 = F_35 ( V_139 -> V_212 -> V_32 ) ;
struct V_2 * V_15 ;
struct V_105 V_106 = {
. V_122 = V_213 ,
. V_128 = type ,
. V_118 = V_69 ,
. V_117 = V_211 ,
. V_142 = V_139 -> V_143 ,
. V_137 = V_139 -> V_212 -> V_32 -> V_80 ,
. V_120 = V_121 | V_214 ,
. V_108 = {
. V_109 = V_1 ,
} ,
} ;
if ( type == V_42 )
V_15 = F_5 ( V_1 , V_5 ) ;
else
V_15 = F_5 ( V_1 , V_7 ) ;
if ( ! V_15 )
return;
V_106 . V_165 = V_15 -> V_25 ;
if ( type != V_78 )
V_106 . V_127 = V_67 ;
else
V_106 . V_127 = V_86 ;
if ( V_103 == V_215 )
F_68 ( V_15 , & V_106 ) ;
else
F_67 ( V_15 , & V_106 ) ;
}
void F_85 ( struct V_138 * V_139 )
{
struct V_48 * V_49 = V_139 -> V_212 ;
struct V_31 * V_32 = V_49 -> V_32 ;
struct V_138 * V_216 = V_139 ;
T_3 V_115 = V_139 -> V_217 ;
T_3 V_33 = V_139 -> V_143 ;
T_3 V_218 = V_139 -> V_219 & V_115 ;
if ( V_139 -> V_220 & V_221 ) {
V_216 = F_86 ( V_49 , V_218 , V_115 ) ;
if ( ! V_216 ) {
F_87 ( L_1 , V_222 ) ;
return;
}
}
F_84 ( V_215 , V_78 , V_33 , 32 , V_216 ) ;
if ( ! ( V_32 -> V_223 & V_224 ) )
return;
if ( V_139 -> V_225 && V_139 -> V_225 != F_88 ( 0xFFFFFFFF ) )
F_84 ( V_215 , V_40 , V_139 -> V_225 , 32 , V_216 ) ;
if ( ! F_22 ( V_218 ) && ! ( V_139 -> V_220 & V_221 ) &&
( V_218 != V_33 || V_139 -> V_226 < 32 ) ) {
F_84 ( V_215 ,
V_32 -> V_223 & V_227 ? V_78 : V_42 ,
V_218 , V_139 -> V_226 , V_216 ) ;
if ( V_139 -> V_226 < 31 ) {
F_84 ( V_215 , V_40 , V_218 , 32 , V_216 ) ;
F_84 ( V_215 , V_40 , V_218 | ~ V_115 ,
32 , V_216 ) ;
}
}
}
void F_89 ( struct V_138 * V_139 , struct V_138 * V_228 )
{
struct V_48 * V_49 = V_139 -> V_212 ;
struct V_31 * V_32 = V_49 -> V_32 ;
struct V_138 * V_229 ;
struct V_138 * V_216 = V_139 , * V_230 = NULL ;
T_3 V_231 = V_139 -> V_219 | ~ V_139 -> V_217 ;
T_3 V_232 = V_139 -> V_219 & V_139 -> V_217 ;
#define F_90 1
#define F_91 2
#define F_92 4
#define F_93 8
unsigned int V_233 = 0 ;
int V_234 = 0 ;
int V_235 = 1 ;
int V_236 = 0 ;
if ( V_139 -> V_220 & V_221 ) {
V_216 = F_86 ( V_49 , V_232 , V_139 -> V_217 ) ;
if ( ! V_216 ) {
F_87 ( L_1 , V_222 ) ;
return;
}
if ( V_228 && V_228 != V_216 ) {
F_87 ( L_2 , V_222 ) ;
return;
}
} else if ( ! F_22 ( V_232 ) &&
( V_232 != V_139 -> V_143 || V_139 -> V_226 < 32 ) ) {
F_84 ( V_237 ,
V_32 -> V_223 & V_227 ? V_78 : V_42 ,
V_232 , V_139 -> V_226 , V_216 ) ;
V_234 = 1 ;
}
for ( V_229 = V_49 -> V_76 ; V_229 ; V_229 = V_229 -> V_140 ) {
if ( V_229 == V_139 ) {
V_235 = 0 ;
continue;
}
if ( V_228 && V_229 -> V_217 == V_228 -> V_217 &&
F_94 ( V_229 -> V_219 , V_228 ) )
continue;
if ( V_229 -> V_220 & V_221 ) {
if ( V_229 -> V_217 == V_216 -> V_217 &&
F_94 ( V_229 -> V_219 , V_216 ) )
V_230 = V_216 ;
else {
if ( ! V_236 )
continue;
if ( ! V_230 ||
V_229 -> V_217 != V_230 -> V_217 ||
! F_94 ( V_229 -> V_219 , V_230 ) )
V_230 = F_86 ( V_49 ,
V_229 -> V_219 ,
V_229 -> V_217 ) ;
if ( ! V_230 )
continue;
if ( V_230 -> V_143 != V_216 -> V_143 )
continue;
}
} else {
if ( V_216 -> V_143 != V_229 -> V_143 )
continue;
V_230 = V_229 ;
if ( V_216 != V_230 )
V_236 = 1 ;
}
if ( V_139 -> V_143 == V_229 -> V_143 )
V_233 |= F_90 ;
if ( V_139 -> V_225 == V_229 -> V_225 )
V_233 |= F_91 ;
if ( V_231 == V_229 -> V_225 )
V_233 |= F_93 ;
if ( V_232 == V_229 -> V_225 )
V_233 |= F_92 ;
if ( V_230 == V_229 && V_229 -> V_226 < 31 ) {
T_3 V_238 = V_229 -> V_219 | ~ V_229 -> V_217 ;
T_3 V_239 = V_229 -> V_219 & V_229 -> V_217 ;
if ( ! F_22 ( V_239 ) ) {
if ( V_139 -> V_225 == V_238 ||
V_139 -> V_225 == V_239 )
V_233 |= F_91 ;
if ( V_231 == V_238 || V_231 == V_239 )
V_233 |= F_93 ;
if ( V_232 == V_238 || V_232 == V_239 )
V_233 |= F_92 ;
}
}
}
if ( ! ( V_233 & F_91 ) )
F_84 ( V_237 , V_40 , V_139 -> V_225 , 32 , V_216 ) ;
if ( V_234 && V_139 -> V_226 < 31 ) {
if ( ! ( V_233 & F_93 ) )
F_84 ( V_237 , V_40 , V_231 , 32 , V_216 ) ;
if ( ! ( V_233 & F_92 ) )
F_84 ( V_237 , V_40 , V_232 , 32 , V_216 ) ;
}
if ( ! ( V_233 & F_90 ) ) {
F_84 ( V_237 , V_78 , V_139 -> V_143 , 32 , V_216 ) ;
if ( V_235 &&
F_28 ( F_35 ( V_32 ) , V_139 -> V_143 ) != V_78 ) {
if ( F_95 ( F_35 ( V_32 ) , V_139 -> V_143 ) )
F_14 ( F_35 ( V_32 ) ) ;
}
}
#undef F_90
#undef F_91
#undef F_92
#undef F_93
}
static void F_96 ( struct V_1 * V_1 , struct V_240 * V_241 )
{
struct V_37 V_38 ;
struct V_34 V_35 = {
. V_65 = V_241 -> V_242 ,
. V_36 = V_241 -> V_243 ,
. V_62 = V_241 -> V_244 ,
. V_64 = V_241 -> V_245 ,
} ;
struct V_2 * V_15 ;
F_25 () ;
V_15 = F_6 ( V_1 , V_241 -> V_246 ) ;
V_241 -> V_160 = - V_247 ;
if ( V_15 ) {
F_97 () ;
V_241 -> V_25 = V_15 -> V_25 ;
V_241 -> V_160 = F_26 ( V_15 , & V_35 , & V_38 , V_43 ) ;
if ( ! V_241 -> V_160 ) {
V_241 -> V_248 = V_38 . V_248 ;
V_241 -> V_249 = V_38 . V_249 ;
V_241 -> type = V_38 . type ;
V_241 -> V_52 = V_38 . V_52 ;
}
F_98 () ;
}
F_27 () ;
}
static void F_99 ( struct V_46 * V_47 )
{
struct V_1 * V_1 ;
struct V_240 * V_241 ;
struct V_168 * V_169 ;
T_2 V_187 ;
V_1 = F_79 ( V_47 -> V_201 ) ;
V_169 = F_100 ( V_47 ) ;
if ( V_47 -> V_98 < V_250 || V_47 -> V_98 < V_169 -> F_82 ||
F_82 ( V_169 ) < sizeof( * V_241 ) )
return;
V_47 = F_101 ( V_47 , V_150 ) ;
if ( ! V_47 )
return;
V_169 = F_100 ( V_47 ) ;
V_241 = (struct V_240 * ) F_73 ( V_169 ) ;
F_96 ( V_1 , V_241 ) ;
V_187 = F_74 ( V_47 ) . V_187 ;
F_74 ( V_47 ) . V_187 = 0 ;
F_74 ( V_47 ) . V_251 = 0 ;
F_102 ( V_1 -> V_10 . V_252 , V_47 , V_187 , V_253 ) ;
}
static int T_1 F_103 ( struct V_1 * V_1 )
{
struct V_254 * V_201 ;
struct V_255 V_106 = {
. V_256 = F_99 ,
} ;
V_201 = F_104 ( V_1 , V_257 , & V_106 ) ;
if ( ! V_201 )
return - V_113 ;
V_1 -> V_10 . V_252 = V_201 ;
return 0 ;
}
static void F_105 ( struct V_1 * V_1 )
{
F_106 ( V_1 -> V_10 . V_252 ) ;
V_1 -> V_10 . V_252 = NULL ;
}
static void F_107 ( struct V_31 * V_32 , unsigned long V_258 )
{
if ( F_108 ( V_32 , V_258 ) )
F_14 ( F_35 ( V_32 ) ) ;
F_17 ( F_35 ( V_32 ) ) ;
F_109 ( V_32 ) ;
}
static int F_110 ( struct V_259 * V_260 , unsigned long V_258 , void * V_261 )
{
struct V_138 * V_139 = (struct V_138 * ) V_261 ;
struct V_31 * V_32 = V_139 -> V_212 -> V_32 ;
struct V_1 * V_1 = F_35 ( V_32 ) ;
switch ( V_258 ) {
case V_262 :
F_85 ( V_139 ) ;
#ifdef F_46
F_111 ( V_32 , V_263 ) ;
#endif
F_112 ( & V_1 -> V_10 . V_264 ) ;
F_17 ( F_35 ( V_32 ) ) ;
break;
case V_265 :
F_89 ( V_139 , NULL ) ;
F_112 ( & V_1 -> V_10 . V_264 ) ;
if ( ! V_139 -> V_212 -> V_76 ) {
F_107 ( V_32 , V_258 ) ;
} else {
F_17 ( F_35 ( V_32 ) ) ;
}
break;
}
return V_266 ;
}
static int F_113 ( struct V_259 * V_260 , unsigned long V_258 , void * V_261 )
{
struct V_31 * V_32 = F_114 ( V_261 ) ;
struct V_48 * V_49 ;
struct V_1 * V_1 = F_35 ( V_32 ) ;
unsigned int V_223 ;
if ( V_258 == V_267 ) {
F_107 ( V_32 , V_258 ) ;
F_115 ( V_32 ) ;
return V_266 ;
}
V_49 = F_62 ( V_32 ) ;
if ( ! V_49 )
return V_266 ;
switch ( V_258 ) {
case V_262 :
F_116 (in_dev) {
F_85 ( V_139 ) ;
} F_117 ( V_49 ) ;
#ifdef F_46
F_111 ( V_32 , V_263 ) ;
#endif
F_112 ( & V_1 -> V_10 . V_264 ) ;
F_17 ( V_1 ) ;
break;
case V_265 :
F_107 ( V_32 , V_258 ) ;
break;
case V_268 :
V_223 = F_118 ( V_32 ) ;
if ( V_223 & ( V_269 | V_270 ) )
F_111 ( V_32 , V_271 ) ;
else
F_108 ( V_32 , V_258 ) ;
case V_272 :
F_17 ( V_1 ) ;
break;
}
return V_266 ;
}
static int T_1 F_119 ( struct V_1 * V_1 )
{
int V_160 ;
T_6 V_273 = sizeof( struct V_23 ) * V_22 ;
V_273 = F_120 ( T_6 , V_273 , V_274 ) ;
V_1 -> V_10 . V_11 = F_63 ( V_273 , V_150 ) ;
if ( ! V_1 -> V_10 . V_11 )
return - V_6 ;
V_160 = F_1 ( V_1 ) ;
if ( V_160 < 0 )
goto V_8;
return 0 ;
V_8:
F_69 ( V_1 -> V_10 . V_11 ) ;
return V_160 ;
}
static void F_121 ( struct V_1 * V_1 )
{
unsigned int V_275 ;
F_66 () ;
#ifdef F_10
F_122 ( V_1 -> V_10 . V_18 , NULL ) ;
F_122 ( V_1 -> V_10 . V_19 , NULL ) ;
F_122 ( V_1 -> V_10 . V_21 , NULL ) ;
#endif
for ( V_275 = 0 ; V_275 < V_22 ; V_275 ++ ) {
struct V_23 * V_24 = & V_1 -> V_10 . V_11 [ V_275 ] ;
struct V_29 * V_30 ;
struct V_2 * V_15 ;
F_15 (tb, tmp, head, tb_hlist) {
F_123 ( & V_15 -> V_9 ) ;
F_16 ( V_15 ) ;
F_4 ( V_15 ) ;
}
}
#ifdef F_10
F_124 ( V_1 ) ;
#endif
F_70 () ;
F_69 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_125 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_126
V_1 -> V_10 . F_43 = 0 ;
#endif
error = F_119 ( V_1 ) ;
if ( error < 0 )
goto V_210;
error = F_103 ( V_1 ) ;
if ( error < 0 )
goto V_276;
error = F_127 ( V_1 ) ;
if ( error < 0 )
goto V_277;
V_210:
return error ;
V_277:
F_105 ( V_1 ) ;
V_276:
F_121 ( V_1 ) ;
goto V_210;
}
static void T_7 F_128 ( struct V_1 * V_1 )
{
F_129 ( V_1 ) ;
F_105 ( V_1 ) ;
F_121 ( V_1 ) ;
}
void T_8 F_130 ( void )
{
F_131 ( V_278 , V_215 , F_80 , NULL , NULL ) ;
F_131 ( V_278 , V_237 , F_78 , NULL , NULL ) ;
F_131 ( V_278 , V_279 , NULL , F_81 , NULL ) ;
F_132 ( & V_280 ) ;
F_133 ( & V_281 ) ;
F_134 ( & V_282 ) ;
F_135 () ;
}
