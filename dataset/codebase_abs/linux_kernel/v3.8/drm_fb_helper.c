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
F_21 ( L_11 ) ;
return F_19 () ;
}
void F_22 ( void )
{
bool V_64 ;
V_64 = F_19 () ;
if ( V_64 == true )
F_17 ( L_12 ) ;
}
static void F_23 ( struct V_73 * V_74 )
{
F_22 () ;
}
static void F_24 ( int V_75 )
{
F_25 ( & V_76 ) ;
}
static void F_26 ( struct V_43 * V_44 , int V_77 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_32 * V_33 ;
struct V_5 * V_6 ;
int V_7 , V_78 ;
F_27 ( & V_4 -> V_79 . V_80 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
if ( ! V_33 -> V_52 )
continue;
for ( V_78 = 0 ; V_78 < V_2 -> V_13 ; V_78 ++ ) {
V_6 = V_2 -> V_12 [ V_78 ] -> V_6 ;
V_6 -> V_40 -> V_81 ( V_6 , V_77 ) ;
F_28 ( & V_6 -> V_61 ,
V_4 -> V_79 . V_82 , V_77 ) ;
}
}
F_29 ( & V_4 -> V_79 . V_80 ) ;
}
int F_30 ( int V_83 , struct V_43 * V_44 )
{
switch ( V_83 ) {
case V_84 :
F_26 ( V_44 , V_85 ) ;
break;
case V_86 :
F_26 ( V_44 , V_87 ) ;
break;
case V_88 :
F_26 ( V_44 , V_87 ) ;
break;
case V_89 :
F_26 ( V_44 , V_90 ) ;
break;
case V_91 :
F_26 ( V_44 , V_92 ) ;
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
F_4 ( V_34 -> V_51 [ V_7 ] . V_50 . V_93 ) ;
if ( V_34 -> V_51 [ V_7 ] . V_50 . V_17 )
F_32 ( V_34 -> V_4 , V_34 -> V_51 [ V_7 ] . V_50 . V_17 ) ;
}
F_4 ( V_34 -> V_51 ) ;
}
int F_33 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_48 , int V_94 )
{
struct V_32 * V_33 ;
int V_7 ;
V_2 -> V_4 = V_4 ;
F_34 ( & V_2 -> V_95 ) ;
V_2 -> V_51 = F_35 ( V_48 , sizeof( struct V_96 ) , V_10 ) ;
if ( ! V_2 -> V_51 )
return - V_14 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_12 = F_35 ( V_4 -> V_79 . V_97 , sizeof( struct V_8 * ) , V_10 ) ;
if ( ! V_2 -> V_12 ) {
F_4 ( V_2 -> V_51 ) ;
return - V_14 ;
}
V_2 -> V_13 = 0 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_2 -> V_51 [ V_7 ] . V_50 . V_93 =
F_35 ( V_94 ,
sizeof( struct V_5 * ) ,
V_10 ) ;
if ( ! V_2 -> V_51 [ V_7 ] . V_50 . V_93 )
goto V_98;
V_2 -> V_51 [ V_7 ] . V_50 . V_99 = 0 ;
}
V_7 = 0 ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
V_2 -> V_51 [ V_7 ] . V_50 . V_33 = V_33 ;
V_7 ++ ;
}
return 0 ;
V_98:
F_31 ( V_2 ) ;
return - V_14 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! F_14 ( & V_2 -> V_95 ) ) {
F_37 ( & V_2 -> V_95 ) ;
if ( F_14 ( & V_47 ) ) {
F_38 ( L_13 ) ;
F_39 ( & V_100 ,
& V_101 ) ;
F_40 ( 'v' , & V_102 ) ;
}
}
F_31 ( V_2 ) ;
}
static int F_41 ( struct V_32 * V_33 , T_2 V_103 , T_2 V_104 ,
T_2 V_105 , T_2 V_106 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_107 ;
if ( V_44 -> V_108 . V_109 == V_110 ) {
T_3 * V_111 ;
T_3 V_112 ;
if ( V_106 > 16 )
return - V_113 ;
V_111 = ( T_3 * ) V_44 -> V_114 ;
V_103 >>= ( 16 - V_44 -> V_115 . V_103 . V_116 ) ;
V_104 >>= ( 16 - V_44 -> V_115 . V_104 . V_116 ) ;
V_105 >>= ( 16 - V_44 -> V_115 . V_105 . V_116 ) ;
V_112 = ( V_103 << V_44 -> V_115 . V_103 . V_117 ) |
( V_104 << V_44 -> V_115 . V_104 . V_117 ) |
( V_105 << V_44 -> V_115 . V_105 . V_117 ) ;
if ( V_44 -> V_115 . V_118 . V_116 > 0 ) {
T_3 V_119 = ( 1 << V_44 -> V_115 . V_118 . V_116 ) - 1 ;
V_119 <<= V_44 -> V_115 . V_118 . V_117 ;
V_112 |= V_119 ;
}
V_111 [ V_106 ] = V_112 ;
return 0 ;
}
V_107 = V_106 ;
if ( V_55 -> V_120 == 16 ) {
V_107 = V_106 << 3 ;
if ( V_55 -> V_121 == 16 && V_106 > 63 )
return - V_113 ;
if ( V_55 -> V_121 == 15 && V_106 > 31 )
return - V_113 ;
if ( V_55 -> V_121 == 16 ) {
T_2 V_122 , V_123 , V_124 ;
int V_7 ;
if ( V_106 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_103 ,
V_104 , V_105 , V_107 + V_7 ) ;
}
V_2 -> V_40 -> V_41 ( V_33 , & V_122 ,
& V_123 , & V_124 ,
V_107 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_40 -> V_42 ( V_33 , V_122 ,
V_104 , V_124 ,
( V_107 >> 1 ) + V_7 ) ;
}
}
if ( V_55 -> V_121 != 16 )
V_2 -> V_40 -> V_42 ( V_33 , V_103 , V_104 , V_105 , V_107 ) ;
return 0 ;
}
int F_42 ( struct V_125 * V_126 , struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_46 * V_127 ;
T_2 * V_103 , * V_104 , * V_105 , * V_118 ;
struct V_32 * V_33 ;
int V_7 , V_78 , V_128 = 0 ;
int V_129 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_127 = V_33 -> V_53 ;
V_103 = V_126 -> V_103 ;
V_104 = V_126 -> V_104 ;
V_105 = V_126 -> V_105 ;
V_118 = V_126 -> V_118 ;
V_129 = V_126 -> V_129 ;
for ( V_78 = 0 ; V_78 < V_126 -> V_130 ; V_78 ++ ) {
T_2 V_131 , V_132 , V_133 , V_134 = 0xffff ;
V_131 = * V_103 ++ ;
V_132 = * V_104 ++ ;
V_133 = * V_105 ++ ;
if ( V_118 )
V_134 = * V_118 ++ ;
V_128 = F_41 ( V_33 , V_131 , V_132 , V_133 , V_129 ++ , V_44 ) ;
if ( V_128 )
return V_128 ;
}
V_127 -> V_135 ( V_33 ) ;
}
return V_128 ;
}
int F_43 ( struct V_136 * V_115 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_59 * V_55 = V_2 -> V_55 ;
int V_121 ;
if ( V_115 -> V_137 != 0 || F_44 () )
return - V_113 ;
if ( V_115 -> V_120 > V_55 -> V_120 ||
V_115 -> V_25 > V_55 -> V_138 || V_115 -> V_26 > V_55 -> V_139 ||
V_115 -> V_140 > V_55 -> V_138 || V_115 -> V_141 > V_55 -> V_139 ) {
F_45 ( L_14
L_15 ,
V_115 -> V_25 , V_115 -> V_26 , V_115 -> V_120 ,
V_115 -> V_140 , V_115 -> V_141 ,
V_55 -> V_138 , V_55 -> V_139 , V_55 -> V_120 ) ;
return - V_113 ;
}
switch ( V_115 -> V_120 ) {
case 16 :
V_121 = ( V_115 -> V_104 . V_116 == 6 ) ? 16 : 15 ;
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
V_115 -> V_103 . V_117 = 0 ;
V_115 -> V_104 . V_117 = 0 ;
V_115 -> V_105 . V_117 = 0 ;
V_115 -> V_103 . V_116 = 8 ;
V_115 -> V_104 . V_116 = 8 ;
V_115 -> V_105 . V_116 = 8 ;
V_115 -> V_118 . V_116 = 0 ;
V_115 -> V_118 . V_117 = 0 ;
break;
case 15 :
V_115 -> V_103 . V_117 = 10 ;
V_115 -> V_104 . V_117 = 5 ;
V_115 -> V_105 . V_117 = 0 ;
V_115 -> V_103 . V_116 = 5 ;
V_115 -> V_104 . V_116 = 5 ;
V_115 -> V_105 . V_116 = 5 ;
V_115 -> V_118 . V_116 = 1 ;
V_115 -> V_118 . V_117 = 15 ;
break;
case 16 :
V_115 -> V_103 . V_117 = 11 ;
V_115 -> V_104 . V_117 = 5 ;
V_115 -> V_105 . V_117 = 0 ;
V_115 -> V_103 . V_116 = 5 ;
V_115 -> V_104 . V_116 = 6 ;
V_115 -> V_105 . V_116 = 5 ;
V_115 -> V_118 . V_116 = 0 ;
V_115 -> V_118 . V_117 = 0 ;
break;
case 24 :
V_115 -> V_103 . V_117 = 16 ;
V_115 -> V_104 . V_117 = 8 ;
V_115 -> V_105 . V_117 = 0 ;
V_115 -> V_103 . V_116 = 8 ;
V_115 -> V_104 . V_116 = 8 ;
V_115 -> V_105 . V_116 = 8 ;
V_115 -> V_118 . V_116 = 0 ;
V_115 -> V_118 . V_117 = 0 ;
break;
case 32 :
V_115 -> V_103 . V_117 = 16 ;
V_115 -> V_104 . V_117 = 8 ;
V_115 -> V_105 . V_117 = 0 ;
V_115 -> V_103 . V_116 = 8 ;
V_115 -> V_104 . V_116 = 8 ;
V_115 -> V_105 . V_116 = 8 ;
V_115 -> V_118 . V_116 = 8 ;
V_115 -> V_118 . V_117 = 24 ;
break;
default:
return - V_113 ;
}
return 0 ;
}
int F_46 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_136 * V_115 = & V_44 -> V_115 ;
struct V_32 * V_33 ;
int V_64 ;
int V_7 ;
if ( V_115 -> V_137 != 0 ) {
F_17 ( L_16 ) ;
return - V_113 ;
}
F_27 ( & V_4 -> V_79 . V_80 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_64 = V_33 -> V_40 -> V_65 ( & V_2 -> V_51 [ V_7 ] . V_50 ) ;
if ( V_64 ) {
F_29 ( & V_4 -> V_79 . V_80 ) ;
return V_64 ;
}
}
F_29 ( & V_4 -> V_79 . V_80 ) ;
if ( V_2 -> V_142 ) {
V_2 -> V_142 = false ;
F_47 ( V_2 ) ;
}
return 0 ;
}
int F_48 ( struct V_136 * V_115 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_45 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_143 ;
struct V_32 * V_33 ;
int V_64 = 0 ;
int V_7 ;
F_27 ( & V_4 -> V_79 . V_80 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_33 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 ;
V_143 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_143 -> V_56 = V_115 -> V_144 ;
V_143 -> V_57 = V_115 -> V_145 ;
if ( V_143 -> V_99 ) {
V_64 = V_33 -> V_40 -> V_65 ( V_143 ) ;
if ( ! V_64 ) {
V_44 -> V_115 . V_144 = V_115 -> V_144 ;
V_44 -> V_115 . V_145 = V_115 -> V_145 ;
}
}
}
F_29 ( & V_4 -> V_79 . V_80 ) ;
return V_64 ;
}
int F_49 ( struct V_1 * V_2 ,
int V_146 )
{
int V_147 = 0 ;
int V_48 = 0 ;
int V_7 ;
struct V_43 * V_44 ;
struct V_148 V_149 ;
int V_39 = 0 ;
memset ( & V_149 , 0 , sizeof( struct V_148 ) ) ;
V_149 . V_150 = 24 ;
V_149 . V_151 = 32 ;
V_149 . V_152 = ( unsigned ) - 1 ;
V_149 . V_153 = ( unsigned ) - 1 ;
if ( V_146 != V_149 . V_151 )
V_149 . V_150 = V_149 . V_151 = V_146 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_8 * V_15 = V_2 -> V_12 [ V_7 ] ;
struct V_16 * V_19 ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_154 ) {
switch ( V_19 -> V_155 ) {
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
V_48 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
struct V_156 * V_157 ;
V_157 = V_2 -> V_51 [ V_7 ] . V_157 ;
if ( V_157 ) {
if ( V_39 == 0 )
V_39 = V_2 -> V_51 [ V_7 ] . V_50 . V_33 -> V_39 ;
if ( V_157 -> V_158 < V_149 . V_152 )
V_149 . V_152 = V_157 -> V_158 ;
if ( V_157 -> V_159 < V_149 . V_153 )
V_149 . V_153 = V_157 -> V_159 ;
if ( V_157 -> V_158 > V_149 . V_160 )
V_149 . V_160 = V_157 -> V_158 ;
if ( V_157 -> V_159 > V_149 . V_161 )
V_149 . V_161 = V_157 -> V_159 ;
V_48 ++ ;
}
}
if ( V_48 == 0 || V_149 . V_152 == - 1 || V_149 . V_153 == - 1 ) {
F_9 ( L_17 ) ;
V_149 . V_152 = V_149 . V_160 = 1024 ;
V_149 . V_153 = V_149 . V_161 = 768 ;
}
V_147 = (* V_2 -> V_40 -> V_162 )( V_2 , & V_149 ) ;
if ( V_147 < 0 )
return V_147 ;
V_44 = V_2 -> V_163 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ )
V_2 -> V_51 [ V_7 ] . V_50 . V_55 = V_2 -> V_55 ;
if ( V_147 ) {
V_44 -> V_115 . V_137 = 0 ;
if ( F_50 ( V_44 ) < 0 )
return - V_113 ;
F_51 ( V_2 -> V_4 -> V_4 , L_18 ,
V_44 -> V_164 , V_44 -> V_108 . V_62 ) ;
} else {
F_46 ( V_44 ) ;
}
if ( F_14 ( & V_47 ) ) {
F_51 ( V_2 -> V_4 -> V_4 , L_19 ) ;
F_52 ( & V_100 ,
& V_101 ) ;
F_53 ( 'v' , & V_102 ) ;
}
if ( V_147 )
F_54 ( & V_2 -> V_95 , & V_47 ) ;
return 0 ;
}
void F_55 ( struct V_43 * V_44 , T_4 V_165 ,
T_4 V_121 )
{
V_44 -> V_108 . type = V_166 ;
V_44 -> V_108 . V_109 = V_121 == 8 ? V_167 :
V_110 ;
V_44 -> V_108 . V_168 = 0 ;
V_44 -> V_108 . V_169 = 0 ;
V_44 -> V_108 . V_170 = 0 ;
V_44 -> V_108 . V_171 = 1 ;
V_44 -> V_108 . V_172 = 1 ;
V_44 -> V_108 . V_173 = 0 ;
V_44 -> V_108 . V_174 = V_175 ;
V_44 -> V_108 . V_170 = 0 ;
V_44 -> V_108 . V_176 = V_165 ;
return;
}
void F_56 ( struct V_43 * V_44 , struct V_1 * V_2 ,
T_4 V_152 , T_4 V_153 )
{
struct V_59 * V_55 = V_2 -> V_55 ;
V_44 -> V_114 = V_2 -> V_114 ;
V_44 -> V_115 . V_140 = V_55 -> V_138 ;
V_44 -> V_115 . V_141 = V_55 -> V_139 ;
V_44 -> V_115 . V_120 = V_55 -> V_120 ;
V_44 -> V_115 . V_177 = V_178 ;
V_44 -> V_115 . V_144 = 0 ;
V_44 -> V_115 . V_145 = 0 ;
V_44 -> V_115 . V_179 = V_180 ;
V_44 -> V_115 . V_139 = - 1 ;
V_44 -> V_115 . V_138 = - 1 ;
switch ( V_55 -> V_121 ) {
case 8 :
V_44 -> V_115 . V_103 . V_117 = 0 ;
V_44 -> V_115 . V_104 . V_117 = 0 ;
V_44 -> V_115 . V_105 . V_117 = 0 ;
V_44 -> V_115 . V_103 . V_116 = 8 ;
V_44 -> V_115 . V_104 . V_116 = 8 ;
V_44 -> V_115 . V_105 . V_116 = 8 ;
V_44 -> V_115 . V_118 . V_117 = 0 ;
V_44 -> V_115 . V_118 . V_116 = 0 ;
break;
case 15 :
V_44 -> V_115 . V_103 . V_117 = 10 ;
V_44 -> V_115 . V_104 . V_117 = 5 ;
V_44 -> V_115 . V_105 . V_117 = 0 ;
V_44 -> V_115 . V_103 . V_116 = 5 ;
V_44 -> V_115 . V_104 . V_116 = 5 ;
V_44 -> V_115 . V_105 . V_116 = 5 ;
V_44 -> V_115 . V_118 . V_117 = 15 ;
V_44 -> V_115 . V_118 . V_116 = 1 ;
break;
case 16 :
V_44 -> V_115 . V_103 . V_117 = 11 ;
V_44 -> V_115 . V_104 . V_117 = 5 ;
V_44 -> V_115 . V_105 . V_117 = 0 ;
V_44 -> V_115 . V_103 . V_116 = 5 ;
V_44 -> V_115 . V_104 . V_116 = 6 ;
V_44 -> V_115 . V_105 . V_116 = 5 ;
V_44 -> V_115 . V_118 . V_117 = 0 ;
break;
case 24 :
V_44 -> V_115 . V_103 . V_117 = 16 ;
V_44 -> V_115 . V_104 . V_117 = 8 ;
V_44 -> V_115 . V_105 . V_117 = 0 ;
V_44 -> V_115 . V_103 . V_116 = 8 ;
V_44 -> V_115 . V_104 . V_116 = 8 ;
V_44 -> V_115 . V_105 . V_116 = 8 ;
V_44 -> V_115 . V_118 . V_117 = 0 ;
V_44 -> V_115 . V_118 . V_116 = 0 ;
break;
case 32 :
V_44 -> V_115 . V_103 . V_117 = 16 ;
V_44 -> V_115 . V_104 . V_117 = 8 ;
V_44 -> V_115 . V_105 . V_117 = 0 ;
V_44 -> V_115 . V_103 . V_116 = 8 ;
V_44 -> V_115 . V_104 . V_116 = 8 ;
V_44 -> V_115 . V_105 . V_116 = 8 ;
V_44 -> V_115 . V_118 . V_117 = 24 ;
V_44 -> V_115 . V_118 . V_116 = 8 ;
break;
default:
break;
}
V_44 -> V_115 . V_25 = V_152 ;
V_44 -> V_115 . V_26 = V_153 ;
}
static int F_57 ( struct V_1 * V_2 ,
T_4 V_181 ,
T_4 V_182 )
{
struct V_5 * V_6 ;
int V_183 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_183 += V_6 -> V_40 -> V_184 ( V_6 , V_181 , V_182 ) ;
}
return V_183 ;
}
static struct V_156 * F_58 ( struct V_8 * V_185 , int V_138 , int V_139 )
{
struct V_156 * V_17 ;
F_2 (mode, &fb_connector->connector->modes, head) {
if ( F_59 ( V_17 ) > V_138 ||
F_60 ( V_17 ) > V_139 )
continue;
if ( V_17 -> type & V_186 )
return V_17 ;
}
return NULL ;
}
static bool F_61 ( struct V_8 * V_185 )
{
struct V_16 * V_19 ;
V_19 = & V_185 -> V_19 ;
return V_19 -> V_187 ;
}
static struct V_156 * F_62 ( struct V_8 * V_15 ,
int V_138 , int V_139 )
{
struct V_16 * V_19 ;
struct V_156 * V_17 = NULL ;
V_19 = & V_15 -> V_19 ;
if ( V_19 -> V_187 == false )
return V_17 ;
if ( V_19 -> V_29 || V_19 -> V_30 )
goto V_188;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_17 -> V_158 != V_19 -> V_25 ||
V_17 -> V_159 != V_19 -> V_26 )
continue;
if ( V_19 -> V_27 ) {
if ( V_17 -> V_189 != V_19 -> V_28 )
continue;
}
if ( V_19 -> V_31 ) {
if ( ! ( V_17 -> V_190 & V_191 ) )
continue;
}
return V_17 ;
}
V_188:
V_17 = F_63 ( V_15 -> V_6 -> V_4 ,
V_19 ) ;
F_54 ( & V_17 -> V_192 , & V_15 -> V_6 -> V_193 ) ;
return V_17 ;
}
static bool F_64 ( struct V_5 * V_6 , bool V_194 )
{
bool V_195 ;
if ( V_194 )
V_195 = V_6 -> V_196 == V_197 ;
else
V_195 = V_6 -> V_196 != V_198 ;
return V_195 ;
}
static void F_65 ( struct V_1 * V_2 ,
bool * V_52 )
{
bool V_199 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_64 ( V_6 , true ) ;
F_10 ( L_20 , V_6 -> V_61 . V_62 ,
V_52 [ V_7 ] ? L_21 : L_22 ) ;
V_199 |= V_52 [ V_7 ] ;
}
if ( V_199 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_6 = V_2 -> V_12 [ V_7 ] -> V_6 ;
V_52 [ V_7 ] = F_64 ( V_6 , false ) ;
}
}
static bool F_66 ( struct V_1 * V_2 ,
struct V_156 * * V_193 ,
bool * V_52 , int V_138 , int V_139 )
{
int V_183 , V_7 , V_78 ;
bool V_200 = false ;
struct V_8 * V_15 ;
struct V_156 * V_201 , * V_17 ;
if ( V_2 -> V_48 > 1 )
return false ;
V_183 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( V_52 [ V_7 ] )
V_183 ++ ;
}
if ( V_183 <= 1 )
return false ;
V_200 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
V_193 [ V_7 ] = F_62 ( V_15 , V_138 , V_139 ) ;
if ( ! V_193 [ V_7 ] ) {
V_200 = false ;
break;
}
for ( V_78 = 0 ; V_78 < V_7 ; V_78 ++ ) {
if ( ! V_52 [ V_78 ] )
continue;
if ( ! F_67 ( V_193 [ V_78 ] , V_193 [ V_7 ] ) )
V_200 = false ;
}
}
if ( V_200 ) {
F_10 ( L_23 ) ;
return true ;
}
V_200 = true ;
V_201 = F_68 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
if ( ! V_52 [ V_7 ] )
continue;
V_15 = V_2 -> V_12 [ V_7 ] ;
F_2 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_67 ( V_17 , V_201 ) )
V_193 [ V_7 ] = V_17 ;
}
if ( ! V_193 [ V_7 ] )
V_200 = false ;
}
if ( V_200 ) {
F_10 ( L_24 ) ;
return true ;
}
F_9 ( L_25 ) ;
return false ;
}
static bool F_69 ( struct V_1 * V_2 ,
struct V_156 * * V_193 ,
bool * V_52 , int V_138 , int V_139 )
{
struct V_8 * V_15 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
V_15 = V_2 -> V_12 [ V_7 ] ;
if ( V_52 [ V_7 ] == false )
continue;
F_10 ( L_26 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_193 [ V_7 ] = F_62 ( V_15 , V_138 , V_139 ) ;
if ( ! V_193 [ V_7 ] ) {
F_10 ( L_27 ,
V_15 -> V_6 -> V_61 . V_62 ) ;
V_193 [ V_7 ] = F_58 ( V_15 , V_138 , V_139 ) ;
}
if ( ! V_193 [ V_7 ] && ! F_14 ( & V_15 -> V_6 -> V_193 ) ) {
F_2 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_10 ( L_28 , V_193 [ V_7 ] ? V_193 [ V_7 ] -> V_202 :
L_29 ) ;
}
return true ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_96 * * V_203 ,
struct V_156 * * V_193 ,
int V_69 , int V_138 , int V_139 )
{
int V_60 , V_204 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_205 * V_206 ;
struct V_207 * V_208 ;
struct V_96 * V_209 ;
int V_210 , V_211 , V_212 ;
struct V_96 * * V_213 , * V_33 ;
struct V_8 * V_15 ;
if ( V_69 == V_2 -> V_13 )
return 0 ;
V_15 = V_2 -> V_12 [ V_69 ] ;
V_6 = V_15 -> V_6 ;
V_203 [ V_69 ] = NULL ;
V_209 = NULL ;
V_211 = F_70 ( V_2 , V_203 , V_193 , V_69 + 1 , V_138 , V_139 ) ;
if ( V_193 [ V_69 ] == NULL )
return V_211 ;
V_213 = F_3 ( V_4 -> V_79 . V_97 *
sizeof( struct V_96 * ) , V_10 ) ;
if ( ! V_213 )
return V_211 ;
V_210 = 1 ;
if ( V_6 -> V_196 == V_197 )
V_210 ++ ;
if ( F_61 ( V_15 ) )
V_210 ++ ;
if ( F_58 ( V_15 , V_138 , V_139 ) )
V_210 ++ ;
V_206 = V_6 -> V_53 ;
V_208 = V_206 -> V_214 ( V_6 ) ;
if ( ! V_208 )
goto V_215;
for ( V_60 = 0 ; V_60 < V_2 -> V_48 ; V_60 ++ ) {
V_33 = & V_2 -> V_51 [ V_60 ] ;
if ( ( V_208 -> V_216 & ( 1 << V_60 ) ) == 0 )
continue;
for ( V_204 = 0 ; V_204 < V_69 ; V_204 ++ )
if ( V_203 [ V_204 ] == V_33 )
break;
if ( V_204 < V_69 ) {
if ( V_2 -> V_48 > 1 )
continue;
if ( ! F_67 ( V_193 [ V_204 ] , V_193 [ V_69 ] ) )
continue;
}
V_213 [ V_69 ] = V_33 ;
memcpy ( V_213 , V_203 , V_69 * sizeof( struct V_96 * ) ) ;
V_212 = V_210 + F_70 ( V_2 , V_213 , V_193 , V_69 + 1 ,
V_138 , V_139 ) ;
if ( V_212 > V_211 ) {
V_209 = V_33 ;
V_211 = V_212 ;
memcpy ( V_203 , V_213 ,
V_4 -> V_79 . V_97 *
sizeof( struct V_96 * ) ) ;
}
}
V_215:
F_4 ( V_213 ) ;
return V_211 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_96 * * V_213 ;
struct V_156 * * V_193 ;
struct V_49 * V_143 ;
bool * V_52 ;
int V_138 , V_139 ;
int V_7 , V_64 ;
F_10 ( L_30 ) ;
V_138 = V_4 -> V_79 . V_217 ;
V_139 = V_4 -> V_79 . V_218 ;
V_213 = F_35 ( V_4 -> V_79 . V_97 ,
sizeof( struct V_96 * ) , V_10 ) ;
V_193 = F_35 ( V_4 -> V_79 . V_97 ,
sizeof( struct V_156 * ) , V_10 ) ;
V_52 = F_35 ( V_4 -> V_79 . V_97 ,
sizeof( bool ) , V_10 ) ;
if ( ! V_213 || ! V_193 || ! V_52 ) {
F_17 ( L_31 ) ;
goto V_215;
}
F_65 ( V_2 , V_52 ) ;
V_64 = F_66 ( V_2 , V_193 , V_52 , V_138 , V_139 ) ;
if ( ! V_64 ) {
V_64 = F_69 ( V_2 , V_193 , V_52 , V_138 , V_139 ) ;
if ( ! V_64 )
F_17 ( L_32 ) ;
}
F_10 ( L_33 , V_138 , V_139 ) ;
F_70 ( V_2 , V_213 , V_193 , 0 , V_138 , V_139 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_48 ; V_7 ++ ) {
V_143 = & V_2 -> V_51 [ V_7 ] . V_50 ;
V_143 -> V_99 = 0 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_13 ; V_7 ++ ) {
struct V_156 * V_17 = V_193 [ V_7 ] ;
struct V_96 * V_219 = V_213 [ V_7 ] ;
V_143 = & V_219 -> V_50 ;
if ( V_17 && V_219 ) {
F_10 ( L_34 ,
V_17 -> V_202 , V_219 -> V_50 . V_33 -> V_61 . V_62 ) ;
V_219 -> V_157 = V_17 ;
if ( V_143 -> V_17 )
F_32 ( V_4 , V_143 -> V_17 ) ;
V_143 -> V_17 = F_72 ( V_4 ,
V_219 -> V_157 ) ;
V_143 -> V_93 [ V_143 -> V_99 ++ ] = V_2 -> V_12 [ V_7 ] -> V_6 ;
}
}
V_215:
F_4 ( V_213 ) ;
F_4 ( V_193 ) ;
F_4 ( V_52 ) ;
}
bool F_73 ( struct V_1 * V_2 , int V_220 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_183 = 0 ;
F_74 ( V_2 -> V_4 ) ;
F_5 ( V_2 ) ;
V_183 = F_57 ( V_2 ,
V_4 -> V_79 . V_217 ,
V_4 -> V_79 . V_218 ) ;
if ( V_183 == 0 )
F_51 ( V_2 -> V_4 -> V_4 , L_35 ) ;
F_71 ( V_2 ) ;
return F_49 ( V_2 , V_220 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_183 = 0 ;
T_3 V_217 , V_218 , V_220 ;
int V_221 = 0 , V_222 = 0 ;
struct V_32 * V_33 ;
if ( ! V_2 -> V_55 )
return 0 ;
F_27 ( & V_4 -> V_79 . V_80 ) ;
F_2 (crtc, &dev->mode_config.crtc_list, head) {
if ( V_33 -> V_55 )
V_222 ++ ;
if ( V_33 -> V_55 == V_2 -> V_55 )
V_221 ++ ;
}
if ( V_221 < V_222 ) {
V_2 -> V_142 = true ;
F_29 ( & V_4 -> V_79 . V_80 ) ;
return 0 ;
}
F_10 ( L_30 ) ;
V_217 = V_2 -> V_55 -> V_138 ;
V_218 = V_2 -> V_55 -> V_139 ;
V_220 = V_2 -> V_55 -> V_120 ;
V_183 = F_57 ( V_2 , V_217 ,
V_218 ) ;
F_71 ( V_2 ) ;
F_29 ( & V_4 -> V_79 . V_80 ) ;
return F_49 ( V_2 , V_220 ) ;
}
static int T_5 F_75 ( void )
{
const char * V_202 = L_36 ;
struct V_223 * V_224 ;
F_27 ( & V_225 ) ;
V_224 = F_76 ( V_202 ) ;
F_29 ( & V_225 ) ;
if ( ! V_224 )
F_77 ( V_202 ) ;
return 0 ;
}
