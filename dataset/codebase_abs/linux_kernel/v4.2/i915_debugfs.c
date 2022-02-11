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
static void
F_19 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
struct V_32 * V_33 = F_20 ( V_26 -> V_34 . V_21 ) ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_39 = 0 ;
int V_40 ;
F_10 ( V_17 , L_10 ,
& V_26 -> V_34 ,
V_26 -> V_41 ? L_11 : L_6 ,
F_15 ( V_26 ) ,
F_16 ( V_26 ) ,
F_17 ( V_26 ) ,
V_26 -> V_34 . V_42 / 1024 ,
V_26 -> V_34 . V_43 ,
V_26 -> V_34 . V_44 ) ;
F_21 (ring, dev_priv, i)
F_10 ( V_17 , L_12 ,
F_22 ( V_26 -> V_45 [ V_40 ] ) ) ;
F_10 ( V_17 , L_13 ,
F_22 ( V_26 -> V_46 ) ,
F_22 ( V_26 -> V_47 ) ,
F_23 ( F_20 ( V_26 -> V_34 . V_21 ) , V_26 -> V_48 ) ,
V_26 -> V_49 ? L_14 : L_15 ,
V_26 -> V_50 == V_51 ? L_16 : L_15 ) ;
if ( V_26 -> V_34 . V_52 )
F_10 ( V_17 , L_17 , V_26 -> V_34 . V_52 ) ;
F_24 (vma, &obj->vma_list, vma_link) {
if ( V_38 -> V_39 > 0 )
V_39 ++ ;
}
F_10 ( V_17 , L_18 , V_39 ) ;
if ( V_26 -> V_27 )
F_10 ( V_17 , L_19 ) ;
if ( V_26 -> V_53 != V_54 )
F_10 ( V_17 , L_20 , V_26 -> V_53 ) ;
F_24 (vma, &obj->vma_list, vma_link) {
if ( ! F_25 ( V_38 -> V_55 ) )
F_26 ( V_17 , L_21 ) ;
else
F_26 ( V_17 , L_22 ) ;
F_10 ( V_17 , L_23 ,
V_38 -> V_8 . V_56 , V_38 -> V_8 . V_42 ,
V_38 -> V_57 . type ) ;
}
if ( V_26 -> V_58 )
F_10 ( V_17 , L_24 , V_26 -> V_58 -> V_56 ) ;
if ( V_26 -> V_27 || V_26 -> V_59 ) {
char V_60 [ 3 ] , * V_61 = V_60 ;
if ( V_26 -> V_27 )
* V_61 ++ = 'p' ;
if ( V_26 -> V_59 )
* V_61 ++ = 'f' ;
* V_61 = '\0' ;
F_10 ( V_17 , L_25 , V_60 ) ;
}
if ( V_26 -> V_46 != NULL )
F_10 ( V_17 , L_26 ,
F_27 ( V_26 -> V_46 ) -> V_52 ) ;
if ( V_26 -> V_62 )
F_10 ( V_17 , L_27 , V_26 -> V_62 ) ;
}
static void F_28 ( struct V_16 * V_17 , struct V_63 * V_64 )
{
F_29 ( V_17 , V_64 -> V_65 . V_66 ? 'I' : 'i' ) ;
F_29 ( V_17 , V_64 -> V_67 ? 'R' : 'r' ) ;
F_29 ( V_17 , ' ' ) ;
}
static int F_30 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_68 * V_69 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_71 * V_55 = & V_33 -> V_72 . V_34 ;
struct V_37 * V_38 ;
T_3 V_73 , V_74 ;
int V_75 , V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
switch ( V_14 ) {
case V_78 :
F_26 ( V_17 , L_28 ) ;
V_69 = & V_55 -> V_79 ;
break;
case V_80 :
F_26 ( V_17 , L_29 ) ;
V_69 = & V_55 -> V_81 ;
break;
default:
F_7 ( & V_21 -> V_77 ) ;
return - V_82 ;
}
V_73 = V_74 = V_75 = 0 ;
F_24 (vma, head, mm_list) {
F_10 ( V_17 , L_30 ) ;
F_19 ( V_17 , V_38 -> V_26 ) ;
F_10 ( V_17 , L_31 ) ;
V_73 += V_38 -> V_26 -> V_34 . V_42 ;
V_74 += V_38 -> V_8 . V_42 ;
V_75 ++ ;
}
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_32 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_32 ( void * V_83 ,
struct V_68 * V_84 , struct V_68 * V_85 )
{
struct V_25 * V_86 =
F_33 ( V_84 , struct V_25 , V_87 ) ;
struct V_25 * V_88 =
F_33 ( V_85 , struct V_25 , V_87 ) ;
return V_86 -> V_58 -> V_56 - V_88 -> V_58 -> V_56 ;
}
static int F_34 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_25 * V_26 ;
T_3 V_73 , V_74 ;
F_35 ( V_58 ) ;
int V_75 , V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_73 = V_74 = V_75 = 0 ;
F_24 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_58 == NULL )
continue;
F_6 ( & V_26 -> V_87 , & V_58 ) ;
V_73 += V_26 -> V_34 . V_42 ;
V_74 += F_36 ( V_26 ) ;
V_75 ++ ;
}
F_24 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_26 -> V_58 == NULL )
continue;
F_6 ( & V_26 -> V_87 , & V_58 ) ;
V_73 += V_26 -> V_34 . V_42 ;
V_75 ++ ;
}
F_37 ( NULL , & V_58 , F_32 ) ;
F_26 ( V_17 , L_33 ) ;
while ( ! F_38 ( & V_58 ) ) {
V_26 = F_39 ( & V_58 , F_40 ( * V_26 ) , V_87 ) ;
F_26 ( V_17 , L_30 ) ;
F_19 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
F_41 ( & V_26 -> V_87 ) ;
}
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_32 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_42 ( int V_89 , void * V_90 , void * V_18 )
{
struct V_25 * V_26 = V_90 ;
struct V_91 * V_92 = V_18 ;
struct V_37 * V_38 ;
V_92 -> V_75 ++ ;
V_92 -> V_93 += V_26 -> V_34 . V_42 ;
if ( V_26 -> V_34 . V_52 || V_26 -> V_34 . V_94 )
V_92 -> V_95 += V_26 -> V_34 . V_42 ;
if ( F_43 ( V_26 -> V_34 . V_21 ) ) {
F_24 (vma, &obj->vma_list, vma_link) {
struct V_96 * V_97 ;
if ( ! F_44 ( & V_38 -> V_8 ) )
continue;
if ( F_25 ( V_38 -> V_55 ) ) {
V_92 -> V_98 += V_26 -> V_34 . V_42 ;
continue;
}
V_97 = F_33 ( V_38 -> V_55 , struct V_96 , V_34 ) ;
if ( V_97 -> V_99 != V_92 -> V_99 )
continue;
if ( V_26 -> V_41 )
V_92 -> V_41 += V_26 -> V_34 . V_42 ;
else
V_92 -> V_100 += V_26 -> V_34 . V_42 ;
return 0 ;
}
} else {
if ( F_45 ( V_26 ) ) {
V_92 -> V_98 += V_26 -> V_34 . V_42 ;
if ( V_26 -> V_41 )
V_92 -> V_41 += V_26 -> V_34 . V_42 ;
else
V_92 -> V_100 += V_26 -> V_34 . V_42 ;
return 0 ;
}
}
if ( ! F_38 ( & V_26 -> V_101 ) )
V_92 -> V_102 += V_26 -> V_34 . V_42 ;
return 0 ;
}
static void F_46 ( struct V_16 * V_17 ,
struct V_32 * V_33 )
{
struct V_25 * V_26 ;
struct V_91 V_92 ;
struct V_35 * V_36 ;
int V_40 , V_103 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
F_21 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < F_47 ( V_36 -> V_104 . V_105 ) ; V_103 ++ ) {
F_24 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
F_42 ( 0 , V_26 , & V_92 ) ;
}
}
F_48 ( V_17 , L_34 , V_92 ) ;
}
static int F_49 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_75 , V_106 , V_107 ;
T_3 V_42 , V_108 , V_109 ;
struct V_25 * V_26 ;
struct V_71 * V_55 = & V_33 -> V_72 . V_34 ;
struct V_110 * V_111 ;
struct V_37 * V_38 ;
int V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_10 ( V_17 , L_35 ,
V_33 -> V_112 . V_113 ,
V_33 -> V_112 . V_114 ) ;
V_42 = V_75 = V_108 = V_106 = 0 ;
F_50 ( & V_33 -> V_112 . V_115 , V_101 ) ;
F_10 ( V_17 , L_36 ,
V_75 , V_106 , V_42 , V_108 ) ;
V_42 = V_75 = V_108 = V_106 = 0 ;
F_51 ( & V_55 -> V_79 , V_116 ) ;
F_10 ( V_17 , L_37 ,
V_75 , V_106 , V_42 , V_108 ) ;
V_42 = V_75 = V_108 = V_106 = 0 ;
F_51 ( & V_55 -> V_81 , V_116 ) ;
F_10 ( V_17 , L_38 ,
V_75 , V_106 , V_42 , V_108 ) ;
V_42 = V_75 = V_109 = V_107 = 0 ;
F_24 (obj, &dev_priv->mm.unbound_list, global_list) {
V_42 += V_26 -> V_34 . V_42 , ++ V_75 ;
if ( V_26 -> V_50 == V_51 )
V_109 += V_26 -> V_34 . V_42 , ++ V_107 ;
}
F_10 ( V_17 , L_39 , V_75 , V_42 ) ;
V_42 = V_75 = V_108 = V_106 = 0 ;
F_24 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_59 ) {
V_42 += F_36 ( V_26 ) ;
++ V_75 ;
}
if ( V_26 -> V_27 ) {
V_108 += F_36 ( V_26 ) ;
++ V_106 ;
}
if ( V_26 -> V_50 == V_51 ) {
V_109 += V_26 -> V_34 . V_42 ;
++ V_107 ;
}
}
F_10 ( V_17 , L_40 ,
V_107 , V_109 ) ;
F_10 ( V_17 , L_41 ,
V_106 , V_108 ) ;
F_10 ( V_17 , L_42 ,
V_75 , V_42 ) ;
F_10 ( V_17 , L_43 ,
V_33 -> V_72 . V_34 . V_93 ,
V_33 -> V_72 . V_117 - V_33 -> V_72 . V_34 . V_56 ) ;
F_29 ( V_17 , '\n' ) ;
F_46 ( V_17 , V_33 ) ;
F_52 (file, &dev->filelist, lhead) {
struct V_91 V_92 ;
struct V_118 * V_119 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_99 = V_111 -> V_120 ;
F_53 ( & V_111 -> V_121 ) ;
F_54 ( & V_111 -> V_122 , F_42 , & V_92 ) ;
F_55 ( & V_111 -> V_121 ) ;
F_56 () ;
V_119 = F_57 ( V_111 -> V_123 , V_124 ) ;
F_48 ( V_17 , V_119 ? V_119 -> V_125 : L_44 , V_92 ) ;
F_58 () ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_59 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_25 * V_26 ;
T_3 V_73 , V_74 ;
int V_75 , V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_73 = V_74 = V_75 = 0 ;
F_24 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_14 == V_126 && ! F_60 ( V_26 ) )
continue;
F_26 ( V_17 , L_30 ) ;
F_19 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
V_73 += V_26 -> V_34 . V_42 ;
V_74 += F_36 ( V_26 ) ;
V_75 ++ ;
}
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_32 ,
V_75 , V_73 , V_74 ) ;
return 0 ;
}
static int F_61 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_127 * V_128 ;
int V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_62 (dev, crtc) {
const char V_129 = F_63 ( V_128 -> V_129 ) ;
const char V_130 = F_64 ( V_128 -> V_130 ) ;
struct V_131 * V_132 ;
F_65 ( & V_21 -> V_133 ) ;
V_132 = V_128 -> V_134 ;
if ( V_132 == NULL ) {
F_10 ( V_17 , L_45 ,
V_129 , V_130 ) ;
} else {
T_4 V_135 ;
if ( F_66 ( & V_132 -> V_136 ) < V_137 ) {
F_10 ( V_17 , L_46 ,
V_129 , V_130 ) ;
} else {
F_10 ( V_17 , L_47 ,
V_129 , V_130 ) ;
}
if ( V_132 -> V_138 ) {
struct V_35 * V_36 =
F_27 ( V_132 -> V_138 ) ;
F_10 ( V_17 , L_48 ,
V_36 -> V_52 ,
F_22 ( V_132 -> V_138 ) ,
V_33 -> V_139 ,
V_36 -> V_140 ( V_36 , true ) ,
F_67 ( V_132 -> V_138 , true ) ) ;
} else
F_10 ( V_17 , L_49 ) ;
F_10 ( V_17 , L_50 ,
V_132 -> V_141 ,
V_132 -> V_142 ,
F_68 ( & V_128 -> V_34 ) ) ;
if ( V_132 -> V_143 )
F_26 ( V_17 , L_51 ) ;
else
F_26 ( V_17 , L_52 ) ;
F_10 ( V_17 , L_53 , F_66 ( & V_132 -> V_136 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 4 )
V_135 = F_69 ( F_70 ( F_71 ( V_128 -> V_130 ) ) ) ;
else
V_135 = F_70 ( F_72 ( V_128 -> V_130 ) ) ;
F_10 ( V_17 , L_54 , V_135 ) ;
if ( V_132 -> V_144 ) {
F_10 ( V_17 , L_55 , ( long ) V_132 -> V_145 ) ;
F_10 ( V_17 , L_56 , V_135 == V_132 -> V_145 ) ;
}
}
F_73 ( & V_21 -> V_133 ) ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_74 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_25 * V_26 ;
struct V_35 * V_36 ;
int V_93 = 0 ;
int V_76 , V_40 , V_103 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_21 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < F_47 ( V_36 -> V_104 . V_105 ) ; V_103 ++ ) {
int V_75 ;
V_75 = 0 ;
F_24 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link)
V_75 ++ ;
F_10 ( V_17 , L_57 ,
V_36 -> V_52 , V_103 , V_75 ) ;
F_24 (obj,
&ring->batch_pool.cache_list[j],
batch_pool_link) {
F_26 ( V_17 , L_30 ) ;
F_19 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
}
V_93 += V_75 ;
}
}
F_10 ( V_17 , L_58 , V_93 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_75 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
struct V_146 * V_147 ;
int V_76 , V_148 , V_40 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_148 = 0 ;
F_21 (ring, dev_priv, i) {
int V_75 ;
V_75 = 0 ;
F_24 (req, &ring->request_list, list)
V_75 ++ ;
if ( V_75 == 0 )
continue;
F_10 ( V_17 , L_59 , V_36 -> V_52 , V_75 ) ;
F_24 (req, &ring->request_list, list) {
struct V_118 * V_119 ;
F_56 () ;
V_119 = NULL ;
if ( V_147 -> V_123 )
V_119 = F_57 ( V_147 -> V_123 , V_124 ) ;
F_10 ( V_17 , L_60 ,
V_147 -> V_149 ,
( int ) ( V_150 - V_147 -> V_151 ) ,
V_119 ? V_119 -> V_125 : L_44 ,
V_119 ? V_119 -> V_123 : - 1 ) ;
F_58 () ;
}
V_148 ++ ;
}
F_7 ( & V_21 -> V_77 ) ;
if ( V_148 == 0 )
F_26 ( V_17 , L_61 ) ;
return 0 ;
}
static void F_76 ( struct V_16 * V_17 ,
struct V_35 * V_36 )
{
if ( V_36 -> V_140 ) {
F_10 ( V_17 , L_62 ,
V_36 -> V_52 , V_36 -> V_140 ( V_36 , false ) ) ;
}
}
static int F_77 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
int V_76 , V_40 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
F_21 (ring, dev_priv, i)
F_76 ( V_17 , V_36 ) ;
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_80 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
int V_76 , V_40 , V_129 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
if ( F_81 ( V_21 ) ) {
F_10 ( V_17 , L_63 ,
F_70 ( V_152 ) ) ;
F_10 ( V_17 , L_64 ,
F_70 ( V_153 ) ) ;
F_10 ( V_17 , L_65 ,
F_70 ( V_154 ) ) ;
F_10 ( V_17 , L_66 ,
F_70 ( V_155 ) ) ;
F_10 ( V_17 , L_67 ,
F_70 ( V_156 ) ) ;
F_82 (dev_priv, pipe)
F_10 ( V_17 , L_68 ,
F_63 ( V_129 ) ,
F_70 ( F_83 ( V_129 ) ) ) ;
F_10 ( V_17 , L_69 ,
F_70 ( V_157 ) ) ;
F_10 ( V_17 , L_70 ,
F_70 ( V_158 ) ) ;
F_10 ( V_17 , L_71 ,
F_70 ( V_159 ) ) ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
F_10 ( V_17 , L_72 ,
V_40 , F_70 ( F_84 ( V_40 ) ) ) ;
F_10 ( V_17 , L_73 ,
V_40 , F_70 ( F_85 ( V_40 ) ) ) ;
F_10 ( V_17 , L_74 ,
V_40 , F_70 ( F_86 ( V_40 ) ) ) ;
}
F_10 ( V_17 , L_75 ,
F_70 ( V_160 ) ) ;
F_10 ( V_17 , L_76 ,
F_70 ( V_161 ) ) ;
F_10 ( V_17 , L_77 ,
F_70 ( V_162 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_10 ( V_17 , L_63 ,
F_70 ( V_152 ) ) ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
F_10 ( V_17 , L_72 ,
V_40 , F_70 ( F_84 ( V_40 ) ) ) ;
F_10 ( V_17 , L_73 ,
V_40 , F_70 ( F_85 ( V_40 ) ) ) ;
F_10 ( V_17 , L_74 ,
V_40 , F_70 ( F_86 ( V_40 ) ) ) ;
}
F_82 (dev_priv, pipe) {
if ( ! F_87 ( V_33 ,
F_88 ( V_129 ) ) ) {
F_10 ( V_17 , L_78 ,
F_63 ( V_129 ) ) ;
continue;
}
F_10 ( V_17 , L_79 ,
F_63 ( V_129 ) ,
F_70 ( F_89 ( V_129 ) ) ) ;
F_10 ( V_17 , L_80 ,
F_63 ( V_129 ) ,
F_70 ( F_90 ( V_129 ) ) ) ;
F_10 ( V_17 , L_81 ,
F_63 ( V_129 ) ,
F_70 ( F_91 ( V_129 ) ) ) ;
}
F_10 ( V_17 , L_82 ,
F_70 ( V_163 ) ) ;
F_10 ( V_17 , L_83 ,
F_70 ( V_164 ) ) ;
F_10 ( V_17 , L_84 ,
F_70 ( V_165 ) ) ;
F_10 ( V_17 , L_85 ,
F_70 ( V_166 ) ) ;
F_10 ( V_17 , L_86 ,
F_70 ( V_167 ) ) ;
F_10 ( V_17 , L_87 ,
F_70 ( V_168 ) ) ;
F_10 ( V_17 , L_75 ,
F_70 ( V_160 ) ) ;
F_10 ( V_17 , L_76 ,
F_70 ( V_161 ) ) ;
F_10 ( V_17 , L_77 ,
F_70 ( V_162 ) ) ;
} else if ( F_92 ( V_21 ) ) {
F_10 ( V_17 , L_64 ,
F_70 ( V_153 ) ) ;
F_10 ( V_17 , L_65 ,
F_70 ( V_154 ) ) ;
F_10 ( V_17 , L_66 ,
F_70 ( V_155 ) ) ;
F_10 ( V_17 , L_67 ,
F_70 ( V_156 ) ) ;
F_82 (dev_priv, pipe)
F_10 ( V_17 , L_68 ,
F_63 ( V_129 ) ,
F_70 ( F_83 ( V_129 ) ) ) ;
F_10 ( V_17 , L_88 ,
F_70 ( V_169 ) ) ;
F_10 ( V_17 , L_89 ,
F_70 ( V_170 ) ) ;
F_10 ( V_17 , L_90 ,
F_70 ( V_171 ) ) ;
F_10 ( V_17 , L_91 ,
F_70 ( V_172 ) ) ;
F_10 ( V_17 , L_92 ,
F_70 ( V_173 ) ) ;
F_10 ( V_17 , L_93 ,
F_70 ( V_174 ) ) ;
F_10 ( V_17 , L_94 ,
F_70 ( V_175 ) ) ;
F_10 ( V_17 , L_69 ,
F_70 ( V_157 ) ) ;
F_10 ( V_17 , L_70 ,
F_70 ( V_158 ) ) ;
F_10 ( V_17 , L_71 ,
F_70 ( V_159 ) ) ;
} else if ( ! F_93 ( V_21 ) ) {
F_10 ( V_17 , L_95 ,
F_70 ( V_176 ) ) ;
F_10 ( V_17 , L_96 ,
F_70 ( V_177 ) ) ;
F_10 ( V_17 , L_97 ,
F_70 ( V_178 ) ) ;
F_82 (dev_priv, pipe)
F_10 ( V_17 , L_98 ,
F_63 ( V_129 ) ,
F_70 ( F_83 ( V_129 ) ) ) ;
} else {
F_10 ( V_17 , L_99 ,
F_70 ( V_179 ) ) ;
F_10 ( V_17 , L_100 ,
F_70 ( V_180 ) ) ;
F_10 ( V_17 , L_101 ,
F_70 ( V_181 ) ) ;
F_10 ( V_17 , L_102 ,
F_70 ( V_182 ) ) ;
F_10 ( V_17 , L_103 ,
F_70 ( V_183 ) ) ;
F_10 ( V_17 , L_104 ,
F_70 ( V_184 ) ) ;
F_10 ( V_17 , L_105 ,
F_70 ( V_170 ) ) ;
F_10 ( V_17 , L_106 ,
F_70 ( V_171 ) ) ;
F_10 ( V_17 , L_107 ,
F_70 ( V_172 ) ) ;
}
F_21 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_108 ,
V_36 -> V_52 , F_94 ( V_36 ) ) ;
}
F_76 ( V_17 , V_36 ) ;
}
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_95 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_40 , V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_10 ( V_17 , L_109 , V_33 -> V_185 ) ;
F_10 ( V_17 , L_110 , V_33 -> V_186 ) ;
for ( V_40 = 0 ; V_40 < V_33 -> V_186 ; V_40 ++ ) {
struct V_25 * V_26 = V_33 -> V_187 [ V_40 ] . V_26 ;
F_10 ( V_17 , L_111 ,
V_40 , V_33 -> V_187 [ V_40 ] . V_39 ) ;
if ( V_26 == NULL )
F_26 ( V_17 , L_112 ) ;
else
F_19 ( V_17 , V_26 ) ;
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_96 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
const T_4 * V_188 ;
int V_40 ;
V_36 = & V_33 -> V_36 [ ( T_2 ) V_8 -> V_12 -> V_18 ] ;
V_188 = V_36 -> V_189 . V_190 ;
if ( V_188 == NULL )
return 0 ;
for ( V_40 = 0 ; V_40 < 4096 / sizeof( T_4 ) / 4 ; V_40 += 4 ) {
F_10 ( V_17 , L_113 ,
V_40 * 4 ,
V_188 [ V_40 ] , V_188 [ V_40 + 1 ] , V_188 [ V_40 + 2 ] , V_188 [ V_40 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_97 ( struct V_111 * V_191 ,
const char T_6 * V_192 ,
T_3 V_193 ,
T_7 * V_194 )
{
struct V_195 * V_196 = V_191 -> V_197 ;
struct V_20 * V_21 = V_196 -> V_21 ;
int V_76 ;
F_98 ( L_114 ) ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_99 ( V_21 ) ;
F_7 ( & V_21 -> V_77 ) ;
return V_193 ;
}
static int F_100 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
struct V_195 * V_196 ;
V_196 = F_101 ( sizeof( * V_196 ) , V_9 ) ;
if ( ! V_196 )
return - V_10 ;
V_196 -> V_21 = V_21 ;
F_102 ( V_21 , V_196 ) ;
V_111 -> V_197 = V_196 ;
return 0 ;
}
static int F_103 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_195 * V_196 = V_111 -> V_197 ;
F_104 ( V_196 ) ;
F_105 ( V_196 ) ;
return 0 ;
}
static T_5 F_106 ( struct V_111 * V_111 , char T_6 * V_200 ,
T_3 V_75 , T_7 * V_201 )
{
struct V_195 * V_196 = V_111 -> V_197 ;
struct V_202 V_203 ;
T_7 V_204 = 0 ;
T_5 V_205 = 0 ;
int V_76 ;
V_76 = F_107 ( & V_203 , F_20 ( V_196 -> V_21 ) , V_75 , * V_201 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_108 ( & V_203 , V_196 ) ;
if ( V_76 )
goto V_206;
V_205 = F_109 ( V_200 , V_75 , & V_204 ,
V_203 . V_207 ,
V_203 . V_208 ) ;
if ( V_205 < 0 )
V_76 = V_205 ;
else
* V_201 = V_203 . V_56 + V_205 ;
V_206:
F_110 ( & V_203 ) ;
return V_76 ? : V_205 ;
}
static int
F_111 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
* V_209 = V_33 -> V_139 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_112 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
int V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_113 ( V_21 , V_209 ) ;
F_7 ( & V_21 -> V_77 ) ;
return V_76 ;
}
static int F_114 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 = 0 ;
F_78 ( V_33 ) ;
F_115 ( & V_33 -> V_211 . V_212 ) ;
if ( F_116 ( V_21 ) ) {
T_9 V_213 = F_117 ( V_214 ) ;
T_9 V_215 = F_117 ( V_216 ) ;
F_10 ( V_17 , L_115 , ( V_213 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_116 , V_213 & 0x3f ) ;
F_10 ( V_17 , L_117 , ( V_215 & V_217 ) >>
V_218 ) ;
F_10 ( V_17 , L_118 ,
( V_215 & V_219 ) >> V_220 ) ;
} else if ( F_118 ( V_21 ) || ( F_119 ( V_21 ) && ! F_92 ( V_21 ) ) ||
F_120 ( V_21 ) || F_121 ( V_21 ) ) {
T_4 V_221 = F_70 ( V_222 ) ;
T_4 V_223 = F_70 ( V_224 ) ;
T_4 V_225 = F_70 ( V_226 ) ;
T_4 V_227 , V_228 , V_229 ;
T_4 V_230 , V_231 , V_232 ;
T_4 V_233 , V_234 , V_235 ;
T_4 V_236 , V_237 , V_238 ;
T_4 V_239 , V_240 , V_241 , V_242 , V_243 ;
int V_244 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
goto V_206;
F_122 ( V_33 , V_245 ) ;
V_232 = F_70 ( V_246 ) ;
if ( F_121 ( V_21 ) )
V_232 >>= 23 ;
else {
V_232 &= ~ V_247 ;
if ( F_123 ( V_21 ) || F_120 ( V_21 ) )
V_232 >>= 24 ;
else
V_232 >>= 25 ;
}
V_232 = F_124 ( V_33 , V_232 ) ;
V_227 = F_70 ( V_248 ) ;
V_228 = F_70 ( V_249 ) ;
V_229 = F_70 ( V_250 ) ;
V_230 = F_70 ( V_251 ) ;
V_233 = F_70 ( V_252 ) ;
V_234 = F_70 ( V_253 ) ;
V_235 = F_70 ( V_254 ) ;
V_236 = F_70 ( V_255 ) ;
V_237 = F_70 ( V_256 ) ;
V_238 = F_70 ( V_257 ) ;
if ( F_121 ( V_21 ) )
V_231 = ( V_230 & V_258 ) >> V_259 ;
else if ( F_123 ( V_21 ) || F_120 ( V_21 ) )
V_231 = ( V_230 & V_260 ) >> V_261 ;
else
V_231 = ( V_230 & V_262 ) >> V_263 ;
V_231 = F_124 ( V_33 , V_231 ) ;
F_125 ( V_33 , V_245 ) ;
F_7 ( & V_21 -> V_77 ) ;
if ( F_118 ( V_21 ) || F_119 ( V_21 ) ) {
V_239 = F_70 ( V_173 ) ;
V_240 = F_70 ( V_175 ) ;
V_241 = F_70 ( V_264 ) ;
V_242 = F_70 ( V_174 ) ;
V_243 = F_70 ( V_265 ) ;
} else {
V_239 = F_70 ( F_86 ( 2 ) ) ;
V_240 = F_70 ( F_84 ( 2 ) ) ;
V_241 = F_70 ( F_126 ( 2 ) ) ;
V_242 = F_70 ( F_85 ( 2 ) ) ;
V_243 = F_70 ( V_265 ) ;
}
F_10 ( V_17 , L_119 ,
V_239 , V_240 , V_241 , V_242 , V_243 ) ;
F_10 ( V_17 , L_120 , V_221 ) ;
F_10 ( V_17 , L_121 ,
( V_221 & ( F_121 ( V_21 ) ? 0x1ff00 : 0xff00 ) ) >> 8 ) ;
F_10 ( V_17 , L_122 ,
V_221 & 0xff ) ;
F_10 ( V_17 , L_123 ,
V_223 & 0xff ) ;
F_10 ( V_17 , L_124 , V_230 ) ;
F_10 ( V_17 , L_125 , V_227 ) ;
F_10 ( V_17 , L_126 , V_228 ) ;
F_10 ( V_17 , L_127 , V_229 ) ;
F_10 ( V_17 , L_128 , V_232 ) ;
F_10 ( V_17 , L_129 , V_231 ) ;
F_10 ( V_17 , L_130 , V_233 &
V_266 ) ;
F_10 ( V_17 , L_131 , V_234 &
V_267 ) ;
F_10 ( V_17 , L_132 , V_235 &
V_267 ) ;
F_10 ( V_17 , L_133 ,
V_33 -> V_211 . V_268 ) ;
F_10 ( V_17 , L_134 , V_236 &
V_269 ) ;
F_10 ( V_17 , L_135 , V_237 &
V_267 ) ;
F_10 ( V_17 , L_136 , V_238 &
V_267 ) ;
F_10 ( V_17 , L_137 ,
V_33 -> V_211 . V_270 ) ;
V_244 = ( V_225 & 0xff0000 ) >> 16 ;
V_244 *= ( F_127 ( V_21 ) ? V_271 : 1 ) ;
F_10 ( V_17 , L_138 ,
F_124 ( V_33 , V_244 ) ) ;
V_244 = ( V_225 & 0xff00 ) >> 8 ;
V_244 *= ( F_127 ( V_21 ) ? V_271 : 1 ) ;
F_10 ( V_17 , L_139 ,
F_124 ( V_33 , V_244 ) ) ;
V_244 = V_225 & 0xff ;
V_244 *= ( F_127 ( V_21 ) ? V_271 : 1 ) ;
F_10 ( V_17 , L_140 ,
F_124 ( V_33 , V_244 ) ) ;
F_10 ( V_17 , L_141 ,
F_124 ( V_33 , V_33 -> V_211 . V_244 ) ) ;
F_10 ( V_17 , L_142 ,
F_124 ( V_33 , V_33 -> V_211 . V_272 ) ) ;
F_10 ( V_17 , L_143 , V_231 ) ;
F_10 ( V_17 , L_144 ,
F_124 ( V_33 , V_33 -> V_211 . V_273 ) ) ;
F_10 ( V_17 , L_145 ,
F_124 ( V_33 , V_33 -> V_211 . V_274 ) ) ;
F_10 ( V_17 , L_146 ,
F_124 ( V_33 , V_33 -> V_211 . V_244 ) ) ;
F_10 ( V_17 ,
L_147 ,
F_124 ( V_33 , V_33 -> V_211 . V_275 ) ) ;
} else if ( F_92 ( V_21 ) ) {
T_4 V_276 ;
F_5 ( & V_33 -> V_211 . V_277 ) ;
V_276 = F_128 ( V_33 , V_278 ) ;
F_10 ( V_17 , L_148 , V_276 ) ;
F_10 ( V_17 , L_149 , V_33 -> V_279 ) ;
F_10 ( V_17 , L_150 ,
F_124 ( V_33 , ( V_276 >> 8 ) & 0xff ) ) ;
F_10 ( V_17 , L_151 ,
F_124 ( V_33 , V_33 -> V_211 . V_272 ) ) ;
F_10 ( V_17 , L_152 ,
F_124 ( V_33 , V_33 -> V_211 . V_244 ) ) ;
F_10 ( V_17 , L_153 ,
F_124 ( V_33 , V_33 -> V_211 . V_274 ) ) ;
F_10 ( V_17 , L_154 ,
F_124 ( V_33 , V_33 -> V_211 . V_273 ) ) ;
F_10 ( V_17 ,
L_147 ,
F_124 ( V_33 , V_33 -> V_211 . V_275 ) ) ;
F_7 ( & V_33 -> V_211 . V_277 ) ;
} else {
F_26 ( V_17 , L_155 ) ;
}
V_206:
F_79 ( V_33 ) ;
return V_76 ;
}
static int F_129 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
T_8 V_280 [ V_281 ] ;
T_4 V_149 [ V_281 ] ;
int V_40 ;
if ( ! V_282 . V_283 ) {
F_10 ( V_17 , L_156 ) ;
return 0 ;
}
F_78 ( V_33 ) ;
F_21 (ring, dev_priv, i) {
V_149 [ V_40 ] = V_36 -> V_140 ( V_36 , false ) ;
V_280 [ V_40 ] = F_130 ( V_36 ) ;
}
F_79 ( V_33 ) ;
if ( F_131 ( & V_33 -> V_284 . V_285 ) ) {
F_10 ( V_17 , L_157 ,
F_132 ( V_33 -> V_284 . V_285 . V_286 . V_287 -
V_150 ) ) ;
} else
F_10 ( V_17 , L_158 ) ;
F_21 (ring, dev_priv, i) {
F_10 ( V_17 , L_159 , V_36 -> V_52 ) ;
F_10 ( V_17 , L_160 ,
V_36 -> V_288 . V_149 , V_149 [ V_40 ] ) ;
F_10 ( V_17 , L_161 ,
( long long ) V_36 -> V_288 . V_280 ,
( long long ) V_280 [ V_40 ] ) ;
F_10 ( V_17 , L_162 ,
( long long ) V_36 -> V_288 . V_289 ) ;
F_10 ( V_17 , L_163 , V_36 -> V_288 . V_290 ) ;
F_10 ( V_17 , L_164 , V_36 -> V_288 . V_291 ) ;
}
return 0 ;
}
static int F_133 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_292 , V_293 ;
T_9 V_294 ;
int V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
V_292 = F_70 ( V_295 ) ;
V_293 = F_70 ( V_296 ) ;
V_294 = F_117 ( V_297 ) ;
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_165 , ( V_292 & V_298 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_166 ,
( V_292 & V_299 ) >>
V_300 ) ;
F_10 ( V_17 , L_167 ,
V_292 & V_301 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_168 ,
V_292 & V_302 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_169 ,
V_292 & V_303 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_170 ,
( V_292 & V_304 ) >> V_305 ) ;
F_10 ( V_17 , L_171 ,
( V_292 & V_306 ) >> V_307 ) ;
F_10 ( V_17 , L_172 , ( V_292 & V_308 ) ) ;
F_10 ( V_17 , L_173 , ( V_294 & 0x3f ) ) ;
F_10 ( V_17 , L_174 , ( ( V_294 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_175 ,
( V_293 & V_309 ) ? L_2 : L_1 ) ;
F_26 ( V_17 , L_176 ) ;
switch ( V_293 & V_310 ) {
case V_311 :
F_26 ( V_17 , L_177 ) ;
break;
case V_312 :
F_26 ( V_17 , L_178 ) ;
break;
case V_313 :
F_26 ( V_17 , L_179 ) ;
break;
case V_314 :
F_26 ( V_17 , L_180 ) ;
break;
case V_315 :
F_26 ( V_17 , L_181 ) ;
break;
case V_316 :
F_26 ( V_17 , L_182 ) ;
break;
default:
F_26 ( V_17 , L_183 ) ;
break;
}
return 0 ;
}
static int F_134 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_317 * V_318 ;
int V_40 ;
F_65 ( & V_33 -> V_319 . V_320 ) ;
F_135 (fw_domain, dev_priv, i) {
F_10 ( V_17 , L_184 ,
F_136 ( V_40 ) ,
V_318 -> V_321 ) ;
}
F_73 ( & V_33 -> V_319 . V_320 ) ;
return 0 ;
}
static int F_137 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_322 , V_323 , V_324 ;
F_78 ( V_33 ) ;
V_324 = F_70 ( V_325 ) ;
V_322 = F_70 ( V_248 ) ;
V_323 = F_70 ( V_326 ) ;
F_79 ( V_33 ) ;
F_10 ( V_17 , L_185 ,
F_1 ( V_322 & V_327 ) ) ;
F_10 ( V_17 , L_186 ,
F_1 ( V_322 & V_328 ) ) ;
F_10 ( V_17 , L_167 ,
F_1 ( V_322 & V_328 ) ) ;
F_10 ( V_17 , L_168 ,
F_1 ( ( V_322 & V_329 ) ==
V_330 ) ) ;
F_10 ( V_17 , L_187 ,
F_1 ( V_323 & ( V_331 |
F_138 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_188 ,
( V_324 & V_332 ) ? L_189 : L_190 ) ;
F_10 ( V_17 , L_191 ,
( V_324 & V_333 ) ? L_189 : L_190 ) ;
F_10 ( V_17 , L_192 ,
F_70 ( V_334 ) ) ;
F_10 ( V_17 , L_193 ,
F_70 ( V_335 ) ) ;
return F_134 ( V_17 , NULL ) ;
}
static int F_139 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_322 , V_336 , V_323 , V_337 = 0 ;
unsigned V_338 ;
int V_75 = 0 , V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
F_65 ( & V_33 -> V_319 . V_320 ) ;
V_338 = V_33 -> V_319 . V_318 [ V_339 ] . V_321 ;
F_73 ( & V_33 -> V_319 . V_320 ) ;
if ( V_338 ) {
F_26 ( V_17 , L_194
L_195 ) ;
} else {
while ( V_75 ++ < 50 && ( F_140 ( V_340 ) & 1 ) )
F_141 ( 10 ) ;
F_10 ( V_17 , L_196 , F_1 ( V_75 < 51 ) ) ;
}
V_336 = F_142 ( V_33 -> V_341 + V_342 ) ;
F_143 ( false , V_342 , V_336 , 4 , true ) ;
V_322 = F_70 ( V_248 ) ;
V_323 = F_70 ( V_326 ) ;
F_7 ( & V_21 -> V_77 ) ;
F_5 ( & V_33 -> V_211 . V_277 ) ;
F_144 ( V_33 , V_343 , & V_337 ) ;
F_7 ( & V_33 -> V_211 . V_277 ) ;
F_79 ( V_33 ) ;
F_10 ( V_17 , L_185 ,
F_1 ( V_322 & V_327 ) ) ;
F_10 ( V_17 , L_167 ,
F_1 ( V_322 & V_328 ) ) ;
F_10 ( V_17 , L_168 ,
F_1 ( ( V_322 & V_329 ) ==
V_330 ) ) ;
F_10 ( V_17 , L_197 ,
F_1 ( V_323 & V_344 ) ) ;
F_10 ( V_17 , L_187 ,
F_1 ( V_323 & V_345 ) ) ;
F_10 ( V_17 , L_198 ,
F_1 ( V_323 & V_346 ) ) ;
F_10 ( V_17 , L_199 ,
F_1 ( V_323 & V_347 ) ) ;
F_26 ( V_17 , L_200 ) ;
switch ( V_336 & V_348 ) {
case V_349 :
if ( V_336 & V_350 )
F_26 ( V_17 , L_201 ) ;
else
F_26 ( V_17 , L_177 ) ;
break;
case V_351 :
F_26 ( V_17 , L_202 ) ;
break;
case V_352 :
F_26 ( V_17 , L_203 ) ;
break;
case V_353 :
F_26 ( V_17 , L_204 ) ;
break;
default:
F_26 ( V_17 , L_205 ) ;
break;
}
F_10 ( V_17 , L_206 ,
F_1 ( V_336 & V_350 ) ) ;
F_10 ( V_17 , L_207 ,
F_70 ( V_354 ) ) ;
F_10 ( V_17 , L_208 ,
F_70 ( V_355 ) ) ;
F_10 ( V_17 , L_209 ,
F_70 ( V_356 ) ) ;
F_10 ( V_17 , L_210 ,
F_70 ( V_357 ) ) ;
F_10 ( V_17 , L_211 ,
F_145 ( ( ( V_337 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_212 ,
F_145 ( ( ( V_337 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_213 ,
F_145 ( ( ( V_337 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_146 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_92 ( V_21 ) )
return F_137 ( V_17 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
return F_139 ( V_17 ) ;
else
return F_133 ( V_17 ) ;
}
static int F_147 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
if ( ! F_148 ( V_21 ) ) {
F_26 ( V_17 , L_214 ) ;
return 0 ;
}
F_78 ( V_33 ) ;
if ( F_149 ( V_21 ) ) {
F_26 ( V_17 , L_215 ) ;
} else {
F_26 ( V_17 , L_216 ) ;
switch ( V_33 -> V_358 . V_359 ) {
case V_360 :
F_26 ( V_17 , L_217 ) ;
break;
case V_361 :
F_26 ( V_17 , L_218 ) ;
break;
case V_362 :
F_26 ( V_17 , L_219 ) ;
break;
case V_363 :
F_26 ( V_17 , L_220 ) ;
break;
case V_364 :
F_26 ( V_17 , L_221 ) ;
break;
case V_365 :
F_26 ( V_17 , L_222 ) ;
break;
case V_366 :
F_26 ( V_17 , L_223 ) ;
break;
case V_367 :
F_26 ( V_17 , L_224 ) ;
break;
case V_368 :
F_26 ( V_17 , L_225 ) ;
break;
case V_369 :
F_26 ( V_17 , L_226 ) ;
break;
case V_370 :
F_26 ( V_17 , L_227 ) ;
break;
default:
F_26 ( V_17 , L_228 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_79 ( V_33 ) ;
return 0 ;
}
static int F_150 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_148 ( V_21 ) )
return - V_371 ;
F_151 ( V_21 ) ;
* V_209 = V_33 -> V_358 . V_372 ;
F_152 ( V_21 ) ;
return 0 ;
}
static int F_153 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_373 ;
if ( F_9 ( V_21 ) -> V_24 < 7 || ! F_148 ( V_21 ) )
return - V_371 ;
F_151 ( V_21 ) ;
V_373 = F_70 ( V_374 ) ;
V_33 -> V_358 . V_372 = V_209 ;
F_154 ( V_374 , V_209 ?
( V_373 | V_375 ) :
( V_373 & ~ V_375 ) ) ;
F_152 ( V_21 ) ;
return 0 ;
}
static int F_155 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
if ( ! F_156 ( V_21 ) ) {
F_26 ( V_17 , L_229 ) ;
return 0 ;
}
F_78 ( V_33 ) ;
F_10 ( V_17 , L_230 ,
F_1 ( V_282 . V_376 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_26 ( V_17 , L_231 ) ;
} else {
if ( F_70 ( V_377 ) & V_378 )
F_26 ( V_17 , L_232 ) ;
else
F_26 ( V_17 , L_233 ) ;
}
F_79 ( V_33 ) ;
return 0 ;
}
static int F_157 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
bool V_379 = false ;
F_78 ( V_33 ) ;
if ( F_93 ( V_21 ) )
V_379 = F_70 ( V_380 ) & V_381 ;
else if ( F_158 ( V_21 ) || F_159 ( V_21 ) ||
F_160 ( V_21 ) || F_161 ( V_21 ) )
V_379 = F_70 ( V_382 ) & V_383 ;
else if ( F_162 ( V_21 ) )
V_379 = F_70 ( V_384 ) & V_385 ;
else if ( F_163 ( V_21 ) )
V_379 = F_70 ( V_386 ) & V_387 ;
else if ( F_92 ( V_21 ) )
V_379 = F_70 ( V_388 ) & V_389 ;
F_79 ( V_33 ) ;
F_10 ( V_17 , L_234 ,
V_379 ? L_235 : L_236 ) ;
return 0 ;
}
static int F_164 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
unsigned long V_390 , V_391 , V_392 ;
int V_76 ;
if ( ! F_116 ( V_21 ) )
return - V_371 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_390 = F_165 ( V_33 ) ;
V_391 = F_166 ( V_33 ) ;
V_392 = F_167 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
F_10 ( V_17 , L_237 , V_390 ) ;
F_10 ( V_17 , L_238 , V_391 ) ;
F_10 ( V_17 , L_239 , V_392 ) ;
F_10 ( V_17 , L_240 , V_391 + V_392 ) ;
return 0 ;
}
static int F_168 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 = 0 ;
int V_393 , V_394 ;
if ( ! ( F_118 ( V_21 ) || F_119 ( V_21 ) ) ) {
F_26 ( V_17 , L_241 ) ;
return 0 ;
}
F_78 ( V_33 ) ;
F_115 ( & V_33 -> V_211 . V_212 ) ;
V_76 = F_31 ( & V_33 -> V_211 . V_277 ) ;
if ( V_76 )
goto V_206;
F_26 ( V_17 , L_242 ) ;
for ( V_393 = V_33 -> V_211 . V_395 ;
V_393 <= V_33 -> V_211 . V_396 ;
V_393 ++ ) {
V_394 = V_393 ;
F_144 ( V_33 ,
V_397 ,
& V_394 ) ;
F_10 ( V_17 , L_243 ,
F_124 ( V_33 , V_393 ) ,
( ( V_394 >> 0 ) & 0xff ) * 100 ,
( ( V_394 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_33 -> V_211 . V_277 ) ;
V_206:
F_79 ( V_33 ) ;
return V_76 ;
}
static int F_169 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_398 * V_399 = & V_33 -> V_399 ;
void * V_18 = F_3 ( V_400 , V_9 ) ;
int V_76 ;
if ( V_18 == NULL )
return - V_10 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
goto V_206;
if ( V_399 -> V_401 ) {
F_170 ( V_18 , V_399 -> V_401 , V_400 ) ;
F_171 ( V_17 , V_18 , V_400 ) ;
}
F_7 ( & V_21 -> V_77 ) ;
V_206:
F_105 ( V_18 ) ;
return 0 ;
}
static int F_172 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_402 * V_403 = NULL ;
struct V_404 * V_405 ;
#ifdef F_173
struct V_32 * V_33 = V_21 -> V_70 ;
V_403 = V_33 -> V_406 ;
V_405 = F_174 ( V_403 -> V_407 . V_405 ) ;
F_10 ( V_17 , L_244 ,
V_405 -> V_34 . V_408 ,
V_405 -> V_34 . V_409 ,
V_405 -> V_34 . V_410 ,
V_405 -> V_34 . V_411 ,
V_405 -> V_34 . V_412 [ 0 ] ,
F_66 ( & V_405 -> V_34 . V_413 . V_413 ) ) ;
F_19 ( V_17 , V_405 -> V_26 ) ;
F_29 ( V_17 , '\n' ) ;
#endif
F_5 ( & V_21 -> V_414 . V_415 ) ;
F_24 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_403 && & V_405 -> V_34 == V_403 -> V_407 . V_405 )
continue;
F_10 ( V_17 , L_245 ,
V_405 -> V_34 . V_408 ,
V_405 -> V_34 . V_409 ,
V_405 -> V_34 . V_410 ,
V_405 -> V_34 . V_411 ,
V_405 -> V_34 . V_412 [ 0 ] ,
F_66 ( & V_405 -> V_34 . V_413 . V_413 ) ) ;
F_19 ( V_17 , V_405 -> V_26 ) ;
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_414 . V_415 ) ;
return 0 ;
}
static void F_175 ( struct V_16 * V_17 ,
struct V_416 * V_417 )
{
F_10 ( V_17 , L_246 ,
V_417 -> V_418 , V_417 -> V_69 , V_417 -> V_419 ,
V_417 -> V_420 ) ;
}
static int F_176 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
struct V_63 * V_64 ;
int V_76 , V_40 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_24 (ctx, &dev_priv->context_list, link) {
if ( ! V_282 . V_421 &&
V_64 -> V_65 . V_422 == NULL )
continue;
F_26 ( V_17 , L_247 ) ;
F_28 ( V_17 , V_64 ) ;
F_21 (ring, dev_priv, i) {
if ( V_36 -> V_423 == V_64 )
F_10 ( V_17 , L_248 ,
V_36 -> V_52 ) ;
}
if ( V_282 . V_421 ) {
F_29 ( V_17 , '\n' ) ;
F_21 (ring, dev_priv, i) {
struct V_25 * V_424 =
V_64 -> V_425 [ V_40 ] . V_426 ;
struct V_416 * V_417 =
V_64 -> V_425 [ V_40 ] . V_417 ;
F_10 ( V_17 , L_249 , V_36 -> V_52 ) ;
if ( V_424 )
F_19 ( V_17 , V_424 ) ;
if ( V_417 )
F_175 ( V_17 , V_417 ) ;
F_29 ( V_17 , '\n' ) ;
}
} else {
F_19 ( V_17 , V_64 -> V_65 . V_422 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static void F_177 ( struct V_16 * V_17 ,
struct V_35 * V_36 ,
struct V_25 * V_424 )
{
struct V_427 * V_427 ;
T_10 * V_428 ;
int V_103 ;
unsigned long V_429 = 0 ;
if ( V_424 == NULL ) {
F_10 ( V_17 , L_250 ,
V_36 -> V_52 ) ;
return;
}
F_10 ( V_17 , L_251 , V_36 -> V_52 ,
F_178 ( V_424 ) ) ;
if ( ! F_45 ( V_424 ) )
F_26 ( V_17 , L_252 ) ;
else
V_429 = F_179 ( V_424 ) ;
if ( F_180 ( V_424 ) ) {
F_26 ( V_17 , L_253 ) ;
return;
}
V_427 = F_181 ( V_424 , 1 ) ;
if ( ! F_182 ( V_427 == NULL ) ) {
V_428 = F_183 ( V_427 ) ;
for ( V_103 = 0 ; V_103 < 0x600 / sizeof( T_4 ) / 4 ; V_103 += 4 ) {
F_10 ( V_17 , L_254 ,
V_429 + 4096 + ( V_103 * 4 ) ,
V_428 [ V_103 ] , V_428 [ V_103 + 1 ] ,
V_428 [ V_103 + 2 ] , V_428 [ V_103 + 3 ] ) ;
}
F_184 ( V_428 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
static int F_185 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
struct V_63 * V_64 ;
int V_76 , V_40 ;
if ( ! V_282 . V_421 ) {
F_10 ( V_17 , L_255 ) ;
return 0 ;
}
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_24 (ctx, &dev_priv->context_list, link) {
F_21 (ring, dev_priv, i) {
if ( V_36 -> V_423 != V_64 )
F_177 ( V_17 , V_36 ,
V_64 -> V_425 [ V_40 ] . V_426 ) ;
}
}
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_186 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
T_4 V_430 ;
T_11 V_431 ;
T_11 V_432 ;
T_4 V_433 ;
T_4 V_434 ;
struct V_68 * V_435 ;
int V_436 , V_40 ;
int V_76 ;
if ( ! V_282 . V_421 ) {
F_26 ( V_17 , L_255 ) ;
return 0 ;
}
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
F_21 (ring, dev_priv, ring_id) {
struct V_146 * V_437 = NULL ;
int V_75 = 0 ;
unsigned long V_438 ;
F_10 ( V_17 , L_256 , V_36 -> V_52 ) ;
V_433 = F_70 ( F_187 ( V_36 ) ) ;
V_434 = F_70 ( F_187 ( V_36 ) + 4 ) ;
F_10 ( V_17 , L_257 ,
V_433 , V_434 ) ;
V_430 = F_70 ( F_188 ( V_36 ) ) ;
F_10 ( V_17 , L_258 , V_430 ) ;
V_431 = V_36 -> V_439 ;
V_432 = V_430 & 0x07 ;
if ( V_431 > V_432 )
V_432 += 6 ;
F_10 ( V_17 , L_259 ,
V_431 , V_432 ) ;
for ( V_40 = 0 ; V_40 < 6 ; V_40 ++ ) {
V_433 = F_70 ( F_189 ( V_36 ) + 8 * V_40 ) ;
V_434 = F_70 ( F_189 ( V_36 ) + 8 * V_40 + 4 ) ;
F_10 ( V_17 , L_260 ,
V_40 , V_433 , V_434 ) ;
}
F_190 ( & V_36 -> V_440 , V_438 ) ;
F_191 (cursor, &ring->execlist_queue)
V_75 ++ ;
V_437 = F_192 ( & V_36 -> V_441 ,
struct V_146 , V_442 ) ;
F_193 ( & V_36 -> V_440 , V_438 ) ;
F_10 ( V_17 , L_261 , V_75 ) ;
if ( V_437 ) {
struct V_25 * V_424 ;
V_424 = V_437 -> V_64 -> V_425 [ V_436 ] . V_426 ;
F_10 ( V_17 , L_262 ,
F_178 ( V_424 ) ) ;
F_10 ( V_17 , L_263 ,
V_437 -> V_419 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static const char * F_194 ( unsigned V_443 )
{
switch ( V_443 ) {
case V_444 :
return L_264 ;
case V_445 :
return L_265 ;
case V_446 :
return L_266 ;
case V_447 :
return L_267 ;
case V_448 :
return L_268 ;
case V_449 :
return L_269 ;
case V_450 :
return L_270 ;
case V_451 :
return L_271 ;
}
return L_272 ;
}
static int F_195 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
F_10 ( V_17 , L_273 ,
F_194 ( V_33 -> V_112 . V_452 ) ) ;
F_10 ( V_17 , L_274 ,
F_194 ( V_33 -> V_112 . V_453 ) ) ;
if ( F_196 ( V_21 ) || F_197 ( V_21 ) ) {
F_10 ( V_17 , L_275 ,
F_70 ( V_454 ) ) ;
F_10 ( V_17 , L_276 ,
F_70 ( V_455 ) ) ;
F_10 ( V_17 , L_277 ,
F_117 ( V_456 ) ) ;
F_10 ( V_17 , L_278 ,
F_117 ( V_457 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_279 ,
F_70 ( V_458 ) ) ;
F_10 ( V_17 , L_280 ,
F_70 ( V_459 ) ) ;
F_10 ( V_17 , L_281 ,
F_70 ( V_460 ) ) ;
F_10 ( V_17 , L_282 ,
F_70 ( V_461 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_10 ( V_17 , L_283 ,
F_70 ( V_462 ) ) ;
else
F_10 ( V_17 , L_284 ,
F_70 ( V_463 ) ) ;
F_10 ( V_17 , L_285 ,
F_70 ( V_464 ) ) ;
}
if ( V_33 -> V_465 & V_466 )
F_26 ( V_17 , L_286 ) ;
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_198 ( int V_89 , void * V_90 , void * V_18 )
{
struct V_63 * V_64 = V_90 ;
struct V_16 * V_17 = V_18 ;
struct V_96 * V_97 = V_64 -> V_97 ;
if ( ! V_97 ) {
F_10 ( V_17 , L_287 ,
V_64 -> V_467 ) ;
return 0 ;
}
if ( F_199 ( V_64 ) )
F_26 ( V_17 , L_288 ) ;
else
F_10 ( V_17 , L_289 , V_64 -> V_467 ) ;
V_97 -> V_468 ( V_97 , V_17 ) ;
return 0 ;
}
static void F_200 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
struct V_96 * V_97 = V_33 -> V_112 . V_469 ;
int V_210 , V_40 ;
if ( ! V_97 )
return;
F_21 (ring, dev_priv, unused) {
F_10 ( V_17 , L_256 , V_36 -> V_52 ) ;
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
T_4 V_470 = 0x270 + V_40 * 8 ;
T_8 V_471 = F_70 ( V_36 -> V_472 + V_470 + 4 ) ;
V_471 <<= 32 ;
V_471 |= F_70 ( V_36 -> V_472 + V_470 ) ;
F_10 ( V_17 , L_290 , V_40 , V_471 ) ;
}
}
}
static void F_201 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
struct V_110 * V_111 ;
int V_40 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_291 , F_70 ( V_473 ) ) ;
F_21 (ring, dev_priv, i) {
F_10 ( V_17 , L_256 , V_36 -> V_52 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_291 , F_70 ( F_202 ( V_36 ) ) ) ;
F_10 ( V_17 , L_292 , F_70 ( F_203 ( V_36 ) ) ) ;
F_10 ( V_17 , L_293 , F_70 ( F_204 ( V_36 ) ) ) ;
F_10 ( V_17 , L_294 , F_70 ( F_205 ( V_36 ) ) ) ;
}
if ( V_33 -> V_112 . V_469 ) {
struct V_96 * V_97 = V_33 -> V_112 . V_469 ;
F_26 ( V_17 , L_295 ) ;
F_10 ( V_17 , L_296 , V_97 -> V_474 . V_475 ) ;
V_97 -> V_468 ( V_97 , V_17 ) ;
}
F_52 (file, &dev->filelist, lhead) {
struct V_476 * V_99 = V_111 -> V_120 ;
F_10 ( V_17 , L_297 ,
F_206 ( V_111 -> V_123 , V_124 ) -> V_125 ) ;
F_54 ( & V_99 -> V_477 , F_198 , V_17 ) ;
}
F_10 ( V_17 , L_298 , F_70 ( V_478 ) ) ;
}
static int F_207 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_200 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_201 ( V_17 , V_21 ) ;
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_208 ( struct V_32 * V_282 )
{
struct V_35 * V_36 ;
int V_75 = 0 ;
int V_40 ;
F_21 (ring, i915, i)
V_75 += V_36 -> V_479 ;
return V_75 ;
}
static int F_209 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_110 * V_111 ;
F_10 ( V_17 , L_299 , V_33 -> V_211 . V_480 ) ;
F_10 ( V_17 , L_300 , V_33 -> V_112 . V_481 ) ;
F_10 ( V_17 , L_301 , F_208 ( V_33 ) ) ;
F_10 ( V_17 , L_302 ,
F_124 ( V_33 , V_33 -> V_211 . V_272 ) ,
F_124 ( V_33 , V_33 -> V_211 . V_274 ) ,
F_124 ( V_33 , V_33 -> V_211 . V_395 ) ,
F_124 ( V_33 , V_33 -> V_211 . V_396 ) ,
F_124 ( V_33 , V_33 -> V_211 . V_244 ) ) ;
F_53 ( & V_33 -> V_211 . V_482 ) ;
F_52 (file, &dev->filelist, lhead) {
struct V_476 * V_99 = V_111 -> V_120 ;
struct V_118 * V_119 ;
F_56 () ;
V_119 = F_57 ( V_111 -> V_123 , V_124 ) ;
F_10 ( V_17 , L_303 ,
V_119 ? V_119 -> V_125 : L_44 ,
V_119 ? V_119 -> V_123 : - 1 ,
V_99 -> V_211 . V_483 ,
F_38 ( & V_99 -> V_211 . V_484 ) ? L_15 : L_304 ) ;
F_58 () ;
}
F_10 ( V_17 , L_305 ,
V_33 -> V_211 . V_485 . V_483 ,
F_38 ( & V_33 -> V_211 . V_485 . V_484 ) ? L_15 : L_304 ) ;
F_10 ( V_17 , L_306 ,
V_33 -> V_211 . V_486 . V_483 ,
F_38 ( & V_33 -> V_211 . V_486 . V_484 ) ? L_15 : L_304 ) ;
F_10 ( V_17 , L_307 , V_33 -> V_211 . V_483 ) ;
F_55 ( & V_33 -> V_211 . V_482 ) ;
return 0 ;
}
static int F_210 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
F_10 ( V_17 , L_308 , F_1 ( F_211 ( V_21 ) ) ) ;
F_10 ( V_17 , L_309 , V_33 -> V_487 ) ;
return 0 ;
}
static int F_212 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_488 = 0 ;
T_4 V_489 [ 3 ] ;
enum V_129 V_129 ;
bool V_480 = false ;
if ( ! F_213 ( V_21 ) ) {
F_26 ( V_17 , L_310 ) ;
return 0 ;
}
F_78 ( V_33 ) ;
F_5 ( & V_33 -> V_490 . V_320 ) ;
F_10 ( V_17 , L_311 , F_1 ( V_33 -> V_490 . V_491 ) ) ;
F_10 ( V_17 , L_312 , F_1 ( V_33 -> V_490 . V_492 ) ) ;
F_10 ( V_17 , L_313 , F_1 ( ( bool ) V_33 -> V_490 . V_480 ) ) ;
F_10 ( V_17 , L_314 , F_1 ( V_33 -> V_490 . V_41 ) ) ;
F_10 ( V_17 , L_315 ,
V_33 -> V_490 . V_493 ) ;
F_10 ( V_17 , L_316 ,
F_1 ( F_214 ( & V_33 -> V_490 . V_132 . V_132 ) ) ) ;
if ( F_215 ( V_21 ) )
V_480 = F_70 ( F_216 ( V_21 ) ) & V_494 ;
else {
F_82 (dev_priv, pipe) {
V_489 [ V_129 ] = F_70 ( F_217 ( V_129 ) ) &
V_495 ;
if ( ( V_489 [ V_129 ] == V_496 ) ||
( V_489 [ V_129 ] == V_497 ) )
V_480 = true ;
}
}
F_10 ( V_17 , L_317 , F_1 ( V_480 ) ) ;
if ( ! F_215 ( V_21 ) )
F_82 (dev_priv, pipe) {
if ( ( V_489 [ V_129 ] == V_496 ) ||
( V_489 [ V_129 ] == V_497 ) )
F_10 ( V_17 , L_318 , F_63 ( V_129 ) ) ;
}
F_26 ( V_17 , L_31 ) ;
if ( F_215 ( V_21 ) ) {
V_488 = F_70 ( F_218 ( V_21 ) ) &
V_498 ;
F_10 ( V_17 , L_319 , V_488 ) ;
}
F_7 ( & V_33 -> V_490 . V_320 ) ;
F_79 ( V_33 ) ;
return 0 ;
}
static int F_219 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_499 * V_500 ;
struct V_501 * V_502 ;
struct V_503 * V_503 = NULL ;
int V_76 ;
T_11 V_504 [ 6 ] ;
F_151 ( V_21 ) ;
F_220 (dev, connector) {
if ( V_502 -> V_34 . V_505 != V_506 )
continue;
if ( ! V_502 -> V_34 . V_500 )
continue;
V_500 = F_221 ( V_502 -> V_34 . V_500 ) ;
if ( V_500 -> type != V_507 )
continue;
V_503 = F_222 ( & V_500 -> V_34 ) ;
V_76 = F_223 ( V_503 , V_504 ) ;
if ( V_76 )
goto V_206;
F_10 ( V_17 , L_320 ,
V_504 [ 0 ] , V_504 [ 1 ] , V_504 [ 2 ] ,
V_504 [ 3 ] , V_504 [ 4 ] , V_504 [ 5 ] ) ;
goto V_206;
}
V_76 = - V_371 ;
V_206:
F_152 ( V_21 ) ;
return V_76 ;
}
static int F_224 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_8 V_508 ;
T_4 V_509 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_371 ;
F_78 ( V_33 ) ;
F_225 ( V_510 , V_508 ) ;
V_508 = ( V_508 & 0x1f00 ) >> 8 ;
V_509 = 1000000 / ( 1 << V_508 ) ;
V_508 = F_70 ( V_511 ) ;
V_508 *= V_509 ;
F_79 ( V_33 ) ;
F_10 ( V_17 , L_321 , ( long long unsigned ) V_508 ) ;
return 0 ;
}
static int F_226 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
if ( ! F_123 ( V_21 ) && ! F_120 ( V_21 ) ) {
F_26 ( V_17 , L_229 ) ;
return 0 ;
}
F_10 ( V_17 , L_322 , F_1 ( ! V_33 -> V_112 . V_481 ) ) ;
F_10 ( V_17 , L_323 ,
F_1 ( ! F_227 ( V_33 ) ) ) ;
return 0 ;
}
static const char * F_228 ( enum V_512 V_513 )
{
switch ( V_513 ) {
case V_514 :
return L_324 ;
case V_515 :
return L_325 ;
case V_516 :
return L_326 ;
case V_517 :
return L_327 ;
case V_518 :
return L_328 ;
case V_519 :
return L_329 ;
case V_520 :
return L_330 ;
case V_521 :
return L_331 ;
case V_522 :
return L_332 ;
case V_523 :
return L_333 ;
case V_524 :
return L_334 ;
case V_525 :
return L_335 ;
case V_526 :
return L_336 ;
case V_527 :
return L_337 ;
case V_528 :
return L_338 ;
case V_529 :
return L_339 ;
case V_530 :
return L_340 ;
case V_531 :
return L_341 ;
case V_532 :
return L_342 ;
case V_533 :
return L_343 ;
case V_534 :
return L_344 ;
case V_535 :
return L_345 ;
case V_536 :
return L_346 ;
case V_537 :
return L_347 ;
case V_538 :
return L_348 ;
case V_539 :
return L_349 ;
case V_540 :
return L_350 ;
case V_541 :
return L_351 ;
case V_542 :
return L_352 ;
default:
F_229 ( V_513 ) ;
return L_353 ;
}
}
static int F_230 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_543 * V_544 = & V_33 -> V_544 ;
int V_40 ;
F_5 ( & V_544 -> V_320 ) ;
F_10 ( V_17 , L_354 , L_355 , L_356 ) ;
for ( V_40 = 0 ; V_40 < V_544 -> V_545 ; V_40 ++ ) {
struct V_546 * V_547 ;
enum V_512 V_548 ;
V_547 = & V_544 -> V_549 [ V_40 ] ;
F_10 ( V_17 , L_357 , V_547 -> V_52 ,
V_547 -> V_75 ) ;
for ( V_548 = 0 ; V_548 < V_550 ;
V_548 ++ ) {
if ( ! ( F_231 ( V_548 ) & V_547 -> V_551 ) )
continue;
F_10 ( V_17 , L_358 ,
F_228 ( V_548 ) ,
V_544 -> V_552 [ V_548 ] ) ;
}
}
F_7 ( & V_544 -> V_320 ) ;
return 0 ;
}
static void F_232 ( struct V_16 * V_17 , int V_553 ,
struct V_554 * V_555 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_553 ; V_40 ++ )
F_29 ( V_17 , '\t' ) ;
F_10 ( V_17 , L_359 ,
V_555 -> V_34 . V_89 , V_555 -> V_52 ,
V_555 -> V_556 , V_555 -> clock ,
V_555 -> V_557 , V_555 -> V_558 ,
V_555 -> V_559 , V_555 -> V_560 ,
V_555 -> V_561 , V_555 -> V_562 ,
V_555 -> V_563 , V_555 -> V_564 ,
V_555 -> type , V_555 -> V_438 ) ;
}
static void F_233 ( struct V_16 * V_17 ,
struct V_127 * V_127 ,
struct V_499 * V_499 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_565 * V_128 = & V_127 -> V_34 ;
struct V_501 * V_501 ;
struct V_566 * V_500 ;
V_500 = & V_499 -> V_34 ;
F_10 ( V_17 , L_360 ,
V_500 -> V_34 . V_89 , V_500 -> V_52 ) ;
F_234 (dev, encoder, intel_connector) {
struct V_567 * V_502 = & V_501 -> V_34 ;
F_10 ( V_17 , L_361 ,
V_502 -> V_34 . V_89 ,
V_502 -> V_52 ,
F_235 ( V_502 -> V_433 ) ) ;
if ( V_502 -> V_433 == V_568 ) {
struct V_554 * V_555 = & V_128 -> V_555 ;
F_10 ( V_17 , L_362 ) ;
F_232 ( V_17 , 2 , V_555 ) ;
} else {
F_29 ( V_17 , '\n' ) ;
}
}
}
static void F_236 ( struct V_16 * V_17 , struct V_127 * V_127 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_565 * V_128 = & V_127 -> V_34 ;
struct V_499 * V_499 ;
if ( V_128 -> V_569 -> V_405 )
F_10 ( V_17 , L_363 ,
V_128 -> V_569 -> V_405 -> V_34 . V_89 , V_128 -> T_1 , V_128 -> V_570 ,
V_128 -> V_569 -> V_405 -> V_408 , V_128 -> V_569 -> V_405 -> V_409 ) ;
else
F_26 ( V_17 , L_364 ) ;
F_237 (dev, crtc, intel_encoder)
F_233 ( V_17 , V_127 , V_499 ) ;
}
static void F_238 ( struct V_16 * V_17 , struct V_571 * V_572 )
{
struct V_554 * V_555 = V_572 -> V_573 ;
F_10 ( V_17 , L_365 ) ;
F_232 ( V_17 , 2 , V_555 ) ;
}
static void F_239 ( struct V_16 * V_17 ,
struct V_501 * V_501 )
{
struct V_499 * V_499 = V_501 -> V_500 ;
struct V_503 * V_503 = F_222 ( & V_499 -> V_34 ) ;
F_10 ( V_17 , L_366 , V_503 -> V_574 [ V_575 ] ) ;
F_10 ( V_17 , L_367 , V_503 -> V_576 ? L_1 :
L_2 ) ;
if ( V_499 -> type == V_507 )
F_238 ( V_17 , & V_501 -> V_572 ) ;
}
static void F_240 ( struct V_16 * V_17 ,
struct V_501 * V_501 )
{
struct V_499 * V_499 = V_501 -> V_500 ;
struct V_577 * V_577 = F_241 ( & V_499 -> V_34 ) ;
F_10 ( V_17 , L_367 , V_577 -> V_576 ? L_1 :
L_2 ) ;
}
static void F_242 ( struct V_16 * V_17 ,
struct V_501 * V_501 )
{
F_238 ( V_17 , & V_501 -> V_572 ) ;
}
static void F_243 ( struct V_16 * V_17 ,
struct V_567 * V_502 )
{
struct V_501 * V_501 = F_244 ( V_502 ) ;
struct V_499 * V_499 = V_501 -> V_500 ;
struct V_554 * V_555 ;
F_10 ( V_17 , L_368 ,
V_502 -> V_34 . V_89 , V_502 -> V_52 ,
F_235 ( V_502 -> V_433 ) ) ;
if ( V_502 -> V_433 == V_568 ) {
F_10 ( V_17 , L_369 , V_502 -> V_578 . V_52 ) ;
F_10 ( V_17 , L_370 ,
V_502 -> V_578 . V_579 ,
V_502 -> V_578 . V_580 ) ;
F_10 ( V_17 , L_371 ,
F_245 ( V_502 -> V_578 . V_581 ) ) ;
F_10 ( V_17 , L_372 ,
V_502 -> V_578 . V_582 ) ;
}
if ( V_499 ) {
if ( V_499 -> type == V_583 ||
V_499 -> type == V_507 )
F_239 ( V_17 , V_501 ) ;
else if ( V_499 -> type == V_584 )
F_240 ( V_17 , V_501 ) ;
else if ( V_499 -> type == V_585 )
F_242 ( V_17 , V_501 ) ;
}
F_10 ( V_17 , L_373 ) ;
F_24 (mode, &connector->modes, head)
F_232 ( V_17 , 2 , V_555 ) ;
}
static bool F_246 ( struct V_20 * V_21 , int V_129 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_426 ;
if ( F_247 ( V_21 ) || F_248 ( V_21 ) )
V_426 = F_70 ( V_586 ) & V_587 ;
else
V_426 = F_70 ( F_249 ( V_129 ) ) & V_588 ;
return V_426 ;
}
static bool F_250 ( struct V_20 * V_21 , int V_129 , int * T_1 , int * V_570 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_201 ;
V_201 = F_70 ( F_251 ( V_129 ) ) ;
* T_1 = ( V_201 >> V_589 ) & V_590 ;
if ( V_201 & ( V_591 << V_589 ) )
* T_1 = - * T_1 ;
* V_570 = ( V_201 >> V_592 ) & V_590 ;
if ( V_201 & ( V_591 << V_592 ) )
* V_570 = - * V_570 ;
return F_246 ( V_21 , V_129 ) ;
}
static int F_252 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_127 * V_128 ;
struct V_567 * V_502 ;
F_78 ( V_33 ) ;
F_151 ( V_21 ) ;
F_10 ( V_17 , L_374 ) ;
F_10 ( V_17 , L_375 ) ;
F_62 (dev, crtc) {
bool V_41 ;
int T_1 , V_570 ;
F_10 ( V_17 , L_376 ,
V_128 -> V_34 . V_34 . V_89 , F_63 ( V_128 -> V_129 ) ,
F_1 ( V_128 -> V_41 ) , V_128 -> V_593 -> V_594 ,
V_128 -> V_593 -> V_595 ) ;
if ( V_128 -> V_41 ) {
F_236 ( V_17 , V_128 ) ;
V_41 = F_250 ( V_21 , V_128 -> V_129 , & T_1 , & V_570 ) ;
F_10 ( V_17 , L_377 ,
F_1 ( V_128 -> V_596 ) ,
T_1 , V_570 , V_128 -> V_34 . V_435 -> V_426 -> V_597 ,
V_128 -> V_34 . V_435 -> V_426 -> V_598 ,
V_128 -> V_599 , F_1 ( V_41 ) ) ;
}
F_10 ( V_17 , L_378 ,
F_1 ( ! V_128 -> V_600 ) ,
F_1 ( ! V_128 -> V_601 ) ) ;
}
F_10 ( V_17 , L_31 ) ;
F_10 ( V_17 , L_379 ) ;
F_10 ( V_17 , L_380 ) ;
F_24 (connector, &dev->mode_config.connector_list, head) {
F_243 ( V_17 , V_502 ) ;
}
F_152 ( V_21 ) ;
F_79 ( V_33 ) ;
return 0 ;
}
static int F_253 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_35 * V_36 ;
int V_602 = F_254 ( F_9 ( V_21 ) -> V_603 ) ;
int V_40 , V_103 , V_76 ;
if ( ! F_255 ( V_21 ) ) {
F_26 ( V_17 , L_381 ) ;
return 0 ;
}
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
if ( F_120 ( V_21 ) ) {
struct V_427 * V_427 ;
T_12 * V_149 ;
V_427 = F_181 ( V_33 -> V_604 , 0 ) ;
V_149 = ( T_12 * ) F_183 ( V_427 ) ;
F_21 (ring, dev_priv, i) {
T_12 V_470 ;
F_10 ( V_17 , L_256 , V_36 -> V_52 ) ;
F_26 ( V_17 , L_382 ) ;
for ( V_103 = 0 ; V_103 < V_602 ; V_103 ++ ) {
V_470 = V_40 * V_281 + V_103 ;
F_10 ( V_17 , L_383 ,
V_149 [ V_470 ] , V_470 * 8 ) ;
}
F_29 ( V_17 , '\n' ) ;
F_26 ( V_17 , L_384 ) ;
for ( V_103 = 0 ; V_103 < V_602 ; V_103 ++ ) {
V_470 = V_40 + ( V_103 * V_281 ) ;
F_10 ( V_17 , L_383 ,
V_149 [ V_470 ] , V_470 * 8 ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_184 ( V_149 ) ;
} else {
F_26 ( V_17 , L_382 ) ;
F_21 (ring, dev_priv, i)
for ( V_103 = 0 ; V_103 < V_602 ; V_103 ++ )
F_10 ( V_17 , L_385 ,
F_70 ( V_36 -> V_605 . V_606 . signal [ V_103 ] ) ) ;
F_29 ( V_17 , '\n' ) ;
}
F_26 ( V_17 , L_386 ) ;
F_21 (ring, dev_priv, i) {
for ( V_103 = 0 ; V_103 < V_602 ; V_103 ++ ) {
F_10 ( V_17 , L_387 , V_36 -> V_605 . V_607 [ V_103 ] ) ;
}
F_29 ( V_17 , '\n' ) ;
}
F_29 ( V_17 , '\n' ) ;
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_256 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_40 ;
F_151 ( V_21 ) ;
for ( V_40 = 0 ; V_40 < V_33 -> V_608 ; V_40 ++ ) {
struct V_609 * V_610 = & V_33 -> V_611 [ V_40 ] ;
F_10 ( V_17 , L_388 , V_40 , V_610 -> V_52 , V_610 -> V_89 ) ;
F_10 ( V_17 , L_389 ,
V_610 -> V_593 . V_612 , V_610 -> V_41 , F_1 ( V_610 -> V_613 ) ) ;
F_10 ( V_17 , L_390 ) ;
F_10 ( V_17 , L_391 , V_610 -> V_593 . V_614 . V_615 ) ;
F_10 ( V_17 , L_392 ,
V_610 -> V_593 . V_614 . V_616 ) ;
F_10 ( V_17 , L_393 , V_610 -> V_593 . V_614 . V_617 ) ;
F_10 ( V_17 , L_394 , V_610 -> V_593 . V_614 . V_618 ) ;
F_10 ( V_17 , L_395 , V_610 -> V_593 . V_614 . V_619 ) ;
}
F_152 ( V_21 ) ;
return 0 ;
}
static int F_257 ( struct V_16 * V_17 , void * V_210 )
{
int V_40 ;
int V_76 ;
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
F_10 ( V_17 , L_396 , V_33 -> V_620 . V_75 ) ;
for ( V_40 = 0 ; V_40 < V_33 -> V_620 . V_75 ; ++ V_40 ) {
T_4 V_135 , V_621 , V_622 , V_623 ;
bool V_624 ;
V_135 = V_33 -> V_620 . V_373 [ V_40 ] . V_135 ;
V_621 = V_33 -> V_620 . V_373 [ V_40 ] . V_621 ;
V_622 = V_33 -> V_620 . V_373 [ V_40 ] . V_622 ;
V_623 = F_70 ( V_135 ) ;
V_624 = ( V_622 & V_621 ) == ( V_623 & V_621 ) ;
F_10 ( V_17 , L_397 ,
V_135 , V_622 , V_621 , V_623 , V_624 ? L_398 : L_399 ) ;
}
F_79 ( V_33 ) ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int F_258 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_625 * V_626 ;
struct V_627 * V_628 ;
enum V_129 V_129 ;
int V_130 ;
if ( F_9 ( V_21 ) -> V_24 < 9 )
return 0 ;
F_151 ( V_21 ) ;
V_626 = & V_33 -> V_629 . V_630 . V_626 ;
F_10 ( V_17 , L_400 , L_15 , L_401 , L_402 , L_403 ) ;
F_82 (dev_priv, pipe) {
F_10 ( V_17 , L_404 , F_63 ( V_129 ) ) ;
F_259 (dev_priv, pipe, plane) {
V_628 = & V_626 -> V_130 [ V_129 ] [ V_130 ] ;
F_10 ( V_17 , L_405 , V_130 + 1 ,
V_628 -> V_56 , V_628 -> V_631 ,
F_260 ( V_628 ) ) ;
}
V_628 = & V_626 -> V_435 [ V_129 ] ;
F_10 ( V_17 , L_406 , L_407 , V_628 -> V_56 ,
V_628 -> V_631 , F_260 ( V_628 ) ) ;
}
F_152 ( V_21 ) ;
return 0 ;
}
static void F_261 ( struct V_16 * V_17 ,
struct V_20 * V_21 , struct V_127 * V_127 )
{
struct V_499 * V_499 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_632 * V_633 = & V_33 -> V_633 ;
int V_556 = 0 ;
F_237 (dev, &intel_crtc->base, intel_encoder) {
switch ( V_499 -> type ) {
case V_507 :
F_26 ( V_17 , L_408 ) ;
break;
case V_634 :
F_26 ( V_17 , L_409 ) ;
break;
case V_584 :
F_26 ( V_17 , L_410 ) ;
break;
case V_583 :
F_26 ( V_17 , L_411 ) ;
break;
default:
F_10 ( V_17 , L_412 ,
V_499 -> type ) ;
return;
}
}
if ( V_33 -> V_635 . V_636 == V_637 )
F_26 ( V_17 , L_413 ) ;
else if ( V_33 -> V_635 . V_636 == V_638 )
F_26 ( V_17 , L_414 ) ;
else if ( V_33 -> V_635 . V_636 == V_639 )
F_26 ( V_17 , L_415 ) ;
else
F_26 ( V_17 , L_416 ) ;
F_26 ( V_17 , L_417 ) ;
if ( V_127 -> V_593 -> V_640 ) {
struct V_571 * V_572 ;
F_5 ( & V_633 -> V_641 ) ;
F_26 ( V_17 , L_418 ) ;
if ( ! V_633 -> V_642 ) {
F_26 ( V_17 , L_419 ) ;
F_7 ( & V_633 -> V_641 ) ;
return;
}
V_572 = & V_633 -> V_642 -> V_643 -> V_572 ;
F_10 ( V_17 , L_420 ,
V_633 -> V_493 ) ;
F_26 ( V_17 , L_421 ) ;
if ( V_633 -> V_644 == V_645 ) {
F_26 ( V_17 , L_422 ) ;
V_556 = V_572 -> V_573 -> V_556 ;
} else if ( V_633 -> V_644 == V_646 ) {
F_26 ( V_17 , L_423 ) ;
V_556 = V_572 -> V_647 -> V_556 ;
} else {
F_10 ( V_17 , L_424 ,
V_633 -> V_644 ) ;
F_7 ( & V_633 -> V_641 ) ;
return;
}
F_10 ( V_17 , L_425 , V_556 ) ;
F_26 ( V_17 , L_421 ) ;
F_7 ( & V_633 -> V_641 ) ;
} else {
F_26 ( V_17 , L_426 ) ;
}
F_26 ( V_17 , L_31 ) ;
}
static int F_262 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_127 * V_127 ;
int V_648 = 0 ;
F_62 (dev, intel_crtc) {
F_263 ( & V_127 -> V_34 . V_641 , NULL ) ;
if ( V_127 -> V_41 ) {
V_648 ++ ;
F_10 ( V_17 , L_427 , V_648 ) ;
F_261 ( V_17 , V_21 , V_127 ) ;
}
F_264 ( & V_127 -> V_34 . V_641 ) ;
}
if ( ! V_648 )
F_26 ( V_17 , L_428 ) ;
return 0 ;
}
static int F_265 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_566 * V_500 ;
struct V_499 * V_499 ;
struct V_649 * V_650 ;
F_151 ( V_21 ) ;
F_24 (encoder, &dev->mode_config.encoder_list, head) {
V_499 = F_221 ( V_500 ) ;
if ( V_499 -> type != V_583 )
continue;
V_650 = F_266 ( V_500 ) ;
if ( ! V_650 -> V_642 . V_651 )
continue;
F_267 ( V_17 , & V_650 -> V_642 . V_652 ) ;
}
F_152 ( V_21 ) ;
return 0 ;
}
static int F_268 ( struct V_198 * V_198 , struct V_111 * V_653 )
{
struct V_654 * V_23 = V_198 -> V_199 ;
struct V_32 * V_33 = V_23 -> V_21 -> V_70 ;
struct V_655 * V_656 = & V_33 -> V_656 [ V_23 -> V_129 ] ;
if ( V_23 -> V_129 >= F_9 ( V_23 -> V_21 ) -> V_657 )
return - V_371 ;
F_65 ( & V_656 -> V_320 ) ;
if ( V_656 -> V_658 ) {
F_73 ( & V_656 -> V_320 ) ;
return - V_659 ;
}
V_656 -> V_658 = true ;
V_653 -> V_197 = V_198 -> V_199 ;
F_73 ( & V_656 -> V_320 ) ;
return 0 ;
}
static int F_269 ( struct V_198 * V_198 , struct V_111 * V_653 )
{
struct V_654 * V_23 = V_198 -> V_199 ;
struct V_32 * V_33 = V_23 -> V_21 -> V_70 ;
struct V_655 * V_656 = & V_33 -> V_656 [ V_23 -> V_129 ] ;
F_65 ( & V_656 -> V_320 ) ;
V_656 -> V_658 = false ;
F_73 ( & V_656 -> V_320 ) ;
return 0 ;
}
static int F_270 ( struct V_655 * V_656 )
{
F_271 ( & V_656 -> V_320 ) ;
return F_272 ( V_656 -> V_69 , V_656 -> V_419 ,
V_660 ) ;
}
static T_5
F_273 ( struct V_111 * V_653 , char T_6 * V_661 , T_3 V_75 ,
T_7 * V_201 )
{
struct V_654 * V_23 = V_653 -> V_197 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_655 * V_656 = & V_33 -> V_656 [ V_23 -> V_129 ] ;
char V_207 [ V_662 ] ;
int V_663 ;
T_5 V_664 ;
if ( V_75 < V_665 )
return - V_82 ;
if ( V_656 -> V_666 == V_667 )
return 0 ;
F_65 ( & V_656 -> V_320 ) ;
while ( F_270 ( V_656 ) == 0 ) {
int V_76 ;
if ( V_653 -> V_668 & V_669 ) {
F_73 ( & V_656 -> V_320 ) ;
return - V_670 ;
}
V_76 = F_274 ( V_656 -> V_671 ,
F_270 ( V_656 ) , V_656 -> V_320 ) ;
if ( V_76 ) {
F_73 ( & V_656 -> V_320 ) ;
return V_76 ;
}
}
V_663 = V_75 / V_665 ;
V_664 = 0 ;
while ( V_663 > 0 ) {
struct V_672 * V_628 =
& V_656 -> V_673 [ V_656 -> V_419 ] ;
int V_76 ;
if ( F_272 ( V_656 -> V_69 , V_656 -> V_419 ,
V_660 ) < 1 )
break;
F_275 ( V_660 ) ;
V_656 -> V_419 = ( V_656 -> V_419 + 1 ) & ( V_660 - 1 ) ;
V_664 += snprintf ( V_207 , V_662 ,
L_429 ,
V_628 -> V_674 , V_628 -> V_504 [ 0 ] ,
V_628 -> V_504 [ 1 ] , V_628 -> V_504 [ 2 ] ,
V_628 -> V_504 [ 3 ] , V_628 -> V_504 [ 4 ] ) ;
F_73 ( & V_656 -> V_320 ) ;
V_76 = F_276 ( V_661 , V_207 , V_665 ) ;
if ( V_76 == V_665 )
return - V_675 ;
V_661 += V_665 ;
V_663 -- ;
F_65 ( & V_656 -> V_320 ) ;
}
F_73 ( & V_656 -> V_320 ) ;
return V_664 ;
}
static int F_277 ( struct V_4 * V_676 , struct V_2 * V_3 ,
enum V_129 V_129 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_654 * V_23 = & V_677 [ V_129 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_278 ( V_23 -> V_52 , V_678 , V_676 , V_23 ,
& V_679 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_279 ( enum V_680 V_666 )
{
F_280 ( F_47 ( V_681 ) != V_682 ) ;
return V_681 [ V_666 ] ;
}
static int F_281 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_683 ; V_40 ++ )
F_10 ( V_17 , L_430 , F_63 ( V_40 ) ,
F_279 ( V_33 -> V_656 [ V_40 ] . V_666 ) ) ;
return 0 ;
}
static int F_282 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_283 ( V_111 , F_281 , V_21 ) ;
}
static int F_284 ( enum V_680 * V_666 ,
T_10 * V_209 )
{
if ( * V_666 == V_684 )
* V_666 = V_685 ;
switch ( * V_666 ) {
case V_685 :
* V_209 = V_686 | V_687 ;
break;
case V_667 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_285 ( struct V_20 * V_21 , enum V_129 V_129 ,
enum V_680 * V_666 )
{
struct V_499 * V_500 ;
struct V_127 * V_128 ;
struct V_649 * V_688 ;
int V_76 = 0 ;
* V_666 = V_685 ;
F_151 ( V_21 ) ;
F_286 (dev, encoder) {
if ( ! V_500 -> V_34 . V_128 )
continue;
V_128 = F_287 ( V_500 -> V_34 . V_128 ) ;
if ( V_128 -> V_129 != V_129 )
continue;
switch ( V_500 -> type ) {
case V_689 :
* V_666 = V_690 ;
break;
case V_583 :
case V_507 :
V_688 = F_266 ( & V_500 -> V_34 ) ;
switch ( V_688 -> V_691 ) {
case V_692 :
* V_666 = V_693 ;
break;
case V_694 :
* V_666 = V_695 ;
break;
case V_696 :
* V_666 = V_697 ;
break;
default:
F_288 ( 1 , L_431 ,
F_289 ( V_688 -> V_691 ) ) ;
break;
}
break;
default:
break;
}
}
F_152 ( V_21 ) ;
return V_76 ;
}
static int F_290 ( struct V_20 * V_21 ,
enum V_129 V_129 ,
enum V_680 * V_666 ,
T_10 * V_209 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
bool V_698 = false ;
if ( * V_666 == V_684 ) {
int V_76 = F_285 ( V_21 , V_129 , V_666 ) ;
if ( V_76 )
return V_76 ;
}
switch ( * V_666 ) {
case V_685 :
* V_209 = V_686 | V_699 ;
break;
case V_693 :
* V_209 = V_686 | V_700 ;
V_698 = true ;
break;
case V_695 :
* V_209 = V_686 | V_701 ;
V_698 = true ;
break;
case V_697 :
if ( ! F_81 ( V_21 ) )
return - V_82 ;
* V_209 = V_686 | V_702 ;
V_698 = true ;
break;
case V_667 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
if ( V_698 ) {
T_10 V_703 = F_70 ( V_704 ) ;
V_703 |= V_705 ;
switch ( V_129 ) {
case V_706 :
V_703 |= V_707 ;
break;
case V_708 :
V_703 |= V_709 ;
break;
case V_710 :
V_703 |= V_711 ;
break;
default:
return - V_82 ;
}
F_154 ( V_704 , V_703 ) ;
}
return 0 ;
}
static int F_291 ( struct V_20 * V_21 ,
enum V_129 V_129 ,
enum V_680 * V_666 ,
T_10 * V_209 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
bool V_698 = false ;
if ( * V_666 == V_684 ) {
int V_76 = F_285 ( V_21 , V_129 , V_666 ) ;
if ( V_76 )
return V_76 ;
}
switch ( * V_666 ) {
case V_685 :
* V_209 = V_686 | V_712 ;
break;
case V_690 :
if ( ! F_292 ( V_21 ) )
return - V_82 ;
* V_209 = V_686 | V_713 ;
break;
case V_693 :
if ( ! F_159 ( V_21 ) )
return - V_82 ;
* V_209 = V_686 | V_714 ;
V_698 = true ;
break;
case V_695 :
if ( ! F_159 ( V_21 ) )
return - V_82 ;
* V_209 = V_686 | V_715 ;
V_698 = true ;
break;
case V_697 :
if ( ! F_159 ( V_21 ) )
return - V_82 ;
* V_209 = V_686 | V_716 ;
V_698 = true ;
break;
case V_667 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
if ( V_698 ) {
T_10 V_703 = F_70 ( V_704 ) ;
F_182 ( ! F_159 ( V_21 ) ) ;
F_154 ( V_717 ,
F_70 ( V_717 ) | V_718 ) ;
if ( V_129 == V_706 )
V_703 |= V_707 ;
else
V_703 |= V_709 ;
F_154 ( V_704 , V_703 ) ;
}
return 0 ;
}
static void F_293 ( struct V_20 * V_21 ,
enum V_129 V_129 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
T_10 V_703 = F_70 ( V_704 ) ;
switch ( V_129 ) {
case V_706 :
V_703 &= ~ V_707 ;
break;
case V_708 :
V_703 &= ~ V_709 ;
break;
case V_710 :
V_703 &= ~ V_711 ;
break;
default:
return;
}
if ( ! ( V_703 & V_719 ) )
V_703 &= ~ V_705 ;
F_154 ( V_704 , V_703 ) ;
}
static void F_294 ( struct V_20 * V_21 ,
enum V_129 V_129 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
T_10 V_703 = F_70 ( V_704 ) ;
if ( V_129 == V_706 )
V_703 &= ~ V_707 ;
else
V_703 &= ~ V_709 ;
F_154 ( V_704 , V_703 ) ;
if ( ! ( V_703 & V_719 ) ) {
F_154 ( V_717 ,
F_70 ( V_717 ) & ~ V_718 ) ;
}
}
static int F_295 ( enum V_680 * V_666 ,
T_10 * V_209 )
{
if ( * V_666 == V_684 )
* V_666 = V_685 ;
switch ( * V_666 ) {
case V_720 :
* V_209 = V_686 | V_721 ;
break;
case V_722 :
* V_209 = V_686 | V_723 ;
break;
case V_685 :
* V_209 = V_686 | V_724 ;
break;
case V_667 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static void F_296 ( struct V_20 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_127 * V_128 =
F_287 ( V_33 -> V_725 [ V_706 ] ) ;
F_151 ( V_21 ) ;
if ( V_128 -> V_593 -> V_726 == V_727 &&
! V_128 -> V_593 -> V_728 . V_480 ) {
V_128 -> V_593 -> V_728 . V_729 = true ;
F_297 ( V_33 ,
F_298 ( V_706 ) ) ;
F_299 ( V_128 ) ;
}
F_152 ( V_21 ) ;
}
static void F_300 ( struct V_20 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_127 * V_128 =
F_287 ( V_33 -> V_725 [ V_706 ] ) ;
F_151 ( V_21 ) ;
if ( V_128 -> V_593 -> V_728 . V_729 ) {
V_128 -> V_593 -> V_728 . V_729 = false ;
F_299 ( V_128 ) ;
F_301 ( V_33 ,
F_298 ( V_706 ) ) ;
}
F_152 ( V_21 ) ;
}
static int F_302 ( struct V_20 * V_21 ,
enum V_129 V_129 ,
enum V_680 * V_666 ,
T_10 * V_209 )
{
if ( * V_666 == V_684 )
* V_666 = V_730 ;
switch ( * V_666 ) {
case V_720 :
* V_209 = V_686 | V_731 ;
break;
case V_722 :
* V_209 = V_686 | V_732 ;
break;
case V_730 :
if ( F_123 ( V_21 ) && V_129 == V_706 )
F_296 ( V_21 ) ;
* V_209 = V_686 | V_733 ;
break;
case V_667 :
* V_209 = 0 ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_303 ( struct V_20 * V_21 , enum V_129 V_129 ,
enum V_680 V_666 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
struct V_655 * V_656 = & V_33 -> V_656 [ V_129 ] ;
struct V_127 * V_128 = F_287 ( F_304 ( V_21 ,
V_129 ) ) ;
T_4 V_209 = 0 ;
int V_76 ;
if ( V_656 -> V_666 == V_666 )
return 0 ;
if ( V_656 -> V_666 && V_666 )
return - V_82 ;
if ( ! F_87 ( V_33 , F_88 ( V_129 ) ) ) {
F_305 ( L_432 ) ;
return - V_734 ;
}
if ( F_306 ( V_21 ) )
V_76 = F_284 ( & V_666 , & V_209 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_76 = F_291 ( V_21 , V_129 , & V_666 , & V_209 ) ;
else if ( F_92 ( V_21 ) )
V_76 = F_290 ( V_21 , V_129 , & V_666 , & V_209 ) ;
else if ( F_116 ( V_21 ) || F_118 ( V_21 ) )
V_76 = F_295 ( & V_666 , & V_209 ) ;
else
V_76 = F_302 ( V_21 , V_129 , & V_666 , & V_209 ) ;
if ( V_76 != 0 )
return V_76 ;
if ( V_666 ) {
struct V_672 * V_673 ;
F_98 ( L_433 ,
F_63 ( V_129 ) , F_279 ( V_666 ) ) ;
V_673 = F_307 ( V_660 ,
sizeof( V_656 -> V_673 [ 0 ] ) ,
V_9 ) ;
if ( ! V_673 )
return - V_10 ;
F_308 ( V_128 ) ;
F_65 ( & V_656 -> V_320 ) ;
F_105 ( V_656 -> V_673 ) ;
V_656 -> V_673 = V_673 ;
V_656 -> V_69 = 0 ;
V_656 -> V_419 = 0 ;
F_73 ( & V_656 -> V_320 ) ;
}
V_656 -> V_666 = V_666 ;
F_154 ( F_309 ( V_129 ) , V_209 ) ;
F_310 ( F_309 ( V_129 ) ) ;
if ( V_666 == V_667 ) {
struct V_672 * V_673 ;
struct V_127 * V_128 =
F_287 ( V_33 -> V_725 [ V_129 ] ) ;
F_98 ( L_434 ,
F_63 ( V_129 ) ) ;
F_263 ( & V_128 -> V_34 . V_641 , NULL ) ;
if ( V_128 -> V_41 )
F_311 ( V_21 , V_129 ) ;
F_264 ( & V_128 -> V_34 . V_641 ) ;
F_65 ( & V_656 -> V_320 ) ;
V_673 = V_656 -> V_673 ;
V_656 -> V_673 = NULL ;
V_656 -> V_69 = 0 ;
V_656 -> V_419 = 0 ;
F_73 ( & V_656 -> V_320 ) ;
F_105 ( V_673 ) ;
if ( F_159 ( V_21 ) )
F_294 ( V_21 , V_129 ) ;
else if ( F_92 ( V_21 ) )
F_293 ( V_21 , V_129 ) ;
else if ( F_123 ( V_21 ) && V_129 == V_706 )
F_300 ( V_21 ) ;
F_312 ( V_128 ) ;
}
return 0 ;
}
static int F_313 ( char * V_207 , char * V_735 [] , int V_736 )
{
int V_737 = 0 ;
while ( * V_207 ) {
char * V_631 ;
V_207 = F_314 ( V_207 ) ;
if ( ! * V_207 )
break;
for ( V_631 = V_207 ; * V_631 && ! isspace ( * V_631 ) ; V_631 ++ )
;
if ( V_737 == V_736 ) {
F_98 ( L_435 ,
V_736 ) ;
return - V_82 ;
}
if ( * V_631 )
* V_631 ++ = '\0' ;
V_735 [ V_737 ++ ] = V_207 ;
V_207 = V_631 ;
}
return V_737 ;
}
static int
F_315 ( const char * V_207 , enum V_738 * V_739 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_47 ( V_740 ) ; V_40 ++ )
if ( ! strcmp ( V_207 , V_740 [ V_40 ] ) ) {
* V_739 = V_40 ;
return 0 ;
}
return - V_82 ;
}
static int F_316 ( const char * V_207 , enum V_129 * V_129 )
{
const char V_52 = V_207 [ 0 ] ;
if ( V_52 < 'A' || V_52 >= F_63 ( V_683 ) )
return - V_82 ;
* V_129 = V_52 - 'A' ;
return 0 ;
}
static int
F_317 ( const char * V_207 , enum V_680 * V_60 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_47 ( V_681 ) ; V_40 ++ )
if ( ! strcmp ( V_207 , V_681 [ V_40 ] ) ) {
* V_60 = V_40 ;
return 0 ;
}
return - V_82 ;
}
static int F_318 ( struct V_20 * V_21 , char * V_207 , T_3 V_741 )
{
#define F_319 3
int V_737 ;
char * V_735 [ F_319 ] ;
enum V_129 V_129 ;
enum V_738 V_742 ;
enum V_680 V_666 ;
V_737 = F_313 ( V_207 , V_735 , F_319 ) ;
if ( V_737 != F_319 ) {
F_98 ( L_436 ,
F_319 ) ;
return - V_82 ;
}
if ( F_315 ( V_735 [ 0 ] , & V_742 ) < 0 ) {
F_98 ( L_437 , V_735 [ 0 ] ) ;
return - V_82 ;
}
if ( F_316 ( V_735 [ 1 ] , & V_129 ) < 0 ) {
F_98 ( L_438 , V_735 [ 1 ] ) ;
return - V_82 ;
}
if ( F_317 ( V_735 [ 2 ] , & V_666 ) < 0 ) {
F_98 ( L_439 , V_735 [ 2 ] ) ;
return - V_82 ;
}
return F_303 ( V_21 , V_129 , V_666 ) ;
}
static T_5 F_320 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_3 V_741 , T_7 * V_743 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_744 ;
int V_76 ;
if ( V_741 == 0 )
return 0 ;
if ( V_741 > V_745 - 1 ) {
F_98 ( L_440 ,
V_745 ) ;
return - V_746 ;
}
V_744 = F_3 ( V_741 + 1 , V_9 ) ;
if ( ! V_744 )
return - V_10 ;
if ( F_321 ( V_744 , V_192 , V_741 ) ) {
V_76 = - V_675 ;
goto V_206;
}
V_744 [ V_741 ] = '\0' ;
V_76 = F_318 ( V_21 , V_744 , V_741 ) ;
V_206:
F_105 ( V_744 ) ;
if ( V_76 < 0 )
return V_76 ;
* V_743 += V_741 ;
return V_741 ;
}
static T_5 F_322 ( struct V_111 * V_111 ,
const char T_6 * V_192 ,
T_3 V_741 , T_7 * V_743 )
{
char * V_747 ;
int V_433 = 0 ;
struct V_16 * V_17 ;
struct V_20 * V_21 ;
struct V_567 * V_502 ;
struct V_68 * V_748 ;
struct V_503 * V_503 ;
int V_209 = 0 ;
V_17 = V_111 -> V_197 ;
if ( ! V_17 ) {
V_433 = - V_371 ;
return V_433 ;
}
V_21 = V_17 -> V_19 ;
if ( ! V_21 ) {
V_433 = - V_371 ;
return V_433 ;
}
V_748 = & V_21 -> V_414 . V_748 ;
if ( V_741 == 0 )
return 0 ;
V_747 = F_3 ( V_741 + 1 , V_9 ) ;
if ( ! V_747 )
return - V_10 ;
if ( F_321 ( V_747 , V_192 , V_741 ) ) {
V_433 = - V_675 ;
goto V_206;
}
V_747 [ V_741 ] = '\0' ;
F_98 ( L_441 , ( unsigned int ) V_741 ) ;
F_24 (connector, connector_list, head) {
if ( V_502 -> V_749 !=
V_750 )
continue;
if ( V_502 -> V_749 ==
V_750 &&
V_502 -> V_433 == V_568 &&
V_502 -> V_500 != NULL ) {
V_503 = F_222 ( V_502 -> V_500 ) ;
V_433 = F_323 ( V_747 , 10 , & V_209 ) ;
if ( V_433 < 0 )
goto V_206;
F_98 ( L_442 , V_209 ) ;
if ( V_209 == 1 )
V_503 -> V_751 = 1 ;
else
V_503 -> V_751 = 0 ;
}
}
V_206:
F_105 ( V_747 ) ;
if ( V_433 < 0 )
return V_433 ;
* V_743 += V_741 ;
return V_741 ;
}
static int F_324 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_567 * V_502 ;
struct V_68 * V_748 = & V_21 -> V_414 . V_748 ;
struct V_503 * V_503 ;
if ( ! V_21 )
return - V_371 ;
F_24 (connector, connector_list, head) {
if ( V_502 -> V_749 !=
V_750 )
continue;
if ( V_502 -> V_433 == V_568 &&
V_502 -> V_500 != NULL ) {
V_503 = F_222 ( V_502 -> V_500 ) ;
if ( V_503 -> V_751 )
F_26 ( V_17 , L_443 ) ;
else
F_26 ( V_17 , L_444 ) ;
} else
F_26 ( V_17 , L_444 ) ;
}
return 0 ;
}
static int F_325 ( struct V_198 * V_198 ,
struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_283 ( V_111 , F_324 , V_21 ) ;
}
static int F_326 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_567 * V_502 ;
struct V_68 * V_748 = & V_21 -> V_414 . V_748 ;
struct V_503 * V_503 ;
if ( ! V_21 )
return - V_371 ;
F_24 (connector, connector_list, head) {
if ( V_502 -> V_749 !=
V_750 )
continue;
if ( V_502 -> V_433 == V_568 &&
V_502 -> V_500 != NULL ) {
V_503 = F_222 ( V_502 -> V_500 ) ;
F_10 ( V_17 , L_445 , V_503 -> V_752 ) ;
} else
F_26 ( V_17 , L_444 ) ;
}
return 0 ;
}
static int F_327 ( struct V_198 * V_198 ,
struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_283 ( V_111 , F_326 , V_21 ) ;
}
static int F_328 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_567 * V_502 ;
struct V_68 * V_748 = & V_21 -> V_414 . V_748 ;
struct V_503 * V_503 ;
if ( ! V_21 )
return - V_371 ;
F_24 (connector, connector_list, head) {
if ( V_502 -> V_749 !=
V_750 )
continue;
if ( V_502 -> V_433 == V_568 &&
V_502 -> V_500 != NULL ) {
V_503 = F_222 ( V_502 -> V_500 ) ;
F_10 ( V_17 , L_446 , V_503 -> V_753 ) ;
} else
F_26 ( V_17 , L_444 ) ;
}
return 0 ;
}
static int F_329 ( struct V_198 * V_198 ,
struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
return F_283 ( V_111 , F_328 , V_21 ) ;
}
static void F_330 ( struct V_16 * V_17 , const T_13 V_629 [ 8 ] )
{
struct V_20 * V_21 = V_17 -> V_19 ;
int V_754 = F_331 ( V_21 ) + 1 ;
int V_755 ;
F_151 ( V_21 ) ;
for ( V_755 = 0 ; V_755 < V_754 ; V_755 ++ ) {
unsigned int V_756 = V_629 [ V_755 ] ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_756 *= 10 ;
else if ( V_755 > 0 )
V_756 *= 5 ;
F_10 ( V_17 , L_447 ,
V_755 , V_629 [ V_755 ] , V_756 / 10 , V_756 % 10 ) ;
}
F_152 ( V_21 ) ;
}
static int F_332 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_32 * V_33 = V_21 -> V_70 ;
const T_13 * V_757 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_757 = V_33 -> V_629 . V_758 ;
else
V_757 = F_20 ( V_21 ) -> V_629 . V_759 ;
F_330 ( V_17 , V_757 ) ;
return 0 ;
}
static int F_333 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_32 * V_33 = V_21 -> V_70 ;
const T_13 * V_757 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_757 = V_33 -> V_629 . V_758 ;
else
V_757 = F_20 ( V_21 ) -> V_629 . V_760 ;
F_330 ( V_17 , V_757 ) ;
return 0 ;
}
static int F_334 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_32 * V_33 = V_21 -> V_70 ;
const T_13 * V_757 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_757 = V_33 -> V_629 . V_758 ;
else
V_757 = F_20 ( V_21 ) -> V_629 . V_761 ;
F_330 ( V_17 , V_757 ) ;
return 0 ;
}
static int F_335 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
if ( F_336 ( V_21 ) )
return - V_371 ;
return F_283 ( V_111 , F_332 , V_21 ) ;
}
static int F_337 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
if ( F_336 ( V_21 ) )
return - V_371 ;
return F_283 ( V_111 , F_333 , V_21 ) ;
}
static int F_338 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
if ( F_336 ( V_21 ) )
return - V_371 ;
return F_283 ( V_111 , F_334 , V_21 ) ;
}
static T_5 F_339 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_3 V_741 , T_7 * V_743 , T_13 V_629 [ 8 ] )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
T_13 V_762 [ 8 ] = { 0 } ;
int V_754 = F_331 ( V_21 ) + 1 ;
int V_755 ;
int V_76 ;
char V_703 [ 32 ] ;
if ( V_741 >= sizeof( V_703 ) )
return - V_82 ;
if ( F_321 ( V_703 , V_192 , V_741 ) )
return - V_675 ;
V_703 [ V_741 ] = '\0' ;
V_76 = sscanf ( V_703 , L_448 ,
& V_762 [ 0 ] , & V_762 [ 1 ] , & V_762 [ 2 ] , & V_762 [ 3 ] ,
& V_762 [ 4 ] , & V_762 [ 5 ] , & V_762 [ 6 ] , & V_762 [ 7 ] ) ;
if ( V_76 != V_754 )
return - V_82 ;
F_151 ( V_21 ) ;
for ( V_755 = 0 ; V_755 < V_754 ; V_755 ++ )
V_629 [ V_755 ] = V_762 [ V_755 ] ;
F_152 ( V_21 ) ;
return V_741 ;
}
static T_5 F_340 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_3 V_741 , T_7 * V_743 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_13 * V_757 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_757 = V_33 -> V_629 . V_758 ;
else
V_757 = F_20 ( V_21 ) -> V_629 . V_759 ;
return F_339 ( V_111 , V_192 , V_741 , V_743 , V_757 ) ;
}
static T_5 F_341 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_3 V_741 , T_7 * V_743 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_13 * V_757 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_757 = V_33 -> V_629 . V_758 ;
else
V_757 = F_20 ( V_21 ) -> V_629 . V_760 ;
return F_339 ( V_111 , V_192 , V_741 , V_743 , V_757 ) ;
}
static T_5 F_342 ( struct V_111 * V_111 , const char T_6 * V_192 ,
T_3 V_741 , T_7 * V_743 )
{
struct V_16 * V_17 = V_111 -> V_197 ;
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_13 * V_757 ;
if ( F_9 ( V_21 ) -> V_24 >= 9 )
V_757 = V_33 -> V_629 . V_758 ;
else
V_757 = F_20 ( V_21 ) -> V_629 . V_761 ;
return F_339 ( V_111 , V_192 , V_741 , V_743 , V_757 ) ;
}
static int
F_343 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
* V_209 = F_66 ( & V_33 -> V_284 . V_763 ) ;
return 0 ;
}
static int
F_344 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
if ( F_345 ( & V_33 -> V_284 ) )
return - V_670 ;
F_78 ( V_33 ) ;
F_346 ( V_21 , V_209 ,
L_449 , V_209 ) ;
F_79 ( V_33 ) ;
return 0 ;
}
static int
F_347 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
* V_209 = V_33 -> V_284 . V_764 ;
return 0 ;
}
static int
F_348 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
F_98 ( L_450 , V_209 ) ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_33 -> V_284 . V_764 = V_209 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_349 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
* V_209 = V_33 -> V_284 . V_765 ;
return 0 ;
}
static int
F_350 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_33 -> V_284 . V_765 = V_209 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_351 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
* V_209 = V_33 -> V_284 . V_766 ;
return 0 ;
}
static int
F_352 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
F_98 ( L_451 , V_209 ) ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
V_33 -> V_284 . V_766 = V_209 ;
F_7 ( & V_21 -> V_77 ) ;
return 0 ;
}
static int
F_353 ( void * V_18 , T_8 * V_209 )
{
* V_209 = V_767 ;
return 0 ;
}
static int
F_354 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
F_355 ( L_452 , V_209 ) ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
if ( V_209 & V_768 ) {
V_76 = F_356 ( V_21 ) ;
if ( V_76 )
goto V_769;
}
if ( V_209 & ( V_770 | V_768 ) )
F_357 ( V_21 ) ;
if ( V_209 & V_771 )
F_358 ( V_33 , V_772 , V_773 ) ;
if ( V_209 & V_774 )
F_358 ( V_33 , V_772 , V_775 ) ;
V_769:
F_7 ( & V_21 -> V_77 ) ;
return V_76 ;
}
static int
F_359 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_371 ;
F_115 ( & V_33 -> V_211 . V_212 ) ;
V_76 = F_31 ( & V_33 -> V_211 . V_277 ) ;
if ( V_76 )
return V_76 ;
* V_209 = F_124 ( V_33 , V_33 -> V_211 . V_396 ) ;
F_7 ( & V_33 -> V_211 . V_277 ) ;
return 0 ;
}
static int
F_360 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_776 , V_777 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_371 ;
F_115 ( & V_33 -> V_211 . V_212 ) ;
F_98 ( L_453 , V_209 ) ;
V_76 = F_31 ( & V_33 -> V_211 . V_277 ) ;
if ( V_76 )
return V_76 ;
V_209 = F_361 ( V_33 , V_209 ) ;
V_776 = V_33 -> V_211 . V_244 ;
V_777 = V_33 -> V_211 . V_274 ;
if ( V_209 < V_777 || V_209 > V_776 || V_209 < V_33 -> V_211 . V_395 ) {
F_7 ( & V_33 -> V_211 . V_277 ) ;
return - V_82 ;
}
V_33 -> V_211 . V_396 = V_209 ;
F_362 ( V_21 , V_209 ) ;
F_7 ( & V_33 -> V_211 . V_277 ) ;
return 0 ;
}
static int
F_363 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_371 ;
F_115 ( & V_33 -> V_211 . V_212 ) ;
V_76 = F_31 ( & V_33 -> V_211 . V_277 ) ;
if ( V_76 )
return V_76 ;
* V_209 = F_124 ( V_33 , V_33 -> V_211 . V_395 ) ;
F_7 ( & V_33 -> V_211 . V_277 ) ;
return 0 ;
}
static int
F_364 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_776 , V_777 ;
int V_76 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_371 ;
F_115 ( & V_33 -> V_211 . V_212 ) ;
F_98 ( L_454 , V_209 ) ;
V_76 = F_31 ( & V_33 -> V_211 . V_277 ) ;
if ( V_76 )
return V_76 ;
V_209 = F_361 ( V_33 , V_209 ) ;
V_776 = V_33 -> V_211 . V_244 ;
V_777 = V_33 -> V_211 . V_274 ;
if ( V_209 < V_777 || V_209 > V_776 || V_209 > V_33 -> V_211 . V_396 ) {
F_7 ( & V_33 -> V_211 . V_277 ) ;
return - V_82 ;
}
V_33 -> V_211 . V_395 = V_209 ;
F_362 ( V_21 , V_209 ) ;
F_7 ( & V_33 -> V_211 . V_277 ) ;
return 0 ;
}
static int
F_365 ( void * V_18 , T_8 * V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_778 ;
int V_76 ;
if ( ! ( F_118 ( V_21 ) || F_119 ( V_21 ) ) )
return - V_371 ;
V_76 = F_31 ( & V_21 -> V_77 ) ;
if ( V_76 )
return V_76 ;
F_78 ( V_33 ) ;
V_778 = F_70 ( V_779 ) ;
F_79 ( V_33 ) ;
F_7 ( & V_33 -> V_21 -> V_77 ) ;
* V_209 = ( V_778 & V_780 ) >> V_781 ;
return 0 ;
}
static int
F_366 ( void * V_18 , T_8 V_209 )
{
struct V_20 * V_21 = V_18 ;
struct V_32 * V_33 = V_21 -> V_70 ;
T_4 V_778 ;
if ( ! ( F_118 ( V_21 ) || F_119 ( V_21 ) ) )
return - V_371 ;
if ( V_209 > 3 )
return - V_82 ;
F_78 ( V_33 ) ;
F_98 ( L_455 , V_209 ) ;
V_778 = F_70 ( V_779 ) ;
V_778 &= ~ V_780 ;
V_778 |= ( V_209 << V_781 ) ;
F_154 ( V_779 , V_778 ) ;
F_79 ( V_33 ) ;
return 0 ;
}
static void F_367 ( struct V_20 * V_21 ,
struct V_782 * V_489 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
const int V_783 = 2 ;
int V_784 ;
T_4 V_785 [ V_783 ] , V_786 [ V_783 ] ;
V_785 [ 0 ] = F_70 ( V_787 ) ;
V_785 [ 1 ] = F_70 ( V_788 ) ;
V_786 [ 0 ] = F_70 ( V_789 ) ;
V_786 [ 1 ] = F_70 ( V_790 ) ;
for ( V_784 = 0 ; V_784 < V_783 ; V_784 ++ ) {
unsigned int V_791 ;
if ( V_785 [ V_784 ] & V_792 )
continue;
V_489 -> V_793 = 1 ;
V_489 -> V_794 ++ ;
V_791 = ( ( V_785 [ V_784 ] & V_795 ) ? 0 : 2 ) +
( ( V_785 [ V_784 ] & V_796 ) ? 0 : 2 ) +
( ( V_785 [ V_784 ] & V_797 ) ? 0 : 2 ) +
( ( V_786 [ V_784 ] & V_798 ) ? 0 : 2 ) ;
V_489 -> V_799 += V_791 ;
V_489 -> V_800 = F_368 ( V_489 -> V_800 , V_791 ) ;
}
V_489 -> V_801 = V_489 -> V_794 ;
}
static void F_369 ( struct V_20 * V_21 ,
struct V_782 * V_489 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
int V_802 = 3 , V_783 = 4 ;
int V_60 , V_784 ;
T_4 V_803 [ V_802 ] , V_804 [ 2 * V_802 ] , V_805 [ 2 ] ;
if ( F_370 ( V_21 ) ) {
V_802 = 1 ;
V_783 = 3 ;
}
for ( V_60 = 0 ; V_60 < V_802 ; V_60 ++ ) {
V_803 [ V_60 ] = F_70 ( F_371 ( V_60 ) ) ;
V_804 [ 2 * V_60 ] = F_70 ( F_372 ( V_60 ) ) ;
V_804 [ 2 * V_60 + 1 ] = F_70 ( F_373 ( V_60 ) ) ;
}
V_805 [ 0 ] = V_806 |
V_807 |
V_808 |
V_809 ;
V_805 [ 1 ] = V_810 |
V_811 |
V_812 |
V_813 ;
for ( V_60 = 0 ; V_60 < V_802 ; V_60 ++ ) {
unsigned int V_814 = 0 ;
if ( ( V_803 [ V_60 ] & V_815 ) == 0 )
continue;
V_489 -> V_793 ++ ;
if ( F_127 ( V_21 ) )
V_814 = F_9 ( V_21 ) -> V_794 ;
for ( V_784 = 0 ; V_784 < V_783 ; V_784 ++ ) {
unsigned int V_791 ;
if ( F_370 ( V_21 ) &&
! ( V_803 [ V_60 ] & ( F_374 ( V_784 ) ) ) )
continue;
if ( F_370 ( V_21 ) )
V_814 ++ ;
V_791 = 2 * F_254 ( V_804 [ 2 * V_60 + V_784 / 2 ] &
V_805 [ V_784 % 2 ] ) ;
V_489 -> V_799 += V_791 ;
V_489 -> V_800 = F_368 ( V_489 -> V_800 ,
V_791 ) ;
}
V_489 -> V_801 += V_814 ;
V_489 -> V_794 = F_368 ( V_489 -> V_794 ,
V_814 ) ;
}
}
static int F_375 ( struct V_16 * V_17 , void * V_210 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_782 V_489 ;
if ( ( F_9 ( V_21 ) -> V_24 < 8 ) || F_120 ( V_21 ) )
return - V_371 ;
F_26 ( V_17 , L_456 ) ;
F_10 ( V_17 , L_457 ,
F_9 ( V_21 ) -> V_793 ) ;
F_10 ( V_17 , L_458 ,
F_9 ( V_21 ) -> V_801 ) ;
F_10 ( V_17 , L_459 ,
F_9 ( V_21 ) -> V_794 ) ;
F_10 ( V_17 , L_460 ,
F_9 ( V_21 ) -> V_799 ) ;
F_10 ( V_17 , L_461 ,
F_9 ( V_21 ) -> V_800 ) ;
F_10 ( V_17 , L_462 ,
F_1 ( F_9 ( V_21 ) -> V_816 ) ) ;
F_10 ( V_17 , L_463 ,
F_1 ( F_9 ( V_21 ) -> V_817 ) ) ;
F_10 ( V_17 , L_464 ,
F_1 ( F_9 ( V_21 ) -> V_818 ) ) ;
F_26 ( V_17 , L_465 ) ;
memset ( & V_489 , 0 , sizeof( V_489 ) ) ;
if ( F_81 ( V_21 ) ) {
F_367 ( V_21 , & V_489 ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 9 ) {
F_369 ( V_21 , & V_489 ) ;
}
F_10 ( V_17 , L_466 ,
V_489 . V_793 ) ;
F_10 ( V_17 , L_467 ,
V_489 . V_801 ) ;
F_10 ( V_17 , L_468 ,
V_489 . V_794 ) ;
F_10 ( V_17 , L_469 ,
V_489 . V_799 ) ;
F_10 ( V_17 , L_470 ,
V_489 . V_800 ) ;
return 0 ;
}
static int F_376 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
struct V_32 * V_33 = V_21 -> V_70 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_78 ( V_33 ) ;
F_122 ( V_33 , V_245 ) ;
return 0 ;
}
static int F_377 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
struct V_20 * V_21 = V_198 -> V_199 ;
struct V_32 * V_33 = V_21 -> V_70 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_125 ( V_33 , V_245 ) ;
F_79 ( V_33 ) ;
return 0 ;
}
static int F_378 ( struct V_4 * V_676 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_278 ( L_471 ,
V_819 ,
V_676 , V_21 ,
& V_820 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_820 ) ;
}
static int F_379 ( struct V_4 * V_676 ,
struct V_2 * V_3 ,
const char * V_52 ,
const struct V_821 * V_822 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_278 ( V_52 ,
V_678 | V_823 ,
V_676 , V_21 ,
V_822 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_822 ) ;
}
void F_380 ( struct V_20 * V_21 )
{
struct V_32 * V_33 = V_21 -> V_70 ;
enum V_129 V_129 ;
F_82 (dev_priv, pipe) {
struct V_655 * V_656 = & V_33 -> V_656 [ V_129 ] ;
V_656 -> V_658 = false ;
F_381 ( & V_656 -> V_320 ) ;
F_382 ( & V_656 -> V_671 ) ;
}
}
int F_383 ( struct V_2 * V_3 )
{
int V_76 , V_40 ;
V_76 = F_378 ( V_3 -> V_824 , V_3 ) ;
if ( V_76 )
return V_76 ;
for ( V_40 = 0 ; V_40 < F_47 ( V_677 ) ; V_40 ++ ) {
V_76 = F_277 ( V_3 -> V_824 , V_3 , V_40 ) ;
if ( V_76 )
return V_76 ;
}
for ( V_40 = 0 ; V_40 < F_47 ( V_825 ) ; V_40 ++ ) {
V_76 = F_379 ( V_3 -> V_824 , V_3 ,
V_825 [ V_40 ] . V_52 ,
V_825 [ V_40 ] . V_822 ) ;
if ( V_76 )
return V_76 ;
}
return F_384 ( V_826 ,
V_827 ,
V_3 -> V_824 , V_3 ) ;
}
void F_385 ( struct V_2 * V_3 )
{
int V_40 ;
F_386 ( V_826 ,
V_827 , V_3 ) ;
F_386 ( (struct V_828 * ) & V_820 ,
1 , V_3 ) ;
for ( V_40 = 0 ; V_40 < F_47 ( V_677 ) ; V_40 ++ ) {
struct V_828 * V_829 =
(struct V_828 * ) & V_677 [ V_40 ] ;
F_386 ( V_829 , 1 , V_3 ) ;
}
for ( V_40 = 0 ; V_40 < F_47 ( V_825 ) ; V_40 ++ ) {
struct V_828 * V_829 =
(struct V_828 * ) V_825 [ V_40 ] . V_822 ;
F_386 ( V_829 , 1 , V_3 ) ;
}
}
static int F_387 ( struct V_16 * V_17 , void * V_18 )
{
struct V_567 * V_502 = V_17 -> V_19 ;
struct V_503 * V_503 =
F_222 ( & F_388 ( V_502 ) -> V_34 ) ;
T_14 V_207 [ 16 ] ;
T_5 V_830 ;
int V_40 ;
if ( V_502 -> V_433 != V_568 )
return - V_371 ;
for ( V_40 = 0 ; V_40 < F_47 ( V_831 ) ; V_40 ++ ) {
const struct V_832 * V_88 = & V_831 [ V_40 ] ;
T_3 V_42 = V_88 -> V_631 ? V_88 -> V_631 - V_88 -> V_470 + 1 : ( V_88 -> V_42 ? : 1 ) ;
if ( V_88 -> V_833 &&
V_502 -> V_749 != V_834 )
continue;
if ( F_182 ( V_42 > sizeof( V_207 ) ) )
continue;
V_830 = F_389 ( & V_503 -> V_835 , V_88 -> V_470 , V_207 , V_42 ) ;
if ( V_830 <= 0 ) {
F_390 ( L_472 ,
V_42 , V_88 -> V_470 , V_830 ) ;
continue;
}
F_10 ( V_17 , L_473 , V_88 -> V_470 , ( int ) V_42 , V_207 ) ;
}
return 0 ;
}
static int F_391 ( struct V_198 * V_198 , struct V_111 * V_111 )
{
return F_283 ( V_111 , F_387 , V_198 -> V_199 ) ;
}
int F_392 ( struct V_567 * V_502 )
{
struct V_4 * V_676 = V_502 -> V_836 ;
if ( ! V_676 )
return - V_371 ;
if ( V_502 -> V_749 == V_750 ||
V_502 -> V_749 == V_834 )
F_278 ( L_474 , V_678 , V_676 , V_502 ,
& V_837 ) ;
return 0 ;
}
