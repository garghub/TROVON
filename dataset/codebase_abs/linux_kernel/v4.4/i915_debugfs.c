static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const void * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL ) {
F_3 ( V_4 ) ;
return - V_9 ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_10 = V_4 ;
V_7 -> V_11 = ( void * ) V_5 ;
F_4 ( & V_2 -> V_12 ) ;
F_5 ( & V_7 -> V_13 , & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
const struct V_21 * V_22 = F_8 ( V_20 ) ;
F_9 ( V_16 , L_1 , V_22 -> V_23 ) ;
F_9 ( V_16 , L_2 , F_10 ( V_20 ) ) ;
#define F_11 ( T_1 ) seq_printf(m, #x ": %s\n", yesno(info->x))
#define F_12 ;
F_13 ( F_11 , F_12 ) ;
#undef F_11
#undef F_12
return 0 ;
}
static const char * F_14 ( struct V_24 * V_25 )
{
if ( V_25 -> V_26 )
return L_3 ;
else
return L_4 ;
}
static const char * F_15 ( struct V_24 * V_25 )
{
switch ( V_25 -> V_27 ) {
default:
case V_28 : return L_4 ;
case V_29 : return L_5 ;
case V_30 : return L_6 ;
}
}
static inline const char * F_16 ( struct V_24 * V_25 )
{
return F_17 ( V_25 ) ? L_7 : L_4 ;
}
static T_2 F_18 ( struct V_24 * V_25 )
{
T_2 V_31 = 0 ;
struct V_32 * V_33 ;
F_19 (vma, &obj->vma_list, vma_link) {
if ( F_20 ( V_33 -> V_34 ) &&
F_21 ( & V_33 -> V_7 ) )
V_31 += V_33 -> V_7 . V_31 ;
}
return V_31 ;
}
static void
F_22 ( struct V_15 * V_16 , struct V_24 * V_25 )
{
struct V_35 * V_36 = F_23 ( V_25 -> V_37 . V_20 ) ;
struct V_38 * V_39 ;
struct V_32 * V_33 ;
int V_40 = 0 ;
int V_41 ;
F_9 ( V_16 , L_8 ,
& V_25 -> V_37 ,
V_25 -> V_42 ? L_9 : L_4 ,
F_14 ( V_25 ) ,
F_15 ( V_25 ) ,
F_16 ( V_25 ) ,
V_25 -> V_37 . V_31 / 1024 ,
V_25 -> V_37 . V_43 ,
V_25 -> V_37 . V_44 ) ;
F_24 (ring, dev_priv, i)
F_9 ( V_16 , L_10 ,
F_25 ( V_25 -> V_45 [ V_41 ] ) ) ;
F_9 ( V_16 , L_11 ,
F_25 ( V_25 -> V_46 ) ,
F_25 ( V_25 -> V_47 ) ,
F_26 ( F_23 ( V_25 -> V_37 . V_20 ) , V_25 -> V_48 ) ,
V_25 -> V_49 ? L_12 : L_13 ,
V_25 -> V_50 == V_51 ? L_14 : L_13 ) ;
if ( V_25 -> V_37 . V_52 )
F_9 ( V_16 , L_15 , V_25 -> V_37 . V_52 ) ;
F_19 (vma, &obj->vma_list, vma_link) {
if ( V_33 -> V_40 > 0 )
V_40 ++ ;
}
F_9 ( V_16 , L_16 , V_40 ) ;
if ( V_25 -> V_26 )
F_9 ( V_16 , L_17 ) ;
if ( V_25 -> V_53 != V_54 )
F_9 ( V_16 , L_18 , V_25 -> V_53 ) ;
F_19 (vma, &obj->vma_list, vma_link) {
F_9 ( V_16 , L_19 ,
F_20 ( V_33 -> V_34 ) ? L_7 : L_20 ,
V_33 -> V_7 . V_55 , V_33 -> V_7 . V_31 ) ;
if ( F_20 ( V_33 -> V_34 ) )
F_9 ( V_16 , L_21 , V_33 -> V_56 . type ) ;
else
F_27 ( V_16 , L_22 ) ;
}
if ( V_25 -> V_57 )
F_9 ( V_16 , L_23 , V_25 -> V_57 -> V_55 ) ;
if ( V_25 -> V_26 || V_25 -> V_58 ) {
char V_59 [ 3 ] , * V_60 = V_59 ;
if ( V_25 -> V_26 )
* V_60 ++ = 'p' ;
if ( V_25 -> V_58 )
* V_60 ++ = 'f' ;
* V_60 = '\0' ;
F_9 ( V_16 , L_24 , V_59 ) ;
}
if ( V_25 -> V_46 != NULL )
F_9 ( V_16 , L_25 ,
F_28 ( V_25 -> V_46 ) -> V_52 ) ;
if ( V_25 -> V_61 )
F_9 ( V_16 , L_26 , V_25 -> V_61 ) ;
}
static void F_29 ( struct V_15 * V_16 , struct V_62 * V_63 )
{
F_30 ( V_16 , V_63 -> V_64 . V_65 ? 'I' : 'i' ) ;
F_30 ( V_16 , V_63 -> V_66 ? 'R' : 'r' ) ;
F_30 ( V_16 , ' ' ) ;
}
static int F_31 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
T_3 V_13 = ( T_3 ) V_7 -> V_11 -> V_17 ;
struct V_67 * V_68 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_70 * V_34 = & V_36 -> V_71 . V_37 ;
struct V_32 * V_33 ;
T_2 V_72 , V_73 ;
int V_74 , V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
switch ( V_13 ) {
case V_77 :
F_27 ( V_16 , L_27 ) ;
V_68 = & V_34 -> V_78 ;
break;
case V_79 :
F_27 ( V_16 , L_28 ) ;
V_68 = & V_34 -> V_80 ;
break;
default:
F_6 ( & V_20 -> V_76 ) ;
return - V_81 ;
}
V_72 = V_73 = V_74 = 0 ;
F_19 (vma, head, mm_list) {
F_9 ( V_16 , L_29 ) ;
F_22 ( V_16 , V_33 -> V_25 ) ;
F_9 ( V_16 , L_30 ) ;
V_72 += V_33 -> V_25 -> V_37 . V_31 ;
V_73 += V_33 -> V_7 . V_31 ;
V_74 ++ ;
}
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_31 ,
V_74 , V_72 , V_73 ) ;
return 0 ;
}
static int F_33 ( void * V_82 ,
struct V_67 * V_83 , struct V_67 * V_84 )
{
struct V_24 * V_85 =
F_34 ( V_83 , struct V_24 , V_86 ) ;
struct V_24 * V_87 =
F_34 ( V_84 , struct V_24 , V_86 ) ;
if ( V_85 -> V_57 -> V_55 < V_87 -> V_57 -> V_55 )
return - 1 ;
if ( V_85 -> V_57 -> V_55 > V_87 -> V_57 -> V_55 )
return 1 ;
return 0 ;
}
static int F_35 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_25 ;
T_2 V_72 , V_73 ;
F_36 ( V_57 ) ;
int V_74 , V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_72 = V_73 = V_74 = 0 ;
F_19 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_25 -> V_57 == NULL )
continue;
F_5 ( & V_25 -> V_86 , & V_57 ) ;
V_72 += V_25 -> V_37 . V_31 ;
V_73 += F_18 ( V_25 ) ;
V_74 ++ ;
}
F_19 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_25 -> V_57 == NULL )
continue;
F_5 ( & V_25 -> V_86 , & V_57 ) ;
V_72 += V_25 -> V_37 . V_31 ;
V_74 ++ ;
}
F_37 ( NULL , & V_57 , F_33 ) ;
F_27 ( V_16 , L_32 ) ;
while ( ! F_38 ( & V_57 ) ) {
V_25 = F_39 ( & V_57 , F_40 ( * V_25 ) , V_86 ) ;
F_27 ( V_16 , L_29 ) ;
F_22 ( V_16 , V_25 ) ;
F_30 ( V_16 , '\n' ) ;
F_41 ( & V_25 -> V_86 ) ;
}
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_31 ,
V_74 , V_72 , V_73 ) ;
return 0 ;
}
static int F_42 ( int V_88 , void * V_89 , void * V_17 )
{
struct V_24 * V_25 = V_89 ;
struct V_90 * V_91 = V_17 ;
struct V_32 * V_33 ;
V_91 -> V_74 ++ ;
V_91 -> V_92 += V_25 -> V_37 . V_31 ;
if ( V_25 -> V_37 . V_52 || V_25 -> V_37 . V_93 )
V_91 -> V_94 += V_25 -> V_37 . V_31 ;
if ( F_43 ( V_25 -> V_37 . V_20 ) ) {
F_19 (vma, &obj->vma_list, vma_link) {
struct V_95 * V_96 ;
if ( ! F_21 ( & V_33 -> V_7 ) )
continue;
if ( F_20 ( V_33 -> V_34 ) ) {
V_91 -> V_97 += V_25 -> V_37 . V_31 ;
continue;
}
V_96 = F_34 ( V_33 -> V_34 , struct V_95 , V_37 ) ;
if ( V_96 -> V_98 != V_91 -> V_98 )
continue;
if ( V_25 -> V_42 )
V_91 -> V_42 += V_25 -> V_37 . V_31 ;
else
V_91 -> V_99 += V_25 -> V_37 . V_31 ;
return 0 ;
}
} else {
if ( F_44 ( V_25 ) ) {
V_91 -> V_97 += V_25 -> V_37 . V_31 ;
if ( V_25 -> V_42 )
V_91 -> V_42 += V_25 -> V_37 . V_31 ;
else
V_91 -> V_99 += V_25 -> V_37 . V_31 ;
return 0 ;
}
}
if ( ! F_38 ( & V_25 -> V_100 ) )
V_91 -> V_101 += V_25 -> V_37 . V_31 ;
return 0 ;
}
static void F_45 ( struct V_15 * V_16 ,
struct V_35 * V_36 )
{
struct V_24 * V_25 ;
struct V_90 V_91 ;
struct V_38 * V_39 ;
int V_41 , V_102 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
F_24 (ring, dev_priv, i) {
for ( V_102 = 0 ; V_102 < F_46 ( V_39 -> V_103 . V_104 ) ; V_102 ++ ) {
F_19 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
F_42 ( 0 , V_25 , & V_91 ) ;
}
}
F_47 ( V_16 , L_33 , V_91 ) ;
}
static int F_48 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_74 , V_105 , V_106 ;
T_2 V_31 , V_107 , V_108 ;
struct V_24 * V_25 ;
struct V_70 * V_34 = & V_36 -> V_71 . V_37 ;
struct V_109 * V_110 ;
struct V_32 * V_33 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_9 ( V_16 , L_34 ,
V_36 -> V_111 . V_112 ,
V_36 -> V_111 . V_113 ) ;
V_31 = V_74 = V_107 = V_105 = 0 ;
F_49 ( & V_36 -> V_111 . V_114 , V_100 ) ;
F_9 ( V_16 , L_35 ,
V_74 , V_105 , V_31 , V_107 ) ;
V_31 = V_74 = V_107 = V_105 = 0 ;
F_50 ( & V_34 -> V_78 , V_115 ) ;
F_9 ( V_16 , L_36 ,
V_74 , V_105 , V_31 , V_107 ) ;
V_31 = V_74 = V_107 = V_105 = 0 ;
F_50 ( & V_34 -> V_80 , V_115 ) ;
F_9 ( V_16 , L_37 ,
V_74 , V_105 , V_31 , V_107 ) ;
V_31 = V_74 = V_108 = V_106 = 0 ;
F_19 (obj, &dev_priv->mm.unbound_list, global_list) {
V_31 += V_25 -> V_37 . V_31 , ++ V_74 ;
if ( V_25 -> V_50 == V_51 )
V_108 += V_25 -> V_37 . V_31 , ++ V_106 ;
}
F_9 ( V_16 , L_38 , V_74 , V_31 ) ;
V_31 = V_74 = V_107 = V_105 = 0 ;
F_19 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_25 -> V_58 ) {
V_31 += F_51 ( V_25 ) ;
++ V_74 ;
}
if ( V_25 -> V_26 ) {
V_107 += F_51 ( V_25 ) ;
++ V_105 ;
}
if ( V_25 -> V_50 == V_51 ) {
V_108 += V_25 -> V_37 . V_31 ;
++ V_106 ;
}
}
F_9 ( V_16 , L_39 ,
V_106 , V_108 ) ;
F_9 ( V_16 , L_40 ,
V_105 , V_107 ) ;
F_9 ( V_16 , L_41 ,
V_74 , V_31 ) ;
F_9 ( V_16 , L_42 ,
V_36 -> V_71 . V_37 . V_92 ,
( T_2 ) V_36 -> V_71 . V_116 - V_36 -> V_71 . V_37 . V_55 ) ;
F_30 ( V_16 , '\n' ) ;
F_45 ( V_16 , V_36 ) ;
F_52 (file, &dev->filelist, lhead) {
struct V_90 V_91 ;
struct V_117 * V_118 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_98 = V_110 -> V_119 ;
F_53 ( & V_110 -> V_120 ) ;
F_54 ( & V_110 -> V_121 , F_42 , & V_91 ) ;
F_55 ( & V_110 -> V_120 ) ;
F_56 () ;
V_118 = F_57 ( V_110 -> V_122 , V_123 ) ;
F_47 ( V_16 , V_118 ? V_118 -> V_124 : L_43 , V_91 ) ;
F_58 () ;
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_59 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
T_3 V_13 = ( T_3 ) V_7 -> V_11 -> V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_25 ;
T_2 V_72 , V_73 ;
int V_74 , V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_72 = V_73 = V_74 = 0 ;
F_19 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_13 == V_125 && ! F_60 ( V_25 ) )
continue;
F_27 ( V_16 , L_29 ) ;
F_22 ( V_16 , V_25 ) ;
F_30 ( V_16 , '\n' ) ;
V_72 += V_25 -> V_37 . V_31 ;
V_73 += F_18 ( V_25 ) ;
V_74 ++ ;
}
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_31 ,
V_74 , V_72 , V_73 ) ;
return 0 ;
}
static int F_61 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_126 * V_127 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_62 (dev, crtc) {
const char V_128 = F_63 ( V_127 -> V_128 ) ;
const char V_129 = F_64 ( V_127 -> V_129 ) ;
struct V_130 * V_131 ;
F_65 ( & V_20 -> V_132 ) ;
V_131 = V_127 -> V_133 ;
if ( V_131 == NULL ) {
F_9 ( V_16 , L_44 ,
V_128 , V_129 ) ;
} else {
T_4 V_134 ;
if ( F_66 ( & V_131 -> V_135 ) < V_136 ) {
F_9 ( V_16 , L_45 ,
V_128 , V_129 ) ;
} else {
F_9 ( V_16 , L_46 ,
V_128 , V_129 ) ;
}
if ( V_131 -> V_137 ) {
struct V_38 * V_39 =
F_28 ( V_131 -> V_137 ) ;
F_9 ( V_16 , L_47 ,
V_39 -> V_52 ,
F_25 ( V_131 -> V_137 ) ,
V_36 -> V_138 ,
V_39 -> V_139 ( V_39 , true ) ,
F_67 ( V_131 -> V_137 , true ) ) ;
} else
F_9 ( V_16 , L_48 ) ;
F_9 ( V_16 , L_49 ,
V_131 -> V_140 ,
V_131 -> V_141 ,
F_68 ( & V_127 -> V_37 ) ) ;
if ( V_131 -> V_142 )
F_27 ( V_16 , L_50 ) ;
else
F_27 ( V_16 , L_51 ) ;
F_9 ( V_16 , L_52 , F_66 ( & V_131 -> V_135 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 4 )
V_134 = F_69 ( F_70 ( F_71 ( V_127 -> V_129 ) ) ) ;
else
V_134 = F_70 ( F_72 ( V_127 -> V_129 ) ) ;
F_9 ( V_16 , L_53 , V_134 ) ;
if ( V_131 -> V_143 ) {
F_9 ( V_16 , L_54 , ( long ) V_131 -> V_144 ) ;
F_9 ( V_16 , L_55 , V_134 == V_131 -> V_144 ) ;
}
}
F_73 ( & V_20 -> V_132 ) ;
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_74 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_25 ;
struct V_38 * V_39 ;
int V_92 = 0 ;
int V_75 , V_41 , V_102 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_24 (ring, dev_priv, i) {
for ( V_102 = 0 ; V_102 < F_46 ( V_39 -> V_103 . V_104 ) ; V_102 ++ ) {
int V_74 ;
V_74 = 0 ;
F_19 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
V_74 ++ ;
F_9 ( V_16 , L_56 ,
V_39 -> V_52 , V_102 , V_74 ) ;
F_19 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link) {
F_27 ( V_16 , L_29 ) ;
F_22 ( V_16 , V_25 ) ;
F_30 ( V_16 , '\n' ) ;
}
V_92 += V_74 ;
}
}
F_9 ( V_16 , L_57 , V_92 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_75 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_145 * V_146 ;
int V_75 , V_147 , V_41 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_147 = 0 ;
F_24 (ring, dev_priv, i) {
int V_74 ;
V_74 = 0 ;
F_19 (req, &ring->request_list, list)
V_74 ++ ;
if ( V_74 == 0 )
continue;
F_9 ( V_16 , L_58 , V_39 -> V_52 , V_74 ) ;
F_19 (req, &ring->request_list, list) {
struct V_117 * V_118 ;
F_56 () ;
V_118 = NULL ;
if ( V_146 -> V_122 )
V_118 = F_57 ( V_146 -> V_122 , V_123 ) ;
F_9 ( V_16 , L_59 ,
V_146 -> V_148 ,
( int ) ( V_149 - V_146 -> V_150 ) ,
V_118 ? V_118 -> V_124 : L_43 ,
V_118 ? V_118 -> V_122 : - 1 ) ;
F_58 () ;
}
V_147 ++ ;
}
F_6 ( & V_20 -> V_76 ) ;
if ( V_147 == 0 )
F_27 ( V_16 , L_60 ) ;
return 0 ;
}
static void F_76 ( struct V_15 * V_16 ,
struct V_38 * V_39 )
{
if ( V_39 -> V_139 ) {
F_9 ( V_16 , L_61 ,
V_39 -> V_52 , V_39 -> V_139 ( V_39 , false ) ) ;
}
}
static int F_77 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_75 , V_41 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
F_24 (ring, dev_priv, i)
F_76 ( V_16 , V_39 ) ;
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_80 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_75 , V_41 , V_128 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
if ( F_81 ( V_20 ) ) {
F_9 ( V_16 , L_62 ,
F_70 ( V_151 ) ) ;
F_9 ( V_16 , L_63 ,
F_70 ( V_152 ) ) ;
F_9 ( V_16 , L_64 ,
F_70 ( V_153 ) ) ;
F_9 ( V_16 , L_65 ,
F_70 ( V_154 ) ) ;
F_9 ( V_16 , L_66 ,
F_70 ( V_155 ) ) ;
F_82 (dev_priv, pipe)
F_9 ( V_16 , L_67 ,
F_63 ( V_128 ) ,
F_70 ( F_83 ( V_128 ) ) ) ;
F_9 ( V_16 , L_68 ,
F_70 ( V_156 ) ) ;
F_9 ( V_16 , L_69 ,
F_70 ( V_157 ) ) ;
F_9 ( V_16 , L_70 ,
F_70 ( V_158 ) ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
F_9 ( V_16 , L_71 ,
V_41 , F_70 ( F_84 ( V_41 ) ) ) ;
F_9 ( V_16 , L_72 ,
V_41 , F_70 ( F_85 ( V_41 ) ) ) ;
F_9 ( V_16 , L_73 ,
V_41 , F_70 ( F_86 ( V_41 ) ) ) ;
}
F_9 ( V_16 , L_74 ,
F_70 ( V_159 ) ) ;
F_9 ( V_16 , L_75 ,
F_70 ( V_160 ) ) ;
F_9 ( V_16 , L_76 ,
F_70 ( V_161 ) ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 8 ) {
F_9 ( V_16 , L_62 ,
F_70 ( V_151 ) ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
F_9 ( V_16 , L_71 ,
V_41 , F_70 ( F_84 ( V_41 ) ) ) ;
F_9 ( V_16 , L_72 ,
V_41 , F_70 ( F_85 ( V_41 ) ) ) ;
F_9 ( V_16 , L_73 ,
V_41 , F_70 ( F_86 ( V_41 ) ) ) ;
}
F_82 (dev_priv, pipe) {
if ( ! F_87 ( V_36 ,
F_88 ( V_128 ) ) ) {
F_9 ( V_16 , L_77 ,
F_63 ( V_128 ) ) ;
continue;
}
F_9 ( V_16 , L_78 ,
F_63 ( V_128 ) ,
F_70 ( F_89 ( V_128 ) ) ) ;
F_9 ( V_16 , L_79 ,
F_63 ( V_128 ) ,
F_70 ( F_90 ( V_128 ) ) ) ;
F_9 ( V_16 , L_80 ,
F_63 ( V_128 ) ,
F_70 ( F_91 ( V_128 ) ) ) ;
}
F_9 ( V_16 , L_81 ,
F_70 ( V_162 ) ) ;
F_9 ( V_16 , L_82 ,
F_70 ( V_163 ) ) ;
F_9 ( V_16 , L_83 ,
F_70 ( V_164 ) ) ;
F_9 ( V_16 , L_84 ,
F_70 ( V_165 ) ) ;
F_9 ( V_16 , L_85 ,
F_70 ( V_166 ) ) ;
F_9 ( V_16 , L_86 ,
F_70 ( V_167 ) ) ;
F_9 ( V_16 , L_74 ,
F_70 ( V_159 ) ) ;
F_9 ( V_16 , L_75 ,
F_70 ( V_160 ) ) ;
F_9 ( V_16 , L_76 ,
F_70 ( V_161 ) ) ;
} else if ( F_92 ( V_20 ) ) {
F_9 ( V_16 , L_63 ,
F_70 ( V_152 ) ) ;
F_9 ( V_16 , L_64 ,
F_70 ( V_153 ) ) ;
F_9 ( V_16 , L_65 ,
F_70 ( V_154 ) ) ;
F_9 ( V_16 , L_66 ,
F_70 ( V_155 ) ) ;
F_82 (dev_priv, pipe)
F_9 ( V_16 , L_67 ,
F_63 ( V_128 ) ,
F_70 ( F_83 ( V_128 ) ) ) ;
F_9 ( V_16 , L_87 ,
F_70 ( V_168 ) ) ;
F_9 ( V_16 , L_88 ,
F_70 ( V_169 ) ) ;
F_9 ( V_16 , L_89 ,
F_70 ( V_170 ) ) ;
F_9 ( V_16 , L_90 ,
F_70 ( V_171 ) ) ;
F_9 ( V_16 , L_91 ,
F_70 ( V_172 ) ) ;
F_9 ( V_16 , L_92 ,
F_70 ( V_173 ) ) ;
F_9 ( V_16 , L_93 ,
F_70 ( V_174 ) ) ;
F_9 ( V_16 , L_68 ,
F_70 ( V_156 ) ) ;
F_9 ( V_16 , L_69 ,
F_70 ( V_157 ) ) ;
F_9 ( V_16 , L_70 ,
F_70 ( V_158 ) ) ;
} else if ( ! F_93 ( V_20 ) ) {
F_9 ( V_16 , L_94 ,
F_70 ( V_175 ) ) ;
F_9 ( V_16 , L_95 ,
F_70 ( V_176 ) ) ;
F_9 ( V_16 , L_96 ,
F_70 ( V_177 ) ) ;
F_82 (dev_priv, pipe)
F_9 ( V_16 , L_97 ,
F_63 ( V_128 ) ,
F_70 ( F_83 ( V_128 ) ) ) ;
} else {
F_9 ( V_16 , L_98 ,
F_70 ( V_178 ) ) ;
F_9 ( V_16 , L_99 ,
F_70 ( V_179 ) ) ;
F_9 ( V_16 , L_100 ,
F_70 ( V_180 ) ) ;
F_9 ( V_16 , L_101 ,
F_70 ( V_181 ) ) ;
F_9 ( V_16 , L_102 ,
F_70 ( V_182 ) ) ;
F_9 ( V_16 , L_103 ,
F_70 ( V_183 ) ) ;
F_9 ( V_16 , L_104 ,
F_70 ( V_169 ) ) ;
F_9 ( V_16 , L_105 ,
F_70 ( V_170 ) ) ;
F_9 ( V_16 , L_106 ,
F_70 ( V_171 ) ) ;
}
F_24 (ring, dev_priv, i) {
if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
F_9 ( V_16 ,
L_107 ,
V_39 -> V_52 , F_94 ( V_39 ) ) ;
}
F_76 ( V_16 , V_39 ) ;
}
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_95 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 , V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_9 ( V_16 , L_108 , V_36 -> V_184 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_184 ; V_41 ++ ) {
struct V_24 * V_25 = V_36 -> V_185 [ V_41 ] . V_25 ;
F_9 ( V_16 , L_109 ,
V_41 , V_36 -> V_185 [ V_41 ] . V_40 ) ;
if ( V_25 == NULL )
F_27 ( V_16 , L_110 ) ;
else
F_22 ( V_16 , V_25 ) ;
F_30 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_96 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
const T_4 * V_186 ;
int V_41 ;
V_39 = & V_36 -> V_39 [ ( T_3 ) V_7 -> V_11 -> V_17 ] ;
V_186 = V_39 -> V_187 . V_188 ;
if ( V_186 == NULL )
return 0 ;
for ( V_41 = 0 ; V_41 < 4096 / sizeof( T_4 ) / 4 ; V_41 += 4 ) {
F_9 ( V_16 , L_111 ,
V_41 * 4 ,
V_186 [ V_41 ] , V_186 [ V_41 + 1 ] , V_186 [ V_41 + 2 ] , V_186 [ V_41 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_97 ( struct V_110 * V_189 ,
const char T_6 * V_190 ,
T_7 V_191 ,
T_8 * V_192 )
{
struct V_193 * V_194 = V_189 -> V_195 ;
struct V_19 * V_20 = V_194 -> V_20 ;
int V_75 ;
F_98 ( L_112 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_99 ( V_20 ) ;
F_6 ( & V_20 -> V_76 ) ;
return V_191 ;
}
static int F_100 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
struct V_193 * V_194 ;
V_194 = F_101 ( sizeof( * V_194 ) , V_8 ) ;
if ( ! V_194 )
return - V_9 ;
V_194 -> V_20 = V_20 ;
F_102 ( V_20 , V_194 ) ;
V_110 -> V_195 = V_194 ;
return 0 ;
}
static int F_103 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_193 * V_194 = V_110 -> V_195 ;
F_104 ( V_194 ) ;
F_105 ( V_194 ) ;
return 0 ;
}
static T_5 F_106 ( struct V_110 * V_110 , char T_6 * V_198 ,
T_7 V_74 , T_8 * V_199 )
{
struct V_193 * V_194 = V_110 -> V_195 ;
struct V_200 V_201 ;
T_8 V_202 = 0 ;
T_5 V_203 = 0 ;
int V_75 ;
V_75 = F_107 ( & V_201 , F_23 ( V_194 -> V_20 ) , V_74 , * V_199 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_108 ( & V_201 , V_194 ) ;
if ( V_75 )
goto V_204;
V_203 = F_109 ( V_198 , V_74 , & V_202 ,
V_201 . V_205 ,
V_201 . V_206 ) ;
if ( V_203 < 0 )
V_75 = V_203 ;
else
* V_199 = V_201 . V_55 + V_203 ;
V_204:
F_110 ( & V_201 ) ;
return V_75 ? : V_203 ;
}
static int
F_111 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
* V_207 = V_36 -> V_138 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_112 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_113 ( V_20 , V_207 ) ;
F_6 ( & V_20 -> V_76 ) ;
return V_75 ;
}
static int F_114 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 = 0 ;
F_78 ( V_36 ) ;
F_115 ( & V_36 -> V_209 . V_210 ) ;
if ( F_116 ( V_20 ) ) {
T_9 V_211 = F_117 ( V_212 ) ;
T_9 V_213 = F_117 ( V_214 ) ;
F_9 ( V_16 , L_113 , ( V_211 >> 8 ) & 0xf ) ;
F_9 ( V_16 , L_114 , V_211 & 0x3f ) ;
F_9 ( V_16 , L_115 , ( V_213 & V_215 ) >>
V_216 ) ;
F_9 ( V_16 , L_116 ,
( V_213 & V_217 ) >> V_218 ) ;
} else if ( F_118 ( V_20 ) || ( F_119 ( V_20 ) && ! F_92 ( V_20 ) ) ||
F_120 ( V_20 ) || F_121 ( V_20 ) ) {
T_4 V_219 ;
T_4 V_220 ;
T_4 V_221 ;
T_4 V_222 , V_223 , V_224 ;
T_4 V_225 , V_226 , V_227 ;
T_4 V_228 , V_229 , V_230 ;
T_4 V_231 , V_232 , V_233 ;
T_4 V_234 , V_235 , V_236 , V_237 , V_238 ;
int V_239 ;
V_219 = F_70 ( V_240 ) ;
if ( F_122 ( V_20 ) ) {
V_221 = F_70 ( V_241 ) ;
V_220 = F_70 ( V_242 ) ;
} else {
V_221 = F_70 ( V_243 ) ;
V_220 = F_70 ( V_244 ) ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
goto V_204;
F_123 ( V_36 , V_245 ) ;
V_227 = F_70 ( V_246 ) ;
if ( F_121 ( V_20 ) )
V_227 >>= 23 ;
else {
V_227 &= ~ V_247 ;
if ( F_124 ( V_20 ) || F_120 ( V_20 ) )
V_227 >>= 24 ;
else
V_227 >>= 25 ;
}
V_227 = F_125 ( V_36 , V_227 ) ;
V_222 = F_70 ( V_248 ) ;
V_223 = F_70 ( V_249 ) ;
V_224 = F_70 ( V_250 ) ;
V_225 = F_70 ( V_251 ) ;
V_228 = F_70 ( V_252 ) ;
V_229 = F_70 ( V_253 ) ;
V_230 = F_70 ( V_254 ) ;
V_231 = F_70 ( V_255 ) ;
V_232 = F_70 ( V_256 ) ;
V_233 = F_70 ( V_257 ) ;
if ( F_121 ( V_20 ) )
V_226 = ( V_225 & V_258 ) >> V_259 ;
else if ( F_124 ( V_20 ) || F_120 ( V_20 ) )
V_226 = ( V_225 & V_260 ) >> V_261 ;
else
V_226 = ( V_225 & V_262 ) >> V_263 ;
V_226 = F_125 ( V_36 , V_226 ) ;
F_126 ( V_36 , V_245 ) ;
F_6 ( & V_20 -> V_76 ) ;
if ( F_118 ( V_20 ) || F_119 ( V_20 ) ) {
V_234 = F_70 ( V_172 ) ;
V_235 = F_70 ( V_174 ) ;
V_236 = F_70 ( V_264 ) ;
V_237 = F_70 ( V_173 ) ;
V_238 = F_70 ( V_265 ) ;
} else {
V_234 = F_70 ( F_86 ( 2 ) ) ;
V_235 = F_70 ( F_84 ( 2 ) ) ;
V_236 = F_70 ( F_127 ( 2 ) ) ;
V_237 = F_70 ( F_85 ( 2 ) ) ;
V_238 = F_70 ( V_265 ) ;
}
F_9 ( V_16 , L_117 ,
V_234 , V_235 , V_236 , V_237 , V_238 ) ;
F_9 ( V_16 , L_118 , V_220 ) ;
F_9 ( V_16 , L_119 ,
( V_220 & ( F_121 ( V_20 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_9 ( V_16 , L_120 ,
V_220 & 0xff ) ;
F_9 ( V_16 , L_121 ,
V_219 & 0xff ) ;
F_9 ( V_16 , L_122 , V_225 ) ;
F_9 ( V_16 , L_123 , V_222 ) ;
F_9 ( V_16 , L_124 , V_223 ) ;
F_9 ( V_16 , L_125 , V_224 ) ;
F_9 ( V_16 , L_126 , V_227 ) ;
F_9 ( V_16 , L_127 , V_226 ) ;
F_9 ( V_16 , L_128 , V_228 &
V_266 ) ;
F_9 ( V_16 , L_129 , V_229 &
V_267 ) ;
F_9 ( V_16 , L_130 , V_230 &
V_267 ) ;
F_9 ( V_16 , L_131 ,
V_36 -> V_209 . V_268 ) ;
F_9 ( V_16 , L_132 , V_231 &
V_269 ) ;
F_9 ( V_16 , L_133 , V_232 &
V_267 ) ;
F_9 ( V_16 , L_134 , V_233 &
V_267 ) ;
F_9 ( V_16 , L_135 ,
V_36 -> V_209 . V_270 ) ;
V_239 = ( F_122 ( V_20 ) ? V_221 >> 0 :
V_221 >> 16 ) & 0xff ;
V_239 *= ( F_128 ( V_20 ) ? V_271 : 1 ) ;
F_9 ( V_16 , L_136 ,
F_125 ( V_36 , V_239 ) ) ;
V_239 = ( V_221 & 0xff00 ) >> 8 ;
V_239 *= ( F_128 ( V_20 ) ? V_271 : 1 ) ;
F_9 ( V_16 , L_137 ,
F_125 ( V_36 , V_239 ) ) ;
V_239 = ( F_122 ( V_20 ) ? V_221 >> 16 :
V_221 >> 0 ) & 0xff ;
V_239 *= ( F_128 ( V_20 ) ? V_271 : 1 ) ;
F_9 ( V_16 , L_138 ,
F_125 ( V_36 , V_239 ) ) ;
F_9 ( V_16 , L_139 ,
F_125 ( V_36 , V_36 -> V_209 . V_239 ) ) ;
F_9 ( V_16 , L_140 ,
F_125 ( V_36 , V_36 -> V_209 . V_272 ) ) ;
F_9 ( V_16 , L_141 , V_226 ) ;
F_9 ( V_16 , L_142 ,
F_125 ( V_36 , V_36 -> V_209 . V_273 ) ) ;
F_9 ( V_16 , L_143 ,
F_125 ( V_36 , V_36 -> V_209 . V_274 ) ) ;
F_9 ( V_16 , L_144 ,
F_125 ( V_36 , V_36 -> V_209 . V_239 ) ) ;
F_9 ( V_16 ,
L_145 ,
F_125 ( V_36 , V_36 -> V_209 . V_275 ) ) ;
} else if ( F_92 ( V_20 ) ) {
T_4 V_276 ;
F_4 ( & V_36 -> V_209 . V_277 ) ;
V_276 = F_129 ( V_36 , V_278 ) ;
F_9 ( V_16 , L_146 , V_276 ) ;
F_9 ( V_16 , L_147 , V_36 -> V_279 ) ;
F_9 ( V_16 , L_148 ,
F_125 ( V_36 , ( V_276 >> 8 ) & 0xff ) ) ;
F_9 ( V_16 , L_149 ,
F_125 ( V_36 , V_36 -> V_209 . V_272 ) ) ;
F_9 ( V_16 , L_150 ,
F_125 ( V_36 , V_36 -> V_209 . V_239 ) ) ;
F_9 ( V_16 , L_151 ,
F_125 ( V_36 , V_36 -> V_209 . V_274 ) ) ;
F_9 ( V_16 , L_152 ,
F_125 ( V_36 , V_36 -> V_209 . V_273 ) ) ;
F_9 ( V_16 ,
L_145 ,
F_125 ( V_36 , V_36 -> V_209 . V_275 ) ) ;
F_6 ( & V_36 -> V_209 . V_277 ) ;
} else {
F_27 ( V_16 , L_153 ) ;
}
F_9 ( V_16 , L_154 , V_36 -> V_280 ) ;
F_9 ( V_16 , L_155 , V_36 -> V_281 ) ;
F_9 ( V_16 , L_156 , V_36 -> V_282 ) ;
V_204:
F_79 ( V_36 ) ;
return V_75 ;
}
static int F_130 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
T_2 V_283 [ V_284 ] ;
T_4 V_148 [ V_284 ] ;
int V_41 ;
if ( ! V_285 . V_286 ) {
F_9 ( V_16 , L_157 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_24 (ring, dev_priv, i) {
V_148 [ V_41 ] = V_39 -> V_139 ( V_39 , false ) ;
V_283 [ V_41 ] = F_131 ( V_39 ) ;
}
F_79 ( V_36 ) ;
if ( F_132 ( & V_36 -> V_287 . V_288 ) ) {
F_9 ( V_16 , L_158 ,
F_133 ( V_36 -> V_287 . V_288 . V_289 . V_290 -
V_149 ) ) ;
} else
F_9 ( V_16 , L_159 ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_160 , V_39 -> V_52 ) ;
F_9 ( V_16 , L_161 ,
V_39 -> V_291 . V_148 , V_148 [ V_41 ] ) ;
F_9 ( V_16 , L_162 ,
( long long ) V_39 -> V_291 . V_283 ,
( long long ) V_283 [ V_41 ] ) ;
F_9 ( V_16 , L_163 ,
( long long ) V_39 -> V_291 . V_292 ) ;
F_9 ( V_16 , L_164 , V_39 -> V_291 . V_293 ) ;
F_9 ( V_16 , L_165 , V_39 -> V_291 . V_294 ) ;
}
return 0 ;
}
static int F_134 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_295 , V_296 ;
T_9 V_297 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
V_295 = F_70 ( V_298 ) ;
V_296 = F_70 ( V_299 ) ;
V_297 = F_117 ( V_300 ) ;
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_166 , F_135 ( V_295 & V_301 ) ) ;
F_9 ( V_16 , L_167 ,
( V_295 & V_302 ) >>
V_303 ) ;
F_9 ( V_16 , L_168 ,
F_135 ( V_295 & V_304 ) ) ;
F_9 ( V_16 , L_169 ,
F_135 ( V_295 & V_305 ) ) ;
F_9 ( V_16 , L_170 ,
F_135 ( V_295 & V_306 ) ) ;
F_9 ( V_16 , L_171 ,
( V_295 & V_307 ) >> V_308 ) ;
F_9 ( V_16 , L_172 ,
( V_295 & V_309 ) >> V_310 ) ;
F_9 ( V_16 , L_173 , ( V_295 & V_311 ) ) ;
F_9 ( V_16 , L_174 , ( V_297 & 0x3f ) ) ;
F_9 ( V_16 , L_175 , ( ( V_297 >> 8 ) & 0x3f ) ) ;
F_9 ( V_16 , L_176 ,
F_135 ( ! ( V_296 & V_312 ) ) ) ;
F_27 ( V_16 , L_177 ) ;
switch ( V_296 & V_313 ) {
case V_314 :
F_27 ( V_16 , L_178 ) ;
break;
case V_315 :
F_27 ( V_16 , L_179 ) ;
break;
case V_316 :
F_27 ( V_16 , L_180 ) ;
break;
case V_317 :
F_27 ( V_16 , L_181 ) ;
break;
case V_318 :
F_27 ( V_16 , L_182 ) ;
break;
case V_319 :
F_27 ( V_16 , L_183 ) ;
break;
default:
F_27 ( V_16 , L_184 ) ;
break;
}
return 0 ;
}
static int F_136 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_320 * V_321 ;
int V_41 ;
F_65 ( & V_36 -> V_322 . V_323 ) ;
F_137 (fw_domain, dev_priv, i) {
F_9 ( V_16 , L_185 ,
F_138 ( V_41 ) ,
V_321 -> V_324 ) ;
}
F_73 ( & V_36 -> V_322 . V_323 ) ;
return 0 ;
}
static int F_139 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_325 , V_326 , V_327 ;
F_78 ( V_36 ) ;
V_327 = F_70 ( V_328 ) ;
V_325 = F_70 ( V_248 ) ;
V_326 = F_70 ( V_329 ) ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_186 ,
F_135 ( V_325 & V_330 ) ) ;
F_9 ( V_16 , L_187 ,
F_135 ( V_325 & V_331 ) ) ;
F_9 ( V_16 , L_168 ,
F_135 ( V_325 & V_331 ) ) ;
F_9 ( V_16 , L_169 ,
F_135 ( ( V_325 & V_332 ) ==
V_333 ) ) ;
F_9 ( V_16 , L_188 ,
F_135 ( V_326 & ( V_334 |
F_140 ( 1 ) ) ) ) ;
F_9 ( V_16 , L_189 ,
( V_327 & V_335 ) ? L_190 : L_191 ) ;
F_9 ( V_16 , L_192 ,
( V_327 & V_336 ) ? L_190 : L_191 ) ;
F_9 ( V_16 , L_193 ,
F_70 ( V_337 ) ) ;
F_9 ( V_16 , L_194 ,
F_70 ( V_338 ) ) ;
return F_136 ( V_16 , NULL ) ;
}
static int F_141 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_325 , V_339 , V_326 , V_340 = 0 ;
unsigned V_341 ;
int V_74 = 0 , V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
F_65 ( & V_36 -> V_322 . V_323 ) ;
V_341 = V_36 -> V_322 . V_321 [ V_342 ] . V_324 ;
F_73 ( & V_36 -> V_322 . V_323 ) ;
if ( V_341 ) {
F_27 ( V_16 , L_195
L_196 ) ;
} else {
while ( V_74 ++ < 50 && ( F_142 ( V_343 ) & 1 ) )
F_143 ( 10 ) ;
F_9 ( V_16 , L_197 , F_135 ( V_74 < 51 ) ) ;
}
V_339 = F_144 ( V_36 -> V_344 + V_345 ) ;
F_145 ( false , V_345 , V_339 , 4 , true ) ;
V_325 = F_70 ( V_248 ) ;
V_326 = F_70 ( V_329 ) ;
F_6 ( & V_20 -> V_76 ) ;
F_4 ( & V_36 -> V_209 . V_277 ) ;
F_146 ( V_36 , V_346 , & V_340 ) ;
F_6 ( & V_36 -> V_209 . V_277 ) ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_186 ,
F_135 ( V_325 & V_330 ) ) ;
F_9 ( V_16 , L_168 ,
F_135 ( V_325 & V_331 ) ) ;
F_9 ( V_16 , L_169 ,
F_135 ( ( V_325 & V_332 ) ==
V_333 ) ) ;
F_9 ( V_16 , L_198 ,
F_135 ( V_326 & V_347 ) ) ;
F_9 ( V_16 , L_188 ,
F_135 ( V_326 & V_348 ) ) ;
F_9 ( V_16 , L_199 ,
F_135 ( V_326 & V_349 ) ) ;
F_9 ( V_16 , L_200 ,
F_135 ( V_326 & V_350 ) ) ;
F_27 ( V_16 , L_201 ) ;
switch ( V_339 & V_351 ) {
case V_352 :
if ( V_339 & V_353 )
F_27 ( V_16 , L_202 ) ;
else
F_27 ( V_16 , L_178 ) ;
break;
case V_354 :
F_27 ( V_16 , L_203 ) ;
break;
case V_355 :
F_27 ( V_16 , L_204 ) ;
break;
case V_356 :
F_27 ( V_16 , L_205 ) ;
break;
default:
F_27 ( V_16 , L_206 ) ;
break;
}
F_9 ( V_16 , L_207 ,
F_135 ( V_339 & V_353 ) ) ;
F_9 ( V_16 , L_208 ,
F_70 ( V_357 ) ) ;
F_9 ( V_16 , L_209 ,
F_70 ( V_358 ) ) ;
F_9 ( V_16 , L_210 ,
F_70 ( V_359 ) ) ;
F_9 ( V_16 , L_211 ,
F_70 ( V_360 ) ) ;
F_9 ( V_16 , L_212 ,
F_147 ( ( ( V_340 >> 0 ) & 0xff ) ) ) ;
F_9 ( V_16 , L_213 ,
F_147 ( ( ( V_340 >> 8 ) & 0xff ) ) ) ;
F_9 ( V_16 , L_214 ,
F_147 ( ( ( V_340 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_148 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
if ( F_92 ( V_20 ) )
return F_139 ( V_16 ) ;
else if ( F_8 ( V_20 ) -> V_23 >= 6 )
return F_141 ( V_16 ) ;
else
return F_134 ( V_16 ) ;
}
static int F_149 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
F_9 ( V_16 , L_215 ,
V_36 -> V_361 . V_362 ) ;
F_9 ( V_16 , L_216 ,
V_36 -> V_361 . V_363 ) ;
return 0 ;
}
static int F_150 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_151 ( V_20 ) ) {
F_27 ( V_16 , L_217 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_4 ( & V_36 -> V_364 . V_323 ) ;
if ( F_152 ( V_36 ) )
F_27 ( V_16 , L_218 ) ;
else
F_9 ( V_16 , L_219 ,
F_153 ( V_36 -> V_364 . V_365 ) ) ;
if ( F_8 ( V_36 ) -> V_23 >= 7 )
F_9 ( V_16 , L_220 ,
F_135 ( F_70 ( V_366 ) &
V_367 ) ) ;
F_6 ( & V_36 -> V_364 . V_323 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_154 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 7 || ! F_151 ( V_20 ) )
return - V_368 ;
* V_207 = V_36 -> V_364 . V_369 ;
return 0 ;
}
static int F_155 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_370 ;
if ( F_8 ( V_20 ) -> V_23 < 7 || ! F_151 ( V_20 ) )
return - V_368 ;
F_4 ( & V_36 -> V_364 . V_323 ) ;
V_370 = F_70 ( V_371 ) ;
V_36 -> V_364 . V_369 = V_207 ;
F_156 ( V_371 , V_207 ?
( V_370 | V_372 ) :
( V_370 & ~ V_372 ) ) ;
F_6 ( & V_36 -> V_364 . V_323 ) ;
return 0 ;
}
static int F_157 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_158 ( V_20 ) ) {
F_27 ( V_16 , L_221 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_9 ( V_16 , L_222 ,
F_135 ( V_285 . V_373 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 ) {
F_27 ( V_16 , L_223 ) ;
} else {
if ( F_70 ( V_374 ) & V_375 )
F_27 ( V_16 , L_224 ) ;
else
F_27 ( V_16 , L_225 ) ;
}
F_79 ( V_36 ) ;
return 0 ;
}
static int F_159 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_376 = false ;
F_78 ( V_36 ) ;
if ( F_93 ( V_20 ) )
V_376 = F_70 ( V_377 ) & V_378 ;
else if ( F_160 ( V_20 ) || F_161 ( V_20 ) ||
F_162 ( V_20 ) || F_163 ( V_20 ) )
V_376 = F_70 ( V_379 ) & V_380 ;
else if ( F_164 ( V_20 ) )
V_376 = F_70 ( V_381 ) & V_382 ;
else if ( F_165 ( V_20 ) )
V_376 = F_70 ( V_383 ) & V_384 ;
else if ( F_92 ( V_20 ) )
V_376 = F_70 ( V_385 ) & V_386 ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_226 ,
V_376 ? L_227 : L_228 ) ;
return 0 ;
}
static int F_166 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
unsigned long V_387 , V_388 , V_389 ;
int V_75 ;
if ( ! F_116 ( V_20 ) )
return - V_368 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_387 = F_167 ( V_36 ) ;
V_388 = F_168 ( V_36 ) ;
V_389 = F_169 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_229 , V_387 ) ;
F_9 ( V_16 , L_230 , V_388 ) ;
F_9 ( V_16 , L_231 , V_389 ) ;
F_9 ( V_16 , L_232 , V_388 + V_389 ) ;
return 0 ;
}
static int F_170 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 = 0 ;
int V_390 , V_391 ;
unsigned int V_392 , V_393 ;
if ( ! F_171 ( V_20 ) ) {
F_27 ( V_16 , L_233 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_115 ( & V_36 -> V_209 . V_210 ) ;
V_75 = F_32 ( & V_36 -> V_209 . V_277 ) ;
if ( V_75 )
goto V_204;
if ( F_128 ( V_20 ) ) {
V_393 =
V_36 -> V_209 . V_394 / V_271 ;
V_392 =
V_36 -> V_209 . V_395 / V_271 ;
} else {
V_393 = V_36 -> V_209 . V_394 ;
V_392 = V_36 -> V_209 . V_395 ;
}
F_27 ( V_16 , L_234 ) ;
for ( V_390 = V_393 ; V_390 <= V_392 ; V_390 ++ ) {
V_391 = V_390 ;
F_146 ( V_36 ,
V_396 ,
& V_391 ) ;
F_9 ( V_16 , L_235 ,
F_125 ( V_36 , ( V_390 *
( F_128 ( V_20 ) ? V_271 : 1 ) ) ) ,
( ( V_391 >> 0 ) & 0xff ) * 100 ,
( ( V_391 >> 8 ) & 0xff ) * 100 ) ;
}
F_6 ( & V_36 -> V_209 . V_277 ) ;
V_204:
F_79 ( V_36 ) ;
return V_75 ;
}
static int F_172 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_397 * V_398 = & V_36 -> V_398 ;
void * V_17 = F_2 ( V_399 , V_8 ) ;
int V_75 ;
if ( V_17 == NULL )
return - V_9 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
goto V_204;
if ( V_398 -> V_400 ) {
memcpy ( V_17 , V_398 -> V_400 , V_399 ) ;
F_173 ( V_16 , V_17 , V_399 ) ;
}
F_6 ( & V_20 -> V_76 ) ;
V_204:
F_105 ( V_17 ) ;
return 0 ;
}
static int F_174 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_401 * V_402 = NULL ;
struct V_403 * V_404 ;
struct V_405 * V_406 ;
#ifdef F_175
struct V_35 * V_36 = V_20 -> V_69 ;
V_402 = V_36 -> V_407 ;
V_404 = F_176 ( V_402 -> V_408 . V_404 ) ;
F_9 ( V_16 , L_236 ,
V_404 -> V_37 . V_409 ,
V_404 -> V_37 . V_410 ,
V_404 -> V_37 . V_411 ,
V_404 -> V_37 . V_412 ,
V_404 -> V_37 . V_413 [ 0 ] ,
F_66 ( & V_404 -> V_37 . V_414 . V_414 ) ) ;
F_22 ( V_16 , V_404 -> V_25 ) ;
F_30 ( V_16 , '\n' ) ;
#endif
F_4 ( & V_20 -> V_415 . V_416 ) ;
F_177 (drm_fb, dev) {
V_404 = F_176 ( V_406 ) ;
if ( V_402 && & V_404 -> V_37 == V_402 -> V_408 . V_404 )
continue;
F_9 ( V_16 , L_237 ,
V_404 -> V_37 . V_409 ,
V_404 -> V_37 . V_410 ,
V_404 -> V_37 . V_411 ,
V_404 -> V_37 . V_412 ,
V_404 -> V_37 . V_413 [ 0 ] ,
F_66 ( & V_404 -> V_37 . V_414 . V_414 ) ) ;
F_22 ( V_16 , V_404 -> V_25 ) ;
F_30 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_415 . V_416 ) ;
return 0 ;
}
static void F_178 ( struct V_15 * V_16 ,
struct V_417 * V_418 )
{
F_9 ( V_16 , L_238 ,
V_418 -> V_419 , V_418 -> V_68 , V_418 -> V_420 ,
V_418 -> V_421 ) ;
}
static int F_179 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_62 * V_63 ;
int V_75 , V_41 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_19 (ctx, &dev_priv->context_list, link) {
if ( ! V_285 . V_422 &&
V_63 -> V_64 . V_423 == NULL )
continue;
F_27 ( V_16 , L_239 ) ;
F_29 ( V_16 , V_63 ) ;
F_24 (ring, dev_priv, i) {
if ( V_39 -> V_424 == V_63 )
F_9 ( V_16 , L_240 ,
V_39 -> V_52 ) ;
}
if ( V_285 . V_422 ) {
F_30 ( V_16 , '\n' ) ;
F_24 (ring, dev_priv, i) {
struct V_24 * V_425 =
V_63 -> V_426 [ V_41 ] . V_427 ;
struct V_417 * V_418 =
V_63 -> V_426 [ V_41 ] . V_418 ;
F_9 ( V_16 , L_241 , V_39 -> V_52 ) ;
if ( V_425 )
F_22 ( V_16 , V_425 ) ;
if ( V_418 )
F_178 ( V_16 , V_418 ) ;
F_30 ( V_16 , '\n' ) ;
}
} else {
F_22 ( V_16 , V_63 -> V_64 . V_423 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static void F_180 ( struct V_15 * V_16 ,
struct V_38 * V_39 ,
struct V_24 * V_425 )
{
struct V_428 * V_428 ;
T_10 * V_429 ;
int V_102 ;
unsigned long V_430 = 0 ;
if ( V_425 == NULL ) {
F_9 ( V_16 , L_242 ,
V_39 -> V_52 ) ;
return;
}
F_9 ( V_16 , L_243 , V_39 -> V_52 ,
F_181 ( V_425 ) ) ;
if ( ! F_44 ( V_425 ) )
F_27 ( V_16 , L_244 ) ;
else
V_430 = F_182 ( V_425 ) ;
if ( F_183 ( V_425 ) ) {
F_27 ( V_16 , L_245 ) ;
return;
}
V_428 = F_184 ( V_425 , V_431 ) ;
if ( ! F_185 ( V_428 == NULL ) ) {
V_429 = F_186 ( V_428 ) ;
for ( V_102 = 0 ; V_102 < 0x600 / sizeof( T_4 ) / 4 ; V_102 += 4 ) {
F_9 ( V_16 , L_246 ,
V_430 + 4096 + ( V_102 * 4 ) ,
V_429 [ V_102 ] , V_429 [ V_102 + 1 ] ,
V_429 [ V_102 + 2 ] , V_429 [ V_102 + 3 ] ) ;
}
F_187 ( V_429 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
static int F_188 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_62 * V_63 ;
int V_75 , V_41 ;
if ( ! V_285 . V_422 ) {
F_9 ( V_16 , L_247 ) ;
return 0 ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_19 (ctx, &dev_priv->context_list, link) {
F_24 (ring, dev_priv, i) {
if ( V_39 -> V_424 != V_63 )
F_180 ( V_16 , V_39 ,
V_63 -> V_426 [ V_41 ] . V_427 ) ;
}
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_189 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
T_4 V_432 ;
T_11 V_433 ;
T_11 V_434 ;
T_4 V_435 ;
T_4 V_436 ;
struct V_67 * V_437 ;
int V_438 , V_41 ;
int V_75 ;
if ( ! V_285 . V_422 ) {
F_27 ( V_16 , L_247 ) ;
return 0 ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
F_24 (ring, dev_priv, ring_id) {
struct V_145 * V_439 = NULL ;
int V_74 = 0 ;
unsigned long V_440 ;
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
V_435 = F_70 ( F_190 ( V_39 ) ) ;
V_436 = F_70 ( F_191 ( V_39 ) ) ;
F_9 ( V_16 , L_249 ,
V_435 , V_436 ) ;
V_432 = F_70 ( F_192 ( V_39 ) ) ;
F_9 ( V_16 , L_250 , V_432 ) ;
V_433 = V_39 -> V_441 ;
V_434 = V_432 & 0x07 ;
if ( V_433 > V_434 )
V_434 += 6 ;
F_9 ( V_16 , L_251 ,
V_433 , V_434 ) ;
for ( V_41 = 0 ; V_41 < 6 ; V_41 ++ ) {
V_435 = F_70 ( F_193 ( V_39 , V_41 ) ) ;
V_436 = F_70 ( F_194 ( V_39 , V_41 ) ) ;
F_9 ( V_16 , L_252 ,
V_41 , V_435 , V_436 ) ;
}
F_195 ( & V_39 -> V_442 , V_440 ) ;
F_196 (cursor, &ring->execlist_queue)
V_74 ++ ;
V_439 = F_197 ( & V_39 -> V_443 ,
struct V_145 , V_444 ) ;
F_198 ( & V_39 -> V_442 , V_440 ) ;
F_9 ( V_16 , L_253 , V_74 ) ;
if ( V_439 ) {
struct V_24 * V_425 ;
V_425 = V_439 -> V_63 -> V_426 [ V_438 ] . V_427 ;
F_9 ( V_16 , L_254 ,
F_181 ( V_425 ) ) ;
F_9 ( V_16 , L_255 ,
V_439 -> V_420 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static const char * F_199 ( unsigned V_445 )
{
switch ( V_445 ) {
case V_446 :
return L_256 ;
case V_447 :
return L_257 ;
case V_448 :
return L_258 ;
case V_449 :
return L_259 ;
case V_450 :
return L_260 ;
case V_451 :
return L_261 ;
case V_452 :
return L_262 ;
case V_453 :
return L_263 ;
}
return L_264 ;
}
static int F_200 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
F_9 ( V_16 , L_265 ,
F_199 ( V_36 -> V_111 . V_454 ) ) ;
F_9 ( V_16 , L_266 ,
F_199 ( V_36 -> V_111 . V_455 ) ) ;
if ( F_201 ( V_20 ) || F_202 ( V_20 ) ) {
F_9 ( V_16 , L_267 ,
F_70 ( V_456 ) ) ;
F_9 ( V_16 , L_268 ,
F_70 ( V_457 ) ) ;
F_9 ( V_16 , L_269 ,
F_117 ( V_458 ) ) ;
F_9 ( V_16 , L_270 ,
F_117 ( V_459 ) ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
F_9 ( V_16 , L_271 ,
F_70 ( V_460 ) ) ;
F_9 ( V_16 , L_272 ,
F_70 ( V_461 ) ) ;
F_9 ( V_16 , L_273 ,
F_70 ( V_462 ) ) ;
F_9 ( V_16 , L_274 ,
F_70 ( V_463 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 )
F_9 ( V_16 , L_275 ,
F_70 ( V_464 ) ) ;
else
F_9 ( V_16 , L_276 ,
F_70 ( V_465 ) ) ;
F_9 ( V_16 , L_277 ,
F_70 ( V_466 ) ) ;
}
if ( V_36 -> V_467 & V_468 )
F_27 ( V_16 , L_278 ) ;
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_203 ( int V_88 , void * V_89 , void * V_17 )
{
struct V_62 * V_63 = V_89 ;
struct V_15 * V_16 = V_17 ;
struct V_95 * V_96 = V_63 -> V_96 ;
if ( ! V_96 ) {
F_9 ( V_16 , L_279 ,
V_63 -> V_469 ) ;
return 0 ;
}
if ( F_204 ( V_63 ) )
F_27 ( V_16 , L_280 ) ;
else
F_9 ( V_16 , L_281 , V_63 -> V_469 ) ;
V_96 -> V_470 ( V_96 , V_16 ) ;
return 0 ;
}
static void F_205 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_95 * V_96 = V_36 -> V_111 . V_471 ;
int V_208 , V_41 ;
if ( ! V_96 )
return;
F_24 (ring, dev_priv, unused) {
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
T_2 V_472 = F_70 ( F_206 ( V_39 , V_41 ) ) ;
V_472 <<= 32 ;
V_472 |= F_70 ( F_207 ( V_39 , V_41 ) ) ;
F_9 ( V_16 , L_282 , V_41 , V_472 ) ;
}
}
}
static void F_208 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_41 ;
if ( F_8 ( V_20 ) -> V_23 == 6 )
F_9 ( V_16 , L_283 , F_70 ( V_473 ) ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
if ( F_8 ( V_20 ) -> V_23 == 7 )
F_9 ( V_16 , L_283 , F_70 ( F_209 ( V_39 ) ) ) ;
F_9 ( V_16 , L_284 , F_70 ( F_210 ( V_39 ) ) ) ;
F_9 ( V_16 , L_285 , F_70 ( F_211 ( V_39 ) ) ) ;
F_9 ( V_16 , L_286 , F_70 ( F_212 ( V_39 ) ) ) ;
}
if ( V_36 -> V_111 . V_471 ) {
struct V_95 * V_96 = V_36 -> V_111 . V_471 ;
F_27 ( V_16 , L_287 ) ;
F_9 ( V_16 , L_288 , V_96 -> V_474 . V_37 . V_430 ) ;
V_96 -> V_470 ( V_96 , V_16 ) ;
}
F_9 ( V_16 , L_289 , F_70 ( V_475 ) ) ;
}
static int F_213 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_109 * V_110 ;
int V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 )
F_205 ( V_16 , V_20 ) ;
else if ( F_8 ( V_20 ) -> V_23 >= 6 )
F_208 ( V_16 , V_20 ) ;
F_52 (file, &dev->filelist, lhead) {
struct V_476 * V_98 = V_110 -> V_119 ;
struct V_117 * V_118 ;
V_118 = F_214 ( V_110 -> V_122 , V_123 ) ;
if ( ! V_118 ) {
V_75 = - V_477 ;
goto V_478;
}
F_9 ( V_16 , L_290 , V_118 -> V_124 ) ;
F_215 ( V_118 ) ;
F_54 ( & V_98 -> V_479 , F_203 ,
( void * ) ( unsigned long ) V_16 ) ;
}
V_478:
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return V_75 ;
}
static int F_216 ( struct V_35 * V_285 )
{
struct V_38 * V_39 ;
int V_74 = 0 ;
int V_41 ;
F_24 (ring, i915, i)
V_74 += V_39 -> V_480 ;
return V_74 ;
}
static int F_217 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_109 * V_110 ;
F_9 ( V_16 , L_291 , V_36 -> V_209 . V_481 ) ;
F_9 ( V_16 , L_292 , V_36 -> V_111 . V_482 ) ;
F_9 ( V_16 , L_293 , F_216 ( V_36 ) ) ;
F_9 ( V_16 , L_294 ,
F_125 ( V_36 , V_36 -> V_209 . V_272 ) ,
F_125 ( V_36 , V_36 -> V_209 . V_274 ) ,
F_125 ( V_36 , V_36 -> V_209 . V_394 ) ,
F_125 ( V_36 , V_36 -> V_209 . V_395 ) ,
F_125 ( V_36 , V_36 -> V_209 . V_239 ) ) ;
F_53 ( & V_36 -> V_209 . V_483 ) ;
F_52 (file, &dev->filelist, lhead) {
struct V_476 * V_98 = V_110 -> V_119 ;
struct V_117 * V_118 ;
F_56 () ;
V_118 = F_57 ( V_110 -> V_122 , V_123 ) ;
F_9 ( V_16 , L_295 ,
V_118 ? V_118 -> V_124 : L_43 ,
V_118 ? V_118 -> V_122 : - 1 ,
V_98 -> V_209 . V_484 ,
F_38 ( & V_98 -> V_209 . V_485 ) ? L_13 : L_296 ) ;
F_58 () ;
}
F_9 ( V_16 , L_297 ,
V_36 -> V_209 . V_486 . V_484 ,
F_38 ( & V_36 -> V_209 . V_486 . V_485 ) ? L_13 : L_296 ) ;
F_9 ( V_16 , L_298 ,
V_36 -> V_209 . V_487 . V_484 ,
F_38 ( & V_36 -> V_209 . V_487 . V_485 ) ? L_13 : L_296 ) ;
F_9 ( V_16 , L_299 , V_36 -> V_209 . V_484 ) ;
F_55 ( & V_36 -> V_209 . V_483 ) ;
return 0 ;
}
static int F_218 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
F_9 ( V_16 , L_300 , F_135 ( F_219 ( V_20 ) ) ) ;
F_9 ( V_16 , L_301 , V_36 -> V_488 ) ;
return 0 ;
}
static int F_220 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_35 * V_36 = V_7 -> V_2 -> V_20 -> V_69 ;
struct V_489 * V_490 = & V_36 -> V_491 . V_490 ;
T_4 V_492 , V_41 ;
if ( ! F_221 ( V_36 -> V_20 ) )
return 0 ;
F_9 ( V_16 , L_302 ) ;
F_9 ( V_16 , L_303 ,
V_490 -> V_493 ) ;
F_9 ( V_16 , L_304 ,
F_222 ( V_490 -> V_494 ) ) ;
F_9 ( V_16 , L_305 ,
F_222 ( V_490 -> V_495 ) ) ;
F_9 ( V_16 , L_306 ,
V_490 -> V_496 , V_490 -> V_497 ) ;
F_9 ( V_16 , L_307 ,
V_490 -> V_498 , V_490 -> V_499 ) ;
V_492 = F_70 ( V_500 ) ;
F_9 ( V_16 , L_308 , V_492 ) ;
F_9 ( V_16 , L_309 ,
( V_492 & V_501 ) >> V_502 ) ;
F_9 ( V_16 , L_310 ,
( V_492 & V_503 ) >> V_504 ) ;
F_9 ( V_16 , L_311 ,
( V_492 & V_505 ) >> V_506 ) ;
F_27 ( V_16 , L_312 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
F_9 ( V_16 , L_313 , V_41 , F_70 ( F_223 ( V_41 ) ) ) ;
return 0 ;
}
static void F_224 ( struct V_15 * V_16 ,
struct V_35 * V_36 ,
struct V_507 * V_508 )
{
struct V_38 * V_39 ;
T_12 V_509 = 0 ;
T_10 V_41 ;
F_9 ( V_16 , L_314 ,
V_508 -> V_510 , V_508 -> V_511 , V_508 -> V_512 ) ;
F_9 ( V_16 , L_315 ,
V_508 -> V_513 , V_508 -> V_514 , V_508 -> V_515 ) ;
F_9 ( V_16 , L_316 ,
V_508 -> V_516 , V_508 -> V_517 , V_508 -> V_518 ) ;
F_9 ( V_16 , L_317 , V_508 -> V_519 ) ;
F_9 ( V_16 , L_318 , V_508 -> V_520 ) ;
F_9 ( V_16 , L_319 , V_508 -> V_521 ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_320 ,
V_508 -> V_522 [ V_41 ] ,
V_39 -> V_52 ) ;
V_509 += V_508 -> V_522 [ V_41 ] ;
}
F_9 ( V_16 , L_321 , V_509 ) ;
}
static int F_225 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_523 V_491 ;
struct V_507 V_508 = {} ;
struct V_38 * V_39 ;
enum V_524 V_41 ;
T_2 V_92 = 0 ;
if ( ! F_226 ( V_36 -> V_20 ) )
return 0 ;
F_53 ( & V_36 -> V_491 . V_525 ) ;
V_491 = V_36 -> V_491 ;
if ( V_491 . V_526 ) {
F_53 ( & V_491 . V_526 -> V_527 ) ;
V_508 = * V_491 . V_526 ;
F_55 ( & V_491 . V_526 -> V_527 ) ;
}
F_55 ( & V_36 -> V_491 . V_525 ) ;
F_9 ( V_16 , L_322 , V_491 . V_528 ) ;
F_9 ( V_16 , L_323 , V_491 . V_529 ) ;
F_9 ( V_16 , L_324 , V_491 . V_530 ) ;
F_9 ( V_16 , L_325 , V_491 . V_531 ) ;
F_9 ( V_16 , L_326 , V_491 . V_532 ) ;
F_9 ( V_16 , L_327 ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_328 ,
V_39 -> V_52 , V_491 . V_522 [ V_41 ] ,
V_491 . V_533 [ V_41 ] , V_491 . V_533 [ V_41 ] ) ;
V_92 += V_491 . V_522 [ V_41 ] ;
}
F_9 ( V_16 , L_329 , L_330 , V_92 ) ;
F_9 ( V_16 , L_331 , V_491 . V_526 ) ;
F_224 ( V_16 , V_36 , & V_508 ) ;
return 0 ;
}
static int F_227 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_534 = V_36 -> V_491 . V_534 ;
T_4 * log ;
int V_41 = 0 , V_535 ;
if ( ! V_534 )
return 0 ;
for ( V_535 = 0 ; V_535 < V_534 -> V_37 . V_31 / V_536 ; V_535 ++ ) {
log = F_186 ( F_184 ( V_534 , V_535 ) ) ;
for ( V_41 = 0 ; V_41 < V_536 / sizeof( T_4 ) ; V_41 += 4 )
F_9 ( V_16 , L_332 ,
* ( log + V_41 ) , * ( log + V_41 + 1 ) ,
* ( log + V_41 + 2 ) , * ( log + V_41 + 3 ) ) ;
F_187 ( log ) ;
}
F_30 ( V_16 , '\n' ) ;
return 0 ;
}
static int F_228 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_537 = 0 ;
T_4 V_538 [ 3 ] ;
enum V_128 V_128 ;
bool V_481 = false ;
if ( ! F_229 ( V_20 ) ) {
F_27 ( V_16 , L_333 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_4 ( & V_36 -> V_539 . V_323 ) ;
F_9 ( V_16 , L_334 , F_135 ( V_36 -> V_539 . V_540 ) ) ;
F_9 ( V_16 , L_335 , F_135 ( V_36 -> V_539 . V_541 ) ) ;
F_9 ( V_16 , L_336 , F_135 ( ( bool ) V_36 -> V_539 . V_481 ) ) ;
F_9 ( V_16 , L_337 , F_135 ( V_36 -> V_539 . V_42 ) ) ;
F_9 ( V_16 , L_338 ,
V_36 -> V_539 . V_542 ) ;
F_9 ( V_16 , L_339 ,
F_135 ( F_230 ( & V_36 -> V_539 . V_131 . V_131 ) ) ) ;
if ( F_231 ( V_20 ) )
V_481 = F_70 ( F_232 ( V_20 ) ) & V_543 ;
else {
F_82 (dev_priv, pipe) {
V_538 [ V_128 ] = F_70 ( F_233 ( V_128 ) ) &
V_544 ;
if ( ( V_538 [ V_128 ] == V_545 ) ||
( V_538 [ V_128 ] == V_546 ) )
V_481 = true ;
}
}
F_9 ( V_16 , L_340 , F_135 ( V_481 ) ) ;
if ( ! F_231 ( V_20 ) )
F_82 (dev_priv, pipe) {
if ( ( V_538 [ V_128 ] == V_545 ) ||
( V_538 [ V_128 ] == V_546 ) )
F_9 ( V_16 , L_341 , F_63 ( V_128 ) ) ;
}
F_27 ( V_16 , L_30 ) ;
if ( F_231 ( V_20 ) ) {
V_537 = F_70 ( F_234 ( V_20 ) ) &
V_547 ;
F_9 ( V_16 , L_342 , V_537 ) ;
}
F_6 ( & V_36 -> V_539 . V_323 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_235 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_548 * V_549 ;
struct V_550 * V_551 ;
struct V_552 * V_552 = NULL ;
int V_75 ;
T_11 V_553 [ 6 ] ;
F_236 ( V_20 ) ;
F_237 (dev, connector) {
if ( V_551 -> V_37 . V_554 != V_555 )
continue;
if ( ! V_551 -> V_37 . V_549 )
continue;
V_549 = F_238 ( V_551 -> V_37 . V_549 ) ;
if ( V_549 -> type != V_556 )
continue;
V_552 = F_239 ( & V_549 -> V_37 ) ;
V_75 = F_240 ( V_552 , V_553 ) ;
if ( V_75 )
goto V_204;
F_9 ( V_16 , L_343 ,
V_553 [ 0 ] , V_553 [ 1 ] , V_553 [ 2 ] ,
V_553 [ 3 ] , V_553 [ 4 ] , V_553 [ 5 ] ) ;
goto V_204;
}
V_75 = - V_368 ;
V_204:
F_241 ( V_20 ) ;
return V_75 ;
}
static int F_242 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_2 V_557 ;
T_4 V_558 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_368 ;
F_78 ( V_36 ) ;
F_243 ( V_559 , V_557 ) ;
V_557 = ( V_557 & 0x1f00 ) >> 8 ;
V_558 = 1000000 / ( 1 << V_557 ) ;
V_557 = F_70 ( V_560 ) ;
V_557 *= V_558 ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_344 , ( long long unsigned ) V_557 ) ;
return 0 ;
}
static int F_244 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_245 ( V_20 ) ) {
F_27 ( V_16 , L_221 ) ;
return 0 ;
}
F_9 ( V_16 , L_345 , F_135 ( ! V_36 -> V_111 . V_482 ) ) ;
F_9 ( V_16 , L_346 ,
F_135 ( ! F_246 ( V_36 ) ) ) ;
#ifdef F_247
F_9 ( V_16 , L_347 ,
F_66 ( & V_20 -> V_20 -> V_557 . V_561 ) ) ;
#else
F_9 ( V_16 , L_348 ) ;
#endif
return 0 ;
}
static const char * F_248 ( enum V_562 V_563 )
{
switch ( V_563 ) {
case V_564 :
return L_349 ;
case V_565 :
return L_350 ;
case V_566 :
return L_351 ;
case V_567 :
return L_352 ;
case V_568 :
return L_353 ;
case V_569 :
return L_354 ;
case V_570 :
return L_355 ;
case V_571 :
return L_356 ;
case V_572 :
return L_357 ;
case V_573 :
return L_358 ;
case V_574 :
return L_359 ;
case V_575 :
return L_360 ;
case V_576 :
return L_361 ;
case V_577 :
return L_362 ;
case V_578 :
return L_363 ;
case V_579 :
return L_364 ;
case V_580 :
return L_365 ;
case V_581 :
return L_366 ;
case V_582 :
return L_367 ;
case V_583 :
return L_368 ;
case V_584 :
return L_369 ;
case V_585 :
return L_370 ;
case V_586 :
return L_371 ;
case V_587 :
return L_372 ;
case V_588 :
return L_373 ;
case V_589 :
return L_374 ;
case V_590 :
return L_375 ;
case V_591 :
return L_376 ;
case V_592 :
return L_377 ;
case V_593 :
return L_378 ;
case V_594 :
return L_379 ;
default:
F_249 ( V_563 ) ;
return L_380 ;
}
}
static int F_250 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_595 * V_596 = & V_36 -> V_596 ;
int V_41 ;
F_4 ( & V_596 -> V_323 ) ;
F_9 ( V_16 , L_381 , L_382 , L_383 ) ;
for ( V_41 = 0 ; V_41 < V_596 -> V_597 ; V_41 ++ ) {
struct V_598 * V_599 ;
enum V_562 V_600 ;
V_599 = & V_596 -> V_601 [ V_41 ] ;
F_9 ( V_16 , L_384 , V_599 -> V_52 ,
V_599 -> V_74 ) ;
for ( V_600 = 0 ; V_600 < V_602 ;
V_600 ++ ) {
if ( ! ( F_251 ( V_600 ) & V_599 -> V_603 ) )
continue;
F_9 ( V_16 , L_385 ,
F_248 ( V_600 ) ,
V_596 -> V_604 [ V_600 ] ) ;
}
}
F_6 ( & V_596 -> V_323 ) ;
return 0 ;
}
static void F_252 ( struct V_15 * V_16 , int V_605 ,
struct V_606 * V_607 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_605 ; V_41 ++ )
F_30 ( V_16 , '\t' ) ;
F_9 ( V_16 , L_386 ,
V_607 -> V_37 . V_88 , V_607 -> V_52 ,
V_607 -> V_608 , V_607 -> clock ,
V_607 -> V_609 , V_607 -> V_610 ,
V_607 -> V_611 , V_607 -> V_612 ,
V_607 -> V_613 , V_607 -> V_614 ,
V_607 -> V_615 , V_607 -> V_616 ,
V_607 -> type , V_607 -> V_440 ) ;
}
static void F_253 ( struct V_15 * V_16 ,
struct V_126 * V_126 ,
struct V_548 * V_548 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_617 * V_127 = & V_126 -> V_37 ;
struct V_550 * V_550 ;
struct V_618 * V_549 ;
V_549 = & V_548 -> V_37 ;
F_9 ( V_16 , L_387 ,
V_549 -> V_37 . V_88 , V_549 -> V_52 ) ;
F_254 (dev, encoder, intel_connector) {
struct V_619 * V_551 = & V_550 -> V_37 ;
F_9 ( V_16 , L_388 ,
V_551 -> V_37 . V_88 ,
V_551 -> V_52 ,
F_255 ( V_551 -> V_435 ) ) ;
if ( V_551 -> V_435 == V_620 ) {
struct V_606 * V_607 = & V_127 -> V_607 ;
F_9 ( V_16 , L_389 ) ;
F_252 ( V_16 , 2 , V_607 ) ;
} else {
F_30 ( V_16 , '\n' ) ;
}
}
}
static void F_256 ( struct V_15 * V_16 , struct V_126 * V_126 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_617 * V_127 = & V_126 -> V_37 ;
struct V_548 * V_548 ;
struct V_621 * V_622 = V_127 -> V_623 -> V_427 ;
struct V_405 * V_404 = V_622 -> V_404 ;
if ( V_404 )
F_9 ( V_16 , L_390 ,
V_404 -> V_37 . V_88 , V_622 -> V_624 >> 16 ,
V_622 -> V_625 >> 16 , V_404 -> V_409 , V_404 -> V_410 ) ;
else
F_27 ( V_16 , L_391 ) ;
F_257 (dev, crtc, intel_encoder)
F_253 ( V_16 , V_126 , V_548 ) ;
}
static void F_258 ( struct V_15 * V_16 , struct V_626 * V_627 )
{
struct V_606 * V_607 = V_627 -> V_628 ;
F_9 ( V_16 , L_392 ) ;
F_252 ( V_16 , 2 , V_607 ) ;
}
static void F_259 ( struct V_15 * V_16 ,
struct V_550 * V_550 )
{
struct V_548 * V_548 = V_550 -> V_549 ;
struct V_552 * V_552 = F_239 ( & V_548 -> V_37 ) ;
F_9 ( V_16 , L_393 , V_552 -> V_629 [ V_630 ] ) ;
F_9 ( V_16 , L_394 , F_135 ( V_552 -> V_631 ) ) ;
if ( V_548 -> type == V_556 )
F_258 ( V_16 , & V_550 -> V_627 ) ;
}
static void F_260 ( struct V_15 * V_16 ,
struct V_550 * V_550 )
{
struct V_548 * V_548 = V_550 -> V_549 ;
struct V_632 * V_632 = F_261 ( & V_548 -> V_37 ) ;
F_9 ( V_16 , L_394 , F_135 ( V_632 -> V_631 ) ) ;
}
static void F_262 ( struct V_15 * V_16 ,
struct V_550 * V_550 )
{
F_258 ( V_16 , & V_550 -> V_627 ) ;
}
static void F_263 ( struct V_15 * V_16 ,
struct V_619 * V_551 )
{
struct V_550 * V_550 = F_264 ( V_551 ) ;
struct V_548 * V_548 = V_550 -> V_549 ;
struct V_606 * V_607 ;
F_9 ( V_16 , L_395 ,
V_551 -> V_37 . V_88 , V_551 -> V_52 ,
F_255 ( V_551 -> V_435 ) ) ;
if ( V_551 -> V_435 == V_620 ) {
F_9 ( V_16 , L_396 , V_551 -> V_633 . V_52 ) ;
F_9 ( V_16 , L_397 ,
V_551 -> V_633 . V_634 ,
V_551 -> V_633 . V_635 ) ;
F_9 ( V_16 , L_398 ,
F_265 ( V_551 -> V_633 . V_636 ) ) ;
F_9 ( V_16 , L_399 ,
V_551 -> V_633 . V_637 ) ;
}
if ( V_548 ) {
if ( V_548 -> type == V_638 ||
V_548 -> type == V_556 )
F_259 ( V_16 , V_550 ) ;
else if ( V_548 -> type == V_639 )
F_260 ( V_16 , V_550 ) ;
else if ( V_548 -> type == V_640 )
F_262 ( V_16 , V_550 ) ;
}
F_9 ( V_16 , L_400 ) ;
F_19 (mode, &connector->modes, head)
F_252 ( V_16 , 2 , V_607 ) ;
}
static bool F_266 ( struct V_19 * V_20 , int V_128 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_427 ;
if ( F_267 ( V_20 ) || F_268 ( V_20 ) )
V_427 = F_70 ( F_269 ( V_641 ) ) & V_642 ;
else
V_427 = F_70 ( F_269 ( V_128 ) ) & V_643 ;
return V_427 ;
}
static bool F_270 ( struct V_19 * V_20 , int V_128 , int * T_1 , int * V_644 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_199 ;
V_199 = F_70 ( F_271 ( V_128 ) ) ;
* T_1 = ( V_199 >> V_645 ) & V_646 ;
if ( V_199 & ( V_647 << V_645 ) )
* T_1 = - * T_1 ;
* V_644 = ( V_199 >> V_648 ) & V_646 ;
if ( V_199 & ( V_647 << V_648 ) )
* V_644 = - * V_644 ;
return F_266 ( V_20 , V_128 ) ;
}
static int F_272 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_126 * V_127 ;
struct V_619 * V_551 ;
F_78 ( V_36 ) ;
F_236 ( V_20 ) ;
F_9 ( V_16 , L_401 ) ;
F_9 ( V_16 , L_402 ) ;
F_62 (dev, crtc) {
bool V_42 ;
struct V_649 * V_650 ;
int T_1 , V_644 ;
V_650 = F_273 ( V_127 -> V_37 . V_427 ) ;
F_9 ( V_16 , L_403 ,
V_127 -> V_37 . V_37 . V_88 , F_63 ( V_127 -> V_128 ) ,
F_135 ( V_650 -> V_37 . V_42 ) ,
V_650 -> V_651 , V_650 -> V_652 ) ;
if ( V_650 -> V_37 . V_42 ) {
F_256 ( V_16 , V_127 ) ;
V_42 = F_270 ( V_20 , V_127 -> V_128 , & T_1 , & V_644 ) ;
F_9 ( V_16 , L_404 ,
F_135 ( V_127 -> V_653 ) ,
T_1 , V_644 , V_127 -> V_37 . V_437 -> V_427 -> V_654 ,
V_127 -> V_37 . V_437 -> V_427 -> V_655 ,
V_127 -> V_656 , F_135 ( V_42 ) ) ;
}
F_9 ( V_16 , L_405 ,
F_135 ( ! V_127 -> V_657 ) ,
F_135 ( ! V_127 -> V_658 ) ) ;
}
F_9 ( V_16 , L_30 ) ;
F_9 ( V_16 , L_406 ) ;
F_9 ( V_16 , L_407 ) ;
F_19 (connector, &dev->mode_config.connector_list, head) {
F_263 ( V_16 , V_551 ) ;
}
F_241 ( V_20 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_274 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_659 = F_275 ( F_8 ( V_20 ) -> V_660 ) ;
int V_41 , V_102 , V_75 ;
if ( ! F_276 ( V_20 ) ) {
F_27 ( V_16 , L_408 ) ;
return 0 ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
if ( F_120 ( V_20 ) ) {
struct V_428 * V_428 ;
T_12 * V_148 ;
V_428 = F_184 ( V_36 -> V_661 , 0 ) ;
V_148 = ( T_12 * ) F_186 ( V_428 ) ;
F_24 (ring, dev_priv, i) {
T_12 V_662 ;
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
F_27 ( V_16 , L_409 ) ;
for ( V_102 = 0 ; V_102 < V_659 ; V_102 ++ ) {
V_662 = V_41 * V_284 + V_102 ;
F_9 ( V_16 , L_410 ,
V_148 [ V_662 ] , V_662 * 8 ) ;
}
F_30 ( V_16 , '\n' ) ;
F_27 ( V_16 , L_411 ) ;
for ( V_102 = 0 ; V_102 < V_659 ; V_102 ++ ) {
V_662 = V_41 + ( V_102 * V_284 ) ;
F_9 ( V_16 , L_410 ,
V_148 [ V_662 ] , V_662 * 8 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_187 ( V_148 ) ;
} else {
F_27 ( V_16 , L_409 ) ;
F_24 (ring, dev_priv, i)
for ( V_102 = 0 ; V_102 < V_659 ; V_102 ++ )
F_9 ( V_16 , L_412 ,
F_70 ( V_39 -> V_663 . V_664 . signal [ V_102 ] ) ) ;
F_30 ( V_16 , '\n' ) ;
}
F_27 ( V_16 , L_413 ) ;
F_24 (ring, dev_priv, i) {
for ( V_102 = 0 ; V_102 < V_659 ; V_102 ++ ) {
F_9 ( V_16 , L_414 , V_39 -> V_663 . V_665 [ V_102 ] ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_30 ( V_16 , '\n' ) ;
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_277 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 ;
F_236 ( V_20 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_666 ; V_41 ++ ) {
struct V_667 * V_668 = & V_36 -> V_669 [ V_41 ] ;
F_9 ( V_16 , L_415 , V_41 , V_668 -> V_52 , V_668 -> V_88 ) ;
F_9 ( V_16 , L_416 ,
V_668 -> V_670 . V_671 , V_668 -> V_42 , F_135 ( V_668 -> V_672 ) ) ;
F_9 ( V_16 , L_417 ) ;
F_9 ( V_16 , L_418 , V_668 -> V_670 . V_673 . V_674 ) ;
F_9 ( V_16 , L_419 ,
V_668 -> V_670 . V_673 . V_675 ) ;
F_9 ( V_16 , L_420 , V_668 -> V_670 . V_673 . V_676 ) ;
F_9 ( V_16 , L_421 , V_668 -> V_670 . V_673 . V_677 ) ;
F_9 ( V_16 , L_422 , V_668 -> V_670 . V_673 . V_678 ) ;
}
F_241 ( V_20 ) ;
return 0 ;
}
static int F_278 ( struct V_15 * V_16 , void * V_208 )
{
int V_41 ;
int V_75 ;
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
F_9 ( V_16 , L_423 , V_36 -> V_679 . V_74 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_679 . V_74 ; ++ V_41 ) {
T_4 V_134 , V_680 , V_681 , V_682 ;
bool V_683 ;
V_134 = V_36 -> V_679 . V_370 [ V_41 ] . V_134 ;
V_680 = V_36 -> V_679 . V_370 [ V_41 ] . V_680 ;
V_681 = V_36 -> V_679 . V_370 [ V_41 ] . V_681 ;
V_682 = F_70 ( V_134 ) ;
V_683 = ( V_681 & V_680 ) == ( V_682 & V_680 ) ;
F_9 ( V_16 , L_424 ,
V_134 , V_681 , V_680 , V_682 , V_683 ? L_425 : L_426 ) ;
}
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_279 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_684 * V_685 ;
struct V_686 * V_687 ;
enum V_128 V_128 ;
int V_129 ;
if ( F_8 ( V_20 ) -> V_23 < 9 )
return 0 ;
F_236 ( V_20 ) ;
V_685 = & V_36 -> V_688 . V_689 . V_685 ;
F_9 ( V_16 , L_427 , L_13 , L_428 , L_429 , L_430 ) ;
F_82 (dev_priv, pipe) {
F_9 ( V_16 , L_431 , F_63 ( V_128 ) ) ;
F_280 (dev_priv, pipe, plane) {
V_687 = & V_685 -> V_129 [ V_128 ] [ V_129 ] ;
F_9 ( V_16 , L_432 , V_129 + 1 ,
V_687 -> V_55 , V_687 -> V_690 ,
F_281 ( V_687 ) ) ;
}
V_687 = & V_685 -> V_129 [ V_128 ] [ V_691 ] ;
F_9 ( V_16 , L_433 , L_434 , V_687 -> V_55 ,
V_687 -> V_690 , F_281 ( V_687 ) ) ;
}
F_241 ( V_20 ) ;
return 0 ;
}
static void F_282 ( struct V_15 * V_16 ,
struct V_19 * V_20 , struct V_126 * V_126 )
{
struct V_548 * V_548 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_692 * V_693 = & V_36 -> V_693 ;
int V_608 = 0 ;
F_257 (dev, &intel_crtc->base, intel_encoder) {
switch ( V_548 -> type ) {
case V_556 :
F_27 ( V_16 , L_435 ) ;
break;
case V_694 :
F_27 ( V_16 , L_436 ) ;
break;
case V_639 :
F_27 ( V_16 , L_437 ) ;
break;
case V_638 :
F_27 ( V_16 , L_438 ) ;
break;
default:
F_9 ( V_16 , L_439 ,
V_548 -> type ) ;
return;
}
}
if ( V_36 -> V_695 . V_696 == V_697 )
F_27 ( V_16 , L_440 ) ;
else if ( V_36 -> V_695 . V_696 == V_698 )
F_27 ( V_16 , L_441 ) ;
else if ( V_36 -> V_695 . V_696 == V_699 )
F_27 ( V_16 , L_442 ) ;
else
F_27 ( V_16 , L_443 ) ;
F_27 ( V_16 , L_444 ) ;
if ( F_273 ( V_126 -> V_37 . V_427 ) -> V_700 ) {
struct V_626 * V_627 ;
F_4 ( & V_693 -> V_701 ) ;
F_27 ( V_16 , L_445 ) ;
if ( ! V_693 -> V_702 ) {
F_27 ( V_16 , L_446 ) ;
F_6 ( & V_693 -> V_701 ) ;
return;
}
V_627 = & V_693 -> V_702 -> V_703 -> V_627 ;
F_9 ( V_16 , L_447 ,
V_693 -> V_542 ) ;
F_27 ( V_16 , L_448 ) ;
if ( V_693 -> V_704 == V_705 ) {
F_27 ( V_16 , L_449 ) ;
V_608 = V_627 -> V_628 -> V_608 ;
} else if ( V_693 -> V_704 == V_706 ) {
F_27 ( V_16 , L_450 ) ;
V_608 = V_627 -> V_707 -> V_608 ;
} else {
F_9 ( V_16 , L_451 ,
V_693 -> V_704 ) ;
F_6 ( & V_693 -> V_701 ) ;
return;
}
F_9 ( V_16 , L_452 , V_608 ) ;
F_27 ( V_16 , L_448 ) ;
F_6 ( & V_693 -> V_701 ) ;
} else {
F_27 ( V_16 , L_453 ) ;
}
F_27 ( V_16 , L_30 ) ;
}
static int F_283 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_126 * V_126 ;
int V_708 = 0 ;
F_62 (dev, intel_crtc) {
F_284 ( & V_126 -> V_37 . V_701 , NULL ) ;
if ( V_126 -> V_37 . V_427 -> V_42 ) {
V_708 ++ ;
F_9 ( V_16 , L_454 , V_708 ) ;
F_282 ( V_16 , V_20 , V_126 ) ;
}
F_285 ( & V_126 -> V_37 . V_701 ) ;
}
if ( ! V_708 )
F_27 ( V_16 , L_455 ) ;
return 0 ;
}
static int F_286 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_618 * V_549 ;
struct V_548 * V_548 ;
struct V_709 * V_710 ;
F_236 ( V_20 ) ;
F_19 (encoder, &dev->mode_config.encoder_list, head) {
V_548 = F_238 ( V_549 ) ;
if ( V_548 -> type != V_638 )
continue;
V_710 = F_287 ( V_549 ) ;
if ( ! V_710 -> V_702 . V_711 )
continue;
F_288 ( V_16 , & V_710 -> V_702 . V_712 ) ;
}
F_241 ( V_20 ) ;
return 0 ;
}
static int F_289 ( struct V_196 * V_196 , struct V_110 * V_713 )
{
struct V_714 * V_22 = V_196 -> V_197 ;
struct V_35 * V_36 = V_22 -> V_20 -> V_69 ;
struct V_715 * V_716 = & V_36 -> V_716 [ V_22 -> V_128 ] ;
if ( V_22 -> V_128 >= F_8 ( V_22 -> V_20 ) -> V_717 )
return - V_368 ;
F_65 ( & V_716 -> V_323 ) ;
if ( V_716 -> V_718 ) {
F_73 ( & V_716 -> V_323 ) ;
return - V_719 ;
}
V_716 -> V_718 = true ;
V_713 -> V_195 = V_196 -> V_197 ;
F_73 ( & V_716 -> V_323 ) ;
return 0 ;
}
static int F_290 ( struct V_196 * V_196 , struct V_110 * V_713 )
{
struct V_714 * V_22 = V_196 -> V_197 ;
struct V_35 * V_36 = V_22 -> V_20 -> V_69 ;
struct V_715 * V_716 = & V_36 -> V_716 [ V_22 -> V_128 ] ;
F_65 ( & V_716 -> V_323 ) ;
V_716 -> V_718 = false ;
F_73 ( & V_716 -> V_323 ) ;
return 0 ;
}
static int F_291 ( struct V_715 * V_716 )
{
F_292 ( & V_716 -> V_323 ) ;
return F_293 ( V_716 -> V_68 , V_716 -> V_420 ,
V_720 ) ;
}
static T_5
F_294 ( struct V_110 * V_713 , char T_6 * V_721 , T_7 V_74 ,
T_8 * V_199 )
{
struct V_714 * V_22 = V_713 -> V_195 ;
struct V_19 * V_20 = V_22 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_715 * V_716 = & V_36 -> V_716 [ V_22 -> V_128 ] ;
char V_205 [ V_722 ] ;
int V_723 ;
T_5 V_724 ;
if ( V_74 < V_725 )
return - V_81 ;
if ( V_716 -> V_726 == V_727 )
return 0 ;
F_65 ( & V_716 -> V_323 ) ;
while ( F_291 ( V_716 ) == 0 ) {
int V_75 ;
if ( V_713 -> V_728 & V_729 ) {
F_73 ( & V_716 -> V_323 ) ;
return - V_730 ;
}
V_75 = F_295 ( V_716 -> V_731 ,
F_291 ( V_716 ) , V_716 -> V_323 ) ;
if ( V_75 ) {
F_73 ( & V_716 -> V_323 ) ;
return V_75 ;
}
}
V_723 = V_74 / V_725 ;
V_724 = 0 ;
while ( V_723 > 0 ) {
struct V_732 * V_687 =
& V_716 -> V_733 [ V_716 -> V_420 ] ;
int V_75 ;
if ( F_293 ( V_716 -> V_68 , V_716 -> V_420 ,
V_720 ) < 1 )
break;
F_296 ( V_720 ) ;
V_716 -> V_420 = ( V_716 -> V_420 + 1 ) & ( V_720 - 1 ) ;
V_724 += snprintf ( V_205 , V_722 ,
L_456 ,
V_687 -> V_734 , V_687 -> V_553 [ 0 ] ,
V_687 -> V_553 [ 1 ] , V_687 -> V_553 [ 2 ] ,
V_687 -> V_553 [ 3 ] , V_687 -> V_553 [ 4 ] ) ;
F_73 ( & V_716 -> V_323 ) ;
V_75 = F_297 ( V_721 , V_205 , V_725 ) ;
if ( V_75 == V_725 )
return - V_735 ;
V_721 += V_725 ;
V_723 -- ;
F_65 ( & V_716 -> V_323 ) ;
}
F_73 ( & V_716 -> V_323 ) ;
return V_724 ;
}
static int F_298 ( struct V_3 * V_736 , struct V_1 * V_2 ,
enum V_128 V_128 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
struct V_714 * V_22 = & V_737 [ V_128 ] ;
V_22 -> V_20 = V_20 ;
V_4 = F_299 ( V_22 -> V_52 , V_738 , V_736 , V_22 ,
& V_739 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , V_22 ) ;
}
static const char * F_300 ( enum V_740 V_726 )
{
F_301 ( F_46 ( V_741 ) != V_742 ) ;
return V_741 [ V_726 ] ;
}
static int F_302 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_743 ; V_41 ++ )
F_9 ( V_16 , L_457 , F_63 ( V_41 ) ,
F_300 ( V_36 -> V_716 [ V_41 ] . V_726 ) ) ;
return 0 ;
}
static int F_303 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
return F_304 ( V_110 , F_302 , V_20 ) ;
}
static int F_305 ( enum V_740 * V_726 ,
T_10 * V_207 )
{
if ( * V_726 == V_744 )
* V_726 = V_745 ;
switch ( * V_726 ) {
case V_745 :
* V_207 = V_746 | V_747 ;
break;
case V_727 :
* V_207 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_306 ( struct V_19 * V_20 , enum V_128 V_128 ,
enum V_740 * V_726 )
{
struct V_548 * V_549 ;
struct V_126 * V_127 ;
struct V_709 * V_748 ;
int V_75 = 0 ;
* V_726 = V_745 ;
F_236 ( V_20 ) ;
F_307 (dev, encoder) {
if ( ! V_549 -> V_37 . V_127 )
continue;
V_127 = F_308 ( V_549 -> V_37 . V_127 ) ;
if ( V_127 -> V_128 != V_128 )
continue;
switch ( V_549 -> type ) {
case V_749 :
* V_726 = V_750 ;
break;
case V_638 :
case V_556 :
V_748 = F_287 ( & V_549 -> V_37 ) ;
switch ( V_748 -> V_751 ) {
case V_752 :
* V_726 = V_753 ;
break;
case V_754 :
* V_726 = V_755 ;
break;
case V_756 :
* V_726 = V_757 ;
break;
default:
F_309 ( 1 , L_458 ,
F_310 ( V_748 -> V_751 ) ) ;
break;
}
break;
default:
break;
}
}
F_241 ( V_20 ) ;
return V_75 ;
}
static int F_311 ( struct V_19 * V_20 ,
enum V_128 V_128 ,
enum V_740 * V_726 ,
T_10 * V_207 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_758 = false ;
if ( * V_726 == V_744 ) {
int V_75 = F_306 ( V_20 , V_128 , V_726 ) ;
if ( V_75 )
return V_75 ;
}
switch ( * V_726 ) {
case V_745 :
* V_207 = V_746 | V_759 ;
break;
case V_753 :
* V_207 = V_746 | V_760 ;
V_758 = true ;
break;
case V_755 :
* V_207 = V_746 | V_761 ;
V_758 = true ;
break;
case V_757 :
if ( ! F_81 ( V_20 ) )
return - V_81 ;
* V_207 = V_746 | V_762 ;
V_758 = true ;
break;
case V_727 :
* V_207 = 0 ;
break;
default:
return - V_81 ;
}
if ( V_758 ) {
T_10 V_492 = F_70 ( V_763 ) ;
V_492 |= V_764 ;
switch ( V_128 ) {
case V_641 :
V_492 |= V_765 ;
break;
case V_766 :
V_492 |= V_767 ;
break;
case V_768 :
V_492 |= V_769 ;
break;
default:
return - V_81 ;
}
F_156 ( V_763 , V_492 ) ;
}
return 0 ;
}
static int F_312 ( struct V_19 * V_20 ,
enum V_128 V_128 ,
enum V_740 * V_726 ,
T_10 * V_207 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_758 = false ;
if ( * V_726 == V_744 ) {
int V_75 = F_306 ( V_20 , V_128 , V_726 ) ;
if ( V_75 )
return V_75 ;
}
switch ( * V_726 ) {
case V_745 :
* V_207 = V_746 | V_770 ;
break;
case V_750 :
if ( ! F_313 ( V_20 ) )
return - V_81 ;
* V_207 = V_746 | V_771 ;
break;
case V_753 :
if ( ! F_161 ( V_20 ) )
return - V_81 ;
* V_207 = V_746 | V_772 ;
V_758 = true ;
break;
case V_755 :
if ( ! F_161 ( V_20 ) )
return - V_81 ;
* V_207 = V_746 | V_773 ;
V_758 = true ;
break;
case V_757 :
if ( ! F_161 ( V_20 ) )
return - V_81 ;
* V_207 = V_746 | V_774 ;
V_758 = true ;
break;
case V_727 :
* V_207 = 0 ;
break;
default:
return - V_81 ;
}
if ( V_758 ) {
T_10 V_492 = F_70 ( V_763 ) ;
F_185 ( ! F_161 ( V_20 ) ) ;
F_156 ( V_775 ,
F_70 ( V_775 ) | V_776 ) ;
if ( V_128 == V_641 )
V_492 |= V_765 ;
else
V_492 |= V_767 ;
F_156 ( V_763 , V_492 ) ;
}
return 0 ;
}
static void F_314 ( struct V_19 * V_20 ,
enum V_128 V_128 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_10 V_492 = F_70 ( V_763 ) ;
switch ( V_128 ) {
case V_641 :
V_492 &= ~ V_765 ;
break;
case V_766 :
V_492 &= ~ V_767 ;
break;
case V_768 :
V_492 &= ~ V_769 ;
break;
default:
return;
}
if ( ! ( V_492 & V_777 ) )
V_492 &= ~ V_764 ;
F_156 ( V_763 , V_492 ) ;
}
static void F_315 ( struct V_19 * V_20 ,
enum V_128 V_128 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_10 V_492 = F_70 ( V_763 ) ;
if ( V_128 == V_641 )
V_492 &= ~ V_765 ;
else
V_492 &= ~ V_767 ;
F_156 ( V_763 , V_492 ) ;
if ( ! ( V_492 & V_777 ) ) {
F_156 ( V_775 ,
F_70 ( V_775 ) & ~ V_776 ) ;
}
}
static int F_316 ( enum V_740 * V_726 ,
T_10 * V_207 )
{
if ( * V_726 == V_744 )
* V_726 = V_745 ;
switch ( * V_726 ) {
case V_778 :
* V_207 = V_746 | V_779 ;
break;
case V_780 :
* V_207 = V_746 | V_781 ;
break;
case V_745 :
* V_207 = V_746 | V_782 ;
break;
case V_727 :
* V_207 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static void F_317 ( struct V_19 * V_20 , bool V_783 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_126 * V_127 =
F_308 ( V_36 -> V_784 [ V_641 ] ) ;
struct V_649 * V_650 ;
struct V_785 * V_427 ;
int V_75 = 0 ;
F_236 ( V_20 ) ;
V_427 = F_318 ( V_20 ) ;
if ( ! V_427 ) {
V_75 = - V_9 ;
goto V_204;
}
V_427 -> V_786 = F_319 ( & V_127 -> V_37 ) ;
V_650 = F_320 ( V_427 , V_127 ) ;
if ( F_321 ( V_650 ) ) {
V_75 = F_322 ( V_650 ) ;
goto V_204;
}
V_650 -> V_787 . V_788 = V_783 ;
if ( V_650 -> V_789 == V_790 &&
V_650 -> V_787 . V_481 != V_783 )
V_650 -> V_37 . V_791 = true ;
V_75 = F_323 ( V_427 ) ;
V_204:
F_241 ( V_20 ) ;
F_309 ( V_75 , L_459 , V_783 , V_75 ) ;
if ( V_75 )
F_324 ( V_427 ) ;
}
static int F_325 ( struct V_19 * V_20 ,
enum V_128 V_128 ,
enum V_740 * V_726 ,
T_10 * V_207 )
{
if ( * V_726 == V_744 )
* V_726 = V_792 ;
switch ( * V_726 ) {
case V_778 :
* V_207 = V_746 | V_793 ;
break;
case V_780 :
* V_207 = V_746 | V_794 ;
break;
case V_792 :
if ( F_124 ( V_20 ) && V_128 == V_641 )
F_317 ( V_20 , true ) ;
* V_207 = V_746 | V_795 ;
break;
case V_727 :
* V_207 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_326 ( struct V_19 * V_20 , enum V_128 V_128 ,
enum V_740 V_726 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_715 * V_716 = & V_36 -> V_716 [ V_128 ] ;
struct V_126 * V_127 = F_308 ( F_327 ( V_20 ,
V_128 ) ) ;
T_4 V_207 = 0 ;
int V_75 ;
if ( V_716 -> V_726 == V_726 )
return 0 ;
if ( V_716 -> V_726 && V_726 )
return - V_81 ;
if ( ! F_87 ( V_36 , F_88 ( V_128 ) ) ) {
F_328 ( L_460 ) ;
return - V_796 ;
}
if ( F_329 ( V_20 ) )
V_75 = F_305 ( & V_726 , & V_207 ) ;
else if ( F_8 ( V_20 ) -> V_23 < 5 )
V_75 = F_312 ( V_20 , V_128 , & V_726 , & V_207 ) ;
else if ( F_92 ( V_20 ) )
V_75 = F_311 ( V_20 , V_128 , & V_726 , & V_207 ) ;
else if ( F_116 ( V_20 ) || F_118 ( V_20 ) )
V_75 = F_316 ( & V_726 , & V_207 ) ;
else
V_75 = F_325 ( V_20 , V_128 , & V_726 , & V_207 ) ;
if ( V_75 != 0 )
return V_75 ;
if ( V_726 ) {
struct V_732 * V_733 ;
F_98 ( L_461 ,
F_63 ( V_128 ) , F_300 ( V_726 ) ) ;
V_733 = F_330 ( V_720 ,
sizeof( V_716 -> V_733 [ 0 ] ) ,
V_8 ) ;
if ( ! V_733 )
return - V_9 ;
F_331 ( V_127 ) ;
F_65 ( & V_716 -> V_323 ) ;
F_105 ( V_716 -> V_733 ) ;
V_716 -> V_733 = V_733 ;
V_716 -> V_68 = 0 ;
V_716 -> V_420 = 0 ;
F_73 ( & V_716 -> V_323 ) ;
}
V_716 -> V_726 = V_726 ;
F_156 ( F_332 ( V_128 ) , V_207 ) ;
F_333 ( F_332 ( V_128 ) ) ;
if ( V_726 == V_727 ) {
struct V_732 * V_733 ;
struct V_126 * V_127 =
F_308 ( V_36 -> V_784 [ V_128 ] ) ;
F_98 ( L_462 ,
F_63 ( V_128 ) ) ;
F_284 ( & V_127 -> V_37 . V_701 , NULL ) ;
if ( V_127 -> V_37 . V_427 -> V_42 )
F_334 ( V_20 , V_128 ) ;
F_285 ( & V_127 -> V_37 . V_701 ) ;
F_65 ( & V_716 -> V_323 ) ;
V_733 = V_716 -> V_733 ;
V_716 -> V_733 = NULL ;
V_716 -> V_68 = 0 ;
V_716 -> V_420 = 0 ;
F_73 ( & V_716 -> V_323 ) ;
F_105 ( V_733 ) ;
if ( F_161 ( V_20 ) )
F_315 ( V_20 , V_128 ) ;
else if ( F_92 ( V_20 ) )
F_314 ( V_20 , V_128 ) ;
else if ( F_124 ( V_20 ) && V_128 == V_641 )
F_317 ( V_20 , false ) ;
F_335 ( V_127 ) ;
}
return 0 ;
}
static int F_336 ( char * V_205 , char * V_797 [] , int V_798 )
{
int V_799 = 0 ;
while ( * V_205 ) {
char * V_690 ;
V_205 = F_337 ( V_205 ) ;
if ( ! * V_205 )
break;
for ( V_690 = V_205 ; * V_690 && ! isspace ( * V_690 ) ; V_690 ++ )
;
if ( V_799 == V_798 ) {
F_98 ( L_463 ,
V_798 ) ;
return - V_81 ;
}
if ( * V_690 )
* V_690 ++ = '\0' ;
V_797 [ V_799 ++ ] = V_205 ;
V_205 = V_690 ;
}
return V_799 ;
}
static int
F_338 ( const char * V_205 , enum V_800 * V_801 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_802 ) ; V_41 ++ )
if ( ! strcmp ( V_205 , V_802 [ V_41 ] ) ) {
* V_801 = V_41 ;
return 0 ;
}
return - V_81 ;
}
static int F_339 ( const char * V_205 , enum V_128 * V_128 )
{
const char V_52 = V_205 [ 0 ] ;
if ( V_52 < 'A' || V_52 >= F_63 ( V_743 ) )
return - V_81 ;
* V_128 = V_52 - 'A' ;
return 0 ;
}
static int
F_340 ( const char * V_205 , enum V_740 * V_59 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_741 ) ; V_41 ++ )
if ( ! strcmp ( V_205 , V_741 [ V_41 ] ) ) {
* V_59 = V_41 ;
return 0 ;
}
return - V_81 ;
}
static int F_341 ( struct V_19 * V_20 , char * V_205 , T_7 V_803 )
{
#define F_342 3
int V_799 ;
char * V_797 [ F_342 ] ;
enum V_128 V_128 ;
enum V_800 V_804 ;
enum V_740 V_726 ;
V_799 = F_336 ( V_205 , V_797 , F_342 ) ;
if ( V_799 != F_342 ) {
F_98 ( L_464 ,
F_342 ) ;
return - V_81 ;
}
if ( F_338 ( V_797 [ 0 ] , & V_804 ) < 0 ) {
F_98 ( L_465 , V_797 [ 0 ] ) ;
return - V_81 ;
}
if ( F_339 ( V_797 [ 1 ] , & V_128 ) < 0 ) {
F_98 ( L_466 , V_797 [ 1 ] ) ;
return - V_81 ;
}
if ( F_340 ( V_797 [ 2 ] , & V_726 ) < 0 ) {
F_98 ( L_467 , V_797 [ 2 ] ) ;
return - V_81 ;
}
return F_326 ( V_20 , V_128 , V_726 ) ;
}
static T_5 F_343 ( struct V_110 * V_110 , const char T_6 * V_190 ,
T_7 V_803 , T_8 * V_805 )
{
struct V_15 * V_16 = V_110 -> V_195 ;
struct V_19 * V_20 = V_16 -> V_18 ;
char * V_806 ;
int V_75 ;
if ( V_803 == 0 )
return 0 ;
if ( V_803 > V_536 - 1 ) {
F_98 ( L_468 ,
V_536 ) ;
return - V_807 ;
}
V_806 = F_2 ( V_803 + 1 , V_8 ) ;
if ( ! V_806 )
return - V_9 ;
if ( F_344 ( V_806 , V_190 , V_803 ) ) {
V_75 = - V_735 ;
goto V_204;
}
V_806 [ V_803 ] = '\0' ;
V_75 = F_341 ( V_20 , V_806 , V_803 ) ;
V_204:
F_105 ( V_806 ) ;
if ( V_75 < 0 )
return V_75 ;
* V_805 += V_803 ;
return V_803 ;
}
static T_5 F_345 ( struct V_110 * V_110 ,
const char T_6 * V_190 ,
T_7 V_803 , T_8 * V_805 )
{
char * V_808 ;
int V_435 = 0 ;
struct V_19 * V_20 ;
struct V_619 * V_551 ;
struct V_67 * V_809 ;
struct V_552 * V_552 ;
int V_207 = 0 ;
V_20 = ( (struct V_15 * ) V_110 -> V_195 ) -> V_18 ;
V_809 = & V_20 -> V_415 . V_809 ;
if ( V_803 == 0 )
return 0 ;
V_808 = F_2 ( V_803 + 1 , V_8 ) ;
if ( ! V_808 )
return - V_9 ;
if ( F_344 ( V_808 , V_190 , V_803 ) ) {
V_435 = - V_735 ;
goto V_204;
}
V_808 [ V_803 ] = '\0' ;
F_98 ( L_469 , ( unsigned int ) V_803 ) ;
F_19 (connector, connector_list, head) {
if ( V_551 -> V_810 !=
V_811 )
continue;
if ( V_551 -> V_435 == V_620 &&
V_551 -> V_549 != NULL ) {
V_552 = F_239 ( V_551 -> V_549 ) ;
V_435 = F_346 ( V_808 , 10 , & V_207 ) ;
if ( V_435 < 0 )
goto V_204;
F_98 ( L_470 , V_207 ) ;
if ( V_207 == 1 )
V_552 -> V_812 = 1 ;
else
V_552 -> V_812 = 0 ;
}
}
V_204:
F_105 ( V_808 ) ;
if ( V_435 < 0 )
return V_435 ;
* V_805 += V_803 ;
return V_803 ;
}
static int F_347 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_619 * V_551 ;
struct V_67 * V_809 = & V_20 -> V_415 . V_809 ;
struct V_552 * V_552 ;
F_19 (connector, connector_list, head) {
if ( V_551 -> V_810 !=
V_811 )
continue;
if ( V_551 -> V_435 == V_620 &&
V_551 -> V_549 != NULL ) {
V_552 = F_239 ( V_551 -> V_549 ) ;
if ( V_552 -> V_812 )
F_27 ( V_16 , L_471 ) ;
else
F_27 ( V_16 , L_472 ) ;
} else
F_27 ( V_16 , L_472 ) ;
}
return 0 ;
}
static int F_348 ( struct V_196 * V_196 ,
struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
return F_304 ( V_110 , F_347 , V_20 ) ;
}
static int F_349 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_619 * V_551 ;
struct V_67 * V_809 = & V_20 -> V_415 . V_809 ;
struct V_552 * V_552 ;
F_19 (connector, connector_list, head) {
if ( V_551 -> V_810 !=
V_811 )
continue;
if ( V_551 -> V_435 == V_620 &&
V_551 -> V_549 != NULL ) {
V_552 = F_239 ( V_551 -> V_549 ) ;
F_9 ( V_16 , L_473 , V_552 -> V_813 ) ;
} else
F_27 ( V_16 , L_472 ) ;
}
return 0 ;
}
static int F_350 ( struct V_196 * V_196 ,
struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
return F_304 ( V_110 , F_349 , V_20 ) ;
}
static int F_351 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_619 * V_551 ;
struct V_67 * V_809 = & V_20 -> V_415 . V_809 ;
struct V_552 * V_552 ;
F_19 (connector, connector_list, head) {
if ( V_551 -> V_810 !=
V_811 )
continue;
if ( V_551 -> V_435 == V_620 &&
V_551 -> V_549 != NULL ) {
V_552 = F_239 ( V_551 -> V_549 ) ;
F_9 ( V_16 , L_474 , V_552 -> V_814 ) ;
} else
F_27 ( V_16 , L_472 ) ;
}
return 0 ;
}
static int F_352 ( struct V_196 * V_196 ,
struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
return F_304 ( V_110 , F_351 , V_20 ) ;
}
static void F_353 ( struct V_15 * V_16 , const T_13 V_688 [ 8 ] )
{
struct V_19 * V_20 = V_16 -> V_18 ;
int V_815 ;
int V_816 ;
if ( F_81 ( V_20 ) )
V_816 = 3 ;
else if ( F_92 ( V_20 ) )
V_816 = 1 ;
else
V_816 = F_354 ( V_20 ) + 1 ;
F_236 ( V_20 ) ;
for ( V_815 = 0 ; V_815 < V_816 ; V_815 ++ ) {
unsigned int V_817 = V_688 [ V_815 ] ;
if ( F_8 ( V_20 ) -> V_23 >= 9 || F_92 ( V_20 ) )
V_817 *= 10 ;
else if ( V_815 > 0 )
V_817 *= 5 ;
F_9 ( V_16 , L_475 ,
V_815 , V_688 [ V_815 ] , V_817 / 10 , V_817 % 10 ) ;
}
F_241 ( V_20 ) ;
}
static int F_355 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_13 * V_818 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_818 = V_36 -> V_688 . V_819 ;
else
V_818 = F_23 ( V_20 ) -> V_688 . V_820 ;
F_353 ( V_16 , V_818 ) ;
return 0 ;
}
static int F_356 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_13 * V_818 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_818 = V_36 -> V_688 . V_819 ;
else
V_818 = F_23 ( V_20 ) -> V_688 . V_821 ;
F_353 ( V_16 , V_818 ) ;
return 0 ;
}
static int F_357 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_13 * V_818 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_818 = V_36 -> V_688 . V_819 ;
else
V_818 = F_23 ( V_20 ) -> V_688 . V_822 ;
F_353 ( V_16 , V_818 ) ;
return 0 ;
}
static int F_358 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
if ( F_8 ( V_20 ) -> V_23 < 5 )
return - V_368 ;
return F_304 ( V_110 , F_355 , V_20 ) ;
}
static int F_359 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
if ( F_360 ( V_20 ) )
return - V_368 ;
return F_304 ( V_110 , F_356 , V_20 ) ;
}
static int F_361 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
if ( F_360 ( V_20 ) )
return - V_368 ;
return F_304 ( V_110 , F_357 , V_20 ) ;
}
static T_5 F_362 ( struct V_110 * V_110 , const char T_6 * V_190 ,
T_7 V_803 , T_8 * V_805 , T_13 V_688 [ 8 ] )
{
struct V_15 * V_16 = V_110 -> V_195 ;
struct V_19 * V_20 = V_16 -> V_18 ;
T_13 V_823 [ 8 ] = { 0 } ;
int V_816 ;
int V_815 ;
int V_75 ;
char V_492 [ 32 ] ;
if ( F_81 ( V_20 ) )
V_816 = 3 ;
else if ( F_92 ( V_20 ) )
V_816 = 1 ;
else
V_816 = F_354 ( V_20 ) + 1 ;
if ( V_803 >= sizeof( V_492 ) )
return - V_81 ;
if ( F_344 ( V_492 , V_190 , V_803 ) )
return - V_735 ;
V_492 [ V_803 ] = '\0' ;
V_75 = sscanf ( V_492 , L_476 ,
& V_823 [ 0 ] , & V_823 [ 1 ] , & V_823 [ 2 ] , & V_823 [ 3 ] ,
& V_823 [ 4 ] , & V_823 [ 5 ] , & V_823 [ 6 ] , & V_823 [ 7 ] ) ;
if ( V_75 != V_816 )
return - V_81 ;
F_236 ( V_20 ) ;
for ( V_815 = 0 ; V_815 < V_816 ; V_815 ++ )
V_688 [ V_815 ] = V_823 [ V_815 ] ;
F_241 ( V_20 ) ;
return V_803 ;
}
static T_5 F_363 ( struct V_110 * V_110 , const char T_6 * V_190 ,
T_7 V_803 , T_8 * V_805 )
{
struct V_15 * V_16 = V_110 -> V_195 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_13 * V_818 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_818 = V_36 -> V_688 . V_819 ;
else
V_818 = F_23 ( V_20 ) -> V_688 . V_820 ;
return F_362 ( V_110 , V_190 , V_803 , V_805 , V_818 ) ;
}
static T_5 F_364 ( struct V_110 * V_110 , const char T_6 * V_190 ,
T_7 V_803 , T_8 * V_805 )
{
struct V_15 * V_16 = V_110 -> V_195 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_13 * V_818 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_818 = V_36 -> V_688 . V_819 ;
else
V_818 = F_23 ( V_20 ) -> V_688 . V_821 ;
return F_362 ( V_110 , V_190 , V_803 , V_805 , V_818 ) ;
}
static T_5 F_365 ( struct V_110 * V_110 , const char T_6 * V_190 ,
T_7 V_803 , T_8 * V_805 )
{
struct V_15 * V_16 = V_110 -> V_195 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_13 * V_818 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_818 = V_36 -> V_688 . V_819 ;
else
V_818 = F_23 ( V_20 ) -> V_688 . V_822 ;
return F_362 ( V_110 , V_190 , V_803 , V_805 , V_818 ) ;
}
static int
F_366 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_207 = F_66 ( & V_36 -> V_287 . V_824 ) ;
return 0 ;
}
static int
F_367 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_368 ( & V_36 -> V_287 ) )
return - V_730 ;
F_78 ( V_36 ) ;
F_369 ( V_20 , V_207 ,
L_477 , V_207 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int
F_370 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_207 = V_36 -> V_287 . V_825 ;
return 0 ;
}
static int
F_371 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
F_98 ( L_478 , V_207 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_36 -> V_287 . V_825 = V_207 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_372 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_207 = V_36 -> V_287 . V_826 ;
return 0 ;
}
static int
F_373 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_36 -> V_287 . V_826 = V_207 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_374 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_207 = V_36 -> V_287 . V_827 ;
return 0 ;
}
static int
F_375 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
F_98 ( L_479 , V_207 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_36 -> V_287 . V_827 = V_207 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_376 ( void * V_17 , T_2 * V_207 )
{
* V_207 = V_828 ;
return 0 ;
}
static int
F_377 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
F_378 ( L_480 , V_207 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
if ( V_207 & V_829 ) {
V_75 = F_379 ( V_20 ) ;
if ( V_75 )
goto V_830;
}
if ( V_207 & ( V_831 | V_829 ) )
F_380 ( V_20 ) ;
if ( V_207 & V_832 )
F_381 ( V_36 , V_833 , V_834 ) ;
if ( V_207 & V_835 )
F_381 ( V_36 , V_833 , V_836 ) ;
V_830:
F_6 ( & V_20 -> V_76 ) ;
return V_75 ;
}
static int
F_382 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_368 ;
F_115 ( & V_36 -> V_209 . V_210 ) ;
V_75 = F_32 ( & V_36 -> V_209 . V_277 ) ;
if ( V_75 )
return V_75 ;
* V_207 = F_125 ( V_36 , V_36 -> V_209 . V_395 ) ;
F_6 ( & V_36 -> V_209 . V_277 ) ;
return 0 ;
}
static int
F_383 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_837 , V_838 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_368 ;
F_115 ( & V_36 -> V_209 . V_210 ) ;
F_98 ( L_481 , V_207 ) ;
V_75 = F_32 ( & V_36 -> V_209 . V_277 ) ;
if ( V_75 )
return V_75 ;
V_207 = F_384 ( V_36 , V_207 ) ;
V_837 = V_36 -> V_209 . V_239 ;
V_838 = V_36 -> V_209 . V_274 ;
if ( V_207 < V_838 || V_207 > V_837 || V_207 < V_36 -> V_209 . V_394 ) {
F_6 ( & V_36 -> V_209 . V_277 ) ;
return - V_81 ;
}
V_36 -> V_209 . V_395 = V_207 ;
F_385 ( V_20 , V_207 ) ;
F_6 ( & V_36 -> V_209 . V_277 ) ;
return 0 ;
}
static int
F_386 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_368 ;
F_115 ( & V_36 -> V_209 . V_210 ) ;
V_75 = F_32 ( & V_36 -> V_209 . V_277 ) ;
if ( V_75 )
return V_75 ;
* V_207 = F_125 ( V_36 , V_36 -> V_209 . V_394 ) ;
F_6 ( & V_36 -> V_209 . V_277 ) ;
return 0 ;
}
static int
F_387 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_837 , V_838 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_368 ;
F_115 ( & V_36 -> V_209 . V_210 ) ;
F_98 ( L_482 , V_207 ) ;
V_75 = F_32 ( & V_36 -> V_209 . V_277 ) ;
if ( V_75 )
return V_75 ;
V_207 = F_384 ( V_36 , V_207 ) ;
V_837 = V_36 -> V_209 . V_239 ;
V_838 = V_36 -> V_209 . V_274 ;
if ( V_207 < V_838 || V_207 > V_837 || V_207 > V_36 -> V_209 . V_395 ) {
F_6 ( & V_36 -> V_209 . V_277 ) ;
return - V_81 ;
}
V_36 -> V_209 . V_394 = V_207 ;
F_385 ( V_20 , V_207 ) ;
F_6 ( & V_36 -> V_209 . V_277 ) ;
return 0 ;
}
static int
F_388 ( void * V_17 , T_2 * V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_839 ;
int V_75 ;
if ( ! ( F_118 ( V_20 ) || F_119 ( V_20 ) ) )
return - V_368 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
V_839 = F_70 ( V_840 ) ;
F_79 ( V_36 ) ;
F_6 ( & V_36 -> V_20 -> V_76 ) ;
* V_207 = ( V_839 & V_841 ) >> V_842 ;
return 0 ;
}
static int
F_389 ( void * V_17 , T_2 V_207 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_839 ;
if ( ! ( F_118 ( V_20 ) || F_119 ( V_20 ) ) )
return - V_368 ;
if ( V_207 > 3 )
return - V_81 ;
F_78 ( V_36 ) ;
F_98 ( L_483 , V_207 ) ;
V_839 = F_70 ( V_840 ) ;
V_839 &= ~ V_841 ;
V_839 |= ( V_207 << V_842 ) ;
F_156 ( V_840 , V_839 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static void F_390 ( struct V_19 * V_20 ,
struct V_843 * V_538 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_844 = 2 ;
int V_845 ;
T_4 V_846 [ V_844 ] , V_847 [ V_844 ] ;
V_846 [ 0 ] = F_70 ( V_848 ) ;
V_846 [ 1 ] = F_70 ( V_849 ) ;
V_847 [ 0 ] = F_70 ( V_850 ) ;
V_847 [ 1 ] = F_70 ( V_851 ) ;
for ( V_845 = 0 ; V_845 < V_844 ; V_845 ++ ) {
unsigned int V_852 ;
if ( V_846 [ V_845 ] & V_853 )
continue;
V_538 -> V_854 = 1 ;
V_538 -> V_855 ++ ;
V_852 = ( ( V_846 [ V_845 ] & V_856 ) ? 0 : 2 ) +
( ( V_846 [ V_845 ] & V_857 ) ? 0 : 2 ) +
( ( V_846 [ V_845 ] & V_858 ) ? 0 : 2 ) +
( ( V_847 [ V_845 ] & V_859 ) ? 0 : 2 ) ;
V_538 -> V_860 += V_852 ;
V_538 -> V_861 = F_391 ( V_538 -> V_861 , V_852 ) ;
}
V_538 -> V_862 = V_538 -> V_855 ;
}
static void F_392 ( struct V_19 * V_20 ,
struct V_843 * V_538 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_863 = 3 , V_844 = 4 ;
int V_59 , V_845 ;
T_4 V_864 [ V_863 ] , V_865 [ 2 * V_863 ] , V_866 [ 2 ] ;
if ( F_122 ( V_20 ) ) {
V_863 = 1 ;
V_844 = 3 ;
}
for ( V_59 = 0 ; V_59 < V_863 ; V_59 ++ ) {
V_864 [ V_59 ] = F_70 ( F_393 ( V_59 ) ) ;
V_865 [ 2 * V_59 ] = F_70 ( F_394 ( V_59 ) ) ;
V_865 [ 2 * V_59 + 1 ] = F_70 ( F_395 ( V_59 ) ) ;
}
V_866 [ 0 ] = V_867 |
V_868 |
V_869 |
V_870 ;
V_866 [ 1 ] = V_871 |
V_872 |
V_873 |
V_874 ;
for ( V_59 = 0 ; V_59 < V_863 ; V_59 ++ ) {
unsigned int V_875 = 0 ;
if ( ( V_864 [ V_59 ] & V_876 ) == 0 )
continue;
V_538 -> V_854 ++ ;
if ( F_128 ( V_20 ) )
V_875 = F_8 ( V_20 ) -> V_855 ;
for ( V_845 = 0 ; V_845 < V_844 ; V_845 ++ ) {
unsigned int V_852 ;
if ( F_122 ( V_20 ) &&
! ( V_864 [ V_59 ] & ( F_396 ( V_845 ) ) ) )
continue;
if ( F_122 ( V_20 ) )
V_875 ++ ;
V_852 = 2 * F_275 ( V_865 [ 2 * V_59 + V_845 / 2 ] &
V_866 [ V_845 % 2 ] ) ;
V_538 -> V_860 += V_852 ;
V_538 -> V_861 = F_391 ( V_538 -> V_861 ,
V_852 ) ;
}
V_538 -> V_862 += V_875 ;
V_538 -> V_855 = F_391 ( V_538 -> V_855 ,
V_875 ) ;
}
}
static void F_397 ( struct V_19 * V_20 ,
struct V_843 * V_538 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_59 ;
T_4 V_877 = F_70 ( V_878 ) ;
V_538 -> V_854 = F_275 ( V_877 & V_879 ) ;
if ( V_538 -> V_854 ) {
V_538 -> V_855 = F_8 ( V_20 ) -> V_855 ;
V_538 -> V_862 = V_538 -> V_854 *
V_538 -> V_855 ;
V_538 -> V_861 = F_8 ( V_20 ) -> V_861 ;
V_538 -> V_860 = V_538 -> V_861 * V_538 -> V_862 ;
for ( V_59 = 0 ; V_59 < V_538 -> V_854 ; V_59 ++ ) {
T_11 V_880 = F_8 ( V_20 ) -> V_880 [ V_59 ] ;
V_538 -> V_860 -= F_398 ( V_880 ) ;
}
}
}
static int F_399 ( struct V_15 * V_16 , void * V_208 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_843 V_538 ;
if ( F_8 ( V_20 ) -> V_23 < 8 )
return - V_368 ;
F_27 ( V_16 , L_484 ) ;
F_9 ( V_16 , L_485 ,
F_8 ( V_20 ) -> V_854 ) ;
F_9 ( V_16 , L_486 ,
F_8 ( V_20 ) -> V_862 ) ;
F_9 ( V_16 , L_487 ,
F_8 ( V_20 ) -> V_855 ) ;
F_9 ( V_16 , L_488 ,
F_8 ( V_20 ) -> V_860 ) ;
F_9 ( V_16 , L_489 ,
F_8 ( V_20 ) -> V_861 ) ;
F_9 ( V_16 , L_490 ,
F_135 ( F_8 ( V_20 ) -> V_881 ) ) ;
F_9 ( V_16 , L_491 ,
F_135 ( F_8 ( V_20 ) -> V_882 ) ) ;
F_9 ( V_16 , L_492 ,
F_135 ( F_8 ( V_20 ) -> V_883 ) ) ;
F_27 ( V_16 , L_493 ) ;
memset ( & V_538 , 0 , sizeof( V_538 ) ) ;
if ( F_81 ( V_20 ) ) {
F_390 ( V_20 , & V_538 ) ;
} else if ( F_120 ( V_20 ) ) {
F_397 ( V_20 , & V_538 ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 9 ) {
F_392 ( V_20 , & V_538 ) ;
}
F_9 ( V_16 , L_494 ,
V_538 . V_854 ) ;
F_9 ( V_16 , L_495 ,
V_538 . V_862 ) ;
F_9 ( V_16 , L_496 ,
V_538 . V_855 ) ;
F_9 ( V_16 , L_497 ,
V_538 . V_860 ) ;
F_9 ( V_16 , L_498 ,
V_538 . V_861 ) ;
return 0 ;
}
static int F_400 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return 0 ;
F_78 ( V_36 ) ;
F_123 ( V_36 , V_245 ) ;
return 0 ;
}
static int F_401 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_196 -> V_197 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return 0 ;
F_126 ( V_36 , V_245 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_402 ( struct V_3 * V_736 , struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
V_4 = F_299 ( L_499 ,
V_884 ,
V_736 , V_20 ,
& V_885 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , & V_885 ) ;
}
static int F_403 ( struct V_3 * V_736 ,
struct V_1 * V_2 ,
const char * V_52 ,
const struct V_886 * V_887 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
V_4 = F_299 ( V_52 ,
V_738 | V_888 ,
V_736 , V_20 ,
V_887 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , V_887 ) ;
}
void F_404 ( struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
enum V_128 V_128 ;
F_82 (dev_priv, pipe) {
struct V_715 * V_716 = & V_36 -> V_716 [ V_128 ] ;
V_716 -> V_718 = false ;
F_405 ( & V_716 -> V_323 ) ;
F_406 ( & V_716 -> V_731 ) ;
}
}
int F_407 ( struct V_1 * V_2 )
{
int V_75 , V_41 ;
V_75 = F_402 ( V_2 -> V_889 , V_2 ) ;
if ( V_75 )
return V_75 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_737 ) ; V_41 ++ ) {
V_75 = F_298 ( V_2 -> V_889 , V_2 , V_41 ) ;
if ( V_75 )
return V_75 ;
}
for ( V_41 = 0 ; V_41 < F_46 ( V_890 ) ; V_41 ++ ) {
V_75 = F_403 ( V_2 -> V_889 , V_2 ,
V_890 [ V_41 ] . V_52 ,
V_890 [ V_41 ] . V_887 ) ;
if ( V_75 )
return V_75 ;
}
return F_408 ( V_891 ,
V_892 ,
V_2 -> V_889 , V_2 ) ;
}
void F_409 ( struct V_1 * V_2 )
{
int V_41 ;
F_410 ( V_891 ,
V_892 , V_2 ) ;
F_410 ( (struct V_893 * ) & V_885 ,
1 , V_2 ) ;
for ( V_41 = 0 ; V_41 < F_46 ( V_737 ) ; V_41 ++ ) {
struct V_893 * V_894 =
(struct V_893 * ) & V_737 [ V_41 ] ;
F_410 ( V_894 , 1 , V_2 ) ;
}
for ( V_41 = 0 ; V_41 < F_46 ( V_890 ) ; V_41 ++ ) {
struct V_893 * V_894 =
(struct V_893 * ) V_890 [ V_41 ] . V_887 ;
F_410 ( V_894 , 1 , V_2 ) ;
}
}
static int F_411 ( struct V_15 * V_16 , void * V_17 )
{
struct V_619 * V_551 = V_16 -> V_18 ;
struct V_552 * V_552 =
F_239 ( & F_412 ( V_551 ) -> V_37 ) ;
T_14 V_205 [ 16 ] ;
T_5 V_895 ;
int V_41 ;
if ( V_551 -> V_435 != V_620 )
return - V_368 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_896 ) ; V_41 ++ ) {
const struct V_897 * V_87 = & V_896 [ V_41 ] ;
T_7 V_31 = V_87 -> V_690 ? V_87 -> V_690 - V_87 -> V_662 + 1 : ( V_87 -> V_31 ? : 1 ) ;
if ( V_87 -> V_898 &&
V_551 -> V_810 != V_899 )
continue;
if ( F_185 ( V_31 > sizeof( V_205 ) ) )
continue;
V_895 = F_413 ( & V_552 -> V_900 , V_87 -> V_662 , V_205 , V_31 ) ;
if ( V_895 <= 0 ) {
F_414 ( L_500 ,
V_31 , V_87 -> V_662 , V_895 ) ;
continue;
}
F_9 ( V_16 , L_501 , V_87 -> V_662 , ( int ) V_31 , V_205 ) ;
}
return 0 ;
}
static int F_415 ( struct V_196 * V_196 , struct V_110 * V_110 )
{
return F_304 ( V_110 , F_411 , V_196 -> V_197 ) ;
}
int F_416 ( struct V_619 * V_551 )
{
struct V_3 * V_736 = V_551 -> V_901 ;
if ( ! V_736 )
return - V_368 ;
if ( V_551 -> V_810 == V_811 ||
V_551 -> V_810 == V_899 )
F_299 ( L_502 , V_738 , V_736 , V_551 ,
& V_902 ) ;
return 0 ;
}
