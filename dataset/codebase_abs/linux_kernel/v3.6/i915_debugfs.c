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
default:
F_13 ( & V_9 -> V_75 ) ;
return - V_83 ;
}
V_71 = V_72 = V_73 = 0 ;
F_14 (obj, head, mm_list) {
F_4 ( V_3 , L_25 ) ;
F_10 ( V_3 , V_35 ) ;
F_4 ( V_3 , L_26 ) ;
V_71 += V_35 -> V_45 . V_46 ;
V_72 += V_35 -> V_58 -> V_46 ;
V_73 ++ ;
}
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_27 ,
V_73 , V_71 , V_72 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_84 * V_69 = V_9 -> V_70 ;
T_5 V_73 , V_85 ;
T_4 V_46 , V_86 ;
struct V_34 * V_35 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_28 ,
V_69 -> V_77 . V_87 ,
V_69 -> V_77 . V_88 ) ;
V_46 = V_73 = V_86 = V_85 = 0 ;
F_16 ( & V_69 -> V_77 . V_89 , V_89 ) ;
F_4 ( V_3 , L_29 ,
V_73 , V_85 , V_46 , V_86 ) ;
V_46 = V_73 = V_86 = V_85 = 0 ;
F_16 ( & V_69 -> V_77 . V_78 , V_90 ) ;
F_16 ( & V_69 -> V_77 . V_82 , V_90 ) ;
F_4 ( V_3 , L_30 ,
V_73 , V_85 , V_46 , V_86 ) ;
V_46 = V_73 = V_86 = V_85 = 0 ;
F_16 ( & V_69 -> V_77 . V_80 , V_90 ) ;
F_4 ( V_3 , L_31 ,
V_73 , V_85 , V_46 , V_86 ) ;
V_46 = V_73 = V_86 = V_85 = 0 ;
F_14 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_35 -> V_61 ) {
V_46 += V_35 -> V_58 -> V_46 ;
++ V_73 ;
}
if ( V_35 -> V_60 ) {
V_86 += V_35 -> V_58 -> V_46 ;
++ V_85 ;
}
}
F_4 ( V_3 , L_32 ,
V_85 , V_86 ) ;
F_4 ( V_3 , L_33 ,
V_73 , V_46 ) ;
F_4 ( V_3 , L_34 ,
V_69 -> V_77 . V_91 , V_69 -> V_77 . V_92 ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_2 V_65 = ( T_2 ) V_6 -> V_66 -> V_4 ;
struct V_84 * V_69 = V_9 -> V_70 ;
struct V_34 * V_35 ;
T_4 V_71 , V_72 ;
int V_73 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_71 = V_72 = V_73 = 0 ;
F_14 (obj, &dev_priv->mm.gtt_list, gtt_list) {
if ( V_65 == V_93 && V_35 -> V_37 == 0 )
continue;
F_4 ( V_3 , L_25 ) ;
F_10 ( V_3 , V_35 ) ;
F_4 ( V_3 , L_26 ) ;
V_71 += V_35 -> V_45 . V_46 ;
V_72 += V_35 -> V_58 -> V_46 ;
V_73 ++ ;
}
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_27 ,
V_73 , V_71 , V_72 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
unsigned long V_94 ;
struct V_95 * V_96 ;
F_14 (crtc, &dev->mode_config.crtc_list, base.head) {
const char V_97 = F_19 ( V_96 -> V_97 ) ;
const char V_98 = F_20 ( V_96 -> V_98 ) ;
struct V_99 * V_100 ;
F_21 ( & V_9 -> V_101 , V_94 ) ;
V_100 = V_96 -> V_102 ;
if ( V_100 == NULL ) {
F_4 ( V_3 , L_35 ,
V_97 , V_98 ) ;
} else {
if ( ! V_100 -> V_103 ) {
F_4 ( V_3 , L_36 ,
V_97 , V_98 ) ;
} else {
F_4 ( V_3 , L_37 ,
V_97 , V_98 ) ;
}
if ( V_100 -> V_104 )
F_4 ( V_3 , L_38 ) ;
else
F_4 ( V_3 , L_39 ) ;
F_4 ( V_3 , L_40 , V_100 -> V_103 ) ;
if ( V_100 -> V_105 ) {
struct V_34 * V_35 = V_100 -> V_105 ;
if ( V_35 )
F_4 ( V_3 , L_41 , V_35 -> V_59 ) ;
}
if ( V_100 -> V_106 ) {
struct V_34 * V_35 = V_100 -> V_106 ;
if ( V_35 )
F_4 ( V_3 , L_42 , V_35 -> V_59 ) ;
}
}
F_22 ( & V_9 -> V_101 , V_94 ) ;
}
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_107 * V_108 ;
int V_74 , V_73 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_73 = 0 ;
if ( ! F_24 ( & V_69 -> V_64 [ V_109 ] . V_110 ) ) {
F_4 ( V_3 , L_43 ) ;
F_14 (gem_request,
&dev_priv->ring[RCS].request_list,
list) {
F_4 ( V_3 , L_44 ,
V_108 -> V_111 ,
( int ) ( V_112 - V_108 -> V_113 ) ) ;
}
V_73 ++ ;
}
if ( ! F_24 ( & V_69 -> V_64 [ V_114 ] . V_110 ) ) {
F_4 ( V_3 , L_45 ) ;
F_14 (gem_request,
&dev_priv->ring[VCS].request_list,
list) {
F_4 ( V_3 , L_44 ,
V_108 -> V_111 ,
( int ) ( V_112 - V_108 -> V_113 ) ) ;
}
V_73 ++ ;
}
if ( ! F_24 ( & V_69 -> V_64 [ V_115 ] . V_110 ) ) {
F_4 ( V_3 , L_46 ) ;
F_14 (gem_request,
&dev_priv->ring[BCS].request_list,
list) {
F_4 ( V_3 , L_44 ,
V_108 -> V_111 ,
( int ) ( V_112 - V_108 -> V_113 ) ) ;
}
V_73 ++ ;
}
F_13 ( & V_9 -> V_75 ) ;
if ( V_73 == 0 )
F_4 ( V_3 , L_47 ) ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_116 * V_64 )
{
if ( V_64 -> V_117 ) {
F_4 ( V_3 , L_48 ,
V_64 -> V_55 , V_64 -> V_117 ( V_64 ) ) ;
}
}
static int F_26 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 , V_118 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
F_25 ( V_3 , & V_69 -> V_64 [ V_118 ] ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 , V_118 , V_97 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
if ( F_28 ( V_9 ) ) {
F_4 ( V_3 , L_49 ,
F_29 ( V_120 ) ) ;
F_4 ( V_3 , L_50 ,
F_29 ( V_121 ) ) ;
F_4 ( V_3 , L_51 ,
F_29 ( V_122 ) ) ;
F_4 ( V_3 , L_52 ,
F_29 ( V_123 ) ) ;
F_30 (pipe)
F_4 ( V_3 , L_53 ,
F_19 ( V_97 ) ,
F_29 ( F_31 ( V_97 ) ) ) ;
F_4 ( V_3 , L_54 ,
F_29 ( V_124 ) ) ;
F_4 ( V_3 , L_55 ,
F_29 ( V_125 ) ) ;
F_4 ( V_3 , L_56 ,
F_29 ( V_126 ) ) ;
F_4 ( V_3 , L_57 ,
F_29 ( V_127 ) ) ;
F_4 ( V_3 , L_58 ,
F_29 ( V_128 ) ) ;
F_4 ( V_3 , L_59 ,
F_29 ( V_129 ) ) ;
F_4 ( V_3 , L_60 ,
F_29 ( V_130 ) ) ;
F_4 ( V_3 , L_61 ,
F_29 ( V_131 ) ) ;
F_4 ( V_3 , L_62 ,
F_29 ( V_132 ) ) ;
F_4 ( V_3 , L_63 ,
F_29 ( V_133 ) ) ;
} else if ( ! F_32 ( V_9 ) ) {
F_4 ( V_3 , L_64 ,
F_29 ( V_134 ) ) ;
F_4 ( V_3 , L_65 ,
F_29 ( V_135 ) ) ;
F_4 ( V_3 , L_66 ,
F_29 ( V_136 ) ) ;
F_30 (pipe)
F_4 ( V_3 , L_67 ,
F_19 ( V_97 ) ,
F_29 ( F_31 ( V_97 ) ) ) ;
} else {
F_4 ( V_3 , L_68 ,
F_29 ( V_137 ) ) ;
F_4 ( V_3 , L_69 ,
F_29 ( V_138 ) ) ;
F_4 ( V_3 , L_70 ,
F_29 ( V_139 ) ) ;
F_4 ( V_3 , L_71 ,
F_29 ( V_140 ) ) ;
F_4 ( V_3 , L_72 ,
F_29 ( V_141 ) ) ;
F_4 ( V_3 , L_73 ,
F_29 ( V_142 ) ) ;
F_4 ( V_3 , L_74 ,
F_29 ( V_125 ) ) ;
F_4 ( V_3 , L_75 ,
F_29 ( V_126 ) ) ;
F_4 ( V_3 , L_76 ,
F_29 ( V_127 ) ) ;
}
F_4 ( V_3 , L_77 ,
F_33 ( & V_69 -> V_143 ) ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
if ( F_34 ( V_9 ) || F_35 ( V_9 ) ) {
F_4 ( V_3 , L_78 ,
V_69 -> V_64 [ V_118 ] . V_55 ,
F_36 ( & V_69 -> V_64 [ V_118 ] ) ) ;
}
F_25 ( V_3 , & V_69 -> V_64 [ V_118 ] ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_118 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_79 , V_69 -> V_144 ) ;
F_4 ( V_3 , L_80 , V_69 -> V_145 ) ;
for ( V_118 = 0 ; V_118 < V_69 -> V_145 ; V_118 ++ ) {
struct V_34 * V_35 = V_69 -> V_146 [ V_118 ] . V_35 ;
F_4 ( V_3 , L_81 , V_118 ) ;
if ( V_35 == NULL )
F_4 ( V_3 , L_82 ) ;
else
F_10 ( V_3 , V_35 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_116 * V_64 ;
const volatile T_5 T_6 * V_147 ;
int V_118 ;
V_64 = & V_69 -> V_64 [ ( T_2 ) V_6 -> V_66 -> V_4 ] ;
V_147 = ( volatile T_5 T_6 * ) V_64 -> V_148 . V_149 ;
if ( V_147 == NULL )
return 0 ;
for ( V_118 = 0 ; V_118 < 4096 / sizeof( T_5 ) / 4 ; V_118 += 4 ) {
F_4 ( V_3 , L_83 ,
V_118 * 4 ,
V_147 [ V_118 ] , V_147 [ V_118 + 1 ] , V_147 [ V_118 + 2 ] , V_147 [ V_118 + 3 ] ) ;
}
return 0 ;
}
static const char * F_39 ( int V_64 )
{
switch ( V_64 ) {
case V_109 : return L_84 ;
case V_114 : return L_85 ;
case V_115 : return L_86 ;
default: return L_13 ;
}
}
static const char * F_40 ( int V_150 )
{
if ( V_150 > 0 )
return L_87 ;
else if ( V_150 < 0 )
return L_88 ;
else
return L_13 ;
}
static const char * F_41 ( int V_151 )
{
switch ( V_151 ) {
default:
case V_39 : return L_13 ;
case V_40 : return L_89 ;
case V_41 : return L_90 ;
}
}
static const char * F_42 ( int V_52 )
{
return V_52 ? L_15 : L_13 ;
}
static const char * F_43 ( int V_152 )
{
return V_152 ? L_16 : L_13 ;
}
static void F_44 ( struct V_2 * V_3 ,
const char * V_55 ,
struct V_153 * V_154 ,
int V_73 )
{
F_4 ( V_3 , L_91 , V_55 , V_73 ) ;
while ( V_73 -- ) {
F_4 ( V_3 , L_92 ,
V_154 -> V_59 ,
V_154 -> V_46 ,
V_154 -> V_47 ,
V_154 -> V_48 ,
V_154 -> V_111 ,
F_40 ( V_154 -> V_150 ) ,
F_41 ( V_154 -> V_151 ) ,
F_42 ( V_154 -> V_52 ) ,
F_43 ( V_154 -> V_152 ) ,
V_154 -> V_64 != - 1 ? L_7 : L_13 ,
F_39 ( V_154 -> V_64 ) ,
F_9 ( V_154 -> V_51 ) ) ;
if ( V_154 -> V_55 )
F_4 ( V_3 , L_17 , V_154 -> V_55 ) ;
if ( V_154 -> V_56 != V_57 )
F_4 ( V_3 , L_18 , V_154 -> V_56 ) ;
F_4 ( V_3 , L_26 ) ;
V_154 ++ ;
}
}
static void F_45 ( struct V_2 * V_3 ,
struct V_8 * V_9 ,
struct V_155 * error ,
unsigned V_64 )
{
F_46 ( V_64 >= V_119 ) ;
F_4 ( V_3 , L_93 , F_39 ( V_64 ) ) ;
F_4 ( V_3 , L_94 , error -> V_68 [ V_64 ] ) ;
F_4 ( V_3 , L_95 , error -> V_156 [ V_64 ] ) ;
F_4 ( V_3 , L_96 , error -> V_157 [ V_64 ] ) ;
F_4 ( V_3 , L_97 , error -> V_158 [ V_64 ] ) ;
F_4 ( V_3 , L_98 , error -> V_159 [ V_64 ] ) ;
F_4 ( V_3 , L_99 , error -> V_160 [ V_64 ] ) ;
if ( V_64 == V_109 && F_3 ( V_9 ) -> V_13 >= 4 ) {
F_4 ( V_3 , L_100 , error -> V_161 ) ;
F_4 ( V_3 , L_101 , error -> V_162 ) ;
}
if ( F_3 ( V_9 ) -> V_13 >= 4 )
F_4 ( V_3 , L_102 , error -> V_163 [ V_64 ] ) ;
F_4 ( V_3 , L_103 , error -> V_164 [ V_64 ] ) ;
F_4 ( V_3 , L_104 , error -> V_165 [ V_64 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_105 , error -> V_166 [ V_64 ] ) ;
F_4 ( V_3 , L_106 , error -> V_167 [ V_64 ] ) ;
F_4 ( V_3 , L_107 ,
error -> V_168 [ V_64 ] [ 0 ] ) ;
F_4 ( V_3 , L_108 ,
error -> V_168 [ V_64 ] [ 1 ] ) ;
}
F_4 ( V_3 , L_109 , error -> V_111 [ V_64 ] ) ;
F_4 ( V_3 , L_110 , F_1 ( error -> V_169 [ V_64 ] ) ) ;
F_4 ( V_3 , L_111 , error -> V_170 [ V_64 ] ) ;
F_4 ( V_3 , L_112 , error -> V_171 [ V_64 ] ) ;
}
static int F_47 ( struct V_2 * V_3 , void * V_172 )
{
struct V_173 * V_174 = V_3 -> V_7 ;
struct V_8 * V_9 = V_174 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_155 * error = V_174 -> error ;
struct V_116 * V_64 ;
int V_118 , V_175 , V_176 , V_177 , V_178 ;
if ( ! error ) {
F_4 ( V_3 , L_113 ) ;
return 0 ;
}
F_4 ( V_3 , L_114 , error -> time . V_179 ,
error -> time . V_180 ) ;
F_4 ( V_3 , L_115 , V_9 -> V_181 ) ;
F_4 ( V_3 , L_116 , error -> V_182 ) ;
F_4 ( V_3 , L_117 , error -> V_183 ) ;
F_4 ( V_3 , L_118 , error -> V_184 ) ;
F_4 ( V_3 , L_119 , error -> V_185 ) ;
for ( V_118 = 0 ; V_118 < V_69 -> V_145 ; V_118 ++ )
F_4 ( V_3 , L_120 , V_118 , error -> V_186 [ V_118 ] ) ;
if ( F_3 ( V_9 ) -> V_13 >= 6 ) {
F_4 ( V_3 , L_121 , error -> error ) ;
F_4 ( V_3 , L_122 , error -> V_187 ) ;
}
F_48 (ring, dev_priv, i)
F_45 ( V_3 , V_9 , error , V_118 ) ;
if ( error -> V_188 )
F_44 ( V_3 , L_123 ,
error -> V_188 ,
error -> V_189 ) ;
if ( error -> V_190 )
F_44 ( V_3 , L_124 ,
error -> V_190 ,
error -> V_191 ) ;
for ( V_118 = 0 ; V_118 < F_49 ( error -> V_64 ) ; V_118 ++ ) {
struct V_192 * V_35 ;
if ( ( V_35 = error -> V_64 [ V_118 ] . V_193 ) ) {
F_4 ( V_3 , L_125 ,
V_69 -> V_64 [ V_118 ] . V_55 ,
V_35 -> V_59 ) ;
V_177 = 0 ;
for ( V_176 = 0 ; V_176 < V_35 -> V_194 ; V_176 ++ ) {
for ( V_178 = 0 ; V_178 < V_195 / 4 ; V_178 ++ ) {
F_4 ( V_3 , L_126 , V_177 , V_35 -> V_196 [ V_176 ] [ V_178 ] ) ;
V_177 += 4 ;
}
}
}
if ( error -> V_64 [ V_118 ] . V_197 ) {
F_4 ( V_3 , L_127 ,
V_69 -> V_64 [ V_118 ] . V_55 ,
error -> V_64 [ V_118 ] . V_197 ) ;
for ( V_175 = 0 ; V_175 < error -> V_64 [ V_118 ] . V_197 ; V_175 ++ ) {
F_4 ( V_3 , L_128 ,
error -> V_64 [ V_118 ] . V_198 [ V_175 ] . V_111 ,
error -> V_64 [ V_118 ] . V_198 [ V_175 ] . V_112 ,
error -> V_64 [ V_118 ] . V_198 [ V_175 ] . V_156 ) ;
}
}
if ( ( V_35 = error -> V_64 [ V_118 ] . V_199 ) ) {
F_4 ( V_3 , L_129 ,
V_69 -> V_64 [ V_118 ] . V_55 ,
V_35 -> V_59 ) ;
V_177 = 0 ;
for ( V_176 = 0 ; V_176 < V_35 -> V_194 ; V_176 ++ ) {
for ( V_178 = 0 ; V_178 < V_195 / 4 ; V_178 ++ ) {
F_4 ( V_3 , L_126 ,
V_177 ,
V_35 -> V_196 [ V_176 ] [ V_178 ] ) ;
V_177 += 4 ;
}
}
}
}
if ( error -> V_200 )
F_50 ( V_3 , error -> V_200 ) ;
if ( error -> V_201 )
F_51 ( V_3 , V_9 , error -> V_201 ) ;
return 0 ;
}
static T_7
F_52 ( struct V_202 * V_203 ,
const char T_8 * V_204 ,
T_4 V_205 ,
T_9 * V_206 )
{
struct V_2 * V_3 = V_203 -> V_207 ;
struct V_173 * V_174 = V_3 -> V_7 ;
struct V_8 * V_9 = V_174 -> V_9 ;
F_53 ( L_130 ) ;
F_54 ( & V_9 -> V_75 ) ;
F_55 ( V_9 ) ;
F_13 ( & V_9 -> V_75 ) ;
return V_205 ;
}
static int F_56 ( struct V_208 * V_208 , struct V_202 * V_202 )
{
struct V_8 * V_9 = V_208 -> V_209 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_173 * V_174 ;
unsigned long V_94 ;
V_174 = F_57 ( sizeof( * V_174 ) , V_210 ) ;
if ( ! V_174 )
return - V_211 ;
V_174 -> V_9 = V_9 ;
F_21 ( & V_69 -> V_212 , V_94 ) ;
V_174 -> error = V_69 -> V_213 ;
if ( V_174 -> error )
F_58 ( & V_174 -> error -> V_214 ) ;
F_22 ( & V_69 -> V_212 , V_94 ) ;
return F_59 ( V_202 , F_47 , V_174 ) ;
}
static int F_60 ( struct V_208 * V_208 , struct V_202 * V_202 )
{
struct V_2 * V_3 = V_202 -> V_207 ;
struct V_173 * V_174 = V_3 -> V_7 ;
if ( V_174 -> error )
F_61 ( & V_174 -> error -> V_214 , V_215 ) ;
F_62 ( V_174 ) ;
return F_63 ( V_208 , V_202 ) ;
}
static int F_64 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_10 V_216 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_216 = F_65 ( V_217 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_131 , ( V_216 >> 8 ) & 0x3f , ( V_216 & 0x3f ) ) ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
if ( F_67 ( V_9 ) ) {
T_10 V_218 = F_65 ( V_219 ) ;
T_10 V_220 = F_65 ( V_221 ) ;
F_4 ( V_3 , L_132 , ( V_218 >> 8 ) & 0xf ) ;
F_4 ( V_3 , L_133 , V_218 & 0x3f ) ;
F_4 ( V_3 , L_134 , ( V_220 & V_222 ) >>
V_223 ) ;
F_4 ( V_3 , L_135 ,
( V_220 & V_224 ) >> V_225 ) ;
} else if ( F_34 ( V_9 ) || F_35 ( V_9 ) ) {
T_5 V_226 = F_29 ( V_227 ) ;
T_5 V_228 = F_29 ( V_229 ) ;
T_5 V_230 = F_29 ( V_231 ) ;
T_5 V_232 ;
T_5 V_233 , V_234 , V_235 ;
T_5 V_236 , V_237 , V_238 ;
int V_239 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_68 ( V_69 ) ;
V_232 = F_29 ( V_240 ) ;
V_233 = F_29 ( V_241 ) ;
V_234 = F_29 ( V_242 ) ;
V_235 = F_29 ( V_243 ) ;
V_236 = F_29 ( V_244 ) ;
V_237 = F_29 ( V_245 ) ;
V_238 = F_29 ( V_246 ) ;
F_69 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_136 , V_226 ) ;
F_4 ( V_3 , L_137 , V_232 ) ;
F_4 ( V_3 , L_138 ,
( V_226 & 0xff00 ) >> 8 ) ;
F_4 ( V_3 , L_139 ,
V_226 & 0xff ) ;
F_4 ( V_3 , L_140 ,
V_228 & 0xff ) ;
F_4 ( V_3 , L_141 , ( ( V_232 & V_247 ) >>
V_248 ) * 50 ) ;
F_4 ( V_3 , L_142 , V_233 &
V_249 ) ;
F_4 ( V_3 , L_143 , V_234 &
V_250 ) ;
F_4 ( V_3 , L_144 , V_235 &
V_250 ) ;
F_4 ( V_3 , L_145 , V_236 &
V_251 ) ;
F_4 ( V_3 , L_146 , V_237 &
V_250 ) ;
F_4 ( V_3 , L_147 , V_238 &
V_250 ) ;
V_239 = ( V_230 & 0xff0000 ) >> 16 ;
F_4 ( V_3 , L_148 ,
V_239 * 50 ) ;
V_239 = ( V_230 & 0xff00 ) >> 8 ;
F_4 ( V_3 , L_149 ,
V_239 * 50 ) ;
V_239 = V_230 & 0xff ;
F_4 ( V_3 , L_150 ,
V_239 * 50 ) ;
} else {
F_4 ( V_3 , L_151 ) ;
}
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_5 V_252 ;
int V_74 , V_118 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
for ( V_118 = 0 ; V_118 < 16 ; V_118 ++ ) {
V_252 = F_29 ( V_253 + V_118 * 4 ) ;
F_4 ( V_3 , L_152 , V_118 , V_252 ,
( V_252 & V_254 ) >> V_255 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static inline int F_71 ( int V_256 )
{
return 1250 - ( V_256 * 25 ) ;
}
static int F_72 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_5 V_257 ;
int V_74 , V_118 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
for ( V_118 = 1 ; V_118 <= 32 ; V_118 ++ ) {
V_257 = F_29 ( V_258 + V_118 * 4 ) ;
F_4 ( V_3 , L_153 , V_118 , V_257 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
T_5 V_259 , V_260 ;
T_10 V_261 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_259 = F_29 ( V_262 ) ;
V_260 = F_29 ( V_263 ) ;
V_261 = F_65 ( V_217 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_154 , ( V_259 & V_264 ) ?
L_1 : L_2 ) ;
F_4 ( V_3 , L_155 ,
( V_259 & V_265 ) >>
V_266 ) ;
F_4 ( V_3 , L_156 ,
V_259 & V_267 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_157 ,
V_259 & V_268 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_158 ,
V_259 & V_269 ? L_1 : L_2 ) ;
F_4 ( V_3 , L_159 ,
( V_259 & V_270 ) >> V_271 ) ;
F_4 ( V_3 , L_160 ,
( V_259 & V_272 ) >> V_273 ) ;
F_4 ( V_3 , L_161 , ( V_259 & V_274 ) ) ;
F_4 ( V_3 , L_162 , ( V_261 & 0x3f ) ) ;
F_4 ( V_3 , L_163 , ( ( V_261 >> 8 ) & 0x3f ) ) ;
F_4 ( V_3 , L_164 ,
( V_260 & V_275 ) ? L_2 : L_1 ) ;
F_4 ( V_3 , L_165 ) ;
switch ( V_260 & V_276 ) {
case V_277 :
F_4 ( V_3 , L_166 ) ;
break;
case V_278 :
F_4 ( V_3 , L_167 ) ;
break;
case V_279 :
F_4 ( V_3 , L_168 ) ;
break;
case V_280 :
F_4 ( V_3 , L_169 ) ;
break;
case V_281 :
F_4 ( V_3 , L_170 ) ;
break;
case V_282 :
F_4 ( V_3 , L_171 ) ;
break;
default:
F_4 ( V_3 , L_172 ) ;
break;
}
return 0 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_84 * V_69 = V_9 -> V_70 ;
T_5 V_283 , V_284 , V_285 ;
unsigned V_286 ;
int V_73 = 0 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_75 ( & V_69 -> V_287 ) ;
V_286 = V_69 -> V_286 ;
F_76 ( & V_69 -> V_287 ) ;
if ( V_286 ) {
F_4 ( V_3 , L_173
L_174 ) ;
} else {
while ( V_73 ++ < 50 && ( F_77 ( V_288 ) & 1 ) )
F_78 ( 10 ) ;
F_4 ( V_3 , L_175 , F_1 ( V_73 < 51 ) ) ;
}
V_284 = F_79 ( V_69 -> V_289 + V_290 ) ;
F_80 ( false , V_290 , V_284 , 4 ) ;
V_283 = F_29 ( V_291 ) ;
V_285 = F_29 ( V_292 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_176 ,
F_1 ( V_283 & V_293 ) ) ;
F_4 ( V_3 , L_156 ,
F_1 ( V_283 & V_294 ) ) ;
F_4 ( V_3 , L_157 ,
F_1 ( ( V_283 & V_295 ) ==
V_296 ) ) ;
F_4 ( V_3 , L_177 ,
F_1 ( V_285 & V_297 ) ) ;
F_4 ( V_3 , L_178 ,
F_1 ( V_285 & V_298 ) ) ;
F_4 ( V_3 , L_179 ,
F_1 ( V_285 & V_299 ) ) ;
F_4 ( V_3 , L_180 ,
F_1 ( V_285 & V_300 ) ) ;
F_4 ( V_3 , L_181 ) ;
switch ( V_284 & V_301 ) {
case V_302 :
if ( V_284 & V_303 )
F_4 ( V_3 , L_182 ) ;
else
F_4 ( V_3 , L_166 ) ;
break;
case V_304 :
F_4 ( V_3 , L_183 ) ;
break;
case V_305 :
F_4 ( V_3 , L_184 ) ;
break;
case V_306 :
F_4 ( V_3 , L_185 ) ;
break;
default:
F_4 ( V_3 , L_186 ) ;
break;
}
F_4 ( V_3 , L_187 ,
F_1 ( V_284 & V_303 ) ) ;
F_4 ( V_3 , L_188 ,
F_29 ( V_307 ) ) ;
F_4 ( V_3 , L_189 ,
F_29 ( V_308 ) ) ;
F_4 ( V_3 , L_190 ,
F_29 ( V_309 ) ) ;
F_4 ( V_3 , L_191 ,
F_29 ( V_310 ) ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
if ( F_34 ( V_9 ) || F_35 ( V_9 ) )
return F_74 ( V_3 ) ;
else
return F_73 ( V_3 ) ;
}
static int F_82 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
if ( ! F_83 ( V_9 ) ) {
F_4 ( V_3 , L_192 ) ;
return 0 ;
}
if ( F_84 ( V_9 ) ) {
F_4 ( V_3 , L_193 ) ;
} else {
F_4 ( V_3 , L_194 ) ;
switch ( V_69 -> V_311 ) {
case V_312 :
F_4 ( V_3 , L_195 ) ;
break;
case V_313 :
F_4 ( V_3 , L_196 ) ;
break;
case V_314 :
F_4 ( V_3 , L_197 ) ;
break;
case V_315 :
F_4 ( V_3 , L_198 ) ;
break;
case V_316 :
F_4 ( V_3 , L_199 ) ;
break;
case V_317 :
F_4 ( V_3 , L_200 ) ;
break;
case V_318 :
F_4 ( V_3 , L_201 ) ;
break;
case V_319 :
F_4 ( V_3 , L_202 ) ;
break;
default:
F_4 ( V_3 , L_203 ) ;
}
F_4 ( V_3 , L_26 ) ;
}
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
bool V_320 = false ;
if ( F_32 ( V_9 ) )
V_320 = F_29 ( V_321 ) & V_322 ;
else if ( F_86 ( V_9 ) || F_87 ( V_9 ) || F_88 ( V_9 ) )
V_320 = F_29 ( V_323 ) & V_324 ;
else if ( F_89 ( V_9 ) )
V_320 = F_29 ( V_325 ) & V_326 ;
else if ( F_90 ( V_9 ) )
V_320 = F_29 ( V_327 ) & V_328 ;
F_4 ( V_3 , L_204 ,
V_320 ? L_205 : L_206 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
unsigned long V_329 , V_330 , V_331 ;
int V_74 ;
if ( ! F_67 ( V_9 ) )
return - V_332 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
V_329 = F_92 ( V_69 ) ;
V_330 = F_93 ( V_69 ) ;
V_331 = F_94 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_207 , V_329 ) ;
F_4 ( V_3 , L_208 , V_330 ) ;
F_4 ( V_3 , L_209 , V_331 ) ;
F_4 ( V_3 , L_210 , V_330 + V_331 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
int V_333 , V_334 ;
if ( ! ( F_34 ( V_9 ) || F_35 ( V_9 ) ) ) {
F_4 ( V_3 , L_211 ) ;
return 0 ;
}
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_212 ) ;
for ( V_333 = V_69 -> V_335 ; V_333 <= V_69 -> V_336 ;
V_333 ++ ) {
F_96 ( V_337 , V_333 ) ;
F_96 ( V_338 , V_339 |
V_340 ) ;
if ( F_97 ( ( F_29 ( V_338 ) &
V_339 ) == 0 , 10 ) ) {
F_98 ( L_213 ) ;
continue;
}
V_334 = F_29 ( V_337 ) ;
F_4 ( V_3 , L_214 , V_333 * 50 , V_334 * 100 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_215 , ( unsigned long ) F_29 ( 0x112f4 ) ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_100 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_341 * V_342 = & V_69 -> V_342 ;
void * V_4 = F_101 ( V_343 , V_210 ) ;
int V_74 ;
if ( V_4 == NULL )
return - V_211 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
goto V_344;
if ( V_342 -> V_345 ) {
F_102 ( V_4 , V_342 -> V_345 , V_343 ) ;
F_103 ( V_3 , V_4 , V_343 ) ;
}
F_13 ( & V_9 -> V_75 ) ;
V_344:
F_62 ( V_4 ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
struct V_346 * V_347 ;
struct V_348 * V_349 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_350 . V_351 ) ;
if ( V_74 )
return V_74 ;
V_347 = V_69 -> V_352 ;
V_349 = F_105 ( V_347 -> V_353 . V_349 ) ;
F_4 ( V_3 , L_216 ,
V_349 -> V_45 . V_354 ,
V_349 -> V_45 . V_355 ,
V_349 -> V_45 . V_356 ,
V_349 -> V_45 . V_357 ) ;
F_10 ( V_3 , V_349 -> V_35 ) ;
F_4 ( V_3 , L_26 ) ;
F_14 (fb, &dev->mode_config.fb_list, base.head) {
if ( & V_349 -> V_45 == V_347 -> V_353 . V_349 )
continue;
F_4 ( V_3 , L_217 ,
V_349 -> V_45 . V_354 ,
V_349 -> V_45 . V_355 ,
V_349 -> V_45 . V_356 ,
V_349 -> V_45 . V_357 ) ;
F_10 ( V_3 , V_349 -> V_35 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_13 ( & V_9 -> V_350 . V_351 ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 , void * V_172 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
T_3 * V_69 = V_9 -> V_70 ;
int V_74 ;
V_74 = F_12 ( & V_9 -> V_350 . V_351 ) ;
if ( V_74 )
return V_74 ;
if ( V_69 -> V_358 ) {
F_4 ( V_3 , L_218 ) ;
F_10 ( V_3 , V_69 -> V_358 ) ;
F_4 ( V_3 , L_26 ) ;
}
if ( V_69 -> V_359 ) {
F_4 ( V_3 , L_219 ) ;
F_10 ( V_3 , V_69 -> V_359 ) ;
F_4 ( V_3 , L_26 ) ;
}
F_13 ( & V_9 -> V_350 . V_351 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_84 * V_69 = V_9 -> V_70 ;
unsigned V_286 ;
F_75 ( & V_69 -> V_287 ) ;
V_286 = V_69 -> V_286 ;
F_76 ( & V_69 -> V_287 ) ;
F_4 ( V_3 , L_220 , V_286 ) ;
return 0 ;
}
static const char * F_108 ( unsigned V_360 )
{
switch( V_360 ) {
case V_361 :
return L_221 ;
case V_362 :
return L_222 ;
case V_363 :
return L_223 ;
case V_364 :
return L_224 ;
case V_365 :
return L_225 ;
case V_366 :
return L_226 ;
case V_367 :
return L_227 ;
case V_368 :
return L_228 ;
}
return L_229 ;
}
static int F_109 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_84 * V_69 = V_9 -> V_70 ;
F_54 ( & V_9 -> V_75 ) ;
F_4 ( V_3 , L_230 ,
F_108 ( V_69 -> V_77 . V_369 ) ) ;
F_4 ( V_3 , L_231 ,
F_108 ( V_69 -> V_77 . V_370 ) ) ;
if ( F_110 ( V_9 ) || F_111 ( V_9 ) ) {
F_4 ( V_3 , L_232 ,
F_29 ( V_371 ) ) ;
F_4 ( V_3 , L_233 ,
F_65 ( V_372 ) ) ;
F_4 ( V_3 , L_234 ,
F_65 ( V_373 ) ) ;
} else if ( F_34 ( V_9 ) || F_35 ( V_9 ) ) {
F_4 ( V_3 , L_235 ,
F_29 ( V_374 ) ) ;
F_4 ( V_3 , L_236 ,
F_29 ( V_375 ) ) ;
F_4 ( V_3 , L_237 ,
F_29 ( V_376 ) ) ;
F_4 ( V_3 , L_238 ,
F_29 ( V_377 ) ) ;
F_4 ( V_3 , L_239 ,
F_29 ( V_378 ) ) ;
F_4 ( V_3 , L_240 ,
F_29 ( V_379 ) ) ;
}
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_112 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_84 * V_69 = V_9 -> V_70 ;
struct V_116 * V_64 ;
int V_118 , V_74 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
if ( F_3 ( V_9 ) -> V_13 == 6 )
F_4 ( V_3 , L_241 , F_29 ( V_380 ) ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
V_64 = & V_69 -> V_64 [ V_118 ] ;
F_4 ( V_3 , L_242 , V_64 -> V_55 ) ;
if ( F_3 ( V_9 ) -> V_13 == 7 )
F_4 ( V_3 , L_241 , F_29 ( F_113 ( V_64 ) ) ) ;
F_4 ( V_3 , L_243 , F_29 ( F_114 ( V_64 ) ) ) ;
F_4 ( V_3 , L_244 , F_29 ( F_115 ( V_64 ) ) ) ;
F_4 ( V_3 , L_245 , F_29 ( F_116 ( V_64 ) ) ) ;
}
if ( V_69 -> V_77 . V_381 ) {
struct V_382 * V_383 = V_69 -> V_77 . V_381 ;
F_4 ( V_3 , L_246 ) ;
F_4 ( V_3 , L_247 , V_383 -> V_384 ) ;
}
F_4 ( V_3 , L_248 , F_29 ( V_385 ) ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 -> V_9 ;
struct V_84 * V_69 = V_9 -> V_70 ;
int V_74 ;
if ( ! F_28 ( V_9 ) ) {
F_4 ( V_3 , L_249 ) ;
return 0 ;
}
V_74 = F_12 ( & V_9 -> V_350 . V_351 ) ;
if ( V_74 )
return V_74 ;
F_4 ( V_3 , L_250 , F_29 ( V_386 ) ) ;
F_4 ( V_3 , L_251 ,
F_118 ( V_69 , V_387 ) ) ;
F_4 ( V_3 , L_252 ,
F_118 ( V_69 , V_388 ) ) ;
F_4 ( V_3 , L_253 ,
F_118 ( V_69 , V_389 ) ) ;
F_4 ( V_3 , L_254 ,
F_118 ( V_69 , V_390 ) ) ;
F_4 ( V_3 , L_255 ,
F_118 ( V_69 , V_391 ) ) ;
F_4 ( V_3 , L_256 ,
F_118 ( V_69 , V_392 ) ) ;
F_4 ( V_3 , L_257 ,
F_118 ( V_69 , V_393 ) ) ;
F_4 ( V_3 , L_258 ,
F_118 ( V_69 , V_394 ) ) ;
F_4 ( V_3 , L_259 ,
F_118 ( V_69 , V_395 ) ) ;
F_13 ( & V_9 -> V_350 . V_351 ) ;
return 0 ;
}
static T_7
F_119 ( struct V_202 * V_203 ,
char T_8 * V_204 ,
T_4 V_396 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_397 [ 80 ] ;
int V_398 ;
V_398 = snprintf ( V_397 , sizeof( V_397 ) ,
L_260 ,
F_33 ( & V_69 -> V_77 . V_399 ) ) ;
if ( V_398 > sizeof( V_397 ) )
V_398 = sizeof( V_397 ) ;
return F_120 ( V_204 , V_396 , V_206 , V_397 , V_398 ) ;
}
static T_7
F_121 ( struct V_202 * V_203 ,
const char T_8 * V_204 ,
T_4 V_205 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
char V_397 [ 20 ] ;
int V_400 = 1 ;
if ( V_205 > 0 ) {
if ( V_205 > sizeof( V_397 ) - 1 )
return - V_83 ;
if ( F_122 ( V_397 , V_204 , V_205 ) )
return - V_401 ;
V_397 [ V_205 ] = 0 ;
V_400 = F_123 ( V_397 , NULL , 0 ) ;
}
F_124 ( L_261 , V_400 ) ;
F_125 ( V_9 , V_400 ) ;
return V_205 ;
}
static T_7
F_126 ( struct V_202 * V_203 ,
char T_8 * V_204 ,
T_4 V_396 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_397 [ 20 ] ;
int V_398 ;
V_398 = snprintf ( V_397 , sizeof( V_397 ) ,
L_262 , V_69 -> V_402 ) ;
if ( V_398 > sizeof( V_397 ) )
V_398 = sizeof( V_397 ) ;
return F_120 ( V_204 , V_396 , V_206 , V_397 , V_398 ) ;
}
static T_7
F_127 ( struct V_202 * V_203 ,
const char T_8 * V_204 ,
T_4 V_205 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
struct V_84 * V_69 = V_9 -> V_70 ;
char V_397 [ 20 ] ;
int V_400 = 0 ;
if ( V_205 > 0 ) {
if ( V_205 > sizeof( V_397 ) - 1 )
return - V_83 ;
if ( F_122 ( V_397 , V_204 , V_205 ) )
return - V_401 ;
V_397 [ V_205 ] = 0 ;
V_400 = F_123 ( V_397 , NULL , 0 ) ;
}
F_53 ( L_263 , V_400 ) ;
F_54 ( & V_9 -> V_75 ) ;
V_69 -> V_402 = V_400 ;
F_13 ( & V_9 -> V_75 ) ;
return V_205 ;
}
static T_7
F_128 ( struct V_202 * V_203 ,
char T_8 * V_204 ,
T_4 V_396 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_397 [ 80 ] ;
int V_398 ;
V_398 = snprintf ( V_397 , sizeof( V_397 ) ,
L_264 , V_69 -> V_336 * 50 ) ;
if ( V_398 > sizeof( V_397 ) )
V_398 = sizeof( V_397 ) ;
return F_120 ( V_204 , V_396 , V_206 , V_397 , V_398 ) ;
}
static T_7
F_129 ( struct V_202 * V_203 ,
const char T_8 * V_204 ,
T_4 V_205 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
struct V_84 * V_69 = V_9 -> V_70 ;
char V_397 [ 20 ] ;
int V_400 = 1 ;
if ( V_205 > 0 ) {
if ( V_205 > sizeof( V_397 ) - 1 )
return - V_83 ;
if ( F_122 ( V_397 , V_204 , V_205 ) )
return - V_401 ;
V_397 [ V_205 ] = 0 ;
V_400 = F_123 ( V_397 , NULL , 0 ) ;
}
F_53 ( L_265 , V_400 ) ;
V_69 -> V_336 = V_400 / 50 ;
F_130 ( V_9 , V_400 / 50 ) ;
return V_205 ;
}
static T_7
F_131 ( struct V_202 * V_203 , char T_8 * V_204 , T_4 V_396 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_397 [ 80 ] ;
int V_398 ;
V_398 = snprintf ( V_397 , sizeof( V_397 ) ,
L_266 , V_69 -> V_335 * 50 ) ;
if ( V_398 > sizeof( V_397 ) )
V_398 = sizeof( V_397 ) ;
return F_120 ( V_204 , V_396 , V_206 , V_397 , V_398 ) ;
}
static T_7
F_132 ( struct V_202 * V_203 , const char T_8 * V_204 , T_4 V_205 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
struct V_84 * V_69 = V_9 -> V_70 ;
char V_397 [ 20 ] ;
int V_400 = 1 ;
if ( V_205 > 0 ) {
if ( V_205 > sizeof( V_397 ) - 1 )
return - V_83 ;
if ( F_122 ( V_397 , V_204 , V_205 ) )
return - V_401 ;
V_397 [ V_205 ] = 0 ;
V_400 = F_123 ( V_397 , NULL , 0 ) ;
}
F_53 ( L_267 , V_400 ) ;
V_69 -> V_335 = V_400 / 50 ;
F_130 ( V_9 , V_400 / 50 ) ;
return V_205 ;
}
static T_7
F_133 ( struct V_202 * V_203 ,
char T_8 * V_204 ,
T_4 V_396 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
T_3 * V_69 = V_9 -> V_70 ;
char V_397 [ 80 ] ;
T_5 V_403 ;
int V_398 ;
F_54 ( & V_69 -> V_9 -> V_75 ) ;
V_403 = F_29 ( V_404 ) ;
F_13 ( & V_69 -> V_9 -> V_75 ) ;
V_398 = snprintf ( V_397 , sizeof( V_397 ) ,
L_268 , ( V_403 & V_405 ) >>
V_406 ) ;
if ( V_398 > sizeof( V_397 ) )
V_398 = sizeof( V_397 ) ;
return F_120 ( V_204 , V_396 , V_206 , V_397 , V_398 ) ;
}
static T_7
F_134 ( struct V_202 * V_203 ,
const char T_8 * V_204 ,
T_4 V_205 ,
T_9 * V_206 )
{
struct V_8 * V_9 = V_203 -> V_207 ;
struct V_84 * V_69 = V_9 -> V_70 ;
char V_397 [ 20 ] ;
T_5 V_403 ;
int V_400 = 1 ;
if ( V_205 > 0 ) {
if ( V_205 > sizeof( V_397 ) - 1 )
return - V_83 ;
if ( F_122 ( V_397 , V_204 , V_205 ) )
return - V_401 ;
V_397 [ V_205 ] = 0 ;
V_400 = F_123 ( V_397 , NULL , 0 ) ;
}
if ( V_400 < 0 || V_400 > 3 )
return - V_83 ;
F_53 ( L_269 , V_400 ) ;
V_403 = F_29 ( V_404 ) ;
V_403 &= ~ V_405 ;
V_403 |= ( V_400 << V_406 ) ;
F_96 ( V_404 , V_403 ) ;
return V_205 ;
}
static int
F_135 ( struct V_407 * V_10 ,
struct V_408 * V_409 ,
const void * V_410 )
{
struct V_5 * V_6 ;
V_6 = F_101 ( sizeof( struct V_5 ) , V_210 ) ;
if ( V_6 == NULL ) {
F_136 ( V_409 ) ;
return - V_211 ;
}
V_6 -> V_10 = V_10 ;
V_6 -> V_411 = V_409 ;
V_6 -> V_66 = ( void * ) V_410 ;
F_54 ( & V_10 -> V_412 ) ;
F_137 ( & V_6 -> V_65 , & V_10 -> V_413 ) ;
F_13 ( & V_10 -> V_412 ) ;
return 0 ;
}
static int F_138 ( struct V_208 * V_208 , struct V_202 * V_202 )
{
struct V_8 * V_9 = V_208 -> V_209 ;
struct V_84 * V_69 = V_9 -> V_70 ;
int V_74 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
V_74 = F_12 ( & V_9 -> V_75 ) ;
if ( V_74 )
return V_74 ;
F_68 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_139 ( struct V_208 * V_208 , struct V_202 * V_202 )
{
struct V_8 * V_9 = V_208 -> V_209 ;
struct V_84 * V_69 = V_9 -> V_70 ;
if ( F_3 ( V_9 ) -> V_13 < 6 )
return 0 ;
F_54 ( & V_9 -> V_75 ) ;
F_69 ( V_69 ) ;
F_13 ( & V_9 -> V_75 ) ;
return 0 ;
}
static int F_140 ( struct V_408 * V_414 , struct V_407 * V_10 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_408 * V_409 ;
V_409 = F_141 ( L_270 ,
V_415 ,
V_414 , V_9 ,
& V_416 ) ;
if ( F_142 ( V_409 ) )
return F_143 ( V_409 ) ;
return F_135 ( V_10 , V_409 , & V_416 ) ;
}
static int F_144 ( struct V_408 * V_414 ,
struct V_407 * V_10 ,
const char * V_55 ,
const struct V_417 * V_418 )
{
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_408 * V_409 ;
V_409 = F_141 ( V_55 ,
V_419 | V_420 ,
V_414 , V_9 ,
V_418 ) ;
if ( F_142 ( V_409 ) )
return F_143 ( V_409 ) ;
return F_135 ( V_10 , V_409 , V_418 ) ;
}
int F_145 ( struct V_407 * V_10 )
{
int V_74 ;
V_74 = F_144 ( V_10 -> V_421 , V_10 ,
L_271 ,
& V_422 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_140 ( V_10 -> V_421 , V_10 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_144 ( V_10 -> V_421 , V_10 ,
L_272 ,
& V_423 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_144 ( V_10 -> V_421 , V_10 ,
L_273 ,
& V_424 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_144 ( V_10 -> V_421 , V_10 ,
L_274 ,
& V_425 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_144 ( V_10 -> V_421 , V_10 ,
L_275 ,
& V_426 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_144 ( V_10 -> V_421 , V_10 ,
L_276 ,
& V_427 ) ;
if ( V_74 )
return V_74 ;
return F_146 ( V_428 ,
V_429 ,
V_10 -> V_421 , V_10 ) ;
}
void F_147 ( struct V_407 * V_10 )
{
F_148 ( V_428 ,
V_429 , V_10 ) ;
F_148 ( (struct V_430 * ) & V_416 ,
1 , V_10 ) ;
F_148 ( (struct V_430 * ) & V_422 ,
1 , V_10 ) ;
F_148 ( (struct V_430 * ) & V_423 ,
1 , V_10 ) ;
F_148 ( (struct V_430 * ) & V_424 ,
1 , V_10 ) ;
F_148 ( (struct V_430 * ) & V_425 ,
1 , V_10 ) ;
F_148 ( (struct V_430 * ) & V_426 ,
1 , V_10 ) ;
F_148 ( (struct V_430 * ) & V_427 ,
1 , V_10 ) ;
}
