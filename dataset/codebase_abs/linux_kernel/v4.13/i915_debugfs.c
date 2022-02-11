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
struct V_128 * V_129 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_70 (dev, crtc) {
const char V_130 = F_71 ( V_129 -> V_130 ) ;
const char V_50 = F_72 ( V_129 -> V_50 ) ;
struct V_131 * V_132 ;
F_73 ( & V_5 -> V_133 ) ;
V_132 = V_129 -> V_134 ;
if ( V_132 == NULL ) {
F_5 ( V_7 , L_44 ,
V_130 , V_50 ) ;
} else {
T_4 V_135 ;
T_4 V_136 ;
V_135 = F_39 ( & V_132 -> V_135 ) ;
if ( V_135 ) {
F_5 ( V_7 , L_45 ,
V_130 , V_50 ) ;
} else {
F_5 ( V_7 , L_46 ,
V_130 , V_50 ) ;
}
if ( V_132 -> V_137 ) {
struct V_30 * V_31 = V_132 -> V_137 -> V_31 ;
F_5 ( V_7 , L_47 ,
V_31 -> V_8 ,
V_132 -> V_137 -> V_138 ,
F_74 ( V_31 ) ,
F_75 ( V_31 ) ,
F_76 ( V_132 -> V_137 ) ) ;
} else
F_5 ( V_7 , L_48 ) ;
F_5 ( V_7 , L_49 ,
V_132 -> V_139 ,
V_132 -> V_140 ,
F_77 ( V_129 ) ) ;
F_5 ( V_7 , L_50 , F_39 ( & V_132 -> V_135 ) ) ;
if ( F_10 ( V_11 ) >= 4 )
V_136 = F_78 ( F_79 ( F_80 ( V_129 -> V_50 ) ) ) ;
else
V_136 = F_79 ( F_81 ( V_129 -> V_50 ) ) ;
F_5 ( V_7 , L_51 , V_136 ) ;
if ( V_132 -> V_141 ) {
F_5 ( V_7 , L_52 , ( long ) V_132 -> V_142 ) ;
F_5 ( V_7 , L_53 , V_136 == V_132 -> V_142 ) ;
}
}
F_82 ( & V_5 -> V_133 ) ;
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
F_5 ( V_7 , L_54 ,
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
F_5 ( V_7 , L_55 , V_67 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_84 ( struct V_6 * V_7 ,
struct V_115 * V_143 ,
const char * V_144 )
{
F_5 ( V_7 , L_56 , V_144 ,
V_143 -> V_138 , V_143 -> V_95 -> V_145 , V_143 -> V_54 . V_146 ,
V_143 -> V_147 . V_148 ,
F_85 ( V_149 - V_143 -> V_150 ) ,
V_143 -> V_151 -> V_152 -> V_8 ) ;
}
static int F_86 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_115 * V_153 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_70 , V_154 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_154 = 0 ;
F_53 (engine, dev_priv, id) {
int V_68 ;
V_68 = 0 ;
F_28 (req, &engine->timeline->requests, link)
V_68 ++ ;
if ( V_68 == 0 )
continue;
F_5 ( V_7 , L_57 , V_31 -> V_8 , V_68 ) ;
F_28 (req, &engine->timeline->requests, link)
F_84 ( V_7 , V_153 , L_58 ) ;
V_154 ++ ;
}
F_47 ( & V_5 -> V_34 ) ;
if ( V_154 == 0 )
F_35 ( V_7 , L_59 ) ;
return 0 ;
}
static void F_87 ( struct V_6 * V_7 ,
struct V_30 * V_31 )
{
struct V_155 * V_61 = & V_31 -> V_156 ;
struct V_157 * V_158 ;
F_5 ( V_7 , L_60 ,
V_31 -> V_8 , F_75 ( V_31 ) ) ;
F_73 ( & V_61 -> V_159 ) ;
for ( V_158 = F_88 ( & V_61 -> V_160 ) ; V_158 ; V_158 = F_89 ( V_158 ) ) {
struct V_161 * V_162 = F_90 ( V_158 , F_91 ( * V_162 ) , V_3 ) ;
F_5 ( V_7 , L_61 ,
V_31 -> V_8 , V_162 -> V_163 -> V_125 , V_162 -> V_163 -> V_123 , V_162 -> V_146 ) ;
}
F_82 ( & V_61 -> V_159 ) ;
}
static int F_92 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
F_53 (engine, dev_priv, id)
F_87 ( V_7 , V_31 ) ;
return 0 ;
}
static int F_93 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_164 , V_130 ;
F_94 ( V_11 ) ;
if ( F_95 ( V_11 ) ) {
F_5 ( V_7 , L_62 ,
F_79 ( V_165 ) ) ;
F_5 ( V_7 , L_63 ,
F_79 ( V_166 ) ) ;
F_5 ( V_7 , L_64 ,
F_79 ( V_167 ) ) ;
F_5 ( V_7 , L_65 ,
F_79 ( V_168 ) ) ;
F_5 ( V_7 , L_66 ,
F_79 ( V_169 ) ) ;
F_96 (dev_priv, pipe) {
enum V_170 V_171 ;
V_171 = F_97 ( V_130 ) ;
if ( ! F_98 ( V_11 ,
V_171 ) ) {
F_5 ( V_7 , L_67 ,
F_71 ( V_130 ) ) ;
continue;
}
F_5 ( V_7 , L_68 ,
F_71 ( V_130 ) ,
F_79 ( F_99 ( V_130 ) ) ) ;
F_100 ( V_11 , V_171 ) ;
}
F_101 ( V_11 , V_172 ) ;
F_5 ( V_7 , L_69 ,
F_79 ( V_173 ) ) ;
F_5 ( V_7 , L_70 ,
F_79 ( V_174 ) ) ;
F_5 ( V_7 , L_71 ,
F_79 ( V_175 ) ) ;
F_100 ( V_11 , V_172 ) ;
for ( V_164 = 0 ; V_164 < 4 ; V_164 ++ ) {
F_5 ( V_7 , L_72 ,
V_164 , F_79 ( F_102 ( V_164 ) ) ) ;
F_5 ( V_7 , L_73 ,
V_164 , F_79 ( F_103 ( V_164 ) ) ) ;
F_5 ( V_7 , L_74 ,
V_164 , F_79 ( F_104 ( V_164 ) ) ) ;
}
F_5 ( V_7 , L_75 ,
F_79 ( V_176 ) ) ;
F_5 ( V_7 , L_76 ,
F_79 ( V_177 ) ) ;
F_5 ( V_7 , L_77 ,
F_79 ( V_178 ) ) ;
} else if ( F_10 ( V_11 ) >= 8 ) {
F_5 ( V_7 , L_62 ,
F_79 ( V_165 ) ) ;
for ( V_164 = 0 ; V_164 < 4 ; V_164 ++ ) {
F_5 ( V_7 , L_72 ,
V_164 , F_79 ( F_102 ( V_164 ) ) ) ;
F_5 ( V_7 , L_73 ,
V_164 , F_79 ( F_103 ( V_164 ) ) ) ;
F_5 ( V_7 , L_74 ,
V_164 , F_79 ( F_104 ( V_164 ) ) ) ;
}
F_96 (dev_priv, pipe) {
enum V_170 V_171 ;
V_171 = F_97 ( V_130 ) ;
if ( ! F_98 ( V_11 ,
V_171 ) ) {
F_5 ( V_7 , L_67 ,
F_71 ( V_130 ) ) ;
continue;
}
F_5 ( V_7 , L_78 ,
F_71 ( V_130 ) ,
F_79 ( F_105 ( V_130 ) ) ) ;
F_5 ( V_7 , L_79 ,
F_71 ( V_130 ) ,
F_79 ( F_106 ( V_130 ) ) ) ;
F_5 ( V_7 , L_80 ,
F_71 ( V_130 ) ,
F_79 ( F_107 ( V_130 ) ) ) ;
F_100 ( V_11 , V_171 ) ;
}
F_5 ( V_7 , L_81 ,
F_79 ( V_179 ) ) ;
F_5 ( V_7 , L_82 ,
F_79 ( V_180 ) ) ;
F_5 ( V_7 , L_83 ,
F_79 ( V_181 ) ) ;
F_5 ( V_7 , L_84 ,
F_79 ( V_182 ) ) ;
F_5 ( V_7 , L_85 ,
F_79 ( V_183 ) ) ;
F_5 ( V_7 , L_86 ,
F_79 ( V_184 ) ) ;
F_5 ( V_7 , L_75 ,
F_79 ( V_176 ) ) ;
F_5 ( V_7 , L_76 ,
F_79 ( V_177 ) ) ;
F_5 ( V_7 , L_77 ,
F_79 ( V_178 ) ) ;
} else if ( F_108 ( V_11 ) ) {
F_5 ( V_7 , L_63 ,
F_79 ( V_166 ) ) ;
F_5 ( V_7 , L_64 ,
F_79 ( V_167 ) ) ;
F_5 ( V_7 , L_65 ,
F_79 ( V_168 ) ) ;
F_5 ( V_7 , L_66 ,
F_79 ( V_169 ) ) ;
F_96 (dev_priv, pipe) {
enum V_170 V_171 ;
V_171 = F_97 ( V_130 ) ;
if ( ! F_98 ( V_11 ,
V_171 ) ) {
F_5 ( V_7 , L_67 ,
F_71 ( V_130 ) ) ;
continue;
}
F_5 ( V_7 , L_68 ,
F_71 ( V_130 ) ,
F_79 ( F_99 ( V_130 ) ) ) ;
F_100 ( V_11 , V_171 ) ;
}
F_5 ( V_7 , L_87 ,
F_79 ( V_185 ) ) ;
F_5 ( V_7 , L_88 ,
F_79 ( V_186 ) ) ;
F_5 ( V_7 , L_89 ,
F_79 ( V_187 ) ) ;
F_5 ( V_7 , L_90 ,
F_79 ( V_188 ) ) ;
F_5 ( V_7 , L_91 ,
F_79 ( V_189 ) ) ;
F_5 ( V_7 , L_92 ,
F_79 ( V_190 ) ) ;
F_5 ( V_7 , L_93 ,
F_79 ( V_191 ) ) ;
F_5 ( V_7 , L_69 ,
F_79 ( V_173 ) ) ;
F_5 ( V_7 , L_70 ,
F_79 ( V_174 ) ) ;
F_5 ( V_7 , L_71 ,
F_79 ( V_175 ) ) ;
} else if ( ! F_109 ( V_11 ) ) {
F_5 ( V_7 , L_94 ,
F_79 ( V_192 ) ) ;
F_5 ( V_7 , L_95 ,
F_79 ( V_193 ) ) ;
F_5 ( V_7 , L_96 ,
F_79 ( V_194 ) ) ;
F_96 (dev_priv, pipe)
F_5 ( V_7 , L_97 ,
F_71 ( V_130 ) ,
F_79 ( F_99 ( V_130 ) ) ) ;
} else {
F_5 ( V_7 , L_98 ,
F_79 ( V_195 ) ) ;
F_5 ( V_7 , L_99 ,
F_79 ( V_196 ) ) ;
F_5 ( V_7 , L_100 ,
F_79 ( V_197 ) ) ;
F_5 ( V_7 , L_101 ,
F_79 ( V_198 ) ) ;
F_5 ( V_7 , L_102 ,
F_79 ( V_199 ) ) ;
F_5 ( V_7 , L_103 ,
F_79 ( V_200 ) ) ;
F_5 ( V_7 , L_104 ,
F_79 ( V_186 ) ) ;
F_5 ( V_7 , L_105 ,
F_79 ( V_187 ) ) ;
F_5 ( V_7 , L_106 ,
F_79 ( V_188 ) ) ;
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
int V_164 , V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_5 ( V_7 , L_108 , V_11 -> V_201 ) ;
for ( V_164 = 0 ; V_164 < V_11 -> V_201 ; V_164 ++ ) {
struct V_27 * V_28 = V_11 -> V_202 [ V_164 ] . V_28 ;
F_5 ( V_7 , L_109 ,
V_164 , V_11 -> V_202 [ V_164 ] . V_33 ) ;
if ( ! V_28 )
F_35 ( V_7 , L_110 ) ;
else
F_31 ( V_7 , V_28 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static T_5 F_113 ( struct V_86 * V_86 , char T_6 * V_203 ,
T_7 V_68 , T_8 * V_204 )
{
struct V_205 * error = V_86 -> V_206 ;
struct V_207 V_208 ;
T_5 V_70 ;
T_8 V_209 ;
if ( ! error )
return 0 ;
V_70 = F_114 ( & V_208 , error -> V_210 , V_68 , * V_204 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_115 ( & V_208 , error ) ;
if ( V_70 )
goto V_74;
V_209 = 0 ;
V_70 = F_116 ( V_203 , V_68 , & V_209 , V_208 . V_211 , V_208 . V_212 ) ;
if ( V_70 < 0 )
goto V_74;
* V_204 = V_208 . V_41 + V_70 ;
V_74:
F_117 ( & V_208 ) ;
return V_70 ;
}
static int F_118 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
F_119 ( V_86 -> V_206 ) ;
return 0 ;
}
static int F_120 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
struct V_1 * V_210 = V_213 -> V_214 ;
struct V_205 * V_215 ;
F_94 ( V_210 ) ;
V_215 = F_121 ( V_210 ) ;
F_111 ( V_210 ) ;
if ( ! V_215 )
return - V_73 ;
V_86 -> V_206 = V_215 ;
return 0 ;
}
static T_5
F_122 ( struct V_86 * V_216 ,
const char T_6 * V_203 ,
T_7 V_217 ,
T_8 * V_218 )
{
struct V_205 * error = V_216 -> V_206 ;
if ( ! error )
return 0 ;
F_123 ( L_111 ) ;
F_124 ( error -> V_210 ) ;
return V_217 ;
}
static int F_125 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
V_86 -> V_206 = F_126 ( V_213 -> V_214 ) ;
return 0 ;
}
static int
F_127 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_11 = V_10 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_128 ( V_5 , V_219 ) ;
F_47 ( & V_5 -> V_34 ) ;
return V_70 ;
}
static int F_129 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_70 = 0 ;
F_94 ( V_11 ) ;
if ( F_130 ( V_11 ) ) {
T_9 V_221 = F_131 ( V_222 ) ;
T_9 V_223 = F_131 ( V_224 ) ;
F_5 ( V_7 , L_112 , ( V_221 >> 8 ) & 0xf ) ;
F_5 ( V_7 , L_113 , V_221 & 0x3f ) ;
F_5 ( V_7 , L_114 , ( V_223 & V_225 ) >>
V_226 ) ;
F_5 ( V_7 , L_115 ,
( V_223 & V_227 ) >> V_228 ) ;
} else if ( F_108 ( V_11 ) || F_95 ( V_11 ) ) {
T_4 V_229 ;
F_58 ( & V_11 -> V_230 . V_231 ) ;
V_229 = F_132 ( V_11 , V_232 ) ;
F_5 ( V_7 , L_116 , V_229 ) ;
F_5 ( V_7 , L_117 , V_11 -> V_233 ) ;
F_5 ( V_7 , L_118 ,
F_133 ( V_11 , ( V_229 >> 8 ) & 0xff ) ) ;
F_5 ( V_7 , L_119 ,
F_133 ( V_11 , V_11 -> V_230 . V_234 ) ) ;
F_5 ( V_7 , L_120 ,
F_133 ( V_11 , V_11 -> V_230 . V_235 ) ) ;
F_5 ( V_7 , L_121 ,
F_133 ( V_11 , V_11 -> V_230 . V_236 ) ) ;
F_5 ( V_7 , L_122 ,
F_133 ( V_11 , V_11 -> V_230 . V_237 ) ) ;
F_5 ( V_7 ,
L_123 ,
F_133 ( V_11 , V_11 -> V_230 . V_238 ) ) ;
F_47 ( & V_11 -> V_230 . V_231 ) ;
} else if ( F_10 ( V_11 ) >= 6 ) {
T_4 V_239 ;
T_4 V_240 ;
T_4 V_241 ;
T_4 V_242 , V_243 , V_244 ;
T_4 V_245 , V_246 , V_247 ;
T_4 V_248 , V_249 , V_250 ;
T_4 V_251 , V_252 , V_253 ;
T_4 V_254 , V_255 , V_256 , V_257 , V_258 ;
int V_235 ;
V_239 = F_79 ( V_259 ) ;
if ( F_134 ( V_11 ) ) {
V_241 = F_79 ( V_260 ) ;
V_240 = F_79 ( V_261 ) ;
} else {
V_241 = F_79 ( V_262 ) ;
V_240 = F_79 ( V_263 ) ;
}
F_135 ( V_11 , V_264 ) ;
V_247 = F_79 ( V_265 ) ;
if ( F_136 ( V_11 ) )
V_247 >>= 23 ;
else {
V_247 &= ~ V_266 ;
if ( F_137 ( V_11 ) || F_138 ( V_11 ) )
V_247 >>= 24 ;
else
V_247 >>= 25 ;
}
V_247 = F_133 ( V_11 , V_247 ) ;
V_242 = F_79 ( V_267 ) ;
V_243 = F_79 ( V_268 ) ;
V_244 = F_79 ( V_269 ) ;
V_245 = F_79 ( V_270 ) ;
V_248 = F_79 ( V_271 ) & V_272 ;
V_249 = F_79 ( V_273 ) & V_274 ;
V_250 = F_79 ( V_275 ) & V_274 ;
V_251 = F_79 ( V_276 ) & V_277 ;
V_252 = F_79 ( V_278 ) & V_274 ;
V_253 = F_79 ( V_279 ) & V_274 ;
if ( F_136 ( V_11 ) )
V_246 = ( V_245 & V_280 ) >> V_281 ;
else if ( F_137 ( V_11 ) || F_138 ( V_11 ) )
V_246 = ( V_245 & V_282 ) >> V_283 ;
else
V_246 = ( V_245 & V_284 ) >> V_285 ;
V_246 = F_133 ( V_11 , V_246 ) ;
F_139 ( V_11 , V_264 ) ;
if ( F_140 ( V_11 ) || F_141 ( V_11 ) ) {
V_254 = F_79 ( V_189 ) ;
V_255 = F_79 ( V_191 ) ;
V_256 = F_79 ( V_286 ) ;
V_257 = F_79 ( V_190 ) ;
V_258 = F_79 ( V_287 ) ;
} else {
V_254 = F_79 ( F_104 ( 2 ) ) ;
V_255 = F_79 ( F_102 ( 2 ) ) ;
V_256 = F_79 ( F_142 ( 2 ) ) ;
V_257 = F_79 ( F_103 ( 2 ) ) ;
V_258 = F_79 ( V_287 ) ;
}
F_5 ( V_7 , L_124 ,
V_254 , V_255 , V_256 , V_257 , V_258 ) ;
F_5 ( V_7 , L_125 ,
V_11 -> V_230 . V_288 ) ;
F_5 ( V_7 , L_126 , V_240 ) ;
F_5 ( V_7 , L_127 ,
( V_240 & ( F_136 ( V_11 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_5 ( V_7 , L_128 ,
V_240 & 0xff ) ;
F_5 ( V_7 , L_129 ,
V_239 & 0xff ) ;
F_5 ( V_7 , L_130 , V_245 ) ;
F_5 ( V_7 , L_131 , V_242 ) ;
F_5 ( V_7 , L_132 , V_243 ) ;
F_5 ( V_7 , L_133 , V_244 ) ;
F_5 ( V_7 , L_134 , V_247 ) ;
F_5 ( V_7 , L_135 , V_246 ) ;
F_5 ( V_7 , L_136 ,
V_248 , F_143 ( V_11 , V_248 ) ) ;
F_5 ( V_7 , L_137 ,
V_249 , F_143 ( V_11 , V_249 ) ) ;
F_5 ( V_7 , L_138 ,
V_250 , F_143 ( V_11 , V_250 ) ) ;
F_5 ( V_7 , L_139 ,
V_11 -> V_230 . V_289 ) ;
F_5 ( V_7 , L_140 ,
V_251 , F_143 ( V_11 , V_251 ) ) ;
F_5 ( V_7 , L_141 ,
V_252 , F_143 ( V_11 , V_252 ) ) ;
F_5 ( V_7 , L_142 ,
V_253 , F_143 ( V_11 , V_253 ) ) ;
F_5 ( V_7 , L_143 ,
V_11 -> V_230 . V_290 ) ;
V_235 = ( F_134 ( V_11 ) ? V_241 >> 0 :
V_241 >> 16 ) & 0xff ;
V_235 *= ( F_144 ( V_11 ) ? V_291 : 1 ) ;
F_5 ( V_7 , L_144 ,
F_133 ( V_11 , V_235 ) ) ;
V_235 = ( V_241 & 0xff00 ) >> 8 ;
V_235 *= ( F_144 ( V_11 ) ? V_291 : 1 ) ;
F_5 ( V_7 , L_145 ,
F_133 ( V_11 , V_235 ) ) ;
V_235 = ( F_134 ( V_11 ) ? V_241 >> 16 :
V_241 >> 0 ) & 0xff ;
V_235 *= ( F_144 ( V_11 ) ? V_291 : 1 ) ;
F_5 ( V_7 , L_146 ,
F_133 ( V_11 , V_235 ) ) ;
F_5 ( V_7 , L_147 ,
F_133 ( V_11 , V_11 -> V_230 . V_235 ) ) ;
F_5 ( V_7 , L_148 ,
F_133 ( V_11 , V_11 -> V_230 . V_234 ) ) ;
F_5 ( V_7 , L_149 , V_246 ) ;
F_5 ( V_7 , L_150 ,
F_133 ( V_11 , V_11 -> V_230 . V_237 ) ) ;
F_5 ( V_7 , L_151 ,
F_133 ( V_11 , V_11 -> V_230 . V_236 ) ) ;
F_5 ( V_7 , L_152 ,
F_133 ( V_11 , V_11 -> V_230 . V_292 ) ) ;
F_5 ( V_7 , L_153 ,
F_133 ( V_11 , V_11 -> V_230 . V_235 ) ) ;
F_5 ( V_7 ,
L_123 ,
F_133 ( V_11 , V_11 -> V_230 . V_238 ) ) ;
} else {
F_35 ( V_7 , L_154 ) ;
}
F_5 ( V_7 , L_155 , V_11 -> V_293 . V_294 . V_293 ) ;
F_5 ( V_7 , L_156 , V_11 -> V_295 ) ;
F_5 ( V_7 , L_157 , V_11 -> V_296 ) ;
F_111 ( V_11 ) ;
return V_70 ;
}
static void F_145 ( struct V_1 * V_11 ,
struct V_6 * V_7 ,
struct V_297 * V_298 )
{
int V_299 ;
int V_300 ;
F_5 ( V_7 , L_158 ,
V_298 -> V_298 ) ;
if ( F_10 ( V_11 ) <= 3 )
return;
F_5 ( V_7 , L_159 ,
V_298 -> V_301 ) ;
if ( F_10 ( V_11 ) <= 6 )
return;
F_146 (dev_priv, slice, subslice)
F_5 ( V_7 , L_160 ,
V_299 , V_300 , V_298 -> V_302 [ V_299 ] [ V_300 ] ) ;
F_146 (dev_priv, slice, subslice)
F_5 ( V_7 , L_161 ,
V_299 , V_300 , V_298 -> V_303 [ V_299 ] [ V_300 ] ) ;
}
static int F_147 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
T_3 V_304 [ V_305 ] ;
T_4 V_146 [ V_305 ] ;
struct V_297 V_298 ;
enum V_90 V_55 ;
if ( F_148 ( V_306 , & V_11 -> V_307 . V_308 ) )
F_35 ( V_7 , L_162 ) ;
if ( F_148 ( V_309 , & V_11 -> V_307 . V_308 ) )
F_35 ( V_7 , L_163 ) ;
if ( F_148 ( V_310 , & V_11 -> V_307 . V_308 ) )
F_35 ( V_7 , L_164 ) ;
if ( F_149 ( & V_11 -> V_307 . V_311 ) )
F_35 ( V_7 , L_165 ) ;
if ( F_149 ( & V_11 -> V_307 . V_312 ) )
F_35 ( V_7 , L_166 ) ;
if ( ! V_210 . V_313 ) {
F_35 ( V_7 , L_167 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_53 (engine, dev_priv, id) {
V_304 [ V_55 ] = F_150 ( V_31 ) ;
V_146 [ V_55 ] = F_75 ( V_31 ) ;
}
F_151 ( V_11 -> V_31 [ V_314 ] , & V_298 ) ;
F_111 ( V_11 ) ;
if ( F_152 ( & V_11 -> V_307 . V_315 . V_316 ) )
F_5 ( V_7 , L_168 ,
F_85 ( V_11 -> V_307 . V_315 . V_316 . V_317 -
V_149 ) ) ;
else if ( F_153 ( & V_11 -> V_307 . V_315 ) )
F_35 ( V_7 , L_169 ) ;
else
F_35 ( V_7 , L_170 ) ;
F_5 ( V_7 , L_171 , F_6 ( V_11 -> V_318 . V_319 ) ) ;
F_53 (engine, dev_priv, id) {
struct V_155 * V_61 = & V_31 -> V_156 ;
struct V_157 * V_158 ;
F_5 ( V_7 , L_172 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_173 ,
V_31 -> V_320 . V_146 , V_146 [ V_55 ] ,
F_74 ( V_31 ) ,
V_31 -> V_151 -> V_321 ) ;
F_5 ( V_7 , L_174 ,
F_6 ( F_154 ( V_31 ) ) ,
F_6 ( F_148 ( V_31 -> V_55 ,
& V_11 -> V_307 . V_322 ) ) ,
F_6 ( V_31 -> V_320 . V_323 ) ) ;
F_73 ( & V_61 -> V_159 ) ;
for ( V_158 = F_88 ( & V_61 -> V_160 ) ; V_158 ; V_158 = F_89 ( V_158 ) ) {
struct V_161 * V_162 = F_90 ( V_158 , F_91 ( * V_162 ) , V_3 ) ;
F_5 ( V_7 , L_175 ,
V_162 -> V_163 -> V_125 , V_162 -> V_163 -> V_123 , V_162 -> V_146 ) ;
}
F_82 ( & V_61 -> V_159 ) ;
F_5 ( V_7 , L_176 ,
( long long ) V_31 -> V_320 . V_304 ,
( long long ) V_304 [ V_55 ] ) ;
F_5 ( V_7 , L_177 ,
F_155 ( V_31 -> V_320 . V_324 ) ,
V_31 -> V_320 . V_324 ,
F_85 ( V_149 -
V_31 -> V_320 . V_325 ) ) ;
if ( V_31 -> V_55 == V_314 ) {
F_35 ( V_7 , L_178 ) ;
F_145 ( V_11 , V_7 , & V_298 ) ;
F_35 ( V_7 , L_179 ) ;
F_145 ( V_11 , V_7 ,
& V_31 -> V_320 . V_298 ) ;
}
}
return 0 ;
}
static int F_156 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_326 , V_327 ;
T_9 V_328 ;
V_326 = F_79 ( V_329 ) ;
V_327 = F_79 ( V_330 ) ;
V_328 = F_131 ( V_331 ) ;
F_5 ( V_7 , L_180 , F_6 ( V_326 & V_332 ) ) ;
F_5 ( V_7 , L_181 ,
( V_326 & V_333 ) >>
V_334 ) ;
F_5 ( V_7 , L_182 ,
F_6 ( V_326 & V_335 ) ) ;
F_5 ( V_7 , L_183 ,
F_6 ( V_326 & V_336 ) ) ;
F_5 ( V_7 , L_184 ,
F_6 ( V_326 & V_337 ) ) ;
F_5 ( V_7 , L_185 ,
( V_326 & V_338 ) >> V_339 ) ;
F_5 ( V_7 , L_186 ,
( V_326 & V_340 ) >> V_341 ) ;
F_5 ( V_7 , L_187 , ( V_326 & V_342 ) ) ;
F_5 ( V_7 , L_188 , ( V_328 & 0x3f ) ) ;
F_5 ( V_7 , L_189 , ( ( V_328 >> 8 ) & 0x3f ) ) ;
F_5 ( V_7 , L_190 ,
F_6 ( ! ( V_327 & V_343 ) ) ) ;
F_35 ( V_7 , L_191 ) ;
switch ( V_327 & V_344 ) {
case V_345 :
F_35 ( V_7 , L_192 ) ;
break;
case V_346 :
F_35 ( V_7 , L_193 ) ;
break;
case V_347 :
F_35 ( V_7 , L_194 ) ;
break;
case V_348 :
F_35 ( V_7 , L_195 ) ;
break;
case V_349 :
F_35 ( V_7 , L_196 ) ;
break;
case V_350 :
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
struct V_1 * V_210 = F_1 ( V_7 -> V_12 ) ;
struct V_351 * V_352 ;
unsigned int V_209 ;
F_158 (fw_domain, i915, tmp)
F_5 ( V_7 , L_199 ,
F_159 ( V_352 -> V_55 ) ,
F_42 ( V_352 -> V_353 ) ) ;
return 0 ;
}
static void F_160 ( struct V_6 * V_7 ,
const char * V_354 ,
const T_10 V_355 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_5 ( V_7 , L_200 ,
V_354 , F_79 ( V_355 ) ,
F_161 ( V_11 , V_355 ) ) ;
}
static int F_162 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_356 , V_357 , V_358 ;
V_358 = F_79 ( V_359 ) ;
V_356 = F_79 ( V_267 ) ;
V_357 = F_79 ( V_360 ) ;
F_5 ( V_7 , L_201 ,
F_6 ( V_356 & V_361 ) ) ;
F_5 ( V_7 , L_202 ,
F_6 ( V_356 & V_362 ) ) ;
F_5 ( V_7 , L_182 ,
F_6 ( V_356 & V_362 ) ) ;
F_5 ( V_7 , L_183 ,
F_6 ( ( V_356 & V_363 ) ==
V_364 ) ) ;
F_5 ( V_7 , L_203 ,
F_6 ( V_357 & ( V_365 |
F_163 ( 1 ) ) ) ) ;
F_5 ( V_7 , L_204 ,
( V_358 & V_366 ) ? L_205 : L_206 ) ;
F_5 ( V_7 , L_207 ,
( V_358 & V_367 ) ? L_205 : L_206 ) ;
F_160 ( V_7 , L_208 , V_368 ) ;
F_160 ( V_7 , L_209 , V_369 ) ;
return F_157 ( V_7 , NULL ) ;
}
static int F_164 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_356 , V_370 , V_357 , V_371 = 0 ;
T_4 V_372 = 0 , V_373 = 0 ;
unsigned V_374 ;
int V_68 = 0 ;
V_374 = F_42 ( V_11 -> V_375 . V_352 [ V_376 ] . V_353 ) ;
if ( V_374 ) {
F_35 ( V_7 , L_210
L_211 ) ;
} else {
while ( V_68 ++ < 50 && ( F_165 ( V_377 ) & 1 ) )
F_166 ( 10 ) ;
F_5 ( V_7 , L_212 , F_6 ( V_68 < 51 ) ) ;
}
V_370 = F_167 ( V_378 ) ;
F_168 ( false , V_378 , V_370 , 4 , true ) ;
V_356 = F_79 ( V_267 ) ;
V_357 = F_79 ( V_360 ) ;
if ( F_10 ( V_11 ) >= 9 ) {
V_372 = F_79 ( V_379 ) ;
V_373 = F_79 ( V_380 ) ;
}
F_58 ( & V_11 -> V_230 . V_231 ) ;
F_169 ( V_11 , V_381 , & V_371 ) ;
F_47 ( & V_11 -> V_230 . V_231 ) ;
F_5 ( V_7 , L_201 ,
F_6 ( V_356 & V_361 ) ) ;
F_5 ( V_7 , L_182 ,
F_6 ( V_356 & V_362 ) ) ;
F_5 ( V_7 , L_183 ,
F_6 ( ( V_356 & V_363 ) ==
V_364 ) ) ;
F_5 ( V_7 , L_213 ,
F_6 ( V_357 & V_382 ) ) ;
F_5 ( V_7 , L_203 ,
F_6 ( V_357 & V_383 ) ) ;
if ( F_10 ( V_11 ) >= 9 ) {
F_5 ( V_7 , L_214 ,
F_6 ( V_372 & V_384 ) ) ;
F_5 ( V_7 , L_215 ,
F_6 ( V_372 & V_385 ) ) ;
}
F_5 ( V_7 , L_216 ,
F_6 ( V_357 & V_386 ) ) ;
F_5 ( V_7 , L_217 ,
F_6 ( V_357 & V_387 ) ) ;
F_35 ( V_7 , L_218 ) ;
switch ( V_370 & V_388 ) {
case V_389 :
if ( V_370 & V_390 )
F_35 ( V_7 , L_219 ) ;
else
F_35 ( V_7 , L_192 ) ;
break;
case V_391 :
F_35 ( V_7 , L_220 ) ;
break;
case V_392 :
F_35 ( V_7 , L_221 ) ;
break;
case V_393 :
F_35 ( V_7 , L_222 ) ;
break;
default:
F_35 ( V_7 , L_223 ) ;
break;
}
F_5 ( V_7 , L_224 ,
F_6 ( V_370 & V_390 ) ) ;
if ( F_10 ( V_11 ) >= 9 ) {
F_5 ( V_7 , L_204 ,
( V_373 &
V_394 ) ? L_205 : L_206 ) ;
F_5 ( V_7 , L_207 ,
( V_373 &
V_395 ) ? L_205 : L_206 ) ;
}
F_160 ( V_7 , L_225 ,
V_396 ) ;
F_160 ( V_7 , L_226 , V_397 ) ;
F_160 ( V_7 , L_227 , V_398 ) ;
F_160 ( V_7 , L_228 , V_399 ) ;
F_5 ( V_7 , L_229 ,
F_170 ( ( ( V_371 >> 0 ) & 0xff ) ) ) ;
F_5 ( V_7 , L_230 ,
F_170 ( ( ( V_371 >> 8 ) & 0xff ) ) ) ;
F_5 ( V_7 , L_231 ,
F_170 ( ( ( V_371 >> 16 ) & 0xff ) ) ) ;
return F_157 ( V_7 , NULL ) ;
}
static int F_171 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_400 ;
F_94 ( V_11 ) ;
if ( F_108 ( V_11 ) || F_95 ( V_11 ) )
V_400 = F_162 ( V_7 ) ;
else if ( F_10 ( V_11 ) >= 6 )
V_400 = F_164 ( V_7 ) ;
else
V_400 = F_156 ( V_7 ) ;
F_111 ( V_11 ) ;
return V_400 ;
}
static int F_172 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_5 ( V_7 , L_232 ,
V_11 -> V_401 . V_402 ) ;
F_5 ( V_7 , L_233 ,
V_11 -> V_401 . V_403 ) ;
return 0 ;
}
static int F_173 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
if ( ! F_174 ( V_11 ) ) {
F_35 ( V_7 , L_234 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_58 ( & V_11 -> V_404 . V_405 ) ;
if ( F_175 ( V_11 ) )
F_35 ( V_7 , L_235 ) ;
else
F_5 ( V_7 , L_236 ,
V_11 -> V_404 . V_406 ) ;
if ( F_175 ( V_11 ) ) {
T_4 V_407 ;
if ( F_10 ( V_11 ) >= 8 )
V_407 = F_79 ( V_408 ) & V_409 ;
else if ( F_10 ( V_11 ) >= 7 )
V_407 = F_79 ( V_408 ) & V_410 ;
else if ( F_10 ( V_11 ) >= 5 )
V_407 = F_79 ( V_411 ) & V_412 ;
else if ( F_176 ( V_11 ) )
V_407 = F_79 ( V_413 ) & V_414 ;
else
V_407 = F_79 ( V_415 ) & ( V_416 |
V_417 ) ;
F_5 ( V_7 , L_237 , F_6 ( V_407 ) ) ;
}
F_47 ( & V_11 -> V_404 . V_405 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_177 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 7 || ! F_174 ( V_11 ) )
return - V_418 ;
* V_219 = V_11 -> V_404 . V_419 ;
return 0 ;
}
static int F_178 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_355 ;
if ( F_10 ( V_11 ) < 7 || ! F_174 ( V_11 ) )
return - V_418 ;
F_58 ( & V_11 -> V_404 . V_405 ) ;
V_355 = F_79 ( V_420 ) ;
V_11 -> V_404 . V_419 = V_219 ;
F_179 ( V_420 , V_219 ?
( V_355 | V_421 ) :
( V_355 & ~ V_421 ) ) ;
F_47 ( & V_11 -> V_404 . V_405 ) ;
return 0 ;
}
static int F_180 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
if ( ! F_181 ( V_11 ) ) {
F_35 ( V_7 , L_238 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_5 ( V_7 , L_239 ,
F_6 ( V_210 . V_422 ) ) ;
if ( F_10 ( V_11 ) >= 8 ) {
F_35 ( V_7 , L_240 ) ;
} else {
if ( F_79 ( V_423 ) & V_424 )
F_35 ( V_7 , L_241 ) ;
else
F_35 ( V_7 , L_242 ) ;
}
F_111 ( V_11 ) ;
return 0 ;
}
static int F_182 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
bool V_425 = false ;
F_94 ( V_11 ) ;
F_101 ( V_11 , V_172 ) ;
if ( F_10 ( V_11 ) >= 9 )
;
else if ( F_109 ( V_11 ) )
V_425 = F_79 ( V_426 ) & V_427 ;
else if ( F_183 ( V_11 ) || F_176 ( V_11 ) ||
F_184 ( V_11 ) || F_185 ( V_11 ) )
V_425 = F_79 ( V_428 ) & V_429 ;
else if ( F_186 ( V_11 ) )
V_425 = F_79 ( V_430 ) & V_431 ;
else if ( F_187 ( V_11 ) )
V_425 = F_79 ( V_432 ) & V_433 ;
else if ( F_108 ( V_11 ) || F_95 ( V_11 ) )
V_425 = F_79 ( V_434 ) & V_435 ;
F_100 ( V_11 , V_172 ) ;
F_111 ( V_11 ) ;
F_5 ( V_7 , L_243 , F_188 ( V_425 ) ) ;
return 0 ;
}
static int F_189 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
unsigned long V_436 , V_437 , V_438 ;
int V_70 ;
if ( ! F_130 ( V_11 ) )
return - V_418 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
V_436 = F_190 ( V_11 ) ;
V_437 = F_191 ( V_11 ) ;
V_438 = F_192 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
F_5 ( V_7 , L_244 , V_436 ) ;
F_5 ( V_7 , L_245 , V_437 ) ;
F_5 ( V_7 , L_246 , V_438 ) ;
F_5 ( V_7 , L_247 , V_437 + V_438 ) ;
return 0 ;
}
static int F_193 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
int V_70 = 0 ;
int V_439 , V_440 ;
unsigned int V_441 , V_442 ;
if ( ! F_194 ( V_11 ) ) {
F_35 ( V_7 , L_248 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
V_70 = F_44 ( & V_11 -> V_230 . V_231 ) ;
if ( V_70 )
goto V_74;
if ( F_144 ( V_11 ) ) {
V_442 =
V_11 -> V_230 . V_443 / V_291 ;
V_441 =
V_11 -> V_230 . V_444 / V_291 ;
} else {
V_442 = V_11 -> V_230 . V_443 ;
V_441 = V_11 -> V_230 . V_444 ;
}
F_35 ( V_7 , L_249 ) ;
for ( V_439 = V_442 ; V_439 <= V_441 ; V_439 ++ ) {
V_440 = V_439 ;
F_169 ( V_11 ,
V_445 ,
& V_440 ) ;
F_5 ( V_7 , L_250 ,
F_133 ( V_11 , ( V_439 *
( F_144 ( V_11 ) ?
V_291 : 1 ) ) ) ,
( ( V_440 >> 0 ) & 0xff ) * 100 ,
( ( V_440 >> 8 ) & 0xff ) * 100 ) ;
}
F_47 ( & V_11 -> V_230 . V_231 ) ;
V_74:
F_111 ( V_11 ) ;
return V_70 ;
}
static int F_195 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_446 * V_447 = & V_11 -> V_447 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_74;
if ( V_447 -> V_448 )
F_196 ( V_7 , V_447 -> V_448 , V_449 ) ;
F_47 ( & V_5 -> V_34 ) ;
V_74:
return 0 ;
}
static int F_197 ( struct V_6 * V_7 , void * V_220 )
{
struct V_446 * V_447 = & F_1 ( V_7 -> V_12 ) -> V_447 ;
if ( V_447 -> V_450 )
F_196 ( V_7 , V_447 -> V_450 , V_447 -> V_451 ) ;
return 0 ;
}
static int F_198 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_452 * V_453 = NULL ;
struct V_454 * V_455 ;
int V_70 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
#ifdef F_199
if ( V_11 -> V_456 ) {
V_453 = F_200 ( V_11 -> V_456 -> V_457 . V_458 ) ;
F_5 ( V_7 , L_251 ,
V_453 -> V_29 . V_51 ,
V_453 -> V_29 . V_52 ,
V_453 -> V_29 . V_459 -> V_460 ,
V_453 -> V_29 . V_459 -> V_461 [ 0 ] * 8 ,
V_453 -> V_29 . V_462 ,
F_201 ( & V_453 -> V_29 ) ) ;
F_31 ( V_7 , V_453 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
#endif
F_58 ( & V_5 -> V_463 . V_464 ) ;
F_202 (drm_fb, dev) {
struct V_452 * V_458 = F_200 ( V_455 ) ;
if ( V_458 == V_453 )
continue;
F_5 ( V_7 , L_252 ,
V_458 -> V_29 . V_51 ,
V_458 -> V_29 . V_52 ,
V_458 -> V_29 . V_459 -> V_460 ,
V_458 -> V_29 . V_459 -> V_461 [ 0 ] * 8 ,
V_458 -> V_29 . V_462 ,
F_201 ( & V_458 -> V_29 ) ) ;
F_31 ( V_7 , V_458 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_463 . V_464 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_203 ( struct V_6 * V_7 , struct V_465 * V_97 )
{
F_5 ( V_7 , L_253 ,
V_97 -> V_466 , V_97 -> V_467 , V_97 -> V_468 ) ;
}
static int F_204 ( struct V_6 * V_7 , void * V_220 )
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
F_28 (ctx, &dev_priv->context_list, link) {
F_5 ( V_7 , L_254 , V_95 -> V_145 ) ;
if ( V_95 -> V_123 ) {
struct V_117 * V_118 ;
V_118 = F_205 ( V_95 -> V_123 , V_124 ) ;
if ( V_118 ) {
F_5 ( V_7 , L_255 ,
V_118 -> V_125 , V_118 -> V_123 ) ;
F_206 ( V_118 ) ;
}
} else if ( F_207 ( V_95 -> V_87 ) ) {
F_35 ( V_7 , L_256 ) ;
} else {
F_35 ( V_7 , L_257 ) ;
}
F_46 ( V_7 , V_95 -> V_469 ? 'R' : 'r' ) ;
F_46 ( V_7 , '\n' ) ;
F_53 (engine, dev_priv, id) {
struct V_470 * V_471 = & V_95 -> V_31 [ V_31 -> V_55 ] ;
F_5 ( V_7 , L_258 , V_31 -> V_8 ) ;
F_46 ( V_7 , V_471 -> V_472 ? 'I' : 'i' ) ;
if ( V_471 -> V_96 )
F_31 ( V_7 , V_471 -> V_96 -> V_18 ) ;
if ( V_471 -> V_97 )
F_203 ( V_7 , V_471 -> V_97 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_5 ( V_7 ,
L_259 ,
V_95 -> V_473 . V_474 ,
F_208 ( V_95 -> V_473 . V_475 ) ,
V_95 -> V_473 . V_476 ) ;
F_46 ( V_7 , '\n' ) ;
}
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static void F_209 ( struct V_6 * V_7 ,
struct V_94 * V_95 ,
struct V_30 * V_31 )
{
struct V_27 * V_28 = V_95 -> V_31 [ V_31 -> V_55 ] . V_96 ;
struct V_477 * V_477 ;
int V_91 ;
F_5 ( V_7 , L_260 , V_31 -> V_8 , V_95 -> V_145 ) ;
if ( ! V_28 ) {
F_35 ( V_7 , L_261 ) ;
return;
}
if ( V_28 -> V_308 & V_478 )
F_5 ( V_7 , L_262 ,
F_210 ( V_28 ) ) ;
if ( F_211 ( V_28 -> V_18 ) ) {
F_35 ( V_7 , L_263 ) ;
return;
}
V_477 = F_212 ( V_28 -> V_18 , V_479 ) ;
if ( V_477 ) {
T_4 * V_480 = F_213 ( V_477 ) ;
for ( V_91 = 0 ; V_91 < 0x600 / sizeof( T_4 ) / 4 ; V_91 += 4 ) {
F_5 ( V_7 ,
L_264 ,
V_91 * 4 ,
V_480 [ V_91 ] , V_480 [ V_91 + 1 ] ,
V_480 [ V_91 + 2 ] , V_480 [ V_91 + 3 ] ) ;
}
F_214 ( V_480 ) ;
}
F_215 ( V_28 -> V_18 ) ;
F_46 ( V_7 , '\n' ) ;
}
static int F_216 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
struct V_94 * V_95 ;
enum V_90 V_55 ;
int V_70 ;
if ( ! V_210 . V_481 ) {
F_5 ( V_7 , L_265 ) ;
return 0 ;
}
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_28 (ctx, &dev_priv->context_list, link)
F_53 (engine, dev_priv, id)
F_209 ( V_7 , V_95 , V_31 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static const char * F_217 ( unsigned V_482 )
{
switch ( V_482 ) {
case V_483 :
return L_266 ;
case V_484 :
return L_267 ;
case V_485 :
return L_268 ;
case V_486 :
return L_269 ;
case V_487 :
return L_270 ;
case V_488 :
return L_271 ;
case V_489 :
return L_272 ;
case V_490 :
return L_273 ;
}
return L_274 ;
}
static int F_218 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_275 ,
F_217 ( V_11 -> V_24 . V_491 ) ) ;
F_5 ( V_7 , L_276 ,
F_217 ( V_11 -> V_24 . V_492 ) ) ;
if ( F_219 ( V_11 ) || F_220 ( V_11 ) ) {
F_5 ( V_7 , L_277 ,
F_79 ( V_493 ) ) ;
F_5 ( V_7 , L_278 ,
F_79 ( V_494 ) ) ;
F_5 ( V_7 , L_279 ,
F_131 ( V_495 ) ) ;
F_5 ( V_7 , L_280 ,
F_131 ( V_496 ) ) ;
} else if ( F_10 ( V_11 ) >= 6 ) {
F_5 ( V_7 , L_281 ,
F_79 ( V_497 ) ) ;
F_5 ( V_7 , L_282 ,
F_79 ( V_498 ) ) ;
F_5 ( V_7 , L_283 ,
F_79 ( V_499 ) ) ;
F_5 ( V_7 , L_284 ,
F_79 ( V_500 ) ) ;
if ( F_10 ( V_11 ) >= 8 )
F_5 ( V_7 , L_285 ,
F_79 ( V_501 ) ) ;
else
F_5 ( V_7 , L_286 ,
F_79 ( V_502 ) ) ;
F_5 ( V_7 , L_287 ,
F_79 ( V_503 ) ) ;
}
if ( V_11 -> V_504 & V_505 )
F_35 ( V_7 , L_288 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_221 ( int V_55 , void * V_75 , void * V_10 )
{
struct V_94 * V_95 = V_75 ;
struct V_6 * V_7 = V_10 ;
struct V_83 * V_84 = V_95 -> V_84 ;
if ( ! V_84 ) {
F_5 ( V_7 , L_289 ,
V_95 -> V_506 ) ;
return 0 ;
}
if ( F_222 ( V_95 ) )
F_35 ( V_7 , L_290 ) ;
else
F_5 ( V_7 , L_291 , V_95 -> V_506 ) ;
V_84 -> V_507 ( V_84 , V_7 ) ;
return 0 ;
}
static void F_223 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_83 * V_84 = V_11 -> V_24 . V_508 ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_164 ;
if ( ! V_84 )
return;
F_53 (engine, dev_priv, id) {
F_5 ( V_7 , L_292 , V_31 -> V_8 ) ;
for ( V_164 = 0 ; V_164 < 4 ; V_164 ++ ) {
T_3 V_509 = F_79 ( F_224 ( V_31 , V_164 ) ) ;
V_509 <<= 32 ;
V_509 |= F_79 ( F_225 ( V_31 , V_164 ) ) ;
F_5 ( V_7 , L_293 , V_164 , V_509 ) ;
}
}
}
static void F_226 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_30 * V_31 ;
enum V_90 V_55 ;
if ( F_140 ( V_11 ) )
F_5 ( V_7 , L_294 , F_79 ( V_510 ) ) ;
F_53 (engine, dev_priv, id) {
F_5 ( V_7 , L_292 , V_31 -> V_8 ) ;
if ( F_141 ( V_11 ) )
F_5 ( V_7 , L_294 ,
F_79 ( F_227 ( V_31 ) ) ) ;
F_5 ( V_7 , L_295 ,
F_79 ( F_228 ( V_31 ) ) ) ;
F_5 ( V_7 , L_296 ,
F_79 ( F_229 ( V_31 ) ) ) ;
F_5 ( V_7 , L_297 ,
F_79 ( F_230 ( V_31 ) ) ) ;
}
if ( V_11 -> V_24 . V_508 ) {
struct V_83 * V_84 = V_11 -> V_24 . V_508 ;
F_35 ( V_7 , L_298 ) ;
F_5 ( V_7 , L_299 , V_84 -> V_511 . V_29 . V_512 ) ;
V_84 -> V_507 ( V_84 , V_7 ) ;
}
F_5 ( V_7 , L_300 , F_79 ( V_513 ) ) ;
}
static int F_231 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_98 * V_86 ;
int V_70 ;
F_58 ( & V_5 -> V_114 ) ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
goto V_514;
F_94 ( V_11 ) ;
if ( F_10 ( V_11 ) >= 8 )
F_223 ( V_7 , V_11 ) ;
else if ( F_10 ( V_11 ) >= 6 )
F_226 ( V_7 , V_11 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_100 * V_87 = V_86 -> V_102 ;
struct V_117 * V_118 ;
V_118 = F_205 ( V_86 -> V_123 , V_124 ) ;
if ( ! V_118 ) {
V_70 = - V_515 ;
goto V_516;
}
F_5 ( V_7 , L_301 , V_118 -> V_125 ) ;
F_206 ( V_118 ) ;
F_59 ( & V_87 -> V_103 , F_221 ,
( void * ) ( unsigned long ) V_7 ) ;
}
V_516:
F_111 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
V_514:
F_47 ( & V_5 -> V_114 ) ;
return V_70 ;
}
static int F_232 ( struct V_1 * V_210 )
{
struct V_30 * V_31 ;
enum V_90 V_55 ;
int V_68 = 0 ;
F_53 (engine, i915, id)
V_68 += F_154 ( V_31 ) ;
return V_68 ;
}
static const char * F_233 ( unsigned int V_517 )
{
static const char * const V_518 [] = {
[ V_519 ] = L_302 ,
[ V_520 ] = L_303 ,
[ V_521 ] = L_304 ,
} ;
if ( V_517 >= F_54 ( V_518 ) || ! V_518 [ V_517 ] )
return L_273 ;
return V_518 [ V_517 ] ;
}
static int F_234 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_98 * V_86 ;
F_5 ( V_7 , L_305 , V_11 -> V_230 . V_522 ) ;
F_5 ( V_7 , L_306 ,
F_6 ( V_11 -> V_318 . V_319 ) , V_11 -> V_318 . V_523 ) ;
F_5 ( V_7 , L_307 , F_232 ( V_11 ) ) ;
F_5 ( V_7 , L_308 ,
F_133 ( V_11 , V_11 -> V_230 . V_234 ) ) ;
F_5 ( V_7 , L_309 ,
F_133 ( V_11 , V_11 -> V_230 . V_236 ) ,
F_133 ( V_11 , V_11 -> V_230 . V_443 ) ,
F_133 ( V_11 , V_11 -> V_230 . V_444 ) ,
F_133 ( V_11 , V_11 -> V_230 . V_235 ) ) ;
F_5 ( V_7 , L_310 ,
F_133 ( V_11 , V_11 -> V_230 . V_237 ) ,
F_133 ( V_11 , V_11 -> V_230 . V_238 ) ,
F_133 ( V_11 , V_11 -> V_230 . V_292 ) ) ;
F_58 ( & V_5 -> V_114 ) ;
F_62 ( & V_11 -> V_230 . V_524 ) ;
F_61 (file, &dev->filelist, lhead) {
struct V_100 * V_87 = V_86 -> V_102 ;
struct V_117 * V_118 ;
F_65 () ;
V_118 = F_66 ( V_86 -> V_123 , V_124 ) ;
F_5 ( V_7 , L_311 ,
V_118 ? V_118 -> V_125 : L_42 ,
V_118 ? V_118 -> V_123 : - 1 ,
V_87 -> V_230 . V_525 ,
F_25 ( & V_87 -> V_230 . V_526 ) ? L_13 : L_312 ) ;
F_67 () ;
}
F_5 ( V_7 , L_313 , V_11 -> V_230 . V_525 ) ;
F_63 ( & V_11 -> V_230 . V_524 ) ;
F_47 ( & V_5 -> V_114 ) ;
if ( F_10 ( V_11 ) >= 6 &&
V_11 -> V_230 . V_522 &&
V_11 -> V_318 . V_523 ) {
T_4 V_527 , V_248 ;
T_4 V_528 , V_251 ;
F_135 ( V_11 , V_264 ) ;
V_527 = F_167 ( V_273 ) & V_529 ;
V_248 = F_167 ( V_271 ) & V_529 ;
V_528 = F_167 ( V_278 ) & V_529 ;
V_251 = F_167 ( V_276 ) & V_529 ;
F_139 ( V_11 , V_264 ) ;
F_5 ( V_7 , L_314 ,
F_233 ( V_11 -> V_230 . V_517 ) ) ;
F_5 ( V_7 , L_315 ,
V_527 && V_248 ? 100 * V_527 / V_248 : 0 ,
V_11 -> V_230 . V_289 ) ;
F_5 ( V_7 , L_316 ,
V_528 && V_251 ? 100 * V_528 / V_251 : 0 ,
V_11 -> V_230 . V_290 ) ;
} else {
F_35 ( V_7 , L_317 ) ;
}
return 0 ;
}
static int F_235 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const bool V_530 = F_10 ( V_11 ) > 8 ;
F_5 ( V_7 , L_318 , F_6 ( F_194 ( V_11 ) ) ) ;
F_5 ( V_7 , L_319 , V_530 ? L_320 : L_321 ,
F_236 ( V_11 ) / 1024 / 1024 ) ;
return 0 ;
}
static int F_237 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_531 * V_532 = & V_11 -> V_533 . V_534 ;
if ( ! F_238 ( V_11 ) )
return 0 ;
F_35 ( V_7 , L_322 ) ;
F_5 ( V_7 , L_323 , V_532 -> V_535 ) ;
F_5 ( V_7 , L_324 ,
F_239 ( V_532 -> V_536 ) ) ;
F_5 ( V_7 , L_325 ,
F_239 ( V_532 -> V_537 ) ) ;
F_5 ( V_7 , L_326 ,
V_532 -> V_538 , V_532 -> V_539 ) ;
F_5 ( V_7 , L_327 ,
V_532 -> V_540 , V_532 -> V_541 ) ;
F_5 ( V_7 , L_328 ,
V_532 -> V_542 , V_532 -> V_543 ) ;
F_5 ( V_7 , L_329 ,
V_532 -> V_544 , V_532 -> V_545 ) ;
F_5 ( V_7 , L_330 ,
V_532 -> V_546 , V_532 -> V_547 ) ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_331 , F_79 ( V_548 ) ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_240 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_531 * V_549 = & V_11 -> V_550 . V_534 ;
T_4 V_209 , V_164 ;
if ( ! F_241 ( V_11 ) )
return 0 ;
F_5 ( V_7 , L_332 ) ;
F_5 ( V_7 , L_323 ,
V_549 -> V_535 ) ;
F_5 ( V_7 , L_324 ,
F_239 ( V_549 -> V_536 ) ) ;
F_5 ( V_7 , L_325 ,
F_239 ( V_549 -> V_537 ) ) ;
F_5 ( V_7 , L_326 ,
V_549 -> V_538 , V_549 -> V_539 ) ;
F_5 ( V_7 , L_327 ,
V_549 -> V_540 , V_549 -> V_541 ) ;
F_5 ( V_7 , L_328 ,
V_549 -> V_542 , V_549 -> V_543 ) ;
F_5 ( V_7 , L_329 ,
V_549 -> V_544 , V_549 -> V_545 ) ;
F_5 ( V_7 , L_330 ,
V_549 -> V_546 , V_549 -> V_547 ) ;
F_94 ( V_11 ) ;
V_209 = F_79 ( V_551 ) ;
F_5 ( V_7 , L_333 , V_209 ) ;
F_5 ( V_7 , L_334 ,
( V_209 & V_552 ) >> V_553 ) ;
F_5 ( V_7 , L_335 ,
( V_209 & V_554 ) >> V_555 ) ;
F_5 ( V_7 , L_336 ,
( V_209 & V_556 ) >> V_557 ) ;
F_35 ( V_7 , L_337 ) ;
for ( V_164 = 0 ; V_164 < 16 ; V_164 ++ )
F_5 ( V_7 , L_338 , V_164 , F_79 ( F_242 ( V_164 ) ) ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static void F_243 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_558 * V_550 = & V_11 -> V_550 ;
F_35 ( V_7 , L_339 ) ;
F_5 ( V_7 , L_340 ,
V_550 -> log . V_559 [ V_560 ] ,
V_550 -> log . V_561 [ V_560 ] ) ;
F_5 ( V_7 , L_341 ,
V_550 -> log . V_559 [ V_562 ] ,
V_550 -> log . V_561 [ V_562 ] ) ;
F_5 ( V_7 , L_342 ,
V_550 -> log . V_559 [ V_563 ] ,
V_550 -> log . V_561 [ V_563 ] ) ;
F_5 ( V_7 , L_343 ,
V_550 -> log . V_564 ) ;
F_5 ( V_7 , L_344 ,
V_550 -> log . V_565 ) ;
}
static void F_244 ( struct V_6 * V_7 ,
struct V_1 * V_11 ,
struct V_566 * V_567 )
{
struct V_30 * V_31 ;
enum V_90 V_55 ;
T_11 V_568 = 0 ;
F_5 ( V_7 , L_345 ,
V_567 -> V_148 , V_567 -> V_569 , V_567 -> V_570 ) ;
F_5 ( V_7 , L_346 ,
V_567 -> V_571 , V_567 -> V_572 , V_567 -> V_573 ) ;
F_5 ( V_7 , L_347 ,
V_567 -> V_574 , V_567 -> V_575 , V_567 -> V_576 ) ;
F_5 ( V_7 , L_348 , V_567 -> V_577 ) ;
F_53 (engine, dev_priv, id) {
T_3 V_578 = V_567 -> V_578 [ V_55 ] ;
V_568 += V_578 ;
F_5 ( V_7 , L_349 ,
V_578 , V_31 -> V_8 ) ;
}
F_5 ( V_7 , L_350 , V_568 ) ;
}
static bool F_245 ( struct V_6 * V_7 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_558 * V_550 = & V_11 -> V_550 ;
if ( ! V_550 -> V_579 ) {
F_5 ( V_7 , L_351 ,
F_246 ( V_11 ) ?
L_352 :
L_353 ) ;
return false ;
}
return true ;
}
static int F_247 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_558 * V_550 = & V_11 -> V_550 ;
if ( ! F_245 ( V_7 ) )
return 0 ;
F_5 ( V_7 , L_354 ) ;
F_5 ( V_7 , L_355 , V_580 , V_550 -> V_581 ) ;
F_5 ( V_7 , L_356 , V_550 -> V_582 ) ;
F_5 ( V_7 , L_357 , V_550 -> V_579 ) ;
F_244 ( V_7 , V_11 , V_550 -> V_579 ) ;
F_243 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_248 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const struct V_558 * V_550 = & V_11 -> V_550 ;
struct V_583 * V_584 = V_550 -> V_585 ;
struct V_566 * V_567 = V_550 -> V_579 ;
unsigned int V_209 ;
int V_586 ;
if ( ! F_245 ( V_7 ) )
return 0 ;
for ( V_586 = 0 ; V_586 < V_587 ; V_586 ++ , V_584 ++ ) {
struct V_30 * V_31 ;
if ( ! ( V_584 -> V_588 & V_589 ) )
continue;
F_5 ( V_7 , L_358 , V_586 ) ;
F_5 ( V_7 , L_359 , V_584 -> V_569 ) ;
F_5 ( V_7 , L_360 , V_584 -> V_588 ) ;
F_5 ( V_7 , L_361 , V_584 -> V_148 ) ;
F_5 ( V_7 , L_362 , V_584 -> V_590 ) ;
F_5 ( V_7 , L_363 ,
V_584 -> V_591 ) ;
F_5 ( V_7 , L_364 ,
V_584 -> V_592 ,
V_584 -> V_593 ,
V_584 -> V_594 ) ;
F_5 ( V_7 , L_365 ,
V_584 -> V_595 ) ;
F_5 ( V_7 , L_366 ,
V_584 -> V_596 , V_584 -> V_574 ) ;
F_46 ( V_7 , '\n' ) ;
F_249 (engine, dev_priv, client->engines, tmp) {
T_4 V_597 = V_31 -> V_598 ;
struct V_599 * V_600 =
& V_584 -> V_600 [ V_597 ] ;
F_5 ( V_7 , L_367 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_368 ,
V_600 -> V_601 ) ;
F_5 ( V_7 , L_369 , V_600 -> V_602 ) ;
F_5 ( V_7 , L_370 , V_600 -> V_603 ) ;
F_5 ( V_7 , L_371 , V_600 -> V_604 ) ;
F_5 ( V_7 , L_372 , V_600 -> V_605 ) ;
F_46 ( V_7 , '\n' ) ;
}
}
return 0 ;
}
static int F_250 ( struct V_6 * V_7 , void * V_10 )
{
struct V_2 * V_3 = V_7 -> V_12 ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
bool V_606 = ! ! V_3 -> V_127 -> V_10 ;
struct V_17 * V_18 = NULL ;
T_4 * log ;
int V_164 = 0 ;
if ( V_606 )
V_18 = V_11 -> V_550 . V_607 ;
else if ( V_11 -> V_550 . log . V_28 )
V_18 = V_11 -> V_550 . log . V_28 -> V_18 ;
if ( ! V_18 )
return 0 ;
log = F_251 ( V_18 , V_608 ) ;
if ( F_207 ( log ) ) {
F_252 ( L_373 ) ;
F_35 ( V_7 , L_374 ) ;
return F_253 ( log ) ;
}
for ( V_164 = 0 ; V_164 < V_18 -> V_29 . V_26 / sizeof( T_4 ) ; V_164 += 4 )
F_5 ( V_7 , L_375 ,
* ( log + V_164 ) , * ( log + V_164 + 1 ) ,
* ( log + V_164 + 2 ) , * ( log + V_164 + 3 ) ) ;
F_46 ( V_7 , '\n' ) ;
F_254 ( V_18 ) ;
return 0 ;
}
static int F_255 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
if ( ! V_11 -> V_550 . log . V_28 )
return - V_609 ;
* V_219 = V_210 . V_610 ;
return 0 ;
}
static int F_256 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_11 = V_10 ;
int V_70 ;
if ( ! V_11 -> V_550 . log . V_28 )
return - V_609 ;
V_70 = F_44 ( & V_11 -> V_63 . V_34 ) ;
if ( V_70 )
return V_70 ;
F_94 ( V_11 ) ;
V_70 = F_257 ( V_11 , V_219 ) ;
F_111 ( V_11 ) ;
F_47 ( & V_11 -> V_63 . V_34 ) ;
return V_70 ;
}
static const char * F_258 ( T_4 V_219 )
{
static const char * const V_611 [] = {
L_376 ,
L_377 ,
L_378 ,
L_379 ,
L_380 ,
L_381 ,
L_382 ,
L_383 ,
L_384 ,
L_385 ,
L_386
} ;
V_219 = ( V_219 & V_612 ) >> V_613 ;
if ( V_219 < F_54 ( V_611 ) )
return V_611 [ V_219 ] ;
return L_273 ;
}
static int F_259 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_4 V_614 = 0 ;
T_4 V_615 [ 3 ] ;
enum V_130 V_130 ;
bool V_522 = false ;
if ( ! F_260 ( V_11 ) ) {
F_35 ( V_7 , L_387 ) ;
return 0 ;
}
F_94 ( V_11 ) ;
F_58 ( & V_11 -> V_616 . V_405 ) ;
F_5 ( V_7 , L_388 , F_6 ( V_11 -> V_616 . V_617 ) ) ;
F_5 ( V_7 , L_389 , F_6 ( V_11 -> V_616 . V_618 ) ) ;
F_5 ( V_7 , L_390 , F_6 ( ( bool ) V_11 -> V_616 . V_522 ) ) ;
F_5 ( V_7 , L_391 , F_6 ( V_11 -> V_616 . V_88 ) ) ;
F_5 ( V_7 , L_392 ,
V_11 -> V_616 . V_619 ) ;
F_5 ( V_7 , L_393 ,
F_6 ( F_261 ( & V_11 -> V_616 . V_132 . V_132 ) ) ) ;
if ( F_262 ( V_11 ) ) {
if ( V_11 -> V_616 . V_620 )
V_522 = F_79 ( V_621 ) & V_622 ;
else
V_522 = F_79 ( V_623 ) & V_624 ;
} else {
F_96 (dev_priv, pipe) {
enum V_625 V_626 =
F_263 ( V_11 , V_130 ) ;
enum V_170 V_171 ;
V_171 = F_264 ( V_626 ) ;
if ( ! F_98 ( V_11 ,
V_171 ) )
continue;
V_615 [ V_130 ] = F_79 ( F_265 ( V_130 ) ) &
V_627 ;
if ( ( V_615 [ V_130 ] == V_628 ) ||
( V_615 [ V_130 ] == V_629 ) )
V_522 = true ;
F_100 ( V_11 , V_171 ) ;
}
}
F_5 ( V_7 , L_394 ,
F_6 ( V_11 -> V_616 . V_630 ) ) ;
F_5 ( V_7 , L_395 , F_6 ( V_522 ) ) ;
if ( ! F_262 ( V_11 ) )
F_96 (dev_priv, pipe) {
if ( ( V_615 [ V_130 ] == V_628 ) ||
( V_615 [ V_130 ] == V_629 ) )
F_5 ( V_7 , L_396 , F_71 ( V_130 ) ) ;
}
F_35 ( V_7 , L_397 ) ;
if ( F_137 ( V_11 ) || F_138 ( V_11 ) ) {
V_614 = F_79 ( V_631 ) &
V_632 ;
F_5 ( V_7 , L_398 , V_614 ) ;
}
if ( V_11 -> V_616 . V_620 ) {
T_4 V_633 = F_79 ( V_634 ) ;
F_5 ( V_7 , L_399 ,
V_633 , F_258 ( V_633 ) ) ;
}
F_47 ( & V_11 -> V_616 . V_405 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_266 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_635 * V_636 ;
struct V_637 V_638 ;
struct V_639 * V_639 = NULL ;
int V_70 ;
T_12 V_640 [ 6 ] ;
F_267 ( V_5 ) ;
F_268 ( V_5 , & V_638 ) ;
F_269 (connector, &conn_iter) {
struct V_641 * V_129 ;
if ( ! V_636 -> V_29 . V_96 -> V_642 )
continue;
V_129 = V_636 -> V_29 . V_96 -> V_129 ;
if ( ! V_129 -> V_96 -> V_88 )
continue;
if ( V_636 -> V_29 . V_643 != V_644 )
continue;
V_639 = F_270 ( V_636 -> V_29 . V_96 -> V_642 ) ;
V_70 = F_271 ( V_639 , V_640 ) ;
if ( V_70 )
goto V_74;
F_5 ( V_7 , L_400 ,
V_640 [ 0 ] , V_640 [ 1 ] , V_640 [ 2 ] ,
V_640 [ 3 ] , V_640 [ 4 ] , V_640 [ 5 ] ) ;
goto V_74;
}
V_70 = - V_418 ;
V_74:
F_272 ( & V_638 ) ;
F_273 ( V_5 ) ;
return V_70 ;
}
static int F_274 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
T_3 V_517 ;
T_4 V_645 ;
if ( F_10 ( V_11 ) < 6 )
return - V_418 ;
F_94 ( V_11 ) ;
F_275 ( V_646 , V_517 ) ;
V_517 = ( V_517 & 0x1f00 ) >> 8 ;
V_645 = 1000000 / ( 1 << V_517 ) ;
V_517 = F_79 ( V_647 ) ;
V_517 *= V_645 ;
F_111 ( V_11 ) ;
F_5 ( V_7 , L_401 , ( long long unsigned ) V_517 ) ;
return 0 ;
}
static int F_276 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_648 * V_649 = V_11 -> V_63 . V_649 ;
if ( ! F_277 ( V_11 ) )
F_35 ( V_7 , L_402 ) ;
F_5 ( V_7 , L_403 , F_6 ( ! V_11 -> V_318 . V_319 ) ) ;
F_5 ( V_7 , L_404 ,
F_6 ( ! F_278 ( V_11 ) ) ) ;
#ifdef F_279
F_5 ( V_7 , L_405 ,
F_39 ( & V_11 -> V_63 . V_5 -> V_517 . V_650 ) ) ;
#else
F_5 ( V_7 , L_406 ) ;
#endif
F_5 ( V_7 , L_407 ,
F_280 ( V_649 -> V_651 ) ,
V_649 -> V_651 ) ;
return 0 ;
}
static int F_281 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_652 * V_653 = & V_11 -> V_653 ;
int V_164 ;
F_58 ( & V_653 -> V_405 ) ;
F_5 ( V_7 , L_408 , L_409 , L_410 ) ;
for ( V_164 = 0 ; V_164 < V_653 -> V_654 ; V_164 ++ ) {
struct V_655 * V_656 ;
enum V_170 V_171 ;
V_656 = & V_653 -> V_657 [ V_164 ] ;
F_5 ( V_7 , L_411 , V_656 -> V_8 ,
V_656 -> V_68 ) ;
F_282 (power_domain, power_well->domains)
F_5 ( V_7 , L_412 ,
F_283 ( V_171 ) ,
V_653 -> V_658 [ V_171 ] ) ;
}
F_47 ( & V_653 -> V_405 ) ;
return 0 ;
}
static int F_284 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_659 * V_660 ;
if ( ! F_285 ( V_11 ) ) {
F_35 ( V_7 , L_238 ) ;
return 0 ;
}
V_660 = & V_11 -> V_660 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_413 , F_6 ( V_660 -> V_661 != NULL ) ) ;
F_5 ( V_7 , L_414 , V_660 -> V_662 ) ;
if ( ! V_660 -> V_661 )
goto V_74;
F_5 ( V_7 , L_415 , F_286 ( V_660 -> V_663 ) ,
F_287 ( V_660 -> V_663 ) ) ;
if ( F_288 ( V_11 ) ||
( F_289 ( V_11 ) && V_660 -> V_663 >= F_290 ( 1 , 6 ) ) ) {
F_5 ( V_7 , L_416 ,
F_79 ( V_664 ) ) ;
F_5 ( V_7 , L_417 ,
F_79 ( V_665 ) ) ;
} else if ( F_291 ( V_11 ) && V_660 -> V_663 >= F_290 ( 1 , 4 ) ) {
F_5 ( V_7 , L_416 ,
F_79 ( V_666 ) ) ;
}
V_74:
F_5 ( V_7 , L_418 , F_79 ( F_292 ( 0 ) ) ) ;
F_5 ( V_7 , L_419 , F_79 ( V_667 ) ) ;
F_5 ( V_7 , L_420 , F_79 ( V_668 ) ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static void F_293 ( struct V_6 * V_7 , int V_669 ,
struct V_670 * V_671 )
{
int V_164 ;
for ( V_164 = 0 ; V_164 < V_669 ; V_164 ++ )
F_46 ( V_7 , '\t' ) ;
F_5 ( V_7 , L_421 ,
V_671 -> V_29 . V_55 , V_671 -> V_8 ,
V_671 -> V_672 , V_671 -> clock ,
V_671 -> V_673 , V_671 -> V_674 ,
V_671 -> V_675 , V_671 -> V_676 ,
V_671 -> V_677 , V_671 -> V_678 ,
V_671 -> V_679 , V_671 -> V_680 ,
V_671 -> type , V_671 -> V_308 ) ;
}
static void F_294 ( struct V_6 * V_7 ,
struct V_128 * V_128 ,
struct V_681 * V_681 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_641 * V_129 = & V_128 -> V_29 ;
struct V_635 * V_635 ;
struct V_682 * V_683 ;
V_683 = & V_681 -> V_29 ;
F_5 ( V_7 , L_422 ,
V_683 -> V_29 . V_55 , V_683 -> V_8 ) ;
F_295 (dev, encoder, intel_connector) {
struct V_684 * V_636 = & V_635 -> V_29 ;
F_5 ( V_7 , L_423 ,
V_636 -> V_29 . V_55 ,
V_636 -> V_8 ,
F_296 ( V_636 -> V_685 ) ) ;
if ( V_636 -> V_685 == V_686 ) {
struct V_670 * V_671 = & V_129 -> V_671 ;
F_5 ( V_7 , L_424 ) ;
F_293 ( V_7 , 2 , V_671 ) ;
} else {
F_46 ( V_7 , '\n' ) ;
}
}
}
static void F_297 ( struct V_6 * V_7 , struct V_128 * V_128 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_641 * V_129 = & V_128 -> V_29 ;
struct V_681 * V_681 ;
struct V_687 * V_688 = V_129 -> V_689 -> V_96 ;
struct V_454 * V_458 = V_688 -> V_458 ;
if ( V_458 )
F_5 ( V_7 , L_425 ,
V_458 -> V_29 . V_55 , V_688 -> V_690 >> 16 ,
V_688 -> V_691 >> 16 , V_458 -> V_51 , V_458 -> V_52 ) ;
else
F_35 ( V_7 , L_426 ) ;
F_298 (dev, crtc, intel_encoder)
F_294 ( V_7 , V_128 , V_681 ) ;
}
static void F_299 ( struct V_6 * V_7 , struct V_692 * V_693 )
{
struct V_670 * V_671 = V_693 -> V_694 ;
F_5 ( V_7 , L_427 ) ;
F_293 ( V_7 , 2 , V_671 ) ;
}
static void F_300 ( struct V_6 * V_7 ,
struct V_635 * V_635 )
{
struct V_681 * V_681 = V_635 -> V_683 ;
struct V_639 * V_639 = F_270 ( & V_681 -> V_29 ) ;
F_5 ( V_7 , L_428 , V_639 -> V_695 [ V_696 ] ) ;
F_5 ( V_7 , L_429 , F_6 ( V_639 -> V_697 ) ) ;
if ( V_635 -> V_29 . V_643 == V_644 )
F_299 ( V_7 , & V_635 -> V_693 ) ;
F_301 ( V_7 , V_639 -> V_695 , V_639 -> V_698 ,
& V_639 -> V_699 ) ;
}
static void F_302 ( struct V_6 * V_7 ,
struct V_635 * V_635 )
{
struct V_681 * V_681 = V_635 -> V_683 ;
struct V_700 * V_701 =
F_303 ( & V_681 -> V_29 ) ;
struct V_702 * V_703 = V_701 -> V_689 ;
struct V_639 * V_639 = & V_703 -> V_704 ;
bool V_697 = F_304 ( & V_639 -> V_705 ,
V_635 -> V_706 ) ;
F_5 ( V_7 , L_429 , F_6 ( V_697 ) ) ;
}
static void F_305 ( struct V_6 * V_7 ,
struct V_635 * V_635 )
{
struct V_681 * V_681 = V_635 -> V_683 ;
struct V_707 * V_707 = F_306 ( & V_681 -> V_29 ) ;
F_5 ( V_7 , L_429 , F_6 ( V_707 -> V_697 ) ) ;
}
static void F_307 ( struct V_6 * V_7 ,
struct V_635 * V_635 )
{
F_299 ( V_7 , & V_635 -> V_693 ) ;
}
static void F_308 ( struct V_6 * V_7 ,
struct V_684 * V_636 )
{
struct V_635 * V_635 = F_309 ( V_636 ) ;
struct V_681 * V_681 = V_635 -> V_683 ;
struct V_670 * V_671 ;
F_5 ( V_7 , L_430 ,
V_636 -> V_29 . V_55 , V_636 -> V_8 ,
F_296 ( V_636 -> V_685 ) ) ;
if ( V_636 -> V_685 == V_686 ) {
F_5 ( V_7 , L_431 , V_636 -> V_708 . V_8 ) ;
F_5 ( V_7 , L_432 ,
V_636 -> V_708 . V_709 ,
V_636 -> V_708 . V_710 ) ;
F_5 ( V_7 , L_433 ,
F_310 ( V_636 -> V_708 . V_711 ) ) ;
F_5 ( V_7 , L_434 ,
V_636 -> V_708 . V_712 ) ;
}
if ( ! V_681 )
return;
switch ( V_636 -> V_643 ) {
case V_713 :
case V_644 :
if ( V_681 -> type == V_714 )
F_302 ( V_7 , V_635 ) ;
else
F_300 ( V_7 , V_635 ) ;
break;
case V_715 :
if ( V_681 -> type == V_716 )
F_307 ( V_7 , V_635 ) ;
break;
case V_717 :
if ( V_681 -> type == V_718 ||
V_681 -> type == V_719 )
F_305 ( V_7 , V_635 ) ;
break;
default:
break;
}
F_5 ( V_7 , L_435 ) ;
F_28 (mode, &connector->modes, head)
F_293 ( V_7 , 2 , V_671 ) ;
}
static const char * F_311 ( enum V_720 type )
{
switch ( type ) {
case V_721 :
return L_436 ;
case V_722 :
return L_437 ;
case V_723 :
return L_438 ;
}
return L_273 ;
}
static const char * F_312 ( unsigned int V_724 )
{
static char V_211 [ 48 ] ;
snprintf ( V_211 , sizeof( V_211 ) ,
L_439 ,
( V_724 & V_725 ) ? L_440 : L_13 ,
( V_724 & V_726 ) ? L_441 : L_13 ,
( V_724 & V_727 ) ? L_442 : L_13 ,
( V_724 & V_728 ) ? L_443 : L_13 ,
( V_724 & V_729 ) ? L_444 : L_13 ,
( V_724 & V_730 ) ? L_445 : L_13 ,
V_724 ) ;
return V_211 ;
}
static void F_313 ( struct V_6 * V_7 , struct V_128 * V_128 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_731 * V_731 ;
F_314 (dev, intel_crtc, intel_plane) {
struct V_687 * V_96 ;
struct V_732 * V_50 = & V_731 -> V_29 ;
struct V_733 V_734 ;
if ( ! V_50 -> V_96 ) {
F_35 ( V_7 , L_446 ) ;
continue;
}
V_96 = V_50 -> V_96 ;
if ( V_96 -> V_458 ) {
F_315 ( V_96 -> V_458 -> V_459 -> V_459 ,
& V_734 ) ;
} else {
sprintf ( V_734 . V_208 , L_447 ) ;
}
F_5 ( V_7 , L_448 ,
V_50 -> V_29 . V_55 ,
F_311 ( V_731 -> V_29 . type ) ,
V_96 -> V_735 , V_96 -> V_736 ,
V_96 -> V_737 , V_96 -> V_738 ,
( V_96 -> V_690 >> 16 ) ,
( ( V_96 -> V_690 & 0xffff ) * 15625 ) >> 10 ,
( V_96 -> V_691 >> 16 ) ,
( ( V_96 -> V_691 & 0xffff ) * 15625 ) >> 10 ,
( V_96 -> V_739 >> 16 ) ,
( ( V_96 -> V_739 & 0xffff ) * 15625 ) >> 10 ,
( V_96 -> V_740 >> 16 ) ,
( ( V_96 -> V_740 & 0xffff ) * 15625 ) >> 10 ,
V_734 . V_208 ,
F_312 ( V_96 -> V_724 ) ) ;
}
}
static void F_316 ( struct V_6 * V_7 , struct V_128 * V_128 )
{
struct V_741 * V_742 ;
int V_743 = V_128 -> V_743 ;
int V_164 ;
V_742 = F_317 ( V_128 -> V_29 . V_96 ) ;
if ( V_743 ) {
F_5 ( V_7 , L_449 ,
V_743 ,
V_742 -> V_744 . V_745 ,
V_742 -> V_744 . V_746 ) ;
for ( V_164 = 0 ; V_164 < V_743 ; V_164 ++ ) {
struct V_747 * V_748 =
& V_742 -> V_744 . V_749 [ V_164 ] ;
F_5 ( V_7 , L_450 ,
V_164 , F_6 ( V_748 -> V_750 ) , V_748 -> V_671 ) ;
}
F_35 ( V_7 , L_397 ) ;
} else {
F_35 ( V_7 , L_451 ) ;
}
}
static int F_318 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_128 * V_129 ;
struct V_684 * V_636 ;
struct V_637 V_638 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_452 ) ;
F_5 ( V_7 , L_453 ) ;
F_70 (dev, crtc) {
struct V_741 * V_742 ;
F_319 ( & V_129 -> V_29 . V_751 , NULL ) ;
V_742 = F_317 ( V_129 -> V_29 . V_96 ) ;
F_5 ( V_7 , L_454 ,
V_129 -> V_29 . V_29 . V_55 , F_71 ( V_129 -> V_130 ) ,
F_6 ( V_742 -> V_29 . V_88 ) ,
V_742 -> V_752 , V_742 -> V_753 ,
F_6 ( V_742 -> V_754 ) , V_742 -> V_755 ) ;
if ( V_742 -> V_29 . V_88 ) {
struct V_731 * V_756 =
F_320 ( V_129 -> V_29 . V_756 ) ;
F_297 ( V_7 , V_129 ) ;
F_5 ( V_7 , L_455 ,
F_6 ( V_756 -> V_29 . V_96 -> V_757 ) ,
V_756 -> V_29 . V_96 -> V_735 ,
V_756 -> V_29 . V_96 -> V_736 ,
V_756 -> V_29 . V_96 -> V_737 ,
V_756 -> V_29 . V_96 -> V_738 ,
V_756 -> V_756 . V_29 ) ;
F_316 ( V_7 , V_129 ) ;
F_313 ( V_7 , V_129 ) ;
}
F_5 ( V_7 , L_456 ,
F_6 ( ! V_129 -> V_758 ) ,
F_6 ( ! V_129 -> V_759 ) ) ;
F_321 ( & V_129 -> V_29 . V_751 ) ;
}
F_5 ( V_7 , L_397 ) ;
F_5 ( V_7 , L_457 ) ;
F_5 ( V_7 , L_458 ) ;
F_58 ( & V_5 -> V_463 . V_751 ) ;
F_268 ( V_5 , & V_638 ) ;
F_322 (connector, &conn_iter)
F_308 ( V_7 , V_636 ) ;
F_272 ( & V_638 ) ;
F_47 ( & V_5 -> V_463 . V_751 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_323 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_30 * V_31 ;
enum V_90 V_55 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_459 ,
F_6 ( V_11 -> V_318 . V_319 ) ) ;
F_5 ( V_7 , L_460 ,
V_11 -> V_318 . V_523 ) ;
F_53 (engine, dev_priv, id) {
struct V_155 * V_61 = & V_31 -> V_156 ;
struct V_115 * V_143 ;
struct V_157 * V_158 ;
T_3 V_136 ;
F_5 ( V_7 , L_292 , V_31 -> V_8 ) ;
F_5 ( V_7 , L_461 ,
F_75 ( V_31 ) ,
F_74 ( V_31 ) ,
V_31 -> V_320 . V_146 ,
F_85 ( V_149 - V_31 -> V_320 . V_325 ) ,
V_31 -> V_151 -> V_321 ) ;
F_65 () ;
F_5 ( V_7 , L_462 ) ;
V_143 = F_324 ( & V_31 -> V_151 -> V_760 ,
struct V_115 , V_526 ) ;
if ( & V_143 -> V_526 != & V_31 -> V_151 -> V_760 )
F_84 ( V_7 , V_143 , L_463 ) ;
V_143 = F_325 ( & V_31 -> V_151 -> V_760 ,
struct V_115 , V_526 ) ;
if ( & V_143 -> V_526 != & V_31 -> V_151 -> V_760 )
F_84 ( V_7 , V_143 , L_464 ) ;
V_143 = F_326 ( V_31 ) ;
if ( V_143 ) {
F_84 ( V_7 , V_143 , L_465 ) ;
F_5 ( V_7 ,
L_466 ,
V_143 -> V_467 , V_143 -> V_761 , V_143 -> V_468 ,
V_143 -> V_762 ? F_327 ( V_143 -> V_762 -> V_3 . V_41 ) : ~ 0u ,
V_143 -> V_762 ? F_328 ( V_143 -> V_762 -> V_3 . V_41 ) : ~ 0u ) ;
}
F_5 ( V_7 , L_467 ,
F_79 ( F_329 ( V_31 -> V_763 ) ) ,
V_143 ? F_210 ( V_143 -> V_97 -> V_28 ) : 0 ) ;
F_5 ( V_7 , L_468 ,
F_79 ( F_330 ( V_31 -> V_763 ) ) & V_764 ,
V_143 ? V_143 -> V_97 -> V_467 : 0 ) ;
F_5 ( V_7 , L_469 ,
F_79 ( F_331 ( V_31 -> V_763 ) ) & V_765 ,
V_143 ? V_143 -> V_97 -> V_468 : 0 ) ;
F_5 ( V_7 , L_470 ,
F_79 ( F_332 ( V_31 -> V_763 ) ) ,
F_79 ( F_332 ( V_31 -> V_763 ) ) & ( V_766 | V_767 ) ? L_471 : L_13 ) ;
F_67 () ;
V_136 = F_150 ( V_31 ) ;
F_5 ( V_7 , L_472 ,
F_327 ( V_136 ) , F_328 ( V_136 ) ) ;
V_136 = F_333 ( V_31 ) ;
F_5 ( V_7 , L_473 ,
F_327 ( V_136 ) , F_328 ( V_136 ) ) ;
if ( V_210 . V_481 ) {
T_4 V_75 , V_768 , V_769 ;
unsigned int V_770 ;
F_5 ( V_7 , L_474 ,
F_79 ( F_334 ( V_31 ) ) ,
F_79 ( F_335 ( V_31 ) ) ) ;
V_75 = F_79 ( F_336 ( V_31 ) ) ;
V_768 = F_337 ( V_75 ) ;
V_769 = F_338 ( V_75 ) ;
F_5 ( V_7 , L_475 ,
V_768 , V_769 ) ;
if ( V_768 >= V_771 )
V_768 = 0 ;
if ( V_769 >= V_771 )
V_769 = 0 ;
if ( V_768 > V_769 )
V_769 += V_771 ;
while ( V_768 < V_769 ) {
V_770 = ++ V_768 % V_771 ;
F_5 ( V_7 , L_476 ,
V_770 ,
F_79 ( F_339 ( V_31 , V_770 ) ) ,
F_79 ( F_340 ( V_31 , V_770 ) ) ) ;
}
F_65 () ;
for ( V_770 = 0 ; V_770 < F_54 ( V_31 -> V_772 ) ; V_770 ++ ) {
unsigned int V_68 ;
V_143 = F_341 ( & V_31 -> V_772 [ V_770 ] ,
& V_68 ) ;
if ( V_143 ) {
F_5 ( V_7 , L_477 ,
V_770 , V_68 ) ;
F_84 ( V_7 , V_143 , L_478 ) ;
} else {
F_5 ( V_7 , L_479 ,
V_770 ) ;
}
}
F_67 () ;
F_73 ( & V_31 -> V_151 -> V_405 ) ;
for ( V_158 = V_31 -> V_773 ; V_158 ; V_158 = F_89 ( V_158 ) ) {
struct V_774 * V_775 =
F_90 ( V_158 , F_91 ( * V_775 ) , V_3 ) ;
F_28 (rq, &p->requests,
priotree.link)
F_84 ( V_7 , V_143 , L_480 ) ;
}
F_82 ( & V_31 -> V_151 -> V_405 ) ;
} else if ( F_10 ( V_11 ) > 6 ) {
F_5 ( V_7 , L_481 ,
F_79 ( F_228 ( V_31 ) ) ) ;
F_5 ( V_7 , L_482 ,
F_79 ( F_229 ( V_31 ) ) ) ;
F_5 ( V_7 , L_483 ,
F_79 ( F_230 ( V_31 ) ) ) ;
}
F_73 ( & V_61 -> V_159 ) ;
for ( V_158 = F_88 ( & V_61 -> V_160 ) ; V_158 ; V_158 = F_89 ( V_158 ) ) {
struct V_161 * V_162 = F_90 ( V_158 , F_91 ( * V_162 ) , V_3 ) ;
F_5 ( V_7 , L_175 ,
V_162 -> V_163 -> V_125 , V_162 -> V_163 -> V_123 , V_162 -> V_146 ) ;
}
F_82 ( & V_61 -> V_159 ) ;
F_35 ( V_7 , L_397 ) ;
}
F_111 ( V_11 ) ;
return 0 ;
}
static int F_342 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_30 * V_31 ;
int V_776 = F_9 ( V_11 ) -> V_776 ;
enum V_90 V_55 ;
int V_91 , V_70 ;
if ( ! V_210 . V_777 ) {
F_35 ( V_7 , L_484 ) ;
return 0 ;
}
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_94 ( V_11 ) ;
if ( F_138 ( V_11 ) ) {
struct V_477 * V_477 ;
T_11 * V_146 ;
V_477 = F_212 ( V_11 -> V_778 -> V_18 , 0 ) ;
V_146 = ( T_11 * ) F_213 ( V_477 ) ;
F_53 (engine, dev_priv, id) {
T_11 V_46 ;
F_5 ( V_7 , L_292 , V_31 -> V_8 ) ;
F_35 ( V_7 , L_485 ) ;
for ( V_91 = 0 ; V_91 < V_776 ; V_91 ++ ) {
V_46 = V_55 * V_305 + V_91 ;
F_5 ( V_7 , L_486 ,
V_146 [ V_46 ] , V_46 * 8 ) ;
}
F_46 ( V_7 , '\n' ) ;
F_35 ( V_7 , L_487 ) ;
for ( V_91 = 0 ; V_91 < V_776 ; V_91 ++ ) {
V_46 = V_55 + ( V_91 * V_305 ) ;
F_5 ( V_7 , L_486 ,
V_146 [ V_46 ] , V_46 * 8 ) ;
}
F_46 ( V_7 , '\n' ) ;
}
F_214 ( V_146 ) ;
} else {
F_35 ( V_7 , L_485 ) ;
F_53 (engine, dev_priv, id)
for ( V_91 = 0 ; V_91 < V_776 ; V_91 ++ )
F_5 ( V_7 , L_488 ,
F_79 ( V_31 -> V_778 . V_779 . signal [ V_91 ] ) ) ;
F_46 ( V_7 , '\n' ) ;
}
F_111 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static int F_343 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_164 ;
F_267 ( V_5 ) ;
for ( V_164 = 0 ; V_164 < V_11 -> V_780 ; V_164 ++ ) {
struct V_781 * V_782 = & V_11 -> V_783 [ V_164 ] ;
F_5 ( V_7 , L_489 , V_164 , V_782 -> V_8 , V_782 -> V_55 ) ;
F_5 ( V_7 , L_490 ,
V_782 -> V_96 . V_784 , V_782 -> V_785 , F_6 ( V_782 -> V_786 ) ) ;
F_5 ( V_7 , L_491 ) ;
F_5 ( V_7 , L_492 , V_782 -> V_96 . V_787 . V_788 ) ;
F_5 ( V_7 , L_493 ,
V_782 -> V_96 . V_787 . V_789 ) ;
F_5 ( V_7 , L_494 , V_782 -> V_96 . V_787 . V_790 ) ;
F_5 ( V_7 , L_495 , V_782 -> V_96 . V_787 . V_791 ) ;
F_5 ( V_7 , L_496 , V_782 -> V_96 . V_787 . V_792 ) ;
}
F_273 ( V_5 ) ;
return 0 ;
}
static int F_344 ( struct V_6 * V_7 , void * V_220 )
{
int V_164 ;
int V_70 ;
struct V_30 * V_31 ;
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_793 * V_794 = & V_11 -> V_794 ;
enum V_90 V_55 ;
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
F_94 ( V_11 ) ;
F_5 ( V_7 , L_497 , V_794 -> V_68 ) ;
F_53 (engine, dev_priv, id)
F_5 ( V_7 , L_498 ,
V_31 -> V_8 , V_794 -> V_795 [ V_55 ] ) ;
for ( V_164 = 0 ; V_164 < V_794 -> V_68 ; ++ V_164 ) {
T_10 V_136 ;
T_4 V_407 , V_796 , V_768 ;
bool V_797 ;
V_136 = V_794 -> V_355 [ V_164 ] . V_136 ;
V_407 = V_794 -> V_355 [ V_164 ] . V_407 ;
V_796 = V_794 -> V_355 [ V_164 ] . V_796 ;
V_768 = F_79 ( V_136 ) ;
V_797 = ( V_796 & V_407 ) == ( V_768 & V_407 ) ;
F_5 ( V_7 , L_499 ,
F_345 ( V_136 ) , V_796 , V_407 , V_768 , V_797 ? L_500 : L_501 ) ;
}
F_111 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
return 0 ;
}
static int F_346 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_798 * V_799 ;
struct V_800 * V_801 ;
enum V_130 V_130 ;
int V_50 ;
if ( F_10 ( V_11 ) < 9 )
return 0 ;
F_267 ( V_5 ) ;
V_799 = & V_11 -> V_802 . V_803 . V_799 ;
F_5 ( V_7 , L_502 , L_13 , L_503 , L_504 , L_505 ) ;
F_96 (dev_priv, pipe) {
F_5 ( V_7 , L_506 , F_71 ( V_130 ) ) ;
F_347 (dev_priv, pipe, plane) {
V_801 = & V_799 -> V_50 [ V_130 ] [ V_50 ] ;
F_5 ( V_7 , L_507 , V_50 + 1 ,
V_801 -> V_41 , V_801 -> V_804 ,
F_348 ( V_801 ) ) ;
}
V_801 = & V_799 -> V_50 [ V_130 ] [ V_805 ] ;
F_5 ( V_7 , L_508 , L_509 , V_801 -> V_41 ,
V_801 -> V_804 , F_348 ( V_801 ) ) ;
}
F_273 ( V_5 ) ;
return 0 ;
}
static void F_349 ( struct V_6 * V_7 ,
struct V_62 * V_5 ,
struct V_128 * V_128 )
{
struct V_1 * V_11 = F_2 ( V_5 ) ;
struct V_806 * V_807 = & V_11 -> V_807 ;
int V_672 = 0 ;
struct V_684 * V_636 ;
struct V_637 V_638 ;
F_268 ( V_5 , & V_638 ) ;
F_322 (connector, &conn_iter) {
if ( V_636 -> V_96 -> V_129 != & V_128 -> V_29 )
continue;
F_5 ( V_7 , L_172 , V_636 -> V_8 ) ;
}
F_272 ( & V_638 ) ;
if ( V_11 -> V_450 . V_808 == V_809 )
F_35 ( V_7 , L_510 ) ;
else if ( V_11 -> V_450 . V_808 == V_810 )
F_35 ( V_7 , L_511 ) ;
else if ( V_11 -> V_450 . V_808 == V_811 )
F_35 ( V_7 , L_512 ) ;
else
F_35 ( V_7 , L_513 ) ;
F_35 ( V_7 , L_514 ) ;
if ( F_317 ( V_128 -> V_29 . V_96 ) -> V_812 ) {
struct V_692 * V_693 ;
F_58 ( & V_807 -> V_751 ) ;
F_35 ( V_7 , L_515 ) ;
if ( ! V_807 -> V_704 ) {
F_35 ( V_7 , L_516 ) ;
F_47 ( & V_807 -> V_751 ) ;
return;
}
V_693 = & V_807 -> V_704 -> V_813 -> V_693 ;
F_5 ( V_7 , L_517 ,
V_807 -> V_619 ) ;
F_35 ( V_7 , L_518 ) ;
if ( V_807 -> V_814 == V_815 ) {
F_35 ( V_7 , L_519 ) ;
V_672 = V_693 -> V_694 -> V_672 ;
} else if ( V_807 -> V_814 == V_816 ) {
F_35 ( V_7 , L_520 ) ;
V_672 = V_693 -> V_817 -> V_672 ;
} else {
F_5 ( V_7 , L_521 ,
V_807 -> V_814 ) ;
F_47 ( & V_807 -> V_751 ) ;
return;
}
F_5 ( V_7 , L_522 , V_672 ) ;
F_35 ( V_7 , L_518 ) ;
F_47 ( & V_807 -> V_751 ) ;
} else {
F_35 ( V_7 , L_523 ) ;
}
F_35 ( V_7 , L_397 ) ;
}
static int F_350 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_128 * V_128 ;
int V_818 = 0 ;
F_267 ( V_5 ) ;
F_70 (dev, intel_crtc) {
if ( V_128 -> V_29 . V_96 -> V_88 ) {
V_818 ++ ;
F_5 ( V_7 , L_524 , V_818 ) ;
F_349 ( V_7 , V_5 , V_128 ) ;
}
}
F_273 ( V_5 ) ;
if ( ! V_818 )
F_35 ( V_7 , L_525 ) ;
return 0 ;
}
static int F_351 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_62 * V_5 = & V_11 -> V_63 ;
struct V_681 * V_681 ;
struct V_702 * V_703 ;
struct V_684 * V_636 ;
struct V_637 V_638 ;
F_268 ( V_5 , & V_638 ) ;
F_322 (connector, &conn_iter) {
if ( V_636 -> V_643 != V_713 )
continue;
V_681 = F_352 ( V_636 ) ;
if ( ! V_681 || V_681 -> type == V_714 )
continue;
V_703 = F_353 ( & V_681 -> V_29 ) ;
if ( ! V_703 -> V_704 . V_819 )
continue;
F_5 ( V_7 , L_526 ,
F_354 ( V_703 -> V_706 ) ) ;
F_355 ( V_7 , & V_703 -> V_704 . V_705 ) ;
}
F_272 ( & V_638 ) ;
return 0 ;
}
static T_5 F_356 ( struct V_86 * V_86 ,
const char T_6 * V_203 ,
T_7 V_820 , T_8 * V_821 )
{
char * V_822 ;
int V_685 = 0 ;
struct V_62 * V_5 ;
struct V_684 * V_636 ;
struct V_637 V_638 ;
struct V_639 * V_639 ;
int V_219 = 0 ;
V_5 = ( (struct V_6 * ) V_86 -> V_206 ) -> V_12 ;
if ( V_820 == 0 )
return 0 ;
V_822 = F_357 ( V_203 , V_820 ) ;
if ( F_207 ( V_822 ) )
return F_253 ( V_822 ) ;
F_123 ( L_527 , ( unsigned int ) V_820 ) ;
F_268 ( V_5 , & V_638 ) ;
F_322 (connector, &conn_iter) {
if ( V_636 -> V_643 !=
V_713 )
continue;
if ( V_636 -> V_685 == V_686 &&
V_636 -> V_683 != NULL ) {
V_639 = F_270 ( V_636 -> V_683 ) ;
V_685 = F_358 ( V_822 , 10 , & V_219 ) ;
if ( V_685 < 0 )
break;
F_123 ( L_528 , V_219 ) ;
if ( V_219 == 1 )
V_639 -> V_823 . V_824 = 1 ;
else
V_639 -> V_823 . V_824 = 0 ;
}
}
F_272 ( & V_638 ) ;
F_359 ( V_822 ) ;
if ( V_685 < 0 )
return V_685 ;
* V_821 += V_820 ;
return V_820 ;
}
static int F_360 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_684 * V_636 ;
struct V_637 V_638 ;
struct V_639 * V_639 ;
F_268 ( V_5 , & V_638 ) ;
F_322 (connector, &conn_iter) {
if ( V_636 -> V_643 !=
V_713 )
continue;
if ( V_636 -> V_685 == V_686 &&
V_636 -> V_683 != NULL ) {
V_639 = F_270 ( V_636 -> V_683 ) ;
if ( V_639 -> V_823 . V_824 )
F_35 ( V_7 , L_529 ) ;
else
F_35 ( V_7 , L_530 ) ;
} else
F_35 ( V_7 , L_530 ) ;
}
F_272 ( & V_638 ) ;
return 0 ;
}
static int F_361 ( struct V_213 * V_213 ,
struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
return F_362 ( V_86 , F_360 ,
& V_11 -> V_63 ) ;
}
static int F_363 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_684 * V_636 ;
struct V_637 V_638 ;
struct V_639 * V_639 ;
F_268 ( V_5 , & V_638 ) ;
F_322 (connector, &conn_iter) {
if ( V_636 -> V_643 !=
V_713 )
continue;
if ( V_636 -> V_685 == V_686 &&
V_636 -> V_683 != NULL ) {
V_639 = F_270 ( V_636 -> V_683 ) ;
if ( V_639 -> V_823 . V_825 ==
V_826 )
F_5 ( V_7 , L_531 ,
V_639 -> V_823 . V_827 . V_828 ) ;
else if ( V_639 -> V_823 . V_825 ==
V_829 ) {
F_5 ( V_7 , L_532 ,
V_639 -> V_823 . V_827 . V_673 ) ;
F_5 ( V_7 , L_533 ,
V_639 -> V_823 . V_827 . V_677 ) ;
F_5 ( V_7 , L_534 ,
V_639 -> V_823 . V_827 . V_830 ) ;
}
} else
F_35 ( V_7 , L_530 ) ;
}
F_272 ( & V_638 ) ;
return 0 ;
}
static int F_364 ( struct V_213 * V_213 ,
struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
return F_362 ( V_86 , F_363 ,
& V_11 -> V_63 ) ;
}
static int F_365 ( struct V_6 * V_7 , void * V_10 )
{
struct V_62 * V_5 = V_7 -> V_12 ;
struct V_684 * V_636 ;
struct V_637 V_638 ;
struct V_639 * V_639 ;
F_268 ( V_5 , & V_638 ) ;
F_322 (connector, &conn_iter) {
if ( V_636 -> V_643 !=
V_713 )
continue;
if ( V_636 -> V_685 == V_686 &&
V_636 -> V_683 != NULL ) {
V_639 = F_270 ( V_636 -> V_683 ) ;
F_5 ( V_7 , L_535 , V_639 -> V_823 . V_825 ) ;
} else
F_35 ( V_7 , L_530 ) ;
}
F_272 ( & V_638 ) ;
return 0 ;
}
static int F_366 ( struct V_213 * V_213 ,
struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
return F_362 ( V_86 , F_365 ,
& V_11 -> V_63 ) ;
}
static void F_367 ( struct V_6 * V_7 , const T_13 V_802 [ 8 ] )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_831 ;
int V_832 ;
if ( F_95 ( V_11 ) )
V_832 = 3 ;
else if ( F_108 ( V_11 ) )
V_832 = 1 ;
else if ( F_176 ( V_11 ) )
V_832 = 3 ;
else
V_832 = F_368 ( V_11 ) + 1 ;
F_267 ( V_5 ) ;
for ( V_831 = 0 ; V_831 < V_832 ; V_831 ++ ) {
unsigned int V_833 = V_802 [ V_831 ] ;
if ( F_10 ( V_11 ) >= 9 ||
F_108 ( V_11 ) ||
F_95 ( V_11 ) ||
F_176 ( V_11 ) )
V_833 *= 10 ;
else if ( V_831 > 0 )
V_833 *= 5 ;
F_5 ( V_7 , L_536 ,
V_831 , V_802 [ V_831 ] , V_833 / 10 , V_833 % 10 ) ;
}
F_273 ( V_5 ) ;
}
static int F_369 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_13 * V_834 ;
if ( F_10 ( V_11 ) >= 9 )
V_834 = V_11 -> V_802 . V_835 ;
else
V_834 = V_11 -> V_802 . V_836 ;
F_367 ( V_7 , V_834 ) ;
return 0 ;
}
static int F_370 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_13 * V_834 ;
if ( F_10 ( V_11 ) >= 9 )
V_834 = V_11 -> V_802 . V_835 ;
else
V_834 = V_11 -> V_802 . V_837 ;
F_367 ( V_7 , V_834 ) ;
return 0 ;
}
static int F_371 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
const T_13 * V_834 ;
if ( F_10 ( V_11 ) >= 9 )
V_834 = V_11 -> V_802 . V_835 ;
else
V_834 = V_11 -> V_802 . V_838 ;
F_367 ( V_7 , V_834 ) ;
return 0 ;
}
static int F_372 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
if ( F_10 ( V_11 ) < 5 && ! F_176 ( V_11 ) )
return - V_418 ;
return F_362 ( V_86 , F_369 , V_11 ) ;
}
static int F_373 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
if ( F_374 ( V_11 ) )
return - V_418 ;
return F_362 ( V_86 , F_370 , V_11 ) ;
}
static int F_375 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
if ( F_374 ( V_11 ) )
return - V_418 ;
return F_362 ( V_86 , F_371 , V_11 ) ;
}
static T_5 F_376 ( struct V_86 * V_86 , const char T_6 * V_203 ,
T_7 V_820 , T_8 * V_821 , T_13 V_802 [ 8 ] )
{
struct V_6 * V_7 = V_86 -> V_206 ;
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
T_13 V_839 [ 8 ] = { 0 } ;
int V_832 ;
int V_831 ;
int V_70 ;
char V_209 [ 32 ] ;
if ( F_95 ( V_11 ) )
V_832 = 3 ;
else if ( F_108 ( V_11 ) )
V_832 = 1 ;
else if ( F_176 ( V_11 ) )
V_832 = 3 ;
else
V_832 = F_368 ( V_11 ) + 1 ;
if ( V_820 >= sizeof( V_209 ) )
return - V_609 ;
if ( F_377 ( V_209 , V_203 , V_820 ) )
return - V_840 ;
V_209 [ V_820 ] = '\0' ;
V_70 = sscanf ( V_209 , L_537 ,
& V_839 [ 0 ] , & V_839 [ 1 ] , & V_839 [ 2 ] , & V_839 [ 3 ] ,
& V_839 [ 4 ] , & V_839 [ 5 ] , & V_839 [ 6 ] , & V_839 [ 7 ] ) ;
if ( V_70 != V_832 )
return - V_609 ;
F_267 ( V_5 ) ;
for ( V_831 = 0 ; V_831 < V_832 ; V_831 ++ )
V_802 [ V_831 ] = V_839 [ V_831 ] ;
F_273 ( V_5 ) ;
return V_820 ;
}
static T_5 F_378 ( struct V_86 * V_86 , const char T_6 * V_203 ,
T_7 V_820 , T_8 * V_821 )
{
struct V_6 * V_7 = V_86 -> V_206 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_13 * V_834 ;
if ( F_10 ( V_11 ) >= 9 )
V_834 = V_11 -> V_802 . V_835 ;
else
V_834 = V_11 -> V_802 . V_836 ;
return F_376 ( V_86 , V_203 , V_820 , V_821 , V_834 ) ;
}
static T_5 F_379 ( struct V_86 * V_86 , const char T_6 * V_203 ,
T_7 V_820 , T_8 * V_821 )
{
struct V_6 * V_7 = V_86 -> V_206 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_13 * V_834 ;
if ( F_10 ( V_11 ) >= 9 )
V_834 = V_11 -> V_802 . V_835 ;
else
V_834 = V_11 -> V_802 . V_837 ;
return F_376 ( V_86 , V_203 , V_820 , V_821 , V_834 ) ;
}
static T_5 F_380 ( struct V_86 * V_86 , const char T_6 * V_203 ,
T_7 V_820 , T_8 * V_821 )
{
struct V_6 * V_7 = V_86 -> V_206 ;
struct V_1 * V_11 = V_7 -> V_12 ;
T_13 * V_834 ;
if ( F_10 ( V_11 ) >= 9 )
V_834 = V_11 -> V_802 . V_835 ;
else
V_834 = V_11 -> V_802 . V_838 ;
return F_376 ( V_86 , V_203 , V_820 , V_821 , V_834 ) ;
}
static int
F_381 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
* V_219 = F_382 ( & V_11 -> V_307 ) ;
return 0 ;
}
static int
F_383 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_210 = V_10 ;
struct V_30 * V_31 ;
unsigned int V_209 ;
if ( F_384 ( & V_210 -> V_307 ) )
return - V_841 ;
F_249 (engine, i915, val, tmp) {
V_31 -> V_320 . V_146 = F_75 ( V_31 ) ;
V_31 -> V_320 . V_323 = true ;
}
F_385 ( V_210 , V_219 , L_538 , V_219 ) ;
F_386 ( & V_210 -> V_307 . V_308 ,
V_310 ,
V_842 ) ;
return 0 ;
}
static int
F_387 ( struct V_1 * V_210 ,
unsigned long * V_843 ,
unsigned long V_219 )
{
int V_400 ;
V_400 = F_44 ( & V_210 -> V_63 . V_34 ) ;
if ( V_400 )
return V_400 ;
V_400 = F_388 ( V_210 ,
V_844 |
V_845 ) ;
if ( V_400 )
goto V_846;
* V_843 = V_219 ;
F_47 ( & V_210 -> V_63 . V_34 ) ;
while ( F_389 ( & V_210 -> V_318 . V_847 ) )
;
return 0 ;
V_846:
F_47 ( & V_210 -> V_63 . V_34 ) ;
return V_400 ;
}
static int
F_390 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
* V_219 = V_11 -> V_307 . V_322 ;
return 0 ;
}
static int
F_391 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_210 = V_10 ;
return F_387 ( V_210 , & V_210 -> V_307 . V_322 , V_219 ) ;
}
static int
F_392 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
* V_219 = V_11 -> V_307 . V_848 ;
return 0 ;
}
static int
F_393 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_210 = V_10 ;
V_219 &= F_9 ( V_210 ) -> V_849 ;
F_123 ( L_539 , V_219 ) ;
return F_387 ( V_210 , & V_210 -> V_307 . V_848 , V_219 ) ;
}
static int
F_394 ( void * V_10 , T_3 * V_219 )
{
* V_219 = V_850 ;
return 0 ;
}
static int
F_395 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_11 = V_10 ;
struct V_62 * V_5 = & V_11 -> V_63 ;
int V_70 = 0 ;
F_252 ( L_540 , V_219 ) ;
if ( V_219 & ( V_851 | V_852 ) ) {
V_70 = F_44 ( & V_5 -> V_34 ) ;
if ( V_70 )
return V_70 ;
if ( V_219 & V_851 )
V_70 = F_388 ( V_11 ,
V_845 |
V_844 ) ;
if ( V_219 & V_852 )
F_396 ( V_11 ) ;
F_47 ( & V_5 -> V_34 ) ;
}
F_397 ( V_72 ) ;
if ( V_219 & V_853 )
F_398 ( V_11 , V_854 , V_855 ) ;
if ( V_219 & V_856 )
F_398 ( V_11 , V_854 , V_857 ) ;
if ( V_219 & V_858 )
F_399 ( V_11 ) ;
F_400 () ;
if ( V_219 & V_859 ) {
F_401 () ;
F_402 ( V_11 ) ;
}
return V_70 ;
}
static int
F_403 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 6 )
return - V_418 ;
* V_219 = F_133 ( V_11 , V_11 -> V_230 . V_444 ) ;
return 0 ;
}
static int
F_404 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_860 , V_861 ;
int V_70 ;
if ( F_10 ( V_11 ) < 6 )
return - V_418 ;
F_123 ( L_541 , V_219 ) ;
V_70 = F_44 ( & V_11 -> V_230 . V_231 ) ;
if ( V_70 )
return V_70 ;
V_219 = F_405 ( V_11 , V_219 ) ;
V_860 = V_11 -> V_230 . V_235 ;
V_861 = V_11 -> V_230 . V_236 ;
if ( V_219 < V_861 || V_219 > V_860 || V_219 < V_11 -> V_230 . V_443 ) {
F_47 ( & V_11 -> V_230 . V_231 ) ;
return - V_609 ;
}
V_11 -> V_230 . V_444 = V_219 ;
if ( F_406 ( V_11 , V_219 ) )
F_123 ( L_542 ) ;
F_47 ( & V_11 -> V_230 . V_231 ) ;
return 0 ;
}
static int
F_407 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
if ( F_10 ( V_11 ) < 6 )
return - V_418 ;
* V_219 = F_133 ( V_11 , V_11 -> V_230 . V_443 ) ;
return 0 ;
}
static int
F_408 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_860 , V_861 ;
int V_70 ;
if ( F_10 ( V_11 ) < 6 )
return - V_418 ;
F_123 ( L_543 , V_219 ) ;
V_70 = F_44 ( & V_11 -> V_230 . V_231 ) ;
if ( V_70 )
return V_70 ;
V_219 = F_405 ( V_11 , V_219 ) ;
V_860 = V_11 -> V_230 . V_235 ;
V_861 = V_11 -> V_230 . V_236 ;
if ( V_219 < V_861 ||
V_219 > V_860 || V_219 > V_11 -> V_230 . V_444 ) {
F_47 ( & V_11 -> V_230 . V_231 ) ;
return - V_609 ;
}
V_11 -> V_230 . V_443 = V_219 ;
if ( F_406 ( V_11 , V_219 ) )
F_123 ( L_542 ) ;
F_47 ( & V_11 -> V_230 . V_231 ) ;
return 0 ;
}
static int
F_409 ( void * V_10 , T_3 * V_219 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_862 ;
if ( ! ( F_140 ( V_11 ) || F_141 ( V_11 ) ) )
return - V_418 ;
F_94 ( V_11 ) ;
V_862 = F_79 ( V_863 ) ;
F_111 ( V_11 ) ;
* V_219 = ( V_862 & V_864 ) >> V_865 ;
return 0 ;
}
static int
F_410 ( void * V_10 , T_3 V_219 )
{
struct V_1 * V_11 = V_10 ;
T_4 V_862 ;
if ( ! ( F_140 ( V_11 ) || F_141 ( V_11 ) ) )
return - V_418 ;
if ( V_219 > 3 )
return - V_609 ;
F_94 ( V_11 ) ;
F_123 ( L_544 , V_219 ) ;
V_862 = F_79 ( V_863 ) ;
V_862 &= ~ V_864 ;
V_862 |= ( V_219 << V_865 ) ;
F_179 ( V_863 , V_862 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static void F_411 ( struct V_1 * V_11 ,
struct V_866 * V_867 )
{
int V_868 = 2 ;
int V_869 ;
T_4 V_870 [ V_868 ] , V_871 [ V_868 ] ;
V_870 [ 0 ] = F_79 ( V_872 ) ;
V_870 [ 1 ] = F_79 ( V_873 ) ;
V_871 [ 0 ] = F_79 ( V_874 ) ;
V_871 [ 1 ] = F_79 ( V_875 ) ;
for ( V_869 = 0 ; V_869 < V_868 ; V_869 ++ ) {
unsigned int V_876 ;
if ( V_870 [ V_869 ] & V_877 )
continue;
V_867 -> V_878 = F_208 ( 0 ) ;
V_867 -> V_879 |= F_208 ( V_869 ) ;
V_876 = ( ( V_870 [ V_869 ] & V_880 ) ? 0 : 2 ) +
( ( V_870 [ V_869 ] & V_881 ) ? 0 : 2 ) +
( ( V_870 [ V_869 ] & V_882 ) ? 0 : 2 ) +
( ( V_871 [ V_869 ] & V_883 ) ? 0 : 2 ) ;
V_867 -> V_884 += V_876 ;
V_867 -> V_885 = F_412 (unsigned int,
sseu->eu_per_subslice, eu_cnt) ;
}
}
static void F_413 ( struct V_1 * V_11 ,
struct V_866 * V_867 )
{
int V_886 = 3 , V_868 = 4 ;
int V_887 , V_869 ;
T_4 V_888 [ V_886 ] , V_889 [ 2 * V_886 ] , V_890 [ 2 ] ;
if ( F_134 ( V_11 ) ) {
V_886 = 1 ;
V_868 = 3 ;
}
for ( V_887 = 0 ; V_887 < V_886 ; V_887 ++ ) {
V_888 [ V_887 ] = F_79 ( F_414 ( V_887 ) ) ;
V_889 [ 2 * V_887 ] = F_79 ( F_415 ( V_887 ) ) ;
V_889 [ 2 * V_887 + 1 ] = F_79 ( F_416 ( V_887 ) ) ;
}
V_890 [ 0 ] = V_891 |
V_892 |
V_893 |
V_894 ;
V_890 [ 1 ] = V_895 |
V_896 |
V_897 |
V_898 ;
for ( V_887 = 0 ; V_887 < V_886 ; V_887 ++ ) {
if ( ( V_888 [ V_887 ] & V_899 ) == 0 )
continue;
V_867 -> V_878 |= F_208 ( V_887 ) ;
if ( F_144 ( V_11 ) || F_417 ( V_11 ) )
V_867 -> V_879 =
F_9 ( V_11 ) -> V_867 . V_879 ;
for ( V_869 = 0 ; V_869 < V_868 ; V_869 ++ ) {
unsigned int V_876 ;
if ( F_134 ( V_11 ) ) {
if ( ! ( V_888 [ V_887 ] & ( F_418 ( V_869 ) ) ) )
continue;
V_867 -> V_879 |= F_208 ( V_869 ) ;
}
V_876 = 2 * F_419 ( V_889 [ 2 * V_887 + V_869 / 2 ] &
V_890 [ V_869 % 2 ] ) ;
V_867 -> V_884 += V_876 ;
V_867 -> V_885 = F_412 (unsigned int,
sseu->eu_per_subslice,
eu_cnt) ;
}
}
}
static void F_420 ( struct V_1 * V_11 ,
struct V_866 * V_867 )
{
T_4 V_900 = F_79 ( V_901 ) ;
int V_887 ;
V_867 -> V_878 = V_900 & V_902 ;
if ( V_867 -> V_878 ) {
V_867 -> V_879 = F_9 ( V_11 ) -> V_867 . V_879 ;
V_867 -> V_885 =
F_9 ( V_11 ) -> V_867 . V_885 ;
V_867 -> V_884 = V_867 -> V_885 *
F_421 ( V_867 ) ;
for ( V_887 = 0 ; V_887 < F_422 ( V_867 -> V_878 ) ; V_887 ++ ) {
T_12 V_903 =
F_9 ( V_11 ) -> V_867 . V_903 [ V_887 ] ;
V_867 -> V_884 -= F_423 ( V_903 ) ;
}
}
}
static void F_424 ( struct V_6 * V_7 , bool V_904 ,
const struct V_866 * V_867 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
const char * type = V_904 ? L_545 : L_546 ;
F_5 ( V_7 , L_547 , type ,
V_867 -> V_878 ) ;
F_5 ( V_7 , L_548 , type ,
F_423 ( V_867 -> V_878 ) ) ;
F_5 ( V_7 , L_549 , type ,
F_421 ( V_867 ) ) ;
F_5 ( V_7 , L_550 , type ,
V_867 -> V_879 ) ;
F_5 ( V_7 , L_551 , type ,
F_423 ( V_867 -> V_879 ) ) ;
F_5 ( V_7 , L_552 , type ,
V_867 -> V_884 ) ;
F_5 ( V_7 , L_553 , type ,
V_867 -> V_885 ) ;
if ( ! V_904 )
return;
F_5 ( V_7 , L_554 , F_6 ( F_425 ( V_11 ) ) ) ;
if ( F_425 ( V_11 ) )
F_5 ( V_7 , L_555 , V_867 -> V_905 ) ;
F_5 ( V_7 , L_556 ,
F_6 ( V_867 -> V_906 ) ) ;
F_5 ( V_7 , L_557 ,
F_6 ( V_867 -> V_907 ) ) ;
F_5 ( V_7 , L_558 ,
F_6 ( V_867 -> V_908 ) ) ;
}
static int F_426 ( struct V_6 * V_7 , void * V_220 )
{
struct V_1 * V_11 = F_1 ( V_7 -> V_12 ) ;
struct V_866 V_867 ;
if ( F_10 ( V_11 ) < 8 )
return - V_418 ;
F_35 ( V_7 , L_559 ) ;
F_424 ( V_7 , true , & F_9 ( V_11 ) -> V_867 ) ;
F_35 ( V_7 , L_560 ) ;
memset ( & V_867 , 0 , sizeof( V_867 ) ) ;
F_94 ( V_11 ) ;
if ( F_95 ( V_11 ) ) {
F_411 ( V_11 , & V_867 ) ;
} else if ( F_138 ( V_11 ) ) {
F_420 ( V_11 , & V_867 ) ;
} else if ( F_10 ( V_11 ) >= 9 ) {
F_413 ( V_11 , & V_867 ) ;
}
F_111 ( V_11 ) ;
F_424 ( V_7 , false , & V_867 ) ;
return 0 ;
}
static int F_427 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
if ( F_10 ( V_11 ) < 6 )
return 0 ;
F_94 ( V_11 ) ;
F_135 ( V_11 , V_264 ) ;
return 0 ;
}
static int F_428 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
struct V_1 * V_11 = V_213 -> V_214 ;
if ( F_10 ( V_11 ) < 6 )
return 0 ;
F_139 ( V_11 , V_264 ) ;
F_111 ( V_11 ) ;
return 0 ;
}
static int F_429 ( struct V_6 * V_7 , void * V_10 )
{
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_909 * V_910 = & V_11 -> V_910 ;
F_5 ( V_7 , L_561 , V_910 -> V_911 ) ;
F_5 ( V_7 , L_562 ,
F_6 ( F_153 ( & V_910 -> V_912 ) ) ) ;
return 0 ;
}
static T_5 F_430 ( struct V_86 * V_86 ,
const char T_6 * V_203 , T_7 V_820 ,
T_8 * V_821 )
{
struct V_6 * V_7 = V_86 -> V_206 ;
struct V_1 * V_11 = V_7 -> V_12 ;
struct V_909 * V_910 = & V_11 -> V_910 ;
unsigned int V_913 ;
int V_164 ;
char * V_914 ;
char V_209 [ 16 ] ;
if ( V_820 >= sizeof( V_209 ) )
return - V_609 ;
if ( F_377 ( V_209 , V_203 , V_820 ) )
return - V_840 ;
V_209 [ V_820 ] = '\0' ;
V_914 = strchr ( V_209 , '\n' ) ;
if ( V_914 )
* V_914 = '\0' ;
if ( strcmp ( V_209 , L_563 ) == 0 )
V_913 = V_915 ;
else if ( F_431 ( V_209 , 10 , & V_913 ) != 0 )
return - V_609 ;
if ( V_913 > 0 )
F_432 ( L_564 ,
V_913 ) ;
else
F_432 ( L_565 ) ;
F_73 ( & V_11 -> V_916 ) ;
V_910 -> V_911 = V_913 ;
F_433 (i)
V_910 -> V_77 [ V_164 ] . V_68 = 0 ;
F_82 ( & V_11 -> V_916 ) ;
F_389 ( & V_11 -> V_910 . V_912 ) ;
return V_820 ;
}
static int F_434 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
return F_362 ( V_86 , F_429 , V_213 -> V_214 ) ;
}
int F_435 ( struct V_1 * V_11 )
{
struct V_917 * V_4 = V_11 -> V_63 . V_689 ;
struct V_918 * V_919 ;
int V_70 , V_164 ;
V_919 = F_436 ( L_566 , V_920 ,
V_4 -> V_921 , F_2 ( V_4 -> V_5 ) ,
& V_922 ) ;
if ( ! V_919 )
return - V_73 ;
V_70 = F_437 ( V_4 ) ;
if ( V_70 )
return V_70 ;
for ( V_164 = 0 ; V_164 < F_54 ( V_923 ) ; V_164 ++ ) {
V_919 = F_436 ( V_923 [ V_164 ] . V_8 ,
V_924 | V_925 ,
V_4 -> V_921 ,
F_2 ( V_4 -> V_5 ) ,
V_923 [ V_164 ] . V_926 ) ;
if ( ! V_919 )
return - V_73 ;
}
return F_438 ( V_927 ,
V_928 ,
V_4 -> V_921 , V_4 ) ;
}
static int F_439 ( struct V_6 * V_7 , void * V_10 )
{
struct V_684 * V_636 = V_7 -> V_12 ;
struct V_639 * V_639 =
F_270 ( & F_352 ( V_636 ) -> V_29 ) ;
T_14 V_211 [ 16 ] ;
T_5 V_400 ;
int V_164 ;
if ( V_636 -> V_685 != V_686 )
return - V_418 ;
for ( V_164 = 0 ; V_164 < F_54 ( V_929 ) ; V_164 ++ ) {
const struct V_930 * V_61 = & V_929 [ V_164 ] ;
T_7 V_26 = V_61 -> V_804 ? V_61 -> V_804 - V_61 -> V_46 + 1 : ( V_61 -> V_26 ? : 1 ) ;
if ( V_61 -> V_931 &&
V_636 -> V_643 != V_644 )
continue;
if ( F_440 ( V_26 > sizeof( V_211 ) ) )
continue;
V_400 = F_441 ( & V_639 -> V_699 , V_61 -> V_46 , V_211 , V_26 ) ;
if ( V_400 <= 0 ) {
F_442 ( L_567 ,
V_26 , V_61 -> V_46 , V_400 ) ;
continue;
}
F_5 ( V_7 , L_568 , V_61 -> V_46 , ( int ) V_26 , V_211 ) ;
}
return 0 ;
}
static int F_443 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
return F_362 ( V_86 , F_439 , V_213 -> V_214 ) ;
}
static int F_444 ( struct V_6 * V_7 , void * V_10 )
{
struct V_684 * V_636 = V_7 -> V_12 ;
struct V_639 * V_639 =
F_270 ( & F_352 ( V_636 ) -> V_29 ) ;
if ( V_636 -> V_685 != V_686 )
return - V_418 ;
F_5 ( V_7 , L_569 ,
V_639 -> V_932 ) ;
F_5 ( V_7 , L_570 ,
V_639 -> V_933 ) ;
F_5 ( V_7 , L_571 ,
V_639 -> V_934 ) ;
F_5 ( V_7 , L_572 ,
V_639 -> V_935 ) ;
return 0 ;
}
static int F_445 ( struct V_213 * V_213 , struct V_86 * V_86 )
{
return F_362 ( V_86 , F_444 , V_213 -> V_214 ) ;
}
int F_446 ( struct V_684 * V_636 )
{
struct V_918 * V_936 = V_636 -> V_937 ;
if ( ! V_936 )
return - V_418 ;
if ( V_636 -> V_643 == V_713 ||
V_636 -> V_643 == V_644 )
F_436 ( L_573 , V_924 , V_936 ,
V_636 , & V_938 ) ;
if ( V_636 -> V_643 == V_644 )
F_436 ( L_574 , V_924 , V_936 ,
V_636 , & V_939 ) ;
return 0 ;
}
