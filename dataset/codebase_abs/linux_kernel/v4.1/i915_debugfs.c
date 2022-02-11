static const char * F_1 ( int V_1 )
{
return V_1 ? L_1 : L_2 ;
}
static int
F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
const void * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 == NULL ) {
F_4 ( V_5 ) ;
return - V_10 ;
}
V_8 -> V_3 = V_3 ;
V_8 -> V_11 = V_5 ;
V_8 -> V_12 = ( void * ) V_6 ;
F_5 ( & V_3 -> V_13 ) ;
F_6 ( & V_8 -> V_14 , & V_3 -> V_15 ) ;
F_7 ( & V_3 -> V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
const struct V_22 * V_23 = F_9 ( V_21 ) ;
F_10 ( V_17 , L_3 , V_23 -> V_24 ) ;
F_10 ( V_17 , L_4 , F_11 ( V_21 ) ) ;
#define F_12 ( T_1 ) seq_printf(m, #x ": %s\n", yesno(info->x))
#define F_13 ;
F_14 ( F_12 , F_13 ) ;
#undef F_12
#undef F_13
return 0 ;
}
static const char * F_15 ( struct V_25 * V_26 )
{
if ( F_16 ( V_26 ) )
return L_5 ;
else
return L_6 ;
}
static const char * F_17 ( struct V_25 * V_26 )
{
switch ( V_26 -> V_27 ) {
default:
case V_28 : return L_6 ;
case V_29 : return L_7 ;
case V_30 : return L_8 ;
}
}
static inline const char * F_18 ( struct V_25 * V_26 )
{
return F_19 ( V_26 ) ? L_9 : L_6 ;
}
static void
F_20 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
struct V_31 * V_32 ;
int V_33 = 0 ;
F_10 ( V_17 , L_10 ,
& V_26 -> V_34 ,
F_15 ( V_26 ) ,
F_17 ( V_26 ) ,
F_18 ( V_26 ) ,
V_26 -> V_34 . V_35 / 1024 ,
V_26 -> V_34 . V_36 ,
V_26 -> V_34 . V_37 ,
F_21 ( V_26 -> V_38 ) ,
F_21 ( V_26 -> V_39 ) ,
F_21 ( V_26 -> V_40 ) ,
F_22 ( F_23 ( V_26 -> V_34 . V_21 ) , V_26 -> V_41 ) ,
V_26 -> V_42 ? L_11 : L_12 ,
V_26 -> V_43 == V_44 ? L_13 : L_12 ) ;
if ( V_26 -> V_34 . V_45 )
F_10 ( V_17 , L_14 , V_26 -> V_34 . V_45 ) ;
F_24 (vma, &obj->vma_list, vma_link) {
if ( V_32 -> V_33 > 0 )
V_33 ++ ;
}
F_10 ( V_17 , L_15 , V_33 ) ;
if ( V_26 -> V_46 )
F_10 ( V_17 , L_16 ) ;
if ( V_26 -> V_47 != V_48 )
F_10 ( V_17 , L_17 , V_26 -> V_47 ) ;
F_24 (vma, &obj->vma_list, vma_link) {
if ( ! F_25 ( V_32 -> V_49 ) )
F_26 ( V_17 , L_18 ) ;
else
F_26 ( V_17 , L_19 ) ;
F_10 ( V_17 , L_20 ,
V_32 -> V_8 . V_50 , V_32 -> V_8 . V_35 ,
V_32 -> V_51 . type ) ;
}
if ( V_26 -> V_52 )
F_10 ( V_17 , L_21 , V_26 -> V_52 -> V_50 ) ;
if ( V_26 -> V_53 || V_26 -> V_54 ) {
char V_55 [ 3 ] , * V_56 = V_55 ;
if ( V_26 -> V_53 )
* V_56 ++ = 'p' ;
if ( V_26 -> V_54 )
* V_56 ++ = 'f' ;
* V_56 = '\0' ;
F_10 ( V_17 , L_22 , V_55 ) ;
}
if ( V_26 -> V_38 != NULL )
F_10 ( V_17 , L_23 ,
F_27 ( V_26 -> V_38 ) -> V_45 ) ;
if ( V_26 -> V_57 )
F_10 ( V_17 , L_24 , V_26 -> V_57 ) ;
}
static void F_28 ( struct V_16 * V_17 , struct V_58 * V_59 )
{
F_29 ( V_17 , V_59 -> V_60 . V_61 ? 'I' : 'i' ) ;
F_29 ( V_17 , V_59 -> V_62 ? 'R' : 'r' ) ;
F_29 ( V_17 , ' ' ) ;
}
static int F_30 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_63 * V_64 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_68 * V_49 = & V_66 -> V_69 . V_34 ;
struct V_31 * V_32 ;
T_3 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
switch ( V_14 ) {
case V_75 :
F_26 ( V_17 , L_25 ) ;
V_64 = & V_49 -> V_76 ;
break;
case V_77 :
F_26 ( V_17 , L_26 ) ;
V_64 = & V_49 -> V_78 ;
break;
default:
F_7 ( & V_21 -> V_74 ) ;
return - V_79 ;
}
V_70 = V_71 = V_72 = 0 ;
F_24 (vma, head, mm_list) {
F_10 ( V_17 , L_27 ) ;
F_20 ( V_17 , V_32 -> V_26 ) ;
F_10 ( V_17 , L_28 ) ;
V_70 += V_32 -> V_26 -> V_34 . V_35 ;
V_71 += V_32 -> V_8 . V_35 ;
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_32 ( void * V_80 ,
struct V_63 * V_81 , struct V_63 * V_82 )
{
struct V_25 * V_83 =
F_33 ( V_81 , struct V_25 , V_84 ) ;
struct V_25 * V_85 =
F_33 ( V_82 , struct V_25 , V_84 ) ;
return V_83 -> V_52 -> V_50 - V_85 -> V_52 -> V_50 ;
}
static int F_34 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 ;
T_3 V_70 , V_71 ;
F_35 ( V_52 ) ;
int V_72 , V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_70 = V_71 = V_72 = 0 ;
F_24 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_52 == NULL )
continue;
F_6 ( & V_26 -> V_84 , & V_52 ) ;
V_70 += V_26 -> V_34 . V_35 ;
V_71 += F_36 ( V_26 ) ;
V_72 ++ ;
}
F_24 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_26 -> V_52 == NULL )
continue;
F_6 ( & V_26 -> V_84 , & V_52 ) ;
V_70 += V_26 -> V_34 . V_35 ;
V_72 ++ ;
}
F_37 ( NULL , & V_52 , F_32 ) ;
F_26 ( V_17 , L_30 ) ;
while ( ! F_38 ( & V_52 ) ) {
V_26 = F_39 ( & V_52 , F_40 ( * V_26 ) , V_84 ) ;
F_26 ( V_17 , L_27 ) ;
F_20 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
F_41 ( & V_26 -> V_84 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_42 ( int V_86 , void * V_87 , void * V_18 )
{
struct V_25 * V_26 = V_87 ;
struct V_88 * V_89 = V_18 ;
struct V_31 * V_32 ;
V_89 -> V_72 ++ ;
V_89 -> V_90 += V_26 -> V_34 . V_35 ;
if ( V_26 -> V_34 . V_45 || V_26 -> V_34 . V_91 )
V_89 -> V_92 += V_26 -> V_34 . V_35 ;
if ( F_43 ( V_26 -> V_34 . V_21 ) ) {
F_24 (vma, &obj->vma_list, vma_link) {
struct V_93 * V_94 ;
if ( ! F_44 ( & V_32 -> V_8 ) )
continue;
if ( F_25 ( V_32 -> V_49 ) ) {
V_89 -> V_95 += V_26 -> V_34 . V_35 ;
continue;
}
V_94 = F_33 ( V_32 -> V_49 , struct V_93 , V_34 ) ;
if ( V_94 -> V_96 != V_89 -> V_96 )
continue;
if ( V_26 -> V_97 )
V_89 -> V_97 += V_26 -> V_34 . V_35 ;
else
V_89 -> V_98 += V_26 -> V_34 . V_35 ;
return 0 ;
}
} else {
if ( F_45 ( V_26 ) ) {
V_89 -> V_95 += V_26 -> V_34 . V_35 ;
if ( V_26 -> V_97 )
V_89 -> V_97 += V_26 -> V_34 . V_35 ;
else
V_89 -> V_98 += V_26 -> V_34 . V_35 ;
return 0 ;
}
}
if ( ! F_38 ( & V_26 -> V_99 ) )
V_89 -> V_100 += V_26 -> V_34 . V_35 ;
return 0 ;
}
static void F_46 ( struct V_16 * V_17 ,
struct V_65 * V_66 )
{
struct V_25 * V_26 ;
struct V_88 V_89 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
F_24 (obj,
&dev_priv->mm.batch_pool.cache_list,
batch_pool_list)
F_42 ( 0 , V_26 , & V_89 ) ;
F_47 ( V_17 , L_31 , V_89 ) ;
}
static int F_48 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_72 , V_101 , V_102 ;
T_3 V_35 , V_103 , V_104 ;
struct V_25 * V_26 ;
struct V_68 * V_49 = & V_66 -> V_69 . V_34 ;
struct V_105 * V_106 ;
struct V_31 * V_32 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_32 ,
V_66 -> V_107 . V_108 ,
V_66 -> V_107 . V_109 ) ;
V_35 = V_72 = V_103 = V_101 = 0 ;
F_49 ( & V_66 -> V_107 . V_110 , V_99 ) ;
F_10 ( V_17 , L_33 ,
V_72 , V_101 , V_35 , V_103 ) ;
V_35 = V_72 = V_103 = V_101 = 0 ;
F_50 ( & V_49 -> V_76 , V_111 ) ;
F_10 ( V_17 , L_34 ,
V_72 , V_101 , V_35 , V_103 ) ;
V_35 = V_72 = V_103 = V_101 = 0 ;
F_50 ( & V_49 -> V_78 , V_111 ) ;
F_10 ( V_17 , L_35 ,
V_72 , V_101 , V_35 , V_103 ) ;
V_35 = V_72 = V_104 = V_102 = 0 ;
F_24 (obj, &dev_priv->mm.unbound_list, global_list) {
V_35 += V_26 -> V_34 . V_35 , ++ V_72 ;
if ( V_26 -> V_43 == V_44 )
V_104 += V_26 -> V_34 . V_35 , ++ V_102 ;
}
F_10 ( V_17 , L_36 , V_72 , V_35 ) ;
V_35 = V_72 = V_103 = V_101 = 0 ;
F_24 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_54 ) {
V_35 += F_36 ( V_26 ) ;
++ V_72 ;
}
if ( V_26 -> V_53 ) {
V_103 += F_36 ( V_26 ) ;
++ V_101 ;
}
if ( V_26 -> V_43 == V_44 ) {
V_104 += V_26 -> V_34 . V_35 ;
++ V_102 ;
}
}
F_10 ( V_17 , L_37 ,
V_102 , V_104 ) ;
F_10 ( V_17 , L_38 ,
V_101 , V_103 ) ;
F_10 ( V_17 , L_39 ,
V_72 , V_35 ) ;
F_10 ( V_17 , L_40 ,
V_66 -> V_69 . V_34 . V_90 ,
V_66 -> V_69 . V_112 - V_66 -> V_69 . V_34 . V_50 ) ;
F_29 ( V_17 , '\n' ) ;
F_46 ( V_17 , V_66 ) ;
F_29 ( V_17 , '\n' ) ;
F_51 (file, &dev->filelist, lhead) {
struct V_88 V_89 ;
struct V_113 * V_114 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_96 = V_106 -> V_115 ;
F_52 ( & V_106 -> V_116 ) ;
F_53 ( & V_106 -> V_117 , F_42 , & V_89 ) ;
F_54 ( & V_106 -> V_116 ) ;
F_55 () ;
V_114 = F_56 ( V_106 -> V_118 , V_119 ) ;
F_47 ( V_17 , V_114 ? V_114 -> V_120 : L_41 , V_89 ) ;
F_57 () ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_58 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 ;
T_3 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_70 = V_71 = V_72 = 0 ;
F_24 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_14 == V_121 && ! F_16 ( V_26 ) )
continue;
F_26 ( V_17 , L_27 ) ;
F_20 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
V_70 += V_26 -> V_34 . V_35 ;
V_71 += F_36 ( V_26 ) ;
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_59 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_60 (dev, crtc) {
const char V_124 = F_61 ( V_123 -> V_124 ) ;
const char V_125 = F_62 ( V_123 -> V_125 ) ;
struct V_126 * V_127 ;
F_63 ( & V_21 -> V_128 ) ;
V_127 = V_123 -> V_129 ;
if ( V_127 == NULL ) {
F_10 ( V_17 , L_42 ,
V_124 , V_125 ) ;
} else {
T_4 V_130 ;
if ( F_64 ( & V_127 -> V_131 ) < V_132 ) {
F_10 ( V_17 , L_43 ,
V_124 , V_125 ) ;
} else {
F_10 ( V_17 , L_44 ,
V_124 , V_125 ) ;
}
if ( V_127 -> V_133 ) {
struct V_134 * V_135 =
F_27 ( V_127 -> V_133 ) ;
F_10 ( V_17 , L_45 ,
V_135 -> V_45 ,
F_21 ( V_127 -> V_133 ) ,
V_66 -> V_136 ,
V_135 -> V_137 ( V_135 , true ) ,
F_65 ( V_127 -> V_133 , true ) ) ;
} else
F_10 ( V_17 , L_46 ) ;
F_10 ( V_17 , L_47 ,
V_127 -> V_138 ,
V_127 -> V_139 ,
F_66 ( & V_123 -> V_34 ) ) ;
if ( V_127 -> V_140 )
F_26 ( V_17 , L_48 ) ;
else
F_26 ( V_17 , L_49 ) ;
F_10 ( V_17 , L_50 , F_64 ( & V_127 -> V_131 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 4 )
V_130 = F_67 ( F_68 ( F_69 ( V_123 -> V_125 ) ) ) ;
else
V_130 = F_68 ( F_70 ( V_123 -> V_125 ) ) ;
F_10 ( V_17 , L_51 , V_130 ) ;
if ( V_127 -> V_141 ) {
F_10 ( V_17 , L_52 , ( long ) V_127 -> V_142 ) ;
F_10 ( V_17 , L_53 , V_130 == V_127 -> V_142 ) ;
}
}
F_71 ( & V_21 -> V_128 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_72 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 ;
int V_72 = 0 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_26 ( V_17 , L_54 ) ;
F_24 (obj,
&dev_priv->mm.batch_pool.cache_list,
batch_pool_list) {
F_26 ( V_17 , L_27 ) ;
F_20 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
V_72 ++ ;
}
F_10 ( V_17 , L_55 , V_72 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_73 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_143 * V_144 ;
int V_73 , V_72 , V_145 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_72 = 0 ;
F_74 (ring, dev_priv, i) {
if ( F_38 ( & V_135 -> V_146 ) )
continue;
F_10 ( V_17 , L_56 , V_135 -> V_45 ) ;
F_24 (gem_request,
&ring->request_list,
list) {
F_10 ( V_17 , L_57 ,
V_144 -> V_147 ,
( int ) ( V_148 - V_144 -> V_149 ) ) ;
}
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
if ( V_72 == 0 )
F_26 ( V_17 , L_58 ) ;
return 0 ;
}
static void F_75 ( struct V_16 * V_17 ,
struct V_134 * V_135 )
{
if ( V_135 -> V_137 ) {
F_10 ( V_17 , L_59 ,
V_135 -> V_45 , V_135 -> V_137 ( V_135 , false ) ) ;
}
}
static int F_76 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
int V_73 , V_145 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
F_74 (ring, dev_priv, i)
F_75 ( V_17 , V_135 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_79 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
int V_73 , V_145 , V_124 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
if ( F_80 ( V_21 ) ) {
F_10 ( V_17 , L_60 ,
F_68 ( V_150 ) ) ;
F_10 ( V_17 , L_61 ,
F_68 ( V_151 ) ) ;
F_10 ( V_17 , L_62 ,
F_68 ( V_152 ) ) ;
F_10 ( V_17 , L_63 ,
F_68 ( V_153 ) ) ;
F_10 ( V_17 , L_64 ,
F_68 ( V_154 ) ) ;
F_81 (dev_priv, pipe)
F_10 ( V_17 , L_65 ,
F_61 ( V_124 ) ,
F_68 ( F_82 ( V_124 ) ) ) ;
F_10 ( V_17 , L_66 ,
F_68 ( V_155 ) ) ;
F_10 ( V_17 , L_67 ,
F_68 ( V_156 ) ) ;
F_10 ( V_17 , L_68 ,
F_68 ( V_157 ) ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
F_10 ( V_17 , L_69 ,
V_145 , F_68 ( F_83 ( V_145 ) ) ) ;
F_10 ( V_17 , L_70 ,
V_145 , F_68 ( F_84 ( V_145 ) ) ) ;
F_10 ( V_17 , L_71 ,
V_145 , F_68 ( F_85 ( V_145 ) ) ) ;
}
F_10 ( V_17 , L_72 ,
F_68 ( V_158 ) ) ;
F_10 ( V_17 , L_73 ,
F_68 ( V_159 ) ) ;
F_10 ( V_17 , L_74 ,
F_68 ( V_160 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_10 ( V_17 , L_60 ,
F_68 ( V_150 ) ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
F_10 ( V_17 , L_69 ,
V_145 , F_68 ( F_83 ( V_145 ) ) ) ;
F_10 ( V_17 , L_70 ,
V_145 , F_68 ( F_84 ( V_145 ) ) ) ;
F_10 ( V_17 , L_71 ,
V_145 , F_68 ( F_85 ( V_145 ) ) ) ;
}
F_81 (dev_priv, pipe) {
if ( ! F_86 ( V_66 ,
F_87 ( V_124 ) ) ) {
F_10 ( V_17 , L_75 ,
F_61 ( V_124 ) ) ;
continue;
}
F_10 ( V_17 , L_76 ,
F_61 ( V_124 ) ,
F_68 ( F_88 ( V_124 ) ) ) ;
F_10 ( V_17 , L_77 ,
F_61 ( V_124 ) ,
F_68 ( F_89 ( V_124 ) ) ) ;
F_10 ( V_17 , L_78 ,
F_61 ( V_124 ) ,
F_68 ( F_90 ( V_124 ) ) ) ;
}
F_10 ( V_17 , L_79 ,
F_68 ( V_161 ) ) ;
F_10 ( V_17 , L_80 ,
F_68 ( V_162 ) ) ;
F_10 ( V_17 , L_81 ,
F_68 ( V_163 ) ) ;
F_10 ( V_17 , L_82 ,
F_68 ( V_164 ) ) ;
F_10 ( V_17 , L_83 ,
F_68 ( V_165 ) ) ;
F_10 ( V_17 , L_84 ,
F_68 ( V_166 ) ) ;
F_10 ( V_17 , L_72 ,
F_68 ( V_158 ) ) ;
F_10 ( V_17 , L_73 ,
F_68 ( V_159 ) ) ;
F_10 ( V_17 , L_74 ,
F_68 ( V_160 ) ) ;
} else if ( F_91 ( V_21 ) ) {
F_10 ( V_17 , L_61 ,
F_68 ( V_151 ) ) ;
F_10 ( V_17 , L_62 ,
F_68 ( V_152 ) ) ;
F_10 ( V_17 , L_63 ,
F_68 ( V_153 ) ) ;
F_10 ( V_17 , L_64 ,
F_68 ( V_154 ) ) ;
F_81 (dev_priv, pipe)
F_10 ( V_17 , L_65 ,
F_61 ( V_124 ) ,
F_68 ( F_82 ( V_124 ) ) ) ;
F_10 ( V_17 , L_85 ,
F_68 ( V_167 ) ) ;
F_10 ( V_17 , L_86 ,
F_68 ( V_168 ) ) ;
F_10 ( V_17 , L_87 ,
F_68 ( V_169 ) ) ;
F_10 ( V_17 , L_88 ,
F_68 ( V_170 ) ) ;
F_10 ( V_17 , L_89 ,
F_68 ( V_171 ) ) ;
F_10 ( V_17 , L_90 ,
F_68 ( V_172 ) ) ;
F_10 ( V_17 , L_91 ,
F_68 ( V_173 ) ) ;
F_10 ( V_17 , L_66 ,
F_68 ( V_155 ) ) ;
F_10 ( V_17 , L_67 ,
F_68 ( V_156 ) ) ;
F_10 ( V_17 , L_68 ,
F_68 ( V_157 ) ) ;
} else if ( ! F_92 ( V_21 ) ) {
F_10 ( V_17 , L_92 ,
F_68 ( V_174 ) ) ;
F_10 ( V_17 , L_93 ,
F_68 ( V_175 ) ) ;
F_10 ( V_17 , L_94 ,
F_68 ( V_176 ) ) ;
F_81 (dev_priv, pipe)
F_10 ( V_17 , L_95 ,
F_61 ( V_124 ) ,
F_68 ( F_82 ( V_124 ) ) ) ;
} else {
F_10 ( V_17 , L_96 ,
F_68 ( V_177 ) ) ;
F_10 ( V_17 , L_97 ,
F_68 ( V_178 ) ) ;
F_10 ( V_17 , L_98 ,
F_68 ( V_179 ) ) ;
F_10 ( V_17 , L_99 ,
F_68 ( V_180 ) ) ;
F_10 ( V_17 , L_100 ,
F_68 ( V_181 ) ) ;
F_10 ( V_17 , L_101 ,
F_68 ( V_182 ) ) ;
F_10 ( V_17 , L_102 ,
F_68 ( V_168 ) ) ;
F_10 ( V_17 , L_103 ,
F_68 ( V_169 ) ) ;
F_10 ( V_17 , L_104 ,
F_68 ( V_170 ) ) ;
}
F_74 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_105 ,
V_135 -> V_45 , F_93 ( V_135 ) ) ;
}
F_75 ( V_17 , V_135 ) ;
}
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_94 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_145 , V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_106 , V_66 -> V_183 ) ;
F_10 ( V_17 , L_107 , V_66 -> V_184 ) ;
for ( V_145 = 0 ; V_145 < V_66 -> V_184 ; V_145 ++ ) {
struct V_25 * V_26 = V_66 -> V_185 [ V_145 ] . V_26 ;
F_10 ( V_17 , L_108 ,
V_145 , V_66 -> V_185 [ V_145 ] . V_33 ) ;
if ( V_26 == NULL )
F_26 ( V_17 , L_109 ) ;
else
F_20 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_95 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
const T_4 * V_186 ;
int V_145 ;
V_135 = & V_66 -> V_135 [ ( T_2 ) V_8 -> V_12 -> V_18 ] ;
V_186 = V_135 -> V_187 . V_188 ;
if ( V_186 == NULL )
return 0 ;
for ( V_145 = 0 ; V_145 < 4096 / sizeof( T_4 ) / 4 ; V_145 += 4 ) {
F_10 ( V_17 , L_110 ,
V_145 * 4 ,
V_186 [ V_145 ] , V_186 [ V_145 + 1 ] , V_186 [ V_145 + 2 ] , V_186 [ V_145 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_96 ( struct V_106 * V_189 ,
const char T_6 * V_190 ,
T_3 V_191 ,
T_7 * V_192 )
{
struct V_193 * V_194 = V_189 -> V_195 ;
struct V_20 * V_21 = V_194 -> V_21 ;
int V_73 ;
F_97 ( L_111 ) ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_98 ( V_21 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_191 ;
}
static int F_99 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
struct V_193 * V_194 ;
V_194 = F_100 ( sizeof( * V_194 ) , V_9 ) ;
if ( ! V_194 )
return - V_10 ;
V_194 -> V_21 = V_21 ;
F_101 ( V_21 , V_194 ) ;
V_106 -> V_195 = V_194 ;
return 0 ;
}
static int F_102 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_193 * V_194 = V_106 -> V_195 ;
F_103 ( V_194 ) ;
F_104 ( V_194 ) ;
return 0 ;
}
static T_5 F_105 ( struct V_106 * V_106 , char T_6 * V_198 ,
T_3 V_72 , T_7 * V_199 )
{
struct V_193 * V_194 = V_106 -> V_195 ;
struct V_200 V_201 ;
T_7 V_202 = 0 ;
T_5 V_203 = 0 ;
int V_73 ;
V_73 = F_106 ( & V_201 , F_23 ( V_194 -> V_21 ) , V_72 , * V_199 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_107 ( & V_201 , V_194 ) ;
if ( V_73 )
goto V_204;
V_203 = F_108 ( V_198 , V_72 , & V_202 ,
V_201 . V_205 ,
V_201 . V_206 ) ;
if ( V_203 < 0 )
V_73 = V_203 ;
else
* V_199 = V_201 . V_50 + V_203 ;
V_204:
F_109 ( & V_201 ) ;
return V_73 ? : V_203 ;
}
static int
F_110 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
* V_207 = V_66 -> V_136 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_111 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_112 ( V_21 , V_207 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int F_113 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
F_77 ( V_66 ) ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
if ( F_115 ( V_21 ) ) {
T_9 V_211 = F_116 ( V_212 ) ;
T_9 V_213 = F_116 ( V_214 ) ;
F_10 ( V_17 , L_112 , ( V_211 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_113 , V_211 & 0x3f ) ;
F_10 ( V_17 , L_114 , ( V_213 & V_215 ) >>
V_216 ) ;
F_10 ( V_17 , L_115 ,
( V_213 & V_217 ) >> V_218 ) ;
} else if ( F_117 ( V_21 ) || ( F_118 ( V_21 ) && ! F_91 ( V_21 ) ) ||
F_119 ( V_21 ) || F_120 ( V_21 ) ) {
T_4 V_219 = F_68 ( V_220 ) ;
T_4 V_221 = F_68 ( V_222 ) ;
T_4 V_223 = F_68 ( V_224 ) ;
T_4 V_225 , V_226 , V_227 ;
T_4 V_228 , V_229 , V_230 ;
T_4 V_231 , V_232 , V_233 ;
T_4 V_234 , V_235 , V_236 ;
T_4 V_237 , V_238 , V_239 , V_240 , V_241 ;
int V_242 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_204;
F_121 ( V_66 , V_243 ) ;
V_230 = F_68 ( V_244 ) ;
if ( F_120 ( V_21 ) )
V_230 >>= 23 ;
else {
V_230 &= ~ V_245 ;
if ( F_122 ( V_21 ) || F_119 ( V_21 ) )
V_230 >>= 24 ;
else
V_230 >>= 25 ;
}
V_230 = F_123 ( V_66 , V_230 ) ;
V_225 = F_68 ( V_246 ) ;
V_226 = F_68 ( V_247 ) ;
V_227 = F_68 ( V_248 ) ;
V_228 = F_68 ( V_249 ) ;
V_231 = F_68 ( V_250 ) ;
V_232 = F_68 ( V_251 ) ;
V_233 = F_68 ( V_252 ) ;
V_234 = F_68 ( V_253 ) ;
V_235 = F_68 ( V_254 ) ;
V_236 = F_68 ( V_255 ) ;
if ( F_120 ( V_21 ) )
V_229 = ( V_228 & V_256 ) >> V_257 ;
else if ( F_122 ( V_21 ) || F_119 ( V_21 ) )
V_229 = ( V_228 & V_258 ) >> V_259 ;
else
V_229 = ( V_228 & V_260 ) >> V_261 ;
V_229 = F_123 ( V_66 , V_229 ) ;
F_124 ( V_66 , V_243 ) ;
F_7 ( & V_21 -> V_74 ) ;
if ( F_117 ( V_21 ) || F_118 ( V_21 ) ) {
V_237 = F_68 ( V_171 ) ;
V_238 = F_68 ( V_173 ) ;
V_239 = F_68 ( V_262 ) ;
V_240 = F_68 ( V_172 ) ;
V_241 = F_68 ( V_263 ) ;
} else {
V_237 = F_68 ( F_85 ( 2 ) ) ;
V_238 = F_68 ( F_83 ( 2 ) ) ;
V_239 = F_68 ( F_125 ( 2 ) ) ;
V_240 = F_68 ( F_84 ( 2 ) ) ;
V_241 = F_68 ( V_263 ) ;
}
F_10 ( V_17 , L_116 ,
V_237 , V_238 , V_239 , V_240 , V_241 ) ;
F_10 ( V_17 , L_117 , V_219 ) ;
F_10 ( V_17 , L_118 ,
( V_219 & ( F_120 ( V_21 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_10 ( V_17 , L_119 ,
V_219 & 0xff ) ;
F_10 ( V_17 , L_120 ,
V_221 & 0xff ) ;
F_10 ( V_17 , L_121 , V_228 ) ;
F_10 ( V_17 , L_122 , V_225 ) ;
F_10 ( V_17 , L_123 , V_226 ) ;
F_10 ( V_17 , L_124 , V_227 ) ;
F_10 ( V_17 , L_125 , V_230 ) ;
F_10 ( V_17 , L_126 , V_229 ) ;
F_10 ( V_17 , L_127 , V_231 &
V_264 ) ;
F_10 ( V_17 , L_128 , V_232 &
V_265 ) ;
F_10 ( V_17 , L_129 , V_233 &
V_265 ) ;
F_10 ( V_17 , L_130 , V_234 &
V_266 ) ;
F_10 ( V_17 , L_131 , V_235 &
V_265 ) ;
F_10 ( V_17 , L_132 , V_236 &
V_265 ) ;
V_242 = ( V_223 & 0xff0000 ) >> 16 ;
V_242 *= ( F_126 ( V_21 ) ? V_267 : 1 ) ;
F_10 ( V_17 , L_133 ,
F_123 ( V_66 , V_242 ) ) ;
V_242 = ( V_223 & 0xff00 ) >> 8 ;
V_242 *= ( F_126 ( V_21 ) ? V_267 : 1 ) ;
F_10 ( V_17 , L_134 ,
F_123 ( V_66 , V_242 ) ) ;
V_242 = V_223 & 0xff ;
V_242 *= ( F_126 ( V_21 ) ? V_267 : 1 ) ;
F_10 ( V_17 , L_135 ,
F_123 ( V_66 , V_242 ) ) ;
F_10 ( V_17 , L_136 ,
F_123 ( V_66 , V_66 -> V_209 . V_242 ) ) ;
F_10 ( V_17 , L_137 ,
F_123 ( V_66 , V_66 -> V_209 . V_268 ) ) ;
} else if ( F_91 ( V_21 ) ) {
T_4 V_269 ;
F_5 ( & V_66 -> V_209 . V_270 ) ;
V_269 = F_127 ( V_66 , V_271 ) ;
F_10 ( V_17 , L_138 , V_269 ) ;
F_10 ( V_17 , L_139 , V_66 -> V_272 ) ;
F_10 ( V_17 , L_140 ,
F_123 ( V_66 , V_66 -> V_209 . V_242 ) ) ;
F_10 ( V_17 , L_141 ,
F_123 ( V_66 , V_66 -> V_209 . V_273 ) ) ;
F_10 ( V_17 , L_142 ,
F_123 ( V_66 , V_66 -> V_209 . V_268 ) ) ;
F_10 ( V_17 ,
L_143 ,
F_123 ( V_66 , V_66 -> V_209 . V_274 ) ) ;
F_10 ( V_17 , L_144 ,
F_123 ( V_66 , ( V_269 >> 8 ) & 0xff ) ) ;
F_7 ( & V_66 -> V_209 . V_270 ) ;
} else {
F_26 ( V_17 , L_145 ) ;
}
V_204:
F_78 ( V_66 ) ;
return V_73 ;
}
static int F_128 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
T_8 V_275 [ V_276 ] ;
T_4 V_147 [ V_276 ] ;
int V_145 ;
if ( ! V_277 . V_278 ) {
F_10 ( V_17 , L_146 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
F_74 (ring, dev_priv, i) {
V_147 [ V_145 ] = V_135 -> V_137 ( V_135 , false ) ;
V_275 [ V_145 ] = F_129 ( V_135 ) ;
}
F_78 ( V_66 ) ;
if ( F_130 ( & V_66 -> V_279 . V_280 ) ) {
F_10 ( V_17 , L_147 ,
F_131 ( V_66 -> V_279 . V_280 . V_281 . V_282 -
V_148 ) ) ;
} else
F_10 ( V_17 , L_148 ) ;
F_74 (ring, dev_priv, i) {
F_10 ( V_17 , L_149 , V_135 -> V_45 ) ;
F_10 ( V_17 , L_150 ,
V_135 -> V_283 . V_147 , V_147 [ V_145 ] ) ;
F_10 ( V_17 , L_151 ,
( long long ) V_135 -> V_283 . V_275 ,
( long long ) V_275 [ V_145 ] ) ;
F_10 ( V_17 , L_152 ,
( long long ) V_135 -> V_283 . V_284 ) ;
F_10 ( V_17 , L_153 , V_135 -> V_283 . V_285 ) ;
F_10 ( V_17 , L_154 , V_135 -> V_283 . V_286 ) ;
}
return 0 ;
}
static int F_132 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_287 , V_288 ;
T_9 V_289 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
V_287 = F_68 ( V_290 ) ;
V_288 = F_68 ( V_291 ) ;
V_289 = F_116 ( V_292 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_155 , ( V_287 & V_293 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_156 ,
( V_287 & V_294 ) >>
V_295 ) ;
F_10 ( V_17 , L_157 ,
V_287 & V_296 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_158 ,
V_287 & V_297 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_159 ,
V_287 & V_298 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_160 ,
( V_287 & V_299 ) >> V_300 ) ;
F_10 ( V_17 , L_161 ,
( V_287 & V_301 ) >> V_302 ) ;
F_10 ( V_17 , L_162 , ( V_287 & V_303 ) ) ;
F_10 ( V_17 , L_163 , ( V_289 & 0x3f ) ) ;
F_10 ( V_17 , L_164 , ( ( V_289 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_165 ,
( V_288 & V_304 ) ? L_2 : L_1 ) ;
F_26 ( V_17 , L_166 ) ;
switch ( V_288 & V_305 ) {
case V_306 :
F_26 ( V_17 , L_167 ) ;
break;
case V_307 :
F_26 ( V_17 , L_168 ) ;
break;
case V_308 :
F_26 ( V_17 , L_169 ) ;
break;
case V_309 :
F_26 ( V_17 , L_170 ) ;
break;
case V_310 :
F_26 ( V_17 , L_171 ) ;
break;
case V_311 :
F_26 ( V_17 , L_172 ) ;
break;
default:
F_26 ( V_17 , L_173 ) ;
break;
}
return 0 ;
}
static int F_133 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_312 * V_313 ;
int V_145 ;
F_63 ( & V_66 -> V_314 . V_315 ) ;
F_134 (fw_domain, dev_priv, i) {
F_10 ( V_17 , L_174 ,
F_135 ( V_145 ) ,
V_313 -> V_316 ) ;
}
F_71 ( & V_66 -> V_314 . V_315 ) ;
return 0 ;
}
static int F_136 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_317 , V_318 , V_319 ;
F_77 ( V_66 ) ;
V_319 = F_68 ( V_320 ) ;
V_317 = F_68 ( V_246 ) ;
V_318 = F_68 ( V_321 ) ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_175 ,
F_1 ( V_317 & V_322 ) ) ;
F_10 ( V_17 , L_176 ,
F_1 ( V_317 & V_323 ) ) ;
F_10 ( V_17 , L_157 ,
F_1 ( V_317 & V_323 ) ) ;
F_10 ( V_17 , L_158 ,
F_1 ( ( V_317 & V_324 ) ==
V_325 ) ) ;
F_10 ( V_17 , L_177 ,
F_1 ( V_318 & ( V_326 |
F_137 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_178 ,
( V_319 & V_327 ) ? L_179 : L_180 ) ;
F_10 ( V_17 , L_181 ,
( V_319 & V_328 ) ? L_179 : L_180 ) ;
F_10 ( V_17 , L_182 ,
F_68 ( V_329 ) ) ;
F_10 ( V_17 , L_183 ,
F_68 ( V_330 ) ) ;
return F_133 ( V_17 , NULL ) ;
}
static int F_138 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_317 , V_331 , V_318 , V_332 = 0 ;
unsigned V_333 ;
int V_72 = 0 , V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
F_63 ( & V_66 -> V_314 . V_315 ) ;
V_333 = V_66 -> V_314 . V_313 [ V_334 ] . V_316 ;
F_71 ( & V_66 -> V_314 . V_315 ) ;
if ( V_333 ) {
F_26 ( V_17 , L_184
L_185 ) ;
} else {
while ( V_72 ++ < 50 && ( F_139 ( V_335 ) & 1 ) )
F_140 ( 10 ) ;
F_10 ( V_17 , L_186 , F_1 ( V_72 < 51 ) ) ;
}
V_331 = F_141 ( V_66 -> V_336 + V_337 ) ;
F_142 ( false , V_337 , V_331 , 4 , true ) ;
V_317 = F_68 ( V_246 ) ;
V_318 = F_68 ( V_321 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_5 ( & V_66 -> V_209 . V_270 ) ;
F_143 ( V_66 , V_338 , & V_332 ) ;
F_7 ( & V_66 -> V_209 . V_270 ) ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_175 ,
F_1 ( V_317 & V_322 ) ) ;
F_10 ( V_17 , L_157 ,
F_1 ( V_317 & V_323 ) ) ;
F_10 ( V_17 , L_158 ,
F_1 ( ( V_317 & V_324 ) ==
V_325 ) ) ;
F_10 ( V_17 , L_187 ,
F_1 ( V_318 & V_339 ) ) ;
F_10 ( V_17 , L_177 ,
F_1 ( V_318 & V_340 ) ) ;
F_10 ( V_17 , L_188 ,
F_1 ( V_318 & V_341 ) ) ;
F_10 ( V_17 , L_189 ,
F_1 ( V_318 & V_342 ) ) ;
F_26 ( V_17 , L_190 ) ;
switch ( V_331 & V_343 ) {
case V_344 :
if ( V_331 & V_345 )
F_26 ( V_17 , L_191 ) ;
else
F_26 ( V_17 , L_167 ) ;
break;
case V_346 :
F_26 ( V_17 , L_192 ) ;
break;
case V_347 :
F_26 ( V_17 , L_193 ) ;
break;
case V_348 :
F_26 ( V_17 , L_194 ) ;
break;
default:
F_26 ( V_17 , L_195 ) ;
break;
}
F_10 ( V_17 , L_196 ,
F_1 ( V_331 & V_345 ) ) ;
F_10 ( V_17 , L_197 ,
F_68 ( V_349 ) ) ;
F_10 ( V_17 , L_198 ,
F_68 ( V_350 ) ) ;
F_10 ( V_17 , L_199 ,
F_68 ( V_351 ) ) ;
F_10 ( V_17 , L_200 ,
F_68 ( V_352 ) ) ;
F_10 ( V_17 , L_201 ,
F_144 ( ( ( V_332 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_202 ,
F_144 ( ( ( V_332 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_203 ,
F_144 ( ( ( V_332 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_145 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_91 ( V_21 ) )
return F_136 ( V_17 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
return F_138 ( V_17 ) ;
else
return F_132 ( V_17 ) ;
}
static int F_146 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_147 ( V_21 ) ) {
F_26 ( V_17 , L_204 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
if ( F_148 ( V_21 ) ) {
F_26 ( V_17 , L_205 ) ;
} else {
F_26 ( V_17 , L_206 ) ;
switch ( V_66 -> V_353 . V_354 ) {
case V_355 :
F_26 ( V_17 , L_207 ) ;
break;
case V_356 :
F_26 ( V_17 , L_208 ) ;
break;
case V_357 :
F_26 ( V_17 , L_209 ) ;
break;
case V_358 :
F_26 ( V_17 , L_210 ) ;
break;
case V_359 :
F_26 ( V_17 , L_211 ) ;
break;
case V_360 :
F_26 ( V_17 , L_212 ) ;
break;
case V_361 :
F_26 ( V_17 , L_213 ) ;
break;
case V_362 :
F_26 ( V_17 , L_214 ) ;
break;
case V_363 :
F_26 ( V_17 , L_215 ) ;
break;
case V_364 :
F_26 ( V_17 , L_216 ) ;
break;
case V_365 :
F_26 ( V_17 , L_217 ) ;
break;
default:
F_26 ( V_17 , L_218 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_78 ( V_66 ) ;
return 0 ;
}
static int F_149 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_147 ( V_21 ) )
return - V_366 ;
F_150 ( V_21 ) ;
* V_207 = V_66 -> V_353 . V_367 ;
F_151 ( V_21 ) ;
return 0 ;
}
static int F_152 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_368 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_147 ( V_21 ) )
return - V_366 ;
F_150 ( V_21 ) ;
V_368 = F_68 ( V_369 ) ;
V_66 -> V_353 . V_367 = V_207 ;
F_153 ( V_369 , V_207 ?
( V_368 | V_370 ) :
( V_368 & ~ V_370 ) ) ;
F_151 ( V_21 ) ;
return 0 ;
}
static int F_154 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_155 ( V_21 ) ) {
F_26 ( V_17 , L_219 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
F_10 ( V_17 , L_220 ,
F_1 ( V_277 . V_371 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_26 ( V_17 , L_221 ) ;
} else {
if ( F_68 ( V_372 ) & V_373 )
F_26 ( V_17 , L_222 ) ;
else
F_26 ( V_17 , L_223 ) ;
}
F_78 ( V_66 ) ;
return 0 ;
}
static int F_156 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_374 = false ;
F_77 ( V_66 ) ;
if ( F_92 ( V_21 ) )
V_374 = F_68 ( V_375 ) & V_376 ;
else if ( F_157 ( V_21 ) || F_158 ( V_21 ) ||
F_159 ( V_21 ) || F_160 ( V_21 ) )
V_374 = F_68 ( V_377 ) & V_378 ;
else if ( F_161 ( V_21 ) )
V_374 = F_68 ( V_379 ) & V_380 ;
else if ( F_162 ( V_21 ) )
V_374 = F_68 ( V_381 ) & V_382 ;
else if ( F_91 ( V_21 ) )
V_374 = F_68 ( V_383 ) & V_384 ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_224 ,
V_374 ? L_225 : L_226 ) ;
return 0 ;
}
static int F_163 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned long V_385 , V_386 , V_387 ;
int V_73 ;
if ( ! F_115 ( V_21 ) )
return - V_366 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_385 = F_164 ( V_66 ) ;
V_386 = F_165 ( V_66 ) ;
V_387 = F_166 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_227 , V_385 ) ;
F_10 ( V_17 , L_228 , V_386 ) ;
F_10 ( V_17 , L_229 , V_387 ) ;
F_10 ( V_17 , L_230 , V_386 + V_387 ) ;
return 0 ;
}
static int F_167 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
int V_388 , V_389 ;
if ( ! ( F_117 ( V_21 ) || F_118 ( V_21 ) ) ) {
F_26 ( V_17 , L_231 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_270 ) ;
if ( V_73 )
goto V_204;
F_26 ( V_17 , L_232 ) ;
for ( V_388 = V_66 -> V_209 . V_390 ;
V_388 <= V_66 -> V_209 . V_391 ;
V_388 ++ ) {
V_389 = V_388 ;
F_143 ( V_66 ,
V_392 ,
& V_389 ) ;
F_10 ( V_17 , L_233 ,
F_123 ( V_66 , V_388 ) ,
( ( V_389 >> 0 ) & 0xff ) * 100 ,
( ( V_389 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_66 -> V_209 . V_270 ) ;
V_204:
F_78 ( V_66 ) ;
return V_73 ;
}
static int F_168 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_393 * V_394 = & V_66 -> V_394 ;
void * V_18 = F_3 ( V_395 , V_9 ) ;
int V_73 ;
if ( V_18 == NULL )
return - V_10 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_204;
if ( V_394 -> V_396 ) {
F_169 ( V_18 , V_394 -> V_396 , V_395 ) ;
F_170 ( V_17 , V_18 , V_395 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
V_204:
F_104 ( V_18 ) ;
return 0 ;
}
static int F_171 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_397 * V_398 = NULL ;
struct V_399 * V_400 ;
#ifdef F_172
struct V_65 * V_66 = V_21 -> V_67 ;
V_398 = V_66 -> V_401 ;
V_400 = F_173 ( V_398 -> V_402 . V_400 ) ;
F_10 ( V_17 , L_234 ,
V_400 -> V_34 . V_403 ,
V_400 -> V_34 . V_404 ,
V_400 -> V_34 . V_405 ,
V_400 -> V_34 . V_406 ,
V_400 -> V_34 . V_407 [ 0 ] ,
F_64 ( & V_400 -> V_34 . V_408 . V_408 ) ) ;
F_20 ( V_17 , V_400 -> V_26 ) ;
F_29 ( V_17 , '\n' ) ;
#endif
F_5 ( & V_21 -> V_409 . V_410 ) ;
F_24 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_398 && & V_400 -> V_34 == V_398 -> V_402 . V_400 )
continue;
F_10 ( V_17 , L_235 ,
V_400 -> V_34 . V_403 ,
V_400 -> V_34 . V_404 ,
V_400 -> V_34 . V_405 ,
V_400 -> V_34 . V_406 ,
V_400 -> V_34 . V_407 [ 0 ] ,
F_64 ( & V_400 -> V_34 . V_408 . V_408 ) ) ;
F_20 ( V_17 , V_400 -> V_26 ) ;
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_409 . V_410 ) ;
return 0 ;
}
static void F_174 ( struct V_16 * V_17 ,
struct V_411 * V_412 )
{
F_10 ( V_17 , L_236 ,
V_412 -> V_413 , V_412 -> V_64 , V_412 -> V_414 ,
V_412 -> V_415 ) ;
}
static int F_175 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_58 * V_59 ;
int V_73 , V_145 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_24 (ctx, &dev_priv->context_list, link) {
if ( ! V_277 . V_416 &&
V_59 -> V_60 . V_417 == NULL )
continue;
F_26 ( V_17 , L_237 ) ;
F_28 ( V_17 , V_59 ) ;
F_74 (ring, dev_priv, i) {
if ( V_135 -> V_418 == V_59 )
F_10 ( V_17 , L_238 ,
V_135 -> V_45 ) ;
}
if ( V_277 . V_416 ) {
F_29 ( V_17 , '\n' ) ;
F_74 (ring, dev_priv, i) {
struct V_25 * V_419 =
V_59 -> V_420 [ V_145 ] . V_421 ;
struct V_411 * V_412 =
V_59 -> V_420 [ V_145 ] . V_412 ;
F_10 ( V_17 , L_239 , V_135 -> V_45 ) ;
if ( V_419 )
F_20 ( V_17 , V_419 ) ;
if ( V_412 )
F_174 ( V_17 , V_412 ) ;
F_29 ( V_17 , '\n' ) ;
}
} else {
F_20 ( V_17 , V_59 -> V_60 . V_417 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static void F_176 ( struct V_16 * V_17 ,
struct V_134 * V_135 ,
struct V_25 * V_419 )
{
struct V_422 * V_422 ;
T_10 * V_423 ;
int V_424 ;
unsigned long V_425 = 0 ;
if ( V_419 == NULL ) {
F_10 ( V_17 , L_240 ,
V_135 -> V_45 ) ;
return;
}
F_10 ( V_17 , L_241 , V_135 -> V_45 ,
F_177 ( V_419 ) ) ;
if ( ! F_45 ( V_419 ) )
F_26 ( V_17 , L_242 ) ;
else
V_425 = F_178 ( V_419 ) ;
if ( F_179 ( V_419 ) ) {
F_26 ( V_17 , L_243 ) ;
return;
}
V_422 = F_180 ( V_419 , 1 ) ;
if ( ! F_181 ( V_422 == NULL ) ) {
V_423 = F_182 ( V_422 ) ;
for ( V_424 = 0 ; V_424 < 0x600 / sizeof( T_4 ) / 4 ; V_424 += 4 ) {
F_10 ( V_17 , L_244 ,
V_425 + 4096 + ( V_424 * 4 ) ,
V_423 [ V_424 ] , V_423 [ V_424 + 1 ] ,
V_423 [ V_424 + 2 ] , V_423 [ V_424 + 3 ] ) ;
}
F_183 ( V_423 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
static int F_184 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_58 * V_59 ;
int V_73 , V_145 ;
if ( ! V_277 . V_416 ) {
F_10 ( V_17 , L_245 ) ;
return 0 ;
}
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_24 (ctx, &dev_priv->context_list, link) {
F_74 (ring, dev_priv, i) {
if ( V_135 -> V_418 != V_59 )
F_176 ( V_17 , V_135 ,
V_59 -> V_420 [ V_145 ] . V_421 ) ;
}
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_185 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
T_4 V_426 ;
T_11 V_427 ;
T_11 V_428 ;
T_4 V_429 ;
T_4 V_430 ;
struct V_63 * V_431 ;
int V_432 , V_145 ;
int V_73 ;
if ( ! V_277 . V_416 ) {
F_26 ( V_17 , L_245 ) ;
return 0 ;
}
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
F_74 (ring, dev_priv, ring_id) {
struct V_143 * V_433 = NULL ;
int V_72 = 0 ;
unsigned long V_434 ;
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
V_429 = F_68 ( F_186 ( V_135 ) ) ;
V_430 = F_68 ( F_186 ( V_135 ) + 4 ) ;
F_10 ( V_17 , L_247 ,
V_429 , V_430 ) ;
V_426 = F_68 ( F_187 ( V_135 ) ) ;
F_10 ( V_17 , L_248 , V_426 ) ;
V_427 = V_135 -> V_435 ;
V_428 = V_426 & 0x07 ;
if ( V_427 > V_428 )
V_428 += 6 ;
F_10 ( V_17 , L_249 ,
V_427 , V_428 ) ;
for ( V_145 = 0 ; V_145 < 6 ; V_145 ++ ) {
V_429 = F_68 ( F_188 ( V_135 ) + 8 * V_145 ) ;
V_430 = F_68 ( F_188 ( V_135 ) + 8 * V_145 + 4 ) ;
F_10 ( V_17 , L_250 ,
V_145 , V_429 , V_430 ) ;
}
F_189 ( & V_135 -> V_436 , V_434 ) ;
F_190 (cursor, &ring->execlist_queue)
V_72 ++ ;
V_433 = F_191 ( & V_135 -> V_437 ,
struct V_143 , V_438 ) ;
F_192 ( & V_135 -> V_436 , V_434 ) ;
F_10 ( V_17 , L_251 , V_72 ) ;
if ( V_433 ) {
struct V_25 * V_419 ;
V_419 = V_433 -> V_59 -> V_420 [ V_432 ] . V_421 ;
F_10 ( V_17 , L_252 ,
F_177 ( V_419 ) ) ;
F_10 ( V_17 , L_253 ,
V_433 -> V_414 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static const char * F_193 ( unsigned V_439 )
{
switch ( V_439 ) {
case V_440 :
return L_254 ;
case V_441 :
return L_255 ;
case V_442 :
return L_256 ;
case V_443 :
return L_257 ;
case V_444 :
return L_258 ;
case V_445 :
return L_259 ;
case V_446 :
return L_260 ;
case V_447 :
return L_261 ;
}
return L_262 ;
}
static int F_194 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
F_10 ( V_17 , L_263 ,
F_193 ( V_66 -> V_107 . V_448 ) ) ;
F_10 ( V_17 , L_264 ,
F_193 ( V_66 -> V_107 . V_449 ) ) ;
if ( F_195 ( V_21 ) || F_196 ( V_21 ) ) {
F_10 ( V_17 , L_265 ,
F_68 ( V_450 ) ) ;
F_10 ( V_17 , L_266 ,
F_68 ( V_451 ) ) ;
F_10 ( V_17 , L_267 ,
F_116 ( V_452 ) ) ;
F_10 ( V_17 , L_268 ,
F_116 ( V_453 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_269 ,
F_68 ( V_454 ) ) ;
F_10 ( V_17 , L_270 ,
F_68 ( V_455 ) ) ;
F_10 ( V_17 , L_271 ,
F_68 ( V_456 ) ) ;
F_10 ( V_17 , L_272 ,
F_68 ( V_457 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_10 ( V_17 , L_273 ,
F_68 ( V_458 ) ) ;
else
F_10 ( V_17 , L_274 ,
F_68 ( V_459 ) ) ;
F_10 ( V_17 , L_275 ,
F_68 ( V_460 ) ) ;
}
if ( V_66 -> V_461 & V_462 )
F_26 ( V_17 , L_276 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_197 ( int V_86 , void * V_87 , void * V_18 )
{
struct V_58 * V_59 = V_87 ;
struct V_16 * V_17 = V_18 ;
struct V_93 * V_94 = V_59 -> V_94 ;
if ( ! V_94 ) {
F_10 ( V_17 , L_277 ,
V_59 -> V_463 ) ;
return 0 ;
}
if ( F_198 ( V_59 ) )
F_26 ( V_17 , L_278 ) ;
else
F_10 ( V_17 , L_279 , V_59 -> V_463 ) ;
V_94 -> V_464 ( V_94 , V_17 ) ;
return 0 ;
}
static void F_199 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_93 * V_94 = V_66 -> V_107 . V_465 ;
int V_208 , V_145 ;
if ( ! V_94 )
return;
F_10 ( V_17 , L_280 , V_94 -> V_466 ) ;
F_10 ( V_17 , L_281 , V_94 -> V_467 ) ;
F_74 (ring, dev_priv, unused) {
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
T_4 V_468 = 0x270 + V_145 * 8 ;
T_8 V_469 = F_68 ( V_135 -> V_470 + V_468 + 4 ) ;
V_469 <<= 32 ;
V_469 |= F_68 ( V_135 -> V_470 + V_468 ) ;
F_10 ( V_17 , L_282 , V_145 , V_469 ) ;
}
}
}
static void F_200 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_105 * V_106 ;
int V_145 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_283 , F_68 ( V_471 ) ) ;
F_74 (ring, dev_priv, i) {
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_283 , F_68 ( F_201 ( V_135 ) ) ) ;
F_10 ( V_17 , L_284 , F_68 ( F_202 ( V_135 ) ) ) ;
F_10 ( V_17 , L_285 , F_68 ( F_203 ( V_135 ) ) ) ;
F_10 ( V_17 , L_286 , F_68 ( F_204 ( V_135 ) ) ) ;
}
if ( V_66 -> V_107 . V_465 ) {
struct V_93 * V_94 = V_66 -> V_107 . V_465 ;
F_26 ( V_17 , L_287 ) ;
F_10 ( V_17 , L_288 , V_94 -> V_472 . V_473 ) ;
V_94 -> V_464 ( V_94 , V_17 ) ;
}
F_51 (file, &dev->filelist, lhead) {
struct V_474 * V_96 = V_106 -> V_115 ;
F_10 ( V_17 , L_289 ,
F_205 ( V_106 -> V_118 , V_119 ) -> V_120 ) ;
F_53 ( & V_96 -> V_475 , F_197 , V_17 ) ;
}
F_10 ( V_17 , L_290 , F_68 ( V_476 ) ) ;
}
static int F_206 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_199 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_200 ( V_17 , V_21 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_207 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
F_10 ( V_17 , L_291 , F_1 ( F_208 ( V_21 ) ) ) ;
F_10 ( V_17 , L_292 , V_66 -> V_477 ) ;
return 0 ;
}
static int F_209 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_478 = 0 ;
T_4 V_479 [ 3 ] ;
enum V_124 V_124 ;
bool V_480 = false ;
if ( ! F_210 ( V_21 ) ) {
F_26 ( V_17 , L_293 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
F_5 ( & V_66 -> V_481 . V_315 ) ;
F_10 ( V_17 , L_294 , F_1 ( V_66 -> V_481 . V_482 ) ) ;
F_10 ( V_17 , L_295 , F_1 ( V_66 -> V_481 . V_483 ) ) ;
F_10 ( V_17 , L_296 , F_1 ( ( bool ) V_66 -> V_481 . V_480 ) ) ;
F_10 ( V_17 , L_297 , F_1 ( V_66 -> V_481 . V_97 ) ) ;
F_10 ( V_17 , L_298 ,
V_66 -> V_481 . V_484 ) ;
F_10 ( V_17 , L_299 ,
F_1 ( F_211 ( & V_66 -> V_481 . V_127 . V_127 ) ) ) ;
if ( F_212 ( V_21 ) )
V_480 = F_68 ( F_213 ( V_21 ) ) & V_485 ;
else {
F_81 (dev_priv, pipe) {
V_479 [ V_124 ] = F_68 ( F_214 ( V_124 ) ) &
V_486 ;
if ( ( V_479 [ V_124 ] == V_487 ) ||
( V_479 [ V_124 ] == V_488 ) )
V_480 = true ;
}
}
F_10 ( V_17 , L_300 , F_1 ( V_480 ) ) ;
if ( ! F_212 ( V_21 ) )
F_81 (dev_priv, pipe) {
if ( ( V_479 [ V_124 ] == V_487 ) ||
( V_479 [ V_124 ] == V_488 ) )
F_10 ( V_17 , L_301 , F_61 ( V_124 ) ) ;
}
F_26 ( V_17 , L_28 ) ;
F_10 ( V_17 , L_302 ,
F_1 ( ( bool ) V_66 -> V_481 . V_489 ) ) ;
if ( F_212 ( V_21 ) ) {
V_478 = F_68 ( F_215 ( V_21 ) ) &
V_490 ;
F_10 ( V_17 , L_303 , V_478 ) ;
}
F_7 ( & V_66 -> V_481 . V_315 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_216 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_491 * V_492 ;
struct V_493 * V_494 ;
struct V_495 * V_495 = NULL ;
int V_73 ;
T_11 V_496 [ 6 ] ;
F_150 ( V_21 ) ;
F_217 (dev, connector) {
if ( V_494 -> V_34 . V_497 != V_498 )
continue;
if ( ! V_494 -> V_34 . V_492 )
continue;
V_492 = F_218 ( V_494 -> V_34 . V_492 ) ;
if ( V_492 -> type != V_499 )
continue;
V_495 = F_219 ( & V_492 -> V_34 ) ;
V_73 = F_220 ( V_495 , V_496 ) ;
if ( V_73 )
goto V_204;
F_10 ( V_17 , L_304 ,
V_496 [ 0 ] , V_496 [ 1 ] , V_496 [ 2 ] ,
V_496 [ 3 ] , V_496 [ 4 ] , V_496 [ 5 ] ) ;
goto V_204;
}
V_73 = - V_366 ;
V_204:
F_151 ( V_21 ) ;
return V_73 ;
}
static int F_221 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_8 V_500 ;
T_4 V_501 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_366 ;
F_77 ( V_66 ) ;
F_222 ( V_502 , V_500 ) ;
V_500 = ( V_500 & 0x1f00 ) >> 8 ;
V_501 = 1000000 / ( 1 << V_500 ) ;
V_500 = F_68 ( V_503 ) ;
V_500 *= V_501 ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_305 , ( long long unsigned ) V_500 ) ;
return 0 ;
}
static int F_223 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_122 ( V_21 ) && ! F_119 ( V_21 ) ) {
F_26 ( V_17 , L_219 ) ;
return 0 ;
}
F_10 ( V_17 , L_306 , F_1 ( ! V_66 -> V_107 . V_504 ) ) ;
F_10 ( V_17 , L_307 ,
F_1 ( ! F_224 ( V_66 ) ) ) ;
return 0 ;
}
static const char * F_225 ( enum V_505 V_506 )
{
switch ( V_506 ) {
case V_507 :
return L_308 ;
case V_508 :
return L_309 ;
case V_509 :
return L_310 ;
case V_510 :
return L_311 ;
case V_511 :
return L_312 ;
case V_512 :
return L_313 ;
case V_513 :
return L_314 ;
case V_514 :
return L_315 ;
case V_515 :
return L_316 ;
case V_516 :
return L_317 ;
case V_517 :
return L_318 ;
case V_518 :
return L_319 ;
case V_519 :
return L_320 ;
case V_520 :
return L_321 ;
case V_521 :
return L_322 ;
case V_522 :
return L_323 ;
case V_523 :
return L_324 ;
case V_524 :
return L_325 ;
case V_525 :
return L_326 ;
case V_526 :
return L_327 ;
case V_527 :
return L_328 ;
case V_528 :
return L_329 ;
case V_529 :
return L_330 ;
case V_530 :
return L_331 ;
case V_531 :
return L_332 ;
case V_532 :
return L_333 ;
case V_533 :
return L_334 ;
case V_534 :
return L_335 ;
case V_535 :
return L_336 ;
default:
F_226 ( V_506 ) ;
return L_337 ;
}
}
static int F_227 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_536 * V_537 = & V_66 -> V_537 ;
int V_145 ;
F_5 ( & V_537 -> V_315 ) ;
F_10 ( V_17 , L_338 , L_339 , L_340 ) ;
for ( V_145 = 0 ; V_145 < V_537 -> V_538 ; V_145 ++ ) {
struct V_539 * V_540 ;
enum V_505 V_541 ;
V_540 = & V_537 -> V_542 [ V_145 ] ;
F_10 ( V_17 , L_341 , V_540 -> V_45 ,
V_540 -> V_72 ) ;
for ( V_541 = 0 ; V_541 < V_543 ;
V_541 ++ ) {
if ( ! ( F_228 ( V_541 ) & V_540 -> V_544 ) )
continue;
F_10 ( V_17 , L_342 ,
F_225 ( V_541 ) ,
V_537 -> V_545 [ V_541 ] ) ;
}
}
F_7 ( & V_537 -> V_315 ) ;
return 0 ;
}
static void F_229 ( struct V_16 * V_17 , int V_546 ,
struct V_547 * V_548 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < V_546 ; V_145 ++ )
F_29 ( V_17 , '\t' ) ;
F_10 ( V_17 , L_343 ,
V_548 -> V_34 . V_86 , V_548 -> V_45 ,
V_548 -> V_549 , V_548 -> clock ,
V_548 -> V_550 , V_548 -> V_551 ,
V_548 -> V_552 , V_548 -> V_553 ,
V_548 -> V_554 , V_548 -> V_555 ,
V_548 -> V_556 , V_548 -> V_557 ,
V_548 -> type , V_548 -> V_434 ) ;
}
static void F_230 ( struct V_16 * V_17 ,
struct V_122 * V_122 ,
struct V_491 * V_491 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_558 * V_123 = & V_122 -> V_34 ;
struct V_493 * V_493 ;
struct V_559 * V_492 ;
V_492 = & V_491 -> V_34 ;
F_10 ( V_17 , L_344 ,
V_492 -> V_34 . V_86 , V_492 -> V_45 ) ;
F_231 (dev, encoder, intel_connector) {
struct V_560 * V_494 = & V_493 -> V_34 ;
F_10 ( V_17 , L_345 ,
V_494 -> V_34 . V_86 ,
V_494 -> V_45 ,
F_232 ( V_494 -> V_429 ) ) ;
if ( V_494 -> V_429 == V_561 ) {
struct V_547 * V_548 = & V_123 -> V_548 ;
F_10 ( V_17 , L_346 ) ;
F_229 ( V_17 , 2 , V_548 ) ;
} else {
F_29 ( V_17 , '\n' ) ;
}
}
}
static void F_233 ( struct V_16 * V_17 , struct V_122 * V_122 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_558 * V_123 = & V_122 -> V_34 ;
struct V_491 * V_491 ;
if ( V_123 -> V_562 -> V_400 )
F_10 ( V_17 , L_347 ,
V_123 -> V_562 -> V_400 -> V_34 . V_86 , V_123 -> T_1 , V_123 -> V_563 ,
V_123 -> V_562 -> V_400 -> V_403 , V_123 -> V_562 -> V_400 -> V_404 ) ;
else
F_26 ( V_17 , L_348 ) ;
F_234 (dev, crtc, intel_encoder)
F_230 ( V_17 , V_122 , V_491 ) ;
}
static void F_235 ( struct V_16 * V_17 , struct V_564 * V_565 )
{
struct V_547 * V_548 = V_565 -> V_566 ;
F_10 ( V_17 , L_349 ) ;
F_229 ( V_17 , 2 , V_548 ) ;
}
static void F_236 ( struct V_16 * V_17 ,
struct V_493 * V_493 )
{
struct V_491 * V_491 = V_493 -> V_492 ;
struct V_495 * V_495 = F_219 ( & V_491 -> V_34 ) ;
F_10 ( V_17 , L_350 , V_495 -> V_567 [ V_568 ] ) ;
F_10 ( V_17 , L_351 , V_495 -> V_569 ? L_1 :
L_2 ) ;
if ( V_491 -> type == V_499 )
F_235 ( V_17 , & V_493 -> V_565 ) ;
}
static void F_237 ( struct V_16 * V_17 ,
struct V_493 * V_493 )
{
struct V_491 * V_491 = V_493 -> V_492 ;
struct V_570 * V_570 = F_238 ( & V_491 -> V_34 ) ;
F_10 ( V_17 , L_351 , V_570 -> V_569 ? L_1 :
L_2 ) ;
}
static void F_239 ( struct V_16 * V_17 ,
struct V_493 * V_493 )
{
F_235 ( V_17 , & V_493 -> V_565 ) ;
}
static void F_240 ( struct V_16 * V_17 ,
struct V_560 * V_494 )
{
struct V_493 * V_493 = F_241 ( V_494 ) ;
struct V_491 * V_491 = V_493 -> V_492 ;
struct V_547 * V_548 ;
F_10 ( V_17 , L_352 ,
V_494 -> V_34 . V_86 , V_494 -> V_45 ,
F_232 ( V_494 -> V_429 ) ) ;
if ( V_494 -> V_429 == V_561 ) {
F_10 ( V_17 , L_353 , V_494 -> V_571 . V_45 ) ;
F_10 ( V_17 , L_354 ,
V_494 -> V_571 . V_572 ,
V_494 -> V_571 . V_573 ) ;
F_10 ( V_17 , L_355 ,
F_242 ( V_494 -> V_571 . V_574 ) ) ;
F_10 ( V_17 , L_356 ,
V_494 -> V_571 . V_575 ) ;
}
if ( V_491 ) {
if ( V_491 -> type == V_576 ||
V_491 -> type == V_499 )
F_236 ( V_17 , V_493 ) ;
else if ( V_491 -> type == V_577 )
F_237 ( V_17 , V_493 ) ;
else if ( V_491 -> type == V_578 )
F_239 ( V_17 , V_493 ) ;
}
F_10 ( V_17 , L_357 ) ;
F_24 (mode, &connector->modes, head)
F_229 ( V_17 , 2 , V_548 ) ;
}
static bool F_243 ( struct V_20 * V_21 , int V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_421 ;
if ( F_244 ( V_21 ) || F_245 ( V_21 ) )
V_421 = F_68 ( V_579 ) & V_580 ;
else
V_421 = F_68 ( F_246 ( V_124 ) ) & V_581 ;
return V_421 ;
}
static bool F_247 ( struct V_20 * V_21 , int V_124 , int * T_1 , int * V_563 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_199 ;
V_199 = F_68 ( F_248 ( V_124 ) ) ;
* T_1 = ( V_199 >> V_582 ) & V_583 ;
if ( V_199 & ( V_584 << V_582 ) )
* T_1 = - * T_1 ;
* V_563 = ( V_199 >> V_585 ) & V_583 ;
if ( V_199 & ( V_584 << V_585 ) )
* V_563 = - * V_563 ;
return F_243 ( V_21 , V_124 ) ;
}
static int F_249 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 ;
struct V_560 * V_494 ;
F_77 ( V_66 ) ;
F_150 ( V_21 ) ;
F_10 ( V_17 , L_358 ) ;
F_10 ( V_17 , L_359 ) ;
F_60 (dev, crtc) {
bool V_97 ;
int T_1 , V_563 ;
F_10 ( V_17 , L_360 ,
V_123 -> V_34 . V_34 . V_86 , F_61 ( V_123 -> V_124 ) ,
F_1 ( V_123 -> V_97 ) , V_123 -> V_586 -> V_587 ,
V_123 -> V_586 -> V_588 ) ;
if ( V_123 -> V_97 ) {
F_233 ( V_17 , V_123 ) ;
V_97 = F_247 ( V_21 , V_123 -> V_124 , & T_1 , & V_563 ) ;
F_10 ( V_17 , L_361 ,
F_1 ( V_123 -> V_589 ) ,
T_1 , V_563 , V_123 -> V_34 . V_431 -> V_421 -> V_590 ,
V_123 -> V_34 . V_431 -> V_421 -> V_591 ,
V_123 -> V_592 , F_1 ( V_97 ) ) ;
}
F_10 ( V_17 , L_362 ,
F_1 ( ! V_123 -> V_593 ) ,
F_1 ( ! V_123 -> V_594 ) ) ;
}
F_10 ( V_17 , L_28 ) ;
F_10 ( V_17 , L_363 ) ;
F_10 ( V_17 , L_364 ) ;
F_24 (connector, &dev->mode_config.connector_list, head) {
F_240 ( V_17 , V_494 ) ;
}
F_151 ( V_21 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_250 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
int V_595 = F_251 ( F_9 ( V_21 ) -> V_596 ) ;
int V_145 , V_424 , V_73 ;
if ( ! F_252 ( V_21 ) ) {
F_26 ( V_17 , L_365 ) ;
return 0 ;
}
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
if ( F_119 ( V_21 ) ) {
struct V_422 * V_422 ;
T_12 * V_147 ;
V_422 = F_180 ( V_66 -> V_597 , 0 ) ;
V_147 = ( T_12 * ) F_182 ( V_422 ) ;
F_74 (ring, dev_priv, i) {
T_12 V_468 ;
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
F_26 ( V_17 , L_366 ) ;
for ( V_424 = 0 ; V_424 < V_595 ; V_424 ++ ) {
V_468 = V_145 * V_276 + V_424 ;
F_10 ( V_17 , L_367 ,
V_147 [ V_468 ] , V_468 * 8 ) ;
}
F_29 ( V_17 , '\n' ) ;
F_26 ( V_17 , L_368 ) ;
for ( V_424 = 0 ; V_424 < V_595 ; V_424 ++ ) {
V_468 = V_145 + ( V_424 * V_276 ) ;
F_10 ( V_17 , L_367 ,
V_147 [ V_468 ] , V_468 * 8 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_183 ( V_147 ) ;
} else {
F_26 ( V_17 , L_366 ) ;
F_74 (ring, dev_priv, i)
for ( V_424 = 0 ; V_424 < V_595 ; V_424 ++ )
F_10 ( V_17 , L_369 ,
F_68 ( V_135 -> V_598 . V_599 . signal [ V_424 ] ) ) ;
F_29 ( V_17 , '\n' ) ;
}
F_26 ( V_17 , L_370 ) ;
F_74 (ring, dev_priv, i) {
for ( V_424 = 0 ; V_424 < V_595 ; V_424 ++ ) {
F_10 ( V_17 , L_371 , V_135 -> V_598 . V_600 [ V_424 ] ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_29 ( V_17 , '\n' ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_253 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_145 ;
F_150 ( V_21 ) ;
for ( V_145 = 0 ; V_145 < V_66 -> V_601 ; V_145 ++ ) {
struct V_602 * V_603 = & V_66 -> V_604 [ V_145 ] ;
F_10 ( V_17 , L_372 , V_145 , V_603 -> V_45 , V_603 -> V_86 ) ;
F_10 ( V_17 , L_373 ,
V_603 -> V_586 . V_605 , V_603 -> V_97 , F_1 ( V_603 -> V_606 ) ) ;
F_10 ( V_17 , L_374 ) ;
F_10 ( V_17 , L_375 , V_603 -> V_586 . V_607 . V_608 ) ;
F_10 ( V_17 , L_376 ,
V_603 -> V_586 . V_607 . V_609 ) ;
F_10 ( V_17 , L_377 , V_603 -> V_586 . V_607 . V_610 ) ;
F_10 ( V_17 , L_378 , V_603 -> V_586 . V_607 . V_611 ) ;
F_10 ( V_17 , L_379 , V_603 -> V_586 . V_607 . V_612 ) ;
}
F_151 ( V_21 ) ;
return 0 ;
}
static int F_254 ( struct V_16 * V_17 , void * V_208 )
{
int V_145 ;
int V_73 ;
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
F_10 ( V_17 , L_380 , V_66 -> V_613 . V_72 ) ;
for ( V_145 = 0 ; V_145 < V_66 -> V_613 . V_72 ; ++ V_145 ) {
T_4 V_130 , V_614 , V_615 , V_616 ;
bool V_617 ;
V_130 = V_66 -> V_613 . V_368 [ V_145 ] . V_130 ;
V_614 = V_66 -> V_613 . V_368 [ V_145 ] . V_614 ;
V_615 = V_66 -> V_613 . V_368 [ V_145 ] . V_615 ;
V_616 = F_68 ( V_130 ) ;
V_617 = ( V_615 & V_614 ) == ( V_616 & V_614 ) ;
F_10 ( V_17 , L_381 ,
V_130 , V_615 , V_614 , V_616 , V_617 ? L_382 : L_383 ) ;
}
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_255 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_618 * V_619 ;
struct V_620 * V_621 ;
enum V_124 V_124 ;
int V_125 ;
if ( F_9 ( V_21 ) -> V_24 < 9 )
return 0 ;
F_150 ( V_21 ) ;
V_619 = & V_66 -> V_622 . V_623 . V_619 ;
F_10 ( V_17 , L_384 , L_12 , L_385 , L_386 , L_387 ) ;
F_81 (dev_priv, pipe) {
F_10 ( V_17 , L_388 , F_61 ( V_124 ) ) ;
F_256 (dev_priv, pipe, plane) {
V_621 = & V_619 -> V_125 [ V_124 ] [ V_125 ] ;
F_10 ( V_17 , L_389 , V_125 + 1 ,
V_621 -> V_50 , V_621 -> V_624 ,
F_257 ( V_621 ) ) ;
}
V_621 = & V_619 -> V_431 [ V_124 ] ;
F_10 ( V_17 , L_390 , L_391 , V_621 -> V_50 ,
V_621 -> V_624 , F_257 ( V_621 ) ) ;
}
F_151 ( V_21 ) ;
return 0 ;
}
static void F_258 ( struct V_16 * V_17 ,
struct V_20 * V_21 , struct V_122 * V_122 )
{
struct V_491 * V_491 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_625 * V_626 = & V_66 -> V_626 ;
int V_549 = 0 ;
F_234 (dev, &intel_crtc->base, intel_encoder) {
switch ( V_491 -> type ) {
case V_499 :
F_26 ( V_17 , L_392 ) ;
break;
case V_627 :
F_26 ( V_17 , L_393 ) ;
break;
case V_577 :
F_26 ( V_17 , L_394 ) ;
break;
case V_576 :
F_26 ( V_17 , L_395 ) ;
break;
default:
F_10 ( V_17 , L_396 ,
V_491 -> type ) ;
return;
}
}
if ( V_66 -> V_628 . V_629 == V_630 )
F_26 ( V_17 , L_397 ) ;
else if ( V_66 -> V_628 . V_629 == V_631 )
F_26 ( V_17 , L_398 ) ;
else if ( V_66 -> V_628 . V_629 == V_632 )
F_26 ( V_17 , L_399 ) ;
else
F_26 ( V_17 , L_400 ) ;
F_26 ( V_17 , L_401 ) ;
if ( V_122 -> V_586 -> V_633 ) {
struct V_564 * V_565 ;
F_5 ( & V_626 -> V_634 ) ;
F_26 ( V_17 , L_402 ) ;
if ( ! V_626 -> V_635 ) {
F_26 ( V_17 , L_403 ) ;
F_7 ( & V_626 -> V_634 ) ;
return;
}
V_565 = & V_626 -> V_635 -> V_636 -> V_565 ;
F_10 ( V_17 , L_404 ,
V_626 -> V_484 ) ;
F_26 ( V_17 , L_405 ) ;
if ( V_626 -> V_637 == V_638 ) {
F_26 ( V_17 , L_406 ) ;
V_549 = V_565 -> V_566 -> V_549 ;
} else if ( V_626 -> V_637 == V_639 ) {
F_26 ( V_17 , L_407 ) ;
V_549 = V_565 -> V_640 -> V_549 ;
} else {
F_10 ( V_17 , L_408 ,
V_626 -> V_637 ) ;
F_7 ( & V_626 -> V_634 ) ;
return;
}
F_10 ( V_17 , L_409 , V_549 ) ;
F_26 ( V_17 , L_405 ) ;
F_7 ( & V_626 -> V_634 ) ;
} else {
F_26 ( V_17 , L_410 ) ;
}
F_26 ( V_17 , L_28 ) ;
}
static int F_259 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_122 * V_122 ;
int V_641 = 0 ;
F_60 (dev, intel_crtc) {
F_260 ( & V_122 -> V_34 . V_634 , NULL ) ;
if ( V_122 -> V_97 ) {
V_641 ++ ;
F_10 ( V_17 , L_411 , V_641 ) ;
F_258 ( V_17 , V_21 , V_122 ) ;
}
F_261 ( & V_122 -> V_34 . V_634 ) ;
}
if ( ! V_641 )
F_26 ( V_17 , L_412 ) ;
return 0 ;
}
static int F_262 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_559 * V_492 ;
struct V_491 * V_491 ;
struct V_642 * V_643 ;
F_150 ( V_21 ) ;
F_24 (encoder, &dev->mode_config.encoder_list, head) {
V_491 = F_218 ( V_492 ) ;
if ( V_491 -> type != V_576 )
continue;
V_643 = F_263 ( V_492 ) ;
if ( ! V_643 -> V_635 . V_644 )
continue;
F_264 ( V_17 , & V_643 -> V_635 . V_645 ) ;
}
F_151 ( V_21 ) ;
return 0 ;
}
static int F_265 ( struct V_196 * V_196 , struct V_106 * V_646 )
{
struct V_647 * V_23 = V_196 -> V_197 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_648 * V_649 = & V_66 -> V_649 [ V_23 -> V_124 ] ;
if ( V_23 -> V_124 >= F_9 ( V_23 -> V_21 ) -> V_650 )
return - V_366 ;
F_63 ( & V_649 -> V_315 ) ;
if ( V_649 -> V_651 ) {
F_71 ( & V_649 -> V_315 ) ;
return - V_652 ;
}
V_649 -> V_651 = true ;
V_646 -> V_195 = V_196 -> V_197 ;
F_71 ( & V_649 -> V_315 ) ;
return 0 ;
}
static int F_266 ( struct V_196 * V_196 , struct V_106 * V_646 )
{
struct V_647 * V_23 = V_196 -> V_197 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_648 * V_649 = & V_66 -> V_649 [ V_23 -> V_124 ] ;
F_63 ( & V_649 -> V_315 ) ;
V_649 -> V_651 = false ;
F_71 ( & V_649 -> V_315 ) ;
return 0 ;
}
static int F_267 ( struct V_648 * V_649 )
{
F_268 ( & V_649 -> V_315 ) ;
return F_269 ( V_649 -> V_64 , V_649 -> V_414 ,
V_653 ) ;
}
static T_5
F_270 ( struct V_106 * V_646 , char T_6 * V_654 , T_3 V_72 ,
T_7 * V_199 )
{
struct V_647 * V_23 = V_646 -> V_195 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_648 * V_649 = & V_66 -> V_649 [ V_23 -> V_124 ] ;
char V_205 [ V_655 ] ;
int V_656 ;
T_5 V_657 ;
if ( V_72 < V_658 )
return - V_79 ;
if ( V_649 -> V_659 == V_660 )
return 0 ;
F_63 ( & V_649 -> V_315 ) ;
while ( F_267 ( V_649 ) == 0 ) {
int V_73 ;
if ( V_646 -> V_661 & V_662 ) {
F_71 ( & V_649 -> V_315 ) ;
return - V_663 ;
}
V_73 = F_271 ( V_649 -> V_664 ,
F_267 ( V_649 ) , V_649 -> V_315 ) ;
if ( V_73 ) {
F_71 ( & V_649 -> V_315 ) ;
return V_73 ;
}
}
V_656 = V_72 / V_658 ;
V_657 = 0 ;
while ( V_656 > 0 ) {
struct V_665 * V_621 =
& V_649 -> V_666 [ V_649 -> V_414 ] ;
int V_73 ;
if ( F_269 ( V_649 -> V_64 , V_649 -> V_414 ,
V_653 ) < 1 )
break;
F_272 ( V_653 ) ;
V_649 -> V_414 = ( V_649 -> V_414 + 1 ) & ( V_653 - 1 ) ;
V_657 += snprintf ( V_205 , V_655 ,
L_413 ,
V_621 -> V_667 , V_621 -> V_496 [ 0 ] ,
V_621 -> V_496 [ 1 ] , V_621 -> V_496 [ 2 ] ,
V_621 -> V_496 [ 3 ] , V_621 -> V_496 [ 4 ] ) ;
F_71 ( & V_649 -> V_315 ) ;
V_73 = F_273 ( V_654 , V_205 , V_658 ) ;
if ( V_73 == V_658 )
return - V_668 ;
V_654 += V_658 ;
V_656 -- ;
F_63 ( & V_649 -> V_315 ) ;
}
F_71 ( & V_649 -> V_315 ) ;
return V_657 ;
}
static int F_274 ( struct V_4 * V_669 , struct V_2 * V_3 ,
enum V_124 V_124 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_647 * V_23 = & V_670 [ V_124 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_275 ( V_23 -> V_45 , V_671 , V_669 , V_23 ,
& V_672 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_276 ( enum V_673 V_659 )
{
F_277 ( F_278 ( V_674 ) != V_675 ) ;
return V_674 [ V_659 ] ;
}
static int F_279 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_145 ;
for ( V_145 = 0 ; V_145 < V_676 ; V_145 ++ )
F_10 ( V_17 , L_414 , F_61 ( V_145 ) ,
F_276 ( V_66 -> V_649 [ V_145 ] . V_659 ) ) ;
return 0 ;
}
static int F_280 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
return F_281 ( V_106 , F_279 , V_21 ) ;
}
static int F_282 ( enum V_673 * V_659 ,
T_10 * V_207 )
{
if ( * V_659 == V_677 )
* V_659 = V_678 ;
switch ( * V_659 ) {
case V_678 :
* V_207 = V_679 | V_680 ;
break;
case V_660 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_283 ( struct V_20 * V_21 , enum V_124 V_124 ,
enum V_673 * V_659 )
{
struct V_491 * V_492 ;
struct V_122 * V_123 ;
struct V_642 * V_681 ;
int V_73 = 0 ;
* V_659 = V_678 ;
F_150 ( V_21 ) ;
F_284 (dev, encoder) {
if ( ! V_492 -> V_34 . V_123 )
continue;
V_123 = F_285 ( V_492 -> V_34 . V_123 ) ;
if ( V_123 -> V_124 != V_124 )
continue;
switch ( V_492 -> type ) {
case V_682 :
* V_659 = V_683 ;
break;
case V_576 :
case V_499 :
V_681 = F_263 ( & V_492 -> V_34 ) ;
switch ( V_681 -> V_684 ) {
case V_685 :
* V_659 = V_686 ;
break;
case V_687 :
* V_659 = V_688 ;
break;
case V_689 :
* V_659 = V_690 ;
break;
default:
F_286 ( 1 , L_415 ,
F_287 ( V_681 -> V_684 ) ) ;
break;
}
break;
default:
break;
}
}
F_151 ( V_21 ) ;
return V_73 ;
}
static int F_288 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_673 * V_659 ,
T_10 * V_207 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_691 = false ;
if ( * V_659 == V_677 ) {
int V_73 = F_283 ( V_21 , V_124 , V_659 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_659 ) {
case V_678 :
* V_207 = V_679 | V_692 ;
break;
case V_686 :
* V_207 = V_679 | V_693 ;
V_691 = true ;
break;
case V_688 :
* V_207 = V_679 | V_694 ;
V_691 = true ;
break;
case V_690 :
if ( ! F_80 ( V_21 ) )
return - V_79 ;
* V_207 = V_679 | V_695 ;
V_691 = true ;
break;
case V_660 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_691 ) {
T_10 V_696 = F_68 ( V_697 ) ;
V_696 |= V_698 ;
switch ( V_124 ) {
case V_699 :
V_696 |= V_700 ;
break;
case V_701 :
V_696 |= V_702 ;
break;
case V_703 :
V_696 |= V_704 ;
break;
default:
return - V_79 ;
}
F_153 ( V_697 , V_696 ) ;
}
return 0 ;
}
static int F_289 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_673 * V_659 ,
T_10 * V_207 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_691 = false ;
if ( * V_659 == V_677 ) {
int V_73 = F_283 ( V_21 , V_124 , V_659 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_659 ) {
case V_678 :
* V_207 = V_679 | V_705 ;
break;
case V_683 :
if ( ! F_290 ( V_21 ) )
return - V_79 ;
* V_207 = V_679 | V_706 ;
break;
case V_686 :
if ( ! F_158 ( V_21 ) )
return - V_79 ;
* V_207 = V_679 | V_707 ;
V_691 = true ;
break;
case V_688 :
if ( ! F_158 ( V_21 ) )
return - V_79 ;
* V_207 = V_679 | V_708 ;
V_691 = true ;
break;
case V_690 :
if ( ! F_158 ( V_21 ) )
return - V_79 ;
* V_207 = V_679 | V_709 ;
V_691 = true ;
break;
case V_660 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_691 ) {
T_10 V_696 = F_68 ( V_697 ) ;
F_181 ( ! F_158 ( V_21 ) ) ;
F_153 ( V_710 ,
F_68 ( V_710 ) | V_711 ) ;
if ( V_124 == V_699 )
V_696 |= V_700 ;
else
V_696 |= V_702 ;
F_153 ( V_697 , V_696 ) ;
}
return 0 ;
}
static void F_291 ( struct V_20 * V_21 ,
enum V_124 V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_10 V_696 = F_68 ( V_697 ) ;
switch ( V_124 ) {
case V_699 :
V_696 &= ~ V_700 ;
break;
case V_701 :
V_696 &= ~ V_702 ;
break;
case V_703 :
V_696 &= ~ V_704 ;
break;
default:
return;
}
if ( ! ( V_696 & V_712 ) )
V_696 &= ~ V_698 ;
F_153 ( V_697 , V_696 ) ;
}
static void F_292 ( struct V_20 * V_21 ,
enum V_124 V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_10 V_696 = F_68 ( V_697 ) ;
if ( V_124 == V_699 )
V_696 &= ~ V_700 ;
else
V_696 &= ~ V_702 ;
F_153 ( V_697 , V_696 ) ;
if ( ! ( V_696 & V_712 ) ) {
F_153 ( V_710 ,
F_68 ( V_710 ) & ~ V_711 ) ;
}
}
static int F_293 ( enum V_673 * V_659 ,
T_10 * V_207 )
{
if ( * V_659 == V_677 )
* V_659 = V_678 ;
switch ( * V_659 ) {
case V_713 :
* V_207 = V_679 | V_714 ;
break;
case V_715 :
* V_207 = V_679 | V_716 ;
break;
case V_678 :
* V_207 = V_679 | V_717 ;
break;
case V_660 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static void F_294 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 =
F_285 ( V_66 -> V_718 [ V_699 ] ) ;
F_150 ( V_21 ) ;
if ( V_123 -> V_586 -> V_719 == V_720 &&
! V_123 -> V_586 -> V_721 . V_480 ) {
V_123 -> V_586 -> V_721 . V_722 = true ;
F_295 ( V_66 ,
F_296 ( V_699 ) ) ;
V_66 -> V_723 . V_724 ( & V_123 -> V_34 ) ;
V_66 -> V_723 . V_725 ( & V_123 -> V_34 ) ;
}
F_151 ( V_21 ) ;
}
static void F_297 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 =
F_285 ( V_66 -> V_718 [ V_699 ] ) ;
F_150 ( V_21 ) ;
if ( V_123 -> V_586 -> V_721 . V_722 ) {
V_123 -> V_586 -> V_721 . V_722 = false ;
V_66 -> V_723 . V_724 ( & V_123 -> V_34 ) ;
V_66 -> V_723 . V_725 ( & V_123 -> V_34 ) ;
F_298 ( V_66 ,
F_296 ( V_699 ) ) ;
}
F_151 ( V_21 ) ;
}
static int F_299 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_673 * V_659 ,
T_10 * V_207 )
{
if ( * V_659 == V_677 )
* V_659 = V_726 ;
switch ( * V_659 ) {
case V_713 :
* V_207 = V_679 | V_727 ;
break;
case V_715 :
* V_207 = V_679 | V_728 ;
break;
case V_726 :
if ( F_122 ( V_21 ) && V_124 == V_699 )
F_294 ( V_21 ) ;
* V_207 = V_679 | V_729 ;
break;
case V_660 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_300 ( struct V_20 * V_21 , enum V_124 V_124 ,
enum V_673 V_659 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_648 * V_649 = & V_66 -> V_649 [ V_124 ] ;
struct V_122 * V_123 = F_285 ( F_301 ( V_21 ,
V_124 ) ) ;
T_4 V_207 = 0 ;
int V_73 ;
if ( V_649 -> V_659 == V_659 )
return 0 ;
if ( V_649 -> V_659 && V_659 )
return - V_79 ;
if ( ! F_86 ( V_66 , F_87 ( V_124 ) ) ) {
F_302 ( L_416 ) ;
return - V_730 ;
}
if ( F_303 ( V_21 ) )
V_73 = F_282 ( & V_659 , & V_207 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_73 = F_289 ( V_21 , V_124 , & V_659 , & V_207 ) ;
else if ( F_91 ( V_21 ) )
V_73 = F_288 ( V_21 , V_124 , & V_659 , & V_207 ) ;
else if ( F_115 ( V_21 ) || F_117 ( V_21 ) )
V_73 = F_293 ( & V_659 , & V_207 ) ;
else
V_73 = F_299 ( V_21 , V_124 , & V_659 , & V_207 ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_659 ) {
struct V_665 * V_666 ;
F_97 ( L_417 ,
F_61 ( V_124 ) , F_276 ( V_659 ) ) ;
V_666 = F_304 ( V_653 ,
sizeof( V_649 -> V_666 [ 0 ] ) ,
V_9 ) ;
if ( ! V_666 )
return - V_10 ;
F_305 ( V_123 ) ;
F_63 ( & V_649 -> V_315 ) ;
F_104 ( V_649 -> V_666 ) ;
V_649 -> V_666 = V_666 ;
V_649 -> V_64 = 0 ;
V_649 -> V_414 = 0 ;
F_71 ( & V_649 -> V_315 ) ;
}
V_649 -> V_659 = V_659 ;
F_153 ( F_306 ( V_124 ) , V_207 ) ;
F_307 ( F_306 ( V_124 ) ) ;
if ( V_659 == V_660 ) {
struct V_665 * V_666 ;
struct V_122 * V_123 =
F_285 ( V_66 -> V_718 [ V_124 ] ) ;
F_97 ( L_418 ,
F_61 ( V_124 ) ) ;
F_260 ( & V_123 -> V_34 . V_634 , NULL ) ;
if ( V_123 -> V_97 )
F_308 ( V_21 , V_124 ) ;
F_261 ( & V_123 -> V_34 . V_634 ) ;
F_63 ( & V_649 -> V_315 ) ;
V_666 = V_649 -> V_666 ;
V_649 -> V_666 = NULL ;
V_649 -> V_64 = 0 ;
V_649 -> V_414 = 0 ;
F_71 ( & V_649 -> V_315 ) ;
F_104 ( V_666 ) ;
if ( F_158 ( V_21 ) )
F_292 ( V_21 , V_124 ) ;
else if ( F_91 ( V_21 ) )
F_291 ( V_21 , V_124 ) ;
else if ( F_122 ( V_21 ) && V_124 == V_699 )
F_297 ( V_21 ) ;
F_309 ( V_123 ) ;
}
return 0 ;
}
static int F_310 ( char * V_205 , char * V_731 [] , int V_732 )
{
int V_733 = 0 ;
while ( * V_205 ) {
char * V_624 ;
V_205 = F_311 ( V_205 ) ;
if ( ! * V_205 )
break;
for ( V_624 = V_205 ; * V_624 && ! isspace ( * V_624 ) ; V_624 ++ )
;
if ( V_733 == V_732 ) {
F_97 ( L_419 ,
V_732 ) ;
return - V_79 ;
}
if ( * V_624 )
* V_624 ++ = '\0' ;
V_731 [ V_733 ++ ] = V_205 ;
V_205 = V_624 ;
}
return V_733 ;
}
static int
F_312 ( const char * V_205 , enum V_734 * V_735 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < F_278 ( V_736 ) ; V_145 ++ )
if ( ! strcmp ( V_205 , V_736 [ V_145 ] ) ) {
* V_735 = V_145 ;
return 0 ;
}
return - V_79 ;
}
static int F_313 ( const char * V_205 , enum V_124 * V_124 )
{
const char V_45 = V_205 [ 0 ] ;
if ( V_45 < 'A' || V_45 >= F_61 ( V_676 ) )
return - V_79 ;
* V_124 = V_45 - 'A' ;
return 0 ;
}
static int
F_314 ( const char * V_205 , enum V_673 * V_55 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < F_278 ( V_674 ) ; V_145 ++ )
if ( ! strcmp ( V_205 , V_674 [ V_145 ] ) ) {
* V_55 = V_145 ;
return 0 ;
}
return - V_79 ;
}
static int F_315 ( struct V_20 * V_21 , char * V_205 , T_3 V_737 )
{
#define F_316 3
int V_733 ;
char * V_731 [ F_316 ] ;
enum V_124 V_124 ;
enum V_734 V_738 ;
enum V_673 V_659 ;
V_733 = F_310 ( V_205 , V_731 , F_316 ) ;
if ( V_733 != F_316 ) {
F_97 ( L_420 ,
F_316 ) ;
return - V_79 ;
}
if ( F_312 ( V_731 [ 0 ] , & V_738 ) < 0 ) {
F_97 ( L_421 , V_731 [ 0 ] ) ;
return - V_79 ;
}
if ( F_313 ( V_731 [ 1 ] , & V_124 ) < 0 ) {
F_97 ( L_422 , V_731 [ 1 ] ) ;
return - V_79 ;
}
if ( F_314 ( V_731 [ 2 ] , & V_659 ) < 0 ) {
F_97 ( L_423 , V_731 [ 2 ] ) ;
return - V_79 ;
}
return F_300 ( V_21 , V_124 , V_659 ) ;
}
static T_5 F_317 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_737 , T_7 * V_739 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_740 ;
int V_73 ;
if ( V_737 == 0 )
return 0 ;
if ( V_737 > V_741 - 1 ) {
F_97 ( L_424 ,
V_741 ) ;
return - V_742 ;
}
V_740 = F_3 ( V_737 + 1 , V_9 ) ;
if ( ! V_740 )
return - V_10 ;
if ( F_318 ( V_740 , V_190 , V_737 ) ) {
V_73 = - V_668 ;
goto V_204;
}
V_740 [ V_737 ] = '\0' ;
V_73 = F_315 ( V_21 , V_740 , V_737 ) ;
V_204:
F_104 ( V_740 ) ;
if ( V_73 < 0 )
return V_73 ;
* V_739 += V_737 ;
return V_737 ;
}
static void F_319 ( struct V_16 * V_17 , const T_13 V_622 [ 8 ] )
{
struct V_20 * V_21 = V_17 -> V_19 ;
int V_743 = F_320 ( V_21 ) + 1 ;
int V_744 ;
F_150 ( V_21 ) ;
for ( V_744 = 0 ; V_744 < V_743 ; V_744 ++ ) {
unsigned int V_745 = V_622 [ V_744 ] ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_745 *= 10 ;
else if ( V_744 > 0 )
V_745 *= 5 ;
F_10 ( V_17 , L_425 ,
V_744 , V_622 [ V_744 ] , V_745 / 10 , V_745 % 10 ) ;
}
F_151 ( V_21 ) ;
}
static int F_321 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
const T_13 * V_746 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_746 = V_66 -> V_622 . V_747 ;
else
V_746 = F_23 ( V_21 ) -> V_622 . V_748 ;
F_319 ( V_17 , V_746 ) ;
return 0 ;
}
static int F_322 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
const T_13 * V_746 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_746 = V_66 -> V_622 . V_747 ;
else
V_746 = F_23 ( V_21 ) -> V_622 . V_749 ;
F_319 ( V_17 , V_746 ) ;
return 0 ;
}
static int F_323 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
const T_13 * V_746 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_746 = V_66 -> V_622 . V_747 ;
else
V_746 = F_23 ( V_21 ) -> V_622 . V_750 ;
F_319 ( V_17 , V_746 ) ;
return 0 ;
}
static int F_324 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
if ( F_325 ( V_21 ) )
return - V_366 ;
return F_281 ( V_106 , F_321 , V_21 ) ;
}
static int F_326 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
if ( F_325 ( V_21 ) )
return - V_366 ;
return F_281 ( V_106 , F_322 , V_21 ) ;
}
static int F_327 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
if ( F_325 ( V_21 ) )
return - V_366 ;
return F_281 ( V_106 , F_323 , V_21 ) ;
}
static T_5 F_328 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_737 , T_7 * V_739 , T_13 V_622 [ 8 ] )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
T_13 V_751 [ 8 ] = { 0 } ;
int V_743 = F_320 ( V_21 ) + 1 ;
int V_744 ;
int V_73 ;
char V_696 [ 32 ] ;
if ( V_737 >= sizeof( V_696 ) )
return - V_79 ;
if ( F_318 ( V_696 , V_190 , V_737 ) )
return - V_668 ;
V_696 [ V_737 ] = '\0' ;
V_73 = sscanf ( V_696 , L_426 ,
& V_751 [ 0 ] , & V_751 [ 1 ] , & V_751 [ 2 ] , & V_751 [ 3 ] ,
& V_751 [ 4 ] , & V_751 [ 5 ] , & V_751 [ 6 ] , & V_751 [ 7 ] ) ;
if ( V_73 != V_743 )
return - V_79 ;
F_150 ( V_21 ) ;
for ( V_744 = 0 ; V_744 < V_743 ; V_744 ++ )
V_622 [ V_744 ] = V_751 [ V_744 ] ;
F_151 ( V_21 ) ;
return V_737 ;
}
static T_5 F_329 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_737 , T_7 * V_739 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_13 * V_746 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_746 = V_66 -> V_622 . V_747 ;
else
V_746 = F_23 ( V_21 ) -> V_622 . V_748 ;
return F_328 ( V_106 , V_190 , V_737 , V_739 , V_746 ) ;
}
static T_5 F_330 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_737 , T_7 * V_739 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_13 * V_746 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_746 = V_66 -> V_622 . V_747 ;
else
V_746 = F_23 ( V_21 ) -> V_622 . V_749 ;
return F_328 ( V_106 , V_190 , V_737 , V_739 , V_746 ) ;
}
static T_5 F_331 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_737 , T_7 * V_739 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_13 * V_746 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_746 = V_66 -> V_622 . V_747 ;
else
V_746 = F_23 ( V_21 ) -> V_622 . V_750 ;
return F_328 ( V_106 , V_190 , V_737 , V_739 , V_746 ) ;
}
static int
F_332 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = F_64 ( & V_66 -> V_279 . V_752 ) ;
return 0 ;
}
static int
F_333 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_334 ( & V_66 -> V_279 ) )
return - V_663 ;
F_77 ( V_66 ) ;
F_335 ( V_21 , V_207 ,
L_427 , V_207 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int
F_336 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = V_66 -> V_279 . V_753 ;
return 0 ;
}
static int
F_337 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_97 ( L_428 , V_207 ) ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_279 . V_753 = V_207 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_338 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = V_66 -> V_279 . V_754 ;
return 0 ;
}
static int
F_339 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_279 . V_754 = V_207 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_340 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = V_66 -> V_279 . V_755 ;
return 0 ;
}
static int
F_341 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_97 ( L_429 , V_207 ) ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_279 . V_755 = V_207 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_342 ( void * V_18 , T_8 * V_207 )
{
* V_207 = V_756 ;
return 0 ;
}
static int
F_343 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_344 ( L_430 , V_207 ) ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( V_207 & V_757 ) {
V_73 = F_345 ( V_21 ) ;
if ( V_73 )
goto V_758;
}
if ( V_207 & ( V_759 | V_757 ) )
F_346 ( V_21 ) ;
if ( V_207 & V_760 )
F_347 ( V_66 , V_761 , V_762 ) ;
if ( V_207 & V_763 )
F_347 ( V_66 , V_761 , V_764 ) ;
V_758:
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int
F_348 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_366 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_270 ) ;
if ( V_73 )
return V_73 ;
* V_207 = F_123 ( V_66 , V_66 -> V_209 . V_391 ) ;
F_7 ( & V_66 -> V_209 . V_270 ) ;
return 0 ;
}
static int
F_349 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_765 , V_766 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_366 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
F_97 ( L_431 , V_207 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_270 ) ;
if ( V_73 )
return V_73 ;
V_207 = F_350 ( V_66 , V_207 ) ;
V_765 = V_66 -> V_209 . V_242 ;
V_766 = V_66 -> V_209 . V_273 ;
if ( V_207 < V_766 || V_207 > V_765 || V_207 < V_66 -> V_209 . V_390 ) {
F_7 ( & V_66 -> V_209 . V_270 ) ;
return - V_79 ;
}
V_66 -> V_209 . V_391 = V_207 ;
F_351 ( V_21 , V_207 ) ;
F_7 ( & V_66 -> V_209 . V_270 ) ;
return 0 ;
}
static int
F_352 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_366 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_270 ) ;
if ( V_73 )
return V_73 ;
* V_207 = F_123 ( V_66 , V_66 -> V_209 . V_390 ) ;
F_7 ( & V_66 -> V_209 . V_270 ) ;
return 0 ;
}
static int
F_353 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_765 , V_766 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_366 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
F_97 ( L_432 , V_207 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_270 ) ;
if ( V_73 )
return V_73 ;
V_207 = F_350 ( V_66 , V_207 ) ;
V_765 = V_66 -> V_209 . V_242 ;
V_766 = V_66 -> V_209 . V_273 ;
if ( V_207 < V_766 || V_207 > V_765 || V_207 > V_66 -> V_209 . V_391 ) {
F_7 ( & V_66 -> V_209 . V_270 ) ;
return - V_79 ;
}
V_66 -> V_209 . V_390 = V_207 ;
F_351 ( V_21 , V_207 ) ;
F_7 ( & V_66 -> V_209 . V_270 ) ;
return 0 ;
}
static int
F_354 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_767 ;
int V_73 ;
if ( ! ( F_117 ( V_21 ) || F_118 ( V_21 ) ) )
return - V_366 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
V_767 = F_68 ( V_768 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_66 -> V_21 -> V_74 ) ;
* V_207 = ( V_767 & V_769 ) >> V_770 ;
return 0 ;
}
static int
F_355 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_767 ;
if ( ! ( F_117 ( V_21 ) || F_118 ( V_21 ) ) )
return - V_366 ;
if ( V_207 > 3 )
return - V_79 ;
F_77 ( V_66 ) ;
F_97 ( L_433 , V_207 ) ;
V_767 = F_68 ( V_768 ) ;
V_767 &= ~ V_769 ;
V_767 |= ( V_207 << V_770 ) ;
F_153 ( V_768 , V_767 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_356 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned int V_771 = 0 , V_772 = 0 , V_773 = 0 , V_774 = 0 , V_775 = 0 ;
if ( ( F_9 ( V_21 ) -> V_24 < 8 ) || F_119 ( V_21 ) )
return - V_366 ;
F_26 ( V_17 , L_434 ) ;
F_10 ( V_17 , L_435 ,
F_9 ( V_21 ) -> V_776 ) ;
F_10 ( V_17 , L_436 ,
F_9 ( V_21 ) -> V_777 ) ;
F_10 ( V_17 , L_437 ,
F_9 ( V_21 ) -> V_778 ) ;
F_10 ( V_17 , L_438 ,
F_9 ( V_21 ) -> V_779 ) ;
F_10 ( V_17 , L_439 ,
F_9 ( V_21 ) -> V_780 ) ;
F_10 ( V_17 , L_440 ,
F_1 ( F_9 ( V_21 ) -> V_781 ) ) ;
F_10 ( V_17 , L_441 ,
F_1 ( F_9 ( V_21 ) -> V_782 ) ) ;
F_10 ( V_17 , L_442 ,
F_1 ( F_9 ( V_21 ) -> V_783 ) ) ;
F_26 ( V_17 , L_443 ) ;
if ( F_80 ( V_21 ) ) {
const int V_784 = 2 ;
int V_785 ;
T_4 V_786 [ V_784 ] , V_787 [ V_784 ] ;
V_786 [ 0 ] = F_68 ( V_788 ) ;
V_786 [ 1 ] = F_68 ( V_789 ) ;
V_787 [ 0 ] = F_68 ( V_790 ) ;
V_787 [ 1 ] = F_68 ( V_791 ) ;
for ( V_785 = 0 ; V_785 < V_784 ; V_785 ++ ) {
unsigned int V_792 ;
if ( V_786 [ V_785 ] & V_793 )
continue;
V_771 = 1 ;
V_773 ++ ;
V_792 = ( ( V_786 [ V_785 ] & V_794 ) ? 0 : 2 ) +
( ( V_786 [ V_785 ] & V_795 ) ? 0 : 2 ) +
( ( V_786 [ V_785 ] & V_796 ) ? 0 : 2 ) +
( ( V_787 [ V_785 ] & V_797 ) ? 0 : 2 ) ;
V_774 += V_792 ;
V_775 = F_357 ( V_775 , V_792 ) ;
}
V_772 = V_773 ;
} else if ( F_126 ( V_21 ) ) {
const int V_798 = 3 , V_784 = 4 ;
int V_55 , V_785 ;
T_4 V_799 [ V_798 ] , V_800 [ 2 * V_798 ] , V_801 [ 2 ] ;
V_799 [ 0 ] = F_68 ( V_802 ) ;
V_799 [ 1 ] = F_68 ( V_803 ) ;
V_799 [ 2 ] = F_68 ( V_804 ) ;
V_800 [ 0 ] = F_68 ( V_805 ) ;
V_800 [ 1 ] = F_68 ( V_806 ) ;
V_800 [ 2 ] = F_68 ( V_807 ) ;
V_800 [ 3 ] = F_68 ( V_808 ) ;
V_800 [ 4 ] = F_68 ( V_809 ) ;
V_800 [ 5 ] = F_68 ( V_810 ) ;
V_801 [ 0 ] = V_811 |
V_812 |
V_813 |
V_814 ;
V_801 [ 1 ] = V_815 |
V_816 |
V_817 |
V_818 ;
for ( V_55 = 0 ; V_55 < V_798 ; V_55 ++ ) {
if ( ( V_799 [ V_55 ] & V_819 ) == 0 )
continue;
V_771 ++ ;
V_773 = F_9 ( V_21 ) -> V_778 ;
V_772 += V_773 ;
for ( V_785 = 0 ; V_785 < V_784 ; V_785 ++ ) {
unsigned int V_792 ;
V_792 = 2 * F_251 ( V_800 [ 2 * V_55 + V_785 / 2 ] &
V_801 [ V_785 % 2 ] ) ;
V_774 += V_792 ;
V_775 = F_357 ( V_775 , V_792 ) ;
}
}
}
F_10 ( V_17 , L_444 , V_771 ) ;
F_10 ( V_17 , L_445 , V_772 ) ;
F_10 ( V_17 , L_446 , V_773 ) ;
F_10 ( V_17 , L_447 , V_774 ) ;
F_10 ( V_17 , L_448 , V_775 ) ;
return 0 ;
}
static int F_358 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_77 ( V_66 ) ;
F_121 ( V_66 , V_243 ) ;
return 0 ;
}
static int F_359 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_124 ( V_66 , V_243 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_360 ( struct V_4 * V_669 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_275 ( L_449 ,
V_820 ,
V_669 , V_21 ,
& V_821 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_821 ) ;
}
static int F_361 ( struct V_4 * V_669 ,
struct V_2 * V_3 ,
const char * V_45 ,
const struct V_822 * V_823 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_275 ( V_45 ,
V_671 | V_824 ,
V_669 , V_21 ,
V_823 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_823 ) ;
}
void F_362 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
enum V_124 V_124 ;
F_81 (dev_priv, pipe) {
struct V_648 * V_649 = & V_66 -> V_649 [ V_124 ] ;
V_649 -> V_651 = false ;
F_363 ( & V_649 -> V_315 ) ;
F_364 ( & V_649 -> V_664 ) ;
}
}
int F_365 ( struct V_2 * V_3 )
{
int V_73 , V_145 ;
V_73 = F_360 ( V_3 -> V_825 , V_3 ) ;
if ( V_73 )
return V_73 ;
for ( V_145 = 0 ; V_145 < F_278 ( V_670 ) ; V_145 ++ ) {
V_73 = F_274 ( V_3 -> V_825 , V_3 , V_145 ) ;
if ( V_73 )
return V_73 ;
}
for ( V_145 = 0 ; V_145 < F_278 ( V_826 ) ; V_145 ++ ) {
V_73 = F_361 ( V_3 -> V_825 , V_3 ,
V_826 [ V_145 ] . V_45 ,
V_826 [ V_145 ] . V_823 ) ;
if ( V_73 )
return V_73 ;
}
return F_366 ( V_827 ,
V_828 ,
V_3 -> V_825 , V_3 ) ;
}
void F_367 ( struct V_2 * V_3 )
{
int V_145 ;
F_368 ( V_827 ,
V_828 , V_3 ) ;
F_368 ( (struct V_829 * ) & V_821 ,
1 , V_3 ) ;
for ( V_145 = 0 ; V_145 < F_278 ( V_670 ) ; V_145 ++ ) {
struct V_829 * V_830 =
(struct V_829 * ) & V_670 [ V_145 ] ;
F_368 ( V_830 , 1 , V_3 ) ;
}
for ( V_145 = 0 ; V_145 < F_278 ( V_826 ) ; V_145 ++ ) {
struct V_829 * V_830 =
(struct V_829 * ) V_826 [ V_145 ] . V_823 ;
F_368 ( V_830 , 1 , V_3 ) ;
}
}
