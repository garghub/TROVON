static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 -> V_5 ) ;
}
static T_1 void F_3 ( struct V_6 * V_7 ,
const char * V_8 ,
const char * type ,
const void * V_9 )
{
if ( ! F_4 ( type , L_1 ) )
F_5 ( V_7 , L_2 , V_8 , F_6 ( * ( const bool * ) V_9 ) ) ;
else if ( ! F_4 ( type , L_3 ) )
F_5 ( V_7 , L_4 , V_8 , * ( const int * ) V_9 ) ;
else if ( ! F_4 ( type , L_5 ) )
F_5 ( V_7 , L_6 , V_8 , * ( const unsigned int * ) V_9 ) ;
else if ( ! F_4 ( type , L_7 ) )
F_5 ( V_7 , L_2 , V_8 , * ( const char * * ) V_9 ) ;
else
F_7 () ;
}
static int F_8 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_13 * V_14 = F_9 ( V_11 ) ;
F_5 ( V_7 , L_8 , F_10 ( V_11 ) ) ;
F_5 ( V_7 , L_9 , F_11 ( V_14 -> V_15 ) ) ;
F_5 ( V_7 , L_10 , F_12 ( V_11 ) ) ;
#define F_13 ( V_9 ) seq_printf(m, #x ": %s\n", yesno(info->x))
F_14 ( F_13 ) ;
#undef F_13
F_15 ( V_16 ) ;
#define F_16 ( T_2 , V_9 ) seq_print_param(m, #x, #T, &i915.x);
F_17 ( F_16 ) ;
#undef F_16
F_18 ( V_16 ) ;
return 0 ;
}
static char F_19 ( struct V_17 * V_18 )
{
return F_20 ( V_18 ) ? '*' : ' ' ;
}
static char F_21 ( struct V_17 * V_18 )
{
return V_18 -> V_19 ? 'p' : ' ' ;
}
static char F_22 ( struct V_17 * V_18 )
{
switch ( F_23 ( V_18 ) ) {
default:
case V_20 : return ' ' ;
case V_21 : return 'X' ;
case V_22 : return 'Y' ;
}
}
static char F_24 ( struct V_17 * V_18 )
{
return ! F_25 ( & V_18 -> V_23 ) ? 'g' : ' ' ;
}
static char F_26 ( struct V_17 * V_18 )
{
return V_18 -> V_24 . V_25 ? 'M' : ' ' ;
}
static T_3 F_27 ( struct V_17 * V_18 )
{
T_3 V_26 = 0 ;
struct V_27 * V_28 ;
F_28 (vma, &obj->vma_list, obj_link) {
if ( F_29 ( V_28 ) && F_30 ( & V_28 -> V_3 ) )
V_26 += V_28 -> V_3 . V_26 ;
}
return V_26 ;
}
static void
F_31 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_1 * V_11 = F_2 ( V_18 -> V_29 . V_5 ) ;
struct V_30 * V_31 ;
struct V_27 * V_28 ;
unsigned int V_32 ;
int V_33 = 0 ;
F_32 ( & V_18 -> V_29 . V_5 -> V_34 ) ;
F_5 ( V_7 , L_11 ,
& V_18 -> V_29 ,
F_19 ( V_18 ) ,
F_21 ( V_18 ) ,
F_22 ( V_18 ) ,
F_24 ( V_18 ) ,
F_26 ( V_18 ) ,
V_18 -> V_29 . V_26 / 1024 ,
V_18 -> V_29 . V_35 ,
V_18 -> V_29 . V_36 ,
F_33 ( V_11 , V_18 -> V_37 ) ,
V_18 -> V_24 . V_38 ? L_12 : L_13 ,
V_18 -> V_24 . V_39 == V_40 ? L_14 : L_13 ) ;
if ( V_18 -> V_29 . V_8 )
F_5 ( V_7 , L_15 , V_18 -> V_29 . V_8 ) ;
F_28 (vma, &obj->vma_list, obj_link) {
if ( F_34 ( V_28 ) )
V_33 ++ ;
}
F_5 ( V_7 , L_16 , V_33 ) ;
if ( V_18 -> V_19 )
F_5 ( V_7 , L_17 ) ;
F_28 (vma, &obj->vma_list, obj_link) {
if ( ! F_30 ( & V_28 -> V_3 ) )
continue;
F_5 ( V_7 , L_18 ,
F_29 ( V_28 ) ? L_19 : L_20 ,
V_28 -> V_3 . V_41 , V_28 -> V_3 . V_26 ) ;
if ( F_29 ( V_28 ) ) {
switch ( V_28 -> V_42 . type ) {
case V_43 :
F_35 ( V_7 , L_21 ) ;
break;
case V_44 :
F_5 ( V_7 , L_22 ,
V_28 -> V_42 . V_45 . V_46 << V_47 ,
V_28 -> V_42 . V_45 . V_26 << V_47 ) ;
break;
case V_48 :
F_5 ( V_7 , L_23 ,
V_28 -> V_42 . V_49 . V_50 [ 0 ] . V_51 ,
V_28 -> V_42 . V_49 . V_50 [ 0 ] . V_52 ,
V_28 -> V_42 . V_49 . V_50 [ 0 ] . V_53 ,
V_28 -> V_42 . V_49 . V_50 [ 0 ] . V_46 ,
V_28 -> V_42 . V_49 . V_50 [ 1 ] . V_51 ,
V_28 -> V_42 . V_49 . V_50 [ 1 ] . V_52 ,
V_28 -> V_42 . V_49 . V_50 [ 1 ] . V_53 ,
V_28 -> V_42 . V_49 . V_50 [ 1 ] . V_46 ) ;
break;
default:
F_36 ( V_28 -> V_42 . type ) ;
break;
}
}
if ( V_28 -> V_54 )
F_5 ( V_7 , L_24 ,
V_28 -> V_54 -> V_55 ,
F_37 ( & V_28 -> V_56 ) ? L_25 : L_13 ) ;
F_35 ( V_7 , L_26 ) ;
}
if ( V_18 -> V_57 )
F_5 ( V_7 , L_27 , V_18 -> V_57 -> V_41 ) ;
V_31 = F_38 ( V_18 ) ;
if ( V_31 )
F_5 ( V_7 , L_28 , V_31 -> V_8 ) ;
V_32 = F_39 ( & V_18 -> V_32 ) ;
if ( V_32 )
F_5 ( V_7 , L_29 , V_32 ) ;
}
static int F_40 ( const void * V_58 , const void * V_59 )
{
const struct V_17 * V_60 =
* ( const struct V_17 * * ) V_58 ;
const struct V_17 * V_61 =
* ( const struct V_17 * * ) V_59 ;
if ( V_60 -> V_57 -> V_41 < V_61 -> V_57 -> V_41 )
return - 1 ;
if ( V_60 -> V_57 -> V_41 > V_61 -> V_57 -> V_41 )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_17 * * V_64 ;
struct V_17 * V_18 ;
T_3 V_65 , V_66 ;
unsigned long V_67 , V_68 , V_69 ;
int V_70 ;
V_67 = F_42 ( V_11 -> V_24 . V_71 ) ;
V_64 = F_43 ( V_67 , sizeof( * V_64 ) ) ;
if ( ! V_64 )
return - V_72 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_73;
V_65 = V_66 = V_68 = 0 ;
F_28 (obj, &dev_priv->mm.bound_list, global_link) {
if ( V_68 == V_67 )
break;
if ( V_18 -> V_57 == NULL )
continue;
V_64 [ V_68 ++ ] = V_18 ;
V_65 += V_18 -> V_29 . V_26 ;
V_66 += F_27 ( V_18 ) ;
}
F_28 (obj, &dev_priv->mm.unbound_list, global_link) {
if ( V_68 == V_67 )
break;
if ( V_18 -> V_57 == NULL )
continue;
V_64 [ V_68 ++ ] = V_18 ;
V_65 += V_18 -> V_29 . V_26 ;
}
F_45 ( V_64 , V_68 , sizeof( * V_64 ) , F_40 , NULL ) ;
F_35 ( V_7 , L_30 ) ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
F_35 ( V_7 , L_31 ) ;
F_31 ( V_7 , V_64 [ V_69 ] ) ;
F_46 ( V_7 , '\n' ) ;
}
F_5 ( V_7 , L_32 ,
V_68 , V_65 , V_66 ) ;
F_47 ( & V_5 -> V_34 ) ;
V_73:
F_48 ( V_64 ) ;
return V_70 ;
}
static int F_49 ( int V_55 , void * V_74 , void * V_10 )
{
struct V_17 * V_18 = V_74 ;
struct V_75 * V_76 = V_10 ;
struct V_27 * V_28 ;
F_32 ( & V_18 -> V_29 . V_5 -> V_34 ) ;
V_76 -> V_68 ++ ;
V_76 -> V_67 += V_18 -> V_29 . V_26 ;
if ( ! V_18 -> V_77 )
V_76 -> V_78 += V_18 -> V_29 . V_26 ;
if ( V_18 -> V_29 . V_8 || V_18 -> V_29 . V_79 )
V_76 -> V_80 += V_18 -> V_29 . V_26 ;
F_28 (vma, &obj->vma_list, obj_link) {
if ( ! F_30 ( & V_28 -> V_3 ) )
continue;
if ( F_29 ( V_28 ) ) {
V_76 -> V_81 += V_28 -> V_3 . V_26 ;
} else {
struct V_82 * V_83 = F_50 ( V_28 -> V_84 ) ;
if ( V_83 -> V_29 . V_85 != V_76 -> V_86 )
continue;
}
if ( F_51 ( V_28 ) )
V_76 -> V_87 += V_28 -> V_3 . V_26 ;
else
V_76 -> V_88 += V_28 -> V_3 . V_26 ;
}
return 0 ;
}
static void F_52 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_17 * V_18 ;
struct V_75 V_76 ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
int V_90 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
F_53 (engine, dev_priv, id) {
for ( V_90 = 0 ; V_90 < F_54 ( V_31 -> V_91 . V_92 ) ; V_90 ++ ) {
F_28 (obj,
&engine->batch_pool.cache_list[j],
batch_pool_link)
F_49 ( 0 , V_18 , & V_76 ) ;
}
}
F_55 ( V_7 , L_33 , V_76 ) ;
}
static int F_56 ( int V_55 , void * V_74 , void * V_10 )
{
struct V_93 * V_94 = V_74 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < F_54 ( V_94 -> V_31 ) ; V_69 ++ ) {
if ( V_94 -> V_31 [ V_69 ] . V_95 )
F_49 ( 0 , V_94 -> V_31 [ V_69 ] . V_95 -> V_18 , V_10 ) ;
if ( V_94 -> V_31 [ V_69 ] . V_96 )
F_49 ( 0 , V_94 -> V_31 [ V_69 ] . V_96 -> V_28 -> V_18 , V_10 ) ;
}
return 0 ;
}
static void F_57 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_75 V_76 ;
struct V_97 * V_85 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
F_58 ( & V_5 -> V_34 ) ;
if ( V_11 -> V_98 )
F_56 ( 0 , V_11 -> V_98 , & V_76 ) ;
F_28 (file, &dev->filelist, lhead) {
struct V_99 * V_100 = V_85 -> V_101 ;
F_59 ( & V_100 -> V_102 , F_56 , & V_76 ) ;
}
F_47 ( & V_5 -> V_34 ) ;
F_55 ( V_7 , L_34 , V_76 ) ;
}
static int F_60 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_103 * V_104 = & V_11 -> V_104 ;
T_4 V_68 , V_105 , V_106 , V_107 ;
T_3 V_26 , V_108 , V_109 , V_110 ;
struct V_17 * V_18 ;
struct V_97 * V_85 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_5 ( V_7 , L_35 ,
V_11 -> V_24 . V_71 ,
V_11 -> V_24 . V_111 ) ;
V_26 = V_68 = 0 ;
V_108 = V_105 = 0 ;
V_109 = V_106 = 0 ;
F_28 (obj, &dev_priv->mm.unbound_list, global_link) {
V_26 += V_18 -> V_29 . V_26 ;
++ V_68 ;
if ( V_18 -> V_24 . V_39 == V_40 ) {
V_109 += V_18 -> V_29 . V_26 ;
++ V_106 ;
}
if ( V_18 -> V_24 . V_25 ) {
V_105 ++ ;
V_108 += V_18 -> V_29 . V_26 ;
}
}
F_5 ( V_7 , L_36 , V_68 , V_26 ) ;
V_26 = V_68 = V_110 = V_107 = 0 ;
F_28 (obj, &dev_priv->mm.bound_list, global_link) {
V_26 += V_18 -> V_29 . V_26 ;
++ V_68 ;
if ( V_18 -> V_19 ) {
V_110 += V_18 -> V_29 . V_26 ;
++ V_107 ;
}
if ( V_18 -> V_24 . V_39 == V_40 ) {
V_109 += V_18 -> V_29 . V_26 ;
++ V_106 ;
}
if ( V_18 -> V_24 . V_25 ) {
V_105 ++ ;
V_108 += V_18 -> V_29 . V_26 ;
}
}
F_5 ( V_7 , L_37 ,
V_68 , V_26 ) ;
F_5 ( V_7 , L_38 ,
V_106 , V_109 ) ;
F_5 ( V_7 , L_39 ,
V_105 , V_108 ) ;
F_5 ( V_7 , L_40 ,
V_107 , V_110 ) ;
F_5 ( V_7 , L_41 ,
V_104 -> V_29 . V_67 , V_104 -> V_112 ) ;
F_46 ( V_7 , '\n' ) ;
F_52 ( V_7 , V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
F_58 ( & V_5 -> V_113 ) ;
F_57 ( V_7 , V_11 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_75 V_76 ;
struct V_99 * V_86 = V_85 -> V_101 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
F_58 ( & V_5 -> V_34 ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_86 = V_85 -> V_101 ;
F_62 ( & V_85 -> V_118 ) ;
F_59 ( & V_85 -> V_119 , F_49 , & V_76 ) ;
F_63 ( & V_85 -> V_118 ) ;
V_115 = F_64 ( & V_86 -> V_24 . V_120 ,
struct V_114 ,
V_121 ) ;
F_65 () ;
V_117 = F_66 ( V_115 && V_115 -> V_94 -> V_122 ?
V_115 -> V_94 -> V_122 : V_85 -> V_122 ,
V_123 ) ;
F_55 ( V_7 , V_117 ? V_117 -> V_124 : L_42 , V_76 ) ;
F_67 () ;
F_47 ( & V_5 -> V_34 ) ;
}
F_47 ( & V_5 -> V_113 ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 , void * V_10 )
{
struct V_2 * V_3 = V_7 -> V_12 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
bool V_125 = ! ! V_3 -> V_126 -> V_10 ;
struct V_17 * V_18 ;
T_3 V_65 , V_66 ;
int V_68 , V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_65 = V_66 = V_68 = 0 ;
F_28 (obj, &dev_priv->mm.bound_list, global_link) {
if ( V_125 && ! V_18 -> V_19 )
continue;
F_35 ( V_7 , L_31 ) ;
F_31 ( V_7 , V_18 ) ;
F_46 ( V_7 , '\n' ) ;
V_65 += V_18 -> V_29 . V_26 ;
V_66 += F_27 ( V_18 ) ;
V_68 ++ ;
}
F_47 ( & V_5 -> V_34 ) ;
F_5 ( V_7 , L_43 ,
V_68 , V_65 , V_66 ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_127 * V_128 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_70 (dev, crtc) {
const char V_129 = F_71 ( V_128 -> V_129 ) ;
const char V_50 = F_72 ( V_128 -> V_50 ) ;
struct V_130 * V_131 ;
F_73 ( & V_5 -> V_132 ) ;
V_131 = V_128 -> V_133 ;
if ( V_131 == NULL ) {
F_5 ( V_7 , L_44 ,
V_129 , V_50 ) ;
} else {
T_4 V_134 ;
T_4 V_135 ;
V_134 = F_39 ( & V_131 -> V_134 ) ;
if ( V_134 ) {
F_5 ( V_7 , L_45 ,
V_129 , V_50 ) ;
} else {
F_5 ( V_7 , L_46 ,
V_129 , V_50 ) ;
}
if ( V_131 -> V_136 ) {
struct V_30 * V_31 = V_131 -> V_136 -> V_31 ;
F_5 ( V_7 , L_47 ,
V_31 -> V_8 ,
V_131 -> V_136 -> V_137 ,
F_74 ( V_31 ) ,
F_75 ( V_31 ) ,
F_76 ( V_131 -> V_136 ) ) ;
} else
F_5 ( V_7 , L_48 ) ;
F_5 ( V_7 , L_49 ,
V_131 -> V_138 ,
V_131 -> V_139 ,
F_77 ( V_128 ) ) ;
F_5 ( V_7 , L_50 , F_39 ( & V_131 -> V_134 ) ) ;
if ( F_10 ( V_11 ) >= 4 )
V_135 = F_78 ( F_79 ( F_80 ( V_128 -> V_50 ) ) ) ;
else
V_135 = F_79 ( F_81 ( V_128 -> V_50 ) ) ;
F_5 ( V_7 , L_51 , V_135 ) ;
if ( V_131 -> V_140 ) {
F_5 ( V_7 , L_52 , ( long ) V_131 -> V_141 ) ;
F_5 ( V_7 , L_53 , V_135 == V_131 -> V_141 ) ;
}
}
F_82 ( & V_5 -> V_132 ) ;
}
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_17 * V_18 ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
int V_67 = 0 ;
int V_70 , V_90 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_53 (engine, dev_priv, id) {
for ( V_90 = 0 ; V_90 < F_54 ( V_31 -> V_91 . V_92 ) ; V_90 ++ ) {
int V_68 ;
V_68 = 0 ;
F_28 (obj,
&engine->batch_pool.cache_list[j],
batch_pool_link)
V_68 ++ ;
F_5 ( V_7 , L_54 ,
V_31 -> V_8 , V_90 , V_68 ) ;
F_28 (obj,
&engine->batch_pool.cache_list[j],
batch_pool_link) {
F_35 ( V_7 , L_31 ) ;
F_31 ( V_7 , V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
V_67 += V_68 ;
}
}
F_5 ( V_7 , L_55 , V_67 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_84 ( struct V_6 * V_7 ,
struct V_114 * V_142 ,
const char * V_143 )
{
F_5 ( V_7 , L_56 , V_143 ,
V_142 -> V_137 , V_142 -> V_94 -> V_144 , V_142 -> V_54 . V_145 ,
V_142 -> V_146 . V_147 ,
F_85 ( V_148 - V_142 -> V_149 ) ,
V_142 -> V_150 -> V_151 -> V_8 ) ;
}
static int F_86 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_114 * V_152 ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
int V_70 , V_153 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_153 = 0 ;
F_53 (engine, dev_priv, id) {
int V_68 ;
V_68 = 0 ;
F_28 (req, &engine->timeline->requests, link)
V_68 ++ ;
if ( V_68 == 0 )
continue;
F_5 ( V_7 , L_57 , V_31 -> V_8 , V_68 ) ;
F_28 (req, &engine->timeline->requests, link)
F_84 ( V_7 , V_152 , L_58 ) ;
V_153 ++ ;
}
F_47 ( & V_5 -> V_34 ) ;
if ( V_153 == 0 )
F_35 ( V_7 , L_59 ) ;
return 0 ;
}
static void F_87 ( struct V_6 * V_7 ,
struct V_30 * V_31 )
{
struct V_154 * V_61 = & V_31 -> V_155 ;
struct V_156 * V_157 ;
F_5 ( V_7 , L_60 ,
V_31 -> V_8 , F_75 ( V_31 ) ) ;
F_73 ( & V_61 -> V_158 ) ;
for ( V_157 = F_88 ( & V_61 -> V_159 ) ; V_157 ; V_157 = F_89 ( V_157 ) ) {
struct V_160 * V_161 = F_90 ( V_157 , F_91 ( * V_161 ) , V_3 ) ;
F_5 ( V_7 , L_61 ,
V_31 -> V_8 , V_161 -> V_162 -> V_124 , V_161 -> V_162 -> V_122 , V_161 -> V_145 ) ;
}
F_82 ( & V_61 -> V_158 ) ;
}
static int F_92 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
F_53 (engine, dev_priv, id)
F_87 ( V_7 , V_31 ) ;
return 0 ;
}
static int F_93 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
int V_163 , V_129 ;
F_94 ( V_11 ) ;
if ( F_95 ( V_11 ) ) {
F_5 ( V_7 , L_62 ,
F_79 ( V_164 ) ) ;
F_5 ( V_7 , L_63 ,
F_79 ( V_165 ) ) ;
F_5 ( V_7 , L_64 ,
F_79 ( V_166 ) ) ;
F_5 ( V_7 , L_65 ,
F_79 ( V_167 ) ) ;
F_5 ( V_7 , L_66 ,
F_79 ( V_168 ) ) ;
F_96 (dev_priv, pipe) {
enum V_169 V_170 ;
V_170 = F_97 ( V_129 ) ;
if ( ! F_98 ( V_11 ,
V_170 ) ) {
F_5 ( V_7 , L_67 ,
F_71 ( V_129 ) ) ;
continue;
}
F_5 ( V_7 , L_68 ,
F_71 ( V_129 ) ,
F_79 ( F_99 ( V_129 ) ) ) ;
F_100 ( V_11 , V_170 ) ;
}
F_101 ( V_11 , V_171 ) ;
F_5 ( V_7 , L_69 ,
F_79 ( V_172 ) ) ;
F_5 ( V_7 , L_70 ,
F_79 ( V_173 ) ) ;
F_5 ( V_7 , L_71 ,
F_79 ( V_174 ) ) ;
F_100 ( V_11 , V_171 ) ;
for ( V_163 = 0 ; V_163 < 4 ; V_163 ++ ) {
F_5 ( V_7 , L_72 ,
V_163 , F_79 ( F_102 ( V_163 ) ) ) ;
F_5 ( V_7 , L_73 ,
V_163 , F_79 ( F_103 ( V_163 ) ) ) ;
F_5 ( V_7 , L_74 ,
V_163 , F_79 ( F_104 ( V_163 ) ) ) ;
}
F_5 ( V_7 , L_75 ,
F_79 ( V_175 ) ) ;
F_5 ( V_7 , L_76 ,
F_79 ( V_176 ) ) ;
F_5 ( V_7 , L_77 ,
F_79 ( V_177 ) ) ;
} else if ( F_10 ( V_11 ) >= 8 ) {
F_5 ( V_7 , L_62 ,
F_79 ( V_164 ) ) ;
for ( V_163 = 0 ; V_163 < 4 ; V_163 ++ ) {
F_5 ( V_7 , L_72 ,
V_163 , F_79 ( F_102 ( V_163 ) ) ) ;
F_5 ( V_7 , L_73 ,
V_163 , F_79 ( F_103 ( V_163 ) ) ) ;
F_5 ( V_7 , L_74 ,
V_163 , F_79 ( F_104 ( V_163 ) ) ) ;
}
F_96 (dev_priv, pipe) {
enum V_169 V_170 ;
V_170 = F_97 ( V_129 ) ;
if ( ! F_98 ( V_11 ,
V_170 ) ) {
F_5 ( V_7 , L_67 ,
F_71 ( V_129 ) ) ;
continue;
}
F_5 ( V_7 , L_78 ,
F_71 ( V_129 ) ,
F_79 ( F_105 ( V_129 ) ) ) ;
F_5 ( V_7 , L_79 ,
F_71 ( V_129 ) ,
F_79 ( F_106 ( V_129 ) ) ) ;
F_5 ( V_7 , L_80 ,
F_71 ( V_129 ) ,
F_79 ( F_107 ( V_129 ) ) ) ;
F_100 ( V_11 , V_170 ) ;
}
F_5 ( V_7 , L_81 ,
F_79 ( V_178 ) ) ;
F_5 ( V_7 , L_82 ,
F_79 ( V_179 ) ) ;
F_5 ( V_7 , L_83 ,
F_79 ( V_180 ) ) ;
F_5 ( V_7 , L_84 ,
F_79 ( V_181 ) ) ;
F_5 ( V_7 , L_85 ,
F_79 ( V_182 ) ) ;
F_5 ( V_7 , L_86 ,
F_79 ( V_183 ) ) ;
F_5 ( V_7 , L_75 ,
F_79 ( V_175 ) ) ;
F_5 ( V_7 , L_76 ,
F_79 ( V_176 ) ) ;
F_5 ( V_7 , L_77 ,
F_79 ( V_177 ) ) ;
} else if ( F_108 ( V_11 ) ) {
F_5 ( V_7 , L_63 ,
F_79 ( V_165 ) ) ;
F_5 ( V_7 , L_64 ,
F_79 ( V_166 ) ) ;
F_5 ( V_7 , L_65 ,
F_79 ( V_167 ) ) ;
F_5 ( V_7 , L_66 ,
F_79 ( V_168 ) ) ;
F_96 (dev_priv, pipe) {
enum V_169 V_170 ;
V_170 = F_97 ( V_129 ) ;
if ( ! F_98 ( V_11 ,
V_170 ) ) {
F_5 ( V_7 , L_67 ,
F_71 ( V_129 ) ) ;
continue;
}
F_5 ( V_7 , L_68 ,
F_71 ( V_129 ) ,
F_79 ( F_99 ( V_129 ) ) ) ;
F_100 ( V_11 , V_170 ) ;
}
F_5 ( V_7 , L_87 ,
F_79 ( V_184 ) ) ;
F_5 ( V_7 , L_88 ,
F_79 ( V_185 ) ) ;
F_5 ( V_7 , L_89 ,
F_79 ( V_186 ) ) ;
F_5 ( V_7 , L_90 ,
F_79 ( V_187 ) ) ;
F_5 ( V_7 , L_91 ,
F_79 ( V_188 ) ) ;
F_5 ( V_7 , L_92 ,
F_79 ( V_189 ) ) ;
F_5 ( V_7 , L_93 ,
F_79 ( V_190 ) ) ;
F_5 ( V_7 , L_69 ,
F_79 ( V_172 ) ) ;
F_5 ( V_7 , L_70 ,
F_79 ( V_173 ) ) ;
F_5 ( V_7 , L_71 ,
F_79 ( V_174 ) ) ;
} else if ( ! F_109 ( V_11 ) ) {
F_5 ( V_7 , L_94 ,
F_79 ( V_191 ) ) ;
F_5 ( V_7 , L_95 ,
F_79 ( V_192 ) ) ;
F_5 ( V_7 , L_96 ,
F_79 ( V_193 ) ) ;
F_96 (dev_priv, pipe)
F_5 ( V_7 , L_97 ,
F_71 ( V_129 ) ,
F_79 ( F_99 ( V_129 ) ) ) ;
} else {
F_5 ( V_7 , L_98 ,
F_79 ( V_194 ) ) ;
F_5 ( V_7 , L_99 ,
F_79 ( V_195 ) ) ;
F_5 ( V_7 , L_100 ,
F_79 ( V_196 ) ) ;
F_5 ( V_7 , L_101 ,
F_79 ( V_197 ) ) ;
F_5 ( V_7 , L_102 ,
F_79 ( V_198 ) ) ;
F_5 ( V_7 , L_103 ,
F_79 ( V_199 ) ) ;
F_5 ( V_7 , L_104 ,
F_79 ( V_185 ) ) ;
F_5 ( V_7 , L_105 ,
F_79 ( V_186 ) ) ;
F_5 ( V_7 , L_106 ,
F_79 ( V_187 ) ) ;
}
F_53 (engine, dev_priv, id) {
if ( F_10 ( V_11 ) >= 6 ) {
F_5 ( V_7 ,
L_107 ,
V_31 -> V_8 , F_110 ( V_31 ) ) ;
}
F_87 ( V_7 , V_31 ) ;
}
F_111 ( V_11 ) ;
return 0 ;
}
static int F_112 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_163 , V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_5 ( V_7 , L_108 , V_11 -> V_200 ) ;
for ( V_163 = 0 ; V_163 < V_11 -> V_200 ; V_163 ++ ) {
struct V_27 * V_28 = V_11 -> V_201 [ V_163 ] . V_28 ;
F_5 ( V_7 , L_109 ,
V_163 , V_11 -> V_201 [ V_163 ] . V_33 ) ;
if ( ! V_28 )
F_35 ( V_7 , L_110 ) ;
else
F_31 ( V_7 , V_28 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static T_5 F_113 ( struct V_85 * V_85 , char T_6 * V_202 ,
T_7 V_68 , T_8 * V_203 )
{
struct V_204 * error = V_85 -> V_205 ;
struct V_206 V_207 ;
T_5 V_70 ;
T_8 V_208 ;
if ( ! error )
return 0 ;
V_70 = F_114 ( & V_207 , error -> V_209 , V_68 , * V_203 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_115 ( & V_207 , error ) ;
if ( V_70 )
goto V_73;
V_208 = 0 ;
V_70 = F_116 ( V_202 , V_68 , & V_208 , V_207 . V_210 , V_207 . V_211 ) ;
if ( V_70 < 0 )
goto V_73;
* V_203 = V_207 . V_41 + V_70 ;
V_73:
F_117 ( & V_207 ) ;
return V_70 ;
}
static int F_118 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
F_119 ( V_85 -> V_205 ) ;
return 0 ;
}
static int F_120 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
struct V_1 * V_209 = V_212 -> V_213 ;
struct V_204 * V_214 ;
F_94 ( V_209 ) ;
V_214 = F_121 ( V_209 ) ;
F_111 ( V_209 ) ;
if ( ! V_214 )
return - V_72 ;
V_85 -> V_205 = V_214 ;
return 0 ;
}
static T_5
F_122 ( struct V_85 * V_215 ,
const char T_6 * V_202 ,
T_7 V_216 ,
T_8 * V_217 )
{
struct V_204 * error = V_215 -> V_205 ;
if ( ! error )
return 0 ;
F_123 ( L_111 ) ;
F_124 ( error -> V_209 ) ;
return V_216 ;
}
static int F_125 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
V_85 -> V_205 = F_126 ( V_212 -> V_213 ) ;
return 0 ;
}
static int
F_127 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_11 = V_10 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_128 ( V_5 , V_218 ) ;
F_47 ( & V_5 -> V_34 ) ;
return V_70 ;
}
static int F_129 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_70 = 0 ;
F_94 ( V_11 ) ;
if ( F_130 ( V_11 ) ) {
T_9 V_220 = F_131 ( V_221 ) ;
T_9 V_222 = F_131 ( V_223 ) ;
F_5 ( V_7 , L_112 , ( V_220 >> 8 ) & 0xf ) ;
F_5 ( V_7 , L_113 , V_220 & 0x3f ) ;
F_5 ( V_7 , L_114 , ( V_222 & V_224 ) >>
V_225 ) ;
F_5 ( V_7 , L_115 ,
( V_222 & V_226 ) >> V_227 ) ;
} else if ( F_108 ( V_11 ) || F_95 ( V_11 ) ) {
T_4 V_228 ;
F_58 ( & V_11 -> V_229 . V_230 ) ;
V_228 = F_132 ( V_11 , V_231 ) ;
F_5 ( V_7 , L_116 , V_228 ) ;
F_5 ( V_7 , L_117 , V_11 -> V_232 ) ;
F_5 ( V_7 , L_118 ,
F_133 ( V_11 , ( V_228 >> 8 ) & 0xff ) ) ;
F_5 ( V_7 , L_119 ,
F_133 ( V_11 , V_11 -> V_229 . V_233 ) ) ;
F_5 ( V_7 , L_120 ,
F_133 ( V_11 , V_11 -> V_229 . V_234 ) ) ;
F_5 ( V_7 , L_121 ,
F_133 ( V_11 , V_11 -> V_229 . V_235 ) ) ;
F_5 ( V_7 , L_122 ,
F_133 ( V_11 , V_11 -> V_229 . V_236 ) ) ;
F_5 ( V_7 ,
L_123 ,
F_133 ( V_11 , V_11 -> V_229 . V_237 ) ) ;
F_47 ( & V_11 -> V_229 . V_230 ) ;
} else if ( F_10 ( V_11 ) >= 6 ) {
T_4 V_238 ;
T_4 V_239 ;
T_4 V_240 ;
T_4 V_241 , V_242 , V_243 ;
T_4 V_244 , V_245 , V_246 ;
T_4 V_247 , V_248 , V_249 ;
T_4 V_250 , V_251 , V_252 ;
T_4 V_253 , V_254 , V_255 , V_256 , V_257 ;
int V_234 ;
V_238 = F_79 ( V_258 ) ;
if ( F_134 ( V_11 ) ) {
V_240 = F_79 ( V_259 ) ;
V_239 = F_79 ( V_260 ) ;
} else {
V_240 = F_79 ( V_261 ) ;
V_239 = F_79 ( V_262 ) ;
}
F_135 ( V_11 , V_263 ) ;
V_246 = F_79 ( V_264 ) ;
if ( F_136 ( V_11 ) )
V_246 >>= 23 ;
else {
V_246 &= ~ V_265 ;
if ( F_137 ( V_11 ) || F_138 ( V_11 ) )
V_246 >>= 24 ;
else
V_246 >>= 25 ;
}
V_246 = F_133 ( V_11 , V_246 ) ;
V_241 = F_79 ( V_266 ) ;
V_242 = F_79 ( V_267 ) ;
V_243 = F_79 ( V_268 ) ;
V_244 = F_79 ( V_269 ) ;
V_247 = F_79 ( V_270 ) & V_271 ;
V_248 = F_79 ( V_272 ) & V_273 ;
V_249 = F_79 ( V_274 ) & V_273 ;
V_250 = F_79 ( V_275 ) & V_276 ;
V_251 = F_79 ( V_277 ) & V_273 ;
V_252 = F_79 ( V_278 ) & V_273 ;
if ( F_136 ( V_11 ) )
V_245 = ( V_244 & V_279 ) >> V_280 ;
else if ( F_137 ( V_11 ) || F_138 ( V_11 ) )
V_245 = ( V_244 & V_281 ) >> V_282 ;
else
V_245 = ( V_244 & V_283 ) >> V_284 ;
V_245 = F_133 ( V_11 , V_245 ) ;
F_139 ( V_11 , V_263 ) ;
if ( F_140 ( V_11 ) || F_141 ( V_11 ) ) {
V_253 = F_79 ( V_188 ) ;
V_254 = F_79 ( V_190 ) ;
V_255 = F_79 ( V_285 ) ;
V_256 = F_79 ( V_189 ) ;
V_257 = F_79 ( V_286 ) ;
} else {
V_253 = F_79 ( F_104 ( 2 ) ) ;
V_254 = F_79 ( F_102 ( 2 ) ) ;
V_255 = F_79 ( F_142 ( 2 ) ) ;
V_256 = F_79 ( F_103 ( 2 ) ) ;
V_257 = F_79 ( V_286 ) ;
}
F_5 ( V_7 , L_124 ,
V_253 , V_254 , V_255 , V_256 , V_257 ) ;
F_5 ( V_7 , L_125 ,
V_11 -> V_229 . V_287 ) ;
F_5 ( V_7 , L_126 , V_239 ) ;
F_5 ( V_7 , L_127 ,
( V_239 & ( F_136 ( V_11 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_5 ( V_7 , L_128 ,
V_239 & 0xff ) ;
F_5 ( V_7 , L_129 ,
V_238 & 0xff ) ;
F_5 ( V_7 , L_130 , V_244 ) ;
F_5 ( V_7 , L_131 , V_241 ) ;
F_5 ( V_7 , L_132 , V_242 ) ;
F_5 ( V_7 , L_133 , V_243 ) ;
F_5 ( V_7 , L_134 , V_246 ) ;
F_5 ( V_7 , L_135 , V_245 ) ;
F_5 ( V_7 , L_136 ,
V_247 , F_143 ( V_11 , V_247 ) ) ;
F_5 ( V_7 , L_137 ,
V_248 , F_143 ( V_11 , V_248 ) ) ;
F_5 ( V_7 , L_138 ,
V_249 , F_143 ( V_11 , V_249 ) ) ;
F_5 ( V_7 , L_139 ,
V_11 -> V_229 . V_288 ) ;
F_5 ( V_7 , L_140 ,
V_250 , F_143 ( V_11 , V_250 ) ) ;
F_5 ( V_7 , L_141 ,
V_251 , F_143 ( V_11 , V_251 ) ) ;
F_5 ( V_7 , L_142 ,
V_252 , F_143 ( V_11 , V_252 ) ) ;
F_5 ( V_7 , L_143 ,
V_11 -> V_229 . V_289 ) ;
V_234 = ( F_134 ( V_11 ) ? V_240 >> 0 :
V_240 >> 16 ) & 0xff ;
V_234 *= ( F_144 ( V_11 ) ? V_290 : 1 ) ;
F_5 ( V_7 , L_144 ,
F_133 ( V_11 , V_234 ) ) ;
V_234 = ( V_240 & 0xff00 ) >> 8 ;
V_234 *= ( F_144 ( V_11 ) ? V_290 : 1 ) ;
F_5 ( V_7 , L_145 ,
F_133 ( V_11 , V_234 ) ) ;
V_234 = ( F_134 ( V_11 ) ? V_240 >> 16 :
V_240 >> 0 ) & 0xff ;
V_234 *= ( F_144 ( V_11 ) ? V_290 : 1 ) ;
F_5 ( V_7 , L_146 ,
F_133 ( V_11 , V_234 ) ) ;
F_5 ( V_7 , L_147 ,
F_133 ( V_11 , V_11 -> V_229 . V_234 ) ) ;
F_5 ( V_7 , L_148 ,
F_133 ( V_11 , V_11 -> V_229 . V_233 ) ) ;
F_5 ( V_7 , L_149 , V_245 ) ;
F_5 ( V_7 , L_150 ,
F_133 ( V_11 , V_11 -> V_229 . V_236 ) ) ;
F_5 ( V_7 , L_151 ,
F_133 ( V_11 , V_11 -> V_229 . V_235 ) ) ;
F_5 ( V_7 , L_152 ,
F_133 ( V_11 , V_11 -> V_229 . V_291 ) ) ;
F_5 ( V_7 , L_153 ,
F_133 ( V_11 , V_11 -> V_229 . V_234 ) ) ;
F_5 ( V_7 ,
L_123 ,
F_133 ( V_11 , V_11 -> V_229 . V_237 ) ) ;
} else {
F_35 ( V_7 , L_154 ) ;
}
F_5 ( V_7 , L_155 , V_11 -> V_292 . V_293 . V_292 ) ;
F_5 ( V_7 , L_156 , V_11 -> V_294 ) ;
F_5 ( V_7 , L_157 , V_11 -> V_295 ) ;
F_111 ( V_11 ) ;
return V_70 ;
}
static void F_145 ( struct V_1 * V_11 ,
struct V_6 * V_7 ,
struct V_296 * V_297 )
{
int V_298 ;
int V_299 ;
F_5 ( V_7 , L_158 ,
V_297 -> V_297 ) ;
if ( F_10 ( V_11 ) <= 3 )
return;
F_5 ( V_7 , L_159 ,
V_297 -> V_300 ) ;
if ( F_10 ( V_11 ) <= 6 )
return;
F_146 (dev_priv, slice, subslice)
F_5 ( V_7 , L_160 ,
V_298 , V_299 , V_297 -> V_301 [ V_298 ] [ V_299 ] ) ;
F_146 (dev_priv, slice, subslice)
F_5 ( V_7 , L_161 ,
V_298 , V_299 , V_297 -> V_302 [ V_298 ] [ V_299 ] ) ;
}
static int F_147 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
T_3 V_303 [ V_304 ] ;
T_4 V_145 [ V_304 ] ;
struct V_296 V_297 ;
enum V_89 V_55 ;
if ( F_148 ( V_305 , & V_11 -> V_306 . V_307 ) )
F_35 ( V_7 , L_162 ) ;
if ( F_148 ( V_308 , & V_11 -> V_306 . V_307 ) )
F_35 ( V_7 , L_163 ) ;
if ( F_148 ( V_309 , & V_11 -> V_306 . V_307 ) )
F_35 ( V_7 , L_164 ) ;
if ( F_149 ( & V_11 -> V_306 . V_310 ) )
F_35 ( V_7 , L_165 ) ;
if ( F_149 ( & V_11 -> V_306 . V_311 ) )
F_35 ( V_7 , L_166 ) ;
if ( ! V_209 . V_312 ) {
F_35 ( V_7 , L_167 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_53 (engine, dev_priv, id) {
V_303 [ V_55 ] = F_150 ( V_31 ) ;
V_145 [ V_55 ] = F_75 ( V_31 ) ;
}
F_151 ( V_11 -> V_31 [ V_313 ] , & V_297 ) ;
F_111 ( V_11 ) ;
if ( F_152 ( & V_11 -> V_306 . V_314 . V_315 ) )
F_5 ( V_7 , L_168 ,
F_85 ( V_11 -> V_306 . V_314 . V_315 . V_316 -
V_148 ) ) ;
else if ( F_153 ( & V_11 -> V_306 . V_314 ) )
F_35 ( V_7 , L_169 ) ;
else
F_35 ( V_7 , L_170 ) ;
F_5 ( V_7 , L_171 , F_6 ( V_11 -> V_317 . V_318 ) ) ;
F_53 (engine, dev_priv, id) {
struct V_154 * V_61 = & V_31 -> V_155 ;
struct V_156 * V_157 ;
F_5 ( V_7 , L_172 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_173 ,
V_31 -> V_319 . V_145 , V_145 [ V_55 ] ,
F_74 ( V_31 ) ,
V_31 -> V_150 -> V_320 ) ;
F_5 ( V_7 , L_174 ,
F_6 ( F_154 ( V_31 ) ) ,
F_6 ( F_148 ( V_31 -> V_55 ,
& V_11 -> V_306 . V_321 ) ) ,
F_6 ( V_31 -> V_319 . V_322 ) ) ;
F_73 ( & V_61 -> V_158 ) ;
for ( V_157 = F_88 ( & V_61 -> V_159 ) ; V_157 ; V_157 = F_89 ( V_157 ) ) {
struct V_160 * V_161 = F_90 ( V_157 , F_91 ( * V_161 ) , V_3 ) ;
F_5 ( V_7 , L_175 ,
V_161 -> V_162 -> V_124 , V_161 -> V_162 -> V_122 , V_161 -> V_145 ) ;
}
F_82 ( & V_61 -> V_158 ) ;
F_5 ( V_7 , L_176 ,
( long long ) V_31 -> V_319 . V_303 ,
( long long ) V_303 [ V_55 ] ) ;
F_5 ( V_7 , L_177 ,
F_155 ( V_31 -> V_319 . V_323 ) ,
V_31 -> V_319 . V_323 ,
F_85 ( V_148 -
V_31 -> V_319 . V_324 ) ) ;
if ( V_31 -> V_55 == V_313 ) {
F_35 ( V_7 , L_178 ) ;
F_145 ( V_11 , V_7 , & V_297 ) ;
F_35 ( V_7 , L_179 ) ;
F_145 ( V_11 , V_7 ,
& V_31 -> V_319 . V_297 ) ;
}
}
return 0 ;
}
static int F_156 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_325 , V_326 ;
T_9 V_327 ;
V_325 = F_79 ( V_328 ) ;
V_326 = F_79 ( V_329 ) ;
V_327 = F_131 ( V_330 ) ;
F_5 ( V_7 , L_180 , F_6 ( V_325 & V_331 ) ) ;
F_5 ( V_7 , L_181 ,
( V_325 & V_332 ) >>
V_333 ) ;
F_5 ( V_7 , L_182 ,
F_6 ( V_325 & V_334 ) ) ;
F_5 ( V_7 , L_183 ,
F_6 ( V_325 & V_335 ) ) ;
F_5 ( V_7 , L_184 ,
F_6 ( V_325 & V_336 ) ) ;
F_5 ( V_7 , L_185 ,
( V_325 & V_337 ) >> V_338 ) ;
F_5 ( V_7 , L_186 ,
( V_325 & V_339 ) >> V_340 ) ;
F_5 ( V_7 , L_187 , ( V_325 & V_341 ) ) ;
F_5 ( V_7 , L_188 , ( V_327 & 0x3f ) ) ;
F_5 ( V_7 , L_189 , ( ( V_327 >> 8 ) & 0x3f ) ) ;
F_5 ( V_7 , L_190 ,
F_6 ( ! ( V_326 & V_342 ) ) ) ;
F_35 ( V_7 , L_191 ) ;
switch ( V_326 & V_343 ) {
case V_344 :
F_35 ( V_7 , L_192 ) ;
break;
case V_345 :
F_35 ( V_7 , L_193 ) ;
break;
case V_346 :
F_35 ( V_7 , L_194 ) ;
break;
case V_347 :
F_35 ( V_7 , L_195 ) ;
break;
case V_348 :
F_35 ( V_7 , L_196 ) ;
break;
case V_349 :
F_35 ( V_7 , L_197 ) ;
break;
default:
F_35 ( V_7 , L_198 ) ;
break;
}
return 0 ;
}
static int F_157 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_209 = F_1 ( V_7 -> V_12 ) ;
struct V_350 * V_351 ;
unsigned int V_208 ;
F_158 (fw_domain, i915, tmp)
F_5 ( V_7 , L_199 ,
F_159 ( V_351 -> V_55 ) ,
F_42 ( V_351 -> V_352 ) ) ;
return 0 ;
}
static void F_160 ( struct V_6 * V_7 ,
const char * V_353 ,
const T_10 V_354 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_5 ( V_7 , L_200 ,
V_353 , F_79 ( V_354 ) ,
F_161 ( V_11 , V_354 ) ) ;
}
static int F_162 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_355 , V_356 , V_357 ;
V_357 = F_79 ( V_358 ) ;
V_355 = F_79 ( V_266 ) ;
V_356 = F_79 ( V_359 ) ;
F_5 ( V_7 , L_201 ,
F_6 ( V_355 & V_360 ) ) ;
F_5 ( V_7 , L_202 ,
F_6 ( V_355 & V_361 ) ) ;
F_5 ( V_7 , L_182 ,
F_6 ( V_355 & V_361 ) ) ;
F_5 ( V_7 , L_183 ,
F_6 ( ( V_355 & V_362 ) ==
V_363 ) ) ;
F_5 ( V_7 , L_203 ,
F_6 ( V_356 & ( V_364 |
F_163 ( 1 ) ) ) ) ;
F_5 ( V_7 , L_204 ,
( V_357 & V_365 ) ? L_205 : L_206 ) ;
F_5 ( V_7 , L_207 ,
( V_357 & V_366 ) ? L_205 : L_206 ) ;
F_160 ( V_7 , L_208 , V_367 ) ;
F_160 ( V_7 , L_209 , V_368 ) ;
return F_157 ( V_7 , NULL ) ;
}
static int F_164 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_355 , V_369 , V_356 , V_370 = 0 ;
T_4 V_371 = 0 , V_372 = 0 ;
unsigned V_373 ;
int V_68 = 0 ;
V_373 = F_42 ( V_11 -> V_374 . V_351 [ V_375 ] . V_352 ) ;
if ( V_373 ) {
F_35 ( V_7 , L_210
L_211 ) ;
} else {
while ( V_68 ++ < 50 && ( F_165 ( V_376 ) & 1 ) )
F_166 ( 10 ) ;
F_5 ( V_7 , L_212 , F_6 ( V_68 < 51 ) ) ;
}
V_369 = F_167 ( V_377 ) ;
F_168 ( false , V_377 , V_369 , 4 , true ) ;
V_355 = F_79 ( V_266 ) ;
V_356 = F_79 ( V_359 ) ;
if ( F_10 ( V_11 ) >= 9 ) {
V_371 = F_79 ( V_378 ) ;
V_372 = F_79 ( V_379 ) ;
}
F_58 ( & V_11 -> V_229 . V_230 ) ;
F_169 ( V_11 , V_380 , & V_370 ) ;
F_47 ( & V_11 -> V_229 . V_230 ) ;
F_5 ( V_7 , L_201 ,
F_6 ( V_355 & V_360 ) ) ;
F_5 ( V_7 , L_182 ,
F_6 ( V_355 & V_361 ) ) ;
F_5 ( V_7 , L_183 ,
F_6 ( ( V_355 & V_362 ) ==
V_363 ) ) ;
F_5 ( V_7 , L_213 ,
F_6 ( V_356 & V_381 ) ) ;
F_5 ( V_7 , L_203 ,
F_6 ( V_356 & V_382 ) ) ;
if ( F_10 ( V_11 ) >= 9 ) {
F_5 ( V_7 , L_214 ,
F_6 ( V_371 & V_383 ) ) ;
F_5 ( V_7 , L_215 ,
F_6 ( V_371 & V_384 ) ) ;
}
F_5 ( V_7 , L_216 ,
F_6 ( V_356 & V_385 ) ) ;
F_5 ( V_7 , L_217 ,
F_6 ( V_356 & V_386 ) ) ;
F_35 ( V_7 , L_218 ) ;
switch ( V_369 & V_387 ) {
case V_388 :
if ( V_369 & V_389 )
F_35 ( V_7 , L_219 ) ;
else
F_35 ( V_7 , L_192 ) ;
break;
case V_390 :
F_35 ( V_7 , L_220 ) ;
break;
case V_391 :
F_35 ( V_7 , L_221 ) ;
break;
case V_392 :
F_35 ( V_7 , L_222 ) ;
break;
default:
F_35 ( V_7 , L_223 ) ;
break;
}
F_5 ( V_7 , L_224 ,
F_6 ( V_369 & V_389 ) ) ;
if ( F_10 ( V_11 ) >= 9 ) {
F_5 ( V_7 , L_204 ,
( V_372 &
V_393 ) ? L_205 : L_206 ) ;
F_5 ( V_7 , L_207 ,
( V_372 &
V_394 ) ? L_205 : L_206 ) ;
}
F_160 ( V_7 , L_225 ,
V_395 ) ;
F_160 ( V_7 , L_226 , V_396 ) ;
F_160 ( V_7 , L_227 , V_397 ) ;
F_160 ( V_7 , L_228 , V_398 ) ;
F_5 ( V_7 , L_229 ,
F_170 ( ( ( V_370 >> 0 ) & 0xff ) ) ) ;
F_5 ( V_7 , L_230 ,
F_170 ( ( ( V_370 >> 8 ) & 0xff ) ) ) ;
F_5 ( V_7 , L_231 ,
F_170 ( ( ( V_370 >> 16 ) & 0xff ) ) ) ;
return F_157 ( V_7 , NULL ) ;
}
static int F_171 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_399 ;
F_94 ( V_11 ) ;
if ( F_108 ( V_11 ) || F_95 ( V_11 ) )
V_399 = F_162 ( V_7 ) ;
else if ( F_10 ( V_11 ) >= 6 )
V_399 = F_164 ( V_7 ) ;
else
V_399 = F_156 ( V_7 ) ;
F_111 ( V_11 ) ;
return V_399 ;
}
static int F_172 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_5 ( V_7 , L_232 ,
V_11 -> V_400 . V_401 ) ;
F_5 ( V_7 , L_233 ,
V_11 -> V_400 . V_402 ) ;
return 0 ;
}
static int F_173 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
if ( ! F_174 ( V_11 ) ) {
F_35 ( V_7 , L_234 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_58 ( & V_11 -> V_403 . V_404 ) ;
if ( F_175 ( V_11 ) )
F_35 ( V_7 , L_235 ) ;
else
F_5 ( V_7 , L_236 ,
V_11 -> V_403 . V_405 ) ;
if ( F_175 ( V_11 ) && F_10 ( V_11 ) >= 7 ) {
T_11 V_406 = F_10 ( V_11 ) >= 8 ?
V_407 :
V_408 ;
F_5 ( V_7 , L_237 ,
F_6 ( F_79 ( V_409 ) & V_406 ) ) ;
}
F_47 ( & V_11 -> V_403 . V_404 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_176 ( void * V_10 , T_3 * V_218 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 7 || ! F_174 ( V_11 ) )
return - V_410 ;
* V_218 = V_11 -> V_403 . V_411 ;
return 0 ;
}
static int F_177 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_354 ;
if ( F_10 ( V_11 ) < 7 || ! F_174 ( V_11 ) )
return - V_410 ;
F_58 ( & V_11 -> V_403 . V_404 ) ;
V_354 = F_79 ( V_412 ) ;
V_11 -> V_403 . V_411 = V_218 ;
F_178 ( V_412 , V_218 ?
( V_354 | V_413 ) :
( V_354 & ~ V_413 ) ) ;
F_47 ( & V_11 -> V_403 . V_404 ) ;
return 0 ;
}
static int F_179 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
if ( ! F_180 ( V_11 ) ) {
F_35 ( V_7 , L_238 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_5 ( V_7 , L_239 ,
F_6 ( V_209 . V_414 ) ) ;
if ( F_10 ( V_11 ) >= 8 ) {
F_35 ( V_7 , L_240 ) ;
} else {
if ( F_79 ( V_415 ) & V_416 )
F_35 ( V_7 , L_241 ) ;
else
F_35 ( V_7 , L_242 ) ;
}
F_111 ( V_11 ) ;
return 0 ;
}
static int F_181 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
bool V_417 = false ;
F_94 ( V_11 ) ;
F_101 ( V_11 , V_171 ) ;
if ( F_10 ( V_11 ) >= 9 )
;
else if ( F_109 ( V_11 ) )
V_417 = F_79 ( V_418 ) & V_419 ;
else if ( F_182 ( V_11 ) || F_183 ( V_11 ) ||
F_184 ( V_11 ) || F_185 ( V_11 ) )
V_417 = F_79 ( V_420 ) & V_421 ;
else if ( F_186 ( V_11 ) )
V_417 = F_79 ( V_422 ) & V_423 ;
else if ( F_187 ( V_11 ) )
V_417 = F_79 ( V_424 ) & V_425 ;
else if ( F_108 ( V_11 ) || F_95 ( V_11 ) )
V_417 = F_79 ( V_426 ) & V_427 ;
F_100 ( V_11 , V_171 ) ;
F_111 ( V_11 ) ;
F_5 ( V_7 , L_243 , F_188 ( V_417 ) ) ;
return 0 ;
}
static int F_189 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
unsigned long V_428 , V_429 , V_430 ;
int V_70 ;
if ( ! F_130 ( V_11 ) )
return - V_410 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_428 = F_190 ( V_11 ) ;
V_429 = F_191 ( V_11 ) ;
V_430 = F_192 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
F_5 ( V_7 , L_244 , V_428 ) ;
F_5 ( V_7 , L_245 , V_429 ) ;
F_5 ( V_7 , L_246 , V_430 ) ;
F_5 ( V_7 , L_247 , V_429 + V_430 ) ;
return 0 ;
}
static int F_193 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_70 = 0 ;
int V_431 , V_432 ;
unsigned int V_433 , V_434 ;
if ( ! F_194 ( V_11 ) ) {
F_35 ( V_7 , L_248 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
V_70 = F_44 ( & V_11 -> V_229 . V_230 ) ;
if ( V_70 )
goto V_73;
if ( F_144 ( V_11 ) ) {
V_434 =
V_11 -> V_229 . V_435 / V_290 ;
V_433 =
V_11 -> V_229 . V_436 / V_290 ;
} else {
V_434 = V_11 -> V_229 . V_435 ;
V_433 = V_11 -> V_229 . V_436 ;
}
F_35 ( V_7 , L_249 ) ;
for ( V_431 = V_434 ; V_431 <= V_433 ; V_431 ++ ) {
V_432 = V_431 ;
F_169 ( V_11 ,
V_437 ,
& V_432 ) ;
F_5 ( V_7 , L_250 ,
F_133 ( V_11 , ( V_431 *
( F_144 ( V_11 ) ?
V_290 : 1 ) ) ) ,
( ( V_432 >> 0 ) & 0xff ) * 100 ,
( ( V_432 >> 8 ) & 0xff ) * 100 ) ;
}
F_47 ( & V_11 -> V_229 . V_230 ) ;
V_73:
F_111 ( V_11 ) ;
return V_70 ;
}
static int F_195 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_438 * V_439 = & V_11 -> V_439 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_73;
if ( V_439 -> V_440 )
F_196 ( V_7 , V_439 -> V_440 , V_441 ) ;
F_47 ( & V_5 -> V_34 ) ;
V_73:
return 0 ;
}
static int F_197 ( struct V_6 * V_7 , void * V_219 )
{
struct V_438 * V_439 = & F_1 ( V_7 -> V_12 ) -> V_439 ;
if ( V_439 -> V_442 )
F_196 ( V_7 , V_439 -> V_442 , V_439 -> V_443 ) ;
return 0 ;
}
static int F_198 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_444 * V_445 = NULL ;
struct V_446 * V_447 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
#ifdef F_199
if ( V_11 -> V_448 ) {
V_445 = F_200 ( V_11 -> V_448 -> V_449 . V_450 ) ;
F_5 ( V_7 , L_251 ,
V_445 -> V_29 . V_51 ,
V_445 -> V_29 . V_52 ,
V_445 -> V_29 . V_451 -> V_452 ,
V_445 -> V_29 . V_451 -> V_453 [ 0 ] * 8 ,
V_445 -> V_29 . V_454 ,
F_201 ( & V_445 -> V_29 ) ) ;
F_31 ( V_7 , V_445 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
#endif
F_58 ( & V_5 -> V_455 . V_456 ) ;
F_202 (drm_fb, dev) {
struct V_444 * V_450 = F_200 ( V_447 ) ;
if ( V_450 == V_445 )
continue;
F_5 ( V_7 , L_252 ,
V_450 -> V_29 . V_51 ,
V_450 -> V_29 . V_52 ,
V_450 -> V_29 . V_451 -> V_452 ,
V_450 -> V_29 . V_451 -> V_453 [ 0 ] * 8 ,
V_450 -> V_29 . V_454 ,
F_201 ( & V_450 -> V_29 ) ) ;
F_31 ( V_7 , V_450 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_455 . V_456 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_203 ( struct V_6 * V_7 , struct V_457 * V_96 )
{
F_5 ( V_7 , L_253 ,
V_96 -> V_458 , V_96 -> V_459 , V_96 -> V_460 ) ;
}
static int F_204 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
struct V_93 * V_94 ;
enum V_89 V_55 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_28 (ctx, &dev_priv->context_list, link) {
F_5 ( V_7 , L_254 , V_94 -> V_144 ) ;
if ( V_94 -> V_122 ) {
struct V_116 * V_117 ;
V_117 = F_205 ( V_94 -> V_122 , V_123 ) ;
if ( V_117 ) {
F_5 ( V_7 , L_255 ,
V_117 -> V_124 , V_117 -> V_122 ) ;
F_206 ( V_117 ) ;
}
} else if ( F_207 ( V_94 -> V_86 ) ) {
F_35 ( V_7 , L_256 ) ;
} else {
F_35 ( V_7 , L_257 ) ;
}
F_46 ( V_7 , V_94 -> V_461 ? 'R' : 'r' ) ;
F_46 ( V_7 , '\n' ) ;
F_53 (engine, dev_priv, id) {
struct V_462 * V_463 = & V_94 -> V_31 [ V_31 -> V_55 ] ;
F_5 ( V_7 , L_258 , V_31 -> V_8 ) ;
F_46 ( V_7 , V_463 -> V_464 ? 'I' : 'i' ) ;
if ( V_463 -> V_95 )
F_31 ( V_7 , V_463 -> V_95 -> V_18 ) ;
if ( V_463 -> V_96 )
F_203 ( V_7 , V_463 -> V_96 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_208 ( struct V_6 * V_7 ,
struct V_93 * V_94 ,
struct V_30 * V_31 )
{
struct V_27 * V_28 = V_94 -> V_31 [ V_31 -> V_55 ] . V_95 ;
struct V_465 * V_465 ;
int V_90 ;
F_5 ( V_7 , L_259 , V_31 -> V_8 , V_94 -> V_144 ) ;
if ( ! V_28 ) {
F_35 ( V_7 , L_260 ) ;
return;
}
if ( V_28 -> V_307 & V_466 )
F_5 ( V_7 , L_261 ,
F_209 ( V_28 ) ) ;
if ( F_210 ( V_28 -> V_18 ) ) {
F_35 ( V_7 , L_262 ) ;
return;
}
V_465 = F_211 ( V_28 -> V_18 , V_467 ) ;
if ( V_465 ) {
T_4 * V_468 = F_212 ( V_465 ) ;
for ( V_90 = 0 ; V_90 < 0x600 / sizeof( T_4 ) / 4 ; V_90 += 4 ) {
F_5 ( V_7 ,
L_263 ,
V_90 * 4 ,
V_468 [ V_90 ] , V_468 [ V_90 + 1 ] ,
V_468 [ V_90 + 2 ] , V_468 [ V_90 + 3 ] ) ;
}
F_213 ( V_468 ) ;
}
F_214 ( V_28 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
static int F_215 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
struct V_93 * V_94 ;
enum V_89 V_55 ;
int V_70 ;
if ( ! V_209 . V_469 ) {
F_5 ( V_7 , L_264 ) ;
return 0 ;
}
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_28 (ctx, &dev_priv->context_list, link)
F_53 (engine, dev_priv, id)
F_208 ( V_7 , V_94 , V_31 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static const char * F_216 ( unsigned V_470 )
{
switch ( V_470 ) {
case V_471 :
return L_265 ;
case V_472 :
return L_266 ;
case V_473 :
return L_267 ;
case V_474 :
return L_268 ;
case V_475 :
return L_269 ;
case V_476 :
return L_270 ;
case V_477 :
return L_271 ;
case V_478 :
return L_272 ;
}
return L_273 ;
}
static int F_217 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_274 ,
F_216 ( V_11 -> V_24 . V_479 ) ) ;
F_5 ( V_7 , L_275 ,
F_216 ( V_11 -> V_24 . V_480 ) ) ;
if ( F_218 ( V_11 ) || F_219 ( V_11 ) ) {
F_5 ( V_7 , L_276 ,
F_79 ( V_481 ) ) ;
F_5 ( V_7 , L_277 ,
F_79 ( V_482 ) ) ;
F_5 ( V_7 , L_278 ,
F_131 ( V_483 ) ) ;
F_5 ( V_7 , L_279 ,
F_131 ( V_484 ) ) ;
} else if ( F_10 ( V_11 ) >= 6 ) {
F_5 ( V_7 , L_280 ,
F_79 ( V_485 ) ) ;
F_5 ( V_7 , L_281 ,
F_79 ( V_486 ) ) ;
F_5 ( V_7 , L_282 ,
F_79 ( V_487 ) ) ;
F_5 ( V_7 , L_283 ,
F_79 ( V_488 ) ) ;
if ( F_10 ( V_11 ) >= 8 )
F_5 ( V_7 , L_284 ,
F_79 ( V_489 ) ) ;
else
F_5 ( V_7 , L_285 ,
F_79 ( V_490 ) ) ;
F_5 ( V_7 , L_286 ,
F_79 ( V_491 ) ) ;
}
if ( V_11 -> V_492 & V_493 )
F_35 ( V_7 , L_287 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_220 ( int V_55 , void * V_74 , void * V_10 )
{
struct V_93 * V_94 = V_74 ;
struct V_6 * V_7 = V_10 ;
struct V_82 * V_83 = V_94 -> V_83 ;
if ( ! V_83 ) {
F_5 ( V_7 , L_288 ,
V_94 -> V_494 ) ;
return 0 ;
}
if ( F_221 ( V_94 ) )
F_35 ( V_7 , L_289 ) ;
else
F_5 ( V_7 , L_290 , V_94 -> V_494 ) ;
V_83 -> V_495 ( V_83 , V_7 ) ;
return 0 ;
}
static void F_222 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_82 * V_83 = V_11 -> V_24 . V_496 ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
int V_163 ;
if ( ! V_83 )
return;
F_53 (engine, dev_priv, id) {
F_5 ( V_7 , L_291 , V_31 -> V_8 ) ;
for ( V_163 = 0 ; V_163 < 4 ; V_163 ++ ) {
T_3 V_497 = F_79 ( F_223 ( V_31 , V_163 ) ) ;
V_497 <<= 32 ;
V_497 |= F_79 ( F_224 ( V_31 , V_163 ) ) ;
F_5 ( V_7 , L_292 , V_163 , V_497 ) ;
}
}
}
static void F_225 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_30 * V_31 ;
enum V_89 V_55 ;
if ( F_140 ( V_11 ) )
F_5 ( V_7 , L_293 , F_79 ( V_498 ) ) ;
F_53 (engine, dev_priv, id) {
F_5 ( V_7 , L_291 , V_31 -> V_8 ) ;
if ( F_141 ( V_11 ) )
F_5 ( V_7 , L_293 ,
F_79 ( F_226 ( V_31 ) ) ) ;
F_5 ( V_7 , L_294 ,
F_79 ( F_227 ( V_31 ) ) ) ;
F_5 ( V_7 , L_295 ,
F_79 ( F_228 ( V_31 ) ) ) ;
F_5 ( V_7 , L_296 ,
F_79 ( F_229 ( V_31 ) ) ) ;
}
if ( V_11 -> V_24 . V_496 ) {
struct V_82 * V_83 = V_11 -> V_24 . V_496 ;
F_35 ( V_7 , L_297 ) ;
F_5 ( V_7 , L_298 , V_83 -> V_499 . V_29 . V_500 ) ;
V_83 -> V_495 ( V_83 , V_7 ) ;
}
F_5 ( V_7 , L_299 , F_79 ( V_501 ) ) ;
}
static int F_230 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_97 * V_85 ;
int V_70 ;
F_58 ( & V_5 -> V_113 ) ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_502;
F_94 ( V_11 ) ;
if ( F_10 ( V_11 ) >= 8 )
F_222 ( V_7 , V_11 ) ;
else if ( F_10 ( V_11 ) >= 6 )
F_225 ( V_7 , V_11 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_99 * V_86 = V_85 -> V_101 ;
struct V_116 * V_117 ;
V_117 = F_205 ( V_85 -> V_122 , V_123 ) ;
if ( ! V_117 ) {
V_70 = - V_503 ;
goto V_504;
}
F_5 ( V_7 , L_300 , V_117 -> V_124 ) ;
F_206 ( V_117 ) ;
F_59 ( & V_86 -> V_102 , F_220 ,
( void * ) ( unsigned long ) V_7 ) ;
}
V_504:
F_111 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
V_502:
F_47 ( & V_5 -> V_113 ) ;
return V_70 ;
}
static int F_231 ( struct V_1 * V_209 )
{
struct V_30 * V_31 ;
enum V_89 V_55 ;
int V_68 = 0 ;
F_53 (engine, i915, id)
V_68 += F_154 ( V_31 ) ;
return V_68 ;
}
static const char * F_232 ( unsigned int V_505 )
{
static const char * const V_506 [] = {
[ V_507 ] = L_301 ,
[ V_508 ] = L_302 ,
[ V_509 ] = L_303 ,
} ;
if ( V_505 >= F_54 ( V_506 ) || ! V_506 [ V_505 ] )
return L_272 ;
return V_506 [ V_505 ] ;
}
static int F_233 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_97 * V_85 ;
F_5 ( V_7 , L_304 , V_11 -> V_229 . V_510 ) ;
F_5 ( V_7 , L_305 ,
F_6 ( V_11 -> V_317 . V_318 ) , V_11 -> V_317 . V_511 ) ;
F_5 ( V_7 , L_306 , F_231 ( V_11 ) ) ;
F_5 ( V_7 , L_307 ,
F_133 ( V_11 , V_11 -> V_229 . V_233 ) ) ;
F_5 ( V_7 , L_308 ,
F_133 ( V_11 , V_11 -> V_229 . V_235 ) ,
F_133 ( V_11 , V_11 -> V_229 . V_435 ) ,
F_133 ( V_11 , V_11 -> V_229 . V_436 ) ,
F_133 ( V_11 , V_11 -> V_229 . V_234 ) ) ;
F_5 ( V_7 , L_309 ,
F_133 ( V_11 , V_11 -> V_229 . V_236 ) ,
F_133 ( V_11 , V_11 -> V_229 . V_237 ) ,
F_133 ( V_11 , V_11 -> V_229 . V_291 ) ) ;
F_58 ( & V_5 -> V_113 ) ;
F_62 ( & V_11 -> V_229 . V_512 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_99 * V_86 = V_85 -> V_101 ;
struct V_116 * V_117 ;
F_65 () ;
V_117 = F_66 ( V_85 -> V_122 , V_123 ) ;
F_5 ( V_7 , L_310 ,
V_117 ? V_117 -> V_124 : L_42 ,
V_117 ? V_117 -> V_122 : - 1 ,
V_86 -> V_229 . V_513 ,
F_25 ( & V_86 -> V_229 . V_514 ) ? L_13 : L_311 ) ;
F_67 () ;
}
F_5 ( V_7 , L_312 , V_11 -> V_229 . V_513 ) ;
F_63 ( & V_11 -> V_229 . V_512 ) ;
F_47 ( & V_5 -> V_113 ) ;
if ( F_10 ( V_11 ) >= 6 &&
V_11 -> V_229 . V_510 &&
V_11 -> V_317 . V_511 ) {
T_4 V_515 , V_247 ;
T_4 V_516 , V_250 ;
F_135 ( V_11 , V_263 ) ;
V_515 = F_167 ( V_272 ) & V_517 ;
V_247 = F_167 ( V_270 ) & V_517 ;
V_516 = F_167 ( V_277 ) & V_517 ;
V_250 = F_167 ( V_275 ) & V_517 ;
F_139 ( V_11 , V_263 ) ;
F_5 ( V_7 , L_313 ,
F_232 ( V_11 -> V_229 . V_505 ) ) ;
F_5 ( V_7 , L_314 ,
V_515 && V_247 ? 100 * V_515 / V_247 : 0 ,
V_11 -> V_229 . V_288 ) ;
F_5 ( V_7 , L_315 ,
V_516 && V_250 ? 100 * V_516 / V_250 : 0 ,
V_11 -> V_229 . V_289 ) ;
} else {
F_35 ( V_7 , L_316 ) ;
}
return 0 ;
}
static int F_234 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const bool V_518 = F_10 ( V_11 ) > 8 ;
F_5 ( V_7 , L_317 , F_6 ( F_194 ( V_11 ) ) ) ;
F_5 ( V_7 , L_318 , V_518 ? L_319 : L_320 ,
F_235 ( V_11 ) / 1024 / 1024 ) ;
return 0 ;
}
static int F_236 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_519 * V_520 = & V_11 -> V_521 . V_522 ;
if ( ! F_237 ( V_11 ) )
return 0 ;
F_35 ( V_7 , L_321 ) ;
F_5 ( V_7 , L_322 , V_520 -> V_523 ) ;
F_5 ( V_7 , L_323 ,
F_238 ( V_520 -> V_524 ) ) ;
F_5 ( V_7 , L_324 ,
F_238 ( V_520 -> V_525 ) ) ;
F_5 ( V_7 , L_325 ,
V_520 -> V_526 , V_520 -> V_527 ) ;
F_5 ( V_7 , L_326 ,
V_520 -> V_528 , V_520 -> V_529 ) ;
F_5 ( V_7 , L_327 ,
V_520 -> V_530 , V_520 -> V_531 ) ;
F_5 ( V_7 , L_328 ,
V_520 -> V_532 , V_520 -> V_533 ) ;
F_5 ( V_7 , L_329 ,
V_520 -> V_534 , V_520 -> V_535 ) ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_330 , F_79 ( V_536 ) ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_239 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_519 * V_537 = & V_11 -> V_538 . V_522 ;
T_4 V_208 , V_163 ;
if ( ! F_240 ( V_11 ) )
return 0 ;
F_5 ( V_7 , L_331 ) ;
F_5 ( V_7 , L_322 ,
V_537 -> V_523 ) ;
F_5 ( V_7 , L_323 ,
F_238 ( V_537 -> V_524 ) ) ;
F_5 ( V_7 , L_324 ,
F_238 ( V_537 -> V_525 ) ) ;
F_5 ( V_7 , L_325 ,
V_537 -> V_526 , V_537 -> V_527 ) ;
F_5 ( V_7 , L_326 ,
V_537 -> V_528 , V_537 -> V_529 ) ;
F_5 ( V_7 , L_327 ,
V_537 -> V_530 , V_537 -> V_531 ) ;
F_5 ( V_7 , L_328 ,
V_537 -> V_532 , V_537 -> V_533 ) ;
F_5 ( V_7 , L_329 ,
V_537 -> V_534 , V_537 -> V_535 ) ;
F_94 ( V_11 ) ;
V_208 = F_79 ( V_539 ) ;
F_5 ( V_7 , L_332 , V_208 ) ;
F_5 ( V_7 , L_333 ,
( V_208 & V_540 ) >> V_541 ) ;
F_5 ( V_7 , L_334 ,
( V_208 & V_542 ) >> V_543 ) ;
F_5 ( V_7 , L_335 ,
( V_208 & V_544 ) >> V_545 ) ;
F_35 ( V_7 , L_336 ) ;
for ( V_163 = 0 ; V_163 < 16 ; V_163 ++ )
F_5 ( V_7 , L_337 , V_163 , F_79 ( F_241 ( V_163 ) ) ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static void F_242 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_546 * V_538 = & V_11 -> V_538 ;
F_35 ( V_7 , L_338 ) ;
F_5 ( V_7 , L_339 ,
V_538 -> log . V_547 [ V_548 ] ,
V_538 -> log . V_549 [ V_548 ] ) ;
F_5 ( V_7 , L_340 ,
V_538 -> log . V_547 [ V_550 ] ,
V_538 -> log . V_549 [ V_550 ] ) ;
F_5 ( V_7 , L_341 ,
V_538 -> log . V_547 [ V_551 ] ,
V_538 -> log . V_549 [ V_551 ] ) ;
F_5 ( V_7 , L_342 ,
V_538 -> log . V_552 ) ;
F_5 ( V_7 , L_343 ,
V_538 -> log . V_553 ) ;
}
static void F_243 ( struct V_6 * V_7 ,
struct V_1 * V_11 ,
struct V_554 * V_555 )
{
struct V_30 * V_31 ;
enum V_89 V_55 ;
T_12 V_556 = 0 ;
F_5 ( V_7 , L_344 ,
V_555 -> V_147 , V_555 -> V_557 , V_555 -> V_558 ) ;
F_5 ( V_7 , L_345 ,
V_555 -> V_559 , V_555 -> V_560 , V_555 -> V_561 ) ;
F_5 ( V_7 , L_346 ,
V_555 -> V_562 , V_555 -> V_563 , V_555 -> V_564 ) ;
F_5 ( V_7 , L_347 , V_555 -> V_565 ) ;
F_5 ( V_7 , L_348 , V_555 -> V_566 ) ;
F_5 ( V_7 , L_349 , V_555 -> V_567 ) ;
F_53 (engine, dev_priv, id) {
T_3 V_568 = V_555 -> V_568 [ V_55 ] ;
V_556 += V_568 ;
F_5 ( V_7 , L_350 ,
V_568 , V_31 -> V_8 ) ;
}
F_5 ( V_7 , L_351 , V_556 ) ;
}
static int F_244 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_546 * V_538 = & V_11 -> V_538 ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
T_3 V_67 ;
if ( ! V_538 -> V_569 ) {
F_5 ( V_7 , L_352 ,
F_245 ( V_11 ) ?
L_353 :
L_354 ) ;
return 0 ;
}
F_5 ( V_7 , L_355 ) ;
F_5 ( V_7 , L_356 , V_570 , V_538 -> V_571 ) ;
F_5 ( V_7 , L_357 , V_538 -> V_572 ) ;
F_5 ( V_7 , L_358 , V_538 -> V_573 ) ;
F_5 ( V_7 , L_359 , V_538 -> V_574 ) ;
F_5 ( V_7 , L_360 , V_538 -> V_575 ) ;
F_5 ( V_7 , L_361 , V_538 -> V_576 ) ;
F_5 ( V_7 , L_362 , V_538 -> V_577 ) ;
V_67 = 0 ;
F_5 ( V_7 , L_363 ) ;
F_53 (engine, dev_priv, id) {
T_3 V_568 = V_538 -> V_568 [ V_55 ] ;
V_67 += V_568 ;
F_5 ( V_7 , L_364 ,
V_31 -> V_8 , V_568 , V_538 -> V_578 [ V_55 ] ) ;
}
F_5 ( V_7 , L_365 , L_366 , V_67 ) ;
F_5 ( V_7 , L_367 , V_538 -> V_569 ) ;
F_243 ( V_7 , V_11 , V_538 -> V_569 ) ;
F_242 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_246 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_17 * V_18 ;
int V_163 = 0 , V_579 ;
if ( ! V_11 -> V_538 . log . V_28 )
return 0 ;
V_18 = V_11 -> V_538 . log . V_28 -> V_18 ;
for ( V_579 = 0 ; V_579 < V_18 -> V_29 . V_26 / V_580 ; V_579 ++ ) {
T_4 * log = F_212 ( F_211 ( V_18 , V_579 ) ) ;
for ( V_163 = 0 ; V_163 < V_580 / sizeof( T_4 ) ; V_163 += 4 )
F_5 ( V_7 , L_368 ,
* ( log + V_163 ) , * ( log + V_163 + 1 ) ,
* ( log + V_163 + 2 ) , * ( log + V_163 + 3 ) ) ;
F_213 ( log ) ;
}
F_46 ( V_7 , '\n' ) ;
return 0 ;
}
static int F_247 ( void * V_10 , T_3 * V_218 )
{
struct V_62 * V_5 = V_10 ;
struct V_1 * V_11 = F_2 ( V_5 ) ;
if ( ! V_11 -> V_538 . log . V_28 )
return - V_581 ;
* V_218 = V_209 . V_582 ;
return 0 ;
}
static int F_248 ( void * V_10 , T_3 V_218 )
{
struct V_62 * V_5 = V_10 ;
struct V_1 * V_11 = F_2 ( V_5 ) ;
int V_70 ;
if ( ! V_11 -> V_538 . log . V_28 )
return - V_581 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_94 ( V_11 ) ;
V_70 = F_249 ( V_11 , V_218 ) ;
F_111 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
return V_70 ;
}
static const char * F_250 ( T_4 V_218 )
{
static const char * const V_583 [] = {
L_369 ,
L_370 ,
L_371 ,
L_372 ,
L_373 ,
L_374 ,
L_375 ,
L_376 ,
L_377 ,
L_378 ,
L_379
} ;
V_218 = ( V_218 & V_584 ) >> V_585 ;
if ( V_218 < F_54 ( V_583 ) )
return V_583 [ V_218 ] ;
return L_272 ;
}
static int F_251 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_586 = 0 ;
T_4 V_587 [ 3 ] ;
enum V_129 V_129 ;
bool V_510 = false ;
if ( ! F_252 ( V_11 ) ) {
F_35 ( V_7 , L_380 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_58 ( & V_11 -> V_588 . V_404 ) ;
F_5 ( V_7 , L_381 , F_6 ( V_11 -> V_588 . V_589 ) ) ;
F_5 ( V_7 , L_382 , F_6 ( V_11 -> V_588 . V_590 ) ) ;
F_5 ( V_7 , L_383 , F_6 ( ( bool ) V_11 -> V_588 . V_510 ) ) ;
F_5 ( V_7 , L_384 , F_6 ( V_11 -> V_588 . V_87 ) ) ;
F_5 ( V_7 , L_385 ,
V_11 -> V_588 . V_591 ) ;
F_5 ( V_7 , L_386 ,
F_6 ( F_253 ( & V_11 -> V_588 . V_131 . V_131 ) ) ) ;
if ( F_254 ( V_11 ) ) {
if ( V_11 -> V_588 . V_592 )
V_510 = F_79 ( V_593 ) & V_594 ;
else
V_510 = F_79 ( V_595 ) & V_596 ;
} else {
F_96 (dev_priv, pipe) {
enum V_597 V_598 =
F_255 ( V_11 , V_129 ) ;
enum V_169 V_170 ;
V_170 = F_256 ( V_598 ) ;
if ( ! F_98 ( V_11 ,
V_170 ) )
continue;
V_587 [ V_129 ] = F_79 ( F_257 ( V_129 ) ) &
V_599 ;
if ( ( V_587 [ V_129 ] == V_600 ) ||
( V_587 [ V_129 ] == V_601 ) )
V_510 = true ;
F_100 ( V_11 , V_170 ) ;
}
}
F_5 ( V_7 , L_387 ,
F_6 ( V_11 -> V_588 . V_602 ) ) ;
F_5 ( V_7 , L_388 , F_6 ( V_510 ) ) ;
if ( ! F_254 ( V_11 ) )
F_96 (dev_priv, pipe) {
if ( ( V_587 [ V_129 ] == V_600 ) ||
( V_587 [ V_129 ] == V_601 ) )
F_5 ( V_7 , L_389 , F_71 ( V_129 ) ) ;
}
F_35 ( V_7 , L_390 ) ;
if ( F_137 ( V_11 ) || F_138 ( V_11 ) ) {
V_586 = F_79 ( V_603 ) &
V_604 ;
F_5 ( V_7 , L_391 , V_586 ) ;
}
if ( V_11 -> V_588 . V_592 ) {
T_4 V_605 = F_79 ( V_606 ) ;
F_5 ( V_7 , L_392 ,
V_605 , F_250 ( V_605 ) ) ;
}
F_47 ( & V_11 -> V_588 . V_404 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_258 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_607 * V_608 ;
struct V_609 V_610 ;
struct V_611 * V_611 = NULL ;
int V_70 ;
T_13 V_612 [ 6 ] ;
F_259 ( V_5 ) ;
F_260 ( V_5 , & V_610 ) ;
F_261 (connector, &conn_iter) {
struct V_613 * V_128 ;
if ( ! V_608 -> V_29 . V_95 -> V_614 )
continue;
V_128 = V_608 -> V_29 . V_95 -> V_128 ;
if ( ! V_128 -> V_95 -> V_87 )
continue;
if ( V_608 -> V_29 . V_615 != V_616 )
continue;
V_611 = F_262 ( V_608 -> V_29 . V_95 -> V_614 ) ;
V_70 = F_263 ( V_611 , V_612 ) ;
if ( V_70 )
goto V_73;
F_5 ( V_7 , L_393 ,
V_612 [ 0 ] , V_612 [ 1 ] , V_612 [ 2 ] ,
V_612 [ 3 ] , V_612 [ 4 ] , V_612 [ 5 ] ) ;
goto V_73;
}
V_70 = - V_410 ;
V_73:
F_264 ( & V_610 ) ;
F_265 ( V_5 ) ;
return V_70 ;
}
static int F_266 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_3 V_505 ;
T_4 V_617 ;
if ( F_10 ( V_11 ) < 6 )
return - V_410 ;
F_94 ( V_11 ) ;
F_267 ( V_618 , V_505 ) ;
V_505 = ( V_505 & 0x1f00 ) >> 8 ;
V_617 = 1000000 / ( 1 << V_505 ) ;
V_505 = F_79 ( V_619 ) ;
V_505 *= V_617 ;
F_111 ( V_11 ) ;
F_5 ( V_7 , L_394 , ( long long unsigned ) V_505 ) ;
return 0 ;
}
static int F_268 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_620 * V_621 = V_11 -> V_63 . V_621 ;
if ( ! F_269 ( V_11 ) )
F_35 ( V_7 , L_395 ) ;
F_5 ( V_7 , L_396 , F_6 ( ! V_11 -> V_317 . V_318 ) ) ;
F_5 ( V_7 , L_397 ,
F_6 ( ! F_270 ( V_11 ) ) ) ;
#ifdef F_271
F_5 ( V_7 , L_398 ,
F_39 ( & V_11 -> V_63 . V_5 -> V_505 . V_622 ) ) ;
#else
F_5 ( V_7 , L_399 ) ;
#endif
F_5 ( V_7 , L_400 ,
F_272 ( V_621 -> V_623 ) ,
V_621 -> V_623 ) ;
return 0 ;
}
static int F_273 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_624 * V_625 = & V_11 -> V_625 ;
int V_163 ;
F_58 ( & V_625 -> V_404 ) ;
F_5 ( V_7 , L_401 , L_402 , L_403 ) ;
for ( V_163 = 0 ; V_163 < V_625 -> V_626 ; V_163 ++ ) {
struct V_627 * V_628 ;
enum V_169 V_170 ;
V_628 = & V_625 -> V_629 [ V_163 ] ;
F_5 ( V_7 , L_404 , V_628 -> V_8 ,
V_628 -> V_68 ) ;
F_274 (power_domain, power_well->domains)
F_5 ( V_7 , L_405 ,
F_275 ( V_170 ) ,
V_625 -> V_630 [ V_170 ] ) ;
}
F_47 ( & V_625 -> V_404 ) ;
return 0 ;
}
static int F_276 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_631 * V_632 ;
if ( ! F_277 ( V_11 ) ) {
F_35 ( V_7 , L_238 ) ;
return 0 ;
}
V_632 = & V_11 -> V_632 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_406 , F_6 ( V_632 -> V_633 != NULL ) ) ;
F_5 ( V_7 , L_407 , V_632 -> V_634 ) ;
if ( ! V_632 -> V_633 )
goto V_73;
F_5 ( V_7 , L_408 , F_278 ( V_632 -> V_635 ) ,
F_279 ( V_632 -> V_635 ) ) ;
if ( F_280 ( V_11 ) && V_632 -> V_635 >= F_281 ( 1 , 6 ) ) {
F_5 ( V_7 , L_409 ,
F_79 ( V_636 ) ) ;
F_5 ( V_7 , L_410 ,
F_79 ( V_637 ) ) ;
} else if ( F_282 ( V_11 ) && V_632 -> V_635 >= F_281 ( 1 , 4 ) ) {
F_5 ( V_7 , L_409 ,
F_79 ( V_638 ) ) ;
}
V_73:
F_5 ( V_7 , L_411 , F_79 ( F_283 ( 0 ) ) ) ;
F_5 ( V_7 , L_412 , F_79 ( V_639 ) ) ;
F_5 ( V_7 , L_413 , F_79 ( V_640 ) ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static void F_284 ( struct V_6 * V_7 , int V_641 ,
struct V_642 * V_643 )
{
int V_163 ;
for ( V_163 = 0 ; V_163 < V_641 ; V_163 ++ )
F_46 ( V_7 , '\t' ) ;
F_5 ( V_7 , L_414 ,
V_643 -> V_29 . V_55 , V_643 -> V_8 ,
V_643 -> V_644 , V_643 -> clock ,
V_643 -> V_645 , V_643 -> V_646 ,
V_643 -> V_647 , V_643 -> V_648 ,
V_643 -> V_649 , V_643 -> V_650 ,
V_643 -> V_651 , V_643 -> V_652 ,
V_643 -> type , V_643 -> V_307 ) ;
}
static void F_285 ( struct V_6 * V_7 ,
struct V_127 * V_127 ,
struct V_653 * V_653 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_613 * V_128 = & V_127 -> V_29 ;
struct V_607 * V_607 ;
struct V_654 * V_655 ;
V_655 = & V_653 -> V_29 ;
F_5 ( V_7 , L_415 ,
V_655 -> V_29 . V_55 , V_655 -> V_8 ) ;
F_286 (dev, encoder, intel_connector) {
struct V_656 * V_608 = & V_607 -> V_29 ;
F_5 ( V_7 , L_416 ,
V_608 -> V_29 . V_55 ,
V_608 -> V_8 ,
F_287 ( V_608 -> V_657 ) ) ;
if ( V_608 -> V_657 == V_658 ) {
struct V_642 * V_643 = & V_128 -> V_643 ;
F_5 ( V_7 , L_417 ) ;
F_284 ( V_7 , 2 , V_643 ) ;
} else {
F_46 ( V_7 , '\n' ) ;
}
}
}
static void F_288 ( struct V_6 * V_7 , struct V_127 * V_127 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_613 * V_128 = & V_127 -> V_29 ;
struct V_653 * V_653 ;
struct V_659 * V_660 = V_128 -> V_661 -> V_95 ;
struct V_446 * V_450 = V_660 -> V_450 ;
if ( V_450 )
F_5 ( V_7 , L_418 ,
V_450 -> V_29 . V_55 , V_660 -> V_662 >> 16 ,
V_660 -> V_663 >> 16 , V_450 -> V_51 , V_450 -> V_52 ) ;
else
F_35 ( V_7 , L_419 ) ;
F_289 (dev, crtc, intel_encoder)
F_285 ( V_7 , V_127 , V_653 ) ;
}
static void F_290 ( struct V_6 * V_7 , struct V_664 * V_665 )
{
struct V_642 * V_643 = V_665 -> V_666 ;
F_5 ( V_7 , L_420 ) ;
F_284 ( V_7 , 2 , V_643 ) ;
}
static void F_291 ( struct V_6 * V_7 ,
struct V_607 * V_607 )
{
struct V_653 * V_653 = V_607 -> V_655 ;
struct V_611 * V_611 = F_262 ( & V_653 -> V_29 ) ;
F_5 ( V_7 , L_421 , V_611 -> V_667 [ V_668 ] ) ;
F_5 ( V_7 , L_422 , F_6 ( V_611 -> V_669 ) ) ;
if ( V_607 -> V_29 . V_615 == V_616 )
F_290 ( V_7 , & V_607 -> V_665 ) ;
F_292 ( V_7 , V_611 -> V_667 , V_611 -> V_670 ,
& V_611 -> V_671 ) ;
}
static void F_293 ( struct V_6 * V_7 ,
struct V_607 * V_607 )
{
struct V_653 * V_653 = V_607 -> V_655 ;
struct V_672 * V_673 =
F_294 ( & V_653 -> V_29 ) ;
struct V_674 * V_675 = V_673 -> V_661 ;
struct V_611 * V_611 = & V_675 -> V_676 ;
bool V_669 = F_295 ( & V_611 -> V_677 ,
V_607 -> V_678 ) ;
F_5 ( V_7 , L_422 , F_6 ( V_669 ) ) ;
}
static void F_296 ( struct V_6 * V_7 ,
struct V_607 * V_607 )
{
struct V_653 * V_653 = V_607 -> V_655 ;
struct V_679 * V_679 = F_297 ( & V_653 -> V_29 ) ;
F_5 ( V_7 , L_422 , F_6 ( V_679 -> V_669 ) ) ;
}
static void F_298 ( struct V_6 * V_7 ,
struct V_607 * V_607 )
{
F_290 ( V_7 , & V_607 -> V_665 ) ;
}
static void F_299 ( struct V_6 * V_7 ,
struct V_656 * V_608 )
{
struct V_607 * V_607 = F_300 ( V_608 ) ;
struct V_653 * V_653 = V_607 -> V_655 ;
struct V_642 * V_643 ;
F_5 ( V_7 , L_423 ,
V_608 -> V_29 . V_55 , V_608 -> V_8 ,
F_287 ( V_608 -> V_657 ) ) ;
if ( V_608 -> V_657 == V_658 ) {
F_5 ( V_7 , L_424 , V_608 -> V_680 . V_8 ) ;
F_5 ( V_7 , L_425 ,
V_608 -> V_680 . V_681 ,
V_608 -> V_680 . V_682 ) ;
F_5 ( V_7 , L_426 ,
F_301 ( V_608 -> V_680 . V_683 ) ) ;
F_5 ( V_7 , L_427 ,
V_608 -> V_680 . V_684 ) ;
}
if ( ! V_653 || V_653 -> type == V_685 )
return;
switch ( V_608 -> V_615 ) {
case V_686 :
case V_616 :
if ( V_653 -> type == V_685 )
F_293 ( V_7 , V_607 ) ;
else
F_291 ( V_7 , V_607 ) ;
break;
case V_687 :
if ( V_653 -> type == V_688 )
F_298 ( V_7 , V_607 ) ;
break;
case V_689 :
if ( V_653 -> type == V_690 ||
V_653 -> type == V_691 )
F_296 ( V_7 , V_607 ) ;
break;
default:
break;
}
F_5 ( V_7 , L_428 ) ;
F_28 (mode, &connector->modes, head)
F_284 ( V_7 , 2 , V_643 ) ;
}
static bool F_302 ( struct V_1 * V_11 , int V_129 )
{
T_4 V_95 ;
if ( F_303 ( V_11 ) || F_304 ( V_11 ) )
V_95 = F_79 ( F_305 ( V_692 ) ) & V_693 ;
else
V_95 = F_79 ( F_305 ( V_129 ) ) & V_694 ;
return V_95 ;
}
static bool F_306 ( struct V_1 * V_11 ,
int V_129 , int * V_9 , int * V_695 )
{
T_4 V_203 ;
V_203 = F_79 ( F_307 ( V_129 ) ) ;
* V_9 = ( V_203 >> V_696 ) & V_697 ;
if ( V_203 & ( V_698 << V_696 ) )
* V_9 = - * V_9 ;
* V_695 = ( V_203 >> V_699 ) & V_697 ;
if ( V_203 & ( V_698 << V_699 ) )
* V_695 = - * V_695 ;
return F_302 ( V_11 , V_129 ) ;
}
static const char * F_308 ( enum V_700 type )
{
switch ( type ) {
case V_701 :
return L_429 ;
case V_702 :
return L_430 ;
case V_703 :
return L_431 ;
}
return L_272 ;
}
static const char * F_309 ( unsigned int V_704 )
{
static char V_210 [ 48 ] ;
snprintf ( V_210 , sizeof( V_210 ) ,
L_432 ,
( V_704 & V_705 ) ? L_433 : L_13 ,
( V_704 & V_706 ) ? L_434 : L_13 ,
( V_704 & V_707 ) ? L_435 : L_13 ,
( V_704 & V_708 ) ? L_436 : L_13 ,
( V_704 & V_709 ) ? L_437 : L_13 ,
( V_704 & V_710 ) ? L_438 : L_13 ,
V_704 ) ;
return V_210 ;
}
static void F_310 ( struct V_6 * V_7 , struct V_127 * V_127 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_711 * V_711 ;
F_311 (dev, intel_crtc, intel_plane) {
struct V_659 * V_95 ;
struct V_712 * V_50 = & V_711 -> V_29 ;
struct V_713 V_714 ;
if ( ! V_50 -> V_95 ) {
F_35 ( V_7 , L_439 ) ;
continue;
}
V_95 = V_50 -> V_95 ;
if ( V_95 -> V_450 ) {
F_312 ( V_95 -> V_450 -> V_451 -> V_451 ,
& V_714 ) ;
} else {
sprintf ( V_714 . V_207 , L_440 ) ;
}
F_5 ( V_7 , L_441 ,
V_50 -> V_29 . V_55 ,
F_308 ( V_711 -> V_29 . type ) ,
V_95 -> V_715 , V_95 -> V_716 ,
V_95 -> V_717 , V_95 -> V_718 ,
( V_95 -> V_662 >> 16 ) ,
( ( V_95 -> V_662 & 0xffff ) * 15625 ) >> 10 ,
( V_95 -> V_663 >> 16 ) ,
( ( V_95 -> V_663 & 0xffff ) * 15625 ) >> 10 ,
( V_95 -> V_719 >> 16 ) ,
( ( V_95 -> V_719 & 0xffff ) * 15625 ) >> 10 ,
( V_95 -> V_720 >> 16 ) ,
( ( V_95 -> V_720 & 0xffff ) * 15625 ) >> 10 ,
V_714 . V_207 ,
F_309 ( V_95 -> V_704 ) ) ;
}
}
static void F_313 ( struct V_6 * V_7 , struct V_127 * V_127 )
{
struct V_721 * V_722 ;
int V_723 = V_127 -> V_723 ;
int V_163 ;
V_722 = F_314 ( V_127 -> V_29 . V_95 ) ;
if ( V_723 ) {
F_5 ( V_7 , L_442 ,
V_723 ,
V_722 -> V_724 . V_725 ,
V_722 -> V_724 . V_726 ) ;
for ( V_163 = 0 ; V_163 < V_723 ; V_163 ++ ) {
struct V_727 * V_728 =
& V_722 -> V_724 . V_729 [ V_163 ] ;
F_5 ( V_7 , L_443 ,
V_163 , F_6 ( V_728 -> V_730 ) , V_728 -> V_643 ) ;
}
F_35 ( V_7 , L_390 ) ;
} else {
F_35 ( V_7 , L_444 ) ;
}
}
static int F_315 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_127 * V_128 ;
struct V_656 * V_608 ;
struct V_609 V_610 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_445 ) ;
F_5 ( V_7 , L_446 ) ;
F_70 (dev, crtc) {
bool V_87 ;
struct V_721 * V_722 ;
int V_9 , V_695 ;
F_316 ( & V_128 -> V_29 . V_731 , NULL ) ;
V_722 = F_314 ( V_128 -> V_29 . V_95 ) ;
F_5 ( V_7 , L_447 ,
V_128 -> V_29 . V_29 . V_55 , F_71 ( V_128 -> V_129 ) ,
F_6 ( V_722 -> V_29 . V_87 ) ,
V_722 -> V_732 , V_722 -> V_733 ,
F_6 ( V_722 -> V_734 ) , V_722 -> V_735 ) ;
if ( V_722 -> V_29 . V_87 ) {
F_288 ( V_7 , V_128 ) ;
V_87 = F_306 ( V_11 , V_128 -> V_129 , & V_9 , & V_695 ) ;
F_5 ( V_7 , L_448 ,
F_6 ( V_128 -> V_736 ) ,
V_9 , V_695 , V_128 -> V_29 . V_737 -> V_95 -> V_717 ,
V_128 -> V_29 . V_737 -> V_95 -> V_718 ,
V_128 -> V_738 , F_6 ( V_87 ) ) ;
F_313 ( V_7 , V_128 ) ;
F_310 ( V_7 , V_128 ) ;
}
F_5 ( V_7 , L_449 ,
F_6 ( ! V_128 -> V_739 ) ,
F_6 ( ! V_128 -> V_740 ) ) ;
F_317 ( & V_128 -> V_29 . V_731 ) ;
}
F_5 ( V_7 , L_390 ) ;
F_5 ( V_7 , L_450 ) ;
F_5 ( V_7 , L_451 ) ;
F_58 ( & V_5 -> V_455 . V_731 ) ;
F_260 ( V_5 , & V_610 ) ;
F_318 (connector, &conn_iter)
F_299 ( V_7 , V_608 ) ;
F_264 ( & V_610 ) ;
F_47 ( & V_5 -> V_455 . V_731 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_319 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_89 V_55 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_452 ,
F_6 ( V_11 -> V_317 . V_318 ) ) ;
F_5 ( V_7 , L_453 ,
V_11 -> V_317 . V_511 ) ;
F_53 (engine, dev_priv, id) {
struct V_154 * V_61 = & V_31 -> V_155 ;
struct V_114 * V_142 ;
struct V_156 * V_157 ;
T_3 V_135 ;
F_5 ( V_7 , L_291 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_454 ,
F_75 ( V_31 ) ,
F_74 ( V_31 ) ,
V_31 -> V_319 . V_145 ,
F_85 ( V_148 - V_31 -> V_319 . V_324 ) ,
V_31 -> V_150 -> V_320 ) ;
F_65 () ;
F_5 ( V_7 , L_455 ) ;
V_142 = F_320 ( & V_31 -> V_150 -> V_741 ,
struct V_114 , V_514 ) ;
if ( & V_142 -> V_514 != & V_31 -> V_150 -> V_741 )
F_84 ( V_7 , V_142 , L_456 ) ;
V_142 = F_321 ( & V_31 -> V_150 -> V_741 ,
struct V_114 , V_514 ) ;
if ( & V_142 -> V_514 != & V_31 -> V_150 -> V_741 )
F_84 ( V_7 , V_142 , L_457 ) ;
V_142 = F_322 ( V_31 ) ;
if ( V_142 ) {
F_84 ( V_7 , V_142 , L_458 ) ;
F_5 ( V_7 ,
L_459 ,
V_142 -> V_459 , V_142 -> V_742 , V_142 -> V_460 ,
V_142 -> V_743 ? F_323 ( V_142 -> V_743 -> V_3 . V_41 ) : ~ 0u ,
V_142 -> V_743 ? F_324 ( V_142 -> V_743 -> V_3 . V_41 ) : ~ 0u ) ;
}
F_5 ( V_7 , L_460 ,
F_79 ( F_325 ( V_31 -> V_744 ) ) ,
V_142 ? F_209 ( V_142 -> V_96 -> V_28 ) : 0 ) ;
F_5 ( V_7 , L_461 ,
F_79 ( F_326 ( V_31 -> V_744 ) ) & V_745 ,
V_142 ? V_142 -> V_96 -> V_459 : 0 ) ;
F_5 ( V_7 , L_462 ,
F_79 ( F_327 ( V_31 -> V_744 ) ) & V_746 ,
V_142 ? V_142 -> V_96 -> V_460 : 0 ) ;
F_5 ( V_7 , L_463 ,
F_79 ( F_328 ( V_31 -> V_744 ) ) ,
F_79 ( F_328 ( V_31 -> V_744 ) ) & ( V_747 | V_748 ) ? L_464 : L_13 ) ;
F_67 () ;
V_135 = F_150 ( V_31 ) ;
F_5 ( V_7 , L_465 ,
F_323 ( V_135 ) , F_324 ( V_135 ) ) ;
V_135 = F_329 ( V_31 ) ;
F_5 ( V_7 , L_466 ,
F_323 ( V_135 ) , F_324 ( V_135 ) ) ;
if ( V_209 . V_469 ) {
T_4 V_74 , V_749 , V_750 ;
struct V_156 * V_157 ;
F_5 ( V_7 , L_467 ,
F_79 ( F_330 ( V_31 ) ) ,
F_79 ( F_331 ( V_31 ) ) ) ;
V_74 = F_79 ( F_332 ( V_31 ) ) ;
V_749 = F_333 ( V_74 ) ;
V_750 = F_334 ( V_74 ) ;
F_5 ( V_7 , L_468 ,
V_749 , V_750 ) ;
if ( V_749 >= V_751 )
V_749 = 0 ;
if ( V_750 >= V_751 )
V_750 = 0 ;
if ( V_749 > V_750 )
V_750 += V_751 ;
while ( V_749 < V_750 ) {
unsigned int V_752 = ++ V_749 % V_751 ;
F_5 ( V_7 , L_469 ,
V_752 ,
F_79 ( F_335 ( V_31 , V_752 ) ) ,
F_79 ( F_336 ( V_31 , V_752 ) ) ) ;
}
F_65 () ;
V_142 = F_42 ( V_31 -> V_753 [ 0 ] . V_115 ) ;
if ( V_142 ) {
F_5 ( V_7 , L_470 ,
V_31 -> V_753 [ 0 ] . V_68 ) ;
F_84 ( V_7 , V_142 , L_471 ) ;
} else {
F_5 ( V_7 , L_472 ) ;
}
V_142 = F_42 ( V_31 -> V_753 [ 1 ] . V_115 ) ;
if ( V_142 ) {
F_5 ( V_7 , L_473 ,
V_31 -> V_753 [ 1 ] . V_68 ) ;
F_84 ( V_7 , V_142 , L_471 ) ;
} else {
F_5 ( V_7 , L_474 ) ;
}
F_67 () ;
F_73 ( & V_31 -> V_150 -> V_404 ) ;
for ( V_157 = V_31 -> V_754 ; V_157 ; V_157 = F_89 ( V_157 ) ) {
V_142 = F_90 ( V_157 , F_91 ( * V_142 ) , V_146 . V_3 ) ;
F_84 ( V_7 , V_142 , L_475 ) ;
}
F_82 ( & V_31 -> V_150 -> V_404 ) ;
} else if ( F_10 ( V_11 ) > 6 ) {
F_5 ( V_7 , L_476 ,
F_79 ( F_227 ( V_31 ) ) ) ;
F_5 ( V_7 , L_477 ,
F_79 ( F_228 ( V_31 ) ) ) ;
F_5 ( V_7 , L_478 ,
F_79 ( F_229 ( V_31 ) ) ) ;
}
F_73 ( & V_61 -> V_158 ) ;
for ( V_157 = F_88 ( & V_61 -> V_159 ) ; V_157 ; V_157 = F_89 ( V_157 ) ) {
struct V_160 * V_161 = F_90 ( V_157 , F_91 ( * V_161 ) , V_3 ) ;
F_5 ( V_7 , L_175 ,
V_161 -> V_162 -> V_124 , V_161 -> V_162 -> V_122 , V_161 -> V_145 ) ;
}
F_82 ( & V_61 -> V_158 ) ;
F_35 ( V_7 , L_390 ) ;
}
F_111 ( V_11 ) ;
return 0 ;
}
static int F_337 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
int V_755 = F_9 ( V_11 ) -> V_755 ;
enum V_89 V_55 ;
int V_90 , V_70 ;
if ( ! V_209 . V_756 ) {
F_35 ( V_7 , L_479 ) ;
return 0 ;
}
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_94 ( V_11 ) ;
if ( F_138 ( V_11 ) ) {
struct V_465 * V_465 ;
T_12 * V_145 ;
V_465 = F_211 ( V_11 -> V_757 -> V_18 , 0 ) ;
V_145 = ( T_12 * ) F_212 ( V_465 ) ;
F_53 (engine, dev_priv, id) {
T_12 V_46 ;
F_5 ( V_7 , L_291 , V_31 -> V_8 ) ;
F_35 ( V_7 , L_480 ) ;
for ( V_90 = 0 ; V_90 < V_755 ; V_90 ++ ) {
V_46 = V_55 * V_304 + V_90 ;
F_5 ( V_7 , L_481 ,
V_145 [ V_46 ] , V_46 * 8 ) ;
}
F_46 ( V_7 , '\n' ) ;
F_35 ( V_7 , L_482 ) ;
for ( V_90 = 0 ; V_90 < V_755 ; V_90 ++ ) {
V_46 = V_55 + ( V_90 * V_304 ) ;
F_5 ( V_7 , L_481 ,
V_145 [ V_46 ] , V_46 * 8 ) ;
}
F_46 ( V_7 , '\n' ) ;
}
F_213 ( V_145 ) ;
} else {
F_35 ( V_7 , L_480 ) ;
F_53 (engine, dev_priv, id)
for ( V_90 = 0 ; V_90 < V_755 ; V_90 ++ )
F_5 ( V_7 , L_483 ,
F_79 ( V_31 -> V_757 . V_758 . signal [ V_90 ] ) ) ;
F_46 ( V_7 , '\n' ) ;
}
F_111 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static int F_338 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_163 ;
F_259 ( V_5 ) ;
for ( V_163 = 0 ; V_163 < V_11 -> V_759 ; V_163 ++ ) {
struct V_760 * V_761 = & V_11 -> V_762 [ V_163 ] ;
F_5 ( V_7 , L_484 , V_163 , V_761 -> V_8 , V_761 -> V_55 ) ;
F_5 ( V_7 , L_485 ,
V_761 -> V_95 . V_763 , V_761 -> V_764 , F_6 ( V_761 -> V_765 ) ) ;
F_5 ( V_7 , L_486 ) ;
F_5 ( V_7 , L_487 , V_761 -> V_95 . V_766 . V_767 ) ;
F_5 ( V_7 , L_488 ,
V_761 -> V_95 . V_766 . V_768 ) ;
F_5 ( V_7 , L_489 , V_761 -> V_95 . V_766 . V_769 ) ;
F_5 ( V_7 , L_490 , V_761 -> V_95 . V_766 . V_770 ) ;
F_5 ( V_7 , L_491 , V_761 -> V_95 . V_766 . V_771 ) ;
}
F_265 ( V_5 ) ;
return 0 ;
}
static int F_339 ( struct V_6 * V_7 , void * V_219 )
{
int V_163 ;
int V_70 ;
struct V_30 * V_31 ;
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_772 * V_773 = & V_11 -> V_773 ;
enum V_89 V_55 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_492 , V_773 -> V_68 ) ;
F_53 (engine, dev_priv, id)
F_5 ( V_7 , L_493 ,
V_31 -> V_8 , V_773 -> V_774 [ V_55 ] ) ;
for ( V_163 = 0 ; V_163 < V_773 -> V_68 ; ++ V_163 ) {
T_10 V_135 ;
T_4 V_406 , V_775 , V_749 ;
bool V_776 ;
V_135 = V_773 -> V_354 [ V_163 ] . V_135 ;
V_406 = V_773 -> V_354 [ V_163 ] . V_406 ;
V_775 = V_773 -> V_354 [ V_163 ] . V_775 ;
V_749 = F_79 ( V_135 ) ;
V_776 = ( V_775 & V_406 ) == ( V_749 & V_406 ) ;
F_5 ( V_7 , L_494 ,
F_340 ( V_135 ) , V_775 , V_406 , V_749 , V_776 ? L_495 : L_496 ) ;
}
F_111 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static int F_341 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_777 * V_778 ;
struct V_779 * V_780 ;
enum V_129 V_129 ;
int V_50 ;
if ( F_10 ( V_11 ) < 9 )
return 0 ;
F_259 ( V_5 ) ;
V_778 = & V_11 -> V_781 . V_782 . V_778 ;
F_5 ( V_7 , L_497 , L_13 , L_498 , L_499 , L_500 ) ;
F_96 (dev_priv, pipe) {
F_5 ( V_7 , L_501 , F_71 ( V_129 ) ) ;
F_342 (dev_priv, pipe, plane) {
V_780 = & V_778 -> V_50 [ V_129 ] [ V_50 ] ;
F_5 ( V_7 , L_502 , V_50 + 1 ,
V_780 -> V_41 , V_780 -> V_783 ,
F_343 ( V_780 ) ) ;
}
V_780 = & V_778 -> V_50 [ V_129 ] [ V_784 ] ;
F_5 ( V_7 , L_503 , L_504 , V_780 -> V_41 ,
V_780 -> V_783 , F_343 ( V_780 ) ) ;
}
F_265 ( V_5 ) ;
return 0 ;
}
static void F_344 ( struct V_6 * V_7 ,
struct V_62 * V_5 ,
struct V_127 * V_127 )
{
struct V_1 * V_11 = F_2 ( V_5 ) ;
struct V_785 * V_786 = & V_11 -> V_786 ;
int V_644 = 0 ;
struct V_656 * V_608 ;
struct V_609 V_610 ;
F_260 ( V_5 , & V_610 ) ;
F_318 (connector, &conn_iter) {
if ( V_608 -> V_95 -> V_128 != & V_127 -> V_29 )
continue;
F_5 ( V_7 , L_172 , V_608 -> V_8 ) ;
}
F_264 ( & V_610 ) ;
if ( V_11 -> V_442 . V_787 == V_788 )
F_35 ( V_7 , L_505 ) ;
else if ( V_11 -> V_442 . V_787 == V_789 )
F_35 ( V_7 , L_506 ) ;
else if ( V_11 -> V_442 . V_787 == V_790 )
F_35 ( V_7 , L_507 ) ;
else
F_35 ( V_7 , L_508 ) ;
F_35 ( V_7 , L_509 ) ;
if ( F_314 ( V_127 -> V_29 . V_95 ) -> V_791 ) {
struct V_664 * V_665 ;
F_58 ( & V_786 -> V_731 ) ;
F_35 ( V_7 , L_510 ) ;
if ( ! V_786 -> V_676 ) {
F_35 ( V_7 , L_511 ) ;
F_47 ( & V_786 -> V_731 ) ;
return;
}
V_665 = & V_786 -> V_676 -> V_792 -> V_665 ;
F_5 ( V_7 , L_512 ,
V_786 -> V_591 ) ;
F_35 ( V_7 , L_513 ) ;
if ( V_786 -> V_793 == V_794 ) {
F_35 ( V_7 , L_514 ) ;
V_644 = V_665 -> V_666 -> V_644 ;
} else if ( V_786 -> V_793 == V_795 ) {
F_35 ( V_7 , L_515 ) ;
V_644 = V_665 -> V_796 -> V_644 ;
} else {
F_5 ( V_7 , L_516 ,
V_786 -> V_793 ) ;
F_47 ( & V_786 -> V_731 ) ;
return;
}
F_5 ( V_7 , L_517 , V_644 ) ;
F_35 ( V_7 , L_513 ) ;
F_47 ( & V_786 -> V_731 ) ;
} else {
F_35 ( V_7 , L_518 ) ;
}
F_35 ( V_7 , L_390 ) ;
}
static int F_345 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_127 * V_127 ;
int V_797 = 0 ;
F_259 ( V_5 ) ;
F_70 (dev, intel_crtc) {
if ( V_127 -> V_29 . V_95 -> V_87 ) {
V_797 ++ ;
F_5 ( V_7 , L_519 , V_797 ) ;
F_344 ( V_7 , V_5 , V_127 ) ;
}
}
F_265 ( V_5 ) ;
if ( ! V_797 )
F_35 ( V_7 , L_520 ) ;
return 0 ;
}
static int F_346 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_653 * V_653 ;
struct V_674 * V_675 ;
struct V_656 * V_608 ;
struct V_609 V_610 ;
F_260 ( V_5 , & V_610 ) ;
F_318 (connector, &conn_iter) {
if ( V_608 -> V_615 != V_686 )
continue;
V_653 = F_347 ( V_608 ) ;
if ( ! V_653 || V_653 -> type == V_685 )
continue;
V_675 = F_348 ( & V_653 -> V_29 ) ;
if ( ! V_675 -> V_676 . V_798 )
continue;
F_5 ( V_7 , L_521 ,
F_349 ( V_675 -> V_678 ) ) ;
F_350 ( V_7 , & V_675 -> V_676 . V_677 ) ;
}
F_264 ( & V_610 ) ;
return 0 ;
}
static T_5 F_351 ( struct V_85 * V_85 ,
const char T_6 * V_202 ,
T_7 V_799 , T_8 * V_800 )
{
char * V_801 ;
int V_657 = 0 ;
struct V_62 * V_5 ;
struct V_656 * V_608 ;
struct V_609 V_610 ;
struct V_611 * V_611 ;
int V_218 = 0 ;
V_5 = ( (struct V_6 * ) V_85 -> V_205 ) -> V_12 ;
if ( V_799 == 0 )
return 0 ;
V_801 = F_352 ( V_799 + 1 , V_802 ) ;
if ( ! V_801 )
return - V_72 ;
if ( F_353 ( V_801 , V_202 , V_799 ) ) {
V_657 = - V_803 ;
goto V_73;
}
V_801 [ V_799 ] = '\0' ;
F_123 ( L_522 , ( unsigned int ) V_799 ) ;
F_260 ( V_5 , & V_610 ) ;
F_318 (connector, &conn_iter) {
if ( V_608 -> V_615 !=
V_686 )
continue;
if ( V_608 -> V_657 == V_658 &&
V_608 -> V_655 != NULL ) {
V_611 = F_262 ( V_608 -> V_655 ) ;
V_657 = F_354 ( V_801 , 10 , & V_218 ) ;
if ( V_657 < 0 )
break;
F_123 ( L_523 , V_218 ) ;
if ( V_218 == 1 )
V_611 -> V_804 . V_805 = 1 ;
else
V_611 -> V_804 . V_805 = 0 ;
}
}
F_264 ( & V_610 ) ;
V_73:
F_355 ( V_801 ) ;
if ( V_657 < 0 )
return V_657 ;
* V_800 += V_799 ;
return V_799 ;
}
static int F_356 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_656 * V_608 ;
struct V_609 V_610 ;
struct V_611 * V_611 ;
F_260 ( V_5 , & V_610 ) ;
F_318 (connector, &conn_iter) {
if ( V_608 -> V_615 !=
V_686 )
continue;
if ( V_608 -> V_657 == V_658 &&
V_608 -> V_655 != NULL ) {
V_611 = F_262 ( V_608 -> V_655 ) ;
if ( V_611 -> V_804 . V_805 )
F_35 ( V_7 , L_524 ) ;
else
F_35 ( V_7 , L_525 ) ;
} else
F_35 ( V_7 , L_525 ) ;
}
F_264 ( & V_610 ) ;
return 0 ;
}
static int F_357 ( struct V_212 * V_212 ,
struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
return F_358 ( V_85 , F_356 ,
& V_11 -> V_63 ) ;
}
static int F_359 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_656 * V_608 ;
struct V_609 V_610 ;
struct V_611 * V_611 ;
F_260 ( V_5 , & V_610 ) ;
F_318 (connector, &conn_iter) {
if ( V_608 -> V_615 !=
V_686 )
continue;
if ( V_608 -> V_657 == V_658 &&
V_608 -> V_655 != NULL ) {
V_611 = F_262 ( V_608 -> V_655 ) ;
if ( V_611 -> V_804 . V_806 ==
V_807 )
F_5 ( V_7 , L_526 ,
V_611 -> V_804 . V_808 . V_809 ) ;
else if ( V_611 -> V_804 . V_806 ==
V_810 ) {
F_5 ( V_7 , L_527 ,
V_611 -> V_804 . V_808 . V_645 ) ;
F_5 ( V_7 , L_528 ,
V_611 -> V_804 . V_808 . V_649 ) ;
F_5 ( V_7 , L_529 ,
V_611 -> V_804 . V_808 . V_811 ) ;
}
} else
F_35 ( V_7 , L_525 ) ;
}
F_264 ( & V_610 ) ;
return 0 ;
}
static int F_360 ( struct V_212 * V_212 ,
struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
return F_358 ( V_85 , F_359 ,
& V_11 -> V_63 ) ;
}
static int F_361 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_656 * V_608 ;
struct V_609 V_610 ;
struct V_611 * V_611 ;
F_260 ( V_5 , & V_610 ) ;
F_318 (connector, &conn_iter) {
if ( V_608 -> V_615 !=
V_686 )
continue;
if ( V_608 -> V_657 == V_658 &&
V_608 -> V_655 != NULL ) {
V_611 = F_262 ( V_608 -> V_655 ) ;
F_5 ( V_7 , L_530 , V_611 -> V_804 . V_806 ) ;
} else
F_35 ( V_7 , L_525 ) ;
}
F_264 ( & V_610 ) ;
return 0 ;
}
static int F_362 ( struct V_212 * V_212 ,
struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
return F_358 ( V_85 , F_361 ,
& V_11 -> V_63 ) ;
}
static void F_363 ( struct V_6 * V_7 , const T_14 V_781 [ 8 ] )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_812 ;
int V_813 ;
if ( F_95 ( V_11 ) )
V_813 = 3 ;
else if ( F_108 ( V_11 ) )
V_813 = 1 ;
else
V_813 = F_364 ( V_11 ) + 1 ;
F_259 ( V_5 ) ;
for ( V_812 = 0 ; V_812 < V_813 ; V_812 ++ ) {
unsigned int V_814 = V_781 [ V_812 ] ;
if ( F_10 ( V_11 ) >= 9 || F_108 ( V_11 ) ||
F_95 ( V_11 ) )
V_814 *= 10 ;
else if ( V_812 > 0 )
V_814 *= 5 ;
F_5 ( V_7 , L_531 ,
V_812 , V_781 [ V_812 ] , V_814 / 10 , V_814 % 10 ) ;
}
F_265 ( V_5 ) ;
}
static int F_365 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_14 * V_815 ;
if ( F_10 ( V_11 ) >= 9 )
V_815 = V_11 -> V_781 . V_816 ;
else
V_815 = V_11 -> V_781 . V_817 ;
F_363 ( V_7 , V_815 ) ;
return 0 ;
}
static int F_366 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_14 * V_815 ;
if ( F_10 ( V_11 ) >= 9 )
V_815 = V_11 -> V_781 . V_816 ;
else
V_815 = V_11 -> V_781 . V_818 ;
F_363 ( V_7 , V_815 ) ;
return 0 ;
}
static int F_367 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_14 * V_815 ;
if ( F_10 ( V_11 ) >= 9 )
V_815 = V_11 -> V_781 . V_816 ;
else
V_815 = V_11 -> V_781 . V_819 ;
F_363 ( V_7 , V_815 ) ;
return 0 ;
}
static int F_368 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
if ( F_10 ( V_11 ) < 5 )
return - V_410 ;
return F_358 ( V_85 , F_365 , V_11 ) ;
}
static int F_369 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
if ( F_370 ( V_11 ) )
return - V_410 ;
return F_358 ( V_85 , F_366 , V_11 ) ;
}
static int F_371 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
if ( F_370 ( V_11 ) )
return - V_410 ;
return F_358 ( V_85 , F_367 , V_11 ) ;
}
static T_5 F_372 ( struct V_85 * V_85 , const char T_6 * V_202 ,
T_7 V_799 , T_8 * V_800 , T_14 V_781 [ 8 ] )
{
struct V_6 * V_7 = V_85 -> V_205 ;
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
T_14 V_820 [ 8 ] = { 0 } ;
int V_813 ;
int V_812 ;
int V_70 ;
char V_208 [ 32 ] ;
if ( F_95 ( V_11 ) )
V_813 = 3 ;
else if ( F_108 ( V_11 ) )
V_813 = 1 ;
else
V_813 = F_364 ( V_11 ) + 1 ;
if ( V_799 >= sizeof( V_208 ) )
return - V_581 ;
if ( F_353 ( V_208 , V_202 , V_799 ) )
return - V_803 ;
V_208 [ V_799 ] = '\0' ;
V_70 = sscanf ( V_208 , L_532 ,
& V_820 [ 0 ] , & V_820 [ 1 ] , & V_820 [ 2 ] , & V_820 [ 3 ] ,
& V_820 [ 4 ] , & V_820 [ 5 ] , & V_820 [ 6 ] , & V_820 [ 7 ] ) ;
if ( V_70 != V_813 )
return - V_581 ;
F_259 ( V_5 ) ;
for ( V_812 = 0 ; V_812 < V_813 ; V_812 ++ )
V_781 [ V_812 ] = V_820 [ V_812 ] ;
F_265 ( V_5 ) ;
return V_799 ;
}
static T_5 F_373 ( struct V_85 * V_85 , const char T_6 * V_202 ,
T_7 V_799 , T_8 * V_800 )
{
struct V_6 * V_7 = V_85 -> V_205 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_14 * V_815 ;
if ( F_10 ( V_11 ) >= 9 )
V_815 = V_11 -> V_781 . V_816 ;
else
V_815 = V_11 -> V_781 . V_817 ;
return F_372 ( V_85 , V_202 , V_799 , V_800 , V_815 ) ;
}
static T_5 F_374 ( struct V_85 * V_85 , const char T_6 * V_202 ,
T_7 V_799 , T_8 * V_800 )
{
struct V_6 * V_7 = V_85 -> V_205 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_14 * V_815 ;
if ( F_10 ( V_11 ) >= 9 )
V_815 = V_11 -> V_781 . V_816 ;
else
V_815 = V_11 -> V_781 . V_818 ;
return F_372 ( V_85 , V_202 , V_799 , V_800 , V_815 ) ;
}
static T_5 F_375 ( struct V_85 * V_85 , const char T_6 * V_202 ,
T_7 V_799 , T_8 * V_800 )
{
struct V_6 * V_7 = V_85 -> V_205 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_14 * V_815 ;
if ( F_10 ( V_11 ) >= 9 )
V_815 = V_11 -> V_781 . V_816 ;
else
V_815 = V_11 -> V_781 . V_819 ;
return F_372 ( V_85 , V_202 , V_799 , V_800 , V_815 ) ;
}
static int
F_376 ( void * V_10 , T_3 * V_218 )
{
struct V_1 * V_11 = V_10 ;
* V_218 = F_377 ( & V_11 -> V_306 ) ;
return 0 ;
}
static int
F_378 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_209 = V_10 ;
struct V_30 * V_31 ;
unsigned int V_208 ;
if ( F_379 ( & V_209 -> V_306 ) )
return - V_821 ;
F_380 (engine, i915, val, tmp) {
V_31 -> V_319 . V_145 = F_75 ( V_31 ) ;
V_31 -> V_319 . V_322 = true ;
}
F_381 ( V_209 , V_218 , L_533 , V_218 ) ;
F_382 ( & V_209 -> V_306 . V_307 ,
V_309 ,
V_822 ) ;
return 0 ;
}
static int
F_383 ( struct V_1 * V_209 ,
unsigned long * V_823 ,
unsigned long V_218 )
{
int V_399 ;
V_399 = F_44 ( & V_209 -> V_63 . V_34 ) ;
if ( V_399 )
return V_399 ;
V_399 = F_384 ( V_209 ,
V_824 |
V_825 ) ;
if ( V_399 )
goto V_826;
* V_823 = V_218 ;
F_47 ( & V_209 -> V_63 . V_34 ) ;
while ( F_385 ( & V_209 -> V_317 . V_827 ) )
;
return 0 ;
V_826:
F_47 ( & V_209 -> V_63 . V_34 ) ;
return V_399 ;
}
static int
F_386 ( void * V_10 , T_3 * V_218 )
{
struct V_1 * V_11 = V_10 ;
* V_218 = V_11 -> V_306 . V_321 ;
return 0 ;
}
static int
F_387 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_209 = V_10 ;
return F_383 ( V_209 , & V_209 -> V_306 . V_321 , V_218 ) ;
}
static int
F_388 ( void * V_10 , T_3 * V_218 )
{
struct V_1 * V_11 = V_10 ;
* V_218 = V_11 -> V_306 . V_828 ;
return 0 ;
}
static int
F_389 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_209 = V_10 ;
V_218 &= F_9 ( V_209 ) -> V_829 ;
F_123 ( L_534 , V_218 ) ;
return F_383 ( V_209 , & V_209 -> V_306 . V_828 , V_218 ) ;
}
static int
F_390 ( void * V_10 , T_3 * V_218 )
{
* V_218 = V_830 ;
return 0 ;
}
static int
F_391 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_11 = V_10 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_70 ;
F_392 ( L_535 , V_218 ) ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
if ( V_218 & V_831 ) {
V_70 = F_384 ( V_11 ,
V_825 |
V_824 ) ;
if ( V_70 )
goto V_832;
}
if ( V_218 & V_833 )
F_393 ( V_11 ) ;
F_394 ( V_802 ) ;
if ( V_218 & V_834 )
F_395 ( V_11 , V_835 , V_836 ) ;
if ( V_218 & V_837 )
F_395 ( V_11 , V_835 , V_838 ) ;
if ( V_218 & V_839 )
F_396 ( V_11 ) ;
F_397 () ;
V_832:
F_47 ( & V_5 -> V_34 ) ;
if ( V_218 & V_840 ) {
F_398 () ;
F_399 ( V_11 ) ;
}
return V_70 ;
}
static int
F_400 ( void * V_10 , T_3 * V_218 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 6 )
return - V_410 ;
* V_218 = F_133 ( V_11 , V_11 -> V_229 . V_436 ) ;
return 0 ;
}
static int
F_401 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_841 , V_842 ;
int V_70 ;
if ( F_10 ( V_11 ) < 6 )
return - V_410 ;
F_123 ( L_536 , V_218 ) ;
V_70 = F_44 ( & V_11 -> V_229 . V_230 ) ;
if ( V_70 )
return V_70 ;
V_218 = F_402 ( V_11 , V_218 ) ;
V_841 = V_11 -> V_229 . V_234 ;
V_842 = V_11 -> V_229 . V_235 ;
if ( V_218 < V_842 || V_218 > V_841 || V_218 < V_11 -> V_229 . V_435 ) {
F_47 ( & V_11 -> V_229 . V_230 ) ;
return - V_581 ;
}
V_11 -> V_229 . V_436 = V_218 ;
if ( F_403 ( V_11 , V_218 ) )
F_123 ( L_537 ) ;
F_47 ( & V_11 -> V_229 . V_230 ) ;
return 0 ;
}
static int
F_404 ( void * V_10 , T_3 * V_218 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 6 )
return - V_410 ;
* V_218 = F_133 ( V_11 , V_11 -> V_229 . V_435 ) ;
return 0 ;
}
static int
F_405 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_841 , V_842 ;
int V_70 ;
if ( F_10 ( V_11 ) < 6 )
return - V_410 ;
F_123 ( L_538 , V_218 ) ;
V_70 = F_44 ( & V_11 -> V_229 . V_230 ) ;
if ( V_70 )
return V_70 ;
V_218 = F_402 ( V_11 , V_218 ) ;
V_841 = V_11 -> V_229 . V_234 ;
V_842 = V_11 -> V_229 . V_235 ;
if ( V_218 < V_842 ||
V_218 > V_841 || V_218 > V_11 -> V_229 . V_436 ) {
F_47 ( & V_11 -> V_229 . V_230 ) ;
return - V_581 ;
}
V_11 -> V_229 . V_435 = V_218 ;
if ( F_403 ( V_11 , V_218 ) )
F_123 ( L_537 ) ;
F_47 ( & V_11 -> V_229 . V_230 ) ;
return 0 ;
}
static int
F_406 ( void * V_10 , T_3 * V_218 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_843 ;
if ( ! ( F_140 ( V_11 ) || F_141 ( V_11 ) ) )
return - V_410 ;
F_94 ( V_11 ) ;
V_843 = F_79 ( V_844 ) ;
F_111 ( V_11 ) ;
* V_218 = ( V_843 & V_845 ) >> V_846 ;
return 0 ;
}
static int
F_407 ( void * V_10 , T_3 V_218 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_843 ;
if ( ! ( F_140 ( V_11 ) || F_141 ( V_11 ) ) )
return - V_410 ;
if ( V_218 > 3 )
return - V_581 ;
F_94 ( V_11 ) ;
F_123 ( L_539 , V_218 ) ;
V_843 = F_79 ( V_844 ) ;
V_843 &= ~ V_845 ;
V_843 |= ( V_218 << V_846 ) ;
F_178 ( V_844 , V_843 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static void F_408 ( struct V_1 * V_11 ,
struct V_847 * V_848 )
{
int V_849 = 2 ;
int V_850 ;
T_4 V_851 [ V_849 ] , V_852 [ V_849 ] ;
V_851 [ 0 ] = F_79 ( V_853 ) ;
V_851 [ 1 ] = F_79 ( V_854 ) ;
V_852 [ 0 ] = F_79 ( V_855 ) ;
V_852 [ 1 ] = F_79 ( V_856 ) ;
for ( V_850 = 0 ; V_850 < V_849 ; V_850 ++ ) {
unsigned int V_857 ;
if ( V_851 [ V_850 ] & V_858 )
continue;
V_848 -> V_859 = F_409 ( 0 ) ;
V_848 -> V_860 |= F_409 ( V_850 ) ;
V_857 = ( ( V_851 [ V_850 ] & V_861 ) ? 0 : 2 ) +
( ( V_851 [ V_850 ] & V_862 ) ? 0 : 2 ) +
( ( V_851 [ V_850 ] & V_863 ) ? 0 : 2 ) +
( ( V_852 [ V_850 ] & V_864 ) ? 0 : 2 ) ;
V_848 -> V_865 += V_857 ;
V_848 -> V_866 = F_410 (unsigned int,
sseu->eu_per_subslice, eu_cnt) ;
}
}
static void F_411 ( struct V_1 * V_11 ,
struct V_847 * V_848 )
{
int V_867 = 3 , V_849 = 4 ;
int V_868 , V_850 ;
T_4 V_869 [ V_867 ] , V_870 [ 2 * V_867 ] , V_871 [ 2 ] ;
if ( F_134 ( V_11 ) ) {
V_867 = 1 ;
V_849 = 3 ;
}
for ( V_868 = 0 ; V_868 < V_867 ; V_868 ++ ) {
V_869 [ V_868 ] = F_79 ( F_412 ( V_868 ) ) ;
V_870 [ 2 * V_868 ] = F_79 ( F_413 ( V_868 ) ) ;
V_870 [ 2 * V_868 + 1 ] = F_79 ( F_414 ( V_868 ) ) ;
}
V_871 [ 0 ] = V_872 |
V_873 |
V_874 |
V_875 ;
V_871 [ 1 ] = V_876 |
V_877 |
V_878 |
V_879 ;
for ( V_868 = 0 ; V_868 < V_867 ; V_868 ++ ) {
if ( ( V_869 [ V_868 ] & V_880 ) == 0 )
continue;
V_848 -> V_859 |= F_409 ( V_868 ) ;
if ( F_144 ( V_11 ) )
V_848 -> V_860 =
F_9 ( V_11 ) -> V_848 . V_860 ;
for ( V_850 = 0 ; V_850 < V_849 ; V_850 ++ ) {
unsigned int V_857 ;
if ( F_134 ( V_11 ) ) {
if ( ! ( V_869 [ V_868 ] & ( F_415 ( V_850 ) ) ) )
continue;
V_848 -> V_860 |= F_409 ( V_850 ) ;
}
V_857 = 2 * F_416 ( V_870 [ 2 * V_868 + V_850 / 2 ] &
V_871 [ V_850 % 2 ] ) ;
V_848 -> V_865 += V_857 ;
V_848 -> V_866 = F_410 (unsigned int,
sseu->eu_per_subslice,
eu_cnt) ;
}
}
}
static void F_417 ( struct V_1 * V_11 ,
struct V_847 * V_848 )
{
T_4 V_881 = F_79 ( V_882 ) ;
int V_868 ;
V_848 -> V_859 = V_881 & V_883 ;
if ( V_848 -> V_859 ) {
V_848 -> V_860 = F_9 ( V_11 ) -> V_848 . V_860 ;
V_848 -> V_866 =
F_9 ( V_11 ) -> V_848 . V_866 ;
V_848 -> V_865 = V_848 -> V_866 *
F_418 ( V_848 ) ;
for ( V_868 = 0 ; V_868 < F_419 ( V_848 -> V_859 ) ; V_868 ++ ) {
T_13 V_884 =
F_9 ( V_11 ) -> V_848 . V_884 [ V_868 ] ;
V_848 -> V_865 -= F_420 ( V_884 ) ;
}
}
}
static void F_421 ( struct V_6 * V_7 , bool V_885 ,
const struct V_847 * V_848 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const char * type = V_885 ? L_540 : L_541 ;
F_5 ( V_7 , L_542 , type ,
V_848 -> V_859 ) ;
F_5 ( V_7 , L_543 , type ,
F_420 ( V_848 -> V_859 ) ) ;
F_5 ( V_7 , L_544 , type ,
F_418 ( V_848 ) ) ;
F_5 ( V_7 , L_545 , type ,
V_848 -> V_860 ) ;
F_5 ( V_7 , L_546 , type ,
F_420 ( V_848 -> V_860 ) ) ;
F_5 ( V_7 , L_547 , type ,
V_848 -> V_865 ) ;
F_5 ( V_7 , L_548 , type ,
V_848 -> V_866 ) ;
if ( ! V_885 )
return;
F_5 ( V_7 , L_549 , F_6 ( F_422 ( V_11 ) ) ) ;
if ( F_422 ( V_11 ) )
F_5 ( V_7 , L_550 , V_848 -> V_886 ) ;
F_5 ( V_7 , L_551 ,
F_6 ( V_848 -> V_887 ) ) ;
F_5 ( V_7 , L_552 ,
F_6 ( V_848 -> V_888 ) ) ;
F_5 ( V_7 , L_553 ,
F_6 ( V_848 -> V_889 ) ) ;
}
static int F_423 ( struct V_6 * V_7 , void * V_219 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_847 V_848 ;
if ( F_10 ( V_11 ) < 8 )
return - V_410 ;
F_35 ( V_7 , L_554 ) ;
F_421 ( V_7 , true , & F_9 ( V_11 ) -> V_848 ) ;
F_35 ( V_7 , L_555 ) ;
memset ( & V_848 , 0 , sizeof( V_848 ) ) ;
F_94 ( V_11 ) ;
if ( F_95 ( V_11 ) ) {
F_408 ( V_11 , & V_848 ) ;
} else if ( F_138 ( V_11 ) ) {
F_417 ( V_11 , & V_848 ) ;
} else if ( F_10 ( V_11 ) >= 9 ) {
F_411 ( V_11 , & V_848 ) ;
}
F_111 ( V_11 ) ;
F_421 ( V_7 , false , & V_848 ) ;
return 0 ;
}
static int F_424 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
if ( F_10 ( V_11 ) < 6 )
return 0 ;
F_94 ( V_11 ) ;
F_135 ( V_11 , V_263 ) ;
return 0 ;
}
static int F_425 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
struct V_1 * V_11 = V_212 -> V_213 ;
if ( F_10 ( V_11 ) < 6 )
return 0 ;
F_139 ( V_11 , V_263 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_426 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_890 * V_891 = & V_11 -> V_891 ;
F_5 ( V_7 , L_556 , V_891 -> V_892 ) ;
F_5 ( V_7 , L_557 ,
F_6 ( F_153 ( & V_891 -> V_893 ) ) ) ;
return 0 ;
}
static T_5 F_427 ( struct V_85 * V_85 ,
const char T_6 * V_202 , T_7 V_799 ,
T_8 * V_800 )
{
struct V_6 * V_7 = V_85 -> V_205 ;
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_890 * V_891 = & V_11 -> V_891 ;
unsigned int V_894 ;
int V_163 ;
char * V_895 ;
char V_208 [ 16 ] ;
if ( V_799 >= sizeof( V_208 ) )
return - V_581 ;
if ( F_353 ( V_208 , V_202 , V_799 ) )
return - V_803 ;
V_208 [ V_799 ] = '\0' ;
V_895 = strchr ( V_208 , '\n' ) ;
if ( V_895 )
* V_895 = '\0' ;
if ( strcmp ( V_208 , L_558 ) == 0 )
V_894 = V_896 ;
else if ( F_428 ( V_208 , 10 , & V_894 ) != 0 )
return - V_581 ;
if ( V_894 > 0 )
F_429 ( L_559 ,
V_894 ) ;
else
F_429 ( L_560 ) ;
F_73 ( & V_11 -> V_897 ) ;
V_891 -> V_892 = V_894 ;
F_430 (i)
V_891 -> V_76 [ V_163 ] . V_68 = 0 ;
F_82 ( & V_11 -> V_897 ) ;
F_385 ( & V_11 -> V_891 . V_893 ) ;
return V_799 ;
}
static int F_431 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
return F_358 ( V_85 , F_426 , V_212 -> V_213 ) ;
}
int F_432 ( struct V_1 * V_11 )
{
struct V_898 * V_4 = V_11 -> V_63 . V_661 ;
struct V_899 * V_900 ;
int V_70 , V_163 ;
V_900 = F_433 ( L_561 , V_901 ,
V_4 -> V_902 , F_2 ( V_4 -> V_5 ) ,
& V_903 ) ;
if ( ! V_900 )
return - V_72 ;
V_70 = F_434 ( V_4 ) ;
if ( V_70 )
return V_70 ;
for ( V_163 = 0 ; V_163 < F_54 ( V_904 ) ; V_163 ++ ) {
V_900 = F_433 ( V_904 [ V_163 ] . V_8 ,
V_905 | V_906 ,
V_4 -> V_902 ,
F_2 ( V_4 -> V_5 ) ,
V_904 [ V_163 ] . V_907 ) ;
if ( ! V_900 )
return - V_72 ;
}
return F_435 ( V_908 ,
V_909 ,
V_4 -> V_902 , V_4 ) ;
}
static int F_436 ( struct V_6 * V_7 , void * V_10 )
{
struct V_656 * V_608 = V_7 -> V_12 ;
struct V_611 * V_611 =
F_262 ( & F_347 ( V_608 ) -> V_29 ) ;
T_15 V_210 [ 16 ] ;
T_5 V_399 ;
int V_163 ;
if ( V_608 -> V_657 != V_658 )
return - V_410 ;
for ( V_163 = 0 ; V_163 < F_54 ( V_910 ) ; V_163 ++ ) {
const struct V_911 * V_61 = & V_910 [ V_163 ] ;
T_7 V_26 = V_61 -> V_783 ? V_61 -> V_783 - V_61 -> V_46 + 1 : ( V_61 -> V_26 ? : 1 ) ;
if ( V_61 -> V_912 &&
V_608 -> V_615 != V_616 )
continue;
if ( F_437 ( V_26 > sizeof( V_210 ) ) )
continue;
V_399 = F_438 ( & V_611 -> V_671 , V_61 -> V_46 , V_210 , V_26 ) ;
if ( V_399 <= 0 ) {
F_439 ( L_562 ,
V_26 , V_61 -> V_46 , V_399 ) ;
continue;
}
F_5 ( V_7 , L_563 , V_61 -> V_46 , ( int ) V_26 , V_210 ) ;
}
return 0 ;
}
static int F_440 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
return F_358 ( V_85 , F_436 , V_212 -> V_213 ) ;
}
static int F_441 ( struct V_6 * V_7 , void * V_10 )
{
struct V_656 * V_608 = V_7 -> V_12 ;
struct V_611 * V_611 =
F_262 ( & F_347 ( V_608 ) -> V_29 ) ;
if ( V_608 -> V_657 != V_658 )
return - V_410 ;
F_5 ( V_7 , L_564 ,
V_611 -> V_913 ) ;
F_5 ( V_7 , L_565 ,
V_611 -> V_914 ) ;
F_5 ( V_7 , L_566 ,
V_611 -> V_915 ) ;
F_5 ( V_7 , L_567 ,
V_611 -> V_916 ) ;
return 0 ;
}
static int F_442 ( struct V_212 * V_212 , struct V_85 * V_85 )
{
return F_358 ( V_85 , F_441 , V_212 -> V_213 ) ;
}
int F_443 ( struct V_656 * V_608 )
{
struct V_899 * V_917 = V_608 -> V_918 ;
if ( ! V_917 )
return - V_410 ;
if ( V_608 -> V_615 == V_686 ||
V_608 -> V_615 == V_616 )
F_433 ( L_568 , V_905 , V_917 ,
V_608 , & V_919 ) ;
if ( V_608 -> V_615 == V_616 )
F_433 ( L_569 , V_905 , V_917 ,
V_608 , & V_920 ) ;
return 0 ;
}
