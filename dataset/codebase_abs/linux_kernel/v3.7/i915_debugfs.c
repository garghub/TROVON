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
if ( V_16 -> V_42 || V_16 -> V_43 ) {
char V_44 [ 3 ] , * V_45 = V_44 ;
if ( V_16 -> V_42 )
* V_45 ++ = 'p' ;
if ( V_16 -> V_43 )
* V_45 ++ = 'f' ;
* V_45 = '\0' ;
F_4 ( V_3 , L_21 , V_44 ) ;
}
if ( V_16 -> V_46 != NULL )
F_4 ( V_3 , L_22 , V_16 -> V_46 -> V_37 ) ;
}
static int F_12 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_47 = ( T_2 ) V_6 -> V_48 -> V_4 ;
struct V_49 * V_50 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_15 * V_16 ;
T_4 V_53 , V_54 ;
int V_55 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
switch ( V_47 ) {
case V_58 :
F_4 ( V_3 , L_23 ) ;
V_50 = & V_51 -> V_59 . V_60 ;
break;
case V_61 :
F_4 ( V_3 , L_24 ) ;
V_50 = & V_51 -> V_59 . V_62 ;
break;
default:
F_14 ( & V_9 -> V_57 ) ;
return - V_63 ;
}
V_53 = V_54 = V_55 = 0 ;
F_15 (obj, head, mm_list) {
F_4 ( V_3 , L_25 ) ;
F_11 ( V_3 , V_16 ) ;
F_4 ( V_3 , L_26 ) ;
V_53 += V_16 -> V_26 . V_27 ;
V_54 += V_16 -> V_40 -> V_27 ;
V_55 ++ ;
}
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_27 ,
V_55 , V_53 , V_54 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
T_5 V_55 , V_65 , V_66 ;
T_4 V_27 , V_67 , V_68 ;
struct V_15 * V_16 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_28 ,
V_51 -> V_59 . V_69 ,
V_51 -> V_59 . V_70 ) ;
V_27 = V_55 = V_67 = V_65 = 0 ;
F_17 ( & V_51 -> V_59 . V_71 , V_72 ) ;
F_4 ( V_3 , L_29 ,
V_55 , V_65 , V_27 , V_67 ) ;
V_27 = V_55 = V_67 = V_65 = 0 ;
F_17 ( & V_51 -> V_59 . V_60 , V_73 ) ;
F_4 ( V_3 , L_30 ,
V_55 , V_65 , V_27 , V_67 ) ;
V_27 = V_55 = V_67 = V_65 = 0 ;
F_17 ( & V_51 -> V_59 . V_62 , V_73 ) ;
F_4 ( V_3 , L_31 ,
V_55 , V_65 , V_27 , V_67 ) ;
V_27 = V_55 = V_68 = V_66 = 0 ;
F_15 (obj, &dev_priv->mm.unbound_list, gtt_list) {
V_27 += V_16 -> V_26 . V_27 , ++ V_55 ;
if ( V_16 -> V_35 == V_36 )
V_68 += V_16 -> V_26 . V_27 , ++ V_66 ;
}
F_4 ( V_3 , L_32 , V_55 , V_27 ) ;
V_27 = V_55 = V_67 = V_65 = 0 ;
F_15 (obj, &dev_priv->mm.bound_list, gtt_list) {
if ( V_16 -> V_43 ) {
V_27 += V_16 -> V_40 -> V_27 ;
++ V_55 ;
}
if ( V_16 -> V_42 ) {
V_67 += V_16 -> V_40 -> V_27 ;
++ V_65 ;
}
if ( V_16 -> V_35 == V_36 ) {
V_68 += V_16 -> V_26 . V_27 ;
++ V_66 ;
}
}
F_4 ( V_3 , L_33 ,
V_66 , V_68 ) ;
F_4 ( V_3 , L_34 ,
V_65 , V_67 ) ;
F_4 ( V_3 , L_35 ,
V_55 , V_27 ) ;
F_4 ( V_3 , L_36 ,
V_51 -> V_59 . V_74 , V_51 -> V_59 . V_75 ) ;
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_2 V_47 = ( T_2 ) V_6 -> V_48 -> V_4 ;
struct V_64 * V_51 = V_9 -> V_52 ;
struct V_15 * V_16 ;
T_4 V_53 , V_54 ;
int V_55 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_53 = V_54 = V_55 = 0 ;
F_15 (obj, &dev_priv->mm.bound_list, gtt_list) {
if ( V_47 == V_76 && V_16 -> V_18 == 0 )
continue;
F_4 ( V_3 , L_25 ) ;
F_11 ( V_3 , V_16 ) ;
F_4 ( V_3 , L_26 ) ;
V_53 += V_16 -> V_26 . V_27 ;
V_54 += V_16 -> V_40 -> V_27 ;
V_55 ++ ;
}
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_27 ,
V_55 , V_53 , V_54 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
unsigned long V_77 ;
struct V_78 * V_79 ;
F_15 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_80 = F_20 ( V_79 -> V_80 ) ;
const char V_81 = F_21 ( V_79 -> V_81 ) ;
struct V_82 * V_83 ;
F_22 ( & V_9 -> V_84 , V_77 ) ;
V_83 = V_79 -> V_85 ;
if ( V_83 == NULL ) {
F_4 ( V_3 , L_37 ,
V_80 , V_81 ) ;
} else {
if ( ! V_83 -> V_86 ) {
F_4 ( V_3 , L_38 ,
V_80 , V_81 ) ;
} else {
F_4 ( V_3 , L_39 ,
V_80 , V_81 ) ;
}
if ( V_83 -> V_87 )
F_4 ( V_3 , L_40 ) ;
else
F_4 ( V_3 , L_41 ) ;
F_4 ( V_3 , L_42 , V_83 -> V_86 ) ;
if ( V_83 -> V_88 ) {
struct V_15 * V_16 = V_83 -> V_88 ;
if ( V_16 )
F_4 ( V_3 , L_43 , V_16 -> V_41 ) ;
}
if ( V_83 -> V_89 ) {
struct V_15 * V_16 = V_83 -> V_89 ;
if ( V_16 )
F_4 ( V_3 , L_44 , V_16 -> V_41 ) ;
}
}
F_23 ( & V_9 -> V_84 , V_77 ) ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_90 * V_46 ;
struct V_91 * V_92 ;
int V_56 , V_55 , V_93 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_55 = 0 ;
F_25 (ring, dev_priv, i) {
if ( F_26 ( & V_46 -> V_94 ) )
continue;
F_4 ( V_3 , L_45 , V_46 -> V_37 ) ;
F_15 (gem_request,
&ring->request_list,
list) {
F_4 ( V_3 , L_46 ,
V_92 -> V_95 ,
( int ) ( V_96 - V_92 -> V_97 ) ) ;
}
V_55 ++ ;
}
F_14 ( & V_9 -> V_57 ) ;
if ( V_55 == 0 )
F_4 ( V_3 , L_47 ) ;
return 0 ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_90 * V_46 )
{
if ( V_46 -> V_98 ) {
F_4 ( V_3 , L_48 ,
V_46 -> V_37 , V_46 -> V_98 ( V_46 , false ) ) ;
}
}
static int F_28 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_90 * V_46 ;
int V_56 , V_93 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_25 (ring, dev_priv, i)
F_27 ( V_3 , V_46 ) ;
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_90 * V_46 ;
int V_56 , V_93 , V_80 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
if ( F_30 ( V_9 ) ) {
F_4 ( V_3 , L_49 ,
F_31 ( V_99 ) ) ;
F_4 ( V_3 , L_50 ,
F_31 ( V_100 ) ) ;
F_4 ( V_3 , L_51 ,
F_31 ( V_101 ) ) ;
F_4 ( V_3 , L_52 ,
F_31 ( V_102 ) ) ;
F_32 (pipe)
F_4 ( V_3 , L_53 ,
F_20 ( V_80 ) ,
F_31 ( F_33 ( V_80 ) ) ) ;
F_4 ( V_3 , L_54 ,
F_31 ( V_103 ) ) ;
F_4 ( V_3 , L_55 ,
F_31 ( V_104 ) ) ;
F_4 ( V_3 , L_56 ,
F_31 ( V_105 ) ) ;
F_4 ( V_3 , L_57 ,
F_31 ( V_106 ) ) ;
F_4 ( V_3 , L_58 ,
F_31 ( V_107 ) ) ;
F_4 ( V_3 , L_59 ,
F_31 ( V_108 ) ) ;
F_4 ( V_3 , L_60 ,
F_31 ( V_109 ) ) ;
F_4 ( V_3 , L_61 ,
F_31 ( V_110 ) ) ;
F_4 ( V_3 , L_62 ,
F_31 ( V_111 ) ) ;
F_4 ( V_3 , L_63 ,
F_31 ( V_112 ) ) ;
} else if ( ! F_34 ( V_9 ) ) {
F_4 ( V_3 , L_64 ,
F_31 ( V_113 ) ) ;
F_4 ( V_3 , L_65 ,
F_31 ( V_114 ) ) ;
F_4 ( V_3 , L_66 ,
F_31 ( V_115 ) ) ;
F_32 (pipe)
F_4 ( V_3 , L_67 ,
F_20 ( V_80 ) ,
F_31 ( F_33 ( V_80 ) ) ) ;
} else {
F_4 ( V_3 , L_68 ,
F_31 ( V_116 ) ) ;
F_4 ( V_3 , L_69 ,
F_31 ( V_117 ) ) ;
F_4 ( V_3 , L_70 ,
F_31 ( V_118 ) ) ;
F_4 ( V_3 , L_71 ,
F_31 ( V_119 ) ) ;
F_4 ( V_3 , L_72 ,
F_31 ( V_120 ) ) ;
F_4 ( V_3 , L_73 ,
F_31 ( V_121 ) ) ;
F_4 ( V_3 , L_74 ,
F_31 ( V_104 ) ) ;
F_4 ( V_3 , L_75 ,
F_31 ( V_105 ) ) ;
F_4 ( V_3 , L_76 ,
F_31 ( V_106 ) ) ;
}
F_4 ( V_3 , L_77 ,
F_35 ( & V_51 -> V_122 ) ) ;
F_25 (ring, dev_priv, i) {
if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
F_4 ( V_3 ,
L_78 ,
V_46 -> V_37 , F_38 ( V_46 ) ) ;
}
F_27 ( V_3 , V_46 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_93 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_79 , V_51 -> V_123 ) ;
F_4 ( V_3 , L_80 , V_51 -> V_124 ) ;
for ( V_93 = 0 ; V_93 < V_51 -> V_124 ; V_93 ++ ) {
struct V_15 * V_16 = V_51 -> V_125 [ V_93 ] . V_16 ;
F_4 ( V_3 , L_81 ,
V_93 , V_51 -> V_125 [ V_93 ] . V_18 ) ;
if ( V_16 == NULL )
F_4 ( V_3 , L_82 ) ;
else
F_11 ( V_3 , V_16 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_90 * V_46 ;
const volatile T_5 T_6 * V_126 ;
int V_93 ;
V_46 = & V_51 -> V_46 [ ( T_2 ) V_6 -> V_48 -> V_4 ] ;
V_126 = ( volatile T_5 T_6 * ) V_46 -> V_127 . V_128 ;
if ( V_126 == NULL )
return 0 ;
for ( V_93 = 0 ; V_93 < 4096 / sizeof( T_5 ) / 4 ; V_93 += 4 ) {
F_4 ( V_3 , L_83 ,
V_93 * 4 ,
V_126 [ V_93 ] , V_126 [ V_93 + 1 ] , V_126 [ V_93 + 2 ] , V_126 [ V_93 + 3 ] ) ;
}
return 0 ;
}
static const char * F_41 ( int V_46 )
{
switch ( V_46 ) {
case V_129 : return L_84 ;
case V_130 : return L_85 ;
case V_131 : return L_86 ;
default: return L_13 ;
}
}
static const char * F_42 ( int V_132 )
{
if ( V_132 > 0 )
return L_87 ;
else if ( V_132 < 0 )
return L_88 ;
else
return L_13 ;
}
static const char * F_43 ( int V_133 )
{
switch ( V_133 ) {
default:
case V_20 : return L_13 ;
case V_21 : return L_89 ;
case V_22 : return L_90 ;
}
}
static const char * F_44 ( int V_34 )
{
return V_34 ? L_15 : L_13 ;
}
static const char * F_45 ( int V_134 )
{
return V_134 ? L_16 : L_13 ;
}
static void F_46 ( struct V_2 * V_3 ,
const char * V_37 ,
struct V_135 * V_136 ,
int V_55 )
{
F_4 ( V_3 , L_91 , V_37 , V_55 ) ;
while ( V_55 -- ) {
F_4 ( V_3 , L_92 ,
V_136 -> V_41 ,
V_136 -> V_27 ,
V_136 -> V_28 ,
V_136 -> V_29 ,
V_136 -> V_137 , V_136 -> V_138 ,
F_42 ( V_136 -> V_132 ) ,
F_43 ( V_136 -> V_133 ) ,
F_44 ( V_136 -> V_34 ) ,
F_45 ( V_136 -> V_134 ) ,
V_136 -> V_46 != - 1 ? L_7 : L_13 ,
F_41 ( V_136 -> V_46 ) ,
F_10 ( V_136 -> V_33 ) ) ;
if ( V_136 -> V_37 )
F_4 ( V_3 , L_17 , V_136 -> V_37 ) ;
if ( V_136 -> V_38 != V_39 )
F_4 ( V_3 , L_19 , V_136 -> V_38 ) ;
F_4 ( V_3 , L_26 ) ;
V_136 ++ ;
}
}
static void F_47 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
struct V_139 * error ,
unsigned V_46 )
{
F_48 ( V_46 >= V_140 ) ;
F_4 ( V_3 , L_93 , F_41 ( V_46 ) ) ;
F_4 ( V_3 , L_94 , error -> V_50 [ V_46 ] ) ;
F_4 ( V_3 , L_95 , error -> V_141 [ V_46 ] ) ;
F_4 ( V_3 , L_96 , error -> V_142 [ V_46 ] ) ;
F_4 ( V_3 , L_97 , error -> V_143 [ V_46 ] ) ;
F_4 ( V_3 , L_98 , error -> V_144 [ V_46 ] ) ;
F_4 ( V_3 , L_99 , error -> V_145 [ V_46 ] ) ;
if ( V_46 == V_129 && F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_100 , error -> V_146 ) ;
if ( F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_101 , error -> V_147 [ V_46 ] ) ;
F_4 ( V_3 , L_102 , error -> V_148 [ V_46 ] ) ;
F_4 ( V_3 , L_103 , error -> V_149 [ V_46 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_104 , error -> V_150 [ V_46 ] ) ;
F_4 ( V_3 , L_105 , error -> V_151 [ V_46 ] ) ;
F_4 ( V_3 , L_106 ,
error -> V_152 [ V_46 ] [ 0 ] ) ;
F_4 ( V_3 , L_107 ,
error -> V_152 [ V_46 ] [ 1 ] ) ;
}
F_4 ( V_3 , L_108 , error -> V_95 [ V_46 ] ) ;
F_4 ( V_3 , L_109 , F_1 ( error -> V_153 [ V_46 ] ) ) ;
F_4 ( V_3 , L_110 , error -> V_154 [ V_46 ] ) ;
F_4 ( V_3 , L_111 , error -> V_155 [ V_46 ] ) ;
}
static int F_49 ( struct V_2 * V_3 , void * V_156 )
{
struct V_157 * V_158 = V_3 -> V_7 ;
struct V_8 * V_9 = V_158 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_139 * error = V_158 -> error ;
struct V_90 * V_46 ;
int V_93 , V_159 , V_160 , V_161 , V_162 ;
if ( ! error ) {
F_4 ( V_3 , L_112 ) ;
return 0 ;
}
F_4 ( V_3 , L_113 , error -> time . V_163 ,
error -> time . V_164 ) ;
F_4 ( V_3 , L_114 , V_9 -> V_165 ) ;
F_4 ( V_3 , L_115 , error -> V_166 ) ;
F_4 ( V_3 , L_116 , error -> V_167 ) ;
F_4 ( V_3 , L_117 , error -> V_168 ) ;
F_4 ( V_3 , L_118 , error -> V_169 ) ;
for ( V_93 = 0 ; V_93 < V_51 -> V_124 ; V_93 ++ )
F_4 ( V_3 , L_119 , V_93 , error -> V_170 [ V_93 ] ) ;
for ( V_93 = 0 ; V_93 < F_50 ( error -> V_171 ) ; V_93 ++ )
F_4 ( V_3 , L_120 , V_93 , error -> V_171 [ V_93 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_121 , error -> error ) ;
F_4 ( V_3 , L_122 , error -> V_172 ) ;
}
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_123 , error -> V_173 ) ;
F_25 (ring, dev_priv, i)
F_47 ( V_3 , V_9 , error , V_93 ) ;
if ( error -> V_174 )
F_46 ( V_3 , L_124 ,
error -> V_174 ,
error -> V_175 ) ;
if ( error -> V_176 )
F_46 ( V_3 , L_125 ,
error -> V_176 ,
error -> V_177 ) ;
for ( V_93 = 0 ; V_93 < F_50 ( error -> V_46 ) ; V_93 ++ ) {
struct V_178 * V_16 ;
if ( ( V_16 = error -> V_46 [ V_93 ] . V_179 ) ) {
F_4 ( V_3 , L_126 ,
V_51 -> V_46 [ V_93 ] . V_37 ,
V_16 -> V_41 ) ;
V_161 = 0 ;
for ( V_160 = 0 ; V_160 < V_16 -> V_180 ; V_160 ++ ) {
for ( V_162 = 0 ; V_162 < V_181 / 4 ; V_162 ++ ) {
F_4 ( V_3 , L_127 , V_161 , V_16 -> V_182 [ V_160 ] [ V_162 ] ) ;
V_161 += 4 ;
}
}
}
if ( error -> V_46 [ V_93 ] . V_183 ) {
F_4 ( V_3 , L_128 ,
V_51 -> V_46 [ V_93 ] . V_37 ,
error -> V_46 [ V_93 ] . V_183 ) ;
for ( V_159 = 0 ; V_159 < error -> V_46 [ V_93 ] . V_183 ; V_159 ++ ) {
F_4 ( V_3 , L_129 ,
error -> V_46 [ V_93 ] . V_184 [ V_159 ] . V_95 ,
error -> V_46 [ V_93 ] . V_184 [ V_159 ] . V_96 ,
error -> V_46 [ V_93 ] . V_184 [ V_159 ] . V_141 ) ;
}
}
if ( ( V_16 = error -> V_46 [ V_93 ] . V_185 ) ) {
F_4 ( V_3 , L_130 ,
V_51 -> V_46 [ V_93 ] . V_37 ,
V_16 -> V_41 ) ;
V_161 = 0 ;
for ( V_160 = 0 ; V_160 < V_16 -> V_180 ; V_160 ++ ) {
for ( V_162 = 0 ; V_162 < V_181 / 4 ; V_162 ++ ) {
F_4 ( V_3 , L_127 ,
V_161 ,
V_16 -> V_182 [ V_160 ] [ V_162 ] ) ;
V_161 += 4 ;
}
}
}
}
if ( error -> V_186 )
F_51 ( V_3 , error -> V_186 ) ;
if ( error -> V_187 )
F_52 ( V_3 , V_9 , error -> V_187 ) ;
return 0 ;
}
static T_7
F_53 ( struct V_188 * V_189 ,
const char T_8 * V_190 ,
T_4 V_191 ,
T_9 * V_192 )
{
struct V_2 * V_3 = V_189 -> V_193 ;
struct V_157 * V_158 = V_3 -> V_7 ;
struct V_8 * V_9 = V_158 -> V_9 ;
int V_56 ;
F_54 ( L_131 ) ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_55 ( V_9 ) ;
F_14 ( & V_9 -> V_57 ) ;
return V_191 ;
}
static int F_56 ( struct V_194 * V_194 , struct V_188 * V_188 )
{
struct V_8 * V_9 = V_194 -> V_195 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_157 * V_158 ;
unsigned long V_77 ;
V_158 = F_57 ( sizeof( * V_158 ) , V_196 ) ;
if ( ! V_158 )
return - V_197 ;
V_158 -> V_9 = V_9 ;
F_22 ( & V_51 -> V_198 , V_77 ) ;
V_158 -> error = V_51 -> V_199 ;
if ( V_158 -> error )
F_58 ( & V_158 -> error -> V_200 ) ;
F_23 ( & V_51 -> V_198 , V_77 ) ;
return F_59 ( V_188 , F_49 , V_158 ) ;
}
static int F_60 ( struct V_194 * V_194 , struct V_188 * V_188 )
{
struct V_2 * V_3 = V_188 -> V_193 ;
struct V_157 * V_158 = V_3 -> V_7 ;
if ( V_158 -> error )
F_61 ( & V_158 -> error -> V_200 , V_201 ) ;
F_62 ( V_158 ) ;
return F_63 ( V_194 , V_188 ) ;
}
static int F_64 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_10 V_202 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_202 = F_65 ( V_203 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_132 , ( V_202 >> 8 ) & 0x3f , ( V_202 & 0x3f ) ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
if ( F_67 ( V_9 ) ) {
T_10 V_204 = F_65 ( V_205 ) ;
T_10 V_206 = F_65 ( V_207 ) ;
F_4 ( V_3 , L_133 , ( V_204 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_134 , V_204 & 0x3f ) ;
F_4 ( V_3 , L_135 , ( V_206 & V_208 ) >>
V_209 ) ;
F_4 ( V_3 , L_136 ,
( V_206 & V_210 ) >> V_211 ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
T_5 V_212 = F_31 ( V_213 ) ;
T_5 V_214 = F_31 ( V_215 ) ;
T_5 V_216 = F_31 ( V_217 ) ;
T_5 V_218 ;
T_5 V_219 , V_220 , V_221 ;
T_5 V_222 , V_223 , V_224 ;
int V_225 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_68 ( V_51 ) ;
V_218 = F_31 ( V_226 ) ;
V_219 = F_31 ( V_227 ) ;
V_220 = F_31 ( V_228 ) ;
V_221 = F_31 ( V_229 ) ;
V_222 = F_31 ( V_230 ) ;
V_223 = F_31 ( V_231 ) ;
V_224 = F_31 ( V_232 ) ;
F_69 ( V_51 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_137 , V_212 ) ;
F_4 ( V_3 , L_138 , V_218 ) ;
F_4 ( V_3 , L_139 ,
( V_212 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_140 ,
V_212 & 0xff ) ;
F_4 ( V_3 , L_141 ,
V_214 & 0xff ) ;
F_4 ( V_3 , L_142 , ( ( V_218 & V_233 ) >>
V_234 ) * V_235 ) ;
F_4 ( V_3 , L_143 , V_219 &
V_236 ) ;
F_4 ( V_3 , L_144 , V_220 &
V_237 ) ;
F_4 ( V_3 , L_145 , V_221 &
V_237 ) ;
F_4 ( V_3 , L_146 , V_222 &
V_238 ) ;
F_4 ( V_3 , L_147 , V_223 &
V_237 ) ;
F_4 ( V_3 , L_148 , V_224 &
V_237 ) ;
V_225 = ( V_216 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_149 ,
V_225 * V_235 ) ;
V_225 = ( V_216 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_150 ,
V_225 * V_235 ) ;
V_225 = V_216 & 0xff ;
F_4 ( V_3 , L_151 ,
V_225 * V_235 ) ;
} else {
F_4 ( V_3 , L_152 ) ;
}
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_5 V_239 ;
int V_56 , V_93 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
for ( V_93 = 0 ; V_93 < 16 ; V_93 ++ ) {
V_239 = F_31 ( V_240 + V_93 * 4 ) ;
F_4 ( V_3 , L_153 , V_93 , V_239 ,
( V_239 & V_241 ) >> V_242 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static inline int F_71 ( int V_243 )
{
return 1250 - ( V_243 * 25 ) ;
}
static int F_72 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_5 V_244 ;
int V_56 , V_93 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
for ( V_93 = 1 ; V_93 <= 32 ; V_93 ++ ) {
V_244 = F_31 ( V_245 + V_93 * 4 ) ;
F_4 ( V_3 , L_154 , V_93 , V_244 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_5 V_246 , V_247 ;
T_10 V_248 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_246 = F_31 ( V_249 ) ;
V_247 = F_31 ( V_250 ) ;
V_248 = F_65 ( V_203 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_155 , ( V_246 & V_251 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_156 ,
( V_246 & V_252 ) >>
V_253 ) ;
F_4 ( V_3 , L_157 ,
V_246 & V_254 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_158 ,
V_246 & V_255 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_159 ,
V_246 & V_256 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_160 ,
( V_246 & V_257 ) >> V_258 ) ;
F_4 ( V_3 , L_161 ,
( V_246 & V_259 ) >> V_260 ) ;
F_4 ( V_3 , L_162 , ( V_246 & V_261 ) ) ;
F_4 ( V_3 , L_163 , ( V_248 & 0x3f ) ) ;
F_4 ( V_3 , L_164 , ( ( V_248 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_165 ,
( V_247 & V_262 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_166 ) ;
switch ( V_247 & V_263 ) {
case V_264 :
F_4 ( V_3 , L_167 ) ;
break;
case V_265 :
F_4 ( V_3 , L_168 ) ;
break;
case V_266 :
F_4 ( V_3 , L_169 ) ;
break;
case V_267 :
F_4 ( V_3 , L_170 ) ;
break;
case V_268 :
F_4 ( V_3 , L_171 ) ;
break;
case V_269 :
F_4 ( V_3 , L_172 ) ;
break;
default:
F_4 ( V_3 , L_173 ) ;
break;
}
return 0 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
T_5 V_270 , V_271 , V_272 ;
unsigned V_273 ;
int V_55 = 0 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_75 ( & V_51 -> V_274 ) ;
V_273 = V_51 -> V_273 ;
F_76 ( & V_51 -> V_274 ) ;
if ( V_273 ) {
F_4 ( V_3 , L_174
L_175 ) ;
} else {
while ( V_55 ++ < 50 && ( F_77 ( V_275 ) & 1 ) )
F_78 ( 10 ) ;
F_4 ( V_3 , L_176 , F_1 ( V_55 < 51 ) ) ;
}
V_271 = F_79 ( V_51 -> V_276 + V_277 ) ;
F_80 ( false , V_277 , V_271 , 4 ) ;
V_270 = F_31 ( V_278 ) ;
V_272 = F_31 ( V_279 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_177 ,
F_1 ( V_270 & V_280 ) ) ;
F_4 ( V_3 , L_157 ,
F_1 ( V_270 & V_281 ) ) ;
F_4 ( V_3 , L_158 ,
F_1 ( ( V_270 & V_282 ) ==
V_283 ) ) ;
F_4 ( V_3 , L_178 ,
F_1 ( V_272 & V_284 ) ) ;
F_4 ( V_3 , L_179 ,
F_1 ( V_272 & V_285 ) ) ;
F_4 ( V_3 , L_180 ,
F_1 ( V_272 & V_286 ) ) ;
F_4 ( V_3 , L_181 ,
F_1 ( V_272 & V_287 ) ) ;
F_4 ( V_3 , L_182 ) ;
switch ( V_271 & V_288 ) {
case V_289 :
if ( V_271 & V_290 )
F_4 ( V_3 , L_183 ) ;
else
F_4 ( V_3 , L_167 ) ;
break;
case V_291 :
F_4 ( V_3 , L_184 ) ;
break;
case V_292 :
F_4 ( V_3 , L_185 ) ;
break;
case V_293 :
F_4 ( V_3 , L_186 ) ;
break;
default:
F_4 ( V_3 , L_187 ) ;
break;
}
F_4 ( V_3 , L_188 ,
F_1 ( V_271 & V_290 ) ) ;
F_4 ( V_3 , L_189 ,
F_31 ( V_294 ) ) ;
F_4 ( V_3 , L_190 ,
F_31 ( V_295 ) ) ;
F_4 ( V_3 , L_191 ,
F_31 ( V_296 ) ) ;
F_4 ( V_3 , L_192 ,
F_31 ( V_297 ) ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_36 ( V_9 ) || F_37 ( V_9 ) )
return F_74 ( V_3 ) ;
else
return F_73 ( V_3 ) ;
}
static int F_82 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
if ( ! F_83 ( V_9 ) ) {
F_4 ( V_3 , L_193 ) ;
return 0 ;
}
if ( F_84 ( V_9 ) ) {
F_4 ( V_3 , L_194 ) ;
} else {
F_4 ( V_3 , L_195 ) ;
switch ( V_51 -> V_298 ) {
case V_299 :
F_4 ( V_3 , L_196 ) ;
break;
case V_300 :
F_4 ( V_3 , L_197 ) ;
break;
case V_301 :
F_4 ( V_3 , L_198 ) ;
break;
case V_302 :
F_4 ( V_3 , L_199 ) ;
break;
case V_303 :
F_4 ( V_3 , L_200 ) ;
break;
case V_304 :
F_4 ( V_3 , L_201 ) ;
break;
case V_305 :
F_4 ( V_3 , L_202 ) ;
break;
case V_306 :
F_4 ( V_3 , L_203 ) ;
break;
default:
F_4 ( V_3 , L_204 ) ;
}
F_4 ( V_3 , L_26 ) ;
}
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
bool V_307 = false ;
if ( F_34 ( V_9 ) )
V_307 = F_31 ( V_308 ) & V_309 ;
else if ( F_86 ( V_9 ) || F_87 ( V_9 ) || F_88 ( V_9 ) )
V_307 = F_31 ( V_310 ) & V_311 ;
else if ( F_89 ( V_9 ) )
V_307 = F_31 ( V_312 ) & V_313 ;
else if ( F_90 ( V_9 ) )
V_307 = F_31 ( V_314 ) & V_315 ;
F_4 ( V_3 , L_205 ,
V_307 ? L_206 : L_207 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
unsigned long V_316 , V_317 , V_318 ;
int V_56 ;
if ( ! F_67 ( V_9 ) )
return - V_319 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_316 = F_92 ( V_51 ) ;
V_317 = F_93 ( V_51 ) ;
V_318 = F_94 ( V_51 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_208 , V_316 ) ;
F_4 ( V_3 , L_209 , V_317 ) ;
F_4 ( V_3 , L_210 , V_318 ) ;
F_4 ( V_3 , L_211 , V_317 + V_318 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
int V_320 , V_321 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) ) {
F_4 ( V_3 , L_212 ) ;
return 0 ;
}
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_213 ) ;
for ( V_320 = V_51 -> V_322 . V_323 ;
V_320 <= V_51 -> V_322 . V_324 ;
V_320 ++ ) {
F_96 ( V_325 , V_320 ) ;
F_96 ( V_326 , V_327 |
V_328 ) ;
if ( F_97 ( ( F_31 ( V_326 ) &
V_327 ) == 0 , 10 ) ) {
F_98 ( L_214 ) ;
continue;
}
V_321 = F_31 ( V_325 ) ;
F_4 ( V_3 , L_215 , V_320 * V_235 , V_321 * 100 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_216 , ( unsigned long ) F_31 ( 0x112f4 ) ) ;
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_329 * V_330 = & V_51 -> V_330 ;
void * V_4 = F_101 ( V_331 , V_196 ) ;
int V_56 ;
if ( V_4 == NULL )
return - V_197 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
goto V_332;
if ( V_330 -> V_333 ) {
F_102 ( V_4 , V_330 -> V_333 , V_331 ) ;
F_103 ( V_3 , V_4 , V_331 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
V_332:
F_62 ( V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_334 * V_335 ;
struct V_336 * V_337 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_338 . V_339 ) ;
if ( V_56 )
return V_56 ;
V_335 = V_51 -> V_340 ;
V_337 = F_105 ( V_335 -> V_341 . V_337 ) ;
F_4 ( V_3 , L_217 ,
V_337 -> V_26 . V_342 ,
V_337 -> V_26 . V_343 ,
V_337 -> V_26 . V_344 ,
V_337 -> V_26 . V_345 ) ;
F_11 ( V_3 , V_337 -> V_16 ) ;
F_4 ( V_3 , L_26 ) ;
F_15 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_337 -> V_26 == V_335 -> V_341 . V_337 )
continue;
F_4 ( V_3 , L_218 ,
V_337 -> V_26 . V_342 ,
V_337 -> V_26 . V_343 ,
V_337 -> V_26 . V_344 ,
V_337 -> V_26 . V_345 ) ;
F_11 ( V_3 , V_337 -> V_16 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_14 ( & V_9 -> V_338 . V_339 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 , void * V_156 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_338 . V_339 ) ;
if ( V_56 )
return V_56 ;
if ( V_51 -> V_346 ) {
F_4 ( V_3 , L_219 ) ;
F_11 ( V_3 , V_51 -> V_346 ) ;
F_4 ( V_3 , L_26 ) ;
}
if ( V_51 -> V_347 ) {
F_4 ( V_3 , L_220 ) ;
F_11 ( V_3 , V_51 -> V_347 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_14 ( & V_9 -> V_338 . V_339 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
unsigned V_273 ;
F_75 ( & V_51 -> V_274 ) ;
V_273 = V_51 -> V_273 ;
F_76 ( & V_51 -> V_274 ) ;
F_4 ( V_3 , L_221 , V_273 ) ;
return 0 ;
}
static const char * F_108 ( unsigned V_348 )
{
switch( V_348 ) {
case V_349 :
return L_222 ;
case V_350 :
return L_223 ;
case V_351 :
return L_224 ;
case V_352 :
return L_225 ;
case V_353 :
return L_226 ;
case V_354 :
return L_227 ;
case V_355 :
return L_228 ;
case V_356 :
return L_229 ;
}
return L_230 ;
}
static int F_109 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_231 ,
F_108 ( V_51 -> V_59 . V_357 ) ) ;
F_4 ( V_3 , L_232 ,
F_108 ( V_51 -> V_59 . V_358 ) ) ;
if ( F_110 ( V_9 ) || F_111 ( V_9 ) ) {
F_4 ( V_3 , L_233 ,
F_31 ( V_359 ) ) ;
F_4 ( V_3 , L_234 ,
F_65 ( V_360 ) ) ;
F_4 ( V_3 , L_235 ,
F_65 ( V_361 ) ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
F_4 ( V_3 , L_236 ,
F_31 ( V_362 ) ) ;
F_4 ( V_3 , L_237 ,
F_31 ( V_363 ) ) ;
F_4 ( V_3 , L_238 ,
F_31 ( V_364 ) ) ;
F_4 ( V_3 , L_239 ,
F_31 ( V_365 ) ) ;
F_4 ( V_3 , L_240 ,
F_31 ( V_366 ) ) ;
F_4 ( V_3 , L_241 ,
F_31 ( V_367 ) ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
struct V_90 * V_46 ;
int V_93 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
if ( F_3 ( V_9 ) -> V_13 == 6 )
F_4 ( V_3 , L_242 , F_31 ( V_368 ) ) ;
F_25 (ring, dev_priv, i) {
F_4 ( V_3 , L_243 , V_46 -> V_37 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_242 , F_31 ( F_113 ( V_46 ) ) ) ;
F_4 ( V_3 , L_244 , F_31 ( F_114 ( V_46 ) ) ) ;
F_4 ( V_3 , L_245 , F_31 ( F_115 ( V_46 ) ) ) ;
F_4 ( V_3 , L_246 , F_31 ( F_116 ( V_46 ) ) ) ;
}
if ( V_51 -> V_59 . V_369 ) {
struct V_370 * V_371 = V_51 -> V_59 . V_369 ;
F_4 ( V_3 , L_247 ) ;
F_4 ( V_3 , L_248 , V_371 -> V_372 ) ;
}
F_4 ( V_3 , L_249 , F_31 ( V_373 ) ) ;
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
int V_56 ;
if ( ! F_30 ( V_9 ) ) {
F_4 ( V_3 , L_250 ) ;
return 0 ;
}
V_56 = F_13 ( & V_9 -> V_338 . V_339 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_251 , F_31 ( V_374 ) ) ;
F_4 ( V_3 , L_252 ,
F_118 ( V_51 , V_375 ) ) ;
F_4 ( V_3 , L_253 ,
F_118 ( V_51 , V_376 ) ) ;
F_4 ( V_3 , L_254 ,
F_118 ( V_51 , V_377 ) ) ;
F_4 ( V_3 , L_255 ,
F_118 ( V_51 , V_378 ) ) ;
F_4 ( V_3 , L_256 ,
F_118 ( V_51 , V_379 ) ) ;
F_4 ( V_3 , L_257 ,
F_118 ( V_51 , V_380 ) ) ;
F_4 ( V_3 , L_258 ,
F_118 ( V_51 , V_381 ) ) ;
F_4 ( V_3 , L_259 ,
F_118 ( V_51 , V_382 ) ) ;
F_4 ( V_3 , L_260 ,
F_118 ( V_51 , V_383 ) ) ;
F_14 ( & V_9 -> V_338 . V_339 ) ;
return 0 ;
}
static T_7
F_119 ( struct V_188 * V_189 ,
char T_8 * V_190 ,
T_4 V_384 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_385 [ 80 ] ;
int V_386 ;
V_386 = snprintf ( V_385 , sizeof( V_385 ) ,
L_261 ,
F_35 ( & V_51 -> V_59 . V_387 ) ) ;
if ( V_386 > sizeof( V_385 ) )
V_386 = sizeof( V_385 ) ;
return F_120 ( V_190 , V_384 , V_192 , V_385 , V_386 ) ;
}
static T_7
F_121 ( struct V_188 * V_189 ,
const char T_8 * V_190 ,
T_4 V_191 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
char V_385 [ 20 ] ;
int V_388 = 1 ;
if ( V_191 > 0 ) {
if ( V_191 > sizeof( V_385 ) - 1 )
return - V_63 ;
if ( F_122 ( V_385 , V_190 , V_191 ) )
return - V_389 ;
V_385 [ V_191 ] = 0 ;
V_388 = F_123 ( V_385 , NULL , 0 ) ;
}
F_124 ( L_262 , V_388 ) ;
F_125 ( V_9 , V_388 ) ;
return V_191 ;
}
static T_7
F_126 ( struct V_188 * V_189 ,
char T_8 * V_190 ,
T_4 V_384 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_385 [ 20 ] ;
int V_386 ;
V_386 = snprintf ( V_385 , sizeof( V_385 ) ,
L_263 , V_51 -> V_390 ) ;
if ( V_386 > sizeof( V_385 ) )
V_386 = sizeof( V_385 ) ;
return F_120 ( V_190 , V_384 , V_192 , V_385 , V_386 ) ;
}
static T_7
F_127 ( struct V_188 * V_189 ,
const char T_8 * V_190 ,
T_4 V_191 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_385 [ 20 ] ;
int V_388 = 0 , V_56 ;
if ( V_191 > 0 ) {
if ( V_191 > sizeof( V_385 ) - 1 )
return - V_63 ;
if ( F_122 ( V_385 , V_190 , V_191 ) )
return - V_389 ;
V_385 [ V_191 ] = 0 ;
V_388 = F_123 ( V_385 , NULL , 0 ) ;
}
F_54 ( L_264 , V_388 ) ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_51 -> V_390 = V_388 ;
F_14 ( & V_9 -> V_57 ) ;
return V_191 ;
}
static T_7
F_128 ( struct V_188 * V_189 ,
char T_8 * V_190 ,
T_4 V_384 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_385 [ 80 ] ;
int V_386 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_319 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_386 = snprintf ( V_385 , sizeof( V_385 ) ,
L_265 , V_51 -> V_322 . V_324 * V_235 ) ;
F_14 ( & V_9 -> V_57 ) ;
if ( V_386 > sizeof( V_385 ) )
V_386 = sizeof( V_385 ) ;
return F_120 ( V_190 , V_384 , V_192 , V_385 , V_386 ) ;
}
static T_7
F_129 ( struct V_188 * V_189 ,
const char T_8 * V_190 ,
T_4 V_191 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_385 [ 20 ] ;
int V_388 = 1 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_319 ;
if ( V_191 > 0 ) {
if ( V_191 > sizeof( V_385 ) - 1 )
return - V_63 ;
if ( F_122 ( V_385 , V_190 , V_191 ) )
return - V_389 ;
V_385 [ V_191 ] = 0 ;
V_388 = F_123 ( V_385 , NULL , 0 ) ;
}
F_54 ( L_266 , V_388 ) ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_51 -> V_322 . V_324 = V_388 / V_235 ;
F_130 ( V_9 , V_388 / V_235 ) ;
F_14 ( & V_9 -> V_57 ) ;
return V_191 ;
}
static T_7
F_131 ( struct V_188 * V_189 , char T_8 * V_190 , T_4 V_384 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_385 [ 80 ] ;
int V_386 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_319 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_386 = snprintf ( V_385 , sizeof( V_385 ) ,
L_267 , V_51 -> V_322 . V_323 * V_235 ) ;
F_14 ( & V_9 -> V_57 ) ;
if ( V_386 > sizeof( V_385 ) )
V_386 = sizeof( V_385 ) ;
return F_120 ( V_190 , V_384 , V_192 , V_385 , V_386 ) ;
}
static T_7
F_132 ( struct V_188 * V_189 , const char T_8 * V_190 , T_4 V_191 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_385 [ 20 ] ;
int V_388 = 1 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_319 ;
if ( V_191 > 0 ) {
if ( V_191 > sizeof( V_385 ) - 1 )
return - V_63 ;
if ( F_122 ( V_385 , V_190 , V_191 ) )
return - V_389 ;
V_385 [ V_191 ] = 0 ;
V_388 = F_123 ( V_385 , NULL , 0 ) ;
}
F_54 ( L_268 , V_388 ) ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_51 -> V_322 . V_323 = V_388 / V_235 ;
F_130 ( V_9 , V_388 / V_235 ) ;
F_14 ( & V_9 -> V_57 ) ;
return V_191 ;
}
static T_7
F_133 ( struct V_188 * V_189 ,
char T_8 * V_190 ,
T_4 V_384 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_385 [ 80 ] ;
T_5 V_391 ;
int V_386 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_319 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_391 = F_31 ( V_392 ) ;
F_14 ( & V_51 -> V_9 -> V_57 ) ;
V_386 = snprintf ( V_385 , sizeof( V_385 ) ,
L_269 , ( V_391 & V_393 ) >>
V_394 ) ;
if ( V_386 > sizeof( V_385 ) )
V_386 = sizeof( V_385 ) ;
return F_120 ( V_190 , V_384 , V_192 , V_385 , V_386 ) ;
}
static T_7
F_134 ( struct V_188 * V_189 ,
const char T_8 * V_190 ,
T_4 V_191 ,
T_9 * V_192 )
{
struct V_8 * V_9 = V_189 -> V_193 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_385 [ 20 ] ;
T_5 V_391 ;
int V_388 = 1 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_319 ;
if ( V_191 > 0 ) {
if ( V_191 > sizeof( V_385 ) - 1 )
return - V_63 ;
if ( F_122 ( V_385 , V_190 , V_191 ) )
return - V_389 ;
V_385 [ V_191 ] = 0 ;
V_388 = F_123 ( V_385 , NULL , 0 ) ;
}
if ( V_388 < 0 || V_388 > 3 )
return - V_63 ;
F_54 ( L_270 , V_388 ) ;
V_391 = F_31 ( V_392 ) ;
V_391 &= ~ V_393 ;
V_391 |= ( V_388 << V_394 ) ;
F_96 ( V_392 , V_391 ) ;
return V_191 ;
}
static int
F_135 ( struct V_395 * V_10 ,
struct V_396 * V_397 ,
const void * V_398 )
{
struct V_5 * V_6 ;
V_6 = F_101 ( sizeof( struct V_5 ) , V_196 ) ;
if ( V_6 == NULL ) {
F_136 ( V_397 ) ;
return - V_197 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_399 = V_397 ;
V_6 -> V_48 = ( void * ) V_398 ;
F_137 ( & V_10 -> V_400 ) ;
F_138 ( & V_6 -> V_47 , & V_10 -> V_401 ) ;
F_14 ( & V_10 -> V_400 ) ;
return 0 ;
}
static int F_139 ( struct V_194 * V_194 , struct V_188 * V_188 )
{
struct V_8 * V_9 = V_194 -> V_195 ;
struct V_64 * V_51 = V_9 -> V_52 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_68 ( V_51 ) ;
return 0 ;
}
static int F_140 ( struct V_194 * V_194 , struct V_188 * V_188 )
{
struct V_8 * V_9 = V_194 -> V_195 ;
struct V_64 * V_51 = V_9 -> V_52 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_69 ( V_51 ) ;
return 0 ;
}
static int F_141 ( struct V_396 * V_402 , struct V_395 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_396 * V_397 ;
V_397 = F_142 ( L_271 ,
V_403 ,
V_402 , V_9 ,
& V_404 ) ;
if ( F_143 ( V_397 ) )
return F_144 ( V_397 ) ;
return F_135 ( V_10 , V_397 , & V_404 ) ;
}
static int F_145 ( struct V_396 * V_402 ,
struct V_395 * V_10 ,
const char * V_37 ,
const struct V_405 * V_406 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_396 * V_397 ;
V_397 = F_142 ( V_37 ,
V_407 | V_408 ,
V_402 , V_9 ,
V_406 ) ;
if ( F_143 ( V_397 ) )
return F_144 ( V_397 ) ;
return F_135 ( V_10 , V_397 , V_406 ) ;
}
int F_146 ( struct V_395 * V_10 )
{
int V_56 ;
V_56 = F_145 ( V_10 -> V_409 , V_10 ,
L_272 ,
& V_410 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_141 ( V_10 -> V_409 , V_10 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_409 , V_10 ,
L_273 ,
& V_411 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_409 , V_10 ,
L_274 ,
& V_412 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_409 , V_10 ,
L_275 ,
& V_413 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_409 , V_10 ,
L_276 ,
& V_414 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_409 , V_10 ,
L_277 ,
& V_415 ) ;
if ( V_56 )
return V_56 ;
return F_147 ( V_416 ,
V_417 ,
V_10 -> V_409 , V_10 ) ;
}
void F_148 ( struct V_395 * V_10 )
{
F_149 ( V_416 ,
V_417 , V_10 ) ;
F_149 ( (struct V_418 * ) & V_404 ,
1 , V_10 ) ;
F_149 ( (struct V_418 * ) & V_410 ,
1 , V_10 ) ;
F_149 ( (struct V_418 * ) & V_411 ,
1 , V_10 ) ;
F_149 ( (struct V_418 * ) & V_412 ,
1 , V_10 ) ;
F_149 ( (struct V_418 * ) & V_413 ,
1 , V_10 ) ;
F_149 ( (struct V_418 * ) & V_414 ,
1 , V_10 ) ;
F_149 ( (struct V_418 * ) & V_415 ,
1 , V_10 ) ;
}
