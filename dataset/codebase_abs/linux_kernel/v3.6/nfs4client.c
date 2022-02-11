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
F_21 ( V_2 -> V_29 -> V_33 ) ;
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
int error ;
if ( V_2 -> V_55 == V_56 ) {
F_32 ( L_3 , V_2 ) ;
return V_2 ;
}
V_2 -> V_9 = & V_57 ;
F_33 ( V_58 , & V_2 -> V_59 ) ;
error = F_39 ( V_2 , V_50 , V_52 ) ;
if ( error < 0 )
goto error;
if ( V_51 == NULL ) {
struct V_60 V_61 ;
struct V_62 * V_63 = (struct V_62 * ) & V_61 ;
error = F_40 ( V_2 -> V_41 , V_63 , sizeof( V_61 ) ) ;
if ( error < 0 )
goto error;
error = F_41 ( V_63 , V_53 , sizeof( V_53 ) ) ;
if ( error < 0 )
goto error;
V_51 = ( const char * ) V_53 ;
}
F_42 ( V_2 -> V_64 , V_51 , sizeof( V_2 -> V_64 ) ) ;
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
F_37 ( V_2 , V_56 ) ;
return V_2 ;
error:
F_37 ( V_2 , error ) ;
F_44 ( V_2 ) ;
F_32 ( L_5 , error ) ;
return F_18 ( error ) ;
}
static void F_45 ( struct V_65 * V_66 )
{
F_46 ( V_66 ) ;
F_47 ( V_66 ) ;
F_48 ( V_66 ) ;
}
struct V_1 *
F_49 ( struct V_67 * V_67 , int V_68 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_67 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
V_2 = F_50 ( & V_6 -> V_12 , V_68 ) ;
if ( V_2 )
F_51 ( & V_2 -> V_69 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
static bool F_52 ( const struct V_62 * V_70 ,
struct V_1 * V_2 , T_2 V_3 )
{
struct V_62 * V_71 = (struct V_62 * ) & V_2 -> V_72 ;
if ( ! ( V_2 -> V_55 == V_56 ||
V_2 -> V_55 == V_48 ) )
return false ;
F_53 () ;
if ( V_2 -> V_9 -> V_10 != 4 ||
V_2 -> V_28 != V_3 )
return false ;
if ( ! F_54 ( V_70 , V_71 ) )
return false ;
return true ;
}
struct V_1 *
F_55 ( struct V_67 * V_67 , const struct V_62 * V_70 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = F_2 ( V_67 , V_8 ) ;
F_4 ( & V_6 -> V_15 ) ;
F_56 (clp, &nn->nfs_client_list, cl_share_link) {
if ( F_52 ( V_70 , V_2 , 1 ) == false )
continue;
if ( ! F_8 ( V_2 ) )
continue;
if ( memcmp ( V_2 -> V_18 -> V_75 . V_76 ,
V_74 -> V_76 , V_77 ) != 0 )
continue;
F_51 ( & V_2 -> V_69 ) ;
F_6 ( & V_6 -> V_15 ) ;
return V_2 ;
}
F_6 ( & V_6 -> V_15 ) ;
return NULL ;
}
struct V_1 *
F_55 ( struct V_67 * V_67 , const struct V_62 * V_70 ,
struct V_73 * V_74 )
{
return NULL ;
}
static int F_57 ( struct V_65 * V_66 ,
const char * V_78 ,
const struct V_62 * V_70 ,
const T_3 V_79 ,
const char * V_51 ,
T_1 V_52 ,
int V_80 , const struct V_49 * V_50 ,
T_2 V_3 , struct V_67 * V_67 )
{
struct V_19 V_20 = {
. V_78 = V_78 ,
. V_70 = V_70 ,
. V_79 = V_79 ,
. V_81 = & V_82 ,
. V_80 = V_80 ,
. V_3 = V_3 ,
. V_67 = V_67 ,
} ;
struct V_1 * V_2 ;
int error ;
F_32 ( L_6 ) ;
if ( V_66 -> V_83 & V_84 )
F_58 ( V_85 , & V_20 . V_86 ) ;
V_2 = F_59 ( & V_20 , V_50 , V_51 , V_52 ) ;
if ( F_13 ( V_2 ) ) {
error = F_60 ( V_2 ) ;
goto error;
}
F_58 ( V_87 , & V_2 -> V_32 ) ;
V_66 -> V_1 = V_2 ;
F_32 ( L_7 , V_2 ) ;
return 0 ;
error:
F_32 ( L_8 , error ) ;
return error ;
}
struct V_1 * F_61 ( struct V_1 * V_88 ,
const struct V_62 * V_89 , int V_90 ,
int V_91 , unsigned int V_92 , unsigned int V_93 )
{
struct V_19 V_20 = {
. V_70 = V_89 ,
. V_79 = V_90 ,
. V_81 = & V_82 ,
. V_80 = V_91 ,
. V_3 = V_88 -> V_28 ,
. V_67 = V_88 -> V_7 ,
} ;
struct V_49 V_94 ;
struct V_1 * V_2 ;
F_62 ( & V_94 , V_91 , V_92 , V_93 ) ;
V_2 = F_59 ( & V_20 , & V_94 , V_88 -> V_64 ,
V_88 -> V_41 -> V_95 -> V_96 ) ;
F_32 ( L_9 , V_44 , V_2 ) ;
return V_2 ;
}
static void F_63 ( struct V_65 * V_66 )
{
#ifdef V_45
struct V_46 * V_97 ;
T_2 V_98 ;
T_2 V_99 ;
if ( ! F_8 ( V_66 -> V_1 ) )
return;
V_97 = V_66 -> V_1 -> V_18 ;
V_98 = V_97 -> V_100 . V_101 - V_102 ;
V_99 = V_97 -> V_100 . V_103 - V_104 ;
if ( V_66 -> V_105 > V_98 )
V_66 -> V_105 = V_98 ;
if ( V_66 -> V_106 > V_99 )
V_66 -> V_106 = V_99 ;
#endif
}
static int F_64 ( struct V_65 * V_66 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 ;
int error ;
F_65 ( ! V_66 -> V_1 ) ;
F_65 ( ! V_66 -> V_1 -> V_9 ) ;
F_65 ( ! V_66 -> V_1 -> V_9 -> V_111 ) ;
if ( F_66 ( V_66 -> V_1 ) )
return - V_112 ;
V_110 = F_67 () ;
if ( V_110 == NULL )
return - V_14 ;
error = F_68 ( V_66 ) ;
if ( error < 0 )
goto V_113;
error = F_69 ( V_66 , V_108 ) ;
if ( error < 0 )
goto V_113;
F_32 ( L_10 ,
( unsigned long long ) V_66 -> V_114 . V_115 ,
( unsigned long long ) V_66 -> V_114 . V_116 ) ;
F_32 ( L_11 , V_108 -> V_117 ) ;
F_63 ( V_66 ) ;
error = F_70 ( V_66 , V_108 , V_110 ) ;
if ( error < 0 )
goto V_113;
if ( V_66 -> V_118 == 0 || V_66 -> V_118 > V_119 )
V_66 -> V_118 = V_119 ;
F_71 ( V_66 ) ;
V_66 -> V_120 = V_121 ;
V_66 -> V_122 = F_45 ;
V_113:
F_72 ( V_110 ) ;
return error ;
}
static int F_73 ( struct V_65 * V_66 ,
const struct V_123 * V_76 )
{
struct V_49 V_50 ;
int error ;
F_32 ( L_12 ) ;
F_62 ( & V_50 , V_76 -> V_65 . V_124 ,
V_76 -> V_125 , V_76 -> V_126 ) ;
V_66 -> V_83 = V_76 -> V_83 ;
V_66 -> V_127 |= V_128 | V_129 | V_130 ;
if ( ! ( V_76 -> V_83 & V_131 ) )
V_66 -> V_127 |= V_132 ;
V_66 -> V_133 = V_76 -> V_133 ;
error = F_57 ( V_66 ,
V_76 -> V_65 . V_78 ,
( const struct V_62 * ) & V_76 -> V_65 . V_134 ,
V_76 -> V_65 . V_79 ,
V_76 -> V_135 ,
V_76 -> V_136 [ 0 ] ,
V_76 -> V_65 . V_124 ,
& V_50 ,
V_76 -> V_3 ,
V_76 -> V_67 ) ;
if ( error < 0 )
goto error;
if ( V_137 && V_76 -> V_136 [ 0 ] == V_138 )
V_66 -> V_127 |= V_139 ;
if ( V_76 -> V_105 )
V_66 -> V_105 = F_74 ( V_76 -> V_105 , NULL ) ;
if ( V_76 -> V_106 )
V_66 -> V_106 = F_74 ( V_76 -> V_106 , NULL ) ;
V_66 -> V_140 = V_76 -> V_140 * V_141 ;
V_66 -> V_142 = V_76 -> V_142 * V_141 ;
V_66 -> V_143 = V_76 -> V_143 * V_141 ;
V_66 -> V_144 = V_76 -> V_144 * V_141 ;
V_66 -> V_145 = V_76 -> V_65 . V_145 ;
error = F_75 ( V_66 , & V_50 , V_76 -> V_136 [ 0 ] ) ;
error:
F_32 ( L_13 , error ) ;
return error ;
}
struct V_65 * F_76 ( struct V_146 * V_147 ,
struct V_148 * V_81 )
{
struct V_65 * V_66 ;
int error ;
F_32 ( L_14 ) ;
V_66 = F_77 () ;
if ( ! V_66 )
return F_18 ( - V_14 ) ;
error = F_73 ( V_66 , V_147 -> V_149 ) ;
if ( error < 0 )
goto error;
error = F_64 ( V_66 , V_147 -> V_108 ) ;
if ( error < 0 )
goto error;
F_32 ( L_15 , V_66 ) ;
return V_66 ;
error:
F_78 ( V_66 ) ;
F_32 ( L_16 , error ) ;
return F_18 ( error ) ;
}
struct V_65 * F_79 ( struct V_150 * V_76 ,
struct V_107 * V_108 )
{
struct V_1 * V_151 ;
struct V_65 * V_66 , * V_152 ;
int error ;
F_32 ( L_17 ) ;
V_66 = F_77 () ;
if ( ! V_66 )
return F_18 ( - V_14 ) ;
V_152 = F_80 ( V_76 -> V_153 ) ;
V_151 = V_152 -> V_1 ;
F_81 ( V_66 , V_152 ) ;
V_66 -> V_127 |= V_128 | V_129 ;
error = F_57 ( V_66 , V_76 -> V_78 ,
V_76 -> V_70 ,
V_76 -> V_79 ,
V_151 -> V_64 ,
V_76 -> V_154 ,
F_82 ( V_152 -> V_155 ) ,
V_152 -> V_155 -> V_156 ,
V_151 -> V_29 -> V_33 ,
V_151 -> V_7 ) ;
if ( error < 0 )
goto error;
error = F_75 ( V_66 , V_152 -> V_155 -> V_156 , V_76 -> V_154 ) ;
if ( error < 0 )
goto error;
error = F_64 ( V_66 , V_108 ) ;
if ( error < 0 )
goto error;
F_32 ( L_18 , V_66 ) ;
return V_66 ;
error:
F_78 ( V_66 ) ;
F_32 ( L_19 , error ) ;
return F_18 ( error ) ;
}
