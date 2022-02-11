static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_4 ) ;
F_3 (nfs, &nfs_versions, list) {
if ( V_3 -> V_5 -> V_2 == V_2 ) {
F_4 ( & V_4 ) ;
return V_3 ;
}
}
F_4 ( & V_4 ) ;
return F_5 ( - V_6 ) ;
}
struct V_1 * F_6 ( unsigned int V_2 )
{
struct V_1 * V_3 = F_1 ( V_2 ) ;
if ( F_7 ( V_3 ) ) {
F_8 ( & V_7 ) ;
F_9 ( L_1 , V_2 ) ;
V_3 = F_1 ( V_2 ) ;
F_10 ( & V_7 ) ;
}
if ( ! F_7 ( V_3 ) && ! F_11 ( V_3 -> V_8 ) )
return F_5 ( - V_9 ) ;
return V_3 ;
}
void F_12 ( struct V_1 * V_3 )
{
F_13 ( V_3 -> V_8 ) ;
}
void F_14 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_15 ( & V_3 -> V_10 , & V_11 ) ;
V_12 [ V_3 -> V_5 -> V_2 ] = V_3 -> V_13 ;
F_4 ( & V_4 ) ;
}
void F_16 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
V_12 [ V_3 -> V_5 -> V_2 ] = NULL ;
F_17 ( & V_3 -> V_10 ) ;
F_4 ( & V_4 ) ;
}
struct V_14 * F_18 ( const struct V_15 * V_16 )
{
struct V_14 * V_17 ;
struct V_18 * V_19 ;
int V_20 = - V_21 ;
if ( ( V_17 = F_19 ( sizeof( * V_17 ) , V_22 ) ) == NULL )
goto V_23;
V_17 -> V_24 = V_16 -> V_25 ;
if ( ! F_11 ( V_17 -> V_24 -> V_8 ) )
goto V_26;
V_17 -> V_5 = V_17 -> V_24 -> V_5 ;
F_20 ( & V_17 -> V_27 , 1 ) ;
V_17 -> V_28 = V_29 ;
memcpy ( & V_17 -> V_30 , V_16 -> V_31 , V_16 -> V_32 ) ;
V_17 -> V_33 = V_16 -> V_32 ;
if ( V_16 -> V_34 ) {
V_20 = - V_21 ;
V_17 -> V_35 = F_21 ( V_16 -> V_34 , V_22 ) ;
if ( ! V_17 -> V_35 )
goto V_36;
}
F_22 ( & V_17 -> V_37 ) ;
V_17 -> V_38 = F_5 ( - V_39 ) ;
V_17 -> V_40 = V_16 -> V_41 ;
V_17 -> V_42 = F_23 ( V_16 -> V_43 ) ;
V_19 = F_24 ( L_2 ) ;
if ( ! F_7 ( V_19 ) )
V_17 -> V_44 = V_19 ;
F_25 ( V_17 ) ;
return V_17 ;
V_36:
F_12 ( V_17 -> V_24 ) ;
V_26:
F_26 ( V_17 ) ;
V_23:
return F_5 ( V_20 ) ;
}
void F_27 ( struct V_43 * V_43 )
{
struct V_45 * V_46 = F_28 ( V_43 , V_47 ) ;
F_29 ( & V_46 -> V_48 ) ;
}
static void F_30 ( struct V_14 * V_17 )
{
struct V_45 * V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
if ( V_17 -> V_49 )
F_31 ( & V_46 -> V_48 , V_17 -> V_49 ) ;
}
static void F_32 ( struct V_50 * V_51 )
{
F_33 ( & V_51 -> V_52 , L_3 ) ;
F_33 ( & V_51 -> V_53 , L_4 ) ;
}
void F_27 ( struct V_43 * V_43 )
{
}
static void F_30 ( struct V_14 * V_17 )
{
}
static void F_32 ( struct V_50 * V_51 )
{
}
void F_34 ( struct V_14 * V_17 )
{
F_35 ( V_17 ) ;
if ( ! F_7 ( V_17 -> V_38 ) )
F_36 ( V_17 -> V_38 ) ;
if ( V_17 -> V_44 != NULL )
F_37 ( V_17 -> V_44 ) ;
F_38 ( V_17 -> V_42 ) ;
F_12 ( V_17 -> V_24 ) ;
F_26 ( V_17 -> V_35 ) ;
F_26 ( V_17 -> V_54 ) ;
F_26 ( V_17 ) ;
}
void F_39 ( struct V_14 * V_17 )
{
struct V_45 * V_46 ;
if ( ! V_17 )
return;
V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
if ( F_40 ( & V_17 -> V_27 , & V_46 -> V_55 ) ) {
F_17 ( & V_17 -> V_56 ) ;
F_30 ( V_17 ) ;
F_4 ( & V_46 -> V_55 ) ;
F_41 ( ! F_42 ( & V_17 -> V_37 ) ) ;
V_17 -> V_5 -> V_57 ( V_17 ) ;
}
}
static struct V_14 * F_43 ( const struct V_15 * V_58 )
{
struct V_14 * V_17 ;
const struct V_59 * V_60 = V_58 -> V_31 ;
struct V_45 * V_46 = F_28 ( V_58 -> V_43 , V_47 ) ;
F_3 (clp, &nn->nfs_client_list, cl_share_link) {
const struct V_59 * V_61 = (struct V_59 * ) & V_17 -> V_30 ;
if ( V_17 -> V_28 < 0 )
continue;
if ( V_17 -> V_5 != V_58 -> V_25 -> V_5 )
continue;
if ( V_17 -> V_40 != V_58 -> V_41 )
continue;
if ( V_17 -> V_62 != V_58 -> V_63 )
continue;
if ( ! F_44 ( V_60 , V_61 ) )
if ( F_7 ( V_17 -> V_38 ) ||
! F_45 ( V_17 -> V_38 ,
V_60 ) )
continue;
F_46 ( & V_17 -> V_27 ) ;
return V_17 ;
}
return NULL ;
}
bool F_47 ( const struct V_14 * V_17 )
{
return V_17 -> V_28 <= V_64 ;
}
int F_48 ( const struct V_14 * V_17 )
{
if ( V_17 -> V_28 > V_64 ) {
F_41 ( 1 ) ;
return - V_39 ;
}
return V_17 -> V_28 ;
}
int F_49 ( const struct V_14 * V_17 )
{
return F_50 ( V_65 ,
F_47 ( V_17 ) ) ;
}
static struct V_14 *
F_51 ( const struct V_15 * V_16 ,
struct V_14 * V_17 )
{
int error ;
error = F_49 ( V_17 ) ;
if ( error < 0 ) {
F_39 ( V_17 ) ;
return F_5 ( - V_66 ) ;
}
if ( V_17 -> V_28 < V_64 ) {
error = V_17 -> V_28 ;
F_39 ( V_17 ) ;
return F_5 ( error ) ;
}
F_52 () ;
return V_17 ;
}
struct V_14 * F_53 ( const struct V_15 * V_16 )
{
struct V_14 * V_17 , * V_67 = NULL ;
struct V_45 * V_46 = F_28 ( V_16 -> V_43 , V_47 ) ;
const struct V_68 * V_5 = V_16 -> V_25 -> V_5 ;
if ( V_16 -> V_34 == NULL ) {
F_54 ( 1 ) ;
return NULL ;
}
do {
F_2 ( & V_46 -> V_55 ) ;
V_17 = F_43 ( V_16 ) ;
if ( V_17 ) {
F_4 ( & V_46 -> V_55 ) ;
if ( V_67 )
V_67 -> V_5 -> V_57 ( V_67 ) ;
return F_51 ( V_16 , V_17 ) ;
}
if ( V_67 ) {
F_55 ( & V_67 -> V_56 ,
& V_46 -> V_69 ) ;
F_4 ( & V_46 -> V_55 ) ;
V_67 -> V_70 = V_16 -> V_71 ;
return V_5 -> V_72 ( V_67 , V_16 ) ;
}
F_4 ( & V_46 -> V_55 ) ;
V_67 = V_5 -> V_73 ( V_16 ) ;
} while ( ! F_7 ( V_67 ) );
return V_67 ;
}
void F_56 ( struct V_14 * V_17 , int V_74 )
{
F_57 () ;
V_17 -> V_28 = V_74 ;
F_58 ( & V_65 ) ;
}
void F_59 ( struct V_75 * V_76 , int V_41 ,
int V_77 , int V_78 )
{
V_76 -> V_79 = V_77 * V_80 / 10 ;
V_76 -> V_81 = V_78 ;
switch ( V_41 ) {
case V_82 :
case V_83 :
if ( V_78 == V_84 )
V_76 -> V_81 = V_85 ;
if ( V_77 == V_86 || V_76 -> V_81 == 0 )
V_76 -> V_79 = V_87 * V_80 / 10 ;
if ( V_76 -> V_79 > V_88 )
V_76 -> V_79 = V_88 ;
V_76 -> V_89 = V_76 -> V_79 ;
V_76 -> V_90 = V_76 -> V_79 + ( V_76 -> V_89 * V_76 -> V_81 ) ;
if ( V_76 -> V_90 > V_88 )
V_76 -> V_90 = V_88 ;
if ( V_76 -> V_90 < V_76 -> V_79 )
V_76 -> V_90 = V_76 -> V_79 ;
V_76 -> V_91 = 0 ;
break;
case V_92 :
if ( V_78 == V_84 )
V_76 -> V_81 = V_93 ;
if ( V_77 == V_86 || V_76 -> V_79 == 0 )
V_76 -> V_79 = V_94 * V_80 / 10 ;
if ( V_76 -> V_79 > V_95 )
V_76 -> V_79 = V_95 ;
V_76 -> V_90 = V_95 ;
V_76 -> V_91 = 1 ;
break;
default:
F_60 () ;
}
}
int F_61 ( struct V_14 * V_17 ,
const struct V_15 * V_16 ,
T_1 V_96 )
{
struct V_97 * V_98 = NULL ;
struct V_99 args = {
. V_43 = V_17 -> V_42 ,
. V_100 = V_17 -> V_40 ,
. V_101 = (struct V_59 * ) & V_17 -> V_30 ,
. V_102 = V_17 -> V_33 ,
. V_103 = V_16 -> V_104 ,
. V_105 = V_17 -> V_35 ,
. V_106 = V_16 -> V_106 ,
. V_107 = & V_108 ,
. V_2 = V_17 -> V_5 -> V_2 ,
. V_109 = V_96 ,
} ;
if ( F_62 ( V_110 , & V_17 -> V_70 ) )
args . V_111 |= V_112 ;
if ( F_62 ( V_113 , & V_17 -> V_70 ) )
args . V_111 |= V_114 ;
if ( F_62 ( V_115 , & V_17 -> V_70 ) )
args . V_111 |= V_116 ;
if ( F_62 ( V_117 , & V_17 -> V_70 ) )
args . V_111 |= V_118 ;
if ( ! F_7 ( V_17 -> V_38 ) )
return 0 ;
V_98 = F_63 ( & args ) ;
if ( F_7 ( V_98 ) ) {
F_64 ( L_5 ,
V_119 , F_65 ( V_98 ) ) ;
return F_65 ( V_98 ) ;
}
V_17 -> V_38 = V_98 ;
return 0 ;
}
static void F_66 ( struct V_50 * V_51 )
{
if ( V_51 -> V_120 )
F_67 ( V_51 -> V_120 ) ;
}
static int F_68 ( struct V_50 * V_51 )
{
struct V_120 * V_121 ;
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_122 V_123 = {
. V_34 = V_17 -> V_35 ,
. V_101 = (struct V_59 * ) & V_17 -> V_30 ,
. V_32 = V_17 -> V_33 ,
. V_12 = V_17 -> V_5 -> V_2 ,
. V_124 = V_51 -> V_111 & V_125 ?
1 : 0 ,
. V_43 = V_17 -> V_42 ,
. V_126 = V_17 -> V_24 -> V_5 -> V_126 ,
} ;
if ( V_123 . V_12 > 3 )
return 0 ;
if ( ( V_51 -> V_111 & V_127 ) &&
( V_51 -> V_111 & V_128 ) )
return 0 ;
switch ( V_17 -> V_40 ) {
default:
V_123 . V_100 = V_129 ;
break;
case V_92 :
V_123 . V_100 = V_130 ;
}
V_121 = F_69 ( & V_123 ) ;
if ( F_7 ( V_121 ) )
return F_65 ( V_121 ) ;
V_51 -> V_120 = V_121 ;
V_51 -> V_131 = F_66 ;
return 0 ;
}
int F_70 ( struct V_50 * V_51 ,
const struct V_75 * V_77 ,
T_1 V_132 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
V_51 -> V_133 = F_71 ( V_17 -> V_38 ,
V_132 ) ;
if ( F_7 ( V_51 -> V_133 ) ) {
F_64 ( L_6 , V_119 ) ;
return F_65 ( V_51 -> V_133 ) ;
}
memcpy ( & V_51 -> V_133 -> V_134 ,
V_77 ,
sizeof( V_51 -> V_133 -> V_134 ) ) ;
V_51 -> V_133 -> V_135 = & V_51 -> V_133 -> V_134 ;
V_51 -> V_133 -> V_136 = 0 ;
if ( V_51 -> V_111 & V_137 )
V_51 -> V_133 -> V_136 = 1 ;
return 0 ;
}
struct V_14 * F_72 ( struct V_14 * V_17 ,
const struct V_15 * V_16 )
{
int error ;
if ( V_17 -> V_28 == V_64 )
return V_17 ;
error = F_61 ( V_17 , V_16 , V_138 ) ;
F_56 ( V_17 , error == 0 ? V_64 : error ) ;
if ( error < 0 ) {
F_39 ( V_17 ) ;
V_17 = F_5 ( error ) ;
}
return V_17 ;
}
static int F_73 ( struct V_50 * V_51 ,
const struct V_139 * V_58 ,
struct V_1 * V_25 )
{
struct V_75 V_104 ;
struct V_15 V_16 = {
. V_34 = V_58 -> V_50 . V_34 ,
. V_31 = ( const struct V_59 * ) & V_58 -> V_50 . V_101 ,
. V_32 = V_58 -> V_50 . V_32 ,
. V_25 = V_25 ,
. V_41 = V_58 -> V_50 . V_100 ,
. V_43 = V_58 -> V_43 ,
. V_104 = & V_104 ,
} ;
struct V_14 * V_17 ;
int error ;
F_59 ( & V_104 , V_58 -> V_50 . V_100 ,
V_58 -> V_77 , V_58 -> V_78 ) ;
if ( V_58 -> V_111 & V_125 )
F_74 ( V_115 , & V_16 . V_71 ) ;
V_17 = F_53 ( & V_16 ) ;
if ( F_7 ( V_17 ) )
return F_65 ( V_17 ) ;
V_51 -> V_14 = V_17 ;
V_51 -> V_111 = V_58 -> V_111 ;
V_51 -> V_140 = V_58 -> V_140 ;
V_51 -> V_141 |= V_142 | V_143 | V_144 |
V_145 | V_146 | V_147 | V_148 |
V_149 | V_150 | V_151 ;
if ( V_58 -> V_152 )
V_51 -> V_152 = F_75 ( V_58 -> V_152 , NULL ) ;
if ( V_58 -> V_153 )
V_51 -> V_153 = F_75 ( V_58 -> V_153 , NULL ) ;
V_51 -> V_154 = V_58 -> V_154 * V_80 ;
V_51 -> V_155 = V_58 -> V_155 * V_80 ;
V_51 -> V_156 = V_58 -> V_156 * V_80 ;
V_51 -> V_157 = V_58 -> V_157 * V_80 ;
error = F_68 ( V_51 ) ;
if ( error < 0 )
goto error;
V_51 -> V_158 = V_58 -> V_50 . V_158 ;
V_51 -> V_159 = V_58 -> V_159 ;
error = F_70 ( V_51 , & V_104 ,
V_58 -> V_160 ) ;
if ( error < 0 )
goto error;
if ( V_58 -> V_161 . V_32 ) {
memcpy ( & V_51 -> V_162 , & V_58 -> V_161 . V_101 ,
V_58 -> V_161 . V_32 ) ;
V_51 -> V_163 = V_58 -> V_161 . V_32 ;
}
V_51 -> V_164 = V_58 -> V_161 . V_2 ;
V_51 -> V_165 = V_58 -> V_161 . V_158 ;
V_51 -> V_166 = V_58 -> V_161 . V_100 ;
V_51 -> V_167 = V_58 -> V_168 ;
return 0 ;
error:
V_51 -> V_14 = NULL ;
F_39 ( V_17 ) ;
return error ;
}
static void F_76 ( struct V_50 * V_51 ,
struct V_169 * V_170 )
{
unsigned long V_171 ;
if ( V_51 -> V_152 == 0 )
V_51 -> V_152 = F_75 ( V_170 -> V_172 , NULL ) ;
if ( V_51 -> V_153 == 0 )
V_51 -> V_153 = F_75 ( V_170 -> V_173 , NULL ) ;
if ( V_170 -> V_174 >= 512 && V_51 -> V_152 > V_170 -> V_174 )
V_51 -> V_152 = F_75 ( V_170 -> V_174 , NULL ) ;
if ( V_170 -> V_175 >= 512 && V_51 -> V_153 > V_170 -> V_175 )
V_51 -> V_153 = F_75 ( V_170 -> V_175 , NULL ) ;
V_171 = F_75 ( F_77 ( V_51 -> V_133 ) , NULL ) ;
if ( V_51 -> V_152 > V_171 )
V_51 -> V_152 = V_171 ;
if ( V_51 -> V_152 > V_176 )
V_51 -> V_152 = V_176 ;
V_51 -> V_177 = ( V_51 -> V_152 + V_178 - 1 ) >> V_179 ;
if ( V_51 -> V_153 > V_171 )
V_51 -> V_153 = V_171 ;
if ( V_51 -> V_153 > V_176 )
V_51 -> V_153 = V_176 ;
V_51 -> V_180 = ( V_51 -> V_153 + V_178 - 1 ) >> V_179 ;
V_51 -> V_181 = F_78 ( V_170 -> V_181 , NULL ) ;
V_51 -> V_182 = F_75 ( V_170 -> V_183 , NULL ) ;
if ( V_51 -> V_182 > V_178 * V_184 )
V_51 -> V_182 = V_178 * V_184 ;
if ( V_51 -> V_182 > V_51 -> V_152 )
V_51 -> V_182 = V_51 -> V_152 ;
if ( V_51 -> V_111 & V_185 ) {
V_51 -> V_154 = V_51 -> V_155 = 0 ;
V_51 -> V_156 = V_51 -> V_157 = 0 ;
}
V_51 -> V_186 = V_170 -> V_186 ;
V_51 -> V_187 = V_170 -> V_187 ;
V_51 -> V_188 = V_170 -> V_188 ;
F_79 ( V_51 -> V_133 , V_51 -> V_153 + 100 , V_51 -> V_152 + 100 ) ;
}
int F_80 ( struct V_50 * V_51 , struct V_189 * V_190 , struct V_191 * V_192 )
{
struct V_169 V_170 ;
struct V_14 * V_17 = V_51 -> V_14 ;
int error ;
if ( V_17 -> V_5 -> V_193 != NULL ) {
error = V_17 -> V_5 -> V_193 ( V_51 , V_190 ) ;
if ( error < 0 )
return error ;
}
V_170 . V_192 = V_192 ;
V_170 . V_194 = 0 ;
memset ( V_170 . V_195 , 0 , sizeof( V_170 . V_195 ) ) ;
error = V_17 -> V_5 -> V_170 ( V_51 , V_190 , & V_170 ) ;
if ( error < 0 )
return error ;
F_76 ( V_51 , & V_170 ) ;
if ( V_51 -> V_167 == 0 ) {
struct V_196 V_197 ;
V_197 . V_192 = V_192 ;
F_81 ( V_192 ) ;
if ( V_17 -> V_5 -> V_198 ( V_51 , V_190 , & V_197 ) >= 0 )
V_51 -> V_167 = V_197 . V_199 ;
}
return 0 ;
}
void F_82 ( struct V_50 * V_200 , struct V_50 * V_201 )
{
V_200 -> V_111 = V_201 -> V_111 ;
V_200 -> V_152 = V_201 -> V_152 ;
V_200 -> V_153 = V_201 -> V_153 ;
V_200 -> V_154 = V_201 -> V_154 ;
V_200 -> V_155 = V_201 -> V_155 ;
V_200 -> V_156 = V_201 -> V_156 ;
V_200 -> V_157 = V_201 -> V_157 ;
V_200 -> V_141 = V_201 -> V_141 ;
V_200 -> V_140 = V_201 -> V_140 ;
V_200 -> V_159 = V_201 -> V_159 ;
V_200 -> V_158 = V_201 -> V_158 ;
}
void F_83 ( struct V_50 * V_51 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_45 * V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
F_2 ( & V_46 -> V_55 ) ;
F_84 ( & V_51 -> V_202 , & V_17 -> V_37 ) ;
F_55 ( & V_51 -> V_203 , & V_46 -> V_204 ) ;
F_85 ( V_205 , & V_17 -> V_206 ) ;
F_4 ( & V_46 -> V_55 ) ;
}
void F_86 ( struct V_50 * V_51 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_45 * V_46 ;
if ( V_17 == NULL )
return;
V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
F_2 ( & V_46 -> V_55 ) ;
F_87 ( & V_51 -> V_202 ) ;
if ( F_42 ( & V_17 -> V_37 ) )
F_74 ( V_205 , & V_17 -> V_206 ) ;
F_17 ( & V_51 -> V_203 ) ;
F_4 ( & V_46 -> V_55 ) ;
F_88 () ;
}
struct V_50 * F_89 ( void )
{
struct V_50 * V_51 ;
V_51 = F_19 ( sizeof( struct V_50 ) , V_22 ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_133 = V_51 -> V_207 = F_5 ( - V_39 ) ;
F_22 ( & V_51 -> V_202 ) ;
F_22 ( & V_51 -> V_203 ) ;
F_22 ( & V_51 -> V_208 ) ;
F_22 ( & V_51 -> V_209 ) ;
F_22 ( & V_51 -> V_210 ) ;
F_20 ( & V_51 -> V_211 , 0 ) ;
V_51 -> V_212 = F_90 () ;
if ( ! V_51 -> V_212 ) {
F_26 ( V_51 ) ;
return NULL ;
}
F_91 ( & V_51 -> V_213 ) ;
F_91 ( & V_51 -> V_214 ) ;
F_32 ( V_51 ) ;
return V_51 ;
}
void F_92 ( struct V_50 * V_51 )
{
F_86 ( V_51 ) ;
if ( V_51 -> V_131 != NULL )
V_51 -> V_131 ( V_51 ) ;
if ( ! F_7 ( V_51 -> V_207 ) )
F_36 ( V_51 -> V_207 ) ;
if ( ! F_7 ( V_51 -> V_133 ) )
F_36 ( V_51 -> V_133 ) ;
F_39 ( V_51 -> V_14 ) ;
F_93 ( & V_51 -> V_214 ) ;
F_93 ( & V_51 -> V_213 ) ;
F_94 ( V_51 -> V_212 ) ;
F_26 ( V_51 ) ;
F_95 () ;
}
struct V_50 * F_96 ( struct V_215 * V_216 ,
struct V_1 * V_25 )
{
struct V_50 * V_51 ;
struct V_191 * V_192 ;
int error ;
V_51 = F_89 () ;
if ( ! V_51 )
return F_5 ( - V_21 ) ;
error = - V_21 ;
V_192 = F_97 () ;
if ( V_192 == NULL )
goto error;
error = F_73 ( V_51 , V_216 -> V_217 , V_25 ) ;
if ( error < 0 )
goto error;
error = F_80 ( V_51 , V_216 -> V_190 , V_192 ) ;
if ( error < 0 )
goto error;
if ( V_51 -> V_14 -> V_5 -> V_2 == 3 ) {
if ( V_51 -> V_167 == 0 || V_51 -> V_167 > V_218 )
V_51 -> V_167 = V_218 ;
if ( ! ( V_216 -> V_217 -> V_111 & V_219 ) )
V_51 -> V_141 |= V_220 ;
} else {
if ( V_51 -> V_167 == 0 || V_51 -> V_167 > V_221 )
V_51 -> V_167 = V_221 ;
}
if ( ! ( V_192 -> V_222 & V_223 ) ) {
error = V_25 -> V_5 -> V_224 ( V_51 , V_216 -> V_190 , V_192 , NULL ) ;
if ( error < 0 ) {
F_64 ( L_7 , - error ) ;
goto error;
}
}
memcpy ( & V_51 -> V_225 , & V_192 -> V_225 , sizeof( V_51 -> V_225 ) ) ;
F_64 ( L_8 ,
( unsigned long long ) V_51 -> V_225 . V_226 ,
( unsigned long long ) V_51 -> V_225 . V_227 ) ;
F_83 ( V_51 ) ;
V_51 -> V_228 = V_229 ;
F_98 ( V_192 ) ;
return V_51 ;
error:
F_98 ( V_192 ) ;
F_92 ( V_51 ) ;
return F_5 ( error ) ;
}
struct V_50 * F_99 ( struct V_50 * V_201 ,
struct V_189 * V_230 ,
struct V_191 * V_192 ,
T_1 V_96 )
{
struct V_50 * V_51 ;
struct V_191 * V_231 ;
int error ;
V_51 = F_89 () ;
if ( ! V_51 )
return F_5 ( - V_21 ) ;
error = - V_21 ;
V_231 = F_97 () ;
if ( V_231 == NULL )
goto V_232;
V_51 -> V_14 = V_201 -> V_14 ;
V_51 -> V_131 = V_201 -> V_131 ;
F_46 ( & V_51 -> V_14 -> V_27 ) ;
F_82 ( V_51 , V_201 ) ;
V_51 -> V_225 = V_192 -> V_225 ;
error = F_70 ( V_51 ,
V_201 -> V_133 -> V_135 ,
V_96 ) ;
if ( error < 0 )
goto V_232;
error = F_80 ( V_51 , V_230 , V_231 ) ;
if ( error < 0 )
goto V_232;
if ( V_51 -> V_167 == 0 || V_51 -> V_167 > V_233 )
V_51 -> V_167 = V_233 ;
error = F_68 ( V_51 ) ;
if ( error < 0 )
goto V_232;
F_83 ( V_51 ) ;
V_51 -> V_228 = V_229 ;
F_98 ( V_231 ) ;
return V_51 ;
V_232:
F_98 ( V_231 ) ;
F_92 ( V_51 ) ;
return F_5 ( error ) ;
}
void F_100 ( struct V_43 * V_43 )
{
struct V_45 * V_46 = F_28 ( V_43 , V_47 ) ;
F_22 ( & V_46 -> V_69 ) ;
F_22 ( & V_46 -> V_204 ) ;
#if F_101 ( V_234 )
F_102 ( & V_46 -> V_48 ) ;
#endif
F_103 ( & V_46 -> V_55 ) ;
V_46 -> V_235 = F_104 () ;
}
static int F_105 ( struct V_236 * V_236 , struct V_237 * V_237 )
{
return F_106 ( V_236 , V_237 , & V_238 ,
sizeof( struct V_239 ) ) ;
}
static void * F_107 ( struct V_240 * V_241 , T_2 * V_242 )
__acquires( &nn->nfs_client_lock
static void * F_108 ( struct V_240 * V_243 , void * V_244 , T_2 * V_245 )
{
struct V_45 * V_46 = F_28 ( F_109 ( V_243 ) , V_47 ) ;
return F_110 ( V_244 , & V_46 -> V_69 , V_245 ) ;
}
static void F_111 ( struct V_240 * V_243 , void * V_244 )
__releases( &nn->nfs_client_lock
static int F_112 ( struct V_240 * V_241 , void * V_244 )
{
struct V_14 * V_17 ;
struct V_45 * V_46 = F_28 ( F_109 ( V_241 ) , V_47 ) ;
if ( V_244 == & V_46 -> V_69 ) {
F_113 ( V_241 , L_9 ) ;
return 0 ;
}
V_17 = F_114 ( V_244 , struct V_14 , V_56 ) ;
if ( V_17 -> V_28 != V_64 )
return 0 ;
F_115 () ;
F_116 ( V_241 , L_10 ,
V_17 -> V_5 -> V_2 ,
F_117 ( V_17 -> V_38 , V_246 ) ,
F_117 ( V_17 -> V_38 , V_247 ) ,
F_118 ( & V_17 -> V_27 ) ,
V_17 -> V_35 ) ;
F_119 () ;
return 0 ;
}
static int F_120 ( struct V_236 * V_236 , struct V_237 * V_237 )
{
return F_106 ( V_236 , V_237 , & V_248 ,
sizeof( struct V_239 ) ) ;
}
static void * F_121 ( struct V_240 * V_241 , T_2 * V_242 )
__acquires( &nn->nfs_client_lock
static void * F_122 ( struct V_240 * V_243 , void * V_244 , T_2 * V_245 )
{
struct V_45 * V_46 = F_28 ( F_109 ( V_243 ) , V_47 ) ;
return F_110 ( V_244 , & V_46 -> V_204 , V_245 ) ;
}
static void F_123 ( struct V_240 * V_243 , void * V_244 )
__releases( &nn->nfs_client_lock
static int F_124 ( struct V_240 * V_241 , void * V_244 )
{
struct V_50 * V_51 ;
struct V_14 * V_17 ;
char V_249 [ 13 ] ;
char V_225 [ 34 ] ;
struct V_45 * V_46 = F_28 ( F_109 ( V_241 ) , V_47 ) ;
if ( V_244 == & V_46 -> V_204 ) {
F_113 ( V_241 , L_11
L_12 ) ;
return 0 ;
}
V_51 = F_114 ( V_244 , struct V_50 , V_203 ) ;
V_17 = V_51 -> V_14 ;
snprintf ( V_249 , sizeof( V_249 ) , L_13 ,
F_125 ( V_51 -> V_250 ) , F_126 ( V_51 -> V_250 ) ) ;
snprintf ( V_225 , sizeof( V_225 ) , L_14 ,
( unsigned long long ) V_51 -> V_225 . V_226 ,
( unsigned long long ) V_51 -> V_225 . V_227 ) ;
F_115 () ;
F_116 ( V_241 , L_15 ,
V_17 -> V_5 -> V_2 ,
F_117 ( V_17 -> V_38 , V_246 ) ,
F_117 ( V_17 -> V_38 , V_247 ) ,
V_249 ,
V_225 ,
F_127 ( V_51 ) ) ;
F_119 () ;
return 0 ;
}
int F_128 ( struct V_43 * V_43 )
{
struct V_45 * V_46 = F_28 ( V_43 , V_47 ) ;
struct V_251 * V_243 ;
V_46 -> V_252 = F_129 ( V_43 , L_16 , V_43 -> V_253 ) ;
if ( ! V_46 -> V_252 )
goto V_23;
V_243 = F_130 ( L_17 , V_254 | V_255 ,
V_46 -> V_252 , & V_256 ) ;
if ( ! V_243 )
goto V_257;
V_243 = F_130 ( L_18 , V_254 | V_255 ,
V_46 -> V_252 , & V_258 ) ;
if ( ! V_243 )
goto V_257;
return 0 ;
V_257:
F_131 ( L_16 , V_43 -> V_253 ) ;
V_23:
return - V_21 ;
}
void F_132 ( struct V_43 * V_43 )
{
F_131 ( L_16 , V_43 -> V_253 ) ;
}
int T_3 F_133 ( void )
{
if ( ! F_134 ( L_19 , NULL ) )
goto V_23;
if ( ! F_135 ( L_20 , NULL , L_21 ) )
goto V_257;
if ( ! F_135 ( L_22 , NULL , L_23 ) )
goto V_257;
return 0 ;
V_257:
F_131 ( L_19 , NULL ) ;
V_23:
return - V_21 ;
}
void F_136 ( void )
{
F_131 ( L_19 , NULL ) ;
}
