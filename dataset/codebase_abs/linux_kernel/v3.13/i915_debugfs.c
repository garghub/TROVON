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
else if ( V_26 -> V_28 > 0 )
return L_6 ;
else
return L_7 ;
}
static const char * F_16 ( struct V_25 * V_26 )
{
switch ( V_26 -> V_29 ) {
default:
case V_30 : return L_7 ;
case V_31 : return L_8 ;
case V_32 : return L_9 ;
}
}
static inline const char * F_17 ( struct V_25 * V_26 )
{
return V_26 -> V_33 ? L_10 : L_7 ;
}
static void
F_18 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
struct V_34 * V_35 ;
F_10 ( V_17 , L_11 ,
& V_26 -> V_36 ,
F_15 ( V_26 ) ,
F_16 ( V_26 ) ,
F_17 ( V_26 ) ,
V_26 -> V_36 . V_37 / 1024 ,
V_26 -> V_36 . V_38 ,
V_26 -> V_36 . V_39 ,
V_26 -> V_40 ,
V_26 -> V_41 ,
V_26 -> V_42 ,
F_19 ( V_26 -> V_43 ) ,
V_26 -> V_44 ? L_12 : L_13 ,
V_26 -> V_45 == V_46 ? L_14 : L_13 ) ;
if ( V_26 -> V_36 . V_47 )
F_10 ( V_17 , L_15 , V_26 -> V_36 . V_47 ) ;
if ( V_26 -> V_28 )
F_10 ( V_17 , L_16 , V_26 -> V_28 ) ;
if ( V_26 -> V_48 )
F_10 ( V_17 , L_17 ) ;
if ( V_26 -> V_49 != V_50 )
F_10 ( V_17 , L_18 , V_26 -> V_49 ) ;
F_20 (vma, &obj->vma_list, vma_link) {
if ( ! F_21 ( V_35 -> V_51 ) )
F_22 ( V_17 , L_19 ) ;
else
F_22 ( V_17 , L_20 ) ;
F_10 ( V_17 , L_21 ,
V_35 -> V_8 . V_52 , V_35 -> V_8 . V_37 ) ;
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
static void F_23 ( struct V_16 * V_17 , struct V_59 * V_60 )
{
F_24 ( V_17 , V_60 -> V_61 ? 'I' : 'i' ) ;
F_24 ( V_17 , V_60 -> V_62 ? 'R' : 'r' ) ;
F_24 ( V_17 , ' ' ) ;
}
static int F_25 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_63 * V_64 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_68 * V_51 = & V_66 -> V_69 . V_36 ;
struct V_34 * V_35 ;
T_3 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
switch ( V_14 ) {
case V_75 :
F_22 ( V_17 , L_25 ) ;
V_64 = & V_51 -> V_76 ;
break;
case V_77 :
F_22 ( V_17 , L_26 ) ;
V_64 = & V_51 -> V_78 ;
break;
default:
F_7 ( & V_21 -> V_74 ) ;
return - V_79 ;
}
V_70 = V_71 = V_72 = 0 ;
F_20 (vma, head, mm_list) {
F_10 ( V_17 , L_27 ) ;
F_18 ( V_17 , V_35 -> V_26 ) ;
F_10 ( V_17 , L_28 ) ;
V_70 += V_35 -> V_26 -> V_36 . V_37 ;
V_71 += V_35 -> V_8 . V_37 ;
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_27 ( void * V_80 ,
struct V_63 * V_81 , struct V_63 * V_82 )
{
struct V_25 * V_83 =
F_28 ( V_81 , struct V_25 , V_84 ) ;
struct V_25 * V_85 =
F_28 ( V_82 , struct V_25 , V_84 ) ;
return V_83 -> V_53 -> V_52 - V_85 -> V_53 -> V_52 ;
}
static int F_29 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 ;
T_3 V_70 , V_71 ;
F_30 ( V_53 ) ;
int V_72 , V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_70 = V_71 = V_72 = 0 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_53 == NULL )
continue;
F_6 ( & V_26 -> V_84 , & V_53 ) ;
V_70 += V_26 -> V_36 . V_37 ;
V_71 += F_31 ( V_26 ) ;
V_72 ++ ;
}
F_20 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_26 -> V_53 == NULL )
continue;
F_6 ( & V_26 -> V_84 , & V_53 ) ;
V_70 += V_26 -> V_36 . V_37 ;
V_72 ++ ;
}
F_32 ( NULL , & V_53 , F_27 ) ;
F_22 ( V_17 , L_30 ) ;
while ( ! F_33 ( & V_53 ) ) {
V_26 = F_34 ( & V_53 , F_35 ( * V_26 ) , V_84 ) ;
F_22 ( V_17 , L_27 ) ;
F_18 ( V_17 , V_26 ) ;
F_24 ( V_17 , '\n' ) ;
F_36 ( & V_26 -> V_84 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_37 ( int V_86 , void * V_87 , void * V_18 )
{
struct V_25 * V_26 = V_87 ;
struct V_88 * V_89 = V_18 ;
V_89 -> V_72 ++ ;
V_89 -> V_90 += V_26 -> V_36 . V_37 ;
if ( F_38 ( V_26 ) ) {
if ( ! F_33 ( & V_26 -> V_91 ) )
V_89 -> V_92 += V_26 -> V_36 . V_37 ;
else
V_89 -> V_93 += V_26 -> V_36 . V_37 ;
} else {
if ( ! F_33 ( & V_26 -> V_94 ) )
V_89 -> V_95 += V_26 -> V_36 . V_37 ;
}
return 0 ;
}
static int F_39 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_72 , V_96 , V_97 ;
T_3 V_37 , V_98 , V_99 ;
struct V_25 * V_26 ;
struct V_68 * V_51 = & V_66 -> V_69 . V_36 ;
struct V_100 * V_101 ;
struct V_34 * V_35 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_31 ,
V_66 -> V_102 . V_103 ,
V_66 -> V_102 . V_104 ) ;
V_37 = V_72 = V_98 = V_96 = 0 ;
F_40 ( & V_66 -> V_102 . V_105 , V_94 ) ;
F_10 ( V_17 , L_32 ,
V_72 , V_96 , V_37 , V_98 ) ;
V_37 = V_72 = V_98 = V_96 = 0 ;
F_41 ( & V_51 -> V_76 , V_106 ) ;
F_10 ( V_17 , L_33 ,
V_72 , V_96 , V_37 , V_98 ) ;
V_37 = V_72 = V_98 = V_96 = 0 ;
F_41 ( & V_51 -> V_78 , V_106 ) ;
F_10 ( V_17 , L_34 ,
V_72 , V_96 , V_37 , V_98 ) ;
V_37 = V_72 = V_99 = V_97 = 0 ;
F_20 (obj, &dev_priv->mm.unbound_list, global_list) {
V_37 += V_26 -> V_36 . V_37 , ++ V_72 ;
if ( V_26 -> V_45 == V_46 )
V_99 += V_26 -> V_36 . V_37 , ++ V_97 ;
}
F_10 ( V_17 , L_35 , V_72 , V_37 ) ;
V_37 = V_72 = V_98 = V_96 = 0 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_26 -> V_55 ) {
V_37 += F_31 ( V_26 ) ;
++ V_72 ;
}
if ( V_26 -> V_54 ) {
V_98 += F_31 ( V_26 ) ;
++ V_96 ;
}
if ( V_26 -> V_45 == V_46 ) {
V_99 += V_26 -> V_36 . V_37 ;
++ V_97 ;
}
}
F_10 ( V_17 , L_36 ,
V_97 , V_99 ) ;
F_10 ( V_17 , L_37 ,
V_96 , V_98 ) ;
F_10 ( V_17 , L_38 ,
V_72 , V_37 ) ;
F_10 ( V_17 , L_39 ,
V_66 -> V_69 . V_36 . V_90 ,
V_66 -> V_69 . V_107 - V_66 -> V_69 . V_36 . V_52 ) ;
F_24 ( V_17 , '\n' ) ;
F_42 (file, &dev->filelist, lhead) {
struct V_88 V_89 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
F_43 ( & V_101 -> V_108 , F_37 , & V_89 ) ;
F_10 ( V_17 , L_40 ,
F_44 ( V_101 -> V_109 , V_110 ) -> V_111 ,
V_89 . V_72 ,
V_89 . V_90 ,
V_89 . V_92 ,
V_89 . V_93 ,
V_89 . V_95 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_45 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_2 V_14 = ( T_2 ) V_8 -> V_12 -> V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 ;
T_3 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_70 = V_71 = V_72 = 0 ;
F_20 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_14 == V_112 && V_26 -> V_28 == 0 )
continue;
F_22 ( V_17 , L_27 ) ;
F_18 ( V_17 , V_26 ) ;
F_24 ( V_17 , '\n' ) ;
V_70 += V_26 -> V_36 . V_37 ;
V_71 += F_31 ( V_26 ) ;
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_29 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_46 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
unsigned long V_113 ;
struct V_114 * V_115 ;
F_20 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_116 = F_47 ( V_115 -> V_116 ) ;
const char V_117 = F_48 ( V_115 -> V_117 ) ;
struct V_118 * V_119 ;
F_49 ( & V_21 -> V_120 , V_113 ) ;
V_119 = V_115 -> V_121 ;
if ( V_119 == NULL ) {
F_10 ( V_17 , L_41 ,
V_116 , V_117 ) ;
} else {
if ( F_50 ( & V_119 -> V_122 ) < V_123 ) {
F_10 ( V_17 , L_42 ,
V_116 , V_117 ) ;
} else {
F_10 ( V_17 , L_43 ,
V_116 , V_117 ) ;
}
if ( V_119 -> V_124 )
F_22 ( V_17 , L_44 ) ;
else
F_22 ( V_17 , L_45 ) ;
F_10 ( V_17 , L_46 , F_50 ( & V_119 -> V_122 ) ) ;
if ( V_119 -> V_125 ) {
struct V_25 * V_26 = V_119 -> V_125 ;
if ( V_26 )
F_10 ( V_17 , L_47 ,
F_51 ( V_26 ) ) ;
}
if ( V_119 -> V_126 ) {
struct V_25 * V_26 = V_119 -> V_126 ;
if ( V_26 )
F_10 ( V_17 , L_48 ,
F_51 ( V_26 ) ) ;
}
}
F_52 ( & V_21 -> V_120 , V_113 ) ;
}
return 0 ;
}
static int F_53 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_127 * V_58 ;
struct V_128 * V_129 ;
int V_73 , V_72 , V_130 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_72 = 0 ;
F_54 (ring, dev_priv, i) {
if ( F_33 ( & V_58 -> V_131 ) )
continue;
F_10 ( V_17 , L_49 , V_58 -> V_47 ) ;
F_20 (gem_request,
&ring->request_list,
list) {
F_10 ( V_17 , L_50 ,
V_129 -> V_132 ,
( int ) ( V_133 - V_129 -> V_134 ) ) ;
}
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
if ( V_72 == 0 )
F_22 ( V_17 , L_51 ) ;
return 0 ;
}
static void F_55 ( struct V_16 * V_17 ,
struct V_127 * V_58 )
{
if ( V_58 -> V_135 ) {
F_10 ( V_17 , L_52 ,
V_58 -> V_47 , V_58 -> V_135 ( V_58 , false ) ) ;
}
}
static int F_56 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_127 * V_58 ;
int V_73 , V_130 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_54 (ring, dev_priv, i)
F_55 ( V_17 , V_58 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_57 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_127 * V_58 ;
int V_73 , V_130 , V_116 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
int V_130 ;
F_10 ( V_17 , L_53 ,
F_58 ( V_136 ) ) ;
for ( V_130 = 0 ; V_130 < 4 ; V_130 ++ ) {
F_10 ( V_17 , L_54 ,
V_130 , F_58 ( F_59 ( V_130 ) ) ) ;
F_10 ( V_17 , L_55 ,
V_130 , F_58 ( F_60 ( V_130 ) ) ) ;
F_10 ( V_17 , L_56 ,
V_130 , F_58 ( F_61 ( V_130 ) ) ) ;
}
F_62 (i) {
F_10 ( V_17 , L_57 ,
F_47 ( V_130 ) ,
F_58 ( F_63 ( V_130 ) ) ) ;
F_10 ( V_17 , L_58 ,
F_47 ( V_130 ) ,
F_58 ( F_64 ( V_130 ) ) ) ;
F_10 ( V_17 , L_59 ,
F_47 ( V_130 ) ,
F_58 ( F_65 ( V_130 ) ) ) ;
}
F_10 ( V_17 , L_60 ,
F_58 ( V_137 ) ) ;
F_10 ( V_17 , L_61 ,
F_58 ( V_138 ) ) ;
F_10 ( V_17 , L_62 ,
F_58 ( V_139 ) ) ;
F_10 ( V_17 , L_63 ,
F_58 ( V_140 ) ) ;
F_10 ( V_17 , L_64 ,
F_58 ( V_141 ) ) ;
F_10 ( V_17 , L_65 ,
F_58 ( V_142 ) ) ;
F_10 ( V_17 , L_66 ,
F_58 ( V_143 ) ) ;
F_10 ( V_17 , L_67 ,
F_58 ( V_144 ) ) ;
F_10 ( V_17 , L_68 ,
F_58 ( V_145 ) ) ;
} else if ( F_66 ( V_21 ) ) {
F_10 ( V_17 , L_69 ,
F_58 ( V_146 ) ) ;
F_10 ( V_17 , L_70 ,
F_58 ( V_147 ) ) ;
F_10 ( V_17 , L_71 ,
F_58 ( V_148 ) ) ;
F_10 ( V_17 , L_72 ,
F_58 ( V_149 ) ) ;
F_62 (pipe)
F_10 ( V_17 , L_73 ,
F_47 ( V_116 ) ,
F_58 ( F_67 ( V_116 ) ) ) ;
F_10 ( V_17 , L_74 ,
F_58 ( V_150 ) ) ;
F_10 ( V_17 , L_75 ,
F_58 ( V_151 ) ) ;
F_10 ( V_17 , L_76 ,
F_58 ( V_152 ) ) ;
F_10 ( V_17 , L_77 ,
F_58 ( V_153 ) ) ;
F_10 ( V_17 , L_78 ,
F_58 ( V_154 ) ) ;
F_10 ( V_17 , L_79 ,
F_58 ( V_155 ) ) ;
F_10 ( V_17 , L_80 ,
F_58 ( V_156 ) ) ;
F_10 ( V_17 , L_81 ,
F_58 ( V_157 ) ) ;
F_10 ( V_17 , L_82 ,
F_58 ( V_158 ) ) ;
F_10 ( V_17 , L_83 ,
F_58 ( V_159 ) ) ;
} else if ( ! F_68 ( V_21 ) ) {
F_10 ( V_17 , L_84 ,
F_58 ( V_160 ) ) ;
F_10 ( V_17 , L_85 ,
F_58 ( V_161 ) ) ;
F_10 ( V_17 , L_86 ,
F_58 ( V_162 ) ) ;
F_62 (pipe)
F_10 ( V_17 , L_87 ,
F_47 ( V_116 ) ,
F_58 ( F_67 ( V_116 ) ) ) ;
} else {
F_10 ( V_17 , L_88 ,
F_58 ( V_163 ) ) ;
F_10 ( V_17 , L_89 ,
F_58 ( V_164 ) ) ;
F_10 ( V_17 , L_90 ,
F_58 ( V_165 ) ) ;
F_10 ( V_17 , L_91 ,
F_58 ( V_166 ) ) ;
F_10 ( V_17 , L_92 ,
F_58 ( V_167 ) ) ;
F_10 ( V_17 , L_93 ,
F_58 ( V_168 ) ) ;
F_10 ( V_17 , L_94 ,
F_58 ( V_151 ) ) ;
F_10 ( V_17 , L_95 ,
F_58 ( V_152 ) ) ;
F_10 ( V_17 , L_96 ,
F_58 ( V_153 ) ) ;
}
F_10 ( V_17 , L_97 ,
F_50 ( & V_66 -> V_169 ) ) ;
F_54 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_98 ,
V_58 -> V_47 , F_69 ( V_58 ) ) ;
}
F_55 ( V_17 , V_58 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_70 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_130 , V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_99 , V_66 -> V_170 ) ;
F_10 ( V_17 , L_100 , V_66 -> V_171 ) ;
for ( V_130 = 0 ; V_130 < V_66 -> V_171 ; V_130 ++ ) {
struct V_25 * V_26 = V_66 -> V_172 [ V_130 ] . V_26 ;
F_10 ( V_17 , L_101 ,
V_130 , V_66 -> V_172 [ V_130 ] . V_28 ) ;
if ( V_26 == NULL )
F_22 ( V_17 , L_102 ) ;
else
F_18 ( V_17 , V_26 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_71 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_127 * V_58 ;
const T_4 * V_173 ;
int V_130 ;
V_58 = & V_66 -> V_58 [ ( T_2 ) V_8 -> V_12 -> V_18 ] ;
V_173 = V_58 -> V_174 . V_175 ;
if ( V_173 == NULL )
return 0 ;
for ( V_130 = 0 ; V_130 < 4096 / sizeof( T_4 ) / 4 ; V_130 += 4 ) {
F_10 ( V_17 , L_103 ,
V_130 * 4 ,
V_173 [ V_130 ] , V_173 [ V_130 + 1 ] , V_173 [ V_130 + 2 ] , V_173 [ V_130 + 3 ] ) ;
}
return 0 ;
}
static T_6
F_72 ( struct V_101 * V_176 ,
const char T_7 * V_177 ,
T_3 V_178 ,
T_8 * V_179 )
{
struct V_180 * V_181 = V_176 -> V_182 ;
struct V_20 * V_21 = V_181 -> V_21 ;
int V_73 ;
F_73 ( L_104 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_74 ( V_21 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_178 ;
}
static int F_75 ( struct V_183 * V_183 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_183 -> V_184 ;
struct V_180 * V_181 ;
V_181 = F_76 ( sizeof( * V_181 ) , V_9 ) ;
if ( ! V_181 )
return - V_10 ;
V_181 -> V_21 = V_21 ;
F_77 ( V_21 , V_181 ) ;
V_101 -> V_182 = V_181 ;
return 0 ;
}
static int F_78 ( struct V_183 * V_183 , struct V_101 * V_101 )
{
struct V_180 * V_181 = V_101 -> V_182 ;
F_79 ( V_181 ) ;
F_80 ( V_181 ) ;
return 0 ;
}
static T_6 F_81 ( struct V_101 * V_101 , char T_7 * V_185 ,
T_3 V_72 , T_8 * V_186 )
{
struct V_180 * V_181 = V_101 -> V_182 ;
struct V_187 V_188 ;
T_8 V_189 = 0 ;
T_6 V_190 = 0 ;
int V_73 ;
V_73 = F_82 ( & V_188 , V_72 , * V_186 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_83 ( & V_188 , V_181 ) ;
if ( V_73 )
goto V_191;
V_190 = F_84 ( V_185 , V_72 , & V_189 ,
V_188 . V_192 ,
V_188 . V_193 ) ;
if ( V_190 < 0 )
V_73 = V_190 ;
else
* V_186 = V_188 . V_52 + V_190 ;
V_191:
F_85 ( & V_188 ) ;
return V_73 ? : V_190 ;
}
static int
F_86 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
* V_194 = V_66 -> V_195 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_87 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_88 ( V_21 , V_194 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int F_89 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_10 V_197 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_197 = F_90 ( V_198 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_105 , ( V_197 >> 8 ) & 0x3f , ( V_197 & 0x3f ) ) ;
return 0 ;
}
static int F_91 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_92 ( & V_66 -> V_199 . V_200 ) ;
if ( F_93 ( V_21 ) ) {
T_10 V_201 = F_90 ( V_202 ) ;
T_10 V_203 = F_90 ( V_204 ) ;
F_10 ( V_17 , L_106 , ( V_201 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_107 , V_201 & 0x3f ) ;
F_10 ( V_17 , L_108 , ( V_203 & V_205 ) >>
V_206 ) ;
F_10 ( V_17 , L_109 ,
( V_203 & V_207 ) >> V_208 ) ;
} else if ( ( F_94 ( V_21 ) || F_95 ( V_21 ) ) && ! F_66 ( V_21 ) ) {
T_4 V_209 = F_58 ( V_210 ) ;
T_4 V_211 = F_58 ( V_212 ) ;
T_4 V_213 = F_58 ( V_214 ) ;
T_4 V_215 , V_216 , V_217 ;
T_4 V_218 , V_219 , V_220 ;
T_4 V_221 , V_222 , V_223 ;
int V_224 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_96 ( V_66 ) ;
V_217 = F_58 ( V_225 ) ;
V_217 &= ~ V_226 ;
if ( F_97 ( V_21 ) )
V_217 >>= 24 ;
else
V_217 >>= 25 ;
V_217 *= V_227 ;
V_215 = F_58 ( V_228 ) ;
V_218 = F_58 ( V_229 ) ;
V_219 = F_58 ( V_230 ) ;
V_220 = F_58 ( V_231 ) ;
V_221 = F_58 ( V_232 ) ;
V_222 = F_58 ( V_233 ) ;
V_223 = F_58 ( V_234 ) ;
if ( F_97 ( V_21 ) )
V_216 = ( V_215 & V_235 ) >> V_236 ;
else
V_216 = ( V_215 & V_237 ) >> V_238 ;
V_216 *= V_227 ;
F_98 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_110 , V_209 ) ;
F_10 ( V_17 , L_111 , V_215 ) ;
F_10 ( V_17 , L_112 ,
( V_209 & 0xff00 ) >> 8 ) ;
F_10 ( V_17 , L_113 ,
V_209 & 0xff ) ;
F_10 ( V_17 , L_114 ,
V_211 & 0xff ) ;
F_10 ( V_17 , L_115 , V_217 ) ;
F_10 ( V_17 , L_116 , V_216 ) ;
F_10 ( V_17 , L_117 , V_218 &
V_239 ) ;
F_10 ( V_17 , L_118 , V_219 &
V_240 ) ;
F_10 ( V_17 , L_119 , V_220 &
V_240 ) ;
F_10 ( V_17 , L_120 , V_221 &
V_241 ) ;
F_10 ( V_17 , L_121 , V_222 &
V_240 ) ;
F_10 ( V_17 , L_122 , V_223 &
V_240 ) ;
V_224 = ( V_213 & 0xff0000 ) >> 16 ;
F_10 ( V_17 , L_123 ,
V_224 * V_227 ) ;
V_224 = ( V_213 & 0xff00 ) >> 8 ;
F_10 ( V_17 , L_124 ,
V_224 * V_227 ) ;
V_224 = V_213 & 0xff ;
F_10 ( V_17 , L_125 ,
V_224 * V_227 ) ;
F_10 ( V_17 , L_126 ,
V_66 -> V_199 . V_242 * V_227 ) ;
} else if ( F_66 ( V_21 ) ) {
T_4 V_243 , V_194 ;
F_5 ( & V_66 -> V_199 . V_244 ) ;
V_243 = F_99 ( V_66 , V_245 ) ;
F_10 ( V_17 , L_127 , V_243 ) ;
F_10 ( V_17 , L_128 , V_66 -> V_246 ) ;
V_194 = F_99 ( V_66 , V_247 ) ;
F_10 ( V_17 , L_129 ,
F_100 ( V_66 -> V_246 , V_194 ) ) ;
V_194 = F_99 ( V_66 , V_248 ) ;
F_10 ( V_17 , L_130 ,
F_100 ( V_66 -> V_246 , V_194 ) ) ;
F_10 ( V_17 , L_131 ,
F_100 ( V_66 -> V_246 ,
( V_243 >> 8 ) & 0xff ) ) ;
F_7 ( & V_66 -> V_199 . V_244 ) ;
} else {
F_22 ( V_17 , L_132 ) ;
}
return 0 ;
}
static int F_101 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_249 ;
int V_73 , V_130 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
for ( V_130 = 0 ; V_130 < 16 ; V_130 ++ ) {
V_249 = F_58 ( V_250 + V_130 * 4 ) ;
F_10 ( V_17 , L_133 , V_130 , V_249 ,
( V_249 & V_251 ) >> V_252 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static inline int F_102 ( int V_253 )
{
return 1250 - ( V_253 * 25 ) ;
}
static int F_103 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_254 ;
int V_73 , V_130 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
for ( V_130 = 1 ; V_130 <= 32 ; V_130 ++ ) {
V_254 = F_58 ( V_255 + V_130 * 4 ) ;
F_10 ( V_17 , L_134 , V_130 , V_254 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_104 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_256 , V_257 ;
T_10 V_258 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_256 = F_58 ( V_259 ) ;
V_257 = F_58 ( V_260 ) ;
V_258 = F_90 ( V_198 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_135 , ( V_256 & V_261 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_136 ,
( V_256 & V_262 ) >>
V_263 ) ;
F_10 ( V_17 , L_137 ,
V_256 & V_264 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_138 ,
V_256 & V_265 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_139 ,
V_256 & V_266 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_140 ,
( V_256 & V_267 ) >> V_268 ) ;
F_10 ( V_17 , L_141 ,
( V_256 & V_269 ) >> V_270 ) ;
F_10 ( V_17 , L_142 , ( V_256 & V_271 ) ) ;
F_10 ( V_17 , L_143 , ( V_258 & 0x3f ) ) ;
F_10 ( V_17 , L_144 , ( ( V_258 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_145 ,
( V_257 & V_272 ) ? L_2 : L_1 ) ;
F_22 ( V_17 , L_146 ) ;
switch ( V_257 & V_273 ) {
case V_274 :
F_22 ( V_17 , L_147 ) ;
break;
case V_275 :
F_22 ( V_17 , L_148 ) ;
break;
case V_276 :
F_22 ( V_17 , L_149 ) ;
break;
case V_277 :
F_22 ( V_17 , L_150 ) ;
break;
case V_278 :
F_22 ( V_17 , L_151 ) ;
break;
case V_279 :
F_22 ( V_17 , L_152 ) ;
break;
default:
F_22 ( V_17 , L_153 ) ;
break;
}
return 0 ;
}
static int F_105 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_280 , V_281 , V_282 , V_283 = 0 ;
unsigned V_284 ;
int V_72 = 0 , V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_106 ( & V_66 -> V_285 . V_286 ) ;
V_284 = V_66 -> V_285 . V_284 ;
F_107 ( & V_66 -> V_285 . V_286 ) ;
if ( V_284 ) {
F_22 ( V_17 , L_154
L_155 ) ;
} else {
while ( V_72 ++ < 50 && ( F_108 ( V_287 ) & 1 ) )
F_109 ( 10 ) ;
F_10 ( V_17 , L_156 , F_1 ( V_72 < 51 ) ) ;
}
V_281 = F_110 ( V_66 -> V_288 + V_289 ) ;
F_111 ( false , V_289 , V_281 , 4 , true ) ;
V_280 = F_58 ( V_290 ) ;
V_282 = F_58 ( V_291 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_5 ( & V_66 -> V_199 . V_244 ) ;
F_112 ( V_66 , V_292 , & V_283 ) ;
F_7 ( & V_66 -> V_199 . V_244 ) ;
F_10 ( V_17 , L_157 ,
F_1 ( V_280 & V_293 ) ) ;
F_10 ( V_17 , L_137 ,
F_1 ( V_280 & V_294 ) ) ;
F_10 ( V_17 , L_138 ,
F_1 ( ( V_280 & V_295 ) ==
V_296 ) ) ;
F_10 ( V_17 , L_158 ,
F_1 ( V_282 & V_297 ) ) ;
F_10 ( V_17 , L_159 ,
F_1 ( V_282 & V_298 ) ) ;
F_10 ( V_17 , L_160 ,
F_1 ( V_282 & V_299 ) ) ;
F_10 ( V_17 , L_161 ,
F_1 ( V_282 & V_300 ) ) ;
F_22 ( V_17 , L_162 ) ;
switch ( V_281 & V_301 ) {
case V_302 :
if ( V_281 & V_303 )
F_22 ( V_17 , L_163 ) ;
else
F_22 ( V_17 , L_147 ) ;
break;
case V_304 :
F_22 ( V_17 , L_164 ) ;
break;
case V_305 :
F_22 ( V_17 , L_165 ) ;
break;
case V_306 :
F_22 ( V_17 , L_166 ) ;
break;
default:
F_22 ( V_17 , L_167 ) ;
break;
}
F_10 ( V_17 , L_168 ,
F_1 ( V_281 & V_303 ) ) ;
F_10 ( V_17 , L_169 ,
F_58 ( V_307 ) ) ;
F_10 ( V_17 , L_170 ,
F_58 ( V_308 ) ) ;
F_10 ( V_17 , L_171 ,
F_58 ( V_309 ) ) ;
F_10 ( V_17 , L_172 ,
F_58 ( V_310 ) ) ;
F_10 ( V_17 , L_173 ,
F_113 ( ( ( V_283 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_174 ,
F_113 ( ( ( V_283 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_175 ,
F_113 ( ( ( V_283 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_114 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_94 ( V_21 ) || F_95 ( V_21 ) )
return F_105 ( V_17 ) ;
else
return F_104 ( V_17 ) ;
}
static int F_115 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
if ( ! F_116 ( V_21 ) ) {
F_22 ( V_17 , L_176 ) ;
return 0 ;
}
if ( F_117 ( V_21 ) ) {
F_22 ( V_17 , L_177 ) ;
} else {
F_22 ( V_17 , L_178 ) ;
switch ( V_66 -> V_311 . V_312 ) {
case V_313 :
F_22 ( V_17 , L_179 ) ;
break;
case V_314 :
F_22 ( V_17 , L_180 ) ;
break;
case V_315 :
F_22 ( V_17 , L_181 ) ;
break;
case V_316 :
F_22 ( V_17 , L_182 ) ;
break;
case V_317 :
F_22 ( V_17 , L_183 ) ;
break;
case V_318 :
F_22 ( V_17 , L_184 ) ;
break;
case V_319 :
F_22 ( V_17 , L_185 ) ;
break;
case V_320 :
F_22 ( V_17 , L_186 ) ;
break;
case V_321 :
F_22 ( V_17 , L_187 ) ;
break;
case V_322 :
F_22 ( V_17 , L_188 ) ;
break;
case V_323 :
F_22 ( V_17 , L_189 ) ;
break;
default:
F_22 ( V_17 , L_190 ) ;
}
F_24 ( V_17 , '\n' ) ;
}
return 0 ;
}
static int F_118 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_119 ( V_21 ) ) {
F_22 ( V_17 , L_191 ) ;
return 0 ;
}
if ( F_58 ( V_324 ) & V_325 )
F_22 ( V_17 , L_192 ) ;
else
F_22 ( V_17 , L_193 ) ;
return 0 ;
}
static int F_120 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
bool V_326 = false ;
if ( F_68 ( V_21 ) )
V_326 = F_58 ( V_327 ) & V_328 ;
else if ( F_121 ( V_21 ) || F_122 ( V_21 ) || F_123 ( V_21 ) )
V_326 = F_58 ( V_329 ) & V_330 ;
else if ( F_124 ( V_21 ) )
V_326 = F_58 ( V_331 ) & V_332 ;
else if ( F_125 ( V_21 ) )
V_326 = F_58 ( V_333 ) & V_334 ;
F_10 ( V_17 , L_194 ,
V_326 ? L_195 : L_196 ) ;
return 0 ;
}
static int F_126 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
unsigned long V_335 , V_336 , V_337 ;
int V_73 ;
if ( ! F_93 ( V_21 ) )
return - V_338 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_335 = F_127 ( V_66 ) ;
V_336 = F_128 ( V_66 ) ;
V_337 = F_129 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_197 , V_335 ) ;
F_10 ( V_17 , L_198 , V_336 ) ;
F_10 ( V_17 , L_199 , V_337 ) ;
F_10 ( V_17 , L_200 , V_336 + V_337 ) ;
return 0 ;
}
static int F_130 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
int V_339 , V_340 ;
if ( ! ( F_94 ( V_21 ) || F_95 ( V_21 ) ) ) {
F_22 ( V_17 , L_201 ) ;
return 0 ;
}
F_92 ( & V_66 -> V_199 . V_200 ) ;
V_73 = F_26 ( & V_66 -> V_199 . V_244 ) ;
if ( V_73 )
return V_73 ;
F_22 ( V_17 , L_202 ) ;
for ( V_339 = V_66 -> V_199 . V_341 ;
V_339 <= V_66 -> V_199 . V_342 ;
V_339 ++ ) {
V_340 = V_339 ;
F_112 ( V_66 ,
V_343 ,
& V_340 ) ;
F_10 ( V_17 , L_203 ,
V_339 * V_227 ,
( ( V_340 >> 0 ) & 0xff ) * 100 ,
( ( V_340 >> 8 ) & 0xff ) * 100 ) ;
}
F_7 ( & V_66 -> V_199 . V_244 ) ;
return 0 ;
}
static int F_131 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_204 , ( unsigned long ) F_58 ( 0x112f4 ) ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_132 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_344 * V_345 = & V_66 -> V_345 ;
void * V_18 = F_3 ( V_346 , V_9 ) ;
int V_73 ;
if ( V_18 == NULL )
return - V_10 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_191;
if ( V_345 -> V_347 ) {
F_133 ( V_18 , V_345 -> V_347 , V_346 ) ;
F_134 ( V_17 , V_18 , V_346 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
V_191:
F_80 ( V_18 ) ;
return 0 ;
}
static int F_135 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_348 * V_349 = NULL ;
struct V_350 * V_351 ;
#ifdef F_136
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_26 ( & V_21 -> V_352 . V_353 ) ;
if ( V_73 )
return V_73 ;
V_349 = V_66 -> V_354 ;
V_351 = F_137 ( V_349 -> V_355 . V_351 ) ;
F_10 ( V_17 , L_205 ,
V_351 -> V_36 . V_356 ,
V_351 -> V_36 . V_357 ,
V_351 -> V_36 . V_358 ,
V_351 -> V_36 . V_359 ,
F_50 ( & V_351 -> V_36 . V_360 . V_360 ) ) ;
F_18 ( V_17 , V_351 -> V_26 ) ;
F_24 ( V_17 , '\n' ) ;
F_7 ( & V_21 -> V_352 . V_353 ) ;
#endif
F_5 ( & V_21 -> V_352 . V_361 ) ;
F_20 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_349 && & V_351 -> V_36 == V_349 -> V_355 . V_351 )
continue;
F_10 ( V_17 , L_206 ,
V_351 -> V_36 . V_356 ,
V_351 -> V_36 . V_357 ,
V_351 -> V_36 . V_358 ,
V_351 -> V_36 . V_359 ,
F_50 ( & V_351 -> V_36 . V_360 . V_360 ) ) ;
F_18 ( V_17 , V_351 -> V_26 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_352 . V_361 ) ;
return 0 ;
}
static int F_138 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_127 * V_58 ;
struct V_59 * V_60 ;
int V_73 , V_130 ;
V_73 = F_26 ( & V_21 -> V_352 . V_353 ) ;
if ( V_73 )
return V_73 ;
if ( V_66 -> V_362 . V_363 ) {
F_22 ( V_17 , L_207 ) ;
F_18 ( V_17 , V_66 -> V_362 . V_363 ) ;
F_24 ( V_17 , '\n' ) ;
}
if ( V_66 -> V_362 . V_364 ) {
F_22 ( V_17 , L_208 ) ;
F_18 ( V_17 , V_66 -> V_362 . V_364 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_20 (ctx, &dev_priv->context_list, link) {
F_22 ( V_17 , L_209 ) ;
F_23 ( V_17 , V_60 ) ;
F_54 (ring, dev_priv, i)
if ( V_58 -> V_365 == V_60 )
F_10 ( V_17 , L_210 , V_58 -> V_47 ) ;
F_18 ( V_17 , V_60 -> V_26 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_352 . V_353 ) ;
return 0 ;
}
static int F_139 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned V_284 ;
F_106 ( & V_66 -> V_285 . V_286 ) ;
V_284 = V_66 -> V_285 . V_284 ;
F_107 ( & V_66 -> V_285 . V_286 ) ;
F_10 ( V_17 , L_211 , V_284 ) ;
return 0 ;
}
static const char * F_140 ( unsigned V_366 )
{
switch ( V_366 ) {
case V_367 :
return L_212 ;
case V_368 :
return L_213 ;
case V_369 :
return L_214 ;
case V_370 :
return L_215 ;
case V_371 :
return L_216 ;
case V_372 :
return L_217 ;
case V_373 :
return L_218 ;
case V_374 :
return L_219 ;
}
return L_220 ;
}
static int F_141 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_221 ,
F_140 ( V_66 -> V_102 . V_375 ) ) ;
F_10 ( V_17 , L_222 ,
F_140 ( V_66 -> V_102 . V_376 ) ) ;
if ( F_142 ( V_21 ) || F_143 ( V_21 ) ) {
F_10 ( V_17 , L_223 ,
F_58 ( V_377 ) ) ;
F_10 ( V_17 , L_224 ,
F_90 ( V_378 ) ) ;
F_10 ( V_17 , L_225 ,
F_90 ( V_379 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_226 ,
F_58 ( V_380 ) ) ;
F_10 ( V_17 , L_227 ,
F_58 ( V_381 ) ) ;
F_10 ( V_17 , L_228 ,
F_58 ( V_382 ) ) ;
F_10 ( V_17 , L_229 ,
F_58 ( V_383 ) ) ;
if ( F_144 ( V_21 ) )
F_10 ( V_17 , L_230 ,
F_58 ( V_384 ) ) ;
else
F_10 ( V_17 , L_231 ,
F_58 ( V_385 ) ) ;
F_10 ( V_17 , L_232 ,
F_58 ( V_386 ) ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static void F_145 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_127 * V_58 ;
struct V_387 * V_388 = V_66 -> V_102 . V_389 ;
int V_196 , V_130 ;
if ( ! V_388 )
return;
F_10 ( V_17 , L_233 , V_388 -> V_390 ) ;
F_10 ( V_17 , L_234 , V_388 -> V_391 ) ;
F_54 (ring, dev_priv, unused) {
F_10 ( V_17 , L_235 , V_58 -> V_47 ) ;
for ( V_130 = 0 ; V_130 < 4 ; V_130 ++ ) {
T_4 V_392 = 0x270 + V_130 * 8 ;
T_9 V_393 = F_58 ( V_58 -> V_394 + V_392 + 4 ) ;
V_393 <<= 32 ;
V_393 |= F_58 ( V_58 -> V_394 + V_392 ) ;
for ( V_130 = 0 ; V_130 < 4 ; V_130 ++ )
F_10 ( V_17 , L_236 , V_130 , V_393 ) ;
}
}
}
static void F_146 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_127 * V_58 ;
int V_130 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_237 , F_58 ( V_395 ) ) ;
F_54 (ring, dev_priv, i) {
F_10 ( V_17 , L_235 , V_58 -> V_47 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_237 , F_58 ( F_147 ( V_58 ) ) ) ;
F_10 ( V_17 , L_238 , F_58 ( F_148 ( V_58 ) ) ) ;
F_10 ( V_17 , L_239 , F_58 ( F_149 ( V_58 ) ) ) ;
F_10 ( V_17 , L_240 , F_58 ( F_150 ( V_58 ) ) ) ;
}
if ( V_66 -> V_102 . V_389 ) {
struct V_387 * V_388 = V_66 -> V_102 . V_389 ;
F_22 ( V_17 , L_241 ) ;
F_10 ( V_17 , L_242 , V_388 -> V_396 ) ;
}
F_10 ( V_17 , L_243 , F_58 ( V_397 ) ) ;
}
static int F_151 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
int V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_145 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_146 ( V_17 , V_21 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_152 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! F_66 ( V_21 ) ) {
F_22 ( V_17 , L_244 ) ;
return 0 ;
}
V_73 = F_26 ( & V_66 -> V_398 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_245 , F_58 ( V_399 ) ) ;
F_10 ( V_17 , L_246 ,
F_153 ( V_66 , V_400 , V_401 ) ) ;
F_10 ( V_17 , L_247 ,
F_153 ( V_66 , V_400 , V_402 ) ) ;
F_10 ( V_17 , L_248 ,
F_153 ( V_66 , V_400 , V_403 ) ) ;
F_10 ( V_17 , L_249 ,
F_153 ( V_66 , V_400 , V_404 ) ) ;
F_10 ( V_17 , L_250 ,
F_153 ( V_66 , V_400 , V_405 ) ) ;
F_10 ( V_17 , L_251 ,
F_153 ( V_66 , V_400 , V_406 ) ) ;
F_10 ( V_17 , L_252 ,
F_153 ( V_66 , V_400 , V_407 ) ) ;
F_10 ( V_17 , L_253 ,
F_153 ( V_66 , V_400 , V_408 ) ) ;
F_10 ( V_17 , L_254 ,
F_153 ( V_66 , V_400 , V_409 ) ) ;
F_7 ( & V_66 -> V_398 ) ;
return 0 ;
}
static int F_154 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
F_10 ( V_17 , L_255 , F_1 ( F_155 ( V_21 ) ) ) ;
F_10 ( V_17 , L_256 , V_66 -> V_410 ) ;
return 0 ;
}
static int F_156 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_411 = 0 ;
bool V_412 = false ;
F_10 ( V_17 , L_257 , F_1 ( V_66 -> V_413 . V_414 ) ) ;
F_10 ( V_17 , L_258 , F_1 ( V_66 -> V_413 . V_415 ) ) ;
V_412 = F_157 ( V_21 ) &&
F_58 ( F_158 ( V_21 ) ) & V_416 ;
F_10 ( V_17 , L_259 , F_1 ( V_412 ) ) ;
if ( F_157 ( V_21 ) )
V_411 = F_58 ( F_159 ( V_21 ) ) &
V_417 ;
F_10 ( V_17 , L_260 , V_411 ) ;
return 0 ;
}
static int F_160 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_9 V_418 ;
T_4 V_419 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_338 ;
F_161 ( V_420 , V_418 ) ;
V_418 = ( V_418 & 0x1f00 ) >> 8 ;
V_419 = 1000000 / ( 1 << V_418 ) ;
V_418 = F_58 ( V_421 ) ;
V_418 *= V_419 ;
F_10 ( V_17 , L_261 , ( long long unsigned ) V_418 ) ;
return 0 ;
}
static int F_162 ( struct V_16 * V_17 , void * V_196 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_97 ( V_21 ) ) {
F_22 ( V_17 , L_191 ) ;
return 0 ;
}
F_5 ( & V_66 -> V_422 . V_286 ) ;
F_10 ( V_17 , L_262 ,
F_1 ( V_66 -> V_422 . V_423 ) ) ;
F_10 ( V_17 , L_263 , F_1 ( V_66 -> V_422 . V_424 ) ) ;
F_10 ( V_17 , L_264 , V_66 -> V_422 . V_425 ) ;
F_10 ( V_17 , L_265 ,
F_1 ( V_66 -> V_422 . V_426 ) ) ;
F_10 ( V_17 , L_259 , F_1 ( V_66 -> V_422 . V_412 ) ) ;
F_7 ( & V_66 -> V_422 . V_286 ) ;
return 0 ;
}
static int F_163 ( struct V_183 * V_183 , struct V_101 * V_427 )
{
struct V_428 * V_23 = V_183 -> V_184 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_429 * V_430 = & V_66 -> V_430 [ V_23 -> V_116 ] ;
F_106 ( & V_430 -> V_286 ) ;
if ( V_430 -> V_431 ) {
F_107 ( & V_430 -> V_286 ) ;
return - V_432 ;
}
V_430 -> V_431 = true ;
V_427 -> V_182 = V_183 -> V_184 ;
F_107 ( & V_430 -> V_286 ) ;
return 0 ;
}
static int F_164 ( struct V_183 * V_183 , struct V_101 * V_427 )
{
struct V_428 * V_23 = V_183 -> V_184 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_429 * V_430 = & V_66 -> V_430 [ V_23 -> V_116 ] ;
F_106 ( & V_430 -> V_286 ) ;
V_430 -> V_431 = false ;
F_107 ( & V_430 -> V_286 ) ;
return 0 ;
}
static int F_165 ( struct V_429 * V_430 )
{
F_166 ( & V_430 -> V_286 ) ;
return F_167 ( V_430 -> V_64 , V_430 -> V_433 ,
V_434 ) ;
}
static T_6
F_168 ( struct V_101 * V_427 , char T_7 * V_435 , T_3 V_72 ,
T_8 * V_186 )
{
struct V_428 * V_23 = V_427 -> V_182 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_429 * V_430 = & V_66 -> V_430 [ V_23 -> V_116 ] ;
char V_192 [ V_436 ] ;
int V_64 , V_433 , V_437 , V_438 ;
T_6 V_439 ;
if ( V_72 < V_440 )
return - V_79 ;
if ( V_430 -> V_441 == V_442 )
return 0 ;
F_106 ( & V_430 -> V_286 ) ;
while ( F_165 ( V_430 ) == 0 ) {
int V_73 ;
if ( V_427 -> V_443 & V_444 ) {
F_107 ( & V_430 -> V_286 ) ;
return - V_445 ;
}
V_73 = F_169 ( V_430 -> V_446 ,
F_165 ( V_430 ) , V_430 -> V_286 ) ;
if ( V_73 ) {
F_107 ( & V_430 -> V_286 ) ;
return V_73 ;
}
}
V_64 = V_430 -> V_64 ;
V_433 = V_430 -> V_433 ;
V_437 = F_170 ( ( T_3 ) F_167 ( V_64 , V_433 , V_434 ) ,
V_72 / V_440 ) ;
F_107 ( & V_430 -> V_286 ) ;
V_439 = 0 ;
V_438 = 0 ;
do {
struct V_447 * V_448 = & V_430 -> V_449 [ V_433 ] ;
int V_73 ;
V_439 += snprintf ( V_192 , V_436 ,
L_266 ,
V_448 -> V_450 , V_448 -> V_451 [ 0 ] ,
V_448 -> V_451 [ 1 ] , V_448 -> V_451 [ 2 ] ,
V_448 -> V_451 [ 3 ] , V_448 -> V_451 [ 4 ] ) ;
V_73 = F_171 ( V_435 + V_438 * V_440 ,
V_192 , V_440 ) ;
if ( V_73 == V_440 )
return - V_452 ;
F_172 ( V_434 ) ;
V_433 = ( V_433 + 1 ) & ( V_434 - 1 ) ;
V_438 ++ ;
} while ( -- V_437 );
F_106 ( & V_430 -> V_286 ) ;
V_430 -> V_433 = V_433 ;
F_107 ( & V_430 -> V_286 ) ;
return V_439 ;
}
static int F_173 ( struct V_4 * V_453 , struct V_2 * V_3 ,
enum V_116 V_116 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_428 * V_23 = & V_454 [ V_116 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_174 ( V_23 -> V_47 , V_455 , V_453 , V_23 ,
& V_456 ) ;
if ( F_175 ( V_5 ) )
return F_176 ( V_5 ) ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_177 ( enum V_457 V_441 )
{
F_178 ( F_179 ( V_458 ) != V_459 ) ;
return V_458 [ V_441 ] ;
}
static int F_180 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_130 ;
for ( V_130 = 0 ; V_130 < V_460 ; V_130 ++ )
F_10 ( V_17 , L_267 , F_47 ( V_130 ) ,
F_177 ( V_66 -> V_430 [ V_130 ] . V_441 ) ) ;
return 0 ;
}
static int F_181 ( struct V_183 * V_183 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_183 -> V_184 ;
return F_182 ( V_101 , F_180 , V_21 ) ;
}
static int F_183 ( enum V_457 * V_441 ,
T_11 * V_194 )
{
if ( * V_441 == V_461 )
* V_441 = V_462 ;
switch ( * V_441 ) {
case V_462 :
* V_194 = V_463 | V_464 ;
break;
case V_442 :
* V_194 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_184 ( struct V_20 * V_21 , enum V_116 V_116 ,
enum V_457 * V_441 )
{
struct V_465 * V_466 ;
struct V_114 * V_115 ;
struct V_467 * V_468 ;
int V_73 = 0 ;
* V_441 = V_462 ;
F_5 ( & V_21 -> V_352 . V_353 ) ;
F_20 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_466 -> V_36 . V_115 )
continue;
V_115 = F_185 ( V_466 -> V_36 . V_115 ) ;
if ( V_115 -> V_116 != V_116 )
continue;
switch ( V_466 -> type ) {
case V_469 :
* V_441 = V_470 ;
break;
case V_471 :
case V_472 :
V_468 = F_186 ( & V_466 -> V_36 ) ;
switch ( V_468 -> V_473 ) {
case V_474 :
* V_441 = V_475 ;
break;
case V_476 :
* V_441 = V_477 ;
break;
case V_478 :
* V_441 = V_479 ;
break;
default:
F_187 ( 1 , L_268 ,
F_188 ( V_468 -> V_473 ) ) ;
break;
}
break;
}
}
F_7 ( & V_21 -> V_352 . V_353 ) ;
return V_73 ;
}
static int F_189 ( struct V_20 * V_21 ,
enum V_116 V_116 ,
enum V_457 * V_441 ,
T_11 * V_194 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_480 = false ;
if ( * V_441 == V_461 ) {
int V_73 = F_184 ( V_21 , V_116 , V_441 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_441 ) {
case V_462 :
* V_194 = V_463 | V_481 ;
break;
case V_475 :
* V_194 = V_463 | V_482 ;
V_480 = true ;
break;
case V_477 :
* V_194 = V_463 | V_483 ;
V_480 = true ;
break;
case V_442 :
* V_194 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_480 ) {
T_11 V_484 = F_58 ( V_485 ) ;
F_190 ( ! F_191 ( V_21 ) ) ;
V_484 |= V_486 ;
if ( V_116 == V_400 )
V_484 |= V_487 ;
else
V_484 |= V_488 ;
F_192 ( V_485 , V_484 ) ;
}
return 0 ;
}
static int F_193 ( struct V_20 * V_21 ,
enum V_116 V_116 ,
enum V_457 * V_441 ,
T_11 * V_194 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_480 = false ;
if ( * V_441 == V_461 ) {
int V_73 = F_184 ( V_21 , V_116 , V_441 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_441 ) {
case V_462 :
* V_194 = V_463 | V_489 ;
break;
case V_470 :
if ( ! F_194 ( V_21 ) )
return - V_79 ;
* V_194 = V_463 | V_490 ;
break;
case V_475 :
if ( ! F_191 ( V_21 ) )
return - V_79 ;
* V_194 = V_463 | V_491 ;
V_480 = true ;
break;
case V_477 :
if ( ! F_191 ( V_21 ) )
return - V_79 ;
* V_194 = V_463 | V_492 ;
V_480 = true ;
break;
case V_479 :
if ( ! F_191 ( V_21 ) )
return - V_79 ;
* V_194 = V_463 | V_493 ;
V_480 = true ;
break;
case V_442 :
* V_194 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_480 ) {
T_11 V_484 = F_58 ( V_485 ) ;
F_190 ( ! F_191 ( V_21 ) ) ;
F_192 ( V_494 ,
F_58 ( V_494 ) | V_495 ) ;
if ( V_116 == V_400 )
V_484 |= V_487 ;
else
V_484 |= V_488 ;
F_192 ( V_485 , V_484 ) ;
}
return 0 ;
}
static void F_195 ( struct V_20 * V_21 ,
enum V_116 V_116 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_484 = F_58 ( V_485 ) ;
if ( V_116 == V_400 )
V_484 &= ~ V_487 ;
else
V_484 &= ~ V_488 ;
if ( ! ( V_484 & V_496 ) )
V_484 &= ~ V_486 ;
F_192 ( V_485 , V_484 ) ;
}
static void F_196 ( struct V_20 * V_21 ,
enum V_116 V_116 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_484 = F_58 ( V_485 ) ;
if ( V_116 == V_400 )
V_484 &= ~ V_487 ;
else
V_484 &= ~ V_488 ;
F_192 ( V_485 , V_484 ) ;
if ( ! ( V_484 & V_496 ) ) {
F_192 ( V_494 ,
F_58 ( V_494 ) & ~ V_495 ) ;
}
}
static int F_197 ( enum V_457 * V_441 ,
T_11 * V_194 )
{
if ( * V_441 == V_461 )
* V_441 = V_462 ;
switch ( * V_441 ) {
case V_497 :
* V_194 = V_463 | V_498 ;
break;
case V_499 :
* V_194 = V_463 | V_500 ;
break;
case V_462 :
* V_194 = V_463 | V_501 ;
break;
case V_442 :
* V_194 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_198 ( enum V_457 * V_441 ,
T_11 * V_194 )
{
if ( * V_441 == V_461 )
* V_441 = V_502 ;
switch ( * V_441 ) {
case V_497 :
* V_194 = V_463 | V_503 ;
break;
case V_499 :
* V_194 = V_463 | V_504 ;
break;
case V_502 :
* V_194 = V_463 | V_505 ;
break;
case V_442 :
* V_194 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_199 ( struct V_20 * V_21 , enum V_116 V_116 ,
enum V_457 V_441 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_429 * V_430 = & V_66 -> V_430 [ V_116 ] ;
T_4 V_194 ;
int V_73 ;
if ( V_430 -> V_441 == V_441 )
return 0 ;
if ( V_430 -> V_441 && V_441 )
return - V_79 ;
if ( F_200 ( V_21 ) )
V_73 = F_183 ( & V_441 , & V_194 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_73 = F_193 ( V_21 , V_116 , & V_441 , & V_194 ) ;
else if ( F_66 ( V_21 ) )
V_73 = F_189 ( V_21 , V_116 , & V_441 , & V_194 ) ;
else if ( F_93 ( V_21 ) || F_94 ( V_21 ) )
V_73 = F_197 ( & V_441 , & V_194 ) ;
else
V_73 = F_198 ( & V_441 , & V_194 ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_441 ) {
F_73 ( L_269 ,
F_47 ( V_116 ) , F_177 ( V_441 ) ) ;
V_430 -> V_449 = F_76 ( sizeof( * V_430 -> V_449 ) *
V_434 ,
V_9 ) ;
if ( ! V_430 -> V_449 )
return - V_10 ;
F_106 ( & V_430 -> V_286 ) ;
V_430 -> V_64 = 0 ;
V_430 -> V_433 = 0 ;
F_107 ( & V_430 -> V_286 ) ;
}
V_430 -> V_441 = V_441 ;
F_192 ( F_201 ( V_116 ) , V_194 ) ;
F_202 ( F_201 ( V_116 ) ) ;
if ( V_441 == V_442 ) {
struct V_447 * V_449 ;
F_73 ( L_270 ,
F_47 ( V_116 ) ) ;
F_203 ( V_21 , V_116 ) ;
F_106 ( & V_430 -> V_286 ) ;
V_449 = V_430 -> V_449 ;
V_430 -> V_449 = NULL ;
F_107 ( & V_430 -> V_286 ) ;
F_80 ( V_449 ) ;
if ( F_191 ( V_21 ) )
F_196 ( V_21 , V_116 ) ;
else if ( F_66 ( V_21 ) )
F_195 ( V_21 , V_116 ) ;
}
return 0 ;
}
static int F_204 ( char * V_192 , char * V_506 [] , int V_507 )
{
int V_508 = 0 ;
while ( * V_192 ) {
char * V_509 ;
V_192 = F_205 ( V_192 ) ;
if ( ! * V_192 )
break;
for ( V_509 = V_192 ; * V_509 && ! isspace ( * V_509 ) ; V_509 ++ )
;
if ( V_508 == V_507 ) {
F_73 ( L_271 ,
V_507 ) ;
return - V_79 ;
}
if ( * V_509 )
* V_509 ++ = '\0' ;
V_506 [ V_508 ++ ] = V_192 ;
V_192 = V_509 ;
}
return V_508 ;
}
static int
F_206 ( const char * V_192 , enum V_510 * V_511 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < F_179 ( V_512 ) ; V_130 ++ )
if ( ! strcmp ( V_192 , V_512 [ V_130 ] ) ) {
* V_511 = V_130 ;
return 0 ;
}
return - V_79 ;
}
static int F_207 ( const char * V_192 , enum V_116 * V_116 )
{
const char V_47 = V_192 [ 0 ] ;
if ( V_47 < 'A' || V_47 >= F_47 ( V_460 ) )
return - V_79 ;
* V_116 = V_47 - 'A' ;
return 0 ;
}
static int
F_208 ( const char * V_192 , enum V_457 * V_56 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < F_179 ( V_458 ) ; V_130 ++ )
if ( ! strcmp ( V_192 , V_458 [ V_130 ] ) ) {
* V_56 = V_130 ;
return 0 ;
}
return - V_79 ;
}
static int F_209 ( struct V_20 * V_21 , char * V_192 , T_3 V_513 )
{
#define F_210 3
int V_508 ;
char * V_506 [ F_210 ] ;
enum V_116 V_116 ;
enum V_510 V_514 ;
enum V_457 V_441 ;
V_508 = F_204 ( V_192 , V_506 , F_210 ) ;
if ( V_508 != F_210 ) {
F_73 ( L_272 ,
F_210 ) ;
return - V_79 ;
}
if ( F_206 ( V_506 [ 0 ] , & V_514 ) < 0 ) {
F_73 ( L_273 , V_506 [ 0 ] ) ;
return - V_79 ;
}
if ( F_207 ( V_506 [ 1 ] , & V_116 ) < 0 ) {
F_73 ( L_274 , V_506 [ 1 ] ) ;
return - V_79 ;
}
if ( F_208 ( V_506 [ 2 ] , & V_441 ) < 0 ) {
F_73 ( L_275 , V_506 [ 2 ] ) ;
return - V_79 ;
}
return F_199 ( V_21 , V_116 , V_441 ) ;
}
static T_6 F_211 ( struct V_101 * V_101 , const char T_7 * V_177 ,
T_3 V_513 , T_8 * V_515 )
{
struct V_16 * V_17 = V_101 -> V_182 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_516 ;
int V_73 ;
if ( V_513 == 0 )
return 0 ;
if ( V_513 > V_517 - 1 ) {
F_73 ( L_276 ,
V_517 ) ;
return - V_518 ;
}
V_516 = F_3 ( V_513 + 1 , V_9 ) ;
if ( ! V_516 )
return - V_10 ;
if ( F_212 ( V_516 , V_177 , V_513 ) ) {
V_73 = - V_452 ;
goto V_191;
}
V_516 [ V_513 ] = '\0' ;
V_73 = F_209 ( V_21 , V_516 , V_513 ) ;
V_191:
F_80 ( V_516 ) ;
if ( V_73 < 0 )
return V_73 ;
* V_515 += V_513 ;
return V_513 ;
}
static int
F_213 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
* V_194 = F_50 ( & V_66 -> V_519 . V_520 ) ;
return 0 ;
}
static int
F_214 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
F_215 ( L_277 , V_194 ) ;
F_216 ( V_21 , V_194 ) ;
return 0 ;
}
static int
F_217 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
* V_194 = V_66 -> V_519 . V_521 ;
return 0 ;
}
static int
F_218 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_73 ( L_278 , V_194 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_519 . V_521 = V_194 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_219 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_194 = V_66 -> V_519 . V_522 ;
return 0 ;
}
static int
F_220 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_519 . V_522 = V_194 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_221 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_194 = V_66 -> V_519 . V_523 ;
return 0 ;
}
static int
F_222 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_73 ( L_279 , V_194 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_519 . V_523 = V_194 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_223 ( void * V_18 , T_9 * V_194 )
{
* V_194 = V_524 ;
return 0 ;
}
static int
F_224 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 , * V_525 ;
struct V_68 * V_51 ;
struct V_34 * V_35 , * T_1 ;
int V_73 ;
F_73 ( L_280 , V_194 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( V_194 & V_526 ) {
V_73 = F_225 ( V_21 ) ;
if ( V_73 )
goto V_527;
}
if ( V_194 & ( V_528 | V_526 ) )
F_226 ( V_21 ) ;
if ( V_194 & V_529 ) {
F_20 (vm, &dev_priv->vm_list, global_link) {
F_227 (vma, x, &vm->inactive_list,
mm_list) {
if ( V_35 -> V_26 -> V_28 )
continue;
V_73 = F_228 ( V_35 ) ;
if ( V_73 )
goto V_527;
}
}
}
if ( V_194 & V_530 ) {
F_227 (obj, next, &dev_priv->mm.unbound_list,
global_list)
if ( V_26 -> V_531 == 0 ) {
V_73 = F_229 ( V_26 ) ;
if ( V_73 )
goto V_527;
}
}
V_527:
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int
F_230 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_94 ( V_21 ) || F_95 ( V_21 ) ) )
return - V_338 ;
F_92 ( & V_66 -> V_199 . V_200 ) ;
V_73 = F_26 ( & V_66 -> V_199 . V_244 ) ;
if ( V_73 )
return V_73 ;
if ( F_66 ( V_21 ) )
* V_194 = F_100 ( V_66 -> V_246 ,
V_66 -> V_199 . V_342 ) ;
else
* V_194 = V_66 -> V_199 . V_342 * V_227 ;
F_7 ( & V_66 -> V_199 . V_244 ) ;
return 0 ;
}
static int
F_231 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_94 ( V_21 ) || F_95 ( V_21 ) ) )
return - V_338 ;
F_92 ( & V_66 -> V_199 . V_200 ) ;
F_73 ( L_281 , V_194 ) ;
V_73 = F_26 ( & V_66 -> V_199 . V_244 ) ;
if ( V_73 )
return V_73 ;
if ( F_66 ( V_21 ) ) {
V_194 = F_232 ( V_66 -> V_246 , V_194 ) ;
V_66 -> V_199 . V_342 = V_194 ;
F_233 ( V_21 , V_194 ) ;
} else {
F_234 ( V_194 , V_227 ) ;
V_66 -> V_199 . V_342 = V_194 ;
F_233 ( V_21 , V_194 ) ;
}
F_7 ( & V_66 -> V_199 . V_244 ) ;
return 0 ;
}
static int
F_235 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_94 ( V_21 ) || F_95 ( V_21 ) ) )
return - V_338 ;
F_92 ( & V_66 -> V_199 . V_200 ) ;
V_73 = F_26 ( & V_66 -> V_199 . V_244 ) ;
if ( V_73 )
return V_73 ;
if ( F_66 ( V_21 ) )
* V_194 = F_100 ( V_66 -> V_246 ,
V_66 -> V_199 . V_341 ) ;
else
* V_194 = V_66 -> V_199 . V_341 * V_227 ;
F_7 ( & V_66 -> V_199 . V_244 ) ;
return 0 ;
}
static int
F_236 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_94 ( V_21 ) || F_95 ( V_21 ) ) )
return - V_338 ;
F_92 ( & V_66 -> V_199 . V_200 ) ;
F_73 ( L_282 , V_194 ) ;
V_73 = F_26 ( & V_66 -> V_199 . V_244 ) ;
if ( V_73 )
return V_73 ;
if ( F_66 ( V_21 ) ) {
V_194 = F_232 ( V_66 -> V_246 , V_194 ) ;
V_66 -> V_199 . V_341 = V_194 ;
F_237 ( V_21 , V_194 ) ;
} else {
F_234 ( V_194 , V_227 ) ;
V_66 -> V_199 . V_341 = V_194 ;
F_233 ( V_21 , V_194 ) ;
}
F_7 ( & V_66 -> V_199 . V_244 ) ;
return 0 ;
}
static int
F_238 ( void * V_18 , T_9 * V_194 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_532 ;
int V_73 ;
if ( ! ( F_94 ( V_21 ) || F_95 ( V_21 ) ) )
return - V_338 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_532 = F_58 ( V_533 ) ;
F_7 ( & V_66 -> V_21 -> V_74 ) ;
* V_194 = ( V_532 & V_534 ) >> V_535 ;
return 0 ;
}
static int
F_239 ( void * V_18 , T_9 V_194 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_532 ;
if ( ! ( F_94 ( V_21 ) || F_95 ( V_21 ) ) )
return - V_338 ;
if ( V_194 > 3 )
return - V_79 ;
F_73 ( L_283 , V_194 ) ;
V_532 = F_58 ( V_533 ) ;
V_532 &= ~ V_534 ;
V_532 |= ( V_194 << V_535 ) ;
F_192 ( V_533 , V_532 ) ;
return 0 ;
}
static int F_240 ( struct V_183 * V_183 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_183 -> V_184 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_96 ( V_66 ) ;
return 0 ;
}
static int F_241 ( struct V_183 * V_183 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_183 -> V_184 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_98 ( V_66 ) ;
return 0 ;
}
static int F_242 ( struct V_4 * V_453 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_174 ( L_284 ,
V_536 ,
V_453 , V_21 ,
& V_537 ) ;
if ( F_175 ( V_5 ) )
return F_176 ( V_5 ) ;
return F_2 ( V_3 , V_5 , & V_537 ) ;
}
static int F_243 ( struct V_4 * V_453 ,
struct V_2 * V_3 ,
const char * V_47 ,
const struct V_538 * V_539 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_174 ( V_47 ,
V_455 | V_540 ,
V_453 , V_21 ,
V_539 ) ;
if ( F_175 ( V_5 ) )
return F_176 ( V_5 ) ;
return F_2 ( V_3 , V_5 , V_539 ) ;
}
void F_244 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
int V_130 ;
for ( V_130 = 0 ; V_130 < F_9 ( V_21 ) -> V_541 ; V_130 ++ ) {
struct V_429 * V_430 = & V_66 -> V_430 [ V_130 ] ;
V_430 -> V_431 = false ;
F_245 ( & V_430 -> V_286 ) ;
F_246 ( & V_430 -> V_446 ) ;
}
}
int F_247 ( struct V_2 * V_3 )
{
int V_73 , V_130 ;
V_73 = F_242 ( V_3 -> V_542 , V_3 ) ;
if ( V_73 )
return V_73 ;
for ( V_130 = 0 ; V_130 < F_179 ( V_454 ) ; V_130 ++ ) {
V_73 = F_173 ( V_3 -> V_542 , V_3 , V_130 ) ;
if ( V_73 )
return V_73 ;
}
for ( V_130 = 0 ; V_130 < F_179 ( V_543 ) ; V_130 ++ ) {
V_73 = F_243 ( V_3 -> V_542 , V_3 ,
V_543 [ V_130 ] . V_47 ,
V_543 [ V_130 ] . V_539 ) ;
if ( V_73 )
return V_73 ;
}
return F_248 ( V_544 ,
V_545 ,
V_3 -> V_542 , V_3 ) ;
}
void F_249 ( struct V_2 * V_3 )
{
int V_130 ;
F_250 ( V_544 ,
V_545 , V_3 ) ;
F_250 ( (struct V_546 * ) & V_537 ,
1 , V_3 ) ;
for ( V_130 = 0 ; V_130 < F_179 ( V_454 ) ; V_130 ++ ) {
struct V_546 * V_547 =
(struct V_546 * ) & V_454 [ V_130 ] ;
F_250 ( V_547 , 1 , V_3 ) ;
}
for ( V_130 = 0 ; V_130 < F_179 ( V_543 ) ; V_130 ++ ) {
struct V_546 * V_547 =
(struct V_546 * ) V_543 [ V_130 ] . V_539 ;
F_250 ( V_547 , 1 , V_3 ) ;
}
}
