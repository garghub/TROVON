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
static void F_10 ( struct V_21 * V_22 , struct V_1 * V_23 )
{
T_1 * V_24 , * V_25 , * V_26 ;
int V_7 ;
if ( V_23 -> V_27 -> V_28 == NULL )
return;
V_24 = V_22 -> V_29 ;
V_25 = V_24 + V_22 -> V_30 ;
V_26 = V_25 + V_22 -> V_30 ;
for ( V_7 = 0 ; V_7 < V_22 -> V_30 ; V_7 ++ )
V_23 -> V_27 -> V_28 ( V_22 , & V_24 [ V_7 ] , & V_25 [ V_7 ] , & V_26 [ V_7 ] , V_7 ) ;
}
static void F_11 ( struct V_21 * V_22 )
{
T_1 * V_24 , * V_25 , * V_26 ;
if ( V_22 -> V_27 -> V_31 == NULL )
return;
V_24 = V_22 -> V_29 ;
V_25 = V_24 + V_22 -> V_30 ;
V_26 = V_25 + V_22 -> V_30 ;
V_22 -> V_27 -> V_31 ( V_22 , V_24 , V_25 , V_26 , 0 , V_22 -> V_30 ) ;
}
int F_12 ( struct V_32 * V_33 )
{
struct V_1 * V_23 = V_33 -> V_34 ;
struct V_35 * V_27 ;
int V_7 ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_23 -> V_36 ; V_7 ++ ) {
struct V_37 * V_38 =
& V_23 -> V_39 [ V_7 ] . V_38 ;
if ( ! V_38 -> V_22 -> V_40 )
continue;
V_27 = V_38 -> V_22 -> V_41 ;
F_10 ( V_38 -> V_22 , V_23 ) ;
V_27 -> V_42 ( V_38 -> V_22 ,
V_38 -> V_43 ,
V_38 -> V_44 ,
V_38 -> V_45 ,
V_46 ) ;
}
}
return 0 ;
}
static struct V_47 * F_13 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = V_22 -> V_4 ;
struct V_21 * V_48 ;
F_2 (c, &dev->mode_config.crtc_list, head) {
if ( V_22 -> V_49 . V_50 == V_48 -> V_49 . V_50 )
return V_48 -> V_51 -> V_43 ;
}
return NULL ;
}
int F_14 ( struct V_32 * V_33 )
{
struct V_1 * V_23 = V_33 -> V_34 ;
struct V_21 * V_22 ;
struct V_35 * V_27 ;
struct V_47 * V_43 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_36 ; V_7 ++ ) {
struct V_37 * V_38 = & V_23 -> V_39 [ V_7 ] . V_38 ;
V_22 = V_38 -> V_22 ;
V_27 = V_22 -> V_41 ;
V_43 = F_13 ( V_22 ) ;
if ( ! V_22 -> V_40 )
continue;
if ( ! V_43 ) {
F_15 ( L_1 ) ;
continue;
}
F_11 ( V_38 -> V_22 ) ;
V_27 -> V_42 ( V_38 -> V_22 , V_43 , V_22 -> V_44 ,
V_22 -> V_45 , V_52 ) ;
}
return 0 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_53 * V_54 ;
bool error = false ;
int V_7 ;
F_17 ( V_4 ) ;
F_2 (plane, &dev->mode_config.plane_list, head) {
if ( V_54 -> type != V_55 )
F_18 ( V_54 ) ;
if ( V_4 -> V_16 . V_56 ) {
F_19 ( V_54 ,
V_4 -> V_16 . V_56 ,
F_20 ( V_57 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
struct V_37 * V_38 = & V_2 -> V_39 [ V_7 ] . V_38 ;
struct V_21 * V_22 = V_38 -> V_22 ;
int V_58 ;
if ( V_22 -> V_27 -> V_59 ) {
V_58 = V_22 -> V_27 -> V_59 ( V_22 , NULL , 0 , 0 , 0 ) ;
if ( V_58 )
error = true ;
}
V_58 = F_21 ( V_38 ) ;
if ( V_58 )
error = true ;
}
return error ;
}
static bool F_22 ( struct V_1 * V_2 )
{
return F_16 ( V_2 ) ;
}
bool F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_58 ;
F_24 ( V_4 ) ;
V_58 = F_16 ( V_2 ) ;
F_25 ( V_4 ) ;
return V_58 ;
}
static bool F_26 ( void )
{
bool V_58 , error = false ;
struct V_1 * V_23 ;
if ( F_27 ( & V_60 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_23 -> V_4 ;
if ( V_4 -> V_61 == V_62 )
continue;
if ( F_28 ( V_4 , true ) != 0 ) {
error = true ;
continue;
}
V_58 = F_22 ( V_23 ) ;
if ( V_58 )
error = true ;
F_25 ( V_4 ) ;
}
return error ;
}
static int F_29 ( struct V_63 * V_64 , unsigned long V_65 ,
void * V_66 )
{
if ( V_67 < 0 )
return 0 ;
F_30 ( L_2 ) ;
return F_26 () ;
}
static bool F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
int V_68 = 0 , V_69 = 0 ;
if ( V_4 -> V_51 -> V_70 )
return false ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_22 -> V_51 -> V_43 )
V_69 ++ ;
if ( V_22 -> V_51 -> V_43 == V_2 -> V_43 )
V_68 ++ ;
}
if ( V_68 < V_69 )
return false ;
return true ;
}
static void F_32 ( struct V_71 * V_72 )
{
bool V_58 ;
V_58 = F_26 () ;
if ( V_58 == true )
F_15 ( L_3 ) ;
}
static void F_33 ( int V_73 )
{
F_34 ( & V_74 ) ;
}
static void F_35 ( struct V_32 * V_33 , int V_75 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 ;
struct V_5 * V_6 ;
int V_7 , V_19 ;
if ( V_76 )
return;
F_24 ( V_4 ) ;
if ( ! F_31 ( V_2 ) ) {
F_25 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
V_22 = V_2 -> V_39 [ V_7 ] . V_38 . V_22 ;
if ( ! V_22 -> V_40 )
continue;
for ( V_19 = 0 ; V_19 < V_2 -> V_13 ; V_19 ++ ) {
V_6 = V_2 -> V_12 [ V_19 ] -> V_6 ;
V_6 -> V_27 -> V_77 ( V_6 , V_75 ) ;
F_36 ( & V_6 -> V_49 ,
V_4 -> V_16 . V_78 , V_75 ) ;
}
}
F_25 ( V_4 ) ;
}
int F_37 ( int V_79 , struct V_32 * V_33 )
{
switch ( V_79 ) {
case V_80 :
F_35 ( V_33 , V_81 ) ;
break;
case V_82 :
F_35 ( V_33 , V_83 ) ;
break;
case V_84 :
F_35 ( V_33 , V_83 ) ;
break;
case V_85 :
F_35 ( V_33 , V_86 ) ;
break;
case V_87 :
F_35 ( V_33 , V_88 ) ;
break;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_23 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_23 -> V_13 ; V_7 ++ )
F_4 ( V_23 -> V_12 [ V_7 ] ) ;
F_4 ( V_23 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_23 -> V_36 ; V_7 ++ ) {
F_4 ( V_23 -> V_39 [ V_7 ] . V_38 . V_89 ) ;
if ( V_23 -> V_39 [ V_7 ] . V_38 . V_90 )
F_39 ( V_23 -> V_4 , V_23 -> V_39 [ V_7 ] . V_38 . V_90 ) ;
}
F_4 ( V_23 -> V_39 ) ;
}
void F_40 ( struct V_3 * V_4 , struct V_1 * V_23 ,
const struct V_91 * V_27 )
{
F_41 ( & V_23 -> V_92 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_4 = V_4 ;
}
int F_42 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_36 , int V_93 )
{
struct V_21 * V_22 ;
int V_7 ;
if ( ! V_93 )
return - V_20 ;
V_2 -> V_39 = F_43 ( V_36 , sizeof( struct V_94 ) , V_10 ) ;
if ( ! V_2 -> V_39 )
return - V_14 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_12 = F_43 ( V_4 -> V_16 . V_95 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_39 ) ;
return - V_14 ;
}
V_2 -> V_18 = V_4 -> V_16 . V_95 ;
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_36 ; V_7 ++ ) {
V_2 -> V_39 [ V_7 ] . V_38 . V_89 =
F_43 ( V_93 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_39 [ V_7 ] . V_38 . V_89 )
goto V_96;
V_2 -> V_39 [ V_7 ] . V_38 . V_97 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_39 [ V_7 ] . V_38 . V_22 = V_22 ;
V_7 ++ ;
}
return 0 ;
V_96:
F_38 ( V_2 ) ;
return - V_14 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( ! F_27 ( & V_2 -> V_92 ) ) {
F_45 ( & V_2 -> V_92 ) ;
if ( F_27 ( & V_60 ) ) {
F_46 ( L_4 ) ;
F_47 ( & V_98 ,
& V_99 ) ;
F_48 ( 'v' , & V_100 ) ;
}
}
F_38 ( V_2 ) ;
}
static int F_49 ( struct V_21 * V_22 , T_2 V_101 , T_2 V_102 ,
T_2 V_103 , T_2 V_104 , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
struct V_47 * V_43 = V_2 -> V_43 ;
int V_105 ;
if ( V_33 -> V_106 . V_107 == V_108 ) {
T_3 * V_109 ;
T_3 V_110 ;
if ( V_104 > 16 )
return - V_20 ;
V_109 = ( T_3 * ) V_33 -> V_111 ;
V_101 >>= ( 16 - V_33 -> V_112 . V_101 . V_113 ) ;
V_102 >>= ( 16 - V_33 -> V_112 . V_102 . V_113 ) ;
V_103 >>= ( 16 - V_33 -> V_112 . V_103 . V_113 ) ;
V_110 = ( V_101 << V_33 -> V_112 . V_101 . V_114 ) |
( V_102 << V_33 -> V_112 . V_102 . V_114 ) |
( V_103 << V_33 -> V_112 . V_103 . V_114 ) ;
if ( V_33 -> V_112 . V_115 . V_113 > 0 ) {
T_3 V_116 = ( 1 << V_33 -> V_112 . V_115 . V_113 ) - 1 ;
V_116 <<= V_33 -> V_112 . V_115 . V_114 ;
V_110 |= V_116 ;
}
V_109 [ V_104 ] = V_110 ;
return 0 ;
}
if ( F_6 ( ! V_2 -> V_27 -> V_31 ||
! V_2 -> V_27 -> V_28 ) )
return - V_20 ;
V_105 = V_104 ;
if ( V_43 -> V_117 == 16 ) {
V_105 = V_104 << 3 ;
if ( V_43 -> V_118 == 16 && V_104 > 63 )
return - V_20 ;
if ( V_43 -> V_118 == 15 && V_104 > 31 )
return - V_20 ;
if ( V_43 -> V_118 == 16 ) {
T_2 V_119 , V_120 , V_121 ;
int V_7 ;
if ( V_104 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_27 -> V_31 ( V_22 , V_101 ,
V_102 , V_103 , V_105 + V_7 ) ;
}
V_2 -> V_27 -> V_28 ( V_22 , & V_119 ,
& V_120 , & V_121 ,
V_105 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_27 -> V_31 ( V_22 , V_119 ,
V_102 , V_121 ,
( V_105 >> 1 ) + V_7 ) ;
}
}
if ( V_43 -> V_118 != 16 )
V_2 -> V_27 -> V_31 ( V_22 , V_101 , V_102 , V_103 , V_105 ) ;
return 0 ;
}
int F_50 ( struct V_122 * V_123 , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_35 * V_124 ;
T_2 * V_101 , * V_102 , * V_103 , * V_115 ;
struct V_21 * V_22 ;
int V_7 , V_19 , V_125 = 0 ;
int V_126 ;
F_24 ( V_4 ) ;
if ( ! F_31 ( V_2 ) ) {
F_25 ( V_4 ) ;
return - V_127 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
V_22 = V_2 -> V_39 [ V_7 ] . V_38 . V_22 ;
V_124 = V_22 -> V_41 ;
V_101 = V_123 -> V_101 ;
V_102 = V_123 -> V_102 ;
V_103 = V_123 -> V_103 ;
V_115 = V_123 -> V_115 ;
V_126 = V_123 -> V_126 ;
for ( V_19 = 0 ; V_19 < V_123 -> V_128 ; V_19 ++ ) {
T_2 V_129 , V_130 , V_131 , V_132 = 0xffff ;
V_129 = * V_101 ++ ;
V_130 = * V_102 ++ ;
V_131 = * V_103 ++ ;
if ( V_115 )
V_132 = * V_115 ++ ;
V_125 = F_49 ( V_22 , V_129 , V_130 , V_131 , V_126 ++ , V_33 ) ;
if ( V_125 )
goto V_133;
}
if ( V_124 -> V_134 )
V_124 -> V_134 ( V_22 ) ;
}
V_133:
F_25 ( V_4 ) ;
return V_125 ;
}
int F_51 ( struct V_135 * V_112 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
struct V_47 * V_43 = V_2 -> V_43 ;
int V_118 ;
if ( V_112 -> V_136 != 0 || F_52 () )
return - V_20 ;
if ( V_112 -> V_117 > V_43 -> V_117 ||
V_112 -> V_137 > V_43 -> V_138 || V_112 -> V_139 > V_43 -> V_140 ||
V_112 -> V_141 > V_43 -> V_138 || V_112 -> V_142 > V_43 -> V_140 ) {
F_53 ( L_5
L_6 ,
V_112 -> V_137 , V_112 -> V_139 , V_112 -> V_117 ,
V_112 -> V_141 , V_112 -> V_142 ,
V_43 -> V_138 , V_43 -> V_140 , V_43 -> V_117 ) ;
return - V_20 ;
}
switch ( V_112 -> V_117 ) {
case 16 :
V_118 = ( V_112 -> V_102 . V_113 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_118 = ( V_112 -> V_115 . V_113 > 0 ) ? 32 : 24 ;
break;
default:
V_118 = V_112 -> V_117 ;
break;
}
switch ( V_118 ) {
case 8 :
V_112 -> V_101 . V_114 = 0 ;
V_112 -> V_102 . V_114 = 0 ;
V_112 -> V_103 . V_114 = 0 ;
V_112 -> V_101 . V_113 = 8 ;
V_112 -> V_102 . V_113 = 8 ;
V_112 -> V_103 . V_113 = 8 ;
V_112 -> V_115 . V_113 = 0 ;
V_112 -> V_115 . V_114 = 0 ;
break;
case 15 :
V_112 -> V_101 . V_114 = 10 ;
V_112 -> V_102 . V_114 = 5 ;
V_112 -> V_103 . V_114 = 0 ;
V_112 -> V_101 . V_113 = 5 ;
V_112 -> V_102 . V_113 = 5 ;
V_112 -> V_103 . V_113 = 5 ;
V_112 -> V_115 . V_113 = 1 ;
V_112 -> V_115 . V_114 = 15 ;
break;
case 16 :
V_112 -> V_101 . V_114 = 11 ;
V_112 -> V_102 . V_114 = 5 ;
V_112 -> V_103 . V_114 = 0 ;
V_112 -> V_101 . V_113 = 5 ;
V_112 -> V_102 . V_113 = 6 ;
V_112 -> V_103 . V_113 = 5 ;
V_112 -> V_115 . V_113 = 0 ;
V_112 -> V_115 . V_114 = 0 ;
break;
case 24 :
V_112 -> V_101 . V_114 = 16 ;
V_112 -> V_102 . V_114 = 8 ;
V_112 -> V_103 . V_114 = 0 ;
V_112 -> V_101 . V_113 = 8 ;
V_112 -> V_102 . V_113 = 8 ;
V_112 -> V_103 . V_113 = 8 ;
V_112 -> V_115 . V_113 = 0 ;
V_112 -> V_115 . V_114 = 0 ;
break;
case 32 :
V_112 -> V_101 . V_114 = 16 ;
V_112 -> V_102 . V_114 = 8 ;
V_112 -> V_103 . V_114 = 0 ;
V_112 -> V_101 . V_113 = 8 ;
V_112 -> V_102 . V_113 = 8 ;
V_112 -> V_103 . V_113 = 8 ;
V_112 -> V_115 . V_113 = 8 ;
V_112 -> V_115 . V_114 = 24 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
int F_54 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
struct V_135 * V_112 = & V_33 -> V_112 ;
if ( V_112 -> V_136 != 0 ) {
F_15 ( L_7 ) ;
return - V_20 ;
}
F_23 ( V_2 ) ;
if ( V_2 -> V_143 ) {
V_2 -> V_143 = false ;
F_55 ( V_2 ) ;
}
return 0 ;
}
int F_56 ( struct V_135 * V_112 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_34 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_37 * V_144 ;
int V_58 = 0 ;
int V_7 ;
F_24 ( V_4 ) ;
if ( ! F_31 ( V_2 ) ) {
F_25 ( V_4 ) ;
return - V_127 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
V_144 = & V_2 -> V_39 [ V_7 ] . V_38 ;
V_144 -> V_44 = V_112 -> V_145 ;
V_144 -> V_45 = V_112 -> V_146 ;
if ( V_144 -> V_97 ) {
V_58 = F_21 ( V_144 ) ;
if ( ! V_58 ) {
V_33 -> V_112 . V_145 = V_112 -> V_145 ;
V_33 -> V_112 . V_146 = V_112 -> V_146 ;
}
}
}
F_25 ( V_4 ) ;
return V_58 ;
}
static int F_57 ( struct V_1 * V_2 ,
int V_147 )
{
int V_58 = 0 ;
int V_36 = 0 ;
int V_7 ;
struct V_32 * V_33 ;
struct V_148 V_149 ;
int V_30 = 0 ;
memset ( & V_149 , 0 , sizeof( struct V_148 ) ) ;
V_149 . V_150 = 24 ;
V_149 . V_151 = 32 ;
V_149 . V_152 = ( unsigned ) - 1 ;
V_149 . V_153 = ( unsigned ) - 1 ;
if ( V_147 != V_149 . V_151 )
V_149 . V_150 = V_149 . V_151 = V_147 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_154 = V_2 -> V_12 [ V_7 ] ;
struct V_155 * V_156 ;
V_156 = & V_154 -> V_6 -> V_156 ;
if ( V_156 -> V_157 ) {
switch ( V_156 -> V_158 ) {
case 8 :
V_149 . V_150 = V_149 . V_151 = 8 ;
break;
case 15 :
V_149 . V_150 = 15 ;
V_149 . V_151 = 16 ;
break;
case 16 :
V_149 . V_150 = V_149 . V_151 = 16 ;
break;
case 24 :
V_149 . V_150 = V_149 . V_151 = 24 ;
break;
case 32 :
V_149 . V_150 = 24 ;
V_149 . V_151 = 32 ;
break;
}
break;
}
}
V_36 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
struct V_159 * V_160 ;
V_160 = V_2 -> V_39 [ V_7 ] . V_160 ;
if ( V_160 ) {
if ( V_30 == 0 )
V_30 = V_2 -> V_39 [ V_7 ] . V_38 . V_22 -> V_30 ;
if ( V_160 -> V_161 < V_149 . V_152 )
V_149 . V_152 = V_160 -> V_161 ;
if ( V_160 -> V_162 < V_149 . V_153 )
V_149 . V_153 = V_160 -> V_162 ;
if ( V_160 -> V_161 > V_149 . V_163 )
V_149 . V_163 = V_160 -> V_161 ;
if ( V_160 -> V_162 > V_149 . V_164 )
V_149 . V_164 = V_160 -> V_162 ;
V_36 ++ ;
}
}
if ( V_36 == 0 || V_149 . V_152 == - 1 || V_149 . V_153 == - 1 ) {
F_58 ( L_8 ) ;
V_149 . V_152 = V_149 . V_163 = 1024 ;
V_149 . V_153 = V_149 . V_164 = 768 ;
}
V_58 = (* V_2 -> V_27 -> V_165 )( V_2 , & V_149 ) ;
if ( V_58 < 0 )
return V_58 ;
V_33 = V_2 -> V_166 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ )
if ( V_2 -> V_39 [ V_7 ] . V_38 . V_97 )
V_2 -> V_39 [ V_7 ] . V_38 . V_43 = V_2 -> V_43 ;
V_33 -> V_112 . V_136 = 0 ;
if ( F_59 ( V_33 ) < 0 )
return - V_20 ;
F_60 ( V_2 -> V_4 -> V_4 , L_9 ,
V_33 -> V_167 , V_33 -> V_106 . V_50 ) ;
if ( F_27 ( & V_60 ) ) {
F_60 ( V_2 -> V_4 -> V_4 , L_10 ) ;
F_61 ( & V_98 ,
& V_99 ) ;
F_62 ( 'v' , & V_100 ) ;
}
F_63 ( & V_2 -> V_92 , & V_60 ) ;
return 0 ;
}
void F_64 ( struct V_32 * V_33 , T_4 V_168 ,
T_4 V_118 )
{
V_33 -> V_106 . type = V_169 ;
V_33 -> V_106 . V_107 = V_118 == 8 ? V_170 :
V_108 ;
V_33 -> V_106 . V_171 = 0 ;
V_33 -> V_106 . V_172 = 0 ;
V_33 -> V_106 . V_173 = 0 ;
V_33 -> V_106 . V_174 = 1 ;
V_33 -> V_106 . V_175 = 1 ;
V_33 -> V_106 . V_176 = 0 ;
V_33 -> V_106 . V_177 = V_178 ;
V_33 -> V_106 . V_179 = V_168 ;
return;
}
void F_65 ( struct V_32 * V_33 , struct V_1 * V_2 ,
T_4 V_152 , T_4 V_153 )
{
struct V_47 * V_43 = V_2 -> V_43 ;
V_33 -> V_111 = V_2 -> V_111 ;
V_33 -> V_112 . V_141 = V_43 -> V_138 ;
V_33 -> V_112 . V_142 = V_43 -> V_140 ;
V_33 -> V_112 . V_117 = V_43 -> V_117 ;
V_33 -> V_112 . V_180 = V_181 ;
V_33 -> V_112 . V_145 = 0 ;
V_33 -> V_112 . V_146 = 0 ;
V_33 -> V_112 . V_182 = V_183 ;
V_33 -> V_112 . V_140 = - 1 ;
V_33 -> V_112 . V_138 = - 1 ;
switch ( V_43 -> V_118 ) {
case 8 :
V_33 -> V_112 . V_101 . V_114 = 0 ;
V_33 -> V_112 . V_102 . V_114 = 0 ;
V_33 -> V_112 . V_103 . V_114 = 0 ;
V_33 -> V_112 . V_101 . V_113 = 8 ;
V_33 -> V_112 . V_102 . V_113 = 8 ;
V_33 -> V_112 . V_103 . V_113 = 8 ;
V_33 -> V_112 . V_115 . V_114 = 0 ;
V_33 -> V_112 . V_115 . V_113 = 0 ;
break;
case 15 :
V_33 -> V_112 . V_101 . V_114 = 10 ;
V_33 -> V_112 . V_102 . V_114 = 5 ;
V_33 -> V_112 . V_103 . V_114 = 0 ;
V_33 -> V_112 . V_101 . V_113 = 5 ;
V_33 -> V_112 . V_102 . V_113 = 5 ;
V_33 -> V_112 . V_103 . V_113 = 5 ;
V_33 -> V_112 . V_115 . V_114 = 15 ;
V_33 -> V_112 . V_115 . V_113 = 1 ;
break;
case 16 :
V_33 -> V_112 . V_101 . V_114 = 11 ;
V_33 -> V_112 . V_102 . V_114 = 5 ;
V_33 -> V_112 . V_103 . V_114 = 0 ;
V_33 -> V_112 . V_101 . V_113 = 5 ;
V_33 -> V_112 . V_102 . V_113 = 6 ;
V_33 -> V_112 . V_103 . V_113 = 5 ;
V_33 -> V_112 . V_115 . V_114 = 0 ;
break;
case 24 :
V_33 -> V_112 . V_101 . V_114 = 16 ;
V_33 -> V_112 . V_102 . V_114 = 8 ;
V_33 -> V_112 . V_103 . V_114 = 0 ;
V_33 -> V_112 . V_101 . V_113 = 8 ;
V_33 -> V_112 . V_102 . V_113 = 8 ;
V_33 -> V_112 . V_103 . V_113 = 8 ;
V_33 -> V_112 . V_115 . V_114 = 0 ;
V_33 -> V_112 . V_115 . V_113 = 0 ;
break;
case 32 :
V_33 -> V_112 . V_101 . V_114 = 16 ;
V_33 -> V_112 . V_102 . V_114 = 8 ;
V_33 -> V_112 . V_103 . V_114 = 0 ;
V_33 -> V_112 . V_101 . V_113 = 8 ;
V_33 -> V_112 . V_102 . V_113 = 8 ;
V_33 -> V_112 . V_103 . V_113 = 8 ;
V_33 -> V_112 . V_115 . V_114 = 24 ;
V_33 -> V_112 . V_115 . V_113 = 8 ;
break;
default:
break;
}
V_33 -> V_112 . V_137 = V_152 ;
V_33 -> V_112 . V_139 = V_153 ;
}
static int F_66 ( struct V_1 * V_2 ,
T_4 V_184 ,
T_4 V_185 )
{
struct V_5 * V_6 ;
int V_186 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_186 += V_6 -> V_27 -> V_187 ( V_6 , V_184 , V_185 ) ;
}
return V_186 ;
}
struct V_159 * F_67 ( struct V_8 * V_188 , int V_138 , int V_140 )
{
struct V_159 * V_90 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( V_90 -> V_161 > V_138 ||
V_90 -> V_162 > V_140 )
continue;
if ( V_90 -> type & V_189 )
return V_90 ;
}
return NULL ;
}
static bool F_68 ( struct V_8 * V_188 )
{
return V_188 -> V_6 -> V_156 . V_190 ;
}
struct V_159 * F_69 ( struct V_8 * V_154 ,
int V_138 , int V_140 )
{
struct V_155 * V_156 ;
struct V_159 * V_90 = NULL ;
bool V_191 ;
V_156 = & V_154 -> V_6 -> V_156 ;
if ( V_156 -> V_190 == false )
return V_90 ;
if ( V_156 -> V_192 || V_156 -> V_193 )
goto V_194;
V_191 = ! V_156 -> V_195 ;
V_196:
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_90 -> V_161 != V_156 -> V_137 ||
V_90 -> V_162 != V_156 -> V_139 )
continue;
if ( V_156 -> V_197 ) {
if ( V_90 -> V_198 != V_156 -> V_199 )
continue;
}
if ( V_156 -> V_195 ) {
if ( ! ( V_90 -> V_200 & V_201 ) )
continue;
} else if ( V_191 ) {
if ( V_90 -> V_200 & V_201 )
continue;
}
return V_90 ;
}
if ( V_191 ) {
V_191 = false ;
goto V_196;
}
V_194:
V_90 = F_70 ( V_154 -> V_6 -> V_4 ,
V_156 ) ;
F_63 ( & V_90 -> V_202 , & V_154 -> V_6 -> V_203 ) ;
return V_90 ;
}
static bool F_71 ( struct V_5 * V_6 , bool V_204 )
{
bool V_205 ;
if ( V_204 )
V_205 = V_6 -> V_206 == V_207 ;
else
V_205 = V_6 -> V_206 != V_208 ;
return V_205 ;
}
static void F_72 ( struct V_1 * V_2 ,
bool * V_40 )
{
bool V_209 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_40 [ V_7 ] = F_71 ( V_6 , true ) ;
F_73 ( L_11 , V_6 -> V_49 . V_50 ,
V_40 [ V_7 ] ? L_12 : L_13 ) ;
V_209 |= V_40 [ V_7 ] ;
}
if ( V_209 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_40 [ V_7 ] = F_71 ( V_6 , false ) ;
}
}
static bool F_74 ( struct V_1 * V_2 ,
struct V_159 * * V_203 ,
bool * V_40 , int V_138 , int V_140 )
{
int V_186 , V_7 , V_19 ;
bool V_210 = false ;
struct V_8 * V_154 ;
struct V_159 * V_211 , * V_90 ;
if ( V_2 -> V_36 > 1 )
return false ;
V_186 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_40 [ V_7 ] )
V_186 ++ ;
}
if ( V_186 <= 1 )
return false ;
V_210 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_40 [ V_7 ] )
continue;
V_154 = V_2 -> V_12 [ V_7 ] ;
V_203 [ V_7 ] = F_69 ( V_154 , V_138 , V_140 ) ;
if ( ! V_203 [ V_7 ] ) {
V_210 = false ;
break;
}
for ( V_19 = 0 ; V_19 < V_7 ; V_19 ++ ) {
if ( ! V_40 [ V_19 ] )
continue;
if ( ! F_75 ( V_203 [ V_19 ] , V_203 [ V_7 ] ) )
V_210 = false ;
}
}
if ( V_210 ) {
F_73 ( L_14 ) ;
return true ;
}
V_210 = true ;
V_211 = F_76 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_40 [ V_7 ] )
continue;
V_154 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_75 ( V_90 , V_211 ) )
V_203 [ V_7 ] = V_90 ;
}
if ( ! V_203 [ V_7 ] )
V_210 = false ;
}
if ( V_210 ) {
F_73 ( L_15 ) ;
return true ;
}
F_58 ( L_16 ) ;
return false ;
}
static bool F_77 ( struct V_1 * V_2 ,
struct V_159 * * V_203 ,
bool * V_40 , int V_138 , int V_140 )
{
struct V_8 * V_154 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_154 = V_2 -> V_12 [ V_7 ] ;
if ( V_40 [ V_7 ] == false )
continue;
F_73 ( L_17 ,
V_154 -> V_6 -> V_49 . V_50 ) ;
V_203 [ V_7 ] = F_69 ( V_154 , V_138 , V_140 ) ;
if ( ! V_203 [ V_7 ] ) {
F_73 ( L_18 ,
V_154 -> V_6 -> V_49 . V_50 ) ;
V_203 [ V_7 ] = F_67 ( V_154 , V_138 , V_140 ) ;
}
if ( ! V_203 [ V_7 ] && ! F_27 ( & V_154 -> V_6 -> V_203 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_73 ( L_19 , V_203 [ V_7 ] ? V_203 [ V_7 ] -> V_212 :
L_20 ) ;
}
return true ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_94 * * V_213 ,
struct V_159 * * V_203 ,
int V_64 , int V_138 , int V_140 )
{
int V_48 , V_214 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
int V_219 , V_220 , V_221 ;
struct V_94 * * V_222 , * V_22 ;
struct V_8 * V_154 ;
if ( V_64 == V_2 -> V_13 )
return 0 ;
V_154 = V_2 -> V_12 [ V_64 ] ;
V_6 = V_154 -> V_6 ;
V_213 [ V_64 ] = NULL ;
V_220 = F_78 ( V_2 , V_213 , V_203 , V_64 + 1 , V_138 , V_140 ) ;
if ( V_203 [ V_64 ] == NULL )
return V_220 ;
V_222 = F_3 ( V_4 -> V_16 . V_95 *
sizeof( struct V_94 * ) , V_10 ) ;
if ( ! V_222 )
return V_220 ;
V_219 = 1 ;
if ( V_6 -> V_206 == V_207 )
V_219 ++ ;
if ( F_68 ( V_154 ) )
V_219 ++ ;
if ( F_67 ( V_154 , V_138 , V_140 ) )
V_219 ++ ;
V_216 = V_6 -> V_41 ;
V_218 = V_216 -> V_223 ( V_6 ) ;
if ( ! V_218 )
goto V_133;
for ( V_48 = 0 ; V_48 < V_2 -> V_36 ; V_48 ++ ) {
V_22 = & V_2 -> V_39 [ V_48 ] ;
if ( ( V_218 -> V_224 & ( 1 << V_48 ) ) == 0 )
continue;
for ( V_214 = 0 ; V_214 < V_64 ; V_214 ++ )
if ( V_213 [ V_214 ] == V_22 )
break;
if ( V_214 < V_64 ) {
if ( V_2 -> V_36 > 1 )
continue;
if ( ! F_75 ( V_203 [ V_214 ] , V_203 [ V_64 ] ) )
continue;
}
V_222 [ V_64 ] = V_22 ;
memcpy ( V_222 , V_213 , V_64 * sizeof( struct V_94 * ) ) ;
V_221 = V_219 + F_78 ( V_2 , V_222 , V_203 , V_64 + 1 ,
V_138 , V_140 ) ;
if ( V_221 > V_220 ) {
V_220 = V_221 ;
memcpy ( V_213 , V_222 ,
V_4 -> V_16 . V_95 *
sizeof( struct V_94 * ) ) ;
}
}
V_133:
F_4 ( V_222 ) ;
return V_220 ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_94 * * V_222 ;
struct V_159 * * V_203 ;
struct V_37 * V_144 ;
bool * V_40 ;
int V_138 , V_140 ;
int V_7 ;
F_73 ( L_21 ) ;
V_138 = V_4 -> V_16 . V_225 ;
V_140 = V_4 -> V_16 . V_226 ;
V_222 = F_43 ( V_4 -> V_16 . V_95 ,
sizeof( struct V_94 * ) , V_10 ) ;
V_203 = F_43 ( V_4 -> V_16 . V_95 ,
sizeof( struct V_159 * ) , V_10 ) ;
V_40 = F_43 ( V_4 -> V_16 . V_95 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_222 || ! V_203 || ! V_40 ) {
F_15 ( L_22 ) ;
goto V_133;
}
F_72 ( V_2 , V_40 ) ;
if ( ! ( V_2 -> V_27 -> V_227 &&
V_2 -> V_27 -> V_227 ( V_2 , V_222 , V_203 ,
V_40 , V_138 , V_140 ) ) ) {
memset ( V_203 , 0 , V_4 -> V_16 . V_95 * sizeof( V_203 [ 0 ] ) ) ;
memset ( V_222 , 0 , V_4 -> V_16 . V_95 * sizeof( V_222 [ 0 ] ) ) ;
if ( ! F_74 ( V_2 ,
V_203 , V_40 , V_138 , V_140 ) &&
! F_77 ( V_2 ,
V_203 , V_40 , V_138 , V_140 ) )
F_15 ( L_23 ) ;
F_73 ( L_24 ,
V_138 , V_140 ) ;
F_78 ( V_2 , V_222 , V_203 , 0 , V_138 , V_140 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
V_144 = & V_2 -> V_39 [ V_7 ] . V_38 ;
V_144 -> V_97 = 0 ;
V_144 -> V_43 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_159 * V_90 = V_203 [ V_7 ] ;
struct V_94 * V_228 = V_222 [ V_7 ] ;
V_144 = & V_228 -> V_38 ;
if ( V_90 && V_228 ) {
F_73 ( L_25 ,
V_90 -> V_212 , V_228 -> V_38 . V_22 -> V_49 . V_50 ) ;
V_228 -> V_160 = V_90 ;
if ( V_144 -> V_90 )
F_39 ( V_4 , V_144 -> V_90 ) ;
V_144 -> V_90 = F_80 ( V_4 ,
V_228 -> V_160 ) ;
V_144 -> V_89 [ V_144 -> V_97 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_144 -> V_43 = V_2 -> V_43 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_36 ; V_7 ++ ) {
V_144 = & V_2 -> V_39 [ V_7 ] . V_38 ;
if ( V_144 -> V_97 == 0 ) {
F_81 ( V_144 -> V_43 ) ;
F_81 ( V_144 -> V_97 ) ;
if ( V_144 -> V_90 )
F_39 ( V_4 , V_144 -> V_90 ) ;
V_144 -> V_90 = NULL ;
}
}
V_133:
F_4 ( V_222 ) ;
F_4 ( V_203 ) ;
F_4 ( V_40 ) ;
}
bool F_82 ( struct V_1 * V_2 , int V_229 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_186 = 0 ;
F_83 ( & V_4 -> V_16 . V_17 ) ;
V_186 = F_66 ( V_2 ,
V_4 -> V_16 . V_225 ,
V_4 -> V_16 . V_226 ) ;
F_84 ( & V_4 -> V_16 . V_17 ) ;
if ( V_186 == 0 )
F_60 ( V_2 -> V_4 -> V_4 , L_26 ) ;
F_79 ( V_2 ) ;
return F_57 ( V_2 , V_229 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_225 , V_226 ;
F_83 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
if ( ! V_2 -> V_43 || ! F_31 ( V_2 ) ) {
V_2 -> V_143 = true ;
F_84 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
return 0 ;
}
F_73 ( L_21 ) ;
V_225 = V_2 -> V_43 -> V_138 ;
V_226 = V_2 -> V_43 -> V_140 ;
F_66 ( V_2 , V_225 , V_226 ) ;
F_84 ( & V_2 -> V_4 -> V_16 . V_17 ) ;
F_24 ( V_4 ) ;
F_79 ( V_2 ) ;
F_25 ( V_4 ) ;
F_54 ( V_2 -> V_166 ) ;
return 0 ;
}
static int T_5 F_85 ( void )
{
const char * V_212 = L_27 ;
struct V_230 * V_231 ;
F_83 ( & V_232 ) ;
V_231 = F_86 ( V_212 ) ;
F_84 ( & V_232 ) ;
if ( ! V_231 )
F_87 ( V_212 ) ;
return 0 ;
}
