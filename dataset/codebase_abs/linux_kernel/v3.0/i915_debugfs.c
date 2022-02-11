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
#define F_5 ( T_1 ) seq_printf(m, #x ": %s\n", yesno(info->x))
F_5 ( V_14 ) ;
F_5 ( V_15 ) ;
F_5 ( V_16 ) ;
F_5 ( V_17 ) ;
F_5 ( V_18 ) ;
F_5 ( V_19 ) ;
F_5 ( V_20 ) ;
F_5 ( V_21 ) ;
F_5 ( V_22 ) ;
F_5 ( V_23 ) ;
F_5 ( V_24 ) ;
F_5 ( V_25 ) ;
F_5 ( V_26 ) ;
F_5 ( V_27 ) ;
F_5 ( V_28 ) ;
F_5 ( V_29 ) ;
F_5 ( V_30 ) ;
F_5 ( V_31 ) ;
F_5 ( V_32 ) ;
#undef F_5
return 0 ;
}
static const char * F_6 ( struct V_33 * V_34 )
{
if ( V_34 -> V_35 > 0 )
return L_4 ;
else if ( V_34 -> V_36 > 0 )
return L_5 ;
else
return L_6 ;
}
static const char * F_7 ( struct V_33 * V_34 )
{
switch ( V_34 -> V_37 ) {
default:
case V_38 : return L_6 ;
case V_39 : return L_7 ;
case V_40 : return L_8 ;
}
}
static const char * F_8 ( int type )
{
switch ( type ) {
case V_41 : return L_9 ;
case V_42 : return L_10 ;
case V_43 : return L_11 ;
default: return L_12 ;
}
}
static void
F_9 ( struct V_2 * V_3 , struct V_33 * V_34 )
{
F_4 ( V_3 , L_13 ,
& V_34 -> V_44 ,
F_6 ( V_34 ) ,
F_7 ( V_34 ) ,
V_34 -> V_44 . V_45 ,
V_34 -> V_44 . V_46 ,
V_34 -> V_44 . V_47 ,
V_34 -> V_48 ,
V_34 -> V_49 ,
F_8 ( V_34 -> V_50 ) ,
V_34 -> V_51 ? L_14 : L_12 ,
V_34 -> V_52 == V_53 ? L_15 : L_12 ) ;
if ( V_34 -> V_44 . V_54 )
F_4 ( V_3 , L_16 , V_34 -> V_44 . V_54 ) ;
if ( V_34 -> V_55 != V_56 )
F_4 ( V_3 , L_17 , V_34 -> V_55 ) ;
if ( V_34 -> V_57 != NULL )
F_4 ( V_3 , L_18 ,
V_34 -> V_58 , ( unsigned int ) V_34 -> V_57 -> V_45 ) ;
if ( V_34 -> V_59 || V_34 -> V_60 ) {
char V_61 [ 3 ] , * V_62 = V_61 ;
if ( V_34 -> V_59 )
* V_62 ++ = 'p' ;
if ( V_34 -> V_60 )
* V_62 ++ = 'f' ;
* V_62 = '\0' ;
F_4 ( V_3 , L_19 , V_61 ) ;
}
if ( V_34 -> V_63 != NULL )
F_4 ( V_3 , L_20 , V_34 -> V_63 -> V_54 ) ;
}
static int F_10 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_64 = ( T_2 ) V_6 -> V_65 -> V_4 ;
struct V_66 * V_67 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_33 * V_34 ;
T_4 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
switch ( V_64 ) {
case V_75 :
F_4 ( V_3 , L_21 ) ;
V_67 = & V_68 -> V_76 . V_77 ;
break;
case V_78 :
F_4 ( V_3 , L_22 ) ;
V_67 = & V_68 -> V_76 . V_79 ;
break;
case V_80 :
F_4 ( V_3 , L_23 ) ;
V_67 = & V_68 -> V_76 . V_81 ;
break;
case V_82 :
F_4 ( V_3 , L_24 ) ;
V_67 = & V_68 -> V_76 . V_83 ;
break;
case V_84 :
F_4 ( V_3 , L_25 ) ;
V_67 = & V_68 -> V_76 . V_85 ;
break;
default:
F_12 ( & V_9 -> V_74 ) ;
return - V_86 ;
}
V_70 = V_71 = V_72 = 0 ;
F_13 (obj, head, mm_list) {
F_4 ( V_3 , L_26 ) ;
F_9 ( V_3 , V_34 ) ;
F_4 ( V_3 , L_27 ) ;
V_70 += V_34 -> V_44 . V_45 ;
V_71 += V_34 -> V_57 -> V_45 ;
V_72 ++ ;
}
F_12 ( & V_9 -> V_74 ) ;
F_4 ( V_3 , L_28 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_87 * V_68 = V_9 -> V_69 ;
T_5 V_72 , V_88 ;
T_4 V_45 , V_89 ;
struct V_33 * V_34 ;
int V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_4 ( V_3 , L_29 ,
V_68 -> V_76 . V_90 ,
V_68 -> V_76 . V_91 ) ;
V_45 = V_72 = V_89 = V_88 = 0 ;
F_15 ( & V_68 -> V_76 . V_92 , V_92 ) ;
F_4 ( V_3 , L_30 ,
V_72 , V_88 , V_45 , V_89 ) ;
V_45 = V_72 = V_89 = V_88 = 0 ;
F_15 ( & V_68 -> V_76 . V_77 , V_93 ) ;
F_15 ( & V_68 -> V_76 . V_83 , V_93 ) ;
F_4 ( V_3 , L_31 ,
V_72 , V_88 , V_45 , V_89 ) ;
V_45 = V_72 = V_89 = V_88 = 0 ;
F_15 ( & V_68 -> V_76 . V_81 , V_93 ) ;
F_4 ( V_3 , L_32 ,
V_72 , V_88 , V_45 , V_89 ) ;
V_45 = V_72 = V_89 = V_88 = 0 ;
F_15 ( & V_68 -> V_76 . V_79 , V_93 ) ;
F_4 ( V_3 , L_33 ,
V_72 , V_88 , V_45 , V_89 ) ;
V_45 = V_72 = V_89 = V_88 = 0 ;
F_15 ( & V_68 -> V_76 . V_85 , V_93 ) ;
F_4 ( V_3 , L_34 ,
V_72 , V_88 , V_45 , V_89 ) ;
V_45 = V_72 = V_89 = V_88 = 0 ;
F_13 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_34 -> V_60 ) {
V_45 += V_34 -> V_57 -> V_45 ;
++ V_72 ;
}
if ( V_34 -> V_59 ) {
V_89 += V_34 -> V_57 -> V_45 ;
++ V_88 ;
}
}
F_4 ( V_3 , L_35 ,
V_88 , V_89 ) ;
F_4 ( V_3 , L_36 ,
V_72 , V_45 ) ;
F_4 ( V_3 , L_37 ,
V_68 -> V_76 . V_94 , V_68 -> V_76 . V_95 ) ;
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_87 * V_68 = V_9 -> V_69 ;
struct V_33 * V_34 ;
T_4 V_70 , V_71 ;
int V_72 , V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_70 = V_71 = V_72 = 0 ;
F_13 (obj, &dev_priv->mm.gtt_list, gtt_list) {
F_4 ( V_3 , L_26 ) ;
F_9 ( V_3 , V_34 ) ;
F_4 ( V_3 , L_27 ) ;
V_70 += V_34 -> V_44 . V_45 ;
V_71 += V_34 -> V_57 -> V_45 ;
V_72 ++ ;
}
F_12 ( & V_9 -> V_74 ) ;
F_4 ( V_3 , L_28 ,
V_72 , V_70 , V_71 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
unsigned long V_96 ;
struct V_97 * V_98 ;
F_13 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_99 = F_18 ( V_98 -> V_99 ) ;
const char V_100 = F_19 ( V_98 -> V_100 ) ;
struct V_101 * V_102 ;
F_20 ( & V_9 -> V_103 , V_96 ) ;
V_102 = V_98 -> V_104 ;
if ( V_102 == NULL ) {
F_4 ( V_3 , L_38 ,
V_99 , V_100 ) ;
} else {
if ( ! V_102 -> V_105 ) {
F_4 ( V_3 , L_39 ,
V_99 , V_100 ) ;
} else {
F_4 ( V_3 , L_40 ,
V_99 , V_100 ) ;
}
if ( V_102 -> V_106 )
F_4 ( V_3 , L_41 ) ;
else
F_4 ( V_3 , L_42 ) ;
F_4 ( V_3 , L_43 , V_102 -> V_105 ) ;
if ( V_102 -> V_107 ) {
struct V_33 * V_34 = V_102 -> V_107 ;
if ( V_34 )
F_4 ( V_3 , L_44 , V_34 -> V_58 ) ;
}
if ( V_102 -> V_108 ) {
struct V_33 * V_34 = V_102 -> V_108 ;
if ( V_34 )
F_4 ( V_3 , L_45 , V_34 -> V_58 ) ;
}
}
F_21 ( & V_9 -> V_103 , V_96 ) ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_109 * V_110 ;
int V_73 , V_72 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_72 = 0 ;
if ( ! F_23 ( & V_68 -> V_63 [ V_111 ] . V_112 ) ) {
F_4 ( V_3 , L_46 ) ;
F_13 (gem_request,
&dev_priv->ring[RCS].request_list,
list) {
F_4 ( V_3 , L_47 ,
V_110 -> V_113 ,
( int ) ( V_114 - V_110 -> V_115 ) ) ;
}
V_72 ++ ;
}
if ( ! F_23 ( & V_68 -> V_63 [ V_116 ] . V_112 ) ) {
F_4 ( V_3 , L_48 ) ;
F_13 (gem_request,
&dev_priv->ring[VCS].request_list,
list) {
F_4 ( V_3 , L_47 ,
V_110 -> V_113 ,
( int ) ( V_114 - V_110 -> V_115 ) ) ;
}
V_72 ++ ;
}
if ( ! F_23 ( & V_68 -> V_63 [ V_117 ] . V_112 ) ) {
F_4 ( V_3 , L_49 ) ;
F_13 (gem_request,
&dev_priv->ring[BCS].request_list,
list) {
F_4 ( V_3 , L_47 ,
V_110 -> V_113 ,
( int ) ( V_114 - V_110 -> V_115 ) ) ;
}
V_72 ++ ;
}
F_12 ( & V_9 -> V_74 ) ;
if ( V_72 == 0 )
F_4 ( V_3 , L_50 ) ;
return 0 ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_118 * V_63 )
{
if ( V_63 -> V_119 ) {
F_4 ( V_3 , L_51 ,
V_63 -> V_54 , V_63 -> V_119 ( V_63 ) ) ;
F_4 ( V_3 , L_52 ,
V_63 -> V_54 , V_63 -> V_120 ) ;
F_4 ( V_3 , L_53 ,
V_63 -> V_54 , V_63 -> V_121 ) ;
}
}
static int F_25 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
int V_73 , V_122 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ )
F_24 ( V_3 , & V_68 -> V_63 [ V_122 ] ) ;
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
int V_73 , V_122 , V_99 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( ! F_27 ( V_9 ) ) {
F_4 ( V_3 , L_54 ,
F_28 ( V_124 ) ) ;
F_4 ( V_3 , L_55 ,
F_28 ( V_125 ) ) ;
F_4 ( V_3 , L_56 ,
F_28 ( V_126 ) ) ;
F_29 (pipe)
F_4 ( V_3 , L_57 ,
F_18 ( V_99 ) ,
F_28 ( F_30 ( V_99 ) ) ) ;
} else {
F_4 ( V_3 , L_58 ,
F_28 ( V_127 ) ) ;
F_4 ( V_3 , L_59 ,
F_28 ( V_128 ) ) ;
F_4 ( V_3 , L_60 ,
F_28 ( V_129 ) ) ;
F_4 ( V_3 , L_61 ,
F_28 ( V_130 ) ) ;
F_4 ( V_3 , L_62 ,
F_28 ( V_131 ) ) ;
F_4 ( V_3 , L_63 ,
F_28 ( V_132 ) ) ;
F_4 ( V_3 , L_64 ,
F_28 ( V_133 ) ) ;
F_4 ( V_3 , L_65 ,
F_28 ( V_134 ) ) ;
F_4 ( V_3 , L_66 ,
F_28 ( V_135 ) ) ;
}
F_4 ( V_3 , L_67 ,
F_31 ( & V_68 -> V_136 ) ) ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ ) {
if ( F_32 ( V_9 ) ) {
F_4 ( V_3 , L_68 ,
V_68 -> V_63 [ V_122 ] . V_54 ,
F_33 ( & V_68 -> V_63 [ V_122 ] ) ) ;
}
F_24 ( V_3 , & V_68 -> V_63 [ V_122 ] ) ;
}
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
int V_122 , V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_4 ( V_3 , L_69 , V_68 -> V_137 ) ;
F_4 ( V_3 , L_70 , V_68 -> V_138 ) ;
for ( V_122 = 0 ; V_122 < V_68 -> V_138 ; V_122 ++ ) {
struct V_33 * V_34 = V_68 -> V_139 [ V_122 ] . V_34 ;
F_4 ( V_3 , L_71 , V_122 ) ;
if ( V_34 == NULL )
F_4 ( V_3 , L_72 ) ;
else
F_9 ( V_3 , V_34 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_118 * V_63 ;
const volatile T_5 T_6 * V_140 ;
int V_122 ;
V_63 = & V_68 -> V_63 [ ( T_2 ) V_6 -> V_65 -> V_4 ] ;
V_140 = ( volatile T_5 T_6 * ) V_63 -> V_141 . V_142 ;
if ( V_140 == NULL )
return 0 ;
for ( V_122 = 0 ; V_122 < 4096 / sizeof( T_5 ) / 4 ; V_122 += 4 ) {
F_4 ( V_3 , L_73 ,
V_122 * 4 ,
V_140 [ V_122 ] , V_140 [ V_122 + 1 ] , V_140 [ V_122 + 2 ] , V_140 [ V_122 + 3 ] ) ;
}
return 0 ;
}
static void F_36 ( struct V_2 * V_3 ,
struct V_143 * V_144 ,
struct V_33 * V_34 )
{
int V_145 , V_146 , V_122 ;
V_146 = V_34 -> V_44 . V_45 / V_147 ;
for ( V_145 = 0 ; V_145 < V_146 ; V_145 ++ ) {
T_5 * V_148 = F_37 ( V_144 ,
V_34 -> V_58 + V_145 * V_147 ) ;
for ( V_122 = 0 ; V_122 < V_147 ; V_122 += 4 )
F_4 ( V_3 , L_74 , V_122 , V_148 [ V_122 / 4 ] ) ;
F_38 ( V_148 ) ;
}
}
static int F_39 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_33 * V_34 ;
int V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_13 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_34 -> V_44 . V_46 & V_149 ) {
F_4 ( V_3 , L_75 , V_34 -> V_58 ) ;
F_36 ( V_3 , V_68 -> V_76 . V_150 , V_34 ) ;
}
}
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_118 * V_63 ;
int V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_63 = & V_68 -> V_63 [ ( T_2 ) V_6 -> V_65 -> V_4 ] ;
if ( ! V_63 -> V_34 ) {
F_4 ( V_3 , L_76 ) ;
} else {
const T_7 T_6 * V_151 = V_63 -> V_152 ;
T_8 V_153 ;
for ( V_153 = 0 ; V_153 < V_63 -> V_45 ; V_153 += 4 ) {
T_8 * V_154 = ( T_8 * ) ( V_151 + V_153 ) ;
F_4 ( V_3 , L_74 , V_153 , * V_154 ) ;
}
}
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_118 * V_63 ;
V_63 = & V_68 -> V_63 [ ( T_2 ) V_6 -> V_65 -> V_4 ] ;
if ( V_63 -> V_45 == 0 )
return 0 ;
F_4 ( V_3 , L_77 , V_63 -> V_54 ) ;
F_4 ( V_3 , L_78 , F_42 ( V_63 ) & V_155 ) ;
F_4 ( V_3 , L_79 , F_43 ( V_63 ) & V_156 ) ;
F_4 ( V_3 , L_80 , V_63 -> V_45 ) ;
F_4 ( V_3 , L_81 , F_44 ( V_63 ) ) ;
F_4 ( V_3 , L_82 , F_45 ( V_63 ) ) ;
if ( F_32 ( V_9 ) ) {
F_4 ( V_3 , L_83 , F_46 ( V_63 ) ) ;
F_4 ( V_3 , L_84 , F_47 ( V_63 ) ) ;
}
F_4 ( V_3 , L_85 , F_48 ( V_63 ) ) ;
F_4 ( V_3 , L_86 , F_49 ( V_63 ) ) ;
return 0 ;
}
static const char * F_50 ( int V_63 )
{
switch ( V_63 ) {
case V_157 : return L_87 ;
case V_158 : return L_88 ;
case V_159 : return L_89 ;
default: return L_12 ;
}
}
static const char * F_51 ( int V_160 )
{
if ( V_160 > 0 )
return L_90 ;
else if ( V_160 < 0 )
return L_91 ;
else
return L_12 ;
}
static const char * F_52 ( int V_161 )
{
switch ( V_161 ) {
default:
case V_38 : return L_12 ;
case V_39 : return L_92 ;
case V_40 : return L_93 ;
}
}
static const char * F_53 ( int V_51 )
{
return V_51 ? L_14 : L_12 ;
}
static const char * F_54 ( int V_162 )
{
return V_162 ? L_15 : L_12 ;
}
static void F_55 ( struct V_2 * V_3 ,
const char * V_54 ,
struct V_163 * V_164 ,
int V_72 )
{
F_4 ( V_3 , L_94 , V_54 , V_72 ) ;
while ( V_72 -- ) {
F_4 ( V_3 , L_95 ,
V_164 -> V_58 ,
V_164 -> V_45 ,
V_164 -> V_46 ,
V_164 -> V_47 ,
V_164 -> V_113 ,
F_51 ( V_164 -> V_160 ) ,
F_52 ( V_164 -> V_161 ) ,
F_53 ( V_164 -> V_51 ) ,
F_54 ( V_164 -> V_162 ) ,
F_50 ( V_164 -> V_63 ) ,
F_8 ( V_164 -> V_50 ) ) ;
if ( V_164 -> V_54 )
F_4 ( V_3 , L_16 , V_164 -> V_54 ) ;
if ( V_164 -> V_55 != V_56 )
F_4 ( V_3 , L_17 , V_164 -> V_55 ) ;
F_4 ( V_3 , L_27 ) ;
V_164 ++ ;
}
}
static int F_56 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_166 * error ;
unsigned long V_96 ;
int V_122 , V_145 , V_167 , V_168 ;
F_20 ( & V_68 -> V_169 , V_96 ) ;
if ( ! V_68 -> V_170 ) {
F_4 ( V_3 , L_96 ) ;
goto V_171;
}
error = V_68 -> V_170 ;
F_4 ( V_3 , L_97 , error -> time . V_172 ,
error -> time . V_173 ) ;
F_4 ( V_3 , L_98 , V_9 -> V_174 ) ;
F_4 ( V_3 , L_99 , error -> V_175 ) ;
F_4 ( V_3 , L_100 , error -> V_176 ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_101 , error -> error ) ;
F_4 ( V_3 , L_102 ) ;
F_4 ( V_3 , L_103 , error -> V_177 ) ;
F_4 ( V_3 , L_104 , error -> V_178 ) ;
F_4 ( V_3 , L_105 , error -> V_179 ) ;
F_4 ( V_3 , L_106 , error -> V_180 ) ;
F_4 ( V_3 , L_107 , error -> V_181 ) ;
F_4 ( V_3 , L_108 ) ;
F_4 ( V_3 , L_103 , error -> V_182 ) ;
F_4 ( V_3 , L_104 , error -> V_183 ) ;
F_4 ( V_3 , L_105 , error -> V_184 ) ;
F_4 ( V_3 , L_106 , error -> V_185 ) ;
F_4 ( V_3 , L_107 , error -> V_186 ) ;
}
F_4 ( V_3 , L_109 ) ;
F_4 ( V_3 , L_110 , error -> V_187 ) ;
F_4 ( V_3 , L_111 , error -> V_188 ) ;
F_4 ( V_3 , L_112 , error -> V_189 ) ;
F_4 ( V_3 , L_106 , error -> V_190 ) ;
if ( F_3 ( V_9 ) -> V_13 >= 4 ) {
F_4 ( V_3 , L_113 , error -> V_191 ) ;
F_4 ( V_3 , L_114 , error -> V_192 ) ;
}
F_4 ( V_3 , L_115 , error -> V_193 ) ;
F_4 ( V_3 , L_116 , error -> V_113 ) ;
for ( V_122 = 0 ; V_122 < V_68 -> V_138 ; V_122 ++ )
F_4 ( V_3 , L_117 , V_122 , error -> V_194 [ V_122 ] ) ;
if ( error -> V_195 )
F_55 ( V_3 , L_118 ,
error -> V_195 ,
error -> V_196 ) ;
if ( error -> V_197 )
F_55 ( V_3 , L_119 ,
error -> V_197 ,
error -> V_198 ) ;
for ( V_122 = 0 ; V_122 < F_57 ( error -> V_199 ) ; V_122 ++ ) {
if ( error -> V_199 [ V_122 ] ) {
struct V_200 * V_34 = error -> V_199 [ V_122 ] ;
F_4 ( V_3 , L_120 ,
V_68 -> V_63 [ V_122 ] . V_54 ,
V_34 -> V_58 ) ;
V_167 = 0 ;
for ( V_145 = 0 ; V_145 < V_34 -> V_146 ; V_145 ++ ) {
for ( V_168 = 0 ; V_168 < V_147 / 4 ; V_168 ++ ) {
F_4 ( V_3 , L_74 , V_167 , V_34 -> V_201 [ V_145 ] [ V_168 ] ) ;
V_167 += 4 ;
}
}
}
}
for ( V_122 = 0 ; V_122 < F_57 ( error -> V_202 ) ; V_122 ++ ) {
if ( error -> V_202 [ V_122 ] ) {
struct V_200 * V_34 = error -> V_202 [ V_122 ] ;
F_4 ( V_3 , L_121 ,
V_68 -> V_63 [ V_122 ] . V_54 ,
V_34 -> V_58 ) ;
V_167 = 0 ;
for ( V_145 = 0 ; V_145 < V_34 -> V_146 ; V_145 ++ ) {
for ( V_168 = 0 ; V_168 < V_147 / 4 ; V_168 ++ ) {
F_4 ( V_3 , L_74 ,
V_167 ,
V_34 -> V_201 [ V_145 ] [ V_168 ] ) ;
V_167 += 4 ;
}
}
}
}
if ( error -> V_203 )
F_58 ( V_3 , error -> V_203 ) ;
if ( error -> V_204 )
F_59 ( V_3 , V_9 , error -> V_204 ) ;
V_171:
F_21 ( & V_68 -> V_169 , V_96 ) ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
T_9 V_205 = F_61 ( V_206 ) ;
F_4 ( V_3 , L_122 , ( V_205 >> 8 ) & 0x3f , ( V_205 & 0x3f ) ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
int V_73 ;
if ( F_63 ( V_9 ) ) {
T_9 V_207 = F_61 ( V_208 ) ;
T_9 V_209 = F_61 ( V_210 ) ;
F_4 ( V_3 , L_123 , ( V_207 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_124 , V_207 & 0x3f ) ;
F_4 ( V_3 , L_125 , ( V_209 & V_211 ) >>
V_212 ) ;
F_4 ( V_3 , L_126 ,
( V_209 & V_213 ) >> V_214 ) ;
} else if ( F_32 ( V_9 ) ) {
T_5 V_215 = F_28 ( V_216 ) ;
T_5 V_217 = F_28 ( V_218 ) ;
T_5 V_219 = F_28 ( V_220 ) ;
T_5 V_221 ;
T_5 V_222 , V_223 , V_224 ;
T_5 V_225 , V_226 , V_227 ;
int V_228 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_64 ( V_68 ) ;
V_221 = F_28 ( V_229 ) ;
V_222 = F_28 ( V_230 ) ;
V_223 = F_28 ( V_231 ) ;
V_224 = F_28 ( V_232 ) ;
V_225 = F_28 ( V_233 ) ;
V_226 = F_28 ( V_234 ) ;
V_227 = F_28 ( V_235 ) ;
F_65 ( V_68 ) ;
F_12 ( & V_9 -> V_74 ) ;
F_4 ( V_3 , L_127 , V_215 ) ;
F_4 ( V_3 , L_128 , V_221 ) ;
F_4 ( V_3 , L_129 ,
( V_215 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_130 ,
V_215 & 0xff ) ;
F_4 ( V_3 , L_131 ,
V_217 & 0xff ) ;
F_4 ( V_3 , L_132 , ( ( V_221 & V_236 ) >>
V_237 ) * 50 ) ;
F_4 ( V_3 , L_133 , V_222 &
V_238 ) ;
F_4 ( V_3 , L_134 , V_223 &
V_239 ) ;
F_4 ( V_3 , L_135 , V_224 &
V_239 ) ;
F_4 ( V_3 , L_136 , V_225 &
V_240 ) ;
F_4 ( V_3 , L_137 , V_226 &
V_239 ) ;
F_4 ( V_3 , L_138 , V_227 &
V_239 ) ;
V_228 = ( V_219 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_139 ,
V_228 * 50 ) ;
V_228 = ( V_219 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_140 ,
V_228 * 50 ) ;
V_228 = V_219 & 0xff ;
F_4 ( V_3 , L_141 ,
V_228 * 50 ) ;
} else {
F_4 ( V_3 , L_142 ) ;
}
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
T_5 V_241 ;
int V_122 ;
for ( V_122 = 0 ; V_122 < 16 ; V_122 ++ ) {
V_241 = F_28 ( V_242 + V_122 * 4 ) ;
F_4 ( V_3 , L_143 , V_122 , V_241 ,
( V_241 & V_243 ) >> V_244 ) ;
}
return 0 ;
}
static inline int F_67 ( int V_245 )
{
return 1250 - ( V_245 * 25 ) ;
}
static int F_68 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
T_5 V_246 ;
int V_122 ;
for ( V_122 = 1 ; V_122 <= 32 ; V_122 ++ ) {
V_246 = F_28 ( V_247 + V_122 * 4 ) ;
F_4 ( V_3 , L_144 , V_122 , V_246 ) ;
}
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
T_5 V_248 = F_28 ( V_249 ) ;
T_5 V_250 = F_28 ( V_251 ) ;
T_9 V_252 = F_61 ( V_206 ) ;
F_4 ( V_3 , L_145 , ( V_248 & V_253 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_146 ,
( V_248 & V_254 ) >>
V_255 ) ;
F_4 ( V_3 , L_147 ,
V_248 & V_256 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_148 ,
V_248 & V_257 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_149 ,
V_248 & V_258 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_150 ,
( V_248 & V_259 ) >> V_260 ) ;
F_4 ( V_3 , L_151 ,
( V_248 & V_261 ) >> V_262 ) ;
F_4 ( V_3 , L_152 , ( V_248 & V_263 ) ) ;
F_4 ( V_3 , L_153 , ( V_252 & 0x3f ) ) ;
F_4 ( V_3 , L_154 , ( ( V_252 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_155 ,
( V_250 & V_264 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_156 ) ;
switch ( V_250 & V_265 ) {
case V_266 :
F_4 ( V_3 , L_157 ) ;
break;
case V_267 :
F_4 ( V_3 , L_158 ) ;
break;
case V_268 :
F_4 ( V_3 , L_159 ) ;
break;
case V_269 :
F_4 ( V_3 , L_160 ) ;
break;
case V_270 :
F_4 ( V_3 , L_161 ) ;
break;
case V_271 :
F_4 ( V_3 , L_162 ) ;
break;
default:
F_4 ( V_3 , L_163 ) ;
break;
}
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
if ( ! F_71 ( V_9 ) ) {
F_4 ( V_3 , L_164 ) ;
return 0 ;
}
if ( F_72 ( V_9 ) ) {
F_4 ( V_3 , L_165 ) ;
} else {
F_4 ( V_3 , L_166 ) ;
switch ( V_68 -> V_272 ) {
case V_273 :
F_4 ( V_3 , L_167 ) ;
break;
case V_274 :
F_4 ( V_3 , L_168 ) ;
break;
case V_275 :
F_4 ( V_3 , L_169 ) ;
break;
case V_276 :
F_4 ( V_3 , L_170 ) ;
break;
case V_277 :
F_4 ( V_3 , L_171 ) ;
break;
case V_278 :
F_4 ( V_3 , L_172 ) ;
break;
case V_279 :
F_4 ( V_3 , L_173 ) ;
break;
case V_280 :
F_4 ( V_3 , L_174 ) ;
break;
default:
F_4 ( V_3 , L_175 ) ;
}
F_4 ( V_3 , L_27 ) ;
}
return 0 ;
}
static int F_73 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
bool V_281 = false ;
if ( F_27 ( V_9 ) )
V_281 = F_28 ( V_282 ) & V_283 ;
else if ( F_74 ( V_9 ) || F_75 ( V_9 ) || F_76 ( V_9 ) )
V_281 = F_28 ( V_284 ) & V_285 ;
else if ( F_77 ( V_9 ) )
V_281 = F_28 ( V_286 ) & V_287 ;
else if ( F_78 ( V_9 ) )
V_281 = F_28 ( V_288 ) & V_289 ;
F_4 ( V_3 , L_176 ,
V_281 ? L_177 : L_178 ) ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
unsigned long V_290 , V_291 , V_292 ;
int V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
V_290 = F_80 ( V_68 ) ;
V_291 = F_81 ( V_68 ) ;
V_292 = F_82 ( V_68 ) ;
F_12 ( & V_9 -> V_74 ) ;
F_4 ( V_3 , L_179 , V_290 ) ;
F_4 ( V_3 , L_180 , V_291 ) ;
F_4 ( V_3 , L_181 , V_292 ) ;
F_4 ( V_3 , L_182 , V_291 + V_292 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
F_4 ( V_3 , L_183 , ( unsigned long ) F_28 ( 0x112f4 ) ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_293 * V_294 = & V_68 -> V_294 ;
int V_73 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
if ( V_294 -> V_295 )
F_85 ( V_3 , V_294 -> V_295 , V_296 ) ;
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
struct V_297 * V_298 ;
struct V_299 * V_300 ;
int V_73 ;
V_73 = F_11 ( & V_9 -> V_301 . V_302 ) ;
if ( V_73 )
return V_73 ;
V_298 = V_68 -> V_303 ;
V_300 = F_87 ( V_298 -> V_304 . V_300 ) ;
F_4 ( V_3 , L_184 ,
V_300 -> V_44 . V_305 ,
V_300 -> V_44 . V_306 ,
V_300 -> V_44 . V_307 ,
V_300 -> V_44 . V_308 ) ;
F_9 ( V_3 , V_300 -> V_34 ) ;
F_4 ( V_3 , L_27 ) ;
F_13 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_300 -> V_44 == V_298 -> V_304 . V_300 )
continue;
F_4 ( V_3 , L_185 ,
V_300 -> V_44 . V_305 ,
V_300 -> V_44 . V_306 ,
V_300 -> V_44 . V_307 ,
V_300 -> V_44 . V_308 ) ;
F_9 ( V_3 , V_300 -> V_34 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_12 ( & V_9 -> V_301 . V_302 ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 , void * V_165 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_68 = V_9 -> V_69 ;
int V_73 ;
V_73 = F_11 ( & V_9 -> V_301 . V_302 ) ;
if ( V_73 )
return V_73 ;
if ( V_68 -> V_309 ) {
F_4 ( V_3 , L_186 ) ;
F_9 ( V_3 , V_68 -> V_309 ) ;
F_4 ( V_3 , L_27 ) ;
}
if ( V_68 -> V_310 ) {
F_4 ( V_3 , L_187 ) ;
F_9 ( V_3 , V_68 -> V_310 ) ;
F_4 ( V_3 , L_27 ) ;
}
F_12 ( & V_9 -> V_301 . V_302 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_87 * V_68 = V_9 -> V_69 ;
F_4 ( V_3 , L_188 ,
F_31 ( & V_68 -> V_311 ) ) ;
return 0 ;
}
static int
F_90 ( struct V_312 * V_312 ,
struct V_313 * V_314 )
{
V_314 -> V_315 = V_312 -> V_316 ;
return 0 ;
}
static T_10
F_91 ( struct V_313 * V_314 ,
char T_11 * V_317 ,
T_4 V_318 ,
T_12 * V_319 )
{
struct V_8 * V_9 = V_314 -> V_315 ;
T_3 * V_68 = V_9 -> V_69 ;
char V_320 [ 80 ] ;
int V_321 ;
V_321 = snprintf ( V_320 , sizeof ( V_320 ) ,
L_189 ,
F_31 ( & V_68 -> V_76 . V_322 ) ) ;
if ( V_321 > sizeof ( V_320 ) )
V_321 = sizeof ( V_320 ) ;
return F_92 ( V_317 , V_318 , V_319 , V_320 , V_321 ) ;
}
static T_10
F_93 ( struct V_313 * V_314 ,
const char T_11 * V_317 ,
T_4 V_323 ,
T_12 * V_319 )
{
struct V_8 * V_9 = V_314 -> V_315 ;
char V_320 [ 20 ] ;
int V_324 = 1 ;
if ( V_323 > 0 ) {
if ( V_323 > sizeof ( V_320 ) - 1 )
return - V_86 ;
if ( F_94 ( V_320 , V_317 , V_323 ) )
return - V_325 ;
V_320 [ V_323 ] = 0 ;
V_324 = F_95 ( V_320 , NULL , 0 ) ;
}
F_96 ( L_190 , V_324 ) ;
F_97 ( V_9 , V_324 ) ;
return V_323 ;
}
static int
F_98 ( struct V_326 * V_10 ,
struct V_327 * V_328 ,
const void * V_329 )
{
struct V_5 * V_6 ;
V_6 = F_99 ( sizeof( struct V_5 ) , V_330 ) ;
if ( V_6 == NULL ) {
F_100 ( V_328 ) ;
return - V_331 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_332 = V_328 ;
V_6 -> V_65 = ( void * ) V_329 ;
F_101 ( & V_6 -> V_64 , & V_10 -> V_333 . V_64 ) ;
return 0 ;
}
static int F_102 ( struct V_327 * V_334 , struct V_326 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_327 * V_328 ;
V_328 = F_103 ( L_191 ,
V_335 | V_336 ,
V_334 , V_9 ,
& V_337 ) ;
if ( F_104 ( V_328 ) )
return F_105 ( V_328 ) ;
return F_98 ( V_10 , V_328 , & V_337 ) ;
}
static int F_106 ( struct V_312 * V_312 , struct V_313 * V_313 )
{
struct V_8 * V_9 = V_312 -> V_316 ;
struct V_87 * V_68 = V_9 -> V_69 ;
int V_73 ;
if ( ! F_32 ( V_9 ) )
return 0 ;
V_73 = F_11 ( & V_9 -> V_74 ) ;
if ( V_73 )
return V_73 ;
F_64 ( V_68 ) ;
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
int F_107 ( struct V_312 * V_312 , struct V_313 * V_313 )
{
struct V_8 * V_9 = V_312 -> V_316 ;
struct V_87 * V_68 = V_9 -> V_69 ;
if ( ! F_32 ( V_9 ) )
return 0 ;
F_108 ( & V_9 -> V_74 ) ;
F_65 ( V_68 ) ;
F_12 ( & V_9 -> V_74 ) ;
return 0 ;
}
static int F_109 ( struct V_327 * V_334 , struct V_326 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_327 * V_328 ;
V_328 = F_103 ( L_192 ,
V_338 ,
V_334 , V_9 ,
& V_339 ) ;
if ( F_104 ( V_328 ) )
return F_105 ( V_328 ) ;
return F_98 ( V_10 , V_328 , & V_339 ) ;
}
int F_110 ( struct V_326 * V_10 )
{
int V_73 ;
V_73 = F_102 ( V_10 -> V_340 , V_10 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_109 ( V_10 -> V_340 , V_10 ) ;
if ( V_73 )
return V_73 ;
return F_111 ( V_341 ,
V_342 ,
V_10 -> V_340 , V_10 ) ;
}
void F_112 ( struct V_326 * V_10 )
{
F_113 ( V_341 ,
V_342 , V_10 ) ;
F_113 ( (struct V_343 * ) & V_339 ,
1 , V_10 ) ;
F_113 ( (struct V_343 * ) & V_337 ,
1 , V_10 ) ;
}
