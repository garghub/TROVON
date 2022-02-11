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
enum V_162 V_163 ;
V_163 = F_87 ( V_128 ) ;
if ( ! F_88 ( V_36 ,
V_163 ) ) {
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
F_92 ( V_36 , V_163 ) ;
}
F_9 ( V_16 , L_81 ,
F_70 ( V_164 ) ) ;
F_9 ( V_16 , L_82 ,
F_70 ( V_165 ) ) ;
F_9 ( V_16 , L_83 ,
F_70 ( V_166 ) ) ;
F_9 ( V_16 , L_84 ,
F_70 ( V_167 ) ) ;
F_9 ( V_16 , L_85 ,
F_70 ( V_168 ) ) ;
F_9 ( V_16 , L_86 ,
F_70 ( V_169 ) ) ;
F_9 ( V_16 , L_74 ,
F_70 ( V_159 ) ) ;
F_9 ( V_16 , L_75 ,
F_70 ( V_160 ) ) ;
F_9 ( V_16 , L_76 ,
F_70 ( V_161 ) ) ;
} else if ( F_93 ( V_20 ) ) {
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
F_70 ( V_170 ) ) ;
F_9 ( V_16 , L_88 ,
F_70 ( V_171 ) ) ;
F_9 ( V_16 , L_89 ,
F_70 ( V_172 ) ) ;
F_9 ( V_16 , L_90 ,
F_70 ( V_173 ) ) ;
F_9 ( V_16 , L_91 ,
F_70 ( V_174 ) ) ;
F_9 ( V_16 , L_92 ,
F_70 ( V_175 ) ) ;
F_9 ( V_16 , L_93 ,
F_70 ( V_176 ) ) ;
F_9 ( V_16 , L_68 ,
F_70 ( V_156 ) ) ;
F_9 ( V_16 , L_69 ,
F_70 ( V_157 ) ) ;
F_9 ( V_16 , L_70 ,
F_70 ( V_158 ) ) ;
} else if ( ! F_94 ( V_20 ) ) {
F_9 ( V_16 , L_94 ,
F_70 ( V_177 ) ) ;
F_9 ( V_16 , L_95 ,
F_70 ( V_178 ) ) ;
F_9 ( V_16 , L_96 ,
F_70 ( V_179 ) ) ;
F_82 (dev_priv, pipe)
F_9 ( V_16 , L_97 ,
F_63 ( V_128 ) ,
F_70 ( F_83 ( V_128 ) ) ) ;
} else {
F_9 ( V_16 , L_98 ,
F_70 ( V_180 ) ) ;
F_9 ( V_16 , L_99 ,
F_70 ( V_181 ) ) ;
F_9 ( V_16 , L_100 ,
F_70 ( V_182 ) ) ;
F_9 ( V_16 , L_101 ,
F_70 ( V_183 ) ) ;
F_9 ( V_16 , L_102 ,
F_70 ( V_184 ) ) ;
F_9 ( V_16 , L_103 ,
F_70 ( V_185 ) ) ;
F_9 ( V_16 , L_104 ,
F_70 ( V_171 ) ) ;
F_9 ( V_16 , L_105 ,
F_70 ( V_172 ) ) ;
F_9 ( V_16 , L_106 ,
F_70 ( V_173 ) ) ;
}
F_24 (ring, dev_priv, i) {
if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
F_9 ( V_16 ,
L_107 ,
V_39 -> V_52 , F_95 ( V_39 ) ) ;
}
F_76 ( V_16 , V_39 ) ;
}
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_96 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 , V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_9 ( V_16 , L_108 , V_36 -> V_186 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_186 ; V_41 ++ ) {
struct V_24 * V_25 = V_36 -> V_187 [ V_41 ] . V_25 ;
F_9 ( V_16 , L_109 ,
V_41 , V_36 -> V_187 [ V_41 ] . V_40 ) ;
if ( V_25 == NULL )
F_27 ( V_16 , L_110 ) ;
else
F_22 ( V_16 , V_25 ) ;
F_30 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_97 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
const T_4 * V_188 ;
int V_41 ;
V_39 = & V_36 -> V_39 [ ( T_3 ) V_7 -> V_11 -> V_17 ] ;
V_188 = V_39 -> V_189 . V_190 ;
if ( V_188 == NULL )
return 0 ;
for ( V_41 = 0 ; V_41 < 4096 / sizeof( T_4 ) / 4 ; V_41 += 4 ) {
F_9 ( V_16 , L_111 ,
V_41 * 4 ,
V_188 [ V_41 ] , V_188 [ V_41 + 1 ] , V_188 [ V_41 + 2 ] , V_188 [ V_41 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_98 ( struct V_110 * V_191 ,
const char T_6 * V_192 ,
T_7 V_193 ,
T_8 * V_194 )
{
struct V_195 * V_196 = V_191 -> V_197 ;
struct V_19 * V_20 = V_196 -> V_20 ;
int V_75 ;
F_99 ( L_112 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_100 ( V_20 ) ;
F_6 ( & V_20 -> V_76 ) ;
return V_193 ;
}
static int F_101 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
struct V_195 * V_196 ;
V_196 = F_102 ( sizeof( * V_196 ) , V_8 ) ;
if ( ! V_196 )
return - V_9 ;
V_196 -> V_20 = V_20 ;
F_103 ( V_20 , V_196 ) ;
V_110 -> V_197 = V_196 ;
return 0 ;
}
static int F_104 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_195 * V_196 = V_110 -> V_197 ;
F_105 ( V_196 ) ;
F_106 ( V_196 ) ;
return 0 ;
}
static T_5 F_107 ( struct V_110 * V_110 , char T_6 * V_200 ,
T_7 V_74 , T_8 * V_201 )
{
struct V_195 * V_196 = V_110 -> V_197 ;
struct V_202 V_203 ;
T_8 V_204 = 0 ;
T_5 V_205 = 0 ;
int V_75 ;
V_75 = F_108 ( & V_203 , F_23 ( V_196 -> V_20 ) , V_74 , * V_201 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_109 ( & V_203 , V_196 ) ;
if ( V_75 )
goto V_206;
V_205 = F_110 ( V_200 , V_74 , & V_204 ,
V_203 . V_207 ,
V_203 . V_208 ) ;
if ( V_205 < 0 )
V_75 = V_205 ;
else
* V_201 = V_203 . V_55 + V_205 ;
V_206:
F_111 ( & V_203 ) ;
return V_75 ? : V_205 ;
}
static int
F_112 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
* V_209 = V_36 -> V_138 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_113 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_114 ( V_20 , V_209 ) ;
F_6 ( & V_20 -> V_76 ) ;
return V_75 ;
}
static int F_115 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 = 0 ;
F_78 ( V_36 ) ;
F_116 ( & V_36 -> V_211 . V_212 ) ;
if ( F_117 ( V_20 ) ) {
T_9 V_213 = F_118 ( V_214 ) ;
T_9 V_215 = F_118 ( V_216 ) ;
F_9 ( V_16 , L_113 , ( V_213 >> 8 ) & 0xf ) ;
F_9 ( V_16 , L_114 , V_213 & 0x3f ) ;
F_9 ( V_16 , L_115 , ( V_215 & V_217 ) >>
V_218 ) ;
F_9 ( V_16 , L_116 ,
( V_215 & V_219 ) >> V_220 ) ;
} else if ( F_93 ( V_20 ) || F_81 ( V_20 ) ) {
T_4 V_221 ;
F_4 ( & V_36 -> V_211 . V_222 ) ;
V_221 = F_119 ( V_36 , V_223 ) ;
F_9 ( V_16 , L_117 , V_221 ) ;
F_9 ( V_16 , L_118 , V_36 -> V_224 ) ;
F_9 ( V_16 , L_119 ,
F_120 ( V_36 , ( V_221 >> 8 ) & 0xff ) ) ;
F_9 ( V_16 , L_120 ,
F_120 ( V_36 , V_36 -> V_211 . V_225 ) ) ;
F_9 ( V_16 , L_121 ,
F_120 ( V_36 , V_36 -> V_211 . V_226 ) ) ;
F_9 ( V_16 , L_122 ,
F_120 ( V_36 , V_36 -> V_211 . V_227 ) ) ;
F_9 ( V_16 , L_123 ,
F_120 ( V_36 , V_36 -> V_211 . V_228 ) ) ;
F_9 ( V_16 ,
L_124 ,
F_120 ( V_36 , V_36 -> V_211 . V_229 ) ) ;
F_6 ( & V_36 -> V_211 . V_222 ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
T_4 V_230 ;
T_4 V_231 ;
T_4 V_232 ;
T_4 V_233 , V_234 , V_235 ;
T_4 V_236 , V_237 , V_238 ;
T_4 V_239 , V_240 , V_241 ;
T_4 V_242 , V_243 , V_244 ;
T_4 V_245 , V_246 , V_247 , V_248 , V_249 ;
int V_226 ;
V_230 = F_70 ( V_250 ) ;
if ( F_121 ( V_20 ) ) {
V_232 = F_70 ( V_251 ) ;
V_231 = F_70 ( V_252 ) ;
} else {
V_232 = F_70 ( V_253 ) ;
V_231 = F_70 ( V_254 ) ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
goto V_206;
F_122 ( V_36 , V_255 ) ;
V_238 = F_70 ( V_256 ) ;
if ( F_123 ( V_20 ) )
V_238 >>= 23 ;
else {
V_238 &= ~ V_257 ;
if ( F_124 ( V_20 ) || F_125 ( V_20 ) )
V_238 >>= 24 ;
else
V_238 >>= 25 ;
}
V_238 = F_120 ( V_36 , V_238 ) ;
V_233 = F_70 ( V_258 ) ;
V_234 = F_70 ( V_259 ) ;
V_235 = F_70 ( V_260 ) ;
V_236 = F_70 ( V_261 ) ;
V_239 = F_70 ( V_262 ) ;
V_240 = F_70 ( V_263 ) ;
V_241 = F_70 ( V_264 ) ;
V_242 = F_70 ( V_265 ) ;
V_243 = F_70 ( V_266 ) ;
V_244 = F_70 ( V_267 ) ;
if ( F_123 ( V_20 ) )
V_237 = ( V_236 & V_268 ) >> V_269 ;
else if ( F_124 ( V_20 ) || F_125 ( V_20 ) )
V_237 = ( V_236 & V_270 ) >> V_271 ;
else
V_237 = ( V_236 & V_272 ) >> V_273 ;
V_237 = F_120 ( V_36 , V_237 ) ;
F_126 ( V_36 , V_255 ) ;
F_6 ( & V_20 -> V_76 ) ;
if ( F_127 ( V_20 ) || F_128 ( V_20 ) ) {
V_245 = F_70 ( V_174 ) ;
V_246 = F_70 ( V_176 ) ;
V_247 = F_70 ( V_274 ) ;
V_248 = F_70 ( V_175 ) ;
V_249 = F_70 ( V_275 ) ;
} else {
V_245 = F_70 ( F_86 ( 2 ) ) ;
V_246 = F_70 ( F_84 ( 2 ) ) ;
V_247 = F_70 ( F_129 ( 2 ) ) ;
V_248 = F_70 ( F_85 ( 2 ) ) ;
V_249 = F_70 ( V_275 ) ;
}
F_9 ( V_16 , L_125 ,
V_245 , V_246 , V_247 , V_248 , V_249 ) ;
F_9 ( V_16 , L_126 , V_231 ) ;
F_9 ( V_16 , L_127 ,
( V_231 & ( F_123 ( V_20 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_9 ( V_16 , L_128 ,
V_231 & 0xff ) ;
F_9 ( V_16 , L_129 ,
V_230 & 0xff ) ;
F_9 ( V_16 , L_130 , V_236 ) ;
F_9 ( V_16 , L_131 , V_233 ) ;
F_9 ( V_16 , L_132 , V_234 ) ;
F_9 ( V_16 , L_133 , V_235 ) ;
F_9 ( V_16 , L_134 , V_238 ) ;
F_9 ( V_16 , L_135 , V_237 ) ;
F_9 ( V_16 , L_136 , V_239 &
V_276 ) ;
F_9 ( V_16 , L_137 , V_240 &
V_277 ) ;
F_9 ( V_16 , L_138 , V_241 &
V_277 ) ;
F_9 ( V_16 , L_139 ,
V_36 -> V_211 . V_278 ) ;
F_9 ( V_16 , L_140 , V_242 &
V_279 ) ;
F_9 ( V_16 , L_141 , V_243 &
V_277 ) ;
F_9 ( V_16 , L_142 , V_244 &
V_277 ) ;
F_9 ( V_16 , L_143 ,
V_36 -> V_211 . V_280 ) ;
V_226 = ( F_121 ( V_20 ) ? V_232 >> 0 :
V_232 >> 16 ) & 0xff ;
V_226 *= ( F_130 ( V_20 ) || F_131 ( V_20 ) ?
V_281 : 1 ) ;
F_9 ( V_16 , L_144 ,
F_120 ( V_36 , V_226 ) ) ;
V_226 = ( V_232 & 0xff00 ) >> 8 ;
V_226 *= ( F_130 ( V_20 ) || F_131 ( V_20 ) ?
V_281 : 1 ) ;
F_9 ( V_16 , L_145 ,
F_120 ( V_36 , V_226 ) ) ;
V_226 = ( F_121 ( V_20 ) ? V_232 >> 16 :
V_232 >> 0 ) & 0xff ;
V_226 *= ( F_130 ( V_20 ) || F_131 ( V_20 ) ?
V_281 : 1 ) ;
F_9 ( V_16 , L_146 ,
F_120 ( V_36 , V_226 ) ) ;
F_9 ( V_16 , L_147 ,
F_120 ( V_36 , V_36 -> V_211 . V_226 ) ) ;
F_9 ( V_16 , L_148 ,
F_120 ( V_36 , V_36 -> V_211 . V_225 ) ) ;
F_9 ( V_16 , L_149 , V_237 ) ;
F_9 ( V_16 , L_150 ,
F_120 ( V_36 , V_36 -> V_211 . V_228 ) ) ;
F_9 ( V_16 , L_151 ,
F_120 ( V_36 , V_36 -> V_211 . V_227 ) ) ;
F_9 ( V_16 , L_152 ,
F_120 ( V_36 , V_36 -> V_211 . V_226 ) ) ;
F_9 ( V_16 ,
L_124 ,
F_120 ( V_36 , V_36 -> V_211 . V_229 ) ) ;
} else {
F_27 ( V_16 , L_153 ) ;
}
F_9 ( V_16 , L_154 , V_36 -> V_282 ) ;
F_9 ( V_16 , L_155 , V_36 -> V_283 ) ;
F_9 ( V_16 , L_156 , V_36 -> V_284 ) ;
V_206:
F_79 ( V_36 ) ;
return V_75 ;
}
static int F_132 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
T_2 V_285 [ V_286 ] ;
T_4 V_148 [ V_286 ] ;
int V_41 ;
if ( ! V_287 . V_288 ) {
F_9 ( V_16 , L_157 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_24 (ring, dev_priv, i) {
V_148 [ V_41 ] = V_39 -> V_139 ( V_39 , false ) ;
V_285 [ V_41 ] = F_133 ( V_39 ) ;
}
F_79 ( V_36 ) ;
if ( F_134 ( & V_36 -> V_289 . V_290 ) ) {
F_9 ( V_16 , L_158 ,
F_135 ( V_36 -> V_289 . V_290 . V_291 . V_292 -
V_149 ) ) ;
} else
F_9 ( V_16 , L_159 ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_160 , V_39 -> V_52 ) ;
F_9 ( V_16 , L_161 ,
V_39 -> V_293 . V_148 , V_148 [ V_41 ] ) ;
F_9 ( V_16 , L_162 ,
( long long ) V_39 -> V_293 . V_285 ,
( long long ) V_285 [ V_41 ] ) ;
F_9 ( V_16 , L_163 ,
( long long ) V_39 -> V_293 . V_294 ) ;
F_9 ( V_16 , L_164 , V_39 -> V_293 . V_295 ) ;
F_9 ( V_16 , L_165 , V_39 -> V_293 . V_296 ) ;
}
return 0 ;
}
static int F_136 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_297 , V_298 ;
T_9 V_299 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
V_297 = F_70 ( V_300 ) ;
V_298 = F_70 ( V_301 ) ;
V_299 = F_118 ( V_302 ) ;
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_166 , F_137 ( V_297 & V_303 ) ) ;
F_9 ( V_16 , L_167 ,
( V_297 & V_304 ) >>
V_305 ) ;
F_9 ( V_16 , L_168 ,
F_137 ( V_297 & V_306 ) ) ;
F_9 ( V_16 , L_169 ,
F_137 ( V_297 & V_307 ) ) ;
F_9 ( V_16 , L_170 ,
F_137 ( V_297 & V_308 ) ) ;
F_9 ( V_16 , L_171 ,
( V_297 & V_309 ) >> V_310 ) ;
F_9 ( V_16 , L_172 ,
( V_297 & V_311 ) >> V_312 ) ;
F_9 ( V_16 , L_173 , ( V_297 & V_313 ) ) ;
F_9 ( V_16 , L_174 , ( V_299 & 0x3f ) ) ;
F_9 ( V_16 , L_175 , ( ( V_299 >> 8 ) & 0x3f ) ) ;
F_9 ( V_16 , L_176 ,
F_137 ( ! ( V_298 & V_314 ) ) ) ;
F_27 ( V_16 , L_177 ) ;
switch ( V_298 & V_315 ) {
case V_316 :
F_27 ( V_16 , L_178 ) ;
break;
case V_317 :
F_27 ( V_16 , L_179 ) ;
break;
case V_318 :
F_27 ( V_16 , L_180 ) ;
break;
case V_319 :
F_27 ( V_16 , L_181 ) ;
break;
case V_320 :
F_27 ( V_16 , L_182 ) ;
break;
case V_321 :
F_27 ( V_16 , L_183 ) ;
break;
default:
F_27 ( V_16 , L_184 ) ;
break;
}
return 0 ;
}
static int F_138 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_322 * V_323 ;
int V_41 ;
F_65 ( & V_36 -> V_324 . V_325 ) ;
F_139 (fw_domain, dev_priv, i) {
F_9 ( V_16 , L_185 ,
F_140 ( V_41 ) ,
V_323 -> V_326 ) ;
}
F_73 ( & V_36 -> V_324 . V_325 ) ;
return 0 ;
}
static int F_141 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_327 , V_328 , V_329 ;
F_78 ( V_36 ) ;
V_329 = F_70 ( V_330 ) ;
V_327 = F_70 ( V_258 ) ;
V_328 = F_70 ( V_331 ) ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_186 ,
F_137 ( V_327 & V_332 ) ) ;
F_9 ( V_16 , L_187 ,
F_137 ( V_327 & V_333 ) ) ;
F_9 ( V_16 , L_168 ,
F_137 ( V_327 & V_333 ) ) ;
F_9 ( V_16 , L_169 ,
F_137 ( ( V_327 & V_334 ) ==
V_335 ) ) ;
F_9 ( V_16 , L_188 ,
F_137 ( V_328 & ( V_336 |
F_142 ( 1 ) ) ) ) ;
F_9 ( V_16 , L_189 ,
( V_329 & V_337 ) ? L_190 : L_191 ) ;
F_9 ( V_16 , L_192 ,
( V_329 & V_338 ) ? L_190 : L_191 ) ;
F_9 ( V_16 , L_193 ,
F_70 ( V_339 ) ) ;
F_9 ( V_16 , L_194 ,
F_70 ( V_340 ) ) ;
return F_138 ( V_16 , NULL ) ;
}
static int F_143 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_327 , V_341 , V_328 , V_342 = 0 ;
unsigned V_343 ;
int V_74 = 0 , V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
F_65 ( & V_36 -> V_324 . V_325 ) ;
V_343 = V_36 -> V_324 . V_323 [ V_344 ] . V_326 ;
F_73 ( & V_36 -> V_324 . V_325 ) ;
if ( V_343 ) {
F_27 ( V_16 , L_195
L_196 ) ;
} else {
while ( V_74 ++ < 50 && ( F_144 ( V_345 ) & 1 ) )
F_145 ( 10 ) ;
F_9 ( V_16 , L_197 , F_137 ( V_74 < 51 ) ) ;
}
V_341 = F_146 ( V_346 ) ;
F_147 ( false , V_346 , V_341 , 4 , true ) ;
V_327 = F_70 ( V_258 ) ;
V_328 = F_70 ( V_331 ) ;
F_6 ( & V_20 -> V_76 ) ;
F_4 ( & V_36 -> V_211 . V_222 ) ;
F_148 ( V_36 , V_347 , & V_342 ) ;
F_6 ( & V_36 -> V_211 . V_222 ) ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_186 ,
F_137 ( V_327 & V_332 ) ) ;
F_9 ( V_16 , L_168 ,
F_137 ( V_327 & V_333 ) ) ;
F_9 ( V_16 , L_169 ,
F_137 ( ( V_327 & V_334 ) ==
V_335 ) ) ;
F_9 ( V_16 , L_198 ,
F_137 ( V_328 & V_348 ) ) ;
F_9 ( V_16 , L_188 ,
F_137 ( V_328 & V_349 ) ) ;
F_9 ( V_16 , L_199 ,
F_137 ( V_328 & V_350 ) ) ;
F_9 ( V_16 , L_200 ,
F_137 ( V_328 & V_351 ) ) ;
F_27 ( V_16 , L_201 ) ;
switch ( V_341 & V_352 ) {
case V_353 :
if ( V_341 & V_354 )
F_27 ( V_16 , L_202 ) ;
else
F_27 ( V_16 , L_178 ) ;
break;
case V_355 :
F_27 ( V_16 , L_203 ) ;
break;
case V_356 :
F_27 ( V_16 , L_204 ) ;
break;
case V_357 :
F_27 ( V_16 , L_205 ) ;
break;
default:
F_27 ( V_16 , L_206 ) ;
break;
}
F_9 ( V_16 , L_207 ,
F_137 ( V_341 & V_354 ) ) ;
F_9 ( V_16 , L_208 ,
F_70 ( V_358 ) ) ;
F_9 ( V_16 , L_209 ,
F_70 ( V_359 ) ) ;
F_9 ( V_16 , L_210 ,
F_70 ( V_360 ) ) ;
F_9 ( V_16 , L_211 ,
F_70 ( V_361 ) ) ;
F_9 ( V_16 , L_212 ,
F_149 ( ( ( V_342 >> 0 ) & 0xff ) ) ) ;
F_9 ( V_16 , L_213 ,
F_149 ( ( ( V_342 >> 8 ) & 0xff ) ) ) ;
F_9 ( V_16 , L_214 ,
F_149 ( ( ( V_342 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_150 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
if ( F_93 ( V_20 ) || F_81 ( V_20 ) )
return F_141 ( V_16 ) ;
else if ( F_8 ( V_20 ) -> V_23 >= 6 )
return F_143 ( V_16 ) ;
else
return F_136 ( V_16 ) ;
}
static int F_151 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
F_9 ( V_16 , L_215 ,
V_36 -> V_362 . V_363 ) ;
F_9 ( V_16 , L_216 ,
V_36 -> V_362 . V_364 ) ;
return 0 ;
}
static int F_152 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_153 ( V_20 ) ) {
F_27 ( V_16 , L_217 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_4 ( & V_36 -> V_365 . V_325 ) ;
if ( F_154 ( V_36 ) )
F_27 ( V_16 , L_218 ) ;
else
F_9 ( V_16 , L_219 ,
V_36 -> V_365 . V_366 ) ;
if ( F_8 ( V_36 ) -> V_23 >= 7 )
F_9 ( V_16 , L_220 ,
F_137 ( F_70 ( V_367 ) &
V_368 ) ) ;
F_6 ( & V_36 -> V_365 . V_325 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_155 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 7 || ! F_153 ( V_20 ) )
return - V_369 ;
* V_209 = V_36 -> V_365 . V_370 ;
return 0 ;
}
static int F_156 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_371 ;
if ( F_8 ( V_20 ) -> V_23 < 7 || ! F_153 ( V_20 ) )
return - V_369 ;
F_4 ( & V_36 -> V_365 . V_325 ) ;
V_371 = F_70 ( V_372 ) ;
V_36 -> V_365 . V_370 = V_209 ;
F_157 ( V_372 , V_209 ?
( V_371 | V_373 ) :
( V_371 & ~ V_373 ) ) ;
F_6 ( & V_36 -> V_365 . V_325 ) ;
return 0 ;
}
static int F_158 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_159 ( V_20 ) ) {
F_27 ( V_16 , L_221 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_9 ( V_16 , L_222 ,
F_137 ( V_287 . V_374 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 ) {
F_27 ( V_16 , L_223 ) ;
} else {
if ( F_70 ( V_375 ) & V_376 )
F_27 ( V_16 , L_224 ) ;
else
F_27 ( V_16 , L_225 ) ;
}
F_79 ( V_36 ) ;
return 0 ;
}
static int F_160 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_377 = false ;
F_78 ( V_36 ) ;
if ( F_94 ( V_20 ) )
V_377 = F_70 ( V_378 ) & V_379 ;
else if ( F_161 ( V_20 ) || F_162 ( V_20 ) ||
F_163 ( V_20 ) || F_164 ( V_20 ) )
V_377 = F_70 ( V_380 ) & V_381 ;
else if ( F_165 ( V_20 ) )
V_377 = F_70 ( V_382 ) & V_383 ;
else if ( F_166 ( V_20 ) )
V_377 = F_70 ( V_384 ) & V_385 ;
else if ( F_93 ( V_20 ) || F_81 ( V_20 ) )
V_377 = F_70 ( V_386 ) & V_387 ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_226 ,
V_377 ? L_227 : L_228 ) ;
return 0 ;
}
static int F_167 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
unsigned long V_388 , V_389 , V_390 ;
int V_75 ;
if ( ! F_117 ( V_20 ) )
return - V_369 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_388 = F_168 ( V_36 ) ;
V_389 = F_169 ( V_36 ) ;
V_390 = F_170 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_229 , V_388 ) ;
F_9 ( V_16 , L_230 , V_389 ) ;
F_9 ( V_16 , L_231 , V_390 ) ;
F_9 ( V_16 , L_232 , V_389 + V_390 ) ;
return 0 ;
}
static int F_171 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 = 0 ;
int V_391 , V_392 ;
unsigned int V_393 , V_394 ;
if ( ! F_172 ( V_20 ) ) {
F_27 ( V_16 , L_233 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_116 ( & V_36 -> V_211 . V_212 ) ;
V_75 = F_32 ( & V_36 -> V_211 . V_222 ) ;
if ( V_75 )
goto V_206;
if ( F_130 ( V_20 ) || F_131 ( V_20 ) ) {
V_394 =
V_36 -> V_211 . V_395 / V_281 ;
V_393 =
V_36 -> V_211 . V_396 / V_281 ;
} else {
V_394 = V_36 -> V_211 . V_395 ;
V_393 = V_36 -> V_211 . V_396 ;
}
F_27 ( V_16 , L_234 ) ;
for ( V_391 = V_394 ; V_391 <= V_393 ; V_391 ++ ) {
V_392 = V_391 ;
F_148 ( V_36 ,
V_397 ,
& V_392 ) ;
F_9 ( V_16 , L_235 ,
F_120 ( V_36 , ( V_391 *
( F_130 ( V_20 ) || F_131 ( V_20 ) ?
V_281 : 1 ) ) ) ,
( ( V_392 >> 0 ) & 0xff ) * 100 ,
( ( V_392 >> 8 ) & 0xff ) * 100 ) ;
}
F_6 ( & V_36 -> V_211 . V_222 ) ;
V_206:
F_79 ( V_36 ) ;
return V_75 ;
}
static int F_173 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_398 * V_399 = & V_36 -> V_399 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
goto V_206;
if ( V_399 -> V_400 )
F_174 ( V_16 , V_399 -> V_400 , V_401 ) ;
F_6 ( & V_20 -> V_76 ) ;
V_206:
return 0 ;
}
static int F_175 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_398 * V_399 = & V_36 -> V_399 ;
if ( V_399 -> V_402 )
F_174 ( V_16 , V_399 -> V_402 , V_399 -> V_403 ) ;
return 0 ;
}
static int F_176 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_404 * V_405 = NULL ;
struct V_406 * V_407 ;
#ifdef F_177
if ( F_23 ( V_20 ) -> V_408 ) {
V_405 = F_178 ( F_23 ( V_20 ) -> V_408 -> V_409 . V_410 ) ;
F_9 ( V_16 , L_236 ,
V_405 -> V_37 . V_411 ,
V_405 -> V_37 . V_412 ,
V_405 -> V_37 . V_413 ,
V_405 -> V_37 . V_414 ,
V_405 -> V_37 . V_415 [ 0 ] ,
F_66 ( & V_405 -> V_37 . V_416 . V_416 ) ) ;
F_22 ( V_16 , V_405 -> V_25 ) ;
F_30 ( V_16 , '\n' ) ;
}
#endif
F_4 ( & V_20 -> V_417 . V_418 ) ;
F_179 (drm_fb, dev) {
struct V_404 * V_410 = F_178 ( V_407 ) ;
if ( V_410 == V_405 )
continue;
F_9 ( V_16 , L_237 ,
V_410 -> V_37 . V_411 ,
V_410 -> V_37 . V_412 ,
V_410 -> V_37 . V_413 ,
V_410 -> V_37 . V_414 ,
V_410 -> V_37 . V_415 [ 0 ] ,
F_66 ( & V_410 -> V_37 . V_416 . V_416 ) ) ;
F_22 ( V_16 , V_410 -> V_25 ) ;
F_30 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_417 . V_418 ) ;
return 0 ;
}
static void F_180 ( struct V_15 * V_16 ,
struct V_419 * V_420 )
{
F_9 ( V_16 , L_238 ,
V_420 -> V_421 , V_420 -> V_68 , V_420 -> V_422 ,
V_420 -> V_423 ) ;
}
static int F_181 ( struct V_15 * V_16 , void * V_210 )
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
if ( ! V_287 . V_424 &&
V_63 -> V_64 . V_425 == NULL )
continue;
F_27 ( V_16 , L_239 ) ;
F_29 ( V_16 , V_63 ) ;
F_24 (ring, dev_priv, i) {
if ( V_39 -> V_426 == V_63 )
F_9 ( V_16 , L_240 ,
V_39 -> V_52 ) ;
}
if ( V_287 . V_424 ) {
F_30 ( V_16 , '\n' ) ;
F_24 (ring, dev_priv, i) {
struct V_24 * V_427 =
V_63 -> V_428 [ V_41 ] . V_429 ;
struct V_419 * V_420 =
V_63 -> V_428 [ V_41 ] . V_420 ;
F_9 ( V_16 , L_241 , V_39 -> V_52 ) ;
if ( V_427 )
F_22 ( V_16 , V_427 ) ;
if ( V_420 )
F_180 ( V_16 , V_420 ) ;
F_30 ( V_16 , '\n' ) ;
}
} else {
F_22 ( V_16 , V_63 -> V_64 . V_425 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static void F_182 ( struct V_15 * V_16 ,
struct V_38 * V_39 ,
struct V_24 * V_427 )
{
struct V_430 * V_430 ;
T_10 * V_431 ;
int V_102 ;
unsigned long V_432 = 0 ;
if ( V_427 == NULL ) {
F_9 ( V_16 , L_242 ,
V_39 -> V_52 ) ;
return;
}
F_9 ( V_16 , L_243 , V_39 -> V_52 ,
F_183 ( V_427 ) ) ;
if ( ! F_44 ( V_427 ) )
F_27 ( V_16 , L_244 ) ;
else
V_432 = F_184 ( V_427 ) ;
if ( F_185 ( V_427 ) ) {
F_27 ( V_16 , L_245 ) ;
return;
}
V_430 = F_186 ( V_427 , V_433 ) ;
if ( ! F_187 ( V_430 == NULL ) ) {
V_431 = F_188 ( V_430 ) ;
for ( V_102 = 0 ; V_102 < 0x600 / sizeof( T_4 ) / 4 ; V_102 += 4 ) {
F_9 ( V_16 , L_246 ,
V_432 + 4096 + ( V_102 * 4 ) ,
V_431 [ V_102 ] , V_431 [ V_102 + 1 ] ,
V_431 [ V_102 + 2 ] , V_431 [ V_102 + 3 ] ) ;
}
F_189 ( V_431 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
static int F_190 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_62 * V_63 ;
int V_75 , V_41 ;
if ( ! V_287 . V_424 ) {
F_9 ( V_16 , L_247 ) ;
return 0 ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_19 (ctx, &dev_priv->context_list, link) {
F_24 (ring, dev_priv, i) {
if ( V_39 -> V_426 != V_63 )
F_182 ( V_16 , V_39 ,
V_63 -> V_428 [ V_41 ] . V_429 ) ;
}
}
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_191 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
T_4 V_434 ;
T_11 V_435 ;
T_11 V_436 ;
T_4 V_437 ;
T_4 V_438 ;
struct V_67 * V_439 ;
int V_440 , V_41 ;
int V_75 ;
if ( ! V_287 . V_424 ) {
F_27 ( V_16 , L_247 ) ;
return 0 ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
F_24 (ring, dev_priv, ring_id) {
struct V_145 * V_441 = NULL ;
int V_74 = 0 ;
unsigned long V_442 ;
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
V_437 = F_70 ( F_192 ( V_39 ) ) ;
V_438 = F_70 ( F_193 ( V_39 ) ) ;
F_9 ( V_16 , L_249 ,
V_437 , V_438 ) ;
V_434 = F_70 ( F_194 ( V_39 ) ) ;
F_9 ( V_16 , L_250 , V_434 ) ;
V_435 = V_39 -> V_443 ;
V_436 = V_434 & 0x07 ;
if ( V_435 > V_436 )
V_436 += 6 ;
F_9 ( V_16 , L_251 ,
V_435 , V_436 ) ;
for ( V_41 = 0 ; V_41 < 6 ; V_41 ++ ) {
V_437 = F_70 ( F_195 ( V_39 , V_41 ) ) ;
V_438 = F_70 ( F_196 ( V_39 , V_41 ) ) ;
F_9 ( V_16 , L_252 ,
V_41 , V_437 , V_438 ) ;
}
F_197 ( & V_39 -> V_444 , V_442 ) ;
F_198 (cursor, &ring->execlist_queue)
V_74 ++ ;
V_441 = F_199 ( & V_39 -> V_445 ,
struct V_145 , V_446 ) ;
F_200 ( & V_39 -> V_444 , V_442 ) ;
F_9 ( V_16 , L_253 , V_74 ) ;
if ( V_441 ) {
struct V_24 * V_427 ;
V_427 = V_441 -> V_63 -> V_428 [ V_440 ] . V_429 ;
F_9 ( V_16 , L_254 ,
F_183 ( V_427 ) ) ;
F_9 ( V_16 , L_255 ,
V_441 -> V_422 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static const char * F_201 ( unsigned V_447 )
{
switch ( V_447 ) {
case V_448 :
return L_256 ;
case V_449 :
return L_257 ;
case V_450 :
return L_258 ;
case V_451 :
return L_259 ;
case V_452 :
return L_260 ;
case V_453 :
return L_261 ;
case V_454 :
return L_262 ;
case V_455 :
return L_263 ;
}
return L_264 ;
}
static int F_202 ( struct V_15 * V_16 , void * V_17 )
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
F_201 ( V_36 -> V_111 . V_456 ) ) ;
F_9 ( V_16 , L_266 ,
F_201 ( V_36 -> V_111 . V_457 ) ) ;
if ( F_203 ( V_20 ) || F_204 ( V_20 ) ) {
F_9 ( V_16 , L_267 ,
F_70 ( V_458 ) ) ;
F_9 ( V_16 , L_268 ,
F_70 ( V_459 ) ) ;
F_9 ( V_16 , L_269 ,
F_118 ( V_460 ) ) ;
F_9 ( V_16 , L_270 ,
F_118 ( V_461 ) ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
F_9 ( V_16 , L_271 ,
F_70 ( V_462 ) ) ;
F_9 ( V_16 , L_272 ,
F_70 ( V_463 ) ) ;
F_9 ( V_16 , L_273 ,
F_70 ( V_464 ) ) ;
F_9 ( V_16 , L_274 ,
F_70 ( V_465 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 )
F_9 ( V_16 , L_275 ,
F_70 ( V_466 ) ) ;
else
F_9 ( V_16 , L_276 ,
F_70 ( V_467 ) ) ;
F_9 ( V_16 , L_277 ,
F_70 ( V_468 ) ) ;
}
if ( V_36 -> V_469 & V_470 )
F_27 ( V_16 , L_278 ) ;
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_205 ( int V_88 , void * V_89 , void * V_17 )
{
struct V_62 * V_63 = V_89 ;
struct V_15 * V_16 = V_17 ;
struct V_95 * V_96 = V_63 -> V_96 ;
if ( ! V_96 ) {
F_9 ( V_16 , L_279 ,
V_63 -> V_471 ) ;
return 0 ;
}
if ( F_206 ( V_63 ) )
F_27 ( V_16 , L_280 ) ;
else
F_9 ( V_16 , L_281 , V_63 -> V_471 ) ;
V_96 -> V_472 ( V_96 , V_16 ) ;
return 0 ;
}
static void F_207 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_95 * V_96 = V_36 -> V_111 . V_473 ;
int V_210 , V_41 ;
if ( ! V_96 )
return;
F_24 (ring, dev_priv, unused) {
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
T_2 V_474 = F_70 ( F_208 ( V_39 , V_41 ) ) ;
V_474 <<= 32 ;
V_474 |= F_70 ( F_209 ( V_39 , V_41 ) ) ;
F_9 ( V_16 , L_282 , V_41 , V_474 ) ;
}
}
}
static void F_210 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_41 ;
if ( F_8 ( V_20 ) -> V_23 == 6 )
F_9 ( V_16 , L_283 , F_70 ( V_475 ) ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
if ( F_8 ( V_20 ) -> V_23 == 7 )
F_9 ( V_16 , L_283 , F_70 ( F_211 ( V_39 ) ) ) ;
F_9 ( V_16 , L_284 , F_70 ( F_212 ( V_39 ) ) ) ;
F_9 ( V_16 , L_285 , F_70 ( F_213 ( V_39 ) ) ) ;
F_9 ( V_16 , L_286 , F_70 ( F_214 ( V_39 ) ) ) ;
}
if ( V_36 -> V_111 . V_473 ) {
struct V_95 * V_96 = V_36 -> V_111 . V_473 ;
F_27 ( V_16 , L_287 ) ;
F_9 ( V_16 , L_288 , V_96 -> V_476 . V_37 . V_432 ) ;
V_96 -> V_472 ( V_96 , V_16 ) ;
}
F_9 ( V_16 , L_289 , F_70 ( V_477 ) ) ;
}
static int F_215 ( struct V_15 * V_16 , void * V_17 )
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
F_207 ( V_16 , V_20 ) ;
else if ( F_8 ( V_20 ) -> V_23 >= 6 )
F_210 ( V_16 , V_20 ) ;
F_52 (file, &dev->filelist, lhead) {
struct V_478 * V_98 = V_110 -> V_119 ;
struct V_117 * V_118 ;
V_118 = F_216 ( V_110 -> V_122 , V_123 ) ;
if ( ! V_118 ) {
V_75 = - V_479 ;
goto V_480;
}
F_9 ( V_16 , L_290 , V_118 -> V_124 ) ;
F_217 ( V_118 ) ;
F_54 ( & V_98 -> V_481 , F_205 ,
( void * ) ( unsigned long ) V_16 ) ;
}
V_480:
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return V_75 ;
}
static int F_218 ( struct V_35 * V_287 )
{
struct V_38 * V_39 ;
int V_74 = 0 ;
int V_41 ;
F_24 (ring, i915, i)
V_74 += V_39 -> V_482 ;
return V_74 ;
}
static int F_219 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_109 * V_110 ;
F_9 ( V_16 , L_291 , V_36 -> V_211 . V_483 ) ;
F_9 ( V_16 , L_292 , V_36 -> V_111 . V_484 ) ;
F_9 ( V_16 , L_293 , F_218 ( V_36 ) ) ;
F_9 ( V_16 , L_294 ,
F_120 ( V_36 , V_36 -> V_211 . V_225 ) ,
F_120 ( V_36 , V_36 -> V_211 . V_227 ) ,
F_120 ( V_36 , V_36 -> V_211 . V_395 ) ,
F_120 ( V_36 , V_36 -> V_211 . V_396 ) ,
F_120 ( V_36 , V_36 -> V_211 . V_226 ) ) ;
F_53 ( & V_36 -> V_211 . V_485 ) ;
F_52 (file, &dev->filelist, lhead) {
struct V_478 * V_98 = V_110 -> V_119 ;
struct V_117 * V_118 ;
F_56 () ;
V_118 = F_57 ( V_110 -> V_122 , V_123 ) ;
F_9 ( V_16 , L_295 ,
V_118 ? V_118 -> V_124 : L_43 ,
V_118 ? V_118 -> V_122 : - 1 ,
V_98 -> V_211 . V_486 ,
F_38 ( & V_98 -> V_211 . V_487 ) ? L_13 : L_296 ) ;
F_58 () ;
}
F_9 ( V_16 , L_297 ,
V_36 -> V_211 . V_488 . V_486 ,
F_38 ( & V_36 -> V_211 . V_488 . V_487 ) ? L_13 : L_296 ) ;
F_9 ( V_16 , L_298 ,
V_36 -> V_211 . V_489 . V_486 ,
F_38 ( & V_36 -> V_211 . V_489 . V_487 ) ? L_13 : L_296 ) ;
F_9 ( V_16 , L_299 , V_36 -> V_211 . V_486 ) ;
F_55 ( & V_36 -> V_211 . V_485 ) ;
return 0 ;
}
static int F_220 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
F_9 ( V_16 , L_300 , F_137 ( F_221 ( V_20 ) ) ) ;
F_9 ( V_16 , L_301 , V_36 -> V_490 ) ;
return 0 ;
}
static int F_222 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_35 * V_36 = V_7 -> V_2 -> V_20 -> V_69 ;
struct V_491 * V_492 = & V_36 -> V_493 . V_492 ;
T_4 V_494 , V_41 ;
if ( ! F_223 ( V_36 -> V_20 ) )
return 0 ;
F_9 ( V_16 , L_302 ) ;
F_9 ( V_16 , L_303 ,
V_492 -> V_495 ) ;
F_9 ( V_16 , L_304 ,
F_224 ( V_492 -> V_496 ) ) ;
F_9 ( V_16 , L_305 ,
F_224 ( V_492 -> V_497 ) ) ;
F_9 ( V_16 , L_306 ,
V_492 -> V_498 , V_492 -> V_499 ) ;
F_9 ( V_16 , L_307 ,
V_492 -> V_500 , V_492 -> V_501 ) ;
F_9 ( V_16 , L_308 ,
V_492 -> V_502 , V_492 -> V_503 ) ;
F_9 ( V_16 , L_309 ,
V_492 -> V_504 , V_492 -> V_505 ) ;
F_9 ( V_16 , L_310 ,
V_492 -> V_506 , V_492 -> V_507 ) ;
V_494 = F_70 ( V_508 ) ;
F_9 ( V_16 , L_311 , V_494 ) ;
F_9 ( V_16 , L_312 ,
( V_494 & V_509 ) >> V_510 ) ;
F_9 ( V_16 , L_313 ,
( V_494 & V_511 ) >> V_512 ) ;
F_9 ( V_16 , L_314 ,
( V_494 & V_513 ) >> V_514 ) ;
F_27 ( V_16 , L_315 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
F_9 ( V_16 , L_316 , V_41 , F_70 ( F_225 ( V_41 ) ) ) ;
return 0 ;
}
static void F_226 ( struct V_15 * V_16 ,
struct V_35 * V_36 ,
struct V_515 * V_516 )
{
struct V_38 * V_39 ;
T_12 V_517 = 0 ;
T_10 V_41 ;
F_9 ( V_16 , L_317 ,
V_516 -> V_518 , V_516 -> V_519 , V_516 -> V_520 ) ;
F_9 ( V_16 , L_318 ,
V_516 -> V_521 , V_516 -> V_522 , V_516 -> V_523 ) ;
F_9 ( V_16 , L_319 ,
V_516 -> V_524 , V_516 -> V_525 , V_516 -> V_526 ) ;
F_9 ( V_16 , L_320 , V_516 -> V_527 ) ;
F_9 ( V_16 , L_321 , V_516 -> V_528 ) ;
F_9 ( V_16 , L_322 , V_516 -> V_529 ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_323 ,
V_516 -> V_530 [ V_41 ] ,
V_39 -> V_52 ) ;
V_517 += V_516 -> V_530 [ V_41 ] ;
}
F_9 ( V_16 , L_324 , V_517 ) ;
}
static int F_227 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_531 V_493 ;
struct V_515 V_516 = {} ;
struct V_38 * V_39 ;
enum V_532 V_41 ;
T_2 V_92 = 0 ;
if ( ! F_228 ( V_36 -> V_20 ) )
return 0 ;
if ( F_32 ( & V_20 -> V_76 ) )
return 0 ;
V_493 = V_36 -> V_493 ;
if ( V_493 . V_533 )
V_516 = * V_493 . V_533 ;
F_6 ( & V_20 -> V_76 ) ;
F_9 ( V_16 , L_325 , V_493 . V_534 ) ;
F_9 ( V_16 , L_326 , V_493 . V_535 ) ;
F_9 ( V_16 , L_327 , V_493 . V_536 ) ;
F_9 ( V_16 , L_328 , V_493 . V_537 ) ;
F_9 ( V_16 , L_329 , V_493 . V_538 ) ;
F_9 ( V_16 , L_330 ) ;
F_24 (ring, dev_priv, i) {
F_9 ( V_16 , L_331 ,
V_39 -> V_52 , V_493 . V_530 [ V_41 ] ,
V_493 . V_539 [ V_41 ] , V_493 . V_539 [ V_41 ] ) ;
V_92 += V_493 . V_530 [ V_41 ] ;
}
F_9 ( V_16 , L_332 , L_333 , V_92 ) ;
F_9 ( V_16 , L_334 , V_493 . V_533 ) ;
F_226 ( V_16 , V_36 , & V_516 ) ;
return 0 ;
}
static int F_229 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_540 = V_36 -> V_493 . V_540 ;
T_4 * log ;
int V_41 = 0 , V_541 ;
if ( ! V_540 )
return 0 ;
for ( V_541 = 0 ; V_541 < V_540 -> V_37 . V_31 / V_542 ; V_541 ++ ) {
log = F_188 ( F_186 ( V_540 , V_541 ) ) ;
for ( V_41 = 0 ; V_41 < V_542 / sizeof( T_4 ) ; V_41 += 4 )
F_9 ( V_16 , L_335 ,
* ( log + V_41 ) , * ( log + V_41 + 1 ) ,
* ( log + V_41 + 2 ) , * ( log + V_41 + 3 ) ) ;
F_189 ( log ) ;
}
F_30 ( V_16 , '\n' ) ;
return 0 ;
}
static int F_230 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_543 = 0 ;
T_4 V_544 [ 3 ] ;
enum V_128 V_128 ;
bool V_483 = false ;
if ( ! F_231 ( V_20 ) ) {
F_27 ( V_16 , L_336 ) ;
return 0 ;
}
F_78 ( V_36 ) ;
F_4 ( & V_36 -> V_545 . V_325 ) ;
F_9 ( V_16 , L_337 , F_137 ( V_36 -> V_545 . V_546 ) ) ;
F_9 ( V_16 , L_338 , F_137 ( V_36 -> V_545 . V_547 ) ) ;
F_9 ( V_16 , L_339 , F_137 ( ( bool ) V_36 -> V_545 . V_483 ) ) ;
F_9 ( V_16 , L_340 , F_137 ( V_36 -> V_545 . V_42 ) ) ;
F_9 ( V_16 , L_341 ,
V_36 -> V_545 . V_548 ) ;
F_9 ( V_16 , L_342 ,
F_137 ( F_232 ( & V_36 -> V_545 . V_131 . V_131 ) ) ) ;
if ( F_233 ( V_20 ) )
V_483 = F_70 ( V_549 ) & V_550 ;
else {
F_82 (dev_priv, pipe) {
V_544 [ V_128 ] = F_70 ( F_234 ( V_128 ) ) &
V_551 ;
if ( ( V_544 [ V_128 ] == V_552 ) ||
( V_544 [ V_128 ] == V_553 ) )
V_483 = true ;
}
}
F_9 ( V_16 , L_343 , F_137 ( V_483 ) ) ;
if ( ! F_233 ( V_20 ) )
F_82 (dev_priv, pipe) {
if ( ( V_544 [ V_128 ] == V_552 ) ||
( V_544 [ V_128 ] == V_553 ) )
F_9 ( V_16 , L_344 , F_63 ( V_128 ) ) ;
}
F_27 ( V_16 , L_30 ) ;
if ( F_124 ( V_20 ) || F_125 ( V_20 ) ) {
V_543 = F_70 ( V_554 ) &
V_555 ;
F_9 ( V_16 , L_345 , V_543 ) ;
}
F_6 ( & V_36 -> V_545 . V_325 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_235 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_556 * V_557 ;
struct V_558 * V_559 ;
struct V_560 * V_560 = NULL ;
int V_75 ;
T_11 V_561 [ 6 ] ;
F_236 ( V_20 ) ;
F_237 (dev, connector) {
if ( V_559 -> V_37 . V_562 != V_563 )
continue;
if ( ! V_559 -> V_37 . V_557 )
continue;
V_557 = F_238 ( V_559 -> V_37 . V_557 ) ;
if ( V_557 -> type != V_564 )
continue;
V_560 = F_239 ( & V_557 -> V_37 ) ;
V_75 = F_240 ( V_560 , V_561 ) ;
if ( V_75 )
goto V_206;
F_9 ( V_16 , L_346 ,
V_561 [ 0 ] , V_561 [ 1 ] , V_561 [ 2 ] ,
V_561 [ 3 ] , V_561 [ 4 ] , V_561 [ 5 ] ) ;
goto V_206;
}
V_75 = - V_369 ;
V_206:
F_241 ( V_20 ) ;
return V_75 ;
}
static int F_242 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_2 V_565 ;
T_4 V_566 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_369 ;
F_78 ( V_36 ) ;
F_243 ( V_567 , V_565 ) ;
V_565 = ( V_565 & 0x1f00 ) >> 8 ;
V_566 = 1000000 / ( 1 << V_565 ) ;
V_565 = F_70 ( V_568 ) ;
V_565 *= V_566 ;
F_79 ( V_36 ) ;
F_9 ( V_16 , L_347 , ( long long unsigned ) V_565 ) ;
return 0 ;
}
static int F_244 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_245 ( V_20 ) ) {
F_27 ( V_16 , L_221 ) ;
return 0 ;
}
F_9 ( V_16 , L_348 , F_137 ( ! V_36 -> V_111 . V_484 ) ) ;
F_9 ( V_16 , L_349 ,
F_137 ( ! F_246 ( V_36 ) ) ) ;
#ifdef F_247
F_9 ( V_16 , L_350 ,
F_66 ( & V_20 -> V_20 -> V_565 . V_569 ) ) ;
#else
F_9 ( V_16 , L_351 ) ;
#endif
return 0 ;
}
static int F_248 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_570 * V_571 = & V_36 -> V_571 ;
int V_41 ;
F_4 ( & V_571 -> V_325 ) ;
F_9 ( V_16 , L_352 , L_353 , L_354 ) ;
for ( V_41 = 0 ; V_41 < V_571 -> V_572 ; V_41 ++ ) {
struct V_573 * V_574 ;
enum V_162 V_163 ;
V_574 = & V_571 -> V_575 [ V_41 ] ;
F_9 ( V_16 , L_355 , V_574 -> V_52 ,
V_574 -> V_74 ) ;
for ( V_163 = 0 ; V_163 < V_576 ;
V_163 ++ ) {
if ( ! ( F_249 ( V_163 ) & V_574 -> V_577 ) )
continue;
F_9 ( V_16 , L_356 ,
F_250 ( V_163 ) ,
V_571 -> V_578 [ V_163 ] ) ;
}
}
F_6 ( & V_571 -> V_325 ) ;
return 0 ;
}
static int F_251 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_579 * V_580 ;
if ( ! F_252 ( V_20 ) ) {
F_27 ( V_16 , L_221 ) ;
return 0 ;
}
V_580 = & V_36 -> V_580 ;
F_78 ( V_36 ) ;
F_9 ( V_16 , L_357 , F_137 ( V_580 -> V_581 != NULL ) ) ;
F_9 ( V_16 , L_358 , V_580 -> V_582 ) ;
if ( ! V_580 -> V_581 )
goto V_206;
F_9 ( V_16 , L_359 , F_253 ( V_580 -> V_583 ) ,
F_254 ( V_580 -> V_583 ) ) ;
if ( F_130 ( V_20 ) && V_580 -> V_583 >= F_255 ( 1 , 6 ) ) {
F_9 ( V_16 , L_360 ,
F_70 ( V_584 ) ) ;
F_9 ( V_16 , L_361 ,
F_70 ( V_585 ) ) ;
} else if ( F_121 ( V_20 ) && V_580 -> V_583 >= F_255 ( 1 , 4 ) ) {
F_9 ( V_16 , L_360 ,
F_70 ( V_586 ) ) ;
}
V_206:
F_9 ( V_16 , L_362 , F_70 ( F_256 ( 0 ) ) ) ;
F_9 ( V_16 , L_363 , F_70 ( V_587 ) ) ;
F_9 ( V_16 , L_364 , F_70 ( V_588 ) ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static void F_257 ( struct V_15 * V_16 , int V_589 ,
struct V_590 * V_591 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_589 ; V_41 ++ )
F_30 ( V_16 , '\t' ) ;
F_9 ( V_16 , L_365 ,
V_591 -> V_37 . V_88 , V_591 -> V_52 ,
V_591 -> V_592 , V_591 -> clock ,
V_591 -> V_593 , V_591 -> V_594 ,
V_591 -> V_595 , V_591 -> V_596 ,
V_591 -> V_597 , V_591 -> V_598 ,
V_591 -> V_599 , V_591 -> V_600 ,
V_591 -> type , V_591 -> V_442 ) ;
}
static void F_258 ( struct V_15 * V_16 ,
struct V_126 * V_126 ,
struct V_556 * V_556 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_601 * V_127 = & V_126 -> V_37 ;
struct V_558 * V_558 ;
struct V_602 * V_557 ;
V_557 = & V_556 -> V_37 ;
F_9 ( V_16 , L_366 ,
V_557 -> V_37 . V_88 , V_557 -> V_52 ) ;
F_259 (dev, encoder, intel_connector) {
struct V_603 * V_559 = & V_558 -> V_37 ;
F_9 ( V_16 , L_367 ,
V_559 -> V_37 . V_88 ,
V_559 -> V_52 ,
F_260 ( V_559 -> V_437 ) ) ;
if ( V_559 -> V_437 == V_604 ) {
struct V_590 * V_591 = & V_127 -> V_591 ;
F_9 ( V_16 , L_368 ) ;
F_257 ( V_16 , 2 , V_591 ) ;
} else {
F_30 ( V_16 , '\n' ) ;
}
}
}
static void F_261 ( struct V_15 * V_16 , struct V_126 * V_126 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_601 * V_127 = & V_126 -> V_37 ;
struct V_556 * V_556 ;
struct V_605 * V_606 = V_127 -> V_607 -> V_429 ;
struct V_406 * V_410 = V_606 -> V_410 ;
if ( V_410 )
F_9 ( V_16 , L_369 ,
V_410 -> V_37 . V_88 , V_606 -> V_608 >> 16 ,
V_606 -> V_609 >> 16 , V_410 -> V_411 , V_410 -> V_412 ) ;
else
F_27 ( V_16 , L_370 ) ;
F_262 (dev, crtc, intel_encoder)
F_258 ( V_16 , V_126 , V_556 ) ;
}
static void F_263 ( struct V_15 * V_16 , struct V_610 * V_611 )
{
struct V_590 * V_591 = V_611 -> V_612 ;
F_9 ( V_16 , L_371 ) ;
F_257 ( V_16 , 2 , V_591 ) ;
}
static void F_264 ( struct V_15 * V_16 ,
struct V_558 * V_558 )
{
struct V_556 * V_556 = V_558 -> V_557 ;
struct V_560 * V_560 = F_239 ( & V_556 -> V_37 ) ;
F_9 ( V_16 , L_372 , V_560 -> V_613 [ V_614 ] ) ;
F_9 ( V_16 , L_373 , F_137 ( V_560 -> V_615 ) ) ;
if ( V_556 -> type == V_564 )
F_263 ( V_16 , & V_558 -> V_611 ) ;
}
static void F_265 ( struct V_15 * V_16 ,
struct V_558 * V_558 )
{
struct V_556 * V_556 = V_558 -> V_557 ;
struct V_616 * V_617 =
F_266 ( & V_556 -> V_37 ) ;
struct V_618 * V_619 = V_617 -> V_607 ;
struct V_560 * V_560 = & V_619 -> V_620 ;
bool V_615 = F_267 ( & V_560 -> V_621 ,
V_558 -> V_622 ) ;
F_9 ( V_16 , L_373 , F_137 ( V_615 ) ) ;
}
static void F_268 ( struct V_15 * V_16 ,
struct V_558 * V_558 )
{
struct V_556 * V_556 = V_558 -> V_557 ;
struct V_623 * V_623 = F_269 ( & V_556 -> V_37 ) ;
F_9 ( V_16 , L_373 , F_137 ( V_623 -> V_615 ) ) ;
}
static void F_270 ( struct V_15 * V_16 ,
struct V_558 * V_558 )
{
F_263 ( V_16 , & V_558 -> V_611 ) ;
}
static void F_271 ( struct V_15 * V_16 ,
struct V_603 * V_559 )
{
struct V_558 * V_558 = F_272 ( V_559 ) ;
struct V_556 * V_556 = V_558 -> V_557 ;
struct V_590 * V_591 ;
F_9 ( V_16 , L_374 ,
V_559 -> V_37 . V_88 , V_559 -> V_52 ,
F_260 ( V_559 -> V_437 ) ) ;
if ( V_559 -> V_437 == V_604 ) {
F_9 ( V_16 , L_375 , V_559 -> V_624 . V_52 ) ;
F_9 ( V_16 , L_376 ,
V_559 -> V_624 . V_625 ,
V_559 -> V_624 . V_626 ) ;
F_9 ( V_16 , L_377 ,
F_273 ( V_559 -> V_624 . V_627 ) ) ;
F_9 ( V_16 , L_378 ,
V_559 -> V_624 . V_628 ) ;
}
if ( V_556 ) {
if ( V_556 -> type == V_629 ||
V_556 -> type == V_564 )
F_264 ( V_16 , V_558 ) ;
else if ( V_556 -> type == V_630 )
F_268 ( V_16 , V_558 ) ;
else if ( V_556 -> type == V_631 )
F_270 ( V_16 , V_558 ) ;
else if ( V_556 -> type == V_632 )
F_265 ( V_16 , V_558 ) ;
}
F_9 ( V_16 , L_379 ) ;
F_19 (mode, &connector->modes, head)
F_257 ( V_16 , 2 , V_591 ) ;
}
static bool F_274 ( struct V_19 * V_20 , int V_128 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_429 ;
if ( F_275 ( V_20 ) || F_276 ( V_20 ) )
V_429 = F_70 ( F_277 ( V_633 ) ) & V_634 ;
else
V_429 = F_70 ( F_277 ( V_128 ) ) & V_635 ;
return V_429 ;
}
static bool F_278 ( struct V_19 * V_20 , int V_128 , int * T_1 , int * V_636 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_201 ;
V_201 = F_70 ( F_279 ( V_128 ) ) ;
* T_1 = ( V_201 >> V_637 ) & V_638 ;
if ( V_201 & ( V_639 << V_637 ) )
* T_1 = - * T_1 ;
* V_636 = ( V_201 >> V_640 ) & V_638 ;
if ( V_201 & ( V_639 << V_640 ) )
* V_636 = - * V_636 ;
return F_274 ( V_20 , V_128 ) ;
}
static const char * F_280 ( enum V_641 type )
{
switch ( type ) {
case V_642 :
return L_380 ;
case V_643 :
return L_381 ;
case V_644 :
return L_382 ;
}
return L_263 ;
}
static const char * F_281 ( unsigned int V_645 )
{
static char V_207 [ 48 ] ;
snprintf ( V_207 , sizeof( V_207 ) ,
L_383 ,
( V_645 & F_249 ( V_646 ) ) ? L_384 : L_13 ,
( V_645 & F_249 ( V_647 ) ) ? L_385 : L_13 ,
( V_645 & F_249 ( V_648 ) ) ? L_386 : L_13 ,
( V_645 & F_249 ( V_649 ) ) ? L_387 : L_13 ,
( V_645 & F_249 ( V_650 ) ) ? L_388 : L_13 ,
( V_645 & F_249 ( V_651 ) ) ? L_389 : L_13 ,
V_645 ) ;
return V_207 ;
}
static void F_282 ( struct V_15 * V_16 , struct V_126 * V_126 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_652 * V_652 ;
F_283 (dev, intel_crtc, intel_plane) {
struct V_605 * V_429 ;
struct V_653 * V_129 = & V_652 -> V_37 ;
if ( ! V_129 -> V_429 ) {
F_27 ( V_16 , L_390 ) ;
continue;
}
V_429 = V_129 -> V_429 ;
F_9 ( V_16 , L_391 ,
V_129 -> V_37 . V_88 ,
F_280 ( V_652 -> V_37 . type ) ,
V_429 -> V_654 , V_429 -> V_655 ,
V_429 -> V_656 , V_429 -> V_657 ,
( V_429 -> V_608 >> 16 ) ,
( ( V_429 -> V_608 & 0xffff ) * 15625 ) >> 10 ,
( V_429 -> V_609 >> 16 ) ,
( ( V_429 -> V_609 & 0xffff ) * 15625 ) >> 10 ,
( V_429 -> V_658 >> 16 ) ,
( ( V_429 -> V_658 & 0xffff ) * 15625 ) >> 10 ,
( V_429 -> V_659 >> 16 ) ,
( ( V_429 -> V_659 & 0xffff ) * 15625 ) >> 10 ,
V_429 -> V_410 ? F_284 ( V_429 -> V_410 -> V_660 ) : L_392 ,
F_281 ( V_429 -> V_645 ) ) ;
}
}
static void F_285 ( struct V_15 * V_16 , struct V_126 * V_126 )
{
struct V_661 * V_662 ;
int V_663 = V_126 -> V_663 ;
int V_41 ;
V_662 = F_286 ( V_126 -> V_37 . V_429 ) ;
if ( V_663 ) {
F_9 ( V_16 , L_393 ,
V_663 ,
V_662 -> V_664 . V_665 ,
V_662 -> V_664 . V_666 ) ;
for ( V_41 = 0 ; V_41 < V_667 ; V_41 ++ ) {
struct V_668 * V_669 =
& V_662 -> V_664 . V_670 [ V_41 ] ;
F_9 ( V_16 , L_394 ,
V_41 , F_137 ( V_669 -> V_671 ) , V_669 -> V_591 ) ;
}
F_27 ( V_16 , L_30 ) ;
} else {
F_27 ( V_16 , L_395 ) ;
}
}
static int F_287 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_126 * V_127 ;
struct V_603 * V_559 ;
F_78 ( V_36 ) ;
F_236 ( V_20 ) ;
F_9 ( V_16 , L_396 ) ;
F_9 ( V_16 , L_397 ) ;
F_62 (dev, crtc) {
bool V_42 ;
struct V_661 * V_662 ;
int T_1 , V_636 ;
V_662 = F_286 ( V_127 -> V_37 . V_429 ) ;
F_9 ( V_16 , L_398 ,
V_127 -> V_37 . V_37 . V_88 , F_63 ( V_127 -> V_128 ) ,
F_137 ( V_662 -> V_37 . V_42 ) ,
V_662 -> V_672 , V_662 -> V_673 ,
F_137 ( V_662 -> V_674 ) , V_662 -> V_675 ) ;
if ( V_662 -> V_37 . V_42 ) {
F_261 ( V_16 , V_127 ) ;
V_42 = F_278 ( V_20 , V_127 -> V_128 , & T_1 , & V_636 ) ;
F_9 ( V_16 , L_399 ,
F_137 ( V_127 -> V_676 ) ,
T_1 , V_636 , V_127 -> V_37 . V_439 -> V_429 -> V_656 ,
V_127 -> V_37 . V_439 -> V_429 -> V_657 ,
V_127 -> V_677 , F_137 ( V_42 ) ) ;
F_285 ( V_16 , V_127 ) ;
F_282 ( V_16 , V_127 ) ;
}
F_9 ( V_16 , L_400 ,
F_137 ( ! V_127 -> V_678 ) ,
F_137 ( ! V_127 -> V_679 ) ) ;
}
F_9 ( V_16 , L_30 ) ;
F_9 ( V_16 , L_401 ) ;
F_9 ( V_16 , L_402 ) ;
F_19 (connector, &dev->mode_config.connector_list, head) {
F_271 ( V_16 , V_559 ) ;
}
F_241 ( V_20 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_288 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_680 = F_289 ( F_8 ( V_20 ) -> V_681 ) ;
int V_41 , V_102 , V_75 ;
if ( ! F_290 ( V_20 ) ) {
F_27 ( V_16 , L_403 ) ;
return 0 ;
}
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
if ( F_125 ( V_20 ) ) {
struct V_430 * V_430 ;
T_12 * V_148 ;
V_430 = F_186 ( V_36 -> V_682 , 0 ) ;
V_148 = ( T_12 * ) F_188 ( V_430 ) ;
F_24 (ring, dev_priv, i) {
T_12 V_683 ;
F_9 ( V_16 , L_248 , V_39 -> V_52 ) ;
F_27 ( V_16 , L_404 ) ;
for ( V_102 = 0 ; V_102 < V_680 ; V_102 ++ ) {
V_683 = V_41 * V_286 + V_102 ;
F_9 ( V_16 , L_405 ,
V_148 [ V_683 ] , V_683 * 8 ) ;
}
F_30 ( V_16 , '\n' ) ;
F_27 ( V_16 , L_406 ) ;
for ( V_102 = 0 ; V_102 < V_680 ; V_102 ++ ) {
V_683 = V_41 + ( V_102 * V_286 ) ;
F_9 ( V_16 , L_405 ,
V_148 [ V_683 ] , V_683 * 8 ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_189 ( V_148 ) ;
} else {
F_27 ( V_16 , L_404 ) ;
F_24 (ring, dev_priv, i)
for ( V_102 = 0 ; V_102 < V_680 ; V_102 ++ )
F_9 ( V_16 , L_407 ,
F_70 ( V_39 -> V_684 . V_685 . signal [ V_102 ] ) ) ;
F_30 ( V_16 , '\n' ) ;
}
F_27 ( V_16 , L_408 ) ;
F_24 (ring, dev_priv, i) {
for ( V_102 = 0 ; V_102 < V_680 ; V_102 ++ ) {
F_9 ( V_16 , L_409 , V_39 -> V_684 . V_686 [ V_102 ] ) ;
}
F_30 ( V_16 , '\n' ) ;
}
F_30 ( V_16 , '\n' ) ;
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_291 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 ;
F_236 ( V_20 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_687 ; V_41 ++ ) {
struct V_688 * V_689 = & V_36 -> V_690 [ V_41 ] ;
F_9 ( V_16 , L_410 , V_41 , V_689 -> V_52 , V_689 -> V_88 ) ;
F_9 ( V_16 , L_411 ,
V_689 -> V_691 . V_692 , V_689 -> V_42 , F_137 ( V_689 -> V_693 ) ) ;
F_9 ( V_16 , L_412 ) ;
F_9 ( V_16 , L_413 , V_689 -> V_691 . V_694 . V_695 ) ;
F_9 ( V_16 , L_414 ,
V_689 -> V_691 . V_694 . V_696 ) ;
F_9 ( V_16 , L_415 , V_689 -> V_691 . V_694 . V_697 ) ;
F_9 ( V_16 , L_416 , V_689 -> V_691 . V_694 . V_698 ) ;
F_9 ( V_16 , L_417 , V_689 -> V_691 . V_694 . V_699 ) ;
}
F_241 ( V_20 ) ;
return 0 ;
}
static int F_292 ( struct V_15 * V_16 , void * V_210 )
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
F_9 ( V_16 , L_418 , V_36 -> V_700 . V_74 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_700 . V_74 ; ++ V_41 ) {
T_13 V_134 ;
T_4 V_701 , V_702 , V_703 ;
bool V_704 ;
V_134 = V_36 -> V_700 . V_371 [ V_41 ] . V_134 ;
V_701 = V_36 -> V_700 . V_371 [ V_41 ] . V_701 ;
V_702 = V_36 -> V_700 . V_371 [ V_41 ] . V_702 ;
V_703 = F_70 ( V_134 ) ;
V_704 = ( V_702 & V_701 ) == ( V_703 & V_701 ) ;
F_9 ( V_16 , L_419 ,
F_293 ( V_134 ) , V_702 , V_701 , V_703 , V_704 ? L_420 : L_421 ) ;
}
F_79 ( V_36 ) ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int F_294 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_705 * V_706 ;
struct V_707 * V_708 ;
enum V_128 V_128 ;
int V_129 ;
if ( F_8 ( V_20 ) -> V_23 < 9 )
return 0 ;
F_236 ( V_20 ) ;
V_706 = & V_36 -> V_709 . V_710 . V_706 ;
F_9 ( V_16 , L_422 , L_13 , L_423 , L_424 , L_425 ) ;
F_82 (dev_priv, pipe) {
F_9 ( V_16 , L_426 , F_63 ( V_128 ) ) ;
F_295 (dev_priv, pipe, plane) {
V_708 = & V_706 -> V_129 [ V_128 ] [ V_129 ] ;
F_9 ( V_16 , L_427 , V_129 + 1 ,
V_708 -> V_55 , V_708 -> V_711 ,
F_296 ( V_708 ) ) ;
}
V_708 = & V_706 -> V_129 [ V_128 ] [ V_712 ] ;
F_9 ( V_16 , L_428 , L_429 , V_708 -> V_55 ,
V_708 -> V_711 , F_296 ( V_708 ) ) ;
}
F_241 ( V_20 ) ;
return 0 ;
}
static void F_297 ( struct V_15 * V_16 ,
struct V_19 * V_20 , struct V_126 * V_126 )
{
struct V_556 * V_556 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_713 * V_714 = & V_36 -> V_714 ;
int V_592 = 0 ;
F_262 (dev, &intel_crtc->base, intel_encoder) {
switch ( V_556 -> type ) {
case V_564 :
F_27 ( V_16 , L_430 ) ;
break;
case V_715 :
F_27 ( V_16 , L_431 ) ;
break;
case V_630 :
F_27 ( V_16 , L_432 ) ;
break;
case V_629 :
F_27 ( V_16 , L_433 ) ;
break;
default:
F_9 ( V_16 , L_434 ,
V_556 -> type ) ;
return;
}
}
if ( V_36 -> V_402 . V_716 == V_717 )
F_27 ( V_16 , L_435 ) ;
else if ( V_36 -> V_402 . V_716 == V_718 )
F_27 ( V_16 , L_436 ) ;
else if ( V_36 -> V_402 . V_716 == V_719 )
F_27 ( V_16 , L_437 ) ;
else
F_27 ( V_16 , L_438 ) ;
F_27 ( V_16 , L_439 ) ;
if ( F_286 ( V_126 -> V_37 . V_429 ) -> V_720 ) {
struct V_610 * V_611 ;
F_4 ( & V_714 -> V_721 ) ;
F_27 ( V_16 , L_440 ) ;
if ( ! V_714 -> V_620 ) {
F_27 ( V_16 , L_441 ) ;
F_6 ( & V_714 -> V_721 ) ;
return;
}
V_611 = & V_714 -> V_620 -> V_722 -> V_611 ;
F_9 ( V_16 , L_442 ,
V_714 -> V_548 ) ;
F_27 ( V_16 , L_443 ) ;
if ( V_714 -> V_723 == V_724 ) {
F_27 ( V_16 , L_444 ) ;
V_592 = V_611 -> V_612 -> V_592 ;
} else if ( V_714 -> V_723 == V_725 ) {
F_27 ( V_16 , L_445 ) ;
V_592 = V_611 -> V_726 -> V_592 ;
} else {
F_9 ( V_16 , L_446 ,
V_714 -> V_723 ) ;
F_6 ( & V_714 -> V_721 ) ;
return;
}
F_9 ( V_16 , L_447 , V_592 ) ;
F_27 ( V_16 , L_443 ) ;
F_6 ( & V_714 -> V_721 ) ;
} else {
F_27 ( V_16 , L_448 ) ;
}
F_27 ( V_16 , L_30 ) ;
}
static int F_298 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_126 * V_126 ;
int V_727 = 0 ;
F_62 (dev, intel_crtc) {
F_299 ( & V_126 -> V_37 . V_721 , NULL ) ;
if ( V_126 -> V_37 . V_429 -> V_42 ) {
V_727 ++ ;
F_9 ( V_16 , L_449 , V_727 ) ;
F_297 ( V_16 , V_20 , V_126 ) ;
}
F_300 ( & V_126 -> V_37 . V_721 ) ;
}
if ( ! V_727 )
F_27 ( V_16 , L_450 ) ;
return 0 ;
}
static int F_301 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_602 * V_557 ;
struct V_556 * V_556 ;
struct V_618 * V_619 ;
F_236 ( V_20 ) ;
F_19 (encoder, &dev->mode_config.encoder_list, head) {
V_556 = F_238 ( V_557 ) ;
if ( V_556 -> type != V_629 )
continue;
V_619 = F_302 ( V_557 ) ;
if ( ! V_619 -> V_620 . V_728 )
continue;
F_303 ( V_16 , & V_619 -> V_620 . V_621 ) ;
}
F_241 ( V_20 ) ;
return 0 ;
}
static int F_304 ( struct V_198 * V_198 , struct V_110 * V_729 )
{
struct V_730 * V_22 = V_198 -> V_199 ;
struct V_35 * V_36 = V_22 -> V_20 -> V_69 ;
struct V_731 * V_732 = & V_36 -> V_732 [ V_22 -> V_128 ] ;
if ( V_22 -> V_128 >= F_8 ( V_22 -> V_20 ) -> V_733 )
return - V_369 ;
F_65 ( & V_732 -> V_325 ) ;
if ( V_732 -> V_734 ) {
F_73 ( & V_732 -> V_325 ) ;
return - V_735 ;
}
V_732 -> V_734 = true ;
V_729 -> V_197 = V_198 -> V_199 ;
F_73 ( & V_732 -> V_325 ) ;
return 0 ;
}
static int F_305 ( struct V_198 * V_198 , struct V_110 * V_729 )
{
struct V_730 * V_22 = V_198 -> V_199 ;
struct V_35 * V_36 = V_22 -> V_20 -> V_69 ;
struct V_731 * V_732 = & V_36 -> V_732 [ V_22 -> V_128 ] ;
F_65 ( & V_732 -> V_325 ) ;
V_732 -> V_734 = false ;
F_73 ( & V_732 -> V_325 ) ;
return 0 ;
}
static int F_306 ( struct V_731 * V_732 )
{
F_307 ( & V_732 -> V_325 ) ;
return F_308 ( V_732 -> V_68 , V_732 -> V_422 ,
V_736 ) ;
}
static T_5
F_309 ( struct V_110 * V_729 , char T_6 * V_737 , T_7 V_74 ,
T_8 * V_201 )
{
struct V_730 * V_22 = V_729 -> V_197 ;
struct V_19 * V_20 = V_22 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_731 * V_732 = & V_36 -> V_732 [ V_22 -> V_128 ] ;
char V_207 [ V_738 ] ;
int V_739 ;
T_5 V_740 ;
if ( V_74 < V_741 )
return - V_81 ;
if ( V_732 -> V_742 == V_743 )
return 0 ;
F_65 ( & V_732 -> V_325 ) ;
while ( F_306 ( V_732 ) == 0 ) {
int V_75 ;
if ( V_729 -> V_744 & V_745 ) {
F_73 ( & V_732 -> V_325 ) ;
return - V_746 ;
}
V_75 = F_310 ( V_732 -> V_747 ,
F_306 ( V_732 ) , V_732 -> V_325 ) ;
if ( V_75 ) {
F_73 ( & V_732 -> V_325 ) ;
return V_75 ;
}
}
V_739 = V_74 / V_741 ;
V_740 = 0 ;
while ( V_739 > 0 ) {
struct V_748 * V_708 =
& V_732 -> V_749 [ V_732 -> V_422 ] ;
int V_75 ;
if ( F_308 ( V_732 -> V_68 , V_732 -> V_422 ,
V_736 ) < 1 )
break;
F_311 ( V_736 ) ;
V_732 -> V_422 = ( V_732 -> V_422 + 1 ) & ( V_736 - 1 ) ;
V_740 += snprintf ( V_207 , V_738 ,
L_451 ,
V_708 -> V_750 , V_708 -> V_561 [ 0 ] ,
V_708 -> V_561 [ 1 ] , V_708 -> V_561 [ 2 ] ,
V_708 -> V_561 [ 3 ] , V_708 -> V_561 [ 4 ] ) ;
F_73 ( & V_732 -> V_325 ) ;
V_75 = F_312 ( V_737 , V_207 , V_741 ) ;
if ( V_75 == V_741 )
return - V_751 ;
V_737 += V_741 ;
V_739 -- ;
F_65 ( & V_732 -> V_325 ) ;
}
F_73 ( & V_732 -> V_325 ) ;
return V_740 ;
}
static int F_313 ( struct V_3 * V_752 , struct V_1 * V_2 ,
enum V_128 V_128 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
struct V_730 * V_22 = & V_753 [ V_128 ] ;
V_22 -> V_20 = V_20 ;
V_4 = F_314 ( V_22 -> V_52 , V_754 , V_752 , V_22 ,
& V_755 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , V_22 ) ;
}
static const char * F_315 ( enum V_756 V_742 )
{
F_316 ( F_46 ( V_757 ) != V_758 ) ;
return V_757 [ V_742 ] ;
}
static int F_317 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_759 ; V_41 ++ )
F_9 ( V_16 , L_452 , F_63 ( V_41 ) ,
F_315 ( V_36 -> V_732 [ V_41 ] . V_742 ) ) ;
return 0 ;
}
static int F_318 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
return F_319 ( V_110 , F_317 , V_20 ) ;
}
static int F_320 ( enum V_756 * V_742 ,
T_10 * V_209 )
{
if ( * V_742 == V_760 )
* V_742 = V_761 ;
switch ( * V_742 ) {
case V_761 :
* V_209 = V_762 | V_763 ;
break;
case V_743 :
* V_209 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_321 ( struct V_19 * V_20 , enum V_128 V_128 ,
enum V_756 * V_742 )
{
struct V_556 * V_557 ;
struct V_126 * V_127 ;
struct V_618 * V_764 ;
int V_75 = 0 ;
* V_742 = V_761 ;
F_236 ( V_20 ) ;
F_322 (dev, encoder) {
if ( ! V_557 -> V_37 . V_127 )
continue;
V_127 = F_323 ( V_557 -> V_37 . V_127 ) ;
if ( V_127 -> V_128 != V_128 )
continue;
switch ( V_557 -> type ) {
case V_765 :
* V_742 = V_766 ;
break;
case V_629 :
case V_564 :
V_764 = F_302 ( & V_557 -> V_37 ) ;
switch ( V_764 -> V_622 ) {
case V_767 :
* V_742 = V_768 ;
break;
case V_769 :
* V_742 = V_770 ;
break;
case V_771 :
* V_742 = V_772 ;
break;
default:
F_324 ( 1 , L_453 ,
F_325 ( V_764 -> V_622 ) ) ;
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
static int F_326 ( struct V_19 * V_20 ,
enum V_128 V_128 ,
enum V_756 * V_742 ,
T_10 * V_209 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_773 = false ;
if ( * V_742 == V_760 ) {
int V_75 = F_321 ( V_20 , V_128 , V_742 ) ;
if ( V_75 )
return V_75 ;
}
switch ( * V_742 ) {
case V_761 :
* V_209 = V_762 | V_774 ;
break;
case V_768 :
* V_209 = V_762 | V_775 ;
V_773 = true ;
break;
case V_770 :
* V_209 = V_762 | V_776 ;
V_773 = true ;
break;
case V_772 :
if ( ! F_81 ( V_20 ) )
return - V_81 ;
* V_209 = V_762 | V_777 ;
V_773 = true ;
break;
case V_743 :
* V_209 = 0 ;
break;
default:
return - V_81 ;
}
if ( V_773 ) {
T_10 V_494 = F_70 ( V_778 ) ;
V_494 |= V_779 ;
switch ( V_128 ) {
case V_633 :
V_494 |= V_780 ;
break;
case V_781 :
V_494 |= V_782 ;
break;
case V_783 :
V_494 |= V_784 ;
break;
default:
return - V_81 ;
}
F_157 ( V_778 , V_494 ) ;
}
return 0 ;
}
static int F_327 ( struct V_19 * V_20 ,
enum V_128 V_128 ,
enum V_756 * V_742 ,
T_10 * V_209 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_773 = false ;
if ( * V_742 == V_760 ) {
int V_75 = F_321 ( V_20 , V_128 , V_742 ) ;
if ( V_75 )
return V_75 ;
}
switch ( * V_742 ) {
case V_761 :
* V_209 = V_762 | V_785 ;
break;
case V_766 :
if ( ! F_328 ( V_20 ) )
return - V_81 ;
* V_209 = V_762 | V_786 ;
break;
case V_768 :
if ( ! F_162 ( V_20 ) )
return - V_81 ;
* V_209 = V_762 | V_787 ;
V_773 = true ;
break;
case V_770 :
if ( ! F_162 ( V_20 ) )
return - V_81 ;
* V_209 = V_762 | V_788 ;
V_773 = true ;
break;
case V_772 :
if ( ! F_162 ( V_20 ) )
return - V_81 ;
* V_209 = V_762 | V_789 ;
V_773 = true ;
break;
case V_743 :
* V_209 = 0 ;
break;
default:
return - V_81 ;
}
if ( V_773 ) {
T_10 V_494 = F_70 ( V_778 ) ;
F_187 ( ! F_162 ( V_20 ) ) ;
F_157 ( V_790 ,
F_70 ( V_790 ) | V_791 ) ;
if ( V_128 == V_633 )
V_494 |= V_780 ;
else
V_494 |= V_782 ;
F_157 ( V_778 , V_494 ) ;
}
return 0 ;
}
static void F_329 ( struct V_19 * V_20 ,
enum V_128 V_128 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_10 V_494 = F_70 ( V_778 ) ;
switch ( V_128 ) {
case V_633 :
V_494 &= ~ V_780 ;
break;
case V_781 :
V_494 &= ~ V_782 ;
break;
case V_783 :
V_494 &= ~ V_784 ;
break;
default:
return;
}
if ( ! ( V_494 & V_792 ) )
V_494 &= ~ V_779 ;
F_157 ( V_778 , V_494 ) ;
}
static void F_330 ( struct V_19 * V_20 ,
enum V_128 V_128 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_10 V_494 = F_70 ( V_778 ) ;
if ( V_128 == V_633 )
V_494 &= ~ V_780 ;
else
V_494 &= ~ V_782 ;
F_157 ( V_778 , V_494 ) ;
if ( ! ( V_494 & V_792 ) ) {
F_157 ( V_790 ,
F_70 ( V_790 ) & ~ V_791 ) ;
}
}
static int F_331 ( enum V_756 * V_742 ,
T_10 * V_209 )
{
if ( * V_742 == V_760 )
* V_742 = V_761 ;
switch ( * V_742 ) {
case V_793 :
* V_209 = V_762 | V_794 ;
break;
case V_795 :
* V_209 = V_762 | V_796 ;
break;
case V_761 :
* V_209 = V_762 | V_797 ;
break;
case V_743 :
* V_209 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static void F_332 ( struct V_19 * V_20 , bool V_798 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_126 * V_127 =
F_323 ( V_36 -> V_799 [ V_633 ] ) ;
struct V_661 * V_662 ;
struct V_800 * V_429 ;
int V_75 = 0 ;
F_236 ( V_20 ) ;
V_429 = F_333 ( V_20 ) ;
if ( ! V_429 ) {
V_75 = - V_9 ;
goto V_206;
}
V_429 -> V_801 = F_334 ( & V_127 -> V_37 ) ;
V_662 = F_335 ( V_429 , V_127 ) ;
if ( F_336 ( V_662 ) ) {
V_75 = F_337 ( V_662 ) ;
goto V_206;
}
V_662 -> V_802 . V_803 = V_798 ;
if ( V_662 -> V_804 == V_805 &&
V_662 -> V_802 . V_483 != V_798 )
V_662 -> V_37 . V_806 = true ;
V_75 = F_338 ( V_429 ) ;
V_206:
F_241 ( V_20 ) ;
F_324 ( V_75 , L_454 , V_798 , V_75 ) ;
if ( V_75 )
F_339 ( V_429 ) ;
}
static int F_340 ( struct V_19 * V_20 ,
enum V_128 V_128 ,
enum V_756 * V_742 ,
T_10 * V_209 )
{
if ( * V_742 == V_760 )
* V_742 = V_807 ;
switch ( * V_742 ) {
case V_793 :
* V_209 = V_762 | V_808 ;
break;
case V_795 :
* V_209 = V_762 | V_809 ;
break;
case V_807 :
if ( F_124 ( V_20 ) && V_128 == V_633 )
F_332 ( V_20 , true ) ;
* V_209 = V_762 | V_810 ;
break;
case V_743 :
* V_209 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_341 ( struct V_19 * V_20 , enum V_128 V_128 ,
enum V_756 V_742 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_731 * V_732 = & V_36 -> V_732 [ V_128 ] ;
struct V_126 * V_127 = F_323 ( F_342 ( V_20 ,
V_128 ) ) ;
enum V_162 V_163 ;
T_4 V_209 = 0 ;
int V_75 ;
if ( V_732 -> V_742 == V_742 )
return 0 ;
if ( V_732 -> V_742 && V_742 )
return - V_81 ;
V_163 = F_87 ( V_128 ) ;
if ( ! F_88 ( V_36 , V_163 ) ) {
F_343 ( L_455 ) ;
return - V_811 ;
}
if ( F_344 ( V_20 ) )
V_75 = F_320 ( & V_742 , & V_209 ) ;
else if ( F_8 ( V_20 ) -> V_23 < 5 )
V_75 = F_327 ( V_20 , V_128 , & V_742 , & V_209 ) ;
else if ( F_93 ( V_20 ) || F_81 ( V_20 ) )
V_75 = F_326 ( V_20 , V_128 , & V_742 , & V_209 ) ;
else if ( F_117 ( V_20 ) || F_127 ( V_20 ) )
V_75 = F_331 ( & V_742 , & V_209 ) ;
else
V_75 = F_340 ( V_20 , V_128 , & V_742 , & V_209 ) ;
if ( V_75 != 0 )
goto V_206;
if ( V_742 ) {
struct V_748 * V_749 ;
F_99 ( L_456 ,
F_63 ( V_128 ) , F_315 ( V_742 ) ) ;
V_749 = F_345 ( V_736 ,
sizeof( V_732 -> V_749 [ 0 ] ) ,
V_8 ) ;
if ( ! V_749 ) {
V_75 = - V_9 ;
goto V_206;
}
F_346 ( V_127 ) ;
F_65 ( & V_732 -> V_325 ) ;
F_106 ( V_732 -> V_749 ) ;
V_732 -> V_749 = V_749 ;
V_732 -> V_68 = 0 ;
V_732 -> V_422 = 0 ;
F_73 ( & V_732 -> V_325 ) ;
}
V_732 -> V_742 = V_742 ;
F_157 ( F_347 ( V_128 ) , V_209 ) ;
F_348 ( F_347 ( V_128 ) ) ;
if ( V_742 == V_743 ) {
struct V_748 * V_749 ;
struct V_126 * V_127 =
F_323 ( V_36 -> V_799 [ V_128 ] ) ;
F_99 ( L_457 ,
F_63 ( V_128 ) ) ;
F_299 ( & V_127 -> V_37 . V_721 , NULL ) ;
if ( V_127 -> V_37 . V_429 -> V_42 )
F_349 ( V_20 , V_128 ) ;
F_300 ( & V_127 -> V_37 . V_721 ) ;
F_65 ( & V_732 -> V_325 ) ;
V_749 = V_732 -> V_749 ;
V_732 -> V_749 = NULL ;
V_732 -> V_68 = 0 ;
V_732 -> V_422 = 0 ;
F_73 ( & V_732 -> V_325 ) ;
F_106 ( V_749 ) ;
if ( F_162 ( V_20 ) )
F_330 ( V_20 , V_128 ) ;
else if ( F_93 ( V_20 ) || F_81 ( V_20 ) )
F_329 ( V_20 , V_128 ) ;
else if ( F_124 ( V_20 ) && V_128 == V_633 )
F_332 ( V_20 , false ) ;
F_350 ( V_127 ) ;
}
V_75 = 0 ;
V_206:
F_92 ( V_36 , V_163 ) ;
return V_75 ;
}
static int F_351 ( char * V_207 , char * V_812 [] , int V_813 )
{
int V_814 = 0 ;
while ( * V_207 ) {
char * V_711 ;
V_207 = F_352 ( V_207 ) ;
if ( ! * V_207 )
break;
for ( V_711 = V_207 ; * V_711 && ! isspace ( * V_711 ) ; V_711 ++ )
;
if ( V_814 == V_813 ) {
F_99 ( L_458 ,
V_813 ) ;
return - V_81 ;
}
if ( * V_711 )
* V_711 ++ = '\0' ;
V_812 [ V_814 ++ ] = V_207 ;
V_207 = V_711 ;
}
return V_814 ;
}
static int
F_353 ( const char * V_207 , enum V_815 * V_816 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_817 ) ; V_41 ++ )
if ( ! strcmp ( V_207 , V_817 [ V_41 ] ) ) {
* V_816 = V_41 ;
return 0 ;
}
return - V_81 ;
}
static int F_354 ( const char * V_207 , enum V_128 * V_128 )
{
const char V_52 = V_207 [ 0 ] ;
if ( V_52 < 'A' || V_52 >= F_63 ( V_759 ) )
return - V_81 ;
* V_128 = V_52 - 'A' ;
return 0 ;
}
static int
F_355 ( const char * V_207 , enum V_756 * V_59 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_757 ) ; V_41 ++ )
if ( ! strcmp ( V_207 , V_757 [ V_41 ] ) ) {
* V_59 = V_41 ;
return 0 ;
}
return - V_81 ;
}
static int F_356 ( struct V_19 * V_20 , char * V_207 , T_7 V_818 )
{
#define F_357 3
int V_814 ;
char * V_812 [ F_357 ] ;
enum V_128 V_128 ;
enum V_815 V_819 ;
enum V_756 V_742 ;
V_814 = F_351 ( V_207 , V_812 , F_357 ) ;
if ( V_814 != F_357 ) {
F_99 ( L_459 ,
F_357 ) ;
return - V_81 ;
}
if ( F_353 ( V_812 [ 0 ] , & V_819 ) < 0 ) {
F_99 ( L_460 , V_812 [ 0 ] ) ;
return - V_81 ;
}
if ( F_354 ( V_812 [ 1 ] , & V_128 ) < 0 ) {
F_99 ( L_461 , V_812 [ 1 ] ) ;
return - V_81 ;
}
if ( F_355 ( V_812 [ 2 ] , & V_742 ) < 0 ) {
F_99 ( L_462 , V_812 [ 2 ] ) ;
return - V_81 ;
}
return F_341 ( V_20 , V_128 , V_742 ) ;
}
static T_5 F_358 ( struct V_110 * V_110 , const char T_6 * V_192 ,
T_7 V_818 , T_8 * V_820 )
{
struct V_15 * V_16 = V_110 -> V_197 ;
struct V_19 * V_20 = V_16 -> V_18 ;
char * V_821 ;
int V_75 ;
if ( V_818 == 0 )
return 0 ;
if ( V_818 > V_542 - 1 ) {
F_99 ( L_463 ,
V_542 ) ;
return - V_822 ;
}
V_821 = F_2 ( V_818 + 1 , V_8 ) ;
if ( ! V_821 )
return - V_9 ;
if ( F_359 ( V_821 , V_192 , V_818 ) ) {
V_75 = - V_751 ;
goto V_206;
}
V_821 [ V_818 ] = '\0' ;
V_75 = F_356 ( V_20 , V_821 , V_818 ) ;
V_206:
F_106 ( V_821 ) ;
if ( V_75 < 0 )
return V_75 ;
* V_820 += V_818 ;
return V_818 ;
}
static T_5 F_360 ( struct V_110 * V_110 ,
const char T_6 * V_192 ,
T_7 V_818 , T_8 * V_820 )
{
char * V_823 ;
int V_437 = 0 ;
struct V_19 * V_20 ;
struct V_603 * V_559 ;
struct V_67 * V_824 ;
struct V_560 * V_560 ;
int V_209 = 0 ;
V_20 = ( (struct V_15 * ) V_110 -> V_197 ) -> V_18 ;
V_824 = & V_20 -> V_417 . V_824 ;
if ( V_818 == 0 )
return 0 ;
V_823 = F_2 ( V_818 + 1 , V_8 ) ;
if ( ! V_823 )
return - V_9 ;
if ( F_359 ( V_823 , V_192 , V_818 ) ) {
V_437 = - V_751 ;
goto V_206;
}
V_823 [ V_818 ] = '\0' ;
F_99 ( L_464 , ( unsigned int ) V_818 ) ;
F_19 (connector, connector_list, head) {
if ( V_559 -> V_825 !=
V_826 )
continue;
if ( V_559 -> V_437 == V_604 &&
V_559 -> V_557 != NULL ) {
V_560 = F_239 ( V_559 -> V_557 ) ;
V_437 = F_361 ( V_823 , 10 , & V_209 ) ;
if ( V_437 < 0 )
goto V_206;
F_99 ( L_465 , V_209 ) ;
if ( V_209 == 1 )
V_560 -> V_827 = 1 ;
else
V_560 -> V_827 = 0 ;
}
}
V_206:
F_106 ( V_823 ) ;
if ( V_437 < 0 )
return V_437 ;
* V_820 += V_818 ;
return V_818 ;
}
static int F_362 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_603 * V_559 ;
struct V_67 * V_824 = & V_20 -> V_417 . V_824 ;
struct V_560 * V_560 ;
F_19 (connector, connector_list, head) {
if ( V_559 -> V_825 !=
V_826 )
continue;
if ( V_559 -> V_437 == V_604 &&
V_559 -> V_557 != NULL ) {
V_560 = F_239 ( V_559 -> V_557 ) ;
if ( V_560 -> V_827 )
F_27 ( V_16 , L_466 ) ;
else
F_27 ( V_16 , L_467 ) ;
} else
F_27 ( V_16 , L_467 ) ;
}
return 0 ;
}
static int F_363 ( struct V_198 * V_198 ,
struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
return F_319 ( V_110 , F_362 , V_20 ) ;
}
static int F_364 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_603 * V_559 ;
struct V_67 * V_824 = & V_20 -> V_417 . V_824 ;
struct V_560 * V_560 ;
F_19 (connector, connector_list, head) {
if ( V_559 -> V_825 !=
V_826 )
continue;
if ( V_559 -> V_437 == V_604 &&
V_559 -> V_557 != NULL ) {
V_560 = F_239 ( V_559 -> V_557 ) ;
F_9 ( V_16 , L_468 , V_560 -> V_828 ) ;
} else
F_27 ( V_16 , L_467 ) ;
}
return 0 ;
}
static int F_365 ( struct V_198 * V_198 ,
struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
return F_319 ( V_110 , F_364 , V_20 ) ;
}
static int F_366 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_603 * V_559 ;
struct V_67 * V_824 = & V_20 -> V_417 . V_824 ;
struct V_560 * V_560 ;
F_19 (connector, connector_list, head) {
if ( V_559 -> V_825 !=
V_826 )
continue;
if ( V_559 -> V_437 == V_604 &&
V_559 -> V_557 != NULL ) {
V_560 = F_239 ( V_559 -> V_557 ) ;
F_9 ( V_16 , L_469 , V_560 -> V_829 ) ;
} else
F_27 ( V_16 , L_467 ) ;
}
return 0 ;
}
static int F_367 ( struct V_198 * V_198 ,
struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
return F_319 ( V_110 , F_366 , V_20 ) ;
}
static void F_368 ( struct V_15 * V_16 , const T_14 V_709 [ 8 ] )
{
struct V_19 * V_20 = V_16 -> V_18 ;
int V_830 ;
int V_831 ;
if ( F_81 ( V_20 ) )
V_831 = 3 ;
else if ( F_93 ( V_20 ) )
V_831 = 1 ;
else
V_831 = F_369 ( V_20 ) + 1 ;
F_236 ( V_20 ) ;
for ( V_830 = 0 ; V_830 < V_831 ; V_830 ++ ) {
unsigned int V_832 = V_709 [ V_830 ] ;
if ( F_8 ( V_20 ) -> V_23 >= 9 || F_93 ( V_20 ) ||
F_81 ( V_20 ) )
V_832 *= 10 ;
else if ( V_830 > 0 )
V_832 *= 5 ;
F_9 ( V_16 , L_470 ,
V_830 , V_709 [ V_830 ] , V_832 / 10 , V_832 % 10 ) ;
}
F_241 ( V_20 ) ;
}
static int F_370 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_14 * V_833 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_833 = V_36 -> V_709 . V_834 ;
else
V_833 = F_23 ( V_20 ) -> V_709 . V_835 ;
F_368 ( V_16 , V_833 ) ;
return 0 ;
}
static int F_371 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_14 * V_833 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_833 = V_36 -> V_709 . V_834 ;
else
V_833 = F_23 ( V_20 ) -> V_709 . V_836 ;
F_368 ( V_16 , V_833 ) ;
return 0 ;
}
static int F_372 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_14 * V_833 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_833 = V_36 -> V_709 . V_834 ;
else
V_833 = F_23 ( V_20 ) -> V_709 . V_837 ;
F_368 ( V_16 , V_833 ) ;
return 0 ;
}
static int F_373 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
if ( F_8 ( V_20 ) -> V_23 < 5 )
return - V_369 ;
return F_319 ( V_110 , F_370 , V_20 ) ;
}
static int F_374 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
if ( F_375 ( V_20 ) )
return - V_369 ;
return F_319 ( V_110 , F_371 , V_20 ) ;
}
static int F_376 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
if ( F_375 ( V_20 ) )
return - V_369 ;
return F_319 ( V_110 , F_372 , V_20 ) ;
}
static T_5 F_377 ( struct V_110 * V_110 , const char T_6 * V_192 ,
T_7 V_818 , T_8 * V_820 , T_14 V_709 [ 8 ] )
{
struct V_15 * V_16 = V_110 -> V_197 ;
struct V_19 * V_20 = V_16 -> V_18 ;
T_14 V_838 [ 8 ] = { 0 } ;
int V_831 ;
int V_830 ;
int V_75 ;
char V_494 [ 32 ] ;
if ( F_81 ( V_20 ) )
V_831 = 3 ;
else if ( F_93 ( V_20 ) )
V_831 = 1 ;
else
V_831 = F_369 ( V_20 ) + 1 ;
if ( V_818 >= sizeof( V_494 ) )
return - V_81 ;
if ( F_359 ( V_494 , V_192 , V_818 ) )
return - V_751 ;
V_494 [ V_818 ] = '\0' ;
V_75 = sscanf ( V_494 , L_471 ,
& V_838 [ 0 ] , & V_838 [ 1 ] , & V_838 [ 2 ] , & V_838 [ 3 ] ,
& V_838 [ 4 ] , & V_838 [ 5 ] , & V_838 [ 6 ] , & V_838 [ 7 ] ) ;
if ( V_75 != V_831 )
return - V_81 ;
F_236 ( V_20 ) ;
for ( V_830 = 0 ; V_830 < V_831 ; V_830 ++ )
V_709 [ V_830 ] = V_838 [ V_830 ] ;
F_241 ( V_20 ) ;
return V_818 ;
}
static T_5 F_378 ( struct V_110 * V_110 , const char T_6 * V_192 ,
T_7 V_818 , T_8 * V_820 )
{
struct V_15 * V_16 = V_110 -> V_197 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_14 * V_833 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_833 = V_36 -> V_709 . V_834 ;
else
V_833 = F_23 ( V_20 ) -> V_709 . V_835 ;
return F_377 ( V_110 , V_192 , V_818 , V_820 , V_833 ) ;
}
static T_5 F_379 ( struct V_110 * V_110 , const char T_6 * V_192 ,
T_7 V_818 , T_8 * V_820 )
{
struct V_15 * V_16 = V_110 -> V_197 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_14 * V_833 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_833 = V_36 -> V_709 . V_834 ;
else
V_833 = F_23 ( V_20 ) -> V_709 . V_836 ;
return F_377 ( V_110 , V_192 , V_818 , V_820 , V_833 ) ;
}
static T_5 F_380 ( struct V_110 * V_110 , const char T_6 * V_192 ,
T_7 V_818 , T_8 * V_820 )
{
struct V_15 * V_16 = V_110 -> V_197 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_14 * V_833 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_833 = V_36 -> V_709 . V_834 ;
else
V_833 = F_23 ( V_20 ) -> V_709 . V_837 ;
return F_377 ( V_110 , V_192 , V_818 , V_820 , V_833 ) ;
}
static int
F_381 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_209 = F_66 ( & V_36 -> V_289 . V_839 ) ;
return 0 ;
}
static int
F_382 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_383 ( & V_36 -> V_289 ) )
return - V_746 ;
F_78 ( V_36 ) ;
F_384 ( V_20 , V_209 ,
L_472 , V_209 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int
F_385 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_209 = V_36 -> V_289 . V_840 ;
return 0 ;
}
static int
F_386 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
F_99 ( L_473 , V_209 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_36 -> V_289 . V_840 = V_209 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_387 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_209 = V_36 -> V_289 . V_841 ;
return 0 ;
}
static int
F_388 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_36 -> V_289 . V_841 = V_209 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_389 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_209 = V_36 -> V_289 . V_842 ;
return 0 ;
}
static int
F_390 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
F_99 ( L_474 , V_209 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_36 -> V_289 . V_842 = V_209 ;
F_6 ( & V_20 -> V_76 ) ;
return 0 ;
}
static int
F_391 ( void * V_17 , T_2 * V_209 )
{
* V_209 = V_843 ;
return 0 ;
}
static int
F_392 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
F_393 ( L_475 , V_209 ) ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
if ( V_209 & V_844 ) {
V_75 = F_394 ( V_20 ) ;
if ( V_75 )
goto V_845;
}
if ( V_209 & ( V_846 | V_844 ) )
F_395 ( V_20 ) ;
if ( V_209 & V_847 )
F_396 ( V_36 , V_848 , V_849 ) ;
if ( V_209 & V_850 )
F_396 ( V_36 , V_848 , V_851 ) ;
V_845:
F_6 ( & V_20 -> V_76 ) ;
return V_75 ;
}
static int
F_397 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_369 ;
F_116 ( & V_36 -> V_211 . V_212 ) ;
V_75 = F_32 ( & V_36 -> V_211 . V_222 ) ;
if ( V_75 )
return V_75 ;
* V_209 = F_120 ( V_36 , V_36 -> V_211 . V_396 ) ;
F_6 ( & V_36 -> V_211 . V_222 ) ;
return 0 ;
}
static int
F_398 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_852 , V_853 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_369 ;
F_116 ( & V_36 -> V_211 . V_212 ) ;
F_99 ( L_476 , V_209 ) ;
V_75 = F_32 ( & V_36 -> V_211 . V_222 ) ;
if ( V_75 )
return V_75 ;
V_209 = F_399 ( V_36 , V_209 ) ;
V_852 = V_36 -> V_211 . V_226 ;
V_853 = V_36 -> V_211 . V_227 ;
if ( V_209 < V_853 || V_209 > V_852 || V_209 < V_36 -> V_211 . V_395 ) {
F_6 ( & V_36 -> V_211 . V_222 ) ;
return - V_81 ;
}
V_36 -> V_211 . V_396 = V_209 ;
F_400 ( V_20 , V_209 ) ;
F_6 ( & V_36 -> V_211 . V_222 ) ;
return 0 ;
}
static int
F_401 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_369 ;
F_116 ( & V_36 -> V_211 . V_212 ) ;
V_75 = F_32 ( & V_36 -> V_211 . V_222 ) ;
if ( V_75 )
return V_75 ;
* V_209 = F_120 ( V_36 , V_36 -> V_211 . V_395 ) ;
F_6 ( & V_36 -> V_211 . V_222 ) ;
return 0 ;
}
static int
F_402 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_852 , V_853 ;
int V_75 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_369 ;
F_116 ( & V_36 -> V_211 . V_212 ) ;
F_99 ( L_477 , V_209 ) ;
V_75 = F_32 ( & V_36 -> V_211 . V_222 ) ;
if ( V_75 )
return V_75 ;
V_209 = F_399 ( V_36 , V_209 ) ;
V_852 = V_36 -> V_211 . V_226 ;
V_853 = V_36 -> V_211 . V_227 ;
if ( V_209 < V_853 || V_209 > V_852 || V_209 > V_36 -> V_211 . V_396 ) {
F_6 ( & V_36 -> V_211 . V_222 ) ;
return - V_81 ;
}
V_36 -> V_211 . V_395 = V_209 ;
F_400 ( V_20 , V_209 ) ;
F_6 ( & V_36 -> V_211 . V_222 ) ;
return 0 ;
}
static int
F_403 ( void * V_17 , T_2 * V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_854 ;
int V_75 ;
if ( ! ( F_127 ( V_20 ) || F_128 ( V_20 ) ) )
return - V_369 ;
V_75 = F_32 ( & V_20 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_78 ( V_36 ) ;
V_854 = F_70 ( V_855 ) ;
F_79 ( V_36 ) ;
F_6 ( & V_36 -> V_20 -> V_76 ) ;
* V_209 = ( V_854 & V_856 ) >> V_857 ;
return 0 ;
}
static int
F_404 ( void * V_17 , T_2 V_209 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_854 ;
if ( ! ( F_127 ( V_20 ) || F_128 ( V_20 ) ) )
return - V_369 ;
if ( V_209 > 3 )
return - V_81 ;
F_78 ( V_36 ) ;
F_99 ( L_478 , V_209 ) ;
V_854 = F_70 ( V_855 ) ;
V_854 &= ~ V_856 ;
V_854 |= ( V_209 << V_857 ) ;
F_157 ( V_855 , V_854 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static void F_405 ( struct V_19 * V_20 ,
struct V_858 * V_544 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_859 = 2 ;
int V_860 ;
T_4 V_861 [ V_859 ] , V_862 [ V_859 ] ;
V_861 [ 0 ] = F_70 ( V_863 ) ;
V_861 [ 1 ] = F_70 ( V_864 ) ;
V_862 [ 0 ] = F_70 ( V_865 ) ;
V_862 [ 1 ] = F_70 ( V_866 ) ;
for ( V_860 = 0 ; V_860 < V_859 ; V_860 ++ ) {
unsigned int V_867 ;
if ( V_861 [ V_860 ] & V_868 )
continue;
V_544 -> V_869 = 1 ;
V_544 -> V_870 ++ ;
V_867 = ( ( V_861 [ V_860 ] & V_871 ) ? 0 : 2 ) +
( ( V_861 [ V_860 ] & V_872 ) ? 0 : 2 ) +
( ( V_861 [ V_860 ] & V_873 ) ? 0 : 2 ) +
( ( V_862 [ V_860 ] & V_874 ) ? 0 : 2 ) ;
V_544 -> V_875 += V_867 ;
V_544 -> V_876 = F_406 ( V_544 -> V_876 , V_867 ) ;
}
V_544 -> V_877 = V_544 -> V_870 ;
}
static void F_407 ( struct V_19 * V_20 ,
struct V_858 * V_544 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_878 = 3 , V_859 = 4 ;
int V_59 , V_860 ;
T_4 V_879 [ V_878 ] , V_880 [ 2 * V_878 ] , V_881 [ 2 ] ;
if ( F_121 ( V_20 ) ) {
V_878 = 1 ;
V_859 = 3 ;
}
for ( V_59 = 0 ; V_59 < V_878 ; V_59 ++ ) {
V_879 [ V_59 ] = F_70 ( F_408 ( V_59 ) ) ;
V_880 [ 2 * V_59 ] = F_70 ( F_409 ( V_59 ) ) ;
V_880 [ 2 * V_59 + 1 ] = F_70 ( F_410 ( V_59 ) ) ;
}
V_881 [ 0 ] = V_882 |
V_883 |
V_884 |
V_885 ;
V_881 [ 1 ] = V_886 |
V_887 |
V_888 |
V_889 ;
for ( V_59 = 0 ; V_59 < V_878 ; V_59 ++ ) {
unsigned int V_890 = 0 ;
if ( ( V_879 [ V_59 ] & V_891 ) == 0 )
continue;
V_544 -> V_869 ++ ;
if ( F_130 ( V_20 ) || F_131 ( V_20 ) )
V_890 = F_8 ( V_20 ) -> V_870 ;
for ( V_860 = 0 ; V_860 < V_859 ; V_860 ++ ) {
unsigned int V_867 ;
if ( F_121 ( V_20 ) &&
! ( V_879 [ V_59 ] & ( F_411 ( V_860 ) ) ) )
continue;
if ( F_121 ( V_20 ) )
V_890 ++ ;
V_867 = 2 * F_289 ( V_880 [ 2 * V_59 + V_860 / 2 ] &
V_881 [ V_860 % 2 ] ) ;
V_544 -> V_875 += V_867 ;
V_544 -> V_876 = F_406 ( V_544 -> V_876 ,
V_867 ) ;
}
V_544 -> V_877 += V_890 ;
V_544 -> V_870 = F_406 ( V_544 -> V_870 ,
V_890 ) ;
}
}
static void F_412 ( struct V_19 * V_20 ,
struct V_858 * V_544 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_59 ;
T_4 V_892 = F_70 ( V_893 ) ;
V_544 -> V_869 = F_289 ( V_892 & V_894 ) ;
if ( V_544 -> V_869 ) {
V_544 -> V_870 = F_8 ( V_20 ) -> V_870 ;
V_544 -> V_877 = V_544 -> V_869 *
V_544 -> V_870 ;
V_544 -> V_876 = F_8 ( V_20 ) -> V_876 ;
V_544 -> V_875 = V_544 -> V_876 * V_544 -> V_877 ;
for ( V_59 = 0 ; V_59 < V_544 -> V_869 ; V_59 ++ ) {
T_11 V_895 = F_8 ( V_20 ) -> V_895 [ V_59 ] ;
V_544 -> V_875 -= F_413 ( V_895 ) ;
}
}
}
static int F_414 ( struct V_15 * V_16 , void * V_210 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_858 V_544 ;
if ( F_8 ( V_20 ) -> V_23 < 8 )
return - V_369 ;
F_27 ( V_16 , L_479 ) ;
F_9 ( V_16 , L_480 ,
F_8 ( V_20 ) -> V_869 ) ;
F_9 ( V_16 , L_481 ,
F_8 ( V_20 ) -> V_877 ) ;
F_9 ( V_16 , L_482 ,
F_8 ( V_20 ) -> V_870 ) ;
F_9 ( V_16 , L_483 ,
F_8 ( V_20 ) -> V_875 ) ;
F_9 ( V_16 , L_484 ,
F_8 ( V_20 ) -> V_876 ) ;
F_9 ( V_16 , L_485 ,
F_137 ( F_8 ( V_20 ) -> V_896 ) ) ;
F_9 ( V_16 , L_486 ,
F_137 ( F_8 ( V_20 ) -> V_897 ) ) ;
F_9 ( V_16 , L_487 ,
F_137 ( F_8 ( V_20 ) -> V_898 ) ) ;
F_27 ( V_16 , L_488 ) ;
memset ( & V_544 , 0 , sizeof( V_544 ) ) ;
if ( F_81 ( V_20 ) ) {
F_405 ( V_20 , & V_544 ) ;
} else if ( F_125 ( V_20 ) ) {
F_412 ( V_20 , & V_544 ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 9 ) {
F_407 ( V_20 , & V_544 ) ;
}
F_9 ( V_16 , L_489 ,
V_544 . V_869 ) ;
F_9 ( V_16 , L_490 ,
V_544 . V_877 ) ;
F_9 ( V_16 , L_491 ,
V_544 . V_870 ) ;
F_9 ( V_16 , L_492 ,
V_544 . V_875 ) ;
F_9 ( V_16 , L_493 ,
V_544 . V_876 ) ;
return 0 ;
}
static int F_415 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return 0 ;
F_78 ( V_36 ) ;
F_122 ( V_36 , V_255 ) ;
return 0 ;
}
static int F_416 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
struct V_19 * V_20 = V_198 -> V_199 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return 0 ;
F_126 ( V_36 , V_255 ) ;
F_79 ( V_36 ) ;
return 0 ;
}
static int F_417 ( struct V_3 * V_752 , struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
V_4 = F_314 ( L_494 ,
V_899 ,
V_752 , V_20 ,
& V_900 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , & V_900 ) ;
}
static int F_418 ( struct V_3 * V_752 ,
struct V_1 * V_2 ,
const char * V_52 ,
const struct V_901 * V_902 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
V_4 = F_314 ( V_52 ,
V_754 | V_903 ,
V_752 , V_20 ,
V_902 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , V_902 ) ;
}
void F_419 ( struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
enum V_128 V_128 ;
F_82 (dev_priv, pipe) {
struct V_731 * V_732 = & V_36 -> V_732 [ V_128 ] ;
V_732 -> V_734 = false ;
F_420 ( & V_732 -> V_325 ) ;
F_421 ( & V_732 -> V_747 ) ;
}
}
int F_422 ( struct V_1 * V_2 )
{
int V_75 , V_41 ;
V_75 = F_417 ( V_2 -> V_904 , V_2 ) ;
if ( V_75 )
return V_75 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_753 ) ; V_41 ++ ) {
V_75 = F_313 ( V_2 -> V_904 , V_2 , V_41 ) ;
if ( V_75 )
return V_75 ;
}
for ( V_41 = 0 ; V_41 < F_46 ( V_905 ) ; V_41 ++ ) {
V_75 = F_418 ( V_2 -> V_904 , V_2 ,
V_905 [ V_41 ] . V_52 ,
V_905 [ V_41 ] . V_902 ) ;
if ( V_75 )
return V_75 ;
}
return F_423 ( V_906 ,
V_907 ,
V_2 -> V_904 , V_2 ) ;
}
void F_424 ( struct V_1 * V_2 )
{
int V_41 ;
F_425 ( V_906 ,
V_907 , V_2 ) ;
F_425 ( (struct V_908 * ) & V_900 ,
1 , V_2 ) ;
for ( V_41 = 0 ; V_41 < F_46 ( V_753 ) ; V_41 ++ ) {
struct V_908 * V_909 =
(struct V_908 * ) & V_753 [ V_41 ] ;
F_425 ( V_909 , 1 , V_2 ) ;
}
for ( V_41 = 0 ; V_41 < F_46 ( V_905 ) ; V_41 ++ ) {
struct V_908 * V_909 =
(struct V_908 * ) V_905 [ V_41 ] . V_902 ;
F_425 ( V_909 , 1 , V_2 ) ;
}
}
static int F_426 ( struct V_15 * V_16 , void * V_17 )
{
struct V_603 * V_559 = V_16 -> V_18 ;
struct V_560 * V_560 =
F_239 ( & F_427 ( V_559 ) -> V_37 ) ;
T_15 V_207 [ 16 ] ;
T_5 V_910 ;
int V_41 ;
if ( V_559 -> V_437 != V_604 )
return - V_369 ;
for ( V_41 = 0 ; V_41 < F_46 ( V_911 ) ; V_41 ++ ) {
const struct V_912 * V_87 = & V_911 [ V_41 ] ;
T_7 V_31 = V_87 -> V_711 ? V_87 -> V_711 - V_87 -> V_683 + 1 : ( V_87 -> V_31 ? : 1 ) ;
if ( V_87 -> V_913 &&
V_559 -> V_825 != V_914 )
continue;
if ( F_187 ( V_31 > sizeof( V_207 ) ) )
continue;
V_910 = F_428 ( & V_560 -> V_915 , V_87 -> V_683 , V_207 , V_31 ) ;
if ( V_910 <= 0 ) {
F_429 ( L_495 ,
V_31 , V_87 -> V_683 , V_910 ) ;
continue;
}
F_9 ( V_16 , L_496 , V_87 -> V_683 , ( int ) V_31 , V_207 ) ;
}
return 0 ;
}
static int F_430 ( struct V_198 * V_198 , struct V_110 * V_110 )
{
return F_319 ( V_110 , F_426 , V_198 -> V_199 ) ;
}
int F_431 ( struct V_603 * V_559 )
{
struct V_3 * V_752 = V_559 -> V_916 ;
if ( ! V_752 )
return - V_369 ;
if ( V_559 -> V_825 == V_826 ||
V_559 -> V_825 == V_914 )
F_314 ( L_497 , V_754 , V_752 , V_559 ,
& V_917 ) ;
return 0 ;
}
