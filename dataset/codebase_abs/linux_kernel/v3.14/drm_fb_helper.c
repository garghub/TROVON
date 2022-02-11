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
if ( F_6 ( F_7 ( V_6 ) , & V_18 ) )
continue;
if ( F_8 ( V_18 ,
V_6 ,
V_17 ) ) {
if ( V_17 -> V_20 ) {
const char * V_21 ;
switch ( V_17 -> V_20 ) {
case V_22 :
V_21 = L_1 ;
break;
case V_23 :
V_21 = L_2 ;
break;
default:
case V_24 :
V_21 = L_3 ;
break;
}
F_9 ( L_4 ,
F_7 ( V_6 ) , V_21 ) ;
V_6 -> V_20 = V_17 -> V_20 ;
}
F_10 ( L_5 ,
F_7 ( V_6 ) ,
V_17 -> V_25 , V_17 -> V_26 ,
V_17 -> V_27 ? V_17 -> V_28 : 60 ,
V_17 -> V_29 ? L_6 : L_7 ,
V_17 -> V_30 ? L_8 : L_7 ,
V_17 -> V_31 ? L_9 : L_7 ) ;
}
}
return 0 ;
}
static void F_11 ( struct V_32 * V_33 , struct V_1 * V_34 )
{
T_1 * V_35 , * V_36 , * V_37 ;
int V_7 ;
if ( V_34 -> V_38 -> V_39 == NULL )
return;
V_35 = V_33 -> V_40 ;
V_36 = V_35 + V_33 -> V_41 ;
V_37 = V_36 + V_33 -> V_41 ;
for ( V_7 = 0 ; V_7 < V_33 -> V_41 ; V_7 ++ )
V_34 -> V_38 -> V_39 ( V_33 , & V_35 [ V_7 ] , & V_36 [ V_7 ] , & V_37 [ V_7 ] , V_7 ) ;
}
static void F_12 ( struct V_32 * V_33 )
{
T_1 * V_35 , * V_36 , * V_37 ;
if ( V_33 -> V_38 -> V_42 == NULL )
return;
V_35 = V_33 -> V_40 ;
V_36 = V_35 + V_33 -> V_41 ;
V_37 = V_36 + V_33 -> V_41 ;
V_33 -> V_38 -> V_42 ( V_33 , V_35 , V_36 , V_37 , 0 , V_33 -> V_41 ) ;
}
int F_13 ( struct V_43 * V_44 )
{
struct V_1 * V_34 = V_44 -> V_45 ;
struct V_46 * V_38 ;
int V_7 ;
if ( F_14 ( & V_47 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_34 -> V_48 ; V_7 ++ ) {
struct V_49 * V_50 =
& V_34 -> V_51 [ V_7 ] . V_50 ;
if ( ! V_50 -> V_33 -> V_52 )
continue;
V_38 = V_50 -> V_33 -> V_53 ;
F_11 ( V_50 -> V_33 , V_34 ) ;
V_38 -> V_54 ( V_50 -> V_33 ,
V_50 -> V_55 ,
V_50 -> V_56 ,
V_50 -> V_57 ,
V_58 ) ;
}
}
return 0 ;
}
static struct V_59 * F_15 ( struct V_32 * V_33 )
{
struct V_3 * V_4 = V_33 -> V_4 ;
struct V_32 * V_60 ;
F_2 (c, &dev->mode_config.crtc_list, head) {
if ( V_33 -> V_61 . V_62 == V_60 -> V_61 . V_62 )
return V_60 -> V_55 ;
}
return NULL ;
}
int F_16 ( struct V_43 * V_44 )
{
struct V_1 * V_34 = V_44 -> V_45 ;
struct V_32 * V_33 ;
struct V_46 * V_38 ;
struct V_59 * V_55 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_34 -> V_48 ; V_7 ++ ) {
struct V_49 * V_50 = & V_34 -> V_51 [ V_7 ] . V_50 ;
V_33 = V_50 -> V_33 ;
V_38 = V_33 -> V_53 ;
V_55 = F_15 ( V_33 ) ;
if ( ! V_33 -> V_52 )
continue;
if ( ! V_55 ) {
F_17 ( L_10 ) ;
continue;
}
F_12 ( V_50 -> V_33 ) ;
V_38 -> V_54 ( V_50 -> V_33 , V_55 , V_33 -> V_56 ,
V_33 -> V_57 , V_63 ) ;
}
return 0 ;
}
bool F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_64 * V_65 ;
bool error = false ;
int V_7 ;
F_19 ( V_4 ) ;
F_2 (plane, &dev->mode_config.plane_list, head)
F_20 ( V_65 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_49 * V_50 = & V_2 -> V_51 [ V_7 ] . V_50 ;
struct V_32 * V_33 = V_50 -> V_33 ;
int V_66 ;
if ( V_33 -> V_38 -> V_67 ) {
V_66 = V_33 -> V_38 -> V_67 ( V_33 , NULL , 0 , 0 , 0 ) ;
if ( V_66 )
error = true ;
}
V_66 = F_21 ( V_50 ) ;
if ( V_66 )
error = true ;
}
return error ;
}
static bool F_22 ( void )
{
bool V_66 , error = false ;
struct V_1 * V_34 ;
if ( F_14 ( & V_47 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
if ( V_34 -> V_4 -> V_68 == V_69 )
continue;
V_66 = F_18 ( V_34 ) ;
if ( V_66 )
error = true ;
}
return error ;
}
static int F_23 ( struct V_70 * V_71 , unsigned long V_72 ,
void * V_73 )
{
if ( V_74 < 0 )
return 0 ;
F_24 ( L_11 ) ;
return F_22 () ;
}
static bool F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
int V_75 = 0 , V_76 = 0 ;
if ( V_4 -> V_77 -> V_78 )
return false ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_33 -> V_55 )
V_76 ++ ;
if ( V_33 -> V_55 == V_2 -> V_55 )
V_75 ++ ;
}
if ( V_75 < V_76 )
return false ;
return true ;
}
static void F_26 ( struct V_79 * V_80 )
{
bool V_66 ;
V_66 = F_22 () ;
if ( V_66 == true )
F_17 ( L_12 ) ;
}
static void F_27 ( int V_81 )
{
F_28 ( & V_82 ) ;
}
static void F_29 ( struct V_43 * V_44 , int V_83 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_5 * V_6 ;
int V_7 , V_84 ;
if ( V_85 )
return;
F_30 ( V_4 ) ;
if ( ! F_25 ( V_2 ) ) {
F_31 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
if ( ! V_33 -> V_52 )
continue;
for ( V_84 = 0 ; V_84 < V_2 -> V_13 ; V_84 ++ ) {
V_6 = V_2 -> V_12 [ V_84 ] -> V_6 ;
V_6 -> V_38 -> V_86 ( V_6 , V_83 ) ;
F_32 ( & V_6 -> V_61 ,
V_4 -> V_87 . V_88 , V_83 ) ;
}
}
F_31 ( V_4 ) ;
}
int F_33 ( int V_89 , struct V_43 * V_44 )
{
switch ( V_89 ) {
case V_90 :
F_29 ( V_44 , V_91 ) ;
break;
case V_92 :
F_29 ( V_44 , V_93 ) ;
break;
case V_94 :
F_29 ( V_44 , V_93 ) ;
break;
case V_95 :
F_29 ( V_44 , V_96 ) ;
break;
case V_97 :
F_29 ( V_44 , V_98 ) ;
break;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_34 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_34 -> V_13 ; V_7 ++ )
F_4 ( V_34 -> V_12 [ V_7 ] ) ;
F_4 ( V_34 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_34 -> V_48 ; V_7 ++ ) {
F_4 ( V_34 -> V_51 [ V_7 ] . V_50 . V_99 ) ;
if ( V_34 -> V_51 [ V_7 ] . V_50 . V_17 )
F_35 ( V_34 -> V_4 , V_34 -> V_51 [ V_7 ] . V_50 . V_17 ) ;
}
F_4 ( V_34 -> V_51 ) ;
}
int F_36 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_48 , int V_100 )
{
struct V_32 * V_33 ;
int V_7 ;
V_2 -> V_4 = V_4 ;
F_37 ( & V_2 -> V_101 ) ;
V_2 -> V_51 = F_38 ( V_48 , sizeof( struct V_102 ) , V_10 ) ;
if ( ! V_2 -> V_51 )
return - V_14 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_12 = F_38 ( V_4 -> V_87 . V_103 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_51 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_99 =
F_38 ( V_100 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_51 [ V_7 ] . V_50 . V_99 )
goto V_104;
V_2 -> V_51 [ V_7 ] . V_50 . V_105 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_51 [ V_7 ] . V_50 . V_33 = V_33 ;
V_7 ++ ;
}
return 0 ;
V_104:
F_34 ( V_2 ) ;
return - V_14 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! F_14 ( & V_2 -> V_101 ) ) {
F_40 ( & V_2 -> V_101 ) ;
if ( F_14 ( & V_47 ) ) {
F_41 ( L_13 ) ;
F_42 ( & V_106 ,
& V_107 ) ;
F_43 ( 'v' , & V_108 ) ;
}
}
F_34 ( V_2 ) ;
}
static int F_44 ( struct V_32 * V_33 , T_2 V_109 , T_2 V_110 ,
T_2 V_111 , T_2 V_112 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_113 ;
if ( V_44 -> V_114 . V_115 == V_116 ) {
T_3 * V_117 ;
T_3 V_118 ;
if ( V_112 > 16 )
return - V_119 ;
V_117 = ( T_3 * ) V_44 -> V_120 ;
V_109 >>= ( 16 - V_44 -> V_121 . V_109 . V_122 ) ;
V_110 >>= ( 16 - V_44 -> V_121 . V_110 . V_122 ) ;
V_111 >>= ( 16 - V_44 -> V_121 . V_111 . V_122 ) ;
V_118 = ( V_109 << V_44 -> V_121 . V_109 . V_123 ) |
( V_110 << V_44 -> V_121 . V_110 . V_123 ) |
( V_111 << V_44 -> V_121 . V_111 . V_123 ) ;
if ( V_44 -> V_121 . V_124 . V_122 > 0 ) {
T_3 V_125 = ( 1 << V_44 -> V_121 . V_124 . V_122 ) - 1 ;
V_125 <<= V_44 -> V_121 . V_124 . V_123 ;
V_118 |= V_125 ;
}
V_117 [ V_112 ] = V_118 ;
return 0 ;
}
if ( F_45 ( ! V_2 -> V_38 -> V_42 ||
! V_2 -> V_38 -> V_39 ) )
return - V_119 ;
V_113 = V_112 ;
if ( V_55 -> V_126 == 16 ) {
V_113 = V_112 << 3 ;
if ( V_55 -> V_127 == 16 && V_112 > 63 )
return - V_119 ;
if ( V_55 -> V_127 == 15 && V_112 > 31 )
return - V_119 ;
if ( V_55 -> V_127 == 16 ) {
T_2 V_128 , V_129 , V_130 ;
int V_7 ;
if ( V_112 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_38 -> V_42 ( V_33 , V_109 ,
V_110 , V_111 , V_113 + V_7 ) ;
}
V_2 -> V_38 -> V_39 ( V_33 , & V_128 ,
& V_129 , & V_130 ,
V_113 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_38 -> V_42 ( V_33 , V_128 ,
V_110 , V_130 ,
( V_113 >> 1 ) + V_7 ) ;
}
}
if ( V_55 -> V_127 != 16 )
V_2 -> V_38 -> V_42 ( V_33 , V_109 , V_110 , V_111 , V_113 ) ;
return 0 ;
}
int F_46 ( struct V_131 * V_132 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_46 * V_133 ;
T_2 * V_109 , * V_110 , * V_111 , * V_124 ;
struct V_32 * V_33 ;
int V_7 , V_84 , V_134 = 0 ;
int V_135 ;
F_30 ( V_4 ) ;
if ( ! F_25 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_136 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_133 = V_33 -> V_53 ;
V_109 = V_132 -> V_109 ;
V_110 = V_132 -> V_110 ;
V_111 = V_132 -> V_111 ;
V_124 = V_132 -> V_124 ;
V_135 = V_132 -> V_135 ;
for ( V_84 = 0 ; V_84 < V_132 -> V_137 ; V_84 ++ ) {
T_2 V_138 , V_139 , V_140 , V_141 = 0xffff ;
V_138 = * V_109 ++ ;
V_139 = * V_110 ++ ;
V_140 = * V_111 ++ ;
if ( V_124 )
V_141 = * V_124 ++ ;
V_134 = F_44 ( V_33 , V_138 , V_139 , V_140 , V_135 ++ , V_44 ) ;
if ( V_134 )
goto V_142;
}
if ( V_133 -> V_143 )
V_133 -> V_143 ( V_33 ) ;
}
V_142:
F_31 ( V_4 ) ;
return V_134 ;
}
int F_47 ( struct V_144 * V_121 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_127 ;
if ( V_121 -> V_145 != 0 || F_48 () )
return - V_119 ;
if ( V_121 -> V_126 > V_55 -> V_126 ||
V_121 -> V_25 > V_55 -> V_146 || V_121 -> V_26 > V_55 -> V_147 ||
V_121 -> V_148 > V_55 -> V_146 || V_121 -> V_149 > V_55 -> V_147 ) {
F_49 ( L_14
L_15 ,
V_121 -> V_25 , V_121 -> V_26 , V_121 -> V_126 ,
V_121 -> V_148 , V_121 -> V_149 ,
V_55 -> V_146 , V_55 -> V_147 , V_55 -> V_126 ) ;
return - V_119 ;
}
switch ( V_121 -> V_126 ) {
case 16 :
V_127 = ( V_121 -> V_110 . V_122 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_127 = ( V_121 -> V_124 . V_122 > 0 ) ? 32 : 24 ;
break;
default:
V_127 = V_121 -> V_126 ;
break;
}
switch ( V_127 ) {
case 8 :
V_121 -> V_109 . V_123 = 0 ;
V_121 -> V_110 . V_123 = 0 ;
V_121 -> V_111 . V_123 = 0 ;
V_121 -> V_109 . V_122 = 8 ;
V_121 -> V_110 . V_122 = 8 ;
V_121 -> V_111 . V_122 = 8 ;
V_121 -> V_124 . V_122 = 0 ;
V_121 -> V_124 . V_123 = 0 ;
break;
case 15 :
V_121 -> V_109 . V_123 = 10 ;
V_121 -> V_110 . V_123 = 5 ;
V_121 -> V_111 . V_123 = 0 ;
V_121 -> V_109 . V_122 = 5 ;
V_121 -> V_110 . V_122 = 5 ;
V_121 -> V_111 . V_122 = 5 ;
V_121 -> V_124 . V_122 = 1 ;
V_121 -> V_124 . V_123 = 15 ;
break;
case 16 :
V_121 -> V_109 . V_123 = 11 ;
V_121 -> V_110 . V_123 = 5 ;
V_121 -> V_111 . V_123 = 0 ;
V_121 -> V_109 . V_122 = 5 ;
V_121 -> V_110 . V_122 = 6 ;
V_121 -> V_111 . V_122 = 5 ;
V_121 -> V_124 . V_122 = 0 ;
V_121 -> V_124 . V_123 = 0 ;
break;
case 24 :
V_121 -> V_109 . V_123 = 16 ;
V_121 -> V_110 . V_123 = 8 ;
V_121 -> V_111 . V_123 = 0 ;
V_121 -> V_109 . V_122 = 8 ;
V_121 -> V_110 . V_122 = 8 ;
V_121 -> V_111 . V_122 = 8 ;
V_121 -> V_124 . V_122 = 0 ;
V_121 -> V_124 . V_123 = 0 ;
break;
case 32 :
V_121 -> V_109 . V_123 = 16 ;
V_121 -> V_110 . V_123 = 8 ;
V_121 -> V_111 . V_123 = 0 ;
V_121 -> V_109 . V_122 = 8 ;
V_121 -> V_110 . V_122 = 8 ;
V_121 -> V_111 . V_122 = 8 ;
V_121 -> V_124 . V_122 = 8 ;
V_121 -> V_124 . V_123 = 24 ;
break;
default:
return - V_119 ;
}
return 0 ;
}
int F_50 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_144 * V_121 = & V_44 -> V_121 ;
int V_66 ;
int V_7 ;
if ( V_121 -> V_145 != 0 ) {
F_17 ( L_16 ) ;
return - V_119 ;
}
F_30 ( V_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_66 = F_21 ( & V_2 -> V_51 [ V_7 ] . V_50 ) ;
if ( V_66 ) {
F_31 ( V_4 ) ;
return V_66 ;
}
}
F_31 ( V_4 ) ;
if ( V_2 -> V_150 ) {
V_2 -> V_150 = false ;
F_51 ( V_2 ) ;
}
return 0 ;
}
int F_52 ( struct V_144 * V_121 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_151 ;
int V_66 = 0 ;
int V_7 ;
F_30 ( V_4 ) ;
if ( ! F_25 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_136 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_151 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_151 -> V_56 = V_121 -> V_152 ;
V_151 -> V_57 = V_121 -> V_153 ;
if ( V_151 -> V_105 ) {
V_66 = F_21 ( V_151 ) ;
if ( ! V_66 ) {
V_44 -> V_121 . V_152 = V_121 -> V_152 ;
V_44 -> V_121 . V_153 = V_121 -> V_153 ;
}
}
}
F_31 ( V_4 ) ;
return V_66 ;
}
static int F_53 ( struct V_1 * V_2 ,
int V_154 )
{
int V_66 = 0 ;
int V_48 = 0 ;
int V_7 ;
struct V_43 * V_44 ;
struct V_155 V_156 ;
int V_41 = 0 ;
memset ( & V_156 , 0 , sizeof( struct V_155 ) ) ;
V_156 . V_157 = 24 ;
V_156 . V_158 = 32 ;
V_156 . V_159 = ( unsigned ) - 1 ;
V_156 . V_160 = ( unsigned ) - 1 ;
if ( V_154 != V_156 . V_158 )
V_156 . V_157 = V_156 . V_158 = V_154 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_15 = V_2 -> V_12 [ V_7 ] ;
struct V_16 * V_19 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_161 ) {
switch ( V_19 -> V_162 ) {
case 8 :
V_156 . V_157 = V_156 . V_158 = 8 ;
break;
case 15 :
V_156 . V_157 = 15 ;
V_156 . V_158 = 16 ;
break;
case 16 :
V_156 . V_157 = V_156 . V_158 = 16 ;
break;
case 24 :
V_156 . V_157 = V_156 . V_158 = 24 ;
break;
case 32 :
V_156 . V_157 = 24 ;
V_156 . V_158 = 32 ;
break;
}
break;
}
}
V_48 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_163 * V_164 ;
V_164 = V_2 -> V_51 [ V_7 ] . V_164 ;
if ( V_164 ) {
if ( V_41 == 0 )
V_41 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 -> V_41 ;
if ( V_164 -> V_165 < V_156 . V_159 )
V_156 . V_159 = V_164 -> V_165 ;
if ( V_164 -> V_166 < V_156 . V_160 )
V_156 . V_160 = V_164 -> V_166 ;
if ( V_164 -> V_165 > V_156 . V_167 )
V_156 . V_167 = V_164 -> V_165 ;
if ( V_164 -> V_166 > V_156 . V_168 )
V_156 . V_168 = V_164 -> V_166 ;
V_48 ++ ;
}
}
if ( V_48 == 0 || V_156 . V_159 == - 1 || V_156 . V_160 == - 1 ) {
F_9 ( L_17 ) ;
V_156 . V_159 = V_156 . V_167 = 1024 ;
V_156 . V_160 = V_156 . V_168 = 768 ;
}
V_66 = (* V_2 -> V_38 -> V_169 )( V_2 , & V_156 ) ;
if ( V_66 < 0 )
return V_66 ;
V_44 = V_2 -> V_170 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ )
if ( V_2 -> V_51 [ V_7 ] . V_50 . V_105 )
V_2 -> V_51 [ V_7 ] . V_50 . V_55 = V_2 -> V_55 ;
V_44 -> V_121 . V_145 = 0 ;
if ( F_54 ( V_44 ) < 0 )
return - V_119 ;
F_55 ( V_2 -> V_4 -> V_4 , L_18 ,
V_44 -> V_171 , V_44 -> V_114 . V_62 ) ;
if ( F_14 ( & V_47 ) ) {
F_55 ( V_2 -> V_4 -> V_4 , L_19 ) ;
F_56 ( & V_106 ,
& V_107 ) ;
F_57 ( 'v' , & V_108 ) ;
}
F_58 ( & V_2 -> V_101 , & V_47 ) ;
return 0 ;
}
void F_59 ( struct V_43 * V_44 , T_4 V_172 ,
T_4 V_127 )
{
V_44 -> V_114 . type = V_173 ;
V_44 -> V_114 . V_115 = V_127 == 8 ? V_174 :
V_116 ;
V_44 -> V_114 . V_175 = 0 ;
V_44 -> V_114 . V_176 = 0 ;
V_44 -> V_114 . V_177 = 0 ;
V_44 -> V_114 . V_178 = 1 ;
V_44 -> V_114 . V_179 = 1 ;
V_44 -> V_114 . V_180 = 0 ;
V_44 -> V_114 . V_181 = V_182 ;
V_44 -> V_114 . V_177 = 0 ;
V_44 -> V_114 . V_183 = V_172 ;
return;
}
void F_60 ( struct V_43 * V_44 , struct V_1 * V_2 ,
T_4 V_159 , T_4 V_160 )
{
struct V_59 * V_55 = V_2 -> V_55 ;
V_44 -> V_120 = V_2 -> V_120 ;
V_44 -> V_121 . V_148 = V_55 -> V_146 ;
V_44 -> V_121 . V_149 = V_55 -> V_147 ;
V_44 -> V_121 . V_126 = V_55 -> V_126 ;
V_44 -> V_121 . V_184 = V_185 ;
V_44 -> V_121 . V_152 = 0 ;
V_44 -> V_121 . V_153 = 0 ;
V_44 -> V_121 . V_186 = V_187 ;
V_44 -> V_121 . V_147 = - 1 ;
V_44 -> V_121 . V_146 = - 1 ;
switch ( V_55 -> V_127 ) {
case 8 :
V_44 -> V_121 . V_109 . V_123 = 0 ;
V_44 -> V_121 . V_110 . V_123 = 0 ;
V_44 -> V_121 . V_111 . V_123 = 0 ;
V_44 -> V_121 . V_109 . V_122 = 8 ;
V_44 -> V_121 . V_110 . V_122 = 8 ;
V_44 -> V_121 . V_111 . V_122 = 8 ;
V_44 -> V_121 . V_124 . V_123 = 0 ;
V_44 -> V_121 . V_124 . V_122 = 0 ;
break;
case 15 :
V_44 -> V_121 . V_109 . V_123 = 10 ;
V_44 -> V_121 . V_110 . V_123 = 5 ;
V_44 -> V_121 . V_111 . V_123 = 0 ;
V_44 -> V_121 . V_109 . V_122 = 5 ;
V_44 -> V_121 . V_110 . V_122 = 5 ;
V_44 -> V_121 . V_111 . V_122 = 5 ;
V_44 -> V_121 . V_124 . V_123 = 15 ;
V_44 -> V_121 . V_124 . V_122 = 1 ;
break;
case 16 :
V_44 -> V_121 . V_109 . V_123 = 11 ;
V_44 -> V_121 . V_110 . V_123 = 5 ;
V_44 -> V_121 . V_111 . V_123 = 0 ;
V_44 -> V_121 . V_109 . V_122 = 5 ;
V_44 -> V_121 . V_110 . V_122 = 6 ;
V_44 -> V_121 . V_111 . V_122 = 5 ;
V_44 -> V_121 . V_124 . V_123 = 0 ;
break;
case 24 :
V_44 -> V_121 . V_109 . V_123 = 16 ;
V_44 -> V_121 . V_110 . V_123 = 8 ;
V_44 -> V_121 . V_111 . V_123 = 0 ;
V_44 -> V_121 . V_109 . V_122 = 8 ;
V_44 -> V_121 . V_110 . V_122 = 8 ;
V_44 -> V_121 . V_111 . V_122 = 8 ;
V_44 -> V_121 . V_124 . V_123 = 0 ;
V_44 -> V_121 . V_124 . V_122 = 0 ;
break;
case 32 :
V_44 -> V_121 . V_109 . V_123 = 16 ;
V_44 -> V_121 . V_110 . V_123 = 8 ;
V_44 -> V_121 . V_111 . V_123 = 0 ;
V_44 -> V_121 . V_109 . V_122 = 8 ;
V_44 -> V_121 . V_110 . V_122 = 8 ;
V_44 -> V_121 . V_111 . V_122 = 8 ;
V_44 -> V_121 . V_124 . V_123 = 24 ;
V_44 -> V_121 . V_124 . V_122 = 8 ;
break;
default:
break;
}
V_44 -> V_121 . V_25 = V_159 ;
V_44 -> V_121 . V_26 = V_160 ;
}
static int F_61 ( struct V_1 * V_2 ,
T_4 V_188 ,
T_4 V_189 )
{
struct V_5 * V_6 ;
int V_190 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_190 += V_6 -> V_38 -> V_191 ( V_6 , V_188 , V_189 ) ;
}
return V_190 ;
}
static struct V_163 * F_62 ( struct V_8 * V_192 , int V_146 , int V_147 )
{
struct V_163 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( F_63 ( V_17 ) > V_146 ||
F_64 ( V_17 ) > V_147 )
continue;
if ( V_17 -> type & V_193 )
return V_17 ;
}
return NULL ;
}
static bool F_65 ( struct V_8 * V_192 )
{
struct V_16 * V_19 ;
V_19 = & V_192 -> V_19 ;
return V_19 -> V_194 ;
}
static struct V_163 * F_66 ( struct V_8 * V_15 ,
int V_146 , int V_147 )
{
struct V_16 * V_19 ;
struct V_163 * V_17 = NULL ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_194 == false )
return V_17 ;
if ( V_19 -> V_29 || V_19 -> V_30 )
goto V_195;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_165 != V_19 -> V_25 ||
V_17 -> V_166 != V_19 -> V_26 )
continue;
if ( V_19 -> V_27 ) {
if ( V_17 -> V_196 != V_19 -> V_28 )
continue;
}
if ( V_19 -> V_31 ) {
if ( ! ( V_17 -> V_197 & V_198 ) )
continue;
}
return V_17 ;
}
V_195:
V_17 = F_67 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_58 ( & V_17 -> V_199 , & V_15 -> V_6 -> V_200 ) ;
return V_17 ;
}
static bool F_68 ( struct V_5 * V_6 , bool V_201 )
{
bool V_202 ;
if ( V_201 )
V_202 = V_6 -> V_203 == V_204 ;
else
V_202 = V_6 -> V_203 != V_205 ;
return V_202 ;
}
static void F_69 ( struct V_1 * V_2 ,
bool * V_52 )
{
bool V_206 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_68 ( V_6 , true ) ;
F_10 ( L_20 , V_6 -> V_61 . V_62 ,
V_52 [ V_7 ] ? L_21 : L_22 ) ;
V_206 |= V_52 [ V_7 ] ;
}
if ( V_206 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_68 ( V_6 , false ) ;
}
}
static bool F_70 ( struct V_1 * V_2 ,
struct V_163 * * V_200 ,
bool * V_52 , int V_146 , int V_147 )
{
int V_190 , V_7 , V_84 ;
bool V_207 = false ;
struct V_8 * V_15 ;
struct V_163 * V_208 , * V_17 ;
if ( V_2 -> V_48 > 1 )
return false ;
V_190 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_52 [ V_7 ] )
V_190 ++ ;
}
if ( V_190 <= 1 )
return false ;
V_207 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_200 [ V_7 ] = F_66 ( V_15 , V_146 , V_147 ) ;
if ( ! V_200 [ V_7 ] ) {
V_207 = false ;
break;
}
for ( V_84 = 0 ; V_84 < V_7 ; V_84 ++ ) {
if ( ! V_52 [ V_84 ] )
continue;
if ( ! F_71 ( V_200 [ V_84 ] , V_200 [ V_7 ] ) )
V_207 = false ;
}
}
if ( V_207 ) {
F_10 ( L_23 ) ;
return true ;
}
V_207 = true ;
V_208 = F_72 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_71 ( V_17 , V_208 ) )
V_200 [ V_7 ] = V_17 ;
}
if ( ! V_200 [ V_7 ] )
V_207 = false ;
}
if ( V_207 ) {
F_10 ( L_24 ) ;
return true ;
}
F_9 ( L_25 ) ;
return false ;
}
static bool F_73 ( struct V_1 * V_2 ,
struct V_163 * * V_200 ,
bool * V_52 , int V_146 , int V_147 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_15 = V_2 -> V_12 [ V_7 ] ;
if ( V_52 [ V_7 ] == false )
continue;
F_10 ( L_26 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_200 [ V_7 ] = F_66 ( V_15 , V_146 , V_147 ) ;
if ( ! V_200 [ V_7 ] ) {
F_10 ( L_27 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_200 [ V_7 ] = F_62 ( V_15 , V_146 , V_147 ) ;
}
if ( ! V_200 [ V_7 ] && ! F_14 ( & V_15 -> V_6 -> V_200 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_10 ( L_28 , V_200 [ V_7 ] ? V_200 [ V_7 ] -> V_209 :
L_29 ) ;
}
return true ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_102 * * V_210 ,
struct V_163 * * V_200 ,
int V_71 , int V_146 , int V_147 )
{
int V_60 , V_211 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_212 * V_213 ;
struct V_214 * V_215 ;
int V_216 , V_217 , V_218 ;
struct V_102 * * V_219 , * V_33 ;
struct V_8 * V_15 ;
if ( V_71 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_71 ] ;
V_6 = V_15 -> V_6 ;
V_210 [ V_71 ] = NULL ;
V_217 = F_74 ( V_2 , V_210 , V_200 , V_71 + 1 , V_146 , V_147 ) ;
if ( V_200 [ V_71 ] == NULL )
return V_217 ;
V_219 = F_3 ( V_4 -> V_87 . V_103 *
sizeof( struct V_102 * ) , V_10 ) ;
if ( ! V_219 )
return V_217 ;
V_216 = 1 ;
if ( V_6 -> V_203 == V_204 )
V_216 ++ ;
if ( F_65 ( V_15 ) )
V_216 ++ ;
if ( F_62 ( V_15 , V_146 , V_147 ) )
V_216 ++ ;
V_213 = V_6 -> V_53 ;
V_215 = V_213 -> V_220 ( V_6 ) ;
if ( ! V_215 )
goto V_142;
for ( V_60 = 0 ; V_60 < V_2 -> V_48 ; V_60 ++ ) {
V_33 = & V_2 -> V_51 [ V_60 ] ;
if ( ( V_215 -> V_221 & ( 1 << V_60 ) ) == 0 )
continue;
for ( V_211 = 0 ; V_211 < V_71 ; V_211 ++ )
if ( V_210 [ V_211 ] == V_33 )
break;
if ( V_211 < V_71 ) {
if ( V_2 -> V_48 > 1 )
continue;
if ( ! F_71 ( V_200 [ V_211 ] , V_200 [ V_71 ] ) )
continue;
}
V_219 [ V_71 ] = V_33 ;
memcpy ( V_219 , V_210 , V_71 * sizeof( struct V_102 * ) ) ;
V_218 = V_216 + F_74 ( V_2 , V_219 , V_200 , V_71 + 1 ,
V_146 , V_147 ) ;
if ( V_218 > V_217 ) {
V_217 = V_218 ;
memcpy ( V_210 , V_219 ,
V_4 -> V_87 . V_103 *
sizeof( struct V_102 * ) ) ;
}
}
V_142:
F_4 ( V_219 ) ;
return V_217 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_102 * * V_219 ;
struct V_163 * * V_200 ;
struct V_49 * V_151 ;
bool * V_52 ;
int V_146 , V_147 ;
int V_7 ;
F_10 ( L_30 ) ;
V_146 = V_4 -> V_87 . V_222 ;
V_147 = V_4 -> V_87 . V_223 ;
V_219 = F_38 ( V_4 -> V_87 . V_103 ,
sizeof( struct V_102 * ) , V_10 ) ;
V_200 = F_38 ( V_4 -> V_87 . V_103 ,
sizeof( struct V_163 * ) , V_10 ) ;
V_52 = F_38 ( V_4 -> V_87 . V_103 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_219 || ! V_200 || ! V_52 ) {
F_17 ( L_31 ) ;
goto V_142;
}
F_69 ( V_2 , V_52 ) ;
if ( ! ( V_2 -> V_38 -> V_224 &&
V_2 -> V_38 -> V_224 ( V_2 , V_219 , V_200 ,
V_52 , V_146 , V_147 ) ) ) {
memset ( V_200 , 0 , V_4 -> V_87 . V_103 * sizeof( V_200 [ 0 ] ) ) ;
memset ( V_219 , 0 , V_4 -> V_87 . V_103 * sizeof( V_219 [ 0 ] ) ) ;
if ( ! F_70 ( V_2 ,
V_200 , V_52 , V_146 , V_147 ) &&
! F_73 ( V_2 ,
V_200 , V_52 , V_146 , V_147 ) )
F_17 ( L_32 ) ;
F_10 ( L_33 ,
V_146 , V_147 ) ;
F_74 ( V_2 , V_219 , V_200 , 0 , V_146 , V_147 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_151 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_151 -> V_105 = 0 ;
V_151 -> V_55 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_163 * V_17 = V_200 [ V_7 ] ;
struct V_102 * V_225 = V_219 [ V_7 ] ;
V_151 = & V_225 -> V_50 ;
if ( V_17 && V_225 ) {
F_10 ( L_34 ,
V_17 -> V_209 , V_225 -> V_50 . V_33 -> V_61 . V_62 ) ;
V_225 -> V_164 = V_17 ;
if ( V_151 -> V_17 )
F_35 ( V_4 , V_151 -> V_17 ) ;
V_151 -> V_17 = F_76 ( V_4 ,
V_225 -> V_164 ) ;
V_151 -> V_99 [ V_151 -> V_105 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_151 -> V_55 = V_2 -> V_55 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_151 = & V_2 -> V_51 [ V_7 ] . V_50 ;
if ( V_151 -> V_105 == 0 ) {
F_77 ( V_151 -> V_55 ) ;
F_77 ( V_151 -> V_105 ) ;
if ( V_151 -> V_17 )
F_35 ( V_4 , V_151 -> V_17 ) ;
V_151 -> V_17 = NULL ;
}
}
V_142:
F_4 ( V_219 ) ;
F_4 ( V_200 ) ;
F_4 ( V_52 ) ;
}
bool F_78 ( struct V_1 * V_2 , int V_226 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_190 = 0 ;
F_5 ( V_2 ) ;
V_190 = F_61 ( V_2 ,
V_4 -> V_87 . V_222 ,
V_4 -> V_87 . V_223 ) ;
if ( V_190 == 0 )
F_55 ( V_2 -> V_4 -> V_4 , L_35 ) ;
F_75 ( V_2 ) ;
return F_53 ( V_2 , V_226 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_222 , V_223 ;
if ( ! V_2 -> V_55 )
return 0 ;
F_79 ( & V_2 -> V_4 -> V_87 . V_227 ) ;
if ( ! F_25 ( V_2 ) ) {
V_2 -> V_150 = true ;
F_80 ( & V_2 -> V_4 -> V_87 . V_227 ) ;
return 0 ;
}
F_10 ( L_30 ) ;
V_222 = V_2 -> V_55 -> V_146 ;
V_223 = V_2 -> V_55 -> V_147 ;
F_61 ( V_2 , V_222 , V_223 ) ;
F_80 ( & V_2 -> V_4 -> V_87 . V_227 ) ;
F_30 ( V_4 ) ;
F_75 ( V_2 ) ;
F_31 ( V_4 ) ;
F_50 ( V_2 -> V_170 ) ;
return 0 ;
}
static int T_5 F_81 ( void )
{
const char * V_209 = L_36 ;
struct V_228 * V_229 ;
F_79 ( & V_230 ) ;
V_229 = F_82 ( V_209 ) ;
F_80 ( & V_230 ) ;
if ( ! V_229 )
F_83 ( V_209 ) ;
return 0 ;
}
