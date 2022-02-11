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
if ( V_2 -> V_79 == V_80 ) {
F_60 ( L_4 , V_2 ) ;
return V_2 ;
}
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
F_60 ( L_5 ,
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
F_60 ( L_6 , error ) ;
return F_17 ( error ) ;
}
static void F_77 ( struct V_1 * V_94 ,
struct V_1 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_94 -> V_7 , V_8 ) ;
unsigned int V_96 = V_94 -> V_15 ;
if ( V_94 -> V_15 == V_95 -> V_15 )
return;
F_60 ( L_7 ,
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
int F_80 ( struct V_1 * V_24 ,
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
F_81 ( & V_102 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_103 ) ;
V_103 = V_102 ;
V_110 = F_82 ( V_102 ) ;
if ( V_110 < 0 )
goto V_23;
V_110 = - V_111 ;
F_4 ( & V_6 -> V_12 ) ;
}
if ( V_102 -> V_79 != V_80 )
continue;
if ( V_102 -> V_107 != V_24 -> V_107 )
continue;
if ( ! F_79 ( V_102 , V_24 ) )
continue;
F_81 ( & V_102 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_103 ) ;
V_103 = V_102 ;
V_110 = F_83 ( V_102 , & V_105 , V_101 ) ;
switch ( V_110 ) {
case - V_111 :
break;
case 0 :
F_77 ( V_102 , V_24 ) ;
V_103 = NULL ;
* V_99 = V_102 ;
F_60 ( L_8 ,
V_67 , V_102 , F_84 ( & V_102 -> V_112 ) ) ;
goto V_23;
case - V_113 :
case - V_114 :
F_85 ( V_102 ) ;
default:
goto V_23;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_23:
F_76 ( V_103 ) ;
F_60 ( L_9 , V_67 , V_110 ) ;
return V_110 ;
}
static bool F_86 ( T_2 V_115 , T_2 V_116 )
{
if ( V_115 != V_116 ) {
F_60 ( L_10 ,
V_67 , V_115 , V_116 ) ;
return false ;
}
F_60 ( L_11 ,
V_67 , V_115 , V_116 ) ;
return true ;
}
static bool
F_87 ( struct V_117 * V_118 ,
struct V_117 * V_119 )
{
if ( V_118 -> V_120 != V_119 -> V_120 )
goto V_121;
if ( memcmp ( V_118 -> V_122 , V_119 -> V_122 , V_118 -> V_120 ) != 0 )
goto V_121;
F_60 ( L_12 , V_67 ) ;
return true ;
V_121:
F_60 ( L_13 ,
V_67 ) ;
return false ;
}
static bool
F_88 ( struct V_117 * V_118 ,
struct V_117 * V_119 )
{
if ( V_118 -> V_123 != V_119 -> V_123 )
goto V_124;
F_60 ( L_14 , V_67 ) ;
return true ;
V_124:
F_60 ( L_15 , V_67 ) ;
return false ;
}
static bool
F_89 ( struct V_125 * V_126 ,
struct V_125 * V_127 )
{
if ( V_126 -> V_128 != V_127 -> V_128 )
goto V_129;
if ( memcmp ( V_126 -> V_130 , V_127 -> V_130 ,
V_126 -> V_128 ) != 0 )
goto V_129;
F_60 ( L_16 , V_67 ) ;
return true ;
V_129:
F_60 ( L_17 ,
V_67 ) ;
return false ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_131 * V_132 ,
struct V_63 * V_64 )
{
if ( ! F_86 ( V_2 -> V_107 , V_132 -> V_106 ) )
goto V_133;
if ( ! F_87 ( V_2 -> V_59 ,
V_132 -> V_134 ) )
goto V_133;
if ( ! F_88 ( V_2 -> V_59 ,
V_132 -> V_134 ) )
goto V_133;
if ( ! F_89 ( V_2 -> V_60 , V_132 -> V_130 ) )
goto V_133;
F_91 ( V_2 -> V_30 , V_64 ) ;
F_92 ( L_18 ,
V_2 -> V_135 ,
V_64 -> V_136 [ V_137 ] ) ;
return 0 ;
V_133:
F_92 ( L_19 , V_2 -> V_135 ,
V_64 -> V_136 [ V_137 ] ) ;
return - V_41 ;
}
int F_93 ( struct V_1 * V_24 ,
struct V_1 * * V_99 ,
struct V_100 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_102 , * V_103 = NULL ;
int V_110 = - V_111 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_102 == V_24 )
goto V_138;
if ( V_102 -> V_9 != V_24 -> V_9 )
continue;
if ( V_102 -> V_47 != V_24 -> V_47 )
continue;
if ( V_102 -> V_79 > V_80 ) {
F_81 ( & V_102 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_103 ) ;
V_103 = V_102 ;
V_110 = F_82 ( V_102 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_110 < 0 )
break;
V_110 = - V_111 ;
}
if ( V_102 -> V_79 != V_80 )
continue;
if ( ! F_86 ( V_102 -> V_107 , V_24 -> V_107 ) )
continue;
if ( ! F_87 ( V_102 -> V_59 ,
V_24 -> V_59 ) )
continue;
if ( ! F_79 ( V_102 , V_24 ) )
continue;
V_138:
F_81 ( & V_102 -> V_112 ) ;
* V_99 = V_102 ;
V_110 = 0 ;
F_60 ( L_8 ,
V_67 , V_102 , F_84 ( & V_102 -> V_112 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_60 ( L_9 , V_67 , V_110 ) ;
F_76 ( V_103 ) ;
return V_110 ;
}
static void F_94 ( struct V_139 * V_140 )
{
F_95 ( V_140 ) ;
F_96 ( V_140 ) ;
F_97 ( V_140 ) ;
}
struct V_1 *
F_98 ( struct V_141 * V_141 , int V_142 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_141 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_99 ( & V_6 -> V_13 , V_142 ) ;
if ( V_2 )
F_81 ( & V_2 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_100 ( const struct V_90 * V_143 ,
struct V_1 * V_2 , T_3 V_3 )
{
struct V_90 * V_144 = (struct V_90 * ) & V_2 -> V_145 ;
if ( ! ( V_2 -> V_79 == V_80 ||
V_2 -> V_79 == V_73 ) )
return false ;
F_101 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
return F_102 ( V_143 , V_144 ) ;
}
struct V_1 *
F_103 ( struct V_141 * V_141 , const struct V_90 * V_143 ,
struct V_146 * V_147 , T_3 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_141 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_100 ( V_143 , V_2 , V_3 ) == false )
continue;
if ( ! F_35 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_36 -> V_148 . V_149 ,
V_147 -> V_149 , V_150 ) != 0 )
continue;
F_81 ( & V_2 -> V_112 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_103 ( struct V_141 * V_141 , const struct V_90 * V_143 ,
struct V_146 * V_147 , T_3 V_3 )
{
return NULL ;
}
static int F_104 ( struct V_139 * V_140 ,
const char * V_151 ,
const struct V_90 * V_143 ,
const T_4 V_152 ,
const char * V_77 ,
T_1 V_153 ,
int V_154 , const struct V_155 * V_156 ,
T_3 V_3 , struct V_141 * V_141 )
{
struct V_38 V_39 = {
. V_151 = V_151 ,
. V_143 = V_143 ,
. V_152 = V_152 ,
. V_77 = V_77 ,
. V_157 = & V_158 ,
. V_154 = V_154 ,
. V_3 = V_3 ,
. V_141 = V_141 ,
. V_156 = V_156 ,
} ;
struct V_1 * V_2 ;
int error ;
F_60 ( L_20 ) ;
if ( V_140 -> V_159 & V_160 )
F_105 ( V_161 , & V_39 . V_162 ) ;
if ( V_140 -> V_163 & V_164 )
F_105 ( V_165 , & V_39 . V_162 ) ;
V_2 = F_106 ( & V_39 , V_153 ) ;
if ( F_19 ( V_2 ) ) {
error = F_20 ( V_2 ) ;
goto error;
}
if ( V_140 -> V_1 == V_2 ) {
error = - V_166 ;
goto error;
}
F_105 ( V_167 , & V_2 -> V_54 ) ;
V_140 -> V_1 = V_2 ;
F_60 ( L_21 , V_2 ) ;
return 0 ;
error:
F_60 ( L_22 , error ) ;
return error ;
}
struct V_1 * F_107 ( struct V_139 * V_168 ,
const struct V_90 * V_169 , int V_170 ,
int V_171 , unsigned int V_172 , unsigned int V_173 ,
T_3 V_55 , T_1 V_22 )
{
struct V_155 V_174 ;
struct V_1 * V_175 = V_168 -> V_1 ;
struct V_38 V_39 = {
. V_143 = V_169 ,
. V_152 = V_170 ,
. V_176 = V_175 -> V_30 -> V_177 ,
. V_77 = V_175 -> V_92 ,
. V_157 = & V_158 ,
. V_154 = V_171 ,
. V_3 = V_55 ,
. V_141 = V_175 -> V_7 ,
. V_156 = & V_174 ,
} ;
struct V_1 * V_2 ;
char V_75 [ V_76 + 1 ] ;
if ( F_72 ( V_169 , V_75 , sizeof( V_75 ) ) <= 0 )
return F_17 ( - V_41 ) ;
V_39 . V_151 = V_75 ;
if ( V_168 -> V_159 & V_160 )
F_61 ( V_161 , & V_39 . V_162 ) ;
F_108 ( & V_174 , V_171 , V_172 , V_173 ) ;
V_2 = F_106 ( & V_39 , V_22 ) ;
F_60 ( L_23 , V_67 , V_2 ) ;
return V_2 ;
}
static void F_109 ( struct V_139 * V_140 )
{
#ifdef V_51
struct V_71 * V_178 ;
T_3 V_179 ;
T_3 V_180 ;
if ( ! F_35 ( V_140 -> V_1 ) )
return;
V_178 = V_140 -> V_1 -> V_36 ;
V_179 = V_178 -> V_181 . V_182 - V_183 ;
V_180 = V_178 -> V_181 . V_184 - V_185 ;
if ( V_140 -> V_186 > V_179 )
V_140 -> V_186 = V_179 ;
if ( V_140 -> V_187 > V_180 )
V_140 -> V_187 = V_180 ;
#endif
}
static int F_110 ( struct V_139 * V_140 ,
struct V_188 * V_189 , bool V_190 )
{
struct V_191 * V_192 ;
int error ;
if ( F_111 ( V_140 -> V_1 ) )
return - V_193 ;
V_192 = F_112 () ;
if ( V_192 == NULL )
return - V_29 ;
error = F_113 ( V_140 -> V_1 ) ;
if ( error < 0 )
goto V_23;
V_140 -> V_194 |= V_140 -> V_1 -> V_48 -> V_195 ;
if ( V_140 -> V_159 & V_196 )
V_140 -> V_194 &= ~ V_197 ;
if ( V_198 &&
V_140 -> V_33 -> V_21 -> V_22 == V_87 )
V_140 -> V_194 |= V_199 ;
error = F_114 ( V_140 , V_189 , V_190 ) ;
if ( error < 0 )
goto V_23;
F_60 ( L_24 ,
( unsigned long long ) V_140 -> V_200 . V_201 ,
( unsigned long long ) V_140 -> V_200 . V_202 ) ;
F_115 ( V_189 , L_25 ) ;
F_109 ( V_140 ) ;
error = F_116 ( V_140 , V_189 , V_192 ) ;
if ( error < 0 )
goto V_23;
if ( V_140 -> V_203 == 0 || V_140 -> V_203 > V_204 )
V_140 -> V_203 = V_204 ;
F_117 ( V_140 ) ;
V_140 -> V_205 = V_206 ;
V_140 -> V_207 = F_94 ;
V_23:
F_118 ( V_192 ) ;
return error ;
}
static int F_119 ( struct V_139 * V_140 ,
struct V_208 * V_149 )
{
struct V_155 V_156 ;
int error ;
F_60 ( L_26 ) ;
F_108 ( & V_156 , V_149 -> V_139 . V_209 ,
V_149 -> V_210 , V_149 -> V_211 ) ;
V_140 -> V_159 = V_149 -> V_159 ;
V_140 -> V_163 = V_149 -> V_163 ;
V_140 -> V_212 = V_149 -> V_212 ;
if ( V_149 -> V_212 . V_213 >= 1 )
V_149 -> V_214 = V_149 -> V_212 . V_215 [ 0 ] ;
else
V_149 -> V_214 = V_87 ;
error = F_104 ( V_140 ,
V_149 -> V_139 . V_151 ,
( const struct V_90 * ) & V_149 -> V_139 . V_216 ,
V_149 -> V_139 . V_152 ,
V_149 -> V_217 ,
V_149 -> V_214 ,
V_149 -> V_139 . V_209 ,
& V_156 ,
V_149 -> V_3 ,
V_149 -> V_141 ) ;
if ( error < 0 )
goto error;
if ( V_149 -> V_186 )
V_140 -> V_186 = F_120 ( V_149 -> V_186 , NULL ) ;
if ( V_149 -> V_187 )
V_140 -> V_187 = F_120 ( V_149 -> V_187 , NULL ) ;
V_140 -> V_218 = V_149 -> V_218 * V_219 ;
V_140 -> V_220 = V_149 -> V_220 * V_219 ;
V_140 -> V_221 = V_149 -> V_221 * V_219 ;
V_140 -> V_222 = V_149 -> V_222 * V_219 ;
V_140 -> V_223 = V_149 -> V_139 . V_223 ;
error = F_121 ( V_140 , & V_156 ,
V_149 -> V_214 ) ;
error:
F_60 ( L_27 , error ) ;
return error ;
}
struct V_139 * F_122 ( struct V_224 * V_225 ,
struct V_226 * V_157 )
{
struct V_139 * V_140 ;
bool V_190 ;
int error ;
F_60 ( L_28 ) ;
V_140 = F_123 () ;
if ( ! V_140 )
return F_17 ( - V_29 ) ;
V_190 = V_225 -> V_227 -> V_212 . V_213 < 1 ;
error = F_119 ( V_140 , V_225 -> V_227 ) ;
if ( error < 0 )
goto error;
error = F_110 ( V_140 , V_225 -> V_189 , V_190 ) ;
if ( error < 0 )
goto error;
F_60 ( L_29 , V_140 ) ;
return V_140 ;
error:
F_124 ( V_140 ) ;
F_60 ( L_30 , error ) ;
return F_17 ( error ) ;
}
struct V_139 * F_125 ( struct V_228 * V_149 ,
struct V_188 * V_189 )
{
struct V_1 * V_229 ;
struct V_139 * V_140 , * V_230 ;
bool V_190 ;
int error ;
F_60 ( L_31 ) ;
V_140 = F_123 () ;
if ( ! V_140 )
return F_17 ( - V_29 ) ;
V_230 = F_126 ( V_149 -> V_231 ) ;
V_229 = V_230 -> V_1 ;
F_127 ( V_140 , V_230 ) ;
error = F_104 ( V_140 , V_149 -> V_151 ,
V_149 -> V_143 ,
V_149 -> V_152 ,
V_229 -> V_92 ,
V_149 -> V_232 ,
F_128 ( V_230 -> V_33 ) ,
V_230 -> V_33 -> V_233 ,
V_229 -> V_48 -> V_55 ,
V_229 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_121 ( V_140 , V_230 -> V_33 -> V_233 , V_149 -> V_232 ) ;
if ( error < 0 )
goto error;
V_190 = V_230 -> V_212 . V_213 < 1 ;
error = F_110 ( V_140 , V_189 , V_190 ) ;
if ( error < 0 )
goto error;
F_60 ( L_32 , V_140 ) ;
return V_140 ;
error:
F_124 ( V_140 ) ;
F_60 ( L_33 , error ) ;
return F_17 ( error ) ;
}
static int F_129 ( struct V_139 * V_140 )
{
struct V_32 * V_32 = F_130 ( V_140 -> V_234 -> V_235 ) ;
struct V_191 * V_192 ;
int error ;
V_192 = F_112 () ;
if ( V_192 == NULL )
return - V_29 ;
error = F_116 ( V_140 , F_131 ( V_32 ) , V_192 ) ;
F_118 ( V_192 ) ;
return error ;
}
int F_132 ( struct V_139 * V_140 , const char * V_151 ,
struct V_90 * V_91 , T_4 V_236 , struct V_141 * V_141 )
{
struct V_1 * V_2 = V_140 -> V_1 ;
struct V_20 * V_237 = V_140 -> V_33 ;
struct V_238 V_239 = {
. V_240 = V_2 -> V_241 ,
. V_141 = V_141 ,
. V_242 = V_91 ,
. V_152 = V_236 ,
. V_243 = V_151 ,
} ;
char V_75 [ V_76 + 1 ] ;
struct V_88 V_216 ;
struct V_90 * V_244 = (struct V_90 * ) & V_216 ;
int error ;
F_60 ( L_34 , V_67 ,
( unsigned long long ) V_140 -> V_200 . V_201 ,
( unsigned long long ) V_140 -> V_200 . V_202 ,
V_151 ) ;
error = F_133 ( V_237 , & V_239 , V_237 -> V_233 ) ;
if ( error != 0 ) {
F_60 ( L_35 ,
V_67 , error ) ;
goto V_23;
}
error = F_71 ( V_237 , V_244 , sizeof( V_216 ) ) ;
if ( error != 0 ) {
F_60 ( L_36 ,
V_67 , error ) ;
goto V_23;
}
error = - V_245 ;
if ( F_72 ( V_244 , V_75 , sizeof( V_75 ) ) == 0 ) {
F_60 ( L_37 ,
V_67 , error ) ;
goto V_23;
}
F_134 ( V_140 ) ;
error = F_104 ( V_140 , V_151 , V_91 , V_236 , V_75 ,
V_2 -> V_30 -> V_21 -> V_22 ,
V_2 -> V_241 , V_237 -> V_233 ,
V_2 -> V_47 , V_141 ) ;
F_76 ( V_2 ) ;
if ( error != 0 ) {
F_117 ( V_140 ) ;
F_60 ( L_38 ,
V_67 , error ) ;
goto V_23;
}
if ( V_140 -> V_1 -> V_135 == NULL )
V_140 -> V_1 -> V_135 = F_135 ( V_151 , V_11 ) ;
F_117 ( V_140 ) ;
error = F_129 ( V_140 ) ;
if ( error < 0 )
goto V_23;
F_60 ( L_39 , V_67 ) ;
V_23:
return error ;
}
