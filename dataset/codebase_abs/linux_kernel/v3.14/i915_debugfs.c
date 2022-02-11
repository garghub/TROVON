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
struct V_108 * V_109 ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
F_43 ( & V_101 -> V_110 , F_37 , & V_89 ) ;
F_44 () ;
V_109 = F_45 ( V_101 -> V_111 , V_112 ) ;
F_10 ( V_17 , L_40 ,
V_109 ? V_109 -> V_113 : L_41 ,
V_89 . V_72 ,
V_89 . V_90 ,
V_89 . V_92 ,
V_89 . V_93 ,
V_89 . V_95 ) ;
F_46 () ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_47 ( struct V_16 * V_17 , void * V_18 )
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
if ( V_14 == V_114 && V_26 -> V_28 == 0 )
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
static int F_48 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
unsigned long V_115 ;
struct V_116 * V_117 ;
F_20 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_118 = F_49 ( V_117 -> V_118 ) ;
const char V_119 = F_50 ( V_117 -> V_119 ) ;
struct V_120 * V_121 ;
F_51 ( & V_21 -> V_122 , V_115 ) ;
V_121 = V_117 -> V_123 ;
if ( V_121 == NULL ) {
F_10 ( V_17 , L_42 ,
V_118 , V_119 ) ;
} else {
if ( F_52 ( & V_121 -> V_124 ) < V_125 ) {
F_10 ( V_17 , L_43 ,
V_118 , V_119 ) ;
} else {
F_10 ( V_17 , L_44 ,
V_118 , V_119 ) ;
}
if ( V_121 -> V_126 )
F_22 ( V_17 , L_45 ) ;
else
F_22 ( V_17 , L_46 ) ;
F_10 ( V_17 , L_47 , F_52 ( & V_121 -> V_124 ) ) ;
if ( V_121 -> V_127 ) {
struct V_25 * V_26 = V_121 -> V_127 ;
if ( V_26 )
F_10 ( V_17 , L_48 ,
F_53 ( V_26 ) ) ;
}
if ( V_121 -> V_128 ) {
struct V_25 * V_26 = V_121 -> V_128 ;
if ( V_26 )
F_10 ( V_17 , L_49 ,
F_53 ( V_26 ) ) ;
}
}
F_54 ( & V_21 -> V_122 , V_115 ) ;
}
return 0 ;
}
static int F_55 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_129 * V_58 ;
struct V_130 * V_131 ;
int V_73 , V_72 , V_132 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_72 = 0 ;
F_56 (ring, dev_priv, i) {
if ( F_33 ( & V_58 -> V_133 ) )
continue;
F_10 ( V_17 , L_50 , V_58 -> V_47 ) ;
F_20 (gem_request,
&ring->request_list,
list) {
F_10 ( V_17 , L_51 ,
V_131 -> V_134 ,
( int ) ( V_135 - V_131 -> V_136 ) ) ;
}
V_72 ++ ;
}
F_7 ( & V_21 -> V_74 ) ;
if ( V_72 == 0 )
F_22 ( V_17 , L_52 ) ;
return 0 ;
}
static void F_57 ( struct V_16 * V_17 ,
struct V_129 * V_58 )
{
if ( V_58 -> V_137 ) {
F_10 ( V_17 , L_53 ,
V_58 -> V_47 , V_58 -> V_137 ( V_58 , false ) ) ;
}
}
static int F_58 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_129 * V_58 ;
int V_73 , V_132 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
F_56 (ring, dev_priv, i)
F_57 ( V_17 , V_58 ) ;
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_61 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_129 * V_58 ;
int V_73 , V_132 , V_118 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 ) {
int V_132 ;
F_10 ( V_17 , L_54 ,
F_62 ( V_138 ) ) ;
for ( V_132 = 0 ; V_132 < 4 ; V_132 ++ ) {
F_10 ( V_17 , L_55 ,
V_132 , F_62 ( F_63 ( V_132 ) ) ) ;
F_10 ( V_17 , L_56 ,
V_132 , F_62 ( F_64 ( V_132 ) ) ) ;
F_10 ( V_17 , L_57 ,
V_132 , F_62 ( F_65 ( V_132 ) ) ) ;
}
F_66 (i) {
F_10 ( V_17 , L_58 ,
F_49 ( V_132 ) ,
F_62 ( F_67 ( V_132 ) ) ) ;
F_10 ( V_17 , L_59 ,
F_49 ( V_132 ) ,
F_62 ( F_68 ( V_132 ) ) ) ;
F_10 ( V_17 , L_60 ,
F_49 ( V_132 ) ,
F_62 ( F_69 ( V_132 ) ) ) ;
}
F_10 ( V_17 , L_61 ,
F_62 ( V_139 ) ) ;
F_10 ( V_17 , L_62 ,
F_62 ( V_140 ) ) ;
F_10 ( V_17 , L_63 ,
F_62 ( V_141 ) ) ;
F_10 ( V_17 , L_64 ,
F_62 ( V_142 ) ) ;
F_10 ( V_17 , L_65 ,
F_62 ( V_143 ) ) ;
F_10 ( V_17 , L_66 ,
F_62 ( V_144 ) ) ;
F_10 ( V_17 , L_67 ,
F_62 ( V_145 ) ) ;
F_10 ( V_17 , L_68 ,
F_62 ( V_146 ) ) ;
F_10 ( V_17 , L_69 ,
F_62 ( V_147 ) ) ;
} else if ( F_70 ( V_21 ) ) {
F_10 ( V_17 , L_70 ,
F_62 ( V_148 ) ) ;
F_10 ( V_17 , L_71 ,
F_62 ( V_149 ) ) ;
F_10 ( V_17 , L_72 ,
F_62 ( V_150 ) ) ;
F_10 ( V_17 , L_73 ,
F_62 ( V_151 ) ) ;
F_66 (pipe)
F_10 ( V_17 , L_74 ,
F_49 ( V_118 ) ,
F_62 ( F_71 ( V_118 ) ) ) ;
F_10 ( V_17 , L_75 ,
F_62 ( V_152 ) ) ;
F_10 ( V_17 , L_76 ,
F_62 ( V_153 ) ) ;
F_10 ( V_17 , L_77 ,
F_62 ( V_154 ) ) ;
F_10 ( V_17 , L_78 ,
F_62 ( V_155 ) ) ;
F_10 ( V_17 , L_79 ,
F_62 ( V_156 ) ) ;
F_10 ( V_17 , L_80 ,
F_62 ( V_157 ) ) ;
F_10 ( V_17 , L_81 ,
F_62 ( V_158 ) ) ;
F_10 ( V_17 , L_82 ,
F_62 ( V_159 ) ) ;
F_10 ( V_17 , L_83 ,
F_62 ( V_160 ) ) ;
F_10 ( V_17 , L_84 ,
F_62 ( V_161 ) ) ;
} else if ( ! F_72 ( V_21 ) ) {
F_10 ( V_17 , L_85 ,
F_62 ( V_162 ) ) ;
F_10 ( V_17 , L_86 ,
F_62 ( V_163 ) ) ;
F_10 ( V_17 , L_87 ,
F_62 ( V_164 ) ) ;
F_66 (pipe)
F_10 ( V_17 , L_88 ,
F_49 ( V_118 ) ,
F_62 ( F_71 ( V_118 ) ) ) ;
} else {
F_10 ( V_17 , L_89 ,
F_62 ( V_165 ) ) ;
F_10 ( V_17 , L_90 ,
F_62 ( V_166 ) ) ;
F_10 ( V_17 , L_91 ,
F_62 ( V_167 ) ) ;
F_10 ( V_17 , L_92 ,
F_62 ( V_168 ) ) ;
F_10 ( V_17 , L_93 ,
F_62 ( V_169 ) ) ;
F_10 ( V_17 , L_94 ,
F_62 ( V_170 ) ) ;
F_10 ( V_17 , L_95 ,
F_62 ( V_153 ) ) ;
F_10 ( V_17 , L_96 ,
F_62 ( V_154 ) ) ;
F_10 ( V_17 , L_97 ,
F_62 ( V_155 ) ) ;
}
F_10 ( V_17 , L_98 ,
F_52 ( & V_66 -> V_171 ) ) ;
F_56 (ring, dev_priv, i) {
if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 ,
L_99 ,
V_58 -> V_47 , F_73 ( V_58 ) ) ;
}
F_57 ( V_17 , V_58 ) ;
}
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_74 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_132 , V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_100 , V_66 -> V_172 ) ;
F_10 ( V_17 , L_101 , V_66 -> V_173 ) ;
for ( V_132 = 0 ; V_132 < V_66 -> V_173 ; V_132 ++ ) {
struct V_25 * V_26 = V_66 -> V_174 [ V_132 ] . V_26 ;
F_10 ( V_17 , L_102 ,
V_132 , V_66 -> V_174 [ V_132 ] . V_28 ) ;
if ( V_26 == NULL )
F_22 ( V_17 , L_103 ) ;
else
F_18 ( V_17 , V_26 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_75 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_129 * V_58 ;
const T_4 * V_175 ;
int V_132 ;
V_58 = & V_66 -> V_58 [ ( T_2 ) V_8 -> V_12 -> V_18 ] ;
V_175 = V_58 -> V_176 . V_177 ;
if ( V_175 == NULL )
return 0 ;
for ( V_132 = 0 ; V_132 < 4096 / sizeof( T_4 ) / 4 ; V_132 += 4 ) {
F_10 ( V_17 , L_104 ,
V_132 * 4 ,
V_175 [ V_132 ] , V_175 [ V_132 + 1 ] , V_175 [ V_132 + 2 ] , V_175 [ V_132 + 3 ] ) ;
}
return 0 ;
}
static T_6
F_76 ( struct V_101 * V_178 ,
const char T_7 * V_179 ,
T_3 V_180 ,
T_8 * V_181 )
{
struct V_182 * V_183 = V_178 -> V_184 ;
struct V_20 * V_21 = V_183 -> V_21 ;
int V_73 ;
F_77 ( L_105 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_78 ( V_21 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_180 ;
}
static int F_79 ( struct V_185 * V_185 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_185 -> V_186 ;
struct V_182 * V_183 ;
V_183 = F_80 ( sizeof( * V_183 ) , V_9 ) ;
if ( ! V_183 )
return - V_10 ;
V_183 -> V_21 = V_21 ;
F_81 ( V_21 , V_183 ) ;
V_101 -> V_184 = V_183 ;
return 0 ;
}
static int F_82 ( struct V_185 * V_185 , struct V_101 * V_101 )
{
struct V_182 * V_183 = V_101 -> V_184 ;
F_83 ( V_183 ) ;
F_84 ( V_183 ) ;
return 0 ;
}
static T_6 F_85 ( struct V_101 * V_101 , char T_7 * V_187 ,
T_3 V_72 , T_8 * V_188 )
{
struct V_182 * V_183 = V_101 -> V_184 ;
struct V_189 V_190 ;
T_8 V_191 = 0 ;
T_6 V_192 = 0 ;
int V_73 ;
V_73 = F_86 ( & V_190 , V_72 , * V_188 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_87 ( & V_190 , V_183 ) ;
if ( V_73 )
goto V_193;
V_192 = F_88 ( V_187 , V_72 , & V_191 ,
V_190 . V_194 ,
V_190 . V_195 ) ;
if ( V_192 < 0 )
V_73 = V_192 ;
else
* V_188 = V_190 . V_52 + V_192 ;
V_193:
F_89 ( & V_190 ) ;
return V_73 ? : V_192 ;
}
static int
F_90 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
* V_196 = V_66 -> V_197 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_91 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_92 ( V_21 , V_196 ) ;
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int F_93 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_10 V_199 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
V_199 = F_94 ( V_200 ) ;
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_106 , ( V_199 >> 8 ) & 0x3f , ( V_199 & 0x3f ) ) ;
return 0 ;
}
static int F_95 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 = 0 ;
F_59 ( V_66 ) ;
F_96 ( & V_66 -> V_201 . V_202 ) ;
if ( F_97 ( V_21 ) ) {
T_10 V_203 = F_94 ( V_204 ) ;
T_10 V_205 = F_94 ( V_206 ) ;
F_10 ( V_17 , L_107 , ( V_203 >> 8 ) & 0xf ) ;
F_10 ( V_17 , L_108 , V_203 & 0x3f ) ;
F_10 ( V_17 , L_109 , ( V_205 & V_207 ) >>
V_208 ) ;
F_10 ( V_17 , L_110 ,
( V_205 & V_209 ) >> V_210 ) ;
} else if ( ( F_98 ( V_21 ) || F_99 ( V_21 ) ) && ! F_70 ( V_21 ) ) {
T_4 V_211 = F_62 ( V_212 ) ;
T_4 V_213 = F_62 ( V_214 ) ;
T_4 V_215 = F_62 ( V_216 ) ;
T_4 V_217 , V_218 , V_219 ;
T_4 V_220 , V_221 , V_222 ;
T_4 V_223 , V_224 , V_225 ;
int V_226 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_193;
F_100 ( V_66 , V_227 ) ;
V_219 = F_62 ( V_228 ) ;
V_219 &= ~ V_229 ;
if ( F_101 ( V_21 ) )
V_219 >>= 24 ;
else
V_219 >>= 25 ;
V_219 *= V_230 ;
V_217 = F_62 ( V_231 ) ;
V_220 = F_62 ( V_232 ) ;
V_221 = F_62 ( V_233 ) ;
V_222 = F_62 ( V_234 ) ;
V_223 = F_62 ( V_235 ) ;
V_224 = F_62 ( V_236 ) ;
V_225 = F_62 ( V_237 ) ;
if ( F_101 ( V_21 ) )
V_218 = ( V_217 & V_238 ) >> V_239 ;
else
V_218 = ( V_217 & V_240 ) >> V_241 ;
V_218 *= V_230 ;
F_102 ( V_66 , V_227 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_111 , V_211 ) ;
F_10 ( V_17 , L_112 , V_217 ) ;
F_10 ( V_17 , L_113 ,
( V_211 & 0xff00 ) >> 8 ) ;
F_10 ( V_17 , L_114 ,
V_211 & 0xff ) ;
F_10 ( V_17 , L_115 ,
V_213 & 0xff ) ;
F_10 ( V_17 , L_116 , V_219 ) ;
F_10 ( V_17 , L_117 , V_218 ) ;
F_10 ( V_17 , L_118 , V_220 &
V_242 ) ;
F_10 ( V_17 , L_119 , V_221 &
V_243 ) ;
F_10 ( V_17 , L_120 , V_222 &
V_243 ) ;
F_10 ( V_17 , L_121 , V_223 &
V_244 ) ;
F_10 ( V_17 , L_122 , V_224 &
V_243 ) ;
F_10 ( V_17 , L_123 , V_225 &
V_243 ) ;
V_226 = ( V_215 & 0xff0000 ) >> 16 ;
F_10 ( V_17 , L_124 ,
V_226 * V_230 ) ;
V_226 = ( V_215 & 0xff00 ) >> 8 ;
F_10 ( V_17 , L_125 ,
V_226 * V_230 ) ;
V_226 = V_215 & 0xff ;
F_10 ( V_17 , L_126 ,
V_226 * V_230 ) ;
F_10 ( V_17 , L_127 ,
V_66 -> V_201 . V_245 * V_230 ) ;
} else if ( F_70 ( V_21 ) ) {
T_4 V_246 , V_196 ;
F_5 ( & V_66 -> V_201 . V_247 ) ;
V_246 = F_103 ( V_66 , V_248 ) ;
F_10 ( V_17 , L_128 , V_246 ) ;
F_10 ( V_17 , L_129 , V_66 -> V_249 ) ;
V_196 = F_104 ( V_66 ) ;
F_10 ( V_17 , L_130 ,
F_105 ( V_66 , V_196 ) ) ;
V_196 = F_106 ( V_66 ) ;
F_10 ( V_17 , L_131 ,
F_105 ( V_66 , V_196 ) ) ;
F_10 ( V_17 , L_132 ,
F_105 ( V_66 , ( V_246 >> 8 ) & 0xff ) ) ;
F_7 ( & V_66 -> V_201 . V_247 ) ;
} else {
F_22 ( V_17 , L_133 ) ;
}
V_193:
F_60 ( V_66 ) ;
return V_73 ;
}
static int F_107 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_250 ;
int V_73 , V_132 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
for ( V_132 = 0 ; V_132 < 16 ; V_132 ++ ) {
V_250 = F_62 ( V_251 + V_132 * 4 ) ;
F_10 ( V_17 , L_134 , V_132 , V_250 ,
( V_250 & V_252 ) >> V_253 ) ;
}
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static inline int F_108 ( int V_254 )
{
return 1250 - ( V_254 * 25 ) ;
}
static int F_109 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_255 ;
int V_73 , V_132 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
for ( V_132 = 1 ; V_132 <= 32 ; V_132 ++ ) {
V_255 = F_62 ( V_256 + V_132 * 4 ) ;
F_10 ( V_17 , L_135 , V_132 , V_255 ) ;
}
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_110 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_257 , V_258 ;
T_10 V_259 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
V_257 = F_62 ( V_260 ) ;
V_258 = F_62 ( V_261 ) ;
V_259 = F_94 ( V_200 ) ;
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_136 , ( V_257 & V_262 ) ?
L_1 : L_2 ) ;
F_10 ( V_17 , L_137 ,
( V_257 & V_263 ) >>
V_264 ) ;
F_10 ( V_17 , L_138 ,
V_257 & V_265 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_139 ,
V_257 & V_266 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_140 ,
V_257 & V_267 ? L_1 : L_2 ) ;
F_10 ( V_17 , L_141 ,
( V_257 & V_268 ) >> V_269 ) ;
F_10 ( V_17 , L_142 ,
( V_257 & V_270 ) >> V_271 ) ;
F_10 ( V_17 , L_143 , ( V_257 & V_272 ) ) ;
F_10 ( V_17 , L_144 , ( V_259 & 0x3f ) ) ;
F_10 ( V_17 , L_145 , ( ( V_259 >> 8 ) & 0x3f ) ) ;
F_10 ( V_17 , L_146 ,
( V_258 & V_273 ) ? L_2 : L_1 ) ;
F_22 ( V_17 , L_147 ) ;
switch ( V_258 & V_274 ) {
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
case V_280 :
F_22 ( V_17 , L_153 ) ;
break;
default:
F_22 ( V_17 , L_154 ) ;
break;
}
return 0 ;
}
static int F_111 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_281 , V_282 ;
unsigned V_283 = 0 , V_284 = 0 ;
V_281 = F_62 ( V_285 ) ;
V_282 = F_62 ( V_286 ) ;
F_10 ( V_17 , L_155 ,
F_1 ( V_281 & V_287 ) ) ;
F_10 ( V_17 , L_156 ,
F_1 ( V_281 & V_288 ) ) ;
F_10 ( V_17 , L_138 ,
F_1 ( V_281 & V_288 ) ) ;
F_10 ( V_17 , L_139 ,
F_1 ( ( V_281 & V_289 ) ==
V_290 ) ) ;
F_10 ( V_17 , L_157 ,
F_1 ( V_282 & ( V_291 |
F_112 ( 1 ) ) ) ) ;
F_10 ( V_17 , L_158 ,
( F_62 ( V_292 ) &
V_293 ) ? L_159 : L_160 ) ;
F_10 ( V_17 , L_161 ,
( F_62 ( V_292 ) &
V_294 ) ? L_159 : L_160 ) ;
F_113 ( & V_66 -> V_295 . V_296 ) ;
V_283 = V_66 -> V_295 . V_283 ;
V_284 = V_66 -> V_295 . V_284 ;
F_114 ( & V_66 -> V_295 . V_296 ) ;
F_10 ( V_17 , L_162 , V_283 ) ;
F_10 ( V_17 , L_163 , V_284 ) ;
return 0 ;
}
static int F_115 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_281 , V_297 , V_282 , V_298 = 0 ;
unsigned V_299 ;
int V_72 = 0 , V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
F_113 ( & V_66 -> V_295 . V_296 ) ;
V_299 = V_66 -> V_295 . V_299 ;
F_114 ( & V_66 -> V_295 . V_296 ) ;
if ( V_299 ) {
F_22 ( V_17 , L_164
L_165 ) ;
} else {
while ( V_72 ++ < 50 && ( F_116 ( V_300 ) & 1 ) )
F_117 ( 10 ) ;
F_10 ( V_17 , L_166 , F_1 ( V_72 < 51 ) ) ;
}
V_297 = F_118 ( V_66 -> V_301 + V_302 ) ;
F_119 ( false , V_302 , V_297 , 4 , true ) ;
V_281 = F_62 ( V_285 ) ;
V_282 = F_62 ( V_286 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_5 ( & V_66 -> V_201 . V_247 ) ;
F_120 ( V_66 , V_303 , & V_298 ) ;
F_7 ( & V_66 -> V_201 . V_247 ) ;
F_60 ( V_66 ) ;
F_10 ( V_17 , L_155 ,
F_1 ( V_281 & V_287 ) ) ;
F_10 ( V_17 , L_138 ,
F_1 ( V_281 & V_288 ) ) ;
F_10 ( V_17 , L_139 ,
F_1 ( ( V_281 & V_289 ) ==
V_290 ) ) ;
F_10 ( V_17 , L_167 ,
F_1 ( V_282 & V_304 ) ) ;
F_10 ( V_17 , L_157 ,
F_1 ( V_282 & V_305 ) ) ;
F_10 ( V_17 , L_168 ,
F_1 ( V_282 & V_306 ) ) ;
F_10 ( V_17 , L_169 ,
F_1 ( V_282 & V_307 ) ) ;
F_22 ( V_17 , L_170 ) ;
switch ( V_297 & V_308 ) {
case V_309 :
if ( V_297 & V_310 )
F_22 ( V_17 , L_171 ) ;
else
F_22 ( V_17 , L_148 ) ;
break;
case V_311 :
F_22 ( V_17 , L_172 ) ;
break;
case V_312 :
F_22 ( V_17 , L_173 ) ;
break;
case V_313 :
F_22 ( V_17 , L_174 ) ;
break;
default:
F_22 ( V_17 , L_175 ) ;
break;
}
F_10 ( V_17 , L_176 ,
F_1 ( V_297 & V_310 ) ) ;
F_10 ( V_17 , L_177 ,
F_62 ( V_314 ) ) ;
F_10 ( V_17 , L_178 ,
F_62 ( V_315 ) ) ;
F_10 ( V_17 , L_179 ,
F_62 ( V_316 ) ) ;
F_10 ( V_17 , L_180 ,
F_62 ( V_317 ) ) ;
F_10 ( V_17 , L_181 ,
F_121 ( ( ( V_298 >> 0 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_182 ,
F_121 ( ( ( V_298 >> 8 ) & 0xff ) ) ) ;
F_10 ( V_17 , L_183 ,
F_121 ( ( ( V_298 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_122 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
if ( F_70 ( V_21 ) )
return F_111 ( V_17 ) ;
else if ( F_98 ( V_21 ) || F_99 ( V_21 ) )
return F_115 ( V_17 ) ;
else
return F_110 ( V_17 ) ;
}
static int F_123 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
if ( ! F_124 ( V_21 ) ) {
F_22 ( V_17 , L_184 ) ;
return 0 ;
}
if ( F_125 ( V_21 ) ) {
F_22 ( V_17 , L_185 ) ;
} else {
F_22 ( V_17 , L_186 ) ;
switch ( V_66 -> V_318 . V_319 ) {
case V_320 :
F_22 ( V_17 , L_187 ) ;
break;
case V_321 :
F_22 ( V_17 , L_188 ) ;
break;
case V_322 :
F_22 ( V_17 , L_189 ) ;
break;
case V_323 :
F_22 ( V_17 , L_190 ) ;
break;
case V_324 :
F_22 ( V_17 , L_191 ) ;
break;
case V_325 :
F_22 ( V_17 , L_192 ) ;
break;
case V_326 :
F_22 ( V_17 , L_193 ) ;
break;
case V_327 :
F_22 ( V_17 , L_194 ) ;
break;
case V_328 :
F_22 ( V_17 , L_195 ) ;
break;
case V_329 :
F_22 ( V_17 , L_196 ) ;
break;
case V_330 :
F_22 ( V_17 , L_197 ) ;
break;
default:
F_22 ( V_17 , L_198 ) ;
}
F_24 ( V_17 , '\n' ) ;
}
return 0 ;
}
static int F_126 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_127 ( V_21 ) ) {
F_22 ( V_17 , L_199 ) ;
return 0 ;
}
if ( F_128 ( V_21 ) || F_62 ( V_331 ) & V_332 )
F_22 ( V_17 , L_200 ) ;
else
F_22 ( V_17 , L_201 ) ;
return 0 ;
}
static int F_129 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
bool V_333 = false ;
if ( F_72 ( V_21 ) )
V_333 = F_62 ( V_334 ) & V_335 ;
else if ( F_130 ( V_21 ) || F_131 ( V_21 ) || F_132 ( V_21 ) )
V_333 = F_62 ( V_336 ) & V_337 ;
else if ( F_133 ( V_21 ) )
V_333 = F_62 ( V_338 ) & V_339 ;
else if ( F_134 ( V_21 ) )
V_333 = F_62 ( V_340 ) & V_341 ;
F_10 ( V_17 , L_202 ,
V_333 ? L_203 : L_204 ) ;
return 0 ;
}
static int F_135 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
unsigned long V_342 , V_343 , V_344 ;
int V_73 ;
if ( ! F_97 ( V_21 ) )
return - V_345 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_342 = F_136 ( V_66 ) ;
V_343 = F_137 ( V_66 ) ;
V_344 = F_138 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
F_10 ( V_17 , L_205 , V_342 ) ;
F_10 ( V_17 , L_206 , V_343 ) ;
F_10 ( V_17 , L_207 , V_344 ) ;
F_10 ( V_17 , L_208 , V_343 + V_344 ) ;
return 0 ;
}
static int F_139 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
int V_346 , V_347 ;
if ( ! ( F_98 ( V_21 ) || F_99 ( V_21 ) ) ) {
F_22 ( V_17 , L_209 ) ;
return 0 ;
}
F_96 ( & V_66 -> V_201 . V_202 ) ;
V_73 = F_26 ( & V_66 -> V_201 . V_247 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
F_22 ( V_17 , L_210 ) ;
for ( V_346 = V_66 -> V_201 . V_348 ;
V_346 <= V_66 -> V_201 . V_349 ;
V_346 ++ ) {
V_347 = V_346 ;
F_120 ( V_66 ,
V_350 ,
& V_347 ) ;
F_10 ( V_17 , L_211 ,
V_346 * V_230 ,
( ( V_347 >> 0 ) & 0xff ) * 100 ,
( ( V_347 >> 8 ) & 0xff ) * 100 ) ;
}
F_60 ( V_66 ) ;
F_7 ( & V_66 -> V_201 . V_247 ) ;
return 0 ;
}
static int F_140 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
F_10 ( V_17 , L_212 , ( unsigned long ) F_62 ( 0x112f4 ) ) ;
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_141 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_351 * V_352 = & V_66 -> V_352 ;
void * V_18 = F_3 ( V_353 , V_9 ) ;
int V_73 ;
if ( V_18 == NULL )
return - V_10 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
goto V_193;
if ( V_352 -> V_354 ) {
F_142 ( V_18 , V_352 -> V_354 , V_353 ) ;
F_143 ( V_17 , V_18 , V_353 ) ;
}
F_7 ( & V_21 -> V_74 ) ;
V_193:
F_84 ( V_18 ) ;
return 0 ;
}
static int F_144 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_355 * V_356 = NULL ;
struct V_357 * V_358 ;
#ifdef F_145
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_26 ( & V_21 -> V_359 . V_360 ) ;
if ( V_73 )
return V_73 ;
V_356 = V_66 -> V_361 ;
V_358 = F_146 ( V_356 -> V_362 . V_358 ) ;
F_10 ( V_17 , L_213 ,
V_358 -> V_36 . V_363 ,
V_358 -> V_36 . V_364 ,
V_358 -> V_36 . V_365 ,
V_358 -> V_36 . V_366 ,
F_52 ( & V_358 -> V_36 . V_367 . V_367 ) ) ;
F_18 ( V_17 , V_358 -> V_26 ) ;
F_24 ( V_17 , '\n' ) ;
F_7 ( & V_21 -> V_359 . V_360 ) ;
#endif
F_5 ( & V_21 -> V_359 . V_368 ) ;
F_20 (fb, &dev->mode_config.fb_list, base.head) {
if ( V_356 && & V_358 -> V_36 == V_356 -> V_362 . V_358 )
continue;
F_10 ( V_17 , L_214 ,
V_358 -> V_36 . V_363 ,
V_358 -> V_36 . V_364 ,
V_358 -> V_36 . V_365 ,
V_358 -> V_36 . V_366 ,
F_52 ( & V_358 -> V_36 . V_367 . V_367 ) ) ;
F_18 ( V_17 , V_358 -> V_26 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_359 . V_368 ) ;
return 0 ;
}
static int F_147 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
T_5 * V_66 = V_21 -> V_67 ;
struct V_129 * V_58 ;
struct V_59 * V_60 ;
int V_73 , V_132 ;
V_73 = F_26 ( & V_21 -> V_359 . V_360 ) ;
if ( V_73 )
return V_73 ;
if ( V_66 -> V_369 . V_370 ) {
F_22 ( V_17 , L_215 ) ;
F_18 ( V_17 , V_66 -> V_369 . V_370 ) ;
F_24 ( V_17 , '\n' ) ;
}
if ( V_66 -> V_369 . V_371 ) {
F_22 ( V_17 , L_216 ) ;
F_18 ( V_17 , V_66 -> V_369 . V_371 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_20 (ctx, &dev_priv->context_list, link) {
F_22 ( V_17 , L_217 ) ;
F_23 ( V_17 , V_60 ) ;
F_56 (ring, dev_priv, i)
if ( V_58 -> V_372 == V_60 )
F_10 ( V_17 , L_218 , V_58 -> V_47 ) ;
F_18 ( V_17 , V_60 -> V_26 ) ;
F_24 ( V_17 , '\n' ) ;
}
F_7 ( & V_21 -> V_359 . V_360 ) ;
return 0 ;
}
static int F_148 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
unsigned V_299 = 0 , V_283 = 0 , V_284 = 0 ;
F_113 ( & V_66 -> V_295 . V_296 ) ;
if ( F_70 ( V_21 ) ) {
V_283 = V_66 -> V_295 . V_283 ;
V_284 = V_66 -> V_295 . V_284 ;
} else
V_299 = V_66 -> V_295 . V_299 ;
F_114 ( & V_66 -> V_295 . V_296 ) ;
if ( F_70 ( V_21 ) ) {
F_10 ( V_17 , L_219 , V_283 ) ;
F_10 ( V_17 , L_220 , V_284 ) ;
} else
F_10 ( V_17 , L_221 , V_299 ) ;
return 0 ;
}
static const char * F_149 ( unsigned V_373 )
{
switch ( V_373 ) {
case V_374 :
return L_222 ;
case V_375 :
return L_223 ;
case V_376 :
return L_224 ;
case V_377 :
return L_225 ;
case V_378 :
return L_226 ;
case V_379 :
return L_227 ;
case V_380 :
return L_228 ;
case V_381 :
return L_229 ;
}
return L_230 ;
}
static int F_150 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
F_10 ( V_17 , L_231 ,
F_149 ( V_66 -> V_102 . V_382 ) ) ;
F_10 ( V_17 , L_232 ,
F_149 ( V_66 -> V_102 . V_383 ) ) ;
if ( F_151 ( V_21 ) || F_152 ( V_21 ) ) {
F_10 ( V_17 , L_233 ,
F_62 ( V_384 ) ) ;
F_10 ( V_17 , L_234 ,
F_94 ( V_385 ) ) ;
F_10 ( V_17 , L_235 ,
F_94 ( V_386 ) ) ;
} else if ( F_9 ( V_21 ) -> V_24 >= 6 ) {
F_10 ( V_17 , L_236 ,
F_62 ( V_387 ) ) ;
F_10 ( V_17 , L_237 ,
F_62 ( V_388 ) ) ;
F_10 ( V_17 , L_238 ,
F_62 ( V_389 ) ) ;
F_10 ( V_17 , L_239 ,
F_62 ( V_390 ) ) ;
if ( F_153 ( V_21 ) )
F_10 ( V_17 , L_240 ,
F_62 ( V_391 ) ) ;
else
F_10 ( V_17 , L_241 ,
F_62 ( V_392 ) ) ;
F_10 ( V_17 , L_242 ,
F_62 ( V_393 ) ) ;
}
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static void F_154 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_129 * V_58 ;
struct V_394 * V_395 = V_66 -> V_102 . V_396 ;
int V_198 , V_132 ;
if ( ! V_395 )
return;
F_10 ( V_17 , L_243 , V_395 -> V_397 ) ;
F_10 ( V_17 , L_244 , V_395 -> V_398 ) ;
F_56 (ring, dev_priv, unused) {
F_10 ( V_17 , L_245 , V_58 -> V_47 ) ;
for ( V_132 = 0 ; V_132 < 4 ; V_132 ++ ) {
T_4 V_399 = 0x270 + V_132 * 8 ;
T_9 V_400 = F_62 ( V_58 -> V_401 + V_399 + 4 ) ;
V_400 <<= 32 ;
V_400 |= F_62 ( V_58 -> V_401 + V_399 ) ;
for ( V_132 = 0 ; V_132 < 4 ; V_132 ++ )
F_10 ( V_17 , L_246 , V_132 , V_400 ) ;
}
}
}
static void F_155 ( struct V_16 * V_17 , struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_129 * V_58 ;
int V_132 ;
if ( F_9 ( V_21 ) -> V_24 == 6 )
F_10 ( V_17 , L_247 , F_62 ( V_402 ) ) ;
F_56 (ring, dev_priv, i) {
F_10 ( V_17 , L_245 , V_58 -> V_47 ) ;
if ( F_9 ( V_21 ) -> V_24 == 7 )
F_10 ( V_17 , L_247 , F_62 ( F_156 ( V_58 ) ) ) ;
F_10 ( V_17 , L_248 , F_62 ( F_157 ( V_58 ) ) ) ;
F_10 ( V_17 , L_249 , F_62 ( F_158 ( V_58 ) ) ) ;
F_10 ( V_17 , L_250 , F_62 ( F_159 ( V_58 ) ) ) ;
}
if ( V_66 -> V_102 . V_396 ) {
struct V_394 * V_395 = V_66 -> V_102 . V_396 ;
F_22 ( V_17 , L_251 ) ;
F_10 ( V_17 , L_252 , V_395 -> V_403 ) ;
}
F_10 ( V_17 , L_253 , F_62 ( V_404 ) ) ;
}
static int F_160 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
if ( F_9 ( V_21 ) -> V_24 >= 8 )
F_154 ( V_17 , V_21 ) ;
else if ( F_9 ( V_21 ) -> V_24 >= 6 )
F_155 ( V_17 , V_21 ) ;
F_60 ( V_66 ) ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int F_161 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! F_70 ( V_21 ) ) {
F_22 ( V_17 , L_254 ) ;
return 0 ;
}
V_73 = F_26 ( & V_66 -> V_405 ) ;
if ( V_73 )
return V_73 ;
F_10 ( V_17 , L_255 , F_62 ( V_406 ) ) ;
F_10 ( V_17 , L_256 ,
F_162 ( V_66 , V_407 , F_163 ( 0 ) ) ) ;
F_10 ( V_17 , L_257 ,
F_162 ( V_66 , V_407 , F_163 ( 1 ) ) ) ;
F_10 ( V_17 , L_258 ,
F_162 ( V_66 , V_407 , F_164 ( 0 ) ) ) ;
F_10 ( V_17 , L_259 ,
F_162 ( V_66 , V_407 , F_164 ( 1 ) ) ) ;
F_10 ( V_17 , L_260 ,
F_162 ( V_66 , V_407 , F_165 ( 0 ) ) ) ;
F_10 ( V_17 , L_261 ,
F_162 ( V_66 , V_407 , F_165 ( 1 ) ) ) ;
F_10 ( V_17 , L_262 ,
F_162 ( V_66 , V_407 , F_166 ( 0 ) ) ) ;
F_10 ( V_17 , L_263 ,
F_162 ( V_66 , V_407 , F_166 ( 1 ) ) ) ;
F_10 ( V_17 , L_264 ,
F_162 ( V_66 , V_407 , V_408 ) ) ;
F_7 ( & V_66 -> V_405 ) ;
return 0 ;
}
static int F_167 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
F_10 ( V_17 , L_265 , F_1 ( F_168 ( V_21 ) ) ) ;
F_10 ( V_17 , L_266 , V_66 -> V_409 ) ;
return 0 ;
}
static int F_169 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_410 = 0 ;
bool V_411 = false ;
F_59 ( V_66 ) ;
F_10 ( V_17 , L_267 , F_1 ( V_66 -> V_412 . V_413 ) ) ;
F_10 ( V_17 , L_268 , F_1 ( V_66 -> V_412 . V_414 ) ) ;
V_411 = F_170 ( V_21 ) &&
F_62 ( F_171 ( V_21 ) ) & V_415 ;
F_10 ( V_17 , L_269 , F_1 ( V_411 ) ) ;
if ( F_170 ( V_21 ) )
V_410 = F_62 ( F_172 ( V_21 ) ) &
V_416 ;
F_10 ( V_17 , L_270 , V_410 ) ;
F_60 ( V_66 ) ;
return 0 ;
}
static int F_173 ( struct V_16 * V_17 , void * V_18 )
{
struct V_7 * V_8 = V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_9 V_417 ;
T_4 V_418 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return - V_345 ;
F_174 ( V_419 , V_417 ) ;
V_417 = ( V_417 & 0x1f00 ) >> 8 ;
V_418 = 1000000 / ( 1 << V_417 ) ;
V_417 = F_62 ( V_420 ) ;
V_417 *= V_418 ;
F_10 ( V_17 , L_271 , ( long long unsigned ) V_417 ) ;
return 0 ;
}
static int F_175 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( ! F_101 ( V_21 ) ) {
F_22 ( V_17 , L_199 ) ;
return 0 ;
}
F_5 ( & V_66 -> V_421 . V_296 ) ;
F_10 ( V_17 , L_272 ,
F_1 ( V_66 -> V_421 . V_422 ) ) ;
F_10 ( V_17 , L_273 , F_1 ( V_66 -> V_421 . V_423 ) ) ;
F_10 ( V_17 , L_274 , V_66 -> V_421 . V_424 ) ;
F_10 ( V_17 , L_275 ,
F_1 ( V_66 -> V_421 . V_425 ) ) ;
F_10 ( V_17 , L_269 , F_1 ( V_66 -> V_421 . V_411 ) ) ;
F_7 ( & V_66 -> V_421 . V_296 ) ;
return 0 ;
}
static const char * F_176 ( enum V_426 V_427 )
{
switch ( V_427 ) {
case V_428 :
return L_276 ;
case V_429 :
return L_277 ;
case V_430 :
return L_278 ;
case V_431 :
return L_279 ;
case V_432 :
return L_280 ;
case V_433 :
return L_281 ;
case V_434 :
return L_282 ;
case V_435 :
return L_283 ;
case V_436 :
return L_284 ;
case V_437 :
return L_285 ;
case V_438 :
return L_286 ;
case V_439 :
return L_287 ;
case V_440 :
return L_288 ;
default:
F_177 ( 1 ) ;
return L_289 ;
}
}
static int F_178 ( struct V_16 * V_17 , void * V_198 )
{
struct V_7 * V_8 = (struct V_7 * ) V_17 -> V_19 ;
struct V_20 * V_21 = V_8 -> V_3 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_441 * V_442 = & V_66 -> V_442 ;
int V_132 ;
F_5 ( & V_442 -> V_296 ) ;
F_10 ( V_17 , L_290 , L_291 , L_292 ) ;
for ( V_132 = 0 ; V_132 < V_442 -> V_443 ; V_132 ++ ) {
struct V_444 * V_445 ;
enum V_426 V_446 ;
V_445 = & V_442 -> V_447 [ V_132 ] ;
F_10 ( V_17 , L_293 , V_445 -> V_47 ,
V_445 -> V_72 ) ;
for ( V_446 = 0 ; V_446 < V_448 ;
V_446 ++ ) {
if ( ! ( F_179 ( V_446 ) & V_445 -> V_449 ) )
continue;
F_10 ( V_17 , L_294 ,
F_176 ( V_446 ) ,
V_442 -> V_450 [ V_446 ] ) ;
}
}
F_7 ( & V_442 -> V_296 ) ;
return 0 ;
}
static int F_180 ( struct V_185 * V_185 , struct V_101 * V_451 )
{
struct V_452 * V_23 = V_185 -> V_186 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_453 * V_454 = & V_66 -> V_454 [ V_23 -> V_118 ] ;
if ( V_23 -> V_118 >= F_9 ( V_23 -> V_21 ) -> V_455 )
return - V_345 ;
F_113 ( & V_454 -> V_296 ) ;
if ( V_454 -> V_456 ) {
F_114 ( & V_454 -> V_296 ) ;
return - V_457 ;
}
V_454 -> V_456 = true ;
V_451 -> V_184 = V_185 -> V_186 ;
F_114 ( & V_454 -> V_296 ) ;
return 0 ;
}
static int F_181 ( struct V_185 * V_185 , struct V_101 * V_451 )
{
struct V_452 * V_23 = V_185 -> V_186 ;
struct V_65 * V_66 = V_23 -> V_21 -> V_67 ;
struct V_453 * V_454 = & V_66 -> V_454 [ V_23 -> V_118 ] ;
F_113 ( & V_454 -> V_296 ) ;
V_454 -> V_456 = false ;
F_114 ( & V_454 -> V_296 ) ;
return 0 ;
}
static int F_182 ( struct V_453 * V_454 )
{
F_183 ( & V_454 -> V_296 ) ;
return F_184 ( V_454 -> V_64 , V_454 -> V_458 ,
V_459 ) ;
}
static T_6
F_185 ( struct V_101 * V_451 , char T_7 * V_460 , T_3 V_72 ,
T_8 * V_188 )
{
struct V_452 * V_23 = V_451 -> V_184 ;
struct V_20 * V_21 = V_23 -> V_21 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_453 * V_454 = & V_66 -> V_454 [ V_23 -> V_118 ] ;
char V_194 [ V_461 ] ;
int V_64 , V_458 , V_462 , V_463 ;
T_6 V_464 ;
if ( V_72 < V_465 )
return - V_79 ;
if ( V_454 -> V_466 == V_467 )
return 0 ;
F_113 ( & V_454 -> V_296 ) ;
while ( F_182 ( V_454 ) == 0 ) {
int V_73 ;
if ( V_451 -> V_468 & V_469 ) {
F_114 ( & V_454 -> V_296 ) ;
return - V_470 ;
}
V_73 = F_186 ( V_454 -> V_471 ,
F_182 ( V_454 ) , V_454 -> V_296 ) ;
if ( V_73 ) {
F_114 ( & V_454 -> V_296 ) ;
return V_73 ;
}
}
V_64 = V_454 -> V_64 ;
V_458 = V_454 -> V_458 ;
V_462 = F_187 ( ( T_3 ) F_184 ( V_64 , V_458 , V_459 ) ,
V_72 / V_465 ) ;
F_114 ( & V_454 -> V_296 ) ;
V_464 = 0 ;
V_463 = 0 ;
do {
struct V_472 * V_473 = & V_454 -> V_474 [ V_458 ] ;
int V_73 ;
V_464 += snprintf ( V_194 , V_461 ,
L_295 ,
V_473 -> V_475 , V_473 -> V_476 [ 0 ] ,
V_473 -> V_476 [ 1 ] , V_473 -> V_476 [ 2 ] ,
V_473 -> V_476 [ 3 ] , V_473 -> V_476 [ 4 ] ) ;
V_73 = F_188 ( V_460 + V_463 * V_465 ,
V_194 , V_465 ) ;
if ( V_73 == V_465 )
return - V_477 ;
F_189 ( V_459 ) ;
V_458 = ( V_458 + 1 ) & ( V_459 - 1 ) ;
V_463 ++ ;
} while ( -- V_462 );
F_113 ( & V_454 -> V_296 ) ;
V_454 -> V_458 = V_458 ;
F_114 ( & V_454 -> V_296 ) ;
return V_464 ;
}
static int F_190 ( struct V_4 * V_478 , struct V_2 * V_3 ,
enum V_118 V_118 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
struct V_452 * V_23 = & V_479 [ V_118 ] ;
V_23 -> V_21 = V_21 ;
V_5 = F_191 ( V_23 -> V_47 , V_480 , V_478 , V_23 ,
& V_481 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_23 ) ;
}
static const char * F_192 ( enum V_482 V_466 )
{
F_193 ( F_194 ( V_483 ) != V_484 ) ;
return V_483 [ V_466 ] ;
}
static int F_195 ( struct V_16 * V_17 , void * V_18 )
{
struct V_20 * V_21 = V_17 -> V_19 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_132 ;
for ( V_132 = 0 ; V_132 < V_485 ; V_132 ++ )
F_10 ( V_17 , L_296 , F_49 ( V_132 ) ,
F_192 ( V_66 -> V_454 [ V_132 ] . V_466 ) ) ;
return 0 ;
}
static int F_196 ( struct V_185 * V_185 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_185 -> V_186 ;
return F_197 ( V_101 , F_195 , V_21 ) ;
}
static int F_198 ( enum V_482 * V_466 ,
T_11 * V_196 )
{
if ( * V_466 == V_486 )
* V_466 = V_487 ;
switch ( * V_466 ) {
case V_487 :
* V_196 = V_488 | V_489 ;
break;
case V_467 :
* V_196 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_199 ( struct V_20 * V_21 , enum V_118 V_118 ,
enum V_482 * V_466 )
{
struct V_490 * V_491 ;
struct V_116 * V_117 ;
struct V_492 * V_493 ;
int V_73 = 0 ;
* V_466 = V_487 ;
F_5 ( & V_21 -> V_359 . V_360 ) ;
F_20 (encoder, &dev->mode_config.encoder_list,
base.head) {
if ( ! V_491 -> V_36 . V_117 )
continue;
V_117 = F_200 ( V_491 -> V_36 . V_117 ) ;
if ( V_117 -> V_118 != V_118 )
continue;
switch ( V_491 -> type ) {
case V_494 :
* V_466 = V_495 ;
break;
case V_496 :
case V_497 :
V_493 = F_201 ( & V_491 -> V_36 ) ;
switch ( V_493 -> V_498 ) {
case V_499 :
* V_466 = V_500 ;
break;
case V_501 :
* V_466 = V_502 ;
break;
case V_503 :
* V_466 = V_504 ;
break;
default:
F_202 ( 1 , L_297 ,
F_203 ( V_493 -> V_498 ) ) ;
break;
}
break;
}
}
F_7 ( & V_21 -> V_359 . V_360 ) ;
return V_73 ;
}
static int F_204 ( struct V_20 * V_21 ,
enum V_118 V_118 ,
enum V_482 * V_466 ,
T_11 * V_196 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_505 = false ;
if ( * V_466 == V_486 ) {
int V_73 = F_199 ( V_21 , V_118 , V_466 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_466 ) {
case V_487 :
* V_196 = V_488 | V_506 ;
break;
case V_500 :
* V_196 = V_488 | V_507 ;
V_505 = true ;
break;
case V_502 :
* V_196 = V_488 | V_508 ;
V_505 = true ;
break;
case V_467 :
* V_196 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_505 ) {
T_11 V_509 = F_62 ( V_510 ) ;
F_177 ( ! F_205 ( V_21 ) ) ;
V_509 |= V_511 ;
if ( V_118 == V_407 )
V_509 |= V_512 ;
else
V_509 |= V_513 ;
F_206 ( V_510 , V_509 ) ;
}
return 0 ;
}
static int F_207 ( struct V_20 * V_21 ,
enum V_118 V_118 ,
enum V_482 * V_466 ,
T_11 * V_196 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
bool V_505 = false ;
if ( * V_466 == V_486 ) {
int V_73 = F_199 ( V_21 , V_118 , V_466 ) ;
if ( V_73 )
return V_73 ;
}
switch ( * V_466 ) {
case V_487 :
* V_196 = V_488 | V_514 ;
break;
case V_495 :
if ( ! F_208 ( V_21 ) )
return - V_79 ;
* V_196 = V_488 | V_515 ;
break;
case V_500 :
if ( ! F_205 ( V_21 ) )
return - V_79 ;
* V_196 = V_488 | V_516 ;
V_505 = true ;
break;
case V_502 :
if ( ! F_205 ( V_21 ) )
return - V_79 ;
* V_196 = V_488 | V_517 ;
V_505 = true ;
break;
case V_504 :
if ( ! F_205 ( V_21 ) )
return - V_79 ;
* V_196 = V_488 | V_518 ;
V_505 = true ;
break;
case V_467 :
* V_196 = 0 ;
break;
default:
return - V_79 ;
}
if ( V_505 ) {
T_11 V_509 = F_62 ( V_510 ) ;
F_177 ( ! F_205 ( V_21 ) ) ;
F_206 ( V_519 ,
F_62 ( V_519 ) | V_520 ) ;
if ( V_118 == V_407 )
V_509 |= V_512 ;
else
V_509 |= V_513 ;
F_206 ( V_510 , V_509 ) ;
}
return 0 ;
}
static void F_209 ( struct V_20 * V_21 ,
enum V_118 V_118 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_509 = F_62 ( V_510 ) ;
if ( V_118 == V_407 )
V_509 &= ~ V_512 ;
else
V_509 &= ~ V_513 ;
if ( ! ( V_509 & V_521 ) )
V_509 &= ~ V_511 ;
F_206 ( V_510 , V_509 ) ;
}
static void F_210 ( struct V_20 * V_21 ,
enum V_118 V_118 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
T_11 V_509 = F_62 ( V_510 ) ;
if ( V_118 == V_407 )
V_509 &= ~ V_512 ;
else
V_509 &= ~ V_513 ;
F_206 ( V_510 , V_509 ) ;
if ( ! ( V_509 & V_521 ) ) {
F_206 ( V_519 ,
F_62 ( V_519 ) & ~ V_520 ) ;
}
}
static int F_211 ( enum V_482 * V_466 ,
T_11 * V_196 )
{
if ( * V_466 == V_486 )
* V_466 = V_487 ;
switch ( * V_466 ) {
case V_522 :
* V_196 = V_488 | V_523 ;
break;
case V_524 :
* V_196 = V_488 | V_525 ;
break;
case V_487 :
* V_196 = V_488 | V_526 ;
break;
case V_467 :
* V_196 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_212 ( enum V_482 * V_466 ,
T_11 * V_196 )
{
if ( * V_466 == V_486 )
* V_466 = V_527 ;
switch ( * V_466 ) {
case V_522 :
* V_196 = V_488 | V_528 ;
break;
case V_524 :
* V_196 = V_488 | V_529 ;
break;
case V_527 :
* V_196 = V_488 | V_530 ;
break;
case V_467 :
* V_196 = 0 ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_213 ( struct V_20 * V_21 , enum V_118 V_118 ,
enum V_482 V_466 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_453 * V_454 = & V_66 -> V_454 [ V_118 ] ;
T_4 V_196 = 0 ;
int V_73 ;
if ( V_454 -> V_466 == V_466 )
return 0 ;
if ( V_454 -> V_466 && V_466 )
return - V_79 ;
if ( F_214 ( V_21 ) )
V_73 = F_198 ( & V_466 , & V_196 ) ;
else if ( F_9 ( V_21 ) -> V_24 < 5 )
V_73 = F_207 ( V_21 , V_118 , & V_466 , & V_196 ) ;
else if ( F_70 ( V_21 ) )
V_73 = F_204 ( V_21 , V_118 , & V_466 , & V_196 ) ;
else if ( F_97 ( V_21 ) || F_98 ( V_21 ) )
V_73 = F_211 ( & V_466 , & V_196 ) ;
else
V_73 = F_212 ( & V_466 , & V_196 ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_466 ) {
F_77 ( L_298 ,
F_49 ( V_118 ) , F_192 ( V_466 ) ) ;
V_454 -> V_474 = F_80 ( sizeof( * V_454 -> V_474 ) *
V_459 ,
V_9 ) ;
if ( ! V_454 -> V_474 )
return - V_10 ;
F_113 ( & V_454 -> V_296 ) ;
V_454 -> V_64 = 0 ;
V_454 -> V_458 = 0 ;
F_114 ( & V_454 -> V_296 ) ;
}
V_454 -> V_466 = V_466 ;
F_206 ( F_215 ( V_118 ) , V_196 ) ;
F_216 ( F_215 ( V_118 ) ) ;
if ( V_466 == V_467 ) {
struct V_472 * V_474 ;
F_77 ( L_299 ,
F_49 ( V_118 ) ) ;
F_217 ( V_21 , V_118 ) ;
F_113 ( & V_454 -> V_296 ) ;
V_474 = V_454 -> V_474 ;
V_454 -> V_474 = NULL ;
F_114 ( & V_454 -> V_296 ) ;
F_84 ( V_474 ) ;
if ( F_205 ( V_21 ) )
F_210 ( V_21 , V_118 ) ;
else if ( F_70 ( V_21 ) )
F_209 ( V_21 , V_118 ) ;
}
return 0 ;
}
static int F_218 ( char * V_194 , char * V_531 [] , int V_532 )
{
int V_533 = 0 ;
while ( * V_194 ) {
char * V_534 ;
V_194 = F_219 ( V_194 ) ;
if ( ! * V_194 )
break;
for ( V_534 = V_194 ; * V_534 && ! isspace ( * V_534 ) ; V_534 ++ )
;
if ( V_533 == V_532 ) {
F_77 ( L_300 ,
V_532 ) ;
return - V_79 ;
}
if ( * V_534 )
* V_534 ++ = '\0' ;
V_531 [ V_533 ++ ] = V_194 ;
V_194 = V_534 ;
}
return V_533 ;
}
static int
F_220 ( const char * V_194 , enum V_535 * V_536 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < F_194 ( V_537 ) ; V_132 ++ )
if ( ! strcmp ( V_194 , V_537 [ V_132 ] ) ) {
* V_536 = V_132 ;
return 0 ;
}
return - V_79 ;
}
static int F_221 ( const char * V_194 , enum V_118 * V_118 )
{
const char V_47 = V_194 [ 0 ] ;
if ( V_47 < 'A' || V_47 >= F_49 ( V_485 ) )
return - V_79 ;
* V_118 = V_47 - 'A' ;
return 0 ;
}
static int
F_222 ( const char * V_194 , enum V_482 * V_56 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < F_194 ( V_483 ) ; V_132 ++ )
if ( ! strcmp ( V_194 , V_483 [ V_132 ] ) ) {
* V_56 = V_132 ;
return 0 ;
}
return - V_79 ;
}
static int F_223 ( struct V_20 * V_21 , char * V_194 , T_3 V_538 )
{
#define F_224 3
int V_533 ;
char * V_531 [ F_224 ] ;
enum V_118 V_118 ;
enum V_535 V_539 ;
enum V_482 V_466 ;
V_533 = F_218 ( V_194 , V_531 , F_224 ) ;
if ( V_533 != F_224 ) {
F_77 ( L_301 ,
F_224 ) ;
return - V_79 ;
}
if ( F_220 ( V_531 [ 0 ] , & V_539 ) < 0 ) {
F_77 ( L_302 , V_531 [ 0 ] ) ;
return - V_79 ;
}
if ( F_221 ( V_531 [ 1 ] , & V_118 ) < 0 ) {
F_77 ( L_303 , V_531 [ 1 ] ) ;
return - V_79 ;
}
if ( F_222 ( V_531 [ 2 ] , & V_466 ) < 0 ) {
F_77 ( L_304 , V_531 [ 2 ] ) ;
return - V_79 ;
}
return F_213 ( V_21 , V_118 , V_466 ) ;
}
static T_6 F_225 ( struct V_101 * V_101 , const char T_7 * V_179 ,
T_3 V_538 , T_8 * V_540 )
{
struct V_16 * V_17 = V_101 -> V_184 ;
struct V_20 * V_21 = V_17 -> V_19 ;
char * V_541 ;
int V_73 ;
if ( V_538 == 0 )
return 0 ;
if ( V_538 > V_542 - 1 ) {
F_77 ( L_305 ,
V_542 ) ;
return - V_543 ;
}
V_541 = F_3 ( V_538 + 1 , V_9 ) ;
if ( ! V_541 )
return - V_10 ;
if ( F_226 ( V_541 , V_179 , V_538 ) ) {
V_73 = - V_477 ;
goto V_193;
}
V_541 [ V_538 ] = '\0' ;
V_73 = F_223 ( V_21 , V_541 , V_538 ) ;
V_193:
F_84 ( V_541 ) ;
if ( V_73 < 0 )
return V_73 ;
* V_540 += V_538 ;
return V_538 ;
}
static int
F_227 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
* V_196 = F_52 ( & V_66 -> V_544 . V_545 ) ;
return 0 ;
}
static int
F_228 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
F_229 ( L_306 , V_196 ) ;
F_230 ( V_21 , V_196 ) ;
return 0 ;
}
static int
F_231 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
* V_196 = V_66 -> V_544 . V_546 ;
return 0 ;
}
static int
F_232 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_77 ( L_307 , V_196 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_544 . V_546 = V_196 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_233 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_196 = V_66 -> V_544 . V_547 ;
return 0 ;
}
static int
F_234 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_544 . V_547 = V_196 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_235 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
* V_196 = V_66 -> V_544 . V_548 ;
return 0 ;
}
static int
F_236 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
F_77 ( L_308 , V_196 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_66 -> V_544 . V_548 = V_196 ;
F_7 ( & V_21 -> V_74 ) ;
return 0 ;
}
static int
F_237 ( void * V_18 , T_9 * V_196 )
{
* V_196 = V_549 ;
return 0 ;
}
static int
F_238 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
struct V_25 * V_26 , * V_550 ;
struct V_68 * V_51 ;
struct V_34 * V_35 , * T_1 ;
int V_73 ;
F_239 ( L_309 , V_196 ) ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( V_196 & V_551 ) {
V_73 = F_240 ( V_21 ) ;
if ( V_73 )
goto V_552;
}
if ( V_196 & ( V_553 | V_551 ) )
F_241 ( V_21 ) ;
if ( V_196 & V_554 ) {
F_20 (vm, &dev_priv->vm_list, global_link) {
F_242 (vma, x, &vm->inactive_list,
mm_list) {
if ( V_35 -> V_26 -> V_28 )
continue;
V_73 = F_243 ( V_35 ) ;
if ( V_73 )
goto V_552;
}
}
}
if ( V_196 & V_555 ) {
F_242 (obj, next, &dev_priv->mm.unbound_list,
global_list)
if ( V_26 -> V_556 == 0 ) {
V_73 = F_244 ( V_26 ) ;
if ( V_73 )
goto V_552;
}
}
V_552:
F_7 ( & V_21 -> V_74 ) ;
return V_73 ;
}
static int
F_245 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_98 ( V_21 ) || F_99 ( V_21 ) ) )
return - V_345 ;
F_96 ( & V_66 -> V_201 . V_202 ) ;
V_73 = F_26 ( & V_66 -> V_201 . V_247 ) ;
if ( V_73 )
return V_73 ;
if ( F_70 ( V_21 ) )
* V_196 = F_105 ( V_66 , V_66 -> V_201 . V_349 ) ;
else
* V_196 = V_66 -> V_201 . V_349 * V_230 ;
F_7 ( & V_66 -> V_201 . V_247 ) ;
return 0 ;
}
static int
F_246 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_98 ( V_21 ) || F_99 ( V_21 ) ) )
return - V_345 ;
F_96 ( & V_66 -> V_201 . V_202 ) ;
F_77 ( L_310 , V_196 ) ;
V_73 = F_26 ( & V_66 -> V_201 . V_247 ) ;
if ( V_73 )
return V_73 ;
if ( F_70 ( V_21 ) ) {
V_196 = F_247 ( V_66 , V_196 ) ;
V_66 -> V_201 . V_349 = V_196 ;
F_248 ( V_21 , V_196 ) ;
} else {
F_249 ( V_196 , V_230 ) ;
V_66 -> V_201 . V_349 = V_196 ;
F_250 ( V_21 , V_196 ) ;
}
F_7 ( & V_66 -> V_201 . V_247 ) ;
return 0 ;
}
static int
F_251 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_98 ( V_21 ) || F_99 ( V_21 ) ) )
return - V_345 ;
F_96 ( & V_66 -> V_201 . V_202 ) ;
V_73 = F_26 ( & V_66 -> V_201 . V_247 ) ;
if ( V_73 )
return V_73 ;
if ( F_70 ( V_21 ) )
* V_196 = F_105 ( V_66 , V_66 -> V_201 . V_348 ) ;
else
* V_196 = V_66 -> V_201 . V_348 * V_230 ;
F_7 ( & V_66 -> V_201 . V_247 ) ;
return 0 ;
}
static int
F_252 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
int V_73 ;
if ( ! ( F_98 ( V_21 ) || F_99 ( V_21 ) ) )
return - V_345 ;
F_96 ( & V_66 -> V_201 . V_202 ) ;
F_77 ( L_311 , V_196 ) ;
V_73 = F_26 ( & V_66 -> V_201 . V_247 ) ;
if ( V_73 )
return V_73 ;
if ( F_70 ( V_21 ) ) {
V_196 = F_247 ( V_66 , V_196 ) ;
V_66 -> V_201 . V_348 = V_196 ;
F_248 ( V_21 , V_196 ) ;
} else {
F_249 ( V_196 , V_230 ) ;
V_66 -> V_201 . V_348 = V_196 ;
F_250 ( V_21 , V_196 ) ;
}
F_7 ( & V_66 -> V_201 . V_247 ) ;
return 0 ;
}
static int
F_253 ( void * V_18 , T_9 * V_196 )
{
struct V_20 * V_21 = V_18 ;
T_5 * V_66 = V_21 -> V_67 ;
T_4 V_557 ;
int V_73 ;
if ( ! ( F_98 ( V_21 ) || F_99 ( V_21 ) ) )
return - V_345 ;
V_73 = F_26 ( & V_21 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_59 ( V_66 ) ;
V_557 = F_62 ( V_558 ) ;
F_60 ( V_66 ) ;
F_7 ( & V_66 -> V_21 -> V_74 ) ;
* V_196 = ( V_557 & V_559 ) >> V_560 ;
return 0 ;
}
static int
F_254 ( void * V_18 , T_9 V_196 )
{
struct V_20 * V_21 = V_18 ;
struct V_65 * V_66 = V_21 -> V_67 ;
T_4 V_557 ;
if ( ! ( F_98 ( V_21 ) || F_99 ( V_21 ) ) )
return - V_345 ;
if ( V_196 > 3 )
return - V_79 ;
F_59 ( V_66 ) ;
F_77 ( L_312 , V_196 ) ;
V_557 = F_62 ( V_558 ) ;
V_557 &= ~ V_559 ;
V_557 |= ( V_196 << V_560 ) ;
F_206 ( V_558 , V_557 ) ;
F_60 ( V_66 ) ;
return 0 ;
}
static int F_255 ( struct V_185 * V_185 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_185 -> V_186 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_59 ( V_66 ) ;
F_100 ( V_66 , V_227 ) ;
return 0 ;
}
static int F_256 ( struct V_185 * V_185 , struct V_101 * V_101 )
{
struct V_20 * V_21 = V_185 -> V_186 ;
struct V_65 * V_66 = V_21 -> V_67 ;
if ( F_9 ( V_21 ) -> V_24 < 6 )
return 0 ;
F_102 ( V_66 , V_227 ) ;
F_60 ( V_66 ) ;
return 0 ;
}
static int F_257 ( struct V_4 * V_478 , struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_191 ( L_313 ,
V_561 ,
V_478 , V_21 ,
& V_562 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , & V_562 ) ;
}
static int F_258 ( struct V_4 * V_478 ,
struct V_2 * V_3 ,
const char * V_47 ,
const struct V_563 * V_564 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_4 * V_5 ;
V_5 = F_191 ( V_47 ,
V_480 | V_565 ,
V_478 , V_21 ,
V_564 ) ;
if ( ! V_5 )
return - V_10 ;
return F_2 ( V_3 , V_5 , V_564 ) ;
}
void F_259 ( struct V_20 * V_21 )
{
struct V_65 * V_66 = V_21 -> V_67 ;
enum V_118 V_118 ;
F_66 (pipe) {
struct V_453 * V_454 = & V_66 -> V_454 [ V_118 ] ;
V_454 -> V_456 = false ;
F_260 ( & V_454 -> V_296 ) ;
F_261 ( & V_454 -> V_471 ) ;
}
}
int F_262 ( struct V_2 * V_3 )
{
int V_73 , V_132 ;
V_73 = F_257 ( V_3 -> V_566 , V_3 ) ;
if ( V_73 )
return V_73 ;
for ( V_132 = 0 ; V_132 < F_194 ( V_479 ) ; V_132 ++ ) {
V_73 = F_190 ( V_3 -> V_566 , V_3 , V_132 ) ;
if ( V_73 )
return V_73 ;
}
for ( V_132 = 0 ; V_132 < F_194 ( V_567 ) ; V_132 ++ ) {
V_73 = F_258 ( V_3 -> V_566 , V_3 ,
V_567 [ V_132 ] . V_47 ,
V_567 [ V_132 ] . V_564 ) ;
if ( V_73 )
return V_73 ;
}
return F_263 ( V_568 ,
V_569 ,
V_3 -> V_566 , V_3 ) ;
}
void F_264 ( struct V_2 * V_3 )
{
int V_132 ;
F_265 ( V_568 ,
V_569 , V_3 ) ;
F_265 ( (struct V_570 * ) & V_562 ,
1 , V_3 ) ;
for ( V_132 = 0 ; V_132 < F_194 ( V_479 ) ; V_132 ++ ) {
struct V_570 * V_571 =
(struct V_570 * ) & V_479 [ V_132 ] ;
F_265 ( V_571 , 1 , V_3 ) ;
}
for ( V_132 = 0 ; V_132 < F_194 ( V_567 ) ; V_132 ++ ) {
struct V_570 * V_571 =
(struct V_570 * ) V_567 [ V_132 ] . V_564 ;
F_265 ( V_571 , 1 , V_3 ) ;
}
}
