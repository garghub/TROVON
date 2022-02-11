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
if ( V_26 -> V_27 )
return L_5 ;
else
return L_6 ;
}
static const char * F_16 ( struct V_25 * V_26 )
{
switch ( V_26 -> V_28 ) {
default:
case V_29 : return L_6 ;
case V_30 : return L_7 ;
case V_31 : return L_8 ;
}
}
static inline const char * F_17 ( struct V_25 * V_26 )
{
return F_18 ( V_26 ) ? L_9 : L_6 ;
}
static T_2 F_19 ( struct V_25 * V_26 )
{
T_2 V_32 = 0 ;
struct V_33 * V_34 ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( F_21 ( V_34 -> V_35 ) &&
F_22 ( & V_34 -> V_8 ) )
V_32 += V_34 -> V_8 . V_32 ;
}
return V_32 ;
}
static void
F_23 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
struct V_36 * V_37 = F_24 ( V_26 -> V_38 . V_21 ) ;
struct V_39 * V_40 ;
struct V_33 * V_34 ;
int V_41 = 0 ;
int V_42 ;
F_10 ( V_17 , L_10 ,
& V_26 -> V_38 ,
V_26 -> V_43 ? L_11 : L_6 ,
F_15 ( V_26 ) ,
F_16 ( V_26 ) ,
F_17 ( V_26 ) ,
V_26 -> V_38 . V_32 / 1024 ,
V_26 -> V_38 . V_44 ,
V_26 -> V_38 . V_45 ) ;
F_25 (ring, dev_priv, i)
F_10 ( V_17 , L_12 ,
F_26 ( V_26 -> V_46 [ V_42 ] ) ) ;
F_10 ( V_17 , L_13 ,
F_26 ( V_26 -> V_47 ) ,
F_26 ( V_26 -> V_48 ) ,
F_27 ( F_24 ( V_26 -> V_38 . V_21 ) , V_26 -> V_49 ) ,
V_26 -> V_50 ? L_14 : L_15 ,
V_26 -> V_51 == V_52 ? L_16 : L_15 ) ;
if ( V_26 -> V_38 . V_53 )
F_10 ( V_17 , L_17 , V_26 -> V_38 . V_53 ) ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( V_34 -> V_41 > 0 )
V_41 ++ ;
}
F_10 ( V_17 , L_18 , V_41 ) ;
if ( V_26 -> V_27 )
F_10 ( V_17 , L_19 ) ;
if ( V_26 -> V_54 != V_55 )
F_10 ( V_17 , L_20 , V_26 -> V_54 ) ;
F_20 (vma, &obj->vma_list, vma_link) {
F_10 ( V_17 , L_21 ,
F_21 ( V_34 -> V_35 ) ? L_9 : L_22 ,
V_34 -> V_8 . V_56 , V_34 -> V_8 . V_32 ) ;
if ( F_21 ( V_34 -> V_35 ) )
F_10 ( V_17 , L_23 , V_34 -> V_57 . type ) ;
else
F_28 ( V_17 , L_24 ) ;
}
if ( V_26 -> V_58 )
F_10 ( V_17 , L_25 , V_26 -> V_58 -> V_56 ) ;
if ( V_26 -> V_27 || V_26 -> V_59 ) {
char V_60 [ 3 ] , * V_61 = V_60 ;
if ( V_26 -> V_27 )
* V_61 ++ = 'p' ;
if ( V_26 -> V_59 )
* V_61 ++ = 'f' ;
* V_61 = '\0' ;
F_10 ( V_17 , L_26 , V_60 ) ;
}
if ( V_26 -> V_47 != NULL )
F_10 ( V_17 , L_27 ,
F_29 ( V_26 -> V_47 ) -> V_53 ) ;
if ( V_26 -> V_62 )
F_10 ( V_17 , L_28 , V_26 -> V_62 ) ;
}
static void F_30 ( struct V_16 * V_17 , struct V_63 * V_64 )
{
F_31 ( V_17 , V_64 -> V_65 . V_66 ? 'I' : 'i' ) ;
F_31 ( V_17 , V_64 -> V_67 ? 'R' : 'r' ) ;
F_31 ( V_17 , ' ' ) ;
}
static int F_32 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
T_3 V_14 = ( T_3 ) V_8 -> V_12 -> V_18 ;
struct V_68 * V_69 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_71 * V_35 = & V_37 -> V_72 . V_38 ;
struct V_33 * V_34 ;
T_2 V_73 , V_74 ;
int V_75 , V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
switch ( V_14 ) {
case V_78 :
F_28 ( V_17 , L_29 ) ;
V_69 = & V_35 -> V_79 ;
break;
case V_80 :
F_28 ( V_17 , L_30 ) ;
V_69 = & V_35 -> V_81 ;
break;
default:
F_7 ( & V_21 -> V_77 ) ;
return - V_82 ;
}
V_73 = V_74 = V_75 = 0 ;
F_20 (vma, head, mm_list) {
F_10 ( V_17 , L_31 ) ;
F_23 ( V_17 , V_34 -> V_26 ) ;
F_10 ( V_17 , L_32 ) ;
V_73 += V_34 -> V_26 -> V_38 . V_32 ;
V_74 += V_34 -> V_8 . V_32 ;
V_75 ++ ;
}
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_33 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_34 ( void * V_83 ,
struct V_68 * V_84 , struct V_68 * V_85 )
{
struct V_25 * V_86 =
F_35 ( V_84 , struct V_25 , V_87 ) ;
struct V_25 * V_88 =
F_35 ( V_85 , struct V_25 , V_87 ) ;
return V_86 -> V_58 -> V_56 - V_88 -> V_58 -> V_56 ;
}
static int F_36 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_25 * V_26 ;
T_2 V_73 , V_74 ;
F_37 ( V_58 ) ;
int V_75 , V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_73 = V_74 = V_75 = 0 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_58 == NULL )
continue;
F_6 ( & V_26 -> V_87 , & V_58 ) ;
V_73 += V_26 -> V_38 . V_32 ;
V_74 += F_19 ( V_26 ) ;
V_75 ++ ;
}
F_20 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_26 -> V_58 == NULL )
continue;
F_6 ( & V_26 -> V_87 , & V_58 ) ;
V_73 += V_26 -> V_38 . V_32 ;
V_75 ++ ;
}
F_38 ( NULL , & V_58 , F_34 ) ;
F_28 ( V_17 , L_34 ) ;
while ( ! F_39 ( & V_58 ) ) {
V_26 = F_40 ( & V_58 , F_41 ( * V_26 ) , V_87 ) ;
F_28 ( V_17 , L_31 ) ;
F_23 ( V_17 , V_26 ) ;
F_31 ( V_17 , '\n' ) ;
F_42 ( & V_26 -> V_87 ) ;
}
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_33 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_43 ( int V_89 , void * V_90 , void * V_18 )
{
struct V_25 * V_26 = V_90 ;
struct V_91 * V_92 = V_18 ;
struct V_33 * V_34 ;
V_92 -> V_75 ++ ;
V_92 -> V_93 += V_26 -> V_38 . V_32 ;
if ( V_26 -> V_38 . V_53 || V_26 -> V_38 . V_94 )
V_92 -> V_95 += V_26 -> V_38 . V_32 ;
if ( F_44 ( V_26 -> V_38 . V_21 ) ) {
F_20 (vma, &obj->vma_list, vma_link) {
struct V_96 * V_97 ;
if ( ! F_22 ( & V_34 -> V_8 ) )
continue;
if ( F_21 ( V_34 -> V_35 ) ) {
V_92 -> V_98 += V_26 -> V_38 . V_32 ;
continue;
}
V_97 = F_35 ( V_34 -> V_35 , struct V_96 , V_38 ) ;
if ( V_97 -> V_99 != V_92 -> V_99 )
continue;
if ( V_26 -> V_43 )
V_92 -> V_43 += V_26 -> V_38 . V_32 ;
else
V_92 -> V_100 += V_26 -> V_38 . V_32 ;
return 0 ;
}
} else {
if ( F_45 ( V_26 ) ) {
V_92 -> V_98 += V_26 -> V_38 . V_32 ;
if ( V_26 -> V_43 )
V_92 -> V_43 += V_26 -> V_38 . V_32 ;
else
V_92 -> V_100 += V_26 -> V_38 . V_32 ;
return 0 ;
}
}
if ( ! F_39 ( & V_26 -> V_101 ) )
V_92 -> V_102 += V_26 -> V_38 . V_32 ;
return 0 ;
}
static void F_46 ( struct V_16 * V_17 ,
struct V_36 * V_37 )
{
struct V_25 * V_26 ;
struct V_91 V_92 ;
struct V_39 * V_40 ;
int V_42 , V_103 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
F_25 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < F_47 ( V_40 -> V_104 . V_105 ) ; V_103 ++ ) {
F_20 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
F_43 ( 0 , V_26 , & V_92 ) ;
}
}
F_48 ( V_17 , L_35 , V_92 ) ;
}
static int F_49 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_75 , V_106 , V_107 ;
T_2 V_32 , V_108 , V_109 ;
struct V_25 * V_26 ;
struct V_71 * V_35 = & V_37 -> V_72 . V_38 ;
struct V_110 * V_111 ;
struct V_33 * V_34 ;
int V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_10 ( V_17 , L_36 ,
V_37 -> V_112 . V_113 ,
V_37 -> V_112 . V_114 ) ;
V_32 = V_75 = V_108 = V_106 = 0 ;
F_50 ( & V_37 -> V_112 . V_115 , V_101 ) ;
F_10 ( V_17 , L_37 ,
V_75 , V_106 , V_32 , V_108 ) ;
V_32 = V_75 = V_108 = V_106 = 0 ;
F_51 ( & V_35 -> V_79 , V_116 ) ;
F_10 ( V_17 , L_38 ,
V_75 , V_106 , V_32 , V_108 ) ;
V_32 = V_75 = V_108 = V_106 = 0 ;
F_51 ( & V_35 -> V_81 , V_116 ) ;
F_10 ( V_17 , L_39 ,
V_75 , V_106 , V_32 , V_108 ) ;
V_32 = V_75 = V_109 = V_107 = 0 ;
F_20 (obj, &dev_priv->mm.unbound_list, global_list) {
V_32 += V_26 -> V_38 . V_32 , ++ V_75 ;
if ( V_26 -> V_51 == V_52 )
V_109 += V_26 -> V_38 . V_32 , ++ V_107 ;
}
F_10 ( V_17 , L_40 , V_75 , V_32 ) ;
V_32 = V_75 = V_108 = V_106 = 0 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_59 ) {
V_32 += F_52 ( V_26 ) ;
++ V_75 ;
}
if ( V_26 -> V_27 ) {
V_108 += F_52 ( V_26 ) ;
++ V_106 ;
}
if ( V_26 -> V_51 == V_52 ) {
V_109 += V_26 -> V_38 . V_32 ;
++ V_107 ;
}
}
F_10 ( V_17 , L_41 ,
V_107 , V_109 ) ;
F_10 ( V_17 , L_42 ,
V_106 , V_108 ) ;
F_10 ( V_17 , L_43 ,
V_75 , V_32 ) ;
F_10 ( V_17 , L_44 ,
V_37 -> V_72 . V_38 . V_93 ,
( T_2 ) V_37 -> V_72 . V_117 - V_37 -> V_72 . V_38 . V_56 ) ;
F_31 ( V_17 , '\n' ) ;
F_46 ( V_17 , V_37 ) ;
F_53 (file, &dev->filelist, lhead) {
struct V_91 V_92 ;
struct V_118 * V_119 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_99 = V_111 -> V_120 ;
F_54 ( & V_111 -> V_121 ) ;
F_55 ( & V_111 -> V_122 , F_43 , & V_92 ) ;
F_56 ( & V_111 -> V_121 ) ;
F_57 () ;
V_119 = F_58 ( V_111 -> V_123 , V_124 ) ;
F_48 ( V_17 , V_119 ? V_119 -> V_125 : L_45 , V_92 ) ;
F_59 () ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_60 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_3 V_14 = ( T_3 ) V_8 -> V_12 -> V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_25 * V_26 ;
T_2 V_73 , V_74 ;
int V_75 , V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_73 = V_74 = V_75 = 0 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_14 == V_126 && ! F_61 ( V_26 ) )
continue;
F_28 ( V_17 , L_31 ) ;
F_23 ( V_17 , V_26 ) ;
F_31 ( V_17 , '\n' ) ;
V_73 += V_26 -> V_38 . V_32 ;
V_74 += F_19 ( V_26 ) ;
V_75 ++ ;
}
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_33 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_62 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_127 * V_128 ;
int V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_63 (dev, crtc) {
const char V_129 = F_64 ( V_128 -> V_129 ) ;
const char V_130 = F_65 ( V_128 -> V_130 ) ;
struct V_131 * V_132 ;
F_66 ( & V_21 -> V_133 ) ;
V_132 = V_128 -> V_134 ;
if ( V_132 == NULL ) {
F_10 ( V_17 , L_46 ,
V_129 , V_130 ) ;
} else {
T_4 V_135 ;
if ( F_67 ( & V_132 -> V_136 ) < V_137 ) {
F_10 ( V_17 , L_47 ,
V_129 , V_130 ) ;
} else {
F_10 ( V_17 , L_48 ,
V_129 , V_130 ) ;
}
if ( V_132 -> V_138 ) {
struct V_39 * V_40 =
F_29 ( V_132 -> V_138 ) ;
F_10 ( V_17 , L_49 ,
V_40 -> V_53 ,
F_26 ( V_132 -> V_138 ) ,
V_37 -> V_139 ,
V_40 -> V_140 ( V_40 , true ) ,
F_68 ( V_132 -> V_138 , true ) ) ;
} else
F_10 ( V_17 , L_50 ) ;
F_10 ( V_17 , L_51 ,
V_132 -> V_141 ,
V_132 -> V_142 ,
F_69 ( & V_128 -> V_38 ) ) ;
if ( V_132 -> V_143 )
F_28 ( V_17 , L_52 ) ;
else
F_28 ( V_17 , L_53 ) ;
F_10 ( V_17 , L_54 , F_67 ( & V_132 -> V_136 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 4 )
V_135 = F_70 ( F_71 ( F_72 ( V_128 -> V_130 ) ) ) ;
else
V_135 = F_71 ( F_73 ( V_128 -> V_130 ) ) ;
F_10 ( V_17 , L_55 , V_135 ) ;
if ( V_132 -> V_144 ) {
F_10 ( V_17 , L_56 , ( long ) V_132 -> V_145 ) ;
F_10 ( V_17 , L_57 , V_135 == V_132 -> V_145 ) ;
}
}
F_74 ( & V_21 -> V_133 ) ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_75 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_25 * V_26 ;
struct V_39 * V_40 ;
int V_93 = 0 ;
int V_76 , V_42 , V_103 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_25 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < F_47 ( V_40 -> V_104 . V_105 ) ; V_103 ++ ) {
int V_75 ;
V_75 = 0 ;
F_20 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
V_75 ++ ;
F_10 ( V_17 , L_58 ,
V_40 -> V_53 , V_103 , V_75 ) ;
F_20 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link) {
F_28 ( V_17 , L_31 ) ;
F_23 ( V_17 , V_26 ) ;
F_31 ( V_17 , '\n' ) ;
}
V_93 += V_75 ;
}
}
F_10 ( V_17 , L_59 , V_93 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_76 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
struct V_146 * V_147 ;
int V_76 , V_148 , V_42 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_148 = 0 ;
F_25 (ring, dev_priv, i) {
int V_75 ;
V_75 = 0 ;
F_20 (req, &ring->request_list, list)
V_75 ++ ;
if ( V_75 == 0 )
continue;
F_10 ( V_17 , L_60 , V_40 -> V_53 , V_75 ) ;
F_20 (req, &ring->request_list, list) {
struct V_118 * V_119 ;
F_57 () ;
V_119 = NULL ;
if ( V_147 -> V_123 )
V_119 = F_58 ( V_147 -> V_123 , V_124 ) ;
F_10 ( V_17 , L_61 ,
V_147 -> V_149 ,
( int ) ( V_150 - V_147 -> V_151 ) ,
V_119 ? V_119 -> V_125 : L_45 ,
V_119 ? V_119 -> V_123 : - 1 ) ;
F_59 () ;
}
V_148 ++ ;
}
F_7 ( & V_21 -> V_77 ) ;
if ( V_148 == 0 )
F_28 ( V_17 , L_62 ) ;
return 0 ;
}
static void F_77 ( struct V_16 * V_17 ,
struct V_39 * V_40 )
{
if ( V_40 -> V_140 ) {
F_10 ( V_17 , L_63 ,
V_40 -> V_53 , V_40 -> V_140 ( V_40 , false ) ) ;
}
}
static int F_78 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
int V_76 , V_42 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
F_25 (ring, dev_priv, i)
F_77 ( V_17 , V_40 ) ;
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_81 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
int V_76 , V_42 , V_129 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
if ( F_82 ( V_21 ) ) {
F_10 ( V_17 , L_64 ,
F_71 ( V_152 ) ) ;
F_10 ( V_17 , L_65 ,
F_71 ( V_153 ) ) ;
F_10 ( V_17 , L_66 ,
F_71 ( V_154 ) ) ;
F_10 ( V_17 , L_67 ,
F_71 ( V_155 ) ) ;
F_10 ( V_17 , L_68 ,
F_71 ( V_156 ) ) ;
F_83 (dev_priv, pipe)
F_10 ( V_17 , L_69 ,
F_64 ( V_129 ) ,
F_71 ( F_84 ( V_129 ) ) ) ;
F_10 ( V_17 , L_70 ,
F_71 ( V_157 ) ) ;
F_10 ( V_17 , L_71 ,
F_71 ( V_158 ) ) ;
F_10 ( V_17 , L_72 ,
F_71 ( V_159 ) ) ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
F_10 ( V_17 , L_73 ,
V_42 , F_71 ( F_85 ( V_42 ) ) ) ;
F_10 ( V_17 , L_74 ,
V_42 , F_71 ( F_86 ( V_42 ) ) ) ;
F_10 ( V_17 , L_75 ,
V_42 , F_71 ( F_87 ( V_42 ) ) ) ;
}
F_10 ( V_17 , L_76 ,
F_71 ( V_160 ) ) ;
F_10 ( V_17 , L_77 ,
F_71 ( V_161 ) ) ;
F_10 ( V_17 , L_78 ,
F_71 ( V_162 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_10 ( V_17 , L_64 ,
F_71 ( V_152 ) ) ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
F_10 ( V_17 , L_73 ,
V_42 , F_71 ( F_85 ( V_42 ) ) ) ;
F_10 ( V_17 , L_74 ,
V_42 , F_71 ( F_86 ( V_42 ) ) ) ;
F_10 ( V_17 , L_75 ,
V_42 , F_71 ( F_87 ( V_42 ) ) ) ;
}
F_83 (dev_priv, pipe) {
if ( ! F_88 ( V_37 ,
F_89 ( V_129 ) ) ) {
F_10 ( V_17 , L_79 ,
F_64 ( V_129 ) ) ;
continue;
}
F_10 ( V_17 , L_80 ,
F_64 ( V_129 ) ,
F_71 ( F_90 ( V_129 ) ) ) ;
F_10 ( V_17 , L_81 ,
F_64 ( V_129 ) ,
F_71 ( F_91 ( V_129 ) ) ) ;
F_10 ( V_17 , L_82 ,
F_64 ( V_129 ) ,
F_71 ( F_92 ( V_129 ) ) ) ;
}
F_10 ( V_17 , L_83 ,
F_71 ( V_163 ) ) ;
F_10 ( V_17 , L_84 ,
F_71 ( V_164 ) ) ;
F_10 ( V_17 , L_85 ,
F_71 ( V_165 ) ) ;
F_10 ( V_17 , L_86 ,
F_71 ( V_166 ) ) ;
F_10 ( V_17 , L_87 ,
F_71 ( V_167 ) ) ;
F_10 ( V_17 , L_88 ,
F_71 ( V_168 ) ) ;
F_10 ( V_17 , L_76 ,
F_71 ( V_160 ) ) ;
F_10 ( V_17 , L_77 ,
F_71 ( V_161 ) ) ;
F_10 ( V_17 , L_78 ,
F_71 ( V_162 ) ) ;
} else if ( F_93 ( V_21 ) ) {
F_10 ( V_17 , L_65 ,
F_71 ( V_153 ) ) ;
F_10 ( V_17 , L_66 ,
F_71 ( V_154 ) ) ;
F_10 ( V_17 , L_67 ,
F_71 ( V_155 ) ) ;
F_10 ( V_17 , L_68 ,
F_71 ( V_156 ) ) ;
F_83 (dev_priv, pipe)
F_10 ( V_17 , L_69 ,
F_64 ( V_129 ) ,
F_71 ( F_84 ( V_129 ) ) ) ;
F_10 ( V_17 , L_89 ,
F_71 ( V_169 ) ) ;
F_10 ( V_17 , L_90 ,
F_71 ( V_170 ) ) ;
F_10 ( V_17 , L_91 ,
F_71 ( V_171 ) ) ;
F_10 ( V_17 , L_92 ,
F_71 ( V_172 ) ) ;
F_10 ( V_17 , L_93 ,
F_71 ( V_173 ) ) ;
F_10 ( V_17 , L_94 ,
F_71 ( V_174 ) ) ;
F_10 ( V_17 , L_95 ,
F_71 ( V_175 ) ) ;
F_10 ( V_17 , L_70 ,
F_71 ( V_157 ) ) ;
F_10 ( V_17 , L_71 ,
F_71 ( V_158 ) ) ;
F_10 ( V_17 , L_72 ,
F_71 ( V_159 ) ) ;
} else if ( ! F_94 ( V_21 ) ) {
F_10 ( V_17 , L_96 ,
F_71 ( V_176 ) ) ;
F_10 ( V_17 , L_97 ,
F_71 ( V_177 ) ) ;
F_10 ( V_17 , L_98 ,
F_71 ( V_178 ) ) ;
F_83 (dev_priv, pipe)
F_10 ( V_17 , L_99 ,
F_64 ( V_129 ) ,
F_71 ( F_84 ( V_129 ) ) ) ;
} else {
F_10 ( V_17 , L_100 ,
F_71 ( V_179 ) ) ;
F_10 ( V_17 , L_101 ,
F_71 ( V_180 ) ) ;
F_10 ( V_17 , L_102 ,
F_71 ( V_181 ) ) ;
F_10 ( V_17 , L_103 ,
F_71 ( V_182 ) ) ;
F_10 ( V_17 , L_104 ,
F_71 ( V_183 ) ) ;
F_10 ( V_17 , L_105 ,
F_71 ( V_184 ) ) ;
F_10 ( V_17 , L_106 ,
F_71 ( V_170 ) ) ;
F_10 ( V_17 , L_107 ,
F_71 ( V_171 ) ) ;
F_10 ( V_17 , L_108 ,
F_71 ( V_172 ) ) ;
}
F_25 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_109 ,
V_40 -> V_53 , F_95 ( V_40 ) ) ;
}
F_77 ( V_17 , V_40 ) ;
}
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_96 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_42 , V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_10 ( V_17 , L_110 , V_37 -> V_185 ) ;
F_10 ( V_17 , L_111 , V_37 -> V_186 ) ;
for ( V_42 = 0 ; V_42 < V_37 -> V_186 ; V_42 ++ ) {
struct V_25 * V_26 = V_37 -> V_187 [ V_42 ] . V_26 ;
F_10 ( V_17 , L_112 ,
V_42 , V_37 -> V_187 [ V_42 ] . V_41 ) ;
if ( V_26 == NULL )
F_28 ( V_17 , L_113 ) ;
else
F_23 ( V_17 , V_26 ) ;
F_31 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_97 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
const T_4 * V_188 ;
int V_42 ;
V_40 = & V_37 -> V_40 [ ( T_3 ) V_8 -> V_12 -> V_18 ] ;
V_188 = V_40 -> V_189 . V_190 ;
if ( V_188 == NULL )
return 0 ;
for ( V_42 = 0 ; V_42 < 4096 / sizeof( T_4 ) / 4 ; V_42 += 4 ) {
F_10 ( V_17 , L_114 ,
V_42 * 4 ,
V_188 [ V_42 ] , V_188 [ V_42 + 1 ] , V_188 [ V_42 + 2 ] , V_188 [ V_42 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_98 ( struct V_111 * V_191 ,
const char T_6 * V_192 ,
T_7 V_193 ,
T_8 * V_194 )
{
struct V_195 * V_196 = V_191 -> V_197 ;
struct V_20 * V_21 = V_196 -> V_21 ;
int V_76 ;
F_99 ( L_115 ) ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_100 ( V_21 ) ;
F_7 ( & V_21 -> V_77 ) ;
return V_193 ;
}
static int F_101 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
struct V_195 * V_196 ;
V_196 = F_102 ( sizeof( * V_196 ) , V_9 ) ;
if ( ! V_196 )
return - V_10 ;
V_196 -> V_21 = V_21 ;
F_103 ( V_21 , V_196 ) ;
V_111 -> V_197 = V_196 ;
return 0 ;
}
static int F_104 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_195 * V_196 = V_111 -> V_197 ;
F_105 ( V_196 ) ;
F_106 ( V_196 ) ;
return 0 ;
}
static T_5 F_107 ( struct V_111 * V_111 , char T_6 * V_200 ,
T_7 V_75 , T_8 * V_201 )
{
struct V_195 * V_196 = V_111 -> V_197 ;
struct V_202 V_203 ;
T_8 V_204 = 0 ;
T_5 V_205 = 0 ;
int V_76 ;
V_76 = F_108 ( & V_203 , F_24 ( V_196 -> V_21 ) , V_75 , * V_201 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_109 ( & V_203 , V_196 ) ;
if ( V_76 )
goto V_206;
V_205 = F_110 ( V_200 , V_75 , & V_204 ,
V_203 . V_207 ,
V_203 . V_208 ) ;
if ( V_205 < 0 )
V_76 = V_205 ;
else
* V_201 = V_203 . V_56 + V_205 ;
V_206:
F_111 ( & V_203 ) ;
return V_76 ? : V_205 ;
}
static int
F_112 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
* V_209 = V_37 -> V_139 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_113 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
int V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_114 ( V_21 , V_209 ) ;
F_7 ( & V_21 -> V_77 ) ;
return V_76 ;
}
static int F_115 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 = 0 ;
F_79 ( V_37 ) ;
F_116 ( & V_37 -> V_211 . V_212 ) ;
if ( F_117 ( V_21 ) ) {
T_9 V_213 = F_118 ( V_214 ) ;
T_9 V_215 = F_118 ( V_216 ) ;
F_10 ( V_17 , L_116 , ( V_213 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_117 , V_213 & 0x3f ) ;
F_10 ( V_17 , L_118 , ( V_215 & V_217 ) >>
V_218 ) ;
F_10 ( V_17 , L_119 ,
( V_215 & V_219 ) >> V_220 ) ;
} else if ( F_119 ( V_21 ) || ( F_120 ( V_21 ) && ! F_93 ( V_21 ) ) ||
F_121 ( V_21 ) || F_122 ( V_21 ) ) {
T_4 V_221 ;
T_4 V_222 ;
T_4 V_223 ;
T_4 V_224 , V_225 , V_226 ;
T_4 V_227 , V_228 , V_229 ;
T_4 V_230 , V_231 , V_232 ;
T_4 V_233 , V_234 , V_235 ;
T_4 V_236 , V_237 , V_238 , V_239 , V_240 ;
int V_241 ;
V_221 = F_71 ( V_242 ) ;
if ( F_123 ( V_21 ) ) {
V_223 = F_71 ( V_243 ) ;
V_222 = F_71 ( V_244 ) ;
} else {
V_223 = F_71 ( V_245 ) ;
V_222 = F_71 ( V_246 ) ;
}
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
goto V_206;
F_124 ( V_37 , V_247 ) ;
V_229 = F_71 ( V_248 ) ;
if ( F_122 ( V_21 ) )
V_229 >>= 23 ;
else {
V_229 &= ~ V_249 ;
if ( F_125 ( V_21 ) || F_121 ( V_21 ) )
V_229 >>= 24 ;
else
V_229 >>= 25 ;
}
V_229 = F_126 ( V_37 , V_229 ) ;
V_224 = F_71 ( V_250 ) ;
V_225 = F_71 ( V_251 ) ;
V_226 = F_71 ( V_252 ) ;
V_227 = F_71 ( V_253 ) ;
V_230 = F_71 ( V_254 ) ;
V_231 = F_71 ( V_255 ) ;
V_232 = F_71 ( V_256 ) ;
V_233 = F_71 ( V_257 ) ;
V_234 = F_71 ( V_258 ) ;
V_235 = F_71 ( V_259 ) ;
if ( F_122 ( V_21 ) )
V_228 = ( V_227 & V_260 ) >> V_261 ;
else if ( F_125 ( V_21 ) || F_121 ( V_21 ) )
V_228 = ( V_227 & V_262 ) >> V_263 ;
else
V_228 = ( V_227 & V_264 ) >> V_265 ;
V_228 = F_126 ( V_37 , V_228 ) ;
F_127 ( V_37 , V_247 ) ;
F_7 ( & V_21 -> V_77 ) ;
if ( F_119 ( V_21 ) || F_120 ( V_21 ) ) {
V_236 = F_71 ( V_173 ) ;
V_237 = F_71 ( V_175 ) ;
V_238 = F_71 ( V_266 ) ;
V_239 = F_71 ( V_174 ) ;
V_240 = F_71 ( V_267 ) ;
} else {
V_236 = F_71 ( F_87 ( 2 ) ) ;
V_237 = F_71 ( F_85 ( 2 ) ) ;
V_238 = F_71 ( F_128 ( 2 ) ) ;
V_239 = F_71 ( F_86 ( 2 ) ) ;
V_240 = F_71 ( V_267 ) ;
}
F_10 ( V_17 , L_120 ,
V_236 , V_237 , V_238 , V_239 , V_240 ) ;
F_10 ( V_17 , L_121 , V_222 ) ;
F_10 ( V_17 , L_122 ,
( V_222 & ( F_122 ( V_21 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_10 ( V_17 , L_123 ,
V_222 & 0xff ) ;
F_10 ( V_17 , L_124 ,
V_221 & 0xff ) ;
F_10 ( V_17 , L_125 , V_227 ) ;
F_10 ( V_17 , L_126 , V_224 ) ;
F_10 ( V_17 , L_127 , V_225 ) ;
F_10 ( V_17 , L_128 , V_226 ) ;
F_10 ( V_17 , L_129 , V_229 ) ;
F_10 ( V_17 , L_130 , V_228 ) ;
F_10 ( V_17 , L_131 , V_230 &
V_268 ) ;
F_10 ( V_17 , L_132 , V_231 &
V_269 ) ;
F_10 ( V_17 , L_133 , V_232 &
V_269 ) ;
F_10 ( V_17 , L_134 ,
V_37 -> V_211 . V_270 ) ;
F_10 ( V_17 , L_135 , V_233 &
V_271 ) ;
F_10 ( V_17 , L_136 , V_234 &
V_269 ) ;
F_10 ( V_17 , L_137 , V_235 &
V_269 ) ;
F_10 ( V_17 , L_138 ,
V_37 -> V_211 . V_272 ) ;
V_241 = ( F_123 ( V_21 ) ? V_223 >> 0 :
V_223 >> 16 ) & 0xff ;
V_241 *= ( F_129 ( V_21 ) ? V_273 : 1 ) ;
F_10 ( V_17 , L_139 ,
F_126 ( V_37 , V_241 ) ) ;
V_241 = ( V_223 & 0xff00 ) >> 8 ;
V_241 *= ( F_129 ( V_21 ) ? V_273 : 1 ) ;
F_10 ( V_17 , L_140 ,
F_126 ( V_37 , V_241 ) ) ;
V_241 = ( F_123 ( V_21 ) ? V_223 >> 16 :
V_223 >> 0 ) & 0xff ;
V_241 *= ( F_129 ( V_21 ) ? V_273 : 1 ) ;
F_10 ( V_17 , L_141 ,
F_126 ( V_37 , V_241 ) ) ;
F_10 ( V_17 , L_142 ,
F_126 ( V_37 , V_37 -> V_211 . V_241 ) ) ;
F_10 ( V_17 , L_143 ,
F_126 ( V_37 , V_37 -> V_211 . V_274 ) ) ;
F_10 ( V_17 , L_144 , V_228 ) ;
F_10 ( V_17 , L_145 ,
F_126 ( V_37 , V_37 -> V_211 . V_275 ) ) ;
F_10 ( V_17 , L_146 ,
F_126 ( V_37 , V_37 -> V_211 . V_276 ) ) ;
F_10 ( V_17 , L_147 ,
F_126 ( V_37 , V_37 -> V_211 . V_241 ) ) ;
F_10 ( V_17 ,
L_148 ,
F_126 ( V_37 , V_37 -> V_211 . V_277 ) ) ;
} else if ( F_93 ( V_21 ) ) {
T_4 V_278 ;
F_5 ( & V_37 -> V_211 . V_279 ) ;
V_278 = F_130 ( V_37 , V_280 ) ;
F_10 ( V_17 , L_149 , V_278 ) ;
F_10 ( V_17 , L_150 , V_37 -> V_281 ) ;
F_10 ( V_17 , L_151 ,
F_126 ( V_37 , ( V_278 >> 8 ) & 0xff ) ) ;
F_10 ( V_17 , L_152 ,
F_126 ( V_37 , V_37 -> V_211 . V_274 ) ) ;
F_10 ( V_17 , L_153 ,
F_126 ( V_37 , V_37 -> V_211 . V_241 ) ) ;
F_10 ( V_17 , L_154 ,
F_126 ( V_37 , V_37 -> V_211 . V_276 ) ) ;
F_10 ( V_17 , L_155 ,
F_126 ( V_37 , V_37 -> V_211 . V_275 ) ) ;
F_10 ( V_17 ,
L_148 ,
F_126 ( V_37 , V_37 -> V_211 . V_277 ) ) ;
F_7 ( & V_37 -> V_211 . V_279 ) ;
} else {
F_28 ( V_17 , L_156 ) ;
}
V_206:
F_80 ( V_37 ) ;
return V_76 ;
}
static int F_131 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
T_2 V_282 [ V_283 ] ;
T_4 V_149 [ V_283 ] ;
int V_42 ;
if ( ! V_284 . V_285 ) {
F_10 ( V_17 , L_157 ) ;
return 0 ;
}
F_79 ( V_37 ) ;
F_25 (ring, dev_priv, i) {
V_149 [ V_42 ] = V_40 -> V_140 ( V_40 , false ) ;
V_282 [ V_42 ] = F_132 ( V_40 ) ;
}
F_80 ( V_37 ) ;
if ( F_133 ( & V_37 -> V_286 . V_287 ) ) {
F_10 ( V_17 , L_158 ,
F_134 ( V_37 -> V_286 . V_287 . V_288 . V_289 -
V_150 ) ) ;
} else
F_10 ( V_17 , L_159 ) ;
F_25 (ring, dev_priv, i) {
F_10 ( V_17 , L_160 , V_40 -> V_53 ) ;
F_10 ( V_17 , L_161 ,
V_40 -> V_290 . V_149 , V_149 [ V_42 ] ) ;
F_10 ( V_17 , L_162 ,
( long long ) V_40 -> V_290 . V_282 ,
( long long ) V_282 [ V_42 ] ) ;
F_10 ( V_17 , L_163 ,
( long long ) V_40 -> V_290 . V_291 ) ;
F_10 ( V_17 , L_164 , V_40 -> V_290 . V_292 ) ;
F_10 ( V_17 , L_165 , V_40 -> V_290 . V_293 ) ;
}
return 0 ;
}
static int F_135 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_294 , V_295 ;
T_9 V_296 ;
int V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
V_294 = F_71 ( V_297 ) ;
V_295 = F_71 ( V_298 ) ;
V_296 = F_118 ( V_299 ) ;
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_166 , ( V_294 & V_300 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_167 ,
( V_294 & V_301 ) >>
V_302 ) ;
F_10 ( V_17 , L_168 ,
V_294 & V_303 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_169 ,
V_294 & V_304 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_170 ,
V_294 & V_305 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_171 ,
( V_294 & V_306 ) >> V_307 ) ;
F_10 ( V_17 , L_172 ,
( V_294 & V_308 ) >> V_309 ) ;
F_10 ( V_17 , L_173 , ( V_294 & V_310 ) ) ;
F_10 ( V_17 , L_174 , ( V_296 & 0x3f ) ) ;
F_10 ( V_17 , L_175 , ( ( V_296 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_176 ,
( V_295 & V_311 ) ? L_2 : L_1 ) ;
F_28 ( V_17 , L_177 ) ;
switch ( V_295 & V_312 ) {
case V_313 :
F_28 ( V_17 , L_178 ) ;
break;
case V_314 :
F_28 ( V_17 , L_179 ) ;
break;
case V_315 :
F_28 ( V_17 , L_180 ) ;
break;
case V_316 :
F_28 ( V_17 , L_181 ) ;
break;
case V_317 :
F_28 ( V_17 , L_182 ) ;
break;
case V_318 :
F_28 ( V_17 , L_183 ) ;
break;
default:
F_28 ( V_17 , L_184 ) ;
break;
}
return 0 ;
}
static int F_136 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_319 * V_320 ;
int V_42 ;
F_66 ( & V_37 -> V_321 . V_322 ) ;
F_137 (fw_domain, dev_priv, i) {
F_10 ( V_17 , L_185 ,
F_138 ( V_42 ) ,
V_320 -> V_323 ) ;
}
F_74 ( & V_37 -> V_321 . V_322 ) ;
return 0 ;
}
static int F_139 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_324 , V_325 , V_326 ;
F_79 ( V_37 ) ;
V_326 = F_71 ( V_327 ) ;
V_324 = F_71 ( V_250 ) ;
V_325 = F_71 ( V_328 ) ;
F_80 ( V_37 ) ;
F_10 ( V_17 , L_186 ,
F_1 ( V_324 & V_329 ) ) ;
F_10 ( V_17 , L_187 ,
F_1 ( V_324 & V_330 ) ) ;
F_10 ( V_17 , L_168 ,
F_1 ( V_324 & V_330 ) ) ;
F_10 ( V_17 , L_169 ,
F_1 ( ( V_324 & V_331 ) ==
V_332 ) ) ;
F_10 ( V_17 , L_188 ,
F_1 ( V_325 & ( V_333 |
F_140 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_189 ,
( V_326 & V_334 ) ? L_190 : L_191 ) ;
F_10 ( V_17 , L_192 ,
( V_326 & V_335 ) ? L_190 : L_191 ) ;
F_10 ( V_17 , L_193 ,
F_71 ( V_336 ) ) ;
F_10 ( V_17 , L_194 ,
F_71 ( V_337 ) ) ;
return F_136 ( V_17 , NULL ) ;
}
static int F_141 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_324 , V_338 , V_325 , V_339 = 0 ;
unsigned V_340 ;
int V_75 = 0 , V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
F_66 ( & V_37 -> V_321 . V_322 ) ;
V_340 = V_37 -> V_321 . V_320 [ V_341 ] . V_323 ;
F_74 ( & V_37 -> V_321 . V_322 ) ;
if ( V_340 ) {
F_28 ( V_17 , L_195
L_196 ) ;
} else {
while ( V_75 ++ < 50 && ( F_142 ( V_342 ) & 1 ) )
F_143 ( 10 ) ;
F_10 ( V_17 , L_197 , F_1 ( V_75 < 51 ) ) ;
}
V_338 = F_144 ( V_37 -> V_343 + V_344 ) ;
F_145 ( false , V_344 , V_338 , 4 , true ) ;
V_324 = F_71 ( V_250 ) ;
V_325 = F_71 ( V_328 ) ;
F_7 ( & V_21 -> V_77 ) ;
F_5 ( & V_37 -> V_211 . V_279 ) ;
F_146 ( V_37 , V_345 , & V_339 ) ;
F_7 ( & V_37 -> V_211 . V_279 ) ;
F_80 ( V_37 ) ;
F_10 ( V_17 , L_186 ,
F_1 ( V_324 & V_329 ) ) ;
F_10 ( V_17 , L_168 ,
F_1 ( V_324 & V_330 ) ) ;
F_10 ( V_17 , L_169 ,
F_1 ( ( V_324 & V_331 ) ==
V_332 ) ) ;
F_10 ( V_17 , L_198 ,
F_1 ( V_325 & V_346 ) ) ;
F_10 ( V_17 , L_188 ,
F_1 ( V_325 & V_347 ) ) ;
F_10 ( V_17 , L_199 ,
F_1 ( V_325 & V_348 ) ) ;
F_10 ( V_17 , L_200 ,
F_1 ( V_325 & V_349 ) ) ;
F_28 ( V_17 , L_201 ) ;
switch ( V_338 & V_350 ) {
case V_351 :
if ( V_338 & V_352 )
F_28 ( V_17 , L_202 ) ;
else
F_28 ( V_17 , L_178 ) ;
break;
case V_353 :
F_28 ( V_17 , L_203 ) ;
break;
case V_354 :
F_28 ( V_17 , L_204 ) ;
break;
case V_355 :
F_28 ( V_17 , L_205 ) ;
break;
default:
F_28 ( V_17 , L_206 ) ;
break;
}
F_10 ( V_17 , L_207 ,
F_1 ( V_338 & V_352 ) ) ;
F_10 ( V_17 , L_208 ,
F_71 ( V_356 ) ) ;
F_10 ( V_17 , L_209 ,
F_71 ( V_357 ) ) ;
F_10 ( V_17 , L_210 ,
F_71 ( V_358 ) ) ;
F_10 ( V_17 , L_211 ,
F_71 ( V_359 ) ) ;
F_10 ( V_17 , L_212 ,
F_147 ( ( ( V_339 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_213 ,
F_147 ( ( ( V_339 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_214 ,
F_147 ( ( ( V_339 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_148 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_93 ( V_21 ) )
return F_139 ( V_17 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
return F_141 ( V_17 ) ;
else
return F_135 ( V_17 ) ;
}
static int F_149 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
F_10 ( V_17 , L_215 ,
V_37 -> V_360 . V_361 ) ;
F_10 ( V_17 , L_216 ,
V_37 -> V_360 . V_362 ) ;
return 0 ;
}
static int F_150 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
if ( ! F_151 ( V_21 ) ) {
F_28 ( V_17 , L_217 ) ;
return 0 ;
}
F_79 ( V_37 ) ;
F_5 ( & V_37 -> V_363 . V_322 ) ;
if ( F_152 ( V_37 ) )
F_28 ( V_17 , L_218 ) ;
else
F_10 ( V_17 , L_219 ,
F_153 ( V_37 -> V_363 . V_364 ) ) ;
if ( F_9 ( V_37 ) -> V_24 >= 7 )
F_10 ( V_17 , L_220 ,
F_1 ( F_71 ( V_365 ) &
V_366 ) ) ;
F_7 ( & V_37 -> V_363 . V_322 ) ;
F_80 ( V_37 ) ;
return 0 ;
}
static int F_154 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_151 ( V_21 ) )
return - V_367 ;
* V_209 = V_37 -> V_363 . V_368 ;
return 0 ;
}
static int F_155 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_369 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_151 ( V_21 ) )
return - V_367 ;
F_5 ( & V_37 -> V_363 . V_322 ) ;
V_369 = F_71 ( V_370 ) ;
V_37 -> V_363 . V_368 = V_209 ;
F_156 ( V_370 , V_209 ?
( V_369 | V_371 ) :
( V_369 & ~ V_371 ) ) ;
F_7 ( & V_37 -> V_363 . V_322 ) ;
return 0 ;
}
static int F_157 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
if ( ! F_158 ( V_21 ) ) {
F_28 ( V_17 , L_221 ) ;
return 0 ;
}
F_79 ( V_37 ) ;
F_10 ( V_17 , L_222 ,
F_1 ( V_284 . V_372 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_28 ( V_17 , L_223 ) ;
} else {
if ( F_71 ( V_373 ) & V_374 )
F_28 ( V_17 , L_224 ) ;
else
F_28 ( V_17 , L_225 ) ;
}
F_80 ( V_37 ) ;
return 0 ;
}
static int F_159 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
bool V_375 = false ;
F_79 ( V_37 ) ;
if ( F_94 ( V_21 ) )
V_375 = F_71 ( V_376 ) & V_377 ;
else if ( F_160 ( V_21 ) || F_161 ( V_21 ) ||
F_162 ( V_21 ) || F_163 ( V_21 ) )
V_375 = F_71 ( V_378 ) & V_379 ;
else if ( F_164 ( V_21 ) )
V_375 = F_71 ( V_380 ) & V_381 ;
else if ( F_165 ( V_21 ) )
V_375 = F_71 ( V_382 ) & V_383 ;
else if ( F_93 ( V_21 ) )
V_375 = F_71 ( V_384 ) & V_385 ;
F_80 ( V_37 ) ;
F_10 ( V_17 , L_226 ,
V_375 ? L_227 : L_228 ) ;
return 0 ;
}
static int F_166 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
unsigned long V_386 , V_387 , V_388 ;
int V_76 ;
if ( ! F_117 ( V_21 ) )
return - V_367 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_386 = F_167 ( V_37 ) ;
V_387 = F_168 ( V_37 ) ;
V_388 = F_169 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_229 , V_386 ) ;
F_10 ( V_17 , L_230 , V_387 ) ;
F_10 ( V_17 , L_231 , V_388 ) ;
F_10 ( V_17 , L_232 , V_387 + V_388 ) ;
return 0 ;
}
static int F_170 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 = 0 ;
int V_389 , V_390 ;
unsigned int V_391 , V_392 ;
if ( ! F_171 ( V_21 ) ) {
F_28 ( V_17 , L_233 ) ;
return 0 ;
}
F_79 ( V_37 ) ;
F_116 ( & V_37 -> V_211 . V_212 ) ;
V_76 = F_33 ( & V_37 -> V_211 . V_279 ) ;
if ( V_76 )
goto V_206;
if ( F_129 ( V_21 ) ) {
V_392 =
V_37 -> V_211 . V_393 / V_273 ;
V_391 =
V_37 -> V_211 . V_394 / V_273 ;
} else {
V_392 = V_37 -> V_211 . V_393 ;
V_391 = V_37 -> V_211 . V_394 ;
}
F_28 ( V_17 , L_234 ) ;
for ( V_389 = V_392 ; V_389 <= V_391 ; V_389 ++ ) {
V_390 = V_389 ;
F_146 ( V_37 ,
V_395 ,
& V_390 ) ;
F_10 ( V_17 , L_235 ,
F_126 ( V_37 , ( V_389 *
( F_129 ( V_21 ) ? V_273 : 1 ) ) ) ,
( ( V_390 >> 0 ) & 0xff ) * 100 ,
( ( V_390 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_37 -> V_211 . V_279 ) ;
V_206:
F_80 ( V_37 ) ;
return V_76 ;
}
static int F_172 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_396 * V_397 = & V_37 -> V_397 ;
void * V_18 = F_3 ( V_398 , V_9 ) ;
int V_76 ;
if ( V_18 == NULL )
return - V_10 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
goto V_206;
if ( V_397 -> V_399 ) {
F_173 ( V_18 , V_397 -> V_399 , V_398 ) ;
F_174 ( V_17 , V_18 , V_398 ) ;
}
F_7 ( & V_21 -> V_77 ) ;
V_206:
F_106 ( V_18 ) ;
return 0 ;
}
static int F_175 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_400 * V_401 = NULL ;
struct V_402 * V_403 ;
struct V_404 * V_405 ;
#ifdef F_176
struct V_36 * V_37 = V_21 -> V_70 ;
V_401 = V_37 -> V_406 ;
V_403 = F_177 ( V_401 -> V_407 . V_403 ) ;
F_10 ( V_17 , L_236 ,
V_403 -> V_38 . V_408 ,
V_403 -> V_38 . V_409 ,
V_403 -> V_38 . V_410 ,
V_403 -> V_38 . V_411 ,
V_403 -> V_38 . V_412 [ 0 ] ,
F_67 ( & V_403 -> V_38 . V_413 . V_413 ) ) ;
F_23 ( V_17 , V_403 -> V_26 ) ;
F_31 ( V_17 , '\n' ) ;
#endif
F_5 ( & V_21 -> V_414 . V_415 ) ;
F_178 (drm_fb, dev) {
V_403 = F_177 ( V_405 ) ;
if ( V_401 && & V_403 -> V_38 == V_401 -> V_407 . V_403 )
continue;
F_10 ( V_17 , L_237 ,
V_403 -> V_38 . V_408 ,
V_403 -> V_38 . V_409 ,
V_403 -> V_38 . V_410 ,
V_403 -> V_38 . V_411 ,
V_403 -> V_38 . V_412 [ 0 ] ,
F_67 ( & V_403 -> V_38 . V_413 . V_413 ) ) ;
F_23 ( V_17 , V_403 -> V_26 ) ;
F_31 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_414 . V_415 ) ;
return 0 ;
}
static void F_179 ( struct V_16 * V_17 ,
struct V_416 * V_417 )
{
F_10 ( V_17 , L_238 ,
V_417 -> V_418 , V_417 -> V_69 , V_417 -> V_419 ,
V_417 -> V_420 ) ;
}
static int F_180 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
struct V_63 * V_64 ;
int V_76 , V_42 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_20 (ctx, &dev_priv->context_list, link) {
if ( ! V_284 . V_421 &&
V_64 -> V_65 . V_422 == NULL )
continue;
F_28 ( V_17 , L_239 ) ;
F_30 ( V_17 , V_64 ) ;
F_25 (ring, dev_priv, i) {
if ( V_40 -> V_423 == V_64 )
F_10 ( V_17 , L_240 ,
V_40 -> V_53 ) ;
}
if ( V_284 . V_421 ) {
F_31 ( V_17 , '\n' ) ;
F_25 (ring, dev_priv, i) {
struct V_25 * V_424 =
V_64 -> V_425 [ V_42 ] . V_426 ;
struct V_416 * V_417 =
V_64 -> V_425 [ V_42 ] . V_417 ;
F_10 ( V_17 , L_241 , V_40 -> V_53 ) ;
if ( V_424 )
F_23 ( V_17 , V_424 ) ;
if ( V_417 )
F_179 ( V_17 , V_417 ) ;
F_31 ( V_17 , '\n' ) ;
}
} else {
F_23 ( V_17 , V_64 -> V_65 . V_422 ) ;
}
F_31 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static void F_181 ( struct V_16 * V_17 ,
struct V_39 * V_40 ,
struct V_25 * V_424 )
{
struct V_427 * V_427 ;
T_10 * V_428 ;
int V_103 ;
unsigned long V_429 = 0 ;
if ( V_424 == NULL ) {
F_10 ( V_17 , L_242 ,
V_40 -> V_53 ) ;
return;
}
F_10 ( V_17 , L_243 , V_40 -> V_53 ,
F_182 ( V_424 ) ) ;
if ( ! F_45 ( V_424 ) )
F_28 ( V_17 , L_244 ) ;
else
V_429 = F_183 ( V_424 ) ;
if ( F_184 ( V_424 ) ) {
F_28 ( V_17 , L_245 ) ;
return;
}
V_427 = F_185 ( V_424 , 1 ) ;
if ( ! F_186 ( V_427 == NULL ) ) {
V_428 = F_187 ( V_427 ) ;
for ( V_103 = 0 ; V_103 < 0x600 / sizeof( T_4 ) / 4 ; V_103 += 4 ) {
F_10 ( V_17 , L_246 ,
V_429 + 4096 + ( V_103 * 4 ) ,
V_428 [ V_103 ] , V_428 [ V_103 + 1 ] ,
V_428 [ V_103 + 2 ] , V_428 [ V_103 + 3 ] ) ;
}
F_188 ( V_428 ) ;
}
F_31 ( V_17 , '\n' ) ;
}
static int F_189 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
struct V_63 * V_64 ;
int V_76 , V_42 ;
if ( ! V_284 . V_421 ) {
F_10 ( V_17 , L_247 ) ;
return 0 ;
}
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_20 (ctx, &dev_priv->context_list, link) {
F_25 (ring, dev_priv, i) {
if ( V_40 -> V_423 != V_64 )
F_181 ( V_17 , V_40 ,
V_64 -> V_425 [ V_42 ] . V_426 ) ;
}
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_190 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
T_4 V_430 ;
T_11 V_431 ;
T_11 V_432 ;
T_4 V_433 ;
T_4 V_434 ;
struct V_68 * V_435 ;
int V_436 , V_42 ;
int V_76 ;
if ( ! V_284 . V_421 ) {
F_28 ( V_17 , L_247 ) ;
return 0 ;
}
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
F_25 (ring, dev_priv, ring_id) {
struct V_146 * V_437 = NULL ;
int V_75 = 0 ;
unsigned long V_438 ;
F_10 ( V_17 , L_248 , V_40 -> V_53 ) ;
V_433 = F_71 ( F_191 ( V_40 ) ) ;
V_434 = F_71 ( F_191 ( V_40 ) + 4 ) ;
F_10 ( V_17 , L_249 ,
V_433 , V_434 ) ;
V_430 = F_71 ( F_192 ( V_40 ) ) ;
F_10 ( V_17 , L_250 , V_430 ) ;
V_431 = V_40 -> V_439 ;
V_432 = V_430 & 0x07 ;
if ( V_431 > V_432 )
V_432 += 6 ;
F_10 ( V_17 , L_251 ,
V_431 , V_432 ) ;
for ( V_42 = 0 ; V_42 < 6 ; V_42 ++ ) {
V_433 = F_71 ( F_193 ( V_40 ) + 8 * V_42 ) ;
V_434 = F_71 ( F_193 ( V_40 ) + 8 * V_42 + 4 ) ;
F_10 ( V_17 , L_252 ,
V_42 , V_433 , V_434 ) ;
}
F_194 ( & V_40 -> V_440 , V_438 ) ;
F_195 (cursor, &ring->execlist_queue)
V_75 ++ ;
V_437 = F_196 ( & V_40 -> V_441 ,
struct V_146 , V_442 ) ;
F_197 ( & V_40 -> V_440 , V_438 ) ;
F_10 ( V_17 , L_253 , V_75 ) ;
if ( V_437 ) {
struct V_25 * V_424 ;
V_424 = V_437 -> V_64 -> V_425 [ V_436 ] . V_426 ;
F_10 ( V_17 , L_254 ,
F_182 ( V_424 ) ) ;
F_10 ( V_17 , L_255 ,
V_437 -> V_419 ) ;
}
F_31 ( V_17 , '\n' ) ;
}
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static const char * F_198 ( unsigned V_443 )
{
switch ( V_443 ) {
case V_444 :
return L_256 ;
case V_445 :
return L_257 ;
case V_446 :
return L_258 ;
case V_447 :
return L_259 ;
case V_448 :
return L_260 ;
case V_449 :
return L_261 ;
case V_450 :
return L_262 ;
case V_451 :
return L_263 ;
}
return L_264 ;
}
static int F_199 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
F_10 ( V_17 , L_265 ,
F_198 ( V_37 -> V_112 . V_452 ) ) ;
F_10 ( V_17 , L_266 ,
F_198 ( V_37 -> V_112 . V_453 ) ) ;
if ( F_200 ( V_21 ) || F_201 ( V_21 ) ) {
F_10 ( V_17 , L_267 ,
F_71 ( V_454 ) ) ;
F_10 ( V_17 , L_268 ,
F_71 ( V_455 ) ) ;
F_10 ( V_17 , L_269 ,
F_118 ( V_456 ) ) ;
F_10 ( V_17 , L_270 ,
F_118 ( V_457 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_271 ,
F_71 ( V_458 ) ) ;
F_10 ( V_17 , L_272 ,
F_71 ( V_459 ) ) ;
F_10 ( V_17 , L_273 ,
F_71 ( V_460 ) ) ;
F_10 ( V_17 , L_274 ,
F_71 ( V_461 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_10 ( V_17 , L_275 ,
F_71 ( V_462 ) ) ;
else
F_10 ( V_17 , L_276 ,
F_71 ( V_463 ) ) ;
F_10 ( V_17 , L_277 ,
F_71 ( V_464 ) ) ;
}
if ( V_37 -> V_465 & V_466 )
F_28 ( V_17 , L_278 ) ;
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_202 ( int V_89 , void * V_90 , void * V_18 )
{
struct V_63 * V_64 = V_90 ;
struct V_16 * V_17 = V_18 ;
struct V_96 * V_97 = V_64 -> V_97 ;
if ( ! V_97 ) {
F_10 ( V_17 , L_279 ,
V_64 -> V_467 ) ;
return 0 ;
}
if ( F_203 ( V_64 ) )
F_28 ( V_17 , L_280 ) ;
else
F_10 ( V_17 , L_281 , V_64 -> V_467 ) ;
V_97 -> V_468 ( V_97 , V_17 ) ;
return 0 ;
}
static void F_204 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
struct V_96 * V_97 = V_37 -> V_112 . V_469 ;
int V_210 , V_42 ;
if ( ! V_97 )
return;
F_25 (ring, dev_priv, unused) {
F_10 ( V_17 , L_248 , V_40 -> V_53 ) ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
T_4 V_470 = 0x270 + V_42 * 8 ;
T_2 V_471 = F_71 ( V_40 -> V_472 + V_470 + 4 ) ;
V_471 <<= 32 ;
V_471 |= F_71 ( V_40 -> V_472 + V_470 ) ;
F_10 ( V_17 , L_282 , V_42 , V_471 ) ;
}
}
}
static void F_205 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
struct V_110 * V_111 ;
int V_42 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_283 , F_71 ( V_473 ) ) ;
F_25 (ring, dev_priv, i) {
F_10 ( V_17 , L_248 , V_40 -> V_53 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_283 , F_71 ( F_206 ( V_40 ) ) ) ;
F_10 ( V_17 , L_284 , F_71 ( F_207 ( V_40 ) ) ) ;
F_10 ( V_17 , L_285 , F_71 ( F_208 ( V_40 ) ) ) ;
F_10 ( V_17 , L_286 , F_71 ( F_209 ( V_40 ) ) ) ;
}
if ( V_37 -> V_112 . V_469 ) {
struct V_96 * V_97 = V_37 -> V_112 . V_469 ;
F_28 ( V_17 , L_287 ) ;
F_10 ( V_17 , L_288 , V_97 -> V_474 . V_38 . V_429 ) ;
V_97 -> V_468 ( V_97 , V_17 ) ;
}
F_53 (file, &dev->filelist, lhead) {
struct V_475 * V_99 = V_111 -> V_120 ;
F_10 ( V_17 , L_289 ,
F_210 ( V_111 -> V_123 , V_124 ) -> V_125 ) ;
F_55 ( & V_99 -> V_476 , F_202 , V_17 ) ;
}
F_10 ( V_17 , L_290 , F_71 ( V_477 ) ) ;
}
static int F_211 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_204 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_205 ( V_17 , V_21 ) ;
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_212 ( struct V_36 * V_284 )
{
struct V_39 * V_40 ;
int V_75 = 0 ;
int V_42 ;
F_25 (ring, i915, i)
V_75 += V_40 -> V_478 ;
return V_75 ;
}
static int F_213 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_110 * V_111 ;
F_10 ( V_17 , L_291 , V_37 -> V_211 . V_479 ) ;
F_10 ( V_17 , L_292 , V_37 -> V_112 . V_480 ) ;
F_10 ( V_17 , L_293 , F_212 ( V_37 ) ) ;
F_10 ( V_17 , L_294 ,
F_126 ( V_37 , V_37 -> V_211 . V_274 ) ,
F_126 ( V_37 , V_37 -> V_211 . V_276 ) ,
F_126 ( V_37 , V_37 -> V_211 . V_393 ) ,
F_126 ( V_37 , V_37 -> V_211 . V_394 ) ,
F_126 ( V_37 , V_37 -> V_211 . V_241 ) ) ;
F_54 ( & V_37 -> V_211 . V_481 ) ;
F_53 (file, &dev->filelist, lhead) {
struct V_475 * V_99 = V_111 -> V_120 ;
struct V_118 * V_119 ;
F_57 () ;
V_119 = F_58 ( V_111 -> V_123 , V_124 ) ;
F_10 ( V_17 , L_295 ,
V_119 ? V_119 -> V_125 : L_45 ,
V_119 ? V_119 -> V_123 : - 1 ,
V_99 -> V_211 . V_482 ,
F_39 ( & V_99 -> V_211 . V_483 ) ? L_15 : L_296 ) ;
F_59 () ;
}
F_10 ( V_17 , L_297 ,
V_37 -> V_211 . V_484 . V_482 ,
F_39 ( & V_37 -> V_211 . V_484 . V_483 ) ? L_15 : L_296 ) ;
F_10 ( V_17 , L_298 ,
V_37 -> V_211 . V_485 . V_482 ,
F_39 ( & V_37 -> V_211 . V_485 . V_483 ) ? L_15 : L_296 ) ;
F_10 ( V_17 , L_299 , V_37 -> V_211 . V_482 ) ;
F_56 ( & V_37 -> V_211 . V_481 ) ;
return 0 ;
}
static int F_214 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
F_10 ( V_17 , L_300 , F_1 ( F_215 ( V_21 ) ) ) ;
F_10 ( V_17 , L_301 , V_37 -> V_486 ) ;
return 0 ;
}
static int F_216 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_487 = 0 ;
T_4 V_488 [ 3 ] ;
enum V_129 V_129 ;
bool V_479 = false ;
if ( ! F_217 ( V_21 ) ) {
F_28 ( V_17 , L_302 ) ;
return 0 ;
}
F_79 ( V_37 ) ;
F_5 ( & V_37 -> V_489 . V_322 ) ;
F_10 ( V_17 , L_303 , F_1 ( V_37 -> V_489 . V_490 ) ) ;
F_10 ( V_17 , L_304 , F_1 ( V_37 -> V_489 . V_491 ) ) ;
F_10 ( V_17 , L_305 , F_1 ( ( bool ) V_37 -> V_489 . V_479 ) ) ;
F_10 ( V_17 , L_306 , F_1 ( V_37 -> V_489 . V_43 ) ) ;
F_10 ( V_17 , L_307 ,
V_37 -> V_489 . V_492 ) ;
F_10 ( V_17 , L_308 ,
F_1 ( F_218 ( & V_37 -> V_489 . V_132 . V_132 ) ) ) ;
if ( F_219 ( V_21 ) )
V_479 = F_71 ( F_220 ( V_21 ) ) & V_493 ;
else {
F_83 (dev_priv, pipe) {
V_488 [ V_129 ] = F_71 ( F_221 ( V_129 ) ) &
V_494 ;
if ( ( V_488 [ V_129 ] == V_495 ) ||
( V_488 [ V_129 ] == V_496 ) )
V_479 = true ;
}
}
F_10 ( V_17 , L_309 , F_1 ( V_479 ) ) ;
if ( ! F_219 ( V_21 ) )
F_83 (dev_priv, pipe) {
if ( ( V_488 [ V_129 ] == V_495 ) ||
( V_488 [ V_129 ] == V_496 ) )
F_10 ( V_17 , L_310 , F_64 ( V_129 ) ) ;
}
F_28 ( V_17 , L_32 ) ;
if ( F_219 ( V_21 ) ) {
V_487 = F_71 ( F_222 ( V_21 ) ) &
V_497 ;
F_10 ( V_17 , L_311 , V_487 ) ;
}
F_7 ( & V_37 -> V_489 . V_322 ) ;
F_80 ( V_37 ) ;
return 0 ;
}
static int F_223 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_498 * V_499 ;
struct V_500 * V_501 ;
struct V_502 * V_502 = NULL ;
int V_76 ;
T_11 V_503 [ 6 ] ;
F_224 ( V_21 ) ;
F_225 (dev, connector) {
if ( V_501 -> V_38 . V_504 != V_505 )
continue;
if ( ! V_501 -> V_38 . V_499 )
continue;
V_499 = F_226 ( V_501 -> V_38 . V_499 ) ;
if ( V_499 -> type != V_506 )
continue;
V_502 = F_227 ( & V_499 -> V_38 ) ;
V_76 = F_228 ( V_502 , V_503 ) ;
if ( V_76 )
goto V_206;
F_10 ( V_17 , L_312 ,
V_503 [ 0 ] , V_503 [ 1 ] , V_503 [ 2 ] ,
V_503 [ 3 ] , V_503 [ 4 ] , V_503 [ 5 ] ) ;
goto V_206;
}
V_76 = - V_367 ;
V_206:
F_229 ( V_21 ) ;
return V_76 ;
}
static int F_230 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_2 V_507 ;
T_4 V_508 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_367 ;
F_79 ( V_37 ) ;
F_231 ( V_509 , V_507 ) ;
V_507 = ( V_507 & 0x1f00 ) >> 8 ;
V_508 = 1000000 / ( 1 << V_507 ) ;
V_507 = F_71 ( V_510 ) ;
V_507 *= V_508 ;
F_80 ( V_37 ) ;
F_10 ( V_17 , L_313 , ( long long unsigned ) V_507 ) ;
return 0 ;
}
static int F_232 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
if ( ! F_233 ( V_21 ) ) {
F_28 ( V_17 , L_221 ) ;
return 0 ;
}
F_10 ( V_17 , L_314 , F_1 ( ! V_37 -> V_112 . V_480 ) ) ;
F_10 ( V_17 , L_315 ,
F_1 ( ! F_234 ( V_37 ) ) ) ;
#ifdef F_235
F_10 ( V_17 , L_316 ,
F_67 ( & V_21 -> V_21 -> V_507 . V_511 ) ) ;
#else
F_10 ( V_17 , L_317 ) ;
#endif
return 0 ;
}
static const char * F_236 ( enum V_512 V_513 )
{
switch ( V_513 ) {
case V_514 :
return L_318 ;
case V_515 :
return L_319 ;
case V_516 :
return L_320 ;
case V_517 :
return L_321 ;
case V_518 :
return L_322 ;
case V_519 :
return L_323 ;
case V_520 :
return L_324 ;
case V_521 :
return L_325 ;
case V_522 :
return L_326 ;
case V_523 :
return L_327 ;
case V_524 :
return L_328 ;
case V_525 :
return L_329 ;
case V_526 :
return L_330 ;
case V_527 :
return L_331 ;
case V_528 :
return L_332 ;
case V_529 :
return L_333 ;
case V_530 :
return L_334 ;
case V_531 :
return L_335 ;
case V_532 :
return L_336 ;
case V_533 :
return L_337 ;
case V_534 :
return L_338 ;
case V_535 :
return L_339 ;
case V_536 :
return L_340 ;
case V_537 :
return L_341 ;
case V_538 :
return L_342 ;
case V_539 :
return L_343 ;
case V_540 :
return L_344 ;
case V_541 :
return L_345 ;
case V_542 :
return L_346 ;
case V_543 :
return L_347 ;
default:
F_237 ( V_513 ) ;
return L_348 ;
}
}
static int F_238 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_544 * V_545 = & V_37 -> V_545 ;
int V_42 ;
F_5 ( & V_545 -> V_322 ) ;
F_10 ( V_17 , L_349 , L_350 , L_351 ) ;
for ( V_42 = 0 ; V_42 < V_545 -> V_546 ; V_42 ++ ) {
struct V_547 * V_548 ;
enum V_512 V_549 ;
V_548 = & V_545 -> V_550 [ V_42 ] ;
F_10 ( V_17 , L_352 , V_548 -> V_53 ,
V_548 -> V_75 ) ;
for ( V_549 = 0 ; V_549 < V_551 ;
V_549 ++ ) {
if ( ! ( F_239 ( V_549 ) & V_548 -> V_552 ) )
continue;
F_10 ( V_17 , L_353 ,
F_236 ( V_549 ) ,
V_545 -> V_553 [ V_549 ] ) ;
}
}
F_7 ( & V_545 -> V_322 ) ;
return 0 ;
}
static void F_240 ( struct V_16 * V_17 , int V_554 ,
struct V_555 * V_556 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < V_554 ; V_42 ++ )
F_31 ( V_17 , '\t' ) ;
F_10 ( V_17 , L_354 ,
V_556 -> V_38 . V_89 , V_556 -> V_53 ,
V_556 -> V_557 , V_556 -> clock ,
V_556 -> V_558 , V_556 -> V_559 ,
V_556 -> V_560 , V_556 -> V_561 ,
V_556 -> V_562 , V_556 -> V_563 ,
V_556 -> V_564 , V_556 -> V_565 ,
V_556 -> type , V_556 -> V_438 ) ;
}
static void F_241 ( struct V_16 * V_17 ,
struct V_127 * V_127 ,
struct V_498 * V_498 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_566 * V_128 = & V_127 -> V_38 ;
struct V_500 * V_500 ;
struct V_567 * V_499 ;
V_499 = & V_498 -> V_38 ;
F_10 ( V_17 , L_355 ,
V_499 -> V_38 . V_89 , V_499 -> V_53 ) ;
F_242 (dev, encoder, intel_connector) {
struct V_568 * V_501 = & V_500 -> V_38 ;
F_10 ( V_17 , L_356 ,
V_501 -> V_38 . V_89 ,
V_501 -> V_53 ,
F_243 ( V_501 -> V_433 ) ) ;
if ( V_501 -> V_433 == V_569 ) {
struct V_555 * V_556 = & V_128 -> V_556 ;
F_10 ( V_17 , L_357 ) ;
F_240 ( V_17 , 2 , V_556 ) ;
} else {
F_31 ( V_17 , '\n' ) ;
}
}
}
static void F_244 ( struct V_16 * V_17 , struct V_127 * V_127 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_566 * V_128 = & V_127 -> V_38 ;
struct V_498 * V_498 ;
if ( V_128 -> V_570 -> V_403 )
F_10 ( V_17 , L_358 ,
V_128 -> V_570 -> V_403 -> V_38 . V_89 , V_128 -> T_1 , V_128 -> V_571 ,
V_128 -> V_570 -> V_403 -> V_408 , V_128 -> V_570 -> V_403 -> V_409 ) ;
else
F_28 ( V_17 , L_359 ) ;
F_245 (dev, crtc, intel_encoder)
F_241 ( V_17 , V_127 , V_498 ) ;
}
static void F_246 ( struct V_16 * V_17 , struct V_572 * V_573 )
{
struct V_555 * V_556 = V_573 -> V_574 ;
F_10 ( V_17 , L_360 ) ;
F_240 ( V_17 , 2 , V_556 ) ;
}
static void F_247 ( struct V_16 * V_17 ,
struct V_500 * V_500 )
{
struct V_498 * V_498 = V_500 -> V_499 ;
struct V_502 * V_502 = F_227 ( & V_498 -> V_38 ) ;
F_10 ( V_17 , L_361 , V_502 -> V_575 [ V_576 ] ) ;
F_10 ( V_17 , L_362 , V_502 -> V_577 ? L_1 :
L_2 ) ;
if ( V_498 -> type == V_506 )
F_246 ( V_17 , & V_500 -> V_573 ) ;
}
static void F_248 ( struct V_16 * V_17 ,
struct V_500 * V_500 )
{
struct V_498 * V_498 = V_500 -> V_499 ;
struct V_578 * V_578 = F_249 ( & V_498 -> V_38 ) ;
F_10 ( V_17 , L_362 , V_578 -> V_577 ? L_1 :
L_2 ) ;
}
static void F_250 ( struct V_16 * V_17 ,
struct V_500 * V_500 )
{
F_246 ( V_17 , & V_500 -> V_573 ) ;
}
static void F_251 ( struct V_16 * V_17 ,
struct V_568 * V_501 )
{
struct V_500 * V_500 = F_252 ( V_501 ) ;
struct V_498 * V_498 = V_500 -> V_499 ;
struct V_555 * V_556 ;
F_10 ( V_17 , L_363 ,
V_501 -> V_38 . V_89 , V_501 -> V_53 ,
F_243 ( V_501 -> V_433 ) ) ;
if ( V_501 -> V_433 == V_569 ) {
F_10 ( V_17 , L_364 , V_501 -> V_579 . V_53 ) ;
F_10 ( V_17 , L_365 ,
V_501 -> V_579 . V_580 ,
V_501 -> V_579 . V_581 ) ;
F_10 ( V_17 , L_366 ,
F_253 ( V_501 -> V_579 . V_582 ) ) ;
F_10 ( V_17 , L_367 ,
V_501 -> V_579 . V_583 ) ;
}
if ( V_498 ) {
if ( V_498 -> type == V_584 ||
V_498 -> type == V_506 )
F_247 ( V_17 , V_500 ) ;
else if ( V_498 -> type == V_585 )
F_248 ( V_17 , V_500 ) ;
else if ( V_498 -> type == V_586 )
F_250 ( V_17 , V_500 ) ;
}
F_10 ( V_17 , L_368 ) ;
F_20 (mode, &connector->modes, head)
F_240 ( V_17 , 2 , V_556 ) ;
}
static bool F_254 ( struct V_20 * V_21 , int V_129 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_426 ;
if ( F_255 ( V_21 ) || F_256 ( V_21 ) )
V_426 = F_71 ( V_587 ) & V_588 ;
else
V_426 = F_71 ( F_257 ( V_129 ) ) & V_589 ;
return V_426 ;
}
static bool F_258 ( struct V_20 * V_21 , int V_129 , int * T_1 , int * V_571 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_201 ;
V_201 = F_71 ( F_259 ( V_129 ) ) ;
* T_1 = ( V_201 >> V_590 ) & V_591 ;
if ( V_201 & ( V_592 << V_590 ) )
* T_1 = - * T_1 ;
* V_571 = ( V_201 >> V_593 ) & V_591 ;
if ( V_201 & ( V_592 << V_593 ) )
* V_571 = - * V_571 ;
return F_254 ( V_21 , V_129 ) ;
}
static int F_260 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_127 * V_128 ;
struct V_568 * V_501 ;
F_79 ( V_37 ) ;
F_224 ( V_21 ) ;
F_10 ( V_17 , L_369 ) ;
F_10 ( V_17 , L_370 ) ;
F_63 (dev, crtc) {
bool V_43 ;
struct V_594 * V_595 ;
int T_1 , V_571 ;
V_595 = F_261 ( V_128 -> V_38 . V_426 ) ;
F_10 ( V_17 , L_371 ,
V_128 -> V_38 . V_38 . V_89 , F_64 ( V_128 -> V_129 ) ,
F_1 ( V_595 -> V_38 . V_43 ) ,
V_595 -> V_596 , V_595 -> V_597 ) ;
if ( V_595 -> V_38 . V_43 ) {
F_244 ( V_17 , V_128 ) ;
V_43 = F_258 ( V_21 , V_128 -> V_129 , & T_1 , & V_571 ) ;
F_10 ( V_17 , L_372 ,
F_1 ( V_128 -> V_598 ) ,
T_1 , V_571 , V_128 -> V_38 . V_435 -> V_426 -> V_599 ,
V_128 -> V_38 . V_435 -> V_426 -> V_600 ,
V_128 -> V_601 , F_1 ( V_43 ) ) ;
}
F_10 ( V_17 , L_373 ,
F_1 ( ! V_128 -> V_602 ) ,
F_1 ( ! V_128 -> V_603 ) ) ;
}
F_10 ( V_17 , L_32 ) ;
F_10 ( V_17 , L_374 ) ;
F_10 ( V_17 , L_375 ) ;
F_20 (connector, &dev->mode_config.connector_list, head) {
F_251 ( V_17 , V_501 ) ;
}
F_229 ( V_21 ) ;
F_80 ( V_37 ) ;
return 0 ;
}
static int F_262 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_39 * V_40 ;
int V_604 = F_263 ( F_9 ( V_21 ) -> V_605 ) ;
int V_42 , V_103 , V_76 ;
if ( ! F_264 ( V_21 ) ) {
F_28 ( V_17 , L_376 ) ;
return 0 ;
}
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
if ( F_121 ( V_21 ) ) {
struct V_427 * V_427 ;
T_12 * V_149 ;
V_427 = F_185 ( V_37 -> V_606 , 0 ) ;
V_149 = ( T_12 * ) F_187 ( V_427 ) ;
F_25 (ring, dev_priv, i) {
T_12 V_470 ;
F_10 ( V_17 , L_248 , V_40 -> V_53 ) ;
F_28 ( V_17 , L_377 ) ;
for ( V_103 = 0 ; V_103 < V_604 ; V_103 ++ ) {
V_470 = V_42 * V_283 + V_103 ;
F_10 ( V_17 , L_378 ,
V_149 [ V_470 ] , V_470 * 8 ) ;
}
F_31 ( V_17 , '\n' ) ;
F_28 ( V_17 , L_379 ) ;
for ( V_103 = 0 ; V_103 < V_604 ; V_103 ++ ) {
V_470 = V_42 + ( V_103 * V_283 ) ;
F_10 ( V_17 , L_378 ,
V_149 [ V_470 ] , V_470 * 8 ) ;
}
F_31 ( V_17 , '\n' ) ;
}
F_188 ( V_149 ) ;
} else {
F_28 ( V_17 , L_377 ) ;
F_25 (ring, dev_priv, i)
for ( V_103 = 0 ; V_103 < V_604 ; V_103 ++ )
F_10 ( V_17 , L_380 ,
F_71 ( V_40 -> V_607 . V_608 . signal [ V_103 ] ) ) ;
F_31 ( V_17 , '\n' ) ;
}
F_28 ( V_17 , L_381 ) ;
F_25 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < V_604 ; V_103 ++ ) {
F_10 ( V_17 , L_382 , V_40 -> V_607 . V_609 [ V_103 ] ) ;
}
F_31 ( V_17 , '\n' ) ;
}
F_31 ( V_17 , '\n' ) ;
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_265 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_42 ;
F_224 ( V_21 ) ;
for ( V_42 = 0 ; V_42 < V_37 -> V_610 ; V_42 ++ ) {
struct V_611 * V_612 = & V_37 -> V_613 [ V_42 ] ;
F_10 ( V_17 , L_383 , V_42 , V_612 -> V_53 , V_612 -> V_89 ) ;
F_10 ( V_17 , L_384 ,
V_612 -> V_614 . V_615 , V_612 -> V_43 , F_1 ( V_612 -> V_616 ) ) ;
F_10 ( V_17 , L_385 ) ;
F_10 ( V_17 , L_386 , V_612 -> V_614 . V_617 . V_618 ) ;
F_10 ( V_17 , L_387 ,
V_612 -> V_614 . V_617 . V_619 ) ;
F_10 ( V_17 , L_388 , V_612 -> V_614 . V_617 . V_620 ) ;
F_10 ( V_17 , L_389 , V_612 -> V_614 . V_617 . V_621 ) ;
F_10 ( V_17 , L_390 , V_612 -> V_614 . V_617 . V_622 ) ;
}
F_229 ( V_21 ) ;
return 0 ;
}
static int F_266 ( struct V_16 * V_17 , void * V_210 )
{
int V_42 ;
int V_76 ;
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
F_10 ( V_17 , L_391 , V_37 -> V_623 . V_75 ) ;
for ( V_42 = 0 ; V_42 < V_37 -> V_623 . V_75 ; ++ V_42 ) {
T_4 V_135 , V_624 , V_625 , V_626 ;
bool V_627 ;
V_135 = V_37 -> V_623 . V_369 [ V_42 ] . V_135 ;
V_624 = V_37 -> V_623 . V_369 [ V_42 ] . V_624 ;
V_625 = V_37 -> V_623 . V_369 [ V_42 ] . V_625 ;
V_626 = F_71 ( V_135 ) ;
V_627 = ( V_625 & V_624 ) == ( V_626 & V_624 ) ;
F_10 ( V_17 , L_392 ,
V_135 , V_625 , V_624 , V_626 , V_627 ? L_393 : L_394 ) ;
}
F_80 ( V_37 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_267 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_628 * V_629 ;
struct V_630 * V_631 ;
enum V_129 V_129 ;
int V_130 ;
if ( F_9 ( V_21 ) -> V_24 < 9 )
return 0 ;
F_224 ( V_21 ) ;
V_629 = & V_37 -> V_632 . V_633 . V_629 ;
F_10 ( V_17 , L_395 , L_15 , L_396 , L_397 , L_398 ) ;
F_83 (dev_priv, pipe) {
F_10 ( V_17 , L_399 , F_64 ( V_129 ) ) ;
F_268 (dev_priv, pipe, plane) {
V_631 = & V_629 -> V_130 [ V_129 ] [ V_130 ] ;
F_10 ( V_17 , L_400 , V_130 + 1 ,
V_631 -> V_56 , V_631 -> V_634 ,
F_269 ( V_631 ) ) ;
}
V_631 = & V_629 -> V_435 [ V_129 ] ;
F_10 ( V_17 , L_401 , L_402 , V_631 -> V_56 ,
V_631 -> V_634 , F_269 ( V_631 ) ) ;
}
F_229 ( V_21 ) ;
return 0 ;
}
static void F_270 ( struct V_16 * V_17 ,
struct V_20 * V_21 , struct V_127 * V_127 )
{
struct V_498 * V_498 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_635 * V_636 = & V_37 -> V_636 ;
int V_557 = 0 ;
F_245 (dev, &intel_crtc->base, intel_encoder) {
switch ( V_498 -> type ) {
case V_506 :
F_28 ( V_17 , L_403 ) ;
break;
case V_637 :
F_28 ( V_17 , L_404 ) ;
break;
case V_585 :
F_28 ( V_17 , L_405 ) ;
break;
case V_584 :
F_28 ( V_17 , L_406 ) ;
break;
default:
F_10 ( V_17 , L_407 ,
V_498 -> type ) ;
return;
}
}
if ( V_37 -> V_638 . V_639 == V_640 )
F_28 ( V_17 , L_408 ) ;
else if ( V_37 -> V_638 . V_639 == V_641 )
F_28 ( V_17 , L_409 ) ;
else if ( V_37 -> V_638 . V_639 == V_642 )
F_28 ( V_17 , L_410 ) ;
else
F_28 ( V_17 , L_411 ) ;
F_28 ( V_17 , L_412 ) ;
if ( F_261 ( V_127 -> V_38 . V_426 ) -> V_643 ) {
struct V_572 * V_573 ;
F_5 ( & V_636 -> V_644 ) ;
F_28 ( V_17 , L_413 ) ;
if ( ! V_636 -> V_645 ) {
F_28 ( V_17 , L_414 ) ;
F_7 ( & V_636 -> V_644 ) ;
return;
}
V_573 = & V_636 -> V_645 -> V_646 -> V_573 ;
F_10 ( V_17 , L_415 ,
V_636 -> V_492 ) ;
F_28 ( V_17 , L_416 ) ;
if ( V_636 -> V_647 == V_648 ) {
F_28 ( V_17 , L_417 ) ;
V_557 = V_573 -> V_574 -> V_557 ;
} else if ( V_636 -> V_647 == V_649 ) {
F_28 ( V_17 , L_418 ) ;
V_557 = V_573 -> V_650 -> V_557 ;
} else {
F_10 ( V_17 , L_419 ,
V_636 -> V_647 ) ;
F_7 ( & V_636 -> V_644 ) ;
return;
}
F_10 ( V_17 , L_420 , V_557 ) ;
F_28 ( V_17 , L_416 ) ;
F_7 ( & V_636 -> V_644 ) ;
} else {
F_28 ( V_17 , L_421 ) ;
}
F_28 ( V_17 , L_32 ) ;
}
static int F_271 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_127 * V_127 ;
int V_651 = 0 ;
F_63 (dev, intel_crtc) {
F_272 ( & V_127 -> V_38 . V_644 , NULL ) ;
if ( V_127 -> V_38 . V_426 -> V_43 ) {
V_651 ++ ;
F_10 ( V_17 , L_422 , V_651 ) ;
F_270 ( V_17 , V_21 , V_127 ) ;
}
F_273 ( & V_127 -> V_38 . V_644 ) ;
}
if ( ! V_651 )
F_28 ( V_17 , L_423 ) ;
return 0 ;
}
static int F_274 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_567 * V_499 ;
struct V_498 * V_498 ;
struct V_652 * V_653 ;
F_224 ( V_21 ) ;
F_20 (encoder, &dev->mode_config.encoder_list, head) {
V_498 = F_226 ( V_499 ) ;
if ( V_498 -> type != V_584 )
continue;
V_653 = F_275 ( V_499 ) ;
if ( ! V_653 -> V_645 . V_654 )
continue;
F_276 ( V_17 , & V_653 -> V_645 . V_655 ) ;
}
F_229 ( V_21 ) ;
return 0 ;
}
static int F_277 ( struct V_198 * V_198 , struct V_111 * V_656 )
{
struct V_657 * V_23 = V_198 -> V_199 ;
struct V_36 * V_37 = V_23 -> V_21 -> V_70 ;
struct V_658 * V_659 = & V_37 -> V_659 [ V_23 -> V_129 ] ;
if ( V_23 -> V_129 >= F_9 ( V_23 -> V_21 ) -> V_660 )
return - V_367 ;
F_66 ( & V_659 -> V_322 ) ;
if ( V_659 -> V_661 ) {
F_74 ( & V_659 -> V_322 ) ;
return - V_662 ;
}
V_659 -> V_661 = true ;
V_656 -> V_197 = V_198 -> V_199 ;
F_74 ( & V_659 -> V_322 ) ;
return 0 ;
}
static int F_278 ( struct V_198 * V_198 , struct V_111 * V_656 )
{
struct V_657 * V_23 = V_198 -> V_199 ;
struct V_36 * V_37 = V_23 -> V_21 -> V_70 ;
struct V_658 * V_659 = & V_37 -> V_659 [ V_23 -> V_129 ] ;
F_66 ( & V_659 -> V_322 ) ;
V_659 -> V_661 = false ;
F_74 ( & V_659 -> V_322 ) ;
return 0 ;
}
static int F_279 ( struct V_658 * V_659 )
{
F_280 ( & V_659 -> V_322 ) ;
return F_281 ( V_659 -> V_69 , V_659 -> V_419 ,
V_663 ) ;
}
static T_5
F_282 ( struct V_111 * V_656 , char T_6 * V_664 , T_7 V_75 ,
T_8 * V_201 )
{
struct V_657 * V_23 = V_656 -> V_197 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_658 * V_659 = & V_37 -> V_659 [ V_23 -> V_129 ] ;
char V_207 [ V_665 ] ;
int V_666 ;
T_5 V_667 ;
if ( V_75 < V_668 )
return - V_82 ;
if ( V_659 -> V_669 == V_670 )
return 0 ;
F_66 ( & V_659 -> V_322 ) ;
while ( F_279 ( V_659 ) == 0 ) {
int V_76 ;
if ( V_656 -> V_671 & V_672 ) {
F_74 ( & V_659 -> V_322 ) ;
return - V_673 ;
}
V_76 = F_283 ( V_659 -> V_674 ,
F_279 ( V_659 ) , V_659 -> V_322 ) ;
if ( V_76 ) {
F_74 ( & V_659 -> V_322 ) ;
return V_76 ;
}
}
V_666 = V_75 / V_668 ;
V_667 = 0 ;
while ( V_666 > 0 ) {
struct V_675 * V_631 =
& V_659 -> V_676 [ V_659 -> V_419 ] ;
int V_76 ;
if ( F_281 ( V_659 -> V_69 , V_659 -> V_419 ,
V_663 ) < 1 )
break;
F_284 ( V_663 ) ;
V_659 -> V_419 = ( V_659 -> V_419 + 1 ) & ( V_663 - 1 ) ;
V_667 += snprintf ( V_207 , V_665 ,
L_424 ,
V_631 -> V_677 , V_631 -> V_503 [ 0 ] ,
V_631 -> V_503 [ 1 ] , V_631 -> V_503 [ 2 ] ,
V_631 -> V_503 [ 3 ] , V_631 -> V_503 [ 4 ] ) ;
F_74 ( & V_659 -> V_322 ) ;
V_76 = F_285 ( V_664 , V_207 , V_668 ) ;
if ( V_76 == V_668 )
return - V_678 ;
V_664 += V_668 ;
V_666 -- ;
F_66 ( & V_659 -> V_322 ) ;
}
F_74 ( & V_659 -> V_322 ) ;
return V_667 ;
}
static int F_286 ( struct V_4 * V_679 , struct V_2 * V_3 ,
enum V_129 V_129 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_657 * V_23 = & V_680 [ V_129 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_287 ( V_23 -> V_53 , V_681 , V_679 , V_23 ,
& V_682 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_288 ( enum V_683 V_669 )
{
F_289 ( F_47 ( V_684 ) != V_685 ) ;
return V_684 [ V_669 ] ;
}
static int F_290 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_686 ; V_42 ++ )
F_10 ( V_17 , L_425 , F_64 ( V_42 ) ,
F_288 ( V_37 -> V_659 [ V_42 ] . V_669 ) ) ;
return 0 ;
}
static int F_291 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_292 ( V_111 , F_290 , V_21 ) ;
}
static int F_293 ( enum V_683 * V_669 ,
T_10 * V_209 )
{
if ( * V_669 == V_687 )
* V_669 = V_688 ;
switch ( * V_669 ) {
case V_688 :
* V_209 = V_689 | V_690 ;
break;
case V_670 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_294 ( struct V_20 * V_21 , enum V_129 V_129 ,
enum V_683 * V_669 )
{
struct V_498 * V_499 ;
struct V_127 * V_128 ;
struct V_652 * V_691 ;
int V_76 = 0 ;
* V_669 = V_688 ;
F_224 ( V_21 ) ;
F_295 (dev, encoder) {
if ( ! V_499 -> V_38 . V_128 )
continue;
V_128 = F_296 ( V_499 -> V_38 . V_128 ) ;
if ( V_128 -> V_129 != V_129 )
continue;
switch ( V_499 -> type ) {
case V_692 :
* V_669 = V_693 ;
break;
case V_584 :
case V_506 :
V_691 = F_275 ( & V_499 -> V_38 ) ;
switch ( V_691 -> V_694 ) {
case V_695 :
* V_669 = V_696 ;
break;
case V_697 :
* V_669 = V_698 ;
break;
case V_699 :
* V_669 = V_700 ;
break;
default:
F_297 ( 1 , L_426 ,
F_298 ( V_691 -> V_694 ) ) ;
break;
}
break;
default:
break;
}
}
F_229 ( V_21 ) ;
return V_76 ;
}
static int F_299 ( struct V_20 * V_21 ,
enum V_129 V_129 ,
enum V_683 * V_669 ,
T_10 * V_209 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
bool V_701 = false ;
if ( * V_669 == V_687 ) {
int V_76 = F_294 ( V_21 , V_129 , V_669 ) ;
if ( V_76 )
return V_76 ;
}
switch ( * V_669 ) {
case V_688 :
* V_209 = V_689 | V_702 ;
break;
case V_696 :
* V_209 = V_689 | V_703 ;
V_701 = true ;
break;
case V_698 :
* V_209 = V_689 | V_704 ;
V_701 = true ;
break;
case V_700 :
if ( ! F_82 ( V_21 ) )
return - V_82 ;
* V_209 = V_689 | V_705 ;
V_701 = true ;
break;
case V_670 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
if ( V_701 ) {
T_10 V_706 = F_71 ( V_707 ) ;
V_706 |= V_708 ;
switch ( V_129 ) {
case V_709 :
V_706 |= V_710 ;
break;
case V_711 :
V_706 |= V_712 ;
break;
case V_713 :
V_706 |= V_714 ;
break;
default:
return - V_82 ;
}
F_156 ( V_707 , V_706 ) ;
}
return 0 ;
}
static int F_300 ( struct V_20 * V_21 ,
enum V_129 V_129 ,
enum V_683 * V_669 ,
T_10 * V_209 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
bool V_701 = false ;
if ( * V_669 == V_687 ) {
int V_76 = F_294 ( V_21 , V_129 , V_669 ) ;
if ( V_76 )
return V_76 ;
}
switch ( * V_669 ) {
case V_688 :
* V_209 = V_689 | V_715 ;
break;
case V_693 :
if ( ! F_301 ( V_21 ) )
return - V_82 ;
* V_209 = V_689 | V_716 ;
break;
case V_696 :
if ( ! F_161 ( V_21 ) )
return - V_82 ;
* V_209 = V_689 | V_717 ;
V_701 = true ;
break;
case V_698 :
if ( ! F_161 ( V_21 ) )
return - V_82 ;
* V_209 = V_689 | V_718 ;
V_701 = true ;
break;
case V_700 :
if ( ! F_161 ( V_21 ) )
return - V_82 ;
* V_209 = V_689 | V_719 ;
V_701 = true ;
break;
case V_670 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
if ( V_701 ) {
T_10 V_706 = F_71 ( V_707 ) ;
F_186 ( ! F_161 ( V_21 ) ) ;
F_156 ( V_720 ,
F_71 ( V_720 ) | V_721 ) ;
if ( V_129 == V_709 )
V_706 |= V_710 ;
else
V_706 |= V_712 ;
F_156 ( V_707 , V_706 ) ;
}
return 0 ;
}
static void F_302 ( struct V_20 * V_21 ,
enum V_129 V_129 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
T_10 V_706 = F_71 ( V_707 ) ;
switch ( V_129 ) {
case V_709 :
V_706 &= ~ V_710 ;
break;
case V_711 :
V_706 &= ~ V_712 ;
break;
case V_713 :
V_706 &= ~ V_714 ;
break;
default:
return;
}
if ( ! ( V_706 & V_722 ) )
V_706 &= ~ V_708 ;
F_156 ( V_707 , V_706 ) ;
}
static void F_303 ( struct V_20 * V_21 ,
enum V_129 V_129 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
T_10 V_706 = F_71 ( V_707 ) ;
if ( V_129 == V_709 )
V_706 &= ~ V_710 ;
else
V_706 &= ~ V_712 ;
F_156 ( V_707 , V_706 ) ;
if ( ! ( V_706 & V_722 ) ) {
F_156 ( V_720 ,
F_71 ( V_720 ) & ~ V_721 ) ;
}
}
static int F_304 ( enum V_683 * V_669 ,
T_10 * V_209 )
{
if ( * V_669 == V_687 )
* V_669 = V_688 ;
switch ( * V_669 ) {
case V_723 :
* V_209 = V_689 | V_724 ;
break;
case V_725 :
* V_209 = V_689 | V_726 ;
break;
case V_688 :
* V_209 = V_689 | V_727 ;
break;
case V_670 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static void F_305 ( struct V_20 * V_21 , bool V_728 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_127 * V_128 =
F_296 ( V_37 -> V_729 [ V_709 ] ) ;
struct V_594 * V_595 ;
struct V_730 * V_426 ;
int V_76 = 0 ;
F_224 ( V_21 ) ;
V_426 = F_306 ( V_21 ) ;
if ( ! V_426 ) {
V_76 = - V_10 ;
goto V_206;
}
V_426 -> V_731 = F_307 ( & V_128 -> V_38 ) ;
V_595 = F_308 ( V_426 , V_128 ) ;
if ( F_309 ( V_595 ) ) {
V_76 = F_310 ( V_595 ) ;
goto V_206;
}
V_595 -> V_732 . V_733 = V_728 ;
if ( V_595 -> V_734 == V_735 &&
V_595 -> V_732 . V_479 != V_728 )
V_595 -> V_38 . V_736 = true ;
V_76 = F_311 ( V_426 ) ;
V_206:
F_229 ( V_21 ) ;
F_297 ( V_76 , L_427 , V_728 , V_76 ) ;
if ( V_76 )
F_312 ( V_426 ) ;
}
static int F_313 ( struct V_20 * V_21 ,
enum V_129 V_129 ,
enum V_683 * V_669 ,
T_10 * V_209 )
{
if ( * V_669 == V_687 )
* V_669 = V_737 ;
switch ( * V_669 ) {
case V_723 :
* V_209 = V_689 | V_738 ;
break;
case V_725 :
* V_209 = V_689 | V_739 ;
break;
case V_737 :
if ( F_125 ( V_21 ) && V_129 == V_709 )
F_305 ( V_21 , true ) ;
* V_209 = V_689 | V_740 ;
break;
case V_670 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_314 ( struct V_20 * V_21 , enum V_129 V_129 ,
enum V_683 V_669 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
struct V_658 * V_659 = & V_37 -> V_659 [ V_129 ] ;
struct V_127 * V_128 = F_296 ( F_315 ( V_21 ,
V_129 ) ) ;
T_4 V_209 = 0 ;
int V_76 ;
if ( V_659 -> V_669 == V_669 )
return 0 ;
if ( V_659 -> V_669 && V_669 )
return - V_82 ;
if ( ! F_88 ( V_37 , F_89 ( V_129 ) ) ) {
F_316 ( L_428 ) ;
return - V_741 ;
}
if ( F_317 ( V_21 ) )
V_76 = F_293 ( & V_669 , & V_209 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_76 = F_300 ( V_21 , V_129 , & V_669 , & V_209 ) ;
else if ( F_93 ( V_21 ) )
V_76 = F_299 ( V_21 , V_129 , & V_669 , & V_209 ) ;
else if ( F_117 ( V_21 ) || F_119 ( V_21 ) )
V_76 = F_304 ( & V_669 , & V_209 ) ;
else
V_76 = F_313 ( V_21 , V_129 , & V_669 , & V_209 ) ;
if ( V_76 != 0 )
return V_76 ;
if ( V_669 ) {
struct V_675 * V_676 ;
F_99 ( L_429 ,
F_64 ( V_129 ) , F_288 ( V_669 ) ) ;
V_676 = F_318 ( V_663 ,
sizeof( V_659 -> V_676 [ 0 ] ) ,
V_9 ) ;
if ( ! V_676 )
return - V_10 ;
F_319 ( V_128 ) ;
F_66 ( & V_659 -> V_322 ) ;
F_106 ( V_659 -> V_676 ) ;
V_659 -> V_676 = V_676 ;
V_659 -> V_69 = 0 ;
V_659 -> V_419 = 0 ;
F_74 ( & V_659 -> V_322 ) ;
}
V_659 -> V_669 = V_669 ;
F_156 ( F_320 ( V_129 ) , V_209 ) ;
F_321 ( F_320 ( V_129 ) ) ;
if ( V_669 == V_670 ) {
struct V_675 * V_676 ;
struct V_127 * V_128 =
F_296 ( V_37 -> V_729 [ V_129 ] ) ;
F_99 ( L_430 ,
F_64 ( V_129 ) ) ;
F_272 ( & V_128 -> V_38 . V_644 , NULL ) ;
if ( V_128 -> V_38 . V_426 -> V_43 )
F_322 ( V_21 , V_129 ) ;
F_273 ( & V_128 -> V_38 . V_644 ) ;
F_66 ( & V_659 -> V_322 ) ;
V_676 = V_659 -> V_676 ;
V_659 -> V_676 = NULL ;
V_659 -> V_69 = 0 ;
V_659 -> V_419 = 0 ;
F_74 ( & V_659 -> V_322 ) ;
F_106 ( V_676 ) ;
if ( F_161 ( V_21 ) )
F_303 ( V_21 , V_129 ) ;
else if ( F_93 ( V_21 ) )
F_302 ( V_21 , V_129 ) ;
else if ( F_125 ( V_21 ) && V_129 == V_709 )
F_305 ( V_21 , false ) ;
F_323 ( V_128 ) ;
}
return 0 ;
}
static int F_324 ( char * V_207 , char * V_742 [] , int V_743 )
{
int V_744 = 0 ;
while ( * V_207 ) {
char * V_634 ;
V_207 = F_325 ( V_207 ) ;
if ( ! * V_207 )
break;
for ( V_634 = V_207 ; * V_634 && ! isspace ( * V_634 ) ; V_634 ++ )
;
if ( V_744 == V_743 ) {
F_99 ( L_431 ,
V_743 ) ;
return - V_82 ;
}
if ( * V_634 )
* V_634 ++ = '\0' ;
V_742 [ V_744 ++ ] = V_207 ;
V_207 = V_634 ;
}
return V_744 ;
}
static int
F_326 ( const char * V_207 , enum V_745 * V_746 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_47 ( V_747 ) ; V_42 ++ )
if ( ! strcmp ( V_207 , V_747 [ V_42 ] ) ) {
* V_746 = V_42 ;
return 0 ;
}
return - V_82 ;
}
static int F_327 ( const char * V_207 , enum V_129 * V_129 )
{
const char V_53 = V_207 [ 0 ] ;
if ( V_53 < 'A' || V_53 >= F_64 ( V_686 ) )
return - V_82 ;
* V_129 = V_53 - 'A' ;
return 0 ;
}
static int
F_328 ( const char * V_207 , enum V_683 * V_60 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < F_47 ( V_684 ) ; V_42 ++ )
if ( ! strcmp ( V_207 , V_684 [ V_42 ] ) ) {
* V_60 = V_42 ;
return 0 ;
}
return - V_82 ;
}
static int F_329 ( struct V_20 * V_21 , char * V_207 , T_7 V_748 )
{
#define F_330 3
int V_744 ;
char * V_742 [ F_330 ] ;
enum V_129 V_129 ;
enum V_745 V_749 ;
enum V_683 V_669 ;
V_744 = F_324 ( V_207 , V_742 , F_330 ) ;
if ( V_744 != F_330 ) {
F_99 ( L_432 ,
F_330 ) ;
return - V_82 ;
}
if ( F_326 ( V_742 [ 0 ] , & V_749 ) < 0 ) {
F_99 ( L_433 , V_742 [ 0 ] ) ;
return - V_82 ;
}
if ( F_327 ( V_742 [ 1 ] , & V_129 ) < 0 ) {
F_99 ( L_434 , V_742 [ 1 ] ) ;
return - V_82 ;
}
if ( F_328 ( V_742 [ 2 ] , & V_669 ) < 0 ) {
F_99 ( L_435 , V_742 [ 2 ] ) ;
return - V_82 ;
}
return F_314 ( V_21 , V_129 , V_669 ) ;
}
static T_5 F_331 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_7 V_748 , T_8 * V_750 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_751 ;
int V_76 ;
if ( V_748 == 0 )
return 0 ;
if ( V_748 > V_752 - 1 ) {
F_99 ( L_436 ,
V_752 ) ;
return - V_753 ;
}
V_751 = F_3 ( V_748 + 1 , V_9 ) ;
if ( ! V_751 )
return - V_10 ;
if ( F_332 ( V_751 , V_192 , V_748 ) ) {
V_76 = - V_678 ;
goto V_206;
}
V_751 [ V_748 ] = '\0' ;
V_76 = F_329 ( V_21 , V_751 , V_748 ) ;
V_206:
F_106 ( V_751 ) ;
if ( V_76 < 0 )
return V_76 ;
* V_750 += V_748 ;
return V_748 ;
}
static T_5 F_333 ( struct V_111 * V_111 ,
const char T_6 * V_192 ,
T_7 V_748 , T_8 * V_750 )
{
char * V_754 ;
int V_433 = 0 ;
struct V_20 * V_21 ;
struct V_568 * V_501 ;
struct V_68 * V_755 ;
struct V_502 * V_502 ;
int V_209 = 0 ;
V_21 = ( (struct V_16 * ) V_111 -> V_197 ) -> V_19 ;
V_755 = & V_21 -> V_414 . V_755 ;
if ( V_748 == 0 )
return 0 ;
V_754 = F_3 ( V_748 + 1 , V_9 ) ;
if ( ! V_754 )
return - V_10 ;
if ( F_332 ( V_754 , V_192 , V_748 ) ) {
V_433 = - V_678 ;
goto V_206;
}
V_754 [ V_748 ] = '\0' ;
F_99 ( L_437 , ( unsigned int ) V_748 ) ;
F_20 (connector, connector_list, head) {
if ( V_501 -> V_756 !=
V_757 )
continue;
if ( V_501 -> V_433 == V_569 &&
V_501 -> V_499 != NULL ) {
V_502 = F_227 ( V_501 -> V_499 ) ;
V_433 = F_334 ( V_754 , 10 , & V_209 ) ;
if ( V_433 < 0 )
goto V_206;
F_99 ( L_438 , V_209 ) ;
if ( V_209 == 1 )
V_502 -> V_758 = 1 ;
else
V_502 -> V_758 = 0 ;
}
}
V_206:
F_106 ( V_754 ) ;
if ( V_433 < 0 )
return V_433 ;
* V_750 += V_748 ;
return V_748 ;
}
static int F_335 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_568 * V_501 ;
struct V_68 * V_755 = & V_21 -> V_414 . V_755 ;
struct V_502 * V_502 ;
F_20 (connector, connector_list, head) {
if ( V_501 -> V_756 !=
V_757 )
continue;
if ( V_501 -> V_433 == V_569 &&
V_501 -> V_499 != NULL ) {
V_502 = F_227 ( V_501 -> V_499 ) ;
if ( V_502 -> V_758 )
F_28 ( V_17 , L_439 ) ;
else
F_28 ( V_17 , L_440 ) ;
} else
F_28 ( V_17 , L_440 ) ;
}
return 0 ;
}
static int F_336 ( struct V_198 * V_198 ,
struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_292 ( V_111 , F_335 , V_21 ) ;
}
static int F_337 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_568 * V_501 ;
struct V_68 * V_755 = & V_21 -> V_414 . V_755 ;
struct V_502 * V_502 ;
F_20 (connector, connector_list, head) {
if ( V_501 -> V_756 !=
V_757 )
continue;
if ( V_501 -> V_433 == V_569 &&
V_501 -> V_499 != NULL ) {
V_502 = F_227 ( V_501 -> V_499 ) ;
F_10 ( V_17 , L_441 , V_502 -> V_759 ) ;
} else
F_28 ( V_17 , L_440 ) ;
}
return 0 ;
}
static int F_338 ( struct V_198 * V_198 ,
struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_292 ( V_111 , F_337 , V_21 ) ;
}
static int F_339 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_568 * V_501 ;
struct V_68 * V_755 = & V_21 -> V_414 . V_755 ;
struct V_502 * V_502 ;
F_20 (connector, connector_list, head) {
if ( V_501 -> V_756 !=
V_757 )
continue;
if ( V_501 -> V_433 == V_569 &&
V_501 -> V_499 != NULL ) {
V_502 = F_227 ( V_501 -> V_499 ) ;
F_10 ( V_17 , L_442 , V_502 -> V_760 ) ;
} else
F_28 ( V_17 , L_440 ) ;
}
return 0 ;
}
static int F_340 ( struct V_198 * V_198 ,
struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_292 ( V_111 , F_339 , V_21 ) ;
}
static void F_341 ( struct V_16 * V_17 , const T_13 V_632 [ 8 ] )
{
struct V_20 * V_21 = V_17 -> V_19 ;
int V_761 ;
int V_762 ;
if ( F_82 ( V_21 ) )
V_762 = 3 ;
else if ( F_93 ( V_21 ) )
V_762 = 1 ;
else
V_762 = F_342 ( V_21 ) + 1 ;
F_224 ( V_21 ) ;
for ( V_761 = 0 ; V_761 < V_762 ; V_761 ++ ) {
unsigned int V_763 = V_632 [ V_761 ] ;
if ( F_9 ( V_21 ) -> V_24 >= 9 || F_93 ( V_21 ) )
V_763 *= 10 ;
else if ( V_761 > 0 )
V_763 *= 5 ;
F_10 ( V_17 , L_443 ,
V_761 , V_632 [ V_761 ] , V_763 / 10 , V_763 % 10 ) ;
}
F_229 ( V_21 ) ;
}
static int F_343 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_36 * V_37 = V_21 -> V_70 ;
const T_13 * V_764 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_764 = V_37 -> V_632 . V_765 ;
else
V_764 = F_24 ( V_21 ) -> V_632 . V_766 ;
F_341 ( V_17 , V_764 ) ;
return 0 ;
}
static int F_344 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_36 * V_37 = V_21 -> V_70 ;
const T_13 * V_764 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_764 = V_37 -> V_632 . V_765 ;
else
V_764 = F_24 ( V_21 ) -> V_632 . V_767 ;
F_341 ( V_17 , V_764 ) ;
return 0 ;
}
static int F_345 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_36 * V_37 = V_21 -> V_70 ;
const T_13 * V_764 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_764 = V_37 -> V_632 . V_765 ;
else
V_764 = F_24 ( V_21 ) -> V_632 . V_768 ;
F_341 ( V_17 , V_764 ) ;
return 0 ;
}
static int F_346 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
if ( F_9 ( V_21 ) -> V_24 < 5 )
return - V_367 ;
return F_292 ( V_111 , F_343 , V_21 ) ;
}
static int F_347 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
if ( F_348 ( V_21 ) )
return - V_367 ;
return F_292 ( V_111 , F_344 , V_21 ) ;
}
static int F_349 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
if ( F_348 ( V_21 ) )
return - V_367 ;
return F_292 ( V_111 , F_345 , V_21 ) ;
}
static T_5 F_350 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_7 V_748 , T_8 * V_750 , T_13 V_632 [ 8 ] )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
T_13 V_769 [ 8 ] = { 0 } ;
int V_762 ;
int V_761 ;
int V_76 ;
char V_706 [ 32 ] ;
if ( F_82 ( V_21 ) )
V_762 = 3 ;
else if ( F_93 ( V_21 ) )
V_762 = 1 ;
else
V_762 = F_342 ( V_21 ) + 1 ;
if ( V_748 >= sizeof( V_706 ) )
return - V_82 ;
if ( F_332 ( V_706 , V_192 , V_748 ) )
return - V_678 ;
V_706 [ V_748 ] = '\0' ;
V_76 = sscanf ( V_706 , L_444 ,
& V_769 [ 0 ] , & V_769 [ 1 ] , & V_769 [ 2 ] , & V_769 [ 3 ] ,
& V_769 [ 4 ] , & V_769 [ 5 ] , & V_769 [ 6 ] , & V_769 [ 7 ] ) ;
if ( V_76 != V_762 )
return - V_82 ;
F_224 ( V_21 ) ;
for ( V_761 = 0 ; V_761 < V_762 ; V_761 ++ )
V_632 [ V_761 ] = V_769 [ V_761 ] ;
F_229 ( V_21 ) ;
return V_748 ;
}
static T_5 F_351 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_7 V_748 , T_8 * V_750 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_13 * V_764 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_764 = V_37 -> V_632 . V_765 ;
else
V_764 = F_24 ( V_21 ) -> V_632 . V_766 ;
return F_350 ( V_111 , V_192 , V_748 , V_750 , V_764 ) ;
}
static T_5 F_352 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_7 V_748 , T_8 * V_750 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_13 * V_764 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_764 = V_37 -> V_632 . V_765 ;
else
V_764 = F_24 ( V_21 ) -> V_632 . V_767 ;
return F_350 ( V_111 , V_192 , V_748 , V_750 , V_764 ) ;
}
static T_5 F_353 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_7 V_748 , T_8 * V_750 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_13 * V_764 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_764 = V_37 -> V_632 . V_765 ;
else
V_764 = F_24 ( V_21 ) -> V_632 . V_768 ;
return F_350 ( V_111 , V_192 , V_748 , V_750 , V_764 ) ;
}
static int
F_354 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
* V_209 = F_67 ( & V_37 -> V_286 . V_770 ) ;
return 0 ;
}
static int
F_355 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
if ( F_356 ( & V_37 -> V_286 ) )
return - V_673 ;
F_79 ( V_37 ) ;
F_357 ( V_21 , V_209 ,
L_445 , V_209 ) ;
F_80 ( V_37 ) ;
return 0 ;
}
static int
F_358 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
* V_209 = V_37 -> V_286 . V_771 ;
return 0 ;
}
static int
F_359 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
F_99 ( L_446 , V_209 ) ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_37 -> V_286 . V_771 = V_209 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_360 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
* V_209 = V_37 -> V_286 . V_772 ;
return 0 ;
}
static int
F_361 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_37 -> V_286 . V_772 = V_209 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_362 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
* V_209 = V_37 -> V_286 . V_773 ;
return 0 ;
}
static int
F_363 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
F_99 ( L_447 , V_209 ) ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_37 -> V_286 . V_773 = V_209 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_364 ( void * V_18 , T_2 * V_209 )
{
* V_209 = V_774 ;
return 0 ;
}
static int
F_365 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
F_366 ( L_448 , V_209 ) ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
if ( V_209 & V_775 ) {
V_76 = F_367 ( V_21 ) ;
if ( V_76 )
goto V_776;
}
if ( V_209 & ( V_777 | V_775 ) )
F_368 ( V_21 ) ;
if ( V_209 & V_778 )
F_369 ( V_37 , V_779 , V_780 ) ;
if ( V_209 & V_781 )
F_369 ( V_37 , V_779 , V_782 ) ;
V_776:
F_7 ( & V_21 -> V_77 ) ;
return V_76 ;
}
static int
F_370 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_367 ;
F_116 ( & V_37 -> V_211 . V_212 ) ;
V_76 = F_33 ( & V_37 -> V_211 . V_279 ) ;
if ( V_76 )
return V_76 ;
* V_209 = F_126 ( V_37 , V_37 -> V_211 . V_394 ) ;
F_7 ( & V_37 -> V_211 . V_279 ) ;
return 0 ;
}
static int
F_371 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_783 , V_784 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_367 ;
F_116 ( & V_37 -> V_211 . V_212 ) ;
F_99 ( L_449 , V_209 ) ;
V_76 = F_33 ( & V_37 -> V_211 . V_279 ) ;
if ( V_76 )
return V_76 ;
V_209 = F_372 ( V_37 , V_209 ) ;
V_783 = V_37 -> V_211 . V_241 ;
V_784 = V_37 -> V_211 . V_276 ;
if ( V_209 < V_784 || V_209 > V_783 || V_209 < V_37 -> V_211 . V_393 ) {
F_7 ( & V_37 -> V_211 . V_279 ) ;
return - V_82 ;
}
V_37 -> V_211 . V_394 = V_209 ;
F_373 ( V_21 , V_209 ) ;
F_7 ( & V_37 -> V_211 . V_279 ) ;
return 0 ;
}
static int
F_374 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_367 ;
F_116 ( & V_37 -> V_211 . V_212 ) ;
V_76 = F_33 ( & V_37 -> V_211 . V_279 ) ;
if ( V_76 )
return V_76 ;
* V_209 = F_126 ( V_37 , V_37 -> V_211 . V_393 ) ;
F_7 ( & V_37 -> V_211 . V_279 ) ;
return 0 ;
}
static int
F_375 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_783 , V_784 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_367 ;
F_116 ( & V_37 -> V_211 . V_212 ) ;
F_99 ( L_450 , V_209 ) ;
V_76 = F_33 ( & V_37 -> V_211 . V_279 ) ;
if ( V_76 )
return V_76 ;
V_209 = F_372 ( V_37 , V_209 ) ;
V_783 = V_37 -> V_211 . V_241 ;
V_784 = V_37 -> V_211 . V_276 ;
if ( V_209 < V_784 || V_209 > V_783 || V_209 > V_37 -> V_211 . V_394 ) {
F_7 ( & V_37 -> V_211 . V_279 ) ;
return - V_82 ;
}
V_37 -> V_211 . V_393 = V_209 ;
F_373 ( V_21 , V_209 ) ;
F_7 ( & V_37 -> V_211 . V_279 ) ;
return 0 ;
}
static int
F_376 ( void * V_18 , T_2 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_785 ;
int V_76 ;
if ( ! ( F_119 ( V_21 ) || F_120 ( V_21 ) ) )
return - V_367 ;
V_76 = F_33 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_79 ( V_37 ) ;
V_785 = F_71 ( V_786 ) ;
F_80 ( V_37 ) ;
F_7 ( & V_37 -> V_21 -> V_77 ) ;
* V_209 = ( V_785 & V_787 ) >> V_788 ;
return 0 ;
}
static int
F_377 ( void * V_18 , T_2 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_36 * V_37 = V_21 -> V_70 ;
T_4 V_785 ;
if ( ! ( F_119 ( V_21 ) || F_120 ( V_21 ) ) )
return - V_367 ;
if ( V_209 > 3 )
return - V_82 ;
F_79 ( V_37 ) ;
F_99 ( L_451 , V_209 ) ;
V_785 = F_71 ( V_786 ) ;
V_785 &= ~ V_787 ;
V_785 |= ( V_209 << V_788 ) ;
F_156 ( V_786 , V_785 ) ;
F_80 ( V_37 ) ;
return 0 ;
}
static void F_378 ( struct V_20 * V_21 ,
struct V_789 * V_488 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
const int V_790 = 2 ;
int V_791 ;
T_4 V_792 [ V_790 ] , V_793 [ V_790 ] ;
V_792 [ 0 ] = F_71 ( V_794 ) ;
V_792 [ 1 ] = F_71 ( V_795 ) ;
V_793 [ 0 ] = F_71 ( V_796 ) ;
V_793 [ 1 ] = F_71 ( V_797 ) ;
for ( V_791 = 0 ; V_791 < V_790 ; V_791 ++ ) {
unsigned int V_798 ;
if ( V_792 [ V_791 ] & V_799 )
continue;
V_488 -> V_800 = 1 ;
V_488 -> V_801 ++ ;
V_798 = ( ( V_792 [ V_791 ] & V_802 ) ? 0 : 2 ) +
( ( V_792 [ V_791 ] & V_803 ) ? 0 : 2 ) +
( ( V_792 [ V_791 ] & V_804 ) ? 0 : 2 ) +
( ( V_793 [ V_791 ] & V_805 ) ? 0 : 2 ) ;
V_488 -> V_806 += V_798 ;
V_488 -> V_807 = F_379 ( V_488 -> V_807 , V_798 ) ;
}
V_488 -> V_808 = V_488 -> V_801 ;
}
static void F_380 ( struct V_20 * V_21 ,
struct V_789 * V_488 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
int V_809 = 3 , V_790 = 4 ;
int V_60 , V_791 ;
T_4 V_810 [ V_809 ] , V_811 [ 2 * V_809 ] , V_812 [ 2 ] ;
if ( F_123 ( V_21 ) ) {
V_809 = 1 ;
V_790 = 3 ;
}
for ( V_60 = 0 ; V_60 < V_809 ; V_60 ++ ) {
V_810 [ V_60 ] = F_71 ( F_381 ( V_60 ) ) ;
V_811 [ 2 * V_60 ] = F_71 ( F_382 ( V_60 ) ) ;
V_811 [ 2 * V_60 + 1 ] = F_71 ( F_383 ( V_60 ) ) ;
}
V_812 [ 0 ] = V_813 |
V_814 |
V_815 |
V_816 ;
V_812 [ 1 ] = V_817 |
V_818 |
V_819 |
V_820 ;
for ( V_60 = 0 ; V_60 < V_809 ; V_60 ++ ) {
unsigned int V_821 = 0 ;
if ( ( V_810 [ V_60 ] & V_822 ) == 0 )
continue;
V_488 -> V_800 ++ ;
if ( F_129 ( V_21 ) )
V_821 = F_9 ( V_21 ) -> V_801 ;
for ( V_791 = 0 ; V_791 < V_790 ; V_791 ++ ) {
unsigned int V_798 ;
if ( F_123 ( V_21 ) &&
! ( V_810 [ V_60 ] & ( F_384 ( V_791 ) ) ) )
continue;
if ( F_123 ( V_21 ) )
V_821 ++ ;
V_798 = 2 * F_263 ( V_811 [ 2 * V_60 + V_791 / 2 ] &
V_812 [ V_791 % 2 ] ) ;
V_488 -> V_806 += V_798 ;
V_488 -> V_807 = F_379 ( V_488 -> V_807 ,
V_798 ) ;
}
V_488 -> V_808 += V_821 ;
V_488 -> V_801 = F_379 ( V_488 -> V_801 ,
V_821 ) ;
}
}
static int F_385 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_789 V_488 ;
if ( ( F_9 ( V_21 ) -> V_24 < 8 ) || F_121 ( V_21 ) )
return - V_367 ;
F_28 ( V_17 , L_452 ) ;
F_10 ( V_17 , L_453 ,
F_9 ( V_21 ) -> V_800 ) ;
F_10 ( V_17 , L_454 ,
F_9 ( V_21 ) -> V_808 ) ;
F_10 ( V_17 , L_455 ,
F_9 ( V_21 ) -> V_801 ) ;
F_10 ( V_17 , L_456 ,
F_9 ( V_21 ) -> V_806 ) ;
F_10 ( V_17 , L_457 ,
F_9 ( V_21 ) -> V_807 ) ;
F_10 ( V_17 , L_458 ,
F_1 ( F_9 ( V_21 ) -> V_823 ) ) ;
F_10 ( V_17 , L_459 ,
F_1 ( F_9 ( V_21 ) -> V_824 ) ) ;
F_10 ( V_17 , L_460 ,
F_1 ( F_9 ( V_21 ) -> V_825 ) ) ;
F_28 ( V_17 , L_461 ) ;
memset ( & V_488 , 0 , sizeof( V_488 ) ) ;
if ( F_82 ( V_21 ) ) {
F_378 ( V_21 , & V_488 ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 9 ) {
F_380 ( V_21 , & V_488 ) ;
}
F_10 ( V_17 , L_462 ,
V_488 . V_800 ) ;
F_10 ( V_17 , L_463 ,
V_488 . V_808 ) ;
F_10 ( V_17 , L_464 ,
V_488 . V_801 ) ;
F_10 ( V_17 , L_465 ,
V_488 . V_806 ) ;
F_10 ( V_17 , L_466 ,
V_488 . V_807 ) ;
return 0 ;
}
static int F_386 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
struct V_36 * V_37 = V_21 -> V_70 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_79 ( V_37 ) ;
F_124 ( V_37 , V_247 ) ;
return 0 ;
}
static int F_387 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
struct V_36 * V_37 = V_21 -> V_70 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_127 ( V_37 , V_247 ) ;
F_80 ( V_37 ) ;
return 0 ;
}
static int F_388 ( struct V_4 * V_679 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_287 ( L_467 ,
V_826 ,
V_679 , V_21 ,
& V_827 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_827 ) ;
}
static int F_389 ( struct V_4 * V_679 ,
struct V_2 * V_3 ,
const char * V_53 ,
const struct V_828 * V_829 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_287 ( V_53 ,
V_681 | V_830 ,
V_679 , V_21 ,
V_829 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_829 ) ;
}
void F_390 ( struct V_20 * V_21 )
{
struct V_36 * V_37 = V_21 -> V_70 ;
enum V_129 V_129 ;
F_83 (dev_priv, pipe) {
struct V_658 * V_659 = & V_37 -> V_659 [ V_129 ] ;
V_659 -> V_661 = false ;
F_391 ( & V_659 -> V_322 ) ;
F_392 ( & V_659 -> V_674 ) ;
}
}
int F_393 ( struct V_2 * V_3 )
{
int V_76 , V_42 ;
V_76 = F_388 ( V_3 -> V_831 , V_3 ) ;
if ( V_76 )
return V_76 ;
for ( V_42 = 0 ; V_42 < F_47 ( V_680 ) ; V_42 ++ ) {
V_76 = F_286 ( V_3 -> V_831 , V_3 , V_42 ) ;
if ( V_76 )
return V_76 ;
}
for ( V_42 = 0 ; V_42 < F_47 ( V_832 ) ; V_42 ++ ) {
V_76 = F_389 ( V_3 -> V_831 , V_3 ,
V_832 [ V_42 ] . V_53 ,
V_832 [ V_42 ] . V_829 ) ;
if ( V_76 )
return V_76 ;
}
return F_394 ( V_833 ,
V_834 ,
V_3 -> V_831 , V_3 ) ;
}
void F_395 ( struct V_2 * V_3 )
{
int V_42 ;
F_396 ( V_833 ,
V_834 , V_3 ) ;
F_396 ( (struct V_835 * ) & V_827 ,
1 , V_3 ) ;
for ( V_42 = 0 ; V_42 < F_47 ( V_680 ) ; V_42 ++ ) {
struct V_835 * V_836 =
(struct V_835 * ) & V_680 [ V_42 ] ;
F_396 ( V_836 , 1 , V_3 ) ;
}
for ( V_42 = 0 ; V_42 < F_47 ( V_832 ) ; V_42 ++ ) {
struct V_835 * V_836 =
(struct V_835 * ) V_832 [ V_42 ] . V_829 ;
F_396 ( V_836 , 1 , V_3 ) ;
}
}
static int F_397 ( struct V_16 * V_17 , void * V_18 )
{
struct V_568 * V_501 = V_17 -> V_19 ;
struct V_502 * V_502 =
F_227 ( & F_398 ( V_501 ) -> V_38 ) ;
T_14 V_207 [ 16 ] ;
T_5 V_837 ;
int V_42 ;
if ( V_501 -> V_433 != V_569 )
return - V_367 ;
for ( V_42 = 0 ; V_42 < F_47 ( V_838 ) ; V_42 ++ ) {
const struct V_839 * V_88 = & V_838 [ V_42 ] ;
T_7 V_32 = V_88 -> V_634 ? V_88 -> V_634 - V_88 -> V_470 + 1 : ( V_88 -> V_32 ? : 1 ) ;
if ( V_88 -> V_840 &&
V_501 -> V_756 != V_841 )
continue;
if ( F_186 ( V_32 > sizeof( V_207 ) ) )
continue;
V_837 = F_399 ( & V_502 -> V_842 , V_88 -> V_470 , V_207 , V_32 ) ;
if ( V_837 <= 0 ) {
F_400 ( L_468 ,
V_32 , V_88 -> V_470 , V_837 ) ;
continue;
}
F_10 ( V_17 , L_469 , V_88 -> V_470 , ( int ) V_32 , V_207 ) ;
}
return 0 ;
}
static int F_401 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
return F_292 ( V_111 , F_397 , V_198 -> V_199 ) ;
}
int F_402 ( struct V_568 * V_501 )
{
struct V_4 * V_679 = V_501 -> V_843 ;
if ( ! V_679 )
return - V_367 ;
if ( V_501 -> V_756 == V_757 ||
V_501 -> V_756 == V_841 )
F_287 ( L_470 , V_681 , V_679 , V_501 ,
& V_844 ) ;
return 0 ;
}
