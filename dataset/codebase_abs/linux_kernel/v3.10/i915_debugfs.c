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
V_14 ;
#undef F_6
#undef F_7
return 0 ;
}
static const char * F_8 ( struct V_15 * V_16 )
{
if ( V_16 -> V_17 > 0 )
return L_5 ;
else if ( V_16 -> V_18 > 0 )
return L_6 ;
else
return L_7 ;
}
static const char * F_9 ( struct V_15 * V_16 )
{
switch ( V_16 -> V_19 ) {
default:
case V_20 : return L_7 ;
case V_21 : return L_8 ;
case V_22 : return L_9 ;
}
}
static const char * F_10 ( int type )
{
switch ( type ) {
case V_23 : return L_10 ;
case V_24 : return L_11 ;
case V_25 : return L_12 ;
default: return L_13 ;
}
}
static void
F_11 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
F_4 ( V_3 , L_14 ,
& V_16 -> V_26 ,
F_8 ( V_16 ) ,
F_9 ( V_16 ) ,
V_16 -> V_26 . V_27 / 1024 ,
V_16 -> V_26 . V_28 ,
V_16 -> V_26 . V_29 ,
V_16 -> V_30 ,
V_16 -> V_31 ,
V_16 -> V_32 ,
F_10 ( V_16 -> V_33 ) ,
V_16 -> V_34 ? L_15 : L_13 ,
V_16 -> V_35 == V_36 ? L_16 : L_13 ) ;
if ( V_16 -> V_26 . V_37 )
F_4 ( V_3 , L_17 , V_16 -> V_26 . V_37 ) ;
if ( V_16 -> V_18 )
F_4 ( V_3 , L_18 , V_16 -> V_18 ) ;
if ( V_16 -> V_38 != V_39 )
F_4 ( V_3 , L_19 , V_16 -> V_38 ) ;
if ( V_16 -> V_40 != NULL )
F_4 ( V_3 , L_20 ,
V_16 -> V_41 , ( unsigned int ) V_16 -> V_40 -> V_27 ) ;
if ( V_16 -> V_42 )
F_4 ( V_3 , L_21 , V_16 -> V_42 -> V_43 ) ;
if ( V_16 -> V_44 || V_16 -> V_45 ) {
char V_46 [ 3 ] , * V_47 = V_46 ;
if ( V_16 -> V_44 )
* V_47 ++ = 'p' ;
if ( V_16 -> V_45 )
* V_47 ++ = 'f' ;
* V_47 = '\0' ;
F_4 ( V_3 , L_22 , V_46 ) ;
}
if ( V_16 -> V_48 != NULL )
F_4 ( V_3 , L_23 , V_16 -> V_48 -> V_37 ) ;
}
static int F_12 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_49 = ( T_2 ) V_6 -> V_50 -> V_4 ;
struct V_51 * V_52 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_15 * V_16 ;
T_4 V_55 , V_56 ;
int V_57 , V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
switch ( V_49 ) {
case V_60 :
F_4 ( V_3 , L_24 ) ;
V_52 = & V_53 -> V_61 . V_62 ;
break;
case V_63 :
F_4 ( V_3 , L_25 ) ;
V_52 = & V_53 -> V_61 . V_64 ;
break;
default:
F_14 ( & V_9 -> V_59 ) ;
return - V_65 ;
}
V_55 = V_56 = V_57 = 0 ;
F_15 (obj, head, mm_list) {
F_4 ( V_3 , L_26 ) ;
F_11 ( V_3 , V_16 ) ;
F_4 ( V_3 , L_27 ) ;
V_55 += V_16 -> V_26 . V_27 ;
V_56 += V_16 -> V_40 -> V_27 ;
V_57 ++ ;
}
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_28 ,
V_57 , V_55 , V_56 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
T_5 V_57 , V_67 , V_68 ;
T_4 V_27 , V_69 , V_70 ;
struct V_15 * V_16 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_29 ,
V_53 -> V_61 . V_71 ,
V_53 -> V_61 . V_72 ) ;
V_27 = V_57 = V_69 = V_67 = 0 ;
F_17 ( & V_53 -> V_61 . V_73 , V_74 ) ;
F_4 ( V_3 , L_30 ,
V_57 , V_67 , V_27 , V_69 ) ;
V_27 = V_57 = V_69 = V_67 = 0 ;
F_17 ( & V_53 -> V_61 . V_62 , V_75 ) ;
F_4 ( V_3 , L_31 ,
V_57 , V_67 , V_27 , V_69 ) ;
V_27 = V_57 = V_69 = V_67 = 0 ;
F_17 ( & V_53 -> V_61 . V_64 , V_75 ) ;
F_4 ( V_3 , L_32 ,
V_57 , V_67 , V_27 , V_69 ) ;
V_27 = V_57 = V_70 = V_68 = 0 ;
F_15 (obj, &dev_priv->mm.unbound_list, gtt_list) {
V_27 += V_16 -> V_26 . V_27 , ++ V_57 ;
if ( V_16 -> V_35 == V_36 )
V_70 += V_16 -> V_26 . V_27 , ++ V_68 ;
}
F_4 ( V_3 , L_33 , V_57 , V_27 ) ;
V_27 = V_57 = V_69 = V_67 = 0 ;
F_15 (obj, &dev_priv->mm.bound_list, gtt_list) {
if ( V_16 -> V_45 ) {
V_27 += V_16 -> V_40 -> V_27 ;
++ V_57 ;
}
if ( V_16 -> V_44 ) {
V_69 += V_16 -> V_40 -> V_27 ;
++ V_67 ;
}
if ( V_16 -> V_35 == V_36 ) {
V_70 += V_16 -> V_26 . V_27 ;
++ V_68 ;
}
}
F_4 ( V_3 , L_34 ,
V_68 , V_70 ) ;
F_4 ( V_3 , L_35 ,
V_67 , V_69 ) ;
F_4 ( V_3 , L_36 ,
V_57 , V_27 ) ;
F_4 ( V_3 , L_37 ,
V_53 -> V_76 . V_77 ,
V_53 -> V_76 . V_78 - V_53 -> V_76 . V_43 ) ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_2 V_49 = ( T_2 ) V_6 -> V_50 -> V_4 ;
struct V_66 * V_53 = V_9 -> V_54 ;
struct V_15 * V_16 ;
T_4 V_55 , V_56 ;
int V_57 , V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_55 = V_56 = V_57 = 0 ;
F_15 (obj, &dev_priv->mm.bound_list, gtt_list) {
if ( V_49 == V_79 && V_16 -> V_18 == 0 )
continue;
F_4 ( V_3 , L_26 ) ;
F_11 ( V_3 , V_16 ) ;
F_4 ( V_3 , L_27 ) ;
V_55 += V_16 -> V_26 . V_27 ;
V_56 += V_16 -> V_40 -> V_27 ;
V_57 ++ ;
}
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_28 ,
V_57 , V_55 , V_56 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
unsigned long V_80 ;
struct V_81 * V_82 ;
F_15 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_83 = F_20 ( V_82 -> V_83 ) ;
const char V_84 = F_21 ( V_82 -> V_84 ) ;
struct V_85 * V_86 ;
F_22 ( & V_9 -> V_87 , V_80 ) ;
V_86 = V_82 -> V_88 ;
if ( V_86 == NULL ) {
F_4 ( V_3 , L_38 ,
V_83 , V_84 ) ;
} else {
if ( F_23 ( & V_86 -> V_89 ) < V_90 ) {
F_4 ( V_3 , L_39 ,
V_83 , V_84 ) ;
} else {
F_4 ( V_3 , L_40 ,
V_83 , V_84 ) ;
}
if ( V_86 -> V_91 )
F_4 ( V_3 , L_41 ) ;
else
F_4 ( V_3 , L_42 ) ;
F_4 ( V_3 , L_43 , F_23 ( & V_86 -> V_89 ) ) ;
if ( V_86 -> V_92 ) {
struct V_15 * V_16 = V_86 -> V_92 ;
if ( V_16 )
F_4 ( V_3 , L_44 , V_16 -> V_41 ) ;
}
if ( V_86 -> V_93 ) {
struct V_15 * V_16 = V_86 -> V_93 ;
if ( V_16 )
F_4 ( V_3 , L_45 , V_16 -> V_41 ) ;
}
}
F_24 ( & V_9 -> V_87 , V_80 ) ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_94 * V_48 ;
struct V_95 * V_96 ;
int V_58 , V_57 , V_97 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_57 = 0 ;
F_26 (ring, dev_priv, i) {
if ( F_27 ( & V_48 -> V_98 ) )
continue;
F_4 ( V_3 , L_46 , V_48 -> V_37 ) ;
F_15 (gem_request,
&ring->request_list,
list) {
F_4 ( V_3 , L_47 ,
V_96 -> V_99 ,
( int ) ( V_100 - V_96 -> V_101 ) ) ;
}
V_57 ++ ;
}
F_14 ( & V_9 -> V_59 ) ;
if ( V_57 == 0 )
F_4 ( V_3 , L_48 ) ;
return 0 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_94 * V_48 )
{
if ( V_48 -> V_102 ) {
F_4 ( V_3 , L_49 ,
V_48 -> V_37 , V_48 -> V_102 ( V_48 , false ) ) ;
}
}
static int F_29 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_94 * V_48 ;
int V_58 , V_97 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_26 (ring, dev_priv, i)
F_28 ( V_3 , V_48 ) ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_94 * V_48 ;
int V_58 , V_97 , V_83 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
if ( F_31 ( V_9 ) ) {
F_4 ( V_3 , L_50 ,
F_32 ( V_103 ) ) ;
F_4 ( V_3 , L_51 ,
F_32 ( V_104 ) ) ;
F_4 ( V_3 , L_52 ,
F_32 ( V_105 ) ) ;
F_4 ( V_3 , L_53 ,
F_32 ( V_106 ) ) ;
F_33 (pipe)
F_4 ( V_3 , L_54 ,
F_20 ( V_83 ) ,
F_32 ( F_34 ( V_83 ) ) ) ;
F_4 ( V_3 , L_55 ,
F_32 ( V_107 ) ) ;
F_4 ( V_3 , L_56 ,
F_32 ( V_108 ) ) ;
F_4 ( V_3 , L_57 ,
F_32 ( V_109 ) ) ;
F_4 ( V_3 , L_58 ,
F_32 ( V_110 ) ) ;
F_4 ( V_3 , L_59 ,
F_32 ( V_111 ) ) ;
F_4 ( V_3 , L_60 ,
F_32 ( V_112 ) ) ;
F_4 ( V_3 , L_61 ,
F_32 ( V_113 ) ) ;
F_4 ( V_3 , L_62 ,
F_32 ( V_114 ) ) ;
F_4 ( V_3 , L_63 ,
F_32 ( V_115 ) ) ;
F_4 ( V_3 , L_64 ,
F_32 ( V_116 ) ) ;
} else if ( ! F_35 ( V_9 ) ) {
F_4 ( V_3 , L_65 ,
F_32 ( V_117 ) ) ;
F_4 ( V_3 , L_66 ,
F_32 ( V_118 ) ) ;
F_4 ( V_3 , L_67 ,
F_32 ( V_119 ) ) ;
F_33 (pipe)
F_4 ( V_3 , L_68 ,
F_20 ( V_83 ) ,
F_32 ( F_34 ( V_83 ) ) ) ;
} else {
F_4 ( V_3 , L_69 ,
F_32 ( V_120 ) ) ;
F_4 ( V_3 , L_70 ,
F_32 ( V_121 ) ) ;
F_4 ( V_3 , L_71 ,
F_32 ( V_122 ) ) ;
F_4 ( V_3 , L_72 ,
F_32 ( V_123 ) ) ;
F_4 ( V_3 , L_73 ,
F_32 ( V_124 ) ) ;
F_4 ( V_3 , L_74 ,
F_32 ( V_125 ) ) ;
F_4 ( V_3 , L_75 ,
F_32 ( V_108 ) ) ;
F_4 ( V_3 , L_76 ,
F_32 ( V_109 ) ) ;
F_4 ( V_3 , L_77 ,
F_32 ( V_110 ) ) ;
}
F_4 ( V_3 , L_78 ,
F_23 ( & V_53 -> V_126 ) ) ;
F_26 (ring, dev_priv, i) {
if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
F_4 ( V_3 ,
L_79 ,
V_48 -> V_37 , F_38 ( V_48 ) ) ;
}
F_28 ( V_3 , V_48 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_97 , V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_80 , V_53 -> V_127 ) ;
F_4 ( V_3 , L_81 , V_53 -> V_128 ) ;
for ( V_97 = 0 ; V_97 < V_53 -> V_128 ; V_97 ++ ) {
struct V_15 * V_16 = V_53 -> V_129 [ V_97 ] . V_16 ;
F_4 ( V_3 , L_82 ,
V_97 , V_53 -> V_129 [ V_97 ] . V_18 ) ;
if ( V_16 == NULL )
F_4 ( V_3 , L_83 ) ;
else
F_11 ( V_3 , V_16 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_94 * V_48 ;
const T_5 * V_130 ;
int V_97 ;
V_48 = & V_53 -> V_48 [ ( T_2 ) V_6 -> V_50 -> V_4 ] ;
V_130 = V_48 -> V_131 . V_132 ;
if ( V_130 == NULL )
return 0 ;
for ( V_97 = 0 ; V_97 < 4096 / sizeof( T_5 ) / 4 ; V_97 += 4 ) {
F_4 ( V_3 , L_84 ,
V_97 * 4 ,
V_130 [ V_97 ] , V_130 [ V_97 + 1 ] , V_130 [ V_97 + 2 ] , V_130 [ V_97 + 3 ] ) ;
}
return 0 ;
}
static const char * F_41 ( int V_48 )
{
switch ( V_48 ) {
case V_133 : return L_85 ;
case V_134 : return L_86 ;
case V_135 : return L_87 ;
default: return L_13 ;
}
}
static const char * F_42 ( int V_136 )
{
if ( V_136 > 0 )
return L_88 ;
else if ( V_136 < 0 )
return L_89 ;
else
return L_13 ;
}
static const char * F_43 ( int V_137 )
{
switch ( V_137 ) {
default:
case V_20 : return L_13 ;
case V_21 : return L_90 ;
case V_22 : return L_91 ;
}
}
static const char * F_44 ( int V_34 )
{
return V_34 ? L_15 : L_13 ;
}
static const char * F_45 ( int V_138 )
{
return V_138 ? L_16 : L_13 ;
}
static void F_46 ( struct V_2 * V_3 ,
const char * V_37 ,
struct V_139 * V_140 ,
int V_57 )
{
F_4 ( V_3 , L_92 , V_37 , V_57 ) ;
while ( V_57 -- ) {
F_4 ( V_3 , L_93 ,
V_140 -> V_41 ,
V_140 -> V_27 ,
V_140 -> V_28 ,
V_140 -> V_29 ,
V_140 -> V_141 , V_140 -> V_142 ,
F_42 ( V_140 -> V_136 ) ,
F_43 ( V_140 -> V_137 ) ,
F_44 ( V_140 -> V_34 ) ,
F_45 ( V_140 -> V_138 ) ,
V_140 -> V_48 != - 1 ? L_7 : L_13 ,
F_41 ( V_140 -> V_48 ) ,
F_10 ( V_140 -> V_33 ) ) ;
if ( V_140 -> V_37 )
F_4 ( V_3 , L_17 , V_140 -> V_37 ) ;
if ( V_140 -> V_38 != V_39 )
F_4 ( V_3 , L_19 , V_140 -> V_38 ) ;
F_4 ( V_3 , L_27 ) ;
V_140 ++ ;
}
}
static void F_47 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
struct V_143 * error ,
unsigned V_48 )
{
F_48 ( V_48 >= V_144 ) ;
F_4 ( V_3 , L_94 , F_41 ( V_48 ) ) ;
F_4 ( V_3 , L_95 , error -> V_52 [ V_48 ] ) ;
F_4 ( V_3 , L_96 , error -> V_145 [ V_48 ] ) ;
F_4 ( V_3 , L_97 , error -> V_146 [ V_48 ] ) ;
F_4 ( V_3 , L_98 , error -> V_147 [ V_48 ] ) ;
F_4 ( V_3 , L_99 , error -> V_148 [ V_48 ] ) ;
F_4 ( V_3 , L_100 , error -> V_149 [ V_48 ] ) ;
F_4 ( V_3 , L_101 , error -> V_150 [ V_48 ] ) ;
if ( V_48 == V_133 && F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_102 , error -> V_151 ) ;
if ( F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_103 , error -> V_152 [ V_48 ] ) ;
F_4 ( V_3 , L_104 , error -> V_153 [ V_48 ] ) ;
F_4 ( V_3 , L_105 , error -> V_154 [ V_48 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_106 , error -> V_155 [ V_48 ] ) ;
F_4 ( V_3 , L_107 , error -> V_156 [ V_48 ] ) ;
F_4 ( V_3 , L_108 ,
error -> V_157 [ V_48 ] [ 0 ] ,
error -> V_158 [ V_48 ] [ 0 ] ) ;
F_4 ( V_3 , L_109 ,
error -> V_157 [ V_48 ] [ 1 ] ,
error -> V_158 [ V_48 ] [ 1 ] ) ;
}
F_4 ( V_3 , L_110 , error -> V_99 [ V_48 ] ) ;
F_4 ( V_3 , L_111 , F_1 ( error -> V_159 [ V_48 ] ) ) ;
F_4 ( V_3 , L_112 , error -> V_160 [ V_48 ] ) ;
F_4 ( V_3 , L_113 , error -> V_161 [ V_48 ] ) ;
}
static int F_49 ( struct V_2 * V_3 , void * V_162 )
{
struct V_163 * V_164 = V_3 -> V_7 ;
struct V_8 * V_9 = V_164 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_143 * error = V_164 -> error ;
struct V_94 * V_48 ;
int V_97 , V_165 , V_166 , V_167 , V_168 ;
if ( ! error ) {
F_4 ( V_3 , L_114 ) ;
return 0 ;
}
F_4 ( V_3 , L_115 , error -> time . V_169 ,
error -> time . V_170 ) ;
F_4 ( V_3 , L_116 V_171 L_27 ) ;
F_4 ( V_3 , L_117 , V_9 -> V_172 ) ;
F_4 ( V_3 , L_118 , error -> V_173 ) ;
F_4 ( V_3 , L_119 , error -> V_174 ) ;
F_4 ( V_3 , L_120 , error -> V_175 ) ;
F_4 ( V_3 , L_121 , error -> V_176 ) ;
F_4 ( V_3 , L_122 , error -> V_177 ) ;
F_4 ( V_3 , L_123 , error -> V_178 ) ;
for ( V_97 = 0 ; V_97 < V_53 -> V_128 ; V_97 ++ )
F_4 ( V_3 , L_124 , V_97 , error -> V_179 [ V_97 ] ) ;
for ( V_97 = 0 ; V_97 < F_50 ( error -> V_180 ) ; V_97 ++ )
F_4 ( V_3 , L_125 , V_97 , error -> V_180 [ V_97 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_126 , error -> error ) ;
F_4 ( V_3 , L_127 , error -> V_181 ) ;
}
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_128 , error -> V_182 ) ;
F_26 (ring, dev_priv, i)
F_47 ( V_3 , V_9 , error , V_97 ) ;
if ( error -> V_183 )
F_46 ( V_3 , L_129 ,
error -> V_183 ,
error -> V_184 ) ;
if ( error -> V_185 )
F_46 ( V_3 , L_130 ,
error -> V_185 ,
error -> V_186 ) ;
for ( V_97 = 0 ; V_97 < F_50 ( error -> V_48 ) ; V_97 ++ ) {
struct V_187 * V_16 ;
if ( ( V_16 = error -> V_48 [ V_97 ] . V_188 ) ) {
F_4 ( V_3 , L_131 ,
V_53 -> V_48 [ V_97 ] . V_37 ,
V_16 -> V_41 ) ;
V_167 = 0 ;
for ( V_166 = 0 ; V_166 < V_16 -> V_189 ; V_166 ++ ) {
for ( V_168 = 0 ; V_168 < V_190 / 4 ; V_168 ++ ) {
F_4 ( V_3 , L_132 , V_167 , V_16 -> V_191 [ V_166 ] [ V_168 ] ) ;
V_167 += 4 ;
}
}
}
if ( error -> V_48 [ V_97 ] . V_192 ) {
F_4 ( V_3 , L_133 ,
V_53 -> V_48 [ V_97 ] . V_37 ,
error -> V_48 [ V_97 ] . V_192 ) ;
for ( V_165 = 0 ; V_165 < error -> V_48 [ V_97 ] . V_192 ; V_165 ++ ) {
F_4 ( V_3 , L_134 ,
error -> V_48 [ V_97 ] . V_193 [ V_165 ] . V_99 ,
error -> V_48 [ V_97 ] . V_193 [ V_165 ] . V_100 ,
error -> V_48 [ V_97 ] . V_193 [ V_165 ] . V_145 ) ;
}
}
if ( ( V_16 = error -> V_48 [ V_97 ] . V_194 ) ) {
F_4 ( V_3 , L_135 ,
V_53 -> V_48 [ V_97 ] . V_37 ,
V_16 -> V_41 ) ;
V_167 = 0 ;
for ( V_166 = 0 ; V_166 < V_16 -> V_189 ; V_166 ++ ) {
for ( V_168 = 0 ; V_168 < V_190 / 4 ; V_168 ++ ) {
F_4 ( V_3 , L_132 ,
V_167 ,
V_16 -> V_191 [ V_166 ] [ V_168 ] ) ;
V_167 += 4 ;
}
}
}
V_16 = error -> V_48 [ V_97 ] . V_195 ;
if ( V_16 ) {
F_4 ( V_3 , L_136 ,
V_53 -> V_48 [ V_97 ] . V_37 ,
V_16 -> V_41 ) ;
V_167 = 0 ;
for ( V_168 = 0 ; V_168 < V_190 / 16 ; V_168 += 4 ) {
F_4 ( V_3 , L_137 ,
V_167 ,
V_16 -> V_191 [ 0 ] [ V_168 ] ,
V_16 -> V_191 [ 0 ] [ V_168 + 1 ] ,
V_16 -> V_191 [ 0 ] [ V_168 + 2 ] ,
V_16 -> V_191 [ 0 ] [ V_168 + 3 ] ) ;
V_167 += 16 ;
}
}
}
if ( error -> V_196 )
F_51 ( V_3 , error -> V_196 ) ;
if ( error -> V_197 )
F_52 ( V_3 , V_9 , error -> V_197 ) ;
return 0 ;
}
static T_6
F_53 ( struct V_198 * V_199 ,
const char T_7 * V_200 ,
T_4 V_201 ,
T_8 * V_202 )
{
struct V_2 * V_3 = V_199 -> V_203 ;
struct V_163 * V_164 = V_3 -> V_7 ;
struct V_8 * V_9 = V_164 -> V_9 ;
int V_58 ;
F_54 ( L_138 ) ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_55 ( V_9 ) ;
F_14 ( & V_9 -> V_59 ) ;
return V_201 ;
}
static int F_56 ( struct V_204 * V_204 , struct V_198 * V_198 )
{
struct V_8 * V_9 = V_204 -> V_205 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_163 * V_164 ;
unsigned long V_80 ;
V_164 = F_57 ( sizeof( * V_164 ) , V_206 ) ;
if ( ! V_164 )
return - V_207 ;
V_164 -> V_9 = V_9 ;
F_22 ( & V_53 -> V_208 . V_209 , V_80 ) ;
V_164 -> error = V_53 -> V_208 . V_210 ;
if ( V_164 -> error )
F_58 ( & V_164 -> error -> V_211 ) ;
F_24 ( & V_53 -> V_208 . V_209 , V_80 ) ;
return F_59 ( V_198 , F_49 , V_164 ) ;
}
static int F_60 ( struct V_204 * V_204 , struct V_198 * V_198 )
{
struct V_2 * V_3 = V_198 -> V_203 ;
struct V_163 * V_164 = V_3 -> V_7 ;
if ( V_164 -> error )
F_61 ( & V_164 -> error -> V_211 , V_212 ) ;
F_62 ( V_164 ) ;
return F_63 ( V_204 , V_198 ) ;
}
static int
F_64 ( void * V_4 , T_9 * V_213 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
* V_213 = V_53 -> V_214 ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int
F_65 ( void * V_4 , T_9 V_213 )
{
struct V_8 * V_9 = V_4 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_66 ( V_9 , V_213 ) ;
F_14 ( & V_9 -> V_59 ) ;
return V_58 ;
}
static int F_67 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_10 V_215 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_215 = F_68 ( V_216 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_139 , ( V_215 >> 8 ) & 0x3f , ( V_215 & 0x3f ) ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( F_70 ( V_9 ) ) {
T_10 V_217 = F_68 ( V_218 ) ;
T_10 V_219 = F_68 ( V_220 ) ;
F_4 ( V_3 , L_140 , ( V_217 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_141 , V_217 & 0x3f ) ;
F_4 ( V_3 , L_142 , ( V_219 & V_221 ) >>
V_222 ) ;
F_4 ( V_3 , L_143 ,
( V_219 & V_223 ) >> V_224 ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
T_5 V_225 = F_32 ( V_226 ) ;
T_5 V_227 = F_32 ( V_228 ) ;
T_5 V_229 = F_32 ( V_230 ) ;
T_5 V_231 , V_232 ;
T_5 V_233 , V_234 , V_235 ;
T_5 V_236 , V_237 , V_238 ;
int V_239 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_71 ( V_53 ) ;
V_231 = F_32 ( V_240 ) ;
V_233 = F_32 ( V_241 ) ;
V_234 = F_32 ( V_242 ) ;
V_235 = F_32 ( V_243 ) ;
V_236 = F_32 ( V_244 ) ;
V_237 = F_32 ( V_245 ) ;
V_238 = F_32 ( V_246 ) ;
if ( F_72 ( V_9 ) )
V_232 = ( V_231 & V_247 ) >> V_248 ;
else
V_232 = ( V_231 & V_249 ) >> V_250 ;
V_232 *= V_251 ;
F_73 ( V_53 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_144 , V_225 ) ;
F_4 ( V_3 , L_145 , V_231 ) ;
F_4 ( V_3 , L_146 ,
( V_225 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_147 ,
V_225 & 0xff ) ;
F_4 ( V_3 , L_148 ,
V_227 & 0xff ) ;
F_4 ( V_3 , L_149 , V_232 ) ;
F_4 ( V_3 , L_150 , V_233 &
V_252 ) ;
F_4 ( V_3 , L_151 , V_234 &
V_253 ) ;
F_4 ( V_3 , L_152 , V_235 &
V_253 ) ;
F_4 ( V_3 , L_153 , V_236 &
V_254 ) ;
F_4 ( V_3 , L_154 , V_237 &
V_253 ) ;
F_4 ( V_3 , L_155 , V_238 &
V_253 ) ;
V_239 = ( V_229 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_156 ,
V_239 * V_251 ) ;
V_239 = ( V_229 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_157 ,
V_239 * V_251 ) ;
V_239 = V_229 & 0xff ;
F_4 ( V_3 , L_158 ,
V_239 * V_251 ) ;
F_4 ( V_3 , L_159 ,
V_53 -> V_255 . V_256 * V_251 ) ;
} else {
F_4 ( V_3 , L_160 ) ;
}
return 0 ;
}
static int F_74 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_5 V_257 ;
int V_58 , V_97 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
for ( V_97 = 0 ; V_97 < 16 ; V_97 ++ ) {
V_257 = F_32 ( V_258 + V_97 * 4 ) ;
F_4 ( V_3 , L_161 , V_97 , V_257 ,
( V_257 & V_259 ) >> V_260 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static inline int F_75 ( int V_261 )
{
return 1250 - ( V_261 * 25 ) ;
}
static int F_76 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_5 V_262 ;
int V_58 , V_97 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
for ( V_97 = 1 ; V_97 <= 32 ; V_97 ++ ) {
V_262 = F_32 ( V_263 + V_97 * 4 ) ;
F_4 ( V_3 , L_162 , V_97 , V_262 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_5 V_264 , V_265 ;
T_10 V_266 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_264 = F_32 ( V_267 ) ;
V_265 = F_32 ( V_268 ) ;
V_266 = F_68 ( V_216 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_163 , ( V_264 & V_269 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_164 ,
( V_264 & V_270 ) >>
V_271 ) ;
F_4 ( V_3 , L_165 ,
V_264 & V_272 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_166 ,
V_264 & V_273 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_167 ,
V_264 & V_274 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_168 ,
( V_264 & V_275 ) >> V_276 ) ;
F_4 ( V_3 , L_169 ,
( V_264 & V_277 ) >> V_278 ) ;
F_4 ( V_3 , L_170 , ( V_264 & V_279 ) ) ;
F_4 ( V_3 , L_171 , ( V_266 & 0x3f ) ) ;
F_4 ( V_3 , L_172 , ( ( V_266 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_173 ,
( V_265 & V_280 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_174 ) ;
switch ( V_265 & V_281 ) {
case V_282 :
F_4 ( V_3 , L_175 ) ;
break;
case V_283 :
F_4 ( V_3 , L_176 ) ;
break;
case V_284 :
F_4 ( V_3 , L_177 ) ;
break;
case V_285 :
F_4 ( V_3 , L_178 ) ;
break;
case V_286 :
F_4 ( V_3 , L_179 ) ;
break;
case V_287 :
F_4 ( V_3 , L_180 ) ;
break;
default:
F_4 ( V_3 , L_181 ) ;
break;
}
return 0 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
T_5 V_288 , V_289 , V_290 , V_291 = 0 ;
unsigned V_292 ;
int V_57 = 0 , V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_79 ( & V_53 -> V_293 ) ;
V_292 = V_53 -> V_292 ;
F_80 ( & V_53 -> V_293 ) ;
if ( V_292 ) {
F_4 ( V_3 , L_182
L_183 ) ;
} else {
while ( V_57 ++ < 50 && ( F_81 ( V_294 ) & 1 ) )
F_82 ( 10 ) ;
F_4 ( V_3 , L_184 , F_1 ( V_57 < 51 ) ) ;
}
V_289 = F_83 ( V_53 -> V_295 + V_296 ) ;
F_84 ( false , V_296 , V_289 , 4 ) ;
V_288 = F_32 ( V_297 ) ;
V_290 = F_32 ( V_298 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_85 ( & V_53 -> V_255 . V_299 ) ;
F_86 ( V_53 , V_300 , & V_291 ) ;
F_14 ( & V_53 -> V_255 . V_299 ) ;
F_4 ( V_3 , L_185 ,
F_1 ( V_288 & V_301 ) ) ;
F_4 ( V_3 , L_165 ,
F_1 ( V_288 & V_302 ) ) ;
F_4 ( V_3 , L_166 ,
F_1 ( ( V_288 & V_303 ) ==
V_304 ) ) ;
F_4 ( V_3 , L_186 ,
F_1 ( V_290 & V_305 ) ) ;
F_4 ( V_3 , L_187 ,
F_1 ( V_290 & V_306 ) ) ;
F_4 ( V_3 , L_188 ,
F_1 ( V_290 & V_307 ) ) ;
F_4 ( V_3 , L_189 ,
F_1 ( V_290 & V_308 ) ) ;
F_4 ( V_3 , L_190 ) ;
switch ( V_289 & V_309 ) {
case V_310 :
if ( V_289 & V_311 )
F_4 ( V_3 , L_191 ) ;
else
F_4 ( V_3 , L_175 ) ;
break;
case V_312 :
F_4 ( V_3 , L_192 ) ;
break;
case V_313 :
F_4 ( V_3 , L_193 ) ;
break;
case V_314 :
F_4 ( V_3 , L_194 ) ;
break;
default:
F_4 ( V_3 , L_195 ) ;
break;
}
F_4 ( V_3 , L_196 ,
F_1 ( V_289 & V_311 ) ) ;
F_4 ( V_3 , L_197 ,
F_32 ( V_315 ) ) ;
F_4 ( V_3 , L_198 ,
F_32 ( V_316 ) ) ;
F_4 ( V_3 , L_199 ,
F_32 ( V_317 ) ) ;
F_4 ( V_3 , L_200 ,
F_32 ( V_318 ) ) ;
F_4 ( V_3 , L_201 ,
F_87 ( ( ( V_291 >> 0 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_202 ,
F_87 ( ( ( V_291 >> 8 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_203 ,
F_87 ( ( ( V_291 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_36 ( V_9 ) || F_37 ( V_9 ) )
return F_78 ( V_3 ) ;
else
return F_77 ( V_3 ) ;
}
static int F_89 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
if ( ! F_90 ( V_9 ) ) {
F_4 ( V_3 , L_204 ) ;
return 0 ;
}
if ( F_91 ( V_9 ) ) {
F_4 ( V_3 , L_205 ) ;
} else {
F_4 ( V_3 , L_206 ) ;
switch ( V_53 -> V_319 ) {
case V_320 :
F_4 ( V_3 , L_207 ) ;
break;
case V_321 :
F_4 ( V_3 , L_208 ) ;
break;
case V_322 :
F_4 ( V_3 , L_209 ) ;
break;
case V_323 :
F_4 ( V_3 , L_210 ) ;
break;
case V_324 :
F_4 ( V_3 , L_211 ) ;
break;
case V_325 :
F_4 ( V_3 , L_212 ) ;
break;
case V_326 :
F_4 ( V_3 , L_213 ) ;
break;
case V_327 :
F_4 ( V_3 , L_214 ) ;
break;
default:
F_4 ( V_3 , L_215 ) ;
}
F_4 ( V_3 , L_27 ) ;
}
return 0 ;
}
static int F_92 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
bool V_328 = false ;
if ( F_35 ( V_9 ) )
V_328 = F_32 ( V_329 ) & V_330 ;
else if ( F_93 ( V_9 ) || F_94 ( V_9 ) || F_95 ( V_9 ) )
V_328 = F_32 ( V_331 ) & V_332 ;
else if ( F_96 ( V_9 ) )
V_328 = F_32 ( V_333 ) & V_334 ;
else if ( F_97 ( V_9 ) )
V_328 = F_32 ( V_335 ) & V_336 ;
F_4 ( V_3 , L_216 ,
V_328 ? L_217 : L_218 ) ;
return 0 ;
}
static int F_98 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
unsigned long V_337 , V_338 , V_339 ;
int V_58 ;
if ( ! F_70 ( V_9 ) )
return - V_340 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_337 = F_99 ( V_53 ) ;
V_338 = F_100 ( V_53 ) ;
V_339 = F_101 ( V_53 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_219 , V_337 ) ;
F_4 ( V_3 , L_220 , V_338 ) ;
F_4 ( V_3 , L_221 , V_339 ) ;
F_4 ( V_3 , L_222 , V_338 + V_339 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
int V_341 , V_342 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) ) {
F_4 ( V_3 , L_223 ) ;
return 0 ;
}
V_58 = F_13 ( & V_53 -> V_255 . V_299 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_224 ) ;
for ( V_341 = V_53 -> V_255 . V_343 ;
V_341 <= V_53 -> V_255 . V_344 ;
V_341 ++ ) {
V_342 = V_341 ;
F_86 ( V_53 ,
V_345 ,
& V_342 ) ;
F_4 ( V_3 , L_225 ,
V_341 * V_251 ,
( ( V_342 >> 0 ) & 0xff ) * 100 ,
( ( V_342 >> 8 ) & 0xff ) * 100 ) ;
}
F_14 ( & V_53 -> V_255 . V_299 ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_226 , ( unsigned long ) F_32 ( 0x112f4 ) ) ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_346 * V_347 = & V_53 -> V_347 ;
void * V_4 = F_105 ( V_348 , V_206 ) ;
int V_58 ;
if ( V_4 == NULL )
return - V_207 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
goto V_349;
if ( V_347 -> V_350 ) {
F_106 ( V_4 , V_347 -> V_350 , V_348 ) ;
F_107 ( V_3 , V_4 , V_348 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
V_349:
F_62 ( V_4 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_351 * V_352 ;
struct V_353 * V_354 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_355 . V_356 ) ;
if ( V_58 )
return V_58 ;
V_352 = V_53 -> V_357 ;
V_354 = F_109 ( V_352 -> V_358 . V_354 ) ;
F_4 ( V_3 , L_227 ,
V_354 -> V_26 . V_359 ,
V_354 -> V_26 . V_360 ,
V_354 -> V_26 . V_361 ,
V_354 -> V_26 . V_362 ,
F_23 ( & V_354 -> V_26 . V_363 . V_363 ) ) ;
F_11 ( V_3 , V_354 -> V_16 ) ;
F_4 ( V_3 , L_27 ) ;
F_14 ( & V_9 -> V_355 . V_356 ) ;
F_85 ( & V_9 -> V_355 . V_364 ) ;
F_15 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_354 -> V_26 == V_352 -> V_358 . V_354 )
continue;
F_4 ( V_3 , L_228 ,
V_354 -> V_26 . V_359 ,
V_354 -> V_26 . V_360 ,
V_354 -> V_26 . V_361 ,
V_354 -> V_26 . V_362 ,
F_23 ( & V_354 -> V_26 . V_363 . V_363 ) ) ;
F_11 ( V_3 , V_354 -> V_16 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_14 ( & V_9 -> V_355 . V_364 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_94 * V_48 ;
int V_58 , V_97 ;
V_58 = F_13 ( & V_9 -> V_355 . V_356 ) ;
if ( V_58 )
return V_58 ;
if ( V_53 -> V_365 . V_366 ) {
F_4 ( V_3 , L_229 ) ;
F_11 ( V_3 , V_53 -> V_365 . V_366 ) ;
F_4 ( V_3 , L_27 ) ;
}
if ( V_53 -> V_365 . V_367 ) {
F_4 ( V_3 , L_230 ) ;
F_11 ( V_3 , V_53 -> V_365 . V_367 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_26 (ring, dev_priv, i) {
if ( V_48 -> V_368 ) {
F_4 ( V_3 , L_231 , V_48 -> V_37 ) ;
F_11 ( V_3 , V_48 -> V_368 -> V_16 ) ;
F_4 ( V_3 , L_27 ) ;
}
}
F_14 ( & V_9 -> V_355 . V_356 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
unsigned V_292 ;
F_79 ( & V_53 -> V_293 ) ;
V_292 = V_53 -> V_292 ;
F_80 ( & V_53 -> V_293 ) ;
F_4 ( V_3 , L_232 , V_292 ) ;
return 0 ;
}
static const char * F_112 ( unsigned V_369 )
{
switch( V_369 ) {
case V_370 :
return L_233 ;
case V_371 :
return L_234 ;
case V_372 :
return L_235 ;
case V_373 :
return L_236 ;
case V_374 :
return L_237 ;
case V_375 :
return L_238 ;
case V_376 :
return L_239 ;
case V_377 :
return L_240 ;
}
return L_241 ;
}
static int F_113 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_242 ,
F_112 ( V_53 -> V_61 . V_378 ) ) ;
F_4 ( V_3 , L_243 ,
F_112 ( V_53 -> V_61 . V_379 ) ) ;
if ( F_114 ( V_9 ) || F_115 ( V_9 ) ) {
F_4 ( V_3 , L_244 ,
F_32 ( V_380 ) ) ;
F_4 ( V_3 , L_245 ,
F_68 ( V_381 ) ) ;
F_4 ( V_3 , L_246 ,
F_68 ( V_382 ) ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
F_4 ( V_3 , L_247 ,
F_32 ( V_383 ) ) ;
F_4 ( V_3 , L_248 ,
F_32 ( V_384 ) ) ;
F_4 ( V_3 , L_249 ,
F_32 ( V_385 ) ) ;
F_4 ( V_3 , L_250 ,
F_32 ( V_386 ) ) ;
F_4 ( V_3 , L_251 ,
F_32 ( V_387 ) ) ;
F_4 ( V_3 , L_252 ,
F_32 ( V_388 ) ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_116 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
struct V_94 * V_48 ;
int V_97 , V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
if ( F_3 ( V_9 ) -> V_13 == 6 )
F_4 ( V_3 , L_253 , F_32 ( V_389 ) ) ;
F_26 (ring, dev_priv, i) {
F_4 ( V_3 , L_254 , V_48 -> V_37 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_253 , F_32 ( F_117 ( V_48 ) ) ) ;
F_4 ( V_3 , L_255 , F_32 ( F_118 ( V_48 ) ) ) ;
F_4 ( V_3 , L_256 , F_32 ( F_119 ( V_48 ) ) ) ;
F_4 ( V_3 , L_257 , F_32 ( F_120 ( V_48 ) ) ) ;
}
if ( V_53 -> V_61 . V_390 ) {
struct V_391 * V_392 = V_53 -> V_61 . V_390 ;
F_4 ( V_3 , L_258 ) ;
F_4 ( V_3 , L_259 , V_392 -> V_393 ) ;
}
F_4 ( V_3 , L_260 , F_32 ( V_394 ) ) ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_121 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( ! F_31 ( V_9 ) ) {
F_4 ( V_3 , L_261 ) ;
return 0 ;
}
V_58 = F_13 ( & V_53 -> V_395 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_262 , F_32 ( V_396 ) ) ;
F_4 ( V_3 , L_263 ,
F_122 ( V_53 , V_397 ) ) ;
F_4 ( V_3 , L_264 ,
F_122 ( V_53 , V_398 ) ) ;
F_4 ( V_3 , L_265 ,
F_122 ( V_53 , V_399 ) ) ;
F_4 ( V_3 , L_266 ,
F_122 ( V_53 , V_400 ) ) ;
F_4 ( V_3 , L_267 ,
F_122 ( V_53 , V_401 ) ) ;
F_4 ( V_3 , L_268 ,
F_122 ( V_53 , V_402 ) ) ;
F_4 ( V_3 , L_269 ,
F_122 ( V_53 , V_403 ) ) ;
F_4 ( V_3 , L_270 ,
F_122 ( V_53 , V_404 ) ) ;
F_4 ( V_3 , L_271 ,
F_122 ( V_53 , V_405 ) ) ;
F_14 ( & V_53 -> V_395 ) ;
return 0 ;
}
static int
F_123 ( void * V_4 , T_9 * V_213 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_53 = V_9 -> V_54 ;
* V_213 = F_23 ( & V_53 -> V_208 . V_406 ) ;
return 0 ;
}
static int
F_124 ( void * V_4 , T_9 V_213 )
{
struct V_8 * V_9 = V_4 ;
F_125 ( L_272 , V_213 ) ;
F_126 ( V_9 , V_213 ) ;
return 0 ;
}
static int
F_127 ( void * V_4 , T_9 * V_213 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_53 = V_9 -> V_54 ;
* V_213 = V_53 -> V_208 . V_407 ;
return 0 ;
}
static int
F_128 ( void * V_4 , T_9 V_213 )
{
struct V_8 * V_9 = V_4 ;
struct V_66 * V_53 = V_9 -> V_54 ;
int V_58 ;
F_54 ( L_273 , V_213 ) ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_53 -> V_208 . V_407 = V_213 ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int
F_129 ( void * V_4 , T_9 * V_213 )
{
* V_213 = V_408 ;
return 0 ;
}
static int
F_130 ( void * V_4 , T_9 V_213 )
{
struct V_8 * V_9 = V_4 ;
struct V_66 * V_53 = V_9 -> V_54 ;
struct V_15 * V_16 , * V_409 ;
int V_58 ;
F_54 ( L_274 , V_213 ) ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
if ( V_213 & V_410 ) {
V_58 = F_131 ( V_9 ) ;
if ( V_58 )
goto V_411;
}
if ( V_213 & ( V_412 | V_410 ) )
F_132 ( V_9 ) ;
if ( V_213 & V_413 ) {
F_133 (obj, next, &dev_priv->mm.inactive_list, mm_list)
if ( V_16 -> V_18 == 0 ) {
V_58 = F_134 ( V_16 ) ;
if ( V_58 )
goto V_411;
}
}
if ( V_213 & V_414 ) {
F_133 (obj, next, &dev_priv->mm.unbound_list, gtt_list)
if ( V_16 -> V_415 == 0 ) {
V_58 = F_135 ( V_16 ) ;
if ( V_58 )
goto V_411;
}
}
V_411:
F_14 ( & V_9 -> V_59 ) ;
return V_58 ;
}
static int
F_136 ( void * V_4 , T_9 * V_213 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_340 ;
V_58 = F_13 ( & V_53 -> V_255 . V_299 ) ;
if ( V_58 )
return V_58 ;
* V_213 = V_53 -> V_255 . V_344 * V_251 ;
F_14 ( & V_53 -> V_255 . V_299 ) ;
return 0 ;
}
static int
F_137 ( void * V_4 , T_9 V_213 )
{
struct V_8 * V_9 = V_4 ;
struct V_66 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_340 ;
F_54 ( L_275 , V_213 ) ;
V_58 = F_13 ( & V_53 -> V_255 . V_299 ) ;
if ( V_58 )
return V_58 ;
F_138 ( V_213 , V_251 ) ;
V_53 -> V_255 . V_344 = V_213 ;
F_139 ( V_9 , V_213 ) ;
F_14 ( & V_53 -> V_255 . V_299 ) ;
return 0 ;
}
static int
F_140 ( void * V_4 , T_9 * V_213 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_340 ;
V_58 = F_13 ( & V_53 -> V_255 . V_299 ) ;
if ( V_58 )
return V_58 ;
* V_213 = V_53 -> V_255 . V_343 * V_251 ;
F_14 ( & V_53 -> V_255 . V_299 ) ;
return 0 ;
}
static int
F_141 ( void * V_4 , T_9 V_213 )
{
struct V_8 * V_9 = V_4 ;
struct V_66 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_340 ;
F_54 ( L_276 , V_213 ) ;
V_58 = F_13 ( & V_53 -> V_255 . V_299 ) ;
if ( V_58 )
return V_58 ;
F_138 ( V_213 , V_251 ) ;
V_53 -> V_255 . V_343 = V_213 ;
F_139 ( V_9 , V_213 ) ;
F_14 ( & V_53 -> V_255 . V_299 ) ;
return 0 ;
}
static int
F_142 ( void * V_4 , T_9 * V_213 )
{
struct V_8 * V_9 = V_4 ;
T_3 * V_53 = V_9 -> V_54 ;
T_5 V_416 ;
int V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_340 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_416 = F_32 ( V_417 ) ;
F_14 ( & V_53 -> V_9 -> V_59 ) ;
* V_213 = ( V_416 & V_418 ) >> V_419 ;
return 0 ;
}
static int
F_143 ( void * V_4 , T_9 V_213 )
{
struct V_8 * V_9 = V_4 ;
struct V_66 * V_53 = V_9 -> V_54 ;
T_5 V_416 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_340 ;
if ( V_213 > 3 )
return - V_65 ;
F_54 ( L_277 , V_213 ) ;
V_416 = F_32 ( V_417 ) ;
V_416 &= ~ V_418 ;
V_416 |= ( V_213 << V_419 ) ;
F_144 ( V_417 , V_416 ) ;
return 0 ;
}
static int
F_145 ( struct V_420 * V_10 ,
struct V_421 * V_422 ,
const void * V_423 )
{
struct V_5 * V_6 ;
V_6 = F_105 ( sizeof( struct V_5 ) , V_206 ) ;
if ( V_6 == NULL ) {
F_146 ( V_422 ) ;
return - V_207 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_424 = V_422 ;
V_6 -> V_50 = ( void * ) V_423 ;
F_85 ( & V_10 -> V_425 ) ;
F_147 ( & V_6 -> V_49 , & V_10 -> V_426 ) ;
F_14 ( & V_10 -> V_425 ) ;
return 0 ;
}
static int F_148 ( struct V_204 * V_204 , struct V_198 * V_198 )
{
struct V_8 * V_9 = V_204 -> V_205 ;
struct V_66 * V_53 = V_9 -> V_54 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_71 ( V_53 ) ;
return 0 ;
}
static int F_149 ( struct V_204 * V_204 , struct V_198 * V_198 )
{
struct V_8 * V_9 = V_204 -> V_205 ;
struct V_66 * V_53 = V_9 -> V_54 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_73 ( V_53 ) ;
return 0 ;
}
static int F_150 ( struct V_421 * V_427 , struct V_420 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_421 * V_422 ;
V_422 = F_151 ( L_278 ,
V_428 ,
V_427 , V_9 ,
& V_429 ) ;
if ( F_152 ( V_422 ) )
return F_153 ( V_422 ) ;
return F_145 ( V_10 , V_422 , & V_429 ) ;
}
static int F_154 ( struct V_421 * V_427 ,
struct V_420 * V_10 ,
const char * V_37 ,
const struct V_430 * V_431 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_421 * V_422 ;
V_422 = F_151 ( V_37 ,
V_432 | V_433 ,
V_427 , V_9 ,
V_431 ) ;
if ( F_152 ( V_422 ) )
return F_153 ( V_422 ) ;
return F_145 ( V_10 , V_422 , V_431 ) ;
}
int F_155 ( struct V_420 * V_10 )
{
int V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_279 ,
& V_435 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_150 ( V_10 -> V_434 , V_10 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_280 ,
& V_436 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_281 ,
& V_437 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_282 ,
& V_438 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_283 ,
& V_439 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_284 ,
& V_440 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_285 ,
& V_441 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_154 ( V_10 -> V_434 , V_10 ,
L_286 ,
& V_442 ) ;
if ( V_58 )
return V_58 ;
return F_156 ( V_443 ,
V_444 ,
V_10 -> V_434 , V_10 ) ;
}
void F_157 ( struct V_420 * V_10 )
{
F_158 ( V_443 ,
V_444 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_429 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_435 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_436 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_437 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_438 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_440 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_439 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_441 ,
1 , V_10 ) ;
F_158 ( (struct V_445 * ) & V_442 ,
1 , V_10 ) ;
}
