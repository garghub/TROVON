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
F_24 (vma, &obj->vma_list, vma_link)
if ( V_32 -> V_33 > 0 )
V_33 ++ ;
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
F_66 ( V_21 , V_123 -> V_124 ) ) ;
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
F_119 ( V_21 ) ) {
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
F_120 ( V_66 , V_243 ) ;
V_230 = F_68 ( V_244 ) ;
V_230 &= ~ V_245 ;
if ( F_121 ( V_21 ) || F_119 ( V_21 ) )
V_230 >>= 24 ;
else
V_230 >>= 25 ;
V_230 = F_122 ( V_66 , V_230 ) ;
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
if ( F_121 ( V_21 ) || F_119 ( V_21 ) )
V_229 = ( V_228 & V_256 ) >> V_257 ;
else
V_229 = ( V_228 & V_258 ) >> V_259 ;
V_229 = F_122 ( V_66 , V_229 ) ;
F_123 ( V_66 , V_243 ) ;
F_7 ( & V_21 -> V_74 ) ;
if ( F_117 ( V_21 ) || F_118 ( V_21 ) ) {
V_237 = F_68 ( V_171 ) ;
V_238 = F_68 ( V_173 ) ;
V_239 = F_68 ( V_260 ) ;
V_240 = F_68 ( V_172 ) ;
V_241 = F_68 ( V_261 ) ;
} else {
V_237 = F_68 ( F_85 ( 2 ) ) ;
V_238 = F_68 ( F_83 ( 2 ) ) ;
V_239 = F_68 ( F_124 ( 2 ) ) ;
V_240 = F_68 ( F_84 ( 2 ) ) ;
V_241 = F_68 ( V_261 ) ;
}
F_10 ( V_17 , L_116 ,
V_237 , V_238 , V_239 , V_240 , V_241 ) ;
F_10 ( V_17 , L_117 , V_219 ) ;
F_10 ( V_17 , L_118 ,
( V_219 & 0xff00 ) >> 8 ) ;
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
V_262 ) ;
F_10 ( V_17 , L_128 , V_232 &
V_263 ) ;
F_10 ( V_17 , L_129 , V_233 &
V_263 ) ;
F_10 ( V_17 , L_130 , V_234 &
V_264 ) ;
F_10 ( V_17 , L_131 , V_235 &
V_263 ) ;
F_10 ( V_17 , L_132 , V_236 &
V_263 ) ;
V_242 = ( V_223 & 0xff0000 ) >> 16 ;
F_10 ( V_17 , L_133 ,
F_122 ( V_66 , V_242 ) ) ;
V_242 = ( V_223 & 0xff00 ) >> 8 ;
F_10 ( V_17 , L_134 ,
F_122 ( V_66 , V_242 ) ) ;
V_242 = V_223 & 0xff ;
F_10 ( V_17 , L_135 ,
F_122 ( V_66 , V_242 ) ) ;
F_10 ( V_17 , L_136 ,
F_122 ( V_66 , V_66 -> V_209 . V_242 ) ) ;
} else if ( F_91 ( V_21 ) ) {
T_4 V_265 ;
F_5 ( & V_66 -> V_209 . V_266 ) ;
V_265 = F_125 ( V_66 , V_267 ) ;
F_10 ( V_17 , L_137 , V_265 ) ;
F_10 ( V_17 , L_138 , V_66 -> V_268 ) ;
F_10 ( V_17 , L_139 ,
F_122 ( V_66 , V_66 -> V_209 . V_242 ) ) ;
F_10 ( V_17 , L_140 ,
F_122 ( V_66 , V_66 -> V_209 . V_269 ) ) ;
F_10 ( V_17 ,
L_141 ,
F_122 ( V_66 , V_66 -> V_209 . V_270 ) ) ;
F_10 ( V_17 , L_142 ,
F_122 ( V_66 , ( V_265 >> 8 ) & 0xff ) ) ;
F_7 ( & V_66 -> V_209 . V_266 ) ;
} else {
F_26 ( V_17 , L_143 ) ;
}
V_204:
F_78 ( V_66 ) ;
return V_73 ;
}
static int F_126 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
T_8 V_271 [ V_272 ] ;
T_4 V_147 [ V_272 ] ;
int V_145 ;
if ( ! V_273 . V_274 ) {
F_10 ( V_17 , L_144 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
F_74 (ring, dev_priv, i) {
V_147 [ V_145 ] = V_135 -> V_137 ( V_135 , false ) ;
V_271 [ V_145 ] = F_127 ( V_135 ) ;
}
F_78 ( V_66 ) ;
if ( F_128 ( & V_66 -> V_275 . V_276 ) ) {
F_10 ( V_17 , L_145 ,
F_129 ( V_66 -> V_275 . V_276 . V_277 . V_278 -
V_148 ) ) ;
} else
F_10 ( V_17 , L_146 ) ;
F_74 (ring, dev_priv, i) {
F_10 ( V_17 , L_147 , V_135 -> V_45 ) ;
F_10 ( V_17 , L_148 ,
V_135 -> V_279 . V_147 , V_147 [ V_145 ] ) ;
F_10 ( V_17 , L_149 ,
( long long ) V_135 -> V_279 . V_271 ,
( long long ) V_271 [ V_145 ] ) ;
F_10 ( V_17 , L_150 ,
( long long ) V_135 -> V_279 . V_280 ) ;
F_10 ( V_17 , L_151 , V_135 -> V_279 . V_281 ) ;
F_10 ( V_17 , L_152 , V_135 -> V_279 . V_282 ) ;
}
return 0 ;
}
static int F_130 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_283 , V_284 ;
T_9 V_285 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
V_283 = F_68 ( V_286 ) ;
V_284 = F_68 ( V_287 ) ;
V_285 = F_116 ( V_288 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_153 , ( V_283 & V_289 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_154 ,
( V_283 & V_290 ) >>
V_291 ) ;
F_10 ( V_17 , L_155 ,
V_283 & V_292 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_156 ,
V_283 & V_293 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_157 ,
V_283 & V_294 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_158 ,
( V_283 & V_295 ) >> V_296 ) ;
F_10 ( V_17 , L_159 ,
( V_283 & V_297 ) >> V_298 ) ;
F_10 ( V_17 , L_160 , ( V_283 & V_299 ) ) ;
F_10 ( V_17 , L_161 , ( V_285 & 0x3f ) ) ;
F_10 ( V_17 , L_162 , ( ( V_285 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_163 ,
( V_284 & V_300 ) ? L_2 : L_1 ) ;
F_26 ( V_17 , L_164 ) ;
switch ( V_284 & V_301 ) {
case V_302 :
F_26 ( V_17 , L_165 ) ;
break;
case V_303 :
F_26 ( V_17 , L_166 ) ;
break;
case V_304 :
F_26 ( V_17 , L_167 ) ;
break;
case V_305 :
F_26 ( V_17 , L_168 ) ;
break;
case V_306 :
F_26 ( V_17 , L_169 ) ;
break;
case V_307 :
F_26 ( V_17 , L_170 ) ;
break;
default:
F_26 ( V_17 , L_171 ) ;
break;
}
return 0 ;
}
static int F_131 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_308 * V_309 ;
int V_145 ;
F_63 ( & V_66 -> V_310 . V_311 ) ;
F_132 (fw_domain, dev_priv, i) {
F_10 ( V_17 , L_172 ,
F_133 ( V_145 ) ,
V_309 -> V_312 ) ;
}
F_71 ( & V_66 -> V_310 . V_311 ) ;
return 0 ;
}
static int F_134 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_313 , V_314 , V_315 ;
F_77 ( V_66 ) ;
V_315 = F_68 ( V_316 ) ;
V_313 = F_68 ( V_246 ) ;
V_314 = F_68 ( V_317 ) ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_173 ,
F_1 ( V_313 & V_318 ) ) ;
F_10 ( V_17 , L_174 ,
F_1 ( V_313 & V_319 ) ) ;
F_10 ( V_17 , L_155 ,
F_1 ( V_313 & V_319 ) ) ;
F_10 ( V_17 , L_156 ,
F_1 ( ( V_313 & V_320 ) ==
V_321 ) ) ;
F_10 ( V_17 , L_175 ,
F_1 ( V_314 & ( V_322 |
F_135 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_176 ,
( V_315 & V_323 ) ? L_177 : L_178 ) ;
F_10 ( V_17 , L_179 ,
( V_315 & V_324 ) ? L_177 : L_178 ) ;
F_10 ( V_17 , L_180 ,
F_68 ( V_325 ) ) ;
F_10 ( V_17 , L_181 ,
F_68 ( V_326 ) ) ;
return F_131 ( V_17 , NULL ) ;
}
static int F_136 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_313 , V_327 , V_314 , V_328 = 0 ;
unsigned V_329 ;
int V_72 = 0 , V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
F_63 ( & V_66 -> V_310 . V_311 ) ;
V_329 = V_66 -> V_310 . V_309 [ V_330 ] . V_312 ;
F_71 ( & V_66 -> V_310 . V_311 ) ;
if ( V_329 ) {
F_26 ( V_17 , L_182
L_183 ) ;
} else {
while ( V_72 ++ < 50 && ( F_137 ( V_331 ) & 1 ) )
F_138 ( 10 ) ;
F_10 ( V_17 , L_184 , F_1 ( V_72 < 51 ) ) ;
}
V_327 = F_139 ( V_66 -> V_332 + V_333 ) ;
F_140 ( false , V_333 , V_327 , 4 , true ) ;
V_313 = F_68 ( V_246 ) ;
V_314 = F_68 ( V_317 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_5 ( & V_66 -> V_209 . V_266 ) ;
F_141 ( V_66 , V_334 , & V_328 ) ;
F_7 ( & V_66 -> V_209 . V_266 ) ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_173 ,
F_1 ( V_313 & V_318 ) ) ;
F_10 ( V_17 , L_155 ,
F_1 ( V_313 & V_319 ) ) ;
F_10 ( V_17 , L_156 ,
F_1 ( ( V_313 & V_320 ) ==
V_321 ) ) ;
F_10 ( V_17 , L_185 ,
F_1 ( V_314 & V_335 ) ) ;
F_10 ( V_17 , L_175 ,
F_1 ( V_314 & V_336 ) ) ;
F_10 ( V_17 , L_186 ,
F_1 ( V_314 & V_337 ) ) ;
F_10 ( V_17 , L_187 ,
F_1 ( V_314 & V_338 ) ) ;
F_26 ( V_17 , L_188 ) ;
switch ( V_327 & V_339 ) {
case V_340 :
if ( V_327 & V_341 )
F_26 ( V_17 , L_189 ) ;
else
F_26 ( V_17 , L_165 ) ;
break;
case V_342 :
F_26 ( V_17 , L_190 ) ;
break;
case V_343 :
F_26 ( V_17 , L_191 ) ;
break;
case V_344 :
F_26 ( V_17 , L_192 ) ;
break;
default:
F_26 ( V_17 , L_193 ) ;
break;
}
F_10 ( V_17 , L_194 ,
F_1 ( V_327 & V_341 ) ) ;
F_10 ( V_17 , L_195 ,
F_68 ( V_345 ) ) ;
F_10 ( V_17 , L_196 ,
F_68 ( V_346 ) ) ;
F_10 ( V_17 , L_197 ,
F_68 ( V_347 ) ) ;
F_10 ( V_17 , L_198 ,
F_68 ( V_348 ) ) ;
F_10 ( V_17 , L_199 ,
F_142 ( ( ( V_328 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_200 ,
F_142 ( ( ( V_328 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_201 ,
F_142 ( ( ( V_328 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_143 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_91 ( V_21 ) )
return F_134 ( V_17 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
return F_136 ( V_17 ) ;
else
return F_130 ( V_17 ) ;
}
static int F_144 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_145 ( V_21 ) ) {
F_26 ( V_17 , L_202 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
if ( F_146 ( V_21 ) ) {
F_26 ( V_17 , L_203 ) ;
} else {
F_26 ( V_17 , L_204 ) ;
switch ( V_66 -> V_349 . V_350 ) {
case V_351 :
F_26 ( V_17 , L_205 ) ;
break;
case V_352 :
F_26 ( V_17 , L_206 ) ;
break;
case V_353 :
F_26 ( V_17 , L_207 ) ;
break;
case V_354 :
F_26 ( V_17 , L_208 ) ;
break;
case V_355 :
F_26 ( V_17 , L_209 ) ;
break;
case V_356 :
F_26 ( V_17 , L_210 ) ;
break;
case V_357 :
F_26 ( V_17 , L_211 ) ;
break;
case V_358 :
F_26 ( V_17 , L_212 ) ;
break;
case V_359 :
F_26 ( V_17 , L_213 ) ;
break;
case V_360 :
F_26 ( V_17 , L_214 ) ;
break;
case V_361 :
F_26 ( V_17 , L_215 ) ;
break;
default:
F_26 ( V_17 , L_216 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_78 ( V_66 ) ;
return 0 ;
}
static int F_147 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_145 ( V_21 ) )
return - V_362 ;
F_148 ( V_21 ) ;
* V_207 = V_66 -> V_349 . V_363 ;
F_149 ( V_21 ) ;
return 0 ;
}
static int F_150 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_364 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_145 ( V_21 ) )
return - V_362 ;
F_148 ( V_21 ) ;
V_364 = F_68 ( V_365 ) ;
V_66 -> V_349 . V_363 = V_207 ;
F_151 ( V_365 , V_207 ?
( V_364 | V_366 ) :
( V_364 & ~ V_366 ) ) ;
F_149 ( V_21 ) ;
return 0 ;
}
static int F_152 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_153 ( V_21 ) ) {
F_26 ( V_17 , L_217 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
F_10 ( V_17 , L_218 ,
F_1 ( V_273 . V_367 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_26 ( V_17 , L_219 ) ;
} else {
if ( F_68 ( V_368 ) & V_369 )
F_26 ( V_17 , L_220 ) ;
else
F_26 ( V_17 , L_221 ) ;
}
F_78 ( V_66 ) ;
return 0 ;
}
static int F_154 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_370 = false ;
F_77 ( V_66 ) ;
if ( F_92 ( V_21 ) )
V_370 = F_68 ( V_371 ) & V_372 ;
else if ( F_155 ( V_21 ) || F_156 ( V_21 ) || F_157 ( V_21 ) )
V_370 = F_68 ( V_373 ) & V_374 ;
else if ( F_158 ( V_21 ) )
V_370 = F_68 ( V_375 ) & V_376 ;
else if ( F_159 ( V_21 ) )
V_370 = F_68 ( V_377 ) & V_378 ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_222 ,
V_370 ? L_223 : L_224 ) ;
return 0 ;
}
static int F_160 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned long V_379 , V_380 , V_381 ;
int V_73 ;
if ( ! F_115 ( V_21 ) )
return - V_362 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_379 = F_161 ( V_66 ) ;
V_380 = F_162 ( V_66 ) ;
V_381 = F_163 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_225 , V_379 ) ;
F_10 ( V_17 , L_226 , V_380 ) ;
F_10 ( V_17 , L_227 , V_381 ) ;
F_10 ( V_17 , L_228 , V_380 + V_381 ) ;
return 0 ;
}
static int F_164 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
int V_382 , V_383 ;
if ( ! ( F_117 ( V_21 ) || F_118 ( V_21 ) ) ) {
F_26 ( V_17 , L_229 ) ;
return 0 ;
}
F_77 ( V_66 ) ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_266 ) ;
if ( V_73 )
goto V_204;
F_26 ( V_17 , L_230 ) ;
for ( V_382 = V_66 -> V_209 . V_384 ;
V_382 <= V_66 -> V_209 . V_385 ;
V_382 ++ ) {
V_383 = V_382 ;
F_141 ( V_66 ,
V_386 ,
& V_383 ) ;
F_10 ( V_17 , L_231 ,
F_122 ( V_66 , V_382 ) ,
( ( V_383 >> 0 ) & 0xff ) * 100 ,
( ( V_383 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_66 -> V_209 . V_266 ) ;
V_204:
F_78 ( V_66 ) ;
return V_73 ;
}
static int F_165 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_387 * V_388 = & V_66 -> V_388 ;
void * V_18 = F_3 ( V_389 , V_9 ) ;
int V_73 ;
if ( V_18 == NULL )
return - V_10 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_204;
if ( V_388 -> V_390 ) {
F_166 ( V_18 , V_388 -> V_390 , V_389 ) ;
F_167 ( V_17 , V_18 , V_389 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
V_204:
F_104 ( V_18 ) ;
return 0 ;
}
static int F_168 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_391 * V_392 = NULL ;
struct V_393 * V_394 ;
#ifdef F_169
struct V_65 * V_66 = V_21 -> V_67 ;
V_392 = V_66 -> V_395 ;
V_394 = F_170 ( V_392 -> V_396 . V_394 ) ;
F_10 ( V_17 , L_232 ,
V_394 -> V_34 . V_397 ,
V_394 -> V_34 . V_398 ,
V_394 -> V_34 . V_399 ,
V_394 -> V_34 . V_400 ,
F_64 ( & V_394 -> V_34 . V_401 . V_401 ) ) ;
F_20 ( V_17 , V_394 -> V_26 ) ;
F_29 ( V_17 , '\n' ) ;
#endif
F_5 ( & V_21 -> V_402 . V_403 ) ;
F_24 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_392 && & V_394 -> V_34 == V_392 -> V_396 . V_394 )
continue;
F_10 ( V_17 , L_233 ,
V_394 -> V_34 . V_397 ,
V_394 -> V_34 . V_398 ,
V_394 -> V_34 . V_399 ,
V_394 -> V_34 . V_400 ,
F_64 ( & V_394 -> V_34 . V_401 . V_401 ) ) ;
F_20 ( V_17 , V_394 -> V_26 ) ;
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_402 . V_403 ) ;
return 0 ;
}
static void F_171 ( struct V_16 * V_17 ,
struct V_404 * V_405 )
{
F_10 ( V_17 , L_234 ,
V_405 -> V_406 , V_405 -> V_64 , V_405 -> V_407 ,
V_405 -> V_408 ) ;
}
static int F_172 ( struct V_16 * V_17 , void * V_208 )
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
if ( V_66 -> V_409 . V_410 ) {
F_26 ( V_17 , L_235 ) ;
F_20 ( V_17 , V_66 -> V_409 . V_410 ) ;
F_29 ( V_17 , '\n' ) ;
}
if ( V_66 -> V_409 . V_411 ) {
F_26 ( V_17 , L_236 ) ;
F_20 ( V_17 , V_66 -> V_409 . V_411 ) ;
F_29 ( V_17 , '\n' ) ;
}
F_24 (ctx, &dev_priv->context_list, link) {
if ( ! V_273 . V_412 &&
V_59 -> V_60 . V_413 == NULL )
continue;
F_26 ( V_17 , L_237 ) ;
F_28 ( V_17 , V_59 ) ;
F_74 (ring, dev_priv, i) {
if ( V_135 -> V_414 == V_59 )
F_10 ( V_17 , L_238 ,
V_135 -> V_45 ) ;
}
if ( V_273 . V_412 ) {
F_29 ( V_17 , '\n' ) ;
F_74 (ring, dev_priv, i) {
struct V_25 * V_415 =
V_59 -> V_416 [ V_145 ] . V_417 ;
struct V_404 * V_405 =
V_59 -> V_416 [ V_145 ] . V_405 ;
F_10 ( V_17 , L_239 , V_135 -> V_45 ) ;
if ( V_415 )
F_20 ( V_17 , V_415 ) ;
if ( V_405 )
F_171 ( V_17 , V_405 ) ;
F_29 ( V_17 , '\n' ) ;
}
} else {
F_20 ( V_17 , V_59 -> V_60 . V_413 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static void F_173 ( struct V_16 * V_17 ,
struct V_134 * V_135 ,
struct V_25 * V_415 )
{
struct V_418 * V_418 ;
T_10 * V_419 ;
int V_420 ;
unsigned long V_421 = 0 ;
if ( V_415 == NULL ) {
F_10 ( V_17 , L_240 ,
V_135 -> V_45 ) ;
return;
}
F_10 ( V_17 , L_241 , V_135 -> V_45 ,
F_174 ( V_415 ) ) ;
if ( ! F_45 ( V_415 ) )
F_26 ( V_17 , L_242 ) ;
else
V_421 = F_175 ( V_415 ) ;
if ( F_176 ( V_415 ) ) {
F_26 ( V_17 , L_243 ) ;
return;
}
V_418 = F_177 ( V_415 , 1 ) ;
if ( ! F_178 ( V_418 == NULL ) ) {
V_419 = F_179 ( V_418 ) ;
for ( V_420 = 0 ; V_420 < 0x600 / sizeof( T_4 ) / 4 ; V_420 += 4 ) {
F_10 ( V_17 , L_244 ,
V_421 + 4096 + ( V_420 * 4 ) ,
V_419 [ V_420 ] , V_419 [ V_420 + 1 ] ,
V_419 [ V_420 + 2 ] , V_419 [ V_420 + 3 ] ) ;
}
F_180 ( V_419 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
static int F_181 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_58 * V_59 ;
int V_73 , V_145 ;
if ( ! V_273 . V_412 ) {
F_10 ( V_17 , L_245 ) ;
return 0 ;
}
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_24 (ctx, &dev_priv->context_list, link) {
F_74 (ring, dev_priv, i) {
if ( V_135 -> V_414 != V_59 )
F_173 ( V_17 , V_135 ,
V_59 -> V_416 [ V_145 ] . V_417 ) ;
}
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_182 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
T_4 V_422 ;
T_11 V_423 ;
T_11 V_424 ;
T_4 V_425 ;
T_4 V_426 ;
struct V_63 * V_427 ;
int V_428 , V_145 ;
int V_73 ;
if ( ! V_273 . V_412 ) {
F_26 ( V_17 , L_245 ) ;
return 0 ;
}
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
F_74 (ring, dev_priv, ring_id) {
struct V_143 * V_429 = NULL ;
int V_72 = 0 ;
unsigned long V_430 ;
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
V_425 = F_68 ( F_183 ( V_135 ) ) ;
V_426 = F_68 ( F_183 ( V_135 ) + 4 ) ;
F_10 ( V_17 , L_247 ,
V_425 , V_426 ) ;
V_422 = F_68 ( F_184 ( V_135 ) ) ;
F_10 ( V_17 , L_248 , V_422 ) ;
V_423 = V_135 -> V_431 ;
V_424 = V_422 & 0x07 ;
if ( V_423 > V_424 )
V_424 += 6 ;
F_10 ( V_17 , L_249 ,
V_423 , V_424 ) ;
for ( V_145 = 0 ; V_145 < 6 ; V_145 ++ ) {
V_425 = F_68 ( F_185 ( V_135 ) + 8 * V_145 ) ;
V_426 = F_68 ( F_185 ( V_135 ) + 8 * V_145 + 4 ) ;
F_10 ( V_17 , L_250 ,
V_145 , V_425 , V_426 ) ;
}
F_186 ( & V_135 -> V_432 , V_430 ) ;
F_187 (cursor, &ring->execlist_queue)
V_72 ++ ;
V_429 = F_188 ( & V_135 -> V_433 ,
struct V_143 , V_434 ) ;
F_189 ( & V_135 -> V_432 , V_430 ) ;
F_10 ( V_17 , L_251 , V_72 ) ;
if ( V_429 ) {
struct V_25 * V_415 ;
V_415 = V_429 -> V_59 -> V_416 [ V_428 ] . V_417 ;
F_10 ( V_17 , L_252 ,
F_174 ( V_415 ) ) ;
F_10 ( V_17 , L_253 ,
V_429 -> V_407 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static const char * F_190 ( unsigned V_435 )
{
switch ( V_435 ) {
case V_436 :
return L_254 ;
case V_437 :
return L_255 ;
case V_438 :
return L_256 ;
case V_439 :
return L_257 ;
case V_440 :
return L_258 ;
case V_441 :
return L_259 ;
case V_442 :
return L_260 ;
case V_443 :
return L_261 ;
}
return L_262 ;
}
static int F_191 ( struct V_16 * V_17 , void * V_18 )
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
F_190 ( V_66 -> V_107 . V_444 ) ) ;
F_10 ( V_17 , L_264 ,
F_190 ( V_66 -> V_107 . V_445 ) ) ;
if ( F_192 ( V_21 ) || F_193 ( V_21 ) ) {
F_10 ( V_17 , L_265 ,
F_68 ( V_446 ) ) ;
F_10 ( V_17 , L_266 ,
F_68 ( V_447 ) ) ;
F_10 ( V_17 , L_267 ,
F_116 ( V_448 ) ) ;
F_10 ( V_17 , L_268 ,
F_116 ( V_449 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_269 ,
F_68 ( V_450 ) ) ;
F_10 ( V_17 , L_270 ,
F_68 ( V_451 ) ) ;
F_10 ( V_17 , L_271 ,
F_68 ( V_452 ) ) ;
F_10 ( V_17 , L_272 ,
F_68 ( V_453 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_10 ( V_17 , L_273 ,
F_68 ( V_454 ) ) ;
else
F_10 ( V_17 , L_274 ,
F_68 ( V_455 ) ) ;
F_10 ( V_17 , L_275 ,
F_68 ( V_456 ) ) ;
}
if ( V_66 -> V_457 & V_458 )
F_26 ( V_17 , L_276 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_194 ( int V_86 , void * V_87 , void * V_18 )
{
struct V_58 * V_59 = V_87 ;
struct V_16 * V_17 = V_18 ;
struct V_93 * V_94 = V_59 -> V_94 ;
if ( ! V_94 ) {
F_10 ( V_17 , L_277 ,
V_59 -> V_459 ) ;
return 0 ;
}
if ( F_195 ( V_59 ) )
F_26 ( V_17 , L_278 ) ;
else
F_10 ( V_17 , L_279 , V_59 -> V_459 ) ;
V_94 -> V_460 ( V_94 , V_17 ) ;
return 0 ;
}
static void F_196 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_93 * V_94 = V_66 -> V_107 . V_461 ;
int V_208 , V_145 ;
if ( ! V_94 )
return;
F_10 ( V_17 , L_280 , V_94 -> V_462 ) ;
F_10 ( V_17 , L_281 , V_94 -> V_463 ) ;
F_74 (ring, dev_priv, unused) {
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
for ( V_145 = 0 ; V_145 < 4 ; V_145 ++ ) {
T_4 V_464 = 0x270 + V_145 * 8 ;
T_8 V_465 = F_68 ( V_135 -> V_466 + V_464 + 4 ) ;
V_465 <<= 32 ;
V_465 |= F_68 ( V_135 -> V_466 + V_464 ) ;
F_10 ( V_17 , L_282 , V_145 , V_465 ) ;
}
}
}
static void F_197 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
struct V_105 * V_106 ;
int V_145 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_283 , F_68 ( V_467 ) ) ;
F_74 (ring, dev_priv, i) {
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_283 , F_68 ( F_198 ( V_135 ) ) ) ;
F_10 ( V_17 , L_284 , F_68 ( F_199 ( V_135 ) ) ) ;
F_10 ( V_17 , L_285 , F_68 ( F_200 ( V_135 ) ) ) ;
F_10 ( V_17 , L_286 , F_68 ( F_201 ( V_135 ) ) ) ;
}
if ( V_66 -> V_107 . V_461 ) {
struct V_93 * V_94 = V_66 -> V_107 . V_461 ;
F_26 ( V_17 , L_287 ) ;
F_10 ( V_17 , L_288 , V_94 -> V_468 ) ;
V_94 -> V_460 ( V_94 , V_17 ) ;
}
F_51 (file, &dev->filelist, lhead) {
struct V_469 * V_96 = V_106 -> V_115 ;
F_10 ( V_17 , L_289 ,
F_202 ( V_106 -> V_118 , V_119 ) -> V_120 ) ;
F_53 ( & V_96 -> V_470 , F_194 , V_17 ) ;
}
F_10 ( V_17 , L_290 , F_68 ( V_471 ) ) ;
}
static int F_203 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_196 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_197 ( V_17 , V_21 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_204 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
F_10 ( V_17 , L_291 , F_1 ( F_205 ( V_21 ) ) ) ;
F_10 ( V_17 , L_292 , V_66 -> V_472 ) ;
return 0 ;
}
static int F_206 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_473 = 0 ;
T_4 V_474 [ 3 ] ;
enum V_124 V_124 ;
bool V_475 = false ;
F_77 ( V_66 ) ;
F_5 ( & V_66 -> V_476 . V_311 ) ;
F_10 ( V_17 , L_293 , F_1 ( V_66 -> V_476 . V_477 ) ) ;
F_10 ( V_17 , L_294 , F_1 ( V_66 -> V_476 . V_478 ) ) ;
F_10 ( V_17 , L_295 , F_1 ( ( bool ) V_66 -> V_476 . V_475 ) ) ;
F_10 ( V_17 , L_296 , F_1 ( V_66 -> V_476 . V_97 ) ) ;
F_10 ( V_17 , L_297 ,
V_66 -> V_476 . V_479 ) ;
F_10 ( V_17 , L_298 ,
F_1 ( F_207 ( & V_66 -> V_476 . V_127 . V_127 ) ) ) ;
if ( F_208 ( V_21 ) ) {
if ( F_209 ( V_21 ) )
V_475 = F_68 ( F_210 ( V_21 ) ) & V_480 ;
else {
F_81 (dev_priv, pipe) {
V_474 [ V_124 ] = F_68 ( F_211 ( V_124 ) ) &
V_481 ;
if ( ( V_474 [ V_124 ] == V_482 ) ||
( V_474 [ V_124 ] == V_483 ) )
V_475 = true ;
}
}
}
F_10 ( V_17 , L_299 , F_1 ( V_475 ) ) ;
if ( ! F_209 ( V_21 ) )
F_81 (dev_priv, pipe) {
if ( ( V_474 [ V_124 ] == V_482 ) ||
( V_474 [ V_124 ] == V_483 ) )
F_10 ( V_17 , L_300 , F_61 ( V_124 ) ) ;
}
F_26 ( V_17 , L_28 ) ;
F_10 ( V_17 , L_301 ,
F_1 ( ( bool ) V_66 -> V_476 . V_484 ) ) ;
if ( F_208 ( V_21 ) && F_209 ( V_21 ) ) {
V_473 = F_68 ( F_212 ( V_21 ) ) &
V_485 ;
F_10 ( V_17 , L_302 , V_473 ) ;
}
F_7 ( & V_66 -> V_476 . V_311 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_213 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_486 * V_487 ;
struct V_488 * V_489 ;
struct V_490 * V_490 = NULL ;
int V_73 ;
T_11 V_491 [ 6 ] ;
F_148 ( V_21 ) ;
F_24 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_489 -> V_34 . V_492 != V_493 )
continue;
if ( ! V_489 -> V_34 . V_487 )
continue;
V_487 = F_214 ( V_489 -> V_34 . V_487 ) ;
if ( V_487 -> type != V_494 )
continue;
V_490 = F_215 ( & V_487 -> V_34 ) ;
V_73 = F_216 ( V_490 , V_491 ) ;
if ( V_73 )
goto V_204;
F_10 ( V_17 , L_303 ,
V_491 [ 0 ] , V_491 [ 1 ] , V_491 [ 2 ] ,
V_491 [ 3 ] , V_491 [ 4 ] , V_491 [ 5 ] ) ;
goto V_204;
}
V_73 = - V_362 ;
V_204:
F_149 ( V_21 ) ;
return V_73 ;
}
static int F_217 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_8 V_495 ;
T_4 V_496 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_362 ;
F_77 ( V_66 ) ;
F_218 ( V_497 , V_495 ) ;
V_495 = ( V_495 & 0x1f00 ) >> 8 ;
V_496 = 1000000 / ( 1 << V_495 ) ;
V_495 = F_68 ( V_498 ) ;
V_495 *= V_496 ;
F_78 ( V_66 ) ;
F_10 ( V_17 , L_304 , ( long long unsigned ) V_495 ) ;
return 0 ;
}
static int F_219 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_121 ( V_21 ) && ! F_119 ( V_21 ) ) {
F_26 ( V_17 , L_217 ) ;
return 0 ;
}
F_10 ( V_17 , L_305 , F_1 ( ! V_66 -> V_107 . V_499 ) ) ;
F_10 ( V_17 , L_306 ,
F_1 ( ! F_220 ( V_66 ) ) ) ;
return 0 ;
}
static const char * F_221 ( enum V_500 V_501 )
{
switch ( V_501 ) {
case V_502 :
return L_307 ;
case V_503 :
return L_308 ;
case V_504 :
return L_309 ;
case V_505 :
return L_310 ;
case V_506 :
return L_311 ;
case V_507 :
return L_312 ;
case V_508 :
return L_313 ;
case V_509 :
return L_314 ;
case V_510 :
return L_315 ;
case V_511 :
return L_316 ;
case V_512 :
return L_317 ;
case V_513 :
return L_318 ;
case V_514 :
return L_319 ;
case V_515 :
return L_320 ;
case V_516 :
return L_321 ;
case V_517 :
return L_322 ;
case V_518 :
return L_323 ;
case V_519 :
return L_324 ;
case V_520 :
return L_325 ;
case V_521 :
return L_326 ;
case V_522 :
return L_327 ;
case V_523 :
return L_328 ;
case V_524 :
return L_329 ;
case V_525 :
return L_330 ;
case V_526 :
return L_331 ;
case V_527 :
return L_332 ;
case V_528 :
return L_333 ;
case V_529 :
return L_334 ;
case V_530 :
return L_335 ;
default:
F_222 ( V_501 ) ;
return L_336 ;
}
}
static int F_223 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_531 * V_532 = & V_66 -> V_532 ;
int V_145 ;
F_5 ( & V_532 -> V_311 ) ;
F_10 ( V_17 , L_337 , L_338 , L_339 ) ;
for ( V_145 = 0 ; V_145 < V_532 -> V_533 ; V_145 ++ ) {
struct V_534 * V_535 ;
enum V_500 V_536 ;
V_535 = & V_532 -> V_537 [ V_145 ] ;
F_10 ( V_17 , L_340 , V_535 -> V_45 ,
V_535 -> V_72 ) ;
for ( V_536 = 0 ; V_536 < V_538 ;
V_536 ++ ) {
if ( ! ( F_224 ( V_536 ) & V_535 -> V_539 ) )
continue;
F_10 ( V_17 , L_341 ,
F_221 ( V_536 ) ,
V_532 -> V_540 [ V_536 ] ) ;
}
}
F_7 ( & V_532 -> V_311 ) ;
return 0 ;
}
static void F_225 ( struct V_16 * V_17 , int V_541 ,
struct V_542 * V_543 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < V_541 ; V_145 ++ )
F_29 ( V_17 , '\t' ) ;
F_10 ( V_17 , L_342 ,
V_543 -> V_34 . V_86 , V_543 -> V_45 ,
V_543 -> V_544 , V_543 -> clock ,
V_543 -> V_545 , V_543 -> V_546 ,
V_543 -> V_547 , V_543 -> V_548 ,
V_543 -> V_549 , V_543 -> V_550 ,
V_543 -> V_551 , V_543 -> V_552 ,
V_543 -> type , V_543 -> V_430 ) ;
}
static void F_226 ( struct V_16 * V_17 ,
struct V_122 * V_122 ,
struct V_486 * V_486 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_553 * V_123 = & V_122 -> V_34 ;
struct V_488 * V_488 ;
struct V_554 * V_487 ;
V_487 = & V_486 -> V_34 ;
F_10 ( V_17 , L_343 ,
V_487 -> V_34 . V_86 , V_487 -> V_45 ) ;
F_227 (dev, encoder, intel_connector) {
struct V_555 * V_489 = & V_488 -> V_34 ;
F_10 ( V_17 , L_344 ,
V_489 -> V_34 . V_86 ,
V_489 -> V_45 ,
F_228 ( V_489 -> V_425 ) ) ;
if ( V_489 -> V_425 == V_556 ) {
struct V_542 * V_543 = & V_123 -> V_543 ;
F_10 ( V_17 , L_345 ) ;
F_225 ( V_17 , 2 , V_543 ) ;
} else {
F_29 ( V_17 , '\n' ) ;
}
}
}
static void F_229 ( struct V_16 * V_17 , struct V_122 * V_122 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_553 * V_123 = & V_122 -> V_34 ;
struct V_486 * V_486 ;
if ( V_123 -> V_557 -> V_394 )
F_10 ( V_17 , L_346 ,
V_123 -> V_557 -> V_394 -> V_34 . V_86 , V_123 -> T_1 , V_123 -> V_558 ,
V_123 -> V_557 -> V_394 -> V_397 , V_123 -> V_557 -> V_394 -> V_398 ) ;
else
F_26 ( V_17 , L_347 ) ;
F_230 (dev, crtc, intel_encoder)
F_226 ( V_17 , V_122 , V_486 ) ;
}
static void F_231 ( struct V_16 * V_17 , struct V_559 * V_560 )
{
struct V_542 * V_543 = V_560 -> V_561 ;
F_10 ( V_17 , L_348 ) ;
F_225 ( V_17 , 2 , V_543 ) ;
}
static void F_232 ( struct V_16 * V_17 ,
struct V_488 * V_488 )
{
struct V_486 * V_486 = V_488 -> V_487 ;
struct V_490 * V_490 = F_215 ( & V_486 -> V_34 ) ;
F_10 ( V_17 , L_349 , V_490 -> V_562 [ V_563 ] ) ;
F_10 ( V_17 , L_350 , V_490 -> V_564 ? L_1 :
L_2 ) ;
if ( V_486 -> type == V_494 )
F_231 ( V_17 , & V_488 -> V_560 ) ;
}
static void F_233 ( struct V_16 * V_17 ,
struct V_488 * V_488 )
{
struct V_486 * V_486 = V_488 -> V_487 ;
struct V_565 * V_565 = F_234 ( & V_486 -> V_34 ) ;
F_10 ( V_17 , L_350 , V_565 -> V_564 ? L_1 :
L_2 ) ;
}
static void F_235 ( struct V_16 * V_17 ,
struct V_488 * V_488 )
{
F_231 ( V_17 , & V_488 -> V_560 ) ;
}
static void F_236 ( struct V_16 * V_17 ,
struct V_555 * V_489 )
{
struct V_488 * V_488 = F_237 ( V_489 ) ;
struct V_486 * V_486 = V_488 -> V_487 ;
struct V_542 * V_543 ;
F_10 ( V_17 , L_351 ,
V_489 -> V_34 . V_86 , V_489 -> V_45 ,
F_228 ( V_489 -> V_425 ) ) ;
if ( V_489 -> V_425 == V_556 ) {
F_10 ( V_17 , L_352 , V_489 -> V_566 . V_45 ) ;
F_10 ( V_17 , L_353 ,
V_489 -> V_566 . V_567 ,
V_489 -> V_566 . V_568 ) ;
F_10 ( V_17 , L_354 ,
F_238 ( V_489 -> V_566 . V_569 ) ) ;
F_10 ( V_17 , L_355 ,
V_489 -> V_566 . V_570 ) ;
}
if ( V_486 ) {
if ( V_486 -> type == V_571 ||
V_486 -> type == V_494 )
F_232 ( V_17 , V_488 ) ;
else if ( V_486 -> type == V_572 )
F_233 ( V_17 , V_488 ) ;
else if ( V_486 -> type == V_573 )
F_235 ( V_17 , V_488 ) ;
}
F_10 ( V_17 , L_356 ) ;
F_24 (mode, &connector->modes, head)
F_225 ( V_17 , 2 , V_543 ) ;
}
static bool F_239 ( struct V_20 * V_21 , int V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_417 ;
if ( F_240 ( V_21 ) || F_241 ( V_21 ) )
V_417 = F_68 ( V_574 ) & V_575 ;
else
V_417 = F_68 ( F_242 ( V_124 ) ) & V_576 ;
return V_417 ;
}
static bool F_243 ( struct V_20 * V_21 , int V_124 , int * T_1 , int * V_558 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_199 ;
V_199 = F_68 ( F_244 ( V_124 ) ) ;
* T_1 = ( V_199 >> V_577 ) & V_578 ;
if ( V_199 & ( V_579 << V_577 ) )
* T_1 = - * T_1 ;
* V_558 = ( V_199 >> V_580 ) & V_578 ;
if ( V_199 & ( V_579 << V_580 ) )
* V_558 = - * V_558 ;
return F_239 ( V_21 , V_124 ) ;
}
static int F_245 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 ;
struct V_555 * V_489 ;
F_77 ( V_66 ) ;
F_148 ( V_21 ) ;
F_10 ( V_17 , L_357 ) ;
F_10 ( V_17 , L_358 ) ;
F_60 (dev, crtc) {
bool V_97 ;
int T_1 , V_558 ;
F_10 ( V_17 , L_359 ,
V_123 -> V_34 . V_34 . V_86 , F_61 ( V_123 -> V_124 ) ,
F_1 ( V_123 -> V_97 ) , V_123 -> V_581 -> V_582 ,
V_123 -> V_581 -> V_583 ) ;
if ( V_123 -> V_97 ) {
F_229 ( V_17 , V_123 ) ;
V_97 = F_243 ( V_21 , V_123 -> V_124 , & T_1 , & V_558 ) ;
F_10 ( V_17 , L_360 ,
F_1 ( V_123 -> V_584 ) ,
T_1 , V_558 , V_123 -> V_585 , V_123 -> V_586 ,
V_123 -> V_587 , F_1 ( V_97 ) ) ;
}
F_10 ( V_17 , L_361 ,
F_1 ( ! V_123 -> V_588 ) ,
F_1 ( ! V_123 -> V_589 ) ) ;
}
F_10 ( V_17 , L_28 ) ;
F_10 ( V_17 , L_362 ) ;
F_10 ( V_17 , L_363 ) ;
F_24 (connector, &dev->mode_config.connector_list, head) {
F_236 ( V_17 , V_489 ) ;
}
F_149 ( V_21 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_246 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_134 * V_135 ;
int V_590 = F_247 ( F_9 ( V_21 ) -> V_591 ) ;
int V_145 , V_420 , V_73 ;
if ( ! F_248 ( V_21 ) ) {
F_26 ( V_17 , L_364 ) ;
return 0 ;
}
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
if ( F_119 ( V_21 ) ) {
struct V_418 * V_418 ;
T_12 * V_147 ;
V_418 = F_177 ( V_66 -> V_592 , 0 ) ;
V_147 = ( T_12 * ) F_179 ( V_418 ) ;
F_74 (ring, dev_priv, i) {
T_12 V_464 ;
F_10 ( V_17 , L_246 , V_135 -> V_45 ) ;
F_26 ( V_17 , L_365 ) ;
for ( V_420 = 0 ; V_420 < V_590 ; V_420 ++ ) {
V_464 = V_145 * V_272 + V_420 ;
F_10 ( V_17 , L_366 ,
V_147 [ V_464 ] , V_464 * 8 ) ;
}
F_29 ( V_17 , '\n' ) ;
F_26 ( V_17 , L_367 ) ;
for ( V_420 = 0 ; V_420 < V_590 ; V_420 ++ ) {
V_464 = V_145 + ( V_420 * V_272 ) ;
F_10 ( V_17 , L_366 ,
V_147 [ V_464 ] , V_464 * 8 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_180 ( V_147 ) ;
} else {
F_26 ( V_17 , L_365 ) ;
F_74 (ring, dev_priv, i)
for ( V_420 = 0 ; V_420 < V_590 ; V_420 ++ )
F_10 ( V_17 , L_368 ,
F_68 ( V_135 -> V_593 . V_594 . signal [ V_420 ] ) ) ;
F_29 ( V_17 , '\n' ) ;
}
F_26 ( V_17 , L_369 ) ;
F_74 (ring, dev_priv, i) {
for ( V_420 = 0 ; V_420 < V_590 ; V_420 ++ ) {
F_10 ( V_17 , L_370 , V_135 -> V_593 . V_595 [ V_420 ] ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_29 ( V_17 , '\n' ) ;
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_249 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_145 ;
F_148 ( V_21 ) ;
for ( V_145 = 0 ; V_145 < V_66 -> V_596 ; V_145 ++ ) {
struct V_597 * V_598 = & V_66 -> V_599 [ V_145 ] ;
F_10 ( V_17 , L_371 , V_145 , V_598 -> V_45 , V_598 -> V_86 ) ;
F_10 ( V_17 , L_372 ,
V_598 -> V_581 . V_600 , V_598 -> V_97 , F_1 ( V_598 -> V_601 ) ) ;
F_10 ( V_17 , L_373 ) ;
F_10 ( V_17 , L_374 , V_598 -> V_581 . V_602 . V_603 ) ;
F_10 ( V_17 , L_375 ,
V_598 -> V_581 . V_602 . V_604 ) ;
F_10 ( V_17 , L_376 , V_598 -> V_581 . V_602 . V_605 ) ;
F_10 ( V_17 , L_377 , V_598 -> V_581 . V_602 . V_606 ) ;
F_10 ( V_17 , L_378 , V_598 -> V_581 . V_602 . V_607 ) ;
}
F_149 ( V_21 ) ;
return 0 ;
}
static int F_250 ( struct V_16 * V_17 , void * V_208 )
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
F_10 ( V_17 , L_379 , V_66 -> V_608 . V_72 ) ;
for ( V_145 = 0 ; V_145 < V_66 -> V_608 . V_72 ; ++ V_145 ) {
T_4 V_130 , V_609 , V_610 , V_611 ;
bool V_612 ;
V_130 = V_66 -> V_608 . V_364 [ V_145 ] . V_130 ;
V_609 = V_66 -> V_608 . V_364 [ V_145 ] . V_609 ;
V_610 = V_66 -> V_608 . V_364 [ V_145 ] . V_610 ;
V_611 = F_68 ( V_130 ) ;
V_612 = ( V_610 & V_609 ) == ( V_611 & V_609 ) ;
F_10 ( V_17 , L_380 ,
V_130 , V_610 , V_609 , V_611 , V_612 ? L_381 : L_382 ) ;
}
F_78 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_251 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_613 * V_614 ;
struct V_615 * V_616 ;
enum V_124 V_124 ;
int V_125 ;
if ( F_9 ( V_21 ) -> V_24 < 9 )
return 0 ;
F_148 ( V_21 ) ;
V_614 = & V_66 -> V_617 . V_618 . V_614 ;
F_10 ( V_17 , L_383 , L_12 , L_384 , L_385 , L_386 ) ;
F_81 (dev_priv, pipe) {
F_10 ( V_17 , L_387 , F_61 ( V_124 ) ) ;
F_252 (pipe, plane) {
V_616 = & V_614 -> V_125 [ V_124 ] [ V_125 ] ;
F_10 ( V_17 , L_388 , V_125 + 1 ,
V_616 -> V_50 , V_616 -> V_619 ,
F_253 ( V_616 ) ) ;
}
V_616 = & V_614 -> V_427 [ V_124 ] ;
F_10 ( V_17 , L_389 , L_390 , V_616 -> V_50 ,
V_616 -> V_619 , F_253 ( V_616 ) ) ;
}
F_149 ( V_21 ) ;
return 0 ;
}
static int F_254 ( struct V_16 * V_17 , void * V_208 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_554 * V_487 ;
struct V_486 * V_486 ;
struct V_620 * V_621 ;
F_148 ( V_21 ) ;
F_24 (encoder, &dev->mode_config.encoder_list, head) {
V_486 = F_214 ( V_487 ) ;
if ( V_486 -> type != V_571 )
continue;
V_621 = F_255 ( V_487 ) ;
if ( ! V_621 -> V_622 . V_623 )
continue;
F_256 ( V_17 , & V_621 -> V_622 . V_624 ) ;
}
F_149 ( V_21 ) ;
return 0 ;
}
static int F_257 ( struct V_196 * V_196 , struct V_106 * V_625 )
{
struct V_626 * V_23 = V_196 -> V_197 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_627 * V_628 = & V_66 -> V_628 [ V_23 -> V_124 ] ;
if ( V_23 -> V_124 >= F_9 ( V_23 -> V_21 ) -> V_629 )
return - V_362 ;
F_63 ( & V_628 -> V_311 ) ;
if ( V_628 -> V_630 ) {
F_71 ( & V_628 -> V_311 ) ;
return - V_631 ;
}
V_628 -> V_630 = true ;
V_625 -> V_195 = V_196 -> V_197 ;
F_71 ( & V_628 -> V_311 ) ;
return 0 ;
}
static int F_258 ( struct V_196 * V_196 , struct V_106 * V_625 )
{
struct V_626 * V_23 = V_196 -> V_197 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_627 * V_628 = & V_66 -> V_628 [ V_23 -> V_124 ] ;
F_63 ( & V_628 -> V_311 ) ;
V_628 -> V_630 = false ;
F_71 ( & V_628 -> V_311 ) ;
return 0 ;
}
static int F_259 ( struct V_627 * V_628 )
{
F_260 ( & V_628 -> V_311 ) ;
return F_261 ( V_628 -> V_64 , V_628 -> V_407 ,
V_632 ) ;
}
static T_5
F_262 ( struct V_106 * V_625 , char T_6 * V_633 , T_3 V_72 ,
T_7 * V_199 )
{
struct V_626 * V_23 = V_625 -> V_195 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_627 * V_628 = & V_66 -> V_628 [ V_23 -> V_124 ] ;
char V_205 [ V_634 ] ;
int V_635 ;
T_5 V_636 ;
if ( V_72 < V_637 )
return - V_79 ;
if ( V_628 -> V_638 == V_639 )
return 0 ;
F_63 ( & V_628 -> V_311 ) ;
while ( F_259 ( V_628 ) == 0 ) {
int V_73 ;
if ( V_625 -> V_640 & V_641 ) {
F_71 ( & V_628 -> V_311 ) ;
return - V_642 ;
}
V_73 = F_263 ( V_628 -> V_643 ,
F_259 ( V_628 ) , V_628 -> V_311 ) ;
if ( V_73 ) {
F_71 ( & V_628 -> V_311 ) ;
return V_73 ;
}
}
V_635 = V_72 / V_637 ;
V_636 = 0 ;
while ( V_635 > 0 ) {
struct V_644 * V_616 =
& V_628 -> V_645 [ V_628 -> V_407 ] ;
int V_73 ;
if ( F_261 ( V_628 -> V_64 , V_628 -> V_407 ,
V_632 ) < 1 )
break;
F_264 ( V_632 ) ;
V_628 -> V_407 = ( V_628 -> V_407 + 1 ) & ( V_632 - 1 ) ;
V_636 += snprintf ( V_205 , V_634 ,
L_391 ,
V_616 -> V_646 , V_616 -> V_491 [ 0 ] ,
V_616 -> V_491 [ 1 ] , V_616 -> V_491 [ 2 ] ,
V_616 -> V_491 [ 3 ] , V_616 -> V_491 [ 4 ] ) ;
F_71 ( & V_628 -> V_311 ) ;
V_73 = F_265 ( V_633 , V_205 , V_637 ) ;
if ( V_73 == V_637 )
return - V_647 ;
V_633 += V_637 ;
V_635 -- ;
F_63 ( & V_628 -> V_311 ) ;
}
F_71 ( & V_628 -> V_311 ) ;
return V_636 ;
}
static int F_266 ( struct V_4 * V_648 , struct V_2 * V_3 ,
enum V_124 V_124 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_626 * V_23 = & V_649 [ V_124 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_267 ( V_23 -> V_45 , V_650 , V_648 , V_23 ,
& V_651 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_268 ( enum V_652 V_638 )
{
F_269 ( F_270 ( V_653 ) != V_654 ) ;
return V_653 [ V_638 ] ;
}
static int F_271 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_145 ;
for ( V_145 = 0 ; V_145 < V_655 ; V_145 ++ )
F_10 ( V_17 , L_392 , F_61 ( V_145 ) ,
F_268 ( V_66 -> V_628 [ V_145 ] . V_638 ) ) ;
return 0 ;
}
static int F_272 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
return F_273 ( V_106 , F_271 , V_21 ) ;
}
static int F_274 ( enum V_652 * V_638 ,
T_10 * V_207 )
{
if ( * V_638 == V_656 )
* V_638 = V_657 ;
switch ( * V_638 ) {
case V_657 :
* V_207 = V_658 | V_659 ;
break;
case V_639 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_275 ( struct V_20 * V_21 , enum V_124 V_124 ,
enum V_652 * V_638 )
{
struct V_486 * V_487 ;
struct V_122 * V_123 ;
struct V_620 * V_660 ;
int V_73 = 0 ;
* V_638 = V_657 ;
F_148 ( V_21 ) ;
F_276 (dev, encoder) {
if ( ! V_487 -> V_34 . V_123 )
continue;
V_123 = F_277 ( V_487 -> V_34 . V_123 ) ;
if ( V_123 -> V_124 != V_124 )
continue;
switch ( V_487 -> type ) {
case V_661 :
* V_638 = V_662 ;
break;
case V_571 :
case V_494 :
V_660 = F_255 ( & V_487 -> V_34 ) ;
switch ( V_660 -> V_663 ) {
case V_664 :
* V_638 = V_665 ;
break;
case V_666 :
* V_638 = V_667 ;
break;
case V_668 :
* V_638 = V_669 ;
break;
default:
F_278 ( 1 , L_393 ,
F_279 ( V_660 -> V_663 ) ) ;
break;
}
break;
default:
break;
}
}
F_149 ( V_21 ) ;
return V_73 ;
}
static int F_280 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_652 * V_638 ,
T_10 * V_207 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_670 = false ;
if ( * V_638 == V_656 ) {
int V_73 = F_275 ( V_21 , V_124 , V_638 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_638 ) {
case V_657 :
* V_207 = V_658 | V_671 ;
break;
case V_665 :
* V_207 = V_658 | V_672 ;
V_670 = true ;
break;
case V_667 :
* V_207 = V_658 | V_673 ;
V_670 = true ;
break;
case V_669 :
if ( ! F_80 ( V_21 ) )
return - V_79 ;
* V_207 = V_658 | V_674 ;
V_670 = true ;
break;
case V_639 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_670 ) {
T_10 V_675 = F_68 ( V_676 ) ;
V_675 |= V_677 ;
switch ( V_124 ) {
case V_678 :
V_675 |= V_679 ;
break;
case V_680 :
V_675 |= V_681 ;
break;
case V_682 :
V_675 |= V_683 ;
break;
default:
return - V_79 ;
}
F_151 ( V_676 , V_675 ) ;
}
return 0 ;
}
static int F_281 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_652 * V_638 ,
T_10 * V_207 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_670 = false ;
if ( * V_638 == V_656 ) {
int V_73 = F_275 ( V_21 , V_124 , V_638 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_638 ) {
case V_657 :
* V_207 = V_658 | V_684 ;
break;
case V_662 :
if ( ! F_282 ( V_21 ) )
return - V_79 ;
* V_207 = V_658 | V_685 ;
break;
case V_665 :
if ( ! F_283 ( V_21 ) )
return - V_79 ;
* V_207 = V_658 | V_686 ;
V_670 = true ;
break;
case V_667 :
if ( ! F_283 ( V_21 ) )
return - V_79 ;
* V_207 = V_658 | V_687 ;
V_670 = true ;
break;
case V_669 :
if ( ! F_283 ( V_21 ) )
return - V_79 ;
* V_207 = V_658 | V_688 ;
V_670 = true ;
break;
case V_639 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_670 ) {
T_10 V_675 = F_68 ( V_676 ) ;
F_178 ( ! F_283 ( V_21 ) ) ;
F_151 ( V_689 ,
F_68 ( V_689 ) | V_690 ) ;
if ( V_124 == V_678 )
V_675 |= V_679 ;
else
V_675 |= V_681 ;
F_151 ( V_676 , V_675 ) ;
}
return 0 ;
}
static void F_284 ( struct V_20 * V_21 ,
enum V_124 V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_10 V_675 = F_68 ( V_676 ) ;
switch ( V_124 ) {
case V_678 :
V_675 &= ~ V_679 ;
break;
case V_680 :
V_675 &= ~ V_681 ;
break;
case V_682 :
V_675 &= ~ V_683 ;
break;
default:
return;
}
if ( ! ( V_675 & V_691 ) )
V_675 &= ~ V_677 ;
F_151 ( V_676 , V_675 ) ;
}
static void F_285 ( struct V_20 * V_21 ,
enum V_124 V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_10 V_675 = F_68 ( V_676 ) ;
if ( V_124 == V_678 )
V_675 &= ~ V_679 ;
else
V_675 &= ~ V_681 ;
F_151 ( V_676 , V_675 ) ;
if ( ! ( V_675 & V_691 ) ) {
F_151 ( V_689 ,
F_68 ( V_689 ) & ~ V_690 ) ;
}
}
static int F_286 ( enum V_652 * V_638 ,
T_10 * V_207 )
{
if ( * V_638 == V_656 )
* V_638 = V_657 ;
switch ( * V_638 ) {
case V_692 :
* V_207 = V_658 | V_693 ;
break;
case V_694 :
* V_207 = V_658 | V_695 ;
break;
case V_657 :
* V_207 = V_658 | V_696 ;
break;
case V_639 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static void F_287 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 =
F_277 ( V_66 -> V_697 [ V_678 ] ) ;
F_148 ( V_21 ) ;
if ( V_123 -> V_581 -> V_698 == V_699 &&
! V_123 -> V_581 -> V_700 . V_475 ) {
V_123 -> V_581 -> V_700 . V_701 = true ;
F_288 ( V_66 ,
F_289 ( V_678 ) ) ;
V_66 -> V_702 . V_703 ( & V_123 -> V_34 ) ;
V_66 -> V_702 . V_704 ( & V_123 -> V_34 ) ;
}
F_149 ( V_21 ) ;
}
static void F_290 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 =
F_277 ( V_66 -> V_697 [ V_678 ] ) ;
F_148 ( V_21 ) ;
if ( V_123 -> V_581 -> V_700 . V_701 ) {
V_123 -> V_581 -> V_700 . V_701 = false ;
V_66 -> V_702 . V_703 ( & V_123 -> V_34 ) ;
V_66 -> V_702 . V_704 ( & V_123 -> V_34 ) ;
F_291 ( V_66 ,
F_289 ( V_678 ) ) ;
}
F_149 ( V_21 ) ;
}
static int F_292 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_652 * V_638 ,
T_10 * V_207 )
{
if ( * V_638 == V_656 )
* V_638 = V_705 ;
switch ( * V_638 ) {
case V_692 :
* V_207 = V_658 | V_706 ;
break;
case V_694 :
* V_207 = V_658 | V_707 ;
break;
case V_705 :
if ( F_121 ( V_21 ) && V_124 == V_678 )
F_287 ( V_21 ) ;
* V_207 = V_658 | V_708 ;
break;
case V_639 :
* V_207 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_293 ( struct V_20 * V_21 , enum V_124 V_124 ,
enum V_652 V_638 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_627 * V_628 = & V_66 -> V_628 [ V_124 ] ;
struct V_122 * V_123 = F_277 ( F_294 ( V_21 ,
V_124 ) ) ;
T_4 V_207 = 0 ;
int V_73 ;
if ( V_628 -> V_638 == V_638 )
return 0 ;
if ( V_628 -> V_638 && V_638 )
return - V_79 ;
if ( ! F_86 ( V_66 , F_87 ( V_124 ) ) ) {
F_295 ( L_394 ) ;
return - V_709 ;
}
if ( F_296 ( V_21 ) )
V_73 = F_274 ( & V_638 , & V_207 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_73 = F_281 ( V_21 , V_124 , & V_638 , & V_207 ) ;
else if ( F_91 ( V_21 ) )
V_73 = F_280 ( V_21 , V_124 , & V_638 , & V_207 ) ;
else if ( F_115 ( V_21 ) || F_117 ( V_21 ) )
V_73 = F_286 ( & V_638 , & V_207 ) ;
else
V_73 = F_292 ( V_21 , V_124 , & V_638 , & V_207 ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_638 ) {
struct V_644 * V_645 ;
F_97 ( L_395 ,
F_61 ( V_124 ) , F_268 ( V_638 ) ) ;
V_645 = F_297 ( V_632 ,
sizeof( V_628 -> V_645 [ 0 ] ) ,
V_9 ) ;
if ( ! V_645 )
return - V_10 ;
F_298 ( V_123 ) ;
F_63 ( & V_628 -> V_311 ) ;
F_104 ( V_628 -> V_645 ) ;
V_628 -> V_645 = V_645 ;
V_628 -> V_64 = 0 ;
V_628 -> V_407 = 0 ;
F_71 ( & V_628 -> V_311 ) ;
}
V_628 -> V_638 = V_638 ;
F_151 ( F_299 ( V_124 ) , V_207 ) ;
F_300 ( F_299 ( V_124 ) ) ;
if ( V_638 == V_639 ) {
struct V_644 * V_645 ;
struct V_122 * V_123 =
F_277 ( V_66 -> V_697 [ V_124 ] ) ;
F_97 ( L_396 ,
F_61 ( V_124 ) ) ;
F_301 ( & V_123 -> V_34 . V_710 , NULL ) ;
if ( V_123 -> V_97 )
F_302 ( V_21 , V_124 ) ;
F_303 ( & V_123 -> V_34 . V_710 ) ;
F_63 ( & V_628 -> V_311 ) ;
V_645 = V_628 -> V_645 ;
V_628 -> V_645 = NULL ;
V_628 -> V_64 = 0 ;
V_628 -> V_407 = 0 ;
F_71 ( & V_628 -> V_311 ) ;
F_104 ( V_645 ) ;
if ( F_283 ( V_21 ) )
F_285 ( V_21 , V_124 ) ;
else if ( F_91 ( V_21 ) )
F_284 ( V_21 , V_124 ) ;
else if ( F_121 ( V_21 ) && V_124 == V_678 )
F_290 ( V_21 ) ;
F_304 ( V_123 ) ;
}
return 0 ;
}
static int F_305 ( char * V_205 , char * V_711 [] , int V_712 )
{
int V_713 = 0 ;
while ( * V_205 ) {
char * V_619 ;
V_205 = F_306 ( V_205 ) ;
if ( ! * V_205 )
break;
for ( V_619 = V_205 ; * V_619 && ! isspace ( * V_619 ) ; V_619 ++ )
;
if ( V_713 == V_712 ) {
F_97 ( L_397 ,
V_712 ) ;
return - V_79 ;
}
if ( * V_619 )
* V_619 ++ = '\0' ;
V_711 [ V_713 ++ ] = V_205 ;
V_205 = V_619 ;
}
return V_713 ;
}
static int
F_307 ( const char * V_205 , enum V_714 * V_715 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < F_270 ( V_716 ) ; V_145 ++ )
if ( ! strcmp ( V_205 , V_716 [ V_145 ] ) ) {
* V_715 = V_145 ;
return 0 ;
}
return - V_79 ;
}
static int F_308 ( const char * V_205 , enum V_124 * V_124 )
{
const char V_45 = V_205 [ 0 ] ;
if ( V_45 < 'A' || V_45 >= F_61 ( V_655 ) )
return - V_79 ;
* V_124 = V_45 - 'A' ;
return 0 ;
}
static int
F_309 ( const char * V_205 , enum V_652 * V_55 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < F_270 ( V_653 ) ; V_145 ++ )
if ( ! strcmp ( V_205 , V_653 [ V_145 ] ) ) {
* V_55 = V_145 ;
return 0 ;
}
return - V_79 ;
}
static int F_310 ( struct V_20 * V_21 , char * V_205 , T_3 V_717 )
{
#define F_311 3
int V_713 ;
char * V_711 [ F_311 ] ;
enum V_124 V_124 ;
enum V_714 V_718 ;
enum V_652 V_638 ;
V_713 = F_305 ( V_205 , V_711 , F_311 ) ;
if ( V_713 != F_311 ) {
F_97 ( L_398 ,
F_311 ) ;
return - V_79 ;
}
if ( F_307 ( V_711 [ 0 ] , & V_718 ) < 0 ) {
F_97 ( L_399 , V_711 [ 0 ] ) ;
return - V_79 ;
}
if ( F_308 ( V_711 [ 1 ] , & V_124 ) < 0 ) {
F_97 ( L_400 , V_711 [ 1 ] ) ;
return - V_79 ;
}
if ( F_309 ( V_711 [ 2 ] , & V_638 ) < 0 ) {
F_97 ( L_401 , V_711 [ 2 ] ) ;
return - V_79 ;
}
return F_293 ( V_21 , V_124 , V_638 ) ;
}
static T_5 F_312 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_717 , T_7 * V_719 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_720 ;
int V_73 ;
if ( V_717 == 0 )
return 0 ;
if ( V_717 > V_721 - 1 ) {
F_97 ( L_402 ,
V_721 ) ;
return - V_722 ;
}
V_720 = F_3 ( V_717 + 1 , V_9 ) ;
if ( ! V_720 )
return - V_10 ;
if ( F_313 ( V_720 , V_190 , V_717 ) ) {
V_73 = - V_647 ;
goto V_204;
}
V_720 [ V_717 ] = '\0' ;
V_73 = F_310 ( V_21 , V_720 , V_717 ) ;
V_204:
F_104 ( V_720 ) ;
if ( V_73 < 0 )
return V_73 ;
* V_719 += V_717 ;
return V_717 ;
}
static void F_314 ( struct V_16 * V_17 , const T_13 V_617 [ 8 ] )
{
struct V_20 * V_21 = V_17 -> V_19 ;
int V_723 = F_315 ( V_21 ) + 1 ;
int V_724 ;
F_148 ( V_21 ) ;
for ( V_724 = 0 ; V_724 < V_723 ; V_724 ++ ) {
unsigned int V_725 = V_617 [ V_724 ] ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_725 *= 10 ;
else if ( V_724 > 0 )
V_725 *= 5 ;
F_10 ( V_17 , L_403 ,
V_724 , V_617 [ V_724 ] , V_725 / 10 , V_725 % 10 ) ;
}
F_149 ( V_21 ) ;
}
static int F_316 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
const T_13 * V_726 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_726 = V_66 -> V_617 . V_727 ;
else
V_726 = F_23 ( V_21 ) -> V_617 . V_728 ;
F_314 ( V_17 , V_726 ) ;
return 0 ;
}
static int F_317 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
const T_13 * V_726 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_726 = V_66 -> V_617 . V_727 ;
else
V_726 = F_23 ( V_21 ) -> V_617 . V_729 ;
F_314 ( V_17 , V_726 ) ;
return 0 ;
}
static int F_318 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
const T_13 * V_726 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_726 = V_66 -> V_617 . V_727 ;
else
V_726 = F_23 ( V_21 ) -> V_617 . V_730 ;
F_314 ( V_17 , V_726 ) ;
return 0 ;
}
static int F_319 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
if ( F_320 ( V_21 ) )
return - V_362 ;
return F_273 ( V_106 , F_316 , V_21 ) ;
}
static int F_321 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
if ( F_320 ( V_21 ) )
return - V_362 ;
return F_273 ( V_106 , F_317 , V_21 ) ;
}
static int F_322 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
if ( F_320 ( V_21 ) )
return - V_362 ;
return F_273 ( V_106 , F_318 , V_21 ) ;
}
static T_5 F_323 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_717 , T_7 * V_719 , T_13 V_617 [ 8 ] )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
T_13 V_731 [ 8 ] = { 0 } ;
int V_723 = F_315 ( V_21 ) + 1 ;
int V_724 ;
int V_73 ;
char V_675 [ 32 ] ;
if ( V_717 >= sizeof( V_675 ) )
return - V_79 ;
if ( F_313 ( V_675 , V_190 , V_717 ) )
return - V_647 ;
V_675 [ V_717 ] = '\0' ;
V_73 = sscanf ( V_675 , L_404 ,
& V_731 [ 0 ] , & V_731 [ 1 ] , & V_731 [ 2 ] , & V_731 [ 3 ] ,
& V_731 [ 4 ] , & V_731 [ 5 ] , & V_731 [ 6 ] , & V_731 [ 7 ] ) ;
if ( V_73 != V_723 )
return - V_79 ;
F_148 ( V_21 ) ;
for ( V_724 = 0 ; V_724 < V_723 ; V_724 ++ )
V_617 [ V_724 ] = V_731 [ V_724 ] ;
F_149 ( V_21 ) ;
return V_717 ;
}
static T_5 F_324 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_717 , T_7 * V_719 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_13 * V_726 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_726 = V_66 -> V_617 . V_727 ;
else
V_726 = F_23 ( V_21 ) -> V_617 . V_728 ;
return F_323 ( V_106 , V_190 , V_717 , V_719 , V_726 ) ;
}
static T_5 F_325 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_717 , T_7 * V_719 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_13 * V_726 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_726 = V_66 -> V_617 . V_727 ;
else
V_726 = F_23 ( V_21 ) -> V_617 . V_729 ;
return F_323 ( V_106 , V_190 , V_717 , V_719 , V_726 ) ;
}
static T_5 F_326 ( struct V_106 * V_106 , const char T_6 * V_190 ,
T_3 V_717 , T_7 * V_719 )
{
struct V_16 * V_17 = V_106 -> V_195 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_13 * V_726 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_726 = V_66 -> V_617 . V_727 ;
else
V_726 = F_23 ( V_21 ) -> V_617 . V_730 ;
return F_323 ( V_106 , V_190 , V_717 , V_719 , V_726 ) ;
}
static int
F_327 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = F_64 ( & V_66 -> V_275 . V_732 ) ;
return 0 ;
}
static int
F_328 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_329 ( & V_66 -> V_275 ) )
return - V_642 ;
F_77 ( V_66 ) ;
F_330 ( V_21 , V_207 ,
L_405 , V_207 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int
F_331 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = V_66 -> V_275 . V_733 ;
return 0 ;
}
static int
F_332 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_97 ( L_406 , V_207 ) ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_275 . V_733 = V_207 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_333 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = V_66 -> V_275 . V_734 ;
return 0 ;
}
static int
F_334 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_275 . V_734 = V_207 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_335 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_207 = V_66 -> V_275 . V_735 ;
return 0 ;
}
static int
F_336 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_97 ( L_407 , V_207 ) ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_275 . V_735 = V_207 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_337 ( void * V_18 , T_8 * V_207 )
{
* V_207 = V_736 ;
return 0 ;
}
static int
F_338 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_339 ( L_408 , V_207 ) ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( V_207 & V_737 ) {
V_73 = F_340 ( V_21 ) ;
if ( V_73 )
goto V_738;
}
if ( V_207 & ( V_739 | V_737 ) )
F_341 ( V_21 ) ;
if ( V_207 & V_740 )
F_342 ( V_66 , V_741 , V_742 ) ;
if ( V_207 & V_743 )
F_342 ( V_66 , V_741 , V_744 ) ;
V_738:
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int
F_343 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_362 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_266 ) ;
if ( V_73 )
return V_73 ;
* V_207 = F_122 ( V_66 , V_66 -> V_209 . V_385 ) ;
F_7 ( & V_66 -> V_209 . V_266 ) ;
return 0 ;
}
static int
F_344 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_223 , V_745 , V_746 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_362 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
F_97 ( L_409 , V_207 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_266 ) ;
if ( V_73 )
return V_73 ;
if ( F_91 ( V_21 ) ) {
V_207 = F_345 ( V_66 , V_207 ) ;
V_745 = V_66 -> V_209 . V_242 ;
V_746 = V_66 -> V_209 . V_269 ;
} else {
V_207 = F_345 ( V_66 , V_207 ) ;
V_223 = F_68 ( V_224 ) ;
V_745 = V_66 -> V_209 . V_242 ;
V_746 = ( V_223 >> 16 ) & 0xff ;
}
if ( V_207 < V_746 || V_207 > V_745 || V_207 < V_66 -> V_209 . V_384 ) {
F_7 ( & V_66 -> V_209 . V_266 ) ;
return - V_79 ;
}
V_66 -> V_209 . V_385 = V_207 ;
if ( F_91 ( V_21 ) )
F_346 ( V_21 , V_207 ) ;
else
F_347 ( V_21 , V_207 ) ;
F_7 ( & V_66 -> V_209 . V_266 ) ;
return 0 ;
}
static int
F_348 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_362 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_266 ) ;
if ( V_73 )
return V_73 ;
* V_207 = F_122 ( V_66 , V_66 -> V_209 . V_384 ) ;
F_7 ( & V_66 -> V_209 . V_266 ) ;
return 0 ;
}
static int
F_349 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_223 , V_745 , V_746 ;
int V_73 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_362 ;
F_114 ( & V_66 -> V_209 . V_210 ) ;
F_97 ( L_410 , V_207 ) ;
V_73 = F_31 ( & V_66 -> V_209 . V_266 ) ;
if ( V_73 )
return V_73 ;
if ( F_91 ( V_21 ) ) {
V_207 = F_345 ( V_66 , V_207 ) ;
V_745 = V_66 -> V_209 . V_242 ;
V_746 = V_66 -> V_209 . V_269 ;
} else {
V_207 = F_345 ( V_66 , V_207 ) ;
V_223 = F_68 ( V_224 ) ;
V_745 = V_66 -> V_209 . V_242 ;
V_746 = ( V_223 >> 16 ) & 0xff ;
}
if ( V_207 < V_746 || V_207 > V_745 || V_207 > V_66 -> V_209 . V_385 ) {
F_7 ( & V_66 -> V_209 . V_266 ) ;
return - V_79 ;
}
V_66 -> V_209 . V_384 = V_207 ;
if ( F_91 ( V_21 ) )
F_346 ( V_21 , V_207 ) ;
else
F_347 ( V_21 , V_207 ) ;
F_7 ( & V_66 -> V_209 . V_266 ) ;
return 0 ;
}
static int
F_350 ( void * V_18 , T_8 * V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_747 ;
int V_73 ;
if ( ! ( F_117 ( V_21 ) || F_118 ( V_21 ) ) )
return - V_362 ;
V_73 = F_31 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_77 ( V_66 ) ;
V_747 = F_68 ( V_748 ) ;
F_78 ( V_66 ) ;
F_7 ( & V_66 -> V_21 -> V_74 ) ;
* V_207 = ( V_747 & V_749 ) >> V_750 ;
return 0 ;
}
static int
F_351 ( void * V_18 , T_8 V_207 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_747 ;
if ( ! ( F_117 ( V_21 ) || F_118 ( V_21 ) ) )
return - V_362 ;
if ( V_207 > 3 )
return - V_79 ;
F_77 ( V_66 ) ;
F_97 ( L_411 , V_207 ) ;
V_747 = F_68 ( V_748 ) ;
V_747 &= ~ V_749 ;
V_747 |= ( V_207 << V_750 ) ;
F_151 ( V_748 , V_747 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_352 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_77 ( V_66 ) ;
F_120 ( V_66 , V_243 ) ;
return 0 ;
}
static int F_353 ( struct V_196 * V_196 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_196 -> V_197 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_123 ( V_66 , V_243 ) ;
F_78 ( V_66 ) ;
return 0 ;
}
static int F_354 ( struct V_4 * V_648 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_267 ( L_412 ,
V_751 ,
V_648 , V_21 ,
& V_752 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_752 ) ;
}
static int F_355 ( struct V_4 * V_648 ,
struct V_2 * V_3 ,
const char * V_45 ,
const struct V_753 * V_754 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_267 ( V_45 ,
V_650 | V_755 ,
V_648 , V_21 ,
V_754 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_754 ) ;
}
void F_356 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
enum V_124 V_124 ;
F_81 (dev_priv, pipe) {
struct V_627 * V_628 = & V_66 -> V_628 [ V_124 ] ;
V_628 -> V_630 = false ;
F_357 ( & V_628 -> V_311 ) ;
F_358 ( & V_628 -> V_643 ) ;
}
}
int F_359 ( struct V_2 * V_3 )
{
int V_73 , V_145 ;
V_73 = F_354 ( V_3 -> V_756 , V_3 ) ;
if ( V_73 )
return V_73 ;
for ( V_145 = 0 ; V_145 < F_270 ( V_649 ) ; V_145 ++ ) {
V_73 = F_266 ( V_3 -> V_756 , V_3 , V_145 ) ;
if ( V_73 )
return V_73 ;
}
for ( V_145 = 0 ; V_145 < F_270 ( V_757 ) ; V_145 ++ ) {
V_73 = F_355 ( V_3 -> V_756 , V_3 ,
V_757 [ V_145 ] . V_45 ,
V_757 [ V_145 ] . V_754 ) ;
if ( V_73 )
return V_73 ;
}
return F_360 ( V_758 ,
V_759 ,
V_3 -> V_756 , V_3 ) ;
}
void F_361 ( struct V_2 * V_3 )
{
int V_145 ;
F_362 ( V_758 ,
V_759 , V_3 ) ;
F_362 ( (struct V_760 * ) & V_752 ,
1 , V_3 ) ;
for ( V_145 = 0 ; V_145 < F_270 ( V_649 ) ; V_145 ++ ) {
struct V_760 * V_761 =
(struct V_760 * ) & V_649 [ V_145 ] ;
F_362 ( V_761 , 1 , V_3 ) ;
}
for ( V_145 = 0 ; V_145 < F_270 ( V_757 ) ; V_145 ++ ) {
struct V_760 * V_761 =
(struct V_760 * ) V_757 [ V_145 ] . V_754 ;
F_362 ( V_761 , 1 , V_3 ) ;
}
}
