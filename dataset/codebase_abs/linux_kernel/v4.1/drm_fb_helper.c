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
V_15 = F_8 ( V_2 -> V_12 , sizeof( struct V_8 * ) * ( V_2 -> V_13 + 1 ) , V_10 ) ;
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
static void F_9 ( struct V_19 * V_20 ,
struct V_5 * V_6 )
{
int V_7 , V_21 ;
for ( V_7 = 0 ; V_7 < V_20 -> V_22 ; V_7 ++ ) {
if ( V_20 -> V_23 [ V_7 ] == V_6 )
break;
}
if ( V_7 == V_20 -> V_22 )
return;
for ( V_21 = V_7 + 1 ; V_21 < V_20 -> V_22 ; V_21 ++ ) {
V_20 -> V_23 [ V_21 - 1 ] = V_20 -> V_23 [ V_21 ] ;
}
V_20 -> V_22 -- ;
if ( V_20 -> V_22 == 0 )
V_20 -> V_24 = NULL ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int V_7 , V_21 ;
F_6 ( ! F_7 ( & V_2 -> V_4 -> V_16 . V_17 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_2 -> V_12 [ V_7 ] -> V_6 == V_6 )
break;
}
if ( V_7 == V_2 -> V_13 )
return - V_25 ;
V_9 = V_2 -> V_12 [ V_7 ] ;
for ( V_21 = V_7 + 1 ; V_21 < V_2 -> V_13 ; V_21 ++ ) {
V_2 -> V_12 [ V_21 - 1 ] = V_2 -> V_12 [ V_21 ] ;
}
V_2 -> V_13 -- ;
F_4 ( V_9 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ )
F_9 ( & V_2 -> V_27 [ V_7 ] . V_28 , V_6 ) ;
return 0 ;
}
static void F_11 ( struct V_29 * V_30 , struct V_1 * V_31 )
{
T_1 * V_32 , * V_33 , * V_34 ;
int V_7 ;
if ( V_31 -> V_35 -> V_36 == NULL )
return;
V_32 = V_30 -> V_37 ;
V_33 = V_32 + V_30 -> V_38 ;
V_34 = V_33 + V_30 -> V_38 ;
for ( V_7 = 0 ; V_7 < V_30 -> V_38 ; V_7 ++ )
V_31 -> V_35 -> V_36 ( V_30 , & V_32 [ V_7 ] , & V_33 [ V_7 ] , & V_34 [ V_7 ] , V_7 ) ;
}
static void F_12 ( struct V_29 * V_30 )
{
T_1 * V_32 , * V_33 , * V_34 ;
if ( V_30 -> V_35 -> V_39 == NULL )
return;
V_32 = V_30 -> V_37 ;
V_33 = V_32 + V_30 -> V_38 ;
V_34 = V_33 + V_30 -> V_38 ;
V_30 -> V_35 -> V_39 ( V_30 , V_32 , V_33 , V_34 , 0 , V_30 -> V_38 ) ;
}
int F_13 ( struct V_40 * V_41 )
{
struct V_1 * V_31 = V_41 -> V_42 ;
const struct V_43 * V_35 ;
int V_7 ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_31 -> V_26 ; V_7 ++ ) {
struct V_19 * V_28 =
& V_31 -> V_27 [ V_7 ] . V_28 ;
if ( ! V_28 -> V_30 -> V_44 )
continue;
V_35 = V_28 -> V_30 -> V_45 ;
F_11 ( V_28 -> V_30 , V_31 ) ;
V_35 -> V_46 ( V_28 -> V_30 ,
V_28 -> V_24 ,
V_28 -> V_47 ,
V_28 -> V_48 ,
V_49 ) ;
}
}
return 0 ;
}
static struct V_50 * F_14 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_4 ;
struct V_29 * V_51 ;
F_2 (c, &dev->mode_config.crtc_list, head) {
if ( V_30 -> V_52 . V_53 == V_51 -> V_52 . V_53 )
return V_51 -> V_54 -> V_24 ;
}
return NULL ;
}
int F_15 ( struct V_40 * V_41 )
{
struct V_1 * V_31 = V_41 -> V_42 ;
struct V_29 * V_30 ;
const struct V_43 * V_35 ;
struct V_50 * V_24 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_31 -> V_26 ; V_7 ++ ) {
struct V_19 * V_28 = & V_31 -> V_27 [ V_7 ] . V_28 ;
V_30 = V_28 -> V_30 ;
V_35 = V_30 -> V_45 ;
V_24 = F_14 ( V_30 ) ;
if ( ! V_30 -> V_44 )
continue;
if ( ! V_24 ) {
F_16 ( L_1 ) ;
continue;
}
F_12 ( V_28 -> V_30 ) ;
V_35 -> V_46 ( V_28 -> V_30 , V_24 , V_30 -> V_47 ,
V_30 -> V_48 , V_55 ) ;
}
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_56 * V_57 ;
bool error = false ;
int V_7 ;
F_18 ( V_4 ) ;
F_2 (plane, &dev->mode_config.plane_list, head) {
if ( V_57 -> type != V_58 )
F_19 ( V_57 ) ;
if ( V_4 -> V_16 . V_59 ) {
F_20 ( V_57 ,
V_4 -> V_16 . V_59 ,
F_21 ( V_60 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ ) {
struct V_19 * V_28 = & V_2 -> V_27 [ V_7 ] . V_28 ;
struct V_29 * V_30 = V_28 -> V_30 ;
int V_61 ;
if ( V_30 -> V_35 -> V_62 ) {
V_61 = V_30 -> V_35 -> V_62 ( V_30 , NULL , 0 , 0 , 0 ) ;
if ( V_61 )
error = true ;
}
V_61 = F_22 ( V_28 ) ;
if ( V_61 )
error = true ;
}
return error ;
}
static bool F_23 ( struct V_1 * V_2 )
{
return F_17 ( V_2 ) ;
}
bool F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_61 ;
bool V_63 = false ;
F_25 ( V_4 ) ;
V_61 = F_17 ( V_2 ) ;
V_63 = V_2 -> V_64 ;
if ( V_63 )
V_2 -> V_64 = false ;
F_26 ( V_4 ) ;
if ( V_63 )
F_27 ( V_2 ) ;
return V_61 ;
}
static bool F_28 ( void )
{
bool V_61 , error = false ;
struct V_1 * V_31 ;
if ( F_29 ( & V_65 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_31 -> V_4 ;
if ( V_4 -> V_66 == V_67 )
continue;
if ( F_30 ( V_4 , true ) != 0 ) {
error = true ;
continue;
}
V_61 = F_23 ( V_31 ) ;
if ( V_61 )
error = true ;
F_26 ( V_4 ) ;
}
return error ;
}
static int F_31 ( struct V_68 * V_69 , unsigned long V_70 ,
void * V_71 )
{
if ( V_72 < 0 )
return 0 ;
F_32 ( L_2 ) ;
return F_28 () ;
}
static bool F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_29 * V_30 ;
int V_73 = 0 , V_74 = 0 ;
if ( V_4 -> V_54 -> V_75 )
return false ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_30 -> V_54 -> V_24 )
V_74 ++ ;
if ( V_30 -> V_54 -> V_24 == V_2 -> V_24 )
V_73 ++ ;
}
if ( V_73 < V_74 )
return false ;
return true ;
}
static void F_34 ( struct V_76 * V_77 )
{
bool V_61 ;
V_61 = F_28 () ;
if ( V_61 == true )
F_16 ( L_3 ) ;
}
static void F_35 ( int V_78 )
{
F_36 ( & V_79 ) ;
}
static void F_37 ( struct V_40 * V_41 , int V_80 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_29 * V_30 ;
struct V_5 * V_6 ;
int V_7 , V_21 ;
if ( V_81 )
return;
F_25 ( V_4 ) ;
if ( ! F_33 ( V_2 ) ) {
F_26 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ ) {
V_30 = V_2 -> V_27 [ V_7 ] . V_28 . V_30 ;
if ( ! V_30 -> V_44 )
continue;
for ( V_21 = 0 ; V_21 < V_2 -> V_13 ; V_21 ++ ) {
V_6 = V_2 -> V_12 [ V_21 ] -> V_6 ;
V_6 -> V_35 -> V_82 ( V_6 , V_80 ) ;
F_38 ( & V_6 -> V_52 ,
V_4 -> V_16 . V_83 , V_80 ) ;
}
}
F_26 ( V_4 ) ;
}
int F_39 ( int V_84 , struct V_40 * V_41 )
{
switch ( V_84 ) {
case V_85 :
F_37 ( V_41 , V_86 ) ;
break;
case V_87 :
F_37 ( V_41 , V_88 ) ;
break;
case V_89 :
F_37 ( V_41 , V_88 ) ;
break;
case V_90 :
F_37 ( V_41 , V_91 ) ;
break;
case V_92 :
F_37 ( V_41 , V_93 ) ;
break;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_31 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_31 -> V_13 ; V_7 ++ )
F_4 ( V_31 -> V_12 [ V_7 ] ) ;
F_4 ( V_31 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_31 -> V_26 ; V_7 ++ ) {
F_4 ( V_31 -> V_27 [ V_7 ] . V_28 . V_23 ) ;
if ( V_31 -> V_27 [ V_7 ] . V_28 . V_94 )
F_41 ( V_31 -> V_4 , V_31 -> V_27 [ V_7 ] . V_28 . V_94 ) ;
}
F_4 ( V_31 -> V_27 ) ;
}
void F_42 ( struct V_3 * V_4 , struct V_1 * V_31 ,
const struct V_95 * V_35 )
{
F_43 ( & V_31 -> V_96 ) ;
V_31 -> V_35 = V_35 ;
V_31 -> V_4 = V_4 ;
}
int F_44 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_26 , int V_97 )
{
struct V_29 * V_30 ;
int V_7 ;
if ( ! V_97 )
return - V_25 ;
V_2 -> V_27 = F_45 ( V_26 , sizeof( struct V_98 ) , V_10 ) ;
if ( ! V_2 -> V_27 )
return - V_14 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_12 = F_45 ( V_4 -> V_16 . V_99 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_27 ) ;
return - V_14 ;
}
V_2 -> V_18 = V_4 -> V_16 . V_99 ;
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_26 ; V_7 ++ ) {
V_2 -> V_27 [ V_7 ] . V_28 . V_23 =
F_45 ( V_97 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_27 [ V_7 ] . V_28 . V_23 )
goto V_100;
V_2 -> V_27 [ V_7 ] . V_28 . V_22 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_27 [ V_7 ] . V_28 . V_30 = V_30 ;
V_7 ++ ;
}
return 0 ;
V_100:
F_40 ( V_2 ) ;
return - V_14 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( ! F_29 ( & V_2 -> V_96 ) ) {
F_47 ( & V_2 -> V_96 ) ;
if ( F_29 ( & V_65 ) ) {
F_48 ( L_4 ) ;
F_49 ( & V_101 ,
& V_102 ) ;
F_50 ( 'v' , & V_103 ) ;
}
}
F_40 ( V_2 ) ;
}
static int F_51 ( struct V_29 * V_30 , T_2 V_104 , T_2 V_105 ,
T_2 V_106 , T_2 V_107 , struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_50 * V_24 = V_2 -> V_24 ;
int V_108 ;
if ( V_41 -> V_109 . V_110 == V_111 ) {
T_3 * V_112 ;
T_3 V_113 ;
if ( V_107 > 16 )
return - V_25 ;
V_112 = ( T_3 * ) V_41 -> V_114 ;
V_104 >>= ( 16 - V_41 -> V_115 . V_104 . V_116 ) ;
V_105 >>= ( 16 - V_41 -> V_115 . V_105 . V_116 ) ;
V_106 >>= ( 16 - V_41 -> V_115 . V_106 . V_116 ) ;
V_113 = ( V_104 << V_41 -> V_115 . V_104 . V_117 ) |
( V_105 << V_41 -> V_115 . V_105 . V_117 ) |
( V_106 << V_41 -> V_115 . V_106 . V_117 ) ;
if ( V_41 -> V_115 . V_118 . V_116 > 0 ) {
T_3 V_119 = ( 1 << V_41 -> V_115 . V_118 . V_116 ) - 1 ;
V_119 <<= V_41 -> V_115 . V_118 . V_117 ;
V_113 |= V_119 ;
}
V_112 [ V_107 ] = V_113 ;
return 0 ;
}
if ( F_6 ( ! V_2 -> V_35 -> V_39 ||
! V_2 -> V_35 -> V_36 ) )
return - V_25 ;
V_108 = V_107 ;
if ( V_24 -> V_120 == 16 ) {
V_108 = V_107 << 3 ;
if ( V_24 -> V_121 == 16 && V_107 > 63 )
return - V_25 ;
if ( V_24 -> V_121 == 15 && V_107 > 31 )
return - V_25 ;
if ( V_24 -> V_121 == 16 ) {
T_2 V_122 , V_123 , V_124 ;
int V_7 ;
if ( V_107 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_35 -> V_39 ( V_30 , V_104 ,
V_105 , V_106 , V_108 + V_7 ) ;
}
V_2 -> V_35 -> V_36 ( V_30 , & V_122 ,
& V_123 , & V_124 ,
V_108 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_35 -> V_39 ( V_30 , V_122 ,
V_105 , V_124 ,
( V_108 >> 1 ) + V_7 ) ;
}
}
if ( V_24 -> V_121 != 16 )
V_2 -> V_35 -> V_39 ( V_30 , V_104 , V_105 , V_106 , V_108 ) ;
return 0 ;
}
int F_52 ( struct V_125 * V_126 , struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_43 * V_127 ;
T_2 * V_104 , * V_105 , * V_106 , * V_118 ;
struct V_29 * V_30 ;
int V_7 , V_21 , V_128 = 0 ;
int V_129 ;
if ( F_30 ( V_4 , ! ! V_81 ) ) {
return - V_130 ;
}
if ( ! F_33 ( V_2 ) ) {
F_26 ( V_4 ) ;
return - V_130 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ ) {
V_30 = V_2 -> V_27 [ V_7 ] . V_28 . V_30 ;
V_127 = V_30 -> V_45 ;
V_104 = V_126 -> V_104 ;
V_105 = V_126 -> V_105 ;
V_106 = V_126 -> V_106 ;
V_118 = V_126 -> V_118 ;
V_129 = V_126 -> V_129 ;
for ( V_21 = 0 ; V_21 < V_126 -> V_131 ; V_21 ++ ) {
T_2 V_132 , V_133 , V_134 , V_135 = 0xffff ;
V_132 = * V_104 ++ ;
V_133 = * V_105 ++ ;
V_134 = * V_106 ++ ;
if ( V_118 )
V_135 = * V_118 ++ ;
V_128 = F_51 ( V_30 , V_132 , V_133 , V_134 , V_129 ++ , V_41 ) ;
if ( V_128 )
goto V_136;
}
if ( V_127 -> V_137 )
V_127 -> V_137 ( V_30 ) ;
}
V_136:
F_26 ( V_4 ) ;
return V_128 ;
}
int F_53 ( struct V_138 * V_115 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_50 * V_24 = V_2 -> V_24 ;
int V_121 ;
if ( V_115 -> V_139 != 0 || F_54 () )
return - V_25 ;
if ( V_115 -> V_120 > V_24 -> V_120 ||
V_115 -> V_140 > V_24 -> V_141 || V_115 -> V_142 > V_24 -> V_143 ||
V_115 -> V_144 > V_24 -> V_141 || V_115 -> V_145 > V_24 -> V_143 ) {
F_55 ( L_5
L_6 ,
V_115 -> V_140 , V_115 -> V_142 , V_115 -> V_120 ,
V_115 -> V_144 , V_115 -> V_145 ,
V_24 -> V_141 , V_24 -> V_143 , V_24 -> V_120 ) ;
return - V_25 ;
}
switch ( V_115 -> V_120 ) {
case 16 :
V_121 = ( V_115 -> V_105 . V_116 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_121 = ( V_115 -> V_118 . V_116 > 0 ) ? 32 : 24 ;
break;
default:
V_121 = V_115 -> V_120 ;
break;
}
switch ( V_121 ) {
case 8 :
V_115 -> V_104 . V_117 = 0 ;
V_115 -> V_105 . V_117 = 0 ;
V_115 -> V_106 . V_117 = 0 ;
V_115 -> V_104 . V_116 = 8 ;
V_115 -> V_105 . V_116 = 8 ;
V_115 -> V_106 . V_116 = 8 ;
V_115 -> V_118 . V_116 = 0 ;
V_115 -> V_118 . V_117 = 0 ;
break;
case 15 :
V_115 -> V_104 . V_117 = 10 ;
V_115 -> V_105 . V_117 = 5 ;
V_115 -> V_106 . V_117 = 0 ;
V_115 -> V_104 . V_116 = 5 ;
V_115 -> V_105 . V_116 = 5 ;
V_115 -> V_106 . V_116 = 5 ;
V_115 -> V_118 . V_116 = 1 ;
V_115 -> V_118 . V_117 = 15 ;
break;
case 16 :
V_115 -> V_104 . V_117 = 11 ;
V_115 -> V_105 . V_117 = 5 ;
V_115 -> V_106 . V_117 = 0 ;
V_115 -> V_104 . V_116 = 5 ;
V_115 -> V_105 . V_116 = 6 ;
V_115 -> V_106 . V_116 = 5 ;
V_115 -> V_118 . V_116 = 0 ;
V_115 -> V_118 . V_117 = 0 ;
break;
case 24 :
V_115 -> V_104 . V_117 = 16 ;
V_115 -> V_105 . V_117 = 8 ;
V_115 -> V_106 . V_117 = 0 ;
V_115 -> V_104 . V_116 = 8 ;
V_115 -> V_105 . V_116 = 8 ;
V_115 -> V_106 . V_116 = 8 ;
V_115 -> V_118 . V_116 = 0 ;
V_115 -> V_118 . V_117 = 0 ;
break;
case 32 :
V_115 -> V_104 . V_117 = 16 ;
V_115 -> V_105 . V_117 = 8 ;
V_115 -> V_106 . V_117 = 0 ;
V_115 -> V_104 . V_116 = 8 ;
V_115 -> V_105 . V_116 = 8 ;
V_115 -> V_106 . V_116 = 8 ;
V_115 -> V_118 . V_116 = 8 ;
V_115 -> V_118 . V_117 = 24 ;
break;
default:
return - V_25 ;
}
return 0 ;
}
int F_56 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_138 * V_115 = & V_41 -> V_115 ;
if ( V_115 -> V_139 != 0 ) {
F_16 ( L_7 ) ;
return - V_25 ;
}
F_24 ( V_2 ) ;
return 0 ;
}
int F_57 ( struct V_138 * V_115 ,
struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_19 * V_146 ;
int V_61 = 0 ;
int V_7 ;
if ( F_30 ( V_4 , ! ! V_81 ) ) {
return - V_130 ;
}
if ( ! F_33 ( V_2 ) ) {
F_26 ( V_4 ) ;
return - V_130 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ ) {
V_146 = & V_2 -> V_27 [ V_7 ] . V_28 ;
V_146 -> V_47 = V_115 -> V_147 ;
V_146 -> V_48 = V_115 -> V_148 ;
if ( V_146 -> V_22 ) {
V_61 = F_22 ( V_146 ) ;
if ( ! V_61 ) {
V_41 -> V_115 . V_147 = V_115 -> V_147 ;
V_41 -> V_115 . V_148 = V_115 -> V_148 ;
}
}
}
F_26 ( V_4 ) ;
return V_61 ;
}
static int F_58 ( struct V_1 * V_2 ,
int V_149 )
{
int V_61 = 0 ;
int V_26 = 0 ;
int V_7 ;
struct V_40 * V_41 ;
struct V_150 V_151 ;
int V_38 = 0 ;
memset ( & V_151 , 0 , sizeof( struct V_150 ) ) ;
V_151 . V_152 = 24 ;
V_151 . V_153 = 32 ;
V_151 . V_154 = ( unsigned ) - 1 ;
V_151 . V_155 = ( unsigned ) - 1 ;
if ( V_149 != V_151 . V_153 )
V_151 . V_152 = V_151 . V_153 = V_149 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_156 = V_2 -> V_12 [ V_7 ] ;
struct V_157 * V_158 ;
V_158 = & V_156 -> V_6 -> V_158 ;
if ( V_158 -> V_159 ) {
switch ( V_158 -> V_160 ) {
case 8 :
V_151 . V_152 = V_151 . V_153 = 8 ;
break;
case 15 :
V_151 . V_152 = 15 ;
V_151 . V_153 = 16 ;
break;
case 16 :
V_151 . V_152 = V_151 . V_153 = 16 ;
break;
case 24 :
V_151 . V_152 = V_151 . V_153 = 24 ;
break;
case 32 :
V_151 . V_152 = 24 ;
V_151 . V_153 = 32 ;
break;
}
break;
}
}
V_26 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ ) {
struct V_161 * V_162 ;
struct V_19 * V_28 ;
int V_47 , V_48 , V_21 ;
bool V_163 = true , V_164 = true ;
V_162 = V_2 -> V_27 [ V_7 ] . V_162 ;
V_28 = & V_2 -> V_27 [ V_7 ] . V_28 ;
if ( ! V_162 )
continue;
V_26 ++ ;
V_47 = V_2 -> V_27 [ V_7 ] . V_47 ;
V_48 = V_2 -> V_27 [ V_7 ] . V_48 ;
if ( V_38 == 0 )
V_38 = V_2 -> V_27 [ V_7 ] . V_28 . V_30 -> V_38 ;
V_151 . V_165 = F_59 ( T_3 , V_162 -> V_166 + V_47 , V_151 . V_165 ) ;
V_151 . V_167 = F_59 ( T_3 , V_162 -> V_168 + V_48 , V_151 . V_167 ) ;
for ( V_21 = 0 ; V_21 < V_28 -> V_22 ; V_21 ++ ) {
struct V_5 * V_6 = V_28 -> V_23 [ V_21 ] ;
if ( V_6 -> V_169 ) {
V_164 = ( V_6 -> V_170 == ( V_6 -> V_171 - 1 ) ) ;
V_163 = ( V_6 -> V_172 == ( V_6 -> V_173 - 1 ) ) ;
break;
}
}
if ( V_164 )
V_151 . V_154 = F_60 ( T_3 , V_162 -> V_166 + V_47 , V_151 . V_154 ) ;
if ( V_163 )
V_151 . V_155 = F_60 ( T_3 , V_162 -> V_168 + V_48 , V_151 . V_155 ) ;
}
if ( V_26 == 0 || V_151 . V_154 == - 1 || V_151 . V_155 == - 1 ) {
F_61 ( L_8 ) ;
V_151 . V_154 = V_151 . V_165 = 1024 ;
V_151 . V_155 = V_151 . V_167 = 768 ;
}
V_61 = (* V_2 -> V_35 -> V_174 )( V_2 , & V_151 ) ;
if ( V_61 < 0 )
return V_61 ;
V_41 = V_2 -> V_175 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ )
if ( V_2 -> V_27 [ V_7 ] . V_28 . V_22 )
V_2 -> V_27 [ V_7 ] . V_28 . V_24 = V_2 -> V_24 ;
V_41 -> V_115 . V_139 = 0 ;
if ( F_62 ( V_41 ) < 0 )
return - V_25 ;
F_63 ( V_2 -> V_4 -> V_4 , L_9 ,
V_41 -> V_176 , V_41 -> V_109 . V_53 ) ;
if ( F_29 ( & V_65 ) ) {
F_63 ( V_2 -> V_4 -> V_4 , L_10 ) ;
F_64 ( & V_101 ,
& V_102 ) ;
F_65 ( 'v' , & V_103 ) ;
}
F_66 ( & V_2 -> V_96 , & V_65 ) ;
return 0 ;
}
void F_67 ( struct V_40 * V_41 , T_4 V_177 ,
T_4 V_121 )
{
V_41 -> V_109 . type = V_178 ;
V_41 -> V_109 . V_110 = V_121 == 8 ? V_179 :
V_111 ;
V_41 -> V_109 . V_180 = 0 ;
V_41 -> V_109 . V_181 = 0 ;
V_41 -> V_109 . V_182 = 0 ;
V_41 -> V_109 . V_183 = 1 ;
V_41 -> V_109 . V_184 = 1 ;
V_41 -> V_109 . V_185 = 0 ;
V_41 -> V_109 . V_186 = V_187 ;
V_41 -> V_109 . V_188 = V_177 ;
return;
}
void F_68 ( struct V_40 * V_41 , struct V_1 * V_2 ,
T_4 V_154 , T_4 V_155 )
{
struct V_50 * V_24 = V_2 -> V_24 ;
V_41 -> V_114 = V_2 -> V_114 ;
V_41 -> V_115 . V_144 = V_24 -> V_141 ;
V_41 -> V_115 . V_145 = V_24 -> V_143 ;
V_41 -> V_115 . V_120 = V_24 -> V_120 ;
V_41 -> V_115 . V_189 = V_190 ;
V_41 -> V_115 . V_147 = 0 ;
V_41 -> V_115 . V_148 = 0 ;
V_41 -> V_115 . V_191 = V_192 ;
V_41 -> V_115 . V_143 = - 1 ;
V_41 -> V_115 . V_141 = - 1 ;
switch ( V_24 -> V_121 ) {
case 8 :
V_41 -> V_115 . V_104 . V_117 = 0 ;
V_41 -> V_115 . V_105 . V_117 = 0 ;
V_41 -> V_115 . V_106 . V_117 = 0 ;
V_41 -> V_115 . V_104 . V_116 = 8 ;
V_41 -> V_115 . V_105 . V_116 = 8 ;
V_41 -> V_115 . V_106 . V_116 = 8 ;
V_41 -> V_115 . V_118 . V_117 = 0 ;
V_41 -> V_115 . V_118 . V_116 = 0 ;
break;
case 15 :
V_41 -> V_115 . V_104 . V_117 = 10 ;
V_41 -> V_115 . V_105 . V_117 = 5 ;
V_41 -> V_115 . V_106 . V_117 = 0 ;
V_41 -> V_115 . V_104 . V_116 = 5 ;
V_41 -> V_115 . V_105 . V_116 = 5 ;
V_41 -> V_115 . V_106 . V_116 = 5 ;
V_41 -> V_115 . V_118 . V_117 = 15 ;
V_41 -> V_115 . V_118 . V_116 = 1 ;
break;
case 16 :
V_41 -> V_115 . V_104 . V_117 = 11 ;
V_41 -> V_115 . V_105 . V_117 = 5 ;
V_41 -> V_115 . V_106 . V_117 = 0 ;
V_41 -> V_115 . V_104 . V_116 = 5 ;
V_41 -> V_115 . V_105 . V_116 = 6 ;
V_41 -> V_115 . V_106 . V_116 = 5 ;
V_41 -> V_115 . V_118 . V_117 = 0 ;
break;
case 24 :
V_41 -> V_115 . V_104 . V_117 = 16 ;
V_41 -> V_115 . V_105 . V_117 = 8 ;
V_41 -> V_115 . V_106 . V_117 = 0 ;
V_41 -> V_115 . V_104 . V_116 = 8 ;
V_41 -> V_115 . V_105 . V_116 = 8 ;
V_41 -> V_115 . V_106 . V_116 = 8 ;
V_41 -> V_115 . V_118 . V_117 = 0 ;
V_41 -> V_115 . V_118 . V_116 = 0 ;
break;
case 32 :
V_41 -> V_115 . V_104 . V_117 = 16 ;
V_41 -> V_115 . V_105 . V_117 = 8 ;
V_41 -> V_115 . V_106 . V_117 = 0 ;
V_41 -> V_115 . V_104 . V_116 = 8 ;
V_41 -> V_115 . V_105 . V_116 = 8 ;
V_41 -> V_115 . V_106 . V_116 = 8 ;
V_41 -> V_115 . V_118 . V_117 = 24 ;
V_41 -> V_115 . V_118 . V_116 = 8 ;
break;
default:
break;
}
V_41 -> V_115 . V_140 = V_154 ;
V_41 -> V_115 . V_142 = V_155 ;
}
static int F_69 ( struct V_1 * V_2 ,
T_4 V_193 ,
T_4 V_194 )
{
struct V_5 * V_6 ;
int V_195 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_195 += V_6 -> V_35 -> V_196 ( V_6 , V_193 , V_194 ) ;
}
return V_195 ;
}
struct V_161 * F_70 ( struct V_8 * V_197 , int V_141 , int V_143 )
{
struct V_161 * V_94 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( V_94 -> V_166 > V_141 ||
V_94 -> V_168 > V_143 )
continue;
if ( V_94 -> type & V_198 )
return V_94 ;
}
return NULL ;
}
static bool F_71 ( struct V_8 * V_197 )
{
return V_197 -> V_6 -> V_158 . V_199 ;
}
struct V_161 * F_72 ( struct V_8 * V_156 ,
int V_141 , int V_143 )
{
struct V_157 * V_158 ;
struct V_161 * V_94 ;
bool V_200 ;
V_158 = & V_156 -> V_6 -> V_158 ;
if ( V_158 -> V_199 == false )
return NULL ;
if ( V_158 -> V_201 || V_158 -> V_202 )
goto V_203;
V_200 = ! V_158 -> V_204 ;
V_205:
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_94 -> V_166 != V_158 -> V_140 ||
V_94 -> V_168 != V_158 -> V_142 )
continue;
if ( V_158 -> V_206 ) {
if ( V_94 -> V_207 != V_158 -> V_208 )
continue;
}
if ( V_158 -> V_204 ) {
if ( ! ( V_94 -> V_209 & V_210 ) )
continue;
} else if ( V_200 ) {
if ( V_94 -> V_209 & V_210 )
continue;
}
return V_94 ;
}
if ( V_200 ) {
V_200 = false ;
goto V_205;
}
V_203:
V_94 = F_73 ( V_156 -> V_6 -> V_4 ,
V_158 ) ;
F_66 ( & V_94 -> V_211 , & V_156 -> V_6 -> V_212 ) ;
return V_94 ;
}
static bool F_74 ( struct V_5 * V_6 , bool V_213 )
{
bool V_214 ;
if ( V_213 )
V_214 = V_6 -> V_215 == V_216 ;
else
V_214 = V_6 -> V_215 != V_217 ;
return V_214 ;
}
static void F_75 ( struct V_1 * V_2 ,
bool * V_44 )
{
bool V_218 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_44 [ V_7 ] = F_74 ( V_6 , true ) ;
F_76 ( L_11 , V_6 -> V_52 . V_53 ,
V_44 [ V_7 ] ? L_12 : L_13 ) ;
V_218 |= V_44 [ V_7 ] ;
}
if ( V_218 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_44 [ V_7 ] = F_74 ( V_6 , false ) ;
}
}
static bool F_77 ( struct V_1 * V_2 ,
struct V_161 * * V_212 ,
struct V_219 * V_220 ,
bool * V_44 , int V_141 , int V_143 )
{
int V_195 , V_7 , V_21 ;
bool V_221 = false ;
struct V_8 * V_156 ;
struct V_161 * V_222 , * V_94 ;
if ( V_2 -> V_26 > 1 )
return false ;
V_195 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_44 [ V_7 ] )
V_195 ++ ;
}
if ( V_195 <= 1 )
return false ;
V_221 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_44 [ V_7 ] )
continue;
V_156 = V_2 -> V_12 [ V_7 ] ;
V_212 [ V_7 ] = F_72 ( V_156 , V_141 , V_143 ) ;
if ( ! V_212 [ V_7 ] ) {
V_221 = false ;
break;
}
for ( V_21 = 0 ; V_21 < V_7 ; V_21 ++ ) {
if ( ! V_44 [ V_21 ] )
continue;
if ( ! F_78 ( V_212 [ V_21 ] , V_212 [ V_7 ] ) )
V_221 = false ;
}
}
if ( V_221 ) {
F_76 ( L_14 ) ;
return true ;
}
V_221 = true ;
V_222 = F_79 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_44 [ V_7 ] )
continue;
V_156 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_78 ( V_94 , V_222 ) )
V_212 [ V_7 ] = V_94 ;
}
if ( ! V_212 [ V_7 ] )
V_221 = false ;
}
if ( V_221 ) {
F_76 ( L_15 ) ;
return true ;
}
F_61 ( L_16 ) ;
return false ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_161 * * V_212 ,
struct V_219 * V_220 ,
int V_223 ,
int V_224 , int V_225 )
{
struct V_8 * V_156 ;
int V_7 ;
int V_226 = 0 , V_227 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_156 = V_2 -> V_12 [ V_7 ] ;
if ( ! V_156 -> V_6 -> V_169 )
continue;
if ( ! V_212 [ V_7 ] && ( V_224 || V_225 ) ) {
F_76 ( L_17 , V_7 ,
V_156 -> V_6 -> V_52 . V_53 ) ;
continue;
}
if ( V_156 -> V_6 -> V_170 < V_224 )
V_226 += V_212 [ V_7 ] -> V_166 ;
if ( V_156 -> V_6 -> V_172 < V_225 )
V_227 += V_212 [ V_7 ] -> V_168 ;
}
V_220 [ V_223 ] . V_47 = V_226 ;
V_220 [ V_223 ] . V_48 = V_227 ;
F_76 ( L_18 , V_226 , V_227 , V_224 , V_225 ) ;
return 0 ;
}
static bool F_81 ( struct V_1 * V_2 ,
struct V_161 * * V_212 ,
struct V_219 * V_220 ,
bool * V_44 , int V_141 , int V_143 )
{
struct V_8 * V_156 ;
int V_7 ;
T_5 V_228 = 0 , V_119 ;
int V_229 = 0 ;
V_119 = ( 1 << V_2 -> V_13 ) - 1 ;
V_230:
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_156 = V_2 -> V_12 [ V_7 ] ;
if ( V_228 & ( 1 << V_7 ) )
continue;
if ( V_44 [ V_7 ] == false ) {
V_228 |= ( 1 << V_7 ) ;
continue;
}
if ( V_229 == 0 && V_156 -> V_6 -> V_169 )
continue;
if ( V_229 == 1 ) {
if ( V_156 -> V_6 -> V_170 != 0 ||
V_156 -> V_6 -> V_172 != 0 )
continue;
} else {
if ( V_156 -> V_6 -> V_170 != V_229 - 1 &&
V_156 -> V_6 -> V_172 != V_229 - 1 )
continue;
F_80 ( V_2 , V_212 , V_220 ,
V_7 , V_156 -> V_6 -> V_170 , V_156 -> V_6 -> V_172 ) ;
}
F_76 ( L_19 ,
V_156 -> V_6 -> V_52 . V_53 ) ;
V_212 [ V_7 ] = F_72 ( V_156 , V_141 , V_143 ) ;
if ( ! V_212 [ V_7 ] ) {
F_76 ( L_20 ,
V_156 -> V_6 -> V_52 . V_53 , V_156 -> V_6 -> V_231 ? V_156 -> V_6 -> V_231 -> V_53 : 0 ) ;
V_212 [ V_7 ] = F_70 ( V_156 , V_141 , V_143 ) ;
}
if ( ! V_212 [ V_7 ] && ! F_29 ( & V_156 -> V_6 -> V_212 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_76 ( L_21 , V_212 [ V_7 ] ? V_212 [ V_7 ] -> V_232 :
L_22 ) ;
V_228 |= ( 1 << V_7 ) ;
}
if ( ( V_228 & V_119 ) != V_119 ) {
V_229 ++ ;
goto V_230;
}
return true ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_98 * * V_233 ,
struct V_161 * * V_212 ,
int V_69 , int V_141 , int V_143 )
{
int V_51 , V_234 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
const struct V_235 * V_236 ;
struct V_237 * V_238 ;
int V_239 , V_240 , V_241 ;
struct V_98 * * V_242 , * V_30 ;
struct V_8 * V_156 ;
if ( V_69 == V_2 -> V_13 )
return 0 ;
V_156 = V_2 -> V_12 [ V_69 ] ;
V_6 = V_156 -> V_6 ;
V_233 [ V_69 ] = NULL ;
V_240 = F_82 ( V_2 , V_233 , V_212 , V_69 + 1 , V_141 , V_143 ) ;
if ( V_212 [ V_69 ] == NULL )
return V_240 ;
V_242 = F_3 ( V_4 -> V_16 . V_99 *
sizeof( struct V_98 * ) , V_10 ) ;
if ( ! V_242 )
return V_240 ;
V_239 = 1 ;
if ( V_6 -> V_215 == V_216 )
V_239 ++ ;
if ( F_71 ( V_156 ) )
V_239 ++ ;
if ( F_70 ( V_156 , V_141 , V_143 ) )
V_239 ++ ;
V_236 = V_6 -> V_45 ;
V_238 = V_236 -> V_243 ( V_6 ) ;
if ( ! V_238 )
goto V_136;
for ( V_51 = 0 ; V_51 < V_2 -> V_26 ; V_51 ++ ) {
V_30 = & V_2 -> V_27 [ V_51 ] ;
if ( ( V_238 -> V_244 & ( 1 << V_51 ) ) == 0 )
continue;
for ( V_234 = 0 ; V_234 < V_69 ; V_234 ++ )
if ( V_233 [ V_234 ] == V_30 )
break;
if ( V_234 < V_69 ) {
if ( V_2 -> V_26 > 1 )
continue;
if ( ! F_78 ( V_212 [ V_234 ] , V_212 [ V_69 ] ) )
continue;
}
V_242 [ V_69 ] = V_30 ;
memcpy ( V_242 , V_233 , V_69 * sizeof( struct V_98 * ) ) ;
V_241 = V_239 + F_82 ( V_2 , V_242 , V_212 , V_69 + 1 ,
V_141 , V_143 ) ;
if ( V_241 > V_240 ) {
V_240 = V_241 ;
memcpy ( V_233 , V_242 ,
V_4 -> V_16 . V_99 *
sizeof( struct V_98 * ) ) ;
}
}
V_136:
F_4 ( V_242 ) ;
return V_240 ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_98 * * V_242 ;
struct V_161 * * V_212 ;
struct V_219 * V_220 ;
struct V_19 * V_146 ;
bool * V_44 ;
int V_141 , V_143 ;
int V_7 ;
F_76 ( L_23 ) ;
V_141 = V_4 -> V_16 . V_245 ;
V_143 = V_4 -> V_16 . V_246 ;
V_242 = F_45 ( V_4 -> V_16 . V_99 ,
sizeof( struct V_98 * ) , V_10 ) ;
V_212 = F_45 ( V_4 -> V_16 . V_99 ,
sizeof( struct V_161 * ) , V_10 ) ;
V_220 = F_45 ( V_4 -> V_16 . V_99 ,
sizeof( struct V_219 ) , V_10 ) ;
V_44 = F_45 ( V_4 -> V_16 . V_99 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_242 || ! V_212 || ! V_44 || ! V_220 ) {
F_16 ( L_24 ) ;
goto V_136;
}
F_75 ( V_2 , V_44 ) ;
if ( ! ( V_2 -> V_35 -> V_247 &&
V_2 -> V_35 -> V_247 ( V_2 , V_242 , V_212 ,
V_220 ,
V_44 , V_141 , V_143 ) ) ) {
memset ( V_212 , 0 , V_4 -> V_16 . V_99 * sizeof( V_212 [ 0 ] ) ) ;
memset ( V_242 , 0 , V_4 -> V_16 . V_99 * sizeof( V_242 [ 0 ] ) ) ;
memset ( V_220 , 0 , V_4 -> V_16 . V_99 * sizeof( V_220 [ 0 ] ) ) ;
if ( ! F_77 ( V_2 , V_212 , V_220 ,
V_44 , V_141 , V_143 ) &&
! F_81 ( V_2 , V_212 , V_220 ,
V_44 , V_141 , V_143 ) )
F_16 ( L_25 ) ;
F_76 ( L_26 ,
V_141 , V_143 ) ;
F_82 ( V_2 , V_242 , V_212 , 0 , V_141 , V_143 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ ) {
V_146 = & V_2 -> V_27 [ V_7 ] . V_28 ;
V_146 -> V_22 = 0 ;
V_146 -> V_24 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_161 * V_94 = V_212 [ V_7 ] ;
struct V_98 * V_248 = V_242 [ V_7 ] ;
struct V_219 * V_117 = & V_220 [ V_7 ] ;
V_146 = & V_248 -> V_28 ;
if ( V_94 && V_248 ) {
F_76 ( L_27 ,
V_94 -> V_232 , V_248 -> V_28 . V_30 -> V_52 . V_53 , V_117 -> V_47 , V_117 -> V_48 ) ;
V_248 -> V_162 = V_94 ;
V_248 -> V_47 = V_117 -> V_47 ;
V_248 -> V_48 = V_117 -> V_48 ;
if ( V_146 -> V_94 )
F_41 ( V_4 , V_146 -> V_94 ) ;
V_146 -> V_94 = F_84 ( V_4 ,
V_248 -> V_162 ) ;
V_146 -> V_23 [ V_146 -> V_22 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_146 -> V_24 = V_2 -> V_24 ;
V_146 -> V_47 = V_117 -> V_47 ;
V_146 -> V_48 = V_117 -> V_48 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_26 ; V_7 ++ ) {
V_146 = & V_2 -> V_27 [ V_7 ] . V_28 ;
if ( V_146 -> V_22 == 0 ) {
F_85 ( V_146 -> V_24 ) ;
if ( V_146 -> V_94 )
F_41 ( V_4 , V_146 -> V_94 ) ;
V_146 -> V_94 = NULL ;
}
}
V_136:
F_4 ( V_242 ) ;
F_4 ( V_212 ) ;
F_4 ( V_220 ) ;
F_4 ( V_44 ) ;
}
int F_86 ( struct V_1 * V_2 , int V_249 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_195 = 0 ;
F_87 ( & V_4 -> V_16 . V_17 ) ;
V_195 = F_69 ( V_2 ,
V_4 -> V_16 . V_245 ,
V_4 -> V_16 . V_246 ) ;
F_88 ( & V_4 -> V_16 . V_17 ) ;
if ( V_195 == 0 )
F_63 ( V_2 -> V_4 -> V_4 , L_28 ) ;
F_83 ( V_2 ) ;
return F_58 ( V_2 , V_249 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_245 , V_246 ;
F_87 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
if ( ! V_2 -> V_24 || ! F_33 ( V_2 ) ) {
V_2 -> V_64 = true ;
F_88 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
return 0 ;
}
F_76 ( L_23 ) ;
V_245 = V_2 -> V_24 -> V_141 ;
V_246 = V_2 -> V_24 -> V_143 ;
F_69 ( V_2 , V_245 , V_246 ) ;
F_88 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
F_25 ( V_4 ) ;
F_83 ( V_2 ) ;
F_26 ( V_4 ) ;
F_56 ( V_2 -> V_175 ) ;
return 0 ;
}
static int T_6 F_89 ( void )
{
const char * V_232 = L_29 ;
struct V_250 * V_251 ;
F_87 ( & V_252 ) ;
V_251 = F_90 ( V_232 ) ;
F_88 ( & V_252 ) ;
if ( ! V_251 )
F_91 ( V_232 ) ;
return 0 ;
}
