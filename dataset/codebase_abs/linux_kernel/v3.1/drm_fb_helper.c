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
case V_22 : V_21 = L_1 ; break;
case V_23 : V_21 = L_2 ; break;
default:
case V_24 : V_21 = L_3 ; break;
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
V_35 = V_33 -> V_38 ;
V_36 = V_35 + V_33 -> V_39 ;
V_37 = V_36 + V_33 -> V_39 ;
for ( V_7 = 0 ; V_7 < V_33 -> V_39 ; V_7 ++ )
V_34 -> V_40 -> V_41 ( V_33 , & V_35 [ V_7 ] , & V_36 [ V_7 ] , & V_37 [ V_7 ] , V_7 ) ;
}
static void F_12 ( struct V_32 * V_33 )
{
T_1 * V_35 , * V_36 , * V_37 ;
V_35 = V_33 -> V_38 ;
V_36 = V_35 + V_33 -> V_39 ;
V_37 = V_36 + V_33 -> V_39 ;
V_33 -> V_40 -> V_42 ( V_33 , V_35 , V_36 , V_37 , 0 , V_33 -> V_39 ) ;
}
int F_13 ( struct V_43 * V_44 )
{
struct V_1 * V_34 = V_44 -> V_45 ;
struct V_46 * V_40 ;
int V_7 ;
if ( F_14 ( & V_47 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_34 -> V_48 ; V_7 ++ ) {
struct V_49 * V_50 =
& V_34 -> V_51 [ V_7 ] . V_50 ;
if ( ! V_50 -> V_33 -> V_52 )
continue;
V_40 = V_50 -> V_33 -> V_53 ;
F_11 ( V_50 -> V_33 , V_34 ) ;
V_40 -> V_54 ( V_50 -> V_33 ,
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
struct V_46 * V_40 ;
struct V_59 * V_55 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_34 -> V_48 ; V_7 ++ ) {
struct V_49 * V_50 = & V_34 -> V_51 [ V_7 ] . V_50 ;
V_33 = V_50 -> V_33 ;
V_40 = V_33 -> V_53 ;
V_55 = F_15 ( V_33 ) ;
if ( ! V_33 -> V_52 )
continue;
if ( ! V_55 ) {
F_17 ( L_10 ) ;
continue;
}
F_12 ( V_50 -> V_33 ) ;
V_40 -> V_54 ( V_50 -> V_33 , V_55 , V_33 -> V_56 ,
V_33 -> V_57 , V_63 ) ;
}
return 0 ;
}
bool F_18 ( struct V_1 * V_2 )
{
bool error = false ;
int V_7 , V_64 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_49 * V_50 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_64 = F_19 ( V_50 ) ;
if ( V_64 )
error = true ;
}
return error ;
}
bool F_20 ( void )
{
bool V_64 , error = false ;
struct V_1 * V_34 ;
if ( F_14 ( & V_47 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
if ( V_34 -> V_4 -> V_65 == V_66 )
continue;
V_64 = F_18 ( V_34 ) ;
if ( V_64 )
error = true ;
}
return error ;
}
int F_21 ( struct V_67 * V_68 , unsigned long V_69 ,
void * V_70 )
{
F_22 ( V_71 L_11 ) ;
return F_20 () ;
}
void F_23 ( void )
{
bool V_64 ;
V_64 = F_20 () ;
if ( V_64 == true )
F_17 ( L_12 ) ;
}
static void F_24 ( struct V_72 * V_73 )
{
F_23 () ;
}
static void F_25 ( int V_74 )
{
F_26 ( & V_75 ) ;
}
static void F_27 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_46 * V_76 ;
struct V_5 * V_6 ;
struct V_77 * V_78 ;
int V_7 , V_79 ;
F_28 ( & V_4 -> V_80 . V_81 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_76 = V_33 -> V_53 ;
if ( ! V_33 -> V_52 )
continue;
V_76 -> V_82 ( V_33 , V_83 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_13 ; V_79 ++ ) {
V_6 = V_2 -> V_12 [ V_79 ] -> V_6 ;
V_6 -> V_82 = V_83 ;
F_29 ( V_6 ,
V_4 -> V_80 . V_84 ,
V_83 ) ;
}
F_2 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_78 -> V_33 == V_33 ) {
struct V_85 * V_86 ;
V_86 = V_78 -> V_53 ;
V_86 -> V_82 ( V_78 , V_83 ) ;
}
}
}
F_30 ( & V_4 -> V_80 . V_81 ) ;
}
static void F_31 ( struct V_43 * V_44 , int V_87 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_46 * V_76 ;
struct V_5 * V_6 ;
struct V_77 * V_78 ;
int V_7 , V_79 ;
F_28 ( & V_4 -> V_80 . V_81 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_76 = V_33 -> V_53 ;
if ( ! V_33 -> V_52 )
continue;
for ( V_79 = 0 ; V_79 < V_2 -> V_13 ; V_79 ++ ) {
V_6 = V_2 -> V_12 [ V_79 ] -> V_6 ;
V_6 -> V_82 = V_87 ;
F_29 ( V_6 ,
V_4 -> V_80 . V_84 ,
V_87 ) ;
}
F_2 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_78 -> V_33 == V_33 ) {
struct V_85 * V_86 ;
V_86 = V_78 -> V_53 ;
V_86 -> V_82 ( V_78 , V_87 ) ;
}
}
V_76 -> V_82 ( V_33 , V_88 ) ;
}
F_30 ( & V_4 -> V_80 . V_81 ) ;
}
int F_32 ( int V_89 , struct V_43 * V_44 )
{
switch ( V_89 ) {
case V_90 :
F_27 ( V_44 ) ;
break;
case V_91 :
F_31 ( V_44 , V_92 ) ;
break;
case V_93 :
F_31 ( V_44 , V_92 ) ;
break;
case V_94 :
F_31 ( V_44 , V_95 ) ;
break;
case V_96 :
F_31 ( V_44 , V_88 ) ;
break;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_34 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_34 -> V_13 ; V_7 ++ )
F_4 ( V_34 -> V_12 [ V_7 ] ) ;
F_4 ( V_34 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_34 -> V_48 ; V_7 ++ )
F_4 ( V_34 -> V_51 [ V_7 ] . V_50 . V_97 ) ;
F_4 ( V_34 -> V_51 ) ;
}
int F_34 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_48 , int V_98 )
{
struct V_32 * V_33 ;
int V_64 = 0 ;
int V_7 ;
V_2 -> V_4 = V_4 ;
F_35 ( & V_2 -> V_99 ) ;
V_2 -> V_51 = F_36 ( V_48 , sizeof( struct V_100 ) , V_10 ) ;
if ( ! V_2 -> V_51 )
return - V_14 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_12 = F_36 ( V_4 -> V_80 . V_101 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_51 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_97 =
F_36 ( V_98 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_51 [ V_7 ] . V_50 . V_97 ) {
V_64 = - V_14 ;
goto V_102;
}
V_2 -> V_51 [ V_7 ] . V_50 . V_103 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_51 [ V_7 ] . V_104 = V_33 -> V_61 . V_62 ;
V_2 -> V_51 [ V_7 ] . V_50 . V_33 = V_33 ;
V_7 ++ ;
}
V_2 -> V_105 = V_98 ;
return 0 ;
V_102:
F_33 ( V_2 ) ;
return - V_14 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( ! F_14 ( & V_2 -> V_99 ) ) {
F_38 ( & V_2 -> V_99 ) ;
if ( F_14 ( & V_47 ) ) {
F_22 ( V_106 L_13 ) ;
F_39 ( & V_107 ,
& V_108 ) ;
F_40 ( 'v' , & V_109 ) ;
}
}
F_33 ( V_2 ) ;
}
static int F_41 ( struct V_32 * V_33 , T_2 V_110 , T_2 V_111 ,
T_2 V_112 , T_2 V_113 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_114 ;
if ( V_44 -> V_115 . V_116 == V_117 ) {
T_3 * V_118 ;
T_3 V_119 ;
if ( V_113 > 16 )
return - V_120 ;
V_118 = ( T_3 * ) V_44 -> V_121 ;
V_110 >>= ( 16 - V_44 -> V_122 . V_110 . V_123 ) ;
V_111 >>= ( 16 - V_44 -> V_122 . V_111 . V_123 ) ;
V_112 >>= ( 16 - V_44 -> V_122 . V_112 . V_123 ) ;
V_119 = ( V_110 << V_44 -> V_122 . V_110 . V_124 ) |
( V_111 << V_44 -> V_122 . V_111 . V_124 ) |
( V_112 << V_44 -> V_122 . V_112 . V_124 ) ;
if ( V_44 -> V_122 . V_125 . V_123 > 0 ) {
T_3 V_126 = ( 1 << V_44 -> V_122 . V_125 . V_123 ) - 1 ;
V_126 <<= V_44 -> V_122 . V_125 . V_124 ;
V_119 |= V_126 ;
}
V_118 [ V_113 ] = V_119 ;
return 0 ;
}
V_114 = V_113 ;
if ( V_55 -> V_127 == 16 ) {
V_114 = V_113 << 3 ;
if ( V_55 -> V_128 == 16 && V_113 > 63 )
return - V_120 ;
if ( V_55 -> V_128 == 15 && V_113 > 31 )
return - V_120 ;
if ( V_55 -> V_128 == 16 ) {
T_2 V_129 , V_130 , V_131 ;
int V_7 ;
if ( V_113 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_110 ,
V_111 , V_112 , V_114 + V_7 ) ;
}
V_2 -> V_40 -> V_41 ( V_33 , & V_129 ,
& V_130 , & V_131 ,
V_114 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_129 ,
V_111 , V_131 ,
( V_114 >> 1 ) + V_7 ) ;
}
}
if ( V_55 -> V_128 != 16 )
V_2 -> V_40 -> V_42 ( V_33 , V_110 , V_111 , V_112 , V_114 ) ;
return 0 ;
}
int F_42 ( struct V_132 * V_133 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_46 * V_76 ;
T_2 * V_110 , * V_111 , * V_112 , * V_125 ;
struct V_32 * V_33 ;
int V_7 , V_79 , V_134 = 0 ;
int V_135 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_76 = V_33 -> V_53 ;
V_110 = V_133 -> V_110 ;
V_111 = V_133 -> V_111 ;
V_112 = V_133 -> V_112 ;
V_125 = V_133 -> V_125 ;
V_135 = V_133 -> V_135 ;
for ( V_79 = 0 ; V_79 < V_133 -> V_136 ; V_79 ++ ) {
T_2 V_137 , V_138 , V_139 , V_140 = 0xffff ;
V_137 = * V_110 ++ ;
V_138 = * V_111 ++ ;
V_139 = * V_112 ++ ;
if ( V_125 )
V_140 = * V_125 ++ ;
V_134 = F_41 ( V_33 , V_137 , V_138 , V_139 , V_135 ++ , V_44 ) ;
if ( V_134 )
return V_134 ;
}
V_76 -> V_141 ( V_33 ) ;
}
return V_134 ;
}
int F_43 ( struct V_142 * V_122 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_128 ;
if ( V_122 -> V_143 != 0 || F_44 () )
return - V_120 ;
if ( V_122 -> V_127 > V_55 -> V_127 || V_122 -> V_25 > V_55 -> V_144 || V_122 -> V_26 > V_55 -> V_145 ) {
F_45 ( L_14
L_15 , V_122 -> V_25 , V_122 -> V_26 , V_122 -> V_127 ,
V_55 -> V_144 , V_55 -> V_145 , V_55 -> V_127 ) ;
return - V_120 ;
}
switch ( V_122 -> V_127 ) {
case 16 :
V_128 = ( V_122 -> V_111 . V_123 == 6 ) ? 16 : 15 ;
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
V_122 -> V_110 . V_124 = 0 ;
V_122 -> V_111 . V_124 = 0 ;
V_122 -> V_112 . V_124 = 0 ;
V_122 -> V_110 . V_123 = 8 ;
V_122 -> V_111 . V_123 = 8 ;
V_122 -> V_112 . V_123 = 8 ;
V_122 -> V_125 . V_123 = 0 ;
V_122 -> V_125 . V_124 = 0 ;
break;
case 15 :
V_122 -> V_110 . V_124 = 10 ;
V_122 -> V_111 . V_124 = 5 ;
V_122 -> V_112 . V_124 = 0 ;
V_122 -> V_110 . V_123 = 5 ;
V_122 -> V_111 . V_123 = 5 ;
V_122 -> V_112 . V_123 = 5 ;
V_122 -> V_125 . V_123 = 1 ;
V_122 -> V_125 . V_124 = 15 ;
break;
case 16 :
V_122 -> V_110 . V_124 = 11 ;
V_122 -> V_111 . V_124 = 5 ;
V_122 -> V_112 . V_124 = 0 ;
V_122 -> V_110 . V_123 = 5 ;
V_122 -> V_111 . V_123 = 6 ;
V_122 -> V_112 . V_123 = 5 ;
V_122 -> V_125 . V_123 = 0 ;
V_122 -> V_125 . V_124 = 0 ;
break;
case 24 :
V_122 -> V_110 . V_124 = 16 ;
V_122 -> V_111 . V_124 = 8 ;
V_122 -> V_112 . V_124 = 0 ;
V_122 -> V_110 . V_123 = 8 ;
V_122 -> V_111 . V_123 = 8 ;
V_122 -> V_112 . V_123 = 8 ;
V_122 -> V_125 . V_123 = 0 ;
V_122 -> V_125 . V_124 = 0 ;
break;
case 32 :
V_122 -> V_110 . V_124 = 16 ;
V_122 -> V_111 . V_124 = 8 ;
V_122 -> V_112 . V_124 = 0 ;
V_122 -> V_110 . V_123 = 8 ;
V_122 -> V_111 . V_123 = 8 ;
V_122 -> V_112 . V_123 = 8 ;
V_122 -> V_125 . V_123 = 8 ;
V_122 -> V_125 . V_124 = 24 ;
break;
default:
return - V_120 ;
}
return 0 ;
}
int F_46 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_142 * V_122 = & V_44 -> V_122 ;
struct V_32 * V_33 ;
int V_64 ;
int V_7 ;
if ( V_122 -> V_143 != 0 ) {
F_17 ( L_16 ) ;
return - V_120 ;
}
F_28 ( & V_4 -> V_80 . V_81 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_64 = V_33 -> V_40 -> V_146 ( & V_2 -> V_51 [ V_7 ] . V_50 ) ;
if ( V_64 ) {
F_30 ( & V_4 -> V_80 . V_81 ) ;
return V_64 ;
}
}
F_30 ( & V_4 -> V_80 . V_81 ) ;
if ( V_2 -> V_147 ) {
V_2 -> V_147 = false ;
F_47 ( V_2 ) ;
}
return 0 ;
}
int F_48 ( struct V_142 * V_122 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_148 ;
struct V_32 * V_33 ;
int V_64 = 0 ;
int V_7 ;
F_28 ( & V_4 -> V_80 . V_81 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_148 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_148 -> V_56 = V_122 -> V_149 ;
V_148 -> V_57 = V_122 -> V_150 ;
if ( V_148 -> V_103 ) {
V_64 = V_33 -> V_40 -> V_146 ( V_148 ) ;
if ( ! V_64 ) {
V_44 -> V_122 . V_149 = V_122 -> V_149 ;
V_44 -> V_122 . V_150 = V_122 -> V_150 ;
}
}
}
F_30 ( & V_4 -> V_80 . V_81 ) ;
return V_64 ;
}
int F_49 ( struct V_1 * V_2 ,
int V_151 )
{
int V_152 = 0 ;
int V_48 = 0 ;
int V_7 ;
struct V_43 * V_44 ;
struct V_153 V_154 ;
int V_39 = 0 ;
memset ( & V_154 , 0 , sizeof( struct V_153 ) ) ;
V_154 . V_155 = 24 ;
V_154 . V_156 = 32 ;
V_154 . V_157 = ( unsigned ) - 1 ;
V_154 . V_158 = ( unsigned ) - 1 ;
if ( V_151 != V_154 . V_156 ) {
V_154 . V_155 = V_154 . V_156 = V_151 ;
}
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
if ( V_39 == 0 )
V_39 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 -> V_39 ;
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
V_152 = (* V_2 -> V_40 -> V_167 )( V_2 , & V_154 ) ;
if ( V_152 < 0 )
return V_152 ;
V_44 = V_2 -> V_168 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_55 = V_2 -> V_55 ;
}
if ( V_152 ) {
V_44 -> V_122 . V_143 = 0 ;
if ( F_50 ( V_44 ) < 0 ) {
return - V_120 ;
}
F_22 ( V_106 L_18 , V_44 -> V_169 ,
V_44 -> V_115 . V_62 ) ;
} else {
F_46 ( V_44 ) ;
}
if ( F_14 ( & V_47 ) ) {
F_22 ( V_106 L_19 ) ;
F_51 ( & V_107 ,
& V_108 ) ;
F_52 ( 'v' , & V_109 ) ;
}
if ( V_152 )
F_53 ( & V_2 -> V_99 , & V_47 ) ;
return 0 ;
}
void F_54 ( struct V_43 * V_44 , T_4 V_170 ,
T_4 V_128 )
{
V_44 -> V_115 . type = V_171 ;
V_44 -> V_115 . V_116 = V_128 == 8 ? V_172 :
V_117 ;
V_44 -> V_115 . V_173 = 0 ;
V_44 -> V_115 . V_174 = 0 ;
V_44 -> V_115 . V_175 = 0 ;
V_44 -> V_115 . V_176 = 1 ;
V_44 -> V_115 . V_177 = 1 ;
V_44 -> V_115 . V_178 = 0 ;
V_44 -> V_115 . V_179 = V_180 ;
V_44 -> V_115 . V_175 = 0 ;
V_44 -> V_115 . V_181 = V_170 ;
return;
}
void F_55 ( struct V_43 * V_44 , struct V_1 * V_2 ,
T_4 V_157 , T_4 V_158 )
{
struct V_59 * V_55 = V_2 -> V_55 ;
V_44 -> V_121 = V_2 -> V_121 ;
V_44 -> V_122 . V_182 = V_55 -> V_144 ;
V_44 -> V_122 . V_183 = V_55 -> V_145 ;
V_44 -> V_122 . V_127 = V_55 -> V_127 ;
V_44 -> V_122 . V_184 = V_185 ;
V_44 -> V_122 . V_149 = 0 ;
V_44 -> V_122 . V_150 = 0 ;
V_44 -> V_122 . V_186 = V_187 ;
V_44 -> V_122 . V_145 = - 1 ;
V_44 -> V_122 . V_144 = - 1 ;
switch ( V_55 -> V_128 ) {
case 8 :
V_44 -> V_122 . V_110 . V_124 = 0 ;
V_44 -> V_122 . V_111 . V_124 = 0 ;
V_44 -> V_122 . V_112 . V_124 = 0 ;
V_44 -> V_122 . V_110 . V_123 = 8 ;
V_44 -> V_122 . V_111 . V_123 = 8 ;
V_44 -> V_122 . V_112 . V_123 = 8 ;
V_44 -> V_122 . V_125 . V_124 = 0 ;
V_44 -> V_122 . V_125 . V_123 = 0 ;
break;
case 15 :
V_44 -> V_122 . V_110 . V_124 = 10 ;
V_44 -> V_122 . V_111 . V_124 = 5 ;
V_44 -> V_122 . V_112 . V_124 = 0 ;
V_44 -> V_122 . V_110 . V_123 = 5 ;
V_44 -> V_122 . V_111 . V_123 = 5 ;
V_44 -> V_122 . V_112 . V_123 = 5 ;
V_44 -> V_122 . V_125 . V_124 = 15 ;
V_44 -> V_122 . V_125 . V_123 = 1 ;
break;
case 16 :
V_44 -> V_122 . V_110 . V_124 = 11 ;
V_44 -> V_122 . V_111 . V_124 = 5 ;
V_44 -> V_122 . V_112 . V_124 = 0 ;
V_44 -> V_122 . V_110 . V_123 = 5 ;
V_44 -> V_122 . V_111 . V_123 = 6 ;
V_44 -> V_122 . V_112 . V_123 = 5 ;
V_44 -> V_122 . V_125 . V_124 = 0 ;
break;
case 24 :
V_44 -> V_122 . V_110 . V_124 = 16 ;
V_44 -> V_122 . V_111 . V_124 = 8 ;
V_44 -> V_122 . V_112 . V_124 = 0 ;
V_44 -> V_122 . V_110 . V_123 = 8 ;
V_44 -> V_122 . V_111 . V_123 = 8 ;
V_44 -> V_122 . V_112 . V_123 = 8 ;
V_44 -> V_122 . V_125 . V_124 = 0 ;
V_44 -> V_122 . V_125 . V_123 = 0 ;
break;
case 32 :
V_44 -> V_122 . V_110 . V_124 = 16 ;
V_44 -> V_122 . V_111 . V_124 = 8 ;
V_44 -> V_122 . V_112 . V_124 = 0 ;
V_44 -> V_122 . V_110 . V_123 = 8 ;
V_44 -> V_122 . V_111 . V_123 = 8 ;
V_44 -> V_122 . V_112 . V_123 = 8 ;
V_44 -> V_122 . V_125 . V_124 = 24 ;
V_44 -> V_122 . V_125 . V_123 = 8 ;
break;
default:
break;
}
V_44 -> V_122 . V_25 = V_157 ;
V_44 -> V_122 . V_26 = V_158 ;
}
static int F_56 ( struct V_1 * V_2 ,
T_4 V_188 ,
T_4 V_189 )
{
struct V_5 * V_6 ;
int V_190 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_190 += V_6 -> V_40 -> V_191 ( V_6 , V_188 , V_189 ) ;
}
return V_190 ;
}
static struct V_161 * F_57 ( struct V_8 * V_192 , int V_144 , int V_145 )
{
struct V_161 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( F_58 ( V_17 ) > V_144 ||
F_59 ( V_17 ) > V_145 )
continue;
if ( V_17 -> type & V_193 )
return V_17 ;
}
return NULL ;
}
static bool F_60 ( struct V_8 * V_192 )
{
struct V_16 * V_19 ;
V_19 = & V_192 -> V_19 ;
return V_19 -> V_194 ;
}
static struct V_161 * F_61 ( struct V_8 * V_15 ,
int V_144 , int V_145 )
{
struct V_16 * V_19 ;
struct V_161 * V_17 = NULL ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_194 == false )
return V_17 ;
if ( V_19 -> V_29 || V_19 -> V_30 )
goto V_195;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_163 != V_19 -> V_25 ||
V_17 -> V_164 != V_19 -> V_26 )
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
V_17 = F_62 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_53 ( & V_17 -> V_199 , & V_15 -> V_6 -> V_200 ) ;
return V_17 ;
}
static bool F_63 ( struct V_5 * V_6 , bool V_201 )
{
bool V_202 ;
if ( V_201 ) {
V_202 = V_6 -> V_203 == V_204 ;
} else {
V_202 = V_6 -> V_203 != V_205 ;
}
return V_202 ;
}
static void F_64 ( struct V_1 * V_2 ,
bool * V_52 )
{
bool V_206 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_63 ( V_6 , true ) ;
F_10 ( L_20 , V_6 -> V_61 . V_62 ,
V_52 [ V_7 ] ? L_21 : L_22 ) ;
V_206 |= V_52 [ V_7 ] ;
}
if ( V_206 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_63 ( V_6 , false ) ;
}
}
static bool F_65 ( struct V_1 * V_2 ,
struct V_161 * * V_200 ,
bool * V_52 , int V_144 , int V_145 )
{
int V_190 , V_7 , V_79 ;
bool V_207 = false ;
struct V_8 * V_15 ;
struct V_161 * V_208 , * V_17 ;
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
V_200 [ V_7 ] = F_61 ( V_15 , V_144 , V_145 ) ;
if ( ! V_200 [ V_7 ] ) {
V_207 = false ;
break;
}
for ( V_79 = 0 ; V_79 < V_7 ; V_79 ++ ) {
if ( ! V_52 [ V_79 ] )
continue;
if ( ! F_66 ( V_200 [ V_79 ] , V_200 [ V_7 ] ) )
V_207 = false ;
}
}
if ( V_207 ) {
F_10 ( L_23 ) ;
return true ;
}
V_207 = true ;
V_208 = F_67 ( V_2 -> V_4 , 1024 , 768 , 60 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_66 ( V_17 , V_208 ) )
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
static bool F_68 ( struct V_1 * V_2 ,
struct V_161 * * V_200 ,
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
V_200 [ V_7 ] = F_61 ( V_15 , V_144 , V_145 ) ;
if ( ! V_200 [ V_7 ] ) {
F_10 ( L_27 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_200 [ V_7 ] = F_57 ( V_15 , V_144 , V_145 ) ;
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
static int F_69 ( struct V_1 * V_2 ,
struct V_100 * * V_210 ,
struct V_161 * * V_200 ,
int V_68 , int V_144 , int V_145 )
{
int V_60 , V_211 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_212 * V_213 ;
struct V_77 * V_78 ;
struct V_100 * V_214 ;
int V_215 , V_216 , V_217 ;
struct V_100 * * V_218 , * V_33 ;
struct V_8 * V_15 ;
if ( V_68 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_68 ] ;
V_6 = V_15 -> V_6 ;
V_210 [ V_68 ] = NULL ;
V_214 = NULL ;
V_216 = F_69 ( V_2 , V_210 , V_200 , V_68 + 1 , V_144 , V_145 ) ;
if ( V_200 [ V_68 ] == NULL )
return V_216 ;
V_218 = F_3 ( V_4 -> V_80 . V_101 *
sizeof( struct V_100 * ) , V_10 ) ;
if ( ! V_218 )
return V_216 ;
V_215 = 1 ;
if ( V_6 -> V_203 == V_204 )
V_215 ++ ;
if ( F_60 ( V_15 ) )
V_215 ++ ;
if ( F_57 ( V_15 , V_144 , V_145 ) )
V_215 ++ ;
V_213 = V_6 -> V_53 ;
V_78 = V_213 -> V_219 ( V_6 ) ;
if ( ! V_78 )
goto V_220;
for ( V_60 = 0 ; V_60 < V_2 -> V_48 ; V_60 ++ ) {
V_33 = & V_2 -> V_51 [ V_60 ] ;
if ( ( V_78 -> V_221 & ( 1 << V_60 ) ) == 0 ) {
continue;
}
for ( V_211 = 0 ; V_211 < V_68 ; V_211 ++ )
if ( V_210 [ V_211 ] == V_33 )
break;
if ( V_211 < V_68 ) {
if ( V_2 -> V_48 > 1 )
continue;
if ( ! F_66 ( V_200 [ V_211 ] , V_200 [ V_68 ] ) )
continue;
}
V_218 [ V_68 ] = V_33 ;
memcpy ( V_218 , V_210 , V_68 * sizeof( struct V_100 * ) ) ;
V_217 = V_215 + F_69 ( V_2 , V_218 , V_200 , V_68 + 1 ,
V_144 , V_145 ) ;
if ( V_217 > V_216 ) {
V_214 = V_33 ;
V_216 = V_217 ;
memcpy ( V_210 , V_218 ,
V_4 -> V_80 . V_101 *
sizeof( struct V_100 * ) ) ;
}
}
V_220:
F_4 ( V_218 ) ;
return V_216 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_100 * * V_218 ;
struct V_161 * * V_200 ;
struct V_77 * V_78 ;
struct V_49 * V_148 ;
bool * V_52 ;
int V_144 , V_145 ;
int V_7 , V_64 ;
F_10 ( L_30 ) ;
V_144 = V_4 -> V_80 . V_222 ;
V_145 = V_4 -> V_80 . V_223 ;
F_2 (encoder, &dev->mode_config.encoder_list, head) {
V_78 -> V_33 = NULL ;
}
V_218 = F_36 ( V_4 -> V_80 . V_101 ,
sizeof( struct V_100 * ) , V_10 ) ;
V_200 = F_36 ( V_4 -> V_80 . V_101 ,
sizeof( struct V_161 * ) , V_10 ) ;
V_52 = F_36 ( V_4 -> V_80 . V_101 ,
sizeof( bool ) , V_10 ) ;
F_64 ( V_2 , V_52 ) ;
V_64 = F_65 ( V_2 , V_200 , V_52 , V_144 , V_145 ) ;
if ( ! V_64 ) {
V_64 = F_68 ( V_2 , V_200 , V_52 , V_144 , V_145 ) ;
if ( ! V_64 )
F_17 ( L_31 ) ;
}
F_10 ( L_32 , V_144 , V_145 ) ;
F_69 ( V_2 , V_218 , V_200 , 0 , V_144 , V_145 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_148 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_148 -> V_103 = 0 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_161 * V_17 = V_200 [ V_7 ] ;
struct V_100 * V_224 = V_218 [ V_7 ] ;
V_148 = & V_224 -> V_50 ;
if ( V_17 && V_224 ) {
F_10 ( L_33 ,
V_17 -> V_209 , V_224 -> V_50 . V_33 -> V_61 . V_62 ) ;
V_224 -> V_162 = V_17 ;
if ( V_148 -> V_17 )
F_71 ( V_4 , V_148 -> V_17 ) ;
V_148 -> V_17 = F_72 ( V_4 ,
V_224 -> V_162 ) ;
V_148 -> V_97 [ V_148 -> V_103 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
}
}
F_4 ( V_218 ) ;
F_4 ( V_200 ) ;
F_4 ( V_52 ) ;
}
bool F_73 ( struct V_1 * V_2 , int V_225 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_190 = 0 ;
F_74 ( V_2 -> V_4 ) ;
F_5 ( V_2 ) ;
V_190 = F_56 ( V_2 ,
V_4 -> V_80 . V_222 ,
V_4 -> V_80 . V_223 ) ;
if ( V_190 == 0 ) {
F_22 ( V_106 L_34 ) ;
}
F_70 ( V_2 ) ;
return F_49 ( V_2 , V_225 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_190 = 0 ;
T_3 V_222 , V_223 , V_225 ;
bool V_226 = false , V_227 = false ;
struct V_32 * V_33 ;
if ( ! V_2 -> V_55 )
return 0 ;
F_28 ( & V_4 -> V_80 . V_81 ) ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_33 -> V_55 )
V_227 = true ;
if ( V_33 -> V_55 == V_2 -> V_55 )
V_226 = true ;
}
if ( ! V_226 && V_227 ) {
V_2 -> V_147 = true ;
F_30 ( & V_4 -> V_80 . V_81 ) ;
return 0 ;
}
F_10 ( L_30 ) ;
V_222 = V_2 -> V_55 -> V_144 ;
V_223 = V_2 -> V_55 -> V_145 ;
V_225 = V_2 -> V_55 -> V_127 ;
V_190 = F_56 ( V_2 , V_222 ,
V_223 ) ;
F_70 ( V_2 ) ;
F_30 ( & V_4 -> V_80 . V_81 ) ;
return F_49 ( V_2 , V_225 ) ;
}
static int T_5 F_75 ( void )
{
const char * V_209 = L_35 ;
struct V_228 * V_229 ;
F_28 ( & V_230 ) ;
V_229 = F_76 ( V_209 ) ;
F_30 ( & V_230 ) ;
if ( ! V_229 )
F_77 ( V_209 ) ;
return 0 ;
}
