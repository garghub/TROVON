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
V_23 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_7 (tb, head, tb_hlist) {
if ( V_15 -> V_24 == V_14 )
return V_15 ;
}
return NULL ;
}
static void F_8 ( struct V_1 * V_1 )
{
int V_25 = 0 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_21 ; V_16 ++ ) {
V_23 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_9 (tb, head, tb_hlist)
V_25 += F_10 ( V_15 ) ;
}
if ( V_25 )
F_11 ( V_1 ) ;
}
static inline unsigned int F_12 ( struct V_1 * V_1 ,
const struct V_26 * V_27 ,
T_3 V_28 )
{
struct V_29 V_30 = { . V_31 = V_28 } ;
struct V_32 V_33 ;
unsigned int V_34 = V_35 ;
struct V_2 * V_3 ;
if ( F_13 ( V_28 ) || F_14 ( V_28 ) )
return V_35 ;
if ( F_15 ( V_28 ) )
return V_36 ;
F_16 () ;
V_3 = F_6 ( V_1 , V_5 ) ;
if ( V_3 ) {
V_34 = V_37 ;
if ( ! F_17 ( V_3 , & V_30 , & V_33 , V_38 ) ) {
if ( ! V_27 || V_27 == V_33 . V_39 -> V_40 )
V_34 = V_33 . type ;
}
}
F_18 () ;
return V_34 ;
}
unsigned int F_19 ( struct V_1 * V_1 , T_3 V_28 )
{
return F_12 ( V_1 , NULL , V_28 ) ;
}
unsigned int F_20 ( struct V_1 * V_1 , const struct V_26 * V_27 ,
T_3 V_28 )
{
return F_12 ( V_1 , V_27 , V_28 ) ;
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
if ( ! F_13 ( F_23 ( V_42 ) -> V_53 ) ) {
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
int V_34 , V_69 ;
struct V_32 V_33 ;
struct V_29 V_30 ;
struct V_1 * V_1 ;
bool V_70 ;
V_30 . V_54 = 0 ;
V_30 . V_55 = V_65 ? : V_56 ;
V_30 . V_31 = V_63 ;
V_30 . V_53 = V_64 ;
V_30 . V_57 = V_58 ;
V_30 . V_59 = V_52 ;
V_69 = V_67 -> V_71 == NULL ;
V_30 . V_60 = F_28 ( V_67 ) ? V_42 -> V_61 : 0 ;
V_1 = F_26 ( V_27 ) ;
if ( F_29 ( V_1 , & V_30 , & V_33 ) )
goto V_72;
if ( V_33 . type != V_37 &&
( V_33 . type != V_73 || ! F_33 ( V_67 ) ) )
goto V_74;
if ( ! V_66 && ! F_34 ( F_26 ( V_27 ) ) &&
( V_27 -> V_75 != V_65 || ! F_35 ( V_67 ) ) )
goto V_72;
F_36 ( V_68 , & V_33 ) ;
V_70 = false ;
#ifdef F_37
for ( V_34 = 0 ; V_34 < V_33 . V_39 -> V_76 ; V_34 ++ ) {
struct V_77 * V_78 = & V_33 . V_39 -> V_77 [ V_34 ] ;
if ( V_78 -> V_79 == V_27 ) {
V_70 = true ;
break;
}
}
#else
if ( F_38 ( V_33 ) == V_27 )
V_70 = true ;
#endif
if ( V_70 ) {
V_34 = F_39 ( V_33 ) . V_80 >= V_81 ;
return V_34 ;
}
if ( V_69 )
goto V_72;
if ( V_66 == 1 )
goto V_82;
V_30 . V_54 = V_27 -> V_75 ;
V_34 = 0 ;
if ( F_29 ( V_1 , & V_30 , & V_33 ) == 0 ) {
if ( V_33 . type == V_37 )
V_34 = F_39 ( V_33 ) . V_80 >= V_81 ;
}
return V_34 ;
V_72:
if ( V_66 )
goto V_82;
* V_68 = 0 ;
return 0 ;
V_74:
return - V_83 ;
V_82:
return - V_84 ;
}
int F_40 ( struct V_41 * V_42 , T_3 V_63 , T_3 V_64 ,
T_4 V_58 , int V_65 , struct V_26 * V_27 ,
struct V_43 * V_67 , T_2 * V_68 )
{
int V_85 = F_41 ( V_42 ) ? 0 : F_42 ( V_67 ) ;
if ( ! V_85 && ! F_34 ( F_26 ( V_27 ) ) &&
F_33 ( V_67 ) &&
( V_27 -> V_75 != V_65 || ! F_35 ( V_67 ) ) ) {
* V_68 = 0 ;
return 0 ;
}
return F_32 ( V_42 , V_63 , V_64 , V_58 , V_65 , V_27 , V_85 , V_67 , V_68 ) ;
}
static inline T_3 F_43 ( struct V_86 * V_28 )
{
return ( (struct V_87 * ) V_28 ) -> V_88 . V_89 ;
}
static int F_44 ( struct V_90 * V_91 , int V_92 , int type , T_2 V_93 )
{
struct V_90 * V_94 ;
V_94 = (struct V_90 * ) ( ( char * ) V_91 + V_92 ) ;
V_94 -> V_95 = type ;
V_94 -> V_96 = F_45 ( 4 ) ;
* ( T_2 * ) F_46 ( V_94 ) = V_93 ;
return V_92 + F_47 ( 4 ) ;
}
static int F_48 ( struct V_1 * V_1 , int V_97 , struct V_98 * V_46 ,
struct V_99 * V_100 )
{
T_3 V_28 ;
int V_101 ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_100 -> V_102 . V_103 = V_1 ;
if ( V_46 -> V_104 . V_105 != V_106 )
return - V_107 ;
V_101 = 32 ;
V_28 = F_43 ( & V_46 -> V_104 ) ;
if ( ! ( V_46 -> V_48 & V_108 ) ) {
T_3 V_109 = F_43 ( & V_46 -> V_110 ) ;
if ( V_46 -> V_110 . V_105 != V_106 ) {
if ( V_109 || V_46 -> V_110 . V_105 )
return - V_107 ;
}
if ( F_49 ( V_109 , V_28 ) )
return - V_83 ;
V_101 = F_50 ( V_109 ) ;
}
V_100 -> V_111 = V_101 ;
V_100 -> V_112 = V_28 ;
if ( V_97 != V_113 ) {
V_100 -> V_114 = V_115 ;
V_100 -> V_116 = V_117 ;
}
if ( V_46 -> V_118 )
V_100 -> V_119 = V_46 -> V_118 - 1 ;
if ( V_46 -> V_48 & V_120 ) {
V_100 -> V_121 = V_81 ;
V_100 -> V_122 = V_123 ;
return 0 ;
}
V_100 -> V_121 = V_124 ;
V_100 -> V_122 = V_37 ;
if ( V_46 -> V_125 ) {
char * V_126 ;
struct V_26 * V_27 ;
char V_127 [ V_128 ] ;
if ( F_51 ( V_127 , V_46 -> V_125 , V_128 - 1 ) )
return - V_129 ;
V_127 [ V_128 - 1 ] = 0 ;
V_126 = strchr ( V_127 , ':' ) ;
if ( V_126 )
* V_126 = 0 ;
V_27 = F_52 ( V_1 , V_127 ) ;
if ( ! V_27 )
return - V_130 ;
V_100 -> V_131 = V_27 -> V_75 ;
if ( V_126 ) {
struct V_132 * V_133 ;
struct V_43 * V_44 = F_53 ( V_27 ) ;
if ( ! V_44 )
return - V_130 ;
* V_126 = ':' ;
for ( V_133 = V_44 -> V_71 ; V_133 ; V_133 = V_133 -> V_134 )
if ( strcmp ( V_133 -> V_135 , V_127 ) == 0 )
break;
if ( V_133 == NULL )
return - V_130 ;
V_100 -> V_136 = V_133 -> V_137 ;
}
}
V_28 = F_43 ( & V_46 -> V_138 ) ;
if ( V_46 -> V_138 . V_105 == V_106 && V_28 ) {
V_100 -> V_139 = V_28 ;
if ( V_46 -> V_48 & V_140 &&
F_19 ( V_1 , V_28 ) == V_37 )
V_100 -> V_121 = V_52 ;
}
if ( V_97 == V_113 )
return 0 ;
if ( V_46 -> V_48 & V_140 && ! V_100 -> V_139 )
return - V_83 ;
if ( V_100 -> V_121 == V_124 )
V_100 -> V_121 = V_62 ;
if ( V_46 -> V_48 & ( V_141 | V_142 | V_143 ) ) {
struct V_90 * V_91 ;
int V_92 = 0 ;
V_91 = F_54 ( 3 * F_47 ( 4 ) , V_144 ) ;
if ( V_91 == NULL )
return - V_6 ;
if ( V_46 -> V_48 & V_141 )
V_92 = F_44 ( V_91 , V_92 , V_145 , V_46 -> V_146 - 40 ) ;
if ( V_46 -> V_48 & V_142 )
V_92 = F_44 ( V_91 , V_92 , V_147 , V_46 -> V_148 ) ;
if ( V_46 -> V_48 & V_143 )
V_92 = F_44 ( V_91 , V_92 , V_149 , V_46 -> V_150 << 3 ) ;
V_100 -> V_151 = V_91 ;
V_100 -> V_152 = V_92 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_1 , unsigned int V_97 , void T_5 * V_153 )
{
struct V_99 V_100 ;
struct V_98 V_46 ;
int V_154 ;
switch ( V_97 ) {
case V_155 :
case V_113 :
if ( ! F_56 ( V_1 -> V_156 , V_157 ) )
return - V_158 ;
if ( F_51 ( & V_46 , V_153 , sizeof( V_46 ) ) )
return - V_129 ;
F_57 () ;
V_154 = F_48 ( V_1 , V_97 , & V_46 , & V_100 ) ;
if ( V_154 == 0 ) {
struct V_2 * V_15 ;
if ( V_97 == V_113 ) {
V_15 = F_6 ( V_1 , V_100 . V_159 ) ;
if ( V_15 )
V_154 = F_58 ( V_15 , & V_100 ) ;
else
V_154 = - V_160 ;
} else {
V_15 = F_5 ( V_1 , V_100 . V_159 ) ;
if ( V_15 )
V_154 = F_59 ( V_15 , & V_100 ) ;
else
V_154 = - V_161 ;
}
F_60 ( V_100 . V_151 ) ;
}
F_61 () ;
return V_154 ;
}
return - V_83 ;
}
static int F_62 ( struct V_1 * V_1 , struct V_41 * V_42 ,
struct V_162 * V_163 , struct V_99 * V_100 )
{
struct V_90 * V_164 ;
int V_154 , V_165 ;
struct V_166 * V_167 ;
V_154 = F_63 ( V_163 , sizeof( * V_167 ) , V_168 , V_169 ) ;
if ( V_154 < 0 )
goto V_170;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
V_167 = F_64 ( V_163 ) ;
V_100 -> V_111 = V_167 -> V_171 ;
V_100 -> V_172 = V_167 -> V_173 ;
V_100 -> V_159 = V_167 -> V_174 ;
V_100 -> V_116 = V_167 -> V_175 ;
V_100 -> V_121 = V_167 -> V_176 ;
V_100 -> V_122 = V_167 -> V_177 ;
V_100 -> V_178 = V_167 -> V_179 ;
V_100 -> V_114 = V_163 -> V_180 ;
V_100 -> V_102 . V_181 = F_65 ( V_42 ) . V_181 ;
V_100 -> V_102 . V_163 = V_163 ;
V_100 -> V_102 . V_103 = V_1 ;
if ( V_100 -> V_122 > V_182 ) {
V_154 = - V_83 ;
goto V_170;
}
F_66 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_95 ( V_164 ) ) {
case V_183 :
V_100 -> V_112 = F_67 ( V_164 ) ;
break;
case V_184 :
V_100 -> V_131 = F_68 ( V_164 ) ;
break;
case V_185 :
V_100 -> V_139 = F_67 ( V_164 ) ;
break;
case V_186 :
V_100 -> V_119 = F_68 ( V_164 ) ;
break;
case V_187 :
V_100 -> V_136 = F_67 ( V_164 ) ;
break;
case V_188 :
V_100 -> V_151 = F_46 ( V_164 ) ;
V_100 -> V_152 = V_96 ( V_164 ) ;
break;
case V_189 :
V_100 -> V_190 = F_46 ( V_164 ) ;
V_100 -> V_191 = V_96 ( V_164 ) ;
break;
case V_192 :
V_100 -> V_193 = F_68 ( V_164 ) ;
break;
case V_194 :
V_100 -> V_159 = F_68 ( V_164 ) ;
break;
}
}
return 0 ;
V_170:
return V_154 ;
}
static int F_69 ( struct V_41 * V_42 , struct V_162 * V_163 )
{
struct V_1 * V_1 = F_70 ( V_42 -> V_195 ) ;
struct V_99 V_100 ;
struct V_2 * V_15 ;
int V_154 ;
V_154 = F_62 ( V_1 , V_42 , V_163 , & V_100 ) ;
if ( V_154 < 0 )
goto V_170;
V_15 = F_6 ( V_1 , V_100 . V_159 ) ;
if ( V_15 == NULL ) {
V_154 = - V_160 ;
goto V_170;
}
V_154 = F_58 ( V_15 , & V_100 ) ;
V_170:
return V_154 ;
}
static int F_71 ( struct V_41 * V_42 , struct V_162 * V_163 )
{
struct V_1 * V_1 = F_70 ( V_42 -> V_195 ) ;
struct V_99 V_100 ;
struct V_2 * V_15 ;
int V_154 ;
V_154 = F_62 ( V_1 , V_42 , V_163 , & V_100 ) ;
if ( V_154 < 0 )
goto V_170;
V_15 = F_5 ( V_1 , V_100 . V_159 ) ;
if ( V_15 == NULL ) {
V_154 = - V_161 ;
goto V_170;
}
V_154 = F_59 ( V_15 , & V_100 ) ;
V_170:
return V_154 ;
}
static int F_72 ( struct V_41 * V_42 , struct V_196 * V_197 )
{
struct V_1 * V_1 = F_70 ( V_42 -> V_195 ) ;
unsigned int V_16 , V_198 ;
unsigned int V_199 = 0 , V_200 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
int V_201 = 0 ;
if ( F_73 ( V_197 -> V_163 ) >= sizeof( struct V_166 ) &&
( (struct V_166 * ) F_64 ( V_197 -> V_163 ) ) -> V_179 & V_202 )
return V_42 -> V_92 ;
V_198 = V_197 -> args [ 0 ] ;
V_200 = V_197 -> args [ 1 ] ;
for ( V_16 = V_198 ; V_16 < V_21 ; V_16 ++ , V_200 = 0 ) {
V_199 = 0 ;
V_23 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_9 (tb, head, tb_hlist) {
if ( V_199 < V_200 )
goto V_203;
if ( V_201 )
memset ( & V_197 -> args [ 2 ] , 0 , sizeof( V_197 -> args ) -
2 * sizeof( V_197 -> args [ 0 ] ) ) ;
if ( F_74 ( V_15 , V_42 , V_197 ) < 0 )
goto V_204;
V_201 = 1 ;
V_203:
V_199 ++ ;
}
}
V_204:
V_197 -> args [ 1 ] = V_199 ;
V_197 -> args [ 0 ] = V_16 ;
return V_42 -> V_92 ;
}
static void F_75 ( int V_97 , int type , T_3 V_64 , int V_205 , struct V_132 * V_133 )
{
struct V_1 * V_1 = F_26 ( V_133 -> V_206 -> V_27 ) ;
struct V_2 * V_15 ;
struct V_99 V_100 = {
. V_116 = V_207 ,
. V_122 = type ,
. V_112 = V_64 ,
. V_111 = V_205 ,
. V_136 = V_133 -> V_137 ,
. V_131 = V_133 -> V_206 -> V_27 -> V_75 ,
. V_114 = V_115 | V_208 ,
. V_102 = {
. V_103 = V_1 ,
} ,
} ;
if ( type == V_37 )
V_15 = F_5 ( V_1 , V_7 ) ;
else
V_15 = F_5 ( V_1 , V_5 ) ;
if ( V_15 == NULL )
return;
V_100 . V_159 = V_15 -> V_24 ;
if ( type != V_73 )
V_100 . V_121 = V_62 ;
else
V_100 . V_121 = V_81 ;
if ( V_97 == V_209 )
F_59 ( V_15 , & V_100 ) ;
else
F_58 ( V_15 , & V_100 ) ;
}
void F_76 ( struct V_132 * V_133 )
{
struct V_43 * V_44 = V_133 -> V_206 ;
struct V_26 * V_27 = V_44 -> V_27 ;
struct V_132 * V_210 = V_133 ;
T_3 V_109 = V_133 -> V_211 ;
T_3 V_28 = V_133 -> V_137 ;
T_3 V_212 = V_133 -> V_213 & V_109 ;
if ( V_133 -> V_214 & V_215 ) {
V_210 = F_77 ( V_44 , V_212 , V_109 ) ;
if ( V_210 == NULL ) {
F_78 ( L_1 , V_216 ) ;
return;
}
}
F_75 ( V_209 , V_73 , V_28 , 32 , V_210 ) ;
if ( ! ( V_27 -> V_217 & V_218 ) )
return;
if ( V_133 -> V_219 && V_133 -> V_219 != F_79 ( 0xFFFFFFFF ) )
F_75 ( V_209 , V_35 , V_133 -> V_219 , 32 , V_210 ) ;
if ( ! F_13 ( V_212 ) && ! ( V_133 -> V_214 & V_215 ) &&
( V_212 != V_28 || V_133 -> V_220 < 32 ) ) {
F_75 ( V_209 ,
V_27 -> V_217 & V_221 ? V_73 : V_37 ,
V_212 , V_133 -> V_220 , V_210 ) ;
if ( V_133 -> V_220 < 31 ) {
F_75 ( V_209 , V_35 , V_212 , 32 , V_210 ) ;
F_75 ( V_209 , V_35 , V_212 | ~ V_109 ,
32 , V_210 ) ;
}
}
}
void F_80 ( struct V_132 * V_133 , struct V_132 * V_222 )
{
struct V_43 * V_44 = V_133 -> V_206 ;
struct V_26 * V_27 = V_44 -> V_27 ;
struct V_132 * V_223 ;
struct V_132 * V_210 = V_133 , * V_224 = NULL ;
T_3 V_225 = V_133 -> V_213 | ~ V_133 -> V_211 ;
T_3 V_226 = V_133 -> V_213 & V_133 -> V_211 ;
#define F_81 1
#define F_82 2
#define F_83 4
#define F_84 8
unsigned int V_227 = 0 ;
int V_228 = 0 ;
int V_229 = 1 ;
int V_230 = 0 ;
if ( V_133 -> V_214 & V_215 ) {
V_210 = F_77 ( V_44 , V_226 , V_133 -> V_211 ) ;
if ( V_210 == NULL ) {
F_78 ( L_1 , V_216 ) ;
return;
}
if ( V_222 && V_222 != V_210 ) {
F_78 ( L_2 , V_216 ) ;
return;
}
} else if ( ! F_13 ( V_226 ) &&
( V_226 != V_133 -> V_137 || V_133 -> V_220 < 32 ) ) {
F_75 ( V_231 ,
V_27 -> V_217 & V_221 ? V_73 : V_37 ,
V_226 , V_133 -> V_220 , V_210 ) ;
V_228 = 1 ;
}
for ( V_223 = V_44 -> V_71 ; V_223 ; V_223 = V_223 -> V_134 ) {
if ( V_223 == V_133 ) {
V_229 = 0 ;
continue;
}
if ( V_222 && V_223 -> V_211 == V_222 -> V_211 &&
F_85 ( V_223 -> V_213 , V_222 ) )
continue;
if ( V_223 -> V_214 & V_215 ) {
if ( V_223 -> V_211 == V_210 -> V_211 &&
F_85 ( V_223 -> V_213 , V_210 ) )
V_224 = V_210 ;
else {
if ( ! V_230 )
continue;
if ( ! V_224 ||
V_223 -> V_211 != V_224 -> V_211 ||
! F_85 ( V_223 -> V_213 , V_224 ) )
V_224 = F_77 ( V_44 ,
V_223 -> V_213 ,
V_223 -> V_211 ) ;
if ( ! V_224 )
continue;
if ( V_224 -> V_137 != V_210 -> V_137 )
continue;
}
} else {
if ( V_210 -> V_137 != V_223 -> V_137 )
continue;
V_224 = V_223 ;
if ( V_210 != V_224 )
V_230 = 1 ;
}
if ( V_133 -> V_137 == V_223 -> V_137 )
V_227 |= F_81 ;
if ( V_133 -> V_219 == V_223 -> V_219 )
V_227 |= F_82 ;
if ( V_225 == V_223 -> V_219 )
V_227 |= F_84 ;
if ( V_226 == V_223 -> V_219 )
V_227 |= F_83 ;
if ( V_224 == V_223 && V_223 -> V_220 < 31 ) {
T_3 V_232 = V_223 -> V_213 | ~ V_223 -> V_211 ;
T_3 V_233 = V_223 -> V_213 & V_223 -> V_211 ;
if ( ! F_13 ( V_233 ) ) {
if ( V_133 -> V_219 == V_232 ||
V_133 -> V_219 == V_233 )
V_227 |= F_82 ;
if ( V_225 == V_232 || V_225 == V_233 )
V_227 |= F_84 ;
if ( V_226 == V_232 || V_226 == V_233 )
V_227 |= F_83 ;
}
}
}
if ( ! ( V_227 & F_82 ) )
F_75 ( V_231 , V_35 , V_133 -> V_219 , 32 , V_210 ) ;
if ( V_228 && V_133 -> V_220 < 31 ) {
if ( ! ( V_227 & F_84 ) )
F_75 ( V_231 , V_35 , V_225 , 32 , V_210 ) ;
if ( ! ( V_227 & F_83 ) )
F_75 ( V_231 , V_35 , V_226 , 32 , V_210 ) ;
}
if ( ! ( V_227 & F_81 ) ) {
F_75 ( V_231 , V_73 , V_133 -> V_137 , 32 , V_210 ) ;
if ( V_229 &&
F_19 ( F_26 ( V_27 ) , V_133 -> V_137 ) != V_73 ) {
if ( F_86 ( F_26 ( V_27 ) , V_133 -> V_137 ) )
F_8 ( F_26 ( V_27 ) ) ;
}
}
#undef F_81
#undef F_82
#undef F_83
#undef F_84
}
static void F_87 ( struct V_1 * V_1 , struct V_234 * V_235 )
{
struct V_32 V_33 ;
struct V_29 V_30 = {
. V_60 = V_235 -> V_236 ,
. V_31 = V_235 -> V_237 ,
. V_57 = V_235 -> V_238 ,
. V_59 = V_235 -> V_239 ,
} ;
struct V_2 * V_15 ;
F_16 () ;
V_15 = F_6 ( V_1 , V_235 -> V_240 ) ;
V_235 -> V_154 = - V_241 ;
if ( V_15 ) {
F_88 () ;
V_235 -> V_24 = V_15 -> V_24 ;
V_235 -> V_154 = F_17 ( V_15 , & V_30 , & V_33 , V_38 ) ;
if ( ! V_235 -> V_154 ) {
V_235 -> V_242 = V_33 . V_242 ;
V_235 -> V_243 = V_33 . V_243 ;
V_235 -> type = V_33 . type ;
V_235 -> V_47 = V_33 . V_47 ;
}
F_89 () ;
}
F_18 () ;
}
static void F_90 ( struct V_41 * V_42 )
{
struct V_1 * V_1 ;
struct V_234 * V_235 ;
struct V_162 * V_163 ;
T_2 V_181 ;
V_1 = F_70 ( V_42 -> V_195 ) ;
V_163 = F_91 ( V_42 ) ;
if ( V_42 -> V_92 < V_244 || V_42 -> V_92 < V_163 -> F_73 ||
F_73 ( V_163 ) < sizeof( * V_235 ) )
return;
V_42 = F_92 ( V_42 , V_144 ) ;
if ( V_42 == NULL )
return;
V_163 = F_91 ( V_42 ) ;
V_235 = (struct V_234 * ) F_64 ( V_163 ) ;
F_87 ( V_1 , V_235 ) ;
V_181 = F_65 ( V_42 ) . V_181 ;
F_65 ( V_42 ) . V_181 = 0 ;
F_65 ( V_42 ) . V_245 = 0 ;
F_93 ( V_1 -> V_10 . V_246 , V_42 , V_181 , V_247 ) ;
}
static int T_1 F_94 ( struct V_1 * V_1 )
{
struct V_248 * V_195 ;
struct V_249 V_100 = {
. V_250 = F_90 ,
} ;
V_195 = F_95 ( V_1 , V_251 , & V_100 ) ;
if ( V_195 == NULL )
return - V_107 ;
V_1 -> V_10 . V_246 = V_195 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_1 )
{
F_97 ( V_1 -> V_10 . V_246 ) ;
V_1 -> V_10 . V_246 = NULL ;
}
static void F_98 ( struct V_26 * V_27 , int V_252 )
{
if ( F_99 ( V_27 , V_252 ) )
F_8 ( F_26 ( V_27 ) ) ;
F_11 ( F_26 ( V_27 ) ) ;
F_100 ( V_27 ) ;
}
static int F_101 ( struct V_253 * V_254 , unsigned long V_255 , void * V_256 )
{
struct V_132 * V_133 = (struct V_132 * ) V_256 ;
struct V_26 * V_27 = V_133 -> V_206 -> V_27 ;
struct V_1 * V_1 = F_26 ( V_27 ) ;
switch ( V_255 ) {
case V_257 :
F_76 ( V_133 ) ;
#ifdef F_37
F_102 ( V_27 ) ;
#endif
F_103 ( & V_1 -> V_10 . V_258 ) ;
F_11 ( F_26 ( V_27 ) ) ;
break;
case V_259 :
F_80 ( V_133 , NULL ) ;
F_103 ( & V_1 -> V_10 . V_258 ) ;
if ( V_133 -> V_206 -> V_71 == NULL ) {
F_98 ( V_27 , 1 ) ;
} else {
F_11 ( F_26 ( V_27 ) ) ;
}
break;
}
return V_260 ;
}
static int F_104 ( struct V_253 * V_254 , unsigned long V_255 , void * V_256 )
{
struct V_26 * V_27 = F_105 ( V_256 ) ;
struct V_43 * V_44 ;
struct V_1 * V_1 = F_26 ( V_27 ) ;
if ( V_255 == V_261 ) {
F_98 ( V_27 , 2 ) ;
F_106 ( V_27 ) ;
return V_260 ;
}
V_44 = F_53 ( V_27 ) ;
if ( ! V_44 )
return V_260 ;
switch ( V_255 ) {
case V_257 :
F_107 (in_dev) {
F_76 ( V_133 ) ;
} F_108 ( V_44 ) ;
#ifdef F_37
F_102 ( V_27 ) ;
#endif
F_103 ( & V_1 -> V_10 . V_258 ) ;
F_11 ( V_1 ) ;
break;
case V_259 :
F_98 ( V_27 , 0 ) ;
break;
case V_262 :
case V_263 :
F_11 ( V_1 ) ;
break;
}
return V_260 ;
}
static int T_1 F_109 ( struct V_1 * V_1 )
{
int V_154 ;
T_6 V_264 = sizeof( struct V_22 ) * V_21 ;
V_264 = F_110 ( T_6 , V_264 , V_265 ) ;
V_1 -> V_10 . V_11 = F_54 ( V_264 , V_144 ) ;
if ( V_1 -> V_10 . V_11 == NULL )
return - V_6 ;
V_154 = F_1 ( V_1 ) ;
if ( V_154 < 0 )
goto V_8;
return 0 ;
V_8:
F_60 ( V_1 -> V_10 . V_11 ) ;
return V_154 ;
}
static void F_111 ( struct V_1 * V_1 )
{
unsigned int V_266 ;
F_57 () ;
#ifdef F_112
F_113 ( V_1 ) ;
#endif
for ( V_266 = 0 ; V_266 < V_21 ; V_266 ++ ) {
struct V_2 * V_15 ;
struct V_22 * V_23 ;
struct V_267 * V_268 ;
V_23 = & V_1 -> V_10 . V_11 [ V_266 ] ;
F_114 (tb, tmp, head, tb_hlist) {
F_115 ( & V_15 -> V_9 ) ;
F_10 ( V_15 ) ;
F_4 ( V_15 ) ;
}
}
F_61 () ;
F_60 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_116 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_117
V_1 -> V_10 . F_34 = 0 ;
#endif
error = F_109 ( V_1 ) ;
if ( error < 0 )
goto V_204;
error = F_94 ( V_1 ) ;
if ( error < 0 )
goto V_269;
error = F_118 ( V_1 ) ;
if ( error < 0 )
goto V_270;
V_204:
return error ;
V_270:
F_96 ( V_1 ) ;
V_269:
F_111 ( V_1 ) ;
goto V_204;
}
static void T_7 F_119 ( struct V_1 * V_1 )
{
F_120 ( V_1 ) ;
F_96 ( V_1 ) ;
F_111 ( V_1 ) ;
}
void T_8 F_121 ( void )
{
F_122 ( V_271 , V_209 , F_71 , NULL , NULL ) ;
F_122 ( V_271 , V_231 , F_69 , NULL , NULL ) ;
F_122 ( V_271 , V_272 , NULL , F_72 , NULL ) ;
F_123 ( & V_273 ) ;
F_124 ( & V_274 ) ;
F_125 ( & V_275 ) ;
F_126 () ;
}
