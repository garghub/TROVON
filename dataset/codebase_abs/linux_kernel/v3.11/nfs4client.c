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
if ( V_18 -> V_3 > V_20 ) {
V_19 = - V_21 ;
goto error;
}
F_15 ( & V_2 -> V_22 ) ;
F_16 ( & V_2 -> V_23 , V_24 ) ;
F_17 ( & V_2 -> V_25 , L_1 ) ;
V_2 -> V_26 = 1 << V_27 ;
V_2 -> V_28 = V_18 -> V_3 ;
V_2 -> V_29 = V_30 [ V_18 -> V_3 ] ;
return V_2 ;
error:
F_18 ( V_2 ) ;
return F_19 ( V_19 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( F_21 ( V_31 , & V_2 -> V_32 ) )
F_22 ( V_2 -> V_29 -> V_33 , V_2 -> V_7 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( F_21 ( V_34 , & V_2 -> V_32 ) )
F_24 ( V_2 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( F_21 ( V_35 , & V_2 -> V_32 ) )
F_25 ( V_2 ) ;
F_26 ( & V_2 -> V_25 ) ;
F_27 ( V_2 -> V_36 ) ;
F_27 ( V_2 -> V_37 ) ;
F_27 ( V_2 -> V_38 ) ;
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
struct V_39 * V_40 ;
V_40 = F_30 ( V_2 -> V_41 -> V_42 ) ;
if ( F_9 ( V_2 ) ) {
error = F_31 ( V_40 ,
V_43 ) ;
if ( error < 0 )
return error ;
}
error = F_32 ( V_2 -> V_29 -> V_33 , V_40 ) ;
if ( error < 0 ) {
F_33 ( L_2 ,
V_44 , error ) ;
return error ;
}
F_34 ( V_31 , & V_2 -> V_32 ) ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
#if F_36 ( V_45 )
if ( V_2 -> V_29 -> V_33 ) {
struct V_46 * V_47 = NULL ;
V_47 = F_37 ( V_2 ) ;
if ( ! V_47 )
return - V_48 ;
V_2 -> V_16 = V_47 ;
F_38 ( V_2 , V_49 ) ;
}
#endif
return F_29 ( V_2 ) ;
}
struct V_1 * F_39 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
const char * V_52 ,
T_1 V_53 )
{
char V_54 [ V_55 + 1 ] ;
struct V_1 * V_56 ;
int error ;
if ( V_2 -> V_57 == V_58 ) {
F_33 ( L_3 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_59 ;
if ( V_2 -> V_28 != 0 )
F_34 ( V_60 , & V_2 -> V_61 ) ;
F_34 ( V_62 , & V_2 -> V_61 ) ;
error = F_40 ( V_2 , V_51 , V_63 ) ;
if ( error == - V_21 )
error = F_40 ( V_2 , V_51 , V_64 ) ;
if ( error < 0 )
goto error;
if ( V_52 == NULL ) {
struct V_65 V_66 ;
struct V_67 * V_68 = (struct V_67 * ) & V_66 ;
error = F_41 ( V_2 -> V_41 , V_68 , sizeof( V_66 ) ) ;
if ( error < 0 )
goto error;
error = F_42 ( V_68 , V_54 , sizeof( V_54 ) ) ;
if ( error < 0 )
goto error;
V_52 = ( const char * ) V_54 ;
}
F_43 ( V_2 -> V_69 , V_52 , sizeof( V_2 -> V_69 ) ) ;
error = F_44 ( V_2 ) ;
if ( error < 0 ) {
F_33 ( L_4 ,
V_44 , error ) ;
goto error;
}
F_34 ( V_35 , & V_2 -> V_32 ) ;
error = F_35 ( V_2 ) ;
if ( error < 0 )
goto error;
if ( ! F_9 ( V_2 ) )
F_38 ( V_2 , V_58 ) ;
error = F_45 ( V_2 , & V_56 ) ;
if ( error < 0 )
goto error;
F_46 ( V_2 ) ;
if ( V_2 != V_56 ) {
V_2 -> V_70 = true ;
V_2 = V_56 ;
}
return V_2 ;
error:
F_38 ( V_2 , error ) ;
F_46 ( V_2 ) ;
F_33 ( L_5 , error ) ;
return F_19 ( error ) ;
}
static void F_47 ( struct V_1 * V_71 ,
struct V_1 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_71 -> V_7 , V_8 ) ;
unsigned int V_73 = V_71 -> V_15 ;
if ( V_71 -> V_15 == V_72 -> V_15 )
return;
F_33 ( L_6 ,
V_44 , V_71 -> V_15 , V_72 -> V_15 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_48 ( & V_6 -> V_13 , V_71 , V_72 -> V_15 ) ;
V_71 -> V_15 = V_72 -> V_15 ;
F_48 ( & V_6 -> V_13 , V_72 , V_73 ) ;
V_72 -> V_15 = V_73 ;
F_6 ( & V_6 -> V_12 ) ;
}
int F_49 ( struct V_1 * V_74 ,
struct V_1 * * V_75 ,
struct V_76 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_74 -> V_7 , V_8 ) ;
struct V_1 * V_78 , * V_79 = NULL ;
struct V_80 V_81 = {
. V_82 = V_74 -> V_83 ,
. V_84 = V_74 -> V_85 ,
} ;
int V_86 = - V_87 ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_78 -> V_57 > V_58 ) {
F_51 ( & V_78 -> V_88 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_79 )
F_46 ( V_79 ) ;
V_79 = V_78 ;
V_86 = F_52 ( V_78 ) ;
F_4 ( & V_6 -> V_12 ) ;
if ( V_86 < 0 )
continue;
}
if ( V_78 -> V_57 != V_58 )
continue;
if ( V_78 -> V_9 != V_74 -> V_9 )
continue;
if ( V_78 -> V_89 != V_74 -> V_89 )
continue;
if ( V_78 -> V_28 != V_74 -> V_28 )
continue;
if ( V_78 -> V_83 != V_74 -> V_83 )
continue;
F_51 ( & V_78 -> V_88 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_79 )
F_46 ( V_79 ) ;
V_79 = V_78 ;
V_86 = F_53 ( V_78 , & V_81 , V_77 ) ;
switch ( V_86 ) {
case - V_87 :
break;
case 0 :
F_47 ( V_78 , V_74 ) ;
V_79 = NULL ;
* V_75 = V_78 ;
F_33 ( L_7 ,
V_44 , V_78 , F_54 ( & V_78 -> V_88 ) ) ;
default:
goto V_90;
}
F_4 ( & V_6 -> V_12 ) ;
}
F_6 ( & V_6 -> V_12 ) ;
V_90:
if ( V_79 )
F_46 ( V_79 ) ;
F_33 ( L_8 , V_44 , V_86 ) ;
return V_86 ;
}
static bool F_55 ( struct V_1 * V_91 , struct V_1 * V_92 )
{
if ( V_91 -> V_83 != V_92 -> V_83 ) {
F_33 ( L_9 ,
V_44 , V_91 -> V_83 , V_92 -> V_83 ) ;
return false ;
}
F_33 ( L_10 ,
V_44 , V_91 -> V_83 , V_92 -> V_83 ) ;
return true ;
}
static bool
F_56 ( struct V_1 * V_91 , struct V_1 * V_92 )
{
struct V_93 * V_94 = V_91 -> V_36 ;
struct V_93 * V_95 = V_92 -> V_36 ;
if ( V_94 -> V_96 != V_95 -> V_96 ) {
F_33 ( L_11 ,
V_44 ) ;
return false ;
}
if ( V_94 -> V_97 != V_95 -> V_97 )
goto V_98;
if ( memcmp ( V_94 -> V_99 , V_95 -> V_99 , V_94 -> V_97 ) != 0 )
goto V_98;
F_33 ( L_12 , V_44 ) ;
return true ;
V_98:
F_33 ( L_13 ,
V_44 ) ;
return false ;
}
int F_57 ( struct V_1 * V_74 ,
struct V_1 * * V_75 ,
struct V_76 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_74 -> V_7 , V_8 ) ;
struct V_1 * V_78 , * V_79 = NULL ;
int V_86 = - V_87 ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (pos, &nn->nfs_client_list, cl_share_link) {
if ( V_78 -> V_57 > V_58 ) {
F_51 ( & V_78 -> V_88 ) ;
F_6 ( & V_6 -> V_12 ) ;
if ( V_79 )
F_46 ( V_79 ) ;
V_79 = V_78 ;
V_86 = F_52 ( V_78 ) ;
if ( V_86 == 0 ) {
F_58 ( V_78 ) ;
V_86 = F_59 ( V_78 ) ;
}
F_4 ( & V_6 -> V_12 ) ;
if ( V_86 < 0 )
continue;
}
if ( V_78 -> V_57 != V_58 )
continue;
if ( V_78 -> V_9 != V_74 -> V_9 )
continue;
if ( V_78 -> V_89 != V_74 -> V_89 )
continue;
if ( V_78 -> V_28 != V_74 -> V_28 )
continue;
if ( ! F_55 ( V_78 , V_74 ) )
continue;
if ( ! F_56 ( V_78 , V_74 ) )
continue;
F_51 ( & V_78 -> V_88 ) ;
* V_75 = V_78 ;
V_86 = 0 ;
F_33 ( L_7 ,
V_44 , V_78 , F_54 ( & V_78 -> V_88 ) ) ;
break;
}
F_6 ( & V_6 -> V_12 ) ;
F_33 ( L_8 , V_44 , V_86 ) ;
if ( V_79 )
F_46 ( V_79 ) ;
return V_86 ;
}
static void F_60 ( struct V_100 * V_101 )
{
F_61 ( V_101 ) ;
F_62 ( V_101 ) ;
F_63 ( V_101 ) ;
}
struct V_1 *
F_64 ( struct V_102 * V_102 , int V_103 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_102 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
V_2 = F_65 ( & V_6 -> V_13 , V_103 ) ;
if ( V_2 )
F_51 ( & V_2 -> V_88 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
static bool F_66 ( const struct V_67 * V_104 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_67 * V_105 = (struct V_67 * ) & V_2 -> V_106 ;
if ( ! ( V_2 -> V_57 == V_58 ||
V_2 -> V_57 == V_49 ) )
return false ;
F_67 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_28 != V_3 )
return false ;
if ( ! F_68 ( V_104 , V_105 ) )
return false ;
return true ;
}
struct V_1 *
F_69 ( struct V_102 * V_102 , const struct V_67 * V_104 ,
struct V_107 * V_108 , T_2 V_3 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_102 , V_8 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_50 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_66 ( V_104 , V_2 , V_3 ) == false )
continue;
if ( ! F_9 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_16 -> V_109 . V_110 ,
V_108 -> V_110 , V_111 ) != 0 )
continue;
F_51 ( & V_2 -> V_88 ) ;
F_6 ( & V_6 -> V_12 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_12 ) ;
return NULL ;
}
struct V_1 *
F_69 ( struct V_102 * V_102 , const struct V_67 * V_104 ,
struct V_107 * V_108 , T_2 V_3 )
{
return NULL ;
}
static int F_70 ( struct V_100 * V_101 ,
const char * V_112 ,
const struct V_67 * V_104 ,
const T_3 V_113 ,
const char * V_52 ,
T_1 V_53 ,
int V_114 , const struct V_50 * V_51 ,
T_2 V_3 , struct V_102 * V_102 )
{
struct V_17 V_18 = {
. V_112 = V_112 ,
. V_104 = V_104 ,
. V_113 = V_113 ,
. V_115 = & V_116 ,
. V_114 = V_114 ,
. V_3 = V_3 ,
. V_102 = V_102 ,
} ;
struct V_1 * V_2 ;
int error ;
F_33 ( L_14 ) ;
if ( V_101 -> V_117 & V_118 )
F_71 ( V_119 , & V_18 . V_120 ) ;
if ( V_101 -> V_121 & V_122 )
F_71 ( V_123 , & V_18 . V_120 ) ;
V_2 = F_72 ( & V_18 , V_51 , V_52 , V_53 ) ;
if ( F_14 ( V_2 ) ) {
error = F_73 ( V_2 ) ;
goto error;
}
F_71 ( V_124 , & V_2 -> V_32 ) ;
V_101 -> V_1 = V_2 ;
F_33 ( L_15 , V_2 ) ;
return 0 ;
error:
F_33 ( L_16 , error ) ;
return error ;
}
struct V_1 * F_74 ( struct V_1 * V_125 ,
const struct V_67 * V_126 , int V_127 ,
int V_128 , unsigned int V_129 , unsigned int V_130 )
{
struct V_17 V_18 = {
. V_104 = V_126 ,
. V_113 = V_127 ,
. V_115 = & V_116 ,
. V_114 = V_128 ,
. V_3 = V_125 -> V_28 ,
. V_102 = V_125 -> V_7 ,
} ;
struct V_50 V_131 ;
struct V_1 * V_2 ;
F_75 ( & V_131 , V_128 , V_129 , V_130 ) ;
V_2 = F_72 ( & V_18 , & V_131 , V_125 -> V_69 ,
V_125 -> V_41 -> V_132 -> V_133 ) ;
F_33 ( L_17 , V_44 , V_2 ) ;
return V_2 ;
}
static void F_76 ( struct V_100 * V_101 )
{
#ifdef V_45
struct V_46 * V_134 ;
T_2 V_135 ;
T_2 V_136 ;
if ( ! F_9 ( V_101 -> V_1 ) )
return;
V_134 = V_101 -> V_1 -> V_16 ;
V_135 = V_134 -> V_137 . V_138 - V_139 ;
V_136 = V_134 -> V_137 . V_140 - V_141 ;
if ( V_101 -> V_142 > V_135 )
V_101 -> V_142 = V_135 ;
if ( V_101 -> V_143 > V_136 )
V_101 -> V_143 = V_136 ;
#endif
}
static int F_77 ( struct V_100 * V_101 ,
struct V_144 * V_145 )
{
struct V_146 * V_147 ;
int error ;
if ( F_78 ( V_101 -> V_1 ) )
return - V_148 ;
V_147 = F_79 () ;
if ( V_147 == NULL )
return - V_48 ;
error = F_80 ( V_101 -> V_1 ) ;
if ( error < 0 )
goto V_90;
V_101 -> V_149 |= V_101 -> V_1 -> V_29 -> V_150 ;
if ( V_101 -> V_117 & V_151 )
V_101 -> V_149 &= ~ V_152 ;
if ( V_153 &&
V_101 -> V_154 -> V_132 -> V_133 == V_64 )
V_101 -> V_149 |= V_155 ;
error = F_81 ( V_101 , V_145 ) ;
if ( error < 0 )
goto V_90;
F_33 ( L_18 ,
( unsigned long long ) V_101 -> V_156 . V_157 ,
( unsigned long long ) V_101 -> V_156 . V_158 ) ;
F_33 ( L_19 , V_145 -> V_159 ) ;
F_76 ( V_101 ) ;
error = F_82 ( V_101 , V_145 , V_147 ) ;
if ( error < 0 )
goto V_90;
if ( V_101 -> V_160 == 0 || V_101 -> V_160 > V_161 )
V_101 -> V_160 = V_161 ;
F_83 ( V_101 ) ;
V_101 -> V_162 = V_163 ;
V_101 -> V_164 = F_60 ;
V_90:
F_84 ( V_147 ) ;
return error ;
}
static int F_85 ( struct V_100 * V_101 ,
const struct V_165 * V_110 )
{
struct V_50 V_51 ;
int error ;
F_33 ( L_20 ) ;
F_75 ( & V_51 , V_110 -> V_100 . V_166 ,
V_110 -> V_167 , V_110 -> V_168 ) ;
V_101 -> V_117 = V_110 -> V_117 ;
V_101 -> V_121 = V_110 -> V_121 ;
error = F_70 ( V_101 ,
V_110 -> V_100 . V_112 ,
( const struct V_67 * ) & V_110 -> V_100 . V_169 ,
V_110 -> V_100 . V_113 ,
V_110 -> V_170 ,
V_110 -> V_171 [ 0 ] ,
V_110 -> V_100 . V_166 ,
& V_51 ,
V_110 -> V_3 ,
V_110 -> V_102 ) ;
if ( error < 0 )
goto error;
if ( V_110 -> V_142 )
V_101 -> V_142 = F_86 ( V_110 -> V_142 , NULL ) ;
if ( V_110 -> V_143 )
V_101 -> V_143 = F_86 ( V_110 -> V_143 , NULL ) ;
V_101 -> V_172 = V_110 -> V_172 * V_173 ;
V_101 -> V_174 = V_110 -> V_174 * V_173 ;
V_101 -> V_175 = V_110 -> V_175 * V_173 ;
V_101 -> V_176 = V_110 -> V_176 * V_173 ;
V_101 -> V_177 = V_110 -> V_100 . V_177 ;
error = F_87 ( V_101 , & V_51 , V_110 -> V_171 [ 0 ] ) ;
error:
F_33 ( L_21 , error ) ;
return error ;
}
struct V_100 * F_88 ( struct V_178 * V_179 ,
struct V_180 * V_115 )
{
struct V_100 * V_101 ;
int error ;
F_33 ( L_22 ) ;
V_101 = F_89 () ;
if ( ! V_101 )
return F_19 ( - V_48 ) ;
error = F_85 ( V_101 , V_179 -> V_181 ) ;
if ( error < 0 )
goto error;
error = F_77 ( V_101 , V_179 -> V_145 ) ;
if ( error < 0 )
goto error;
F_33 ( L_23 , V_101 ) ;
return V_101 ;
error:
F_90 ( V_101 ) ;
F_33 ( L_24 , error ) ;
return F_19 ( error ) ;
}
struct V_100 * F_91 ( struct V_182 * V_110 ,
struct V_144 * V_145 )
{
struct V_1 * V_183 ;
struct V_100 * V_101 , * V_184 ;
int error ;
F_33 ( L_25 ) ;
V_101 = F_89 () ;
if ( ! V_101 )
return F_19 ( - V_48 ) ;
V_184 = F_92 ( V_110 -> V_185 ) ;
V_183 = V_184 -> V_1 ;
F_93 ( V_101 , V_184 ) ;
error = F_70 ( V_101 , V_110 -> V_112 ,
V_110 -> V_104 ,
V_110 -> V_113 ,
V_183 -> V_69 ,
V_110 -> V_186 ,
F_94 ( V_184 -> V_154 ) ,
V_184 -> V_154 -> V_187 ,
V_183 -> V_29 -> V_33 ,
V_183 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_87 ( V_101 , V_184 -> V_154 -> V_187 , V_110 -> V_186 ) ;
if ( error < 0 )
goto error;
error = F_77 ( V_101 , V_145 ) ;
if ( error < 0 )
goto error;
F_33 ( L_26 , V_101 ) ;
return V_101 ;
error:
F_90 ( V_101 ) ;
F_33 ( L_27 , error ) ;
return F_19 ( error ) ;
}
