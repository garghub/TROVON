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
int V_18 ;
if ( V_7 -> V_19 == V_20 ) {
F_5 ( V_7 -> V_3 , L_1 ) ;
return NULL ;
}
V_17 = F_2 ( ( sizeof( struct V_14 ) +
V_15 * sizeof( struct V_21 ) +
V_16 * sizeof( unsigned ) ) , V_9 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_22 = V_7 -> V_19 ++ ;
V_7 -> V_17 [ V_17 -> V_22 ] = V_17 ;
V_17 -> V_23 = (struct V_21 * ) ( V_17 + 1 ) ;
V_17 -> V_24 = ( V_25 * ) ( V_17 -> V_23 + V_15 ) ;
V_17 -> V_7 = V_7 ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ )
V_17 -> V_23 [ V_18 ] . V_26 = V_18 ;
return V_17 ;
}
static int F_6 ( struct V_27 * V_28 , unsigned type )
{
struct V_29 * V_30 ;
unsigned V_23 ;
V_23 = V_28 -> V_31 . V_23 [ 0 ] ;
if ( V_28 -> V_32 == V_33 ) {
F_5 ( V_28 -> V_3 , L_2 ) ;
return - V_34 ;
}
if ( V_28 -> V_3 -> V_35 == V_28 -> V_3 -> V_36 ) {
V_30 = F_7 ( sizeof( struct V_29 ) *
V_28 -> V_3 -> V_36 * 2 , V_9 ) ;
if ( V_30 == NULL ) {
F_5 ( V_28 -> V_3 , L_3 ) ;
return - V_37 ;
}
memcpy ( V_30 , V_28 -> V_3 -> V_30 ,
sizeof( struct V_29 ) *
V_28 -> V_3 -> V_36 ) ;
memset ( V_30 + V_28 -> V_3 -> V_36 , 0 ,
sizeof( struct V_29 ) *
V_28 -> V_3 -> V_36 ) ;
F_8 ( V_28 -> V_3 -> V_30 ) ;
V_28 -> V_3 -> V_30 = V_30 ;
V_28 -> V_3 -> V_36 *= 2 ;
}
V_28 -> V_38 [ V_28 -> V_32 ++ ] =
V_28 -> V_3 -> V_35 ;
V_30 = V_28 -> V_3 -> V_30 +
V_28 -> V_3 -> V_35 ++ ;
V_30 -> type = type ;
V_30 -> V_23 = V_23 ;
V_30 -> V_39 = V_28 -> V_32 - 1 ;
if ( type == V_40 )
V_28 -> V_3 -> V_41 ++ ;
return 0 ;
}
static int F_9 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_32 ) {
F_5 ( V_28 -> V_3 , L_4 ) ;
return - V_34 ;
}
V_28 -> V_32 -- ;
return 0 ;
}
static unsigned F_10 ( struct V_27 * V_28 , unsigned type )
{
struct V_29 * V_30 = V_28 -> V_3 -> V_30 ;
int V_42 ;
for ( V_42 = V_28 -> V_32 - 1 ; V_42 >= 0 ; V_42 -- ) {
unsigned V_22 = V_28 -> V_38 [ V_42 ] ;
if ( V_30 [ V_22 ] . type == type )
return V_30 [ V_22 ] . V_23 ;
}
return 0 ;
}
static int F_11 ( struct V_27 * V_28 , unsigned V_23 )
{
if ( V_28 -> V_31 . V_26 >= V_43 ) {
F_5 ( V_28 -> V_3 , L_5 ) ;
return - 1 ;
}
V_28 -> V_31 . V_23 [ V_28 -> V_31 . V_26 ] = V_23 ;
V_28 -> V_31 . V_44 [ V_28 -> V_31 . V_26 ] =
V_28 -> V_32 ?
V_28 -> V_38 [ V_28 -> V_32 - 1 ] : 0 ;
V_28 -> V_31 . V_26 ++ ;
return 0 ;
}
static int F_12 ( struct V_27 * V_28 , unsigned V_45 , unsigned V_46 )
{
struct V_1 * V_7 ;
struct V_14 * V_17 ;
int V_15 ;
unsigned V_47 ;
int V_18 ;
V_7 = F_1 ( V_28 -> V_3 , V_45 , V_28 -> V_48 . V_49 ) ;
if ( ! V_7 ) {
F_5 ( V_28 -> V_3 , L_6 ) ;
return - 1 ;
}
if ( ( V_28 -> V_48 . V_50 < 0 &&
V_28 -> V_48 . V_51 <
V_28 -> V_48 . V_50 ) ||
( V_28 -> V_48 . V_50 >= 0 &&
( V_52 ) V_28 -> V_48 . V_51 <
( V_52 ) V_28 -> V_48 . V_50 ) ) {
F_13 ( L_7 ,
V_28 -> V_48 . V_50 ,
V_28 -> V_48 . V_51 ) ;
return - 1 ;
}
V_47 = V_7 -> V_11 ;
V_7 -> V_11 += V_28 -> V_48 . V_53 * V_28 -> V_48 . V_54 ;
if ( ! V_28 -> V_31 . V_26 )
return 0 ;
V_15 = F_14 ( int , V_28 -> V_31 . V_26 , V_28 -> V_48 . V_54 ) ;
V_17 = F_4 ( V_7 , V_15 , V_28 -> V_48 . V_54 ) ;
if ( ! V_17 )
return 0 ;
V_17 -> V_55 = F_10 ( V_28 , V_56 ) ;
V_17 -> V_57 = F_10 ( V_28 , V_58 ) ;
V_17 -> V_59 = F_10 ( V_28 , V_40 ) ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
int V_60 = V_18 ;
if ( V_18 >= V_28 -> V_31 . V_26 )
V_60 = V_28 -> V_31 . V_26 - 1 ;
V_17 -> V_23 [ V_18 ] . V_61 = V_28 -> V_31 . V_23 [ V_60 ] ;
V_17 -> V_23 [ V_18 ] . V_44 =
V_28 -> V_31 . V_44 [ V_60 ] ;
}
V_17 -> V_62 = V_15 ;
V_17 -> V_46 = V_46 ;
V_17 -> V_63 = V_47 ;
V_17 -> V_45 = V_45 ;
V_17 -> V_53 = V_28 -> V_48 . V_53 ;
V_17 -> V_54 = V_28 -> V_48 . V_54 ;
V_17 -> V_50 = V_28 -> V_48 . V_50 ;
V_17 -> V_51 = V_28 -> V_48 . V_51 ;
V_17 -> V_64 = V_28 -> V_48 . V_64 ;
V_17 -> V_65 = V_28 -> V_48 . V_65 ;
V_17 -> V_66 = V_28 -> V_48 . V_66 ;
V_17 -> V_67 = V_28 -> V_48 . V_67 ;
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
static V_25 F_16 ( struct V_68 * V_69 )
{
switch ( V_69 -> V_11 ) {
case 1 : return V_69 -> V_70 . V_73 ;
case 2 : return V_69 -> V_70 . V_74 ;
case 4 : return V_69 -> V_70 . V_25 ;
}
return 0 ;
}
static int F_17 ( struct V_27 * V_28 , struct V_68 * V_69 )
{
V_52 V_75 ;
switch ( V_69 -> V_76 ) {
case V_77 :
if ( V_28 -> V_78 == V_79 ) {
F_5 ( V_28 -> V_3 , L_8 ) ;
return - 1 ;
}
memcpy ( V_28 -> V_80 + V_28 -> V_78 ++ ,
& V_28 -> V_48 , sizeof( struct V_81 ) ) ;
return 0 ;
case V_82 :
if ( ! V_28 -> V_78 ) {
F_5 ( V_28 -> V_3 , L_9 ) ;
return - 1 ;
}
memcpy ( & V_28 -> V_48 , V_28 -> V_80 +
-- V_28 -> V_78 , sizeof( struct V_81 ) ) ;
return 0 ;
case V_83 :
V_28 -> V_48 . V_84 = F_15 ( V_69 ) ;
return 0 ;
case V_85 :
V_28 -> V_48 . V_50 = F_16 ( V_69 ) ;
return 0 ;
case V_86 :
if ( V_28 -> V_48 . V_50 < 0 )
V_28 -> V_48 . V_51 = F_16 ( V_69 ) ;
else
V_28 -> V_48 . V_51 = F_15 ( V_69 ) ;
return 0 ;
case V_87 :
V_28 -> V_48 . V_64 = F_16 ( V_69 ) ;
return 0 ;
case V_88 :
if ( V_28 -> V_48 . V_64 < 0 )
V_28 -> V_48 . V_65 = F_16 ( V_69 ) ;
else
V_28 -> V_48 . V_65 = F_15 ( V_69 ) ;
return 0 ;
case V_89 :
V_75 = F_15 ( V_69 ) ;
if ( ! ( V_75 & 0xfffffff0 ) )
V_28 -> V_48 . V_66 = F_18 ( V_75 , 4 ) ;
else
V_28 -> V_48 . V_66 = V_75 ;
return 0 ;
case V_90 :
V_28 -> V_48 . V_67 = F_15 ( V_69 ) ;
return 0 ;
case V_91 :
V_28 -> V_48 . V_53 = F_15 ( V_69 ) ;
if ( V_28 -> V_48 . V_53 > 128 ) {
F_5 ( V_28 -> V_3 , L_10 ,
V_28 -> V_48 . V_53 ) ;
return - 1 ;
}
return 0 ;
case V_92 :
V_28 -> V_48 . V_54 = F_15 ( V_69 ) ;
if ( V_28 -> V_48 . V_54 > V_43 ) {
F_5 ( V_28 -> V_3 , L_11 ,
V_28 -> V_48 . V_54 ) ;
return - 1 ;
}
return 0 ;
case V_93 :
V_28 -> V_48 . V_49 = F_15 ( V_69 ) ;
if ( V_28 -> V_48 . V_49 == 0 ) {
F_5 ( V_28 -> V_3 , L_12 ) ;
return - 1 ;
}
return 0 ;
default:
F_5 ( V_28 -> V_3 , L_13 , V_69 -> V_76 ) ;
return - 1 ;
}
}
static int F_19 ( struct V_27 * V_28 , struct V_68 * V_69 )
{
V_52 V_70 ;
unsigned V_42 ;
V_70 = F_15 ( V_69 ) ;
switch ( V_69 -> V_76 ) {
case V_94 :
if ( V_70 ) {
if ( V_28 -> V_31 . V_95 != 0 ) {
F_5 ( V_28 -> V_3 , L_14 ) ;
return - 1 ;
}
V_28 -> V_31 . V_95 ++ ;
V_28 -> V_31 . V_96 ++ ;
} else {
if ( V_28 -> V_31 . V_95 < 1 ) {
F_5 ( V_28 -> V_3 , L_15 ) ;
return - 1 ;
}
V_28 -> V_31 . V_95 -- ;
}
return 1 ;
case V_97 :
if ( V_28 -> V_31 . V_96 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_69 -> V_11 <= 2 )
V_70 = ( V_28 -> V_48 . V_84 << 16 ) + V_70 ;
return F_11 ( V_28 , V_70 ) ;
case V_98 :
if ( V_28 -> V_31 . V_96 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_69 -> V_11 <= 2 )
V_70 = ( V_28 -> V_48 . V_84 << 16 ) + V_70 ;
V_28 -> V_31 . V_99 = V_70 ;
return 0 ;
case V_100 :
if ( V_28 -> V_31 . V_96 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_69 -> V_11 <= 2 )
V_70 = ( V_28 -> V_48 . V_84 << 16 ) + V_70 ;
for ( V_42 = V_28 -> V_31 . V_99 ; V_42 <= V_70 ; V_42 ++ )
if ( F_11 ( V_28 , V_42 ) ) {
F_13 ( L_17 ) ;
return - 1 ;
}
return 0 ;
default:
F_13 ( L_18 , V_69 -> V_76 ) ;
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_27 * V_28 , struct V_68 * V_69 )
{
V_52 V_70 ;
int V_101 ;
V_70 = F_15 ( V_69 ) ;
switch ( V_69 -> V_76 ) {
case V_102 :
V_101 = F_6 ( V_28 , V_70 & 0xff ) ;
break;
case V_103 :
V_101 = F_9 ( V_28 ) ;
break;
case V_104 :
V_101 = F_12 ( V_28 , V_105 , V_70 ) ;
break;
case V_106 :
V_101 = F_12 ( V_28 , V_107 , V_70 ) ;
break;
case V_108 :
V_101 = F_12 ( V_28 , V_109 , V_70 ) ;
break;
default:
F_5 ( V_28 -> V_3 , L_19 , V_69 -> V_76 ) ;
V_101 = 0 ;
}
memset ( & V_28 -> V_31 , 0 , sizeof( V_28 -> V_31 ) ) ;
return V_101 ;
}
static int F_21 ( struct V_27 * V_28 , struct V_68 * V_69 )
{
F_13 ( L_20 , V_69 -> V_76 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_7 )
{
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_19 ; V_42 ++ )
F_8 ( V_7 -> V_17 [ V_42 ] ) ;
F_8 ( V_7 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
unsigned V_18 , V_60 ;
for ( V_18 = 0 ; V_18 < V_110 ; V_18 ++ ) {
struct V_5 * V_6 = V_3 -> V_6 + V_18 ;
for ( V_60 = 0 ; V_60 < 256 ; V_60 ++ ) {
struct V_1 * V_7 = V_6 -> V_8 [ V_60 ] ;
if ( V_7 )
F_22 ( V_7 ) ;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_24 ( & V_6 -> V_13 ) ;
}
F_8 ( V_3 -> V_111 ) ;
V_3 -> V_111 = NULL ;
V_3 -> V_112 = 0 ;
F_8 ( V_3 -> V_30 ) ;
V_3 -> V_30 = NULL ;
V_3 -> V_36 = 0 ;
V_3 -> V_35 = 0 ;
V_3 -> V_41 = 0 ;
V_3 -> V_113 &= ~ V_114 ;
}
static void F_25 ( struct V_3 * V_115 )
{
struct V_2 * V_61 = F_26 ( V_115 , struct V_2 , V_115 ) ;
F_23 ( V_61 ) ;
F_8 ( V_61 -> V_116 ) ;
F_8 ( V_61 ) ;
}
static V_71 * F_27 ( T_2 * V_117 , T_2 * V_118 , struct V_68 * V_69 )
{
V_71 V_119 ;
if ( ( V_118 - V_117 ) <= 0 )
return NULL ;
V_119 = * V_117 ++ ;
V_69 -> type = ( V_119 >> 2 ) & 3 ;
V_69 -> V_76 = ( V_119 >> 4 ) & 15 ;
if ( V_69 -> V_76 == V_120 ) {
V_69 -> V_121 = V_122 ;
if ( ( V_118 - V_117 ) < 2 )
return NULL ;
V_69 -> V_11 = * V_117 ++ ;
V_69 -> V_76 = * V_117 ++ ;
if ( ( V_118 - V_117 ) < V_69 -> V_11 )
return NULL ;
V_69 -> V_70 . V_123 = V_117 ;
V_117 += V_69 -> V_11 ;
return V_117 ;
}
V_69 -> V_121 = V_124 ;
V_69 -> V_11 = V_119 & 3 ;
switch ( V_69 -> V_11 ) {
case 0 :
return V_117 ;
case 1 :
if ( ( V_118 - V_117 ) < 1 )
return NULL ;
V_69 -> V_70 . V_71 = * V_117 ++ ;
return V_117 ;
case 2 :
if ( ( V_118 - V_117 ) < 2 )
return NULL ;
V_69 -> V_70 . V_72 = F_28 ( V_117 ) ;
V_117 = ( T_2 * ) ( ( V_125 * ) V_117 + 1 ) ;
return V_117 ;
case 3 :
V_69 -> V_11 ++ ;
if ( ( V_118 - V_117 ) < 4 )
return NULL ;
V_69 -> V_70 . T_1 = F_29 ( V_117 ) ;
V_117 = ( T_2 * ) ( ( V_126 * ) V_117 + 1 ) ;
return V_117 ;
}
return NULL ;
}
static void F_30 ( struct V_2 * V_61 , T_1 V_23 )
{
if ( V_23 == V_127 )
V_61 -> V_128 = V_129 ;
}
static int F_31 ( struct V_2 * V_61 )
{
unsigned int V_130 = 0 , V_131 = 0 ;
T_2 * V_117 = V_61 -> V_116 ;
T_2 * V_118 = V_117 + V_61 -> V_132 ;
unsigned int V_133 , V_134 = 0 , V_135 = 0 ;
struct V_68 V_69 ;
V_61 -> V_128 = V_136 ;
while ( ( V_117 = F_27 ( V_117 , V_118 , & V_69 ) ) != NULL ) {
if ( V_69 . V_121 != V_124 )
return - V_34 ;
if ( V_69 . type == V_137 ) {
if ( V_69 . V_76 == V_83 )
V_130 = F_15 ( & V_69 ) << 16 ;
} else if ( V_69 . type == V_138 ) {
if ( V_131 > 1 )
break;
V_133 = F_15 ( & V_69 ) ;
if ( V_69 . V_11 <= 2 )
V_133 += V_130 ;
switch ( V_69 . V_76 ) {
case V_94 :
V_131 += ! ! V_133 ;
break;
case V_97 :
F_30 ( V_61 , V_133 ) ;
break;
case V_98 :
V_134 = V_133 ;
break;
case V_100 :
V_135 = V_133 ;
for ( V_133 = V_134 ; V_133 <= V_135 ; V_133 ++ )
F_30 ( V_61 , V_133 ) ;
break;
}
} else if ( V_130 == V_139 &&
V_69 . type == V_140 &&
V_69 . V_76 == V_102 &&
( F_15 ( & V_69 ) & 0xff ) == V_56 &&
V_61 -> V_141 == V_142 )
V_61 -> V_128 = V_143 ;
}
return 0 ;
}
int F_32 ( struct V_2 * V_61 , T_2 * V_117 , unsigned V_11 )
{
V_61 -> V_116 = F_33 ( V_117 , V_11 , V_9 ) ;
if ( ! V_61 -> V_116 )
return - V_37 ;
V_61 -> V_132 = V_11 ;
return 0 ;
}
int F_34 ( struct V_2 * V_3 )
{
struct V_27 * V_28 ;
struct V_68 V_69 ;
unsigned int V_11 ;
T_2 * V_117 ;
T_2 * V_144 ;
T_2 * V_118 ;
int V_101 ;
static int (* F_35 [])( struct V_27 * V_28 ,
struct V_68 * V_69 ) = {
F_20 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static V_25 F_36 ( V_52 V_24 , unsigned V_42 )
{
switch ( V_42 ) {
case 8 : return ( ( V_145 ) V_24 ) ;
case 16 : return ( ( V_146 ) V_24 ) ;
case 32 : return ( ( V_147 ) V_24 ) ;
}
return V_24 & ( 1 << ( V_42 - 1 ) ) ? V_24 | ( - 1 << V_42 ) : V_24 ;
}
V_25 F_18 ( V_52 V_24 , unsigned V_42 )
{
return F_36 ( V_24 , V_42 ) ;
}
static T_1 F_37 ( V_147 V_24 , unsigned V_42 )
{
V_25 V_148 = V_24 >> ( V_42 - 1 ) ;
if ( V_148 && V_148 != - 1 )
return V_24 < 0 ? 1 << ( V_42 - 1 ) : ( 1 << ( V_42 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_42 ) - 1 ) ;
}
static V_52 F_38 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_47 , unsigned V_42 )
{
T_3 V_149 ;
if ( V_42 > 32 )
F_39 ( V_61 , L_21 ,
V_42 , V_150 -> V_151 ) ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_149 = F_40 ( V_7 ) ;
V_149 = ( V_149 >> V_47 ) & ( ( 1ULL << V_42 ) - 1 ) ;
return ( T_1 ) V_149 ;
}
static void F_41 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_47 , unsigned V_42 , V_52 V_24 )
{
T_3 V_149 ;
T_3 V_152 = ( 1ULL << V_42 ) - 1 ;
if ( V_42 > 32 )
F_39 ( V_61 , L_22 ,
V_153 , V_42 , V_150 -> V_151 ) ;
if ( V_24 > V_152 )
F_39 ( V_61 , L_23 ,
V_153 , V_24 , V_150 -> V_151 ) ;
F_42 ( V_24 > V_152 ) ;
V_24 &= V_152 ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_149 = F_40 ( V_7 ) ;
V_149 &= ~ ( V_152 << V_47 ) ;
V_149 |= ( ( T_3 ) V_24 ) << V_47 ;
F_43 ( V_149 , V_7 ) ;
}
static int F_44 ( V_147 * V_154 , V_147 V_24 , unsigned V_42 )
{
while ( V_42 -- ) {
if ( * V_154 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_45 ( struct V_2 * V_61 , struct V_1 * V_7 )
{
const struct V_155 * V_4 = V_61 -> V_156 -> V_157 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_158 ; V_4 ++ )
if ( V_4 -> V_45 == V_159 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_61 , struct V_21 * V_23 )
{
const struct V_160 * V_4 = V_61 -> V_156 -> V_161 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_162 != V_159 - 1 ; V_4 ++ )
if ( ( V_4 -> V_163 == V_159 ||
V_4 -> V_163 == V_23 -> V_61 ) &&
( V_4 -> V_162 == V_159 ||
V_4 -> V_162 == V_23 -> type ) &&
( V_4 -> V_164 == V_159 ||
V_4 -> V_164 == V_23 -> V_165 ) )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_2 * V_61 , struct V_14 * V_17 ,
struct V_21 * V_23 , V_147 V_24 , int V_166 )
{
struct V_167 * V_168 = V_61 -> V_156 ;
int V_101 ;
if ( ! F_48 ( & V_61 -> V_169 ) )
F_49 ( V_61 , V_23 , V_24 ) ;
if ( V_168 && V_168 -> V_170 && F_46 ( V_61 , V_23 ) ) {
V_101 = V_168 -> V_170 ( V_61 , V_17 , V_23 , V_24 ) ;
if ( V_101 != 0 ) {
if ( V_101 < 0 )
F_5 ( V_61 , L_24 ,
V_168 -> V_171 , V_101 ) ;
return;
}
}
if ( V_61 -> V_172 & V_173 )
F_50 ( V_61 , V_17 , V_23 , V_24 ) ;
if ( V_61 -> V_172 & V_174 && V_166 && V_61 -> V_175 )
V_61 -> V_175 ( V_61 , V_17 , V_23 , V_24 ) ;
}
static void F_51 ( struct V_2 * V_61 , struct V_14 * V_17 ,
T_2 * V_70 , int V_166 )
{
unsigned V_42 ;
unsigned V_176 = V_17 -> V_54 ;
unsigned V_47 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
V_147 V_177 = V_17 -> V_50 ;
V_147 V_178 = V_17 -> V_51 ;
V_147 * V_24 ;
V_24 = F_7 ( sizeof( V_147 ) * V_176 , V_179 ) ;
if ( ! V_24 )
return;
for ( V_42 = 0 ; V_42 < V_176 ; V_42 ++ ) {
V_24 [ V_42 ] = V_177 < 0 ?
F_36 ( F_38 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ) ,
V_11 ) :
F_38 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ) ;
if ( ! ( V_17 -> V_46 & V_180 ) &&
V_24 [ V_42 ] >= V_177 && V_24 [ V_42 ] <= V_178 &&
V_17 -> V_23 [ V_24 [ V_42 ] - V_177 ] . V_61 == V_181 + 1 )
goto exit;
}
for ( V_42 = 0 ; V_42 < V_176 ; V_42 ++ ) {
if ( V_180 & V_17 -> V_46 ) {
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_42 ] , V_24 [ V_42 ] , V_166 ) ;
continue;
}
if ( V_17 -> V_24 [ V_42 ] >= V_177 && V_17 -> V_24 [ V_42 ] <= V_178
&& V_17 -> V_23 [ V_17 -> V_24 [ V_42 ] - V_177 ] . V_61
&& F_44 ( V_24 , V_17 -> V_24 [ V_42 ] , V_176 ) )
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_17 -> V_24 [ V_42 ] - V_177 ] , 0 , V_166 ) ;
if ( V_24 [ V_42 ] >= V_177 && V_24 [ V_42 ] <= V_178
&& V_17 -> V_23 [ V_24 [ V_42 ] - V_177 ] . V_61
&& F_44 ( V_17 -> V_24 , V_24 [ V_42 ] , V_176 ) )
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_24 [ V_42 ] - V_177 ] , 1 , V_166 ) ;
}
memcpy ( V_17 -> V_24 , V_24 , V_176 * sizeof( V_147 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_52 ( const struct V_2 * V_61 ,
struct V_14 * V_17 , T_2 * V_70 )
{
unsigned V_176 = V_17 -> V_54 ;
unsigned V_47 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_176 ; V_42 ++ ) {
if ( V_17 -> V_50 < 0 )
F_41 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ,
F_37 ( V_17 -> V_24 [ V_42 ] , V_11 ) ) ;
else
F_41 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ,
V_17 -> V_24 [ V_42 ] ) ;
}
}
void F_53 ( struct V_1 * V_7 , T_2 * V_70 )
{
unsigned V_42 ;
if ( V_7 -> V_4 > 0 )
* V_70 ++ = V_7 -> V_4 ;
memset ( V_70 , 0 , ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ) ;
for ( V_42 = 0 ; V_42 < V_7 -> V_19 ; V_42 ++ )
F_52 ( V_7 -> V_3 , V_7 -> V_17 [ V_42 ] , V_70 ) ;
}
int F_54 ( struct V_14 * V_17 , unsigned V_47 , V_147 V_24 )
{
unsigned V_11 = V_17 -> V_53 ;
F_49 ( V_17 -> V_7 -> V_3 , V_17 -> V_23 + V_47 , V_24 ) ;
if ( V_47 >= V_17 -> V_54 ) {
F_5 ( V_17 -> V_7 -> V_3 , L_25 ,
V_47 , V_17 -> V_54 ) ;
return - 1 ;
}
if ( V_17 -> V_50 < 0 ) {
if ( V_24 != F_36 ( F_37 ( V_24 , V_11 ) , V_11 ) ) {
F_5 ( V_17 -> V_7 -> V_3 , L_26 , V_24 ) ;
return - 1 ;
}
}
V_17 -> V_24 [ V_47 ] = V_24 ;
return 0 ;
}
static struct V_1 * F_55 ( struct V_5 * V_6 ,
const V_71 * V_70 )
{
struct V_1 * V_7 ;
unsigned int V_42 = 0 ;
if ( V_6 -> V_10 )
V_42 = * V_70 ;
V_7 = V_6 -> V_8 [ V_42 ] ;
if ( V_7 == NULL )
F_13 ( L_27 , V_42 ) ;
return V_7 ;
}
int F_56 ( struct V_2 * V_61 , int type , V_71 * V_70 , int V_11 ,
int V_166 )
{
struct V_5 * V_6 = V_61 -> V_6 + type ;
struct V_1 * V_7 ;
unsigned int V_148 ;
int V_112 , V_182 = V_11 ;
V_71 * V_183 = V_70 ;
int V_101 = 0 ;
V_7 = F_55 ( V_6 , V_70 ) ;
if ( ! V_7 )
goto V_184;
if ( V_6 -> V_10 ) {
V_183 ++ ;
V_182 -- ;
}
V_112 = ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ;
if ( V_112 > V_185 )
V_112 = V_185 ;
if ( V_182 < V_112 ) {
F_13 ( L_28 , V_7 -> V_4 ,
V_182 , V_112 ) ;
memset ( V_183 + V_182 , 0 , V_112 - V_182 ) ;
}
if ( ( V_61 -> V_172 & V_174 ) && V_61 -> V_186 )
V_61 -> V_186 ( V_61 , V_7 ) ;
if ( V_61 -> V_172 & V_187 ) {
V_101 = F_57 ( V_61 , V_70 , V_11 ) ;
if ( V_101 )
goto V_184;
}
if ( V_61 -> V_172 != V_187 ) {
for ( V_148 = 0 ; V_148 < V_7 -> V_19 ; V_148 ++ )
F_51 ( V_61 , V_7 -> V_17 [ V_148 ] , V_183 , V_166 ) ;
}
if ( V_61 -> V_172 & V_173 )
F_58 ( V_61 , V_7 ) ;
V_184:
return V_101 ;
}
int F_59 ( struct V_2 * V_61 , int type , V_71 * V_70 , int V_11 , int V_166 )
{
struct V_5 * V_6 ;
struct V_167 * V_168 ;
struct V_1 * V_7 ;
char * V_144 ;
unsigned int V_18 ;
int V_101 = 0 ;
if ( ! V_61 )
return - V_188 ;
if ( F_60 ( & V_61 -> V_189 ) )
return - V_190 ;
if ( ! V_61 -> V_156 ) {
V_101 = - V_188 ;
goto V_191;
}
V_6 = V_61 -> V_6 + type ;
V_168 = V_61 -> V_156 ;
if ( ! V_11 ) {
F_13 ( L_29 ) ;
V_101 = - 1 ;
goto V_191;
}
if ( F_48 ( & V_61 -> V_169 ) )
goto V_192;
V_144 = F_7 ( sizeof( char ) * V_193 , V_179 ) ;
if ( ! V_144 )
goto V_192;
snprintf ( V_144 , V_193 - 1 ,
L_30 , V_11 , V_6 -> V_10 ? L_31 : L_32 ) ;
F_61 ( V_61 , V_144 ) ;
for ( V_18 = 0 ; V_18 < V_11 ; V_18 ++ ) {
snprintf ( V_144 , V_193 - 1 ,
L_33 , V_70 [ V_18 ] ) ;
F_61 ( V_61 , V_144 ) ;
}
F_61 ( V_61 , L_34 ) ;
F_8 ( V_144 ) ;
V_192:
V_7 = F_55 ( V_6 , V_70 ) ;
if ( ! V_7 ) {
V_101 = - 1 ;
goto V_191;
}
if ( V_168 && V_168 -> V_194 && F_45 ( V_61 , V_7 ) ) {
V_101 = V_168 -> V_194 ( V_61 , V_7 , V_70 , V_11 ) ;
if ( V_101 != 0 ) {
V_101 = V_101 < 0 ? V_101 : 0 ;
goto V_191;
}
}
V_101 = F_56 ( V_61 , type , V_70 , V_11 , V_166 ) ;
V_191:
F_62 ( & V_61 -> V_189 ) ;
return V_101 ;
}
static bool F_63 ( struct V_2 * V_195 ,
const struct V_196 * V_4 )
{
return ( V_4 -> V_141 == V_197 || V_4 -> V_141 == V_195 -> V_141 ) &&
( V_4 -> V_128 == V_198 || V_4 -> V_128 == V_195 -> V_128 ) &&
( V_4 -> V_199 == V_159 || V_4 -> V_199 == V_195 -> V_199 ) &&
( V_4 -> V_200 == V_159 || V_4 -> V_200 == V_195 -> V_200 ) ;
}
const struct V_196 * F_64 ( struct V_2 * V_195 ,
const struct V_196 * V_4 )
{
for (; V_4 -> V_141 ; V_4 ++ )
if ( F_63 ( V_195 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_65 ( struct V_2 * V_195 )
{
return ! ! F_64 ( V_195 , V_201 ) ;
}
static T_4
F_66 ( struct V_202 * V_203 , struct V_204 * V_205 ,
struct V_206 * V_207 ,
char * V_144 , T_5 V_208 , T_6 V_176 )
{
struct V_3 * V_115 = F_26 ( V_205 , struct V_3 , V_205 ) ;
struct V_2 * V_195 = F_26 ( V_115 , struct V_2 , V_115 ) ;
if ( V_208 >= V_195 -> V_112 )
return 0 ;
if ( V_208 + V_176 > V_195 -> V_112 )
V_176 = V_195 -> V_112 - V_208 ;
memcpy ( V_144 , V_195 -> V_111 + V_208 , V_176 ) ;
return V_176 ;
}
int F_67 ( struct V_2 * V_195 , unsigned int V_209 )
{
static const char * V_210 [] = { L_35 , L_36 , L_37 , L_35 ,
L_38 , L_39 , L_40 , L_41 ,
L_42
} ;
const char * type , * V_141 ;
char V_144 [ 64 ] ;
unsigned int V_18 ;
int V_211 ;
int V_101 ;
if ( V_195 -> V_212 & V_213 )
V_209 |= ( V_214 | V_215 ) ;
if ( V_195 -> V_212 & V_216 )
V_209 |= V_217 ;
if ( V_195 -> V_141 != V_142 )
V_209 &= ~ V_215 ;
if ( F_65 ( V_195 ) )
V_209 |= V_214 ;
if ( ( V_209 & V_218 ) && ! F_68 ( V_195 ,
V_209 & V_217 ) )
V_195 -> V_172 |= V_173 ;
if ( ( V_209 & V_215 ) && V_195 -> V_219 &&
! V_195 -> V_219 ( V_195 ,
V_209 & V_214 ) )
V_195 -> V_172 |= V_174 ;
if ( ( V_209 & V_220 ) && ! F_69 ( V_195 ) )
V_195 -> V_172 |= V_187 ;
if ( ! V_195 -> V_172 && ! V_195 -> V_156 -> V_194 ) {
F_5 ( V_195 , L_43 ) ;
return - V_188 ;
}
if ( ( V_195 -> V_172 & V_173 ) &&
( V_209 & V_221 ) && V_195 -> V_222 )
V_195 -> V_222 ( V_195 ) ;
V_211 = 0 ;
if ( V_195 -> V_172 & V_173 )
V_211 += sprintf ( V_144 + V_211 , L_44 ) ;
if ( V_195 -> V_172 & V_174 )
V_211 += sprintf ( V_144 + V_211 , L_45 , V_211 ? L_46 : L_31 ,
V_195 -> V_223 ) ;
if ( V_195 -> V_172 & V_187 )
V_211 += sprintf ( V_144 + V_211 , L_47 , V_211 ? L_46 : L_31 ,
( (struct V_224 * ) V_195 -> V_224 ) -> V_223 ) ;
type = L_35 ;
for ( V_18 = 0 ; V_18 < V_195 -> V_35 ; V_18 ++ ) {
struct V_29 * V_225 = & V_195 -> V_30 [ V_18 ] ;
if ( V_225 -> type == V_40 &&
( V_225 -> V_23 & V_226 ) == V_227 &&
( V_225 -> V_23 & 0xffff ) < F_70 ( V_210 ) ) {
type = V_210 [ V_225 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_195 -> V_141 ) {
case V_142 :
V_141 = L_48 ;
break;
case V_228 :
V_141 = L_49 ;
break;
default:
V_141 = L_50 ;
}
V_101 = F_71 ( & V_195 -> V_115 , & V_229 ) ;
if ( V_101 )
F_39 ( V_195 ,
L_51 , V_101 ) ;
F_72 ( V_195 , L_52 ,
V_144 , V_141 , V_195 -> V_230 >> 8 , V_195 -> V_230 & 0xff ,
type , V_195 -> V_171 , V_195 -> V_231 ) ;
return 0 ;
}
void F_73 ( struct V_2 * V_195 )
{
F_74 ( & V_195 -> V_115 , & V_229 ) ;
if ( V_195 -> V_172 & V_173 )
F_75 ( V_195 ) ;
if ( V_195 -> V_172 & V_174 )
V_195 -> V_232 ( V_195 ) ;
if ( V_195 -> V_172 & V_187 )
F_76 ( V_195 ) ;
}
static T_4 F_77 ( struct V_233 * V_234 , const char * V_144 ,
T_6 V_176 )
{
struct V_167 * V_168 = F_26 ( V_234 , struct V_167 , V_156 ) ;
struct V_235 * V_236 ;
V_52 V_141 , V_199 , V_200 ;
unsigned long V_237 = 0 ;
int V_101 ;
V_101 = sscanf ( V_144 , L_53 ,
& V_141 , & V_199 , & V_200 , & V_237 ) ;
if ( V_101 < 3 )
return - V_34 ;
V_236 = F_2 ( sizeof( * V_236 ) , V_9 ) ;
if ( ! V_236 )
return - V_37 ;
V_236 -> V_4 . V_141 = V_141 ;
V_236 -> V_4 . V_128 = V_198 ;
V_236 -> V_4 . V_199 = V_199 ;
V_236 -> V_4 . V_200 = V_200 ;
V_236 -> V_4 . V_237 = V_237 ;
F_78 ( & V_168 -> V_238 ) ;
F_3 ( & V_236 -> V_12 , & V_168 -> V_239 ) ;
F_79 ( & V_168 -> V_238 ) ;
V_101 = F_80 ( & V_168 -> V_156 ) ;
return V_101 ? : V_176 ;
}
static void F_81 ( struct V_167 * V_168 )
{
struct V_235 * V_236 , * V_42 ;
F_78 ( & V_168 -> V_238 ) ;
F_82 (dynid, n, &hdrv->dyn_list, list) {
F_83 ( & V_236 -> V_12 ) ;
F_8 ( V_236 ) ;
}
F_79 ( & V_168 -> V_238 ) ;
}
static const struct V_196 * F_84 ( struct V_2 * V_195 ,
struct V_167 * V_168 )
{
struct V_235 * V_236 ;
F_78 ( & V_168 -> V_238 ) ;
F_85 (dynid, &hdrv->dyn_list, list) {
if ( F_63 ( V_195 , & V_236 -> V_4 ) ) {
F_79 ( & V_168 -> V_238 ) ;
return & V_236 -> V_4 ;
}
}
F_79 ( & V_168 -> V_238 ) ;
return F_64 ( V_195 , V_168 -> V_240 ) ;
}
static int F_86 ( struct V_3 * V_115 , struct V_233 * V_234 )
{
struct V_167 * V_168 = F_26 ( V_234 , struct V_167 , V_156 ) ;
struct V_2 * V_195 = F_26 ( V_115 , struct V_2 , V_115 ) ;
return F_84 ( V_195 , V_168 ) != NULL ;
}
static int F_87 ( struct V_3 * V_115 )
{
struct V_167 * V_168 = F_26 ( V_115 -> V_156 ,
struct V_167 , V_156 ) ;
struct V_2 * V_195 = F_26 ( V_115 , struct V_2 , V_115 ) ;
const struct V_196 * V_4 ;
int V_101 = 0 ;
if ( F_88 ( & V_195 -> V_189 ) )
return - V_241 ;
if ( ! V_195 -> V_156 ) {
V_4 = F_84 ( V_195 , V_168 ) ;
if ( V_4 == NULL ) {
V_101 = - V_188 ;
goto V_191;
}
V_195 -> V_156 = V_168 ;
if ( V_168 -> V_242 ) {
V_101 = V_168 -> V_242 ( V_195 , V_4 ) ;
} else {
V_101 = F_34 ( V_195 ) ;
if ( ! V_101 )
V_101 = F_89 ( V_195 , V_243 ) ;
}
if ( V_101 ) {
F_23 ( V_195 ) ;
V_195 -> V_156 = NULL ;
}
}
V_191:
F_62 ( & V_195 -> V_189 ) ;
return V_101 ;
}
static int F_90 ( struct V_3 * V_115 )
{
struct V_2 * V_195 = F_26 ( V_115 , struct V_2 , V_115 ) ;
struct V_167 * V_168 ;
if ( F_88 ( & V_195 -> V_189 ) )
return - V_241 ;
V_168 = V_195 -> V_156 ;
if ( V_168 ) {
if ( V_168 -> remove )
V_168 -> remove ( V_195 ) ;
else
F_91 ( V_195 ) ;
F_23 ( V_195 ) ;
V_195 -> V_156 = NULL ;
}
F_62 ( & V_195 -> V_189 ) ;
return 0 ;
}
static T_4 F_92 ( struct V_3 * V_115 , struct V_244 * V_148 ,
char * V_144 )
{
struct V_2 * V_195 = F_26 ( V_115 , struct V_2 , V_115 ) ;
int V_211 ;
V_211 = snprintf ( V_144 , V_245 , L_54 ,
V_195 -> V_141 , V_195 -> V_128 , V_195 -> V_199 , V_195 -> V_200 ) ;
return ( V_211 >= V_245 ) ? ( V_245 - 1 ) : V_211 ;
}
static int F_93 ( struct V_3 * V_115 , struct V_246 * V_247 )
{
struct V_2 * V_195 = F_26 ( V_115 , struct V_2 , V_115 ) ;
if ( F_94 ( V_247 , L_55 ,
V_195 -> V_141 , V_195 -> V_199 , V_195 -> V_200 ) )
return - V_37 ;
if ( F_94 ( V_247 , L_56 , V_195 -> V_171 ) )
return - V_37 ;
if ( F_94 ( V_247 , L_57 , V_195 -> V_231 ) )
return - V_37 ;
if ( F_94 ( V_247 , L_58 , V_195 -> V_248 ) )
return - V_37 ;
if ( F_94 ( V_247 , L_59 ,
V_195 -> V_141 , V_195 -> V_128 , V_195 -> V_199 , V_195 -> V_200 ) )
return - V_37 ;
return 0 ;
}
bool F_95 ( struct V_2 * V_195 )
{
if ( V_195 -> V_212 & V_249 )
return false ;
if ( V_195 -> V_212 & V_250 )
return true ;
switch ( V_195 -> V_199 ) {
case V_251 :
if ( V_195 -> V_200 >= V_252 &&
V_195 -> V_200 <= V_253 )
return true ;
break;
case V_254 :
if ( V_195 -> V_200 >= V_255 &&
V_195 -> V_200 <= V_256 )
return true ;
if ( V_195 -> V_200 == V_257 &&
! strcmp ( V_195 -> V_171 , L_60 ) )
return true ;
break;
case V_258 :
if ( V_195 -> V_200 >= V_259 &&
V_195 -> V_200 <= V_260 )
return true ;
break;
case V_261 :
if ( V_195 -> V_200 >= V_262 &&
V_195 -> V_200 <= V_263 )
return true ;
break;
case V_264 :
if ( V_195 -> V_200 == V_265 &&
V_195 -> type == V_266 )
return true ;
break;
case V_267 :
if ( ( V_195 -> V_200 == V_268 ||
V_195 -> V_200 == V_269 ) &&
V_195 -> type != V_270 )
return true ;
break;
}
if ( V_195 -> type == V_270 &&
F_64 ( V_195 , V_271 ) )
return true ;
return ! ! F_64 ( V_195 , V_272 ) ;
}
int F_96 ( struct V_2 * V_195 )
{
static T_7 V_4 = F_97 ( 0 ) ;
int V_101 ;
if ( F_42 ( V_195 -> V_113 & V_273 ) )
return - V_190 ;
if ( F_95 ( V_195 ) )
return - V_188 ;
V_101 = V_195 -> V_274 -> V_275 ( V_195 ) ;
if ( V_101 )
return V_101 ;
if ( ! V_195 -> V_116 )
return - V_188 ;
if ( V_276 ||
! F_64 ( V_195 , V_277 ) ) {
V_101 = F_31 ( V_195 ) ;
if ( V_101 )
F_39 ( V_195 , L_61 , V_101 ) ;
}
F_98 ( & V_195 -> V_115 , L_62 , V_195 -> V_141 ,
V_195 -> V_199 , V_195 -> V_200 , F_99 ( & V_4 ) ) ;
F_100 ( V_195 , F_101 ( & V_195 -> V_115 ) ) ;
V_101 = F_102 ( & V_195 -> V_115 ) ;
if ( ! V_101 )
V_195 -> V_113 |= V_273 ;
else
F_103 ( V_195 ) ;
return V_101 ;
}
struct V_2 * F_104 ( void )
{
struct V_2 * V_195 ;
int V_101 = - V_37 ;
V_195 = F_2 ( sizeof( * V_195 ) , V_9 ) ;
if ( V_195 == NULL )
return F_105 ( V_101 ) ;
F_106 ( & V_195 -> V_115 ) ;
V_195 -> V_115 . V_278 = F_25 ;
V_195 -> V_115 . V_141 = & V_279 ;
F_23 ( V_195 ) ;
F_107 ( & V_195 -> V_280 ) ;
F_24 ( & V_195 -> V_169 ) ;
F_108 ( & V_195 -> V_189 , 1 ) ;
return V_195 ;
}
static void F_109 ( struct V_2 * V_195 )
{
if ( V_195 -> V_113 & V_273 ) {
F_110 ( & V_195 -> V_115 ) ;
F_103 ( V_195 ) ;
V_195 -> V_113 &= ~ V_273 ;
}
F_8 ( V_195 -> V_116 ) ;
V_195 -> V_116 = NULL ;
V_195 -> V_132 = 0 ;
}
void F_111 ( struct V_2 * V_195 )
{
F_109 ( V_195 ) ;
F_112 ( & V_195 -> V_115 ) ;
}
int F_113 ( struct V_167 * V_168 , struct V_281 * V_282 ,
const char * V_283 )
{
int V_101 ;
V_168 -> V_156 . V_171 = V_168 -> V_171 ;
V_168 -> V_156 . V_141 = & V_279 ;
V_168 -> V_156 . V_282 = V_282 ;
V_168 -> V_156 . V_283 = V_283 ;
F_24 ( & V_168 -> V_239 ) ;
F_114 ( & V_168 -> V_238 ) ;
V_101 = F_115 ( & V_168 -> V_156 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_116 ( & V_168 -> V_156 , & V_284 ) ;
if ( V_101 )
F_117 ( & V_168 -> V_156 ) ;
return V_101 ;
}
void F_118 ( struct V_167 * V_168 )
{
F_119 ( & V_168 -> V_156 , & V_284 ) ;
F_117 ( & V_168 -> V_156 ) ;
F_81 ( V_168 ) ;
}
int F_120 ( struct V_2 * V_61 )
{
struct V_285 * V_286 ;
int V_18 ;
if ( ! ( V_61 -> V_172 & V_173 ) )
return 0 ;
F_85 (hidinput, &hid->inputs, list) {
for ( V_18 = 0 ; V_18 < F_121 ( V_287 ) ; V_18 ++ )
if ( V_286 -> V_288 -> V_289 [ V_18 ] )
return 1 ;
}
return 0 ;
}
static int T_8 F_122 ( void )
{
int V_101 ;
if ( V_290 )
F_123 ( L_63
L_64 ) ;
V_101 = F_124 ( & V_279 ) ;
if ( V_101 ) {
F_125 ( L_65 ) ;
goto V_291;
}
V_101 = F_126 () ;
if ( V_101 )
goto V_292;
F_127 () ;
return 0 ;
V_292:
F_128 ( & V_279 ) ;
V_291:
return V_101 ;
}
static void T_9 F_129 ( void )
{
F_130 () ;
F_131 () ;
F_128 ( & V_279 ) ;
}
