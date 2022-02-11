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
case V_5 :
F_7 ( V_1 -> V_10 . V_18 , V_15 ) ;
break;
case V_19 :
F_7 ( V_1 -> V_10 . V_20 , V_15 ) ;
break;
default:
break;
}
V_17 = V_14 & ( V_21 - 1 ) ;
F_3 ( & V_15 -> V_9 , & V_1 -> V_10 . V_11 [ V_17 ] ) ;
return V_15 ;
}
struct V_2 * F_6 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_15 ;
struct V_22 * V_23 ;
unsigned int V_17 ;
if ( V_14 == 0 )
V_14 = V_5 ;
V_17 = V_14 & ( V_21 - 1 ) ;
V_23 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_15 -> V_24 == V_14 )
return V_15 ;
}
return NULL ;
}
static void F_9 ( struct V_1 * V_1 , struct V_2 * V_25 ,
struct V_2 * V_26 )
{
#ifdef F_10
switch ( V_26 -> V_24 ) {
case V_5 :
F_7 ( V_1 -> V_10 . V_18 , V_26 ) ;
break;
case V_19 :
F_7 ( V_1 -> V_10 . V_20 , V_26 ) ;
break;
default:
break;
}
#endif
F_11 ( & V_25 -> V_9 , & V_26 -> V_9 ) ;
}
int F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_25 , * V_26 , * V_4 ;
V_25 = F_6 ( V_1 , V_7 ) ;
if ( ! V_25 )
return 0 ;
V_26 = F_13 ( V_25 ) ;
if ( ! V_26 )
return - V_6 ;
if ( V_26 == V_25 )
return 0 ;
F_9 ( V_1 , V_25 , V_26 ) ;
F_4 ( V_25 ) ;
V_4 = F_6 ( V_1 , V_5 ) ;
if ( ! V_4 )
return 0 ;
F_14 ( V_4 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_1 )
{
int V_27 = 0 ;
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
struct V_22 * V_23 = & V_1 -> V_10 . V_11 [ V_17 ] ;
struct V_28 * V_29 ;
struct V_2 * V_15 ;
F_16 (tb, tmp, head, tb_hlist)
V_27 += F_17 ( V_1 , V_15 ) ;
}
if ( V_27 )
F_18 ( V_1 ) ;
}
static inline unsigned int F_19 ( struct V_1 * V_1 ,
const struct V_30 * V_31 ,
T_3 V_32 , T_2 V_24 )
{
struct V_33 V_34 = { . V_35 = V_32 } ;
struct V_36 V_37 ;
unsigned int V_38 = V_39 ;
struct V_2 * V_40 ;
if ( F_20 ( V_32 ) || F_21 ( V_32 ) )
return V_39 ;
if ( F_22 ( V_32 ) )
return V_41 ;
F_23 () ;
V_40 = F_6 ( V_1 , V_24 ) ;
if ( V_40 ) {
V_38 = V_42 ;
if ( ! F_24 ( V_40 , & V_34 , & V_37 , V_43 ) ) {
if ( ! V_31 || V_31 == V_37 . V_44 -> V_45 )
V_38 = V_37 . type ;
}
}
F_25 () ;
return V_38 ;
}
unsigned int F_26 ( struct V_1 * V_1 , T_3 V_32 , T_2 V_24 )
{
return F_19 ( V_1 , NULL , V_32 , V_24 ) ;
}
unsigned int F_27 ( struct V_1 * V_1 , T_3 V_32 )
{
return F_19 ( V_1 , NULL , V_32 , V_7 ) ;
}
unsigned int F_28 ( struct V_1 * V_1 , const struct V_30 * V_31 ,
T_3 V_32 )
{
T_2 V_46 = F_29 ( V_31 ) ? : V_7 ;
return F_19 ( V_1 , V_31 , V_32 , V_46 ) ;
}
unsigned int F_30 ( struct V_1 * V_1 ,
const struct V_30 * V_31 ,
T_3 V_32 )
{
T_2 V_46 = F_29 ( V_31 ) ? : V_7 ;
return F_19 ( V_1 , NULL , V_32 , V_46 ) ;
}
T_3 F_31 ( struct V_47 * V_48 )
{
struct V_30 * V_31 = V_48 -> V_31 ;
struct V_49 * V_50 ;
struct V_36 V_37 ;
struct V_51 * V_52 ;
struct V_1 * V_1 ;
int V_53 ;
V_52 = F_32 ( V_48 ) ;
if ( ( V_52 -> V_54 & ( V_55 | V_56 | V_57 ) ) ==
V_57 )
return F_33 ( V_48 ) -> V_35 ;
V_50 = F_34 ( V_31 ) ;
F_35 ( ! V_50 ) ;
V_1 = F_36 ( V_31 ) ;
V_53 = V_58 ;
if ( ! F_20 ( F_33 ( V_48 ) -> V_59 ) ) {
struct V_33 V_34 = {
. V_60 = V_61 ,
. V_35 = F_33 ( V_48 ) -> V_59 ,
. V_62 = F_37 ( F_33 ( V_48 ) -> V_63 ) ,
. V_64 = V_53 ,
. V_65 = F_38 ( V_50 ) ? V_48 -> V_66 : 0 ,
} ;
if ( ! F_39 ( V_1 , & V_34 , & V_37 , 0 ) )
return F_40 ( V_1 , V_37 ) ;
} else {
V_53 = V_67 ;
}
return F_41 ( V_31 , F_33 ( V_48 ) -> V_59 , V_53 ) ;
}
static int F_42 ( struct V_47 * V_48 , T_3 V_68 , T_3 V_69 ,
T_4 V_63 , int V_70 , struct V_30 * V_31 ,
int V_71 , struct V_49 * V_72 , T_2 * V_73 )
{
int V_38 , V_74 ;
struct V_36 V_37 ;
struct V_33 V_34 ;
struct V_1 * V_1 ;
bool V_75 ;
V_34 . V_76 = 0 ;
V_34 . V_60 = F_43 ( V_31 ) ;
if ( ! V_34 . V_60 )
V_34 . V_60 = V_70 ? : V_61 ;
V_34 . V_35 = V_68 ;
V_34 . V_59 = V_69 ;
V_34 . V_62 = V_63 ;
V_34 . V_64 = V_58 ;
V_34 . V_77 . V_78 = 0 ;
V_34 . V_79 = 0 ;
V_74 = V_72 -> V_80 == NULL ;
V_34 . V_65 = F_38 ( V_72 ) ? V_48 -> V_66 : 0 ;
F_44 ( V_31 , & V_34 ) ;
V_1 = F_36 ( V_31 ) ;
if ( F_39 ( V_1 , & V_34 , & V_37 , 0 ) )
goto V_81;
if ( V_37 . type != V_42 &&
( V_37 . type != V_82 || ! F_45 ( V_72 ) ) )
goto V_83;
if ( ! V_71 && ! F_46 ( F_36 ( V_31 ) ) &&
( V_31 -> V_84 != V_70 || ! F_47 ( V_72 ) ) )
goto V_81;
F_48 ( V_73 , & V_37 ) ;
V_75 = false ;
#ifdef F_49
for ( V_38 = 0 ; V_38 < V_37 . V_44 -> V_85 ; V_38 ++ ) {
struct V_86 * V_87 = & V_37 . V_44 -> V_86 [ V_38 ] ;
if ( V_87 -> V_88 == V_31 ) {
V_75 = true ;
break;
} else if ( F_43 ( V_87 -> V_88 ) == V_31 -> V_84 ) {
V_75 = true ;
break;
}
}
#else
if ( F_50 ( V_37 ) == V_31 )
V_75 = true ;
#endif
if ( V_75 ) {
V_38 = F_51 ( V_37 ) . V_89 >= V_90 ;
return V_38 ;
}
if ( V_74 )
goto V_81;
if ( V_71 == 1 )
goto V_91;
V_34 . V_76 = V_31 -> V_84 ;
V_38 = 0 ;
if ( F_39 ( V_1 , & V_34 , & V_37 , V_92 ) == 0 ) {
if ( V_37 . type == V_42 )
V_38 = F_51 ( V_37 ) . V_89 >= V_90 ;
}
return V_38 ;
V_81:
if ( V_71 )
goto V_91;
* V_73 = 0 ;
return 0 ;
V_83:
return - V_93 ;
V_91:
return - V_94 ;
}
int F_52 ( struct V_47 * V_48 , T_3 V_68 , T_3 V_69 ,
T_4 V_63 , int V_70 , struct V_30 * V_31 ,
struct V_49 * V_72 , T_2 * V_73 )
{
int V_95 = F_53 ( V_48 ) ? 0 : F_54 ( V_72 ) ;
if ( ! V_95 && ! F_46 ( F_36 ( V_31 ) ) &&
F_45 ( V_72 ) &&
( V_31 -> V_84 != V_70 || ! F_47 ( V_72 ) ) ) {
* V_73 = 0 ;
return 0 ;
}
return F_42 ( V_48 , V_68 , V_69 , V_63 , V_70 , V_31 , V_95 , V_72 , V_73 ) ;
}
static inline T_3 F_55 ( struct V_96 * V_32 )
{
return ( (struct V_97 * ) V_32 ) -> V_98 . V_99 ;
}
static int F_56 ( struct V_100 * V_101 , int V_102 , int type , T_2 V_103 )
{
struct V_100 * V_104 ;
V_104 = (struct V_100 * ) ( ( char * ) V_101 + V_102 ) ;
V_104 -> V_105 = type ;
V_104 -> V_106 = F_57 ( 4 ) ;
* ( T_2 * ) F_58 ( V_104 ) = V_103 ;
return V_102 + F_59 ( 4 ) ;
}
static int F_60 ( struct V_1 * V_1 , int V_107 , struct V_108 * V_52 ,
struct V_109 * V_110 )
{
T_3 V_32 ;
int V_111 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_112 . V_113 = V_1 ;
if ( V_52 -> V_114 . V_115 != V_116 )
return - V_117 ;
V_111 = 32 ;
V_32 = F_55 ( & V_52 -> V_114 ) ;
if ( ! ( V_52 -> V_54 & V_118 ) ) {
T_3 V_119 = F_55 ( & V_52 -> V_120 ) ;
if ( V_52 -> V_120 . V_115 != V_116 ) {
if ( V_119 || V_52 -> V_120 . V_115 )
return - V_117 ;
}
if ( F_61 ( V_119 , V_32 ) )
return - V_93 ;
V_111 = F_62 ( V_119 ) ;
}
V_110 -> V_121 = V_111 ;
V_110 -> V_122 = V_32 ;
if ( V_107 != V_123 ) {
V_110 -> V_124 = V_125 ;
V_110 -> V_126 = V_127 ;
}
if ( V_52 -> V_128 )
V_110 -> V_129 = V_52 -> V_128 - 1 ;
if ( V_52 -> V_54 & V_130 ) {
V_110 -> V_131 = V_90 ;
V_110 -> V_132 = V_133 ;
return 0 ;
}
V_110 -> V_131 = V_134 ;
V_110 -> V_132 = V_42 ;
if ( V_52 -> V_135 ) {
char * V_136 ;
struct V_30 * V_31 ;
char V_137 [ V_138 ] ;
if ( F_63 ( V_137 , V_52 -> V_135 , V_138 - 1 ) )
return - V_139 ;
V_137 [ V_138 - 1 ] = 0 ;
V_136 = strchr ( V_137 , ':' ) ;
if ( V_136 )
* V_136 = 0 ;
V_31 = F_64 ( V_1 , V_137 ) ;
if ( ! V_31 )
return - V_140 ;
V_110 -> V_141 = V_31 -> V_84 ;
V_110 -> V_142 = F_29 ( V_31 ) ;
if ( V_136 ) {
struct V_143 * V_144 ;
struct V_49 * V_50 = F_65 ( V_31 ) ;
if ( ! V_50 )
return - V_140 ;
* V_136 = ':' ;
for ( V_144 = V_50 -> V_80 ; V_144 ; V_144 = V_144 -> V_145 )
if ( strcmp ( V_144 -> V_146 , V_137 ) == 0 )
break;
if ( ! V_144 )
return - V_140 ;
V_110 -> V_147 = V_144 -> V_148 ;
}
}
V_32 = F_55 ( & V_52 -> V_149 ) ;
if ( V_52 -> V_149 . V_115 == V_116 && V_32 ) {
unsigned int V_150 ;
V_110 -> V_151 = V_32 ;
V_150 = F_26 ( V_1 , V_32 , V_110 -> V_142 ) ;
if ( V_52 -> V_54 & V_152 &&
V_150 == V_42 )
V_110 -> V_131 = V_58 ;
}
if ( V_107 == V_123 )
return 0 ;
if ( V_52 -> V_54 & V_152 && ! V_110 -> V_151 )
return - V_93 ;
if ( V_110 -> V_131 == V_134 )
V_110 -> V_131 = V_67 ;
if ( V_52 -> V_54 & ( V_153 | V_154 | V_155 ) ) {
struct V_100 * V_101 ;
int V_102 = 0 ;
V_101 = F_66 ( 3 * F_59 ( 4 ) , V_156 ) ;
if ( ! V_101 )
return - V_6 ;
if ( V_52 -> V_54 & V_153 )
V_102 = F_56 ( V_101 , V_102 , V_157 , V_52 -> V_158 - 40 ) ;
if ( V_52 -> V_54 & V_154 )
V_102 = F_56 ( V_101 , V_102 , V_159 , V_52 -> V_160 ) ;
if ( V_52 -> V_54 & V_155 )
V_102 = F_56 ( V_101 , V_102 , V_161 , V_52 -> V_162 << 3 ) ;
V_110 -> V_163 = V_101 ;
V_110 -> V_164 = V_102 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_1 , unsigned int V_107 , void T_5 * V_165 )
{
struct V_109 V_110 ;
struct V_108 V_52 ;
int V_166 ;
switch ( V_107 ) {
case V_167 :
case V_123 :
if ( ! F_68 ( V_1 -> V_168 , V_169 ) )
return - V_170 ;
if ( F_63 ( & V_52 , V_165 , sizeof( V_52 ) ) )
return - V_139 ;
F_69 () ;
V_166 = F_60 ( V_1 , V_107 , & V_52 , & V_110 ) ;
if ( V_166 == 0 ) {
struct V_2 * V_15 ;
if ( V_107 == V_123 ) {
V_15 = F_6 ( V_1 , V_110 . V_142 ) ;
if ( V_15 )
V_166 = F_70 ( V_1 , V_15 , & V_110 ) ;
else
V_166 = - V_171 ;
} else {
V_15 = F_5 ( V_1 , V_110 . V_142 ) ;
if ( V_15 )
V_166 = F_71 ( V_1 , V_15 , & V_110 ) ;
else
V_166 = - V_172 ;
}
F_72 ( V_110 . V_163 ) ;
}
F_73 () ;
return V_166 ;
}
return - V_93 ;
}
static int F_74 ( struct V_1 * V_1 , struct V_47 * V_48 ,
struct V_173 * V_174 , struct V_109 * V_110 )
{
struct V_100 * V_175 ;
int V_166 , V_176 ;
struct V_177 * V_178 ;
V_166 = F_75 ( V_174 , sizeof( * V_178 ) , V_179 , V_180 ) ;
if ( V_166 < 0 )
goto V_181;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_178 = F_76 ( V_174 ) ;
V_110 -> V_121 = V_178 -> V_182 ;
V_110 -> V_183 = V_178 -> V_184 ;
V_110 -> V_142 = V_178 -> V_185 ;
V_110 -> V_126 = V_178 -> V_186 ;
V_110 -> V_131 = V_178 -> V_187 ;
V_110 -> V_132 = V_178 -> V_188 ;
V_110 -> V_189 = V_178 -> V_190 ;
V_110 -> V_124 = V_174 -> V_191 ;
V_110 -> V_112 . V_192 = F_77 ( V_48 ) . V_192 ;
V_110 -> V_112 . V_174 = V_174 ;
V_110 -> V_112 . V_113 = V_1 ;
if ( V_110 -> V_132 > V_193 ) {
V_166 = - V_93 ;
goto V_181;
}
F_78 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_105 ( V_175 ) ) {
case V_194 :
V_110 -> V_122 = F_79 ( V_175 ) ;
break;
case V_195 :
V_110 -> V_141 = F_80 ( V_175 ) ;
break;
case V_196 :
V_110 -> V_151 = F_79 ( V_175 ) ;
break;
case V_197 :
V_110 -> V_129 = F_80 ( V_175 ) ;
break;
case V_198 :
V_110 -> V_147 = F_79 ( V_175 ) ;
break;
case V_199 :
V_110 -> V_163 = F_58 ( V_175 ) ;
V_110 -> V_164 = V_106 ( V_175 ) ;
break;
case V_200 :
V_110 -> V_201 = F_58 ( V_175 ) ;
V_110 -> V_202 = V_106 ( V_175 ) ;
break;
case V_203 :
V_110 -> V_204 = F_80 ( V_175 ) ;
break;
case V_205 :
V_110 -> V_142 = F_80 ( V_175 ) ;
break;
case V_206 :
V_110 -> V_207 = V_175 ;
break;
case V_208 :
V_110 -> V_209 = F_81 ( V_175 ) ;
break;
}
}
return 0 ;
V_181:
return V_166 ;
}
static int F_82 ( struct V_47 * V_48 , struct V_173 * V_174 )
{
struct V_1 * V_1 = F_83 ( V_48 -> V_210 ) ;
struct V_109 V_110 ;
struct V_2 * V_15 ;
int V_166 ;
V_166 = F_74 ( V_1 , V_48 , V_174 , & V_110 ) ;
if ( V_166 < 0 )
goto V_181;
V_15 = F_6 ( V_1 , V_110 . V_142 ) ;
if ( ! V_15 ) {
V_166 = - V_171 ;
goto V_181;
}
V_166 = F_70 ( V_1 , V_15 , & V_110 ) ;
V_181:
return V_166 ;
}
static int F_84 ( struct V_47 * V_48 , struct V_173 * V_174 )
{
struct V_1 * V_1 = F_83 ( V_48 -> V_210 ) ;
struct V_109 V_110 ;
struct V_2 * V_15 ;
int V_166 ;
V_166 = F_74 ( V_1 , V_48 , V_174 , & V_110 ) ;
if ( V_166 < 0 )
goto V_181;
V_15 = F_5 ( V_1 , V_110 . V_142 ) ;
if ( ! V_15 ) {
V_166 = - V_172 ;
goto V_181;
}
V_166 = F_71 ( V_1 , V_15 , & V_110 ) ;
V_181:
return V_166 ;
}
static int F_85 ( struct V_47 * V_48 , struct V_211 * V_212 )
{
struct V_1 * V_1 = F_83 ( V_48 -> V_210 ) ;
unsigned int V_17 , V_213 ;
unsigned int V_214 = 0 , V_215 ;
struct V_2 * V_15 ;
struct V_22 * V_23 ;
int V_216 = 0 ;
if ( F_86 ( V_212 -> V_174 ) >= sizeof( struct V_177 ) &&
( (struct V_177 * ) F_76 ( V_212 -> V_174 ) ) -> V_190 & V_217 )
return V_48 -> V_102 ;
V_213 = V_212 -> args [ 0 ] ;
V_215 = V_212 -> args [ 1 ] ;
F_23 () ;
for ( V_17 = V_213 ; V_17 < V_21 ; V_17 ++ , V_215 = 0 ) {
V_214 = 0 ;
V_23 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_214 < V_215 )
goto V_218;
if ( V_216 )
memset ( & V_212 -> args [ 2 ] , 0 , sizeof( V_212 -> args ) -
2 * sizeof( V_212 -> args [ 0 ] ) ) ;
if ( F_87 ( V_15 , V_48 , V_212 ) < 0 )
goto V_219;
V_216 = 1 ;
V_218:
V_214 ++ ;
}
}
V_219:
F_25 () ;
V_212 -> args [ 1 ] = V_214 ;
V_212 -> args [ 0 ] = V_17 ;
return V_48 -> V_102 ;
}
static void F_88 ( int V_107 , int type , T_3 V_69 , int V_220 , struct V_143 * V_144 )
{
struct V_1 * V_1 = F_36 ( V_144 -> V_221 -> V_31 ) ;
T_2 V_24 = F_29 ( V_144 -> V_221 -> V_31 ) ;
struct V_2 * V_15 ;
struct V_109 V_110 = {
. V_126 = V_222 ,
. V_132 = type ,
. V_122 = V_69 ,
. V_121 = V_220 ,
. V_147 = V_144 -> V_148 ,
. V_141 = V_144 -> V_221 -> V_31 -> V_84 ,
. V_124 = V_125 | V_223 ,
. V_112 = {
. V_113 = V_1 ,
} ,
} ;
if ( ! V_24 )
V_24 = ( type == V_42 ) ? V_5 : V_7 ;
V_15 = F_5 ( V_1 , V_24 ) ;
if ( ! V_15 )
return;
V_110 . V_142 = V_15 -> V_24 ;
if ( type != V_82 )
V_110 . V_131 = V_67 ;
else
V_110 . V_131 = V_90 ;
if ( V_107 == V_224 )
F_71 ( V_1 , V_15 , & V_110 ) ;
else
F_70 ( V_1 , V_15 , & V_110 ) ;
}
void F_89 ( struct V_143 * V_144 )
{
struct V_49 * V_50 = V_144 -> V_221 ;
struct V_30 * V_31 = V_50 -> V_31 ;
struct V_143 * V_225 = V_144 ;
T_3 V_119 = V_144 -> V_226 ;
T_3 V_32 = V_144 -> V_148 ;
T_3 V_227 = V_144 -> V_228 & V_119 ;
if ( V_144 -> V_229 & V_230 ) {
V_225 = F_90 ( V_50 , V_227 , V_119 ) ;
if ( ! V_225 ) {
F_91 ( L_1 , V_231 ) ;
return;
}
}
F_88 ( V_224 , V_82 , V_32 , 32 , V_225 ) ;
if ( ! ( V_31 -> V_232 & V_233 ) )
return;
if ( V_144 -> V_234 && V_144 -> V_234 != F_92 ( 0xFFFFFFFF ) )
F_88 ( V_224 , V_39 , V_144 -> V_234 , 32 , V_225 ) ;
if ( ! F_20 ( V_227 ) && ! ( V_144 -> V_229 & V_230 ) &&
( V_227 != V_32 || V_144 -> V_235 < 32 ) ) {
if ( ! ( V_144 -> V_229 & V_236 ) )
F_88 ( V_224 ,
V_31 -> V_232 & V_237 ? V_82 : V_42 ,
V_227 , V_144 -> V_235 , V_225 ) ;
if ( V_144 -> V_235 < 31 ) {
F_88 ( V_224 , V_39 , V_227 , 32 , V_225 ) ;
F_88 ( V_224 , V_39 , V_227 | ~ V_119 ,
32 , V_225 ) ;
}
}
}
void F_93 ( struct V_143 * V_144 , struct V_143 * V_238 )
{
struct V_49 * V_50 = V_144 -> V_221 ;
struct V_30 * V_31 = V_50 -> V_31 ;
struct V_143 * V_239 ;
struct V_143 * V_225 = V_144 , * V_240 = NULL ;
T_3 V_241 = V_144 -> V_228 | ~ V_144 -> V_226 ;
T_3 V_242 = V_144 -> V_228 & V_144 -> V_226 ;
#define F_94 1
#define F_95 2
#define F_96 4
#define F_97 8
unsigned int V_243 = 0 ;
int V_244 = 0 ;
int V_245 = 1 ;
int V_246 = 0 ;
if ( V_144 -> V_229 & V_230 ) {
V_225 = F_90 ( V_50 , V_242 , V_144 -> V_226 ) ;
if ( ! V_225 ) {
if ( ! V_50 -> V_247 )
F_91 ( L_1 , V_231 ) ;
return;
}
if ( V_238 && V_238 != V_225 ) {
F_91 ( L_2 , V_231 ) ;
return;
}
} else if ( ! F_20 ( V_242 ) &&
( V_242 != V_144 -> V_148 || V_144 -> V_235 < 32 ) ) {
if ( ! ( V_144 -> V_229 & V_236 ) )
F_88 ( V_248 ,
V_31 -> V_232 & V_237 ? V_82 : V_42 ,
V_242 , V_144 -> V_235 , V_225 ) ;
V_244 = 1 ;
}
if ( V_50 -> V_247 )
goto V_249;
for ( V_239 = V_50 -> V_80 ; V_239 ; V_239 = V_239 -> V_145 ) {
if ( V_239 == V_144 ) {
V_245 = 0 ;
continue;
}
if ( V_238 && V_239 -> V_226 == V_238 -> V_226 &&
F_98 ( V_239 -> V_228 , V_238 ) )
continue;
if ( V_239 -> V_229 & V_230 ) {
if ( V_239 -> V_226 == V_225 -> V_226 &&
F_98 ( V_239 -> V_228 , V_225 ) )
V_240 = V_225 ;
else {
if ( ! V_246 )
continue;
if ( ! V_240 ||
V_239 -> V_226 != V_240 -> V_226 ||
! F_98 ( V_239 -> V_228 , V_240 ) )
V_240 = F_90 ( V_50 ,
V_239 -> V_228 ,
V_239 -> V_226 ) ;
if ( ! V_240 )
continue;
if ( V_240 -> V_148 != V_225 -> V_148 )
continue;
}
} else {
if ( V_225 -> V_148 != V_239 -> V_148 )
continue;
V_240 = V_239 ;
if ( V_225 != V_240 )
V_246 = 1 ;
}
if ( V_144 -> V_148 == V_239 -> V_148 )
V_243 |= F_94 ;
if ( V_144 -> V_234 == V_239 -> V_234 )
V_243 |= F_95 ;
if ( V_241 == V_239 -> V_234 )
V_243 |= F_97 ;
if ( V_242 == V_239 -> V_234 )
V_243 |= F_96 ;
if ( V_240 == V_239 && V_239 -> V_235 < 31 ) {
T_3 V_250 = V_239 -> V_228 | ~ V_239 -> V_226 ;
T_3 V_251 = V_239 -> V_228 & V_239 -> V_226 ;
if ( ! F_20 ( V_251 ) ) {
if ( V_144 -> V_234 == V_250 ||
V_144 -> V_234 == V_251 )
V_243 |= F_95 ;
if ( V_241 == V_250 || V_241 == V_251 )
V_243 |= F_97 ;
if ( V_242 == V_250 || V_242 == V_251 )
V_243 |= F_96 ;
}
}
}
V_249:
if ( ! ( V_243 & F_95 ) )
F_88 ( V_248 , V_39 , V_144 -> V_234 , 32 , V_225 ) ;
if ( V_244 && V_144 -> V_235 < 31 ) {
if ( ! ( V_243 & F_97 ) )
F_88 ( V_248 , V_39 , V_241 , 32 , V_225 ) ;
if ( ! ( V_243 & F_96 ) )
F_88 ( V_248 , V_39 , V_242 , 32 , V_225 ) ;
}
if ( ! ( V_243 & F_94 ) ) {
unsigned int V_150 ;
F_88 ( V_248 , V_82 , V_144 -> V_148 , 32 , V_225 ) ;
V_150 = F_30 ( F_36 ( V_31 ) , V_31 ,
V_144 -> V_148 ) ;
if ( V_245 && V_150 != V_82 ) {
if ( F_99 ( V_31 , V_144 -> V_148 ) )
F_15 ( F_36 ( V_31 ) ) ;
}
}
#undef F_94
#undef F_95
#undef F_96
#undef F_97
}
static void F_100 ( struct V_1 * V_1 , struct V_252 * V_253 )
{
struct V_36 V_37 ;
struct V_33 V_34 = {
. V_65 = V_253 -> V_254 ,
. V_35 = V_253 -> V_255 ,
. V_62 = V_253 -> V_256 ,
. V_64 = V_253 -> V_257 ,
} ;
struct V_2 * V_15 ;
F_23 () ;
V_15 = F_6 ( V_1 , V_253 -> V_258 ) ;
V_253 -> V_166 = - V_259 ;
if ( V_15 ) {
F_101 () ;
V_253 -> V_24 = V_15 -> V_24 ;
V_253 -> V_166 = F_24 ( V_15 , & V_34 , & V_37 , V_43 ) ;
if ( ! V_253 -> V_166 ) {
V_253 -> V_260 = V_37 . V_260 ;
V_253 -> V_261 = V_37 . V_261 ;
V_253 -> type = V_37 . type ;
V_253 -> V_53 = V_37 . V_53 ;
}
F_102 () ;
}
F_25 () ;
}
static void F_103 ( struct V_47 * V_48 )
{
struct V_1 * V_1 ;
struct V_252 * V_253 ;
struct V_173 * V_174 ;
T_2 V_192 ;
V_1 = F_83 ( V_48 -> V_210 ) ;
V_174 = F_104 ( V_48 ) ;
if ( V_48 -> V_102 < V_262 || V_48 -> V_102 < V_174 -> F_86 ||
F_86 ( V_174 ) < sizeof( * V_253 ) )
return;
V_48 = F_105 ( V_48 , V_156 ) ;
if ( ! V_48 )
return;
V_174 = F_104 ( V_48 ) ;
V_253 = (struct V_252 * ) F_76 ( V_174 ) ;
F_100 ( V_1 , V_253 ) ;
V_192 = F_77 ( V_48 ) . V_192 ;
F_77 ( V_48 ) . V_192 = 0 ;
F_77 ( V_48 ) . V_263 = 0 ;
F_106 ( V_1 -> V_10 . V_264 , V_48 , V_192 , V_265 ) ;
}
static int T_1 F_107 ( struct V_1 * V_1 )
{
struct V_266 * V_210 ;
struct V_267 V_110 = {
. V_268 = F_103 ,
} ;
V_210 = F_108 ( V_1 , V_269 , & V_110 ) ;
if ( ! V_210 )
return - V_117 ;
V_1 -> V_10 . V_264 = V_210 ;
return 0 ;
}
static void F_109 ( struct V_1 * V_1 )
{
F_110 ( V_1 -> V_10 . V_264 ) ;
V_1 -> V_10 . V_264 = NULL ;
}
static void F_111 ( struct V_30 * V_31 , unsigned long V_270 ,
bool V_271 )
{
if ( F_112 ( V_31 , V_270 , V_271 ) )
F_15 ( F_36 ( V_31 ) ) ;
F_18 ( F_36 ( V_31 ) ) ;
F_113 ( V_31 ) ;
}
static int F_114 ( struct V_272 * V_273 , unsigned long V_270 , void * V_274 )
{
struct V_143 * V_144 = (struct V_143 * ) V_274 ;
struct V_30 * V_31 = V_144 -> V_221 -> V_31 ;
struct V_1 * V_1 = F_36 ( V_31 ) ;
switch ( V_270 ) {
case V_275 :
F_89 ( V_144 ) ;
#ifdef F_49
F_115 ( V_31 , V_276 ) ;
#endif
F_116 ( & V_1 -> V_10 . V_277 ) ;
F_18 ( F_36 ( V_31 ) ) ;
break;
case V_278 :
F_93 ( V_144 , NULL ) ;
F_116 ( & V_1 -> V_10 . V_277 ) ;
if ( ! V_144 -> V_221 -> V_80 ) {
F_111 ( V_31 , V_270 , true ) ;
} else {
F_18 ( F_36 ( V_31 ) ) ;
}
break;
}
return V_279 ;
}
static int F_117 ( struct V_272 * V_273 , unsigned long V_270 , void * V_274 )
{
struct V_30 * V_31 = F_118 ( V_274 ) ;
struct V_280 * V_281 ;
struct V_49 * V_50 ;
struct V_1 * V_1 = F_36 ( V_31 ) ;
unsigned int V_232 ;
if ( V_270 == V_282 ) {
F_111 ( V_31 , V_270 , true ) ;
F_119 ( V_31 ) ;
return V_279 ;
}
V_50 = F_65 ( V_31 ) ;
if ( ! V_50 )
return V_279 ;
switch ( V_270 ) {
case V_275 :
F_120 (in_dev) {
F_89 ( V_144 ) ;
} F_121 ( V_50 ) ;
#ifdef F_49
F_115 ( V_31 , V_276 ) ;
#endif
F_116 ( & V_1 -> V_10 . V_277 ) ;
F_18 ( V_1 ) ;
break;
case V_278 :
F_111 ( V_31 , V_270 , false ) ;
break;
case V_283 :
V_232 = F_122 ( V_31 ) ;
if ( V_232 & ( V_284 | V_285 ) )
F_115 ( V_31 , V_286 ) ;
else
F_112 ( V_31 , V_270 , false ) ;
case V_287 :
F_18 ( V_1 ) ;
break;
case V_288 :
V_281 = V_274 ;
if ( V_281 -> V_289 && F_123 ( V_281 -> V_289 ) )
F_111 ( V_31 , V_278 , true ) ;
break;
}
return V_279 ;
}
static int T_1 F_124 ( struct V_1 * V_1 )
{
int V_166 ;
T_6 V_290 = sizeof( struct V_22 ) * V_21 ;
V_290 = F_125 ( T_6 , V_290 , V_291 ) ;
V_1 -> V_10 . V_11 = F_66 ( V_290 , V_156 ) ;
if ( ! V_1 -> V_10 . V_11 )
return - V_6 ;
V_166 = F_1 ( V_1 ) ;
if ( V_166 < 0 )
goto V_8;
return 0 ;
V_8:
F_72 ( V_1 -> V_10 . V_11 ) ;
return V_166 ;
}
static void F_126 ( struct V_1 * V_1 )
{
unsigned int V_292 ;
F_69 () ;
#ifdef F_10
F_127 ( V_1 -> V_10 . V_18 , NULL ) ;
F_127 ( V_1 -> V_10 . V_20 , NULL ) ;
#endif
for ( V_292 = 0 ; V_292 < V_21 ; V_292 ++ ) {
struct V_22 * V_23 = & V_1 -> V_10 . V_11 [ V_292 ] ;
struct V_28 * V_29 ;
struct V_2 * V_15 ;
F_16 (tb, tmp, head, tb_hlist) {
F_128 ( & V_15 -> V_9 ) ;
F_17 ( V_1 , V_15 ) ;
F_4 ( V_15 ) ;
}
}
#ifdef F_10
F_129 ( V_1 ) ;
#endif
F_73 () ;
F_72 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_130 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_131
V_1 -> V_10 . F_46 = 0 ;
#endif
error = F_124 ( V_1 ) ;
if ( error < 0 )
goto V_219;
error = F_107 ( V_1 ) ;
if ( error < 0 )
goto V_293;
error = F_132 ( V_1 ) ;
if ( error < 0 )
goto V_294;
V_219:
return error ;
V_294:
F_109 ( V_1 ) ;
V_293:
F_126 ( V_1 ) ;
goto V_219;
}
static void T_7 F_133 ( struct V_1 * V_1 )
{
F_134 ( V_1 ) ;
F_109 ( V_1 ) ;
F_126 ( V_1 ) ;
}
void T_8 F_135 ( void )
{
F_136 ( V_295 , V_224 , F_84 , NULL , NULL ) ;
F_136 ( V_295 , V_248 , F_82 , NULL , NULL ) ;
F_136 ( V_295 , V_296 , NULL , F_85 , NULL ) ;
F_137 ( & V_297 ) ;
F_138 ( & V_298 ) ;
F_139 ( & V_299 ) ;
F_140 () ;
}
