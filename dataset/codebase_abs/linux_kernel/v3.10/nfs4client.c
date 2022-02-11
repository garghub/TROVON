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
if ( V_2 -> V_26 != 0 )
F_34 ( V_58 , & V_2 -> V_59 ) ;
F_34 ( V_60 , & V_2 -> V_59 ) ;
error = F_40 ( V_2 , V_49 , V_61 ) ;
if ( error == - V_62 )
error = F_40 ( V_2 , V_49 , V_63 ) ;
if ( error < 0 )
goto error;
if ( V_50 == NULL ) {
struct V_64 V_65 ;
struct V_66 * V_67 = (struct V_66 * ) & V_65 ;
error = F_41 ( V_2 -> V_39 , V_67 , sizeof( V_65 ) ) ;
if ( error < 0 )
goto error;
error = F_42 ( V_67 , V_52 , sizeof( V_52 ) ) ;
if ( error < 0 )
goto error;
V_50 = ( const char * ) V_52 ;
}
F_43 ( V_2 -> V_68 , V_50 , sizeof( V_2 -> V_68 ) ) ;
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
V_2 -> V_69 = true ;
V_2 = V_54 ;
}
return V_2 ;
error:
F_38 ( V_2 , error ) ;
F_46 ( V_2 ) ;
F_33 ( L_5 , error ) ;
return F_19 ( error ) ;
}
static void F_47 ( struct V_1 * V_70 ,
struct V_1 * V_71 )
{
struct V_5 * V_6 = F_2 ( V_70 -> V_7 , V_8 ) ;
unsigned int V_72 = V_70 -> V_15 ;
if ( V_70 -> V_15 == V_71 -> V_15 )
return;
F_33 ( L_6 ,
V_42 , V_70 -> V_15 , V_71 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_48 ( & V_6 -> V_13 , V_70 , V_71 -> V_15 ) ;
V_70 -> V_15 = V_71 -> V_15 ;
F_48 ( & V_6 -> V_13 , V_71 , V_72 ) ;
V_71 -> V_15 = V_72 ;
F_6 ( & V_6 -> V_12 ) ;
}
int F_49 ( struct V_1 * V_73 ,
struct V_1 * * V_74 ,
struct V_75 * V_76 )
{
struct V_5 * V_6 = F_2 ( V_73 -> V_7 , V_8 ) ;
struct V_1 * V_77 , * V_78 = NULL ;
struct V_79 V_80 = {
. V_81 = V_73 -> V_82 ,
. V_83 = V_73 -> V_84 ,
} ;
int V_85 = - V_86 ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_77 -> V_55 > V_56 ) {
F_51 ( & V_77 -> V_87 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_78 )
F_46 ( V_78 ) ;
V_78 = V_77 ;
V_85 = F_52 ( V_77 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_85 < 0 )
continue;
}
if ( V_77 -> V_55 != V_56 )
continue;
if ( V_77 -> V_9 != V_73 -> V_9 )
continue;
if ( V_77 -> V_88 != V_73 -> V_88 )
continue;
if ( V_77 -> V_26 != V_73 -> V_26 )
continue;
if ( V_77 -> V_82 != V_73 -> V_82 )
continue;
F_51 ( & V_77 -> V_87 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_78 )
F_46 ( V_78 ) ;
V_78 = V_77 ;
V_85 = F_53 ( V_77 , & V_80 , V_76 ) ;
switch ( V_85 ) {
case - V_86 :
break;
case 0 :
F_47 ( V_77 , V_73 ) ;
V_78 = NULL ;
* V_74 = V_77 ;
F_33 ( L_7 ,
V_42 , V_77 , F_54 ( & V_77 -> V_87 ) ) ;
default:
goto V_89;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_89:
if ( V_78 )
F_46 ( V_78 ) ;
F_33 ( L_8 , V_42 , V_85 ) ;
return V_85 ;
}
static bool F_55 ( struct V_1 * V_90 , struct V_1 * V_91 )
{
if ( V_90 -> V_82 != V_91 -> V_82 ) {
F_33 ( L_9 ,
V_42 , V_90 -> V_82 , V_91 -> V_82 ) ;
return false ;
}
F_33 ( L_10 ,
V_42 , V_90 -> V_82 , V_91 -> V_82 ) ;
return true ;
}
static bool
F_56 ( struct V_1 * V_90 , struct V_1 * V_91 )
{
struct V_92 * V_93 = V_90 -> V_34 ;
struct V_92 * V_94 = V_91 -> V_34 ;
if ( V_93 -> V_95 != V_94 -> V_95 ) {
F_33 ( L_11 ,
V_42 ) ;
return false ;
}
if ( V_93 -> V_96 != V_94 -> V_96 )
goto V_97;
if ( memcmp ( V_93 -> V_98 , V_94 -> V_98 , V_93 -> V_96 ) != 0 )
goto V_97;
F_33 ( L_12 , V_42 ) ;
return true ;
V_97:
F_33 ( L_13 ,
V_42 ) ;
return false ;
}
int F_57 ( struct V_1 * V_73 ,
struct V_1 * * V_74 ,
struct V_75 * V_76 )
{
struct V_5 * V_6 = F_2 ( V_73 -> V_7 , V_8 ) ;
struct V_1 * V_77 , * V_78 = NULL ;
int V_85 = - V_86 ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_77 -> V_55 > V_56 ) {
F_51 ( & V_77 -> V_87 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_78 )
F_46 ( V_78 ) ;
V_78 = V_77 ;
V_85 = F_52 ( V_77 ) ;
if ( V_85 == 0 ) {
F_58 ( V_77 ) ;
V_85 = F_59 ( V_77 ) ;
}
F_4 ( & V_6 -> V_12 ) ;
if ( V_85 < 0 )
continue;
}
if ( V_77 -> V_55 != V_56 )
continue;
if ( V_77 -> V_9 != V_73 -> V_9 )
continue;
if ( V_77 -> V_88 != V_73 -> V_88 )
continue;
if ( V_77 -> V_26 != V_73 -> V_26 )
continue;
if ( ! F_55 ( V_77 , V_73 ) )
continue;
if ( ! F_56 ( V_77 , V_73 ) )
continue;
F_51 ( & V_77 -> V_87 ) ;
* V_74 = V_77 ;
V_85 = 0 ;
F_33 ( L_7 ,
V_42 , V_77 , F_54 ( & V_77 -> V_87 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_33 ( L_8 , V_42 , V_85 ) ;
if ( V_78 )
F_46 ( V_78 ) ;
return V_85 ;
}
static void F_60 ( struct V_99 * V_100 )
{
F_61 ( V_100 ) ;
F_62 ( V_100 ) ;
F_63 ( V_100 ) ;
}
struct V_1 *
F_64 ( struct V_101 * V_101 , int V_102 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_101 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_65 ( & V_6 -> V_13 , V_102 ) ;
if ( V_2 )
F_51 ( & V_2 -> V_87 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_66 ( const struct V_66 * V_103 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_66 * V_104 = (struct V_66 * ) & V_2 -> V_105 ;
if ( ! ( V_2 -> V_55 == V_56 ||
V_2 -> V_55 == V_47 ) )
return false ;
F_67 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_26 != V_3 )
return false ;
if ( ! F_68 ( V_103 , V_104 ) )
return false ;
return true ;
}
struct V_1 *
F_69 ( struct V_101 * V_101 , const struct V_66 * V_103 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_101 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_66 ( V_103 , V_2 , 1 ) == false )
continue;
if ( ! F_9 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_16 -> V_108 . V_109 ,
V_107 -> V_109 , V_110 ) != 0 )
continue;
F_51 ( & V_2 -> V_87 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_69 ( struct V_101 * V_101 , const struct V_66 * V_103 ,
struct V_106 * V_107 )
{
return NULL ;
}
static int F_70 ( struct V_99 * V_100 ,
const char * V_111 ,
const struct V_66 * V_103 ,
const T_3 V_112 ,
const char * V_50 ,
T_1 V_51 ,
int V_113 , const struct V_48 * V_49 ,
T_2 V_3 , struct V_101 * V_101 )
{
struct V_17 V_18 = {
. V_111 = V_111 ,
. V_103 = V_103 ,
. V_112 = V_112 ,
. V_114 = & V_115 ,
. V_113 = V_113 ,
. V_3 = V_3 ,
. V_101 = V_101 ,
} ;
struct V_1 * V_2 ;
int error ;
F_33 ( L_14 ) ;
if ( V_100 -> V_116 & V_117 )
F_71 ( V_118 , & V_18 . V_119 ) ;
V_2 = F_72 ( & V_18 , V_49 , V_50 , V_51 ) ;
if ( F_14 ( V_2 ) ) {
error = F_73 ( V_2 ) ;
goto error;
}
F_71 ( V_120 , & V_2 -> V_30 ) ;
V_100 -> V_1 = V_2 ;
F_33 ( L_15 , V_2 ) ;
return 0 ;
error:
F_33 ( L_16 , error ) ;
return error ;
}
struct V_1 * F_74 ( struct V_1 * V_121 ,
const struct V_66 * V_122 , int V_123 ,
int V_124 , unsigned int V_125 , unsigned int V_126 )
{
struct V_17 V_18 = {
. V_103 = V_122 ,
. V_112 = V_123 ,
. V_114 = & V_115 ,
. V_113 = V_124 ,
. V_3 = V_121 -> V_26 ,
. V_101 = V_121 -> V_7 ,
} ;
struct V_48 V_127 ;
struct V_1 * V_2 ;
F_75 ( & V_127 , V_124 , V_125 , V_126 ) ;
V_2 = F_72 ( & V_18 , & V_127 , V_121 -> V_68 ,
V_121 -> V_39 -> V_128 -> V_129 ) ;
F_33 ( L_17 , V_42 , V_2 ) ;
return V_2 ;
}
static void F_76 ( struct V_99 * V_100 )
{
#ifdef V_43
struct V_44 * V_130 ;
T_2 V_131 ;
T_2 V_132 ;
if ( ! F_9 ( V_100 -> V_1 ) )
return;
V_130 = V_100 -> V_1 -> V_16 ;
V_131 = V_130 -> V_133 . V_134 - V_135 ;
V_132 = V_130 -> V_133 . V_136 - V_137 ;
if ( V_100 -> V_138 > V_131 )
V_100 -> V_138 = V_131 ;
if ( V_100 -> V_139 > V_132 )
V_100 -> V_139 = V_132 ;
#endif
}
static int F_77 ( struct V_99 * V_100 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 ;
int error ;
if ( F_78 ( V_100 -> V_1 ) )
return - V_144 ;
V_143 = F_79 () ;
if ( V_143 == NULL )
return - V_46 ;
error = F_80 ( V_100 ) ;
if ( error < 0 )
goto V_89;
V_100 -> V_145 |= V_100 -> V_1 -> V_27 -> V_146 ;
if ( V_100 -> V_116 & V_147 )
V_100 -> V_145 &= ~ V_148 ;
if ( V_149 &&
V_100 -> V_150 -> V_128 -> V_129 == V_63 )
V_100 -> V_145 |= V_151 ;
error = F_81 ( V_100 , V_141 ) ;
if ( error < 0 )
goto V_89;
F_33 ( L_18 ,
( unsigned long long ) V_100 -> V_152 . V_153 ,
( unsigned long long ) V_100 -> V_152 . V_154 ) ;
F_33 ( L_19 , V_141 -> V_155 ) ;
F_76 ( V_100 ) ;
error = F_82 ( V_100 , V_141 , V_143 ) ;
if ( error < 0 )
goto V_89;
if ( V_100 -> V_156 == 0 || V_100 -> V_156 > V_157 )
V_100 -> V_156 = V_157 ;
F_83 ( V_100 ) ;
V_100 -> V_158 = V_159 ;
V_100 -> V_160 = F_60 ;
V_89:
F_84 ( V_143 ) ;
return error ;
}
static int F_85 ( struct V_99 * V_100 ,
const struct V_161 * V_109 )
{
struct V_48 V_49 ;
int error ;
F_33 ( L_20 ) ;
F_75 ( & V_49 , V_109 -> V_99 . V_162 ,
V_109 -> V_163 , V_109 -> V_164 ) ;
V_100 -> V_116 = V_109 -> V_116 ;
V_100 -> V_165 = V_109 -> V_165 ;
error = F_70 ( V_100 ,
V_109 -> V_99 . V_111 ,
( const struct V_66 * ) & V_109 -> V_99 . V_166 ,
V_109 -> V_99 . V_112 ,
V_109 -> V_167 ,
V_109 -> V_168 [ 0 ] ,
V_109 -> V_99 . V_162 ,
& V_49 ,
V_109 -> V_3 ,
V_109 -> V_101 ) ;
if ( error < 0 )
goto error;
if ( V_109 -> V_138 )
V_100 -> V_138 = F_86 ( V_109 -> V_138 , NULL ) ;
if ( V_109 -> V_139 )
V_100 -> V_139 = F_86 ( V_109 -> V_139 , NULL ) ;
V_100 -> V_169 = V_109 -> V_169 * V_170 ;
V_100 -> V_171 = V_109 -> V_171 * V_170 ;
V_100 -> V_172 = V_109 -> V_172 * V_170 ;
V_100 -> V_173 = V_109 -> V_173 * V_170 ;
V_100 -> V_174 = V_109 -> V_99 . V_174 ;
error = F_87 ( V_100 , & V_49 , V_109 -> V_168 [ 0 ] ) ;
error:
F_33 ( L_21 , error ) ;
return error ;
}
struct V_99 * F_88 ( struct V_175 * V_176 ,
struct V_177 * V_114 )
{
struct V_99 * V_100 ;
int error ;
F_33 ( L_22 ) ;
V_100 = F_89 () ;
if ( ! V_100 )
return F_19 ( - V_46 ) ;
error = F_85 ( V_100 , V_176 -> V_178 ) ;
if ( error < 0 )
goto error;
error = F_77 ( V_100 , V_176 -> V_141 ) ;
if ( error < 0 )
goto error;
F_33 ( L_23 , V_100 ) ;
return V_100 ;
error:
F_90 ( V_100 ) ;
F_33 ( L_24 , error ) ;
return F_19 ( error ) ;
}
struct V_99 * F_91 ( struct V_179 * V_109 ,
struct V_140 * V_141 )
{
struct V_1 * V_180 ;
struct V_99 * V_100 , * V_181 ;
int error ;
F_33 ( L_25 ) ;
V_100 = F_89 () ;
if ( ! V_100 )
return F_19 ( - V_46 ) ;
V_181 = F_92 ( V_109 -> V_182 ) ;
V_180 = V_181 -> V_1 ;
F_93 ( V_100 , V_181 ) ;
error = F_70 ( V_100 , V_109 -> V_111 ,
V_109 -> V_103 ,
V_109 -> V_112 ,
V_180 -> V_68 ,
V_109 -> V_183 ,
F_94 ( V_181 -> V_150 ) ,
V_181 -> V_150 -> V_184 ,
V_180 -> V_27 -> V_31 ,
V_180 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_87 ( V_100 , V_181 -> V_150 -> V_184 , V_109 -> V_183 ) ;
if ( error < 0 )
goto error;
error = F_77 ( V_100 , V_141 ) ;
if ( error < 0 )
goto error;
F_33 ( L_26 , V_100 ) ;
return V_100 ;
error:
F_90 ( V_100 ) ;
F_33 ( L_27 , error ) ;
return F_19 ( error ) ;
}
