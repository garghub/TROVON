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
F_6 ( V_14 ) ;
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
F_6 ( V_17 ) ;
F_6 ( V_18 ) ;
F_6 ( V_19 ) ;
F_6 ( V_20 ) ;
F_6 ( V_21 ) ;
F_6 ( V_22 ) ;
F_6 ( V_23 ) ;
F_6 ( V_24 ) ;
F_6 ( V_25 ) ;
F_6 ( V_26 ) ;
F_6 ( V_27 ) ;
F_6 ( V_28 ) ;
F_6 ( V_29 ) ;
F_6 ( V_30 ) ;
F_6 ( V_31 ) ;
F_6 ( V_32 ) ;
F_6 ( V_33 ) ;
#undef F_6
return 0 ;
}
static const char * F_7 ( struct V_34 * V_35 )
{
if ( V_35 -> V_36 > 0 )
return L_5 ;
else if ( V_35 -> V_37 > 0 )
return L_6 ;
else
return L_7 ;
}
static const char * F_8 ( struct V_34 * V_35 )
{
switch ( V_35 -> V_38 ) {
default:
case V_39 : return L_7 ;
case V_40 : return L_8 ;
case V_41 : return L_9 ;
}
}
static const char * F_9 ( int type )
{
switch ( type ) {
case V_42 : return L_10 ;
case V_43 : return L_11 ;
case V_44 : return L_12 ;
default: return L_13 ;
}
}
static void
F_10 ( struct V_2 * V_3 , struct V_34 * V_35 )
{
F_4 ( V_3 , L_14 ,
& V_35 -> V_45 ,
F_7 ( V_35 ) ,
F_8 ( V_35 ) ,
V_35 -> V_45 . V_46 / 1024 ,
V_35 -> V_45 . V_47 ,
V_35 -> V_45 . V_48 ,
V_35 -> V_49 ,
V_35 -> V_50 ,
F_9 ( V_35 -> V_51 ) ,
V_35 -> V_52 ? L_15 : L_13 ,
V_35 -> V_53 == V_54 ? L_16 : L_13 ) ;
if ( V_35 -> V_45 . V_55 )
F_4 ( V_3 , L_17 , V_35 -> V_45 . V_55 ) ;
if ( V_35 -> V_56 != V_57 )
F_4 ( V_3 , L_18 , V_35 -> V_56 ) ;
if ( V_35 -> V_58 != NULL )
F_4 ( V_3 , L_19 ,
V_35 -> V_59 , ( unsigned int ) V_35 -> V_58 -> V_46 ) ;
if ( V_35 -> V_60 || V_35 -> V_61 ) {
char V_62 [ 3 ] , * V_63 = V_62 ;
if ( V_35 -> V_60 )
* V_63 ++ = 'p' ;
if ( V_35 -> V_61 )
* V_63 ++ = 'f' ;
* V_63 = '\0' ;
F_4 ( V_3 , L_20 , V_62 ) ;
}
if ( V_35 -> V_64 != NULL )
F_4 ( V_3 , L_21 , V_35 -> V_64 -> V_55 ) ;
}
static int F_11 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_65 = ( T_2 ) V_6 -> V_66 -> V_4 ;
struct V_67 * V_68 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_34 * V_35 ;
T_4 V_71 , V_72 ;
int V_73 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
switch ( V_65 ) {
case V_76 :
F_4 ( V_3 , L_22 ) ;
V_68 = & V_69 -> V_77 . V_78 ;
break;
case V_79 :
F_4 ( V_3 , L_23 ) ;
V_68 = & V_69 -> V_77 . V_80 ;
break;
case V_81 :
F_4 ( V_3 , L_24 ) ;
V_68 = & V_69 -> V_77 . V_82 ;
break;
case V_83 :
F_4 ( V_3 , L_25 ) ;
V_68 = & V_69 -> V_77 . V_84 ;
break;
case V_85 :
F_4 ( V_3 , L_26 ) ;
V_68 = & V_69 -> V_77 . V_86 ;
break;
default:
F_13 ( & V_9 -> V_75 ) ;
return - V_87 ;
}
V_71 = V_72 = V_73 = 0 ;
F_14 (obj, head, mm_list) {
F_4 ( V_3 , L_27 ) ;
F_10 ( V_3 , V_35 ) ;
F_4 ( V_3 , L_28 ) ;
V_71 += V_35 -> V_45 . V_46 ;
V_72 += V_35 -> V_58 -> V_46 ;
V_73 ++ ;
}
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_29 ,
V_73 , V_71 , V_72 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_88 * V_69 = V_9 -> V_70 ;
T_5 V_73 , V_89 ;
T_4 V_46 , V_90 ;
struct V_34 * V_35 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_30 ,
V_69 -> V_77 . V_91 ,
V_69 -> V_77 . V_92 ) ;
V_46 = V_73 = V_90 = V_89 = 0 ;
F_16 ( & V_69 -> V_77 . V_93 , V_93 ) ;
F_4 ( V_3 , L_31 ,
V_73 , V_89 , V_46 , V_90 ) ;
V_46 = V_73 = V_90 = V_89 = 0 ;
F_16 ( & V_69 -> V_77 . V_78 , V_94 ) ;
F_16 ( & V_69 -> V_77 . V_84 , V_94 ) ;
F_4 ( V_3 , L_32 ,
V_73 , V_89 , V_46 , V_90 ) ;
V_46 = V_73 = V_90 = V_89 = 0 ;
F_16 ( & V_69 -> V_77 . V_82 , V_94 ) ;
F_4 ( V_3 , L_33 ,
V_73 , V_89 , V_46 , V_90 ) ;
V_46 = V_73 = V_90 = V_89 = 0 ;
F_16 ( & V_69 -> V_77 . V_80 , V_94 ) ;
F_4 ( V_3 , L_34 ,
V_73 , V_89 , V_46 , V_90 ) ;
V_46 = V_73 = V_90 = V_89 = 0 ;
F_16 ( & V_69 -> V_77 . V_86 , V_94 ) ;
F_4 ( V_3 , L_35 ,
V_73 , V_89 , V_46 , V_90 ) ;
V_46 = V_73 = V_90 = V_89 = 0 ;
F_14 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_35 -> V_61 ) {
V_46 += V_35 -> V_58 -> V_46 ;
++ V_73 ;
}
if ( V_35 -> V_60 ) {
V_90 += V_35 -> V_58 -> V_46 ;
++ V_89 ;
}
}
F_4 ( V_3 , L_36 ,
V_89 , V_90 ) ;
F_4 ( V_3 , L_37 ,
V_73 , V_46 ) ;
F_4 ( V_3 , L_38 ,
V_69 -> V_77 . V_95 , V_69 -> V_77 . V_96 ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_88 * V_69 = V_9 -> V_70 ;
struct V_34 * V_35 ;
T_4 V_71 , V_72 ;
int V_73 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_71 = V_72 = V_73 = 0 ;
F_14 (obj, &dev_priv->mm.gtt_list, gtt_list) {
F_4 ( V_3 , L_27 ) ;
F_10 ( V_3 , V_35 ) ;
F_4 ( V_3 , L_28 ) ;
V_71 += V_35 -> V_45 . V_46 ;
V_72 += V_35 -> V_58 -> V_46 ;
V_73 ++ ;
}
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_29 ,
V_73 , V_71 , V_72 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
unsigned long V_97 ;
struct V_98 * V_99 ;
F_14 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_100 = F_19 ( V_99 -> V_100 ) ;
const char V_101 = F_20 ( V_99 -> V_101 ) ;
struct V_102 * V_103 ;
F_21 ( & V_9 -> V_104 , V_97 ) ;
V_103 = V_99 -> V_105 ;
if ( V_103 == NULL ) {
F_4 ( V_3 , L_39 ,
V_100 , V_101 ) ;
} else {
if ( ! V_103 -> V_106 ) {
F_4 ( V_3 , L_40 ,
V_100 , V_101 ) ;
} else {
F_4 ( V_3 , L_41 ,
V_100 , V_101 ) ;
}
if ( V_103 -> V_107 )
F_4 ( V_3 , L_42 ) ;
else
F_4 ( V_3 , L_43 ) ;
F_4 ( V_3 , L_44 , V_103 -> V_106 ) ;
if ( V_103 -> V_108 ) {
struct V_34 * V_35 = V_103 -> V_108 ;
if ( V_35 )
F_4 ( V_3 , L_45 , V_35 -> V_59 ) ;
}
if ( V_103 -> V_109 ) {
struct V_34 * V_35 = V_103 -> V_109 ;
if ( V_35 )
F_4 ( V_3 , L_46 , V_35 -> V_59 ) ;
}
}
F_22 ( & V_9 -> V_104 , V_97 ) ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_110 * V_111 ;
int V_74 , V_73 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_73 = 0 ;
if ( ! F_24 ( & V_69 -> V_64 [ V_112 ] . V_113 ) ) {
F_4 ( V_3 , L_47 ) ;
F_14 (gem_request,
&dev_priv->ring[RCS].request_list,
list) {
F_4 ( V_3 , L_48 ,
V_111 -> V_114 ,
( int ) ( V_115 - V_111 -> V_116 ) ) ;
}
V_73 ++ ;
}
if ( ! F_24 ( & V_69 -> V_64 [ V_117 ] . V_113 ) ) {
F_4 ( V_3 , L_49 ) ;
F_14 (gem_request,
&dev_priv->ring[VCS].request_list,
list) {
F_4 ( V_3 , L_48 ,
V_111 -> V_114 ,
( int ) ( V_115 - V_111 -> V_116 ) ) ;
}
V_73 ++ ;
}
if ( ! F_24 ( & V_69 -> V_64 [ V_118 ] . V_113 ) ) {
F_4 ( V_3 , L_50 ) ;
F_14 (gem_request,
&dev_priv->ring[BCS].request_list,
list) {
F_4 ( V_3 , L_48 ,
V_111 -> V_114 ,
( int ) ( V_115 - V_111 -> V_116 ) ) ;
}
V_73 ++ ;
}
F_13 ( & V_9 -> V_75 ) ;
if ( V_73 == 0 )
F_4 ( V_3 , L_51 ) ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_119 * V_64 )
{
if ( V_64 -> V_120 ) {
F_4 ( V_3 , L_52 ,
V_64 -> V_55 , V_64 -> V_120 ( V_64 ) ) ;
F_4 ( V_3 , L_53 ,
V_64 -> V_55 , V_64 -> V_121 ) ;
F_4 ( V_3 , L_54 ,
V_64 -> V_55 , V_64 -> V_122 ) ;
}
}
static int F_26 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 , V_123 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ )
F_25 ( V_3 , & V_69 -> V_64 [ V_123 ] ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 , V_123 , V_100 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
if ( ! F_28 ( V_9 ) ) {
F_4 ( V_3 , L_55 ,
F_29 ( V_125 ) ) ;
F_4 ( V_3 , L_56 ,
F_29 ( V_126 ) ) ;
F_4 ( V_3 , L_57 ,
F_29 ( V_127 ) ) ;
F_30 (pipe)
F_4 ( V_3 , L_58 ,
F_19 ( V_100 ) ,
F_29 ( F_31 ( V_100 ) ) ) ;
} else {
F_4 ( V_3 , L_59 ,
F_29 ( V_128 ) ) ;
F_4 ( V_3 , L_60 ,
F_29 ( V_129 ) ) ;
F_4 ( V_3 , L_61 ,
F_29 ( V_130 ) ) ;
F_4 ( V_3 , L_62 ,
F_29 ( V_131 ) ) ;
F_4 ( V_3 , L_63 ,
F_29 ( V_132 ) ) ;
F_4 ( V_3 , L_64 ,
F_29 ( V_133 ) ) ;
F_4 ( V_3 , L_65 ,
F_29 ( V_134 ) ) ;
F_4 ( V_3 , L_66 ,
F_29 ( V_135 ) ) ;
F_4 ( V_3 , L_67 ,
F_29 ( V_136 ) ) ;
}
F_4 ( V_3 , L_68 ,
F_32 ( & V_69 -> V_137 ) ) ;
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ ) {
if ( F_33 ( V_9 ) || F_34 ( V_9 ) ) {
F_4 ( V_3 , L_69 ,
V_69 -> V_64 [ V_123 ] . V_55 ,
F_35 ( & V_69 -> V_64 [ V_123 ] ) ) ;
}
F_25 ( V_3 , & V_69 -> V_64 [ V_123 ] ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_123 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_70 , V_69 -> V_138 ) ;
F_4 ( V_3 , L_71 , V_69 -> V_139 ) ;
for ( V_123 = 0 ; V_123 < V_69 -> V_139 ; V_123 ++ ) {
struct V_34 * V_35 = V_69 -> V_140 [ V_123 ] . V_35 ;
F_4 ( V_3 , L_72 , V_123 ) ;
if ( V_35 == NULL )
F_4 ( V_3 , L_73 ) ;
else
F_10 ( V_3 , V_35 ) ;
F_4 ( V_3 , L_28 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_119 * V_64 ;
const volatile T_5 T_6 * V_141 ;
int V_123 ;
V_64 = & V_69 -> V_64 [ ( T_2 ) V_6 -> V_66 -> V_4 ] ;
V_141 = ( volatile T_5 T_6 * ) V_64 -> V_142 . V_143 ;
if ( V_141 == NULL )
return 0 ;
for ( V_123 = 0 ; V_123 < 4096 / sizeof( T_5 ) / 4 ; V_123 += 4 ) {
F_4 ( V_3 , L_74 ,
V_123 * 4 ,
V_141 [ V_123 ] , V_141 [ V_123 + 1 ] , V_141 [ V_123 + 2 ] , V_141 [ V_123 + 3 ] ) ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_119 * V_64 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_64 = & V_69 -> V_64 [ ( T_2 ) V_6 -> V_66 -> V_4 ] ;
if ( ! V_64 -> V_35 ) {
F_4 ( V_3 , L_75 ) ;
} else {
const T_7 T_6 * V_144 = V_64 -> V_145 ;
T_8 V_146 ;
for ( V_146 = 0 ; V_146 < V_64 -> V_46 ; V_146 += 4 ) {
T_8 * V_147 = ( T_8 * ) ( V_144 + V_146 ) ;
F_4 ( V_3 , L_76 , V_146 , * V_147 ) ;
}
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_119 * V_64 ;
int V_74 ;
V_64 = & V_69 -> V_64 [ ( T_2 ) V_6 -> V_66 -> V_4 ] ;
if ( V_64 -> V_46 == 0 )
return 0 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_77 , V_64 -> V_55 ) ;
F_4 ( V_3 , L_78 , F_40 ( V_64 ) & V_148 ) ;
F_4 ( V_3 , L_79 , F_41 ( V_64 ) & V_149 ) ;
F_4 ( V_3 , L_80 , V_64 -> V_46 ) ;
F_4 ( V_3 , L_81 , F_42 ( V_64 ) ) ;
F_4 ( V_3 , L_82 , F_43 ( V_64 ) ) ;
if ( F_33 ( V_9 ) || F_34 ( V_9 ) ) {
F_4 ( V_3 , L_83 , F_44 ( V_64 ) ) ;
F_4 ( V_3 , L_84 , F_45 ( V_64 ) ) ;
}
F_4 ( V_3 , L_85 , F_46 ( V_64 ) ) ;
F_4 ( V_3 , L_86 , F_47 ( V_64 ) ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static const char * F_48 ( int V_64 )
{
switch ( V_64 ) {
case V_112 : return L_87 ;
case V_117 : return L_88 ;
case V_118 : return L_89 ;
default: return L_13 ;
}
}
static const char * F_49 ( int V_150 )
{
if ( V_150 > 0 )
return L_90 ;
else if ( V_150 < 0 )
return L_91 ;
else
return L_13 ;
}
static const char * F_50 ( int V_151 )
{
switch ( V_151 ) {
default:
case V_39 : return L_13 ;
case V_40 : return L_92 ;
case V_41 : return L_93 ;
}
}
static const char * F_51 ( int V_52 )
{
return V_52 ? L_15 : L_13 ;
}
static const char * F_52 ( int V_152 )
{
return V_152 ? L_16 : L_13 ;
}
static void F_53 ( struct V_2 * V_3 ,
const char * V_55 ,
struct V_153 * V_154 ,
int V_73 )
{
F_4 ( V_3 , L_94 , V_55 , V_73 ) ;
while ( V_73 -- ) {
F_4 ( V_3 , L_95 ,
V_154 -> V_59 ,
V_154 -> V_46 ,
V_154 -> V_47 ,
V_154 -> V_48 ,
V_154 -> V_114 ,
F_49 ( V_154 -> V_150 ) ,
F_50 ( V_154 -> V_151 ) ,
F_51 ( V_154 -> V_52 ) ,
F_52 ( V_154 -> V_152 ) ,
V_154 -> V_64 != - 1 ? L_7 : L_13 ,
F_48 ( V_154 -> V_64 ) ,
F_9 ( V_154 -> V_51 ) ) ;
if ( V_154 -> V_55 )
F_4 ( V_3 , L_17 , V_154 -> V_55 ) ;
if ( V_154 -> V_56 != V_57 )
F_4 ( V_3 , L_18 , V_154 -> V_56 ) ;
F_4 ( V_3 , L_28 ) ;
V_154 ++ ;
}
}
static void F_54 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
struct V_155 * error ,
unsigned V_64 )
{
F_4 ( V_3 , L_96 , F_48 ( V_64 ) ) ;
F_4 ( V_3 , L_97 , error -> V_68 [ V_64 ] ) ;
F_4 ( V_3 , L_98 , error -> V_156 [ V_64 ] ) ;
F_4 ( V_3 , L_99 , error -> V_157 [ V_64 ] ) ;
F_4 ( V_3 , L_100 , error -> V_158 [ V_64 ] ) ;
F_4 ( V_3 , L_101 , error -> V_159 [ V_64 ] ) ;
F_4 ( V_3 , L_102 , error -> V_160 [ V_64 ] ) ;
if ( V_64 == V_112 && F_3 ( V_9 ) -> V_13 >= 4 ) {
F_4 ( V_3 , L_103 , error -> V_161 ) ;
F_4 ( V_3 , L_104 , error -> V_162 ) ;
}
if ( F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_105 , error -> V_163 [ V_64 ] ) ;
F_4 ( V_3 , L_106 , error -> V_164 [ V_64 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_107 , error -> V_165 [ V_64 ] ) ;
F_4 ( V_3 , L_108 , error -> V_166 [ V_64 ] ) ;
F_4 ( V_3 , L_109 ,
error -> V_167 [ V_64 ] [ 0 ] ) ;
F_4 ( V_3 , L_110 ,
error -> V_167 [ V_64 ] [ 1 ] ) ;
}
F_4 ( V_3 , L_111 , error -> V_114 [ V_64 ] ) ;
F_4 ( V_3 , L_112 , error -> V_168 [ V_64 ] ) ;
F_4 ( V_3 , L_113 , error -> V_169 [ V_64 ] ) ;
}
static int F_55 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_155 * error ;
unsigned long V_97 ;
int V_123 , V_171 , V_172 , V_173 , V_174 ;
F_21 ( & V_69 -> V_175 , V_97 ) ;
if ( ! V_69 -> V_176 ) {
F_4 ( V_3 , L_114 ) ;
goto V_177;
}
error = V_69 -> V_176 ;
F_4 ( V_3 , L_115 , error -> time . V_178 ,
error -> time . V_179 ) ;
F_4 ( V_3 , L_116 , V_9 -> V_180 ) ;
F_4 ( V_3 , L_117 , error -> V_181 ) ;
F_4 ( V_3 , L_118 , error -> V_182 ) ;
for ( V_123 = 0 ; V_123 < V_69 -> V_139 ; V_123 ++ )
F_4 ( V_3 , L_119 , V_123 , error -> V_183 [ V_123 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_120 , error -> error ) ;
F_4 ( V_3 , L_121 , error -> V_184 ) ;
}
F_54 ( V_3 , V_9 , error , V_112 ) ;
if ( F_56 ( V_9 ) )
F_54 ( V_3 , V_9 , error , V_118 ) ;
if ( F_57 ( V_9 ) )
F_54 ( V_3 , V_9 , error , V_117 ) ;
if ( error -> V_185 )
F_53 ( V_3 , L_122 ,
error -> V_185 ,
error -> V_186 ) ;
if ( error -> V_187 )
F_53 ( V_3 , L_123 ,
error -> V_187 ,
error -> V_188 ) ;
for ( V_123 = 0 ; V_123 < F_58 ( error -> V_64 ) ; V_123 ++ ) {
struct V_189 * V_35 ;
if ( ( V_35 = error -> V_64 [ V_123 ] . V_190 ) ) {
F_4 ( V_3 , L_124 ,
V_69 -> V_64 [ V_123 ] . V_55 ,
V_35 -> V_59 ) ;
V_173 = 0 ;
for ( V_172 = 0 ; V_172 < V_35 -> V_191 ; V_172 ++ ) {
for ( V_174 = 0 ; V_174 < V_192 / 4 ; V_174 ++ ) {
F_4 ( V_3 , L_76 , V_173 , V_35 -> V_193 [ V_172 ] [ V_174 ] ) ;
V_173 += 4 ;
}
}
}
if ( error -> V_64 [ V_123 ] . V_194 ) {
F_4 ( V_3 , L_125 ,
V_69 -> V_64 [ V_123 ] . V_55 ,
error -> V_64 [ V_123 ] . V_194 ) ;
for ( V_171 = 0 ; V_171 < error -> V_64 [ V_123 ] . V_194 ; V_171 ++ ) {
F_4 ( V_3 , L_126 ,
error -> V_64 [ V_123 ] . V_195 [ V_171 ] . V_114 ,
error -> V_64 [ V_123 ] . V_195 [ V_171 ] . V_115 ,
error -> V_64 [ V_123 ] . V_195 [ V_171 ] . V_156 ) ;
}
}
if ( ( V_35 = error -> V_64 [ V_123 ] . V_196 ) ) {
F_4 ( V_3 , L_127 ,
V_69 -> V_64 [ V_123 ] . V_55 ,
V_35 -> V_59 ) ;
V_173 = 0 ;
for ( V_172 = 0 ; V_172 < V_35 -> V_191 ; V_172 ++ ) {
for ( V_174 = 0 ; V_174 < V_192 / 4 ; V_174 ++ ) {
F_4 ( V_3 , L_76 ,
V_173 ,
V_35 -> V_193 [ V_172 ] [ V_174 ] ) ;
V_173 += 4 ;
}
}
}
}
if ( error -> V_197 )
F_59 ( V_3 , error -> V_197 ) ;
if ( error -> V_198 )
F_60 ( V_3 , V_9 , error -> V_198 ) ;
V_177:
F_22 ( & V_69 -> V_175 , V_97 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_9 V_199 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_199 = F_62 ( V_200 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_128 , ( V_199 >> 8 ) & 0x3f , ( V_199 & 0x3f ) ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
if ( F_64 ( V_9 ) ) {
T_9 V_201 = F_62 ( V_202 ) ;
T_9 V_203 = F_62 ( V_204 ) ;
F_4 ( V_3 , L_129 , ( V_201 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_130 , V_201 & 0x3f ) ;
F_4 ( V_3 , L_131 , ( V_203 & V_205 ) >>
V_206 ) ;
F_4 ( V_3 , L_132 ,
( V_203 & V_207 ) >> V_208 ) ;
} else if ( F_33 ( V_9 ) || F_34 ( V_9 ) ) {
T_5 V_209 = F_29 ( V_210 ) ;
T_5 V_211 = F_29 ( V_212 ) ;
T_5 V_213 = F_29 ( V_214 ) ;
T_5 V_215 ;
T_5 V_216 , V_217 , V_218 ;
T_5 V_219 , V_220 , V_221 ;
int V_222 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_65 ( V_69 ) ;
V_215 = F_29 ( V_223 ) ;
V_216 = F_29 ( V_224 ) ;
V_217 = F_29 ( V_225 ) ;
V_218 = F_29 ( V_226 ) ;
V_219 = F_29 ( V_227 ) ;
V_220 = F_29 ( V_228 ) ;
V_221 = F_29 ( V_229 ) ;
F_66 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_133 , V_209 ) ;
F_4 ( V_3 , L_134 , V_215 ) ;
F_4 ( V_3 , L_135 ,
( V_209 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_136 ,
V_209 & 0xff ) ;
F_4 ( V_3 , L_137 ,
V_211 & 0xff ) ;
F_4 ( V_3 , L_138 , ( ( V_215 & V_230 ) >>
V_231 ) * 50 ) ;
F_4 ( V_3 , L_139 , V_216 &
V_232 ) ;
F_4 ( V_3 , L_140 , V_217 &
V_233 ) ;
F_4 ( V_3 , L_141 , V_218 &
V_233 ) ;
F_4 ( V_3 , L_142 , V_219 &
V_234 ) ;
F_4 ( V_3 , L_143 , V_220 &
V_233 ) ;
F_4 ( V_3 , L_144 , V_221 &
V_233 ) ;
V_222 = ( V_213 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_145 ,
V_222 * 50 ) ;
V_222 = ( V_213 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_146 ,
V_222 * 50 ) ;
V_222 = V_213 & 0xff ;
F_4 ( V_3 , L_147 ,
V_222 * 50 ) ;
} else {
F_4 ( V_3 , L_148 ) ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_5 V_235 ;
int V_74 , V_123 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
for ( V_123 = 0 ; V_123 < 16 ; V_123 ++ ) {
V_235 = F_29 ( V_236 + V_123 * 4 ) ;
F_4 ( V_3 , L_149 , V_123 , V_235 ,
( V_235 & V_237 ) >> V_238 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static inline int F_68 ( int V_239 )
{
return 1250 - ( V_239 * 25 ) ;
}
static int F_69 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_5 V_240 ;
int V_74 , V_123 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
for ( V_123 = 1 ; V_123 <= 32 ; V_123 ++ ) {
V_240 = F_29 ( V_241 + V_123 * 4 ) ;
F_4 ( V_3 , L_150 , V_123 , V_240 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_5 V_242 , V_243 ;
T_9 V_244 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_242 = F_29 ( V_245 ) ;
V_243 = F_29 ( V_246 ) ;
V_244 = F_62 ( V_200 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_151 , ( V_242 & V_247 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_152 ,
( V_242 & V_248 ) >>
V_249 ) ;
F_4 ( V_3 , L_153 ,
V_242 & V_250 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_154 ,
V_242 & V_251 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_155 ,
V_242 & V_252 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_156 ,
( V_242 & V_253 ) >> V_254 ) ;
F_4 ( V_3 , L_157 ,
( V_242 & V_255 ) >> V_256 ) ;
F_4 ( V_3 , L_158 , ( V_242 & V_257 ) ) ;
F_4 ( V_3 , L_159 , ( V_244 & 0x3f ) ) ;
F_4 ( V_3 , L_160 , ( ( V_244 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_161 ,
( V_243 & V_258 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_162 ) ;
switch ( V_243 & V_259 ) {
case V_260 :
F_4 ( V_3 , L_163 ) ;
break;
case V_261 :
F_4 ( V_3 , L_164 ) ;
break;
case V_262 :
F_4 ( V_3 , L_165 ) ;
break;
case V_263 :
F_4 ( V_3 , L_166 ) ;
break;
case V_264 :
F_4 ( V_3 , L_167 ) ;
break;
case V_265 :
F_4 ( V_3 , L_168 ) ;
break;
default:
F_4 ( V_3 , L_169 ) ;
break;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_88 * V_69 = V_9 -> V_70 ;
T_5 V_266 , V_267 , V_268 ;
unsigned V_269 ;
int V_73 = 0 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_72 ( & V_69 -> V_270 ) ;
V_269 = V_69 -> V_269 ;
F_73 ( & V_69 -> V_270 ) ;
if ( V_269 ) {
F_4 ( V_3 , L_170
L_171 ) ;
} else {
while ( V_73 ++ < 50 && ( F_74 ( V_271 ) & 1 ) )
F_75 ( 10 ) ;
F_4 ( V_3 , L_172 , F_1 ( V_73 < 51 ) ) ;
}
V_267 = F_76 ( V_69 -> V_272 + V_273 ) ;
F_77 ( false , V_273 , V_267 , 4 ) ;
V_266 = F_29 ( V_274 ) ;
V_268 = F_29 ( V_275 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_173 ,
F_1 ( V_266 & V_276 ) ) ;
F_4 ( V_3 , L_153 ,
F_1 ( V_266 & V_277 ) ) ;
F_4 ( V_3 , L_154 ,
F_1 ( ( V_266 & V_278 ) ==
V_279 ) ) ;
F_4 ( V_3 , L_174 ,
F_1 ( V_268 & V_280 ) ) ;
F_4 ( V_3 , L_175 ,
F_1 ( V_268 & V_281 ) ) ;
F_4 ( V_3 , L_176 ,
F_1 ( V_268 & V_282 ) ) ;
F_4 ( V_3 , L_177 ,
F_1 ( V_268 & V_283 ) ) ;
F_4 ( V_3 , L_178 ) ;
switch ( V_267 & V_284 ) {
case V_285 :
if ( V_267 & V_286 )
F_4 ( V_3 , L_179 ) ;
else
F_4 ( V_3 , L_163 ) ;
break;
case V_287 :
F_4 ( V_3 , L_180 ) ;
break;
case V_288 :
F_4 ( V_3 , L_181 ) ;
break;
case V_289 :
F_4 ( V_3 , L_182 ) ;
break;
default:
F_4 ( V_3 , L_183 ) ;
break;
}
F_4 ( V_3 , L_184 ,
F_1 ( V_267 & V_286 ) ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_33 ( V_9 ) || F_34 ( V_9 ) )
return F_71 ( V_3 ) ;
else
return F_70 ( V_3 ) ;
}
static int F_79 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
if ( ! F_80 ( V_9 ) ) {
F_4 ( V_3 , L_185 ) ;
return 0 ;
}
if ( F_81 ( V_9 ) ) {
F_4 ( V_3 , L_186 ) ;
} else {
F_4 ( V_3 , L_187 ) ;
switch ( V_69 -> V_290 ) {
case V_291 :
F_4 ( V_3 , L_188 ) ;
break;
case V_292 :
F_4 ( V_3 , L_189 ) ;
break;
case V_293 :
F_4 ( V_3 , L_190 ) ;
break;
case V_294 :
F_4 ( V_3 , L_191 ) ;
break;
case V_295 :
F_4 ( V_3 , L_192 ) ;
break;
case V_296 :
F_4 ( V_3 , L_193 ) ;
break;
case V_297 :
F_4 ( V_3 , L_194 ) ;
break;
case V_298 :
F_4 ( V_3 , L_195 ) ;
break;
default:
F_4 ( V_3 , L_196 ) ;
}
F_4 ( V_3 , L_28 ) ;
}
return 0 ;
}
static int F_82 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
bool V_299 = false ;
if ( F_28 ( V_9 ) )
V_299 = F_29 ( V_300 ) & V_301 ;
else if ( F_83 ( V_9 ) || F_84 ( V_9 ) || F_85 ( V_9 ) )
V_299 = F_29 ( V_302 ) & V_303 ;
else if ( F_86 ( V_9 ) )
V_299 = F_29 ( V_304 ) & V_305 ;
else if ( F_87 ( V_9 ) )
V_299 = F_29 ( V_306 ) & V_307 ;
F_4 ( V_3 , L_197 ,
V_299 ? L_198 : L_199 ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
unsigned long V_308 , V_309 , V_310 ;
int V_74 ;
if ( ! F_64 ( V_9 ) )
return - V_311 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_308 = F_89 ( V_69 ) ;
V_309 = F_90 ( V_69 ) ;
V_310 = F_91 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_200 , V_308 ) ;
F_4 ( V_3 , L_201 , V_309 ) ;
F_4 ( V_3 , L_202 , V_310 ) ;
F_4 ( V_3 , L_203 , V_309 + V_310 ) ;
return 0 ;
}
static int F_92 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
int V_312 , V_313 ;
if ( ! ( F_33 ( V_9 ) || F_34 ( V_9 ) ) ) {
F_4 ( V_3 , L_204 ) ;
return 0 ;
}
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_205 ) ;
for ( V_312 = V_69 -> V_314 ; V_312 <= V_69 -> V_315 ;
V_312 ++ ) {
F_93 ( V_316 , V_312 ) ;
F_93 ( V_317 , V_318 |
V_319 ) ;
if ( F_94 ( ( F_29 ( V_317 ) &
V_318 ) == 0 , 10 ) ) {
F_95 ( L_206 ) ;
continue;
}
V_313 = F_29 ( V_316 ) ;
F_4 ( V_3 , L_207 , V_312 * 50 , V_313 * 100 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_208 , ( unsigned long ) F_29 ( 0x112f4 ) ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_97 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_320 * V_321 = & V_69 -> V_321 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
if ( V_321 -> V_322 )
F_98 ( V_3 , V_321 -> V_322 , V_323 ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_324 * V_325 ;
struct V_326 * V_327 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_328 . V_329 ) ;
if ( V_74 )
return V_74 ;
V_325 = V_69 -> V_330 ;
V_327 = F_100 ( V_325 -> V_331 . V_327 ) ;
F_4 ( V_3 , L_209 ,
V_327 -> V_45 . V_332 ,
V_327 -> V_45 . V_333 ,
V_327 -> V_45 . V_334 ,
V_327 -> V_45 . V_335 ) ;
F_10 ( V_3 , V_327 -> V_35 ) ;
F_4 ( V_3 , L_28 ) ;
F_14 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_327 -> V_45 == V_325 -> V_331 . V_327 )
continue;
F_4 ( V_3 , L_210 ,
V_327 -> V_45 . V_332 ,
V_327 -> V_45 . V_333 ,
V_327 -> V_45 . V_334 ,
V_327 -> V_45 . V_335 ) ;
F_10 ( V_3 , V_327 -> V_35 ) ;
F_4 ( V_3 , L_28 ) ;
}
F_13 ( & V_9 -> V_328 . V_329 ) ;
return 0 ;
}
static int F_101 ( struct V_2 * V_3 , void * V_170 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_328 . V_329 ) ;
if ( V_74 )
return V_74 ;
if ( V_69 -> V_336 ) {
F_4 ( V_3 , L_211 ) ;
F_10 ( V_3 , V_69 -> V_336 ) ;
F_4 ( V_3 , L_28 ) ;
}
if ( V_69 -> V_337 ) {
F_4 ( V_3 , L_212 ) ;
F_10 ( V_3 , V_69 -> V_337 ) ;
F_4 ( V_3 , L_28 ) ;
}
F_13 ( & V_9 -> V_328 . V_329 ) ;
return 0 ;
}
static int F_102 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_88 * V_69 = V_9 -> V_70 ;
unsigned V_269 ;
F_72 ( & V_69 -> V_270 ) ;
V_269 = V_69 -> V_269 ;
F_73 ( & V_69 -> V_270 ) ;
F_4 ( V_3 , L_213 , V_269 ) ;
return 0 ;
}
static const char * F_103 ( unsigned V_338 )
{
switch( V_338 ) {
case V_339 :
return L_214 ;
case V_340 :
return L_215 ;
case V_341 :
return L_216 ;
case V_342 :
return L_217 ;
case V_343 :
return L_218 ;
case V_344 :
return L_219 ;
case V_345 :
return L_220 ;
case V_346 :
return L_221 ;
}
return L_222 ;
}
static int F_104 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_88 * V_69 = V_9 -> V_70 ;
F_105 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_223 ,
F_103 ( V_69 -> V_77 . V_347 ) ) ;
F_4 ( V_3 , L_224 ,
F_103 ( V_69 -> V_77 . V_348 ) ) ;
if ( F_106 ( V_9 ) || F_107 ( V_9 ) ) {
F_4 ( V_3 , L_225 ,
F_29 ( V_349 ) ) ;
F_4 ( V_3 , L_226 ,
F_62 ( V_350 ) ) ;
F_4 ( V_3 , L_227 ,
F_62 ( V_351 ) ) ;
} else if ( F_33 ( V_9 ) || F_34 ( V_9 ) ) {
F_4 ( V_3 , L_228 ,
F_29 ( V_352 ) ) ;
F_4 ( V_3 , L_229 ,
F_29 ( V_353 ) ) ;
F_4 ( V_3 , L_230 ,
F_29 ( V_354 ) ) ;
F_4 ( V_3 , L_231 ,
F_29 ( V_355 ) ) ;
F_4 ( V_3 , L_232 ,
F_29 ( V_356 ) ) ;
F_4 ( V_3 , L_233 ,
F_29 ( V_357 ) ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_88 * V_69 = V_9 -> V_70 ;
struct V_119 * V_64 ;
int V_123 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
if ( F_3 ( V_9 ) -> V_13 == 6 )
F_4 ( V_3 , L_234 , F_29 ( V_358 ) ) ;
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ ) {
V_64 = & V_69 -> V_64 [ V_123 ] ;
F_4 ( V_3 , L_235 , V_64 -> V_55 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_234 , F_29 ( F_109 ( V_64 ) ) ) ;
F_4 ( V_3 , L_236 , F_29 ( F_110 ( V_64 ) ) ) ;
F_4 ( V_3 , L_237 , F_29 ( F_111 ( V_64 ) ) ) ;
F_4 ( V_3 , L_238 , F_29 ( F_112 ( V_64 ) ) ) ;
}
if ( V_69 -> V_77 . V_359 ) {
struct V_360 * V_361 = V_69 -> V_77 . V_359 ;
F_4 ( V_3 , L_239 ) ;
F_4 ( V_3 , L_240 , V_361 -> V_362 ) ;
}
F_4 ( V_3 , L_241 , F_29 ( V_363 ) ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static T_10
F_113 ( struct V_364 * V_365 ,
char T_11 * V_366 ,
T_4 V_367 ,
T_12 * V_368 )
{
struct V_8 * V_9 = V_365 -> V_369 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_370 [ 80 ] ;
int V_371 ;
V_371 = snprintf ( V_370 , sizeof( V_370 ) ,
L_242 ,
F_32 ( & V_69 -> V_77 . V_372 ) ) ;
if ( V_371 > sizeof( V_370 ) )
V_371 = sizeof( V_370 ) ;
return F_114 ( V_366 , V_367 , V_368 , V_370 , V_371 ) ;
}
static T_10
F_115 ( struct V_364 * V_365 ,
const char T_11 * V_366 ,
T_4 V_373 ,
T_12 * V_368 )
{
struct V_8 * V_9 = V_365 -> V_369 ;
char V_370 [ 20 ] ;
int V_374 = 1 ;
if ( V_373 > 0 ) {
if ( V_373 > sizeof( V_370 ) - 1 )
return - V_87 ;
if ( F_116 ( V_370 , V_366 , V_373 ) )
return - V_375 ;
V_370 [ V_373 ] = 0 ;
V_374 = F_117 ( V_370 , NULL , 0 ) ;
}
F_118 ( L_243 , V_374 ) ;
F_119 ( V_9 , V_374 ) ;
return V_373 ;
}
static T_10
F_120 ( struct V_364 * V_365 ,
char T_11 * V_366 ,
T_4 V_367 ,
T_12 * V_368 )
{
struct V_8 * V_9 = V_365 -> V_369 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_370 [ 80 ] ;
int V_371 ;
V_371 = snprintf ( V_370 , sizeof( V_370 ) ,
L_244 , V_69 -> V_315 * 50 ) ;
if ( V_371 > sizeof( V_370 ) )
V_371 = sizeof( V_370 ) ;
return F_114 ( V_366 , V_367 , V_368 , V_370 , V_371 ) ;
}
static T_10
F_121 ( struct V_364 * V_365 ,
const char T_11 * V_366 ,
T_4 V_373 ,
T_12 * V_368 )
{
struct V_8 * V_9 = V_365 -> V_369 ;
struct V_88 * V_69 = V_9 -> V_70 ;
char V_370 [ 20 ] ;
int V_374 = 1 ;
if ( V_373 > 0 ) {
if ( V_373 > sizeof( V_370 ) - 1 )
return - V_87 ;
if ( F_116 ( V_370 , V_366 , V_373 ) )
return - V_375 ;
V_370 [ V_373 ] = 0 ;
V_374 = F_117 ( V_370 , NULL , 0 ) ;
}
F_122 ( L_245 , V_374 ) ;
V_69 -> V_315 = V_374 / 50 ;
F_123 ( V_9 , V_374 / 50 ) ;
return V_373 ;
}
static T_10
F_124 ( struct V_364 * V_365 ,
char T_11 * V_366 ,
T_4 V_367 ,
T_12 * V_368 )
{
struct V_8 * V_9 = V_365 -> V_369 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_370 [ 80 ] ;
T_5 V_376 ;
int V_371 ;
F_105 ( & V_69 -> V_9 -> V_75 ) ;
V_376 = F_29 ( V_377 ) ;
F_13 ( & V_69 -> V_9 -> V_75 ) ;
V_371 = snprintf ( V_370 , sizeof( V_370 ) ,
L_246 , ( V_376 & V_378 ) >>
V_379 ) ;
if ( V_371 > sizeof( V_370 ) )
V_371 = sizeof( V_370 ) ;
return F_114 ( V_366 , V_367 , V_368 , V_370 , V_371 ) ;
}
static T_10
F_125 ( struct V_364 * V_365 ,
const char T_11 * V_366 ,
T_4 V_373 ,
T_12 * V_368 )
{
struct V_8 * V_9 = V_365 -> V_369 ;
struct V_88 * V_69 = V_9 -> V_70 ;
char V_370 [ 20 ] ;
T_5 V_376 ;
int V_374 = 1 ;
if ( V_373 > 0 ) {
if ( V_373 > sizeof( V_370 ) - 1 )
return - V_87 ;
if ( F_116 ( V_370 , V_366 , V_373 ) )
return - V_375 ;
V_370 [ V_373 ] = 0 ;
V_374 = F_117 ( V_370 , NULL , 0 ) ;
}
if ( V_374 < 0 || V_374 > 3 )
return - V_87 ;
F_122 ( L_247 , V_374 ) ;
V_376 = F_29 ( V_377 ) ;
V_376 &= ~ V_378 ;
V_376 |= ( V_374 << V_379 ) ;
F_93 ( V_377 , V_376 ) ;
return V_373 ;
}
static int
F_126 ( struct V_380 * V_10 ,
struct V_381 * V_382 ,
const void * V_383 )
{
struct V_5 * V_6 ;
V_6 = F_127 ( sizeof( struct V_5 ) , V_384 ) ;
if ( V_6 == NULL ) {
F_128 ( V_382 ) ;
return - V_385 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_386 = V_382 ;
V_6 -> V_66 = ( void * ) V_383 ;
F_105 ( & V_10 -> V_387 ) ;
F_129 ( & V_6 -> V_65 , & V_10 -> V_388 ) ;
F_13 ( & V_10 -> V_387 ) ;
return 0 ;
}
static int F_130 ( struct V_389 * V_389 , struct V_364 * V_364 )
{
struct V_8 * V_9 = V_389 -> V_390 ;
struct V_88 * V_69 = V_9 -> V_70 ;
int V_74 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_65 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
int F_131 ( struct V_389 * V_389 , struct V_364 * V_364 )
{
struct V_8 * V_9 = V_389 -> V_390 ;
struct V_88 * V_69 = V_9 -> V_70 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_105 ( & V_9 -> V_75 ) ;
F_66 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_132 ( struct V_381 * V_391 , struct V_380 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_381 * V_382 ;
V_382 = F_133 ( L_248 ,
V_392 ,
V_391 , V_9 ,
& V_393 ) ;
if ( F_134 ( V_382 ) )
return F_135 ( V_382 ) ;
return F_126 ( V_10 , V_382 , & V_393 ) ;
}
static int F_136 ( struct V_381 * V_391 ,
struct V_380 * V_10 ,
const char * V_55 ,
const struct V_394 * V_395 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_381 * V_382 ;
V_382 = F_133 ( V_55 ,
V_396 | V_397 ,
V_391 , V_9 ,
V_395 ) ;
if ( F_134 ( V_382 ) )
return F_135 ( V_382 ) ;
return F_126 ( V_10 , V_382 , V_395 ) ;
}
int F_137 ( struct V_380 * V_10 )
{
int V_74 ;
V_74 = F_136 ( V_10 -> V_398 , V_10 ,
L_249 ,
& V_399 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_132 ( V_10 -> V_398 , V_10 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_136 ( V_10 -> V_398 , V_10 ,
L_250 ,
& V_400 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_136 ( V_10 -> V_398 , V_10 ,
L_251 ,
& V_401 ) ;
if ( V_74 )
return V_74 ;
return F_138 ( V_402 ,
V_403 ,
V_10 -> V_398 , V_10 ) ;
}
void F_139 ( struct V_380 * V_10 )
{
F_140 ( V_402 ,
V_403 , V_10 ) ;
F_140 ( (struct V_404 * ) & V_393 ,
1 , V_10 ) ;
F_140 ( (struct V_404 * ) & V_399 ,
1 , V_10 ) ;
F_140 ( (struct V_404 * ) & V_400 ,
1 , V_10 ) ;
F_140 ( (struct V_404 * ) & V_401 ,
1 , V_10 ) ;
}
