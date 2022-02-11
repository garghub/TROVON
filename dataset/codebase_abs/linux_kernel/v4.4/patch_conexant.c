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
T_1 V_3 ;
F_7 (nid, codec)
if ( F_8 ( F_9 ( V_10 , V_3 ) ) == V_20 ) {
F_1 ( V_2 , V_3 , 0 , V_21 ) ;
break;
}
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 ;
F_7 (nid, codec) {
if ( F_8 ( F_9 ( V_10 , V_3 ) ) != V_22 )
continue;
if ( ! ( F_11 ( V_10 , V_3 ) & V_23 ) )
continue;
V_2 -> V_24 [ V_2 -> V_25 ++ ] = V_3 ;
if ( V_2 -> V_25 >= F_12 ( V_2 -> V_24 ) )
break;
}
if ( V_2 -> V_25 > 2 )
V_2 -> V_26 = 1 ;
}
static void F_13 ( struct V_9 * V_10 , int V_27 ,
T_1 * V_28 , bool V_29 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ ) {
if ( F_11 ( V_10 , V_28 [ V_30 ] ) & V_23 )
F_14 ( V_10 , V_28 [ V_30 ] , 0 ,
V_31 ,
V_29 ? 0x02 : 0 ) ;
}
}
static void F_15 ( void * V_32 , int V_33 )
{
struct V_9 * V_10 = V_32 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_13 ( V_10 , V_2 -> V_25 , V_2 -> V_24 , V_33 ) ;
}
static void F_16 ( void * V_32 , int V_33 )
{
struct V_9 * V_10 = V_32 ;
struct V_1 * V_2 = V_10 -> V_2 ;
F_14 ( V_10 , V_2 -> V_34 , 0 ,
V_31 ,
V_33 ? 0x00 : 0x02 ) ;
}
static int F_17 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_18 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_20 ( V_10 ) ;
if ( ! V_2 -> V_26 )
F_13 ( V_10 , V_2 -> V_25 , V_2 -> V_24 , true ) ;
F_21 ( V_10 , V_35 ) ;
return 0 ;
}
static void F_22 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_10 -> V_36 . V_37 != 0x14f150f2 )
return;
F_13 ( V_10 , V_2 -> V_25 , V_2 -> V_24 , false ) ;
F_23 ( V_10 , V_10 -> V_36 . V_38 , V_39 ) ;
F_14 ( V_10 , V_10 -> V_36 . V_38 , 0 ,
V_40 , V_39 ) ;
}
static void F_24 ( struct V_9 * V_10 )
{
F_22 ( V_10 ) ;
F_25 ( V_10 ) ;
}
static void F_26 ( struct V_9 * V_10 ,
const struct V_41 * V_42 , int V_43 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_6 . V_44 = 1 ;
}
static void F_27 ( struct V_9 * V_10 ,
const struct V_41 * V_42 , int V_43 )
{
if ( V_43 != V_45 )
return;
F_28 ( V_10 , 0x17 , V_21 ,
( 0x3 << V_46 ) |
( 0x4 << V_47 ) |
( 0x27 << V_48 ) |
( 0 << V_49 ) ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
int V_30 ;
bool V_50 = false ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_51 * V_52 = & V_2 -> V_6 . V_53 ;
T_1 V_54 = V_2 -> V_6 . V_55 [ V_2 -> V_6 . V_56 [ 0 ] ] ;
for ( V_30 = 0 ; V_30 < V_52 -> V_57 ; V_30 ++ )
if ( V_52 -> V_58 [ V_30 ] . V_59 == V_54 ) {
V_50 = ! ! V_52 -> V_58 [ V_30 ] . V_60 ;
break;
}
if ( V_50 ) {
F_30 ( V_10 , 0x1c , 0 , 0x410 , 0x7c ) ;
V_2 -> V_6 . V_61 = false ;
} else {
F_30 ( V_10 , 0x1c , 0 , 0x410 , 0x54 ) ;
V_2 -> V_6 . V_61 = F_31 ( V_10 , V_2 -> V_6 . V_53 . V_62 [ 0 ] ) ;
}
F_32 ( V_10 ) ;
}
static void F_33 ( struct V_9 * V_10 ,
struct V_16 * V_63 ,
struct V_64 * V_65 )
{
F_29 ( V_10 ) ;
}
static void F_34 ( struct V_9 * V_10 ,
const struct V_41 * V_42 , int V_43 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_43 ) {
case V_45 :
V_2 -> V_66 |= V_67 ;
F_35 ( & V_10 -> V_36 , 0x410 ) ;
break;
case V_68 :
V_2 -> V_6 . V_69 = F_33 ;
V_2 -> V_6 . V_70 = F_29 ;
break;
case V_35 :
F_29 ( V_10 ) ;
break;
}
}
static void F_36 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_71 , V_72 ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_72 = V_73 |
( V_71 ? V_74 : V_75 ) ;
if ( ! V_2 -> V_76 )
V_72 |= F_37 ( V_10 , 0x17 , V_71 , V_21 , 0 ) ;
F_14 ( V_10 , 0x17 , 0 ,
V_77 , V_72 ) ;
}
}
static void F_38 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_78 , V_72 ;
struct V_79 * V_80 ;
V_78 = V_2 -> V_6 . V_81 [ 0 ] [ V_2 -> V_6 . V_56 [ 0 ] ] ;
if ( ! V_2 -> V_76 ) {
F_39 ( V_10 , 0x1e , 0 ) ;
F_40 ( V_10 , V_2 -> V_82 , false , false ) ;
F_39 ( V_10 , 0x1a , V_2 -> V_83 ?
F_41 ( V_10 , 0x1a ) : 0 ) ;
F_39 ( V_10 , 0x1b , V_2 -> V_83 ?
F_41 ( V_10 , 0x1b ) : 0 ) ;
V_80 = F_42 ( V_10 , V_78 ) ;
if ( V_80 )
F_40 ( V_10 , V_80 , true , false ) ;
} else {
V_80 = F_42 ( V_10 , V_78 ) ;
if ( V_80 )
F_40 ( V_10 , V_80 , false , false ) ;
if ( V_2 -> V_83 )
V_72 = V_84 . V_85 [ V_2 -> V_86 ] . V_87 ;
else
V_72 = 0 ;
F_39 ( V_10 , 0x1a , V_72 ) ;
F_39 ( V_10 , 0x1b , 0 ) ;
F_39 ( V_10 , 0x1e , V_2 -> V_83 ? V_88 : 0 ) ;
F_40 ( V_10 , V_2 -> V_82 , true , false ) ;
}
}
static void F_43 ( struct V_9 * V_10 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( ! V_2 -> V_76 )
F_44 ( V_10 , V_90 ) ;
F_38 ( V_10 ) ;
if ( V_2 -> V_76 )
F_36 ( V_10 ) ;
}
static void F_45 ( struct V_91 * V_92 ,
struct V_9 * V_10 ,
struct V_93 * V_94 ,
int V_43 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_43 ) {
case V_95 :
V_2 -> V_83 = 1 ;
F_38 ( V_10 ) ;
break;
case V_96 :
V_2 -> V_83 = 0 ;
F_38 ( V_10 ) ;
break;
}
}
static int F_46 ( struct V_16 * V_63 ,
struct V_64 * V_65 )
{
struct V_9 * V_10 = F_47 ( V_63 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_65 -> V_97 . integer . V_97 [ 0 ] = V_2 -> V_76 ;
return 0 ;
}
static int F_48 ( struct V_16 * V_63 ,
struct V_64 * V_65 )
{
struct V_9 * V_10 = F_47 ( V_63 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_76 = ! ! V_65 -> V_97 . integer . V_97 [ 0 ] ;
if ( V_76 == V_2 -> V_76 )
return 0 ;
V_2 -> V_76 = V_76 ;
F_38 ( V_10 ) ;
F_36 ( V_10 ) ;
return 1 ;
}
static int F_49 ( struct V_16 * V_63 ,
struct V_64 * V_65 )
{
struct V_9 * V_10 = F_47 ( V_63 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_65 -> V_97 . V_98 . V_99 [ 0 ] = V_2 -> V_86 ;
return 0 ;
}
static int F_50 ( struct V_16 * V_63 ,
struct V_100 * V_101 )
{
return F_51 ( & V_84 , V_101 ) ;
}
static int F_52 ( struct V_16 * V_63 ,
struct V_64 * V_65 )
{
struct V_9 * V_10 = F_47 ( V_63 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_102 * V_103 = & V_84 ;
unsigned int V_4 ;
V_4 = V_65 -> V_97 . V_98 . V_99 [ 0 ] ;
if ( V_4 >= V_103 -> V_104 )
V_4 = V_103 -> V_104 - 1 ;
if ( V_2 -> V_86 == V_4 )
return 0 ;
V_2 -> V_86 = V_4 ;
if ( V_2 -> V_76 )
F_38 ( V_10 ) ;
return 1 ;
}
static int F_53 ( struct V_16 * V_63 ,
struct V_64 * V_65 )
{
struct V_9 * V_10 = F_47 ( V_63 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_105 = F_54 ( V_63 , V_65 ) ;
if ( V_105 > 0 && V_2 -> V_76 )
F_36 ( V_10 ) ;
return V_105 ;
}
static void F_55 ( struct V_9 * V_10 ,
const struct V_41 * V_42 , int V_43 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_30 ;
if ( V_43 != V_68 )
return;
V_2 -> V_6 . V_106 = F_43 ;
V_2 -> V_6 . V_107 = F_45 ;
V_2 -> V_82 = F_56 ( V_10 , 0x1e , 0x14 , 0 ) ;
F_57 ( V_10 , V_108 ) ;
F_58 ( V_10 , 0x1a , V_109 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_6 . V_110 . V_111 ; V_30 ++ ) {
struct V_12 * V_17 =
F_59 ( & V_2 -> V_6 . V_110 , V_30 ) ;
if ( ! strcmp ( V_17 -> V_15 , L_1 ) ) {
V_17 -> V_112 = F_53 ;
break;
}
}
}
static void F_60 ( struct V_9 * V_10 ,
const struct V_41 * V_42 , int V_43 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_43 == V_45 ) {
V_2 -> V_34 = 0x1b ;
V_2 -> V_26 = 1 ;
V_2 -> V_6 . V_113 . V_114 = F_16 ;
}
}
static void F_61 ( struct V_9 * V_10 ,
const struct V_41 * V_42 , int V_43 )
{
F_28 ( V_10 , 0x17 , V_115 ,
( 0x14 << V_46 ) |
( 0x14 << V_47 ) |
( 0x05 << V_48 ) |
( 1 << V_49 ) ) ;
}
static void F_62 ( struct V_9 * V_10 ,
const struct V_41 * V_42 , int V_43 )
{
F_28 ( V_10 , 0x10 , V_115 ,
( 0x17 << V_46 ) |
( 0x17 << V_47 ) |
( 0x05 << V_48 ) |
( 1 << V_49 ) ) ;
}
static void F_63 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
static T_1 V_116 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_117 ;
for ( V_117 = V_116 ; * V_117 ; V_117 ++ )
F_28 ( V_10 , * V_117 , V_21 ,
V_118 |
F_64 ( V_10 , * V_117 , V_21 ) ) ;
V_2 -> V_6 . V_119 = true ;
}
static int F_65 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
F_66 ( V_10 , L_2 , V_10 -> V_36 . V_120 ) ;
V_2 = F_67 ( sizeof( * V_2 ) , V_121 ) ;
if ( ! V_2 )
return - V_18 ;
F_68 ( & V_2 -> V_6 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_122 = V_123 ;
F_6 ( V_10 ) ;
F_10 ( V_10 ) ;
V_2 -> V_6 . V_124 = 1 ;
if ( V_2 -> V_26 )
V_2 -> V_6 . V_113 . V_114 = F_15 ;
switch ( V_10 -> V_36 . V_37 ) {
case 0x14f15045 :
V_10 -> V_125 = 1 ;
V_2 -> V_6 . V_126 = 0x17 ;
V_2 -> V_6 . V_127 = V_128 ;
F_69 ( V_10 , V_129 ,
V_130 , V_131 ) ;
break;
case 0x14f15047 :
V_10 -> V_132 = 1 ;
V_2 -> V_6 . V_126 = 0x19 ;
V_2 -> V_6 . V_127 = V_128 ;
F_69 ( V_10 , V_133 ,
V_134 , V_131 ) ;
break;
case 0x14f15051 :
F_63 ( V_10 ) ;
V_10 -> V_132 = 1 ;
F_69 ( V_10 , V_135 ,
V_136 , V_131 ) ;
break;
default:
V_10 -> V_132 = 1 ;
F_69 ( V_10 , V_137 ,
V_138 , V_131 ) ;
break;
}
switch ( V_10 -> V_36 . V_139 >> 16 ) {
case 0x103c :
V_2 -> V_6 . V_140 = 1 ;
break;
}
F_21 ( V_10 , V_45 ) ;
V_11 = F_70 ( V_10 , & V_2 -> V_6 . V_53 , NULL ,
V_2 -> V_66 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_71 ( V_10 , & V_2 -> V_6 . V_53 ) ;
if ( V_11 < 0 )
goto error;
if ( ! V_10 -> V_141 -> V_36 . V_142 ) {
F_66 ( V_10 ,
L_3 ) ;
V_10 -> V_141 -> V_36 . V_142 = 1 ;
V_10 -> V_141 -> V_143 = 1 ;
}
F_21 ( V_10 , V_68 ) ;
return 0 ;
error:
F_24 ( V_10 ) ;
return V_11 ;
}
