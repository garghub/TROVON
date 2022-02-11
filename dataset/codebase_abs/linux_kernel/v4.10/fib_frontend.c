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
struct V_1 * V_1 ;
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
V_75 = V_73 -> V_81 == NULL ;
V_35 . V_66 = F_38 ( V_73 ) ? V_49 -> V_67 : 0 ;
F_44 ( V_32 , & V_35 ) ;
V_1 = F_36 ( V_32 ) ;
if ( F_39 ( V_1 , & V_35 , & V_38 , 0 ) )
goto V_82;
if ( V_38 . type != V_43 &&
( V_38 . type != V_83 || ! F_45 ( V_73 ) ) )
goto V_84;
if ( ! V_72 && ! F_46 ( F_36 ( V_32 ) ) &&
( V_32 -> V_85 != V_71 || ! F_47 ( V_73 ) ) )
goto V_82;
F_48 ( V_74 , & V_38 ) ;
V_76 = false ;
#ifdef F_49
for ( V_39 = 0 ; V_39 < V_38 . V_45 -> V_86 ; V_39 ++ ) {
struct V_87 * V_88 = & V_38 . V_45 -> V_87 [ V_39 ] ;
if ( V_88 -> V_89 == V_32 ) {
V_76 = true ;
break;
} else if ( F_43 ( V_88 -> V_89 ) == V_32 -> V_85 ) {
V_76 = true ;
break;
}
}
#else
if ( F_50 ( V_38 ) == V_32 )
V_76 = true ;
#endif
if ( V_76 ) {
V_39 = F_51 ( V_38 ) . V_90 >= V_91 ;
return V_39 ;
}
if ( V_75 )
goto V_82;
if ( V_72 == 1 )
goto V_92;
V_35 . V_77 = V_32 -> V_85 ;
V_39 = 0 ;
if ( F_39 ( V_1 , & V_35 , & V_38 , V_93 ) == 0 ) {
if ( V_38 . type == V_43 )
V_39 = F_51 ( V_38 ) . V_90 >= V_91 ;
}
return V_39 ;
V_82:
if ( V_72 )
goto V_92;
* V_74 = 0 ;
return 0 ;
V_84:
return - V_94 ;
V_92:
return - V_95 ;
}
int F_52 ( struct V_48 * V_49 , T_3 V_69 , T_3 V_70 ,
T_4 V_64 , int V_71 , struct V_31 * V_32 ,
struct V_50 * V_73 , T_2 * V_74 )
{
int V_96 = F_53 ( V_49 ) ? 0 : F_54 ( V_73 ) ;
if ( ! V_96 && ! F_46 ( F_36 ( V_32 ) ) &&
F_45 ( V_73 ) &&
( V_32 -> V_85 != V_71 || ! F_47 ( V_73 ) ) ) {
* V_74 = 0 ;
return 0 ;
}
return F_42 ( V_49 , V_69 , V_70 , V_64 , V_71 , V_32 , V_96 , V_73 , V_74 ) ;
}
static inline T_3 F_55 ( struct V_97 * V_33 )
{
return ( (struct V_98 * ) V_33 ) -> V_99 . V_100 ;
}
static int F_56 ( struct V_101 * V_102 , int V_103 , int type , T_2 V_104 )
{
struct V_101 * V_105 ;
V_105 = (struct V_101 * ) ( ( char * ) V_102 + V_103 ) ;
V_105 -> V_106 = type ;
V_105 -> V_107 = F_57 ( 4 ) ;
* ( T_2 * ) F_58 ( V_105 ) = V_104 ;
return V_103 + F_59 ( 4 ) ;
}
static int F_60 ( struct V_1 * V_1 , int V_108 , struct V_109 * V_53 ,
struct V_110 * V_111 )
{
T_3 V_33 ;
int V_112 ;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_113 . V_114 = V_1 ;
if ( V_53 -> V_115 . V_116 != V_117 )
return - V_118 ;
V_112 = 32 ;
V_33 = F_55 ( & V_53 -> V_115 ) ;
if ( ! ( V_53 -> V_55 & V_119 ) ) {
T_3 V_120 = F_55 ( & V_53 -> V_121 ) ;
if ( V_53 -> V_121 . V_116 != V_117 ) {
if ( V_120 || V_53 -> V_121 . V_116 )
return - V_118 ;
}
if ( F_61 ( V_120 , V_33 ) )
return - V_94 ;
V_112 = F_62 ( V_120 ) ;
}
V_111 -> V_122 = V_112 ;
V_111 -> V_123 = V_33 ;
if ( V_108 != V_124 ) {
V_111 -> V_125 = V_126 ;
V_111 -> V_127 = V_128 ;
}
if ( V_53 -> V_129 )
V_111 -> V_130 = V_53 -> V_129 - 1 ;
if ( V_53 -> V_55 & V_131 ) {
V_111 -> V_132 = V_91 ;
V_111 -> V_133 = V_134 ;
return 0 ;
}
V_111 -> V_132 = V_135 ;
V_111 -> V_133 = V_43 ;
if ( V_53 -> V_136 ) {
char * V_137 ;
struct V_31 * V_32 ;
char V_138 [ V_139 ] ;
if ( F_63 ( V_138 , V_53 -> V_136 , V_139 - 1 ) )
return - V_140 ;
V_138 [ V_139 - 1 ] = 0 ;
V_137 = strchr ( V_138 , ':' ) ;
if ( V_137 )
* V_137 = 0 ;
V_32 = F_64 ( V_1 , V_138 ) ;
if ( ! V_32 )
return - V_141 ;
V_111 -> V_142 = V_32 -> V_85 ;
V_111 -> V_143 = F_29 ( V_32 ) ;
if ( V_137 ) {
struct V_144 * V_145 ;
struct V_50 * V_51 = F_65 ( V_32 ) ;
if ( ! V_51 )
return - V_141 ;
* V_137 = ':' ;
for ( V_145 = V_51 -> V_81 ; V_145 ; V_145 = V_145 -> V_146 )
if ( strcmp ( V_145 -> V_147 , V_138 ) == 0 )
break;
if ( ! V_145 )
return - V_141 ;
V_111 -> V_148 = V_145 -> V_149 ;
}
}
V_33 = F_55 ( & V_53 -> V_150 ) ;
if ( V_53 -> V_150 . V_116 == V_117 && V_33 ) {
unsigned int V_151 ;
V_111 -> V_152 = V_33 ;
V_151 = F_26 ( V_1 , V_33 , V_111 -> V_143 ) ;
if ( V_53 -> V_55 & V_153 &&
V_151 == V_43 )
V_111 -> V_132 = V_59 ;
}
if ( V_108 == V_124 )
return 0 ;
if ( V_53 -> V_55 & V_153 && ! V_111 -> V_152 )
return - V_94 ;
if ( V_111 -> V_132 == V_135 )
V_111 -> V_132 = V_68 ;
if ( V_53 -> V_55 & ( V_154 | V_155 | V_156 ) ) {
struct V_101 * V_102 ;
int V_103 = 0 ;
V_102 = F_66 ( 3 * F_59 ( 4 ) , V_157 ) ;
if ( ! V_102 )
return - V_6 ;
if ( V_53 -> V_55 & V_154 )
V_103 = F_56 ( V_102 , V_103 , V_158 , V_53 -> V_159 - 40 ) ;
if ( V_53 -> V_55 & V_155 )
V_103 = F_56 ( V_102 , V_103 , V_160 , V_53 -> V_161 ) ;
if ( V_53 -> V_55 & V_156 )
V_103 = F_56 ( V_102 , V_103 , V_162 , V_53 -> V_163 << 3 ) ;
V_111 -> V_164 = V_102 ;
V_111 -> V_165 = V_103 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_1 , unsigned int V_108 , void T_5 * V_166 )
{
struct V_110 V_111 ;
struct V_109 V_53 ;
int V_167 ;
switch ( V_108 ) {
case V_168 :
case V_124 :
if ( ! F_68 ( V_1 -> V_169 , V_170 ) )
return - V_171 ;
if ( F_63 ( & V_53 , V_166 , sizeof( V_53 ) ) )
return - V_140 ;
F_69 () ;
V_167 = F_60 ( V_1 , V_108 , & V_53 , & V_111 ) ;
if ( V_167 == 0 ) {
struct V_2 * V_15 ;
if ( V_108 == V_124 ) {
V_15 = F_6 ( V_1 , V_111 . V_143 ) ;
if ( V_15 )
V_167 = F_70 ( V_1 , V_15 , & V_111 ) ;
else
V_167 = - V_172 ;
} else {
V_15 = F_5 ( V_1 , V_111 . V_143 ) ;
if ( V_15 )
V_167 = F_71 ( V_1 , V_15 , & V_111 ) ;
else
V_167 = - V_173 ;
}
F_72 ( V_111 . V_164 ) ;
}
F_73 () ;
return V_167 ;
}
return - V_94 ;
}
static int F_74 ( struct V_1 * V_1 , struct V_48 * V_49 ,
struct V_174 * V_175 , struct V_110 * V_111 )
{
struct V_101 * V_176 ;
int V_167 , V_177 ;
struct V_178 * V_179 ;
V_167 = F_75 ( V_175 , sizeof( * V_179 ) , V_180 , V_181 ) ;
if ( V_167 < 0 )
goto V_182;
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_179 = F_76 ( V_175 ) ;
V_111 -> V_122 = V_179 -> V_183 ;
V_111 -> V_184 = V_179 -> V_185 ;
V_111 -> V_143 = V_179 -> V_186 ;
V_111 -> V_127 = V_179 -> V_187 ;
V_111 -> V_132 = V_179 -> V_188 ;
V_111 -> V_133 = V_179 -> V_189 ;
V_111 -> V_190 = V_179 -> V_191 ;
V_111 -> V_125 = V_175 -> V_192 ;
V_111 -> V_113 . V_193 = F_77 ( V_49 ) . V_193 ;
V_111 -> V_113 . V_175 = V_175 ;
V_111 -> V_113 . V_114 = V_1 ;
if ( V_111 -> V_133 > V_194 ) {
V_167 = - V_94 ;
goto V_182;
}
F_78 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_106 ( V_176 ) ) {
case V_195 :
V_111 -> V_123 = F_79 ( V_176 ) ;
break;
case V_196 :
V_111 -> V_142 = F_80 ( V_176 ) ;
break;
case V_197 :
V_111 -> V_152 = F_79 ( V_176 ) ;
break;
case V_198 :
V_111 -> V_130 = F_80 ( V_176 ) ;
break;
case V_199 :
V_111 -> V_148 = F_79 ( V_176 ) ;
break;
case V_200 :
V_111 -> V_164 = F_58 ( V_176 ) ;
V_111 -> V_165 = V_107 ( V_176 ) ;
break;
case V_201 :
V_167 = F_81 ( F_58 ( V_176 ) ,
V_107 ( V_176 ) ) ;
if ( V_167 < 0 )
goto V_182;
V_111 -> V_202 = F_58 ( V_176 ) ;
V_111 -> V_203 = V_107 ( V_176 ) ;
break;
case V_204 :
V_111 -> V_205 = F_80 ( V_176 ) ;
break;
case V_206 :
V_111 -> V_143 = F_80 ( V_176 ) ;
break;
case V_207 :
V_111 -> V_208 = V_176 ;
break;
case V_209 :
V_111 -> V_210 = F_82 ( V_176 ) ;
V_167 = F_83 ( V_111 -> V_210 ) ;
if ( V_167 < 0 )
goto V_182;
break;
}
}
return 0 ;
V_182:
return V_167 ;
}
static int F_84 ( struct V_48 * V_49 , struct V_174 * V_175 )
{
struct V_1 * V_1 = F_85 ( V_49 -> V_211 ) ;
struct V_110 V_111 ;
struct V_2 * V_15 ;
int V_167 ;
V_167 = F_74 ( V_1 , V_49 , V_175 , & V_111 ) ;
if ( V_167 < 0 )
goto V_182;
V_15 = F_6 ( V_1 , V_111 . V_143 ) ;
if ( ! V_15 ) {
V_167 = - V_172 ;
goto V_182;
}
V_167 = F_70 ( V_1 , V_15 , & V_111 ) ;
V_182:
return V_167 ;
}
static int F_86 ( struct V_48 * V_49 , struct V_174 * V_175 )
{
struct V_1 * V_1 = F_85 ( V_49 -> V_211 ) ;
struct V_110 V_111 ;
struct V_2 * V_15 ;
int V_167 ;
V_167 = F_74 ( V_1 , V_49 , V_175 , & V_111 ) ;
if ( V_167 < 0 )
goto V_182;
V_15 = F_5 ( V_1 , V_111 . V_143 ) ;
if ( ! V_15 ) {
V_167 = - V_173 ;
goto V_182;
}
V_167 = F_71 ( V_1 , V_15 , & V_111 ) ;
V_182:
return V_167 ;
}
static int F_87 ( struct V_48 * V_49 , struct V_212 * V_213 )
{
struct V_1 * V_1 = F_85 ( V_49 -> V_211 ) ;
unsigned int V_17 , V_214 ;
unsigned int V_215 = 0 , V_216 ;
struct V_2 * V_15 ;
struct V_23 * V_24 ;
int V_217 = 0 ;
if ( F_88 ( V_213 -> V_175 ) >= sizeof( struct V_178 ) &&
( (struct V_178 * ) F_76 ( V_213 -> V_175 ) ) -> V_191 & V_218 )
return V_49 -> V_103 ;
V_214 = V_213 -> args [ 0 ] ;
V_216 = V_213 -> args [ 1 ] ;
F_23 () ;
for ( V_17 = V_214 ; V_17 < V_22 ; V_17 ++ , V_216 = 0 ) {
V_215 = 0 ;
V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_215 < V_216 )
goto V_219;
if ( V_217 )
memset ( & V_213 -> args [ 2 ] , 0 , sizeof( V_213 -> args ) -
2 * sizeof( V_213 -> args [ 0 ] ) ) ;
if ( F_89 ( V_15 , V_49 , V_213 ) < 0 )
goto V_220;
V_217 = 1 ;
V_219:
V_215 ++ ;
}
}
V_220:
F_25 () ;
V_213 -> args [ 1 ] = V_215 ;
V_213 -> args [ 0 ] = V_17 ;
return V_49 -> V_103 ;
}
static void F_90 ( int V_108 , int type , T_3 V_70 , int V_221 , struct V_144 * V_145 )
{
struct V_1 * V_1 = F_36 ( V_145 -> V_222 -> V_32 ) ;
T_2 V_25 = F_29 ( V_145 -> V_222 -> V_32 ) ;
struct V_2 * V_15 ;
struct V_110 V_111 = {
. V_127 = V_223 ,
. V_133 = type ,
. V_123 = V_70 ,
. V_122 = V_221 ,
. V_148 = V_145 -> V_149 ,
. V_142 = V_145 -> V_222 -> V_32 -> V_85 ,
. V_125 = V_126 | V_224 ,
. V_113 = {
. V_114 = V_1 ,
} ,
} ;
if ( ! V_25 )
V_25 = ( type == V_43 ) ? V_5 : V_7 ;
V_15 = F_5 ( V_1 , V_25 ) ;
if ( ! V_15 )
return;
V_111 . V_143 = V_15 -> V_25 ;
if ( type != V_83 )
V_111 . V_132 = V_68 ;
else
V_111 . V_132 = V_91 ;
if ( V_108 == V_225 )
F_71 ( V_1 , V_15 , & V_111 ) ;
else
F_70 ( V_1 , V_15 , & V_111 ) ;
}
void F_91 ( struct V_144 * V_145 )
{
struct V_50 * V_51 = V_145 -> V_222 ;
struct V_31 * V_32 = V_51 -> V_32 ;
struct V_144 * V_226 = V_145 ;
T_3 V_120 = V_145 -> V_227 ;
T_3 V_33 = V_145 -> V_149 ;
T_3 V_228 = V_145 -> V_229 & V_120 ;
if ( V_145 -> V_230 & V_231 ) {
V_226 = F_92 ( V_51 , V_228 , V_120 ) ;
if ( ! V_226 ) {
F_93 ( L_1 , V_232 ) ;
return;
}
}
F_90 ( V_225 , V_83 , V_33 , 32 , V_226 ) ;
if ( ! ( V_32 -> V_233 & V_234 ) )
return;
if ( V_145 -> V_235 && V_145 -> V_235 != F_94 ( 0xFFFFFFFF ) )
F_90 ( V_225 , V_40 , V_145 -> V_235 , 32 , V_226 ) ;
if ( ! F_20 ( V_228 ) && ! ( V_145 -> V_230 & V_231 ) &&
( V_228 != V_33 || V_145 -> V_236 < 32 ) ) {
if ( ! ( V_145 -> V_230 & V_237 ) )
F_90 ( V_225 ,
V_32 -> V_233 & V_238 ? V_83 : V_43 ,
V_228 , V_145 -> V_236 , V_226 ) ;
if ( V_145 -> V_236 < 31 ) {
F_90 ( V_225 , V_40 , V_228 , 32 , V_226 ) ;
F_90 ( V_225 , V_40 , V_228 | ~ V_120 ,
32 , V_226 ) ;
}
}
}
void F_95 ( struct V_144 * V_145 , struct V_144 * V_239 )
{
struct V_50 * V_51 = V_145 -> V_222 ;
struct V_31 * V_32 = V_51 -> V_32 ;
struct V_144 * V_240 ;
struct V_144 * V_226 = V_145 , * V_241 = NULL ;
T_3 V_242 = V_145 -> V_229 | ~ V_145 -> V_227 ;
T_3 V_243 = V_145 -> V_229 & V_145 -> V_227 ;
#define F_96 1
#define F_97 2
#define F_98 4
#define F_99 8
unsigned int V_244 = 0 ;
int V_245 = 0 ;
int V_246 = 1 ;
int V_247 = 0 ;
if ( V_145 -> V_230 & V_231 ) {
V_226 = F_92 ( V_51 , V_243 , V_145 -> V_227 ) ;
if ( ! V_226 ) {
if ( ! V_51 -> V_248 )
F_93 ( L_1 , V_232 ) ;
return;
}
if ( V_239 && V_239 != V_226 ) {
F_93 ( L_2 , V_232 ) ;
return;
}
} else if ( ! F_20 ( V_243 ) &&
( V_243 != V_145 -> V_149 || V_145 -> V_236 < 32 ) ) {
if ( ! ( V_145 -> V_230 & V_237 ) )
F_90 ( V_249 ,
V_32 -> V_233 & V_238 ? V_83 : V_43 ,
V_243 , V_145 -> V_236 , V_226 ) ;
V_245 = 1 ;
}
if ( V_51 -> V_248 )
goto V_250;
for ( V_240 = V_51 -> V_81 ; V_240 ; V_240 = V_240 -> V_146 ) {
if ( V_240 == V_145 ) {
V_246 = 0 ;
continue;
}
if ( V_239 && V_240 -> V_227 == V_239 -> V_227 &&
F_100 ( V_240 -> V_229 , V_239 ) )
continue;
if ( V_240 -> V_230 & V_231 ) {
if ( V_240 -> V_227 == V_226 -> V_227 &&
F_100 ( V_240 -> V_229 , V_226 ) )
V_241 = V_226 ;
else {
if ( ! V_247 )
continue;
if ( ! V_241 ||
V_240 -> V_227 != V_241 -> V_227 ||
! F_100 ( V_240 -> V_229 , V_241 ) )
V_241 = F_92 ( V_51 ,
V_240 -> V_229 ,
V_240 -> V_227 ) ;
if ( ! V_241 )
continue;
if ( V_241 -> V_149 != V_226 -> V_149 )
continue;
}
} else {
if ( V_226 -> V_149 != V_240 -> V_149 )
continue;
V_241 = V_240 ;
if ( V_226 != V_241 )
V_247 = 1 ;
}
if ( V_145 -> V_149 == V_240 -> V_149 )
V_244 |= F_96 ;
if ( V_145 -> V_235 == V_240 -> V_235 )
V_244 |= F_97 ;
if ( V_242 == V_240 -> V_235 )
V_244 |= F_99 ;
if ( V_243 == V_240 -> V_235 )
V_244 |= F_98 ;
if ( V_241 == V_240 && V_240 -> V_236 < 31 ) {
T_3 V_251 = V_240 -> V_229 | ~ V_240 -> V_227 ;
T_3 V_252 = V_240 -> V_229 & V_240 -> V_227 ;
if ( ! F_20 ( V_252 ) ) {
if ( V_145 -> V_235 == V_251 ||
V_145 -> V_235 == V_252 )
V_244 |= F_97 ;
if ( V_242 == V_251 || V_242 == V_252 )
V_244 |= F_99 ;
if ( V_243 == V_251 || V_243 == V_252 )
V_244 |= F_98 ;
}
}
}
V_250:
if ( ! ( V_244 & F_97 ) )
F_90 ( V_249 , V_40 , V_145 -> V_235 , 32 , V_226 ) ;
if ( V_245 && V_145 -> V_236 < 31 ) {
if ( ! ( V_244 & F_99 ) )
F_90 ( V_249 , V_40 , V_242 , 32 , V_226 ) ;
if ( ! ( V_244 & F_98 ) )
F_90 ( V_249 , V_40 , V_243 , 32 , V_226 ) ;
}
if ( ! ( V_244 & F_96 ) ) {
unsigned int V_151 ;
F_90 ( V_249 , V_83 , V_145 -> V_149 , 32 , V_226 ) ;
V_151 = F_30 ( F_36 ( V_32 ) , V_32 ,
V_145 -> V_149 ) ;
if ( V_246 && V_151 != V_83 ) {
if ( F_101 ( V_32 , V_145 -> V_149 ) )
F_15 ( F_36 ( V_32 ) ) ;
}
}
#undef F_96
#undef F_97
#undef F_98
#undef F_99
}
static void F_102 ( struct V_1 * V_1 , struct V_253 * V_254 )
{
struct V_37 V_38 ;
struct V_34 V_35 = {
. V_66 = V_254 -> V_255 ,
. V_36 = V_254 -> V_256 ,
. V_63 = V_254 -> V_257 ,
. V_65 = V_254 -> V_258 ,
} ;
struct V_2 * V_15 ;
F_23 () ;
V_15 = F_6 ( V_1 , V_254 -> V_259 ) ;
V_254 -> V_167 = - V_260 ;
if ( V_15 ) {
F_103 () ;
V_254 -> V_25 = V_15 -> V_25 ;
V_254 -> V_167 = F_24 ( V_15 , & V_35 , & V_38 , V_44 ) ;
if ( ! V_254 -> V_167 ) {
V_254 -> V_261 = V_38 . V_261 ;
V_254 -> V_262 = V_38 . V_262 ;
V_254 -> type = V_38 . type ;
V_254 -> V_54 = V_38 . V_54 ;
}
F_104 () ;
}
F_25 () ;
}
static void F_105 ( struct V_48 * V_49 )
{
struct V_1 * V_1 ;
struct V_253 * V_254 ;
struct V_174 * V_175 ;
T_2 V_193 ;
V_1 = F_85 ( V_49 -> V_211 ) ;
V_175 = F_106 ( V_49 ) ;
if ( V_49 -> V_103 < V_263 || V_49 -> V_103 < V_175 -> F_88 ||
F_88 ( V_175 ) < sizeof( * V_254 ) )
return;
V_49 = F_107 ( V_49 , V_157 ) ;
if ( ! V_49 )
return;
V_175 = F_106 ( V_49 ) ;
V_254 = (struct V_253 * ) F_76 ( V_175 ) ;
F_102 ( V_1 , V_254 ) ;
V_193 = F_77 ( V_49 ) . V_193 ;
F_77 ( V_49 ) . V_193 = 0 ;
F_77 ( V_49 ) . V_264 = 0 ;
F_108 ( V_1 -> V_10 . V_265 , V_49 , V_193 , V_266 ) ;
}
static int T_1 F_109 ( struct V_1 * V_1 )
{
struct V_267 * V_211 ;
struct V_268 V_111 = {
. V_269 = F_105 ,
} ;
V_211 = F_110 ( V_1 , V_270 , & V_111 ) ;
if ( ! V_211 )
return - V_118 ;
V_1 -> V_10 . V_265 = V_211 ;
return 0 ;
}
static void F_111 ( struct V_1 * V_1 )
{
F_112 ( V_1 -> V_10 . V_265 ) ;
V_1 -> V_10 . V_265 = NULL ;
}
static void F_113 ( struct V_31 * V_32 , unsigned long V_271 ,
bool V_272 )
{
if ( F_114 ( V_32 , V_271 , V_272 ) )
F_15 ( F_36 ( V_32 ) ) ;
F_18 ( F_36 ( V_32 ) ) ;
F_115 ( V_32 ) ;
}
static int F_116 ( struct V_273 * V_274 , unsigned long V_271 , void * V_275 )
{
struct V_144 * V_145 = (struct V_144 * ) V_275 ;
struct V_31 * V_32 = V_145 -> V_222 -> V_32 ;
struct V_1 * V_1 = F_36 ( V_32 ) ;
switch ( V_271 ) {
case V_276 :
F_91 ( V_145 ) ;
#ifdef F_49
F_117 ( V_32 , V_277 ) ;
#endif
F_118 ( & V_1 -> V_10 . V_278 ) ;
F_18 ( F_36 ( V_32 ) ) ;
break;
case V_279 :
F_95 ( V_145 , NULL ) ;
F_118 ( & V_1 -> V_10 . V_278 ) ;
if ( ! V_145 -> V_222 -> V_81 ) {
F_113 ( V_32 , V_271 , true ) ;
} else {
F_18 ( F_36 ( V_32 ) ) ;
}
break;
}
return V_280 ;
}
static int F_119 ( struct V_273 * V_274 , unsigned long V_271 , void * V_275 )
{
struct V_31 * V_32 = F_120 ( V_275 ) ;
struct V_281 * V_282 ;
struct V_50 * V_51 ;
struct V_1 * V_1 = F_36 ( V_32 ) ;
unsigned int V_233 ;
if ( V_271 == V_283 ) {
F_113 ( V_32 , V_271 , true ) ;
F_121 ( V_32 ) ;
return V_280 ;
}
V_51 = F_65 ( V_32 ) ;
if ( ! V_51 )
return V_280 ;
switch ( V_271 ) {
case V_276 :
F_122 (in_dev) {
F_91 ( V_145 ) ;
} F_123 ( V_51 ) ;
#ifdef F_49
F_117 ( V_32 , V_277 ) ;
#endif
F_118 ( & V_1 -> V_10 . V_278 ) ;
F_18 ( V_1 ) ;
break;
case V_279 :
F_113 ( V_32 , V_271 , false ) ;
break;
case V_284 :
V_233 = F_124 ( V_32 ) ;
if ( V_233 & ( V_285 | V_286 ) )
F_117 ( V_32 , V_287 ) ;
else
F_114 ( V_32 , V_271 , false ) ;
case V_288 :
F_18 ( V_1 ) ;
break;
case V_289 :
V_282 = V_275 ;
if ( V_282 -> V_290 && F_125 ( V_282 -> V_290 ) )
F_113 ( V_32 , V_279 , true ) ;
break;
}
return V_280 ;
}
static int T_1 F_126 ( struct V_1 * V_1 )
{
int V_167 ;
T_6 V_291 = sizeof( struct V_23 ) * V_22 ;
V_1 -> V_10 . V_292 = 0 ;
V_291 = F_127 ( T_6 , V_291 , V_293 ) ;
V_1 -> V_10 . V_11 = F_66 ( V_291 , V_157 ) ;
if ( ! V_1 -> V_10 . V_11 )
return - V_6 ;
V_167 = F_1 ( V_1 ) ;
if ( V_167 < 0 )
goto V_8;
return 0 ;
V_8:
F_72 ( V_1 -> V_10 . V_11 ) ;
return V_167 ;
}
static void F_128 ( struct V_1 * V_1 )
{
unsigned int V_294 ;
F_69 () ;
#ifdef F_10
F_129 ( V_1 -> V_10 . V_19 , NULL ) ;
F_129 ( V_1 -> V_10 . V_21 , NULL ) ;
#endif
for ( V_294 = 0 ; V_294 < V_22 ; V_294 ++ ) {
struct V_23 * V_24 = & V_1 -> V_10 . V_11 [ V_294 ] ;
struct V_29 * V_30 ;
struct V_2 * V_15 ;
F_16 (tb, tmp, head, tb_hlist) {
F_130 ( & V_15 -> V_9 ) ;
F_17 ( V_1 , V_15 ) ;
F_4 ( V_15 ) ;
}
}
#ifdef F_10
F_131 ( V_1 ) ;
#endif
F_73 () ;
F_72 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_132 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_133
V_1 -> V_10 . F_46 = 0 ;
#endif
error = F_126 ( V_1 ) ;
if ( error < 0 )
goto V_220;
error = F_109 ( V_1 ) ;
if ( error < 0 )
goto V_295;
error = F_134 ( V_1 ) ;
if ( error < 0 )
goto V_296;
V_220:
return error ;
V_296:
F_111 ( V_1 ) ;
V_295:
F_128 ( V_1 ) ;
goto V_220;
}
static void T_7 F_135 ( struct V_1 * V_1 )
{
F_136 ( V_1 ) ;
F_111 ( V_1 ) ;
F_128 ( V_1 ) ;
}
void T_8 F_137 ( void )
{
F_138 ( V_297 , V_225 , F_86 , NULL , NULL ) ;
F_138 ( V_297 , V_249 , F_84 , NULL , NULL ) ;
F_138 ( V_297 , V_298 , NULL , F_87 , NULL ) ;
F_139 ( & V_299 ) ;
F_140 ( & V_300 ) ;
F_141 ( & V_301 ) ;
F_142 () ;
}
