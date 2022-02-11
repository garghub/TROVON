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
V_16 = V_14 & ( V_17 - 1 ) ;
F_3 ( & V_15 -> V_9 , & V_1 -> V_10 . V_11 [ V_16 ] ) ;
return V_15 ;
}
struct V_2 * F_6 ( struct V_1 * V_1 , T_2 V_14 )
{
struct V_2 * V_15 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
unsigned int V_16 ;
if ( V_14 == 0 )
V_14 = V_7 ;
V_16 = V_14 & ( V_17 - 1 ) ;
F_7 () ;
V_21 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_8 (tb, node, head, tb_hlist) {
if ( V_15 -> V_22 == V_14 ) {
F_9 () ;
return V_15 ;
}
}
F_9 () ;
return NULL ;
}
static void F_10 ( struct V_1 * V_1 )
{
int V_23 = 0 ;
struct V_2 * V_15 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_21 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_11 (tb, node, head, tb_hlist)
V_23 += F_12 ( V_15 ) ;
}
if ( V_23 )
F_13 ( V_1 , - 1 ) ;
}
static inline unsigned F_14 ( struct V_1 * V_1 ,
const struct V_24 * V_25 ,
T_3 V_26 )
{
struct V_27 V_28 = { . V_29 = V_26 } ;
struct V_30 V_31 ;
unsigned V_32 = V_33 ;
struct V_2 * V_3 ;
if ( F_15 ( V_26 ) || F_16 ( V_26 ) )
return V_33 ;
if ( F_17 ( V_26 ) )
return V_34 ;
#ifdef F_18
V_31 . V_35 = NULL ;
#endif
V_3 = F_6 ( V_1 , V_5 ) ;
if ( V_3 ) {
V_32 = V_36 ;
F_7 () ;
if ( ! F_19 ( V_3 , & V_28 , & V_31 , V_37 ) ) {
if ( ! V_25 || V_25 == V_31 . V_38 -> V_39 )
V_32 = V_31 . type ;
}
F_9 () ;
}
return V_32 ;
}
unsigned int F_20 ( struct V_1 * V_1 , T_3 V_26 )
{
return F_14 ( V_1 , NULL , V_26 ) ;
}
unsigned int F_21 ( struct V_1 * V_1 , const struct V_24 * V_25 ,
T_3 V_26 )
{
return F_14 ( V_1 , V_25 , V_26 ) ;
}
int F_22 ( struct V_40 * V_41 , T_3 V_42 , T_3 V_43 , T_4 V_44 ,
int V_45 , struct V_24 * V_25 , T_3 * V_46 ,
T_2 * V_47 )
{
struct V_48 * V_49 ;
struct V_27 V_28 ;
struct V_30 V_31 ;
int V_50 , V_51 , V_52 ;
bool V_53 ;
int V_32 ;
struct V_1 * V_1 ;
V_28 . V_54 = 0 ;
V_28 . V_55 = V_45 ;
V_28 . V_29 = V_42 ;
V_28 . V_56 = V_43 ;
V_28 . V_57 = V_44 ;
V_28 . V_58 = V_59 ;
V_50 = V_51 = V_52 = 0 ;
V_49 = F_23 ( V_25 ) ;
if ( V_49 ) {
V_50 = V_49 -> V_60 == NULL ;
V_51 = F_24 ( V_41 ) ? 0 : F_25 ( V_49 ) ;
V_52 = F_26 ( V_49 ) ;
V_28 . V_61 = F_27 ( V_49 ) ? V_41 -> V_62 : 0 ;
}
if ( V_49 == NULL )
goto V_63;
V_1 = F_28 ( V_25 ) ;
if ( F_29 ( V_1 , & V_28 , & V_31 ) )
goto V_64;
if ( V_31 . type != V_36 ) {
if ( V_31 . type != V_65 || ! V_52 )
goto V_63;
}
* V_46 = F_30 ( V_1 , V_31 ) ;
F_31 ( V_47 , & V_31 ) ;
V_53 = false ;
#ifdef F_32
for ( V_32 = 0 ; V_32 < V_31 . V_38 -> V_66 ; V_32 ++ ) {
struct V_67 * V_68 = & V_31 . V_38 -> V_67 [ V_32 ] ;
if ( V_68 -> V_69 == V_25 ) {
V_53 = true ;
break;
}
}
#else
if ( F_33 ( V_31 ) == V_25 )
V_53 = true ;
#endif
if ( V_53 ) {
V_32 = F_34 ( V_31 ) . V_70 >= V_71 ;
return V_32 ;
}
if ( V_50 )
goto V_64;
if ( V_51 == 1 )
goto V_72;
V_28 . V_54 = V_25 -> V_73 ;
V_32 = 0 ;
if ( F_29 ( V_1 , & V_28 , & V_31 ) == 0 ) {
if ( V_31 . type == V_36 ) {
* V_46 = F_30 ( V_1 , V_31 ) ;
V_32 = F_34 ( V_31 ) . V_70 >= V_71 ;
}
}
return V_32 ;
V_64:
if ( V_51 )
goto V_72;
* V_46 = F_35 ( V_25 , 0 , V_59 ) ;
* V_47 = 0 ;
return 0 ;
V_63:
return - V_74 ;
V_72:
return - V_75 ;
}
static inline T_3 F_36 ( struct V_76 * V_26 )
{
return ( (struct V_77 * ) V_26 ) -> V_78 . V_79 ;
}
static int F_37 ( struct V_80 * V_81 , int V_82 , int type , T_2 V_83 )
{
struct V_80 * V_84 ;
V_84 = (struct V_80 * ) ( ( char * ) V_81 + V_82 ) ;
V_84 -> V_85 = type ;
V_84 -> V_86 = F_38 ( 4 ) ;
* ( T_2 * ) F_39 ( V_84 ) = V_83 ;
return V_82 + F_40 ( 4 ) ;
}
static int F_41 ( struct V_1 * V_1 , int V_87 , struct V_88 * V_89 ,
struct V_90 * V_91 )
{
T_3 V_26 ;
int V_92 ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
V_91 -> V_93 . V_94 = V_1 ;
if ( V_89 -> V_95 . V_96 != V_97 )
return - V_98 ;
V_92 = 32 ;
V_26 = F_36 ( & V_89 -> V_95 ) ;
if ( ! ( V_89 -> V_99 & V_100 ) ) {
T_3 V_101 = F_36 ( & V_89 -> V_102 ) ;
if ( V_89 -> V_102 . V_96 != V_97 ) {
if ( V_101 || V_89 -> V_102 . V_96 )
return - V_98 ;
}
if ( F_42 ( V_101 , V_26 ) )
return - V_74 ;
V_92 = F_43 ( V_101 ) ;
}
V_91 -> V_103 = V_92 ;
V_91 -> V_104 = V_26 ;
if ( V_87 != V_105 ) {
V_91 -> V_106 = V_107 ;
V_91 -> V_108 = V_109 ;
}
if ( V_89 -> V_110 )
V_91 -> V_111 = V_89 -> V_110 - 1 ;
if ( V_89 -> V_99 & V_112 ) {
V_91 -> V_113 = V_71 ;
V_91 -> V_114 = V_115 ;
return 0 ;
}
V_91 -> V_113 = V_116 ;
V_91 -> V_114 = V_36 ;
if ( V_89 -> V_117 ) {
char * V_118 ;
struct V_24 * V_25 ;
char V_119 [ V_120 ] ;
if ( F_44 ( V_119 , V_89 -> V_117 , V_120 - 1 ) )
return - V_121 ;
V_119 [ V_120 - 1 ] = 0 ;
V_118 = strchr ( V_119 , ':' ) ;
if ( V_118 )
* V_118 = 0 ;
V_25 = F_45 ( V_1 , V_119 ) ;
if ( ! V_25 )
return - V_122 ;
V_91 -> V_123 = V_25 -> V_73 ;
if ( V_118 ) {
struct V_124 * V_125 ;
struct V_48 * V_49 = F_46 ( V_25 ) ;
if ( ! V_49 )
return - V_122 ;
* V_118 = ':' ;
for ( V_125 = V_49 -> V_60 ; V_125 ; V_125 = V_125 -> V_126 )
if ( strcmp ( V_125 -> V_127 , V_119 ) == 0 )
break;
if ( V_125 == NULL )
return - V_122 ;
V_91 -> V_128 = V_125 -> V_129 ;
}
}
V_26 = F_36 ( & V_89 -> V_130 ) ;
if ( V_89 -> V_130 . V_96 == V_97 && V_26 ) {
V_91 -> V_131 = V_26 ;
if ( V_89 -> V_99 & V_132 &&
F_20 ( V_1 , V_26 ) == V_36 )
V_91 -> V_113 = V_59 ;
}
if ( V_87 == V_105 )
return 0 ;
if ( V_89 -> V_99 & V_132 && ! V_91 -> V_131 )
return - V_74 ;
if ( V_91 -> V_113 == V_116 )
V_91 -> V_113 = V_133 ;
if ( V_89 -> V_99 & ( V_134 | V_135 | V_136 ) ) {
struct V_80 * V_81 ;
int V_82 = 0 ;
V_81 = F_47 ( 3 * F_40 ( 4 ) , V_137 ) ;
if ( V_81 == NULL )
return - V_6 ;
if ( V_89 -> V_99 & V_134 )
V_82 = F_37 ( V_81 , V_82 , V_138 , V_89 -> V_139 - 40 ) ;
if ( V_89 -> V_99 & V_135 )
V_82 = F_37 ( V_81 , V_82 , V_140 , V_89 -> V_141 ) ;
if ( V_89 -> V_99 & V_136 )
V_82 = F_37 ( V_81 , V_82 , V_142 , V_89 -> V_143 << 3 ) ;
V_91 -> V_144 = V_81 ;
V_91 -> V_145 = V_82 ;
}
return 0 ;
}
int F_48 ( struct V_1 * V_1 , unsigned int V_87 , void T_5 * V_146 )
{
struct V_90 V_91 ;
struct V_88 V_89 ;
int V_147 ;
switch ( V_87 ) {
case V_148 :
case V_105 :
if ( ! F_49 ( V_149 ) )
return - V_150 ;
if ( F_44 ( & V_89 , V_146 , sizeof( V_89 ) ) )
return - V_121 ;
F_50 () ;
V_147 = F_41 ( V_1 , V_87 , & V_89 , & V_91 ) ;
if ( V_147 == 0 ) {
struct V_2 * V_15 ;
if ( V_87 == V_105 ) {
V_15 = F_6 ( V_1 , V_91 . V_151 ) ;
if ( V_15 )
V_147 = F_51 ( V_15 , & V_91 ) ;
else
V_147 = - V_152 ;
} else {
V_15 = F_5 ( V_1 , V_91 . V_151 ) ;
if ( V_15 )
V_147 = F_52 ( V_15 , & V_91 ) ;
else
V_147 = - V_153 ;
}
F_4 ( V_91 . V_144 ) ;
}
F_53 () ;
return V_147 ;
}
return - V_74 ;
}
static int F_54 ( struct V_1 * V_1 , struct V_40 * V_41 ,
struct V_154 * V_155 , struct V_90 * V_91 )
{
struct V_80 * V_156 ;
int V_147 , V_157 ;
struct V_158 * V_159 ;
V_147 = F_55 ( V_155 , sizeof( * V_159 ) , V_160 , V_161 ) ;
if ( V_147 < 0 )
goto V_162;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
V_159 = F_56 ( V_155 ) ;
V_91 -> V_103 = V_159 -> V_163 ;
V_91 -> V_164 = V_159 -> V_165 ;
V_91 -> V_151 = V_159 -> V_166 ;
V_91 -> V_108 = V_159 -> V_167 ;
V_91 -> V_113 = V_159 -> V_168 ;
V_91 -> V_114 = V_159 -> V_169 ;
V_91 -> V_170 = V_159 -> V_171 ;
V_91 -> V_106 = V_155 -> V_172 ;
V_91 -> V_93 . V_173 = F_57 ( V_41 ) . V_173 ;
V_91 -> V_93 . V_155 = V_155 ;
V_91 -> V_93 . V_94 = V_1 ;
if ( V_91 -> V_114 > V_174 ) {
V_147 = - V_74 ;
goto V_162;
}
F_58 (attr, nlh, sizeof(struct rtmsg), remaining) {
switch ( V_85 ( V_156 ) ) {
case V_175 :
V_91 -> V_104 = F_59 ( V_156 ) ;
break;
case V_176 :
V_91 -> V_123 = F_60 ( V_156 ) ;
break;
case V_177 :
V_91 -> V_131 = F_59 ( V_156 ) ;
break;
case V_178 :
V_91 -> V_111 = F_60 ( V_156 ) ;
break;
case V_179 :
V_91 -> V_128 = F_59 ( V_156 ) ;
break;
case V_180 :
V_91 -> V_144 = F_39 ( V_156 ) ;
V_91 -> V_145 = V_86 ( V_156 ) ;
break;
case V_181 :
V_91 -> V_182 = F_39 ( V_156 ) ;
V_91 -> V_183 = V_86 ( V_156 ) ;
break;
case V_184 :
V_91 -> V_185 = F_60 ( V_156 ) ;
break;
case V_186 :
V_91 -> V_151 = F_60 ( V_156 ) ;
break;
}
}
return 0 ;
V_162:
return V_147 ;
}
static int F_61 ( struct V_40 * V_41 , struct V_154 * V_155 , void * V_146 )
{
struct V_1 * V_1 = F_62 ( V_41 -> V_187 ) ;
struct V_90 V_91 ;
struct V_2 * V_15 ;
int V_147 ;
V_147 = F_54 ( V_1 , V_41 , V_155 , & V_91 ) ;
if ( V_147 < 0 )
goto V_162;
V_15 = F_6 ( V_1 , V_91 . V_151 ) ;
if ( V_15 == NULL ) {
V_147 = - V_152 ;
goto V_162;
}
V_147 = F_51 ( V_15 , & V_91 ) ;
V_162:
return V_147 ;
}
static int F_63 ( struct V_40 * V_41 , struct V_154 * V_155 , void * V_146 )
{
struct V_1 * V_1 = F_62 ( V_41 -> V_187 ) ;
struct V_90 V_91 ;
struct V_2 * V_15 ;
int V_147 ;
V_147 = F_54 ( V_1 , V_41 , V_155 , & V_91 ) ;
if ( V_147 < 0 )
goto V_162;
V_15 = F_5 ( V_1 , V_91 . V_151 ) ;
if ( V_15 == NULL ) {
V_147 = - V_153 ;
goto V_162;
}
V_147 = F_52 ( V_15 , & V_91 ) ;
V_162:
return V_147 ;
}
static int F_64 ( struct V_40 * V_41 , struct V_188 * V_189 )
{
struct V_1 * V_1 = F_62 ( V_41 -> V_187 ) ;
unsigned int V_16 , V_190 ;
unsigned int V_191 = 0 , V_192 ;
struct V_2 * V_15 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_193 = 0 ;
if ( F_65 ( V_189 -> V_155 ) >= sizeof( struct V_158 ) &&
( (struct V_158 * ) F_56 ( V_189 -> V_155 ) ) -> V_171 & V_194 )
return F_66 ( V_41 , V_189 ) ;
V_190 = V_189 -> args [ 0 ] ;
V_192 = V_189 -> args [ 1 ] ;
for ( V_16 = V_190 ; V_16 < V_17 ; V_16 ++ , V_192 = 0 ) {
V_191 = 0 ;
V_21 = & V_1 -> V_10 . V_11 [ V_16 ] ;
F_11 (tb, node, head, tb_hlist) {
if ( V_191 < V_192 )
goto V_195;
if ( V_193 )
memset ( & V_189 -> args [ 2 ] , 0 , sizeof( V_189 -> args ) -
2 * sizeof( V_189 -> args [ 0 ] ) ) ;
if ( F_67 ( V_15 , V_41 , V_189 ) < 0 )
goto V_196;
V_193 = 1 ;
V_195:
V_191 ++ ;
}
}
V_196:
V_189 -> args [ 1 ] = V_191 ;
V_189 -> args [ 0 ] = V_16 ;
return V_41 -> V_82 ;
}
static void F_68 ( int V_87 , int type , T_3 V_43 , int V_197 , struct V_124 * V_125 )
{
struct V_1 * V_1 = F_28 ( V_125 -> V_198 -> V_25 ) ;
struct V_2 * V_15 ;
struct V_90 V_91 = {
. V_108 = V_199 ,
. V_114 = type ,
. V_104 = V_43 ,
. V_103 = V_197 ,
. V_128 = V_125 -> V_129 ,
. V_123 = V_125 -> V_198 -> V_25 -> V_73 ,
. V_106 = V_107 | V_200 ,
. V_93 = {
. V_94 = V_1 ,
} ,
} ;
if ( type == V_36 )
V_15 = F_5 ( V_1 , V_7 ) ;
else
V_15 = F_5 ( V_1 , V_5 ) ;
if ( V_15 == NULL )
return;
V_91 . V_151 = V_15 -> V_22 ;
if ( type != V_65 )
V_91 . V_113 = V_133 ;
else
V_91 . V_113 = V_71 ;
if ( V_87 == V_201 )
F_52 ( V_15 , & V_91 ) ;
else
F_51 ( V_15 , & V_91 ) ;
}
void F_69 ( struct V_124 * V_125 )
{
struct V_48 * V_49 = V_125 -> V_198 ;
struct V_24 * V_25 = V_49 -> V_25 ;
struct V_124 * V_202 = V_125 ;
T_3 V_101 = V_125 -> V_203 ;
T_3 V_26 = V_125 -> V_129 ;
T_3 V_204 = V_125 -> V_205 & V_101 ;
if ( V_125 -> V_206 & V_207 ) {
V_202 = F_70 ( V_49 , V_204 , V_101 ) ;
if ( V_202 == NULL ) {
F_71 ( V_208 L_1 ) ;
return;
}
}
F_68 ( V_201 , V_65 , V_26 , 32 , V_202 ) ;
if ( ! ( V_25 -> V_209 & V_210 ) )
return;
if ( V_125 -> V_211 && V_125 -> V_211 != F_72 ( 0xFFFFFFFF ) )
F_68 ( V_201 , V_33 , V_125 -> V_211 , 32 , V_202 ) ;
if ( ! F_15 ( V_204 ) && ! ( V_125 -> V_206 & V_207 ) &&
( V_204 != V_26 || V_125 -> V_212 < 32 ) ) {
F_68 ( V_201 ,
V_25 -> V_209 & V_213 ? V_65 : V_36 ,
V_204 , V_125 -> V_212 , V_202 ) ;
if ( V_125 -> V_212 < 31 ) {
F_68 ( V_201 , V_33 , V_204 , 32 , V_202 ) ;
F_68 ( V_201 , V_33 , V_204 | ~ V_101 ,
32 , V_202 ) ;
}
}
}
void F_73 ( struct V_124 * V_125 , struct V_124 * V_214 )
{
struct V_48 * V_49 = V_125 -> V_198 ;
struct V_24 * V_25 = V_49 -> V_25 ;
struct V_124 * V_215 ;
struct V_124 * V_202 = V_125 , * V_216 = NULL ;
T_3 V_217 = V_125 -> V_205 | ~ V_125 -> V_203 ;
T_3 V_218 = V_125 -> V_205 & V_125 -> V_203 ;
#define F_74 1
#define F_75 2
#define F_76 4
#define F_77 8
unsigned V_219 = 0 ;
int V_220 = 0 ;
int V_221 = 1 ;
int V_222 = 0 ;
if ( V_125 -> V_206 & V_207 ) {
V_202 = F_70 ( V_49 , V_218 , V_125 -> V_203 ) ;
if ( V_202 == NULL ) {
F_71 ( V_208 L_2 ) ;
return;
}
if ( V_214 && V_214 != V_202 ) {
F_71 ( V_208 L_3 ) ;
return;
}
} else if ( ! F_15 ( V_218 ) &&
( V_218 != V_125 -> V_129 || V_125 -> V_212 < 32 ) ) {
F_68 ( V_223 ,
V_25 -> V_209 & V_213 ? V_65 : V_36 ,
V_218 , V_125 -> V_212 , V_202 ) ;
V_220 = 1 ;
}
for ( V_215 = V_49 -> V_60 ; V_215 ; V_215 = V_215 -> V_126 ) {
if ( V_215 == V_125 ) {
V_221 = 0 ;
continue;
}
if ( V_214 && V_215 -> V_203 == V_214 -> V_203 &&
F_78 ( V_215 -> V_205 , V_214 ) )
continue;
if ( V_215 -> V_206 & V_207 ) {
if ( V_215 -> V_203 == V_202 -> V_203 &&
F_78 ( V_215 -> V_205 , V_202 ) )
V_216 = V_202 ;
else {
if ( ! V_222 )
continue;
if ( ! V_216 ||
V_215 -> V_203 != V_216 -> V_203 ||
! F_78 ( V_215 -> V_205 , V_216 ) )
V_216 = F_70 ( V_49 ,
V_215 -> V_205 ,
V_215 -> V_203 ) ;
if ( ! V_216 )
continue;
if ( V_216 -> V_129 != V_202 -> V_129 )
continue;
}
} else {
if ( V_202 -> V_129 != V_215 -> V_129 )
continue;
V_216 = V_215 ;
if ( V_202 != V_216 )
V_222 = 1 ;
}
if ( V_125 -> V_129 == V_215 -> V_129 )
V_219 |= F_74 ;
if ( V_125 -> V_211 == V_215 -> V_211 )
V_219 |= F_75 ;
if ( V_217 == V_215 -> V_211 )
V_219 |= F_77 ;
if ( V_218 == V_215 -> V_211 )
V_219 |= F_76 ;
if ( V_216 == V_215 && V_215 -> V_212 < 31 ) {
T_3 V_224 = V_215 -> V_205 | ~ V_215 -> V_203 ;
T_3 V_225 = V_215 -> V_205 & V_215 -> V_203 ;
if ( ! F_15 ( V_225 ) ) {
if ( V_125 -> V_211 == V_224 ||
V_125 -> V_211 == V_225 )
V_219 |= F_75 ;
if ( V_217 == V_224 || V_217 == V_225 )
V_219 |= F_77 ;
if ( V_218 == V_224 || V_218 == V_225 )
V_219 |= F_76 ;
}
}
}
if ( ! ( V_219 & F_75 ) )
F_68 ( V_223 , V_33 , V_125 -> V_211 , 32 , V_202 ) ;
if ( V_220 && V_125 -> V_212 < 31 ) {
if ( ! ( V_219 & F_77 ) )
F_68 ( V_223 , V_33 , V_217 , 32 , V_202 ) ;
if ( ! ( V_219 & F_76 ) )
F_68 ( V_223 , V_33 , V_218 , 32 , V_202 ) ;
}
if ( ! ( V_219 & F_74 ) ) {
F_68 ( V_223 , V_65 , V_125 -> V_129 , 32 , V_202 ) ;
if ( V_221 &&
F_20 ( F_28 ( V_25 ) , V_125 -> V_129 ) != V_65 ) {
if ( F_79 ( F_28 ( V_25 ) , V_125 -> V_129 ) )
F_10 ( F_28 ( V_25 ) ) ;
}
}
#undef F_74
#undef F_75
#undef F_76
#undef F_77
}
static void F_80 ( struct V_226 * V_227 , struct V_2 * V_15 )
{
struct V_30 V_31 ;
struct V_27 V_28 = {
. V_61 = V_227 -> V_228 ,
. V_29 = V_227 -> V_229 ,
. V_57 = V_227 -> V_230 ,
. V_58 = V_227 -> V_231 ,
} ;
#ifdef F_18
V_31 . V_35 = NULL ;
#endif
V_227 -> V_147 = - V_232 ;
if ( V_15 ) {
F_81 () ;
V_227 -> V_22 = V_15 -> V_22 ;
F_7 () ;
V_227 -> V_147 = F_19 ( V_15 , & V_28 , & V_31 , V_37 ) ;
if ( ! V_227 -> V_147 ) {
V_227 -> V_233 = V_31 . V_233 ;
V_227 -> V_234 = V_31 . V_234 ;
V_227 -> type = V_31 . type ;
V_227 -> V_235 = V_31 . V_235 ;
}
F_9 () ;
F_82 () ;
}
}
static void F_83 ( struct V_40 * V_41 )
{
struct V_1 * V_1 ;
struct V_226 * V_227 ;
struct V_154 * V_155 ;
struct V_2 * V_15 ;
T_2 V_173 ;
V_1 = F_62 ( V_41 -> V_187 ) ;
V_155 = F_84 ( V_41 ) ;
if ( V_41 -> V_82 < F_85 ( 0 ) || V_41 -> V_82 < V_155 -> F_65 ||
V_155 -> F_65 < F_86 ( sizeof( * V_227 ) ) )
return;
V_41 = F_87 ( V_41 , V_137 ) ;
if ( V_41 == NULL )
return;
V_155 = F_84 ( V_41 ) ;
V_227 = (struct V_226 * ) F_88 ( V_155 ) ;
V_15 = F_6 ( V_1 , V_227 -> V_236 ) ;
F_80 ( V_227 , V_15 ) ;
V_173 = F_57 ( V_41 ) . V_173 ;
F_57 ( V_41 ) . V_173 = 0 ;
F_57 ( V_41 ) . V_237 = 0 ;
F_89 ( V_1 -> V_10 . V_238 , V_41 , V_173 , V_239 ) ;
}
static int T_1 F_90 ( struct V_1 * V_1 )
{
struct V_240 * V_187 ;
V_187 = F_91 ( V_1 , V_241 , 0 ,
F_83 , NULL , V_242 ) ;
if ( V_187 == NULL )
return - V_98 ;
V_1 -> V_10 . V_238 = V_187 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_1 )
{
F_93 ( V_1 -> V_10 . V_238 ) ;
V_1 -> V_10 . V_238 = NULL ;
}
static void F_94 ( struct V_24 * V_25 , int V_243 , int V_244 )
{
if ( F_95 ( V_25 , V_243 ) )
F_10 ( F_28 ( V_25 ) ) ;
F_13 ( F_28 ( V_25 ) , V_244 ) ;
F_96 ( V_25 ) ;
}
static int F_97 ( struct V_245 * V_246 , unsigned long V_247 , void * V_248 )
{
struct V_124 * V_125 = (struct V_124 * ) V_248 ;
struct V_24 * V_25 = V_125 -> V_198 -> V_25 ;
struct V_1 * V_1 = F_28 ( V_25 ) ;
switch ( V_247 ) {
case V_249 :
F_69 ( V_125 ) ;
#ifdef F_32
F_98 ( V_25 ) ;
#endif
F_99 ( & V_1 -> V_10 . V_250 ) ;
F_13 ( F_28 ( V_25 ) , - 1 ) ;
break;
case V_251 :
F_73 ( V_125 , NULL ) ;
F_99 ( & V_1 -> V_10 . V_250 ) ;
if ( V_125 -> V_198 -> V_60 == NULL ) {
F_94 ( V_25 , 1 , 0 ) ;
} else {
F_13 ( F_28 ( V_25 ) , - 1 ) ;
}
break;
}
return V_252 ;
}
static int F_100 ( struct V_245 * V_246 , unsigned long V_247 , void * V_248 )
{
struct V_24 * V_25 = V_248 ;
struct V_48 * V_49 = F_46 ( V_25 ) ;
struct V_1 * V_1 = F_28 ( V_25 ) ;
if ( V_247 == V_253 ) {
F_94 ( V_25 , 2 , - 1 ) ;
return V_252 ;
}
if ( ! V_49 )
return V_252 ;
switch ( V_247 ) {
case V_249 :
F_101 (in_dev) {
F_69 ( V_125 ) ;
} F_102 ( V_49 ) ;
#ifdef F_32
F_98 ( V_25 ) ;
#endif
F_99 ( & V_1 -> V_10 . V_250 ) ;
F_13 ( F_28 ( V_25 ) , - 1 ) ;
break;
case V_251 :
F_94 ( V_25 , 0 , 0 ) ;
break;
case V_254 :
case V_255 :
F_13 ( F_28 ( V_25 ) , 0 ) ;
break;
case V_256 :
F_103 ( NULL ) ;
break;
}
return V_252 ;
}
static int T_1 F_104 ( struct V_1 * V_1 )
{
int V_147 ;
T_6 V_257 = sizeof( struct V_20 ) * V_17 ;
V_257 = F_105 ( T_6 , V_257 , V_258 ) ;
V_1 -> V_10 . V_11 = F_47 ( V_257 , V_137 ) ;
if ( V_1 -> V_10 . V_11 == NULL )
return - V_6 ;
V_147 = F_1 ( V_1 ) ;
if ( V_147 < 0 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_1 -> V_10 . V_11 ) ;
return V_147 ;
}
static void F_106 ( struct V_1 * V_1 )
{
unsigned int V_259 ;
#ifdef F_18
F_107 ( V_1 ) ;
#endif
F_50 () ;
for ( V_259 = 0 ; V_259 < V_17 ; V_259 ++ ) {
struct V_2 * V_15 ;
struct V_20 * V_21 ;
struct V_18 * V_19 , * V_260 ;
V_21 = & V_1 -> V_10 . V_11 [ V_259 ] ;
F_108 (tb, node, tmp, head, tb_hlist) {
F_109 ( V_19 ) ;
F_12 ( V_15 ) ;
F_110 ( V_15 ) ;
}
}
F_53 () ;
F_4 ( V_1 -> V_10 . V_11 ) ;
}
static int T_1 F_111 ( struct V_1 * V_1 )
{
int error ;
error = F_104 ( V_1 ) ;
if ( error < 0 )
goto V_196;
error = F_90 ( V_1 ) ;
if ( error < 0 )
goto V_261;
error = F_112 ( V_1 ) ;
if ( error < 0 )
goto V_262;
V_196:
return error ;
V_262:
F_92 ( V_1 ) ;
V_261:
F_106 ( V_1 ) ;
goto V_196;
}
static void T_7 F_113 ( struct V_1 * V_1 )
{
F_114 ( V_1 ) ;
F_92 ( V_1 ) ;
F_106 ( V_1 ) ;
}
void T_8 F_115 ( void )
{
F_116 ( V_263 , V_201 , F_63 , NULL ) ;
F_116 ( V_263 , V_223 , F_61 , NULL ) ;
F_116 ( V_263 , V_264 , NULL , F_64 ) ;
F_117 ( & V_265 ) ;
F_118 ( & V_266 ) ;
F_119 ( & V_267 ) ;
F_120 () ;
}
