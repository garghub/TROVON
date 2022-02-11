int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_7 ;
F_2 (connector, &dev->mode_config.connector_list, head) {
struct V_8 * V_9 ;
V_9 = F_3 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 )
goto V_11;
V_9 -> V_6 = V_6 ;
V_2 -> V_12 [ V_2 -> V_13 ++ ] = V_9 ;
}
return 0 ;
V_11:
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
F_4 ( V_2 -> V_12 [ V_7 ] ) ;
V_2 -> V_12 [ V_7 ] = NULL ;
}
V_2 -> V_13 = 0 ;
return - V_14 ;
}
int F_5 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_8 * * V_15 ;
struct V_8 * V_9 ;
F_6 ( ! F_7 ( & V_2 -> V_4 -> V_16 . V_17 ) ) ;
if ( V_2 -> V_13 + 1 > V_2 -> V_18 ) {
V_15 = F_8 ( V_2 -> V_12 , sizeof( struct V_8 ) * ( V_2 -> V_13 + 1 ) , V_10 ) ;
if ( ! V_15 )
return - V_14 ;
V_2 -> V_18 = V_2 -> V_13 + 1 ;
V_2 -> V_12 = V_15 ;
}
V_9 = F_3 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 )
return - V_14 ;
V_9 -> V_6 = V_6 ;
V_2 -> V_12 [ V_2 -> V_13 ++ ] = V_9 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int V_7 , V_19 ;
F_6 ( ! F_7 ( & V_2 -> V_4 -> V_16 . V_17 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_2 -> V_12 [ V_7 ] -> V_6 == V_6 )
break;
}
if ( V_7 == V_2 -> V_13 )
return - V_20 ;
V_9 = V_2 -> V_12 [ V_7 ] ;
for ( V_19 = V_7 + 1 ; V_19 < V_2 -> V_13 ; V_19 ++ ) {
V_2 -> V_12 [ V_19 - 1 ] = V_2 -> V_12 [ V_19 ] ;
}
V_2 -> V_13 -- ;
F_4 ( V_9 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_21 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_22 * V_23 ;
struct V_5 * V_6 ;
char * V_24 = NULL ;
V_21 = V_2 -> V_12 [ V_7 ] ;
V_6 = V_21 -> V_6 ;
V_23 = & V_21 -> V_25 ;
if ( F_11 ( V_6 -> V_26 , & V_24 ) )
continue;
if ( F_12 ( V_24 ,
V_6 ,
V_23 ) ) {
if ( V_23 -> V_27 ) {
const char * V_28 ;
switch ( V_23 -> V_27 ) {
case V_29 :
V_28 = L_1 ;
break;
case V_30 :
V_28 = L_2 ;
break;
default:
case V_31 :
V_28 = L_3 ;
break;
}
F_13 ( L_4 ,
V_6 -> V_26 , V_28 ) ;
V_6 -> V_27 = V_23 -> V_27 ;
}
F_14 ( L_5 ,
V_6 -> V_26 ,
V_23 -> V_32 , V_23 -> V_33 ,
V_23 -> V_34 ? V_23 -> V_35 : 60 ,
V_23 -> V_36 ? L_6 : L_7 ,
V_23 -> V_37 ? L_8 : L_7 ,
V_23 -> V_38 ? L_9 : L_7 ) ;
}
}
return 0 ;
}
static void F_15 ( struct V_39 * V_40 , struct V_1 * V_41 )
{
T_1 * V_42 , * V_43 , * V_44 ;
int V_7 ;
if ( V_41 -> V_45 -> V_46 == NULL )
return;
V_42 = V_40 -> V_47 ;
V_43 = V_42 + V_40 -> V_48 ;
V_44 = V_43 + V_40 -> V_48 ;
for ( V_7 = 0 ; V_7 < V_40 -> V_48 ; V_7 ++ )
V_41 -> V_45 -> V_46 ( V_40 , & V_42 [ V_7 ] , & V_43 [ V_7 ] , & V_44 [ V_7 ] , V_7 ) ;
}
static void F_16 ( struct V_39 * V_40 )
{
T_1 * V_42 , * V_43 , * V_44 ;
if ( V_40 -> V_45 -> V_49 == NULL )
return;
V_42 = V_40 -> V_47 ;
V_43 = V_42 + V_40 -> V_48 ;
V_44 = V_43 + V_40 -> V_48 ;
V_40 -> V_45 -> V_49 ( V_40 , V_42 , V_43 , V_44 , 0 , V_40 -> V_48 ) ;
}
int F_17 ( struct V_50 * V_51 )
{
struct V_1 * V_41 = V_51 -> V_52 ;
struct V_53 * V_45 ;
int V_7 ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_41 -> V_54 ; V_7 ++ ) {
struct V_55 * V_56 =
& V_41 -> V_57 [ V_7 ] . V_56 ;
if ( ! V_56 -> V_40 -> V_58 )
continue;
V_45 = V_56 -> V_40 -> V_59 ;
F_15 ( V_56 -> V_40 , V_41 ) ;
V_45 -> V_60 ( V_56 -> V_40 ,
V_56 -> V_61 ,
V_56 -> V_62 ,
V_56 -> V_63 ,
V_64 ) ;
}
}
return 0 ;
}
static struct V_65 * F_18 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_4 ;
struct V_39 * V_66 ;
F_2 (c, &dev->mode_config.crtc_list, head) {
if ( V_40 -> V_67 . V_68 == V_66 -> V_67 . V_68 )
return V_66 -> V_69 -> V_61 ;
}
return NULL ;
}
int F_19 ( struct V_50 * V_51 )
{
struct V_1 * V_41 = V_51 -> V_52 ;
struct V_39 * V_40 ;
struct V_53 * V_45 ;
struct V_65 * V_61 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_41 -> V_54 ; V_7 ++ ) {
struct V_55 * V_56 = & V_41 -> V_57 [ V_7 ] . V_56 ;
V_40 = V_56 -> V_40 ;
V_45 = V_40 -> V_59 ;
V_61 = F_18 ( V_40 ) ;
if ( ! V_40 -> V_58 )
continue;
if ( ! V_61 ) {
F_20 ( L_10 ) ;
continue;
}
F_16 ( V_56 -> V_40 ) ;
V_45 -> V_60 ( V_56 -> V_40 , V_61 , V_40 -> V_62 ,
V_40 -> V_63 , V_70 ) ;
}
return 0 ;
}
static bool F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_71 * V_72 ;
bool error = false ;
int V_7 ;
F_22 ( V_4 ) ;
F_2 (plane, &dev->mode_config.plane_list, head)
if ( V_72 -> type != V_73 )
F_23 ( V_72 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ ) {
struct V_55 * V_56 = & V_2 -> V_57 [ V_7 ] . V_56 ;
struct V_39 * V_40 = V_56 -> V_40 ;
int V_74 ;
if ( V_40 -> V_45 -> V_75 ) {
V_74 = V_40 -> V_45 -> V_75 ( V_40 , NULL , 0 , 0 , 0 ) ;
if ( V_74 )
error = true ;
}
V_74 = F_24 ( V_56 ) ;
if ( V_74 )
error = true ;
}
return error ;
}
static bool F_25 ( struct V_1 * V_2 )
{
return F_21 ( V_2 ) ;
}
bool F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_74 ;
F_27 ( V_4 ) ;
V_74 = F_21 ( V_2 ) ;
F_28 ( V_4 ) ;
return V_74 ;
}
static bool F_29 ( void )
{
bool V_74 , error = false ;
struct V_1 * V_41 ;
if ( F_30 ( & V_76 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_41 -> V_4 ;
if ( V_4 -> V_77 == V_78 )
continue;
if ( ! F_31 ( & V_4 -> V_16 . V_17 ) ) {
error = true ;
continue;
}
V_74 = F_25 ( V_41 ) ;
if ( V_74 )
error = true ;
F_32 ( & V_4 -> V_16 . V_17 ) ;
}
return error ;
}
static int F_33 ( struct V_79 * V_80 , unsigned long V_81 ,
void * V_82 )
{
if ( V_83 < 0 )
return 0 ;
F_34 ( L_11 ) ;
return F_29 () ;
}
static bool F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_39 * V_40 ;
int V_84 = 0 , V_85 = 0 ;
if ( V_4 -> V_69 -> V_86 )
return false ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_40 -> V_69 -> V_61 )
V_85 ++ ;
if ( V_40 -> V_69 -> V_61 == V_2 -> V_61 )
V_84 ++ ;
}
if ( V_84 < V_85 )
return false ;
return true ;
}
static void F_36 ( struct V_87 * V_88 )
{
bool V_74 ;
V_74 = F_29 () ;
if ( V_74 == true )
F_20 ( L_12 ) ;
}
static void F_37 ( int V_89 )
{
F_38 ( & V_90 ) ;
}
static void F_39 ( struct V_50 * V_51 , int V_91 )
{
struct V_1 * V_2 = V_51 -> V_52 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_39 * V_40 ;
struct V_5 * V_6 ;
int V_7 , V_19 ;
if ( V_92 )
return;
F_27 ( V_4 ) ;
if ( ! F_35 ( V_2 ) ) {
F_28 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ ) {
V_40 = V_2 -> V_57 [ V_7 ] . V_56 . V_40 ;
if ( ! V_40 -> V_58 )
continue;
for ( V_19 = 0 ; V_19 < V_2 -> V_13 ; V_19 ++ ) {
V_6 = V_2 -> V_12 [ V_19 ] -> V_6 ;
V_6 -> V_45 -> V_93 ( V_6 , V_91 ) ;
F_40 ( & V_6 -> V_67 ,
V_4 -> V_16 . V_94 , V_91 ) ;
}
}
F_28 ( V_4 ) ;
}
int F_41 ( int V_95 , struct V_50 * V_51 )
{
switch ( V_95 ) {
case V_96 :
F_39 ( V_51 , V_97 ) ;
break;
case V_98 :
F_39 ( V_51 , V_99 ) ;
break;
case V_100 :
F_39 ( V_51 , V_99 ) ;
break;
case V_101 :
F_39 ( V_51 , V_102 ) ;
break;
case V_103 :
F_39 ( V_51 , V_104 ) ;
break;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_41 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_41 -> V_13 ; V_7 ++ )
F_4 ( V_41 -> V_12 [ V_7 ] ) ;
F_4 ( V_41 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_41 -> V_54 ; V_7 ++ ) {
F_4 ( V_41 -> V_57 [ V_7 ] . V_56 . V_105 ) ;
if ( V_41 -> V_57 [ V_7 ] . V_56 . V_23 )
F_43 ( V_41 -> V_4 , V_41 -> V_57 [ V_7 ] . V_56 . V_23 ) ;
}
F_4 ( V_41 -> V_57 ) ;
}
void F_44 ( struct V_3 * V_4 , struct V_1 * V_41 ,
const struct V_106 * V_45 )
{
F_45 ( & V_41 -> V_107 ) ;
V_41 -> V_45 = V_45 ;
V_41 -> V_4 = V_4 ;
}
int F_46 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_54 , int V_108 )
{
struct V_39 * V_40 ;
int V_7 ;
if ( ! V_108 )
return - V_20 ;
V_2 -> V_57 = F_47 ( V_54 , sizeof( struct V_109 ) , V_10 ) ;
if ( ! V_2 -> V_57 )
return - V_14 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_12 = F_47 ( V_4 -> V_16 . V_110 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_57 ) ;
return - V_14 ;
}
V_2 -> V_18 = V_4 -> V_16 . V_110 ;
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_54 ; V_7 ++ ) {
V_2 -> V_57 [ V_7 ] . V_56 . V_105 =
F_47 ( V_108 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_57 [ V_7 ] . V_56 . V_105 )
goto V_111;
V_2 -> V_57 [ V_7 ] . V_56 . V_112 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_57 [ V_7 ] . V_56 . V_40 = V_40 ;
V_7 ++ ;
}
return 0 ;
V_111:
F_42 ( V_2 ) ;
return - V_14 ;
}
void F_48 ( struct V_1 * V_2 )
{
if ( ! F_30 ( & V_2 -> V_107 ) ) {
F_49 ( & V_2 -> V_107 ) ;
if ( F_30 ( & V_76 ) ) {
F_50 ( L_13 ) ;
F_51 ( & V_113 ,
& V_114 ) ;
F_52 ( 'v' , & V_115 ) ;
}
}
F_42 ( V_2 ) ;
}
static int F_53 ( struct V_39 * V_40 , T_2 V_116 , T_2 V_117 ,
T_2 V_118 , T_2 V_119 , struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_52 ;
struct V_65 * V_61 = V_2 -> V_61 ;
int V_120 ;
if ( V_51 -> V_121 . V_122 == V_123 ) {
T_3 * V_124 ;
T_3 V_125 ;
if ( V_119 > 16 )
return - V_20 ;
V_124 = ( T_3 * ) V_51 -> V_126 ;
V_116 >>= ( 16 - V_51 -> V_127 . V_116 . V_128 ) ;
V_117 >>= ( 16 - V_51 -> V_127 . V_117 . V_128 ) ;
V_118 >>= ( 16 - V_51 -> V_127 . V_118 . V_128 ) ;
V_125 = ( V_116 << V_51 -> V_127 . V_116 . V_129 ) |
( V_117 << V_51 -> V_127 . V_117 . V_129 ) |
( V_118 << V_51 -> V_127 . V_118 . V_129 ) ;
if ( V_51 -> V_127 . V_130 . V_128 > 0 ) {
T_3 V_131 = ( 1 << V_51 -> V_127 . V_130 . V_128 ) - 1 ;
V_131 <<= V_51 -> V_127 . V_130 . V_129 ;
V_125 |= V_131 ;
}
V_124 [ V_119 ] = V_125 ;
return 0 ;
}
if ( F_6 ( ! V_2 -> V_45 -> V_49 ||
! V_2 -> V_45 -> V_46 ) )
return - V_20 ;
V_120 = V_119 ;
if ( V_61 -> V_132 == 16 ) {
V_120 = V_119 << 3 ;
if ( V_61 -> V_133 == 16 && V_119 > 63 )
return - V_20 ;
if ( V_61 -> V_133 == 15 && V_119 > 31 )
return - V_20 ;
if ( V_61 -> V_133 == 16 ) {
T_2 V_134 , V_135 , V_136 ;
int V_7 ;
if ( V_119 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_45 -> V_49 ( V_40 , V_116 ,
V_117 , V_118 , V_120 + V_7 ) ;
}
V_2 -> V_45 -> V_46 ( V_40 , & V_134 ,
& V_135 , & V_136 ,
V_120 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_45 -> V_49 ( V_40 , V_134 ,
V_117 , V_136 ,
( V_120 >> 1 ) + V_7 ) ;
}
}
if ( V_61 -> V_133 != 16 )
V_2 -> V_45 -> V_49 ( V_40 , V_116 , V_117 , V_118 , V_120 ) ;
return 0 ;
}
int F_54 ( struct V_137 * V_138 , struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_52 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_53 * V_139 ;
T_2 * V_116 , * V_117 , * V_118 , * V_130 ;
struct V_39 * V_40 ;
int V_7 , V_19 , V_140 = 0 ;
int V_141 ;
F_27 ( V_4 ) ;
if ( ! F_35 ( V_2 ) ) {
F_28 ( V_4 ) ;
return - V_142 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ ) {
V_40 = V_2 -> V_57 [ V_7 ] . V_56 . V_40 ;
V_139 = V_40 -> V_59 ;
V_116 = V_138 -> V_116 ;
V_117 = V_138 -> V_117 ;
V_118 = V_138 -> V_118 ;
V_130 = V_138 -> V_130 ;
V_141 = V_138 -> V_141 ;
for ( V_19 = 0 ; V_19 < V_138 -> V_143 ; V_19 ++ ) {
T_2 V_144 , V_145 , V_146 , V_147 = 0xffff ;
V_144 = * V_116 ++ ;
V_145 = * V_117 ++ ;
V_146 = * V_118 ++ ;
if ( V_130 )
V_147 = * V_130 ++ ;
V_140 = F_53 ( V_40 , V_144 , V_145 , V_146 , V_141 ++ , V_51 ) ;
if ( V_140 )
goto V_148;
}
if ( V_139 -> V_149 )
V_139 -> V_149 ( V_40 ) ;
}
V_148:
F_28 ( V_4 ) ;
return V_140 ;
}
int F_55 ( struct V_150 * V_127 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_52 ;
struct V_65 * V_61 = V_2 -> V_61 ;
int V_133 ;
if ( V_127 -> V_151 != 0 || F_56 () )
return - V_20 ;
if ( V_127 -> V_132 > V_61 -> V_132 ||
V_127 -> V_32 > V_61 -> V_152 || V_127 -> V_33 > V_61 -> V_153 ||
V_127 -> V_154 > V_61 -> V_152 || V_127 -> V_155 > V_61 -> V_153 ) {
F_57 ( L_14
L_15 ,
V_127 -> V_32 , V_127 -> V_33 , V_127 -> V_132 ,
V_127 -> V_154 , V_127 -> V_155 ,
V_61 -> V_152 , V_61 -> V_153 , V_61 -> V_132 ) ;
return - V_20 ;
}
switch ( V_127 -> V_132 ) {
case 16 :
V_133 = ( V_127 -> V_117 . V_128 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_133 = ( V_127 -> V_130 . V_128 > 0 ) ? 32 : 24 ;
break;
default:
V_133 = V_127 -> V_132 ;
break;
}
switch ( V_133 ) {
case 8 :
V_127 -> V_116 . V_129 = 0 ;
V_127 -> V_117 . V_129 = 0 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 8 ;
V_127 -> V_117 . V_128 = 8 ;
V_127 -> V_118 . V_128 = 8 ;
V_127 -> V_130 . V_128 = 0 ;
V_127 -> V_130 . V_129 = 0 ;
break;
case 15 :
V_127 -> V_116 . V_129 = 10 ;
V_127 -> V_117 . V_129 = 5 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 5 ;
V_127 -> V_117 . V_128 = 5 ;
V_127 -> V_118 . V_128 = 5 ;
V_127 -> V_130 . V_128 = 1 ;
V_127 -> V_130 . V_129 = 15 ;
break;
case 16 :
V_127 -> V_116 . V_129 = 11 ;
V_127 -> V_117 . V_129 = 5 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 5 ;
V_127 -> V_117 . V_128 = 6 ;
V_127 -> V_118 . V_128 = 5 ;
V_127 -> V_130 . V_128 = 0 ;
V_127 -> V_130 . V_129 = 0 ;
break;
case 24 :
V_127 -> V_116 . V_129 = 16 ;
V_127 -> V_117 . V_129 = 8 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 8 ;
V_127 -> V_117 . V_128 = 8 ;
V_127 -> V_118 . V_128 = 8 ;
V_127 -> V_130 . V_128 = 0 ;
V_127 -> V_130 . V_129 = 0 ;
break;
case 32 :
V_127 -> V_116 . V_129 = 16 ;
V_127 -> V_117 . V_129 = 8 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 8 ;
V_127 -> V_117 . V_128 = 8 ;
V_127 -> V_118 . V_128 = 8 ;
V_127 -> V_130 . V_128 = 8 ;
V_127 -> V_130 . V_129 = 24 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
int F_58 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_52 ;
struct V_150 * V_127 = & V_51 -> V_127 ;
if ( V_127 -> V_151 != 0 ) {
F_20 ( L_16 ) ;
return - V_20 ;
}
F_26 ( V_2 ) ;
if ( V_2 -> V_156 ) {
V_2 -> V_156 = false ;
F_59 ( V_2 ) ;
}
return 0 ;
}
int F_60 ( struct V_150 * V_127 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = V_51 -> V_52 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_55 * V_157 ;
int V_74 = 0 ;
int V_7 ;
F_27 ( V_4 ) ;
if ( ! F_35 ( V_2 ) ) {
F_28 ( V_4 ) ;
return - V_142 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ ) {
V_157 = & V_2 -> V_57 [ V_7 ] . V_56 ;
V_157 -> V_62 = V_127 -> V_158 ;
V_157 -> V_63 = V_127 -> V_159 ;
if ( V_157 -> V_112 ) {
V_74 = F_24 ( V_157 ) ;
if ( ! V_74 ) {
V_51 -> V_127 . V_158 = V_127 -> V_158 ;
V_51 -> V_127 . V_159 = V_127 -> V_159 ;
}
}
}
F_28 ( V_4 ) ;
return V_74 ;
}
static int F_61 ( struct V_1 * V_2 ,
int V_160 )
{
int V_74 = 0 ;
int V_54 = 0 ;
int V_7 ;
struct V_50 * V_51 ;
struct V_161 V_162 ;
int V_48 = 0 ;
memset ( & V_162 , 0 , sizeof( struct V_161 ) ) ;
V_162 . V_163 = 24 ;
V_162 . V_164 = 32 ;
V_162 . V_165 = ( unsigned ) - 1 ;
V_162 . V_166 = ( unsigned ) - 1 ;
if ( V_160 != V_162 . V_164 )
V_162 . V_163 = V_162 . V_164 = V_160 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_21 = V_2 -> V_12 [ V_7 ] ;
struct V_22 * V_25 ;
V_25 = & V_21 -> V_25 ;
if ( V_25 -> V_167 ) {
switch ( V_25 -> V_168 ) {
case 8 :
V_162 . V_163 = V_162 . V_164 = 8 ;
break;
case 15 :
V_162 . V_163 = 15 ;
V_162 . V_164 = 16 ;
break;
case 16 :
V_162 . V_163 = V_162 . V_164 = 16 ;
break;
case 24 :
V_162 . V_163 = V_162 . V_164 = 24 ;
break;
case 32 :
V_162 . V_163 = 24 ;
V_162 . V_164 = 32 ;
break;
}
break;
}
}
V_54 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ ) {
struct V_169 * V_170 ;
V_170 = V_2 -> V_57 [ V_7 ] . V_170 ;
if ( V_170 ) {
if ( V_48 == 0 )
V_48 = V_2 -> V_57 [ V_7 ] . V_56 . V_40 -> V_48 ;
if ( V_170 -> V_171 < V_162 . V_165 )
V_162 . V_165 = V_170 -> V_171 ;
if ( V_170 -> V_172 < V_162 . V_166 )
V_162 . V_166 = V_170 -> V_172 ;
if ( V_170 -> V_171 > V_162 . V_173 )
V_162 . V_173 = V_170 -> V_171 ;
if ( V_170 -> V_172 > V_162 . V_174 )
V_162 . V_174 = V_170 -> V_172 ;
V_54 ++ ;
}
}
if ( V_54 == 0 || V_162 . V_165 == - 1 || V_162 . V_166 == - 1 ) {
F_13 ( L_17 ) ;
V_162 . V_165 = V_162 . V_173 = 1024 ;
V_162 . V_166 = V_162 . V_174 = 768 ;
}
V_74 = (* V_2 -> V_45 -> V_175 )( V_2 , & V_162 ) ;
if ( V_74 < 0 )
return V_74 ;
V_51 = V_2 -> V_176 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ )
if ( V_2 -> V_57 [ V_7 ] . V_56 . V_112 )
V_2 -> V_57 [ V_7 ] . V_56 . V_61 = V_2 -> V_61 ;
V_51 -> V_127 . V_151 = 0 ;
if ( F_62 ( V_51 ) < 0 )
return - V_20 ;
F_63 ( V_2 -> V_4 -> V_4 , L_18 ,
V_51 -> V_177 , V_51 -> V_121 . V_68 ) ;
if ( F_30 ( & V_76 ) ) {
F_63 ( V_2 -> V_4 -> V_4 , L_19 ) ;
F_64 ( & V_113 ,
& V_114 ) ;
F_65 ( 'v' , & V_115 ) ;
}
F_66 ( & V_2 -> V_107 , & V_76 ) ;
return 0 ;
}
void F_67 ( struct V_50 * V_51 , T_4 V_178 ,
T_4 V_133 )
{
V_51 -> V_121 . type = V_179 ;
V_51 -> V_121 . V_122 = V_133 == 8 ? V_180 :
V_123 ;
V_51 -> V_121 . V_181 = 0 ;
V_51 -> V_121 . V_182 = 0 ;
V_51 -> V_121 . V_183 = 0 ;
V_51 -> V_121 . V_184 = 1 ;
V_51 -> V_121 . V_185 = 1 ;
V_51 -> V_121 . V_186 = 0 ;
V_51 -> V_121 . V_187 = V_188 ;
V_51 -> V_121 . V_189 = V_178 ;
return;
}
void F_68 ( struct V_50 * V_51 , struct V_1 * V_2 ,
T_4 V_165 , T_4 V_166 )
{
struct V_65 * V_61 = V_2 -> V_61 ;
V_51 -> V_126 = V_2 -> V_126 ;
V_51 -> V_127 . V_154 = V_61 -> V_152 ;
V_51 -> V_127 . V_155 = V_61 -> V_153 ;
V_51 -> V_127 . V_132 = V_61 -> V_132 ;
V_51 -> V_127 . V_190 = V_191 ;
V_51 -> V_127 . V_158 = 0 ;
V_51 -> V_127 . V_159 = 0 ;
V_51 -> V_127 . V_192 = V_193 ;
V_51 -> V_127 . V_153 = - 1 ;
V_51 -> V_127 . V_152 = - 1 ;
switch ( V_61 -> V_133 ) {
case 8 :
V_51 -> V_127 . V_116 . V_129 = 0 ;
V_51 -> V_127 . V_117 . V_129 = 0 ;
V_51 -> V_127 . V_118 . V_129 = 0 ;
V_51 -> V_127 . V_116 . V_128 = 8 ;
V_51 -> V_127 . V_117 . V_128 = 8 ;
V_51 -> V_127 . V_118 . V_128 = 8 ;
V_51 -> V_127 . V_130 . V_129 = 0 ;
V_51 -> V_127 . V_130 . V_128 = 0 ;
break;
case 15 :
V_51 -> V_127 . V_116 . V_129 = 10 ;
V_51 -> V_127 . V_117 . V_129 = 5 ;
V_51 -> V_127 . V_118 . V_129 = 0 ;
V_51 -> V_127 . V_116 . V_128 = 5 ;
V_51 -> V_127 . V_117 . V_128 = 5 ;
V_51 -> V_127 . V_118 . V_128 = 5 ;
V_51 -> V_127 . V_130 . V_129 = 15 ;
V_51 -> V_127 . V_130 . V_128 = 1 ;
break;
case 16 :
V_51 -> V_127 . V_116 . V_129 = 11 ;
V_51 -> V_127 . V_117 . V_129 = 5 ;
V_51 -> V_127 . V_118 . V_129 = 0 ;
V_51 -> V_127 . V_116 . V_128 = 5 ;
V_51 -> V_127 . V_117 . V_128 = 6 ;
V_51 -> V_127 . V_118 . V_128 = 5 ;
V_51 -> V_127 . V_130 . V_129 = 0 ;
break;
case 24 :
V_51 -> V_127 . V_116 . V_129 = 16 ;
V_51 -> V_127 . V_117 . V_129 = 8 ;
V_51 -> V_127 . V_118 . V_129 = 0 ;
V_51 -> V_127 . V_116 . V_128 = 8 ;
V_51 -> V_127 . V_117 . V_128 = 8 ;
V_51 -> V_127 . V_118 . V_128 = 8 ;
V_51 -> V_127 . V_130 . V_129 = 0 ;
V_51 -> V_127 . V_130 . V_128 = 0 ;
break;
case 32 :
V_51 -> V_127 . V_116 . V_129 = 16 ;
V_51 -> V_127 . V_117 . V_129 = 8 ;
V_51 -> V_127 . V_118 . V_129 = 0 ;
V_51 -> V_127 . V_116 . V_128 = 8 ;
V_51 -> V_127 . V_117 . V_128 = 8 ;
V_51 -> V_127 . V_118 . V_128 = 8 ;
V_51 -> V_127 . V_130 . V_129 = 24 ;
V_51 -> V_127 . V_130 . V_128 = 8 ;
break;
default:
break;
}
V_51 -> V_127 . V_32 = V_165 ;
V_51 -> V_127 . V_33 = V_166 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_4 V_194 ,
T_4 V_195 )
{
struct V_5 * V_6 ;
int V_196 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_196 += V_6 -> V_45 -> V_197 ( V_6 , V_194 , V_195 ) ;
}
return V_196 ;
}
struct V_169 * F_70 ( struct V_8 * V_198 , int V_152 , int V_153 )
{
struct V_169 * V_23 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( V_23 -> V_171 > V_152 ||
V_23 -> V_172 > V_153 )
continue;
if ( V_23 -> type & V_199 )
return V_23 ;
}
return NULL ;
}
static bool F_71 ( struct V_8 * V_198 )
{
struct V_22 * V_25 ;
V_25 = & V_198 -> V_25 ;
return V_25 -> V_200 ;
}
struct V_169 * F_72 ( struct V_8 * V_21 ,
int V_152 , int V_153 )
{
struct V_22 * V_25 ;
struct V_169 * V_23 = NULL ;
bool V_201 ;
V_25 = & V_21 -> V_25 ;
if ( V_25 -> V_200 == false )
return V_23 ;
if ( V_25 -> V_36 || V_25 -> V_37 )
goto V_202;
V_201 = ! V_25 -> V_38 ;
V_203:
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_23 -> V_171 != V_25 -> V_32 ||
V_23 -> V_172 != V_25 -> V_33 )
continue;
if ( V_25 -> V_34 ) {
if ( V_23 -> V_204 != V_25 -> V_35 )
continue;
}
if ( V_25 -> V_38 ) {
if ( ! ( V_23 -> V_205 & V_206 ) )
continue;
} else if ( V_201 ) {
if ( V_23 -> V_205 & V_206 )
continue;
}
return V_23 ;
}
if ( V_201 ) {
V_201 = false ;
goto V_203;
}
V_202:
V_23 = F_73 ( V_21 -> V_6 -> V_4 ,
V_25 ) ;
F_66 ( & V_23 -> V_207 , & V_21 -> V_6 -> V_208 ) ;
return V_23 ;
}
static bool F_74 ( struct V_5 * V_6 , bool V_209 )
{
bool V_210 ;
if ( V_209 )
V_210 = V_6 -> V_211 == V_212 ;
else
V_210 = V_6 -> V_211 != V_213 ;
return V_210 ;
}
static void F_75 ( struct V_1 * V_2 ,
bool * V_58 )
{
bool V_214 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_58 [ V_7 ] = F_74 ( V_6 , true ) ;
F_14 ( L_20 , V_6 -> V_67 . V_68 ,
V_58 [ V_7 ] ? L_21 : L_22 ) ;
V_214 |= V_58 [ V_7 ] ;
}
if ( V_214 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_58 [ V_7 ] = F_74 ( V_6 , false ) ;
}
}
static bool F_76 ( struct V_1 * V_2 ,
struct V_169 * * V_208 ,
bool * V_58 , int V_152 , int V_153 )
{
int V_196 , V_7 , V_19 ;
bool V_215 = false ;
struct V_8 * V_21 ;
struct V_169 * V_216 , * V_23 ;
if ( V_2 -> V_54 > 1 )
return false ;
V_196 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_58 [ V_7 ] )
V_196 ++ ;
}
if ( V_196 <= 1 )
return false ;
V_215 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_58 [ V_7 ] )
continue;
V_21 = V_2 -> V_12 [ V_7 ] ;
V_208 [ V_7 ] = F_72 ( V_21 , V_152 , V_153 ) ;
if ( ! V_208 [ V_7 ] ) {
V_215 = false ;
break;
}
for ( V_19 = 0 ; V_19 < V_7 ; V_19 ++ ) {
if ( ! V_58 [ V_19 ] )
continue;
if ( ! F_77 ( V_208 [ V_19 ] , V_208 [ V_7 ] ) )
V_215 = false ;
}
}
if ( V_215 ) {
F_14 ( L_23 ) ;
return true ;
}
V_215 = true ;
V_216 = F_78 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_58 [ V_7 ] )
continue;
V_21 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_77 ( V_23 , V_216 ) )
V_208 [ V_7 ] = V_23 ;
}
if ( ! V_208 [ V_7 ] )
V_215 = false ;
}
if ( V_215 ) {
F_14 ( L_24 ) ;
return true ;
}
F_13 ( L_25 ) ;
return false ;
}
static bool F_79 ( struct V_1 * V_2 ,
struct V_169 * * V_208 ,
bool * V_58 , int V_152 , int V_153 )
{
struct V_8 * V_21 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_21 = V_2 -> V_12 [ V_7 ] ;
if ( V_58 [ V_7 ] == false )
continue;
F_14 ( L_26 ,
V_21 -> V_6 -> V_67 . V_68 ) ;
V_208 [ V_7 ] = F_72 ( V_21 , V_152 , V_153 ) ;
if ( ! V_208 [ V_7 ] ) {
F_14 ( L_27 ,
V_21 -> V_6 -> V_67 . V_68 ) ;
V_208 [ V_7 ] = F_70 ( V_21 , V_152 , V_153 ) ;
}
if ( ! V_208 [ V_7 ] && ! F_30 ( & V_21 -> V_6 -> V_208 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_14 ( L_28 , V_208 [ V_7 ] ? V_208 [ V_7 ] -> V_26 :
L_29 ) ;
}
return true ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_109 * * V_217 ,
struct V_169 * * V_208 ,
int V_80 , int V_152 , int V_153 )
{
int V_66 , V_218 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_219 * V_220 ;
struct V_221 * V_222 ;
int V_223 , V_224 , V_225 ;
struct V_109 * * V_226 , * V_40 ;
struct V_8 * V_21 ;
if ( V_80 == V_2 -> V_13 )
return 0 ;
V_21 = V_2 -> V_12 [ V_80 ] ;
V_6 = V_21 -> V_6 ;
V_217 [ V_80 ] = NULL ;
V_224 = F_80 ( V_2 , V_217 , V_208 , V_80 + 1 , V_152 , V_153 ) ;
if ( V_208 [ V_80 ] == NULL )
return V_224 ;
V_226 = F_3 ( V_4 -> V_16 . V_110 *
sizeof( struct V_109 * ) , V_10 ) ;
if ( ! V_226 )
return V_224 ;
V_223 = 1 ;
if ( V_6 -> V_211 == V_212 )
V_223 ++ ;
if ( F_71 ( V_21 ) )
V_223 ++ ;
if ( F_70 ( V_21 , V_152 , V_153 ) )
V_223 ++ ;
V_220 = V_6 -> V_59 ;
V_222 = V_220 -> V_227 ( V_6 ) ;
if ( ! V_222 )
goto V_148;
for ( V_66 = 0 ; V_66 < V_2 -> V_54 ; V_66 ++ ) {
V_40 = & V_2 -> V_57 [ V_66 ] ;
if ( ( V_222 -> V_228 & ( 1 << V_66 ) ) == 0 )
continue;
for ( V_218 = 0 ; V_218 < V_80 ; V_218 ++ )
if ( V_217 [ V_218 ] == V_40 )
break;
if ( V_218 < V_80 ) {
if ( V_2 -> V_54 > 1 )
continue;
if ( ! F_77 ( V_208 [ V_218 ] , V_208 [ V_80 ] ) )
continue;
}
V_226 [ V_80 ] = V_40 ;
memcpy ( V_226 , V_217 , V_80 * sizeof( struct V_109 * ) ) ;
V_225 = V_223 + F_80 ( V_2 , V_226 , V_208 , V_80 + 1 ,
V_152 , V_153 ) ;
if ( V_225 > V_224 ) {
V_224 = V_225 ;
memcpy ( V_217 , V_226 ,
V_4 -> V_16 . V_110 *
sizeof( struct V_109 * ) ) ;
}
}
V_148:
F_4 ( V_226 ) ;
return V_224 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_109 * * V_226 ;
struct V_169 * * V_208 ;
struct V_55 * V_157 ;
bool * V_58 ;
int V_152 , V_153 ;
int V_7 ;
F_14 ( L_30 ) ;
V_152 = V_4 -> V_16 . V_229 ;
V_153 = V_4 -> V_16 . V_230 ;
V_226 = F_47 ( V_4 -> V_16 . V_110 ,
sizeof( struct V_109 * ) , V_10 ) ;
V_208 = F_47 ( V_4 -> V_16 . V_110 ,
sizeof( struct V_169 * ) , V_10 ) ;
V_58 = F_47 ( V_4 -> V_16 . V_110 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_226 || ! V_208 || ! V_58 ) {
F_20 ( L_31 ) ;
goto V_148;
}
F_75 ( V_2 , V_58 ) ;
if ( ! ( V_2 -> V_45 -> V_231 &&
V_2 -> V_45 -> V_231 ( V_2 , V_226 , V_208 ,
V_58 , V_152 , V_153 ) ) ) {
memset ( V_208 , 0 , V_4 -> V_16 . V_110 * sizeof( V_208 [ 0 ] ) ) ;
memset ( V_226 , 0 , V_4 -> V_16 . V_110 * sizeof( V_226 [ 0 ] ) ) ;
if ( ! F_76 ( V_2 ,
V_208 , V_58 , V_152 , V_153 ) &&
! F_79 ( V_2 ,
V_208 , V_58 , V_152 , V_153 ) )
F_20 ( L_32 ) ;
F_14 ( L_33 ,
V_152 , V_153 ) ;
F_80 ( V_2 , V_226 , V_208 , 0 , V_152 , V_153 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ ) {
V_157 = & V_2 -> V_57 [ V_7 ] . V_56 ;
V_157 -> V_112 = 0 ;
V_157 -> V_61 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_169 * V_23 = V_208 [ V_7 ] ;
struct V_109 * V_232 = V_226 [ V_7 ] ;
V_157 = & V_232 -> V_56 ;
if ( V_23 && V_232 ) {
F_14 ( L_34 ,
V_23 -> V_26 , V_232 -> V_56 . V_40 -> V_67 . V_68 ) ;
V_232 -> V_170 = V_23 ;
if ( V_157 -> V_23 )
F_43 ( V_4 , V_157 -> V_23 ) ;
V_157 -> V_23 = F_82 ( V_4 ,
V_232 -> V_170 ) ;
V_157 -> V_105 [ V_157 -> V_112 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_157 -> V_61 = V_2 -> V_61 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_54 ; V_7 ++ ) {
V_157 = & V_2 -> V_57 [ V_7 ] . V_56 ;
if ( V_157 -> V_112 == 0 ) {
F_83 ( V_157 -> V_61 ) ;
F_83 ( V_157 -> V_112 ) ;
if ( V_157 -> V_23 )
F_43 ( V_4 , V_157 -> V_23 ) ;
V_157 -> V_23 = NULL ;
}
}
V_148:
F_4 ( V_226 ) ;
F_4 ( V_208 ) ;
F_4 ( V_58 ) ;
}
bool F_84 ( struct V_1 * V_2 , int V_233 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_196 = 0 ;
F_10 ( V_2 ) ;
F_85 ( & V_4 -> V_16 . V_17 ) ;
V_196 = F_69 ( V_2 ,
V_4 -> V_16 . V_229 ,
V_4 -> V_16 . V_230 ) ;
F_32 ( & V_4 -> V_16 . V_17 ) ;
if ( V_196 == 0 )
F_63 ( V_2 -> V_4 -> V_4 , L_35 ) ;
F_81 ( V_2 ) ;
return F_61 ( V_2 , V_233 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_229 , V_230 ;
F_85 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
if ( ! V_2 -> V_61 || ! F_35 ( V_2 ) ) {
V_2 -> V_156 = true ;
F_32 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
return 0 ;
}
F_14 ( L_30 ) ;
V_229 = V_2 -> V_61 -> V_152 ;
V_230 = V_2 -> V_61 -> V_153 ;
F_69 ( V_2 , V_229 , V_230 ) ;
F_32 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
F_27 ( V_4 ) ;
F_81 ( V_2 ) ;
F_28 ( V_4 ) ;
F_58 ( V_2 -> V_176 ) ;
return 0 ;
}
static int T_5 F_86 ( void )
{
const char * V_26 = L_36 ;
struct V_234 * V_235 ;
F_85 ( & V_236 ) ;
V_235 = F_87 ( V_26 ) ;
F_32 ( & V_236 ) ;
if ( ! V_235 )
F_88 ( V_26 ) ;
return 0 ;
}
