int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
int V_7 ;
if ( ! V_8 )
return 0 ;
F_2 ( & V_4 -> V_9 . V_10 ) ;
F_3 (connector, dev) {
struct V_11 * V_12 ;
V_12 = F_4 ( sizeof( struct V_11 ) , V_13 ) ;
if ( ! V_12 )
goto V_14;
V_12 -> V_6 = V_6 ;
V_2 -> V_15 [ V_2 -> V_16 ++ ] = V_12 ;
}
F_5 ( & V_4 -> V_9 . V_10 ) ;
return 0 ;
V_14:
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
F_6 ( V_2 -> V_15 [ V_7 ] ) ;
V_2 -> V_15 [ V_7 ] = NULL ;
}
V_2 -> V_16 = 0 ;
F_5 ( & V_4 -> V_9 . V_10 ) ;
return - V_17 ;
}
int F_7 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_11 * * V_18 ;
struct V_11 * V_12 ;
if ( ! V_8 )
return 0 ;
F_8 ( ! F_9 ( & V_2 -> V_4 -> V_9 . V_10 ) ) ;
if ( V_2 -> V_16 + 1 > V_2 -> V_19 ) {
V_18 = F_10 ( V_2 -> V_15 , sizeof( struct V_11 * ) * ( V_2 -> V_16 + 1 ) , V_13 ) ;
if ( ! V_18 )
return - V_17 ;
V_2 -> V_19 = V_2 -> V_16 + 1 ;
V_2 -> V_15 = V_18 ;
}
V_12 = F_4 ( sizeof( struct V_11 ) , V_13 ) ;
if ( ! V_12 )
return - V_17 ;
V_12 -> V_6 = V_6 ;
V_2 -> V_15 [ V_2 -> V_16 ++ ] = V_12 ;
return 0 ;
}
static void F_11 ( struct V_20 * V_21 ,
struct V_5 * V_6 )
{
int V_7 , V_22 ;
for ( V_7 = 0 ; V_7 < V_21 -> V_23 ; V_7 ++ ) {
if ( V_21 -> V_24 [ V_7 ] == V_6 )
break;
}
if ( V_7 == V_21 -> V_23 )
return;
for ( V_22 = V_7 + 1 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
V_21 -> V_24 [ V_22 - 1 ] = V_21 -> V_24 [ V_22 ] ;
}
V_21 -> V_23 -- ;
if ( V_21 -> V_23 == 0 ) {
V_21 -> V_25 = NULL ;
F_12 ( V_6 -> V_4 , V_21 -> V_26 ) ;
V_21 -> V_26 = NULL ;
}
}
int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_11 * V_12 ;
int V_7 , V_22 ;
if ( ! V_8 )
return 0 ;
F_8 ( ! F_9 ( & V_2 -> V_4 -> V_9 . V_10 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
if ( V_2 -> V_15 [ V_7 ] -> V_6 == V_6 )
break;
}
if ( V_7 == V_2 -> V_16 )
return - V_27 ;
V_12 = V_2 -> V_15 [ V_7 ] ;
for ( V_22 = V_7 + 1 ; V_22 < V_2 -> V_16 ; V_22 ++ ) {
V_2 -> V_15 [ V_22 - 1 ] = V_2 -> V_15 [ V_22 ] ;
}
V_2 -> V_16 -- ;
F_6 ( V_12 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ )
F_11 ( & V_2 -> V_29 [ V_7 ] . V_30 , V_6 ) ;
return 0 ;
}
static void F_14 ( struct V_31 * V_32 , struct V_1 * V_33 )
{
T_1 * V_34 , * V_35 , * V_36 ;
int V_7 ;
if ( V_33 -> V_37 -> V_38 == NULL )
return;
V_34 = V_32 -> V_39 ;
V_35 = V_34 + V_32 -> V_40 ;
V_36 = V_35 + V_32 -> V_40 ;
for ( V_7 = 0 ; V_7 < V_32 -> V_40 ; V_7 ++ )
V_33 -> V_37 -> V_38 ( V_32 , & V_34 [ V_7 ] , & V_35 [ V_7 ] , & V_36 [ V_7 ] , V_7 ) ;
}
static void F_15 ( struct V_31 * V_32 )
{
T_1 * V_34 , * V_35 , * V_36 ;
if ( V_32 -> V_37 -> V_41 == NULL )
return;
V_34 = V_32 -> V_39 ;
V_35 = V_34 + V_32 -> V_40 ;
V_36 = V_35 + V_32 -> V_40 ;
V_32 -> V_37 -> V_41 ( V_32 , V_34 , V_35 , V_36 , 0 , V_32 -> V_40 ) ;
}
int F_16 ( struct V_42 * V_43 )
{
struct V_1 * V_33 = V_43 -> V_44 ;
const struct V_45 * V_37 ;
int V_7 ;
F_17 (helper, &kernel_fb_helper_list, kernel_fb_list) {
for ( V_7 = 0 ; V_7 < V_33 -> V_28 ; V_7 ++ ) {
struct V_20 * V_30 =
& V_33 -> V_29 [ V_7 ] . V_30 ;
if ( ! V_30 -> V_32 -> V_46 )
continue;
V_37 = V_30 -> V_32 -> V_47 ;
F_14 ( V_30 -> V_32 , V_33 ) ;
V_37 -> V_48 ( V_30 -> V_32 ,
V_30 -> V_25 ,
V_30 -> V_49 ,
V_30 -> V_50 ,
V_51 ) ;
}
}
return 0 ;
}
static struct V_52 * F_18 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_4 ;
struct V_31 * V_53 ;
F_19 (c, dev) {
if ( V_32 -> V_54 . V_55 == V_53 -> V_54 . V_55 )
return V_53 -> V_56 -> V_25 ;
}
return NULL ;
}
int F_20 ( struct V_42 * V_43 )
{
struct V_1 * V_33 = V_43 -> V_44 ;
struct V_31 * V_32 ;
const struct V_45 * V_37 ;
struct V_52 * V_25 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_33 -> V_28 ; V_7 ++ ) {
struct V_20 * V_30 = & V_33 -> V_29 [ V_7 ] . V_30 ;
V_32 = V_30 -> V_32 ;
V_37 = V_32 -> V_47 ;
V_25 = F_18 ( V_32 ) ;
if ( ! V_32 -> V_46 )
continue;
if ( ! V_25 ) {
F_21 ( L_1 ) ;
continue;
}
F_15 ( V_30 -> V_32 ) ;
V_37 -> V_48 ( V_30 -> V_32 , V_25 , V_32 -> V_49 ,
V_32 -> V_50 , V_57 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
int V_7 , V_62 ;
unsigned V_63 ;
V_61 = F_23 ( V_4 ) ;
if ( ! V_61 )
return - V_17 ;
V_61 -> V_64 = V_4 -> V_9 . V_64 ;
V_65:
V_63 = 0 ;
F_24 (plane, dev) {
struct V_66 * V_67 ;
V_67 = F_25 ( V_61 , V_59 ) ;
if ( F_26 ( V_67 ) ) {
V_62 = F_27 ( V_67 ) ;
goto V_14;
}
V_67 -> V_68 = F_28 ( V_69 ) ;
V_59 -> V_70 = V_59 -> V_25 ;
V_63 |= 1 << F_29 ( V_59 ) ;
if ( V_59 -> type == V_71 )
continue;
V_62 = F_30 ( V_59 , V_67 ) ;
if ( V_62 != 0 )
goto V_14;
}
for( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
struct V_20 * V_30 = & V_2 -> V_29 [ V_7 ] . V_30 ;
V_62 = F_31 ( V_30 , V_61 ) ;
if ( V_62 != 0 )
goto V_14;
}
V_62 = F_32 ( V_61 ) ;
V_14:
F_33 ( V_4 , V_63 , V_62 ) ;
if ( V_62 == - V_72 )
goto V_73;
if ( V_62 != 0 )
F_34 ( V_61 ) ;
return V_62 ;
V_73:
F_35 ( V_61 ) ;
F_36 ( V_61 ) ;
goto V_65;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_58 * V_59 ;
int V_7 ;
F_38 ( V_4 ) ;
if ( V_2 -> V_74 )
return F_22 ( V_2 ) ;
F_24 (plane, dev) {
if ( V_59 -> type != V_71 )
F_39 ( V_59 ) ;
if ( V_4 -> V_9 . V_75 ) {
F_40 ( V_59 ,
V_4 -> V_9 . V_75 ,
F_28 ( V_69 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
struct V_20 * V_30 = & V_2 -> V_29 [ V_7 ] . V_30 ;
struct V_31 * V_32 = V_30 -> V_32 ;
int V_62 ;
if ( V_32 -> V_37 -> V_76 ) {
V_62 = V_32 -> V_37 -> V_76 ( V_32 , NULL , 0 , 0 , 0 , 0 , 0 ) ;
if ( V_62 )
return V_62 ;
} else if ( V_32 -> V_37 -> V_77 ) {
V_62 = V_32 -> V_37 -> V_77 ( V_32 , NULL , 0 , 0 , 0 ) ;
if ( V_62 )
return V_62 ;
}
V_62 = F_41 ( V_30 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_78 ;
int V_62 ;
if ( ! V_8 )
return - V_79 ;
F_43 ( V_4 ) ;
V_62 = F_37 ( V_2 ) ;
V_78 = V_2 -> V_80 ;
if ( V_78 )
V_2 -> V_80 = false ;
F_44 ( V_4 ) ;
if ( V_78 )
F_45 ( V_2 ) ;
return V_62 ;
}
static bool F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_31 * V_32 ;
int V_81 = 0 , V_82 = 0 ;
if ( V_4 -> V_56 -> V_83 )
return false ;
F_19 (crtc, dev) {
if ( V_32 -> V_56 -> V_25 )
V_82 ++ ;
if ( V_32 -> V_56 -> V_25 == V_2 -> V_25 )
V_81 ++ ;
}
if ( V_81 < V_82 )
return false ;
return true ;
}
static bool F_47 ( void )
{
bool V_62 , error = false ;
struct V_1 * V_33 ;
if ( F_48 ( & V_84 ) )
return false ;
F_17 (helper, &kernel_fb_helper_list, kernel_fb_list) {
struct V_3 * V_4 = V_33 -> V_4 ;
if ( V_4 -> V_85 == V_86 )
continue;
F_43 ( V_4 ) ;
V_62 = F_37 ( V_33 ) ;
if ( V_62 )
error = true ;
F_44 ( V_4 ) ;
}
return error ;
}
static void F_49 ( struct V_87 * V_88 )
{
bool V_62 ;
V_62 = F_47 () ;
if ( V_62 == true )
F_21 ( L_2 ) ;
}
static void F_50 ( int V_89 )
{
F_51 ( & V_90 ) ;
}
static void F_52 ( struct V_42 * V_43 , int V_91 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_31 * V_32 ;
struct V_5 * V_6 ;
int V_7 , V_22 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
V_32 = V_2 -> V_29 [ V_7 ] . V_30 . V_32 ;
if ( ! V_32 -> V_46 )
continue;
for ( V_22 = 0 ; V_22 < V_2 -> V_16 ; V_22 ++ ) {
V_6 = V_2 -> V_15 [ V_22 ] -> V_6 ;
V_6 -> V_37 -> V_92 ( V_6 , V_91 ) ;
F_53 ( & V_6 -> V_54 ,
V_4 -> V_9 . V_93 , V_91 ) ;
}
}
F_44 ( V_4 ) ;
}
int F_54 ( int V_94 , struct V_42 * V_43 )
{
if ( V_95 )
return - V_96 ;
switch ( V_94 ) {
case V_97 :
F_52 ( V_43 , V_98 ) ;
break;
case V_99 :
F_52 ( V_43 , V_100 ) ;
break;
case V_101 :
F_52 ( V_43 , V_100 ) ;
break;
case V_102 :
F_52 ( V_43 , V_103 ) ;
break;
case V_104 :
F_52 ( V_43 , V_105 ) ;
break;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_33 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_33 -> V_16 ; V_7 ++ )
F_6 ( V_33 -> V_15 [ V_7 ] ) ;
F_6 ( V_33 -> V_15 ) ;
for ( V_7 = 0 ; V_7 < V_33 -> V_28 ; V_7 ++ ) {
F_6 ( V_33 -> V_29 [ V_7 ] . V_30 . V_24 ) ;
if ( V_33 -> V_29 [ V_7 ] . V_30 . V_26 )
F_12 ( V_33 -> V_4 , V_33 -> V_29 [ V_7 ] . V_30 . V_26 ) ;
}
F_6 ( V_33 -> V_29 ) ;
}
void F_56 ( struct V_3 * V_4 , struct V_1 * V_33 ,
const struct V_106 * V_37 )
{
F_57 ( & V_33 -> V_107 ) ;
V_33 -> V_37 = V_37 ;
V_33 -> V_4 = V_4 ;
}
int F_58 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_28 , int V_108 )
{
struct V_31 * V_32 ;
int V_7 ;
if ( ! V_8 )
return 0 ;
if ( ! V_108 )
return - V_27 ;
V_2 -> V_29 = F_59 ( V_28 , sizeof( struct V_109 ) , V_13 ) ;
if ( ! V_2 -> V_29 )
return - V_17 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_15 = F_59 ( V_4 -> V_9 . V_110 , sizeof( struct V_11 * ) , V_13 ) ;
if ( ! V_2 -> V_15 ) {
F_6 ( V_2 -> V_29 ) ;
return - V_17 ;
}
V_2 -> V_19 = V_4 -> V_9 . V_110 ;
V_2 -> V_16 = 0 ;
for ( V_7 = 0 ; V_7 < V_28 ; V_7 ++ ) {
V_2 -> V_29 [ V_7 ] . V_30 . V_24 =
F_59 ( V_108 ,
sizeof( struct V_5 * ) ,
V_13 ) ;
if ( ! V_2 -> V_29 [ V_7 ] . V_30 . V_24 )
goto V_111;
V_2 -> V_29 [ V_7 ] . V_30 . V_23 = 0 ;
}
V_7 = 0 ;
F_19 (crtc, dev) {
V_2 -> V_29 [ V_7 ] . V_30 . V_32 = V_32 ;
V_7 ++ ;
}
V_2 -> V_74 = ! ! F_60 ( V_4 , V_112 ) ;
return 0 ;
V_111:
F_55 ( V_2 ) ;
return - V_17 ;
}
struct V_42 * F_61 ( struct V_1 * V_2 )
{
struct V_113 * V_4 = V_2 -> V_4 -> V_4 ;
struct V_42 * V_43 ;
int V_62 ;
V_43 = F_62 ( 0 , V_4 ) ;
if ( ! V_43 )
return F_63 ( - V_17 ) ;
V_62 = F_64 ( & V_43 -> V_114 , 256 , 0 ) ;
if ( V_62 )
goto V_115;
V_43 -> V_116 = F_65 ( 1 ) ;
if ( ! V_43 -> V_116 ) {
V_62 = - V_17 ;
goto V_117;
}
V_2 -> V_118 = V_43 ;
return V_43 ;
V_117:
F_66 ( & V_43 -> V_114 ) ;
V_115:
F_67 ( V_43 ) ;
return F_63 ( V_62 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_118 )
F_69 ( V_2 -> V_118 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
if ( V_2 ) {
struct V_42 * V_43 = V_2 -> V_118 ;
if ( V_43 ) {
if ( V_43 -> V_114 . V_119 )
F_66 ( & V_43 -> V_114 ) ;
F_67 ( V_43 ) ;
}
V_2 -> V_118 = NULL ;
}
}
void F_71 ( struct V_1 * V_2 )
{
if ( ! V_8 )
return;
if ( ! F_48 ( & V_2 -> V_107 ) ) {
F_72 ( & V_2 -> V_107 ) ;
if ( F_48 ( & V_84 ) ) {
F_73 ( 'v' , & V_120 ) ;
}
}
F_55 ( V_2 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_118 )
F_75 ( V_2 -> V_118 ) ;
}
T_2 F_76 ( struct V_42 * V_43 , char T_3 * V_121 ,
T_4 V_122 , T_5 * V_123 )
{
return F_77 ( V_43 , V_121 , V_122 , V_123 ) ;
}
T_2 F_78 ( struct V_42 * V_43 , const char T_3 * V_121 ,
T_4 V_122 , T_5 * V_123 )
{
return F_79 ( V_43 , V_121 , V_122 , V_123 ) ;
}
void F_80 ( struct V_42 * V_43 ,
const struct V_124 * V_125 )
{
F_81 ( V_43 , V_125 ) ;
}
void F_82 ( struct V_42 * V_43 ,
const struct V_126 * V_127 )
{
F_83 ( V_43 , V_127 ) ;
}
void F_84 ( struct V_42 * V_43 ,
const struct V_128 * V_129 )
{
F_85 ( V_43 , V_129 ) ;
}
void F_86 ( struct V_42 * V_43 ,
const struct V_124 * V_125 )
{
F_87 ( V_43 , V_125 ) ;
}
void F_88 ( struct V_42 * V_43 ,
const struct V_126 * V_127 )
{
F_89 ( V_43 , V_127 ) ;
}
void F_90 ( struct V_42 * V_43 ,
const struct V_128 * V_129 )
{
F_91 ( V_43 , V_129 ) ;
}
void F_92 ( struct V_1 * V_2 , int V_61 )
{
if ( V_2 && V_2 -> V_118 )
F_93 ( V_2 -> V_118 , V_61 ) ;
}
static int F_94 ( struct V_31 * V_32 , T_6 V_130 , T_6 V_131 ,
T_6 V_132 , T_6 V_133 , struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_52 * V_25 = V_2 -> V_25 ;
int V_134 ;
if ( V_43 -> V_135 . V_136 == V_137 ) {
T_7 * V_138 ;
T_7 V_139 ;
if ( V_133 > 16 )
return - V_27 ;
V_138 = ( T_7 * ) V_43 -> V_140 ;
V_130 >>= ( 16 - V_43 -> V_141 . V_130 . V_142 ) ;
V_131 >>= ( 16 - V_43 -> V_141 . V_131 . V_142 ) ;
V_132 >>= ( 16 - V_43 -> V_141 . V_132 . V_142 ) ;
V_139 = ( V_130 << V_43 -> V_141 . V_130 . V_143 ) |
( V_131 << V_43 -> V_141 . V_131 . V_143 ) |
( V_132 << V_43 -> V_141 . V_132 . V_143 ) ;
if ( V_43 -> V_141 . V_144 . V_142 > 0 ) {
T_7 V_145 = ( 1 << V_43 -> V_141 . V_144 . V_142 ) - 1 ;
V_145 <<= V_43 -> V_141 . V_144 . V_143 ;
V_139 |= V_145 ;
}
V_138 [ V_133 ] = V_139 ;
return 0 ;
}
if ( F_8 ( ! V_2 -> V_37 -> V_41 ||
! V_2 -> V_37 -> V_38 ) )
return - V_27 ;
V_134 = V_133 ;
if ( V_25 -> V_146 == 16 ) {
V_134 = V_133 << 3 ;
if ( V_25 -> V_147 == 16 && V_133 > 63 )
return - V_27 ;
if ( V_25 -> V_147 == 15 && V_133 > 31 )
return - V_27 ;
if ( V_25 -> V_147 == 16 ) {
T_6 V_148 , V_149 , V_150 ;
int V_7 ;
if ( V_133 < 32 ) {
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_2 -> V_37 -> V_41 ( V_32 , V_130 ,
V_131 , V_132 , V_134 + V_7 ) ;
}
V_2 -> V_37 -> V_38 ( V_32 , & V_148 ,
& V_149 , & V_150 ,
V_134 >> 1 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
V_2 -> V_37 -> V_41 ( V_32 , V_148 ,
V_131 , V_150 ,
( V_134 >> 1 ) + V_7 ) ;
}
}
if ( V_25 -> V_147 != 16 )
V_2 -> V_37 -> V_41 ( V_32 , V_130 , V_131 , V_132 , V_134 ) ;
return 0 ;
}
int F_95 ( struct V_151 * V_114 , struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_45 * V_152 ;
T_6 * V_130 , * V_131 , * V_132 , * V_144 ;
struct V_31 * V_32 ;
int V_7 , V_22 , V_153 = 0 ;
int V_154 ;
if ( V_95 )
return - V_96 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return - V_96 ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
V_32 = V_2 -> V_29 [ V_7 ] . V_30 . V_32 ;
V_152 = V_32 -> V_47 ;
V_130 = V_114 -> V_130 ;
V_131 = V_114 -> V_131 ;
V_132 = V_114 -> V_132 ;
V_144 = V_114 -> V_144 ;
V_154 = V_114 -> V_154 ;
for ( V_22 = 0 ; V_22 < V_114 -> V_119 ; V_22 ++ ) {
T_6 V_155 , V_156 , V_157 , V_158 = 0xffff ;
V_155 = * V_130 ++ ;
V_156 = * V_131 ++ ;
V_157 = * V_132 ++ ;
if ( V_144 )
V_158 = * V_144 ++ ;
V_153 = F_94 ( V_32 , V_155 , V_156 , V_157 , V_154 ++ , V_43 ) ;
if ( V_153 )
goto V_159;
}
if ( V_152 -> V_160 )
V_152 -> V_160 ( V_32 ) ;
}
V_159:
F_44 ( V_4 ) ;
return V_153 ;
}
int F_96 ( struct V_161 * V_141 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_52 * V_25 = V_2 -> V_25 ;
int V_147 ;
if ( V_141 -> V_162 != 0 || F_97 () )
return - V_27 ;
if ( V_141 -> V_146 > V_25 -> V_146 ||
V_141 -> V_163 > V_25 -> V_164 || V_141 -> V_165 > V_25 -> V_166 ||
V_141 -> V_167 > V_25 -> V_164 || V_141 -> V_168 > V_25 -> V_166 ) {
F_98 ( L_3
L_4 ,
V_141 -> V_163 , V_141 -> V_165 , V_141 -> V_146 ,
V_141 -> V_167 , V_141 -> V_168 ,
V_25 -> V_164 , V_25 -> V_166 , V_25 -> V_146 ) ;
return - V_27 ;
}
switch ( V_141 -> V_146 ) {
case 16 :
V_147 = ( V_141 -> V_131 . V_142 == 6 ) ? 16 : 15 ;
break;
case 32 :
V_147 = ( V_141 -> V_144 . V_142 > 0 ) ? 32 : 24 ;
break;
default:
V_147 = V_141 -> V_146 ;
break;
}
switch ( V_147 ) {
case 8 :
V_141 -> V_130 . V_143 = 0 ;
V_141 -> V_131 . V_143 = 0 ;
V_141 -> V_132 . V_143 = 0 ;
V_141 -> V_130 . V_142 = 8 ;
V_141 -> V_131 . V_142 = 8 ;
V_141 -> V_132 . V_142 = 8 ;
V_141 -> V_144 . V_142 = 0 ;
V_141 -> V_144 . V_143 = 0 ;
break;
case 15 :
V_141 -> V_130 . V_143 = 10 ;
V_141 -> V_131 . V_143 = 5 ;
V_141 -> V_132 . V_143 = 0 ;
V_141 -> V_130 . V_142 = 5 ;
V_141 -> V_131 . V_142 = 5 ;
V_141 -> V_132 . V_142 = 5 ;
V_141 -> V_144 . V_142 = 1 ;
V_141 -> V_144 . V_143 = 15 ;
break;
case 16 :
V_141 -> V_130 . V_143 = 11 ;
V_141 -> V_131 . V_143 = 5 ;
V_141 -> V_132 . V_143 = 0 ;
V_141 -> V_130 . V_142 = 5 ;
V_141 -> V_131 . V_142 = 6 ;
V_141 -> V_132 . V_142 = 5 ;
V_141 -> V_144 . V_142 = 0 ;
V_141 -> V_144 . V_143 = 0 ;
break;
case 24 :
V_141 -> V_130 . V_143 = 16 ;
V_141 -> V_131 . V_143 = 8 ;
V_141 -> V_132 . V_143 = 0 ;
V_141 -> V_130 . V_142 = 8 ;
V_141 -> V_131 . V_142 = 8 ;
V_141 -> V_132 . V_142 = 8 ;
V_141 -> V_144 . V_142 = 0 ;
V_141 -> V_144 . V_143 = 0 ;
break;
case 32 :
V_141 -> V_130 . V_143 = 16 ;
V_141 -> V_131 . V_143 = 8 ;
V_141 -> V_132 . V_143 = 0 ;
V_141 -> V_130 . V_142 = 8 ;
V_141 -> V_131 . V_142 = 8 ;
V_141 -> V_132 . V_142 = 8 ;
V_141 -> V_144 . V_142 = 8 ;
V_141 -> V_144 . V_143 = 24 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
int F_99 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_161 * V_141 = & V_43 -> V_141 ;
if ( V_95 )
return - V_96 ;
if ( V_141 -> V_162 != 0 ) {
F_21 ( L_5 ) ;
return - V_27 ;
}
F_42 ( V_2 ) ;
return 0 ;
}
static int F_100 ( struct V_161 * V_141 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_60 * V_61 ;
struct V_58 * V_59 ;
int V_7 , V_62 ;
unsigned V_63 ;
V_61 = F_23 ( V_4 ) ;
if ( ! V_61 )
return - V_17 ;
V_61 -> V_64 = V_4 -> V_9 . V_64 ;
V_65:
V_63 = 0 ;
for( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
struct V_20 * V_30 ;
V_30 = & V_2 -> V_29 [ V_7 ] . V_30 ;
V_30 -> V_49 = V_141 -> V_169 ;
V_30 -> V_50 = V_141 -> V_170 ;
V_62 = F_31 ( V_30 , V_61 ) ;
if ( V_62 != 0 )
goto V_14;
V_59 = V_30 -> V_32 -> V_56 ;
V_63 |= ( 1 << F_29 ( V_59 ) ) ;
V_59 -> V_70 = V_59 -> V_25 ;
}
V_62 = F_32 ( V_61 ) ;
if ( V_62 != 0 )
goto V_14;
V_43 -> V_141 . V_169 = V_141 -> V_169 ;
V_43 -> V_141 . V_170 = V_141 -> V_170 ;
V_14:
F_33 ( V_4 , V_63 , V_62 ) ;
if ( V_62 == - V_72 )
goto V_73;
if ( V_62 != 0 )
F_34 ( V_61 ) ;
return V_62 ;
V_73:
F_35 ( V_61 ) ;
F_36 ( V_61 ) ;
goto V_65;
}
int F_101 ( struct V_161 * V_141 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_171 ;
int V_62 = 0 ;
int V_7 ;
if ( V_95 )
return - V_96 ;
F_43 ( V_4 ) ;
if ( ! F_46 ( V_2 ) ) {
F_44 ( V_4 ) ;
return - V_96 ;
}
if ( V_2 -> V_74 ) {
V_62 = F_100 ( V_141 , V_43 ) ;
goto V_172;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
V_171 = & V_2 -> V_29 [ V_7 ] . V_30 ;
V_171 -> V_49 = V_141 -> V_169 ;
V_171 -> V_50 = V_141 -> V_170 ;
if ( V_171 -> V_23 ) {
V_62 = F_41 ( V_171 ) ;
if ( ! V_62 ) {
V_43 -> V_141 . V_169 = V_141 -> V_169 ;
V_43 -> V_141 . V_170 = V_141 -> V_170 ;
}
}
}
V_172:
F_44 ( V_4 ) ;
return V_62 ;
}
static int F_102 ( struct V_1 * V_2 ,
int V_173 )
{
int V_62 = 0 ;
int V_28 = 0 ;
int V_7 ;
struct V_42 * V_43 ;
struct V_174 V_175 ;
int V_40 = 0 ;
memset ( & V_175 , 0 , sizeof( struct V_174 ) ) ;
V_175 . V_176 = 24 ;
V_175 . V_177 = 32 ;
V_175 . V_178 = ( unsigned ) - 1 ;
V_175 . V_179 = ( unsigned ) - 1 ;
if ( V_173 != V_175 . V_177 )
V_175 . V_176 = V_175 . V_177 = V_173 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
struct V_11 * V_180 = V_2 -> V_15 [ V_7 ] ;
struct V_181 * V_182 ;
V_182 = & V_180 -> V_6 -> V_182 ;
if ( V_182 -> V_183 ) {
switch ( V_182 -> V_184 ) {
case 8 :
V_175 . V_176 = V_175 . V_177 = 8 ;
break;
case 15 :
V_175 . V_176 = 15 ;
V_175 . V_177 = 16 ;
break;
case 16 :
V_175 . V_176 = V_175 . V_177 = 16 ;
break;
case 24 :
V_175 . V_176 = V_175 . V_177 = 24 ;
break;
case 32 :
V_175 . V_176 = 24 ;
V_175 . V_177 = 32 ;
break;
}
break;
}
}
V_28 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
struct V_185 * V_186 ;
struct V_20 * V_30 ;
int V_49 , V_50 , V_22 ;
bool V_187 = true , V_188 = true ;
V_186 = V_2 -> V_29 [ V_7 ] . V_186 ;
V_30 = & V_2 -> V_29 [ V_7 ] . V_30 ;
if ( ! V_186 )
continue;
V_28 ++ ;
V_49 = V_2 -> V_29 [ V_7 ] . V_49 ;
V_50 = V_2 -> V_29 [ V_7 ] . V_50 ;
if ( V_40 == 0 )
V_40 = V_2 -> V_29 [ V_7 ] . V_30 . V_32 -> V_40 ;
V_175 . V_189 = F_103 ( T_7 , V_186 -> V_190 + V_49 , V_175 . V_189 ) ;
V_175 . V_191 = F_103 ( T_7 , V_186 -> V_192 + V_50 , V_175 . V_191 ) ;
for ( V_22 = 0 ; V_22 < V_30 -> V_23 ; V_22 ++ ) {
struct V_5 * V_6 = V_30 -> V_24 [ V_22 ] ;
if ( V_6 -> V_193 ) {
V_188 = ( V_6 -> V_194 == ( V_6 -> V_195 - 1 ) ) ;
V_187 = ( V_6 -> V_196 == ( V_6 -> V_197 - 1 ) ) ;
break;
}
}
if ( V_188 )
V_175 . V_178 = F_104 ( T_7 , V_186 -> V_190 + V_49 , V_175 . V_178 ) ;
if ( V_187 )
V_175 . V_179 = F_104 ( T_7 , V_186 -> V_192 + V_50 , V_175 . V_179 ) ;
}
if ( V_28 == 0 || V_175 . V_178 == - 1 || V_175 . V_179 == - 1 ) {
F_105 ( L_6 ) ;
V_175 . V_178 = V_175 . V_189 = 1024 ;
V_175 . V_179 = V_175 . V_191 = 768 ;
}
V_62 = (* V_2 -> V_37 -> V_198 )( V_2 , & V_175 ) ;
if ( V_62 < 0 )
return V_62 ;
V_43 = V_2 -> V_118 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ )
if ( V_2 -> V_29 [ V_7 ] . V_30 . V_23 )
V_2 -> V_29 [ V_7 ] . V_30 . V_25 = V_2 -> V_25 ;
V_43 -> V_141 . V_162 = 0 ;
if ( F_106 ( V_43 ) < 0 )
return - V_27 ;
F_107 ( V_2 -> V_4 -> V_4 , L_7 ,
V_43 -> V_199 , V_43 -> V_135 . V_55 ) ;
if ( F_48 ( & V_84 ) ) {
F_108 ( 'v' , & V_120 ) ;
}
F_109 ( & V_2 -> V_107 , & V_84 ) ;
return 0 ;
}
void F_110 ( struct V_42 * V_43 , T_8 V_200 ,
T_8 V_147 )
{
V_43 -> V_135 . type = V_201 ;
V_43 -> V_135 . V_136 = V_147 == 8 ? V_202 :
V_137 ;
V_43 -> V_135 . V_203 = 0 ;
V_43 -> V_135 . V_204 = 0 ;
V_43 -> V_135 . V_205 = 0 ;
V_43 -> V_135 . V_206 = 1 ;
V_43 -> V_135 . V_207 = 1 ;
V_43 -> V_135 . V_208 = 0 ;
V_43 -> V_135 . V_209 = V_210 ;
V_43 -> V_135 . V_211 = V_200 ;
return;
}
void F_111 ( struct V_42 * V_43 , struct V_1 * V_2 ,
T_8 V_178 , T_8 V_179 )
{
struct V_52 * V_25 = V_2 -> V_25 ;
V_43 -> V_140 = V_2 -> V_140 ;
V_43 -> V_141 . V_167 = V_25 -> V_164 ;
V_43 -> V_141 . V_168 = V_25 -> V_166 ;
V_43 -> V_141 . V_146 = V_25 -> V_146 ;
V_43 -> V_141 . V_212 = V_213 ;
V_43 -> V_141 . V_169 = 0 ;
V_43 -> V_141 . V_170 = 0 ;
V_43 -> V_141 . V_214 = V_215 ;
V_43 -> V_141 . V_166 = - 1 ;
V_43 -> V_141 . V_164 = - 1 ;
switch ( V_25 -> V_147 ) {
case 8 :
V_43 -> V_141 . V_130 . V_143 = 0 ;
V_43 -> V_141 . V_131 . V_143 = 0 ;
V_43 -> V_141 . V_132 . V_143 = 0 ;
V_43 -> V_141 . V_130 . V_142 = 8 ;
V_43 -> V_141 . V_131 . V_142 = 8 ;
V_43 -> V_141 . V_132 . V_142 = 8 ;
V_43 -> V_141 . V_144 . V_143 = 0 ;
V_43 -> V_141 . V_144 . V_142 = 0 ;
break;
case 15 :
V_43 -> V_141 . V_130 . V_143 = 10 ;
V_43 -> V_141 . V_131 . V_143 = 5 ;
V_43 -> V_141 . V_132 . V_143 = 0 ;
V_43 -> V_141 . V_130 . V_142 = 5 ;
V_43 -> V_141 . V_131 . V_142 = 5 ;
V_43 -> V_141 . V_132 . V_142 = 5 ;
V_43 -> V_141 . V_144 . V_143 = 15 ;
V_43 -> V_141 . V_144 . V_142 = 1 ;
break;
case 16 :
V_43 -> V_141 . V_130 . V_143 = 11 ;
V_43 -> V_141 . V_131 . V_143 = 5 ;
V_43 -> V_141 . V_132 . V_143 = 0 ;
V_43 -> V_141 . V_130 . V_142 = 5 ;
V_43 -> V_141 . V_131 . V_142 = 6 ;
V_43 -> V_141 . V_132 . V_142 = 5 ;
V_43 -> V_141 . V_144 . V_143 = 0 ;
break;
case 24 :
V_43 -> V_141 . V_130 . V_143 = 16 ;
V_43 -> V_141 . V_131 . V_143 = 8 ;
V_43 -> V_141 . V_132 . V_143 = 0 ;
V_43 -> V_141 . V_130 . V_142 = 8 ;
V_43 -> V_141 . V_131 . V_142 = 8 ;
V_43 -> V_141 . V_132 . V_142 = 8 ;
V_43 -> V_141 . V_144 . V_143 = 0 ;
V_43 -> V_141 . V_144 . V_142 = 0 ;
break;
case 32 :
V_43 -> V_141 . V_130 . V_143 = 16 ;
V_43 -> V_141 . V_131 . V_143 = 8 ;
V_43 -> V_141 . V_132 . V_143 = 0 ;
V_43 -> V_141 . V_130 . V_142 = 8 ;
V_43 -> V_141 . V_131 . V_142 = 8 ;
V_43 -> V_141 . V_132 . V_142 = 8 ;
V_43 -> V_141 . V_144 . V_143 = 24 ;
V_43 -> V_141 . V_144 . V_142 = 8 ;
break;
default:
break;
}
V_43 -> V_141 . V_163 = V_178 ;
V_43 -> V_141 . V_165 = V_179 ;
}
static int F_112 ( struct V_1 * V_2 ,
T_8 V_216 ,
T_8 V_217 )
{
struct V_5 * V_6 ;
int V_122 = 0 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
V_6 = V_2 -> V_15 [ V_7 ] -> V_6 ;
V_122 += V_6 -> V_37 -> V_218 ( V_6 , V_216 , V_217 ) ;
}
return V_122 ;
}
struct V_185 * F_113 ( struct V_11 * V_219 , int V_164 , int V_166 )
{
struct V_185 * V_26 ;
F_17 (mode, &fb_connector->connector->modes, head) {
if ( V_26 -> V_190 > V_164 ||
V_26 -> V_192 > V_166 )
continue;
if ( V_26 -> type & V_220 )
return V_26 ;
}
return NULL ;
}
static bool F_114 ( struct V_11 * V_219 )
{
return V_219 -> V_6 -> V_182 . V_221 ;
}
struct V_185 * F_115 ( struct V_11 * V_180 ,
int V_164 , int V_166 )
{
struct V_181 * V_182 ;
struct V_185 * V_26 ;
bool V_222 ;
V_182 = & V_180 -> V_6 -> V_182 ;
if ( V_182 -> V_221 == false )
return NULL ;
if ( V_182 -> V_223 || V_182 -> V_224 )
goto V_225;
V_222 = ! V_182 -> V_226 ;
V_227:
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( V_26 -> V_190 != V_182 -> V_163 ||
V_26 -> V_192 != V_182 -> V_165 )
continue;
if ( V_182 -> V_228 ) {
if ( V_26 -> V_229 != V_182 -> V_230 )
continue;
}
if ( V_182 -> V_226 ) {
if ( ! ( V_26 -> V_231 & V_232 ) )
continue;
} else if ( V_222 ) {
if ( V_26 -> V_231 & V_232 )
continue;
}
return V_26 ;
}
if ( V_222 ) {
V_222 = false ;
goto V_227;
}
V_225:
V_26 = F_116 ( V_180 -> V_6 -> V_4 ,
V_182 ) ;
F_109 ( & V_26 -> V_233 , & V_180 -> V_6 -> V_234 ) ;
return V_26 ;
}
static bool F_117 ( struct V_5 * V_6 , bool V_235 )
{
bool V_236 ;
if ( V_235 )
V_236 = V_6 -> V_237 == V_238 ;
else
V_236 = V_6 -> V_237 != V_239 ;
return V_236 ;
}
static void F_118 ( struct V_1 * V_2 ,
bool * V_46 )
{
bool V_240 = false ;
struct V_5 * V_6 ;
int V_7 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
V_6 = V_2 -> V_15 [ V_7 ] -> V_6 ;
V_46 [ V_7 ] = F_117 ( V_6 , true ) ;
F_119 ( L_8 , V_6 -> V_54 . V_55 ,
V_46 [ V_7 ] ? L_9 : L_10 ) ;
V_240 |= V_46 [ V_7 ] ;
}
if ( V_240 )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
V_6 = V_2 -> V_15 [ V_7 ] -> V_6 ;
V_46 [ V_7 ] = F_117 ( V_6 , false ) ;
}
}
static bool F_120 ( struct V_1 * V_2 ,
struct V_185 * * V_234 ,
struct V_241 * V_242 ,
bool * V_46 , int V_164 , int V_166 )
{
int V_122 , V_7 , V_22 ;
bool V_243 = false ;
struct V_11 * V_180 ;
struct V_185 * V_244 , * V_26 ;
if ( V_2 -> V_28 > 1 )
return false ;
V_122 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
if ( V_46 [ V_7 ] )
V_122 ++ ;
}
if ( V_122 <= 1 )
return false ;
V_243 = true ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
if ( ! V_46 [ V_7 ] )
continue;
V_180 = V_2 -> V_15 [ V_7 ] ;
V_234 [ V_7 ] = F_115 ( V_180 , V_164 , V_166 ) ;
if ( ! V_234 [ V_7 ] ) {
V_243 = false ;
break;
}
for ( V_22 = 0 ; V_22 < V_7 ; V_22 ++ ) {
if ( ! V_46 [ V_22 ] )
continue;
if ( ! F_121 ( V_234 [ V_22 ] , V_234 [ V_7 ] ) )
V_243 = false ;
}
}
if ( V_243 ) {
F_119 ( L_11 ) ;
return true ;
}
V_243 = true ;
V_244 = F_122 ( V_2 -> V_4 , 1024 , 768 , 60 , false ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
if ( ! V_46 [ V_7 ] )
continue;
V_180 = V_2 -> V_15 [ V_7 ] ;
F_17 (mode, &fb_helper_conn->connector->modes, head) {
if ( F_121 ( V_26 , V_244 ) )
V_234 [ V_7 ] = V_26 ;
}
if ( ! V_234 [ V_7 ] )
V_243 = false ;
}
if ( V_243 ) {
F_119 ( L_12 ) ;
return true ;
}
F_105 ( L_13 ) ;
return false ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_185 * * V_234 ,
struct V_241 * V_242 ,
int V_245 ,
int V_246 , int V_247 )
{
struct V_11 * V_180 ;
int V_7 ;
int V_248 = 0 , V_249 = 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
V_180 = V_2 -> V_15 [ V_7 ] ;
if ( ! V_180 -> V_6 -> V_193 )
continue;
if ( ! V_234 [ V_7 ] && ( V_246 || V_247 ) ) {
F_119 ( L_14 , V_7 ,
V_180 -> V_6 -> V_54 . V_55 ) ;
continue;
}
if ( V_180 -> V_6 -> V_194 < V_246 )
V_248 += V_234 [ V_7 ] -> V_190 ;
if ( V_180 -> V_6 -> V_196 < V_247 )
V_249 += V_234 [ V_7 ] -> V_192 ;
}
V_242 [ V_245 ] . V_49 = V_248 ;
V_242 [ V_245 ] . V_50 = V_249 ;
F_119 ( L_15 , V_248 , V_249 , V_246 , V_247 ) ;
return 0 ;
}
static bool F_124 ( struct V_1 * V_2 ,
struct V_185 * * V_234 ,
struct V_241 * V_242 ,
bool * V_46 , int V_164 , int V_166 )
{
struct V_11 * V_180 ;
int V_7 ;
T_9 V_250 = 0 , V_145 ;
int V_251 = 0 ;
V_145 = ( 1 << V_2 -> V_16 ) - 1 ;
V_65:
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
V_180 = V_2 -> V_15 [ V_7 ] ;
if ( V_250 & ( 1 << V_7 ) )
continue;
if ( V_46 [ V_7 ] == false ) {
V_250 |= ( 1 << V_7 ) ;
continue;
}
if ( V_251 == 0 && V_180 -> V_6 -> V_193 )
continue;
if ( V_251 == 1 ) {
if ( V_180 -> V_6 -> V_194 != 0 ||
V_180 -> V_6 -> V_196 != 0 )
continue;
} else {
if ( V_180 -> V_6 -> V_194 != V_251 - 1 &&
V_180 -> V_6 -> V_196 != V_251 - 1 )
continue;
F_123 ( V_2 , V_234 , V_242 ,
V_7 , V_180 -> V_6 -> V_194 , V_180 -> V_6 -> V_196 ) ;
}
F_119 ( L_16 ,
V_180 -> V_6 -> V_54 . V_55 ) ;
V_234 [ V_7 ] = F_115 ( V_180 , V_164 , V_166 ) ;
if ( ! V_234 [ V_7 ] ) {
F_119 ( L_17 ,
V_180 -> V_6 -> V_54 . V_55 , V_180 -> V_6 -> V_252 ? V_180 -> V_6 -> V_252 -> V_55 : 0 ) ;
V_234 [ V_7 ] = F_113 ( V_180 , V_164 , V_166 ) ;
}
if ( ! V_234 [ V_7 ] && ! F_48 ( & V_180 -> V_6 -> V_234 ) ) {
F_17 (modes[i], &fb_helper_conn->connector->modes, head)
break;
}
F_119 ( L_18 , V_234 [ V_7 ] ? V_234 [ V_7 ] -> V_253 :
L_19 ) ;
V_250 |= ( 1 << V_7 ) ;
}
if ( ( V_250 & V_145 ) != V_145 ) {
V_251 ++ ;
goto V_65;
}
return true ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_109 * * V_254 ,
struct V_185 * * V_234 ,
int V_255 , int V_164 , int V_166 )
{
int V_53 , V_256 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
const struct V_257 * V_258 ;
struct V_259 * V_260 ;
int V_261 , V_262 , V_263 ;
struct V_109 * * V_264 , * V_32 ;
struct V_11 * V_180 ;
if ( V_255 == V_2 -> V_16 )
return 0 ;
V_180 = V_2 -> V_15 [ V_255 ] ;
V_6 = V_180 -> V_6 ;
V_254 [ V_255 ] = NULL ;
V_262 = F_125 ( V_2 , V_254 , V_234 , V_255 + 1 , V_164 , V_166 ) ;
if ( V_234 [ V_255 ] == NULL )
return V_262 ;
V_264 = F_4 ( V_4 -> V_9 . V_110 *
sizeof( struct V_109 * ) , V_13 ) ;
if ( ! V_264 )
return V_262 ;
V_261 = 1 ;
if ( V_6 -> V_237 == V_238 )
V_261 ++ ;
if ( F_114 ( V_180 ) )
V_261 ++ ;
if ( F_113 ( V_180 , V_164 , V_166 ) )
V_261 ++ ;
V_258 = V_6 -> V_47 ;
V_260 = V_258 -> V_265 ( V_6 ) ;
if ( ! V_260 )
goto V_159;
for ( V_53 = 0 ; V_53 < V_2 -> V_28 ; V_53 ++ ) {
V_32 = & V_2 -> V_29 [ V_53 ] ;
if ( ( V_260 -> V_266 & ( 1 << V_53 ) ) == 0 )
continue;
for ( V_256 = 0 ; V_256 < V_255 ; V_256 ++ )
if ( V_254 [ V_256 ] == V_32 )
break;
if ( V_256 < V_255 ) {
if ( V_2 -> V_28 > 1 )
continue;
if ( ! F_121 ( V_234 [ V_256 ] , V_234 [ V_255 ] ) )
continue;
}
V_264 [ V_255 ] = V_32 ;
memcpy ( V_264 , V_254 , V_255 * sizeof( struct V_109 * ) ) ;
V_263 = V_261 + F_125 ( V_2 , V_264 , V_234 , V_255 + 1 ,
V_164 , V_166 ) ;
if ( V_263 > V_262 ) {
V_262 = V_263 ;
memcpy ( V_254 , V_264 ,
V_4 -> V_9 . V_110 *
sizeof( struct V_109 * ) ) ;
}
}
V_159:
F_6 ( V_264 ) ;
return V_262 ;
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_109 * * V_264 ;
struct V_185 * * V_234 ;
struct V_241 * V_242 ;
struct V_20 * V_171 ;
bool * V_46 ;
int V_164 , V_166 ;
int V_7 ;
F_119 ( L_20 ) ;
V_164 = V_4 -> V_9 . V_267 ;
V_166 = V_4 -> V_9 . V_268 ;
V_264 = F_59 ( V_4 -> V_9 . V_110 ,
sizeof( struct V_109 * ) , V_13 ) ;
V_234 = F_59 ( V_4 -> V_9 . V_110 ,
sizeof( struct V_185 * ) , V_13 ) ;
V_242 = F_59 ( V_4 -> V_9 . V_110 ,
sizeof( struct V_241 ) , V_13 ) ;
V_46 = F_59 ( V_4 -> V_9 . V_110 ,
sizeof( bool ) , V_13 ) ;
if ( ! V_264 || ! V_234 || ! V_46 || ! V_242 ) {
F_21 ( L_21 ) ;
goto V_159;
}
F_118 ( V_2 , V_46 ) ;
if ( ! ( V_2 -> V_37 -> V_269 &&
V_2 -> V_37 -> V_269 ( V_2 , V_264 , V_234 ,
V_242 ,
V_46 , V_164 , V_166 ) ) ) {
memset ( V_234 , 0 , V_4 -> V_9 . V_110 * sizeof( V_234 [ 0 ] ) ) ;
memset ( V_264 , 0 , V_4 -> V_9 . V_110 * sizeof( V_264 [ 0 ] ) ) ;
memset ( V_242 , 0 , V_4 -> V_9 . V_110 * sizeof( V_242 [ 0 ] ) ) ;
if ( ! F_120 ( V_2 , V_234 , V_242 ,
V_46 , V_164 , V_166 ) &&
! F_124 ( V_2 , V_234 , V_242 ,
V_46 , V_164 , V_166 ) )
F_21 ( L_22 ) ;
F_119 ( L_23 ,
V_164 , V_166 ) ;
F_125 ( V_2 , V_264 , V_234 , 0 , V_164 , V_166 ) ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
V_171 = & V_2 -> V_29 [ V_7 ] . V_30 ;
V_171 -> V_23 = 0 ;
V_171 -> V_25 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_16 ; V_7 ++ ) {
struct V_185 * V_26 = V_234 [ V_7 ] ;
struct V_109 * V_270 = V_264 [ V_7 ] ;
struct V_241 * V_143 = & V_242 [ V_7 ] ;
V_171 = & V_270 -> V_30 ;
if ( V_26 && V_270 ) {
F_119 ( L_24 ,
V_26 -> V_253 , V_270 -> V_30 . V_32 -> V_54 . V_55 , V_143 -> V_49 , V_143 -> V_50 ) ;
V_270 -> V_186 = V_26 ;
V_270 -> V_49 = V_143 -> V_49 ;
V_270 -> V_50 = V_143 -> V_50 ;
if ( V_171 -> V_26 )
F_12 ( V_4 , V_171 -> V_26 ) ;
V_171 -> V_26 = F_127 ( V_4 ,
V_270 -> V_186 ) ;
V_171 -> V_24 [ V_171 -> V_23 ++ ] = V_2 -> V_15 [ V_7 ] -> V_6 ;
V_171 -> V_25 = V_2 -> V_25 ;
V_171 -> V_49 = V_143 -> V_49 ;
V_171 -> V_50 = V_143 -> V_50 ;
}
}
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
V_171 = & V_2 -> V_29 [ V_7 ] . V_30 ;
if ( V_171 -> V_23 == 0 ) {
F_128 ( V_171 -> V_25 ) ;
if ( V_171 -> V_26 )
F_12 ( V_4 , V_171 -> V_26 ) ;
V_171 -> V_26 = NULL ;
}
}
V_159:
F_6 ( V_264 ) ;
F_6 ( V_234 ) ;
F_6 ( V_242 ) ;
F_6 ( V_46 ) ;
}
int F_129 ( struct V_1 * V_2 , int V_271 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_122 = 0 ;
if ( ! V_8 )
return 0 ;
F_2 ( & V_4 -> V_9 . V_10 ) ;
V_122 = F_112 ( V_2 ,
V_4 -> V_9 . V_267 ,
V_4 -> V_9 . V_268 ) ;
F_5 ( & V_4 -> V_9 . V_10 ) ;
if ( V_122 == 0 )
F_107 ( V_2 -> V_4 -> V_4 , L_25 ) ;
F_126 ( V_2 ) ;
return F_102 ( V_2 , V_271 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_7 V_267 , V_268 ;
if ( ! V_8 )
return 0 ;
F_2 ( & V_2 -> V_4 -> V_9 . V_10 ) ;
if ( ! V_2 -> V_25 || ! F_46 ( V_2 ) ) {
V_2 -> V_80 = true ;
F_5 ( & V_2 -> V_4 -> V_9 . V_10 ) ;
return 0 ;
}
F_119 ( L_20 ) ;
V_267 = V_2 -> V_25 -> V_164 ;
V_268 = V_2 -> V_25 -> V_166 ;
F_112 ( V_2 , V_267 , V_268 ) ;
F_5 ( & V_2 -> V_4 -> V_9 . V_10 ) ;
F_43 ( V_4 ) ;
F_126 ( V_2 ) ;
F_44 ( V_4 ) ;
F_99 ( V_2 -> V_118 ) ;
return 0 ;
}
static int T_10 F_130 ( void )
{
const char * V_253 = L_26 ;
struct V_272 * V_273 ;
F_2 ( & V_274 ) ;
V_273 = F_131 ( V_253 ) ;
F_5 ( & V_274 ) ;
if ( ! V_273 )
F_132 ( V_253 ) ;
return 0 ;
}
