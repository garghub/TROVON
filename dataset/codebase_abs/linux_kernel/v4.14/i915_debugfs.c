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
V_64 = F_43 ( V_67 , sizeof( * V_64 ) , V_72 ) ;
if ( ! V_64 )
return - V_73 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_74;
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
V_74:
F_48 ( V_64 ) ;
return V_70 ;
}
static int F_49 ( int V_55 , void * V_75 , void * V_10 )
{
struct V_17 * V_18 = V_75 ;
struct V_76 * V_77 = V_10 ;
struct V_27 * V_28 ;
F_32 ( & V_18 -> V_29 . V_5 -> V_34 ) ;
V_77 -> V_68 ++ ;
V_77 -> V_67 += V_18 -> V_29 . V_26 ;
if ( ! V_18 -> V_78 )
V_77 -> V_79 += V_18 -> V_29 . V_26 ;
if ( V_18 -> V_29 . V_8 || V_18 -> V_29 . V_80 )
V_77 -> V_81 += V_18 -> V_29 . V_26 ;
F_28 (vma, &obj->vma_list, obj_link) {
if ( ! F_30 ( & V_28 -> V_3 ) )
continue;
if ( F_29 ( V_28 ) ) {
V_77 -> V_82 += V_28 -> V_3 . V_26 ;
} else {
struct V_83 * V_84 = F_50 ( V_28 -> V_85 ) ;
if ( V_84 -> V_29 . V_86 != V_77 -> V_87 )
continue;
}
if ( F_51 ( V_28 ) )
V_77 -> V_88 += V_28 -> V_3 . V_26 ;
else
V_77 -> V_89 += V_28 -> V_3 . V_26 ;
}
return 0 ;
}
static void F_52 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_17 * V_18 ;
struct V_76 V_77 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_91 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
F_53 (engine, dev_priv, id) {
for ( V_91 = 0 ; V_91 < F_54 ( V_31 -> V_92 . V_93 ) ; V_91 ++ ) {
F_28 (obj,
&engine->batch_pool.cache_list[j],
batch_pool_link)
F_49 ( 0 , V_18 , & V_77 ) ;
}
}
F_55 ( V_7 , L_33 , V_77 ) ;
}
static int F_56 ( int V_55 , void * V_75 , void * V_10 )
{
struct V_94 * V_95 = V_75 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < F_54 ( V_95 -> V_31 ) ; V_69 ++ ) {
if ( V_95 -> V_31 [ V_69 ] . V_96 )
F_49 ( 0 , V_95 -> V_31 [ V_69 ] . V_96 -> V_18 , V_10 ) ;
if ( V_95 -> V_31 [ V_69 ] . V_97 )
F_49 ( 0 , V_95 -> V_31 [ V_69 ] . V_97 -> V_28 -> V_18 , V_10 ) ;
}
return 0 ;
}
static void F_57 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_76 V_77 ;
struct V_98 * V_86 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
F_58 ( & V_5 -> V_34 ) ;
if ( V_11 -> V_99 )
F_56 ( 0 , V_11 -> V_99 , & V_77 ) ;
F_28 (file, &dev->filelist, lhead) {
struct V_100 * V_101 = V_86 -> V_102 ;
F_59 ( & V_101 -> V_103 , F_56 , & V_77 ) ;
}
F_47 ( & V_5 -> V_34 ) ;
F_55 ( V_7 , L_34 , V_77 ) ;
}
static int F_60 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_104 * V_105 = & V_11 -> V_105 ;
T_4 V_68 , V_106 , V_107 , V_108 ;
T_3 V_26 , V_109 , V_110 , V_111 ;
struct V_17 * V_18 ;
struct V_98 * V_86 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_5 ( V_7 , L_35 ,
V_11 -> V_24 . V_71 ,
V_11 -> V_24 . V_112 ) ;
V_26 = V_68 = 0 ;
V_109 = V_106 = 0 ;
V_110 = V_107 = 0 ;
F_28 (obj, &dev_priv->mm.unbound_list, global_link) {
V_26 += V_18 -> V_29 . V_26 ;
++ V_68 ;
if ( V_18 -> V_24 . V_39 == V_40 ) {
V_110 += V_18 -> V_29 . V_26 ;
++ V_107 ;
}
if ( V_18 -> V_24 . V_25 ) {
V_106 ++ ;
V_109 += V_18 -> V_29 . V_26 ;
}
}
F_5 ( V_7 , L_36 , V_68 , V_26 ) ;
V_26 = V_68 = V_111 = V_108 = 0 ;
F_28 (obj, &dev_priv->mm.bound_list, global_link) {
V_26 += V_18 -> V_29 . V_26 ;
++ V_68 ;
if ( V_18 -> V_19 ) {
V_111 += V_18 -> V_29 . V_26 ;
++ V_108 ;
}
if ( V_18 -> V_24 . V_39 == V_40 ) {
V_110 += V_18 -> V_29 . V_26 ;
++ V_107 ;
}
if ( V_18 -> V_24 . V_25 ) {
V_106 ++ ;
V_109 += V_18 -> V_29 . V_26 ;
}
}
F_5 ( V_7 , L_37 ,
V_68 , V_26 ) ;
F_5 ( V_7 , L_38 ,
V_107 , V_110 ) ;
F_5 ( V_7 , L_39 ,
V_106 , V_109 ) ;
F_5 ( V_7 , L_40 ,
V_108 , V_111 ) ;
F_5 ( V_7 , L_41 ,
V_105 -> V_29 . V_67 , V_105 -> V_113 ) ;
F_46 ( V_7 , '\n' ) ;
F_52 ( V_7 , V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
F_58 ( & V_5 -> V_114 ) ;
F_57 ( V_7 , V_11 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_76 V_77 ;
struct V_100 * V_87 = V_86 -> V_102 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
F_58 ( & V_5 -> V_34 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_87 = V_86 -> V_102 ;
F_62 ( & V_86 -> V_119 ) ;
F_59 ( & V_86 -> V_120 , F_49 , & V_77 ) ;
F_63 ( & V_86 -> V_119 ) ;
V_116 = F_64 ( & V_87 -> V_24 . V_121 ,
struct V_115 ,
V_122 ) ;
F_65 () ;
V_118 = F_66 ( V_116 && V_116 -> V_95 -> V_123 ?
V_116 -> V_95 -> V_123 : V_86 -> V_123 ,
V_124 ) ;
F_55 ( V_7 , V_118 ? V_118 -> V_125 : L_42 , V_77 ) ;
F_67 () ;
F_47 ( & V_5 -> V_34 ) ;
}
F_47 ( & V_5 -> V_114 ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 , void * V_10 )
{
struct V_2 * V_3 = V_7 -> V_12 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
bool V_126 = ! ! V_3 -> V_127 -> V_10 ;
struct V_17 * V_18 ;
T_3 V_65 , V_66 ;
int V_68 , V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_65 = V_66 = V_68 = 0 ;
F_28 (obj, &dev_priv->mm.bound_list, global_link) {
if ( V_126 && ! V_18 -> V_19 )
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
struct V_17 * V_18 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_67 = 0 ;
int V_70 , V_91 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_53 (engine, dev_priv, id) {
for ( V_91 = 0 ; V_91 < F_54 ( V_31 -> V_92 . V_93 ) ; V_91 ++ ) {
int V_68 ;
V_68 = 0 ;
F_28 (obj,
&engine->batch_pool.cache_list[j],
batch_pool_link)
V_68 ++ ;
F_5 ( V_7 , L_44 ,
V_31 -> V_8 , V_91 , V_68 ) ;
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
F_5 ( V_7 , L_45 , V_67 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_70 ( struct V_6 * V_7 ,
struct V_115 * V_128 ,
const char * V_129 )
{
F_5 ( V_7 , L_46 , V_129 ,
V_128 -> V_130 , V_128 -> V_95 -> V_131 , V_128 -> V_54 . V_132 ,
V_128 -> V_133 . V_134 ,
F_71 ( V_135 - V_128 -> V_136 ) ,
V_128 -> V_137 -> V_138 -> V_8 ) ;
}
static int F_72 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_115 * V_139 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_70 , V_140 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_140 = 0 ;
F_53 (engine, dev_priv, id) {
int V_68 ;
V_68 = 0 ;
F_28 (req, &engine->timeline->requests, link)
V_68 ++ ;
if ( V_68 == 0 )
continue;
F_5 ( V_7 , L_47 , V_31 -> V_8 , V_68 ) ;
F_28 (req, &engine->timeline->requests, link)
F_70 ( V_7 , V_139 , L_48 ) ;
V_140 ++ ;
}
F_47 ( & V_5 -> V_34 ) ;
if ( V_140 == 0 )
F_35 ( V_7 , L_49 ) ;
return 0 ;
}
static void F_73 ( struct V_6 * V_7 ,
struct V_30 * V_31 )
{
struct V_141 * V_61 = & V_31 -> V_142 ;
struct V_143 * V_144 ;
F_5 ( V_7 , L_50 ,
V_31 -> V_8 , F_74 ( V_31 ) ) ;
F_75 ( & V_61 -> V_145 ) ;
for ( V_144 = F_76 ( & V_61 -> V_146 ) ; V_144 ; V_144 = F_77 ( V_144 ) ) {
struct V_147 * V_148 = F_78 ( V_144 , F_79 ( * V_148 ) , V_3 ) ;
F_5 ( V_7 , L_51 ,
V_31 -> V_8 , V_148 -> V_149 -> V_125 , V_148 -> V_149 -> V_123 , V_148 -> V_132 ) ;
}
F_80 ( & V_61 -> V_145 ) ;
}
static int F_81 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
F_53 (engine, dev_priv, id)
F_73 ( V_7 , V_31 ) ;
return 0 ;
}
static int F_82 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_150 , V_151 ;
F_83 ( V_11 ) ;
if ( F_84 ( V_11 ) ) {
F_5 ( V_7 , L_52 ,
F_85 ( V_152 ) ) ;
F_5 ( V_7 , L_53 ,
F_85 ( V_153 ) ) ;
F_5 ( V_7 , L_54 ,
F_85 ( V_154 ) ) ;
F_5 ( V_7 , L_55 ,
F_85 ( V_155 ) ) ;
F_5 ( V_7 , L_56 ,
F_85 ( V_156 ) ) ;
F_86 (dev_priv, pipe) {
enum V_157 V_158 ;
V_158 = F_87 ( V_151 ) ;
if ( ! F_88 ( V_11 ,
V_158 ) ) {
F_5 ( V_7 , L_57 ,
F_89 ( V_151 ) ) ;
continue;
}
F_5 ( V_7 , L_58 ,
F_89 ( V_151 ) ,
F_85 ( F_90 ( V_151 ) ) ) ;
F_91 ( V_11 , V_158 ) ;
}
F_92 ( V_11 , V_159 ) ;
F_5 ( V_7 , L_59 ,
F_85 ( V_160 ) ) ;
F_5 ( V_7 , L_60 ,
F_85 ( V_161 ) ) ;
F_5 ( V_7 , L_61 ,
F_85 ( V_162 ) ) ;
F_91 ( V_11 , V_159 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
F_5 ( V_7 , L_62 ,
V_150 , F_85 ( F_93 ( V_150 ) ) ) ;
F_5 ( V_7 , L_63 ,
V_150 , F_85 ( F_94 ( V_150 ) ) ) ;
F_5 ( V_7 , L_64 ,
V_150 , F_85 ( F_95 ( V_150 ) ) ) ;
}
F_5 ( V_7 , L_65 ,
F_85 ( V_163 ) ) ;
F_5 ( V_7 , L_66 ,
F_85 ( V_164 ) ) ;
F_5 ( V_7 , L_67 ,
F_85 ( V_165 ) ) ;
} else if ( F_10 ( V_11 ) >= 8 ) {
F_5 ( V_7 , L_52 ,
F_85 ( V_152 ) ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
F_5 ( V_7 , L_62 ,
V_150 , F_85 ( F_93 ( V_150 ) ) ) ;
F_5 ( V_7 , L_63 ,
V_150 , F_85 ( F_94 ( V_150 ) ) ) ;
F_5 ( V_7 , L_64 ,
V_150 , F_85 ( F_95 ( V_150 ) ) ) ;
}
F_86 (dev_priv, pipe) {
enum V_157 V_158 ;
V_158 = F_87 ( V_151 ) ;
if ( ! F_88 ( V_11 ,
V_158 ) ) {
F_5 ( V_7 , L_57 ,
F_89 ( V_151 ) ) ;
continue;
}
F_5 ( V_7 , L_68 ,
F_89 ( V_151 ) ,
F_85 ( F_96 ( V_151 ) ) ) ;
F_5 ( V_7 , L_69 ,
F_89 ( V_151 ) ,
F_85 ( F_97 ( V_151 ) ) ) ;
F_5 ( V_7 , L_70 ,
F_89 ( V_151 ) ,
F_85 ( F_98 ( V_151 ) ) ) ;
F_91 ( V_11 , V_158 ) ;
}
F_5 ( V_7 , L_71 ,
F_85 ( V_166 ) ) ;
F_5 ( V_7 , L_72 ,
F_85 ( V_167 ) ) ;
F_5 ( V_7 , L_73 ,
F_85 ( V_168 ) ) ;
F_5 ( V_7 , L_74 ,
F_85 ( V_169 ) ) ;
F_5 ( V_7 , L_75 ,
F_85 ( V_170 ) ) ;
F_5 ( V_7 , L_76 ,
F_85 ( V_171 ) ) ;
F_5 ( V_7 , L_65 ,
F_85 ( V_163 ) ) ;
F_5 ( V_7 , L_66 ,
F_85 ( V_164 ) ) ;
F_5 ( V_7 , L_67 ,
F_85 ( V_165 ) ) ;
} else if ( F_99 ( V_11 ) ) {
F_5 ( V_7 , L_53 ,
F_85 ( V_153 ) ) ;
F_5 ( V_7 , L_54 ,
F_85 ( V_154 ) ) ;
F_5 ( V_7 , L_55 ,
F_85 ( V_155 ) ) ;
F_5 ( V_7 , L_56 ,
F_85 ( V_156 ) ) ;
F_86 (dev_priv, pipe) {
enum V_157 V_158 ;
V_158 = F_87 ( V_151 ) ;
if ( ! F_88 ( V_11 ,
V_158 ) ) {
F_5 ( V_7 , L_57 ,
F_89 ( V_151 ) ) ;
continue;
}
F_5 ( V_7 , L_58 ,
F_89 ( V_151 ) ,
F_85 ( F_90 ( V_151 ) ) ) ;
F_91 ( V_11 , V_158 ) ;
}
F_5 ( V_7 , L_77 ,
F_85 ( V_172 ) ) ;
F_5 ( V_7 , L_78 ,
F_85 ( V_173 ) ) ;
F_5 ( V_7 , L_79 ,
F_85 ( V_174 ) ) ;
F_5 ( V_7 , L_80 ,
F_85 ( V_175 ) ) ;
F_5 ( V_7 , L_81 ,
F_85 ( V_176 ) ) ;
F_5 ( V_7 , L_82 ,
F_85 ( V_177 ) ) ;
F_5 ( V_7 , L_83 ,
F_85 ( V_178 ) ) ;
F_5 ( V_7 , L_59 ,
F_85 ( V_160 ) ) ;
F_5 ( V_7 , L_60 ,
F_85 ( V_161 ) ) ;
F_5 ( V_7 , L_61 ,
F_85 ( V_162 ) ) ;
} else if ( ! F_100 ( V_11 ) ) {
F_5 ( V_7 , L_84 ,
F_85 ( V_179 ) ) ;
F_5 ( V_7 , L_85 ,
F_85 ( V_180 ) ) ;
F_5 ( V_7 , L_86 ,
F_85 ( V_181 ) ) ;
F_86 (dev_priv, pipe)
F_5 ( V_7 , L_87 ,
F_89 ( V_151 ) ,
F_85 ( F_90 ( V_151 ) ) ) ;
} else {
F_5 ( V_7 , L_88 ,
F_85 ( V_182 ) ) ;
F_5 ( V_7 , L_89 ,
F_85 ( V_183 ) ) ;
F_5 ( V_7 , L_90 ,
F_85 ( V_184 ) ) ;
F_5 ( V_7 , L_91 ,
F_85 ( V_185 ) ) ;
F_5 ( V_7 , L_92 ,
F_85 ( V_186 ) ) ;
F_5 ( V_7 , L_93 ,
F_85 ( V_187 ) ) ;
F_5 ( V_7 , L_94 ,
F_85 ( V_173 ) ) ;
F_5 ( V_7 , L_95 ,
F_85 ( V_174 ) ) ;
F_5 ( V_7 , L_96 ,
F_85 ( V_175 ) ) ;
}
F_53 (engine, dev_priv, id) {
if ( F_10 ( V_11 ) >= 6 ) {
F_5 ( V_7 ,
L_97 ,
V_31 -> V_8 , F_101 ( V_31 ) ) ;
}
F_73 ( V_7 , V_31 ) ;
}
F_102 ( V_11 ) ;
return 0 ;
}
static int F_103 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_150 , V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_5 ( V_7 , L_98 , V_11 -> V_188 ) ;
for ( V_150 = 0 ; V_150 < V_11 -> V_188 ; V_150 ++ ) {
struct V_27 * V_28 = V_11 -> V_189 [ V_150 ] . V_28 ;
F_5 ( V_7 , L_99 ,
V_150 , V_11 -> V_189 [ V_150 ] . V_33 ) ;
if ( ! V_28 )
F_35 ( V_7 , L_100 ) ;
else
F_31 ( V_7 , V_28 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static T_5 F_104 ( struct V_86 * V_86 , char T_6 * V_190 ,
T_7 V_68 , T_8 * V_191 )
{
struct V_192 * error = V_86 -> V_193 ;
struct V_194 V_195 ;
T_5 V_70 ;
T_8 V_196 ;
if ( ! error )
return 0 ;
V_70 = F_105 ( & V_195 , error -> V_197 , V_68 , * V_191 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_106 ( & V_195 , error ) ;
if ( V_70 )
goto V_74;
V_196 = 0 ;
V_70 = F_107 ( V_190 , V_68 , & V_196 , V_195 . V_198 , V_195 . V_199 ) ;
if ( V_70 < 0 )
goto V_74;
* V_191 = V_195 . V_41 + V_70 ;
V_74:
F_108 ( & V_195 ) ;
return V_70 ;
}
static int F_109 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
F_110 ( V_86 -> V_193 ) ;
return 0 ;
}
static int F_111 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
struct V_1 * V_197 = V_200 -> V_201 ;
struct V_192 * V_202 ;
F_83 ( V_197 ) ;
V_202 = F_112 ( V_197 ) ;
F_102 ( V_197 ) ;
if ( ! V_202 )
return - V_73 ;
V_86 -> V_193 = V_202 ;
return 0 ;
}
static T_5
F_113 ( struct V_86 * V_203 ,
const char T_6 * V_190 ,
T_7 V_204 ,
T_8 * V_205 )
{
struct V_192 * error = V_203 -> V_193 ;
if ( ! error )
return 0 ;
F_114 ( L_101 ) ;
F_115 ( error -> V_197 ) ;
return V_204 ;
}
static int F_116 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
V_86 -> V_193 = F_117 ( V_200 -> V_201 ) ;
return 0 ;
}
static int
F_118 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_11 = V_10 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_119 ( V_5 , V_206 ) ;
F_47 ( & V_5 -> V_34 ) ;
return V_70 ;
}
static int F_120 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_70 = 0 ;
F_83 ( V_11 ) ;
if ( F_121 ( V_11 ) ) {
T_9 V_208 = F_122 ( V_209 ) ;
T_9 V_210 = F_122 ( V_211 ) ;
F_5 ( V_7 , L_102 , ( V_208 >> 8 ) & 0xf ) ;
F_5 ( V_7 , L_103 , V_208 & 0x3f ) ;
F_5 ( V_7 , L_104 , ( V_210 & V_212 ) >>
V_213 ) ;
F_5 ( V_7 , L_105 ,
( V_210 & V_214 ) >> V_215 ) ;
} else if ( F_99 ( V_11 ) || F_84 ( V_11 ) ) {
T_4 V_216 ;
F_58 ( & V_11 -> V_217 . V_218 ) ;
V_216 = F_123 ( V_11 , V_219 ) ;
F_5 ( V_7 , L_106 , V_216 ) ;
F_5 ( V_7 , L_107 , V_11 -> V_220 ) ;
F_5 ( V_7 , L_108 ,
F_124 ( V_11 , ( V_216 >> 8 ) & 0xff ) ) ;
F_5 ( V_7 , L_109 ,
F_124 ( V_11 , V_11 -> V_217 . V_221 ) ) ;
F_5 ( V_7 , L_110 ,
F_124 ( V_11 , V_11 -> V_217 . V_222 ) ) ;
F_5 ( V_7 , L_111 ,
F_124 ( V_11 , V_11 -> V_217 . V_223 ) ) ;
F_5 ( V_7 , L_112 ,
F_124 ( V_11 , V_11 -> V_217 . V_224 ) ) ;
F_5 ( V_7 ,
L_113 ,
F_124 ( V_11 , V_11 -> V_217 . V_225 ) ) ;
F_47 ( & V_11 -> V_217 . V_218 ) ;
} else if ( F_10 ( V_11 ) >= 6 ) {
T_4 V_226 ;
T_4 V_227 ;
T_4 V_228 ;
T_4 V_229 , V_230 , V_231 ;
T_4 V_232 , V_233 , V_234 ;
T_4 V_235 , V_236 , V_237 ;
T_4 V_238 , V_239 , V_240 ;
T_4 V_241 , V_242 , V_243 , V_244 , V_245 ;
int V_222 ;
V_226 = F_85 ( V_246 ) ;
if ( F_125 ( V_11 ) ) {
V_228 = F_85 ( V_247 ) ;
V_227 = F_85 ( V_248 ) ;
} else {
V_228 = F_85 ( V_249 ) ;
V_227 = F_85 ( V_250 ) ;
}
F_126 ( V_11 , V_251 ) ;
V_234 = F_85 ( V_252 ) ;
if ( F_10 ( V_11 ) >= 9 )
V_234 >>= 23 ;
else {
V_234 &= ~ V_253 ;
if ( F_127 ( V_11 ) || F_128 ( V_11 ) )
V_234 >>= 24 ;
else
V_234 >>= 25 ;
}
V_234 = F_124 ( V_11 , V_234 ) ;
V_229 = F_85 ( V_254 ) ;
V_230 = F_85 ( V_255 ) ;
V_231 = F_85 ( V_256 ) ;
V_232 = F_85 ( V_257 ) ;
V_235 = F_85 ( V_258 ) & V_259 ;
V_236 = F_85 ( V_260 ) & V_261 ;
V_237 = F_85 ( V_262 ) & V_261 ;
V_238 = F_85 ( V_263 ) & V_264 ;
V_239 = F_85 ( V_265 ) & V_261 ;
V_240 = F_85 ( V_266 ) & V_261 ;
if ( F_10 ( V_11 ) >= 9 )
V_233 = ( V_232 & V_267 ) >> V_268 ;
else if ( F_127 ( V_11 ) || F_128 ( V_11 ) )
V_233 = ( V_232 & V_269 ) >> V_270 ;
else
V_233 = ( V_232 & V_271 ) >> V_272 ;
V_233 = F_124 ( V_11 , V_233 ) ;
F_129 ( V_11 , V_251 ) ;
if ( F_130 ( V_11 ) || F_131 ( V_11 ) ) {
V_241 = F_85 ( V_176 ) ;
V_242 = F_85 ( V_178 ) ;
V_243 = F_85 ( V_273 ) ;
V_244 = F_85 ( V_177 ) ;
V_245 = F_85 ( V_274 ) ;
} else {
V_241 = F_85 ( F_95 ( 2 ) ) ;
V_242 = F_85 ( F_93 ( 2 ) ) ;
V_243 = F_85 ( F_132 ( 2 ) ) ;
V_244 = F_85 ( F_94 ( 2 ) ) ;
V_245 = F_85 ( V_274 ) ;
}
F_5 ( V_7 , L_114 ,
V_241 , V_242 , V_243 , V_244 , V_245 ) ;
F_5 ( V_7 , L_115 ,
V_11 -> V_217 . V_275 ) ;
F_5 ( V_7 , L_116 , V_227 ) ;
F_5 ( V_7 , L_117 ,
( V_227 & ( F_10 ( V_11 ) >= 9 ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_5 ( V_7 , L_118 ,
V_227 & 0xff ) ;
F_5 ( V_7 , L_119 ,
V_226 & 0xff ) ;
F_5 ( V_7 , L_120 , V_232 ) ;
F_5 ( V_7 , L_121 , V_229 ) ;
F_5 ( V_7 , L_122 , V_230 ) ;
F_5 ( V_7 , L_123 , V_231 ) ;
F_5 ( V_7 , L_124 , V_234 ) ;
F_5 ( V_7 , L_125 , V_233 ) ;
F_5 ( V_7 , L_126 ,
V_235 , F_133 ( V_11 , V_235 ) ) ;
F_5 ( V_7 , L_127 ,
V_236 , F_133 ( V_11 , V_236 ) ) ;
F_5 ( V_7 , L_128 ,
V_237 , F_133 ( V_11 , V_237 ) ) ;
F_5 ( V_7 , L_129 ,
V_11 -> V_217 . V_276 ) ;
F_5 ( V_7 , L_130 ,
V_238 , F_133 ( V_11 , V_238 ) ) ;
F_5 ( V_7 , L_131 ,
V_239 , F_133 ( V_11 , V_239 ) ) ;
F_5 ( V_7 , L_132 ,
V_240 , F_133 ( V_11 , V_240 ) ) ;
F_5 ( V_7 , L_133 ,
V_11 -> V_217 . V_277 ) ;
V_222 = ( F_125 ( V_11 ) ? V_228 >> 0 :
V_228 >> 16 ) & 0xff ;
V_222 *= ( F_134 ( V_11 ) ||
F_135 ( V_11 ) ? V_278 : 1 ) ;
F_5 ( V_7 , L_134 ,
F_124 ( V_11 , V_222 ) ) ;
V_222 = ( V_228 & 0xff00 ) >> 8 ;
V_222 *= ( F_134 ( V_11 ) ||
F_135 ( V_11 ) ? V_278 : 1 ) ;
F_5 ( V_7 , L_135 ,
F_124 ( V_11 , V_222 ) ) ;
V_222 = ( F_125 ( V_11 ) ? V_228 >> 16 :
V_228 >> 0 ) & 0xff ;
V_222 *= ( F_134 ( V_11 ) ||
F_135 ( V_11 ) ? V_278 : 1 ) ;
F_5 ( V_7 , L_136 ,
F_124 ( V_11 , V_222 ) ) ;
F_5 ( V_7 , L_137 ,
F_124 ( V_11 , V_11 -> V_217 . V_222 ) ) ;
F_5 ( V_7 , L_138 ,
F_124 ( V_11 , V_11 -> V_217 . V_221 ) ) ;
F_5 ( V_7 , L_139 , V_233 ) ;
F_5 ( V_7 , L_140 ,
F_124 ( V_11 , V_11 -> V_217 . V_224 ) ) ;
F_5 ( V_7 , L_141 ,
F_124 ( V_11 , V_11 -> V_217 . V_223 ) ) ;
F_5 ( V_7 , L_142 ,
F_124 ( V_11 , V_11 -> V_217 . V_279 ) ) ;
F_5 ( V_7 , L_143 ,
F_124 ( V_11 , V_11 -> V_217 . V_222 ) ) ;
F_5 ( V_7 ,
L_113 ,
F_124 ( V_11 , V_11 -> V_217 . V_225 ) ) ;
} else {
F_35 ( V_7 , L_144 ) ;
}
F_5 ( V_7 , L_145 , V_11 -> V_280 . V_281 . V_280 ) ;
F_5 ( V_7 , L_146 , V_11 -> V_282 ) ;
F_5 ( V_7 , L_147 , V_11 -> V_283 ) ;
F_102 ( V_11 ) ;
return V_70 ;
}
static void F_136 ( struct V_1 * V_11 ,
struct V_6 * V_7 ,
struct V_284 * V_285 )
{
int V_286 ;
int V_287 ;
F_5 ( V_7 , L_148 ,
V_285 -> V_285 ) ;
if ( F_10 ( V_11 ) <= 3 )
return;
F_5 ( V_7 , L_149 ,
V_285 -> V_288 ) ;
if ( F_10 ( V_11 ) <= 6 )
return;
F_137 (dev_priv, slice, subslice)
F_5 ( V_7 , L_150 ,
V_286 , V_287 , V_285 -> V_289 [ V_286 ] [ V_287 ] ) ;
F_137 (dev_priv, slice, subslice)
F_5 ( V_7 , L_151 ,
V_286 , V_287 , V_285 -> V_290 [ V_286 ] [ V_287 ] ) ;
}
static int F_138 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
T_3 V_291 [ V_292 ] ;
T_4 V_132 [ V_292 ] ;
struct V_284 V_285 ;
enum V_90 V_55 ;
if ( F_139 ( V_293 , & V_11 -> V_294 . V_295 ) )
F_35 ( V_7 , L_152 ) ;
if ( F_139 ( V_296 , & V_11 -> V_294 . V_295 ) )
F_35 ( V_7 , L_153 ) ;
if ( F_139 ( V_297 , & V_11 -> V_294 . V_295 ) )
F_35 ( V_7 , L_154 ) ;
if ( F_140 ( & V_11 -> V_294 . V_298 ) )
F_35 ( V_7 , L_155 ) ;
if ( F_140 ( & V_11 -> V_294 . V_299 ) )
F_35 ( V_7 , L_156 ) ;
if ( ! V_197 . V_300 ) {
F_35 ( V_7 , L_157 ) ;
return 0 ;
}
F_83 ( V_11 ) ;
F_53 (engine, dev_priv, id) {
V_291 [ V_55 ] = F_141 ( V_31 ) ;
V_132 [ V_55 ] = F_74 ( V_31 ) ;
}
F_142 ( V_11 -> V_31 [ V_301 ] , & V_285 ) ;
F_102 ( V_11 ) ;
if ( F_143 ( & V_11 -> V_294 . V_302 . V_303 ) )
F_5 ( V_7 , L_158 ,
F_71 ( V_11 -> V_294 . V_302 . V_303 . V_304 -
V_135 ) ) ;
else if ( F_144 ( & V_11 -> V_294 . V_302 ) )
F_35 ( V_7 , L_159 ) ;
else
F_35 ( V_7 , L_160 ) ;
F_5 ( V_7 , L_161 , F_6 ( V_11 -> V_305 . V_306 ) ) ;
F_53 (engine, dev_priv, id) {
struct V_141 * V_61 = & V_31 -> V_142 ;
struct V_143 * V_144 ;
F_5 ( V_7 , L_162 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_163 ,
V_31 -> V_307 . V_132 , V_132 [ V_55 ] ,
F_145 ( V_31 ) ,
V_31 -> V_137 -> V_308 ) ;
F_5 ( V_7 , L_164 ,
F_6 ( F_146 ( V_31 ) ) ,
F_6 ( F_139 ( V_31 -> V_55 ,
& V_11 -> V_294 . V_309 ) ) ,
F_6 ( V_31 -> V_307 . V_310 ) ) ;
F_75 ( & V_61 -> V_145 ) ;
for ( V_144 = F_76 ( & V_61 -> V_146 ) ; V_144 ; V_144 = F_77 ( V_144 ) ) {
struct V_147 * V_148 = F_78 ( V_144 , F_79 ( * V_148 ) , V_3 ) ;
F_5 ( V_7 , L_165 ,
V_148 -> V_149 -> V_125 , V_148 -> V_149 -> V_123 , V_148 -> V_132 ) ;
}
F_80 ( & V_61 -> V_145 ) ;
F_5 ( V_7 , L_166 ,
( long long ) V_31 -> V_307 . V_291 ,
( long long ) V_291 [ V_55 ] ) ;
F_5 ( V_7 , L_167 ,
F_147 ( V_31 -> V_307 . V_311 ) ,
V_31 -> V_307 . V_311 ,
F_71 ( V_135 -
V_31 -> V_307 . V_312 ) ) ;
if ( V_31 -> V_55 == V_301 ) {
F_35 ( V_7 , L_168 ) ;
F_136 ( V_11 , V_7 , & V_285 ) ;
F_35 ( V_7 , L_169 ) ;
F_136 ( V_11 , V_7 ,
& V_31 -> V_307 . V_285 ) ;
}
}
return 0 ;
}
static int F_148 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_313 * error = & V_11 -> V_294 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
F_5 ( V_7 , L_170 , F_149 ( error ) ) ;
F_53 (engine, dev_priv, id) {
F_5 ( V_7 , L_171 , V_31 -> V_8 ,
F_150 ( error , V_31 ) ) ;
}
return 0 ;
}
static int F_151 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_314 , V_315 ;
T_9 V_316 ;
V_314 = F_85 ( V_317 ) ;
V_315 = F_85 ( V_318 ) ;
V_316 = F_122 ( V_319 ) ;
F_5 ( V_7 , L_172 , F_6 ( V_314 & V_320 ) ) ;
F_5 ( V_7 , L_173 ,
( V_314 & V_321 ) >>
V_322 ) ;
F_5 ( V_7 , L_174 ,
F_6 ( V_314 & V_323 ) ) ;
F_5 ( V_7 , L_175 ,
F_6 ( V_314 & V_324 ) ) ;
F_5 ( V_7 , L_176 ,
F_6 ( V_314 & V_325 ) ) ;
F_5 ( V_7 , L_177 ,
( V_314 & V_326 ) >> V_327 ) ;
F_5 ( V_7 , L_178 ,
( V_314 & V_328 ) >> V_329 ) ;
F_5 ( V_7 , L_179 , ( V_314 & V_330 ) ) ;
F_5 ( V_7 , L_180 , ( V_316 & 0x3f ) ) ;
F_5 ( V_7 , L_181 , ( ( V_316 >> 8 ) & 0x3f ) ) ;
F_5 ( V_7 , L_182 ,
F_6 ( ! ( V_315 & V_331 ) ) ) ;
F_35 ( V_7 , L_183 ) ;
switch ( V_315 & V_332 ) {
case V_333 :
F_35 ( V_7 , L_184 ) ;
break;
case V_334 :
F_35 ( V_7 , L_185 ) ;
break;
case V_335 :
F_35 ( V_7 , L_186 ) ;
break;
case V_336 :
F_35 ( V_7 , L_187 ) ;
break;
case V_337 :
F_35 ( V_7 , L_188 ) ;
break;
case V_338 :
F_35 ( V_7 , L_189 ) ;
break;
default:
F_35 ( V_7 , L_190 ) ;
break;
}
return 0 ;
}
static int F_152 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_197 = F_1 ( V_7 -> V_12 ) ;
struct V_339 * V_340 ;
unsigned int V_196 ;
F_153 (fw_domain, i915, tmp)
F_5 ( V_7 , L_191 ,
F_154 ( V_340 -> V_55 ) ,
F_42 ( V_340 -> V_341 ) ) ;
return 0 ;
}
static void F_155 ( struct V_6 * V_7 ,
const char * V_342 ,
const T_10 V_343 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_5 ( V_7 , L_192 ,
V_342 , F_85 ( V_343 ) ,
F_156 ( V_11 , V_343 ) ) ;
}
static int F_157 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_344 , V_345 , V_346 ;
V_346 = F_85 ( V_347 ) ;
V_344 = F_85 ( V_254 ) ;
V_345 = F_85 ( V_348 ) ;
F_5 ( V_7 , L_193 ,
F_6 ( V_344 & V_349 ) ) ;
F_5 ( V_7 , L_194 ,
F_6 ( V_344 & V_350 ) ) ;
F_5 ( V_7 , L_174 ,
F_6 ( V_344 & V_350 ) ) ;
F_5 ( V_7 , L_175 ,
F_6 ( ( V_344 & V_351 ) ==
V_352 ) ) ;
F_5 ( V_7 , L_195 ,
F_6 ( V_345 & ( V_353 |
F_158 ( 1 ) ) ) ) ;
F_5 ( V_7 , L_196 ,
( V_346 & V_354 ) ? L_197 : L_198 ) ;
F_5 ( V_7 , L_199 ,
( V_346 & V_355 ) ? L_197 : L_198 ) ;
F_155 ( V_7 , L_200 , V_356 ) ;
F_155 ( V_7 , L_201 , V_357 ) ;
return F_152 ( V_7 , NULL ) ;
}
static int F_159 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_344 , V_358 , V_345 , V_359 = 0 ;
T_4 V_360 = 0 , V_361 = 0 ;
unsigned V_362 ;
int V_68 = 0 ;
V_362 = F_42 ( V_11 -> V_363 . V_340 [ V_364 ] . V_341 ) ;
if ( V_362 ) {
F_35 ( V_7 , L_202
L_203 ) ;
} else {
while ( V_68 ++ < 50 && ( F_160 ( V_365 ) & 1 ) )
F_161 ( 10 ) ;
F_5 ( V_7 , L_204 , F_6 ( V_68 < 51 ) ) ;
}
V_358 = F_162 ( V_366 ) ;
F_163 ( false , V_366 , V_358 , 4 , true ) ;
V_344 = F_85 ( V_254 ) ;
V_345 = F_85 ( V_348 ) ;
if ( F_10 ( V_11 ) >= 9 ) {
V_360 = F_85 ( V_367 ) ;
V_361 = F_85 ( V_368 ) ;
}
F_58 ( & V_11 -> V_217 . V_218 ) ;
F_164 ( V_11 , V_369 , & V_359 ) ;
F_47 ( & V_11 -> V_217 . V_218 ) ;
F_5 ( V_7 , L_193 ,
F_6 ( V_344 & V_349 ) ) ;
F_5 ( V_7 , L_174 ,
F_6 ( V_344 & V_350 ) ) ;
F_5 ( V_7 , L_175 ,
F_6 ( ( V_344 & V_351 ) ==
V_352 ) ) ;
F_5 ( V_7 , L_205 ,
F_6 ( V_345 & V_370 ) ) ;
F_5 ( V_7 , L_195 ,
F_6 ( V_345 & V_371 ) ) ;
if ( F_10 ( V_11 ) >= 9 ) {
F_5 ( V_7 , L_206 ,
F_6 ( V_360 & V_372 ) ) ;
F_5 ( V_7 , L_207 ,
F_6 ( V_360 & V_373 ) ) ;
}
F_5 ( V_7 , L_208 ,
F_6 ( V_345 & V_374 ) ) ;
F_5 ( V_7 , L_209 ,
F_6 ( V_345 & V_375 ) ) ;
F_35 ( V_7 , L_210 ) ;
switch ( V_358 & V_376 ) {
case V_377 :
if ( V_358 & V_378 )
F_35 ( V_7 , L_211 ) ;
else
F_35 ( V_7 , L_184 ) ;
break;
case V_379 :
F_35 ( V_7 , L_212 ) ;
break;
case V_380 :
F_35 ( V_7 , L_213 ) ;
break;
case V_381 :
F_35 ( V_7 , L_214 ) ;
break;
default:
F_35 ( V_7 , L_215 ) ;
break;
}
F_5 ( V_7 , L_216 ,
F_6 ( V_358 & V_378 ) ) ;
if ( F_10 ( V_11 ) >= 9 ) {
F_5 ( V_7 , L_196 ,
( V_361 &
V_382 ) ? L_197 : L_198 ) ;
F_5 ( V_7 , L_199 ,
( V_361 &
V_383 ) ? L_197 : L_198 ) ;
}
F_155 ( V_7 , L_217 ,
V_384 ) ;
F_155 ( V_7 , L_218 , V_385 ) ;
F_155 ( V_7 , L_219 , V_386 ) ;
F_155 ( V_7 , L_220 , V_387 ) ;
F_5 ( V_7 , L_221 ,
F_165 ( ( ( V_359 >> 0 ) & 0xff ) ) ) ;
F_5 ( V_7 , L_222 ,
F_165 ( ( ( V_359 >> 8 ) & 0xff ) ) ) ;
F_5 ( V_7 , L_223 ,
F_165 ( ( ( V_359 >> 16 ) & 0xff ) ) ) ;
return F_152 ( V_7 , NULL ) ;
}
static int F_166 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_388 ;
F_83 ( V_11 ) ;
if ( F_99 ( V_11 ) || F_84 ( V_11 ) )
V_388 = F_157 ( V_7 ) ;
else if ( F_10 ( V_11 ) >= 6 )
V_388 = F_159 ( V_7 ) ;
else
V_388 = F_151 ( V_7 ) ;
F_102 ( V_11 ) ;
return V_388 ;
}
static int F_167 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_5 ( V_7 , L_224 ,
V_11 -> V_389 . V_390 ) ;
F_5 ( V_7 , L_225 ,
V_11 -> V_389 . V_391 ) ;
return 0 ;
}
static int F_168 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
if ( ! F_169 ( V_11 ) ) {
F_35 ( V_7 , L_226 ) ;
return 0 ;
}
F_83 ( V_11 ) ;
F_58 ( & V_11 -> V_392 . V_393 ) ;
if ( F_170 ( V_11 ) )
F_35 ( V_7 , L_227 ) ;
else
F_5 ( V_7 , L_228 ,
V_11 -> V_392 . V_394 ) ;
if ( F_170 ( V_11 ) ) {
T_4 V_395 ;
if ( F_10 ( V_11 ) >= 8 )
V_395 = F_85 ( V_396 ) & V_397 ;
else if ( F_10 ( V_11 ) >= 7 )
V_395 = F_85 ( V_396 ) & V_398 ;
else if ( F_10 ( V_11 ) >= 5 )
V_395 = F_85 ( V_399 ) & V_400 ;
else if ( F_171 ( V_11 ) )
V_395 = F_85 ( V_401 ) & V_402 ;
else
V_395 = F_85 ( V_403 ) & ( V_404 |
V_405 ) ;
F_5 ( V_7 , L_229 , F_6 ( V_395 ) ) ;
}
F_47 ( & V_11 -> V_392 . V_393 ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static int F_172 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 7 || ! F_169 ( V_11 ) )
return - V_406 ;
* V_206 = V_11 -> V_392 . V_407 ;
return 0 ;
}
static int F_173 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_343 ;
if ( F_10 ( V_11 ) < 7 || ! F_169 ( V_11 ) )
return - V_406 ;
F_58 ( & V_11 -> V_392 . V_393 ) ;
V_343 = F_85 ( V_408 ) ;
V_11 -> V_392 . V_407 = V_206 ;
F_174 ( V_408 , V_206 ?
( V_343 | V_409 ) :
( V_343 & ~ V_409 ) ) ;
F_47 ( & V_11 -> V_392 . V_393 ) ;
return 0 ;
}
static int F_175 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
if ( ! F_176 ( V_11 ) ) {
F_35 ( V_7 , L_230 ) ;
return 0 ;
}
F_83 ( V_11 ) ;
F_5 ( V_7 , L_231 ,
F_6 ( V_197 . V_410 ) ) ;
if ( F_10 ( V_11 ) >= 8 ) {
F_35 ( V_7 , L_232 ) ;
} else {
if ( F_85 ( V_411 ) & V_412 )
F_35 ( V_7 , L_233 ) ;
else
F_35 ( V_7 , L_234 ) ;
}
F_102 ( V_11 ) ;
return 0 ;
}
static int F_177 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
bool V_413 = false ;
F_83 ( V_11 ) ;
F_92 ( V_11 , V_159 ) ;
if ( F_10 ( V_11 ) >= 9 )
;
else if ( F_100 ( V_11 ) )
V_413 = F_85 ( V_414 ) & V_415 ;
else if ( F_178 ( V_11 ) || F_171 ( V_11 ) ||
F_179 ( V_11 ) || F_180 ( V_11 ) )
V_413 = F_85 ( V_416 ) & V_417 ;
else if ( F_181 ( V_11 ) )
V_413 = F_85 ( V_418 ) & V_419 ;
else if ( F_182 ( V_11 ) )
V_413 = F_85 ( V_420 ) & V_421 ;
else if ( F_99 ( V_11 ) || F_84 ( V_11 ) )
V_413 = F_85 ( V_422 ) & V_423 ;
F_91 ( V_11 , V_159 ) ;
F_102 ( V_11 ) ;
F_5 ( V_7 , L_235 , F_183 ( V_413 ) ) ;
return 0 ;
}
static int F_184 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
unsigned long V_424 , V_425 , V_426 ;
int V_70 ;
if ( ! F_121 ( V_11 ) )
return - V_406 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_424 = F_185 ( V_11 ) ;
V_425 = F_186 ( V_11 ) ;
V_426 = F_187 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
F_5 ( V_7 , L_236 , V_424 ) ;
F_5 ( V_7 , L_237 , V_425 ) ;
F_5 ( V_7 , L_238 , V_426 ) ;
F_5 ( V_7 , L_239 , V_425 + V_426 ) ;
return 0 ;
}
static int F_188 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_70 = 0 ;
int V_427 , V_428 ;
unsigned int V_429 , V_430 ;
if ( ! F_189 ( V_11 ) ) {
F_35 ( V_7 , L_240 ) ;
return 0 ;
}
F_83 ( V_11 ) ;
V_70 = F_44 ( & V_11 -> V_217 . V_218 ) ;
if ( V_70 )
goto V_74;
if ( F_134 ( V_11 ) || F_135 ( V_11 ) ) {
V_430 =
V_11 -> V_217 . V_431 / V_278 ;
V_429 =
V_11 -> V_217 . V_432 / V_278 ;
} else {
V_430 = V_11 -> V_217 . V_431 ;
V_429 = V_11 -> V_217 . V_432 ;
}
F_35 ( V_7 , L_241 ) ;
for ( V_427 = V_430 ; V_427 <= V_429 ; V_427 ++ ) {
V_428 = V_427 ;
F_164 ( V_11 ,
V_433 ,
& V_428 ) ;
F_5 ( V_7 , L_242 ,
F_124 ( V_11 , ( V_427 *
( F_134 ( V_11 ) ||
F_135 ( V_11 ) ?
V_278 : 1 ) ) ) ,
( ( V_428 >> 0 ) & 0xff ) * 100 ,
( ( V_428 >> 8 ) & 0xff ) * 100 ) ;
}
F_47 ( & V_11 -> V_217 . V_218 ) ;
V_74:
F_102 ( V_11 ) ;
return V_70 ;
}
static int F_190 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_434 * V_435 = & V_11 -> V_435 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_74;
if ( V_435 -> V_436 )
F_191 ( V_7 , V_435 -> V_436 , V_437 ) ;
F_47 ( & V_5 -> V_34 ) ;
V_74:
return 0 ;
}
static int F_192 ( struct V_6 * V_7 , void * V_207 )
{
struct V_434 * V_435 = & F_1 ( V_7 -> V_12 ) -> V_435 ;
if ( V_435 -> V_438 )
F_191 ( V_7 , V_435 -> V_438 , V_435 -> V_439 ) ;
return 0 ;
}
static int F_193 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_440 * V_441 = NULL ;
struct V_442 * V_443 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
#ifdef F_194
if ( V_11 -> V_444 && V_11 -> V_444 -> V_445 . V_446 ) {
V_441 = F_195 ( V_11 -> V_444 -> V_445 . V_446 ) ;
F_5 ( V_7 , L_243 ,
V_441 -> V_29 . V_51 ,
V_441 -> V_29 . V_52 ,
V_441 -> V_29 . V_447 -> V_448 ,
V_441 -> V_29 . V_447 -> V_449 [ 0 ] * 8 ,
V_441 -> V_29 . V_450 ,
F_196 ( & V_441 -> V_29 ) ) ;
F_31 ( V_7 , V_441 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
#endif
F_58 ( & V_5 -> V_451 . V_452 ) ;
F_197 (drm_fb, dev) {
struct V_440 * V_446 = F_195 ( V_443 ) ;
if ( V_446 == V_441 )
continue;
F_5 ( V_7 , L_244 ,
V_446 -> V_29 . V_51 ,
V_446 -> V_29 . V_52 ,
V_446 -> V_29 . V_447 -> V_448 ,
V_446 -> V_29 . V_447 -> V_449 [ 0 ] * 8 ,
V_446 -> V_29 . V_450 ,
F_196 ( & V_446 -> V_29 ) ) ;
F_31 ( V_7 , V_446 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_451 . V_452 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_198 ( struct V_6 * V_7 , struct V_453 * V_97 )
{
F_5 ( V_7 , L_245 ,
V_97 -> V_454 , V_97 -> V_455 , V_97 -> V_456 ) ;
}
static int F_199 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
struct V_94 * V_95 ;
enum V_90 V_55 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_28 (ctx, &dev_priv->contexts.list, link) {
F_5 ( V_7 , L_246 , V_95 -> V_131 ) ;
if ( V_95 -> V_123 ) {
struct V_117 * V_118 ;
V_118 = F_200 ( V_95 -> V_123 , V_124 ) ;
if ( V_118 ) {
F_5 ( V_7 , L_247 ,
V_118 -> V_125 , V_118 -> V_123 ) ;
F_201 ( V_118 ) ;
}
} else if ( F_202 ( V_95 -> V_87 ) ) {
F_35 ( V_7 , L_248 ) ;
} else {
F_35 ( V_7 , L_249 ) ;
}
F_46 ( V_7 , V_95 -> V_457 ? 'R' : 'r' ) ;
F_46 ( V_7 , '\n' ) ;
F_53 (engine, dev_priv, id) {
struct V_458 * V_459 = & V_95 -> V_31 [ V_31 -> V_55 ] ;
F_5 ( V_7 , L_250 , V_31 -> V_8 ) ;
F_46 ( V_7 , V_459 -> V_460 ? 'I' : 'i' ) ;
if ( V_459 -> V_96 )
F_31 ( V_7 , V_459 -> V_96 -> V_18 ) ;
if ( V_459 -> V_97 )
F_198 ( V_7 , V_459 -> V_97 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_203 ( struct V_6 * V_7 ,
struct V_94 * V_95 ,
struct V_30 * V_31 )
{
struct V_27 * V_28 = V_95 -> V_31 [ V_31 -> V_55 ] . V_96 ;
struct V_461 * V_461 ;
int V_91 ;
F_5 ( V_7 , L_251 , V_31 -> V_8 , V_95 -> V_131 ) ;
if ( ! V_28 ) {
F_35 ( V_7 , L_252 ) ;
return;
}
if ( V_28 -> V_295 & V_462 )
F_5 ( V_7 , L_253 ,
F_204 ( V_28 ) ) ;
if ( F_205 ( V_28 -> V_18 ) ) {
F_35 ( V_7 , L_254 ) ;
return;
}
V_461 = F_206 ( V_28 -> V_18 , V_463 ) ;
if ( V_461 ) {
T_4 * V_464 = F_207 ( V_461 ) ;
for ( V_91 = 0 ; V_91 < 0x600 / sizeof( T_4 ) / 4 ; V_91 += 4 ) {
F_5 ( V_7 ,
L_255 ,
V_91 * 4 ,
V_464 [ V_91 ] , V_464 [ V_91 + 1 ] ,
V_464 [ V_91 + 2 ] , V_464 [ V_91 + 3 ] ) ;
}
F_208 ( V_464 ) ;
}
F_209 ( V_28 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
static int F_210 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
struct V_94 * V_95 ;
enum V_90 V_55 ;
int V_70 ;
if ( ! V_197 . V_465 ) {
F_5 ( V_7 , L_256 ) ;
return 0 ;
}
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_28 (ctx, &dev_priv->contexts.list, link)
F_53 (engine, dev_priv, id)
F_203 ( V_7 , V_95 , V_31 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static const char * F_211 ( unsigned V_466 )
{
switch ( V_466 ) {
case V_467 :
return L_257 ;
case V_468 :
return L_258 ;
case V_469 :
return L_259 ;
case V_470 :
return L_260 ;
case V_471 :
return L_261 ;
case V_472 :
return L_262 ;
case V_473 :
return L_263 ;
case V_474 :
return L_264 ;
}
return L_265 ;
}
static int F_212 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_83 ( V_11 ) ;
F_5 ( V_7 , L_266 ,
F_211 ( V_11 -> V_24 . V_475 ) ) ;
F_5 ( V_7 , L_267 ,
F_211 ( V_11 -> V_24 . V_476 ) ) ;
if ( F_213 ( V_11 ) || F_214 ( V_11 ) ) {
F_5 ( V_7 , L_268 ,
F_85 ( V_477 ) ) ;
F_5 ( V_7 , L_269 ,
F_85 ( V_478 ) ) ;
F_5 ( V_7 , L_270 ,
F_122 ( V_479 ) ) ;
F_5 ( V_7 , L_271 ,
F_122 ( V_480 ) ) ;
} else if ( F_10 ( V_11 ) >= 6 ) {
F_5 ( V_7 , L_272 ,
F_85 ( V_481 ) ) ;
F_5 ( V_7 , L_273 ,
F_85 ( V_482 ) ) ;
F_5 ( V_7 , L_274 ,
F_85 ( V_483 ) ) ;
F_5 ( V_7 , L_275 ,
F_85 ( V_484 ) ) ;
if ( F_10 ( V_11 ) >= 8 )
F_5 ( V_7 , L_276 ,
F_85 ( V_485 ) ) ;
else
F_5 ( V_7 , L_277 ,
F_85 ( V_486 ) ) ;
F_5 ( V_7 , L_278 ,
F_85 ( V_487 ) ) ;
}
if ( V_11 -> V_488 & V_489 )
F_35 ( V_7 , L_279 ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static int F_215 ( int V_55 , void * V_75 , void * V_10 )
{
struct V_94 * V_95 = V_75 ;
struct V_6 * V_7 = V_10 ;
struct V_83 * V_84 = V_95 -> V_84 ;
if ( ! V_84 ) {
F_5 ( V_7 , L_280 ,
V_95 -> V_490 ) ;
return 0 ;
}
if ( F_216 ( V_95 ) )
F_35 ( V_7 , L_281 ) ;
else
F_5 ( V_7 , L_282 , V_95 -> V_490 ) ;
V_84 -> V_491 ( V_84 , V_7 ) ;
return 0 ;
}
static void F_217 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_83 * V_84 = V_11 -> V_24 . V_492 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_150 ;
if ( ! V_84 )
return;
F_53 (engine, dev_priv, id) {
F_5 ( V_7 , L_283 , V_31 -> V_8 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
T_3 V_493 = F_85 ( F_218 ( V_31 , V_150 ) ) ;
V_493 <<= 32 ;
V_493 |= F_85 ( F_219 ( V_31 , V_150 ) ) ;
F_5 ( V_7 , L_284 , V_150 , V_493 ) ;
}
}
}
static void F_220 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_30 * V_31 ;
enum V_90 V_55 ;
if ( F_130 ( V_11 ) )
F_5 ( V_7 , L_285 , F_85 ( V_494 ) ) ;
F_53 (engine, dev_priv, id) {
F_5 ( V_7 , L_283 , V_31 -> V_8 ) ;
if ( F_131 ( V_11 ) )
F_5 ( V_7 , L_285 ,
F_85 ( F_221 ( V_31 ) ) ) ;
F_5 ( V_7 , L_286 ,
F_85 ( F_222 ( V_31 ) ) ) ;
F_5 ( V_7 , L_287 ,
F_85 ( F_223 ( V_31 ) ) ) ;
F_5 ( V_7 , L_288 ,
F_85 ( F_224 ( V_31 ) ) ) ;
}
if ( V_11 -> V_24 . V_492 ) {
struct V_83 * V_84 = V_11 -> V_24 . V_492 ;
F_35 ( V_7 , L_289 ) ;
F_5 ( V_7 , L_290 , V_84 -> V_495 . V_29 . V_496 ) ;
V_84 -> V_491 ( V_84 , V_7 ) ;
}
F_5 ( V_7 , L_291 , F_85 ( V_497 ) ) ;
}
static int F_225 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_98 * V_86 ;
int V_70 ;
F_58 ( & V_5 -> V_114 ) ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_498;
F_83 ( V_11 ) ;
if ( F_10 ( V_11 ) >= 8 )
F_217 ( V_7 , V_11 ) ;
else if ( F_10 ( V_11 ) >= 6 )
F_220 ( V_7 , V_11 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_100 * V_87 = V_86 -> V_102 ;
struct V_117 * V_118 ;
V_118 = F_200 ( V_86 -> V_123 , V_124 ) ;
if ( ! V_118 ) {
V_70 = - V_499 ;
goto V_500;
}
F_5 ( V_7 , L_292 , V_118 -> V_125 ) ;
F_201 ( V_118 ) ;
F_59 ( & V_87 -> V_103 , F_215 ,
( void * ) ( unsigned long ) V_7 ) ;
}
V_500:
F_102 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
V_498:
F_47 ( & V_5 -> V_114 ) ;
return V_70 ;
}
static int F_226 ( struct V_1 * V_197 )
{
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_68 = 0 ;
F_53 (engine, i915, id)
V_68 += F_146 ( V_31 ) ;
return V_68 ;
}
static const char * F_227 ( unsigned int V_501 )
{
static const char * const V_502 [] = {
[ V_503 ] = L_293 ,
[ V_504 ] = L_294 ,
[ V_505 ] = L_295 ,
} ;
if ( V_501 >= F_54 ( V_502 ) || ! V_502 [ V_501 ] )
return L_264 ;
return V_502 [ V_501 ] ;
}
static int F_228 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_98 * V_86 ;
F_5 ( V_7 , L_296 , V_11 -> V_217 . V_506 ) ;
F_5 ( V_7 , L_297 ,
F_6 ( V_11 -> V_305 . V_306 ) , V_11 -> V_305 . V_507 ) ;
F_5 ( V_7 , L_298 , F_226 ( V_11 ) ) ;
F_5 ( V_7 , L_299 ,
F_39 ( & V_11 -> V_217 . V_508 ) ) ;
F_5 ( V_7 , L_300 ,
F_124 ( V_11 , V_11 -> V_217 . V_221 ) ) ;
F_5 ( V_7 , L_301 ,
F_124 ( V_11 , V_11 -> V_217 . V_223 ) ,
F_124 ( V_11 , V_11 -> V_217 . V_431 ) ,
F_124 ( V_11 , V_11 -> V_217 . V_432 ) ,
F_124 ( V_11 , V_11 -> V_217 . V_222 ) ) ;
F_5 ( V_7 , L_302 ,
F_124 ( V_11 , V_11 -> V_217 . V_224 ) ,
F_124 ( V_11 , V_11 -> V_217 . V_225 ) ,
F_124 ( V_11 , V_11 -> V_217 . V_279 ) ) ;
F_58 ( & V_5 -> V_114 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_100 * V_87 = V_86 -> V_102 ;
struct V_117 * V_118 ;
F_65 () ;
V_118 = F_66 ( V_86 -> V_123 , V_124 ) ;
F_5 ( V_7 , L_303 ,
V_118 ? V_118 -> V_125 : L_42 ,
V_118 ? V_118 -> V_123 : - 1 ,
F_39 ( & V_87 -> V_217 . V_509 ) ) ;
F_67 () ;
}
F_5 ( V_7 , L_304 ,
F_39 ( & V_11 -> V_217 . V_509 ) ) ;
F_47 ( & V_5 -> V_114 ) ;
if ( F_10 ( V_11 ) >= 6 &&
V_11 -> V_217 . V_506 &&
V_11 -> V_305 . V_507 ) {
T_4 V_510 , V_235 ;
T_4 V_511 , V_238 ;
F_126 ( V_11 , V_251 ) ;
V_510 = F_162 ( V_260 ) & V_512 ;
V_235 = F_162 ( V_258 ) & V_512 ;
V_511 = F_162 ( V_265 ) & V_512 ;
V_238 = F_162 ( V_263 ) & V_512 ;
F_129 ( V_11 , V_251 ) ;
F_5 ( V_7 , L_305 ,
F_227 ( V_11 -> V_217 . V_501 ) ) ;
F_5 ( V_7 , L_306 ,
V_510 && V_235 ? 100 * V_510 / V_235 : 0 ,
V_11 -> V_217 . V_276 ) ;
F_5 ( V_7 , L_307 ,
V_511 && V_238 ? 100 * V_511 / V_238 : 0 ,
V_11 -> V_217 . V_277 ) ;
} else {
F_35 ( V_7 , L_308 ) ;
}
return 0 ;
}
static int F_229 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const bool V_513 = F_10 ( V_11 ) > 8 ;
F_5 ( V_7 , L_309 , F_6 ( F_189 ( V_11 ) ) ) ;
F_5 ( V_7 , L_310 , V_513 ? L_311 : L_312 ,
F_230 ( V_11 ) / 1024 / 1024 ) ;
return 0 ;
}
static int F_231 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_514 * V_515 = & V_11 -> V_516 . V_517 ;
if ( ! F_232 ( V_11 ) )
return 0 ;
F_35 ( V_7 , L_313 ) ;
F_5 ( V_7 , L_314 , V_515 -> V_518 ) ;
F_5 ( V_7 , L_315 ,
F_233 ( V_515 -> V_519 ) ) ;
F_5 ( V_7 , L_316 ,
F_233 ( V_515 -> V_520 ) ) ;
F_5 ( V_7 , L_317 ,
V_515 -> V_521 , V_515 -> V_522 ) ;
F_5 ( V_7 , L_318 ,
V_515 -> V_523 , V_515 -> V_524 ) ;
F_5 ( V_7 , L_319 ,
V_515 -> V_525 , V_515 -> V_526 ) ;
F_5 ( V_7 , L_320 ,
V_515 -> V_527 , V_515 -> V_528 ) ;
F_5 ( V_7 , L_321 ,
V_515 -> V_529 , V_515 -> V_530 ) ;
F_83 ( V_11 ) ;
F_5 ( V_7 , L_322 , F_85 ( V_531 ) ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static int F_234 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_514 * V_532 = & V_11 -> V_533 . V_517 ;
T_4 V_196 , V_150 ;
if ( ! F_235 ( V_11 ) )
return 0 ;
F_5 ( V_7 , L_323 ) ;
F_5 ( V_7 , L_314 ,
V_532 -> V_518 ) ;
F_5 ( V_7 , L_315 ,
F_233 ( V_532 -> V_519 ) ) ;
F_5 ( V_7 , L_316 ,
F_233 ( V_532 -> V_520 ) ) ;
F_5 ( V_7 , L_317 ,
V_532 -> V_521 , V_532 -> V_522 ) ;
F_5 ( V_7 , L_318 ,
V_532 -> V_523 , V_532 -> V_524 ) ;
F_5 ( V_7 , L_319 ,
V_532 -> V_525 , V_532 -> V_526 ) ;
F_5 ( V_7 , L_320 ,
V_532 -> V_527 , V_532 -> V_528 ) ;
F_5 ( V_7 , L_321 ,
V_532 -> V_529 , V_532 -> V_530 ) ;
F_83 ( V_11 ) ;
V_196 = F_85 ( V_534 ) ;
F_5 ( V_7 , L_324 , V_196 ) ;
F_5 ( V_7 , L_325 ,
( V_196 & V_535 ) >> V_536 ) ;
F_5 ( V_7 , L_326 ,
( V_196 & V_537 ) >> V_538 ) ;
F_5 ( V_7 , L_327 ,
( V_196 & V_539 ) >> V_540 ) ;
F_35 ( V_7 , L_328 ) ;
for ( V_150 = 0 ; V_150 < 16 ; V_150 ++ )
F_5 ( V_7 , L_329 , V_150 , F_85 ( F_236 ( V_150 ) ) ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static void F_237 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_541 * V_533 = & V_11 -> V_533 ;
F_35 ( V_7 , L_330 ) ;
F_5 ( V_7 , L_331 ,
V_533 -> log . V_542 [ V_543 ] ,
V_533 -> log . V_544 [ V_543 ] ) ;
F_5 ( V_7 , L_332 ,
V_533 -> log . V_542 [ V_545 ] ,
V_533 -> log . V_544 [ V_545 ] ) ;
F_5 ( V_7 , L_333 ,
V_533 -> log . V_542 [ V_546 ] ,
V_533 -> log . V_544 [ V_546 ] ) ;
F_5 ( V_7 , L_334 ,
V_533 -> log . V_547 ) ;
F_5 ( V_7 , L_335 ,
V_533 -> log . V_548 ) ;
}
static void F_238 ( struct V_6 * V_7 ,
struct V_1 * V_11 ,
struct V_549 * V_550 )
{
struct V_30 * V_31 ;
enum V_90 V_55 ;
T_11 V_551 = 0 ;
F_5 ( V_7 , L_336 ,
V_550 -> V_134 , V_550 -> V_552 , V_550 -> V_553 ) ;
F_5 ( V_7 , L_337 ,
V_550 -> V_554 , V_550 -> V_555 , V_550 -> V_556 ) ;
F_5 ( V_7 , L_338 ,
V_550 -> V_557 , V_550 -> V_558 , V_550 -> V_559 ) ;
F_5 ( V_7 , L_339 , V_550 -> V_560 ) ;
F_53 (engine, dev_priv, id) {
T_3 V_561 = V_550 -> V_561 [ V_55 ] ;
V_551 += V_561 ;
F_5 ( V_7 , L_340 ,
V_561 , V_31 -> V_8 ) ;
}
F_5 ( V_7 , L_341 , V_551 ) ;
}
static bool F_239 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_541 * V_533 = & V_11 -> V_533 ;
if ( ! V_533 -> V_562 ) {
F_5 ( V_7 , L_342 ,
F_240 ( V_11 ) ?
L_343 :
L_344 ) ;
return false ;
}
return true ;
}
static int F_241 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_541 * V_533 = & V_11 -> V_533 ;
if ( ! F_239 ( V_7 ) )
return 0 ;
F_5 ( V_7 , L_345 ) ;
F_5 ( V_7 , L_346 , V_563 , V_533 -> V_564 ) ;
F_5 ( V_7 , L_347 , V_533 -> V_565 ) ;
F_5 ( V_7 , L_348 , V_533 -> V_562 ) ;
F_238 ( V_7 , V_11 , V_533 -> V_562 ) ;
F_237 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_242 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_541 * V_533 = & V_11 -> V_533 ;
struct V_566 * V_567 = V_533 -> V_568 ;
struct V_549 * V_550 = V_533 -> V_562 ;
unsigned int V_196 ;
int V_569 ;
if ( ! F_239 ( V_7 ) )
return 0 ;
for ( V_569 = 0 ; V_569 < V_570 ; V_569 ++ , V_567 ++ ) {
struct V_30 * V_31 ;
if ( ! ( V_567 -> V_571 & V_572 ) )
continue;
F_5 ( V_7 , L_349 , V_569 ) ;
F_5 ( V_7 , L_350 , V_567 -> V_552 ) ;
F_5 ( V_7 , L_351 , V_567 -> V_571 ) ;
F_5 ( V_7 , L_352 , V_567 -> V_134 ) ;
F_5 ( V_7 , L_353 , V_567 -> V_573 ) ;
F_5 ( V_7 , L_354 ,
V_567 -> V_574 ) ;
F_5 ( V_7 , L_355 ,
V_567 -> V_575 ,
V_567 -> V_576 ,
V_567 -> V_577 ) ;
F_5 ( V_7 , L_356 ,
V_567 -> V_578 ) ;
F_5 ( V_7 , L_357 ,
V_567 -> V_579 , V_567 -> V_557 ) ;
F_46 ( V_7 , '\n' ) ;
F_243 (engine, dev_priv, client->engines, tmp) {
T_4 V_580 = V_31 -> V_581 ;
struct V_582 * V_583 =
& V_567 -> V_583 [ V_580 ] ;
F_5 ( V_7 , L_358 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_359 ,
V_583 -> V_584 ) ;
F_5 ( V_7 , L_360 , V_583 -> V_585 ) ;
F_5 ( V_7 , L_361 , V_583 -> V_586 ) ;
F_5 ( V_7 , L_362 , V_583 -> V_587 ) ;
F_5 ( V_7 , L_363 , V_583 -> V_588 ) ;
F_46 ( V_7 , '\n' ) ;
}
}
return 0 ;
}
static int F_244 ( struct V_6 * V_7 , void * V_10 )
{
struct V_2 * V_3 = V_7 -> V_12 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
bool V_589 = ! ! V_3 -> V_127 -> V_10 ;
struct V_17 * V_18 = NULL ;
T_4 * log ;
int V_150 = 0 ;
if ( V_589 )
V_18 = V_11 -> V_533 . V_590 ;
else if ( V_11 -> V_533 . log . V_28 )
V_18 = V_11 -> V_533 . log . V_28 -> V_18 ;
if ( ! V_18 )
return 0 ;
log = F_245 ( V_18 , V_591 ) ;
if ( F_202 ( log ) ) {
F_246 ( L_364 ) ;
F_35 ( V_7 , L_365 ) ;
return F_247 ( log ) ;
}
for ( V_150 = 0 ; V_150 < V_18 -> V_29 . V_26 / sizeof( T_4 ) ; V_150 += 4 )
F_5 ( V_7 , L_366 ,
* ( log + V_150 ) , * ( log + V_150 + 1 ) ,
* ( log + V_150 + 2 ) , * ( log + V_150 + 3 ) ) ;
F_46 ( V_7 , '\n' ) ;
F_248 ( V_18 ) ;
return 0 ;
}
static int F_249 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
if ( ! V_11 -> V_533 . log . V_28 )
return - V_592 ;
* V_206 = V_197 . V_593 ;
return 0 ;
}
static int F_250 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_11 = V_10 ;
int V_70 ;
if ( ! V_11 -> V_533 . log . V_28 )
return - V_592 ;
V_70 = F_44 ( & V_11 -> V_63 . V_34 ) ;
if ( V_70 )
return V_70 ;
F_83 ( V_11 ) ;
V_70 = F_251 ( V_11 , V_206 ) ;
F_102 ( V_11 ) ;
F_47 ( & V_11 -> V_63 . V_34 ) ;
return V_70 ;
}
static const char * F_252 ( T_4 V_206 )
{
static const char * const V_594 [] = {
L_367 ,
L_368 ,
L_369 ,
L_370 ,
L_371 ,
L_372 ,
L_373 ,
L_374 ,
L_375 ,
L_376 ,
L_377
} ;
V_206 = ( V_206 & V_595 ) >> V_596 ;
if ( V_206 < F_54 ( V_594 ) )
return V_594 [ V_206 ] ;
return L_264 ;
}
static int F_253 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_597 = 0 ;
T_4 V_598 [ 3 ] ;
enum V_151 V_151 ;
bool V_506 = false ;
if ( ! F_254 ( V_11 ) ) {
F_35 ( V_7 , L_378 ) ;
return 0 ;
}
F_83 ( V_11 ) ;
F_58 ( & V_11 -> V_599 . V_393 ) ;
F_5 ( V_7 , L_379 , F_6 ( V_11 -> V_599 . V_600 ) ) ;
F_5 ( V_7 , L_380 , F_6 ( V_11 -> V_599 . V_601 ) ) ;
F_5 ( V_7 , L_381 , F_6 ( ( bool ) V_11 -> V_599 . V_506 ) ) ;
F_5 ( V_7 , L_382 , F_6 ( V_11 -> V_599 . V_88 ) ) ;
F_5 ( V_7 , L_383 ,
V_11 -> V_599 . V_602 ) ;
F_5 ( V_7 , L_384 ,
F_6 ( F_255 ( & V_11 -> V_599 . V_603 . V_603 ) ) ) ;
if ( F_256 ( V_11 ) ) {
if ( V_11 -> V_599 . V_604 )
V_506 = F_85 ( V_605 ) & V_606 ;
else
V_506 = F_85 ( V_607 ) & V_608 ;
} else {
F_86 (dev_priv, pipe) {
enum V_609 V_610 =
F_257 ( V_11 , V_151 ) ;
enum V_157 V_158 ;
V_158 = F_258 ( V_610 ) ;
if ( ! F_88 ( V_11 ,
V_158 ) )
continue;
V_598 [ V_151 ] = F_85 ( F_259 ( V_151 ) ) &
V_611 ;
if ( ( V_598 [ V_151 ] == V_612 ) ||
( V_598 [ V_151 ] == V_613 ) )
V_506 = true ;
F_91 ( V_11 , V_158 ) ;
}
}
F_5 ( V_7 , L_385 ,
F_6 ( V_11 -> V_599 . V_614 ) ) ;
F_5 ( V_7 , L_386 , F_6 ( V_506 ) ) ;
if ( ! F_256 ( V_11 ) )
F_86 (dev_priv, pipe) {
if ( ( V_598 [ V_151 ] == V_612 ) ||
( V_598 [ V_151 ] == V_613 ) )
F_5 ( V_7 , L_387 , F_89 ( V_151 ) ) ;
}
F_35 ( V_7 , L_388 ) ;
if ( F_127 ( V_11 ) || F_128 ( V_11 ) ) {
V_597 = F_85 ( V_615 ) &
V_616 ;
F_5 ( V_7 , L_389 , V_597 ) ;
}
if ( V_11 -> V_599 . V_604 ) {
T_4 V_617 = F_85 ( V_618 ) ;
F_5 ( V_7 , L_390 ,
V_617 , F_252 ( V_617 ) ) ;
}
F_47 ( & V_11 -> V_599 . V_393 ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static int F_260 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_619 * V_620 ;
struct V_621 V_622 ;
struct V_623 * V_623 = NULL ;
int V_70 ;
T_12 V_624 [ 6 ] ;
F_261 ( V_5 ) ;
F_262 ( V_5 , & V_622 ) ;
F_263 (connector, &conn_iter) {
struct V_625 * V_626 ;
if ( ! V_620 -> V_29 . V_96 -> V_627 )
continue;
V_626 = V_620 -> V_29 . V_96 -> V_626 ;
if ( ! V_626 -> V_96 -> V_88 )
continue;
if ( V_620 -> V_29 . V_628 != V_629 )
continue;
V_623 = F_264 ( V_620 -> V_29 . V_96 -> V_627 ) ;
V_70 = F_265 ( V_623 , V_624 ) ;
if ( V_70 )
goto V_74;
F_5 ( V_7 , L_391 ,
V_624 [ 0 ] , V_624 [ 1 ] , V_624 [ 2 ] ,
V_624 [ 3 ] , V_624 [ 4 ] , V_624 [ 5 ] ) ;
goto V_74;
}
V_70 = - V_406 ;
V_74:
F_266 ( & V_622 ) ;
F_267 ( V_5 ) ;
return V_70 ;
}
static int F_268 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
unsigned long long V_501 ;
T_4 V_630 ;
if ( F_10 ( V_11 ) < 6 )
return - V_406 ;
F_83 ( V_11 ) ;
if ( F_269 ( V_631 , & V_501 ) ) {
F_102 ( V_11 ) ;
return - V_406 ;
}
V_630 = ( V_501 & 0x1f00 ) >> 8 ;
V_501 = F_85 ( V_632 ) ;
V_501 = ( 1000000 * V_501 ) >> V_630 ;
F_102 ( V_11 ) ;
F_5 ( V_7 , L_392 , V_501 ) ;
return 0 ;
}
static int F_270 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_633 * V_634 = V_11 -> V_63 . V_634 ;
if ( ! F_271 ( V_11 ) )
F_35 ( V_7 , L_393 ) ;
F_5 ( V_7 , L_394 , F_6 ( ! V_11 -> V_305 . V_306 ) ) ;
F_5 ( V_7 , L_395 ,
F_6 ( ! F_272 ( V_11 ) ) ) ;
#ifdef F_273
F_5 ( V_7 , L_396 ,
F_39 ( & V_11 -> V_63 . V_5 -> V_501 . V_635 ) ) ;
#else
F_5 ( V_7 , L_397 ) ;
#endif
F_5 ( V_7 , L_398 ,
F_274 ( V_634 -> V_636 ) ,
V_634 -> V_636 ) ;
return 0 ;
}
static int F_275 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_637 * V_638 = & V_11 -> V_638 ;
int V_150 ;
F_58 ( & V_638 -> V_393 ) ;
F_5 ( V_7 , L_399 , L_400 , L_401 ) ;
for ( V_150 = 0 ; V_150 < V_638 -> V_639 ; V_150 ++ ) {
struct V_640 * V_641 ;
enum V_157 V_158 ;
V_641 = & V_638 -> V_642 [ V_150 ] ;
F_5 ( V_7 , L_402 , V_641 -> V_8 ,
V_641 -> V_68 ) ;
F_276 (power_domain, power_well->domains)
F_5 ( V_7 , L_403 ,
F_277 ( V_158 ) ,
V_638 -> V_643 [ V_158 ] ) ;
}
F_47 ( & V_638 -> V_393 ) ;
return 0 ;
}
static int F_278 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_644 * V_645 ;
if ( ! F_279 ( V_11 ) ) {
F_35 ( V_7 , L_230 ) ;
return 0 ;
}
V_645 = & V_11 -> V_645 ;
F_83 ( V_11 ) ;
F_5 ( V_7 , L_404 , F_6 ( V_645 -> V_646 != NULL ) ) ;
F_5 ( V_7 , L_405 , V_645 -> V_647 ) ;
if ( ! V_645 -> V_646 )
goto V_74;
F_5 ( V_7 , L_406 , F_280 ( V_645 -> V_648 ) ,
F_281 ( V_645 -> V_648 ) ) ;
if ( F_282 ( V_11 ) ||
( F_283 ( V_11 ) && V_645 -> V_648 >= F_284 ( 1 , 6 ) ) ) {
F_5 ( V_7 , L_407 ,
F_85 ( V_649 ) ) ;
F_5 ( V_7 , L_408 ,
F_85 ( V_650 ) ) ;
} else if ( F_285 ( V_11 ) && V_645 -> V_648 >= F_284 ( 1 , 4 ) ) {
F_5 ( V_7 , L_407 ,
F_85 ( V_651 ) ) ;
}
V_74:
F_5 ( V_7 , L_409 , F_85 ( F_286 ( 0 ) ) ) ;
F_5 ( V_7 , L_410 , F_85 ( V_652 ) ) ;
F_5 ( V_7 , L_411 , F_85 ( V_653 ) ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static void F_287 ( struct V_6 * V_7 , int V_654 ,
struct V_655 * V_656 )
{
int V_150 ;
for ( V_150 = 0 ; V_150 < V_654 ; V_150 ++ )
F_46 ( V_7 , '\t' ) ;
F_5 ( V_7 , L_412 ,
V_656 -> V_29 . V_55 , V_656 -> V_8 ,
V_656 -> V_657 , V_656 -> clock ,
V_656 -> V_658 , V_656 -> V_659 ,
V_656 -> V_660 , V_656 -> V_661 ,
V_656 -> V_662 , V_656 -> V_663 ,
V_656 -> V_664 , V_656 -> V_665 ,
V_656 -> type , V_656 -> V_295 ) ;
}
static void F_288 ( struct V_6 * V_7 ,
struct V_666 * V_666 ,
struct V_667 * V_667 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_625 * V_626 = & V_666 -> V_29 ;
struct V_619 * V_619 ;
struct V_668 * V_669 ;
V_669 = & V_667 -> V_29 ;
F_5 ( V_7 , L_413 ,
V_669 -> V_29 . V_55 , V_669 -> V_8 ) ;
F_289 (dev, encoder, intel_connector) {
struct V_670 * V_620 = & V_619 -> V_29 ;
F_5 ( V_7 , L_414 ,
V_620 -> V_29 . V_55 ,
V_620 -> V_8 ,
F_290 ( V_620 -> V_671 ) ) ;
if ( V_620 -> V_671 == V_672 ) {
struct V_655 * V_656 = & V_626 -> V_656 ;
F_5 ( V_7 , L_415 ) ;
F_287 ( V_7 , 2 , V_656 ) ;
} else {
F_46 ( V_7 , '\n' ) ;
}
}
}
static void F_291 ( struct V_6 * V_7 , struct V_666 * V_666 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_625 * V_626 = & V_666 -> V_29 ;
struct V_667 * V_667 ;
struct V_673 * V_674 = V_626 -> V_675 -> V_96 ;
struct V_442 * V_446 = V_674 -> V_446 ;
if ( V_446 )
F_5 ( V_7 , L_416 ,
V_446 -> V_29 . V_55 , V_674 -> V_676 >> 16 ,
V_674 -> V_677 >> 16 , V_446 -> V_51 , V_446 -> V_52 ) ;
else
F_35 ( V_7 , L_417 ) ;
F_292 (dev, crtc, intel_encoder)
F_288 ( V_7 , V_666 , V_667 ) ;
}
static void F_293 ( struct V_6 * V_7 , struct V_678 * V_679 )
{
struct V_655 * V_656 = V_679 -> V_680 ;
F_5 ( V_7 , L_418 ) ;
F_287 ( V_7 , 2 , V_656 ) ;
}
static void F_294 ( struct V_6 * V_7 ,
struct V_619 * V_619 )
{
struct V_667 * V_667 = V_619 -> V_669 ;
struct V_623 * V_623 = F_264 ( & V_667 -> V_29 ) ;
F_5 ( V_7 , L_419 , V_623 -> V_681 [ V_682 ] ) ;
F_5 ( V_7 , L_420 , F_6 ( V_623 -> V_683 ) ) ;
if ( V_619 -> V_29 . V_628 == V_629 )
F_293 ( V_7 , & V_619 -> V_679 ) ;
F_295 ( V_7 , V_623 -> V_681 , V_623 -> V_684 ,
& V_623 -> V_685 ) ;
}
static void F_296 ( struct V_6 * V_7 ,
struct V_619 * V_619 )
{
struct V_667 * V_667 = V_619 -> V_669 ;
struct V_686 * V_687 =
F_297 ( & V_667 -> V_29 ) ;
struct V_688 * V_689 = V_687 -> V_675 ;
struct V_623 * V_623 = & V_689 -> V_690 ;
bool V_683 = F_298 ( & V_623 -> V_691 ,
V_619 -> V_692 ) ;
F_5 ( V_7 , L_420 , F_6 ( V_683 ) ) ;
}
static void F_299 ( struct V_6 * V_7 ,
struct V_619 * V_619 )
{
struct V_667 * V_667 = V_619 -> V_669 ;
struct V_693 * V_693 = F_300 ( & V_667 -> V_29 ) ;
F_5 ( V_7 , L_420 , F_6 ( V_693 -> V_683 ) ) ;
}
static void F_301 ( struct V_6 * V_7 ,
struct V_619 * V_619 )
{
F_293 ( V_7 , & V_619 -> V_679 ) ;
}
static void F_302 ( struct V_6 * V_7 ,
struct V_670 * V_620 )
{
struct V_619 * V_619 = F_303 ( V_620 ) ;
struct V_667 * V_667 = V_619 -> V_669 ;
struct V_655 * V_656 ;
F_5 ( V_7 , L_421 ,
V_620 -> V_29 . V_55 , V_620 -> V_8 ,
F_290 ( V_620 -> V_671 ) ) ;
if ( V_620 -> V_671 == V_672 ) {
F_5 ( V_7 , L_422 , V_620 -> V_694 . V_8 ) ;
F_5 ( V_7 , L_423 ,
V_620 -> V_694 . V_695 ,
V_620 -> V_694 . V_696 ) ;
F_5 ( V_7 , L_424 ,
F_304 ( V_620 -> V_694 . V_697 ) ) ;
F_5 ( V_7 , L_425 ,
V_620 -> V_694 . V_698 ) ;
}
if ( ! V_667 )
return;
switch ( V_620 -> V_628 ) {
case V_699 :
case V_629 :
if ( V_667 -> type == V_700 )
F_296 ( V_7 , V_619 ) ;
else
F_294 ( V_7 , V_619 ) ;
break;
case V_701 :
if ( V_667 -> type == V_702 )
F_301 ( V_7 , V_619 ) ;
break;
case V_703 :
if ( V_667 -> type == V_704 ||
V_667 -> type == V_705 )
F_299 ( V_7 , V_619 ) ;
break;
default:
break;
}
F_5 ( V_7 , L_426 ) ;
F_28 (mode, &connector->modes, head)
F_287 ( V_7 , 2 , V_656 ) ;
}
static const char * F_305 ( enum V_706 type )
{
switch ( type ) {
case V_707 :
return L_427 ;
case V_708 :
return L_428 ;
case V_709 :
return L_429 ;
}
return L_264 ;
}
static const char * F_306 ( unsigned int V_710 )
{
static char V_198 [ 48 ] ;
snprintf ( V_198 , sizeof( V_198 ) ,
L_430 ,
( V_710 & V_711 ) ? L_431 : L_13 ,
( V_710 & V_712 ) ? L_432 : L_13 ,
( V_710 & V_713 ) ? L_433 : L_13 ,
( V_710 & V_714 ) ? L_434 : L_13 ,
( V_710 & V_715 ) ? L_435 : L_13 ,
( V_710 & V_716 ) ? L_436 : L_13 ,
V_710 ) ;
return V_198 ;
}
static void F_307 ( struct V_6 * V_7 , struct V_666 * V_666 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_717 * V_717 ;
F_308 (dev, intel_crtc, intel_plane) {
struct V_673 * V_96 ;
struct V_718 * V_50 = & V_717 -> V_29 ;
struct V_719 V_720 ;
if ( ! V_50 -> V_96 ) {
F_35 ( V_7 , L_437 ) ;
continue;
}
V_96 = V_50 -> V_96 ;
if ( V_96 -> V_446 ) {
F_309 ( V_96 -> V_446 -> V_447 -> V_447 ,
& V_720 ) ;
} else {
sprintf ( V_720 . V_195 , L_438 ) ;
}
F_5 ( V_7 , L_439 ,
V_50 -> V_29 . V_55 ,
F_305 ( V_717 -> V_29 . type ) ,
V_96 -> V_721 , V_96 -> V_722 ,
V_96 -> V_723 , V_96 -> V_724 ,
( V_96 -> V_676 >> 16 ) ,
( ( V_96 -> V_676 & 0xffff ) * 15625 ) >> 10 ,
( V_96 -> V_677 >> 16 ) ,
( ( V_96 -> V_677 & 0xffff ) * 15625 ) >> 10 ,
( V_96 -> V_725 >> 16 ) ,
( ( V_96 -> V_725 & 0xffff ) * 15625 ) >> 10 ,
( V_96 -> V_726 >> 16 ) ,
( ( V_96 -> V_726 & 0xffff ) * 15625 ) >> 10 ,
V_720 . V_195 ,
F_306 ( V_96 -> V_710 ) ) ;
}
}
static void F_310 ( struct V_6 * V_7 , struct V_666 * V_666 )
{
struct V_727 * V_728 ;
int V_729 = V_666 -> V_729 ;
int V_150 ;
V_728 = F_311 ( V_666 -> V_29 . V_96 ) ;
if ( V_729 ) {
F_5 ( V_7 , L_440 ,
V_729 ,
V_728 -> V_730 . V_731 ,
V_728 -> V_730 . V_732 ) ;
for ( V_150 = 0 ; V_150 < V_729 ; V_150 ++ ) {
struct V_733 * V_734 =
& V_728 -> V_730 . V_735 [ V_150 ] ;
F_5 ( V_7 , L_441 ,
V_150 , F_6 ( V_734 -> V_736 ) , V_734 -> V_656 ) ;
}
F_35 ( V_7 , L_388 ) ;
} else {
F_35 ( V_7 , L_442 ) ;
}
}
static int F_312 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_666 * V_626 ;
struct V_670 * V_620 ;
struct V_621 V_622 ;
F_83 ( V_11 ) ;
F_5 ( V_7 , L_443 ) ;
F_5 ( V_7 , L_444 ) ;
F_313 (dev, crtc) {
struct V_727 * V_728 ;
F_314 ( & V_626 -> V_29 . V_737 , NULL ) ;
V_728 = F_311 ( V_626 -> V_29 . V_96 ) ;
F_5 ( V_7 , L_445 ,
V_626 -> V_29 . V_29 . V_55 , F_89 ( V_626 -> V_151 ) ,
F_6 ( V_728 -> V_29 . V_88 ) ,
V_728 -> V_738 , V_728 -> V_739 ,
F_6 ( V_728 -> V_740 ) , V_728 -> V_741 ) ;
if ( V_728 -> V_29 . V_88 ) {
struct V_717 * V_742 =
F_315 ( V_626 -> V_29 . V_742 ) ;
F_291 ( V_7 , V_626 ) ;
F_5 ( V_7 , L_446 ,
F_6 ( V_742 -> V_29 . V_96 -> V_743 ) ,
V_742 -> V_29 . V_96 -> V_721 ,
V_742 -> V_29 . V_96 -> V_722 ,
V_742 -> V_29 . V_96 -> V_723 ,
V_742 -> V_29 . V_96 -> V_724 ,
V_742 -> V_742 . V_29 ) ;
F_310 ( V_7 , V_626 ) ;
F_307 ( V_7 , V_626 ) ;
}
F_5 ( V_7 , L_447 ,
F_6 ( ! V_626 -> V_744 ) ,
F_6 ( ! V_626 -> V_745 ) ) ;
F_316 ( & V_626 -> V_29 . V_737 ) ;
}
F_5 ( V_7 , L_388 ) ;
F_5 ( V_7 , L_448 ) ;
F_5 ( V_7 , L_449 ) ;
F_58 ( & V_5 -> V_451 . V_737 ) ;
F_262 ( V_5 , & V_622 ) ;
F_317 (connector, &conn_iter)
F_302 ( V_7 , V_620 ) ;
F_266 ( & V_622 ) ;
F_47 ( & V_5 -> V_451 . V_737 ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static int F_318 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_313 * error = & V_11 -> V_294 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
F_83 ( V_11 ) ;
F_5 ( V_7 , L_450 ,
F_6 ( V_11 -> V_305 . V_306 ) ) ;
F_5 ( V_7 , L_451 ,
V_11 -> V_305 . V_507 ) ;
F_53 (engine, dev_priv, id) {
struct V_141 * V_61 = & V_31 -> V_142 ;
struct V_115 * V_128 ;
struct V_143 * V_144 ;
T_3 V_746 ;
F_5 ( V_7 , L_283 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_452 ,
F_74 ( V_31 ) ,
F_145 ( V_31 ) ,
V_31 -> V_307 . V_132 ,
F_71 ( V_135 - V_31 -> V_307 . V_312 ) ,
V_31 -> V_137 -> V_308 ) ;
F_5 ( V_7 , L_453 ,
F_150 ( error , V_31 ) ) ;
F_65 () ;
F_5 ( V_7 , L_454 ) ;
V_128 = F_319 ( & V_31 -> V_137 -> V_747 ,
struct V_115 , V_748 ) ;
if ( & V_128 -> V_748 != & V_31 -> V_137 -> V_747 )
F_70 ( V_7 , V_128 , L_455 ) ;
V_128 = F_320 ( & V_31 -> V_137 -> V_747 ,
struct V_115 , V_748 ) ;
if ( & V_128 -> V_748 != & V_31 -> V_137 -> V_747 )
F_70 ( V_7 , V_128 , L_456 ) ;
V_128 = F_321 ( V_31 ) ;
if ( V_128 ) {
F_70 ( V_7 , V_128 , L_457 ) ;
F_5 ( V_7 ,
L_458 ,
V_128 -> V_455 , V_128 -> V_749 , V_128 -> V_456 ,
V_128 -> V_750 ? F_322 ( V_128 -> V_750 -> V_3 . V_41 ) : ~ 0u ,
V_128 -> V_750 ? F_323 ( V_128 -> V_750 -> V_3 . V_41 ) : ~ 0u ) ;
}
F_5 ( V_7 , L_459 ,
F_85 ( F_324 ( V_31 -> V_751 ) ) ,
V_128 ? F_204 ( V_128 -> V_97 -> V_28 ) : 0 ) ;
F_5 ( V_7 , L_460 ,
F_85 ( F_325 ( V_31 -> V_751 ) ) & V_752 ,
V_128 ? V_128 -> V_97 -> V_455 : 0 ) ;
F_5 ( V_7 , L_461 ,
F_85 ( F_326 ( V_31 -> V_751 ) ) & V_753 ,
V_128 ? V_128 -> V_97 -> V_456 : 0 ) ;
F_5 ( V_7 , L_462 ,
F_85 ( F_327 ( V_31 -> V_751 ) ) ,
F_85 ( F_327 ( V_31 -> V_751 ) ) & ( V_754 | V_755 ) ? L_463 : L_13 ) ;
F_67 () ;
V_746 = F_141 ( V_31 ) ;
F_5 ( V_7 , L_464 ,
F_322 ( V_746 ) , F_323 ( V_746 ) ) ;
V_746 = F_328 ( V_31 ) ;
F_5 ( V_7 , L_465 ,
F_322 ( V_746 ) , F_323 ( V_746 ) ) ;
if ( V_197 . V_465 ) {
T_4 V_75 , V_756 , V_757 ;
unsigned int V_758 ;
F_5 ( V_7 , L_466 ,
F_85 ( F_329 ( V_31 ) ) ,
F_85 ( F_330 ( V_31 ) ) ) ;
V_75 = F_85 ( F_331 ( V_31 ) ) ;
V_756 = F_332 ( V_75 ) ;
V_757 = F_333 ( V_75 ) ;
F_5 ( V_7 , L_467 ,
V_756 , V_757 ,
F_6 ( F_139 ( V_759 ,
& V_31 -> V_760 ) ) ) ;
if ( V_756 >= V_761 )
V_756 = 0 ;
if ( V_757 >= V_761 )
V_757 = 0 ;
if ( V_756 > V_757 )
V_757 += V_761 ;
while ( V_756 < V_757 ) {
V_758 = ++ V_756 % V_761 ;
F_5 ( V_7 , L_468 ,
V_758 ,
F_85 ( F_334 ( V_31 , V_758 ) ) ,
F_85 ( F_335 ( V_31 , V_758 ) ) ) ;
}
F_65 () ;
for ( V_758 = 0 ; V_758 < F_54 ( V_31 -> V_762 ) ; V_758 ++ ) {
unsigned int V_68 ;
V_128 = F_336 ( & V_31 -> V_762 [ V_758 ] ,
& V_68 ) ;
if ( V_128 ) {
F_5 ( V_7 , L_469 ,
V_758 , V_68 ) ;
F_70 ( V_7 , V_128 , L_470 ) ;
} else {
F_5 ( V_7 , L_471 ,
V_758 ) ;
}
}
F_67 () ;
F_75 ( & V_31 -> V_137 -> V_393 ) ;
for ( V_144 = V_31 -> V_763 ; V_144 ; V_144 = F_77 ( V_144 ) ) {
struct V_764 * V_765 =
F_78 ( V_144 , F_79 ( * V_765 ) , V_3 ) ;
F_28 (rq, &p->requests,
priotree.link)
F_70 ( V_7 , V_128 , L_472 ) ;
}
F_80 ( & V_31 -> V_137 -> V_393 ) ;
} else if ( F_10 ( V_11 ) > 6 ) {
F_5 ( V_7 , L_473 ,
F_85 ( F_222 ( V_31 ) ) ) ;
F_5 ( V_7 , L_474 ,
F_85 ( F_223 ( V_31 ) ) ) ;
F_5 ( V_7 , L_475 ,
F_85 ( F_224 ( V_31 ) ) ) ;
}
F_75 ( & V_61 -> V_145 ) ;
for ( V_144 = F_76 ( & V_61 -> V_146 ) ; V_144 ; V_144 = F_77 ( V_144 ) ) {
struct V_147 * V_148 = F_78 ( V_144 , F_79 ( * V_148 ) , V_3 ) ;
F_5 ( V_7 , L_165 ,
V_148 -> V_149 -> V_125 , V_148 -> V_149 -> V_123 , V_148 -> V_132 ) ;
}
F_80 ( & V_61 -> V_145 ) ;
F_35 ( V_7 , L_388 ) ;
}
F_102 ( V_11 ) ;
return 0 ;
}
static int F_337 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
int V_766 = F_9 ( V_11 ) -> V_766 ;
enum V_90 V_55 ;
int V_91 , V_70 ;
if ( ! V_197 . V_767 ) {
F_35 ( V_7 , L_476 ) ;
return 0 ;
}
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_83 ( V_11 ) ;
if ( F_128 ( V_11 ) ) {
struct V_461 * V_461 ;
T_11 * V_132 ;
V_461 = F_206 ( V_11 -> V_768 -> V_18 , 0 ) ;
V_132 = ( T_11 * ) F_207 ( V_461 ) ;
F_53 (engine, dev_priv, id) {
T_11 V_46 ;
F_5 ( V_7 , L_283 , V_31 -> V_8 ) ;
F_35 ( V_7 , L_477 ) ;
for ( V_91 = 0 ; V_91 < V_766 ; V_91 ++ ) {
V_46 = V_55 * V_292 + V_91 ;
F_5 ( V_7 , L_478 ,
V_132 [ V_46 ] , V_46 * 8 ) ;
}
F_46 ( V_7 , '\n' ) ;
F_35 ( V_7 , L_479 ) ;
for ( V_91 = 0 ; V_91 < V_766 ; V_91 ++ ) {
V_46 = V_55 + ( V_91 * V_292 ) ;
F_5 ( V_7 , L_478 ,
V_132 [ V_46 ] , V_46 * 8 ) ;
}
F_46 ( V_7 , '\n' ) ;
}
F_208 ( V_132 ) ;
} else {
F_35 ( V_7 , L_477 ) ;
F_53 (engine, dev_priv, id)
for ( V_91 = 0 ; V_91 < V_766 ; V_91 ++ )
F_5 ( V_7 , L_480 ,
F_85 ( V_31 -> V_768 . V_769 . signal [ V_91 ] ) ) ;
F_46 ( V_7 , '\n' ) ;
}
F_102 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static int F_338 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_150 ;
F_261 ( V_5 ) ;
for ( V_150 = 0 ; V_150 < V_11 -> V_770 ; V_150 ++ ) {
struct V_771 * V_772 = & V_11 -> V_773 [ V_150 ] ;
F_5 ( V_7 , L_481 , V_150 , V_772 -> V_8 , V_772 -> V_55 ) ;
F_5 ( V_7 , L_482 ,
V_772 -> V_96 . V_774 , V_772 -> V_775 , F_6 ( V_772 -> V_776 ) ) ;
F_5 ( V_7 , L_483 ) ;
F_5 ( V_7 , L_484 , V_772 -> V_96 . V_777 . V_778 ) ;
F_5 ( V_7 , L_485 ,
V_772 -> V_96 . V_777 . V_779 ) ;
F_5 ( V_7 , L_486 , V_772 -> V_96 . V_777 . V_780 ) ;
F_5 ( V_7 , L_487 , V_772 -> V_96 . V_777 . V_781 ) ;
F_5 ( V_7 , L_488 , V_772 -> V_96 . V_777 . V_782 ) ;
}
F_267 ( V_5 ) ;
return 0 ;
}
static int F_339 ( struct V_6 * V_7 , void * V_207 )
{
int V_150 ;
int V_70 ;
struct V_30 * V_31 ;
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_783 * V_784 = & V_11 -> V_784 ;
enum V_90 V_55 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_83 ( V_11 ) ;
F_5 ( V_7 , L_489 , V_784 -> V_68 ) ;
F_53 (engine, dev_priv, id)
F_5 ( V_7 , L_490 ,
V_31 -> V_8 , V_784 -> V_785 [ V_55 ] ) ;
for ( V_150 = 0 ; V_150 < V_784 -> V_68 ; ++ V_150 ) {
T_10 V_746 ;
T_4 V_395 , V_786 , V_756 ;
bool V_787 ;
V_746 = V_784 -> V_343 [ V_150 ] . V_746 ;
V_395 = V_784 -> V_343 [ V_150 ] . V_395 ;
V_786 = V_784 -> V_343 [ V_150 ] . V_786 ;
V_756 = F_85 ( V_746 ) ;
V_787 = ( V_786 & V_395 ) == ( V_756 & V_395 ) ;
F_5 ( V_7 , L_491 ,
F_340 ( V_746 ) , V_786 , V_395 , V_756 , V_787 ? L_492 : L_493 ) ;
}
F_102 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static int F_341 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_788 * V_789 ;
struct V_790 * V_791 ;
enum V_151 V_151 ;
int V_50 ;
if ( F_10 ( V_11 ) < 9 )
return 0 ;
F_261 ( V_5 ) ;
V_789 = & V_11 -> V_792 . V_793 . V_789 ;
F_5 ( V_7 , L_494 , L_13 , L_495 , L_496 , L_497 ) ;
F_86 (dev_priv, pipe) {
F_5 ( V_7 , L_498 , F_89 ( V_151 ) ) ;
F_342 (dev_priv, pipe, plane) {
V_791 = & V_789 -> V_50 [ V_151 ] [ V_50 ] ;
F_5 ( V_7 , L_499 , V_50 + 1 ,
V_791 -> V_41 , V_791 -> V_794 ,
F_343 ( V_791 ) ) ;
}
V_791 = & V_789 -> V_50 [ V_151 ] [ V_795 ] ;
F_5 ( V_7 , L_500 , L_501 , V_791 -> V_41 ,
V_791 -> V_794 , F_343 ( V_791 ) ) ;
}
F_267 ( V_5 ) ;
return 0 ;
}
static void F_344 ( struct V_6 * V_7 ,
struct V_62 * V_5 ,
struct V_666 * V_666 )
{
struct V_1 * V_11 = F_2 ( V_5 ) ;
struct V_796 * V_797 = & V_11 -> V_797 ;
int V_657 = 0 ;
struct V_670 * V_620 ;
struct V_621 V_622 ;
F_262 ( V_5 , & V_622 ) ;
F_317 (connector, &conn_iter) {
if ( V_620 -> V_96 -> V_626 != & V_666 -> V_29 )
continue;
F_5 ( V_7 , L_162 , V_620 -> V_8 ) ;
}
F_266 ( & V_622 ) ;
if ( V_11 -> V_438 . V_798 == V_799 )
F_35 ( V_7 , L_502 ) ;
else if ( V_11 -> V_438 . V_798 == V_800 )
F_35 ( V_7 , L_503 ) ;
else if ( V_11 -> V_438 . V_798 == V_801 )
F_35 ( V_7 , L_504 ) ;
else
F_35 ( V_7 , L_505 ) ;
F_35 ( V_7 , L_506 ) ;
if ( F_311 ( V_666 -> V_29 . V_96 ) -> V_802 ) {
struct V_678 * V_679 ;
F_58 ( & V_797 -> V_737 ) ;
F_35 ( V_7 , L_507 ) ;
if ( ! V_797 -> V_690 ) {
F_35 ( V_7 , L_508 ) ;
F_47 ( & V_797 -> V_737 ) ;
return;
}
V_679 = & V_797 -> V_690 -> V_803 -> V_679 ;
F_5 ( V_7 , L_509 ,
V_797 -> V_602 ) ;
F_35 ( V_7 , L_510 ) ;
if ( V_797 -> V_804 == V_805 ) {
F_35 ( V_7 , L_511 ) ;
V_657 = V_679 -> V_680 -> V_657 ;
} else if ( V_797 -> V_804 == V_806 ) {
F_35 ( V_7 , L_512 ) ;
V_657 = V_679 -> V_807 -> V_657 ;
} else {
F_5 ( V_7 , L_513 ,
V_797 -> V_804 ) ;
F_47 ( & V_797 -> V_737 ) ;
return;
}
F_5 ( V_7 , L_514 , V_657 ) ;
F_35 ( V_7 , L_510 ) ;
F_47 ( & V_797 -> V_737 ) ;
} else {
F_35 ( V_7 , L_515 ) ;
}
F_35 ( V_7 , L_388 ) ;
}
static int F_345 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_666 * V_666 ;
int V_808 = 0 ;
F_261 ( V_5 ) ;
F_313 (dev, intel_crtc) {
if ( V_666 -> V_29 . V_96 -> V_88 ) {
V_808 ++ ;
F_5 ( V_7 , L_516 , V_808 ) ;
F_344 ( V_7 , V_5 , V_666 ) ;
}
}
F_267 ( V_5 ) ;
if ( ! V_808 )
F_35 ( V_7 , L_517 ) ;
return 0 ;
}
static int F_346 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_667 * V_667 ;
struct V_688 * V_689 ;
struct V_670 * V_620 ;
struct V_621 V_622 ;
F_262 ( V_5 , & V_622 ) ;
F_317 (connector, &conn_iter) {
if ( V_620 -> V_628 != V_699 )
continue;
V_667 = F_347 ( V_620 ) ;
if ( ! V_667 || V_667 -> type == V_700 )
continue;
V_689 = F_348 ( & V_667 -> V_29 ) ;
if ( ! V_689 -> V_690 . V_809 )
continue;
F_5 ( V_7 , L_518 ,
F_349 ( V_689 -> V_692 ) ) ;
F_350 ( V_7 , & V_689 -> V_690 . V_691 ) ;
}
F_266 ( & V_622 ) ;
return 0 ;
}
static T_5 F_351 ( struct V_86 * V_86 ,
const char T_6 * V_190 ,
T_7 V_810 , T_8 * V_811 )
{
char * V_812 ;
int V_671 = 0 ;
struct V_62 * V_5 ;
struct V_670 * V_620 ;
struct V_621 V_622 ;
struct V_623 * V_623 ;
int V_206 = 0 ;
V_5 = ( (struct V_6 * ) V_86 -> V_193 ) -> V_12 ;
if ( V_810 == 0 )
return 0 ;
V_812 = F_352 ( V_190 , V_810 ) ;
if ( F_202 ( V_812 ) )
return F_247 ( V_812 ) ;
F_114 ( L_519 , ( unsigned int ) V_810 ) ;
F_262 ( V_5 , & V_622 ) ;
F_317 (connector, &conn_iter) {
struct V_667 * V_669 ;
if ( V_620 -> V_628 !=
V_699 )
continue;
V_669 = F_353 ( V_620 -> V_669 ) ;
if ( V_669 && V_669 -> type == V_700 )
continue;
if ( V_669 && V_620 -> V_671 == V_672 ) {
V_623 = F_264 ( & V_669 -> V_29 ) ;
V_671 = F_354 ( V_812 , 10 , & V_206 ) ;
if ( V_671 < 0 )
break;
F_114 ( L_520 , V_206 ) ;
if ( V_206 == 1 )
V_623 -> V_813 . V_814 = 1 ;
else
V_623 -> V_813 . V_814 = 0 ;
}
}
F_266 ( & V_622 ) ;
F_355 ( V_812 ) ;
if ( V_671 < 0 )
return V_671 ;
* V_811 += V_810 ;
return V_810 ;
}
static int F_356 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_670 * V_620 ;
struct V_621 V_622 ;
struct V_623 * V_623 ;
F_262 ( V_5 , & V_622 ) ;
F_317 (connector, &conn_iter) {
struct V_667 * V_669 ;
if ( V_620 -> V_628 !=
V_699 )
continue;
V_669 = F_353 ( V_620 -> V_669 ) ;
if ( V_669 && V_669 -> type == V_700 )
continue;
if ( V_669 && V_620 -> V_671 == V_672 ) {
V_623 = F_264 ( & V_669 -> V_29 ) ;
if ( V_623 -> V_813 . V_814 )
F_35 ( V_7 , L_521 ) ;
else
F_35 ( V_7 , L_522 ) ;
} else
F_35 ( V_7 , L_522 ) ;
}
F_266 ( & V_622 ) ;
return 0 ;
}
static int F_357 ( struct V_200 * V_200 ,
struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
return F_358 ( V_86 , F_356 ,
& V_11 -> V_63 ) ;
}
static int F_359 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_670 * V_620 ;
struct V_621 V_622 ;
struct V_623 * V_623 ;
F_262 ( V_5 , & V_622 ) ;
F_317 (connector, &conn_iter) {
struct V_667 * V_669 ;
if ( V_620 -> V_628 !=
V_699 )
continue;
V_669 = F_353 ( V_620 -> V_669 ) ;
if ( V_669 && V_669 -> type == V_700 )
continue;
if ( V_669 && V_620 -> V_671 == V_672 ) {
V_623 = F_264 ( & V_669 -> V_29 ) ;
if ( V_623 -> V_813 . V_815 ==
V_816 )
F_5 ( V_7 , L_523 ,
V_623 -> V_813 . V_817 . V_818 ) ;
else if ( V_623 -> V_813 . V_815 ==
V_819 ) {
F_5 ( V_7 , L_524 ,
V_623 -> V_813 . V_817 . V_658 ) ;
F_5 ( V_7 , L_525 ,
V_623 -> V_813 . V_817 . V_662 ) ;
F_5 ( V_7 , L_526 ,
V_623 -> V_813 . V_817 . V_820 ) ;
}
} else
F_35 ( V_7 , L_522 ) ;
}
F_266 ( & V_622 ) ;
return 0 ;
}
static int F_360 ( struct V_200 * V_200 ,
struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
return F_358 ( V_86 , F_359 ,
& V_11 -> V_63 ) ;
}
static int F_361 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_670 * V_620 ;
struct V_621 V_622 ;
struct V_623 * V_623 ;
F_262 ( V_5 , & V_622 ) ;
F_317 (connector, &conn_iter) {
struct V_667 * V_669 ;
if ( V_620 -> V_628 !=
V_699 )
continue;
V_669 = F_353 ( V_620 -> V_669 ) ;
if ( V_669 && V_669 -> type == V_700 )
continue;
if ( V_669 && V_620 -> V_671 == V_672 ) {
V_623 = F_264 ( & V_669 -> V_29 ) ;
F_5 ( V_7 , L_527 , V_623 -> V_813 . V_815 ) ;
} else
F_35 ( V_7 , L_522 ) ;
}
F_266 ( & V_622 ) ;
return 0 ;
}
static int F_362 ( struct V_200 * V_200 ,
struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
return F_358 ( V_86 , F_361 ,
& V_11 -> V_63 ) ;
}
static void F_363 ( struct V_6 * V_7 , const T_13 V_792 [ 8 ] )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_821 ;
int V_822 ;
if ( F_84 ( V_11 ) )
V_822 = 3 ;
else if ( F_99 ( V_11 ) )
V_822 = 1 ;
else if ( F_171 ( V_11 ) )
V_822 = 3 ;
else
V_822 = F_364 ( V_11 ) + 1 ;
F_261 ( V_5 ) ;
for ( V_821 = 0 ; V_821 < V_822 ; V_821 ++ ) {
unsigned int V_823 = V_792 [ V_821 ] ;
if ( F_10 ( V_11 ) >= 9 ||
F_99 ( V_11 ) ||
F_84 ( V_11 ) ||
F_171 ( V_11 ) )
V_823 *= 10 ;
else if ( V_821 > 0 )
V_823 *= 5 ;
F_5 ( V_7 , L_528 ,
V_821 , V_792 [ V_821 ] , V_823 / 10 , V_823 % 10 ) ;
}
F_267 ( V_5 ) ;
}
static int F_365 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_13 * V_824 ;
if ( F_10 ( V_11 ) >= 9 )
V_824 = V_11 -> V_792 . V_825 ;
else
V_824 = V_11 -> V_792 . V_826 ;
F_363 ( V_7 , V_824 ) ;
return 0 ;
}
static int F_366 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_13 * V_824 ;
if ( F_10 ( V_11 ) >= 9 )
V_824 = V_11 -> V_792 . V_825 ;
else
V_824 = V_11 -> V_792 . V_827 ;
F_363 ( V_7 , V_824 ) ;
return 0 ;
}
static int F_367 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_13 * V_824 ;
if ( F_10 ( V_11 ) >= 9 )
V_824 = V_11 -> V_792 . V_825 ;
else
V_824 = V_11 -> V_792 . V_828 ;
F_363 ( V_7 , V_824 ) ;
return 0 ;
}
static int F_368 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
if ( F_10 ( V_11 ) < 5 && ! F_171 ( V_11 ) )
return - V_406 ;
return F_358 ( V_86 , F_365 , V_11 ) ;
}
static int F_369 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
if ( F_370 ( V_11 ) )
return - V_406 ;
return F_358 ( V_86 , F_366 , V_11 ) ;
}
static int F_371 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
if ( F_370 ( V_11 ) )
return - V_406 ;
return F_358 ( V_86 , F_367 , V_11 ) ;
}
static T_5 F_372 ( struct V_86 * V_86 , const char T_6 * V_190 ,
T_7 V_810 , T_8 * V_811 , T_13 V_792 [ 8 ] )
{
struct V_6 * V_7 = V_86 -> V_193 ;
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
T_13 V_829 [ 8 ] = { 0 } ;
int V_822 ;
int V_821 ;
int V_70 ;
char V_196 [ 32 ] ;
if ( F_84 ( V_11 ) )
V_822 = 3 ;
else if ( F_99 ( V_11 ) )
V_822 = 1 ;
else if ( F_171 ( V_11 ) )
V_822 = 3 ;
else
V_822 = F_364 ( V_11 ) + 1 ;
if ( V_810 >= sizeof( V_196 ) )
return - V_592 ;
if ( F_373 ( V_196 , V_190 , V_810 ) )
return - V_830 ;
V_196 [ V_810 ] = '\0' ;
V_70 = sscanf ( V_196 , L_529 ,
& V_829 [ 0 ] , & V_829 [ 1 ] , & V_829 [ 2 ] , & V_829 [ 3 ] ,
& V_829 [ 4 ] , & V_829 [ 5 ] , & V_829 [ 6 ] , & V_829 [ 7 ] ) ;
if ( V_70 != V_822 )
return - V_592 ;
F_261 ( V_5 ) ;
for ( V_821 = 0 ; V_821 < V_822 ; V_821 ++ )
V_792 [ V_821 ] = V_829 [ V_821 ] ;
F_267 ( V_5 ) ;
return V_810 ;
}
static T_5 F_374 ( struct V_86 * V_86 , const char T_6 * V_190 ,
T_7 V_810 , T_8 * V_811 )
{
struct V_6 * V_7 = V_86 -> V_193 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_13 * V_824 ;
if ( F_10 ( V_11 ) >= 9 )
V_824 = V_11 -> V_792 . V_825 ;
else
V_824 = V_11 -> V_792 . V_826 ;
return F_372 ( V_86 , V_190 , V_810 , V_811 , V_824 ) ;
}
static T_5 F_375 ( struct V_86 * V_86 , const char T_6 * V_190 ,
T_7 V_810 , T_8 * V_811 )
{
struct V_6 * V_7 = V_86 -> V_193 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_13 * V_824 ;
if ( F_10 ( V_11 ) >= 9 )
V_824 = V_11 -> V_792 . V_825 ;
else
V_824 = V_11 -> V_792 . V_827 ;
return F_372 ( V_86 , V_190 , V_810 , V_811 , V_824 ) ;
}
static T_5 F_376 ( struct V_86 * V_86 , const char T_6 * V_190 ,
T_7 V_810 , T_8 * V_811 )
{
struct V_6 * V_7 = V_86 -> V_193 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_13 * V_824 ;
if ( F_10 ( V_11 ) >= 9 )
V_824 = V_11 -> V_792 . V_825 ;
else
V_824 = V_11 -> V_792 . V_828 ;
return F_372 ( V_86 , V_190 , V_810 , V_811 , V_824 ) ;
}
static int
F_377 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
* V_206 = F_378 ( & V_11 -> V_294 ) ;
return 0 ;
}
static int
F_379 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_197 = V_10 ;
struct V_30 * V_31 ;
unsigned int V_196 ;
if ( F_380 ( & V_197 -> V_294 ) )
return - V_831 ;
F_243 (engine, i915, val, tmp) {
V_31 -> V_307 . V_132 = F_74 ( V_31 ) ;
V_31 -> V_307 . V_310 = true ;
}
F_381 ( V_197 , V_206 , L_530 , V_206 ) ;
F_382 ( & V_197 -> V_294 . V_295 ,
V_297 ,
V_832 ) ;
return 0 ;
}
static int
F_383 ( struct V_1 * V_197 ,
unsigned long * V_833 ,
unsigned long V_206 )
{
int V_388 ;
V_388 = F_44 ( & V_197 -> V_63 . V_34 ) ;
if ( V_388 )
return V_388 ;
V_388 = F_384 ( V_197 ,
V_834 |
V_835 ) ;
if ( V_388 )
goto V_836;
* V_833 = V_206 ;
F_47 ( & V_197 -> V_63 . V_34 ) ;
while ( F_385 ( & V_197 -> V_305 . V_837 ) )
;
return 0 ;
V_836:
F_47 ( & V_197 -> V_63 . V_34 ) ;
return V_388 ;
}
static int
F_386 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
* V_206 = V_11 -> V_294 . V_309 ;
return 0 ;
}
static int
F_387 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_197 = V_10 ;
return F_383 ( V_197 , & V_197 -> V_294 . V_309 , V_206 ) ;
}
static int
F_388 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
* V_206 = V_11 -> V_294 . V_838 ;
return 0 ;
}
static int
F_389 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_197 = V_10 ;
V_206 &= F_9 ( V_197 ) -> V_839 ;
F_114 ( L_531 , V_206 ) ;
return F_383 ( V_197 , & V_197 -> V_294 . V_838 , V_206 ) ;
}
static int
F_390 ( void * V_10 , T_3 * V_206 )
{
* V_206 = V_840 ;
return 0 ;
}
static int
F_391 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_11 = V_10 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_70 = 0 ;
F_246 ( L_532 , V_206 ) ;
if ( V_206 & ( V_841 | V_842 ) ) {
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
if ( V_206 & V_841 )
V_70 = F_384 ( V_11 ,
V_835 |
V_834 ) ;
if ( V_206 & V_842 )
F_392 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
}
F_393 ( V_72 ) ;
if ( V_206 & V_843 )
F_394 ( V_11 , V_844 , NULL , V_845 ) ;
if ( V_206 & V_846 )
F_394 ( V_11 , V_844 , NULL , V_847 ) ;
if ( V_206 & V_848 )
F_395 ( V_11 ) ;
F_396 ( V_72 ) ;
if ( V_206 & V_849 ) {
F_397 () ;
F_398 ( V_11 ) ;
}
return V_70 ;
}
static int
F_399 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 6 )
return - V_406 ;
* V_206 = F_124 ( V_11 , V_11 -> V_217 . V_432 ) ;
return 0 ;
}
static int
F_400 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_850 , V_851 ;
int V_70 ;
if ( F_10 ( V_11 ) < 6 )
return - V_406 ;
F_114 ( L_533 , V_206 ) ;
V_70 = F_44 ( & V_11 -> V_217 . V_218 ) ;
if ( V_70 )
return V_70 ;
V_206 = F_401 ( V_11 , V_206 ) ;
V_850 = V_11 -> V_217 . V_222 ;
V_851 = V_11 -> V_217 . V_223 ;
if ( V_206 < V_851 || V_206 > V_850 || V_206 < V_11 -> V_217 . V_431 ) {
F_47 ( & V_11 -> V_217 . V_218 ) ;
return - V_592 ;
}
V_11 -> V_217 . V_432 = V_206 ;
if ( F_402 ( V_11 , V_206 ) )
F_114 ( L_534 ) ;
F_47 ( & V_11 -> V_217 . V_218 ) ;
return 0 ;
}
static int
F_403 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 6 )
return - V_406 ;
* V_206 = F_124 ( V_11 , V_11 -> V_217 . V_431 ) ;
return 0 ;
}
static int
F_404 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_850 , V_851 ;
int V_70 ;
if ( F_10 ( V_11 ) < 6 )
return - V_406 ;
F_114 ( L_535 , V_206 ) ;
V_70 = F_44 ( & V_11 -> V_217 . V_218 ) ;
if ( V_70 )
return V_70 ;
V_206 = F_401 ( V_11 , V_206 ) ;
V_850 = V_11 -> V_217 . V_222 ;
V_851 = V_11 -> V_217 . V_223 ;
if ( V_206 < V_851 ||
V_206 > V_850 || V_206 > V_11 -> V_217 . V_432 ) {
F_47 ( & V_11 -> V_217 . V_218 ) ;
return - V_592 ;
}
V_11 -> V_217 . V_431 = V_206 ;
if ( F_402 ( V_11 , V_206 ) )
F_114 ( L_534 ) ;
F_47 ( & V_11 -> V_217 . V_218 ) ;
return 0 ;
}
static int
F_405 ( void * V_10 , T_3 * V_206 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_852 ;
if ( ! ( F_130 ( V_11 ) || F_131 ( V_11 ) ) )
return - V_406 ;
F_83 ( V_11 ) ;
V_852 = F_85 ( V_853 ) ;
F_102 ( V_11 ) ;
* V_206 = ( V_852 & V_854 ) >> V_855 ;
return 0 ;
}
static int
F_406 ( void * V_10 , T_3 V_206 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_852 ;
if ( ! ( F_130 ( V_11 ) || F_131 ( V_11 ) ) )
return - V_406 ;
if ( V_206 > 3 )
return - V_592 ;
F_83 ( V_11 ) ;
F_114 ( L_536 , V_206 ) ;
V_852 = F_85 ( V_853 ) ;
V_852 &= ~ V_854 ;
V_852 |= ( V_206 << V_855 ) ;
F_174 ( V_853 , V_852 ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static void F_407 ( struct V_1 * V_11 ,
struct V_856 * V_857 )
{
int V_858 = 2 ;
int V_859 ;
T_4 V_860 [ V_858 ] , V_861 [ V_858 ] ;
V_860 [ 0 ] = F_85 ( V_862 ) ;
V_860 [ 1 ] = F_85 ( V_863 ) ;
V_861 [ 0 ] = F_85 ( V_864 ) ;
V_861 [ 1 ] = F_85 ( V_865 ) ;
for ( V_859 = 0 ; V_859 < V_858 ; V_859 ++ ) {
unsigned int V_866 ;
if ( V_860 [ V_859 ] & V_867 )
continue;
V_857 -> V_868 = F_408 ( 0 ) ;
V_857 -> V_869 |= F_408 ( V_859 ) ;
V_866 = ( ( V_860 [ V_859 ] & V_870 ) ? 0 : 2 ) +
( ( V_860 [ V_859 ] & V_871 ) ? 0 : 2 ) +
( ( V_860 [ V_859 ] & V_872 ) ? 0 : 2 ) +
( ( V_861 [ V_859 ] & V_873 ) ? 0 : 2 ) ;
V_857 -> V_874 += V_866 ;
V_857 -> V_875 = F_409 (unsigned int,
sseu->eu_per_subslice, eu_cnt) ;
}
}
static void F_410 ( struct V_1 * V_11 ,
struct V_856 * V_857 )
{
int V_876 = 3 , V_858 = 4 ;
int V_877 , V_859 ;
T_4 V_878 [ V_876 ] , V_879 [ 2 * V_876 ] , V_880 [ 2 ] ;
if ( F_125 ( V_11 ) ) {
V_876 = 1 ;
V_858 = 3 ;
}
for ( V_877 = 0 ; V_877 < V_876 ; V_877 ++ ) {
V_878 [ V_877 ] = F_85 ( F_411 ( V_877 ) ) ;
V_879 [ 2 * V_877 ] = F_85 ( F_412 ( V_877 ) ) ;
V_879 [ 2 * V_877 + 1 ] = F_85 ( F_413 ( V_877 ) ) ;
}
V_880 [ 0 ] = V_881 |
V_882 |
V_883 |
V_884 ;
V_880 [ 1 ] = V_885 |
V_886 |
V_887 |
V_888 ;
for ( V_877 = 0 ; V_877 < V_876 ; V_877 ++ ) {
if ( ( V_878 [ V_877 ] & V_889 ) == 0 )
continue;
V_857 -> V_868 |= F_408 ( V_877 ) ;
if ( F_134 ( V_11 ) || F_135 ( V_11 ) )
V_857 -> V_869 =
F_9 ( V_11 ) -> V_857 . V_869 ;
for ( V_859 = 0 ; V_859 < V_858 ; V_859 ++ ) {
unsigned int V_866 ;
if ( F_125 ( V_11 ) ) {
if ( ! ( V_878 [ V_877 ] & ( F_414 ( V_859 ) ) ) )
continue;
V_857 -> V_869 |= F_408 ( V_859 ) ;
}
V_866 = 2 * F_415 ( V_879 [ 2 * V_877 + V_859 / 2 ] &
V_880 [ V_859 % 2 ] ) ;
V_857 -> V_874 += V_866 ;
V_857 -> V_875 = F_409 (unsigned int,
sseu->eu_per_subslice,
eu_cnt) ;
}
}
}
static void F_416 ( struct V_1 * V_11 ,
struct V_856 * V_857 )
{
T_4 V_890 = F_85 ( V_891 ) ;
int V_877 ;
V_857 -> V_868 = V_890 & V_892 ;
if ( V_857 -> V_868 ) {
V_857 -> V_869 = F_9 ( V_11 ) -> V_857 . V_869 ;
V_857 -> V_875 =
F_9 ( V_11 ) -> V_857 . V_875 ;
V_857 -> V_874 = V_857 -> V_875 *
F_417 ( V_857 ) ;
for ( V_877 = 0 ; V_877 < F_418 ( V_857 -> V_868 ) ; V_877 ++ ) {
T_12 V_893 =
F_9 ( V_11 ) -> V_857 . V_893 [ V_877 ] ;
V_857 -> V_874 -= F_419 ( V_893 ) ;
}
}
}
static void F_420 ( struct V_6 * V_7 , bool V_894 ,
const struct V_856 * V_857 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const char * type = V_894 ? L_537 : L_538 ;
F_5 ( V_7 , L_539 , type ,
V_857 -> V_868 ) ;
F_5 ( V_7 , L_540 , type ,
F_419 ( V_857 -> V_868 ) ) ;
F_5 ( V_7 , L_541 , type ,
F_417 ( V_857 ) ) ;
F_5 ( V_7 , L_542 , type ,
V_857 -> V_869 ) ;
F_5 ( V_7 , L_543 , type ,
F_419 ( V_857 -> V_869 ) ) ;
F_5 ( V_7 , L_544 , type ,
V_857 -> V_874 ) ;
F_5 ( V_7 , L_545 , type ,
V_857 -> V_875 ) ;
if ( ! V_894 )
return;
F_5 ( V_7 , L_546 , F_6 ( F_421 ( V_11 ) ) ) ;
if ( F_421 ( V_11 ) )
F_5 ( V_7 , L_547 , V_857 -> V_895 ) ;
F_5 ( V_7 , L_548 ,
F_6 ( V_857 -> V_896 ) ) ;
F_5 ( V_7 , L_549 ,
F_6 ( V_857 -> V_897 ) ) ;
F_5 ( V_7 , L_550 ,
F_6 ( V_857 -> V_898 ) ) ;
}
static int F_422 ( struct V_6 * V_7 , void * V_207 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_856 V_857 ;
if ( F_10 ( V_11 ) < 8 )
return - V_406 ;
F_35 ( V_7 , L_551 ) ;
F_420 ( V_7 , true , & F_9 ( V_11 ) -> V_857 ) ;
F_35 ( V_7 , L_552 ) ;
memset ( & V_857 , 0 , sizeof( V_857 ) ) ;
F_83 ( V_11 ) ;
if ( F_84 ( V_11 ) ) {
F_407 ( V_11 , & V_857 ) ;
} else if ( F_128 ( V_11 ) ) {
F_416 ( V_11 , & V_857 ) ;
} else if ( F_10 ( V_11 ) >= 9 ) {
F_410 ( V_11 , & V_857 ) ;
}
F_102 ( V_11 ) ;
F_420 ( V_7 , false , & V_857 ) ;
return 0 ;
}
static int F_423 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
if ( F_10 ( V_11 ) < 6 )
return 0 ;
F_83 ( V_11 ) ;
F_126 ( V_11 , V_251 ) ;
return 0 ;
}
static int F_424 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_200 -> V_201 ;
if ( F_10 ( V_11 ) < 6 )
return 0 ;
F_129 ( V_11 , V_251 ) ;
F_102 ( V_11 ) ;
return 0 ;
}
static int F_425 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_899 * V_900 = & V_11 -> V_900 ;
F_5 ( V_7 , L_553 , V_900 -> V_901 ) ;
F_5 ( V_7 , L_554 ,
F_6 ( F_144 ( & V_900 -> V_902 ) ) ) ;
return 0 ;
}
static T_5 F_426 ( struct V_86 * V_86 ,
const char T_6 * V_190 , T_7 V_810 ,
T_8 * V_811 )
{
struct V_6 * V_7 = V_86 -> V_193 ;
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_899 * V_900 = & V_11 -> V_900 ;
unsigned int V_903 ;
int V_150 ;
char * V_904 ;
char V_196 [ 16 ] ;
if ( V_810 >= sizeof( V_196 ) )
return - V_592 ;
if ( F_373 ( V_196 , V_190 , V_810 ) )
return - V_830 ;
V_196 [ V_810 ] = '\0' ;
V_904 = strchr ( V_196 , '\n' ) ;
if ( V_904 )
* V_904 = '\0' ;
if ( strcmp ( V_196 , L_555 ) == 0 )
V_903 = V_905 ;
else if ( F_427 ( V_196 , 10 , & V_903 ) != 0 )
return - V_592 ;
if ( V_903 > 0 )
F_428 ( L_556 ,
V_903 ) ;
else
F_428 ( L_557 ) ;
F_75 ( & V_11 -> V_906 ) ;
V_900 -> V_901 = V_903 ;
F_429 (i)
V_900 -> V_77 [ V_150 ] . V_68 = 0 ;
F_80 ( & V_11 -> V_906 ) ;
F_385 ( & V_11 -> V_900 . V_902 ) ;
return V_810 ;
}
static int F_430 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
return F_358 ( V_86 , F_425 , V_200 -> V_201 ) ;
}
int F_431 ( struct V_1 * V_11 )
{
struct V_907 * V_4 = V_11 -> V_63 . V_675 ;
struct V_908 * V_909 ;
int V_70 , V_150 ;
V_909 = F_432 ( L_558 , V_910 ,
V_4 -> V_911 , F_2 ( V_4 -> V_5 ) ,
& V_912 ) ;
if ( ! V_909 )
return - V_73 ;
V_70 = F_433 ( V_4 ) ;
if ( V_70 )
return V_70 ;
for ( V_150 = 0 ; V_150 < F_54 ( V_913 ) ; V_150 ++ ) {
V_909 = F_432 ( V_913 [ V_150 ] . V_8 ,
V_914 | V_915 ,
V_4 -> V_911 ,
F_2 ( V_4 -> V_5 ) ,
V_913 [ V_150 ] . V_916 ) ;
if ( ! V_909 )
return - V_73 ;
}
return F_434 ( V_917 ,
V_918 ,
V_4 -> V_911 , V_4 ) ;
}
static int F_435 ( struct V_6 * V_7 , void * V_10 )
{
struct V_670 * V_620 = V_7 -> V_12 ;
struct V_623 * V_623 =
F_264 ( & F_347 ( V_620 ) -> V_29 ) ;
T_14 V_198 [ 16 ] ;
T_5 V_388 ;
int V_150 ;
if ( V_620 -> V_671 != V_672 )
return - V_406 ;
for ( V_150 = 0 ; V_150 < F_54 ( V_919 ) ; V_150 ++ ) {
const struct V_920 * V_61 = & V_919 [ V_150 ] ;
T_7 V_26 = V_61 -> V_794 ? V_61 -> V_794 - V_61 -> V_46 + 1 : ( V_61 -> V_26 ? : 1 ) ;
if ( V_61 -> V_921 &&
V_620 -> V_628 != V_629 )
continue;
if ( F_436 ( V_26 > sizeof( V_198 ) ) )
continue;
V_388 = F_437 ( & V_623 -> V_685 , V_61 -> V_46 , V_198 , V_26 ) ;
if ( V_388 <= 0 ) {
F_438 ( L_559 ,
V_26 , V_61 -> V_46 , V_388 ) ;
continue;
}
F_5 ( V_7 , L_560 , V_61 -> V_46 , ( int ) V_26 , V_198 ) ;
}
return 0 ;
}
static int F_439 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
return F_358 ( V_86 , F_435 , V_200 -> V_201 ) ;
}
static int F_440 ( struct V_6 * V_7 , void * V_10 )
{
struct V_670 * V_620 = V_7 -> V_12 ;
struct V_623 * V_623 =
F_264 ( & F_347 ( V_620 ) -> V_29 ) ;
if ( V_620 -> V_671 != V_672 )
return - V_406 ;
F_5 ( V_7 , L_561 ,
V_623 -> V_922 ) ;
F_5 ( V_7 , L_562 ,
V_623 -> V_923 ) ;
F_5 ( V_7 , L_563 ,
V_623 -> V_924 ) ;
F_5 ( V_7 , L_564 ,
V_623 -> V_925 ) ;
return 0 ;
}
static int F_441 ( struct V_200 * V_200 , struct V_86 * V_86 )
{
return F_358 ( V_86 , F_440 , V_200 -> V_201 ) ;
}
int F_442 ( struct V_670 * V_620 )
{
struct V_908 * V_926 = V_620 -> V_927 ;
if ( ! V_926 )
return - V_406 ;
if ( V_620 -> V_628 == V_699 ||
V_620 -> V_628 == V_629 )
F_432 ( L_565 , V_914 , V_926 ,
V_620 , & V_928 ) ;
if ( V_620 -> V_628 == V_629 )
F_432 ( L_566 , V_914 , V_926 ,
V_620 , & V_929 ) ;
return 0 ;
}
