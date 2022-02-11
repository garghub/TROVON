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
F_5 ( V_7 -> V_3 , L_1 ) ;
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
F_5 ( V_26 -> V_3 , L_2 ) ;
return - V_32 ;
}
if ( V_26 -> V_3 -> V_33 == V_26 -> V_3 -> V_34 ) {
V_28 = F_7 ( sizeof( struct V_27 ) *
V_26 -> V_3 -> V_34 * 2 , V_9 ) ;
if ( V_28 == NULL ) {
F_5 ( V_26 -> V_3 , L_3 ) ;
return - V_35 ;
}
memcpy ( V_28 , V_26 -> V_3 -> V_28 ,
sizeof( struct V_27 ) *
V_26 -> V_3 -> V_34 ) ;
memset ( V_28 + V_26 -> V_3 -> V_34 , 0 ,
sizeof( struct V_27 ) *
V_26 -> V_3 -> V_34 ) ;
F_8 ( V_26 -> V_3 -> V_28 ) ;
V_26 -> V_3 -> V_28 = V_28 ;
V_26 -> V_3 -> V_34 *= 2 ;
}
V_26 -> V_36 [ V_26 -> V_30 ++ ] =
V_26 -> V_3 -> V_33 ;
V_28 = V_26 -> V_3 -> V_28 +
V_26 -> V_3 -> V_33 ++ ;
V_28 -> type = type ;
V_28 -> V_22 = V_22 ;
V_28 -> V_37 = V_26 -> V_30 - 1 ;
if ( type == V_38 )
V_26 -> V_3 -> V_39 ++ ;
return 0 ;
}
static int F_9 ( struct V_25 * V_26 )
{
if ( ! V_26 -> V_30 ) {
F_5 ( V_26 -> V_3 , L_4 ) ;
return - V_32 ;
}
V_26 -> V_30 -- ;
return 0 ;
}
static unsigned F_10 ( struct V_25 * V_26 , unsigned type )
{
struct V_27 * V_28 = V_26 -> V_3 -> V_28 ;
int V_40 ;
for ( V_40 = V_26 -> V_30 - 1 ; V_40 >= 0 ; V_40 -- ) {
unsigned V_21 = V_26 -> V_36 [ V_40 ] ;
if ( V_28 [ V_21 ] . type == type )
return V_28 [ V_21 ] . V_22 ;
}
return 0 ;
}
static int F_11 ( struct V_25 * V_26 , unsigned V_22 )
{
if ( V_26 -> V_29 . V_41 >= V_42 ) {
F_5 ( V_26 -> V_3 , L_5 ) ;
return - 1 ;
}
V_26 -> V_29 . V_22 [ V_26 -> V_29 . V_41 ] = V_22 ;
V_26 -> V_29 . V_43 [ V_26 -> V_29 . V_41 ] =
V_26 -> V_30 ?
V_26 -> V_36 [ V_26 -> V_30 - 1 ] : 0 ;
V_26 -> V_29 . V_41 ++ ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 , unsigned V_44 , unsigned V_45 )
{
struct V_1 * V_7 ;
struct V_14 * V_17 ;
int V_15 ;
unsigned V_46 ;
int V_47 ;
V_7 = F_1 ( V_26 -> V_3 , V_44 , V_26 -> V_48 . V_49 ) ;
if ( ! V_7 ) {
F_5 ( V_26 -> V_3 , L_6 ) ;
return - 1 ;
}
if ( ( V_26 -> V_48 . V_50 < 0 &&
V_26 -> V_48 . V_51 <
V_26 -> V_48 . V_50 ) ||
( V_26 -> V_48 . V_50 >= 0 &&
( V_52 ) V_26 -> V_48 . V_51 <
( V_52 ) V_26 -> V_48 . V_50 ) ) {
F_13 ( L_7 ,
V_26 -> V_48 . V_50 ,
V_26 -> V_48 . V_51 ) ;
return - 1 ;
}
V_46 = V_7 -> V_11 ;
V_7 -> V_11 += V_26 -> V_48 . V_53 * V_26 -> V_48 . V_54 ;
if ( ! V_26 -> V_29 . V_41 )
return 0 ;
V_15 = F_14 ( int , V_26 -> V_29 . V_41 , V_26 -> V_48 . V_54 ) ;
V_17 = F_4 ( V_7 , V_15 , V_26 -> V_48 . V_54 ) ;
if ( ! V_17 )
return 0 ;
V_17 -> V_55 = F_10 ( V_26 , V_56 ) ;
V_17 -> V_57 = F_10 ( V_26 , V_58 ) ;
V_17 -> V_59 = F_10 ( V_26 , V_38 ) ;
for ( V_47 = 0 ; V_47 < V_15 ; V_47 ++ ) {
int V_60 = V_47 ;
if ( V_47 >= V_26 -> V_29 . V_41 )
V_60 = V_26 -> V_29 . V_41 - 1 ;
V_17 -> V_22 [ V_47 ] . V_61 = V_26 -> V_29 . V_22 [ V_60 ] ;
V_17 -> V_22 [ V_47 ] . V_43 =
V_26 -> V_29 . V_43 [ V_60 ] ;
}
V_17 -> V_62 = V_15 ;
V_17 -> V_45 = V_45 ;
V_17 -> V_63 = V_46 ;
V_17 -> V_44 = V_44 ;
V_17 -> V_53 = V_26 -> V_48 . V_53 ;
V_17 -> V_54 = V_26 -> V_48 . V_54 ;
V_17 -> V_50 = V_26 -> V_48 . V_50 ;
V_17 -> V_51 = V_26 -> V_48 . V_51 ;
V_17 -> V_64 = V_26 -> V_48 . V_64 ;
V_17 -> V_65 = V_26 -> V_48 . V_65 ;
V_17 -> V_66 = V_26 -> V_48 . V_66 ;
V_17 -> V_67 = V_26 -> V_48 . V_67 ;
return 0 ;
}
static T_1 F_15 ( struct V_68 * V_69 )
{
switch ( V_69 -> V_11 ) {
case 1 : return V_69 -> V_70 . V_71 ;
case 2 : return V_69 -> V_70 . V_72 ;
case 4 : return V_69 -> V_70 . T_1 ;
}
return 0 ;
}
static V_24 F_16 ( struct V_68 * V_69 )
{
switch ( V_69 -> V_11 ) {
case 1 : return V_69 -> V_70 . V_73 ;
case 2 : return V_69 -> V_70 . V_74 ;
case 4 : return V_69 -> V_70 . V_24 ;
}
return 0 ;
}
static int F_17 ( struct V_25 * V_26 , struct V_68 * V_69 )
{
switch ( V_69 -> V_75 ) {
case V_76 :
if ( V_26 -> V_77 == V_78 ) {
F_5 ( V_26 -> V_3 , L_8 ) ;
return - 1 ;
}
memcpy ( V_26 -> V_79 + V_26 -> V_77 ++ ,
& V_26 -> V_48 , sizeof( struct V_80 ) ) ;
return 0 ;
case V_81 :
if ( ! V_26 -> V_77 ) {
F_5 ( V_26 -> V_3 , L_9 ) ;
return - 1 ;
}
memcpy ( & V_26 -> V_48 , V_26 -> V_79 +
-- V_26 -> V_77 , sizeof( struct V_80 ) ) ;
return 0 ;
case V_82 :
V_26 -> V_48 . V_83 = F_15 ( V_69 ) ;
return 0 ;
case V_84 :
V_26 -> V_48 . V_50 = F_16 ( V_69 ) ;
return 0 ;
case V_85 :
if ( V_26 -> V_48 . V_50 < 0 )
V_26 -> V_48 . V_51 = F_16 ( V_69 ) ;
else
V_26 -> V_48 . V_51 = F_15 ( V_69 ) ;
return 0 ;
case V_86 :
V_26 -> V_48 . V_64 = F_16 ( V_69 ) ;
return 0 ;
case V_87 :
if ( V_26 -> V_48 . V_64 < 0 )
V_26 -> V_48 . V_65 = F_16 ( V_69 ) ;
else
V_26 -> V_48 . V_65 = F_15 ( V_69 ) ;
return 0 ;
case V_88 :
V_26 -> V_48 . V_66 = F_16 ( V_69 ) ;
return 0 ;
case V_89 :
V_26 -> V_48 . V_67 = F_15 ( V_69 ) ;
return 0 ;
case V_90 :
V_26 -> V_48 . V_53 = F_15 ( V_69 ) ;
if ( V_26 -> V_48 . V_53 > 128 ) {
F_5 ( V_26 -> V_3 , L_10 ,
V_26 -> V_48 . V_53 ) ;
return - 1 ;
}
return 0 ;
case V_91 :
V_26 -> V_48 . V_54 = F_15 ( V_69 ) ;
if ( V_26 -> V_48 . V_54 > V_42 ) {
F_5 ( V_26 -> V_3 , L_11 ,
V_26 -> V_48 . V_54 ) ;
return - 1 ;
}
return 0 ;
case V_92 :
V_26 -> V_48 . V_49 = F_15 ( V_69 ) ;
if ( V_26 -> V_48 . V_49 == 0 ) {
F_5 ( V_26 -> V_3 , L_12 ) ;
return - 1 ;
}
return 0 ;
default:
F_5 ( V_26 -> V_3 , L_13 , V_69 -> V_75 ) ;
return - 1 ;
}
}
static int F_18 ( struct V_25 * V_26 , struct V_68 * V_69 )
{
V_52 V_70 ;
unsigned V_40 ;
V_70 = F_15 ( V_69 ) ;
switch ( V_69 -> V_75 ) {
case V_93 :
if ( V_70 ) {
if ( V_26 -> V_29 . V_94 != 0 ) {
F_5 ( V_26 -> V_3 , L_14 ) ;
return - 1 ;
}
V_26 -> V_29 . V_94 ++ ;
V_26 -> V_29 . V_95 ++ ;
} else {
if ( V_26 -> V_29 . V_94 < 1 ) {
F_5 ( V_26 -> V_3 , L_15 ) ;
return - 1 ;
}
V_26 -> V_29 . V_94 -- ;
}
return 1 ;
case V_96 :
if ( V_26 -> V_29 . V_95 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_69 -> V_11 <= 2 )
V_70 = ( V_26 -> V_48 . V_83 << 16 ) + V_70 ;
return F_11 ( V_26 , V_70 ) ;
case V_97 :
if ( V_26 -> V_29 . V_95 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_69 -> V_11 <= 2 )
V_70 = ( V_26 -> V_48 . V_83 << 16 ) + V_70 ;
V_26 -> V_29 . V_98 = V_70 ;
return 0 ;
case V_99 :
if ( V_26 -> V_29 . V_95 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_69 -> V_11 <= 2 )
V_70 = ( V_26 -> V_48 . V_83 << 16 ) + V_70 ;
for ( V_40 = V_26 -> V_29 . V_98 ; V_40 <= V_70 ; V_40 ++ )
if ( F_11 ( V_26 , V_40 ) ) {
F_13 ( L_17 ) ;
return - 1 ;
}
return 0 ;
default:
F_13 ( L_18 , V_69 -> V_75 ) ;
return 0 ;
}
return 0 ;
}
static int F_19 ( struct V_25 * V_26 , struct V_68 * V_69 )
{
V_52 V_70 ;
int V_100 ;
V_70 = F_15 ( V_69 ) ;
switch ( V_69 -> V_75 ) {
case V_101 :
V_100 = F_6 ( V_26 , V_70 & 0xff ) ;
break;
case V_102 :
V_100 = F_9 ( V_26 ) ;
break;
case V_103 :
V_100 = F_12 ( V_26 , V_104 , V_70 ) ;
break;
case V_105 :
V_100 = F_12 ( V_26 , V_106 , V_70 ) ;
break;
case V_107 :
V_100 = F_12 ( V_26 , V_108 , V_70 ) ;
break;
default:
F_5 ( V_26 -> V_3 , L_19 , V_69 -> V_75 ) ;
V_100 = 0 ;
}
memset ( & V_26 -> V_29 , 0 , sizeof( V_26 -> V_29 ) ) ;
return V_100 ;
}
static int F_20 ( struct V_25 * V_26 , struct V_68 * V_69 )
{
F_13 ( L_20 , V_69 -> V_75 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_7 )
{
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < V_7 -> V_18 ; V_40 ++ )
F_8 ( V_7 -> V_17 [ V_40 ] ) ;
F_8 ( V_7 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned V_47 , V_60 ;
for ( V_47 = 0 ; V_47 < V_109 ; V_47 ++ ) {
struct V_5 * V_6 = V_3 -> V_6 + V_47 ;
for ( V_60 = 0 ; V_60 < 256 ; V_60 ++ ) {
struct V_1 * V_7 = V_6 -> V_8 [ V_60 ] ;
if ( V_7 )
F_21 ( V_7 ) ;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_23 ( & V_6 -> V_13 ) ;
}
F_8 ( V_3 -> V_110 ) ;
V_3 -> V_110 = NULL ;
V_3 -> V_111 = 0 ;
F_8 ( V_3 -> V_28 ) ;
V_3 -> V_28 = NULL ;
V_3 -> V_34 = 0 ;
V_3 -> V_33 = 0 ;
V_3 -> V_39 = 0 ;
V_3 -> V_112 &= ~ V_113 ;
}
static void F_24 ( struct V_3 * V_114 )
{
struct V_2 * V_61 = F_25 ( V_114 , struct V_2 , V_114 ) ;
F_22 ( V_61 ) ;
F_8 ( V_61 -> V_115 ) ;
F_8 ( V_61 ) ;
}
static V_71 * F_26 ( T_2 * V_116 , T_2 * V_117 , struct V_68 * V_69 )
{
V_71 V_118 ;
if ( ( V_117 - V_116 ) <= 0 )
return NULL ;
V_118 = * V_116 ++ ;
V_69 -> type = ( V_118 >> 2 ) & 3 ;
V_69 -> V_75 = ( V_118 >> 4 ) & 15 ;
if ( V_69 -> V_75 == V_119 ) {
V_69 -> V_120 = V_121 ;
if ( ( V_117 - V_116 ) < 2 )
return NULL ;
V_69 -> V_11 = * V_116 ++ ;
V_69 -> V_75 = * V_116 ++ ;
if ( ( V_117 - V_116 ) < V_69 -> V_11 )
return NULL ;
V_69 -> V_70 . V_122 = V_116 ;
V_116 += V_69 -> V_11 ;
return V_116 ;
}
V_69 -> V_120 = V_123 ;
V_69 -> V_11 = V_118 & 3 ;
switch ( V_69 -> V_11 ) {
case 0 :
return V_116 ;
case 1 :
if ( ( V_117 - V_116 ) < 1 )
return NULL ;
V_69 -> V_70 . V_71 = * V_116 ++ ;
return V_116 ;
case 2 :
if ( ( V_117 - V_116 ) < 2 )
return NULL ;
V_69 -> V_70 . V_72 = F_27 ( V_116 ) ;
V_116 = ( T_2 * ) ( ( V_124 * ) V_116 + 1 ) ;
return V_116 ;
case 3 :
V_69 -> V_11 ++ ;
if ( ( V_117 - V_116 ) < 4 )
return NULL ;
V_69 -> V_70 . T_1 = F_28 ( V_116 ) ;
V_116 = ( T_2 * ) ( ( V_125 * ) V_116 + 1 ) ;
return V_116 ;
}
return NULL ;
}
static void F_29 ( struct V_2 * V_61 , T_1 V_22 )
{
if ( V_22 == V_126 )
V_61 -> V_127 = V_128 ;
}
static int F_30 ( struct V_2 * V_61 )
{
unsigned int V_129 = 0 , V_130 = 0 ;
T_2 * V_116 = V_61 -> V_115 ;
T_2 * V_117 = V_116 + V_61 -> V_131 ;
unsigned int V_132 , V_133 = 0 , V_134 = 0 ;
struct V_68 V_69 ;
V_61 -> V_127 = V_135 ;
while ( ( V_116 = F_26 ( V_116 , V_117 , & V_69 ) ) != NULL ) {
if ( V_69 . V_120 != V_123 )
return - V_32 ;
if ( V_69 . type == V_136 ) {
if ( V_69 . V_75 == V_82 )
V_129 = F_15 ( & V_69 ) << 16 ;
} else if ( V_69 . type == V_137 ) {
if ( V_130 > 1 )
break;
V_132 = F_15 ( & V_69 ) ;
if ( V_69 . V_11 <= 2 )
V_132 += V_129 ;
switch ( V_69 . V_75 ) {
case V_93 :
V_130 += ! ! V_132 ;
break;
case V_96 :
F_29 ( V_61 , V_132 ) ;
break;
case V_97 :
V_133 = V_132 ;
break;
case V_99 :
V_134 = V_132 ;
for ( V_132 = V_133 ; V_132 <= V_134 ; V_132 ++ )
F_29 ( V_61 , V_132 ) ;
break;
}
}
}
return 0 ;
}
int F_31 ( struct V_2 * V_61 , T_2 * V_116 , unsigned V_11 )
{
V_61 -> V_115 = F_32 ( V_116 , V_11 , V_9 ) ;
if ( ! V_61 -> V_115 )
return - V_35 ;
V_61 -> V_131 = V_11 ;
return 0 ;
}
int F_33 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
struct V_68 V_69 ;
unsigned int V_11 ;
T_2 * V_116 ;
T_2 * V_138 ;
T_2 * V_117 ;
int V_100 ;
static int (* F_34 [])( struct V_25 * V_26 ,
struct V_68 * V_69 ) = {
F_19 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static V_24 F_35 ( V_52 V_23 , unsigned V_40 )
{
switch ( V_40 ) {
case 8 : return ( ( V_139 ) V_23 ) ;
case 16 : return ( ( V_140 ) V_23 ) ;
case 32 : return ( ( V_141 ) V_23 ) ;
}
return V_23 & ( 1 << ( V_40 - 1 ) ) ? V_23 | ( - 1 << V_40 ) : V_23 ;
}
static T_1 F_36 ( V_141 V_23 , unsigned V_40 )
{
V_24 V_142 = V_23 >> ( V_40 - 1 ) ;
if ( V_142 && V_142 != - 1 )
return V_23 < 0 ? 1 << ( V_40 - 1 ) : ( 1 << ( V_40 - 1 ) ) - 1 ;
return V_23 & ( ( 1 << V_40 ) - 1 ) ;
}
static V_52 F_37 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_46 , unsigned V_40 )
{
T_3 V_143 ;
if ( V_40 > 32 )
F_38 ( V_61 , L_21 ,
V_40 , V_144 -> V_145 ) ;
V_7 += V_46 >> 3 ;
V_46 &= 7 ;
V_143 = F_39 ( V_7 ) ;
V_143 = ( V_143 >> V_46 ) & ( ( 1ULL << V_40 ) - 1 ) ;
return ( T_1 ) V_143 ;
}
static void F_40 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_46 , unsigned V_40 , V_52 V_23 )
{
T_3 V_143 ;
T_3 V_146 = ( 1ULL << V_40 ) - 1 ;
if ( V_40 > 32 )
F_38 ( V_61 , L_22 ,
V_147 , V_40 , V_144 -> V_145 ) ;
if ( V_23 > V_146 )
F_38 ( V_61 , L_23 ,
V_147 , V_23 , V_144 -> V_145 ) ;
F_41 ( V_23 > V_146 ) ;
V_23 &= V_146 ;
V_7 += V_46 >> 3 ;
V_46 &= 7 ;
V_143 = F_39 ( V_7 ) ;
V_143 &= ~ ( V_146 << V_46 ) ;
V_143 |= ( ( T_3 ) V_23 ) << V_46 ;
F_42 ( V_143 , V_7 ) ;
}
static int F_43 ( V_141 * V_148 , V_141 V_23 , unsigned V_40 )
{
while ( V_40 -- ) {
if ( * V_148 ++ == V_23 )
return 0 ;
}
return - 1 ;
}
static int F_44 ( struct V_2 * V_61 , struct V_1 * V_7 )
{
const struct V_149 * V_4 = V_61 -> V_150 -> V_151 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_44 != V_152 ; V_4 ++ )
if ( V_4 -> V_44 == V_153 ||
V_4 -> V_44 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_61 , struct V_20 * V_22 )
{
const struct V_154 * V_4 = V_61 -> V_150 -> V_155 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_156 != V_153 - 1 ; V_4 ++ )
if ( ( V_4 -> V_157 == V_153 ||
V_4 -> V_157 == V_22 -> V_61 ) &&
( V_4 -> V_156 == V_153 ||
V_4 -> V_156 == V_22 -> type ) &&
( V_4 -> V_158 == V_153 ||
V_4 -> V_158 == V_22 -> V_159 ) )
return 1 ;
return 0 ;
}
static void F_46 ( struct V_2 * V_61 , struct V_14 * V_17 ,
struct V_20 * V_22 , V_141 V_23 , int V_160 )
{
struct V_161 * V_162 = V_61 -> V_150 ;
int V_100 ;
if ( ! F_47 ( & V_61 -> V_163 ) )
F_48 ( V_61 , V_22 , V_23 ) ;
if ( V_162 && V_162 -> V_164 && F_45 ( V_61 , V_22 ) ) {
V_100 = V_162 -> V_164 ( V_61 , V_17 , V_22 , V_23 ) ;
if ( V_100 != 0 ) {
if ( V_100 < 0 )
F_5 ( V_61 , L_24 ,
V_162 -> V_165 , V_100 ) ;
return;
}
}
if ( V_61 -> V_166 & V_167 )
F_49 ( V_61 , V_17 , V_22 , V_23 ) ;
if ( V_61 -> V_166 & V_168 && V_160 && V_61 -> V_169 )
V_61 -> V_169 ( V_61 , V_17 , V_22 , V_23 ) ;
}
static void F_50 ( struct V_2 * V_61 , struct V_14 * V_17 ,
T_2 * V_70 , int V_160 )
{
unsigned V_40 ;
unsigned V_170 = V_17 -> V_54 ;
unsigned V_46 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
V_141 V_171 = V_17 -> V_50 ;
V_141 V_172 = V_17 -> V_51 ;
V_141 * V_23 ;
V_23 = F_7 ( sizeof( V_141 ) * V_170 , V_173 ) ;
if ( ! V_23 )
return;
for ( V_40 = 0 ; V_40 < V_170 ; V_40 ++ ) {
V_23 [ V_40 ] = V_171 < 0 ?
F_35 ( F_37 ( V_61 , V_70 , V_46 + V_40 * V_11 , V_11 ) ,
V_11 ) :
F_37 ( V_61 , V_70 , V_46 + V_40 * V_11 , V_11 ) ;
if ( ! ( V_17 -> V_45 & V_174 ) &&
V_23 [ V_40 ] >= V_171 && V_23 [ V_40 ] <= V_172 &&
V_17 -> V_22 [ V_23 [ V_40 ] - V_171 ] . V_61 == V_175 + 1 )
goto exit;
}
for ( V_40 = 0 ; V_40 < V_170 ; V_40 ++ ) {
if ( V_174 & V_17 -> V_45 ) {
F_46 ( V_61 , V_17 , & V_17 -> V_22 [ V_40 ] , V_23 [ V_40 ] , V_160 ) ;
continue;
}
if ( V_17 -> V_23 [ V_40 ] >= V_171 && V_17 -> V_23 [ V_40 ] <= V_172
&& V_17 -> V_22 [ V_17 -> V_23 [ V_40 ] - V_171 ] . V_61
&& F_43 ( V_23 , V_17 -> V_23 [ V_40 ] , V_170 ) )
F_46 ( V_61 , V_17 , & V_17 -> V_22 [ V_17 -> V_23 [ V_40 ] - V_171 ] , 0 , V_160 ) ;
if ( V_23 [ V_40 ] >= V_171 && V_23 [ V_40 ] <= V_172
&& V_17 -> V_22 [ V_23 [ V_40 ] - V_171 ] . V_61
&& F_43 ( V_17 -> V_23 , V_23 [ V_40 ] , V_170 ) )
F_46 ( V_61 , V_17 , & V_17 -> V_22 [ V_23 [ V_40 ] - V_171 ] , 1 , V_160 ) ;
}
memcpy ( V_17 -> V_23 , V_23 , V_170 * sizeof( V_141 ) ) ;
exit:
F_8 ( V_23 ) ;
}
static void F_51 ( const struct V_2 * V_61 ,
struct V_14 * V_17 , T_2 * V_70 )
{
unsigned V_170 = V_17 -> V_54 ;
unsigned V_46 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < V_170 ; V_40 ++ ) {
if ( V_17 -> V_50 < 0 )
F_40 ( V_61 , V_70 , V_46 + V_40 * V_11 , V_11 ,
F_36 ( V_17 -> V_23 [ V_40 ] , V_11 ) ) ;
else
F_40 ( V_61 , V_70 , V_46 + V_40 * V_11 , V_11 ,
V_17 -> V_23 [ V_40 ] ) ;
}
}
void F_52 ( struct V_1 * V_7 , T_2 * V_70 )
{
unsigned V_40 ;
if ( V_7 -> V_4 > 0 )
* V_70 ++ = V_7 -> V_4 ;
memset ( V_70 , 0 , ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ) ;
for ( V_40 = 0 ; V_40 < V_7 -> V_18 ; V_40 ++ )
F_51 ( V_7 -> V_3 , V_7 -> V_17 [ V_40 ] , V_70 ) ;
}
int F_53 ( struct V_14 * V_17 , unsigned V_46 , V_141 V_23 )
{
unsigned V_11 = V_17 -> V_53 ;
F_48 ( V_17 -> V_7 -> V_3 , V_17 -> V_22 + V_46 , V_23 ) ;
if ( V_46 >= V_17 -> V_54 ) {
F_5 ( V_17 -> V_7 -> V_3 , L_25 ,
V_46 , V_17 -> V_54 ) ;
return - 1 ;
}
if ( V_17 -> V_50 < 0 ) {
if ( V_23 != F_35 ( F_36 ( V_23 , V_11 ) , V_11 ) ) {
F_5 ( V_17 -> V_7 -> V_3 , L_26 , V_23 ) ;
return - 1 ;
}
}
V_17 -> V_23 [ V_46 ] = V_23 ;
return 0 ;
}
static struct V_1 * F_54 ( struct V_5 * V_6 ,
const V_71 * V_70 )
{
struct V_1 * V_7 ;
unsigned int V_40 = 0 ;
if ( V_6 -> V_10 )
V_40 = * V_70 ;
V_7 = V_6 -> V_8 [ V_40 ] ;
if ( V_7 == NULL )
F_13 ( L_27 , V_40 ) ;
return V_7 ;
}
int F_55 ( struct V_2 * V_61 , int type , V_71 * V_70 , int V_11 ,
int V_160 )
{
struct V_5 * V_6 = V_61 -> V_6 + type ;
struct V_1 * V_7 ;
unsigned int V_142 ;
int V_111 , V_176 = V_11 ;
V_71 * V_177 = V_70 ;
int V_100 = 0 ;
V_7 = F_54 ( V_6 , V_70 ) ;
if ( ! V_7 )
goto V_178;
if ( V_6 -> V_10 ) {
V_177 ++ ;
V_176 -- ;
}
V_111 = ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ;
if ( V_111 > V_179 )
V_111 = V_179 ;
if ( V_176 < V_111 ) {
F_13 ( L_28 , V_7 -> V_4 ,
V_176 , V_111 ) ;
memset ( V_177 + V_176 , 0 , V_111 - V_176 ) ;
}
if ( ( V_61 -> V_166 & V_168 ) && V_61 -> V_180 )
V_61 -> V_180 ( V_61 , V_7 ) ;
if ( V_61 -> V_166 & V_181 ) {
V_100 = F_56 ( V_61 , V_70 , V_11 ) ;
if ( V_100 )
goto V_178;
}
if ( V_61 -> V_166 != V_181 ) {
for ( V_142 = 0 ; V_142 < V_7 -> V_18 ; V_142 ++ )
F_50 ( V_61 , V_7 -> V_17 [ V_142 ] , V_177 , V_160 ) ;
}
if ( V_61 -> V_166 & V_167 )
F_57 ( V_61 , V_7 ) ;
V_178:
return V_100 ;
}
int F_58 ( struct V_2 * V_61 , int type , V_71 * V_70 , int V_11 , int V_160 )
{
struct V_5 * V_6 ;
struct V_161 * V_162 ;
struct V_1 * V_7 ;
char * V_138 ;
unsigned int V_47 ;
int V_100 = 0 ;
if ( ! V_61 )
return - V_182 ;
if ( F_59 ( & V_61 -> V_183 ) )
return - V_184 ;
if ( ! V_61 -> V_150 ) {
V_100 = - V_182 ;
goto V_185;
}
V_6 = V_61 -> V_6 + type ;
V_162 = V_61 -> V_150 ;
if ( ! V_11 ) {
F_13 ( L_29 ) ;
V_100 = - 1 ;
goto V_185;
}
if ( F_47 ( & V_61 -> V_163 ) )
goto V_186;
V_138 = F_7 ( sizeof( char ) * V_187 , V_173 ) ;
if ( ! V_138 )
goto V_186;
snprintf ( V_138 , V_187 - 1 ,
L_30 , V_11 , V_6 -> V_10 ? L_31 : L_32 ) ;
F_60 ( V_61 , V_138 ) ;
for ( V_47 = 0 ; V_47 < V_11 ; V_47 ++ ) {
snprintf ( V_138 , V_187 - 1 ,
L_33 , V_70 [ V_47 ] ) ;
F_60 ( V_61 , V_138 ) ;
}
F_60 ( V_61 , L_34 ) ;
F_8 ( V_138 ) ;
V_186:
V_7 = F_54 ( V_6 , V_70 ) ;
if ( ! V_7 ) {
V_100 = - 1 ;
goto V_185;
}
if ( V_162 && V_162 -> V_188 && F_44 ( V_61 , V_7 ) ) {
V_100 = V_162 -> V_188 ( V_61 , V_7 , V_70 , V_11 ) ;
if ( V_100 != 0 ) {
V_100 = V_100 < 0 ? V_100 : 0 ;
goto V_185;
}
}
V_100 = F_55 ( V_61 , type , V_70 , V_11 , V_160 ) ;
V_185:
F_61 ( & V_61 -> V_183 ) ;
return V_100 ;
}
static bool F_62 ( struct V_2 * V_189 ,
const struct V_190 * V_4 )
{
return ( V_4 -> V_191 == V_192 || V_4 -> V_191 == V_189 -> V_191 ) &&
( V_4 -> V_127 == V_193 || V_4 -> V_127 == V_189 -> V_127 ) &&
( V_4 -> V_194 == V_153 || V_4 -> V_194 == V_189 -> V_194 ) &&
( V_4 -> V_195 == V_153 || V_4 -> V_195 == V_189 -> V_195 ) ;
}
const struct V_190 * F_63 ( struct V_2 * V_189 ,
const struct V_190 * V_4 )
{
for (; V_4 -> V_191 ; V_4 ++ )
if ( F_62 ( V_189 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_64 ( struct V_2 * V_189 )
{
return ! ! F_63 ( V_189 , V_196 ) ;
}
static T_4
F_65 ( struct V_197 * V_198 , struct V_199 * V_200 ,
struct V_201 * V_202 ,
char * V_138 , T_5 V_203 , T_6 V_170 )
{
struct V_3 * V_114 = F_25 ( V_200 , struct V_3 , V_200 ) ;
struct V_2 * V_189 = F_25 ( V_114 , struct V_2 , V_114 ) ;
if ( V_203 >= V_189 -> V_111 )
return 0 ;
if ( V_203 + V_170 > V_189 -> V_111 )
V_170 = V_189 -> V_111 - V_203 ;
memcpy ( V_138 , V_189 -> V_110 + V_203 , V_170 ) ;
return V_170 ;
}
int F_66 ( struct V_2 * V_189 , unsigned int V_204 )
{
static const char * V_205 [] = { L_35 , L_36 , L_37 , L_35 ,
L_38 , L_39 , L_40 , L_41 ,
L_42
} ;
const char * type , * V_191 ;
char V_138 [ 64 ] ;
unsigned int V_47 ;
int V_206 ;
int V_100 ;
if ( V_189 -> V_207 & V_208 )
V_204 |= ( V_209 | V_210 ) ;
if ( V_189 -> V_207 & V_211 )
V_204 |= V_212 ;
if ( V_189 -> V_191 != V_213 )
V_204 &= ~ V_210 ;
if ( F_64 ( V_189 ) )
V_204 |= V_209 ;
if ( ( V_204 & V_214 ) && ! F_67 ( V_189 ,
V_204 & V_212 ) )
V_189 -> V_166 |= V_167 ;
if ( ( V_204 & V_210 ) && V_189 -> V_215 &&
! V_189 -> V_215 ( V_189 ,
V_204 & V_209 ) )
V_189 -> V_166 |= V_168 ;
if ( ( V_204 & V_216 ) && ! F_68 ( V_189 ) )
V_189 -> V_166 |= V_181 ;
if ( ! V_189 -> V_166 && ! V_189 -> V_150 -> V_188 ) {
F_5 ( V_189 , L_43 ) ;
return - V_182 ;
}
if ( ( V_189 -> V_166 & V_167 ) &&
( V_204 & V_217 ) && V_189 -> V_218 )
V_189 -> V_218 ( V_189 ) ;
V_206 = 0 ;
if ( V_189 -> V_166 & V_167 )
V_206 += sprintf ( V_138 + V_206 , L_44 ) ;
if ( V_189 -> V_166 & V_168 )
V_206 += sprintf ( V_138 + V_206 , L_45 , V_206 ? L_46 : L_31 ,
V_189 -> V_219 ) ;
if ( V_189 -> V_166 & V_181 )
V_206 += sprintf ( V_138 + V_206 , L_47 , V_206 ? L_46 : L_31 ,
( (struct V_220 * ) V_189 -> V_220 ) -> V_219 ) ;
type = L_35 ;
for ( V_47 = 0 ; V_47 < V_189 -> V_33 ; V_47 ++ ) {
struct V_27 * V_221 = & V_189 -> V_28 [ V_47 ] ;
if ( V_221 -> type == V_38 &&
( V_221 -> V_22 & V_222 ) == V_223 &&
( V_221 -> V_22 & 0xffff ) < F_69 ( V_205 ) ) {
type = V_205 [ V_221 -> V_22 & 0xffff ] ;
break;
}
}
switch ( V_189 -> V_191 ) {
case V_213 :
V_191 = L_48 ;
break;
case V_224 :
V_191 = L_49 ;
break;
default:
V_191 = L_50 ;
}
V_100 = F_70 ( & V_189 -> V_114 , & V_225 ) ;
if ( V_100 )
F_38 ( V_189 ,
L_51 , V_100 ) ;
F_71 ( V_189 , L_52 ,
V_138 , V_191 , V_189 -> V_226 >> 8 , V_189 -> V_226 & 0xff ,
type , V_189 -> V_165 , V_189 -> V_227 ) ;
return 0 ;
}
void F_72 ( struct V_2 * V_189 )
{
F_73 ( & V_189 -> V_114 , & V_225 ) ;
if ( V_189 -> V_166 & V_167 )
F_74 ( V_189 ) ;
if ( V_189 -> V_166 & V_168 )
V_189 -> V_228 ( V_189 ) ;
if ( V_189 -> V_166 & V_181 )
F_75 ( V_189 ) ;
}
static T_4 F_76 ( struct V_229 * V_230 , const char * V_138 ,
T_6 V_170 )
{
struct V_161 * V_162 = F_25 ( V_230 , struct V_161 , V_150 ) ;
struct V_231 * V_232 ;
V_52 V_191 , V_194 , V_195 ;
unsigned long V_233 = 0 ;
int V_100 ;
V_100 = sscanf ( V_138 , L_53 ,
& V_191 , & V_194 , & V_195 , & V_233 ) ;
if ( V_100 < 3 )
return - V_32 ;
V_232 = F_2 ( sizeof( * V_232 ) , V_9 ) ;
if ( ! V_232 )
return - V_35 ;
V_232 -> V_4 . V_191 = V_191 ;
V_232 -> V_4 . V_127 = V_193 ;
V_232 -> V_4 . V_194 = V_194 ;
V_232 -> V_4 . V_195 = V_195 ;
V_232 -> V_4 . V_233 = V_233 ;
F_77 ( & V_162 -> V_234 ) ;
F_3 ( & V_232 -> V_12 , & V_162 -> V_235 ) ;
F_78 ( & V_162 -> V_234 ) ;
V_100 = F_79 ( & V_162 -> V_150 ) ;
return V_100 ? : V_170 ;
}
static void F_80 ( struct V_161 * V_162 )
{
struct V_231 * V_232 , * V_40 ;
F_77 ( & V_162 -> V_234 ) ;
F_81 (dynid, n, &hdrv->dyn_list, list) {
F_82 ( & V_232 -> V_12 ) ;
F_8 ( V_232 ) ;
}
F_78 ( & V_162 -> V_234 ) ;
}
static const struct V_190 * F_83 ( struct V_2 * V_189 ,
struct V_161 * V_162 )
{
struct V_231 * V_232 ;
F_77 ( & V_162 -> V_234 ) ;
F_84 (dynid, &hdrv->dyn_list, list) {
if ( F_62 ( V_189 , & V_232 -> V_4 ) ) {
F_78 ( & V_162 -> V_234 ) ;
return & V_232 -> V_4 ;
}
}
F_78 ( & V_162 -> V_234 ) ;
return F_63 ( V_189 , V_162 -> V_236 ) ;
}
static int F_85 ( struct V_3 * V_114 , struct V_229 * V_230 )
{
struct V_161 * V_162 = F_25 ( V_230 , struct V_161 , V_150 ) ;
struct V_2 * V_189 = F_25 ( V_114 , struct V_2 , V_114 ) ;
return F_83 ( V_189 , V_162 ) != NULL ;
}
static int F_86 ( struct V_3 * V_114 )
{
struct V_161 * V_162 = F_25 ( V_114 -> V_150 ,
struct V_161 , V_150 ) ;
struct V_2 * V_189 = F_25 ( V_114 , struct V_2 , V_114 ) ;
const struct V_190 * V_4 ;
int V_100 = 0 ;
if ( F_87 ( & V_189 -> V_183 ) )
return - V_237 ;
if ( ! V_189 -> V_150 ) {
V_4 = F_83 ( V_189 , V_162 ) ;
if ( V_4 == NULL ) {
V_100 = - V_182 ;
goto V_185;
}
V_189 -> V_150 = V_162 ;
if ( V_162 -> V_238 ) {
V_100 = V_162 -> V_238 ( V_189 , V_4 ) ;
} else {
V_100 = F_33 ( V_189 ) ;
if ( ! V_100 )
V_100 = F_88 ( V_189 , V_239 ) ;
}
if ( V_100 ) {
F_22 ( V_189 ) ;
V_189 -> V_150 = NULL ;
}
}
V_185:
F_61 ( & V_189 -> V_183 ) ;
return V_100 ;
}
static int F_89 ( struct V_3 * V_114 )
{
struct V_2 * V_189 = F_25 ( V_114 , struct V_2 , V_114 ) ;
struct V_161 * V_162 ;
if ( F_87 ( & V_189 -> V_183 ) )
return - V_237 ;
V_162 = V_189 -> V_150 ;
if ( V_162 ) {
if ( V_162 -> remove )
V_162 -> remove ( V_189 ) ;
else
F_90 ( V_189 ) ;
F_22 ( V_189 ) ;
V_189 -> V_150 = NULL ;
}
F_61 ( & V_189 -> V_183 ) ;
return 0 ;
}
static T_4 F_91 ( struct V_3 * V_114 , struct V_240 * V_142 ,
char * V_138 )
{
struct V_2 * V_189 = F_25 ( V_114 , struct V_2 , V_114 ) ;
int V_206 ;
V_206 = snprintf ( V_138 , V_241 , L_54 ,
V_189 -> V_191 , V_189 -> V_127 , V_189 -> V_194 , V_189 -> V_195 ) ;
return ( V_206 >= V_241 ) ? ( V_241 - 1 ) : V_206 ;
}
static int F_92 ( struct V_3 * V_114 , struct V_242 * V_243 )
{
struct V_2 * V_189 = F_25 ( V_114 , struct V_2 , V_114 ) ;
if ( F_93 ( V_243 , L_55 ,
V_189 -> V_191 , V_189 -> V_194 , V_189 -> V_195 ) )
return - V_35 ;
if ( F_93 ( V_243 , L_56 , V_189 -> V_165 ) )
return - V_35 ;
if ( F_93 ( V_243 , L_57 , V_189 -> V_227 ) )
return - V_35 ;
if ( F_93 ( V_243 , L_58 , V_189 -> V_244 ) )
return - V_35 ;
if ( F_93 ( V_243 , L_59 ,
V_189 -> V_191 , V_189 -> V_127 , V_189 -> V_194 , V_189 -> V_195 ) )
return - V_35 ;
return 0 ;
}
static bool F_94 ( struct V_2 * V_189 )
{
switch ( V_189 -> V_194 ) {
case V_245 :
if ( V_189 -> V_195 >= V_246 &&
V_189 -> V_195 <= V_247 )
return true ;
break;
case V_248 :
if ( V_189 -> V_195 >= V_249 &&
V_189 -> V_195 <= V_250 )
return true ;
if ( V_189 -> V_195 == V_251 &&
! strcmp ( V_189 -> V_165 , L_60 ) )
return true ;
break;
case V_252 :
if ( V_189 -> V_195 >= V_253 &&
V_189 -> V_195 <= V_254 )
return true ;
break;
case V_255 :
if ( V_189 -> V_195 >= V_256 &&
V_189 -> V_195 <= V_257 )
return true ;
break;
case V_258 :
if ( V_189 -> V_195 == V_259 &&
V_189 -> type == V_260 )
return true ;
break;
}
if ( V_189 -> type == V_261 &&
F_63 ( V_189 , V_262 ) )
return true ;
return ! ! F_63 ( V_189 , V_263 ) ;
}
int F_95 ( struct V_2 * V_189 )
{
static T_7 V_4 = F_96 ( 0 ) ;
int V_100 ;
if ( F_41 ( V_189 -> V_112 & V_264 ) )
return - V_184 ;
if ( ! ( V_189 -> V_207 & V_265 )
&& ( F_94 ( V_189 ) || ( V_189 -> V_207 & V_266 ) ) )
return - V_182 ;
V_100 = V_189 -> V_267 -> V_268 ( V_189 ) ;
if ( V_100 )
return V_100 ;
if ( ! V_189 -> V_115 )
return - V_182 ;
if ( V_269 ||
! F_63 ( V_189 , V_270 ) ) {
V_100 = F_30 ( V_189 ) ;
if ( V_100 )
F_38 ( V_189 , L_61 , V_100 ) ;
}
F_97 ( & V_189 -> V_114 , L_62 , V_189 -> V_191 ,
V_189 -> V_194 , V_189 -> V_195 , F_98 ( & V_4 ) ) ;
F_99 ( V_189 , F_100 ( & V_189 -> V_114 ) ) ;
V_100 = F_101 ( & V_189 -> V_114 ) ;
if ( ! V_100 )
V_189 -> V_112 |= V_264 ;
else
F_102 ( V_189 ) ;
return V_100 ;
}
struct V_2 * F_103 ( void )
{
struct V_2 * V_189 ;
int V_100 = - V_35 ;
V_189 = F_2 ( sizeof( * V_189 ) , V_9 ) ;
if ( V_189 == NULL )
return F_104 ( V_100 ) ;
F_105 ( & V_189 -> V_114 ) ;
V_189 -> V_114 . V_271 = F_24 ;
V_189 -> V_114 . V_191 = & V_272 ;
F_22 ( V_189 ) ;
F_106 ( & V_189 -> V_273 ) ;
F_23 ( & V_189 -> V_163 ) ;
F_107 ( & V_189 -> V_183 , 1 ) ;
return V_189 ;
}
static void F_108 ( struct V_2 * V_189 )
{
if ( V_189 -> V_112 & V_264 ) {
F_109 ( & V_189 -> V_114 ) ;
F_102 ( V_189 ) ;
V_189 -> V_112 &= ~ V_264 ;
}
F_8 ( V_189 -> V_115 ) ;
V_189 -> V_115 = NULL ;
V_189 -> V_131 = 0 ;
}
void F_110 ( struct V_2 * V_189 )
{
F_108 ( V_189 ) ;
F_111 ( & V_189 -> V_114 ) ;
}
int F_112 ( struct V_161 * V_162 , struct V_274 * V_275 ,
const char * V_276 )
{
int V_100 ;
V_162 -> V_150 . V_165 = V_162 -> V_165 ;
V_162 -> V_150 . V_191 = & V_272 ;
V_162 -> V_150 . V_275 = V_275 ;
V_162 -> V_150 . V_276 = V_276 ;
F_23 ( & V_162 -> V_235 ) ;
F_113 ( & V_162 -> V_234 ) ;
V_100 = F_114 ( & V_162 -> V_150 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_115 ( & V_162 -> V_150 , & V_277 ) ;
if ( V_100 )
F_116 ( & V_162 -> V_150 ) ;
return V_100 ;
}
void F_117 ( struct V_161 * V_162 )
{
F_118 ( & V_162 -> V_150 , & V_277 ) ;
F_116 ( & V_162 -> V_150 ) ;
F_80 ( V_162 ) ;
}
int F_119 ( struct V_2 * V_61 )
{
struct V_278 * V_279 ;
int V_47 ;
if ( ! ( V_61 -> V_166 & V_167 ) )
return 0 ;
F_84 (hidinput, &hid->inputs, list) {
for ( V_47 = 0 ; V_47 < F_120 ( V_280 ) ; V_47 ++ )
if ( V_279 -> V_281 -> V_282 [ V_47 ] )
return 1 ;
}
return 0 ;
}
static int T_8 F_121 ( void )
{
int V_100 ;
if ( V_283 )
F_122 ( L_63
L_64 ) ;
V_100 = F_123 ( & V_272 ) ;
if ( V_100 ) {
F_124 ( L_65 ) ;
goto V_284;
}
V_100 = F_125 () ;
if ( V_100 )
goto V_285;
F_126 () ;
return 0 ;
V_285:
F_127 ( & V_272 ) ;
V_284:
return V_100 ;
}
static void T_9 F_128 ( void )
{
F_129 () ;
F_130 () ;
F_127 ( & V_272 ) ;
}
