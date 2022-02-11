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
F_19 (vma, &obj->vma_list, obj_link) {
if ( V_33 -> V_34 && F_20 ( & V_33 -> V_7 ) )
V_31 += V_33 -> V_7 . V_31 ;
}
return V_31 ;
}
static void
F_21 ( struct V_15 * V_16 , struct V_24 * V_25 )
{
struct V_35 * V_36 = F_22 ( V_25 -> V_37 . V_20 ) ;
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
F_23 (ring, dev_priv, i)
F_9 ( V_16 , L_10 ,
F_24 ( V_25 -> V_45 [ V_41 ] ) ) ;
F_9 ( V_16 , L_11 ,
F_24 ( V_25 -> V_46 ) ,
F_24 ( V_25 -> V_47 ) ,
F_25 ( F_22 ( V_25 -> V_37 . V_20 ) , V_25 -> V_48 ) ,
V_25 -> V_49 ? L_12 : L_13 ,
V_25 -> V_50 == V_51 ? L_14 : L_13 ) ;
if ( V_25 -> V_37 . V_52 )
F_9 ( V_16 , L_15 , V_25 -> V_37 . V_52 ) ;
F_19 (vma, &obj->vma_list, obj_link) {
if ( V_33 -> V_40 > 0 )
V_40 ++ ;
}
F_9 ( V_16 , L_16 , V_40 ) ;
if ( V_25 -> V_26 )
F_9 ( V_16 , L_17 ) ;
if ( V_25 -> V_53 != V_54 )
F_9 ( V_16 , L_18 , V_25 -> V_53 ) ;
F_19 (vma, &obj->vma_list, obj_link) {
F_9 ( V_16 , L_19 ,
V_33 -> V_34 ? L_7 : L_20 ,
V_33 -> V_7 . V_55 , V_33 -> V_7 . V_31 ) ;
if ( V_33 -> V_34 )
F_9 ( V_16 , L_21 , V_33 -> V_56 . type ) ;
F_26 ( V_16 , L_22 ) ;
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
F_27 ( V_25 -> V_46 ) -> V_52 ) ;
if ( V_25 -> V_61 )
F_9 ( V_16 , L_26 , V_25 -> V_61 ) ;
}
static void F_28 ( struct V_15 * V_16 , struct V_62 * V_63 )
{
F_29 ( V_16 , V_63 -> V_64 . V_65 ? 'I' : 'i' ) ;
F_29 ( V_16 , V_63 -> V_66 ? 'R' : 'r' ) ;
F_29 ( V_16 , ' ' ) ;
}
static int F_30 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
T_3 V_13 = ( T_3 ) V_7 -> V_11 -> V_17 ;
struct V_67 * V_68 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_70 * V_71 = & V_36 -> V_72 . V_37 ;
struct V_32 * V_33 ;
T_2 V_73 , V_74 ;
int V_75 , V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
switch ( V_13 ) {
case V_78 :
F_26 ( V_16 , L_27 ) ;
V_68 = & V_71 -> V_79 ;
break;
case V_80 :
F_26 ( V_16 , L_28 ) ;
V_68 = & V_71 -> V_81 ;
break;
default:
F_6 ( & V_20 -> V_77 ) ;
return - V_82 ;
}
V_73 = V_74 = V_75 = 0 ;
F_19 (vma, head, vm_link) {
F_9 ( V_16 , L_29 ) ;
F_21 ( V_16 , V_33 -> V_25 ) ;
F_9 ( V_16 , L_30 ) ;
V_73 += V_33 -> V_25 -> V_37 . V_31 ;
V_74 += V_33 -> V_7 . V_31 ;
V_75 ++ ;
}
F_6 ( & V_20 -> V_77 ) ;
F_9 ( V_16 , L_31 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_32 ( void * V_83 ,
struct V_67 * V_84 , struct V_67 * V_85 )
{
struct V_24 * V_86 =
F_33 ( V_84 , struct V_24 , V_87 ) ;
struct V_24 * V_88 =
F_33 ( V_85 , struct V_24 , V_87 ) ;
if ( V_86 -> V_57 -> V_55 < V_88 -> V_57 -> V_55 )
return - 1 ;
if ( V_86 -> V_57 -> V_55 > V_88 -> V_57 -> V_55 )
return 1 ;
return 0 ;
}
static int F_34 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_25 ;
T_2 V_73 , V_74 ;
F_35 ( V_57 ) ;
int V_75 , V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_73 = V_74 = V_75 = 0 ;
F_19 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_25 -> V_57 == NULL )
continue;
F_5 ( & V_25 -> V_87 , & V_57 ) ;
V_73 += V_25 -> V_37 . V_31 ;
V_74 += F_18 ( V_25 ) ;
V_75 ++ ;
}
F_19 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_25 -> V_57 == NULL )
continue;
F_5 ( & V_25 -> V_87 , & V_57 ) ;
V_73 += V_25 -> V_37 . V_31 ;
V_75 ++ ;
}
F_36 ( NULL , & V_57 , F_32 ) ;
F_26 ( V_16 , L_32 ) ;
while ( ! F_37 ( & V_57 ) ) {
V_25 = F_38 ( & V_57 , F_39 ( * V_25 ) , V_87 ) ;
F_26 ( V_16 , L_29 ) ;
F_21 ( V_16 , V_25 ) ;
F_29 ( V_16 , '\n' ) ;
F_40 ( & V_25 -> V_87 ) ;
}
F_6 ( & V_20 -> V_77 ) ;
F_9 ( V_16 , L_31 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_41 ( int V_89 , void * V_90 , void * V_17 )
{
struct V_24 * V_25 = V_90 ;
struct V_91 * V_92 = V_17 ;
struct V_32 * V_33 ;
V_92 -> V_75 ++ ;
V_92 -> V_93 += V_25 -> V_37 . V_31 ;
if ( V_25 -> V_37 . V_52 || V_25 -> V_37 . V_94 )
V_92 -> V_95 += V_25 -> V_37 . V_31 ;
if ( F_42 ( V_25 -> V_37 . V_20 ) ) {
F_19 (vma, &obj->vma_list, obj_link) {
struct V_96 * V_97 ;
if ( ! F_20 ( & V_33 -> V_7 ) )
continue;
if ( V_33 -> V_34 ) {
V_92 -> V_98 += V_25 -> V_37 . V_31 ;
continue;
}
V_97 = F_33 ( V_33 -> V_71 , struct V_96 , V_37 ) ;
if ( V_97 -> V_99 != V_92 -> V_99 )
continue;
if ( V_25 -> V_42 )
V_92 -> V_42 += V_25 -> V_37 . V_31 ;
else
V_92 -> V_100 += V_25 -> V_37 . V_31 ;
return 0 ;
}
} else {
if ( F_43 ( V_25 ) ) {
V_92 -> V_98 += V_25 -> V_37 . V_31 ;
if ( V_25 -> V_42 )
V_92 -> V_42 += V_25 -> V_37 . V_31 ;
else
V_92 -> V_100 += V_25 -> V_37 . V_31 ;
return 0 ;
}
}
if ( ! F_37 ( & V_25 -> V_101 ) )
V_92 -> V_102 += V_25 -> V_37 . V_31 ;
return 0 ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_35 * V_36 )
{
struct V_24 * V_25 ;
struct V_91 V_92 ;
struct V_38 * V_39 ;
int V_41 , V_103 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
F_23 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < F_45 ( V_39 -> V_104 . V_105 ) ; V_103 ++ ) {
F_19 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
F_41 ( 0 , V_25 , & V_92 ) ;
}
}
F_46 ( V_16 , L_33 , V_92 ) ;
}
static int F_47 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_75 , V_106 , V_107 ;
T_2 V_31 , V_108 , V_109 ;
struct V_24 * V_25 ;
struct V_70 * V_71 = & V_36 -> V_72 . V_37 ;
struct V_110 * V_111 ;
struct V_32 * V_33 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_9 ( V_16 , L_34 ,
V_36 -> V_112 . V_113 ,
V_36 -> V_112 . V_114 ) ;
V_31 = V_75 = V_108 = V_106 = 0 ;
F_48 ( & V_36 -> V_112 . V_115 , V_101 ) ;
F_9 ( V_16 , L_35 ,
V_75 , V_106 , V_31 , V_108 ) ;
V_31 = V_75 = V_108 = V_106 = 0 ;
F_49 ( & V_71 -> V_79 , V_116 ) ;
F_9 ( V_16 , L_36 ,
V_75 , V_106 , V_31 , V_108 ) ;
V_31 = V_75 = V_108 = V_106 = 0 ;
F_49 ( & V_71 -> V_81 , V_116 ) ;
F_9 ( V_16 , L_37 ,
V_75 , V_106 , V_31 , V_108 ) ;
V_31 = V_75 = V_109 = V_107 = 0 ;
F_19 (obj, &dev_priv->mm.unbound_list, global_list) {
V_31 += V_25 -> V_37 . V_31 , ++ V_75 ;
if ( V_25 -> V_50 == V_51 )
V_109 += V_25 -> V_37 . V_31 , ++ V_107 ;
}
F_9 ( V_16 , L_38 , V_75 , V_31 ) ;
V_31 = V_75 = V_108 = V_106 = 0 ;
F_19 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_25 -> V_58 ) {
V_31 += F_50 ( V_25 ) ;
++ V_75 ;
}
if ( V_25 -> V_26 ) {
V_108 += F_50 ( V_25 ) ;
++ V_106 ;
}
if ( V_25 -> V_50 == V_51 ) {
V_109 += V_25 -> V_37 . V_31 ;
++ V_107 ;
}
}
F_9 ( V_16 , L_39 ,
V_107 , V_109 ) ;
F_9 ( V_16 , L_40 ,
V_106 , V_108 ) ;
F_9 ( V_16 , L_41 ,
V_75 , V_31 ) ;
F_9 ( V_16 , L_42 ,
V_36 -> V_72 . V_37 . V_93 ,
( T_2 ) V_36 -> V_72 . V_117 - V_36 -> V_72 . V_37 . V_55 ) ;
F_29 ( V_16 , '\n' ) ;
F_44 ( V_16 , V_36 ) ;
F_51 (file, &dev->filelist, lhead) {
struct V_91 V_92 ;
struct V_118 * V_119 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_99 = V_111 -> V_120 ;
F_52 ( & V_111 -> V_121 ) ;
F_53 ( & V_111 -> V_122 , F_41 , & V_92 ) ;
F_54 ( & V_111 -> V_121 ) ;
F_55 () ;
V_119 = F_56 ( V_111 -> V_123 , V_124 ) ;
F_46 ( V_16 , V_119 ? V_119 -> V_125 : L_43 , V_92 ) ;
F_57 () ;
}
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_58 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
T_3 V_13 = ( T_3 ) V_7 -> V_11 -> V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_25 ;
T_2 V_73 , V_74 ;
int V_75 , V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_73 = V_74 = V_75 = 0 ;
F_19 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_13 == V_126 && ! F_59 ( V_25 ) )
continue;
F_26 ( V_16 , L_29 ) ;
F_21 ( V_16 , V_25 ) ;
F_29 ( V_16 , '\n' ) ;
V_73 += V_25 -> V_37 . V_31 ;
V_74 += F_18 ( V_25 ) ;
V_75 ++ ;
}
F_6 ( & V_20 -> V_77 ) ;
F_9 ( V_16 , L_31 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_60 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_127 * V_128 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_61 (dev, crtc) {
const char V_129 = F_62 ( V_128 -> V_129 ) ;
const char V_130 = F_63 ( V_128 -> V_130 ) ;
struct V_131 * V_132 ;
F_64 ( & V_20 -> V_133 ) ;
V_132 = V_128 -> V_134 ;
if ( V_132 == NULL ) {
F_9 ( V_16 , L_44 ,
V_129 , V_130 ) ;
} else {
T_4 V_135 ;
if ( F_65 ( & V_132 -> V_136 ) < V_137 ) {
F_9 ( V_16 , L_45 ,
V_129 , V_130 ) ;
} else {
F_9 ( V_16 , L_46 ,
V_129 , V_130 ) ;
}
if ( V_132 -> V_138 ) {
struct V_38 * V_39 =
F_27 ( V_132 -> V_138 ) ;
F_9 ( V_16 , L_47 ,
V_39 -> V_52 ,
F_24 ( V_132 -> V_138 ) ,
V_36 -> V_139 ,
V_39 -> V_140 ( V_39 , true ) ,
F_66 ( V_132 -> V_138 , true ) ) ;
} else
F_9 ( V_16 , L_48 ) ;
F_9 ( V_16 , L_49 ,
V_132 -> V_141 ,
V_132 -> V_142 ,
F_67 ( & V_128 -> V_37 ) ) ;
if ( V_132 -> V_143 )
F_26 ( V_16 , L_50 ) ;
else
F_26 ( V_16 , L_51 ) ;
F_9 ( V_16 , L_52 , F_65 ( & V_132 -> V_136 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 4 )
V_135 = F_68 ( F_69 ( F_70 ( V_128 -> V_130 ) ) ) ;
else
V_135 = F_69 ( F_71 ( V_128 -> V_130 ) ) ;
F_9 ( V_16 , L_53 , V_135 ) ;
if ( V_132 -> V_144 ) {
F_9 ( V_16 , L_54 , ( long ) V_132 -> V_145 ) ;
F_9 ( V_16 , L_55 , V_135 == V_132 -> V_145 ) ;
}
}
F_72 ( & V_20 -> V_133 ) ;
}
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_73 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_25 ;
struct V_38 * V_39 ;
int V_93 = 0 ;
int V_76 , V_41 , V_103 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_23 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < F_45 ( V_39 -> V_104 . V_105 ) ; V_103 ++ ) {
int V_75 ;
V_75 = 0 ;
F_19 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
V_75 ++ ;
F_9 ( V_16 , L_56 ,
V_39 -> V_52 , V_103 , V_75 ) ;
F_19 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link) {
F_26 ( V_16 , L_29 ) ;
F_21 ( V_16 , V_25 ) ;
F_29 ( V_16 , '\n' ) ;
}
V_93 += V_75 ;
}
}
F_9 ( V_16 , L_57 , V_93 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_74 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_146 * V_147 ;
int V_76 , V_148 , V_41 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_148 = 0 ;
F_23 (ring, dev_priv, i) {
int V_75 ;
V_75 = 0 ;
F_19 (req, &ring->request_list, list)
V_75 ++ ;
if ( V_75 == 0 )
continue;
F_9 ( V_16 , L_58 , V_39 -> V_52 , V_75 ) ;
F_19 (req, &ring->request_list, list) {
struct V_118 * V_119 ;
F_55 () ;
V_119 = NULL ;
if ( V_147 -> V_123 )
V_119 = F_56 ( V_147 -> V_123 , V_124 ) ;
F_9 ( V_16 , L_59 ,
V_147 -> V_149 ,
( int ) ( V_150 - V_147 -> V_151 ) ,
V_119 ? V_119 -> V_125 : L_43 ,
V_119 ? V_119 -> V_123 : - 1 ) ;
F_57 () ;
}
V_148 ++ ;
}
F_6 ( & V_20 -> V_77 ) ;
if ( V_148 == 0 )
F_26 ( V_16 , L_60 ) ;
return 0 ;
}
static void F_75 ( struct V_15 * V_16 ,
struct V_38 * V_39 )
{
if ( V_39 -> V_140 ) {
F_9 ( V_16 , L_61 ,
V_39 -> V_52 , V_39 -> V_140 ( V_39 , false ) ) ;
}
}
static int F_76 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_76 , V_41 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
F_23 (ring, dev_priv, i)
F_75 ( V_16 , V_39 ) ;
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_79 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_76 , V_41 , V_129 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
if ( F_80 ( V_20 ) ) {
F_9 ( V_16 , L_62 ,
F_69 ( V_152 ) ) ;
F_9 ( V_16 , L_63 ,
F_69 ( V_153 ) ) ;
F_9 ( V_16 , L_64 ,
F_69 ( V_154 ) ) ;
F_9 ( V_16 , L_65 ,
F_69 ( V_155 ) ) ;
F_9 ( V_16 , L_66 ,
F_69 ( V_156 ) ) ;
F_81 (dev_priv, pipe)
F_9 ( V_16 , L_67 ,
F_62 ( V_129 ) ,
F_69 ( F_82 ( V_129 ) ) ) ;
F_9 ( V_16 , L_68 ,
F_69 ( V_157 ) ) ;
F_9 ( V_16 , L_69 ,
F_69 ( V_158 ) ) ;
F_9 ( V_16 , L_70 ,
F_69 ( V_159 ) ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
F_9 ( V_16 , L_71 ,
V_41 , F_69 ( F_83 ( V_41 ) ) ) ;
F_9 ( V_16 , L_72 ,
V_41 , F_69 ( F_84 ( V_41 ) ) ) ;
F_9 ( V_16 , L_73 ,
V_41 , F_69 ( F_85 ( V_41 ) ) ) ;
}
F_9 ( V_16 , L_74 ,
F_69 ( V_160 ) ) ;
F_9 ( V_16 , L_75 ,
F_69 ( V_161 ) ) ;
F_9 ( V_16 , L_76 ,
F_69 ( V_162 ) ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 8 ) {
F_9 ( V_16 , L_62 ,
F_69 ( V_152 ) ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
F_9 ( V_16 , L_71 ,
V_41 , F_69 ( F_83 ( V_41 ) ) ) ;
F_9 ( V_16 , L_72 ,
V_41 , F_69 ( F_84 ( V_41 ) ) ) ;
F_9 ( V_16 , L_73 ,
V_41 , F_69 ( F_85 ( V_41 ) ) ) ;
}
F_81 (dev_priv, pipe) {
enum V_163 V_164 ;
V_164 = F_86 ( V_129 ) ;
if ( ! F_87 ( V_36 ,
V_164 ) ) {
F_9 ( V_16 , L_77 ,
F_62 ( V_129 ) ) ;
continue;
}
F_9 ( V_16 , L_78 ,
F_62 ( V_129 ) ,
F_69 ( F_88 ( V_129 ) ) ) ;
F_9 ( V_16 , L_79 ,
F_62 ( V_129 ) ,
F_69 ( F_89 ( V_129 ) ) ) ;
F_9 ( V_16 , L_80 ,
F_62 ( V_129 ) ,
F_69 ( F_90 ( V_129 ) ) ) ;
F_91 ( V_36 , V_164 ) ;
}
F_9 ( V_16 , L_81 ,
F_69 ( V_165 ) ) ;
F_9 ( V_16 , L_82 ,
F_69 ( V_166 ) ) ;
F_9 ( V_16 , L_83 ,
F_69 ( V_167 ) ) ;
F_9 ( V_16 , L_84 ,
F_69 ( V_168 ) ) ;
F_9 ( V_16 , L_85 ,
F_69 ( V_169 ) ) ;
F_9 ( V_16 , L_86 ,
F_69 ( V_170 ) ) ;
F_9 ( V_16 , L_74 ,
F_69 ( V_160 ) ) ;
F_9 ( V_16 , L_75 ,
F_69 ( V_161 ) ) ;
F_9 ( V_16 , L_76 ,
F_69 ( V_162 ) ) ;
} else if ( F_92 ( V_20 ) ) {
F_9 ( V_16 , L_63 ,
F_69 ( V_153 ) ) ;
F_9 ( V_16 , L_64 ,
F_69 ( V_154 ) ) ;
F_9 ( V_16 , L_65 ,
F_69 ( V_155 ) ) ;
F_9 ( V_16 , L_66 ,
F_69 ( V_156 ) ) ;
F_81 (dev_priv, pipe)
F_9 ( V_16 , L_67 ,
F_62 ( V_129 ) ,
F_69 ( F_82 ( V_129 ) ) ) ;
F_9 ( V_16 , L_87 ,
F_69 ( V_171 ) ) ;
F_9 ( V_16 , L_88 ,
F_69 ( V_172 ) ) ;
F_9 ( V_16 , L_89 ,
F_69 ( V_173 ) ) ;
F_9 ( V_16 , L_90 ,
F_69 ( V_174 ) ) ;
F_9 ( V_16 , L_91 ,
F_69 ( V_175 ) ) ;
F_9 ( V_16 , L_92 ,
F_69 ( V_176 ) ) ;
F_9 ( V_16 , L_93 ,
F_69 ( V_177 ) ) ;
F_9 ( V_16 , L_68 ,
F_69 ( V_157 ) ) ;
F_9 ( V_16 , L_69 ,
F_69 ( V_158 ) ) ;
F_9 ( V_16 , L_70 ,
F_69 ( V_159 ) ) ;
} else if ( ! F_93 ( V_20 ) ) {
F_9 ( V_16 , L_94 ,
F_69 ( V_178 ) ) ;
F_9 ( V_16 , L_95 ,
F_69 ( V_179 ) ) ;
F_9 ( V_16 , L_96 ,
F_69 ( V_180 ) ) ;
F_81 (dev_priv, pipe)
F_9 ( V_16 , L_97 ,
F_62 ( V_129 ) ,
F_69 ( F_82 ( V_129 ) ) ) ;
} else {
F_9 ( V_16 , L_98 ,
F_69 ( V_181 ) ) ;
F_9 ( V_16 , L_99 ,
F_69 ( V_182 ) ) ;
F_9 ( V_16 , L_100 ,
F_69 ( V_183 ) ) ;
F_9 ( V_16 , L_101 ,
F_69 ( V_184 ) ) ;
F_9 ( V_16 , L_102 ,
F_69 ( V_185 ) ) ;
F_9 ( V_16 , L_103 ,
F_69 ( V_186 ) ) ;
F_9 ( V_16 , L_104 ,
F_69 ( V_172 ) ) ;
F_9 ( V_16 , L_105 ,
F_69 ( V_173 ) ) ;
F_9 ( V_16 , L_106 ,
F_69 ( V_174 ) ) ;
}
F_23 (ring, dev_priv, i) {
if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
F_9 ( V_16 ,
L_107 ,
V_39 -> V_52 , F_94 ( V_39 ) ) ;
}
F_75 ( V_16 , V_39 ) ;
}
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_95 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 , V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_9 ( V_16 , L_108 , V_36 -> V_187 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_187 ; V_41 ++ ) {
struct V_24 * V_25 = V_36 -> V_188 [ V_41 ] . V_25 ;
F_9 ( V_16 , L_109 ,
V_41 , V_36 -> V_188 [ V_41 ] . V_40 ) ;
if ( V_25 == NULL )
F_26 ( V_16 , L_110 ) ;
else
F_21 ( V_16 , V_25 ) ;
F_29 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_96 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
const T_4 * V_189 ;
int V_41 ;
V_39 = & V_36 -> V_39 [ ( T_3 ) V_7 -> V_11 -> V_17 ] ;
V_189 = V_39 -> V_190 . V_191 ;
if ( V_189 == NULL )
return 0 ;
for ( V_41 = 0 ; V_41 < 4096 / sizeof( T_4 ) / 4 ; V_41 += 4 ) {
F_9 ( V_16 , L_111 ,
V_41 * 4 ,
V_189 [ V_41 ] , V_189 [ V_41 + 1 ] , V_189 [ V_41 + 2 ] , V_189 [ V_41 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_97 ( struct V_111 * V_192 ,
const char T_6 * V_193 ,
T_7 V_194 ,
T_8 * V_195 )
{
struct V_196 * V_197 = V_192 -> V_198 ;
struct V_19 * V_20 = V_197 -> V_20 ;
int V_76 ;
F_98 ( L_112 ) ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_99 ( V_20 ) ;
F_6 ( & V_20 -> V_77 ) ;
return V_194 ;
}
static int F_100 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
struct V_196 * V_197 ;
V_197 = F_101 ( sizeof( * V_197 ) , V_8 ) ;
if ( ! V_197 )
return - V_9 ;
V_197 -> V_20 = V_20 ;
F_102 ( V_20 , V_197 ) ;
V_111 -> V_198 = V_197 ;
return 0 ;
}
static int F_103 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_196 * V_197 = V_111 -> V_198 ;
F_104 ( V_197 ) ;
F_105 ( V_197 ) ;
return 0 ;
}
static T_5 F_106 ( struct V_111 * V_111 , char T_6 * V_201 ,
T_7 V_75 , T_8 * V_202 )
{
struct V_196 * V_197 = V_111 -> V_198 ;
struct V_203 V_204 ;
T_8 V_205 = 0 ;
T_5 V_206 = 0 ;
int V_76 ;
V_76 = F_107 ( & V_204 , F_22 ( V_197 -> V_20 ) , V_75 , * V_202 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_108 ( & V_204 , V_197 ) ;
if ( V_76 )
goto V_207;
V_206 = F_109 ( V_201 , V_75 , & V_205 ,
V_204 . V_208 ,
V_204 . V_209 ) ;
if ( V_206 < 0 )
V_76 = V_206 ;
else
* V_202 = V_204 . V_55 + V_206 ;
V_207:
F_110 ( & V_204 ) ;
return V_76 ? : V_206 ;
}
static int
F_111 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
* V_210 = V_36 -> V_139 ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int
F_112 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_113 ( V_20 , V_210 ) ;
F_6 ( & V_20 -> V_77 ) ;
return V_76 ;
}
static int F_114 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 = 0 ;
F_77 ( V_36 ) ;
F_115 ( & V_36 -> V_212 . V_213 ) ;
if ( F_116 ( V_20 ) ) {
T_9 V_214 = F_117 ( V_215 ) ;
T_9 V_216 = F_117 ( V_217 ) ;
F_9 ( V_16 , L_113 , ( V_214 >> 8 ) & 0xf ) ;
F_9 ( V_16 , L_114 , V_214 & 0x3f ) ;
F_9 ( V_16 , L_115 , ( V_216 & V_218 ) >>
V_219 ) ;
F_9 ( V_16 , L_116 ,
( V_216 & V_220 ) >> V_221 ) ;
} else if ( F_92 ( V_20 ) || F_80 ( V_20 ) ) {
T_4 V_222 ;
F_4 ( & V_36 -> V_212 . V_223 ) ;
V_222 = F_118 ( V_36 , V_224 ) ;
F_9 ( V_16 , L_117 , V_222 ) ;
F_9 ( V_16 , L_118 , V_36 -> V_225 ) ;
F_9 ( V_16 , L_119 ,
F_119 ( V_36 , ( V_222 >> 8 ) & 0xff ) ) ;
F_9 ( V_16 , L_120 ,
F_119 ( V_36 , V_36 -> V_212 . V_226 ) ) ;
F_9 ( V_16 , L_121 ,
F_119 ( V_36 , V_36 -> V_212 . V_227 ) ) ;
F_9 ( V_16 , L_122 ,
F_119 ( V_36 , V_36 -> V_212 . V_228 ) ) ;
F_9 ( V_16 , L_123 ,
F_119 ( V_36 , V_36 -> V_212 . V_229 ) ) ;
F_9 ( V_16 ,
L_124 ,
F_119 ( V_36 , V_36 -> V_212 . V_230 ) ) ;
F_6 ( & V_36 -> V_212 . V_223 ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
T_4 V_231 ;
T_4 V_232 ;
T_4 V_233 ;
T_4 V_234 , V_235 , V_236 ;
T_4 V_237 , V_238 , V_239 ;
T_4 V_240 , V_241 , V_242 ;
T_4 V_243 , V_244 , V_245 ;
T_4 V_246 , V_247 , V_248 , V_249 , V_250 ;
int V_227 ;
V_231 = F_69 ( V_251 ) ;
if ( F_120 ( V_20 ) ) {
V_233 = F_69 ( V_252 ) ;
V_232 = F_69 ( V_253 ) ;
} else {
V_233 = F_69 ( V_254 ) ;
V_232 = F_69 ( V_255 ) ;
}
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
goto V_207;
F_121 ( V_36 , V_256 ) ;
V_239 = F_69 ( V_257 ) ;
if ( F_122 ( V_20 ) )
V_239 >>= 23 ;
else {
V_239 &= ~ V_258 ;
if ( F_123 ( V_20 ) || F_124 ( V_20 ) )
V_239 >>= 24 ;
else
V_239 >>= 25 ;
}
V_239 = F_119 ( V_36 , V_239 ) ;
V_234 = F_69 ( V_259 ) ;
V_235 = F_69 ( V_260 ) ;
V_236 = F_69 ( V_261 ) ;
V_237 = F_69 ( V_262 ) ;
V_240 = F_69 ( V_263 ) ;
V_241 = F_69 ( V_264 ) ;
V_242 = F_69 ( V_265 ) ;
V_243 = F_69 ( V_266 ) ;
V_244 = F_69 ( V_267 ) ;
V_245 = F_69 ( V_268 ) ;
if ( F_122 ( V_20 ) )
V_238 = ( V_237 & V_269 ) >> V_270 ;
else if ( F_123 ( V_20 ) || F_124 ( V_20 ) )
V_238 = ( V_237 & V_271 ) >> V_272 ;
else
V_238 = ( V_237 & V_273 ) >> V_274 ;
V_238 = F_119 ( V_36 , V_238 ) ;
F_125 ( V_36 , V_256 ) ;
F_6 ( & V_20 -> V_77 ) ;
if ( F_126 ( V_20 ) || F_127 ( V_20 ) ) {
V_246 = F_69 ( V_175 ) ;
V_247 = F_69 ( V_177 ) ;
V_248 = F_69 ( V_275 ) ;
V_249 = F_69 ( V_176 ) ;
V_250 = F_69 ( V_276 ) ;
} else {
V_246 = F_69 ( F_85 ( 2 ) ) ;
V_247 = F_69 ( F_83 ( 2 ) ) ;
V_248 = F_69 ( F_128 ( 2 ) ) ;
V_249 = F_69 ( F_84 ( 2 ) ) ;
V_250 = F_69 ( V_276 ) ;
}
F_9 ( V_16 , L_125 ,
V_246 , V_247 , V_248 , V_249 , V_250 ) ;
F_9 ( V_16 , L_126 , V_232 ) ;
F_9 ( V_16 , L_127 ,
( V_232 & ( F_122 ( V_20 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_9 ( V_16 , L_128 ,
V_232 & 0xff ) ;
F_9 ( V_16 , L_129 ,
V_231 & 0xff ) ;
F_9 ( V_16 , L_130 , V_237 ) ;
F_9 ( V_16 , L_131 , V_234 ) ;
F_9 ( V_16 , L_132 , V_235 ) ;
F_9 ( V_16 , L_133 , V_236 ) ;
F_9 ( V_16 , L_134 , V_239 ) ;
F_9 ( V_16 , L_135 , V_238 ) ;
F_9 ( V_16 , L_136 , V_240 &
V_277 ) ;
F_9 ( V_16 , L_137 , V_241 &
V_278 ) ;
F_9 ( V_16 , L_138 , V_242 &
V_278 ) ;
F_9 ( V_16 , L_139 ,
V_36 -> V_212 . V_279 ) ;
F_9 ( V_16 , L_140 , V_243 &
V_280 ) ;
F_9 ( V_16 , L_141 , V_244 &
V_278 ) ;
F_9 ( V_16 , L_142 , V_245 &
V_278 ) ;
F_9 ( V_16 , L_143 ,
V_36 -> V_212 . V_281 ) ;
V_227 = ( F_120 ( V_20 ) ? V_233 >> 0 :
V_233 >> 16 ) & 0xff ;
V_227 *= ( F_129 ( V_20 ) || F_130 ( V_20 ) ?
V_282 : 1 ) ;
F_9 ( V_16 , L_144 ,
F_119 ( V_36 , V_227 ) ) ;
V_227 = ( V_233 & 0xff00 ) >> 8 ;
V_227 *= ( F_129 ( V_20 ) || F_130 ( V_20 ) ?
V_282 : 1 ) ;
F_9 ( V_16 , L_145 ,
F_119 ( V_36 , V_227 ) ) ;
V_227 = ( F_120 ( V_20 ) ? V_233 >> 16 :
V_233 >> 0 ) & 0xff ;
V_227 *= ( F_129 ( V_20 ) || F_130 ( V_20 ) ?
V_282 : 1 ) ;
F_9 ( V_16 , L_146 ,
F_119 ( V_36 , V_227 ) ) ;
F_9 ( V_16 , L_147 ,
F_119 ( V_36 , V_36 -> V_212 . V_227 ) ) ;
F_9 ( V_16 , L_148 ,
F_119 ( V_36 , V_36 -> V_212 . V_226 ) ) ;
F_9 ( V_16 , L_149 , V_238 ) ;
F_9 ( V_16 , L_150 ,
F_119 ( V_36 , V_36 -> V_212 . V_229 ) ) ;
F_9 ( V_16 , L_151 ,
F_119 ( V_36 , V_36 -> V_212 . V_228 ) ) ;
F_9 ( V_16 , L_152 ,
F_119 ( V_36 , V_36 -> V_212 . V_227 ) ) ;
F_9 ( V_16 ,
L_124 ,
F_119 ( V_36 , V_36 -> V_212 . V_230 ) ) ;
} else {
F_26 ( V_16 , L_153 ) ;
}
F_9 ( V_16 , L_154 , V_36 -> V_283 ) ;
F_9 ( V_16 , L_155 , V_36 -> V_284 ) ;
F_9 ( V_16 , L_156 , V_36 -> V_285 ) ;
V_207:
F_78 ( V_36 ) ;
return V_76 ;
}
static int F_131 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
T_2 V_286 [ V_287 ] ;
T_4 V_149 [ V_287 ] ;
T_4 V_288 [ V_289 ] ;
int V_41 , V_103 ;
if ( ! V_290 . V_291 ) {
F_9 ( V_16 , L_157 ) ;
return 0 ;
}
F_77 ( V_36 ) ;
F_23 (ring, dev_priv, i) {
V_149 [ V_41 ] = V_39 -> V_140 ( V_39 , false ) ;
V_286 [ V_41 ] = F_132 ( V_39 ) ;
}
F_133 ( V_20 , V_288 ) ;
F_78 ( V_36 ) ;
if ( F_134 ( & V_36 -> V_292 . V_293 ) ) {
F_9 ( V_16 , L_158 ,
F_135 ( V_36 -> V_292 . V_293 . V_294 . V_295 -
V_150 ) ) ;
} else
F_9 ( V_16 , L_159 ) ;
F_23 (ring, dev_priv, i) {
F_9 ( V_16 , L_160 , V_39 -> V_52 ) ;
F_9 ( V_16 , L_161 ,
V_39 -> V_296 . V_149 , V_149 [ V_41 ] ) ;
F_9 ( V_16 , L_162 ,
( long long ) V_39 -> V_296 . V_286 ,
( long long ) V_286 [ V_41 ] ) ;
F_9 ( V_16 , L_163 ,
( long long ) V_39 -> V_296 . V_297 ) ;
F_9 ( V_16 , L_164 , V_39 -> V_296 . V_298 ) ;
F_9 ( V_16 , L_165 , V_39 -> V_296 . V_299 ) ;
if ( V_39 -> V_89 == V_300 ) {
F_26 ( V_16 , L_166 ) ;
for ( V_103 = 0 ; V_103 < V_289 ; V_103 ++ )
F_9 ( V_16 , L_167 , V_288 [ V_103 ] ) ;
F_26 ( V_16 , L_168 ) ;
for ( V_103 = 0 ; V_103 < V_289 ; V_103 ++ )
F_9 ( V_16 , L_167 ,
V_39 -> V_296 . V_288 [ V_103 ] ) ;
F_26 ( V_16 , L_30 ) ;
}
}
return 0 ;
}
static int F_136 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_301 , V_302 ;
T_9 V_303 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
V_301 = F_69 ( V_304 ) ;
V_302 = F_69 ( V_305 ) ;
V_303 = F_117 ( V_306 ) ;
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
F_9 ( V_16 , L_169 , F_137 ( V_301 & V_307 ) ) ;
F_9 ( V_16 , L_170 ,
( V_301 & V_308 ) >>
V_309 ) ;
F_9 ( V_16 , L_171 ,
F_137 ( V_301 & V_310 ) ) ;
F_9 ( V_16 , L_172 ,
F_137 ( V_301 & V_311 ) ) ;
F_9 ( V_16 , L_173 ,
F_137 ( V_301 & V_312 ) ) ;
F_9 ( V_16 , L_174 ,
( V_301 & V_313 ) >> V_314 ) ;
F_9 ( V_16 , L_175 ,
( V_301 & V_315 ) >> V_316 ) ;
F_9 ( V_16 , L_176 , ( V_301 & V_317 ) ) ;
F_9 ( V_16 , L_177 , ( V_303 & 0x3f ) ) ;
F_9 ( V_16 , L_178 , ( ( V_303 >> 8 ) & 0x3f ) ) ;
F_9 ( V_16 , L_179 ,
F_137 ( ! ( V_302 & V_318 ) ) ) ;
F_26 ( V_16 , L_180 ) ;
switch ( V_302 & V_319 ) {
case V_320 :
F_26 ( V_16 , L_181 ) ;
break;
case V_321 :
F_26 ( V_16 , L_182 ) ;
break;
case V_322 :
F_26 ( V_16 , L_183 ) ;
break;
case V_323 :
F_26 ( V_16 , L_184 ) ;
break;
case V_324 :
F_26 ( V_16 , L_185 ) ;
break;
case V_325 :
F_26 ( V_16 , L_186 ) ;
break;
default:
F_26 ( V_16 , L_187 ) ;
break;
}
return 0 ;
}
static int F_138 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_326 * V_327 ;
int V_41 ;
F_64 ( & V_36 -> V_328 . V_329 ) ;
F_139 (fw_domain, dev_priv, i) {
F_9 ( V_16 , L_188 ,
F_140 ( V_41 ) ,
V_327 -> V_330 ) ;
}
F_72 ( & V_36 -> V_328 . V_329 ) ;
return 0 ;
}
static int F_141 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_331 , V_332 , V_333 ;
F_77 ( V_36 ) ;
V_333 = F_69 ( V_334 ) ;
V_331 = F_69 ( V_259 ) ;
V_332 = F_69 ( V_335 ) ;
F_78 ( V_36 ) ;
F_9 ( V_16 , L_189 ,
F_137 ( V_331 & V_336 ) ) ;
F_9 ( V_16 , L_190 ,
F_137 ( V_331 & V_337 ) ) ;
F_9 ( V_16 , L_171 ,
F_137 ( V_331 & V_337 ) ) ;
F_9 ( V_16 , L_172 ,
F_137 ( ( V_331 & V_338 ) ==
V_339 ) ) ;
F_9 ( V_16 , L_191 ,
F_137 ( V_332 & ( V_340 |
F_142 ( 1 ) ) ) ) ;
F_9 ( V_16 , L_192 ,
( V_333 & V_341 ) ? L_193 : L_194 ) ;
F_9 ( V_16 , L_195 ,
( V_333 & V_342 ) ? L_193 : L_194 ) ;
F_9 ( V_16 , L_196 ,
F_69 ( V_343 ) ) ;
F_9 ( V_16 , L_197 ,
F_69 ( V_344 ) ) ;
return F_138 ( V_16 , NULL ) ;
}
static int F_143 ( struct V_15 * V_16 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_331 , V_345 , V_332 , V_346 = 0 ;
unsigned V_347 ;
int V_75 = 0 , V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
F_64 ( & V_36 -> V_328 . V_329 ) ;
V_347 = V_36 -> V_328 . V_327 [ V_348 ] . V_330 ;
F_72 ( & V_36 -> V_328 . V_329 ) ;
if ( V_347 ) {
F_26 ( V_16 , L_198
L_199 ) ;
} else {
while ( V_75 ++ < 50 && ( F_144 ( V_349 ) & 1 ) )
F_145 ( 10 ) ;
F_9 ( V_16 , L_200 , F_137 ( V_75 < 51 ) ) ;
}
V_345 = F_146 ( V_350 ) ;
F_147 ( false , V_350 , V_345 , 4 , true ) ;
V_331 = F_69 ( V_259 ) ;
V_332 = F_69 ( V_335 ) ;
F_6 ( & V_20 -> V_77 ) ;
F_4 ( & V_36 -> V_212 . V_223 ) ;
F_148 ( V_36 , V_351 , & V_346 ) ;
F_6 ( & V_36 -> V_212 . V_223 ) ;
F_78 ( V_36 ) ;
F_9 ( V_16 , L_189 ,
F_137 ( V_331 & V_336 ) ) ;
F_9 ( V_16 , L_171 ,
F_137 ( V_331 & V_337 ) ) ;
F_9 ( V_16 , L_172 ,
F_137 ( ( V_331 & V_338 ) ==
V_339 ) ) ;
F_9 ( V_16 , L_201 ,
F_137 ( V_332 & V_352 ) ) ;
F_9 ( V_16 , L_191 ,
F_137 ( V_332 & V_353 ) ) ;
F_9 ( V_16 , L_202 ,
F_137 ( V_332 & V_354 ) ) ;
F_9 ( V_16 , L_203 ,
F_137 ( V_332 & V_355 ) ) ;
F_26 ( V_16 , L_204 ) ;
switch ( V_345 & V_356 ) {
case V_357 :
if ( V_345 & V_358 )
F_26 ( V_16 , L_205 ) ;
else
F_26 ( V_16 , L_181 ) ;
break;
case V_359 :
F_26 ( V_16 , L_206 ) ;
break;
case V_360 :
F_26 ( V_16 , L_207 ) ;
break;
case V_361 :
F_26 ( V_16 , L_208 ) ;
break;
default:
F_26 ( V_16 , L_209 ) ;
break;
}
F_9 ( V_16 , L_210 ,
F_137 ( V_345 & V_358 ) ) ;
F_9 ( V_16 , L_211 ,
F_69 ( V_362 ) ) ;
F_9 ( V_16 , L_212 ,
F_69 ( V_363 ) ) ;
F_9 ( V_16 , L_213 ,
F_69 ( V_364 ) ) ;
F_9 ( V_16 , L_214 ,
F_69 ( V_365 ) ) ;
F_9 ( V_16 , L_215 ,
F_149 ( ( ( V_346 >> 0 ) & 0xff ) ) ) ;
F_9 ( V_16 , L_216 ,
F_149 ( ( ( V_346 >> 8 ) & 0xff ) ) ) ;
F_9 ( V_16 , L_217 ,
F_149 ( ( ( V_346 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_150 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
if ( F_92 ( V_20 ) || F_80 ( V_20 ) )
return F_141 ( V_16 ) ;
else if ( F_8 ( V_20 ) -> V_23 >= 6 )
return F_143 ( V_16 ) ;
else
return F_136 ( V_16 ) ;
}
static int F_151 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
F_9 ( V_16 , L_218 ,
V_36 -> V_366 . V_367 ) ;
F_9 ( V_16 , L_219 ,
V_36 -> V_366 . V_368 ) ;
return 0 ;
}
static int F_152 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_153 ( V_20 ) ) {
F_26 ( V_16 , L_220 ) ;
return 0 ;
}
F_77 ( V_36 ) ;
F_4 ( & V_36 -> V_369 . V_329 ) ;
if ( F_154 ( V_36 ) )
F_26 ( V_16 , L_221 ) ;
else
F_9 ( V_16 , L_222 ,
V_36 -> V_369 . V_370 ) ;
if ( F_8 ( V_36 ) -> V_23 >= 7 )
F_9 ( V_16 , L_223 ,
F_137 ( F_69 ( V_371 ) &
V_372 ) ) ;
F_6 ( & V_36 -> V_369 . V_329 ) ;
F_78 ( V_36 ) ;
return 0 ;
}
static int F_155 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 7 || ! F_153 ( V_20 ) )
return - V_373 ;
* V_210 = V_36 -> V_369 . V_374 ;
return 0 ;
}
static int F_156 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_375 ;
if ( F_8 ( V_20 ) -> V_23 < 7 || ! F_153 ( V_20 ) )
return - V_373 ;
F_4 ( & V_36 -> V_369 . V_329 ) ;
V_375 = F_69 ( V_376 ) ;
V_36 -> V_369 . V_374 = V_210 ;
F_157 ( V_376 , V_210 ?
( V_375 | V_377 ) :
( V_375 & ~ V_377 ) ) ;
F_6 ( & V_36 -> V_369 . V_329 ) ;
return 0 ;
}
static int F_158 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_159 ( V_20 ) ) {
F_26 ( V_16 , L_224 ) ;
return 0 ;
}
F_77 ( V_36 ) ;
F_9 ( V_16 , L_225 ,
F_137 ( V_290 . V_378 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 ) {
F_26 ( V_16 , L_226 ) ;
} else {
if ( F_69 ( V_379 ) & V_380 )
F_26 ( V_16 , L_227 ) ;
else
F_26 ( V_16 , L_228 ) ;
}
F_78 ( V_36 ) ;
return 0 ;
}
static int F_160 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_381 = false ;
F_77 ( V_36 ) ;
if ( F_93 ( V_20 ) )
V_381 = F_69 ( V_382 ) & V_383 ;
else if ( F_161 ( V_20 ) || F_162 ( V_20 ) ||
F_163 ( V_20 ) || F_164 ( V_20 ) )
V_381 = F_69 ( V_384 ) & V_385 ;
else if ( F_165 ( V_20 ) )
V_381 = F_69 ( V_386 ) & V_387 ;
else if ( F_166 ( V_20 ) )
V_381 = F_69 ( V_388 ) & V_389 ;
else if ( F_92 ( V_20 ) || F_80 ( V_20 ) )
V_381 = F_69 ( V_390 ) & V_391 ;
F_78 ( V_36 ) ;
F_9 ( V_16 , L_229 ,
V_381 ? L_230 : L_231 ) ;
return 0 ;
}
static int F_167 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
unsigned long V_392 , V_393 , V_394 ;
int V_76 ;
if ( ! F_116 ( V_20 ) )
return - V_373 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_392 = F_168 ( V_36 ) ;
V_393 = F_169 ( V_36 ) ;
V_394 = F_170 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
F_9 ( V_16 , L_232 , V_392 ) ;
F_9 ( V_16 , L_233 , V_393 ) ;
F_9 ( V_16 , L_234 , V_394 ) ;
F_9 ( V_16 , L_235 , V_393 + V_394 ) ;
return 0 ;
}
static int F_171 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 = 0 ;
int V_395 , V_396 ;
unsigned int V_397 , V_398 ;
if ( ! F_172 ( V_20 ) ) {
F_26 ( V_16 , L_236 ) ;
return 0 ;
}
F_77 ( V_36 ) ;
F_115 ( & V_36 -> V_212 . V_213 ) ;
V_76 = F_31 ( & V_36 -> V_212 . V_223 ) ;
if ( V_76 )
goto V_207;
if ( F_129 ( V_20 ) || F_130 ( V_20 ) ) {
V_398 =
V_36 -> V_212 . V_399 / V_282 ;
V_397 =
V_36 -> V_212 . V_400 / V_282 ;
} else {
V_398 = V_36 -> V_212 . V_399 ;
V_397 = V_36 -> V_212 . V_400 ;
}
F_26 ( V_16 , L_237 ) ;
for ( V_395 = V_398 ; V_395 <= V_397 ; V_395 ++ ) {
V_396 = V_395 ;
F_148 ( V_36 ,
V_401 ,
& V_396 ) ;
F_9 ( V_16 , L_238 ,
F_119 ( V_36 , ( V_395 *
( F_129 ( V_20 ) || F_130 ( V_20 ) ?
V_282 : 1 ) ) ) ,
( ( V_396 >> 0 ) & 0xff ) * 100 ,
( ( V_396 >> 8 ) & 0xff ) * 100 ) ;
}
F_6 ( & V_36 -> V_212 . V_223 ) ;
V_207:
F_78 ( V_36 ) ;
return V_76 ;
}
static int F_173 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_402 * V_403 = & V_36 -> V_403 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
goto V_207;
if ( V_403 -> V_404 )
F_174 ( V_16 , V_403 -> V_404 , V_405 ) ;
F_6 ( & V_20 -> V_77 ) ;
V_207:
return 0 ;
}
static int F_175 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_402 * V_403 = & V_36 -> V_403 ;
if ( V_403 -> V_406 )
F_174 ( V_16 , V_403 -> V_406 , V_403 -> V_407 ) ;
return 0 ;
}
static int F_176 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_408 * V_409 = NULL ;
struct V_410 * V_411 ;
#ifdef F_177
if ( F_22 ( V_20 ) -> V_412 ) {
V_409 = F_178 ( F_22 ( V_20 ) -> V_412 -> V_413 . V_414 ) ;
F_9 ( V_16 , L_239 ,
V_409 -> V_37 . V_415 ,
V_409 -> V_37 . V_416 ,
V_409 -> V_37 . V_417 ,
V_409 -> V_37 . V_418 ,
V_409 -> V_37 . V_419 [ 0 ] ,
F_65 ( & V_409 -> V_37 . V_420 . V_420 ) ) ;
F_21 ( V_16 , V_409 -> V_25 ) ;
F_29 ( V_16 , '\n' ) ;
}
#endif
F_4 ( & V_20 -> V_421 . V_422 ) ;
F_179 (drm_fb, dev) {
struct V_408 * V_414 = F_178 ( V_411 ) ;
if ( V_414 == V_409 )
continue;
F_9 ( V_16 , L_240 ,
V_414 -> V_37 . V_415 ,
V_414 -> V_37 . V_416 ,
V_414 -> V_37 . V_417 ,
V_414 -> V_37 . V_418 ,
V_414 -> V_37 . V_419 [ 0 ] ,
F_65 ( & V_414 -> V_37 . V_420 . V_420 ) ) ;
F_21 ( V_16 , V_414 -> V_25 ) ;
F_29 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_421 . V_422 ) ;
return 0 ;
}
static void F_180 ( struct V_15 * V_16 ,
struct V_423 * V_424 )
{
F_9 ( V_16 , L_241 ,
V_424 -> V_425 , V_424 -> V_68 , V_424 -> V_426 ,
V_424 -> V_427 ) ;
}
static int F_181 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_62 * V_63 ;
int V_76 , V_41 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_19 (ctx, &dev_priv->context_list, link) {
if ( ! V_290 . V_428 &&
V_63 -> V_64 . V_429 == NULL )
continue;
F_26 ( V_16 , L_242 ) ;
F_28 ( V_16 , V_63 ) ;
if ( V_63 == V_36 -> V_430 )
F_9 ( V_16 , L_243 ) ;
if ( V_290 . V_428 ) {
F_29 ( V_16 , '\n' ) ;
F_23 (ring, dev_priv, i) {
struct V_24 * V_431 =
V_63 -> V_432 [ V_41 ] . V_433 ;
struct V_423 * V_424 =
V_63 -> V_432 [ V_41 ] . V_424 ;
F_9 ( V_16 , L_244 , V_39 -> V_52 ) ;
if ( V_431 )
F_21 ( V_16 , V_431 ) ;
if ( V_424 )
F_180 ( V_16 , V_424 ) ;
F_29 ( V_16 , '\n' ) ;
}
} else {
F_21 ( V_16 , V_63 -> V_64 . V_429 ) ;
}
F_29 ( V_16 , '\n' ) ;
}
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static void F_182 ( struct V_15 * V_16 ,
struct V_62 * V_63 ,
struct V_38 * V_39 )
{
struct V_434 * V_434 ;
T_10 * V_435 ;
int V_103 ;
struct V_24 * V_431 = V_63 -> V_432 [ V_39 -> V_89 ] . V_433 ;
unsigned long V_436 = 0 ;
if ( V_431 == NULL ) {
F_9 ( V_16 , L_245 ,
V_39 -> V_52 ) ;
return;
}
F_9 ( V_16 , L_246 , V_39 -> V_52 ,
F_183 ( V_63 , V_39 ) ) ;
if ( ! F_43 ( V_431 ) )
F_26 ( V_16 , L_247 ) ;
else
V_436 = F_184 ( V_431 ) ;
if ( F_185 ( V_431 ) ) {
F_26 ( V_16 , L_248 ) ;
return;
}
V_434 = F_186 ( V_431 , V_437 ) ;
if ( ! F_187 ( V_434 == NULL ) ) {
V_435 = F_188 ( V_434 ) ;
for ( V_103 = 0 ; V_103 < 0x600 / sizeof( T_4 ) / 4 ; V_103 += 4 ) {
F_9 ( V_16 , L_249 ,
V_436 + 4096 + ( V_103 * 4 ) ,
V_435 [ V_103 ] , V_435 [ V_103 + 1 ] ,
V_435 [ V_103 + 2 ] , V_435 [ V_103 + 3 ] ) ;
}
F_189 ( V_435 ) ;
}
F_29 ( V_16 , '\n' ) ;
}
static int F_190 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_62 * V_63 ;
int V_76 , V_41 ;
if ( ! V_290 . V_428 ) {
F_9 ( V_16 , L_250 ) ;
return 0 ;
}
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_19 (ctx, &dev_priv->context_list, link)
if ( V_63 != V_36 -> V_430 )
F_23 (ring, dev_priv, i)
F_182 ( V_16 , V_63 , V_39 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_191 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
T_4 V_438 ;
T_11 V_439 ;
T_11 V_440 ;
T_4 V_441 ;
T_4 V_442 ;
struct V_67 * V_443 ;
int V_444 , V_41 ;
int V_76 ;
if ( ! V_290 . V_428 ) {
F_26 ( V_16 , L_250 ) ;
return 0 ;
}
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
F_23 (ring, dev_priv, ring_id) {
struct V_146 * V_445 = NULL ;
int V_75 = 0 ;
unsigned long V_446 ;
F_9 ( V_16 , L_251 , V_39 -> V_52 ) ;
V_441 = F_69 ( F_192 ( V_39 ) ) ;
V_442 = F_69 ( F_193 ( V_39 ) ) ;
F_9 ( V_16 , L_252 ,
V_441 , V_442 ) ;
V_438 = F_69 ( F_194 ( V_39 ) ) ;
F_9 ( V_16 , L_253 , V_438 ) ;
V_439 = V_39 -> V_447 ;
V_440 = F_195 ( V_438 ) ;
if ( V_439 > V_440 )
V_440 += V_448 ;
F_9 ( V_16 , L_254 ,
V_439 , V_440 ) ;
for ( V_41 = 0 ; V_41 < V_448 ; V_41 ++ ) {
V_441 = F_69 ( F_196 ( V_39 , V_41 ) ) ;
V_442 = F_69 ( F_197 ( V_39 , V_41 ) ) ;
F_9 ( V_16 , L_255 ,
V_41 , V_441 , V_442 ) ;
}
F_198 ( & V_39 -> V_449 , V_446 ) ;
F_199 (cursor, &ring->execlist_queue)
V_75 ++ ;
V_445 = F_200 ( & V_39 -> V_450 ,
struct V_146 , V_451 ) ;
F_201 ( & V_39 -> V_449 , V_446 ) ;
F_9 ( V_16 , L_256 , V_75 ) ;
if ( V_445 ) {
F_9 ( V_16 , L_257 ,
F_183 ( V_445 -> V_63 , V_39 ) ) ;
F_9 ( V_16 , L_258 ,
V_445 -> V_426 ) ;
}
F_29 ( V_16 , '\n' ) ;
}
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static const char * F_202 ( unsigned V_452 )
{
switch ( V_452 ) {
case V_453 :
return L_259 ;
case V_454 :
return L_260 ;
case V_455 :
return L_261 ;
case V_456 :
return L_262 ;
case V_457 :
return L_263 ;
case V_458 :
return L_264 ;
case V_459 :
return L_265 ;
case V_460 :
return L_266 ;
}
return L_267 ;
}
static int F_203 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
F_9 ( V_16 , L_268 ,
F_202 ( V_36 -> V_112 . V_461 ) ) ;
F_9 ( V_16 , L_269 ,
F_202 ( V_36 -> V_112 . V_462 ) ) ;
if ( F_204 ( V_20 ) || F_205 ( V_20 ) ) {
F_9 ( V_16 , L_270 ,
F_69 ( V_463 ) ) ;
F_9 ( V_16 , L_271 ,
F_69 ( V_464 ) ) ;
F_9 ( V_16 , L_272 ,
F_117 ( V_465 ) ) ;
F_9 ( V_16 , L_273 ,
F_117 ( V_466 ) ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 6 ) {
F_9 ( V_16 , L_274 ,
F_69 ( V_467 ) ) ;
F_9 ( V_16 , L_275 ,
F_69 ( V_468 ) ) ;
F_9 ( V_16 , L_276 ,
F_69 ( V_469 ) ) ;
F_9 ( V_16 , L_277 ,
F_69 ( V_470 ) ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 )
F_9 ( V_16 , L_278 ,
F_69 ( V_471 ) ) ;
else
F_9 ( V_16 , L_279 ,
F_69 ( V_472 ) ) ;
F_9 ( V_16 , L_280 ,
F_69 ( V_473 ) ) ;
}
if ( V_36 -> V_474 & V_475 )
F_26 ( V_16 , L_281 ) ;
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_206 ( int V_89 , void * V_90 , void * V_17 )
{
struct V_62 * V_63 = V_90 ;
struct V_15 * V_16 = V_17 ;
struct V_96 * V_97 = V_63 -> V_97 ;
if ( ! V_97 ) {
F_9 ( V_16 , L_282 ,
V_63 -> V_476 ) ;
return 0 ;
}
if ( F_207 ( V_63 ) )
F_26 ( V_16 , L_283 ) ;
else
F_9 ( V_16 , L_284 , V_63 -> V_476 ) ;
V_97 -> V_477 ( V_97 , V_16 ) ;
return 0 ;
}
static void F_208 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
struct V_96 * V_97 = V_36 -> V_112 . V_478 ;
int V_211 , V_41 ;
if ( ! V_97 )
return;
F_23 (ring, dev_priv, unused) {
F_9 ( V_16 , L_251 , V_39 -> V_52 ) ;
for ( V_41 = 0 ; V_41 < 4 ; V_41 ++ ) {
T_2 V_479 = F_69 ( F_209 ( V_39 , V_41 ) ) ;
V_479 <<= 32 ;
V_479 |= F_69 ( F_210 ( V_39 , V_41 ) ) ;
F_9 ( V_16 , L_285 , V_41 , V_479 ) ;
}
}
}
static void F_211 ( struct V_15 * V_16 , struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_41 ;
if ( F_8 ( V_20 ) -> V_23 == 6 )
F_9 ( V_16 , L_286 , F_69 ( V_480 ) ) ;
F_23 (ring, dev_priv, i) {
F_9 ( V_16 , L_251 , V_39 -> V_52 ) ;
if ( F_8 ( V_20 ) -> V_23 == 7 )
F_9 ( V_16 , L_286 , F_69 ( F_212 ( V_39 ) ) ) ;
F_9 ( V_16 , L_287 , F_69 ( F_213 ( V_39 ) ) ) ;
F_9 ( V_16 , L_288 , F_69 ( F_214 ( V_39 ) ) ) ;
F_9 ( V_16 , L_289 , F_69 ( F_215 ( V_39 ) ) ) ;
}
if ( V_36 -> V_112 . V_478 ) {
struct V_96 * V_97 = V_36 -> V_112 . V_478 ;
F_26 ( V_16 , L_290 ) ;
F_9 ( V_16 , L_291 , V_97 -> V_481 . V_37 . V_436 ) ;
V_97 -> V_477 ( V_97 , V_16 ) ;
}
F_9 ( V_16 , L_292 , F_69 ( V_482 ) ) ;
}
static int F_216 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_110 * V_111 ;
int V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
if ( F_8 ( V_20 ) -> V_23 >= 8 )
F_208 ( V_16 , V_20 ) ;
else if ( F_8 ( V_20 ) -> V_23 >= 6 )
F_211 ( V_16 , V_20 ) ;
F_51 (file, &dev->filelist, lhead) {
struct V_483 * V_99 = V_111 -> V_120 ;
struct V_118 * V_119 ;
V_119 = F_217 ( V_111 -> V_123 , V_124 ) ;
if ( ! V_119 ) {
V_76 = - V_484 ;
goto V_485;
}
F_9 ( V_16 , L_293 , V_119 -> V_125 ) ;
F_218 ( V_119 ) ;
F_53 ( & V_99 -> V_486 , F_206 ,
( void * ) ( unsigned long ) V_16 ) ;
}
V_485:
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
return V_76 ;
}
static int F_219 ( struct V_35 * V_290 )
{
struct V_38 * V_39 ;
int V_75 = 0 ;
int V_41 ;
F_23 (ring, i915, i)
V_75 += V_39 -> V_487 ;
return V_75 ;
}
static int F_220 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_110 * V_111 ;
F_9 ( V_16 , L_294 , V_36 -> V_212 . V_488 ) ;
F_9 ( V_16 , L_295 , V_36 -> V_112 . V_489 ) ;
F_9 ( V_16 , L_296 , F_219 ( V_36 ) ) ;
F_9 ( V_16 , L_297 ,
F_119 ( V_36 , V_36 -> V_212 . V_226 ) ,
F_119 ( V_36 , V_36 -> V_212 . V_228 ) ,
F_119 ( V_36 , V_36 -> V_212 . V_399 ) ,
F_119 ( V_36 , V_36 -> V_212 . V_400 ) ,
F_119 ( V_36 , V_36 -> V_212 . V_227 ) ) ;
F_52 ( & V_36 -> V_212 . V_490 ) ;
F_51 (file, &dev->filelist, lhead) {
struct V_483 * V_99 = V_111 -> V_120 ;
struct V_118 * V_119 ;
F_55 () ;
V_119 = F_56 ( V_111 -> V_123 , V_124 ) ;
F_9 ( V_16 , L_298 ,
V_119 ? V_119 -> V_125 : L_43 ,
V_119 ? V_119 -> V_123 : - 1 ,
V_99 -> V_212 . V_491 ,
F_37 ( & V_99 -> V_212 . V_492 ) ? L_13 : L_299 ) ;
F_57 () ;
}
F_9 ( V_16 , L_300 ,
V_36 -> V_212 . V_493 . V_491 ,
F_37 ( & V_36 -> V_212 . V_493 . V_492 ) ? L_13 : L_299 ) ;
F_9 ( V_16 , L_301 ,
V_36 -> V_212 . V_494 . V_491 ,
F_37 ( & V_36 -> V_212 . V_494 . V_492 ) ? L_13 : L_299 ) ;
F_9 ( V_16 , L_302 , V_36 -> V_212 . V_491 ) ;
F_54 ( & V_36 -> V_212 . V_490 ) ;
return 0 ;
}
static int F_221 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
F_9 ( V_16 , L_303 , F_137 ( F_222 ( V_20 ) ) ) ;
F_9 ( V_16 , L_304 , V_36 -> V_495 ) ;
return 0 ;
}
static int F_223 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_35 * V_36 = V_7 -> V_2 -> V_20 -> V_69 ;
struct V_496 * V_497 = & V_36 -> V_498 . V_497 ;
T_4 V_499 , V_41 ;
if ( ! F_224 ( V_36 -> V_20 ) )
return 0 ;
F_9 ( V_16 , L_305 ) ;
F_9 ( V_16 , L_306 ,
V_497 -> V_500 ) ;
F_9 ( V_16 , L_307 ,
F_225 ( V_497 -> V_501 ) ) ;
F_9 ( V_16 , L_308 ,
F_225 ( V_497 -> V_502 ) ) ;
F_9 ( V_16 , L_309 ,
V_497 -> V_503 , V_497 -> V_504 ) ;
F_9 ( V_16 , L_310 ,
V_497 -> V_505 , V_497 -> V_506 ) ;
F_9 ( V_16 , L_311 ,
V_497 -> V_507 , V_497 -> V_508 ) ;
F_9 ( V_16 , L_312 ,
V_497 -> V_509 , V_497 -> V_510 ) ;
F_9 ( V_16 , L_313 ,
V_497 -> V_511 , V_497 -> V_512 ) ;
V_499 = F_69 ( V_513 ) ;
F_9 ( V_16 , L_314 , V_499 ) ;
F_9 ( V_16 , L_315 ,
( V_499 & V_514 ) >> V_515 ) ;
F_9 ( V_16 , L_316 ,
( V_499 & V_516 ) >> V_517 ) ;
F_9 ( V_16 , L_317 ,
( V_499 & V_518 ) >> V_519 ) ;
F_26 ( V_16 , L_318 ) ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
F_9 ( V_16 , L_319 , V_41 , F_69 ( F_226 ( V_41 ) ) ) ;
return 0 ;
}
static void F_227 ( struct V_15 * V_16 ,
struct V_35 * V_36 ,
struct V_520 * V_521 )
{
struct V_38 * V_39 ;
T_12 V_522 = 0 ;
T_10 V_41 ;
F_9 ( V_16 , L_320 ,
V_521 -> V_523 , V_521 -> V_524 , V_521 -> V_525 ) ;
F_9 ( V_16 , L_321 ,
V_521 -> V_526 , V_521 -> V_527 , V_521 -> V_528 ) ;
F_9 ( V_16 , L_322 ,
V_521 -> V_529 , V_521 -> V_530 , V_521 -> V_531 ) ;
F_9 ( V_16 , L_323 , V_521 -> V_532 ) ;
F_9 ( V_16 , L_324 , V_521 -> V_533 ) ;
F_9 ( V_16 , L_325 , V_521 -> V_534 ) ;
F_23 (ring, dev_priv, i) {
F_9 ( V_16 , L_326 ,
V_521 -> V_535 [ V_39 -> V_536 ] ,
V_39 -> V_52 ) ;
V_522 += V_521 -> V_535 [ V_39 -> V_536 ] ;
}
F_9 ( V_16 , L_327 , V_522 ) ;
}
static int F_228 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_537 V_498 ;
struct V_520 V_521 = {} ;
struct V_38 * V_39 ;
enum V_538 V_41 ;
T_2 V_93 = 0 ;
if ( ! F_229 ( V_36 -> V_20 ) )
return 0 ;
if ( F_31 ( & V_20 -> V_77 ) )
return 0 ;
V_498 = V_36 -> V_498 ;
if ( V_498 . V_539 )
V_521 = * V_498 . V_539 ;
F_6 ( & V_20 -> V_77 ) ;
F_9 ( V_16 , L_328 , V_498 . V_540 ) ;
F_9 ( V_16 , L_329 , V_498 . V_541 ) ;
F_9 ( V_16 , L_330 , V_498 . V_542 ) ;
F_9 ( V_16 , L_331 , V_498 . V_543 ) ;
F_9 ( V_16 , L_332 , V_498 . V_544 ) ;
F_9 ( V_16 , L_333 ) ;
F_23 (ring, dev_priv, i) {
F_9 ( V_16 , L_334 ,
V_39 -> V_52 , V_498 . V_535 [ V_39 -> V_536 ] ,
V_498 . V_545 [ V_39 -> V_536 ] ) ;
V_93 += V_498 . V_535 [ V_39 -> V_536 ] ;
}
F_9 ( V_16 , L_335 , L_336 , V_93 ) ;
F_9 ( V_16 , L_337 , V_498 . V_539 ) ;
F_227 ( V_16 , V_36 , & V_521 ) ;
return 0 ;
}
static int F_230 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_24 * V_546 = V_36 -> V_498 . V_546 ;
T_4 * log ;
int V_41 = 0 , V_547 ;
if ( ! V_546 )
return 0 ;
for ( V_547 = 0 ; V_547 < V_546 -> V_37 . V_31 / V_548 ; V_547 ++ ) {
log = F_188 ( F_186 ( V_546 , V_547 ) ) ;
for ( V_41 = 0 ; V_41 < V_548 / sizeof( T_4 ) ; V_41 += 4 )
F_9 ( V_16 , L_338 ,
* ( log + V_41 ) , * ( log + V_41 + 1 ) ,
* ( log + V_41 + 2 ) , * ( log + V_41 + 3 ) ) ;
F_189 ( log ) ;
}
F_29 ( V_16 , '\n' ) ;
return 0 ;
}
static int F_231 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_549 = 0 ;
T_4 V_550 [ 3 ] ;
enum V_129 V_129 ;
bool V_488 = false ;
if ( ! F_232 ( V_20 ) ) {
F_26 ( V_16 , L_339 ) ;
return 0 ;
}
F_77 ( V_36 ) ;
F_4 ( & V_36 -> V_551 . V_329 ) ;
F_9 ( V_16 , L_340 , F_137 ( V_36 -> V_551 . V_552 ) ) ;
F_9 ( V_16 , L_341 , F_137 ( V_36 -> V_551 . V_553 ) ) ;
F_9 ( V_16 , L_342 , F_137 ( ( bool ) V_36 -> V_551 . V_488 ) ) ;
F_9 ( V_16 , L_343 , F_137 ( V_36 -> V_551 . V_42 ) ) ;
F_9 ( V_16 , L_344 ,
V_36 -> V_551 . V_554 ) ;
F_9 ( V_16 , L_345 ,
F_137 ( F_233 ( & V_36 -> V_551 . V_132 . V_132 ) ) ) ;
if ( F_234 ( V_20 ) )
V_488 = F_69 ( V_555 ) & V_556 ;
else {
F_81 (dev_priv, pipe) {
V_550 [ V_129 ] = F_69 ( F_235 ( V_129 ) ) &
V_557 ;
if ( ( V_550 [ V_129 ] == V_558 ) ||
( V_550 [ V_129 ] == V_559 ) )
V_488 = true ;
}
}
F_9 ( V_16 , L_346 ,
F_137 ( V_36 -> V_551 . V_560 ) ) ;
F_9 ( V_16 , L_347 , F_137 ( V_488 ) ) ;
if ( ! F_234 ( V_20 ) )
F_81 (dev_priv, pipe) {
if ( ( V_550 [ V_129 ] == V_558 ) ||
( V_550 [ V_129 ] == V_559 ) )
F_9 ( V_16 , L_348 , F_62 ( V_129 ) ) ;
}
F_26 ( V_16 , L_30 ) ;
if ( F_123 ( V_20 ) || F_124 ( V_20 ) ) {
V_549 = F_69 ( V_561 ) &
V_562 ;
F_9 ( V_16 , L_349 , V_549 ) ;
}
F_6 ( & V_36 -> V_551 . V_329 ) ;
F_78 ( V_36 ) ;
return 0 ;
}
static int F_236 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_563 * V_564 ;
struct V_565 * V_566 ;
struct V_567 * V_567 = NULL ;
int V_76 ;
T_11 V_568 [ 6 ] ;
F_237 ( V_20 ) ;
F_238 (dev, connector) {
if ( V_566 -> V_37 . V_569 != V_570 )
continue;
if ( ! V_566 -> V_37 . V_564 )
continue;
V_564 = F_239 ( V_566 -> V_37 . V_564 ) ;
if ( V_564 -> type != V_571 )
continue;
V_567 = F_240 ( & V_564 -> V_37 ) ;
V_76 = F_241 ( V_567 , V_568 ) ;
if ( V_76 )
goto V_207;
F_9 ( V_16 , L_350 ,
V_568 [ 0 ] , V_568 [ 1 ] , V_568 [ 2 ] ,
V_568 [ 3 ] , V_568 [ 4 ] , V_568 [ 5 ] ) ;
goto V_207;
}
V_76 = - V_373 ;
V_207:
F_242 ( V_20 ) ;
return V_76 ;
}
static int F_243 ( struct V_15 * V_16 , void * V_17 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_2 V_572 ;
T_4 V_573 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_373 ;
F_77 ( V_36 ) ;
F_244 ( V_574 , V_572 ) ;
V_572 = ( V_572 & 0x1f00 ) >> 8 ;
V_573 = 1000000 / ( 1 << V_572 ) ;
V_572 = F_69 ( V_575 ) ;
V_572 *= V_573 ;
F_78 ( V_36 ) ;
F_9 ( V_16 , L_351 , ( long long unsigned ) V_572 ) ;
return 0 ;
}
static int F_245 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( ! F_246 ( V_20 ) ) {
F_26 ( V_16 , L_224 ) ;
return 0 ;
}
F_9 ( V_16 , L_352 , F_137 ( ! V_36 -> V_112 . V_489 ) ) ;
F_9 ( V_16 , L_353 ,
F_137 ( ! F_247 ( V_36 ) ) ) ;
#ifdef F_248
F_9 ( V_16 , L_354 ,
F_65 ( & V_20 -> V_20 -> V_572 . V_576 ) ) ;
#else
F_9 ( V_16 , L_355 ) ;
#endif
return 0 ;
}
static int F_249 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_577 * V_578 = & V_36 -> V_578 ;
int V_41 ;
F_4 ( & V_578 -> V_329 ) ;
F_9 ( V_16 , L_356 , L_357 , L_358 ) ;
for ( V_41 = 0 ; V_41 < V_578 -> V_579 ; V_41 ++ ) {
struct V_580 * V_581 ;
enum V_163 V_164 ;
V_581 = & V_578 -> V_582 [ V_41 ] ;
F_9 ( V_16 , L_359 , V_581 -> V_52 ,
V_581 -> V_75 ) ;
for ( V_164 = 0 ; V_164 < V_583 ;
V_164 ++ ) {
if ( ! ( F_250 ( V_164 ) & V_581 -> V_584 ) )
continue;
F_9 ( V_16 , L_360 ,
F_251 ( V_164 ) ,
V_578 -> V_585 [ V_164 ] ) ;
}
}
F_6 ( & V_578 -> V_329 ) ;
return 0 ;
}
static int F_252 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_586 * V_587 ;
if ( ! F_253 ( V_20 ) ) {
F_26 ( V_16 , L_224 ) ;
return 0 ;
}
V_587 = & V_36 -> V_587 ;
F_77 ( V_36 ) ;
F_9 ( V_16 , L_361 , F_137 ( V_587 -> V_588 != NULL ) ) ;
F_9 ( V_16 , L_362 , V_587 -> V_589 ) ;
if ( ! V_587 -> V_588 )
goto V_207;
F_9 ( V_16 , L_363 , F_254 ( V_587 -> V_590 ) ,
F_255 ( V_587 -> V_590 ) ) ;
if ( F_129 ( V_20 ) && V_587 -> V_590 >= F_256 ( 1 , 6 ) ) {
F_9 ( V_16 , L_364 ,
F_69 ( V_591 ) ) ;
F_9 ( V_16 , L_365 ,
F_69 ( V_592 ) ) ;
} else if ( F_120 ( V_20 ) && V_587 -> V_590 >= F_256 ( 1 , 4 ) ) {
F_9 ( V_16 , L_364 ,
F_69 ( V_593 ) ) ;
}
V_207:
F_9 ( V_16 , L_366 , F_69 ( F_257 ( 0 ) ) ) ;
F_9 ( V_16 , L_367 , F_69 ( V_594 ) ) ;
F_9 ( V_16 , L_368 , F_69 ( V_595 ) ) ;
F_78 ( V_36 ) ;
return 0 ;
}
static void F_258 ( struct V_15 * V_16 , int V_596 ,
struct V_597 * V_598 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_596 ; V_41 ++ )
F_29 ( V_16 , '\t' ) ;
F_9 ( V_16 , L_369 ,
V_598 -> V_37 . V_89 , V_598 -> V_52 ,
V_598 -> V_599 , V_598 -> clock ,
V_598 -> V_600 , V_598 -> V_601 ,
V_598 -> V_602 , V_598 -> V_603 ,
V_598 -> V_604 , V_598 -> V_605 ,
V_598 -> V_606 , V_598 -> V_607 ,
V_598 -> type , V_598 -> V_446 ) ;
}
static void F_259 ( struct V_15 * V_16 ,
struct V_127 * V_127 ,
struct V_563 * V_563 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_608 * V_128 = & V_127 -> V_37 ;
struct V_565 * V_565 ;
struct V_609 * V_564 ;
V_564 = & V_563 -> V_37 ;
F_9 ( V_16 , L_370 ,
V_564 -> V_37 . V_89 , V_564 -> V_52 ) ;
F_260 (dev, encoder, intel_connector) {
struct V_610 * V_566 = & V_565 -> V_37 ;
F_9 ( V_16 , L_371 ,
V_566 -> V_37 . V_89 ,
V_566 -> V_52 ,
F_261 ( V_566 -> V_441 ) ) ;
if ( V_566 -> V_441 == V_611 ) {
struct V_597 * V_598 = & V_128 -> V_598 ;
F_9 ( V_16 , L_372 ) ;
F_258 ( V_16 , 2 , V_598 ) ;
} else {
F_29 ( V_16 , '\n' ) ;
}
}
}
static void F_262 ( struct V_15 * V_16 , struct V_127 * V_127 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_608 * V_128 = & V_127 -> V_37 ;
struct V_563 * V_563 ;
struct V_612 * V_613 = V_128 -> V_614 -> V_433 ;
struct V_410 * V_414 = V_613 -> V_414 ;
if ( V_414 )
F_9 ( V_16 , L_373 ,
V_414 -> V_37 . V_89 , V_613 -> V_615 >> 16 ,
V_613 -> V_616 >> 16 , V_414 -> V_415 , V_414 -> V_416 ) ;
else
F_26 ( V_16 , L_374 ) ;
F_263 (dev, crtc, intel_encoder)
F_259 ( V_16 , V_127 , V_563 ) ;
}
static void F_264 ( struct V_15 * V_16 , struct V_617 * V_618 )
{
struct V_597 * V_598 = V_618 -> V_619 ;
F_9 ( V_16 , L_375 ) ;
F_258 ( V_16 , 2 , V_598 ) ;
}
static void F_265 ( struct V_15 * V_16 ,
struct V_565 * V_565 )
{
struct V_563 * V_563 = V_565 -> V_564 ;
struct V_567 * V_567 = F_240 ( & V_563 -> V_37 ) ;
F_9 ( V_16 , L_376 , V_567 -> V_620 [ V_621 ] ) ;
F_9 ( V_16 , L_377 , F_137 ( V_567 -> V_622 ) ) ;
if ( V_563 -> type == V_571 )
F_264 ( V_16 , & V_565 -> V_618 ) ;
}
static void F_266 ( struct V_15 * V_16 ,
struct V_565 * V_565 )
{
struct V_563 * V_563 = V_565 -> V_564 ;
struct V_623 * V_623 = F_267 ( & V_563 -> V_37 ) ;
F_9 ( V_16 , L_377 , F_137 ( V_623 -> V_622 ) ) ;
}
static void F_268 ( struct V_15 * V_16 ,
struct V_565 * V_565 )
{
F_264 ( V_16 , & V_565 -> V_618 ) ;
}
static void F_269 ( struct V_15 * V_16 ,
struct V_610 * V_566 )
{
struct V_565 * V_565 = F_270 ( V_566 ) ;
struct V_563 * V_563 = V_565 -> V_564 ;
struct V_597 * V_598 ;
F_9 ( V_16 , L_378 ,
V_566 -> V_37 . V_89 , V_566 -> V_52 ,
F_261 ( V_566 -> V_441 ) ) ;
if ( V_566 -> V_441 == V_611 ) {
F_9 ( V_16 , L_379 , V_566 -> V_624 . V_52 ) ;
F_9 ( V_16 , L_380 ,
V_566 -> V_624 . V_625 ,
V_566 -> V_624 . V_626 ) ;
F_9 ( V_16 , L_381 ,
F_271 ( V_566 -> V_624 . V_627 ) ) ;
F_9 ( V_16 , L_382 ,
V_566 -> V_624 . V_628 ) ;
}
if ( V_563 ) {
if ( V_563 -> type == V_629 ||
V_563 -> type == V_571 )
F_265 ( V_16 , V_565 ) ;
else if ( V_563 -> type == V_630 )
F_266 ( V_16 , V_565 ) ;
else if ( V_563 -> type == V_631 )
F_268 ( V_16 , V_565 ) ;
}
F_9 ( V_16 , L_383 ) ;
F_19 (mode, &connector->modes, head)
F_258 ( V_16 , 2 , V_598 ) ;
}
static bool F_272 ( struct V_19 * V_20 , int V_129 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_433 ;
if ( F_273 ( V_20 ) || F_274 ( V_20 ) )
V_433 = F_69 ( F_275 ( V_632 ) ) & V_633 ;
else
V_433 = F_69 ( F_275 ( V_129 ) ) & V_634 ;
return V_433 ;
}
static bool F_276 ( struct V_19 * V_20 , int V_129 , int * T_1 , int * V_635 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_202 ;
V_202 = F_69 ( F_277 ( V_129 ) ) ;
* T_1 = ( V_202 >> V_636 ) & V_637 ;
if ( V_202 & ( V_638 << V_636 ) )
* T_1 = - * T_1 ;
* V_635 = ( V_202 >> V_639 ) & V_637 ;
if ( V_202 & ( V_638 << V_639 ) )
* V_635 = - * V_635 ;
return F_272 ( V_20 , V_129 ) ;
}
static const char * F_278 ( enum V_640 type )
{
switch ( type ) {
case V_641 :
return L_384 ;
case V_642 :
return L_385 ;
case V_643 :
return L_386 ;
}
return L_266 ;
}
static const char * F_279 ( unsigned int V_644 )
{
static char V_208 [ 48 ] ;
snprintf ( V_208 , sizeof( V_208 ) ,
L_387 ,
( V_644 & F_250 ( V_645 ) ) ? L_388 : L_13 ,
( V_644 & F_250 ( V_646 ) ) ? L_389 : L_13 ,
( V_644 & F_250 ( V_647 ) ) ? L_390 : L_13 ,
( V_644 & F_250 ( V_648 ) ) ? L_391 : L_13 ,
( V_644 & F_250 ( V_649 ) ) ? L_392 : L_13 ,
( V_644 & F_250 ( V_650 ) ) ? L_393 : L_13 ,
V_644 ) ;
return V_208 ;
}
static void F_280 ( struct V_15 * V_16 , struct V_127 * V_127 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_651 * V_651 ;
F_281 (dev, intel_crtc, intel_plane) {
struct V_612 * V_433 ;
struct V_652 * V_130 = & V_651 -> V_37 ;
if ( ! V_130 -> V_433 ) {
F_26 ( V_16 , L_394 ) ;
continue;
}
V_433 = V_130 -> V_433 ;
F_9 ( V_16 , L_395 ,
V_130 -> V_37 . V_89 ,
F_278 ( V_651 -> V_37 . type ) ,
V_433 -> V_653 , V_433 -> V_654 ,
V_433 -> V_655 , V_433 -> V_656 ,
( V_433 -> V_615 >> 16 ) ,
( ( V_433 -> V_615 & 0xffff ) * 15625 ) >> 10 ,
( V_433 -> V_616 >> 16 ) ,
( ( V_433 -> V_616 & 0xffff ) * 15625 ) >> 10 ,
( V_433 -> V_657 >> 16 ) ,
( ( V_433 -> V_657 & 0xffff ) * 15625 ) >> 10 ,
( V_433 -> V_658 >> 16 ) ,
( ( V_433 -> V_658 & 0xffff ) * 15625 ) >> 10 ,
V_433 -> V_414 ? F_282 ( V_433 -> V_414 -> V_659 ) : L_396 ,
F_279 ( V_433 -> V_644 ) ) ;
}
}
static void F_283 ( struct V_15 * V_16 , struct V_127 * V_127 )
{
struct V_660 * V_661 ;
int V_662 = V_127 -> V_662 ;
int V_41 ;
V_661 = F_284 ( V_127 -> V_37 . V_433 ) ;
if ( V_662 ) {
F_9 ( V_16 , L_397 ,
V_662 ,
V_661 -> V_663 . V_664 ,
V_661 -> V_663 . V_665 ) ;
for ( V_41 = 0 ; V_41 < V_666 ; V_41 ++ ) {
struct V_667 * V_668 =
& V_661 -> V_663 . V_669 [ V_41 ] ;
F_9 ( V_16 , L_398 ,
V_41 , F_137 ( V_668 -> V_670 ) , V_668 -> V_598 ) ;
}
F_26 ( V_16 , L_30 ) ;
} else {
F_26 ( V_16 , L_399 ) ;
}
}
static int F_285 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_127 * V_128 ;
struct V_610 * V_566 ;
F_77 ( V_36 ) ;
F_237 ( V_20 ) ;
F_9 ( V_16 , L_400 ) ;
F_9 ( V_16 , L_401 ) ;
F_61 (dev, crtc) {
bool V_42 ;
struct V_660 * V_661 ;
int T_1 , V_635 ;
V_661 = F_284 ( V_128 -> V_37 . V_433 ) ;
F_9 ( V_16 , L_402 ,
V_128 -> V_37 . V_37 . V_89 , F_62 ( V_128 -> V_129 ) ,
F_137 ( V_661 -> V_37 . V_42 ) ,
V_661 -> V_671 , V_661 -> V_672 ,
F_137 ( V_661 -> V_673 ) , V_661 -> V_674 ) ;
if ( V_661 -> V_37 . V_42 ) {
F_262 ( V_16 , V_128 ) ;
V_42 = F_276 ( V_20 , V_128 -> V_129 , & T_1 , & V_635 ) ;
F_9 ( V_16 , L_403 ,
F_137 ( V_128 -> V_675 ) ,
T_1 , V_635 , V_128 -> V_37 . V_443 -> V_433 -> V_655 ,
V_128 -> V_37 . V_443 -> V_433 -> V_656 ,
V_128 -> V_676 , F_137 ( V_42 ) ) ;
F_283 ( V_16 , V_128 ) ;
F_280 ( V_16 , V_128 ) ;
}
F_9 ( V_16 , L_404 ,
F_137 ( ! V_128 -> V_677 ) ,
F_137 ( ! V_128 -> V_678 ) ) ;
}
F_9 ( V_16 , L_30 ) ;
F_9 ( V_16 , L_405 ) ;
F_9 ( V_16 , L_406 ) ;
F_19 (connector, &dev->mode_config.connector_list, head) {
F_269 ( V_16 , V_566 ) ;
}
F_242 ( V_20 ) ;
F_78 ( V_36 ) ;
return 0 ;
}
static int F_286 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_38 * V_39 ;
int V_679 = F_287 ( F_8 ( V_20 ) -> V_680 ) ;
int V_41 , V_103 , V_76 ;
if ( ! F_288 ( V_20 ) ) {
F_26 ( V_16 , L_407 ) ;
return 0 ;
}
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
if ( F_124 ( V_20 ) ) {
struct V_434 * V_434 ;
T_12 * V_149 ;
V_434 = F_186 ( V_36 -> V_681 , 0 ) ;
V_149 = ( T_12 * ) F_188 ( V_434 ) ;
F_23 (ring, dev_priv, i) {
T_12 V_682 ;
F_9 ( V_16 , L_251 , V_39 -> V_52 ) ;
F_26 ( V_16 , L_408 ) ;
for ( V_103 = 0 ; V_103 < V_679 ; V_103 ++ ) {
V_682 = V_41 * V_287 + V_103 ;
F_9 ( V_16 , L_409 ,
V_149 [ V_682 ] , V_682 * 8 ) ;
}
F_29 ( V_16 , '\n' ) ;
F_26 ( V_16 , L_410 ) ;
for ( V_103 = 0 ; V_103 < V_679 ; V_103 ++ ) {
V_682 = V_41 + ( V_103 * V_287 ) ;
F_9 ( V_16 , L_409 ,
V_149 [ V_682 ] , V_682 * 8 ) ;
}
F_29 ( V_16 , '\n' ) ;
}
F_189 ( V_149 ) ;
} else {
F_26 ( V_16 , L_408 ) ;
F_23 (ring, dev_priv, i)
for ( V_103 = 0 ; V_103 < V_679 ; V_103 ++ )
F_9 ( V_16 , L_411 ,
F_69 ( V_39 -> V_683 . V_684 . signal [ V_103 ] ) ) ;
F_29 ( V_16 , '\n' ) ;
}
F_26 ( V_16 , L_412 ) ;
F_23 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < V_679 ; V_103 ++ ) {
F_9 ( V_16 , L_413 , V_39 -> V_683 . V_685 [ V_103 ] ) ;
}
F_29 ( V_16 , '\n' ) ;
}
F_29 ( V_16 , '\n' ) ;
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_289 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 ;
F_237 ( V_20 ) ;
for ( V_41 = 0 ; V_41 < V_36 -> V_686 ; V_41 ++ ) {
struct V_687 * V_688 = & V_36 -> V_689 [ V_41 ] ;
F_9 ( V_16 , L_414 , V_41 , V_688 -> V_52 , V_688 -> V_89 ) ;
F_9 ( V_16 , L_415 ,
V_688 -> V_690 . V_691 , V_688 -> V_42 , F_137 ( V_688 -> V_692 ) ) ;
F_9 ( V_16 , L_416 ) ;
F_9 ( V_16 , L_417 , V_688 -> V_690 . V_693 . V_694 ) ;
F_9 ( V_16 , L_418 ,
V_688 -> V_690 . V_693 . V_695 ) ;
F_9 ( V_16 , L_419 , V_688 -> V_690 . V_693 . V_696 ) ;
F_9 ( V_16 , L_420 , V_688 -> V_690 . V_693 . V_697 ) ;
F_9 ( V_16 , L_421 , V_688 -> V_690 . V_693 . V_698 ) ;
}
F_242 ( V_20 ) ;
return 0 ;
}
static int F_290 ( struct V_15 * V_16 , void * V_211 )
{
int V_41 ;
int V_76 ;
struct V_38 * V_39 ;
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_699 * V_700 = & V_36 -> V_700 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
F_9 ( V_16 , L_422 , V_700 -> V_75 ) ;
F_23 (ring, dev_priv, i)
F_9 ( V_16 , L_423 ,
V_39 -> V_52 , V_700 -> V_701 [ V_41 ] ) ;
for ( V_41 = 0 ; V_41 < V_700 -> V_75 ; ++ V_41 ) {
T_13 V_135 ;
T_4 V_702 , V_703 , V_704 ;
bool V_705 ;
V_135 = V_700 -> V_375 [ V_41 ] . V_135 ;
V_702 = V_700 -> V_375 [ V_41 ] . V_702 ;
V_703 = V_700 -> V_375 [ V_41 ] . V_703 ;
V_704 = F_69 ( V_135 ) ;
V_705 = ( V_703 & V_702 ) == ( V_704 & V_702 ) ;
F_9 ( V_16 , L_424 ,
F_291 ( V_135 ) , V_703 , V_702 , V_704 , V_705 ? L_425 : L_426 ) ;
}
F_78 ( V_36 ) ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int F_292 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_706 * V_707 ;
struct V_708 * V_709 ;
enum V_129 V_129 ;
int V_130 ;
if ( F_8 ( V_20 ) -> V_23 < 9 )
return 0 ;
F_237 ( V_20 ) ;
V_707 = & V_36 -> V_710 . V_711 . V_707 ;
F_9 ( V_16 , L_427 , L_13 , L_428 , L_429 , L_430 ) ;
F_81 (dev_priv, pipe) {
F_9 ( V_16 , L_431 , F_62 ( V_129 ) ) ;
F_293 (dev_priv, pipe, plane) {
V_709 = & V_707 -> V_130 [ V_129 ] [ V_130 ] ;
F_9 ( V_16 , L_432 , V_130 + 1 ,
V_709 -> V_55 , V_709 -> V_712 ,
F_294 ( V_709 ) ) ;
}
V_709 = & V_707 -> V_130 [ V_129 ] [ V_713 ] ;
F_9 ( V_16 , L_433 , L_434 , V_709 -> V_55 ,
V_709 -> V_712 , F_294 ( V_709 ) ) ;
}
F_242 ( V_20 ) ;
return 0 ;
}
static void F_295 ( struct V_15 * V_16 ,
struct V_19 * V_20 , struct V_127 * V_127 )
{
struct V_563 * V_563 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_714 * V_715 = & V_36 -> V_715 ;
int V_599 = 0 ;
F_263 (dev, &intel_crtc->base, intel_encoder) {
switch ( V_563 -> type ) {
case V_571 :
F_26 ( V_16 , L_435 ) ;
break;
case V_716 :
F_26 ( V_16 , L_436 ) ;
break;
case V_630 :
F_26 ( V_16 , L_437 ) ;
break;
case V_629 :
F_26 ( V_16 , L_438 ) ;
break;
default:
F_9 ( V_16 , L_439 ,
V_563 -> type ) ;
return;
}
}
if ( V_36 -> V_406 . V_717 == V_718 )
F_26 ( V_16 , L_440 ) ;
else if ( V_36 -> V_406 . V_717 == V_719 )
F_26 ( V_16 , L_441 ) ;
else if ( V_36 -> V_406 . V_717 == V_720 )
F_26 ( V_16 , L_442 ) ;
else
F_26 ( V_16 , L_443 ) ;
F_26 ( V_16 , L_444 ) ;
if ( F_284 ( V_127 -> V_37 . V_433 ) -> V_721 ) {
struct V_617 * V_618 ;
F_4 ( & V_715 -> V_722 ) ;
F_26 ( V_16 , L_445 ) ;
if ( ! V_715 -> V_723 ) {
F_26 ( V_16 , L_446 ) ;
F_6 ( & V_715 -> V_722 ) ;
return;
}
V_618 = & V_715 -> V_723 -> V_724 -> V_618 ;
F_9 ( V_16 , L_447 ,
V_715 -> V_554 ) ;
F_26 ( V_16 , L_448 ) ;
if ( V_715 -> V_725 == V_726 ) {
F_26 ( V_16 , L_449 ) ;
V_599 = V_618 -> V_619 -> V_599 ;
} else if ( V_715 -> V_725 == V_727 ) {
F_26 ( V_16 , L_450 ) ;
V_599 = V_618 -> V_728 -> V_599 ;
} else {
F_9 ( V_16 , L_451 ,
V_715 -> V_725 ) ;
F_6 ( & V_715 -> V_722 ) ;
return;
}
F_9 ( V_16 , L_452 , V_599 ) ;
F_26 ( V_16 , L_448 ) ;
F_6 ( & V_715 -> V_722 ) ;
} else {
F_26 ( V_16 , L_453 ) ;
}
F_26 ( V_16 , L_30 ) ;
}
static int F_296 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_127 * V_127 ;
int V_729 = 0 ;
F_61 (dev, intel_crtc) {
F_297 ( & V_127 -> V_37 . V_722 , NULL ) ;
if ( V_127 -> V_37 . V_433 -> V_42 ) {
V_729 ++ ;
F_9 ( V_16 , L_454 , V_729 ) ;
F_295 ( V_16 , V_20 , V_127 ) ;
}
F_298 ( & V_127 -> V_37 . V_722 ) ;
}
if ( ! V_729 )
F_26 ( V_16 , L_455 ) ;
return 0 ;
}
static int F_299 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_609 * V_564 ;
struct V_563 * V_563 ;
struct V_730 * V_731 ;
F_237 ( V_20 ) ;
F_19 (encoder, &dev->mode_config.encoder_list, head) {
V_563 = F_239 ( V_564 ) ;
if ( V_563 -> type != V_629 )
continue;
V_731 = F_300 ( V_564 ) ;
if ( ! V_731 -> V_723 . V_732 )
continue;
F_301 ( V_16 , & V_731 -> V_723 . V_733 ) ;
}
F_242 ( V_20 ) ;
return 0 ;
}
static int F_302 ( struct V_199 * V_199 , struct V_111 * V_734 )
{
struct V_735 * V_22 = V_199 -> V_200 ;
struct V_35 * V_36 = V_22 -> V_20 -> V_69 ;
struct V_736 * V_737 = & V_36 -> V_737 [ V_22 -> V_129 ] ;
if ( V_22 -> V_129 >= F_8 ( V_22 -> V_20 ) -> V_738 )
return - V_373 ;
F_64 ( & V_737 -> V_329 ) ;
if ( V_737 -> V_739 ) {
F_72 ( & V_737 -> V_329 ) ;
return - V_740 ;
}
V_737 -> V_739 = true ;
V_734 -> V_198 = V_199 -> V_200 ;
F_72 ( & V_737 -> V_329 ) ;
return 0 ;
}
static int F_303 ( struct V_199 * V_199 , struct V_111 * V_734 )
{
struct V_735 * V_22 = V_199 -> V_200 ;
struct V_35 * V_36 = V_22 -> V_20 -> V_69 ;
struct V_736 * V_737 = & V_36 -> V_737 [ V_22 -> V_129 ] ;
F_64 ( & V_737 -> V_329 ) ;
V_737 -> V_739 = false ;
F_72 ( & V_737 -> V_329 ) ;
return 0 ;
}
static int F_304 ( struct V_736 * V_737 )
{
F_305 ( & V_737 -> V_329 ) ;
return F_306 ( V_737 -> V_68 , V_737 -> V_426 ,
V_741 ) ;
}
static T_5
F_307 ( struct V_111 * V_734 , char T_6 * V_742 , T_7 V_75 ,
T_8 * V_202 )
{
struct V_735 * V_22 = V_734 -> V_198 ;
struct V_19 * V_20 = V_22 -> V_20 ;
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_736 * V_737 = & V_36 -> V_737 [ V_22 -> V_129 ] ;
char V_208 [ V_743 ] ;
int V_744 ;
T_5 V_745 ;
if ( V_75 < V_746 )
return - V_82 ;
if ( V_737 -> V_747 == V_748 )
return 0 ;
F_64 ( & V_737 -> V_329 ) ;
while ( F_304 ( V_737 ) == 0 ) {
int V_76 ;
if ( V_734 -> V_749 & V_750 ) {
F_72 ( & V_737 -> V_329 ) ;
return - V_751 ;
}
V_76 = F_308 ( V_737 -> V_752 ,
F_304 ( V_737 ) , V_737 -> V_329 ) ;
if ( V_76 ) {
F_72 ( & V_737 -> V_329 ) ;
return V_76 ;
}
}
V_744 = V_75 / V_746 ;
V_745 = 0 ;
while ( V_744 > 0 ) {
struct V_753 * V_709 =
& V_737 -> V_754 [ V_737 -> V_426 ] ;
int V_76 ;
if ( F_306 ( V_737 -> V_68 , V_737 -> V_426 ,
V_741 ) < 1 )
break;
F_309 ( V_741 ) ;
V_737 -> V_426 = ( V_737 -> V_426 + 1 ) & ( V_741 - 1 ) ;
V_745 += snprintf ( V_208 , V_743 ,
L_456 ,
V_709 -> V_755 , V_709 -> V_568 [ 0 ] ,
V_709 -> V_568 [ 1 ] , V_709 -> V_568 [ 2 ] ,
V_709 -> V_568 [ 3 ] , V_709 -> V_568 [ 4 ] ) ;
F_72 ( & V_737 -> V_329 ) ;
V_76 = F_310 ( V_742 , V_208 , V_746 ) ;
if ( V_76 == V_746 )
return - V_756 ;
V_742 += V_746 ;
V_744 -- ;
F_64 ( & V_737 -> V_329 ) ;
}
F_72 ( & V_737 -> V_329 ) ;
return V_745 ;
}
static int F_311 ( struct V_3 * V_757 , struct V_1 * V_2 ,
enum V_129 V_129 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
struct V_735 * V_22 = & V_758 [ V_129 ] ;
V_22 -> V_20 = V_20 ;
V_4 = F_312 ( V_22 -> V_52 , V_759 , V_757 , V_22 ,
& V_760 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , V_22 ) ;
}
static const char * F_313 ( enum V_761 V_747 )
{
F_314 ( F_45 ( V_762 ) != V_763 ) ;
return V_762 [ V_747 ] ;
}
static int F_315 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_764 ; V_41 ++ )
F_9 ( V_16 , L_457 , F_62 ( V_41 ) ,
F_313 ( V_36 -> V_737 [ V_41 ] . V_747 ) ) ;
return 0 ;
}
static int F_316 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
return F_317 ( V_111 , F_315 , V_20 ) ;
}
static int F_318 ( enum V_761 * V_747 ,
T_10 * V_210 )
{
if ( * V_747 == V_765 )
* V_747 = V_766 ;
switch ( * V_747 ) {
case V_766 :
* V_210 = V_767 | V_768 ;
break;
case V_748 :
* V_210 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_319 ( struct V_19 * V_20 , enum V_129 V_129 ,
enum V_761 * V_747 )
{
struct V_563 * V_564 ;
struct V_127 * V_128 ;
struct V_730 * V_769 ;
int V_76 = 0 ;
* V_747 = V_766 ;
F_237 ( V_20 ) ;
F_320 (dev, encoder) {
if ( ! V_564 -> V_37 . V_128 )
continue;
V_128 = F_321 ( V_564 -> V_37 . V_128 ) ;
if ( V_128 -> V_129 != V_129 )
continue;
switch ( V_564 -> type ) {
case V_770 :
* V_747 = V_771 ;
break;
case V_629 :
case V_571 :
V_769 = F_300 ( & V_564 -> V_37 ) ;
switch ( V_769 -> V_772 ) {
case V_773 :
* V_747 = V_774 ;
break;
case V_775 :
* V_747 = V_776 ;
break;
case V_777 :
* V_747 = V_778 ;
break;
default:
F_322 ( 1 , L_458 ,
F_323 ( V_769 -> V_772 ) ) ;
break;
}
break;
default:
break;
}
}
F_242 ( V_20 ) ;
return V_76 ;
}
static int F_324 ( struct V_19 * V_20 ,
enum V_129 V_129 ,
enum V_761 * V_747 ,
T_10 * V_210 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_779 = false ;
if ( * V_747 == V_765 ) {
int V_76 = F_319 ( V_20 , V_129 , V_747 ) ;
if ( V_76 )
return V_76 ;
}
switch ( * V_747 ) {
case V_766 :
* V_210 = V_767 | V_780 ;
break;
case V_774 :
* V_210 = V_767 | V_781 ;
V_779 = true ;
break;
case V_776 :
* V_210 = V_767 | V_782 ;
V_779 = true ;
break;
case V_778 :
if ( ! F_80 ( V_20 ) )
return - V_82 ;
* V_210 = V_767 | V_783 ;
V_779 = true ;
break;
case V_748 :
* V_210 = 0 ;
break;
default:
return - V_82 ;
}
if ( V_779 ) {
T_10 V_499 = F_69 ( V_784 ) ;
V_499 |= V_785 ;
switch ( V_129 ) {
case V_632 :
V_499 |= V_786 ;
break;
case V_787 :
V_499 |= V_788 ;
break;
case V_789 :
V_499 |= V_790 ;
break;
default:
return - V_82 ;
}
F_157 ( V_784 , V_499 ) ;
}
return 0 ;
}
static int F_325 ( struct V_19 * V_20 ,
enum V_129 V_129 ,
enum V_761 * V_747 ,
T_10 * V_210 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
bool V_779 = false ;
if ( * V_747 == V_765 ) {
int V_76 = F_319 ( V_20 , V_129 , V_747 ) ;
if ( V_76 )
return V_76 ;
}
switch ( * V_747 ) {
case V_766 :
* V_210 = V_767 | V_791 ;
break;
case V_771 :
if ( ! F_326 ( V_20 ) )
return - V_82 ;
* V_210 = V_767 | V_792 ;
break;
case V_774 :
if ( ! F_162 ( V_20 ) )
return - V_82 ;
* V_210 = V_767 | V_793 ;
V_779 = true ;
break;
case V_776 :
if ( ! F_162 ( V_20 ) )
return - V_82 ;
* V_210 = V_767 | V_794 ;
V_779 = true ;
break;
case V_778 :
if ( ! F_162 ( V_20 ) )
return - V_82 ;
* V_210 = V_767 | V_795 ;
V_779 = true ;
break;
case V_748 :
* V_210 = 0 ;
break;
default:
return - V_82 ;
}
if ( V_779 ) {
T_10 V_499 = F_69 ( V_784 ) ;
F_187 ( ! F_162 ( V_20 ) ) ;
F_157 ( V_796 ,
F_69 ( V_796 ) | V_797 ) ;
if ( V_129 == V_632 )
V_499 |= V_786 ;
else
V_499 |= V_788 ;
F_157 ( V_784 , V_499 ) ;
}
return 0 ;
}
static void F_327 ( struct V_19 * V_20 ,
enum V_129 V_129 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_10 V_499 = F_69 ( V_784 ) ;
switch ( V_129 ) {
case V_632 :
V_499 &= ~ V_786 ;
break;
case V_787 :
V_499 &= ~ V_788 ;
break;
case V_789 :
V_499 &= ~ V_790 ;
break;
default:
return;
}
if ( ! ( V_499 & V_798 ) )
V_499 &= ~ V_785 ;
F_157 ( V_784 , V_499 ) ;
}
static void F_328 ( struct V_19 * V_20 ,
enum V_129 V_129 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
T_10 V_499 = F_69 ( V_784 ) ;
if ( V_129 == V_632 )
V_499 &= ~ V_786 ;
else
V_499 &= ~ V_788 ;
F_157 ( V_784 , V_499 ) ;
if ( ! ( V_499 & V_798 ) ) {
F_157 ( V_796 ,
F_69 ( V_796 ) & ~ V_797 ) ;
}
}
static int F_329 ( enum V_761 * V_747 ,
T_10 * V_210 )
{
if ( * V_747 == V_765 )
* V_747 = V_766 ;
switch ( * V_747 ) {
case V_799 :
* V_210 = V_767 | V_800 ;
break;
case V_801 :
* V_210 = V_767 | V_802 ;
break;
case V_766 :
* V_210 = V_767 | V_803 ;
break;
case V_748 :
* V_210 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static void F_330 ( struct V_19 * V_20 , bool V_804 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_127 * V_128 =
F_321 ( V_36 -> V_805 [ V_632 ] ) ;
struct V_660 * V_661 ;
struct V_806 * V_433 ;
int V_76 = 0 ;
F_237 ( V_20 ) ;
V_433 = F_331 ( V_20 ) ;
if ( ! V_433 ) {
V_76 = - V_9 ;
goto V_207;
}
V_433 -> V_807 = F_332 ( & V_128 -> V_37 ) ;
V_661 = F_333 ( V_433 , V_128 ) ;
if ( F_334 ( V_661 ) ) {
V_76 = F_335 ( V_661 ) ;
goto V_207;
}
V_661 -> V_808 . V_809 = V_804 ;
if ( V_661 -> V_810 == V_811 &&
V_661 -> V_808 . V_488 != V_804 )
V_661 -> V_37 . V_812 = true ;
V_76 = F_336 ( V_433 ) ;
V_207:
F_242 ( V_20 ) ;
F_322 ( V_76 , L_459 , V_804 , V_76 ) ;
if ( V_76 )
F_337 ( V_433 ) ;
}
static int F_338 ( struct V_19 * V_20 ,
enum V_129 V_129 ,
enum V_761 * V_747 ,
T_10 * V_210 )
{
if ( * V_747 == V_765 )
* V_747 = V_813 ;
switch ( * V_747 ) {
case V_799 :
* V_210 = V_767 | V_814 ;
break;
case V_801 :
* V_210 = V_767 | V_815 ;
break;
case V_813 :
if ( F_123 ( V_20 ) && V_129 == V_632 )
F_330 ( V_20 , true ) ;
* V_210 = V_767 | V_816 ;
break;
case V_748 :
* V_210 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_339 ( struct V_19 * V_20 , enum V_129 V_129 ,
enum V_761 V_747 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
struct V_736 * V_737 = & V_36 -> V_737 [ V_129 ] ;
struct V_127 * V_128 = F_321 ( F_340 ( V_20 ,
V_129 ) ) ;
enum V_163 V_164 ;
T_4 V_210 = 0 ;
int V_76 ;
if ( V_737 -> V_747 == V_747 )
return 0 ;
if ( V_737 -> V_747 && V_747 )
return - V_82 ;
V_164 = F_86 ( V_129 ) ;
if ( ! F_87 ( V_36 , V_164 ) ) {
F_341 ( L_460 ) ;
return - V_817 ;
}
if ( F_342 ( V_20 ) )
V_76 = F_318 ( & V_747 , & V_210 ) ;
else if ( F_8 ( V_20 ) -> V_23 < 5 )
V_76 = F_325 ( V_20 , V_129 , & V_747 , & V_210 ) ;
else if ( F_92 ( V_20 ) || F_80 ( V_20 ) )
V_76 = F_324 ( V_20 , V_129 , & V_747 , & V_210 ) ;
else if ( F_116 ( V_20 ) || F_126 ( V_20 ) )
V_76 = F_329 ( & V_747 , & V_210 ) ;
else
V_76 = F_338 ( V_20 , V_129 , & V_747 , & V_210 ) ;
if ( V_76 != 0 )
goto V_207;
if ( V_747 ) {
struct V_753 * V_754 ;
F_98 ( L_461 ,
F_62 ( V_129 ) , F_313 ( V_747 ) ) ;
V_754 = F_343 ( V_741 ,
sizeof( V_737 -> V_754 [ 0 ] ) ,
V_8 ) ;
if ( ! V_754 ) {
V_76 = - V_9 ;
goto V_207;
}
F_344 ( V_128 ) ;
F_64 ( & V_737 -> V_329 ) ;
F_105 ( V_737 -> V_754 ) ;
V_737 -> V_754 = V_754 ;
V_737 -> V_68 = 0 ;
V_737 -> V_426 = 0 ;
F_72 ( & V_737 -> V_329 ) ;
}
V_737 -> V_747 = V_747 ;
F_157 ( F_345 ( V_129 ) , V_210 ) ;
F_346 ( F_345 ( V_129 ) ) ;
if ( V_747 == V_748 ) {
struct V_753 * V_754 ;
struct V_127 * V_128 =
F_321 ( V_36 -> V_805 [ V_129 ] ) ;
F_98 ( L_462 ,
F_62 ( V_129 ) ) ;
F_297 ( & V_128 -> V_37 . V_722 , NULL ) ;
if ( V_128 -> V_37 . V_433 -> V_42 )
F_347 ( V_20 , V_129 ) ;
F_298 ( & V_128 -> V_37 . V_722 ) ;
F_64 ( & V_737 -> V_329 ) ;
V_754 = V_737 -> V_754 ;
V_737 -> V_754 = NULL ;
V_737 -> V_68 = 0 ;
V_737 -> V_426 = 0 ;
F_72 ( & V_737 -> V_329 ) ;
F_105 ( V_754 ) ;
if ( F_162 ( V_20 ) )
F_328 ( V_20 , V_129 ) ;
else if ( F_92 ( V_20 ) || F_80 ( V_20 ) )
F_327 ( V_20 , V_129 ) ;
else if ( F_123 ( V_20 ) && V_129 == V_632 )
F_330 ( V_20 , false ) ;
F_348 ( V_128 ) ;
}
V_76 = 0 ;
V_207:
F_91 ( V_36 , V_164 ) ;
return V_76 ;
}
static int F_349 ( char * V_208 , char * V_818 [] , int V_819 )
{
int V_820 = 0 ;
while ( * V_208 ) {
char * V_712 ;
V_208 = F_350 ( V_208 ) ;
if ( ! * V_208 )
break;
for ( V_712 = V_208 ; * V_712 && ! isspace ( * V_712 ) ; V_712 ++ )
;
if ( V_820 == V_819 ) {
F_98 ( L_463 ,
V_819 ) ;
return - V_82 ;
}
if ( * V_712 )
* V_712 ++ = '\0' ;
V_818 [ V_820 ++ ] = V_208 ;
V_208 = V_712 ;
}
return V_820 ;
}
static int
F_351 ( const char * V_208 , enum V_821 * V_822 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_45 ( V_823 ) ; V_41 ++ )
if ( ! strcmp ( V_208 , V_823 [ V_41 ] ) ) {
* V_822 = V_41 ;
return 0 ;
}
return - V_82 ;
}
static int F_352 ( const char * V_208 , enum V_129 * V_129 )
{
const char V_52 = V_208 [ 0 ] ;
if ( V_52 < 'A' || V_52 >= F_62 ( V_764 ) )
return - V_82 ;
* V_129 = V_52 - 'A' ;
return 0 ;
}
static int
F_353 ( const char * V_208 , enum V_761 * V_59 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_45 ( V_762 ) ; V_41 ++ )
if ( ! strcmp ( V_208 , V_762 [ V_41 ] ) ) {
* V_59 = V_41 ;
return 0 ;
}
return - V_82 ;
}
static int F_354 ( struct V_19 * V_20 , char * V_208 , T_7 V_824 )
{
#define F_355 3
int V_820 ;
char * V_818 [ F_355 ] ;
enum V_129 V_129 ;
enum V_821 V_825 ;
enum V_761 V_747 ;
V_820 = F_349 ( V_208 , V_818 , F_355 ) ;
if ( V_820 != F_355 ) {
F_98 ( L_464 ,
F_355 ) ;
return - V_82 ;
}
if ( F_351 ( V_818 [ 0 ] , & V_825 ) < 0 ) {
F_98 ( L_465 , V_818 [ 0 ] ) ;
return - V_82 ;
}
if ( F_352 ( V_818 [ 1 ] , & V_129 ) < 0 ) {
F_98 ( L_466 , V_818 [ 1 ] ) ;
return - V_82 ;
}
if ( F_353 ( V_818 [ 2 ] , & V_747 ) < 0 ) {
F_98 ( L_467 , V_818 [ 2 ] ) ;
return - V_82 ;
}
return F_339 ( V_20 , V_129 , V_747 ) ;
}
static T_5 F_356 ( struct V_111 * V_111 , const char T_6 * V_193 ,
T_7 V_824 , T_8 * V_826 )
{
struct V_15 * V_16 = V_111 -> V_198 ;
struct V_19 * V_20 = V_16 -> V_18 ;
char * V_827 ;
int V_76 ;
if ( V_824 == 0 )
return 0 ;
if ( V_824 > V_548 - 1 ) {
F_98 ( L_468 ,
V_548 ) ;
return - V_828 ;
}
V_827 = F_2 ( V_824 + 1 , V_8 ) ;
if ( ! V_827 )
return - V_9 ;
if ( F_357 ( V_827 , V_193 , V_824 ) ) {
V_76 = - V_756 ;
goto V_207;
}
V_827 [ V_824 ] = '\0' ;
V_76 = F_354 ( V_20 , V_827 , V_824 ) ;
V_207:
F_105 ( V_827 ) ;
if ( V_76 < 0 )
return V_76 ;
* V_826 += V_824 ;
return V_824 ;
}
static T_5 F_358 ( struct V_111 * V_111 ,
const char T_6 * V_193 ,
T_7 V_824 , T_8 * V_826 )
{
char * V_829 ;
int V_441 = 0 ;
struct V_19 * V_20 ;
struct V_610 * V_566 ;
struct V_67 * V_830 ;
struct V_567 * V_567 ;
int V_210 = 0 ;
V_20 = ( (struct V_15 * ) V_111 -> V_198 ) -> V_18 ;
V_830 = & V_20 -> V_421 . V_830 ;
if ( V_824 == 0 )
return 0 ;
V_829 = F_2 ( V_824 + 1 , V_8 ) ;
if ( ! V_829 )
return - V_9 ;
if ( F_357 ( V_829 , V_193 , V_824 ) ) {
V_441 = - V_756 ;
goto V_207;
}
V_829 [ V_824 ] = '\0' ;
F_98 ( L_469 , ( unsigned int ) V_824 ) ;
F_19 (connector, connector_list, head) {
if ( V_566 -> V_831 !=
V_832 )
continue;
if ( V_566 -> V_441 == V_611 &&
V_566 -> V_564 != NULL ) {
V_567 = F_240 ( V_566 -> V_564 ) ;
V_441 = F_359 ( V_829 , 10 , & V_210 ) ;
if ( V_441 < 0 )
goto V_207;
F_98 ( L_470 , V_210 ) ;
if ( V_210 == 1 )
V_567 -> V_833 = 1 ;
else
V_567 -> V_833 = 0 ;
}
}
V_207:
F_105 ( V_829 ) ;
if ( V_441 < 0 )
return V_441 ;
* V_826 += V_824 ;
return V_824 ;
}
static int F_360 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_610 * V_566 ;
struct V_67 * V_830 = & V_20 -> V_421 . V_830 ;
struct V_567 * V_567 ;
F_19 (connector, connector_list, head) {
if ( V_566 -> V_831 !=
V_832 )
continue;
if ( V_566 -> V_441 == V_611 &&
V_566 -> V_564 != NULL ) {
V_567 = F_240 ( V_566 -> V_564 ) ;
if ( V_567 -> V_833 )
F_26 ( V_16 , L_471 ) ;
else
F_26 ( V_16 , L_472 ) ;
} else
F_26 ( V_16 , L_472 ) ;
}
return 0 ;
}
static int F_361 ( struct V_199 * V_199 ,
struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
return F_317 ( V_111 , F_360 , V_20 ) ;
}
static int F_362 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_610 * V_566 ;
struct V_67 * V_830 = & V_20 -> V_421 . V_830 ;
struct V_567 * V_567 ;
F_19 (connector, connector_list, head) {
if ( V_566 -> V_831 !=
V_832 )
continue;
if ( V_566 -> V_441 == V_611 &&
V_566 -> V_564 != NULL ) {
V_567 = F_240 ( V_566 -> V_564 ) ;
F_9 ( V_16 , L_473 , V_567 -> V_834 ) ;
} else
F_26 ( V_16 , L_472 ) ;
}
return 0 ;
}
static int F_363 ( struct V_199 * V_199 ,
struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
return F_317 ( V_111 , F_362 , V_20 ) ;
}
static int F_364 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_610 * V_566 ;
struct V_67 * V_830 = & V_20 -> V_421 . V_830 ;
struct V_567 * V_567 ;
F_19 (connector, connector_list, head) {
if ( V_566 -> V_831 !=
V_832 )
continue;
if ( V_566 -> V_441 == V_611 &&
V_566 -> V_564 != NULL ) {
V_567 = F_240 ( V_566 -> V_564 ) ;
F_9 ( V_16 , L_474 , V_567 -> V_835 ) ;
} else
F_26 ( V_16 , L_472 ) ;
}
return 0 ;
}
static int F_365 ( struct V_199 * V_199 ,
struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
return F_317 ( V_111 , F_364 , V_20 ) ;
}
static void F_366 ( struct V_15 * V_16 , const T_14 V_710 [ 8 ] )
{
struct V_19 * V_20 = V_16 -> V_18 ;
int V_836 ;
int V_837 ;
if ( F_80 ( V_20 ) )
V_837 = 3 ;
else if ( F_92 ( V_20 ) )
V_837 = 1 ;
else
V_837 = F_367 ( V_20 ) + 1 ;
F_237 ( V_20 ) ;
for ( V_836 = 0 ; V_836 < V_837 ; V_836 ++ ) {
unsigned int V_838 = V_710 [ V_836 ] ;
if ( F_8 ( V_20 ) -> V_23 >= 9 || F_92 ( V_20 ) ||
F_80 ( V_20 ) )
V_838 *= 10 ;
else if ( V_836 > 0 )
V_838 *= 5 ;
F_9 ( V_16 , L_475 ,
V_836 , V_710 [ V_836 ] , V_838 / 10 , V_838 % 10 ) ;
}
F_242 ( V_20 ) ;
}
static int F_368 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_14 * V_839 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_839 = V_36 -> V_710 . V_840 ;
else
V_839 = F_22 ( V_20 ) -> V_710 . V_841 ;
F_366 ( V_16 , V_839 ) ;
return 0 ;
}
static int F_369 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_14 * V_839 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_839 = V_36 -> V_710 . V_840 ;
else
V_839 = F_22 ( V_20 ) -> V_710 . V_842 ;
F_366 ( V_16 , V_839 ) ;
return 0 ;
}
static int F_370 ( struct V_15 * V_16 , void * V_17 )
{
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
const T_14 * V_839 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_839 = V_36 -> V_710 . V_840 ;
else
V_839 = F_22 ( V_20 ) -> V_710 . V_843 ;
F_366 ( V_16 , V_839 ) ;
return 0 ;
}
static int F_371 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
if ( F_8 ( V_20 ) -> V_23 < 5 )
return - V_373 ;
return F_317 ( V_111 , F_368 , V_20 ) ;
}
static int F_372 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
if ( F_373 ( V_20 ) )
return - V_373 ;
return F_317 ( V_111 , F_369 , V_20 ) ;
}
static int F_374 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
if ( F_373 ( V_20 ) )
return - V_373 ;
return F_317 ( V_111 , F_370 , V_20 ) ;
}
static T_5 F_375 ( struct V_111 * V_111 , const char T_6 * V_193 ,
T_7 V_824 , T_8 * V_826 , T_14 V_710 [ 8 ] )
{
struct V_15 * V_16 = V_111 -> V_198 ;
struct V_19 * V_20 = V_16 -> V_18 ;
T_14 V_844 [ 8 ] = { 0 } ;
int V_837 ;
int V_836 ;
int V_76 ;
char V_499 [ 32 ] ;
if ( F_80 ( V_20 ) )
V_837 = 3 ;
else if ( F_92 ( V_20 ) )
V_837 = 1 ;
else
V_837 = F_367 ( V_20 ) + 1 ;
if ( V_824 >= sizeof( V_499 ) )
return - V_82 ;
if ( F_357 ( V_499 , V_193 , V_824 ) )
return - V_756 ;
V_499 [ V_824 ] = '\0' ;
V_76 = sscanf ( V_499 , L_476 ,
& V_844 [ 0 ] , & V_844 [ 1 ] , & V_844 [ 2 ] , & V_844 [ 3 ] ,
& V_844 [ 4 ] , & V_844 [ 5 ] , & V_844 [ 6 ] , & V_844 [ 7 ] ) ;
if ( V_76 != V_837 )
return - V_82 ;
F_237 ( V_20 ) ;
for ( V_836 = 0 ; V_836 < V_837 ; V_836 ++ )
V_710 [ V_836 ] = V_844 [ V_836 ] ;
F_242 ( V_20 ) ;
return V_824 ;
}
static T_5 F_376 ( struct V_111 * V_111 , const char T_6 * V_193 ,
T_7 V_824 , T_8 * V_826 )
{
struct V_15 * V_16 = V_111 -> V_198 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_14 * V_839 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_839 = V_36 -> V_710 . V_840 ;
else
V_839 = F_22 ( V_20 ) -> V_710 . V_841 ;
return F_375 ( V_111 , V_193 , V_824 , V_826 , V_839 ) ;
}
static T_5 F_377 ( struct V_111 * V_111 , const char T_6 * V_193 ,
T_7 V_824 , T_8 * V_826 )
{
struct V_15 * V_16 = V_111 -> V_198 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_14 * V_839 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_839 = V_36 -> V_710 . V_840 ;
else
V_839 = F_22 ( V_20 ) -> V_710 . V_842 ;
return F_375 ( V_111 , V_193 , V_824 , V_826 , V_839 ) ;
}
static T_5 F_378 ( struct V_111 * V_111 , const char T_6 * V_193 ,
T_7 V_824 , T_8 * V_826 )
{
struct V_15 * V_16 = V_111 -> V_198 ;
struct V_19 * V_20 = V_16 -> V_18 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_14 * V_839 ;
if ( F_8 ( V_20 ) -> V_23 >= 9 )
V_839 = V_36 -> V_710 . V_840 ;
else
V_839 = F_22 ( V_20 ) -> V_710 . V_843 ;
return F_375 ( V_111 , V_193 , V_824 , V_826 , V_839 ) ;
}
static int
F_379 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_210 = F_65 ( & V_36 -> V_292 . V_845 ) ;
return 0 ;
}
static int
F_380 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_381 ( & V_36 -> V_292 ) )
return - V_751 ;
F_77 ( V_36 ) ;
F_382 ( V_20 , V_210 ,
L_477 , V_210 ) ;
F_78 ( V_36 ) ;
return 0 ;
}
static int
F_383 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_210 = V_36 -> V_292 . V_846 ;
return 0 ;
}
static int
F_384 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
F_98 ( L_478 , V_210 ) ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_36 -> V_292 . V_846 = V_210 ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int
F_385 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_210 = V_36 -> V_292 . V_847 ;
return 0 ;
}
static int
F_386 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_36 -> V_292 . V_847 = V_210 ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int
F_387 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
* V_210 = V_36 -> V_292 . V_848 ;
return 0 ;
}
static int
F_388 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
F_98 ( L_479 , V_210 ) ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_36 -> V_292 . V_848 = V_210 ;
F_6 ( & V_20 -> V_77 ) ;
return 0 ;
}
static int
F_389 ( void * V_17 , T_2 * V_210 )
{
* V_210 = V_849 ;
return 0 ;
}
static int
F_390 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
F_391 ( L_480 , V_210 ) ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
if ( V_210 & V_850 ) {
V_76 = F_392 ( V_20 ) ;
if ( V_76 )
goto V_851;
}
if ( V_210 & ( V_852 | V_850 ) )
F_393 ( V_20 ) ;
if ( V_210 & V_853 )
F_394 ( V_36 , V_854 , V_855 ) ;
if ( V_210 & V_856 )
F_394 ( V_36 , V_854 , V_857 ) ;
V_851:
F_6 ( & V_20 -> V_77 ) ;
return V_76 ;
}
static int
F_395 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_373 ;
F_115 ( & V_36 -> V_212 . V_213 ) ;
V_76 = F_31 ( & V_36 -> V_212 . V_223 ) ;
if ( V_76 )
return V_76 ;
* V_210 = F_119 ( V_36 , V_36 -> V_212 . V_400 ) ;
F_6 ( & V_36 -> V_212 . V_223 ) ;
return 0 ;
}
static int
F_396 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_858 , V_859 ;
int V_76 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_373 ;
F_115 ( & V_36 -> V_212 . V_213 ) ;
F_98 ( L_481 , V_210 ) ;
V_76 = F_31 ( & V_36 -> V_212 . V_223 ) ;
if ( V_76 )
return V_76 ;
V_210 = F_397 ( V_36 , V_210 ) ;
V_858 = V_36 -> V_212 . V_227 ;
V_859 = V_36 -> V_212 . V_228 ;
if ( V_210 < V_859 || V_210 > V_858 || V_210 < V_36 -> V_212 . V_399 ) {
F_6 ( & V_36 -> V_212 . V_223 ) ;
return - V_82 ;
}
V_36 -> V_212 . V_400 = V_210 ;
F_398 ( V_20 , V_210 ) ;
F_6 ( & V_36 -> V_212 . V_223 ) ;
return 0 ;
}
static int
F_399 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
int V_76 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_373 ;
F_115 ( & V_36 -> V_212 . V_213 ) ;
V_76 = F_31 ( & V_36 -> V_212 . V_223 ) ;
if ( V_76 )
return V_76 ;
* V_210 = F_119 ( V_36 , V_36 -> V_212 . V_399 ) ;
F_6 ( & V_36 -> V_212 . V_223 ) ;
return 0 ;
}
static int
F_400 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_858 , V_859 ;
int V_76 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return - V_373 ;
F_115 ( & V_36 -> V_212 . V_213 ) ;
F_98 ( L_482 , V_210 ) ;
V_76 = F_31 ( & V_36 -> V_212 . V_223 ) ;
if ( V_76 )
return V_76 ;
V_210 = F_397 ( V_36 , V_210 ) ;
V_858 = V_36 -> V_212 . V_227 ;
V_859 = V_36 -> V_212 . V_228 ;
if ( V_210 < V_859 || V_210 > V_858 || V_210 > V_36 -> V_212 . V_400 ) {
F_6 ( & V_36 -> V_212 . V_223 ) ;
return - V_82 ;
}
V_36 -> V_212 . V_399 = V_210 ;
F_398 ( V_20 , V_210 ) ;
F_6 ( & V_36 -> V_212 . V_223 ) ;
return 0 ;
}
static int
F_401 ( void * V_17 , T_2 * V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_860 ;
int V_76 ;
if ( ! ( F_126 ( V_20 ) || F_127 ( V_20 ) ) )
return - V_373 ;
V_76 = F_31 ( & V_20 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_77 ( V_36 ) ;
V_860 = F_69 ( V_861 ) ;
F_78 ( V_36 ) ;
F_6 ( & V_36 -> V_20 -> V_77 ) ;
* V_210 = ( V_860 & V_862 ) >> V_863 ;
return 0 ;
}
static int
F_402 ( void * V_17 , T_2 V_210 )
{
struct V_19 * V_20 = V_17 ;
struct V_35 * V_36 = V_20 -> V_69 ;
T_4 V_860 ;
if ( ! ( F_126 ( V_20 ) || F_127 ( V_20 ) ) )
return - V_373 ;
if ( V_210 > 3 )
return - V_82 ;
F_77 ( V_36 ) ;
F_98 ( L_483 , V_210 ) ;
V_860 = F_69 ( V_861 ) ;
V_860 &= ~ V_862 ;
V_860 |= ( V_210 << V_863 ) ;
F_157 ( V_861 , V_860 ) ;
F_78 ( V_36 ) ;
return 0 ;
}
static void F_403 ( struct V_19 * V_20 ,
struct V_864 * V_550 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_865 = 2 ;
int V_866 ;
T_4 V_867 [ V_865 ] , V_868 [ V_865 ] ;
V_867 [ 0 ] = F_69 ( V_869 ) ;
V_867 [ 1 ] = F_69 ( V_870 ) ;
V_868 [ 0 ] = F_69 ( V_871 ) ;
V_868 [ 1 ] = F_69 ( V_872 ) ;
for ( V_866 = 0 ; V_866 < V_865 ; V_866 ++ ) {
unsigned int V_873 ;
if ( V_867 [ V_866 ] & V_874 )
continue;
V_550 -> V_875 = 1 ;
V_550 -> V_876 ++ ;
V_873 = ( ( V_867 [ V_866 ] & V_877 ) ? 0 : 2 ) +
( ( V_867 [ V_866 ] & V_878 ) ? 0 : 2 ) +
( ( V_867 [ V_866 ] & V_879 ) ? 0 : 2 ) +
( ( V_868 [ V_866 ] & V_880 ) ? 0 : 2 ) ;
V_550 -> V_881 += V_873 ;
V_550 -> V_882 = F_404 ( V_550 -> V_882 , V_873 ) ;
}
V_550 -> V_883 = V_550 -> V_876 ;
}
static void F_405 ( struct V_19 * V_20 ,
struct V_864 * V_550 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_884 = 3 , V_865 = 4 ;
int V_59 , V_866 ;
T_4 V_885 [ V_884 ] , V_886 [ 2 * V_884 ] , V_887 [ 2 ] ;
if ( F_120 ( V_20 ) ) {
V_884 = 1 ;
V_865 = 3 ;
}
for ( V_59 = 0 ; V_59 < V_884 ; V_59 ++ ) {
V_885 [ V_59 ] = F_69 ( F_406 ( V_59 ) ) ;
V_886 [ 2 * V_59 ] = F_69 ( F_407 ( V_59 ) ) ;
V_886 [ 2 * V_59 + 1 ] = F_69 ( F_408 ( V_59 ) ) ;
}
V_887 [ 0 ] = V_888 |
V_889 |
V_890 |
V_891 ;
V_887 [ 1 ] = V_892 |
V_893 |
V_894 |
V_895 ;
for ( V_59 = 0 ; V_59 < V_884 ; V_59 ++ ) {
unsigned int V_896 = 0 ;
if ( ( V_885 [ V_59 ] & V_897 ) == 0 )
continue;
V_550 -> V_875 ++ ;
if ( F_129 ( V_20 ) || F_130 ( V_20 ) )
V_896 = F_8 ( V_20 ) -> V_876 ;
for ( V_866 = 0 ; V_866 < V_865 ; V_866 ++ ) {
unsigned int V_873 ;
if ( F_120 ( V_20 ) &&
! ( V_885 [ V_59 ] & ( F_409 ( V_866 ) ) ) )
continue;
if ( F_120 ( V_20 ) )
V_896 ++ ;
V_873 = 2 * F_287 ( V_886 [ 2 * V_59 + V_866 / 2 ] &
V_887 [ V_866 % 2 ] ) ;
V_550 -> V_881 += V_873 ;
V_550 -> V_882 = F_404 ( V_550 -> V_882 ,
V_873 ) ;
}
V_550 -> V_883 += V_896 ;
V_550 -> V_876 = F_404 ( V_550 -> V_876 ,
V_896 ) ;
}
}
static void F_410 ( struct V_19 * V_20 ,
struct V_864 * V_550 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
int V_59 ;
T_4 V_898 = F_69 ( V_899 ) ;
V_550 -> V_875 = F_287 ( V_898 & V_900 ) ;
if ( V_550 -> V_875 ) {
V_550 -> V_876 = F_8 ( V_20 ) -> V_876 ;
V_550 -> V_883 = V_550 -> V_875 *
V_550 -> V_876 ;
V_550 -> V_882 = F_8 ( V_20 ) -> V_882 ;
V_550 -> V_881 = V_550 -> V_882 * V_550 -> V_883 ;
for ( V_59 = 0 ; V_59 < V_550 -> V_875 ; V_59 ++ ) {
T_11 V_901 = F_8 ( V_20 ) -> V_901 [ V_59 ] ;
V_550 -> V_881 -= F_411 ( V_901 ) ;
}
}
}
static int F_412 ( struct V_15 * V_16 , void * V_211 )
{
struct V_6 * V_7 = (struct V_6 * ) V_16 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_2 -> V_20 ;
struct V_864 V_550 ;
if ( F_8 ( V_20 ) -> V_23 < 8 )
return - V_373 ;
F_26 ( V_16 , L_484 ) ;
F_9 ( V_16 , L_485 ,
F_8 ( V_20 ) -> V_875 ) ;
F_9 ( V_16 , L_486 ,
F_8 ( V_20 ) -> V_883 ) ;
F_9 ( V_16 , L_487 ,
F_8 ( V_20 ) -> V_876 ) ;
F_9 ( V_16 , L_488 ,
F_8 ( V_20 ) -> V_881 ) ;
F_9 ( V_16 , L_489 ,
F_8 ( V_20 ) -> V_882 ) ;
F_9 ( V_16 , L_490 ,
F_137 ( F_8 ( V_20 ) -> V_902 ) ) ;
F_9 ( V_16 , L_491 ,
F_137 ( F_8 ( V_20 ) -> V_903 ) ) ;
F_9 ( V_16 , L_492 ,
F_137 ( F_8 ( V_20 ) -> V_904 ) ) ;
F_26 ( V_16 , L_493 ) ;
memset ( & V_550 , 0 , sizeof( V_550 ) ) ;
if ( F_80 ( V_20 ) ) {
F_403 ( V_20 , & V_550 ) ;
} else if ( F_124 ( V_20 ) ) {
F_410 ( V_20 , & V_550 ) ;
} else if ( F_8 ( V_20 ) -> V_23 >= 9 ) {
F_405 ( V_20 , & V_550 ) ;
}
F_9 ( V_16 , L_494 ,
V_550 . V_875 ) ;
F_9 ( V_16 , L_495 ,
V_550 . V_883 ) ;
F_9 ( V_16 , L_496 ,
V_550 . V_876 ) ;
F_9 ( V_16 , L_497 ,
V_550 . V_881 ) ;
F_9 ( V_16 , L_498 ,
V_550 . V_882 ) ;
return 0 ;
}
static int F_413 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return 0 ;
F_77 ( V_36 ) ;
F_121 ( V_36 , V_256 ) ;
return 0 ;
}
static int F_414 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
struct V_19 * V_20 = V_199 -> V_200 ;
struct V_35 * V_36 = V_20 -> V_69 ;
if ( F_8 ( V_20 ) -> V_23 < 6 )
return 0 ;
F_125 ( V_36 , V_256 ) ;
F_78 ( V_36 ) ;
return 0 ;
}
static int F_415 ( struct V_3 * V_757 , struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
V_4 = F_312 ( L_499 ,
V_905 ,
V_757 , V_20 ,
& V_906 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , & V_906 ) ;
}
static int F_416 ( struct V_3 * V_757 ,
struct V_1 * V_2 ,
const char * V_52 ,
const struct V_907 * V_908 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_3 * V_4 ;
V_4 = F_312 ( V_52 ,
V_759 | V_909 ,
V_757 , V_20 ,
V_908 ) ;
if ( ! V_4 )
return - V_9 ;
return F_1 ( V_2 , V_4 , V_908 ) ;
}
void F_417 ( struct V_19 * V_20 )
{
struct V_35 * V_36 = V_20 -> V_69 ;
enum V_129 V_129 ;
F_81 (dev_priv, pipe) {
struct V_736 * V_737 = & V_36 -> V_737 [ V_129 ] ;
V_737 -> V_739 = false ;
F_418 ( & V_737 -> V_329 ) ;
F_419 ( & V_737 -> V_752 ) ;
}
}
int F_420 ( struct V_1 * V_2 )
{
int V_76 , V_41 ;
V_76 = F_415 ( V_2 -> V_910 , V_2 ) ;
if ( V_76 )
return V_76 ;
for ( V_41 = 0 ; V_41 < F_45 ( V_758 ) ; V_41 ++ ) {
V_76 = F_311 ( V_2 -> V_910 , V_2 , V_41 ) ;
if ( V_76 )
return V_76 ;
}
for ( V_41 = 0 ; V_41 < F_45 ( V_911 ) ; V_41 ++ ) {
V_76 = F_416 ( V_2 -> V_910 , V_2 ,
V_911 [ V_41 ] . V_52 ,
V_911 [ V_41 ] . V_908 ) ;
if ( V_76 )
return V_76 ;
}
return F_421 ( V_912 ,
V_913 ,
V_2 -> V_910 , V_2 ) ;
}
void F_422 ( struct V_1 * V_2 )
{
int V_41 ;
F_423 ( V_912 ,
V_913 , V_2 ) ;
F_423 ( (struct V_914 * ) & V_906 ,
1 , V_2 ) ;
for ( V_41 = 0 ; V_41 < F_45 ( V_758 ) ; V_41 ++ ) {
struct V_914 * V_915 =
(struct V_914 * ) & V_758 [ V_41 ] ;
F_423 ( V_915 , 1 , V_2 ) ;
}
for ( V_41 = 0 ; V_41 < F_45 ( V_911 ) ; V_41 ++ ) {
struct V_914 * V_915 =
(struct V_914 * ) V_911 [ V_41 ] . V_908 ;
F_423 ( V_915 , 1 , V_2 ) ;
}
}
static int F_424 ( struct V_15 * V_16 , void * V_17 )
{
struct V_610 * V_566 = V_16 -> V_18 ;
struct V_567 * V_567 =
F_240 ( & F_425 ( V_566 ) -> V_37 ) ;
T_15 V_208 [ 16 ] ;
T_5 V_916 ;
int V_41 ;
if ( V_566 -> V_441 != V_611 )
return - V_373 ;
for ( V_41 = 0 ; V_41 < F_45 ( V_917 ) ; V_41 ++ ) {
const struct V_918 * V_88 = & V_917 [ V_41 ] ;
T_7 V_31 = V_88 -> V_712 ? V_88 -> V_712 - V_88 -> V_682 + 1 : ( V_88 -> V_31 ? : 1 ) ;
if ( V_88 -> V_919 &&
V_566 -> V_831 != V_920 )
continue;
if ( F_187 ( V_31 > sizeof( V_208 ) ) )
continue;
V_916 = F_426 ( & V_567 -> V_921 , V_88 -> V_682 , V_208 , V_31 ) ;
if ( V_916 <= 0 ) {
F_427 ( L_500 ,
V_31 , V_88 -> V_682 , V_916 ) ;
continue;
}
F_9 ( V_16 , L_501 , V_88 -> V_682 , ( int ) V_31 , V_208 ) ;
}
return 0 ;
}
static int F_428 ( struct V_199 * V_199 , struct V_111 * V_111 )
{
return F_317 ( V_111 , F_424 , V_199 -> V_200 ) ;
}
int F_429 ( struct V_610 * V_566 )
{
struct V_3 * V_757 = V_566 -> V_922 ;
if ( ! V_757 )
return - V_373 ;
if ( V_566 -> V_831 == V_832 ||
V_566 -> V_831 == V_920 )
F_312 ( L_502 , V_759 , V_757 , V_566 ,
& V_923 ) ;
return 0 ;
}
