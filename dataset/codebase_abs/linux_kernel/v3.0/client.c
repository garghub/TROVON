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
#if F_18 ( V_47 )
F_10 ( & V_2 -> V_48 ) ;
#endif
F_19 ( V_2 ) ;
return V_2 ;
V_29:
F_20 ( V_2 ) ;
V_19:
return F_11 ( V_18 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( F_22 ( V_2 ) )
F_23 ( V_2 -> V_49 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
}
static void F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_50 , & V_2 -> V_51 ) )
F_26 ( V_2 -> V_44 -> V_52 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( F_25 ( V_53 , & V_2 -> V_51 ) )
F_28 ( V_2 ) ;
F_21 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( F_25 ( V_54 , & V_2 -> V_51 ) )
F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_38 ) ;
}
void F_31 ( void )
{
F_32 ( & V_8 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 )
F_34 ( & V_8 , V_2 -> V_12 ) ;
}
static void F_35 ( struct V_55 * V_56 )
{
F_15 ( & V_56 -> V_57 , L_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
}
void F_31 ( void )
{
}
static void F_33 ( struct V_1 * V_2 )
{
}
static void F_35 ( struct V_55 * V_56 )
{
}
static void F_36 ( struct V_1 * V_2 )
{
F_37 ( L_3 , V_2 -> V_5 -> V_6 ) ;
F_27 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( ! F_17 ( V_2 -> V_31 ) )
F_39 ( V_2 -> V_31 ) ;
if ( V_2 -> V_46 != NULL )
F_40 ( V_2 -> V_46 ) ;
F_41 ( V_2 ) ;
F_20 ( V_2 -> V_28 ) ;
F_20 ( V_2 ) ;
F_37 ( L_4 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_37 ( L_5 , F_43 ( & V_2 -> V_20 ) ) ;
if ( F_44 ( & V_2 -> V_20 , & V_11 ) ) {
F_45 ( & V_2 -> V_58 ) ;
F_33 ( V_2 ) ;
F_5 ( & V_11 ) ;
F_46 ( ! F_47 ( & V_2 -> V_30 ) ) ;
F_36 ( V_2 ) ;
}
}
static int F_48 ( const struct V_59 * V_60 ,
const struct V_59 * V_61 )
{
const struct V_62 * V_63 = ( const struct V_62 * ) V_60 ;
const struct V_62 * V_64 = ( const struct V_62 * ) V_61 ;
if ( F_49 ( & V_63 -> V_65 ) == V_66 &&
V_63 -> V_67 != V_64 -> V_67 )
return 0 ;
return F_50 ( & V_63 -> V_65 , & V_64 -> V_65 ) ;
}
static int F_48 ( const struct V_59 * V_60 ,
const struct V_59 * V_61 )
{
return 0 ;
}
static int F_51 ( const struct V_59 * V_60 ,
const struct V_59 * V_61 )
{
const struct V_68 * V_63 = ( const struct V_68 * ) V_60 ;
const struct V_68 * V_64 = ( const struct V_68 * ) V_61 ;
return V_63 -> V_69 . V_70 == V_64 -> V_69 . V_70 ;
}
static int F_52 ( const struct V_59 * V_60 ,
const struct V_59 * V_61 )
{
const struct V_62 * V_63 = ( const struct V_62 * ) V_60 ;
const struct V_62 * V_64 = ( const struct V_62 * ) V_61 ;
return F_48 ( V_60 , V_61 ) &&
( V_63 -> V_71 == V_64 -> V_71 ) ;
}
static int F_53 ( const struct V_59 * V_60 ,
const struct V_59 * V_61 )
{
const struct V_68 * V_63 = ( const struct V_68 * ) V_60 ;
const struct V_68 * V_64 = ( const struct V_68 * ) V_61 ;
return F_51 ( V_60 , V_61 ) &&
( V_63 -> V_72 == V_64 -> V_72 ) ;
}
static int F_54 ( const struct V_59 * V_60 ,
const struct V_59 * V_61 )
{
if ( V_60 -> V_73 != V_61 -> V_73 )
return 0 ;
switch ( V_60 -> V_73 ) {
case V_74 :
return F_51 ( V_60 , V_61 ) ;
case V_75 :
return F_48 ( V_60 , V_61 ) ;
}
return 0 ;
}
static int F_55 ( const struct V_59 * V_60 ,
const struct V_59 * V_61 )
{
if ( V_60 -> V_73 != V_61 -> V_73 )
return 0 ;
switch ( V_60 -> V_73 ) {
case V_74 :
return F_53 ( V_60 , V_61 ) ;
case V_75 :
return F_52 ( V_60 , V_61 ) ;
}
return 0 ;
}
bool
F_56 ( const struct V_59 * V_24 , struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_59 * V_76 = (struct V_59 * ) & V_2 -> V_23 ;
if ( ! ( V_2 -> V_21 == V_77 ||
V_2 -> V_21 == V_78 ) )
return false ;
if ( V_2 -> V_5 -> V_6 != 4 ||
V_2 -> V_43 != V_3 )
return false ;
if ( ! F_54 ( V_24 , V_76 ) )
return false ;
return true ;
}
static struct V_1 * F_57 ( const struct V_14 * V_79 )
{
struct V_1 * V_2 ;
const struct V_59 * V_80 = V_79 -> V_24 ;
F_58 (clp, &nfs_client_list, cl_share_link) {
const struct V_59 * V_76 = (struct V_59 * ) & V_2 -> V_23 ;
if ( V_2 -> V_21 < 0 )
continue;
if ( V_2 -> V_5 != V_79 -> V_5 )
continue;
if ( V_2 -> V_33 != V_79 -> V_34 )
continue;
if ( V_2 -> V_43 != V_79 -> V_3 )
continue;
if ( ! F_55 ( V_80 , V_76 ) )
continue;
F_59 ( & V_2 -> V_20 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_60 ( const struct V_14 * V_15 ,
const struct V_81 * V_82 ,
const char * V_83 ,
T_2 V_84 ,
int V_85 )
{
struct V_1 * V_2 , * V_86 = NULL ;
int error ;
F_37 ( L_6 ,
V_15 -> V_27 ? : L_7 , V_15 -> V_5 -> V_6 ) ;
do {
F_3 ( & V_11 ) ;
V_2 = F_57 ( V_15 ) ;
if ( V_2 )
goto V_87;
if ( V_86 )
goto V_88;
F_5 ( & V_11 ) ;
V_86 = F_6 ( V_15 ) ;
} while ( ! F_17 ( V_86 ) );
F_37 ( L_8 , F_61 ( V_86 ) ) ;
return V_86 ;
V_88:
V_2 = V_86 ;
F_62 ( & V_2 -> V_58 , & V_89 ) ;
F_5 ( & V_11 ) ;
error = V_15 -> V_5 -> V_90 ( V_2 , V_82 , V_83 ,
V_84 , V_85 ) ;
if ( error < 0 ) {
F_42 ( V_2 ) ;
return F_11 ( error ) ;
}
F_37 ( L_9 , V_2 ) ;
return V_2 ;
V_87:
F_5 ( & V_11 ) ;
if ( V_86 )
F_36 ( V_86 ) ;
error = F_63 ( V_91 ,
V_2 -> V_21 < V_22 ) ;
if ( error < 0 ) {
F_42 ( V_2 ) ;
return F_11 ( - V_92 ) ;
}
if ( V_2 -> V_21 < V_77 ) {
error = V_2 -> V_21 ;
F_42 ( V_2 ) ;
return F_11 ( error ) ;
}
F_46 ( V_2 -> V_21 != V_77 ) ;
F_37 ( L_10 , V_2 ) ;
return V_2 ;
}
void F_64 ( struct V_1 * V_2 , int V_93 )
{
V_2 -> V_21 = V_93 ;
F_65 ( & V_91 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
if ( ! F_22 ( V_2 ) )
return 0 ;
if ( V_2 -> V_21 < V_77 )
return - V_94 ;
return 0 ;
}
static void F_67 ( struct V_81 * V_95 , int V_34 ,
unsigned int V_96 , unsigned int V_97 )
{
V_95 -> V_98 = V_96 * V_99 / 10 ;
V_95 -> V_100 = V_97 ;
switch ( V_34 ) {
case V_101 :
case V_102 :
if ( V_95 -> V_100 == 0 )
V_95 -> V_100 = V_103 ;
if ( V_95 -> V_98 == 0 )
V_95 -> V_98 = V_104 * V_99 / 10 ;
if ( V_95 -> V_98 > V_105 )
V_95 -> V_98 = V_105 ;
V_95 -> V_106 = V_95 -> V_98 ;
V_95 -> V_107 = V_95 -> V_98 + ( V_95 -> V_106 * V_95 -> V_100 ) ;
if ( V_95 -> V_107 > V_105 )
V_95 -> V_107 = V_105 ;
if ( V_95 -> V_107 < V_95 -> V_98 )
V_95 -> V_107 = V_95 -> V_98 ;
V_95 -> V_108 = 0 ;
break;
case V_109 :
if ( V_95 -> V_100 == 0 )
V_95 -> V_100 = V_110 ;
if ( ! V_95 -> V_98 )
V_95 -> V_98 = V_111 * V_99 / 10 ;
if ( V_95 -> V_98 > V_112 )
V_95 -> V_98 = V_112 ;
V_95 -> V_107 = V_112 ;
V_95 -> V_108 = 1 ;
break;
default:
F_68 () ;
}
}
static int F_69 ( struct V_1 * V_2 ,
const struct V_81 * V_82 ,
T_2 V_113 ,
int V_114 , int V_85 )
{
struct V_115 * V_116 = NULL ;
struct V_117 args = {
. V_118 = & V_119 ,
. V_120 = V_2 -> V_33 ,
. V_121 = (struct V_59 * ) & V_2 -> V_23 ,
. V_122 = V_2 -> V_26 ,
. V_123 = V_82 ,
. V_124 = V_2 -> V_28 ,
. V_125 = & V_126 ,
. V_6 = V_2 -> V_5 -> V_6 ,
. V_127 = V_113 ,
} ;
if ( V_114 )
args . V_128 |= V_129 ;
if ( V_85 )
args . V_128 |= V_130 ;
if ( ! F_17 ( V_2 -> V_31 ) )
return 0 ;
V_116 = F_70 ( & args ) ;
if ( F_17 ( V_116 ) ) {
F_37 ( L_11 ,
V_131 , F_61 ( V_116 ) ) ;
return F_61 ( V_116 ) ;
}
V_2 -> V_31 = V_116 ;
return 0 ;
}
static void F_71 ( struct V_55 * V_56 )
{
if ( ! ( V_56 -> V_128 & V_132 ) ||
! ( V_56 -> V_128 & V_133 ) )
F_72 ( V_56 -> V_134 ) ;
}
static int F_73 ( struct V_55 * V_56 )
{
struct V_134 * V_135 ;
struct V_1 * V_2 = V_56 -> V_1 ;
struct V_136 V_137 = {
. V_27 = V_2 -> V_28 ,
. V_121 = (struct V_59 * ) & V_2 -> V_23 ,
. V_25 = V_2 -> V_26 ,
. V_138 = V_2 -> V_5 -> V_6 ,
. V_85 = V_56 -> V_128 & V_139 ?
1 : 0 ,
} ;
if ( V_137 . V_138 > 3 )
return 0 ;
if ( ( V_56 -> V_128 & V_132 ) &&
( V_56 -> V_128 & V_133 ) )
return 0 ;
switch ( V_2 -> V_33 ) {
default:
V_137 . V_120 = V_140 ;
break;
case V_109 :
V_137 . V_120 = V_141 ;
}
V_135 = F_74 ( & V_137 ) ;
if ( F_17 ( V_135 ) )
return F_61 ( V_135 ) ;
V_56 -> V_134 = V_135 ;
V_56 -> V_142 = F_71 ;
return 0 ;
}
static void F_75 ( struct V_55 * V_56 )
{
if ( V_56 -> V_1 -> V_5 -> V_6 != 3 )
goto V_143;
if ( V_56 -> V_128 & V_144 )
goto V_143;
V_56 -> V_145 = F_76 ( V_56 -> V_146 , & V_147 , 3 ) ;
if ( F_17 ( V_56 -> V_145 ) )
goto V_143;
V_56 -> V_148 |= V_149 ;
return;
V_143:
V_56 -> V_148 &= ~ V_149 ;
}
static inline void F_75 ( struct V_55 * V_56 )
{
V_56 -> V_128 &= ~ V_144 ;
V_56 -> V_148 &= ~ V_149 ;
}
static int F_77 ( struct V_55 * V_56 ,
const struct V_81 * V_96 ,
T_2 V_150 )
{
struct V_1 * V_2 = V_56 -> V_1 ;
V_56 -> V_146 = F_78 ( V_2 -> V_31 ) ;
if ( F_17 ( V_56 -> V_146 ) ) {
F_37 ( L_12 , V_131 ) ;
return F_61 ( V_56 -> V_146 ) ;
}
memcpy ( & V_56 -> V_146 -> V_151 ,
V_96 ,
sizeof( V_56 -> V_146 -> V_151 ) ) ;
V_56 -> V_146 -> V_152 = & V_56 -> V_146 -> V_151 ;
if ( V_150 != V_2 -> V_31 -> V_153 -> V_154 ) {
struct V_155 * V_156 ;
V_156 = F_79 ( V_150 , V_56 -> V_146 ) ;
if ( F_17 ( V_156 ) ) {
F_37 ( L_13 , V_131 ) ;
return F_61 ( V_156 ) ;
}
}
V_56 -> V_146 -> V_157 = 0 ;
if ( V_56 -> V_128 & V_158 )
V_56 -> V_146 -> V_157 = 1 ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 , const struct V_81 * V_82 ,
const char * V_83 , T_2 V_84 ,
int V_85 )
{
int error ;
if ( V_2 -> V_21 == V_77 ) {
F_37 ( L_14 , V_2 ) ;
return 0 ;
}
error = F_69 ( V_2 , V_82 , V_159 ,
0 , V_85 ) ;
if ( error < 0 )
goto error;
F_64 ( V_2 , V_77 ) ;
return 0 ;
error:
F_64 ( V_2 , error ) ;
F_37 ( L_15 , error ) ;
return error ;
}
static int F_81 ( struct V_55 * V_56 ,
const struct V_160 * V_79 )
{
struct V_14 V_15 = {
. V_27 = V_79 -> V_55 . V_27 ,
. V_24 = ( const struct V_59 * ) & V_79 -> V_55 . V_121 ,
. V_25 = V_79 -> V_55 . V_25 ,
. V_5 = & V_161 ,
. V_34 = V_79 -> V_55 . V_120 ,
} ;
struct V_81 V_82 ;
struct V_1 * V_2 ;
int error ;
F_37 ( L_16 ) ;
#ifdef F_82
if ( V_79 -> V_6 == 3 )
V_15 . V_5 = & V_162 ;
#endif
F_67 ( & V_82 , V_79 -> V_55 . V_120 ,
V_79 -> V_96 , V_79 -> V_97 ) ;
V_2 = F_60 ( & V_15 , & V_82 , NULL , V_159 ,
V_79 -> V_128 & V_139 ) ;
if ( F_17 ( V_2 ) ) {
F_37 ( L_17 , F_61 ( V_2 ) ) ;
return F_61 ( V_2 ) ;
}
V_56 -> V_1 = V_2 ;
V_56 -> V_128 = V_79 -> V_128 ;
V_56 -> V_163 = V_79 -> V_163 ;
V_56 -> V_148 |= V_164 | V_165 | V_166 |
V_167 | V_168 | V_169 | V_170 |
V_171 | V_172 | V_173 ;
if ( V_79 -> V_174 )
V_56 -> V_174 = F_83 ( V_79 -> V_174 , NULL ) ;
if ( V_79 -> V_175 )
V_56 -> V_175 = F_83 ( V_79 -> V_175 , NULL ) ;
V_56 -> V_176 = V_79 -> V_176 * V_99 ;
V_56 -> V_177 = V_79 -> V_177 * V_99 ;
V_56 -> V_178 = V_79 -> V_178 * V_99 ;
V_56 -> V_179 = V_79 -> V_179 * V_99 ;
error = F_73 ( V_56 ) ;
if ( error < 0 )
goto error;
V_56 -> V_180 = V_79 -> V_55 . V_180 ;
error = F_77 ( V_56 , & V_82 , V_79 -> V_181 [ 0 ] ) ;
if ( error < 0 )
goto error;
if ( V_79 -> V_182 . V_25 ) {
memcpy ( & V_56 -> V_183 , & V_79 -> V_182 . V_121 ,
V_79 -> V_182 . V_25 ) ;
V_56 -> V_184 = V_79 -> V_182 . V_25 ;
}
V_56 -> V_185 = V_79 -> V_182 . V_6 ;
V_56 -> V_186 = V_79 -> V_182 . V_180 ;
V_56 -> V_187 = V_79 -> V_182 . V_120 ;
V_56 -> V_188 = V_79 -> V_189 ;
F_75 ( V_56 ) ;
F_37 ( L_18 , V_2 ) ;
return 0 ;
error:
V_56 -> V_1 = NULL ;
F_42 ( V_2 ) ;
F_37 ( L_19 , error ) ;
return error ;
}
static void F_84 ( struct V_55 * V_56 , struct V_190 * V_191 )
{
unsigned long V_192 ;
if ( V_56 -> V_174 == 0 )
V_56 -> V_174 = F_83 ( V_191 -> V_193 , NULL ) ;
if ( V_56 -> V_175 == 0 )
V_56 -> V_175 = F_83 ( V_191 -> V_194 , NULL ) ;
if ( V_191 -> V_195 >= 512 && V_56 -> V_174 > V_191 -> V_195 )
V_56 -> V_174 = F_83 ( V_191 -> V_195 , NULL ) ;
if ( V_191 -> V_196 >= 512 && V_56 -> V_175 > V_191 -> V_196 )
V_56 -> V_175 = F_83 ( V_191 -> V_196 , NULL ) ;
V_192 = F_83 ( F_85 ( V_56 -> V_146 ) , NULL ) ;
if ( V_56 -> V_174 > V_192 )
V_56 -> V_174 = V_192 ;
if ( V_56 -> V_174 > V_197 )
V_56 -> V_174 = V_197 ;
V_56 -> V_198 = ( V_56 -> V_174 + V_199 - 1 ) >> V_200 ;
V_56 -> V_201 . V_202 = L_20 ;
V_56 -> V_201 . V_203 = V_56 -> V_198 * V_204 ;
if ( V_56 -> V_175 > V_192 )
V_56 -> V_175 = V_192 ;
if ( V_56 -> V_175 > V_197 )
V_56 -> V_175 = V_197 ;
V_56 -> V_205 = ( V_56 -> V_175 + V_199 - 1 ) >> V_200 ;
F_86 ( V_56 , V_191 -> V_206 ) ;
V_56 -> V_207 = F_87 ( V_191 -> V_207 , NULL ) ;
V_56 -> V_208 = F_83 ( V_191 -> V_209 , NULL ) ;
if ( V_56 -> V_208 > V_199 * V_210 )
V_56 -> V_208 = V_199 * V_210 ;
if ( V_56 -> V_208 > V_56 -> V_174 )
V_56 -> V_208 = V_56 -> V_174 ;
if ( V_56 -> V_128 & V_211 ) {
V_56 -> V_176 = V_56 -> V_177 = 0 ;
V_56 -> V_178 = V_56 -> V_179 = 0 ;
}
V_56 -> V_212 = V_191 -> V_212 ;
V_56 -> V_213 = V_191 -> V_213 ;
F_88 ( V_56 -> V_146 , V_56 -> V_175 + 100 , V_56 -> V_174 + 100 ) ;
}
static int F_89 ( struct V_55 * V_56 , struct V_214 * V_215 , struct V_216 * V_217 )
{
struct V_190 V_191 ;
struct V_1 * V_2 = V_56 -> V_1 ;
int error ;
F_37 ( L_21 ) ;
if ( V_2 -> V_5 -> V_218 != NULL ) {
error = V_2 -> V_5 -> V_218 ( V_56 , V_215 ) ;
if ( error < 0 )
goto V_219;
}
V_191 . V_217 = V_217 ;
V_191 . V_206 = 0 ;
error = V_2 -> V_5 -> V_191 ( V_56 , V_215 , & V_191 ) ;
if ( error < 0 )
goto V_219;
F_84 ( V_56 , & V_191 ) ;
if ( V_56 -> V_188 == 0 ) {
struct V_220 V_221 ;
V_221 . V_217 = V_217 ;
F_90 ( V_217 ) ;
if ( V_2 -> V_5 -> V_222 ( V_56 , V_215 , & V_221 ) >= 0 )
V_56 -> V_188 = V_221 . V_223 ;
}
F_37 ( L_22 ) ;
return 0 ;
V_219:
F_37 ( L_23 , - error ) ;
return error ;
}
static void F_91 ( struct V_55 * V_224 , struct V_55 * V_225 )
{
V_224 -> V_128 = V_225 -> V_128 ;
V_224 -> V_174 = V_225 -> V_174 ;
V_224 -> V_175 = V_225 -> V_175 ;
V_224 -> V_176 = V_225 -> V_176 ;
V_224 -> V_177 = V_225 -> V_177 ;
V_224 -> V_178 = V_225 -> V_178 ;
V_224 -> V_179 = V_225 -> V_179 ;
V_224 -> V_148 = V_225 -> V_148 ;
V_224 -> V_163 = V_225 -> V_163 ;
}
static void F_92 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_1 ;
F_3 ( & V_11 ) ;
F_93 ( & V_56 -> V_226 , & V_2 -> V_30 ) ;
F_94 ( & V_56 -> V_227 , & V_228 ) ;
F_95 ( V_229 , & V_2 -> V_51 ) ;
F_5 ( & V_11 ) ;
}
static void F_96 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_1 ;
F_3 ( & V_11 ) ;
F_97 ( & V_56 -> V_226 ) ;
if ( V_2 && F_47 ( & V_2 -> V_30 ) )
F_98 ( V_229 , & V_2 -> V_51 ) ;
F_45 ( & V_56 -> V_227 ) ;
F_5 ( & V_11 ) ;
F_99 () ;
}
static struct V_55 * F_100 ( void )
{
struct V_55 * V_56 ;
V_56 = F_7 ( sizeof( struct V_55 ) , V_9 ) ;
if ( ! V_56 )
return NULL ;
V_56 -> V_146 = V_56 -> V_145 = F_11 ( - V_32 ) ;
F_10 ( & V_56 -> V_226 ) ;
F_10 ( & V_56 -> V_227 ) ;
F_10 ( & V_56 -> V_230 ) ;
F_8 ( & V_56 -> V_231 , 0 ) ;
V_56 -> V_232 = F_101 () ;
if ( ! V_56 -> V_232 ) {
F_20 ( V_56 ) ;
return NULL ;
}
if ( F_102 ( & V_56 -> V_201 ) ) {
F_103 ( V_56 -> V_232 ) ;
F_20 ( V_56 ) ;
return NULL ;
}
F_35 ( V_56 ) ;
return V_56 ;
}
void F_104 ( struct V_55 * V_56 )
{
F_37 ( L_24 ) ;
F_96 ( V_56 ) ;
F_105 ( V_56 ) ;
if ( V_56 -> V_142 != NULL )
V_56 -> V_142 ( V_56 ) ;
if ( ! F_17 ( V_56 -> V_145 ) )
F_39 ( V_56 -> V_145 ) ;
if ( ! F_17 ( V_56 -> V_146 ) )
F_39 ( V_56 -> V_146 ) ;
F_42 ( V_56 -> V_1 ) ;
F_103 ( V_56 -> V_232 ) ;
F_106 ( & V_56 -> V_201 ) ;
F_20 ( V_56 ) ;
F_107 () ;
F_37 ( L_25 ) ;
}
struct V_55 * F_108 ( const struct V_160 * V_79 ,
struct V_214 * V_215 )
{
struct V_55 * V_56 ;
struct V_216 * V_217 ;
int error ;
V_56 = F_100 () ;
if ( ! V_56 )
return F_11 ( - V_10 ) ;
error = - V_10 ;
V_217 = F_109 () ;
if ( V_217 == NULL )
goto error;
error = F_81 ( V_56 , V_79 ) ;
if ( error < 0 )
goto error;
F_46 ( ! V_56 -> V_1 ) ;
F_46 ( ! V_56 -> V_1 -> V_5 ) ;
F_46 ( ! V_56 -> V_1 -> V_5 -> V_233 ) ;
error = F_89 ( V_56 , V_215 , V_217 ) ;
if ( error < 0 )
goto error;
if ( V_56 -> V_1 -> V_5 -> V_6 == 3 ) {
if ( V_56 -> V_188 == 0 || V_56 -> V_188 > V_234 )
V_56 -> V_188 = V_234 ;
if ( ! ( V_79 -> V_128 & V_235 ) )
V_56 -> V_148 |= V_236 ;
} else {
if ( V_56 -> V_188 == 0 || V_56 -> V_188 > V_237 )
V_56 -> V_188 = V_237 ;
}
if ( ! ( V_217 -> V_238 & V_239 ) ) {
error = V_56 -> V_1 -> V_5 -> V_240 ( V_56 , V_215 , V_217 ) ;
if ( error < 0 ) {
F_37 ( L_26 , - error ) ;
goto error;
}
}
memcpy ( & V_56 -> V_241 , & V_217 -> V_241 , sizeof( V_56 -> V_241 ) ) ;
F_37 ( L_27 ,
( unsigned long long ) V_56 -> V_241 . V_242 ,
( unsigned long long ) V_56 -> V_241 . V_243 ) ;
F_92 ( V_56 ) ;
V_56 -> V_244 = V_245 ;
F_110 ( V_217 ) ;
return V_56 ;
error:
F_110 ( V_217 ) ;
F_104 ( V_56 ) ;
return F_11 ( error ) ;
}
struct V_1 *
F_111 ( const struct V_59 * V_24 )
{
struct V_1 * V_2 ;
F_3 ( & V_11 ) ;
F_58 (clp, &nfs_client_list, cl_share_link) {
if ( F_56 ( V_24 , V_2 , 0 ) == false )
continue;
F_59 ( & V_2 -> V_20 ) ;
F_5 ( & V_11 ) ;
return V_2 ;
}
F_5 ( & V_11 ) ;
return NULL ;
}
struct V_1 *
F_112 ( int V_246 )
{
struct V_1 * V_2 ;
F_3 ( & V_11 ) ;
V_2 = F_113 ( & V_8 , V_246 ) ;
if ( V_2 )
F_59 ( & V_2 -> V_20 ) ;
F_5 ( & V_11 ) ;
return V_2 ;
}
struct V_1 *
F_114 ( const struct V_59 * V_24 ,
struct V_247 * V_248 )
{
struct V_1 * V_2 ;
F_3 ( & V_11 ) ;
F_58 (clp, &nfs_client_list, cl_share_link) {
if ( F_56 ( V_24 , V_2 , 1 ) == false )
continue;
if ( ! F_22 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_49 -> V_249 . V_79 ,
V_248 -> V_79 , V_250 ) != 0 )
continue;
F_59 ( & V_2 -> V_20 ) ;
F_5 ( & V_11 ) ;
return V_2 ;
}
F_5 ( & V_11 ) ;
return NULL ;
}
struct V_1 *
F_114 ( const struct V_59 * V_24 ,
struct V_247 * V_248 )
{
return NULL ;
}
static int F_115 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_5 -> V_6 == 4 ) {
if ( F_22 ( V_2 ) ) {
error = F_116 (
V_2 -> V_31 -> V_251 ,
V_252 ) ;
if ( error < 0 )
return error ;
}
error = F_117 ( V_2 -> V_44 -> V_52 ,
V_2 -> V_31 -> V_251 ) ;
if ( error < 0 ) {
F_37 ( L_28 ,
V_131 , error ) ;
return error ;
}
F_118 ( V_50 , & V_2 -> V_51 ) ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
#if F_18 ( V_47 )
if ( V_2 -> V_44 -> V_52 ) {
struct V_253 * V_254 = NULL ;
V_254 = F_120 ( V_2 ) ;
if ( ! V_254 )
return - V_10 ;
V_2 -> V_49 = V_254 ;
V_2 -> V_21 = V_78 ;
}
#endif
return F_115 ( V_2 ) ;
}
int F_121 ( struct V_1 * V_2 ,
const struct V_81 * V_82 ,
const char * V_83 ,
T_2 V_84 ,
int V_85 )
{
int error ;
if ( V_2 -> V_21 == V_77 ) {
F_37 ( L_29 , V_2 ) ;
return 0 ;
}
V_2 -> V_5 = & V_255 ;
error = F_69 ( V_2 , V_82 , V_84 ,
1 , V_85 ) ;
if ( error < 0 )
goto error;
F_122 ( V_2 -> V_256 , V_83 , sizeof( V_2 -> V_256 ) ) ;
error = F_123 ( V_2 ) ;
if ( error < 0 ) {
F_37 ( L_30 ,
V_131 , error ) ;
goto error;
}
F_118 ( V_54 , & V_2 -> V_51 ) ;
error = F_119 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_22 ( V_2 ) )
F_64 ( V_2 , V_77 ) ;
return 0 ;
error:
F_64 ( V_2 , error ) ;
F_37 ( L_31 , error ) ;
return error ;
}
static int F_124 ( struct V_55 * V_56 ,
const char * V_27 ,
const struct V_59 * V_24 ,
const T_3 V_25 ,
const char * V_83 ,
T_2 V_84 ,
int V_34 , const struct V_81 * V_82 ,
T_1 V_3 )
{
struct V_14 V_15 = {
. V_27 = V_27 ,
. V_24 = V_24 ,
. V_25 = V_25 ,
. V_5 = & V_255 ,
. V_34 = V_34 ,
. V_3 = V_3 ,
} ;
struct V_1 * V_2 ;
int error ;
F_37 ( L_32 ) ;
V_2 = F_60 ( & V_15 , V_82 , V_83 , V_84 ,
V_56 -> V_128 & V_139 ) ;
if ( F_17 ( V_2 ) ) {
error = F_61 ( V_2 ) ;
goto error;
}
F_98 ( V_257 , & V_2 -> V_51 ) ;
V_56 -> V_1 = V_2 ;
F_37 ( L_33 , V_2 ) ;
return 0 ;
error:
F_37 ( L_34 , error ) ;
return error ;
}
struct V_1 * F_125 ( struct V_1 * V_258 ,
const struct V_59 * V_259 ,
int V_260 , int V_261 )
{
struct V_14 V_15 = {
. V_24 = V_259 ,
. V_25 = V_260 ,
. V_5 = & V_255 ,
. V_34 = V_261 ,
. V_3 = V_258 -> V_43 ,
} ;
struct V_81 V_262 = {
. V_98 = 15 * V_99 ,
. V_107 = 15 * V_99 ,
. V_100 = 1 ,
. V_108 = 1 ,
} ;
struct V_1 * V_2 ;
V_2 = F_60 ( & V_15 , & V_262 , V_258 -> V_256 ,
V_258 -> V_31 -> V_153 -> V_154 , 0 ) ;
F_37 ( L_35 , V_131 , V_2 ) ;
return V_2 ;
}
static void F_126 ( struct V_55 * V_56 )
{
#ifdef V_47
struct V_253 * V_263 ;
T_1 V_264 ;
T_1 V_265 ;
if ( ! F_22 ( V_56 -> V_1 ) )
return;
V_263 = V_56 -> V_1 -> V_49 ;
V_264 = V_263 -> V_266 . V_267 - V_268 ;
V_265 = V_263 -> V_266 . V_269 - V_270 ;
if ( V_56 -> V_174 > V_264 )
V_56 -> V_174 = V_264 ;
if ( V_56 -> V_175 > V_265 )
V_56 -> V_175 = V_265 ;
#endif
}
static int F_127 ( struct V_55 * V_56 ,
struct V_214 * V_215 )
{
struct V_216 * V_217 ;
int error ;
F_46 ( ! V_56 -> V_1 ) ;
F_46 ( ! V_56 -> V_1 -> V_5 ) ;
F_46 ( ! V_56 -> V_1 -> V_5 -> V_233 ) ;
if ( F_128 ( V_56 -> V_1 ) )
return - V_94 ;
V_217 = F_109 () ;
if ( V_217 == NULL )
return - V_10 ;
error = F_129 ( V_56 ) ;
if ( error < 0 )
goto V_271;
error = F_130 ( V_56 , V_215 ) ;
if ( error < 0 )
goto V_271;
F_37 ( L_27 ,
( unsigned long long ) V_56 -> V_241 . V_242 ,
( unsigned long long ) V_56 -> V_241 . V_243 ) ;
F_37 ( L_36 , V_215 -> V_272 ) ;
F_126 ( V_56 ) ;
error = F_89 ( V_56 , V_215 , V_217 ) ;
if ( error < 0 )
goto V_271;
if ( V_56 -> V_188 == 0 || V_56 -> V_188 > V_273 )
V_56 -> V_188 = V_273 ;
F_92 ( V_56 ) ;
V_56 -> V_244 = V_245 ;
V_271:
F_110 ( V_217 ) ;
return error ;
}
static int F_131 ( struct V_55 * V_56 ,
const struct V_160 * V_79 )
{
struct V_81 V_82 ;
int error ;
F_37 ( L_37 ) ;
F_67 ( & V_82 , V_79 -> V_55 . V_120 ,
V_79 -> V_96 , V_79 -> V_97 ) ;
V_56 -> V_128 = V_79 -> V_128 ;
V_56 -> V_148 |= V_274 | V_275 | V_276 ;
if ( ! ( V_79 -> V_128 & V_235 ) )
V_56 -> V_148 |= V_236 ;
V_56 -> V_163 = V_79 -> V_163 ;
error = F_124 ( V_56 ,
V_79 -> V_55 . V_27 ,
( const struct V_59 * ) & V_79 -> V_55 . V_121 ,
V_79 -> V_55 . V_25 ,
V_79 -> V_277 ,
V_79 -> V_181 [ 0 ] ,
V_79 -> V_55 . V_120 ,
& V_82 ,
V_79 -> V_3 ) ;
if ( error < 0 )
goto error;
if ( V_278 && V_79 -> V_181 [ 0 ] == V_159 )
V_56 -> V_148 |= V_279 ;
if ( V_79 -> V_174 )
V_56 -> V_174 = F_83 ( V_79 -> V_174 , NULL ) ;
if ( V_79 -> V_175 )
V_56 -> V_175 = F_83 ( V_79 -> V_175 , NULL ) ;
V_56 -> V_176 = V_79 -> V_176 * V_99 ;
V_56 -> V_177 = V_79 -> V_177 * V_99 ;
V_56 -> V_178 = V_79 -> V_178 * V_99 ;
V_56 -> V_179 = V_79 -> V_179 * V_99 ;
V_56 -> V_180 = V_79 -> V_55 . V_180 ;
error = F_77 ( V_56 , & V_82 , V_79 -> V_181 [ 0 ] ) ;
error:
F_37 ( L_38 , error ) ;
return error ;
}
struct V_55 * F_132 ( const struct V_160 * V_79 ,
struct V_214 * V_215 )
{
struct V_55 * V_56 ;
int error ;
F_37 ( L_39 ) ;
V_56 = F_100 () ;
if ( ! V_56 )
return F_11 ( - V_10 ) ;
error = F_131 ( V_56 , V_79 ) ;
if ( error < 0 )
goto error;
error = F_127 ( V_56 , V_215 ) ;
if ( error < 0 )
goto error;
F_37 ( L_40 , V_56 ) ;
return V_56 ;
error:
F_104 ( V_56 ) ;
F_37 ( L_41 , error ) ;
return F_11 ( error ) ;
}
struct V_55 * F_133 ( struct V_280 * V_79 ,
struct V_214 * V_215 )
{
struct V_1 * V_281 ;
struct V_55 * V_56 , * V_282 ;
int error ;
F_37 ( L_42 ) ;
V_56 = F_100 () ;
if ( ! V_56 )
return F_11 ( - V_10 ) ;
V_282 = F_134 ( V_79 -> V_283 ) ;
V_281 = V_282 -> V_1 ;
F_91 ( V_56 , V_282 ) ;
V_56 -> V_148 |= V_274 | V_275 ;
error = F_124 ( V_56 , V_79 -> V_27 ,
V_79 -> V_24 ,
V_79 -> V_25 ,
V_281 -> V_256 ,
V_79 -> V_127 ,
V_282 -> V_146 -> V_251 -> V_284 ,
V_282 -> V_146 -> V_152 ,
V_281 -> V_44 -> V_52 ) ;
if ( error < 0 )
goto error;
error = F_77 ( V_56 , V_282 -> V_146 -> V_152 , V_79 -> V_127 ) ;
if ( error < 0 )
goto error;
error = F_127 ( V_56 , V_215 ) ;
if ( error < 0 )
goto error;
F_37 ( L_43 , V_56 ) ;
return V_56 ;
error:
F_104 ( V_56 ) ;
F_37 ( L_44 , error ) ;
return F_11 ( error ) ;
}
struct V_55 * F_135 ( struct V_55 * V_225 ,
struct V_214 * V_285 ,
struct V_216 * V_217 )
{
struct V_55 * V_56 ;
struct V_216 * V_286 ;
int error ;
F_37 ( L_45 ,
( unsigned long long ) V_217 -> V_241 . V_242 ,
( unsigned long long ) V_217 -> V_241 . V_243 ) ;
V_56 = F_100 () ;
if ( ! V_56 )
return F_11 ( - V_10 ) ;
error = - V_10 ;
V_286 = F_109 () ;
if ( V_286 == NULL )
goto V_287;
V_56 -> V_1 = V_225 -> V_1 ;
F_59 ( & V_56 -> V_1 -> V_20 ) ;
F_91 ( V_56 , V_225 ) ;
V_56 -> V_241 = V_217 -> V_241 ;
error = F_77 ( V_56 ,
V_225 -> V_146 -> V_152 ,
V_225 -> V_146 -> V_153 -> V_154 ) ;
if ( error < 0 )
goto V_287;
if ( ! F_17 ( V_225 -> V_145 ) )
F_75 ( V_56 ) ;
error = F_89 ( V_56 , V_285 , V_286 ) ;
if ( error < 0 )
goto V_287;
if ( V_56 -> V_188 == 0 || V_56 -> V_188 > V_273 )
V_56 -> V_188 = V_273 ;
F_37 ( L_46 ,
( unsigned long long ) V_56 -> V_241 . V_242 ,
( unsigned long long ) V_56 -> V_241 . V_243 ) ;
error = F_73 ( V_56 ) ;
if ( error < 0 )
goto V_287;
F_92 ( V_56 ) ;
V_56 -> V_244 = V_245 ;
F_110 ( V_286 ) ;
F_37 ( L_47 , V_56 ) ;
return V_56 ;
V_287:
F_110 ( V_286 ) ;
F_104 ( V_56 ) ;
F_37 ( L_48 , error ) ;
return F_11 ( error ) ;
}
static int F_136 ( struct V_288 * V_288 , struct V_289 * V_289 )
{
struct V_290 * V_291 ;
int V_4 ;
V_4 = F_137 ( V_289 , & V_292 ) ;
if ( V_4 < 0 )
return V_4 ;
V_291 = V_289 -> V_293 ;
V_291 -> V_294 = F_138 ( V_288 ) -> V_79 ;
return 0 ;
}
static void * F_139 ( struct V_290 * V_291 , T_4 * V_295 )
{
F_3 ( & V_11 ) ;
return F_140 ( & V_89 , * V_295 ) ;
}
static void * F_141 ( struct V_290 * V_296 , void * V_297 , T_4 * V_298 )
{
return F_142 ( V_297 , & V_89 , V_298 ) ;
}
static void F_143 ( struct V_290 * V_296 , void * V_297 )
{
F_5 ( & V_11 ) ;
}
static int F_144 ( struct V_290 * V_291 , void * V_297 )
{
struct V_1 * V_2 ;
if ( V_297 == & V_89 ) {
F_145 ( V_291 , L_49 ) ;
return 0 ;
}
V_2 = F_146 ( V_297 , struct V_1 , V_58 ) ;
F_147 ( V_291 , L_50 ,
V_2 -> V_5 -> V_6 ,
F_148 ( V_2 -> V_31 , V_299 ) ,
F_148 ( V_2 -> V_31 , V_300 ) ,
F_43 ( & V_2 -> V_20 ) ,
V_2 -> V_28 ) ;
return 0 ;
}
static int F_149 ( struct V_288 * V_288 , struct V_289 * V_289 )
{
struct V_290 * V_291 ;
int V_4 ;
V_4 = F_137 ( V_289 , & V_301 ) ;
if ( V_4 < 0 )
return V_4 ;
V_291 = V_289 -> V_293 ;
V_291 -> V_294 = F_138 ( V_288 ) -> V_79 ;
return 0 ;
}
static void * F_150 ( struct V_290 * V_291 , T_4 * V_295 )
{
F_3 ( & V_11 ) ;
return F_140 ( & V_228 , * V_295 ) ;
}
static void * F_151 ( struct V_290 * V_296 , void * V_297 , T_4 * V_298 )
{
return F_142 ( V_297 , & V_228 , V_298 ) ;
}
static void F_152 ( struct V_290 * V_296 , void * V_297 )
{
F_5 ( & V_11 ) ;
}
static int F_153 ( struct V_290 * V_291 , void * V_297 )
{
struct V_55 * V_56 ;
struct V_1 * V_2 ;
char V_302 [ 8 ] , V_241 [ 17 ] ;
if ( V_297 == & V_228 ) {
F_145 ( V_291 , L_51 ) ;
return 0 ;
}
V_56 = F_146 ( V_297 , struct V_55 , V_227 ) ;
V_2 = V_56 -> V_1 ;
snprintf ( V_302 , 8 , L_52 ,
F_154 ( V_56 -> V_303 ) , F_155 ( V_56 -> V_303 ) ) ;
snprintf ( V_241 , 17 , L_53 ,
( unsigned long long ) V_56 -> V_241 . V_242 ,
( unsigned long long ) V_56 -> V_241 . V_243 ) ;
F_147 ( V_291 , L_54 ,
V_2 -> V_5 -> V_6 ,
F_148 ( V_2 -> V_31 , V_299 ) ,
F_148 ( V_2 -> V_31 , V_300 ) ,
V_302 ,
V_241 ,
F_156 ( V_56 ) ) ;
return 0 ;
}
int T_5 F_157 ( void )
{
struct V_304 * V_296 ;
V_305 = F_158 ( L_55 , NULL ) ;
if ( ! V_305 )
goto V_19;
V_296 = F_159 ( L_56 , V_306 | V_307 ,
V_305 , & V_308 ) ;
if ( ! V_296 )
goto V_309;
V_296 = F_159 ( L_57 , V_306 | V_307 ,
V_305 , & V_310 ) ;
if ( ! V_296 )
goto V_311;
return 0 ;
V_311:
F_160 ( L_56 , V_305 ) ;
V_309:
F_160 ( L_55 , NULL ) ;
V_19:
return - V_10 ;
}
void F_161 ( void )
{
F_160 ( L_57 , V_305 ) ;
F_160 ( L_56 , V_305 ) ;
F_160 ( L_55 , NULL ) ;
}
