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
static const char * F_11 ( int type )
{
switch ( type ) {
case V_22 : return L_10 ;
case V_23 : return L_11 ;
case V_24 : return L_12 ;
default: return L_13 ;
}
}
static void
F_12 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
F_4 ( V_3 , L_14 ,
& V_15 -> V_25 ,
F_9 ( V_15 ) ,
F_10 ( V_15 ) ,
V_15 -> V_25 . V_26 / 1024 ,
V_15 -> V_25 . V_27 ,
V_15 -> V_25 . V_28 ,
V_15 -> V_29 ,
V_15 -> V_30 ,
V_15 -> V_31 ,
F_11 ( V_15 -> V_32 ) ,
V_15 -> V_33 ? L_15 : L_13 ,
V_15 -> V_34 == V_35 ? L_16 : L_13 ) ;
if ( V_15 -> V_25 . V_36 )
F_4 ( V_3 , L_17 , V_15 -> V_25 . V_36 ) ;
if ( V_15 -> V_17 )
F_4 ( V_3 , L_18 , V_15 -> V_17 ) ;
if ( V_15 -> V_37 != V_38 )
F_4 ( V_3 , L_19 , V_15 -> V_37 ) ;
if ( V_15 -> V_39 != NULL )
F_4 ( V_3 , L_20 ,
V_15 -> V_40 , ( unsigned int ) V_15 -> V_39 -> V_26 ) ;
if ( V_15 -> V_41 )
F_4 ( V_3 , L_21 , V_15 -> V_41 -> V_42 ) ;
if ( V_15 -> V_43 || V_15 -> V_44 ) {
char V_45 [ 3 ] , * V_46 = V_45 ;
if ( V_15 -> V_43 )
* V_46 ++ = 'p' ;
if ( V_15 -> V_44 )
* V_46 ++ = 'f' ;
* V_46 = '\0' ;
F_4 ( V_3 , L_22 , V_45 ) ;
}
if ( V_15 -> V_47 != NULL )
F_4 ( V_3 , L_23 , V_15 -> V_47 -> V_36 ) ;
}
static int F_13 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_48 = ( T_2 ) V_6 -> V_49 -> V_4 ;
struct V_50 * V_51 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_14 * V_15 ;
T_4 V_54 , V_55 ;
int V_56 , V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
switch ( V_48 ) {
case V_59 :
F_4 ( V_3 , L_24 ) ;
V_51 = & V_52 -> V_60 . V_61 ;
break;
case V_62 :
F_4 ( V_3 , L_25 ) ;
V_51 = & V_52 -> V_60 . V_63 ;
break;
default:
F_15 ( & V_9 -> V_58 ) ;
return - V_64 ;
}
V_54 = V_55 = V_56 = 0 ;
F_16 (obj, head, mm_list) {
F_4 ( V_3 , L_26 ) ;
F_12 ( V_3 , V_15 ) ;
F_4 ( V_3 , L_27 ) ;
V_54 += V_15 -> V_25 . V_26 ;
V_55 += V_15 -> V_39 -> V_26 ;
V_56 ++ ;
}
F_15 ( & V_9 -> V_58 ) ;
F_4 ( V_3 , L_28 ,
V_56 , V_54 , V_55 ) ;
return 0 ;
}
static int F_17 ( int V_65 , void * V_66 , void * V_4 )
{
struct V_14 * V_15 = V_66 ;
struct V_67 * V_68 = V_4 ;
V_68 -> V_56 ++ ;
V_68 -> V_69 += V_15 -> V_25 . V_26 ;
if ( V_15 -> V_39 ) {
if ( ! F_18 ( & V_15 -> V_70 ) )
V_68 -> V_71 += V_15 -> V_25 . V_26 ;
else
V_68 -> V_72 += V_15 -> V_25 . V_26 ;
} else {
if ( ! F_18 ( & V_15 -> V_73 ) )
V_68 -> V_74 += V_15 -> V_25 . V_26 ;
}
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_75 * V_52 = V_9 -> V_53 ;
T_5 V_56 , V_76 , V_77 ;
T_4 V_26 , V_78 , V_79 ;
struct V_14 * V_15 ;
struct V_80 * V_81 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_4 ( V_3 , L_29 ,
V_52 -> V_60 . V_82 ,
V_52 -> V_60 . V_83 ) ;
V_26 = V_56 = V_78 = V_76 = 0 ;
F_20 ( & V_52 -> V_60 . V_84 , V_73 ) ;
F_4 ( V_3 , L_30 ,
V_56 , V_76 , V_26 , V_78 ) ;
V_26 = V_56 = V_78 = V_76 = 0 ;
F_20 ( & V_52 -> V_60 . V_61 , V_85 ) ;
F_4 ( V_3 , L_31 ,
V_56 , V_76 , V_26 , V_78 ) ;
V_26 = V_56 = V_78 = V_76 = 0 ;
F_20 ( & V_52 -> V_60 . V_63 , V_85 ) ;
F_4 ( V_3 , L_32 ,
V_56 , V_76 , V_26 , V_78 ) ;
V_26 = V_56 = V_79 = V_77 = 0 ;
F_16 (obj, &dev_priv->mm.unbound_list, global_list) {
V_26 += V_15 -> V_25 . V_26 , ++ V_56 ;
if ( V_15 -> V_34 == V_35 )
V_79 += V_15 -> V_25 . V_26 , ++ V_77 ;
}
F_4 ( V_3 , L_33 , V_56 , V_26 ) ;
V_26 = V_56 = V_78 = V_76 = 0 ;
F_16 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_15 -> V_44 ) {
V_26 += V_15 -> V_39 -> V_26 ;
++ V_56 ;
}
if ( V_15 -> V_43 ) {
V_78 += V_15 -> V_39 -> V_26 ;
++ V_76 ;
}
if ( V_15 -> V_34 == V_35 ) {
V_79 += V_15 -> V_25 . V_26 ;
++ V_77 ;
}
}
F_4 ( V_3 , L_34 ,
V_77 , V_79 ) ;
F_4 ( V_3 , L_35 ,
V_76 , V_78 ) ;
F_4 ( V_3 , L_36 ,
V_56 , V_26 ) ;
F_4 ( V_3 , L_37 ,
V_52 -> V_86 . V_69 ,
V_52 -> V_86 . V_87 - V_52 -> V_86 . V_42 ) ;
F_4 ( V_3 , L_27 ) ;
F_21 (file, &dev->filelist, lhead) {
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
F_22 ( & V_81 -> V_88 , F_17 , & V_68 ) ;
F_4 ( V_3 , L_38 ,
F_23 ( V_81 -> V_89 , V_90 ) -> V_91 ,
V_68 . V_56 ,
V_68 . V_69 ,
V_68 . V_71 ,
V_68 . V_72 ,
V_68 . V_74 ) ;
}
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_2 V_48 = ( T_2 ) V_6 -> V_49 -> V_4 ;
struct V_75 * V_52 = V_9 -> V_53 ;
struct V_14 * V_15 ;
T_4 V_54 , V_55 ;
int V_56 , V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_54 = V_55 = V_56 = 0 ;
F_16 (obj, &dev_priv->mm.bound_list, global_list) {
if ( V_48 == V_92 && V_15 -> V_17 == 0 )
continue;
F_4 ( V_3 , L_26 ) ;
F_12 ( V_3 , V_15 ) ;
F_4 ( V_3 , L_27 ) ;
V_54 += V_15 -> V_25 . V_26 ;
V_55 += V_15 -> V_39 -> V_26 ;
V_56 ++ ;
}
F_15 ( & V_9 -> V_58 ) ;
F_4 ( V_3 , L_28 ,
V_56 , V_54 , V_55 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
unsigned long V_93 ;
struct V_94 * V_95 ;
F_16 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_96 = F_26 ( V_95 -> V_96 ) ;
const char V_97 = F_27 ( V_95 -> V_97 ) ;
struct V_98 * V_99 ;
F_28 ( & V_9 -> V_100 , V_93 ) ;
V_99 = V_95 -> V_101 ;
if ( V_99 == NULL ) {
F_4 ( V_3 , L_39 ,
V_96 , V_97 ) ;
} else {
if ( F_29 ( & V_99 -> V_102 ) < V_103 ) {
F_4 ( V_3 , L_40 ,
V_96 , V_97 ) ;
} else {
F_4 ( V_3 , L_41 ,
V_96 , V_97 ) ;
}
if ( V_99 -> V_104 )
F_4 ( V_3 , L_42 ) ;
else
F_4 ( V_3 , L_43 ) ;
F_4 ( V_3 , L_44 , F_29 ( & V_99 -> V_102 ) ) ;
if ( V_99 -> V_105 ) {
struct V_14 * V_15 = V_99 -> V_105 ;
if ( V_15 )
F_4 ( V_3 , L_45 , V_15 -> V_40 ) ;
}
if ( V_99 -> V_106 ) {
struct V_14 * V_15 = V_99 -> V_106 ;
if ( V_15 )
F_4 ( V_3 , L_46 , V_15 -> V_40 ) ;
}
}
F_30 ( & V_9 -> V_100 , V_93 ) ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_107 * V_47 ;
struct V_108 * V_109 ;
int V_57 , V_56 , V_110 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_56 = 0 ;
F_32 (ring, dev_priv, i) {
if ( F_18 ( & V_47 -> V_111 ) )
continue;
F_4 ( V_3 , L_47 , V_47 -> V_36 ) ;
F_16 (gem_request,
&ring->request_list,
list) {
F_4 ( V_3 , L_48 ,
V_109 -> V_112 ,
( int ) ( V_113 - V_109 -> V_114 ) ) ;
}
V_56 ++ ;
}
F_15 ( & V_9 -> V_58 ) ;
if ( V_56 == 0 )
F_4 ( V_3 , L_49 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_107 * V_47 )
{
if ( V_47 -> V_115 ) {
F_4 ( V_3 , L_50 ,
V_47 -> V_36 , V_47 -> V_115 ( V_47 , false ) ) ;
}
}
static int F_34 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_107 * V_47 ;
int V_57 , V_110 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_32 (ring, dev_priv, i)
F_33 ( V_3 , V_47 ) ;
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_107 * V_47 ;
int V_57 , V_110 , V_96 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
if ( F_36 ( V_9 ) ) {
F_4 ( V_3 , L_51 ,
F_37 ( V_116 ) ) ;
F_4 ( V_3 , L_52 ,
F_37 ( V_117 ) ) ;
F_4 ( V_3 , L_53 ,
F_37 ( V_118 ) ) ;
F_4 ( V_3 , L_54 ,
F_37 ( V_119 ) ) ;
F_38 (pipe)
F_4 ( V_3 , L_55 ,
F_26 ( V_96 ) ,
F_37 ( F_39 ( V_96 ) ) ) ;
F_4 ( V_3 , L_56 ,
F_37 ( V_120 ) ) ;
F_4 ( V_3 , L_57 ,
F_37 ( V_121 ) ) ;
F_4 ( V_3 , L_58 ,
F_37 ( V_122 ) ) ;
F_4 ( V_3 , L_59 ,
F_37 ( V_123 ) ) ;
F_4 ( V_3 , L_60 ,
F_37 ( V_124 ) ) ;
F_4 ( V_3 , L_61 ,
F_37 ( V_125 ) ) ;
F_4 ( V_3 , L_62 ,
F_37 ( V_126 ) ) ;
F_4 ( V_3 , L_63 ,
F_37 ( V_127 ) ) ;
F_4 ( V_3 , L_64 ,
F_37 ( V_128 ) ) ;
F_4 ( V_3 , L_65 ,
F_37 ( V_129 ) ) ;
} else if ( ! F_40 ( V_9 ) ) {
F_4 ( V_3 , L_66 ,
F_37 ( V_130 ) ) ;
F_4 ( V_3 , L_67 ,
F_37 ( V_131 ) ) ;
F_4 ( V_3 , L_68 ,
F_37 ( V_132 ) ) ;
F_38 (pipe)
F_4 ( V_3 , L_69 ,
F_26 ( V_96 ) ,
F_37 ( F_39 ( V_96 ) ) ) ;
} else {
F_4 ( V_3 , L_70 ,
F_37 ( V_133 ) ) ;
F_4 ( V_3 , L_71 ,
F_37 ( V_134 ) ) ;
F_4 ( V_3 , L_72 ,
F_37 ( V_135 ) ) ;
F_4 ( V_3 , L_73 ,
F_37 ( V_136 ) ) ;
F_4 ( V_3 , L_74 ,
F_37 ( V_137 ) ) ;
F_4 ( V_3 , L_75 ,
F_37 ( V_138 ) ) ;
F_4 ( V_3 , L_76 ,
F_37 ( V_121 ) ) ;
F_4 ( V_3 , L_77 ,
F_37 ( V_122 ) ) ;
F_4 ( V_3 , L_78 ,
F_37 ( V_123 ) ) ;
}
F_4 ( V_3 , L_79 ,
F_29 ( & V_52 -> V_139 ) ) ;
F_32 (ring, dev_priv, i) {
if ( F_41 ( V_9 ) || F_42 ( V_9 ) ) {
F_4 ( V_3 ,
L_80 ,
V_47 -> V_36 , F_43 ( V_47 ) ) ;
}
F_33 ( V_3 , V_47 ) ;
}
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
int V_110 , V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_4 ( V_3 , L_81 , V_52 -> V_140 ) ;
F_4 ( V_3 , L_82 , V_52 -> V_141 ) ;
for ( V_110 = 0 ; V_110 < V_52 -> V_141 ; V_110 ++ ) {
struct V_14 * V_15 = V_52 -> V_142 [ V_110 ] . V_15 ;
F_4 ( V_3 , L_83 ,
V_110 , V_52 -> V_142 [ V_110 ] . V_17 ) ;
if ( V_15 == NULL )
F_4 ( V_3 , L_84 ) ;
else
F_12 ( V_3 , V_15 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_107 * V_47 ;
const T_5 * V_143 ;
int V_110 ;
V_47 = & V_52 -> V_47 [ ( T_2 ) V_6 -> V_49 -> V_4 ] ;
V_143 = V_47 -> V_144 . V_145 ;
if ( V_143 == NULL )
return 0 ;
for ( V_110 = 0 ; V_110 < 4096 / sizeof( T_5 ) / 4 ; V_110 += 4 ) {
F_4 ( V_3 , L_85 ,
V_110 * 4 ,
V_143 [ V_110 ] , V_143 [ V_110 + 1 ] , V_143 [ V_110 + 2 ] , V_143 [ V_110 + 3 ] ) ;
}
return 0 ;
}
static const char * F_46 ( int V_47 )
{
switch ( V_47 ) {
case V_146 : return L_86 ;
case V_147 : return L_87 ;
case V_148 : return L_88 ;
case V_149 : return L_89 ;
default: return L_13 ;
}
}
static const char * F_47 ( int V_150 )
{
if ( V_150 > 0 )
return L_90 ;
else if ( V_150 < 0 )
return L_91 ;
else
return L_13 ;
}
static const char * F_48 ( int V_151 )
{
switch ( V_151 ) {
default:
case V_19 : return L_13 ;
case V_20 : return L_92 ;
case V_21 : return L_93 ;
}
}
static const char * F_49 ( int V_33 )
{
return V_33 ? L_15 : L_13 ;
}
static const char * F_50 ( int V_152 )
{
return V_152 ? L_16 : L_13 ;
}
static bool F_51 ( struct V_153 * V_154 )
{
if ( ! V_154 -> V_155 && F_52 ( V_154 -> V_156 > ( V_154 -> V_26 - 1 ) , L_94 ) ) {
V_154 -> V_155 = - V_157 ;
return false ;
}
if ( V_154 -> V_156 == V_154 -> V_26 - 1 || V_154 -> V_155 )
return false ;
return true ;
}
static bool F_53 ( struct V_153 * V_154 ,
unsigned V_158 )
{
if ( V_154 -> V_159 + V_158 <= V_154 -> V_42 ) {
V_154 -> V_159 += V_158 ;
return false ;
}
if ( V_158 >= V_154 -> V_26 ) {
V_154 -> V_155 = - V_160 ;
return false ;
}
return true ;
}
static void F_54 ( struct V_153 * V_154 ,
unsigned V_158 )
{
if ( V_154 -> V_159 < V_154 -> V_42 ) {
const T_4 V_161 = V_154 -> V_42 - V_154 -> V_159 ;
if ( V_161 > V_158 || V_154 -> V_156 ) {
V_154 -> V_155 = - V_160 ;
return;
}
memmove ( V_154 -> V_162 , V_154 -> V_162 + V_161 , V_158 - V_161 ) ;
V_154 -> V_156 = V_158 - V_161 ;
V_154 -> V_159 = V_154 -> V_42 ;
return;
}
V_154 -> V_156 += V_158 ;
V_154 -> V_159 += V_158 ;
}
static void F_55 ( struct V_153 * V_154 ,
const char * V_163 , T_6 args )
{
unsigned V_158 ;
if ( ! F_51 ( V_154 ) )
return;
if ( V_154 -> V_159 < V_154 -> V_42 ) {
V_158 = vsnprintf ( NULL , 0 , V_163 , args ) ;
if ( ! F_53 ( V_154 , V_158 ) )
return;
}
V_158 = vsnprintf ( V_154 -> V_162 + V_154 -> V_156 , V_154 -> V_26 - V_154 -> V_156 , V_163 , args ) ;
if ( V_158 >= V_154 -> V_26 - V_154 -> V_156 )
V_158 = V_154 -> V_26 - V_154 -> V_156 - 1 ;
F_54 ( V_154 , V_158 ) ;
}
static void F_56 ( struct V_153 * V_154 ,
const char * V_164 )
{
unsigned V_158 ;
if ( ! F_51 ( V_154 ) )
return;
V_158 = strlen ( V_164 ) ;
if ( V_154 -> V_159 < V_154 -> V_42 ) {
if ( ! F_53 ( V_154 , V_158 ) )
return;
}
if ( V_158 >= V_154 -> V_26 - V_154 -> V_156 )
V_158 = V_154 -> V_26 - V_154 -> V_156 - 1 ;
memcpy ( V_154 -> V_162 + V_154 -> V_156 , V_164 , V_158 ) ;
F_54 ( V_154 , V_158 ) ;
}
void F_57 ( struct V_153 * V_154 , const char * V_163 , ... )
{
T_6 args ;
va_start ( args , V_163 ) ;
F_55 ( V_154 , V_163 , args ) ;
va_end ( args ) ;
}
static void F_58 ( struct V_153 * V_3 ,
const char * V_36 ,
struct V_165 * V_155 ,
int V_56 )
{
F_59 ( V_3 , L_95 , V_36 , V_56 ) ;
while ( V_56 -- ) {
F_59 ( V_3 , L_96 ,
V_155 -> V_40 ,
V_155 -> V_26 ,
V_155 -> V_27 ,
V_155 -> V_28 ,
V_155 -> V_166 , V_155 -> V_167 ) ;
F_60 ( V_3 , F_47 ( V_155 -> V_150 ) ) ;
F_60 ( V_3 , F_48 ( V_155 -> V_151 ) ) ;
F_60 ( V_3 , F_49 ( V_155 -> V_33 ) ) ;
F_60 ( V_3 , F_50 ( V_155 -> V_152 ) ) ;
F_60 ( V_3 , V_155 -> V_47 != - 1 ? L_7 : L_13 ) ;
F_60 ( V_3 , F_46 ( V_155 -> V_47 ) ) ;
F_60 ( V_3 , F_11 ( V_155 -> V_32 ) ) ;
if ( V_155 -> V_36 )
F_59 ( V_3 , L_17 , V_155 -> V_36 ) ;
if ( V_155 -> V_37 != V_38 )
F_59 ( V_3 , L_19 , V_155 -> V_37 ) ;
F_60 ( V_3 , L_27 ) ;
V_155 ++ ;
}
}
static void F_61 ( struct V_153 * V_3 ,
struct V_8 * V_9 ,
struct V_168 * error ,
unsigned V_47 )
{
F_62 ( V_47 >= V_169 ) ;
F_59 ( V_3 , L_97 , F_46 ( V_47 ) ) ;
F_59 ( V_3 , L_98 , error -> V_51 [ V_47 ] ) ;
F_59 ( V_3 , L_99 , error -> V_170 [ V_47 ] ) ;
F_59 ( V_3 , L_100 , error -> V_171 [ V_47 ] ) ;
F_59 ( V_3 , L_101 , error -> V_172 [ V_47 ] ) ;
F_59 ( V_3 , L_102 , error -> V_173 [ V_47 ] ) ;
F_59 ( V_3 , L_103 , error -> V_174 [ V_47 ] ) ;
F_59 ( V_3 , L_104 , error -> V_175 [ V_47 ] ) ;
if ( V_47 == V_146 && F_3 ( V_9 ) -> V_13 >= 4 )
F_59 ( V_3 , L_105 , error -> V_176 ) ;
if ( F_3 ( V_9 ) -> V_13 >= 4 )
F_59 ( V_3 , L_106 , error -> V_177 [ V_47 ] ) ;
F_59 ( V_3 , L_107 , error -> V_178 [ V_47 ] ) ;
F_59 ( V_3 , L_108 , error -> V_179 [ V_47 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_59 ( V_3 , L_109 , error -> V_180 [ V_47 ] ) ;
F_59 ( V_3 , L_110 , error -> V_181 [ V_47 ] ) ;
F_59 ( V_3 , L_111 ,
error -> V_182 [ V_47 ] [ 0 ] ,
error -> V_183 [ V_47 ] [ 0 ] ) ;
F_59 ( V_3 , L_112 ,
error -> V_182 [ V_47 ] [ 1 ] ,
error -> V_183 [ V_47 ] [ 1 ] ) ;
}
F_59 ( V_3 , L_113 , error -> V_112 [ V_47 ] ) ;
F_59 ( V_3 , L_114 , F_1 ( error -> V_184 [ V_47 ] ) ) ;
F_59 ( V_3 , L_115 , error -> V_185 [ V_47 ] ) ;
F_59 ( V_3 , L_116 , error -> V_186 [ V_47 ] ) ;
}
static int F_63 ( struct V_187 * V_188 ,
struct V_153 * V_3 )
{
struct V_8 * V_9 = V_188 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_168 * error = V_188 -> error ;
struct V_107 * V_47 ;
int V_110 , V_189 , V_190 , V_191 , V_192 ;
if ( ! error ) {
F_59 ( V_3 , L_117 ) ;
return 0 ;
}
F_59 ( V_3 , L_118 , error -> time . V_193 ,
error -> time . V_194 ) ;
F_59 ( V_3 , L_119 V_195 L_27 ) ;
F_59 ( V_3 , L_120 , V_9 -> V_196 ) ;
F_59 ( V_3 , L_121 , error -> V_197 ) ;
F_59 ( V_3 , L_122 , error -> V_198 ) ;
F_59 ( V_3 , L_123 , error -> V_199 ) ;
F_59 ( V_3 , L_124 , error -> V_200 ) ;
F_59 ( V_3 , L_125 , error -> V_201 ) ;
F_59 ( V_3 , L_126 , error -> V_202 ) ;
for ( V_110 = 0 ; V_110 < V_52 -> V_141 ; V_110 ++ )
F_59 ( V_3 , L_127 , V_110 , error -> V_203 [ V_110 ] ) ;
for ( V_110 = 0 ; V_110 < F_64 ( error -> V_204 ) ; V_110 ++ )
F_59 ( V_3 , L_128 , V_110 ,
error -> V_204 [ V_110 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_59 ( V_3 , L_129 , error -> error ) ;
F_59 ( V_3 , L_130 , error -> V_205 ) ;
}
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_59 ( V_3 , L_131 , error -> V_206 ) ;
F_32 (ring, dev_priv, i)
F_61 ( V_3 , V_9 , error , V_110 ) ;
if ( error -> V_207 )
F_58 ( V_3 , L_132 ,
error -> V_207 ,
error -> V_208 ) ;
if ( error -> V_209 )
F_58 ( V_3 , L_133 ,
error -> V_209 ,
error -> V_210 ) ;
for ( V_110 = 0 ; V_110 < F_64 ( error -> V_47 ) ; V_110 ++ ) {
struct V_211 * V_15 ;
if ( ( V_15 = error -> V_47 [ V_110 ] . V_212 ) ) {
F_59 ( V_3 , L_134 ,
V_52 -> V_47 [ V_110 ] . V_36 ,
V_15 -> V_40 ) ;
V_191 = 0 ;
for ( V_190 = 0 ; V_190 < V_15 -> V_213 ; V_190 ++ ) {
for ( V_192 = 0 ; V_192 < V_214 / 4 ; V_192 ++ ) {
F_59 ( V_3 , L_135 , V_191 ,
V_15 -> V_215 [ V_190 ] [ V_192 ] ) ;
V_191 += 4 ;
}
}
}
if ( error -> V_47 [ V_110 ] . V_216 ) {
F_59 ( V_3 , L_136 ,
V_52 -> V_47 [ V_110 ] . V_36 ,
error -> V_47 [ V_110 ] . V_216 ) ;
for ( V_189 = 0 ; V_189 < error -> V_47 [ V_110 ] . V_216 ; V_189 ++ ) {
F_59 ( V_3 , L_137 ,
error -> V_47 [ V_110 ] . V_217 [ V_189 ] . V_112 ,
error -> V_47 [ V_110 ] . V_217 [ V_189 ] . V_113 ,
error -> V_47 [ V_110 ] . V_217 [ V_189 ] . V_170 ) ;
}
}
if ( ( V_15 = error -> V_47 [ V_110 ] . V_218 ) ) {
F_59 ( V_3 , L_138 ,
V_52 -> V_47 [ V_110 ] . V_36 ,
V_15 -> V_40 ) ;
V_191 = 0 ;
for ( V_190 = 0 ; V_190 < V_15 -> V_213 ; V_190 ++ ) {
for ( V_192 = 0 ; V_192 < V_214 / 4 ; V_192 ++ ) {
F_59 ( V_3 , L_135 ,
V_191 ,
V_15 -> V_215 [ V_190 ] [ V_192 ] ) ;
V_191 += 4 ;
}
}
}
V_15 = error -> V_47 [ V_110 ] . V_219 ;
if ( V_15 ) {
F_59 ( V_3 , L_139 ,
V_52 -> V_47 [ V_110 ] . V_36 ,
V_15 -> V_40 ) ;
V_191 = 0 ;
for ( V_192 = 0 ; V_192 < V_214 / 16 ; V_192 += 4 ) {
F_59 ( V_3 , L_140 ,
V_191 ,
V_15 -> V_215 [ 0 ] [ V_192 ] ,
V_15 -> V_215 [ 0 ] [ V_192 + 1 ] ,
V_15 -> V_215 [ 0 ] [ V_192 + 2 ] ,
V_15 -> V_215 [ 0 ] [ V_192 + 3 ] ) ;
V_191 += 16 ;
}
}
}
if ( error -> V_220 )
F_65 ( V_3 , error -> V_220 ) ;
if ( error -> V_221 )
F_66 ( V_3 , V_9 , error -> V_221 ) ;
return 0 ;
}
static T_7
F_67 ( struct V_81 * V_222 ,
const char T_8 * V_223 ,
T_4 V_224 ,
T_9 * V_225 )
{
struct V_187 * V_188 = V_222 -> V_226 ;
struct V_8 * V_9 = V_188 -> V_9 ;
int V_57 ;
F_68 ( L_141 ) ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_69 ( V_9 ) ;
F_15 ( & V_9 -> V_58 ) ;
return V_224 ;
}
static int F_70 ( struct V_227 * V_227 , struct V_81 * V_81 )
{
struct V_8 * V_9 = V_227 -> V_228 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_187 * V_188 ;
unsigned long V_93 ;
V_188 = F_71 ( sizeof( * V_188 ) , V_229 ) ;
if ( ! V_188 )
return - V_230 ;
V_188 -> V_9 = V_9 ;
F_28 ( & V_52 -> V_231 . V_232 , V_93 ) ;
V_188 -> error = V_52 -> V_231 . V_233 ;
if ( V_188 -> error )
F_72 ( & V_188 -> error -> V_234 ) ;
F_30 ( & V_52 -> V_231 . V_232 , V_93 ) ;
V_81 -> V_226 = V_188 ;
return 0 ;
}
static int F_73 ( struct V_227 * V_227 , struct V_81 * V_81 )
{
struct V_187 * V_188 = V_81 -> V_226 ;
if ( V_188 -> error )
F_74 ( & V_188 -> error -> V_234 , V_235 ) ;
F_75 ( V_188 ) ;
return 0 ;
}
static T_7 F_76 ( struct V_81 * V_81 , char T_8 * V_236 ,
T_4 V_56 , T_9 * V_159 )
{
struct V_187 * V_188 = V_81 -> V_226 ;
struct V_153 V_237 ;
T_9 V_238 = 0 ;
T_7 V_239 = 0 ;
int V_57 = 0 ;
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
V_237 . V_26 = V_56 + 1 > V_214 ? V_56 + 1 : V_214 ;
V_237 . V_162 = F_77 ( V_237 . V_26 ,
V_240 | V_241 | V_242 ) ;
if ( V_237 . V_162 == NULL ) {
V_237 . V_26 = V_214 ;
V_237 . V_162 = F_77 ( V_237 . V_26 , V_240 ) ;
}
if ( V_237 . V_162 == NULL ) {
V_237 . V_26 = 128 ;
V_237 . V_162 = F_77 ( V_237 . V_26 , V_240 ) ;
}
if ( V_237 . V_162 == NULL )
return - V_230 ;
V_237 . V_42 = * V_159 ;
V_57 = F_63 ( V_188 , & V_237 ) ;
if ( V_57 )
goto V_243;
if ( V_237 . V_156 == 0 && V_237 . V_155 ) {
V_57 = V_237 . V_155 ;
goto V_243;
}
V_239 = F_78 ( V_236 , V_56 , & V_238 ,
V_237 . V_162 ,
V_237 . V_156 ) ;
if ( V_239 < 0 )
V_57 = V_239 ;
else
* V_159 = V_237 . V_42 + V_239 ;
V_243:
F_75 ( V_237 . V_162 ) ;
return V_57 ? : V_239 ;
}
static int
F_79 ( void * V_4 , T_10 * V_244 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_52 = V_9 -> V_53 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
* V_244 = V_52 -> V_245 ;
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int
F_80 ( void * V_4 , T_10 V_244 )
{
struct V_8 * V_9 = V_4 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_81 ( V_9 , V_244 ) ;
F_15 ( & V_9 -> V_58 ) ;
return V_57 ;
}
static int F_82 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
T_11 V_247 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_247 = F_83 ( V_248 ) ;
F_15 ( & V_9 -> V_58 ) ;
F_4 ( V_3 , L_142 , ( V_247 >> 8 ) & 0x3f , ( V_247 & 0x3f ) ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
int V_57 ;
if ( F_85 ( V_9 ) ) {
T_11 V_249 = F_83 ( V_250 ) ;
T_11 V_251 = F_83 ( V_252 ) ;
F_4 ( V_3 , L_143 , ( V_249 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_144 , V_249 & 0x3f ) ;
F_4 ( V_3 , L_145 , ( V_251 & V_253 ) >>
V_254 ) ;
F_4 ( V_3 , L_146 ,
( V_251 & V_255 ) >> V_256 ) ;
} else if ( ( F_41 ( V_9 ) || F_42 ( V_9 ) ) && ! F_36 ( V_9 ) ) {
T_5 V_257 = F_37 ( V_258 ) ;
T_5 V_259 = F_37 ( V_260 ) ;
T_5 V_261 = F_37 ( V_262 ) ;
T_5 V_263 , V_264 ;
T_5 V_265 , V_266 , V_267 ;
T_5 V_268 , V_269 , V_270 ;
int V_271 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_86 ( V_52 ) ;
V_263 = F_37 ( V_272 ) ;
V_265 = F_37 ( V_273 ) ;
V_266 = F_37 ( V_274 ) ;
V_267 = F_37 ( V_275 ) ;
V_268 = F_37 ( V_276 ) ;
V_269 = F_37 ( V_277 ) ;
V_270 = F_37 ( V_278 ) ;
if ( F_87 ( V_9 ) )
V_264 = ( V_263 & V_279 ) >> V_280 ;
else
V_264 = ( V_263 & V_281 ) >> V_282 ;
V_264 *= V_283 ;
F_88 ( V_52 ) ;
F_15 ( & V_9 -> V_58 ) ;
F_4 ( V_3 , L_147 , V_257 ) ;
F_4 ( V_3 , L_148 , V_263 ) ;
F_4 ( V_3 , L_149 ,
( V_257 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_150 ,
V_257 & 0xff ) ;
F_4 ( V_3 , L_151 ,
V_259 & 0xff ) ;
F_4 ( V_3 , L_152 , V_264 ) ;
F_4 ( V_3 , L_153 , V_265 &
V_284 ) ;
F_4 ( V_3 , L_154 , V_266 &
V_285 ) ;
F_4 ( V_3 , L_155 , V_267 &
V_285 ) ;
F_4 ( V_3 , L_156 , V_268 &
V_286 ) ;
F_4 ( V_3 , L_157 , V_269 &
V_285 ) ;
F_4 ( V_3 , L_158 , V_270 &
V_285 ) ;
V_271 = ( V_261 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_159 ,
V_271 * V_283 ) ;
V_271 = ( V_261 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_160 ,
V_271 * V_283 ) ;
V_271 = V_261 & 0xff ;
F_4 ( V_3 , L_161 ,
V_271 * V_283 ) ;
F_4 ( V_3 , L_162 ,
V_52 -> V_287 . V_288 * V_283 ) ;
} else if ( F_36 ( V_9 ) ) {
T_5 V_289 , V_244 ;
F_89 ( & V_52 -> V_287 . V_290 ) ;
V_289 = F_90 ( V_52 , V_291 ) ;
F_4 ( V_3 , L_163 , V_289 ) ;
F_4 ( V_3 , L_164 , V_52 -> V_292 ) ;
V_244 = F_90 ( V_52 , V_293 ) ;
F_4 ( V_3 , L_165 ,
F_91 ( V_52 -> V_292 , V_244 ) ) ;
V_244 = F_90 ( V_52 , V_294 ) ;
F_4 ( V_3 , L_166 ,
F_91 ( V_52 -> V_292 , V_244 ) ) ;
F_4 ( V_3 , L_167 ,
F_91 ( V_52 -> V_292 ,
( V_289 >> 8 ) & 0xff ) ) ;
F_15 ( & V_52 -> V_287 . V_290 ) ;
} else {
F_4 ( V_3 , L_168 ) ;
}
return 0 ;
}
static int F_92 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
T_5 V_295 ;
int V_57 , V_110 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
for ( V_110 = 0 ; V_110 < 16 ; V_110 ++ ) {
V_295 = F_37 ( V_296 + V_110 * 4 ) ;
F_4 ( V_3 , L_169 , V_110 , V_295 ,
( V_295 & V_297 ) >> V_298 ) ;
}
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static inline int F_93 ( int V_299 )
{
return 1250 - ( V_299 * 25 ) ;
}
static int F_94 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
T_5 V_300 ;
int V_57 , V_110 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
for ( V_110 = 1 ; V_110 <= 32 ; V_110 ++ ) {
V_300 = F_37 ( V_301 + V_110 * 4 ) ;
F_4 ( V_3 , L_170 , V_110 , V_300 ) ;
}
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
T_5 V_302 , V_303 ;
T_11 V_304 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_302 = F_37 ( V_305 ) ;
V_303 = F_37 ( V_306 ) ;
V_304 = F_83 ( V_248 ) ;
F_15 ( & V_9 -> V_58 ) ;
F_4 ( V_3 , L_171 , ( V_302 & V_307 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_172 ,
( V_302 & V_308 ) >>
V_309 ) ;
F_4 ( V_3 , L_173 ,
V_302 & V_310 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_174 ,
V_302 & V_311 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_175 ,
V_302 & V_312 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_176 ,
( V_302 & V_313 ) >> V_314 ) ;
F_4 ( V_3 , L_177 ,
( V_302 & V_315 ) >> V_316 ) ;
F_4 ( V_3 , L_178 , ( V_302 & V_317 ) ) ;
F_4 ( V_3 , L_179 , ( V_304 & 0x3f ) ) ;
F_4 ( V_3 , L_180 , ( ( V_304 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_181 ,
( V_303 & V_318 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_182 ) ;
switch ( V_303 & V_319 ) {
case V_320 :
F_4 ( V_3 , L_183 ) ;
break;
case V_321 :
F_4 ( V_3 , L_184 ) ;
break;
case V_322 :
F_4 ( V_3 , L_185 ) ;
break;
case V_323 :
F_4 ( V_3 , L_186 ) ;
break;
case V_324 :
F_4 ( V_3 , L_187 ) ;
break;
case V_325 :
F_4 ( V_3 , L_188 ) ;
break;
default:
F_4 ( V_3 , L_189 ) ;
break;
}
return 0 ;
}
static int F_96 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_75 * V_52 = V_9 -> V_53 ;
T_5 V_326 , V_327 , V_328 , V_329 = 0 ;
unsigned V_330 ;
int V_56 = 0 , V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_97 ( & V_52 -> V_331 ) ;
V_330 = V_52 -> V_330 ;
F_98 ( & V_52 -> V_331 ) ;
if ( V_330 ) {
F_4 ( V_3 , L_190
L_191 ) ;
} else {
while ( V_56 ++ < 50 && ( F_99 ( V_332 ) & 1 ) )
F_100 ( 10 ) ;
F_4 ( V_3 , L_192 , F_1 ( V_56 < 51 ) ) ;
}
V_327 = F_101 ( V_52 -> V_333 + V_334 ) ;
F_102 ( false , V_334 , V_327 , 4 ) ;
V_326 = F_37 ( V_335 ) ;
V_328 = F_37 ( V_336 ) ;
F_15 ( & V_9 -> V_58 ) ;
F_89 ( & V_52 -> V_287 . V_290 ) ;
F_103 ( V_52 , V_337 , & V_329 ) ;
F_15 ( & V_52 -> V_287 . V_290 ) ;
F_4 ( V_3 , L_193 ,
F_1 ( V_326 & V_338 ) ) ;
F_4 ( V_3 , L_173 ,
F_1 ( V_326 & V_339 ) ) ;
F_4 ( V_3 , L_174 ,
F_1 ( ( V_326 & V_340 ) ==
V_341 ) ) ;
F_4 ( V_3 , L_194 ,
F_1 ( V_328 & V_342 ) ) ;
F_4 ( V_3 , L_195 ,
F_1 ( V_328 & V_343 ) ) ;
F_4 ( V_3 , L_196 ,
F_1 ( V_328 & V_344 ) ) ;
F_4 ( V_3 , L_197 ,
F_1 ( V_328 & V_345 ) ) ;
F_4 ( V_3 , L_198 ) ;
switch ( V_327 & V_346 ) {
case V_347 :
if ( V_327 & V_348 )
F_4 ( V_3 , L_199 ) ;
else
F_4 ( V_3 , L_183 ) ;
break;
case V_349 :
F_4 ( V_3 , L_200 ) ;
break;
case V_350 :
F_4 ( V_3 , L_201 ) ;
break;
case V_351 :
F_4 ( V_3 , L_202 ) ;
break;
default:
F_4 ( V_3 , L_203 ) ;
break;
}
F_4 ( V_3 , L_204 ,
F_1 ( V_327 & V_348 ) ) ;
F_4 ( V_3 , L_205 ,
F_37 ( V_352 ) ) ;
F_4 ( V_3 , L_206 ,
F_37 ( V_353 ) ) ;
F_4 ( V_3 , L_207 ,
F_37 ( V_354 ) ) ;
F_4 ( V_3 , L_208 ,
F_37 ( V_355 ) ) ;
F_4 ( V_3 , L_209 ,
F_104 ( ( ( V_329 >> 0 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_210 ,
F_104 ( ( ( V_329 >> 8 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_211 ,
F_104 ( ( ( V_329 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_41 ( V_9 ) || F_42 ( V_9 ) )
return F_96 ( V_3 ) ;
else
return F_95 ( V_3 ) ;
}
static int F_106 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
if ( ! F_107 ( V_9 ) ) {
F_4 ( V_3 , L_212 ) ;
return 0 ;
}
if ( F_108 ( V_9 ) ) {
F_4 ( V_3 , L_213 ) ;
} else {
F_4 ( V_3 , L_214 ) ;
switch ( V_52 -> V_356 ) {
case V_357 :
F_4 ( V_3 , L_215 ) ;
break;
case V_358 :
F_4 ( V_3 , L_216 ) ;
break;
case V_359 :
F_4 ( V_3 , L_217 ) ;
break;
case V_360 :
F_4 ( V_3 , L_218 ) ;
break;
case V_361 :
F_4 ( V_3 , L_219 ) ;
break;
case V_362 :
F_4 ( V_3 , L_220 ) ;
break;
case V_363 :
F_4 ( V_3 , L_221 ) ;
break;
case V_364 :
F_4 ( V_3 , L_222 ) ;
break;
default:
F_4 ( V_3 , L_223 ) ;
}
F_4 ( V_3 , L_27 ) ;
}
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_75 * V_52 = V_9 -> V_53 ;
if ( ! F_110 ( V_9 ) ) {
F_111 ( V_3 , L_224 ) ;
return 0 ;
}
if ( F_37 ( V_365 ) & V_366 )
F_111 ( V_3 , L_225 ) ;
else
F_111 ( V_3 , L_226 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
bool V_367 = false ;
if ( F_40 ( V_9 ) )
V_367 = F_37 ( V_368 ) & V_369 ;
else if ( F_113 ( V_9 ) || F_114 ( V_9 ) || F_115 ( V_9 ) )
V_367 = F_37 ( V_370 ) & V_371 ;
else if ( F_116 ( V_9 ) )
V_367 = F_37 ( V_372 ) & V_373 ;
else if ( F_117 ( V_9 ) )
V_367 = F_37 ( V_374 ) & V_375 ;
F_4 ( V_3 , L_227 ,
V_367 ? L_228 : L_229 ) ;
return 0 ;
}
static int F_118 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
unsigned long V_376 , V_377 , V_378 ;
int V_57 ;
if ( ! F_85 ( V_9 ) )
return - V_379 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_376 = F_119 ( V_52 ) ;
V_377 = F_120 ( V_52 ) ;
V_378 = F_121 ( V_52 ) ;
F_15 ( & V_9 -> V_58 ) ;
F_4 ( V_3 , L_230 , V_376 ) ;
F_4 ( V_3 , L_231 , V_377 ) ;
F_4 ( V_3 , L_232 , V_378 ) ;
F_4 ( V_3 , L_233 , V_377 + V_378 ) ;
return 0 ;
}
static int F_122 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
int V_57 ;
int V_380 , V_381 ;
if ( ! ( F_41 ( V_9 ) || F_42 ( V_9 ) ) ) {
F_4 ( V_3 , L_234 ) ;
return 0 ;
}
V_57 = F_14 ( & V_52 -> V_287 . V_290 ) ;
if ( V_57 )
return V_57 ;
F_4 ( V_3 , L_235 ) ;
for ( V_380 = V_52 -> V_287 . V_382 ;
V_380 <= V_52 -> V_287 . V_383 ;
V_380 ++ ) {
V_381 = V_380 ;
F_103 ( V_52 ,
V_384 ,
& V_381 ) ;
F_4 ( V_3 , L_236 ,
V_380 * V_283 ,
( ( V_381 >> 0 ) & 0xff ) * 100 ,
( ( V_381 >> 8 ) & 0xff ) * 100 ) ;
}
F_15 ( & V_52 -> V_287 . V_290 ) ;
return 0 ;
}
static int F_123 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_4 ( V_3 , L_237 , ( unsigned long ) F_37 ( 0x112f4 ) ) ;
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_385 * V_386 = & V_52 -> V_386 ;
void * V_4 = F_77 ( V_387 , V_229 ) ;
int V_57 ;
if ( V_4 == NULL )
return - V_230 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
goto V_243;
if ( V_386 -> V_388 ) {
F_125 ( V_4 , V_386 -> V_388 , V_387 ) ;
F_126 ( V_3 , V_4 , V_387 ) ;
}
F_15 ( & V_9 -> V_58 ) ;
V_243:
F_75 ( V_4 ) ;
return 0 ;
}
static int F_127 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_389 * V_390 ;
struct V_391 * V_392 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_393 . V_394 ) ;
if ( V_57 )
return V_57 ;
V_390 = V_52 -> V_395 ;
V_392 = F_128 ( V_390 -> V_396 . V_392 ) ;
F_4 ( V_3 , L_238 ,
V_392 -> V_25 . V_397 ,
V_392 -> V_25 . V_398 ,
V_392 -> V_25 . V_399 ,
V_392 -> V_25 . V_400 ,
F_29 ( & V_392 -> V_25 . V_401 . V_401 ) ) ;
F_12 ( V_3 , V_392 -> V_15 ) ;
F_4 ( V_3 , L_27 ) ;
F_15 ( & V_9 -> V_393 . V_394 ) ;
F_89 ( & V_9 -> V_393 . V_402 ) ;
F_16 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_392 -> V_25 == V_390 -> V_396 . V_392 )
continue;
F_4 ( V_3 , L_239 ,
V_392 -> V_25 . V_397 ,
V_392 -> V_25 . V_398 ,
V_392 -> V_25 . V_399 ,
V_392 -> V_25 . V_400 ,
F_29 ( & V_392 -> V_25 . V_401 . V_401 ) ) ;
F_12 ( V_3 , V_392 -> V_15 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_15 ( & V_9 -> V_393 . V_402 ) ;
return 0 ;
}
static int F_129 ( struct V_2 * V_3 , void * V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_52 = V_9 -> V_53 ;
struct V_107 * V_47 ;
int V_57 , V_110 ;
V_57 = F_14 ( & V_9 -> V_393 . V_394 ) ;
if ( V_57 )
return V_57 ;
if ( V_52 -> V_403 . V_404 ) {
F_4 ( V_3 , L_240 ) ;
F_12 ( V_3 , V_52 -> V_403 . V_404 ) ;
F_4 ( V_3 , L_27 ) ;
}
if ( V_52 -> V_403 . V_405 ) {
F_4 ( V_3 , L_241 ) ;
F_12 ( V_3 , V_52 -> V_403 . V_405 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_32 (ring, dev_priv, i) {
if ( V_47 -> V_406 ) {
F_4 ( V_3 , L_242 , V_47 -> V_36 ) ;
F_12 ( V_3 , V_47 -> V_406 -> V_15 ) ;
F_4 ( V_3 , L_27 ) ;
}
}
F_15 ( & V_9 -> V_393 . V_394 ) ;
return 0 ;
}
static int F_130 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_75 * V_52 = V_9 -> V_53 ;
unsigned V_330 ;
F_97 ( & V_52 -> V_331 ) ;
V_330 = V_52 -> V_330 ;
F_98 ( & V_52 -> V_331 ) ;
F_4 ( V_3 , L_243 , V_330 ) ;
return 0 ;
}
static const char * F_131 ( unsigned V_407 )
{
switch( V_407 ) {
case V_408 :
return L_244 ;
case V_409 :
return L_245 ;
case V_410 :
return L_246 ;
case V_411 :
return L_247 ;
case V_412 :
return L_248 ;
case V_413 :
return L_249 ;
case V_414 :
return L_250 ;
case V_415 :
return L_251 ;
}
return L_252 ;
}
static int F_132 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_75 * V_52 = V_9 -> V_53 ;
int V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
F_4 ( V_3 , L_253 ,
F_131 ( V_52 -> V_60 . V_416 ) ) ;
F_4 ( V_3 , L_254 ,
F_131 ( V_52 -> V_60 . V_417 ) ) ;
if ( F_133 ( V_9 ) || F_134 ( V_9 ) ) {
F_4 ( V_3 , L_255 ,
F_37 ( V_418 ) ) ;
F_4 ( V_3 , L_256 ,
F_83 ( V_419 ) ) ;
F_4 ( V_3 , L_257 ,
F_83 ( V_420 ) ) ;
} else if ( F_41 ( V_9 ) || F_42 ( V_9 ) ) {
F_4 ( V_3 , L_258 ,
F_37 ( V_421 ) ) ;
F_4 ( V_3 , L_259 ,
F_37 ( V_422 ) ) ;
F_4 ( V_3 , L_260 ,
F_37 ( V_423 ) ) ;
F_4 ( V_3 , L_261 ,
F_37 ( V_424 ) ) ;
F_4 ( V_3 , L_262 ,
F_37 ( V_425 ) ) ;
F_4 ( V_3 , L_263 ,
F_37 ( V_426 ) ) ;
}
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_135 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_75 * V_52 = V_9 -> V_53 ;
struct V_107 * V_47 ;
int V_110 , V_57 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
if ( F_3 ( V_9 ) -> V_13 == 6 )
F_4 ( V_3 , L_264 , F_37 ( V_427 ) ) ;
F_32 (ring, dev_priv, i) {
F_4 ( V_3 , L_265 , V_47 -> V_36 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_264 , F_37 ( F_136 ( V_47 ) ) ) ;
F_4 ( V_3 , L_266 , F_37 ( F_137 ( V_47 ) ) ) ;
F_4 ( V_3 , L_267 , F_37 ( F_138 ( V_47 ) ) ) ;
F_4 ( V_3 , L_268 , F_37 ( F_139 ( V_47 ) ) ) ;
}
if ( V_52 -> V_60 . V_428 ) {
struct V_429 * V_430 = V_52 -> V_60 . V_428 ;
F_4 ( V_3 , L_269 ) ;
F_4 ( V_3 , L_270 , V_430 -> V_431 ) ;
}
F_4 ( V_3 , L_271 , F_37 ( V_432 ) ) ;
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int F_140 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_75 * V_52 = V_9 -> V_53 ;
int V_57 ;
if ( ! F_36 ( V_9 ) ) {
F_4 ( V_3 , L_272 ) ;
return 0 ;
}
V_57 = F_14 ( & V_52 -> V_433 ) ;
if ( V_57 )
return V_57 ;
F_4 ( V_3 , L_273 , F_37 ( V_434 ) ) ;
F_4 ( V_3 , L_274 ,
F_141 ( V_52 , V_435 ) ) ;
F_4 ( V_3 , L_275 ,
F_141 ( V_52 , V_436 ) ) ;
F_4 ( V_3 , L_276 ,
F_141 ( V_52 , V_437 ) ) ;
F_4 ( V_3 , L_277 ,
F_141 ( V_52 , V_438 ) ) ;
F_4 ( V_3 , L_278 ,
F_141 ( V_52 , V_439 ) ) ;
F_4 ( V_3 , L_279 ,
F_141 ( V_52 , V_440 ) ) ;
F_4 ( V_3 , L_280 ,
F_141 ( V_52 , V_441 ) ) ;
F_4 ( V_3 , L_281 ,
F_141 ( V_52 , V_442 ) ) ;
F_4 ( V_3 , L_282 ,
F_141 ( V_52 , V_443 ) ) ;
F_15 ( & V_52 -> V_433 ) ;
return 0 ;
}
static int
F_142 ( void * V_4 , T_10 * V_244 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_52 = V_9 -> V_53 ;
* V_244 = F_29 ( & V_52 -> V_231 . V_444 ) ;
return 0 ;
}
static int
F_143 ( void * V_4 , T_10 V_244 )
{
struct V_8 * V_9 = V_4 ;
F_144 ( L_283 , V_244 ) ;
F_145 ( V_9 , V_244 ) ;
return 0 ;
}
static int
F_146 ( void * V_4 , T_10 * V_244 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_52 = V_9 -> V_53 ;
* V_244 = V_52 -> V_231 . V_445 ;
return 0 ;
}
static int
F_147 ( void * V_4 , T_10 V_244 )
{
struct V_8 * V_9 = V_4 ;
struct V_75 * V_52 = V_9 -> V_53 ;
int V_57 ;
F_68 ( L_284 , V_244 ) ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_52 -> V_231 . V_445 = V_244 ;
F_15 ( & V_9 -> V_58 ) ;
return 0 ;
}
static int
F_148 ( void * V_4 , T_10 * V_244 )
{
* V_244 = V_446 ;
return 0 ;
}
static int
F_149 ( void * V_4 , T_10 V_244 )
{
struct V_8 * V_9 = V_4 ;
struct V_75 * V_52 = V_9 -> V_53 ;
struct V_14 * V_15 , * V_447 ;
int V_57 ;
F_68 ( L_285 , V_244 ) ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
if ( V_244 & V_448 ) {
V_57 = F_150 ( V_9 ) ;
if ( V_57 )
goto V_449;
}
if ( V_244 & ( V_450 | V_448 ) )
F_151 ( V_9 ) ;
if ( V_244 & V_451 ) {
F_152 (obj, next, &dev_priv->mm.inactive_list, mm_list)
if ( V_15 -> V_17 == 0 ) {
V_57 = F_153 ( V_15 ) ;
if ( V_57 )
goto V_449;
}
}
if ( V_244 & V_452 ) {
F_152 (obj, next, &dev_priv->mm.unbound_list,
global_list)
if ( V_15 -> V_453 == 0 ) {
V_57 = F_154 ( V_15 ) ;
if ( V_57 )
goto V_449;
}
}
V_449:
F_15 ( & V_9 -> V_58 ) ;
return V_57 ;
}
static int
F_155 ( void * V_4 , T_10 * V_244 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_52 = V_9 -> V_53 ;
int V_57 ;
if ( ! ( F_41 ( V_9 ) || F_42 ( V_9 ) ) )
return - V_379 ;
V_57 = F_14 ( & V_52 -> V_287 . V_290 ) ;
if ( V_57 )
return V_57 ;
if ( F_36 ( V_9 ) )
* V_244 = F_91 ( V_52 -> V_292 ,
V_52 -> V_287 . V_383 ) ;
else
* V_244 = V_52 -> V_287 . V_383 * V_283 ;
F_15 ( & V_52 -> V_287 . V_290 ) ;
return 0 ;
}
static int
F_156 ( void * V_4 , T_10 V_244 )
{
struct V_8 * V_9 = V_4 ;
struct V_75 * V_52 = V_9 -> V_53 ;
int V_57 ;
if ( ! ( F_41 ( V_9 ) || F_42 ( V_9 ) ) )
return - V_379 ;
F_68 ( L_286 , V_244 ) ;
V_57 = F_14 ( & V_52 -> V_287 . V_290 ) ;
if ( V_57 )
return V_57 ;
if ( F_36 ( V_9 ) ) {
V_244 = F_157 ( V_52 -> V_292 , V_244 ) ;
V_52 -> V_287 . V_383 = V_244 ;
F_158 ( V_9 , V_244 ) ;
} else {
F_159 ( V_244 , V_283 ) ;
V_52 -> V_287 . V_383 = V_244 ;
F_158 ( V_9 , V_244 ) ;
}
F_15 ( & V_52 -> V_287 . V_290 ) ;
return 0 ;
}
static int
F_160 ( void * V_4 , T_10 * V_244 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_52 = V_9 -> V_53 ;
int V_57 ;
if ( ! ( F_41 ( V_9 ) || F_42 ( V_9 ) ) )
return - V_379 ;
V_57 = F_14 ( & V_52 -> V_287 . V_290 ) ;
if ( V_57 )
return V_57 ;
if ( F_36 ( V_9 ) )
* V_244 = F_91 ( V_52 -> V_292 ,
V_52 -> V_287 . V_382 ) ;
else
* V_244 = V_52 -> V_287 . V_382 * V_283 ;
F_15 ( & V_52 -> V_287 . V_290 ) ;
return 0 ;
}
static int
F_161 ( void * V_4 , T_10 V_244 )
{
struct V_8 * V_9 = V_4 ;
struct V_75 * V_52 = V_9 -> V_53 ;
int V_57 ;
if ( ! ( F_41 ( V_9 ) || F_42 ( V_9 ) ) )
return - V_379 ;
F_68 ( L_287 , V_244 ) ;
V_57 = F_14 ( & V_52 -> V_287 . V_290 ) ;
if ( V_57 )
return V_57 ;
if ( F_36 ( V_9 ) ) {
V_244 = F_157 ( V_52 -> V_292 , V_244 ) ;
V_52 -> V_287 . V_382 = V_244 ;
F_162 ( V_9 , V_244 ) ;
} else {
F_159 ( V_244 , V_283 ) ;
V_52 -> V_287 . V_382 = V_244 ;
F_158 ( V_9 , V_244 ) ;
}
F_15 ( & V_52 -> V_287 . V_290 ) ;
return 0 ;
}
static int
F_163 ( void * V_4 , T_10 * V_244 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_52 = V_9 -> V_53 ;
T_5 V_454 ;
int V_57 ;
if ( ! ( F_41 ( V_9 ) || F_42 ( V_9 ) ) )
return - V_379 ;
V_57 = F_14 ( & V_9 -> V_58 ) ;
if ( V_57 )
return V_57 ;
V_454 = F_37 ( V_455 ) ;
F_15 ( & V_52 -> V_9 -> V_58 ) ;
* V_244 = ( V_454 & V_456 ) >> V_457 ;
return 0 ;
}
static int
F_164 ( void * V_4 , T_10 V_244 )
{
struct V_8 * V_9 = V_4 ;
struct V_75 * V_52 = V_9 -> V_53 ;
T_5 V_454 ;
if ( ! ( F_41 ( V_9 ) || F_42 ( V_9 ) ) )
return - V_379 ;
if ( V_244 > 3 )
return - V_64 ;
F_68 ( L_288 , V_244 ) ;
V_454 = F_37 ( V_455 ) ;
V_454 &= ~ V_456 ;
V_454 |= ( V_244 << V_457 ) ;
F_165 ( V_455 , V_454 ) ;
return 0 ;
}
static int
F_166 ( struct V_458 * V_10 ,
struct V_459 * V_460 ,
const void * V_461 )
{
struct V_5 * V_6 ;
V_6 = F_77 ( sizeof( struct V_5 ) , V_229 ) ;
if ( V_6 == NULL ) {
F_167 ( V_460 ) ;
return - V_230 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_462 = V_460 ;
V_6 -> V_49 = ( void * ) V_461 ;
F_89 ( & V_10 -> V_463 ) ;
F_168 ( & V_6 -> V_48 , & V_10 -> V_464 ) ;
F_15 ( & V_10 -> V_463 ) ;
return 0 ;
}
static int F_169 ( struct V_227 * V_227 , struct V_81 * V_81 )
{
struct V_8 * V_9 = V_227 -> V_228 ;
struct V_75 * V_52 = V_9 -> V_53 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_86 ( V_52 ) ;
return 0 ;
}
static int F_170 ( struct V_227 * V_227 , struct V_81 * V_81 )
{
struct V_8 * V_9 = V_227 -> V_228 ;
struct V_75 * V_52 = V_9 -> V_53 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_88 ( V_52 ) ;
return 0 ;
}
static int F_171 ( struct V_459 * V_465 , struct V_458 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_459 * V_460 ;
V_460 = F_172 ( L_289 ,
V_466 ,
V_465 , V_9 ,
& V_467 ) ;
if ( F_173 ( V_460 ) )
return F_174 ( V_460 ) ;
return F_166 ( V_10 , V_460 , & V_467 ) ;
}
static int F_175 ( struct V_459 * V_465 ,
struct V_458 * V_10 ,
const char * V_36 ,
const struct V_468 * V_469 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_459 * V_460 ;
V_460 = F_172 ( V_36 ,
V_470 | V_471 ,
V_465 , V_9 ,
V_469 ) ;
if ( F_173 ( V_460 ) )
return F_174 ( V_460 ) ;
return F_166 ( V_10 , V_460 , V_469 ) ;
}
int F_176 ( struct V_458 * V_10 )
{
int V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_290 ,
& V_473 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_171 ( V_10 -> V_472 , V_10 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_291 ,
& V_474 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_292 ,
& V_475 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_293 ,
& V_476 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_294 ,
& V_477 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_295 ,
& V_478 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_296 ,
& V_479 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_175 ( V_10 -> V_472 , V_10 ,
L_297 ,
& V_480 ) ;
if ( V_57 )
return V_57 ;
return F_177 ( V_481 ,
V_482 ,
V_10 -> V_472 , V_10 ) ;
}
void F_178 ( struct V_458 * V_10 )
{
F_179 ( V_481 ,
V_482 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_467 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_473 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_474 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_475 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_476 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_478 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_477 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_479 ,
1 , V_10 ) ;
F_179 ( (struct V_483 * ) & V_480 ,
1 , V_10 ) ;
}
