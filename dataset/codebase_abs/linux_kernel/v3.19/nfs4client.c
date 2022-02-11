static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , V_8 ) ;
if ( V_2 -> V_9 -> V_10 != 4 || V_3 != 0 )
return V_4 ;
F_3 ( V_11 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_4 = F_5 ( & V_6 -> V_13 , V_2 , 0 , 0 , V_14 ) ;
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
return V_2 ;
error:
F_45 ( V_2 ) ;
return F_17 ( V_31 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( F_47 ( V_51 , & V_2 -> V_52 ) )
F_48 ( V_2 -> V_48 -> V_53 , V_2 -> V_7 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( F_47 ( V_54 , & V_2 -> V_52 ) )
F_50 ( V_2 ) ;
V_2 -> V_48 -> V_55 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( F_47 ( V_56 , & V_2 -> V_52 ) )
F_51 ( V_2 ) ;
F_52 ( & V_2 -> V_44 ) ;
F_21 ( V_2 -> V_57 ) ;
F_21 ( V_2 -> V_58 ) ;
F_21 ( V_2 -> V_59 ) ;
F_21 ( V_2 -> V_60 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_49 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
int error ;
V_62 = F_55 ( V_2 -> V_30 -> V_63 ) ;
if ( F_35 ( V_2 ) ) {
error = F_56 ( V_62 , V_64 ) ;
if ( error < 0 )
return error ;
}
error = F_57 ( V_2 -> V_48 -> V_53 , V_62 ) ;
if ( error < 0 ) {
F_58 ( L_2 ,
V_65 , error ) ;
return error ;
}
F_59 ( V_51 , & V_2 -> V_52 ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_66 * V_67 ;
int V_4 ;
V_67 = F_61 ( sizeof( * V_67 ) , V_28 ) ;
if ( V_67 == NULL )
return - V_29 ;
V_4 = F_62 ( V_67 , V_68 ,
L_3 ) ;
if ( V_4 ) {
F_21 ( V_67 ) ;
return V_4 ;
}
V_2 -> V_37 = V_67 ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = NULL ;
V_70 = F_64 ( V_2 ) ;
if ( ! V_70 )
return - V_29 ;
V_2 -> V_36 = V_70 ;
F_65 ( V_2 , V_71 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = V_2 -> V_48 -> V_72 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return F_54 ( V_2 ) ;
}
struct V_1 * F_67 ( struct V_1 * V_2 ,
const struct V_73 * V_74 ,
const char * V_75 )
{
char V_76 [ V_77 + 1 ] ;
struct V_1 * V_78 ;
int error ;
if ( V_2 -> V_79 == V_80 ) {
F_58 ( L_4 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_81 ;
if ( V_2 -> V_47 != 0 )
F_59 ( V_82 , & V_2 -> V_83 ) ;
F_59 ( V_84 , & V_2 -> V_83 ) ;
F_59 ( V_85 , & V_2 -> V_83 ) ;
error = F_68 ( V_2 , V_74 , V_86 ) ;
if ( error == - V_41 )
error = F_68 ( V_2 , V_74 , V_87 ) ;
if ( error < 0 )
goto error;
if ( V_75 == NULL ) {
struct V_88 V_89 ;
struct V_90 * V_91 = (struct V_90 * ) & V_89 ;
error = F_69 ( V_2 -> V_30 , V_91 , sizeof( V_89 ) ) ;
if ( error < 0 )
goto error;
error = F_70 ( V_91 , V_76 , sizeof( V_76 ) ) ;
if ( error < 0 )
goto error;
V_75 = ( const char * ) V_76 ;
}
F_71 ( V_2 -> V_92 , V_75 , sizeof( V_2 -> V_92 ) ) ;
error = F_72 ( V_2 ) ;
if ( error < 0 ) {
F_58 ( L_5 ,
V_65 , error ) ;
goto error;
}
F_59 ( V_56 , & V_2 -> V_52 ) ;
error = F_66 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_35 ( V_2 ) )
F_65 ( V_2 , V_80 ) ;
error = F_73 ( V_2 , & V_78 ) ;
if ( error < 0 )
goto error;
if ( V_2 != V_78 )
V_2 -> V_93 = true ;
F_74 ( V_2 ) ;
return V_78 ;
error:
F_65 ( V_2 , error ) ;
F_74 ( V_2 ) ;
F_58 ( L_6 , error ) ;
return F_17 ( error ) ;
}
static void F_75 ( struct V_1 * V_94 ,
struct V_1 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_94 -> V_7 , V_8 ) ;
unsigned int V_96 = V_94 -> V_15 ;
if ( V_94 -> V_15 == V_95 -> V_15 )
return;
F_58 ( L_7 ,
V_65 , V_94 -> V_15 , V_95 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_76 ( & V_6 -> V_13 , V_94 , V_95 -> V_15 ) ;
V_94 -> V_15 = V_95 -> V_15 ;
F_76 ( & V_6 -> V_13 , V_95 , V_96 ) ;
V_95 -> V_15 = V_96 ;
F_6 ( & V_6 -> V_12 ) ;
}
static bool F_77 ( const struct V_1 * V_97 ,
const struct V_1 * V_98 )
{
if ( V_97 -> V_60 == NULL || V_98 -> V_60 == NULL )
return true ;
return strcmp ( V_97 -> V_60 , V_98 -> V_60 ) == 0 ;
}
int F_78 ( struct V_1 * V_24 ,
struct V_1 * * V_99 ,
struct V_100 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_102 , * V_103 = NULL ;
struct V_104 V_105 = {
. V_106 = V_24 -> V_107 ,
. V_108 = V_24 -> V_109 ,
} ;
int V_110 = - V_111 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_102 -> V_9 != V_24 -> V_9 )
continue;
if ( V_102 -> V_47 != V_24 -> V_47 )
continue;
if ( V_102 -> V_79 > V_80 ) {
F_79 ( & V_102 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_74 ( V_103 ) ;
V_103 = V_102 ;
V_110 = F_80 ( V_102 ) ;
if ( V_110 < 0 )
goto V_23;
V_110 = - V_111 ;
F_4 ( & V_6 -> V_12 ) ;
}
if ( V_102 -> V_79 != V_80 )
continue;
if ( V_102 -> V_107 != V_24 -> V_107 )
continue;
if ( ! F_77 ( V_102 , V_24 ) )
continue;
F_79 ( & V_102 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_74 ( V_103 ) ;
V_103 = V_102 ;
V_110 = F_81 ( V_102 , & V_105 , V_101 ) ;
switch ( V_110 ) {
case - V_111 :
break;
case 0 :
F_75 ( V_102 , V_24 ) ;
V_103 = NULL ;
* V_99 = V_102 ;
F_58 ( L_8 ,
V_65 , V_102 , F_82 ( & V_102 -> V_112 ) ) ;
goto V_23;
case - V_113 :
case - V_114 :
F_83 ( V_102 ) ;
default:
goto V_23;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_23:
F_74 ( V_103 ) ;
F_58 ( L_9 , V_65 , V_110 ) ;
return V_110 ;
}
static bool F_84 ( struct V_1 * V_115 , struct V_1 * V_116 )
{
if ( V_115 -> V_107 != V_116 -> V_107 ) {
F_58 ( L_10 ,
V_65 , V_115 -> V_107 , V_116 -> V_107 ) ;
return false ;
}
F_58 ( L_11 ,
V_65 , V_115 -> V_107 , V_116 -> V_107 ) ;
return true ;
}
static bool
F_85 ( struct V_1 * V_115 , struct V_1 * V_116 )
{
struct V_117 * V_118 = V_115 -> V_57 ;
struct V_117 * V_119 = V_116 -> V_57 ;
if ( V_118 -> V_120 != V_119 -> V_120 )
goto V_121;
if ( memcmp ( V_118 -> V_122 , V_119 -> V_122 , V_118 -> V_120 ) != 0 )
goto V_121;
F_58 ( L_12 , V_65 ) ;
return true ;
V_121:
F_58 ( L_13 ,
V_65 ) ;
return false ;
}
int F_86 ( struct V_1 * V_24 ,
struct V_1 * * V_99 ,
struct V_100 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_102 , * V_103 = NULL ;
int V_110 = - V_111 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_102 -> V_9 != V_24 -> V_9 )
continue;
if ( V_102 -> V_47 != V_24 -> V_47 )
continue;
if ( V_102 -> V_79 > V_80 ) {
F_79 ( & V_102 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_74 ( V_103 ) ;
V_103 = V_102 ;
V_110 = F_80 ( V_102 ) ;
if ( V_102 -> V_79 == V_71 ) {
F_87 ( V_102 ) ;
V_110 = F_88 ( V_102 ) ;
}
F_4 ( & V_6 -> V_12 ) ;
if ( V_110 < 0 )
break;
V_110 = - V_111 ;
}
if ( V_102 -> V_79 != V_80 )
continue;
if ( ! F_84 ( V_102 , V_24 ) )
continue;
if ( ! F_85 ( V_102 , V_24 ) )
continue;
if ( ! F_77 ( V_102 , V_24 ) )
continue;
F_79 ( & V_102 -> V_112 ) ;
* V_99 = V_102 ;
V_110 = 0 ;
F_58 ( L_8 ,
V_65 , V_102 , F_82 ( & V_102 -> V_112 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_58 ( L_9 , V_65 , V_110 ) ;
F_74 ( V_103 ) ;
return V_110 ;
}
static void F_89 ( struct V_123 * V_124 )
{
F_90 ( V_124 ) ;
F_91 ( V_124 ) ;
F_92 ( V_124 ) ;
}
struct V_1 *
F_93 ( struct V_125 * V_125 , int V_126 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_125 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_94 ( & V_6 -> V_13 , V_126 ) ;
if ( V_2 )
F_79 ( & V_2 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_95 ( const struct V_90 * V_127 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_90 * V_128 = (struct V_90 * ) & V_2 -> V_129 ;
if ( ! ( V_2 -> V_79 == V_80 ||
V_2 -> V_79 == V_71 ) )
return false ;
F_96 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
if ( ! F_97 ( V_127 , V_128 ) )
return false ;
return true ;
}
struct V_1 *
F_98 ( struct V_125 * V_125 , const struct V_90 * V_127 ,
struct V_130 * V_131 , T_2 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_125 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_95 ( V_127 , V_2 , V_3 ) == false )
continue;
if ( ! F_35 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_36 -> V_132 . V_133 ,
V_131 -> V_133 , V_134 ) != 0 )
continue;
F_79 ( & V_2 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_98 ( struct V_125 * V_125 , const struct V_90 * V_127 ,
struct V_130 * V_131 , T_2 V_3 )
{
return NULL ;
}
static int F_99 ( struct V_123 * V_124 ,
const char * V_135 ,
const struct V_90 * V_127 ,
const T_3 V_136 ,
const char * V_75 ,
T_1 V_137 ,
int V_138 , const struct V_73 * V_74 ,
T_2 V_3 , struct V_125 * V_125 )
{
struct V_38 V_39 = {
. V_135 = V_135 ,
. V_127 = V_127 ,
. V_136 = V_136 ,
. V_139 = & V_140 ,
. V_138 = V_138 ,
. V_3 = V_3 ,
. V_125 = V_125 ,
} ;
struct V_1 * V_2 ;
int error ;
F_58 ( L_14 ) ;
if ( V_124 -> V_141 & V_142 )
F_100 ( V_143 , & V_39 . V_144 ) ;
if ( V_124 -> V_145 & V_146 )
F_100 ( V_147 , & V_39 . V_144 ) ;
V_2 = F_101 ( & V_39 , V_74 , V_75 , V_137 ) ;
if ( F_19 ( V_2 ) ) {
error = F_20 ( V_2 ) ;
goto error;
}
F_100 ( V_148 , & V_2 -> V_52 ) ;
V_124 -> V_1 = V_2 ;
F_58 ( L_15 , V_2 ) ;
return 0 ;
error:
F_58 ( L_16 , error ) ;
return error ;
}
struct V_1 * F_102 ( struct V_1 * V_149 ,
const struct V_90 * V_150 , int V_151 ,
int V_152 , unsigned int V_153 , unsigned int V_154 )
{
struct V_38 V_39 = {
. V_127 = V_150 ,
. V_136 = V_151 ,
. V_139 = & V_140 ,
. V_138 = V_152 ,
. V_3 = V_149 -> V_47 ,
. V_125 = V_149 -> V_7 ,
} ;
struct V_73 V_155 ;
struct V_1 * V_2 ;
char V_76 [ V_77 + 1 ] ;
if ( F_70 ( V_150 , V_76 , sizeof( V_76 ) ) <= 0 )
return F_17 ( - V_41 ) ;
V_39 . V_135 = V_76 ;
F_103 ( & V_155 , V_152 , V_153 , V_154 ) ;
V_2 = F_101 ( & V_39 , & V_155 , V_149 -> V_92 ,
V_149 -> V_30 -> V_21 -> V_22 ) ;
F_58 ( L_17 , V_65 , V_2 ) ;
return V_2 ;
}
static void F_104 ( struct V_123 * V_124 )
{
#ifdef F_105
struct V_69 * V_156 ;
T_2 V_157 ;
T_2 V_158 ;
if ( ! F_35 ( V_124 -> V_1 ) )
return;
V_156 = V_124 -> V_1 -> V_36 ;
V_157 = V_156 -> V_159 . V_160 - V_161 ;
V_158 = V_156 -> V_159 . V_162 - V_163 ;
if ( V_124 -> V_164 > V_157 )
V_124 -> V_164 = V_157 ;
if ( V_124 -> V_165 > V_158 )
V_124 -> V_165 = V_158 ;
#endif
}
static int F_106 ( struct V_123 * V_124 ,
struct V_166 * V_167 , bool V_168 )
{
struct V_169 * V_170 ;
int error ;
if ( F_107 ( V_124 -> V_1 ) )
return - V_171 ;
V_170 = F_108 () ;
if ( V_170 == NULL )
return - V_29 ;
error = F_109 ( V_124 -> V_1 ) ;
if ( error < 0 )
goto V_23;
V_124 -> V_172 |= V_124 -> V_1 -> V_48 -> V_173 ;
if ( V_124 -> V_141 & V_174 )
V_124 -> V_172 &= ~ V_175 ;
if ( V_176 &&
V_124 -> V_33 -> V_21 -> V_22 == V_87 )
V_124 -> V_172 |= V_177 ;
error = F_110 ( V_124 , V_167 , V_168 ) ;
if ( error < 0 )
goto V_23;
F_58 ( L_18 ,
( unsigned long long ) V_124 -> V_178 . V_179 ,
( unsigned long long ) V_124 -> V_178 . V_180 ) ;
F_111 ( V_167 , L_19 ) ;
F_104 ( V_124 ) ;
error = F_112 ( V_124 , V_167 , V_170 ) ;
if ( error < 0 )
goto V_23;
if ( V_124 -> V_181 == 0 || V_124 -> V_181 > V_182 )
V_124 -> V_181 = V_182 ;
F_113 ( V_124 ) ;
V_124 -> V_183 = V_184 ;
V_124 -> V_185 = F_89 ;
V_23:
F_114 ( V_170 ) ;
return error ;
}
static int F_115 ( struct V_123 * V_124 ,
struct V_186 * V_133 )
{
struct V_73 V_74 ;
int error ;
F_58 ( L_20 ) ;
F_103 ( & V_74 , V_133 -> V_123 . V_187 ,
V_133 -> V_188 , V_133 -> V_189 ) ;
V_124 -> V_141 = V_133 -> V_141 ;
V_124 -> V_145 = V_133 -> V_145 ;
V_124 -> V_190 = V_133 -> V_190 ;
if ( V_133 -> V_190 . V_191 >= 1 )
V_133 -> V_192 = V_133 -> V_190 . V_193 [ 0 ] ;
else
V_133 -> V_192 = V_87 ;
error = F_99 ( V_124 ,
V_133 -> V_123 . V_135 ,
( const struct V_90 * ) & V_133 -> V_123 . V_194 ,
V_133 -> V_123 . V_136 ,
V_133 -> V_195 ,
V_133 -> V_192 ,
V_133 -> V_123 . V_187 ,
& V_74 ,
V_133 -> V_3 ,
V_133 -> V_125 ) ;
if ( error < 0 )
goto error;
if ( V_133 -> V_164 )
V_124 -> V_164 = F_116 ( V_133 -> V_164 , NULL ) ;
if ( V_133 -> V_165 )
V_124 -> V_165 = F_116 ( V_133 -> V_165 , NULL ) ;
V_124 -> V_196 = V_133 -> V_196 * V_197 ;
V_124 -> V_198 = V_133 -> V_198 * V_197 ;
V_124 -> V_199 = V_133 -> V_199 * V_197 ;
V_124 -> V_200 = V_133 -> V_200 * V_197 ;
V_124 -> V_201 = V_133 -> V_123 . V_201 ;
error = F_117 ( V_124 , & V_74 ,
V_133 -> V_192 ) ;
error:
F_58 ( L_21 , error ) ;
return error ;
}
struct V_123 * F_118 ( struct V_202 * V_203 ,
struct V_204 * V_139 )
{
struct V_123 * V_124 ;
bool V_168 ;
int error ;
F_58 ( L_22 ) ;
V_124 = F_119 () ;
if ( ! V_124 )
return F_17 ( - V_29 ) ;
V_168 = V_203 -> V_205 -> V_190 . V_191 < 1 ;
error = F_115 ( V_124 , V_203 -> V_205 ) ;
if ( error < 0 )
goto error;
error = F_106 ( V_124 , V_203 -> V_167 , V_168 ) ;
if ( error < 0 )
goto error;
F_58 ( L_23 , V_124 ) ;
return V_124 ;
error:
F_120 ( V_124 ) ;
F_58 ( L_24 , error ) ;
return F_17 ( error ) ;
}
struct V_123 * F_121 ( struct V_206 * V_133 ,
struct V_166 * V_167 )
{
struct V_1 * V_207 ;
struct V_123 * V_124 , * V_208 ;
bool V_168 ;
int error ;
F_58 ( L_25 ) ;
V_124 = F_119 () ;
if ( ! V_124 )
return F_17 ( - V_29 ) ;
V_208 = F_122 ( V_133 -> V_209 ) ;
V_207 = V_208 -> V_1 ;
F_123 ( V_124 , V_208 ) ;
error = F_99 ( V_124 , V_133 -> V_135 ,
V_133 -> V_127 ,
V_133 -> V_136 ,
V_207 -> V_92 ,
V_133 -> V_210 ,
F_124 ( V_208 -> V_33 ) ,
V_208 -> V_33 -> V_211 ,
V_207 -> V_48 -> V_53 ,
V_207 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_117 ( V_124 , V_208 -> V_33 -> V_211 , V_133 -> V_210 ) ;
if ( error < 0 )
goto error;
V_168 = V_208 -> V_190 . V_191 < 1 ;
error = F_106 ( V_124 , V_167 , V_168 ) ;
if ( error < 0 )
goto error;
F_58 ( L_26 , V_124 ) ;
return V_124 ;
error:
F_120 ( V_124 ) ;
F_58 ( L_27 , error ) ;
return F_17 ( error ) ;
}
static int F_125 ( struct V_123 * V_124 )
{
struct V_32 * V_32 = V_124 -> V_212 -> V_213 -> V_214 ;
struct V_169 * V_170 ;
int error ;
V_170 = F_108 () ;
if ( V_170 == NULL )
return - V_29 ;
error = F_112 ( V_124 , F_126 ( V_32 ) , V_170 ) ;
F_114 ( V_170 ) ;
return error ;
}
int F_127 ( struct V_123 * V_124 , const char * V_135 ,
struct V_90 * V_91 , T_3 V_215 , struct V_125 * V_125 )
{
struct V_1 * V_2 = V_124 -> V_1 ;
struct V_20 * V_216 = V_124 -> V_33 ;
struct V_217 V_218 = {
. V_219 = V_2 -> V_220 ,
. V_125 = V_125 ,
. V_221 = V_91 ,
. V_136 = V_215 ,
. V_222 = V_135 ,
} ;
char V_76 [ V_77 + 1 ] ;
struct V_88 V_194 ;
struct V_90 * V_223 = (struct V_90 * ) & V_194 ;
int error ;
F_58 ( L_28 , V_65 ,
( unsigned long long ) V_124 -> V_178 . V_179 ,
( unsigned long long ) V_124 -> V_178 . V_180 ,
V_135 ) ;
error = F_128 ( V_216 , & V_218 , V_216 -> V_211 ) ;
if ( error != 0 ) {
F_58 ( L_29 ,
V_65 , error ) ;
goto V_23;
}
error = F_69 ( V_216 , V_223 , sizeof( V_194 ) ) ;
if ( error != 0 ) {
F_58 ( L_30 ,
V_65 , error ) ;
goto V_23;
}
error = - V_224 ;
if ( F_70 ( V_223 , V_76 , sizeof( V_76 ) ) == 0 ) {
F_58 ( L_31 ,
V_65 , error ) ;
goto V_23;
}
F_129 ( V_124 ) ;
error = F_99 ( V_124 , V_135 , V_91 , V_215 , V_76 ,
V_2 -> V_30 -> V_21 -> V_22 ,
V_2 -> V_220 , V_216 -> V_211 ,
V_2 -> V_47 , V_125 ) ;
F_74 ( V_2 ) ;
if ( error != 0 ) {
F_113 ( V_124 ) ;
F_58 ( L_32 ,
V_65 , error ) ;
goto V_23;
}
if ( V_124 -> V_1 -> V_225 == NULL )
V_124 -> V_1 -> V_225 = F_130 ( V_135 , V_11 ) ;
F_113 ( V_124 ) ;
error = F_125 ( V_124 ) ;
if ( error < 0 )
goto V_23;
F_58 ( L_33 , V_65 ) ;
V_23:
return error ;
}
