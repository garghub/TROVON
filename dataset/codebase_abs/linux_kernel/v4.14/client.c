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
F_26 ( V_17 -> V_53 ) ;
F_26 ( V_17 ) ;
}
void F_39 ( struct V_14 * V_17 )
{
struct V_45 * V_46 ;
if ( ! V_17 )
return;
V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
if ( F_40 ( & V_17 -> V_27 , & V_46 -> V_54 ) ) {
F_17 ( & V_17 -> V_55 ) ;
F_30 ( V_17 ) ;
F_4 ( & V_46 -> V_54 ) ;
F_41 ( ! F_42 ( & V_17 -> V_37 ) ) ;
V_17 -> V_5 -> V_56 ( V_17 ) ;
}
}
static struct V_14 * F_43 ( const struct V_15 * V_57 )
{
struct V_14 * V_17 ;
const struct V_58 * V_59 = V_57 -> V_31 ;
struct V_45 * V_46 = F_28 ( V_57 -> V_43 , V_47 ) ;
F_3 (clp, &nn->nfs_client_list, cl_share_link) {
const struct V_58 * V_60 = (struct V_58 * ) & V_17 -> V_30 ;
if ( V_17 -> V_28 < 0 )
continue;
if ( V_17 -> V_5 != V_57 -> V_25 -> V_5 )
continue;
if ( V_17 -> V_40 != V_57 -> V_41 )
continue;
if ( V_17 -> V_61 != V_57 -> V_62 )
continue;
if ( ! F_44 ( V_59 , V_60 ) )
if ( F_7 ( V_17 -> V_38 ) ||
! F_45 ( V_17 -> V_38 ,
V_59 ) )
continue;
F_46 ( & V_17 -> V_27 ) ;
return V_17 ;
}
return NULL ;
}
bool F_47 ( const struct V_14 * V_17 )
{
return V_17 -> V_28 <= V_63 ;
}
int F_48 ( const struct V_14 * V_17 )
{
if ( V_17 -> V_28 > V_63 ) {
F_41 ( 1 ) ;
return - V_39 ;
}
return V_17 -> V_28 ;
}
int F_49 ( const struct V_14 * V_17 )
{
return F_50 ( V_64 ,
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
return F_5 ( - V_65 ) ;
}
if ( V_17 -> V_28 < V_63 ) {
error = V_17 -> V_28 ;
F_39 ( V_17 ) ;
return F_5 ( error ) ;
}
F_52 () ;
return V_17 ;
}
struct V_14 * F_53 ( const struct V_15 * V_16 )
{
struct V_14 * V_17 , * V_66 = NULL ;
struct V_45 * V_46 = F_28 ( V_16 -> V_43 , V_47 ) ;
const struct V_67 * V_5 = V_16 -> V_25 -> V_5 ;
if ( V_16 -> V_34 == NULL ) {
F_54 ( 1 ) ;
return NULL ;
}
do {
F_2 ( & V_46 -> V_54 ) ;
V_17 = F_43 ( V_16 ) ;
if ( V_17 ) {
F_4 ( & V_46 -> V_54 ) ;
if ( V_66 )
V_66 -> V_5 -> V_56 ( V_66 ) ;
return F_51 ( V_16 , V_17 ) ;
}
if ( V_66 ) {
F_55 ( & V_66 -> V_55 ,
& V_46 -> V_68 ) ;
F_4 ( & V_46 -> V_54 ) ;
V_66 -> V_69 = V_16 -> V_70 ;
return V_5 -> V_71 ( V_66 , V_16 ) ;
}
F_4 ( & V_46 -> V_54 ) ;
V_66 = V_5 -> V_72 ( V_16 ) ;
} while ( ! F_7 ( V_66 ) );
return V_66 ;
}
void F_56 ( struct V_14 * V_17 , int V_73 )
{
F_57 () ;
V_17 -> V_28 = V_73 ;
F_58 ( & V_64 ) ;
}
void F_59 ( struct V_74 * V_75 , int V_41 ,
int V_76 , int V_77 )
{
V_75 -> V_78 = V_76 * V_79 / 10 ;
V_75 -> V_80 = V_77 ;
switch ( V_41 ) {
case V_81 :
case V_82 :
if ( V_77 == V_83 )
V_75 -> V_80 = V_84 ;
if ( V_76 == V_85 || V_75 -> V_80 == 0 )
V_75 -> V_78 = V_86 * V_79 / 10 ;
if ( V_75 -> V_78 > V_87 )
V_75 -> V_78 = V_87 ;
V_75 -> V_88 = V_75 -> V_78 ;
V_75 -> V_89 = V_75 -> V_78 + ( V_75 -> V_88 * V_75 -> V_80 ) ;
if ( V_75 -> V_89 > V_87 )
V_75 -> V_89 = V_87 ;
if ( V_75 -> V_89 < V_75 -> V_78 )
V_75 -> V_89 = V_75 -> V_78 ;
V_75 -> V_90 = 0 ;
break;
case V_91 :
if ( V_77 == V_83 )
V_75 -> V_80 = V_92 ;
if ( V_76 == V_85 || V_75 -> V_78 == 0 )
V_75 -> V_78 = V_93 * V_79 / 10 ;
if ( V_75 -> V_78 > V_94 )
V_75 -> V_78 = V_94 ;
V_75 -> V_89 = V_94 ;
V_75 -> V_90 = 1 ;
break;
default:
F_60 () ;
}
}
int F_61 ( struct V_14 * V_17 ,
const struct V_15 * V_16 ,
T_1 V_95 )
{
struct V_96 * V_97 = NULL ;
struct V_98 args = {
. V_43 = V_17 -> V_42 ,
. V_99 = V_17 -> V_40 ,
. V_100 = (struct V_58 * ) & V_17 -> V_30 ,
. V_101 = V_17 -> V_33 ,
. V_102 = V_16 -> V_103 ,
. V_104 = V_17 -> V_35 ,
. V_105 = V_16 -> V_105 ,
. V_106 = & V_107 ,
. V_2 = V_17 -> V_5 -> V_2 ,
. V_108 = V_95 ,
} ;
if ( F_62 ( V_109 , & V_17 -> V_69 ) )
args . V_110 |= V_111 ;
if ( F_62 ( V_112 , & V_17 -> V_69 ) )
args . V_110 |= V_113 ;
if ( F_62 ( V_114 , & V_17 -> V_69 ) )
args . V_110 |= V_115 ;
if ( F_62 ( V_116 , & V_17 -> V_69 ) )
args . V_110 |= V_117 ;
if ( ! F_7 ( V_17 -> V_38 ) )
return 0 ;
V_97 = F_63 ( & args ) ;
if ( F_7 ( V_97 ) ) {
F_64 ( L_4 ,
V_118 , F_65 ( V_97 ) ) ;
return F_65 ( V_97 ) ;
}
V_17 -> V_38 = V_97 ;
return 0 ;
}
static void F_66 ( struct V_50 * V_51 )
{
if ( V_51 -> V_119 )
F_67 ( V_51 -> V_119 ) ;
}
static int F_68 ( struct V_50 * V_51 )
{
struct V_119 * V_120 ;
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_121 V_122 = {
. V_34 = V_17 -> V_35 ,
. V_100 = (struct V_58 * ) & V_17 -> V_30 ,
. V_32 = V_17 -> V_33 ,
. V_12 = V_17 -> V_5 -> V_2 ,
. V_123 = V_51 -> V_110 & V_124 ?
1 : 0 ,
. V_43 = V_17 -> V_42 ,
. V_125 = V_17 -> V_24 -> V_5 -> V_125 ,
} ;
if ( V_122 . V_12 > 3 )
return 0 ;
if ( ( V_51 -> V_110 & V_126 ) &&
( V_51 -> V_110 & V_127 ) )
return 0 ;
switch ( V_17 -> V_40 ) {
default:
V_122 . V_99 = V_128 ;
break;
case V_91 :
V_122 . V_99 = V_129 ;
}
V_120 = F_69 ( & V_122 ) ;
if ( F_7 ( V_120 ) )
return F_65 ( V_120 ) ;
V_51 -> V_119 = V_120 ;
V_51 -> V_130 = F_66 ;
return 0 ;
}
int F_70 ( struct V_50 * V_51 ,
const struct V_74 * V_76 ,
T_1 V_131 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
V_51 -> V_132 = F_71 ( V_17 -> V_38 ,
V_131 ) ;
if ( F_7 ( V_51 -> V_132 ) ) {
F_64 ( L_5 , V_118 ) ;
return F_65 ( V_51 -> V_132 ) ;
}
memcpy ( & V_51 -> V_132 -> V_133 ,
V_76 ,
sizeof( V_51 -> V_132 -> V_133 ) ) ;
V_51 -> V_132 -> V_134 = & V_51 -> V_132 -> V_133 ;
V_51 -> V_132 -> V_135 = 0 ;
if ( V_51 -> V_110 & V_136 )
V_51 -> V_132 -> V_135 = 1 ;
return 0 ;
}
struct V_14 * F_72 ( struct V_14 * V_17 ,
const struct V_15 * V_16 )
{
int error ;
if ( V_17 -> V_28 == V_63 )
return V_17 ;
error = F_61 ( V_17 , V_16 , V_137 ) ;
F_56 ( V_17 , error == 0 ? V_63 : error ) ;
if ( error < 0 ) {
F_39 ( V_17 ) ;
V_17 = F_5 ( error ) ;
}
return V_17 ;
}
static int F_73 ( struct V_50 * V_51 ,
const struct V_138 * V_57 ,
struct V_1 * V_25 )
{
struct V_74 V_103 ;
struct V_15 V_16 = {
. V_34 = V_57 -> V_50 . V_34 ,
. V_31 = ( const struct V_58 * ) & V_57 -> V_50 . V_100 ,
. V_32 = V_57 -> V_50 . V_32 ,
. V_25 = V_25 ,
. V_41 = V_57 -> V_50 . V_99 ,
. V_43 = V_57 -> V_43 ,
. V_103 = & V_103 ,
} ;
struct V_14 * V_17 ;
int error ;
F_59 ( & V_103 , V_57 -> V_50 . V_99 ,
V_57 -> V_76 , V_57 -> V_77 ) ;
if ( V_57 -> V_110 & V_124 )
F_74 ( V_114 , & V_16 . V_70 ) ;
V_17 = F_53 ( & V_16 ) ;
if ( F_7 ( V_17 ) )
return F_65 ( V_17 ) ;
V_51 -> V_14 = V_17 ;
V_51 -> V_110 = V_57 -> V_110 ;
V_51 -> V_139 = V_57 -> V_139 ;
V_51 -> V_140 |= V_141 | V_142 | V_143 |
V_144 | V_145 | V_146 | V_147 |
V_148 | V_149 | V_150 ;
if ( V_57 -> V_151 )
V_51 -> V_151 = F_75 ( V_57 -> V_151 , NULL ) ;
if ( V_57 -> V_152 )
V_51 -> V_152 = F_75 ( V_57 -> V_152 , NULL ) ;
V_51 -> V_153 = V_57 -> V_153 * V_79 ;
V_51 -> V_154 = V_57 -> V_154 * V_79 ;
V_51 -> V_155 = V_57 -> V_155 * V_79 ;
V_51 -> V_156 = V_57 -> V_156 * V_79 ;
error = F_68 ( V_51 ) ;
if ( error < 0 )
goto error;
V_51 -> V_157 = V_57 -> V_50 . V_157 ;
V_51 -> V_158 = V_57 -> V_158 ;
error = F_70 ( V_51 , & V_103 ,
V_57 -> V_159 ) ;
if ( error < 0 )
goto error;
if ( V_57 -> V_160 . V_32 ) {
memcpy ( & V_51 -> V_161 , & V_57 -> V_160 . V_100 ,
V_57 -> V_160 . V_32 ) ;
V_51 -> V_162 = V_57 -> V_160 . V_32 ;
}
V_51 -> V_163 = V_57 -> V_160 . V_2 ;
V_51 -> V_164 = V_57 -> V_160 . V_157 ;
V_51 -> V_165 = V_57 -> V_160 . V_99 ;
V_51 -> V_166 = V_57 -> V_167 ;
return 0 ;
error:
V_51 -> V_14 = NULL ;
F_39 ( V_17 ) ;
return error ;
}
static void F_76 ( struct V_50 * V_51 ,
struct V_168 * V_169 )
{
unsigned long V_170 ;
if ( V_51 -> V_151 == 0 )
V_51 -> V_151 = F_75 ( V_169 -> V_171 , NULL ) ;
if ( V_51 -> V_152 == 0 )
V_51 -> V_152 = F_75 ( V_169 -> V_172 , NULL ) ;
if ( V_169 -> V_173 >= 512 && V_51 -> V_151 > V_169 -> V_173 )
V_51 -> V_151 = F_75 ( V_169 -> V_173 , NULL ) ;
if ( V_169 -> V_174 >= 512 && V_51 -> V_152 > V_169 -> V_174 )
V_51 -> V_152 = F_75 ( V_169 -> V_174 , NULL ) ;
V_170 = F_75 ( F_77 ( V_51 -> V_132 ) , NULL ) ;
if ( V_51 -> V_151 > V_170 )
V_51 -> V_151 = V_170 ;
if ( V_51 -> V_151 > V_175 )
V_51 -> V_151 = V_175 ;
V_51 -> V_176 = ( V_51 -> V_151 + V_177 - 1 ) >> V_178 ;
if ( V_51 -> V_152 > V_170 )
V_51 -> V_152 = V_170 ;
if ( V_51 -> V_152 > V_175 )
V_51 -> V_152 = V_175 ;
V_51 -> V_179 = ( V_51 -> V_152 + V_177 - 1 ) >> V_178 ;
V_51 -> V_180 = F_78 ( V_169 -> V_180 , NULL ) ;
V_51 -> V_181 = F_75 ( V_169 -> V_182 , NULL ) ;
if ( V_51 -> V_181 > V_177 * V_183 )
V_51 -> V_181 = V_177 * V_183 ;
if ( V_51 -> V_181 > V_51 -> V_151 )
V_51 -> V_181 = V_51 -> V_151 ;
if ( V_51 -> V_110 & V_184 ) {
V_51 -> V_153 = V_51 -> V_154 = 0 ;
V_51 -> V_155 = V_51 -> V_156 = 0 ;
}
V_51 -> V_185 = V_169 -> V_185 ;
V_51 -> V_186 = V_169 -> V_186 ;
V_51 -> V_187 = V_169 -> V_187 ;
F_79 ( V_51 -> V_132 , V_51 -> V_152 + 100 , V_51 -> V_151 + 100 ) ;
}
int F_80 ( struct V_50 * V_51 , struct V_188 * V_189 , struct V_190 * V_191 )
{
struct V_168 V_169 ;
struct V_14 * V_17 = V_51 -> V_14 ;
int error ;
if ( V_17 -> V_5 -> V_192 != NULL ) {
error = V_17 -> V_5 -> V_192 ( V_51 , V_189 ) ;
if ( error < 0 )
return error ;
}
V_169 . V_191 = V_191 ;
V_169 . V_193 = 0 ;
memset ( V_169 . V_194 , 0 , sizeof( V_169 . V_194 ) ) ;
error = V_17 -> V_5 -> V_169 ( V_51 , V_189 , & V_169 ) ;
if ( error < 0 )
return error ;
F_76 ( V_51 , & V_169 ) ;
if ( V_51 -> V_166 == 0 ) {
struct V_195 V_196 ;
V_196 . V_191 = V_191 ;
F_81 ( V_191 ) ;
if ( V_17 -> V_5 -> V_197 ( V_51 , V_189 , & V_196 ) >= 0 )
V_51 -> V_166 = V_196 . V_198 ;
}
return 0 ;
}
void F_82 ( struct V_50 * V_199 , struct V_50 * V_200 )
{
V_199 -> V_110 = V_200 -> V_110 ;
V_199 -> V_151 = V_200 -> V_151 ;
V_199 -> V_152 = V_200 -> V_152 ;
V_199 -> V_153 = V_200 -> V_153 ;
V_199 -> V_154 = V_200 -> V_154 ;
V_199 -> V_155 = V_200 -> V_155 ;
V_199 -> V_156 = V_200 -> V_156 ;
V_199 -> V_140 = V_200 -> V_140 ;
V_199 -> V_139 = V_200 -> V_139 ;
V_199 -> V_158 = V_200 -> V_158 ;
V_199 -> V_157 = V_200 -> V_157 ;
}
void F_83 ( struct V_50 * V_51 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_45 * V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
F_2 ( & V_46 -> V_54 ) ;
F_84 ( & V_51 -> V_201 , & V_17 -> V_37 ) ;
F_55 ( & V_51 -> V_202 , & V_46 -> V_203 ) ;
F_85 ( V_204 , & V_17 -> V_205 ) ;
F_4 ( & V_46 -> V_54 ) ;
}
void F_86 ( struct V_50 * V_51 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_45 * V_46 ;
if ( V_17 == NULL )
return;
V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
F_2 ( & V_46 -> V_54 ) ;
F_87 ( & V_51 -> V_201 ) ;
if ( F_42 ( & V_17 -> V_37 ) )
F_74 ( V_204 , & V_17 -> V_205 ) ;
F_17 ( & V_51 -> V_202 ) ;
F_4 ( & V_46 -> V_54 ) ;
F_88 () ;
}
struct V_50 * F_89 ( void )
{
struct V_50 * V_51 ;
V_51 = F_19 ( sizeof( struct V_50 ) , V_22 ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_132 = V_51 -> V_206 = F_5 ( - V_39 ) ;
F_22 ( & V_51 -> V_201 ) ;
F_22 ( & V_51 -> V_202 ) ;
F_22 ( & V_51 -> V_207 ) ;
F_22 ( & V_51 -> V_208 ) ;
F_22 ( & V_51 -> V_209 ) ;
F_20 ( & V_51 -> V_210 , 0 ) ;
V_51 -> V_211 = F_90 () ;
if ( ! V_51 -> V_211 ) {
F_26 ( V_51 ) ;
return NULL ;
}
F_91 ( & V_51 -> V_212 ) ;
F_91 ( & V_51 -> V_213 ) ;
F_32 ( V_51 ) ;
F_33 ( & V_51 -> V_214 , L_6 ) ;
return V_51 ;
}
void F_92 ( struct V_50 * V_51 )
{
F_86 ( V_51 ) ;
if ( V_51 -> V_130 != NULL )
V_51 -> V_130 ( V_51 ) ;
if ( ! F_7 ( V_51 -> V_206 ) )
F_36 ( V_51 -> V_206 ) ;
if ( ! F_7 ( V_51 -> V_132 ) )
F_36 ( V_51 -> V_132 ) ;
F_39 ( V_51 -> V_14 ) ;
F_93 ( & V_51 -> V_213 ) ;
F_93 ( & V_51 -> V_212 ) ;
F_94 ( V_51 -> V_211 ) ;
F_26 ( V_51 ) ;
F_95 () ;
}
struct V_50 * F_96 ( struct V_215 * V_216 ,
struct V_1 * V_25 )
{
struct V_50 * V_51 ;
struct V_190 * V_191 ;
int error ;
V_51 = F_89 () ;
if ( ! V_51 )
return F_5 ( - V_21 ) ;
error = - V_21 ;
V_191 = F_97 () ;
if ( V_191 == NULL )
goto error;
error = F_73 ( V_51 , V_216 -> V_217 , V_25 ) ;
if ( error < 0 )
goto error;
error = F_80 ( V_51 , V_216 -> V_189 , V_191 ) ;
if ( error < 0 )
goto error;
if ( V_51 -> V_14 -> V_5 -> V_2 == 3 ) {
if ( V_51 -> V_166 == 0 || V_51 -> V_166 > V_218 )
V_51 -> V_166 = V_218 ;
if ( ! ( V_216 -> V_217 -> V_110 & V_219 ) )
V_51 -> V_140 |= V_220 ;
} else {
if ( V_51 -> V_166 == 0 || V_51 -> V_166 > V_221 )
V_51 -> V_166 = V_221 ;
}
if ( ! ( V_191 -> V_222 & V_223 ) ) {
error = V_25 -> V_5 -> V_224 ( V_51 , V_216 -> V_189 , V_191 , NULL ) ;
if ( error < 0 ) {
F_64 ( L_7 , - error ) ;
goto error;
}
}
memcpy ( & V_51 -> V_225 , & V_191 -> V_225 , sizeof( V_51 -> V_225 ) ) ;
F_64 ( L_8 ,
( unsigned long long ) V_51 -> V_225 . V_226 ,
( unsigned long long ) V_51 -> V_225 . V_227 ) ;
F_83 ( V_51 ) ;
V_51 -> V_228 = V_229 ;
F_98 ( V_191 ) ;
return V_51 ;
error:
F_98 ( V_191 ) ;
F_92 ( V_51 ) ;
return F_5 ( error ) ;
}
struct V_50 * F_99 ( struct V_50 * V_200 ,
struct V_188 * V_230 ,
struct V_190 * V_191 ,
T_1 V_95 )
{
struct V_50 * V_51 ;
struct V_190 * V_231 ;
int error ;
V_51 = F_89 () ;
if ( ! V_51 )
return F_5 ( - V_21 ) ;
error = - V_21 ;
V_231 = F_97 () ;
if ( V_231 == NULL )
goto V_232;
V_51 -> V_14 = V_200 -> V_14 ;
V_51 -> V_130 = V_200 -> V_130 ;
F_46 ( & V_51 -> V_14 -> V_27 ) ;
F_82 ( V_51 , V_200 ) ;
V_51 -> V_225 = V_191 -> V_225 ;
error = F_70 ( V_51 ,
V_200 -> V_132 -> V_134 ,
V_95 ) ;
if ( error < 0 )
goto V_232;
error = F_80 ( V_51 , V_230 , V_231 ) ;
if ( error < 0 )
goto V_232;
if ( V_51 -> V_166 == 0 || V_51 -> V_166 > V_233 )
V_51 -> V_166 = V_233 ;
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
F_22 ( & V_46 -> V_68 ) ;
F_22 ( & V_46 -> V_203 ) ;
#if F_101 ( V_234 )
F_102 ( & V_46 -> V_48 ) ;
#endif
F_103 ( & V_46 -> V_54 ) ;
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
return F_110 ( V_244 , & V_46 -> V_68 , V_245 ) ;
}
static void F_111 ( struct V_240 * V_243 , void * V_244 )
__releases( &nn->nfs_client_lock
static int F_112 ( struct V_240 * V_241 , void * V_244 )
{
struct V_14 * V_17 ;
struct V_45 * V_46 = F_28 ( F_109 ( V_241 ) , V_47 ) ;
if ( V_244 == & V_46 -> V_68 ) {
F_113 ( V_241 , L_9 ) ;
return 0 ;
}
V_17 = F_114 ( V_244 , struct V_14 , V_55 ) ;
if ( V_17 -> V_28 != V_63 )
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
return F_110 ( V_244 , & V_46 -> V_203 , V_245 ) ;
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
if ( V_244 == & V_46 -> V_203 ) {
F_113 ( V_241 , L_11
L_12 ) ;
return 0 ;
}
V_51 = F_114 ( V_244 , struct V_50 , V_202 ) ;
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
