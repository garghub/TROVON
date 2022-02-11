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
return V_60 -> V_63 -> V_55 ;
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
V_33 -> V_57 , V_64 ) ;
}
return 0 ;
}
bool F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_65 * V_66 ;
bool error = false ;
int V_7 ;
F_19 ( V_4 ) ;
F_2 (plane, &dev->mode_config.plane_list, head)
if ( V_66 -> type != V_67 )
F_20 ( V_66 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_49 * V_50 = & V_2 -> V_51 [ V_7 ] . V_50 ;
struct V_32 * V_33 = V_50 -> V_33 ;
int V_68 ;
if ( V_33 -> V_38 -> V_69 ) {
V_68 = V_33 -> V_38 -> V_69 ( V_33 , NULL , 0 , 0 , 0 ) ;
if ( V_68 )
error = true ;
}
V_68 = F_21 ( V_50 ) ;
if ( V_68 )
error = true ;
}
return error ;
}
static bool F_22 ( void )
{
bool V_68 , error = false ;
struct V_1 * V_34 ;
if ( F_14 ( & V_47 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
if ( V_34 -> V_4 -> V_70 == V_71 )
continue;
V_68 = F_18 ( V_34 ) ;
if ( V_68 )
error = true ;
}
return error ;
}
static int F_23 ( struct V_72 * V_73 , unsigned long V_74 ,
void * V_75 )
{
if ( V_76 < 0 )
return 0 ;
F_24 ( L_11 ) ;
return F_22 () ;
}
static bool F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
int V_77 = 0 , V_78 = 0 ;
if ( V_4 -> V_63 -> V_79 )
return false ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_33 -> V_63 -> V_55 )
V_78 ++ ;
if ( V_33 -> V_63 -> V_55 == V_2 -> V_55 )
V_77 ++ ;
}
if ( V_77 < V_78 )
return false ;
return true ;
}
static void F_26 ( struct V_80 * V_81 )
{
bool V_68 ;
V_68 = F_22 () ;
if ( V_68 == true )
F_17 ( L_12 ) ;
}
static void F_27 ( int V_82 )
{
F_28 ( & V_83 ) ;
}
static void F_29 ( struct V_43 * V_44 , int V_84 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_5 * V_6 ;
int V_7 , V_85 ;
if ( V_86 )
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
for ( V_85 = 0 ; V_85 < V_2 -> V_13 ; V_85 ++ ) {
V_6 = V_2 -> V_12 [ V_85 ] -> V_6 ;
V_6 -> V_38 -> V_87 ( V_6 , V_84 ) ;
F_32 ( & V_6 -> V_61 ,
V_4 -> V_88 . V_89 , V_84 ) ;
}
}
F_31 ( V_4 ) ;
}
int F_33 ( int V_90 , struct V_43 * V_44 )
{
switch ( V_90 ) {
case V_91 :
F_29 ( V_44 , V_92 ) ;
break;
case V_93 :
F_29 ( V_44 , V_94 ) ;
break;
case V_95 :
F_29 ( V_44 , V_94 ) ;
break;
case V_96 :
F_29 ( V_44 , V_97 ) ;
break;
case V_98 :
F_29 ( V_44 , V_99 ) ;
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
F_4 ( V_34 -> V_51 [ V_7 ] . V_50 . V_100 ) ;
if ( V_34 -> V_51 [ V_7 ] . V_50 . V_17 )
F_35 ( V_34 -> V_4 , V_34 -> V_51 [ V_7 ] . V_50 . V_17 ) ;
}
F_4 ( V_34 -> V_51 ) ;
}
int F_36 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_48 , int V_101 )
{
struct V_32 * V_33 ;
int V_7 ;
if ( ! V_101 )
return - V_102 ;
V_2 -> V_4 = V_4 ;
F_37 ( & V_2 -> V_103 ) ;
V_2 -> V_51 = F_38 ( V_48 , sizeof( struct V_104 ) , V_10 ) ;
if ( ! V_2 -> V_51 )
return - V_14 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_12 = F_38 ( V_4 -> V_88 . V_105 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_51 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_100 =
F_38 ( V_101 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_51 [ V_7 ] . V_50 . V_100 )
goto V_106;
V_2 -> V_51 [ V_7 ] . V_50 . V_107 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_51 [ V_7 ] . V_50 . V_33 = V_33 ;
V_7 ++ ;
}
return 0 ;
V_106:
F_34 ( V_2 ) ;
return - V_14 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! F_14 ( & V_2 -> V_103 ) ) {
F_40 ( & V_2 -> V_103 ) ;
if ( F_14 ( & V_47 ) ) {
F_41 ( L_13 ) ;
F_42 ( & V_108 ,
& V_109 ) ;
F_43 ( 'v' , & V_110 ) ;
}
}
F_34 ( V_2 ) ;
}
static int F_44 ( struct V_32 * V_33 , T_2 V_111 , T_2 V_112 ,
T_2 V_113 , T_2 V_114 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_115 ;
if ( V_44 -> V_116 . V_117 == V_118 ) {
T_3 * V_119 ;
T_3 V_120 ;
if ( V_114 > 16 )
return - V_102 ;
V_119 = ( T_3 * ) V_44 -> V_121 ;
V_111 >>= ( 16 - V_44 -> V_122 . V_111 . V_123 ) ;
V_112 >>= ( 16 - V_44 -> V_122 . V_112 . V_123 ) ;
V_113 >>= ( 16 - V_44 -> V_122 . V_113 . V_123 ) ;
V_120 = ( V_111 << V_44 -> V_122 . V_111 . V_124 ) |
( V_112 << V_44 -> V_122 . V_112 . V_124 ) |
( V_113 << V_44 -> V_122 . V_113 . V_124 ) ;
if ( V_44 -> V_122 . V_125 . V_123 > 0 ) {
T_3 V_126 = ( 1 << V_44 -> V_122 . V_125 . V_123 ) - 1 ;
V_126 <<= V_44 -> V_122 . V_125 . V_124 ;
V_120 |= V_126 ;
}
V_119 [ V_114 ] = V_120 ;
return 0 ;
}
if ( F_45 ( ! V_2 -> V_38 -> V_42 ||
! V_2 -> V_38 -> V_39 ) )
return - V_102 ;
V_115 = V_114 ;
if ( V_55 -> V_127 == 16 ) {
V_115 = V_114 << 3 ;
if ( V_55 -> V_128 == 16 && V_114 > 63 )
return - V_102 ;
if ( V_55 -> V_128 == 15 && V_114 > 31 )
return - V_102 ;
if ( V_55 -> V_128 == 16 ) {
T_2 V_129 , V_130 , V_131 ;
int V_7 ;
if ( V_114 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_38 -> V_42 ( V_33 , V_111 ,
V_112 , V_113 , V_115 + V_7 ) ;
}
V_2 -> V_38 -> V_39 ( V_33 , & V_129 ,
& V_130 , & V_131 ,
V_115 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_38 -> V_42 ( V_33 , V_129 ,
V_112 , V_131 ,
( V_115 >> 1 ) + V_7 ) ;
}
}
if ( V_55 -> V_128 != 16 )
V_2 -> V_38 -> V_42 ( V_33 , V_111 , V_112 , V_113 , V_115 ) ;
return 0 ;
}
int F_46 ( struct V_132 * V_133 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_46 * V_134 ;
T_2 * V_111 , * V_112 , * V_113 , * V_125 ;
struct V_32 * V_33 ;
int V_7 , V_85 , V_135 = 0 ;
int V_136 ;
F_30 ( V_4 ) ;
if ( ! F_25 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_137 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_134 = V_33 -> V_53 ;
V_111 = V_133 -> V_111 ;
V_112 = V_133 -> V_112 ;
V_113 = V_133 -> V_113 ;
V_125 = V_133 -> V_125 ;
V_136 = V_133 -> V_136 ;
for ( V_85 = 0 ; V_85 < V_133 -> V_138 ; V_85 ++ ) {
T_2 V_139 , V_140 , V_141 , V_142 = 0xffff ;
V_139 = * V_111 ++ ;
V_140 = * V_112 ++ ;
V_141 = * V_113 ++ ;
if ( V_125 )
V_142 = * V_125 ++ ;
V_135 = F_44 ( V_33 , V_139 , V_140 , V_141 , V_136 ++ , V_44 ) ;
if ( V_135 )
goto V_143;
}
if ( V_134 -> V_144 )
V_134 -> V_144 ( V_33 ) ;
}
V_143:
F_31 ( V_4 ) ;
return V_135 ;
}
int F_47 ( struct V_145 * V_122 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_128 ;
if ( V_122 -> V_146 != 0 || F_48 () )
return - V_102 ;
if ( V_122 -> V_127 > V_55 -> V_127 ||
V_122 -> V_25 > V_55 -> V_147 || V_122 -> V_26 > V_55 -> V_148 ||
V_122 -> V_149 > V_55 -> V_147 || V_122 -> V_150 > V_55 -> V_148 ) {
F_49 ( L_14
L_15 ,
V_122 -> V_25 , V_122 -> V_26 , V_122 -> V_127 ,
V_122 -> V_149 , V_122 -> V_150 ,
V_55 -> V_147 , V_55 -> V_148 , V_55 -> V_127 ) ;
return - V_102 ;
}
switch ( V_122 -> V_127 ) {
case 16 :
V_128 = ( V_122 -> V_112 . V_123 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_128 = ( V_122 -> V_125 . V_123 > 0 ) ? 32 : 24 ;
break;
default:
V_128 = V_122 -> V_127 ;
break;
}
switch ( V_128 ) {
case 8 :
V_122 -> V_111 . V_124 = 0 ;
V_122 -> V_112 . V_124 = 0 ;
V_122 -> V_113 . V_124 = 0 ;
V_122 -> V_111 . V_123 = 8 ;
V_122 -> V_112 . V_123 = 8 ;
V_122 -> V_113 . V_123 = 8 ;
V_122 -> V_125 . V_123 = 0 ;
V_122 -> V_125 . V_124 = 0 ;
break;
case 15 :
V_122 -> V_111 . V_124 = 10 ;
V_122 -> V_112 . V_124 = 5 ;
V_122 -> V_113 . V_124 = 0 ;
V_122 -> V_111 . V_123 = 5 ;
V_122 -> V_112 . V_123 = 5 ;
V_122 -> V_113 . V_123 = 5 ;
V_122 -> V_125 . V_123 = 1 ;
V_122 -> V_125 . V_124 = 15 ;
break;
case 16 :
V_122 -> V_111 . V_124 = 11 ;
V_122 -> V_112 . V_124 = 5 ;
V_122 -> V_113 . V_124 = 0 ;
V_122 -> V_111 . V_123 = 5 ;
V_122 -> V_112 . V_123 = 6 ;
V_122 -> V_113 . V_123 = 5 ;
V_122 -> V_125 . V_123 = 0 ;
V_122 -> V_125 . V_124 = 0 ;
break;
case 24 :
V_122 -> V_111 . V_124 = 16 ;
V_122 -> V_112 . V_124 = 8 ;
V_122 -> V_113 . V_124 = 0 ;
V_122 -> V_111 . V_123 = 8 ;
V_122 -> V_112 . V_123 = 8 ;
V_122 -> V_113 . V_123 = 8 ;
V_122 -> V_125 . V_123 = 0 ;
V_122 -> V_125 . V_124 = 0 ;
break;
case 32 :
V_122 -> V_111 . V_124 = 16 ;
V_122 -> V_112 . V_124 = 8 ;
V_122 -> V_113 . V_124 = 0 ;
V_122 -> V_111 . V_123 = 8 ;
V_122 -> V_112 . V_123 = 8 ;
V_122 -> V_113 . V_123 = 8 ;
V_122 -> V_125 . V_123 = 8 ;
V_122 -> V_125 . V_124 = 24 ;
break;
default:
return - V_102 ;
}
return 0 ;
}
int F_50 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_145 * V_122 = & V_44 -> V_122 ;
if ( V_122 -> V_146 != 0 ) {
F_17 ( L_16 ) ;
return - V_102 ;
}
F_30 ( V_4 ) ;
F_18 ( V_2 ) ;
F_31 ( V_4 ) ;
if ( V_2 -> V_151 ) {
V_2 -> V_151 = false ;
F_51 ( V_2 ) ;
}
return 0 ;
}
int F_52 ( struct V_145 * V_122 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_152 ;
int V_68 = 0 ;
int V_7 ;
F_30 ( V_4 ) ;
if ( ! F_25 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_137 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_152 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_152 -> V_56 = V_122 -> V_153 ;
V_152 -> V_57 = V_122 -> V_154 ;
if ( V_152 -> V_107 ) {
V_68 = F_21 ( V_152 ) ;
if ( ! V_68 ) {
V_44 -> V_122 . V_153 = V_122 -> V_153 ;
V_44 -> V_122 . V_154 = V_122 -> V_154 ;
}
}
}
F_31 ( V_4 ) ;
return V_68 ;
}
static int F_53 ( struct V_1 * V_2 ,
int V_155 )
{
int V_68 = 0 ;
int V_48 = 0 ;
int V_7 ;
struct V_43 * V_44 ;
struct V_156 V_157 ;
int V_41 = 0 ;
memset ( & V_157 , 0 , sizeof( struct V_156 ) ) ;
V_157 . V_158 = 24 ;
V_157 . V_159 = 32 ;
V_157 . V_160 = ( unsigned ) - 1 ;
V_157 . V_161 = ( unsigned ) - 1 ;
if ( V_155 != V_157 . V_159 )
V_157 . V_158 = V_157 . V_159 = V_155 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_15 = V_2 -> V_12 [ V_7 ] ;
struct V_16 * V_19 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_162 ) {
switch ( V_19 -> V_163 ) {
case 8 :
V_157 . V_158 = V_157 . V_159 = 8 ;
break;
case 15 :
V_157 . V_158 = 15 ;
V_157 . V_159 = 16 ;
break;
case 16 :
V_157 . V_158 = V_157 . V_159 = 16 ;
break;
case 24 :
V_157 . V_158 = V_157 . V_159 = 24 ;
break;
case 32 :
V_157 . V_158 = 24 ;
V_157 . V_159 = 32 ;
break;
}
break;
}
}
V_48 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_164 * V_165 ;
V_165 = V_2 -> V_51 [ V_7 ] . V_165 ;
if ( V_165 ) {
if ( V_41 == 0 )
V_41 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 -> V_41 ;
if ( V_165 -> V_166 < V_157 . V_160 )
V_157 . V_160 = V_165 -> V_166 ;
if ( V_165 -> V_167 < V_157 . V_161 )
V_157 . V_161 = V_165 -> V_167 ;
if ( V_165 -> V_166 > V_157 . V_168 )
V_157 . V_168 = V_165 -> V_166 ;
if ( V_165 -> V_167 > V_157 . V_169 )
V_157 . V_169 = V_165 -> V_167 ;
V_48 ++ ;
}
}
if ( V_48 == 0 || V_157 . V_160 == - 1 || V_157 . V_161 == - 1 ) {
F_9 ( L_17 ) ;
V_157 . V_160 = V_157 . V_168 = 1024 ;
V_157 . V_161 = V_157 . V_169 = 768 ;
}
V_68 = (* V_2 -> V_38 -> V_170 )( V_2 , & V_157 ) ;
if ( V_68 < 0 )
return V_68 ;
V_44 = V_2 -> V_171 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ )
if ( V_2 -> V_51 [ V_7 ] . V_50 . V_107 )
V_2 -> V_51 [ V_7 ] . V_50 . V_55 = V_2 -> V_55 ;
V_44 -> V_122 . V_146 = 0 ;
if ( F_54 ( V_44 ) < 0 )
return - V_102 ;
F_55 ( V_2 -> V_4 -> V_4 , L_18 ,
V_44 -> V_172 , V_44 -> V_116 . V_62 ) ;
if ( F_14 ( & V_47 ) ) {
F_55 ( V_2 -> V_4 -> V_4 , L_19 ) ;
F_56 ( & V_108 ,
& V_109 ) ;
F_57 ( 'v' , & V_110 ) ;
}
F_58 ( & V_2 -> V_103 , & V_47 ) ;
return 0 ;
}
void F_59 ( struct V_43 * V_44 , T_4 V_173 ,
T_4 V_128 )
{
V_44 -> V_116 . type = V_174 ;
V_44 -> V_116 . V_117 = V_128 == 8 ? V_175 :
V_118 ;
V_44 -> V_116 . V_176 = 0 ;
V_44 -> V_116 . V_177 = 0 ;
V_44 -> V_116 . V_178 = 0 ;
V_44 -> V_116 . V_179 = 1 ;
V_44 -> V_116 . V_180 = 1 ;
V_44 -> V_116 . V_181 = 0 ;
V_44 -> V_116 . V_182 = V_183 ;
V_44 -> V_116 . V_178 = 0 ;
V_44 -> V_116 . V_184 = V_173 ;
return;
}
void F_60 ( struct V_43 * V_44 , struct V_1 * V_2 ,
T_4 V_160 , T_4 V_161 )
{
struct V_59 * V_55 = V_2 -> V_55 ;
V_44 -> V_121 = V_2 -> V_121 ;
V_44 -> V_122 . V_149 = V_55 -> V_147 ;
V_44 -> V_122 . V_150 = V_55 -> V_148 ;
V_44 -> V_122 . V_127 = V_55 -> V_127 ;
V_44 -> V_122 . V_185 = V_186 ;
V_44 -> V_122 . V_153 = 0 ;
V_44 -> V_122 . V_154 = 0 ;
V_44 -> V_122 . V_187 = V_188 ;
V_44 -> V_122 . V_148 = - 1 ;
V_44 -> V_122 . V_147 = - 1 ;
switch ( V_55 -> V_128 ) {
case 8 :
V_44 -> V_122 . V_111 . V_124 = 0 ;
V_44 -> V_122 . V_112 . V_124 = 0 ;
V_44 -> V_122 . V_113 . V_124 = 0 ;
V_44 -> V_122 . V_111 . V_123 = 8 ;
V_44 -> V_122 . V_112 . V_123 = 8 ;
V_44 -> V_122 . V_113 . V_123 = 8 ;
V_44 -> V_122 . V_125 . V_124 = 0 ;
V_44 -> V_122 . V_125 . V_123 = 0 ;
break;
case 15 :
V_44 -> V_122 . V_111 . V_124 = 10 ;
V_44 -> V_122 . V_112 . V_124 = 5 ;
V_44 -> V_122 . V_113 . V_124 = 0 ;
V_44 -> V_122 . V_111 . V_123 = 5 ;
V_44 -> V_122 . V_112 . V_123 = 5 ;
V_44 -> V_122 . V_113 . V_123 = 5 ;
V_44 -> V_122 . V_125 . V_124 = 15 ;
V_44 -> V_122 . V_125 . V_123 = 1 ;
break;
case 16 :
V_44 -> V_122 . V_111 . V_124 = 11 ;
V_44 -> V_122 . V_112 . V_124 = 5 ;
V_44 -> V_122 . V_113 . V_124 = 0 ;
V_44 -> V_122 . V_111 . V_123 = 5 ;
V_44 -> V_122 . V_112 . V_123 = 6 ;
V_44 -> V_122 . V_113 . V_123 = 5 ;
V_44 -> V_122 . V_125 . V_124 = 0 ;
break;
case 24 :
V_44 -> V_122 . V_111 . V_124 = 16 ;
V_44 -> V_122 . V_112 . V_124 = 8 ;
V_44 -> V_122 . V_113 . V_124 = 0 ;
V_44 -> V_122 . V_111 . V_123 = 8 ;
V_44 -> V_122 . V_112 . V_123 = 8 ;
V_44 -> V_122 . V_113 . V_123 = 8 ;
V_44 -> V_122 . V_125 . V_124 = 0 ;
V_44 -> V_122 . V_125 . V_123 = 0 ;
break;
case 32 :
V_44 -> V_122 . V_111 . V_124 = 16 ;
V_44 -> V_122 . V_112 . V_124 = 8 ;
V_44 -> V_122 . V_113 . V_124 = 0 ;
V_44 -> V_122 . V_111 . V_123 = 8 ;
V_44 -> V_122 . V_112 . V_123 = 8 ;
V_44 -> V_122 . V_113 . V_123 = 8 ;
V_44 -> V_122 . V_125 . V_124 = 24 ;
V_44 -> V_122 . V_125 . V_123 = 8 ;
break;
default:
break;
}
V_44 -> V_122 . V_25 = V_160 ;
V_44 -> V_122 . V_26 = V_161 ;
}
static int F_61 ( struct V_1 * V_2 ,
T_4 V_189 ,
T_4 V_190 )
{
struct V_5 * V_6 ;
int V_191 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_191 += V_6 -> V_38 -> V_192 ( V_6 , V_189 , V_190 ) ;
}
return V_191 ;
}
struct V_164 * F_62 ( struct V_8 * V_193 , int V_147 , int V_148 )
{
struct V_164 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( V_17 -> V_166 > V_147 ||
V_17 -> V_167 > V_148 )
continue;
if ( V_17 -> type & V_194 )
return V_17 ;
}
return NULL ;
}
static bool F_63 ( struct V_8 * V_193 )
{
struct V_16 * V_19 ;
V_19 = & V_193 -> V_19 ;
return V_19 -> V_195 ;
}
struct V_164 * F_64 ( struct V_8 * V_15 ,
int V_147 , int V_148 )
{
struct V_16 * V_19 ;
struct V_164 * V_17 = NULL ;
bool V_196 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_195 == false )
return V_17 ;
if ( V_19 -> V_29 || V_19 -> V_30 )
goto V_197;
V_196 = ! V_19 -> V_31 ;
V_198:
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_166 != V_19 -> V_25 ||
V_17 -> V_167 != V_19 -> V_26 )
continue;
if ( V_19 -> V_27 ) {
if ( V_17 -> V_199 != V_19 -> V_28 )
continue;
}
if ( V_19 -> V_31 ) {
if ( ! ( V_17 -> V_200 & V_201 ) )
continue;
} else if ( V_196 ) {
if ( V_17 -> V_200 & V_201 )
continue;
}
return V_17 ;
}
if ( V_196 ) {
V_196 = false ;
goto V_198;
}
V_197:
V_17 = F_65 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_58 ( & V_17 -> V_202 , & V_15 -> V_6 -> V_203 ) ;
return V_17 ;
}
static bool F_66 ( struct V_5 * V_6 , bool V_204 )
{
bool V_205 ;
if ( V_204 )
V_205 = V_6 -> V_206 == V_207 ;
else
V_205 = V_6 -> V_206 != V_208 ;
return V_205 ;
}
static void F_67 ( struct V_1 * V_2 ,
bool * V_52 )
{
bool V_209 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_66 ( V_6 , true ) ;
F_10 ( L_20 , V_6 -> V_61 . V_62 ,
V_52 [ V_7 ] ? L_21 : L_22 ) ;
V_209 |= V_52 [ V_7 ] ;
}
if ( V_209 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_66 ( V_6 , false ) ;
}
}
static bool F_68 ( struct V_1 * V_2 ,
struct V_164 * * V_203 ,
bool * V_52 , int V_147 , int V_148 )
{
int V_191 , V_7 , V_85 ;
bool V_210 = false ;
struct V_8 * V_15 ;
struct V_164 * V_211 , * V_17 ;
if ( V_2 -> V_48 > 1 )
return false ;
V_191 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_52 [ V_7 ] )
V_191 ++ ;
}
if ( V_191 <= 1 )
return false ;
V_210 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_203 [ V_7 ] = F_64 ( V_15 , V_147 , V_148 ) ;
if ( ! V_203 [ V_7 ] ) {
V_210 = false ;
break;
}
for ( V_85 = 0 ; V_85 < V_7 ; V_85 ++ ) {
if ( ! V_52 [ V_85 ] )
continue;
if ( ! F_69 ( V_203 [ V_85 ] , V_203 [ V_7 ] ) )
V_210 = false ;
}
}
if ( V_210 ) {
F_10 ( L_23 ) ;
return true ;
}
V_210 = true ;
V_211 = F_70 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_69 ( V_17 , V_211 ) )
V_203 [ V_7 ] = V_17 ;
}
if ( ! V_203 [ V_7 ] )
V_210 = false ;
}
if ( V_210 ) {
F_10 ( L_24 ) ;
return true ;
}
F_9 ( L_25 ) ;
return false ;
}
static bool F_71 ( struct V_1 * V_2 ,
struct V_164 * * V_203 ,
bool * V_52 , int V_147 , int V_148 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_15 = V_2 -> V_12 [ V_7 ] ;
if ( V_52 [ V_7 ] == false )
continue;
F_10 ( L_26 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_203 [ V_7 ] = F_64 ( V_15 , V_147 , V_148 ) ;
if ( ! V_203 [ V_7 ] ) {
F_10 ( L_27 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_203 [ V_7 ] = F_62 ( V_15 , V_147 , V_148 ) ;
}
if ( ! V_203 [ V_7 ] && ! F_14 ( & V_15 -> V_6 -> V_203 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_10 ( L_28 , V_203 [ V_7 ] ? V_203 [ V_7 ] -> V_212 :
L_29 ) ;
}
return true ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_104 * * V_213 ,
struct V_164 * * V_203 ,
int V_73 , int V_147 , int V_148 )
{
int V_60 , V_214 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
int V_219 , V_220 , V_221 ;
struct V_104 * * V_222 , * V_33 ;
struct V_8 * V_15 ;
if ( V_73 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_73 ] ;
V_6 = V_15 -> V_6 ;
V_213 [ V_73 ] = NULL ;
V_220 = F_72 ( V_2 , V_213 , V_203 , V_73 + 1 , V_147 , V_148 ) ;
if ( V_203 [ V_73 ] == NULL )
return V_220 ;
V_222 = F_3 ( V_4 -> V_88 . V_105 *
sizeof( struct V_104 * ) , V_10 ) ;
if ( ! V_222 )
return V_220 ;
V_219 = 1 ;
if ( V_6 -> V_206 == V_207 )
V_219 ++ ;
if ( F_63 ( V_15 ) )
V_219 ++ ;
if ( F_62 ( V_15 , V_147 , V_148 ) )
V_219 ++ ;
V_216 = V_6 -> V_53 ;
V_218 = V_216 -> V_223 ( V_6 ) ;
if ( ! V_218 )
goto V_143;
for ( V_60 = 0 ; V_60 < V_2 -> V_48 ; V_60 ++ ) {
V_33 = & V_2 -> V_51 [ V_60 ] ;
if ( ( V_218 -> V_224 & ( 1 << V_60 ) ) == 0 )
continue;
for ( V_214 = 0 ; V_214 < V_73 ; V_214 ++ )
if ( V_213 [ V_214 ] == V_33 )
break;
if ( V_214 < V_73 ) {
if ( V_2 -> V_48 > 1 )
continue;
if ( ! F_69 ( V_203 [ V_214 ] , V_203 [ V_73 ] ) )
continue;
}
V_222 [ V_73 ] = V_33 ;
memcpy ( V_222 , V_213 , V_73 * sizeof( struct V_104 * ) ) ;
V_221 = V_219 + F_72 ( V_2 , V_222 , V_203 , V_73 + 1 ,
V_147 , V_148 ) ;
if ( V_221 > V_220 ) {
V_220 = V_221 ;
memcpy ( V_213 , V_222 ,
V_4 -> V_88 . V_105 *
sizeof( struct V_104 * ) ) ;
}
}
V_143:
F_4 ( V_222 ) ;
return V_220 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_104 * * V_222 ;
struct V_164 * * V_203 ;
struct V_49 * V_152 ;
bool * V_52 ;
int V_147 , V_148 ;
int V_7 ;
F_10 ( L_30 ) ;
V_147 = V_4 -> V_88 . V_225 ;
V_148 = V_4 -> V_88 . V_226 ;
V_222 = F_38 ( V_4 -> V_88 . V_105 ,
sizeof( struct V_104 * ) , V_10 ) ;
V_203 = F_38 ( V_4 -> V_88 . V_105 ,
sizeof( struct V_164 * ) , V_10 ) ;
V_52 = F_38 ( V_4 -> V_88 . V_105 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_222 || ! V_203 || ! V_52 ) {
F_17 ( L_31 ) ;
goto V_143;
}
F_67 ( V_2 , V_52 ) ;
if ( ! ( V_2 -> V_38 -> V_227 &&
V_2 -> V_38 -> V_227 ( V_2 , V_222 , V_203 ,
V_52 , V_147 , V_148 ) ) ) {
memset ( V_203 , 0 , V_4 -> V_88 . V_105 * sizeof( V_203 [ 0 ] ) ) ;
memset ( V_222 , 0 , V_4 -> V_88 . V_105 * sizeof( V_222 [ 0 ] ) ) ;
if ( ! F_68 ( V_2 ,
V_203 , V_52 , V_147 , V_148 ) &&
! F_71 ( V_2 ,
V_203 , V_52 , V_147 , V_148 ) )
F_17 ( L_32 ) ;
F_10 ( L_33 ,
V_147 , V_148 ) ;
F_72 ( V_2 , V_222 , V_203 , 0 , V_147 , V_148 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_152 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_152 -> V_107 = 0 ;
V_152 -> V_55 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_164 * V_17 = V_203 [ V_7 ] ;
struct V_104 * V_228 = V_222 [ V_7 ] ;
V_152 = & V_228 -> V_50 ;
if ( V_17 && V_228 ) {
F_10 ( L_34 ,
V_17 -> V_212 , V_228 -> V_50 . V_33 -> V_61 . V_62 ) ;
V_228 -> V_165 = V_17 ;
if ( V_152 -> V_17 )
F_35 ( V_4 , V_152 -> V_17 ) ;
V_152 -> V_17 = F_74 ( V_4 ,
V_228 -> V_165 ) ;
V_152 -> V_100 [ V_152 -> V_107 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_152 -> V_55 = V_2 -> V_55 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_152 = & V_2 -> V_51 [ V_7 ] . V_50 ;
if ( V_152 -> V_107 == 0 ) {
F_75 ( V_152 -> V_55 ) ;
F_75 ( V_152 -> V_107 ) ;
if ( V_152 -> V_17 )
F_35 ( V_4 , V_152 -> V_17 ) ;
V_152 -> V_17 = NULL ;
}
}
V_143:
F_4 ( V_222 ) ;
F_4 ( V_203 ) ;
F_4 ( V_52 ) ;
}
bool F_76 ( struct V_1 * V_2 , int V_229 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_191 = 0 ;
F_5 ( V_2 ) ;
F_77 ( & V_4 -> V_88 . V_230 ) ;
V_191 = F_61 ( V_2 ,
V_4 -> V_88 . V_225 ,
V_4 -> V_88 . V_226 ) ;
F_78 ( & V_4 -> V_88 . V_230 ) ;
if ( V_191 == 0 )
F_55 ( V_2 -> V_4 -> V_4 , L_35 ) ;
F_73 ( V_2 ) ;
return F_53 ( V_2 , V_229 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_225 , V_226 ;
if ( ! V_2 -> V_55 )
return 0 ;
F_77 ( & V_2 -> V_4 -> V_88 . V_230 ) ;
if ( ! F_25 ( V_2 ) ) {
V_2 -> V_151 = true ;
F_78 ( & V_2 -> V_4 -> V_88 . V_230 ) ;
return 0 ;
}
F_10 ( L_30 ) ;
V_225 = V_2 -> V_55 -> V_147 ;
V_226 = V_2 -> V_55 -> V_148 ;
F_61 ( V_2 , V_225 , V_226 ) ;
F_78 ( & V_2 -> V_4 -> V_88 . V_230 ) ;
F_30 ( V_4 ) ;
F_73 ( V_2 ) ;
F_31 ( V_4 ) ;
F_50 ( V_2 -> V_171 ) ;
return 0 ;
}
static int T_5 F_79 ( void )
{
const char * V_212 = L_36 ;
struct V_231 * V_232 ;
F_77 ( & V_233 ) ;
V_232 = F_80 ( V_212 ) ;
F_78 ( & V_233 ) ;
if ( ! V_232 )
F_81 ( V_212 ) ;
return 0 ;
}
