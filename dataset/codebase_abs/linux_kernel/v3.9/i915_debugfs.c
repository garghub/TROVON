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
}
if ( error -> V_195 )
F_51 ( V_3 , error -> V_195 ) ;
if ( error -> V_196 )
F_52 ( V_3 , V_9 , error -> V_196 ) ;
return 0 ;
}
static T_6
F_53 ( struct V_197 * V_198 ,
const char T_7 * V_199 ,
T_4 V_200 ,
T_8 * V_201 )
{
struct V_2 * V_3 = V_198 -> V_202 ;
struct V_163 * V_164 = V_3 -> V_7 ;
struct V_8 * V_9 = V_164 -> V_9 ;
int V_58 ;
F_54 ( L_136 ) ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_55 ( V_9 ) ;
F_14 ( & V_9 -> V_59 ) ;
return V_200 ;
}
static int F_56 ( struct V_203 * V_203 , struct V_197 * V_197 )
{
struct V_8 * V_9 = V_203 -> V_204 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_163 * V_164 ;
unsigned long V_80 ;
V_164 = F_57 ( sizeof( * V_164 ) , V_205 ) ;
if ( ! V_164 )
return - V_206 ;
V_164 -> V_9 = V_9 ;
F_22 ( & V_53 -> V_207 . V_208 , V_80 ) ;
V_164 -> error = V_53 -> V_207 . V_209 ;
if ( V_164 -> error )
F_58 ( & V_164 -> error -> V_210 ) ;
F_24 ( & V_53 -> V_207 . V_208 , V_80 ) ;
return F_59 ( V_197 , F_49 , V_164 ) ;
}
static int F_60 ( struct V_203 * V_203 , struct V_197 * V_197 )
{
struct V_2 * V_3 = V_197 -> V_202 ;
struct V_163 * V_164 = V_3 -> V_7 ;
if ( V_164 -> error )
F_61 ( & V_164 -> error -> V_210 , V_211 ) ;
F_62 ( V_164 ) ;
return F_63 ( V_203 , V_197 ) ;
}
static T_6
F_64 ( struct V_197 * V_198 ,
char T_7 * V_199 ,
T_4 V_212 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
T_3 * V_53 = V_9 -> V_54 ;
char V_213 [ 80 ] ;
int V_214 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_214 = snprintf ( V_213 , sizeof( V_213 ) ,
L_137 ,
V_53 -> V_215 ) ;
F_14 ( & V_9 -> V_59 ) ;
if ( V_214 > sizeof( V_213 ) )
V_214 = sizeof( V_213 ) ;
return F_65 ( V_199 , V_212 , V_201 , V_213 , V_214 ) ;
}
static T_6
F_66 ( struct V_197 * V_198 ,
const char T_7 * V_199 ,
T_4 V_200 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
char V_213 [ 20 ] ;
T_5 V_216 = 1 ;
int V_58 ;
if ( V_200 > 0 ) {
if ( V_200 > sizeof( V_213 ) - 1 )
return - V_65 ;
if ( F_67 ( V_213 , V_199 , V_200 ) )
return - V_217 ;
V_213 [ V_200 ] = 0 ;
V_58 = F_68 ( V_213 , 0 , & V_216 ) ;
if ( V_58 < 0 )
return V_58 ;
}
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_69 ( V_9 , V_216 ) ;
F_14 ( & V_9 -> V_59 ) ;
return V_58 ? : V_200 ;
}
static int F_70 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_9 V_218 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_218 = F_71 ( V_219 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_138 , ( V_218 >> 8 ) & 0x3f , ( V_218 & 0x3f ) ) ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( F_73 ( V_9 ) ) {
T_9 V_220 = F_71 ( V_221 ) ;
T_9 V_222 = F_71 ( V_223 ) ;
F_4 ( V_3 , L_139 , ( V_220 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_140 , V_220 & 0x3f ) ;
F_4 ( V_3 , L_141 , ( V_222 & V_224 ) >>
V_225 ) ;
F_4 ( V_3 , L_142 ,
( V_222 & V_226 ) >> V_227 ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
T_5 V_228 = F_32 ( V_229 ) ;
T_5 V_230 = F_32 ( V_231 ) ;
T_5 V_232 = F_32 ( V_233 ) ;
T_5 V_234 , V_235 ;
T_5 V_236 , V_237 , V_238 ;
T_5 V_239 , V_240 , V_241 ;
int V_242 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_74 ( V_53 ) ;
V_234 = F_32 ( V_243 ) ;
V_236 = F_32 ( V_244 ) ;
V_237 = F_32 ( V_245 ) ;
V_238 = F_32 ( V_246 ) ;
V_239 = F_32 ( V_247 ) ;
V_240 = F_32 ( V_248 ) ;
V_241 = F_32 ( V_249 ) ;
if ( F_75 ( V_9 ) )
V_235 = ( V_234 & V_250 ) >> V_251 ;
else
V_235 = ( V_234 & V_252 ) >> V_253 ;
V_235 *= V_254 ;
F_76 ( V_53 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_143 , V_228 ) ;
F_4 ( V_3 , L_144 , V_234 ) ;
F_4 ( V_3 , L_145 ,
( V_228 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_146 ,
V_228 & 0xff ) ;
F_4 ( V_3 , L_147 ,
V_230 & 0xff ) ;
F_4 ( V_3 , L_148 , V_235 ) ;
F_4 ( V_3 , L_149 , V_236 &
V_255 ) ;
F_4 ( V_3 , L_150 , V_237 &
V_256 ) ;
F_4 ( V_3 , L_151 , V_238 &
V_256 ) ;
F_4 ( V_3 , L_152 , V_239 &
V_257 ) ;
F_4 ( V_3 , L_153 , V_240 &
V_256 ) ;
F_4 ( V_3 , L_154 , V_241 &
V_256 ) ;
V_242 = ( V_232 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_155 ,
V_242 * V_254 ) ;
V_242 = ( V_232 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_156 ,
V_242 * V_254 ) ;
V_242 = V_232 & 0xff ;
F_4 ( V_3 , L_157 ,
V_242 * V_254 ) ;
} else {
F_4 ( V_3 , L_158 ) ;
}
return 0 ;
}
static int F_77 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_5 V_258 ;
int V_58 , V_97 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
for ( V_97 = 0 ; V_97 < 16 ; V_97 ++ ) {
V_258 = F_32 ( V_259 + V_97 * 4 ) ;
F_4 ( V_3 , L_159 , V_97 , V_258 ,
( V_258 & V_260 ) >> V_261 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static inline int F_78 ( int V_262 )
{
return 1250 - ( V_262 * 25 ) ;
}
static int F_79 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_5 V_263 ;
int V_58 , V_97 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
for ( V_97 = 1 ; V_97 <= 32 ; V_97 ++ ) {
V_263 = F_32 ( V_264 + V_97 * 4 ) ;
F_4 ( V_3 , L_160 , V_97 , V_263 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
T_5 V_265 , V_266 ;
T_9 V_267 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_265 = F_32 ( V_268 ) ;
V_266 = F_32 ( V_269 ) ;
V_267 = F_71 ( V_219 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_161 , ( V_265 & V_270 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_162 ,
( V_265 & V_271 ) >>
V_272 ) ;
F_4 ( V_3 , L_163 ,
V_265 & V_273 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_164 ,
V_265 & V_274 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_165 ,
V_265 & V_275 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_166 ,
( V_265 & V_276 ) >> V_277 ) ;
F_4 ( V_3 , L_167 ,
( V_265 & V_278 ) >> V_279 ) ;
F_4 ( V_3 , L_168 , ( V_265 & V_280 ) ) ;
F_4 ( V_3 , L_169 , ( V_267 & 0x3f ) ) ;
F_4 ( V_3 , L_170 , ( ( V_267 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_171 ,
( V_266 & V_281 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_172 ) ;
switch ( V_266 & V_282 ) {
case V_283 :
F_4 ( V_3 , L_173 ) ;
break;
case V_284 :
F_4 ( V_3 , L_174 ) ;
break;
case V_285 :
F_4 ( V_3 , L_175 ) ;
break;
case V_286 :
F_4 ( V_3 , L_176 ) ;
break;
case V_287 :
F_4 ( V_3 , L_177 ) ;
break;
case V_288 :
F_4 ( V_3 , L_178 ) ;
break;
default:
F_4 ( V_3 , L_179 ) ;
break;
}
return 0 ;
}
static int F_81 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
T_5 V_289 , V_290 , V_291 , V_292 = 0 ;
unsigned V_293 ;
int V_57 = 0 , V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_82 ( & V_53 -> V_294 ) ;
V_293 = V_53 -> V_293 ;
F_83 ( & V_53 -> V_294 ) ;
if ( V_293 ) {
F_4 ( V_3 , L_180
L_181 ) ;
} else {
while ( V_57 ++ < 50 && ( F_84 ( V_295 ) & 1 ) )
F_85 ( 10 ) ;
F_4 ( V_3 , L_182 , F_1 ( V_57 < 51 ) ) ;
}
V_290 = F_86 ( V_53 -> V_296 + V_297 ) ;
F_87 ( false , V_297 , V_290 , 4 ) ;
V_289 = F_32 ( V_298 ) ;
V_291 = F_32 ( V_299 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_88 ( & V_53 -> V_300 . V_301 ) ;
F_89 ( V_53 , V_302 , & V_292 ) ;
F_14 ( & V_53 -> V_300 . V_301 ) ;
F_4 ( V_3 , L_183 ,
F_1 ( V_289 & V_303 ) ) ;
F_4 ( V_3 , L_163 ,
F_1 ( V_289 & V_304 ) ) ;
F_4 ( V_3 , L_164 ,
F_1 ( ( V_289 & V_305 ) ==
V_306 ) ) ;
F_4 ( V_3 , L_184 ,
F_1 ( V_291 & V_307 ) ) ;
F_4 ( V_3 , L_185 ,
F_1 ( V_291 & V_308 ) ) ;
F_4 ( V_3 , L_186 ,
F_1 ( V_291 & V_309 ) ) ;
F_4 ( V_3 , L_187 ,
F_1 ( V_291 & V_310 ) ) ;
F_4 ( V_3 , L_188 ) ;
switch ( V_290 & V_311 ) {
case V_312 :
if ( V_290 & V_313 )
F_4 ( V_3 , L_189 ) ;
else
F_4 ( V_3 , L_173 ) ;
break;
case V_314 :
F_4 ( V_3 , L_190 ) ;
break;
case V_315 :
F_4 ( V_3 , L_191 ) ;
break;
case V_316 :
F_4 ( V_3 , L_192 ) ;
break;
default:
F_4 ( V_3 , L_193 ) ;
break;
}
F_4 ( V_3 , L_194 ,
F_1 ( V_290 & V_313 ) ) ;
F_4 ( V_3 , L_195 ,
F_32 ( V_317 ) ) ;
F_4 ( V_3 , L_196 ,
F_32 ( V_318 ) ) ;
F_4 ( V_3 , L_197 ,
F_32 ( V_319 ) ) ;
F_4 ( V_3 , L_198 ,
F_32 ( V_320 ) ) ;
F_4 ( V_3 , L_199 ,
F_90 ( ( ( V_292 >> 0 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_200 ,
F_90 ( ( ( V_292 >> 8 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_201 ,
F_90 ( ( ( V_292 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_36 ( V_9 ) || F_37 ( V_9 ) )
return F_81 ( V_3 ) ;
else
return F_80 ( V_3 ) ;
}
static int F_92 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
if ( ! F_93 ( V_9 ) ) {
F_4 ( V_3 , L_202 ) ;
return 0 ;
}
if ( F_94 ( V_9 ) ) {
F_4 ( V_3 , L_203 ) ;
} else {
F_4 ( V_3 , L_204 ) ;
switch ( V_53 -> V_321 ) {
case V_322 :
F_4 ( V_3 , L_205 ) ;
break;
case V_323 :
F_4 ( V_3 , L_206 ) ;
break;
case V_324 :
F_4 ( V_3 , L_207 ) ;
break;
case V_325 :
F_4 ( V_3 , L_208 ) ;
break;
case V_326 :
F_4 ( V_3 , L_209 ) ;
break;
case V_327 :
F_4 ( V_3 , L_210 ) ;
break;
case V_328 :
F_4 ( V_3 , L_211 ) ;
break;
case V_329 :
F_4 ( V_3 , L_212 ) ;
break;
default:
F_4 ( V_3 , L_213 ) ;
}
F_4 ( V_3 , L_27 ) ;
}
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
bool V_330 = false ;
if ( F_35 ( V_9 ) )
V_330 = F_32 ( V_331 ) & V_332 ;
else if ( F_96 ( V_9 ) || F_97 ( V_9 ) || F_98 ( V_9 ) )
V_330 = F_32 ( V_333 ) & V_334 ;
else if ( F_99 ( V_9 ) )
V_330 = F_32 ( V_335 ) & V_336 ;
else if ( F_100 ( V_9 ) )
V_330 = F_32 ( V_337 ) & V_338 ;
F_4 ( V_3 , L_214 ,
V_330 ? L_215 : L_216 ) ;
return 0 ;
}
static int F_101 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
unsigned long V_339 , V_340 , V_341 ;
int V_58 ;
if ( ! F_73 ( V_9 ) )
return - V_342 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_339 = F_102 ( V_53 ) ;
V_340 = F_103 ( V_53 ) ;
V_341 = F_104 ( V_53 ) ;
F_14 ( & V_9 -> V_59 ) ;
F_4 ( V_3 , L_217 , V_339 ) ;
F_4 ( V_3 , L_218 , V_340 ) ;
F_4 ( V_3 , L_219 , V_341 ) ;
F_4 ( V_3 , L_220 , V_340 + V_341 ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
int V_343 , V_344 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) ) {
F_4 ( V_3 , L_221 ) ;
return 0 ;
}
V_58 = F_13 ( & V_53 -> V_300 . V_301 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_222 ) ;
for ( V_343 = V_53 -> V_300 . V_345 ;
V_343 <= V_53 -> V_300 . V_346 ;
V_343 ++ ) {
V_344 = V_343 ;
F_89 ( V_53 ,
V_347 ,
& V_344 ) ;
F_4 ( V_3 , L_223 , V_343 * V_254 , V_344 * 100 ) ;
}
F_14 ( & V_53 -> V_300 . V_301 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_224 , ( unsigned long ) F_32 ( 0x112f4 ) ) ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_348 * V_349 = & V_53 -> V_349 ;
void * V_4 = F_108 ( V_350 , V_205 ) ;
int V_58 ;
if ( V_4 == NULL )
return - V_206 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
goto V_351;
if ( V_349 -> V_352 ) {
F_109 ( V_4 , V_349 -> V_352 , V_350 ) ;
F_110 ( V_3 , V_4 , V_350 ) ;
}
F_14 ( & V_9 -> V_59 ) ;
V_351:
F_62 ( V_4 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_353 * V_354 ;
struct V_355 * V_356 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_357 . V_358 ) ;
if ( V_58 )
return V_58 ;
V_354 = V_53 -> V_359 ;
V_356 = F_112 ( V_354 -> V_360 . V_356 ) ;
F_4 ( V_3 , L_225 ,
V_356 -> V_26 . V_361 ,
V_356 -> V_26 . V_362 ,
V_356 -> V_26 . V_363 ,
V_356 -> V_26 . V_364 ,
F_23 ( & V_356 -> V_26 . V_365 . V_365 ) ) ;
F_11 ( V_3 , V_356 -> V_16 ) ;
F_4 ( V_3 , L_27 ) ;
F_14 ( & V_9 -> V_357 . V_358 ) ;
F_88 ( & V_9 -> V_357 . V_366 ) ;
F_15 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_356 -> V_26 == V_354 -> V_360 . V_356 )
continue;
F_4 ( V_3 , L_226 ,
V_356 -> V_26 . V_361 ,
V_356 -> V_26 . V_362 ,
V_356 -> V_26 . V_363 ,
V_356 -> V_26 . V_364 ,
F_23 ( & V_356 -> V_26 . V_365 . V_365 ) ) ;
F_11 ( V_3 , V_356 -> V_16 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_14 ( & V_9 -> V_357 . V_366 ) ;
return 0 ;
}
static int F_113 ( struct V_2 * V_3 , void * V_162 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_53 = V_9 -> V_54 ;
struct V_94 * V_48 ;
int V_58 , V_97 ;
V_58 = F_13 ( & V_9 -> V_357 . V_358 ) ;
if ( V_58 )
return V_58 ;
if ( V_53 -> V_367 . V_368 ) {
F_4 ( V_3 , L_227 ) ;
F_11 ( V_3 , V_53 -> V_367 . V_368 ) ;
F_4 ( V_3 , L_27 ) ;
}
if ( V_53 -> V_367 . V_369 ) {
F_4 ( V_3 , L_228 ) ;
F_11 ( V_3 , V_53 -> V_367 . V_369 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_26 (ring, dev_priv, i) {
if ( V_48 -> V_370 ) {
F_4 ( V_3 , L_229 , V_48 -> V_37 ) ;
F_11 ( V_3 , V_48 -> V_370 -> V_16 ) ;
F_4 ( V_3 , L_27 ) ;
}
}
F_14 ( & V_9 -> V_357 . V_358 ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
unsigned V_293 ;
F_82 ( & V_53 -> V_294 ) ;
V_293 = V_53 -> V_293 ;
F_83 ( & V_53 -> V_294 ) ;
F_4 ( V_3 , L_230 , V_293 ) ;
return 0 ;
}
static const char * F_115 ( unsigned V_371 )
{
switch( V_371 ) {
case V_372 :
return L_231 ;
case V_373 :
return L_232 ;
case V_374 :
return L_233 ;
case V_375 :
return L_234 ;
case V_376 :
return L_235 ;
case V_377 :
return L_236 ;
case V_378 :
return L_237 ;
case V_379 :
return L_238 ;
}
return L_239 ;
}
static int F_116 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
int V_58 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_240 ,
F_115 ( V_53 -> V_61 . V_380 ) ) ;
F_4 ( V_3 , L_241 ,
F_115 ( V_53 -> V_61 . V_381 ) ) ;
if ( F_117 ( V_9 ) || F_118 ( V_9 ) ) {
F_4 ( V_3 , L_242 ,
F_32 ( V_382 ) ) ;
F_4 ( V_3 , L_243 ,
F_71 ( V_383 ) ) ;
F_4 ( V_3 , L_244 ,
F_71 ( V_384 ) ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
F_4 ( V_3 , L_245 ,
F_32 ( V_385 ) ) ;
F_4 ( V_3 , L_246 ,
F_32 ( V_386 ) ) ;
F_4 ( V_3 , L_247 ,
F_32 ( V_387 ) ) ;
F_4 ( V_3 , L_248 ,
F_32 ( V_388 ) ) ;
F_4 ( V_3 , L_249 ,
F_32 ( V_389 ) ) ;
F_4 ( V_3 , L_250 ,
F_32 ( V_390 ) ) ;
}
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_119 ( struct V_2 * V_3 , void * V_4 )
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
F_4 ( V_3 , L_251 , F_32 ( V_391 ) ) ;
F_26 (ring, dev_priv, i) {
F_4 ( V_3 , L_252 , V_48 -> V_37 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_251 , F_32 ( F_120 ( V_48 ) ) ) ;
F_4 ( V_3 , L_253 , F_32 ( F_121 ( V_48 ) ) ) ;
F_4 ( V_3 , L_254 , F_32 ( F_122 ( V_48 ) ) ) ;
F_4 ( V_3 , L_255 , F_32 ( F_123 ( V_48 ) ) ) ;
}
if ( V_53 -> V_61 . V_392 ) {
struct V_393 * V_394 = V_53 -> V_61 . V_392 ;
F_4 ( V_3 , L_256 ) ;
F_4 ( V_3 , L_257 , V_394 -> V_395 ) ;
}
F_4 ( V_3 , L_258 , F_32 ( V_396 ) ) ;
F_14 ( & V_9 -> V_59 ) ;
return 0 ;
}
static int F_124 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_66 * V_53 = V_9 -> V_54 ;
int V_58 ;
if ( ! F_31 ( V_9 ) ) {
F_4 ( V_3 , L_259 ) ;
return 0 ;
}
V_58 = F_13 ( & V_53 -> V_397 ) ;
if ( V_58 )
return V_58 ;
F_4 ( V_3 , L_260 , F_32 ( V_398 ) ) ;
F_4 ( V_3 , L_261 ,
F_125 ( V_53 , V_399 ) ) ;
F_4 ( V_3 , L_262 ,
F_125 ( V_53 , V_400 ) ) ;
F_4 ( V_3 , L_263 ,
F_125 ( V_53 , V_401 ) ) ;
F_4 ( V_3 , L_264 ,
F_125 ( V_53 , V_402 ) ) ;
F_4 ( V_3 , L_265 ,
F_125 ( V_53 , V_403 ) ) ;
F_4 ( V_3 , L_266 ,
F_125 ( V_53 , V_404 ) ) ;
F_4 ( V_3 , L_267 ,
F_125 ( V_53 , V_405 ) ) ;
F_4 ( V_3 , L_268 ,
F_125 ( V_53 , V_406 ) ) ;
F_4 ( V_3 , L_269 ,
F_125 ( V_53 , V_407 ) ) ;
F_14 ( & V_53 -> V_397 ) ;
return 0 ;
}
static T_6
F_126 ( struct V_197 * V_198 ,
char T_7 * V_199 ,
T_4 V_212 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
T_3 * V_53 = V_9 -> V_54 ;
char V_213 [ 80 ] ;
int V_214 ;
V_214 = snprintf ( V_213 , sizeof( V_213 ) ,
L_270 ,
F_23 ( & V_53 -> V_207 . V_408 ) ) ;
if ( V_214 > sizeof( V_213 ) )
V_214 = sizeof( V_213 ) ;
return F_65 ( V_199 , V_212 , V_201 , V_213 , V_214 ) ;
}
static T_6
F_127 ( struct V_197 * V_198 ,
const char T_7 * V_199 ,
T_4 V_200 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
char V_213 [ 20 ] ;
int V_216 = 1 ;
if ( V_200 > 0 ) {
if ( V_200 > sizeof( V_213 ) - 1 )
return - V_65 ;
if ( F_67 ( V_213 , V_199 , V_200 ) )
return - V_217 ;
V_213 [ V_200 ] = 0 ;
V_216 = F_128 ( V_213 , NULL , 0 ) ;
}
F_129 ( L_271 , V_216 ) ;
F_130 ( V_9 , V_216 ) ;
return V_200 ;
}
static T_6
F_131 ( struct V_197 * V_198 ,
char T_7 * V_199 ,
T_4 V_212 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
T_3 * V_53 = V_9 -> V_54 ;
char V_213 [ 20 ] ;
int V_214 ;
V_214 = snprintf ( V_213 , sizeof( V_213 ) ,
L_272 , V_53 -> V_207 . V_409 ) ;
if ( V_214 > sizeof( V_213 ) )
V_214 = sizeof( V_213 ) ;
return F_65 ( V_199 , V_212 , V_201 , V_213 , V_214 ) ;
}
static T_6
F_132 ( struct V_197 * V_198 ,
const char T_7 * V_199 ,
T_4 V_200 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
struct V_66 * V_53 = V_9 -> V_54 ;
char V_213 [ 20 ] ;
int V_216 = 0 , V_58 ;
if ( V_200 > 0 ) {
if ( V_200 > sizeof( V_213 ) - 1 )
return - V_65 ;
if ( F_67 ( V_213 , V_199 , V_200 ) )
return - V_217 ;
V_213 [ V_200 ] = 0 ;
V_216 = F_128 ( V_213 , NULL , 0 ) ;
}
F_54 ( L_273 , V_216 ) ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_53 -> V_207 . V_409 = V_216 ;
F_14 ( & V_9 -> V_59 ) ;
return V_200 ;
}
static T_6
F_133 ( struct V_197 * V_198 ,
char T_7 * V_199 ,
T_4 V_212 ,
T_8 * V_201 )
{
char V_213 [ 20 ] ;
int V_214 ;
V_214 = snprintf ( V_213 , sizeof( V_213 ) , L_272 , V_410 ) ;
if ( V_214 > sizeof( V_213 ) )
V_214 = sizeof( V_213 ) ;
return F_65 ( V_199 , V_212 , V_201 , V_213 , V_214 ) ;
}
static T_6
F_134 ( struct V_197 * V_198 ,
const char T_7 * V_199 ,
T_4 V_200 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
struct V_66 * V_53 = V_9 -> V_54 ;
struct V_15 * V_16 , * V_411 ;
char V_213 [ 20 ] ;
int V_216 = 0 , V_58 ;
if ( V_200 > 0 ) {
if ( V_200 > sizeof( V_213 ) - 1 )
return - V_65 ;
if ( F_67 ( V_213 , V_199 , V_200 ) )
return - V_217 ;
V_213 [ V_200 ] = 0 ;
V_216 = F_128 ( V_213 , NULL , 0 ) ;
}
F_54 ( L_274 , V_216 ) ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
if ( V_216 & V_412 ) {
V_58 = F_135 ( V_9 ) ;
if ( V_58 )
goto V_413;
}
if ( V_216 & ( V_414 | V_412 ) )
F_136 ( V_9 ) ;
if ( V_216 & V_415 ) {
F_137 (obj, next, &dev_priv->mm.inactive_list, mm_list)
if ( V_16 -> V_18 == 0 ) {
V_58 = F_138 ( V_16 ) ;
if ( V_58 )
goto V_413;
}
}
if ( V_216 & V_416 ) {
F_137 (obj, next, &dev_priv->mm.unbound_list, gtt_list)
if ( V_16 -> V_417 == 0 ) {
V_58 = F_139 ( V_16 ) ;
if ( V_58 )
goto V_413;
}
}
V_413:
F_14 ( & V_9 -> V_59 ) ;
return V_58 ? : V_200 ;
}
static T_6
F_140 ( struct V_197 * V_198 ,
char T_7 * V_199 ,
T_4 V_212 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
T_3 * V_53 = V_9 -> V_54 ;
char V_213 [ 80 ] ;
int V_214 , V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_342 ;
V_58 = F_13 ( & V_53 -> V_300 . V_301 ) ;
if ( V_58 )
return V_58 ;
V_214 = snprintf ( V_213 , sizeof( V_213 ) ,
L_275 , V_53 -> V_300 . V_346 * V_254 ) ;
F_14 ( & V_53 -> V_300 . V_301 ) ;
if ( V_214 > sizeof( V_213 ) )
V_214 = sizeof( V_213 ) ;
return F_65 ( V_199 , V_212 , V_201 , V_213 , V_214 ) ;
}
static T_6
F_141 ( struct V_197 * V_198 ,
const char T_7 * V_199 ,
T_4 V_200 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
struct V_66 * V_53 = V_9 -> V_54 ;
char V_213 [ 20 ] ;
int V_216 = 1 , V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_342 ;
if ( V_200 > 0 ) {
if ( V_200 > sizeof( V_213 ) - 1 )
return - V_65 ;
if ( F_67 ( V_213 , V_199 , V_200 ) )
return - V_217 ;
V_213 [ V_200 ] = 0 ;
V_216 = F_128 ( V_213 , NULL , 0 ) ;
}
F_54 ( L_276 , V_216 ) ;
V_58 = F_13 ( & V_53 -> V_300 . V_301 ) ;
if ( V_58 )
return V_58 ;
V_53 -> V_300 . V_346 = V_216 / V_254 ;
F_142 ( V_9 , V_216 / V_254 ) ;
F_14 ( & V_53 -> V_300 . V_301 ) ;
return V_200 ;
}
static T_6
F_143 ( struct V_197 * V_198 , char T_7 * V_199 , T_4 V_212 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
T_3 * V_53 = V_9 -> V_54 ;
char V_213 [ 80 ] ;
int V_214 , V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_342 ;
V_58 = F_13 ( & V_53 -> V_300 . V_301 ) ;
if ( V_58 )
return V_58 ;
V_214 = snprintf ( V_213 , sizeof( V_213 ) ,
L_277 , V_53 -> V_300 . V_345 * V_254 ) ;
F_14 ( & V_53 -> V_300 . V_301 ) ;
if ( V_214 > sizeof( V_213 ) )
V_214 = sizeof( V_213 ) ;
return F_65 ( V_199 , V_212 , V_201 , V_213 , V_214 ) ;
}
static T_6
F_144 ( struct V_197 * V_198 , const char T_7 * V_199 , T_4 V_200 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
struct V_66 * V_53 = V_9 -> V_54 ;
char V_213 [ 20 ] ;
int V_216 = 1 , V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_342 ;
if ( V_200 > 0 ) {
if ( V_200 > sizeof( V_213 ) - 1 )
return - V_65 ;
if ( F_67 ( V_213 , V_199 , V_200 ) )
return - V_217 ;
V_213 [ V_200 ] = 0 ;
V_216 = F_128 ( V_213 , NULL , 0 ) ;
}
F_54 ( L_278 , V_216 ) ;
V_58 = F_13 ( & V_53 -> V_300 . V_301 ) ;
if ( V_58 )
return V_58 ;
V_53 -> V_300 . V_345 = V_216 / V_254 ;
F_142 ( V_9 , V_216 / V_254 ) ;
F_14 ( & V_53 -> V_300 . V_301 ) ;
return V_200 ;
}
static T_6
F_145 ( struct V_197 * V_198 ,
char T_7 * V_199 ,
T_4 V_212 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
T_3 * V_53 = V_9 -> V_54 ;
char V_213 [ 80 ] ;
T_5 V_418 ;
int V_214 , V_58 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_342 ;
V_58 = F_13 ( & V_9 -> V_59 ) ;
if ( V_58 )
return V_58 ;
V_418 = F_32 ( V_419 ) ;
F_14 ( & V_53 -> V_9 -> V_59 ) ;
V_214 = snprintf ( V_213 , sizeof( V_213 ) ,
L_279 , ( V_418 & V_420 ) >>
V_421 ) ;
if ( V_214 > sizeof( V_213 ) )
V_214 = sizeof( V_213 ) ;
return F_65 ( V_199 , V_212 , V_201 , V_213 , V_214 ) ;
}
static T_6
F_146 ( struct V_197 * V_198 ,
const char T_7 * V_199 ,
T_4 V_200 ,
T_8 * V_201 )
{
struct V_8 * V_9 = V_198 -> V_202 ;
struct V_66 * V_53 = V_9 -> V_54 ;
char V_213 [ 20 ] ;
T_5 V_418 ;
int V_216 = 1 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_342 ;
if ( V_200 > 0 ) {
if ( V_200 > sizeof( V_213 ) - 1 )
return - V_65 ;
if ( F_67 ( V_213 , V_199 , V_200 ) )
return - V_217 ;
V_213 [ V_200 ] = 0 ;
V_216 = F_128 ( V_213 , NULL , 0 ) ;
}
if ( V_216 < 0 || V_216 > 3 )
return - V_65 ;
F_54 ( L_280 , V_216 ) ;
V_418 = F_32 ( V_419 ) ;
V_418 &= ~ V_420 ;
V_418 |= ( V_216 << V_421 ) ;
F_147 ( V_419 , V_418 ) ;
return V_200 ;
}
static int
F_148 ( struct V_422 * V_10 ,
struct V_423 * V_424 ,
const void * V_425 )
{
struct V_5 * V_6 ;
V_6 = F_108 ( sizeof( struct V_5 ) , V_205 ) ;
if ( V_6 == NULL ) {
F_149 ( V_424 ) ;
return - V_206 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_426 = V_424 ;
V_6 -> V_50 = ( void * ) V_425 ;
F_88 ( & V_10 -> V_427 ) ;
F_150 ( & V_6 -> V_49 , & V_10 -> V_428 ) ;
F_14 ( & V_10 -> V_427 ) ;
return 0 ;
}
static int F_151 ( struct V_203 * V_203 , struct V_197 * V_197 )
{
struct V_8 * V_9 = V_203 -> V_204 ;
struct V_66 * V_53 = V_9 -> V_54 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_74 ( V_53 ) ;
return 0 ;
}
static int F_152 ( struct V_203 * V_203 , struct V_197 * V_197 )
{
struct V_8 * V_9 = V_203 -> V_204 ;
struct V_66 * V_53 = V_9 -> V_54 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_76 ( V_53 ) ;
return 0 ;
}
static int F_153 ( struct V_423 * V_429 , struct V_422 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_423 * V_424 ;
V_424 = F_154 ( L_281 ,
V_430 ,
V_429 , V_9 ,
& V_431 ) ;
if ( F_155 ( V_424 ) )
return F_156 ( V_424 ) ;
return F_148 ( V_10 , V_424 , & V_431 ) ;
}
static int F_157 ( struct V_423 * V_429 ,
struct V_422 * V_10 ,
const char * V_37 ,
const struct V_432 * V_433 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_423 * V_424 ;
V_424 = F_154 ( V_37 ,
V_434 | V_435 ,
V_429 , V_9 ,
V_433 ) ;
if ( F_155 ( V_424 ) )
return F_156 ( V_424 ) ;
return F_148 ( V_10 , V_424 , V_433 ) ;
}
int F_158 ( struct V_422 * V_10 )
{
int V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_282 ,
& V_437 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_153 ( V_10 -> V_436 , V_10 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_283 ,
& V_438 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_284 ,
& V_439 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_285 ,
& V_440 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_286 ,
& V_441 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_287 ,
& V_442 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_288 ,
& V_443 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_157 ( V_10 -> V_436 , V_10 ,
L_289 ,
& V_444 ) ;
if ( V_58 )
return V_58 ;
return F_159 ( V_445 ,
V_446 ,
V_10 -> V_436 , V_10 ) ;
}
void F_160 ( struct V_422 * V_10 )
{
F_161 ( V_445 ,
V_446 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_431 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_437 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_438 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_439 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_440 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_442 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_441 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_443 ,
1 , V_10 ) ;
F_161 ( (struct V_447 * ) & V_444 ,
1 , V_10 ) ;
}
