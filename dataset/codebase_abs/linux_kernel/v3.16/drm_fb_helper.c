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
static int F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_16 * V_17 ;
struct V_5 * V_6 ;
char * V_18 = NULL ;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_6 = V_15 -> V_6 ;
V_17 = & V_15 -> V_19 ;
if ( F_6 ( V_6 -> V_20 , & V_18 ) )
continue;
if ( F_7 ( V_18 ,
V_6 ,
V_17 ) ) {
if ( V_17 -> V_21 ) {
const char * V_22 ;
switch ( V_17 -> V_21 ) {
case V_23 :
V_22 = L_1 ;
break;
case V_24 :
V_22 = L_2 ;
break;
default:
case V_25 :
V_22 = L_3 ;
break;
}
F_8 ( L_4 ,
V_6 -> V_20 , V_22 ) ;
V_6 -> V_21 = V_17 -> V_21 ;
}
F_9 ( L_5 ,
V_6 -> V_20 ,
V_17 -> V_26 , V_17 -> V_27 ,
V_17 -> V_28 ? V_17 -> V_29 : 60 ,
V_17 -> V_30 ? L_6 : L_7 ,
V_17 -> V_31 ? L_8 : L_7 ,
V_17 -> V_32 ? L_9 : L_7 ) ;
}
}
return 0 ;
}
static void F_10 ( struct V_33 * V_34 , struct V_1 * V_35 )
{
T_1 * V_36 , * V_37 , * V_38 ;
int V_7 ;
if ( V_35 -> V_39 -> V_40 == NULL )
return;
V_36 = V_34 -> V_41 ;
V_37 = V_36 + V_34 -> V_42 ;
V_38 = V_37 + V_34 -> V_42 ;
for ( V_7 = 0 ; V_7 < V_34 -> V_42 ; V_7 ++ )
V_35 -> V_39 -> V_40 ( V_34 , & V_36 [ V_7 ] , & V_37 [ V_7 ] , & V_38 [ V_7 ] , V_7 ) ;
}
static void F_11 ( struct V_33 * V_34 )
{
T_1 * V_36 , * V_37 , * V_38 ;
if ( V_34 -> V_39 -> V_43 == NULL )
return;
V_36 = V_34 -> V_41 ;
V_37 = V_36 + V_34 -> V_42 ;
V_38 = V_37 + V_34 -> V_42 ;
V_34 -> V_39 -> V_43 ( V_34 , V_36 , V_37 , V_38 , 0 , V_34 -> V_42 ) ;
}
int F_12 ( struct V_44 * V_45 )
{
struct V_1 * V_35 = V_45 -> V_46 ;
struct V_47 * V_39 ;
int V_7 ;
if ( F_13 ( & V_48 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_35 -> V_49 ; V_7 ++ ) {
struct V_50 * V_51 =
& V_35 -> V_52 [ V_7 ] . V_51 ;
if ( ! V_51 -> V_34 -> V_53 )
continue;
V_39 = V_51 -> V_34 -> V_54 ;
F_10 ( V_51 -> V_34 , V_35 ) ;
V_39 -> V_55 ( V_51 -> V_34 ,
V_51 -> V_56 ,
V_51 -> V_57 ,
V_51 -> V_58 ,
V_59 ) ;
}
}
return 0 ;
}
static struct V_60 * F_14 ( struct V_33 * V_34 )
{
struct V_3 * V_4 = V_34 -> V_4 ;
struct V_33 * V_61 ;
F_2 (c, &dev->mode_config.crtc_list, head) {
if ( V_34 -> V_62 . V_63 == V_61 -> V_62 . V_63 )
return V_61 -> V_64 -> V_56 ;
}
return NULL ;
}
int F_15 ( struct V_44 * V_45 )
{
struct V_1 * V_35 = V_45 -> V_46 ;
struct V_33 * V_34 ;
struct V_47 * V_39 ;
struct V_60 * V_56 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_35 -> V_49 ; V_7 ++ ) {
struct V_50 * V_51 = & V_35 -> V_52 [ V_7 ] . V_51 ;
V_34 = V_51 -> V_34 ;
V_39 = V_34 -> V_54 ;
V_56 = F_14 ( V_34 ) ;
if ( ! V_34 -> V_53 )
continue;
if ( ! V_56 ) {
F_16 ( L_10 ) ;
continue;
}
F_11 ( V_51 -> V_34 ) ;
V_39 -> V_55 ( V_51 -> V_34 , V_56 , V_34 -> V_57 ,
V_34 -> V_58 , V_65 ) ;
}
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_66 * V_67 ;
bool error = false ;
int V_7 ;
F_18 ( V_4 ) ;
F_2 (plane, &dev->mode_config.plane_list, head)
if ( V_67 -> type != V_68 )
F_19 ( V_67 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ ) {
struct V_50 * V_51 = & V_2 -> V_52 [ V_7 ] . V_51 ;
struct V_33 * V_34 = V_51 -> V_34 ;
int V_69 ;
if ( V_34 -> V_39 -> V_70 ) {
V_69 = V_34 -> V_39 -> V_70 ( V_34 , NULL , 0 , 0 , 0 ) ;
if ( V_69 )
error = true ;
}
V_69 = F_20 ( V_51 ) ;
if ( V_69 )
error = true ;
}
return error ;
}
static bool F_21 ( struct V_1 * V_2 )
{
return F_17 ( V_2 ) ;
}
bool F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_69 ;
F_23 ( V_4 ) ;
V_69 = F_17 ( V_2 ) ;
F_24 ( V_4 ) ;
return V_69 ;
}
static bool F_25 ( void )
{
bool V_69 , error = false ;
struct V_1 * V_35 ;
if ( F_13 ( & V_48 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_35 -> V_4 ;
if ( V_4 -> V_71 == V_72 )
continue;
if ( ! F_26 ( & V_4 -> V_73 . V_74 ) ) {
error = true ;
continue;
}
V_69 = F_21 ( V_35 ) ;
if ( V_69 )
error = true ;
F_27 ( & V_4 -> V_73 . V_74 ) ;
}
return error ;
}
static int F_28 ( struct V_75 * V_76 , unsigned long V_77 ,
void * V_78 )
{
if ( V_79 < 0 )
return 0 ;
F_29 ( L_11 ) ;
return F_25 () ;
}
static bool F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_33 * V_34 ;
int V_80 = 0 , V_81 = 0 ;
if ( V_4 -> V_64 -> V_82 )
return false ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_34 -> V_64 -> V_56 )
V_81 ++ ;
if ( V_34 -> V_64 -> V_56 == V_2 -> V_56 )
V_80 ++ ;
}
if ( V_80 < V_81 )
return false ;
return true ;
}
static void F_31 ( struct V_83 * V_84 )
{
bool V_69 ;
V_69 = F_25 () ;
if ( V_69 == true )
F_16 ( L_12 ) ;
}
static void F_32 ( int V_85 )
{
F_33 ( & V_86 ) ;
}
static void F_34 ( struct V_44 * V_45 , int V_87 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_33 * V_34 ;
struct V_5 * V_6 ;
int V_7 , V_88 ;
if ( V_89 )
return;
F_23 ( V_4 ) ;
if ( ! F_30 ( V_2 ) ) {
F_24 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ ) {
V_34 = V_2 -> V_52 [ V_7 ] . V_51 . V_34 ;
if ( ! V_34 -> V_53 )
continue;
for ( V_88 = 0 ; V_88 < V_2 -> V_13 ; V_88 ++ ) {
V_6 = V_2 -> V_12 [ V_88 ] -> V_6 ;
V_6 -> V_39 -> V_90 ( V_6 , V_87 ) ;
F_35 ( & V_6 -> V_62 ,
V_4 -> V_73 . V_91 , V_87 ) ;
}
}
F_24 ( V_4 ) ;
}
int F_36 ( int V_92 , struct V_44 * V_45 )
{
switch ( V_92 ) {
case V_93 :
F_34 ( V_45 , V_94 ) ;
break;
case V_95 :
F_34 ( V_45 , V_96 ) ;
break;
case V_97 :
F_34 ( V_45 , V_96 ) ;
break;
case V_98 :
F_34 ( V_45 , V_99 ) ;
break;
case V_100 :
F_34 ( V_45 , V_101 ) ;
break;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_35 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_35 -> V_13 ; V_7 ++ )
F_4 ( V_35 -> V_12 [ V_7 ] ) ;
F_4 ( V_35 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_35 -> V_49 ; V_7 ++ ) {
F_4 ( V_35 -> V_52 [ V_7 ] . V_51 . V_102 ) ;
if ( V_35 -> V_52 [ V_7 ] . V_51 . V_17 )
F_38 ( V_35 -> V_4 , V_35 -> V_52 [ V_7 ] . V_51 . V_17 ) ;
}
F_4 ( V_35 -> V_52 ) ;
}
int F_39 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_49 , int V_103 )
{
struct V_33 * V_34 ;
int V_7 ;
if ( ! V_103 )
return - V_104 ;
V_2 -> V_4 = V_4 ;
F_40 ( & V_2 -> V_105 ) ;
V_2 -> V_52 = F_41 ( V_49 , sizeof( struct V_106 ) , V_10 ) ;
if ( ! V_2 -> V_52 )
return - V_14 ;
V_2 -> V_49 = V_49 ;
V_2 -> V_12 = F_41 ( V_4 -> V_73 . V_107 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_52 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_49 ; V_7 ++ ) {
V_2 -> V_52 [ V_7 ] . V_51 . V_102 =
F_41 ( V_103 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_52 [ V_7 ] . V_51 . V_102 )
goto V_108;
V_2 -> V_52 [ V_7 ] . V_51 . V_109 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_52 [ V_7 ] . V_51 . V_34 = V_34 ;
V_7 ++ ;
}
return 0 ;
V_108:
F_37 ( V_2 ) ;
return - V_14 ;
}
void F_42 ( struct V_1 * V_2 )
{
if ( ! F_13 ( & V_2 -> V_105 ) ) {
F_43 ( & V_2 -> V_105 ) ;
if ( F_13 ( & V_48 ) ) {
F_44 ( L_13 ) ;
F_45 ( & V_110 ,
& V_111 ) ;
F_46 ( 'v' , & V_112 ) ;
}
}
F_37 ( V_2 ) ;
}
static int F_47 ( struct V_33 * V_34 , T_2 V_113 , T_2 V_114 ,
T_2 V_115 , T_2 V_116 , struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_60 * V_56 = V_2 -> V_56 ;
int V_117 ;
if ( V_45 -> V_118 . V_119 == V_120 ) {
T_3 * V_121 ;
T_3 V_122 ;
if ( V_116 > 16 )
return - V_104 ;
V_121 = ( T_3 * ) V_45 -> V_123 ;
V_113 >>= ( 16 - V_45 -> V_124 . V_113 . V_125 ) ;
V_114 >>= ( 16 - V_45 -> V_124 . V_114 . V_125 ) ;
V_115 >>= ( 16 - V_45 -> V_124 . V_115 . V_125 ) ;
V_122 = ( V_113 << V_45 -> V_124 . V_113 . V_126 ) |
( V_114 << V_45 -> V_124 . V_114 . V_126 ) |
( V_115 << V_45 -> V_124 . V_115 . V_126 ) ;
if ( V_45 -> V_124 . V_127 . V_125 > 0 ) {
T_3 V_128 = ( 1 << V_45 -> V_124 . V_127 . V_125 ) - 1 ;
V_128 <<= V_45 -> V_124 . V_127 . V_126 ;
V_122 |= V_128 ;
}
V_121 [ V_116 ] = V_122 ;
return 0 ;
}
if ( F_48 ( ! V_2 -> V_39 -> V_43 ||
! V_2 -> V_39 -> V_40 ) )
return - V_104 ;
V_117 = V_116 ;
if ( V_56 -> V_129 == 16 ) {
V_117 = V_116 << 3 ;
if ( V_56 -> V_130 == 16 && V_116 > 63 )
return - V_104 ;
if ( V_56 -> V_130 == 15 && V_116 > 31 )
return - V_104 ;
if ( V_56 -> V_130 == 16 ) {
T_2 V_131 , V_132 , V_133 ;
int V_7 ;
if ( V_116 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_39 -> V_43 ( V_34 , V_113 ,
V_114 , V_115 , V_117 + V_7 ) ;
}
V_2 -> V_39 -> V_40 ( V_34 , & V_131 ,
& V_132 , & V_133 ,
V_117 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_39 -> V_43 ( V_34 , V_131 ,
V_114 , V_133 ,
( V_117 >> 1 ) + V_7 ) ;
}
}
if ( V_56 -> V_130 != 16 )
V_2 -> V_39 -> V_43 ( V_34 , V_113 , V_114 , V_115 , V_117 ) ;
return 0 ;
}
int F_49 ( struct V_134 * V_135 , struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_47 * V_136 ;
T_2 * V_113 , * V_114 , * V_115 , * V_127 ;
struct V_33 * V_34 ;
int V_7 , V_88 , V_137 = 0 ;
int V_138 ;
F_23 ( V_4 ) ;
if ( ! F_30 ( V_2 ) ) {
F_24 ( V_4 ) ;
return - V_139 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ ) {
V_34 = V_2 -> V_52 [ V_7 ] . V_51 . V_34 ;
V_136 = V_34 -> V_54 ;
V_113 = V_135 -> V_113 ;
V_114 = V_135 -> V_114 ;
V_115 = V_135 -> V_115 ;
V_127 = V_135 -> V_127 ;
V_138 = V_135 -> V_138 ;
for ( V_88 = 0 ; V_88 < V_135 -> V_140 ; V_88 ++ ) {
T_2 V_141 , V_142 , V_143 , V_144 = 0xffff ;
V_141 = * V_113 ++ ;
V_142 = * V_114 ++ ;
V_143 = * V_115 ++ ;
if ( V_127 )
V_144 = * V_127 ++ ;
V_137 = F_47 ( V_34 , V_141 , V_142 , V_143 , V_138 ++ , V_45 ) ;
if ( V_137 )
goto V_145;
}
if ( V_136 -> V_146 )
V_136 -> V_146 ( V_34 ) ;
}
V_145:
F_24 ( V_4 ) ;
return V_137 ;
}
int F_50 ( struct V_147 * V_124 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_60 * V_56 = V_2 -> V_56 ;
int V_130 ;
if ( V_124 -> V_148 != 0 || F_51 () )
return - V_104 ;
if ( V_124 -> V_129 > V_56 -> V_129 ||
V_124 -> V_26 > V_56 -> V_149 || V_124 -> V_27 > V_56 -> V_150 ||
V_124 -> V_151 > V_56 -> V_149 || V_124 -> V_152 > V_56 -> V_150 ) {
F_52 ( L_14
L_15 ,
V_124 -> V_26 , V_124 -> V_27 , V_124 -> V_129 ,
V_124 -> V_151 , V_124 -> V_152 ,
V_56 -> V_149 , V_56 -> V_150 , V_56 -> V_129 ) ;
return - V_104 ;
}
switch ( V_124 -> V_129 ) {
case 16 :
V_130 = ( V_124 -> V_114 . V_125 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_130 = ( V_124 -> V_127 . V_125 > 0 ) ? 32 : 24 ;
break;
default:
V_130 = V_124 -> V_129 ;
break;
}
switch ( V_130 ) {
case 8 :
V_124 -> V_113 . V_126 = 0 ;
V_124 -> V_114 . V_126 = 0 ;
V_124 -> V_115 . V_126 = 0 ;
V_124 -> V_113 . V_125 = 8 ;
V_124 -> V_114 . V_125 = 8 ;
V_124 -> V_115 . V_125 = 8 ;
V_124 -> V_127 . V_125 = 0 ;
V_124 -> V_127 . V_126 = 0 ;
break;
case 15 :
V_124 -> V_113 . V_126 = 10 ;
V_124 -> V_114 . V_126 = 5 ;
V_124 -> V_115 . V_126 = 0 ;
V_124 -> V_113 . V_125 = 5 ;
V_124 -> V_114 . V_125 = 5 ;
V_124 -> V_115 . V_125 = 5 ;
V_124 -> V_127 . V_125 = 1 ;
V_124 -> V_127 . V_126 = 15 ;
break;
case 16 :
V_124 -> V_113 . V_126 = 11 ;
V_124 -> V_114 . V_126 = 5 ;
V_124 -> V_115 . V_126 = 0 ;
V_124 -> V_113 . V_125 = 5 ;
V_124 -> V_114 . V_125 = 6 ;
V_124 -> V_115 . V_125 = 5 ;
V_124 -> V_127 . V_125 = 0 ;
V_124 -> V_127 . V_126 = 0 ;
break;
case 24 :
V_124 -> V_113 . V_126 = 16 ;
V_124 -> V_114 . V_126 = 8 ;
V_124 -> V_115 . V_126 = 0 ;
V_124 -> V_113 . V_125 = 8 ;
V_124 -> V_114 . V_125 = 8 ;
V_124 -> V_115 . V_125 = 8 ;
V_124 -> V_127 . V_125 = 0 ;
V_124 -> V_127 . V_126 = 0 ;
break;
case 32 :
V_124 -> V_113 . V_126 = 16 ;
V_124 -> V_114 . V_126 = 8 ;
V_124 -> V_115 . V_126 = 0 ;
V_124 -> V_113 . V_125 = 8 ;
V_124 -> V_114 . V_125 = 8 ;
V_124 -> V_115 . V_125 = 8 ;
V_124 -> V_127 . V_125 = 8 ;
V_124 -> V_127 . V_126 = 24 ;
break;
default:
return - V_104 ;
}
return 0 ;
}
int F_53 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_147 * V_124 = & V_45 -> V_124 ;
if ( V_124 -> V_148 != 0 ) {
F_16 ( L_16 ) ;
return - V_104 ;
}
F_22 ( V_2 ) ;
if ( V_2 -> V_153 ) {
V_2 -> V_153 = false ;
F_54 ( V_2 ) ;
}
return 0 ;
}
int F_55 ( struct V_147 * V_124 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_50 * V_154 ;
int V_69 = 0 ;
int V_7 ;
F_23 ( V_4 ) ;
if ( ! F_30 ( V_2 ) ) {
F_24 ( V_4 ) ;
return - V_139 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ ) {
V_154 = & V_2 -> V_52 [ V_7 ] . V_51 ;
V_154 -> V_57 = V_124 -> V_155 ;
V_154 -> V_58 = V_124 -> V_156 ;
if ( V_154 -> V_109 ) {
V_69 = F_20 ( V_154 ) ;
if ( ! V_69 ) {
V_45 -> V_124 . V_155 = V_124 -> V_155 ;
V_45 -> V_124 . V_156 = V_124 -> V_156 ;
}
}
}
F_24 ( V_4 ) ;
return V_69 ;
}
static int F_56 ( struct V_1 * V_2 ,
int V_157 )
{
int V_69 = 0 ;
int V_49 = 0 ;
int V_7 ;
struct V_44 * V_45 ;
struct V_158 V_159 ;
int V_42 = 0 ;
memset ( & V_159 , 0 , sizeof( struct V_158 ) ) ;
V_159 . V_160 = 24 ;
V_159 . V_161 = 32 ;
V_159 . V_162 = ( unsigned ) - 1 ;
V_159 . V_163 = ( unsigned ) - 1 ;
if ( V_157 != V_159 . V_161 )
V_159 . V_160 = V_159 . V_161 = V_157 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_15 = V_2 -> V_12 [ V_7 ] ;
struct V_16 * V_19 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_164 ) {
switch ( V_19 -> V_165 ) {
case 8 :
V_159 . V_160 = V_159 . V_161 = 8 ;
break;
case 15 :
V_159 . V_160 = 15 ;
V_159 . V_161 = 16 ;
break;
case 16 :
V_159 . V_160 = V_159 . V_161 = 16 ;
break;
case 24 :
V_159 . V_160 = V_159 . V_161 = 24 ;
break;
case 32 :
V_159 . V_160 = 24 ;
V_159 . V_161 = 32 ;
break;
}
break;
}
}
V_49 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ ) {
struct V_166 * V_167 ;
V_167 = V_2 -> V_52 [ V_7 ] . V_167 ;
if ( V_167 ) {
if ( V_42 == 0 )
V_42 = V_2 -> V_52 [ V_7 ] . V_51 . V_34 -> V_42 ;
if ( V_167 -> V_168 < V_159 . V_162 )
V_159 . V_162 = V_167 -> V_168 ;
if ( V_167 -> V_169 < V_159 . V_163 )
V_159 . V_163 = V_167 -> V_169 ;
if ( V_167 -> V_168 > V_159 . V_170 )
V_159 . V_170 = V_167 -> V_168 ;
if ( V_167 -> V_169 > V_159 . V_171 )
V_159 . V_171 = V_167 -> V_169 ;
V_49 ++ ;
}
}
if ( V_49 == 0 || V_159 . V_162 == - 1 || V_159 . V_163 == - 1 ) {
F_8 ( L_17 ) ;
V_159 . V_162 = V_159 . V_170 = 1024 ;
V_159 . V_163 = V_159 . V_171 = 768 ;
}
V_69 = (* V_2 -> V_39 -> V_172 )( V_2 , & V_159 ) ;
if ( V_69 < 0 )
return V_69 ;
V_45 = V_2 -> V_173 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ )
if ( V_2 -> V_52 [ V_7 ] . V_51 . V_109 )
V_2 -> V_52 [ V_7 ] . V_51 . V_56 = V_2 -> V_56 ;
V_45 -> V_124 . V_148 = 0 ;
if ( F_57 ( V_45 ) < 0 )
return - V_104 ;
F_58 ( V_2 -> V_4 -> V_4 , L_18 ,
V_45 -> V_174 , V_45 -> V_118 . V_63 ) ;
if ( F_13 ( & V_48 ) ) {
F_58 ( V_2 -> V_4 -> V_4 , L_19 ) ;
F_59 ( & V_110 ,
& V_111 ) ;
F_60 ( 'v' , & V_112 ) ;
}
F_61 ( & V_2 -> V_105 , & V_48 ) ;
return 0 ;
}
void F_62 ( struct V_44 * V_45 , T_4 V_175 ,
T_4 V_130 )
{
V_45 -> V_118 . type = V_176 ;
V_45 -> V_118 . V_119 = V_130 == 8 ? V_177 :
V_120 ;
V_45 -> V_118 . V_178 = 0 ;
V_45 -> V_118 . V_179 = 0 ;
V_45 -> V_118 . V_180 = 0 ;
V_45 -> V_118 . V_181 = 1 ;
V_45 -> V_118 . V_182 = 1 ;
V_45 -> V_118 . V_183 = 0 ;
V_45 -> V_118 . V_184 = V_185 ;
V_45 -> V_118 . V_180 = 0 ;
V_45 -> V_118 . V_186 = V_175 ;
return;
}
void F_63 ( struct V_44 * V_45 , struct V_1 * V_2 ,
T_4 V_162 , T_4 V_163 )
{
struct V_60 * V_56 = V_2 -> V_56 ;
V_45 -> V_123 = V_2 -> V_123 ;
V_45 -> V_124 . V_151 = V_56 -> V_149 ;
V_45 -> V_124 . V_152 = V_56 -> V_150 ;
V_45 -> V_124 . V_129 = V_56 -> V_129 ;
V_45 -> V_124 . V_187 = V_188 ;
V_45 -> V_124 . V_155 = 0 ;
V_45 -> V_124 . V_156 = 0 ;
V_45 -> V_124 . V_189 = V_190 ;
V_45 -> V_124 . V_150 = - 1 ;
V_45 -> V_124 . V_149 = - 1 ;
switch ( V_56 -> V_130 ) {
case 8 :
V_45 -> V_124 . V_113 . V_126 = 0 ;
V_45 -> V_124 . V_114 . V_126 = 0 ;
V_45 -> V_124 . V_115 . V_126 = 0 ;
V_45 -> V_124 . V_113 . V_125 = 8 ;
V_45 -> V_124 . V_114 . V_125 = 8 ;
V_45 -> V_124 . V_115 . V_125 = 8 ;
V_45 -> V_124 . V_127 . V_126 = 0 ;
V_45 -> V_124 . V_127 . V_125 = 0 ;
break;
case 15 :
V_45 -> V_124 . V_113 . V_126 = 10 ;
V_45 -> V_124 . V_114 . V_126 = 5 ;
V_45 -> V_124 . V_115 . V_126 = 0 ;
V_45 -> V_124 . V_113 . V_125 = 5 ;
V_45 -> V_124 . V_114 . V_125 = 5 ;
V_45 -> V_124 . V_115 . V_125 = 5 ;
V_45 -> V_124 . V_127 . V_126 = 15 ;
V_45 -> V_124 . V_127 . V_125 = 1 ;
break;
case 16 :
V_45 -> V_124 . V_113 . V_126 = 11 ;
V_45 -> V_124 . V_114 . V_126 = 5 ;
V_45 -> V_124 . V_115 . V_126 = 0 ;
V_45 -> V_124 . V_113 . V_125 = 5 ;
V_45 -> V_124 . V_114 . V_125 = 6 ;
V_45 -> V_124 . V_115 . V_125 = 5 ;
V_45 -> V_124 . V_127 . V_126 = 0 ;
break;
case 24 :
V_45 -> V_124 . V_113 . V_126 = 16 ;
V_45 -> V_124 . V_114 . V_126 = 8 ;
V_45 -> V_124 . V_115 . V_126 = 0 ;
V_45 -> V_124 . V_113 . V_125 = 8 ;
V_45 -> V_124 . V_114 . V_125 = 8 ;
V_45 -> V_124 . V_115 . V_125 = 8 ;
V_45 -> V_124 . V_127 . V_126 = 0 ;
V_45 -> V_124 . V_127 . V_125 = 0 ;
break;
case 32 :
V_45 -> V_124 . V_113 . V_126 = 16 ;
V_45 -> V_124 . V_114 . V_126 = 8 ;
V_45 -> V_124 . V_115 . V_126 = 0 ;
V_45 -> V_124 . V_113 . V_125 = 8 ;
V_45 -> V_124 . V_114 . V_125 = 8 ;
V_45 -> V_124 . V_115 . V_125 = 8 ;
V_45 -> V_124 . V_127 . V_126 = 24 ;
V_45 -> V_124 . V_127 . V_125 = 8 ;
break;
default:
break;
}
V_45 -> V_124 . V_26 = V_162 ;
V_45 -> V_124 . V_27 = V_163 ;
}
static int F_64 ( struct V_1 * V_2 ,
T_4 V_191 ,
T_4 V_192 )
{
struct V_5 * V_6 ;
int V_193 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_193 += V_6 -> V_39 -> V_194 ( V_6 , V_191 , V_192 ) ;
}
return V_193 ;
}
struct V_166 * F_65 ( struct V_8 * V_195 , int V_149 , int V_150 )
{
struct V_166 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( V_17 -> V_168 > V_149 ||
V_17 -> V_169 > V_150 )
continue;
if ( V_17 -> type & V_196 )
return V_17 ;
}
return NULL ;
}
static bool F_66 ( struct V_8 * V_195 )
{
struct V_16 * V_19 ;
V_19 = & V_195 -> V_19 ;
return V_19 -> V_197 ;
}
struct V_166 * F_67 ( struct V_8 * V_15 ,
int V_149 , int V_150 )
{
struct V_16 * V_19 ;
struct V_166 * V_17 = NULL ;
bool V_198 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_197 == false )
return V_17 ;
if ( V_19 -> V_30 || V_19 -> V_31 )
goto V_199;
V_198 = ! V_19 -> V_32 ;
V_200:
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_168 != V_19 -> V_26 ||
V_17 -> V_169 != V_19 -> V_27 )
continue;
if ( V_19 -> V_28 ) {
if ( V_17 -> V_201 != V_19 -> V_29 )
continue;
}
if ( V_19 -> V_32 ) {
if ( ! ( V_17 -> V_202 & V_203 ) )
continue;
} else if ( V_198 ) {
if ( V_17 -> V_202 & V_203 )
continue;
}
return V_17 ;
}
if ( V_198 ) {
V_198 = false ;
goto V_200;
}
V_199:
V_17 = F_68 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_61 ( & V_17 -> V_204 , & V_15 -> V_6 -> V_205 ) ;
return V_17 ;
}
static bool F_69 ( struct V_5 * V_6 , bool V_206 )
{
bool V_207 ;
if ( V_206 )
V_207 = V_6 -> V_208 == V_209 ;
else
V_207 = V_6 -> V_208 != V_210 ;
return V_207 ;
}
static void F_70 ( struct V_1 * V_2 ,
bool * V_53 )
{
bool V_211 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_53 [ V_7 ] = F_69 ( V_6 , true ) ;
F_9 ( L_20 , V_6 -> V_62 . V_63 ,
V_53 [ V_7 ] ? L_21 : L_22 ) ;
V_211 |= V_53 [ V_7 ] ;
}
if ( V_211 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_53 [ V_7 ] = F_69 ( V_6 , false ) ;
}
}
static bool F_71 ( struct V_1 * V_2 ,
struct V_166 * * V_205 ,
bool * V_53 , int V_149 , int V_150 )
{
int V_193 , V_7 , V_88 ;
bool V_212 = false ;
struct V_8 * V_15 ;
struct V_166 * V_213 , * V_17 ;
if ( V_2 -> V_49 > 1 )
return false ;
V_193 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_53 [ V_7 ] )
V_193 ++ ;
}
if ( V_193 <= 1 )
return false ;
V_212 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_53 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_205 [ V_7 ] = F_67 ( V_15 , V_149 , V_150 ) ;
if ( ! V_205 [ V_7 ] ) {
V_212 = false ;
break;
}
for ( V_88 = 0 ; V_88 < V_7 ; V_88 ++ ) {
if ( ! V_53 [ V_88 ] )
continue;
if ( ! F_72 ( V_205 [ V_88 ] , V_205 [ V_7 ] ) )
V_212 = false ;
}
}
if ( V_212 ) {
F_9 ( L_23 ) ;
return true ;
}
V_212 = true ;
V_213 = F_73 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_53 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_72 ( V_17 , V_213 ) )
V_205 [ V_7 ] = V_17 ;
}
if ( ! V_205 [ V_7 ] )
V_212 = false ;
}
if ( V_212 ) {
F_9 ( L_24 ) ;
return true ;
}
F_8 ( L_25 ) ;
return false ;
}
static bool F_74 ( struct V_1 * V_2 ,
struct V_166 * * V_205 ,
bool * V_53 , int V_149 , int V_150 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_15 = V_2 -> V_12 [ V_7 ] ;
if ( V_53 [ V_7 ] == false )
continue;
F_9 ( L_26 ,
V_15 -> V_6 -> V_62 . V_63 ) ;
V_205 [ V_7 ] = F_67 ( V_15 , V_149 , V_150 ) ;
if ( ! V_205 [ V_7 ] ) {
F_9 ( L_27 ,
V_15 -> V_6 -> V_62 . V_63 ) ;
V_205 [ V_7 ] = F_65 ( V_15 , V_149 , V_150 ) ;
}
if ( ! V_205 [ V_7 ] && ! F_13 ( & V_15 -> V_6 -> V_205 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_9 ( L_28 , V_205 [ V_7 ] ? V_205 [ V_7 ] -> V_20 :
L_29 ) ;
}
return true ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_106 * * V_214 ,
struct V_166 * * V_205 ,
int V_76 , int V_149 , int V_150 )
{
int V_61 , V_215 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_216 * V_217 ;
struct V_218 * V_219 ;
int V_220 , V_221 , V_222 ;
struct V_106 * * V_223 , * V_34 ;
struct V_8 * V_15 ;
if ( V_76 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_76 ] ;
V_6 = V_15 -> V_6 ;
V_214 [ V_76 ] = NULL ;
V_221 = F_75 ( V_2 , V_214 , V_205 , V_76 + 1 , V_149 , V_150 ) ;
if ( V_205 [ V_76 ] == NULL )
return V_221 ;
V_223 = F_3 ( V_4 -> V_73 . V_107 *
sizeof( struct V_106 * ) , V_10 ) ;
if ( ! V_223 )
return V_221 ;
V_220 = 1 ;
if ( V_6 -> V_208 == V_209 )
V_220 ++ ;
if ( F_66 ( V_15 ) )
V_220 ++ ;
if ( F_65 ( V_15 , V_149 , V_150 ) )
V_220 ++ ;
V_217 = V_6 -> V_54 ;
V_219 = V_217 -> V_224 ( V_6 ) ;
if ( ! V_219 )
goto V_145;
for ( V_61 = 0 ; V_61 < V_2 -> V_49 ; V_61 ++ ) {
V_34 = & V_2 -> V_52 [ V_61 ] ;
if ( ( V_219 -> V_225 & ( 1 << V_61 ) ) == 0 )
continue;
for ( V_215 = 0 ; V_215 < V_76 ; V_215 ++ )
if ( V_214 [ V_215 ] == V_34 )
break;
if ( V_215 < V_76 ) {
if ( V_2 -> V_49 > 1 )
continue;
if ( ! F_72 ( V_205 [ V_215 ] , V_205 [ V_76 ] ) )
continue;
}
V_223 [ V_76 ] = V_34 ;
memcpy ( V_223 , V_214 , V_76 * sizeof( struct V_106 * ) ) ;
V_222 = V_220 + F_75 ( V_2 , V_223 , V_205 , V_76 + 1 ,
V_149 , V_150 ) ;
if ( V_222 > V_221 ) {
V_221 = V_222 ;
memcpy ( V_214 , V_223 ,
V_4 -> V_73 . V_107 *
sizeof( struct V_106 * ) ) ;
}
}
V_145:
F_4 ( V_223 ) ;
return V_221 ;
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_106 * * V_223 ;
struct V_166 * * V_205 ;
struct V_50 * V_154 ;
bool * V_53 ;
int V_149 , V_150 ;
int V_7 ;
F_9 ( L_30 ) ;
V_149 = V_4 -> V_73 . V_226 ;
V_150 = V_4 -> V_73 . V_227 ;
V_223 = F_41 ( V_4 -> V_73 . V_107 ,
sizeof( struct V_106 * ) , V_10 ) ;
V_205 = F_41 ( V_4 -> V_73 . V_107 ,
sizeof( struct V_166 * ) , V_10 ) ;
V_53 = F_41 ( V_4 -> V_73 . V_107 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_223 || ! V_205 || ! V_53 ) {
F_16 ( L_31 ) ;
goto V_145;
}
F_70 ( V_2 , V_53 ) ;
if ( ! ( V_2 -> V_39 -> V_228 &&
V_2 -> V_39 -> V_228 ( V_2 , V_223 , V_205 ,
V_53 , V_149 , V_150 ) ) ) {
memset ( V_205 , 0 , V_4 -> V_73 . V_107 * sizeof( V_205 [ 0 ] ) ) ;
memset ( V_223 , 0 , V_4 -> V_73 . V_107 * sizeof( V_223 [ 0 ] ) ) ;
if ( ! F_71 ( V_2 ,
V_205 , V_53 , V_149 , V_150 ) &&
! F_74 ( V_2 ,
V_205 , V_53 , V_149 , V_150 ) )
F_16 ( L_32 ) ;
F_9 ( L_33 ,
V_149 , V_150 ) ;
F_75 ( V_2 , V_223 , V_205 , 0 , V_149 , V_150 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ ) {
V_154 = & V_2 -> V_52 [ V_7 ] . V_51 ;
V_154 -> V_109 = 0 ;
V_154 -> V_56 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_166 * V_17 = V_205 [ V_7 ] ;
struct V_106 * V_229 = V_223 [ V_7 ] ;
V_154 = & V_229 -> V_51 ;
if ( V_17 && V_229 ) {
F_9 ( L_34 ,
V_17 -> V_20 , V_229 -> V_51 . V_34 -> V_62 . V_63 ) ;
V_229 -> V_167 = V_17 ;
if ( V_154 -> V_17 )
F_38 ( V_4 , V_154 -> V_17 ) ;
V_154 -> V_17 = F_77 ( V_4 ,
V_229 -> V_167 ) ;
V_154 -> V_102 [ V_154 -> V_109 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_154 -> V_56 = V_2 -> V_56 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_49 ; V_7 ++ ) {
V_154 = & V_2 -> V_52 [ V_7 ] . V_51 ;
if ( V_154 -> V_109 == 0 ) {
F_78 ( V_154 -> V_56 ) ;
F_78 ( V_154 -> V_109 ) ;
if ( V_154 -> V_17 )
F_38 ( V_4 , V_154 -> V_17 ) ;
V_154 -> V_17 = NULL ;
}
}
V_145:
F_4 ( V_223 ) ;
F_4 ( V_205 ) ;
F_4 ( V_53 ) ;
}
bool F_79 ( struct V_1 * V_2 , int V_230 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_193 = 0 ;
F_5 ( V_2 ) ;
F_80 ( & V_4 -> V_73 . V_74 ) ;
V_193 = F_64 ( V_2 ,
V_4 -> V_73 . V_226 ,
V_4 -> V_73 . V_227 ) ;
F_27 ( & V_4 -> V_73 . V_74 ) ;
if ( V_193 == 0 )
F_58 ( V_2 -> V_4 -> V_4 , L_35 ) ;
F_76 ( V_2 ) ;
return F_56 ( V_2 , V_230 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_226 , V_227 ;
if ( ! V_2 -> V_56 )
return 0 ;
F_80 ( & V_2 -> V_4 -> V_73 . V_74 ) ;
if ( ! F_30 ( V_2 ) ) {
V_2 -> V_153 = true ;
F_27 ( & V_2 -> V_4 -> V_73 . V_74 ) ;
return 0 ;
}
F_9 ( L_30 ) ;
V_226 = V_2 -> V_56 -> V_149 ;
V_227 = V_2 -> V_56 -> V_150 ;
F_64 ( V_2 , V_226 , V_227 ) ;
F_27 ( & V_2 -> V_4 -> V_73 . V_74 ) ;
F_23 ( V_4 ) ;
F_76 ( V_2 ) ;
F_24 ( V_4 ) ;
F_53 ( V_2 -> V_173 ) ;
return 0 ;
}
static int T_5 F_81 ( void )
{
const char * V_20 = L_36 ;
struct V_231 * V_232 ;
F_80 ( & V_233 ) ;
V_232 = F_82 ( V_20 ) ;
F_27 ( & V_233 ) ;
if ( ! V_232 )
F_83 ( V_20 ) ;
return 0 ;
}
