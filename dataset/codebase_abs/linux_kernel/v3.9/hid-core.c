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
( V_61 -> V_141 == V_142 || V_61 -> V_141 == V_143 ) )
V_61 -> V_128 = V_144 ;
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
T_2 * V_145 ;
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
case 8 : return ( ( V_146 ) V_24 ) ;
case 16 : return ( ( V_147 ) V_24 ) ;
case 32 : return ( ( V_148 ) V_24 ) ;
}
return V_24 & ( 1 << ( V_42 - 1 ) ) ? V_24 | ( - 1 << V_42 ) : V_24 ;
}
V_25 F_18 ( V_52 V_24 , unsigned V_42 )
{
return F_36 ( V_24 , V_42 ) ;
}
static T_1 F_37 ( V_148 V_24 , unsigned V_42 )
{
V_25 V_149 = V_24 >> ( V_42 - 1 ) ;
if ( V_149 && V_149 != - 1 )
return V_24 < 0 ? 1 << ( V_42 - 1 ) : ( 1 << ( V_42 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_42 ) - 1 ) ;
}
static V_52 F_38 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_47 , unsigned V_42 )
{
T_3 V_150 ;
if ( V_42 > 32 )
F_39 ( V_61 , L_21 ,
V_42 , V_151 -> V_152 ) ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_150 = F_40 ( V_7 ) ;
V_150 = ( V_150 >> V_47 ) & ( ( 1ULL << V_42 ) - 1 ) ;
return ( T_1 ) V_150 ;
}
static void F_41 ( const struct V_2 * V_61 , T_2 * V_7 ,
unsigned V_47 , unsigned V_42 , V_52 V_24 )
{
T_3 V_150 ;
T_3 V_153 = ( 1ULL << V_42 ) - 1 ;
if ( V_42 > 32 )
F_39 ( V_61 , L_22 ,
V_154 , V_42 , V_151 -> V_152 ) ;
if ( V_24 > V_153 )
F_39 ( V_61 , L_23 ,
V_154 , V_24 , V_151 -> V_152 ) ;
F_42 ( V_24 > V_153 ) ;
V_24 &= V_153 ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_150 = F_40 ( V_7 ) ;
V_150 &= ~ ( V_153 << V_47 ) ;
V_150 |= ( ( T_3 ) V_24 ) << V_47 ;
F_43 ( V_150 , V_7 ) ;
}
static int F_44 ( V_148 * V_155 , V_148 V_24 , unsigned V_42 )
{
while ( V_42 -- ) {
if ( * V_155 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_45 ( struct V_2 * V_61 , struct V_1 * V_7 )
{
const struct V_156 * V_4 = V_61 -> V_157 -> V_158 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_159 ; V_4 ++ )
if ( V_4 -> V_45 == V_160 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_61 , struct V_21 * V_23 )
{
const struct V_161 * V_4 = V_61 -> V_157 -> V_162 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_163 != V_160 - 1 ; V_4 ++ )
if ( ( V_4 -> V_164 == V_160 ||
V_4 -> V_164 == V_23 -> V_61 ) &&
( V_4 -> V_163 == V_160 ||
V_4 -> V_163 == V_23 -> type ) &&
( V_4 -> V_165 == V_160 ||
V_4 -> V_165 == V_23 -> V_166 ) )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_2 * V_61 , struct V_14 * V_17 ,
struct V_21 * V_23 , V_148 V_24 , int V_167 )
{
struct V_168 * V_169 = V_61 -> V_157 ;
int V_101 ;
if ( ! F_48 ( & V_61 -> V_170 ) )
F_49 ( V_61 , V_23 , V_24 ) ;
if ( V_169 && V_169 -> V_171 && F_46 ( V_61 , V_23 ) ) {
V_101 = V_169 -> V_171 ( V_61 , V_17 , V_23 , V_24 ) ;
if ( V_101 != 0 ) {
if ( V_101 < 0 )
F_5 ( V_61 , L_24 ,
V_169 -> V_172 , V_101 ) ;
return;
}
}
if ( V_61 -> V_173 & V_174 )
F_50 ( V_61 , V_17 , V_23 , V_24 ) ;
if ( V_61 -> V_173 & V_175 && V_167 && V_61 -> V_176 )
V_61 -> V_176 ( V_61 , V_17 , V_23 , V_24 ) ;
}
static void F_51 ( struct V_2 * V_61 , struct V_14 * V_17 ,
T_2 * V_70 , int V_167 )
{
unsigned V_42 ;
unsigned V_177 = V_17 -> V_54 ;
unsigned V_47 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
V_148 V_178 = V_17 -> V_50 ;
V_148 V_179 = V_17 -> V_51 ;
V_148 * V_24 ;
V_24 = F_7 ( sizeof( V_148 ) * V_177 , V_180 ) ;
if ( ! V_24 )
return;
for ( V_42 = 0 ; V_42 < V_177 ; V_42 ++ ) {
V_24 [ V_42 ] = V_178 < 0 ?
F_36 ( F_38 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ) ,
V_11 ) :
F_38 ( V_61 , V_70 , V_47 + V_42 * V_11 , V_11 ) ;
if ( ! ( V_17 -> V_46 & V_181 ) &&
V_24 [ V_42 ] >= V_178 && V_24 [ V_42 ] <= V_179 &&
V_17 -> V_23 [ V_24 [ V_42 ] - V_178 ] . V_61 == V_182 + 1 )
goto exit;
}
for ( V_42 = 0 ; V_42 < V_177 ; V_42 ++ ) {
if ( V_181 & V_17 -> V_46 ) {
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_42 ] , V_24 [ V_42 ] , V_167 ) ;
continue;
}
if ( V_17 -> V_24 [ V_42 ] >= V_178 && V_17 -> V_24 [ V_42 ] <= V_179
&& V_17 -> V_23 [ V_17 -> V_24 [ V_42 ] - V_178 ] . V_61
&& F_44 ( V_24 , V_17 -> V_24 [ V_42 ] , V_177 ) )
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_17 -> V_24 [ V_42 ] - V_178 ] , 0 , V_167 ) ;
if ( V_24 [ V_42 ] >= V_178 && V_24 [ V_42 ] <= V_179
&& V_17 -> V_23 [ V_24 [ V_42 ] - V_178 ] . V_61
&& F_44 ( V_17 -> V_24 , V_24 [ V_42 ] , V_177 ) )
F_47 ( V_61 , V_17 , & V_17 -> V_23 [ V_24 [ V_42 ] - V_178 ] , 1 , V_167 ) ;
}
memcpy ( V_17 -> V_24 , V_24 , V_177 * sizeof( V_148 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_52 ( const struct V_2 * V_61 ,
struct V_14 * V_17 , T_2 * V_70 )
{
unsigned V_177 = V_17 -> V_54 ;
unsigned V_47 = V_17 -> V_63 ;
unsigned V_11 = V_17 -> V_53 ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_177 ; V_42 ++ ) {
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
int F_54 ( struct V_14 * V_17 , unsigned V_47 , V_148 V_24 )
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
int V_167 )
{
struct V_5 * V_6 = V_61 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_168 * V_169 ;
unsigned int V_149 ;
int V_112 , V_183 = V_11 ;
V_71 * V_184 = V_70 ;
int V_101 = 0 ;
V_7 = F_55 ( V_6 , V_70 ) ;
if ( ! V_7 )
goto V_185;
if ( V_6 -> V_10 ) {
V_184 ++ ;
V_183 -- ;
}
V_112 = ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ;
if ( V_112 > V_186 )
V_112 = V_186 ;
if ( V_183 < V_112 ) {
F_13 ( L_28 , V_7 -> V_4 ,
V_183 , V_112 ) ;
memset ( V_184 + V_183 , 0 , V_112 - V_183 ) ;
}
if ( ( V_61 -> V_173 & V_175 ) && V_61 -> V_187 )
V_61 -> V_187 ( V_61 , V_7 ) ;
if ( V_61 -> V_173 & V_188 ) {
V_101 = F_57 ( V_61 , V_70 , V_11 ) ;
if ( V_101 )
goto V_185;
}
if ( V_61 -> V_173 != V_188 ) {
for ( V_149 = 0 ; V_149 < V_7 -> V_19 ; V_149 ++ )
F_51 ( V_61 , V_7 -> V_17 [ V_149 ] , V_184 , V_167 ) ;
V_169 = V_61 -> V_157 ;
if ( V_169 && V_169 -> V_7 )
V_169 -> V_7 ( V_61 , V_7 ) ;
}
if ( V_61 -> V_173 & V_174 )
F_58 ( V_61 , V_7 ) ;
V_185:
return V_101 ;
}
int F_59 ( struct V_2 * V_61 , int type , V_71 * V_70 , int V_11 , int V_167 )
{
struct V_5 * V_6 ;
struct V_168 * V_169 ;
struct V_1 * V_7 ;
char * V_145 ;
unsigned int V_18 ;
int V_101 = 0 ;
if ( ! V_61 )
return - V_189 ;
if ( F_60 ( & V_61 -> V_190 ) )
return - V_191 ;
if ( ! V_61 -> V_157 ) {
V_101 = - V_189 ;
goto V_192;
}
V_6 = V_61 -> V_6 + type ;
V_169 = V_61 -> V_157 ;
if ( ! V_11 ) {
F_13 ( L_29 ) ;
V_101 = - 1 ;
goto V_192;
}
if ( F_48 ( & V_61 -> V_170 ) )
goto V_193;
V_145 = F_7 ( sizeof( char ) * V_194 , V_180 ) ;
if ( ! V_145 )
goto V_193;
snprintf ( V_145 , V_194 - 1 ,
L_30 , V_11 , V_6 -> V_10 ? L_31 : L_32 ) ;
F_61 ( V_61 , V_145 ) ;
for ( V_18 = 0 ; V_18 < V_11 ; V_18 ++ ) {
snprintf ( V_145 , V_194 - 1 ,
L_33 , V_70 [ V_18 ] ) ;
F_61 ( V_61 , V_145 ) ;
}
F_61 ( V_61 , L_34 ) ;
F_8 ( V_145 ) ;
V_193:
V_7 = F_55 ( V_6 , V_70 ) ;
if ( ! V_7 ) {
V_101 = - 1 ;
goto V_192;
}
if ( V_169 && V_169 -> V_195 && F_45 ( V_61 , V_7 ) ) {
V_101 = V_169 -> V_195 ( V_61 , V_7 , V_70 , V_11 ) ;
if ( V_101 != 0 ) {
V_101 = V_101 < 0 ? V_101 : 0 ;
goto V_192;
}
}
V_101 = F_56 ( V_61 , type , V_70 , V_11 , V_167 ) ;
V_192:
F_62 ( & V_61 -> V_190 ) ;
return V_101 ;
}
static bool F_63 ( struct V_2 * V_196 ,
const struct V_197 * V_4 )
{
return ( V_4 -> V_141 == V_198 || V_4 -> V_141 == V_196 -> V_141 ) &&
( V_4 -> V_128 == V_199 || V_4 -> V_128 == V_196 -> V_128 ) &&
( V_4 -> V_200 == V_160 || V_4 -> V_200 == V_196 -> V_200 ) &&
( V_4 -> V_201 == V_160 || V_4 -> V_201 == V_196 -> V_201 ) ;
}
const struct V_197 * F_64 ( struct V_2 * V_196 ,
const struct V_197 * V_4 )
{
for (; V_4 -> V_141 ; V_4 ++ )
if ( F_63 ( V_196 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_65 ( struct V_2 * V_196 )
{
return ! ! F_64 ( V_196 , V_202 ) ;
}
static T_4
F_66 ( struct V_203 * V_204 , struct V_205 * V_206 ,
struct V_207 * V_208 ,
char * V_145 , T_5 V_209 , T_6 V_177 )
{
struct V_3 * V_115 = F_26 ( V_206 , struct V_3 , V_206 ) ;
struct V_2 * V_196 = F_26 ( V_115 , struct V_2 , V_115 ) ;
if ( V_209 >= V_196 -> V_112 )
return 0 ;
if ( V_209 + V_177 > V_196 -> V_112 )
V_177 = V_196 -> V_112 - V_209 ;
memcpy ( V_145 , V_196 -> V_111 + V_209 , V_177 ) ;
return V_177 ;
}
int F_67 ( struct V_2 * V_196 , unsigned int V_210 )
{
static const char * V_211 [] = { L_35 , L_36 , L_37 , L_35 ,
L_38 , L_39 , L_40 , L_41 ,
L_42
} ;
const char * type , * V_141 ;
char V_145 [ 64 ] ;
unsigned int V_18 ;
int V_212 ;
int V_101 ;
if ( V_196 -> V_213 & V_214 )
V_210 |= ( V_215 | V_216 ) ;
if ( V_196 -> V_213 & V_217 )
V_210 |= V_218 ;
if ( V_196 -> V_141 != V_142 )
V_210 &= ~ V_216 ;
if ( F_65 ( V_196 ) )
V_210 |= V_215 ;
if ( ( V_210 & V_219 ) && ! F_68 ( V_196 ,
V_210 & V_218 ) )
V_196 -> V_173 |= V_174 ;
if ( ( V_210 & V_216 ) && V_196 -> V_220 &&
! V_196 -> V_220 ( V_196 ,
V_210 & V_215 ) )
V_196 -> V_173 |= V_175 ;
if ( ( V_210 & V_221 ) && ! F_69 ( V_196 ) )
V_196 -> V_173 |= V_188 ;
if ( ! V_196 -> V_173 && ! V_196 -> V_157 -> V_195 ) {
F_5 ( V_196 , L_43 ) ;
return - V_189 ;
}
if ( ( V_196 -> V_173 & V_174 ) &&
( V_210 & V_222 ) && V_196 -> V_223 )
V_196 -> V_223 ( V_196 ) ;
V_212 = 0 ;
if ( V_196 -> V_173 & V_174 )
V_212 += sprintf ( V_145 + V_212 , L_44 ) ;
if ( V_196 -> V_173 & V_175 )
V_212 += sprintf ( V_145 + V_212 , L_45 , V_212 ? L_46 : L_31 ,
V_196 -> V_224 ) ;
if ( V_196 -> V_173 & V_188 )
V_212 += sprintf ( V_145 + V_212 , L_47 , V_212 ? L_46 : L_31 ,
( (struct V_225 * ) V_196 -> V_225 ) -> V_224 ) ;
type = L_35 ;
for ( V_18 = 0 ; V_18 < V_196 -> V_35 ; V_18 ++ ) {
struct V_29 * V_226 = & V_196 -> V_30 [ V_18 ] ;
if ( V_226 -> type == V_40 &&
( V_226 -> V_23 & V_227 ) == V_228 &&
( V_226 -> V_23 & 0xffff ) < F_70 ( V_211 ) ) {
type = V_211 [ V_226 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_196 -> V_141 ) {
case V_142 :
V_141 = L_48 ;
break;
case V_229 :
V_141 = L_49 ;
break;
default:
V_141 = L_50 ;
}
V_101 = F_71 ( & V_196 -> V_115 , & V_230 ) ;
if ( V_101 )
F_39 ( V_196 ,
L_51 , V_101 ) ;
F_72 ( V_196 , L_52 ,
V_145 , V_141 , V_196 -> V_231 >> 8 , V_196 -> V_231 & 0xff ,
type , V_196 -> V_172 , V_196 -> V_232 ) ;
return 0 ;
}
void F_73 ( struct V_2 * V_196 )
{
F_74 ( & V_196 -> V_115 , & V_230 ) ;
if ( V_196 -> V_173 & V_174 )
F_75 ( V_196 ) ;
if ( V_196 -> V_173 & V_175 )
V_196 -> V_233 ( V_196 ) ;
if ( V_196 -> V_173 & V_188 )
F_76 ( V_196 ) ;
}
static T_4 F_77 ( struct V_234 * V_235 , const char * V_145 ,
T_6 V_177 )
{
struct V_168 * V_169 = F_26 ( V_235 , struct V_168 , V_157 ) ;
struct V_236 * V_237 ;
V_52 V_141 , V_200 , V_201 ;
unsigned long V_238 = 0 ;
int V_101 ;
V_101 = sscanf ( V_145 , L_53 ,
& V_141 , & V_200 , & V_201 , & V_238 ) ;
if ( V_101 < 3 )
return - V_34 ;
V_237 = F_2 ( sizeof( * V_237 ) , V_9 ) ;
if ( ! V_237 )
return - V_37 ;
V_237 -> V_4 . V_141 = V_141 ;
V_237 -> V_4 . V_128 = V_199 ;
V_237 -> V_4 . V_200 = V_200 ;
V_237 -> V_4 . V_201 = V_201 ;
V_237 -> V_4 . V_238 = V_238 ;
F_78 ( & V_169 -> V_239 ) ;
F_3 ( & V_237 -> V_12 , & V_169 -> V_240 ) ;
F_79 ( & V_169 -> V_239 ) ;
V_101 = F_80 ( & V_169 -> V_157 ) ;
return V_101 ? : V_177 ;
}
static void F_81 ( struct V_168 * V_169 )
{
struct V_236 * V_237 , * V_42 ;
F_78 ( & V_169 -> V_239 ) ;
F_82 (dynid, n, &hdrv->dyn_list, list) {
F_83 ( & V_237 -> V_12 ) ;
F_8 ( V_237 ) ;
}
F_79 ( & V_169 -> V_239 ) ;
}
static const struct V_197 * F_84 ( struct V_2 * V_196 ,
struct V_168 * V_169 )
{
struct V_236 * V_237 ;
F_78 ( & V_169 -> V_239 ) ;
F_85 (dynid, &hdrv->dyn_list, list) {
if ( F_63 ( V_196 , & V_237 -> V_4 ) ) {
F_79 ( & V_169 -> V_239 ) ;
return & V_237 -> V_4 ;
}
}
F_79 ( & V_169 -> V_239 ) ;
return F_64 ( V_196 , V_169 -> V_241 ) ;
}
static int F_86 ( struct V_3 * V_115 , struct V_234 * V_235 )
{
struct V_168 * V_169 = F_26 ( V_235 , struct V_168 , V_157 ) ;
struct V_2 * V_196 = F_26 ( V_115 , struct V_2 , V_115 ) ;
return F_84 ( V_196 , V_169 ) != NULL ;
}
static int F_87 ( struct V_3 * V_115 )
{
struct V_168 * V_169 = F_26 ( V_115 -> V_157 ,
struct V_168 , V_157 ) ;
struct V_2 * V_196 = F_26 ( V_115 , struct V_2 , V_115 ) ;
const struct V_197 * V_4 ;
int V_101 = 0 ;
if ( F_88 ( & V_196 -> V_190 ) )
return - V_242 ;
if ( ! V_196 -> V_157 ) {
V_4 = F_84 ( V_196 , V_169 ) ;
if ( V_4 == NULL ) {
V_101 = - V_189 ;
goto V_192;
}
V_196 -> V_157 = V_169 ;
if ( V_169 -> V_243 ) {
V_101 = V_169 -> V_243 ( V_196 , V_4 ) ;
} else {
V_101 = F_34 ( V_196 ) ;
if ( ! V_101 )
V_101 = F_89 ( V_196 , V_244 ) ;
}
if ( V_101 ) {
F_23 ( V_196 ) ;
V_196 -> V_157 = NULL ;
}
}
V_192:
F_62 ( & V_196 -> V_190 ) ;
return V_101 ;
}
static int F_90 ( struct V_3 * V_115 )
{
struct V_2 * V_196 = F_26 ( V_115 , struct V_2 , V_115 ) ;
struct V_168 * V_169 ;
if ( F_88 ( & V_196 -> V_190 ) )
return - V_242 ;
V_169 = V_196 -> V_157 ;
if ( V_169 ) {
if ( V_169 -> remove )
V_169 -> remove ( V_196 ) ;
else
F_91 ( V_196 ) ;
F_23 ( V_196 ) ;
V_196 -> V_157 = NULL ;
}
F_62 ( & V_196 -> V_190 ) ;
return 0 ;
}
static T_4 F_92 ( struct V_3 * V_115 , struct V_245 * V_149 ,
char * V_145 )
{
struct V_2 * V_196 = F_26 ( V_115 , struct V_2 , V_115 ) ;
int V_212 ;
V_212 = snprintf ( V_145 , V_246 , L_54 ,
V_196 -> V_141 , V_196 -> V_128 , V_196 -> V_200 , V_196 -> V_201 ) ;
return ( V_212 >= V_246 ) ? ( V_246 - 1 ) : V_212 ;
}
static int F_93 ( struct V_3 * V_115 , struct V_247 * V_248 )
{
struct V_2 * V_196 = F_26 ( V_115 , struct V_2 , V_115 ) ;
if ( F_94 ( V_248 , L_55 ,
V_196 -> V_141 , V_196 -> V_200 , V_196 -> V_201 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_56 , V_196 -> V_172 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_57 , V_196 -> V_232 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_58 , V_196 -> V_249 ) )
return - V_37 ;
if ( F_94 ( V_248 , L_59 ,
V_196 -> V_141 , V_196 -> V_128 , V_196 -> V_200 , V_196 -> V_201 ) )
return - V_37 ;
return 0 ;
}
bool F_95 ( struct V_2 * V_196 )
{
if ( V_196 -> V_213 & V_250 )
return false ;
if ( V_196 -> V_213 & V_251 )
return true ;
switch ( V_196 -> V_200 ) {
case V_252 :
if ( V_196 -> V_201 >= V_253 &&
V_196 -> V_201 <= V_254 )
return true ;
break;
case V_255 :
if ( V_196 -> V_201 >= V_256 &&
V_196 -> V_201 <= V_257 )
return true ;
if ( V_196 -> V_201 == V_258 &&
! strcmp ( V_196 -> V_172 , L_60 ) )
return true ;
break;
case V_259 :
if ( V_196 -> V_201 >= V_260 &&
V_196 -> V_201 <= V_261 )
return true ;
break;
case V_262 :
if ( V_196 -> V_201 >= V_263 &&
V_196 -> V_201 <= V_264 )
return true ;
break;
case V_265 :
if ( V_196 -> V_201 == V_266 &&
V_196 -> type == V_267 )
return true ;
break;
case V_268 :
if ( ( V_196 -> V_201 == V_269 ||
V_196 -> V_201 == V_270 ) &&
V_196 -> type != V_271 )
return true ;
break;
case V_272 :
if ( ( V_196 -> V_201 >= V_273 &&
V_196 -> V_201 <= V_274 ) ||
( V_196 -> V_201 >= V_275 &&
V_196 -> V_201 <= V_276 ) )
return true ;
break;
case V_277 :
if ( V_196 -> V_201 == V_278 &&
V_196 -> V_141 == V_142 &&
strncmp ( V_196 -> V_172 , L_61 , 22 ) == 0 )
return true ;
break;
}
if ( V_196 -> type == V_271 &&
F_64 ( V_196 , V_279 ) )
return true ;
return ! ! F_64 ( V_196 , V_280 ) ;
}
int F_96 ( struct V_2 * V_196 )
{
static T_7 V_4 = F_97 ( 0 ) ;
int V_101 ;
if ( F_42 ( V_196 -> V_113 & V_281 ) )
return - V_191 ;
if ( F_95 ( V_196 ) )
return - V_189 ;
V_101 = V_196 -> V_282 -> V_283 ( V_196 ) ;
if ( V_101 )
return V_101 ;
if ( ! V_196 -> V_116 )
return - V_189 ;
if ( V_284 ||
! F_64 ( V_196 , V_285 ) ) {
V_101 = F_31 ( V_196 ) ;
if ( V_101 )
F_39 ( V_196 , L_62 , V_101 ) ;
}
F_98 ( & V_196 -> V_115 , L_63 , V_196 -> V_141 ,
V_196 -> V_200 , V_196 -> V_201 , F_99 ( & V_4 ) ) ;
F_100 ( V_196 , F_101 ( & V_196 -> V_115 ) ) ;
V_101 = F_102 ( & V_196 -> V_115 ) ;
if ( ! V_101 )
V_196 -> V_113 |= V_281 ;
else
F_103 ( V_196 ) ;
return V_101 ;
}
struct V_2 * F_104 ( void )
{
struct V_2 * V_196 ;
int V_101 = - V_37 ;
V_196 = F_2 ( sizeof( * V_196 ) , V_9 ) ;
if ( V_196 == NULL )
return F_105 ( V_101 ) ;
F_106 ( & V_196 -> V_115 ) ;
V_196 -> V_115 . V_286 = F_25 ;
V_196 -> V_115 . V_141 = & V_287 ;
F_23 ( V_196 ) ;
F_107 ( & V_196 -> V_288 ) ;
F_24 ( & V_196 -> V_170 ) ;
F_108 ( & V_196 -> V_190 , 1 ) ;
return V_196 ;
}
static void F_109 ( struct V_2 * V_196 )
{
if ( V_196 -> V_113 & V_281 ) {
F_110 ( & V_196 -> V_115 ) ;
F_103 ( V_196 ) ;
V_196 -> V_113 &= ~ V_281 ;
}
F_8 ( V_196 -> V_116 ) ;
V_196 -> V_116 = NULL ;
V_196 -> V_132 = 0 ;
}
void F_111 ( struct V_2 * V_196 )
{
F_109 ( V_196 ) ;
F_112 ( & V_196 -> V_115 ) ;
}
int F_113 ( struct V_168 * V_169 , struct V_289 * V_290 ,
const char * V_291 )
{
int V_101 ;
V_169 -> V_157 . V_172 = V_169 -> V_172 ;
V_169 -> V_157 . V_141 = & V_287 ;
V_169 -> V_157 . V_290 = V_290 ;
V_169 -> V_157 . V_291 = V_291 ;
F_24 ( & V_169 -> V_240 ) ;
F_114 ( & V_169 -> V_239 ) ;
V_101 = F_115 ( & V_169 -> V_157 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_116 ( & V_169 -> V_157 , & V_292 ) ;
if ( V_101 )
F_117 ( & V_169 -> V_157 ) ;
return V_101 ;
}
void F_118 ( struct V_168 * V_169 )
{
F_119 ( & V_169 -> V_157 , & V_292 ) ;
F_117 ( & V_169 -> V_157 ) ;
F_81 ( V_169 ) ;
}
int F_120 ( struct V_2 * V_61 )
{
struct V_293 * V_294 ;
int V_18 ;
if ( ! ( V_61 -> V_173 & V_174 ) )
return 0 ;
F_85 (hidinput, &hid->inputs, list) {
for ( V_18 = 0 ; V_18 < F_121 ( V_295 ) ; V_18 ++ )
if ( V_294 -> V_296 -> V_297 [ V_18 ] )
return 1 ;
}
return 0 ;
}
static int T_8 F_122 ( void )
{
int V_101 ;
if ( V_298 )
F_123 ( L_64
L_65 ) ;
V_101 = F_124 ( & V_287 ) ;
if ( V_101 ) {
F_125 ( L_66 ) ;
goto V_299;
}
V_101 = F_126 () ;
if ( V_101 )
goto V_300;
F_127 () ;
return 0 ;
V_300:
F_128 ( & V_287 ) ;
V_299:
return V_101 ;
}
static void T_9 F_129 ( void )
{
F_130 () ;
F_131 () ;
F_128 ( & V_287 ) ;
}
