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
}
void F_53 ( struct V_1 * V_2 )
{
F_49 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_9 -> V_10 == 4 ) {
struct V_60 * V_61 ;
V_61 = F_55 ( V_2 -> V_30 -> V_62 ) ;
if ( F_35 ( V_2 ) ) {
error = F_56 ( V_61 ,
V_63 ) ;
if ( error < 0 )
return error ;
}
error = F_57 ( V_2 -> V_48 -> V_53 , V_61 ) ;
if ( error < 0 ) {
F_58 ( L_2 ,
V_64 , error ) ;
return error ;
}
F_59 ( V_51 , & V_2 -> V_52 ) ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_4 ;
V_66 = F_61 ( sizeof( * V_66 ) , V_28 ) ;
if ( V_66 == NULL )
return - V_29 ;
V_4 = F_62 ( V_66 , V_67 ,
L_3 ) ;
if ( V_4 ) {
F_21 ( V_66 ) ;
return V_4 ;
}
V_2 -> V_37 = V_66 ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_68 * V_69 = NULL ;
V_69 = F_64 ( V_2 ) ;
if ( ! V_69 )
return - V_29 ;
V_2 -> V_36 = V_69 ;
F_65 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = V_2 -> V_48 -> V_71 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return F_54 ( V_2 ) ;
}
struct V_1 * F_67 ( struct V_1 * V_2 ,
const struct V_72 * V_73 ,
const char * V_74 )
{
char V_75 [ V_76 + 1 ] ;
struct V_1 * V_77 ;
int error ;
if ( V_2 -> V_78 == V_79 ) {
F_58 ( L_4 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_80 ;
if ( V_2 -> V_47 != 0 )
F_59 ( V_81 , & V_2 -> V_82 ) ;
F_59 ( V_83 , & V_2 -> V_82 ) ;
F_59 ( V_84 , & V_2 -> V_82 ) ;
error = F_68 ( V_2 , V_73 , V_85 ) ;
if ( error == - V_41 )
error = F_68 ( V_2 , V_73 , V_86 ) ;
if ( error < 0 )
goto error;
if ( V_74 == NULL ) {
struct V_87 V_88 ;
struct V_89 * V_90 = (struct V_89 * ) & V_88 ;
error = F_69 ( V_2 -> V_30 , V_90 , sizeof( V_88 ) ) ;
if ( error < 0 )
goto error;
error = F_70 ( V_90 , V_75 , sizeof( V_75 ) ) ;
if ( error < 0 )
goto error;
V_74 = ( const char * ) V_75 ;
}
F_71 ( V_2 -> V_91 , V_74 , sizeof( V_2 -> V_91 ) ) ;
error = F_72 ( V_2 ) ;
if ( error < 0 ) {
F_58 ( L_5 ,
V_64 , error ) ;
goto error;
}
F_59 ( V_56 , & V_2 -> V_52 ) ;
error = F_66 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_35 ( V_2 ) )
F_65 ( V_2 , V_79 ) ;
error = F_73 ( V_2 , & V_77 ) ;
if ( error < 0 )
goto error;
if ( V_2 != V_77 )
V_2 -> V_92 = true ;
F_74 ( V_2 ) ;
return V_77 ;
error:
F_65 ( V_2 , error ) ;
F_74 ( V_2 ) ;
F_58 ( L_6 , error ) ;
return F_17 ( error ) ;
}
static void F_75 ( struct V_1 * V_93 ,
struct V_1 * V_94 )
{
struct V_5 * V_6 = F_2 ( V_93 -> V_7 , V_8 ) ;
unsigned int V_95 = V_93 -> V_15 ;
if ( V_93 -> V_15 == V_94 -> V_15 )
return;
F_58 ( L_7 ,
V_64 , V_93 -> V_15 , V_94 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_76 ( & V_6 -> V_13 , V_93 , V_94 -> V_15 ) ;
V_93 -> V_15 = V_94 -> V_15 ;
F_76 ( & V_6 -> V_13 , V_94 , V_95 ) ;
V_94 -> V_15 = V_95 ;
F_6 ( & V_6 -> V_12 ) ;
}
int F_77 ( struct V_1 * V_24 ,
struct V_1 * * V_96 ,
struct V_97 * V_98 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_99 , * V_100 = NULL ;
struct V_101 V_102 = {
. V_103 = V_24 -> V_104 ,
. V_105 = V_24 -> V_106 ,
} ;
int V_107 = - V_108 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_99 -> V_9 != V_24 -> V_9 )
continue;
if ( V_99 -> V_109 != V_24 -> V_109 )
continue;
if ( V_99 -> V_47 != V_24 -> V_47 )
continue;
if ( V_99 -> V_78 > V_79 ) {
F_78 ( & V_99 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_100 )
F_74 ( V_100 ) ;
V_100 = V_99 ;
V_107 = F_79 ( V_99 ) ;
if ( V_107 < 0 )
goto V_23;
V_107 = - V_108 ;
F_4 ( & V_6 -> V_12 ) ;
}
if ( V_99 -> V_78 != V_79 )
continue;
if ( V_99 -> V_104 != V_24 -> V_104 )
continue;
F_78 ( & V_99 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_100 )
F_74 ( V_100 ) ;
V_100 = V_99 ;
V_107 = F_80 ( V_99 , & V_102 , V_98 ) ;
switch ( V_107 ) {
case - V_108 :
break;
case 0 :
F_75 ( V_99 , V_24 ) ;
V_100 = NULL ;
* V_96 = V_99 ;
F_58 ( L_8 ,
V_64 , V_99 , F_81 ( & V_99 -> V_110 ) ) ;
goto V_23;
case - V_111 :
case - V_112 :
F_82 ( V_99 ) ;
default:
goto V_23;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_23:
if ( V_100 )
F_74 ( V_100 ) ;
F_58 ( L_9 , V_64 , V_107 ) ;
return V_107 ;
}
static bool F_83 ( struct V_1 * V_113 , struct V_1 * V_114 )
{
if ( V_113 -> V_104 != V_114 -> V_104 ) {
F_58 ( L_10 ,
V_64 , V_113 -> V_104 , V_114 -> V_104 ) ;
return false ;
}
F_58 ( L_11 ,
V_64 , V_113 -> V_104 , V_114 -> V_104 ) ;
return true ;
}
static bool
F_84 ( struct V_1 * V_113 , struct V_1 * V_114 )
{
struct V_115 * V_116 = V_113 -> V_57 ;
struct V_115 * V_117 = V_114 -> V_57 ;
if ( V_116 -> V_118 != V_117 -> V_118 ) {
F_58 ( L_12 ,
V_64 ) ;
return false ;
}
if ( V_116 -> V_119 != V_117 -> V_119 )
goto V_120;
if ( memcmp ( V_116 -> V_121 , V_117 -> V_121 , V_116 -> V_119 ) != 0 )
goto V_120;
F_58 ( L_13 , V_64 ) ;
return true ;
V_120:
F_58 ( L_14 ,
V_64 ) ;
return false ;
}
int F_85 ( struct V_1 * V_24 ,
struct V_1 * * V_96 ,
struct V_97 * V_98 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_99 , * V_100 = NULL ;
int V_107 = - V_108 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_99 -> V_9 != V_24 -> V_9 )
continue;
if ( V_99 -> V_109 != V_24 -> V_109 )
continue;
if ( V_99 -> V_47 != V_24 -> V_47 )
continue;
if ( V_99 -> V_78 > V_79 ) {
F_78 ( & V_99 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_100 )
F_74 ( V_100 ) ;
V_100 = V_99 ;
V_107 = F_79 ( V_99 ) ;
if ( V_107 == 0 ) {
F_86 ( V_99 ) ;
V_107 = F_87 ( V_99 ) ;
}
F_4 ( & V_6 -> V_12 ) ;
if ( V_107 < 0 )
break;
V_107 = - V_108 ;
}
if ( V_99 -> V_78 != V_79 )
continue;
if ( ! F_83 ( V_99 , V_24 ) )
continue;
if ( ! F_84 ( V_99 , V_24 ) )
continue;
F_78 ( & V_99 -> V_110 ) ;
* V_96 = V_99 ;
V_107 = 0 ;
F_58 ( L_8 ,
V_64 , V_99 , F_81 ( & V_99 -> V_110 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_58 ( L_9 , V_64 , V_107 ) ;
if ( V_100 )
F_74 ( V_100 ) ;
return V_107 ;
}
static void F_88 ( struct V_122 * V_123 )
{
F_89 ( V_123 ) ;
F_90 ( V_123 ) ;
F_91 ( V_123 ) ;
}
struct V_1 *
F_92 ( struct V_124 * V_124 , int V_125 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_124 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_93 ( & V_6 -> V_13 , V_125 ) ;
if ( V_2 )
F_78 ( & V_2 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_94 ( const struct V_89 * V_126 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_89 * V_127 = (struct V_89 * ) & V_2 -> V_128 ;
if ( ! ( V_2 -> V_78 == V_79 ||
V_2 -> V_78 == V_70 ) )
return false ;
F_95 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
if ( ! F_96 ( V_126 , V_127 ) )
return false ;
return true ;
}
struct V_1 *
F_97 ( struct V_124 * V_124 , const struct V_89 * V_126 ,
struct V_129 * V_130 , T_2 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_124 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_94 ( V_126 , V_2 , V_3 ) == false )
continue;
if ( ! F_35 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_36 -> V_131 . V_132 ,
V_130 -> V_132 , V_133 ) != 0 )
continue;
F_78 ( & V_2 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_97 ( struct V_124 * V_124 , const struct V_89 * V_126 ,
struct V_129 * V_130 , T_2 V_3 )
{
return NULL ;
}
static int F_98 ( struct V_122 * V_123 ,
const char * V_134 ,
const struct V_89 * V_126 ,
const T_3 V_135 ,
const char * V_74 ,
T_1 V_136 ,
int V_137 , const struct V_72 * V_73 ,
T_2 V_3 , struct V_124 * V_124 )
{
struct V_38 V_39 = {
. V_134 = V_134 ,
. V_126 = V_126 ,
. V_135 = V_135 ,
. V_138 = & V_139 ,
. V_137 = V_137 ,
. V_3 = V_3 ,
. V_124 = V_124 ,
} ;
struct V_1 * V_2 ;
int error ;
F_58 ( L_15 ) ;
if ( V_123 -> V_140 & V_141 )
F_99 ( V_142 , & V_39 . V_143 ) ;
if ( V_123 -> V_144 & V_145 )
F_99 ( V_146 , & V_39 . V_143 ) ;
V_2 = F_100 ( & V_39 , V_73 , V_74 , V_136 ) ;
if ( F_19 ( V_2 ) ) {
error = F_20 ( V_2 ) ;
goto error;
}
F_99 ( V_147 , & V_2 -> V_52 ) ;
V_123 -> V_1 = V_2 ;
F_58 ( L_16 , V_2 ) ;
return 0 ;
error:
F_58 ( L_17 , error ) ;
return error ;
}
struct V_1 * F_101 ( struct V_1 * V_148 ,
const struct V_89 * V_149 , int V_150 ,
int V_151 , unsigned int V_152 , unsigned int V_153 )
{
struct V_38 V_39 = {
. V_126 = V_149 ,
. V_135 = V_150 ,
. V_138 = & V_139 ,
. V_137 = V_151 ,
. V_3 = V_148 -> V_47 ,
. V_124 = V_148 -> V_7 ,
} ;
struct V_72 V_154 ;
struct V_1 * V_2 ;
char V_75 [ V_76 + 1 ] ;
if ( F_70 ( V_149 , V_75 , sizeof( V_75 ) ) <= 0 )
return F_17 ( - V_41 ) ;
V_39 . V_134 = V_75 ;
F_102 ( & V_154 , V_151 , V_152 , V_153 ) ;
V_2 = F_100 ( & V_39 , & V_154 , V_148 -> V_91 ,
V_148 -> V_30 -> V_21 -> V_22 ) ;
F_58 ( L_18 , V_64 , V_2 ) ;
return V_2 ;
}
static void F_103 ( struct V_122 * V_123 )
{
#ifdef F_104
struct V_68 * V_155 ;
T_2 V_156 ;
T_2 V_157 ;
if ( ! F_35 ( V_123 -> V_1 ) )
return;
V_155 = V_123 -> V_1 -> V_36 ;
V_156 = V_155 -> V_158 . V_159 - V_160 ;
V_157 = V_155 -> V_158 . V_161 - V_162 ;
if ( V_123 -> V_163 > V_156 )
V_123 -> V_163 = V_156 ;
if ( V_123 -> V_164 > V_157 )
V_123 -> V_164 = V_157 ;
#endif
}
static int F_105 ( struct V_122 * V_123 ,
struct V_165 * V_166 , bool V_167 )
{
struct V_168 * V_169 ;
int error ;
if ( F_106 ( V_123 -> V_1 ) )
return - V_170 ;
V_169 = F_107 () ;
if ( V_169 == NULL )
return - V_29 ;
error = F_108 ( V_123 -> V_1 ) ;
if ( error < 0 )
goto V_23;
V_123 -> V_171 |= V_123 -> V_1 -> V_48 -> V_172 ;
if ( V_123 -> V_140 & V_173 )
V_123 -> V_171 &= ~ V_174 ;
if ( V_175 &&
V_123 -> V_33 -> V_21 -> V_22 == V_86 )
V_123 -> V_171 |= V_176 ;
error = F_109 ( V_123 , V_166 , V_167 ) ;
if ( error < 0 )
goto V_23;
F_58 ( L_19 ,
( unsigned long long ) V_123 -> V_177 . V_178 ,
( unsigned long long ) V_123 -> V_177 . V_179 ) ;
F_110 ( V_166 , L_20 ) ;
F_103 ( V_123 ) ;
error = F_111 ( V_123 , V_166 , V_169 ) ;
if ( error < 0 )
goto V_23;
if ( V_123 -> V_180 == 0 || V_123 -> V_180 > V_181 )
V_123 -> V_180 = V_181 ;
F_112 ( V_123 ) ;
V_123 -> V_182 = V_183 ;
V_123 -> V_184 = F_88 ;
V_23:
F_113 ( V_169 ) ;
return error ;
}
static int F_114 ( struct V_122 * V_123 ,
struct V_185 * V_132 )
{
struct V_72 V_73 ;
int error ;
F_58 ( L_21 ) ;
F_102 ( & V_73 , V_132 -> V_122 . V_186 ,
V_132 -> V_187 , V_132 -> V_188 ) ;
V_123 -> V_140 = V_132 -> V_140 ;
V_123 -> V_144 = V_132 -> V_144 ;
V_123 -> V_189 = V_132 -> V_189 ;
if ( V_132 -> V_189 . V_190 >= 1 )
V_132 -> V_191 = V_132 -> V_189 . V_192 [ 0 ] ;
else
V_132 -> V_191 = V_86 ;
error = F_98 ( V_123 ,
V_132 -> V_122 . V_134 ,
( const struct V_89 * ) & V_132 -> V_122 . V_193 ,
V_132 -> V_122 . V_135 ,
V_132 -> V_194 ,
V_132 -> V_191 ,
V_132 -> V_122 . V_186 ,
& V_73 ,
V_132 -> V_3 ,
V_132 -> V_124 ) ;
if ( error < 0 )
goto error;
if ( V_132 -> V_163 )
V_123 -> V_163 = F_115 ( V_132 -> V_163 , NULL ) ;
if ( V_132 -> V_164 )
V_123 -> V_164 = F_115 ( V_132 -> V_164 , NULL ) ;
V_123 -> V_195 = V_132 -> V_195 * V_196 ;
V_123 -> V_197 = V_132 -> V_197 * V_196 ;
V_123 -> V_198 = V_132 -> V_198 * V_196 ;
V_123 -> V_199 = V_132 -> V_199 * V_196 ;
V_123 -> V_200 = V_132 -> V_122 . V_200 ;
error = F_116 ( V_123 , & V_73 ,
V_132 -> V_191 ) ;
error:
F_58 ( L_22 , error ) ;
return error ;
}
struct V_122 * F_117 ( struct V_201 * V_202 ,
struct V_203 * V_138 )
{
struct V_122 * V_123 ;
bool V_167 ;
int error ;
F_58 ( L_23 ) ;
V_123 = F_118 () ;
if ( ! V_123 )
return F_17 ( - V_29 ) ;
V_167 = V_202 -> V_204 -> V_189 . V_190 < 1 ;
error = F_114 ( V_123 , V_202 -> V_204 ) ;
if ( error < 0 )
goto error;
error = F_105 ( V_123 , V_202 -> V_166 , V_167 ) ;
if ( error < 0 )
goto error;
F_58 ( L_24 , V_123 ) ;
return V_123 ;
error:
F_119 ( V_123 ) ;
F_58 ( L_25 , error ) ;
return F_17 ( error ) ;
}
struct V_122 * F_120 ( struct V_205 * V_132 ,
struct V_165 * V_166 )
{
struct V_1 * V_206 ;
struct V_122 * V_123 , * V_207 ;
bool V_167 ;
int error ;
F_58 ( L_26 ) ;
V_123 = F_118 () ;
if ( ! V_123 )
return F_17 ( - V_29 ) ;
V_207 = F_121 ( V_132 -> V_208 ) ;
V_206 = V_207 -> V_1 ;
F_122 ( V_123 , V_207 ) ;
error = F_98 ( V_123 , V_132 -> V_134 ,
V_132 -> V_126 ,
V_132 -> V_135 ,
V_206 -> V_91 ,
V_132 -> V_209 ,
F_123 ( V_207 -> V_33 ) ,
V_207 -> V_33 -> V_210 ,
V_206 -> V_48 -> V_53 ,
V_206 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_116 ( V_123 , V_207 -> V_33 -> V_210 , V_132 -> V_209 ) ;
if ( error < 0 )
goto error;
V_167 = V_207 -> V_189 . V_190 < 1 ;
error = F_105 ( V_123 , V_166 , V_167 ) ;
if ( error < 0 )
goto error;
F_58 ( L_27 , V_123 ) ;
return V_123 ;
error:
F_119 ( V_123 ) ;
F_58 ( L_28 , error ) ;
return F_17 ( error ) ;
}
static int F_124 ( struct V_122 * V_123 )
{
struct V_32 * V_32 = V_123 -> V_211 -> V_212 -> V_213 ;
struct V_168 * V_169 ;
int error ;
V_169 = F_107 () ;
if ( V_169 == NULL )
return - V_29 ;
error = F_111 ( V_123 , F_125 ( V_32 ) , V_169 ) ;
F_113 ( V_169 ) ;
return error ;
}
int F_126 ( struct V_122 * V_123 , const char * V_134 ,
struct V_89 * V_90 , T_3 V_214 , struct V_124 * V_124 )
{
struct V_1 * V_2 = V_123 -> V_1 ;
struct V_20 * V_215 = V_123 -> V_33 ;
struct V_216 V_217 = {
. V_218 = V_2 -> V_109 ,
. V_124 = V_124 ,
. V_219 = V_90 ,
. V_135 = V_214 ,
. V_220 = V_134 ,
} ;
char V_75 [ V_76 + 1 ] ;
struct V_87 V_193 ;
struct V_89 * V_221 = (struct V_89 * ) & V_193 ;
int error ;
F_58 ( L_29 , V_64 ,
( unsigned long long ) V_123 -> V_177 . V_178 ,
( unsigned long long ) V_123 -> V_177 . V_179 ,
V_134 ) ;
error = F_127 ( V_215 , & V_217 , V_215 -> V_210 ) ;
if ( error != 0 ) {
F_58 ( L_30 ,
V_64 , error ) ;
goto V_23;
}
error = F_69 ( V_215 , V_221 , sizeof( V_193 ) ) ;
if ( error != 0 ) {
F_58 ( L_31 ,
V_64 , error ) ;
goto V_23;
}
error = - V_222 ;
if ( F_70 ( V_221 , V_75 , sizeof( V_75 ) ) == 0 ) {
F_58 ( L_32 ,
V_64 , error ) ;
goto V_23;
}
F_128 ( V_123 ) ;
error = F_98 ( V_123 , V_134 , V_90 , V_214 , V_75 ,
V_2 -> V_30 -> V_21 -> V_22 ,
V_2 -> V_109 , V_215 -> V_210 ,
V_2 -> V_47 , V_124 ) ;
F_74 ( V_2 ) ;
if ( error != 0 ) {
F_112 ( V_123 ) ;
F_58 ( L_33 ,
V_64 , error ) ;
goto V_23;
}
if ( V_123 -> V_1 -> V_223 == NULL )
V_123 -> V_1 -> V_223 = F_129 ( V_134 , V_11 ) ;
F_112 ( V_123 ) ;
error = F_124 ( V_123 ) ;
if ( error < 0 )
goto V_23;
F_58 ( L_34 , V_64 ) ;
V_23:
return error ;
}
