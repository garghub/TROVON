int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_7 ;
F_2 ( & V_4 -> V_8 . V_9 ) ;
F_3 (connector, dev) {
struct V_10 * V_11 ;
V_11 = F_4 ( sizeof( struct V_10 ) , V_12 ) ;
if ( ! V_11 )
goto V_13;
V_11 -> V_6 = V_6 ;
V_2 -> V_14 [ V_2 -> V_15 ++ ] = V_11 ;
}
F_5 ( & V_4 -> V_8 . V_9 ) ;
return 0 ;
V_13:
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
F_6 ( V_2 -> V_14 [ V_7 ] ) ;
V_2 -> V_14 [ V_7 ] = NULL ;
}
V_2 -> V_15 = 0 ;
F_5 ( & V_4 -> V_8 . V_9 ) ;
return - V_16 ;
}
int F_7 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_10 * * V_17 ;
struct V_10 * V_11 ;
F_8 ( ! F_9 ( & V_2 -> V_4 -> V_8 . V_9 ) ) ;
if ( V_2 -> V_15 + 1 > V_2 -> V_18 ) {
V_17 = F_10 ( V_2 -> V_14 , sizeof( struct V_10 * ) * ( V_2 -> V_15 + 1 ) , V_12 ) ;
if ( ! V_17 )
return - V_16 ;
V_2 -> V_18 = V_2 -> V_15 + 1 ;
V_2 -> V_14 = V_17 ;
}
V_11 = F_4 ( sizeof( struct V_10 ) , V_12 ) ;
if ( ! V_11 )
return - V_16 ;
V_11 -> V_6 = V_6 ;
V_2 -> V_14 [ V_2 -> V_15 ++ ] = V_11 ;
return 0 ;
}
static void F_11 ( struct V_19 * V_20 ,
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
if ( V_20 -> V_22 == 0 ) {
V_20 -> V_24 = NULL ;
F_12 ( V_6 -> V_4 , V_20 -> V_25 ) ;
V_20 -> V_25 = NULL ;
}
}
int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 ;
int V_7 , V_21 ;
F_8 ( ! F_9 ( & V_2 -> V_4 -> V_8 . V_9 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
if ( V_2 -> V_14 [ V_7 ] -> V_6 == V_6 )
break;
}
if ( V_7 == V_2 -> V_15 )
return - V_26 ;
V_11 = V_2 -> V_14 [ V_7 ] ;
for ( V_21 = V_7 + 1 ; V_21 < V_2 -> V_15 ; V_21 ++ ) {
V_2 -> V_14 [ V_21 - 1 ] = V_2 -> V_14 [ V_21 ] ;
}
V_2 -> V_15 -- ;
F_6 ( V_11 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ )
F_11 ( & V_2 -> V_28 [ V_7 ] . V_29 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_30 * V_31 , struct V_1 * V_32 )
{
T_1 * V_33 , * V_34 , * V_35 ;
int V_7 ;
if ( V_32 -> V_36 -> V_37 == NULL )
return;
V_33 = V_31 -> V_38 ;
V_34 = V_33 + V_31 -> V_39 ;
V_35 = V_34 + V_31 -> V_39 ;
for ( V_7 = 0 ; V_7 < V_31 -> V_39 ; V_7 ++ )
V_32 -> V_36 -> V_37 ( V_31 , & V_33 [ V_7 ] , & V_34 [ V_7 ] , & V_35 [ V_7 ] , V_7 ) ;
}
static void F_15 ( struct V_30 * V_31 )
{
T_1 * V_33 , * V_34 , * V_35 ;
if ( V_31 -> V_36 -> V_40 == NULL )
return;
V_33 = V_31 -> V_38 ;
V_34 = V_33 + V_31 -> V_39 ;
V_35 = V_34 + V_31 -> V_39 ;
V_31 -> V_36 -> V_40 ( V_31 , V_33 , V_34 , V_35 , 0 , V_31 -> V_39 ) ;
}
int F_16 ( struct V_41 * V_42 )
{
struct V_1 * V_32 = V_42 -> V_43 ;
const struct V_44 * V_36 ;
int V_7 ;
F_17 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_32 -> V_27 ; V_7 ++ ) {
struct V_19 * V_29 =
& V_32 -> V_28 [ V_7 ] . V_29 ;
if ( ! V_29 -> V_31 -> V_45 )
continue;
V_36 = V_29 -> V_31 -> V_46 ;
F_14 ( V_29 -> V_31 , V_32 ) ;
V_36 -> V_47 ( V_29 -> V_31 ,
V_29 -> V_24 ,
V_29 -> V_48 ,
V_29 -> V_49 ,
V_50 ) ;
}
}
return 0 ;
}
static struct V_51 * F_18 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = V_31 -> V_4 ;
struct V_30 * V_52 ;
F_19 (c, dev) {
if ( V_31 -> V_53 . V_54 == V_52 -> V_53 . V_54 )
return V_52 -> V_55 -> V_24 ;
}
return NULL ;
}
int F_20 ( struct V_41 * V_42 )
{
struct V_1 * V_32 = V_42 -> V_43 ;
struct V_30 * V_31 ;
const struct V_44 * V_36 ;
struct V_51 * V_24 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_32 -> V_27 ; V_7 ++ ) {
struct V_19 * V_29 = & V_32 -> V_28 [ V_7 ] . V_29 ;
V_31 = V_29 -> V_31 ;
V_36 = V_31 -> V_46 ;
V_24 = F_18 ( V_31 ) ;
if ( ! V_31 -> V_45 )
continue;
if ( ! V_24 ) {
F_21 ( L_1 ) ;
continue;
}
F_15 ( V_29 -> V_31 ) ;
V_36 -> V_47 ( V_29 -> V_31 , V_24 , V_31 -> V_48 ,
V_31 -> V_49 , V_56 ) ;
}
return 0 ;
}
static bool F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_57 * V_58 ;
bool error = false ;
int V_7 ;
F_23 ( V_4 ) ;
F_24 (plane, dev) {
if ( V_58 -> type != V_59 )
F_25 ( V_58 ) ;
if ( V_4 -> V_8 . V_60 ) {
F_26 ( V_58 ,
V_4 -> V_8 . V_60 ,
F_27 ( V_61 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
struct V_19 * V_29 = & V_2 -> V_28 [ V_7 ] . V_29 ;
struct V_30 * V_31 = V_29 -> V_31 ;
int V_62 ;
if ( V_31 -> V_36 -> V_63 ) {
V_62 = V_31 -> V_36 -> V_63 ( V_31 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_62 )
error = true ;
} else if ( V_31 -> V_36 -> V_64 ) {
V_62 = V_31 -> V_36 -> V_64 ( V_31 , NULL , 0 , 0 , 0 ) ;
if ( V_62 )
error = true ;
}
V_62 = F_28 ( V_29 ) ;
if ( V_62 )
error = true ;
}
return error ;
}
bool F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_62 ;
bool V_65 = false ;
F_30 ( V_4 ) ;
V_62 = F_22 ( V_2 ) ;
V_65 = V_2 -> V_66 ;
if ( V_65 )
V_2 -> V_66 = false ;
F_31 ( V_4 ) ;
if ( V_65 )
F_32 ( V_2 ) ;
return V_62 ;
}
static bool F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_30 * V_31 ;
int V_67 = 0 , V_68 = 0 ;
if ( V_4 -> V_55 -> V_69 )
return false ;
F_19 (crtc, dev) {
if ( V_31 -> V_55 -> V_24 )
V_68 ++ ;
if ( V_31 -> V_55 -> V_24 == V_2 -> V_24 )
V_67 ++ ;
}
if ( V_67 < V_68 )
return false ;
return true ;
}
static bool F_34 ( void )
{
bool V_62 , error = false ;
struct V_1 * V_32 ;
if ( F_35 ( & V_70 ) )
return false ;
F_17 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_32 -> V_4 ;
if ( V_4 -> V_71 == V_72 )
continue;
F_30 ( V_4 ) ;
V_62 = F_22 ( V_32 ) ;
if ( V_62 )
error = true ;
F_31 ( V_4 ) ;
}
return error ;
}
static void F_36 ( struct V_73 * V_74 )
{
bool V_62 ;
V_62 = F_34 () ;
if ( V_62 == true )
F_21 ( L_2 ) ;
}
static void F_37 ( int V_75 )
{
F_38 ( & V_76 ) ;
}
static void F_39 ( struct V_41 * V_42 , int V_77 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_30 * V_31 ;
struct V_5 * V_6 ;
int V_7 , V_21 ;
F_30 ( V_4 ) ;
if ( ! F_33 ( V_2 ) ) {
F_31 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
V_31 = V_2 -> V_28 [ V_7 ] . V_29 . V_31 ;
if ( ! V_31 -> V_45 )
continue;
for ( V_21 = 0 ; V_21 < V_2 -> V_15 ; V_21 ++ ) {
V_6 = V_2 -> V_14 [ V_21 ] -> V_6 ;
V_6 -> V_36 -> V_78 ( V_6 , V_77 ) ;
F_40 ( & V_6 -> V_53 ,
V_4 -> V_8 . V_79 , V_77 ) ;
}
}
F_31 ( V_4 ) ;
}
int F_41 ( int V_80 , struct V_41 * V_42 )
{
if ( V_81 )
return - V_82 ;
switch ( V_80 ) {
case V_83 :
F_39 ( V_42 , V_84 ) ;
break;
case V_85 :
F_39 ( V_42 , V_86 ) ;
break;
case V_87 :
F_39 ( V_42 , V_86 ) ;
break;
case V_88 :
F_39 ( V_42 , V_89 ) ;
break;
case V_90 :
F_39 ( V_42 , V_91 ) ;
break;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_32 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_32 -> V_15 ; V_7 ++ )
F_6 ( V_32 -> V_14 [ V_7 ] ) ;
F_6 ( V_32 -> V_14 ) ;
for ( V_7 = 0 ; V_7 < V_32 -> V_27 ; V_7 ++ ) {
F_6 ( V_32 -> V_28 [ V_7 ] . V_29 . V_23 ) ;
if ( V_32 -> V_28 [ V_7 ] . V_29 . V_25 )
F_12 ( V_32 -> V_4 , V_32 -> V_28 [ V_7 ] . V_29 . V_25 ) ;
}
F_6 ( V_32 -> V_28 ) ;
}
void F_43 ( struct V_3 * V_4 , struct V_1 * V_32 ,
const struct V_92 * V_36 )
{
F_44 ( & V_32 -> V_93 ) ;
V_32 -> V_36 = V_36 ;
V_32 -> V_4 = V_4 ;
}
int F_45 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_27 , int V_94 )
{
struct V_30 * V_31 ;
int V_7 ;
if ( ! V_94 )
return - V_26 ;
V_2 -> V_28 = F_46 ( V_27 , sizeof( struct V_95 ) , V_12 ) ;
if ( ! V_2 -> V_28 )
return - V_16 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_14 = F_46 ( V_4 -> V_8 . V_96 , sizeof( struct V_10 * ) , V_12 ) ;
if ( ! V_2 -> V_14 ) {
F_6 ( V_2 -> V_28 ) ;
return - V_16 ;
}
V_2 -> V_18 = V_4 -> V_8 . V_96 ;
V_2 -> V_15 = 0 ;
for ( V_7 = 0 ; V_7 < V_27 ; V_7 ++ ) {
V_2 -> V_28 [ V_7 ] . V_29 . V_23 =
F_46 ( V_94 ,
sizeof( struct V_5 * ) ,
V_12 ) ;
if ( ! V_2 -> V_28 [ V_7 ] . V_29 . V_23 )
goto V_97;
V_2 -> V_28 [ V_7 ] . V_29 . V_22 = 0 ;
}
V_7 = 0 ;
F_19 (crtc, dev) {
V_2 -> V_28 [ V_7 ] . V_29 . V_31 = V_31 ;
V_7 ++ ;
}
return 0 ;
V_97:
F_42 ( V_2 ) ;
return - V_16 ;
}
struct V_41 * F_47 ( struct V_1 * V_2 )
{
struct V_98 * V_4 = V_2 -> V_4 -> V_4 ;
struct V_41 * V_42 ;
int V_62 ;
V_42 = F_48 ( 0 , V_4 ) ;
if ( ! V_42 )
return F_49 ( - V_16 ) ;
V_62 = F_50 ( & V_42 -> V_99 , 256 , 0 ) ;
if ( V_62 )
goto V_100;
V_42 -> V_101 = F_51 ( 1 ) ;
if ( ! V_42 -> V_101 ) {
V_62 = - V_16 ;
goto V_102;
}
V_2 -> V_103 = V_42 ;
return V_42 ;
V_102:
F_52 ( & V_42 -> V_99 ) ;
V_100:
F_53 ( V_42 ) ;
return F_49 ( V_62 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_103 )
F_55 ( V_2 -> V_103 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_41 * V_42 = V_2 -> V_103 ;
if ( V_42 ) {
if ( V_42 -> V_99 . V_104 )
F_52 ( & V_42 -> V_99 ) ;
F_53 ( V_42 ) ;
}
V_2 -> V_103 = NULL ;
}
}
void F_57 ( struct V_1 * V_2 )
{
if ( ! F_35 ( & V_2 -> V_93 ) ) {
F_58 ( & V_2 -> V_93 ) ;
if ( F_35 ( & V_70 ) ) {
F_59 ( 'v' , & V_105 ) ;
}
}
F_42 ( V_2 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_103 )
F_61 ( V_2 -> V_103 ) ;
}
T_2 F_62 ( struct V_41 * V_42 , char T_3 * V_106 ,
T_4 V_107 , T_5 * V_108 )
{
return F_63 ( V_42 , V_106 , V_107 , V_108 ) ;
}
T_2 F_64 ( struct V_41 * V_42 , const char T_3 * V_106 ,
T_4 V_107 , T_5 * V_108 )
{
return F_65 ( V_42 , V_106 , V_107 , V_108 ) ;
}
void F_66 ( struct V_41 * V_42 ,
const struct V_109 * V_110 )
{
F_67 ( V_42 , V_110 ) ;
}
void F_68 ( struct V_41 * V_42 ,
const struct V_111 * V_112 )
{
F_69 ( V_42 , V_112 ) ;
}
void F_70 ( struct V_41 * V_42 ,
const struct V_113 * V_114 )
{
F_71 ( V_42 , V_114 ) ;
}
void F_72 ( struct V_41 * V_42 ,
const struct V_109 * V_110 )
{
F_73 ( V_42 , V_110 ) ;
}
void F_74 ( struct V_41 * V_42 ,
const struct V_111 * V_112 )
{
F_75 ( V_42 , V_112 ) ;
}
void F_76 ( struct V_41 * V_42 ,
const struct V_113 * V_114 )
{
F_77 ( V_42 , V_114 ) ;
}
void F_78 ( struct V_1 * V_2 , int V_115 )
{
if ( V_2 && V_2 -> V_103 )
F_79 ( V_2 -> V_103 , V_115 ) ;
}
static int F_80 ( struct V_30 * V_31 , T_6 V_116 , T_6 V_117 ,
T_6 V_118 , T_6 V_119 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_51 * V_24 = V_2 -> V_24 ;
int V_120 ;
if ( V_42 -> V_121 . V_122 == V_123 ) {
T_7 * V_124 ;
T_7 V_125 ;
if ( V_119 > 16 )
return - V_26 ;
V_124 = ( T_7 * ) V_42 -> V_126 ;
V_116 >>= ( 16 - V_42 -> V_127 . V_116 . V_128 ) ;
V_117 >>= ( 16 - V_42 -> V_127 . V_117 . V_128 ) ;
V_118 >>= ( 16 - V_42 -> V_127 . V_118 . V_128 ) ;
V_125 = ( V_116 << V_42 -> V_127 . V_116 . V_129 ) |
( V_117 << V_42 -> V_127 . V_117 . V_129 ) |
( V_118 << V_42 -> V_127 . V_118 . V_129 ) ;
if ( V_42 -> V_127 . V_130 . V_128 > 0 ) {
T_7 V_131 = ( 1 << V_42 -> V_127 . V_130 . V_128 ) - 1 ;
V_131 <<= V_42 -> V_127 . V_130 . V_129 ;
V_125 |= V_131 ;
}
V_124 [ V_119 ] = V_125 ;
return 0 ;
}
if ( F_8 ( ! V_2 -> V_36 -> V_40 ||
! V_2 -> V_36 -> V_37 ) )
return - V_26 ;
V_120 = V_119 ;
if ( V_24 -> V_132 == 16 ) {
V_120 = V_119 << 3 ;
if ( V_24 -> V_133 == 16 && V_119 > 63 )
return - V_26 ;
if ( V_24 -> V_133 == 15 && V_119 > 31 )
return - V_26 ;
if ( V_24 -> V_133 == 16 ) {
T_6 V_134 , V_135 , V_136 ;
int V_7 ;
if ( V_119 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_36 -> V_40 ( V_31 , V_116 ,
V_117 , V_118 , V_120 + V_7 ) ;
}
V_2 -> V_36 -> V_37 ( V_31 , & V_134 ,
& V_135 , & V_136 ,
V_120 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_36 -> V_40 ( V_31 , V_134 ,
V_117 , V_136 ,
( V_120 >> 1 ) + V_7 ) ;
}
}
if ( V_24 -> V_133 != 16 )
V_2 -> V_36 -> V_40 ( V_31 , V_116 , V_117 , V_118 , V_120 ) ;
return 0 ;
}
int F_81 ( struct V_137 * V_99 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_44 * V_138 ;
T_6 * V_116 , * V_117 , * V_118 , * V_130 ;
struct V_30 * V_31 ;
int V_7 , V_21 , V_139 = 0 ;
int V_140 ;
if ( V_81 )
return - V_82 ;
F_30 ( V_4 ) ;
if ( ! F_33 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_82 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
V_31 = V_2 -> V_28 [ V_7 ] . V_29 . V_31 ;
V_138 = V_31 -> V_46 ;
V_116 = V_99 -> V_116 ;
V_117 = V_99 -> V_117 ;
V_118 = V_99 -> V_118 ;
V_130 = V_99 -> V_130 ;
V_140 = V_99 -> V_140 ;
for ( V_21 = 0 ; V_21 < V_99 -> V_104 ; V_21 ++ ) {
T_6 V_141 , V_142 , V_143 , V_144 = 0xffff ;
V_141 = * V_116 ++ ;
V_142 = * V_117 ++ ;
V_143 = * V_118 ++ ;
if ( V_130 )
V_144 = * V_130 ++ ;
V_139 = F_80 ( V_31 , V_141 , V_142 , V_143 , V_140 ++ , V_42 ) ;
if ( V_139 )
goto V_145;
}
if ( V_138 -> V_146 )
V_138 -> V_146 ( V_31 ) ;
}
V_145:
F_31 ( V_4 ) ;
return V_139 ;
}
int F_82 ( struct V_147 * V_127 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_51 * V_24 = V_2 -> V_24 ;
int V_133 ;
if ( V_127 -> V_148 != 0 || F_83 () )
return - V_26 ;
if ( V_127 -> V_132 > V_24 -> V_132 ||
V_127 -> V_149 > V_24 -> V_150 || V_127 -> V_151 > V_24 -> V_152 ||
V_127 -> V_153 > V_24 -> V_150 || V_127 -> V_154 > V_24 -> V_152 ) {
F_84 ( L_3
L_4 ,
V_127 -> V_149 , V_127 -> V_151 , V_127 -> V_132 ,
V_127 -> V_153 , V_127 -> V_154 ,
V_24 -> V_150 , V_24 -> V_152 , V_24 -> V_132 ) ;
return - V_26 ;
}
switch ( V_127 -> V_132 ) {
case 16 :
V_133 = ( V_127 -> V_117 . V_128 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_133 = ( V_127 -> V_130 . V_128 > 0 ) ? 32 : 24 ;
break;
default:
V_133 = V_127 -> V_132 ;
break;
}
switch ( V_133 ) {
case 8 :
V_127 -> V_116 . V_129 = 0 ;
V_127 -> V_117 . V_129 = 0 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 8 ;
V_127 -> V_117 . V_128 = 8 ;
V_127 -> V_118 . V_128 = 8 ;
V_127 -> V_130 . V_128 = 0 ;
V_127 -> V_130 . V_129 = 0 ;
break;
case 15 :
V_127 -> V_116 . V_129 = 10 ;
V_127 -> V_117 . V_129 = 5 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 5 ;
V_127 -> V_117 . V_128 = 5 ;
V_127 -> V_118 . V_128 = 5 ;
V_127 -> V_130 . V_128 = 1 ;
V_127 -> V_130 . V_129 = 15 ;
break;
case 16 :
V_127 -> V_116 . V_129 = 11 ;
V_127 -> V_117 . V_129 = 5 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 5 ;
V_127 -> V_117 . V_128 = 6 ;
V_127 -> V_118 . V_128 = 5 ;
V_127 -> V_130 . V_128 = 0 ;
V_127 -> V_130 . V_129 = 0 ;
break;
case 24 :
V_127 -> V_116 . V_129 = 16 ;
V_127 -> V_117 . V_129 = 8 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 8 ;
V_127 -> V_117 . V_128 = 8 ;
V_127 -> V_118 . V_128 = 8 ;
V_127 -> V_130 . V_128 = 0 ;
V_127 -> V_130 . V_129 = 0 ;
break;
case 32 :
V_127 -> V_116 . V_129 = 16 ;
V_127 -> V_117 . V_129 = 8 ;
V_127 -> V_118 . V_129 = 0 ;
V_127 -> V_116 . V_128 = 8 ;
V_127 -> V_117 . V_128 = 8 ;
V_127 -> V_118 . V_128 = 8 ;
V_127 -> V_130 . V_128 = 8 ;
V_127 -> V_130 . V_129 = 24 ;
break;
default:
return - V_26 ;
}
return 0 ;
}
int F_85 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_147 * V_127 = & V_42 -> V_127 ;
if ( V_81 )
return - V_82 ;
if ( V_127 -> V_148 != 0 ) {
F_21 ( L_5 ) ;
return - V_26 ;
}
F_29 ( V_2 ) ;
return 0 ;
}
int F_86 ( struct V_147 * V_127 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = V_42 -> V_43 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_19 * V_155 ;
int V_62 = 0 ;
int V_7 ;
if ( V_81 )
return - V_82 ;
F_30 ( V_4 ) ;
if ( ! F_33 ( V_2 ) ) {
F_31 ( V_4 ) ;
return - V_82 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
V_155 = & V_2 -> V_28 [ V_7 ] . V_29 ;
V_155 -> V_48 = V_127 -> V_156 ;
V_155 -> V_49 = V_127 -> V_157 ;
if ( V_155 -> V_22 ) {
V_62 = F_28 ( V_155 ) ;
if ( ! V_62 ) {
V_42 -> V_127 . V_156 = V_127 -> V_156 ;
V_42 -> V_127 . V_157 = V_127 -> V_157 ;
}
}
}
F_31 ( V_4 ) ;
return V_62 ;
}
static int F_87 ( struct V_1 * V_2 ,
int V_158 )
{
int V_62 = 0 ;
int V_27 = 0 ;
int V_7 ;
struct V_41 * V_42 ;
struct V_159 V_160 ;
int V_39 = 0 ;
memset ( & V_160 , 0 , sizeof( struct V_159 ) ) ;
V_160 . V_161 = 24 ;
V_160 . V_162 = 32 ;
V_160 . V_163 = ( unsigned ) - 1 ;
V_160 . V_164 = ( unsigned ) - 1 ;
if ( V_158 != V_160 . V_162 )
V_160 . V_161 = V_160 . V_162 = V_158 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
struct V_10 * V_165 = V_2 -> V_14 [ V_7 ] ;
struct V_166 * V_167 ;
V_167 = & V_165 -> V_6 -> V_167 ;
if ( V_167 -> V_168 ) {
switch ( V_167 -> V_169 ) {
case 8 :
V_160 . V_161 = V_160 . V_162 = 8 ;
break;
case 15 :
V_160 . V_161 = 15 ;
V_160 . V_162 = 16 ;
break;
case 16 :
V_160 . V_161 = V_160 . V_162 = 16 ;
break;
case 24 :
V_160 . V_161 = V_160 . V_162 = 24 ;
break;
case 32 :
V_160 . V_161 = 24 ;
V_160 . V_162 = 32 ;
break;
}
break;
}
}
V_27 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
struct V_170 * V_171 ;
struct V_19 * V_29 ;
int V_48 , V_49 , V_21 ;
bool V_172 = true , V_173 = true ;
V_171 = V_2 -> V_28 [ V_7 ] . V_171 ;
V_29 = & V_2 -> V_28 [ V_7 ] . V_29 ;
if ( ! V_171 )
continue;
V_27 ++ ;
V_48 = V_2 -> V_28 [ V_7 ] . V_48 ;
V_49 = V_2 -> V_28 [ V_7 ] . V_49 ;
if ( V_39 == 0 )
V_39 = V_2 -> V_28 [ V_7 ] . V_29 . V_31 -> V_39 ;
V_160 . V_174 = F_88 ( T_7 , V_171 -> V_175 + V_48 , V_160 . V_174 ) ;
V_160 . V_176 = F_88 ( T_7 , V_171 -> V_177 + V_49 , V_160 . V_176 ) ;
for ( V_21 = 0 ; V_21 < V_29 -> V_22 ; V_21 ++ ) {
struct V_5 * V_6 = V_29 -> V_23 [ V_21 ] ;
if ( V_6 -> V_178 ) {
V_173 = ( V_6 -> V_179 == ( V_6 -> V_180 - 1 ) ) ;
V_172 = ( V_6 -> V_181 == ( V_6 -> V_182 - 1 ) ) ;
break;
}
}
if ( V_173 )
V_160 . V_163 = F_89 ( T_7 , V_171 -> V_175 + V_48 , V_160 . V_163 ) ;
if ( V_172 )
V_160 . V_164 = F_89 ( T_7 , V_171 -> V_177 + V_49 , V_160 . V_164 ) ;
}
if ( V_27 == 0 || V_160 . V_163 == - 1 || V_160 . V_164 == - 1 ) {
F_90 ( L_6 ) ;
V_160 . V_163 = V_160 . V_174 = 1024 ;
V_160 . V_164 = V_160 . V_176 = 768 ;
}
V_62 = (* V_2 -> V_36 -> V_183 )( V_2 , & V_160 ) ;
if ( V_62 < 0 )
return V_62 ;
V_42 = V_2 -> V_103 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ )
if ( V_2 -> V_28 [ V_7 ] . V_29 . V_22 )
V_2 -> V_28 [ V_7 ] . V_29 . V_24 = V_2 -> V_24 ;
V_42 -> V_127 . V_148 = 0 ;
if ( F_91 ( V_42 ) < 0 )
return - V_26 ;
F_92 ( V_2 -> V_4 -> V_4 , L_7 ,
V_42 -> V_184 , V_42 -> V_121 . V_54 ) ;
if ( F_35 ( & V_70 ) ) {
F_93 ( 'v' , & V_105 ) ;
}
F_94 ( & V_2 -> V_93 , & V_70 ) ;
return 0 ;
}
void F_95 ( struct V_41 * V_42 , T_8 V_185 ,
T_8 V_133 )
{
V_42 -> V_121 . type = V_186 ;
V_42 -> V_121 . V_122 = V_133 == 8 ? V_187 :
V_123 ;
V_42 -> V_121 . V_188 = 0 ;
V_42 -> V_121 . V_189 = 0 ;
V_42 -> V_121 . V_190 = 0 ;
V_42 -> V_121 . V_191 = 1 ;
V_42 -> V_121 . V_192 = 1 ;
V_42 -> V_121 . V_193 = 0 ;
V_42 -> V_121 . V_194 = V_195 ;
V_42 -> V_121 . V_196 = V_185 ;
return;
}
void F_96 ( struct V_41 * V_42 , struct V_1 * V_2 ,
T_8 V_163 , T_8 V_164 )
{
struct V_51 * V_24 = V_2 -> V_24 ;
V_42 -> V_126 = V_2 -> V_126 ;
V_42 -> V_127 . V_153 = V_24 -> V_150 ;
V_42 -> V_127 . V_154 = V_24 -> V_152 ;
V_42 -> V_127 . V_132 = V_24 -> V_132 ;
V_42 -> V_127 . V_197 = V_198 ;
V_42 -> V_127 . V_156 = 0 ;
V_42 -> V_127 . V_157 = 0 ;
V_42 -> V_127 . V_199 = V_200 ;
V_42 -> V_127 . V_152 = - 1 ;
V_42 -> V_127 . V_150 = - 1 ;
switch ( V_24 -> V_133 ) {
case 8 :
V_42 -> V_127 . V_116 . V_129 = 0 ;
V_42 -> V_127 . V_117 . V_129 = 0 ;
V_42 -> V_127 . V_118 . V_129 = 0 ;
V_42 -> V_127 . V_116 . V_128 = 8 ;
V_42 -> V_127 . V_117 . V_128 = 8 ;
V_42 -> V_127 . V_118 . V_128 = 8 ;
V_42 -> V_127 . V_130 . V_129 = 0 ;
V_42 -> V_127 . V_130 . V_128 = 0 ;
break;
case 15 :
V_42 -> V_127 . V_116 . V_129 = 10 ;
V_42 -> V_127 . V_117 . V_129 = 5 ;
V_42 -> V_127 . V_118 . V_129 = 0 ;
V_42 -> V_127 . V_116 . V_128 = 5 ;
V_42 -> V_127 . V_117 . V_128 = 5 ;
V_42 -> V_127 . V_118 . V_128 = 5 ;
V_42 -> V_127 . V_130 . V_129 = 15 ;
V_42 -> V_127 . V_130 . V_128 = 1 ;
break;
case 16 :
V_42 -> V_127 . V_116 . V_129 = 11 ;
V_42 -> V_127 . V_117 . V_129 = 5 ;
V_42 -> V_127 . V_118 . V_129 = 0 ;
V_42 -> V_127 . V_116 . V_128 = 5 ;
V_42 -> V_127 . V_117 . V_128 = 6 ;
V_42 -> V_127 . V_118 . V_128 = 5 ;
V_42 -> V_127 . V_130 . V_129 = 0 ;
break;
case 24 :
V_42 -> V_127 . V_116 . V_129 = 16 ;
V_42 -> V_127 . V_117 . V_129 = 8 ;
V_42 -> V_127 . V_118 . V_129 = 0 ;
V_42 -> V_127 . V_116 . V_128 = 8 ;
V_42 -> V_127 . V_117 . V_128 = 8 ;
V_42 -> V_127 . V_118 . V_128 = 8 ;
V_42 -> V_127 . V_130 . V_129 = 0 ;
V_42 -> V_127 . V_130 . V_128 = 0 ;
break;
case 32 :
V_42 -> V_127 . V_116 . V_129 = 16 ;
V_42 -> V_127 . V_117 . V_129 = 8 ;
V_42 -> V_127 . V_118 . V_129 = 0 ;
V_42 -> V_127 . V_116 . V_128 = 8 ;
V_42 -> V_127 . V_117 . V_128 = 8 ;
V_42 -> V_127 . V_118 . V_128 = 8 ;
V_42 -> V_127 . V_130 . V_129 = 24 ;
V_42 -> V_127 . V_130 . V_128 = 8 ;
break;
default:
break;
}
V_42 -> V_127 . V_149 = V_163 ;
V_42 -> V_127 . V_151 = V_164 ;
}
static int F_97 ( struct V_1 * V_2 ,
T_8 V_201 ,
T_8 V_202 )
{
struct V_5 * V_6 ;
int V_107 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_107 += V_6 -> V_36 -> V_203 ( V_6 , V_201 , V_202 ) ;
}
return V_107 ;
}
struct V_170 * F_98 ( struct V_10 * V_204 , int V_150 , int V_152 )
{
struct V_170 * V_25 ;
F_17 (mode, &fb_connector->connector->modes, head) {
if ( V_25 -> V_175 > V_150 ||
V_25 -> V_177 > V_152 )
continue;
if ( V_25 -> type & V_205 )
return V_25 ;
}
return NULL ;
}
static bool F_99 ( struct V_10 * V_204 )
{
return V_204 -> V_6 -> V_167 . V_206 ;
}
struct V_170 * F_100 ( struct V_10 * V_165 ,
int V_150 , int V_152 )
{
struct V_166 * V_167 ;
struct V_170 * V_25 ;
bool V_207 ;
V_167 = & V_165 -> V_6 -> V_167 ;
if ( V_167 -> V_206 == false )
return NULL ;
if ( V_167 -> V_208 || V_167 -> V_209 )
goto V_210;
V_207 = ! V_167 -> V_211 ;
V_212:
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_25 -> V_175 != V_167 -> V_149 ||
V_25 -> V_177 != V_167 -> V_151 )
continue;
if ( V_167 -> V_213 ) {
if ( V_25 -> V_214 != V_167 -> V_215 )
continue;
}
if ( V_167 -> V_211 ) {
if ( ! ( V_25 -> V_216 & V_217 ) )
continue;
} else if ( V_207 ) {
if ( V_25 -> V_216 & V_217 )
continue;
}
return V_25 ;
}
if ( V_207 ) {
V_207 = false ;
goto V_212;
}
V_210:
V_25 = F_101 ( V_165 -> V_6 -> V_4 ,
V_167 ) ;
F_94 ( & V_25 -> V_218 , & V_165 -> V_6 -> V_219 ) ;
return V_25 ;
}
static bool F_102 ( struct V_5 * V_6 , bool V_220 )
{
bool V_221 ;
if ( V_220 )
V_221 = V_6 -> V_222 == V_223 ;
else
V_221 = V_6 -> V_222 != V_224 ;
return V_221 ;
}
static void F_103 ( struct V_1 * V_2 ,
bool * V_45 )
{
bool V_225 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_45 [ V_7 ] = F_102 ( V_6 , true ) ;
F_104 ( L_8 , V_6 -> V_53 . V_54 ,
V_45 [ V_7 ] ? L_9 : L_10 ) ;
V_225 |= V_45 [ V_7 ] ;
}
if ( V_225 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
V_6 = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_45 [ V_7 ] = F_102 ( V_6 , false ) ;
}
}
static bool F_105 ( struct V_1 * V_2 ,
struct V_170 * * V_219 ,
struct V_226 * V_227 ,
bool * V_45 , int V_150 , int V_152 )
{
int V_107 , V_7 , V_21 ;
bool V_228 = false ;
struct V_10 * V_165 ;
struct V_170 * V_229 , * V_25 ;
if ( V_2 -> V_27 > 1 )
return false ;
V_107 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
if ( V_45 [ V_7 ] )
V_107 ++ ;
}
if ( V_107 <= 1 )
return false ;
V_228 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
if ( ! V_45 [ V_7 ] )
continue;
V_165 = V_2 -> V_14 [ V_7 ] ;
V_219 [ V_7 ] = F_100 ( V_165 , V_150 , V_152 ) ;
if ( ! V_219 [ V_7 ] ) {
V_228 = false ;
break;
}
for ( V_21 = 0 ; V_21 < V_7 ; V_21 ++ ) {
if ( ! V_45 [ V_21 ] )
continue;
if ( ! F_106 ( V_219 [ V_21 ] , V_219 [ V_7 ] ) )
V_228 = false ;
}
}
if ( V_228 ) {
F_104 ( L_11 ) ;
return true ;
}
V_228 = true ;
V_229 = F_107 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
if ( ! V_45 [ V_7 ] )
continue;
V_165 = V_2 -> V_14 [ V_7 ] ;
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_106 ( V_25 , V_229 ) )
V_219 [ V_7 ] = V_25 ;
}
if ( ! V_219 [ V_7 ] )
V_228 = false ;
}
if ( V_228 ) {
F_104 ( L_12 ) ;
return true ;
}
F_90 ( L_13 ) ;
return false ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_170 * * V_219 ,
struct V_226 * V_227 ,
int V_230 ,
int V_231 , int V_232 )
{
struct V_10 * V_165 ;
int V_7 ;
int V_233 = 0 , V_234 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
V_165 = V_2 -> V_14 [ V_7 ] ;
if ( ! V_165 -> V_6 -> V_178 )
continue;
if ( ! V_219 [ V_7 ] && ( V_231 || V_232 ) ) {
F_104 ( L_14 , V_7 ,
V_165 -> V_6 -> V_53 . V_54 ) ;
continue;
}
if ( V_165 -> V_6 -> V_179 < V_231 )
V_233 += V_219 [ V_7 ] -> V_175 ;
if ( V_165 -> V_6 -> V_181 < V_232 )
V_234 += V_219 [ V_7 ] -> V_177 ;
}
V_227 [ V_230 ] . V_48 = V_233 ;
V_227 [ V_230 ] . V_49 = V_234 ;
F_104 ( L_15 , V_233 , V_234 , V_231 , V_232 ) ;
return 0 ;
}
static bool F_109 ( struct V_1 * V_2 ,
struct V_170 * * V_219 ,
struct V_226 * V_227 ,
bool * V_45 , int V_150 , int V_152 )
{
struct V_10 * V_165 ;
int V_7 ;
T_9 V_235 = 0 , V_131 ;
int V_236 = 0 ;
V_131 = ( 1 << V_2 -> V_15 ) - 1 ;
V_237:
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
V_165 = V_2 -> V_14 [ V_7 ] ;
if ( V_235 & ( 1 << V_7 ) )
continue;
if ( V_45 [ V_7 ] == false ) {
V_235 |= ( 1 << V_7 ) ;
continue;
}
if ( V_236 == 0 && V_165 -> V_6 -> V_178 )
continue;
if ( V_236 == 1 ) {
if ( V_165 -> V_6 -> V_179 != 0 ||
V_165 -> V_6 -> V_181 != 0 )
continue;
} else {
if ( V_165 -> V_6 -> V_179 != V_236 - 1 &&
V_165 -> V_6 -> V_181 != V_236 - 1 )
continue;
F_108 ( V_2 , V_219 , V_227 ,
V_7 , V_165 -> V_6 -> V_179 , V_165 -> V_6 -> V_181 ) ;
}
F_104 ( L_16 ,
V_165 -> V_6 -> V_53 . V_54 ) ;
V_219 [ V_7 ] = F_100 ( V_165 , V_150 , V_152 ) ;
if ( ! V_219 [ V_7 ] ) {
F_104 ( L_17 ,
V_165 -> V_6 -> V_53 . V_54 , V_165 -> V_6 -> V_238 ? V_165 -> V_6 -> V_238 -> V_54 : 0 ) ;
V_219 [ V_7 ] = F_98 ( V_165 , V_150 , V_152 ) ;
}
if ( ! V_219 [ V_7 ] && ! F_35 ( & V_165 -> V_6 -> V_219 ) ) {
F_17 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_104 ( L_18 , V_219 [ V_7 ] ? V_219 [ V_7 ] -> V_239 :
L_19 ) ;
V_235 |= ( 1 << V_7 ) ;
}
if ( ( V_235 & V_131 ) != V_131 ) {
V_236 ++ ;
goto V_237;
}
return true ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_95 * * V_240 ,
struct V_170 * * V_219 ,
int V_241 , int V_150 , int V_152 )
{
int V_52 , V_242 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
const struct V_243 * V_244 ;
struct V_245 * V_246 ;
int V_247 , V_248 , V_249 ;
struct V_95 * * V_250 , * V_31 ;
struct V_10 * V_165 ;
if ( V_241 == V_2 -> V_15 )
return 0 ;
V_165 = V_2 -> V_14 [ V_241 ] ;
V_6 = V_165 -> V_6 ;
V_240 [ V_241 ] = NULL ;
V_248 = F_110 ( V_2 , V_240 , V_219 , V_241 + 1 , V_150 , V_152 ) ;
if ( V_219 [ V_241 ] == NULL )
return V_248 ;
V_250 = F_4 ( V_4 -> V_8 . V_96 *
sizeof( struct V_95 * ) , V_12 ) ;
if ( ! V_250 )
return V_248 ;
V_247 = 1 ;
if ( V_6 -> V_222 == V_223 )
V_247 ++ ;
if ( F_99 ( V_165 ) )
V_247 ++ ;
if ( F_98 ( V_165 , V_150 , V_152 ) )
V_247 ++ ;
V_244 = V_6 -> V_46 ;
V_246 = V_244 -> V_251 ( V_6 ) ;
if ( ! V_246 )
goto V_145;
for ( V_52 = 0 ; V_52 < V_2 -> V_27 ; V_52 ++ ) {
V_31 = & V_2 -> V_28 [ V_52 ] ;
if ( ( V_246 -> V_252 & ( 1 << V_52 ) ) == 0 )
continue;
for ( V_242 = 0 ; V_242 < V_241 ; V_242 ++ )
if ( V_240 [ V_242 ] == V_31 )
break;
if ( V_242 < V_241 ) {
if ( V_2 -> V_27 > 1 )
continue;
if ( ! F_106 ( V_219 [ V_242 ] , V_219 [ V_241 ] ) )
continue;
}
V_250 [ V_241 ] = V_31 ;
memcpy ( V_250 , V_240 , V_241 * sizeof( struct V_95 * ) ) ;
V_249 = V_247 + F_110 ( V_2 , V_250 , V_219 , V_241 + 1 ,
V_150 , V_152 ) ;
if ( V_249 > V_248 ) {
V_248 = V_249 ;
memcpy ( V_240 , V_250 ,
V_4 -> V_8 . V_96 *
sizeof( struct V_95 * ) ) ;
}
}
V_145:
F_6 ( V_250 ) ;
return V_248 ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_95 * * V_250 ;
struct V_170 * * V_219 ;
struct V_226 * V_227 ;
struct V_19 * V_155 ;
bool * V_45 ;
int V_150 , V_152 ;
int V_7 ;
F_104 ( L_20 ) ;
V_150 = V_4 -> V_8 . V_253 ;
V_152 = V_4 -> V_8 . V_254 ;
V_250 = F_46 ( V_4 -> V_8 . V_96 ,
sizeof( struct V_95 * ) , V_12 ) ;
V_219 = F_46 ( V_4 -> V_8 . V_96 ,
sizeof( struct V_170 * ) , V_12 ) ;
V_227 = F_46 ( V_4 -> V_8 . V_96 ,
sizeof( struct V_226 ) , V_12 ) ;
V_45 = F_46 ( V_4 -> V_8 . V_96 ,
sizeof( bool ) , V_12 ) ;
if ( ! V_250 || ! V_219 || ! V_45 || ! V_227 ) {
F_21 ( L_21 ) ;
goto V_145;
}
F_103 ( V_2 , V_45 ) ;
if ( ! ( V_2 -> V_36 -> V_255 &&
V_2 -> V_36 -> V_255 ( V_2 , V_250 , V_219 ,
V_227 ,
V_45 , V_150 , V_152 ) ) ) {
memset ( V_219 , 0 , V_4 -> V_8 . V_96 * sizeof( V_219 [ 0 ] ) ) ;
memset ( V_250 , 0 , V_4 -> V_8 . V_96 * sizeof( V_250 [ 0 ] ) ) ;
memset ( V_227 , 0 , V_4 -> V_8 . V_96 * sizeof( V_227 [ 0 ] ) ) ;
if ( ! F_105 ( V_2 , V_219 , V_227 ,
V_45 , V_150 , V_152 ) &&
! F_109 ( V_2 , V_219 , V_227 ,
V_45 , V_150 , V_152 ) )
F_21 ( L_22 ) ;
F_104 ( L_23 ,
V_150 , V_152 ) ;
F_110 ( V_2 , V_250 , V_219 , 0 , V_150 , V_152 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
V_155 = & V_2 -> V_28 [ V_7 ] . V_29 ;
V_155 -> V_22 = 0 ;
V_155 -> V_24 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ ) {
struct V_170 * V_25 = V_219 [ V_7 ] ;
struct V_95 * V_256 = V_250 [ V_7 ] ;
struct V_226 * V_129 = & V_227 [ V_7 ] ;
V_155 = & V_256 -> V_29 ;
if ( V_25 && V_256 ) {
F_104 ( L_24 ,
V_25 -> V_239 , V_256 -> V_29 . V_31 -> V_53 . V_54 , V_129 -> V_48 , V_129 -> V_49 ) ;
V_256 -> V_171 = V_25 ;
V_256 -> V_48 = V_129 -> V_48 ;
V_256 -> V_49 = V_129 -> V_49 ;
if ( V_155 -> V_25 )
F_12 ( V_4 , V_155 -> V_25 ) ;
V_155 -> V_25 = F_112 ( V_4 ,
V_256 -> V_171 ) ;
V_155 -> V_23 [ V_155 -> V_22 ++ ] = V_2 -> V_14 [ V_7 ] -> V_6 ;
V_155 -> V_24 = V_2 -> V_24 ;
V_155 -> V_48 = V_129 -> V_48 ;
V_155 -> V_49 = V_129 -> V_49 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
V_155 = & V_2 -> V_28 [ V_7 ] . V_29 ;
if ( V_155 -> V_22 == 0 ) {
F_113 ( V_155 -> V_24 ) ;
if ( V_155 -> V_25 )
F_12 ( V_4 , V_155 -> V_25 ) ;
V_155 -> V_25 = NULL ;
}
}
V_145:
F_6 ( V_250 ) ;
F_6 ( V_219 ) ;
F_6 ( V_227 ) ;
F_6 ( V_45 ) ;
}
int F_114 ( struct V_1 * V_2 , int V_257 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_107 = 0 ;
F_2 ( & V_4 -> V_8 . V_9 ) ;
V_107 = F_97 ( V_2 ,
V_4 -> V_8 . V_253 ,
V_4 -> V_8 . V_254 ) ;
F_5 ( & V_4 -> V_8 . V_9 ) ;
if ( V_107 == 0 )
F_92 ( V_2 -> V_4 -> V_4 , L_25 ) ;
F_111 ( V_2 ) ;
return F_87 ( V_2 , V_257 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_7 V_253 , V_254 ;
F_2 ( & V_2 -> V_4 -> V_8 . V_9 ) ;
if ( ! V_2 -> V_24 || ! F_33 ( V_2 ) ) {
V_2 -> V_66 = true ;
F_5 ( & V_2 -> V_4 -> V_8 . V_9 ) ;
return 0 ;
}
F_104 ( L_20 ) ;
V_253 = V_2 -> V_24 -> V_150 ;
V_254 = V_2 -> V_24 -> V_152 ;
F_97 ( V_2 , V_253 , V_254 ) ;
F_5 ( & V_2 -> V_4 -> V_8 . V_9 ) ;
F_30 ( V_4 ) ;
F_111 ( V_2 ) ;
F_31 ( V_4 ) ;
F_85 ( V_2 -> V_103 ) ;
return 0 ;
}
static int T_10 F_115 ( void )
{
const char * V_239 = L_26 ;
struct V_258 * V_259 ;
F_2 ( & V_260 ) ;
V_259 = F_116 ( V_239 ) ;
F_5 ( & V_260 ) ;
if ( ! V_259 )
F_117 ( V_239 ) ;
return 0 ;
}
