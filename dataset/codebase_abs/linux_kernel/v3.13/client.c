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
F_61 ( & V_84 -> V_52 ,
& V_44 -> V_86 ) ;
F_4 ( & V_44 -> V_51 ) ;
V_84 -> V_87 = V_15 -> V_88 ;
return V_5 -> V_89 ( V_84 , V_81 , V_82 ) ;
}
F_4 ( & V_44 -> V_51 ) ;
V_84 = V_5 -> V_90 ( V_15 ) ;
} while ( ! F_7 ( V_84 ) );
F_35 ( L_10 ,
V_15 -> V_32 ? : L_8 , F_62 ( V_84 ) ) ;
return V_84 ;
}
void F_63 ( struct V_13 * V_16 , int V_91 )
{
F_64 () ;
V_16 -> V_26 = V_91 ;
F_65 ( & V_76 ) ;
}
void F_66 ( struct V_80 * V_92 , int V_39 ,
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
F_67 () ;
}
}
int F_68 ( struct V_13 * V_16 ,
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
if ( F_69 ( V_122 , & V_16 -> V_87 ) )
args . V_123 |= V_124 ;
if ( F_69 ( V_125 , & V_16 -> V_87 ) )
args . V_123 |= V_126 ;
if ( F_69 ( V_127 , & V_16 -> V_87 ) )
args . V_123 |= V_128 ;
if ( F_69 ( V_129 , & V_16 -> V_87 ) )
args . V_123 |= V_130 ;
if ( ! F_7 ( V_16 -> V_36 ) )
return 0 ;
V_112 = F_70 ( & args ) ;
if ( F_7 ( V_112 ) ) {
F_35 ( L_11 ,
V_79 , F_62 ( V_112 ) ) ;
return F_62 ( V_112 ) ;
}
V_16 -> V_36 = V_112 ;
return 0 ;
}
static void F_71 ( struct V_48 * V_49 )
{
if ( V_49 -> V_131 )
F_72 ( V_49 -> V_131 ) ;
}
static int F_73 ( struct V_48 * V_49 )
{
struct V_131 * V_132 ;
struct V_13 * V_16 = V_49 -> V_13 ;
struct V_133 V_134 = {
. V_32 = V_16 -> V_33 ,
. V_115 = (struct V_54 * ) & V_16 -> V_28 ,
. V_30 = V_16 -> V_31 ,
. V_11 = V_16 -> V_5 -> V_2 ,
. V_135 = V_49 -> V_123 & V_136 ?
1 : 0 ,
. V_41 = V_16 -> V_40 ,
} ;
if ( V_134 . V_11 > 3 )
return 0 ;
if ( ( V_49 -> V_123 & V_137 ) &&
( V_49 -> V_123 & V_138 ) )
return 0 ;
switch ( V_16 -> V_38 ) {
default:
V_134 . V_114 = V_139 ;
break;
case V_106 :
V_134 . V_114 = V_140 ;
}
V_132 = F_74 ( & V_134 ) ;
if ( F_7 ( V_132 ) )
return F_62 ( V_132 ) ;
V_49 -> V_131 = V_132 ;
V_49 -> V_141 = F_71 ;
return 0 ;
}
int F_75 ( struct V_48 * V_49 ,
const struct V_80 * V_93 ,
T_1 V_142 )
{
struct V_13 * V_16 = V_49 -> V_13 ;
V_49 -> V_143 = F_76 ( V_16 -> V_36 ,
V_142 ) ;
if ( F_7 ( V_49 -> V_143 ) ) {
F_35 ( L_12 , V_79 ) ;
return F_62 ( V_49 -> V_143 ) ;
}
memcpy ( & V_49 -> V_143 -> V_144 ,
V_93 ,
sizeof( V_49 -> V_143 -> V_144 ) ) ;
V_49 -> V_143 -> V_145 = & V_49 -> V_143 -> V_144 ;
V_49 -> V_143 -> V_146 = 0 ;
if ( V_49 -> V_123 & V_147 )
V_49 -> V_143 -> V_146 = 1 ;
return 0 ;
}
struct V_13 * F_77 ( struct V_13 * V_16 ,
const struct V_80 * V_81 ,
const char * V_82 )
{
int error ;
if ( V_16 -> V_26 == V_78 ) {
F_35 ( L_13 , V_16 ) ;
return V_16 ;
}
error = F_68 ( V_16 , V_81 , V_148 ) ;
if ( error < 0 )
goto error;
F_63 ( V_16 , V_78 ) ;
return V_16 ;
error:
F_63 ( V_16 , error ) ;
F_40 ( V_16 ) ;
F_35 ( L_14 , error ) ;
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
F_35 ( L_15 ) ;
F_66 ( & V_81 , V_71 -> V_48 . V_114 ,
V_71 -> V_93 , V_71 -> V_94 ) ;
if ( V_71 -> V_123 & V_136 )
F_79 ( V_127 , & V_15 . V_88 ) ;
V_16 = F_60 ( & V_15 , & V_81 , NULL , V_148 ) ;
if ( F_7 ( V_16 ) ) {
F_35 ( L_16 , F_62 ( V_16 ) ) ;
return F_62 ( V_16 ) ;
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
error = F_73 ( V_49 ) ;
if ( error < 0 )
goto error;
V_49 -> V_169 = V_71 -> V_48 . V_169 ;
V_49 -> V_170 = V_71 -> V_170 ;
error = F_75 ( V_49 , & V_81 ,
V_71 -> V_171 ) ;
if ( error < 0 )
goto error;
if ( V_71 -> V_172 . V_30 ) {
memcpy ( & V_49 -> V_173 , & V_71 -> V_172 . V_115 ,
V_71 -> V_172 . V_30 ) ;
V_49 -> V_174 = V_71 -> V_172 . V_30 ;
}
V_49 -> V_175 = V_71 -> V_172 . V_2 ;
V_49 -> V_176 = V_71 -> V_172 . V_169 ;
V_49 -> V_177 = V_71 -> V_172 . V_114 ;
V_49 -> V_178 = V_71 -> V_179 ;
F_35 ( L_17 , V_16 ) ;
return 0 ;
error:
V_49 -> V_13 = NULL ;
F_40 ( V_16 ) ;
F_35 ( L_18 , error ) ;
return error ;
}
static void F_81 ( struct V_48 * V_49 ,
struct V_180 * V_181 ,
struct V_182 * V_183 )
{
unsigned long V_184 ;
if ( V_49 -> V_163 == 0 )
V_49 -> V_163 = F_80 ( V_183 -> V_185 , NULL ) ;
if ( V_49 -> V_164 == 0 )
V_49 -> V_164 = F_80 ( V_183 -> V_186 , NULL ) ;
if ( V_183 -> V_187 >= 512 && V_49 -> V_163 > V_183 -> V_187 )
V_49 -> V_163 = F_80 ( V_183 -> V_187 , NULL ) ;
if ( V_183 -> V_188 >= 512 && V_49 -> V_164 > V_183 -> V_188 )
V_49 -> V_164 = F_80 ( V_183 -> V_188 , NULL ) ;
V_184 = F_80 ( F_82 ( V_49 -> V_143 ) , NULL ) ;
if ( V_49 -> V_163 > V_184 )
V_49 -> V_163 = V_184 ;
if ( V_49 -> V_163 > V_189 )
V_49 -> V_163 = V_189 ;
V_49 -> V_190 = ( V_49 -> V_163 + V_191 - 1 ) >> V_192 ;
V_49 -> V_193 . V_194 = L_19 ;
V_49 -> V_193 . V_195 = V_49 -> V_190 * V_196 ;
if ( V_49 -> V_164 > V_184 )
V_49 -> V_164 = V_184 ;
if ( V_49 -> V_164 > V_189 )
V_49 -> V_164 = V_189 ;
V_49 -> V_197 = ( V_49 -> V_164 + V_191 - 1 ) >> V_192 ;
V_49 -> V_198 = F_83 ( V_183 -> V_198 , NULL ) ;
V_49 -> V_199 = F_80 ( V_183 -> V_200 , NULL ) ;
if ( V_49 -> V_199 > V_191 * V_201 )
V_49 -> V_199 = V_191 * V_201 ;
if ( V_49 -> V_199 > V_49 -> V_163 )
V_49 -> V_199 = V_49 -> V_163 ;
if ( V_49 -> V_123 & V_202 ) {
V_49 -> V_165 = V_49 -> V_166 = 0 ;
V_49 -> V_167 = V_49 -> V_168 = 0 ;
}
V_49 -> V_203 = V_183 -> V_203 ;
V_49 -> V_204 = V_183 -> V_204 ;
F_84 ( V_49 -> V_143 , V_49 -> V_164 + 100 , V_49 -> V_163 + 100 ) ;
}
int F_85 ( struct V_48 * V_49 , struct V_180 * V_181 , struct V_205 * V_206 )
{
struct V_182 V_183 ;
struct V_13 * V_16 = V_49 -> V_13 ;
int error ;
F_35 ( L_20 ) ;
if ( V_16 -> V_5 -> V_207 != NULL ) {
error = V_16 -> V_5 -> V_207 ( V_49 , V_181 ) ;
if ( error < 0 )
goto V_208;
}
V_183 . V_206 = V_206 ;
V_183 . V_209 = 0 ;
error = V_16 -> V_5 -> V_183 ( V_49 , V_181 , & V_183 ) ;
if ( error < 0 )
goto V_208;
F_81 ( V_49 , V_181 , & V_183 ) ;
if ( V_49 -> V_178 == 0 ) {
struct V_210 V_211 ;
V_211 . V_206 = V_206 ;
F_86 ( V_206 ) ;
if ( V_16 -> V_5 -> V_212 ( V_49 , V_181 , & V_211 ) >= 0 )
V_49 -> V_178 = V_211 . V_213 ;
}
F_35 ( L_21 ) ;
return 0 ;
V_208:
F_35 ( L_22 , - error ) ;
return error ;
}
void F_87 ( struct V_48 * V_214 , struct V_48 * V_215 )
{
V_214 -> V_123 = V_215 -> V_123 ;
V_214 -> V_163 = V_215 -> V_163 ;
V_214 -> V_164 = V_215 -> V_164 ;
V_214 -> V_165 = V_215 -> V_165 ;
V_214 -> V_166 = V_215 -> V_166 ;
V_214 -> V_167 = V_215 -> V_167 ;
V_214 -> V_168 = V_215 -> V_168 ;
V_214 -> V_151 = V_215 -> V_151 ;
V_214 -> V_150 = V_215 -> V_150 ;
V_214 -> V_170 = V_215 -> V_170 ;
}
void F_88 ( struct V_48 * V_49 )
{
struct V_13 * V_16 = V_49 -> V_13 ;
struct V_43 * V_44 = F_28 ( V_16 -> V_40 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
F_89 ( & V_49 -> V_216 , & V_16 -> V_35 ) ;
F_61 ( & V_49 -> V_217 , & V_44 -> V_218 ) ;
F_90 ( V_219 , & V_16 -> V_220 ) ;
F_4 ( & V_44 -> V_51 ) ;
}
void F_91 ( struct V_48 * V_49 )
{
struct V_13 * V_16 = V_49 -> V_13 ;
struct V_43 * V_44 ;
if ( V_16 == NULL )
return;
V_44 = F_28 ( V_16 -> V_40 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
F_92 ( & V_49 -> V_216 ) ;
if ( F_44 ( & V_16 -> V_35 ) )
F_79 ( V_219 , & V_16 -> V_220 ) ;
F_17 ( & V_49 -> V_217 ) ;
F_4 ( & V_44 -> V_51 ) ;
F_93 () ;
}
struct V_48 * F_94 ( void )
{
struct V_48 * V_49 ;
V_49 = F_19 ( sizeof( struct V_48 ) , V_21 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_143 = V_49 -> V_221 = F_5 ( - V_37 ) ;
F_22 ( & V_49 -> V_216 ) ;
F_22 ( & V_49 -> V_217 ) ;
F_22 ( & V_49 -> V_222 ) ;
F_22 ( & V_49 -> V_223 ) ;
F_22 ( & V_49 -> V_224 ) ;
F_20 ( & V_49 -> V_225 , 0 ) ;
V_49 -> V_226 = F_95 () ;
if ( ! V_49 -> V_226 ) {
F_26 ( V_49 ) ;
return NULL ;
}
if ( F_96 ( & V_49 -> V_193 ) ) {
F_97 ( V_49 -> V_226 ) ;
F_26 ( V_49 ) ;
return NULL ;
}
F_98 ( & V_49 -> V_227 ) ;
F_98 ( & V_49 -> V_228 ) ;
F_32 ( V_49 ) ;
return V_49 ;
}
void F_99 ( struct V_48 * V_49 )
{
F_35 ( L_23 ) ;
F_91 ( V_49 ) ;
if ( V_49 -> V_141 != NULL )
V_49 -> V_141 ( V_49 ) ;
if ( ! F_7 ( V_49 -> V_221 ) )
F_37 ( V_49 -> V_221 ) ;
if ( ! F_7 ( V_49 -> V_143 ) )
F_37 ( V_49 -> V_143 ) ;
F_40 ( V_49 -> V_13 ) ;
F_100 ( & V_49 -> V_228 ) ;
F_100 ( & V_49 -> V_227 ) ;
F_97 ( V_49 -> V_226 ) ;
F_101 ( & V_49 -> V_193 ) ;
F_26 ( V_49 ) ;
F_102 () ;
F_35 ( L_24 ) ;
}
struct V_48 * F_103 ( struct V_229 * V_230 ,
struct V_1 * V_24 )
{
struct V_48 * V_49 ;
struct V_205 * V_206 ;
int error ;
V_49 = F_94 () ;
if ( ! V_49 )
return F_5 ( - V_20 ) ;
error = - V_20 ;
V_206 = F_104 () ;
if ( V_206 == NULL )
goto error;
error = F_78 ( V_49 , V_230 -> V_231 , V_24 ) ;
if ( error < 0 )
goto error;
error = F_85 ( V_49 , V_230 -> V_181 , V_206 ) ;
if ( error < 0 )
goto error;
if ( V_49 -> V_13 -> V_5 -> V_2 == 3 ) {
if ( V_49 -> V_178 == 0 || V_49 -> V_178 > V_232 )
V_49 -> V_178 = V_232 ;
if ( ! ( V_230 -> V_231 -> V_123 & V_233 ) )
V_49 -> V_151 |= V_234 ;
} else {
if ( V_49 -> V_178 == 0 || V_49 -> V_178 > V_235 )
V_49 -> V_178 = V_235 ;
}
if ( ! ( V_206 -> V_236 & V_237 ) ) {
error = V_24 -> V_5 -> V_238 ( V_49 , V_230 -> V_181 , V_206 , NULL ) ;
if ( error < 0 ) {
F_35 ( L_25 , - error ) ;
goto error;
}
}
memcpy ( & V_49 -> V_239 , & V_206 -> V_239 , sizeof( V_49 -> V_239 ) ) ;
F_35 ( L_26 ,
( unsigned long long ) V_49 -> V_239 . V_240 ,
( unsigned long long ) V_49 -> V_239 . V_241 ) ;
F_88 ( V_49 ) ;
V_49 -> V_242 = V_243 ;
F_105 ( V_206 ) ;
return V_49 ;
error:
F_105 ( V_206 ) ;
F_99 ( V_49 ) ;
return F_5 ( error ) ;
}
struct V_48 * F_106 ( struct V_48 * V_215 ,
struct V_180 * V_244 ,
struct V_205 * V_206 ,
T_1 V_110 )
{
struct V_48 * V_49 ;
struct V_205 * V_245 ;
int error ;
F_35 ( L_27 ,
( unsigned long long ) V_206 -> V_239 . V_240 ,
( unsigned long long ) V_206 -> V_239 . V_241 ) ;
V_49 = F_94 () ;
if ( ! V_49 )
return F_5 ( - V_20 ) ;
error = - V_20 ;
V_245 = F_104 () ;
if ( V_245 == NULL )
goto V_246;
V_49 -> V_13 = V_215 -> V_13 ;
V_49 -> V_141 = V_215 -> V_141 ;
F_54 ( & V_49 -> V_13 -> V_25 ) ;
F_87 ( V_49 , V_215 ) ;
V_49 -> V_239 = V_206 -> V_239 ;
error = F_75 ( V_49 ,
V_215 -> V_143 -> V_145 ,
V_110 ) ;
if ( error < 0 )
goto V_246;
error = F_85 ( V_49 , V_244 , V_245 ) ;
if ( error < 0 )
goto V_246;
if ( V_49 -> V_178 == 0 || V_49 -> V_178 > V_247 )
V_49 -> V_178 = V_247 ;
F_35 ( L_28 ,
( unsigned long long ) V_49 -> V_239 . V_240 ,
( unsigned long long ) V_49 -> V_239 . V_241 ) ;
error = F_73 ( V_49 ) ;
if ( error < 0 )
goto V_246;
F_88 ( V_49 ) ;
V_49 -> V_242 = V_243 ;
F_105 ( V_245 ) ;
F_35 ( L_29 , V_49 ) ;
return V_49 ;
V_246:
F_105 ( V_245 ) ;
F_99 ( V_49 ) ;
F_35 ( L_30 , error ) ;
return F_5 ( error ) ;
}
void F_107 ( struct V_41 * V_41 )
{
struct V_43 * V_44 = F_28 ( V_41 , V_45 ) ;
F_22 ( & V_44 -> V_86 ) ;
F_22 ( & V_44 -> V_218 ) ;
#if F_108 ( V_248 )
F_109 ( & V_44 -> V_46 ) ;
#endif
F_110 ( & V_44 -> V_51 ) ;
V_44 -> V_249 = V_250 ;
}
static int F_111 ( struct V_251 * V_251 , struct V_252 * V_252 )
{
struct V_253 * V_254 ;
int V_255 ;
struct V_256 * V_257 = V_252 -> V_258 -> V_259 -> V_260 ;
struct V_41 * V_41 = V_257 -> V_261 -> V_262 -> V_263 ;
V_255 = F_112 ( V_252 , & V_264 ) ;
if ( V_255 < 0 )
return V_255 ;
V_254 = V_252 -> V_265 ;
V_254 -> V_266 = V_41 ;
return 0 ;
}
static void * F_113 ( struct V_253 * V_254 , T_2 * V_267 )
{
struct V_43 * V_44 = F_28 ( V_254 -> V_266 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
return F_114 ( & V_44 -> V_86 , * V_267 ) ;
}
static void * F_115 ( struct V_253 * V_268 , void * V_269 , T_2 * V_270 )
{
struct V_43 * V_44 = F_28 ( V_268 -> V_266 , V_45 ) ;
return F_116 ( V_269 , & V_44 -> V_86 , V_270 ) ;
}
static void F_117 ( struct V_253 * V_268 , void * V_269 )
{
struct V_43 * V_44 = F_28 ( V_268 -> V_266 , V_45 ) ;
F_4 ( & V_44 -> V_51 ) ;
}
static int F_118 ( struct V_253 * V_254 , void * V_269 )
{
struct V_13 * V_16 ;
struct V_43 * V_44 = F_28 ( V_254 -> V_266 , V_45 ) ;
if ( V_269 == & V_44 -> V_86 ) {
F_119 ( V_254 , L_31 ) ;
return 0 ;
}
V_16 = F_120 ( V_269 , struct V_13 , V_52 ) ;
if ( V_16 -> V_26 != V_78 )
return 0 ;
F_121 () ;
F_122 ( V_254 , L_32 ,
V_16 -> V_5 -> V_2 ,
F_123 ( V_16 -> V_36 , V_271 ) ,
F_123 ( V_16 -> V_36 , V_272 ) ,
F_41 ( & V_16 -> V_25 ) ,
V_16 -> V_33 ) ;
F_124 () ;
return 0 ;
}
static int F_125 ( struct V_251 * V_251 , struct V_252 * V_252 )
{
struct V_253 * V_254 ;
int V_255 ;
struct V_256 * V_257 = V_252 -> V_258 -> V_259 -> V_260 ;
struct V_41 * V_41 = V_257 -> V_261 -> V_262 -> V_263 ;
V_255 = F_112 ( V_252 , & V_273 ) ;
if ( V_255 < 0 )
return V_255 ;
V_254 = V_252 -> V_265 ;
V_254 -> V_266 = V_41 ;
return 0 ;
}
static void * F_126 ( struct V_253 * V_254 , T_2 * V_267 )
{
struct V_43 * V_44 = F_28 ( V_254 -> V_266 , V_45 ) ;
F_2 ( & V_44 -> V_51 ) ;
return F_114 ( & V_44 -> V_218 , * V_267 ) ;
}
static void * F_127 ( struct V_253 * V_268 , void * V_269 , T_2 * V_270 )
{
struct V_43 * V_44 = F_28 ( V_268 -> V_266 , V_45 ) ;
return F_116 ( V_269 , & V_44 -> V_218 , V_270 ) ;
}
static void F_128 ( struct V_253 * V_268 , void * V_269 )
{
struct V_43 * V_44 = F_28 ( V_268 -> V_266 , V_45 ) ;
F_4 ( & V_44 -> V_51 ) ;
}
static int F_129 ( struct V_253 * V_254 , void * V_269 )
{
struct V_48 * V_49 ;
struct V_13 * V_16 ;
char V_274 [ 8 ] , V_239 [ 17 ] ;
struct V_43 * V_44 = F_28 ( V_254 -> V_266 , V_45 ) ;
if ( V_269 == & V_44 -> V_218 ) {
F_119 ( V_254 , L_33 ) ;
return 0 ;
}
V_49 = F_120 ( V_269 , struct V_48 , V_217 ) ;
V_16 = V_49 -> V_13 ;
snprintf ( V_274 , 8 , L_34 ,
F_130 ( V_49 -> V_275 ) , F_131 ( V_49 -> V_275 ) ) ;
snprintf ( V_239 , 17 , L_35 ,
( unsigned long long ) V_49 -> V_239 . V_240 ,
( unsigned long long ) V_49 -> V_239 . V_241 ) ;
F_121 () ;
F_122 ( V_254 , L_36 ,
V_16 -> V_5 -> V_2 ,
F_123 ( V_16 -> V_36 , V_271 ) ,
F_123 ( V_16 -> V_36 , V_272 ) ,
V_274 ,
V_239 ,
F_132 ( V_49 ) ) ;
F_124 () ;
return 0 ;
}
int T_3 F_133 ( void )
{
struct V_276 * V_268 ;
V_277 = F_134 ( L_37 , NULL ) ;
if ( ! V_277 )
goto V_22;
V_268 = F_135 ( L_38 , V_278 | V_279 ,
V_277 , & V_280 ) ;
if ( ! V_268 )
goto V_281;
V_268 = F_135 ( L_39 , V_278 | V_279 ,
V_277 , & V_282 ) ;
if ( ! V_268 )
goto V_283;
return 0 ;
V_283:
F_136 ( L_38 , V_277 ) ;
V_281:
F_136 ( L_37 , NULL ) ;
V_22:
return - V_20 ;
}
void F_137 ( void )
{
F_136 ( L_39 , V_277 ) ;
F_136 ( L_38 , V_277 ) ;
F_136 ( L_37 , NULL ) ;
}
