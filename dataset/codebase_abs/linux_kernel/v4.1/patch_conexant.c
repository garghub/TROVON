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
static void F_22 ( struct V_9 * V_10 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_6 . V_39 = 1 ;
}
static void F_23 ( struct V_9 * V_10 ,
const struct V_36 * V_37 , int V_38 )
{
if ( V_38 != V_40 )
return;
F_24 ( V_10 , 0x17 , V_21 ,
( 0x3 << V_41 ) |
( 0x4 << V_42 ) |
( 0x27 << V_43 ) |
( 0 << V_44 ) ) ;
}
static void F_25 ( struct V_9 * V_10 )
{
int V_30 ;
bool V_45 = false ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_46 * V_47 = & V_2 -> V_6 . V_48 ;
T_1 V_49 = V_2 -> V_6 . V_50 [ V_2 -> V_6 . V_51 [ 0 ] ] ;
for ( V_30 = 0 ; V_30 < V_47 -> V_52 ; V_30 ++ )
if ( V_47 -> V_53 [ V_30 ] . V_54 == V_49 ) {
V_45 = ! ! V_47 -> V_53 [ V_30 ] . V_55 ;
break;
}
if ( V_45 ) {
F_26 ( V_10 , 0x1c , 0 , 0x410 , 0x7c ) ;
V_2 -> V_6 . V_56 = false ;
} else {
F_26 ( V_10 , 0x1c , 0 , 0x410 , 0x54 ) ;
V_2 -> V_6 . V_56 = F_27 ( V_10 , V_2 -> V_6 . V_48 . V_57 [ 0 ] ) ;
}
F_28 ( V_10 ) ;
}
static void F_29 ( struct V_9 * V_10 ,
struct V_16 * V_58 ,
struct V_59 * V_60 )
{
F_25 ( V_10 ) ;
}
static void F_30 ( struct V_9 * V_10 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_38 ) {
case V_40 :
V_2 -> V_61 |= V_62 ;
F_31 ( & V_10 -> V_63 , 0x410 ) ;
break;
case V_64 :
V_2 -> V_6 . V_65 = F_29 ;
V_2 -> V_6 . V_66 = F_25 ;
break;
case V_35 :
F_25 ( V_10 ) ;
break;
}
}
static void F_32 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_67 , V_68 ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
V_68 = V_69 |
( V_67 ? V_70 : V_71 ) ;
if ( ! V_2 -> V_72 )
V_68 |= F_33 ( V_10 , 0x17 , V_67 , V_21 , 0 ) ;
F_14 ( V_10 , 0x17 , 0 ,
V_73 , V_68 ) ;
}
}
static void F_34 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_74 , V_68 ;
struct V_75 * V_76 ;
V_74 = V_2 -> V_6 . V_77 [ 0 ] [ V_2 -> V_6 . V_51 [ 0 ] ] ;
if ( ! V_2 -> V_72 ) {
F_35 ( V_10 , 0x1e , 0 ) ;
F_36 ( V_10 , V_2 -> V_78 , false , false ) ;
F_35 ( V_10 , 0x1a , V_2 -> V_79 ?
F_37 ( V_10 , 0x1a ) : 0 ) ;
F_35 ( V_10 , 0x1b , V_2 -> V_79 ?
F_37 ( V_10 , 0x1b ) : 0 ) ;
V_76 = F_38 ( V_10 , V_74 ) ;
if ( V_76 )
F_36 ( V_10 , V_76 , true , false ) ;
} else {
V_76 = F_38 ( V_10 , V_74 ) ;
if ( V_76 )
F_36 ( V_10 , V_76 , false , false ) ;
if ( V_2 -> V_79 )
V_68 = V_80 . V_81 [ V_2 -> V_82 ] . V_83 ;
else
V_68 = 0 ;
F_35 ( V_10 , 0x1a , V_68 ) ;
F_35 ( V_10 , 0x1b , 0 ) ;
F_35 ( V_10 , 0x1e , V_2 -> V_79 ? V_84 : 0 ) ;
F_36 ( V_10 , V_2 -> V_78 , true , false ) ;
}
}
static void F_39 ( struct V_9 * V_10 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( ! V_2 -> V_72 )
F_40 ( V_10 , V_86 ) ;
F_34 ( V_10 ) ;
if ( V_2 -> V_72 )
F_32 ( V_10 ) ;
}
static void F_41 ( struct V_87 * V_88 ,
struct V_9 * V_10 ,
struct V_89 * V_90 ,
int V_38 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_38 ) {
case V_91 :
V_2 -> V_79 = 1 ;
F_34 ( V_10 ) ;
break;
case V_92 :
V_2 -> V_79 = 0 ;
F_34 ( V_10 ) ;
break;
}
}
static int F_42 ( struct V_16 * V_58 ,
struct V_59 * V_60 )
{
struct V_9 * V_10 = F_43 ( V_58 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_60 -> V_93 . integer . V_93 [ 0 ] = V_2 -> V_72 ;
return 0 ;
}
static int F_44 ( struct V_16 * V_58 ,
struct V_59 * V_60 )
{
struct V_9 * V_10 = F_43 ( V_58 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_72 = ! ! V_60 -> V_93 . integer . V_93 [ 0 ] ;
if ( V_72 == V_2 -> V_72 )
return 0 ;
V_2 -> V_72 = V_72 ;
F_34 ( V_10 ) ;
F_32 ( V_10 ) ;
return 1 ;
}
static int F_45 ( struct V_16 * V_58 ,
struct V_59 * V_60 )
{
struct V_9 * V_10 = F_43 ( V_58 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_60 -> V_93 . V_94 . V_95 [ 0 ] = V_2 -> V_82 ;
return 0 ;
}
static int F_46 ( struct V_16 * V_58 ,
struct V_96 * V_97 )
{
return F_47 ( & V_80 , V_97 ) ;
}
static int F_48 ( struct V_16 * V_58 ,
struct V_59 * V_60 )
{
struct V_9 * V_10 = F_43 ( V_58 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_98 * V_99 = & V_80 ;
unsigned int V_4 ;
V_4 = V_60 -> V_93 . V_94 . V_95 [ 0 ] ;
if ( V_4 >= V_99 -> V_100 )
V_4 = V_99 -> V_100 - 1 ;
if ( V_2 -> V_82 == V_4 )
return 0 ;
V_2 -> V_82 = V_4 ;
if ( V_2 -> V_72 )
F_34 ( V_10 ) ;
return 1 ;
}
static int F_49 ( struct V_16 * V_58 ,
struct V_59 * V_60 )
{
struct V_9 * V_10 = F_43 ( V_58 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_101 = F_50 ( V_58 , V_60 ) ;
if ( V_101 > 0 && V_2 -> V_72 )
F_32 ( V_10 ) ;
return V_101 ;
}
static void F_51 ( struct V_9 * V_10 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_30 ;
if ( V_38 != V_64 )
return;
V_2 -> V_6 . V_102 = F_39 ;
V_2 -> V_6 . V_103 = F_41 ;
V_2 -> V_78 = F_52 ( V_10 , 0x1e , 0x14 , 0 ) ;
F_53 ( V_10 , V_104 ) ;
F_54 ( V_10 , 0x1a , V_105 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_6 . V_106 . V_107 ; V_30 ++ ) {
struct V_12 * V_17 =
F_55 ( & V_2 -> V_6 . V_106 , V_30 ) ;
if ( ! strcmp ( V_17 -> V_15 , L_1 ) ) {
V_17 -> V_108 = F_49 ;
break;
}
}
}
static void F_56 ( struct V_9 * V_10 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
if ( V_38 == V_40 ) {
V_2 -> V_34 = 0x1b ;
V_2 -> V_26 = 1 ;
V_2 -> V_6 . V_109 . V_110 = F_16 ;
}
}
static void F_57 ( struct V_9 * V_10 ,
const struct V_36 * V_37 , int V_38 )
{
F_24 ( V_10 , 0x17 , V_111 ,
( 0x14 << V_41 ) |
( 0x14 << V_42 ) |
( 0x05 << V_43 ) |
( 1 << V_44 ) ) ;
}
static void F_58 ( struct V_9 * V_10 ,
const struct V_36 * V_37 , int V_38 )
{
F_24 ( V_10 , 0x10 , V_111 ,
( 0x17 << V_41 ) |
( 0x17 << V_42 ) |
( 0x05 << V_43 ) |
( 1 << V_44 ) ) ;
}
static void F_59 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
static T_1 V_112 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_113 ;
for ( V_113 = V_112 ; * V_113 ; V_113 ++ )
F_24 ( V_10 , * V_113 , V_21 ,
V_114 |
F_60 ( V_10 , * V_113 , V_21 ) ) ;
V_2 -> V_6 . V_115 = true ;
}
static int F_61 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
F_62 ( V_10 , L_2 , V_10 -> V_63 . V_116 ) ;
V_2 = F_63 ( sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_18 ;
F_64 ( & V_2 -> V_6 ) ;
V_10 -> V_2 = V_2 ;
F_6 ( V_10 ) ;
F_10 ( V_10 ) ;
V_2 -> V_6 . V_118 = 1 ;
if ( V_2 -> V_26 )
V_2 -> V_6 . V_109 . V_110 = F_15 ;
switch ( V_10 -> V_63 . V_119 ) {
case 0x14f15045 :
V_10 -> V_120 = 1 ;
V_2 -> V_6 . V_121 = 0x17 ;
V_2 -> V_6 . V_122 = V_123 ;
F_65 ( V_10 , V_124 ,
V_125 , V_126 ) ;
break;
case 0x14f15047 :
V_10 -> V_127 = 1 ;
V_2 -> V_6 . V_121 = 0x19 ;
V_2 -> V_6 . V_122 = V_123 ;
F_65 ( V_10 , V_128 ,
V_129 , V_126 ) ;
break;
case 0x14f15051 :
F_59 ( V_10 ) ;
V_10 -> V_127 = 1 ;
F_65 ( V_10 , V_130 ,
V_131 , V_126 ) ;
break;
default:
V_10 -> V_127 = 1 ;
F_65 ( V_10 , V_132 ,
V_133 , V_126 ) ;
break;
}
switch ( V_10 -> V_63 . V_134 >> 16 ) {
case 0x103c :
V_2 -> V_6 . V_135 = 1 ;
break;
}
F_21 ( V_10 , V_40 ) ;
V_11 = F_66 ( V_10 , & V_2 -> V_6 . V_48 , NULL ,
V_2 -> V_61 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_67 ( V_10 , & V_2 -> V_6 . V_48 ) ;
if ( V_11 < 0 )
goto error;
V_10 -> V_136 = V_137 ;
if ( ! V_10 -> V_138 -> V_63 . V_139 ) {
F_62 ( V_10 ,
L_3 ) ;
V_10 -> V_138 -> V_63 . V_139 = 1 ;
V_10 -> V_138 -> V_140 = 1 ;
}
F_21 ( V_10 , V_64 ) ;
return 0 ;
error:
F_68 ( V_10 ) ;
return V_11 ;
}
