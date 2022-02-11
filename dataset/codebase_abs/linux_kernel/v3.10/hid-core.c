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
( F_15 ( & V_69 ) & 0xff ) == V_56 )
V_61 -> V_128 = V_141 ;
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
T_2 * V_142 ;
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
case 8 : return ( ( V_143 ) V_24 ) ;
case 16 : return ( ( V_144 ) V_24 ) ;
case 32 : return ( ( V_145 ) V_24 ) ;
}
return V_24 & ( 1 << ( V_42 - 1 ) ) ? V_24 | ( - 1 << V_42 ) : V_24 ;
}
V_25 F_18 ( V_52 V_24 , unsigned V_42 )
{
return F_36 ( V_24 , V_42 ) ;
}
static T_1 F_37 ( V_145 V_24 , unsigned V_42 )
{
V_25 V_146 = V_24 >> ( V_42 - 1 ) ;
if ( V_146 && V_146 != - 1 )
return V_24 < 0 ? 1 << ( V_42 - 1 ) : ( 1 << ( V_42 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_42 ) - 1 ) ;
}
static V_52 F_38 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_47 , unsigned V_42 )
{
T_3 V_147 ;
if ( V_42 > 32 )
F_39 ( V_61 , L_21 ,
V_42 , V_148 -> V_149 ) ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_147 = F_40 ( V_7 ) ;
V_147 = ( V_147 >> V_47 ) & ( ( 1ULL << V_42 ) - 1 ) ;
return ( T_1 ) V_147 ;
}
static void F_41 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_47 , unsigned V_42 , V_52 V_24 )
{
T_3 V_147 ;
T_3 V_150 = ( 1ULL << V_42 ) - 1 ;
if ( V_42 > 32 )
F_39 ( V_61 , L_22 ,
V_151 , V_42 , V_148 -> V_149 ) ;
if ( V_24 > V_150 )
F_39 ( V_61 , L_23 ,
V_151 , V_24 , V_148 -> V_149 ) ;
F_42 ( V_24 > V_150 ) ;
V_24 &= V_150 ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_147 = F_40 ( V_7 ) ;
V_147 &= ~ ( V_150 << V_47 ) ;
V_147 |= ( ( T_3 ) V_24 ) << V_47 ;
F_43 ( V_147 , V_7 ) ;
}
static int F_44 ( V_145 * V_152 , V_145 V_24 , unsigned V_42 )
{
while ( V_42 -- ) {
if ( * V_152 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_45 ( struct V_2 * V_61 , struct V_1 * V_7 )
{
const struct V_153 * V_4 = V_61 -> V_154 -> V_155 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_156 ; V_4 ++ )
if ( V_4 -> V_45 == V_157 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_61 , struct V_21 * V_23 )
{
const struct V_158 * V_4 = V_61 -> V_154 -> V_159 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_160 != V_157 - 1 ; V_4 ++ )
if ( ( V_4 -> V_161 == V_157 ||
V_4 -> V_161 == V_23 -> V_61 ) &&
( V_4 -> V_160 == V_157 ||
V_4 -> V_160 == V_23 -> type ) &&
( V_4 -> V_162 == V_157 ||
V_4 -> V_162 == V_23 -> V_163 ) )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_2 * V_61 , struct V_14 * V_17 ,
struct V_21 * V_23 , V_145 V_24 , int V_164 )
{
struct V_165 * V_166 = V_61 -> V_154 ;
int V_101 ;
if ( ! F_48 ( & V_61 -> V_167 ) )
F_49 ( V_61 , V_23 , V_24 ) ;
if ( V_166 && V_166 -> V_168 && F_46 ( V_61 , V_23 ) ) {
V_101 = V_166 -> V_168 ( V_61 , V_17 , V_23 , V_24 ) ;
if ( V_101 != 0 ) {
if ( V_101 < 0 )
F_5 ( V_61 , L_24 ,
V_166 -> V_169 , V_101 ) ;
return;
}
}
if ( V_61 -> V_170 & V_171 )
F_50 ( V_61 , V_17 , V_23 , V_24 ) ;
if ( V_61 -> V_170 & V_172 && V_164 && V_61 -> V_173 )
V_61 -> V_173 ( V_61 , V_17 , V_23 , V_24 ) ;
}
static void F_51 ( struct V_2 * V_61 , struct V_14 * V_17 ,
T_2 * V_70 , int V_164 )
{
unsigned V_42 ;
unsigned V_174 = V_17 -> V_54 ;
unsigned V_47 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
V_145 V_175 = V_17 -> V_50 ;
V_145 V_176 = V_17 -> V_51 ;
V_145 * V_24 ;
V_24 = F_7 ( sizeof( V_145 ) * V_174 , V_177 ) ;
if ( ! V_24 )
return;
for ( V_42 = 0 ; V_42 < V_174 ; V_42 ++ ) {
V_24 [ V_42 ] = V_175 < 0 ?
F_36 ( F_38 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ) ,
V_11 ) :
F_38 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ) ;
if ( ! ( V_17 -> V_46 & V_178 ) &&
V_24 [ V_42 ] >= V_175 && V_24 [ V_42 ] <= V_176 &&
V_17 -> V_23 [ V_24 [ V_42 ] - V_175 ] . V_61 == V_179 + 1 )
goto exit;
}
for ( V_42 = 0 ; V_42 < V_174 ; V_42 ++ ) {
if ( V_178 & V_17 -> V_46 ) {
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_42 ] , V_24 [ V_42 ] , V_164 ) ;
continue;
}
if ( V_17 -> V_24 [ V_42 ] >= V_175 && V_17 -> V_24 [ V_42 ] <= V_176
&& V_17 -> V_23 [ V_17 -> V_24 [ V_42 ] - V_175 ] . V_61
&& F_44 ( V_24 , V_17 -> V_24 [ V_42 ] , V_174 ) )
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_17 -> V_24 [ V_42 ] - V_175 ] , 0 , V_164 ) ;
if ( V_24 [ V_42 ] >= V_175 && V_24 [ V_42 ] <= V_176
&& V_17 -> V_23 [ V_24 [ V_42 ] - V_175 ] . V_61
&& F_44 ( V_17 -> V_24 , V_24 [ V_42 ] , V_174 ) )
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_24 [ V_42 ] - V_175 ] , 1 , V_164 ) ;
}
memcpy ( V_17 -> V_24 , V_24 , V_174 * sizeof( V_145 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_52 ( const struct V_2 * V_61 ,
struct V_14 * V_17 , T_2 * V_70 )
{
unsigned V_174 = V_17 -> V_54 ;
unsigned V_47 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_174 ; V_42 ++ ) {
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
int F_54 ( struct V_14 * V_17 , unsigned V_47 , V_145 V_24 )
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
int V_164 )
{
struct V_5 * V_6 = V_61 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_165 * V_166 ;
unsigned int V_146 ;
int V_112 , V_180 = V_11 ;
V_71 * V_181 = V_70 ;
int V_101 = 0 ;
V_7 = F_55 ( V_6 , V_70 ) ;
if ( ! V_7 )
goto V_182;
if ( V_6 -> V_10 ) {
V_181 ++ ;
V_180 -- ;
}
V_112 = ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ;
if ( V_112 > V_183 )
V_112 = V_183 ;
if ( V_180 < V_112 ) {
F_13 ( L_28 , V_7 -> V_4 ,
V_180 , V_112 ) ;
memset ( V_181 + V_180 , 0 , V_112 - V_180 ) ;
}
if ( ( V_61 -> V_170 & V_172 ) && V_61 -> V_184 )
V_61 -> V_184 ( V_61 , V_7 ) ;
if ( V_61 -> V_170 & V_185 ) {
V_101 = F_57 ( V_61 , V_70 , V_11 ) ;
if ( V_101 )
goto V_182;
}
if ( V_61 -> V_170 != V_185 ) {
for ( V_146 = 0 ; V_146 < V_7 -> V_19 ; V_146 ++ )
F_51 ( V_61 , V_7 -> V_17 [ V_146 ] , V_181 , V_164 ) ;
V_166 = V_61 -> V_154 ;
if ( V_166 && V_166 -> V_7 )
V_166 -> V_7 ( V_61 , V_7 ) ;
}
if ( V_61 -> V_170 & V_171 )
F_58 ( V_61 , V_7 ) ;
V_182:
return V_101 ;
}
int F_59 ( struct V_2 * V_61 , int type , V_71 * V_70 , int V_11 , int V_164 )
{
struct V_5 * V_6 ;
struct V_165 * V_166 ;
struct V_1 * V_7 ;
int V_101 = 0 ;
if ( ! V_61 )
return - V_186 ;
if ( F_60 ( & V_61 -> V_187 ) )
return - V_188 ;
if ( ! V_61 -> V_154 ) {
V_101 = - V_186 ;
goto V_189;
}
V_6 = V_61 -> V_6 + type ;
V_166 = V_61 -> V_154 ;
if ( ! V_11 ) {
F_13 ( L_29 ) ;
V_101 = - 1 ;
goto V_189;
}
if ( ! F_48 ( & V_61 -> V_167 ) )
F_61 ( V_61 , type , V_70 , V_11 ) ;
V_7 = F_55 ( V_6 , V_70 ) ;
if ( ! V_7 ) {
V_101 = - 1 ;
goto V_189;
}
if ( V_166 && V_166 -> V_190 && F_45 ( V_61 , V_7 ) ) {
V_101 = V_166 -> V_190 ( V_61 , V_7 , V_70 , V_11 ) ;
if ( V_101 != 0 ) {
V_101 = V_101 < 0 ? V_101 : 0 ;
goto V_189;
}
}
V_101 = F_56 ( V_61 , type , V_70 , V_11 , V_164 ) ;
V_189:
F_62 ( & V_61 -> V_187 ) ;
return V_101 ;
}
static bool F_63 ( struct V_2 * V_191 ,
const struct V_192 * V_4 )
{
return ( V_4 -> V_193 == V_194 || V_4 -> V_193 == V_191 -> V_193 ) &&
( V_4 -> V_128 == V_195 || V_4 -> V_128 == V_191 -> V_128 ) &&
( V_4 -> V_196 == V_157 || V_4 -> V_196 == V_191 -> V_196 ) &&
( V_4 -> V_197 == V_157 || V_4 -> V_197 == V_191 -> V_197 ) ;
}
const struct V_192 * F_64 ( struct V_2 * V_191 ,
const struct V_192 * V_4 )
{
for (; V_4 -> V_193 ; V_4 ++ )
if ( F_63 ( V_191 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_65 ( struct V_2 * V_191 )
{
return ! ! F_64 ( V_191 , V_198 ) ;
}
static T_4
F_66 ( struct V_199 * V_200 , struct V_201 * V_202 ,
struct V_203 * V_204 ,
char * V_142 , T_5 V_205 , T_6 V_174 )
{
struct V_3 * V_115 = F_26 ( V_202 , struct V_3 , V_202 ) ;
struct V_2 * V_191 = F_26 ( V_115 , struct V_2 , V_115 ) ;
if ( V_205 >= V_191 -> V_112 )
return 0 ;
if ( V_205 + V_174 > V_191 -> V_112 )
V_174 = V_191 -> V_112 - V_205 ;
memcpy ( V_142 , V_191 -> V_111 + V_205 , V_174 ) ;
return V_174 ;
}
int F_67 ( struct V_2 * V_191 , unsigned int V_206 )
{
static const char * V_207 [] = { L_30 , L_31 , L_32 , L_30 ,
L_33 , L_34 , L_35 , L_36 ,
L_37
} ;
const char * type , * V_193 ;
char V_142 [ 64 ] ;
unsigned int V_18 ;
int V_208 ;
int V_101 ;
if ( V_191 -> V_209 & V_210 )
V_206 |= ( V_211 | V_212 ) ;
if ( V_191 -> V_209 & V_213 )
V_206 |= V_214 ;
if ( V_191 -> V_193 != V_215 )
V_206 &= ~ V_212 ;
if ( F_65 ( V_191 ) )
V_206 |= V_211 ;
if ( ( V_206 & V_216 ) && ! F_68 ( V_191 ,
V_206 & V_214 ) )
V_191 -> V_170 |= V_171 ;
if ( ( V_206 & V_212 ) && V_191 -> V_217 &&
! V_191 -> V_217 ( V_191 ,
V_206 & V_211 ) )
V_191 -> V_170 |= V_172 ;
if ( ( V_206 & V_218 ) && ! F_69 ( V_191 ) )
V_191 -> V_170 |= V_185 ;
if ( ! V_191 -> V_170 && ! V_191 -> V_154 -> V_190 ) {
F_5 ( V_191 , L_38 ) ;
return - V_186 ;
}
if ( ( V_191 -> V_170 & V_171 ) &&
( V_206 & V_219 ) && V_191 -> V_220 )
V_191 -> V_220 ( V_191 ) ;
V_208 = 0 ;
if ( V_191 -> V_170 & V_171 )
V_208 += sprintf ( V_142 + V_208 , L_39 ) ;
if ( V_191 -> V_170 & V_172 )
V_208 += sprintf ( V_142 + V_208 , L_40 , V_208 ? L_41 : L_42 ,
V_191 -> V_221 ) ;
if ( V_191 -> V_170 & V_185 )
V_208 += sprintf ( V_142 + V_208 , L_43 , V_208 ? L_41 : L_42 ,
( (struct V_222 * ) V_191 -> V_222 ) -> V_221 ) ;
type = L_30 ;
for ( V_18 = 0 ; V_18 < V_191 -> V_35 ; V_18 ++ ) {
struct V_29 * V_223 = & V_191 -> V_30 [ V_18 ] ;
if ( V_223 -> type == V_40 &&
( V_223 -> V_23 & V_224 ) == V_225 &&
( V_223 -> V_23 & 0xffff ) < F_70 ( V_207 ) ) {
type = V_207 [ V_223 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_191 -> V_193 ) {
case V_215 :
V_193 = L_44 ;
break;
case V_226 :
V_193 = L_45 ;
break;
default:
V_193 = L_46 ;
}
V_101 = F_71 ( & V_191 -> V_115 , & V_227 ) ;
if ( V_101 )
F_39 ( V_191 ,
L_47 , V_101 ) ;
F_72 ( V_191 , L_48 ,
V_142 , V_193 , V_191 -> V_228 >> 8 , V_191 -> V_228 & 0xff ,
type , V_191 -> V_169 , V_191 -> V_229 ) ;
return 0 ;
}
void F_73 ( struct V_2 * V_191 )
{
F_74 ( & V_191 -> V_115 , & V_227 ) ;
if ( V_191 -> V_170 & V_171 )
F_75 ( V_191 ) ;
if ( V_191 -> V_170 & V_172 )
V_191 -> V_230 ( V_191 ) ;
if ( V_191 -> V_170 & V_185 )
F_76 ( V_191 ) ;
}
static T_4 F_77 ( struct V_231 * V_232 , const char * V_142 ,
T_6 V_174 )
{
struct V_165 * V_166 = F_26 ( V_232 , struct V_165 , V_154 ) ;
struct V_233 * V_234 ;
V_52 V_193 , V_196 , V_197 ;
unsigned long V_235 = 0 ;
int V_101 ;
V_101 = sscanf ( V_142 , L_49 ,
& V_193 , & V_196 , & V_197 , & V_235 ) ;
if ( V_101 < 3 )
return - V_34 ;
V_234 = F_2 ( sizeof( * V_234 ) , V_9 ) ;
if ( ! V_234 )
return - V_37 ;
V_234 -> V_4 . V_193 = V_193 ;
V_234 -> V_4 . V_128 = V_195 ;
V_234 -> V_4 . V_196 = V_196 ;
V_234 -> V_4 . V_197 = V_197 ;
V_234 -> V_4 . V_235 = V_235 ;
F_78 ( & V_166 -> V_236 ) ;
F_3 ( & V_234 -> V_12 , & V_166 -> V_237 ) ;
F_79 ( & V_166 -> V_236 ) ;
V_101 = F_80 ( & V_166 -> V_154 ) ;
return V_101 ? : V_174 ;
}
static void F_81 ( struct V_165 * V_166 )
{
struct V_233 * V_234 , * V_42 ;
F_78 ( & V_166 -> V_236 ) ;
F_82 (dynid, n, &hdrv->dyn_list, list) {
F_83 ( & V_234 -> V_12 ) ;
F_8 ( V_234 ) ;
}
F_79 ( & V_166 -> V_236 ) ;
}
static const struct V_192 * F_84 ( struct V_2 * V_191 ,
struct V_165 * V_166 )
{
struct V_233 * V_234 ;
F_78 ( & V_166 -> V_236 ) ;
F_85 (dynid, &hdrv->dyn_list, list) {
if ( F_63 ( V_191 , & V_234 -> V_4 ) ) {
F_79 ( & V_166 -> V_236 ) ;
return & V_234 -> V_4 ;
}
}
F_79 ( & V_166 -> V_236 ) ;
return F_64 ( V_191 , V_166 -> V_238 ) ;
}
static int F_86 ( struct V_3 * V_115 , struct V_231 * V_232 )
{
struct V_165 * V_166 = F_26 ( V_232 , struct V_165 , V_154 ) ;
struct V_2 * V_191 = F_26 ( V_115 , struct V_2 , V_115 ) ;
return F_84 ( V_191 , V_166 ) != NULL ;
}
static int F_87 ( struct V_3 * V_115 )
{
struct V_165 * V_166 = F_26 ( V_115 -> V_154 ,
struct V_165 , V_154 ) ;
struct V_2 * V_191 = F_26 ( V_115 , struct V_2 , V_115 ) ;
const struct V_192 * V_4 ;
int V_101 = 0 ;
if ( F_88 ( & V_191 -> V_239 ) )
return - V_240 ;
if ( F_88 ( & V_191 -> V_187 ) ) {
V_101 = - V_240 ;
goto V_241;
}
V_191 -> V_242 = false ;
if ( ! V_191 -> V_154 ) {
V_4 = F_84 ( V_191 , V_166 ) ;
if ( V_4 == NULL ) {
V_101 = - V_186 ;
goto V_189;
}
V_191 -> V_154 = V_166 ;
if ( V_166 -> V_243 ) {
V_101 = V_166 -> V_243 ( V_191 , V_4 ) ;
} else {
V_101 = F_34 ( V_191 ) ;
if ( ! V_101 )
V_101 = F_89 ( V_191 , V_244 ) ;
}
if ( V_101 ) {
F_23 ( V_191 ) ;
V_191 -> V_154 = NULL ;
}
}
V_189:
if ( ! V_191 -> V_242 )
F_62 ( & V_191 -> V_187 ) ;
V_241:
F_62 ( & V_191 -> V_239 ) ;
return V_101 ;
}
static int F_90 ( struct V_3 * V_115 )
{
struct V_2 * V_191 = F_26 ( V_115 , struct V_2 , V_115 ) ;
struct V_165 * V_166 ;
int V_101 = 0 ;
if ( F_88 ( & V_191 -> V_239 ) )
return - V_240 ;
if ( F_88 ( & V_191 -> V_187 ) ) {
V_101 = - V_240 ;
goto V_241;
}
V_191 -> V_242 = false ;
V_166 = V_191 -> V_154 ;
if ( V_166 ) {
if ( V_166 -> remove )
V_166 -> remove ( V_191 ) ;
else
F_91 ( V_191 ) ;
F_23 ( V_191 ) ;
V_191 -> V_154 = NULL ;
}
if ( ! V_191 -> V_242 )
F_62 ( & V_191 -> V_187 ) ;
V_241:
F_62 ( & V_191 -> V_239 ) ;
return V_101 ;
}
static T_4 F_92 ( struct V_3 * V_115 , struct V_245 * V_146 ,
char * V_142 )
{
struct V_2 * V_191 = F_26 ( V_115 , struct V_2 , V_115 ) ;
int V_208 ;
V_208 = snprintf ( V_142 , V_246 , L_50 ,
V_191 -> V_193 , V_191 -> V_128 , V_191 -> V_196 , V_191 -> V_197 ) ;
return ( V_208 >= V_246 ) ? ( V_246 - 1 ) : V_208 ;
}
static int F_93 ( struct V_3 * V_115 , struct V_247 * V_248 )
{
struct V_2 * V_191 = F_26 ( V_115 , struct V_2 , V_115 ) ;
if ( F_94 ( V_248 , L_51 ,
V_191 -> V_193 , V_191 -> V_196 , V_191 -> V_197 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_52 , V_191 -> V_169 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_53 , V_191 -> V_229 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_54 , V_191 -> V_249 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_55 ,
V_191 -> V_193 , V_191 -> V_128 , V_191 -> V_196 , V_191 -> V_197 ) )
return - V_37 ;
return 0 ;
}
bool F_95 ( struct V_2 * V_191 )
{
if ( V_191 -> V_209 & V_250 )
return false ;
if ( V_191 -> V_209 & V_251 )
return true ;
switch ( V_191 -> V_196 ) {
case V_252 :
if ( V_191 -> V_197 >= V_253 &&
V_191 -> V_197 <= V_254 )
return true ;
break;
case V_255 :
if ( V_191 -> V_197 >= V_256 &&
V_191 -> V_197 <= V_257 )
return true ;
if ( V_191 -> V_197 == V_258 &&
! strcmp ( V_191 -> V_169 , L_56 ) )
return true ;
break;
case V_259 :
if ( V_191 -> V_197 >= V_260 &&
V_191 -> V_197 <= V_261 )
return true ;
break;
case V_262 :
if ( V_191 -> V_197 >= V_263 &&
V_191 -> V_197 <= V_264 )
return true ;
break;
case V_265 :
if ( V_191 -> V_197 == V_266 &&
V_191 -> type == V_267 )
return true ;
break;
case V_268 :
if ( ( V_191 -> V_197 == V_269 ||
V_191 -> V_197 == V_270 ) &&
V_191 -> type != V_271 )
return true ;
break;
case V_272 :
if ( ( V_191 -> V_197 >= V_273 &&
V_191 -> V_197 <= V_274 ) ||
( V_191 -> V_197 >= V_275 &&
V_191 -> V_197 <= V_276 ) )
return true ;
break;
case V_277 :
if ( V_191 -> V_197 == V_278 &&
V_191 -> V_193 == V_215 &&
strncmp ( V_191 -> V_169 , L_57 , 22 ) == 0 )
return true ;
break;
}
if ( V_191 -> type == V_271 &&
F_64 ( V_191 , V_279 ) )
return true ;
return ! ! F_64 ( V_191 , V_280 ) ;
}
int F_96 ( struct V_2 * V_191 )
{
static T_7 V_4 = F_97 ( 0 ) ;
int V_101 ;
if ( F_42 ( V_191 -> V_113 & V_281 ) )
return - V_188 ;
if ( F_95 ( V_191 ) )
return - V_186 ;
V_101 = V_191 -> V_282 -> V_283 ( V_191 ) ;
if ( V_101 )
return V_101 ;
if ( ! V_191 -> V_116 )
return - V_186 ;
if ( V_284 ||
! F_64 ( V_191 , V_285 ) ) {
V_101 = F_31 ( V_191 ) ;
if ( V_101 )
F_39 ( V_191 , L_58 , V_101 ) ;
}
F_98 ( & V_191 -> V_115 , L_59 , V_191 -> V_193 ,
V_191 -> V_196 , V_191 -> V_197 , F_99 ( & V_4 ) ) ;
F_100 ( V_191 , F_101 ( & V_191 -> V_115 ) ) ;
V_101 = F_102 ( & V_191 -> V_115 ) ;
if ( ! V_101 )
V_191 -> V_113 |= V_281 ;
else
F_103 ( V_191 ) ;
return V_101 ;
}
struct V_2 * F_104 ( void )
{
struct V_2 * V_191 ;
int V_101 = - V_37 ;
V_191 = F_2 ( sizeof( * V_191 ) , V_9 ) ;
if ( V_191 == NULL )
return F_105 ( V_101 ) ;
F_106 ( & V_191 -> V_115 ) ;
V_191 -> V_115 . V_286 = F_25 ;
V_191 -> V_115 . V_193 = & V_287 ;
F_23 ( V_191 ) ;
F_107 ( & V_191 -> V_288 ) ;
F_24 ( & V_191 -> V_167 ) ;
F_108 ( & V_191 -> V_289 ) ;
F_109 ( & V_191 -> V_239 , 1 ) ;
F_109 ( & V_191 -> V_187 , 1 ) ;
return V_191 ;
}
static void F_110 ( struct V_2 * V_191 )
{
if ( V_191 -> V_113 & V_281 ) {
F_111 ( & V_191 -> V_115 ) ;
F_103 ( V_191 ) ;
V_191 -> V_113 &= ~ V_281 ;
}
F_8 ( V_191 -> V_116 ) ;
V_191 -> V_116 = NULL ;
V_191 -> V_132 = 0 ;
}
void F_112 ( struct V_2 * V_191 )
{
F_110 ( V_191 ) ;
F_113 ( & V_191 -> V_115 ) ;
}
int F_114 ( struct V_165 * V_166 , struct V_290 * V_291 ,
const char * V_292 )
{
int V_101 ;
V_166 -> V_154 . V_169 = V_166 -> V_169 ;
V_166 -> V_154 . V_193 = & V_287 ;
V_166 -> V_154 . V_291 = V_291 ;
V_166 -> V_154 . V_292 = V_292 ;
F_24 ( & V_166 -> V_237 ) ;
F_108 ( & V_166 -> V_236 ) ;
V_101 = F_115 ( & V_166 -> V_154 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_116 ( & V_166 -> V_154 , & V_293 ) ;
if ( V_101 )
F_117 ( & V_166 -> V_154 ) ;
return V_101 ;
}
void F_118 ( struct V_165 * V_166 )
{
F_119 ( & V_166 -> V_154 , & V_293 ) ;
F_117 ( & V_166 -> V_154 ) ;
F_81 ( V_166 ) ;
}
int F_120 ( struct V_2 * V_61 )
{
struct V_294 * V_295 ;
int V_18 ;
if ( ! ( V_61 -> V_170 & V_171 ) )
return 0 ;
F_85 (hidinput, &hid->inputs, list) {
for ( V_18 = 0 ; V_18 < F_121 ( V_296 ) ; V_18 ++ )
if ( V_295 -> V_297 -> V_298 [ V_18 ] )
return 1 ;
}
return 0 ;
}
static int T_8 F_122 ( void )
{
int V_101 ;
if ( V_299 )
F_123 ( L_60
L_61 ) ;
V_101 = F_124 ( & V_287 ) ;
if ( V_101 ) {
F_125 ( L_62 ) ;
goto V_300;
}
V_101 = F_126 () ;
if ( V_101 )
goto V_301;
F_127 () ;
return 0 ;
V_301:
F_128 ( & V_287 ) ;
V_300:
return V_101 ;
}
static void T_9 F_129 ( void )
{
F_130 () ;
F_131 () ;
F_128 ( & V_287 ) ;
}
