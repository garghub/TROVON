static const char * F_1 ( int V_1 )
{
return V_1 ? L_1 : L_2 ;
}
static int F_2 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
const struct V_11 * V_12 = F_3 ( V_9 ) ;
F_4 ( V_3 , L_3 , V_12 -> V_13 ) ;
F_4 ( V_3 , L_4 , F_5 ( V_9 ) ) ;
#define F_6 ( T_1 ) seq_printf(m, #x ": %s\n", yesno(info->x))
#define F_7 ;
F_8 ( F_6 , F_7 ) ;
#undef F_6
#undef F_7
return 0 ;
}
static const char * F_9 ( struct V_14 * V_15 )
{
if ( V_15 -> V_16 > 0 )
return L_5 ;
else if ( V_15 -> V_17 > 0 )
return L_6 ;
else
return L_7 ;
}
static const char * F_10 ( struct V_14 * V_15 )
{
switch ( V_15 -> V_18 ) {
default:
case V_19 : return L_7 ;
case V_20 : return L_8 ;
case V_21 : return L_9 ;
}
}
static inline const char * F_11 ( struct V_14 * V_15 )
{
return V_15 -> V_22 ? L_10 : L_7 ;
}
static void
F_12 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
struct V_23 * V_24 ;
F_4 ( V_3 , L_11 ,
& V_15 -> V_25 ,
F_9 ( V_15 ) ,
F_10 ( V_15 ) ,
F_11 ( V_15 ) ,
V_15 -> V_25 . V_26 / 1024 ,
V_15 -> V_25 . V_27 ,
V_15 -> V_25 . V_28 ,
V_15 -> V_29 ,
V_15 -> V_30 ,
V_15 -> V_31 ,
F_13 ( V_15 -> V_32 ) ,
V_15 -> V_33 ? L_12 : L_13 ,
V_15 -> V_34 == V_35 ? L_14 : L_13 ) ;
if ( V_15 -> V_25 . V_36 )
F_4 ( V_3 , L_15 , V_15 -> V_25 . V_36 ) ;
if ( V_15 -> V_17 )
F_4 ( V_3 , L_16 , V_15 -> V_17 ) ;
if ( V_15 -> V_37 )
F_4 ( V_3 , L_17 ) ;
if ( V_15 -> V_38 != V_39 )
F_4 ( V_3 , L_18 , V_15 -> V_38 ) ;
F_14 (vma, &obj->vma_list, vma_link) {
if ( ! F_15 ( V_24 -> V_40 ) )
F_16 ( V_3 , L_19 ) ;
else
F_16 ( V_3 , L_20 ) ;
F_4 ( V_3 , L_21 ,
V_24 -> V_6 . V_41 , V_24 -> V_6 . V_26 ) ;
}
if ( V_15 -> V_42 )
F_4 ( V_3 , L_22 , V_15 -> V_42 -> V_41 ) ;
if ( V_15 -> V_43 || V_15 -> V_44 ) {
char V_45 [ 3 ] , * V_46 = V_45 ;
if ( V_15 -> V_43 )
* V_46 ++ = 'p' ;
if ( V_15 -> V_44 )
* V_46 ++ = 'f' ;
* V_46 = '\0' ;
F_4 ( V_3 , L_23 , V_45 ) ;
}
if ( V_15 -> V_47 != NULL )
F_4 ( V_3 , L_24 , V_15 -> V_47 -> V_36 ) ;
}
static int F_17 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_48 = ( T_2 ) V_6 -> V_49 -> V_4 ;
struct V_50 * V_51 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
struct V_55 * V_40 = & V_53 -> V_56 . V_25 ;
struct V_23 * V_24 ;
T_3 V_57 , V_58 ;
int V_59 , V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
switch ( V_48 ) {
case V_62 :
F_16 ( V_3 , L_25 ) ;
V_51 = & V_40 -> V_63 ;
break;
case V_64 :
F_16 ( V_3 , L_26 ) ;
V_51 = & V_40 -> V_65 ;
break;
default:
F_19 ( & V_9 -> V_61 ) ;
return - V_66 ;
}
V_57 = V_58 = V_59 = 0 ;
F_14 (vma, head, mm_list) {
F_4 ( V_3 , L_27 ) ;
F_12 ( V_3 , V_24 -> V_15 ) ;
F_4 ( V_3 , L_28 ) ;
V_57 += V_24 -> V_15 -> V_25 . V_26 ;
V_58 += V_24 -> V_6 . V_26 ;
V_59 ++ ;
}
F_19 ( & V_9 -> V_61 ) ;
F_4 ( V_3 , L_29 ,
V_59 , V_57 , V_58 ) ;
return 0 ;
}
static int F_20 ( void * V_67 ,
struct V_50 * V_68 , struct V_50 * V_69 )
{
struct V_14 * V_70 =
F_21 ( V_68 , struct V_14 , V_71 ) ;
struct V_14 * V_72 =
F_21 ( V_69 , struct V_14 , V_71 ) ;
return V_70 -> V_42 -> V_41 - V_72 -> V_42 -> V_41 ;
}
static int F_22 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
struct V_14 * V_15 ;
T_3 V_57 , V_58 ;
F_23 ( V_42 ) ;
int V_59 , V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_57 = V_58 = V_59 = 0 ;
F_14 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_15 -> V_42 == NULL )
continue;
F_24 ( & V_15 -> V_71 , & V_42 ) ;
V_57 += V_15 -> V_25 . V_26 ;
V_58 += F_25 ( V_15 ) ;
V_59 ++ ;
}
F_14 (obj, &dev_priv->mm.unbound_list, global_list) {
if ( V_15 -> V_42 == NULL )
continue;
F_24 ( & V_15 -> V_71 , & V_42 ) ;
V_57 += V_15 -> V_25 . V_26 ;
V_59 ++ ;
}
F_26 ( NULL , & V_42 , F_20 ) ;
F_16 ( V_3 , L_30 ) ;
while ( ! F_27 ( & V_42 ) ) {
V_15 = F_28 ( & V_42 , F_29 ( * V_15 ) , V_71 ) ;
F_16 ( V_3 , L_27 ) ;
F_12 ( V_3 , V_15 ) ;
F_30 ( V_3 , '\n' ) ;
F_31 ( & V_15 -> V_71 ) ;
}
F_19 ( & V_9 -> V_61 ) ;
F_4 ( V_3 , L_29 ,
V_59 , V_57 , V_58 ) ;
return 0 ;
}
static int F_32 ( int V_73 , void * V_74 , void * V_4 )
{
struct V_14 * V_15 = V_74 ;
struct V_75 * V_76 = V_4 ;
V_76 -> V_59 ++ ;
V_76 -> V_77 += V_15 -> V_25 . V_26 ;
if ( F_33 ( V_15 ) ) {
if ( ! F_27 ( & V_15 -> V_78 ) )
V_76 -> V_79 += V_15 -> V_25 . V_26 ;
else
V_76 -> V_80 += V_15 -> V_25 . V_26 ;
} else {
if ( ! F_27 ( & V_15 -> V_81 ) )
V_76 -> V_82 += V_15 -> V_25 . V_26 ;
}
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
T_4 V_59 , V_83 , V_84 ;
T_3 V_26 , V_85 , V_86 ;
struct V_14 * V_15 ;
struct V_55 * V_40 = & V_53 -> V_56 . V_25 ;
struct V_87 * V_88 ;
struct V_23 * V_24 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_4 ( V_3 , L_31 ,
V_53 -> V_89 . V_90 ,
V_53 -> V_89 . V_91 ) ;
V_26 = V_59 = V_85 = V_83 = 0 ;
F_35 ( & V_53 -> V_89 . V_92 , V_81 ) ;
F_4 ( V_3 , L_32 ,
V_59 , V_83 , V_26 , V_85 ) ;
V_26 = V_59 = V_85 = V_83 = 0 ;
F_36 ( & V_40 -> V_63 , V_93 ) ;
F_4 ( V_3 , L_33 ,
V_59 , V_83 , V_26 , V_85 ) ;
V_26 = V_59 = V_85 = V_83 = 0 ;
F_36 ( & V_40 -> V_65 , V_93 ) ;
F_4 ( V_3 , L_34 ,
V_59 , V_83 , V_26 , V_85 ) ;
V_26 = V_59 = V_86 = V_84 = 0 ;
F_14 (obj, &dev_priv->mm.unbound_list, global_list) {
V_26 += V_15 -> V_25 . V_26 , ++ V_59 ;
if ( V_15 -> V_34 == V_35 )
V_86 += V_15 -> V_25 . V_26 , ++ V_84 ;
}
F_4 ( V_3 , L_35 , V_59 , V_26 ) ;
V_26 = V_59 = V_85 = V_83 = 0 ;
F_14 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_15 -> V_44 ) {
V_26 += F_25 ( V_15 ) ;
++ V_59 ;
}
if ( V_15 -> V_43 ) {
V_85 += F_25 ( V_15 ) ;
++ V_83 ;
}
if ( V_15 -> V_34 == V_35 ) {
V_86 += V_15 -> V_25 . V_26 ;
++ V_84 ;
}
}
F_4 ( V_3 , L_36 ,
V_84 , V_86 ) ;
F_4 ( V_3 , L_37 ,
V_83 , V_85 ) ;
F_4 ( V_3 , L_38 ,
V_59 , V_26 ) ;
F_4 ( V_3 , L_39 ,
V_53 -> V_56 . V_25 . V_77 ,
V_53 -> V_56 . V_94 - V_53 -> V_56 . V_25 . V_41 ) ;
F_30 ( V_3 , '\n' ) ;
F_37 (file, &dev->filelist, lhead) {
struct V_75 V_76 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
F_38 ( & V_88 -> V_95 , F_32 , & V_76 ) ;
F_4 ( V_3 , L_40 ,
F_39 ( V_88 -> V_96 , V_97 ) -> V_98 ,
V_76 . V_59 ,
V_76 . V_77 ,
V_76 . V_79 ,
V_76 . V_80 ,
V_76 . V_82 ) ;
}
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_2 V_48 = ( T_2 ) V_6 -> V_49 -> V_4 ;
struct V_52 * V_53 = V_9 -> V_54 ;
struct V_14 * V_15 ;
T_3 V_57 , V_58 ;
int V_59 , V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_57 = V_58 = V_59 = 0 ;
F_14 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_48 == V_99 && V_15 -> V_17 == 0 )
continue;
F_16 ( V_3 , L_27 ) ;
F_12 ( V_3 , V_15 ) ;
F_30 ( V_3 , '\n' ) ;
V_57 += V_15 -> V_25 . V_26 ;
V_58 += F_25 ( V_15 ) ;
V_59 ++ ;
}
F_19 ( & V_9 -> V_61 ) ;
F_4 ( V_3 , L_29 ,
V_59 , V_57 , V_58 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
unsigned long V_100 ;
struct V_101 * V_102 ;
F_14 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_103 = F_42 ( V_102 -> V_103 ) ;
const char V_104 = F_43 ( V_102 -> V_104 ) ;
struct V_105 * V_106 ;
F_44 ( & V_9 -> V_107 , V_100 ) ;
V_106 = V_102 -> V_108 ;
if ( V_106 == NULL ) {
F_4 ( V_3 , L_41 ,
V_103 , V_104 ) ;
} else {
if ( F_45 ( & V_106 -> V_109 ) < V_110 ) {
F_4 ( V_3 , L_42 ,
V_103 , V_104 ) ;
} else {
F_4 ( V_3 , L_43 ,
V_103 , V_104 ) ;
}
if ( V_106 -> V_111 )
F_16 ( V_3 , L_44 ) ;
else
F_16 ( V_3 , L_45 ) ;
F_4 ( V_3 , L_46 , F_45 ( & V_106 -> V_109 ) ) ;
if ( V_106 -> V_112 ) {
struct V_14 * V_15 = V_106 -> V_112 ;
if ( V_15 )
F_4 ( V_3 , L_47 ,
F_46 ( V_15 ) ) ;
}
if ( V_106 -> V_113 ) {
struct V_14 * V_15 = V_106 -> V_113 ;
if ( V_15 )
F_4 ( V_3 , L_48 ,
F_46 ( V_15 ) ) ;
}
}
F_47 ( & V_9 -> V_107 , V_100 ) ;
}
return 0 ;
}
static int F_48 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
struct V_114 * V_47 ;
struct V_115 * V_116 ;
int V_60 , V_59 , V_117 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_59 = 0 ;
F_49 (ring, dev_priv, i) {
if ( F_27 ( & V_47 -> V_118 ) )
continue;
F_4 ( V_3 , L_49 , V_47 -> V_36 ) ;
F_14 (gem_request,
&ring->request_list,
list) {
F_4 ( V_3 , L_50 ,
V_116 -> V_119 ,
( int ) ( V_120 - V_116 -> V_121 ) ) ;
}
V_59 ++ ;
}
F_19 ( & V_9 -> V_61 ) ;
if ( V_59 == 0 )
F_16 ( V_3 , L_51 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_114 * V_47 )
{
if ( V_47 -> V_122 ) {
F_4 ( V_3 , L_52 ,
V_47 -> V_36 , V_47 -> V_122 ( V_47 , false ) ) ;
}
}
static int F_51 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
struct V_114 * V_47 ;
int V_60 , V_117 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_49 (ring, dev_priv, i)
F_50 ( V_3 , V_47 ) ;
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
struct V_114 * V_47 ;
int V_60 , V_117 , V_103 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
if ( F_53 ( V_9 ) ) {
F_4 ( V_3 , L_53 ,
F_54 ( V_123 ) ) ;
F_4 ( V_3 , L_54 ,
F_54 ( V_124 ) ) ;
F_4 ( V_3 , L_55 ,
F_54 ( V_125 ) ) ;
F_4 ( V_3 , L_56 ,
F_54 ( V_126 ) ) ;
F_55 (pipe)
F_4 ( V_3 , L_57 ,
F_42 ( V_103 ) ,
F_54 ( F_56 ( V_103 ) ) ) ;
F_4 ( V_3 , L_58 ,
F_54 ( V_127 ) ) ;
F_4 ( V_3 , L_59 ,
F_54 ( V_128 ) ) ;
F_4 ( V_3 , L_60 ,
F_54 ( V_129 ) ) ;
F_4 ( V_3 , L_61 ,
F_54 ( V_130 ) ) ;
F_4 ( V_3 , L_62 ,
F_54 ( V_131 ) ) ;
F_4 ( V_3 , L_63 ,
F_54 ( V_132 ) ) ;
F_4 ( V_3 , L_64 ,
F_54 ( V_133 ) ) ;
F_4 ( V_3 , L_65 ,
F_54 ( V_134 ) ) ;
F_4 ( V_3 , L_66 ,
F_54 ( V_135 ) ) ;
F_4 ( V_3 , L_67 ,
F_54 ( V_136 ) ) ;
} else if ( ! F_57 ( V_9 ) ) {
F_4 ( V_3 , L_68 ,
F_54 ( V_137 ) ) ;
F_4 ( V_3 , L_69 ,
F_54 ( V_138 ) ) ;
F_4 ( V_3 , L_70 ,
F_54 ( V_139 ) ) ;
F_55 (pipe)
F_4 ( V_3 , L_71 ,
F_42 ( V_103 ) ,
F_54 ( F_56 ( V_103 ) ) ) ;
} else {
F_4 ( V_3 , L_72 ,
F_54 ( V_140 ) ) ;
F_4 ( V_3 , L_73 ,
F_54 ( V_141 ) ) ;
F_4 ( V_3 , L_74 ,
F_54 ( V_142 ) ) ;
F_4 ( V_3 , L_75 ,
F_54 ( V_143 ) ) ;
F_4 ( V_3 , L_76 ,
F_54 ( V_144 ) ) ;
F_4 ( V_3 , L_77 ,
F_54 ( V_145 ) ) ;
F_4 ( V_3 , L_78 ,
F_54 ( V_128 ) ) ;
F_4 ( V_3 , L_79 ,
F_54 ( V_129 ) ) ;
F_4 ( V_3 , L_80 ,
F_54 ( V_130 ) ) ;
}
F_4 ( V_3 , L_81 ,
F_45 ( & V_53 -> V_146 ) ) ;
F_49 (ring, dev_priv, i) {
if ( F_58 ( V_9 ) || F_59 ( V_9 ) ) {
F_4 ( V_3 ,
L_82 ,
V_47 -> V_36 , F_60 ( V_47 ) ) ;
}
F_50 ( V_3 , V_47 ) ;
}
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
int V_117 , V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_4 ( V_3 , L_83 , V_53 -> V_147 ) ;
F_4 ( V_3 , L_84 , V_53 -> V_148 ) ;
for ( V_117 = 0 ; V_117 < V_53 -> V_148 ; V_117 ++ ) {
struct V_14 * V_15 = V_53 -> V_149 [ V_117 ] . V_15 ;
F_4 ( V_3 , L_85 ,
V_117 , V_53 -> V_149 [ V_117 ] . V_17 ) ;
if ( V_15 == NULL )
F_16 ( V_3 , L_86 ) ;
else
F_12 ( V_3 , V_15 ) ;
F_30 ( V_3 , '\n' ) ;
}
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
struct V_114 * V_47 ;
const T_4 * V_150 ;
int V_117 ;
V_47 = & V_53 -> V_47 [ ( T_2 ) V_6 -> V_49 -> V_4 ] ;
V_150 = V_47 -> V_151 . V_152 ;
if ( V_150 == NULL )
return 0 ;
for ( V_117 = 0 ; V_117 < 4096 / sizeof( T_4 ) / 4 ; V_117 += 4 ) {
F_4 ( V_3 , L_87 ,
V_117 * 4 ,
V_150 [ V_117 ] , V_150 [ V_117 + 1 ] , V_150 [ V_117 + 2 ] , V_150 [ V_117 + 3 ] ) ;
}
return 0 ;
}
static T_6
F_63 ( struct V_88 * V_153 ,
const char T_7 * V_154 ,
T_3 V_155 ,
T_8 * V_156 )
{
struct V_157 * V_158 = V_153 -> V_159 ;
struct V_8 * V_9 = V_158 -> V_9 ;
int V_60 ;
F_64 ( L_88 ) ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_65 ( V_9 ) ;
F_19 ( & V_9 -> V_61 ) ;
return V_155 ;
}
static int F_66 ( struct V_160 * V_160 , struct V_88 * V_88 )
{
struct V_8 * V_9 = V_160 -> V_161 ;
struct V_157 * V_158 ;
V_158 = F_67 ( sizeof( * V_158 ) , V_162 ) ;
if ( ! V_158 )
return - V_163 ;
V_158 -> V_9 = V_9 ;
F_68 ( V_9 , V_158 ) ;
V_88 -> V_159 = V_158 ;
return 0 ;
}
static int F_69 ( struct V_160 * V_160 , struct V_88 * V_88 )
{
struct V_157 * V_158 = V_88 -> V_159 ;
F_70 ( V_158 ) ;
F_71 ( V_158 ) ;
return 0 ;
}
static T_6 F_72 ( struct V_88 * V_88 , char T_7 * V_164 ,
T_3 V_59 , T_8 * V_165 )
{
struct V_157 * V_158 = V_88 -> V_159 ;
struct V_166 V_167 ;
T_8 V_168 = 0 ;
T_6 V_169 = 0 ;
int V_60 ;
V_60 = F_73 ( & V_167 , V_59 , * V_165 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_74 ( & V_167 , V_158 ) ;
if ( V_60 )
goto V_170;
V_169 = F_75 ( V_164 , V_59 , & V_168 ,
V_167 . V_171 ,
V_167 . V_172 ) ;
if ( V_169 < 0 )
V_60 = V_169 ;
else
* V_165 = V_167 . V_41 + V_169 ;
V_170:
F_76 ( & V_167 ) ;
return V_60 ? : V_169 ;
}
static int
F_77 ( void * V_4 , T_9 * V_173 )
{
struct V_8 * V_9 = V_4 ;
T_5 * V_53 = V_9 -> V_54 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
* V_173 = V_53 -> V_174 ;
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int
F_78 ( void * V_4 , T_9 V_173 )
{
struct V_8 * V_9 = V_4 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_79 ( V_9 , V_173 ) ;
F_19 ( & V_9 -> V_61 ) ;
return V_60 ;
}
static int F_80 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
T_10 V_176 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_176 = F_81 ( V_177 ) ;
F_19 ( & V_9 -> V_61 ) ;
F_4 ( V_3 , L_89 , ( V_176 >> 8 ) & 0x3f , ( V_176 & 0x3f ) ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
int V_60 ;
if ( F_83 ( V_9 ) ) {
T_10 V_178 = F_81 ( V_179 ) ;
T_10 V_180 = F_81 ( V_181 ) ;
F_4 ( V_3 , L_90 , ( V_178 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_91 , V_178 & 0x3f ) ;
F_4 ( V_3 , L_92 , ( V_180 & V_182 ) >>
V_183 ) ;
F_4 ( V_3 , L_93 ,
( V_180 & V_184 ) >> V_185 ) ;
} else if ( ( F_58 ( V_9 ) || F_59 ( V_9 ) ) && ! F_53 ( V_9 ) ) {
T_4 V_186 = F_54 ( V_187 ) ;
T_4 V_188 = F_54 ( V_189 ) ;
T_4 V_190 = F_54 ( V_191 ) ;
T_4 V_192 , V_193 , V_194 ;
T_4 V_195 , V_196 , V_197 ;
T_4 V_198 , V_199 , V_200 ;
int V_201 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_84 ( V_53 ) ;
V_194 = F_54 ( V_202 ) ;
V_194 &= ~ V_203 ;
if ( F_85 ( V_9 ) )
V_194 >>= 24 ;
else
V_194 >>= 25 ;
V_194 *= V_204 ;
V_192 = F_54 ( V_205 ) ;
V_195 = F_54 ( V_206 ) ;
V_196 = F_54 ( V_207 ) ;
V_197 = F_54 ( V_208 ) ;
V_198 = F_54 ( V_209 ) ;
V_199 = F_54 ( V_210 ) ;
V_200 = F_54 ( V_211 ) ;
if ( F_85 ( V_9 ) )
V_193 = ( V_192 & V_212 ) >> V_213 ;
else
V_193 = ( V_192 & V_214 ) >> V_215 ;
V_193 *= V_204 ;
F_86 ( V_53 ) ;
F_19 ( & V_9 -> V_61 ) ;
F_4 ( V_3 , L_94 , V_186 ) ;
F_4 ( V_3 , L_95 , V_192 ) ;
F_4 ( V_3 , L_96 ,
( V_186 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_97 ,
V_186 & 0xff ) ;
F_4 ( V_3 , L_98 ,
V_188 & 0xff ) ;
F_4 ( V_3 , L_99 , V_194 ) ;
F_4 ( V_3 , L_100 , V_193 ) ;
F_4 ( V_3 , L_101 , V_195 &
V_216 ) ;
F_4 ( V_3 , L_102 , V_196 &
V_217 ) ;
F_4 ( V_3 , L_103 , V_197 &
V_217 ) ;
F_4 ( V_3 , L_104 , V_198 &
V_218 ) ;
F_4 ( V_3 , L_105 , V_199 &
V_217 ) ;
F_4 ( V_3 , L_106 , V_200 &
V_217 ) ;
V_201 = ( V_190 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_107 ,
V_201 * V_204 ) ;
V_201 = ( V_190 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_108 ,
V_201 * V_204 ) ;
V_201 = V_190 & 0xff ;
F_4 ( V_3 , L_109 ,
V_201 * V_204 ) ;
F_4 ( V_3 , L_110 ,
V_53 -> V_219 . V_220 * V_204 ) ;
} else if ( F_53 ( V_9 ) ) {
T_4 V_221 , V_173 ;
F_87 ( & V_53 -> V_219 . V_222 ) ;
V_221 = F_88 ( V_53 , V_223 ) ;
F_4 ( V_3 , L_111 , V_221 ) ;
F_4 ( V_3 , L_112 , V_53 -> V_224 ) ;
V_173 = F_88 ( V_53 , V_225 ) ;
F_4 ( V_3 , L_113 ,
F_89 ( V_53 -> V_224 , V_173 ) ) ;
V_173 = F_88 ( V_53 , V_226 ) ;
F_4 ( V_3 , L_114 ,
F_89 ( V_53 -> V_224 , V_173 ) ) ;
F_4 ( V_3 , L_115 ,
F_89 ( V_53 -> V_224 ,
( V_221 >> 8 ) & 0xff ) ) ;
F_19 ( & V_53 -> V_219 . V_222 ) ;
} else {
F_16 ( V_3 , L_116 ) ;
}
return 0 ;
}
static int F_90 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
T_4 V_227 ;
int V_60 , V_117 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
for ( V_117 = 0 ; V_117 < 16 ; V_117 ++ ) {
V_227 = F_54 ( V_228 + V_117 * 4 ) ;
F_4 ( V_3 , L_117 , V_117 , V_227 ,
( V_227 & V_229 ) >> V_230 ) ;
}
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static inline int F_91 ( int V_231 )
{
return 1250 - ( V_231 * 25 ) ;
}
static int F_92 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
T_4 V_232 ;
int V_60 , V_117 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
for ( V_117 = 1 ; V_117 <= 32 ; V_117 ++ ) {
V_232 = F_54 ( V_233 + V_117 * 4 ) ;
F_4 ( V_3 , L_118 , V_117 , V_232 ) ;
}
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
T_4 V_234 , V_235 ;
T_10 V_236 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_234 = F_54 ( V_237 ) ;
V_235 = F_54 ( V_238 ) ;
V_236 = F_81 ( V_177 ) ;
F_19 ( & V_9 -> V_61 ) ;
F_4 ( V_3 , L_119 , ( V_234 & V_239 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_120 ,
( V_234 & V_240 ) >>
V_241 ) ;
F_4 ( V_3 , L_121 ,
V_234 & V_242 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_122 ,
V_234 & V_243 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_123 ,
V_234 & V_244 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_124 ,
( V_234 & V_245 ) >> V_246 ) ;
F_4 ( V_3 , L_125 ,
( V_234 & V_247 ) >> V_248 ) ;
F_4 ( V_3 , L_126 , ( V_234 & V_249 ) ) ;
F_4 ( V_3 , L_127 , ( V_236 & 0x3f ) ) ;
F_4 ( V_3 , L_128 , ( ( V_236 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_129 ,
( V_235 & V_250 ) ? L_2 : L_1 ) ;
F_16 ( V_3 , L_130 ) ;
switch ( V_235 & V_251 ) {
case V_252 :
F_16 ( V_3 , L_131 ) ;
break;
case V_253 :
F_16 ( V_3 , L_132 ) ;
break;
case V_254 :
F_16 ( V_3 , L_133 ) ;
break;
case V_255 :
F_16 ( V_3 , L_134 ) ;
break;
case V_256 :
F_16 ( V_3 , L_135 ) ;
break;
case V_257 :
F_16 ( V_3 , L_136 ) ;
break;
default:
F_16 ( V_3 , L_137 ) ;
break;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
T_4 V_258 , V_259 , V_260 , V_261 = 0 ;
unsigned V_262 ;
int V_59 = 0 , V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_95 ( & V_53 -> V_263 . V_264 ) ;
V_262 = V_53 -> V_263 . V_262 ;
F_96 ( & V_53 -> V_263 . V_264 ) ;
if ( V_262 ) {
F_16 ( V_3 , L_138
L_139 ) ;
} else {
while ( V_59 ++ < 50 && ( F_97 ( V_265 ) & 1 ) )
F_98 ( 10 ) ;
F_4 ( V_3 , L_140 , F_1 ( V_59 < 51 ) ) ;
}
V_259 = F_99 ( V_53 -> V_266 + V_267 ) ;
F_100 ( false , V_267 , V_259 , 4 , true ) ;
V_258 = F_54 ( V_268 ) ;
V_260 = F_54 ( V_269 ) ;
F_19 ( & V_9 -> V_61 ) ;
F_87 ( & V_53 -> V_219 . V_222 ) ;
F_101 ( V_53 , V_270 , & V_261 ) ;
F_19 ( & V_53 -> V_219 . V_222 ) ;
F_4 ( V_3 , L_141 ,
F_1 ( V_258 & V_271 ) ) ;
F_4 ( V_3 , L_121 ,
F_1 ( V_258 & V_272 ) ) ;
F_4 ( V_3 , L_122 ,
F_1 ( ( V_258 & V_273 ) ==
V_274 ) ) ;
F_4 ( V_3 , L_142 ,
F_1 ( V_260 & V_275 ) ) ;
F_4 ( V_3 , L_143 ,
F_1 ( V_260 & V_276 ) ) ;
F_4 ( V_3 , L_144 ,
F_1 ( V_260 & V_277 ) ) ;
F_4 ( V_3 , L_145 ,
F_1 ( V_260 & V_278 ) ) ;
F_16 ( V_3 , L_146 ) ;
switch ( V_259 & V_279 ) {
case V_280 :
if ( V_259 & V_281 )
F_16 ( V_3 , L_147 ) ;
else
F_16 ( V_3 , L_131 ) ;
break;
case V_282 :
F_16 ( V_3 , L_148 ) ;
break;
case V_283 :
F_16 ( V_3 , L_149 ) ;
break;
case V_284 :
F_16 ( V_3 , L_150 ) ;
break;
default:
F_16 ( V_3 , L_151 ) ;
break;
}
F_4 ( V_3 , L_152 ,
F_1 ( V_259 & V_281 ) ) ;
F_4 ( V_3 , L_153 ,
F_54 ( V_285 ) ) ;
F_4 ( V_3 , L_154 ,
F_54 ( V_286 ) ) ;
F_4 ( V_3 , L_155 ,
F_54 ( V_287 ) ) ;
F_4 ( V_3 , L_156 ,
F_54 ( V_288 ) ) ;
F_4 ( V_3 , L_157 ,
F_102 ( ( ( V_261 >> 0 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_158 ,
F_102 ( ( ( V_261 >> 8 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_159 ,
F_102 ( ( ( V_261 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_58 ( V_9 ) || F_59 ( V_9 ) )
return F_94 ( V_3 ) ;
else
return F_93 ( V_3 ) ;
}
static int F_104 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
if ( ! F_105 ( V_9 ) ) {
F_16 ( V_3 , L_160 ) ;
return 0 ;
}
if ( F_106 ( V_9 ) ) {
F_16 ( V_3 , L_161 ) ;
} else {
F_16 ( V_3 , L_162 ) ;
switch ( V_53 -> V_289 . V_290 ) {
case V_291 :
F_16 ( V_3 , L_163 ) ;
break;
case V_292 :
F_16 ( V_3 , L_164 ) ;
break;
case V_293 :
F_16 ( V_3 , L_165 ) ;
break;
case V_294 :
F_16 ( V_3 , L_166 ) ;
break;
case V_295 :
F_16 ( V_3 , L_167 ) ;
break;
case V_296 :
F_16 ( V_3 , L_168 ) ;
break;
case V_297 :
F_16 ( V_3 , L_169 ) ;
break;
case V_298 :
F_16 ( V_3 , L_170 ) ;
break;
case V_299 :
F_16 ( V_3 , L_171 ) ;
break;
case V_300 :
F_16 ( V_3 , L_172 ) ;
break;
case V_301 :
F_16 ( V_3 , L_173 ) ;
break;
default:
F_16 ( V_3 , L_174 ) ;
}
F_30 ( V_3 , '\n' ) ;
}
return 0 ;
}
static int F_107 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
if ( ! F_108 ( V_9 ) ) {
F_16 ( V_3 , L_175 ) ;
return 0 ;
}
if ( F_54 ( V_302 ) & V_303 )
F_16 ( V_3 , L_176 ) ;
else
F_16 ( V_3 , L_177 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
bool V_304 = false ;
if ( F_57 ( V_9 ) )
V_304 = F_54 ( V_305 ) & V_306 ;
else if ( F_110 ( V_9 ) || F_111 ( V_9 ) || F_112 ( V_9 ) )
V_304 = F_54 ( V_307 ) & V_308 ;
else if ( F_113 ( V_9 ) )
V_304 = F_54 ( V_309 ) & V_310 ;
else if ( F_114 ( V_9 ) )
V_304 = F_54 ( V_311 ) & V_312 ;
F_4 ( V_3 , L_178 ,
V_304 ? L_179 : L_180 ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
unsigned long V_313 , V_314 , V_315 ;
int V_60 ;
if ( ! F_83 ( V_9 ) )
return - V_316 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_313 = F_116 ( V_53 ) ;
V_314 = F_117 ( V_53 ) ;
V_315 = F_118 ( V_53 ) ;
F_19 ( & V_9 -> V_61 ) ;
F_4 ( V_3 , L_181 , V_313 ) ;
F_4 ( V_3 , L_182 , V_314 ) ;
F_4 ( V_3 , L_183 , V_315 ) ;
F_4 ( V_3 , L_184 , V_314 + V_315 ) ;
return 0 ;
}
static int F_119 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
int V_60 ;
int V_317 , V_318 ;
if ( ! ( F_58 ( V_9 ) || F_59 ( V_9 ) ) ) {
F_16 ( V_3 , L_185 ) ;
return 0 ;
}
V_60 = F_18 ( & V_53 -> V_219 . V_222 ) ;
if ( V_60 )
return V_60 ;
F_16 ( V_3 , L_186 ) ;
for ( V_317 = V_53 -> V_219 . V_319 ;
V_317 <= V_53 -> V_219 . V_320 ;
V_317 ++ ) {
V_318 = V_317 ;
F_101 ( V_53 ,
V_321 ,
& V_318 ) ;
F_4 ( V_3 , L_187 ,
V_317 * V_204 ,
( ( V_318 >> 0 ) & 0xff ) * 100 ,
( ( V_318 >> 8 ) & 0xff ) * 100 ) ;
}
F_19 ( & V_53 -> V_219 . V_222 ) ;
return 0 ;
}
static int F_120 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_4 ( V_3 , L_188 , ( unsigned long ) F_54 ( 0x112f4 ) ) ;
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_121 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
struct V_322 * V_323 = & V_53 -> V_323 ;
void * V_4 = F_122 ( V_324 , V_162 ) ;
int V_60 ;
if ( V_4 == NULL )
return - V_163 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
goto V_170;
if ( V_323 -> V_325 ) {
F_123 ( V_4 , V_323 -> V_325 , V_324 ) ;
F_124 ( V_3 , V_4 , V_324 ) ;
}
F_19 ( & V_9 -> V_61 ) ;
V_170:
F_71 ( V_4 ) ;
return 0 ;
}
static int F_125 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
struct V_326 * V_327 ;
struct V_328 * V_329 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_330 . V_331 ) ;
if ( V_60 )
return V_60 ;
V_327 = V_53 -> V_332 ;
V_329 = F_126 ( V_327 -> V_333 . V_329 ) ;
F_4 ( V_3 , L_189 ,
V_329 -> V_25 . V_334 ,
V_329 -> V_25 . V_335 ,
V_329 -> V_25 . V_336 ,
V_329 -> V_25 . V_337 ,
F_45 ( & V_329 -> V_25 . V_338 . V_338 ) ) ;
F_12 ( V_3 , V_329 -> V_15 ) ;
F_30 ( V_3 , '\n' ) ;
F_19 ( & V_9 -> V_330 . V_331 ) ;
F_87 ( & V_9 -> V_330 . V_339 ) ;
F_14 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_329 -> V_25 == V_327 -> V_333 . V_329 )
continue;
F_4 ( V_3 , L_190 ,
V_329 -> V_25 . V_334 ,
V_329 -> V_25 . V_335 ,
V_329 -> V_25 . V_336 ,
V_329 -> V_25 . V_337 ,
F_45 ( & V_329 -> V_25 . V_338 . V_338 ) ) ;
F_12 ( V_3 , V_329 -> V_15 ) ;
F_30 ( V_3 , '\n' ) ;
}
F_19 ( & V_9 -> V_330 . V_339 ) ;
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_5 * V_53 = V_9 -> V_54 ;
struct V_114 * V_47 ;
int V_60 , V_117 ;
V_60 = F_18 ( & V_9 -> V_330 . V_331 ) ;
if ( V_60 )
return V_60 ;
if ( V_53 -> V_340 . V_341 ) {
F_16 ( V_3 , L_191 ) ;
F_12 ( V_3 , V_53 -> V_340 . V_341 ) ;
F_30 ( V_3 , '\n' ) ;
}
if ( V_53 -> V_340 . V_342 ) {
F_16 ( V_3 , L_192 ) ;
F_12 ( V_3 , V_53 -> V_340 . V_342 ) ;
F_30 ( V_3 , '\n' ) ;
}
F_49 (ring, dev_priv, i) {
if ( V_47 -> V_343 ) {
F_4 ( V_3 , L_193 , V_47 -> V_36 ) ;
F_12 ( V_3 , V_47 -> V_343 -> V_15 ) ;
F_30 ( V_3 , '\n' ) ;
}
}
F_19 ( & V_9 -> V_330 . V_331 ) ;
return 0 ;
}
static int F_128 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
unsigned V_262 ;
F_95 ( & V_53 -> V_263 . V_264 ) ;
V_262 = V_53 -> V_263 . V_262 ;
F_96 ( & V_53 -> V_263 . V_264 ) ;
F_4 ( V_3 , L_194 , V_262 ) ;
return 0 ;
}
static const char * F_129 ( unsigned V_344 )
{
switch ( V_344 ) {
case V_345 :
return L_195 ;
case V_346 :
return L_196 ;
case V_347 :
return L_197 ;
case V_348 :
return L_198 ;
case V_349 :
return L_199 ;
case V_350 :
return L_200 ;
case V_351 :
return L_201 ;
case V_352 :
return L_202 ;
}
return L_203 ;
}
static int F_130 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
int V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
F_4 ( V_3 , L_204 ,
F_129 ( V_53 -> V_89 . V_353 ) ) ;
F_4 ( V_3 , L_205 ,
F_129 ( V_53 -> V_89 . V_354 ) ) ;
if ( F_131 ( V_9 ) || F_132 ( V_9 ) ) {
F_4 ( V_3 , L_206 ,
F_54 ( V_355 ) ) ;
F_4 ( V_3 , L_207 ,
F_81 ( V_356 ) ) ;
F_4 ( V_3 , L_208 ,
F_81 ( V_357 ) ) ;
} else if ( F_58 ( V_9 ) || F_59 ( V_9 ) ) {
F_4 ( V_3 , L_209 ,
F_54 ( V_358 ) ) ;
F_4 ( V_3 , L_210 ,
F_54 ( V_359 ) ) ;
F_4 ( V_3 , L_211 ,
F_54 ( V_360 ) ) ;
F_4 ( V_3 , L_212 ,
F_54 ( V_361 ) ) ;
F_4 ( V_3 , L_213 ,
F_54 ( V_362 ) ) ;
F_4 ( V_3 , L_214 ,
F_54 ( V_363 ) ) ;
}
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_133 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
struct V_114 * V_47 ;
int V_117 , V_60 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
if ( F_3 ( V_9 ) -> V_13 == 6 )
F_4 ( V_3 , L_215 , F_54 ( V_364 ) ) ;
F_49 (ring, dev_priv, i) {
F_4 ( V_3 , L_216 , V_47 -> V_36 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_215 , F_54 ( F_134 ( V_47 ) ) ) ;
F_4 ( V_3 , L_217 , F_54 ( F_135 ( V_47 ) ) ) ;
F_4 ( V_3 , L_218 , F_54 ( F_136 ( V_47 ) ) ) ;
F_4 ( V_3 , L_219 , F_54 ( F_137 ( V_47 ) ) ) ;
}
if ( V_53 -> V_89 . V_365 ) {
struct V_366 * V_367 = V_53 -> V_89 . V_365 ;
F_16 ( V_3 , L_220 ) ;
F_4 ( V_3 , L_221 , V_367 -> V_368 ) ;
}
F_4 ( V_3 , L_222 , F_54 ( V_369 ) ) ;
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int F_138 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
int V_60 ;
if ( ! F_53 ( V_9 ) ) {
F_16 ( V_3 , L_223 ) ;
return 0 ;
}
V_60 = F_18 ( & V_53 -> V_370 ) ;
if ( V_60 )
return V_60 ;
F_4 ( V_3 , L_224 , F_54 ( V_371 ) ) ;
F_4 ( V_3 , L_225 ,
F_139 ( V_53 , V_372 ) ) ;
F_4 ( V_3 , L_226 ,
F_139 ( V_53 , V_373 ) ) ;
F_4 ( V_3 , L_227 ,
F_139 ( V_53 , V_374 ) ) ;
F_4 ( V_3 , L_228 ,
F_139 ( V_53 , V_375 ) ) ;
F_4 ( V_3 , L_229 ,
F_139 ( V_53 , V_376 ) ) ;
F_4 ( V_3 , L_230 ,
F_139 ( V_53 , V_377 ) ) ;
F_4 ( V_3 , L_231 ,
F_139 ( V_53 , V_378 ) ) ;
F_4 ( V_3 , L_232 ,
F_139 ( V_53 , V_379 ) ) ;
F_4 ( V_3 , L_233 ,
F_139 ( V_53 , V_380 ) ) ;
F_19 ( & V_53 -> V_370 ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
F_4 ( V_3 , L_234 , F_1 ( F_141 ( V_9 ) ) ) ;
F_4 ( V_3 , L_235 , V_53 -> V_381 ) ;
return 0 ;
}
static int F_142 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
T_4 V_382 , V_383 ;
if ( ! F_85 ( V_9 ) ) {
F_16 ( V_3 , L_236 ) ;
} else if ( F_85 ( V_9 ) && F_54 ( V_384 ) & V_385 ) {
F_16 ( V_3 , L_237 ) ;
} else {
F_16 ( V_3 , L_238 ) ;
switch ( V_53 -> V_386 ) {
case V_387 :
F_16 ( V_3 , L_239 ) ;
break;
case V_388 :
F_16 ( V_3 , L_240 ) ;
break;
case V_389 :
F_16 ( V_3 , L_241 ) ;
break;
case V_390 :
F_16 ( V_3 , L_242 ) ;
break;
case V_391 :
F_16 ( V_3 , L_243 ) ;
break;
case V_392 :
F_16 ( V_3 , L_244 ) ;
break;
case V_393 :
F_16 ( V_3 , L_245 ) ;
break;
case V_394 :
F_16 ( V_3 , L_246 ) ;
break;
case V_395 :
F_16 ( V_3 , L_247 ) ;
break;
case V_396 :
F_16 ( V_3 , L_248 ) ;
break;
default:
F_16 ( V_3 , L_174 ) ;
}
F_16 ( V_3 , L_28 ) ;
return 0 ;
}
V_382 = F_54 ( V_397 ) ;
F_16 ( V_3 , L_249 ) ;
switch ( V_382 & V_398 ) {
case V_399 :
F_16 ( V_3 , L_250 ) ;
break;
case V_400 :
F_16 ( V_3 , L_251 ) ;
break;
case V_401 :
F_16 ( V_3 , L_252 ) ;
break;
case V_402 :
F_16 ( V_3 , L_253 ) ;
break;
case V_403 :
F_16 ( V_3 , L_254 ) ;
break;
case V_404 :
F_16 ( V_3 , L_255 ) ;
break;
case V_405 :
F_16 ( V_3 , L_256 ) ;
break;
default:
F_16 ( V_3 , L_151 ) ;
break;
}
F_16 ( V_3 , L_257 ) ;
switch ( V_382 & V_406 ) {
case V_407 :
F_16 ( V_3 , L_258 ) ;
break;
case V_408 :
F_16 ( V_3 , L_259 ) ;
break;
case V_409 :
F_16 ( V_3 , L_260 ) ;
break;
default:
F_16 ( V_3 , L_151 ) ;
break;
}
F_4 ( V_3 , L_261 ,
V_382 >> V_410 &
V_411 ) ;
F_4 ( V_3 , L_262 ,
V_382 >> V_412 &
V_413 ) ;
F_4 ( V_3 , L_263 ,
F_1 ( V_382 & V_414 ) ) ;
F_4 ( V_3 , L_264 ,
F_1 ( V_382 & V_415 ) ) ;
F_4 ( V_3 , L_265 ,
F_1 ( V_382 & V_416 ) ) ;
F_4 ( V_3 , L_266 ,
F_1 ( V_382 & V_417 ) ) ;
F_4 ( V_3 , L_267 ,
F_1 ( V_382 & V_418 ) ) ;
F_4 ( V_3 , L_268 ,
V_382 & V_419 ) ;
V_383 = ( F_54 ( V_420 ) ) & V_421 ;
F_4 ( V_3 , L_269 , V_383 ) ;
return 0 ;
}
static int F_143 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
T_9 V_422 ;
T_4 V_423 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return - V_316 ;
F_144 ( V_424 , V_422 ) ;
V_422 = ( V_422 & 0x1f00 ) >> 8 ;
V_423 = 1000000 / ( 1 << V_422 ) ;
V_422 = F_54 ( V_425 ) ;
V_422 *= V_423 ;
F_4 ( V_3 , L_270 , ( long long unsigned ) V_422 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_3 , void * V_175 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_52 * V_53 = V_9 -> V_54 ;
if ( ! F_85 ( V_9 ) ) {
F_16 ( V_3 , L_175 ) ;
return 0 ;
}
F_87 ( & V_53 -> V_426 . V_264 ) ;
F_4 ( V_3 , L_271 ,
F_1 ( V_53 -> V_426 . V_427 ) ) ;
F_4 ( V_3 , L_272 , F_1 ( V_53 -> V_426 . V_428 ) ) ;
F_4 ( V_3 , L_273 , V_53 -> V_426 . V_429 ) ;
F_4 ( V_3 , L_274 ,
F_1 ( V_53 -> V_426 . V_430 ) ) ;
F_4 ( V_3 , L_275 , F_1 ( V_53 -> V_426 . V_431 ) ) ;
F_19 ( & V_53 -> V_426 . V_264 ) ;
return 0 ;
}
static int
F_146 ( void * V_4 , T_9 * V_173 )
{
struct V_8 * V_9 = V_4 ;
T_5 * V_53 = V_9 -> V_54 ;
* V_173 = F_45 ( & V_53 -> V_432 . V_433 ) ;
return 0 ;
}
static int
F_147 ( void * V_4 , T_9 V_173 )
{
struct V_8 * V_9 = V_4 ;
F_148 ( L_276 , V_173 ) ;
F_149 ( V_9 , V_173 ) ;
return 0 ;
}
static int
F_150 ( void * V_4 , T_9 * V_173 )
{
struct V_8 * V_9 = V_4 ;
T_5 * V_53 = V_9 -> V_54 ;
* V_173 = V_53 -> V_432 . V_434 ;
return 0 ;
}
static int
F_151 ( void * V_4 , T_9 V_173 )
{
struct V_8 * V_9 = V_4 ;
struct V_52 * V_53 = V_9 -> V_54 ;
int V_60 ;
F_64 ( L_277 , V_173 ) ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_53 -> V_432 . V_434 = V_173 ;
F_19 ( & V_9 -> V_61 ) ;
return 0 ;
}
static int
F_152 ( void * V_4 , T_9 * V_173 )
{
* V_173 = V_435 ;
return 0 ;
}
static int
F_153 ( void * V_4 , T_9 V_173 )
{
struct V_8 * V_9 = V_4 ;
struct V_52 * V_53 = V_9 -> V_54 ;
struct V_14 * V_15 , * V_436 ;
struct V_55 * V_40 ;
struct V_23 * V_24 , * T_1 ;
int V_60 ;
F_64 ( L_278 , V_173 ) ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
if ( V_173 & V_437 ) {
V_60 = F_154 ( V_9 ) ;
if ( V_60 )
goto V_438;
}
if ( V_173 & ( V_439 | V_437 ) )
F_155 ( V_9 ) ;
if ( V_173 & V_440 ) {
F_14 (vm, &dev_priv->vm_list, global_link) {
F_156 (vma, x, &vm->inactive_list,
mm_list) {
if ( V_24 -> V_15 -> V_17 )
continue;
V_60 = F_157 ( V_24 ) ;
if ( V_60 )
goto V_438;
}
}
}
if ( V_173 & V_441 ) {
F_156 (obj, next, &dev_priv->mm.unbound_list,
global_list)
if ( V_15 -> V_442 == 0 ) {
V_60 = F_158 ( V_15 ) ;
if ( V_60 )
goto V_438;
}
}
V_438:
F_19 ( & V_9 -> V_61 ) ;
return V_60 ;
}
static int
F_159 ( void * V_4 , T_9 * V_173 )
{
struct V_8 * V_9 = V_4 ;
T_5 * V_53 = V_9 -> V_54 ;
int V_60 ;
if ( ! ( F_58 ( V_9 ) || F_59 ( V_9 ) ) )
return - V_316 ;
V_60 = F_18 ( & V_53 -> V_219 . V_222 ) ;
if ( V_60 )
return V_60 ;
if ( F_53 ( V_9 ) )
* V_173 = F_89 ( V_53 -> V_224 ,
V_53 -> V_219 . V_320 ) ;
else
* V_173 = V_53 -> V_219 . V_320 * V_204 ;
F_19 ( & V_53 -> V_219 . V_222 ) ;
return 0 ;
}
static int
F_160 ( void * V_4 , T_9 V_173 )
{
struct V_8 * V_9 = V_4 ;
struct V_52 * V_53 = V_9 -> V_54 ;
int V_60 ;
if ( ! ( F_58 ( V_9 ) || F_59 ( V_9 ) ) )
return - V_316 ;
F_64 ( L_279 , V_173 ) ;
V_60 = F_18 ( & V_53 -> V_219 . V_222 ) ;
if ( V_60 )
return V_60 ;
if ( F_53 ( V_9 ) ) {
V_173 = F_161 ( V_53 -> V_224 , V_173 ) ;
V_53 -> V_219 . V_320 = V_173 ;
F_162 ( V_9 , V_173 ) ;
} else {
F_163 ( V_173 , V_204 ) ;
V_53 -> V_219 . V_320 = V_173 ;
F_162 ( V_9 , V_173 ) ;
}
F_19 ( & V_53 -> V_219 . V_222 ) ;
return 0 ;
}
static int
F_164 ( void * V_4 , T_9 * V_173 )
{
struct V_8 * V_9 = V_4 ;
T_5 * V_53 = V_9 -> V_54 ;
int V_60 ;
if ( ! ( F_58 ( V_9 ) || F_59 ( V_9 ) ) )
return - V_316 ;
V_60 = F_18 ( & V_53 -> V_219 . V_222 ) ;
if ( V_60 )
return V_60 ;
if ( F_53 ( V_9 ) )
* V_173 = F_89 ( V_53 -> V_224 ,
V_53 -> V_219 . V_319 ) ;
else
* V_173 = V_53 -> V_219 . V_319 * V_204 ;
F_19 ( & V_53 -> V_219 . V_222 ) ;
return 0 ;
}
static int
F_165 ( void * V_4 , T_9 V_173 )
{
struct V_8 * V_9 = V_4 ;
struct V_52 * V_53 = V_9 -> V_54 ;
int V_60 ;
if ( ! ( F_58 ( V_9 ) || F_59 ( V_9 ) ) )
return - V_316 ;
F_64 ( L_280 , V_173 ) ;
V_60 = F_18 ( & V_53 -> V_219 . V_222 ) ;
if ( V_60 )
return V_60 ;
if ( F_53 ( V_9 ) ) {
V_173 = F_161 ( V_53 -> V_224 , V_173 ) ;
V_53 -> V_219 . V_319 = V_173 ;
F_166 ( V_9 , V_173 ) ;
} else {
F_163 ( V_173 , V_204 ) ;
V_53 -> V_219 . V_319 = V_173 ;
F_162 ( V_9 , V_173 ) ;
}
F_19 ( & V_53 -> V_219 . V_222 ) ;
return 0 ;
}
static int
F_167 ( void * V_4 , T_9 * V_173 )
{
struct V_8 * V_9 = V_4 ;
T_5 * V_53 = V_9 -> V_54 ;
T_4 V_443 ;
int V_60 ;
if ( ! ( F_58 ( V_9 ) || F_59 ( V_9 ) ) )
return - V_316 ;
V_60 = F_18 ( & V_9 -> V_61 ) ;
if ( V_60 )
return V_60 ;
V_443 = F_54 ( V_444 ) ;
F_19 ( & V_53 -> V_9 -> V_61 ) ;
* V_173 = ( V_443 & V_445 ) >> V_446 ;
return 0 ;
}
static int
F_168 ( void * V_4 , T_9 V_173 )
{
struct V_8 * V_9 = V_4 ;
struct V_52 * V_53 = V_9 -> V_54 ;
T_4 V_443 ;
if ( ! ( F_58 ( V_9 ) || F_59 ( V_9 ) ) )
return - V_316 ;
if ( V_173 > 3 )
return - V_66 ;
F_64 ( L_281 , V_173 ) ;
V_443 = F_54 ( V_444 ) ;
V_443 &= ~ V_445 ;
V_443 |= ( V_173 << V_446 ) ;
F_169 ( V_444 , V_443 ) ;
return 0 ;
}
static int
F_170 ( struct V_447 * V_10 ,
struct V_448 * V_449 ,
const void * V_450 )
{
struct V_5 * V_6 ;
V_6 = F_122 ( sizeof( struct V_5 ) , V_162 ) ;
if ( V_6 == NULL ) {
F_171 ( V_449 ) ;
return - V_163 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_451 = V_449 ;
V_6 -> V_49 = ( void * ) V_450 ;
F_87 ( & V_10 -> V_452 ) ;
F_24 ( & V_6 -> V_48 , & V_10 -> V_453 ) ;
F_19 ( & V_10 -> V_452 ) ;
return 0 ;
}
static int F_172 ( struct V_160 * V_160 , struct V_88 * V_88 )
{
struct V_8 * V_9 = V_160 -> V_161 ;
struct V_52 * V_53 = V_9 -> V_54 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_84 ( V_53 ) ;
return 0 ;
}
static int F_173 ( struct V_160 * V_160 , struct V_88 * V_88 )
{
struct V_8 * V_9 = V_160 -> V_161 ;
struct V_52 * V_53 = V_9 -> V_54 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_86 ( V_53 ) ;
return 0 ;
}
static int F_174 ( struct V_448 * V_454 , struct V_447 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_448 * V_449 ;
V_449 = F_175 ( L_282 ,
V_455 ,
V_454 , V_9 ,
& V_456 ) ;
if ( F_176 ( V_449 ) )
return F_177 ( V_449 ) ;
return F_170 ( V_10 , V_449 , & V_456 ) ;
}
static int F_178 ( struct V_448 * V_454 ,
struct V_447 * V_10 ,
const char * V_36 ,
const struct V_457 * V_458 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_448 * V_449 ;
V_449 = F_175 ( V_36 ,
V_459 | V_460 ,
V_454 , V_9 ,
V_458 ) ;
if ( F_176 ( V_449 ) )
return F_177 ( V_449 ) ;
return F_170 ( V_10 , V_449 , V_458 ) ;
}
int F_179 ( struct V_447 * V_10 )
{
int V_60 , V_117 ;
V_60 = F_174 ( V_10 -> V_461 , V_10 ) ;
if ( V_60 )
return V_60 ;
for ( V_117 = 0 ; V_117 < F_180 ( V_462 ) ; V_117 ++ ) {
V_60 = F_178 ( V_10 -> V_461 , V_10 ,
V_462 [ V_117 ] . V_36 ,
V_462 [ V_117 ] . V_458 ) ;
if ( V_60 )
return V_60 ;
}
return F_181 ( V_463 ,
V_464 ,
V_10 -> V_461 , V_10 ) ;
}
void F_182 ( struct V_447 * V_10 )
{
int V_117 ;
F_183 ( V_463 ,
V_464 , V_10 ) ;
F_183 ( (struct V_465 * ) & V_456 ,
1 , V_10 ) ;
for ( V_117 = 0 ; V_117 < F_180 ( V_462 ) ; V_117 ++ ) {
struct V_465 * V_466 =
(struct V_465 * ) V_462 [ V_117 ] . V_458 ;
F_183 ( V_466 , 1 , V_10 ) ;
}
}
