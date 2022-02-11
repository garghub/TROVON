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
static void F_26 ( struct V_77 * V_78 )
{
bool V_66 ;
V_66 = F_22 () ;
if ( V_66 == true )
F_17 ( L_12 ) ;
}
static void F_27 ( int V_79 )
{
F_28 ( & V_80 ) ;
}
static void F_29 ( struct V_43 * V_44 , int V_81 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_5 * V_6 ;
int V_7 , V_82 ;
if ( V_83 )
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
for ( V_82 = 0 ; V_82 < V_2 -> V_13 ; V_82 ++ ) {
V_6 = V_2 -> V_12 [ V_82 ] -> V_6 ;
V_6 -> V_38 -> V_84 ( V_6 , V_81 ) ;
F_32 ( & V_6 -> V_61 ,
V_4 -> V_85 . V_86 , V_81 ) ;
}
}
F_31 ( V_4 ) ;
}
int F_33 ( int V_87 , struct V_43 * V_44 )
{
switch ( V_87 ) {
case V_88 :
F_29 ( V_44 , V_89 ) ;
break;
case V_90 :
F_29 ( V_44 , V_91 ) ;
break;
case V_92 :
F_29 ( V_44 , V_91 ) ;
break;
case V_93 :
F_29 ( V_44 , V_94 ) ;
break;
case V_95 :
F_29 ( V_44 , V_96 ) ;
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
F_4 ( V_34 -> V_51 [ V_7 ] . V_50 . V_97 ) ;
if ( V_34 -> V_51 [ V_7 ] . V_50 . V_17 )
F_35 ( V_34 -> V_4 , V_34 -> V_51 [ V_7 ] . V_50 . V_17 ) ;
}
F_4 ( V_34 -> V_51 ) ;
}
int F_36 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_48 , int V_98 )
{
struct V_32 * V_33 ;
int V_7 ;
V_2 -> V_4 = V_4 ;
F_37 ( & V_2 -> V_99 ) ;
V_2 -> V_51 = F_38 ( V_48 , sizeof( struct V_100 ) , V_10 ) ;
if ( ! V_2 -> V_51 )
return - V_14 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_12 = F_38 ( V_4 -> V_85 . V_101 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_51 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_97 =
F_38 ( V_98 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_51 [ V_7 ] . V_50 . V_97 )
goto V_102;
V_2 -> V_51 [ V_7 ] . V_50 . V_103 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_51 [ V_7 ] . V_50 . V_33 = V_33 ;
V_7 ++ ;
}
return 0 ;
V_102:
F_34 ( V_2 ) ;
return - V_14 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! F_14 ( & V_2 -> V_99 ) ) {
F_40 ( & V_2 -> V_99 ) ;
if ( F_14 ( & V_47 ) ) {
F_41 ( L_13 ) ;
F_42 ( & V_104 ,
& V_105 ) ;
F_43 ( 'v' , & V_106 ) ;
}
}
F_34 ( V_2 ) ;
}
static int F_44 ( struct V_32 * V_33 , T_2 V_107 , T_2 V_108 ,
T_2 V_109 , T_2 V_110 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_111 ;
if ( V_44 -> V_112 . V_113 == V_114 ) {
T_3 * V_115 ;
T_3 V_116 ;
if ( V_110 > 16 )
return - V_117 ;
V_115 = ( T_3 * ) V_44 -> V_118 ;
V_107 >>= ( 16 - V_44 -> V_119 . V_107 . V_120 ) ;
V_108 >>= ( 16 - V_44 -> V_119 . V_108 . V_120 ) ;
V_109 >>= ( 16 - V_44 -> V_119 . V_109 . V_120 ) ;
V_116 = ( V_107 << V_44 -> V_119 . V_107 . V_121 ) |
( V_108 << V_44 -> V_119 . V_108 . V_121 ) |
( V_109 << V_44 -> V_119 . V_109 . V_121 ) ;
if ( V_44 -> V_119 . V_122 . V_120 > 0 ) {
T_3 V_123 = ( 1 << V_44 -> V_119 . V_122 . V_120 ) - 1 ;
V_123 <<= V_44 -> V_119 . V_122 . V_121 ;
V_116 |= V_123 ;
}
V_115 [ V_110 ] = V_116 ;
return 0 ;
}
if ( F_45 ( ! V_2 -> V_38 -> V_42 ||
! V_2 -> V_38 -> V_39 ) )
return - V_117 ;
V_111 = V_110 ;
if ( V_55 -> V_124 == 16 ) {
V_111 = V_110 << 3 ;
if ( V_55 -> V_125 == 16 && V_110 > 63 )
return - V_117 ;
if ( V_55 -> V_125 == 15 && V_110 > 31 )
return - V_117 ;
if ( V_55 -> V_125 == 16 ) {
T_2 V_126 , V_127 , V_128 ;
int V_7 ;
if ( V_110 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_38 -> V_42 ( V_33 , V_107 ,
V_108 , V_109 , V_111 + V_7 ) ;
}
V_2 -> V_38 -> V_39 ( V_33 , & V_126 ,
& V_127 , & V_128 ,
V_111 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_38 -> V_42 ( V_33 , V_126 ,
V_108 , V_128 ,
( V_111 >> 1 ) + V_7 ) ;
}
}
if ( V_55 -> V_125 != 16 )
V_2 -> V_38 -> V_42 ( V_33 , V_107 , V_108 , V_109 , V_111 ) ;
return 0 ;
}
int F_46 ( struct V_129 * V_130 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_46 * V_131 ;
T_2 * V_107 , * V_108 , * V_109 , * V_122 ;
struct V_32 * V_33 ;
int V_7 , V_82 , V_132 = 0 ;
int V_133 ;
F_30 ( V_4 ) ;
if ( ! F_25 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_134 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_131 = V_33 -> V_53 ;
V_107 = V_130 -> V_107 ;
V_108 = V_130 -> V_108 ;
V_109 = V_130 -> V_109 ;
V_122 = V_130 -> V_122 ;
V_133 = V_130 -> V_133 ;
for ( V_82 = 0 ; V_82 < V_130 -> V_135 ; V_82 ++ ) {
T_2 V_136 , V_137 , V_138 , V_139 = 0xffff ;
V_136 = * V_107 ++ ;
V_137 = * V_108 ++ ;
V_138 = * V_109 ++ ;
if ( V_122 )
V_139 = * V_122 ++ ;
V_132 = F_44 ( V_33 , V_136 , V_137 , V_138 , V_133 ++ , V_44 ) ;
if ( V_132 )
goto V_140;
}
if ( V_131 -> V_141 )
V_131 -> V_141 ( V_33 ) ;
}
V_140:
F_31 ( V_4 ) ;
return V_132 ;
}
int F_47 ( struct V_142 * V_119 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_125 ;
if ( V_119 -> V_143 != 0 || F_48 () )
return - V_117 ;
if ( V_119 -> V_124 > V_55 -> V_124 ||
V_119 -> V_25 > V_55 -> V_144 || V_119 -> V_26 > V_55 -> V_145 ||
V_119 -> V_146 > V_55 -> V_144 || V_119 -> V_147 > V_55 -> V_145 ) {
F_49 ( L_14
L_15 ,
V_119 -> V_25 , V_119 -> V_26 , V_119 -> V_124 ,
V_119 -> V_146 , V_119 -> V_147 ,
V_55 -> V_144 , V_55 -> V_145 , V_55 -> V_124 ) ;
return - V_117 ;
}
switch ( V_119 -> V_124 ) {
case 16 :
V_125 = ( V_119 -> V_108 . V_120 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_125 = ( V_119 -> V_122 . V_120 > 0 ) ? 32 : 24 ;
break;
default:
V_125 = V_119 -> V_124 ;
break;
}
switch ( V_125 ) {
case 8 :
V_119 -> V_107 . V_121 = 0 ;
V_119 -> V_108 . V_121 = 0 ;
V_119 -> V_109 . V_121 = 0 ;
V_119 -> V_107 . V_120 = 8 ;
V_119 -> V_108 . V_120 = 8 ;
V_119 -> V_109 . V_120 = 8 ;
V_119 -> V_122 . V_120 = 0 ;
V_119 -> V_122 . V_121 = 0 ;
break;
case 15 :
V_119 -> V_107 . V_121 = 10 ;
V_119 -> V_108 . V_121 = 5 ;
V_119 -> V_109 . V_121 = 0 ;
V_119 -> V_107 . V_120 = 5 ;
V_119 -> V_108 . V_120 = 5 ;
V_119 -> V_109 . V_120 = 5 ;
V_119 -> V_122 . V_120 = 1 ;
V_119 -> V_122 . V_121 = 15 ;
break;
case 16 :
V_119 -> V_107 . V_121 = 11 ;
V_119 -> V_108 . V_121 = 5 ;
V_119 -> V_109 . V_121 = 0 ;
V_119 -> V_107 . V_120 = 5 ;
V_119 -> V_108 . V_120 = 6 ;
V_119 -> V_109 . V_120 = 5 ;
V_119 -> V_122 . V_120 = 0 ;
V_119 -> V_122 . V_121 = 0 ;
break;
case 24 :
V_119 -> V_107 . V_121 = 16 ;
V_119 -> V_108 . V_121 = 8 ;
V_119 -> V_109 . V_121 = 0 ;
V_119 -> V_107 . V_120 = 8 ;
V_119 -> V_108 . V_120 = 8 ;
V_119 -> V_109 . V_120 = 8 ;
V_119 -> V_122 . V_120 = 0 ;
V_119 -> V_122 . V_121 = 0 ;
break;
case 32 :
V_119 -> V_107 . V_121 = 16 ;
V_119 -> V_108 . V_121 = 8 ;
V_119 -> V_109 . V_121 = 0 ;
V_119 -> V_107 . V_120 = 8 ;
V_119 -> V_108 . V_120 = 8 ;
V_119 -> V_109 . V_120 = 8 ;
V_119 -> V_122 . V_120 = 8 ;
V_119 -> V_122 . V_121 = 24 ;
break;
default:
return - V_117 ;
}
return 0 ;
}
int F_50 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_142 * V_119 = & V_44 -> V_119 ;
int V_66 ;
int V_7 ;
if ( V_119 -> V_143 != 0 ) {
F_17 ( L_16 ) ;
return - V_117 ;
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
if ( V_2 -> V_148 ) {
V_2 -> V_148 = false ;
F_51 ( V_2 ) ;
}
return 0 ;
}
int F_52 ( struct V_142 * V_119 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_149 ;
struct V_32 * V_33 ;
int V_66 = 0 ;
int V_7 ;
F_30 ( V_4 ) ;
if ( ! F_25 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_134 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_149 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_149 -> V_56 = V_119 -> V_150 ;
V_149 -> V_57 = V_119 -> V_151 ;
if ( V_149 -> V_103 ) {
V_66 = F_21 ( V_149 ) ;
if ( ! V_66 ) {
V_44 -> V_119 . V_150 = V_119 -> V_150 ;
V_44 -> V_119 . V_151 = V_119 -> V_151 ;
}
}
}
F_31 ( V_4 ) ;
return V_66 ;
}
static int F_53 ( struct V_1 * V_2 ,
int V_152 )
{
int V_66 = 0 ;
int V_48 = 0 ;
int V_7 ;
struct V_43 * V_44 ;
struct V_153 V_154 ;
int V_41 = 0 ;
memset ( & V_154 , 0 , sizeof( struct V_153 ) ) ;
V_154 . V_155 = 24 ;
V_154 . V_156 = 32 ;
V_154 . V_157 = ( unsigned ) - 1 ;
V_154 . V_158 = ( unsigned ) - 1 ;
if ( V_152 != V_154 . V_156 )
V_154 . V_155 = V_154 . V_156 = V_152 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_15 = V_2 -> V_12 [ V_7 ] ;
struct V_16 * V_19 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_159 ) {
switch ( V_19 -> V_160 ) {
case 8 :
V_154 . V_155 = V_154 . V_156 = 8 ;
break;
case 15 :
V_154 . V_155 = 15 ;
V_154 . V_156 = 16 ;
break;
case 16 :
V_154 . V_155 = V_154 . V_156 = 16 ;
break;
case 24 :
V_154 . V_155 = V_154 . V_156 = 24 ;
break;
case 32 :
V_154 . V_155 = 24 ;
V_154 . V_156 = 32 ;
break;
}
break;
}
}
V_48 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_161 * V_162 ;
V_162 = V_2 -> V_51 [ V_7 ] . V_162 ;
if ( V_162 ) {
if ( V_41 == 0 )
V_41 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 -> V_41 ;
if ( V_162 -> V_163 < V_154 . V_157 )
V_154 . V_157 = V_162 -> V_163 ;
if ( V_162 -> V_164 < V_154 . V_158 )
V_154 . V_158 = V_162 -> V_164 ;
if ( V_162 -> V_163 > V_154 . V_165 )
V_154 . V_165 = V_162 -> V_163 ;
if ( V_162 -> V_164 > V_154 . V_166 )
V_154 . V_166 = V_162 -> V_164 ;
V_48 ++ ;
}
}
if ( V_48 == 0 || V_154 . V_157 == - 1 || V_154 . V_158 == - 1 ) {
F_9 ( L_17 ) ;
V_154 . V_157 = V_154 . V_165 = 1024 ;
V_154 . V_158 = V_154 . V_166 = 768 ;
}
V_66 = (* V_2 -> V_38 -> V_167 )( V_2 , & V_154 ) ;
if ( V_66 < 0 )
return V_66 ;
V_44 = V_2 -> V_168 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ )
if ( V_2 -> V_51 [ V_7 ] . V_50 . V_103 )
V_2 -> V_51 [ V_7 ] . V_50 . V_55 = V_2 -> V_55 ;
V_44 -> V_119 . V_143 = 0 ;
if ( F_54 ( V_44 ) < 0 )
return - V_117 ;
F_55 ( V_2 -> V_4 -> V_4 , L_18 ,
V_44 -> V_169 , V_44 -> V_112 . V_62 ) ;
if ( F_14 ( & V_47 ) ) {
F_55 ( V_2 -> V_4 -> V_4 , L_19 ) ;
F_56 ( & V_104 ,
& V_105 ) ;
F_57 ( 'v' , & V_106 ) ;
}
F_58 ( & V_2 -> V_99 , & V_47 ) ;
return 0 ;
}
void F_59 ( struct V_43 * V_44 , T_4 V_170 ,
T_4 V_125 )
{
V_44 -> V_112 . type = V_171 ;
V_44 -> V_112 . V_113 = V_125 == 8 ? V_172 :
V_114 ;
V_44 -> V_112 . V_173 = 0 ;
V_44 -> V_112 . V_174 = 0 ;
V_44 -> V_112 . V_175 = 0 ;
V_44 -> V_112 . V_176 = 1 ;
V_44 -> V_112 . V_177 = 1 ;
V_44 -> V_112 . V_178 = 0 ;
V_44 -> V_112 . V_179 = V_180 ;
V_44 -> V_112 . V_175 = 0 ;
V_44 -> V_112 . V_181 = V_170 ;
return;
}
void F_60 ( struct V_43 * V_44 , struct V_1 * V_2 ,
T_4 V_157 , T_4 V_158 )
{
struct V_59 * V_55 = V_2 -> V_55 ;
V_44 -> V_118 = V_2 -> V_118 ;
V_44 -> V_119 . V_146 = V_55 -> V_144 ;
V_44 -> V_119 . V_147 = V_55 -> V_145 ;
V_44 -> V_119 . V_124 = V_55 -> V_124 ;
V_44 -> V_119 . V_182 = V_183 ;
V_44 -> V_119 . V_150 = 0 ;
V_44 -> V_119 . V_151 = 0 ;
V_44 -> V_119 . V_184 = V_185 ;
V_44 -> V_119 . V_145 = - 1 ;
V_44 -> V_119 . V_144 = - 1 ;
switch ( V_55 -> V_125 ) {
case 8 :
V_44 -> V_119 . V_107 . V_121 = 0 ;
V_44 -> V_119 . V_108 . V_121 = 0 ;
V_44 -> V_119 . V_109 . V_121 = 0 ;
V_44 -> V_119 . V_107 . V_120 = 8 ;
V_44 -> V_119 . V_108 . V_120 = 8 ;
V_44 -> V_119 . V_109 . V_120 = 8 ;
V_44 -> V_119 . V_122 . V_121 = 0 ;
V_44 -> V_119 . V_122 . V_120 = 0 ;
break;
case 15 :
V_44 -> V_119 . V_107 . V_121 = 10 ;
V_44 -> V_119 . V_108 . V_121 = 5 ;
V_44 -> V_119 . V_109 . V_121 = 0 ;
V_44 -> V_119 . V_107 . V_120 = 5 ;
V_44 -> V_119 . V_108 . V_120 = 5 ;
V_44 -> V_119 . V_109 . V_120 = 5 ;
V_44 -> V_119 . V_122 . V_121 = 15 ;
V_44 -> V_119 . V_122 . V_120 = 1 ;
break;
case 16 :
V_44 -> V_119 . V_107 . V_121 = 11 ;
V_44 -> V_119 . V_108 . V_121 = 5 ;
V_44 -> V_119 . V_109 . V_121 = 0 ;
V_44 -> V_119 . V_107 . V_120 = 5 ;
V_44 -> V_119 . V_108 . V_120 = 6 ;
V_44 -> V_119 . V_109 . V_120 = 5 ;
V_44 -> V_119 . V_122 . V_121 = 0 ;
break;
case 24 :
V_44 -> V_119 . V_107 . V_121 = 16 ;
V_44 -> V_119 . V_108 . V_121 = 8 ;
V_44 -> V_119 . V_109 . V_121 = 0 ;
V_44 -> V_119 . V_107 . V_120 = 8 ;
V_44 -> V_119 . V_108 . V_120 = 8 ;
V_44 -> V_119 . V_109 . V_120 = 8 ;
V_44 -> V_119 . V_122 . V_121 = 0 ;
V_44 -> V_119 . V_122 . V_120 = 0 ;
break;
case 32 :
V_44 -> V_119 . V_107 . V_121 = 16 ;
V_44 -> V_119 . V_108 . V_121 = 8 ;
V_44 -> V_119 . V_109 . V_121 = 0 ;
V_44 -> V_119 . V_107 . V_120 = 8 ;
V_44 -> V_119 . V_108 . V_120 = 8 ;
V_44 -> V_119 . V_109 . V_120 = 8 ;
V_44 -> V_119 . V_122 . V_121 = 24 ;
V_44 -> V_119 . V_122 . V_120 = 8 ;
break;
default:
break;
}
V_44 -> V_119 . V_25 = V_157 ;
V_44 -> V_119 . V_26 = V_158 ;
}
static int F_61 ( struct V_1 * V_2 ,
T_4 V_186 ,
T_4 V_187 )
{
struct V_5 * V_6 ;
int V_188 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_188 += V_6 -> V_38 -> V_189 ( V_6 , V_186 , V_187 ) ;
}
return V_188 ;
}
static struct V_161 * F_62 ( struct V_8 * V_190 , int V_144 , int V_145 )
{
struct V_161 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( F_63 ( V_17 ) > V_144 ||
F_64 ( V_17 ) > V_145 )
continue;
if ( V_17 -> type & V_191 )
return V_17 ;
}
return NULL ;
}
static bool F_65 ( struct V_8 * V_190 )
{
struct V_16 * V_19 ;
V_19 = & V_190 -> V_19 ;
return V_19 -> V_192 ;
}
static struct V_161 * F_66 ( struct V_8 * V_15 ,
int V_144 , int V_145 )
{
struct V_16 * V_19 ;
struct V_161 * V_17 = NULL ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_192 == false )
return V_17 ;
if ( V_19 -> V_29 || V_19 -> V_30 )
goto V_193;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_163 != V_19 -> V_25 ||
V_17 -> V_164 != V_19 -> V_26 )
continue;
if ( V_19 -> V_27 ) {
if ( V_17 -> V_194 != V_19 -> V_28 )
continue;
}
if ( V_19 -> V_31 ) {
if ( ! ( V_17 -> V_195 & V_196 ) )
continue;
}
return V_17 ;
}
V_193:
V_17 = F_67 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_58 ( & V_17 -> V_197 , & V_15 -> V_6 -> V_198 ) ;
return V_17 ;
}
static bool F_68 ( struct V_5 * V_6 , bool V_199 )
{
bool V_200 ;
if ( V_199 )
V_200 = V_6 -> V_201 == V_202 ;
else
V_200 = V_6 -> V_201 != V_203 ;
return V_200 ;
}
static void F_69 ( struct V_1 * V_2 ,
bool * V_52 )
{
bool V_204 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_68 ( V_6 , true ) ;
F_10 ( L_20 , V_6 -> V_61 . V_62 ,
V_52 [ V_7 ] ? L_21 : L_22 ) ;
V_204 |= V_52 [ V_7 ] ;
}
if ( V_204 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_68 ( V_6 , false ) ;
}
}
static bool F_70 ( struct V_1 * V_2 ,
struct V_161 * * V_198 ,
bool * V_52 , int V_144 , int V_145 )
{
int V_188 , V_7 , V_82 ;
bool V_205 = false ;
struct V_8 * V_15 ;
struct V_161 * V_206 , * V_17 ;
if ( V_2 -> V_48 > 1 )
return false ;
V_188 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_52 [ V_7 ] )
V_188 ++ ;
}
if ( V_188 <= 1 )
return false ;
V_205 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_198 [ V_7 ] = F_66 ( V_15 , V_144 , V_145 ) ;
if ( ! V_198 [ V_7 ] ) {
V_205 = false ;
break;
}
for ( V_82 = 0 ; V_82 < V_7 ; V_82 ++ ) {
if ( ! V_52 [ V_82 ] )
continue;
if ( ! F_71 ( V_198 [ V_82 ] , V_198 [ V_7 ] ) )
V_205 = false ;
}
}
if ( V_205 ) {
F_10 ( L_23 ) ;
return true ;
}
V_205 = true ;
V_206 = F_72 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_71 ( V_17 , V_206 ) )
V_198 [ V_7 ] = V_17 ;
}
if ( ! V_198 [ V_7 ] )
V_205 = false ;
}
if ( V_205 ) {
F_10 ( L_24 ) ;
return true ;
}
F_9 ( L_25 ) ;
return false ;
}
static bool F_73 ( struct V_1 * V_2 ,
struct V_161 * * V_198 ,
bool * V_52 , int V_144 , int V_145 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_15 = V_2 -> V_12 [ V_7 ] ;
if ( V_52 [ V_7 ] == false )
continue;
F_10 ( L_26 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_198 [ V_7 ] = F_66 ( V_15 , V_144 , V_145 ) ;
if ( ! V_198 [ V_7 ] ) {
F_10 ( L_27 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_198 [ V_7 ] = F_62 ( V_15 , V_144 , V_145 ) ;
}
if ( ! V_198 [ V_7 ] && ! F_14 ( & V_15 -> V_6 -> V_198 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_10 ( L_28 , V_198 [ V_7 ] ? V_198 [ V_7 ] -> V_207 :
L_29 ) ;
}
return true ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_100 * * V_208 ,
struct V_161 * * V_198 ,
int V_71 , int V_144 , int V_145 )
{
int V_60 , V_209 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_210 * V_211 ;
struct V_212 * V_213 ;
struct V_100 * V_214 ;
int V_215 , V_216 , V_217 ;
struct V_100 * * V_218 , * V_33 ;
struct V_8 * V_15 ;
if ( V_71 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_71 ] ;
V_6 = V_15 -> V_6 ;
V_208 [ V_71 ] = NULL ;
V_214 = NULL ;
V_216 = F_74 ( V_2 , V_208 , V_198 , V_71 + 1 , V_144 , V_145 ) ;
if ( V_198 [ V_71 ] == NULL )
return V_216 ;
V_218 = F_3 ( V_4 -> V_85 . V_101 *
sizeof( struct V_100 * ) , V_10 ) ;
if ( ! V_218 )
return V_216 ;
V_215 = 1 ;
if ( V_6 -> V_201 == V_202 )
V_215 ++ ;
if ( F_65 ( V_15 ) )
V_215 ++ ;
if ( F_62 ( V_15 , V_144 , V_145 ) )
V_215 ++ ;
V_211 = V_6 -> V_53 ;
V_213 = V_211 -> V_219 ( V_6 ) ;
if ( ! V_213 )
goto V_140;
for ( V_60 = 0 ; V_60 < V_2 -> V_48 ; V_60 ++ ) {
V_33 = & V_2 -> V_51 [ V_60 ] ;
if ( ( V_213 -> V_220 & ( 1 << V_60 ) ) == 0 )
continue;
for ( V_209 = 0 ; V_209 < V_71 ; V_209 ++ )
if ( V_208 [ V_209 ] == V_33 )
break;
if ( V_209 < V_71 ) {
if ( V_2 -> V_48 > 1 )
continue;
if ( ! F_71 ( V_198 [ V_209 ] , V_198 [ V_71 ] ) )
continue;
}
V_218 [ V_71 ] = V_33 ;
memcpy ( V_218 , V_208 , V_71 * sizeof( struct V_100 * ) ) ;
V_217 = V_215 + F_74 ( V_2 , V_218 , V_198 , V_71 + 1 ,
V_144 , V_145 ) ;
if ( V_217 > V_216 ) {
V_214 = V_33 ;
V_216 = V_217 ;
memcpy ( V_208 , V_218 ,
V_4 -> V_85 . V_101 *
sizeof( struct V_100 * ) ) ;
}
}
V_140:
F_4 ( V_218 ) ;
return V_216 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_100 * * V_218 ;
struct V_161 * * V_198 ;
struct V_49 * V_149 ;
bool * V_52 ;
int V_144 , V_145 ;
int V_7 ;
F_10 ( L_30 ) ;
V_144 = V_4 -> V_85 . V_221 ;
V_145 = V_4 -> V_85 . V_222 ;
V_218 = F_38 ( V_4 -> V_85 . V_101 ,
sizeof( struct V_100 * ) , V_10 ) ;
V_198 = F_38 ( V_4 -> V_85 . V_101 ,
sizeof( struct V_161 * ) , V_10 ) ;
V_52 = F_38 ( V_4 -> V_85 . V_101 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_218 || ! V_198 || ! V_52 ) {
F_17 ( L_31 ) ;
goto V_140;
}
F_69 ( V_2 , V_52 ) ;
if ( ! ( V_2 -> V_38 -> V_223 &&
V_2 -> V_38 -> V_223 ( V_2 , V_218 , V_198 ,
V_52 , V_144 , V_145 ) ) ) {
memset ( V_198 , 0 , V_4 -> V_85 . V_101 * sizeof( V_198 [ 0 ] ) ) ;
memset ( V_218 , 0 , V_4 -> V_85 . V_101 * sizeof( V_218 [ 0 ] ) ) ;
if ( ! F_70 ( V_2 ,
V_198 , V_52 , V_144 , V_145 ) &&
! F_73 ( V_2 ,
V_198 , V_52 , V_144 , V_145 ) )
F_17 ( L_32 ) ;
F_10 ( L_33 ,
V_144 , V_145 ) ;
F_74 ( V_2 , V_218 , V_198 , 0 , V_144 , V_145 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_149 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_149 -> V_103 = 0 ;
V_149 -> V_55 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_161 * V_17 = V_198 [ V_7 ] ;
struct V_100 * V_224 = V_218 [ V_7 ] ;
V_149 = & V_224 -> V_50 ;
if ( V_17 && V_224 ) {
F_10 ( L_34 ,
V_17 -> V_207 , V_224 -> V_50 . V_33 -> V_61 . V_62 ) ;
V_224 -> V_162 = V_17 ;
if ( V_149 -> V_17 )
F_35 ( V_4 , V_149 -> V_17 ) ;
V_149 -> V_17 = F_76 ( V_4 ,
V_224 -> V_162 ) ;
V_149 -> V_97 [ V_149 -> V_103 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_149 -> V_55 = V_2 -> V_55 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_149 = & V_2 -> V_51 [ V_7 ] . V_50 ;
if ( V_149 -> V_103 == 0 ) {
F_77 ( V_149 -> V_55 ) ;
F_77 ( V_149 -> V_103 ) ;
if ( V_149 -> V_17 )
F_35 ( V_4 , V_149 -> V_17 ) ;
V_149 -> V_17 = NULL ;
}
}
V_140:
F_4 ( V_218 ) ;
F_4 ( V_198 ) ;
F_4 ( V_52 ) ;
}
bool F_78 ( struct V_1 * V_2 , int V_225 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_188 = 0 ;
F_5 ( V_2 ) ;
V_188 = F_61 ( V_2 ,
V_4 -> V_85 . V_221 ,
V_4 -> V_85 . V_222 ) ;
if ( V_188 == 0 )
F_55 ( V_2 -> V_4 -> V_4 , L_35 ) ;
F_75 ( V_2 ) ;
return F_53 ( V_2 , V_225 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_188 = 0 ;
T_3 V_221 , V_222 , V_225 ;
if ( ! V_2 -> V_55 )
return 0 ;
F_79 ( & V_2 -> V_4 -> V_85 . V_226 ) ;
if ( ! F_25 ( V_2 ) ) {
V_2 -> V_148 = true ;
F_80 ( & V_2 -> V_4 -> V_85 . V_226 ) ;
return 0 ;
}
F_10 ( L_30 ) ;
V_221 = V_2 -> V_55 -> V_144 ;
V_222 = V_2 -> V_55 -> V_145 ;
V_225 = V_2 -> V_55 -> V_124 ;
V_188 = F_61 ( V_2 , V_221 ,
V_222 ) ;
F_80 ( & V_2 -> V_4 -> V_85 . V_226 ) ;
F_30 ( V_4 ) ;
F_75 ( V_2 ) ;
F_31 ( V_4 ) ;
F_50 ( V_2 -> V_168 ) ;
return 0 ;
}
static int T_5 F_81 ( void )
{
const char * V_207 = L_36 ;
struct V_227 * V_228 ;
F_79 ( & V_229 ) ;
V_228 = F_82 ( V_207 ) ;
F_80 ( & V_229 ) ;
if ( ! V_228 )
F_83 ( V_207 ) ;
return 0 ;
}
