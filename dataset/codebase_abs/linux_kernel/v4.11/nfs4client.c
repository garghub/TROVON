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
static bool F_80 ( T_2 * V_99 , T_2 * V_100 )
{
return memcmp ( V_99 -> V_101 , V_100 -> V_101 , sizeof( V_99 -> V_101 ) ) == 0 ;
}
int F_81 ( struct V_1 * V_24 ,
struct V_1 * * V_102 ,
struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_105 , * V_106 = NULL ;
struct V_107 V_108 = {
. V_109 = V_24 -> V_110 ,
. V_111 = V_24 -> V_112 ,
} ;
int V_113 = - V_114 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_105 -> V_9 != V_24 -> V_9 )
continue;
if ( V_105 -> V_47 != V_24 -> V_47 )
continue;
if ( V_105 -> V_79 > V_80 ) {
F_82 ( & V_105 -> V_115 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_106 ) ;
V_106 = V_105 ;
V_113 = F_83 ( V_105 ) ;
if ( V_113 < 0 )
goto V_23;
V_113 = - V_114 ;
F_4 ( & V_6 -> V_12 ) ;
}
if ( V_105 -> V_79 != V_80 )
continue;
if ( V_105 -> V_110 != V_24 -> V_110 )
continue;
if ( ! F_79 ( V_105 , V_24 ) )
continue;
if ( ( V_24 != V_105 ) && F_80 ( & V_105 -> V_112 ,
& V_24 -> V_112 ) )
continue;
F_82 ( & V_105 -> V_115 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_106 ) ;
V_106 = V_105 ;
V_113 = F_84 ( V_105 , & V_108 , V_104 ) ;
switch ( V_113 ) {
case - V_114 :
break;
case 0 :
F_77 ( V_105 , V_24 ) ;
V_105 -> V_112 = V_24 -> V_112 ;
V_106 = NULL ;
* V_102 = V_105 ;
F_60 ( L_8 ,
V_67 , V_105 , F_85 ( & V_105 -> V_115 ) ) ;
goto V_23;
case - V_116 :
case - V_117 :
F_86 ( V_105 ) ;
default:
goto V_23;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_23:
F_76 ( V_106 ) ;
F_60 ( L_9 , V_67 , V_113 ) ;
return V_113 ;
}
static bool F_87 ( T_3 V_118 , T_3 V_119 )
{
if ( V_118 != V_119 ) {
F_60 ( L_10 ,
V_67 , V_118 , V_119 ) ;
return false ;
}
F_60 ( L_11 ,
V_67 , V_118 , V_119 ) ;
return true ;
}
static bool
F_88 ( struct V_120 * V_121 ,
struct V_120 * V_122 )
{
if ( V_121 -> V_123 != V_122 -> V_123 )
goto V_124;
if ( memcmp ( V_121 -> V_125 , V_122 -> V_125 , V_121 -> V_123 ) != 0 )
goto V_124;
F_60 ( L_12 , V_67 ) ;
return true ;
V_124:
F_60 ( L_13 ,
V_67 ) ;
return false ;
}
static bool
F_89 ( struct V_120 * V_121 ,
struct V_120 * V_122 )
{
if ( V_121 -> V_126 != V_122 -> V_126 )
goto V_127;
F_60 ( L_14 , V_67 ) ;
return true ;
V_127:
F_60 ( L_15 , V_67 ) ;
return false ;
}
static bool
F_90 ( struct V_128 * V_129 ,
struct V_128 * V_130 )
{
if ( V_129 -> V_131 != V_130 -> V_131 )
goto V_132;
if ( memcmp ( V_129 -> V_133 , V_130 -> V_133 ,
V_129 -> V_131 ) != 0 )
goto V_132;
F_60 ( L_16 , V_67 ) ;
return true ;
V_132:
F_60 ( L_17 ,
V_67 ) ;
return false ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_134 * V_135 ,
struct V_63 * V_64 )
{
if ( ! F_87 ( V_2 -> V_110 , V_135 -> V_109 ) )
goto V_136;
if ( ! F_88 ( V_2 -> V_59 ,
V_135 -> V_137 ) )
goto V_136;
if ( ! F_89 ( V_2 -> V_59 ,
V_135 -> V_137 ) )
goto V_136;
if ( ! F_90 ( V_2 -> V_60 , V_135 -> V_133 ) )
goto V_136;
F_92 ( V_2 -> V_30 , V_64 ) ;
F_93 ( L_18 ,
V_2 -> V_138 ,
V_64 -> V_139 [ V_140 ] ) ;
return 0 ;
V_136:
F_93 ( L_19 , V_2 -> V_138 ,
V_64 -> V_139 [ V_140 ] ) ;
return - V_41 ;
}
int F_94 ( struct V_1 * V_24 ,
struct V_1 * * V_102 ,
struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_24 -> V_7 , V_8 ) ;
struct V_1 * V_105 , * V_106 = NULL ;
int V_113 = - V_114 ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_105 == V_24 )
goto V_141;
if ( V_105 -> V_9 != V_24 -> V_9 )
continue;
if ( V_105 -> V_47 != V_24 -> V_47 )
continue;
if ( V_105 -> V_79 > V_80 ) {
F_82 ( & V_105 -> V_115 ) ;
F_6 ( & V_6 -> V_12 ) ;
F_76 ( V_106 ) ;
V_106 = V_105 ;
V_113 = F_83 ( V_105 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_113 < 0 )
break;
V_113 = - V_114 ;
}
if ( V_105 -> V_79 != V_80 )
continue;
if ( ! F_87 ( V_105 -> V_110 , V_24 -> V_110 ) )
continue;
if ( ! F_88 ( V_105 -> V_59 ,
V_24 -> V_59 ) )
continue;
if ( ! F_79 ( V_105 , V_24 ) )
continue;
V_141:
F_82 ( & V_105 -> V_115 ) ;
* V_102 = V_105 ;
V_113 = 0 ;
F_60 ( L_8 ,
V_67 , V_105 , F_85 ( & V_105 -> V_115 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_60 ( L_9 , V_67 , V_113 ) ;
F_76 ( V_106 ) ;
return V_113 ;
}
static void F_95 ( struct V_142 * V_143 )
{
F_96 ( V_143 ) ;
F_97 ( V_143 ) ;
F_98 ( V_143 ) ;
}
struct V_1 *
F_99 ( struct V_144 * V_144 , int V_145 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_144 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_100 ( & V_6 -> V_13 , V_145 ) ;
if ( V_2 )
F_82 ( & V_2 -> V_115 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_101 ( const struct V_90 * V_146 ,
struct V_1 * V_2 , T_4 V_3 )
{
struct V_90 * V_147 = (struct V_90 * ) & V_2 -> V_148 ;
if ( ! ( V_2 -> V_79 == V_80 ||
V_2 -> V_79 == V_73 ) )
return false ;
F_102 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_47 != V_3 )
return false ;
return F_103 ( V_146 , V_147 ) ;
}
struct V_1 *
F_104 ( struct V_144 * V_144 , const struct V_90 * V_146 ,
struct V_149 * V_150 , T_4 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_144 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_13 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_101 ( V_146 , V_2 , V_3 ) == false )
continue;
if ( ! F_35 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_36 -> V_151 . V_101 ,
V_150 -> V_101 , V_152 ) != 0 )
continue;
F_82 ( & V_2 -> V_115 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_104 ( struct V_144 * V_144 , const struct V_90 * V_146 ,
struct V_149 * V_150 , T_4 V_3 )
{
return NULL ;
}
static int F_105 ( struct V_142 * V_143 ,
const char * V_153 ,
const struct V_90 * V_146 ,
const T_5 V_154 ,
const char * V_77 ,
int V_155 , const struct V_156 * V_157 ,
T_4 V_3 , struct V_144 * V_144 )
{
struct V_38 V_39 = {
. V_153 = V_153 ,
. V_146 = V_146 ,
. V_154 = V_154 ,
. V_77 = V_77 ,
. V_158 = & V_159 ,
. V_155 = V_155 ,
. V_3 = V_3 ,
. V_144 = V_144 ,
. V_157 = V_157 ,
} ;
struct V_1 * V_2 ;
int error ;
F_60 ( L_20 ) ;
if ( V_143 -> V_160 & V_161 )
F_106 ( V_162 , & V_39 . V_163 ) ;
if ( V_143 -> V_164 & V_165 )
F_106 ( V_166 , & V_39 . V_163 ) ;
V_2 = F_107 ( & V_39 ) ;
if ( F_19 ( V_2 ) ) {
error = F_20 ( V_2 ) ;
goto error;
}
if ( V_143 -> V_1 == V_2 ) {
error = - V_167 ;
goto error;
}
F_106 ( V_168 , & V_2 -> V_54 ) ;
V_143 -> V_1 = V_2 ;
F_60 ( L_21 , V_2 ) ;
return 0 ;
error:
F_60 ( L_22 , error ) ;
return error ;
}
struct V_1 * F_108 ( struct V_142 * V_169 ,
const struct V_90 * V_170 , int V_171 ,
int V_172 , unsigned int V_173 , unsigned int V_174 ,
T_4 V_55 )
{
struct V_156 V_175 ;
struct V_1 * V_176 = V_169 -> V_1 ;
struct V_38 V_39 = {
. V_146 = V_170 ,
. V_154 = V_171 ,
. V_177 = V_176 -> V_30 -> V_178 ,
. V_77 = V_176 -> V_92 ,
. V_158 = & V_159 ,
. V_155 = V_172 ,
. V_3 = V_55 ,
. V_144 = V_176 -> V_7 ,
. V_157 = & V_175 ,
} ;
struct V_1 * V_2 ;
char V_75 [ V_76 + 1 ] ;
if ( F_72 ( V_170 , V_75 , sizeof( V_75 ) ) <= 0 )
return F_17 ( - V_41 ) ;
V_39 . V_153 = V_75 ;
if ( V_169 -> V_160 & V_161 )
F_61 ( V_162 , & V_39 . V_163 ) ;
F_109 ( & V_175 , V_172 , V_173 , V_174 ) ;
V_2 = F_107 ( & V_39 ) ;
F_60 ( L_23 , V_67 , V_2 ) ;
return V_2 ;
}
static void F_110 ( struct V_142 * V_143 )
{
#ifdef V_51
struct V_71 * V_179 ;
T_4 V_180 ;
T_4 V_181 ;
if ( ! F_35 ( V_143 -> V_1 ) )
return;
V_179 = V_143 -> V_1 -> V_36 ;
V_180 = V_179 -> V_182 . V_183 - V_184 ;
V_181 = V_179 -> V_182 . V_185 - V_186 ;
if ( ! V_143 -> V_187 || V_143 -> V_187 > V_180 )
V_143 -> V_187 = V_180 ;
if ( ! V_143 -> V_188 || V_143 -> V_188 > V_181 )
V_143 -> V_188 = V_181 ;
#endif
}
static int F_111 ( struct V_142 * V_143 ,
struct V_189 * V_190 , bool V_191 )
{
struct V_192 * V_193 ;
int error ;
if ( F_112 ( V_143 -> V_1 ) )
return - V_194 ;
V_193 = F_113 () ;
if ( V_193 == NULL )
return - V_29 ;
error = F_114 ( V_143 -> V_1 ) ;
if ( error < 0 )
goto V_23;
V_143 -> V_195 |= V_143 -> V_1 -> V_48 -> V_196 ;
if ( V_143 -> V_160 & V_197 )
V_143 -> V_195 &= ~ V_198 ;
if ( V_199 &&
V_143 -> V_33 -> V_21 -> V_22 == V_87 )
V_143 -> V_195 |= V_200 ;
error = F_115 ( V_143 , V_190 , V_191 ) ;
if ( error < 0 )
goto V_23;
F_60 ( L_24 ,
( unsigned long long ) V_143 -> V_201 . V_202 ,
( unsigned long long ) V_143 -> V_201 . V_203 ) ;
F_116 ( V_190 , L_25 ) ;
F_110 ( V_143 ) ;
error = F_117 ( V_143 , V_190 , V_193 ) ;
if ( error < 0 )
goto V_23;
if ( V_143 -> V_204 == 0 || V_143 -> V_204 > V_205 )
V_143 -> V_204 = V_205 ;
F_118 ( V_143 ) ;
V_143 -> V_206 = V_207 ;
V_143 -> V_208 = F_95 ;
V_23:
F_119 ( V_193 ) ;
return error ;
}
static int F_120 ( struct V_142 * V_143 ,
struct V_209 * V_101 )
{
struct V_156 V_157 ;
int error ;
F_60 ( L_26 ) ;
F_109 ( & V_157 , V_101 -> V_142 . V_210 ,
V_101 -> V_211 , V_101 -> V_212 ) ;
V_143 -> V_160 = V_101 -> V_160 ;
V_143 -> V_164 = V_101 -> V_164 ;
V_143 -> V_213 = V_101 -> V_213 ;
if ( V_101 -> V_213 . V_214 >= 1 )
V_101 -> V_215 = V_101 -> V_213 . V_216 [ 0 ] ;
else
V_101 -> V_215 = V_87 ;
error = F_105 ( V_143 ,
V_101 -> V_142 . V_153 ,
( const struct V_90 * ) & V_101 -> V_142 . V_217 ,
V_101 -> V_142 . V_154 ,
V_101 -> V_218 ,
V_101 -> V_142 . V_210 ,
& V_157 ,
V_101 -> V_3 ,
V_101 -> V_144 ) ;
if ( error < 0 )
goto error;
if ( V_101 -> V_187 )
V_143 -> V_187 = F_121 ( V_101 -> V_187 , NULL ) ;
if ( V_101 -> V_188 )
V_143 -> V_188 = F_121 ( V_101 -> V_188 , NULL ) ;
V_143 -> V_219 = V_101 -> V_219 * V_220 ;
V_143 -> V_221 = V_101 -> V_221 * V_220 ;
V_143 -> V_222 = V_101 -> V_222 * V_220 ;
V_143 -> V_223 = V_101 -> V_223 * V_220 ;
V_143 -> V_224 = V_101 -> V_142 . V_224 ;
error = F_122 ( V_143 , & V_157 ,
V_101 -> V_215 ) ;
error:
F_60 ( L_27 , error ) ;
return error ;
}
struct V_142 * F_123 ( struct V_225 * V_226 ,
struct V_227 * V_158 )
{
struct V_142 * V_143 ;
bool V_191 ;
int error ;
F_60 ( L_28 ) ;
V_143 = F_124 () ;
if ( ! V_143 )
return F_17 ( - V_29 ) ;
V_191 = V_226 -> V_228 -> V_213 . V_214 < 1 ;
error = F_120 ( V_143 , V_226 -> V_228 ) ;
if ( error < 0 )
goto error;
error = F_111 ( V_143 , V_226 -> V_190 , V_191 ) ;
if ( error < 0 )
goto error;
F_60 ( L_29 , V_143 ) ;
return V_143 ;
error:
F_125 ( V_143 ) ;
F_60 ( L_30 , error ) ;
return F_17 ( error ) ;
}
struct V_142 * F_126 ( struct V_229 * V_101 ,
struct V_189 * V_190 )
{
struct V_1 * V_230 ;
struct V_142 * V_143 , * V_231 ;
bool V_191 ;
int error ;
F_60 ( L_31 ) ;
V_143 = F_124 () ;
if ( ! V_143 )
return F_17 ( - V_29 ) ;
V_231 = F_127 ( V_101 -> V_232 ) ;
V_230 = V_231 -> V_1 ;
F_128 ( V_143 , V_231 ) ;
error = F_105 ( V_143 , V_101 -> V_153 ,
V_101 -> V_146 ,
V_101 -> V_154 ,
V_230 -> V_92 ,
F_129 ( V_231 -> V_33 ) ,
V_231 -> V_33 -> V_233 ,
V_230 -> V_48 -> V_55 ,
V_230 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_122 ( V_143 , V_231 -> V_33 -> V_233 , V_101 -> V_234 ) ;
if ( error < 0 )
goto error;
V_191 = V_231 -> V_213 . V_214 < 1 ;
error = F_111 ( V_143 , V_190 , V_191 ) ;
if ( error < 0 )
goto error;
F_60 ( L_32 , V_143 ) ;
return V_143 ;
error:
F_125 ( V_143 ) ;
F_60 ( L_33 , error ) ;
return F_17 ( error ) ;
}
static int F_130 ( struct V_142 * V_143 )
{
struct V_32 * V_32 = F_131 ( V_143 -> V_235 -> V_236 ) ;
struct V_192 * V_193 ;
int error ;
V_193 = F_113 () ;
if ( V_193 == NULL )
return - V_29 ;
error = F_117 ( V_143 , F_132 ( V_32 ) , V_193 ) ;
F_119 ( V_193 ) ;
return error ;
}
int F_133 ( struct V_142 * V_143 , const char * V_153 ,
struct V_90 * V_91 , T_5 V_237 , struct V_144 * V_144 )
{
struct V_1 * V_2 = V_143 -> V_1 ;
struct V_20 * V_238 = V_143 -> V_33 ;
struct V_239 V_240 = {
. V_241 = V_2 -> V_242 ,
. V_144 = V_144 ,
. V_243 = V_91 ,
. V_154 = V_237 ,
. V_244 = V_153 ,
} ;
char V_75 [ V_76 + 1 ] ;
struct V_88 V_217 ;
struct V_90 * V_245 = (struct V_90 * ) & V_217 ;
int error ;
F_60 ( L_34 , V_67 ,
( unsigned long long ) V_143 -> V_201 . V_202 ,
( unsigned long long ) V_143 -> V_201 . V_203 ,
V_153 ) ;
error = F_134 ( V_238 , & V_240 , V_238 -> V_233 ) ;
if ( error != 0 ) {
F_60 ( L_35 ,
V_67 , error ) ;
goto V_23;
}
error = F_71 ( V_238 , V_245 , sizeof( V_217 ) ) ;
if ( error != 0 ) {
F_60 ( L_36 ,
V_67 , error ) ;
goto V_23;
}
error = - V_246 ;
if ( F_72 ( V_245 , V_75 , sizeof( V_75 ) ) == 0 ) {
F_60 ( L_37 ,
V_67 , error ) ;
goto V_23;
}
F_135 ( V_143 ) ;
error = F_105 ( V_143 , V_153 , V_91 , V_237 , V_75 ,
V_2 -> V_242 , V_238 -> V_233 ,
V_2 -> V_47 , V_144 ) ;
F_76 ( V_2 ) ;
if ( error != 0 ) {
F_118 ( V_143 ) ;
F_60 ( L_38 ,
V_67 , error ) ;
goto V_23;
}
if ( V_143 -> V_1 -> V_138 == NULL )
V_143 -> V_1 -> V_138 = F_136 ( V_153 , V_11 ) ;
F_118 ( V_143 ) ;
error = F_130 ( V_143 ) ;
if ( error < 0 )
goto V_23;
F_60 ( L_39 , V_67 ) ;
V_23:
return error ;
}
