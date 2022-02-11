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
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
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
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
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
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
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
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
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
F_46 ( & V_106 -> V_116 , F_38 , & V_89 ) ;
F_47 () ;
V_114 = F_48 ( V_106 -> V_117 , V_118 ) ;
F_10 ( V_17 , L_40 ,
V_114 ? V_114 -> V_119 : L_41 ,
V_89 . V_72 ,
V_89 . V_90 ,
V_89 . V_97 ,
V_89 . V_98 ,
V_89 . V_95 ,
V_89 . V_92 ,
V_89 . V_100 ) ;
F_49 () ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_50 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
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
if ( V_14 == V_120 && ! F_16 ( V_26 ) )
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
static int F_51 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
unsigned long V_121 ;
struct V_122 * V_123 ;
F_21 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_124 = F_52 ( V_123 -> V_124 ) ;
const char V_125 = F_53 ( V_123 -> V_125 ) ;
struct V_126 * V_127 ;
F_54 ( & V_21 -> V_128 , V_121 ) ;
V_127 = V_123 -> V_129 ;
if ( V_127 == NULL ) {
F_10 ( V_17 , L_42 ,
V_124 , V_125 ) ;
} else {
if ( F_55 ( & V_127 -> V_130 ) < V_131 ) {
F_10 ( V_17 , L_43 ,
V_124 , V_125 ) ;
} else {
F_10 ( V_17 , L_44 ,
V_124 , V_125 ) ;
}
if ( V_127 -> V_132 )
F_23 ( V_17 , L_45 ) ;
else
F_23 ( V_17 , L_46 ) ;
F_10 ( V_17 , L_47 , F_55 ( & V_127 -> V_130 ) ) ;
if ( V_127 -> V_133 ) {
struct V_25 * V_26 = V_127 -> V_133 ;
if ( V_26 )
F_10 ( V_17 , L_48 ,
F_56 ( V_26 ) ) ;
}
if ( V_127 -> V_134 ) {
struct V_25 * V_26 = V_127 -> V_134 ;
if ( V_26 )
F_10 ( V_17 , L_49 ,
F_56 ( V_26 ) ) ;
}
}
F_57 ( & V_21 -> V_128 , V_121 ) ;
}
return 0 ;
}
static int F_58 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_135 * V_58 ;
struct V_136 * V_137 ;
int V_73 , V_72 , V_138 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_72 = 0 ;
F_59 (ring, dev_priv, i) {
if ( F_34 ( & V_58 -> V_139 ) )
continue;
F_10 ( V_17 , L_50 , V_58 -> V_47 ) ;
F_21 (gem_request,
&ring->request_list,
list) {
F_10 ( V_17 , L_51 ,
V_137 -> V_140 ,
( int ) ( V_141 - V_137 -> V_142 ) ) ;
}
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
if ( V_72 == 0 )
F_23 ( V_17 , L_52 ) ;
return 0 ;
}
static void F_60 ( struct V_16 * V_17 ,
struct V_135 * V_58 )
{
if ( V_58 -> V_143 ) {
F_10 ( V_17 , L_53 ,
V_58 -> V_47 , V_58 -> V_143 ( V_58 , false ) ) ;
}
}
static int F_61 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_135 * V_58 ;
int V_73 , V_138 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
F_59 (ring, dev_priv, i)
F_60 ( V_17 , V_58 ) ;
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_64 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_135 * V_58 ;
int V_73 , V_138 , V_124 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
F_10 ( V_17 , L_54 ,
F_65 ( V_144 ) ) ;
for ( V_138 = 0 ; V_138 < 4 ; V_138 ++ ) {
F_10 ( V_17 , L_55 ,
V_138 , F_65 ( F_66 ( V_138 ) ) ) ;
F_10 ( V_17 , L_56 ,
V_138 , F_65 ( F_67 ( V_138 ) ) ) ;
F_10 ( V_17 , L_57 ,
V_138 , F_65 ( F_68 ( V_138 ) ) ) ;
}
F_69 (pipe) {
F_10 ( V_17 , L_58 ,
F_52 ( V_124 ) ,
F_65 ( F_70 ( V_124 ) ) ) ;
F_10 ( V_17 , L_59 ,
F_52 ( V_124 ) ,
F_65 ( F_71 ( V_124 ) ) ) ;
F_10 ( V_17 , L_60 ,
F_52 ( V_124 ) ,
F_65 ( F_72 ( V_124 ) ) ) ;
}
F_10 ( V_17 , L_61 ,
F_65 ( V_145 ) ) ;
F_10 ( V_17 , L_62 ,
F_65 ( V_146 ) ) ;
F_10 ( V_17 , L_63 ,
F_65 ( V_147 ) ) ;
F_10 ( V_17 , L_64 ,
F_65 ( V_148 ) ) ;
F_10 ( V_17 , L_65 ,
F_65 ( V_149 ) ) ;
F_10 ( V_17 , L_66 ,
F_65 ( V_150 ) ) ;
F_10 ( V_17 , L_67 ,
F_65 ( V_151 ) ) ;
F_10 ( V_17 , L_68 ,
F_65 ( V_152 ) ) ;
F_10 ( V_17 , L_69 ,
F_65 ( V_153 ) ) ;
} else if ( F_73 ( V_21 ) ) {
F_10 ( V_17 , L_70 ,
F_65 ( V_154 ) ) ;
F_10 ( V_17 , L_71 ,
F_65 ( V_155 ) ) ;
F_10 ( V_17 , L_72 ,
F_65 ( V_156 ) ) ;
F_10 ( V_17 , L_73 ,
F_65 ( V_157 ) ) ;
F_69 (pipe)
F_10 ( V_17 , L_74 ,
F_52 ( V_124 ) ,
F_65 ( F_74 ( V_124 ) ) ) ;
F_10 ( V_17 , L_75 ,
F_65 ( V_158 ) ) ;
F_10 ( V_17 , L_76 ,
F_65 ( V_159 ) ) ;
F_10 ( V_17 , L_77 ,
F_65 ( V_160 ) ) ;
F_10 ( V_17 , L_78 ,
F_65 ( V_161 ) ) ;
F_10 ( V_17 , L_79 ,
F_65 ( V_162 ) ) ;
F_10 ( V_17 , L_80 ,
F_65 ( V_163 ) ) ;
F_10 ( V_17 , L_81 ,
F_65 ( V_164 ) ) ;
F_10 ( V_17 , L_82 ,
F_65 ( V_165 ) ) ;
F_10 ( V_17 , L_83 ,
F_65 ( V_166 ) ) ;
F_10 ( V_17 , L_84 ,
F_65 ( V_167 ) ) ;
} else if ( ! F_75 ( V_21 ) ) {
F_10 ( V_17 , L_85 ,
F_65 ( V_168 ) ) ;
F_10 ( V_17 , L_86 ,
F_65 ( V_169 ) ) ;
F_10 ( V_17 , L_87 ,
F_65 ( V_170 ) ) ;
F_69 (pipe)
F_10 ( V_17 , L_88 ,
F_52 ( V_124 ) ,
F_65 ( F_74 ( V_124 ) ) ) ;
} else {
F_10 ( V_17 , L_89 ,
F_65 ( V_171 ) ) ;
F_10 ( V_17 , L_90 ,
F_65 ( V_172 ) ) ;
F_10 ( V_17 , L_91 ,
F_65 ( V_173 ) ) ;
F_10 ( V_17 , L_92 ,
F_65 ( V_174 ) ) ;
F_10 ( V_17 , L_93 ,
F_65 ( V_175 ) ) ;
F_10 ( V_17 , L_94 ,
F_65 ( V_176 ) ) ;
F_10 ( V_17 , L_95 ,
F_65 ( V_159 ) ) ;
F_10 ( V_17 , L_96 ,
F_65 ( V_160 ) ) ;
F_10 ( V_17 , L_97 ,
F_65 ( V_161 ) ) ;
}
F_59 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_98 ,
V_58 -> V_47 , F_76 ( V_58 ) ) ;
}
F_60 ( V_17 , V_58 ) ;
}
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_77 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_138 , V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_99 , V_66 -> V_177 ) ;
F_10 ( V_17 , L_100 , V_66 -> V_178 ) ;
for ( V_138 = 0 ; V_138 < V_66 -> V_178 ; V_138 ++ ) {
struct V_25 * V_26 = V_66 -> V_179 [ V_138 ] . V_26 ;
F_10 ( V_17 , L_101 ,
V_138 , V_66 -> V_179 [ V_138 ] . V_35 ) ;
if ( V_26 == NULL )
F_23 ( V_17 , L_102 ) ;
else
F_19 ( V_17 , V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_78 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_135 * V_58 ;
const T_4 * V_180 ;
int V_138 ;
V_58 = & V_66 -> V_58 [ ( T_2 ) V_8 -> V_12 -> V_18 ] ;
V_180 = V_58 -> V_181 . V_182 ;
if ( V_180 == NULL )
return 0 ;
for ( V_138 = 0 ; V_138 < 4096 / sizeof( T_4 ) / 4 ; V_138 += 4 ) {
F_10 ( V_17 , L_103 ,
V_138 * 4 ,
V_180 [ V_138 ] , V_180 [ V_138 + 1 ] , V_180 [ V_138 + 2 ] , V_180 [ V_138 + 3 ] ) ;
}
return 0 ;
}
static T_5
F_79 ( struct V_106 * V_183 ,
const char T_6 * V_184 ,
T_3 V_185 ,
T_7 * V_186 )
{
struct V_187 * V_188 = V_183 -> V_189 ;
struct V_20 * V_21 = V_188 -> V_21 ;
int V_73 ;
F_80 ( L_104 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_81 ( V_21 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_185 ;
}
static int F_82 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_190 -> V_191 ;
struct V_187 * V_188 ;
V_188 = F_83 ( sizeof( * V_188 ) , V_9 ) ;
if ( ! V_188 )
return - V_10 ;
V_188 -> V_21 = V_21 ;
F_84 ( V_21 , V_188 ) ;
V_106 -> V_189 = V_188 ;
return 0 ;
}
static int F_85 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_187 * V_188 = V_106 -> V_189 ;
F_86 ( V_188 ) ;
F_87 ( V_188 ) ;
return 0 ;
}
static T_5 F_88 ( struct V_106 * V_106 , char T_6 * V_192 ,
T_3 V_72 , T_7 * V_193 )
{
struct V_187 * V_188 = V_106 -> V_189 ;
struct V_194 V_195 ;
T_7 V_196 = 0 ;
T_5 V_197 = 0 ;
int V_73 ;
V_73 = F_89 ( & V_195 , V_72 , * V_193 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_90 ( & V_195 , V_188 ) ;
if ( V_73 )
goto V_198;
V_197 = F_91 ( V_192 , V_72 , & V_196 ,
V_195 . V_199 ,
V_195 . V_200 ) ;
if ( V_197 < 0 )
V_73 = V_197 ;
else
* V_193 = V_195 . V_52 + V_197 ;
V_198:
F_92 ( & V_195 ) ;
return V_73 ? : V_197 ;
}
static int
F_93 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
* V_201 = V_66 -> V_202 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_94 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_95 ( V_21 , V_201 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int F_96 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_9 V_204 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
V_204 = F_97 ( V_205 ) ;
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_105 , ( V_204 >> 8 ) & 0x3f , ( V_204 & 0x3f ) ) ;
return 0 ;
}
static int F_98 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
F_62 ( V_66 ) ;
F_99 ( & V_66 -> V_206 . V_207 ) ;
if ( F_100 ( V_21 ) ) {
T_9 V_208 = F_97 ( V_209 ) ;
T_9 V_210 = F_97 ( V_211 ) ;
F_10 ( V_17 , L_106 , ( V_208 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_107 , V_208 & 0x3f ) ;
F_10 ( V_17 , L_108 , ( V_210 & V_212 ) >>
V_213 ) ;
F_10 ( V_17 , L_109 ,
( V_210 & V_214 ) >> V_215 ) ;
} else if ( ( F_101 ( V_21 ) || F_102 ( V_21 ) ) && ! F_73 ( V_21 ) ) {
T_4 V_216 = F_65 ( V_217 ) ;
T_4 V_218 = F_65 ( V_219 ) ;
T_4 V_220 = F_65 ( V_221 ) ;
T_4 V_222 , V_223 , V_224 ;
T_4 V_225 , V_226 , V_227 ;
T_4 V_228 , V_229 , V_230 ;
int V_231 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_198;
F_103 ( V_66 , V_232 ) ;
V_224 = F_65 ( V_233 ) ;
V_224 &= ~ V_234 ;
if ( F_104 ( V_21 ) )
V_224 >>= 24 ;
else
V_224 >>= 25 ;
V_224 *= V_235 ;
V_222 = F_65 ( V_236 ) ;
V_225 = F_65 ( V_237 ) ;
V_226 = F_65 ( V_238 ) ;
V_227 = F_65 ( V_239 ) ;
V_228 = F_65 ( V_240 ) ;
V_229 = F_65 ( V_241 ) ;
V_230 = F_65 ( V_242 ) ;
if ( F_104 ( V_21 ) )
V_223 = ( V_222 & V_243 ) >> V_244 ;
else
V_223 = ( V_222 & V_245 ) >> V_246 ;
V_223 *= V_235 ;
F_105 ( V_66 , V_232 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_110 , V_216 ) ;
F_10 ( V_17 , L_111 , V_222 ) ;
F_10 ( V_17 , L_112 ,
( V_216 & 0xff00 ) >> 8 ) ;
F_10 ( V_17 , L_113 ,
V_216 & 0xff ) ;
F_10 ( V_17 , L_114 ,
V_218 & 0xff ) ;
F_10 ( V_17 , L_115 , V_224 ) ;
F_10 ( V_17 , L_116 , V_223 ) ;
F_10 ( V_17 , L_117 , V_225 &
V_247 ) ;
F_10 ( V_17 , L_118 , V_226 &
V_248 ) ;
F_10 ( V_17 , L_119 , V_227 &
V_248 ) ;
F_10 ( V_17 , L_120 , V_228 &
V_249 ) ;
F_10 ( V_17 , L_121 , V_229 &
V_248 ) ;
F_10 ( V_17 , L_122 , V_230 &
V_248 ) ;
V_231 = ( V_220 & 0xff0000 ) >> 16 ;
F_10 ( V_17 , L_123 ,
V_231 * V_235 ) ;
V_231 = ( V_220 & 0xff00 ) >> 8 ;
F_10 ( V_17 , L_124 ,
V_231 * V_235 ) ;
V_231 = V_220 & 0xff ;
F_10 ( V_17 , L_125 ,
V_231 * V_235 ) ;
F_10 ( V_17 , L_126 ,
V_66 -> V_206 . V_231 * V_235 ) ;
} else if ( F_73 ( V_21 ) ) {
T_4 V_250 , V_201 ;
F_5 ( & V_66 -> V_206 . V_251 ) ;
V_250 = F_106 ( V_66 , V_252 ) ;
F_10 ( V_17 , L_127 , V_250 ) ;
F_10 ( V_17 , L_128 , V_66 -> V_253 ) ;
V_201 = F_107 ( V_66 ) ;
F_10 ( V_17 , L_129 ,
F_108 ( V_66 , V_201 ) ) ;
V_201 = F_109 ( V_66 ) ;
F_10 ( V_17 , L_130 ,
F_108 ( V_66 , V_201 ) ) ;
F_10 ( V_17 , L_131 ,
F_108 ( V_66 , ( V_250 >> 8 ) & 0xff ) ) ;
F_7 ( & V_66 -> V_206 . V_251 ) ;
} else {
F_23 ( V_17 , L_132 ) ;
}
V_198:
F_63 ( V_66 ) ;
return V_73 ;
}
static int F_110 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_254 ;
int V_73 , V_138 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
for ( V_138 = 0 ; V_138 < 16 ; V_138 ++ ) {
V_254 = F_65 ( V_255 + V_138 * 4 ) ;
F_10 ( V_17 , L_133 , V_138 , V_254 ,
( V_254 & V_256 ) >> V_257 ) ;
}
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static inline int F_111 ( int V_258 )
{
return 1250 - ( V_258 * 25 ) ;
}
static int F_112 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_259 ;
int V_73 , V_138 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
for ( V_138 = 1 ; V_138 <= 32 ; V_138 ++ ) {
V_259 = F_65 ( V_260 + V_138 * 4 ) ;
F_10 ( V_17 , L_134 , V_138 , V_259 ) ;
}
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_113 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_261 , V_262 ;
T_9 V_263 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
V_261 = F_65 ( V_264 ) ;
V_262 = F_65 ( V_265 ) ;
V_263 = F_97 ( V_205 ) ;
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_135 , ( V_261 & V_266 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_136 ,
( V_261 & V_267 ) >>
V_268 ) ;
F_10 ( V_17 , L_137 ,
V_261 & V_269 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_138 ,
V_261 & V_270 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_139 ,
V_261 & V_271 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_140 ,
( V_261 & V_272 ) >> V_273 ) ;
F_10 ( V_17 , L_141 ,
( V_261 & V_274 ) >> V_275 ) ;
F_10 ( V_17 , L_142 , ( V_261 & V_276 ) ) ;
F_10 ( V_17 , L_143 , ( V_263 & 0x3f ) ) ;
F_10 ( V_17 , L_144 , ( ( V_263 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_145 ,
( V_262 & V_277 ) ? L_2 : L_1 ) ;
F_23 ( V_17 , L_146 ) ;
switch ( V_262 & V_278 ) {
case V_279 :
F_23 ( V_17 , L_147 ) ;
break;
case V_280 :
F_23 ( V_17 , L_148 ) ;
break;
case V_281 :
F_23 ( V_17 , L_149 ) ;
break;
case V_282 :
F_23 ( V_17 , L_150 ) ;
break;
case V_283 :
F_23 ( V_17 , L_151 ) ;
break;
case V_284 :
F_23 ( V_17 , L_152 ) ;
break;
default:
F_23 ( V_17 , L_153 ) ;
break;
}
return 0 ;
}
static int F_114 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_285 , V_286 ;
unsigned V_287 = 0 , V_288 = 0 ;
V_285 = F_65 ( V_289 ) ;
V_286 = F_65 ( V_290 ) ;
F_10 ( V_17 , L_154 ,
F_1 ( V_285 & V_291 ) ) ;
F_10 ( V_17 , L_155 ,
F_1 ( V_285 & V_292 ) ) ;
F_10 ( V_17 , L_137 ,
F_1 ( V_285 & V_292 ) ) ;
F_10 ( V_17 , L_138 ,
F_1 ( ( V_285 & V_293 ) ==
V_294 ) ) ;
F_10 ( V_17 , L_156 ,
F_1 ( V_286 & ( V_295 |
F_115 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_157 ,
( F_65 ( V_296 ) &
V_297 ) ? L_158 : L_159 ) ;
F_10 ( V_17 , L_160 ,
( F_65 ( V_296 ) &
V_298 ) ? L_158 : L_159 ) ;
F_116 ( & V_66 -> V_299 . V_300 ) ;
V_287 = V_66 -> V_299 . V_287 ;
V_288 = V_66 -> V_299 . V_288 ;
F_117 ( & V_66 -> V_299 . V_300 ) ;
F_10 ( V_17 , L_161 , V_287 ) ;
F_10 ( V_17 , L_162 , V_288 ) ;
return 0 ;
}
static int F_118 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_285 , V_301 , V_286 , V_302 = 0 ;
unsigned V_303 ;
int V_72 = 0 , V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
F_116 ( & V_66 -> V_299 . V_300 ) ;
V_303 = V_66 -> V_299 . V_303 ;
F_117 ( & V_66 -> V_299 . V_300 ) ;
if ( V_303 ) {
F_23 ( V_17 , L_163
L_164 ) ;
} else {
while ( V_72 ++ < 50 && ( F_119 ( V_304 ) & 1 ) )
F_120 ( 10 ) ;
F_10 ( V_17 , L_165 , F_1 ( V_72 < 51 ) ) ;
}
V_301 = F_121 ( V_66 -> V_305 + V_306 ) ;
F_122 ( false , V_306 , V_301 , 4 , true ) ;
V_285 = F_65 ( V_289 ) ;
V_286 = F_65 ( V_290 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_5 ( & V_66 -> V_206 . V_251 ) ;
F_123 ( V_66 , V_307 , & V_302 ) ;
F_7 ( & V_66 -> V_206 . V_251 ) ;
F_63 ( V_66 ) ;
F_10 ( V_17 , L_154 ,
F_1 ( V_285 & V_291 ) ) ;
F_10 ( V_17 , L_137 ,
F_1 ( V_285 & V_292 ) ) ;
F_10 ( V_17 , L_138 ,
F_1 ( ( V_285 & V_293 ) ==
V_294 ) ) ;
F_10 ( V_17 , L_166 ,
F_1 ( V_286 & V_308 ) ) ;
F_10 ( V_17 , L_156 ,
F_1 ( V_286 & V_309 ) ) ;
F_10 ( V_17 , L_167 ,
F_1 ( V_286 & V_310 ) ) ;
F_10 ( V_17 , L_168 ,
F_1 ( V_286 & V_311 ) ) ;
F_23 ( V_17 , L_169 ) ;
switch ( V_301 & V_312 ) {
case V_313 :
if ( V_301 & V_314 )
F_23 ( V_17 , L_170 ) ;
else
F_23 ( V_17 , L_147 ) ;
break;
case V_315 :
F_23 ( V_17 , L_171 ) ;
break;
case V_316 :
F_23 ( V_17 , L_172 ) ;
break;
case V_317 :
F_23 ( V_17 , L_173 ) ;
break;
default:
F_23 ( V_17 , L_174 ) ;
break;
}
F_10 ( V_17 , L_175 ,
F_1 ( V_301 & V_314 ) ) ;
F_10 ( V_17 , L_176 ,
F_65 ( V_318 ) ) ;
F_10 ( V_17 , L_177 ,
F_65 ( V_319 ) ) ;
F_10 ( V_17 , L_178 ,
F_65 ( V_320 ) ) ;
F_10 ( V_17 , L_179 ,
F_65 ( V_321 ) ) ;
F_10 ( V_17 , L_180 ,
F_124 ( ( ( V_302 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_181 ,
F_124 ( ( ( V_302 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_182 ,
F_124 ( ( ( V_302 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_125 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_73 ( V_21 ) )
return F_114 ( V_17 ) ;
else if ( F_101 ( V_21 ) || F_102 ( V_21 ) )
return F_118 ( V_17 ) ;
else
return F_113 ( V_17 ) ;
}
static int F_126 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_127 ( V_21 ) ) {
F_23 ( V_17 , L_183 ) ;
return 0 ;
}
F_62 ( V_66 ) ;
if ( F_128 ( V_21 ) ) {
F_23 ( V_17 , L_184 ) ;
} else {
F_23 ( V_17 , L_185 ) ;
switch ( V_66 -> V_322 . V_323 ) {
case V_324 :
F_23 ( V_17 , L_186 ) ;
break;
case V_325 :
F_23 ( V_17 , L_187 ) ;
break;
case V_326 :
F_23 ( V_17 , L_188 ) ;
break;
case V_327 :
F_23 ( V_17 , L_189 ) ;
break;
case V_328 :
F_23 ( V_17 , L_190 ) ;
break;
case V_329 :
F_23 ( V_17 , L_191 ) ;
break;
case V_330 :
F_23 ( V_17 , L_192 ) ;
break;
case V_331 :
F_23 ( V_17 , L_193 ) ;
break;
case V_332 :
F_23 ( V_17 , L_194 ) ;
break;
case V_333 :
F_23 ( V_17 , L_195 ) ;
break;
case V_334 :
F_23 ( V_17 , L_196 ) ;
break;
default:
F_23 ( V_17 , L_197 ) ;
}
F_25 ( V_17 , '\n' ) ;
}
F_63 ( V_66 ) ;
return 0 ;
}
static int F_129 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_130 ( V_21 ) ) {
F_23 ( V_17 , L_198 ) ;
return 0 ;
}
F_62 ( V_66 ) ;
if ( F_131 ( V_21 ) || F_65 ( V_335 ) & V_336 )
F_23 ( V_17 , L_199 ) ;
else
F_23 ( V_17 , L_200 ) ;
F_63 ( V_66 ) ;
return 0 ;
}
static int F_132 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_337 = false ;
F_62 ( V_66 ) ;
if ( F_75 ( V_21 ) )
V_337 = F_65 ( V_338 ) & V_339 ;
else if ( F_133 ( V_21 ) || F_134 ( V_21 ) || F_135 ( V_21 ) )
V_337 = F_65 ( V_340 ) & V_341 ;
else if ( F_136 ( V_21 ) )
V_337 = F_65 ( V_342 ) & V_343 ;
else if ( F_137 ( V_21 ) )
V_337 = F_65 ( V_344 ) & V_345 ;
F_63 ( V_66 ) ;
F_10 ( V_17 , L_201 ,
V_337 ? L_202 : L_203 ) ;
return 0 ;
}
static int F_138 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned long V_346 , V_347 , V_348 ;
int V_73 ;
if ( ! F_100 ( V_21 ) )
return - V_349 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_346 = F_139 ( V_66 ) ;
V_347 = F_140 ( V_66 ) ;
V_348 = F_141 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_204 , V_346 ) ;
F_10 ( V_17 , L_205 , V_347 ) ;
F_10 ( V_17 , L_206 , V_348 ) ;
F_10 ( V_17 , L_207 , V_347 + V_348 ) ;
return 0 ;
}
static int F_142 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
int V_350 , V_351 ;
if ( ! ( F_101 ( V_21 ) || F_102 ( V_21 ) ) ) {
F_23 ( V_17 , L_208 ) ;
return 0 ;
}
F_62 ( V_66 ) ;
F_99 ( & V_66 -> V_206 . V_207 ) ;
V_73 = F_27 ( & V_66 -> V_206 . V_251 ) ;
if ( V_73 )
goto V_198;
F_23 ( V_17 , L_209 ) ;
for ( V_350 = V_66 -> V_206 . V_352 ;
V_350 <= V_66 -> V_206 . V_353 ;
V_350 ++ ) {
V_351 = V_350 ;
F_123 ( V_66 ,
V_354 ,
& V_351 ) ;
F_10 ( V_17 , L_210 ,
V_350 * V_235 ,
( ( V_351 >> 0 ) & 0xff ) * 100 ,
( ( V_351 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_66 -> V_206 . V_251 ) ;
V_198:
F_63 ( V_66 ) ;
return V_73 ;
}
static int F_143 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
F_10 ( V_17 , L_211 , ( unsigned long ) F_65 ( 0x112f4 ) ) ;
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_144 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_355 * V_356 = & V_66 -> V_356 ;
void * V_18 = F_3 ( V_357 , V_9 ) ;
int V_73 ;
if ( V_18 == NULL )
return - V_10 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_198;
if ( V_356 -> V_358 ) {
F_145 ( V_18 , V_356 -> V_358 , V_357 ) ;
F_146 ( V_17 , V_18 , V_357 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
V_198:
F_87 ( V_18 ) ;
return 0 ;
}
static int F_147 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_359 * V_360 = NULL ;
struct V_361 * V_362 ;
#ifdef F_148
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_27 ( & V_21 -> V_363 . V_364 ) ;
if ( V_73 )
return V_73 ;
V_360 = V_66 -> V_365 ;
V_362 = F_149 ( V_360 -> V_366 . V_362 ) ;
F_10 ( V_17 , L_212 ,
V_362 -> V_36 . V_367 ,
V_362 -> V_36 . V_368 ,
V_362 -> V_36 . V_369 ,
V_362 -> V_36 . V_370 ,
F_55 ( & V_362 -> V_36 . V_371 . V_371 ) ) ;
F_19 ( V_17 , V_362 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
F_7 ( & V_21 -> V_363 . V_364 ) ;
#endif
F_5 ( & V_21 -> V_363 . V_372 ) ;
F_21 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_360 && & V_362 -> V_36 == V_360 -> V_366 . V_362 )
continue;
F_10 ( V_17 , L_213 ,
V_362 -> V_36 . V_367 ,
V_362 -> V_36 . V_368 ,
V_362 -> V_36 . V_369 ,
V_362 -> V_36 . V_370 ,
F_55 ( & V_362 -> V_36 . V_371 . V_371 ) ) ;
F_19 ( V_17 , V_362 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_363 . V_372 ) ;
return 0 ;
}
static int F_150 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_135 * V_58 ;
struct V_59 * V_60 ;
int V_73 , V_138 ;
V_73 = F_27 ( & V_21 -> V_363 . V_364 ) ;
if ( V_73 )
return V_73 ;
if ( V_66 -> V_373 . V_374 ) {
F_23 ( V_17 , L_214 ) ;
F_19 ( V_17 , V_66 -> V_373 . V_374 ) ;
F_25 ( V_17 , '\n' ) ;
}
if ( V_66 -> V_373 . V_375 ) {
F_23 ( V_17 , L_215 ) ;
F_19 ( V_17 , V_66 -> V_373 . V_375 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_21 (ctx, &dev_priv->context_list, link) {
F_23 ( V_17 , L_216 ) ;
F_24 ( V_17 , V_60 ) ;
F_59 (ring, dev_priv, i)
if ( V_58 -> V_376 == V_60 )
F_10 ( V_17 , L_217 , V_58 -> V_47 ) ;
F_19 ( V_17 , V_60 -> V_26 ) ;
F_25 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_363 . V_364 ) ;
return 0 ;
}
static int F_151 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned V_303 = 0 , V_287 = 0 , V_288 = 0 ;
F_116 ( & V_66 -> V_299 . V_300 ) ;
if ( F_73 ( V_21 ) ) {
V_287 = V_66 -> V_299 . V_287 ;
V_288 = V_66 -> V_299 . V_288 ;
} else
V_303 = V_66 -> V_299 . V_303 ;
F_117 ( & V_66 -> V_299 . V_300 ) ;
if ( F_73 ( V_21 ) ) {
F_10 ( V_17 , L_218 , V_287 ) ;
F_10 ( V_17 , L_219 , V_288 ) ;
} else
F_10 ( V_17 , L_220 , V_303 ) ;
return 0 ;
}
static const char * F_152 ( unsigned V_377 )
{
switch ( V_377 ) {
case V_378 :
return L_221 ;
case V_379 :
return L_222 ;
case V_380 :
return L_223 ;
case V_381 :
return L_224 ;
case V_382 :
return L_225 ;
case V_383 :
return L_226 ;
case V_384 :
return L_227 ;
case V_385 :
return L_228 ;
}
return L_229 ;
}
static int F_153 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
F_10 ( V_17 , L_230 ,
F_152 ( V_66 -> V_107 . V_386 ) ) ;
F_10 ( V_17 , L_231 ,
F_152 ( V_66 -> V_107 . V_387 ) ) ;
if ( F_154 ( V_21 ) || F_155 ( V_21 ) ) {
F_10 ( V_17 , L_232 ,
F_65 ( V_388 ) ) ;
F_10 ( V_17 , L_233 ,
F_97 ( V_389 ) ) ;
F_10 ( V_17 , L_234 ,
F_97 ( V_390 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_235 ,
F_65 ( V_391 ) ) ;
F_10 ( V_17 , L_236 ,
F_65 ( V_392 ) ) ;
F_10 ( V_17 , L_237 ,
F_65 ( V_393 ) ) ;
F_10 ( V_17 , L_238 ,
F_65 ( V_394 ) ) ;
if ( F_156 ( V_21 ) )
F_10 ( V_17 , L_239 ,
F_65 ( V_395 ) ) ;
else
F_10 ( V_17 , L_240 ,
F_65 ( V_396 ) ) ;
F_10 ( V_17 , L_241 ,
F_65 ( V_397 ) ) ;
}
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_157 ( int V_86 , void * V_87 , void * V_18 )
{
struct V_59 * V_60 = V_87 ;
struct V_16 * V_17 = V_18 ;
struct V_93 * V_94 = F_158 ( V_60 ) ;
V_94 -> V_398 ( V_94 , V_17 ) ;
return 0 ;
}
static void F_159 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_135 * V_58 ;
struct V_93 * V_94 = V_66 -> V_107 . V_399 ;
int V_203 , V_138 ;
if ( ! V_94 )
return;
F_10 ( V_17 , L_242 , V_94 -> V_400 ) ;
F_10 ( V_17 , L_243 , V_94 -> V_401 ) ;
F_59 (ring, dev_priv, unused) {
F_10 ( V_17 , L_244 , V_58 -> V_47 ) ;
for ( V_138 = 0 ; V_138 < 4 ; V_138 ++ ) {
T_4 V_402 = 0x270 + V_138 * 8 ;
T_8 V_403 = F_65 ( V_58 -> V_404 + V_402 + 4 ) ;
V_403 <<= 32 ;
V_403 |= F_65 ( V_58 -> V_404 + V_402 ) ;
for ( V_138 = 0 ; V_138 < 4 ; V_138 ++ )
F_10 ( V_17 , L_245 , V_138 , V_403 ) ;
}
}
}
static void F_160 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_135 * V_58 ;
struct V_105 * V_106 ;
int V_138 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_246 , F_65 ( V_405 ) ) ;
F_59 (ring, dev_priv, i) {
F_10 ( V_17 , L_244 , V_58 -> V_47 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_246 , F_65 ( F_161 ( V_58 ) ) ) ;
F_10 ( V_17 , L_247 , F_65 ( F_162 ( V_58 ) ) ) ;
F_10 ( V_17 , L_248 , F_65 ( F_163 ( V_58 ) ) ) ;
F_10 ( V_17 , L_249 , F_65 ( F_164 ( V_58 ) ) ) ;
}
if ( V_66 -> V_107 . V_399 ) {
struct V_93 * V_94 = V_66 -> V_107 . V_399 ;
F_23 ( V_17 , L_250 ) ;
F_10 ( V_17 , L_251 , V_94 -> V_406 ) ;
V_94 -> V_398 ( V_94 , V_17 ) ;
} else
return;
F_45 (file, &dev->filelist, lhead) {
struct V_407 * V_96 = V_106 -> V_115 ;
struct V_93 * V_408 ;
V_408 = F_158 ( V_96 -> V_409 ) ;
F_10 ( V_17 , L_252 ,
F_165 ( V_106 -> V_117 , V_118 ) -> V_119 ) ;
F_23 ( V_17 , L_253 ) ;
F_46 ( & V_96 -> V_410 , F_157 , V_17 ) ;
}
F_10 ( V_17 , L_254 , F_65 ( V_411 ) ) ;
}
static int F_166 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_159 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_160 ( V_17 , V_21 ) ;
F_63 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_167 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! F_73 ( V_21 ) ) {
F_23 ( V_17 , L_255 ) ;
return 0 ;
}
V_73 = F_27 ( & V_66 -> V_412 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_256 , F_65 ( V_413 ) ) ;
F_10 ( V_17 , L_257 ,
F_168 ( V_66 , V_414 , F_169 ( 0 ) ) ) ;
F_10 ( V_17 , L_258 ,
F_168 ( V_66 , V_414 , F_169 ( 1 ) ) ) ;
F_10 ( V_17 , L_259 ,
F_168 ( V_66 , V_414 , F_170 ( 0 ) ) ) ;
F_10 ( V_17 , L_260 ,
F_168 ( V_66 , V_414 , F_170 ( 1 ) ) ) ;
F_10 ( V_17 , L_261 ,
F_168 ( V_66 , V_414 , F_171 ( 0 ) ) ) ;
F_10 ( V_17 , L_262 ,
F_168 ( V_66 , V_414 , F_171 ( 1 ) ) ) ;
F_10 ( V_17 , L_263 ,
F_168 ( V_66 , V_414 , F_172 ( 0 ) ) ) ;
F_10 ( V_17 , L_264 ,
F_168 ( V_66 , V_414 , F_172 ( 1 ) ) ) ;
F_10 ( V_17 , L_265 ,
F_168 ( V_66 , V_414 , V_415 ) ) ;
F_7 ( & V_66 -> V_412 ) ;
return 0 ;
}
static int F_173 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
F_10 ( V_17 , L_266 , F_1 ( F_174 ( V_21 ) ) ) ;
F_10 ( V_17 , L_267 , V_66 -> V_416 ) ;
return 0 ;
}
static int F_175 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_417 = 0 ;
bool V_418 = false ;
F_62 ( V_66 ) ;
F_10 ( V_17 , L_268 , F_1 ( V_66 -> V_419 . V_420 ) ) ;
F_10 ( V_17 , L_269 , F_1 ( V_66 -> V_419 . V_421 ) ) ;
V_418 = F_176 ( V_21 ) &&
F_65 ( F_177 ( V_21 ) ) & V_422 ;
F_10 ( V_17 , L_270 , F_1 ( V_418 ) ) ;
if ( F_176 ( V_21 ) )
V_417 = F_65 ( F_178 ( V_21 ) ) &
V_423 ;
F_10 ( V_17 , L_271 , V_417 ) ;
F_63 ( V_66 ) ;
return 0 ;
}
static int F_179 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_424 * V_425 ;
struct V_426 * V_427 ;
struct V_428 * V_428 = NULL ;
int V_73 ;
T_10 V_429 [ 6 ] ;
F_180 ( V_21 ) ;
F_21 (connector, &dev->mode_config.connector_list,
base.head) {
if ( V_427 -> V_36 . V_430 != V_431 )
continue;
if ( ! V_427 -> V_36 . V_425 )
continue;
V_425 = F_181 ( V_427 -> V_36 . V_425 ) ;
if ( V_425 -> type != V_432 )
continue;
V_428 = F_182 ( & V_425 -> V_36 ) ;
V_73 = F_183 ( V_428 , V_429 ) ;
if ( V_73 )
goto V_198;
F_10 ( V_17 , L_272 ,
V_429 [ 0 ] , V_429 [ 1 ] , V_429 [ 2 ] ,
V_429 [ 3 ] , V_429 [ 4 ] , V_429 [ 5 ] ) ;
goto V_198;
}
V_73 = - V_349 ;
V_198:
F_184 ( V_21 ) ;
return V_73 ;
}
static int F_185 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_8 V_433 ;
T_4 V_434 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_349 ;
F_62 ( V_66 ) ;
F_186 ( V_435 , V_433 ) ;
V_433 = ( V_433 & 0x1f00 ) >> 8 ;
V_434 = 1000000 / ( 1 << V_433 ) ;
V_433 = F_65 ( V_436 ) ;
V_433 *= V_434 ;
F_63 ( V_66 ) ;
F_10 ( V_17 , L_273 , ( long long unsigned ) V_433 ) ;
return 0 ;
}
static int F_187 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_104 ( V_21 ) ) {
F_23 ( V_17 , L_198 ) ;
return 0 ;
}
F_10 ( V_17 , L_274 , F_1 ( ! V_66 -> V_107 . V_437 ) ) ;
F_10 ( V_17 , L_275 ,
F_1 ( V_66 -> V_438 . V_439 ) ) ;
return 0 ;
}
static const char * F_188 ( enum V_440 V_441 )
{
switch ( V_441 ) {
case V_442 :
return L_276 ;
case V_443 :
return L_277 ;
case V_444 :
return L_278 ;
case V_445 :
return L_279 ;
case V_446 :
return L_280 ;
case V_447 :
return L_281 ;
case V_448 :
return L_282 ;
case V_449 :
return L_283 ;
case V_450 :
return L_284 ;
case V_451 :
return L_285 ;
case V_452 :
return L_286 ;
case V_453 :
return L_287 ;
case V_454 :
return L_288 ;
case V_455 :
return L_289 ;
case V_456 :
return L_290 ;
case V_457 :
return L_291 ;
case V_458 :
return L_292 ;
case V_459 :
return L_293 ;
case V_460 :
return L_294 ;
case V_461 :
return L_295 ;
case V_462 :
return L_296 ;
case V_463 :
return L_297 ;
case V_464 :
return L_298 ;
case V_465 :
return L_299 ;
default:
F_189 ( 1 ) ;
return L_300 ;
}
}
static int F_190 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_466 * V_467 = & V_66 -> V_467 ;
int V_138 ;
F_5 ( & V_467 -> V_300 ) ;
F_10 ( V_17 , L_301 , L_302 , L_303 ) ;
for ( V_138 = 0 ; V_138 < V_467 -> V_468 ; V_138 ++ ) {
struct V_469 * V_470 ;
enum V_440 V_471 ;
V_470 = & V_467 -> V_472 [ V_138 ] ;
F_10 ( V_17 , L_304 , V_470 -> V_47 ,
V_470 -> V_72 ) ;
for ( V_471 = 0 ; V_471 < V_473 ;
V_471 ++ ) {
if ( ! ( F_191 ( V_471 ) & V_470 -> V_474 ) )
continue;
F_10 ( V_17 , L_305 ,
F_188 ( V_471 ) ,
V_467 -> V_475 [ V_471 ] ) ;
}
}
F_7 ( & V_467 -> V_300 ) ;
return 0 ;
}
static void F_192 ( struct V_16 * V_17 , int V_476 ,
struct V_477 * V_478 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_476 ; V_138 ++ )
F_25 ( V_17 , '\t' ) ;
F_10 ( V_17 , L_306 ,
V_478 -> V_36 . V_86 , V_478 -> V_47 ,
V_478 -> V_479 , V_478 -> clock ,
V_478 -> V_480 , V_478 -> V_481 ,
V_478 -> V_482 , V_478 -> V_483 ,
V_478 -> V_484 , V_478 -> V_485 ,
V_478 -> V_486 , V_478 -> V_487 ,
V_478 -> type , V_478 -> V_121 ) ;
}
static void F_193 ( struct V_16 * V_17 ,
struct V_122 * V_122 ,
struct V_424 * V_424 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_488 * V_123 = & V_122 -> V_36 ;
struct V_426 * V_426 ;
struct V_489 * V_425 ;
V_425 = & V_424 -> V_36 ;
F_10 ( V_17 , L_307 ,
V_425 -> V_36 . V_86 , F_194 ( V_425 ) ) ;
F_195 (dev, encoder, intel_connector) {
struct V_490 * V_427 = & V_426 -> V_36 ;
F_10 ( V_17 , L_308 ,
V_427 -> V_36 . V_86 ,
F_196 ( V_427 ) ,
F_197 ( V_427 -> V_491 ) ) ;
if ( V_427 -> V_491 == V_492 ) {
struct V_477 * V_478 = & V_123 -> V_478 ;
F_10 ( V_17 , L_309 ) ;
F_192 ( V_17 , 2 , V_478 ) ;
} else {
F_25 ( V_17 , '\n' ) ;
}
}
}
static void F_198 ( struct V_16 * V_17 , struct V_122 * V_122 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_488 * V_123 = & V_122 -> V_36 ;
struct V_424 * V_424 ;
F_10 ( V_17 , L_310 ,
V_123 -> V_493 -> V_362 -> V_36 . V_86 , V_123 -> T_1 , V_123 -> V_494 ,
V_123 -> V_493 -> V_362 -> V_367 , V_123 -> V_493 -> V_362 -> V_368 ) ;
F_199 (dev, crtc, intel_encoder)
F_193 ( V_17 , V_122 , V_424 ) ;
}
static void F_200 ( struct V_16 * V_17 , struct V_495 * V_496 )
{
struct V_477 * V_478 = V_496 -> V_497 ;
F_10 ( V_17 , L_311 ) ;
F_192 ( V_17 , 2 , V_478 ) ;
}
static void F_201 ( struct V_16 * V_17 ,
struct V_426 * V_426 )
{
struct V_424 * V_424 = V_426 -> V_425 ;
struct V_428 * V_428 = F_182 ( & V_424 -> V_36 ) ;
F_10 ( V_17 , L_312 , V_428 -> V_498 [ V_499 ] ) ;
F_10 ( V_17 , L_313 , V_428 -> V_500 ? L_1 :
L_2 ) ;
if ( V_424 -> type == V_432 )
F_200 ( V_17 , & V_426 -> V_496 ) ;
}
static void F_202 ( struct V_16 * V_17 ,
struct V_426 * V_426 )
{
struct V_424 * V_424 = V_426 -> V_425 ;
struct V_501 * V_501 = F_203 ( & V_424 -> V_36 ) ;
F_10 ( V_17 , L_313 , V_501 -> V_500 ? L_1 :
L_2 ) ;
}
static void F_204 ( struct V_16 * V_17 ,
struct V_426 * V_426 )
{
F_200 ( V_17 , & V_426 -> V_496 ) ;
}
static void F_205 ( struct V_16 * V_17 ,
struct V_490 * V_427 )
{
struct V_426 * V_426 = F_206 ( V_427 ) ;
struct V_424 * V_424 = V_426 -> V_425 ;
struct V_477 * V_478 ;
F_10 ( V_17 , L_314 ,
V_427 -> V_36 . V_86 , F_196 ( V_427 ) ,
F_197 ( V_427 -> V_491 ) ) ;
if ( V_427 -> V_491 == V_492 ) {
F_10 ( V_17 , L_315 , V_427 -> V_502 . V_47 ) ;
F_10 ( V_17 , L_316 ,
V_427 -> V_502 . V_503 ,
V_427 -> V_502 . V_504 ) ;
F_10 ( V_17 , L_317 ,
F_207 ( V_427 -> V_502 . V_505 ) ) ;
F_10 ( V_17 , L_318 ,
V_427 -> V_502 . V_506 ) ;
}
if ( V_424 -> type == V_507 ||
V_424 -> type == V_432 )
F_201 ( V_17 , V_426 ) ;
else if ( V_424 -> type == V_508 )
F_202 ( V_17 , V_426 ) ;
else if ( V_424 -> type == V_509 )
F_204 ( V_17 , V_426 ) ;
F_10 ( V_17 , L_319 ) ;
F_21 (mode, &connector->modes, head)
F_192 ( V_17 , 2 , V_478 ) ;
}
static bool F_208 ( struct V_20 * V_21 , int V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_510 ;
if ( F_209 ( V_21 ) || F_210 ( V_21 ) )
V_510 = F_65 ( V_511 ) & V_512 ;
else if ( F_9 ( V_21 ) -> V_24 <= 6 || F_73 ( V_21 ) )
V_510 = F_65 ( F_211 ( V_124 ) ) & V_513 ;
else
V_510 = F_65 ( F_212 ( V_124 ) ) & V_513 ;
return V_510 ;
}
static bool F_213 ( struct V_20 * V_21 , int V_124 , int * T_1 , int * V_494 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_193 ;
if ( F_214 ( V_21 ) || F_104 ( V_21 ) || F_131 ( V_21 ) )
V_193 = F_65 ( F_215 ( V_124 ) ) ;
else
V_193 = F_65 ( F_216 ( V_124 ) ) ;
* T_1 = ( V_193 >> V_514 ) & V_515 ;
if ( V_193 & ( V_516 << V_514 ) )
* T_1 = - * T_1 ;
* V_494 = ( V_193 >> V_517 ) & V_515 ;
if ( V_193 & ( V_516 << V_517 ) )
* V_494 = - * V_494 ;
return F_208 ( V_21 , V_124 ) ;
}
static int F_217 ( struct V_16 * V_17 , void * V_203 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_122 * V_123 ;
struct V_490 * V_427 ;
F_62 ( V_66 ) ;
F_180 ( V_21 ) ;
F_10 ( V_17 , L_320 ) ;
F_10 ( V_17 , L_321 ) ;
F_21 (crtc, &dev->mode_config.crtc_list, base.head) {
bool V_97 ;
int T_1 , V_494 ;
F_10 ( V_17 , L_322 ,
V_123 -> V_36 . V_36 . V_86 , F_52 ( V_123 -> V_124 ) ,
F_1 ( V_123 -> V_97 ) ) ;
if ( V_123 -> V_97 ) {
F_198 ( V_17 , V_123 ) ;
V_97 = F_213 ( V_21 , V_123 -> V_124 , & T_1 , & V_494 ) ;
F_10 ( V_17 , L_323 ,
F_1 ( V_123 -> V_518 ) ,
T_1 , V_494 , V_123 -> V_519 ,
F_1 ( V_97 ) ) ;
}
}
F_10 ( V_17 , L_28 ) ;
F_10 ( V_17 , L_324 ) ;
F_10 ( V_17 , L_325 ) ;
F_21 (connector, &dev->mode_config.connector_list, head) {
F_205 ( V_17 , V_427 ) ;
}
F_184 ( V_21 ) ;
F_63 ( V_66 ) ;
return 0 ;
}
static int F_218 ( struct V_190 * V_190 , struct V_106 * V_520 )
{
struct V_521 * V_23 = V_190 -> V_191 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_522 * V_523 = & V_66 -> V_523 [ V_23 -> V_124 ] ;
if ( V_23 -> V_124 >= F_9 ( V_23 -> V_21 ) -> V_524 )
return - V_349 ;
F_116 ( & V_523 -> V_300 ) ;
if ( V_523 -> V_525 ) {
F_117 ( & V_523 -> V_300 ) ;
return - V_526 ;
}
V_523 -> V_525 = true ;
V_520 -> V_189 = V_190 -> V_191 ;
F_117 ( & V_523 -> V_300 ) ;
return 0 ;
}
static int F_219 ( struct V_190 * V_190 , struct V_106 * V_520 )
{
struct V_521 * V_23 = V_190 -> V_191 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_522 * V_523 = & V_66 -> V_523 [ V_23 -> V_124 ] ;
F_116 ( & V_523 -> V_300 ) ;
V_523 -> V_525 = false ;
F_117 ( & V_523 -> V_300 ) ;
return 0 ;
}
static int F_220 ( struct V_522 * V_523 )
{
F_221 ( & V_523 -> V_300 ) ;
return F_222 ( V_523 -> V_64 , V_523 -> V_527 ,
V_528 ) ;
}
static T_5
F_223 ( struct V_106 * V_520 , char T_6 * V_529 , T_3 V_72 ,
T_7 * V_193 )
{
struct V_521 * V_23 = V_520 -> V_189 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_522 * V_523 = & V_66 -> V_523 [ V_23 -> V_124 ] ;
char V_199 [ V_530 ] ;
int V_64 , V_527 , V_531 , V_532 ;
T_5 V_533 ;
if ( V_72 < V_534 )
return - V_79 ;
if ( V_523 -> V_535 == V_536 )
return 0 ;
F_116 ( & V_523 -> V_300 ) ;
while ( F_220 ( V_523 ) == 0 ) {
int V_73 ;
if ( V_520 -> V_537 & V_538 ) {
F_117 ( & V_523 -> V_300 ) ;
return - V_539 ;
}
V_73 = F_224 ( V_523 -> V_540 ,
F_220 ( V_523 ) , V_523 -> V_300 ) ;
if ( V_73 ) {
F_117 ( & V_523 -> V_300 ) ;
return V_73 ;
}
}
V_64 = V_523 -> V_64 ;
V_527 = V_523 -> V_527 ;
V_531 = F_225 ( ( T_3 ) F_222 ( V_64 , V_527 , V_528 ) ,
V_72 / V_534 ) ;
F_117 ( & V_523 -> V_300 ) ;
V_533 = 0 ;
V_532 = 0 ;
do {
struct V_541 * V_542 = & V_523 -> V_543 [ V_527 ] ;
int V_73 ;
V_533 += snprintf ( V_199 , V_530 ,
L_326 ,
V_542 -> V_544 , V_542 -> V_429 [ 0 ] ,
V_542 -> V_429 [ 1 ] , V_542 -> V_429 [ 2 ] ,
V_542 -> V_429 [ 3 ] , V_542 -> V_429 [ 4 ] ) ;
V_73 = F_226 ( V_529 + V_532 * V_534 ,
V_199 , V_534 ) ;
if ( V_73 == V_534 )
return - V_545 ;
F_227 ( V_528 ) ;
V_527 = ( V_527 + 1 ) & ( V_528 - 1 ) ;
V_532 ++ ;
} while ( -- V_531 );
F_116 ( & V_523 -> V_300 ) ;
V_523 -> V_527 = V_527 ;
F_117 ( & V_523 -> V_300 ) ;
return V_533 ;
}
static int F_228 ( struct V_4 * V_546 , struct V_2 * V_3 ,
enum V_124 V_124 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_521 * V_23 = & V_547 [ V_124 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_229 ( V_23 -> V_47 , V_548 , V_546 , V_23 ,
& V_549 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_230 ( enum V_550 V_535 )
{
F_231 ( F_232 ( V_551 ) != V_552 ) ;
return V_551 [ V_535 ] ;
}
static int F_233 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < V_553 ; V_138 ++ )
F_10 ( V_17 , L_327 , F_52 ( V_138 ) ,
F_230 ( V_66 -> V_523 [ V_138 ] . V_535 ) ) ;
return 0 ;
}
static int F_234 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_190 -> V_191 ;
return F_235 ( V_106 , F_233 , V_21 ) ;
}
static int F_236 ( enum V_550 * V_535 ,
T_11 * V_201 )
{
if ( * V_535 == V_554 )
* V_535 = V_555 ;
switch ( * V_535 ) {
case V_555 :
* V_201 = V_556 | V_557 ;
break;
case V_536 :
* V_201 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_237 ( struct V_20 * V_21 , enum V_124 V_124 ,
enum V_550 * V_535 )
{
struct V_424 * V_425 ;
struct V_122 * V_123 ;
struct V_558 * V_559 ;
int V_73 = 0 ;
* V_535 = V_555 ;
F_5 ( & V_21 -> V_363 . V_364 ) ;
F_21 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_425 -> V_36 . V_123 )
continue;
V_123 = F_238 ( V_425 -> V_36 . V_123 ) ;
if ( V_123 -> V_124 != V_124 )
continue;
switch ( V_425 -> type ) {
case V_560 :
* V_535 = V_561 ;
break;
case V_507 :
case V_432 :
V_559 = F_239 ( & V_425 -> V_36 ) ;
switch ( V_559 -> V_562 ) {
case V_563 :
* V_535 = V_564 ;
break;
case V_565 :
* V_535 = V_566 ;
break;
case V_567 :
* V_535 = V_568 ;
break;
default:
F_240 ( 1 , L_328 ,
F_241 ( V_559 -> V_562 ) ) ;
break;
}
break;
}
}
F_7 ( & V_21 -> V_363 . V_364 ) ;
return V_73 ;
}
static int F_242 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_550 * V_535 ,
T_11 * V_201 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_569 = false ;
if ( * V_535 == V_554 ) {
int V_73 = F_237 ( V_21 , V_124 , V_535 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_535 ) {
case V_555 :
* V_201 = V_556 | V_570 ;
break;
case V_564 :
* V_201 = V_556 | V_571 ;
V_569 = true ;
break;
case V_566 :
* V_201 = V_556 | V_572 ;
V_569 = true ;
break;
case V_536 :
* V_201 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_569 ) {
T_11 V_573 = F_65 ( V_574 ) ;
V_573 |= V_575 ;
if ( V_124 == V_414 )
V_573 |= V_576 ;
else
V_573 |= V_577 ;
F_243 ( V_574 , V_573 ) ;
}
return 0 ;
}
static int F_244 ( struct V_20 * V_21 ,
enum V_124 V_124 ,
enum V_550 * V_535 ,
T_11 * V_201 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_569 = false ;
if ( * V_535 == V_554 ) {
int V_73 = F_237 ( V_21 , V_124 , V_535 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_535 ) {
case V_555 :
* V_201 = V_556 | V_578 ;
break;
case V_561 :
if ( ! F_245 ( V_21 ) )
return - V_79 ;
* V_201 = V_556 | V_579 ;
break;
case V_564 :
if ( ! F_246 ( V_21 ) )
return - V_79 ;
* V_201 = V_556 | V_580 ;
V_569 = true ;
break;
case V_566 :
if ( ! F_246 ( V_21 ) )
return - V_79 ;
* V_201 = V_556 | V_581 ;
V_569 = true ;
break;
case V_568 :
if ( ! F_246 ( V_21 ) )
return - V_79 ;
* V_201 = V_556 | V_582 ;
V_569 = true ;
break;
case V_536 :
* V_201 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_569 ) {
T_11 V_573 = F_65 ( V_574 ) ;
F_189 ( ! F_246 ( V_21 ) ) ;
F_243 ( V_583 ,
F_65 ( V_583 ) | V_584 ) ;
if ( V_124 == V_414 )
V_573 |= V_576 ;
else
V_573 |= V_577 ;
F_243 ( V_574 , V_573 ) ;
}
return 0 ;
}
static void F_247 ( struct V_20 * V_21 ,
enum V_124 V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_573 = F_65 ( V_574 ) ;
if ( V_124 == V_414 )
V_573 &= ~ V_576 ;
else
V_573 &= ~ V_577 ;
if ( ! ( V_573 & V_585 ) )
V_573 &= ~ V_575 ;
F_243 ( V_574 , V_573 ) ;
}
static void F_248 ( struct V_20 * V_21 ,
enum V_124 V_124 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_573 = F_65 ( V_574 ) ;
if ( V_124 == V_414 )
V_573 &= ~ V_576 ;
else
V_573 &= ~ V_577 ;
F_243 ( V_574 , V_573 ) ;
if ( ! ( V_573 & V_585 ) ) {
F_243 ( V_583 ,
F_65 ( V_583 ) & ~ V_584 ) ;
}
}
static int F_249 ( enum V_550 * V_535 ,
T_11 * V_201 )
{
if ( * V_535 == V_554 )
* V_535 = V_555 ;
switch ( * V_535 ) {
case V_586 :
* V_201 = V_556 | V_587 ;
break;
case V_588 :
* V_201 = V_556 | V_589 ;
break;
case V_555 :
* V_201 = V_556 | V_590 ;
break;
case V_536 :
* V_201 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_250 ( enum V_550 * V_535 ,
T_11 * V_201 )
{
if ( * V_535 == V_554 )
* V_535 = V_591 ;
switch ( * V_535 ) {
case V_586 :
* V_201 = V_556 | V_592 ;
break;
case V_588 :
* V_201 = V_556 | V_593 ;
break;
case V_591 :
* V_201 = V_556 | V_594 ;
break;
case V_536 :
* V_201 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_251 ( struct V_20 * V_21 , enum V_124 V_124 ,
enum V_550 V_535 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_522 * V_523 = & V_66 -> V_523 [ V_124 ] ;
T_4 V_201 = 0 ;
int V_73 ;
if ( V_523 -> V_535 == V_535 )
return 0 ;
if ( V_523 -> V_535 && V_535 )
return - V_79 ;
if ( F_252 ( V_21 ) )
V_73 = F_236 ( & V_535 , & V_201 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_73 = F_244 ( V_21 , V_124 , & V_535 , & V_201 ) ;
else if ( F_73 ( V_21 ) )
V_73 = F_242 ( V_21 , V_124 , & V_535 , & V_201 ) ;
else if ( F_100 ( V_21 ) || F_101 ( V_21 ) )
V_73 = F_249 ( & V_535 , & V_201 ) ;
else
V_73 = F_250 ( & V_535 , & V_201 ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_535 ) {
F_80 ( L_329 ,
F_52 ( V_124 ) , F_230 ( V_535 ) ) ;
V_523 -> V_543 = F_83 ( sizeof( * V_523 -> V_543 ) *
V_528 ,
V_9 ) ;
if ( ! V_523 -> V_543 )
return - V_10 ;
F_116 ( & V_523 -> V_300 ) ;
V_523 -> V_64 = 0 ;
V_523 -> V_527 = 0 ;
F_117 ( & V_523 -> V_300 ) ;
}
V_523 -> V_535 = V_535 ;
F_243 ( F_253 ( V_124 ) , V_201 ) ;
F_254 ( F_253 ( V_124 ) ) ;
if ( V_535 == V_536 ) {
struct V_541 * V_543 ;
F_80 ( L_330 ,
F_52 ( V_124 ) ) ;
F_255 ( V_21 , V_124 ) ;
F_116 ( & V_523 -> V_300 ) ;
V_543 = V_523 -> V_543 ;
V_523 -> V_543 = NULL ;
F_117 ( & V_523 -> V_300 ) ;
F_87 ( V_543 ) ;
if ( F_246 ( V_21 ) )
F_248 ( V_21 , V_124 ) ;
else if ( F_73 ( V_21 ) )
F_247 ( V_21 , V_124 ) ;
}
return 0 ;
}
static int F_256 ( char * V_199 , char * V_595 [] , int V_596 )
{
int V_597 = 0 ;
while ( * V_199 ) {
char * V_598 ;
V_199 = F_257 ( V_199 ) ;
if ( ! * V_199 )
break;
for ( V_598 = V_199 ; * V_598 && ! isspace ( * V_598 ) ; V_598 ++ )
;
if ( V_597 == V_596 ) {
F_80 ( L_331 ,
V_596 ) ;
return - V_79 ;
}
if ( * V_598 )
* V_598 ++ = '\0' ;
V_595 [ V_597 ++ ] = V_199 ;
V_199 = V_598 ;
}
return V_597 ;
}
static int
F_258 ( const char * V_199 , enum V_599 * V_600 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < F_232 ( V_601 ) ; V_138 ++ )
if ( ! strcmp ( V_199 , V_601 [ V_138 ] ) ) {
* V_600 = V_138 ;
return 0 ;
}
return - V_79 ;
}
static int F_259 ( const char * V_199 , enum V_124 * V_124 )
{
const char V_47 = V_199 [ 0 ] ;
if ( V_47 < 'A' || V_47 >= F_52 ( V_553 ) )
return - V_79 ;
* V_124 = V_47 - 'A' ;
return 0 ;
}
static int
F_260 ( const char * V_199 , enum V_550 * V_56 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < F_232 ( V_551 ) ; V_138 ++ )
if ( ! strcmp ( V_199 , V_551 [ V_138 ] ) ) {
* V_56 = V_138 ;
return 0 ;
}
return - V_79 ;
}
static int F_261 ( struct V_20 * V_21 , char * V_199 , T_3 V_602 )
{
#define F_262 3
int V_597 ;
char * V_595 [ F_262 ] ;
enum V_124 V_124 ;
enum V_599 V_603 ;
enum V_550 V_535 ;
V_597 = F_256 ( V_199 , V_595 , F_262 ) ;
if ( V_597 != F_262 ) {
F_80 ( L_332 ,
F_262 ) ;
return - V_79 ;
}
if ( F_258 ( V_595 [ 0 ] , & V_603 ) < 0 ) {
F_80 ( L_333 , V_595 [ 0 ] ) ;
return - V_79 ;
}
if ( F_259 ( V_595 [ 1 ] , & V_124 ) < 0 ) {
F_80 ( L_334 , V_595 [ 1 ] ) ;
return - V_79 ;
}
if ( F_260 ( V_595 [ 2 ] , & V_535 ) < 0 ) {
F_80 ( L_335 , V_595 [ 2 ] ) ;
return - V_79 ;
}
return F_251 ( V_21 , V_124 , V_535 ) ;
}
static T_5 F_263 ( struct V_106 * V_106 , const char T_6 * V_184 ,
T_3 V_602 , T_7 * V_604 )
{
struct V_16 * V_17 = V_106 -> V_189 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_605 ;
int V_73 ;
if ( V_602 == 0 )
return 0 ;
if ( V_602 > V_606 - 1 ) {
F_80 ( L_336 ,
V_606 ) ;
return - V_607 ;
}
V_605 = F_3 ( V_602 + 1 , V_9 ) ;
if ( ! V_605 )
return - V_10 ;
if ( F_264 ( V_605 , V_184 , V_602 ) ) {
V_73 = - V_545 ;
goto V_198;
}
V_605 [ V_602 ] = '\0' ;
V_73 = F_261 ( V_21 , V_605 , V_602 ) ;
V_198:
F_87 ( V_605 ) ;
if ( V_73 < 0 )
return V_73 ;
* V_604 += V_602 ;
return V_602 ;
}
static void F_265 ( struct V_16 * V_17 , const T_12 V_608 [ 5 ] )
{
struct V_20 * V_21 = V_17 -> V_19 ;
int V_609 = F_104 ( V_21 ) || F_131 ( V_21 ) ? 5 : 4 ;
int V_610 ;
F_180 ( V_21 ) ;
for ( V_610 = 0 ; V_610 < V_609 ; V_610 ++ ) {
unsigned int V_611 = V_608 [ V_610 ] ;
if ( V_610 > 0 )
V_611 *= 5 ;
F_10 ( V_17 , L_337 ,
V_610 , V_608 [ V_610 ] ,
V_611 / 10 , V_611 % 10 ) ;
}
F_184 ( V_21 ) ;
}
static int F_266 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_265 ( V_17 , F_267 ( V_21 ) -> V_608 . V_612 ) ;
return 0 ;
}
static int F_268 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_265 ( V_17 , F_267 ( V_21 ) -> V_608 . V_613 ) ;
return 0 ;
}
static int F_269 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
F_265 ( V_17 , F_267 ( V_21 ) -> V_608 . V_614 ) ;
return 0 ;
}
static int F_270 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_190 -> V_191 ;
if ( ! F_75 ( V_21 ) )
return - V_349 ;
return F_235 ( V_106 , F_266 , V_21 ) ;
}
static int F_271 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_190 -> V_191 ;
if ( ! F_75 ( V_21 ) )
return - V_349 ;
return F_235 ( V_106 , F_268 , V_21 ) ;
}
static int F_272 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_190 -> V_191 ;
if ( ! F_75 ( V_21 ) )
return - V_349 ;
return F_235 ( V_106 , F_269 , V_21 ) ;
}
static T_5 F_273 ( struct V_106 * V_106 , const char T_6 * V_184 ,
T_3 V_602 , T_7 * V_604 , T_12 V_608 [ 5 ] )
{
struct V_16 * V_17 = V_106 -> V_189 ;
struct V_20 * V_21 = V_17 -> V_19 ;
T_12 V_615 [ 5 ] = { 0 } ;
int V_609 = F_104 ( V_21 ) || F_131 ( V_21 ) ? 5 : 4 ;
int V_610 ;
int V_73 ;
char V_573 [ 32 ] ;
if ( V_602 >= sizeof( V_573 ) )
return - V_79 ;
if ( F_264 ( V_573 , V_184 , V_602 ) )
return - V_545 ;
V_573 [ V_602 ] = '\0' ;
V_73 = sscanf ( V_573 , L_338 , & V_615 [ 0 ] , & V_615 [ 1 ] , & V_615 [ 2 ] , & V_615 [ 3 ] , & V_615 [ 4 ] ) ;
if ( V_73 != V_609 )
return - V_79 ;
F_180 ( V_21 ) ;
for ( V_610 = 0 ; V_610 < V_609 ; V_610 ++ )
V_608 [ V_610 ] = V_615 [ V_610 ] ;
F_184 ( V_21 ) ;
return V_602 ;
}
static T_5 F_274 ( struct V_106 * V_106 , const char T_6 * V_184 ,
T_3 V_602 , T_7 * V_604 )
{
struct V_16 * V_17 = V_106 -> V_189 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_273 ( V_106 , V_184 , V_602 , V_604 , F_267 ( V_21 ) -> V_608 . V_612 ) ;
}
static T_5 F_275 ( struct V_106 * V_106 , const char T_6 * V_184 ,
T_3 V_602 , T_7 * V_604 )
{
struct V_16 * V_17 = V_106 -> V_189 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_273 ( V_106 , V_184 , V_602 , V_604 , F_267 ( V_21 ) -> V_608 . V_613 ) ;
}
static T_5 F_276 ( struct V_106 * V_106 , const char T_6 * V_184 ,
T_3 V_602 , T_7 * V_604 )
{
struct V_16 * V_17 = V_106 -> V_189 ;
struct V_20 * V_21 = V_17 -> V_19 ;
return F_273 ( V_106 , V_184 , V_602 , V_604 , F_267 ( V_21 ) -> V_608 . V_614 ) ;
}
static int
F_277 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_201 = F_55 ( & V_66 -> V_616 . V_617 ) ;
return 0 ;
}
static int
F_278 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
F_279 ( V_21 , V_201 ,
L_339 , V_201 ) ;
return 0 ;
}
static int
F_280 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_201 = V_66 -> V_616 . V_618 ;
return 0 ;
}
static int
F_281 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_80 ( L_340 , V_201 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_616 . V_618 = V_201 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_282 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_201 = V_66 -> V_616 . V_619 ;
return 0 ;
}
static int
F_283 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_616 . V_619 = V_201 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_284 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_201 = V_66 -> V_616 . V_620 ;
return 0 ;
}
static int
F_285 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_80 ( L_341 , V_201 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_616 . V_620 = V_201 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_286 ( void * V_18 , T_8 * V_201 )
{
* V_201 = V_621 ;
return 0 ;
}
static int
F_287 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 , * V_622 ;
struct V_68 * V_51 ;
struct V_33 * V_34 , * T_1 ;
int V_73 ;
F_288 ( L_342 , V_201 ) ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( V_201 & V_623 ) {
V_73 = F_289 ( V_21 ) ;
if ( V_73 )
goto V_624;
}
if ( V_201 & ( V_625 | V_623 ) )
F_290 ( V_21 ) ;
if ( V_201 & V_626 ) {
F_21 (vm, &dev_priv->vm_list, global_link) {
F_291 (vma, x, &vm->inactive_list,
mm_list) {
if ( V_34 -> V_35 )
continue;
V_73 = F_292 ( V_34 ) ;
if ( V_73 )
goto V_624;
}
}
}
if ( V_201 & V_627 ) {
F_291 (obj, next, &dev_priv->mm.unbound_list,
global_list)
if ( V_26 -> V_628 == 0 ) {
V_73 = F_293 ( V_26 ) ;
if ( V_73 )
goto V_624;
}
}
V_624:
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int
F_294 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_101 ( V_21 ) || F_102 ( V_21 ) ) )
return - V_349 ;
F_99 ( & V_66 -> V_206 . V_207 ) ;
V_73 = F_27 ( & V_66 -> V_206 . V_251 ) ;
if ( V_73 )
return V_73 ;
if ( F_73 ( V_21 ) )
* V_201 = F_108 ( V_66 , V_66 -> V_206 . V_353 ) ;
else
* V_201 = V_66 -> V_206 . V_353 * V_235 ;
F_7 ( & V_66 -> V_206 . V_251 ) ;
return 0 ;
}
static int
F_295 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_220 , V_629 , V_630 ;
int V_73 ;
if ( ! ( F_101 ( V_21 ) || F_102 ( V_21 ) ) )
return - V_349 ;
F_99 ( & V_66 -> V_206 . V_207 ) ;
F_80 ( L_343 , V_201 ) ;
V_73 = F_27 ( & V_66 -> V_206 . V_251 ) ;
if ( V_73 )
return V_73 ;
if ( F_73 ( V_21 ) ) {
V_201 = F_296 ( V_66 , V_201 ) ;
V_629 = F_107 ( V_66 ) ;
V_630 = F_109 ( V_66 ) ;
} else {
F_297 ( V_201 , V_235 ) ;
V_220 = F_65 ( V_221 ) ;
V_629 = V_66 -> V_206 . V_231 ;
V_630 = ( V_220 >> 16 ) & 0xff ;
}
if ( V_201 < V_630 || V_201 > V_629 || V_201 < V_66 -> V_206 . V_352 ) {
F_7 ( & V_66 -> V_206 . V_251 ) ;
return - V_79 ;
}
V_66 -> V_206 . V_353 = V_201 ;
if ( F_73 ( V_21 ) )
F_298 ( V_21 , V_201 ) ;
else
F_299 ( V_21 , V_201 ) ;
F_7 ( & V_66 -> V_206 . V_251 ) ;
return 0 ;
}
static int
F_300 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_101 ( V_21 ) || F_102 ( V_21 ) ) )
return - V_349 ;
F_99 ( & V_66 -> V_206 . V_207 ) ;
V_73 = F_27 ( & V_66 -> V_206 . V_251 ) ;
if ( V_73 )
return V_73 ;
if ( F_73 ( V_21 ) )
* V_201 = F_108 ( V_66 , V_66 -> V_206 . V_352 ) ;
else
* V_201 = V_66 -> V_206 . V_352 * V_235 ;
F_7 ( & V_66 -> V_206 . V_251 ) ;
return 0 ;
}
static int
F_301 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_220 , V_629 , V_630 ;
int V_73 ;
if ( ! ( F_101 ( V_21 ) || F_102 ( V_21 ) ) )
return - V_349 ;
F_99 ( & V_66 -> V_206 . V_207 ) ;
F_80 ( L_344 , V_201 ) ;
V_73 = F_27 ( & V_66 -> V_206 . V_251 ) ;
if ( V_73 )
return V_73 ;
if ( F_73 ( V_21 ) ) {
V_201 = F_296 ( V_66 , V_201 ) ;
V_629 = F_107 ( V_66 ) ;
V_630 = F_109 ( V_66 ) ;
} else {
F_297 ( V_201 , V_235 ) ;
V_220 = F_65 ( V_221 ) ;
V_629 = V_66 -> V_206 . V_231 ;
V_630 = ( V_220 >> 16 ) & 0xff ;
}
if ( V_201 < V_630 || V_201 > V_629 || V_201 > V_66 -> V_206 . V_353 ) {
F_7 ( & V_66 -> V_206 . V_251 ) ;
return - V_79 ;
}
V_66 -> V_206 . V_352 = V_201 ;
if ( F_73 ( V_21 ) )
F_298 ( V_21 , V_201 ) ;
else
F_299 ( V_21 , V_201 ) ;
F_7 ( & V_66 -> V_206 . V_251 ) ;
return 0 ;
}
static int
F_302 ( void * V_18 , T_8 * V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_631 ;
int V_73 ;
if ( ! ( F_101 ( V_21 ) || F_102 ( V_21 ) ) )
return - V_349 ;
V_73 = F_27 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_62 ( V_66 ) ;
V_631 = F_65 ( V_632 ) ;
F_63 ( V_66 ) ;
F_7 ( & V_66 -> V_21 -> V_74 ) ;
* V_201 = ( V_631 & V_633 ) >> V_634 ;
return 0 ;
}
static int
F_303 ( void * V_18 , T_8 V_201 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_631 ;
if ( ! ( F_101 ( V_21 ) || F_102 ( V_21 ) ) )
return - V_349 ;
if ( V_201 > 3 )
return - V_79 ;
F_62 ( V_66 ) ;
F_80 ( L_345 , V_201 ) ;
V_631 = F_65 ( V_632 ) ;
V_631 &= ~ V_633 ;
V_631 |= ( V_201 << V_634 ) ;
F_243 ( V_632 , V_631 ) ;
F_63 ( V_66 ) ;
return 0 ;
}
static int F_304 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_190 -> V_191 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_103 ( V_66 , V_232 ) ;
return 0 ;
}
static int F_305 ( struct V_190 * V_190 , struct V_106 * V_106 )
{
struct V_20 * V_21 = V_190 -> V_191 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_105 ( V_66 , V_232 ) ;
return 0 ;
}
static int F_306 ( struct V_4 * V_546 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_229 ( L_346 ,
V_635 ,
V_546 , V_21 ,
& V_636 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_636 ) ;
}
static int F_307 ( struct V_4 * V_546 ,
struct V_2 * V_3 ,
const char * V_47 ,
const struct V_637 * V_638 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_229 ( V_47 ,
V_548 | V_639 ,
V_546 , V_21 ,
V_638 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_638 ) ;
}
void F_308 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
enum V_124 V_124 ;
F_69 (pipe) {
struct V_522 * V_523 = & V_66 -> V_523 [ V_124 ] ;
V_523 -> V_525 = false ;
F_309 ( & V_523 -> V_300 ) ;
F_310 ( & V_523 -> V_540 ) ;
}
}
int F_311 ( struct V_2 * V_3 )
{
int V_73 , V_138 ;
V_73 = F_306 ( V_3 -> V_640 , V_3 ) ;
if ( V_73 )
return V_73 ;
for ( V_138 = 0 ; V_138 < F_232 ( V_547 ) ; V_138 ++ ) {
V_73 = F_228 ( V_3 -> V_640 , V_3 , V_138 ) ;
if ( V_73 )
return V_73 ;
}
for ( V_138 = 0 ; V_138 < F_232 ( V_641 ) ; V_138 ++ ) {
V_73 = F_307 ( V_3 -> V_640 , V_3 ,
V_641 [ V_138 ] . V_47 ,
V_641 [ V_138 ] . V_638 ) ;
if ( V_73 )
return V_73 ;
}
return F_312 ( V_642 ,
V_643 ,
V_3 -> V_640 , V_3 ) ;
}
void F_313 ( struct V_2 * V_3 )
{
int V_138 ;
F_314 ( V_642 ,
V_643 , V_3 ) ;
F_314 ( (struct V_644 * ) & V_636 ,
1 , V_3 ) ;
for ( V_138 = 0 ; V_138 < F_232 ( V_547 ) ; V_138 ++ ) {
struct V_644 * V_645 =
(struct V_644 * ) & V_547 [ V_138 ] ;
F_314 ( V_645 , 1 , V_3 ) ;
}
for ( V_138 = 0 ; V_138 < F_232 ( V_641 ) ; V_138 ++ ) {
struct V_644 * V_645 =
(struct V_644 * ) V_641 [ V_138 ] . V_638 ;
F_314 ( V_645 , 1 , V_3 ) ;
}
}
