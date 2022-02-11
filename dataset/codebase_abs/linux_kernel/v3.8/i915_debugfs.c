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
if ( F_23 ( & V_83 -> V_86 ) < V_87 ) {
F_4 ( V_3 , L_38 ,
V_80 , V_81 ) ;
} else {
F_4 ( V_3 , L_39 ,
V_80 , V_81 ) ;
}
if ( V_83 -> V_88 )
F_4 ( V_3 , L_40 ) ;
else
F_4 ( V_3 , L_41 ) ;
F_4 ( V_3 , L_42 , F_23 ( & V_83 -> V_86 ) ) ;
if ( V_83 -> V_89 ) {
struct V_15 * V_16 = V_83 -> V_89 ;
if ( V_16 )
F_4 ( V_3 , L_43 , V_16 -> V_41 ) ;
}
if ( V_83 -> V_90 ) {
struct V_15 * V_16 = V_83 -> V_90 ;
if ( V_16 )
F_4 ( V_3 , L_44 , V_16 -> V_41 ) ;
}
}
F_24 ( & V_9 -> V_84 , V_77 ) ;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_91 * V_46 ;
struct V_92 * V_93 ;
int V_56 , V_55 , V_94 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_55 = 0 ;
F_26 (ring, dev_priv, i) {
if ( F_27 ( & V_46 -> V_95 ) )
continue;
F_4 ( V_3 , L_45 , V_46 -> V_37 ) ;
F_15 (gem_request,
&ring->request_list,
list) {
F_4 ( V_3 , L_46 ,
V_93 -> V_96 ,
( int ) ( V_97 - V_93 -> V_98 ) ) ;
}
V_55 ++ ;
}
F_14 ( & V_9 -> V_57 ) ;
if ( V_55 == 0 )
F_4 ( V_3 , L_47 ) ;
return 0 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_91 * V_46 )
{
if ( V_46 -> V_99 ) {
F_4 ( V_3 , L_48 ,
V_46 -> V_37 , V_46 -> V_99 ( V_46 , false ) ) ;
}
}
static int F_29 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_91 * V_46 ;
int V_56 , V_94 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_26 (ring, dev_priv, i)
F_28 ( V_3 , V_46 ) ;
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_91 * V_46 ;
int V_56 , V_94 , V_80 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
if ( F_31 ( V_9 ) ) {
F_4 ( V_3 , L_49 ,
F_32 ( V_100 ) ) ;
F_4 ( V_3 , L_50 ,
F_32 ( V_101 ) ) ;
F_4 ( V_3 , L_51 ,
F_32 ( V_102 ) ) ;
F_4 ( V_3 , L_52 ,
F_32 ( V_103 ) ) ;
F_33 (pipe)
F_4 ( V_3 , L_53 ,
F_20 ( V_80 ) ,
F_32 ( F_34 ( V_80 ) ) ) ;
F_4 ( V_3 , L_54 ,
F_32 ( V_104 ) ) ;
F_4 ( V_3 , L_55 ,
F_32 ( V_105 ) ) ;
F_4 ( V_3 , L_56 ,
F_32 ( V_106 ) ) ;
F_4 ( V_3 , L_57 ,
F_32 ( V_107 ) ) ;
F_4 ( V_3 , L_58 ,
F_32 ( V_108 ) ) ;
F_4 ( V_3 , L_59 ,
F_32 ( V_109 ) ) ;
F_4 ( V_3 , L_60 ,
F_32 ( V_110 ) ) ;
F_4 ( V_3 , L_61 ,
F_32 ( V_111 ) ) ;
F_4 ( V_3 , L_62 ,
F_32 ( V_112 ) ) ;
F_4 ( V_3 , L_63 ,
F_32 ( V_113 ) ) ;
} else if ( ! F_35 ( V_9 ) ) {
F_4 ( V_3 , L_64 ,
F_32 ( V_114 ) ) ;
F_4 ( V_3 , L_65 ,
F_32 ( V_115 ) ) ;
F_4 ( V_3 , L_66 ,
F_32 ( V_116 ) ) ;
F_33 (pipe)
F_4 ( V_3 , L_67 ,
F_20 ( V_80 ) ,
F_32 ( F_34 ( V_80 ) ) ) ;
} else {
F_4 ( V_3 , L_68 ,
F_32 ( V_117 ) ) ;
F_4 ( V_3 , L_69 ,
F_32 ( V_118 ) ) ;
F_4 ( V_3 , L_70 ,
F_32 ( V_119 ) ) ;
F_4 ( V_3 , L_71 ,
F_32 ( V_120 ) ) ;
F_4 ( V_3 , L_72 ,
F_32 ( V_121 ) ) ;
F_4 ( V_3 , L_73 ,
F_32 ( V_122 ) ) ;
F_4 ( V_3 , L_74 ,
F_32 ( V_105 ) ) ;
F_4 ( V_3 , L_75 ,
F_32 ( V_106 ) ) ;
F_4 ( V_3 , L_76 ,
F_32 ( V_107 ) ) ;
}
F_4 ( V_3 , L_77 ,
F_23 ( & V_51 -> V_123 ) ) ;
F_26 (ring, dev_priv, i) {
if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
F_4 ( V_3 ,
L_78 ,
V_46 -> V_37 , F_38 ( V_46 ) ) ;
}
F_28 ( V_3 , V_46 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_94 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_79 , V_51 -> V_124 ) ;
F_4 ( V_3 , L_80 , V_51 -> V_125 ) ;
for ( V_94 = 0 ; V_94 < V_51 -> V_125 ; V_94 ++ ) {
struct V_15 * V_16 = V_51 -> V_126 [ V_94 ] . V_16 ;
F_4 ( V_3 , L_81 ,
V_94 , V_51 -> V_126 [ V_94 ] . V_18 ) ;
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
struct V_91 * V_46 ;
const volatile T_5 T_6 * V_127 ;
int V_94 ;
V_46 = & V_51 -> V_46 [ ( T_2 ) V_6 -> V_48 -> V_4 ] ;
V_127 = ( volatile T_5 T_6 * ) V_46 -> V_128 . V_129 ;
if ( V_127 == NULL )
return 0 ;
for ( V_94 = 0 ; V_94 < 4096 / sizeof( T_5 ) / 4 ; V_94 += 4 ) {
F_4 ( V_3 , L_83 ,
V_94 * 4 ,
V_127 [ V_94 ] , V_127 [ V_94 + 1 ] , V_127 [ V_94 + 2 ] , V_127 [ V_94 + 3 ] ) ;
}
return 0 ;
}
static const char * F_41 ( int V_46 )
{
switch ( V_46 ) {
case V_130 : return L_84 ;
case V_131 : return L_85 ;
case V_132 : return L_86 ;
default: return L_13 ;
}
}
static const char * F_42 ( int V_133 )
{
if ( V_133 > 0 )
return L_87 ;
else if ( V_133 < 0 )
return L_88 ;
else
return L_13 ;
}
static const char * F_43 ( int V_134 )
{
switch ( V_134 ) {
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
static const char * F_45 ( int V_135 )
{
return V_135 ? L_16 : L_13 ;
}
static void F_46 ( struct V_2 * V_3 ,
const char * V_37 ,
struct V_136 * V_137 ,
int V_55 )
{
F_4 ( V_3 , L_91 , V_37 , V_55 ) ;
while ( V_55 -- ) {
F_4 ( V_3 , L_92 ,
V_137 -> V_41 ,
V_137 -> V_27 ,
V_137 -> V_28 ,
V_137 -> V_29 ,
V_137 -> V_138 , V_137 -> V_139 ,
F_42 ( V_137 -> V_133 ) ,
F_43 ( V_137 -> V_134 ) ,
F_44 ( V_137 -> V_34 ) ,
F_45 ( V_137 -> V_135 ) ,
V_137 -> V_46 != - 1 ? L_7 : L_13 ,
F_41 ( V_137 -> V_46 ) ,
F_10 ( V_137 -> V_33 ) ) ;
if ( V_137 -> V_37 )
F_4 ( V_3 , L_17 , V_137 -> V_37 ) ;
if ( V_137 -> V_38 != V_39 )
F_4 ( V_3 , L_19 , V_137 -> V_38 ) ;
F_4 ( V_3 , L_26 ) ;
V_137 ++ ;
}
}
static void F_47 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
struct V_140 * error ,
unsigned V_46 )
{
F_48 ( V_46 >= V_141 ) ;
F_4 ( V_3 , L_93 , F_41 ( V_46 ) ) ;
F_4 ( V_3 , L_94 , error -> V_50 [ V_46 ] ) ;
F_4 ( V_3 , L_95 , error -> V_142 [ V_46 ] ) ;
F_4 ( V_3 , L_96 , error -> V_143 [ V_46 ] ) ;
F_4 ( V_3 , L_97 , error -> V_144 [ V_46 ] ) ;
F_4 ( V_3 , L_98 , error -> V_145 [ V_46 ] ) ;
F_4 ( V_3 , L_99 , error -> V_146 [ V_46 ] ) ;
F_4 ( V_3 , L_100 , error -> V_147 [ V_46 ] ) ;
if ( V_46 == V_130 && F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_101 , error -> V_148 ) ;
if ( F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_102 , error -> V_149 [ V_46 ] ) ;
F_4 ( V_3 , L_103 , error -> V_150 [ V_46 ] ) ;
F_4 ( V_3 , L_104 , error -> V_151 [ V_46 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_105 , error -> V_152 [ V_46 ] ) ;
F_4 ( V_3 , L_106 , error -> V_153 [ V_46 ] ) ;
F_4 ( V_3 , L_107 ,
error -> V_154 [ V_46 ] [ 0 ] ,
error -> V_155 [ V_46 ] [ 0 ] ) ;
F_4 ( V_3 , L_108 ,
error -> V_154 [ V_46 ] [ 1 ] ,
error -> V_155 [ V_46 ] [ 1 ] ) ;
}
F_4 ( V_3 , L_109 , error -> V_96 [ V_46 ] ) ;
F_4 ( V_3 , L_110 , F_1 ( error -> V_156 [ V_46 ] ) ) ;
F_4 ( V_3 , L_111 , error -> V_157 [ V_46 ] ) ;
F_4 ( V_3 , L_112 , error -> V_158 [ V_46 ] ) ;
}
static int F_49 ( struct V_2 * V_3 , void * V_159 )
{
struct V_160 * V_161 = V_3 -> V_7 ;
struct V_8 * V_9 = V_161 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_140 * error = V_161 -> error ;
struct V_91 * V_46 ;
int V_94 , V_162 , V_163 , V_164 , V_165 ;
if ( ! error ) {
F_4 ( V_3 , L_113 ) ;
return 0 ;
}
F_4 ( V_3 , L_114 , error -> time . V_166 ,
error -> time . V_167 ) ;
F_4 ( V_3 , L_115 V_168 ) ;
F_4 ( V_3 , L_116 , V_9 -> V_169 ) ;
F_4 ( V_3 , L_117 , error -> V_170 ) ;
F_4 ( V_3 , L_118 , error -> V_171 ) ;
F_4 ( V_3 , L_119 , error -> V_172 ) ;
F_4 ( V_3 , L_120 , error -> V_173 ) ;
F_4 ( V_3 , L_121 , error -> V_174 ) ;
F_4 ( V_3 , L_122 , error -> V_175 ) ;
for ( V_94 = 0 ; V_94 < V_51 -> V_125 ; V_94 ++ )
F_4 ( V_3 , L_123 , V_94 , error -> V_176 [ V_94 ] ) ;
for ( V_94 = 0 ; V_94 < F_50 ( error -> V_177 ) ; V_94 ++ )
F_4 ( V_3 , L_124 , V_94 , error -> V_177 [ V_94 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_125 , error -> error ) ;
F_4 ( V_3 , L_126 , error -> V_178 ) ;
}
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_127 , error -> V_179 ) ;
F_26 (ring, dev_priv, i)
F_47 ( V_3 , V_9 , error , V_94 ) ;
if ( error -> V_180 )
F_46 ( V_3 , L_128 ,
error -> V_180 ,
error -> V_181 ) ;
if ( error -> V_182 )
F_46 ( V_3 , L_129 ,
error -> V_182 ,
error -> V_183 ) ;
for ( V_94 = 0 ; V_94 < F_50 ( error -> V_46 ) ; V_94 ++ ) {
struct V_184 * V_16 ;
if ( ( V_16 = error -> V_46 [ V_94 ] . V_185 ) ) {
F_4 ( V_3 , L_130 ,
V_51 -> V_46 [ V_94 ] . V_37 ,
V_16 -> V_41 ) ;
V_164 = 0 ;
for ( V_163 = 0 ; V_163 < V_16 -> V_186 ; V_163 ++ ) {
for ( V_165 = 0 ; V_165 < V_187 / 4 ; V_165 ++ ) {
F_4 ( V_3 , L_131 , V_164 , V_16 -> V_188 [ V_163 ] [ V_165 ] ) ;
V_164 += 4 ;
}
}
}
if ( error -> V_46 [ V_94 ] . V_189 ) {
F_4 ( V_3 , L_132 ,
V_51 -> V_46 [ V_94 ] . V_37 ,
error -> V_46 [ V_94 ] . V_189 ) ;
for ( V_162 = 0 ; V_162 < error -> V_46 [ V_94 ] . V_189 ; V_162 ++ ) {
F_4 ( V_3 , L_133 ,
error -> V_46 [ V_94 ] . V_190 [ V_162 ] . V_96 ,
error -> V_46 [ V_94 ] . V_190 [ V_162 ] . V_97 ,
error -> V_46 [ V_94 ] . V_190 [ V_162 ] . V_142 ) ;
}
}
if ( ( V_16 = error -> V_46 [ V_94 ] . V_191 ) ) {
F_4 ( V_3 , L_134 ,
V_51 -> V_46 [ V_94 ] . V_37 ,
V_16 -> V_41 ) ;
V_164 = 0 ;
for ( V_163 = 0 ; V_163 < V_16 -> V_186 ; V_163 ++ ) {
for ( V_165 = 0 ; V_165 < V_187 / 4 ; V_165 ++ ) {
F_4 ( V_3 , L_131 ,
V_164 ,
V_16 -> V_188 [ V_163 ] [ V_165 ] ) ;
V_164 += 4 ;
}
}
}
}
if ( error -> V_192 )
F_51 ( V_3 , error -> V_192 ) ;
if ( error -> V_193 )
F_52 ( V_3 , V_9 , error -> V_193 ) ;
return 0 ;
}
static T_7
F_53 ( struct V_194 * V_195 ,
const char T_8 * V_196 ,
T_4 V_197 ,
T_9 * V_198 )
{
struct V_2 * V_3 = V_195 -> V_199 ;
struct V_160 * V_161 = V_3 -> V_7 ;
struct V_8 * V_9 = V_161 -> V_9 ;
int V_56 ;
F_54 ( L_135 ) ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_55 ( V_9 ) ;
F_14 ( & V_9 -> V_57 ) ;
return V_197 ;
}
static int F_56 ( struct V_200 * V_200 , struct V_194 * V_194 )
{
struct V_8 * V_9 = V_200 -> V_201 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_160 * V_161 ;
unsigned long V_77 ;
V_161 = F_57 ( sizeof( * V_161 ) , V_202 ) ;
if ( ! V_161 )
return - V_203 ;
V_161 -> V_9 = V_9 ;
F_22 ( & V_51 -> V_204 , V_77 ) ;
V_161 -> error = V_51 -> V_205 ;
if ( V_161 -> error )
F_58 ( & V_161 -> error -> V_206 ) ;
F_24 ( & V_51 -> V_204 , V_77 ) ;
return F_59 ( V_194 , F_49 , V_161 ) ;
}
static int F_60 ( struct V_200 * V_200 , struct V_194 * V_194 )
{
struct V_2 * V_3 = V_194 -> V_199 ;
struct V_160 * V_161 = V_3 -> V_7 ;
if ( V_161 -> error )
F_61 ( & V_161 -> error -> V_206 , V_207 ) ;
F_62 ( V_161 ) ;
return F_63 ( V_200 , V_194 ) ;
}
static int F_64 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_10 V_208 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_208 = F_65 ( V_209 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_136 , ( V_208 >> 8 ) & 0x3f , ( V_208 & 0x3f ) ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
if ( F_67 ( V_9 ) ) {
T_10 V_210 = F_65 ( V_211 ) ;
T_10 V_212 = F_65 ( V_213 ) ;
F_4 ( V_3 , L_137 , ( V_210 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_138 , V_210 & 0x3f ) ;
F_4 ( V_3 , L_139 , ( V_212 & V_214 ) >>
V_215 ) ;
F_4 ( V_3 , L_140 ,
( V_212 & V_216 ) >> V_217 ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
T_5 V_218 = F_32 ( V_219 ) ;
T_5 V_220 = F_32 ( V_221 ) ;
T_5 V_222 = F_32 ( V_223 ) ;
T_5 V_224 ;
T_5 V_225 , V_226 , V_227 ;
T_5 V_228 , V_229 , V_230 ;
int V_231 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_68 ( V_51 ) ;
V_224 = F_32 ( V_232 ) ;
V_225 = F_32 ( V_233 ) ;
V_226 = F_32 ( V_234 ) ;
V_227 = F_32 ( V_235 ) ;
V_228 = F_32 ( V_236 ) ;
V_229 = F_32 ( V_237 ) ;
V_230 = F_32 ( V_238 ) ;
F_69 ( V_51 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_141 , V_218 ) ;
F_4 ( V_3 , L_142 , V_224 ) ;
F_4 ( V_3 , L_143 ,
( V_218 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_144 ,
V_218 & 0xff ) ;
F_4 ( V_3 , L_145 ,
V_220 & 0xff ) ;
F_4 ( V_3 , L_146 , ( ( V_224 & V_239 ) >>
V_240 ) * V_241 ) ;
F_4 ( V_3 , L_147 , V_225 &
V_242 ) ;
F_4 ( V_3 , L_148 , V_226 &
V_243 ) ;
F_4 ( V_3 , L_149 , V_227 &
V_243 ) ;
F_4 ( V_3 , L_150 , V_228 &
V_244 ) ;
F_4 ( V_3 , L_151 , V_229 &
V_243 ) ;
F_4 ( V_3 , L_152 , V_230 &
V_243 ) ;
V_231 = ( V_222 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_153 ,
V_231 * V_241 ) ;
V_231 = ( V_222 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_154 ,
V_231 * V_241 ) ;
V_231 = V_222 & 0xff ;
F_4 ( V_3 , L_155 ,
V_231 * V_241 ) ;
} else {
F_4 ( V_3 , L_156 ) ;
}
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_5 V_245 ;
int V_56 , V_94 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
for ( V_94 = 0 ; V_94 < 16 ; V_94 ++ ) {
V_245 = F_32 ( V_246 + V_94 * 4 ) ;
F_4 ( V_3 , L_157 , V_94 , V_245 ,
( V_245 & V_247 ) >> V_248 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static inline int F_71 ( int V_249 )
{
return 1250 - ( V_249 * 25 ) ;
}
static int F_72 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_5 V_250 ;
int V_56 , V_94 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
for ( V_94 = 1 ; V_94 <= 32 ; V_94 ++ ) {
V_250 = F_32 ( V_251 + V_94 * 4 ) ;
F_4 ( V_3 , L_158 , V_94 , V_250 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
T_5 V_252 , V_253 ;
T_10 V_254 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_252 = F_32 ( V_255 ) ;
V_253 = F_32 ( V_256 ) ;
V_254 = F_65 ( V_209 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_159 , ( V_252 & V_257 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_160 ,
( V_252 & V_258 ) >>
V_259 ) ;
F_4 ( V_3 , L_161 ,
V_252 & V_260 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_162 ,
V_252 & V_261 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_163 ,
V_252 & V_262 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_164 ,
( V_252 & V_263 ) >> V_264 ) ;
F_4 ( V_3 , L_165 ,
( V_252 & V_265 ) >> V_266 ) ;
F_4 ( V_3 , L_166 , ( V_252 & V_267 ) ) ;
F_4 ( V_3 , L_167 , ( V_254 & 0x3f ) ) ;
F_4 ( V_3 , L_168 , ( ( V_254 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_169 ,
( V_253 & V_268 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_170 ) ;
switch ( V_253 & V_269 ) {
case V_270 :
F_4 ( V_3 , L_171 ) ;
break;
case V_271 :
F_4 ( V_3 , L_172 ) ;
break;
case V_272 :
F_4 ( V_3 , L_173 ) ;
break;
case V_273 :
F_4 ( V_3 , L_174 ) ;
break;
case V_274 :
F_4 ( V_3 , L_175 ) ;
break;
case V_275 :
F_4 ( V_3 , L_176 ) ;
break;
default:
F_4 ( V_3 , L_177 ) ;
break;
}
return 0 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
T_5 V_276 , V_277 , V_278 , V_279 = 0 ;
unsigned V_280 ;
int V_55 = 0 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_75 ( & V_51 -> V_281 ) ;
V_280 = V_51 -> V_280 ;
F_76 ( & V_51 -> V_281 ) ;
if ( V_280 ) {
F_4 ( V_3 , L_178
L_179 ) ;
} else {
while ( V_55 ++ < 50 && ( F_77 ( V_282 ) & 1 ) )
F_78 ( 10 ) ;
F_4 ( V_3 , L_180 , F_1 ( V_55 < 51 ) ) ;
}
V_277 = F_79 ( V_51 -> V_283 + V_284 ) ;
F_80 ( false , V_284 , V_277 , 4 ) ;
V_276 = F_32 ( V_285 ) ;
V_278 = F_32 ( V_286 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_81 ( & V_51 -> V_287 . V_288 ) ;
F_82 ( V_51 , V_289 , & V_279 ) ;
F_14 ( & V_51 -> V_287 . V_288 ) ;
F_4 ( V_3 , L_181 ,
F_1 ( V_276 & V_290 ) ) ;
F_4 ( V_3 , L_161 ,
F_1 ( V_276 & V_291 ) ) ;
F_4 ( V_3 , L_162 ,
F_1 ( ( V_276 & V_292 ) ==
V_293 ) ) ;
F_4 ( V_3 , L_182 ,
F_1 ( V_278 & V_294 ) ) ;
F_4 ( V_3 , L_183 ,
F_1 ( V_278 & V_295 ) ) ;
F_4 ( V_3 , L_184 ,
F_1 ( V_278 & V_296 ) ) ;
F_4 ( V_3 , L_185 ,
F_1 ( V_278 & V_297 ) ) ;
F_4 ( V_3 , L_186 ) ;
switch ( V_277 & V_298 ) {
case V_299 :
if ( V_277 & V_300 )
F_4 ( V_3 , L_187 ) ;
else
F_4 ( V_3 , L_171 ) ;
break;
case V_301 :
F_4 ( V_3 , L_188 ) ;
break;
case V_302 :
F_4 ( V_3 , L_189 ) ;
break;
case V_303 :
F_4 ( V_3 , L_190 ) ;
break;
default:
F_4 ( V_3 , L_191 ) ;
break;
}
F_4 ( V_3 , L_192 ,
F_1 ( V_277 & V_300 ) ) ;
F_4 ( V_3 , L_193 ,
F_32 ( V_304 ) ) ;
F_4 ( V_3 , L_194 ,
F_32 ( V_305 ) ) ;
F_4 ( V_3 , L_195 ,
F_32 ( V_306 ) ) ;
F_4 ( V_3 , L_196 ,
F_32 ( V_307 ) ) ;
F_4 ( V_3 , L_197 ,
F_83 ( ( ( V_279 >> 0 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_198 ,
F_83 ( ( ( V_279 >> 8 ) & 0xff ) ) ) ;
F_4 ( V_3 , L_199 ,
F_83 ( ( ( V_279 >> 16 ) & 0xff ) ) ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_36 ( V_9 ) || F_37 ( V_9 ) )
return F_74 ( V_3 ) ;
else
return F_73 ( V_3 ) ;
}
static int F_85 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
if ( ! F_86 ( V_9 ) ) {
F_4 ( V_3 , L_200 ) ;
return 0 ;
}
if ( F_87 ( V_9 ) ) {
F_4 ( V_3 , L_201 ) ;
} else {
F_4 ( V_3 , L_202 ) ;
switch ( V_51 -> V_308 ) {
case V_309 :
F_4 ( V_3 , L_203 ) ;
break;
case V_310 :
F_4 ( V_3 , L_204 ) ;
break;
case V_311 :
F_4 ( V_3 , L_205 ) ;
break;
case V_312 :
F_4 ( V_3 , L_206 ) ;
break;
case V_313 :
F_4 ( V_3 , L_207 ) ;
break;
case V_314 :
F_4 ( V_3 , L_208 ) ;
break;
case V_315 :
F_4 ( V_3 , L_209 ) ;
break;
case V_316 :
F_4 ( V_3 , L_210 ) ;
break;
default:
F_4 ( V_3 , L_211 ) ;
}
F_4 ( V_3 , L_26 ) ;
}
return 0 ;
}
static int F_88 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
bool V_317 = false ;
if ( F_35 ( V_9 ) )
V_317 = F_32 ( V_318 ) & V_319 ;
else if ( F_89 ( V_9 ) || F_90 ( V_9 ) || F_91 ( V_9 ) )
V_317 = F_32 ( V_320 ) & V_321 ;
else if ( F_92 ( V_9 ) )
V_317 = F_32 ( V_322 ) & V_323 ;
else if ( F_93 ( V_9 ) )
V_317 = F_32 ( V_324 ) & V_325 ;
F_4 ( V_3 , L_212 ,
V_317 ? L_213 : L_214 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
unsigned long V_326 , V_327 , V_328 ;
int V_56 ;
if ( ! F_67 ( V_9 ) )
return - V_329 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_326 = F_95 ( V_51 ) ;
V_327 = F_96 ( V_51 ) ;
V_328 = F_97 ( V_51 ) ;
F_14 ( & V_9 -> V_57 ) ;
F_4 ( V_3 , L_215 , V_326 ) ;
F_4 ( V_3 , L_216 , V_327 ) ;
F_4 ( V_3 , L_217 , V_328 ) ;
F_4 ( V_3 , L_218 , V_327 + V_328 ) ;
return 0 ;
}
static int F_98 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
int V_330 , V_331 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) ) {
F_4 ( V_3 , L_219 ) ;
return 0 ;
}
V_56 = F_13 ( & V_51 -> V_287 . V_288 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_220 ) ;
for ( V_330 = V_51 -> V_287 . V_332 ;
V_330 <= V_51 -> V_287 . V_333 ;
V_330 ++ ) {
V_331 = V_330 ;
F_82 ( V_51 ,
V_334 ,
& V_331 ) ;
F_4 ( V_3 , L_221 , V_330 * V_241 , V_331 * 100 ) ;
}
F_14 ( & V_51 -> V_287 . V_288 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_222 , ( unsigned long ) F_32 ( 0x112f4 ) ) ;
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_335 * V_336 = & V_51 -> V_336 ;
void * V_4 = F_101 ( V_337 , V_202 ) ;
int V_56 ;
if ( V_4 == NULL )
return - V_203 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
goto V_338;
if ( V_336 -> V_339 ) {
F_102 ( V_4 , V_336 -> V_339 , V_337 ) ;
F_103 ( V_3 , V_4 , V_337 ) ;
}
F_14 ( & V_9 -> V_57 ) ;
V_338:
F_62 ( V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
struct V_340 * V_341 ;
struct V_342 * V_343 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_344 . V_345 ) ;
if ( V_56 )
return V_56 ;
V_341 = V_51 -> V_346 ;
V_343 = F_105 ( V_341 -> V_347 . V_343 ) ;
F_4 ( V_3 , L_223 ,
V_343 -> V_26 . V_348 ,
V_343 -> V_26 . V_349 ,
V_343 -> V_26 . V_350 ,
V_343 -> V_26 . V_351 ) ;
F_11 ( V_3 , V_343 -> V_16 ) ;
F_4 ( V_3 , L_26 ) ;
F_15 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_343 -> V_26 == V_341 -> V_347 . V_343 )
continue;
F_4 ( V_3 , L_224 ,
V_343 -> V_26 . V_348 ,
V_343 -> V_26 . V_349 ,
V_343 -> V_26 . V_350 ,
V_343 -> V_26 . V_351 ) ;
F_11 ( V_3 , V_343 -> V_16 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_14 ( & V_9 -> V_344 . V_345 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 , void * V_159 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_51 = V_9 -> V_52 ;
int V_56 ;
V_56 = F_13 ( & V_9 -> V_344 . V_345 ) ;
if ( V_56 )
return V_56 ;
if ( V_51 -> V_352 . V_353 ) {
F_4 ( V_3 , L_225 ) ;
F_11 ( V_3 , V_51 -> V_352 . V_353 ) ;
F_4 ( V_3 , L_26 ) ;
}
if ( V_51 -> V_352 . V_354 ) {
F_4 ( V_3 , L_226 ) ;
F_11 ( V_3 , V_51 -> V_352 . V_354 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_14 ( & V_9 -> V_344 . V_345 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
unsigned V_280 ;
F_75 ( & V_51 -> V_281 ) ;
V_280 = V_51 -> V_280 ;
F_76 ( & V_51 -> V_281 ) ;
F_4 ( V_3 , L_227 , V_280 ) ;
return 0 ;
}
static const char * F_108 ( unsigned V_355 )
{
switch( V_355 ) {
case V_356 :
return L_228 ;
case V_357 :
return L_229 ;
case V_358 :
return L_230 ;
case V_359 :
return L_231 ;
case V_360 :
return L_232 ;
case V_361 :
return L_233 ;
case V_362 :
return L_234 ;
case V_363 :
return L_235 ;
}
return L_236 ;
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
F_4 ( V_3 , L_237 ,
F_108 ( V_51 -> V_59 . V_364 ) ) ;
F_4 ( V_3 , L_238 ,
F_108 ( V_51 -> V_59 . V_365 ) ) ;
if ( F_110 ( V_9 ) || F_111 ( V_9 ) ) {
F_4 ( V_3 , L_239 ,
F_32 ( V_366 ) ) ;
F_4 ( V_3 , L_240 ,
F_65 ( V_367 ) ) ;
F_4 ( V_3 , L_241 ,
F_65 ( V_368 ) ) ;
} else if ( F_36 ( V_9 ) || F_37 ( V_9 ) ) {
F_4 ( V_3 , L_242 ,
F_32 ( V_369 ) ) ;
F_4 ( V_3 , L_243 ,
F_32 ( V_370 ) ) ;
F_4 ( V_3 , L_244 ,
F_32 ( V_371 ) ) ;
F_4 ( V_3 , L_245 ,
F_32 ( V_372 ) ) ;
F_4 ( V_3 , L_246 ,
F_32 ( V_373 ) ) ;
F_4 ( V_3 , L_247 ,
F_32 ( V_374 ) ) ;
}
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
struct V_91 * V_46 ;
int V_94 , V_56 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
if ( F_3 ( V_9 ) -> V_13 == 6 )
F_4 ( V_3 , L_248 , F_32 ( V_375 ) ) ;
F_26 (ring, dev_priv, i) {
F_4 ( V_3 , L_249 , V_46 -> V_37 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_248 , F_32 ( F_113 ( V_46 ) ) ) ;
F_4 ( V_3 , L_250 , F_32 ( F_114 ( V_46 ) ) ) ;
F_4 ( V_3 , L_251 , F_32 ( F_115 ( V_46 ) ) ) ;
F_4 ( V_3 , L_252 , F_32 ( F_116 ( V_46 ) ) ) ;
}
if ( V_51 -> V_59 . V_376 ) {
struct V_377 * V_378 = V_51 -> V_59 . V_376 ;
F_4 ( V_3 , L_253 ) ;
F_4 ( V_3 , L_254 , V_378 -> V_379 ) ;
}
F_4 ( V_3 , L_255 , F_32 ( V_380 ) ) ;
F_14 ( & V_9 -> V_57 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_64 * V_51 = V_9 -> V_52 ;
int V_56 ;
if ( ! F_31 ( V_9 ) ) {
F_4 ( V_3 , L_256 ) ;
return 0 ;
}
V_56 = F_13 ( & V_9 -> V_344 . V_345 ) ;
if ( V_56 )
return V_56 ;
F_4 ( V_3 , L_257 , F_32 ( V_381 ) ) ;
F_4 ( V_3 , L_258 ,
F_118 ( V_51 , V_382 ) ) ;
F_4 ( V_3 , L_259 ,
F_118 ( V_51 , V_383 ) ) ;
F_4 ( V_3 , L_260 ,
F_118 ( V_51 , V_384 ) ) ;
F_4 ( V_3 , L_261 ,
F_118 ( V_51 , V_385 ) ) ;
F_4 ( V_3 , L_262 ,
F_118 ( V_51 , V_386 ) ) ;
F_4 ( V_3 , L_263 ,
F_118 ( V_51 , V_387 ) ) ;
F_4 ( V_3 , L_264 ,
F_118 ( V_51 , V_388 ) ) ;
F_4 ( V_3 , L_265 ,
F_118 ( V_51 , V_389 ) ) ;
F_4 ( V_3 , L_266 ,
F_118 ( V_51 , V_390 ) ) ;
F_14 ( & V_9 -> V_344 . V_345 ) ;
return 0 ;
}
static T_7
F_119 ( struct V_194 * V_195 ,
char T_8 * V_196 ,
T_4 V_391 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_392 [ 80 ] ;
int V_393 ;
V_393 = snprintf ( V_392 , sizeof( V_392 ) ,
L_267 ,
F_23 ( & V_51 -> V_59 . V_394 ) ) ;
if ( V_393 > sizeof( V_392 ) )
V_393 = sizeof( V_392 ) ;
return F_120 ( V_196 , V_391 , V_198 , V_392 , V_393 ) ;
}
static T_7
F_121 ( struct V_194 * V_195 ,
const char T_8 * V_196 ,
T_4 V_197 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
char V_392 [ 20 ] ;
int V_395 = 1 ;
if ( V_197 > 0 ) {
if ( V_197 > sizeof( V_392 ) - 1 )
return - V_63 ;
if ( F_122 ( V_392 , V_196 , V_197 ) )
return - V_396 ;
V_392 [ V_197 ] = 0 ;
V_395 = F_123 ( V_392 , NULL , 0 ) ;
}
F_124 ( L_268 , V_395 ) ;
F_125 ( V_9 , V_395 ) ;
return V_197 ;
}
static T_7
F_126 ( struct V_194 * V_195 ,
char T_8 * V_196 ,
T_4 V_391 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_392 [ 20 ] ;
int V_393 ;
V_393 = snprintf ( V_392 , sizeof( V_392 ) ,
L_269 , V_51 -> V_397 ) ;
if ( V_393 > sizeof( V_392 ) )
V_393 = sizeof( V_392 ) ;
return F_120 ( V_196 , V_391 , V_198 , V_392 , V_393 ) ;
}
static T_7
F_127 ( struct V_194 * V_195 ,
const char T_8 * V_196 ,
T_4 V_197 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_392 [ 20 ] ;
int V_395 = 0 , V_56 ;
if ( V_197 > 0 ) {
if ( V_197 > sizeof( V_392 ) - 1 )
return - V_63 ;
if ( F_122 ( V_392 , V_196 , V_197 ) )
return - V_396 ;
V_392 [ V_197 ] = 0 ;
V_395 = F_123 ( V_392 , NULL , 0 ) ;
}
F_54 ( L_270 , V_395 ) ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_51 -> V_397 = V_395 ;
F_14 ( & V_9 -> V_57 ) ;
return V_197 ;
}
static T_7
F_128 ( struct V_194 * V_195 ,
char T_8 * V_196 ,
T_4 V_391 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_392 [ 80 ] ;
int V_393 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_329 ;
V_56 = F_13 ( & V_51 -> V_287 . V_288 ) ;
if ( V_56 )
return V_56 ;
V_393 = snprintf ( V_392 , sizeof( V_392 ) ,
L_271 , V_51 -> V_287 . V_333 * V_241 ) ;
F_14 ( & V_51 -> V_287 . V_288 ) ;
if ( V_393 > sizeof( V_392 ) )
V_393 = sizeof( V_392 ) ;
return F_120 ( V_196 , V_391 , V_198 , V_392 , V_393 ) ;
}
static T_7
F_129 ( struct V_194 * V_195 ,
const char T_8 * V_196 ,
T_4 V_197 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_392 [ 20 ] ;
int V_395 = 1 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_329 ;
if ( V_197 > 0 ) {
if ( V_197 > sizeof( V_392 ) - 1 )
return - V_63 ;
if ( F_122 ( V_392 , V_196 , V_197 ) )
return - V_396 ;
V_392 [ V_197 ] = 0 ;
V_395 = F_123 ( V_392 , NULL , 0 ) ;
}
F_54 ( L_272 , V_395 ) ;
V_56 = F_13 ( & V_51 -> V_287 . V_288 ) ;
if ( V_56 )
return V_56 ;
V_51 -> V_287 . V_333 = V_395 / V_241 ;
F_130 ( V_9 , V_395 / V_241 ) ;
F_14 ( & V_51 -> V_287 . V_288 ) ;
return V_197 ;
}
static T_7
F_131 ( struct V_194 * V_195 , char T_8 * V_196 , T_4 V_391 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_392 [ 80 ] ;
int V_393 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_329 ;
V_56 = F_13 ( & V_51 -> V_287 . V_288 ) ;
if ( V_56 )
return V_56 ;
V_393 = snprintf ( V_392 , sizeof( V_392 ) ,
L_273 , V_51 -> V_287 . V_332 * V_241 ) ;
F_14 ( & V_51 -> V_287 . V_288 ) ;
if ( V_393 > sizeof( V_392 ) )
V_393 = sizeof( V_392 ) ;
return F_120 ( V_196 , V_391 , V_198 , V_392 , V_393 ) ;
}
static T_7
F_132 ( struct V_194 * V_195 , const char T_8 * V_196 , T_4 V_197 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_392 [ 20 ] ;
int V_395 = 1 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_329 ;
if ( V_197 > 0 ) {
if ( V_197 > sizeof( V_392 ) - 1 )
return - V_63 ;
if ( F_122 ( V_392 , V_196 , V_197 ) )
return - V_396 ;
V_392 [ V_197 ] = 0 ;
V_395 = F_123 ( V_392 , NULL , 0 ) ;
}
F_54 ( L_274 , V_395 ) ;
V_56 = F_13 ( & V_51 -> V_287 . V_288 ) ;
if ( V_56 )
return V_56 ;
V_51 -> V_287 . V_332 = V_395 / V_241 ;
F_130 ( V_9 , V_395 / V_241 ) ;
F_14 ( & V_51 -> V_287 . V_288 ) ;
return V_197 ;
}
static T_7
F_133 ( struct V_194 * V_195 ,
char T_8 * V_196 ,
T_4 V_391 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
T_3 * V_51 = V_9 -> V_52 ;
char V_392 [ 80 ] ;
T_5 V_398 ;
int V_393 , V_56 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_329 ;
V_56 = F_13 ( & V_9 -> V_57 ) ;
if ( V_56 )
return V_56 ;
V_398 = F_32 ( V_399 ) ;
F_14 ( & V_51 -> V_9 -> V_57 ) ;
V_393 = snprintf ( V_392 , sizeof( V_392 ) ,
L_275 , ( V_398 & V_400 ) >>
V_401 ) ;
if ( V_393 > sizeof( V_392 ) )
V_393 = sizeof( V_392 ) ;
return F_120 ( V_196 , V_391 , V_198 , V_392 , V_393 ) ;
}
static T_7
F_134 ( struct V_194 * V_195 ,
const char T_8 * V_196 ,
T_4 V_197 ,
T_9 * V_198 )
{
struct V_8 * V_9 = V_195 -> V_199 ;
struct V_64 * V_51 = V_9 -> V_52 ;
char V_392 [ 20 ] ;
T_5 V_398 ;
int V_395 = 1 ;
if ( ! ( F_36 ( V_9 ) || F_37 ( V_9 ) ) )
return - V_329 ;
if ( V_197 > 0 ) {
if ( V_197 > sizeof( V_392 ) - 1 )
return - V_63 ;
if ( F_122 ( V_392 , V_196 , V_197 ) )
return - V_396 ;
V_392 [ V_197 ] = 0 ;
V_395 = F_123 ( V_392 , NULL , 0 ) ;
}
if ( V_395 < 0 || V_395 > 3 )
return - V_63 ;
F_54 ( L_276 , V_395 ) ;
V_398 = F_32 ( V_399 ) ;
V_398 &= ~ V_400 ;
V_398 |= ( V_395 << V_401 ) ;
F_135 ( V_399 , V_398 ) ;
return V_197 ;
}
static int
F_136 ( struct V_402 * V_10 ,
struct V_403 * V_404 ,
const void * V_405 )
{
struct V_5 * V_6 ;
V_6 = F_101 ( sizeof( struct V_5 ) , V_202 ) ;
if ( V_6 == NULL ) {
F_137 ( V_404 ) ;
return - V_203 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_406 = V_404 ;
V_6 -> V_48 = ( void * ) V_405 ;
F_81 ( & V_10 -> V_407 ) ;
F_138 ( & V_6 -> V_47 , & V_10 -> V_408 ) ;
F_14 ( & V_10 -> V_407 ) ;
return 0 ;
}
static int F_139 ( struct V_200 * V_200 , struct V_194 * V_194 )
{
struct V_8 * V_9 = V_200 -> V_201 ;
struct V_64 * V_51 = V_9 -> V_52 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_68 ( V_51 ) ;
return 0 ;
}
static int F_140 ( struct V_200 * V_200 , struct V_194 * V_194 )
{
struct V_8 * V_9 = V_200 -> V_201 ;
struct V_64 * V_51 = V_9 -> V_52 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_69 ( V_51 ) ;
return 0 ;
}
static int F_141 ( struct V_403 * V_409 , struct V_402 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_403 * V_404 ;
V_404 = F_142 ( L_277 ,
V_410 ,
V_409 , V_9 ,
& V_411 ) ;
if ( F_143 ( V_404 ) )
return F_144 ( V_404 ) ;
return F_136 ( V_10 , V_404 , & V_411 ) ;
}
static int F_145 ( struct V_403 * V_409 ,
struct V_402 * V_10 ,
const char * V_37 ,
const struct V_412 * V_413 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_403 * V_404 ;
V_404 = F_142 ( V_37 ,
V_414 | V_415 ,
V_409 , V_9 ,
V_413 ) ;
if ( F_143 ( V_404 ) )
return F_144 ( V_404 ) ;
return F_136 ( V_10 , V_404 , V_413 ) ;
}
int F_146 ( struct V_402 * V_10 )
{
int V_56 ;
V_56 = F_145 ( V_10 -> V_416 , V_10 ,
L_278 ,
& V_417 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_141 ( V_10 -> V_416 , V_10 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_416 , V_10 ,
L_279 ,
& V_418 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_416 , V_10 ,
L_280 ,
& V_419 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_416 , V_10 ,
L_281 ,
& V_420 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_416 , V_10 ,
L_282 ,
& V_421 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_145 ( V_10 -> V_416 , V_10 ,
L_283 ,
& V_422 ) ;
if ( V_56 )
return V_56 ;
return F_147 ( V_423 ,
V_424 ,
V_10 -> V_416 , V_10 ) ;
}
void F_148 ( struct V_402 * V_10 )
{
F_149 ( V_423 ,
V_424 , V_10 ) ;
F_149 ( (struct V_425 * ) & V_411 ,
1 , V_10 ) ;
F_149 ( (struct V_425 * ) & V_417 ,
1 , V_10 ) ;
F_149 ( (struct V_425 * ) & V_418 ,
1 , V_10 ) ;
F_149 ( (struct V_425 * ) & V_419 ,
1 , V_10 ) ;
F_149 ( (struct V_425 * ) & V_420 ,
1 , V_10 ) ;
F_149 ( (struct V_425 * ) & V_421 ,
1 , V_10 ) ;
F_149 ( (struct V_425 * ) & V_422 ,
1 , V_10 ) ;
}
