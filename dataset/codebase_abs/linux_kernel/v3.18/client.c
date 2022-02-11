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
F_35 ( L_4 , V_17 -> V_5 -> V_2 ) ;
F_36 ( V_17 ) ;
if ( ! F_7 ( V_17 -> V_38 ) )
F_37 ( V_17 -> V_38 ) ;
if ( V_17 -> V_44 != NULL )
F_38 ( V_17 -> V_44 ) ;
F_39 ( V_17 -> V_42 ) ;
F_12 ( V_17 -> V_24 ) ;
F_26 ( V_17 -> V_35 ) ;
F_26 ( V_17 -> V_53 ) ;
F_26 ( V_17 ) ;
F_35 ( L_5 ) ;
}
void F_40 ( struct V_14 * V_17 )
{
struct V_45 * V_46 ;
if ( ! V_17 )
return;
F_35 ( L_6 , F_41 ( & V_17 -> V_27 ) ) ;
V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
if ( F_42 ( & V_17 -> V_27 , & V_46 -> V_54 ) ) {
F_17 ( & V_17 -> V_55 ) ;
F_30 ( V_17 ) ;
F_4 ( & V_46 -> V_54 ) ;
F_43 ( ! F_44 ( & V_17 -> V_37 ) ) ;
V_17 -> V_5 -> V_56 ( V_17 ) ;
}
}
static int F_45 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 )
{
const struct V_60 * V_61 = ( const struct V_60 * ) V_58 ;
const struct V_60 * V_62 = ( const struct V_60 * ) V_59 ;
if ( ! F_46 ( & V_61 -> V_63 , & V_62 -> V_63 ) )
return 0 ;
else if ( F_47 ( & V_61 -> V_63 ) & V_64 )
return V_61 -> V_65 == V_62 -> V_65 ;
return 1 ;
}
static int F_45 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 )
{
return 0 ;
}
static int F_48 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 )
{
const struct V_66 * V_61 = ( const struct V_66 * ) V_58 ;
const struct V_66 * V_62 = ( const struct V_66 * ) V_59 ;
return V_61 -> V_67 . V_68 == V_62 -> V_67 . V_68 ;
}
static int F_49 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 )
{
const struct V_60 * V_61 = ( const struct V_60 * ) V_58 ;
const struct V_60 * V_62 = ( const struct V_60 * ) V_59 ;
return F_45 ( V_58 , V_59 ) &&
( V_61 -> V_69 == V_62 -> V_69 ) ;
}
static int F_50 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 )
{
const struct V_66 * V_61 = ( const struct V_66 * ) V_58 ;
const struct V_66 * V_62 = ( const struct V_66 * ) V_59 ;
return F_48 ( V_58 , V_59 ) &&
( V_61 -> V_70 == V_62 -> V_70 ) ;
}
int F_51 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 )
{
if ( V_58 -> V_71 != V_59 -> V_71 )
return 0 ;
switch ( V_58 -> V_71 ) {
case V_72 :
return F_48 ( V_58 , V_59 ) ;
case V_73 :
return F_45 ( V_58 , V_59 ) ;
}
return 0 ;
}
static int F_52 ( const struct V_57 * V_58 ,
const struct V_57 * V_59 )
{
if ( V_58 -> V_71 != V_59 -> V_71 )
return 0 ;
switch ( V_58 -> V_71 ) {
case V_72 :
return F_50 ( V_58 , V_59 ) ;
case V_73 :
return F_49 ( V_58 , V_59 ) ;
}
return 0 ;
}
static struct V_14 * F_53 ( const struct V_15 * V_74 )
{
struct V_14 * V_17 ;
const struct V_57 * V_75 = V_74 -> V_31 ;
struct V_45 * V_46 = F_28 ( V_74 -> V_43 , V_47 ) ;
F_3 (clp, &nn->nfs_client_list, cl_share_link) {
const struct V_57 * V_76 = (struct V_57 * ) & V_17 -> V_30 ;
if ( V_17 -> V_28 < 0 )
continue;
if ( V_17 -> V_5 != V_74 -> V_25 -> V_5 )
continue;
if ( V_17 -> V_40 != V_74 -> V_41 )
continue;
if ( V_17 -> V_77 != V_74 -> V_78 )
continue;
if ( ! F_52 ( V_75 , V_76 ) )
continue;
F_54 ( & V_17 -> V_27 ) ;
return V_17 ;
}
return NULL ;
}
static bool F_55 ( const struct V_14 * V_17 )
{
return V_17 -> V_28 != V_29 ;
}
int F_56 ( const struct V_14 * V_17 )
{
return F_57 ( V_79 ,
F_55 ( V_17 ) ) ;
}
static struct V_14 *
F_58 ( const struct V_15 * V_16 ,
struct V_14 * V_17 )
{
int error ;
error = F_56 ( V_17 ) ;
if ( error < 0 ) {
F_40 ( V_17 ) ;
return F_5 ( - V_80 ) ;
}
if ( V_17 -> V_28 < V_81 ) {
error = V_17 -> V_28 ;
F_40 ( V_17 ) ;
return F_5 ( error ) ;
}
F_59 () ;
F_35 ( L_7 ,
V_82 , V_17 , V_16 -> V_34 ? : L_8 ) ;
return V_17 ;
}
struct V_14 *
F_60 ( const struct V_15 * V_16 ,
const struct V_83 * V_84 ,
const char * V_85 ,
T_1 V_86 )
{
struct V_14 * V_17 , * V_87 = NULL ;
struct V_45 * V_46 = F_28 ( V_16 -> V_43 , V_47 ) ;
const struct V_88 * V_5 = V_16 -> V_25 -> V_5 ;
if ( V_16 -> V_34 == NULL ) {
F_61 ( 1 ) ;
return NULL ;
}
F_35 ( L_9 ,
V_16 -> V_34 , V_5 -> V_2 ) ;
do {
F_2 ( & V_46 -> V_54 ) ;
V_17 = F_53 ( V_16 ) ;
if ( V_17 ) {
F_4 ( & V_46 -> V_54 ) ;
if ( V_87 )
V_87 -> V_5 -> V_56 ( V_87 ) ;
return F_58 ( V_16 , V_17 ) ;
}
if ( V_87 ) {
F_62 ( & V_87 -> V_55 ,
& V_46 -> V_89 ) ;
F_4 ( & V_46 -> V_54 ) ;
V_87 -> V_90 = V_16 -> V_91 ;
return V_5 -> V_92 ( V_87 , V_84 , V_85 ) ;
}
F_4 ( & V_46 -> V_54 ) ;
V_87 = V_5 -> V_93 ( V_16 ) ;
} while ( ! F_7 ( V_87 ) );
F_35 ( L_10 ,
V_16 -> V_34 , F_63 ( V_87 ) ) ;
return V_87 ;
}
void F_64 ( struct V_14 * V_17 , int V_94 )
{
F_65 () ;
V_17 -> V_28 = V_94 ;
F_66 ( & V_79 ) ;
}
void F_67 ( struct V_83 * V_95 , int V_41 ,
unsigned int V_96 , unsigned int V_97 )
{
V_95 -> V_98 = V_96 * V_99 / 10 ;
V_95 -> V_100 = V_97 ;
switch ( V_41 ) {
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
int F_69 ( struct V_14 * V_17 ,
const struct V_83 * V_84 ,
T_1 V_113 )
{
struct V_114 * V_115 = NULL ;
struct V_116 args = {
. V_43 = V_17 -> V_42 ,
. V_117 = V_17 -> V_40 ,
. V_118 = (struct V_57 * ) & V_17 -> V_30 ,
. V_119 = V_17 -> V_33 ,
. V_120 = V_84 ,
. V_121 = V_17 -> V_35 ,
. V_122 = & V_123 ,
. V_2 = V_17 -> V_5 -> V_2 ,
. V_124 = V_113 ,
} ;
if ( F_70 ( V_125 , & V_17 -> V_90 ) )
args . V_126 |= V_127 ;
if ( F_70 ( V_128 , & V_17 -> V_90 ) )
args . V_126 |= V_129 ;
if ( F_70 ( V_130 , & V_17 -> V_90 ) )
args . V_126 |= V_131 ;
if ( F_70 ( V_132 , & V_17 -> V_90 ) )
args . V_126 |= V_133 ;
if ( ! F_7 ( V_17 -> V_38 ) )
return 0 ;
V_115 = F_71 ( & args ) ;
if ( F_7 ( V_115 ) ) {
F_35 ( L_11 ,
V_82 , F_63 ( V_115 ) ) ;
return F_63 ( V_115 ) ;
}
V_17 -> V_38 = V_115 ;
return 0 ;
}
static void F_72 ( struct V_50 * V_51 )
{
if ( V_51 -> V_134 )
F_73 ( V_51 -> V_134 ) ;
}
static int F_74 ( struct V_50 * V_51 )
{
struct V_134 * V_135 ;
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_136 V_137 = {
. V_34 = V_17 -> V_35 ,
. V_118 = (struct V_57 * ) & V_17 -> V_30 ,
. V_32 = V_17 -> V_33 ,
. V_12 = V_17 -> V_5 -> V_2 ,
. V_138 = V_51 -> V_126 & V_139 ?
1 : 0 ,
. V_43 = V_17 -> V_42 ,
} ;
if ( V_137 . V_12 > 3 )
return 0 ;
if ( ( V_51 -> V_126 & V_140 ) &&
( V_51 -> V_126 & V_141 ) )
return 0 ;
switch ( V_17 -> V_40 ) {
default:
V_137 . V_117 = V_142 ;
break;
case V_109 :
V_137 . V_117 = V_143 ;
}
V_135 = F_75 ( & V_137 ) ;
if ( F_7 ( V_135 ) )
return F_63 ( V_135 ) ;
V_51 -> V_134 = V_135 ;
V_51 -> V_144 = F_72 ;
return 0 ;
}
int F_76 ( struct V_50 * V_51 ,
const struct V_83 * V_96 ,
T_1 V_145 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
V_51 -> V_146 = F_77 ( V_17 -> V_38 ,
V_145 ) ;
if ( F_7 ( V_51 -> V_146 ) ) {
F_35 ( L_12 , V_82 ) ;
return F_63 ( V_51 -> V_146 ) ;
}
memcpy ( & V_51 -> V_146 -> V_147 ,
V_96 ,
sizeof( V_51 -> V_146 -> V_147 ) ) ;
V_51 -> V_146 -> V_148 = & V_51 -> V_146 -> V_147 ;
V_51 -> V_146 -> V_149 = 0 ;
if ( V_51 -> V_126 & V_150 )
V_51 -> V_146 -> V_149 = 1 ;
return 0 ;
}
struct V_14 * F_78 ( struct V_14 * V_17 ,
const struct V_83 * V_84 ,
const char * V_85 )
{
int error ;
if ( V_17 -> V_28 == V_81 ) {
F_35 ( L_13 , V_17 ) ;
return V_17 ;
}
error = F_69 ( V_17 , V_84 , V_151 ) ;
if ( error < 0 )
goto error;
F_64 ( V_17 , V_81 ) ;
return V_17 ;
error:
F_64 ( V_17 , error ) ;
F_40 ( V_17 ) ;
F_35 ( L_14 , error ) ;
return F_5 ( error ) ;
}
static int F_79 ( struct V_50 * V_51 ,
const struct V_152 * V_74 ,
struct V_1 * V_25 )
{
struct V_15 V_16 = {
. V_34 = V_74 -> V_50 . V_34 ,
. V_31 = ( const struct V_57 * ) & V_74 -> V_50 . V_118 ,
. V_32 = V_74 -> V_50 . V_32 ,
. V_25 = V_25 ,
. V_41 = V_74 -> V_50 . V_117 ,
. V_43 = V_74 -> V_43 ,
} ;
struct V_83 V_84 ;
struct V_14 * V_17 ;
int error ;
F_35 ( L_15 ) ;
F_67 ( & V_84 , V_74 -> V_50 . V_117 ,
V_74 -> V_96 , V_74 -> V_97 ) ;
if ( V_74 -> V_126 & V_139 )
F_80 ( V_130 , & V_16 . V_91 ) ;
V_17 = F_60 ( & V_16 , & V_84 , NULL , V_151 ) ;
if ( F_7 ( V_17 ) ) {
F_35 ( L_16 , F_63 ( V_17 ) ) ;
return F_63 ( V_17 ) ;
}
V_51 -> V_14 = V_17 ;
V_51 -> V_126 = V_74 -> V_126 ;
V_51 -> V_153 = V_74 -> V_153 ;
V_51 -> V_154 |= V_155 | V_156 | V_157 |
V_158 | V_159 | V_160 | V_161 |
V_162 | V_163 | V_164 | V_165 ;
if ( V_74 -> V_166 )
V_51 -> V_166 = F_81 ( V_74 -> V_166 , NULL ) ;
if ( V_74 -> V_167 )
V_51 -> V_167 = F_81 ( V_74 -> V_167 , NULL ) ;
V_51 -> V_168 = V_74 -> V_168 * V_99 ;
V_51 -> V_169 = V_74 -> V_169 * V_99 ;
V_51 -> V_170 = V_74 -> V_170 * V_99 ;
V_51 -> V_171 = V_74 -> V_171 * V_99 ;
error = F_74 ( V_51 ) ;
if ( error < 0 )
goto error;
V_51 -> V_172 = V_74 -> V_50 . V_172 ;
V_51 -> V_173 = V_74 -> V_173 ;
error = F_76 ( V_51 , & V_84 ,
V_74 -> V_174 ) ;
if ( error < 0 )
goto error;
if ( V_74 -> V_175 . V_32 ) {
memcpy ( & V_51 -> V_176 , & V_74 -> V_175 . V_118 ,
V_74 -> V_175 . V_32 ) ;
V_51 -> V_177 = V_74 -> V_175 . V_32 ;
}
V_51 -> V_178 = V_74 -> V_175 . V_2 ;
V_51 -> V_179 = V_74 -> V_175 . V_172 ;
V_51 -> V_180 = V_74 -> V_175 . V_117 ;
V_51 -> V_181 = V_74 -> V_182 ;
F_35 ( L_17 , V_17 ) ;
return 0 ;
error:
V_51 -> V_14 = NULL ;
F_40 ( V_17 ) ;
F_35 ( L_18 , error ) ;
return error ;
}
static void F_82 ( struct V_50 * V_51 ,
struct V_183 * V_184 ,
struct V_185 * V_186 )
{
unsigned long V_187 ;
if ( V_51 -> V_166 == 0 )
V_51 -> V_166 = F_81 ( V_186 -> V_188 , NULL ) ;
if ( V_51 -> V_167 == 0 )
V_51 -> V_167 = F_81 ( V_186 -> V_189 , NULL ) ;
if ( V_186 -> V_190 >= 512 && V_51 -> V_166 > V_186 -> V_190 )
V_51 -> V_166 = F_81 ( V_186 -> V_190 , NULL ) ;
if ( V_186 -> V_191 >= 512 && V_51 -> V_167 > V_186 -> V_191 )
V_51 -> V_167 = F_81 ( V_186 -> V_191 , NULL ) ;
V_187 = F_81 ( F_83 ( V_51 -> V_146 ) , NULL ) ;
if ( V_51 -> V_166 > V_187 )
V_51 -> V_166 = V_187 ;
if ( V_51 -> V_166 > V_192 )
V_51 -> V_166 = V_192 ;
V_51 -> V_193 = ( V_51 -> V_166 + V_194 - 1 ) >> V_195 ;
V_51 -> V_196 . V_197 = L_19 ;
V_51 -> V_196 . V_198 = V_51 -> V_193 * V_199 ;
if ( V_51 -> V_167 > V_187 )
V_51 -> V_167 = V_187 ;
if ( V_51 -> V_167 > V_192 )
V_51 -> V_167 = V_192 ;
V_51 -> V_200 = ( V_51 -> V_167 + V_194 - 1 ) >> V_195 ;
V_51 -> V_201 = F_84 ( V_186 -> V_201 , NULL ) ;
V_51 -> V_202 = F_81 ( V_186 -> V_203 , NULL ) ;
if ( V_51 -> V_202 > V_194 * V_204 )
V_51 -> V_202 = V_194 * V_204 ;
if ( V_51 -> V_202 > V_51 -> V_166 )
V_51 -> V_202 = V_51 -> V_166 ;
if ( V_51 -> V_126 & V_205 ) {
V_51 -> V_168 = V_51 -> V_169 = 0 ;
V_51 -> V_170 = V_51 -> V_171 = 0 ;
}
V_51 -> V_206 = V_186 -> V_206 ;
V_51 -> V_207 = V_186 -> V_207 ;
F_85 ( V_51 -> V_146 , V_51 -> V_167 + 100 , V_51 -> V_166 + 100 ) ;
}
int F_86 ( struct V_50 * V_51 , struct V_183 * V_184 , struct V_208 * V_209 )
{
struct V_185 V_186 ;
struct V_14 * V_17 = V_51 -> V_14 ;
int error ;
F_35 ( L_20 ) ;
if ( V_17 -> V_5 -> V_210 != NULL ) {
error = V_17 -> V_5 -> V_210 ( V_51 , V_184 ) ;
if ( error < 0 )
goto V_211;
}
V_186 . V_209 = V_209 ;
V_186 . V_212 = 0 ;
error = V_17 -> V_5 -> V_186 ( V_51 , V_184 , & V_186 ) ;
if ( error < 0 )
goto V_211;
F_82 ( V_51 , V_184 , & V_186 ) ;
if ( V_51 -> V_181 == 0 ) {
struct V_213 V_214 ;
V_214 . V_209 = V_209 ;
F_87 ( V_209 ) ;
if ( V_17 -> V_5 -> V_215 ( V_51 , V_184 , & V_214 ) >= 0 )
V_51 -> V_181 = V_214 . V_216 ;
}
F_35 ( L_21 ) ;
return 0 ;
V_211:
F_35 ( L_22 , - error ) ;
return error ;
}
void F_88 ( struct V_50 * V_217 , struct V_50 * V_218 )
{
V_217 -> V_126 = V_218 -> V_126 ;
V_217 -> V_166 = V_218 -> V_166 ;
V_217 -> V_167 = V_218 -> V_167 ;
V_217 -> V_168 = V_218 -> V_168 ;
V_217 -> V_169 = V_218 -> V_169 ;
V_217 -> V_170 = V_218 -> V_170 ;
V_217 -> V_171 = V_218 -> V_171 ;
V_217 -> V_154 = V_218 -> V_154 ;
V_217 -> V_153 = V_218 -> V_153 ;
V_217 -> V_173 = V_218 -> V_173 ;
}
void F_89 ( struct V_50 * V_51 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_45 * V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
F_2 ( & V_46 -> V_54 ) ;
F_90 ( & V_51 -> V_219 , & V_17 -> V_37 ) ;
F_62 ( & V_51 -> V_220 , & V_46 -> V_221 ) ;
F_91 ( V_222 , & V_17 -> V_223 ) ;
F_4 ( & V_46 -> V_54 ) ;
}
void F_92 ( struct V_50 * V_51 )
{
struct V_14 * V_17 = V_51 -> V_14 ;
struct V_45 * V_46 ;
if ( V_17 == NULL )
return;
V_46 = F_28 ( V_17 -> V_42 , V_47 ) ;
F_2 ( & V_46 -> V_54 ) ;
F_93 ( & V_51 -> V_219 ) ;
if ( F_44 ( & V_17 -> V_37 ) )
F_80 ( V_222 , & V_17 -> V_223 ) ;
F_17 ( & V_51 -> V_220 ) ;
F_4 ( & V_46 -> V_54 ) ;
F_94 () ;
}
struct V_50 * F_95 ( void )
{
struct V_50 * V_51 ;
V_51 = F_19 ( sizeof( struct V_50 ) , V_22 ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_146 = V_51 -> V_224 = F_5 ( - V_39 ) ;
F_22 ( & V_51 -> V_219 ) ;
F_22 ( & V_51 -> V_220 ) ;
F_22 ( & V_51 -> V_225 ) ;
F_22 ( & V_51 -> V_226 ) ;
F_22 ( & V_51 -> V_227 ) ;
F_20 ( & V_51 -> V_228 , 0 ) ;
V_51 -> V_229 = F_96 () ;
if ( ! V_51 -> V_229 ) {
F_26 ( V_51 ) ;
return NULL ;
}
if ( F_97 ( & V_51 -> V_196 ) ) {
F_98 ( V_51 -> V_229 ) ;
F_26 ( V_51 ) ;
return NULL ;
}
F_99 ( & V_51 -> V_230 ) ;
F_99 ( & V_51 -> V_231 ) ;
F_32 ( V_51 ) ;
return V_51 ;
}
void F_100 ( struct V_50 * V_51 )
{
F_35 ( L_23 ) ;
F_92 ( V_51 ) ;
if ( V_51 -> V_144 != NULL )
V_51 -> V_144 ( V_51 ) ;
if ( ! F_7 ( V_51 -> V_224 ) )
F_37 ( V_51 -> V_224 ) ;
if ( ! F_7 ( V_51 -> V_146 ) )
F_37 ( V_51 -> V_146 ) ;
F_40 ( V_51 -> V_14 ) ;
F_101 ( & V_51 -> V_231 ) ;
F_101 ( & V_51 -> V_230 ) ;
F_98 ( V_51 -> V_229 ) ;
F_102 ( & V_51 -> V_196 ) ;
F_26 ( V_51 ) ;
F_103 () ;
F_35 ( L_24 ) ;
}
struct V_50 * F_104 ( struct V_232 * V_233 ,
struct V_1 * V_25 )
{
struct V_50 * V_51 ;
struct V_208 * V_209 ;
int error ;
V_51 = F_95 () ;
if ( ! V_51 )
return F_5 ( - V_21 ) ;
error = - V_21 ;
V_209 = F_105 () ;
if ( V_209 == NULL )
goto error;
error = F_79 ( V_51 , V_233 -> V_234 , V_25 ) ;
if ( error < 0 )
goto error;
error = F_86 ( V_51 , V_233 -> V_184 , V_209 ) ;
if ( error < 0 )
goto error;
if ( V_51 -> V_14 -> V_5 -> V_2 == 3 ) {
if ( V_51 -> V_181 == 0 || V_51 -> V_181 > V_235 )
V_51 -> V_181 = V_235 ;
if ( ! ( V_233 -> V_234 -> V_126 & V_236 ) )
V_51 -> V_154 |= V_237 ;
} else {
if ( V_51 -> V_181 == 0 || V_51 -> V_181 > V_238 )
V_51 -> V_181 = V_238 ;
}
if ( ! ( V_209 -> V_239 & V_240 ) ) {
error = V_25 -> V_5 -> V_241 ( V_51 , V_233 -> V_184 , V_209 , NULL ) ;
if ( error < 0 ) {
F_35 ( L_25 , - error ) ;
goto error;
}
}
memcpy ( & V_51 -> V_242 , & V_209 -> V_242 , sizeof( V_51 -> V_242 ) ) ;
F_35 ( L_26 ,
( unsigned long long ) V_51 -> V_242 . V_243 ,
( unsigned long long ) V_51 -> V_242 . V_244 ) ;
F_89 ( V_51 ) ;
V_51 -> V_245 = V_246 ;
F_106 ( V_209 ) ;
return V_51 ;
error:
F_106 ( V_209 ) ;
F_100 ( V_51 ) ;
return F_5 ( error ) ;
}
struct V_50 * F_107 ( struct V_50 * V_218 ,
struct V_183 * V_247 ,
struct V_208 * V_209 ,
T_1 V_113 )
{
struct V_50 * V_51 ;
struct V_208 * V_248 ;
int error ;
F_35 ( L_27 ,
( unsigned long long ) V_209 -> V_242 . V_243 ,
( unsigned long long ) V_209 -> V_242 . V_244 ) ;
V_51 = F_95 () ;
if ( ! V_51 )
return F_5 ( - V_21 ) ;
error = - V_21 ;
V_248 = F_105 () ;
if ( V_248 == NULL )
goto V_249;
V_51 -> V_14 = V_218 -> V_14 ;
V_51 -> V_144 = V_218 -> V_144 ;
F_54 ( & V_51 -> V_14 -> V_27 ) ;
F_88 ( V_51 , V_218 ) ;
V_51 -> V_242 = V_209 -> V_242 ;
error = F_76 ( V_51 ,
V_218 -> V_146 -> V_148 ,
V_113 ) ;
if ( error < 0 )
goto V_249;
error = F_86 ( V_51 , V_247 , V_248 ) ;
if ( error < 0 )
goto V_249;
if ( V_51 -> V_181 == 0 || V_51 -> V_181 > V_250 )
V_51 -> V_181 = V_250 ;
F_35 ( L_28 ,
( unsigned long long ) V_51 -> V_242 . V_243 ,
( unsigned long long ) V_51 -> V_242 . V_244 ) ;
error = F_74 ( V_51 ) ;
if ( error < 0 )
goto V_249;
F_89 ( V_51 ) ;
V_51 -> V_245 = V_246 ;
F_106 ( V_248 ) ;
F_35 ( L_29 , V_51 ) ;
return V_51 ;
V_249:
F_106 ( V_248 ) ;
F_100 ( V_51 ) ;
F_35 ( L_30 , error ) ;
return F_5 ( error ) ;
}
void F_108 ( struct V_43 * V_43 )
{
struct V_45 * V_46 = F_28 ( V_43 , V_47 ) ;
F_22 ( & V_46 -> V_89 ) ;
F_22 ( & V_46 -> V_221 ) ;
#if F_109 ( V_251 )
F_110 ( & V_46 -> V_48 ) ;
#endif
F_111 ( & V_46 -> V_54 ) ;
V_46 -> V_252 = V_253 ;
}
static int F_112 ( struct V_254 * V_254 , struct V_255 * V_255 )
{
return F_113 ( V_254 , V_255 , & V_256 ,
sizeof( struct V_257 ) ) ;
}
static void * F_114 ( struct V_258 * V_259 , T_2 * V_260 )
__acquires( &nn->nfs_client_lock
static void * F_115 ( struct V_258 * V_261 , void * V_262 , T_2 * V_263 )
{
struct V_45 * V_46 = F_28 ( F_116 ( V_261 ) , V_47 ) ;
return F_117 ( V_262 , & V_46 -> V_89 , V_263 ) ;
}
static void F_118 ( struct V_258 * V_261 , void * V_262 )
__releases( &nn->nfs_client_lock
static int F_119 ( struct V_258 * V_259 , void * V_262 )
{
struct V_14 * V_17 ;
struct V_45 * V_46 = F_28 ( F_116 ( V_259 ) , V_47 ) ;
if ( V_262 == & V_46 -> V_89 ) {
F_120 ( V_259 , L_31 ) ;
return 0 ;
}
V_17 = F_121 ( V_262 , struct V_14 , V_55 ) ;
if ( V_17 -> V_28 != V_81 )
return 0 ;
F_122 () ;
F_123 ( V_259 , L_32 ,
V_17 -> V_5 -> V_2 ,
F_124 ( V_17 -> V_38 , V_264 ) ,
F_124 ( V_17 -> V_38 , V_265 ) ,
F_41 ( & V_17 -> V_27 ) ,
V_17 -> V_35 ) ;
F_125 () ;
return 0 ;
}
static int F_126 ( struct V_254 * V_254 , struct V_255 * V_255 )
{
return F_113 ( V_254 , V_255 , & V_266 ,
sizeof( struct V_257 ) ) ;
}
static void * F_127 ( struct V_258 * V_259 , T_2 * V_260 )
__acquires( &nn->nfs_client_lock
static void * F_128 ( struct V_258 * V_261 , void * V_262 , T_2 * V_263 )
{
struct V_45 * V_46 = F_28 ( F_116 ( V_261 ) , V_47 ) ;
return F_117 ( V_262 , & V_46 -> V_221 , V_263 ) ;
}
static void F_129 ( struct V_258 * V_261 , void * V_262 )
__releases( &nn->nfs_client_lock
static int F_130 ( struct V_258 * V_259 , void * V_262 )
{
struct V_50 * V_51 ;
struct V_14 * V_17 ;
char V_267 [ 8 ] , V_242 [ 17 ] ;
struct V_45 * V_46 = F_28 ( F_116 ( V_259 ) , V_47 ) ;
if ( V_262 == & V_46 -> V_221 ) {
F_120 ( V_259 , L_33 ) ;
return 0 ;
}
V_51 = F_121 ( V_262 , struct V_50 , V_220 ) ;
V_17 = V_51 -> V_14 ;
snprintf ( V_267 , 8 , L_34 ,
F_131 ( V_51 -> V_268 ) , F_132 ( V_51 -> V_268 ) ) ;
snprintf ( V_242 , 17 , L_35 ,
( unsigned long long ) V_51 -> V_242 . V_243 ,
( unsigned long long ) V_51 -> V_242 . V_244 ) ;
F_122 () ;
F_123 ( V_259 , L_36 ,
V_17 -> V_5 -> V_2 ,
F_124 ( V_17 -> V_38 , V_264 ) ,
F_124 ( V_17 -> V_38 , V_265 ) ,
V_267 ,
V_242 ,
F_133 ( V_51 ) ) ;
F_125 () ;
return 0 ;
}
int F_134 ( struct V_43 * V_43 )
{
struct V_45 * V_46 = F_28 ( V_43 , V_47 ) ;
struct V_269 * V_261 ;
V_46 -> V_270 = F_135 ( V_43 , L_37 , V_43 -> V_271 ) ;
if ( ! V_46 -> V_270 )
goto V_23;
V_261 = F_136 ( L_38 , V_272 | V_273 ,
V_46 -> V_270 , & V_274 ) ;
if ( ! V_261 )
goto V_275;
V_261 = F_136 ( L_39 , V_272 | V_273 ,
V_46 -> V_270 , & V_276 ) ;
if ( ! V_261 )
goto V_275;
return 0 ;
V_275:
F_137 ( L_37 , V_43 -> V_271 ) ;
V_23:
return - V_21 ;
}
void F_138 ( struct V_43 * V_43 )
{
F_137 ( L_37 , V_43 -> V_271 ) ;
}
int T_3 F_139 ( void )
{
struct V_269 * V_261 ;
V_277 = F_140 ( L_40 , NULL ) ;
if ( ! V_277 )
goto V_23;
V_261 = F_141 ( L_38 , V_277 , L_41 ) ;
if ( ! V_261 )
goto V_275;
V_261 = F_141 ( L_39 , V_277 , L_42 ) ;
if ( ! V_261 )
goto V_278;
return 0 ;
V_278:
F_142 ( L_38 , V_277 ) ;
V_275:
F_142 ( L_40 , NULL ) ;
V_23:
return - V_21 ;
}
void F_143 ( void )
{
F_142 ( L_39 , V_277 ) ;
F_142 ( L_38 , V_277 ) ;
F_142 ( L_40 , NULL ) ;
}
