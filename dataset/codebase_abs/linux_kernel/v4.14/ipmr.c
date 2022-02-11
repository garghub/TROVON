static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
F_2 (mrt, net) {
if ( V_4 -> V_3 == V_3 )
return V_4 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
int V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 = {
. V_12 = & V_9 ,
. V_13 = V_14 ,
} ;
F_4 ( V_2 , F_5 ( V_6 ) ) ;
V_7 = F_6 ( V_2 -> V_15 . V_16 ,
F_5 ( V_6 ) , 0 , & V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = V_9 . V_4 ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 , struct V_19 * V_20 ,
int V_13 , struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_12 ;
struct V_1 * V_4 ;
switch ( V_18 -> V_21 ) {
case V_22 :
break;
case V_23 :
return - V_24 ;
case V_25 :
return - V_26 ;
case V_27 :
default:
return - V_28 ;
}
V_11 -> V_29 = F_8 ( V_18 , V_11 ) ;
V_4 = F_1 ( V_18 -> V_30 , V_11 -> V_29 ) ;
if ( ! V_4 )
return - V_31 ;
V_9 -> V_4 = V_4 ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , struct V_19 * V_32 , int V_13 )
{
return 1 ;
}
static int F_10 ( struct V_17 * V_18 , struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * * V_38 )
{
return 0 ;
}
static int F_11 ( struct V_17 * V_18 , struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
return 1 ;
}
static int F_12 ( struct V_17 * V_18 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_39 = 0 ;
V_36 -> V_40 = 0 ;
V_36 -> V_41 = 0 ;
return 0 ;
}
static int T_2 F_13 ( struct V_2 * V_2 )
{
struct V_42 * V_43 ;
struct V_1 * V_4 ;
int V_7 ;
V_43 = F_14 ( & V_44 , V_2 ) ;
if ( F_15 ( V_43 ) )
return F_16 ( V_43 ) ;
F_17 ( & V_2 -> V_15 . V_45 ) ;
V_4 = F_18 ( V_2 , V_46 ) ;
if ( F_15 ( V_4 ) ) {
V_7 = F_16 ( V_4 ) ;
goto V_47;
}
V_7 = F_19 ( V_43 , 0x7fff , V_46 , 0 ) ;
if ( V_7 < 0 )
goto V_48;
V_2 -> V_15 . V_16 = V_43 ;
return 0 ;
V_48:
F_20 ( V_4 ) ;
V_47:
F_21 ( V_43 ) ;
return V_7 ;
}
static void T_3 F_22 ( struct V_2 * V_2 )
{
struct V_1 * V_4 , * V_49 ;
F_23 () ;
F_24 (mrt, next, &net->ipv4.mr_tables, list) {
F_25 ( & V_4 -> V_50 ) ;
F_20 ( V_4 ) ;
}
F_21 ( V_2 -> V_15 . V_16 ) ;
F_26 () ;
}
static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
return V_2 -> V_15 . V_4 ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
* V_4 = V_2 -> V_15 . V_4 ;
return 0 ;
}
static int T_2 F_13 ( struct V_2 * V_2 )
{
struct V_1 * V_4 ;
V_4 = F_18 ( V_2 , V_46 ) ;
if ( F_15 ( V_4 ) )
return F_16 ( V_4 ) ;
V_2 -> V_15 . V_4 = V_4 ;
return 0 ;
}
static void T_3 F_22 ( struct V_2 * V_2 )
{
F_23 () ;
F_20 ( V_2 -> V_15 . V_4 ) ;
V_2 -> V_15 . V_4 = NULL ;
F_26 () ;
}
static inline int F_27 ( struct V_51 * V_11 ,
const void * V_52 )
{
const struct V_53 * V_54 = V_11 -> V_55 ;
struct V_56 * V_57 = (struct V_56 * ) V_52 ;
return V_54 -> V_58 != V_57 -> V_58 ||
V_54 -> V_59 != V_57 -> V_59 ;
}
static struct V_1 * F_18 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
if ( V_3 != V_46 && V_3 >= 1000000000 )
return F_28 ( - V_28 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_29 ( sizeof( * V_4 ) , V_60 ) ;
if ( ! V_4 )
return F_28 ( - V_61 ) ;
F_30 ( & V_4 -> V_2 , V_2 ) ;
V_4 -> V_3 = V_3 ;
F_31 ( & V_4 -> V_62 , & V_63 ) ;
F_17 ( & V_4 -> V_64 ) ;
F_17 ( & V_4 -> V_65 ) ;
F_32 ( & V_4 -> V_66 , V_67 ,
( unsigned long ) V_4 ) ;
V_4 -> V_68 = - 1 ;
#ifdef F_33
F_34 ( & V_4 -> V_50 , & V_2 -> V_15 . V_45 ) ;
#endif
return V_4 ;
}
static void F_20 ( struct V_1 * V_4 )
{
F_35 ( & V_4 -> V_66 ) ;
F_36 ( V_4 , true ) ;
F_37 ( & V_4 -> V_62 ) ;
F_38 ( V_4 ) ;
}
static void F_39 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_2 * V_2 = F_40 ( V_70 ) ;
F_41 ( V_70 ) ;
V_70 = F_42 ( V_2 , L_1 ) ;
if ( V_70 ) {
const struct V_73 * V_43 = V_70 -> V_74 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_79 . V_80 = V_72 -> V_81 . V_82 ;
V_78 . V_79 . V_83 = V_72 -> V_84 . V_82 ;
V_78 . V_79 . V_85 = 4 ;
V_78 . V_79 . V_86 = 5 ;
V_78 . V_79 . V_87 = V_88 ;
sprintf ( V_78 . V_89 , L_2 , V_72 -> V_90 ) ;
V_76 . V_91 . V_92 = ( V_93 void V_94 * ) & V_78 ;
if ( V_43 -> V_95 ) {
T_4 V_96 = F_43 () ;
F_44 ( V_97 ) ;
V_43 -> V_95 ( V_70 , & V_76 , V_98 ) ;
F_44 ( V_96 ) ;
}
}
}
static bool F_45 ( const struct V_69 * V_70 )
{
struct V_99 * V_100 ;
F_46 () ;
V_100 = F_47 ( V_70 ) ;
if ( ! V_100 )
return false ;
F_48 ( V_100 ) ;
F_49 ( V_100 -> V_101 ) ;
F_50 ( V_100 -> V_102 , V_103 ) = 0 ;
return true ;
}
static struct V_69 * F_51 ( struct V_2 * V_2 , struct V_71 * V_72 )
{
struct V_69 * V_70 ;
V_70 = F_42 ( V_2 , L_1 ) ;
if ( V_70 ) {
const struct V_73 * V_43 = V_70 -> V_74 ;
int V_7 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_79 . V_80 = V_72 -> V_81 . V_82 ;
V_78 . V_79 . V_83 = V_72 -> V_84 . V_82 ;
V_78 . V_79 . V_85 = 4 ;
V_78 . V_79 . V_86 = 5 ;
V_78 . V_79 . V_87 = V_88 ;
sprintf ( V_78 . V_89 , L_2 , V_72 -> V_90 ) ;
V_76 . V_91 . V_92 = ( V_93 void V_94 * ) & V_78 ;
if ( V_43 -> V_95 ) {
T_4 V_96 = F_43 () ;
F_44 ( V_97 ) ;
V_7 = V_43 -> V_95 ( V_70 , & V_76 , V_104 ) ;
F_44 ( V_96 ) ;
} else {
V_7 = - V_105 ;
}
V_70 = NULL ;
if ( V_7 == 0 &&
( V_70 = F_42 ( V_2 , V_78 . V_89 ) ) != NULL ) {
V_70 -> V_13 |= V_106 ;
if ( ! F_45 ( V_70 ) )
goto V_107;
if ( F_52 ( V_70 ) )
goto V_107;
F_53 ( V_70 ) ;
}
}
return V_70 ;
V_107:
F_54 ( V_70 ) ;
return NULL ;
}
static T_5 F_55 ( struct V_33 * V_34 , struct V_69 * V_70 )
{
struct V_2 * V_2 = F_40 ( V_70 ) ;
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_109 = V_70 -> V_110 ,
. V_111 = V_34 -> V_112 ? : V_113 ,
. V_114 = V_34 -> V_115 ,
} ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_108 , & V_4 ) ;
if ( V_7 < 0 ) {
F_56 ( V_34 ) ;
return V_7 ;
}
F_57 ( & V_116 ) ;
V_70 -> V_117 . V_118 += V_34 -> V_119 ;
V_70 -> V_117 . V_120 ++ ;
F_58 ( V_4 , V_34 , V_4 -> V_68 , V_121 ) ;
F_59 ( & V_116 ) ;
F_56 ( V_34 ) ;
return V_122 ;
}
static int F_60 ( const struct V_69 * V_70 )
{
return 0 ;
}
static void F_61 ( struct V_69 * V_70 )
{
V_70 -> type = V_123 ;
V_70 -> V_124 = V_125 - sizeof( struct V_126 ) - 8 ;
V_70 -> V_13 = V_127 ;
V_70 -> V_74 = & V_128 ;
V_70 -> V_129 = true ;
V_70 -> V_130 |= V_131 ;
}
static struct V_69 * F_62 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_69 * V_70 ;
char V_89 [ V_132 ] ;
if ( V_4 -> V_3 == V_46 )
sprintf ( V_89 , L_3 ) ;
else
sprintf ( V_89 , L_4 , V_4 -> V_3 ) ;
V_70 = F_63 ( 0 , V_89 , V_133 , F_61 ) ;
if ( ! V_70 )
return NULL ;
F_64 ( V_70 , V_2 ) ;
if ( F_65 ( V_70 ) ) {
F_66 ( V_70 ) ;
return NULL ;
}
if ( ! F_45 ( V_70 ) )
goto V_107;
if ( F_52 ( V_70 ) )
goto V_107;
F_53 ( V_70 ) ;
return V_70 ;
V_107:
F_54 ( V_70 ) ;
return NULL ;
}
static int F_67 ( struct V_1 * V_4 , struct V_33 * V_34 ,
unsigned int V_134 )
{
struct V_69 * V_135 = NULL ;
struct V_126 * V_136 ;
V_136 = (struct V_126 * ) ( F_68 ( V_34 ) + V_134 ) ;
if ( ! F_69 ( V_136 -> V_80 ) ||
V_136 -> V_137 == 0 ||
F_70 ( V_136 -> V_137 ) + V_134 > V_34 -> V_119 )
return 1 ;
F_57 ( & V_116 ) ;
if ( V_4 -> V_68 >= 0 )
V_135 = V_4 -> V_138 [ V_4 -> V_68 ] . V_70 ;
F_59 ( & V_116 ) ;
if ( ! V_135 )
return 1 ;
V_34 -> V_139 = V_34 -> V_140 ;
F_71 ( V_34 , ( V_141 * ) V_136 - V_34 -> V_142 ) ;
F_72 ( V_34 ) ;
V_34 -> V_87 = F_73 ( V_143 ) ;
V_34 -> V_144 = V_145 ;
F_74 ( V_34 , V_135 , F_40 ( V_135 ) ) ;
F_75 ( V_34 ) ;
return V_146 ;
}
static struct V_69 * F_62 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
return NULL ;
}
static int F_76 ( struct V_1 * V_4 , int V_147 , int V_148 ,
struct V_149 * V_150 )
{
struct V_151 * V_72 ;
struct V_69 * V_70 ;
struct V_99 * V_100 ;
if ( V_147 < 0 || V_147 >= V_4 -> V_152 )
return - V_153 ;
V_72 = & V_4 -> V_138 [ V_147 ] ;
F_77 ( & V_116 ) ;
V_70 = V_72 -> V_70 ;
V_72 -> V_70 = NULL ;
if ( ! V_70 ) {
F_78 ( & V_116 ) ;
return - V_153 ;
}
if ( V_147 == V_4 -> V_68 )
V_4 -> V_68 = - 1 ;
if ( V_147 + 1 == V_4 -> V_152 ) {
int V_154 ;
for ( V_154 = V_147 - 1 ; V_154 >= 0 ; V_154 -- ) {
if ( F_79 ( V_4 , V_154 ) )
break;
}
V_4 -> V_152 = V_154 + 1 ;
}
F_78 ( & V_116 ) ;
F_80 ( V_70 , - 1 ) ;
V_100 = F_47 ( V_70 ) ;
if ( V_100 ) {
F_50 ( V_100 -> V_102 , V_155 ) -- ;
F_81 ( F_40 ( V_70 ) , V_156 ,
V_157 ,
V_70 -> V_110 , & V_100 -> V_102 ) ;
F_82 ( V_100 ) ;
}
if ( V_72 -> V_13 & ( V_158 | V_159 ) && ! V_148 )
F_83 ( V_70 , V_150 ) ;
F_84 ( V_70 ) ;
return 0 ;
}
static void F_85 ( struct V_160 * V_150 )
{
struct V_56 * V_57 = F_86 ( V_150 , struct V_56 , V_161 ) ;
F_87 ( V_162 , V_57 ) ;
}
static inline void F_88 ( struct V_56 * V_57 )
{
F_89 ( & V_57 -> V_161 , F_85 ) ;
}
static void F_90 ( struct V_1 * V_4 , struct V_56 * V_57 )
{
struct V_2 * V_2 = F_91 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
struct V_163 * V_164 ;
F_92 ( & V_4 -> V_165 ) ;
while ( ( V_34 = F_93 ( & V_57 -> V_166 . V_167 . V_168 ) ) ) {
if ( F_94 ( V_34 ) -> V_85 == 0 ) {
struct V_169 * V_170 = F_71 ( V_34 ,
sizeof( struct V_126 ) ) ;
V_170 -> V_171 = V_172 ;
V_170 -> V_173 = F_95 ( sizeof( struct V_163 ) ) ;
F_96 ( V_34 , V_170 -> V_173 ) ;
V_164 = F_97 ( V_170 ) ;
V_164 -> error = - V_174 ;
memset ( & V_164 -> V_175 , 0 , sizeof( V_164 -> V_175 ) ) ;
F_98 ( V_34 , V_2 , F_99 ( V_34 ) . V_176 ) ;
} else {
F_56 ( V_34 ) ;
}
}
F_88 ( V_57 ) ;
}
static void V_67 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
unsigned long V_177 ;
unsigned long V_178 ;
struct V_56 * V_57 , * V_49 ;
if ( ! F_100 ( & V_179 ) ) {
F_101 ( & V_4 -> V_66 , V_180 + V_181 / 10 ) ;
return;
}
if ( F_102 ( & V_4 -> V_65 ) )
goto V_182;
V_177 = V_180 ;
V_178 = 10 * V_181 ;
F_24 (c, next, &mrt->mfc_unres_queue, list) {
if ( F_103 ( V_57 -> V_166 . V_167 . V_178 , V_177 ) ) {
unsigned long V_183 = V_57 -> V_166 . V_167 . V_178 - V_177 ;
if ( V_183 < V_178 )
V_178 = V_183 ;
continue;
}
F_25 ( & V_57 -> V_50 ) ;
F_104 ( V_4 , V_57 , V_184 ) ;
F_90 ( V_4 , V_57 ) ;
}
if ( ! F_102 ( & V_4 -> V_65 ) )
F_101 ( & V_4 -> V_66 , V_180 + V_178 ) ;
V_182:
F_105 ( & V_179 ) ;
}
static void F_106 ( struct V_1 * V_4 , struct V_56 * V_185 ,
unsigned char * V_186 )
{
int V_147 ;
V_185 -> V_166 . V_9 . V_187 = V_188 ;
V_185 -> V_166 . V_9 . V_152 = 0 ;
memset ( V_185 -> V_166 . V_9 . V_186 , 255 , V_188 ) ;
for ( V_147 = 0 ; V_147 < V_4 -> V_152 ; V_147 ++ ) {
if ( F_79 ( V_4 , V_147 ) &&
V_186 [ V_147 ] && V_186 [ V_147 ] < 255 ) {
V_185 -> V_166 . V_9 . V_186 [ V_147 ] = V_186 [ V_147 ] ;
if ( V_185 -> V_166 . V_9 . V_187 > V_147 )
V_185 -> V_166 . V_9 . V_187 = V_147 ;
if ( V_185 -> V_166 . V_9 . V_152 <= V_147 )
V_185 -> V_166 . V_9 . V_152 = V_147 + 1 ;
}
}
V_185 -> V_166 . V_9 . V_189 = V_180 ;
}
static int F_107 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_71 * V_190 , int V_191 )
{
int V_147 = V_190 -> V_90 ;
struct V_151 * V_72 = & V_4 -> V_138 [ V_147 ] ;
struct V_69 * V_70 ;
struct V_99 * V_100 ;
int V_7 ;
if ( F_79 ( V_4 , V_147 ) )
return - V_192 ;
switch ( V_190 -> V_193 ) {
case V_159 :
if ( ! F_108 () )
return - V_28 ;
if ( V_4 -> V_68 >= 0 )
return - V_192 ;
V_70 = F_62 ( V_2 , V_4 ) ;
if ( ! V_70 )
return - V_194 ;
V_7 = F_80 ( V_70 , 1 ) ;
if ( V_7 ) {
F_54 ( V_70 ) ;
F_84 ( V_70 ) ;
return V_7 ;
}
break;
case V_158 :
V_70 = F_51 ( V_2 , V_190 ) ;
if ( ! V_70 )
return - V_194 ;
V_7 = F_80 ( V_70 , 1 ) ;
if ( V_7 ) {
F_39 ( V_70 , V_190 ) ;
F_84 ( V_70 ) ;
return V_7 ;
}
break;
case V_195 :
case 0 :
if ( V_190 -> V_193 == V_195 ) {
V_70 = F_109 ( V_2 , V_190 -> V_196 ) ;
if ( V_70 && ! F_47 ( V_70 ) ) {
F_84 ( V_70 ) ;
return - V_153 ;
}
} else {
V_70 = F_110 ( V_2 , V_190 -> V_84 . V_82 ) ;
}
if ( ! V_70 )
return - V_153 ;
V_7 = F_80 ( V_70 , 1 ) ;
if ( V_7 ) {
F_84 ( V_70 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_100 = F_47 ( V_70 ) ;
if ( ! V_100 ) {
F_84 ( V_70 ) ;
return - V_153 ;
}
F_50 ( V_100 -> V_102 , V_155 ) ++ ;
F_81 ( V_2 , V_156 , V_157 ,
V_70 -> V_110 , & V_100 -> V_102 ) ;
F_82 ( V_100 ) ;
V_72 -> V_197 = V_190 -> V_198 ;
V_72 -> V_199 = V_190 -> V_84 . V_82 ;
V_72 -> V_200 = V_190 -> V_81 . V_82 ;
V_72 -> V_13 = V_190 -> V_193 ;
if ( ! V_191 )
V_72 -> V_13 |= V_201 ;
V_72 -> V_202 = V_190 -> V_203 ;
V_72 -> V_204 = 0 ;
V_72 -> V_205 = 0 ;
V_72 -> V_206 = 0 ;
V_72 -> V_207 = 0 ;
V_72 -> V_208 = V_70 -> V_110 ;
if ( V_72 -> V_13 & ( V_158 | V_159 ) )
V_72 -> V_208 = F_111 ( V_70 ) ;
F_77 ( & V_116 ) ;
V_72 -> V_70 = V_70 ;
if ( V_72 -> V_13 & V_159 )
V_4 -> V_68 = V_147 ;
if ( V_147 + 1 > V_4 -> V_152 )
V_4 -> V_152 = V_147 + 1 ;
F_78 ( & V_116 ) ;
return 0 ;
}
static struct V_56 * F_112 ( struct V_1 * V_4 ,
T_6 V_209 ,
T_6 V_210 )
{
struct V_53 V_11 = {
. V_58 = V_210 ,
. V_59 = V_209
} ;
struct V_211 * V_154 , * V_50 ;
struct V_56 * V_57 ;
V_50 = F_113 ( & V_4 -> V_62 , & V_11 , V_63 ) ;
F_114 (c, tmp, list, mnode)
return V_57 ;
return NULL ;
}
static struct V_56 * F_115 ( struct V_1 * V_4 ,
int V_147 )
{
struct V_53 V_11 = {
. V_58 = F_116 ( V_212 ) ,
. V_59 = F_116 (INADDR_ANY)
} ;
struct V_211 * V_154 , * V_50 ;
struct V_56 * V_57 ;
V_50 = F_113 ( & V_4 -> V_62 , & V_11 , V_63 ) ;
F_114 (c, tmp, list, mnode)
if ( V_57 -> V_166 . V_9 . V_186 [ V_147 ] < 255 )
return V_57 ;
return NULL ;
}
static struct V_56 * F_117 ( struct V_1 * V_4 ,
T_6 V_210 , int V_147 )
{
struct V_53 V_11 = {
. V_58 = V_210 ,
. V_59 = F_116 (INADDR_ANY)
} ;
struct V_211 * V_154 , * V_50 ;
struct V_56 * V_57 , * V_213 ;
if ( V_210 == F_116 ( V_212 ) )
goto V_214;
V_50 = F_113 ( & V_4 -> V_62 , & V_11 , V_63 ) ;
F_114 (c, tmp, list, mnode) {
if ( V_57 -> V_166 . V_9 . V_186 [ V_147 ] < 255 )
return V_57 ;
V_213 = F_115 ( V_4 , V_57 -> V_215 ) ;
if ( V_213 && V_213 -> V_166 . V_9 . V_186 [ V_147 ] < 255 )
return V_57 ;
}
V_214:
return F_115 ( V_4 , V_147 ) ;
}
static struct V_56 * F_118 ( struct V_1 * V_4 ,
T_6 V_209 , T_6 V_210 ,
int V_216 )
{
struct V_53 V_11 = {
. V_58 = V_210 ,
. V_59 = V_209 ,
} ;
struct V_211 * V_154 , * V_50 ;
struct V_56 * V_57 ;
V_50 = F_113 ( & V_4 -> V_62 , & V_11 , V_63 ) ;
F_114 (c, tmp, list, mnode)
if ( V_216 == - 1 || V_216 == V_57 -> V_215 )
return V_57 ;
return NULL ;
}
static struct V_56 * F_119 ( void )
{
struct V_56 * V_57 = F_120 ( V_162 , V_60 ) ;
if ( V_57 ) {
V_57 -> V_166 . V_9 . V_217 = V_180 - V_218 - 1 ;
V_57 -> V_166 . V_9 . V_187 = V_188 ;
}
return V_57 ;
}
static struct V_56 * F_121 ( void )
{
struct V_56 * V_57 = F_120 ( V_162 , V_219 ) ;
if ( V_57 ) {
F_122 ( & V_57 -> V_166 . V_167 . V_168 ) ;
V_57 -> V_166 . V_167 . V_178 = V_180 + 10 * V_181 ;
}
return V_57 ;
}
static void F_123 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_56 * V_220 , struct V_56 * V_57 )
{
struct V_33 * V_34 ;
struct V_163 * V_164 ;
while ( ( V_34 = F_124 ( & V_220 -> V_166 . V_167 . V_168 ) ) ) {
if ( F_94 ( V_34 ) -> V_85 == 0 ) {
struct V_169 * V_170 = F_71 ( V_34 ,
sizeof( struct V_126 ) ) ;
if ( F_125 ( V_4 , V_34 , V_57 , F_97 ( V_170 ) ) > 0 ) {
V_170 -> V_173 = F_126 ( V_34 ) -
( V_141 * ) V_170 ;
} else {
V_170 -> V_171 = V_172 ;
V_170 -> V_173 = F_95 ( sizeof( struct V_163 ) ) ;
F_96 ( V_34 , V_170 -> V_173 ) ;
V_164 = F_97 ( V_170 ) ;
V_164 -> error = - V_221 ;
memset ( & V_164 -> V_175 , 0 , sizeof( V_164 -> V_175 ) ) ;
}
F_98 ( V_34 , V_2 , F_99 ( V_34 ) . V_176 ) ;
} else {
F_127 ( V_2 , V_4 , V_34 -> V_70 , V_34 , V_57 , 0 ) ;
}
}
}
static int F_58 ( struct V_1 * V_4 ,
struct V_33 * V_222 , T_7 V_147 , int assert )
{
const int V_86 = F_128 ( V_222 ) ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_227 * V_175 ;
struct V_33 * V_34 ;
int V_228 ;
if ( assert == V_121 )
V_34 = F_129 ( V_222 , sizeof( struct V_126 ) ) ;
else
V_34 = F_130 ( 128 , V_219 ) ;
if ( ! V_34 )
return - V_194 ;
if ( assert == V_121 ) {
F_131 ( V_34 , sizeof( struct V_126 ) ) ;
F_72 ( V_34 ) ;
F_132 ( V_34 ) ;
V_175 = (struct V_227 * ) F_133 ( V_34 ) ;
memcpy ( V_175 , F_133 ( V_222 ) , sizeof( struct V_126 ) ) ;
V_175 -> V_229 = V_121 ;
V_175 -> V_230 = 0 ;
V_175 -> V_231 = V_4 -> V_68 ;
F_94 ( V_34 ) -> V_86 = sizeof( struct V_126 ) >> 2 ;
F_94 ( V_34 ) -> V_137 = F_73 ( F_70 ( F_94 ( V_222 ) -> V_137 ) +
sizeof( struct V_126 ) ) ;
} else {
F_134 ( V_34 , V_34 -> V_119 ) ;
F_135 ( V_34 , V_86 ) ;
F_136 ( V_34 , V_222 -> V_142 , V_86 ) ;
F_94 ( V_34 ) -> V_87 = 0 ;
V_175 = (struct V_227 * ) F_133 ( V_34 ) ;
V_175 -> V_231 = V_147 ;
F_137 ( V_34 , F_138 ( F_139 ( V_222 ) ) ) ;
V_226 = F_135 ( V_34 , sizeof( struct V_225 ) ) ;
V_226 -> type = assert ;
V_175 -> V_229 = assert ;
V_226 -> V_232 = 0 ;
F_94 ( V_34 ) -> V_137 = F_73 ( V_34 -> V_119 ) ;
V_34 -> V_233 = V_34 -> V_140 ;
}
F_140 () ;
V_224 = F_141 ( V_4 -> V_224 ) ;
if ( ! V_224 ) {
F_142 () ;
F_56 ( V_34 ) ;
return - V_28 ;
}
F_143 ( V_4 , V_34 ) ;
V_228 = F_144 ( V_224 , V_34 ) ;
F_142 () ;
if ( V_228 < 0 ) {
F_145 ( L_5 ) ;
F_56 ( V_34 ) ;
}
return V_228 ;
}
static int F_146 ( struct V_1 * V_4 , T_7 V_147 ,
struct V_33 * V_34 , struct V_69 * V_70 )
{
const struct V_126 * V_79 = F_94 ( V_34 ) ;
struct V_56 * V_57 ;
bool V_234 = false ;
int V_7 ;
F_147 ( & V_179 ) ;
F_148 (c, &mrt->mfc_unres_queue, list) {
if ( V_57 -> V_58 == V_79 -> V_80 &&
V_57 -> V_59 == V_79 -> V_83 ) {
V_234 = true ;
break;
}
}
if ( ! V_234 ) {
if ( F_149 ( & V_4 -> V_165 ) >= 10 ||
( V_57 = F_121 () ) == NULL ) {
F_150 ( & V_179 ) ;
F_56 ( V_34 ) ;
return - V_194 ;
}
V_57 -> V_215 = - 1 ;
V_57 -> V_59 = V_79 -> V_83 ;
V_57 -> V_58 = V_79 -> V_80 ;
V_7 = F_58 ( V_4 , V_34 , V_147 , V_235 ) ;
if ( V_7 < 0 ) {
F_150 ( & V_179 ) ;
F_88 ( V_57 ) ;
F_56 ( V_34 ) ;
return V_7 ;
}
F_151 ( & V_4 -> V_165 ) ;
F_152 ( & V_57 -> V_50 , & V_4 -> V_65 ) ;
F_104 ( V_4 , V_57 , V_236 ) ;
if ( F_149 ( & V_4 -> V_165 ) == 1 )
F_101 ( & V_4 -> V_66 , V_57 -> V_166 . V_167 . V_178 ) ;
}
if ( V_57 -> V_166 . V_167 . V_168 . V_237 > 3 ) {
F_56 ( V_34 ) ;
V_7 = - V_194 ;
} else {
if ( V_70 ) {
V_34 -> V_70 = V_70 ;
V_34 -> V_112 = V_70 -> V_110 ;
}
F_153 ( & V_57 -> V_166 . V_167 . V_168 , V_34 ) ;
V_7 = 0 ;
}
F_150 ( & V_179 ) ;
return V_7 ;
}
static int F_154 ( struct V_1 * V_4 , struct V_238 * V_239 , int V_216 )
{
struct V_56 * V_57 ;
F_140 () ;
V_57 = F_118 ( V_4 , V_239 -> V_240 . V_82 ,
V_239 -> V_241 . V_82 , V_216 ) ;
F_142 () ;
if ( ! V_57 )
return - V_242 ;
F_155 ( & V_4 -> V_62 , & V_57 -> V_243 , V_63 ) ;
F_156 ( & V_57 -> V_50 ) ;
F_104 ( V_4 , V_57 , V_184 ) ;
F_88 ( V_57 ) ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_238 * V_239 , int V_191 , int V_216 )
{
struct V_56 * V_220 , * V_57 ;
bool V_234 ;
int V_228 ;
if ( V_239 -> V_244 >= V_188 )
return - V_245 ;
F_140 () ;
V_57 = F_118 ( V_4 , V_239 -> V_240 . V_82 ,
V_239 -> V_241 . V_82 , V_216 ) ;
F_142 () ;
if ( V_57 ) {
F_77 ( & V_116 ) ;
V_57 -> V_215 = V_239 -> V_244 ;
F_106 ( V_4 , V_57 , V_239 -> V_246 ) ;
if ( ! V_191 )
V_57 -> V_247 |= V_248 ;
F_78 ( & V_116 ) ;
F_104 ( V_4 , V_57 , V_236 ) ;
return 0 ;
}
if ( V_239 -> V_241 . V_82 != F_116 ( V_212 ) &&
! F_69 ( V_239 -> V_241 . V_82 ) )
return - V_28 ;
V_57 = F_119 () ;
if ( ! V_57 )
return - V_61 ;
V_57 -> V_59 = V_239 -> V_240 . V_82 ;
V_57 -> V_58 = V_239 -> V_241 . V_82 ;
V_57 -> V_215 = V_239 -> V_244 ;
F_106 ( V_4 , V_57 , V_239 -> V_246 ) ;
if ( ! V_191 )
V_57 -> V_247 |= V_248 ;
V_228 = F_158 ( & V_4 -> V_62 , & V_57 -> V_54 , & V_57 -> V_243 ,
V_63 ) ;
if ( V_228 ) {
F_159 ( L_6 , V_228 ) ;
F_88 ( V_57 ) ;
return V_228 ;
}
F_34 ( & V_57 -> V_50 , & V_4 -> V_64 ) ;
V_234 = false ;
F_147 ( & V_179 ) ;
F_148 (uc, &mrt->mfc_unres_queue, list) {
if ( V_220 -> V_59 == V_57 -> V_59 &&
V_220 -> V_58 == V_57 -> V_58 ) {
F_25 ( & V_220 -> V_50 ) ;
F_92 ( & V_4 -> V_165 ) ;
V_234 = true ;
break;
}
}
if ( F_102 ( & V_4 -> V_65 ) )
F_160 ( & V_4 -> V_66 ) ;
F_150 ( & V_179 ) ;
if ( V_234 ) {
F_123 ( V_2 , V_4 , V_220 , V_57 ) ;
F_88 ( V_220 ) ;
}
F_104 ( V_4 , V_57 , V_236 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_4 , bool V_249 )
{
struct V_56 * V_57 , * V_154 ;
F_161 ( V_50 ) ;
int V_250 ;
for ( V_250 = 0 ; V_250 < V_4 -> V_152 ; V_250 ++ ) {
if ( ! V_249 && ( V_4 -> V_138 [ V_250 ] . V_13 & V_201 ) )
continue;
F_76 ( V_4 , V_250 , 0 , & V_50 ) ;
}
F_162 ( & V_50 ) ;
F_24 (c, tmp, &mrt->mfc_cache_list, list) {
if ( ! V_249 && ( V_57 -> V_247 & V_248 ) )
continue;
F_155 ( & V_4 -> V_62 , & V_57 -> V_243 , V_63 ) ;
F_156 ( & V_57 -> V_50 ) ;
F_104 ( V_4 , V_57 , V_184 ) ;
F_88 ( V_57 ) ;
}
if ( F_149 ( & V_4 -> V_165 ) != 0 ) {
F_147 ( & V_179 ) ;
F_24 (c, tmp, &mrt->mfc_unres_queue, list) {
F_25 ( & V_57 -> V_50 ) ;
F_104 ( V_4 , V_57 , V_184 ) ;
F_90 ( V_4 , V_57 ) ;
}
F_150 ( & V_179 ) ;
}
}
static void F_163 ( struct V_223 * V_251 )
{
struct V_2 * V_2 = F_164 ( V_251 ) ;
struct V_1 * V_4 ;
F_46 () ;
F_2 (mrt, net) {
if ( V_251 == F_165 ( V_4 -> V_224 ) ) {
F_166 ( V_2 , V_155 ) -- ;
F_81 ( V_2 , V_156 ,
V_157 ,
V_252 ,
V_2 -> V_15 . V_253 ) ;
F_167 ( V_4 -> V_224 , NULL ) ;
F_36 ( V_4 , false ) ;
}
}
}
int F_168 ( struct V_223 * V_251 , int V_254 , char V_94 * V_255 ,
unsigned int V_256 )
{
struct V_2 * V_2 = F_164 ( V_251 ) ;
int V_257 , V_228 = 0 , V_216 = 0 ;
struct V_1 * V_4 ;
struct V_71 V_258 ;
struct V_238 V_239 ;
T_1 V_259 ;
F_23 () ;
if ( V_251 -> V_260 != V_261 ||
F_169 ( V_251 ) -> V_262 != V_263 ) {
V_228 = - V_105 ;
goto V_264;
}
V_4 = F_1 ( V_2 , F_170 ( V_251 ) -> V_265 ? : V_46 ) ;
if ( ! V_4 ) {
V_228 = - V_242 ;
goto V_264;
}
if ( V_254 != V_266 ) {
if ( V_251 != F_171 ( V_4 -> V_224 ) &&
! F_172 ( V_2 -> V_267 , V_268 ) ) {
V_228 = - V_26 ;
goto V_264;
}
}
switch ( V_254 ) {
case V_266 :
if ( V_256 != sizeof( int ) ) {
V_228 = - V_28 ;
break;
}
if ( F_165 ( V_4 -> V_224 ) ) {
V_228 = - V_192 ;
break;
}
V_228 = F_173 ( V_251 , 1 , F_163 ) ;
if ( V_228 == 0 ) {
F_174 ( V_4 -> V_224 , V_251 ) ;
F_166 ( V_2 , V_155 ) ++ ;
F_81 ( V_2 , V_156 ,
V_157 ,
V_252 ,
V_2 -> V_15 . V_253 ) ;
}
break;
case V_269 :
if ( V_251 != F_171 ( V_4 -> V_224 ) ) {
V_228 = - V_26 ;
} else {
V_228 = F_173 ( V_251 , 0 , NULL ) ;
goto V_264;
}
break;
case V_270 :
case V_271 :
if ( V_256 != sizeof( V_258 ) ) {
V_228 = - V_28 ;
break;
}
if ( F_175 ( & V_258 , V_255 , sizeof( V_258 ) ) ) {
V_228 = - V_272 ;
break;
}
if ( V_258 . V_90 >= V_188 ) {
V_228 = - V_245 ;
break;
}
if ( V_254 == V_270 ) {
V_228 = F_107 ( V_2 , V_4 , & V_258 ,
V_251 == F_165 ( V_4 -> V_224 ) ) ;
} else {
V_228 = F_76 ( V_4 , V_258 . V_90 , 0 , NULL ) ;
}
break;
case V_273 :
case V_274 :
V_216 = - 1 ;
case V_275 :
case V_276 :
if ( V_256 != sizeof( V_239 ) ) {
V_228 = - V_28 ;
break;
}
if ( F_175 ( & V_239 , V_255 , sizeof( V_239 ) ) ) {
V_228 = - V_272 ;
break;
}
if ( V_216 == 0 )
V_216 = V_239 . V_244 ;
if ( V_254 == V_274 || V_254 == V_276 )
V_228 = F_154 ( V_4 , & V_239 , V_216 ) ;
else
V_228 = F_157 ( V_2 , V_4 , & V_239 ,
V_251 == F_165 ( V_4 -> V_224 ) ,
V_216 ) ;
break;
case V_277 :
if ( V_256 != sizeof( V_257 ) ) {
V_228 = - V_28 ;
break;
}
if ( F_176 ( V_257 , ( int V_94 * ) V_255 ) ) {
V_228 = - V_272 ;
break;
}
V_4 -> V_278 = V_257 ;
break;
case V_279 :
if ( ! F_108 () ) {
V_228 = - V_280 ;
break;
}
if ( V_256 != sizeof( V_257 ) ) {
V_228 = - V_28 ;
break;
}
if ( F_176 ( V_257 , ( int V_94 * ) V_255 ) ) {
V_228 = - V_272 ;
break;
}
V_257 = ! ! V_257 ;
if ( V_257 != V_4 -> V_281 ) {
V_4 -> V_281 = V_257 ;
V_4 -> V_278 = V_257 ;
}
break;
case V_282 :
if ( ! F_177 ( F_33 ) ) {
V_228 = - V_280 ;
break;
}
if ( V_256 != sizeof( V_259 ) ) {
V_228 = - V_28 ;
break;
}
if ( F_176 ( V_259 , ( T_1 V_94 * ) V_255 ) ) {
V_228 = - V_272 ;
break;
}
if ( V_251 == F_165 ( V_4 -> V_224 ) ) {
V_228 = - V_283 ;
} else {
V_4 = F_18 ( V_2 , V_259 ) ;
if ( F_15 ( V_4 ) )
V_228 = F_16 ( V_4 ) ;
else
F_170 ( V_251 ) -> V_265 = V_259 ;
}
break;
default:
V_228 = - V_280 ;
}
V_264:
F_26 () ;
return V_228 ;
}
int F_178 ( struct V_223 * V_251 , int V_254 , char V_94 * V_255 , int V_94 * V_256 )
{
int V_284 ;
int V_257 ;
struct V_2 * V_2 = F_164 ( V_251 ) ;
struct V_1 * V_4 ;
if ( V_251 -> V_260 != V_261 ||
F_169 ( V_251 ) -> V_262 != V_263 )
return - V_105 ;
V_4 = F_1 ( V_2 , F_170 ( V_251 ) -> V_265 ? : V_46 ) ;
if ( ! V_4 )
return - V_242 ;
switch ( V_254 ) {
case V_285 :
V_257 = 0x0305 ;
break;
case V_279 :
if ( ! F_108 () )
return - V_280 ;
V_257 = V_4 -> V_281 ;
break;
case V_277 :
V_257 = V_4 -> V_278 ;
break;
default:
return - V_280 ;
}
if ( F_176 ( V_284 , V_256 ) )
return - V_272 ;
V_284 = F_179 (unsigned int, olr, sizeof(int)) ;
if ( V_284 < 0 )
return - V_28 ;
if ( F_180 ( V_284 , V_256 ) )
return - V_272 ;
if ( F_181 ( V_255 , & V_257 , V_284 ) )
return - V_272 ;
return 0 ;
}
int F_182 ( struct V_223 * V_251 , int V_286 , void V_94 * V_11 )
{
struct V_287 V_288 ;
struct V_289 V_290 ;
struct V_151 * V_258 ;
struct V_56 * V_57 ;
struct V_2 * V_2 = F_164 ( V_251 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_170 ( V_251 ) -> V_265 ? : V_46 ) ;
if ( ! V_4 )
return - V_242 ;
switch ( V_286 ) {
case V_291 :
if ( F_175 ( & V_290 , V_11 , sizeof( V_290 ) ) )
return - V_272 ;
if ( V_290 . V_147 >= V_4 -> V_152 )
return - V_28 ;
F_57 ( & V_116 ) ;
V_258 = & V_4 -> V_138 [ V_290 . V_147 ] ;
if ( F_79 ( V_4 , V_290 . V_147 ) ) {
V_290 . V_292 = V_258 -> V_206 ;
V_290 . V_293 = V_258 -> V_207 ;
V_290 . V_294 = V_258 -> V_204 ;
V_290 . V_295 = V_258 -> V_205 ;
F_59 ( & V_116 ) ;
if ( F_181 ( V_11 , & V_290 , sizeof( V_290 ) ) )
return - V_272 ;
return 0 ;
}
F_59 ( & V_116 ) ;
return - V_153 ;
case V_296 :
if ( F_175 ( & V_288 , V_11 , sizeof( V_288 ) ) )
return - V_272 ;
F_140 () ;
V_57 = F_112 ( V_4 , V_288 . V_297 . V_82 , V_288 . V_298 . V_82 ) ;
if ( V_57 ) {
V_288 . V_299 = V_57 -> V_166 . V_9 . V_222 ;
V_288 . V_300 = V_57 -> V_166 . V_9 . V_301 ;
V_288 . V_302 = V_57 -> V_166 . V_9 . V_302 ;
F_142 () ;
if ( F_181 ( V_11 , & V_288 , sizeof( V_288 ) ) )
return - V_272 ;
return 0 ;
}
F_142 () ;
return - V_153 ;
default:
return - V_303 ;
}
}
int F_183 ( struct V_223 * V_251 , unsigned int V_286 , void V_94 * V_11 )
{
struct V_304 V_288 ;
struct V_305 V_290 ;
struct V_151 * V_258 ;
struct V_56 * V_57 ;
struct V_2 * V_2 = F_164 ( V_251 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_170 ( V_251 ) -> V_265 ? : V_46 ) ;
if ( ! V_4 )
return - V_242 ;
switch ( V_286 ) {
case V_291 :
if ( F_175 ( & V_290 , V_11 , sizeof( V_290 ) ) )
return - V_272 ;
if ( V_290 . V_147 >= V_4 -> V_152 )
return - V_28 ;
F_57 ( & V_116 ) ;
V_258 = & V_4 -> V_138 [ V_290 . V_147 ] ;
if ( F_79 ( V_4 , V_290 . V_147 ) ) {
V_290 . V_292 = V_258 -> V_206 ;
V_290 . V_293 = V_258 -> V_207 ;
V_290 . V_294 = V_258 -> V_204 ;
V_290 . V_295 = V_258 -> V_205 ;
F_59 ( & V_116 ) ;
if ( F_181 ( V_11 , & V_290 , sizeof( V_290 ) ) )
return - V_272 ;
return 0 ;
}
F_59 ( & V_116 ) ;
return - V_153 ;
case V_296 :
if ( F_175 ( & V_288 , V_11 , sizeof( V_288 ) ) )
return - V_272 ;
F_140 () ;
V_57 = F_112 ( V_4 , V_288 . V_297 . V_82 , V_288 . V_298 . V_82 ) ;
if ( V_57 ) {
V_288 . V_299 = V_57 -> V_166 . V_9 . V_222 ;
V_288 . V_300 = V_57 -> V_166 . V_9 . V_301 ;
V_288 . V_302 = V_57 -> V_166 . V_9 . V_302 ;
F_142 () ;
if ( F_181 ( V_11 , & V_288 , sizeof( V_288 ) ) )
return - V_272 ;
return 0 ;
}
F_142 () ;
return - V_153 ;
default:
return - V_303 ;
}
}
static int F_184 ( struct V_306 * V_307 , unsigned long V_308 , void * V_52 )
{
struct V_69 * V_70 = F_185 ( V_52 ) ;
struct V_2 * V_2 = F_40 ( V_70 ) ;
struct V_1 * V_4 ;
struct V_151 * V_72 ;
int V_309 ;
if ( V_308 != V_310 )
return V_311 ;
F_2 (mrt, net) {
V_72 = & V_4 -> V_138 [ 0 ] ;
for ( V_309 = 0 ; V_309 < V_4 -> V_152 ; V_309 ++ , V_72 ++ ) {
if ( V_72 -> V_70 == V_70 )
F_76 ( V_4 , V_309 , 1 , NULL ) ;
}
}
return V_311 ;
}
static void F_186 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_83 , T_6 V_80 )
{
struct V_126 * V_79 ;
const struct V_126 * V_312 = F_94 ( V_34 ) ;
F_131 ( V_34 , sizeof( struct V_126 ) ) ;
V_34 -> V_233 = V_34 -> V_140 ;
F_72 ( V_34 ) ;
V_79 = F_94 ( V_34 ) ;
V_79 -> V_85 = 4 ;
V_79 -> V_41 = V_312 -> V_41 ;
V_79 -> V_313 = V_312 -> V_313 ;
V_79 -> V_314 = 0 ;
V_79 -> V_80 = V_80 ;
V_79 -> V_83 = V_83 ;
V_79 -> V_87 = V_88 ;
V_79 -> V_86 = 5 ;
V_79 -> V_137 = F_73 ( V_34 -> V_119 ) ;
F_187 ( V_2 , V_34 , NULL ) ;
F_188 ( V_79 ) ;
memset ( & ( F_189 ( V_34 ) -> V_315 ) , 0 , sizeof( F_189 ( V_34 ) -> V_315 ) ) ;
F_190 ( V_34 ) ;
}
static inline int F_191 ( struct V_2 * V_2 , struct V_223 * V_251 ,
struct V_33 * V_34 )
{
struct V_316 * V_315 = & ( F_189 ( V_34 ) -> V_315 ) ;
F_192 ( V_2 , V_317 ) ;
F_193 ( V_2 , V_318 , V_34 -> V_119 ) ;
if ( F_194 ( V_315 -> V_256 ) )
F_195 ( V_34 ) ;
return F_196 ( V_2 , V_251 , V_34 ) ;
}
static void F_197 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_56 * V_57 , int V_147 )
{
const struct V_126 * V_79 = F_94 ( V_34 ) ;
struct V_151 * V_258 = & V_4 -> V_138 [ V_147 ] ;
struct V_69 * V_70 ;
struct V_319 * V_320 ;
struct V_5 V_108 ;
int V_136 = 0 ;
if ( ! V_258 -> V_70 )
goto V_321;
if ( V_258 -> V_13 & V_159 ) {
V_258 -> V_207 ++ ;
V_258 -> V_205 += V_34 -> V_119 ;
V_258 -> V_70 -> V_117 . V_118 += V_34 -> V_119 ;
V_258 -> V_70 -> V_117 . V_120 ++ ;
F_58 ( V_4 , V_34 , V_147 , V_121 ) ;
goto V_321;
}
if ( V_258 -> V_13 & V_158 ) {
V_320 = F_198 ( V_2 , & V_108 , NULL ,
V_258 -> V_200 , V_258 -> V_199 ,
0 , 0 ,
V_88 ,
F_199 ( V_79 -> V_41 ) , V_258 -> V_208 ) ;
if ( F_15 ( V_320 ) )
goto V_321;
V_136 = sizeof( struct V_126 ) ;
} else {
V_320 = F_198 ( V_2 , & V_108 , NULL , V_79 -> V_80 , 0 ,
0 , 0 ,
V_88 ,
F_199 ( V_79 -> V_41 ) , V_258 -> V_208 ) ;
if ( F_15 ( V_320 ) )
goto V_321;
}
V_70 = V_320 -> V_322 . V_70 ;
if ( V_34 -> V_119 + V_136 > F_200 ( & V_320 -> V_322 ) && ( F_70 ( V_79 -> V_314 ) & V_323 ) ) {
F_192 ( V_2 , V_324 ) ;
F_201 ( V_320 ) ;
goto V_321;
}
V_136 += F_202 ( V_70 ) + V_320 -> V_322 . V_325 ;
if ( F_203 ( V_34 , V_136 ) ) {
F_201 ( V_320 ) ;
goto V_321;
}
V_258 -> V_207 ++ ;
V_258 -> V_205 += V_34 -> V_119 ;
F_204 ( V_34 ) ;
F_137 ( V_34 , & V_320 -> V_322 ) ;
F_205 ( F_94 ( V_34 ) ) ;
if ( V_258 -> V_13 & V_158 ) {
F_186 ( V_2 , V_34 , V_258 -> V_199 , V_258 -> V_200 ) ;
V_258 -> V_70 -> V_117 . V_120 ++ ;
V_258 -> V_70 -> V_117 . V_118 += V_34 -> V_119 ;
}
F_189 ( V_34 ) -> V_13 |= V_326 ;
F_206 ( V_327 , V_328 ,
V_2 , NULL , V_34 , V_34 -> V_70 , V_70 ,
F_191 ) ;
return;
V_321:
F_56 ( V_34 ) ;
}
static int F_207 ( struct V_1 * V_4 , struct V_69 * V_70 )
{
int V_309 ;
for ( V_309 = V_4 -> V_152 - 1 ; V_309 >= 0 ; V_309 -- ) {
if ( V_4 -> V_138 [ V_309 ] . V_70 == V_70 )
break;
}
return V_309 ;
}
static void F_127 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_69 * V_70 , struct V_33 * V_34 ,
struct V_56 * V_185 , int V_199 )
{
int V_329 = F_207 ( V_4 , V_70 ) ;
int V_330 = - 1 ;
int V_258 , V_309 ;
V_258 = V_185 -> V_215 ;
V_185 -> V_166 . V_9 . V_222 ++ ;
V_185 -> V_166 . V_9 . V_301 += V_34 -> V_119 ;
V_185 -> V_166 . V_9 . V_189 = V_180 ;
if ( V_185 -> V_59 == F_116 ( V_212 ) && V_329 >= 0 ) {
struct V_56 * V_331 ;
V_331 = F_115 ( V_4 , V_258 ) ;
if ( V_331 &&
V_331 -> V_166 . V_9 . V_186 [ V_329 ] < 255 )
goto V_332;
}
if ( V_4 -> V_138 [ V_258 ] . V_70 != V_70 ) {
if ( F_208 ( F_209 ( V_34 ) ) ) {
goto V_333;
}
V_185 -> V_166 . V_9 . V_302 ++ ;
if ( V_329 >= 0 && V_4 -> V_278 &&
( V_4 -> V_281 ||
V_185 -> V_166 . V_9 . V_186 [ V_329 ] < 255 ) &&
F_103 ( V_180 ,
V_185 -> V_166 . V_9 . V_217 + V_218 ) ) {
V_185 -> V_166 . V_9 . V_217 = V_180 ;
F_58 ( V_4 , V_34 , V_329 , V_334 ) ;
}
goto V_333;
}
V_332:
V_4 -> V_138 [ V_258 ] . V_206 ++ ;
V_4 -> V_138 [ V_258 ] . V_204 += V_34 -> V_119 ;
if ( V_185 -> V_59 == F_116 ( V_212 ) &&
V_185 -> V_58 == F_116 ( V_212 ) ) {
if ( V_329 >= 0 &&
V_329 != V_185 -> V_215 &&
F_94 ( V_34 ) -> V_313 >
V_185 -> V_166 . V_9 . V_186 [ V_185 -> V_215 ] ) {
V_330 = V_185 -> V_215 ;
goto V_335;
}
goto V_333;
}
for ( V_309 = V_185 -> V_166 . V_9 . V_152 - 1 ;
V_309 >= V_185 -> V_166 . V_9 . V_187 ; V_309 -- ) {
if ( ( V_185 -> V_59 != F_116 ( V_212 ) ||
V_309 != V_329 ) &&
F_94 ( V_34 ) -> V_313 > V_185 -> V_166 . V_9 . V_186 [ V_309 ] ) {
if ( V_330 != - 1 ) {
struct V_33 * V_336 = F_210 ( V_34 , V_219 ) ;
if ( V_336 )
F_197 ( V_2 , V_4 , V_336 , V_185 ,
V_330 ) ;
}
V_330 = V_309 ;
}
}
V_335:
if ( V_330 != - 1 ) {
if ( V_199 ) {
struct V_33 * V_336 = F_210 ( V_34 , V_219 ) ;
if ( V_336 )
F_197 ( V_2 , V_4 , V_336 , V_185 , V_330 ) ;
} else {
F_197 ( V_2 , V_4 , V_34 , V_185 , V_330 ) ;
return;
}
}
V_333:
if ( ! V_199 )
F_56 ( V_34 ) ;
}
static struct V_1 * F_211 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_319 * V_320 = F_209 ( V_34 ) ;
struct V_126 * V_79 = F_94 ( V_34 ) ;
struct V_5 V_108 = {
. V_80 = V_79 -> V_80 ,
. V_83 = V_79 -> V_83 ,
. V_337 = F_199 ( V_79 -> V_41 ) ,
. V_109 = ( F_208 ( V_320 ) ?
V_34 -> V_70 -> V_110 : 0 ) ,
. V_111 = ( F_208 ( V_320 ) ?
V_113 :
V_34 -> V_70 -> V_110 ) ,
. V_114 = V_34 -> V_115 ,
} ;
struct V_1 * V_4 ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_108 , & V_4 ) ;
if ( V_7 )
return F_28 ( V_7 ) ;
return V_4 ;
}
int F_212 ( struct V_33 * V_34 )
{
struct V_56 * V_185 ;
struct V_2 * V_2 = F_40 ( V_34 -> V_70 ) ;
int V_199 = F_209 ( V_34 ) -> V_338 & V_339 ;
struct V_1 * V_4 ;
struct V_69 * V_70 ;
V_70 = V_34 -> V_70 ;
if ( F_213 ( V_34 -> V_70 ) ) {
V_70 = F_214 ( V_2 , F_189 ( V_34 ) -> V_340 ) ;
if ( ! V_70 ) {
F_56 ( V_34 ) ;
return - V_341 ;
}
}
if ( F_189 ( V_34 ) -> V_13 & V_326 )
goto V_333;
V_4 = F_211 ( V_2 , V_34 ) ;
if ( F_15 ( V_4 ) ) {
F_56 ( V_34 ) ;
return F_16 ( V_4 ) ;
}
if ( ! V_199 ) {
if ( F_189 ( V_34 ) -> V_315 . V_342 ) {
if ( F_215 ( V_34 ) )
return 0 ;
} else if ( F_94 ( V_34 ) -> V_87 == V_263 ) {
struct V_223 * V_224 ;
V_224 = F_141 ( V_4 -> V_224 ) ;
if ( V_224 ) {
F_190 ( V_34 ) ;
F_216 ( V_224 , V_34 ) ;
return 0 ;
}
}
}
V_185 = F_112 ( V_4 , F_94 ( V_34 ) -> V_83 , F_94 ( V_34 ) -> V_80 ) ;
if ( ! V_185 ) {
int V_258 = F_207 ( V_4 , V_70 ) ;
if ( V_258 >= 0 )
V_185 = F_117 ( V_4 , F_94 ( V_34 ) -> V_80 ,
V_258 ) ;
}
if ( ! V_185 ) {
int V_258 ;
if ( V_199 ) {
struct V_33 * V_336 = F_210 ( V_34 , V_219 ) ;
F_217 ( V_34 ) ;
if ( ! V_336 )
return - V_194 ;
V_34 = V_336 ;
}
F_57 ( & V_116 ) ;
V_258 = F_207 ( V_4 , V_70 ) ;
if ( V_258 >= 0 ) {
int V_48 = F_146 ( V_4 , V_258 , V_34 , V_70 ) ;
F_59 ( & V_116 ) ;
return V_48 ;
}
F_59 ( & V_116 ) ;
F_56 ( V_34 ) ;
return - V_341 ;
}
F_57 ( & V_116 ) ;
F_127 ( V_2 , V_4 , V_70 , V_34 , V_185 , V_199 ) ;
F_59 ( & V_116 ) ;
if ( V_199 )
return F_217 ( V_34 ) ;
return 0 ;
V_333:
if ( V_199 )
return F_217 ( V_34 ) ;
F_56 ( V_34 ) ;
return 0 ;
}
int F_218 ( struct V_33 * V_34 )
{
struct V_225 * V_343 ;
struct V_2 * V_2 = F_40 ( V_34 -> V_70 ) ;
struct V_1 * V_4 ;
if ( ! F_219 ( V_34 , sizeof( * V_343 ) + sizeof( struct V_126 ) ) )
goto V_344;
V_343 = F_220 ( V_34 ) ;
V_4 = F_211 ( V_2 , V_34 ) ;
if ( F_15 ( V_4 ) )
goto V_344;
if ( ! V_4 -> V_281 ||
V_343 -> V_345 != V_346 || V_343 -> V_232 != V_347 )
goto V_344;
if ( F_67 ( V_4 , V_34 , sizeof( * V_343 ) ) ) {
V_344:
F_56 ( V_34 ) ;
}
return 0 ;
}
static int F_221 ( struct V_33 * V_34 )
{
struct V_348 * V_343 ;
struct V_2 * V_2 = F_40 ( V_34 -> V_70 ) ;
struct V_1 * V_4 ;
if ( ! F_219 ( V_34 , sizeof( * V_343 ) + sizeof( struct V_126 ) ) )
goto V_344;
V_343 = (struct V_348 * ) F_68 ( V_34 ) ;
if ( V_343 -> type != ( ( V_349 << 4 ) | ( V_350 ) ) ||
( V_343 -> V_13 & V_351 ) ||
( F_222 ( ( void * ) V_343 , sizeof( * V_343 ) ) != 0 &&
F_223 ( F_224 ( V_34 , 0 , V_34 -> V_119 , 0 ) ) ) )
goto V_344;
V_4 = F_211 ( V_2 , V_34 ) ;
if ( F_15 ( V_4 ) )
goto V_344;
if ( F_67 ( V_4 , V_34 , sizeof( * V_343 ) ) ) {
V_344:
F_56 ( V_34 ) ;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_4 , struct V_33 * V_34 ,
struct V_56 * V_57 , struct V_352 * V_353 )
{
struct V_354 V_355 ;
struct V_37 * V_356 ;
struct V_357 * V_358 ;
unsigned long V_189 ;
int V_309 ;
if ( V_57 -> V_215 >= V_188 ) {
V_353 -> V_359 |= V_360 ;
return - V_242 ;
}
if ( F_79 ( V_4 , V_57 -> V_215 ) &&
F_225 ( V_34 , V_361 , V_4 -> V_138 [ V_57 -> V_215 ] . V_70 -> V_110 ) < 0 )
return - V_221 ;
if ( ! ( V_356 = F_226 ( V_34 , V_362 ) ) )
return - V_221 ;
for ( V_309 = V_57 -> V_166 . V_9 . V_187 ; V_309 < V_57 -> V_166 . V_9 . V_152 ; V_309 ++ ) {
if ( F_79 ( V_4 , V_309 ) && V_57 -> V_166 . V_9 . V_186 [ V_309 ] < 255 ) {
if ( ! ( V_358 = F_227 ( V_34 , sizeof( * V_358 ) ) ) ) {
F_228 ( V_34 , V_356 ) ;
return - V_221 ;
}
V_358 -> V_363 = 0 ;
V_358 -> V_364 = V_57 -> V_166 . V_9 . V_186 [ V_309 ] ;
V_358 -> V_365 = V_4 -> V_138 [ V_309 ] . V_70 -> V_110 ;
V_358 -> V_366 = sizeof( * V_358 ) ;
}
}
F_229 ( V_34 , V_356 ) ;
V_189 = F_230 ( V_57 -> V_166 . V_9 . V_189 ) ;
V_189 = F_231 ( V_180 , V_189 ) ? V_180 - V_189 : 0 ;
V_355 . V_367 = V_57 -> V_166 . V_9 . V_222 ;
V_355 . V_368 = V_57 -> V_166 . V_9 . V_301 ;
V_355 . V_369 = V_57 -> V_166 . V_9 . V_302 ;
if ( F_232 ( V_34 , V_370 , sizeof( V_355 ) , & V_355 , V_371 ) ||
F_233 ( V_34 , V_372 , F_234 ( V_189 ) ,
V_371 ) )
return - V_221 ;
V_353 -> V_373 = V_374 ;
return 1 ;
}
int F_235 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_83 , T_6 V_80 ,
struct V_352 * V_353 , T_1 V_176 )
{
struct V_56 * V_185 ;
struct V_1 * V_4 ;
int V_7 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return - V_242 ;
F_140 () ;
V_185 = F_112 ( V_4 , V_83 , V_80 ) ;
if ( ! V_185 && V_34 -> V_70 ) {
int V_258 = F_207 ( V_4 , V_34 -> V_70 ) ;
if ( V_258 >= 0 )
V_185 = F_117 ( V_4 , V_80 , V_258 ) ;
}
if ( ! V_185 ) {
struct V_33 * V_336 ;
struct V_126 * V_79 ;
struct V_69 * V_70 ;
int V_258 = - 1 ;
V_70 = V_34 -> V_70 ;
F_57 ( & V_116 ) ;
if ( V_70 )
V_258 = F_207 ( V_4 , V_70 ) ;
if ( V_258 < 0 ) {
F_59 ( & V_116 ) ;
F_142 () ;
return - V_341 ;
}
V_336 = F_210 ( V_34 , V_219 ) ;
if ( ! V_336 ) {
F_59 ( & V_116 ) ;
F_142 () ;
return - V_61 ;
}
F_99 ( V_336 ) . V_176 = V_176 ;
F_131 ( V_336 , sizeof( struct V_126 ) ) ;
F_72 ( V_336 ) ;
V_79 = F_94 ( V_336 ) ;
V_79 -> V_86 = sizeof( struct V_126 ) >> 2 ;
V_79 -> V_83 = V_83 ;
V_79 -> V_80 = V_80 ;
V_79 -> V_85 = 0 ;
V_7 = F_146 ( V_4 , V_258 , V_336 , V_70 ) ;
F_59 ( & V_116 ) ;
F_142 () ;
return V_7 ;
}
F_57 ( & V_116 ) ;
V_7 = F_125 ( V_4 , V_34 , V_185 , V_353 ) ;
F_59 ( & V_116 ) ;
F_142 () ;
return V_7 ;
}
static int F_236 ( struct V_1 * V_4 , struct V_33 * V_34 ,
T_1 V_176 , T_1 V_375 , struct V_56 * V_57 , int V_286 ,
int V_13 )
{
struct V_169 * V_170 ;
struct V_352 * V_353 ;
int V_7 ;
V_170 = F_237 ( V_34 , V_176 , V_375 , V_286 , sizeof( * V_353 ) , V_13 ) ;
if ( ! V_170 )
return - V_221 ;
V_353 = F_97 ( V_170 ) ;
V_353 -> V_376 = V_377 ;
V_353 -> V_378 = 32 ;
V_353 -> V_379 = 32 ;
V_353 -> V_380 = 0 ;
V_353 -> V_381 = V_4 -> V_3 ;
if ( F_225 ( V_34 , V_382 , V_4 -> V_3 ) )
goto V_383;
V_353 -> V_373 = V_374 ;
V_353 -> V_384 = V_385 ;
if ( V_57 -> V_247 & V_248 )
V_353 -> V_386 = V_387 ;
else
V_353 -> V_386 = V_388 ;
V_353 -> V_359 = 0 ;
if ( F_238 ( V_34 , V_389 , V_57 -> V_59 ) ||
F_238 ( V_34 , V_390 , V_57 -> V_58 ) )
goto V_383;
V_7 = F_125 ( V_4 , V_34 , V_57 , V_353 ) ;
if ( V_7 < 0 && V_7 != - V_242 )
goto V_383;
F_239 ( V_34 , V_170 ) ;
return 0 ;
V_383:
F_240 ( V_34 , V_170 ) ;
return - V_221 ;
}
static T_8 F_241 ( bool V_168 , int V_152 )
{
T_8 V_119 =
F_242 ( sizeof( struct V_352 ) )
+ F_243 ( 4 )
+ F_243 ( 4 )
+ F_243 ( 4 )
;
if ( ! V_168 )
V_119 = V_119
+ F_243 ( 4 )
+ F_243 ( 0 )
+ V_152 * F_244 ( sizeof( struct V_357 ) )
+ F_245 ( sizeof( struct V_354 ) )
;
return V_119 ;
}
static void F_104 ( struct V_1 * V_4 , struct V_56 * V_239 ,
int V_286 )
{
struct V_2 * V_2 = F_91 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_194 ;
V_34 = F_246 ( F_241 ( V_239 -> V_215 >= V_188 , V_4 -> V_152 ) ,
V_219 ) ;
if ( ! V_34 )
goto V_391;
V_7 = F_236 ( V_4 , V_34 , 0 , 0 , V_239 , V_286 , 0 ) ;
if ( V_7 < 0 )
goto V_391;
F_247 ( V_34 , V_2 , 0 , V_392 , NULL , V_219 ) ;
return;
V_391:
F_56 ( V_34 ) ;
if ( V_7 < 0 )
F_248 ( V_2 , V_392 , V_7 ) ;
}
static T_8 F_249 ( T_8 V_393 )
{
T_8 V_119 =
F_242 ( sizeof( struct V_394 ) )
+ F_243 ( 1 )
+ F_243 ( 4 )
+ F_243 ( 4 )
+ F_243 ( 4 )
+ F_243 ( V_393 )
;
return V_119 ;
}
static void F_143 ( struct V_1 * V_4 , struct V_33 * V_222 )
{
struct V_2 * V_2 = F_91 ( & V_4 -> V_2 ) ;
struct V_169 * V_170 ;
struct V_394 * V_395 ;
struct V_227 * V_175 ;
struct V_33 * V_34 ;
struct V_37 * V_396 ;
int V_393 ;
V_393 = V_222 -> V_119 - sizeof( struct V_227 ) ;
V_175 = (struct V_227 * ) F_133 ( V_222 ) ;
V_34 = F_246 ( F_249 ( V_393 ) , V_219 ) ;
if ( ! V_34 )
goto V_391;
V_170 = F_237 ( V_34 , 0 , 0 , V_397 ,
sizeof( struct V_394 ) , 0 ) ;
if ( ! V_170 )
goto V_391;
V_395 = F_97 ( V_170 ) ;
V_395 -> V_398 = V_377 ;
if ( F_250 ( V_34 , V_399 , V_175 -> V_229 ) ||
F_225 ( V_34 , V_400 , V_175 -> V_231 ) ||
F_238 ( V_34 , V_401 ,
V_175 -> V_402 . V_82 ) ||
F_238 ( V_34 , V_403 ,
V_175 -> V_404 . V_82 ) )
goto V_383;
V_396 = F_251 ( V_34 , V_405 , V_393 ) ;
if ( ! V_396 || F_252 ( V_222 , sizeof( struct V_227 ) ,
F_253 ( V_396 ) , V_393 ) )
goto V_383;
F_239 ( V_34 , V_170 ) ;
F_247 ( V_34 , V_2 , 0 , V_406 , NULL , V_219 ) ;
return;
V_383:
F_240 ( V_34 , V_170 ) ;
V_391:
F_56 ( V_34 ) ;
F_248 ( V_2 , V_406 , - V_194 ) ;
}
static int F_254 ( struct V_33 * V_407 , struct V_169 * V_170 ,
struct V_408 * V_409 )
{
struct V_2 * V_2 = F_164 ( V_407 -> V_251 ) ;
struct V_37 * V_38 [ V_410 + 1 ] ;
struct V_33 * V_34 = NULL ;
struct V_56 * V_185 ;
struct V_1 * V_4 ;
struct V_352 * V_353 ;
T_6 V_297 , V_298 ;
T_1 V_411 ;
int V_7 ;
V_7 = F_255 ( V_170 , sizeof( * V_353 ) , V_38 , V_410 ,
V_412 , V_409 ) ;
if ( V_7 < 0 )
goto V_391;
V_353 = F_97 ( V_170 ) ;
V_297 = V_38 [ V_389 ] ? F_256 ( V_38 [ V_389 ] ) : 0 ;
V_298 = V_38 [ V_390 ] ? F_256 ( V_38 [ V_390 ] ) : 0 ;
V_411 = V_38 [ V_382 ] ? F_257 ( V_38 [ V_382 ] ) : 0 ;
V_4 = F_1 ( V_2 , V_411 ? V_411 : V_46 ) ;
if ( ! V_4 ) {
V_7 = - V_242 ;
goto V_413;
}
F_140 () ;
V_185 = F_112 ( V_4 , V_297 , V_298 ) ;
F_142 () ;
if ( ! V_185 ) {
V_7 = - V_242 ;
goto V_413;
}
V_34 = F_246 ( F_241 ( false , V_4 -> V_152 ) , V_60 ) ;
if ( ! V_34 ) {
V_7 = - V_194 ;
goto V_413;
}
V_7 = F_236 ( V_4 , V_34 , F_99 ( V_407 ) . V_176 ,
V_170 -> V_414 , V_185 ,
V_236 , 0 ) ;
if ( V_7 < 0 )
goto V_413;
V_7 = F_98 ( V_34 , V_2 , F_99 ( V_407 ) . V_176 ) ;
V_391:
return V_7 ;
V_413:
F_56 ( V_34 ) ;
goto V_391;
}
static int F_258 ( struct V_33 * V_34 , struct V_415 * V_416 )
{
struct V_2 * V_2 = F_164 ( V_34 -> V_251 ) ;
struct V_1 * V_4 ;
struct V_56 * V_239 ;
unsigned int V_417 = 0 , V_418 ;
unsigned int V_164 = 0 , V_419 ;
V_418 = V_416 -> args [ 0 ] ;
V_419 = V_416 -> args [ 1 ] ;
F_140 () ;
F_2 (mrt, net) {
if ( V_417 < V_418 )
goto V_420;
F_259 (mfc, &mrt->mfc_cache_list, list) {
if ( V_164 < V_419 )
goto V_421;
if ( F_236 ( V_4 , V_34 ,
F_99 ( V_416 -> V_34 ) . V_176 ,
V_416 -> V_170 -> V_414 ,
V_239 , V_236 ,
V_422 ) < 0 )
goto V_423;
V_421:
V_164 ++ ;
}
V_164 = 0 ;
V_419 = 0 ;
F_147 ( & V_179 ) ;
F_148 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_164 < V_419 )
goto V_424;
if ( F_236 ( V_4 , V_34 ,
F_99 ( V_416 -> V_34 ) . V_176 ,
V_416 -> V_170 -> V_414 ,
V_239 , V_236 ,
V_422 ) < 0 ) {
F_150 ( & V_179 ) ;
goto V_423;
}
V_424:
V_164 ++ ;
}
F_150 ( & V_179 ) ;
V_164 = 0 ;
V_419 = 0 ;
V_420:
V_417 ++ ;
}
V_423:
F_142 () ;
V_416 -> args [ 1 ] = V_164 ;
V_416 -> args [ 0 ] = V_417 ;
return V_34 -> V_119 ;
}
static bool F_260 ( unsigned char V_386 )
{
switch ( V_386 ) {
case V_387 :
case V_388 :
return true ;
}
return false ;
}
static int F_261 ( const struct V_37 * V_396 , struct V_238 * V_425 )
{
struct V_357 * V_426 = F_253 ( V_396 ) ;
int V_427 = F_262 ( V_396 ) , V_147 = 0 ;
while ( F_263 ( V_426 , V_427 ) ) {
V_425 -> V_246 [ V_147 ] = V_426 -> V_364 ;
if ( ++ V_147 == V_188 )
break;
V_426 = F_264 ( V_426 , & V_427 ) ;
}
return V_427 > 0 ? - V_28 : V_147 ;
}
static int F_265 ( struct V_2 * V_2 , struct V_169 * V_170 ,
struct V_238 * V_425 , int * V_191 ,
struct V_1 * * V_428 ,
struct V_408 * V_409 )
{
struct V_69 * V_70 = NULL ;
T_1 V_429 = V_46 ;
struct V_1 * V_4 ;
struct V_37 * V_430 ;
struct V_352 * V_353 ;
int V_228 , V_431 ;
V_228 = F_266 ( V_170 , sizeof( * V_353 ) , V_410 , V_432 ,
V_409 ) ;
if ( V_228 < 0 )
goto V_182;
V_353 = F_97 ( V_170 ) ;
V_228 = - V_28 ;
if ( V_353 -> V_376 != V_377 || V_353 -> V_378 != 32 ||
V_353 -> V_373 != V_374 ||
V_353 -> V_384 != V_385 ||
! F_260 ( V_353 -> V_386 ) )
goto V_182;
memset ( V_425 , 0 , sizeof( * V_425 ) ) ;
V_425 -> V_244 = - 1 ;
V_228 = 0 ;
F_267 (attr, nlh, sizeof(struct rtmsg), rem) {
switch ( F_268 ( V_430 ) ) {
case V_389 :
V_425 -> V_240 . V_82 = F_269 ( V_430 ) ;
break;
case V_390 :
V_425 -> V_241 . V_82 = F_269 ( V_430 ) ;
break;
case V_361 :
V_70 = F_270 ( V_2 , F_257 ( V_430 ) ) ;
if ( ! V_70 ) {
V_228 = - V_341 ;
goto V_182;
}
break;
case V_362 :
if ( F_261 ( V_430 , V_425 ) < 0 ) {
V_228 = - V_28 ;
goto V_182;
}
break;
case V_433 :
V_228 = 1 ;
break;
case V_382 :
V_429 = F_257 ( V_430 ) ;
break;
}
}
V_4 = F_1 ( V_2 , V_429 ) ;
if ( ! V_4 ) {
V_228 = - V_242 ;
goto V_182;
}
* V_428 = V_4 ;
* V_191 = V_353 -> V_386 == V_388 ? 1 : 0 ;
if ( V_70 )
V_425 -> V_244 = F_207 ( V_4 , V_70 ) ;
V_182:
return V_228 ;
}
static int F_271 ( struct V_33 * V_34 , struct V_169 * V_170 ,
struct V_408 * V_409 )
{
struct V_2 * V_2 = F_164 ( V_34 -> V_251 ) ;
int V_228 , V_191 , V_216 ;
struct V_1 * V_434 ;
struct V_238 V_425 ;
V_191 = 0 ;
V_434 = NULL ;
V_228 = F_265 ( V_2 , V_170 , & V_425 , & V_191 , & V_434 , V_409 ) ;
if ( V_228 < 0 )
return V_228 ;
V_216 = V_228 ? V_425 . V_244 : - 1 ;
if ( V_170 -> V_171 == V_236 )
return F_157 ( V_2 , V_434 , & V_425 , V_191 , V_216 ) ;
else
return F_154 ( V_434 , & V_425 , V_216 ) ;
}
static bool F_272 ( struct V_1 * V_4 , struct V_33 * V_34 )
{
T_1 V_435 = F_149 ( & V_4 -> V_165 ) ;
if ( F_225 ( V_34 , V_436 , V_4 -> V_3 ) ||
F_225 ( V_34 , V_437 , V_435 ) ||
F_273 ( V_34 , V_438 ,
V_4 -> V_68 ) ||
F_250 ( V_34 , V_439 ,
V_4 -> V_278 ) ||
F_250 ( V_34 , V_440 , V_4 -> V_281 ) )
return false ;
return true ;
}
static bool F_274 ( struct V_1 * V_4 , T_1 V_441 , struct V_33 * V_34 )
{
struct V_37 * V_442 ;
struct V_151 * V_258 ;
if ( ! F_79 ( V_4 , V_441 ) )
return true ;
V_258 = & V_4 -> V_138 [ V_441 ] ;
V_442 = F_226 ( V_34 , V_443 ) ;
if ( ! V_442 )
return false ;
if ( F_225 ( V_34 , V_444 , V_258 -> V_70 -> V_110 ) ||
F_225 ( V_34 , V_445 , V_441 ) ||
F_275 ( V_34 , V_446 , V_258 -> V_13 ) ||
F_233 ( V_34 , V_447 , V_258 -> V_204 ,
V_448 ) ||
F_233 ( V_34 , V_449 , V_258 -> V_205 ,
V_448 ) ||
F_233 ( V_34 , V_450 , V_258 -> V_206 ,
V_448 ) ||
F_233 ( V_34 , V_451 , V_258 -> V_207 ,
V_448 ) ||
F_276 ( V_34 , V_452 , V_258 -> V_199 ) ||
F_276 ( V_34 , V_453 , V_258 -> V_200 ) ) {
F_228 ( V_34 , V_442 ) ;
return false ;
}
F_229 ( V_34 , V_442 ) ;
return true ;
}
static int F_277 ( struct V_33 * V_34 , struct V_415 * V_416 )
{
struct V_2 * V_2 = F_164 ( V_34 -> V_251 ) ;
struct V_169 * V_170 = NULL ;
unsigned int V_417 = 0 , V_418 ;
unsigned int V_164 = 0 , V_419 ;
struct V_1 * V_4 ;
V_418 = V_416 -> args [ 0 ] ;
V_419 = V_416 -> args [ 1 ] ;
F_2 (mrt, net) {
struct V_37 * V_454 , * V_455 ;
struct V_456 * V_457 ;
T_1 V_250 ;
if ( V_417 < V_418 )
goto V_458;
V_170 = F_237 ( V_34 , F_99 ( V_416 -> V_34 ) . V_176 ,
V_416 -> V_170 -> V_414 , V_459 ,
sizeof( * V_457 ) , V_422 ) ;
if ( ! V_170 )
break;
V_457 = F_97 ( V_170 ) ;
memset ( V_457 , 0 , sizeof( * V_457 ) ) ;
V_457 -> V_460 = V_377 ;
V_455 = F_226 ( V_34 , V_461 ) ;
if ( ! V_455 ) {
F_240 ( V_34 , V_170 ) ;
goto V_182;
}
if ( ! F_272 ( V_4 , V_34 ) ) {
F_240 ( V_34 , V_170 ) ;
goto V_182;
}
V_454 = F_226 ( V_34 , V_462 ) ;
if ( ! V_454 ) {
F_229 ( V_34 , V_455 ) ;
F_239 ( V_34 , V_170 ) ;
goto V_182;
}
for ( V_250 = 0 ; V_250 < V_4 -> V_152 ; V_250 ++ ) {
if ( V_164 < V_419 )
goto V_463;
if ( ! F_274 ( V_4 , V_250 , V_34 ) ) {
F_229 ( V_34 , V_454 ) ;
F_229 ( V_34 , V_455 ) ;
F_239 ( V_34 , V_170 ) ;
goto V_182;
}
V_463:
V_164 ++ ;
}
V_419 = 0 ;
V_164 = 0 ;
F_229 ( V_34 , V_454 ) ;
F_229 ( V_34 , V_455 ) ;
F_239 ( V_34 , V_170 ) ;
V_458:
V_417 ++ ;
}
V_182:
V_416 -> args [ 1 ] = V_164 ;
V_416 -> args [ 0 ] = V_417 ;
return V_34 -> V_119 ;
}
static struct V_151 * F_278 ( struct V_2 * V_2 ,
struct V_464 * V_465 ,
T_9 V_466 )
{
struct V_1 * V_4 = V_465 -> V_4 ;
for ( V_465 -> V_309 = 0 ; V_465 -> V_309 < V_4 -> V_152 ; ++ V_465 -> V_309 ) {
if ( ! F_79 ( V_4 , V_465 -> V_309 ) )
continue;
if ( V_466 -- == 0 )
return & V_4 -> V_138 [ V_465 -> V_309 ] ;
}
return NULL ;
}
static void * F_279 ( struct V_467 * V_375 , T_9 * V_466 )
__acquires( V_116 )
{
struct V_464 * V_465 = V_375 -> V_468 ;
struct V_2 * V_2 = F_280 ( V_375 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_28 ( - V_242 ) ;
V_465 -> V_4 = V_4 ;
F_57 ( & V_116 ) ;
return * V_466 ? F_278 ( V_2 , V_375 -> V_468 , * V_466 - 1 )
: V_469 ;
}
static void * F_281 ( struct V_467 * V_375 , void * V_72 , T_9 * V_466 )
{
struct V_464 * V_465 = V_375 -> V_468 ;
struct V_2 * V_2 = F_280 ( V_375 ) ;
struct V_1 * V_4 = V_465 -> V_4 ;
++ * V_466 ;
if ( V_72 == V_469 )
return F_278 ( V_2 , V_465 , 0 ) ;
while ( ++ V_465 -> V_309 < V_4 -> V_152 ) {
if ( ! F_79 ( V_4 , V_465 -> V_309 ) )
continue;
return & V_4 -> V_138 [ V_465 -> V_309 ] ;
}
return NULL ;
}
static void F_282 ( struct V_467 * V_375 , void * V_72 )
__releases( V_116 )
{
F_59 ( & V_116 ) ;
}
static int F_283 ( struct V_467 * V_375 , void * V_72 )
{
struct V_464 * V_465 = V_375 -> V_468 ;
struct V_1 * V_4 = V_465 -> V_4 ;
if ( V_72 == V_469 ) {
F_284 ( V_375 ,
L_7 ) ;
} else {
const struct V_151 * V_258 = V_72 ;
const char * V_89 = V_258 -> V_70 ? V_258 -> V_70 -> V_89 : L_8 ;
F_285 ( V_375 ,
L_9 ,
V_258 - V_4 -> V_138 ,
V_89 , V_258 -> V_204 , V_258 -> V_206 ,
V_258 -> V_205 , V_258 -> V_207 ,
V_258 -> V_13 , V_258 -> V_199 , V_258 -> V_200 ) ;
}
return 0 ;
}
static int F_286 ( struct V_470 * V_470 , struct V_471 * V_471 )
{
return F_287 ( V_470 , V_471 , & V_472 ,
sizeof( struct V_464 ) ) ;
}
static struct V_56 * F_288 ( struct V_2 * V_2 ,
struct V_473 * V_474 , T_9 V_466 )
{
struct V_1 * V_4 = V_474 -> V_4 ;
struct V_56 * V_239 ;
F_140 () ;
V_474 -> V_185 = & V_4 -> V_64 ;
F_259 (mfc, &mrt->mfc_cache_list, list)
if ( V_466 -- == 0 )
return V_239 ;
F_142 () ;
F_147 ( & V_179 ) ;
V_474 -> V_185 = & V_4 -> V_65 ;
F_148 (mfc, it->cache, list)
if ( V_466 -- == 0 )
return V_239 ;
F_150 ( & V_179 ) ;
V_474 -> V_185 = NULL ;
return NULL ;
}
static void * F_289 ( struct V_467 * V_375 , T_9 * V_466 )
{
struct V_473 * V_474 = V_375 -> V_468 ;
struct V_2 * V_2 = F_280 ( V_375 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_28 ( - V_242 ) ;
V_474 -> V_4 = V_4 ;
V_474 -> V_185 = NULL ;
return * V_466 ? F_288 ( V_2 , V_375 -> V_468 , * V_466 - 1 )
: V_469 ;
}
static void * F_290 ( struct V_467 * V_375 , void * V_72 , T_9 * V_466 )
{
struct V_473 * V_474 = V_375 -> V_468 ;
struct V_2 * V_2 = F_280 ( V_375 ) ;
struct V_1 * V_4 = V_474 -> V_4 ;
struct V_56 * V_239 = V_72 ;
++ * V_466 ;
if ( V_72 == V_469 )
return F_288 ( V_2 , V_375 -> V_468 , 0 ) ;
if ( V_239 -> V_50 . V_49 != V_474 -> V_185 )
return F_291 ( V_239 -> V_50 . V_49 , struct V_56 , V_50 ) ;
if ( V_474 -> V_185 == & V_4 -> V_65 )
goto V_475;
F_142 () ;
V_474 -> V_185 = & V_4 -> V_65 ;
F_147 ( & V_179 ) ;
if ( ! F_102 ( V_474 -> V_185 ) )
return F_292 ( V_474 -> V_185 , struct V_56 , V_50 ) ;
V_475:
F_150 ( & V_179 ) ;
V_474 -> V_185 = NULL ;
return NULL ;
}
static void F_293 ( struct V_467 * V_375 , void * V_72 )
{
struct V_473 * V_474 = V_375 -> V_468 ;
struct V_1 * V_4 = V_474 -> V_4 ;
if ( V_474 -> V_185 == & V_4 -> V_65 )
F_150 ( & V_179 ) ;
else if ( V_474 -> V_185 == & V_4 -> V_64 )
F_142 () ;
}
static int F_294 ( struct V_467 * V_375 , void * V_72 )
{
int V_476 ;
if ( V_72 == V_469 ) {
F_284 ( V_375 ,
L_10 ) ;
} else {
const struct V_56 * V_239 = V_72 ;
const struct V_473 * V_474 = V_375 -> V_468 ;
const struct V_1 * V_4 = V_474 -> V_4 ;
F_285 ( V_375 , L_11 ,
( V_93 T_1 ) V_239 -> V_58 ,
( V_93 T_1 ) V_239 -> V_59 ,
V_239 -> V_215 ) ;
if ( V_474 -> V_185 != & V_4 -> V_65 ) {
F_285 ( V_375 , L_12 ,
V_239 -> V_166 . V_9 . V_222 ,
V_239 -> V_166 . V_9 . V_301 ,
V_239 -> V_166 . V_9 . V_302 ) ;
for ( V_476 = V_239 -> V_166 . V_9 . V_187 ;
V_476 < V_239 -> V_166 . V_9 . V_152 ; V_476 ++ ) {
if ( F_79 ( V_4 , V_476 ) &&
V_239 -> V_166 . V_9 . V_186 [ V_476 ] < 255 )
F_285 ( V_375 ,
L_13 ,
V_476 , V_239 -> V_166 . V_9 . V_186 [ V_476 ] ) ;
}
} else {
F_285 ( V_375 , L_12 , 0ul , 0ul , 0ul ) ;
}
F_295 ( V_375 , '\n' ) ;
}
return 0 ;
}
static int F_296 ( struct V_470 * V_470 , struct V_471 * V_471 )
{
return F_287 ( V_470 , V_471 , & V_477 ,
sizeof( struct V_473 ) ) ;
}
static int T_2 F_297 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_13 ( V_2 ) ;
if ( V_7 < 0 )
goto V_478;
#ifdef F_298
V_7 = - V_61 ;
if ( ! F_299 ( L_14 , 0 , V_2 -> V_479 , & V_480 ) )
goto V_481;
if ( ! F_299 ( L_15 , 0 , V_2 -> V_479 , & V_482 ) )
goto V_483;
#endif
return 0 ;
#ifdef F_298
V_483:
F_300 ( L_14 , V_2 -> V_479 ) ;
V_481:
F_22 ( V_2 ) ;
#endif
V_478:
return V_7 ;
}
static void T_3 F_301 ( struct V_2 * V_2 )
{
#ifdef F_298
F_300 ( L_15 , V_2 -> V_479 ) ;
F_300 ( L_14 , V_2 -> V_479 ) ;
#endif
F_22 ( V_2 ) ;
}
int T_10 F_302 ( void )
{
int V_7 ;
V_162 = F_303 ( L_16 ,
sizeof( struct V_56 ) ,
0 , V_484 | V_485 ,
NULL ) ;
V_7 = F_304 ( & V_486 ) ;
if ( V_7 )
goto V_487;
V_7 = F_305 ( & V_488 ) ;
if ( V_7 )
goto V_489;
#ifdef F_306
if ( F_307 ( & V_490 , V_491 ) < 0 ) {
F_159 ( L_17 , V_492 ) ;
V_7 = - V_31 ;
goto V_493;
}
#endif
F_308 ( V_377 , V_494 ,
F_254 , F_258 , 0 ) ;
F_308 ( V_377 , V_236 ,
F_271 , NULL , 0 ) ;
F_308 ( V_377 , V_184 ,
F_271 , NULL , 0 ) ;
F_308 ( V_377 , V_495 ,
NULL , F_277 , 0 ) ;
return 0 ;
#ifdef F_306
V_493:
F_309 ( & V_488 ) ;
#endif
V_489:
F_310 ( & V_486 ) ;
V_487:
F_311 ( V_162 ) ;
return V_7 ;
}
