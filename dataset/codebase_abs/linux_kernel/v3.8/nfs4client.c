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
F_45 ( V_2 ) ;
if ( V_2 != V_55 ) {
V_2 -> V_66 = true ;
V_2 = V_55 ;
}
return V_2 ;
error:
F_37 ( V_2 , error ) ;
F_45 ( V_2 ) ;
F_32 ( L_5 , error ) ;
return F_18 ( error ) ;
}
static void F_46 ( struct V_1 * V_67 ,
struct V_1 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_67 -> V_7 , V_8 ) ;
unsigned int V_69 = V_67 -> V_16 ;
if ( V_67 -> V_16 == V_68 -> V_16 )
return;
F_32 ( L_6 ,
V_44 , V_67 -> V_16 , V_68 -> V_16 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_47 ( & V_6 -> V_12 , V_67 , V_68 -> V_16 ) ;
V_67 -> V_16 = V_68 -> V_16 ;
F_47 ( & V_6 -> V_12 , V_68 , V_69 ) ;
V_68 -> V_16 = V_69 ;
F_6 ( & V_6 -> V_15 ) ;
}
int F_48 ( struct V_1 * V_70 ,
struct V_1 * * V_71 ,
struct V_72 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_70 -> V_7 , V_8 ) ;
struct V_1 * V_74 , * V_75 , * V_76 = NULL ;
struct V_77 V_78 = {
. V_79 = V_70 -> V_80 ,
. V_81 = V_70 -> V_82 ,
} ;
int V_83 = - V_84 ;
F_4 ( & V_6 -> V_15 ) ;
F_49 (pos, n, &nn->nfs_client_list, cl_share_link) {
if ( V_74 -> V_56 < V_57 )
continue;
if ( V_74 -> V_9 != V_70 -> V_9 )
continue;
if ( V_74 -> V_85 != V_70 -> V_85 )
continue;
if ( V_74 -> V_28 != V_70 -> V_28 )
continue;
if ( V_74 -> V_80 != V_70 -> V_80 )
continue;
F_50 ( & V_74 -> V_86 ) ;
F_6 ( & V_6 -> V_15 ) ;
if ( V_76 )
F_45 ( V_76 ) ;
V_76 = V_74 ;
V_83 = F_51 ( V_74 , & V_78 , V_73 ) ;
switch ( V_83 ) {
case - V_84 :
break;
case 0 :
F_46 ( V_74 , V_70 ) ;
V_76 = NULL ;
* V_71 = V_74 ;
F_32 ( L_7 ,
V_44 , V_74 , F_52 ( & V_74 -> V_86 ) ) ;
default:
goto V_87;
}
F_4 ( & V_6 -> V_15 ) ;
}
F_6 ( & V_6 -> V_15 ) ;
V_87:
if ( V_76 )
F_45 ( V_76 ) ;
F_32 ( L_8 , V_44 , V_83 ) ;
return V_83 ;
}
static bool F_53 ( struct V_1 * V_88 , struct V_1 * V_89 )
{
if ( V_88 -> V_80 != V_89 -> V_80 ) {
F_32 ( L_9 ,
V_44 , V_88 -> V_80 , V_89 -> V_80 ) ;
return false ;
}
F_32 ( L_10 ,
V_44 , V_88 -> V_80 , V_89 -> V_80 ) ;
return true ;
}
static bool
F_54 ( struct V_1 * V_88 , struct V_1 * V_89 )
{
struct V_90 * V_91 = V_88 -> V_36 ;
struct V_90 * V_92 = V_89 -> V_36 ;
if ( V_91 -> V_93 != V_92 -> V_93 ) {
F_32 ( L_11 ,
V_44 ) ;
return false ;
}
if ( V_91 -> V_94 != V_92 -> V_94 )
goto V_95;
if ( memcmp ( V_91 -> V_96 , V_92 -> V_96 , V_91 -> V_94 ) != 0 )
goto V_95;
F_32 ( L_12 , V_44 ) ;
return true ;
V_95:
F_32 ( L_13 ,
V_44 ) ;
return false ;
}
int F_55 ( struct V_1 * V_70 ,
struct V_1 * * V_71 ,
struct V_72 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_70 -> V_7 , V_8 ) ;
struct V_1 * V_74 , * V_75 , * V_76 = NULL ;
int V_83 = - V_84 ;
F_4 ( & V_6 -> V_15 ) ;
F_49 (pos, n, &nn->nfs_client_list, cl_share_link) {
if ( V_74 -> V_56 < V_57 ) {
F_50 ( & V_74 -> V_86 ) ;
F_6 ( & V_6 -> V_15 ) ;
if ( V_76 )
F_45 ( V_76 ) ;
V_76 = V_74 ;
F_56 ( V_74 ) ;
V_83 = F_57 ( V_74 ) ;
if ( V_83 < 0 ) {
F_45 ( V_74 ) ;
F_4 ( & V_6 -> V_15 ) ;
continue;
}
V_83 = V_74 -> V_56 ;
F_4 ( & V_6 -> V_15 ) ;
if ( V_83 < 0 )
continue;
}
if ( V_74 -> V_9 != V_70 -> V_9 )
continue;
if ( V_74 -> V_85 != V_70 -> V_85 )
continue;
if ( V_74 -> V_28 != V_70 -> V_28 )
continue;
if ( ! F_53 ( V_74 , V_70 ) )
continue;
if ( ! F_54 ( V_74 , V_70 ) )
continue;
F_50 ( & V_74 -> V_86 ) ;
F_6 ( & V_6 -> V_15 ) ;
F_32 ( L_7 ,
V_44 , V_74 , F_52 ( & V_74 -> V_86 ) ) ;
* V_71 = V_74 ;
return 0 ;
}
F_6 ( & V_6 -> V_15 ) ;
F_32 ( L_8 , V_44 , V_83 ) ;
return V_83 ;
}
static void F_58 ( struct V_97 * V_98 )
{
F_59 ( V_98 ) ;
F_60 ( V_98 ) ;
F_61 ( V_98 ) ;
}
struct V_1 *
F_62 ( struct V_99 * V_99 , int V_100 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_99 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
V_2 = F_63 ( & V_6 -> V_12 , V_100 ) ;
if ( V_2 )
F_50 ( & V_2 -> V_86 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
static bool F_64 ( const struct V_63 * V_101 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_63 * V_102 = (struct V_63 * ) & V_2 -> V_103 ;
if ( ! ( V_2 -> V_56 == V_57 ||
V_2 -> V_56 == V_48 ) )
return false ;
F_65 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_28 != V_3 )
return false ;
if ( ! F_66 ( V_101 , V_102 ) )
return false ;
return true ;
}
struct V_1 *
F_67 ( struct V_99 * V_99 , const struct V_63 * V_101 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_99 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_68 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_64 ( V_101 , V_2 , 1 ) == false )
continue;
if ( ! F_8 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_18 -> V_106 . V_107 ,
V_105 -> V_107 , V_108 ) != 0 )
continue;
F_50 ( & V_2 -> V_86 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_15 ) ;
return NULL ;
}
struct V_1 *
F_67 ( struct V_99 * V_99 , const struct V_63 * V_101 ,
struct V_104 * V_105 )
{
return NULL ;
}
static int F_69 ( struct V_97 * V_98 ,
const char * V_109 ,
const struct V_63 * V_101 ,
const T_3 V_110 ,
const char * V_51 ,
T_1 V_52 ,
int V_111 , const struct V_49 * V_50 ,
T_2 V_3 , struct V_99 * V_99 )
{
struct V_19 V_20 = {
. V_109 = V_109 ,
. V_101 = V_101 ,
. V_110 = V_110 ,
. V_112 = & V_113 ,
. V_111 = V_111 ,
. V_3 = V_3 ,
. V_99 = V_99 ,
} ;
struct V_1 * V_2 ;
int error ;
F_32 ( L_14 ) ;
if ( V_98 -> V_114 & V_115 )
F_70 ( V_116 , & V_20 . V_117 ) ;
V_2 = F_71 ( & V_20 , V_50 , V_51 , V_52 ) ;
if ( F_13 ( V_2 ) ) {
error = F_72 ( V_2 ) ;
goto error;
}
F_70 ( V_118 , & V_2 -> V_32 ) ;
V_98 -> V_1 = V_2 ;
F_32 ( L_15 , V_2 ) ;
return 0 ;
error:
F_32 ( L_16 , error ) ;
return error ;
}
struct V_1 * F_73 ( struct V_1 * V_119 ,
const struct V_63 * V_120 , int V_121 ,
int V_122 , unsigned int V_123 , unsigned int V_124 )
{
struct V_19 V_20 = {
. V_101 = V_120 ,
. V_110 = V_121 ,
. V_112 = & V_113 ,
. V_111 = V_122 ,
. V_3 = V_119 -> V_28 ,
. V_99 = V_119 -> V_7 ,
} ;
struct V_49 V_125 ;
struct V_1 * V_2 ;
F_74 ( & V_125 , V_122 , V_123 , V_124 ) ;
V_2 = F_71 ( & V_20 , & V_125 , V_119 -> V_65 ,
V_119 -> V_41 -> V_126 -> V_127 ) ;
F_32 ( L_17 , V_44 , V_2 ) ;
return V_2 ;
}
static void F_75 ( struct V_97 * V_98 )
{
#ifdef V_45
struct V_46 * V_128 ;
T_2 V_129 ;
T_2 V_130 ;
if ( ! F_8 ( V_98 -> V_1 ) )
return;
V_128 = V_98 -> V_1 -> V_18 ;
V_129 = V_128 -> V_131 . V_132 - V_133 ;
V_130 = V_128 -> V_131 . V_134 - V_135 ;
if ( V_98 -> V_136 > V_129 )
V_98 -> V_136 = V_129 ;
if ( V_98 -> V_137 > V_130 )
V_98 -> V_137 = V_130 ;
#endif
}
static int F_76 ( struct V_97 * V_98 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 ;
int error ;
if ( F_77 ( V_98 -> V_1 ) )
return - V_142 ;
V_141 = F_78 () ;
if ( V_141 == NULL )
return - V_14 ;
error = F_79 ( V_98 ) ;
if ( error < 0 )
goto V_87;
error = F_80 ( V_98 , V_139 ) ;
if ( error < 0 )
goto V_87;
F_32 ( L_18 ,
( unsigned long long ) V_98 -> V_143 . V_144 ,
( unsigned long long ) V_98 -> V_143 . V_145 ) ;
F_32 ( L_19 , V_139 -> V_146 ) ;
F_75 ( V_98 ) ;
error = F_81 ( V_98 , V_139 , V_141 ) ;
if ( error < 0 )
goto V_87;
if ( V_98 -> V_147 == 0 || V_98 -> V_147 > V_148 )
V_98 -> V_147 = V_148 ;
F_82 ( V_98 ) ;
V_98 -> V_149 = V_150 ;
V_98 -> V_151 = F_58 ;
V_87:
F_83 ( V_141 ) ;
return error ;
}
static int F_84 ( struct V_97 * V_98 ,
const struct V_152 * V_107 )
{
struct V_49 V_50 ;
int error ;
F_32 ( L_20 ) ;
F_74 ( & V_50 , V_107 -> V_97 . V_153 ,
V_107 -> V_154 , V_107 -> V_155 ) ;
V_98 -> V_114 = V_107 -> V_114 ;
V_98 -> V_156 |= V_157 | V_158 | V_159 ;
if ( ! ( V_107 -> V_114 & V_160 ) )
V_98 -> V_156 |= V_161 ;
V_98 -> V_162 = V_107 -> V_162 ;
error = F_69 ( V_98 ,
V_107 -> V_97 . V_109 ,
( const struct V_63 * ) & V_107 -> V_97 . V_163 ,
V_107 -> V_97 . V_110 ,
V_107 -> V_164 ,
V_107 -> V_165 [ 0 ] ,
V_107 -> V_97 . V_153 ,
& V_50 ,
V_107 -> V_3 ,
V_107 -> V_99 ) ;
if ( error < 0 )
goto error;
if ( V_166 && V_107 -> V_165 [ 0 ] == V_167 )
V_98 -> V_156 |= V_168 ;
if ( V_107 -> V_136 )
V_98 -> V_136 = F_85 ( V_107 -> V_136 , NULL ) ;
if ( V_107 -> V_137 )
V_98 -> V_137 = F_85 ( V_107 -> V_137 , NULL ) ;
V_98 -> V_169 = V_107 -> V_169 * V_170 ;
V_98 -> V_171 = V_107 -> V_171 * V_170 ;
V_98 -> V_172 = V_107 -> V_172 * V_170 ;
V_98 -> V_173 = V_107 -> V_173 * V_170 ;
V_98 -> V_174 = V_107 -> V_97 . V_174 ;
error = F_86 ( V_98 , & V_50 , V_107 -> V_165 [ 0 ] ) ;
error:
F_32 ( L_21 , error ) ;
return error ;
}
struct V_97 * F_87 ( struct V_175 * V_176 ,
struct V_177 * V_112 )
{
struct V_97 * V_98 ;
int error ;
F_32 ( L_22 ) ;
V_98 = F_88 () ;
if ( ! V_98 )
return F_18 ( - V_14 ) ;
error = F_84 ( V_98 , V_176 -> V_178 ) ;
if ( error < 0 )
goto error;
error = F_76 ( V_98 , V_176 -> V_139 ) ;
if ( error < 0 )
goto error;
F_32 ( L_23 , V_98 ) ;
return V_98 ;
error:
F_89 ( V_98 ) ;
F_32 ( L_24 , error ) ;
return F_18 ( error ) ;
}
struct V_97 * F_90 ( struct V_179 * V_107 ,
struct V_138 * V_139 )
{
struct V_1 * V_180 ;
struct V_97 * V_98 , * V_181 ;
int error ;
F_32 ( L_25 ) ;
V_98 = F_88 () ;
if ( ! V_98 )
return F_18 ( - V_14 ) ;
V_181 = F_91 ( V_107 -> V_182 ) ;
V_180 = V_181 -> V_1 ;
F_92 ( V_98 , V_181 ) ;
V_98 -> V_156 |= V_157 | V_158 ;
error = F_69 ( V_98 , V_107 -> V_109 ,
V_107 -> V_101 ,
V_107 -> V_110 ,
V_180 -> V_65 ,
V_107 -> V_183 ,
F_93 ( V_181 -> V_184 ) ,
V_181 -> V_184 -> V_185 ,
V_180 -> V_29 -> V_33 ,
V_180 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_86 ( V_98 , V_181 -> V_184 -> V_185 , V_107 -> V_183 ) ;
if ( error < 0 )
goto error;
error = F_76 ( V_98 , V_139 ) ;
if ( error < 0 )
goto error;
F_32 ( L_26 , V_98 ) ;
return V_98 ;
error:
F_89 ( V_98 ) ;
F_32 ( L_27 , error ) ;
return F_18 ( error ) ;
}
