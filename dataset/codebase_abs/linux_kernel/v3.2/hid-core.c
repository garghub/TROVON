struct V_1 * F_1 ( struct V_2 * V_3 , unsigned type , unsigned V_4 )
{
struct V_5 * V_6 = V_3 -> V_6 + type ;
struct V_1 * V_7 ;
if ( V_6 -> V_8 [ V_4 ] )
return V_6 -> V_8 [ V_4 ] ;
V_7 = F_2 ( sizeof( struct V_1 ) , V_9 ) ;
if ( ! V_7 )
return NULL ;
if ( V_4 != 0 )
V_6 -> V_10 = 1 ;
V_7 -> V_4 = V_4 ;
V_7 -> type = type ;
V_7 -> V_11 = 0 ;
V_7 -> V_3 = V_3 ;
V_6 -> V_8 [ V_4 ] = V_7 ;
F_3 ( & V_7 -> V_12 , & V_6 -> V_13 ) ;
return V_7 ;
}
static struct V_14 * F_4 ( struct V_1 * V_7 , unsigned V_15 , unsigned V_16 )
{
struct V_14 * V_17 ;
if ( V_7 -> V_18 == V_19 ) {
F_5 ( L_1 ) ;
return NULL ;
}
V_17 = F_2 ( ( sizeof( struct V_14 ) +
V_15 * sizeof( struct V_20 ) +
V_16 * sizeof( unsigned ) ) , V_9 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_21 = V_7 -> V_18 ++ ;
V_7 -> V_17 [ V_17 -> V_21 ] = V_17 ;
V_17 -> V_22 = (struct V_20 * ) ( V_17 + 1 ) ;
V_17 -> V_23 = ( V_24 * ) ( V_17 -> V_22 + V_15 ) ;
V_17 -> V_7 = V_7 ;
return V_17 ;
}
static int F_6 ( struct V_25 * V_26 , unsigned type )
{
struct V_27 * V_28 ;
unsigned V_22 ;
V_22 = V_26 -> V_29 . V_22 [ 0 ] ;
if ( V_26 -> V_30 == V_31 ) {
F_5 ( L_2 ) ;
return - 1 ;
}
if ( V_26 -> V_3 -> V_32 == V_26 -> V_3 -> V_33 ) {
V_28 = F_7 ( sizeof( struct V_27 ) *
V_26 -> V_3 -> V_33 * 2 , V_9 ) ;
if ( V_28 == NULL ) {
F_5 ( L_3 ) ;
return - 1 ;
}
memcpy ( V_28 , V_26 -> V_3 -> V_28 ,
sizeof( struct V_27 ) *
V_26 -> V_3 -> V_33 ) ;
memset ( V_28 + V_26 -> V_3 -> V_33 , 0 ,
sizeof( struct V_27 ) *
V_26 -> V_3 -> V_33 ) ;
F_8 ( V_26 -> V_3 -> V_28 ) ;
V_26 -> V_3 -> V_28 = V_28 ;
V_26 -> V_3 -> V_33 *= 2 ;
}
V_26 -> V_34 [ V_26 -> V_30 ++ ] =
V_26 -> V_3 -> V_32 ;
V_28 = V_26 -> V_3 -> V_28 +
V_26 -> V_3 -> V_32 ++ ;
V_28 -> type = type ;
V_28 -> V_22 = V_22 ;
V_28 -> V_35 = V_26 -> V_30 - 1 ;
if ( type == V_36 )
V_26 -> V_3 -> V_37 ++ ;
return 0 ;
}
static int F_9 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_30 ) {
F_5 ( L_4 ) ;
return - 1 ;
}
V_26 -> V_30 -- ;
return 0 ;
}
static unsigned F_10 ( struct V_25 * V_26 , unsigned type )
{
struct V_27 * V_28 = V_26 -> V_3 -> V_28 ;
int V_38 ;
for ( V_38 = V_26 -> V_30 - 1 ; V_38 >= 0 ; V_38 -- ) {
unsigned V_21 = V_26 -> V_34 [ V_38 ] ;
if ( V_28 [ V_21 ] . type == type )
return V_28 [ V_21 ] . V_22 ;
}
return 0 ;
}
static int F_11 ( struct V_25 * V_26 , unsigned V_22 )
{
if ( V_26 -> V_29 . V_39 >= V_40 ) {
F_5 ( L_5 ) ;
return - 1 ;
}
V_26 -> V_29 . V_22 [ V_26 -> V_29 . V_39 ] = V_22 ;
V_26 -> V_29 . V_41 [ V_26 -> V_29 . V_39 ] =
V_26 -> V_30 ?
V_26 -> V_34 [ V_26 -> V_30 - 1 ] : 0 ;
V_26 -> V_29 . V_39 ++ ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 , unsigned V_42 , unsigned V_43 )
{
struct V_1 * V_7 ;
struct V_14 * V_17 ;
int V_15 ;
unsigned V_44 ;
int V_45 ;
V_7 = F_1 ( V_26 -> V_3 , V_42 , V_26 -> V_46 . V_47 ) ;
if ( ! V_7 ) {
F_5 ( L_6 ) ;
return - 1 ;
}
if ( V_26 -> V_46 . V_48 < V_26 -> V_46 . V_49 ) {
F_5 ( L_7 , V_26 -> V_46 . V_49 , V_26 -> V_46 . V_48 ) ;
return - 1 ;
}
V_44 = V_7 -> V_11 ;
V_7 -> V_11 += V_26 -> V_46 . V_50 * V_26 -> V_46 . V_51 ;
if ( ! V_26 -> V_29 . V_39 )
return 0 ;
V_15 = F_13 ( int , V_26 -> V_29 . V_39 , V_26 -> V_46 . V_51 ) ;
V_17 = F_4 ( V_7 , V_15 , V_26 -> V_46 . V_51 ) ;
if ( ! V_17 )
return 0 ;
V_17 -> V_52 = F_10 ( V_26 , V_53 ) ;
V_17 -> V_54 = F_10 ( V_26 , V_55 ) ;
V_17 -> V_56 = F_10 ( V_26 , V_36 ) ;
for ( V_45 = 0 ; V_45 < V_15 ; V_45 ++ ) {
int V_57 = V_45 ;
if ( V_45 >= V_26 -> V_29 . V_39 )
V_57 = V_26 -> V_29 . V_39 - 1 ;
V_17 -> V_22 [ V_45 ] . V_58 = V_26 -> V_29 . V_22 [ V_57 ] ;
V_17 -> V_22 [ V_45 ] . V_41 =
V_26 -> V_29 . V_41 [ V_57 ] ;
}
V_17 -> V_59 = V_15 ;
V_17 -> V_43 = V_43 ;
V_17 -> V_60 = V_44 ;
V_17 -> V_42 = V_42 ;
V_17 -> V_50 = V_26 -> V_46 . V_50 ;
V_17 -> V_51 = V_26 -> V_46 . V_51 ;
V_17 -> V_49 = V_26 -> V_46 . V_49 ;
V_17 -> V_48 = V_26 -> V_46 . V_48 ;
V_17 -> V_61 = V_26 -> V_46 . V_61 ;
V_17 -> V_62 = V_26 -> V_46 . V_62 ;
V_17 -> V_63 = V_26 -> V_46 . V_63 ;
V_17 -> V_64 = V_26 -> V_46 . V_64 ;
return 0 ;
}
static T_1 F_14 ( struct V_65 * V_66 )
{
switch ( V_66 -> V_11 ) {
case 1 : return V_66 -> V_67 . V_68 ;
case 2 : return V_66 -> V_67 . V_69 ;
case 4 : return V_66 -> V_67 . T_1 ;
}
return 0 ;
}
static V_24 F_15 ( struct V_65 * V_66 )
{
switch ( V_66 -> V_11 ) {
case 1 : return V_66 -> V_67 . V_70 ;
case 2 : return V_66 -> V_67 . V_71 ;
case 4 : return V_66 -> V_67 . V_24 ;
}
return 0 ;
}
static int F_16 ( struct V_25 * V_26 , struct V_65 * V_66 )
{
switch ( V_66 -> V_72 ) {
case V_73 :
if ( V_26 -> V_74 == V_75 ) {
F_5 ( L_8 ) ;
return - 1 ;
}
memcpy ( V_26 -> V_76 + V_26 -> V_74 ++ ,
& V_26 -> V_46 , sizeof( struct V_77 ) ) ;
return 0 ;
case V_78 :
if ( ! V_26 -> V_74 ) {
F_5 ( L_9 ) ;
return - 1 ;
}
memcpy ( & V_26 -> V_46 , V_26 -> V_76 +
-- V_26 -> V_74 , sizeof( struct V_77 ) ) ;
return 0 ;
case V_79 :
V_26 -> V_46 . V_80 = F_14 ( V_66 ) ;
return 0 ;
case V_81 :
V_26 -> V_46 . V_49 = F_15 ( V_66 ) ;
return 0 ;
case V_82 :
if ( V_26 -> V_46 . V_49 < 0 )
V_26 -> V_46 . V_48 = F_15 ( V_66 ) ;
else
V_26 -> V_46 . V_48 = F_14 ( V_66 ) ;
return 0 ;
case V_83 :
V_26 -> V_46 . V_61 = F_15 ( V_66 ) ;
return 0 ;
case V_84 :
if ( V_26 -> V_46 . V_61 < 0 )
V_26 -> V_46 . V_62 = F_15 ( V_66 ) ;
else
V_26 -> V_46 . V_62 = F_14 ( V_66 ) ;
return 0 ;
case V_85 :
V_26 -> V_46 . V_63 = F_15 ( V_66 ) ;
return 0 ;
case V_86 :
V_26 -> V_46 . V_64 = F_14 ( V_66 ) ;
return 0 ;
case V_87 :
V_26 -> V_46 . V_50 = F_14 ( V_66 ) ;
if ( V_26 -> V_46 . V_50 > 32 ) {
F_5 ( L_10 ,
V_26 -> V_46 . V_50 ) ;
return - 1 ;
}
return 0 ;
case V_88 :
V_26 -> V_46 . V_51 = F_14 ( V_66 ) ;
if ( V_26 -> V_46 . V_51 > V_40 ) {
F_5 ( L_11 ,
V_26 -> V_46 . V_51 ) ;
return - 1 ;
}
return 0 ;
case V_89 :
V_26 -> V_46 . V_47 = F_14 ( V_66 ) ;
if ( V_26 -> V_46 . V_47 == 0 ) {
F_5 ( L_12 ) ;
return - 1 ;
}
return 0 ;
default:
F_5 ( L_13 , V_66 -> V_72 ) ;
return - 1 ;
}
}
static int F_17 ( struct V_25 * V_26 , struct V_65 * V_66 )
{
T_2 V_67 ;
unsigned V_38 ;
V_67 = F_14 ( V_66 ) ;
switch ( V_66 -> V_72 ) {
case V_90 :
if ( V_67 ) {
if ( V_26 -> V_29 . V_91 != 0 ) {
F_5 ( L_14 ) ;
return - 1 ;
}
V_26 -> V_29 . V_91 ++ ;
V_26 -> V_29 . V_92 ++ ;
} else {
if ( V_26 -> V_29 . V_91 < 1 ) {
F_5 ( L_15 ) ;
return - 1 ;
}
V_26 -> V_29 . V_91 -- ;
}
return 1 ;
case V_93 :
if ( V_26 -> V_29 . V_92 > 1 ) {
F_5 ( L_16 ) ;
return 0 ;
}
if ( V_66 -> V_11 <= 2 )
V_67 = ( V_26 -> V_46 . V_80 << 16 ) + V_67 ;
return F_11 ( V_26 , V_67 ) ;
case V_94 :
if ( V_26 -> V_29 . V_92 > 1 ) {
F_5 ( L_16 ) ;
return 0 ;
}
if ( V_66 -> V_11 <= 2 )
V_67 = ( V_26 -> V_46 . V_80 << 16 ) + V_67 ;
V_26 -> V_29 . V_95 = V_67 ;
return 0 ;
case V_96 :
if ( V_26 -> V_29 . V_92 > 1 ) {
F_5 ( L_16 ) ;
return 0 ;
}
if ( V_66 -> V_11 <= 2 )
V_67 = ( V_26 -> V_46 . V_80 << 16 ) + V_67 ;
for ( V_38 = V_26 -> V_29 . V_95 ; V_38 <= V_67 ; V_38 ++ )
if ( F_11 ( V_26 , V_38 ) ) {
F_5 ( L_17 ) ;
return - 1 ;
}
return 0 ;
default:
F_5 ( L_18 , V_66 -> V_72 ) ;
return 0 ;
}
return 0 ;
}
static int F_18 ( struct V_25 * V_26 , struct V_65 * V_66 )
{
T_2 V_67 ;
int V_97 ;
V_67 = F_14 ( V_66 ) ;
switch ( V_66 -> V_72 ) {
case V_98 :
V_97 = F_6 ( V_26 , V_67 & 0xff ) ;
break;
case V_99 :
V_97 = F_9 ( V_26 ) ;
break;
case V_100 :
V_97 = F_12 ( V_26 , V_101 , V_67 ) ;
break;
case V_102 :
V_97 = F_12 ( V_26 , V_103 , V_67 ) ;
break;
case V_104 :
V_97 = F_12 ( V_26 , V_105 , V_67 ) ;
break;
default:
F_5 ( L_19 , V_66 -> V_72 ) ;
V_97 = 0 ;
}
memset ( & V_26 -> V_29 , 0 , sizeof( V_26 -> V_29 ) ) ;
return V_97 ;
}
static int F_19 ( struct V_25 * V_26 , struct V_65 * V_66 )
{
F_5 ( L_20 , V_66 -> V_72 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_7 )
{
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_7 -> V_18 ; V_38 ++ )
F_8 ( V_7 -> V_17 [ V_38 ] ) ;
F_8 ( V_7 ) ;
}
static void F_21 ( struct V_3 * V_106 )
{
struct V_2 * V_3 = F_22 ( V_106 , struct V_2 , V_106 ) ;
unsigned V_45 , V_57 ;
for ( V_45 = 0 ; V_45 < V_107 ; V_45 ++ ) {
struct V_5 * V_6 = V_3 -> V_6 + V_45 ;
for ( V_57 = 0 ; V_57 < 256 ; V_57 ++ ) {
struct V_1 * V_7 = V_6 -> V_8 [ V_57 ] ;
if ( V_7 )
F_20 ( V_7 ) ;
}
}
F_8 ( V_3 -> V_108 ) ;
F_8 ( V_3 -> V_28 ) ;
F_8 ( V_3 ) ;
}
static V_68 * F_23 ( T_3 * V_109 , T_3 * V_110 , struct V_65 * V_66 )
{
V_68 V_111 ;
if ( ( V_110 - V_109 ) <= 0 )
return NULL ;
V_111 = * V_109 ++ ;
V_66 -> type = ( V_111 >> 2 ) & 3 ;
V_66 -> V_72 = ( V_111 >> 4 ) & 15 ;
if ( V_66 -> V_72 == V_112 ) {
V_66 -> V_113 = V_114 ;
if ( ( V_110 - V_109 ) < 2 )
return NULL ;
V_66 -> V_11 = * V_109 ++ ;
V_66 -> V_72 = * V_109 ++ ;
if ( ( V_110 - V_109 ) < V_66 -> V_11 )
return NULL ;
V_66 -> V_67 . V_115 = V_109 ;
V_109 += V_66 -> V_11 ;
return V_109 ;
}
V_66 -> V_113 = V_116 ;
V_66 -> V_11 = V_111 & 3 ;
switch ( V_66 -> V_11 ) {
case 0 :
return V_109 ;
case 1 :
if ( ( V_110 - V_109 ) < 1 )
return NULL ;
V_66 -> V_67 . V_68 = * V_109 ++ ;
return V_109 ;
case 2 :
if ( ( V_110 - V_109 ) < 2 )
return NULL ;
V_66 -> V_67 . V_69 = F_24 ( V_109 ) ;
V_109 = ( T_3 * ) ( ( V_117 * ) V_109 + 1 ) ;
return V_109 ;
case 3 :
V_66 -> V_11 ++ ;
if ( ( V_110 - V_109 ) < 4 )
return NULL ;
V_66 -> V_67 . T_1 = F_25 ( V_109 ) ;
V_109 = ( T_3 * ) ( ( V_118 * ) V_109 + 1 ) ;
return V_109 ;
}
return NULL ;
}
int F_26 ( struct V_2 * V_3 , T_3 * V_109 ,
unsigned V_11 )
{
struct V_25 * V_26 ;
struct V_65 V_66 ;
T_3 * V_110 ;
int V_97 ;
static int (* F_27 [])( struct V_25 * V_26 ,
struct V_65 * V_66 ) = {
F_18 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static V_24 F_28 ( T_2 V_23 , unsigned V_38 )
{
switch ( V_38 ) {
case 8 : return ( ( V_119 ) V_23 ) ;
case 16 : return ( ( V_120 ) V_23 ) ;
case 32 : return ( ( V_121 ) V_23 ) ;
}
return V_23 & ( 1 << ( V_38 - 1 ) ) ? V_23 | ( - 1 << V_38 ) : V_23 ;
}
static T_1 F_29 ( V_121 V_23 , unsigned V_38 )
{
V_24 V_122 = V_23 >> ( V_38 - 1 ) ;
if ( V_122 && V_122 != - 1 )
return V_23 < 0 ? 1 << ( V_38 - 1 ) : ( 1 << ( V_38 - 1 ) ) - 1 ;
return V_23 & ( ( 1 << V_38 ) - 1 ) ;
}
static T_2 F_30 ( const struct V_2 * V_58 , T_3 * V_7 ,
unsigned V_44 , unsigned V_38 )
{
T_4 V_123 ;
if ( V_38 > 32 )
F_31 ( V_58 , L_21 ,
V_38 , V_124 -> V_125 ) ;
V_7 += V_44 >> 3 ;
V_44 &= 7 ;
V_123 = F_32 ( V_7 ) ;
V_123 = ( V_123 >> V_44 ) & ( ( 1ULL << V_38 ) - 1 ) ;
return ( T_1 ) V_123 ;
}
static void F_33 ( const struct V_2 * V_58 , T_3 * V_7 ,
unsigned V_44 , unsigned V_38 , T_2 V_23 )
{
T_4 V_123 ;
T_4 V_126 = ( 1ULL << V_38 ) - 1 ;
if ( V_38 > 32 )
F_31 ( V_58 , L_22 ,
V_127 , V_38 , V_124 -> V_125 ) ;
if ( V_23 > V_126 )
F_31 ( V_58 , L_23 ,
V_127 , V_23 , V_124 -> V_125 ) ;
F_34 ( V_23 > V_126 ) ;
V_23 &= V_126 ;
V_7 += V_44 >> 3 ;
V_44 &= 7 ;
V_123 = F_32 ( V_7 ) ;
V_123 &= ~ ( V_126 << V_44 ) ;
V_123 |= ( ( T_4 ) V_23 ) << V_44 ;
F_35 ( V_123 , V_7 ) ;
}
static int F_36 ( V_121 * V_128 , V_121 V_23 , unsigned V_38 )
{
while ( V_38 -- ) {
if ( * V_128 ++ == V_23 )
return 0 ;
}
return - 1 ;
}
static int F_37 ( struct V_2 * V_58 , struct V_1 * V_7 )
{
const struct V_129 * V_4 = V_58 -> V_130 -> V_131 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_42 != V_132 ; V_4 ++ )
if ( V_4 -> V_42 == V_133 ||
V_4 -> V_42 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_58 , struct V_20 * V_22 )
{
const struct V_134 * V_4 = V_58 -> V_130 -> V_135 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_136 != V_133 - 1 ; V_4 ++ )
if ( ( V_4 -> V_137 == V_133 ||
V_4 -> V_137 == V_22 -> V_58 ) &&
( V_4 -> V_136 == V_133 ||
V_4 -> V_136 == V_22 -> type ) &&
( V_4 -> V_138 == V_133 ||
V_4 -> V_138 == V_22 -> V_139 ) )
return 1 ;
return 0 ;
}
static void F_39 ( struct V_2 * V_58 , struct V_14 * V_17 ,
struct V_20 * V_22 , V_121 V_23 , int V_140 )
{
struct V_141 * V_142 = V_58 -> V_130 ;
int V_97 ;
F_40 ( V_58 , V_22 , V_23 ) ;
if ( V_142 && V_142 -> V_143 && F_38 ( V_58 , V_22 ) ) {
V_97 = V_142 -> V_143 ( V_58 , V_17 , V_22 , V_23 ) ;
if ( V_97 != 0 ) {
if ( V_97 < 0 )
F_5 ( L_24 ,
V_142 -> V_144 , V_97 ) ;
return;
}
}
if ( V_58 -> V_145 & V_146 )
F_41 ( V_58 , V_17 , V_22 , V_23 ) ;
if ( V_58 -> V_145 & V_147 && V_140 && V_58 -> V_148 )
V_58 -> V_148 ( V_58 , V_17 , V_22 , V_23 ) ;
}
static void F_42 ( struct V_2 * V_58 , struct V_14 * V_17 ,
T_3 * V_67 , int V_140 )
{
unsigned V_38 ;
unsigned V_149 = V_17 -> V_51 ;
unsigned V_44 = V_17 -> V_60 ;
unsigned V_11 = V_17 -> V_50 ;
V_121 V_150 = V_17 -> V_49 ;
V_121 V_151 = V_17 -> V_48 ;
V_121 * V_23 ;
V_23 = F_7 ( sizeof( V_121 ) * V_149 , V_152 ) ;
if ( ! V_23 )
return;
for ( V_38 = 0 ; V_38 < V_149 ; V_38 ++ ) {
V_23 [ V_38 ] = V_150 < 0 ?
F_28 ( F_30 ( V_58 , V_67 , V_44 + V_38 * V_11 , V_11 ) ,
V_11 ) :
F_30 ( V_58 , V_67 , V_44 + V_38 * V_11 , V_11 ) ;
if ( ! ( V_17 -> V_43 & V_153 ) &&
V_23 [ V_38 ] >= V_150 && V_23 [ V_38 ] <= V_151 &&
V_17 -> V_22 [ V_23 [ V_38 ] - V_150 ] . V_58 == V_154 + 1 )
goto exit;
}
for ( V_38 = 0 ; V_38 < V_149 ; V_38 ++ ) {
if ( V_153 & V_17 -> V_43 ) {
F_39 ( V_58 , V_17 , & V_17 -> V_22 [ V_38 ] , V_23 [ V_38 ] , V_140 ) ;
continue;
}
if ( V_17 -> V_23 [ V_38 ] >= V_150 && V_17 -> V_23 [ V_38 ] <= V_151
&& V_17 -> V_22 [ V_17 -> V_23 [ V_38 ] - V_150 ] . V_58
&& F_36 ( V_23 , V_17 -> V_23 [ V_38 ] , V_149 ) )
F_39 ( V_58 , V_17 , & V_17 -> V_22 [ V_17 -> V_23 [ V_38 ] - V_150 ] , 0 , V_140 ) ;
if ( V_23 [ V_38 ] >= V_150 && V_23 [ V_38 ] <= V_151
&& V_17 -> V_22 [ V_23 [ V_38 ] - V_150 ] . V_58
&& F_36 ( V_17 -> V_23 , V_23 [ V_38 ] , V_149 ) )
F_39 ( V_58 , V_17 , & V_17 -> V_22 [ V_23 [ V_38 ] - V_150 ] , 1 , V_140 ) ;
}
memcpy ( V_17 -> V_23 , V_23 , V_149 * sizeof( V_121 ) ) ;
exit:
F_8 ( V_23 ) ;
}
static void F_43 ( const struct V_2 * V_58 ,
struct V_14 * V_17 , T_3 * V_67 )
{
unsigned V_149 = V_17 -> V_51 ;
unsigned V_44 = V_17 -> V_60 ;
unsigned V_11 = V_17 -> V_50 ;
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_149 ; V_38 ++ ) {
if ( V_17 -> V_49 < 0 )
F_33 ( V_58 , V_67 , V_44 + V_38 * V_11 , V_11 ,
F_29 ( V_17 -> V_23 [ V_38 ] , V_11 ) ) ;
else
F_33 ( V_58 , V_67 , V_44 + V_38 * V_11 , V_11 ,
V_17 -> V_23 [ V_38 ] ) ;
}
}
void F_44 ( struct V_1 * V_7 , T_3 * V_67 )
{
unsigned V_38 ;
if ( V_7 -> V_4 > 0 )
* V_67 ++ = V_7 -> V_4 ;
memset ( V_67 , 0 , ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ) ;
for ( V_38 = 0 ; V_38 < V_7 -> V_18 ; V_38 ++ )
F_43 ( V_7 -> V_3 , V_7 -> V_17 [ V_38 ] , V_67 ) ;
}
int F_45 ( struct V_14 * V_17 , unsigned V_44 , V_121 V_23 )
{
unsigned V_11 = V_17 -> V_50 ;
F_40 ( V_17 -> V_7 -> V_3 , V_17 -> V_22 + V_44 , V_23 ) ;
if ( V_44 >= V_17 -> V_51 ) {
F_5 ( L_25 , V_44 , V_17 -> V_51 ) ;
return - 1 ;
}
if ( V_17 -> V_49 < 0 ) {
if ( V_23 != F_28 ( F_29 ( V_23 , V_11 ) , V_11 ) ) {
F_5 ( L_26 , V_23 ) ;
return - 1 ;
}
}
V_17 -> V_23 [ V_44 ] = V_23 ;
return 0 ;
}
static struct V_1 * F_46 ( struct V_5 * V_6 ,
const V_68 * V_67 )
{
struct V_1 * V_7 ;
unsigned int V_38 = 0 ;
if ( V_6 -> V_10 )
V_38 = * V_67 ;
V_7 = V_6 -> V_8 [ V_38 ] ;
if ( V_7 == NULL )
F_5 ( L_27 , V_38 ) ;
return V_7 ;
}
void F_47 ( struct V_2 * V_58 , int type , V_68 * V_67 , int V_11 ,
int V_140 )
{
struct V_5 * V_6 = V_58 -> V_6 + type ;
struct V_1 * V_7 ;
unsigned int V_122 ;
int V_155 , V_156 = V_11 ;
V_68 * V_157 = V_67 ;
V_7 = F_46 ( V_6 , V_67 ) ;
if ( ! V_7 )
return;
if ( V_6 -> V_10 ) {
V_157 ++ ;
V_156 -- ;
}
V_155 = ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ;
if ( V_155 > V_158 )
V_155 = V_158 ;
if ( V_156 < V_155 ) {
F_5 ( L_28 , V_7 -> V_4 ,
V_156 , V_155 ) ;
memset ( V_157 + V_156 , 0 , V_155 - V_156 ) ;
}
if ( ( V_58 -> V_145 & V_147 ) && V_58 -> V_159 )
V_58 -> V_159 ( V_58 , V_7 ) ;
if ( V_58 -> V_145 & V_160 )
F_48 ( V_58 , V_67 , V_11 ) ;
for ( V_122 = 0 ; V_122 < V_7 -> V_18 ; V_122 ++ )
F_42 ( V_58 , V_7 -> V_17 [ V_122 ] , V_157 , V_140 ) ;
if ( V_58 -> V_145 & V_146 )
F_49 ( V_58 , V_7 ) ;
}
int F_50 ( struct V_2 * V_58 , int type , V_68 * V_67 , int V_11 , int V_140 )
{
struct V_5 * V_6 ;
struct V_141 * V_142 ;
struct V_1 * V_7 ;
char * V_161 ;
unsigned int V_45 ;
int V_97 = 0 ;
if ( ! V_58 )
return - V_162 ;
if ( F_51 ( & V_58 -> V_163 ) )
return - V_164 ;
if ( ! V_58 -> V_130 ) {
V_97 = - V_162 ;
goto V_165;
}
V_6 = V_58 -> V_6 + type ;
V_142 = V_58 -> V_130 ;
if ( ! V_11 ) {
F_5 ( L_29 ) ;
V_97 = - 1 ;
goto V_165;
}
V_161 = F_7 ( sizeof( char ) * V_166 , V_152 ) ;
if ( ! V_161 )
goto V_167;
snprintf ( V_161 , V_166 - 1 ,
L_30 , V_11 , V_6 -> V_10 ? L_31 : L_32 ) ;
F_52 ( V_58 , V_161 ) ;
for ( V_45 = 0 ; V_45 < V_11 ; V_45 ++ ) {
snprintf ( V_161 , V_166 - 1 ,
L_33 , V_67 [ V_45 ] ) ;
F_52 ( V_58 , V_161 ) ;
}
F_52 ( V_58 , L_34 ) ;
F_8 ( V_161 ) ;
V_167:
V_7 = F_46 ( V_6 , V_67 ) ;
if ( ! V_7 ) {
V_97 = - 1 ;
goto V_165;
}
if ( V_142 && V_142 -> V_168 && F_37 ( V_58 , V_7 ) ) {
V_97 = V_142 -> V_168 ( V_58 , V_7 , V_67 , V_11 ) ;
if ( V_97 != 0 ) {
V_97 = V_97 < 0 ? V_97 : 0 ;
goto V_165;
}
}
F_47 ( V_58 , type , V_67 , V_11 , V_140 ) ;
V_165:
F_53 ( & V_58 -> V_163 ) ;
return V_97 ;
}
static bool F_54 ( struct V_2 * V_169 ,
const struct V_170 * V_4 )
{
return V_4 -> V_171 == V_169 -> V_171 &&
( V_4 -> V_172 == V_133 || V_4 -> V_172 == V_169 -> V_172 ) &&
( V_4 -> V_173 == V_133 || V_4 -> V_173 == V_169 -> V_173 ) ;
}
static const struct V_170 * F_55 ( struct V_2 * V_169 ,
const struct V_170 * V_4 )
{
for (; V_4 -> V_171 ; V_4 ++ )
if ( F_54 ( V_169 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_56 ( struct V_2 * V_169 )
{
return ! ! F_55 ( V_169 , V_174 ) ;
}
static T_5
F_57 ( struct V_175 * V_176 , struct V_177 * V_178 ,
struct V_179 * V_180 ,
char * V_161 , T_6 V_181 , T_7 V_149 )
{
struct V_3 * V_106 = F_22 ( V_178 , struct V_3 , V_178 ) ;
struct V_2 * V_169 = F_22 ( V_106 , struct V_2 , V_106 ) ;
if ( V_181 >= V_169 -> V_155 )
return 0 ;
if ( V_181 + V_149 > V_169 -> V_155 )
V_149 = V_169 -> V_155 - V_181 ;
memcpy ( V_161 , V_169 -> V_108 + V_181 , V_149 ) ;
return V_149 ;
}
int F_58 ( struct V_2 * V_169 , unsigned int V_182 )
{
static const char * V_183 [] = { L_35 , L_36 , L_37 , L_35 ,
L_38 , L_39 , L_40 , L_41 ,
L_42
} ;
const char * type , * V_171 ;
char V_161 [ 64 ] ;
unsigned int V_45 ;
int V_184 ;
int V_97 ;
if ( V_169 -> V_185 & V_186 )
V_182 |= ( V_187 | V_188 ) ;
if ( V_169 -> V_185 & V_189 )
V_182 |= V_190 ;
if ( V_169 -> V_171 != V_191 )
V_182 &= ~ V_188 ;
if ( F_56 ( V_169 ) )
V_182 |= V_187 ;
if ( ( V_182 & V_192 ) && ! F_59 ( V_169 ,
V_182 & V_190 ) )
V_169 -> V_145 |= V_146 ;
if ( V_169 -> V_185 & V_193 ) {
V_169 -> V_185 &= ~ V_193 ;
return - V_162 ;
}
if ( ( V_182 & V_188 ) && V_169 -> V_194 &&
! V_169 -> V_194 ( V_169 ,
V_182 & V_187 ) )
V_169 -> V_145 |= V_147 ;
if ( ( V_182 & V_195 ) && ! F_60 ( V_169 ) )
V_169 -> V_145 |= V_160 ;
if ( ! V_169 -> V_145 ) {
F_61 ( V_169 , L_43 ) ;
return - V_162 ;
}
if ( ( V_169 -> V_145 & V_146 ) &&
( V_182 & V_196 ) && V_169 -> V_197 )
V_169 -> V_197 ( V_169 ) ;
V_184 = 0 ;
if ( V_169 -> V_145 & V_146 )
V_184 += sprintf ( V_161 + V_184 , L_44 ) ;
if ( V_169 -> V_145 & V_147 )
V_184 += sprintf ( V_161 + V_184 , L_45 , V_184 ? L_46 : L_31 ,
V_169 -> V_198 ) ;
if ( V_169 -> V_145 & V_160 )
V_184 += sprintf ( V_161 + V_184 , L_47 , V_184 ? L_46 : L_31 ,
( (struct V_199 * ) V_169 -> V_199 ) -> V_198 ) ;
type = L_35 ;
for ( V_45 = 0 ; V_45 < V_169 -> V_32 ; V_45 ++ ) {
struct V_27 * V_200 = & V_169 -> V_28 [ V_45 ] ;
if ( V_200 -> type == V_36 &&
( V_200 -> V_22 & V_201 ) == V_202 &&
( V_200 -> V_22 & 0xffff ) < F_62 ( V_183 ) ) {
type = V_183 [ V_200 -> V_22 & 0xffff ] ;
break;
}
}
switch ( V_169 -> V_171 ) {
case V_191 :
V_171 = L_48 ;
break;
case V_203 :
V_171 = L_49 ;
break;
default:
V_171 = L_50 ;
}
V_97 = F_63 ( & V_169 -> V_106 , & V_204 ) ;
if ( V_97 )
F_31 ( V_169 ,
L_51 , V_97 ) ;
F_64 ( V_169 , L_52 ,
V_161 , V_171 , V_169 -> V_205 >> 8 , V_169 -> V_205 & 0xff ,
type , V_169 -> V_144 , V_169 -> V_206 ) ;
return 0 ;
}
void F_65 ( struct V_2 * V_169 )
{
F_66 ( & V_169 -> V_106 , & V_204 ) ;
if ( V_169 -> V_145 & V_146 )
F_67 ( V_169 ) ;
if ( V_169 -> V_145 & V_147 )
V_169 -> V_207 ( V_169 ) ;
if ( V_169 -> V_145 & V_160 )
F_68 ( V_169 ) ;
}
static T_5 F_69 ( struct V_208 * V_209 , const char * V_161 ,
T_7 V_149 )
{
struct V_141 * V_142 = F_22 ( V_209 , struct V_141 , V_130 ) ;
struct V_210 * V_211 ;
T_2 V_171 , V_172 , V_173 ;
unsigned long V_212 = 0 ;
int V_97 ;
V_97 = sscanf ( V_161 , L_53 ,
& V_171 , & V_172 , & V_173 , & V_212 ) ;
if ( V_97 < 3 )
return - V_213 ;
V_211 = F_2 ( sizeof( * V_211 ) , V_9 ) ;
if ( ! V_211 )
return - V_214 ;
V_211 -> V_4 . V_171 = V_171 ;
V_211 -> V_4 . V_172 = V_172 ;
V_211 -> V_4 . V_173 = V_173 ;
V_211 -> V_4 . V_212 = V_212 ;
F_70 ( & V_142 -> V_215 ) ;
F_3 ( & V_211 -> V_12 , & V_142 -> V_216 ) ;
F_71 ( & V_142 -> V_215 ) ;
V_97 = 0 ;
if ( F_72 ( & V_142 -> V_130 ) ) {
V_97 = F_73 ( & V_142 -> V_130 ) ;
F_74 ( & V_142 -> V_130 ) ;
}
return V_97 ? : V_149 ;
}
static void F_75 ( struct V_141 * V_142 )
{
struct V_210 * V_211 , * V_38 ;
F_70 ( & V_142 -> V_215 ) ;
F_76 (dynid, n, &hdrv->dyn_list, list) {
F_77 ( & V_211 -> V_12 ) ;
F_8 ( V_211 ) ;
}
F_71 ( & V_142 -> V_215 ) ;
}
static const struct V_170 * F_78 ( struct V_2 * V_169 ,
struct V_141 * V_142 )
{
struct V_210 * V_211 ;
F_70 ( & V_142 -> V_215 ) ;
F_79 (dynid, &hdrv->dyn_list, list) {
if ( F_54 ( V_169 , & V_211 -> V_4 ) ) {
F_71 ( & V_142 -> V_215 ) ;
return & V_211 -> V_4 ;
}
}
F_71 ( & V_142 -> V_215 ) ;
return F_55 ( V_169 , V_142 -> V_217 ) ;
}
static int F_80 ( struct V_3 * V_106 , struct V_208 * V_209 )
{
struct V_141 * V_142 = F_22 ( V_209 , struct V_141 , V_130 ) ;
struct V_2 * V_169 = F_22 ( V_106 , struct V_2 , V_106 ) ;
if ( ! F_78 ( V_169 , V_142 ) )
return 0 ;
if ( ! strncmp ( V_142 -> V_144 , L_54 , 8 ) )
return ! F_55 ( V_169 , V_218 ) ;
return 1 ;
}
static int F_81 ( struct V_3 * V_106 )
{
struct V_141 * V_142 = F_22 ( V_106 -> V_130 ,
struct V_141 , V_130 ) ;
struct V_2 * V_169 = F_22 ( V_106 , struct V_2 , V_106 ) ;
const struct V_170 * V_4 ;
int V_97 = 0 ;
if ( F_82 ( & V_169 -> V_163 ) )
return - V_219 ;
if ( ! V_169 -> V_130 ) {
V_4 = F_78 ( V_169 , V_142 ) ;
if ( V_4 == NULL ) {
V_97 = - V_162 ;
goto V_165;
}
V_169 -> V_130 = V_142 ;
if ( V_142 -> V_220 ) {
V_97 = V_142 -> V_220 ( V_169 , V_4 ) ;
} else {
V_97 = F_83 ( V_169 ) ;
if ( ! V_97 )
V_97 = F_84 ( V_169 , V_221 ) ;
}
if ( V_97 )
V_169 -> V_130 = NULL ;
}
V_165:
F_53 ( & V_169 -> V_163 ) ;
return V_97 ;
}
static int F_85 ( struct V_3 * V_106 )
{
struct V_2 * V_169 = F_22 ( V_106 , struct V_2 , V_106 ) ;
struct V_141 * V_142 ;
if ( F_82 ( & V_169 -> V_163 ) )
return - V_219 ;
V_142 = V_169 -> V_130 ;
if ( V_142 ) {
if ( V_142 -> remove )
V_142 -> remove ( V_169 ) ;
else
F_86 ( V_169 ) ;
V_169 -> V_130 = NULL ;
}
F_53 ( & V_169 -> V_163 ) ;
return 0 ;
}
static int F_87 ( struct V_3 * V_106 , struct V_222 * V_223 )
{
struct V_2 * V_169 = F_22 ( V_106 , struct V_2 , V_106 ) ;
if ( F_88 ( V_223 , L_55 ,
V_169 -> V_171 , V_169 -> V_172 , V_169 -> V_173 ) )
return - V_214 ;
if ( F_88 ( V_223 , L_56 , V_169 -> V_144 ) )
return - V_214 ;
if ( F_88 ( V_223 , L_57 , V_169 -> V_206 ) )
return - V_214 ;
if ( F_88 ( V_223 , L_58 , V_169 -> V_224 ) )
return - V_214 ;
if ( F_88 ( V_223 , L_59 ,
V_169 -> V_171 , V_169 -> V_172 , V_169 -> V_173 ) )
return - V_214 ;
return 0 ;
}
static bool F_89 ( struct V_2 * V_169 )
{
switch ( V_169 -> V_172 ) {
case V_225 :
if ( V_169 -> V_173 >= V_226 &&
V_169 -> V_173 <= V_227 )
return true ;
break;
case V_228 :
if ( V_169 -> V_173 >= V_229 &&
V_169 -> V_173 <= V_230 )
return true ;
break;
case V_231 :
if ( V_169 -> V_173 >= V_232 &&
V_169 -> V_173 <= V_233 )
return true ;
break;
case V_234 :
if ( V_169 -> V_173 >= V_235 &&
V_169 -> V_173 <= V_236 )
return true ;
break;
case V_237 :
if ( V_169 -> V_173 == V_238 &&
V_169 -> type == V_239 )
return true ;
break;
}
if ( V_169 -> type == V_240 &&
F_55 ( V_169 , V_241 ) )
return true ;
return ! ! F_55 ( V_169 , V_242 ) ;
}
int F_90 ( struct V_2 * V_169 )
{
static T_8 V_4 = F_91 ( 0 ) ;
int V_97 ;
if ( F_34 ( V_169 -> V_243 & V_244 ) )
return - V_164 ;
if ( ! ( V_169 -> V_185 & V_245 )
&& ( F_89 ( V_169 ) || ( V_169 -> V_185 & V_246 ) ) )
return - V_162 ;
F_92 ( & V_169 -> V_106 , L_60 , V_169 -> V_171 ,
V_169 -> V_172 , V_169 -> V_173 , F_93 ( & V_4 ) ) ;
F_94 ( V_169 , F_95 ( & V_169 -> V_106 ) ) ;
V_97 = F_96 ( & V_169 -> V_106 ) ;
if ( ! V_97 )
V_169 -> V_243 |= V_244 ;
else
F_97 ( V_169 ) ;
return V_97 ;
}
struct V_2 * F_98 ( void )
{
struct V_2 * V_169 ;
unsigned int V_45 ;
int V_97 = - V_214 ;
V_169 = F_2 ( sizeof( * V_169 ) , V_9 ) ;
if ( V_169 == NULL )
return F_99 ( V_97 ) ;
F_100 ( & V_169 -> V_106 ) ;
V_169 -> V_106 . V_247 = F_21 ;
V_169 -> V_106 . V_171 = & V_248 ;
V_169 -> V_28 = F_101 ( V_249 ,
sizeof( struct V_27 ) , V_9 ) ;
if ( V_169 -> V_28 == NULL )
goto V_250;
V_169 -> V_33 = V_249 ;
for ( V_45 = 0 ; V_45 < V_107 ; V_45 ++ )
F_102 ( & V_169 -> V_6 [ V_45 ] . V_13 ) ;
F_103 ( & V_169 -> V_251 ) ;
F_102 ( & V_169 -> V_252 ) ;
F_104 ( & V_169 -> V_163 , 1 ) ;
return V_169 ;
V_250:
F_105 ( & V_169 -> V_106 ) ;
return F_99 ( V_97 ) ;
}
static void F_106 ( struct V_2 * V_169 )
{
if ( V_169 -> V_243 & V_244 ) {
F_107 ( & V_169 -> V_106 ) ;
F_97 ( V_169 ) ;
V_169 -> V_243 &= ~ V_244 ;
}
}
void F_108 ( struct V_2 * V_169 )
{
F_106 ( V_169 ) ;
F_105 ( & V_169 -> V_106 ) ;
}
int F_109 ( struct V_141 * V_142 , struct V_253 * V_254 ,
const char * V_255 )
{
int V_97 ;
V_142 -> V_130 . V_144 = V_142 -> V_144 ;
V_142 -> V_130 . V_171 = & V_248 ;
V_142 -> V_130 . V_254 = V_254 ;
V_142 -> V_130 . V_255 = V_255 ;
F_102 ( & V_142 -> V_216 ) ;
F_110 ( & V_142 -> V_215 ) ;
V_97 = F_111 ( & V_142 -> V_130 ) ;
if ( V_97 )
return V_97 ;
V_97 = F_112 ( & V_142 -> V_130 , & V_256 ) ;
if ( V_97 )
F_113 ( & V_142 -> V_130 ) ;
return V_97 ;
}
void F_114 ( struct V_141 * V_142 )
{
F_115 ( & V_142 -> V_130 , & V_256 ) ;
F_113 ( & V_142 -> V_130 ) ;
F_75 ( V_142 ) ;
}
int F_116 ( struct V_2 * V_58 )
{
struct V_257 * V_258 ;
int V_45 ;
if ( ! ( V_58 -> V_145 & V_146 ) )
return 0 ;
F_79 (hidinput, &hid->inputs, list) {
for ( V_45 = 0 ; V_45 < F_117 ( V_259 ) ; V_45 ++ )
if ( V_258 -> V_260 -> V_261 [ V_45 ] )
return 1 ;
}
return 0 ;
}
static int T_9 F_118 ( void )
{
int V_97 ;
if ( V_262 )
F_119 ( L_61
L_62 ) ;
V_97 = F_120 ( & V_248 ) ;
if ( V_97 ) {
F_121 ( L_63 ) ;
goto V_250;
}
V_97 = F_122 () ;
if ( V_97 )
goto V_263;
F_123 () ;
return 0 ;
V_263:
F_124 ( & V_248 ) ;
V_250:
return V_97 ;
}
static void T_10 F_125 ( void )
{
F_126 () ;
F_127 () ;
F_124 ( & V_248 ) ;
}
