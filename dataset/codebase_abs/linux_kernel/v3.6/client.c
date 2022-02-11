static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
F_2 ( & V_4 ) ;
F_3 (nfs, &nfs_versions, list) {
if ( V_3 -> V_5 -> V_2 == V_2 ) {
F_4 ( & V_4 ) ;
return V_3 ;
}
} ;
F_4 ( & V_4 ) ;
return F_5 ( - V_6 ) ; ;
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
if ( ! F_7 ( V_3 ) )
F_11 ( V_3 -> V_8 ) ;
return V_3 ;
}
void F_12 ( struct V_1 * V_3 )
{
F_13 ( V_3 -> V_8 ) ;
}
void F_14 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_15 ( & V_3 -> V_9 , & V_10 ) ;
V_11 [ V_3 -> V_5 -> V_2 ] = V_3 -> V_12 ;
F_4 ( & V_4 ) ;
}
void F_16 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
V_11 [ V_3 -> V_5 -> V_2 ] = NULL ;
F_17 ( & V_3 -> V_9 ) ;
F_4 ( & V_4 ) ;
}
struct V_13 * F_18 ( const struct V_14 * V_15 )
{
struct V_13 * V_16 ;
struct V_17 * V_18 ;
int V_19 = - V_20 ;
if ( ( V_16 = F_19 ( sizeof( * V_16 ) , V_21 ) ) == NULL )
goto V_22;
V_16 -> V_23 = V_15 -> V_24 ;
F_11 ( V_16 -> V_23 -> V_8 ) ;
V_16 -> V_5 = V_16 -> V_23 -> V_5 ;
F_20 ( & V_16 -> V_25 , 1 ) ;
V_16 -> V_26 = V_27 ;
memcpy ( & V_16 -> V_28 , V_15 -> V_29 , V_15 -> V_30 ) ;
V_16 -> V_31 = V_15 -> V_30 ;
if ( V_15 -> V_32 ) {
V_19 = - V_20 ;
V_16 -> V_33 = F_21 ( V_15 -> V_32 , V_21 ) ;
if ( ! V_16 -> V_33 )
goto V_34;
}
F_22 ( & V_16 -> V_35 ) ;
V_16 -> V_36 = F_5 ( - V_37 ) ;
V_16 -> V_38 = V_15 -> V_39 ;
V_16 -> V_40 = F_23 ( V_15 -> V_41 ) ;
V_18 = F_24 ( L_2 ) ;
if ( ! F_7 ( V_18 ) )
V_16 -> V_42 = V_18 ;
F_25 ( V_16 ) ;
return V_16 ;
V_34:
F_12 ( V_16 -> V_23 ) ;
F_26 ( V_16 ) ;
V_22:
return F_5 ( V_19 ) ;
}
void F_27 ( struct V_41 * V_41 )
{
struct V_43 * V_44 = F_28 ( V_41 , V_45 ) ;
F_29 ( & V_44 -> V_46 ) ;
}
static void F_30 ( struct V_13 * V_16 )
{
struct V_43 * V_44 = F_28 ( V_16 -> V_40 , V_45 ) ;
if ( V_16 -> V_47 )
F_31 ( & V_44 -> V_46 , V_16 -> V_47 ) ;
}
static void F_32 ( struct V_48 * V_49 )
{
F_33 ( & V_49 -> V_50 , L_3 ) ;
}
void F_27 ( struct V_41 * V_41 )
{
}
static void F_30 ( struct V_13 * V_16 )
{
}
static void F_32 ( struct V_48 * V_49 )
{
}
void F_34 ( struct V_13 * V_16 )
{
F_35 ( L_4 , V_16 -> V_5 -> V_2 ) ;
F_36 ( V_16 ) ;
if ( ! F_7 ( V_16 -> V_36 ) )
F_37 ( V_16 -> V_36 ) ;
if ( V_16 -> V_42 != NULL )
F_38 ( V_16 -> V_42 ) ;
F_39 ( V_16 -> V_40 ) ;
F_12 ( V_16 -> V_23 ) ;
F_26 ( V_16 -> V_33 ) ;
F_26 ( V_16 ) ;
F_35 ( L_5 ) ;
}
void F_40 ( struct V_13 * V_16 )
{
struct V_43 * V_44 ;
if ( ! V_16 )
return;
F_35 ( L_6 , F_41 ( & V_16 -> V_25 ) ) ;
V_44 = F_28 ( V_16 -> V_40 , V_45 ) ;
if ( F_42 ( & V_16 -> V_25 , & V_44 -> V_51 ) ) {
F_17 ( & V_16 -> V_52 ) ;
F_30 ( V_16 ) ;
F_4 ( & V_44 -> V_51 ) ;
F_43 ( ! F_44 ( & V_16 -> V_35 ) ) ;
V_16 -> V_5 -> V_53 ( V_16 ) ;
}
}
static int F_45 ( const struct V_54 * V_55 ,
const struct V_54 * V_56 )
{
const struct V_57 * V_58 = ( const struct V_57 * ) V_55 ;
const struct V_57 * V_59 = ( const struct V_57 * ) V_56 ;
if ( ! F_46 ( & V_58 -> V_60 , & V_59 -> V_60 ) )
return 0 ;
else if ( F_47 ( & V_58 -> V_60 ) & V_61 )
return V_58 -> V_62 == V_59 -> V_62 ;
return 1 ;
}
static int F_45 ( const struct V_54 * V_55 ,
const struct V_54 * V_56 )
{
return 0 ;
}
static int F_48 ( const struct V_54 * V_55 ,
const struct V_54 * V_56 )
{
const struct V_63 * V_58 = ( const struct V_63 * ) V_55 ;
const struct V_63 * V_59 = ( const struct V_63 * ) V_56 ;
return V_58 -> V_64 . V_65 == V_59 -> V_64 . V_65 ;
}
static int F_49 ( const struct V_54 * V_55 ,
const struct V_54 * V_56 )
{
const struct V_57 * V_58 = ( const struct V_57 * ) V_55 ;
const struct V_57 * V_59 = ( const struct V_57 * ) V_56 ;
return F_45 ( V_55 , V_56 ) &&
( V_58 -> V_66 == V_59 -> V_66 ) ;
}
static int F_50 ( const struct V_54 * V_55 ,
const struct V_54 * V_56 )
{
const struct V_63 * V_58 = ( const struct V_63 * ) V_55 ;
const struct V_63 * V_59 = ( const struct V_63 * ) V_56 ;
return F_48 ( V_55 , V_56 ) &&
( V_58 -> V_67 == V_59 -> V_67 ) ;
}
int F_51 ( const struct V_54 * V_55 ,
const struct V_54 * V_56 )
{
if ( V_55 -> V_68 != V_56 -> V_68 )
return 0 ;
switch ( V_55 -> V_68 ) {
case V_69 :
return F_48 ( V_55 , V_56 ) ;
case V_70 :
return F_45 ( V_55 , V_56 ) ;
}
return 0 ;
}
static int F_52 ( const struct V_54 * V_55 ,
const struct V_54 * V_56 )
{
if ( V_55 -> V_68 != V_56 -> V_68 )
return 0 ;
switch ( V_55 -> V_68 ) {
case V_69 :
return F_50 ( V_55 , V_56 ) ;
case V_70 :
return F_49 ( V_55 , V_56 ) ;
}
return 0 ;
}
static struct V_13 * F_53 ( const struct V_14 * V_71 )
{
struct V_13 * V_16 ;
const struct V_54 * V_72 = V_71 -> V_29 ;
struct V_43 * V_44 = F_28 ( V_71 -> V_41 , V_45 ) ;
F_3 (clp, &nn->nfs_client_list, cl_share_link) {
const struct V_54 * V_73 = (struct V_54 * ) & V_16 -> V_28 ;
if ( V_16 -> V_26 < 0 )
continue;
if ( V_16 -> V_5 != V_71 -> V_24 -> V_5 )
continue;
if ( V_16 -> V_38 != V_71 -> V_39 )
continue;
if ( V_16 -> V_74 != V_71 -> V_75 )
continue;
if ( ! F_52 ( V_72 , V_73 ) )
continue;
F_54 ( & V_16 -> V_25 ) ;
return V_16 ;
}
return NULL ;
}
static bool F_55 ( const struct V_13 * V_16 )
{
return V_16 -> V_26 != V_27 ;
}
int F_56 ( const struct V_13 * V_16 )
{
return F_57 ( V_76 ,
F_55 ( V_16 ) ) ;
}
static struct V_13 *
F_58 ( const struct V_14 * V_15 ,
struct V_13 * V_16 )
{
int error ;
error = F_56 ( V_16 ) ;
if ( error < 0 ) {
F_40 ( V_16 ) ;
return F_5 ( - V_77 ) ;
}
if ( V_16 -> V_26 < V_78 ) {
error = V_16 -> V_26 ;
F_40 ( V_16 ) ;
return F_5 ( error ) ;
}
F_59 () ;
F_35 ( L_7 ,
V_79 , V_16 , V_15 -> V_32 ? : L_8 ) ;
return V_16 ;
}
struct V_13 *
F_60 ( const struct V_14 * V_15 ,
const struct V_80 * V_81 ,
const char * V_82 ,
T_1 V_83 )
{
struct V_13 * V_16 , * V_84 = NULL ;
struct V_43 * V_44 = F_28 ( V_15 -> V_41 , V_45 ) ;
const struct V_85 * V_5 = V_15 -> V_24 -> V_5 ;
F_35 ( L_9 ,
V_15 -> V_32 ? : L_8 , V_5 -> V_2 ) ;
do {
F_2 ( & V_44 -> V_51 ) ;
V_16 = F_53 ( V_15 ) ;
if ( V_16 ) {
F_4 ( & V_44 -> V_51 ) ;
if ( V_84 )
V_84 -> V_5 -> V_53 ( V_84 ) ;
return F_58 ( V_15 , V_16 ) ;
}
if ( V_84 ) {
F_15 ( & V_84 -> V_52 , & V_44 -> V_86 ) ;
F_4 ( & V_44 -> V_51 ) ;
V_84 -> V_87 = V_15 -> V_88 ;
return V_5 -> V_89 ( V_84 , V_81 , V_82 ,
V_83 ) ;
}
F_4 ( & V_44 -> V_51 ) ;
V_84 = V_5 -> V_90 ( V_15 ) ;
} while ( ! F_7 ( V_84 ) );
F_35 ( L_10 ,
V_15 -> V_32 ? : L_8 , F_61 ( V_84 ) ) ;
return V_84 ;
}
void F_62 ( struct V_13 * V_16 , int V_91 )
{
F_63 () ;
V_16 -> V_26 = V_91 ;
F_64 ( & V_76 ) ;
}
void F_65 ( struct V_80 * V_92 , int V_39 ,
unsigned int V_93 , unsigned int V_94 )
{
V_92 -> V_95 = V_93 * V_96 / 10 ;
V_92 -> V_97 = V_94 ;
switch ( V_39 ) {
case V_98 :
case V_99 :
if ( V_92 -> V_97 == 0 )
V_92 -> V_97 = V_100 ;
if ( V_92 -> V_95 == 0 )
V_92 -> V_95 = V_101 * V_96 / 10 ;
if ( V_92 -> V_95 > V_102 )
V_92 -> V_95 = V_102 ;
V_92 -> V_103 = V_92 -> V_95 ;
V_92 -> V_104 = V_92 -> V_95 + ( V_92 -> V_103 * V_92 -> V_97 ) ;
if ( V_92 -> V_104 > V_102 )
V_92 -> V_104 = V_102 ;
if ( V_92 -> V_104 < V_92 -> V_95 )
V_92 -> V_104 = V_92 -> V_95 ;
V_92 -> V_105 = 0 ;
break;
case V_106 :
if ( V_92 -> V_97 == 0 )
V_92 -> V_97 = V_107 ;
if ( ! V_92 -> V_95 )
V_92 -> V_95 = V_108 * V_96 / 10 ;
if ( V_92 -> V_95 > V_109 )
V_92 -> V_95 = V_109 ;
V_92 -> V_104 = V_109 ;
V_92 -> V_105 = 1 ;
break;
default:
F_66 () ;
}
}
int F_67 ( struct V_13 * V_16 ,
const struct V_80 * V_81 ,
T_1 V_110 )
{
struct V_111 * V_112 = NULL ;
struct V_113 args = {
. V_41 = V_16 -> V_40 ,
. V_114 = V_16 -> V_38 ,
. V_115 = (struct V_54 * ) & V_16 -> V_28 ,
. V_116 = V_16 -> V_31 ,
. V_117 = V_81 ,
. V_118 = V_16 -> V_33 ,
. V_119 = & V_120 ,
. V_2 = V_16 -> V_5 -> V_2 ,
. V_121 = V_110 ,
} ;
if ( F_68 ( V_122 , & V_16 -> V_87 ) )
args . V_123 |= V_124 ;
if ( F_68 ( V_125 , & V_16 -> V_87 ) )
args . V_123 |= V_126 ;
if ( ! F_7 ( V_16 -> V_36 ) )
return 0 ;
V_112 = F_69 ( & args ) ;
if ( F_7 ( V_112 ) ) {
F_35 ( L_11 ,
V_79 , F_61 ( V_112 ) ) ;
return F_61 ( V_112 ) ;
}
V_16 -> V_36 = V_112 ;
return 0 ;
}
static void F_70 ( struct V_48 * V_49 )
{
if ( ! ( V_49 -> V_123 & V_127 ) ||
! ( V_49 -> V_123 & V_128 ) )
F_71 ( V_49 -> V_129 ) ;
}
static int F_72 ( struct V_48 * V_49 )
{
struct V_129 * V_130 ;
struct V_13 * V_16 = V_49 -> V_13 ;
struct V_131 V_132 = {
. V_32 = V_16 -> V_33 ,
. V_115 = (struct V_54 * ) & V_16 -> V_28 ,
. V_30 = V_16 -> V_31 ,
. V_11 = V_16 -> V_5 -> V_2 ,
. V_133 = V_49 -> V_123 & V_134 ?
1 : 0 ,
. V_41 = V_16 -> V_40 ,
} ;
if ( V_132 . V_11 > 3 )
return 0 ;
if ( ( V_49 -> V_123 & V_127 ) &&
( V_49 -> V_123 & V_128 ) )
return 0 ;
switch ( V_16 -> V_38 ) {
default:
V_132 . V_114 = V_135 ;
break;
case V_106 :
V_132 . V_114 = V_136 ;
}
V_130 = F_73 ( & V_132 ) ;
if ( F_7 ( V_130 ) )
return F_61 ( V_130 ) ;
V_49 -> V_129 = V_130 ;
V_49 -> V_137 = F_70 ;
return 0 ;
}
int F_74 ( struct V_48 * V_49 ,
const struct V_80 * V_93 ,
T_1 V_138 )
{
struct V_13 * V_16 = V_49 -> V_13 ;
V_49 -> V_139 = F_75 ( V_16 -> V_36 ) ;
if ( F_7 ( V_49 -> V_139 ) ) {
F_35 ( L_12 , V_79 ) ;
return F_61 ( V_49 -> V_139 ) ;
}
memcpy ( & V_49 -> V_139 -> V_140 ,
V_93 ,
sizeof( V_49 -> V_139 -> V_140 ) ) ;
V_49 -> V_139 -> V_141 = & V_49 -> V_139 -> V_140 ;
if ( V_138 != V_16 -> V_36 -> V_142 -> V_143 ) {
struct V_144 * V_145 ;
V_145 = F_76 ( V_138 , V_49 -> V_139 ) ;
if ( F_7 ( V_145 ) ) {
F_35 ( L_13 , V_79 ) ;
return F_61 ( V_145 ) ;
}
}
V_49 -> V_139 -> V_146 = 0 ;
if ( V_49 -> V_123 & V_147 )
V_49 -> V_139 -> V_146 = 1 ;
return 0 ;
}
struct V_13 * F_77 ( struct V_13 * V_16 ,
const struct V_80 * V_81 ,
const char * V_82 , T_1 V_83 )
{
int error ;
if ( V_16 -> V_26 == V_78 ) {
F_35 ( L_14 , V_16 ) ;
return V_16 ;
}
error = F_67 ( V_16 , V_81 , V_148 ) ;
if ( error < 0 )
goto error;
F_62 ( V_16 , V_78 ) ;
return V_16 ;
error:
F_62 ( V_16 , error ) ;
F_40 ( V_16 ) ;
F_35 ( L_15 , error ) ;
return F_5 ( error ) ;
}
static int F_78 ( struct V_48 * V_49 ,
const struct V_149 * V_71 ,
struct V_1 * V_24 )
{
struct V_14 V_15 = {
. V_32 = V_71 -> V_48 . V_32 ,
. V_29 = ( const struct V_54 * ) & V_71 -> V_48 . V_115 ,
. V_30 = V_71 -> V_48 . V_30 ,
. V_24 = V_24 ,
. V_39 = V_71 -> V_48 . V_114 ,
. V_41 = V_71 -> V_41 ,
} ;
struct V_80 V_81 ;
struct V_13 * V_16 ;
int error ;
F_35 ( L_16 ) ;
F_65 ( & V_81 , V_71 -> V_48 . V_114 ,
V_71 -> V_93 , V_71 -> V_94 ) ;
if ( V_71 -> V_123 & V_134 )
F_79 ( V_125 , & V_15 . V_88 ) ;
V_16 = F_60 ( & V_15 , & V_81 , NULL , V_148 ) ;
if ( F_7 ( V_16 ) ) {
F_35 ( L_17 , F_61 ( V_16 ) ) ;
return F_61 ( V_16 ) ;
}
V_49 -> V_13 = V_16 ;
V_49 -> V_123 = V_71 -> V_123 ;
V_49 -> V_150 = V_71 -> V_150 ;
V_49 -> V_151 |= V_152 | V_153 | V_154 |
V_155 | V_156 | V_157 | V_158 |
V_159 | V_160 | V_161 | V_162 ;
if ( V_71 -> V_163 )
V_49 -> V_163 = F_80 ( V_71 -> V_163 , NULL ) ;
if ( V_71 -> V_164 )
V_49 -> V_164 = F_80 ( V_71 -> V_164 , NULL ) ;
V_49 -> V_165 = V_71 -> V_165 * V_96 ;
V_49 -> V_166 = V_71 -> V_166 * V_96 ;
V_49 -> V_167 = V_71 -> V_167 * V_96 ;
V_49 -> V_168 = V_71 -> V_168 * V_96 ;
error = F_72 ( V_49 ) ;
if ( error < 0 )
goto error;
V_49 -> V_169 = V_71 -> V_48 . V_169 ;
error = F_74 ( V_49 , & V_81 , V_71 -> V_170 [ 0 ] ) ;
if ( error < 0 )
goto error;
if ( V_71 -> V_171 . V_30 ) {
memcpy ( & V_49 -> V_172 , & V_71 -> V_171 . V_115 ,
V_71 -> V_171 . V_30 ) ;
V_49 -> V_173 = V_71 -> V_171 . V_30 ;
}
V_49 -> V_174 = V_71 -> V_171 . V_2 ;
V_49 -> V_175 = V_71 -> V_171 . V_169 ;
V_49 -> V_176 = V_71 -> V_171 . V_114 ;
V_49 -> V_177 = V_71 -> V_178 ;
F_35 ( L_18 , V_16 ) ;
return 0 ;
error:
V_49 -> V_13 = NULL ;
F_40 ( V_16 ) ;
F_35 ( L_19 , error ) ;
return error ;
}
static void F_81 ( struct V_48 * V_49 ,
struct V_179 * V_180 ,
struct V_181 * V_182 )
{
unsigned long V_183 ;
if ( V_49 -> V_163 == 0 )
V_49 -> V_163 = F_80 ( V_182 -> V_184 , NULL ) ;
if ( V_49 -> V_164 == 0 )
V_49 -> V_164 = F_80 ( V_182 -> V_185 , NULL ) ;
if ( V_182 -> V_186 >= 512 && V_49 -> V_163 > V_182 -> V_186 )
V_49 -> V_163 = F_80 ( V_182 -> V_186 , NULL ) ;
if ( V_182 -> V_187 >= 512 && V_49 -> V_164 > V_182 -> V_187 )
V_49 -> V_164 = F_80 ( V_182 -> V_187 , NULL ) ;
V_183 = F_80 ( F_82 ( V_49 -> V_139 ) , NULL ) ;
if ( V_49 -> V_163 > V_183 )
V_49 -> V_163 = V_183 ;
if ( V_49 -> V_163 > V_188 )
V_49 -> V_163 = V_188 ;
V_49 -> V_189 = ( V_49 -> V_163 + V_190 - 1 ) >> V_191 ;
V_49 -> V_192 . V_193 = L_20 ;
V_49 -> V_192 . V_194 = V_49 -> V_189 * V_195 ;
if ( V_49 -> V_164 > V_183 )
V_49 -> V_164 = V_183 ;
if ( V_49 -> V_164 > V_188 )
V_49 -> V_164 = V_188 ;
V_49 -> V_196 = ( V_49 -> V_164 + V_190 - 1 ) >> V_191 ;
V_49 -> V_197 = V_182 -> V_198 ;
V_49 -> V_199 = F_83 ( V_182 -> V_199 , NULL ) ;
V_49 -> V_200 = F_80 ( V_182 -> V_201 , NULL ) ;
if ( V_49 -> V_200 > V_190 * V_202 )
V_49 -> V_200 = V_190 * V_202 ;
if ( V_49 -> V_200 > V_49 -> V_163 )
V_49 -> V_200 = V_49 -> V_163 ;
if ( V_49 -> V_123 & V_203 ) {
V_49 -> V_165 = V_49 -> V_166 = 0 ;
V_49 -> V_167 = V_49 -> V_168 = 0 ;
}
V_49 -> V_204 = V_182 -> V_204 ;
V_49 -> V_205 = V_182 -> V_205 ;
F_84 ( V_49 -> V_139 , V_49 -> V_164 + 100 , V_49 -> V_163 + 100 ) ;
}
int F_85 ( struct V_48 * V_49 , struct V_179 * V_180 , struct V_206 * V_207 )
{
struct V_181 V_182 ;
struct V_13 * V_16 = V_49 -> V_13 ;
int error ;
F_35 ( L_21 ) ;
if ( V_16 -> V_5 -> V_208 != NULL ) {
error = V_16 -> V_5 -> V_208 ( V_49 , V_180 ) ;
if ( error < 0 )
goto V_209;
}
V_182 . V_207 = V_207 ;
V_182 . V_210 = 0 ;
error = V_16 -> V_5 -> V_182 ( V_49 , V_180 , & V_182 ) ;
if ( error < 0 )
goto V_209;
F_81 ( V_49 , V_180 , & V_182 ) ;
if ( V_49 -> V_177 == 0 ) {
struct V_211 V_212 ;
V_212 . V_207 = V_207 ;
F_86 ( V_207 ) ;
if ( V_16 -> V_5 -> V_213 ( V_49 , V_180 , & V_212 ) >= 0 )
V_49 -> V_177 = V_212 . V_214 ;
}
F_35 ( L_22 ) ;
return 0 ;
V_209:
F_35 ( L_23 , - error ) ;
return error ;
}
void F_87 ( struct V_48 * V_215 , struct V_48 * V_216 )
{
V_215 -> V_123 = V_216 -> V_123 ;
V_215 -> V_163 = V_216 -> V_163 ;
V_215 -> V_164 = V_216 -> V_164 ;
V_215 -> V_165 = V_216 -> V_165 ;
V_215 -> V_166 = V_216 -> V_166 ;
V_215 -> V_167 = V_216 -> V_167 ;
V_215 -> V_168 = V_216 -> V_168 ;
V_215 -> V_151 = V_216 -> V_151 ;
V_215 -> V_150 = V_216 -> V_150 ;
}
void F_88 ( struct V_48 * V_49 )
{
struct V_13 * V_16 = V_49 -> V_13 ;
struct V_43 * V_44 = F_28 ( V_16 -> V_40 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
F_89 ( & V_49 -> V_217 , & V_16 -> V_35 ) ;
F_90 ( & V_49 -> V_218 , & V_44 -> V_219 ) ;
F_91 ( V_220 , & V_16 -> V_221 ) ;
F_4 ( & V_44 -> V_51 ) ;
}
static void F_92 ( struct V_48 * V_49 )
{
struct V_13 * V_16 = V_49 -> V_13 ;
struct V_43 * V_44 ;
if ( V_16 == NULL )
return;
V_44 = F_28 ( V_16 -> V_40 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
F_93 ( & V_49 -> V_217 ) ;
if ( F_44 ( & V_16 -> V_35 ) )
F_79 ( V_220 , & V_16 -> V_221 ) ;
F_17 ( & V_49 -> V_218 ) ;
F_4 ( & V_44 -> V_51 ) ;
F_94 () ;
}
struct V_48 * F_95 ( void )
{
struct V_48 * V_49 ;
V_49 = F_19 ( sizeof( struct V_48 ) , V_21 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_139 = V_49 -> V_222 = F_5 ( - V_37 ) ;
F_22 ( & V_49 -> V_217 ) ;
F_22 ( & V_49 -> V_218 ) ;
F_22 ( & V_49 -> V_223 ) ;
F_22 ( & V_49 -> V_224 ) ;
F_22 ( & V_49 -> V_225 ) ;
F_20 ( & V_49 -> V_226 , 0 ) ;
V_49 -> V_227 = F_96 () ;
if ( ! V_49 -> V_227 ) {
F_26 ( V_49 ) ;
return NULL ;
}
if ( F_97 ( & V_49 -> V_192 ) ) {
F_98 ( V_49 -> V_227 ) ;
F_26 ( V_49 ) ;
return NULL ;
}
F_99 ( & V_49 -> V_228 ) ;
F_99 ( & V_49 -> V_229 ) ;
F_32 ( V_49 ) ;
return V_49 ;
}
void F_100 ( struct V_48 * V_49 )
{
F_35 ( L_24 ) ;
F_92 ( V_49 ) ;
if ( V_49 -> V_137 != NULL )
V_49 -> V_137 ( V_49 ) ;
if ( ! F_7 ( V_49 -> V_222 ) )
F_37 ( V_49 -> V_222 ) ;
if ( ! F_7 ( V_49 -> V_139 ) )
F_37 ( V_49 -> V_139 ) ;
F_40 ( V_49 -> V_13 ) ;
F_101 ( & V_49 -> V_229 ) ;
F_101 ( & V_49 -> V_228 ) ;
F_98 ( V_49 -> V_227 ) ;
F_102 ( & V_49 -> V_192 ) ;
F_26 ( V_49 ) ;
F_103 () ;
F_35 ( L_25 ) ;
}
struct V_48 * F_104 ( struct V_230 * V_231 ,
struct V_1 * V_24 )
{
struct V_48 * V_49 ;
struct V_206 * V_207 ;
int error ;
V_49 = F_95 () ;
if ( ! V_49 )
return F_5 ( - V_20 ) ;
error = - V_20 ;
V_207 = F_105 () ;
if ( V_207 == NULL )
goto error;
error = F_78 ( V_49 , V_231 -> V_232 , V_24 ) ;
if ( error < 0 )
goto error;
F_43 ( ! V_49 -> V_13 ) ;
F_43 ( ! V_49 -> V_13 -> V_5 ) ;
F_43 ( ! V_49 -> V_13 -> V_5 -> V_233 ) ;
error = F_85 ( V_49 , V_231 -> V_180 , V_207 ) ;
if ( error < 0 )
goto error;
if ( V_49 -> V_13 -> V_5 -> V_2 == 3 ) {
if ( V_49 -> V_177 == 0 || V_49 -> V_177 > V_234 )
V_49 -> V_177 = V_234 ;
if ( ! ( V_231 -> V_232 -> V_123 & V_235 ) )
V_49 -> V_151 |= V_236 ;
} else {
if ( V_49 -> V_177 == 0 || V_49 -> V_177 > V_237 )
V_49 -> V_177 = V_237 ;
}
if ( ! ( V_207 -> V_238 & V_239 ) ) {
error = V_24 -> V_5 -> V_240 ( V_49 , V_231 -> V_180 , V_207 ) ;
if ( error < 0 ) {
F_35 ( L_26 , - error ) ;
goto error;
}
}
memcpy ( & V_49 -> V_241 , & V_207 -> V_241 , sizeof( V_49 -> V_241 ) ) ;
F_35 ( L_27 ,
( unsigned long long ) V_49 -> V_241 . V_242 ,
( unsigned long long ) V_49 -> V_241 . V_243 ) ;
F_88 ( V_49 ) ;
V_49 -> V_244 = V_245 ;
F_106 ( V_207 ) ;
return V_49 ;
error:
F_106 ( V_207 ) ;
F_100 ( V_49 ) ;
return F_5 ( error ) ;
}
struct V_48 * F_107 ( struct V_48 * V_216 ,
struct V_179 * V_246 ,
struct V_206 * V_207 ,
T_1 V_110 )
{
struct V_48 * V_49 ;
struct V_206 * V_247 ;
int error ;
F_35 ( L_28 ,
( unsigned long long ) V_207 -> V_241 . V_242 ,
( unsigned long long ) V_207 -> V_241 . V_243 ) ;
V_49 = F_95 () ;
if ( ! V_49 )
return F_5 ( - V_20 ) ;
error = - V_20 ;
V_247 = F_105 () ;
if ( V_247 == NULL )
goto V_248;
V_49 -> V_13 = V_216 -> V_13 ;
V_49 -> V_137 = V_216 -> V_137 ;
F_54 ( & V_49 -> V_13 -> V_25 ) ;
F_87 ( V_49 , V_216 ) ;
V_49 -> V_241 = V_207 -> V_241 ;
error = F_74 ( V_49 ,
V_216 -> V_139 -> V_141 ,
V_110 ) ;
if ( error < 0 )
goto V_248;
error = F_85 ( V_49 , V_246 , V_247 ) ;
if ( error < 0 )
goto V_248;
if ( V_49 -> V_177 == 0 || V_49 -> V_177 > V_249 )
V_49 -> V_177 = V_249 ;
F_35 ( L_29 ,
( unsigned long long ) V_49 -> V_241 . V_242 ,
( unsigned long long ) V_49 -> V_241 . V_243 ) ;
error = F_72 ( V_49 ) ;
if ( error < 0 )
goto V_248;
F_88 ( V_49 ) ;
V_49 -> V_244 = V_245 ;
F_106 ( V_247 ) ;
F_35 ( L_30 , V_49 ) ;
return V_49 ;
V_248:
F_106 ( V_247 ) ;
F_100 ( V_49 ) ;
F_35 ( L_31 , error ) ;
return F_5 ( error ) ;
}
void F_108 ( struct V_41 * V_41 )
{
struct V_43 * V_44 = F_28 ( V_41 , V_45 ) ;
F_22 ( & V_44 -> V_86 ) ;
F_22 ( & V_44 -> V_219 ) ;
#if F_109 ( V_250 )
F_110 ( & V_44 -> V_46 ) ;
#endif
F_111 ( & V_44 -> V_51 ) ;
V_44 -> V_251 = V_252 ;
}
static int F_112 ( struct V_253 * V_253 , struct V_254 * V_254 )
{
struct V_255 * V_256 ;
int V_257 ;
struct V_258 * V_259 = V_254 -> V_260 -> V_261 -> V_262 ;
struct V_41 * V_41 = V_259 -> V_263 -> V_264 -> V_265 ;
V_257 = F_113 ( V_254 , & V_266 ) ;
if ( V_257 < 0 )
return V_257 ;
V_256 = V_254 -> V_267 ;
V_256 -> V_268 = V_41 ;
return 0 ;
}
static void * F_114 ( struct V_255 * V_256 , T_2 * V_269 )
{
struct V_43 * V_44 = F_28 ( V_256 -> V_268 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
return F_115 ( & V_44 -> V_86 , * V_269 ) ;
}
static void * F_116 ( struct V_255 * V_270 , void * V_271 , T_2 * V_272 )
{
struct V_43 * V_44 = F_28 ( V_270 -> V_268 , V_45 ) ;
return F_117 ( V_271 , & V_44 -> V_86 , V_272 ) ;
}
static void F_118 ( struct V_255 * V_270 , void * V_271 )
{
struct V_43 * V_44 = F_28 ( V_270 -> V_268 , V_45 ) ;
F_4 ( & V_44 -> V_51 ) ;
}
static int F_119 ( struct V_255 * V_256 , void * V_271 )
{
struct V_13 * V_16 ;
struct V_43 * V_44 = F_28 ( V_256 -> V_268 , V_45 ) ;
if ( V_271 == & V_44 -> V_86 ) {
F_120 ( V_256 , L_32 ) ;
return 0 ;
}
V_16 = F_121 ( V_271 , struct V_13 , V_52 ) ;
if ( V_16 -> V_26 != V_78 )
return 0 ;
F_122 () ;
F_123 ( V_256 , L_33 ,
V_16 -> V_5 -> V_2 ,
F_124 ( V_16 -> V_36 , V_273 ) ,
F_124 ( V_16 -> V_36 , V_274 ) ,
F_41 ( & V_16 -> V_25 ) ,
V_16 -> V_33 ) ;
F_125 () ;
return 0 ;
}
static int F_126 ( struct V_253 * V_253 , struct V_254 * V_254 )
{
struct V_255 * V_256 ;
int V_257 ;
struct V_258 * V_259 = V_254 -> V_260 -> V_261 -> V_262 ;
struct V_41 * V_41 = V_259 -> V_263 -> V_264 -> V_265 ;
V_257 = F_113 ( V_254 , & V_275 ) ;
if ( V_257 < 0 )
return V_257 ;
V_256 = V_254 -> V_267 ;
V_256 -> V_268 = V_41 ;
return 0 ;
}
static void * F_127 ( struct V_255 * V_256 , T_2 * V_269 )
{
struct V_43 * V_44 = F_28 ( V_256 -> V_268 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
return F_115 ( & V_44 -> V_219 , * V_269 ) ;
}
static void * F_128 ( struct V_255 * V_270 , void * V_271 , T_2 * V_272 )
{
struct V_43 * V_44 = F_28 ( V_270 -> V_268 , V_45 ) ;
return F_117 ( V_271 , & V_44 -> V_219 , V_272 ) ;
}
static void F_129 ( struct V_255 * V_270 , void * V_271 )
{
struct V_43 * V_44 = F_28 ( V_270 -> V_268 , V_45 ) ;
F_4 ( & V_44 -> V_51 ) ;
}
static int F_130 ( struct V_255 * V_256 , void * V_271 )
{
struct V_48 * V_49 ;
struct V_13 * V_16 ;
char V_276 [ 8 ] , V_241 [ 17 ] ;
struct V_43 * V_44 = F_28 ( V_256 -> V_268 , V_45 ) ;
if ( V_271 == & V_44 -> V_219 ) {
F_120 ( V_256 , L_34 ) ;
return 0 ;
}
V_49 = F_121 ( V_271 , struct V_48 , V_218 ) ;
V_16 = V_49 -> V_13 ;
snprintf ( V_276 , 8 , L_35 ,
F_131 ( V_49 -> V_277 ) , F_132 ( V_49 -> V_277 ) ) ;
snprintf ( V_241 , 17 , L_36 ,
( unsigned long long ) V_49 -> V_241 . V_242 ,
( unsigned long long ) V_49 -> V_241 . V_243 ) ;
F_122 () ;
F_123 ( V_256 , L_37 ,
V_16 -> V_5 -> V_2 ,
F_124 ( V_16 -> V_36 , V_273 ) ,
F_124 ( V_16 -> V_36 , V_274 ) ,
V_276 ,
V_241 ,
F_133 ( V_49 ) ) ;
F_125 () ;
return 0 ;
}
int T_3 F_134 ( void )
{
struct V_278 * V_270 ;
V_279 = F_135 ( L_38 , NULL ) ;
if ( ! V_279 )
goto V_22;
V_270 = F_136 ( L_39 , V_280 | V_281 ,
V_279 , & V_282 ) ;
if ( ! V_270 )
goto V_283;
V_270 = F_136 ( L_40 , V_280 | V_281 ,
V_279 , & V_284 ) ;
if ( ! V_270 )
goto V_285;
return 0 ;
V_285:
F_137 ( L_39 , V_279 ) ;
V_283:
F_137 ( L_38 , NULL ) ;
V_22:
return - V_20 ;
}
void F_138 ( void )
{
F_137 ( L_40 , V_279 ) ;
F_137 ( L_39 , V_279 ) ;
F_137 ( L_38 , NULL ) ;
}
