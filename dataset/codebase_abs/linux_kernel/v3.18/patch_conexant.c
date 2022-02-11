static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
int V_4 , int V_5 )
{
V_2 -> V_6 . V_7 = V_3 ;
V_2 -> V_8 = F_2 ( V_3 , 1 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_11 ;
if ( V_2 -> V_8 ) {
const struct V_12 * V_13 ;
for ( V_13 = V_14 ; V_13 -> V_15 ; V_13 ++ ) {
struct V_16 * V_17 ;
V_17 = F_4 ( V_13 , V_10 ) ;
if ( ! V_17 )
return - V_18 ;
V_17 -> V_19 = V_2 -> V_8 ;
V_11 = F_5 ( V_10 , 0 , V_17 ) ;
if ( V_11 < 0 )
return V_11 ;
}
}
return 0 ;
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 , V_20 ;
V_20 = V_10 -> V_21 + V_10 -> V_22 ;
for ( V_3 = V_10 -> V_21 ; V_3 < V_20 ; V_3 ++ )
if ( F_7 ( F_8 ( V_10 , V_3 ) ) == V_23 ) {
F_1 ( V_2 , V_3 , 0 , V_24 ) ;
break;
}
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 , V_20 ;
V_20 = V_10 -> V_21 + V_10 -> V_22 ;
for ( V_3 = V_10 -> V_21 ; V_3 < V_20 ; V_3 ++ ) {
if ( F_7 ( F_8 ( V_10 , V_3 ) ) != V_25 )
continue;
if ( ! ( F_10 ( V_10 , V_3 ) & V_26 ) )
continue;
V_2 -> V_27 [ V_2 -> V_28 ++ ] = V_3 ;
if ( V_2 -> V_28 >= F_11 ( V_2 -> V_27 ) )
break;
}
if ( V_2 -> V_28 > 2 )
V_2 -> V_29 = 1 ;
}
static void F_12 ( struct V_9 * V_10 , int V_30 ,
T_1 * V_31 , bool V_32 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_30 ; V_33 ++ ) {
if ( F_10 ( V_10 , V_31 [ V_33 ] ) & V_26 )
F_13 ( V_10 , V_31 [ V_33 ] , 0 ,
V_34 ,
V_32 ? 0x02 : 0 ) ;
}
}
static void F_14 ( void * V_35 , int V_36 )
{
struct V_9 * V_10 = V_35 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_12 ( V_10 , V_2 -> V_28 , V_2 -> V_27 , V_36 ) ;
}
static void F_15 ( void * V_35 , int V_36 )
{
struct V_9 * V_10 = V_35 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_13 ( V_10 , V_2 -> V_37 , 0 ,
V_34 ,
V_36 ? 0x00 : 0x02 ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_17 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_19 ( V_10 ) ;
if ( ! V_2 -> V_29 )
F_12 ( V_10 , V_2 -> V_28 , V_2 -> V_27 , true ) ;
F_20 ( V_10 , V_38 ) ;
return 0 ;
}
static void F_21 ( struct V_9 * V_10 ,
const struct V_39 * V_40 , int V_41 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_6 . V_42 = 1 ;
}
static void F_22 ( struct V_9 * V_10 ,
const struct V_39 * V_40 , int V_41 )
{
if ( V_41 != V_43 )
return;
F_23 ( V_10 , 0x17 , V_24 ,
( 0x3 << V_44 ) |
( 0x4 << V_45 ) |
( 0x27 << V_46 ) |
( 0 << V_47 ) ) ;
}
static void F_24 ( struct V_9 * V_10 )
{
int V_33 ;
bool V_48 = false ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_49 * V_50 = & V_2 -> V_6 . V_51 ;
T_1 V_52 = V_2 -> V_6 . V_53 [ V_2 -> V_6 . V_54 [ 0 ] ] ;
for ( V_33 = 0 ; V_33 < V_50 -> V_55 ; V_33 ++ )
if ( V_50 -> V_56 [ V_33 ] . V_57 == V_52 ) {
V_48 = ! ! V_50 -> V_56 [ V_33 ] . V_58 ;
break;
}
if ( V_48 ) {
F_25 ( V_10 , 0x1c , 0 , 0x410 , 0x7c ) ;
V_2 -> V_6 . V_59 = false ;
} else {
F_25 ( V_10 , 0x1c , 0 , 0x410 , 0x54 ) ;
V_2 -> V_6 . V_59 = F_26 ( V_10 , V_2 -> V_6 . V_51 . V_60 [ 0 ] ) ;
}
F_27 ( V_10 ) ;
}
static void F_28 ( struct V_9 * V_10 ,
struct V_16 * V_61 ,
struct V_62 * V_63 )
{
F_24 ( V_10 ) ;
}
static void F_29 ( struct V_9 * V_10 ,
const struct V_39 * V_40 , int V_41 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_41 ) {
case V_43 :
V_2 -> V_64 |= V_65 ;
break;
case V_66 :
V_2 -> V_6 . V_67 = F_28 ;
V_2 -> V_6 . V_68 = F_24 ;
break;
case V_38 :
F_24 ( V_10 ) ;
break;
}
}
static void F_30 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_69 , V_70 ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
V_70 = V_71 |
( V_69 ? V_72 : V_73 ) ;
if ( ! V_2 -> V_74 )
V_70 |= F_31 ( V_10 , 0x17 , V_69 , V_24 , 0 ) ;
F_13 ( V_10 , 0x17 , 0 ,
V_75 , V_70 ) ;
}
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_76 , V_70 ;
struct V_77 * V_78 ;
V_76 = V_2 -> V_6 . V_79 [ 0 ] [ V_2 -> V_6 . V_54 [ 0 ] ] ;
if ( ! V_2 -> V_74 ) {
F_33 ( V_10 , 0x1e , 0 ) ;
F_34 ( V_10 , V_2 -> V_80 , false , false ) ;
F_33 ( V_10 , 0x1a , V_2 -> V_81 ?
F_35 ( V_10 , 0x1a ) : 0 ) ;
F_33 ( V_10 , 0x1b , V_2 -> V_81 ?
F_35 ( V_10 , 0x1b ) : 0 ) ;
V_78 = F_36 ( V_10 , V_76 ) ;
if ( V_78 )
F_34 ( V_10 , V_78 , true , false ) ;
} else {
V_78 = F_36 ( V_10 , V_76 ) ;
if ( V_78 )
F_34 ( V_10 , V_78 , false , false ) ;
if ( V_2 -> V_81 )
V_70 = V_82 . V_83 [ V_2 -> V_84 ] . V_85 ;
else
V_70 = 0 ;
F_33 ( V_10 , 0x1a , V_70 ) ;
F_33 ( V_10 , 0x1b , 0 ) ;
F_33 ( V_10 , 0x1e , V_2 -> V_81 ? V_86 : 0 ) ;
F_34 ( V_10 , V_2 -> V_80 , true , false ) ;
}
}
static void F_37 ( struct V_9 * V_10 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_89 = V_10 -> V_90 ;
V_10 -> V_90 = 1 ;
if ( ! V_2 -> V_74 )
F_38 ( V_10 , V_88 ) ;
F_32 ( V_10 ) ;
F_39 ( V_10 ) ;
V_10 -> V_90 = V_89 ;
if ( V_2 -> V_74 )
F_30 ( V_10 ) ;
}
static void F_40 ( struct V_91 * V_92 ,
struct V_9 * V_10 ,
struct V_93 * V_94 ,
int V_41 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_41 ) {
case V_95 :
V_2 -> V_81 = 1 ;
F_32 ( V_10 ) ;
break;
case V_96 :
V_2 -> V_81 = 0 ;
F_32 ( V_10 ) ;
break;
}
}
static int F_41 ( struct V_16 * V_61 ,
struct V_62 * V_63 )
{
struct V_9 * V_10 = F_42 ( V_61 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_63 -> V_97 . integer . V_97 [ 0 ] = V_2 -> V_74 ;
return 0 ;
}
static int F_43 ( struct V_16 * V_61 ,
struct V_62 * V_63 )
{
struct V_9 * V_10 = F_42 ( V_61 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_74 = ! ! V_63 -> V_97 . integer . V_97 [ 0 ] ;
if ( V_74 == V_2 -> V_74 )
return 0 ;
V_2 -> V_74 = V_74 ;
F_32 ( V_10 ) ;
F_30 ( V_10 ) ;
return 1 ;
}
static int F_44 ( struct V_16 * V_61 ,
struct V_62 * V_63 )
{
struct V_9 * V_10 = F_42 ( V_61 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_63 -> V_97 . V_98 . V_99 [ 0 ] = V_2 -> V_84 ;
return 0 ;
}
static int F_45 ( struct V_16 * V_61 ,
struct V_100 * V_101 )
{
return F_46 ( & V_82 , V_101 ) ;
}
static int F_47 ( struct V_16 * V_61 ,
struct V_62 * V_63 )
{
struct V_9 * V_10 = F_42 ( V_61 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_102 * V_103 = & V_82 ;
unsigned int V_4 ;
V_4 = V_63 -> V_97 . V_98 . V_99 [ 0 ] ;
if ( V_4 >= V_103 -> V_104 )
V_4 = V_103 -> V_104 - 1 ;
if ( V_2 -> V_84 == V_4 )
return 0 ;
V_2 -> V_84 = V_4 ;
if ( V_2 -> V_74 )
F_32 ( V_10 ) ;
return 1 ;
}
static int F_48 ( struct V_16 * V_61 ,
struct V_62 * V_63 )
{
struct V_9 * V_10 = F_42 ( V_61 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_105 = F_49 ( V_61 , V_63 ) ;
if ( V_105 > 0 && V_2 -> V_74 )
F_30 ( V_10 ) ;
return V_105 ;
}
static void F_50 ( struct V_9 * V_10 ,
const struct V_39 * V_40 , int V_41 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_33 ;
if ( V_41 != V_66 )
return;
V_2 -> V_6 . V_106 = F_37 ;
V_2 -> V_6 . V_107 = F_40 ;
V_2 -> V_80 = F_51 ( V_10 , 0x1e , 0x14 , 0 ) ;
F_52 ( V_10 , V_108 ) ;
F_53 ( V_10 , 0x1a , V_109 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_6 . V_110 . V_111 ; V_33 ++ ) {
struct V_12 * V_17 =
F_54 ( & V_2 -> V_6 . V_110 , V_33 ) ;
if ( ! strcmp ( V_17 -> V_15 , L_1 ) ) {
V_17 -> V_112 = F_48 ;
break;
}
}
}
static void F_55 ( struct V_9 * V_10 ,
const struct V_39 * V_40 , int V_41 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_41 == V_43 ) {
V_2 -> V_37 = 0x1b ;
V_2 -> V_29 = 1 ;
V_2 -> V_6 . V_113 . V_114 = F_15 ;
}
}
static void F_56 ( struct V_9 * V_10 ,
const struct V_39 * V_40 , int V_41 )
{
F_23 ( V_10 , 0x17 , V_115 ,
( 0x14 << V_44 ) |
( 0x14 << V_45 ) |
( 0x05 << V_46 ) |
( 1 << V_47 ) ) ;
}
static void F_57 ( struct V_9 * V_10 ,
const struct V_39 * V_40 , int V_41 )
{
F_23 ( V_10 , 0x10 , V_115 ,
( 0x17 << V_44 ) |
( 0x17 << V_45 ) |
( 0x05 << V_46 ) |
( 1 << V_47 ) ) ;
}
static void F_58 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
static T_1 V_116 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_117 ;
for ( V_117 = V_116 ; * V_117 ; V_117 ++ )
F_23 ( V_10 , * V_117 , V_24 ,
V_118 |
F_59 ( V_10 , * V_117 , V_24 ) ) ;
V_2 -> V_6 . V_119 = true ;
}
static int F_60 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
F_61 ( V_10 , L_2 , V_10 -> V_120 ) ;
V_2 = F_62 ( sizeof( * V_2 ) , V_121 ) ;
if ( ! V_2 )
return - V_18 ;
F_63 ( & V_2 -> V_6 ) ;
V_10 -> V_2 = V_2 ;
F_6 ( V_10 ) ;
F_9 ( V_10 ) ;
V_2 -> V_6 . V_122 = 1 ;
if ( V_2 -> V_29 )
V_2 -> V_6 . V_113 . V_114 = F_14 ;
switch ( V_10 -> V_123 ) {
case 0x14f15045 :
V_10 -> V_124 = 1 ;
V_2 -> V_6 . V_125 = 0x17 ;
V_2 -> V_6 . V_126 = 1 ;
F_64 ( V_10 , V_127 ,
V_128 , V_129 ) ;
break;
case 0x14f15047 :
V_10 -> V_130 = 1 ;
V_2 -> V_6 . V_125 = 0x19 ;
V_2 -> V_6 . V_126 = 1 ;
F_64 ( V_10 , V_131 ,
V_132 , V_129 ) ;
break;
case 0x14f15051 :
F_58 ( V_10 ) ;
V_10 -> V_130 = 1 ;
F_64 ( V_10 , V_133 ,
V_134 , V_129 ) ;
break;
default:
V_10 -> V_130 = 1 ;
F_64 ( V_10 , V_135 ,
V_136 , V_129 ) ;
break;
}
switch ( V_10 -> V_137 >> 16 ) {
case 0x103c :
V_2 -> V_6 . V_138 = 1 ;
break;
}
F_20 ( V_10 , V_43 ) ;
V_11 = F_65 ( V_10 , & V_2 -> V_6 . V_51 , NULL ,
V_2 -> V_64 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_66 ( V_10 , & V_2 -> V_6 . V_51 ) ;
if ( V_11 < 0 )
goto error;
V_10 -> V_139 = V_140 ;
if ( ! V_10 -> V_141 -> V_142 ) {
F_61 ( V_10 ,
L_3 ) ;
V_10 -> V_141 -> V_142 = 1 ;
V_10 -> V_141 -> V_143 = 1 ;
}
F_20 ( V_10 , V_66 ) ;
return 0 ;
error:
F_67 ( V_10 ) ;
return V_11 ;
}
static int T_2 F_68 ( void )
{
return F_69 ( & V_144 ) ;
}
static void T_3 F_70 ( void )
{
F_71 ( & V_144 ) ;
}
