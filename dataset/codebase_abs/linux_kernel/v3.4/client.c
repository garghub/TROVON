static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( V_2 -> V_9 -> V_10 != 4 || V_3 != 0 )
return V_4 ;
V_11:
if ( ! F_3 ( & V_6 -> V_12 , V_13 ) )
return - V_14 ;
F_4 ( & V_6 -> V_15 ) ;
V_4 = F_5 ( & V_6 -> V_12 , V_2 , & V_2 -> V_16 ) ;
F_6 ( & V_6 -> V_15 ) ;
if ( V_4 == - V_17 )
goto V_11;
return V_4 ;
}
static struct V_1 * F_7 ( const struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_22 = - V_14 ;
if ( ( V_2 = F_8 ( sizeof( * V_2 ) , V_13 ) ) == NULL )
goto V_23;
V_2 -> V_9 = V_19 -> V_9 ;
F_9 ( & V_2 -> V_24 , 1 ) ;
V_2 -> V_25 = V_26 ;
memcpy ( & V_2 -> V_27 , V_19 -> V_28 , V_19 -> V_29 ) ;
V_2 -> V_30 = V_19 -> V_29 ;
if ( V_19 -> V_31 ) {
V_22 = - V_14 ;
V_2 -> V_32 = F_10 ( V_19 -> V_31 , V_13 ) ;
if ( ! V_2 -> V_32 )
goto V_33;
}
F_11 ( & V_2 -> V_34 ) ;
V_2 -> V_35 = F_12 ( - V_36 ) ;
V_2 -> V_37 = V_19 -> V_38 ;
V_2 -> V_7 = F_13 ( V_19 -> V_7 ) ;
#ifdef F_14
V_22 = F_1 ( V_2 , V_19 -> V_3 ) ;
if ( V_22 )
goto V_33;
F_15 ( & V_2 -> V_39 ) ;
F_16 ( & V_2 -> V_40 , V_41 ) ;
F_17 ( & V_2 -> V_42 , L_1 ) ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = 1 << V_46 ;
V_2 -> V_47 = V_19 -> V_3 ;
V_2 -> V_48 = V_49 [ V_19 -> V_3 ] ;
#endif
V_21 = F_18 ( L_2 ) ;
if ( ! F_19 ( V_21 ) )
V_2 -> V_50 = V_21 ;
F_20 ( V_2 ) ;
return V_2 ;
V_33:
F_21 ( V_2 ) ;
V_23:
return F_12 ( V_22 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( F_23 ( V_2 ) ) {
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_51 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
}
static void F_26 ( struct V_1 * V_2 )
{
if ( F_27 ( V_52 , & V_2 -> V_53 ) )
F_28 ( V_2 -> V_48 -> V_54 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( F_27 ( V_55 , & V_2 -> V_53 ) )
F_30 ( V_2 ) ;
F_22 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( F_27 ( V_56 , & V_2 -> V_53 ) )
F_31 ( V_2 ) ;
F_32 ( & V_2 -> V_42 ) ;
}
void F_33 ( struct V_7 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 , V_8 ) ;
F_34 ( & V_6 -> V_12 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( V_2 -> V_16 )
F_36 ( & V_6 -> V_12 , V_2 -> V_16 ) ;
}
static void F_37 ( struct V_57 * V_58 )
{
F_17 ( & V_58 -> V_59 , L_3 ) ;
}
static void F_38 ( struct V_57 * V_58 )
{
F_39 ( V_58 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
}
void F_33 ( struct V_7 * V_7 )
{
}
static void F_35 ( struct V_1 * V_2 )
{
}
static void F_37 ( struct V_57 * V_58 )
{
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( L_4 , V_2 -> V_9 -> V_10 ) ;
F_29 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( ! F_19 ( V_2 -> V_35 ) )
F_43 ( V_2 -> V_35 ) ;
if ( V_2 -> V_50 != NULL )
F_44 ( V_2 -> V_50 ) ;
F_45 ( V_2 -> V_7 ) ;
F_21 ( V_2 -> V_32 ) ;
F_21 ( V_2 -> V_60 ) ;
F_21 ( V_2 -> V_61 ) ;
F_21 ( V_2 ) ;
F_41 ( L_5 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
if ( ! V_2 )
return;
F_41 ( L_6 , F_47 ( & V_2 -> V_24 ) ) ;
V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( F_48 ( & V_2 -> V_24 , & V_6 -> V_15 ) ) {
F_49 ( & V_2 -> V_62 ) ;
F_35 ( V_2 ) ;
F_6 ( & V_6 -> V_15 ) ;
F_50 ( ! F_51 ( & V_2 -> V_34 ) ) ;
F_40 ( V_2 ) ;
}
}
static int F_52 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_64 ;
const struct V_66 * V_68 = ( const struct V_66 * ) V_65 ;
if ( ! F_53 ( & V_67 -> V_69 , & V_68 -> V_69 ) )
return 0 ;
else if ( F_54 ( & V_67 -> V_69 ) & V_70 )
return V_67 -> V_71 == V_68 -> V_71 ;
return 1 ;
}
static int F_52 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
return 0 ;
}
static int F_55 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_72 * V_67 = ( const struct V_72 * ) V_64 ;
const struct V_72 * V_68 = ( const struct V_72 * ) V_65 ;
return V_67 -> V_73 . V_74 == V_68 -> V_73 . V_74 ;
}
static int F_56 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_64 ;
const struct V_66 * V_68 = ( const struct V_66 * ) V_65 ;
return F_52 ( V_64 , V_65 ) &&
( V_67 -> V_75 == V_68 -> V_75 ) ;
}
static int F_57 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
const struct V_72 * V_67 = ( const struct V_72 * ) V_64 ;
const struct V_72 * V_68 = ( const struct V_72 * ) V_65 ;
return F_55 ( V_64 , V_65 ) &&
( V_67 -> V_76 == V_68 -> V_76 ) ;
}
static int F_58 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
if ( V_64 -> V_77 != V_65 -> V_77 )
return 0 ;
switch ( V_64 -> V_77 ) {
case V_78 :
return F_55 ( V_64 , V_65 ) ;
case V_79 :
return F_52 ( V_64 , V_65 ) ;
}
return 0 ;
}
static int F_59 ( const struct V_63 * V_64 ,
const struct V_63 * V_65 )
{
if ( V_64 -> V_77 != V_65 -> V_77 )
return 0 ;
switch ( V_64 -> V_77 ) {
case V_78 :
return F_57 ( V_64 , V_65 ) ;
case V_79 :
return F_56 ( V_64 , V_65 ) ;
}
return 0 ;
}
static bool F_60 ( const struct V_63 * V_28 ,
struct V_1 * V_2 , T_1 V_3 )
{
struct V_63 * V_80 = (struct V_63 * ) & V_2 -> V_27 ;
if ( ! ( V_2 -> V_25 == V_81 ||
V_2 -> V_25 == V_82 ) )
return false ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
if ( ! F_58 ( V_28 , V_80 ) )
return false ;
return true ;
}
static struct V_1 * F_61 ( const struct V_18 * V_83 )
{
struct V_1 * V_2 ;
const struct V_63 * V_84 = V_83 -> V_28 ;
struct V_5 * V_6 = F_2 ( V_83 -> V_7 , V_8 ) ;
F_62 (clp, &nn->nfs_client_list, cl_share_link) {
const struct V_63 * V_80 = (struct V_63 * ) & V_2 -> V_27 ;
if ( V_2 -> V_25 < 0 )
continue;
if ( V_2 -> V_9 != V_83 -> V_9 )
continue;
if ( V_2 -> V_37 != V_83 -> V_38 )
continue;
if ( V_2 -> V_47 != V_83 -> V_3 )
continue;
if ( ! F_59 ( V_84 , V_80 ) )
continue;
F_63 ( & V_2 -> V_24 ) ;
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_64 ( const struct V_18 * V_19 ,
const struct V_85 * V_86 ,
const char * V_87 ,
T_2 V_88 ,
int V_89 )
{
struct V_1 * V_2 , * V_90 = NULL ;
int error ;
struct V_5 * V_6 = F_2 ( V_19 -> V_7 , V_8 ) ;
F_41 ( L_7 ,
V_19 -> V_31 ? : L_8 , V_19 -> V_9 -> V_10 ) ;
do {
F_4 ( & V_6 -> V_15 ) ;
V_2 = F_61 ( V_19 ) ;
if ( V_2 )
goto V_91;
if ( V_90 )
goto V_92;
F_6 ( & V_6 -> V_15 ) ;
V_90 = F_7 ( V_19 ) ;
} while ( ! F_19 ( V_90 ) );
F_41 ( L_9 , F_65 ( V_90 ) ) ;
return V_90 ;
V_92:
V_2 = V_90 ;
F_66 ( & V_2 -> V_62 , & V_6 -> V_93 ) ;
F_6 ( & V_6 -> V_15 ) ;
error = V_19 -> V_9 -> V_94 ( V_2 , V_86 , V_87 ,
V_88 , V_89 ) ;
if ( error < 0 ) {
F_46 ( V_2 ) ;
return F_12 ( error ) ;
}
F_41 ( L_10 , V_2 ) ;
return V_2 ;
V_91:
F_6 ( & V_6 -> V_15 ) ;
if ( V_90 )
F_40 ( V_90 ) ;
error = F_67 ( V_95 ,
V_2 -> V_25 < V_26 ) ;
if ( error < 0 ) {
F_46 ( V_2 ) ;
return F_12 ( - V_96 ) ;
}
if ( V_2 -> V_25 < V_81 ) {
error = V_2 -> V_25 ;
F_46 ( V_2 ) ;
return F_12 ( error ) ;
}
F_50 ( V_2 -> V_25 != V_81 ) ;
F_41 ( L_11 , V_2 ) ;
return V_2 ;
}
void F_68 ( struct V_1 * V_2 , int V_97 )
{
V_2 -> V_25 = V_97 ;
F_69 ( & V_95 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
if ( ! F_23 ( V_2 ) )
return 0 ;
if ( V_2 -> V_25 < V_81 )
return - V_98 ;
return 0 ;
}
static void F_71 ( struct V_85 * V_99 , int V_38 ,
unsigned int V_100 , unsigned int V_101 )
{
V_99 -> V_102 = V_100 * V_103 / 10 ;
V_99 -> V_104 = V_101 ;
switch ( V_38 ) {
case V_105 :
case V_106 :
if ( V_99 -> V_104 == 0 )
V_99 -> V_104 = V_107 ;
if ( V_99 -> V_102 == 0 )
V_99 -> V_102 = V_108 * V_103 / 10 ;
if ( V_99 -> V_102 > V_109 )
V_99 -> V_102 = V_109 ;
V_99 -> V_110 = V_99 -> V_102 ;
V_99 -> V_111 = V_99 -> V_102 + ( V_99 -> V_110 * V_99 -> V_104 ) ;
if ( V_99 -> V_111 > V_109 )
V_99 -> V_111 = V_109 ;
if ( V_99 -> V_111 < V_99 -> V_102 )
V_99 -> V_111 = V_99 -> V_102 ;
V_99 -> V_112 = 0 ;
break;
case V_113 :
if ( V_99 -> V_104 == 0 )
V_99 -> V_104 = V_114 ;
if ( ! V_99 -> V_102 )
V_99 -> V_102 = V_115 * V_103 / 10 ;
if ( V_99 -> V_102 > V_116 )
V_99 -> V_102 = V_116 ;
V_99 -> V_111 = V_116 ;
V_99 -> V_112 = 1 ;
break;
default:
F_72 () ;
}
}
static int F_73 ( struct V_1 * V_2 ,
const struct V_85 * V_86 ,
T_2 V_117 ,
int V_118 , int V_89 )
{
struct V_119 * V_120 = NULL ;
struct V_121 args = {
. V_7 = V_2 -> V_7 ,
. V_122 = V_2 -> V_37 ,
. V_123 = (struct V_63 * ) & V_2 -> V_27 ,
. V_124 = V_2 -> V_30 ,
. V_125 = V_86 ,
. V_126 = V_2 -> V_32 ,
. V_127 = & V_128 ,
. V_10 = V_2 -> V_9 -> V_10 ,
. V_129 = V_117 ,
} ;
if ( V_118 )
args . V_130 |= V_131 ;
if ( V_89 )
args . V_130 |= V_132 ;
if ( ! F_19 ( V_2 -> V_35 ) )
return 0 ;
V_120 = F_74 ( & args ) ;
if ( F_19 ( V_120 ) ) {
F_41 ( L_12 ,
V_133 , F_65 ( V_120 ) ) ;
return F_65 ( V_120 ) ;
}
V_2 -> V_35 = V_120 ;
return 0 ;
}
static void F_75 ( struct V_57 * V_58 )
{
if ( ! ( V_58 -> V_130 & V_134 ) ||
! ( V_58 -> V_130 & V_135 ) )
F_76 ( V_58 -> V_136 ) ;
}
static int F_77 ( struct V_57 * V_58 )
{
struct V_136 * V_137 ;
struct V_1 * V_2 = V_58 -> V_1 ;
struct V_138 V_139 = {
. V_31 = V_2 -> V_32 ,
. V_123 = (struct V_63 * ) & V_2 -> V_27 ,
. V_29 = V_2 -> V_30 ,
. V_140 = V_2 -> V_9 -> V_10 ,
. V_89 = V_58 -> V_130 & V_141 ?
1 : 0 ,
. V_7 = V_2 -> V_7 ,
} ;
if ( V_139 . V_140 > 3 )
return 0 ;
if ( ( V_58 -> V_130 & V_134 ) &&
( V_58 -> V_130 & V_135 ) )
return 0 ;
switch ( V_2 -> V_37 ) {
default:
V_139 . V_122 = V_142 ;
break;
case V_113 :
V_139 . V_122 = V_143 ;
}
V_137 = F_78 ( & V_139 ) ;
if ( F_19 ( V_137 ) )
return F_65 ( V_137 ) ;
V_58 -> V_136 = V_137 ;
V_58 -> V_144 = F_75 ;
return 0 ;
}
static void F_79 ( struct V_57 * V_58 )
{
if ( V_58 -> V_1 -> V_9 -> V_10 != 3 )
goto V_145;
if ( V_58 -> V_130 & V_146 )
goto V_145;
V_58 -> V_147 = F_80 ( V_58 -> V_148 , & V_149 , 3 ) ;
if ( F_19 ( V_58 -> V_147 ) )
goto V_145;
V_58 -> V_150 |= V_151 ;
return;
V_145:
V_58 -> V_150 &= ~ V_151 ;
}
static inline void F_79 ( struct V_57 * V_58 )
{
V_58 -> V_130 &= ~ V_146 ;
V_58 -> V_150 &= ~ V_151 ;
}
static int F_81 ( struct V_57 * V_58 ,
const struct V_85 * V_100 ,
T_2 V_152 )
{
struct V_1 * V_2 = V_58 -> V_1 ;
V_58 -> V_148 = F_82 ( V_2 -> V_35 ) ;
if ( F_19 ( V_58 -> V_148 ) ) {
F_41 ( L_13 , V_133 ) ;
return F_65 ( V_58 -> V_148 ) ;
}
memcpy ( & V_58 -> V_148 -> V_153 ,
V_100 ,
sizeof( V_58 -> V_148 -> V_153 ) ) ;
V_58 -> V_148 -> V_154 = & V_58 -> V_148 -> V_153 ;
if ( V_152 != V_2 -> V_35 -> V_155 -> V_156 ) {
struct V_157 * V_158 ;
V_158 = F_83 ( V_152 , V_58 -> V_148 ) ;
if ( F_19 ( V_158 ) ) {
F_41 ( L_14 , V_133 ) ;
return F_65 ( V_158 ) ;
}
}
V_58 -> V_148 -> V_159 = 0 ;
if ( V_58 -> V_130 & V_160 )
V_58 -> V_148 -> V_159 = 1 ;
return 0 ;
}
int F_84 ( struct V_1 * V_2 , const struct V_85 * V_86 ,
const char * V_87 , T_2 V_88 ,
int V_89 )
{
int error ;
if ( V_2 -> V_25 == V_81 ) {
F_41 ( L_15 , V_2 ) ;
return 0 ;
}
error = F_73 ( V_2 , V_86 , V_161 ,
0 , V_89 ) ;
if ( error < 0 )
goto error;
F_68 ( V_2 , V_81 ) ;
return 0 ;
error:
F_68 ( V_2 , error ) ;
F_41 ( L_16 , error ) ;
return error ;
}
static int F_85 ( struct V_57 * V_58 ,
const struct V_162 * V_83 )
{
struct V_18 V_19 = {
. V_31 = V_83 -> V_57 . V_31 ,
. V_28 = ( const struct V_63 * ) & V_83 -> V_57 . V_123 ,
. V_29 = V_83 -> V_57 . V_29 ,
. V_9 = & V_163 ,
. V_38 = V_83 -> V_57 . V_122 ,
. V_7 = V_83 -> V_7 ,
} ;
struct V_85 V_86 ;
struct V_1 * V_2 ;
int error ;
F_41 ( L_17 ) ;
#ifdef F_86
if ( V_83 -> V_10 == 3 )
V_19 . V_9 = & V_164 ;
#endif
F_71 ( & V_86 , V_83 -> V_57 . V_122 ,
V_83 -> V_100 , V_83 -> V_101 ) ;
V_2 = F_64 ( & V_19 , & V_86 , NULL , V_161 ,
V_83 -> V_130 & V_141 ) ;
if ( F_19 ( V_2 ) ) {
F_41 ( L_18 , F_65 ( V_2 ) ) ;
return F_65 ( V_2 ) ;
}
V_58 -> V_1 = V_2 ;
V_58 -> V_130 = V_83 -> V_130 ;
V_58 -> V_165 = V_83 -> V_165 ;
V_58 -> V_150 |= V_166 | V_167 | V_168 |
V_169 | V_170 | V_171 | V_172 |
V_173 | V_174 | V_175 ;
if ( V_83 -> V_176 )
V_58 -> V_176 = F_87 ( V_83 -> V_176 , NULL ) ;
if ( V_83 -> V_177 )
V_58 -> V_177 = F_87 ( V_83 -> V_177 , NULL ) ;
V_58 -> V_178 = V_83 -> V_178 * V_103 ;
V_58 -> V_179 = V_83 -> V_179 * V_103 ;
V_58 -> V_180 = V_83 -> V_180 * V_103 ;
V_58 -> V_181 = V_83 -> V_181 * V_103 ;
error = F_77 ( V_58 ) ;
if ( error < 0 )
goto error;
V_58 -> V_182 = V_83 -> V_57 . V_182 ;
error = F_81 ( V_58 , & V_86 , V_83 -> V_183 [ 0 ] ) ;
if ( error < 0 )
goto error;
if ( V_83 -> V_184 . V_29 ) {
memcpy ( & V_58 -> V_185 , & V_83 -> V_184 . V_123 ,
V_83 -> V_184 . V_29 ) ;
V_58 -> V_186 = V_83 -> V_184 . V_29 ;
}
V_58 -> V_187 = V_83 -> V_184 . V_10 ;
V_58 -> V_188 = V_83 -> V_184 . V_182 ;
V_58 -> V_189 = V_83 -> V_184 . V_122 ;
V_58 -> V_190 = V_83 -> V_191 ;
F_79 ( V_58 ) ;
F_41 ( L_19 , V_2 ) ;
return 0 ;
error:
V_58 -> V_1 = NULL ;
F_46 ( V_2 ) ;
F_41 ( L_20 , error ) ;
return error ;
}
static void F_88 ( struct V_57 * V_58 ,
struct V_192 * V_193 ,
struct V_194 * V_195 )
{
unsigned long V_196 ;
if ( V_58 -> V_176 == 0 )
V_58 -> V_176 = F_87 ( V_195 -> V_197 , NULL ) ;
if ( V_58 -> V_177 == 0 )
V_58 -> V_177 = F_87 ( V_195 -> V_198 , NULL ) ;
if ( V_195 -> V_199 >= 512 && V_58 -> V_176 > V_195 -> V_199 )
V_58 -> V_176 = F_87 ( V_195 -> V_199 , NULL ) ;
if ( V_195 -> V_200 >= 512 && V_58 -> V_177 > V_195 -> V_200 )
V_58 -> V_177 = F_87 ( V_195 -> V_200 , NULL ) ;
V_196 = F_87 ( F_89 ( V_58 -> V_148 ) , NULL ) ;
if ( V_58 -> V_176 > V_196 )
V_58 -> V_176 = V_196 ;
if ( V_58 -> V_176 > V_201 )
V_58 -> V_176 = V_201 ;
V_58 -> V_202 = ( V_58 -> V_176 + V_203 - 1 ) >> V_204 ;
V_58 -> V_205 . V_206 = L_21 ;
V_58 -> V_205 . V_207 = V_58 -> V_202 * V_208 ;
if ( V_58 -> V_177 > V_196 )
V_58 -> V_177 = V_196 ;
if ( V_58 -> V_177 > V_201 )
V_58 -> V_177 = V_201 ;
V_58 -> V_209 = ( V_58 -> V_177 + V_203 - 1 ) >> V_204 ;
V_58 -> V_210 = V_195 -> V_211 ;
F_90 ( V_58 , V_193 , V_195 -> V_212 ) ;
V_58 -> V_213 = F_91 ( V_195 -> V_213 , NULL ) ;
V_58 -> V_214 = F_87 ( V_195 -> V_215 , NULL ) ;
if ( V_58 -> V_214 > V_203 * V_216 )
V_58 -> V_214 = V_203 * V_216 ;
if ( V_58 -> V_214 > V_58 -> V_176 )
V_58 -> V_214 = V_58 -> V_176 ;
if ( V_58 -> V_130 & V_217 ) {
V_58 -> V_178 = V_58 -> V_179 = 0 ;
V_58 -> V_180 = V_58 -> V_181 = 0 ;
}
V_58 -> V_218 = V_195 -> V_218 ;
V_58 -> V_219 = V_195 -> V_219 ;
F_92 ( V_58 -> V_148 , V_58 -> V_177 + 100 , V_58 -> V_176 + 100 ) ;
}
static int F_93 ( struct V_57 * V_58 , struct V_192 * V_193 , struct V_220 * V_221 )
{
struct V_194 V_195 ;
struct V_1 * V_2 = V_58 -> V_1 ;
int error ;
F_41 ( L_22 ) ;
if ( V_2 -> V_9 -> V_222 != NULL ) {
error = V_2 -> V_9 -> V_222 ( V_58 , V_193 ) ;
if ( error < 0 )
goto V_223;
}
V_195 . V_221 = V_221 ;
V_195 . V_212 = 0 ;
error = V_2 -> V_9 -> V_195 ( V_58 , V_193 , & V_195 ) ;
if ( error < 0 )
goto V_223;
F_88 ( V_58 , V_193 , & V_195 ) ;
if ( V_58 -> V_190 == 0 ) {
struct V_224 V_225 ;
V_225 . V_221 = V_221 ;
F_94 ( V_221 ) ;
if ( V_2 -> V_9 -> V_226 ( V_58 , V_193 , & V_225 ) >= 0 )
V_58 -> V_190 = V_225 . V_227 ;
}
F_41 ( L_23 ) ;
return 0 ;
V_223:
F_41 ( L_24 , - error ) ;
return error ;
}
static void F_95 ( struct V_57 * V_228 , struct V_57 * V_229 )
{
V_228 -> V_130 = V_229 -> V_130 ;
V_228 -> V_176 = V_229 -> V_176 ;
V_228 -> V_177 = V_229 -> V_177 ;
V_228 -> V_178 = V_229 -> V_178 ;
V_228 -> V_179 = V_229 -> V_179 ;
V_228 -> V_180 = V_229 -> V_180 ;
V_228 -> V_181 = V_229 -> V_181 ;
V_228 -> V_150 = V_229 -> V_150 ;
V_228 -> V_165 = V_229 -> V_165 ;
}
static void F_96 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_1 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_97 ( & V_58 -> V_230 , & V_2 -> V_34 ) ;
F_98 ( & V_58 -> V_231 , & V_6 -> V_232 ) ;
F_99 ( V_233 , & V_2 -> V_53 ) ;
F_6 ( & V_6 -> V_15 ) ;
}
static void F_100 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_1 ;
struct V_5 * V_6 ;
if ( V_2 == NULL )
return;
V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_101 ( & V_58 -> V_230 ) ;
if ( F_51 ( & V_2 -> V_34 ) )
F_102 ( V_233 , & V_2 -> V_53 ) ;
F_49 ( & V_58 -> V_231 ) ;
F_6 ( & V_6 -> V_15 ) ;
F_103 () ;
}
static struct V_57 * F_104 ( void )
{
struct V_57 * V_58 ;
V_58 = F_8 ( sizeof( struct V_57 ) , V_13 ) ;
if ( ! V_58 )
return NULL ;
V_58 -> V_148 = V_58 -> V_147 = F_12 ( - V_36 ) ;
F_11 ( & V_58 -> V_230 ) ;
F_11 ( & V_58 -> V_231 ) ;
F_11 ( & V_58 -> V_234 ) ;
F_11 ( & V_58 -> V_235 ) ;
F_11 ( & V_58 -> V_236 ) ;
F_9 ( & V_58 -> V_237 , 0 ) ;
V_58 -> V_238 = F_105 () ;
if ( ! V_58 -> V_238 ) {
F_21 ( V_58 ) ;
return NULL ;
}
if ( F_106 ( & V_58 -> V_205 ) ) {
F_107 ( V_58 -> V_238 ) ;
F_21 ( V_58 ) ;
return NULL ;
}
F_108 ( & V_58 -> V_239 ) ;
F_108 ( & V_58 -> V_240 ) ;
F_37 ( V_58 ) ;
return V_58 ;
}
void F_109 ( struct V_57 * V_58 )
{
F_41 ( L_25 ) ;
F_100 ( V_58 ) ;
F_110 ( V_58 ) ;
if ( V_58 -> V_144 != NULL )
V_58 -> V_144 ( V_58 ) ;
if ( ! F_19 ( V_58 -> V_147 ) )
F_43 ( V_58 -> V_147 ) ;
if ( ! F_19 ( V_58 -> V_148 ) )
F_43 ( V_58 -> V_148 ) ;
F_46 ( V_58 -> V_1 ) ;
F_111 ( & V_58 -> V_240 ) ;
F_111 ( & V_58 -> V_239 ) ;
F_107 ( V_58 -> V_238 ) ;
F_112 ( & V_58 -> V_205 ) ;
F_21 ( V_58 ) ;
F_113 () ;
F_41 ( L_26 ) ;
}
struct V_57 * F_114 ( const struct V_162 * V_83 ,
struct V_192 * V_193 )
{
struct V_57 * V_58 ;
struct V_220 * V_221 ;
int error ;
V_58 = F_104 () ;
if ( ! V_58 )
return F_12 ( - V_14 ) ;
error = - V_14 ;
V_221 = F_115 () ;
if ( V_221 == NULL )
goto error;
error = F_85 ( V_58 , V_83 ) ;
if ( error < 0 )
goto error;
F_50 ( ! V_58 -> V_1 ) ;
F_50 ( ! V_58 -> V_1 -> V_9 ) ;
F_50 ( ! V_58 -> V_1 -> V_9 -> V_241 ) ;
error = F_93 ( V_58 , V_193 , V_221 ) ;
if ( error < 0 )
goto error;
if ( V_58 -> V_1 -> V_9 -> V_10 == 3 ) {
if ( V_58 -> V_190 == 0 || V_58 -> V_190 > V_242 )
V_58 -> V_190 = V_242 ;
if ( ! ( V_83 -> V_130 & V_243 ) )
V_58 -> V_150 |= V_244 ;
} else {
if ( V_58 -> V_190 == 0 || V_58 -> V_190 > V_245 )
V_58 -> V_190 = V_245 ;
}
if ( ! ( V_221 -> V_246 & V_247 ) ) {
error = V_58 -> V_1 -> V_9 -> V_248 ( V_58 , V_193 , V_221 ) ;
if ( error < 0 ) {
F_41 ( L_27 , - error ) ;
goto error;
}
}
memcpy ( & V_58 -> V_249 , & V_221 -> V_249 , sizeof( V_58 -> V_249 ) ) ;
F_41 ( L_28 ,
( unsigned long long ) V_58 -> V_249 . V_250 ,
( unsigned long long ) V_58 -> V_249 . V_251 ) ;
F_96 ( V_58 ) ;
V_58 -> V_252 = V_253 ;
F_116 ( V_221 ) ;
return V_58 ;
error:
F_116 ( V_221 ) ;
F_109 ( V_58 ) ;
return F_12 ( error ) ;
}
struct V_1 *
F_117 ( struct V_7 * V_7 , int V_254 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_7 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
V_2 = F_118 ( & V_6 -> V_12 , V_254 ) ;
if ( V_2 )
F_63 ( & V_2 -> V_24 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
struct V_1 *
F_119 ( struct V_7 * V_7 , const struct V_63 * V_28 ,
struct V_255 * V_256 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_7 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_62 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_60 ( V_28 , V_2 , 1 ) == false )
continue;
if ( ! F_23 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_51 -> V_257 . V_83 ,
V_256 -> V_83 , V_258 ) != 0 )
continue;
F_63 ( & V_2 -> V_24 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_15 ) ;
return NULL ;
}
struct V_1 *
F_119 ( struct V_7 * V_7 , const struct V_63 * V_28 ,
struct V_255 * V_256 )
{
return NULL ;
}
static int F_120 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_9 -> V_10 == 4 ) {
struct V_259 * V_260 ;
V_260 = F_121 ( V_2 -> V_35 -> V_261 ) ;
if ( F_23 ( V_2 ) ) {
error = F_122 ( V_260 ,
V_262 ) ;
if ( error < 0 )
return error ;
}
error = F_123 ( V_2 -> V_48 -> V_54 , V_260 ) ;
if ( error < 0 ) {
F_41 ( L_29 ,
V_133 , error ) ;
return error ;
}
F_124 ( V_52 , & V_2 -> V_53 ) ;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
#if F_126 ( V_263 )
if ( V_2 -> V_48 -> V_54 ) {
struct V_264 * V_265 = NULL ;
V_265 = F_127 ( V_2 ) ;
if ( ! V_265 )
return - V_14 ;
V_2 -> V_51 = V_265 ;
V_2 -> V_25 = V_82 ;
}
#endif
return F_120 ( V_2 ) ;
}
int F_128 ( struct V_1 * V_2 ,
const struct V_85 * V_86 ,
const char * V_87 ,
T_2 V_88 ,
int V_89 )
{
char V_266 [ V_267 + 1 ] ;
int error ;
if ( V_2 -> V_25 == V_81 ) {
F_41 ( L_30 , V_2 ) ;
return 0 ;
}
V_2 -> V_9 = & V_268 ;
error = F_73 ( V_2 , V_86 , V_88 ,
1 , V_89 ) ;
if ( error < 0 )
goto error;
if ( V_87 == NULL ) {
struct V_269 V_270 ;
struct V_63 * V_84 = (struct V_63 * ) & V_270 ;
error = F_129 ( V_2 -> V_35 , V_84 , sizeof( V_270 ) ) ;
if ( error < 0 )
goto error;
error = F_130 ( V_84 , V_266 , sizeof( V_266 ) ) ;
if ( error < 0 )
goto error;
V_87 = ( const char * ) V_266 ;
}
F_131 ( V_2 -> V_271 , V_87 , sizeof( V_2 -> V_271 ) ) ;
error = F_132 ( V_2 ) ;
if ( error < 0 ) {
F_41 ( L_31 ,
V_133 , error ) ;
goto error;
}
F_124 ( V_56 , & V_2 -> V_53 ) ;
error = F_125 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_23 ( V_2 ) )
F_68 ( V_2 , V_81 ) ;
return 0 ;
error:
F_68 ( V_2 , error ) ;
F_41 ( L_32 , error ) ;
return error ;
}
static int F_133 ( struct V_57 * V_58 ,
const char * V_31 ,
const struct V_63 * V_28 ,
const T_3 V_29 ,
const char * V_87 ,
T_2 V_88 ,
int V_38 , const struct V_85 * V_86 ,
T_1 V_3 , struct V_7 * V_7 )
{
struct V_18 V_19 = {
. V_31 = V_31 ,
. V_28 = V_28 ,
. V_29 = V_29 ,
. V_9 = & V_268 ,
. V_38 = V_38 ,
. V_3 = V_3 ,
. V_7 = V_7 ,
} ;
struct V_1 * V_2 ;
int error ;
F_41 ( L_33 ) ;
V_2 = F_64 ( & V_19 , V_86 , V_87 , V_88 ,
V_58 -> V_130 & V_141 ) ;
if ( F_19 ( V_2 ) ) {
error = F_65 ( V_2 ) ;
goto error;
}
F_102 ( V_272 , & V_2 -> V_53 ) ;
V_58 -> V_1 = V_2 ;
F_41 ( L_34 , V_2 ) ;
return 0 ;
error:
F_41 ( L_35 , error ) ;
return error ;
}
struct V_1 * F_134 ( struct V_1 * V_273 ,
const struct V_63 * V_274 ,
int V_275 , int V_276 )
{
struct V_18 V_19 = {
. V_28 = V_274 ,
. V_29 = V_275 ,
. V_9 = & V_268 ,
. V_38 = V_276 ,
. V_3 = V_273 -> V_47 ,
. V_7 = V_273 -> V_7 ,
} ;
struct V_85 V_277 = {
. V_102 = 15 * V_103 ,
. V_111 = 15 * V_103 ,
. V_104 = 1 ,
. V_112 = 1 ,
} ;
struct V_1 * V_2 ;
V_2 = F_64 ( & V_19 , & V_277 , V_273 -> V_271 ,
V_273 -> V_35 -> V_155 -> V_156 , 0 ) ;
F_41 ( L_36 , V_133 , V_2 ) ;
return V_2 ;
}
static void F_135 ( struct V_57 * V_58 )
{
#ifdef V_263
struct V_264 * V_278 ;
T_1 V_279 ;
T_1 V_280 ;
if ( ! F_23 ( V_58 -> V_1 ) )
return;
V_278 = V_58 -> V_1 -> V_51 ;
V_279 = V_278 -> V_281 . V_282 - V_283 ;
V_280 = V_278 -> V_281 . V_284 - V_285 ;
if ( V_58 -> V_176 > V_279 )
V_58 -> V_176 = V_279 ;
if ( V_58 -> V_177 > V_280 )
V_58 -> V_177 = V_280 ;
#endif
}
static int F_136 ( struct V_57 * V_58 ,
struct V_192 * V_193 )
{
struct V_220 * V_221 ;
int error ;
F_50 ( ! V_58 -> V_1 ) ;
F_50 ( ! V_58 -> V_1 -> V_9 ) ;
F_50 ( ! V_58 -> V_1 -> V_9 -> V_241 ) ;
if ( F_137 ( V_58 -> V_1 ) )
return - V_98 ;
V_221 = F_115 () ;
if ( V_221 == NULL )
return - V_14 ;
error = F_138 ( V_58 ) ;
if ( error < 0 )
goto V_286;
error = F_139 ( V_58 , V_193 ) ;
if ( error < 0 )
goto V_286;
F_41 ( L_28 ,
( unsigned long long ) V_58 -> V_249 . V_250 ,
( unsigned long long ) V_58 -> V_249 . V_251 ) ;
F_41 ( L_37 , V_193 -> V_287 ) ;
F_135 ( V_58 ) ;
error = F_93 ( V_58 , V_193 , V_221 ) ;
if ( error < 0 )
goto V_286;
if ( V_58 -> V_190 == 0 || V_58 -> V_190 > V_288 )
V_58 -> V_190 = V_288 ;
F_96 ( V_58 ) ;
V_58 -> V_252 = V_253 ;
V_58 -> V_144 = F_38 ;
V_286:
F_116 ( V_221 ) ;
return error ;
}
static int F_140 ( struct V_57 * V_58 ,
const struct V_162 * V_83 )
{
struct V_85 V_86 ;
int error ;
F_41 ( L_38 ) ;
F_71 ( & V_86 , V_83 -> V_57 . V_122 ,
V_83 -> V_100 , V_83 -> V_101 ) ;
V_58 -> V_130 = V_83 -> V_130 ;
V_58 -> V_150 |= V_289 | V_290 | V_291 ;
if ( ! ( V_83 -> V_130 & V_243 ) )
V_58 -> V_150 |= V_244 ;
V_58 -> V_165 = V_83 -> V_165 ;
error = F_133 ( V_58 ,
V_83 -> V_57 . V_31 ,
( const struct V_63 * ) & V_83 -> V_57 . V_123 ,
V_83 -> V_57 . V_29 ,
V_83 -> V_292 ,
V_83 -> V_183 [ 0 ] ,
V_83 -> V_57 . V_122 ,
& V_86 ,
V_83 -> V_3 ,
V_83 -> V_7 ) ;
if ( error < 0 )
goto error;
if ( V_293 && V_83 -> V_183 [ 0 ] == V_161 )
V_58 -> V_150 |= V_294 ;
if ( V_83 -> V_176 )
V_58 -> V_176 = F_87 ( V_83 -> V_176 , NULL ) ;
if ( V_83 -> V_177 )
V_58 -> V_177 = F_87 ( V_83 -> V_177 , NULL ) ;
V_58 -> V_178 = V_83 -> V_178 * V_103 ;
V_58 -> V_179 = V_83 -> V_179 * V_103 ;
V_58 -> V_180 = V_83 -> V_180 * V_103 ;
V_58 -> V_181 = V_83 -> V_181 * V_103 ;
V_58 -> V_182 = V_83 -> V_57 . V_182 ;
error = F_81 ( V_58 , & V_86 , V_83 -> V_183 [ 0 ] ) ;
error:
F_41 ( L_39 , error ) ;
return error ;
}
struct V_57 * F_141 ( const struct V_162 * V_83 ,
struct V_192 * V_193 )
{
struct V_57 * V_58 ;
int error ;
F_41 ( L_40 ) ;
V_58 = F_104 () ;
if ( ! V_58 )
return F_12 ( - V_14 ) ;
error = F_140 ( V_58 , V_83 ) ;
if ( error < 0 )
goto error;
error = F_136 ( V_58 , V_193 ) ;
if ( error < 0 )
goto error;
F_41 ( L_41 , V_58 ) ;
return V_58 ;
error:
F_109 ( V_58 ) ;
F_41 ( L_42 , error ) ;
return F_12 ( error ) ;
}
struct V_57 * F_142 ( struct V_295 * V_83 ,
struct V_192 * V_193 )
{
struct V_1 * V_296 ;
struct V_57 * V_58 , * V_297 ;
int error ;
F_41 ( L_43 ) ;
V_58 = F_104 () ;
if ( ! V_58 )
return F_12 ( - V_14 ) ;
V_297 = F_143 ( V_83 -> V_298 ) ;
V_296 = V_297 -> V_1 ;
F_95 ( V_58 , V_297 ) ;
V_58 -> V_150 |= V_289 | V_290 ;
error = F_133 ( V_58 , V_83 -> V_31 ,
V_83 -> V_28 ,
V_83 -> V_29 ,
V_296 -> V_271 ,
V_83 -> V_129 ,
F_144 ( V_297 -> V_148 ) ,
V_297 -> V_148 -> V_154 ,
V_296 -> V_48 -> V_54 ,
V_296 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_81 ( V_58 , V_297 -> V_148 -> V_154 , V_83 -> V_129 ) ;
if ( error < 0 )
goto error;
error = F_136 ( V_58 , V_193 ) ;
if ( error < 0 )
goto error;
F_41 ( L_44 , V_58 ) ;
return V_58 ;
error:
F_109 ( V_58 ) ;
F_41 ( L_45 , error ) ;
return F_12 ( error ) ;
}
struct V_57 * F_145 ( struct V_57 * V_229 ,
struct V_192 * V_299 ,
struct V_220 * V_221 ,
T_2 V_117 )
{
struct V_57 * V_58 ;
struct V_220 * V_300 ;
int error ;
F_41 ( L_46 ,
( unsigned long long ) V_221 -> V_249 . V_250 ,
( unsigned long long ) V_221 -> V_249 . V_251 ) ;
V_58 = F_104 () ;
if ( ! V_58 )
return F_12 ( - V_14 ) ;
error = - V_14 ;
V_300 = F_115 () ;
if ( V_300 == NULL )
goto V_301;
V_58 -> V_1 = V_229 -> V_1 ;
V_58 -> V_144 = V_229 -> V_144 ;
F_63 ( & V_58 -> V_1 -> V_24 ) ;
F_95 ( V_58 , V_229 ) ;
V_58 -> V_249 = V_221 -> V_249 ;
error = F_81 ( V_58 ,
V_229 -> V_148 -> V_154 ,
V_117 ) ;
if ( error < 0 )
goto V_301;
if ( ! F_19 ( V_229 -> V_147 ) )
F_79 ( V_58 ) ;
error = F_93 ( V_58 , V_299 , V_300 ) ;
if ( error < 0 )
goto V_301;
if ( V_58 -> V_190 == 0 || V_58 -> V_190 > V_288 )
V_58 -> V_190 = V_288 ;
F_41 ( L_47 ,
( unsigned long long ) V_58 -> V_249 . V_250 ,
( unsigned long long ) V_58 -> V_249 . V_251 ) ;
error = F_77 ( V_58 ) ;
if ( error < 0 )
goto V_301;
F_96 ( V_58 ) ;
V_58 -> V_252 = V_253 ;
F_116 ( V_300 ) ;
F_41 ( L_48 , V_58 ) ;
return V_58 ;
V_301:
F_116 ( V_300 ) ;
F_109 ( V_58 ) ;
F_41 ( L_49 , error ) ;
return F_12 ( error ) ;
}
void F_146 ( struct V_7 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_7 , V_8 ) ;
F_11 ( & V_6 -> V_93 ) ;
F_11 ( & V_6 -> V_232 ) ;
#ifdef F_14
F_147 ( & V_6 -> V_12 ) ;
#endif
F_15 ( & V_6 -> V_15 ) ;
}
static int F_148 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
struct V_304 * V_305 ;
int V_4 ;
struct V_306 * V_307 = V_303 -> V_308 -> V_309 -> V_310 ;
struct V_7 * V_7 = V_307 -> V_311 -> V_312 -> V_313 ;
V_4 = F_149 ( V_303 , & V_314 ) ;
if ( V_4 < 0 )
return V_4 ;
V_305 = V_303 -> V_315 ;
V_305 -> V_316 = V_7 ;
return 0 ;
}
static void * F_150 ( struct V_304 * V_305 , T_4 * V_317 )
{
struct V_5 * V_6 = F_2 ( V_305 -> V_316 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
return F_151 ( & V_6 -> V_93 , * V_317 ) ;
}
static void * F_152 ( struct V_304 * V_318 , void * V_319 , T_4 * V_320 )
{
struct V_5 * V_6 = F_2 ( V_318 -> V_316 , V_8 ) ;
return F_153 ( V_319 , & V_6 -> V_93 , V_320 ) ;
}
static void F_154 ( struct V_304 * V_318 , void * V_319 )
{
struct V_5 * V_6 = F_2 ( V_318 -> V_316 , V_8 ) ;
F_6 ( & V_6 -> V_15 ) ;
}
static int F_155 ( struct V_304 * V_305 , void * V_319 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_305 -> V_316 , V_8 ) ;
if ( V_319 == & V_6 -> V_93 ) {
F_156 ( V_305 , L_50 ) ;
return 0 ;
}
V_2 = F_157 ( V_319 , struct V_1 , V_62 ) ;
if ( V_2 -> V_25 != V_81 )
return 0 ;
F_158 () ;
F_159 ( V_305 , L_51 ,
V_2 -> V_9 -> V_10 ,
F_160 ( V_2 -> V_35 , V_321 ) ,
F_160 ( V_2 -> V_35 , V_322 ) ,
F_47 ( & V_2 -> V_24 ) ,
V_2 -> V_32 ) ;
F_161 () ;
return 0 ;
}
static int F_162 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
struct V_304 * V_305 ;
int V_4 ;
struct V_306 * V_307 = V_303 -> V_308 -> V_309 -> V_310 ;
struct V_7 * V_7 = V_307 -> V_311 -> V_312 -> V_313 ;
V_4 = F_149 ( V_303 , & V_323 ) ;
if ( V_4 < 0 )
return V_4 ;
V_305 = V_303 -> V_315 ;
V_305 -> V_316 = V_7 ;
return 0 ;
}
static void * F_163 ( struct V_304 * V_305 , T_4 * V_317 )
{
struct V_5 * V_6 = F_2 ( V_305 -> V_316 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
return F_151 ( & V_6 -> V_232 , * V_317 ) ;
}
static void * F_164 ( struct V_304 * V_318 , void * V_319 , T_4 * V_320 )
{
struct V_5 * V_6 = F_2 ( V_318 -> V_316 , V_8 ) ;
return F_153 ( V_319 , & V_6 -> V_232 , V_320 ) ;
}
static void F_165 ( struct V_304 * V_318 , void * V_319 )
{
struct V_5 * V_6 = F_2 ( V_318 -> V_316 , V_8 ) ;
F_6 ( & V_6 -> V_15 ) ;
}
static int F_166 ( struct V_304 * V_305 , void * V_319 )
{
struct V_57 * V_58 ;
struct V_1 * V_2 ;
char V_324 [ 8 ] , V_249 [ 17 ] ;
struct V_5 * V_6 = F_2 ( V_305 -> V_316 , V_8 ) ;
if ( V_319 == & V_6 -> V_232 ) {
F_156 ( V_305 , L_52 ) ;
return 0 ;
}
V_58 = F_157 ( V_319 , struct V_57 , V_231 ) ;
V_2 = V_58 -> V_1 ;
snprintf ( V_324 , 8 , L_53 ,
F_167 ( V_58 -> V_325 ) , F_168 ( V_58 -> V_325 ) ) ;
snprintf ( V_249 , 17 , L_54 ,
( unsigned long long ) V_58 -> V_249 . V_250 ,
( unsigned long long ) V_58 -> V_249 . V_251 ) ;
F_158 () ;
F_159 ( V_305 , L_55 ,
V_2 -> V_9 -> V_10 ,
F_160 ( V_2 -> V_35 , V_321 ) ,
F_160 ( V_2 -> V_35 , V_322 ) ,
V_324 ,
V_249 ,
F_169 ( V_58 ) ) ;
F_161 () ;
return 0 ;
}
int T_5 F_170 ( void )
{
struct V_326 * V_318 ;
V_327 = F_171 ( L_56 , NULL ) ;
if ( ! V_327 )
goto V_23;
V_318 = F_172 ( L_57 , V_328 | V_329 ,
V_327 , & V_330 ) ;
if ( ! V_318 )
goto V_331;
V_318 = F_172 ( L_58 , V_328 | V_329 ,
V_327 , & V_332 ) ;
if ( ! V_318 )
goto V_333;
return 0 ;
V_333:
F_173 ( L_57 , V_327 ) ;
V_331:
F_173 ( L_56 , NULL ) ;
V_23:
return - V_14 ;
}
void F_174 ( void )
{
F_173 ( L_58 , V_327 ) ;
F_173 ( L_57 , V_327 ) ;
F_173 ( L_56 , NULL ) ;
}
