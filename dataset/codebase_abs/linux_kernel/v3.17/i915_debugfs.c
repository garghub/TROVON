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
if ( V_26 -> V_59 )
F_10 ( V_17 , L_25 , V_26 -> V_59 ) ;
}
static void F_24 ( struct V_16 * V_17 , struct V_60 * V_61 )
{
F_25 ( V_17 , V_61 -> V_62 . V_63 ? 'I' : 'i' ) ;
F_25 ( V_17 , V_61 -> V_64 ? 'R' : 'r' ) ;
F_25 ( V_17 , ' ' ) ;
}
static int F_26 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_65 * V_66 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_70 * V_51 = & V_68 -> V_71 . V_36 ;
struct V_33 * V_34 ;
T_3 V_72 , V_73 ;
int V_74 , V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
switch ( V_14 ) {
case V_77 :
F_23 ( V_17 , L_26 ) ;
V_66 = & V_51 -> V_78 ;
break;
case V_79 :
F_23 ( V_17 , L_27 ) ;
V_66 = & V_51 -> V_80 ;
break;
default:
F_7 ( & V_21 -> V_76 ) ;
return - V_81 ;
}
V_72 = V_73 = V_74 = 0 ;
F_21 (vma, head, mm_list) {
F_10 ( V_17 , L_28 ) ;
F_19 ( V_17 , V_34 -> V_26 ) ;
F_10 ( V_17 , L_29 ) ;
V_72 += V_34 -> V_26 -> V_36 . V_37 ;
V_73 += V_34 -> V_8 . V_37 ;
V_74 ++ ;
}
F_7 ( & V_21 -> V_76 ) ;
F_10 ( V_17 , L_30 ,
V_74 , V_72 , V_73 ) ;
return 0 ;
}
static int F_28 ( void * V_82 ,
struct V_65 * V_83 , struct V_65 * V_84 )
{
struct V_25 * V_85 =
F_29 ( V_83 , struct V_25 , V_86 ) ;
struct V_25 * V_87 =
F_29 ( V_84 , struct V_25 , V_86 ) ;
return V_85 -> V_53 -> V_52 - V_87 -> V_53 -> V_52 ;
}
static int F_30 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_25 * V_26 ;
T_3 V_72 , V_73 ;
F_31 ( V_53 ) ;
int V_74 , V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_72 = V_73 = V_74 = 0 ;
F_21 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_53 == NULL )
continue;
F_6 ( & V_26 -> V_86 , & V_53 ) ;
V_72 += V_26 -> V_36 . V_37 ;
V_73 += F_32 ( V_26 ) ;
V_74 ++ ;
}
F_21 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_26 -> V_53 == NULL )
continue;
F_6 ( & V_26 -> V_86 , & V_53 ) ;
V_72 += V_26 -> V_36 . V_37 ;
V_74 ++ ;
}
F_33 ( NULL , & V_53 , F_28 ) ;
F_23 ( V_17 , L_31 ) ;
while ( ! F_34 ( & V_53 ) ) {
V_26 = F_35 ( & V_53 , F_36 ( * V_26 ) , V_86 ) ;
F_23 ( V_17 , L_28 ) ;
F_19 ( V_17 , V_26 ) ;
F_25 ( V_17 , '\n' ) ;
F_37 ( & V_26 -> V_86 ) ;
}
F_7 ( & V_21 -> V_76 ) ;
F_10 ( V_17 , L_30 ,
V_74 , V_72 , V_73 ) ;
return 0 ;
}
static int F_38 ( int V_88 , void * V_89 , void * V_18 )
{
struct V_25 * V_26 = V_89 ;
struct V_90 * V_91 = V_18 ;
struct V_33 * V_34 ;
V_91 -> V_74 ++ ;
V_91 -> V_92 += V_26 -> V_36 . V_37 ;
if ( V_26 -> V_36 . V_47 || V_26 -> V_36 . V_93 )
V_91 -> V_94 += V_26 -> V_36 . V_37 ;
if ( F_39 ( V_26 -> V_36 . V_21 ) ) {
F_21 (vma, &obj->vma_list, vma_link) {
struct V_95 * V_96 ;
if ( ! F_40 ( & V_34 -> V_8 ) )
continue;
if ( F_22 ( V_34 -> V_51 ) ) {
V_91 -> V_97 += V_26 -> V_36 . V_37 ;
continue;
}
V_96 = F_29 ( V_34 -> V_51 , struct V_95 , V_36 ) ;
if ( V_96 -> V_61 && V_96 -> V_61 -> V_98 != V_91 -> V_98 )
continue;
if ( V_26 -> V_58 )
V_91 -> V_99 += V_26 -> V_36 . V_37 ;
else
V_91 -> V_100 += V_26 -> V_36 . V_37 ;
return 0 ;
}
} else {
if ( F_41 ( V_26 ) ) {
V_91 -> V_97 += V_26 -> V_36 . V_37 ;
if ( V_26 -> V_58 )
V_91 -> V_99 += V_26 -> V_36 . V_37 ;
else
V_91 -> V_100 += V_26 -> V_36 . V_37 ;
return 0 ;
}
}
if ( ! F_34 ( & V_26 -> V_101 ) )
V_91 -> V_102 += V_26 -> V_36 . V_37 ;
return 0 ;
}
static int F_42 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_74 , V_103 , V_104 ;
T_3 V_37 , V_105 , V_106 ;
struct V_25 * V_26 ;
struct V_70 * V_51 = & V_68 -> V_71 . V_36 ;
struct V_107 * V_108 ;
struct V_33 * V_34 ;
int V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_10 ( V_17 , L_32 ,
V_68 -> V_109 . V_110 ,
V_68 -> V_109 . V_111 ) ;
V_37 = V_74 = V_105 = V_103 = 0 ;
F_43 ( & V_68 -> V_109 . V_112 , V_101 ) ;
F_10 ( V_17 , L_33 ,
V_74 , V_103 , V_37 , V_105 ) ;
V_37 = V_74 = V_105 = V_103 = 0 ;
F_44 ( & V_51 -> V_78 , V_113 ) ;
F_10 ( V_17 , L_34 ,
V_74 , V_103 , V_37 , V_105 ) ;
V_37 = V_74 = V_105 = V_103 = 0 ;
F_44 ( & V_51 -> V_80 , V_113 ) ;
F_10 ( V_17 , L_35 ,
V_74 , V_103 , V_37 , V_105 ) ;
V_37 = V_74 = V_106 = V_104 = 0 ;
F_21 (obj, &dev_priv->mm.unbound_list, global_list) {
V_37 += V_26 -> V_36 . V_37 , ++ V_74 ;
if ( V_26 -> V_45 == V_46 )
V_106 += V_26 -> V_36 . V_37 , ++ V_104 ;
}
F_10 ( V_17 , L_36 , V_74 , V_37 ) ;
V_37 = V_74 = V_105 = V_103 = 0 ;
F_21 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_55 ) {
V_37 += F_32 ( V_26 ) ;
++ V_74 ;
}
if ( V_26 -> V_54 ) {
V_105 += F_32 ( V_26 ) ;
++ V_103 ;
}
if ( V_26 -> V_45 == V_46 ) {
V_106 += V_26 -> V_36 . V_37 ;
++ V_104 ;
}
}
F_10 ( V_17 , L_37 ,
V_104 , V_106 ) ;
F_10 ( V_17 , L_38 ,
V_103 , V_105 ) ;
F_10 ( V_17 , L_39 ,
V_74 , V_37 ) ;
F_10 ( V_17 , L_40 ,
V_68 -> V_71 . V_36 . V_92 ,
V_68 -> V_71 . V_114 - V_68 -> V_71 . V_36 . V_52 ) ;
F_25 ( V_17 , '\n' ) ;
F_45 (file, &dev->filelist, lhead) {
struct V_90 V_91 ;
struct V_115 * V_116 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_98 = V_108 -> V_117 ;
F_46 ( & V_108 -> V_118 ) ;
F_47 ( & V_108 -> V_119 , F_38 , & V_91 ) ;
F_48 ( & V_108 -> V_118 ) ;
F_49 () ;
V_116 = F_50 ( V_108 -> V_120 , V_121 ) ;
F_10 ( V_17 , L_41 ,
V_116 ? V_116 -> V_122 : L_42 ,
V_91 . V_74 ,
V_91 . V_92 ,
V_91 . V_99 ,
V_91 . V_100 ,
V_91 . V_97 ,
V_91 . V_94 ,
V_91 . V_102 ) ;
F_51 () ;
}
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_52 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_25 * V_26 ;
T_3 V_72 , V_73 ;
int V_74 , V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_72 = V_73 = V_74 = 0 ;
F_21 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_14 == V_123 && ! F_16 ( V_26 ) )
continue;
F_23 ( V_17 , L_28 ) ;
F_19 ( V_17 , V_26 ) ;
F_25 ( V_17 , '\n' ) ;
V_72 += V_26 -> V_36 . V_37 ;
V_73 += F_32 ( V_26 ) ;
V_74 ++ ;
}
F_7 ( & V_21 -> V_76 ) ;
F_10 ( V_17 , L_30 ,
V_74 , V_72 , V_73 ) ;
return 0 ;
}
static int F_53 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
unsigned long V_124 ;
struct V_125 * V_126 ;
int V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_54 (dev, crtc) {
const char V_127 = F_55 ( V_126 -> V_127 ) ;
const char V_128 = F_56 ( V_126 -> V_128 ) ;
struct V_129 * V_130 ;
F_57 ( & V_21 -> V_131 , V_124 ) ;
V_130 = V_126 -> V_132 ;
if ( V_130 == NULL ) {
F_10 ( V_17 , L_43 ,
V_127 , V_128 ) ;
} else {
if ( F_58 ( & V_130 -> V_133 ) < V_134 ) {
F_10 ( V_17 , L_44 ,
V_127 , V_128 ) ;
} else {
F_10 ( V_17 , L_45 ,
V_127 , V_128 ) ;
}
if ( V_130 -> V_135 )
F_23 ( V_17 , L_46 ) ;
else
F_23 ( V_17 , L_47 ) ;
F_10 ( V_17 , L_48 , F_58 ( & V_130 -> V_133 ) ) ;
if ( V_130 -> V_136 ) {
struct V_25 * V_26 = V_130 -> V_136 ;
if ( V_26 )
F_10 ( V_17 , L_49 ,
F_59 ( V_26 ) ) ;
}
if ( V_130 -> V_137 ) {
struct V_25 * V_26 = V_130 -> V_137 ;
if ( V_26 )
F_10 ( V_17 , L_50 ,
F_59 ( V_26 ) ) ;
}
}
F_60 ( & V_21 -> V_131 , V_124 ) ;
}
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_61 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
struct V_139 * V_140 ;
int V_75 , V_74 , V_141 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_74 = 0 ;
F_62 (ring, dev_priv, i) {
if ( F_34 ( & V_58 -> V_142 ) )
continue;
F_10 ( V_17 , L_51 , V_58 -> V_47 ) ;
F_21 (gem_request,
&ring->request_list,
list) {
F_10 ( V_17 , L_52 ,
V_140 -> V_143 ,
( int ) ( V_144 - V_140 -> V_145 ) ) ;
}
V_74 ++ ;
}
F_7 ( & V_21 -> V_76 ) ;
if ( V_74 == 0 )
F_23 ( V_17 , L_53 ) ;
return 0 ;
}
static void F_63 ( struct V_16 * V_17 ,
struct V_138 * V_58 )
{
if ( V_58 -> V_146 ) {
F_10 ( V_17 , L_54 ,
V_58 -> V_47 , V_58 -> V_146 ( V_58 , false ) ) ;
}
}
static int F_64 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
int V_75 , V_141 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
F_62 (ring, dev_priv, i)
F_63 ( V_17 , V_58 ) ;
F_66 ( V_68 ) ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_67 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
int V_75 , V_141 , V_127 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
if ( F_68 ( V_21 ) ) {
int V_141 ;
F_10 ( V_17 , L_55 ,
F_69 ( V_147 ) ) ;
F_10 ( V_17 , L_56 ,
F_69 ( V_148 ) ) ;
F_10 ( V_17 , L_57 ,
F_69 ( V_149 ) ) ;
F_10 ( V_17 , L_58 ,
F_69 ( V_150 ) ) ;
F_10 ( V_17 , L_59 ,
F_69 ( V_151 ) ) ;
F_70 (pipe)
F_10 ( V_17 , L_60 ,
F_55 ( V_127 ) ,
F_69 ( F_71 ( V_127 ) ) ) ;
F_10 ( V_17 , L_61 ,
F_69 ( V_152 ) ) ;
F_10 ( V_17 , L_62 ,
F_69 ( V_153 ) ) ;
F_10 ( V_17 , L_63 ,
F_69 ( V_154 ) ) ;
for ( V_141 = 0 ; V_141 < 4 ; V_141 ++ ) {
F_10 ( V_17 , L_64 ,
V_141 , F_69 ( F_72 ( V_141 ) ) ) ;
F_10 ( V_17 , L_65 ,
V_141 , F_69 ( F_73 ( V_141 ) ) ) ;
F_10 ( V_17 , L_66 ,
V_141 , F_69 ( F_74 ( V_141 ) ) ) ;
}
F_10 ( V_17 , L_67 ,
F_69 ( V_155 ) ) ;
F_10 ( V_17 , L_68 ,
F_69 ( V_156 ) ) ;
F_10 ( V_17 , L_69 ,
F_69 ( V_157 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_10 ( V_17 , L_55 ,
F_69 ( V_147 ) ) ;
for ( V_141 = 0 ; V_141 < 4 ; V_141 ++ ) {
F_10 ( V_17 , L_64 ,
V_141 , F_69 ( F_72 ( V_141 ) ) ) ;
F_10 ( V_17 , L_65 ,
V_141 , F_69 ( F_73 ( V_141 ) ) ) ;
F_10 ( V_17 , L_66 ,
V_141 , F_69 ( F_74 ( V_141 ) ) ) ;
}
F_70 (pipe) {
F_10 ( V_17 , L_70 ,
F_55 ( V_127 ) ,
F_69 ( F_75 ( V_127 ) ) ) ;
F_10 ( V_17 , L_71 ,
F_55 ( V_127 ) ,
F_69 ( F_76 ( V_127 ) ) ) ;
F_10 ( V_17 , L_72 ,
F_55 ( V_127 ) ,
F_69 ( F_77 ( V_127 ) ) ) ;
}
F_10 ( V_17 , L_73 ,
F_69 ( V_158 ) ) ;
F_10 ( V_17 , L_74 ,
F_69 ( V_159 ) ) ;
F_10 ( V_17 , L_75 ,
F_69 ( V_160 ) ) ;
F_10 ( V_17 , L_76 ,
F_69 ( V_161 ) ) ;
F_10 ( V_17 , L_77 ,
F_69 ( V_162 ) ) ;
F_10 ( V_17 , L_78 ,
F_69 ( V_163 ) ) ;
F_10 ( V_17 , L_67 ,
F_69 ( V_155 ) ) ;
F_10 ( V_17 , L_68 ,
F_69 ( V_156 ) ) ;
F_10 ( V_17 , L_69 ,
F_69 ( V_157 ) ) ;
} else if ( F_78 ( V_21 ) ) {
F_10 ( V_17 , L_56 ,
F_69 ( V_148 ) ) ;
F_10 ( V_17 , L_57 ,
F_69 ( V_149 ) ) ;
F_10 ( V_17 , L_58 ,
F_69 ( V_150 ) ) ;
F_10 ( V_17 , L_59 ,
F_69 ( V_151 ) ) ;
F_70 (pipe)
F_10 ( V_17 , L_60 ,
F_55 ( V_127 ) ,
F_69 ( F_71 ( V_127 ) ) ) ;
F_10 ( V_17 , L_79 ,
F_69 ( V_164 ) ) ;
F_10 ( V_17 , L_80 ,
F_69 ( V_165 ) ) ;
F_10 ( V_17 , L_81 ,
F_69 ( V_166 ) ) ;
F_10 ( V_17 , L_82 ,
F_69 ( V_167 ) ) ;
F_10 ( V_17 , L_83 ,
F_69 ( V_168 ) ) ;
F_10 ( V_17 , L_84 ,
F_69 ( V_169 ) ) ;
F_10 ( V_17 , L_85 ,
F_69 ( V_170 ) ) ;
F_10 ( V_17 , L_61 ,
F_69 ( V_152 ) ) ;
F_10 ( V_17 , L_62 ,
F_69 ( V_153 ) ) ;
F_10 ( V_17 , L_63 ,
F_69 ( V_154 ) ) ;
} else if ( ! F_79 ( V_21 ) ) {
F_10 ( V_17 , L_86 ,
F_69 ( V_171 ) ) ;
F_10 ( V_17 , L_87 ,
F_69 ( V_172 ) ) ;
F_10 ( V_17 , L_88 ,
F_69 ( V_173 ) ) ;
F_70 (pipe)
F_10 ( V_17 , L_89 ,
F_55 ( V_127 ) ,
F_69 ( F_71 ( V_127 ) ) ) ;
} else {
F_10 ( V_17 , L_90 ,
F_69 ( V_174 ) ) ;
F_10 ( V_17 , L_91 ,
F_69 ( V_175 ) ) ;
F_10 ( V_17 , L_92 ,
F_69 ( V_176 ) ) ;
F_10 ( V_17 , L_93 ,
F_69 ( V_177 ) ) ;
F_10 ( V_17 , L_94 ,
F_69 ( V_178 ) ) ;
F_10 ( V_17 , L_95 ,
F_69 ( V_179 ) ) ;
F_10 ( V_17 , L_96 ,
F_69 ( V_165 ) ) ;
F_10 ( V_17 , L_97 ,
F_69 ( V_166 ) ) ;
F_10 ( V_17 , L_98 ,
F_69 ( V_167 ) ) ;
}
F_62 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_99 ,
V_58 -> V_47 , F_80 ( V_58 ) ) ;
}
F_63 ( V_17 , V_58 ) ;
}
F_66 ( V_68 ) ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_81 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_141 , V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_10 ( V_17 , L_100 , V_68 -> V_180 ) ;
F_10 ( V_17 , L_101 , V_68 -> V_181 ) ;
for ( V_141 = 0 ; V_141 < V_68 -> V_181 ; V_141 ++ ) {
struct V_25 * V_26 = V_68 -> V_182 [ V_141 ] . V_26 ;
F_10 ( V_17 , L_102 ,
V_141 , V_68 -> V_182 [ V_141 ] . V_35 ) ;
if ( V_26 == NULL )
F_23 ( V_17 , L_103 ) ;
else
F_19 ( V_17 , V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_82 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
const T_4 * V_183 ;
int V_141 ;
V_58 = & V_68 -> V_58 [ ( T_2 ) V_8 -> V_12 -> V_18 ] ;
V_183 = V_58 -> V_184 . V_185 ;
if ( V_183 == NULL )
return 0 ;
for ( V_141 = 0 ; V_141 < 4096 / sizeof( T_4 ) / 4 ; V_141 += 4 ) {
F_10 ( V_17 , L_104 ,
V_141 * 4 ,
V_183 [ V_141 ] , V_183 [ V_141 + 1 ] , V_183 [ V_141 + 2 ] , V_183 [ V_141 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_83 ( struct V_108 * V_186 ,
const char T_6 * V_187 ,
T_3 V_188 ,
T_7 * V_189 )
{
struct V_190 * V_191 = V_186 -> V_192 ;
struct V_20 * V_21 = V_191 -> V_21 ;
int V_75 ;
F_84 ( L_105 ) ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_85 ( V_21 ) ;
F_7 ( & V_21 -> V_76 ) ;
return V_188 ;
}
static int F_86 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_20 * V_21 = V_193 -> V_194 ;
struct V_190 * V_191 ;
V_191 = F_87 ( sizeof( * V_191 ) , V_9 ) ;
if ( ! V_191 )
return - V_10 ;
V_191 -> V_21 = V_21 ;
F_88 ( V_21 , V_191 ) ;
V_108 -> V_192 = V_191 ;
return 0 ;
}
static int F_89 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_190 * V_191 = V_108 -> V_192 ;
F_90 ( V_191 ) ;
F_91 ( V_191 ) ;
return 0 ;
}
static T_5 F_92 ( struct V_108 * V_108 , char T_6 * V_195 ,
T_3 V_74 , T_7 * V_196 )
{
struct V_190 * V_191 = V_108 -> V_192 ;
struct V_197 V_198 ;
T_7 V_199 = 0 ;
T_5 V_200 = 0 ;
int V_75 ;
V_75 = F_93 ( & V_198 , V_74 , * V_196 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_94 ( & V_198 , V_191 ) ;
if ( V_75 )
goto V_201;
V_200 = F_95 ( V_195 , V_74 , & V_199 ,
V_198 . V_202 ,
V_198 . V_203 ) ;
if ( V_200 < 0 )
V_75 = V_200 ;
else
* V_196 = V_198 . V_52 + V_200 ;
V_201:
F_96 ( & V_198 ) ;
return V_75 ? : V_200 ;
}
static int
F_97 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
* V_204 = V_68 -> V_205 ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int
F_98 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
int V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_99 ( V_21 , V_204 ) ;
F_7 ( & V_21 -> V_76 ) ;
return V_75 ;
}
static int F_100 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 = 0 ;
F_65 ( V_68 ) ;
F_101 ( & V_68 -> V_207 . V_208 ) ;
if ( F_102 ( V_21 ) ) {
T_9 V_209 = F_103 ( V_210 ) ;
T_9 V_211 = F_103 ( V_212 ) ;
F_10 ( V_17 , L_106 , ( V_209 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_107 , V_209 & 0x3f ) ;
F_10 ( V_17 , L_108 , ( V_211 & V_213 ) >>
V_214 ) ;
F_10 ( V_17 , L_109 ,
( V_211 & V_215 ) >> V_216 ) ;
} else if ( F_104 ( V_21 ) || ( F_105 ( V_21 ) && ! F_78 ( V_21 ) ) ||
F_106 ( V_21 ) ) {
T_4 V_217 = F_69 ( V_218 ) ;
T_4 V_219 = F_69 ( V_220 ) ;
T_4 V_221 = F_69 ( V_222 ) ;
T_4 V_223 , V_224 , V_225 ;
T_4 V_226 , V_227 , V_228 ;
T_4 V_229 , V_230 , V_231 ;
T_4 V_232 , V_233 , V_234 ;
int V_235 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
goto V_201;
F_107 ( V_68 , V_236 ) ;
V_228 = F_69 ( V_237 ) ;
V_228 &= ~ V_238 ;
if ( F_108 ( V_21 ) || F_106 ( V_21 ) )
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
if ( F_108 ( V_21 ) || F_106 ( V_21 ) )
V_227 = ( V_226 & V_250 ) >> V_251 ;
else
V_227 = ( V_226 & V_252 ) >> V_253 ;
V_227 *= V_239 ;
F_109 ( V_68 , V_236 ) ;
F_7 ( & V_21 -> V_76 ) ;
F_10 ( V_17 , L_110 ,
F_69 ( V_168 ) ,
F_69 ( V_170 ) ,
F_69 ( V_254 ) ,
F_69 ( V_169 ) ,
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
V_68 -> V_207 . V_235 * V_239 ) ;
} else if ( F_78 ( V_21 ) ) {
T_4 V_259 ;
F_5 ( & V_68 -> V_207 . V_260 ) ;
V_259 = F_110 ( V_68 , V_261 ) ;
F_10 ( V_17 , L_131 , V_259 ) ;
F_10 ( V_17 , L_132 , V_68 -> V_262 ) ;
F_10 ( V_17 , L_133 ,
F_111 ( V_68 , V_68 -> V_207 . V_235 ) ) ;
F_10 ( V_17 , L_134 ,
F_111 ( V_68 , V_68 -> V_207 . V_263 ) ) ;
F_10 ( V_17 , L_135 ,
F_111 ( V_68 , V_68 -> V_207 . V_264 ) ) ;
F_10 ( V_17 , L_136 ,
F_111 ( V_68 , ( V_259 >> 8 ) & 0xff ) ) ;
F_7 ( & V_68 -> V_207 . V_260 ) ;
} else {
F_23 ( V_17 , L_137 ) ;
}
V_201:
F_66 ( V_68 ) ;
return V_75 ;
}
static int F_112 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_265 , V_266 ;
T_9 V_267 ;
int V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
V_265 = F_69 ( V_268 ) ;
V_266 = F_69 ( V_269 ) ;
V_267 = F_103 ( V_270 ) ;
F_66 ( V_68 ) ;
F_7 ( & V_21 -> V_76 ) ;
F_10 ( V_17 , L_138 , ( V_265 & V_271 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_139 ,
( V_265 & V_272 ) >>
V_273 ) ;
F_10 ( V_17 , L_140 ,
V_265 & V_274 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_141 ,
V_265 & V_275 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_142 ,
V_265 & V_276 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_143 ,
( V_265 & V_277 ) >> V_278 ) ;
F_10 ( V_17 , L_144 ,
( V_265 & V_279 ) >> V_280 ) ;
F_10 ( V_17 , L_145 , ( V_265 & V_281 ) ) ;
F_10 ( V_17 , L_146 , ( V_267 & 0x3f ) ) ;
F_10 ( V_17 , L_147 , ( ( V_267 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_148 ,
( V_266 & V_282 ) ? L_2 : L_1 ) ;
F_23 ( V_17 , L_149 ) ;
switch ( V_266 & V_283 ) {
case V_284 :
F_23 ( V_17 , L_150 ) ;
break;
case V_285 :
F_23 ( V_17 , L_151 ) ;
break;
case V_286 :
F_23 ( V_17 , L_152 ) ;
break;
case V_287 :
F_23 ( V_17 , L_153 ) ;
break;
case V_288 :
F_23 ( V_17 , L_154 ) ;
break;
case V_289 :
F_23 ( V_17 , L_155 ) ;
break;
default:
F_23 ( V_17 , L_156 ) ;
break;
}
return 0 ;
}
static int F_113 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_290 , V_291 ;
unsigned V_292 = 0 , V_293 = 0 ;
F_65 ( V_68 ) ;
V_290 = F_69 ( V_240 ) ;
V_291 = F_69 ( V_294 ) ;
F_66 ( V_68 ) ;
F_10 ( V_17 , L_157 ,
F_1 ( V_290 & V_295 ) ) ;
F_10 ( V_17 , L_158 ,
F_1 ( V_290 & V_296 ) ) ;
F_10 ( V_17 , L_140 ,
F_1 ( V_290 & V_296 ) ) ;
F_10 ( V_17 , L_141 ,
F_1 ( ( V_290 & V_297 ) ==
V_298 ) ) ;
F_10 ( V_17 , L_159 ,
F_1 ( V_291 & ( V_299 |
F_114 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_160 ,
( F_69 ( V_300 ) &
V_301 ) ? L_161 : L_162 ) ;
F_10 ( V_17 , L_163 ,
( F_69 ( V_300 ) &
V_302 ) ? L_161 : L_162 ) ;
F_10 ( V_17 , L_164 ,
F_69 ( V_303 ) ) ;
F_10 ( V_17 , L_165 ,
F_69 ( V_304 ) ) ;
F_115 ( & V_68 -> V_305 . V_306 ) ;
V_292 = V_68 -> V_305 . V_292 ;
V_293 = V_68 -> V_305 . V_293 ;
F_116 ( & V_68 -> V_305 . V_306 ) ;
F_10 ( V_17 , L_166 , V_292 ) ;
F_10 ( V_17 , L_167 , V_293 ) ;
return 0 ;
}
static int F_117 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_290 , V_307 , V_291 , V_308 = 0 ;
unsigned V_309 ;
int V_74 = 0 , V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
F_115 ( & V_68 -> V_305 . V_306 ) ;
V_309 = V_68 -> V_305 . V_309 ;
F_116 ( & V_68 -> V_305 . V_306 ) ;
if ( V_309 ) {
F_23 ( V_17 , L_168
L_169 ) ;
} else {
while ( V_74 ++ < 50 && ( F_118 ( V_310 ) & 1 ) )
F_119 ( 10 ) ;
F_10 ( V_17 , L_170 , F_1 ( V_74 < 51 ) ) ;
}
V_307 = F_120 ( V_68 -> V_311 + V_312 ) ;
F_121 ( false , V_312 , V_307 , 4 , true ) ;
V_290 = F_69 ( V_240 ) ;
V_291 = F_69 ( V_294 ) ;
F_7 ( & V_21 -> V_76 ) ;
F_5 ( & V_68 -> V_207 . V_260 ) ;
F_122 ( V_68 , V_313 , & V_308 ) ;
F_7 ( & V_68 -> V_207 . V_260 ) ;
F_66 ( V_68 ) ;
F_10 ( V_17 , L_157 ,
F_1 ( V_290 & V_295 ) ) ;
F_10 ( V_17 , L_140 ,
F_1 ( V_290 & V_296 ) ) ;
F_10 ( V_17 , L_141 ,
F_1 ( ( V_290 & V_297 ) ==
V_298 ) ) ;
F_10 ( V_17 , L_171 ,
F_1 ( V_291 & V_314 ) ) ;
F_10 ( V_17 , L_159 ,
F_1 ( V_291 & V_315 ) ) ;
F_10 ( V_17 , L_172 ,
F_1 ( V_291 & V_316 ) ) ;
F_10 ( V_17 , L_173 ,
F_1 ( V_291 & V_317 ) ) ;
F_23 ( V_17 , L_174 ) ;
switch ( V_307 & V_318 ) {
case V_319 :
if ( V_307 & V_320 )
F_23 ( V_17 , L_175 ) ;
else
F_23 ( V_17 , L_150 ) ;
break;
case V_321 :
F_23 ( V_17 , L_176 ) ;
break;
case V_322 :
F_23 ( V_17 , L_177 ) ;
break;
case V_323 :
F_23 ( V_17 , L_178 ) ;
break;
default:
F_23 ( V_17 , L_179 ) ;
break;
}
F_10 ( V_17 , L_180 ,
F_1 ( V_307 & V_320 ) ) ;
F_10 ( V_17 , L_181 ,
F_69 ( V_324 ) ) ;
F_10 ( V_17 , L_182 ,
F_69 ( V_325 ) ) ;
F_10 ( V_17 , L_183 ,
F_69 ( V_326 ) ) ;
F_10 ( V_17 , L_184 ,
F_69 ( V_327 ) ) ;
F_10 ( V_17 , L_185 ,
F_123 ( ( ( V_308 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_186 ,
F_123 ( ( ( V_308 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_187 ,
F_123 ( ( ( V_308 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_124 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_78 ( V_21 ) )
return F_113 ( V_17 ) ;
else if ( F_104 ( V_21 ) || F_105 ( V_21 ) )
return F_117 ( V_17 ) ;
else
return F_112 ( V_17 ) ;
}
static int F_125 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
if ( ! F_126 ( V_21 ) ) {
F_23 ( V_17 , L_188 ) ;
return 0 ;
}
F_65 ( V_68 ) ;
if ( F_127 ( V_21 ) ) {
F_23 ( V_17 , L_189 ) ;
} else {
F_23 ( V_17 , L_190 ) ;
switch ( V_68 -> V_328 . V_329 ) {
case V_330 :
F_23 ( V_17 , L_191 ) ;
break;
case V_331 :
F_23 ( V_17 , L_192 ) ;
break;
case V_332 :
F_23 ( V_17 , L_193 ) ;
break;
case V_333 :
F_23 ( V_17 , L_194 ) ;
break;
case V_334 :
F_23 ( V_17 , L_195 ) ;
break;
case V_335 :
F_23 ( V_17 , L_196 ) ;
break;
case V_336 :
F_23 ( V_17 , L_197 ) ;
break;
case V_337 :
F_23 ( V_17 , L_198 ) ;
break;
case V_338 :
F_23 ( V_17 , L_199 ) ;
break;
case V_339 :
F_23 ( V_17 , L_200 ) ;
break;
case V_340 :
F_23 ( V_17 , L_201 ) ;
break;
default:
F_23 ( V_17 , L_202 ) ;
}
F_25 ( V_17 , '\n' ) ;
}
F_66 ( V_68 ) ;
return 0 ;
}
static int F_128 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
if ( ! F_129 ( V_21 ) ) {
F_23 ( V_17 , L_203 ) ;
return 0 ;
}
F_65 ( V_68 ) ;
F_10 ( V_17 , L_204 ,
F_1 ( V_341 . V_342 ) ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_23 ( V_17 , L_205 ) ;
} else {
if ( F_69 ( V_343 ) & V_344 )
F_23 ( V_17 , L_206 ) ;
else
F_23 ( V_17 , L_207 ) ;
}
F_66 ( V_68 ) ;
return 0 ;
}
static int F_130 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
bool V_345 = false ;
F_65 ( V_68 ) ;
if ( F_79 ( V_21 ) )
V_345 = F_69 ( V_346 ) & V_347 ;
else if ( F_131 ( V_21 ) || F_132 ( V_21 ) || F_133 ( V_21 ) )
V_345 = F_69 ( V_348 ) & V_349 ;
else if ( F_134 ( V_21 ) )
V_345 = F_69 ( V_350 ) & V_351 ;
else if ( F_135 ( V_21 ) )
V_345 = F_69 ( V_352 ) & V_353 ;
F_66 ( V_68 ) ;
F_10 ( V_17 , L_208 ,
V_345 ? L_209 : L_210 ) ;
return 0 ;
}
static int F_136 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
unsigned long V_354 , V_355 , V_356 ;
int V_75 ;
if ( ! F_102 ( V_21 ) )
return - V_357 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_354 = F_137 ( V_68 ) ;
V_355 = F_138 ( V_68 ) ;
V_356 = F_139 ( V_68 ) ;
F_7 ( & V_21 -> V_76 ) ;
F_10 ( V_17 , L_211 , V_354 ) ;
F_10 ( V_17 , L_212 , V_355 ) ;
F_10 ( V_17 , L_213 , V_356 ) ;
F_10 ( V_17 , L_214 , V_355 + V_356 ) ;
return 0 ;
}
static int F_140 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 = 0 ;
int V_358 , V_359 ;
if ( ! ( F_104 ( V_21 ) || F_105 ( V_21 ) ) ) {
F_23 ( V_17 , L_215 ) ;
return 0 ;
}
F_65 ( V_68 ) ;
F_101 ( & V_68 -> V_207 . V_208 ) ;
V_75 = F_27 ( & V_68 -> V_207 . V_260 ) ;
if ( V_75 )
goto V_201;
F_23 ( V_17 , L_216 ) ;
for ( V_358 = V_68 -> V_207 . V_360 ;
V_358 <= V_68 -> V_207 . V_361 ;
V_358 ++ ) {
V_359 = V_358 ;
F_122 ( V_68 ,
V_362 ,
& V_359 ) ;
F_10 ( V_17 , L_217 ,
V_358 * V_239 ,
( ( V_359 >> 0 ) & 0xff ) * 100 ,
( ( V_359 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_68 -> V_207 . V_260 ) ;
V_201:
F_66 ( V_68 ) ;
return V_75 ;
}
static int F_141 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_363 * V_364 = & V_68 -> V_364 ;
void * V_18 = F_3 ( V_365 , V_9 ) ;
int V_75 ;
if ( V_18 == NULL )
return - V_10 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
goto V_201;
if ( V_364 -> V_366 ) {
F_142 ( V_18 , V_364 -> V_366 , V_365 ) ;
F_143 ( V_17 , V_18 , V_365 ) ;
}
F_7 ( & V_21 -> V_76 ) ;
V_201:
F_91 ( V_18 ) ;
return 0 ;
}
static int F_144 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_367 * V_368 = NULL ;
struct V_369 * V_370 ;
#ifdef F_145
struct V_67 * V_68 = V_21 -> V_69 ;
V_368 = V_68 -> V_371 ;
V_370 = F_146 ( V_368 -> V_372 . V_370 ) ;
F_10 ( V_17 , L_218 ,
V_370 -> V_36 . V_373 ,
V_370 -> V_36 . V_374 ,
V_370 -> V_36 . V_375 ,
V_370 -> V_36 . V_376 ,
F_58 ( & V_370 -> V_36 . V_377 . V_377 ) ) ;
F_19 ( V_17 , V_370 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
#endif
F_5 ( & V_21 -> V_378 . V_379 ) ;
F_21 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_368 && & V_370 -> V_36 == V_368 -> V_372 . V_370 )
continue;
F_10 ( V_17 , L_219 ,
V_370 -> V_36 . V_373 ,
V_370 -> V_36 . V_374 ,
V_370 -> V_36 . V_375 ,
V_370 -> V_36 . V_376 ,
F_58 ( & V_370 -> V_36 . V_377 . V_377 ) ) ;
F_19 ( V_17 , V_370 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_378 . V_379 ) ;
return 0 ;
}
static int F_147 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
struct V_60 * V_61 ;
int V_75 , V_141 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
if ( V_68 -> V_380 . V_381 ) {
F_23 ( V_17 , L_220 ) ;
F_19 ( V_17 , V_68 -> V_380 . V_381 ) ;
F_25 ( V_17 , '\n' ) ;
}
if ( V_68 -> V_380 . V_382 ) {
F_23 ( V_17 , L_221 ) ;
F_19 ( V_17 , V_68 -> V_380 . V_382 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_21 (ctx, &dev_priv->context_list, link) {
if ( V_61 -> V_62 . V_383 == NULL )
continue;
F_23 ( V_17 , L_222 ) ;
F_24 ( V_17 , V_61 ) ;
F_62 (ring, dev_priv, i)
if ( V_58 -> V_384 == V_61 )
F_10 ( V_17 , L_223 , V_58 -> V_47 ) ;
F_19 ( V_17 , V_61 -> V_62 . V_383 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_148 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
unsigned V_309 = 0 , V_292 = 0 , V_293 = 0 ;
F_115 ( & V_68 -> V_305 . V_306 ) ;
if ( F_78 ( V_21 ) ) {
V_292 = V_68 -> V_305 . V_292 ;
V_293 = V_68 -> V_305 . V_293 ;
} else
V_309 = V_68 -> V_305 . V_309 ;
F_116 ( & V_68 -> V_305 . V_306 ) ;
if ( F_78 ( V_21 ) ) {
F_10 ( V_17 , L_224 , V_292 ) ;
F_10 ( V_17 , L_225 , V_293 ) ;
} else
F_10 ( V_17 , L_226 , V_309 ) ;
return 0 ;
}
static const char * F_149 ( unsigned V_385 )
{
switch ( V_385 ) {
case V_386 :
return L_227 ;
case V_387 :
return L_228 ;
case V_388 :
return L_229 ;
case V_389 :
return L_230 ;
case V_390 :
return L_231 ;
case V_391 :
return L_232 ;
case V_392 :
return L_233 ;
case V_393 :
return L_234 ;
}
return L_235 ;
}
static int F_150 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
F_10 ( V_17 , L_236 ,
F_149 ( V_68 -> V_109 . V_394 ) ) ;
F_10 ( V_17 , L_237 ,
F_149 ( V_68 -> V_109 . V_395 ) ) ;
if ( F_151 ( V_21 ) || F_152 ( V_21 ) ) {
F_10 ( V_17 , L_238 ,
F_69 ( V_396 ) ) ;
F_10 ( V_17 , L_239 ,
F_103 ( V_397 ) ) ;
F_10 ( V_17 , L_240 ,
F_103 ( V_398 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_241 ,
F_69 ( V_399 ) ) ;
F_10 ( V_17 , L_242 ,
F_69 ( V_400 ) ) ;
F_10 ( V_17 , L_243 ,
F_69 ( V_401 ) ) ;
F_10 ( V_17 , L_244 ,
F_69 ( V_402 ) ) ;
if ( F_153 ( V_21 ) )
F_10 ( V_17 , L_245 ,
F_69 ( V_403 ) ) ;
else
F_10 ( V_17 , L_246 ,
F_69 ( V_404 ) ) ;
F_10 ( V_17 , L_247 ,
F_69 ( V_405 ) ) ;
}
F_66 ( V_68 ) ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_154 ( int V_88 , void * V_89 , void * V_18 )
{
struct V_60 * V_61 = V_89 ;
struct V_16 * V_17 = V_18 ;
struct V_95 * V_96 = F_155 ( V_61 ) ;
if ( F_156 ( V_61 ) )
F_23 ( V_17 , L_248 ) ;
else
F_10 ( V_17 , L_249 , V_61 -> V_406 ) ;
V_96 -> V_407 ( V_96 , V_17 ) ;
return 0 ;
}
static void F_157 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
struct V_95 * V_96 = V_68 -> V_109 . V_408 ;
int V_206 , V_141 ;
if ( ! V_96 )
return;
F_10 ( V_17 , L_250 , V_96 -> V_409 ) ;
F_10 ( V_17 , L_251 , V_96 -> V_410 ) ;
F_62 (ring, dev_priv, unused) {
F_10 ( V_17 , L_252 , V_58 -> V_47 ) ;
for ( V_141 = 0 ; V_141 < 4 ; V_141 ++ ) {
T_4 V_411 = 0x270 + V_141 * 8 ;
T_8 V_412 = F_69 ( V_58 -> V_413 + V_411 + 4 ) ;
V_412 <<= 32 ;
V_412 |= F_69 ( V_58 -> V_413 + V_411 ) ;
F_10 ( V_17 , L_253 , V_141 , V_412 ) ;
}
}
}
static void F_158 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
struct V_107 * V_108 ;
int V_141 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_254 , F_69 ( V_414 ) ) ;
F_62 (ring, dev_priv, i) {
F_10 ( V_17 , L_252 , V_58 -> V_47 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_254 , F_69 ( F_159 ( V_58 ) ) ) ;
F_10 ( V_17 , L_255 , F_69 ( F_160 ( V_58 ) ) ) ;
F_10 ( V_17 , L_256 , F_69 ( F_161 ( V_58 ) ) ) ;
F_10 ( V_17 , L_257 , F_69 ( F_162 ( V_58 ) ) ) ;
}
if ( V_68 -> V_109 . V_408 ) {
struct V_95 * V_96 = V_68 -> V_109 . V_408 ;
F_23 ( V_17 , L_258 ) ;
F_10 ( V_17 , L_259 , V_96 -> V_415 ) ;
V_96 -> V_407 ( V_96 , V_17 ) ;
} else
return;
F_45 (file, &dev->filelist, lhead) {
struct V_416 * V_98 = V_108 -> V_117 ;
F_10 ( V_17 , L_260 ,
F_163 ( V_108 -> V_120 , V_121 ) -> V_122 ) ;
F_47 ( & V_98 -> V_417 , F_154 , V_17 ) ;
}
F_10 ( V_17 , L_261 , F_69 ( V_418 ) ) ;
}
static int F_164 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_157 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_158 ( V_17 , V_21 ) ;
F_66 ( V_68 ) ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_165 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
F_10 ( V_17 , L_262 , F_1 ( F_166 ( V_21 ) ) ) ;
F_10 ( V_17 , L_263 , V_68 -> V_419 ) ;
return 0 ;
}
static int F_167 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_420 = 0 ;
bool V_421 = false ;
F_65 ( V_68 ) ;
F_5 ( & V_68 -> V_422 . V_306 ) ;
F_10 ( V_17 , L_264 , F_1 ( V_68 -> V_422 . V_423 ) ) ;
F_10 ( V_17 , L_265 , F_1 ( V_68 -> V_422 . V_424 ) ) ;
F_10 ( V_17 , L_266 , F_1 ( ( bool ) V_68 -> V_422 . V_421 ) ) ;
F_10 ( V_17 , L_267 , F_1 ( V_68 -> V_422 . V_99 ) ) ;
F_10 ( V_17 , L_268 ,
V_68 -> V_422 . V_425 ) ;
F_10 ( V_17 , L_269 ,
F_1 ( F_168 ( & V_68 -> V_422 . V_130 . V_130 ) ) ) ;
V_421 = F_169 ( V_21 ) &&
F_69 ( F_170 ( V_21 ) ) & V_426 ;
F_10 ( V_17 , L_270 , F_1 ( V_421 ) ) ;
if ( F_169 ( V_21 ) )
V_420 = F_69 ( F_171 ( V_21 ) ) &
V_427 ;
F_10 ( V_17 , L_271 , V_420 ) ;
F_7 ( & V_68 -> V_422 . V_306 ) ;
F_66 ( V_68 ) ;
return 0 ;
}
static int F_172 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_428 * V_429 ;
struct V_430 * V_431 ;
struct V_432 * V_432 = NULL ;
int V_75 ;
T_10 V_433 [ 6 ] ;
F_173 ( V_21 ) ;
F_21 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_431 -> V_36 . V_434 != V_435 )
continue;
if ( ! V_431 -> V_36 . V_429 )
continue;
V_429 = F_174 ( V_431 -> V_36 . V_429 ) ;
if ( V_429 -> type != V_436 )
continue;
V_432 = F_175 ( & V_429 -> V_36 ) ;
V_75 = F_176 ( V_432 , V_433 ) ;
if ( V_75 )
goto V_201;
F_10 ( V_17 , L_272 ,
V_433 [ 0 ] , V_433 [ 1 ] , V_433 [ 2 ] ,
V_433 [ 3 ] , V_433 [ 4 ] , V_433 [ 5 ] ) ;
goto V_201;
}
V_75 = - V_357 ;
V_201:
F_177 ( V_21 ) ;
return V_75 ;
}
static int F_178 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_8 V_437 ;
T_4 V_438 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_357 ;
F_65 ( V_68 ) ;
F_179 ( V_439 , V_437 ) ;
V_437 = ( V_437 & 0x1f00 ) >> 8 ;
V_438 = 1000000 / ( 1 << V_437 ) ;
V_437 = F_69 ( V_440 ) ;
V_437 *= V_438 ;
F_66 ( V_68 ) ;
F_10 ( V_17 , L_273 , ( long long unsigned ) V_437 ) ;
return 0 ;
}
static int F_180 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
if ( ! F_108 ( V_21 ) && ! F_106 ( V_21 ) ) {
F_23 ( V_17 , L_203 ) ;
return 0 ;
}
F_10 ( V_17 , L_274 , F_1 ( ! V_68 -> V_109 . V_441 ) ) ;
F_10 ( V_17 , L_275 ,
F_1 ( ! F_181 ( V_68 ) ) ) ;
return 0 ;
}
static const char * F_182 ( enum V_442 V_443 )
{
switch ( V_443 ) {
case V_444 :
return L_276 ;
case V_445 :
return L_277 ;
case V_446 :
return L_278 ;
case V_447 :
return L_279 ;
case V_448 :
return L_280 ;
case V_449 :
return L_281 ;
case V_450 :
return L_282 ;
case V_451 :
return L_283 ;
case V_452 :
return L_284 ;
case V_453 :
return L_285 ;
case V_454 :
return L_286 ;
case V_455 :
return L_287 ;
case V_456 :
return L_288 ;
case V_457 :
return L_289 ;
case V_458 :
return L_290 ;
case V_459 :
return L_291 ;
case V_460 :
return L_292 ;
case V_461 :
return L_293 ;
case V_462 :
return L_294 ;
case V_463 :
return L_295 ;
case V_464 :
return L_296 ;
case V_465 :
return L_297 ;
case V_466 :
return L_298 ;
case V_467 :
return L_299 ;
case V_468 :
return L_300 ;
default:
F_183 ( 1 ) ;
return L_301 ;
}
}
static int F_184 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_469 * V_470 = & V_68 -> V_470 ;
int V_141 ;
F_5 ( & V_470 -> V_306 ) ;
F_10 ( V_17 , L_302 , L_303 , L_304 ) ;
for ( V_141 = 0 ; V_141 < V_470 -> V_471 ; V_141 ++ ) {
struct V_472 * V_473 ;
enum V_442 V_474 ;
V_473 = & V_470 -> V_475 [ V_141 ] ;
F_10 ( V_17 , L_305 , V_473 -> V_47 ,
V_473 -> V_74 ) ;
for ( V_474 = 0 ; V_474 < V_476 ;
V_474 ++ ) {
if ( ! ( F_185 ( V_474 ) & V_473 -> V_477 ) )
continue;
F_10 ( V_17 , L_306 ,
F_182 ( V_474 ) ,
V_470 -> V_478 [ V_474 ] ) ;
}
}
F_7 ( & V_470 -> V_306 ) ;
return 0 ;
}
static void F_186 ( struct V_16 * V_17 , int V_479 ,
struct V_480 * V_481 )
{
int V_141 ;
for ( V_141 = 0 ; V_141 < V_479 ; V_141 ++ )
F_25 ( V_17 , '\t' ) ;
F_10 ( V_17 , L_307 ,
V_481 -> V_36 . V_88 , V_481 -> V_47 ,
V_481 -> V_482 , V_481 -> clock ,
V_481 -> V_483 , V_481 -> V_484 ,
V_481 -> V_485 , V_481 -> V_486 ,
V_481 -> V_487 , V_481 -> V_488 ,
V_481 -> V_489 , V_481 -> V_490 ,
V_481 -> type , V_481 -> V_124 ) ;
}
static void F_187 ( struct V_16 * V_17 ,
struct V_125 * V_125 ,
struct V_428 * V_428 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_491 * V_126 = & V_125 -> V_36 ;
struct V_430 * V_430 ;
struct V_492 * V_429 ;
V_429 = & V_428 -> V_36 ;
F_10 ( V_17 , L_308 ,
V_429 -> V_36 . V_88 , V_429 -> V_47 ) ;
F_188 (dev, encoder, intel_connector) {
struct V_493 * V_431 = & V_430 -> V_36 ;
F_10 ( V_17 , L_309 ,
V_431 -> V_36 . V_88 ,
V_431 -> V_47 ,
F_189 ( V_431 -> V_494 ) ) ;
if ( V_431 -> V_494 == V_495 ) {
struct V_480 * V_481 = & V_126 -> V_481 ;
F_10 ( V_17 , L_310 ) ;
F_186 ( V_17 , 2 , V_481 ) ;
} else {
F_25 ( V_17 , '\n' ) ;
}
}
}
static void F_190 ( struct V_16 * V_17 , struct V_125 * V_125 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_491 * V_126 = & V_125 -> V_36 ;
struct V_428 * V_428 ;
if ( V_126 -> V_496 -> V_370 )
F_10 ( V_17 , L_311 ,
V_126 -> V_496 -> V_370 -> V_36 . V_88 , V_126 -> T_1 , V_126 -> V_497 ,
V_126 -> V_496 -> V_370 -> V_373 , V_126 -> V_496 -> V_370 -> V_374 ) ;
else
F_23 ( V_17 , L_312 ) ;
F_191 (dev, crtc, intel_encoder)
F_187 ( V_17 , V_125 , V_428 ) ;
}
static void F_192 ( struct V_16 * V_17 , struct V_498 * V_499 )
{
struct V_480 * V_481 = V_499 -> V_500 ;
F_10 ( V_17 , L_313 ) ;
F_186 ( V_17 , 2 , V_481 ) ;
}
static void F_193 ( struct V_16 * V_17 ,
struct V_430 * V_430 )
{
struct V_428 * V_428 = V_430 -> V_429 ;
struct V_432 * V_432 = F_175 ( & V_428 -> V_36 ) ;
F_10 ( V_17 , L_314 , V_432 -> V_501 [ V_502 ] ) ;
F_10 ( V_17 , L_315 , V_432 -> V_503 ? L_1 :
L_2 ) ;
if ( V_428 -> type == V_436 )
F_192 ( V_17 , & V_430 -> V_499 ) ;
}
static void F_194 ( struct V_16 * V_17 ,
struct V_430 * V_430 )
{
struct V_428 * V_428 = V_430 -> V_429 ;
struct V_504 * V_504 = F_195 ( & V_428 -> V_36 ) ;
F_10 ( V_17 , L_315 , V_504 -> V_503 ? L_1 :
L_2 ) ;
}
static void F_196 ( struct V_16 * V_17 ,
struct V_430 * V_430 )
{
F_192 ( V_17 , & V_430 -> V_499 ) ;
}
static void F_197 ( struct V_16 * V_17 ,
struct V_493 * V_431 )
{
struct V_430 * V_430 = F_198 ( V_431 ) ;
struct V_428 * V_428 = V_430 -> V_429 ;
struct V_480 * V_481 ;
F_10 ( V_17 , L_316 ,
V_431 -> V_36 . V_88 , V_431 -> V_47 ,
F_189 ( V_431 -> V_494 ) ) ;
if ( V_431 -> V_494 == V_495 ) {
F_10 ( V_17 , L_317 , V_431 -> V_505 . V_47 ) ;
F_10 ( V_17 , L_318 ,
V_431 -> V_505 . V_506 ,
V_431 -> V_505 . V_507 ) ;
F_10 ( V_17 , L_319 ,
F_199 ( V_431 -> V_505 . V_508 ) ) ;
F_10 ( V_17 , L_320 ,
V_431 -> V_505 . V_509 ) ;
}
if ( V_428 ) {
if ( V_428 -> type == V_510 ||
V_428 -> type == V_436 )
F_193 ( V_17 , V_430 ) ;
else if ( V_428 -> type == V_511 )
F_194 ( V_17 , V_430 ) ;
else if ( V_428 -> type == V_512 )
F_196 ( V_17 , V_430 ) ;
}
F_10 ( V_17 , L_321 ) ;
F_21 (mode, &connector->modes, head)
F_186 ( V_17 , 2 , V_481 ) ;
}
static bool F_200 ( struct V_20 * V_21 , int V_127 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_513 ;
if ( F_201 ( V_21 ) || F_202 ( V_21 ) )
V_513 = F_69 ( V_514 ) & V_515 ;
else
V_513 = F_69 ( F_203 ( V_127 ) ) & V_516 ;
return V_513 ;
}
static bool F_204 ( struct V_20 * V_21 , int V_127 , int * T_1 , int * V_497 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_196 ;
V_196 = F_69 ( F_205 ( V_127 ) ) ;
* T_1 = ( V_196 >> V_517 ) & V_518 ;
if ( V_196 & ( V_519 << V_517 ) )
* T_1 = - * T_1 ;
* V_497 = ( V_196 >> V_520 ) & V_518 ;
if ( V_196 & ( V_519 << V_520 ) )
* V_497 = - * V_497 ;
return F_200 ( V_21 , V_127 ) ;
}
static int F_206 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_125 * V_126 ;
struct V_493 * V_431 ;
F_65 ( V_68 ) ;
F_173 ( V_21 ) ;
F_10 ( V_17 , L_322 ) ;
F_10 ( V_17 , L_323 ) ;
F_54 (dev, crtc) {
bool V_99 ;
int T_1 , V_497 ;
F_10 ( V_17 , L_324 ,
V_126 -> V_36 . V_36 . V_88 , F_55 ( V_126 -> V_127 ) ,
F_1 ( V_126 -> V_99 ) , V_126 -> V_521 . V_522 , V_126 -> V_521 . V_523 ) ;
if ( V_126 -> V_99 ) {
F_190 ( V_17 , V_126 ) ;
V_99 = F_204 ( V_21 , V_126 -> V_127 , & T_1 , & V_497 ) ;
F_10 ( V_17 , L_325 ,
F_1 ( V_126 -> V_524 ) ,
T_1 , V_497 , V_126 -> V_525 , V_126 -> V_526 ,
V_126 -> V_527 , F_1 ( V_99 ) ) ;
}
F_10 ( V_17 , L_326 ,
F_1 ( ! V_126 -> V_528 ) ,
F_1 ( ! V_126 -> V_529 ) ) ;
}
F_10 ( V_17 , L_29 ) ;
F_10 ( V_17 , L_327 ) ;
F_10 ( V_17 , L_328 ) ;
F_21 (connector, &dev->mode_config.connector_list, head) {
F_197 ( V_17 , V_431 ) ;
}
F_177 ( V_21 ) ;
F_66 ( V_68 ) ;
return 0 ;
}
static int F_207 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_138 * V_58 ;
int V_530 = F_208 ( F_9 ( V_21 ) -> V_531 ) ;
int V_141 , V_532 , V_75 ;
if ( ! F_209 ( V_21 ) ) {
F_23 ( V_17 , L_329 ) ;
return 0 ;
}
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
if ( F_106 ( V_21 ) ) {
struct V_533 * V_533 ;
T_11 * V_143 ;
V_533 = F_210 ( V_68 -> V_534 , 0 ) ;
V_143 = ( T_11 * ) F_211 ( V_533 ) ;
F_62 (ring, dev_priv, i) {
T_11 V_411 ;
F_10 ( V_17 , L_252 , V_58 -> V_47 ) ;
F_23 ( V_17 , L_330 ) ;
for ( V_532 = 0 ; V_532 < V_530 ; V_532 ++ ) {
V_411 = V_141 * V_535 + V_532 ;
F_10 ( V_17 , L_331 ,
V_143 [ V_411 ] , V_411 * 8 ) ;
}
F_25 ( V_17 , '\n' ) ;
F_23 ( V_17 , L_332 ) ;
for ( V_532 = 0 ; V_532 < V_530 ; V_532 ++ ) {
V_411 = V_141 + ( V_532 * V_535 ) ;
F_10 ( V_17 , L_331 ,
V_143 [ V_411 ] , V_411 * 8 ) ;
}
F_25 ( V_17 , '\n' ) ;
}
F_212 ( V_143 ) ;
} else {
F_23 ( V_17 , L_330 ) ;
F_62 (ring, dev_priv, i)
for ( V_532 = 0 ; V_532 < V_530 ; V_532 ++ )
F_10 ( V_17 , L_333 ,
F_69 ( V_58 -> V_536 . V_537 . signal [ V_532 ] ) ) ;
F_25 ( V_17 , '\n' ) ;
}
F_23 ( V_17 , L_334 ) ;
F_62 (ring, dev_priv, i) {
for ( V_532 = 0 ; V_532 < V_530 ; V_532 ++ ) {
F_10 ( V_17 , L_335 , V_58 -> V_536 . V_538 [ V_532 ] ) ;
}
F_25 ( V_17 , '\n' ) ;
}
F_25 ( V_17 , '\n' ) ;
F_66 ( V_68 ) ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int F_213 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_141 ;
F_173 ( V_21 ) ;
for ( V_141 = 0 ; V_141 < V_68 -> V_539 ; V_141 ++ ) {
struct V_540 * V_541 = & V_68 -> V_542 [ V_141 ] ;
F_10 ( V_17 , L_336 , V_141 , V_541 -> V_47 , V_541 -> V_88 ) ;
F_10 ( V_17 , L_337 , V_541 -> V_377 ,
V_541 -> V_99 , F_1 ( V_541 -> V_543 ) ) ;
F_10 ( V_17 , L_338 ) ;
F_10 ( V_17 , L_339 , V_541 -> V_544 . V_545 ) ;
F_10 ( V_17 , L_340 , V_541 -> V_544 . V_546 ) ;
F_10 ( V_17 , L_341 , V_541 -> V_544 . V_547 ) ;
F_10 ( V_17 , L_342 , V_541 -> V_544 . V_548 ) ;
F_10 ( V_17 , L_343 , V_541 -> V_544 . V_549 ) ;
}
F_177 ( V_21 ) ;
return 0 ;
}
static int F_214 ( struct V_16 * V_17 , void * V_206 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_492 * V_429 ;
struct V_428 * V_428 ;
struct V_550 * V_551 ;
F_173 ( V_21 ) ;
F_21 (encoder, &dev->mode_config.encoder_list, head) {
V_428 = F_174 ( V_429 ) ;
if ( V_428 -> type != V_510 )
continue;
V_551 = F_215 ( V_429 ) ;
if ( ! V_551 -> V_552 . V_553 )
continue;
F_216 ( V_17 , & V_551 -> V_552 . V_554 ) ;
}
F_177 ( V_21 ) ;
return 0 ;
}
static int F_217 ( struct V_193 * V_193 , struct V_108 * V_555 )
{
struct V_556 * V_23 = V_193 -> V_194 ;
struct V_67 * V_68 = V_23 -> V_21 -> V_69 ;
struct V_557 * V_558 = & V_68 -> V_558 [ V_23 -> V_127 ] ;
if ( V_23 -> V_127 >= F_9 ( V_23 -> V_21 ) -> V_559 )
return - V_357 ;
F_115 ( & V_558 -> V_306 ) ;
if ( V_558 -> V_560 ) {
F_116 ( & V_558 -> V_306 ) ;
return - V_561 ;
}
V_558 -> V_560 = true ;
V_555 -> V_192 = V_193 -> V_194 ;
F_116 ( & V_558 -> V_306 ) ;
return 0 ;
}
static int F_218 ( struct V_193 * V_193 , struct V_108 * V_555 )
{
struct V_556 * V_23 = V_193 -> V_194 ;
struct V_67 * V_68 = V_23 -> V_21 -> V_69 ;
struct V_557 * V_558 = & V_68 -> V_558 [ V_23 -> V_127 ] ;
F_115 ( & V_558 -> V_306 ) ;
V_558 -> V_560 = false ;
F_116 ( & V_558 -> V_306 ) ;
return 0 ;
}
static int F_219 ( struct V_557 * V_558 )
{
F_220 ( & V_558 -> V_306 ) ;
return F_221 ( V_558 -> V_66 , V_558 -> V_562 ,
V_563 ) ;
}
static T_5
F_222 ( struct V_108 * V_555 , char T_6 * V_564 , T_3 V_74 ,
T_7 * V_196 )
{
struct V_556 * V_23 = V_555 -> V_192 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_557 * V_558 = & V_68 -> V_558 [ V_23 -> V_127 ] ;
char V_202 [ V_565 ] ;
int V_66 , V_562 , V_566 , V_567 ;
T_5 V_568 ;
if ( V_74 < V_569 )
return - V_81 ;
if ( V_558 -> V_570 == V_571 )
return 0 ;
F_115 ( & V_558 -> V_306 ) ;
while ( F_219 ( V_558 ) == 0 ) {
int V_75 ;
if ( V_555 -> V_572 & V_573 ) {
F_116 ( & V_558 -> V_306 ) ;
return - V_574 ;
}
V_75 = F_223 ( V_558 -> V_575 ,
F_219 ( V_558 ) , V_558 -> V_306 ) ;
if ( V_75 ) {
F_116 ( & V_558 -> V_306 ) ;
return V_75 ;
}
}
V_66 = V_558 -> V_66 ;
V_562 = V_558 -> V_562 ;
V_566 = F_224 ( ( T_3 ) F_221 ( V_66 , V_562 , V_563 ) ,
V_74 / V_569 ) ;
F_116 ( & V_558 -> V_306 ) ;
V_568 = 0 ;
V_567 = 0 ;
do {
struct V_576 * V_577 = & V_558 -> V_578 [ V_562 ] ;
int V_75 ;
V_568 += snprintf ( V_202 , V_565 ,
L_344 ,
V_577 -> V_579 , V_577 -> V_433 [ 0 ] ,
V_577 -> V_433 [ 1 ] , V_577 -> V_433 [ 2 ] ,
V_577 -> V_433 [ 3 ] , V_577 -> V_433 [ 4 ] ) ;
V_75 = F_225 ( V_564 + V_567 * V_569 ,
V_202 , V_569 ) ;
if ( V_75 == V_569 )
return - V_580 ;
F_226 ( V_563 ) ;
V_562 = ( V_562 + 1 ) & ( V_563 - 1 ) ;
V_567 ++ ;
} while ( -- V_566 );
F_115 ( & V_558 -> V_306 ) ;
V_558 -> V_562 = V_562 ;
F_116 ( & V_558 -> V_306 ) ;
return V_568 ;
}
static int F_227 ( struct V_4 * V_581 , struct V_2 * V_3 ,
enum V_127 V_127 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_556 * V_23 = & V_582 [ V_127 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_228 ( V_23 -> V_47 , V_583 , V_581 , V_23 ,
& V_584 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_229 ( enum V_585 V_570 )
{
F_230 ( F_231 ( V_586 ) != V_587 ) ;
return V_586 [ V_570 ] ;
}
static int F_232 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_141 ;
for ( V_141 = 0 ; V_141 < V_588 ; V_141 ++ )
F_10 ( V_17 , L_345 , F_55 ( V_141 ) ,
F_229 ( V_68 -> V_558 [ V_141 ] . V_570 ) ) ;
return 0 ;
}
static int F_233 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_20 * V_21 = V_193 -> V_194 ;
return F_234 ( V_108 , F_232 , V_21 ) ;
}
static int F_235 ( enum V_585 * V_570 ,
T_12 * V_204 )
{
if ( * V_570 == V_589 )
* V_570 = V_590 ;
switch ( * V_570 ) {
case V_590 :
* V_204 = V_591 | V_592 ;
break;
case V_571 :
* V_204 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_236 ( struct V_20 * V_21 , enum V_127 V_127 ,
enum V_585 * V_570 )
{
struct V_428 * V_429 ;
struct V_125 * V_126 ;
struct V_550 * V_593 ;
int V_75 = 0 ;
* V_570 = V_590 ;
F_173 ( V_21 ) ;
F_21 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_429 -> V_36 . V_126 )
continue;
V_126 = F_237 ( V_429 -> V_36 . V_126 ) ;
if ( V_126 -> V_127 != V_127 )
continue;
switch ( V_429 -> type ) {
case V_594 :
* V_570 = V_595 ;
break;
case V_510 :
case V_436 :
V_593 = F_215 ( & V_429 -> V_36 ) ;
switch ( V_593 -> V_596 ) {
case V_597 :
* V_570 = V_598 ;
break;
case V_599 :
* V_570 = V_600 ;
break;
case V_601 :
* V_570 = V_602 ;
break;
default:
F_238 ( 1 , L_346 ,
F_239 ( V_593 -> V_596 ) ) ;
break;
}
break;
}
}
F_177 ( V_21 ) ;
return V_75 ;
}
static int F_240 ( struct V_20 * V_21 ,
enum V_127 V_127 ,
enum V_585 * V_570 ,
T_12 * V_204 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
bool V_603 = false ;
if ( * V_570 == V_589 ) {
int V_75 = F_236 ( V_21 , V_127 , V_570 ) ;
if ( V_75 )
return V_75 ;
}
switch ( * V_570 ) {
case V_590 :
* V_204 = V_591 | V_604 ;
break;
case V_598 :
* V_204 = V_591 | V_605 ;
V_603 = true ;
break;
case V_600 :
* V_204 = V_591 | V_606 ;
V_603 = true ;
break;
case V_571 :
* V_204 = 0 ;
break;
default:
return - V_81 ;
}
if ( V_603 ) {
T_12 V_607 = F_69 ( V_608 ) ;
V_607 |= V_609 ;
if ( V_127 == V_610 )
V_607 |= V_611 ;
else
V_607 |= V_612 ;
F_241 ( V_608 , V_607 ) ;
}
return 0 ;
}
static int F_242 ( struct V_20 * V_21 ,
enum V_127 V_127 ,
enum V_585 * V_570 ,
T_12 * V_204 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
bool V_603 = false ;
if ( * V_570 == V_589 ) {
int V_75 = F_236 ( V_21 , V_127 , V_570 ) ;
if ( V_75 )
return V_75 ;
}
switch ( * V_570 ) {
case V_590 :
* V_204 = V_591 | V_613 ;
break;
case V_595 :
if ( ! F_243 ( V_21 ) )
return - V_81 ;
* V_204 = V_591 | V_614 ;
break;
case V_598 :
if ( ! F_244 ( V_21 ) )
return - V_81 ;
* V_204 = V_591 | V_615 ;
V_603 = true ;
break;
case V_600 :
if ( ! F_244 ( V_21 ) )
return - V_81 ;
* V_204 = V_591 | V_616 ;
V_603 = true ;
break;
case V_602 :
if ( ! F_244 ( V_21 ) )
return - V_81 ;
* V_204 = V_591 | V_617 ;
V_603 = true ;
break;
case V_571 :
* V_204 = 0 ;
break;
default:
return - V_81 ;
}
if ( V_603 ) {
T_12 V_607 = F_69 ( V_608 ) ;
F_183 ( ! F_244 ( V_21 ) ) ;
F_241 ( V_618 ,
F_69 ( V_618 ) | V_619 ) ;
if ( V_127 == V_610 )
V_607 |= V_611 ;
else
V_607 |= V_612 ;
F_241 ( V_608 , V_607 ) ;
}
return 0 ;
}
static void F_245 ( struct V_20 * V_21 ,
enum V_127 V_127 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
T_12 V_607 = F_69 ( V_608 ) ;
if ( V_127 == V_610 )
V_607 &= ~ V_611 ;
else
V_607 &= ~ V_612 ;
if ( ! ( V_607 & V_620 ) )
V_607 &= ~ V_609 ;
F_241 ( V_608 , V_607 ) ;
}
static void F_246 ( struct V_20 * V_21 ,
enum V_127 V_127 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
T_12 V_607 = F_69 ( V_608 ) ;
if ( V_127 == V_610 )
V_607 &= ~ V_611 ;
else
V_607 &= ~ V_612 ;
F_241 ( V_608 , V_607 ) ;
if ( ! ( V_607 & V_620 ) ) {
F_241 ( V_618 ,
F_69 ( V_618 ) & ~ V_619 ) ;
}
}
static int F_247 ( enum V_585 * V_570 ,
T_12 * V_204 )
{
if ( * V_570 == V_589 )
* V_570 = V_590 ;
switch ( * V_570 ) {
case V_621 :
* V_204 = V_591 | V_622 ;
break;
case V_623 :
* V_204 = V_591 | V_624 ;
break;
case V_590 :
* V_204 = V_591 | V_625 ;
break;
case V_571 :
* V_204 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static void F_248 ( struct V_20 * V_21 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_125 * V_126 =
F_237 ( V_68 -> V_626 [ V_610 ] ) ;
F_173 ( V_21 ) ;
if ( V_126 -> V_521 . V_627 == V_628 &&
! V_126 -> V_521 . V_629 . V_421 ) {
V_126 -> V_521 . V_629 . V_630 = true ;
F_249 ( V_68 ,
F_250 ( V_610 ) ) ;
V_68 -> V_631 . V_632 ( & V_126 -> V_36 ) ;
V_68 -> V_631 . V_633 ( & V_126 -> V_36 ) ;
}
F_177 ( V_21 ) ;
}
static void F_251 ( struct V_20 * V_21 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_125 * V_126 =
F_237 ( V_68 -> V_626 [ V_610 ] ) ;
F_173 ( V_21 ) ;
if ( V_126 -> V_521 . V_629 . V_630 ) {
V_126 -> V_521 . V_629 . V_630 = false ;
V_68 -> V_631 . V_632 ( & V_126 -> V_36 ) ;
V_68 -> V_631 . V_633 ( & V_126 -> V_36 ) ;
F_252 ( V_68 ,
F_250 ( V_610 ) ) ;
}
F_177 ( V_21 ) ;
}
static int F_253 ( struct V_20 * V_21 ,
enum V_127 V_127 ,
enum V_585 * V_570 ,
T_12 * V_204 )
{
if ( * V_570 == V_589 )
* V_570 = V_634 ;
switch ( * V_570 ) {
case V_621 :
* V_204 = V_591 | V_635 ;
break;
case V_623 :
* V_204 = V_591 | V_636 ;
break;
case V_634 :
if ( F_108 ( V_21 ) && V_127 == V_610 )
F_248 ( V_21 ) ;
* V_204 = V_591 | V_637 ;
break;
case V_571 :
* V_204 = 0 ;
break;
default:
return - V_81 ;
}
return 0 ;
}
static int F_254 ( struct V_20 * V_21 , enum V_127 V_127 ,
enum V_585 V_570 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_557 * V_558 = & V_68 -> V_558 [ V_127 ] ;
T_4 V_204 = 0 ;
int V_75 ;
if ( V_558 -> V_570 == V_570 )
return 0 ;
if ( V_558 -> V_570 && V_570 )
return - V_81 ;
if ( F_255 ( V_21 ) )
V_75 = F_235 ( & V_570 , & V_204 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_75 = F_242 ( V_21 , V_127 , & V_570 , & V_204 ) ;
else if ( F_78 ( V_21 ) )
V_75 = F_240 ( V_21 , V_127 , & V_570 , & V_204 ) ;
else if ( F_102 ( V_21 ) || F_104 ( V_21 ) )
V_75 = F_247 ( & V_570 , & V_204 ) ;
else
V_75 = F_253 ( V_21 , V_127 , & V_570 , & V_204 ) ;
if ( V_75 != 0 )
return V_75 ;
if ( V_570 ) {
F_84 ( L_347 ,
F_55 ( V_127 ) , F_229 ( V_570 ) ) ;
V_558 -> V_578 = F_87 ( sizeof( * V_558 -> V_578 ) *
V_563 ,
V_9 ) ;
if ( ! V_558 -> V_578 )
return - V_10 ;
F_115 ( & V_558 -> V_306 ) ;
V_558 -> V_66 = 0 ;
V_558 -> V_562 = 0 ;
F_116 ( & V_558 -> V_306 ) ;
}
V_558 -> V_570 = V_570 ;
F_241 ( F_256 ( V_127 ) , V_204 ) ;
F_257 ( F_256 ( V_127 ) ) ;
if ( V_570 == V_571 ) {
struct V_576 * V_578 ;
struct V_125 * V_126 =
F_237 ( V_68 -> V_626 [ V_127 ] ) ;
F_84 ( L_348 ,
F_55 ( V_127 ) ) ;
F_258 ( & V_126 -> V_36 . V_638 , NULL ) ;
if ( V_126 -> V_99 )
F_259 ( V_21 , V_127 ) ;
F_260 ( & V_126 -> V_36 . V_638 ) ;
F_115 ( & V_558 -> V_306 ) ;
V_578 = V_558 -> V_578 ;
V_558 -> V_578 = NULL ;
F_116 ( & V_558 -> V_306 ) ;
F_91 ( V_578 ) ;
if ( F_244 ( V_21 ) )
F_246 ( V_21 , V_127 ) ;
else if ( F_78 ( V_21 ) )
F_245 ( V_21 , V_127 ) ;
else if ( F_108 ( V_21 ) && V_127 == V_610 )
F_251 ( V_21 ) ;
}
return 0 ;
}
static int F_261 ( char * V_202 , char * V_639 [] , int V_640 )
{
int V_641 = 0 ;
while ( * V_202 ) {
char * V_642 ;
V_202 = F_262 ( V_202 ) ;
if ( ! * V_202 )
break;
for ( V_642 = V_202 ; * V_642 && ! isspace ( * V_642 ) ; V_642 ++ )
;
if ( V_641 == V_640 ) {
F_84 ( L_349 ,
V_640 ) ;
return - V_81 ;
}
if ( * V_642 )
* V_642 ++ = '\0' ;
V_639 [ V_641 ++ ] = V_202 ;
V_202 = V_642 ;
}
return V_641 ;
}
static int
F_263 ( const char * V_202 , enum V_643 * V_644 )
{
int V_141 ;
for ( V_141 = 0 ; V_141 < F_231 ( V_645 ) ; V_141 ++ )
if ( ! strcmp ( V_202 , V_645 [ V_141 ] ) ) {
* V_644 = V_141 ;
return 0 ;
}
return - V_81 ;
}
static int F_264 ( const char * V_202 , enum V_127 * V_127 )
{
const char V_47 = V_202 [ 0 ] ;
if ( V_47 < 'A' || V_47 >= F_55 ( V_588 ) )
return - V_81 ;
* V_127 = V_47 - 'A' ;
return 0 ;
}
static int
F_265 ( const char * V_202 , enum V_585 * V_56 )
{
int V_141 ;
for ( V_141 = 0 ; V_141 < F_231 ( V_586 ) ; V_141 ++ )
if ( ! strcmp ( V_202 , V_586 [ V_141 ] ) ) {
* V_56 = V_141 ;
return 0 ;
}
return - V_81 ;
}
static int F_266 ( struct V_20 * V_21 , char * V_202 , T_3 V_646 )
{
#define F_267 3
int V_641 ;
char * V_639 [ F_267 ] ;
enum V_127 V_127 ;
enum V_643 V_647 ;
enum V_585 V_570 ;
V_641 = F_261 ( V_202 , V_639 , F_267 ) ;
if ( V_641 != F_267 ) {
F_84 ( L_350 ,
F_267 ) ;
return - V_81 ;
}
if ( F_263 ( V_639 [ 0 ] , & V_647 ) < 0 ) {
F_84 ( L_351 , V_639 [ 0 ] ) ;
return - V_81 ;
}
if ( F_264 ( V_639 [ 1 ] , & V_127 ) < 0 ) {
F_84 ( L_352 , V_639 [ 1 ] ) ;
return - V_81 ;
}
if ( F_265 ( V_639 [ 2 ] , & V_570 ) < 0 ) {
F_84 ( L_353 , V_639 [ 2 ] ) ;
return - V_81 ;
}
return F_254 ( V_21 , V_127 , V_570 ) ;
}
static T_5 F_268 ( struct V_108 * V_108 , const char T_6 * V_187 ,
T_3 V_646 , T_7 * V_648 )
{
struct V_16 * V_17 = V_108 -> V_192 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_649 ;
int V_75 ;
if ( V_646 == 0 )
return 0 ;
if ( V_646 > V_650 - 1 ) {
F_84 ( L_354 ,
V_650 ) ;
return - V_651 ;
}
V_649 = F_3 ( V_646 + 1 , V_9 ) ;
if ( ! V_649 )
return - V_10 ;
if ( F_269 ( V_649 , V_187 , V_646 ) ) {
V_75 = - V_580 ;
goto V_201;
}
V_649 [ V_646 ] = '\0' ;
V_75 = F_266 ( V_21 , V_649 , V_646 ) ;
V_201:
F_91 ( V_649 ) ;
if ( V_75 < 0 )
return V_75 ;
* V_648 += V_646 ;
return V_646 ;
}
static void F_270 ( struct V_16 * V_17 , const T_13 V_652 [ 5 ] )
{
struct V_20 * V_21 = V_17 -> V_19 ;
int V_653 = F_271 ( V_21 ) + 1 ;
int V_654 ;
F_173 ( V_21 ) ;
for ( V_654 = 0 ; V_654 < V_653 ; V_654 ++ ) {
unsigned int V_655 = V_652 [ V_654 ] ;
if ( V_654 > 0 )
V_655 *= 5 ;
F_10 ( V_17 , L_355 ,
V_654 , V_652 [ V_654 ] ,
V_655 / 10 , V_655 % 10 ) ;
}
F_177 ( V_21 ) ;
}
static int F_272 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_270 ( V_17 , F_273 ( V_21 ) -> V_652 . V_656 ) ;
return 0 ;
}
static int F_274 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_270 ( V_17 , F_273 ( V_21 ) -> V_652 . V_657 ) ;
return 0 ;
}
static int F_275 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_270 ( V_17 , F_273 ( V_21 ) -> V_652 . V_658 ) ;
return 0 ;
}
static int F_276 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_20 * V_21 = V_193 -> V_194 ;
if ( F_277 ( V_21 ) )
return - V_357 ;
return F_234 ( V_108 , F_272 , V_21 ) ;
}
static int F_278 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_20 * V_21 = V_193 -> V_194 ;
if ( F_277 ( V_21 ) )
return - V_357 ;
return F_234 ( V_108 , F_274 , V_21 ) ;
}
static int F_279 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_20 * V_21 = V_193 -> V_194 ;
if ( F_277 ( V_21 ) )
return - V_357 ;
return F_234 ( V_108 , F_275 , V_21 ) ;
}
static T_5 F_280 ( struct V_108 * V_108 , const char T_6 * V_187 ,
T_3 V_646 , T_7 * V_648 , T_13 V_652 [ 5 ] )
{
struct V_16 * V_17 = V_108 -> V_192 ;
struct V_20 * V_21 = V_17 -> V_19 ;
T_13 V_659 [ 5 ] = { 0 } ;
int V_653 = F_271 ( V_21 ) + 1 ;
int V_654 ;
int V_75 ;
char V_607 [ 32 ] ;
if ( V_646 >= sizeof( V_607 ) )
return - V_81 ;
if ( F_269 ( V_607 , V_187 , V_646 ) )
return - V_580 ;
V_607 [ V_646 ] = '\0' ;
V_75 = sscanf ( V_607 , L_356 , & V_659 [ 0 ] , & V_659 [ 1 ] , & V_659 [ 2 ] , & V_659 [ 3 ] , & V_659 [ 4 ] ) ;
if ( V_75 != V_653 )
return - V_81 ;
F_173 ( V_21 ) ;
for ( V_654 = 0 ; V_654 < V_653 ; V_654 ++ )
V_652 [ V_654 ] = V_659 [ V_654 ] ;
F_177 ( V_21 ) ;
return V_646 ;
}
static T_5 F_281 ( struct V_108 * V_108 , const char T_6 * V_187 ,
T_3 V_646 , T_7 * V_648 )
{
struct V_16 * V_17 = V_108 -> V_192 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_280 ( V_108 , V_187 , V_646 , V_648 , F_273 ( V_21 ) -> V_652 . V_656 ) ;
}
static T_5 F_282 ( struct V_108 * V_108 , const char T_6 * V_187 ,
T_3 V_646 , T_7 * V_648 )
{
struct V_16 * V_17 = V_108 -> V_192 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_280 ( V_108 , V_187 , V_646 , V_648 , F_273 ( V_21 ) -> V_652 . V_657 ) ;
}
static T_5 F_283 ( struct V_108 * V_108 , const char T_6 * V_187 ,
T_3 V_646 , T_7 * V_648 )
{
struct V_16 * V_17 = V_108 -> V_192 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_280 ( V_108 , V_187 , V_646 , V_648 , F_273 ( V_21 ) -> V_652 . V_658 ) ;
}
static int
F_284 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
* V_204 = F_58 ( & V_68 -> V_660 . V_661 ) ;
return 0 ;
}
static int
F_285 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
F_65 ( V_68 ) ;
F_286 ( V_21 , V_204 ,
L_357 , V_204 ) ;
F_66 ( V_68 ) ;
return 0 ;
}
static int
F_287 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
* V_204 = V_68 -> V_660 . V_662 ;
return 0 ;
}
static int
F_288 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 ;
F_84 ( L_358 , V_204 ) ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_68 -> V_660 . V_662 = V_204 ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int
F_289 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
* V_204 = V_68 -> V_660 . V_663 ;
return 0 ;
}
static int
F_290 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_68 -> V_660 . V_663 = V_204 ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int
F_291 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
* V_204 = V_68 -> V_660 . V_664 ;
return 0 ;
}
static int
F_292 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 ;
F_84 ( L_359 , V_204 ) ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
V_68 -> V_660 . V_664 = V_204 ;
F_7 ( & V_21 -> V_76 ) ;
return 0 ;
}
static int
F_293 ( void * V_18 , T_8 * V_204 )
{
* V_204 = V_665 ;
return 0 ;
}
static int
F_294 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
struct V_25 * V_26 , * V_666 ;
struct V_70 * V_51 ;
struct V_33 * V_34 , * T_1 ;
int V_75 ;
F_295 ( L_360 , V_204 ) ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
if ( V_204 & V_667 ) {
V_75 = F_296 ( V_21 ) ;
if ( V_75 )
goto V_668;
}
if ( V_204 & ( V_669 | V_667 ) )
F_297 ( V_21 ) ;
if ( V_204 & V_670 ) {
F_21 (vm, &dev_priv->vm_list, global_link) {
F_298 (vma, x, &vm->inactive_list,
mm_list) {
if ( V_34 -> V_35 )
continue;
V_75 = F_299 ( V_34 ) ;
if ( V_75 )
goto V_668;
}
}
}
if ( V_204 & V_671 ) {
F_298 (obj, next, &dev_priv->mm.unbound_list,
global_list)
if ( V_26 -> V_672 == 0 ) {
V_75 = F_300 ( V_26 ) ;
if ( V_75 )
goto V_668;
}
}
V_668:
F_7 ( & V_21 -> V_76 ) ;
return V_75 ;
}
static int
F_301 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_357 ;
F_101 ( & V_68 -> V_207 . V_208 ) ;
V_75 = F_27 ( & V_68 -> V_207 . V_260 ) ;
if ( V_75 )
return V_75 ;
if ( F_78 ( V_21 ) )
* V_204 = F_111 ( V_68 , V_68 -> V_207 . V_361 ) ;
else
* V_204 = V_68 -> V_207 . V_361 * V_239 ;
F_7 ( & V_68 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_302 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_221 , V_673 , V_674 ;
int V_75 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_357 ;
F_101 ( & V_68 -> V_207 . V_208 ) ;
F_84 ( L_361 , V_204 ) ;
V_75 = F_27 ( & V_68 -> V_207 . V_260 ) ;
if ( V_75 )
return V_75 ;
if ( F_78 ( V_21 ) ) {
V_204 = F_303 ( V_68 , V_204 ) ;
V_673 = V_68 -> V_207 . V_235 ;
V_674 = V_68 -> V_207 . V_263 ;
} else {
F_304 ( V_204 , V_239 ) ;
V_221 = F_69 ( V_222 ) ;
V_673 = V_68 -> V_207 . V_235 ;
V_674 = ( V_221 >> 16 ) & 0xff ;
}
if ( V_204 < V_674 || V_204 > V_673 || V_204 < V_68 -> V_207 . V_360 ) {
F_7 ( & V_68 -> V_207 . V_260 ) ;
return - V_81 ;
}
V_68 -> V_207 . V_361 = V_204 ;
if ( F_78 ( V_21 ) )
F_305 ( V_21 , V_204 ) ;
else
F_306 ( V_21 , V_204 ) ;
F_7 ( & V_68 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_307 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
int V_75 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_357 ;
F_101 ( & V_68 -> V_207 . V_208 ) ;
V_75 = F_27 ( & V_68 -> V_207 . V_260 ) ;
if ( V_75 )
return V_75 ;
if ( F_78 ( V_21 ) )
* V_204 = F_111 ( V_68 , V_68 -> V_207 . V_360 ) ;
else
* V_204 = V_68 -> V_207 . V_360 * V_239 ;
F_7 ( & V_68 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_308 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_221 , V_673 , V_674 ;
int V_75 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_357 ;
F_101 ( & V_68 -> V_207 . V_208 ) ;
F_84 ( L_362 , V_204 ) ;
V_75 = F_27 ( & V_68 -> V_207 . V_260 ) ;
if ( V_75 )
return V_75 ;
if ( F_78 ( V_21 ) ) {
V_204 = F_303 ( V_68 , V_204 ) ;
V_673 = V_68 -> V_207 . V_235 ;
V_674 = V_68 -> V_207 . V_263 ;
} else {
F_304 ( V_204 , V_239 ) ;
V_221 = F_69 ( V_222 ) ;
V_673 = V_68 -> V_207 . V_235 ;
V_674 = ( V_221 >> 16 ) & 0xff ;
}
if ( V_204 < V_674 || V_204 > V_673 || V_204 > V_68 -> V_207 . V_361 ) {
F_7 ( & V_68 -> V_207 . V_260 ) ;
return - V_81 ;
}
V_68 -> V_207 . V_360 = V_204 ;
if ( F_78 ( V_21 ) )
F_305 ( V_21 , V_204 ) ;
else
F_306 ( V_21 , V_204 ) ;
F_7 ( & V_68 -> V_207 . V_260 ) ;
return 0 ;
}
static int
F_309 ( void * V_18 , T_8 * V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_675 ;
int V_75 ;
if ( ! ( F_104 ( V_21 ) || F_105 ( V_21 ) ) )
return - V_357 ;
V_75 = F_27 ( & V_21 -> V_76 ) ;
if ( V_75 )
return V_75 ;
F_65 ( V_68 ) ;
V_675 = F_69 ( V_676 ) ;
F_66 ( V_68 ) ;
F_7 ( & V_68 -> V_21 -> V_76 ) ;
* V_204 = ( V_675 & V_677 ) >> V_678 ;
return 0 ;
}
static int
F_310 ( void * V_18 , T_8 V_204 )
{
struct V_20 * V_21 = V_18 ;
struct V_67 * V_68 = V_21 -> V_69 ;
T_4 V_675 ;
if ( ! ( F_104 ( V_21 ) || F_105 ( V_21 ) ) )
return - V_357 ;
if ( V_204 > 3 )
return - V_81 ;
F_65 ( V_68 ) ;
F_84 ( L_363 , V_204 ) ;
V_675 = F_69 ( V_676 ) ;
V_675 &= ~ V_677 ;
V_675 |= ( V_204 << V_678 ) ;
F_241 ( V_676 , V_675 ) ;
F_66 ( V_68 ) ;
return 0 ;
}
static int F_311 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_20 * V_21 = V_193 -> V_194 ;
struct V_67 * V_68 = V_21 -> V_69 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_107 ( V_68 , V_236 ) ;
return 0 ;
}
static int F_312 ( struct V_193 * V_193 , struct V_108 * V_108 )
{
struct V_20 * V_21 = V_193 -> V_194 ;
struct V_67 * V_68 = V_21 -> V_69 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_109 ( V_68 , V_236 ) ;
return 0 ;
}
static int F_313 ( struct V_4 * V_581 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_228 ( L_364 ,
V_679 ,
V_581 , V_21 ,
& V_680 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_680 ) ;
}
static int F_314 ( struct V_4 * V_581 ,
struct V_2 * V_3 ,
const char * V_47 ,
const struct V_681 * V_682 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_228 ( V_47 ,
V_583 | V_683 ,
V_581 , V_21 ,
V_682 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_682 ) ;
}
void F_315 ( struct V_20 * V_21 )
{
struct V_67 * V_68 = V_21 -> V_69 ;
enum V_127 V_127 ;
F_70 (pipe) {
struct V_557 * V_558 = & V_68 -> V_558 [ V_127 ] ;
V_558 -> V_560 = false ;
F_316 ( & V_558 -> V_306 ) ;
F_317 ( & V_558 -> V_575 ) ;
}
}
int F_318 ( struct V_2 * V_3 )
{
int V_75 , V_141 ;
V_75 = F_313 ( V_3 -> V_684 , V_3 ) ;
if ( V_75 )
return V_75 ;
for ( V_141 = 0 ; V_141 < F_231 ( V_582 ) ; V_141 ++ ) {
V_75 = F_227 ( V_3 -> V_684 , V_3 , V_141 ) ;
if ( V_75 )
return V_75 ;
}
for ( V_141 = 0 ; V_141 < F_231 ( V_685 ) ; V_141 ++ ) {
V_75 = F_314 ( V_3 -> V_684 , V_3 ,
V_685 [ V_141 ] . V_47 ,
V_685 [ V_141 ] . V_682 ) ;
if ( V_75 )
return V_75 ;
}
return F_319 ( V_686 ,
V_687 ,
V_3 -> V_684 , V_3 ) ;
}
void F_320 ( struct V_2 * V_3 )
{
int V_141 ;
F_321 ( V_686 ,
V_687 , V_3 ) ;
F_321 ( (struct V_688 * ) & V_680 ,
1 , V_3 ) ;
for ( V_141 = 0 ; V_141 < F_231 ( V_582 ) ; V_141 ++ ) {
struct V_688 * V_689 =
(struct V_688 * ) & V_582 [ V_141 ] ;
F_321 ( V_689 , 1 , V_3 ) ;
}
for ( V_141 = 0 ; V_141 < F_231 ( V_685 ) ; V_141 ++ ) {
struct V_688 * V_689 =
(struct V_688 * ) V_685 [ V_141 ] . V_682 ;
F_321 ( V_689 , 1 , V_3 ) ;
}
}
