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
const struct V_38 * V_39 )
{
char V_73 [ V_74 + 1 ] ;
const char * V_75 = V_39 -> V_75 ;
struct V_1 * V_76 ;
int error ;
if ( V_2 -> V_77 == V_78 ) {
F_58 ( L_4 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_79 ;
if ( V_2 -> V_47 != 0 )
F_59 ( V_80 , & V_2 -> V_81 ) ;
F_59 ( V_82 , & V_2 -> V_81 ) ;
F_59 ( V_83 , & V_2 -> V_81 ) ;
error = F_68 ( V_2 , V_39 , V_84 ) ;
if ( error == - V_41 )
error = F_68 ( V_2 , V_39 , V_85 ) ;
if ( error < 0 )
goto error;
if ( V_75 == NULL ) {
struct V_86 V_87 ;
struct V_88 * V_89 = (struct V_88 * ) & V_87 ;
error = F_69 ( V_2 -> V_30 , V_89 , sizeof( V_87 ) ) ;
if ( error < 0 )
goto error;
error = F_70 ( V_89 , V_73 , sizeof( V_73 ) ) ;
if ( error < 0 )
goto error;
V_75 = ( const char * ) V_73 ;
}
F_71 ( V_2 -> V_90 , V_75 , sizeof( V_2 -> V_90 ) ) ;
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
F_65 ( V_2 , V_78 ) ;
error = F_73 ( V_2 , & V_76 ) ;
if ( error < 0 )
goto error;
if ( V_2 != V_76 )
V_2 -> V_91 = true ;
F_74 ( V_2 ) ;
return V_76 ;
error:
F_65 ( V_2 , error ) ;
F_74 ( V_2 ) ;
F_58 ( L_6 , error ) ;
return F_17 ( error ) ;
}
static void F_75 ( struct V_1 * V_92 ,
struct V_1 * V_93 )
{
struct V_5 * V_6 = F_2 ( V_92 -> V_7 , V_8 ) ;
unsigned int V_94 = V_92 -> V_15 ;
if ( V_92 -> V_15 == V_93 -> V_15 )
return;
F_58 ( L_7 ,
V_65 , V_92 -> V_15 , V_93 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_76 ( & V_6 -> V_13 , V_92 , V_93 -> V_15 ) ;
V_92 -> V_15 = V_93 -> V_15 ;
F_76 ( & V_6 -> V_13 , V_93 , V_94 ) ;
V_93 -> V_15 = V_94 ;
F_6 ( & V_6 -> V_12 ) ;
}
static bool F_77 ( const struct V_1 * V_95 ,
const struct V_1 * V_96 )
{
if ( V_95 -> V_60 == NULL || V_96 -> V_60 == NULL )
return true ;
return strcmp ( V_95 -> V_60 , V_96 -> V_60 ) == 0 ;
}
int F_78 ( struct V_1 * V_24 ,
struct V_1 * * V_97 ,
struct V_98 * V_99 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_100 , * V_101 = NULL ;
struct V_102 V_103 = {
. V_104 = V_24 -> V_105 ,
. V_106 = V_24 -> V_107 ,
} ;
int V_108 = - V_109 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_100 -> V_9 != V_24 -> V_9 )
continue;
if ( V_100 -> V_47 != V_24 -> V_47 )
continue;
if ( V_100 -> V_77 > V_78 ) {
F_79 ( & V_100 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_74 ( V_101 ) ;
V_101 = V_100 ;
V_108 = F_80 ( V_100 ) ;
if ( V_108 < 0 )
goto V_23;
V_108 = - V_109 ;
F_4 ( & V_6 -> V_12 ) ;
}
if ( V_100 -> V_77 != V_78 )
continue;
if ( V_100 -> V_105 != V_24 -> V_105 )
continue;
if ( ! F_77 ( V_100 , V_24 ) )
continue;
F_79 ( & V_100 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_74 ( V_101 ) ;
V_101 = V_100 ;
V_108 = F_81 ( V_100 , & V_103 , V_99 ) ;
switch ( V_108 ) {
case - V_109 :
break;
case 0 :
F_75 ( V_100 , V_24 ) ;
V_101 = NULL ;
* V_97 = V_100 ;
F_58 ( L_8 ,
V_65 , V_100 , F_82 ( & V_100 -> V_110 ) ) ;
goto V_23;
case - V_111 :
case - V_112 :
F_83 ( V_100 ) ;
default:
goto V_23;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_23:
F_74 ( V_101 ) ;
F_58 ( L_9 , V_65 , V_108 ) ;
return V_108 ;
}
static bool F_84 ( struct V_1 * V_113 , struct V_1 * V_114 )
{
if ( V_113 -> V_105 != V_114 -> V_105 ) {
F_58 ( L_10 ,
V_65 , V_113 -> V_105 , V_114 -> V_105 ) ;
return false ;
}
F_58 ( L_11 ,
V_65 , V_113 -> V_105 , V_114 -> V_105 ) ;
return true ;
}
static bool
F_85 ( struct V_1 * V_113 , struct V_1 * V_114 )
{
struct V_115 * V_116 = V_113 -> V_57 ;
struct V_115 * V_117 = V_114 -> V_57 ;
if ( V_116 -> V_118 != V_117 -> V_118 )
goto V_119;
if ( memcmp ( V_116 -> V_120 , V_117 -> V_120 , V_116 -> V_118 ) != 0 )
goto V_119;
F_58 ( L_12 , V_65 ) ;
return true ;
V_119:
F_58 ( L_13 ,
V_65 ) ;
return false ;
}
int F_86 ( struct V_1 * V_24 ,
struct V_1 * * V_97 ,
struct V_98 * V_99 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_100 , * V_101 = NULL ;
int V_108 = - V_109 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_100 == V_24 )
goto V_121;
if ( V_100 -> V_9 != V_24 -> V_9 )
continue;
if ( V_100 -> V_47 != V_24 -> V_47 )
continue;
if ( V_100 -> V_77 > V_78 ) {
F_79 ( & V_100 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_74 ( V_101 ) ;
V_101 = V_100 ;
V_108 = F_80 ( V_100 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_108 < 0 )
break;
V_108 = - V_109 ;
}
if ( V_100 -> V_77 != V_78 )
continue;
if ( ! F_84 ( V_100 , V_24 ) )
continue;
if ( ! F_85 ( V_100 , V_24 ) )
continue;
if ( ! F_77 ( V_100 , V_24 ) )
continue;
V_121:
F_79 ( & V_100 -> V_110 ) ;
* V_97 = V_100 ;
V_108 = 0 ;
F_58 ( L_8 ,
V_65 , V_100 , F_82 ( & V_100 -> V_110 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_58 ( L_9 , V_65 , V_108 ) ;
F_74 ( V_101 ) ;
return V_108 ;
}
static void F_87 ( struct V_122 * V_123 )
{
F_88 ( V_123 ) ;
F_89 ( V_123 ) ;
F_90 ( V_123 ) ;
}
struct V_1 *
F_91 ( struct V_124 * V_124 , int V_125 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_124 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_92 ( & V_6 -> V_13 , V_125 ) ;
if ( V_2 )
F_79 ( & V_2 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_93 ( const struct V_88 * V_126 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_88 * V_127 = (struct V_88 * ) & V_2 -> V_128 ;
if ( ! ( V_2 -> V_77 == V_78 ||
V_2 -> V_77 == V_71 ) )
return false ;
F_94 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
return F_95 ( V_126 , V_127 ) ;
}
struct V_1 *
F_96 ( struct V_124 * V_124 , const struct V_88 * V_126 ,
struct V_129 * V_130 , T_2 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_124 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_93 ( V_126 , V_2 , V_3 ) == false )
continue;
if ( ! F_35 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_36 -> V_131 . V_132 ,
V_130 -> V_132 , V_133 ) != 0 )
continue;
F_79 ( & V_2 -> V_110 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_96 ( struct V_124 * V_124 , const struct V_88 * V_126 ,
struct V_129 * V_130 , T_2 V_3 )
{
return NULL ;
}
static int F_97 ( struct V_122 * V_123 ,
const char * V_134 ,
const struct V_88 * V_126 ,
const T_3 V_135 ,
const char * V_75 ,
T_1 V_136 ,
int V_137 , const struct V_138 * V_139 ,
T_2 V_3 , struct V_124 * V_124 )
{
struct V_38 V_39 = {
. V_134 = V_134 ,
. V_126 = V_126 ,
. V_135 = V_135 ,
. V_75 = V_75 ,
. V_140 = & V_141 ,
. V_137 = V_137 ,
. V_3 = V_3 ,
. V_124 = V_124 ,
. V_139 = V_139 ,
} ;
struct V_1 * V_2 ;
int error ;
F_58 ( L_14 ) ;
if ( V_123 -> V_142 & V_143 )
F_98 ( V_144 , & V_39 . V_145 ) ;
if ( V_123 -> V_146 & V_147 )
F_98 ( V_148 , & V_39 . V_145 ) ;
V_2 = F_99 ( & V_39 , V_136 ) ;
if ( F_19 ( V_2 ) ) {
error = F_20 ( V_2 ) ;
goto error;
}
if ( V_123 -> V_1 == V_2 ) {
error = - V_149 ;
goto error;
}
F_98 ( V_150 , & V_2 -> V_52 ) ;
V_123 -> V_1 = V_2 ;
F_58 ( L_15 , V_2 ) ;
return 0 ;
error:
F_58 ( L_16 , error ) ;
return error ;
}
struct V_1 * F_100 ( struct V_122 * V_151 ,
const struct V_88 * V_152 , int V_153 ,
int V_154 , unsigned int V_155 , unsigned int V_156 ,
T_2 V_53 , T_1 V_22 )
{
struct V_138 V_157 ;
struct V_1 * V_158 = V_151 -> V_1 ;
struct V_38 V_39 = {
. V_126 = V_152 ,
. V_135 = V_153 ,
. V_159 = V_158 -> V_30 -> V_160 ,
. V_75 = V_158 -> V_90 ,
. V_140 = & V_141 ,
. V_137 = V_154 ,
. V_3 = V_53 ,
. V_124 = V_158 -> V_7 ,
. V_139 = & V_157 ,
} ;
struct V_1 * V_2 ;
char V_73 [ V_74 + 1 ] ;
if ( F_70 ( V_152 , V_73 , sizeof( V_73 ) ) <= 0 )
return F_17 ( - V_41 ) ;
V_39 . V_134 = V_73 ;
if ( V_151 -> V_142 & V_143 )
F_59 ( V_144 , & V_39 . V_145 ) ;
F_101 ( & V_157 , V_154 , V_155 , V_156 ) ;
V_2 = F_99 ( & V_39 , V_22 ) ;
F_58 ( L_17 , V_65 , V_2 ) ;
return V_2 ;
}
static void F_102 ( struct V_122 * V_123 )
{
#ifdef F_103
struct V_69 * V_161 ;
T_2 V_162 ;
T_2 V_163 ;
if ( ! F_35 ( V_123 -> V_1 ) )
return;
V_161 = V_123 -> V_1 -> V_36 ;
V_162 = V_161 -> V_164 . V_165 - V_166 ;
V_163 = V_161 -> V_164 . V_167 - V_168 ;
if ( V_123 -> V_169 > V_162 )
V_123 -> V_169 = V_162 ;
if ( V_123 -> V_170 > V_163 )
V_123 -> V_170 = V_163 ;
#endif
}
static int F_104 ( struct V_122 * V_123 ,
struct V_171 * V_172 , bool V_173 )
{
struct V_174 * V_175 ;
int error ;
if ( F_105 ( V_123 -> V_1 ) )
return - V_176 ;
V_175 = F_106 () ;
if ( V_175 == NULL )
return - V_29 ;
error = F_107 ( V_123 -> V_1 ) ;
if ( error < 0 )
goto V_23;
V_123 -> V_177 |= V_123 -> V_1 -> V_48 -> V_178 ;
if ( V_123 -> V_142 & V_179 )
V_123 -> V_177 &= ~ V_180 ;
if ( V_181 &&
V_123 -> V_33 -> V_21 -> V_22 == V_85 )
V_123 -> V_177 |= V_182 ;
error = F_108 ( V_123 , V_172 , V_173 ) ;
if ( error < 0 )
goto V_23;
F_58 ( L_18 ,
( unsigned long long ) V_123 -> V_183 . V_184 ,
( unsigned long long ) V_123 -> V_183 . V_185 ) ;
F_109 ( V_172 , L_19 ) ;
F_102 ( V_123 ) ;
error = F_110 ( V_123 , V_172 , V_175 ) ;
if ( error < 0 )
goto V_23;
if ( V_123 -> V_186 == 0 || V_123 -> V_186 > V_187 )
V_123 -> V_186 = V_187 ;
F_111 ( V_123 ) ;
V_123 -> V_188 = V_189 ;
V_123 -> V_190 = F_87 ;
V_23:
F_112 ( V_175 ) ;
return error ;
}
static int F_113 ( struct V_122 * V_123 ,
struct V_191 * V_132 )
{
struct V_138 V_139 ;
int error ;
F_58 ( L_20 ) ;
F_101 ( & V_139 , V_132 -> V_122 . V_192 ,
V_132 -> V_193 , V_132 -> V_194 ) ;
V_123 -> V_142 = V_132 -> V_142 ;
V_123 -> V_146 = V_132 -> V_146 ;
V_123 -> V_195 = V_132 -> V_195 ;
if ( V_132 -> V_195 . V_196 >= 1 )
V_132 -> V_197 = V_132 -> V_195 . V_198 [ 0 ] ;
else
V_132 -> V_197 = V_85 ;
error = F_97 ( V_123 ,
V_132 -> V_122 . V_134 ,
( const struct V_88 * ) & V_132 -> V_122 . V_199 ,
V_132 -> V_122 . V_135 ,
V_132 -> V_200 ,
V_132 -> V_197 ,
V_132 -> V_122 . V_192 ,
& V_139 ,
V_132 -> V_3 ,
V_132 -> V_124 ) ;
if ( error < 0 )
goto error;
if ( V_132 -> V_169 )
V_123 -> V_169 = F_114 ( V_132 -> V_169 , NULL ) ;
if ( V_132 -> V_170 )
V_123 -> V_170 = F_114 ( V_132 -> V_170 , NULL ) ;
V_123 -> V_201 = V_132 -> V_201 * V_202 ;
V_123 -> V_203 = V_132 -> V_203 * V_202 ;
V_123 -> V_204 = V_132 -> V_204 * V_202 ;
V_123 -> V_205 = V_132 -> V_205 * V_202 ;
V_123 -> V_206 = V_132 -> V_122 . V_206 ;
error = F_115 ( V_123 , & V_139 ,
V_132 -> V_197 ) ;
error:
F_58 ( L_21 , error ) ;
return error ;
}
struct V_122 * F_116 ( struct V_207 * V_208 ,
struct V_209 * V_140 )
{
struct V_122 * V_123 ;
bool V_173 ;
int error ;
F_58 ( L_22 ) ;
V_123 = F_117 () ;
if ( ! V_123 )
return F_17 ( - V_29 ) ;
V_173 = V_208 -> V_210 -> V_195 . V_196 < 1 ;
error = F_113 ( V_123 , V_208 -> V_210 ) ;
if ( error < 0 )
goto error;
error = F_104 ( V_123 , V_208 -> V_172 , V_173 ) ;
if ( error < 0 )
goto error;
F_58 ( L_23 , V_123 ) ;
return V_123 ;
error:
F_118 ( V_123 ) ;
F_58 ( L_24 , error ) ;
return F_17 ( error ) ;
}
struct V_122 * F_119 ( struct V_211 * V_132 ,
struct V_171 * V_172 )
{
struct V_1 * V_212 ;
struct V_122 * V_123 , * V_213 ;
bool V_173 ;
int error ;
F_58 ( L_25 ) ;
V_123 = F_117 () ;
if ( ! V_123 )
return F_17 ( - V_29 ) ;
V_213 = F_120 ( V_132 -> V_214 ) ;
V_212 = V_213 -> V_1 ;
F_121 ( V_123 , V_213 ) ;
error = F_97 ( V_123 , V_132 -> V_134 ,
V_132 -> V_126 ,
V_132 -> V_135 ,
V_212 -> V_90 ,
V_132 -> V_215 ,
F_122 ( V_213 -> V_33 ) ,
V_213 -> V_33 -> V_216 ,
V_212 -> V_48 -> V_53 ,
V_212 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_115 ( V_123 , V_213 -> V_33 -> V_216 , V_132 -> V_215 ) ;
if ( error < 0 )
goto error;
V_173 = V_213 -> V_195 . V_196 < 1 ;
error = F_104 ( V_123 , V_172 , V_173 ) ;
if ( error < 0 )
goto error;
F_58 ( L_26 , V_123 ) ;
return V_123 ;
error:
F_118 ( V_123 ) ;
F_58 ( L_27 , error ) ;
return F_17 ( error ) ;
}
static int F_123 ( struct V_122 * V_123 )
{
struct V_32 * V_32 = F_124 ( V_123 -> V_217 -> V_218 ) ;
struct V_174 * V_175 ;
int error ;
V_175 = F_106 () ;
if ( V_175 == NULL )
return - V_29 ;
error = F_110 ( V_123 , F_125 ( V_32 ) , V_175 ) ;
F_112 ( V_175 ) ;
return error ;
}
int F_126 ( struct V_122 * V_123 , const char * V_134 ,
struct V_88 * V_89 , T_3 V_219 , struct V_124 * V_124 )
{
struct V_1 * V_2 = V_123 -> V_1 ;
struct V_20 * V_220 = V_123 -> V_33 ;
struct V_221 V_222 = {
. V_223 = V_2 -> V_224 ,
. V_124 = V_124 ,
. V_225 = V_89 ,
. V_135 = V_219 ,
. V_226 = V_134 ,
} ;
char V_73 [ V_74 + 1 ] ;
struct V_86 V_199 ;
struct V_88 * V_227 = (struct V_88 * ) & V_199 ;
int error ;
F_58 ( L_28 , V_65 ,
( unsigned long long ) V_123 -> V_183 . V_184 ,
( unsigned long long ) V_123 -> V_183 . V_185 ,
V_134 ) ;
error = F_127 ( V_220 , & V_222 , V_220 -> V_216 ) ;
if ( error != 0 ) {
F_58 ( L_29 ,
V_65 , error ) ;
goto V_23;
}
error = F_69 ( V_220 , V_227 , sizeof( V_199 ) ) ;
if ( error != 0 ) {
F_58 ( L_30 ,
V_65 , error ) ;
goto V_23;
}
error = - V_228 ;
if ( F_70 ( V_227 , V_73 , sizeof( V_73 ) ) == 0 ) {
F_58 ( L_31 ,
V_65 , error ) ;
goto V_23;
}
F_128 ( V_123 ) ;
error = F_97 ( V_123 , V_134 , V_89 , V_219 , V_73 ,
V_2 -> V_30 -> V_21 -> V_22 ,
V_2 -> V_224 , V_220 -> V_216 ,
V_2 -> V_47 , V_124 ) ;
F_74 ( V_2 ) ;
if ( error != 0 ) {
F_111 ( V_123 ) ;
F_58 ( L_32 ,
V_65 , error ) ;
goto V_23;
}
if ( V_123 -> V_1 -> V_229 == NULL )
V_123 -> V_1 -> V_229 = F_129 ( V_134 , V_11 ) ;
F_111 ( V_123 ) ;
error = F_123 ( V_123 ) ;
if ( error < 0 )
goto V_23;
F_58 ( L_33 , V_65 ) ;
V_23:
return error ;
}
