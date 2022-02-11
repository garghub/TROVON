static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( V_2 -> V_9 -> V_10 != 4 || V_3 != 0 )
return V_4 ;
F_3 ( V_11 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_4 = F_5 ( & V_6 -> V_13 , V_2 , 1 , 0 , V_14 ) ;
if ( V_4 >= 0 )
V_2 -> V_15 = V_4 ;
F_6 ( & V_6 -> V_12 ) ;
F_7 () ;
return V_4 < 0 ? V_4 : 0 ;
}
static struct V_16 *
F_8 ( struct V_1 * V_17 , T_1 V_18 )
{
struct V_16 * V_19 ;
F_9 () ;
F_10 (dss, &ds_clp->cl_ds_clients, list) {
if ( V_19 -> V_20 -> V_21 -> V_22 != V_18 )
continue;
goto V_23;
}
V_19 = NULL ;
V_23:
F_11 () ;
return V_19 ;
}
static struct V_16 *
F_12 ( struct V_1 * V_17 , T_1 V_18 ,
struct V_16 * V_24 )
{
struct V_16 * V_19 ;
F_4 ( & V_17 -> V_25 ) ;
F_13 (dss, &ds_clp->cl_ds_clients, list) {
if ( V_19 -> V_20 -> V_21 -> V_22 != V_18 )
continue;
goto V_23;
}
if ( V_24 )
F_14 ( & V_24 -> V_26 , & V_17 -> V_27 ) ;
V_19 = V_24 ;
V_23:
F_6 ( & V_17 -> V_25 ) ;
return V_19 ;
}
static struct V_16 *
F_15 ( struct V_1 * V_17 , T_1 V_18 )
{
struct V_16 * V_19 ;
V_19 = F_16 ( sizeof( * V_19 ) , V_28 ) ;
if ( V_19 == NULL )
return F_17 ( - V_29 ) ;
V_19 -> V_20 = F_18 ( V_17 -> V_30 , V_18 ) ;
if ( F_19 ( V_19 -> V_20 ) ) {
int V_31 = F_20 ( V_19 -> V_20 ) ;
F_21 ( V_19 ) ;
return F_17 ( V_31 ) ;
}
F_22 ( & V_19 -> V_26 ) ;
return V_19 ;
}
static void
F_23 ( struct V_16 * V_19 )
{
F_24 ( V_19 -> V_20 ) ;
F_21 ( V_19 ) ;
}
struct V_20 *
F_25 ( struct V_1 * V_17 , struct V_32 * V_32 )
{
struct V_16 * V_19 , * V_24 ;
T_1 V_18 = F_26 ( V_32 ) -> V_33 -> V_21 -> V_22 ;
V_19 = F_8 ( V_17 , V_18 ) ;
if ( V_19 != NULL )
goto V_23;
V_24 = F_15 ( V_17 , V_18 ) ;
if ( F_19 ( V_24 ) )
return F_27 ( V_24 ) ;
V_19 = F_12 ( V_17 , V_18 , V_24 ) ;
if ( V_19 != V_24 )
F_23 ( V_24 ) ;
V_23:
return V_19 -> V_20 ;
}
static void
F_28 ( struct V_1 * V_2 )
{
struct V_16 * V_19 ;
F_29 ( V_34 ) ;
while ( ! F_30 ( & V_2 -> V_27 ) ) {
V_19 = F_31 ( V_2 -> V_27 . V_35 ,
struct V_16 , V_26 ) ;
F_32 ( & V_19 -> V_26 ) ;
F_33 ( V_19 -> V_20 ) ;
F_21 ( V_19 ) ;
}
}
void F_34 ( struct V_1 * V_2 )
{
if ( F_35 ( V_2 ) ) {
F_28 ( V_2 ) ;
F_36 ( V_2 -> V_36 ) ;
F_37 ( V_2 ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 ) {
F_39 ( V_2 -> V_37 ) ;
F_21 ( V_2 -> V_37 ) ;
}
}
struct V_1 * F_40 ( const struct V_38 * V_39 )
{
int V_31 ;
struct V_1 * V_2 = F_41 ( V_39 ) ;
if ( F_19 ( V_2 ) )
return V_2 ;
V_31 = F_1 ( V_2 , V_39 -> V_3 ) ;
if ( V_31 )
goto error;
if ( V_39 -> V_3 > V_40 ) {
V_31 = - V_41 ;
goto error;
}
F_42 ( & V_2 -> V_25 ) ;
F_43 ( & V_2 -> V_42 , V_43 ) ;
F_22 ( & V_2 -> V_27 ) ;
F_44 ( & V_2 -> V_44 , L_1 ) ;
V_2 -> V_45 = 1 << V_46 ;
V_2 -> V_47 = V_39 -> V_3 ;
V_2 -> V_48 = V_49 [ V_39 -> V_3 ] ;
V_2 -> V_50 = 1 ;
#if F_45 ( V_51 )
F_46 ( & V_2 -> V_52 ) ;
#endif
return V_2 ;
error:
F_47 ( V_2 ) ;
return F_17 ( V_31 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( F_49 ( V_53 , & V_2 -> V_54 ) )
F_50 ( V_2 -> V_48 -> V_55 , V_2 -> V_7 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( F_49 ( V_56 , & V_2 -> V_54 ) )
F_52 ( V_2 ) ;
V_2 -> V_48 -> V_57 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( F_49 ( V_58 , & V_2 -> V_54 ) )
F_53 ( V_2 ) ;
F_54 ( & V_2 -> V_44 ) ;
F_21 ( V_2 -> V_59 ) ;
F_21 ( V_2 -> V_60 ) ;
F_21 ( V_2 -> V_61 ) ;
F_21 ( V_2 -> V_62 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_51 ( V_2 ) ;
F_47 ( V_2 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_63 * V_64 ;
int error ;
V_64 = F_57 ( V_2 -> V_30 -> V_65 ) ;
if ( F_35 ( V_2 ) ) {
error = F_58 ( V_64 , V_66 ) ;
if ( error < 0 )
return error ;
}
error = F_59 ( V_2 -> V_48 -> V_55 , V_64 ) ;
if ( error < 0 ) {
F_60 ( L_2 ,
V_67 , error ) ;
return error ;
}
F_61 ( V_53 , & V_2 -> V_54 ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
int V_4 ;
V_69 = F_63 ( sizeof( * V_69 ) , V_28 ) ;
if ( V_69 == NULL )
return - V_29 ;
V_4 = F_64 ( V_69 , V_70 ,
L_3 ) ;
if ( V_4 ) {
F_21 ( V_69 ) ;
return V_4 ;
}
V_2 -> V_37 = V_69 ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = NULL ;
V_72 = F_66 ( V_2 ) ;
if ( ! V_72 )
return - V_29 ;
V_2 -> V_36 = V_72 ;
F_67 ( V_2 , V_73 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = V_2 -> V_48 -> V_74 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return F_56 ( V_2 ) ;
}
struct V_1 * F_69 ( struct V_1 * V_2 ,
const struct V_38 * V_39 )
{
char V_75 [ V_76 + 1 ] ;
const char * V_77 = V_39 -> V_77 ;
struct V_1 * V_78 ;
int error ;
if ( V_2 -> V_79 == V_80 )
return V_2 ;
V_2 -> V_9 = & V_81 ;
if ( V_2 -> V_47 != 0 )
F_61 ( V_82 , & V_2 -> V_83 ) ;
F_61 ( V_84 , & V_2 -> V_83 ) ;
F_61 ( V_85 , & V_2 -> V_83 ) ;
error = F_70 ( V_2 , V_39 , V_86 ) ;
if ( error == - V_41 )
error = F_70 ( V_2 , V_39 , V_87 ) ;
if ( error < 0 )
goto error;
if ( V_77 == NULL ) {
struct V_88 V_89 ;
struct V_90 * V_91 = (struct V_90 * ) & V_89 ;
error = F_71 ( V_2 -> V_30 , V_91 , sizeof( V_89 ) ) ;
if ( error < 0 )
goto error;
error = F_72 ( V_91 , V_75 , sizeof( V_75 ) ) ;
if ( error < 0 )
goto error;
V_77 = ( const char * ) V_75 ;
}
F_73 ( V_2 -> V_92 , V_77 , sizeof( V_2 -> V_92 ) ) ;
error = F_74 ( V_2 ) ;
if ( error < 0 ) {
F_60 ( L_4 ,
V_67 , error ) ;
goto error;
}
F_61 ( V_58 , & V_2 -> V_54 ) ;
error = F_68 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_35 ( V_2 ) )
F_67 ( V_2 , V_80 ) ;
error = F_75 ( V_2 , & V_78 ) ;
if ( error < 0 )
goto error;
if ( V_2 != V_78 )
V_2 -> V_93 = true ;
F_76 ( V_2 ) ;
return V_78 ;
error:
F_67 ( V_2 , error ) ;
F_76 ( V_2 ) ;
return F_17 ( error ) ;
}
static void F_77 ( struct V_1 * V_94 ,
struct V_1 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_94 -> V_7 , V_8 ) ;
unsigned int V_96 = V_94 -> V_15 ;
if ( V_94 -> V_15 == V_95 -> V_15 )
return;
F_60 ( L_5 ,
V_67 , V_94 -> V_15 , V_95 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_78 ( & V_6 -> V_13 , V_94 , V_95 -> V_15 ) ;
V_94 -> V_15 = V_95 -> V_15 ;
F_78 ( & V_6 -> V_13 , V_95 , V_96 ) ;
V_95 -> V_15 = V_96 ;
F_6 ( & V_6 -> V_12 ) ;
}
static bool F_79 ( const struct V_1 * V_97 ,
const struct V_1 * V_98 )
{
if ( V_97 -> V_62 == NULL || V_98 -> V_62 == NULL )
return true ;
return strcmp ( V_97 -> V_62 , V_98 -> V_62 ) == 0 ;
}
static bool F_80 ( T_2 * V_99 , T_2 * V_100 )
{
return memcmp ( V_99 -> V_101 , V_100 -> V_101 , sizeof( V_99 -> V_101 ) ) == 0 ;
}
static int F_81 ( struct V_1 * V_102 , struct V_1 * V_24 ,
struct V_1 * * V_103 , struct V_5 * V_6 )
{
int V_104 ;
if ( V_102 -> V_9 != V_24 -> V_9 )
return 1 ;
if ( V_102 -> V_47 != V_24 -> V_47 )
return 1 ;
if ( V_102 -> V_79 > V_80 ) {
F_82 ( & V_102 -> V_105 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( * V_103 ) ;
* V_103 = V_102 ;
V_104 = F_83 ( V_102 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_104 < 0 )
return V_104 ;
}
if ( V_102 -> V_79 != V_80 )
return 1 ;
if ( V_102 -> V_106 != V_24 -> V_106 )
return 1 ;
if ( ! F_79 ( V_102 , V_24 ) )
return 1 ;
return 0 ;
}
int F_84 ( struct V_1 * V_24 ,
struct V_1 * * V_107 ,
struct V_108 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_102 , * V_103 = NULL ;
struct V_110 V_111 = {
. V_112 = V_24 -> V_106 ,
. V_113 = V_24 -> V_114 ,
} ;
int V_104 = - V_115 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
V_104 = F_81 ( V_102 , V_24 , & V_103 , V_6 ) ;
if ( V_104 < 0 )
goto V_116;
if ( V_104 != 0 )
continue;
if ( ( V_24 != V_102 ) && F_80 ( & V_102 -> V_114 ,
& V_24 -> V_114 ) )
continue;
F_82 ( & V_102 -> V_105 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_103 ) ;
V_103 = V_102 ;
V_104 = F_85 ( V_102 , & V_111 , V_109 ) ;
switch ( V_104 ) {
case - V_115 :
break;
case 0 :
F_77 ( V_102 , V_24 ) ;
V_102 -> V_114 = V_24 -> V_114 ;
V_103 = NULL ;
* V_107 = V_102 ;
goto V_23;
case - V_117 :
case - V_118 :
F_86 ( V_102 ) ;
default:
goto V_23;
}
F_4 ( & V_6 -> V_12 ) ;
}
V_116:
F_6 ( & V_6 -> V_12 ) ;
V_23:
F_76 ( V_103 ) ;
return V_104 ;
}
static bool
F_87 ( struct V_119 * V_120 ,
struct V_119 * V_121 )
{
if ( V_120 -> V_122 != V_121 -> V_122 )
return false ;
return memcmp ( V_120 -> V_123 , V_121 -> V_123 , V_120 -> V_122 ) == 0 ;
}
static bool
F_88 ( struct V_124 * V_125 ,
struct V_124 * V_126 )
{
if ( V_125 -> V_127 != V_126 -> V_127 )
return false ;
return memcmp ( V_125 -> V_128 , V_126 -> V_128 ,
V_125 -> V_127 ) == 0 ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_129 * V_130 ,
struct V_63 * V_64 )
{
if ( V_2 -> V_106 != V_130 -> V_112 )
goto V_131;
if ( ! F_87 ( V_2 -> V_59 ,
V_130 -> V_132 ) )
goto V_131;
if ( V_2 -> V_59 -> V_133 != V_130 -> V_132 -> V_133 )
goto V_131;
if ( ! F_88 ( V_2 -> V_60 , V_130 -> V_128 ) )
goto V_131;
F_90 ( V_2 -> V_30 , V_64 ) ;
F_91 ( L_6 ,
V_2 -> V_134 ,
V_64 -> V_135 [ V_136 ] ) ;
return 0 ;
V_131:
F_91 ( L_7 , V_2 -> V_134 ,
V_64 -> V_135 [ V_136 ] ) ;
return - V_41 ;
}
int F_92 ( struct V_1 * V_24 ,
struct V_1 * * V_107 ,
struct V_108 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_102 , * V_103 = NULL ;
int V_104 = - V_115 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_102 == V_24 )
goto V_137;
V_104 = F_81 ( V_102 , V_24 , & V_103 , V_6 ) ;
if ( V_104 < 0 )
goto V_23;
if ( V_104 != 0 )
continue;
if ( ! F_87 ( V_102 -> V_59 ,
V_24 -> V_59 ) )
continue;
V_137:
F_82 ( & V_102 -> V_105 ) ;
* V_107 = V_102 ;
V_104 = 0 ;
break;
}
V_23:
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_103 ) ;
return V_104 ;
}
static void F_93 ( struct V_138 * V_139 )
{
F_94 ( V_139 ) ;
F_95 ( V_139 ) ;
F_96 ( V_139 ) ;
}
struct V_1 *
F_97 ( struct V_140 * V_140 , int V_141 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_140 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_98 ( & V_6 -> V_13 , V_141 ) ;
if ( V_2 )
F_82 ( & V_2 -> V_105 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_99 ( const struct V_90 * V_142 ,
struct V_1 * V_2 , T_3 V_3 )
{
struct V_90 * V_143 = (struct V_90 * ) & V_2 -> V_144 ;
if ( ! ( V_2 -> V_79 == V_80 ||
V_2 -> V_79 == V_73 ) )
return false ;
F_100 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
return F_101 ( V_142 , V_143 ) ;
}
struct V_1 *
F_102 ( struct V_140 * V_140 , const struct V_90 * V_142 ,
struct V_145 * V_146 , T_3 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_140 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_99 ( V_142 , V_2 , V_3 ) == false )
continue;
if ( ! F_35 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_36 -> V_147 . V_101 ,
V_146 -> V_101 , V_148 ) != 0 )
continue;
F_82 ( & V_2 -> V_105 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_102 ( struct V_140 * V_140 , const struct V_90 * V_142 ,
struct V_145 * V_146 , T_3 V_3 )
{
return NULL ;
}
static int F_103 ( struct V_138 * V_139 ,
const char * V_149 ,
const struct V_90 * V_142 ,
const T_4 V_150 ,
const char * V_77 ,
int V_151 , const struct V_152 * V_153 ,
T_3 V_3 , struct V_140 * V_140 )
{
struct V_38 V_39 = {
. V_149 = V_149 ,
. V_142 = V_142 ,
. V_150 = V_150 ,
. V_77 = V_77 ,
. V_154 = & V_155 ,
. V_151 = V_151 ,
. V_3 = V_3 ,
. V_140 = V_140 ,
. V_153 = V_153 ,
} ;
struct V_1 * V_2 ;
if ( V_139 -> V_156 & V_157 )
F_104 ( V_158 , & V_39 . V_159 ) ;
if ( V_139 -> V_160 & V_161 )
F_104 ( V_162 , & V_39 . V_159 ) ;
V_2 = F_105 ( & V_39 ) ;
if ( F_19 ( V_2 ) )
return F_20 ( V_2 ) ;
if ( V_139 -> V_1 == V_2 )
return - V_163 ;
F_104 ( V_164 , & V_2 -> V_54 ) ;
V_139 -> V_1 = V_2 ;
return 0 ;
}
struct V_1 * F_106 ( struct V_138 * V_165 ,
const struct V_90 * V_166 , int V_167 ,
int V_168 , unsigned int V_169 , unsigned int V_170 ,
T_3 V_55 )
{
struct V_152 V_171 ;
struct V_1 * V_172 = V_165 -> V_1 ;
struct V_38 V_39 = {
. V_142 = V_166 ,
. V_150 = V_167 ,
. V_173 = V_172 -> V_30 -> V_174 ,
. V_77 = V_172 -> V_92 ,
. V_154 = & V_155 ,
. V_151 = V_168 ,
. V_3 = V_55 ,
. V_140 = V_172 -> V_7 ,
. V_153 = & V_171 ,
} ;
char V_75 [ V_76 + 1 ] ;
if ( F_72 ( V_166 , V_75 , sizeof( V_75 ) ) <= 0 )
return F_17 ( - V_41 ) ;
V_39 . V_149 = V_75 ;
if ( V_165 -> V_156 & V_157 )
F_61 ( V_158 , & V_39 . V_159 ) ;
F_107 ( & V_171 , V_168 , V_169 , V_170 ) ;
return F_105 ( & V_39 ) ;
}
static void F_108 ( struct V_138 * V_139 )
{
#ifdef V_51
struct V_71 * V_175 ;
T_3 V_176 ;
T_3 V_177 ;
if ( ! F_35 ( V_139 -> V_1 ) )
return;
V_175 = V_139 -> V_1 -> V_36 ;
V_176 = V_175 -> V_178 . V_179 - V_180 ;
V_177 = V_175 -> V_178 . V_181 - V_182 ;
if ( ! V_139 -> V_183 || V_139 -> V_183 > V_176 )
V_139 -> V_183 = V_176 ;
if ( ! V_139 -> V_184 || V_139 -> V_184 > V_177 )
V_139 -> V_184 = V_177 ;
#endif
}
static int F_109 ( struct V_138 * V_139 ,
struct V_185 * V_186 , bool V_187 )
{
struct V_188 * V_189 ;
int error ;
if ( F_110 ( V_139 -> V_1 ) )
return - V_190 ;
V_189 = F_111 () ;
if ( V_189 == NULL )
return - V_29 ;
error = F_112 ( V_139 -> V_1 ) ;
if ( error < 0 )
goto V_23;
V_139 -> V_191 |= V_139 -> V_1 -> V_48 -> V_192 ;
if ( V_139 -> V_156 & V_193 )
V_139 -> V_191 &= ~ V_194 ;
if ( V_195 &&
V_139 -> V_33 -> V_21 -> V_22 == V_87 )
V_139 -> V_191 |= V_196 ;
error = F_113 ( V_139 , V_186 , V_187 ) ;
if ( error < 0 )
goto V_23;
F_60 ( L_8 ,
( unsigned long long ) V_139 -> V_197 . V_198 ,
( unsigned long long ) V_139 -> V_197 . V_199 ) ;
F_114 ( V_186 , L_9 ) ;
F_108 ( V_139 ) ;
error = F_115 ( V_139 , V_186 , V_189 ) ;
if ( error < 0 )
goto V_23;
if ( V_139 -> V_200 == 0 || V_139 -> V_200 > V_201 )
V_139 -> V_200 = V_201 ;
F_116 ( V_139 ) ;
V_139 -> V_202 = V_203 ;
V_139 -> V_204 = F_93 ;
V_23:
F_117 ( V_189 ) ;
return error ;
}
static int F_118 ( struct V_138 * V_139 ,
struct V_205 * V_101 )
{
struct V_152 V_153 ;
int error ;
F_107 ( & V_153 , V_101 -> V_138 . V_206 ,
V_101 -> V_207 , V_101 -> V_208 ) ;
V_139 -> V_156 = V_101 -> V_156 ;
V_139 -> V_160 = V_101 -> V_160 ;
V_139 -> V_209 = V_101 -> V_209 ;
if ( V_101 -> V_209 . V_210 >= 1 )
V_101 -> V_211 = V_101 -> V_209 . V_212 [ 0 ] ;
else
V_101 -> V_211 = V_87 ;
error = F_103 ( V_139 ,
V_101 -> V_138 . V_149 ,
( const struct V_90 * ) & V_101 -> V_138 . V_213 ,
V_101 -> V_138 . V_150 ,
V_101 -> V_214 ,
V_101 -> V_138 . V_206 ,
& V_153 ,
V_101 -> V_3 ,
V_101 -> V_140 ) ;
if ( error < 0 )
return error ;
if ( V_101 -> V_183 )
V_139 -> V_183 = F_119 ( V_101 -> V_183 , NULL ) ;
if ( V_101 -> V_184 )
V_139 -> V_184 = F_119 ( V_101 -> V_184 , NULL ) ;
V_139 -> V_215 = V_101 -> V_215 * V_216 ;
V_139 -> V_217 = V_101 -> V_217 * V_216 ;
V_139 -> V_218 = V_101 -> V_218 * V_216 ;
V_139 -> V_219 = V_101 -> V_219 * V_216 ;
V_139 -> V_220 = V_101 -> V_138 . V_220 ;
return F_120 ( V_139 , & V_153 ,
V_101 -> V_211 ) ;
}
struct V_138 * F_121 ( struct V_221 * V_222 ,
struct V_223 * V_154 )
{
struct V_138 * V_139 ;
bool V_187 ;
int error ;
V_139 = F_122 () ;
if ( ! V_139 )
return F_17 ( - V_29 ) ;
V_187 = V_222 -> V_224 -> V_209 . V_210 < 1 ;
error = F_118 ( V_139 , V_222 -> V_224 ) ;
if ( error < 0 )
goto error;
error = F_109 ( V_139 , V_222 -> V_186 , V_187 ) ;
if ( error < 0 )
goto error;
return V_139 ;
error:
F_123 ( V_139 ) ;
return F_17 ( error ) ;
}
struct V_138 * F_124 ( struct V_225 * V_101 ,
struct V_185 * V_186 )
{
struct V_1 * V_226 ;
struct V_138 * V_139 , * V_227 ;
bool V_187 ;
int error ;
V_139 = F_122 () ;
if ( ! V_139 )
return F_17 ( - V_29 ) ;
V_227 = F_125 ( V_101 -> V_228 ) ;
V_226 = V_227 -> V_1 ;
F_126 ( V_139 , V_227 ) ;
error = F_103 ( V_139 , V_101 -> V_149 ,
V_101 -> V_142 ,
V_101 -> V_150 ,
V_226 -> V_92 ,
F_127 ( V_227 -> V_33 ) ,
V_227 -> V_33 -> V_229 ,
V_226 -> V_48 -> V_55 ,
V_226 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_120 ( V_139 , V_227 -> V_33 -> V_229 , V_101 -> V_230 ) ;
if ( error < 0 )
goto error;
V_187 = V_227 -> V_209 . V_210 < 1 ;
error = F_109 ( V_139 , V_186 , V_187 ) ;
if ( error < 0 )
goto error;
return V_139 ;
error:
F_123 ( V_139 ) ;
return F_17 ( error ) ;
}
static int F_128 ( struct V_138 * V_139 )
{
struct V_32 * V_32 = F_129 ( V_139 -> V_231 -> V_232 ) ;
struct V_188 * V_189 ;
int error ;
V_189 = F_111 () ;
if ( V_189 == NULL )
return - V_29 ;
error = F_115 ( V_139 , F_130 ( V_32 ) , V_189 ) ;
F_117 ( V_189 ) ;
return error ;
}
int F_131 ( struct V_138 * V_139 , const char * V_149 ,
struct V_90 * V_91 , T_4 V_233 , struct V_140 * V_140 )
{
struct V_1 * V_2 = V_139 -> V_1 ;
struct V_20 * V_234 = V_139 -> V_33 ;
struct V_235 V_236 = {
. V_237 = V_2 -> V_238 ,
. V_140 = V_140 ,
. V_239 = V_91 ,
. V_150 = V_233 ,
. V_240 = V_149 ,
} ;
char V_75 [ V_76 + 1 ] ;
struct V_88 V_213 ;
struct V_90 * V_241 = (struct V_90 * ) & V_213 ;
int error ;
error = F_132 ( V_234 , & V_236 , V_234 -> V_229 ) ;
if ( error != 0 )
return error ;
error = F_71 ( V_234 , V_241 , sizeof( V_213 ) ) ;
if ( error != 0 )
return error ;
if ( F_72 ( V_241 , V_75 , sizeof( V_75 ) ) == 0 )
return - V_242 ;
F_133 ( V_139 ) ;
error = F_103 ( V_139 , V_149 , V_91 , V_233 , V_75 ,
V_2 -> V_238 , V_234 -> V_229 ,
V_2 -> V_47 , V_140 ) ;
F_76 ( V_2 ) ;
if ( error != 0 ) {
F_116 ( V_139 ) ;
return error ;
}
if ( V_139 -> V_1 -> V_134 == NULL )
V_139 -> V_1 -> V_134 = F_134 ( V_149 , V_11 ) ;
F_116 ( V_139 ) ;
return F_128 ( V_139 ) ;
}
