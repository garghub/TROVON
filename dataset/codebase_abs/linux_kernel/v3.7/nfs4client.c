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
static void F_7 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 ) ) {
F_9 ( V_2 -> V_18 ) ;
F_10 ( V_2 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
}
struct V_1 * F_11 ( const struct V_19 * V_20 )
{
int V_21 ;
struct V_1 * V_2 = F_12 ( V_20 ) ;
if ( F_13 ( V_2 ) )
return V_2 ;
V_21 = F_1 ( V_2 , V_20 -> V_3 ) ;
if ( V_21 )
goto error;
F_14 ( & V_2 -> V_22 ) ;
F_15 ( & V_2 -> V_23 , V_24 ) ;
F_16 ( & V_2 -> V_25 , L_1 ) ;
V_2 -> V_26 = 1 << V_27 ;
V_2 -> V_28 = V_20 -> V_3 ;
V_2 -> V_29 = V_30 [ V_20 -> V_3 ] ;
return V_2 ;
error:
F_17 ( V_2 ) ;
return F_18 ( V_21 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( F_20 ( V_31 , & V_2 -> V_32 ) )
F_21 ( V_2 -> V_29 -> V_33 , V_2 -> V_7 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( F_20 ( V_34 , & V_2 -> V_32 ) )
F_23 ( V_2 ) ;
F_7 ( V_2 ) ;
F_19 ( V_2 ) ;
if ( F_20 ( V_35 , & V_2 -> V_32 ) )
F_24 ( V_2 ) ;
F_25 ( & V_2 -> V_25 ) ;
F_26 ( V_2 -> V_36 ) ;
F_26 ( V_2 -> V_37 ) ;
F_26 ( V_2 -> V_38 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_9 -> V_10 == 4 ) {
struct V_39 * V_40 ;
V_40 = F_29 ( V_2 -> V_41 -> V_42 ) ;
if ( F_8 ( V_2 ) ) {
error = F_30 ( V_40 ,
V_43 ) ;
if ( error < 0 )
return error ;
}
error = F_31 ( V_2 -> V_29 -> V_33 , V_40 ) ;
if ( error < 0 ) {
F_32 ( L_2 ,
V_44 , error ) ;
return error ;
}
F_33 ( V_31 , & V_2 -> V_32 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
#if F_35 ( V_45 )
if ( V_2 -> V_29 -> V_33 ) {
struct V_46 * V_47 = NULL ;
V_47 = F_36 ( V_2 ) ;
if ( ! V_47 )
return - V_14 ;
V_2 -> V_18 = V_47 ;
F_37 ( V_2 , V_48 ) ;
}
#endif
return F_28 ( V_2 ) ;
}
struct V_1 * F_38 ( struct V_1 * V_2 ,
const struct V_49 * V_50 ,
const char * V_51 ,
T_1 V_52 )
{
char V_53 [ V_54 + 1 ] ;
struct V_1 * V_55 ;
int error ;
if ( V_2 -> V_56 == V_57 ) {
F_32 ( L_3 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_58 ;
F_33 ( V_59 , & V_2 -> V_60 ) ;
error = F_39 ( V_2 , V_50 , V_52 ) ;
if ( error < 0 )
goto error;
if ( V_51 == NULL ) {
struct V_61 V_62 ;
struct V_63 * V_64 = (struct V_63 * ) & V_62 ;
error = F_40 ( V_2 -> V_41 , V_64 , sizeof( V_62 ) ) ;
if ( error < 0 )
goto error;
error = F_41 ( V_64 , V_53 , sizeof( V_53 ) ) ;
if ( error < 0 )
goto error;
V_51 = ( const char * ) V_53 ;
}
F_42 ( V_2 -> V_65 , V_51 , sizeof( V_2 -> V_65 ) ) ;
error = F_43 ( V_2 ) ;
if ( error < 0 ) {
F_32 ( L_4 ,
V_44 , error ) ;
goto error;
}
F_33 ( V_35 , & V_2 -> V_32 ) ;
error = F_34 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_8 ( V_2 ) )
F_37 ( V_2 , V_57 ) ;
error = F_44 ( V_2 , & V_55 ) ;
if ( error < 0 )
goto error;
if ( V_2 != V_55 ) {
V_2 -> V_66 = true ;
F_45 ( V_2 ) ;
V_2 = V_55 ;
F_46 ( & V_2 -> V_67 ) ;
}
return V_2 ;
error:
F_37 ( V_2 , error ) ;
F_45 ( V_2 ) ;
F_32 ( L_5 , error ) ;
return F_18 ( error ) ;
}
static void F_47 ( struct V_1 * V_68 ,
struct V_1 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_68 -> V_7 , V_8 ) ;
unsigned int V_70 = V_68 -> V_16 ;
if ( V_68 -> V_16 == V_69 -> V_16 )
return;
F_32 ( L_6 ,
V_44 , V_68 -> V_16 , V_69 -> V_16 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_48 ( & V_6 -> V_12 , V_68 , V_69 -> V_16 ) ;
V_68 -> V_16 = V_69 -> V_16 ;
F_48 ( & V_6 -> V_12 , V_69 , V_70 ) ;
V_69 -> V_16 = V_70 ;
F_6 ( & V_6 -> V_15 ) ;
}
int F_49 ( struct V_1 * V_71 ,
struct V_1 * * V_72 ,
struct V_73 * V_74 )
{
struct V_5 * V_6 = F_2 ( V_71 -> V_7 , V_8 ) ;
struct V_1 * V_75 , * V_76 , * V_77 = NULL ;
struct V_78 V_79 = {
. V_80 = V_71 -> V_81 ,
. V_82 = V_71 -> V_83 ,
} ;
int V_84 ;
F_4 ( & V_6 -> V_15 ) ;
F_50 (pos, n, &nn->nfs_client_list, cl_share_link) {
if ( V_75 -> V_56 < V_57 )
continue;
if ( V_75 -> V_9 != V_71 -> V_9 )
continue;
if ( V_75 -> V_85 != V_71 -> V_85 )
continue;
if ( V_75 -> V_28 != V_71 -> V_28 )
continue;
if ( V_75 -> V_81 != V_71 -> V_81 )
continue;
F_46 ( & V_75 -> V_67 ) ;
F_6 ( & V_6 -> V_15 ) ;
if ( V_77 )
F_45 ( V_77 ) ;
V_84 = F_51 ( V_75 , & V_79 , V_74 ) ;
if ( V_84 == 0 ) {
F_47 ( V_75 , V_71 ) ;
F_45 ( V_75 ) ;
* V_72 = V_75 ;
F_32 ( L_7 ,
V_44 , V_75 , F_52 ( & V_75 -> V_67 ) ) ;
return 0 ;
}
if ( V_84 != - V_86 ) {
F_45 ( V_75 ) ;
F_32 ( L_8 ,
V_44 , V_84 ) ;
return V_84 ;
}
F_4 ( & V_6 -> V_15 ) ;
V_77 = V_75 ;
}
if ( V_77 )
F_45 ( V_77 ) ;
F_6 ( & V_6 -> V_15 ) ;
F_53 ( L_9 , V_44 ) ;
return - V_86 ;
}
static bool F_54 ( struct V_1 * V_87 , struct V_1 * V_88 )
{
if ( V_87 -> V_81 != V_88 -> V_81 ) {
F_32 ( L_10 ,
V_44 , V_87 -> V_81 , V_88 -> V_81 ) ;
return false ;
}
F_32 ( L_11 ,
V_44 , V_87 -> V_81 , V_88 -> V_81 ) ;
return true ;
}
static bool
F_55 ( struct V_1 * V_87 , struct V_1 * V_88 )
{
struct V_89 * V_90 = V_87 -> V_36 ;
struct V_89 * V_91 = V_88 -> V_36 ;
if ( V_90 -> V_92 != V_91 -> V_92 ) {
F_32 ( L_12 ,
V_44 ) ;
return false ;
}
if ( V_90 -> V_93 != V_91 -> V_93 )
goto V_94;
if ( memcmp ( V_90 -> V_95 , V_91 -> V_95 , V_90 -> V_93 ) != 0 )
goto V_94;
F_32 ( L_13 , V_44 ) ;
return true ;
V_94:
F_32 ( L_14 ,
V_44 ) ;
return false ;
}
int F_56 ( struct V_1 * V_71 ,
struct V_1 * * V_72 ,
struct V_73 * V_74 )
{
struct V_5 * V_6 = F_2 ( V_71 -> V_7 , V_8 ) ;
struct V_1 * V_75 , * V_76 , * V_77 = NULL ;
int error ;
F_4 ( & V_6 -> V_15 ) ;
F_50 (pos, n, &nn->nfs_client_list, cl_share_link) {
if ( V_75 -> V_56 < V_57 ) {
F_46 ( & V_75 -> V_67 ) ;
F_6 ( & V_6 -> V_15 ) ;
if ( V_77 )
F_45 ( V_77 ) ;
V_77 = V_75 ;
error = F_57 ( V_75 ) ;
if ( error < 0 ) {
F_45 ( V_75 ) ;
F_4 ( & V_6 -> V_15 ) ;
continue;
}
F_4 ( & V_6 -> V_15 ) ;
}
if ( V_75 -> V_9 != V_71 -> V_9 )
continue;
if ( V_75 -> V_85 != V_71 -> V_85 )
continue;
if ( V_75 -> V_28 != V_71 -> V_28 )
continue;
if ( ! F_54 ( V_75 , V_71 ) )
continue;
if ( ! F_55 ( V_75 , V_71 ) )
continue;
F_6 ( & V_6 -> V_15 ) ;
F_32 ( L_7 ,
V_44 , V_75 , F_52 ( & V_75 -> V_67 ) ) ;
* V_72 = V_75 ;
return 0 ;
}
F_6 ( & V_6 -> V_15 ) ;
F_53 ( L_9 , V_44 ) ;
return - V_86 ;
}
static void F_58 ( struct V_96 * V_97 )
{
F_59 ( V_97 ) ;
F_60 ( V_97 ) ;
F_61 ( V_97 ) ;
}
struct V_1 *
F_62 ( struct V_98 * V_98 , int V_99 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_98 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
V_2 = F_63 ( & V_6 -> V_12 , V_99 ) ;
if ( V_2 )
F_46 ( & V_2 -> V_67 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
static bool F_64 ( const struct V_63 * V_100 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_63 * V_101 = (struct V_63 * ) & V_2 -> V_102 ;
if ( ! ( V_2 -> V_56 == V_57 ||
V_2 -> V_56 == V_48 ) )
return false ;
F_65 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_28 != V_3 )
return false ;
if ( ! F_66 ( V_100 , V_101 ) )
return false ;
return true ;
}
struct V_1 *
F_67 ( struct V_98 * V_98 , const struct V_63 * V_100 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_98 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_68 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_64 ( V_100 , V_2 , 1 ) == false )
continue;
if ( ! F_8 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_18 -> V_105 . V_106 ,
V_104 -> V_106 , V_107 ) != 0 )
continue;
F_46 ( & V_2 -> V_67 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_15 ) ;
return NULL ;
}
struct V_1 *
F_67 ( struct V_98 * V_98 , const struct V_63 * V_100 ,
struct V_103 * V_104 )
{
return NULL ;
}
static int F_69 ( struct V_96 * V_97 ,
const char * V_108 ,
const struct V_63 * V_100 ,
const T_3 V_109 ,
const char * V_51 ,
T_1 V_52 ,
int V_110 , const struct V_49 * V_50 ,
T_2 V_3 , struct V_98 * V_98 )
{
struct V_19 V_20 = {
. V_108 = V_108 ,
. V_100 = V_100 ,
. V_109 = V_109 ,
. V_111 = & V_112 ,
. V_110 = V_110 ,
. V_3 = V_3 ,
. V_98 = V_98 ,
} ;
struct V_1 * V_2 ;
int error ;
F_32 ( L_15 ) ;
if ( V_97 -> V_113 & V_114 )
F_70 ( V_115 , & V_20 . V_116 ) ;
V_2 = F_71 ( & V_20 , V_50 , V_51 , V_52 ) ;
if ( F_13 ( V_2 ) ) {
error = F_72 ( V_2 ) ;
goto error;
}
F_70 ( V_117 , & V_2 -> V_32 ) ;
V_97 -> V_1 = V_2 ;
F_32 ( L_16 , V_2 ) ;
return 0 ;
error:
F_32 ( L_17 , error ) ;
return error ;
}
struct V_1 * F_73 ( struct V_1 * V_118 ,
const struct V_63 * V_119 , int V_120 ,
int V_121 , unsigned int V_122 , unsigned int V_123 )
{
struct V_19 V_20 = {
. V_100 = V_119 ,
. V_109 = V_120 ,
. V_111 = & V_112 ,
. V_110 = V_121 ,
. V_3 = V_118 -> V_28 ,
. V_98 = V_118 -> V_7 ,
} ;
struct V_49 V_124 ;
struct V_1 * V_2 ;
F_74 ( & V_124 , V_121 , V_122 , V_123 ) ;
V_2 = F_71 ( & V_20 , & V_124 , V_118 -> V_65 ,
V_118 -> V_41 -> V_125 -> V_126 ) ;
F_32 ( L_18 , V_44 , V_2 ) ;
return V_2 ;
}
static void F_75 ( struct V_96 * V_97 )
{
#ifdef V_45
struct V_46 * V_127 ;
T_2 V_128 ;
T_2 V_129 ;
if ( ! F_8 ( V_97 -> V_1 ) )
return;
V_127 = V_97 -> V_1 -> V_18 ;
V_128 = V_127 -> V_130 . V_131 - V_132 ;
V_129 = V_127 -> V_130 . V_133 - V_134 ;
if ( V_97 -> V_135 > V_128 )
V_97 -> V_135 = V_128 ;
if ( V_97 -> V_136 > V_129 )
V_97 -> V_136 = V_129 ;
#endif
}
static int F_76 ( struct V_96 * V_97 ,
struct V_137 * V_138 )
{
struct V_139 * V_140 ;
int error ;
F_77 ( ! V_97 -> V_1 ) ;
F_77 ( ! V_97 -> V_1 -> V_9 ) ;
F_77 ( ! V_97 -> V_1 -> V_9 -> V_141 ) ;
if ( F_78 ( V_97 -> V_1 ) )
return - V_142 ;
V_140 = F_79 () ;
if ( V_140 == NULL )
return - V_14 ;
error = F_80 ( V_97 ) ;
if ( error < 0 )
goto V_143;
error = F_81 ( V_97 , V_138 ) ;
if ( error < 0 )
goto V_143;
F_32 ( L_19 ,
( unsigned long long ) V_97 -> V_144 . V_145 ,
( unsigned long long ) V_97 -> V_144 . V_146 ) ;
F_32 ( L_20 , V_138 -> V_147 ) ;
F_75 ( V_97 ) ;
error = F_82 ( V_97 , V_138 , V_140 ) ;
if ( error < 0 )
goto V_143;
if ( V_97 -> V_148 == 0 || V_97 -> V_148 > V_149 )
V_97 -> V_148 = V_149 ;
F_83 ( V_97 ) ;
V_97 -> V_150 = V_151 ;
V_97 -> V_152 = F_58 ;
V_143:
F_84 ( V_140 ) ;
return error ;
}
static int F_85 ( struct V_96 * V_97 ,
const struct V_153 * V_106 )
{
struct V_49 V_50 ;
int error ;
F_32 ( L_21 ) ;
F_74 ( & V_50 , V_106 -> V_96 . V_154 ,
V_106 -> V_155 , V_106 -> V_156 ) ;
V_97 -> V_113 = V_106 -> V_113 ;
V_97 -> V_157 |= V_158 | V_159 | V_160 ;
if ( ! ( V_106 -> V_113 & V_161 ) )
V_97 -> V_157 |= V_162 ;
V_97 -> V_163 = V_106 -> V_163 ;
error = F_69 ( V_97 ,
V_106 -> V_96 . V_108 ,
( const struct V_63 * ) & V_106 -> V_96 . V_164 ,
V_106 -> V_96 . V_109 ,
V_106 -> V_165 ,
V_106 -> V_166 [ 0 ] ,
V_106 -> V_96 . V_154 ,
& V_50 ,
V_106 -> V_3 ,
V_106 -> V_98 ) ;
if ( error < 0 )
goto error;
if ( V_167 && V_106 -> V_166 [ 0 ] == V_168 )
V_97 -> V_157 |= V_169 ;
if ( V_106 -> V_135 )
V_97 -> V_135 = F_86 ( V_106 -> V_135 , NULL ) ;
if ( V_106 -> V_136 )
V_97 -> V_136 = F_86 ( V_106 -> V_136 , NULL ) ;
V_97 -> V_170 = V_106 -> V_170 * V_171 ;
V_97 -> V_172 = V_106 -> V_172 * V_171 ;
V_97 -> V_173 = V_106 -> V_173 * V_171 ;
V_97 -> V_174 = V_106 -> V_174 * V_171 ;
V_97 -> V_175 = V_106 -> V_96 . V_175 ;
error = F_87 ( V_97 , & V_50 , V_106 -> V_166 [ 0 ] ) ;
error:
F_32 ( L_22 , error ) ;
return error ;
}
struct V_96 * F_88 ( struct V_176 * V_177 ,
struct V_178 * V_111 )
{
struct V_96 * V_97 ;
int error ;
F_32 ( L_23 ) ;
V_97 = F_89 () ;
if ( ! V_97 )
return F_18 ( - V_14 ) ;
error = F_85 ( V_97 , V_177 -> V_179 ) ;
if ( error < 0 )
goto error;
error = F_76 ( V_97 , V_177 -> V_138 ) ;
if ( error < 0 )
goto error;
F_32 ( L_24 , V_97 ) ;
return V_97 ;
error:
F_90 ( V_97 ) ;
F_32 ( L_25 , error ) ;
return F_18 ( error ) ;
}
struct V_96 * F_91 ( struct V_180 * V_106 ,
struct V_137 * V_138 )
{
struct V_1 * V_181 ;
struct V_96 * V_97 , * V_182 ;
int error ;
F_32 ( L_26 ) ;
V_97 = F_89 () ;
if ( ! V_97 )
return F_18 ( - V_14 ) ;
V_182 = F_92 ( V_106 -> V_183 ) ;
V_181 = V_182 -> V_1 ;
F_93 ( V_97 , V_182 ) ;
V_97 -> V_157 |= V_158 | V_159 ;
error = F_69 ( V_97 , V_106 -> V_108 ,
V_106 -> V_100 ,
V_106 -> V_109 ,
V_181 -> V_65 ,
V_106 -> V_184 ,
F_94 ( V_182 -> V_185 ) ,
V_182 -> V_185 -> V_186 ,
V_181 -> V_29 -> V_33 ,
V_181 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_87 ( V_97 , V_182 -> V_185 -> V_186 , V_106 -> V_184 ) ;
if ( error < 0 )
goto error;
error = F_76 ( V_97 , V_138 ) ;
if ( error < 0 )
goto error;
F_32 ( L_27 , V_97 ) ;
return V_97 ;
error:
F_90 ( V_97 ) ;
F_32 ( L_28 , error ) ;
return F_18 ( error ) ;
}
