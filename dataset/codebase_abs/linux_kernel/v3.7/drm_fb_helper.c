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
if ( V_33 -> V_40 -> V_42 == NULL )
return;
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
V_64 = V_50 -> V_33 -> V_40 -> V_65 ( V_50 ) ;
if ( V_64 )
error = true ;
}
return error ;
}
static bool F_19 ( void )
{
bool V_64 , error = false ;
struct V_1 * V_34 ;
if ( F_14 ( & V_47 ) )
return false ;
F_2 (helper, &kernel_fb_helper_list, kernel_fb_list) {
if ( V_34 -> V_4 -> V_66 == V_67 )
continue;
V_64 = F_18 ( V_34 ) ;
if ( V_64 )
error = true ;
}
return error ;
}
int F_20 ( struct V_68 * V_69 , unsigned long V_70 ,
void * V_71 )
{
if ( V_72 < 0 )
return 0 ;
F_21 ( V_73 L_11 ) ;
return F_19 () ;
}
void F_22 ( void )
{
bool V_64 ;
V_64 = F_19 () ;
if ( V_64 == true )
F_17 ( L_12 ) ;
}
static void F_23 ( struct V_74 * V_75 )
{
F_22 () ;
}
static void F_24 ( int V_76 )
{
F_25 ( & V_77 ) ;
}
static void F_26 ( struct V_43 * V_44 , int V_78 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_5 * V_6 ;
int V_7 , V_79 ;
F_27 ( & V_4 -> V_80 . V_81 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
if ( ! V_33 -> V_52 )
continue;
for ( V_79 = 0 ; V_79 < V_2 -> V_13 ; V_79 ++ ) {
V_6 = V_2 -> V_12 [ V_79 ] -> V_6 ;
V_6 -> V_40 -> V_82 ( V_6 , V_78 ) ;
F_28 ( V_6 ,
V_4 -> V_80 . V_83 , V_78 ) ;
}
}
F_29 ( & V_4 -> V_80 . V_81 ) ;
}
int F_30 ( int V_84 , struct V_43 * V_44 )
{
switch ( V_84 ) {
case V_85 :
F_26 ( V_44 , V_86 ) ;
break;
case V_87 :
F_26 ( V_44 , V_88 ) ;
break;
case V_89 :
F_26 ( V_44 , V_88 ) ;
break;
case V_90 :
F_26 ( V_44 , V_91 ) ;
break;
case V_92 :
F_26 ( V_44 , V_93 ) ;
break;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_34 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_34 -> V_13 ; V_7 ++ )
F_4 ( V_34 -> V_12 [ V_7 ] ) ;
F_4 ( V_34 -> V_12 ) ;
for ( V_7 = 0 ; V_7 < V_34 -> V_48 ; V_7 ++ ) {
F_4 ( V_34 -> V_51 [ V_7 ] . V_50 . V_94 ) ;
if ( V_34 -> V_51 [ V_7 ] . V_50 . V_17 )
F_32 ( V_34 -> V_4 , V_34 -> V_51 [ V_7 ] . V_50 . V_17 ) ;
}
F_4 ( V_34 -> V_51 ) ;
}
int F_33 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_48 , int V_95 )
{
struct V_32 * V_33 ;
int V_7 ;
V_2 -> V_4 = V_4 ;
F_34 ( & V_2 -> V_96 ) ;
V_2 -> V_51 = F_35 ( V_48 , sizeof( struct V_97 ) , V_10 ) ;
if ( ! V_2 -> V_51 )
return - V_14 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_12 = F_35 ( V_4 -> V_80 . V_98 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_51 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_94 =
F_35 ( V_95 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_51 [ V_7 ] . V_50 . V_94 )
goto V_99;
V_2 -> V_51 [ V_7 ] . V_50 . V_100 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_51 [ V_7 ] . V_50 . V_33 = V_33 ;
V_7 ++ ;
}
return 0 ;
V_99:
F_31 ( V_2 ) ;
return - V_14 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! F_14 ( & V_2 -> V_96 ) ) {
F_37 ( & V_2 -> V_96 ) ;
if ( F_14 ( & V_47 ) ) {
F_21 ( V_101 L_13 ) ;
F_38 ( & V_102 ,
& V_103 ) ;
F_39 ( 'v' , & V_104 ) ;
}
}
F_31 ( V_2 ) ;
}
static int F_40 ( struct V_32 * V_33 , T_2 V_105 , T_2 V_106 ,
T_2 V_107 , T_2 V_108 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_109 ;
if ( V_44 -> V_110 . V_111 == V_112 ) {
T_3 * V_113 ;
T_3 V_114 ;
if ( V_108 > 16 )
return - V_115 ;
V_113 = ( T_3 * ) V_44 -> V_116 ;
V_105 >>= ( 16 - V_44 -> V_117 . V_105 . V_118 ) ;
V_106 >>= ( 16 - V_44 -> V_117 . V_106 . V_118 ) ;
V_107 >>= ( 16 - V_44 -> V_117 . V_107 . V_118 ) ;
V_114 = ( V_105 << V_44 -> V_117 . V_105 . V_119 ) |
( V_106 << V_44 -> V_117 . V_106 . V_119 ) |
( V_107 << V_44 -> V_117 . V_107 . V_119 ) ;
if ( V_44 -> V_117 . V_120 . V_118 > 0 ) {
T_3 V_121 = ( 1 << V_44 -> V_117 . V_120 . V_118 ) - 1 ;
V_121 <<= V_44 -> V_117 . V_120 . V_119 ;
V_114 |= V_121 ;
}
V_113 [ V_108 ] = V_114 ;
return 0 ;
}
V_109 = V_108 ;
if ( V_55 -> V_122 == 16 ) {
V_109 = V_108 << 3 ;
if ( V_55 -> V_123 == 16 && V_108 > 63 )
return - V_115 ;
if ( V_55 -> V_123 == 15 && V_108 > 31 )
return - V_115 ;
if ( V_55 -> V_123 == 16 ) {
T_2 V_124 , V_125 , V_126 ;
int V_7 ;
if ( V_108 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_105 ,
V_106 , V_107 , V_109 + V_7 ) ;
}
V_2 -> V_40 -> V_41 ( V_33 , & V_124 ,
& V_125 , & V_126 ,
V_109 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_124 ,
V_106 , V_126 ,
( V_109 >> 1 ) + V_7 ) ;
}
}
if ( V_55 -> V_123 != 16 )
V_2 -> V_40 -> V_42 ( V_33 , V_105 , V_106 , V_107 , V_109 ) ;
return 0 ;
}
int F_41 ( struct V_127 * V_128 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_46 * V_129 ;
T_2 * V_105 , * V_106 , * V_107 , * V_120 ;
struct V_32 * V_33 ;
int V_7 , V_79 , V_130 = 0 ;
int V_131 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_129 = V_33 -> V_53 ;
V_105 = V_128 -> V_105 ;
V_106 = V_128 -> V_106 ;
V_107 = V_128 -> V_107 ;
V_120 = V_128 -> V_120 ;
V_131 = V_128 -> V_131 ;
for ( V_79 = 0 ; V_79 < V_128 -> V_132 ; V_79 ++ ) {
T_2 V_133 , V_134 , V_135 , V_136 = 0xffff ;
V_133 = * V_105 ++ ;
V_134 = * V_106 ++ ;
V_135 = * V_107 ++ ;
if ( V_120 )
V_136 = * V_120 ++ ;
V_130 = F_40 ( V_33 , V_133 , V_134 , V_135 , V_131 ++ , V_44 ) ;
if ( V_130 )
return V_130 ;
}
V_129 -> V_137 ( V_33 ) ;
}
return V_130 ;
}
int F_42 ( struct V_138 * V_117 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_123 ;
if ( V_117 -> V_139 != 0 || F_43 () )
return - V_115 ;
if ( V_117 -> V_122 > V_55 -> V_122 ||
V_117 -> V_25 > V_55 -> V_140 || V_117 -> V_26 > V_55 -> V_141 ||
V_117 -> V_142 > V_55 -> V_140 || V_117 -> V_143 > V_55 -> V_141 ) {
F_44 ( L_14
L_15 ,
V_117 -> V_25 , V_117 -> V_26 , V_117 -> V_122 ,
V_117 -> V_142 , V_117 -> V_143 ,
V_55 -> V_140 , V_55 -> V_141 , V_55 -> V_122 ) ;
return - V_115 ;
}
switch ( V_117 -> V_122 ) {
case 16 :
V_123 = ( V_117 -> V_106 . V_118 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_123 = ( V_117 -> V_120 . V_118 > 0 ) ? 32 : 24 ;
break;
default:
V_123 = V_117 -> V_122 ;
break;
}
switch ( V_123 ) {
case 8 :
V_117 -> V_105 . V_119 = 0 ;
V_117 -> V_106 . V_119 = 0 ;
V_117 -> V_107 . V_119 = 0 ;
V_117 -> V_105 . V_118 = 8 ;
V_117 -> V_106 . V_118 = 8 ;
V_117 -> V_107 . V_118 = 8 ;
V_117 -> V_120 . V_118 = 0 ;
V_117 -> V_120 . V_119 = 0 ;
break;
case 15 :
V_117 -> V_105 . V_119 = 10 ;
V_117 -> V_106 . V_119 = 5 ;
V_117 -> V_107 . V_119 = 0 ;
V_117 -> V_105 . V_118 = 5 ;
V_117 -> V_106 . V_118 = 5 ;
V_117 -> V_107 . V_118 = 5 ;
V_117 -> V_120 . V_118 = 1 ;
V_117 -> V_120 . V_119 = 15 ;
break;
case 16 :
V_117 -> V_105 . V_119 = 11 ;
V_117 -> V_106 . V_119 = 5 ;
V_117 -> V_107 . V_119 = 0 ;
V_117 -> V_105 . V_118 = 5 ;
V_117 -> V_106 . V_118 = 6 ;
V_117 -> V_107 . V_118 = 5 ;
V_117 -> V_120 . V_118 = 0 ;
V_117 -> V_120 . V_119 = 0 ;
break;
case 24 :
V_117 -> V_105 . V_119 = 16 ;
V_117 -> V_106 . V_119 = 8 ;
V_117 -> V_107 . V_119 = 0 ;
V_117 -> V_105 . V_118 = 8 ;
V_117 -> V_106 . V_118 = 8 ;
V_117 -> V_107 . V_118 = 8 ;
V_117 -> V_120 . V_118 = 0 ;
V_117 -> V_120 . V_119 = 0 ;
break;
case 32 :
V_117 -> V_105 . V_119 = 16 ;
V_117 -> V_106 . V_119 = 8 ;
V_117 -> V_107 . V_119 = 0 ;
V_117 -> V_105 . V_118 = 8 ;
V_117 -> V_106 . V_118 = 8 ;
V_117 -> V_107 . V_118 = 8 ;
V_117 -> V_120 . V_118 = 8 ;
V_117 -> V_120 . V_119 = 24 ;
break;
default:
return - V_115 ;
}
return 0 ;
}
int F_45 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_138 * V_117 = & V_44 -> V_117 ;
struct V_32 * V_33 ;
int V_64 ;
int V_7 ;
if ( V_117 -> V_139 != 0 ) {
F_17 ( L_16 ) ;
return - V_115 ;
}
F_27 ( & V_4 -> V_80 . V_81 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_64 = V_33 -> V_40 -> V_65 ( & V_2 -> V_51 [ V_7 ] . V_50 ) ;
if ( V_64 ) {
F_29 ( & V_4 -> V_80 . V_81 ) ;
return V_64 ;
}
}
F_29 ( & V_4 -> V_80 . V_81 ) ;
if ( V_2 -> V_144 ) {
V_2 -> V_144 = false ;
F_46 ( V_2 ) ;
}
return 0 ;
}
int F_47 ( struct V_138 * V_117 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_145 ;
struct V_32 * V_33 ;
int V_64 = 0 ;
int V_7 ;
F_27 ( & V_4 -> V_80 . V_81 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_145 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_145 -> V_56 = V_117 -> V_146 ;
V_145 -> V_57 = V_117 -> V_147 ;
if ( V_145 -> V_100 ) {
V_64 = V_33 -> V_40 -> V_65 ( V_145 ) ;
if ( ! V_64 ) {
V_44 -> V_117 . V_146 = V_117 -> V_146 ;
V_44 -> V_117 . V_147 = V_117 -> V_147 ;
}
}
}
F_29 ( & V_4 -> V_80 . V_81 ) ;
return V_64 ;
}
int F_48 ( struct V_1 * V_2 ,
int V_148 )
{
int V_149 = 0 ;
int V_48 = 0 ;
int V_7 ;
struct V_43 * V_44 ;
struct V_150 V_151 ;
int V_39 = 0 ;
memset ( & V_151 , 0 , sizeof( struct V_150 ) ) ;
V_151 . V_152 = 24 ;
V_151 . V_153 = 32 ;
V_151 . V_154 = ( unsigned ) - 1 ;
V_151 . V_155 = ( unsigned ) - 1 ;
if ( V_148 != V_151 . V_153 ) {
V_151 . V_152 = V_151 . V_153 = V_148 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_15 = V_2 -> V_12 [ V_7 ] ;
struct V_16 * V_19 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_156 ) {
switch ( V_19 -> V_157 ) {
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
V_48 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_158 * V_159 ;
V_159 = V_2 -> V_51 [ V_7 ] . V_159 ;
if ( V_159 ) {
if ( V_39 == 0 )
V_39 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 -> V_39 ;
if ( V_159 -> V_160 < V_151 . V_154 )
V_151 . V_154 = V_159 -> V_160 ;
if ( V_159 -> V_161 < V_151 . V_155 )
V_151 . V_155 = V_159 -> V_161 ;
if ( V_159 -> V_160 > V_151 . V_162 )
V_151 . V_162 = V_159 -> V_160 ;
if ( V_159 -> V_161 > V_151 . V_163 )
V_151 . V_163 = V_159 -> V_161 ;
V_48 ++ ;
}
}
if ( V_48 == 0 || V_151 . V_154 == - 1 || V_151 . V_155 == - 1 ) {
F_9 ( L_17 ) ;
V_151 . V_154 = V_151 . V_162 = 1024 ;
V_151 . V_155 = V_151 . V_163 = 768 ;
}
V_149 = (* V_2 -> V_40 -> V_164 )( V_2 , & V_151 ) ;
if ( V_149 < 0 )
return V_149 ;
V_44 = V_2 -> V_165 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_55 = V_2 -> V_55 ;
}
if ( V_149 ) {
V_44 -> V_117 . V_139 = 0 ;
if ( F_49 ( V_44 ) < 0 ) {
return - V_115 ;
}
F_21 ( V_101 L_18 , V_44 -> V_166 ,
V_44 -> V_110 . V_62 ) ;
} else {
F_45 ( V_44 ) ;
}
if ( F_14 ( & V_47 ) ) {
F_21 ( V_101 L_19 ) ;
F_50 ( & V_102 ,
& V_103 ) ;
F_51 ( 'v' , & V_104 ) ;
}
if ( V_149 )
F_52 ( & V_2 -> V_96 , & V_47 ) ;
return 0 ;
}
void F_53 ( struct V_43 * V_44 , T_4 V_167 ,
T_4 V_123 )
{
V_44 -> V_110 . type = V_168 ;
V_44 -> V_110 . V_111 = V_123 == 8 ? V_169 :
V_112 ;
V_44 -> V_110 . V_170 = 0 ;
V_44 -> V_110 . V_171 = 0 ;
V_44 -> V_110 . V_172 = 0 ;
V_44 -> V_110 . V_173 = 1 ;
V_44 -> V_110 . V_174 = 1 ;
V_44 -> V_110 . V_175 = 0 ;
V_44 -> V_110 . V_176 = V_177 ;
V_44 -> V_110 . V_172 = 0 ;
V_44 -> V_110 . V_178 = V_167 ;
return;
}
void F_54 ( struct V_43 * V_44 , struct V_1 * V_2 ,
T_4 V_154 , T_4 V_155 )
{
struct V_59 * V_55 = V_2 -> V_55 ;
V_44 -> V_116 = V_2 -> V_116 ;
V_44 -> V_117 . V_142 = V_55 -> V_140 ;
V_44 -> V_117 . V_143 = V_55 -> V_141 ;
V_44 -> V_117 . V_122 = V_55 -> V_122 ;
V_44 -> V_117 . V_179 = V_180 ;
V_44 -> V_117 . V_146 = 0 ;
V_44 -> V_117 . V_147 = 0 ;
V_44 -> V_117 . V_181 = V_182 ;
V_44 -> V_117 . V_141 = - 1 ;
V_44 -> V_117 . V_140 = - 1 ;
switch ( V_55 -> V_123 ) {
case 8 :
V_44 -> V_117 . V_105 . V_119 = 0 ;
V_44 -> V_117 . V_106 . V_119 = 0 ;
V_44 -> V_117 . V_107 . V_119 = 0 ;
V_44 -> V_117 . V_105 . V_118 = 8 ;
V_44 -> V_117 . V_106 . V_118 = 8 ;
V_44 -> V_117 . V_107 . V_118 = 8 ;
V_44 -> V_117 . V_120 . V_119 = 0 ;
V_44 -> V_117 . V_120 . V_118 = 0 ;
break;
case 15 :
V_44 -> V_117 . V_105 . V_119 = 10 ;
V_44 -> V_117 . V_106 . V_119 = 5 ;
V_44 -> V_117 . V_107 . V_119 = 0 ;
V_44 -> V_117 . V_105 . V_118 = 5 ;
V_44 -> V_117 . V_106 . V_118 = 5 ;
V_44 -> V_117 . V_107 . V_118 = 5 ;
V_44 -> V_117 . V_120 . V_119 = 15 ;
V_44 -> V_117 . V_120 . V_118 = 1 ;
break;
case 16 :
V_44 -> V_117 . V_105 . V_119 = 11 ;
V_44 -> V_117 . V_106 . V_119 = 5 ;
V_44 -> V_117 . V_107 . V_119 = 0 ;
V_44 -> V_117 . V_105 . V_118 = 5 ;
V_44 -> V_117 . V_106 . V_118 = 6 ;
V_44 -> V_117 . V_107 . V_118 = 5 ;
V_44 -> V_117 . V_120 . V_119 = 0 ;
break;
case 24 :
V_44 -> V_117 . V_105 . V_119 = 16 ;
V_44 -> V_117 . V_106 . V_119 = 8 ;
V_44 -> V_117 . V_107 . V_119 = 0 ;
V_44 -> V_117 . V_105 . V_118 = 8 ;
V_44 -> V_117 . V_106 . V_118 = 8 ;
V_44 -> V_117 . V_107 . V_118 = 8 ;
V_44 -> V_117 . V_120 . V_119 = 0 ;
V_44 -> V_117 . V_120 . V_118 = 0 ;
break;
case 32 :
V_44 -> V_117 . V_105 . V_119 = 16 ;
V_44 -> V_117 . V_106 . V_119 = 8 ;
V_44 -> V_117 . V_107 . V_119 = 0 ;
V_44 -> V_117 . V_105 . V_118 = 8 ;
V_44 -> V_117 . V_106 . V_118 = 8 ;
V_44 -> V_117 . V_107 . V_118 = 8 ;
V_44 -> V_117 . V_120 . V_119 = 24 ;
V_44 -> V_117 . V_120 . V_118 = 8 ;
break;
default:
break;
}
V_44 -> V_117 . V_25 = V_154 ;
V_44 -> V_117 . V_26 = V_155 ;
}
static int F_55 ( struct V_1 * V_2 ,
T_4 V_183 ,
T_4 V_184 )
{
struct V_5 * V_6 ;
int V_185 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_185 += V_6 -> V_40 -> V_186 ( V_6 , V_183 , V_184 ) ;
}
return V_185 ;
}
static struct V_158 * F_56 ( struct V_8 * V_187 , int V_140 , int V_141 )
{
struct V_158 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( F_57 ( V_17 ) > V_140 ||
F_58 ( V_17 ) > V_141 )
continue;
if ( V_17 -> type & V_188 )
return V_17 ;
}
return NULL ;
}
static bool F_59 ( struct V_8 * V_187 )
{
struct V_16 * V_19 ;
V_19 = & V_187 -> V_19 ;
return V_19 -> V_189 ;
}
static struct V_158 * F_60 ( struct V_8 * V_15 ,
int V_140 , int V_141 )
{
struct V_16 * V_19 ;
struct V_158 * V_17 = NULL ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_189 == false )
return V_17 ;
if ( V_19 -> V_29 || V_19 -> V_30 )
goto V_190;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_160 != V_19 -> V_25 ||
V_17 -> V_161 != V_19 -> V_26 )
continue;
if ( V_19 -> V_27 ) {
if ( V_17 -> V_191 != V_19 -> V_28 )
continue;
}
if ( V_19 -> V_31 ) {
if ( ! ( V_17 -> V_192 & V_193 ) )
continue;
}
return V_17 ;
}
V_190:
V_17 = F_61 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_52 ( & V_17 -> V_194 , & V_15 -> V_6 -> V_195 ) ;
return V_17 ;
}
static bool F_62 ( struct V_5 * V_6 , bool V_196 )
{
bool V_197 ;
if ( V_196 ) {
V_197 = V_6 -> V_198 == V_199 ;
} else {
V_197 = V_6 -> V_198 != V_200 ;
}
return V_197 ;
}
static void F_63 ( struct V_1 * V_2 ,
bool * V_52 )
{
bool V_201 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_62 ( V_6 , true ) ;
F_10 ( L_20 , V_6 -> V_61 . V_62 ,
V_52 [ V_7 ] ? L_21 : L_22 ) ;
V_201 |= V_52 [ V_7 ] ;
}
if ( V_201 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_62 ( V_6 , false ) ;
}
}
static bool F_64 ( struct V_1 * V_2 ,
struct V_158 * * V_195 ,
bool * V_52 , int V_140 , int V_141 )
{
int V_185 , V_7 , V_79 ;
bool V_202 = false ;
struct V_8 * V_15 ;
struct V_158 * V_203 , * V_17 ;
if ( V_2 -> V_48 > 1 )
return false ;
V_185 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_52 [ V_7 ] )
V_185 ++ ;
}
if ( V_185 <= 1 )
return false ;
V_202 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_195 [ V_7 ] = F_60 ( V_15 , V_140 , V_141 ) ;
if ( ! V_195 [ V_7 ] ) {
V_202 = false ;
break;
}
for ( V_79 = 0 ; V_79 < V_7 ; V_79 ++ ) {
if ( ! V_52 [ V_79 ] )
continue;
if ( ! F_65 ( V_195 [ V_79 ] , V_195 [ V_7 ] ) )
V_202 = false ;
}
}
if ( V_202 ) {
F_10 ( L_23 ) ;
return true ;
}
V_202 = true ;
V_203 = F_66 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_65 ( V_17 , V_203 ) )
V_195 [ V_7 ] = V_17 ;
}
if ( ! V_195 [ V_7 ] )
V_202 = false ;
}
if ( V_202 ) {
F_10 ( L_24 ) ;
return true ;
}
F_9 ( L_25 ) ;
return false ;
}
static bool F_67 ( struct V_1 * V_2 ,
struct V_158 * * V_195 ,
bool * V_52 , int V_140 , int V_141 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_15 = V_2 -> V_12 [ V_7 ] ;
if ( V_52 [ V_7 ] == false )
continue;
F_10 ( L_26 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_195 [ V_7 ] = F_60 ( V_15 , V_140 , V_141 ) ;
if ( ! V_195 [ V_7 ] ) {
F_10 ( L_27 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_195 [ V_7 ] = F_56 ( V_15 , V_140 , V_141 ) ;
}
if ( ! V_195 [ V_7 ] && ! F_14 ( & V_15 -> V_6 -> V_195 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_10 ( L_28 , V_195 [ V_7 ] ? V_195 [ V_7 ] -> V_204 :
L_29 ) ;
}
return true ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_97 * * V_205 ,
struct V_158 * * V_195 ,
int V_69 , int V_140 , int V_141 )
{
int V_60 , V_206 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_207 * V_208 ;
struct V_209 * V_210 ;
struct V_97 * V_211 ;
int V_212 , V_213 , V_214 ;
struct V_97 * * V_215 , * V_33 ;
struct V_8 * V_15 ;
if ( V_69 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_69 ] ;
V_6 = V_15 -> V_6 ;
V_205 [ V_69 ] = NULL ;
V_211 = NULL ;
V_213 = F_68 ( V_2 , V_205 , V_195 , V_69 + 1 , V_140 , V_141 ) ;
if ( V_195 [ V_69 ] == NULL )
return V_213 ;
V_215 = F_3 ( V_4 -> V_80 . V_98 *
sizeof( struct V_97 * ) , V_10 ) ;
if ( ! V_215 )
return V_213 ;
V_212 = 1 ;
if ( V_6 -> V_198 == V_199 )
V_212 ++ ;
if ( F_59 ( V_15 ) )
V_212 ++ ;
if ( F_56 ( V_15 , V_140 , V_141 ) )
V_212 ++ ;
V_208 = V_6 -> V_53 ;
V_210 = V_208 -> V_216 ( V_6 ) ;
if ( ! V_210 )
goto V_217;
for ( V_60 = 0 ; V_60 < V_2 -> V_48 ; V_60 ++ ) {
V_33 = & V_2 -> V_51 [ V_60 ] ;
if ( ( V_210 -> V_218 & ( 1 << V_60 ) ) == 0 ) {
continue;
}
for ( V_206 = 0 ; V_206 < V_69 ; V_206 ++ )
if ( V_205 [ V_206 ] == V_33 )
break;
if ( V_206 < V_69 ) {
if ( V_2 -> V_48 > 1 )
continue;
if ( ! F_65 ( V_195 [ V_206 ] , V_195 [ V_69 ] ) )
continue;
}
V_215 [ V_69 ] = V_33 ;
memcpy ( V_215 , V_205 , V_69 * sizeof( struct V_97 * ) ) ;
V_214 = V_212 + F_68 ( V_2 , V_215 , V_195 , V_69 + 1 ,
V_140 , V_141 ) ;
if ( V_214 > V_213 ) {
V_211 = V_33 ;
V_213 = V_214 ;
memcpy ( V_205 , V_215 ,
V_4 -> V_80 . V_98 *
sizeof( struct V_97 * ) ) ;
}
}
V_217:
F_4 ( V_215 ) ;
return V_213 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_97 * * V_215 ;
struct V_158 * * V_195 ;
struct V_49 * V_145 ;
bool * V_52 ;
int V_140 , V_141 ;
int V_7 , V_64 ;
F_10 ( L_30 ) ;
V_140 = V_4 -> V_80 . V_219 ;
V_141 = V_4 -> V_80 . V_220 ;
V_215 = F_35 ( V_4 -> V_80 . V_98 ,
sizeof( struct V_97 * ) , V_10 ) ;
V_195 = F_35 ( V_4 -> V_80 . V_98 ,
sizeof( struct V_158 * ) , V_10 ) ;
V_52 = F_35 ( V_4 -> V_80 . V_98 ,
sizeof( bool ) , V_10 ) ;
F_63 ( V_2 , V_52 ) ;
V_64 = F_64 ( V_2 , V_195 , V_52 , V_140 , V_141 ) ;
if ( ! V_64 ) {
V_64 = F_67 ( V_2 , V_195 , V_52 , V_140 , V_141 ) ;
if ( ! V_64 )
F_17 ( L_31 ) ;
}
F_10 ( L_32 , V_140 , V_141 ) ;
F_68 ( V_2 , V_215 , V_195 , 0 , V_140 , V_141 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_145 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_145 -> V_100 = 0 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_158 * V_17 = V_195 [ V_7 ] ;
struct V_97 * V_221 = V_215 [ V_7 ] ;
V_145 = & V_221 -> V_50 ;
if ( V_17 && V_221 ) {
F_10 ( L_33 ,
V_17 -> V_204 , V_221 -> V_50 . V_33 -> V_61 . V_62 ) ;
V_221 -> V_159 = V_17 ;
if ( V_145 -> V_17 )
F_32 ( V_4 , V_145 -> V_17 ) ;
V_145 -> V_17 = F_70 ( V_4 ,
V_221 -> V_159 ) ;
V_145 -> V_94 [ V_145 -> V_100 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
}
}
F_4 ( V_215 ) ;
F_4 ( V_195 ) ;
F_4 ( V_52 ) ;
}
bool F_71 ( struct V_1 * V_2 , int V_222 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_185 = 0 ;
F_72 ( V_2 -> V_4 ) ;
F_5 ( V_2 ) ;
V_185 = F_55 ( V_2 ,
V_4 -> V_80 . V_219 ,
V_4 -> V_80 . V_220 ) ;
if ( V_185 == 0 ) {
F_21 ( V_101 L_34 ) ;
}
F_69 ( V_2 ) ;
return F_48 ( V_2 , V_222 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_185 = 0 ;
T_3 V_219 , V_220 , V_222 ;
int V_223 = 0 , V_224 = 0 ;
struct V_32 * V_33 ;
if ( ! V_2 -> V_55 )
return 0 ;
F_27 ( & V_4 -> V_80 . V_81 ) ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_33 -> V_55 )
V_224 ++ ;
if ( V_33 -> V_55 == V_2 -> V_55 )
V_223 ++ ;
}
if ( V_223 < V_224 ) {
V_2 -> V_144 = true ;
F_29 ( & V_4 -> V_80 . V_81 ) ;
return 0 ;
}
F_10 ( L_30 ) ;
V_219 = V_2 -> V_55 -> V_140 ;
V_220 = V_2 -> V_55 -> V_141 ;
V_222 = V_2 -> V_55 -> V_122 ;
V_185 = F_55 ( V_2 , V_219 ,
V_220 ) ;
F_69 ( V_2 ) ;
F_29 ( & V_4 -> V_80 . V_81 ) ;
return F_48 ( V_2 , V_222 ) ;
}
static int T_5 F_73 ( void )
{
const char * V_204 = L_35 ;
struct V_225 * V_226 ;
F_27 ( & V_227 ) ;
V_226 = F_74 ( V_204 ) ;
F_29 ( & V_227 ) ;
if ( ! V_226 )
F_75 ( V_204 ) ;
return 0 ;
}
