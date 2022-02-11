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
if ( V_26 -> V_27 > 0 )
return L_5 ;
else if ( F_16 ( V_26 ) )
return L_6 ;
else
return L_7 ;
}
static const char * F_17 ( struct V_25 * V_26 )
{
switch ( V_26 -> V_28 ) {
default:
case V_29 : return L_7 ;
case V_30 : return L_8 ;
case V_31 : return L_9 ;
}
}
static inline const char * F_18 ( struct V_25 * V_26 )
{
return V_26 -> V_32 ? L_10 : L_7 ;
}
static void
F_19 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
struct V_33 * V_34 ;
int V_35 = 0 ;
F_10 ( V_17 , L_11 ,
& V_26 -> V_36 ,
F_15 ( V_26 ) ,
F_17 ( V_26 ) ,
F_18 ( V_26 ) ,
V_26 -> V_36 . V_37 / 1024 ,
V_26 -> V_36 . V_38 ,
V_26 -> V_36 . V_39 ,
V_26 -> V_40 ,
V_26 -> V_41 ,
V_26 -> V_42 ,
F_20 ( V_26 -> V_43 ) ,
V_26 -> V_44 ? L_12 : L_13 ,
V_26 -> V_45 == V_46 ? L_14 : L_13 ) ;
if ( V_26 -> V_36 . V_47 )
F_10 ( V_17 , L_15 , V_26 -> V_36 . V_47 ) ;
F_21 (vma, &obj->vma_list, vma_link)
if ( V_34 -> V_35 > 0 )
V_35 ++ ;
F_10 ( V_17 , L_16 , V_35 ) ;
if ( V_26 -> V_48 )
F_10 ( V_17 , L_17 ) ;
if ( V_26 -> V_49 != V_50 )
F_10 ( V_17 , L_18 , V_26 -> V_49 ) ;
F_21 (vma, &obj->vma_list, vma_link) {
if ( ! F_22 ( V_34 -> V_51 ) )
F_23 ( V_17 , L_19 ) ;
else
F_23 ( V_17 , L_20 ) ;
F_10 ( V_17 , L_21 ,
V_34 -> V_8 . V_52 , V_34 -> V_8 . V_37 ) ;
}
if ( V_26 -> V_53 )
F_10 ( V_17 , L_22 , V_26 -> V_53 -> V_52 ) ;
if ( V_26 -> V_54 || V_26 -> V_55 ) {
char V_56 [ 3 ] , * V_57 = V_56 ;
if ( V_26 -> V_54 )
* V_57 ++ = 'p' ;
if ( V_26 -> V_55 )
* V_57 ++ = 'f' ;
* V_57 = '\0' ;
F_10 ( V_17 , L_23 , V_56 ) ;
}
if ( V_26 -> V_58 != NULL )
F_10 ( V_17 , L_24 , V_26 -> V_58 -> V_47 ) ;
}
static void F_24 ( struct V_16 * V_17 , struct V_59 * V_60 )
{
F_25 ( V_17 , V_60 -> V_61 ? 'I' : 'i' ) ;
F_25 ( V_17 , V_60 -> V_62 ? 'R' : 'r' ) ;
F_25 ( V_17 , ' ' ) ;
}
static int F_26 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_63 * V_64 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_68 * V_51 = & V_66 -> V_69 . V_36 ;
struct V_33 * V_34 ;
T_3 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
switch ( V_14 ) {
case V_75 :
F_23 ( V_17 , L_25 ) ;
V_64 = & V_51 -> V_76 ;
break;
case V_77 :
F_23 ( V_17 , L_26 ) ;
V_64 = & V_51 -> V_78 ;
break;
default:
F_7 ( & V_21 -> V_74 ) ;
return - V_79 ;
}
V_70 = V_71 = V_72 = 0 ;
F_21 (vma, head, mm_list) {
F_10 ( V_17 , L_27 ) ;
F_19 ( V_17 , V_34 -> V_26 ) ;
F_10 ( V_17 , L_28 ) ;
V_70 += V_34 -> V_26 -> V_36 . V_37 ;
V_71 += V_34 -> V_8 . V_37 ;
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_28 ( void * V_80 ,
struct V_63 * V_81 , struct V_63 * V_82 )
{
struct V_25 * V_83 =
F_29 ( V_81 , struct V_25 , V_84 ) ;
struct V_25 * V_85 =
F_29 ( V_82 , struct V_25 , V_84 ) ;
return V_83 -> V_53 -> V_52 - V_85 -> V_53 -> V_52 ;
}
static int F_30 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 ;
T_3 V_70 , V_71 ;
F_31 ( V_53 ) ;
int V_72 , V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_70 = V_71 = V_72 = 0 ;
F_21 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_53 == NULL )
continue;
F_6 ( & V_26 -> V_84 , & V_53 ) ;
V_70 += V_26 -> V_36 . V_37 ;
V_71 += F_32 ( V_26 ) ;
V_72 ++ ;
}
F_21 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_26 -> V_53 == NULL )
continue;
F_6 ( & V_26 -> V_84 , & V_53 ) ;
V_70 += V_26 -> V_36 . V_37 ;
V_72 ++ ;
}
F_33 ( NULL , & V_53 , F_28 ) ;
F_23 ( V_17 , L_30 ) ;
while ( ! F_34 ( & V_53 ) ) {
V_26 = F_35 ( & V_53 , F_36 ( * V_26 ) , V_84 ) ;
F_23 ( V_17 , L_27 ) ;
F_19 ( V_17 , V_26 ) ;
F_25 ( V_17 , '\n' ) ;
F_37 ( & V_26 -> V_84 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_38 ( int V_86 , void * V_87 , void * V_18 )
{
struct V_25 * V_26 = V_87 ;
struct V_88 * V_89 = V_18 ;
struct V_33 * V_34 ;
V_89 -> V_72 ++ ;
V_89 -> V_90 += V_26 -> V_36 . V_37 ;
if ( V_26 -> V_36 . V_47 || V_26 -> V_36 . V_91 )
V_89 -> V_92 += V_26 -> V_36 . V_37 ;
if ( F_39 ( V_26 -> V_36 . V_21 ) ) {
F_21 (vma, &obj->vma_list, vma_link) {
struct V_93 * V_94 ;
if ( ! F_40 ( & V_34 -> V_8 ) )
continue;
if ( F_22 ( V_34 -> V_51 ) ) {
V_89 -> V_95 += V_26 -> V_36 . V_37 ;
continue;
}
V_94 = F_29 ( V_34 -> V_51 , struct V_93 , V_36 ) ;
if ( V_94 -> V_60 && V_94 -> V_60 -> V_96 != V_89 -> V_96 )
continue;
if ( V_26 -> V_58 )
V_89 -> V_97 += V_26 -> V_36 . V_37 ;
else
V_89 -> V_98 += V_26 -> V_36 . V_37 ;
return 0 ;
}
} else {
if ( F_41 ( V_26 ) ) {
V_89 -> V_95 += V_26 -> V_36 . V_37 ;
if ( V_26 -> V_58 )
V_89 -> V_97 += V_26 -> V_36 . V_37 ;
else
V_89 -> V_98 += V_26 -> V_36 . V_37 ;
return 0 ;
}
}
if ( ! F_34 ( & V_26 -> V_99 ) )
V_89 -> V_100 += V_26 -> V_36 . V_37 ;
return 0 ;
}
static int F_42 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_72 , V_101 , V_102 ;
T_3 V_37 , V_103 , V_104 ;
struct V_25 * V_26 ;
struct V_68 * V_51 = & V_66 -> V_69 . V_36 ;
struct V_105 * V_106 ;
struct V_33 * V_34 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_31 ,
V_66 -> V_107 . V_108 ,
V_66 -> V_107 . V_109 ) ;
V_37 = V_72 = V_103 = V_101 = 0 ;
F_43 ( & V_66 -> V_107 . V_110 , V_99 ) ;
F_10 ( V_17 , L_32 ,
V_72 , V_101 , V_37 , V_103 ) ;
V_37 = V_72 = V_103 = V_101 = 0 ;
F_44 ( & V_51 -> V_76 , V_111 ) ;
F_10 ( V_17 , L_33 ,
V_72 , V_101 , V_37 , V_103 ) ;
V_37 = V_72 = V_103 = V_101 = 0 ;
F_44 ( & V_51 -> V_78 , V_111 ) ;
F_10 ( V_17 , L_34 ,
V_72 , V_101 , V_37 , V_103 ) ;
V_37 = V_72 = V_104 = V_102 = 0 ;
F_21 (obj, &dev_priv->mm.unbound_list, global_list) {
V_37 += V_26 -> V_36 . V_37 , ++ V_72 ;
if ( V_26 -> V_45 == V_46 )
V_104 += V_26 -> V_36 . V_37 , ++ V_102 ;
}
F_10 ( V_17 , L_35 , V_72 , V_37 ) ;
V_37 = V_72 = V_103 = V_101 = 0 ;
F_21 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_55 ) {
V_37 += F_32 ( V_26 ) ;
++ V_72 ;
}
if ( V_26 -> V_54 ) {
V_103 += F_32 ( V_26 ) ;
++ V_101 ;
}
if ( V_26 -> V_45 == V_46 ) {
V_104 += V_26 -> V_36 . V_37 ;
++ V_102 ;
}
}
F_10 ( V_17 , L_36 ,
V_102 , V_104 ) ;
F_10 ( V_17 , L_37 ,
V_101 , V_103 ) ;
F_10 ( V_17 , L_38 ,
V_72 , V_37 ) ;
F_10 ( V_17 , L_39 ,
V_66 -> V_69 . V_36 . V_90 ,
V_66 -> V_69 . V_112 - V_66 -> V_69 . V_36 . V_52 ) ;
F_25 ( V_17 , '\n' ) ;
F_45 (file, &dev->filelist, lhead) {
struct V_88 V_89 ;
struct V_113 * V_114 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_96 = V_106 -> V_115 ;
F_46 ( & V_106 -> V_116 ) ;
F_47 ( & V_106 -> V_117 , F_38 , & V_89 ) ;
F_48 ( & V_106 -> V_116 ) ;
F_49 () ;
V_114 = F_50 ( V_106 -> V_118 , V_119 ) ;
F_10 ( V_17 , L_40 ,
V_114 ? V_114 -> V_120 : L_41 ,
V_89 . V_72 ,
V_89 . V_90 ,
V_89 . V_97 ,
V_89 . V_98 ,
V_89 . V_95 ,
V_89 . V_92 ,
V_89 . V_100 ) ;
F_51 () ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_52 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 ;
T_3 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_70 = V_71 = V_72 = 0 ;
F_21 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_14 == V_121 && ! F_16 ( V_26 ) )
continue;
F_23 ( V_17 , L_27 ) ;
F_19 ( V_17 , V_26 ) ;
F_25 ( V_17 , '\n' ) ;
V_70 += V_26 -> V_36 . V_37 ;
V_71 += F_32 ( V_26 ) ;
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
unsigned long V_122 ;
struct V_123 * V_124 ;
F_54 (dev, crtc) {
const char V_125 = F_55 ( V_124 -> V_125 ) ;
const char V_126 = F_56 ( V_124 -> V_126 ) ;
struct V_127 * V_128 ;
F_57 ( & V_21 -> V_129 , V_122 ) ;
V_128 = V_124 -> V_130 ;
if ( V_128 == NULL ) {
F_10 ( V_17 , L_42 ,
V_125 , V_126 ) ;
} else {
if ( F_58 ( & V_128 -> V_131 ) < V_132 ) {
F_10 ( V_17 , L_43 ,
V_125 , V_126 ) ;
} else {
F_10 ( V_17 , L_44 ,
V_125 , V_126 ) ;
}
if ( V_128 -> V_133 )
F_23 ( V_17 , L_45 ) ;
else
F_23 ( V_17 , L_46 ) ;
F_10 ( V_17 , L_47 , F_58 ( & V_128 -> V_131 ) ) ;
if ( V_128 -> V_134 ) {
struct V_25 * V_26 = V_128 -> V_134 ;
if ( V_26 )
F_10 ( V_17 , L_48 ,
F_59 ( V_26 ) ) ;
}
if ( V_128 -> V_135 ) {
struct V_25 * V_26 = V_128 -> V_135 ;
if ( V_26 )
F_10 ( V_17 , L_49 ,
F_59 ( V_26 ) ) ;
}
}
F_60 ( & V_21 -> V_129 , V_122 ) ;
}
return 0 ;
}
static int F_61 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_136 * V_58 ;
struct V_137 * V_138 ;
int V_73 , V_72 , V_139 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_72 = 0 ;
F_62 (ring, dev_priv, i) {
if ( F_34 ( & V_58 -> V_140 ) )
continue;
F_10 ( V_17 , L_50 , V_58 -> V_47 ) ;
F_21 (gem_request,
&ring->request_list,
list) {
F_10 ( V_17 , L_51 ,
V_138 -> V_141 ,
( int ) ( V_142 - V_138 -> V_143 ) ) ;
}
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
if ( V_72 == 0 )
F_23 ( V_17 , L_52 ) ;
return 0 ;
}
static void F_63 ( struct V_16 * V_17 ,
struct V_136 * V_58 )
{
if ( V_58 -> V_144 ) {
F_10 ( V_17 , L_53 ,
V_58 -> V_47 , V_58 -> V_144 ( V_58 , false ) ) ;
}
}
static int F_64 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_136 * V_58 ;
int V_73 , V_139 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
F_62 (ring, dev_priv, i)
F_63 ( V_17 , V_58 ) ;
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_67 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_136 * V_58 ;
int V_73 , V_139 , V_125 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
if ( F_68 ( V_21 ) ) {
int V_139 ;
F_10 ( V_17 , L_54 ,
F_69 ( V_145 ) ) ;
F_10 ( V_17 , L_55 ,
F_69 ( V_146 ) ) ;
F_10 ( V_17 , L_56 ,
F_69 ( V_147 ) ) ;
F_10 ( V_17 , L_57 ,
F_69 ( V_148 ) ) ;
F_10 ( V_17 , L_58 ,
F_69 ( V_149 ) ) ;
F_70 (pipe)
F_10 ( V_17 , L_59 ,
F_55 ( V_125 ) ,
F_69 ( F_71 ( V_125 ) ) ) ;
F_10 ( V_17 , L_60 ,
F_69 ( V_150 ) ) ;
F_10 ( V_17 , L_61 ,
F_69 ( V_151 ) ) ;
F_10 ( V_17 , L_62 ,
F_69 ( V_152 ) ) ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
F_10 ( V_17 , L_63 ,
V_139 , F_69 ( F_72 ( V_139 ) ) ) ;
F_10 ( V_17 , L_64 ,
V_139 , F_69 ( F_73 ( V_139 ) ) ) ;
F_10 ( V_17 , L_65 ,
V_139 , F_69 ( F_74 ( V_139 ) ) ) ;
}
F_10 ( V_17 , L_66 ,
F_69 ( V_153 ) ) ;
F_10 ( V_17 , L_67 ,
F_69 ( V_154 ) ) ;
F_10 ( V_17 , L_68 ,
F_69 ( V_155 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_10 ( V_17 , L_54 ,
F_69 ( V_145 ) ) ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
F_10 ( V_17 , L_63 ,
V_139 , F_69 ( F_72 ( V_139 ) ) ) ;
F_10 ( V_17 , L_64 ,
V_139 , F_69 ( F_73 ( V_139 ) ) ) ;
F_10 ( V_17 , L_65 ,
V_139 , F_69 ( F_74 ( V_139 ) ) ) ;
}
F_70 (pipe) {
F_10 ( V_17 , L_69 ,
F_55 ( V_125 ) ,
F_69 ( F_75 ( V_125 ) ) ) ;
F_10 ( V_17 , L_70 ,
F_55 ( V_125 ) ,
F_69 ( F_76 ( V_125 ) ) ) ;
F_10 ( V_17 , L_71 ,
F_55 ( V_125 ) ,
F_69 ( F_77 ( V_125 ) ) ) ;
}
F_10 ( V_17 , L_72 ,
F_69 ( V_156 ) ) ;
F_10 ( V_17 , L_73 ,
F_69 ( V_157 ) ) ;
F_10 ( V_17 , L_74 ,
F_69 ( V_158 ) ) ;
F_10 ( V_17 , L_75 ,
F_69 ( V_159 ) ) ;
F_10 ( V_17 , L_76 ,
F_69 ( V_160 ) ) ;
F_10 ( V_17 , L_77 ,
F_69 ( V_161 ) ) ;
F_10 ( V_17 , L_66 ,
F_69 ( V_153 ) ) ;
F_10 ( V_17 , L_67 ,
F_69 ( V_154 ) ) ;
F_10 ( V_17 , L_68 ,
F_69 ( V_155 ) ) ;
} else if ( F_78 ( V_21 ) ) {
F_10 ( V_17 , L_55 ,
F_69 ( V_146 ) ) ;
F_10 ( V_17 , L_56 ,
F_69 ( V_147 ) ) ;
F_10 ( V_17 , L_57 ,
F_69 ( V_148 ) ) ;
F_10 ( V_17 , L_58 ,
F_69 ( V_149 ) ) ;
F_70 (pipe)
F_10 ( V_17 , L_59 ,
F_55 ( V_125 ) ,
F_69 ( F_71 ( V_125 ) ) ) ;
F_10 ( V_17 , L_78 ,
F_69 ( V_162 ) ) ;
F_10 ( V_17 , L_79 ,
F_69 ( V_163 ) ) ;
F_10 ( V_17 , L_80 ,
F_69 ( V_164 ) ) ;
F_10 ( V_17 , L_81 ,
F_69 ( V_165 ) ) ;
F_10 ( V_17 , L_82 ,
F_69 ( V_166 ) ) ;
F_10 ( V_17 , L_83 ,
F_69 ( V_167 ) ) ;
F_10 ( V_17 , L_84 ,
F_69 ( V_168 ) ) ;
F_10 ( V_17 , L_60 ,
F_69 ( V_150 ) ) ;
F_10 ( V_17 , L_61 ,
F_69 ( V_151 ) ) ;
F_10 ( V_17 , L_62 ,
F_69 ( V_152 ) ) ;
} else if ( ! F_79 ( V_21 ) ) {
F_10 ( V_17 , L_85 ,
F_69 ( V_169 ) ) ;
F_10 ( V_17 , L_86 ,
F_69 ( V_170 ) ) ;
F_10 ( V_17 , L_87 ,
F_69 ( V_171 ) ) ;
F_70 (pipe)
F_10 ( V_17 , L_88 ,
F_55 ( V_125 ) ,
F_69 ( F_71 ( V_125 ) ) ) ;
} else {
F_10 ( V_17 , L_89 ,
F_69 ( V_172 ) ) ;
F_10 ( V_17 , L_90 ,
F_69 ( V_173 ) ) ;
F_10 ( V_17 , L_91 ,
F_69 ( V_174 ) ) ;
F_10 ( V_17 , L_92 ,
F_69 ( V_175 ) ) ;
F_10 ( V_17 , L_93 ,
F_69 ( V_176 ) ) ;
F_10 ( V_17 , L_94 ,
F_69 ( V_177 ) ) ;
F_10 ( V_17 , L_95 ,
F_69 ( V_163 ) ) ;
F_10 ( V_17 , L_96 ,
F_69 ( V_164 ) ) ;
F_10 ( V_17 , L_97 ,
F_69 ( V_165 ) ) ;
}
F_62 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_98 ,
V_58 -> V_47 , F_80 ( V_58 ) ) ;
}
F_63 ( V_17 , V_58 ) ;
}
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_81 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_139 , V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_99 , V_66 -> V_178 ) ;
F_10 ( V_17 , L_100 , V_66 -> V_179 ) ;
for ( V_139 = 0 ; V_139 < V_66 -> V_179 ; V_139 ++ ) {
struct V_25 * V_26 = V_66 -> V_180 [ V_139 ] . V_26 ;
F_10 ( V_17 , L_101 ,
V_139 , V_66 -> V_180 [ V_139 ] . V_35 ) ;
if ( V_26 == NULL )
F_23 ( V_17 , L_102 ) ;
else
F_19 ( V_17 , V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_82 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_136 * V_58 ;
const T_4 * V_181 ;
int V_139 ;
V_58 = & V_66 -> V_58 [ ( T_2 ) V_8 -> V_12 -> V_18 ] ;
V_181 = V_58 -> V_182 . V_183 ;
if ( V_181 == NULL )
return 0 ;
for ( V_139 = 0 ; V_139 < 4096 / sizeof( T_4 ) / 4 ; V_139 += 4 ) {
F_10 ( V_17 , L_103 ,
V_139 * 4 ,
V_181 [ V_139 ] , V_181 [ V_139 + 1 ] , V_181 [ V_139 + 2 ] , V_181 [ V_139 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_83 ( struct V_106 * V_184 ,
const char T_6 * V_185 ,
T_3 V_186 ,
T_7 * V_187 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_20 * V_21 = V_189 -> V_21 ;
int V_73 ;
F_84 ( L_104 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_85 ( V_21 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_186 ;
}
static int F_86 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_191 -> V_192 ;
struct V_188 * V_189 ;
V_189 = F_87 ( sizeof( * V_189 ) , V_9 ) ;
if ( ! V_189 )
return - V_10 ;
V_189 -> V_21 = V_21 ;
F_88 ( V_21 , V_189 ) ;
V_106 -> V_190 = V_189 ;
return 0 ;
}
static int F_89 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_188 * V_189 = V_106 -> V_190 ;
F_90 ( V_189 ) ;
F_91 ( V_189 ) ;
return 0 ;
}
static T_5 F_92 ( struct V_106 * V_106 , char T_6 * V_193 ,
T_3 V_72 , T_7 * V_194 )
{
struct V_188 * V_189 = V_106 -> V_190 ;
struct V_195 V_196 ;
T_7 V_197 = 0 ;
T_5 V_198 = 0 ;
int V_73 ;
V_73 = F_93 ( & V_196 , V_72 , * V_194 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_94 ( & V_196 , V_189 ) ;
if ( V_73 )
goto V_199;
V_198 = F_95 ( V_193 , V_72 , & V_197 ,
V_196 . V_200 ,
V_196 . V_201 ) ;
if ( V_198 < 0 )
V_73 = V_198 ;
else
* V_194 = V_196 . V_52 + V_198 ;
V_199:
F_96 ( & V_196 ) ;
return V_73 ? : V_198 ;
}
static int
F_97 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
* V_202 = V_66 -> V_203 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_98 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_99 ( V_21 , V_202 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int F_100 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_9 V_205 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
V_205 = F_101 ( V_206 ) ;
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_105 , ( V_205 >> 8 ) & 0x3f , ( V_205 & 0x3f ) ) ;
return 0 ;
}
static int F_102 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
F_65 ( V_66 ) ;
F_103 ( & V_66 -> V_207 . V_208 ) ;
if ( F_104 ( V_21 ) ) {
T_9 V_209 = F_101 ( V_210 ) ;
T_9 V_211 = F_101 ( V_212 ) ;
F_10 ( V_17 , L_106 , ( V_209 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_107 , V_209 & 0x3f ) ;
F_10 ( V_17 , L_108 , ( V_211 & V_213 ) >>
V_214 ) ;
F_10 ( V_17 , L_109 ,
( V_211 & V_215 ) >> V_216 ) ;
} else if ( ( F_105 ( V_21 ) || F_106 ( V_21 ) ) && ! F_78 ( V_21 ) ) {
T_4 V_217 = F_69 ( V_218 ) ;
T_4 V_219 = F_69 ( V_220 ) ;
T_4 V_221 = F_69 ( V_222 ) ;
T_4 V_223 , V_224 , V_225 ;
T_4 V_226 , V_227 , V_228 ;
T_4 V_229 , V_230 , V_231 ;
T_4 V_232 , V_233 , V_234 ;
int V_235 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_199;
F_107 ( V_66 , V_236 ) ;
V_228 = F_69 ( V_237 ) ;
V_228 &= ~ V_238 ;
if ( F_108 ( V_21 ) )
V_228 >>= 24 ;
else
V_228 >>= 25 ;
V_228 *= V_239 ;
V_223 = F_69 ( V_240 ) ;
V_224 = F_69 ( V_241 ) ;
V_225 = F_69 ( V_242 ) ;
V_226 = F_69 ( V_243 ) ;
V_229 = F_69 ( V_244 ) ;
V_230 = F_69 ( V_245 ) ;
V_231 = F_69 ( V_246 ) ;
V_232 = F_69 ( V_247 ) ;
V_233 = F_69 ( V_248 ) ;
V_234 = F_69 ( V_249 ) ;
if ( F_108 ( V_21 ) )
V_227 = ( V_226 & V_250 ) >> V_251 ;
else
V_227 = ( V_226 & V_252 ) >> V_253 ;
V_227 *= V_239 ;
F_109 ( V_66 , V_236 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_110 ,
F_69 ( V_166 ) ,
F_69 ( V_168 ) ,
F_69 ( V_254 ) ,
F_69 ( V_167 ) ,
F_69 ( V_255 ) ) ;
F_10 ( V_17 , L_111 , V_217 ) ;
F_10 ( V_17 , L_112 ,
( V_217 & 0xff00 ) >> 8 ) ;
F_10 ( V_17 , L_113 ,
V_217 & 0xff ) ;
F_10 ( V_17 , L_114 ,
V_219 & 0xff ) ;
F_10 ( V_17 , L_115 , V_226 ) ;
F_10 ( V_17 , L_116 , V_223 ) ;
F_10 ( V_17 , L_117 , V_224 ) ;
F_10 ( V_17 , L_118 , V_225 ) ;
F_10 ( V_17 , L_119 , V_228 ) ;
F_10 ( V_17 , L_120 , V_227 ) ;
F_10 ( V_17 , L_121 , V_229 &
V_256 ) ;
F_10 ( V_17 , L_122 , V_230 &
V_257 ) ;
F_10 ( V_17 , L_123 , V_231 &
V_257 ) ;
F_10 ( V_17 , L_124 , V_232 &
V_258 ) ;
F_10 ( V_17 , L_125 , V_233 &
V_257 ) ;
F_10 ( V_17 , L_126 , V_234 &
V_257 ) ;
V_235 = ( V_221 & 0xff0000 ) >> 16 ;
F_10 ( V_17 , L_127 ,
V_235 * V_239 ) ;
V_235 = ( V_221 & 0xff00 ) >> 8 ;
F_10 ( V_17 , L_128 ,
V_235 * V_239 ) ;
V_235 = V_221 & 0xff ;
F_10 ( V_17 , L_129 ,
V_235 * V_239 ) ;
F_10 ( V_17 , L_130 ,
V_66 -> V_207 . V_235 * V_239 ) ;
} else if ( F_78 ( V_21 ) ) {
T_4 V_259 , V_202 ;
F_5 ( & V_66 -> V_207 . V_260 ) ;
V_259 = F_110 ( V_66 , V_261 ) ;
F_10 ( V_17 , L_131 , V_259 ) ;
F_10 ( V_17 , L_132 , V_66 -> V_262 ) ;
V_202 = F_111 ( V_66 ) ;
F_10 ( V_17 , L_133 ,
F_112 ( V_66 , V_202 ) ) ;
V_202 = F_113 ( V_66 ) ;
F_10 ( V_17 , L_134 ,
F_112 ( V_66 , V_202 ) ) ;
F_10 ( V_17 , L_135 ,
F_112 ( V_66 , ( V_259 >> 8 ) & 0xff ) ) ;
F_7 ( & V_66 -> V_207 . V_260 ) ;
} else {
F_23 ( V_17 , L_136 ) ;
}
V_199:
F_66 ( V_66 ) ;
return V_73 ;
}
static int F_114 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_263 ;
int V_73 , V_139 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
for ( V_139 = 0 ; V_139 < 16 ; V_139 ++ ) {
V_263 = F_69 ( V_264 + V_139 * 4 ) ;
F_10 ( V_17 , L_137 , V_139 , V_263 ,
( V_263 & V_265 ) >> V_266 ) ;
}
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static inline int F_115 ( int V_267 )
{
return 1250 - ( V_267 * 25 ) ;
}
static int F_116 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_268 ;
int V_73 , V_139 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
for ( V_139 = 1 ; V_139 <= 32 ; V_139 ++ ) {
V_268 = F_69 ( V_269 + V_139 * 4 ) ;
F_10 ( V_17 , L_138 , V_139 , V_268 ) ;
}
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_117 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_270 , V_271 ;
T_9 V_272 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
V_270 = F_69 ( V_273 ) ;
V_271 = F_69 ( V_274 ) ;
V_272 = F_101 ( V_206 ) ;
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_139 , ( V_270 & V_275 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_140 ,
( V_270 & V_276 ) >>
V_277 ) ;
F_10 ( V_17 , L_141 ,
V_270 & V_278 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_142 ,
V_270 & V_279 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_143 ,
V_270 & V_280 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_144 ,
( V_270 & V_281 ) >> V_282 ) ;
F_10 ( V_17 , L_145 ,
( V_270 & V_283 ) >> V_284 ) ;
F_10 ( V_17 , L_146 , ( V_270 & V_285 ) ) ;
F_10 ( V_17 , L_147 , ( V_272 & 0x3f ) ) ;
F_10 ( V_17 , L_148 , ( ( V_272 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_149 ,
( V_271 & V_286 ) ? L_2 : L_1 ) ;
F_23 ( V_17 , L_150 ) ;
switch ( V_271 & V_287 ) {
case V_288 :
F_23 ( V_17 , L_151 ) ;
break;
case V_289 :
F_23 ( V_17 , L_152 ) ;
break;
case V_290 :
F_23 ( V_17 , L_153 ) ;
break;
case V_291 :
F_23 ( V_17 , L_154 ) ;
break;
case V_292 :
F_23 ( V_17 , L_155 ) ;
break;
case V_293 :
F_23 ( V_17 , L_156 ) ;
break;
default:
F_23 ( V_17 , L_157 ) ;
break;
}
return 0 ;
}
static int F_118 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_294 , V_295 ;
unsigned V_296 = 0 , V_297 = 0 ;
F_65 ( V_66 ) ;
V_294 = F_69 ( V_240 ) ;
V_295 = F_69 ( V_298 ) ;
F_66 ( V_66 ) ;
F_10 ( V_17 , L_158 ,
F_1 ( V_294 & V_299 ) ) ;
F_10 ( V_17 , L_159 ,
F_1 ( V_294 & V_300 ) ) ;
F_10 ( V_17 , L_141 ,
F_1 ( V_294 & V_300 ) ) ;
F_10 ( V_17 , L_142 ,
F_1 ( ( V_294 & V_301 ) ==
V_302 ) ) ;
F_10 ( V_17 , L_160 ,
F_1 ( V_295 & ( V_303 |
F_119 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_161 ,
( F_69 ( V_304 ) &
V_305 ) ? L_162 : L_163 ) ;
F_10 ( V_17 , L_164 ,
( F_69 ( V_304 ) &
V_306 ) ? L_162 : L_163 ) ;
F_10 ( V_17 , L_165 ,
F_69 ( V_307 ) ) ;
F_10 ( V_17 , L_166 ,
F_69 ( V_308 ) ) ;
F_120 ( & V_66 -> V_309 . V_310 ) ;
V_296 = V_66 -> V_309 . V_296 ;
V_297 = V_66 -> V_309 . V_297 ;
F_121 ( & V_66 -> V_309 . V_310 ) ;
F_10 ( V_17 , L_167 , V_296 ) ;
F_10 ( V_17 , L_168 , V_297 ) ;
return 0 ;
}
static int F_122 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_294 , V_311 , V_295 , V_312 = 0 ;
unsigned V_313 ;
int V_72 = 0 , V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
F_120 ( & V_66 -> V_309 . V_310 ) ;
V_313 = V_66 -> V_309 . V_313 ;
F_121 ( & V_66 -> V_309 . V_310 ) ;
if ( V_313 ) {
F_23 ( V_17 , L_169
L_170 ) ;
} else {
while ( V_72 ++ < 50 && ( F_123 ( V_314 ) & 1 ) )
F_124 ( 10 ) ;
F_10 ( V_17 , L_171 , F_1 ( V_72 < 51 ) ) ;
}
V_311 = F_125 ( V_66 -> V_315 + V_316 ) ;
F_126 ( false , V_316 , V_311 , 4 , true ) ;
V_294 = F_69 ( V_240 ) ;
V_295 = F_69 ( V_298 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_5 ( & V_66 -> V_207 . V_260 ) ;
F_127 ( V_66 , V_317 , & V_312 ) ;
F_7 ( & V_66 -> V_207 . V_260 ) ;
F_66 ( V_66 ) ;
F_10 ( V_17 , L_158 ,
F_1 ( V_294 & V_299 ) ) ;
F_10 ( V_17 , L_141 ,
F_1 ( V_294 & V_300 ) ) ;
F_10 ( V_17 , L_142 ,
F_1 ( ( V_294 & V_301 ) ==
V_302 ) ) ;
F_10 ( V_17 , L_172 ,
F_1 ( V_295 & V_318 ) ) ;
F_10 ( V_17 , L_160 ,
F_1 ( V_295 & V_319 ) ) ;
F_10 ( V_17 , L_173 ,
F_1 ( V_295 & V_320 ) ) ;
F_10 ( V_17 , L_174 ,
F_1 ( V_295 & V_321 ) ) ;
F_23 ( V_17 , L_175 ) ;
switch ( V_311 & V_322 ) {
case V_323 :
if ( V_311 & V_324 )
F_23 ( V_17 , L_176 ) ;
else
F_23 ( V_17 , L_151 ) ;
break;
case V_325 :
F_23 ( V_17 , L_177 ) ;
break;
case V_326 :
F_23 ( V_17 , L_178 ) ;
break;
case V_327 :
F_23 ( V_17 , L_179 ) ;
break;
default:
F_23 ( V_17 , L_180 ) ;
break;
}
F_10 ( V_17 , L_181 ,
F_1 ( V_311 & V_324 ) ) ;
F_10 ( V_17 , L_182 ,
F_69 ( V_328 ) ) ;
F_10 ( V_17 , L_183 ,
F_69 ( V_329 ) ) ;
F_10 ( V_17 , L_184 ,
F_69 ( V_330 ) ) ;
F_10 ( V_17 , L_185 ,
F_69 ( V_331 ) ) ;
F_10 ( V_17 , L_186 ,
F_128 ( ( ( V_312 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_187 ,
F_128 ( ( ( V_312 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_188 ,
F_128 ( ( ( V_312 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_129 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_78 ( V_21 ) )
return F_118 ( V_17 ) ;
else if ( F_105 ( V_21 ) || F_106 ( V_21 ) )
return F_122 ( V_17 ) ;
else
return F_117 ( V_17 ) ;
}
static int F_130 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_131 ( V_21 ) ) {
F_23 ( V_17 , L_189 ) ;
return 0 ;
}
F_65 ( V_66 ) ;
if ( F_132 ( V_21 ) ) {
F_23 ( V_17 , L_190 ) ;
} else {
F_23 ( V_17 , L_191 ) ;
switch ( V_66 -> V_332 . V_333 ) {
case V_334 :
F_23 ( V_17 , L_192 ) ;
break;
case V_335 :
F_23 ( V_17 , L_193 ) ;
break;
case V_336 :
F_23 ( V_17 , L_194 ) ;
break;
case V_337 :
F_23 ( V_17 , L_195 ) ;
break;
case V_338 :
F_23 ( V_17 , L_196 ) ;
break;
case V_339 :
F_23 ( V_17 , L_197 ) ;
break;
case V_340 :
F_23 ( V_17 , L_198 ) ;
break;
case V_341 :
F_23 ( V_17 , L_199 ) ;
break;
case V_342 :
F_23 ( V_17 , L_200 ) ;
break;
case V_343 :
F_23 ( V_17 , L_201 ) ;
break;
case V_344 :
F_23 ( V_17 , L_202 ) ;
break;
default:
F_23 ( V_17 , L_203 ) ;
}
F_25 ( V_17 , '\n' ) ;
}
F_66 ( V_66 ) ;
return 0 ;
}
static int F_133 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_134 ( V_21 ) ) {
F_23 ( V_17 , L_204 ) ;
return 0 ;
}
F_65 ( V_66 ) ;
if ( F_135 ( V_21 ) || F_69 ( V_345 ) & V_346 )
F_23 ( V_17 , L_205 ) ;
else
F_23 ( V_17 , L_206 ) ;
F_66 ( V_66 ) ;
return 0 ;
}
static int F_136 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_347 = false ;
F_65 ( V_66 ) ;
if ( F_79 ( V_21 ) )
V_347 = F_69 ( V_348 ) & V_349 ;
else if ( F_137 ( V_21 ) || F_138 ( V_21 ) || F_139 ( V_21 ) )
V_347 = F_69 ( V_350 ) & V_351 ;
else if ( F_140 ( V_21 ) )
V_347 = F_69 ( V_352 ) & V_353 ;
else if ( F_141 ( V_21 ) )
V_347 = F_69 ( V_354 ) & V_355 ;
F_66 ( V_66 ) ;
F_10 ( V_17 , L_207 ,
V_347 ? L_208 : L_209 ) ;
return 0 ;
}
static int F_142 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned long V_356 , V_357 , V_358 ;
int V_73 ;
if ( ! F_104 ( V_21 ) )
return - V_359 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_356 = F_143 ( V_66 ) ;
V_357 = F_144 ( V_66 ) ;
V_358 = F_145 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_210 , V_356 ) ;
F_10 ( V_17 , L_211 , V_357 ) ;
F_10 ( V_17 , L_212 , V_358 ) ;
F_10 ( V_17 , L_213 , V_357 + V_358 ) ;
return 0 ;
}
static int F_146 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
int V_360 , V_361 ;
if ( ! ( F_105 ( V_21 ) || F_106 ( V_21 ) ) ) {
F_23 ( V_17 , L_214 ) ;
return 0 ;
}
F_65 ( V_66 ) ;
F_103 ( & V_66 -> V_207 . V_208 ) ;
V_73 = F_27 ( & V_66 -> V_207 . V_260 ) ;
if ( V_73 )
goto V_199;
F_23 ( V_17 , L_215 ) ;
for ( V_360 = V_66 -> V_207 . V_362 ;
V_360 <= V_66 -> V_207 . V_363 ;
V_360 ++ ) {
V_361 = V_360 ;
F_127 ( V_66 ,
V_364 ,
& V_361 ) ;
F_10 ( V_17 , L_216 ,
V_360 * V_239 ,
( ( V_361 >> 0 ) & 0xff ) * 100 ,
( ( V_361 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_66 -> V_207 . V_260 ) ;
V_199:
F_66 ( V_66 ) ;
return V_73 ;
}
static int F_147 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
F_10 ( V_17 , L_217 , ( unsigned long ) F_69 ( 0x112f4 ) ) ;
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_148 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_365 * V_366 = & V_66 -> V_366 ;
void * V_18 = F_3 ( V_367 , V_9 ) ;
int V_73 ;
if ( V_18 == NULL )
return - V_10 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_199;
if ( V_366 -> V_368 ) {
F_149 ( V_18 , V_366 -> V_368 , V_367 ) ;
F_150 ( V_17 , V_18 , V_367 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
V_199:
F_91 ( V_18 ) ;
return 0 ;
}
static int F_151 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_369 * V_370 = NULL ;
struct V_371 * V_372 ;
#ifdef F_152
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_27 ( & V_21 -> V_373 . V_374 ) ;
if ( V_73 )
return V_73 ;
V_370 = V_66 -> V_375 ;
V_372 = F_153 ( V_370 -> V_376 . V_372 ) ;
F_10 ( V_17 , L_218 ,
V_372 -> V_36 . V_377 ,
V_372 -> V_36 . V_378 ,
V_372 -> V_36 . V_379 ,
V_372 -> V_36 . V_380 ,
F_58 ( & V_372 -> V_36 . V_381 . V_381 ) ) ;
F_19 ( V_17 , V_372 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
F_7 ( & V_21 -> V_373 . V_374 ) ;
#endif
F_5 ( & V_21 -> V_373 . V_382 ) ;
F_21 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_370 && & V_372 -> V_36 == V_370 -> V_376 . V_372 )
continue;
F_10 ( V_17 , L_219 ,
V_372 -> V_36 . V_377 ,
V_372 -> V_36 . V_378 ,
V_372 -> V_36 . V_379 ,
V_372 -> V_36 . V_380 ,
F_58 ( & V_372 -> V_36 . V_381 . V_381 ) ) ;
F_19 ( V_17 , V_372 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_373 . V_382 ) ;
return 0 ;
}
static int F_154 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_136 * V_58 ;
struct V_59 * V_60 ;
int V_73 , V_139 ;
V_73 = F_27 ( & V_21 -> V_373 . V_374 ) ;
if ( V_73 )
return V_73 ;
if ( V_66 -> V_383 . V_384 ) {
F_23 ( V_17 , L_220 ) ;
F_19 ( V_17 , V_66 -> V_383 . V_384 ) ;
F_25 ( V_17 , '\n' ) ;
}
if ( V_66 -> V_383 . V_385 ) {
F_23 ( V_17 , L_221 ) ;
F_19 ( V_17 , V_66 -> V_383 . V_385 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_21 (ctx, &dev_priv->context_list, link) {
if ( V_60 -> V_26 == NULL )
continue;
F_23 ( V_17 , L_222 ) ;
F_24 ( V_17 , V_60 ) ;
F_62 (ring, dev_priv, i)
if ( V_58 -> V_386 == V_60 )
F_10 ( V_17 , L_223 , V_58 -> V_47 ) ;
F_19 ( V_17 , V_60 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_373 . V_374 ) ;
return 0 ;
}
static int F_155 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned V_313 = 0 , V_296 = 0 , V_297 = 0 ;
F_120 ( & V_66 -> V_309 . V_310 ) ;
if ( F_78 ( V_21 ) ) {
V_296 = V_66 -> V_309 . V_296 ;
V_297 = V_66 -> V_309 . V_297 ;
} else
V_313 = V_66 -> V_309 . V_313 ;
F_121 ( & V_66 -> V_309 . V_310 ) ;
if ( F_78 ( V_21 ) ) {
F_10 ( V_17 , L_224 , V_296 ) ;
F_10 ( V_17 , L_225 , V_297 ) ;
} else
F_10 ( V_17 , L_226 , V_313 ) ;
return 0 ;
}
static const char * F_156 ( unsigned V_387 )
{
switch ( V_387 ) {
case V_388 :
return L_227 ;
case V_389 :
return L_228 ;
case V_390 :
return L_229 ;
case V_391 :
return L_230 ;
case V_392 :
return L_231 ;
case V_393 :
return L_232 ;
case V_394 :
return L_233 ;
case V_395 :
return L_234 ;
}
return L_235 ;
}
static int F_157 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
F_10 ( V_17 , L_236 ,
F_156 ( V_66 -> V_107 . V_396 ) ) ;
F_10 ( V_17 , L_237 ,
F_156 ( V_66 -> V_107 . V_397 ) ) ;
if ( F_158 ( V_21 ) || F_159 ( V_21 ) ) {
F_10 ( V_17 , L_238 ,
F_69 ( V_398 ) ) ;
F_10 ( V_17 , L_239 ,
F_101 ( V_399 ) ) ;
F_10 ( V_17 , L_240 ,
F_101 ( V_400 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_241 ,
F_69 ( V_401 ) ) ;
F_10 ( V_17 , L_242 ,
F_69 ( V_402 ) ) ;
F_10 ( V_17 , L_243 ,
F_69 ( V_403 ) ) ;
F_10 ( V_17 , L_244 ,
F_69 ( V_404 ) ) ;
if ( F_160 ( V_21 ) )
F_10 ( V_17 , L_245 ,
F_69 ( V_405 ) ) ;
else
F_10 ( V_17 , L_246 ,
F_69 ( V_406 ) ) ;
F_10 ( V_17 , L_247 ,
F_69 ( V_407 ) ) ;
}
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_161 ( int V_86 , void * V_87 , void * V_18 )
{
struct V_59 * V_60 = V_87 ;
struct V_16 * V_17 = V_18 ;
struct V_93 * V_94 = F_162 ( V_60 ) ;
if ( F_163 ( V_60 ) )
F_23 ( V_17 , L_248 ) ;
else
F_10 ( V_17 , L_249 , V_60 -> V_86 ) ;
V_94 -> V_408 ( V_94 , V_17 ) ;
return 0 ;
}
static void F_164 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_136 * V_58 ;
struct V_93 * V_94 = V_66 -> V_107 . V_409 ;
int V_204 , V_139 ;
if ( ! V_94 )
return;
F_10 ( V_17 , L_250 , V_94 -> V_410 ) ;
F_10 ( V_17 , L_251 , V_94 -> V_411 ) ;
F_62 (ring, dev_priv, unused) {
F_10 ( V_17 , L_252 , V_58 -> V_47 ) ;
for ( V_139 = 0 ; V_139 < 4 ; V_139 ++ ) {
T_4 V_412 = 0x270 + V_139 * 8 ;
T_8 V_413 = F_69 ( V_58 -> V_414 + V_412 + 4 ) ;
V_413 <<= 32 ;
V_413 |= F_69 ( V_58 -> V_414 + V_412 ) ;
F_10 ( V_17 , L_253 , V_139 , V_413 ) ;
}
}
}
static void F_165 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_136 * V_58 ;
struct V_105 * V_106 ;
int V_139 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_254 , F_69 ( V_415 ) ) ;
F_62 (ring, dev_priv, i) {
F_10 ( V_17 , L_252 , V_58 -> V_47 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_254 , F_69 ( F_166 ( V_58 ) ) ) ;
F_10 ( V_17 , L_255 , F_69 ( F_167 ( V_58 ) ) ) ;
F_10 ( V_17 , L_256 , F_69 ( F_168 ( V_58 ) ) ) ;
F_10 ( V_17 , L_257 , F_69 ( F_169 ( V_58 ) ) ) ;
}
if ( V_66 -> V_107 . V_409 ) {
struct V_93 * V_94 = V_66 -> V_107 . V_409 ;
F_23 ( V_17 , L_258 ) ;
F_10 ( V_17 , L_259 , V_94 -> V_416 ) ;
V_94 -> V_408 ( V_94 , V_17 ) ;
} else
return;
F_45 (file, &dev->filelist, lhead) {
struct V_417 * V_96 = V_106 -> V_115 ;
F_10 ( V_17 , L_260 ,
F_170 ( V_106 -> V_118 , V_119 ) -> V_120 ) ;
F_47 ( & V_96 -> V_418 , F_161 , V_17 ) ;
}
F_10 ( V_17 , L_261 , F_69 ( V_419 ) ) ;
}
static int F_171 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_164 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_165 ( V_17 , V_21 ) ;
F_66 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_172 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
F_10 ( V_17 , L_262 , F_1 ( F_173 ( V_21 ) ) ) ;
F_10 ( V_17 , L_263 , V_66 -> V_420 ) ;
return 0 ;
}
static int F_174 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_421 = 0 ;
bool V_422 = false ;
F_65 ( V_66 ) ;
F_10 ( V_17 , L_264 , F_1 ( V_66 -> V_423 . V_424 ) ) ;
F_10 ( V_17 , L_265 , F_1 ( V_66 -> V_423 . V_425 ) ) ;
V_422 = F_175 ( V_21 ) &&
F_69 ( F_176 ( V_21 ) ) & V_426 ;
F_10 ( V_17 , L_266 , F_1 ( V_422 ) ) ;
if ( F_175 ( V_21 ) )
V_421 = F_69 ( F_177 ( V_21 ) ) &
V_427 ;
F_10 ( V_17 , L_267 , V_421 ) ;
F_66 ( V_66 ) ;
return 0 ;
}
static int F_178 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_428 * V_429 ;
struct V_430 * V_431 ;
struct V_432 * V_432 = NULL ;
int V_73 ;
T_10 V_433 [ 6 ] ;
F_179 ( V_21 ) ;
F_21 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_36 . V_434 != V_435 )
continue;
if ( ! V_431 -> V_36 . V_429 )
continue;
V_429 = F_180 ( V_431 -> V_36 . V_429 ) ;
if ( V_429 -> type != V_436 )
continue;
V_432 = F_181 ( & V_429 -> V_36 ) ;
V_73 = F_182 ( V_432 , V_433 ) ;
if ( V_73 )
goto V_199;
F_10 ( V_17 , L_268 ,
V_433 [ 0 ] , V_433 [ 1 ] , V_433 [ 2 ] ,
V_433 [ 3 ] , V_433 [ 4 ] , V_433 [ 5 ] ) ;
goto V_199;
}
V_73 = - V_359 ;
V_199:
F_183 ( V_21 ) ;
return V_73 ;
}
static int F_184 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_8 V_437 ;
T_4 V_438 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_359 ;
F_65 ( V_66 ) ;
F_185 ( V_439 , V_437 ) ;
V_437 = ( V_437 & 0x1f00 ) >> 8 ;
V_438 = 1000000 / ( 1 << V_437 ) ;
V_437 = F_69 ( V_440 ) ;
V_437 *= V_438 ;
F_66 ( V_66 ) ;
F_10 ( V_17 , L_269 , ( long long unsigned ) V_437 ) ;
return 0 ;
}
static int F_186 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_108 ( V_21 ) && ! F_135 ( V_21 ) ) {
F_23 ( V_17 , L_204 ) ;
return 0 ;
}
F_10 ( V_17 , L_270 , F_1 ( ! V_66 -> V_107 . V_441 ) ) ;
F_10 ( V_17 , L_271 ,
F_1 ( V_66 -> V_442 . V_443 ) ) ;
return 0 ;
}
static const char * F_187 ( enum V_444 V_445 )
{
switch ( V_445 ) {
case V_446 :
return L_272 ;
case V_447 :
return L_273 ;
case V_448 :
return L_274 ;
case V_449 :
return L_275 ;
case V_450 :
return L_276 ;
case V_451 :
return L_277 ;
case V_452 :
return L_278 ;
case V_453 :
return L_279 ;
case V_454 :
return L_280 ;
case V_455 :
return L_281 ;
case V_456 :
return L_282 ;
case V_457 :
return L_283 ;
case V_458 :
return L_284 ;
case V_459 :
return L_285 ;
case V_460 :
return L_286 ;
case V_461 :
return L_287 ;
case V_462 :
return L_288 ;
case V_463 :
return L_289 ;
case V_464 :
return L_290 ;
case V_465 :
return L_291 ;
case V_466 :
return L_292 ;
case V_467 :
return L_293 ;
case V_468 :
return L_294 ;
case V_469 :
return L_295 ;
default:
F_188 ( 1 ) ;
return L_296 ;
}
}
static int F_189 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_470 * V_471 = & V_66 -> V_471 ;
int V_139 ;
F_5 ( & V_471 -> V_310 ) ;
F_10 ( V_17 , L_297 , L_298 , L_299 ) ;
for ( V_139 = 0 ; V_139 < V_471 -> V_472 ; V_139 ++ ) {
struct V_473 * V_474 ;
enum V_444 V_475 ;
V_474 = & V_471 -> V_476 [ V_139 ] ;
F_10 ( V_17 , L_300 , V_474 -> V_47 ,
V_474 -> V_72 ) ;
for ( V_475 = 0 ; V_475 < V_477 ;
V_475 ++ ) {
if ( ! ( F_190 ( V_475 ) & V_474 -> V_478 ) )
continue;
F_10 ( V_17 , L_301 ,
F_187 ( V_475 ) ,
V_471 -> V_479 [ V_475 ] ) ;
}
}
F_7 ( & V_471 -> V_310 ) ;
return 0 ;
}
static void F_191 ( struct V_16 * V_17 , int V_480 ,
struct V_481 * V_482 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_480 ; V_139 ++ )
F_25 ( V_17 , '\t' ) ;
F_10 ( V_17 , L_302 ,
V_482 -> V_36 . V_86 , V_482 -> V_47 ,
V_482 -> V_483 , V_482 -> clock ,
V_482 -> V_484 , V_482 -> V_485 ,
V_482 -> V_486 , V_482 -> V_487 ,
V_482 -> V_488 , V_482 -> V_489 ,
V_482 -> V_490 , V_482 -> V_491 ,
V_482 -> type , V_482 -> V_122 ) ;
}
static void F_192 ( struct V_16 * V_17 ,
struct V_123 * V_123 ,
struct V_428 * V_428 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_492 * V_124 = & V_123 -> V_36 ;
struct V_430 * V_430 ;
struct V_493 * V_429 ;
V_429 = & V_428 -> V_36 ;
F_10 ( V_17 , L_303 ,
V_429 -> V_36 . V_86 , V_429 -> V_47 ) ;
F_193 (dev, encoder, intel_connector) {
struct V_494 * V_431 = & V_430 -> V_36 ;
F_10 ( V_17 , L_304 ,
V_431 -> V_36 . V_86 ,
V_431 -> V_47 ,
F_194 ( V_431 -> V_495 ) ) ;
if ( V_431 -> V_495 == V_496 ) {
struct V_481 * V_482 = & V_124 -> V_482 ;
F_10 ( V_17 , L_305 ) ;
F_191 ( V_17 , 2 , V_482 ) ;
} else {
F_25 ( V_17 , '\n' ) ;
}
}
}
static void F_195 ( struct V_16 * V_17 , struct V_123 * V_123 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_492 * V_124 = & V_123 -> V_36 ;
struct V_428 * V_428 ;
F_10 ( V_17 , L_306 ,
V_124 -> V_497 -> V_372 -> V_36 . V_86 , V_124 -> T_1 , V_124 -> V_498 ,
V_124 -> V_497 -> V_372 -> V_377 , V_124 -> V_497 -> V_372 -> V_378 ) ;
F_196 (dev, crtc, intel_encoder)
F_192 ( V_17 , V_123 , V_428 ) ;
}
static void F_197 ( struct V_16 * V_17 , struct V_499 * V_500 )
{
struct V_481 * V_482 = V_500 -> V_501 ;
F_10 ( V_17 , L_307 ) ;
F_191 ( V_17 , 2 , V_482 ) ;
}
static void F_198 ( struct V_16 * V_17 ,
struct V_430 * V_430 )
{
struct V_428 * V_428 = V_430 -> V_429 ;
struct V_432 * V_432 = F_181 ( & V_428 -> V_36 ) ;
F_10 ( V_17 , L_308 , V_432 -> V_502 [ V_503 ] ) ;
F_10 ( V_17 , L_309 , V_432 -> V_504 ? L_1 :
L_2 ) ;
if ( V_428 -> type == V_436 )
F_197 ( V_17 , & V_430 -> V_500 ) ;
}
static void F_199 ( struct V_16 * V_17 ,
struct V_430 * V_430 )
{
struct V_428 * V_428 = V_430 -> V_429 ;
struct V_505 * V_505 = F_200 ( & V_428 -> V_36 ) ;
F_10 ( V_17 , L_309 , V_505 -> V_504 ? L_1 :
L_2 ) ;
}
static void F_201 ( struct V_16 * V_17 ,
struct V_430 * V_430 )
{
F_197 ( V_17 , & V_430 -> V_500 ) ;
}
static void F_202 ( struct V_16 * V_17 ,
struct V_494 * V_431 )
{
struct V_430 * V_430 = F_203 ( V_431 ) ;
struct V_428 * V_428 = V_430 -> V_429 ;
struct V_481 * V_482 ;
F_10 ( V_17 , L_310 ,
V_431 -> V_36 . V_86 , V_431 -> V_47 ,
F_194 ( V_431 -> V_495 ) ) ;
if ( V_431 -> V_495 == V_496 ) {
F_10 ( V_17 , L_311 , V_431 -> V_506 . V_47 ) ;
F_10 ( V_17 , L_312 ,
V_431 -> V_506 . V_507 ,
V_431 -> V_506 . V_508 ) ;
F_10 ( V_17 , L_313 ,
F_204 ( V_431 -> V_506 . V_509 ) ) ;
F_10 ( V_17 , L_314 ,
V_431 -> V_506 . V_510 ) ;
}
if ( V_428 -> type == V_511 ||
V_428 -> type == V_436 )
F_198 ( V_17 , V_430 ) ;
else if ( V_428 -> type == V_512 )
F_199 ( V_17 , V_430 ) ;
else if ( V_428 -> type == V_513 )
F_201 ( V_17 , V_430 ) ;
F_10 ( V_17 , L_315 ) ;
F_21 (mode, &connector->modes, head)
F_191 ( V_17 , 2 , V_482 ) ;
}
static bool F_205 ( struct V_20 * V_21 , int V_125 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_514 ;
if ( F_206 ( V_21 ) || F_207 ( V_21 ) )
V_514 = F_69 ( V_515 ) & V_516 ;
else
V_514 = F_69 ( F_208 ( V_125 ) ) & V_517 ;
return V_514 ;
}
static bool F_209 ( struct V_20 * V_21 , int V_125 , int * T_1 , int * V_498 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_194 ;
V_194 = F_69 ( F_210 ( V_125 ) ) ;
* T_1 = ( V_194 >> V_518 ) & V_519 ;
if ( V_194 & ( V_520 << V_518 ) )
* T_1 = - * T_1 ;
* V_498 = ( V_194 >> V_521 ) & V_519 ;
if ( V_194 & ( V_520 << V_521 ) )
* V_498 = - * V_498 ;
return F_205 ( V_21 , V_125 ) ;
}
static int F_211 ( struct V_16 * V_17 , void * V_204 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_123 * V_124 ;
struct V_494 * V_431 ;
F_65 ( V_66 ) ;
F_179 ( V_21 ) ;
F_10 ( V_17 , L_316 ) ;
F_10 ( V_17 , L_317 ) ;
F_54 (dev, crtc) {
bool V_97 ;
int T_1 , V_498 ;
F_10 ( V_17 , L_318 ,
V_124 -> V_36 . V_36 . V_86 , F_55 ( V_124 -> V_125 ) ,
F_1 ( V_124 -> V_97 ) ) ;
if ( V_124 -> V_97 ) {
F_195 ( V_17 , V_124 ) ;
V_97 = F_209 ( V_21 , V_124 -> V_125 , & T_1 , & V_498 ) ;
F_10 ( V_17 , L_319 ,
F_1 ( V_124 -> V_522 ) ,
T_1 , V_498 , V_124 -> V_523 ,
F_1 ( V_97 ) ) ;
}
F_10 ( V_17 , L_320 ,
F_1 ( ! V_124 -> V_524 ) ,
F_1 ( ! V_124 -> V_525 ) ) ;
}
F_10 ( V_17 , L_28 ) ;
F_10 ( V_17 , L_321 ) ;
F_10 ( V_17 , L_322 ) ;
F_21 (connector, &dev->mode_config.connector_list, head) {
F_202 ( V_17 , V_431 ) ;
}
F_183 ( V_21 ) ;
F_66 ( V_66 ) ;
return 0 ;
}
static int F_212 ( struct V_191 * V_191 , struct V_106 * V_526 )
{
struct V_527 * V_23 = V_191 -> V_192 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_528 * V_529 = & V_66 -> V_529 [ V_23 -> V_125 ] ;
if ( V_23 -> V_125 >= F_9 ( V_23 -> V_21 ) -> V_530 )
return - V_359 ;
F_120 ( & V_529 -> V_310 ) ;
if ( V_529 -> V_531 ) {
F_121 ( & V_529 -> V_310 ) ;
return - V_532 ;
}
V_529 -> V_531 = true ;
V_526 -> V_190 = V_191 -> V_192 ;
F_121 ( & V_529 -> V_310 ) ;
return 0 ;
}
static int F_213 ( struct V_191 * V_191 , struct V_106 * V_526 )
{
struct V_527 * V_23 = V_191 -> V_192 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_528 * V_529 = & V_66 -> V_529 [ V_23 -> V_125 ] ;
F_120 ( & V_529 -> V_310 ) ;
V_529 -> V_531 = false ;
F_121 ( & V_529 -> V_310 ) ;
return 0 ;
}
static int F_214 ( struct V_528 * V_529 )
{
F_215 ( & V_529 -> V_310 ) ;
return F_216 ( V_529 -> V_64 , V_529 -> V_533 ,
V_534 ) ;
}
static T_5
F_217 ( struct V_106 * V_526 , char T_6 * V_535 , T_3 V_72 ,
T_7 * V_194 )
{
struct V_527 * V_23 = V_526 -> V_190 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_528 * V_529 = & V_66 -> V_529 [ V_23 -> V_125 ] ;
char V_200 [ V_536 ] ;
int V_64 , V_533 , V_537 , V_538 ;
T_5 V_539 ;
if ( V_72 < V_540 )
return - V_79 ;
if ( V_529 -> V_541 == V_542 )
return 0 ;
F_120 ( & V_529 -> V_310 ) ;
while ( F_214 ( V_529 ) == 0 ) {
int V_73 ;
if ( V_526 -> V_543 & V_544 ) {
F_121 ( & V_529 -> V_310 ) ;
return - V_545 ;
}
V_73 = F_218 ( V_529 -> V_546 ,
F_214 ( V_529 ) , V_529 -> V_310 ) ;
if ( V_73 ) {
F_121 ( & V_529 -> V_310 ) ;
return V_73 ;
}
}
V_64 = V_529 -> V_64 ;
V_533 = V_529 -> V_533 ;
V_537 = F_219 ( ( T_3 ) F_216 ( V_64 , V_533 , V_534 ) ,
V_72 / V_540 ) ;
F_121 ( & V_529 -> V_310 ) ;
V_539 = 0 ;
V_538 = 0 ;
do {
struct V_547 * V_548 = & V_529 -> V_549 [ V_533 ] ;
int V_73 ;
V_539 += snprintf ( V_200 , V_536 ,
L_323 ,
V_548 -> V_550 , V_548 -> V_433 [ 0 ] ,
V_548 -> V_433 [ 1 ] , V_548 -> V_433 [ 2 ] ,
V_548 -> V_433 [ 3 ] , V_548 -> V_433 [ 4 ] ) ;
V_73 = F_220 ( V_535 + V_538 * V_540 ,
V_200 , V_540 ) ;
if ( V_73 == V_540 )
return - V_551 ;
F_221 ( V_534 ) ;
V_533 = ( V_533 + 1 ) & ( V_534 - 1 ) ;
V_538 ++ ;
} while ( -- V_537 );
F_120 ( & V_529 -> V_310 ) ;
V_529 -> V_533 = V_533 ;
F_121 ( & V_529 -> V_310 ) ;
return V_539 ;
}
static int F_222 ( struct V_4 * V_552 , struct V_2 * V_3 ,
enum V_125 V_125 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_527 * V_23 = & V_553 [ V_125 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_223 ( V_23 -> V_47 , V_554 , V_552 , V_23 ,
& V_555 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_224 ( enum V_556 V_541 )
{
F_225 ( F_226 ( V_557 ) != V_558 ) ;
return V_557 [ V_541 ] ;
}
static int F_227 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_559 ; V_139 ++ )
F_10 ( V_17 , L_324 , F_55 ( V_139 ) ,
F_224 ( V_66 -> V_529 [ V_139 ] . V_541 ) ) ;
return 0 ;
}
static int F_228 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_191 -> V_192 ;
return F_229 ( V_106 , F_227 , V_21 ) ;
}
static int F_230 ( enum V_556 * V_541 ,
T_11 * V_202 )
{
if ( * V_541 == V_560 )
* V_541 = V_561 ;
switch ( * V_541 ) {
case V_561 :
* V_202 = V_562 | V_563 ;
break;
case V_542 :
* V_202 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_231 ( struct V_20 * V_21 , enum V_125 V_125 ,
enum V_556 * V_541 )
{
struct V_428 * V_429 ;
struct V_123 * V_124 ;
struct V_564 * V_565 ;
int V_73 = 0 ;
* V_541 = V_561 ;
F_179 ( V_21 ) ;
F_21 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_429 -> V_36 . V_124 )
continue;
V_124 = F_232 ( V_429 -> V_36 . V_124 ) ;
if ( V_124 -> V_125 != V_125 )
continue;
switch ( V_429 -> type ) {
case V_566 :
* V_541 = V_567 ;
break;
case V_511 :
case V_436 :
V_565 = F_233 ( & V_429 -> V_36 ) ;
switch ( V_565 -> V_568 ) {
case V_569 :
* V_541 = V_570 ;
break;
case V_571 :
* V_541 = V_572 ;
break;
case V_573 :
* V_541 = V_574 ;
break;
default:
F_234 ( 1 , L_325 ,
F_235 ( V_565 -> V_568 ) ) ;
break;
}
break;
}
}
F_183 ( V_21 ) ;
return V_73 ;
}
static int F_236 ( struct V_20 * V_21 ,
enum V_125 V_125 ,
enum V_556 * V_541 ,
T_11 * V_202 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_575 = false ;
if ( * V_541 == V_560 ) {
int V_73 = F_231 ( V_21 , V_125 , V_541 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_541 ) {
case V_561 :
* V_202 = V_562 | V_576 ;
break;
case V_570 :
* V_202 = V_562 | V_577 ;
V_575 = true ;
break;
case V_572 :
* V_202 = V_562 | V_578 ;
V_575 = true ;
break;
case V_542 :
* V_202 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_575 ) {
T_11 V_579 = F_69 ( V_580 ) ;
V_579 |= V_581 ;
if ( V_125 == V_582 )
V_579 |= V_583 ;
else
V_579 |= V_584 ;
F_237 ( V_580 , V_579 ) ;
}
return 0 ;
}
static int F_238 ( struct V_20 * V_21 ,
enum V_125 V_125 ,
enum V_556 * V_541 ,
T_11 * V_202 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_575 = false ;
if ( * V_541 == V_560 ) {
int V_73 = F_231 ( V_21 , V_125 , V_541 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_541 ) {
case V_561 :
* V_202 = V_562 | V_585 ;
break;
case V_567 :
if ( ! F_239 ( V_21 ) )
return - V_79 ;
* V_202 = V_562 | V_586 ;
break;
case V_570 :
if ( ! F_240 ( V_21 ) )
return - V_79 ;
* V_202 = V_562 | V_587 ;
V_575 = true ;
break;
case V_572 :
if ( ! F_240 ( V_21 ) )
return - V_79 ;
* V_202 = V_562 | V_588 ;
V_575 = true ;
break;
case V_574 :
if ( ! F_240 ( V_21 ) )
return - V_79 ;
* V_202 = V_562 | V_589 ;
V_575 = true ;
break;
case V_542 :
* V_202 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_575 ) {
T_11 V_579 = F_69 ( V_580 ) ;
F_188 ( ! F_240 ( V_21 ) ) ;
F_237 ( V_590 ,
F_69 ( V_590 ) | V_591 ) ;
if ( V_125 == V_582 )
V_579 |= V_583 ;
else
V_579 |= V_584 ;
F_237 ( V_580 , V_579 ) ;
}
return 0 ;
}
static void F_241 ( struct V_20 * V_21 ,
enum V_125 V_125 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_579 = F_69 ( V_580 ) ;
if ( V_125 == V_582 )
V_579 &= ~ V_583 ;
else
V_579 &= ~ V_584 ;
if ( ! ( V_579 & V_592 ) )
V_579 &= ~ V_581 ;
F_237 ( V_580 , V_579 ) ;
}
static void F_242 ( struct V_20 * V_21 ,
enum V_125 V_125 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_579 = F_69 ( V_580 ) ;
if ( V_125 == V_582 )
V_579 &= ~ V_583 ;
else
V_579 &= ~ V_584 ;
F_237 ( V_580 , V_579 ) ;
if ( ! ( V_579 & V_592 ) ) {
F_237 ( V_590 ,
F_69 ( V_590 ) & ~ V_591 ) ;
}
}
static int F_243 ( enum V_556 * V_541 ,
T_11 * V_202 )
{
if ( * V_541 == V_560 )
* V_541 = V_561 ;
switch ( * V_541 ) {
case V_593 :
* V_202 = V_562 | V_594 ;
break;
case V_595 :
* V_202 = V_562 | V_596 ;
break;
case V_561 :
* V_202 = V_562 | V_597 ;
break;
case V_542 :
* V_202 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_244 ( enum V_556 * V_541 ,
T_11 * V_202 )
{
if ( * V_541 == V_560 )
* V_541 = V_598 ;
switch ( * V_541 ) {
case V_593 :
* V_202 = V_562 | V_599 ;
break;
case V_595 :
* V_202 = V_562 | V_600 ;
break;
case V_598 :
* V_202 = V_562 | V_601 ;
break;
case V_542 :
* V_202 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_245 ( struct V_20 * V_21 , enum V_125 V_125 ,
enum V_556 V_541 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_528 * V_529 = & V_66 -> V_529 [ V_125 ] ;
T_4 V_202 = 0 ;
int V_73 ;
if ( V_529 -> V_541 == V_541 )
return 0 ;
if ( V_529 -> V_541 && V_541 )
return - V_79 ;
if ( F_246 ( V_21 ) )
V_73 = F_230 ( & V_541 , & V_202 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_73 = F_238 ( V_21 , V_125 , & V_541 , & V_202 ) ;
else if ( F_78 ( V_21 ) )
V_73 = F_236 ( V_21 , V_125 , & V_541 , & V_202 ) ;
else if ( F_104 ( V_21 ) || F_105 ( V_21 ) )
V_73 = F_243 ( & V_541 , & V_202 ) ;
else
V_73 = F_244 ( & V_541 , & V_202 ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_541 ) {
F_84 ( L_326 ,
F_55 ( V_125 ) , F_224 ( V_541 ) ) ;
V_529 -> V_549 = F_87 ( sizeof( * V_529 -> V_549 ) *
V_534 ,
V_9 ) ;
if ( ! V_529 -> V_549 )
return - V_10 ;
F_120 ( & V_529 -> V_310 ) ;
V_529 -> V_64 = 0 ;
V_529 -> V_533 = 0 ;
F_121 ( & V_529 -> V_310 ) ;
}
V_529 -> V_541 = V_541 ;
F_237 ( F_247 ( V_125 ) , V_202 ) ;
F_248 ( F_247 ( V_125 ) ) ;
if ( V_541 == V_542 ) {
struct V_547 * V_549 ;
F_84 ( L_327 ,
F_55 ( V_125 ) ) ;
F_249 ( V_21 , V_125 ) ;
F_120 ( & V_529 -> V_310 ) ;
V_549 = V_529 -> V_549 ;
V_529 -> V_549 = NULL ;
F_121 ( & V_529 -> V_310 ) ;
F_91 ( V_549 ) ;
if ( F_240 ( V_21 ) )
F_242 ( V_21 , V_125 ) ;
else if ( F_78 ( V_21 ) )
F_241 ( V_21 , V_125 ) ;
}
return 0 ;
}
static int F_250 ( char * V_200 , char * V_602 [] , int V_603 )
{
int V_604 = 0 ;
while ( * V_200 ) {
char * V_605 ;
V_200 = F_251 ( V_200 ) ;
if ( ! * V_200 )
break;
for ( V_605 = V_200 ; * V_605 && ! isspace ( * V_605 ) ; V_605 ++ )
;
if ( V_604 == V_603 ) {
F_84 ( L_328 ,
V_603 ) ;
return - V_79 ;
}
if ( * V_605 )
* V_605 ++ = '\0' ;
V_602 [ V_604 ++ ] = V_200 ;
V_200 = V_605 ;
}
return V_604 ;
}
static int
F_252 ( const char * V_200 , enum V_606 * V_607 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < F_226 ( V_608 ) ; V_139 ++ )
if ( ! strcmp ( V_200 , V_608 [ V_139 ] ) ) {
* V_607 = V_139 ;
return 0 ;
}
return - V_79 ;
}
static int F_253 ( const char * V_200 , enum V_125 * V_125 )
{
const char V_47 = V_200 [ 0 ] ;
if ( V_47 < 'A' || V_47 >= F_55 ( V_559 ) )
return - V_79 ;
* V_125 = V_47 - 'A' ;
return 0 ;
}
static int
F_254 ( const char * V_200 , enum V_556 * V_56 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < F_226 ( V_557 ) ; V_139 ++ )
if ( ! strcmp ( V_200 , V_557 [ V_139 ] ) ) {
* V_56 = V_139 ;
return 0 ;
}
return - V_79 ;
}
static int F_255 ( struct V_20 * V_21 , char * V_200 , T_3 V_609 )
{
#define F_256 3
int V_604 ;
char * V_602 [ F_256 ] ;
enum V_125 V_125 ;
enum V_606 V_610 ;
enum V_556 V_541 ;
V_604 = F_250 ( V_200 , V_602 , F_256 ) ;
if ( V_604 != F_256 ) {
F_84 ( L_329 ,
F_256 ) ;
return - V_79 ;
}
if ( F_252 ( V_602 [ 0 ] , & V_610 ) < 0 ) {
F_84 ( L_330 , V_602 [ 0 ] ) ;
return - V_79 ;
}
if ( F_253 ( V_602 [ 1 ] , & V_125 ) < 0 ) {
F_84 ( L_331 , V_602 [ 1 ] ) ;
return - V_79 ;
}
if ( F_254 ( V_602 [ 2 ] , & V_541 ) < 0 ) {
F_84 ( L_332 , V_602 [ 2 ] ) ;
return - V_79 ;
}
return F_245 ( V_21 , V_125 , V_541 ) ;
}
static T_5 F_257 ( struct V_106 * V_106 , const char T_6 * V_185 ,
T_3 V_609 , T_7 * V_611 )
{
struct V_16 * V_17 = V_106 -> V_190 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_612 ;
int V_73 ;
if ( V_609 == 0 )
return 0 ;
if ( V_609 > V_613 - 1 ) {
F_84 ( L_333 ,
V_613 ) ;
return - V_614 ;
}
V_612 = F_3 ( V_609 + 1 , V_9 ) ;
if ( ! V_612 )
return - V_10 ;
if ( F_258 ( V_612 , V_185 , V_609 ) ) {
V_73 = - V_551 ;
goto V_199;
}
V_612 [ V_609 ] = '\0' ;
V_73 = F_255 ( V_21 , V_612 , V_609 ) ;
V_199:
F_91 ( V_612 ) ;
if ( V_73 < 0 )
return V_73 ;
* V_611 += V_609 ;
return V_609 ;
}
static void F_259 ( struct V_16 * V_17 , const T_12 V_615 [ 5 ] )
{
struct V_20 * V_21 = V_17 -> V_19 ;
int V_616 = F_260 ( V_21 ) + 1 ;
int V_617 ;
F_179 ( V_21 ) ;
for ( V_617 = 0 ; V_617 < V_616 ; V_617 ++ ) {
unsigned int V_618 = V_615 [ V_617 ] ;
if ( V_617 > 0 )
V_618 *= 5 ;
F_10 ( V_17 , L_334 ,
V_617 , V_615 [ V_617 ] ,
V_618 / 10 , V_618 % 10 ) ;
}
F_183 ( V_21 ) ;
}
static int F_261 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_259 ( V_17 , F_262 ( V_21 ) -> V_615 . V_619 ) ;
return 0 ;
}
static int F_263 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_259 ( V_17 , F_262 ( V_21 ) -> V_615 . V_620 ) ;
return 0 ;
}
static int F_264 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_259 ( V_17 , F_262 ( V_21 ) -> V_615 . V_621 ) ;
return 0 ;
}
static int F_265 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_191 -> V_192 ;
if ( ! F_79 ( V_21 ) )
return - V_359 ;
return F_229 ( V_106 , F_261 , V_21 ) ;
}
static int F_266 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_191 -> V_192 ;
if ( ! F_79 ( V_21 ) )
return - V_359 ;
return F_229 ( V_106 , F_263 , V_21 ) ;
}
static int F_267 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_191 -> V_192 ;
if ( ! F_79 ( V_21 ) )
return - V_359 ;
return F_229 ( V_106 , F_264 , V_21 ) ;
}
static T_5 F_268 ( struct V_106 * V_106 , const char T_6 * V_185 ,
T_3 V_609 , T_7 * V_611 , T_12 V_615 [ 5 ] )
{
struct V_16 * V_17 = V_106 -> V_190 ;
struct V_20 * V_21 = V_17 -> V_19 ;
T_12 V_622 [ 5 ] = { 0 } ;
int V_616 = F_260 ( V_21 ) + 1 ;
int V_617 ;
int V_73 ;
char V_579 [ 32 ] ;
if ( V_609 >= sizeof( V_579 ) )
return - V_79 ;
if ( F_258 ( V_579 , V_185 , V_609 ) )
return - V_551 ;
V_579 [ V_609 ] = '\0' ;
V_73 = sscanf ( V_579 , L_335 , & V_622 [ 0 ] , & V_622 [ 1 ] , & V_622 [ 2 ] , & V_622 [ 3 ] , & V_622 [ 4 ] ) ;
if ( V_73 != V_616 )
return - V_79 ;
F_179 ( V_21 ) ;
for ( V_617 = 0 ; V_617 < V_616 ; V_617 ++ )
V_615 [ V_617 ] = V_622 [ V_617 ] ;
F_183 ( V_21 ) ;
return V_609 ;
}
static T_5 F_269 ( struct V_106 * V_106 , const char T_6 * V_185 ,
T_3 V_609 , T_7 * V_611 )
{
struct V_16 * V_17 = V_106 -> V_190 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_268 ( V_106 , V_185 , V_609 , V_611 , F_262 ( V_21 ) -> V_615 . V_619 ) ;
}
static T_5 F_270 ( struct V_106 * V_106 , const char T_6 * V_185 ,
T_3 V_609 , T_7 * V_611 )
{
struct V_16 * V_17 = V_106 -> V_190 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_268 ( V_106 , V_185 , V_609 , V_611 , F_262 ( V_21 ) -> V_615 . V_620 ) ;
}
static T_5 F_271 ( struct V_106 * V_106 , const char T_6 * V_185 ,
T_3 V_609 , T_7 * V_611 )
{
struct V_16 * V_17 = V_106 -> V_190 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_268 ( V_106 , V_185 , V_609 , V_611 , F_262 ( V_21 ) -> V_615 . V_621 ) ;
}
static int
F_272 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_202 = F_58 ( & V_66 -> V_623 . V_624 ) ;
return 0 ;
}
static int
F_273 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
F_65 ( V_66 ) ;
F_274 ( V_21 , V_202 ,
L_336 , V_202 ) ;
F_66 ( V_66 ) ;
return 0 ;
}
static int
F_275 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_202 = V_66 -> V_623 . V_625 ;
return 0 ;
}
static int
F_276 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_84 ( L_337 , V_202 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_623 . V_625 = V_202 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_277 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_202 = V_66 -> V_623 . V_626 ;
return 0 ;
}
static int
F_278 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_623 . V_626 = V_202 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_279 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_202 = V_66 -> V_623 . V_627 ;
return 0 ;
}
static int
F_280 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_84 ( L_338 , V_202 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_623 . V_627 = V_202 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_281 ( void * V_18 , T_8 * V_202 )
{
* V_202 = V_628 ;
return 0 ;
}
static int
F_282 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 , * V_629 ;
struct V_68 * V_51 ;
struct V_33 * V_34 , * T_1 ;
int V_73 ;
F_283 ( L_339 , V_202 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( V_202 & V_630 ) {
V_73 = F_284 ( V_21 ) ;
if ( V_73 )
goto V_631;
}
if ( V_202 & ( V_632 | V_630 ) )
F_285 ( V_21 ) ;
if ( V_202 & V_633 ) {
F_21 (vm, &dev_priv->vm_list, global_link) {
F_286 (vma, x, &vm->inactive_list,
mm_list) {
if ( V_34 -> V_35 )
continue;
V_73 = F_287 ( V_34 ) ;
if ( V_73 )
goto V_631;
}
}
}
if ( V_202 & V_634 ) {
F_286 (obj, next, &dev_priv->mm.unbound_list,
global_list)
if ( V_26 -> V_635 == 0 ) {
V_73 = F_288 ( V_26 ) ;
if ( V_73 )
goto V_631;
}
}
V_631:
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int
F_289 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_105 ( V_21 ) || F_106 ( V_21 ) ) )
return - V_359 ;
F_103 ( & V_66 -> V_207 . V_208 ) ;
V_73 = F_27 ( & V_66 -> V_207 . V_260 ) ;
if ( V_73 )
return V_73 ;
if ( F_78 ( V_21 ) )
* V_202 = F_112 ( V_66 , V_66 -> V_207 . V_363 ) ;
else
* V_202 = V_66 -> V_207 . V_363 * V_239 ;
F_7 ( & V_66 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_290 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_221 , V_636 , V_637 ;
int V_73 ;
if ( ! ( F_105 ( V_21 ) || F_106 ( V_21 ) ) )
return - V_359 ;
F_103 ( & V_66 -> V_207 . V_208 ) ;
F_84 ( L_340 , V_202 ) ;
V_73 = F_27 ( & V_66 -> V_207 . V_260 ) ;
if ( V_73 )
return V_73 ;
if ( F_78 ( V_21 ) ) {
V_202 = F_291 ( V_66 , V_202 ) ;
V_636 = F_111 ( V_66 ) ;
V_637 = F_113 ( V_66 ) ;
} else {
F_292 ( V_202 , V_239 ) ;
V_221 = F_69 ( V_222 ) ;
V_636 = V_66 -> V_207 . V_235 ;
V_637 = ( V_221 >> 16 ) & 0xff ;
}
if ( V_202 < V_637 || V_202 > V_636 || V_202 < V_66 -> V_207 . V_362 ) {
F_7 ( & V_66 -> V_207 . V_260 ) ;
return - V_79 ;
}
V_66 -> V_207 . V_363 = V_202 ;
if ( F_78 ( V_21 ) )
F_293 ( V_21 , V_202 ) ;
else
F_294 ( V_21 , V_202 ) ;
F_7 ( & V_66 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_295 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_105 ( V_21 ) || F_106 ( V_21 ) ) )
return - V_359 ;
F_103 ( & V_66 -> V_207 . V_208 ) ;
V_73 = F_27 ( & V_66 -> V_207 . V_260 ) ;
if ( V_73 )
return V_73 ;
if ( F_78 ( V_21 ) )
* V_202 = F_112 ( V_66 , V_66 -> V_207 . V_362 ) ;
else
* V_202 = V_66 -> V_207 . V_362 * V_239 ;
F_7 ( & V_66 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_296 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_221 , V_636 , V_637 ;
int V_73 ;
if ( ! ( F_105 ( V_21 ) || F_106 ( V_21 ) ) )
return - V_359 ;
F_103 ( & V_66 -> V_207 . V_208 ) ;
F_84 ( L_341 , V_202 ) ;
V_73 = F_27 ( & V_66 -> V_207 . V_260 ) ;
if ( V_73 )
return V_73 ;
if ( F_78 ( V_21 ) ) {
V_202 = F_291 ( V_66 , V_202 ) ;
V_636 = F_111 ( V_66 ) ;
V_637 = F_113 ( V_66 ) ;
} else {
F_292 ( V_202 , V_239 ) ;
V_221 = F_69 ( V_222 ) ;
V_636 = V_66 -> V_207 . V_235 ;
V_637 = ( V_221 >> 16 ) & 0xff ;
}
if ( V_202 < V_637 || V_202 > V_636 || V_202 > V_66 -> V_207 . V_363 ) {
F_7 ( & V_66 -> V_207 . V_260 ) ;
return - V_79 ;
}
V_66 -> V_207 . V_362 = V_202 ;
if ( F_78 ( V_21 ) )
F_293 ( V_21 , V_202 ) ;
else
F_294 ( V_21 , V_202 ) ;
F_7 ( & V_66 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_297 ( void * V_18 , T_8 * V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_638 ;
int V_73 ;
if ( ! ( F_105 ( V_21 ) || F_106 ( V_21 ) ) )
return - V_359 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_65 ( V_66 ) ;
V_638 = F_69 ( V_639 ) ;
F_66 ( V_66 ) ;
F_7 ( & V_66 -> V_21 -> V_74 ) ;
* V_202 = ( V_638 & V_640 ) >> V_641 ;
return 0 ;
}
static int
F_298 ( void * V_18 , T_8 V_202 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_638 ;
if ( ! ( F_105 ( V_21 ) || F_106 ( V_21 ) ) )
return - V_359 ;
if ( V_202 > 3 )
return - V_79 ;
F_65 ( V_66 ) ;
F_84 ( L_342 , V_202 ) ;
V_638 = F_69 ( V_639 ) ;
V_638 &= ~ V_640 ;
V_638 |= ( V_202 << V_641 ) ;
F_237 ( V_639 , V_638 ) ;
F_66 ( V_66 ) ;
return 0 ;
}
static int F_299 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_191 -> V_192 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_107 ( V_66 , V_236 ) ;
return 0 ;
}
static int F_300 ( struct V_191 * V_191 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_191 -> V_192 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_109 ( V_66 , V_236 ) ;
return 0 ;
}
static int F_301 ( struct V_4 * V_552 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_223 ( L_343 ,
V_642 ,
V_552 , V_21 ,
& V_643 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_643 ) ;
}
static int F_302 ( struct V_4 * V_552 ,
struct V_2 * V_3 ,
const char * V_47 ,
const struct V_644 * V_645 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_223 ( V_47 ,
V_554 | V_646 ,
V_552 , V_21 ,
V_645 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_645 ) ;
}
void F_303 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
enum V_125 V_125 ;
F_70 (pipe) {
struct V_528 * V_529 = & V_66 -> V_529 [ V_125 ] ;
V_529 -> V_531 = false ;
F_304 ( & V_529 -> V_310 ) ;
F_305 ( & V_529 -> V_546 ) ;
}
}
int F_306 ( struct V_2 * V_3 )
{
int V_73 , V_139 ;
V_73 = F_301 ( V_3 -> V_647 , V_3 ) ;
if ( V_73 )
return V_73 ;
for ( V_139 = 0 ; V_139 < F_226 ( V_553 ) ; V_139 ++ ) {
V_73 = F_222 ( V_3 -> V_647 , V_3 , V_139 ) ;
if ( V_73 )
return V_73 ;
}
for ( V_139 = 0 ; V_139 < F_226 ( V_648 ) ; V_139 ++ ) {
V_73 = F_302 ( V_3 -> V_647 , V_3 ,
V_648 [ V_139 ] . V_47 ,
V_648 [ V_139 ] . V_645 ) ;
if ( V_73 )
return V_73 ;
}
return F_307 ( V_649 ,
V_650 ,
V_3 -> V_647 , V_3 ) ;
}
void F_308 ( struct V_2 * V_3 )
{
int V_139 ;
F_309 ( V_649 ,
V_650 , V_3 ) ;
F_309 ( (struct V_651 * ) & V_643 ,
1 , V_3 ) ;
for ( V_139 = 0 ; V_139 < F_226 ( V_553 ) ; V_139 ++ ) {
struct V_651 * V_652 =
(struct V_651 * ) & V_553 [ V_139 ] ;
F_309 ( V_652 , 1 , V_3 ) ;
}
for ( V_139 = 0 ; V_139 < F_226 ( V_648 ) ; V_139 ++ ) {
struct V_651 * V_652 =
(struct V_651 * ) V_648 [ V_139 ] . V_645 ;
F_309 ( V_652 , 1 , V_3 ) ;
}
}
