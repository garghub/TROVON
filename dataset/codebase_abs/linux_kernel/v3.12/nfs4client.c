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
return V_2 ;
error:
F_45 ( V_2 ) ;
return F_17 ( V_31 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( F_47 ( V_50 , & V_2 -> V_51 ) )
F_48 ( V_2 -> V_48 -> V_52 , V_2 -> V_7 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( F_47 ( V_53 , & V_2 -> V_51 ) )
F_50 ( V_2 ) ;
V_2 -> V_48 -> V_54 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( F_47 ( V_55 , & V_2 -> V_51 ) )
F_51 ( V_2 ) ;
F_52 ( & V_2 -> V_44 ) ;
F_21 ( V_2 -> V_56 ) ;
F_21 ( V_2 -> V_57 ) ;
F_21 ( V_2 -> V_58 ) ;
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
struct V_59 * V_60 ;
V_60 = F_55 ( V_2 -> V_30 -> V_61 ) ;
if ( F_35 ( V_2 ) ) {
error = F_56 ( V_60 ,
V_62 ) ;
if ( error < 0 )
return error ;
}
error = F_57 ( V_2 -> V_48 -> V_52 , V_60 ) ;
if ( error < 0 ) {
F_58 ( L_2 ,
V_63 , error ) ;
return error ;
}
F_59 ( V_50 , & V_2 -> V_51 ) ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
int V_4 ;
V_65 = F_61 ( sizeof( * V_65 ) , V_28 ) ;
if ( V_65 == NULL )
return - V_29 ;
V_4 = F_62 ( V_65 , V_66 ,
L_3 ) ;
if ( V_4 ) {
F_21 ( V_65 ) ;
return V_4 ;
}
V_2 -> V_37 = V_65 ;
return 0 ;
}
int F_63 ( struct V_1 * V_2 )
{
struct V_67 * V_68 = NULL ;
V_68 = F_64 ( V_2 ) ;
if ( ! V_68 )
return - V_29 ;
V_2 -> V_36 = V_68 ;
F_65 ( V_2 , V_69 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = V_2 -> V_48 -> V_70 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return F_54 ( V_2 ) ;
}
struct V_1 * F_67 ( struct V_1 * V_2 ,
const struct V_71 * V_72 ,
const char * V_73 )
{
char V_74 [ V_75 + 1 ] ;
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
error = F_68 ( V_2 , V_72 , V_83 ) ;
if ( error == - V_41 )
error = F_68 ( V_2 , V_72 , V_84 ) ;
if ( error < 0 )
goto error;
if ( V_73 == NULL ) {
struct V_85 V_86 ;
struct V_87 * V_88 = (struct V_87 * ) & V_86 ;
error = F_69 ( V_2 -> V_30 , V_88 , sizeof( V_86 ) ) ;
if ( error < 0 )
goto error;
error = F_70 ( V_88 , V_74 , sizeof( V_74 ) ) ;
if ( error < 0 )
goto error;
V_73 = ( const char * ) V_74 ;
}
F_71 ( V_2 -> V_89 , V_73 , sizeof( V_2 -> V_89 ) ) ;
error = F_72 ( V_2 ) ;
if ( error < 0 ) {
F_58 ( L_5 ,
V_63 , error ) ;
goto error;
}
F_59 ( V_55 , & V_2 -> V_51 ) ;
error = F_66 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_35 ( V_2 ) )
F_65 ( V_2 , V_78 ) ;
error = F_73 ( V_2 , & V_76 ) ;
if ( error < 0 )
goto error;
F_74 ( V_2 ) ;
if ( V_2 != V_76 ) {
V_2 -> V_90 = true ;
V_2 = V_76 ;
}
return V_2 ;
error:
F_65 ( V_2 , error ) ;
F_74 ( V_2 ) ;
F_58 ( L_6 , error ) ;
return F_17 ( error ) ;
}
static void F_75 ( struct V_1 * V_91 ,
struct V_1 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_91 -> V_7 , V_8 ) ;
unsigned int V_93 = V_91 -> V_15 ;
if ( V_91 -> V_15 == V_92 -> V_15 )
return;
F_58 ( L_7 ,
V_63 , V_91 -> V_15 , V_92 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_76 ( & V_6 -> V_13 , V_91 , V_92 -> V_15 ) ;
V_91 -> V_15 = V_92 -> V_15 ;
F_76 ( & V_6 -> V_13 , V_92 , V_93 ) ;
V_92 -> V_15 = V_93 ;
F_6 ( & V_6 -> V_12 ) ;
}
int F_77 ( struct V_1 * V_24 ,
struct V_1 * * V_94 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_97 , * V_98 = NULL ;
struct V_99 V_100 = {
. V_101 = V_24 -> V_102 ,
. V_103 = V_24 -> V_104 ,
} ;
int V_105 = - V_106 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_97 -> V_77 > V_78 ) {
F_78 ( & V_97 -> V_107 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_98 )
F_74 ( V_98 ) ;
V_98 = V_97 ;
V_105 = F_79 ( V_97 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_105 < 0 )
continue;
}
if ( V_97 -> V_77 != V_78 )
continue;
if ( V_97 -> V_9 != V_24 -> V_9 )
continue;
if ( V_97 -> V_108 != V_24 -> V_108 )
continue;
if ( V_97 -> V_47 != V_24 -> V_47 )
continue;
if ( V_97 -> V_102 != V_24 -> V_102 )
continue;
F_78 ( & V_97 -> V_107 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_98 )
F_74 ( V_98 ) ;
V_98 = V_97 ;
V_105 = F_80 ( V_97 , & V_100 , V_96 ) ;
switch ( V_105 ) {
case - V_106 :
break;
case 0 :
F_75 ( V_97 , V_24 ) ;
V_98 = NULL ;
* V_94 = V_97 ;
F_58 ( L_8 ,
V_63 , V_97 , F_81 ( & V_97 -> V_107 ) ) ;
default:
goto V_23;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_23:
if ( V_98 )
F_74 ( V_98 ) ;
F_58 ( L_9 , V_63 , V_105 ) ;
return V_105 ;
}
static bool F_82 ( struct V_1 * V_109 , struct V_1 * V_110 )
{
if ( V_109 -> V_102 != V_110 -> V_102 ) {
F_58 ( L_10 ,
V_63 , V_109 -> V_102 , V_110 -> V_102 ) ;
return false ;
}
F_58 ( L_11 ,
V_63 , V_109 -> V_102 , V_110 -> V_102 ) ;
return true ;
}
static bool
F_83 ( struct V_1 * V_109 , struct V_1 * V_110 )
{
struct V_111 * V_112 = V_109 -> V_56 ;
struct V_111 * V_113 = V_110 -> V_56 ;
if ( V_112 -> V_114 != V_113 -> V_114 ) {
F_58 ( L_12 ,
V_63 ) ;
return false ;
}
if ( V_112 -> V_115 != V_113 -> V_115 )
goto V_116;
if ( memcmp ( V_112 -> V_117 , V_113 -> V_117 , V_112 -> V_115 ) != 0 )
goto V_116;
F_58 ( L_13 , V_63 ) ;
return true ;
V_116:
F_58 ( L_14 ,
V_63 ) ;
return false ;
}
int F_84 ( struct V_1 * V_24 ,
struct V_1 * * V_94 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_97 , * V_98 = NULL ;
int V_105 = - V_106 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_97 -> V_77 > V_78 ) {
F_78 ( & V_97 -> V_107 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_98 )
F_74 ( V_98 ) ;
V_98 = V_97 ;
V_105 = F_79 ( V_97 ) ;
if ( V_105 == 0 ) {
F_85 ( V_97 ) ;
V_105 = F_86 ( V_97 ) ;
}
F_4 ( & V_6 -> V_12 ) ;
if ( V_105 < 0 )
continue;
}
if ( V_97 -> V_77 != V_78 )
continue;
if ( V_97 -> V_9 != V_24 -> V_9 )
continue;
if ( V_97 -> V_108 != V_24 -> V_108 )
continue;
if ( V_97 -> V_47 != V_24 -> V_47 )
continue;
if ( ! F_82 ( V_97 , V_24 ) )
continue;
if ( ! F_83 ( V_97 , V_24 ) )
continue;
F_78 ( & V_97 -> V_107 ) ;
* V_94 = V_97 ;
V_105 = 0 ;
F_58 ( L_8 ,
V_63 , V_97 , F_81 ( & V_97 -> V_107 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_58 ( L_9 , V_63 , V_105 ) ;
if ( V_98 )
F_74 ( V_98 ) ;
return V_105 ;
}
static void F_87 ( struct V_118 * V_119 )
{
F_88 ( V_119 ) ;
F_89 ( V_119 ) ;
F_90 ( V_119 ) ;
}
struct V_1 *
F_91 ( struct V_120 * V_120 , int V_121 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_120 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_92 ( & V_6 -> V_13 , V_121 ) ;
if ( V_2 )
F_78 ( & V_2 -> V_107 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_93 ( const struct V_87 * V_122 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_87 * V_123 = (struct V_87 * ) & V_2 -> V_124 ;
if ( ! ( V_2 -> V_77 == V_78 ||
V_2 -> V_77 == V_69 ) )
return false ;
F_94 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
if ( ! F_95 ( V_122 , V_123 ) )
return false ;
return true ;
}
struct V_1 *
F_96 ( struct V_120 * V_120 , const struct V_87 * V_122 ,
struct V_125 * V_126 , T_2 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_120 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_93 ( V_122 , V_2 , V_3 ) == false )
continue;
if ( ! F_35 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_36 -> V_127 . V_128 ,
V_126 -> V_128 , V_129 ) != 0 )
continue;
F_78 ( & V_2 -> V_107 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_96 ( struct V_120 * V_120 , const struct V_87 * V_122 ,
struct V_125 * V_126 , T_2 V_3 )
{
return NULL ;
}
static int F_97 ( struct V_118 * V_119 ,
const char * V_130 ,
const struct V_87 * V_122 ,
const T_3 V_131 ,
const char * V_73 ,
T_1 V_132 ,
int V_133 , const struct V_71 * V_72 ,
T_2 V_3 , struct V_120 * V_120 )
{
struct V_38 V_39 = {
. V_130 = V_130 ,
. V_122 = V_122 ,
. V_131 = V_131 ,
. V_134 = & V_135 ,
. V_133 = V_133 ,
. V_3 = V_3 ,
. V_120 = V_120 ,
} ;
struct V_1 * V_2 ;
int error ;
F_58 ( L_15 ) ;
if ( V_119 -> V_136 & V_137 )
F_98 ( V_138 , & V_39 . V_139 ) ;
if ( V_119 -> V_140 & V_141 )
F_98 ( V_142 , & V_39 . V_139 ) ;
V_2 = F_99 ( & V_39 , V_72 , V_73 , V_132 ) ;
if ( F_19 ( V_2 ) ) {
error = F_20 ( V_2 ) ;
goto error;
}
F_98 ( V_143 , & V_2 -> V_51 ) ;
V_119 -> V_1 = V_2 ;
F_58 ( L_16 , V_2 ) ;
return 0 ;
error:
F_58 ( L_17 , error ) ;
return error ;
}
struct V_1 * F_100 ( struct V_1 * V_144 ,
const struct V_87 * V_145 , int V_146 ,
int V_147 , unsigned int V_148 , unsigned int V_149 )
{
struct V_38 V_39 = {
. V_122 = V_145 ,
. V_131 = V_146 ,
. V_134 = & V_135 ,
. V_133 = V_147 ,
. V_3 = V_144 -> V_47 ,
. V_120 = V_144 -> V_7 ,
} ;
struct V_71 V_150 ;
struct V_1 * V_2 ;
F_101 ( & V_150 , V_147 , V_148 , V_149 ) ;
V_2 = F_99 ( & V_39 , & V_150 , V_144 -> V_89 ,
V_144 -> V_30 -> V_21 -> V_22 ) ;
F_58 ( L_18 , V_63 , V_2 ) ;
return V_2 ;
}
static void F_102 ( struct V_118 * V_119 )
{
#ifdef F_103
struct V_67 * V_151 ;
T_2 V_152 ;
T_2 V_153 ;
if ( ! F_35 ( V_119 -> V_1 ) )
return;
V_151 = V_119 -> V_1 -> V_36 ;
V_152 = V_151 -> V_154 . V_155 - V_156 ;
V_153 = V_151 -> V_154 . V_157 - V_158 ;
if ( V_119 -> V_159 > V_152 )
V_119 -> V_159 = V_152 ;
if ( V_119 -> V_160 > V_153 )
V_119 -> V_160 = V_153 ;
#endif
}
static int F_104 ( struct V_118 * V_119 ,
struct V_161 * V_162 , bool V_163 )
{
struct V_164 * V_165 ;
int error ;
if ( F_105 ( V_119 -> V_1 ) )
return - V_166 ;
V_165 = F_106 () ;
if ( V_165 == NULL )
return - V_29 ;
error = F_107 ( V_119 -> V_1 ) ;
if ( error < 0 )
goto V_23;
V_119 -> V_167 |= V_119 -> V_1 -> V_48 -> V_168 ;
if ( V_119 -> V_136 & V_169 )
V_119 -> V_167 &= ~ V_170 ;
if ( V_171 &&
V_119 -> V_33 -> V_21 -> V_22 == V_84 )
V_119 -> V_167 |= V_172 ;
error = F_108 ( V_119 , V_162 , V_163 ) ;
if ( error < 0 )
goto V_23;
F_58 ( L_19 ,
( unsigned long long ) V_119 -> V_173 . V_174 ,
( unsigned long long ) V_119 -> V_173 . V_175 ) ;
F_58 ( L_20 , V_162 -> V_176 ) ;
F_102 ( V_119 ) ;
error = F_109 ( V_119 , V_162 , V_165 ) ;
if ( error < 0 )
goto V_23;
if ( V_119 -> V_177 == 0 || V_119 -> V_177 > V_178 )
V_119 -> V_177 = V_178 ;
F_110 ( V_119 ) ;
V_119 -> V_179 = V_180 ;
V_119 -> V_181 = F_87 ;
V_23:
F_111 ( V_165 ) ;
return error ;
}
static int F_112 ( struct V_118 * V_119 ,
const struct V_182 * V_128 )
{
T_1 V_183 = V_84 ;
struct V_71 V_72 ;
int error ;
F_58 ( L_21 ) ;
F_101 ( & V_72 , V_128 -> V_118 . V_184 ,
V_128 -> V_185 , V_128 -> V_186 ) ;
V_119 -> V_136 = V_128 -> V_136 ;
V_119 -> V_140 = V_128 -> V_140 ;
if ( V_128 -> V_187 >= 1 )
V_183 = V_128 -> V_188 [ 0 ] ;
error = F_97 ( V_119 ,
V_128 -> V_118 . V_130 ,
( const struct V_87 * ) & V_128 -> V_118 . V_189 ,
V_128 -> V_118 . V_131 ,
V_128 -> V_190 ,
V_183 ,
V_128 -> V_118 . V_184 ,
& V_72 ,
V_128 -> V_3 ,
V_128 -> V_120 ) ;
if ( error < 0 )
goto error;
if ( V_128 -> V_159 )
V_119 -> V_159 = F_113 ( V_128 -> V_159 , NULL ) ;
if ( V_128 -> V_160 )
V_119 -> V_160 = F_113 ( V_128 -> V_160 , NULL ) ;
V_119 -> V_191 = V_128 -> V_191 * V_192 ;
V_119 -> V_193 = V_128 -> V_193 * V_192 ;
V_119 -> V_194 = V_128 -> V_194 * V_192 ;
V_119 -> V_195 = V_128 -> V_195 * V_192 ;
V_119 -> V_196 = V_128 -> V_118 . V_196 ;
error = F_114 ( V_119 , & V_72 , V_183 ) ;
error:
F_58 ( L_22 , error ) ;
return error ;
}
struct V_118 * F_115 ( struct V_197 * V_198 ,
struct V_199 * V_134 )
{
struct V_118 * V_119 ;
bool V_163 ;
int error ;
F_58 ( L_23 ) ;
V_119 = F_116 () ;
if ( ! V_119 )
return F_17 ( - V_29 ) ;
V_163 = V_198 -> V_200 -> V_187 < 1 ;
error = F_112 ( V_119 , V_198 -> V_200 ) ;
if ( error < 0 )
goto error;
error = F_104 ( V_119 , V_198 -> V_162 , V_163 ) ;
if ( error < 0 )
goto error;
F_58 ( L_24 , V_119 ) ;
return V_119 ;
error:
F_117 ( V_119 ) ;
F_58 ( L_25 , error ) ;
return F_17 ( error ) ;
}
struct V_118 * F_118 ( struct V_201 * V_128 ,
struct V_161 * V_162 )
{
struct V_1 * V_202 ;
struct V_118 * V_119 , * V_203 ;
int error ;
F_58 ( L_26 ) ;
V_119 = F_116 () ;
if ( ! V_119 )
return F_17 ( - V_29 ) ;
V_203 = F_119 ( V_128 -> V_204 ) ;
V_202 = V_203 -> V_1 ;
F_120 ( V_119 , V_203 ) ;
error = F_97 ( V_119 , V_128 -> V_130 ,
V_128 -> V_122 ,
V_128 -> V_131 ,
V_202 -> V_89 ,
V_128 -> V_205 ,
F_121 ( V_203 -> V_33 ) ,
V_203 -> V_33 -> V_206 ,
V_202 -> V_48 -> V_52 ,
V_202 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_114 ( V_119 , V_203 -> V_33 -> V_206 , V_128 -> V_205 ) ;
if ( error < 0 )
goto error;
error = F_104 ( V_119 , V_162 ,
! ( V_203 -> V_136 & V_207 ) ) ;
if ( error < 0 )
goto error;
F_58 ( L_27 , V_119 ) ;
return V_119 ;
error:
F_117 ( V_119 ) ;
F_58 ( L_28 , error ) ;
return F_17 ( error ) ;
}
