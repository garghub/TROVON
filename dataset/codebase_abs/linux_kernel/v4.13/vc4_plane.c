static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 ;
}
static const struct V_4 * F_2 ( T_1 V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_8 == V_5 )
return & V_7 [ V_6 ] ;
}
return NULL ;
}
static enum V_9 F_4 ( T_1 V_10 , T_1 V_11 )
{
if ( V_11 > V_10 )
return V_12 ;
else if ( V_11 < V_10 )
return V_13 ;
else
return V_14 ;
}
static bool F_5 ( struct V_2 * V_3 )
{
return V_3 -> V_15 && V_3 -> V_16 ;
}
static struct V_2 * F_6 ( struct V_17 * V_18 )
{
struct V_1 * V_19 ;
if ( F_7 ( ! V_18 -> V_3 ) )
return NULL ;
V_19 = F_8 ( V_18 -> V_3 , sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 )
return NULL ;
memset ( & V_19 -> V_21 , 0 , sizeof( V_19 -> V_21 ) ) ;
F_9 ( V_18 , & V_19 -> V_22 ) ;
if ( V_19 -> V_23 ) {
V_19 -> V_23 = F_8 ( V_19 -> V_23 ,
V_19 -> V_24 * 4 ,
V_20 ) ;
if ( ! V_19 -> V_23 ) {
F_10 ( V_19 ) ;
return NULL ;
}
V_19 -> V_25 = V_19 -> V_24 ;
}
return & V_19 -> V_22 ;
}
static void F_11 ( struct V_17 * V_18 ,
struct V_2 * V_3 )
{
struct V_26 * V_27 = F_12 ( V_18 -> V_28 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( V_19 -> V_21 . V_29 ) {
unsigned long V_30 ;
F_13 ( & V_27 -> V_31 -> V_32 , V_30 ) ;
F_14 ( & V_19 -> V_21 ) ;
F_15 ( & V_27 -> V_31 -> V_32 , V_30 ) ;
}
F_10 ( V_19 -> V_23 ) ;
F_16 ( & V_19 -> V_22 ) ;
F_10 ( V_3 ) ;
}
static void F_17 ( struct V_17 * V_18 )
{
struct V_1 * V_19 ;
F_7 ( V_18 -> V_3 ) ;
V_19 = F_18 ( sizeof( * V_19 ) , V_20 ) ;
if ( ! V_19 )
return;
V_18 -> V_3 = & V_19 -> V_22 ;
V_19 -> V_22 . V_18 = V_18 ;
}
static void F_19 ( struct V_1 * V_19 , T_1 V_33 )
{
if ( V_19 -> V_24 == V_19 -> V_25 ) {
T_1 V_34 = F_20 ( 4u , V_19 -> V_24 * 2 ) ;
T_1 * V_35 = F_21 ( V_34 * 4 , V_20 ) ;
if ( ! V_35 )
return;
memcpy ( V_35 , V_19 -> V_23 , V_19 -> V_24 * 4 ) ;
F_10 ( V_19 -> V_23 ) ;
V_19 -> V_23 = V_35 ;
V_19 -> V_25 = V_34 ;
}
V_19 -> V_23 [ V_19 -> V_24 ++ ] = V_33 ;
}
static T_1 F_22 ( struct V_2 * V_3 , int V_18 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
switch ( V_19 -> V_36 [ V_18 ] << 2 | V_19 -> V_37 [ V_18 ] ) {
case V_12 << 2 | V_12 :
return V_38 ;
case V_13 << 2 | V_12 :
return V_39 ;
case V_12 << 2 | V_13 :
return V_40 ;
case V_13 << 2 | V_13 :
return V_41 ;
case V_12 << 2 | V_14 :
return V_42 ;
case V_14 << 2 | V_12 :
return V_43 ;
case V_14 << 2 | V_13 :
return V_44 ;
case V_13 << 2 | V_14 :
return V_45 ;
default:
case V_14 << 2 | V_14 :
return 0 ;
}
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_18 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_46 * V_15 = V_3 -> V_15 ;
struct V_47 * V_48 = F_24 ( V_15 , 0 ) ;
T_1 V_49 = ( 1 << 16 ) - 1 ;
T_1 V_50 = V_15 -> V_50 -> V_50 ;
int V_51 = V_15 -> V_50 -> V_51 ;
T_1 V_52 = 1 ;
T_1 V_53 = 1 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_51 ; V_6 ++ )
V_19 -> V_54 [ V_6 ] = V_48 -> V_55 + V_15 -> V_54 [ V_6 ] ;
if ( ( V_3 -> V_56 & V_49 ) ||
( V_3 -> V_57 & V_49 ) ||
( V_3 -> V_58 & V_49 ) ||
( V_3 -> V_59 & V_49 ) ) {
return - V_60 ;
}
V_19 -> V_56 = V_3 -> V_56 >> 16 ;
V_19 -> V_57 = V_3 -> V_57 >> 16 ;
V_19 -> V_58 [ 0 ] = V_3 -> V_58 >> 16 ;
V_19 -> V_59 [ 0 ] = V_3 -> V_59 >> 16 ;
V_19 -> V_61 = V_3 -> V_61 ;
V_19 -> V_62 = V_3 -> V_62 ;
V_19 -> V_63 = V_3 -> V_63 ;
V_19 -> V_64 = V_3 -> V_64 ;
V_19 -> V_36 [ 0 ] = F_4 ( V_19 -> V_58 [ 0 ] ,
V_19 -> V_63 ) ;
V_19 -> V_37 [ 0 ] = F_4 ( V_19 -> V_59 [ 0 ] ,
V_19 -> V_64 ) ;
if ( V_51 > 1 ) {
V_19 -> V_65 = true ;
V_52 = F_25 ( V_50 ) ;
V_53 = F_26 ( V_50 ) ;
V_19 -> V_58 [ 1 ] = V_19 -> V_58 [ 0 ] / V_52 ;
V_19 -> V_59 [ 1 ] = V_19 -> V_59 [ 0 ] / V_53 ;
V_19 -> V_36 [ 1 ] =
F_4 ( V_19 -> V_58 [ 1 ] ,
V_19 -> V_63 ) ;
V_19 -> V_37 [ 1 ] =
F_4 ( V_19 -> V_59 [ 1 ] ,
V_19 -> V_64 ) ;
if ( V_19 -> V_36 [ 0 ] == V_14 )
V_19 -> V_36 [ 0 ] = V_13 ;
if ( V_19 -> V_37 [ 0 ] == V_14 )
V_19 -> V_37 [ 0 ] = V_13 ;
}
V_19 -> V_66 = ( V_19 -> V_36 [ 0 ] == V_14 &&
V_19 -> V_37 [ 0 ] == V_14 &&
V_19 -> V_36 [ 1 ] == V_14 &&
V_19 -> V_37 [ 1 ] == V_14 ) ;
if ( V_18 -> type == V_67 && ! V_19 -> V_66 )
return - V_60 ;
if ( V_19 -> V_61 < 0 ) {
for ( V_6 = 0 ; V_6 < V_51 ; V_6 ++ ) {
T_1 V_68 = V_15 -> V_50 -> V_68 [ V_6 ] ;
T_1 V_69 = ( ( V_6 == 0 ) ? 1 : V_52 ) ;
V_19 -> V_54 [ V_6 ] += ( V_68 *
( - V_19 -> V_61 ) / V_69 ) ;
}
V_19 -> V_58 [ 0 ] += V_19 -> V_61 ;
V_19 -> V_58 [ 1 ] += V_19 -> V_61 / V_52 ;
V_19 -> V_61 = 0 ;
}
if ( V_19 -> V_62 < 0 ) {
for ( V_6 = 0 ; V_6 < V_51 ; V_6 ++ ) {
T_1 V_69 = ( ( V_6 == 0 ) ? 1 : V_53 ) ;
V_19 -> V_54 [ V_6 ] += ( V_15 -> V_70 [ V_6 ] *
( - V_19 -> V_62 ) / V_69 ) ;
}
V_19 -> V_59 [ 0 ] += V_19 -> V_62 ;
V_19 -> V_59 [ 1 ] += V_19 -> V_62 / V_53 ;
V_19 -> V_62 = 0 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_19 , T_1 V_10 , T_1 V_11 )
{
T_1 V_71 , V_72 ;
V_71 = ( 1 << 16 ) * V_10 / V_11 ;
V_72 = ~ 0 / V_71 ;
F_19 ( V_19 ,
F_28 ( V_71 , V_73 ) |
F_28 ( 0 , V_74 ) ) ;
F_19 ( V_19 ,
F_28 ( V_72 , V_75 ) ) ;
}
static void F_29 ( struct V_1 * V_19 , T_1 V_10 , T_1 V_11 )
{
T_1 V_71 = ( 1 << 16 ) * V_10 / V_11 ;
F_19 ( V_19 ,
V_76 |
F_28 ( V_71 , V_77 ) |
F_28 ( 0 , V_78 ) ) ;
}
static T_1 F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_79 = F_20 ( V_19 -> V_58 [ 0 ] , ( T_1 ) V_19 -> V_63 ) ;
T_1 V_21 ;
if ( ! V_19 -> V_65 ) {
if ( V_19 -> V_66 )
return 0 ;
else if ( V_19 -> V_37 [ 0 ] == V_13 )
V_21 = V_79 * 8 ;
else {
V_21 = V_79 * 16 ;
}
} else {
V_21 = V_79 * 16 ;
}
V_21 = F_31 ( V_21 , 32 ) ;
return V_21 ;
}
static void F_32 ( struct V_2 * V_3 ,
int V_80 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
if ( V_19 -> V_36 [ V_80 ] == V_12 ) {
F_29 ( V_19 ,
V_19 -> V_58 [ V_80 ] , V_19 -> V_63 ) ;
}
if ( V_19 -> V_37 [ V_80 ] == V_12 ) {
F_29 ( V_19 ,
V_19 -> V_59 [ V_80 ] , V_19 -> V_64 ) ;
F_19 ( V_19 , 0xc0c0c0c0 ) ;
}
if ( V_19 -> V_36 [ V_80 ] == V_13 ) {
F_27 ( V_19 ,
V_19 -> V_58 [ V_80 ] , V_19 -> V_63 ) ;
}
if ( V_19 -> V_37 [ V_80 ] == V_13 ) {
F_27 ( V_19 ,
V_19 -> V_59 [ V_80 ] , V_19 -> V_64 ) ;
F_19 ( V_19 , 0xc0c0c0c0 ) ;
}
}
static int F_33 ( struct V_17 * V_18 ,
struct V_2 * V_3 )
{
struct V_26 * V_27 = F_12 ( V_18 -> V_28 ) ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_46 * V_15 = V_3 -> V_15 ;
T_1 V_81 = V_19 -> V_24 ;
const struct V_4 * V_50 = F_2 ( V_15 -> V_50 -> V_50 ) ;
int V_51 = F_34 ( V_50 -> V_8 ) ;
T_1 V_82 , V_83 , V_84 ;
T_1 V_85 , V_86 ;
unsigned long V_30 ;
int V_87 , V_6 ;
V_87 = F_23 ( V_3 ) ;
if ( V_87 )
return V_87 ;
V_85 = F_30 ( V_3 ) ;
if ( V_85 ) {
if ( ! V_19 -> V_21 . V_29 ) {
F_13 ( & V_27 -> V_31 -> V_32 , V_30 ) ;
V_87 = F_35 ( & V_27 -> V_31 -> V_88 ,
& V_19 -> V_21 ,
V_85 , 32 , 0 , 0 ) ;
F_15 ( & V_27 -> V_31 -> V_32 , V_30 ) ;
} else {
F_36 ( V_85 != V_19 -> V_21 . V_89 ) ;
}
}
if ( V_87 )
return V_87 ;
if ( V_51 == 1 ) {
V_82 = F_22 ( V_3 , 1 ) ;
V_83 = V_82 ;
} else {
V_82 = F_22 ( V_3 , 1 ) ;
V_83 = F_22 ( V_3 , 0 ) ;
}
switch ( V_15 -> V_90 ) {
case V_91 :
V_86 = V_92 ;
V_84 = F_28 ( V_15 -> V_70 [ 0 ] , V_93 ) ;
break;
case V_94 :
V_86 = V_95 ;
V_84 = ( F_28 ( 0 , V_96 ) ,
F_28 ( 0 , V_97 ) ,
F_28 ( ( V_19 -> V_58 [ 0 ] + 31 ) >> 5 ,
V_98 ) ) ;
break;
default:
F_37 ( L_1 ,
( long long ) V_15 -> V_90 ) ;
return - V_60 ;
}
F_19 ( V_19 ,
V_99 |
( V_50 -> V_100 << V_101 ) |
( V_50 -> V_31 << V_102 ) |
F_28 ( V_86 , V_103 ) |
( V_19 -> V_66 ? V_104 : 0 ) |
F_28 ( V_82 , V_105 ) |
F_28 ( V_83 , V_106 ) ) ;
V_19 -> V_107 = V_19 -> V_24 ;
F_19 ( V_19 ,
F_28 ( 0xff , V_108 ) |
F_28 ( V_19 -> V_61 , V_109 ) |
F_28 ( V_19 -> V_62 , V_110 ) ) ;
if ( ! V_19 -> V_66 ) {
F_19 ( V_19 ,
F_28 ( V_19 -> V_63 ,
V_111 ) |
F_28 ( V_19 -> V_64 ,
V_112 ) ) ;
}
V_19 -> V_113 = V_19 -> V_24 ;
F_19 ( V_19 ,
F_28 ( V_50 -> V_114 ?
V_115 :
V_116 ,
V_117 ) |
F_28 ( V_19 -> V_58 [ 0 ] , V_118 ) |
F_28 ( V_19 -> V_59 [ 0 ] , V_119 ) ) ;
F_19 ( V_19 , 0xc0c0c0c0 ) ;
V_19 -> V_120 = V_19 -> V_24 ;
if ( ! V_50 -> V_121 ) {
for ( V_6 = 0 ; V_6 < V_51 ; V_6 ++ )
F_19 ( V_19 , V_19 -> V_54 [ V_6 ] ) ;
} else {
F_36 ( V_51 != 3 ) ;
F_19 ( V_19 , V_19 -> V_54 [ 0 ] ) ;
F_19 ( V_19 , V_19 -> V_54 [ 2 ] ) ;
F_19 ( V_19 , V_19 -> V_54 [ 1 ] ) ;
}
for ( V_6 = 0 ; V_6 < V_51 ; V_6 ++ )
F_19 ( V_19 , 0xc0c0c0c0 ) ;
F_19 ( V_19 , V_84 ) ;
for ( V_6 = 1 ; V_6 < V_51 ; V_6 ++ ) {
F_19 ( V_19 ,
F_28 ( V_15 -> V_70 [ V_6 ] , V_93 ) ) ;
}
if ( V_19 -> V_65 ) {
F_19 ( V_19 , V_122 ) ;
F_19 ( V_19 , V_123 ) ;
F_19 ( V_19 , V_124 ) ;
}
if ( ! V_19 -> V_66 ) {
if ( V_19 -> V_37 [ 0 ] != V_14 ||
V_19 -> V_37 [ 1 ] != V_14 ) {
F_19 ( V_19 , V_19 -> V_21 . V_125 ) ;
}
if ( V_51 > 1 ) {
F_32 ( V_3 , 1 ) ;
}
F_32 ( V_3 , 0 ) ;
if ( V_19 -> V_36 [ 0 ] == V_12 ||
V_19 -> V_37 [ 0 ] == V_12 ||
V_19 -> V_36 [ 1 ] == V_12 ||
V_19 -> V_37 [ 1 ] == V_12 ) {
T_1 V_126 = F_28 ( V_27 -> V_31 -> V_127 . V_125 ,
V_128 ) ;
F_19 ( V_19 , V_126 ) ;
F_19 ( V_19 , V_126 ) ;
F_19 ( V_19 , V_126 ) ;
F_19 ( V_19 , V_126 ) ;
}
}
V_19 -> V_23 [ V_81 ] |=
F_28 ( V_19 -> V_24 , V_129 ) ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 ,
struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
V_19 -> V_24 = 0 ;
if ( F_5 ( V_3 ) )
return F_33 ( V_18 , V_3 ) ;
else
return 0 ;
}
static void F_39 ( struct V_17 * V_18 ,
struct V_2 * V_130 )
{
}
T_1 F_40 ( struct V_17 * V_18 , T_1 T_2 * V_23 )
{
struct V_1 * V_19 = F_1 ( V_18 -> V_3 ) ;
int V_6 ;
V_19 -> V_131 = V_23 ;
for ( V_6 = 0 ; V_6 < V_19 -> V_24 ; V_6 ++ )
F_41 ( V_19 -> V_23 [ V_6 ] , & V_23 [ V_6 ] ) ;
return V_19 -> V_24 ;
}
T_1 F_42 ( const struct V_2 * V_3 )
{
const struct V_1 * V_19 =
F_43 ( V_3 , F_44 ( * V_19 ) , V_22 ) ;
return V_19 -> V_24 ;
}
void F_45 ( struct V_17 * V_18 , struct V_46 * V_15 )
{
struct V_1 * V_19 = F_1 ( V_18 -> V_3 ) ;
struct V_47 * V_48 = F_24 ( V_15 , 0 ) ;
T_3 V_132 ;
F_36 ( V_18 -> V_3 -> V_61 < 0 || V_18 -> V_3 -> V_62 < 0 ) ;
V_132 = V_48 -> V_55 + V_15 -> V_54 [ 0 ] ;
F_41 ( V_132 , & V_19 -> V_131 [ V_19 -> V_120 ] ) ;
V_19 -> V_23 [ V_19 -> V_120 ] = V_132 ;
}
static void F_46 ( struct V_17 * V_18 )
{
F_47 ( V_18 ) ;
F_48 ( V_18 ) ;
}
static int
F_49 ( struct V_17 * V_18 ,
struct V_133 * V_16 ,
struct V_46 * V_15 ,
int V_61 , int V_62 ,
unsigned int V_63 , unsigned int V_64 ,
T_3 V_56 , T_3 V_57 ,
T_3 V_58 , T_3 V_59 ,
struct V_134 * V_135 )
{
struct V_2 * V_136 ;
struct V_1 * V_19 ;
if ( V_18 != V_16 -> V_137 )
goto V_138;
V_136 = V_18 -> V_3 ;
V_19 = F_1 ( V_136 ) ;
if ( ! V_136 )
goto V_138;
if ( V_63 != V_136 -> V_63 ||
V_64 != V_136 -> V_64 ||
V_58 != V_136 -> V_58 ||
V_59 != V_136 -> V_59 ) {
goto V_138;
}
if ( V_15 != V_136 -> V_15 ) {
F_50 ( V_18 -> V_3 , V_15 ) ;
F_45 ( V_18 , V_15 ) ;
}
V_136 -> V_61 = V_61 ;
V_136 -> V_62 = V_62 ;
V_136 -> V_56 = V_56 ;
V_136 -> V_57 = V_57 ;
F_38 ( V_18 , V_136 ) ;
F_41 ( V_19 -> V_23 [ V_19 -> V_107 ] ,
& V_19 -> V_131 [ V_19 -> V_107 ] ) ;
F_41 ( V_19 -> V_23 [ V_19 -> V_113 ] ,
& V_19 -> V_131 [ V_19 -> V_113 ] ) ;
F_41 ( V_19 -> V_23 [ V_19 -> V_120 ] ,
& V_19 -> V_131 [ V_19 -> V_120 ] ) ;
return 0 ;
V_138:
return F_51 ( V_18 , V_16 , V_15 ,
V_61 , V_62 ,
V_63 , V_64 ,
V_56 , V_57 ,
V_58 , V_59 ,
V_135 ) ;
}
struct V_17 * F_52 ( struct V_139 * V_28 ,
enum V_140 type )
{
struct V_17 * V_18 = NULL ;
struct V_141 * V_141 ;
T_1 V_142 [ F_3 ( V_7 ) ] ;
T_1 V_143 = 0 ;
int V_87 = 0 ;
unsigned V_6 ;
V_141 = F_53 ( V_28 -> V_28 , sizeof( * V_141 ) ,
V_20 ) ;
if ( ! V_141 )
return F_54 ( - V_144 ) ;
for ( V_6 = 0 ; V_6 < F_3 ( V_7 ) ; V_6 ++ ) {
if ( type != V_67 ||
V_7 [ V_6 ] . V_31 < V_145 ) {
V_142 [ V_143 ++ ] = V_7 [ V_6 ] . V_8 ;
}
}
V_18 = & V_141 -> V_22 ;
V_87 = F_55 ( V_28 , V_18 , 0 ,
& V_146 ,
V_142 , V_143 ,
type , NULL ) ;
F_56 ( V_18 , & V_147 ) ;
return V_18 ;
}
