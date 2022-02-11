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
static int F_15 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_16 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_3 ( V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
F_18 ( V_10 ) ;
if ( ! V_2 -> V_29 )
F_12 ( V_10 , V_2 -> V_28 , V_2 -> V_27 , true ) ;
F_19 ( V_10 , V_37 ) ;
return 0 ;
}
static void F_20 ( struct V_9 * V_10 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
V_2 -> V_6 . V_41 = 1 ;
}
static void F_21 ( struct V_9 * V_10 ,
const struct V_38 * V_39 , int V_40 )
{
if ( V_40 != V_42 )
return;
F_22 ( V_10 , 0x17 , V_24 ,
( 0x3 << V_43 ) |
( 0x4 << V_44 ) |
( 0x27 << V_45 ) |
( 0 << V_46 ) ) ;
}
static void F_23 ( struct V_9 * V_10 )
{
int V_33 ;
bool V_47 = false ;
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_48 * V_49 = & V_2 -> V_6 . V_50 ;
T_1 V_51 = V_2 -> V_6 . V_52 [ V_2 -> V_6 . V_53 [ 0 ] ] ;
for ( V_33 = 0 ; V_33 < V_49 -> V_54 ; V_33 ++ )
if ( V_49 -> V_55 [ V_33 ] . V_56 == V_51 ) {
V_47 = ! ! V_49 -> V_55 [ V_33 ] . V_57 ;
break;
}
if ( V_47 ) {
F_24 ( V_10 , 0x1c , 0 , 0x410 , 0x7c ) ;
V_2 -> V_6 . V_58 = false ;
} else {
F_24 ( V_10 , 0x1c , 0 , 0x410 , 0x54 ) ;
V_2 -> V_6 . V_58 = F_25 ( V_10 , V_2 -> V_6 . V_50 . V_59 [ 0 ] ) ;
}
F_26 ( V_10 ) ;
}
static void F_27 ( struct V_9 * V_10 ,
struct V_16 * V_60 ,
struct V_61 * V_62 )
{
F_23 ( V_10 ) ;
}
static void F_28 ( struct V_9 * V_10 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_40 ) {
case V_42 :
V_2 -> V_63 |= V_64 ;
break;
case V_65 :
V_2 -> V_6 . V_66 = F_27 ;
V_2 -> V_6 . V_67 = F_23 ;
break;
case V_37 :
F_23 ( V_10 ) ;
break;
}
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_68 , V_69 ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_69 = V_70 |
( V_68 ? V_71 : V_72 ) ;
if ( ! V_2 -> V_73 )
V_69 |= F_30 ( V_10 , 0x17 , V_68 , V_24 , 0 ) ;
F_13 ( V_10 , 0x17 , 0 ,
V_74 , V_69 ) ;
}
}
static void F_31 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_75 , V_69 ;
struct V_76 * V_77 ;
V_75 = V_2 -> V_6 . V_78 [ 0 ] [ V_2 -> V_6 . V_53 [ 0 ] ] ;
if ( ! V_2 -> V_73 ) {
F_32 ( V_10 , 0x1e , 0 ) ;
F_33 ( V_10 , V_2 -> V_79 , false , false ) ;
F_32 ( V_10 , 0x1a , V_2 -> V_80 ?
F_34 ( V_10 , 0x1a ) : 0 ) ;
F_32 ( V_10 , 0x1b , V_2 -> V_80 ?
F_34 ( V_10 , 0x1b ) : 0 ) ;
V_77 = F_35 ( V_10 , V_75 ) ;
if ( V_77 )
F_33 ( V_10 , V_77 , true , false ) ;
} else {
V_77 = F_35 ( V_10 , V_75 ) ;
if ( V_77 )
F_33 ( V_10 , V_77 , false , false ) ;
if ( V_2 -> V_80 )
V_69 = V_81 . V_82 [ V_2 -> V_83 ] . V_84 ;
else
V_69 = 0 ;
F_32 ( V_10 , 0x1a , V_69 ) ;
F_32 ( V_10 , 0x1b , 0 ) ;
F_32 ( V_10 , 0x1e , V_2 -> V_80 ? V_85 : 0 ) ;
F_33 ( V_10 , V_2 -> V_79 , true , false ) ;
}
}
static void F_36 ( struct V_9 * V_10 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_88 = V_10 -> V_89 ;
V_10 -> V_89 = 1 ;
if ( ! V_2 -> V_73 )
F_37 ( V_10 , V_87 ) ;
F_31 ( V_10 ) ;
F_38 ( V_10 ) ;
V_10 -> V_89 = V_88 ;
if ( V_2 -> V_73 )
F_29 ( V_10 ) ;
}
static void F_39 ( struct V_90 * V_91 ,
struct V_9 * V_10 ,
struct V_92 * V_93 ,
int V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
switch ( V_40 ) {
case V_94 :
V_2 -> V_80 = 1 ;
F_31 ( V_10 ) ;
break;
case V_95 :
V_2 -> V_80 = 0 ;
F_31 ( V_10 ) ;
break;
}
}
static int F_40 ( struct V_16 * V_60 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_41 ( V_60 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_62 -> V_96 . integer . V_96 [ 0 ] = V_2 -> V_73 ;
return 0 ;
}
static int F_42 ( struct V_16 * V_60 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_41 ( V_60 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_73 = ! ! V_62 -> V_96 . integer . V_96 [ 0 ] ;
if ( V_73 == V_2 -> V_73 )
return 0 ;
V_2 -> V_73 = V_73 ;
F_31 ( V_10 ) ;
F_29 ( V_10 ) ;
return 1 ;
}
static int F_43 ( struct V_16 * V_60 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_41 ( V_60 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
V_62 -> V_96 . V_97 . V_98 [ 0 ] = V_2 -> V_83 ;
return 0 ;
}
static int F_44 ( struct V_16 * V_60 ,
struct V_99 * V_100 )
{
return F_45 ( & V_81 , V_100 ) ;
}
static int F_46 ( struct V_16 * V_60 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_41 ( V_60 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
const struct V_101 * V_102 = & V_81 ;
unsigned int V_4 ;
V_4 = V_62 -> V_96 . V_97 . V_98 [ 0 ] ;
if ( V_4 >= V_102 -> V_103 )
V_4 = V_102 -> V_103 - 1 ;
if ( V_2 -> V_83 == V_4 )
return 0 ;
V_2 -> V_83 = V_4 ;
if ( V_2 -> V_73 )
F_31 ( V_10 ) ;
return 1 ;
}
static int F_47 ( struct V_16 * V_60 ,
struct V_61 * V_62 )
{
struct V_9 * V_10 = F_41 ( V_60 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
int V_104 = F_48 ( V_60 , V_62 ) ;
if ( V_104 > 0 && V_2 -> V_73 )
F_29 ( V_10 ) ;
return V_104 ;
}
static void F_49 ( struct V_9 * V_10 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
int V_33 ;
if ( V_40 != V_65 )
return;
V_2 -> V_6 . V_105 = F_36 ;
V_2 -> V_6 . V_106 = F_39 ;
V_2 -> V_79 = F_50 ( V_10 , 0x1e , 0x14 , 0 ) ;
F_51 ( V_10 , V_107 ) ;
F_52 ( V_10 , 0x1a , V_108 ) ;
for ( V_33 = 0 ; V_33 < V_2 -> V_6 . V_109 . V_110 ; V_33 ++ ) {
struct V_12 * V_17 =
F_53 ( & V_2 -> V_6 . V_109 , V_33 ) ;
if ( ! strcmp ( V_17 -> V_15 , L_1 ) ) {
V_17 -> V_111 = F_47 ;
break;
}
}
}
static void F_54 ( struct V_9 * V_10 ,
const struct V_38 * V_39 , int V_40 )
{
F_22 ( V_10 , 0x17 , V_112 ,
( 0x14 << V_43 ) |
( 0x14 << V_44 ) |
( 0x05 << V_45 ) |
( 1 << V_46 ) ) ;
}
static void F_55 ( struct V_9 * V_10 ,
const struct V_38 * V_39 , int V_40 )
{
F_22 ( V_10 , 0x10 , V_112 ,
( 0x17 << V_43 ) |
( 0x17 << V_44 ) |
( 0x05 << V_45 ) |
( 1 << V_46 ) ) ;
}
static void F_56 ( struct V_9 * V_10 )
{
static T_1 V_113 [] = {
0x10 , 0x11 , 0
} ;
T_1 * V_114 ;
for ( V_114 = V_113 ; * V_114 ; V_114 ++ )
F_22 ( V_10 , * V_114 , V_24 ,
V_115 |
F_57 ( V_10 , * V_114 , V_24 ) ) ;
}
static int F_58 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_11 ;
F_59 ( V_10 , L_2 , V_10 -> V_116 ) ;
V_2 = F_60 ( sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 )
return - V_18 ;
F_61 ( & V_2 -> V_6 ) ;
V_10 -> V_2 = V_2 ;
F_6 ( V_10 ) ;
F_9 ( V_10 ) ;
V_2 -> V_6 . V_118 = 1 ;
if ( V_2 -> V_29 )
V_2 -> V_6 . V_119 . V_120 = F_14 ;
switch ( V_10 -> V_121 ) {
case 0x14f15045 :
V_10 -> V_122 = 1 ;
V_2 -> V_6 . V_123 = 0x17 ;
V_2 -> V_6 . V_124 = 1 ;
F_62 ( V_10 , V_125 ,
V_126 , V_127 ) ;
break;
case 0x14f15047 :
V_10 -> V_128 = 1 ;
V_2 -> V_6 . V_123 = 0x19 ;
V_2 -> V_6 . V_124 = 1 ;
F_62 ( V_10 , V_129 ,
V_130 , V_127 ) ;
break;
case 0x14f15051 :
F_56 ( V_10 ) ;
V_10 -> V_128 = 1 ;
F_62 ( V_10 , V_131 ,
V_132 , V_127 ) ;
break;
default:
V_10 -> V_128 = 1 ;
F_62 ( V_10 , V_133 ,
V_134 , V_127 ) ;
break;
}
switch ( V_10 -> V_135 >> 16 ) {
case 0x103c :
V_2 -> V_6 . V_136 = 1 ;
break;
}
F_19 ( V_10 , V_42 ) ;
V_11 = F_63 ( V_10 , & V_2 -> V_6 . V_50 , NULL ,
V_2 -> V_63 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_64 ( V_10 , & V_2 -> V_6 . V_50 ) ;
if ( V_11 < 0 )
goto error;
if ( V_10 -> V_121 == 0x14f15051 ) {
V_2 -> V_6 . V_137 [ 3 ] |= V_138 ;
}
V_10 -> V_139 = V_140 ;
if ( ! V_10 -> V_141 -> V_142 ) {
F_59 ( V_10 ,
L_3 ) ;
V_10 -> V_141 -> V_142 = 1 ;
V_10 -> V_141 -> V_143 = 1 ;
}
F_19 ( V_10 , V_65 ) ;
return 0 ;
error:
F_65 ( V_10 ) ;
return V_11 ;
}
static int T_2 F_66 ( void )
{
return F_67 ( & V_144 ) ;
}
static void T_3 F_68 ( void )
{
F_69 ( & V_144 ) ;
}
