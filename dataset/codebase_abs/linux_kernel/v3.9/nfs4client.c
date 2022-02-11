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
static void F_8 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) ) {
F_10 ( V_2 -> V_16 ) ;
F_11 ( V_2 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
}
struct V_1 * F_12 ( const struct V_17 * V_18 )
{
int V_19 ;
struct V_1 * V_2 = F_13 ( V_18 ) ;
if ( F_14 ( V_2 ) )
return V_2 ;
V_19 = F_1 ( V_2 , V_18 -> V_3 ) ;
if ( V_19 )
goto error;
F_15 ( & V_2 -> V_20 ) ;
F_16 ( & V_2 -> V_21 , V_22 ) ;
F_17 ( & V_2 -> V_23 , L_1 ) ;
V_2 -> V_24 = 1 << V_25 ;
V_2 -> V_26 = V_18 -> V_3 ;
V_2 -> V_27 = V_28 [ V_18 -> V_3 ] ;
return V_2 ;
error:
F_18 ( V_2 ) ;
return F_19 ( V_19 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( F_21 ( V_29 , & V_2 -> V_30 ) )
F_22 ( V_2 -> V_27 -> V_31 , V_2 -> V_7 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( F_21 ( V_32 , & V_2 -> V_30 ) )
F_24 ( V_2 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( F_21 ( V_33 , & V_2 -> V_30 ) )
F_25 ( V_2 ) ;
F_26 ( & V_2 -> V_23 ) ;
F_27 ( V_2 -> V_34 ) ;
F_27 ( V_2 -> V_35 ) ;
F_27 ( V_2 -> V_36 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int error ;
if ( V_2 -> V_9 -> V_10 == 4 ) {
struct V_37 * V_38 ;
V_38 = F_30 ( V_2 -> V_39 -> V_40 ) ;
if ( F_9 ( V_2 ) ) {
error = F_31 ( V_38 ,
V_41 ) ;
if ( error < 0 )
return error ;
}
error = F_32 ( V_2 -> V_27 -> V_31 , V_38 ) ;
if ( error < 0 ) {
F_33 ( L_2 ,
V_42 , error ) ;
return error ;
}
F_34 ( V_29 , & V_2 -> V_30 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
#if F_36 ( V_43 )
if ( V_2 -> V_27 -> V_31 ) {
struct V_44 * V_45 = NULL ;
V_45 = F_37 ( V_2 ) ;
if ( ! V_45 )
return - V_46 ;
V_2 -> V_16 = V_45 ;
F_38 ( V_2 , V_47 ) ;
}
#endif
return F_29 ( V_2 ) ;
}
struct V_1 * F_39 ( struct V_1 * V_2 ,
const struct V_48 * V_49 ,
const char * V_50 ,
T_1 V_51 )
{
char V_52 [ V_53 + 1 ] ;
struct V_1 * V_54 ;
int error ;
if ( V_2 -> V_55 == V_56 ) {
F_33 ( L_3 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_57 ;
F_34 ( V_58 , & V_2 -> V_59 ) ;
error = F_40 ( V_2 , V_49 , V_51 ) ;
if ( error < 0 )
goto error;
if ( V_50 == NULL ) {
struct V_60 V_61 ;
struct V_62 * V_63 = (struct V_62 * ) & V_61 ;
error = F_41 ( V_2 -> V_39 , V_63 , sizeof( V_61 ) ) ;
if ( error < 0 )
goto error;
error = F_42 ( V_63 , V_52 , sizeof( V_52 ) ) ;
if ( error < 0 )
goto error;
V_50 = ( const char * ) V_52 ;
}
F_43 ( V_2 -> V_64 , V_50 , sizeof( V_2 -> V_64 ) ) ;
error = F_44 ( V_2 ) ;
if ( error < 0 ) {
F_33 ( L_4 ,
V_42 , error ) ;
goto error;
}
F_34 ( V_33 , & V_2 -> V_30 ) ;
error = F_35 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_9 ( V_2 ) )
F_38 ( V_2 , V_56 ) ;
error = F_45 ( V_2 , & V_54 ) ;
if ( error < 0 )
goto error;
F_46 ( V_2 ) ;
if ( V_2 != V_54 ) {
V_2 -> V_65 = true ;
V_2 = V_54 ;
}
return V_2 ;
error:
F_38 ( V_2 , error ) ;
F_46 ( V_2 ) ;
F_33 ( L_5 , error ) ;
return F_19 ( error ) ;
}
static void F_47 ( struct V_1 * V_66 ,
struct V_1 * V_67 )
{
struct V_5 * V_6 = F_2 ( V_66 -> V_7 , V_8 ) ;
unsigned int V_68 = V_66 -> V_15 ;
if ( V_66 -> V_15 == V_67 -> V_15 )
return;
F_33 ( L_6 ,
V_42 , V_66 -> V_15 , V_67 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_48 ( & V_6 -> V_13 , V_66 , V_67 -> V_15 ) ;
V_66 -> V_15 = V_67 -> V_15 ;
F_48 ( & V_6 -> V_13 , V_67 , V_68 ) ;
V_67 -> V_15 = V_68 ;
F_6 ( & V_6 -> V_12 ) ;
}
int F_49 ( struct V_1 * V_69 ,
struct V_1 * * V_70 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_69 -> V_7 , V_8 ) ;
struct V_1 * V_73 , * V_74 = NULL ;
struct V_75 V_76 = {
. V_77 = V_69 -> V_78 ,
. V_79 = V_69 -> V_80 ,
} ;
int V_81 = - V_82 ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_73 -> V_55 > V_56 ) {
F_51 ( & V_73 -> V_83 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_74 )
F_46 ( V_74 ) ;
V_74 = V_73 ;
V_81 = F_52 ( V_73 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_81 < 0 )
continue;
}
if ( V_73 -> V_55 != V_56 )
continue;
if ( V_73 -> V_9 != V_69 -> V_9 )
continue;
if ( V_73 -> V_84 != V_69 -> V_84 )
continue;
if ( V_73 -> V_26 != V_69 -> V_26 )
continue;
if ( V_73 -> V_78 != V_69 -> V_78 )
continue;
F_51 ( & V_73 -> V_83 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_74 )
F_46 ( V_74 ) ;
V_74 = V_73 ;
V_81 = F_53 ( V_73 , & V_76 , V_72 ) ;
switch ( V_81 ) {
case - V_82 :
break;
case 0 :
F_47 ( V_73 , V_69 ) ;
V_74 = NULL ;
* V_70 = V_73 ;
F_33 ( L_7 ,
V_42 , V_73 , F_54 ( & V_73 -> V_83 ) ) ;
default:
goto V_85;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_85:
if ( V_74 )
F_46 ( V_74 ) ;
F_33 ( L_8 , V_42 , V_81 ) ;
return V_81 ;
}
static bool F_55 ( struct V_1 * V_86 , struct V_1 * V_87 )
{
if ( V_86 -> V_78 != V_87 -> V_78 ) {
F_33 ( L_9 ,
V_42 , V_86 -> V_78 , V_87 -> V_78 ) ;
return false ;
}
F_33 ( L_10 ,
V_42 , V_86 -> V_78 , V_87 -> V_78 ) ;
return true ;
}
static bool
F_56 ( struct V_1 * V_86 , struct V_1 * V_87 )
{
struct V_88 * V_89 = V_86 -> V_34 ;
struct V_88 * V_90 = V_87 -> V_34 ;
if ( V_89 -> V_91 != V_90 -> V_91 ) {
F_33 ( L_11 ,
V_42 ) ;
return false ;
}
if ( V_89 -> V_92 != V_90 -> V_92 )
goto V_93;
if ( memcmp ( V_89 -> V_94 , V_90 -> V_94 , V_89 -> V_92 ) != 0 )
goto V_93;
F_33 ( L_12 , V_42 ) ;
return true ;
V_93:
F_33 ( L_13 ,
V_42 ) ;
return false ;
}
int F_57 ( struct V_1 * V_69 ,
struct V_1 * * V_70 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_69 -> V_7 , V_8 ) ;
struct V_1 * V_73 , * V_74 = NULL ;
int V_81 = - V_82 ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_73 -> V_55 > V_56 ) {
F_51 ( & V_73 -> V_83 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_74 )
F_46 ( V_74 ) ;
V_74 = V_73 ;
V_81 = F_52 ( V_73 ) ;
if ( V_81 == 0 ) {
F_58 ( V_73 ) ;
V_81 = F_59 ( V_73 ) ;
}
F_4 ( & V_6 -> V_12 ) ;
if ( V_81 < 0 )
continue;
}
if ( V_73 -> V_55 != V_56 )
continue;
if ( V_73 -> V_9 != V_69 -> V_9 )
continue;
if ( V_73 -> V_84 != V_69 -> V_84 )
continue;
if ( V_73 -> V_26 != V_69 -> V_26 )
continue;
if ( ! F_55 ( V_73 , V_69 ) )
continue;
if ( ! F_56 ( V_73 , V_69 ) )
continue;
F_51 ( & V_73 -> V_83 ) ;
* V_70 = V_73 ;
V_81 = 0 ;
F_33 ( L_7 ,
V_42 , V_73 , F_54 ( & V_73 -> V_83 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_33 ( L_8 , V_42 , V_81 ) ;
if ( V_74 )
F_46 ( V_74 ) ;
return V_81 ;
}
static void F_60 ( struct V_95 * V_96 )
{
F_61 ( V_96 ) ;
F_62 ( V_96 ) ;
F_63 ( V_96 ) ;
}
struct V_1 *
F_64 ( struct V_97 * V_97 , int V_98 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_97 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_65 ( & V_6 -> V_13 , V_98 ) ;
if ( V_2 )
F_51 ( & V_2 -> V_83 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_66 ( const struct V_62 * V_99 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_62 * V_100 = (struct V_62 * ) & V_2 -> V_101 ;
if ( ! ( V_2 -> V_55 == V_56 ||
V_2 -> V_55 == V_47 ) )
return false ;
F_67 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_26 != V_3 )
return false ;
if ( ! F_68 ( V_99 , V_100 ) )
return false ;
return true ;
}
struct V_1 *
F_69 ( struct V_97 * V_97 , const struct V_62 * V_99 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_97 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_66 ( V_99 , V_2 , 1 ) == false )
continue;
if ( ! F_9 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_16 -> V_104 . V_105 ,
V_103 -> V_105 , V_106 ) != 0 )
continue;
F_51 ( & V_2 -> V_83 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_69 ( struct V_97 * V_97 , const struct V_62 * V_99 ,
struct V_102 * V_103 )
{
return NULL ;
}
static int F_70 ( struct V_95 * V_96 ,
const char * V_107 ,
const struct V_62 * V_99 ,
const T_3 V_108 ,
const char * V_50 ,
T_1 V_51 ,
int V_109 , const struct V_48 * V_49 ,
T_2 V_3 , struct V_97 * V_97 )
{
struct V_17 V_18 = {
. V_107 = V_107 ,
. V_99 = V_99 ,
. V_108 = V_108 ,
. V_110 = & V_111 ,
. V_109 = V_109 ,
. V_3 = V_3 ,
. V_97 = V_97 ,
} ;
struct V_1 * V_2 ;
int error ;
F_33 ( L_14 ) ;
if ( V_96 -> V_112 & V_113 )
F_71 ( V_114 , & V_18 . V_115 ) ;
V_2 = F_72 ( & V_18 , V_49 , V_50 , V_51 ) ;
if ( F_14 ( V_2 ) ) {
error = F_73 ( V_2 ) ;
goto error;
}
F_71 ( V_116 , & V_2 -> V_30 ) ;
V_96 -> V_1 = V_2 ;
F_33 ( L_15 , V_2 ) ;
return 0 ;
error:
F_33 ( L_16 , error ) ;
return error ;
}
struct V_1 * F_74 ( struct V_1 * V_117 ,
const struct V_62 * V_118 , int V_119 ,
int V_120 , unsigned int V_121 , unsigned int V_122 )
{
struct V_17 V_18 = {
. V_99 = V_118 ,
. V_108 = V_119 ,
. V_110 = & V_111 ,
. V_109 = V_120 ,
. V_3 = V_117 -> V_26 ,
. V_97 = V_117 -> V_7 ,
} ;
struct V_48 V_123 ;
struct V_1 * V_2 ;
F_75 ( & V_123 , V_120 , V_121 , V_122 ) ;
V_2 = F_72 ( & V_18 , & V_123 , V_117 -> V_64 ,
V_117 -> V_39 -> V_124 -> V_125 ) ;
F_33 ( L_17 , V_42 , V_2 ) ;
return V_2 ;
}
static void F_76 ( struct V_95 * V_96 )
{
#ifdef V_43
struct V_44 * V_126 ;
T_2 V_127 ;
T_2 V_128 ;
if ( ! F_9 ( V_96 -> V_1 ) )
return;
V_126 = V_96 -> V_1 -> V_16 ;
V_127 = V_126 -> V_129 . V_130 - V_131 ;
V_128 = V_126 -> V_129 . V_132 - V_133 ;
if ( V_96 -> V_134 > V_127 )
V_96 -> V_134 = V_127 ;
if ( V_96 -> V_135 > V_128 )
V_96 -> V_135 = V_128 ;
#endif
}
static int F_77 ( struct V_95 * V_96 ,
struct V_136 * V_137 )
{
struct V_138 * V_139 ;
int error ;
if ( F_78 ( V_96 -> V_1 ) )
return - V_140 ;
V_139 = F_79 () ;
if ( V_139 == NULL )
return - V_46 ;
error = F_80 ( V_96 ) ;
if ( error < 0 )
goto V_85;
error = F_81 ( V_96 , V_137 ) ;
if ( error < 0 )
goto V_85;
F_33 ( L_18 ,
( unsigned long long ) V_96 -> V_141 . V_142 ,
( unsigned long long ) V_96 -> V_141 . V_143 ) ;
F_33 ( L_19 , V_137 -> V_144 ) ;
F_76 ( V_96 ) ;
error = F_82 ( V_96 , V_137 , V_139 ) ;
if ( error < 0 )
goto V_85;
if ( V_96 -> V_145 == 0 || V_96 -> V_145 > V_146 )
V_96 -> V_145 = V_146 ;
F_83 ( V_96 ) ;
V_96 -> V_147 = V_148 ;
V_96 -> V_149 = F_60 ;
V_85:
F_84 ( V_139 ) ;
return error ;
}
static int F_85 ( struct V_95 * V_96 ,
const struct V_150 * V_105 )
{
struct V_48 V_49 ;
int error ;
F_33 ( L_20 ) ;
F_75 ( & V_49 , V_105 -> V_95 . V_151 ,
V_105 -> V_152 , V_105 -> V_153 ) ;
V_96 -> V_112 = V_105 -> V_112 ;
V_96 -> V_154 |= V_155 | V_156 | V_157 ;
if ( ! ( V_105 -> V_112 & V_158 ) )
V_96 -> V_154 |= V_159 ;
V_96 -> V_160 = V_105 -> V_160 ;
error = F_70 ( V_96 ,
V_105 -> V_95 . V_107 ,
( const struct V_62 * ) & V_105 -> V_95 . V_161 ,
V_105 -> V_95 . V_108 ,
V_105 -> V_162 ,
V_105 -> V_163 [ 0 ] ,
V_105 -> V_95 . V_151 ,
& V_49 ,
V_105 -> V_3 ,
V_105 -> V_97 ) ;
if ( error < 0 )
goto error;
if ( V_164 && V_105 -> V_163 [ 0 ] == V_165 )
V_96 -> V_154 |= V_166 ;
if ( V_105 -> V_134 )
V_96 -> V_134 = F_86 ( V_105 -> V_134 , NULL ) ;
if ( V_105 -> V_135 )
V_96 -> V_135 = F_86 ( V_105 -> V_135 , NULL ) ;
V_96 -> V_167 = V_105 -> V_167 * V_168 ;
V_96 -> V_169 = V_105 -> V_169 * V_168 ;
V_96 -> V_170 = V_105 -> V_170 * V_168 ;
V_96 -> V_171 = V_105 -> V_171 * V_168 ;
V_96 -> V_172 = V_105 -> V_95 . V_172 ;
error = F_87 ( V_96 , & V_49 , V_105 -> V_163 [ 0 ] ) ;
error:
F_33 ( L_21 , error ) ;
return error ;
}
struct V_95 * F_88 ( struct V_173 * V_174 ,
struct V_175 * V_110 )
{
struct V_95 * V_96 ;
int error ;
F_33 ( L_22 ) ;
V_96 = F_89 () ;
if ( ! V_96 )
return F_19 ( - V_46 ) ;
error = F_85 ( V_96 , V_174 -> V_176 ) ;
if ( error < 0 )
goto error;
error = F_77 ( V_96 , V_174 -> V_137 ) ;
if ( error < 0 )
goto error;
F_33 ( L_23 , V_96 ) ;
return V_96 ;
error:
F_90 ( V_96 ) ;
F_33 ( L_24 , error ) ;
return F_19 ( error ) ;
}
struct V_95 * F_91 ( struct V_177 * V_105 ,
struct V_136 * V_137 )
{
struct V_1 * V_178 ;
struct V_95 * V_96 , * V_179 ;
int error ;
F_33 ( L_25 ) ;
V_96 = F_89 () ;
if ( ! V_96 )
return F_19 ( - V_46 ) ;
V_179 = F_92 ( V_105 -> V_180 ) ;
V_178 = V_179 -> V_1 ;
F_93 ( V_96 , V_179 ) ;
V_96 -> V_154 |= V_155 | V_156 ;
error = F_70 ( V_96 , V_105 -> V_107 ,
V_105 -> V_99 ,
V_105 -> V_108 ,
V_178 -> V_64 ,
V_105 -> V_181 ,
F_94 ( V_179 -> V_182 ) ,
V_179 -> V_182 -> V_183 ,
V_178 -> V_27 -> V_31 ,
V_178 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_87 ( V_96 , V_179 -> V_182 -> V_183 , V_105 -> V_181 ) ;
if ( error < 0 )
goto error;
error = F_77 ( V_96 , V_137 ) ;
if ( error < 0 )
goto error;
F_33 ( L_26 , V_96 ) ;
return V_96 ;
error:
F_90 ( V_96 ) ;
F_33 ( L_27 , error ) ;
return F_19 ( error ) ;
}
