static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
if ( V_2 -> V_5 -> V_6 != 4 || V_3 != 0 )
return V_4 ;
V_7:
if ( ! F_2 ( & V_8 , V_9 ) )
return - V_10 ;
F_3 ( & V_11 ) ;
V_4 = F_4 ( & V_8 , V_2 , & V_2 -> V_12 ) ;
F_5 ( & V_11 ) ;
if ( V_4 == - V_13 )
goto V_7;
return V_4 ;
}
static struct V_1 * F_6 ( const struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_18 = - V_10 ;
if ( ( V_2 = F_7 ( sizeof( * V_2 ) , V_9 ) ) == NULL )
goto V_19;
V_2 -> V_5 = V_15 -> V_5 ;
F_8 ( & V_2 -> V_20 , 1 ) ;
V_2 -> V_21 = V_22 ;
memcpy ( & V_2 -> V_23 , V_15 -> V_24 , V_15 -> V_25 ) ;
V_2 -> V_26 = V_15 -> V_25 ;
if ( V_15 -> V_27 ) {
V_18 = - V_10 ;
V_2 -> V_28 = F_9 ( V_15 -> V_27 , V_9 ) ;
if ( ! V_2 -> V_28 )
goto V_29;
}
F_10 ( & V_2 -> V_30 ) ;
V_2 -> V_31 = F_11 ( - V_32 ) ;
V_2 -> V_33 = V_15 -> V_34 ;
#ifdef F_12
V_18 = F_1 ( V_2 , V_15 -> V_3 ) ;
if ( V_18 )
goto V_29;
F_13 ( & V_2 -> V_35 ) ;
F_14 ( & V_2 -> V_36 , V_37 ) ;
F_15 ( & V_2 -> V_38 , L_1 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = 1 << V_42 ;
V_2 -> V_43 = V_15 -> V_3 ;
V_2 -> V_44 = V_45 [ V_15 -> V_3 ] ;
#endif
V_17 = F_16 () ;
if ( ! F_17 ( V_17 ) )
V_2 -> V_46 = V_17 ;
F_18 ( V_2 ) ;
return V_2 ;
V_29:
F_19 ( V_2 ) ;
V_19:
return F_11 ( V_18 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( F_21 ( V_2 ) )
F_22 ( V_2 -> V_47 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
}
static void F_23 ( struct V_1 * V_2 )
{
if ( F_24 ( V_48 , & V_2 -> V_49 ) )
F_25 ( V_2 -> V_44 -> V_50 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( F_24 ( V_51 , & V_2 -> V_49 ) )
F_27 ( V_2 ) ;
F_20 ( V_2 ) ;
F_23 ( V_2 ) ;
if ( F_24 ( V_52 , & V_2 -> V_49 ) )
F_28 ( V_2 ) ;
F_29 ( & V_2 -> V_38 ) ;
}
void F_30 ( void )
{
F_31 ( & V_8 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
F_33 ( & V_8 , V_2 -> V_12 ) ;
}
static void F_34 ( struct V_53 * V_54 )
{
F_15 ( & V_54 -> V_55 , L_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
}
void F_30 ( void )
{
}
static void F_32 ( struct V_1 * V_2 )
{
}
static void F_34 ( struct V_53 * V_54 )
{
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( L_3 , V_2 -> V_5 -> V_6 ) ;
F_26 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( ! F_17 ( V_2 -> V_31 ) )
F_38 ( V_2 -> V_31 ) ;
if ( V_2 -> V_46 != NULL )
F_39 ( V_2 -> V_46 ) ;
F_40 ( V_2 ) ;
F_19 ( V_2 -> V_28 ) ;
F_19 ( V_2 -> V_56 ) ;
F_19 ( V_2 ) ;
F_36 ( L_4 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_36 ( L_5 , F_42 ( & V_2 -> V_20 ) ) ;
if ( F_43 ( & V_2 -> V_20 , & V_11 ) ) {
F_44 ( & V_2 -> V_57 ) ;
F_32 ( V_2 ) ;
F_5 ( & V_11 ) ;
F_45 ( ! F_46 ( & V_2 -> V_30 ) ) ;
F_35 ( V_2 ) ;
}
}
static int F_47 ( const struct V_58 * V_59 ,
const struct V_58 * V_60 )
{
const struct V_61 * V_62 = ( const struct V_61 * ) V_59 ;
const struct V_61 * V_63 = ( const struct V_61 * ) V_60 ;
if ( F_48 ( & V_62 -> V_64 ) == V_65 &&
V_62 -> V_66 != V_63 -> V_66 )
return 0 ;
return F_49 ( & V_62 -> V_64 , & V_63 -> V_64 ) ;
}
static int F_47 ( const struct V_58 * V_59 ,
const struct V_58 * V_60 )
{
return 0 ;
}
static int F_50 ( const struct V_58 * V_59 ,
const struct V_58 * V_60 )
{
const struct V_67 * V_62 = ( const struct V_67 * ) V_59 ;
const struct V_67 * V_63 = ( const struct V_67 * ) V_60 ;
return V_62 -> V_68 . V_69 == V_63 -> V_68 . V_69 ;
}
static int F_51 ( const struct V_58 * V_59 ,
const struct V_58 * V_60 )
{
const struct V_61 * V_62 = ( const struct V_61 * ) V_59 ;
const struct V_61 * V_63 = ( const struct V_61 * ) V_60 ;
return F_47 ( V_59 , V_60 ) &&
( V_62 -> V_70 == V_63 -> V_70 ) ;
}
static int F_52 ( const struct V_58 * V_59 ,
const struct V_58 * V_60 )
{
const struct V_67 * V_62 = ( const struct V_67 * ) V_59 ;
const struct V_67 * V_63 = ( const struct V_67 * ) V_60 ;
return F_50 ( V_59 , V_60 ) &&
( V_62 -> V_71 == V_63 -> V_71 ) ;
}
static int F_53 ( const struct V_58 * V_59 ,
const struct V_58 * V_60 )
{
if ( V_59 -> V_72 != V_60 -> V_72 )
return 0 ;
switch ( V_59 -> V_72 ) {
case V_73 :
return F_50 ( V_59 , V_60 ) ;
case V_74 :
return F_47 ( V_59 , V_60 ) ;
}
return 0 ;
}
static int F_54 ( const struct V_58 * V_59 ,
const struct V_58 * V_60 )
{
if ( V_59 -> V_72 != V_60 -> V_72 )
return 0 ;
switch ( V_59 -> V_72 ) {
case V_73 :
return F_52 ( V_59 , V_60 ) ;
case V_74 :
return F_51 ( V_59 , V_60 ) ;
}
return 0 ;
}
bool
F_55 ( const struct V_58 * V_24 , struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_58 * V_75 = (struct V_58 * ) & V_2 -> V_23 ;
if ( ! ( V_2 -> V_21 == V_76 ||
V_2 -> V_21 == V_77 ) )
return false ;
if ( V_2 -> V_5 -> V_6 != 4 ||
V_2 -> V_43 != V_3 )
return false ;
if ( ! F_53 ( V_24 , V_75 ) )
return false ;
return true ;
}
static struct V_1 * F_56 ( const struct V_14 * V_78 )
{
struct V_1 * V_2 ;
const struct V_58 * V_79 = V_78 -> V_24 ;
F_57 (clp, &nfs_client_list, cl_share_link) {
const struct V_58 * V_75 = (struct V_58 * ) & V_2 -> V_23 ;
if ( V_2 -> V_21 < 0 )
continue;
if ( V_2 -> V_5 != V_78 -> V_5 )
continue;
if ( V_2 -> V_33 != V_78 -> V_34 )
continue;
if ( V_2 -> V_43 != V_78 -> V_3 )
continue;
if ( ! F_54 ( V_79 , V_75 ) )
continue;
F_58 ( & V_2 -> V_20 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_59 ( const struct V_14 * V_15 ,
const struct V_80 * V_81 ,
const char * V_82 ,
T_2 V_83 ,
int V_84 )
{
struct V_1 * V_2 , * V_85 = NULL ;
int error ;
F_36 ( L_6 ,
V_15 -> V_27 ? : L_7 , V_15 -> V_5 -> V_6 ) ;
do {
F_3 ( & V_11 ) ;
V_2 = F_56 ( V_15 ) ;
if ( V_2 )
goto V_86;
if ( V_85 )
goto V_87;
F_5 ( & V_11 ) ;
V_85 = F_6 ( V_15 ) ;
} while ( ! F_17 ( V_85 ) );
F_36 ( L_8 , F_60 ( V_85 ) ) ;
return V_85 ;
V_87:
V_2 = V_85 ;
F_61 ( & V_2 -> V_57 , & V_88 ) ;
F_5 ( & V_11 ) ;
error = V_15 -> V_5 -> V_89 ( V_2 , V_81 , V_82 ,
V_83 , V_84 ) ;
if ( error < 0 ) {
F_41 ( V_2 ) ;
return F_11 ( error ) ;
}
F_36 ( L_9 , V_2 ) ;
return V_2 ;
V_86:
F_5 ( & V_11 ) ;
if ( V_85 )
F_35 ( V_85 ) ;
error = F_62 ( V_90 ,
V_2 -> V_21 < V_22 ) ;
if ( error < 0 ) {
F_41 ( V_2 ) ;
return F_11 ( - V_91 ) ;
}
if ( V_2 -> V_21 < V_76 ) {
error = V_2 -> V_21 ;
F_41 ( V_2 ) ;
return F_11 ( error ) ;
}
F_45 ( V_2 -> V_21 != V_76 ) ;
F_36 ( L_10 , V_2 ) ;
return V_2 ;
}
void F_63 ( struct V_1 * V_2 , int V_92 )
{
V_2 -> V_21 = V_92 ;
F_64 ( & V_90 ) ;
}
int F_65 ( struct V_1 * V_2 )
{
if ( ! F_21 ( V_2 ) )
return 0 ;
if ( V_2 -> V_21 < V_76 )
return - V_93 ;
return 0 ;
}
static void F_66 ( struct V_80 * V_94 , int V_34 ,
unsigned int V_95 , unsigned int V_96 )
{
V_94 -> V_97 = V_95 * V_98 / 10 ;
V_94 -> V_99 = V_96 ;
switch ( V_34 ) {
case V_100 :
case V_101 :
if ( V_94 -> V_99 == 0 )
V_94 -> V_99 = V_102 ;
if ( V_94 -> V_97 == 0 )
V_94 -> V_97 = V_103 * V_98 / 10 ;
if ( V_94 -> V_97 > V_104 )
V_94 -> V_97 = V_104 ;
V_94 -> V_105 = V_94 -> V_97 ;
V_94 -> V_106 = V_94 -> V_97 + ( V_94 -> V_105 * V_94 -> V_99 ) ;
if ( V_94 -> V_106 > V_104 )
V_94 -> V_106 = V_104 ;
if ( V_94 -> V_106 < V_94 -> V_97 )
V_94 -> V_106 = V_94 -> V_97 ;
V_94 -> V_107 = 0 ;
break;
case V_108 :
if ( V_94 -> V_99 == 0 )
V_94 -> V_99 = V_109 ;
if ( ! V_94 -> V_97 )
V_94 -> V_97 = V_110 * V_98 / 10 ;
if ( V_94 -> V_97 > V_111 )
V_94 -> V_97 = V_111 ;
V_94 -> V_106 = V_111 ;
V_94 -> V_107 = 1 ;
break;
default:
F_67 () ;
}
}
static int F_68 ( struct V_1 * V_2 ,
const struct V_80 * V_81 ,
T_2 V_112 ,
int V_113 , int V_84 )
{
struct V_114 * V_115 = NULL ;
struct V_116 args = {
. V_117 = & V_118 ,
. V_119 = V_2 -> V_33 ,
. V_120 = (struct V_58 * ) & V_2 -> V_23 ,
. V_121 = V_2 -> V_26 ,
. V_122 = V_81 ,
. V_123 = V_2 -> V_28 ,
. V_124 = & V_125 ,
. V_6 = V_2 -> V_5 -> V_6 ,
. V_126 = V_112 ,
} ;
if ( V_113 )
args . V_127 |= V_128 ;
if ( V_84 )
args . V_127 |= V_129 ;
if ( ! F_17 ( V_2 -> V_31 ) )
return 0 ;
V_115 = F_69 ( & args ) ;
if ( F_17 ( V_115 ) ) {
F_36 ( L_11 ,
V_130 , F_60 ( V_115 ) ) ;
return F_60 ( V_115 ) ;
}
V_2 -> V_31 = V_115 ;
return 0 ;
}
static void F_70 ( struct V_53 * V_54 )
{
if ( ! ( V_54 -> V_127 & V_131 ) ||
! ( V_54 -> V_127 & V_132 ) )
F_71 ( V_54 -> V_133 ) ;
}
static int F_72 ( struct V_53 * V_54 )
{
struct V_133 * V_134 ;
struct V_1 * V_2 = V_54 -> V_1 ;
struct V_135 V_136 = {
. V_27 = V_2 -> V_28 ,
. V_120 = (struct V_58 * ) & V_2 -> V_23 ,
. V_25 = V_2 -> V_26 ,
. V_137 = V_2 -> V_5 -> V_6 ,
. V_84 = V_54 -> V_127 & V_138 ?
1 : 0 ,
} ;
if ( V_136 . V_137 > 3 )
return 0 ;
if ( ( V_54 -> V_127 & V_131 ) &&
( V_54 -> V_127 & V_132 ) )
return 0 ;
switch ( V_2 -> V_33 ) {
default:
V_136 . V_119 = V_139 ;
break;
case V_108 :
V_136 . V_119 = V_140 ;
}
V_134 = F_73 ( & V_136 ) ;
if ( F_17 ( V_134 ) )
return F_60 ( V_134 ) ;
V_54 -> V_133 = V_134 ;
V_54 -> V_141 = F_70 ;
return 0 ;
}
static void F_74 ( struct V_53 * V_54 )
{
if ( V_54 -> V_1 -> V_5 -> V_6 != 3 )
goto V_142;
if ( V_54 -> V_127 & V_143 )
goto V_142;
V_54 -> V_144 = F_75 ( V_54 -> V_145 , & V_146 , 3 ) ;
if ( F_17 ( V_54 -> V_144 ) )
goto V_142;
V_54 -> V_147 |= V_148 ;
return;
V_142:
V_54 -> V_147 &= ~ V_148 ;
}
static inline void F_74 ( struct V_53 * V_54 )
{
V_54 -> V_127 &= ~ V_143 ;
V_54 -> V_147 &= ~ V_148 ;
}
static int F_76 ( struct V_53 * V_54 ,
const struct V_80 * V_95 ,
T_2 V_149 )
{
struct V_1 * V_2 = V_54 -> V_1 ;
V_54 -> V_145 = F_77 ( V_2 -> V_31 ) ;
if ( F_17 ( V_54 -> V_145 ) ) {
F_36 ( L_12 , V_130 ) ;
return F_60 ( V_54 -> V_145 ) ;
}
memcpy ( & V_54 -> V_145 -> V_150 ,
V_95 ,
sizeof( V_54 -> V_145 -> V_150 ) ) ;
V_54 -> V_145 -> V_151 = & V_54 -> V_145 -> V_150 ;
if ( V_149 != V_2 -> V_31 -> V_152 -> V_153 ) {
struct V_154 * V_155 ;
V_155 = F_78 ( V_149 , V_54 -> V_145 ) ;
if ( F_17 ( V_155 ) ) {
F_36 ( L_13 , V_130 ) ;
return F_60 ( V_155 ) ;
}
}
V_54 -> V_145 -> V_156 = 0 ;
if ( V_54 -> V_127 & V_157 )
V_54 -> V_145 -> V_156 = 1 ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 , const struct V_80 * V_81 ,
const char * V_82 , T_2 V_83 ,
int V_84 )
{
int error ;
if ( V_2 -> V_21 == V_76 ) {
F_36 ( L_14 , V_2 ) ;
return 0 ;
}
error = F_68 ( V_2 , V_81 , V_158 ,
0 , V_84 ) ;
if ( error < 0 )
goto error;
F_63 ( V_2 , V_76 ) ;
return 0 ;
error:
F_63 ( V_2 , error ) ;
F_36 ( L_15 , error ) ;
return error ;
}
static int F_80 ( struct V_53 * V_54 ,
const struct V_159 * V_78 )
{
struct V_14 V_15 = {
. V_27 = V_78 -> V_53 . V_27 ,
. V_24 = ( const struct V_58 * ) & V_78 -> V_53 . V_120 ,
. V_25 = V_78 -> V_53 . V_25 ,
. V_5 = & V_160 ,
. V_34 = V_78 -> V_53 . V_119 ,
} ;
struct V_80 V_81 ;
struct V_1 * V_2 ;
int error ;
F_36 ( L_16 ) ;
#ifdef F_81
if ( V_78 -> V_6 == 3 )
V_15 . V_5 = & V_161 ;
#endif
F_66 ( & V_81 , V_78 -> V_53 . V_119 ,
V_78 -> V_95 , V_78 -> V_96 ) ;
V_2 = F_59 ( & V_15 , & V_81 , NULL , V_158 ,
V_78 -> V_127 & V_138 ) ;
if ( F_17 ( V_2 ) ) {
F_36 ( L_17 , F_60 ( V_2 ) ) ;
return F_60 ( V_2 ) ;
}
V_54 -> V_1 = V_2 ;
V_54 -> V_127 = V_78 -> V_127 ;
V_54 -> V_162 = V_78 -> V_162 ;
V_54 -> V_147 |= V_163 | V_164 | V_165 |
V_166 | V_167 | V_168 | V_169 |
V_170 | V_171 | V_172 ;
if ( V_78 -> V_173 )
V_54 -> V_173 = F_82 ( V_78 -> V_173 , NULL ) ;
if ( V_78 -> V_174 )
V_54 -> V_174 = F_82 ( V_78 -> V_174 , NULL ) ;
V_54 -> V_175 = V_78 -> V_175 * V_98 ;
V_54 -> V_176 = V_78 -> V_176 * V_98 ;
V_54 -> V_177 = V_78 -> V_177 * V_98 ;
V_54 -> V_178 = V_78 -> V_178 * V_98 ;
error = F_72 ( V_54 ) ;
if ( error < 0 )
goto error;
V_54 -> V_179 = V_78 -> V_53 . V_179 ;
error = F_76 ( V_54 , & V_81 , V_78 -> V_180 [ 0 ] ) ;
if ( error < 0 )
goto error;
if ( V_78 -> V_181 . V_25 ) {
memcpy ( & V_54 -> V_182 , & V_78 -> V_181 . V_120 ,
V_78 -> V_181 . V_25 ) ;
V_54 -> V_183 = V_78 -> V_181 . V_25 ;
}
V_54 -> V_184 = V_78 -> V_181 . V_6 ;
V_54 -> V_185 = V_78 -> V_181 . V_179 ;
V_54 -> V_186 = V_78 -> V_181 . V_119 ;
V_54 -> V_187 = V_78 -> V_188 ;
F_74 ( V_54 ) ;
F_36 ( L_18 , V_2 ) ;
return 0 ;
error:
V_54 -> V_1 = NULL ;
F_41 ( V_2 ) ;
F_36 ( L_19 , error ) ;
return error ;
}
static void F_83 ( struct V_53 * V_54 ,
struct V_189 * V_190 ,
struct V_191 * V_192 )
{
unsigned long V_193 ;
if ( V_54 -> V_173 == 0 )
V_54 -> V_173 = F_82 ( V_192 -> V_194 , NULL ) ;
if ( V_54 -> V_174 == 0 )
V_54 -> V_174 = F_82 ( V_192 -> V_195 , NULL ) ;
if ( V_192 -> V_196 >= 512 && V_54 -> V_173 > V_192 -> V_196 )
V_54 -> V_173 = F_82 ( V_192 -> V_196 , NULL ) ;
if ( V_192 -> V_197 >= 512 && V_54 -> V_174 > V_192 -> V_197 )
V_54 -> V_174 = F_82 ( V_192 -> V_197 , NULL ) ;
V_193 = F_82 ( F_84 ( V_54 -> V_145 ) , NULL ) ;
if ( V_54 -> V_173 > V_193 )
V_54 -> V_173 = V_193 ;
if ( V_54 -> V_173 > V_198 )
V_54 -> V_173 = V_198 ;
V_54 -> V_199 = ( V_54 -> V_173 + V_200 - 1 ) >> V_201 ;
V_54 -> V_202 . V_203 = L_20 ;
V_54 -> V_202 . V_204 = V_54 -> V_199 * V_205 ;
if ( V_54 -> V_174 > V_193 )
V_54 -> V_174 = V_193 ;
if ( V_54 -> V_174 > V_198 )
V_54 -> V_174 = V_198 ;
V_54 -> V_206 = ( V_54 -> V_174 + V_200 - 1 ) >> V_201 ;
V_54 -> V_207 = V_192 -> V_208 ;
F_85 ( V_54 , V_190 , V_192 -> V_209 ) ;
V_54 -> V_210 = F_86 ( V_192 -> V_210 , NULL ) ;
V_54 -> V_211 = F_82 ( V_192 -> V_212 , NULL ) ;
if ( V_54 -> V_211 > V_200 * V_213 )
V_54 -> V_211 = V_200 * V_213 ;
if ( V_54 -> V_211 > V_54 -> V_173 )
V_54 -> V_211 = V_54 -> V_173 ;
if ( V_54 -> V_127 & V_214 ) {
V_54 -> V_175 = V_54 -> V_176 = 0 ;
V_54 -> V_177 = V_54 -> V_178 = 0 ;
}
V_54 -> V_215 = V_192 -> V_215 ;
V_54 -> V_216 = V_192 -> V_216 ;
F_87 ( V_54 -> V_145 , V_54 -> V_174 + 100 , V_54 -> V_173 + 100 ) ;
}
static int F_88 ( struct V_53 * V_54 , struct V_189 * V_190 , struct V_217 * V_218 )
{
struct V_191 V_192 ;
struct V_1 * V_2 = V_54 -> V_1 ;
int error ;
F_36 ( L_21 ) ;
if ( V_2 -> V_5 -> V_219 != NULL ) {
error = V_2 -> V_5 -> V_219 ( V_54 , V_190 ) ;
if ( error < 0 )
goto V_220;
}
V_192 . V_218 = V_218 ;
V_192 . V_209 = 0 ;
error = V_2 -> V_5 -> V_192 ( V_54 , V_190 , & V_192 ) ;
if ( error < 0 )
goto V_220;
F_83 ( V_54 , V_190 , & V_192 ) ;
if ( V_54 -> V_187 == 0 ) {
struct V_221 V_222 ;
V_222 . V_218 = V_218 ;
F_89 ( V_218 ) ;
if ( V_2 -> V_5 -> V_223 ( V_54 , V_190 , & V_222 ) >= 0 )
V_54 -> V_187 = V_222 . V_224 ;
}
F_36 ( L_22 ) ;
return 0 ;
V_220:
F_36 ( L_23 , - error ) ;
return error ;
}
static void F_90 ( struct V_53 * V_225 , struct V_53 * V_226 )
{
V_225 -> V_127 = V_226 -> V_127 ;
V_225 -> V_173 = V_226 -> V_173 ;
V_225 -> V_174 = V_226 -> V_174 ;
V_225 -> V_175 = V_226 -> V_175 ;
V_225 -> V_176 = V_226 -> V_176 ;
V_225 -> V_177 = V_226 -> V_177 ;
V_225 -> V_178 = V_226 -> V_178 ;
V_225 -> V_147 = V_226 -> V_147 ;
V_225 -> V_162 = V_226 -> V_162 ;
}
static void F_91 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_1 ;
F_3 ( & V_11 ) ;
F_92 ( & V_54 -> V_227 , & V_2 -> V_30 ) ;
F_93 ( & V_54 -> V_228 , & V_229 ) ;
F_94 ( V_230 , & V_2 -> V_49 ) ;
F_5 ( & V_11 ) ;
}
static void F_95 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = V_54 -> V_1 ;
F_3 ( & V_11 ) ;
F_96 ( & V_54 -> V_227 ) ;
if ( V_2 && F_46 ( & V_2 -> V_30 ) )
F_97 ( V_230 , & V_2 -> V_49 ) ;
F_44 ( & V_54 -> V_228 ) ;
F_5 ( & V_11 ) ;
F_98 () ;
}
static struct V_53 * F_99 ( void )
{
struct V_53 * V_54 ;
V_54 = F_7 ( sizeof( struct V_53 ) , V_9 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_145 = V_54 -> V_144 = F_11 ( - V_32 ) ;
F_10 ( & V_54 -> V_227 ) ;
F_10 ( & V_54 -> V_228 ) ;
F_10 ( & V_54 -> V_231 ) ;
F_10 ( & V_54 -> V_232 ) ;
F_8 ( & V_54 -> V_233 , 0 ) ;
V_54 -> V_234 = F_100 () ;
if ( ! V_54 -> V_234 ) {
F_19 ( V_54 ) ;
return NULL ;
}
if ( F_101 ( & V_54 -> V_202 ) ) {
F_102 ( V_54 -> V_234 ) ;
F_19 ( V_54 ) ;
return NULL ;
}
F_34 ( V_54 ) ;
return V_54 ;
}
void F_103 ( struct V_53 * V_54 )
{
F_36 ( L_24 ) ;
F_95 ( V_54 ) ;
F_104 ( V_54 ) ;
if ( V_54 -> V_141 != NULL )
V_54 -> V_141 ( V_54 ) ;
if ( ! F_17 ( V_54 -> V_144 ) )
F_38 ( V_54 -> V_144 ) ;
if ( ! F_17 ( V_54 -> V_145 ) )
F_38 ( V_54 -> V_145 ) ;
F_41 ( V_54 -> V_1 ) ;
F_102 ( V_54 -> V_234 ) ;
F_105 ( & V_54 -> V_202 ) ;
F_19 ( V_54 ) ;
F_106 () ;
F_36 ( L_25 ) ;
}
struct V_53 * F_107 ( const struct V_159 * V_78 ,
struct V_189 * V_190 )
{
struct V_53 * V_54 ;
struct V_217 * V_218 ;
int error ;
V_54 = F_99 () ;
if ( ! V_54 )
return F_11 ( - V_10 ) ;
error = - V_10 ;
V_218 = F_108 () ;
if ( V_218 == NULL )
goto error;
error = F_80 ( V_54 , V_78 ) ;
if ( error < 0 )
goto error;
F_45 ( ! V_54 -> V_1 ) ;
F_45 ( ! V_54 -> V_1 -> V_5 ) ;
F_45 ( ! V_54 -> V_1 -> V_5 -> V_235 ) ;
error = F_88 ( V_54 , V_190 , V_218 ) ;
if ( error < 0 )
goto error;
if ( V_54 -> V_1 -> V_5 -> V_6 == 3 ) {
if ( V_54 -> V_187 == 0 || V_54 -> V_187 > V_236 )
V_54 -> V_187 = V_236 ;
if ( ! ( V_78 -> V_127 & V_237 ) )
V_54 -> V_147 |= V_238 ;
} else {
if ( V_54 -> V_187 == 0 || V_54 -> V_187 > V_239 )
V_54 -> V_187 = V_239 ;
}
if ( ! ( V_218 -> V_240 & V_241 ) ) {
error = V_54 -> V_1 -> V_5 -> V_242 ( V_54 , V_190 , V_218 ) ;
if ( error < 0 ) {
F_36 ( L_26 , - error ) ;
goto error;
}
}
memcpy ( & V_54 -> V_243 , & V_218 -> V_243 , sizeof( V_54 -> V_243 ) ) ;
F_36 ( L_27 ,
( unsigned long long ) V_54 -> V_243 . V_244 ,
( unsigned long long ) V_54 -> V_243 . V_245 ) ;
F_91 ( V_54 ) ;
V_54 -> V_246 = V_247 ;
F_109 ( V_218 ) ;
return V_54 ;
error:
F_109 ( V_218 ) ;
F_103 ( V_54 ) ;
return F_11 ( error ) ;
}
struct V_1 *
F_110 ( const struct V_58 * V_24 )
{
struct V_1 * V_2 ;
F_3 ( & V_11 ) ;
F_57 (clp, &nfs_client_list, cl_share_link) {
if ( F_55 ( V_24 , V_2 , 0 ) == false )
continue;
F_58 ( & V_2 -> V_20 ) ;
F_5 ( & V_11 ) ;
return V_2 ;
}
F_5 ( & V_11 ) ;
return NULL ;
}
struct V_1 *
F_111 ( int V_248 )
{
struct V_1 * V_2 ;
F_3 ( & V_11 ) ;
V_2 = F_112 ( & V_8 , V_248 ) ;
if ( V_2 )
F_58 ( & V_2 -> V_20 ) ;
F_5 ( & V_11 ) ;
return V_2 ;
}
struct V_1 *
F_113 ( const struct V_58 * V_24 ,
struct V_249 * V_250 )
{
struct V_1 * V_2 ;
F_3 ( & V_11 ) ;
F_57 (clp, &nfs_client_list, cl_share_link) {
if ( F_55 ( V_24 , V_2 , 1 ) == false )
continue;
if ( ! F_21 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_47 -> V_251 . V_78 ,
V_250 -> V_78 , V_252 ) != 0 )
continue;
F_58 ( & V_2 -> V_20 ) ;
F_5 ( & V_11 ) ;
return V_2 ;
}
F_5 ( & V_11 ) ;
return NULL ;
}
struct V_1 *
F_113 ( const struct V_58 * V_24 ,
struct V_249 * V_250 )
{
return NULL ;
}
static int F_114 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_5 -> V_6 == 4 ) {
if ( F_21 ( V_2 ) ) {
error = F_115 (
V_2 -> V_31 -> V_253 ,
V_254 ) ;
if ( error < 0 )
return error ;
}
error = F_116 ( V_2 -> V_44 -> V_50 ,
V_2 -> V_31 -> V_253 ) ;
if ( error < 0 ) {
F_36 ( L_28 ,
V_130 , error ) ;
return error ;
}
F_117 ( V_48 , & V_2 -> V_49 ) ;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
#if F_119 ( V_255 )
if ( V_2 -> V_44 -> V_50 ) {
struct V_256 * V_257 = NULL ;
V_257 = F_120 ( V_2 ) ;
if ( ! V_257 )
return - V_10 ;
V_2 -> V_47 = V_257 ;
V_2 -> V_21 = V_77 ;
}
#endif
return F_114 ( V_2 ) ;
}
int F_121 ( struct V_1 * V_2 ,
const struct V_80 * V_81 ,
const char * V_82 ,
T_2 V_83 ,
int V_84 )
{
int error ;
if ( V_2 -> V_21 == V_76 ) {
F_36 ( L_29 , V_2 ) ;
return 0 ;
}
V_2 -> V_5 = & V_258 ;
error = F_68 ( V_2 , V_81 , V_83 ,
1 , V_84 ) ;
if ( error < 0 )
goto error;
F_122 ( V_2 -> V_259 , V_82 , sizeof( V_2 -> V_259 ) ) ;
error = F_123 ( V_2 ) ;
if ( error < 0 ) {
F_36 ( L_30 ,
V_130 , error ) ;
goto error;
}
F_117 ( V_52 , & V_2 -> V_49 ) ;
error = F_118 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_21 ( V_2 ) )
F_63 ( V_2 , V_76 ) ;
return 0 ;
error:
F_63 ( V_2 , error ) ;
F_36 ( L_31 , error ) ;
return error ;
}
static int F_124 ( struct V_53 * V_54 ,
const char * V_27 ,
const struct V_58 * V_24 ,
const T_3 V_25 ,
const char * V_82 ,
T_2 V_83 ,
int V_34 , const struct V_80 * V_81 ,
T_1 V_3 )
{
struct V_14 V_15 = {
. V_27 = V_27 ,
. V_24 = V_24 ,
. V_25 = V_25 ,
. V_5 = & V_258 ,
. V_34 = V_34 ,
. V_3 = V_3 ,
} ;
struct V_1 * V_2 ;
int error ;
F_36 ( L_32 ) ;
V_2 = F_59 ( & V_15 , V_81 , V_82 , V_83 ,
V_54 -> V_127 & V_138 ) ;
if ( F_17 ( V_2 ) ) {
error = F_60 ( V_2 ) ;
goto error;
}
F_97 ( V_260 , & V_2 -> V_49 ) ;
V_54 -> V_1 = V_2 ;
F_36 ( L_33 , V_2 ) ;
return 0 ;
error:
F_36 ( L_34 , error ) ;
return error ;
}
struct V_1 * F_125 ( struct V_1 * V_261 ,
const struct V_58 * V_262 ,
int V_263 , int V_264 )
{
struct V_14 V_15 = {
. V_24 = V_262 ,
. V_25 = V_263 ,
. V_5 = & V_258 ,
. V_34 = V_264 ,
. V_3 = V_261 -> V_43 ,
} ;
struct V_80 V_265 = {
. V_97 = 15 * V_98 ,
. V_106 = 15 * V_98 ,
. V_99 = 1 ,
. V_107 = 1 ,
} ;
struct V_1 * V_2 ;
V_2 = F_59 ( & V_15 , & V_265 , V_261 -> V_259 ,
V_261 -> V_31 -> V_152 -> V_153 , 0 ) ;
F_36 ( L_35 , V_130 , V_2 ) ;
return V_2 ;
}
static void F_126 ( struct V_53 * V_54 )
{
#ifdef V_255
struct V_256 * V_266 ;
T_1 V_267 ;
T_1 V_268 ;
if ( ! F_21 ( V_54 -> V_1 ) )
return;
V_266 = V_54 -> V_1 -> V_47 ;
V_267 = V_266 -> V_269 . V_270 - V_271 ;
V_268 = V_266 -> V_269 . V_272 - V_273 ;
if ( V_54 -> V_173 > V_267 )
V_54 -> V_173 = V_267 ;
if ( V_54 -> V_174 > V_268 )
V_54 -> V_174 = V_268 ;
#endif
}
static int F_127 ( struct V_53 * V_54 ,
struct V_189 * V_190 )
{
struct V_217 * V_218 ;
int error ;
F_45 ( ! V_54 -> V_1 ) ;
F_45 ( ! V_54 -> V_1 -> V_5 ) ;
F_45 ( ! V_54 -> V_1 -> V_5 -> V_235 ) ;
if ( F_128 ( V_54 -> V_1 ) )
return - V_93 ;
V_218 = F_108 () ;
if ( V_218 == NULL )
return - V_10 ;
error = F_129 ( V_54 ) ;
if ( error < 0 )
goto V_274;
error = F_130 ( V_54 , V_190 ) ;
if ( error < 0 )
goto V_274;
F_36 ( L_27 ,
( unsigned long long ) V_54 -> V_243 . V_244 ,
( unsigned long long ) V_54 -> V_243 . V_245 ) ;
F_36 ( L_36 , V_190 -> V_275 ) ;
F_126 ( V_54 ) ;
error = F_88 ( V_54 , V_190 , V_218 ) ;
if ( error < 0 )
goto V_274;
if ( V_54 -> V_187 == 0 || V_54 -> V_187 > V_276 )
V_54 -> V_187 = V_276 ;
F_91 ( V_54 ) ;
V_54 -> V_246 = V_247 ;
V_274:
F_109 ( V_218 ) ;
return error ;
}
static int F_131 ( struct V_53 * V_54 ,
const struct V_159 * V_78 )
{
struct V_80 V_81 ;
int error ;
F_36 ( L_37 ) ;
F_66 ( & V_81 , V_78 -> V_53 . V_119 ,
V_78 -> V_95 , V_78 -> V_96 ) ;
V_54 -> V_127 = V_78 -> V_127 ;
V_54 -> V_147 |= V_277 | V_278 | V_279 ;
if ( ! ( V_78 -> V_127 & V_237 ) )
V_54 -> V_147 |= V_238 ;
V_54 -> V_162 = V_78 -> V_162 ;
error = F_124 ( V_54 ,
V_78 -> V_53 . V_27 ,
( const struct V_58 * ) & V_78 -> V_53 . V_120 ,
V_78 -> V_53 . V_25 ,
V_78 -> V_280 ,
V_78 -> V_180 [ 0 ] ,
V_78 -> V_53 . V_119 ,
& V_81 ,
V_78 -> V_3 ) ;
if ( error < 0 )
goto error;
if ( V_281 && V_78 -> V_180 [ 0 ] == V_158 )
V_54 -> V_147 |= V_282 ;
if ( V_78 -> V_173 )
V_54 -> V_173 = F_82 ( V_78 -> V_173 , NULL ) ;
if ( V_78 -> V_174 )
V_54 -> V_174 = F_82 ( V_78 -> V_174 , NULL ) ;
V_54 -> V_175 = V_78 -> V_175 * V_98 ;
V_54 -> V_176 = V_78 -> V_176 * V_98 ;
V_54 -> V_177 = V_78 -> V_177 * V_98 ;
V_54 -> V_178 = V_78 -> V_178 * V_98 ;
V_54 -> V_179 = V_78 -> V_53 . V_179 ;
error = F_76 ( V_54 , & V_81 , V_78 -> V_180 [ 0 ] ) ;
error:
F_36 ( L_38 , error ) ;
return error ;
}
struct V_53 * F_132 ( const struct V_159 * V_78 ,
struct V_189 * V_190 )
{
struct V_53 * V_54 ;
int error ;
F_36 ( L_39 ) ;
V_54 = F_99 () ;
if ( ! V_54 )
return F_11 ( - V_10 ) ;
error = F_131 ( V_54 , V_78 ) ;
if ( error < 0 )
goto error;
error = F_127 ( V_54 , V_190 ) ;
if ( error < 0 )
goto error;
F_36 ( L_40 , V_54 ) ;
return V_54 ;
error:
F_103 ( V_54 ) ;
F_36 ( L_41 , error ) ;
return F_11 ( error ) ;
}
struct V_53 * F_133 ( struct V_283 * V_78 ,
struct V_189 * V_190 )
{
struct V_1 * V_284 ;
struct V_53 * V_54 , * V_285 ;
int error ;
F_36 ( L_42 ) ;
V_54 = F_99 () ;
if ( ! V_54 )
return F_11 ( - V_10 ) ;
V_285 = F_134 ( V_78 -> V_286 ) ;
V_284 = V_285 -> V_1 ;
F_90 ( V_54 , V_285 ) ;
V_54 -> V_147 |= V_277 | V_278 ;
error = F_124 ( V_54 , V_78 -> V_27 ,
V_78 -> V_24 ,
V_78 -> V_25 ,
V_284 -> V_259 ,
V_78 -> V_126 ,
V_285 -> V_145 -> V_253 -> V_287 ,
V_285 -> V_145 -> V_151 ,
V_284 -> V_44 -> V_50 ) ;
if ( error < 0 )
goto error;
error = F_76 ( V_54 , V_285 -> V_145 -> V_151 , V_78 -> V_126 ) ;
if ( error < 0 )
goto error;
error = F_127 ( V_54 , V_190 ) ;
if ( error < 0 )
goto error;
F_36 ( L_43 , V_54 ) ;
return V_54 ;
error:
F_103 ( V_54 ) ;
F_36 ( L_44 , error ) ;
return F_11 ( error ) ;
}
struct V_53 * F_135 ( struct V_53 * V_226 ,
struct V_189 * V_288 ,
struct V_217 * V_218 )
{
struct V_53 * V_54 ;
struct V_217 * V_289 ;
int error ;
F_36 ( L_45 ,
( unsigned long long ) V_218 -> V_243 . V_244 ,
( unsigned long long ) V_218 -> V_243 . V_245 ) ;
V_54 = F_99 () ;
if ( ! V_54 )
return F_11 ( - V_10 ) ;
error = - V_10 ;
V_289 = F_108 () ;
if ( V_289 == NULL )
goto V_290;
V_54 -> V_1 = V_226 -> V_1 ;
F_58 ( & V_54 -> V_1 -> V_20 ) ;
F_90 ( V_54 , V_226 ) ;
V_54 -> V_243 = V_218 -> V_243 ;
error = F_76 ( V_54 ,
V_226 -> V_145 -> V_151 ,
V_226 -> V_145 -> V_152 -> V_153 ) ;
if ( error < 0 )
goto V_290;
if ( ! F_17 ( V_226 -> V_144 ) )
F_74 ( V_54 ) ;
error = F_88 ( V_54 , V_288 , V_289 ) ;
if ( error < 0 )
goto V_290;
if ( V_54 -> V_187 == 0 || V_54 -> V_187 > V_276 )
V_54 -> V_187 = V_276 ;
F_36 ( L_46 ,
( unsigned long long ) V_54 -> V_243 . V_244 ,
( unsigned long long ) V_54 -> V_243 . V_245 ) ;
error = F_72 ( V_54 ) ;
if ( error < 0 )
goto V_290;
F_91 ( V_54 ) ;
V_54 -> V_246 = V_247 ;
F_109 ( V_289 ) ;
F_36 ( L_47 , V_54 ) ;
return V_54 ;
V_290:
F_109 ( V_289 ) ;
F_103 ( V_54 ) ;
F_36 ( L_48 , error ) ;
return F_11 ( error ) ;
}
static int F_136 ( struct V_291 * V_291 , struct V_292 * V_292 )
{
struct V_293 * V_294 ;
int V_4 ;
V_4 = F_137 ( V_292 , & V_295 ) ;
if ( V_4 < 0 )
return V_4 ;
V_294 = V_292 -> V_296 ;
V_294 -> V_297 = F_138 ( V_291 ) -> V_78 ;
return 0 ;
}
static void * F_139 ( struct V_293 * V_294 , T_4 * V_298 )
{
F_3 ( & V_11 ) ;
return F_140 ( & V_88 , * V_298 ) ;
}
static void * F_141 ( struct V_293 * V_299 , void * V_300 , T_4 * V_301 )
{
return F_142 ( V_300 , & V_88 , V_301 ) ;
}
static void F_143 ( struct V_293 * V_299 , void * V_300 )
{
F_5 ( & V_11 ) ;
}
static int F_144 ( struct V_293 * V_294 , void * V_300 )
{
struct V_1 * V_2 ;
if ( V_300 == & V_88 ) {
F_145 ( V_294 , L_49 ) ;
return 0 ;
}
V_2 = F_146 ( V_300 , struct V_1 , V_57 ) ;
F_147 ( V_294 , L_50 ,
V_2 -> V_5 -> V_6 ,
F_148 ( V_2 -> V_31 , V_302 ) ,
F_148 ( V_2 -> V_31 , V_303 ) ,
F_42 ( & V_2 -> V_20 ) ,
V_2 -> V_28 ) ;
return 0 ;
}
static int F_149 ( struct V_291 * V_291 , struct V_292 * V_292 )
{
struct V_293 * V_294 ;
int V_4 ;
V_4 = F_137 ( V_292 , & V_304 ) ;
if ( V_4 < 0 )
return V_4 ;
V_294 = V_292 -> V_296 ;
V_294 -> V_297 = F_138 ( V_291 ) -> V_78 ;
return 0 ;
}
static void * F_150 ( struct V_293 * V_294 , T_4 * V_298 )
{
F_3 ( & V_11 ) ;
return F_140 ( & V_229 , * V_298 ) ;
}
static void * F_151 ( struct V_293 * V_299 , void * V_300 , T_4 * V_301 )
{
return F_142 ( V_300 , & V_229 , V_301 ) ;
}
static void F_152 ( struct V_293 * V_299 , void * V_300 )
{
F_5 ( & V_11 ) ;
}
static int F_153 ( struct V_293 * V_294 , void * V_300 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 ;
char V_305 [ 8 ] , V_243 [ 17 ] ;
if ( V_300 == & V_229 ) {
F_145 ( V_294 , L_51 ) ;
return 0 ;
}
V_54 = F_146 ( V_300 , struct V_53 , V_228 ) ;
V_2 = V_54 -> V_1 ;
snprintf ( V_305 , 8 , L_52 ,
F_154 ( V_54 -> V_306 ) , F_155 ( V_54 -> V_306 ) ) ;
snprintf ( V_243 , 17 , L_53 ,
( unsigned long long ) V_54 -> V_243 . V_244 ,
( unsigned long long ) V_54 -> V_243 . V_245 ) ;
F_147 ( V_294 , L_54 ,
V_2 -> V_5 -> V_6 ,
F_148 ( V_2 -> V_31 , V_302 ) ,
F_148 ( V_2 -> V_31 , V_303 ) ,
V_305 ,
V_243 ,
F_156 ( V_54 ) ) ;
return 0 ;
}
int T_5 F_157 ( void )
{
struct V_307 * V_299 ;
V_308 = F_158 ( L_55 , NULL ) ;
if ( ! V_308 )
goto V_19;
V_299 = F_159 ( L_56 , V_309 | V_310 ,
V_308 , & V_311 ) ;
if ( ! V_299 )
goto V_312;
V_299 = F_159 ( L_57 , V_309 | V_310 ,
V_308 , & V_313 ) ;
if ( ! V_299 )
goto V_314;
return 0 ;
V_314:
F_160 ( L_56 , V_308 ) ;
V_312:
F_160 ( L_55 , NULL ) ;
V_19:
return - V_10 ;
}
void F_161 ( void )
{
F_160 ( L_57 , V_308 ) ;
F_160 ( L_56 , V_308 ) ;
F_160 ( L_55 , NULL ) ;
}
