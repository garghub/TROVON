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
if ( V_71 < 0 )
return 0 ;
F_22 ( V_72 L_11 ) ;
return F_20 () ;
}
void F_23 ( void )
{
bool V_64 ;
V_64 = F_20 () ;
if ( V_64 == true )
F_17 ( L_12 ) ;
}
static void F_24 ( struct V_73 * V_74 )
{
F_23 () ;
}
static void F_25 ( int V_75 )
{
F_26 ( & V_76 ) ;
}
static void F_27 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_46 * V_77 ;
struct V_5 * V_6 ;
struct V_78 * V_79 ;
int V_7 , V_80 ;
F_28 ( & V_4 -> V_81 . V_82 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_77 = V_33 -> V_53 ;
if ( ! V_33 -> V_52 )
continue;
V_77 -> V_83 ( V_33 , V_84 ) ;
for ( V_80 = 0 ; V_80 < V_2 -> V_13 ; V_80 ++ ) {
V_6 = V_2 -> V_12 [ V_80 ] -> V_6 ;
V_6 -> V_83 = V_84 ;
F_29 ( V_6 ,
V_4 -> V_81 . V_85 ,
V_84 ) ;
}
F_2 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_79 -> V_33 == V_33 ) {
struct V_86 * V_87 ;
V_87 = V_79 -> V_53 ;
V_87 -> V_83 ( V_79 , V_84 ) ;
}
}
}
F_30 ( & V_4 -> V_81 . V_82 ) ;
}
static void F_31 ( struct V_43 * V_44 , int V_88 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_46 * V_77 ;
struct V_5 * V_6 ;
struct V_78 * V_79 ;
int V_7 , V_80 ;
F_28 ( & V_4 -> V_81 . V_82 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_77 = V_33 -> V_53 ;
if ( ! V_33 -> V_52 )
continue;
for ( V_80 = 0 ; V_80 < V_2 -> V_13 ; V_80 ++ ) {
V_6 = V_2 -> V_12 [ V_80 ] -> V_6 ;
V_6 -> V_83 = V_88 ;
F_29 ( V_6 ,
V_4 -> V_81 . V_85 ,
V_88 ) ;
}
F_2 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_79 -> V_33 == V_33 ) {
struct V_86 * V_87 ;
V_87 = V_79 -> V_53 ;
V_87 -> V_83 ( V_79 , V_88 ) ;
}
}
V_77 -> V_83 ( V_33 , V_89 ) ;
}
F_30 ( & V_4 -> V_81 . V_82 ) ;
}
int F_32 ( int V_90 , struct V_43 * V_44 )
{
switch ( V_90 ) {
case V_91 :
F_27 ( V_44 ) ;
break;
case V_92 :
F_31 ( V_44 , V_93 ) ;
break;
case V_94 :
F_31 ( V_44 , V_93 ) ;
break;
case V_95 :
F_31 ( V_44 , V_96 ) ;
break;
case V_97 :
F_31 ( V_44 , V_89 ) ;
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
F_4 ( V_34 -> V_51 [ V_7 ] . V_50 . V_98 ) ;
F_4 ( V_34 -> V_51 ) ;
}
int F_34 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_48 , int V_99 )
{
struct V_32 * V_33 ;
int V_64 = 0 ;
int V_7 ;
V_2 -> V_4 = V_4 ;
F_35 ( & V_2 -> V_100 ) ;
V_2 -> V_51 = F_36 ( V_48 , sizeof( struct V_101 ) , V_10 ) ;
if ( ! V_2 -> V_51 )
return - V_14 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_12 = F_36 ( V_4 -> V_81 . V_102 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_51 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_98 =
F_36 ( V_99 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_51 [ V_7 ] . V_50 . V_98 ) {
V_64 = - V_14 ;
goto V_103;
}
V_2 -> V_51 [ V_7 ] . V_50 . V_104 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_51 [ V_7 ] . V_105 = V_33 -> V_61 . V_62 ;
V_2 -> V_51 [ V_7 ] . V_50 . V_33 = V_33 ;
V_7 ++ ;
}
V_2 -> V_106 = V_99 ;
return 0 ;
V_103:
F_33 ( V_2 ) ;
return - V_14 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( ! F_14 ( & V_2 -> V_100 ) ) {
F_38 ( & V_2 -> V_100 ) ;
if ( F_14 ( & V_47 ) ) {
F_22 ( V_107 L_13 ) ;
F_39 ( & V_108 ,
& V_109 ) ;
F_40 ( 'v' , & V_110 ) ;
}
}
F_33 ( V_2 ) ;
}
static int F_41 ( struct V_32 * V_33 , T_2 V_111 , T_2 V_112 ,
T_2 V_113 , T_2 V_114 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_115 ;
if ( V_44 -> V_116 . V_117 == V_118 ) {
T_3 * V_119 ;
T_3 V_120 ;
if ( V_114 > 16 )
return - V_121 ;
V_119 = ( T_3 * ) V_44 -> V_122 ;
V_111 >>= ( 16 - V_44 -> V_123 . V_111 . V_124 ) ;
V_112 >>= ( 16 - V_44 -> V_123 . V_112 . V_124 ) ;
V_113 >>= ( 16 - V_44 -> V_123 . V_113 . V_124 ) ;
V_120 = ( V_111 << V_44 -> V_123 . V_111 . V_125 ) |
( V_112 << V_44 -> V_123 . V_112 . V_125 ) |
( V_113 << V_44 -> V_123 . V_113 . V_125 ) ;
if ( V_44 -> V_123 . V_126 . V_124 > 0 ) {
T_3 V_127 = ( 1 << V_44 -> V_123 . V_126 . V_124 ) - 1 ;
V_127 <<= V_44 -> V_123 . V_126 . V_125 ;
V_120 |= V_127 ;
}
V_119 [ V_114 ] = V_120 ;
return 0 ;
}
V_115 = V_114 ;
if ( V_55 -> V_128 == 16 ) {
V_115 = V_114 << 3 ;
if ( V_55 -> V_129 == 16 && V_114 > 63 )
return - V_121 ;
if ( V_55 -> V_129 == 15 && V_114 > 31 )
return - V_121 ;
if ( V_55 -> V_129 == 16 ) {
T_2 V_130 , V_131 , V_132 ;
int V_7 ;
if ( V_114 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_111 ,
V_112 , V_113 , V_115 + V_7 ) ;
}
V_2 -> V_40 -> V_41 ( V_33 , & V_130 ,
& V_131 , & V_132 ,
V_115 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_130 ,
V_112 , V_132 ,
( V_115 >> 1 ) + V_7 ) ;
}
}
if ( V_55 -> V_129 != 16 )
V_2 -> V_40 -> V_42 ( V_33 , V_111 , V_112 , V_113 , V_115 ) ;
return 0 ;
}
int F_42 ( struct V_133 * V_134 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_46 * V_77 ;
T_2 * V_111 , * V_112 , * V_113 , * V_126 ;
struct V_32 * V_33 ;
int V_7 , V_80 , V_135 = 0 ;
int V_136 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_77 = V_33 -> V_53 ;
V_111 = V_134 -> V_111 ;
V_112 = V_134 -> V_112 ;
V_113 = V_134 -> V_113 ;
V_126 = V_134 -> V_126 ;
V_136 = V_134 -> V_136 ;
for ( V_80 = 0 ; V_80 < V_134 -> V_137 ; V_80 ++ ) {
T_2 V_138 , V_139 , V_140 , V_141 = 0xffff ;
V_138 = * V_111 ++ ;
V_139 = * V_112 ++ ;
V_140 = * V_113 ++ ;
if ( V_126 )
V_141 = * V_126 ++ ;
V_135 = F_41 ( V_33 , V_138 , V_139 , V_140 , V_136 ++ , V_44 ) ;
if ( V_135 )
return V_135 ;
}
V_77 -> V_142 ( V_33 ) ;
}
return V_135 ;
}
int F_43 ( struct V_143 * V_123 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_129 ;
if ( V_123 -> V_144 != 0 || F_44 () )
return - V_121 ;
if ( V_123 -> V_128 > V_55 -> V_128 || V_123 -> V_25 > V_55 -> V_145 || V_123 -> V_26 > V_55 -> V_146 ) {
F_45 ( L_14
L_15 , V_123 -> V_25 , V_123 -> V_26 , V_123 -> V_128 ,
V_55 -> V_145 , V_55 -> V_146 , V_55 -> V_128 ) ;
return - V_121 ;
}
switch ( V_123 -> V_128 ) {
case 16 :
V_129 = ( V_123 -> V_112 . V_124 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_129 = ( V_123 -> V_126 . V_124 > 0 ) ? 32 : 24 ;
break;
default:
V_129 = V_123 -> V_128 ;
break;
}
switch ( V_129 ) {
case 8 :
V_123 -> V_111 . V_125 = 0 ;
V_123 -> V_112 . V_125 = 0 ;
V_123 -> V_113 . V_125 = 0 ;
V_123 -> V_111 . V_124 = 8 ;
V_123 -> V_112 . V_124 = 8 ;
V_123 -> V_113 . V_124 = 8 ;
V_123 -> V_126 . V_124 = 0 ;
V_123 -> V_126 . V_125 = 0 ;
break;
case 15 :
V_123 -> V_111 . V_125 = 10 ;
V_123 -> V_112 . V_125 = 5 ;
V_123 -> V_113 . V_125 = 0 ;
V_123 -> V_111 . V_124 = 5 ;
V_123 -> V_112 . V_124 = 5 ;
V_123 -> V_113 . V_124 = 5 ;
V_123 -> V_126 . V_124 = 1 ;
V_123 -> V_126 . V_125 = 15 ;
break;
case 16 :
V_123 -> V_111 . V_125 = 11 ;
V_123 -> V_112 . V_125 = 5 ;
V_123 -> V_113 . V_125 = 0 ;
V_123 -> V_111 . V_124 = 5 ;
V_123 -> V_112 . V_124 = 6 ;
V_123 -> V_113 . V_124 = 5 ;
V_123 -> V_126 . V_124 = 0 ;
V_123 -> V_126 . V_125 = 0 ;
break;
case 24 :
V_123 -> V_111 . V_125 = 16 ;
V_123 -> V_112 . V_125 = 8 ;
V_123 -> V_113 . V_125 = 0 ;
V_123 -> V_111 . V_124 = 8 ;
V_123 -> V_112 . V_124 = 8 ;
V_123 -> V_113 . V_124 = 8 ;
V_123 -> V_126 . V_124 = 0 ;
V_123 -> V_126 . V_125 = 0 ;
break;
case 32 :
V_123 -> V_111 . V_125 = 16 ;
V_123 -> V_112 . V_125 = 8 ;
V_123 -> V_113 . V_125 = 0 ;
V_123 -> V_111 . V_124 = 8 ;
V_123 -> V_112 . V_124 = 8 ;
V_123 -> V_113 . V_124 = 8 ;
V_123 -> V_126 . V_124 = 8 ;
V_123 -> V_126 . V_125 = 24 ;
break;
default:
return - V_121 ;
}
return 0 ;
}
int F_46 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_143 * V_123 = & V_44 -> V_123 ;
struct V_32 * V_33 ;
int V_64 ;
int V_7 ;
if ( V_123 -> V_144 != 0 ) {
F_17 ( L_16 ) ;
return - V_121 ;
}
F_28 ( & V_4 -> V_81 . V_82 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_64 = V_33 -> V_40 -> V_147 ( & V_2 -> V_51 [ V_7 ] . V_50 ) ;
if ( V_64 ) {
F_30 ( & V_4 -> V_81 . V_82 ) ;
return V_64 ;
}
}
F_30 ( & V_4 -> V_81 . V_82 ) ;
if ( V_2 -> V_148 ) {
V_2 -> V_148 = false ;
F_47 ( V_2 ) ;
}
return 0 ;
}
int F_48 ( struct V_143 * V_123 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_149 ;
struct V_32 * V_33 ;
int V_64 = 0 ;
int V_7 ;
F_28 ( & V_4 -> V_81 . V_82 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_149 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_149 -> V_56 = V_123 -> V_150 ;
V_149 -> V_57 = V_123 -> V_151 ;
if ( V_149 -> V_104 ) {
V_64 = V_33 -> V_40 -> V_147 ( V_149 ) ;
if ( ! V_64 ) {
V_44 -> V_123 . V_150 = V_123 -> V_150 ;
V_44 -> V_123 . V_151 = V_123 -> V_151 ;
}
}
}
F_30 ( & V_4 -> V_81 . V_82 ) ;
return V_64 ;
}
int F_49 ( struct V_1 * V_2 ,
int V_152 )
{
int V_153 = 0 ;
int V_48 = 0 ;
int V_7 ;
struct V_43 * V_44 ;
struct V_154 V_155 ;
int V_39 = 0 ;
memset ( & V_155 , 0 , sizeof( struct V_154 ) ) ;
V_155 . V_156 = 24 ;
V_155 . V_157 = 32 ;
V_155 . V_158 = ( unsigned ) - 1 ;
V_155 . V_159 = ( unsigned ) - 1 ;
if ( V_152 != V_155 . V_157 ) {
V_155 . V_156 = V_155 . V_157 = V_152 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_15 = V_2 -> V_12 [ V_7 ] ;
struct V_16 * V_19 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_160 ) {
switch ( V_19 -> V_161 ) {
case 8 :
V_155 . V_156 = V_155 . V_157 = 8 ;
break;
case 15 :
V_155 . V_156 = 15 ;
V_155 . V_157 = 16 ;
break;
case 16 :
V_155 . V_156 = V_155 . V_157 = 16 ;
break;
case 24 :
V_155 . V_156 = V_155 . V_157 = 24 ;
break;
case 32 :
V_155 . V_156 = 24 ;
V_155 . V_157 = 32 ;
break;
}
break;
}
}
V_48 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_162 * V_163 ;
V_163 = V_2 -> V_51 [ V_7 ] . V_163 ;
if ( V_163 ) {
if ( V_39 == 0 )
V_39 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 -> V_39 ;
if ( V_163 -> V_164 < V_155 . V_158 )
V_155 . V_158 = V_163 -> V_164 ;
if ( V_163 -> V_165 < V_155 . V_159 )
V_155 . V_159 = V_163 -> V_165 ;
if ( V_163 -> V_164 > V_155 . V_166 )
V_155 . V_166 = V_163 -> V_164 ;
if ( V_163 -> V_165 > V_155 . V_167 )
V_155 . V_167 = V_163 -> V_165 ;
V_48 ++ ;
}
}
if ( V_48 == 0 || V_155 . V_158 == - 1 || V_155 . V_159 == - 1 ) {
F_9 ( L_17 ) ;
V_155 . V_158 = V_155 . V_166 = 1024 ;
V_155 . V_159 = V_155 . V_167 = 768 ;
}
V_153 = (* V_2 -> V_40 -> V_168 )( V_2 , & V_155 ) ;
if ( V_153 < 0 )
return V_153 ;
V_44 = V_2 -> V_169 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_55 = V_2 -> V_55 ;
}
if ( V_153 ) {
V_44 -> V_123 . V_144 = 0 ;
if ( F_50 ( V_44 ) < 0 ) {
return - V_121 ;
}
F_22 ( V_107 L_18 , V_44 -> V_170 ,
V_44 -> V_116 . V_62 ) ;
} else {
F_46 ( V_44 ) ;
}
if ( F_14 ( & V_47 ) ) {
F_22 ( V_107 L_19 ) ;
F_51 ( & V_108 ,
& V_109 ) ;
F_52 ( 'v' , & V_110 ) ;
}
if ( V_153 )
F_53 ( & V_2 -> V_100 , & V_47 ) ;
return 0 ;
}
void F_54 ( struct V_43 * V_44 , T_4 V_171 ,
T_4 V_129 )
{
V_44 -> V_116 . type = V_172 ;
V_44 -> V_116 . V_117 = V_129 == 8 ? V_173 :
V_118 ;
V_44 -> V_116 . V_174 = 0 ;
V_44 -> V_116 . V_175 = 0 ;
V_44 -> V_116 . V_176 = 0 ;
V_44 -> V_116 . V_177 = 1 ;
V_44 -> V_116 . V_178 = 1 ;
V_44 -> V_116 . V_179 = 0 ;
V_44 -> V_116 . V_180 = V_181 ;
V_44 -> V_116 . V_176 = 0 ;
V_44 -> V_116 . V_182 = V_171 ;
return;
}
void F_55 ( struct V_43 * V_44 , struct V_1 * V_2 ,
T_4 V_158 , T_4 V_159 )
{
struct V_59 * V_55 = V_2 -> V_55 ;
V_44 -> V_122 = V_2 -> V_122 ;
V_44 -> V_123 . V_183 = V_55 -> V_145 ;
V_44 -> V_123 . V_184 = V_55 -> V_146 ;
V_44 -> V_123 . V_128 = V_55 -> V_128 ;
V_44 -> V_123 . V_185 = V_186 ;
V_44 -> V_123 . V_150 = 0 ;
V_44 -> V_123 . V_151 = 0 ;
V_44 -> V_123 . V_187 = V_188 ;
V_44 -> V_123 . V_146 = - 1 ;
V_44 -> V_123 . V_145 = - 1 ;
switch ( V_55 -> V_129 ) {
case 8 :
V_44 -> V_123 . V_111 . V_125 = 0 ;
V_44 -> V_123 . V_112 . V_125 = 0 ;
V_44 -> V_123 . V_113 . V_125 = 0 ;
V_44 -> V_123 . V_111 . V_124 = 8 ;
V_44 -> V_123 . V_112 . V_124 = 8 ;
V_44 -> V_123 . V_113 . V_124 = 8 ;
V_44 -> V_123 . V_126 . V_125 = 0 ;
V_44 -> V_123 . V_126 . V_124 = 0 ;
break;
case 15 :
V_44 -> V_123 . V_111 . V_125 = 10 ;
V_44 -> V_123 . V_112 . V_125 = 5 ;
V_44 -> V_123 . V_113 . V_125 = 0 ;
V_44 -> V_123 . V_111 . V_124 = 5 ;
V_44 -> V_123 . V_112 . V_124 = 5 ;
V_44 -> V_123 . V_113 . V_124 = 5 ;
V_44 -> V_123 . V_126 . V_125 = 15 ;
V_44 -> V_123 . V_126 . V_124 = 1 ;
break;
case 16 :
V_44 -> V_123 . V_111 . V_125 = 11 ;
V_44 -> V_123 . V_112 . V_125 = 5 ;
V_44 -> V_123 . V_113 . V_125 = 0 ;
V_44 -> V_123 . V_111 . V_124 = 5 ;
V_44 -> V_123 . V_112 . V_124 = 6 ;
V_44 -> V_123 . V_113 . V_124 = 5 ;
V_44 -> V_123 . V_126 . V_125 = 0 ;
break;
case 24 :
V_44 -> V_123 . V_111 . V_125 = 16 ;
V_44 -> V_123 . V_112 . V_125 = 8 ;
V_44 -> V_123 . V_113 . V_125 = 0 ;
V_44 -> V_123 . V_111 . V_124 = 8 ;
V_44 -> V_123 . V_112 . V_124 = 8 ;
V_44 -> V_123 . V_113 . V_124 = 8 ;
V_44 -> V_123 . V_126 . V_125 = 0 ;
V_44 -> V_123 . V_126 . V_124 = 0 ;
break;
case 32 :
V_44 -> V_123 . V_111 . V_125 = 16 ;
V_44 -> V_123 . V_112 . V_125 = 8 ;
V_44 -> V_123 . V_113 . V_125 = 0 ;
V_44 -> V_123 . V_111 . V_124 = 8 ;
V_44 -> V_123 . V_112 . V_124 = 8 ;
V_44 -> V_123 . V_113 . V_124 = 8 ;
V_44 -> V_123 . V_126 . V_125 = 24 ;
V_44 -> V_123 . V_126 . V_124 = 8 ;
break;
default:
break;
}
V_44 -> V_123 . V_25 = V_158 ;
V_44 -> V_123 . V_26 = V_159 ;
}
static int F_56 ( struct V_1 * V_2 ,
T_4 V_189 ,
T_4 V_190 )
{
struct V_5 * V_6 ;
int V_191 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_191 += V_6 -> V_40 -> V_192 ( V_6 , V_189 , V_190 ) ;
}
return V_191 ;
}
static struct V_162 * F_57 ( struct V_8 * V_193 , int V_145 , int V_146 )
{
struct V_162 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( F_58 ( V_17 ) > V_145 ||
F_59 ( V_17 ) > V_146 )
continue;
if ( V_17 -> type & V_194 )
return V_17 ;
}
return NULL ;
}
static bool F_60 ( struct V_8 * V_193 )
{
struct V_16 * V_19 ;
V_19 = & V_193 -> V_19 ;
return V_19 -> V_195 ;
}
static struct V_162 * F_61 ( struct V_8 * V_15 ,
int V_145 , int V_146 )
{
struct V_16 * V_19 ;
struct V_162 * V_17 = NULL ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_195 == false )
return V_17 ;
if ( V_19 -> V_29 || V_19 -> V_30 )
goto V_196;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_164 != V_19 -> V_25 ||
V_17 -> V_165 != V_19 -> V_26 )
continue;
if ( V_19 -> V_27 ) {
if ( V_17 -> V_197 != V_19 -> V_28 )
continue;
}
if ( V_19 -> V_31 ) {
if ( ! ( V_17 -> V_198 & V_199 ) )
continue;
}
return V_17 ;
}
V_196:
V_17 = F_62 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_53 ( & V_17 -> V_200 , & V_15 -> V_6 -> V_201 ) ;
return V_17 ;
}
static bool F_63 ( struct V_5 * V_6 , bool V_202 )
{
bool V_203 ;
if ( V_202 ) {
V_203 = V_6 -> V_204 == V_205 ;
} else {
V_203 = V_6 -> V_204 != V_206 ;
}
return V_203 ;
}
static void F_64 ( struct V_1 * V_2 ,
bool * V_52 )
{
bool V_207 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_63 ( V_6 , true ) ;
F_10 ( L_20 , V_6 -> V_61 . V_62 ,
V_52 [ V_7 ] ? L_21 : L_22 ) ;
V_207 |= V_52 [ V_7 ] ;
}
if ( V_207 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_63 ( V_6 , false ) ;
}
}
static bool F_65 ( struct V_1 * V_2 ,
struct V_162 * * V_201 ,
bool * V_52 , int V_145 , int V_146 )
{
int V_191 , V_7 , V_80 ;
bool V_208 = false ;
struct V_8 * V_15 ;
struct V_162 * V_209 , * V_17 ;
if ( V_2 -> V_48 > 1 )
return false ;
V_191 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_52 [ V_7 ] )
V_191 ++ ;
}
if ( V_191 <= 1 )
return false ;
V_208 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_201 [ V_7 ] = F_61 ( V_15 , V_145 , V_146 ) ;
if ( ! V_201 [ V_7 ] ) {
V_208 = false ;
break;
}
for ( V_80 = 0 ; V_80 < V_7 ; V_80 ++ ) {
if ( ! V_52 [ V_80 ] )
continue;
if ( ! F_66 ( V_201 [ V_80 ] , V_201 [ V_7 ] ) )
V_208 = false ;
}
}
if ( V_208 ) {
F_10 ( L_23 ) ;
return true ;
}
V_208 = true ;
V_209 = F_67 ( V_2 -> V_4 , 1024 , 768 , 60 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_66 ( V_17 , V_209 ) )
V_201 [ V_7 ] = V_17 ;
}
if ( ! V_201 [ V_7 ] )
V_208 = false ;
}
if ( V_208 ) {
F_10 ( L_24 ) ;
return true ;
}
F_9 ( L_25 ) ;
return false ;
}
static bool F_68 ( struct V_1 * V_2 ,
struct V_162 * * V_201 ,
bool * V_52 , int V_145 , int V_146 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_15 = V_2 -> V_12 [ V_7 ] ;
if ( V_52 [ V_7 ] == false )
continue;
F_10 ( L_26 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_201 [ V_7 ] = F_61 ( V_15 , V_145 , V_146 ) ;
if ( ! V_201 [ V_7 ] ) {
F_10 ( L_27 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_201 [ V_7 ] = F_57 ( V_15 , V_145 , V_146 ) ;
}
if ( ! V_201 [ V_7 ] && ! F_14 ( & V_15 -> V_6 -> V_201 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_10 ( L_28 , V_201 [ V_7 ] ? V_201 [ V_7 ] -> V_210 :
L_29 ) ;
}
return true ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_101 * * V_211 ,
struct V_162 * * V_201 ,
int V_68 , int V_145 , int V_146 )
{
int V_60 , V_212 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_213 * V_214 ;
struct V_78 * V_79 ;
struct V_101 * V_215 ;
int V_216 , V_217 , V_218 ;
struct V_101 * * V_219 , * V_33 ;
struct V_8 * V_15 ;
if ( V_68 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_68 ] ;
V_6 = V_15 -> V_6 ;
V_211 [ V_68 ] = NULL ;
V_215 = NULL ;
V_217 = F_69 ( V_2 , V_211 , V_201 , V_68 + 1 , V_145 , V_146 ) ;
if ( V_201 [ V_68 ] == NULL )
return V_217 ;
V_219 = F_3 ( V_4 -> V_81 . V_102 *
sizeof( struct V_101 * ) , V_10 ) ;
if ( ! V_219 )
return V_217 ;
V_216 = 1 ;
if ( V_6 -> V_204 == V_205 )
V_216 ++ ;
if ( F_60 ( V_15 ) )
V_216 ++ ;
if ( F_57 ( V_15 , V_145 , V_146 ) )
V_216 ++ ;
V_214 = V_6 -> V_53 ;
V_79 = V_214 -> V_220 ( V_6 ) ;
if ( ! V_79 )
goto V_221;
for ( V_60 = 0 ; V_60 < V_2 -> V_48 ; V_60 ++ ) {
V_33 = & V_2 -> V_51 [ V_60 ] ;
if ( ( V_79 -> V_222 & ( 1 << V_60 ) ) == 0 ) {
continue;
}
for ( V_212 = 0 ; V_212 < V_68 ; V_212 ++ )
if ( V_211 [ V_212 ] == V_33 )
break;
if ( V_212 < V_68 ) {
if ( V_2 -> V_48 > 1 )
continue;
if ( ! F_66 ( V_201 [ V_212 ] , V_201 [ V_68 ] ) )
continue;
}
V_219 [ V_68 ] = V_33 ;
memcpy ( V_219 , V_211 , V_68 * sizeof( struct V_101 * ) ) ;
V_218 = V_216 + F_69 ( V_2 , V_219 , V_201 , V_68 + 1 ,
V_145 , V_146 ) ;
if ( V_218 > V_217 ) {
V_215 = V_33 ;
V_217 = V_218 ;
memcpy ( V_211 , V_219 ,
V_4 -> V_81 . V_102 *
sizeof( struct V_101 * ) ) ;
}
}
V_221:
F_4 ( V_219 ) ;
return V_217 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_101 * * V_219 ;
struct V_162 * * V_201 ;
struct V_78 * V_79 ;
struct V_49 * V_149 ;
bool * V_52 ;
int V_145 , V_146 ;
int V_7 , V_64 ;
F_10 ( L_30 ) ;
V_145 = V_4 -> V_81 . V_223 ;
V_146 = V_4 -> V_81 . V_224 ;
F_2 (encoder, &dev->mode_config.encoder_list, head) {
V_79 -> V_33 = NULL ;
}
V_219 = F_36 ( V_4 -> V_81 . V_102 ,
sizeof( struct V_101 * ) , V_10 ) ;
V_201 = F_36 ( V_4 -> V_81 . V_102 ,
sizeof( struct V_162 * ) , V_10 ) ;
V_52 = F_36 ( V_4 -> V_81 . V_102 ,
sizeof( bool ) , V_10 ) ;
F_64 ( V_2 , V_52 ) ;
V_64 = F_65 ( V_2 , V_201 , V_52 , V_145 , V_146 ) ;
if ( ! V_64 ) {
V_64 = F_68 ( V_2 , V_201 , V_52 , V_145 , V_146 ) ;
if ( ! V_64 )
F_17 ( L_31 ) ;
}
F_10 ( L_32 , V_145 , V_146 ) ;
F_69 ( V_2 , V_219 , V_201 , 0 , V_145 , V_146 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_149 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_149 -> V_104 = 0 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_162 * V_17 = V_201 [ V_7 ] ;
struct V_101 * V_225 = V_219 [ V_7 ] ;
V_149 = & V_225 -> V_50 ;
if ( V_17 && V_225 ) {
F_10 ( L_33 ,
V_17 -> V_210 , V_225 -> V_50 . V_33 -> V_61 . V_62 ) ;
V_225 -> V_163 = V_17 ;
if ( V_149 -> V_17 )
F_71 ( V_4 , V_149 -> V_17 ) ;
V_149 -> V_17 = F_72 ( V_4 ,
V_225 -> V_163 ) ;
V_149 -> V_98 [ V_149 -> V_104 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
}
}
F_4 ( V_219 ) ;
F_4 ( V_201 ) ;
F_4 ( V_52 ) ;
}
bool F_73 ( struct V_1 * V_2 , int V_226 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_191 = 0 ;
F_74 ( V_2 -> V_4 ) ;
F_5 ( V_2 ) ;
V_191 = F_56 ( V_2 ,
V_4 -> V_81 . V_223 ,
V_4 -> V_81 . V_224 ) ;
if ( V_191 == 0 ) {
F_22 ( V_107 L_34 ) ;
}
F_70 ( V_2 ) ;
return F_49 ( V_2 , V_226 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_191 = 0 ;
T_3 V_223 , V_224 , V_226 ;
bool V_227 = false , V_228 = false ;
struct V_32 * V_33 ;
if ( ! V_2 -> V_55 )
return 0 ;
F_28 ( & V_4 -> V_81 . V_82 ) ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_33 -> V_55 )
V_228 = true ;
if ( V_33 -> V_55 == V_2 -> V_55 )
V_227 = true ;
}
if ( ! V_227 && V_228 ) {
V_2 -> V_148 = true ;
F_30 ( & V_4 -> V_81 . V_82 ) ;
return 0 ;
}
F_10 ( L_30 ) ;
V_223 = V_2 -> V_55 -> V_145 ;
V_224 = V_2 -> V_55 -> V_146 ;
V_226 = V_2 -> V_55 -> V_128 ;
V_191 = F_56 ( V_2 , V_223 ,
V_224 ) ;
F_70 ( V_2 ) ;
F_30 ( & V_4 -> V_81 . V_82 ) ;
return F_49 ( V_2 , V_226 ) ;
}
static int T_5 F_75 ( void )
{
const char * V_210 = L_35 ;
struct V_229 * V_230 ;
F_28 ( & V_231 ) ;
V_230 = F_76 ( V_210 ) ;
F_30 ( & V_231 ) ;
if ( ! V_230 )
F_77 ( V_210 ) ;
return 0 ;
}
