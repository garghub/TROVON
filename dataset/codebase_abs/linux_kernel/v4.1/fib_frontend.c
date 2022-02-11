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
if ( ! F_38 ( V_1 , & V_35 , & V_38 ) )
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
if ( F_38 ( V_1 , & V_35 , & V_38 ) )
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
if ( F_38 ( V_1 , & V_35 , & V_38 ) == 0 ) {
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
return - V_88 ;
V_87:
return - V_89 ;
}
int F_49 ( struct V_46 * V_47 , T_3 V_68 , T_3 V_69 ,
T_4 V_63 , int V_70 , struct V_31 * V_32 ,
struct V_48 * V_72 , T_2 * V_73 )
{
int V_90 = F_50 ( V_47 ) ? 0 : F_51 ( V_72 ) ;
if ( ! V_90 && ! F_43 ( F_35 ( V_32 ) ) &&
F_42 ( V_72 ) &&
( V_32 -> V_80 != V_70 || ! F_44 ( V_72 ) ) ) {
* V_73 = 0 ;
return 0 ;
}
return F_41 ( V_47 , V_68 , V_69 , V_63 , V_70 , V_32 , V_90 , V_72 , V_73 ) ;
}
static inline T_3 F_52 ( struct V_91 * V_33 )
{
return ( (struct V_92 * ) V_33 ) -> V_93 . V_94 ;
}
static int F_53 ( struct V_95 * V_96 , int V_97 , int type , T_2 V_98 )
{
struct V_95 * V_99 ;
V_99 = (struct V_95 * ) ( ( char * ) V_96 + V_97 ) ;
V_99 -> V_100 = type ;
V_99 -> V_101 = F_54 ( 4 ) ;
* ( T_2 * ) F_55 ( V_99 ) = V_98 ;
return V_97 + F_56 ( 4 ) ;
}
static int F_57 ( struct V_1 * V_1 , int V_102 , struct V_103 * V_51 ,
struct V_104 * V_105 )
{
T_3 V_33 ;
int V_106 ;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_107 . V_108 = V_1 ;
if ( V_51 -> V_109 . V_110 != V_111 )
return - V_112 ;
V_106 = 32 ;
V_33 = F_52 ( & V_51 -> V_109 ) ;
if ( ! ( V_51 -> V_53 & V_113 ) ) {
T_3 V_114 = F_52 ( & V_51 -> V_115 ) ;
if ( V_51 -> V_115 . V_110 != V_111 ) {
if ( V_114 || V_51 -> V_115 . V_110 )
return - V_112 ;
}
if ( F_58 ( V_114 , V_33 ) )
return - V_88 ;
V_106 = F_59 ( V_114 ) ;
}
V_105 -> V_116 = V_106 ;
V_105 -> V_117 = V_33 ;
if ( V_102 != V_118 ) {
V_105 -> V_119 = V_120 ;
V_105 -> V_121 = V_122 ;
}
if ( V_51 -> V_123 )
V_105 -> V_124 = V_51 -> V_123 - 1 ;
if ( V_51 -> V_53 & V_125 ) {
V_105 -> V_126 = V_86 ;
V_105 -> V_127 = V_128 ;
return 0 ;
}
V_105 -> V_126 = V_129 ;
V_105 -> V_127 = V_42 ;
if ( V_51 -> V_130 ) {
char * V_131 ;
struct V_31 * V_32 ;
char V_132 [ V_133 ] ;
if ( F_60 ( V_132 , V_51 -> V_130 , V_133 - 1 ) )
return - V_134 ;
V_132 [ V_133 - 1 ] = 0 ;
V_131 = strchr ( V_132 , ':' ) ;
if ( V_131 )
* V_131 = 0 ;
V_32 = F_61 ( V_1 , V_132 ) ;
if ( ! V_32 )
return - V_135 ;
V_105 -> V_136 = V_32 -> V_80 ;
if ( V_131 ) {
struct V_137 * V_138 ;
struct V_48 * V_49 = F_62 ( V_32 ) ;
if ( ! V_49 )
return - V_135 ;
* V_131 = ':' ;
for ( V_138 = V_49 -> V_76 ; V_138 ; V_138 = V_138 -> V_139 )
if ( strcmp ( V_138 -> V_140 , V_132 ) == 0 )
break;
if ( ! V_138 )
return - V_135 ;
V_105 -> V_141 = V_138 -> V_142 ;
}
}
V_33 = F_52 ( & V_51 -> V_143 ) ;
if ( V_51 -> V_143 . V_110 == V_111 && V_33 ) {
V_105 -> V_144 = V_33 ;
if ( V_51 -> V_53 & V_145 &&
F_28 ( V_1 , V_33 ) == V_42 )
V_105 -> V_126 = V_57 ;
}
if ( V_102 == V_118 )
return 0 ;
if ( V_51 -> V_53 & V_145 && ! V_105 -> V_144 )
return - V_88 ;
if ( V_105 -> V_126 == V_129 )
V_105 -> V_126 = V_67 ;
if ( V_51 -> V_53 & ( V_146 | V_147 | V_148 ) ) {
struct V_95 * V_96 ;
int V_97 = 0 ;
V_96 = F_63 ( 3 * F_56 ( 4 ) , V_149 ) ;
if ( ! V_96 )
return - V_6 ;
if ( V_51 -> V_53 & V_146 )
V_97 = F_53 ( V_96 , V_97 , V_150 , V_51 -> V_151 - 40 ) ;
if ( V_51 -> V_53 & V_147 )
V_97 = F_53 ( V_96 , V_97 , V_152 , V_51 -> V_153 ) ;
if ( V_51 -> V_53 & V_148 )
V_97 = F_53 ( V_96 , V_97 , V_154 , V_51 -> V_155 << 3 ) ;
V_105 -> V_156 = V_96 ;
V_105 -> V_157 = V_97 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_1 , unsigned int V_102 , void T_5 * V_158 )
{
struct V_104 V_105 ;
struct V_103 V_51 ;
int V_159 ;
switch ( V_102 ) {
case V_160 :
case V_118 :
if ( ! F_65 ( V_1 -> V_161 , V_162 ) )
return - V_163 ;
if ( F_60 ( & V_51 , V_158 , sizeof( V_51 ) ) )
return - V_134 ;
F_66 () ;
V_159 = F_57 ( V_1 , V_102 , & V_51 , & V_105 ) ;
if ( V_159 == 0 ) {
struct V_2 * V_15 ;
if ( V_102 == V_118 ) {
V_15 = F_6 ( V_1 , V_105 . V_164 ) ;
if ( V_15 )
V_159 = F_67 ( V_15 , & V_105 ) ;
else
V_159 = - V_165 ;
} else {
V_15 = F_5 ( V_1 , V_105 . V_164 ) ;
if ( V_15 )
V_159 = F_68 ( V_15 , & V_105 ) ;
else
V_159 = - V_166 ;
}
F_69 ( V_105 . V_156 ) ;
}
F_70 () ;
return V_159 ;
}
return - V_88 ;
}
static int F_71 ( struct V_1 * V_1 , struct V_46 * V_47 ,
struct V_167 * V_168 , struct V_104 * V_105 )
{
struct V_95 * V_169 ;
int V_159 , V_170 ;
struct V_171 * V_172 ;
V_159 = F_72 ( V_168 , sizeof( * V_172 ) , V_173 , V_174 ) ;
if ( V_159 < 0 )
goto V_175;
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_172 = F_73 ( V_168 ) ;
V_105 -> V_116 = V_172 -> V_176 ;
V_105 -> V_177 = V_172 -> V_178 ;
V_105 -> V_164 = V_172 -> V_179 ;
V_105 -> V_121 = V_172 -> V_180 ;
V_105 -> V_126 = V_172 -> V_181 ;
V_105 -> V_127 = V_172 -> V_182 ;
V_105 -> V_183 = V_172 -> V_184 ;
V_105 -> V_119 = V_168 -> V_185 ;
V_105 -> V_107 . V_186 = F_74 ( V_47 ) . V_186 ;
V_105 -> V_107 . V_168 = V_168 ;
V_105 -> V_107 . V_108 = V_1 ;
if ( V_105 -> V_127 > V_187 ) {
V_159 = - V_88 ;
goto V_175;
}
F_75 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_100 ( V_169 ) ) {
case V_188 :
V_105 -> V_117 = F_76 ( V_169 ) ;
break;
case V_189 :
V_105 -> V_136 = F_77 ( V_169 ) ;
break;
case V_190 :
V_105 -> V_144 = F_76 ( V_169 ) ;
break;
case V_191 :
V_105 -> V_124 = F_77 ( V_169 ) ;
break;
case V_192 :
V_105 -> V_141 = F_76 ( V_169 ) ;
break;
case V_193 :
V_105 -> V_156 = F_55 ( V_169 ) ;
V_105 -> V_157 = V_101 ( V_169 ) ;
break;
case V_194 :
V_105 -> V_195 = F_55 ( V_169 ) ;
V_105 -> V_196 = V_101 ( V_169 ) ;
break;
case V_197 :
V_105 -> V_198 = F_77 ( V_169 ) ;
break;
case V_199 :
V_105 -> V_164 = F_77 ( V_169 ) ;
break;
}
}
return 0 ;
V_175:
return V_159 ;
}
static int F_78 ( struct V_46 * V_47 , struct V_167 * V_168 )
{
struct V_1 * V_1 = F_79 ( V_47 -> V_200 ) ;
struct V_104 V_105 ;
struct V_2 * V_15 ;
int V_159 ;
V_159 = F_71 ( V_1 , V_47 , V_168 , & V_105 ) ;
if ( V_159 < 0 )
goto V_175;
V_15 = F_6 ( V_1 , V_105 . V_164 ) ;
if ( ! V_15 ) {
V_159 = - V_165 ;
goto V_175;
}
V_159 = F_67 ( V_15 , & V_105 ) ;
V_175:
return V_159 ;
}
static int F_80 ( struct V_46 * V_47 , struct V_167 * V_168 )
{
struct V_1 * V_1 = F_79 ( V_47 -> V_200 ) ;
struct V_104 V_105 ;
struct V_2 * V_15 ;
int V_159 ;
V_159 = F_71 ( V_1 , V_47 , V_168 , & V_105 ) ;
if ( V_159 < 0 )
goto V_175;
V_15 = F_5 ( V_1 , V_105 . V_164 ) ;
if ( ! V_15 ) {
V_159 = - V_166 ;
goto V_175;
}
V_159 = F_68 ( V_15 , & V_105 ) ;
V_175:
return V_159 ;
}
static int F_81 ( struct V_46 * V_47 , struct V_201 * V_202 )
{
struct V_1 * V_1 = F_79 ( V_47 -> V_200 ) ;
unsigned int V_17 , V_203 ;
unsigned int V_204 = 0 , V_205 ;
struct V_2 * V_15 ;
struct V_23 * V_24 ;
int V_206 = 0 ;
if ( F_82 ( V_202 -> V_168 ) >= sizeof( struct V_171 ) &&
( (struct V_171 * ) F_73 ( V_202 -> V_168 ) ) -> V_184 & V_207 )
return V_47 -> V_97 ;
V_203 = V_202 -> args [ 0 ] ;
V_205 = V_202 -> args [ 1 ] ;
F_25 () ;
for ( V_17 = V_203 ; V_17 < V_22 ; V_17 ++ , V_205 = 0 ) {
V_204 = 0 ;
V_24 = & V_1 -> V_10 . V_11 [ V_17 ] ;
F_8 (tb, head, tb_hlist) {
if ( V_204 < V_205 )
goto V_208;
if ( V_206 )
memset ( & V_202 -> args [ 2 ] , 0 , sizeof( V_202 -> args ) -
2 * sizeof( V_202 -> args [ 0 ] ) ) ;
if ( F_83 ( V_15 , V_47 , V_202 ) < 0 )
goto V_209;
V_206 = 1 ;
V_208:
V_204 ++ ;
}
}
V_209:
F_27 () ;
V_202 -> args [ 1 ] = V_204 ;
V_202 -> args [ 0 ] = V_17 ;
return V_47 -> V_97 ;
}
static void F_84 ( int V_102 , int type , T_3 V_69 , int V_210 , struct V_137 * V_138 )
{
struct V_1 * V_1 = F_35 ( V_138 -> V_211 -> V_32 ) ;
struct V_2 * V_15 ;
struct V_104 V_105 = {
. V_121 = V_212 ,
. V_127 = type ,
. V_117 = V_69 ,
. V_116 = V_210 ,
. V_141 = V_138 -> V_142 ,
. V_136 = V_138 -> V_211 -> V_32 -> V_80 ,
. V_119 = V_120 | V_213 ,
. V_107 = {
. V_108 = V_1 ,
} ,
} ;
if ( type == V_42 )
V_15 = F_5 ( V_1 , V_5 ) ;
else
V_15 = F_5 ( V_1 , V_7 ) ;
if ( ! V_15 )
return;
V_105 . V_164 = V_15 -> V_25 ;
if ( type != V_78 )
V_105 . V_126 = V_67 ;
else
V_105 . V_126 = V_86 ;
if ( V_102 == V_214 )
F_68 ( V_15 , & V_105 ) ;
else
F_67 ( V_15 , & V_105 ) ;
}
void F_85 ( struct V_137 * V_138 )
{
struct V_48 * V_49 = V_138 -> V_211 ;
struct V_31 * V_32 = V_49 -> V_32 ;
struct V_137 * V_215 = V_138 ;
T_3 V_114 = V_138 -> V_216 ;
T_3 V_33 = V_138 -> V_142 ;
T_3 V_217 = V_138 -> V_218 & V_114 ;
if ( V_138 -> V_219 & V_220 ) {
V_215 = F_86 ( V_49 , V_217 , V_114 ) ;
if ( ! V_215 ) {
F_87 ( L_1 , V_221 ) ;
return;
}
}
F_84 ( V_214 , V_78 , V_33 , 32 , V_215 ) ;
if ( ! ( V_32 -> V_222 & V_223 ) )
return;
if ( V_138 -> V_224 && V_138 -> V_224 != F_88 ( 0xFFFFFFFF ) )
F_84 ( V_214 , V_40 , V_138 -> V_224 , 32 , V_215 ) ;
if ( ! F_22 ( V_217 ) && ! ( V_138 -> V_219 & V_220 ) &&
( V_217 != V_33 || V_138 -> V_225 < 32 ) ) {
F_84 ( V_214 ,
V_32 -> V_222 & V_226 ? V_78 : V_42 ,
V_217 , V_138 -> V_225 , V_215 ) ;
if ( V_138 -> V_225 < 31 ) {
F_84 ( V_214 , V_40 , V_217 , 32 , V_215 ) ;
F_84 ( V_214 , V_40 , V_217 | ~ V_114 ,
32 , V_215 ) ;
}
}
}
void F_89 ( struct V_137 * V_138 , struct V_137 * V_227 )
{
struct V_48 * V_49 = V_138 -> V_211 ;
struct V_31 * V_32 = V_49 -> V_32 ;
struct V_137 * V_228 ;
struct V_137 * V_215 = V_138 , * V_229 = NULL ;
T_3 V_230 = V_138 -> V_218 | ~ V_138 -> V_216 ;
T_3 V_231 = V_138 -> V_218 & V_138 -> V_216 ;
#define F_90 1
#define F_91 2
#define F_92 4
#define F_93 8
unsigned int V_232 = 0 ;
int V_233 = 0 ;
int V_234 = 1 ;
int V_235 = 0 ;
if ( V_138 -> V_219 & V_220 ) {
V_215 = F_86 ( V_49 , V_231 , V_138 -> V_216 ) ;
if ( ! V_215 ) {
F_87 ( L_1 , V_221 ) ;
return;
}
if ( V_227 && V_227 != V_215 ) {
F_87 ( L_2 , V_221 ) ;
return;
}
} else if ( ! F_22 ( V_231 ) &&
( V_231 != V_138 -> V_142 || V_138 -> V_225 < 32 ) ) {
F_84 ( V_236 ,
V_32 -> V_222 & V_226 ? V_78 : V_42 ,
V_231 , V_138 -> V_225 , V_215 ) ;
V_233 = 1 ;
}
for ( V_228 = V_49 -> V_76 ; V_228 ; V_228 = V_228 -> V_139 ) {
if ( V_228 == V_138 ) {
V_234 = 0 ;
continue;
}
if ( V_227 && V_228 -> V_216 == V_227 -> V_216 &&
F_94 ( V_228 -> V_218 , V_227 ) )
continue;
if ( V_228 -> V_219 & V_220 ) {
if ( V_228 -> V_216 == V_215 -> V_216 &&
F_94 ( V_228 -> V_218 , V_215 ) )
V_229 = V_215 ;
else {
if ( ! V_235 )
continue;
if ( ! V_229 ||
V_228 -> V_216 != V_229 -> V_216 ||
! F_94 ( V_228 -> V_218 , V_229 ) )
V_229 = F_86 ( V_49 ,
V_228 -> V_218 ,
V_228 -> V_216 ) ;
if ( ! V_229 )
continue;
if ( V_229 -> V_142 != V_215 -> V_142 )
continue;
}
} else {
if ( V_215 -> V_142 != V_228 -> V_142 )
continue;
V_229 = V_228 ;
if ( V_215 != V_229 )
V_235 = 1 ;
}
if ( V_138 -> V_142 == V_228 -> V_142 )
V_232 |= F_90 ;
if ( V_138 -> V_224 == V_228 -> V_224 )
V_232 |= F_91 ;
if ( V_230 == V_228 -> V_224 )
V_232 |= F_93 ;
if ( V_231 == V_228 -> V_224 )
V_232 |= F_92 ;
if ( V_229 == V_228 && V_228 -> V_225 < 31 ) {
T_3 V_237 = V_228 -> V_218 | ~ V_228 -> V_216 ;
T_3 V_238 = V_228 -> V_218 & V_228 -> V_216 ;
if ( ! F_22 ( V_238 ) ) {
if ( V_138 -> V_224 == V_237 ||
V_138 -> V_224 == V_238 )
V_232 |= F_91 ;
if ( V_230 == V_237 || V_230 == V_238 )
V_232 |= F_93 ;
if ( V_231 == V_237 || V_231 == V_238 )
V_232 |= F_92 ;
}
}
}
if ( ! ( V_232 & F_91 ) )
F_84 ( V_236 , V_40 , V_138 -> V_224 , 32 , V_215 ) ;
if ( V_233 && V_138 -> V_225 < 31 ) {
if ( ! ( V_232 & F_93 ) )
F_84 ( V_236 , V_40 , V_230 , 32 , V_215 ) ;
if ( ! ( V_232 & F_92 ) )
F_84 ( V_236 , V_40 , V_231 , 32 , V_215 ) ;
}
if ( ! ( V_232 & F_90 ) ) {
F_84 ( V_236 , V_78 , V_138 -> V_142 , 32 , V_215 ) ;
if ( V_234 &&
F_28 ( F_35 ( V_32 ) , V_138 -> V_142 ) != V_78 ) {
if ( F_95 ( F_35 ( V_32 ) , V_138 -> V_142 ) )
F_14 ( F_35 ( V_32 ) ) ;
}
}
#undef F_90
#undef F_91
#undef F_92
#undef F_93
}
static void F_96 ( struct V_1 * V_1 , struct V_239 * V_240 )
{
struct V_37 V_38 ;
struct V_34 V_35 = {
. V_65 = V_240 -> V_241 ,
. V_36 = V_240 -> V_242 ,
. V_62 = V_240 -> V_243 ,
. V_64 = V_240 -> V_244 ,
} ;
struct V_2 * V_15 ;
F_25 () ;
V_15 = F_6 ( V_1 , V_240 -> V_245 ) ;
V_240 -> V_159 = - V_246 ;
if ( V_15 ) {
F_97 () ;
V_240 -> V_25 = V_15 -> V_25 ;
V_240 -> V_159 = F_26 ( V_15 , & V_35 , & V_38 , V_43 ) ;
if ( ! V_240 -> V_159 ) {
V_240 -> V_247 = V_38 . V_247 ;
V_240 -> V_248 = V_38 . V_248 ;
V_240 -> type = V_38 . type ;
V_240 -> V_52 = V_38 . V_52 ;
}
F_98 () ;
}
F_27 () ;
}
static void F_99 ( struct V_46 * V_47 )
{
struct V_1 * V_1 ;
struct V_239 * V_240 ;
struct V_167 * V_168 ;
T_2 V_186 ;
V_1 = F_79 ( V_47 -> V_200 ) ;
V_168 = F_100 ( V_47 ) ;
if ( V_47 -> V_97 < V_249 || V_47 -> V_97 < V_168 -> F_82 ||
F_82 ( V_168 ) < sizeof( * V_240 ) )
return;
V_47 = F_101 ( V_47 , V_149 ) ;
if ( ! V_47 )
return;
V_168 = F_100 ( V_47 ) ;
V_240 = (struct V_239 * ) F_73 ( V_168 ) ;
F_96 ( V_1 , V_240 ) ;
V_186 = F_74 ( V_47 ) . V_186 ;
F_74 ( V_47 ) . V_186 = 0 ;
F_74 ( V_47 ) . V_250 = 0 ;
F_102 ( V_1 -> V_10 . V_251 , V_47 , V_186 , V_252 ) ;
}
static int T_1 F_103 ( struct V_1 * V_1 )
{
struct V_253 * V_200 ;
struct V_254 V_105 = {
. V_255 = F_99 ,
} ;
V_200 = F_104 ( V_1 , V_256 , & V_105 ) ;
if ( ! V_200 )
return - V_112 ;
V_1 -> V_10 . V_251 = V_200 ;
return 0 ;
}
static void F_105 ( struct V_1 * V_1 )
{
F_106 ( V_1 -> V_10 . V_251 ) ;
V_1 -> V_10 . V_251 = NULL ;
}
static void F_107 ( struct V_31 * V_32 , int V_257 )
{
if ( F_108 ( V_32 , V_257 ) )
F_14 ( F_35 ( V_32 ) ) ;
F_17 ( F_35 ( V_32 ) ) ;
F_109 ( V_32 ) ;
}
static int F_110 ( struct V_258 * V_259 , unsigned long V_260 , void * V_261 )
{
struct V_137 * V_138 = (struct V_137 * ) V_261 ;
struct V_31 * V_32 = V_138 -> V_211 -> V_32 ;
struct V_1 * V_1 = F_35 ( V_32 ) ;
switch ( V_260 ) {
case V_262 :
F_85 ( V_138 ) ;
#ifdef F_46
F_111 ( V_32 ) ;
#endif
F_112 ( & V_1 -> V_10 . V_263 ) ;
F_17 ( F_35 ( V_32 ) ) ;
break;
case V_264 :
F_89 ( V_138 , NULL ) ;
F_112 ( & V_1 -> V_10 . V_263 ) ;
if ( ! V_138 -> V_211 -> V_76 ) {
F_107 ( V_32 , 1 ) ;
} else {
F_17 ( F_35 ( V_32 ) ) ;
}
break;
}
return V_265 ;
}
static int F_113 ( struct V_258 * V_259 , unsigned long V_260 , void * V_261 )
{
struct V_31 * V_32 = F_114 ( V_261 ) ;
struct V_48 * V_49 ;
struct V_1 * V_1 = F_35 ( V_32 ) ;
if ( V_260 == V_266 ) {
F_107 ( V_32 , 2 ) ;
F_115 ( V_32 ) ;
return V_265 ;
}
V_49 = F_62 ( V_32 ) ;
if ( ! V_49 )
return V_265 ;
switch ( V_260 ) {
case V_262 :
F_116 (in_dev) {
F_85 ( V_138 ) ;
} F_117 ( V_49 ) ;
#ifdef F_46
F_111 ( V_32 ) ;
#endif
F_112 ( & V_1 -> V_10 . V_263 ) ;
F_17 ( V_1 ) ;
break;
case V_264 :
F_107 ( V_32 , 0 ) ;
break;
case V_267 :
case V_268 :
F_17 ( V_1 ) ;
break;
}
return V_265 ;
}
static int T_1 F_118 ( struct V_1 * V_1 )
{
int V_159 ;
T_6 V_269 = sizeof( struct V_23 ) * V_22 ;
V_269 = F_119 ( T_6 , V_269 , V_270 ) ;
V_1 -> V_10 . V_11 = F_63 ( V_269 , V_149 ) ;
if ( ! V_1 -> V_10 . V_11 )
return - V_6 ;
V_159 = F_1 ( V_1 ) ;
if ( V_159 < 0 )
goto V_8;
return 0 ;
V_8:
F_69 ( V_1 -> V_10 . V_11 ) ;
return V_159 ;
}
static void F_120 ( struct V_1 * V_1 )
{
unsigned int V_271 ;
F_66 () ;
#ifdef F_10
F_121 ( V_1 -> V_10 . V_18 , NULL ) ;
F_121 ( V_1 -> V_10 . V_19 , NULL ) ;
F_121 ( V_1 -> V_10 . V_21 , NULL ) ;
#endif
for ( V_271 = 0 ; V_271 < V_22 ; V_271 ++ ) {
struct V_23 * V_24 = & V_1 -> V_10 . V_11 [ V_271 ] ;
struct V_29 * V_30 ;
struct V_2 * V_15 ;
F_15 (tb, tmp, head, tb_hlist) {
F_122 ( & V_15 -> V_9 ) ;
F_16 ( V_15 ) ;
F_4 ( V_15 ) ;
}
}
#ifdef F_10
F_123 ( V_1 ) ;
#endif
F_70 () ;
F_69 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_124 ( struct V_1 * V_1 )
{
int error ;
#ifdef F_125
V_1 -> V_10 . F_43 = 0 ;
#endif
error = F_118 ( V_1 ) ;
if ( error < 0 )
goto V_209;
error = F_103 ( V_1 ) ;
if ( error < 0 )
goto V_272;
error = F_126 ( V_1 ) ;
if ( error < 0 )
goto V_273;
V_209:
return error ;
V_273:
F_105 ( V_1 ) ;
V_272:
F_120 ( V_1 ) ;
goto V_209;
}
static void T_7 F_127 ( struct V_1 * V_1 )
{
F_128 ( V_1 ) ;
F_105 ( V_1 ) ;
F_120 ( V_1 ) ;
}
void T_8 F_129 ( void )
{
F_130 ( V_274 , V_214 , F_80 , NULL , NULL ) ;
F_130 ( V_274 , V_236 , F_78 , NULL , NULL ) ;
F_130 ( V_274 , V_275 , NULL , F_81 , NULL ) ;
F_131 ( & V_276 ) ;
F_132 ( & V_277 ) ;
F_133 ( & V_278 ) ;
F_134 () ;
}
