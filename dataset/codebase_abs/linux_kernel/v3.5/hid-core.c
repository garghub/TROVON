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
return - 1 ;
}
if ( V_26 -> V_3 -> V_32 == V_26 -> V_3 -> V_33 ) {
V_28 = F_7 ( sizeof( struct V_27 ) *
V_26 -> V_3 -> V_33 * 2 , V_9 ) ;
if ( V_28 == NULL ) {
F_5 ( V_26 -> V_3 , L_3 ) ;
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
F_5 ( V_26 -> V_3 , L_4 ) ;
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
F_5 ( V_26 -> V_3 , L_5 ) ;
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
F_5 ( V_26 -> V_3 , L_6 ) ;
return - 1 ;
}
if ( ( V_26 -> V_46 . V_48 < 0 &&
V_26 -> V_46 . V_49 <
V_26 -> V_46 . V_48 ) ||
( V_26 -> V_46 . V_48 >= 0 &&
( V_50 ) V_26 -> V_46 . V_49 <
( V_50 ) V_26 -> V_46 . V_48 ) ) {
F_13 ( L_7 ,
V_26 -> V_46 . V_48 ,
V_26 -> V_46 . V_49 ) ;
return - 1 ;
}
V_44 = V_7 -> V_11 ;
V_7 -> V_11 += V_26 -> V_46 . V_51 * V_26 -> V_46 . V_52 ;
if ( ! V_26 -> V_29 . V_39 )
return 0 ;
V_15 = F_14 ( int , V_26 -> V_29 . V_39 , V_26 -> V_46 . V_52 ) ;
V_17 = F_4 ( V_7 , V_15 , V_26 -> V_46 . V_52 ) ;
if ( ! V_17 )
return 0 ;
V_17 -> V_53 = F_10 ( V_26 , V_54 ) ;
V_17 -> V_55 = F_10 ( V_26 , V_56 ) ;
V_17 -> V_57 = F_10 ( V_26 , V_36 ) ;
for ( V_45 = 0 ; V_45 < V_15 ; V_45 ++ ) {
int V_58 = V_45 ;
if ( V_45 >= V_26 -> V_29 . V_39 )
V_58 = V_26 -> V_29 . V_39 - 1 ;
V_17 -> V_22 [ V_45 ] . V_59 = V_26 -> V_29 . V_22 [ V_58 ] ;
V_17 -> V_22 [ V_45 ] . V_41 =
V_26 -> V_29 . V_41 [ V_58 ] ;
}
V_17 -> V_60 = V_15 ;
V_17 -> V_43 = V_43 ;
V_17 -> V_61 = V_44 ;
V_17 -> V_42 = V_42 ;
V_17 -> V_51 = V_26 -> V_46 . V_51 ;
V_17 -> V_52 = V_26 -> V_46 . V_52 ;
V_17 -> V_48 = V_26 -> V_46 . V_48 ;
V_17 -> V_49 = V_26 -> V_46 . V_49 ;
V_17 -> V_62 = V_26 -> V_46 . V_62 ;
V_17 -> V_63 = V_26 -> V_46 . V_63 ;
V_17 -> V_64 = V_26 -> V_46 . V_64 ;
V_17 -> V_65 = V_26 -> V_46 . V_65 ;
return 0 ;
}
static T_1 F_15 ( struct V_66 * V_67 )
{
switch ( V_67 -> V_11 ) {
case 1 : return V_67 -> V_68 . V_69 ;
case 2 : return V_67 -> V_68 . V_70 ;
case 4 : return V_67 -> V_68 . T_1 ;
}
return 0 ;
}
static V_24 F_16 ( struct V_66 * V_67 )
{
switch ( V_67 -> V_11 ) {
case 1 : return V_67 -> V_68 . V_71 ;
case 2 : return V_67 -> V_68 . V_72 ;
case 4 : return V_67 -> V_68 . V_24 ;
}
return 0 ;
}
static int F_17 ( struct V_25 * V_26 , struct V_66 * V_67 )
{
switch ( V_67 -> V_73 ) {
case V_74 :
if ( V_26 -> V_75 == V_76 ) {
F_5 ( V_26 -> V_3 , L_8 ) ;
return - 1 ;
}
memcpy ( V_26 -> V_77 + V_26 -> V_75 ++ ,
& V_26 -> V_46 , sizeof( struct V_78 ) ) ;
return 0 ;
case V_79 :
if ( ! V_26 -> V_75 ) {
F_5 ( V_26 -> V_3 , L_9 ) ;
return - 1 ;
}
memcpy ( & V_26 -> V_46 , V_26 -> V_77 +
-- V_26 -> V_75 , sizeof( struct V_78 ) ) ;
return 0 ;
case V_80 :
V_26 -> V_46 . V_81 = F_15 ( V_67 ) ;
return 0 ;
case V_82 :
V_26 -> V_46 . V_48 = F_16 ( V_67 ) ;
return 0 ;
case V_83 :
if ( V_26 -> V_46 . V_48 < 0 )
V_26 -> V_46 . V_49 = F_16 ( V_67 ) ;
else
V_26 -> V_46 . V_49 = F_15 ( V_67 ) ;
return 0 ;
case V_84 :
V_26 -> V_46 . V_62 = F_16 ( V_67 ) ;
return 0 ;
case V_85 :
if ( V_26 -> V_46 . V_62 < 0 )
V_26 -> V_46 . V_63 = F_16 ( V_67 ) ;
else
V_26 -> V_46 . V_63 = F_15 ( V_67 ) ;
return 0 ;
case V_86 :
V_26 -> V_46 . V_64 = F_16 ( V_67 ) ;
return 0 ;
case V_87 :
V_26 -> V_46 . V_65 = F_15 ( V_67 ) ;
return 0 ;
case V_88 :
V_26 -> V_46 . V_51 = F_15 ( V_67 ) ;
if ( V_26 -> V_46 . V_51 > 96 ) {
F_5 ( V_26 -> V_3 , L_10 ,
V_26 -> V_46 . V_51 ) ;
return - 1 ;
}
return 0 ;
case V_89 :
V_26 -> V_46 . V_52 = F_15 ( V_67 ) ;
if ( V_26 -> V_46 . V_52 > V_40 ) {
F_5 ( V_26 -> V_3 , L_11 ,
V_26 -> V_46 . V_52 ) ;
return - 1 ;
}
return 0 ;
case V_90 :
V_26 -> V_46 . V_47 = F_15 ( V_67 ) ;
if ( V_26 -> V_46 . V_47 == 0 ) {
F_5 ( V_26 -> V_3 , L_12 ) ;
return - 1 ;
}
return 0 ;
default:
F_5 ( V_26 -> V_3 , L_13 , V_67 -> V_73 ) ;
return - 1 ;
}
}
static int F_18 ( struct V_25 * V_26 , struct V_66 * V_67 )
{
V_50 V_68 ;
unsigned V_38 ;
V_68 = F_15 ( V_67 ) ;
switch ( V_67 -> V_73 ) {
case V_91 :
if ( V_68 ) {
if ( V_26 -> V_29 . V_92 != 0 ) {
F_5 ( V_26 -> V_3 , L_14 ) ;
return - 1 ;
}
V_26 -> V_29 . V_92 ++ ;
V_26 -> V_29 . V_93 ++ ;
} else {
if ( V_26 -> V_29 . V_92 < 1 ) {
F_5 ( V_26 -> V_3 , L_15 ) ;
return - 1 ;
}
V_26 -> V_29 . V_92 -- ;
}
return 1 ;
case V_94 :
if ( V_26 -> V_29 . V_93 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_67 -> V_11 <= 2 )
V_68 = ( V_26 -> V_46 . V_81 << 16 ) + V_68 ;
return F_11 ( V_26 , V_68 ) ;
case V_95 :
if ( V_26 -> V_29 . V_93 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_67 -> V_11 <= 2 )
V_68 = ( V_26 -> V_46 . V_81 << 16 ) + V_68 ;
V_26 -> V_29 . V_96 = V_68 ;
return 0 ;
case V_97 :
if ( V_26 -> V_29 . V_93 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_67 -> V_11 <= 2 )
V_68 = ( V_26 -> V_46 . V_81 << 16 ) + V_68 ;
for ( V_38 = V_26 -> V_29 . V_96 ; V_38 <= V_68 ; V_38 ++ )
if ( F_11 ( V_26 , V_38 ) ) {
F_13 ( L_17 ) ;
return - 1 ;
}
return 0 ;
default:
F_13 ( L_18 , V_67 -> V_73 ) ;
return 0 ;
}
return 0 ;
}
static int F_19 ( struct V_25 * V_26 , struct V_66 * V_67 )
{
V_50 V_68 ;
int V_98 ;
V_68 = F_15 ( V_67 ) ;
switch ( V_67 -> V_73 ) {
case V_99 :
V_98 = F_6 ( V_26 , V_68 & 0xff ) ;
break;
case V_100 :
V_98 = F_9 ( V_26 ) ;
break;
case V_101 :
V_98 = F_12 ( V_26 , V_102 , V_68 ) ;
break;
case V_103 :
V_98 = F_12 ( V_26 , V_104 , V_68 ) ;
break;
case V_105 :
V_98 = F_12 ( V_26 , V_106 , V_68 ) ;
break;
default:
F_5 ( V_26 -> V_3 , L_19 , V_67 -> V_73 ) ;
V_98 = 0 ;
}
memset ( & V_26 -> V_29 , 0 , sizeof( V_26 -> V_29 ) ) ;
return V_98 ;
}
static int F_20 ( struct V_25 * V_26 , struct V_66 * V_67 )
{
F_13 ( L_20 , V_67 -> V_73 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_7 )
{
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_7 -> V_18 ; V_38 ++ )
F_8 ( V_7 -> V_17 [ V_38 ] ) ;
F_8 ( V_7 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned V_45 , V_58 ;
for ( V_45 = 0 ; V_45 < V_107 ; V_45 ++ ) {
struct V_5 * V_6 = V_3 -> V_6 + V_45 ;
for ( V_58 = 0 ; V_58 < 256 ; V_58 ++ ) {
struct V_1 * V_7 = V_6 -> V_8 [ V_58 ] ;
if ( V_7 )
F_21 ( V_7 ) ;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_23 ( & V_6 -> V_13 ) ;
}
F_8 ( V_3 -> V_108 ) ;
V_3 -> V_108 = NULL ;
V_3 -> V_109 = 0 ;
F_8 ( V_3 -> V_28 ) ;
V_3 -> V_28 = NULL ;
V_3 -> V_33 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_37 = 0 ;
V_3 -> V_110 &= ~ V_111 ;
}
static void F_24 ( struct V_3 * V_112 )
{
struct V_2 * V_59 = F_25 ( V_112 , struct V_2 , V_112 ) ;
F_22 ( V_59 ) ;
F_8 ( V_59 -> V_113 ) ;
F_8 ( V_59 ) ;
}
static V_69 * F_26 ( T_2 * V_114 , T_2 * V_115 , struct V_66 * V_67 )
{
V_69 V_116 ;
if ( ( V_115 - V_114 ) <= 0 )
return NULL ;
V_116 = * V_114 ++ ;
V_67 -> type = ( V_116 >> 2 ) & 3 ;
V_67 -> V_73 = ( V_116 >> 4 ) & 15 ;
if ( V_67 -> V_73 == V_117 ) {
V_67 -> V_118 = V_119 ;
if ( ( V_115 - V_114 ) < 2 )
return NULL ;
V_67 -> V_11 = * V_114 ++ ;
V_67 -> V_73 = * V_114 ++ ;
if ( ( V_115 - V_114 ) < V_67 -> V_11 )
return NULL ;
V_67 -> V_68 . V_120 = V_114 ;
V_114 += V_67 -> V_11 ;
return V_114 ;
}
V_67 -> V_118 = V_121 ;
V_67 -> V_11 = V_116 & 3 ;
switch ( V_67 -> V_11 ) {
case 0 :
return V_114 ;
case 1 :
if ( ( V_115 - V_114 ) < 1 )
return NULL ;
V_67 -> V_68 . V_69 = * V_114 ++ ;
return V_114 ;
case 2 :
if ( ( V_115 - V_114 ) < 2 )
return NULL ;
V_67 -> V_68 . V_70 = F_27 ( V_114 ) ;
V_114 = ( T_2 * ) ( ( V_122 * ) V_114 + 1 ) ;
return V_114 ;
case 3 :
V_67 -> V_11 ++ ;
if ( ( V_115 - V_114 ) < 4 )
return NULL ;
V_67 -> V_68 . T_1 = F_28 ( V_114 ) ;
V_114 = ( T_2 * ) ( ( V_123 * ) V_114 + 1 ) ;
return V_114 ;
}
return NULL ;
}
static void F_29 ( struct V_2 * V_59 , T_1 V_22 )
{
if ( V_22 == V_124 )
V_59 -> V_125 = V_126 ;
}
static int F_30 ( struct V_2 * V_59 )
{
unsigned int V_127 = 0 , V_128 = 0 ;
T_2 * V_114 = V_59 -> V_113 ;
T_2 * V_115 = V_114 + V_59 -> V_129 ;
unsigned int V_130 , V_131 = 0 , V_132 = 0 ;
struct V_66 V_67 ;
V_59 -> V_125 = V_133 ;
while ( ( V_114 = F_26 ( V_114 , V_115 , & V_67 ) ) != NULL ) {
if ( V_67 . V_118 != V_121 )
return - V_134 ;
if ( V_67 . type == V_135 ) {
if ( V_67 . V_73 == V_80 )
V_127 = F_15 ( & V_67 ) << 16 ;
} else if ( V_67 . type == V_136 ) {
if ( V_128 > 1 )
break;
V_130 = F_15 ( & V_67 ) ;
if ( V_67 . V_11 <= 2 )
V_130 += V_127 ;
switch ( V_67 . V_73 ) {
case V_91 :
V_128 += ! ! V_130 ;
break;
case V_94 :
F_29 ( V_59 , V_130 ) ;
break;
case V_95 :
V_131 = V_130 ;
break;
case V_97 :
V_132 = V_130 ;
for ( V_130 = V_131 ; V_130 <= V_132 ; V_130 ++ )
F_29 ( V_59 , V_130 ) ;
break;
}
}
}
return 0 ;
}
int F_31 ( struct V_2 * V_59 , T_2 * V_114 , unsigned V_11 )
{
V_59 -> V_113 = F_32 ( V_114 , V_11 , V_9 ) ;
if ( ! V_59 -> V_113 )
return - V_137 ;
V_59 -> V_129 = V_11 ;
return 0 ;
}
int F_33 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
struct V_66 V_67 ;
unsigned int V_11 ;
T_2 * V_114 ;
T_2 * V_115 ;
int V_98 ;
static int (* F_34 [])( struct V_25 * V_26 ,
struct V_66 * V_67 ) = {
F_19 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static V_24 F_35 ( V_50 V_23 , unsigned V_38 )
{
switch ( V_38 ) {
case 8 : return ( ( V_138 ) V_23 ) ;
case 16 : return ( ( V_139 ) V_23 ) ;
case 32 : return ( ( V_140 ) V_23 ) ;
}
return V_23 & ( 1 << ( V_38 - 1 ) ) ? V_23 | ( - 1 << V_38 ) : V_23 ;
}
static T_1 F_36 ( V_140 V_23 , unsigned V_38 )
{
V_24 V_141 = V_23 >> ( V_38 - 1 ) ;
if ( V_141 && V_141 != - 1 )
return V_23 < 0 ? 1 << ( V_38 - 1 ) : ( 1 << ( V_38 - 1 ) ) - 1 ;
return V_23 & ( ( 1 << V_38 ) - 1 ) ;
}
static V_50 F_37 ( const struct V_2 * V_59 , T_2 * V_7 ,
unsigned V_44 , unsigned V_38 )
{
T_3 V_142 ;
if ( V_38 > 32 )
F_38 ( V_59 , L_21 ,
V_38 , V_143 -> V_144 ) ;
V_7 += V_44 >> 3 ;
V_44 &= 7 ;
V_142 = F_39 ( V_7 ) ;
V_142 = ( V_142 >> V_44 ) & ( ( 1ULL << V_38 ) - 1 ) ;
return ( T_1 ) V_142 ;
}
static void F_40 ( const struct V_2 * V_59 , T_2 * V_7 ,
unsigned V_44 , unsigned V_38 , V_50 V_23 )
{
T_3 V_142 ;
T_3 V_145 = ( 1ULL << V_38 ) - 1 ;
if ( V_38 > 32 )
F_38 ( V_59 , L_22 ,
V_146 , V_38 , V_143 -> V_144 ) ;
if ( V_23 > V_145 )
F_38 ( V_59 , L_23 ,
V_146 , V_23 , V_143 -> V_144 ) ;
F_41 ( V_23 > V_145 ) ;
V_23 &= V_145 ;
V_7 += V_44 >> 3 ;
V_44 &= 7 ;
V_142 = F_39 ( V_7 ) ;
V_142 &= ~ ( V_145 << V_44 ) ;
V_142 |= ( ( T_3 ) V_23 ) << V_44 ;
F_42 ( V_142 , V_7 ) ;
}
static int F_43 ( V_140 * V_147 , V_140 V_23 , unsigned V_38 )
{
while ( V_38 -- ) {
if ( * V_147 ++ == V_23 )
return 0 ;
}
return - 1 ;
}
static int F_44 ( struct V_2 * V_59 , struct V_1 * V_7 )
{
const struct V_148 * V_4 = V_59 -> V_149 -> V_150 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_42 != V_151 ; V_4 ++ )
if ( V_4 -> V_42 == V_152 ||
V_4 -> V_42 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_45 ( struct V_2 * V_59 , struct V_20 * V_22 )
{
const struct V_153 * V_4 = V_59 -> V_149 -> V_154 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_155 != V_152 - 1 ; V_4 ++ )
if ( ( V_4 -> V_156 == V_152 ||
V_4 -> V_156 == V_22 -> V_59 ) &&
( V_4 -> V_155 == V_152 ||
V_4 -> V_155 == V_22 -> type ) &&
( V_4 -> V_157 == V_152 ||
V_4 -> V_157 == V_22 -> V_158 ) )
return 1 ;
return 0 ;
}
static void F_46 ( struct V_2 * V_59 , struct V_14 * V_17 ,
struct V_20 * V_22 , V_140 V_23 , int V_159 )
{
struct V_160 * V_161 = V_59 -> V_149 ;
int V_98 ;
F_47 ( V_59 , V_22 , V_23 ) ;
if ( V_161 && V_161 -> V_162 && F_45 ( V_59 , V_22 ) ) {
V_98 = V_161 -> V_162 ( V_59 , V_17 , V_22 , V_23 ) ;
if ( V_98 != 0 ) {
if ( V_98 < 0 )
F_5 ( V_59 , L_24 ,
V_161 -> V_163 , V_98 ) ;
return;
}
}
if ( V_59 -> V_164 & V_165 )
F_48 ( V_59 , V_17 , V_22 , V_23 ) ;
if ( V_59 -> V_164 & V_166 && V_159 && V_59 -> V_167 )
V_59 -> V_167 ( V_59 , V_17 , V_22 , V_23 ) ;
}
static void F_49 ( struct V_2 * V_59 , struct V_14 * V_17 ,
T_2 * V_68 , int V_159 )
{
unsigned V_38 ;
unsigned V_168 = V_17 -> V_52 ;
unsigned V_44 = V_17 -> V_61 ;
unsigned V_11 = V_17 -> V_51 ;
V_140 V_169 = V_17 -> V_48 ;
V_140 V_170 = V_17 -> V_49 ;
V_140 * V_23 ;
V_23 = F_7 ( sizeof( V_140 ) * V_168 , V_171 ) ;
if ( ! V_23 )
return;
for ( V_38 = 0 ; V_38 < V_168 ; V_38 ++ ) {
V_23 [ V_38 ] = V_169 < 0 ?
F_35 ( F_37 ( V_59 , V_68 , V_44 + V_38 * V_11 , V_11 ) ,
V_11 ) :
F_37 ( V_59 , V_68 , V_44 + V_38 * V_11 , V_11 ) ;
if ( ! ( V_17 -> V_43 & V_172 ) &&
V_23 [ V_38 ] >= V_169 && V_23 [ V_38 ] <= V_170 &&
V_17 -> V_22 [ V_23 [ V_38 ] - V_169 ] . V_59 == V_173 + 1 )
goto exit;
}
for ( V_38 = 0 ; V_38 < V_168 ; V_38 ++ ) {
if ( V_172 & V_17 -> V_43 ) {
F_46 ( V_59 , V_17 , & V_17 -> V_22 [ V_38 ] , V_23 [ V_38 ] , V_159 ) ;
continue;
}
if ( V_17 -> V_23 [ V_38 ] >= V_169 && V_17 -> V_23 [ V_38 ] <= V_170
&& V_17 -> V_22 [ V_17 -> V_23 [ V_38 ] - V_169 ] . V_59
&& F_43 ( V_23 , V_17 -> V_23 [ V_38 ] , V_168 ) )
F_46 ( V_59 , V_17 , & V_17 -> V_22 [ V_17 -> V_23 [ V_38 ] - V_169 ] , 0 , V_159 ) ;
if ( V_23 [ V_38 ] >= V_169 && V_23 [ V_38 ] <= V_170
&& V_17 -> V_22 [ V_23 [ V_38 ] - V_169 ] . V_59
&& F_43 ( V_17 -> V_23 , V_23 [ V_38 ] , V_168 ) )
F_46 ( V_59 , V_17 , & V_17 -> V_22 [ V_23 [ V_38 ] - V_169 ] , 1 , V_159 ) ;
}
memcpy ( V_17 -> V_23 , V_23 , V_168 * sizeof( V_140 ) ) ;
exit:
F_8 ( V_23 ) ;
}
static void F_50 ( const struct V_2 * V_59 ,
struct V_14 * V_17 , T_2 * V_68 )
{
unsigned V_168 = V_17 -> V_52 ;
unsigned V_44 = V_17 -> V_61 ;
unsigned V_11 = V_17 -> V_51 ;
unsigned V_38 ;
for ( V_38 = 0 ; V_38 < V_168 ; V_38 ++ ) {
if ( V_17 -> V_48 < 0 )
F_40 ( V_59 , V_68 , V_44 + V_38 * V_11 , V_11 ,
F_36 ( V_17 -> V_23 [ V_38 ] , V_11 ) ) ;
else
F_40 ( V_59 , V_68 , V_44 + V_38 * V_11 , V_11 ,
V_17 -> V_23 [ V_38 ] ) ;
}
}
void F_51 ( struct V_1 * V_7 , T_2 * V_68 )
{
unsigned V_38 ;
if ( V_7 -> V_4 > 0 )
* V_68 ++ = V_7 -> V_4 ;
memset ( V_68 , 0 , ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ) ;
for ( V_38 = 0 ; V_38 < V_7 -> V_18 ; V_38 ++ )
F_50 ( V_7 -> V_3 , V_7 -> V_17 [ V_38 ] , V_68 ) ;
}
int F_52 ( struct V_14 * V_17 , unsigned V_44 , V_140 V_23 )
{
unsigned V_11 = V_17 -> V_51 ;
F_47 ( V_17 -> V_7 -> V_3 , V_17 -> V_22 + V_44 , V_23 ) ;
if ( V_44 >= V_17 -> V_52 ) {
F_5 ( V_17 -> V_7 -> V_3 , L_25 ,
V_44 , V_17 -> V_52 ) ;
return - 1 ;
}
if ( V_17 -> V_48 < 0 ) {
if ( V_23 != F_35 ( F_36 ( V_23 , V_11 ) , V_11 ) ) {
F_5 ( V_17 -> V_7 -> V_3 , L_26 , V_23 ) ;
return - 1 ;
}
}
V_17 -> V_23 [ V_44 ] = V_23 ;
return 0 ;
}
static struct V_1 * F_53 ( struct V_5 * V_6 ,
const V_69 * V_68 )
{
struct V_1 * V_7 ;
unsigned int V_38 = 0 ;
if ( V_6 -> V_10 )
V_38 = * V_68 ;
V_7 = V_6 -> V_8 [ V_38 ] ;
if ( V_7 == NULL )
F_13 ( L_27 , V_38 ) ;
return V_7 ;
}
int F_54 ( struct V_2 * V_59 , int type , V_69 * V_68 , int V_11 ,
int V_159 )
{
struct V_5 * V_6 = V_59 -> V_6 + type ;
struct V_1 * V_7 ;
unsigned int V_141 ;
int V_109 , V_174 = V_11 ;
V_69 * V_175 = V_68 ;
int V_98 = 0 ;
V_7 = F_53 ( V_6 , V_68 ) ;
if ( ! V_7 )
goto V_176;
if ( V_6 -> V_10 ) {
V_175 ++ ;
V_174 -- ;
}
V_109 = ( ( V_7 -> V_11 - 1 ) >> 3 ) + 1 ;
if ( V_109 > V_177 )
V_109 = V_177 ;
if ( V_174 < V_109 ) {
F_13 ( L_28 , V_7 -> V_4 ,
V_174 , V_109 ) ;
memset ( V_175 + V_174 , 0 , V_109 - V_174 ) ;
}
if ( ( V_59 -> V_164 & V_166 ) && V_59 -> V_178 )
V_59 -> V_178 ( V_59 , V_7 ) ;
if ( V_59 -> V_164 & V_179 ) {
V_98 = F_55 ( V_59 , V_68 , V_11 ) ;
if ( V_98 )
goto V_176;
}
for ( V_141 = 0 ; V_141 < V_7 -> V_18 ; V_141 ++ )
F_49 ( V_59 , V_7 -> V_17 [ V_141 ] , V_175 , V_159 ) ;
if ( V_59 -> V_164 & V_165 )
F_56 ( V_59 , V_7 ) ;
V_176:
return V_98 ;
}
int F_57 ( struct V_2 * V_59 , int type , V_69 * V_68 , int V_11 , int V_159 )
{
struct V_5 * V_6 ;
struct V_160 * V_161 ;
struct V_1 * V_7 ;
char * V_180 ;
unsigned int V_45 ;
int V_98 = 0 ;
if ( ! V_59 )
return - V_181 ;
if ( F_58 ( & V_59 -> V_182 ) )
return - V_183 ;
if ( ! V_59 -> V_149 ) {
V_98 = - V_181 ;
goto V_184;
}
V_6 = V_59 -> V_6 + type ;
V_161 = V_59 -> V_149 ;
if ( ! V_11 ) {
F_13 ( L_29 ) ;
V_98 = - 1 ;
goto V_184;
}
V_180 = F_7 ( sizeof( char ) * V_185 , V_171 ) ;
if ( ! V_180 )
goto V_186;
snprintf ( V_180 , V_185 - 1 ,
L_30 , V_11 , V_6 -> V_10 ? L_31 : L_32 ) ;
F_59 ( V_59 , V_180 ) ;
for ( V_45 = 0 ; V_45 < V_11 ; V_45 ++ ) {
snprintf ( V_180 , V_185 - 1 ,
L_33 , V_68 [ V_45 ] ) ;
F_59 ( V_59 , V_180 ) ;
}
F_59 ( V_59 , L_34 ) ;
F_8 ( V_180 ) ;
V_186:
V_7 = F_53 ( V_6 , V_68 ) ;
if ( ! V_7 ) {
V_98 = - 1 ;
goto V_184;
}
if ( V_161 && V_161 -> V_187 && F_44 ( V_59 , V_7 ) ) {
V_98 = V_161 -> V_187 ( V_59 , V_7 , V_68 , V_11 ) ;
if ( V_98 != 0 ) {
V_98 = V_98 < 0 ? V_98 : 0 ;
goto V_184;
}
}
V_98 = F_54 ( V_59 , type , V_68 , V_11 , V_159 ) ;
V_184:
F_60 ( & V_59 -> V_182 ) ;
return V_98 ;
}
static bool F_61 ( struct V_2 * V_188 ,
const struct V_189 * V_4 )
{
return ( V_4 -> V_190 == V_191 || V_4 -> V_190 == V_188 -> V_190 ) &&
( V_4 -> V_125 == V_192 || V_4 -> V_125 == V_188 -> V_125 ) &&
( V_4 -> V_193 == V_152 || V_4 -> V_193 == V_188 -> V_193 ) &&
( V_4 -> V_194 == V_152 || V_4 -> V_194 == V_188 -> V_194 ) ;
}
const struct V_189 * F_62 ( struct V_2 * V_188 ,
const struct V_189 * V_4 )
{
for (; V_4 -> V_190 ; V_4 ++ )
if ( F_61 ( V_188 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_63 ( struct V_2 * V_188 )
{
return ! ! F_62 ( V_188 , V_195 ) ;
}
static T_4
F_64 ( struct V_196 * V_197 , struct V_198 * V_199 ,
struct V_200 * V_201 ,
char * V_180 , T_5 V_202 , T_6 V_168 )
{
struct V_3 * V_112 = F_25 ( V_199 , struct V_3 , V_199 ) ;
struct V_2 * V_188 = F_25 ( V_112 , struct V_2 , V_112 ) ;
if ( V_202 >= V_188 -> V_109 )
return 0 ;
if ( V_202 + V_168 > V_188 -> V_109 )
V_168 = V_188 -> V_109 - V_202 ;
memcpy ( V_180 , V_188 -> V_108 + V_202 , V_168 ) ;
return V_168 ;
}
int F_65 ( struct V_2 * V_188 , unsigned int V_203 )
{
static const char * V_204 [] = { L_35 , L_36 , L_37 , L_35 ,
L_38 , L_39 , L_40 , L_41 ,
L_42
} ;
const char * type , * V_190 ;
char V_180 [ 64 ] ;
unsigned int V_45 ;
int V_205 ;
int V_98 ;
if ( V_188 -> V_206 & V_207 )
V_203 |= ( V_208 | V_209 ) ;
if ( V_188 -> V_206 & V_210 )
V_203 |= V_211 ;
if ( V_188 -> V_190 != V_212 )
V_203 &= ~ V_209 ;
if ( F_63 ( V_188 ) )
V_203 |= V_208 ;
if ( ( V_203 & V_213 ) && ! F_66 ( V_188 ,
V_203 & V_211 ) )
V_188 -> V_164 |= V_165 ;
if ( ( V_203 & V_209 ) && V_188 -> V_214 &&
! V_188 -> V_214 ( V_188 ,
V_203 & V_208 ) )
V_188 -> V_164 |= V_166 ;
if ( ( V_203 & V_215 ) && ! F_67 ( V_188 ) )
V_188 -> V_164 |= V_179 ;
if ( ! V_188 -> V_164 ) {
F_5 ( V_188 , L_43 ) ;
return - V_181 ;
}
if ( ( V_188 -> V_164 & V_165 ) &&
( V_203 & V_216 ) && V_188 -> V_217 )
V_188 -> V_217 ( V_188 ) ;
V_205 = 0 ;
if ( V_188 -> V_164 & V_165 )
V_205 += sprintf ( V_180 + V_205 , L_44 ) ;
if ( V_188 -> V_164 & V_166 )
V_205 += sprintf ( V_180 + V_205 , L_45 , V_205 ? L_46 : L_31 ,
V_188 -> V_218 ) ;
if ( V_188 -> V_164 & V_179 )
V_205 += sprintf ( V_180 + V_205 , L_47 , V_205 ? L_46 : L_31 ,
( (struct V_219 * ) V_188 -> V_219 ) -> V_218 ) ;
type = L_35 ;
for ( V_45 = 0 ; V_45 < V_188 -> V_32 ; V_45 ++ ) {
struct V_27 * V_220 = & V_188 -> V_28 [ V_45 ] ;
if ( V_220 -> type == V_36 &&
( V_220 -> V_22 & V_221 ) == V_222 &&
( V_220 -> V_22 & 0xffff ) < F_68 ( V_204 ) ) {
type = V_204 [ V_220 -> V_22 & 0xffff ] ;
break;
}
}
switch ( V_188 -> V_190 ) {
case V_212 :
V_190 = L_48 ;
break;
case V_223 :
V_190 = L_49 ;
break;
default:
V_190 = L_50 ;
}
V_98 = F_69 ( & V_188 -> V_112 , & V_224 ) ;
if ( V_98 )
F_38 ( V_188 ,
L_51 , V_98 ) ;
F_70 ( V_188 , L_52 ,
V_180 , V_190 , V_188 -> V_225 >> 8 , V_188 -> V_225 & 0xff ,
type , V_188 -> V_163 , V_188 -> V_226 ) ;
return 0 ;
}
void F_71 ( struct V_2 * V_188 )
{
F_72 ( & V_188 -> V_112 , & V_224 ) ;
if ( V_188 -> V_164 & V_165 )
F_73 ( V_188 ) ;
if ( V_188 -> V_164 & V_166 )
V_188 -> V_227 ( V_188 ) ;
if ( V_188 -> V_164 & V_179 )
F_74 ( V_188 ) ;
}
static T_4 F_75 ( struct V_228 * V_229 , const char * V_180 ,
T_6 V_168 )
{
struct V_160 * V_161 = F_25 ( V_229 , struct V_160 , V_149 ) ;
struct V_230 * V_231 ;
V_50 V_190 , V_193 , V_194 ;
unsigned long V_232 = 0 ;
int V_98 ;
V_98 = sscanf ( V_180 , L_53 ,
& V_190 , & V_193 , & V_194 , & V_232 ) ;
if ( V_98 < 3 )
return - V_134 ;
V_231 = F_2 ( sizeof( * V_231 ) , V_9 ) ;
if ( ! V_231 )
return - V_137 ;
V_231 -> V_4 . V_190 = V_190 ;
V_231 -> V_4 . V_125 = V_192 ;
V_231 -> V_4 . V_193 = V_193 ;
V_231 -> V_4 . V_194 = V_194 ;
V_231 -> V_4 . V_232 = V_232 ;
F_76 ( & V_161 -> V_233 ) ;
F_3 ( & V_231 -> V_12 , & V_161 -> V_234 ) ;
F_77 ( & V_161 -> V_233 ) ;
V_98 = F_78 ( & V_161 -> V_149 ) ;
return V_98 ? : V_168 ;
}
static void F_79 ( struct V_160 * V_161 )
{
struct V_230 * V_231 , * V_38 ;
F_76 ( & V_161 -> V_233 ) ;
F_80 (dynid, n, &hdrv->dyn_list, list) {
F_81 ( & V_231 -> V_12 ) ;
F_8 ( V_231 ) ;
}
F_77 ( & V_161 -> V_233 ) ;
}
static const struct V_189 * F_82 ( struct V_2 * V_188 ,
struct V_160 * V_161 )
{
struct V_230 * V_231 ;
F_76 ( & V_161 -> V_233 ) ;
F_83 (dynid, &hdrv->dyn_list, list) {
if ( F_61 ( V_188 , & V_231 -> V_4 ) ) {
F_77 ( & V_161 -> V_233 ) ;
return & V_231 -> V_4 ;
}
}
F_77 ( & V_161 -> V_233 ) ;
return F_62 ( V_188 , V_161 -> V_235 ) ;
}
static int F_84 ( struct V_3 * V_112 , struct V_228 * V_229 )
{
struct V_160 * V_161 = F_25 ( V_229 , struct V_160 , V_149 ) ;
struct V_2 * V_188 = F_25 ( V_112 , struct V_2 , V_112 ) ;
return F_82 ( V_188 , V_161 ) != NULL ;
}
static int F_85 ( struct V_3 * V_112 )
{
struct V_160 * V_161 = F_25 ( V_112 -> V_149 ,
struct V_160 , V_149 ) ;
struct V_2 * V_188 = F_25 ( V_112 , struct V_2 , V_112 ) ;
const struct V_189 * V_4 ;
int V_98 = 0 ;
if ( F_86 ( & V_188 -> V_182 ) )
return - V_236 ;
if ( ! V_188 -> V_149 ) {
V_4 = F_82 ( V_188 , V_161 ) ;
if ( V_4 == NULL ) {
V_98 = - V_181 ;
goto V_184;
}
V_188 -> V_149 = V_161 ;
if ( V_161 -> V_237 ) {
V_98 = V_161 -> V_237 ( V_188 , V_4 ) ;
} else {
V_98 = F_33 ( V_188 ) ;
if ( ! V_98 )
V_98 = F_87 ( V_188 , V_238 ) ;
}
if ( V_98 ) {
F_22 ( V_188 ) ;
V_188 -> V_149 = NULL ;
}
}
V_184:
F_60 ( & V_188 -> V_182 ) ;
return V_98 ;
}
static int F_88 ( struct V_3 * V_112 )
{
struct V_2 * V_188 = F_25 ( V_112 , struct V_2 , V_112 ) ;
struct V_160 * V_161 ;
if ( F_86 ( & V_188 -> V_182 ) )
return - V_236 ;
V_161 = V_188 -> V_149 ;
if ( V_161 ) {
if ( V_161 -> remove )
V_161 -> remove ( V_188 ) ;
else
F_89 ( V_188 ) ;
F_22 ( V_188 ) ;
V_188 -> V_149 = NULL ;
}
F_60 ( & V_188 -> V_182 ) ;
return 0 ;
}
static T_4 F_90 ( struct V_3 * V_112 , struct V_239 * V_141 ,
char * V_180 )
{
struct V_2 * V_188 = F_25 ( V_112 , struct V_2 , V_112 ) ;
int V_205 ;
V_205 = snprintf ( V_180 , V_240 , L_54 ,
V_188 -> V_190 , V_188 -> V_125 , V_188 -> V_193 , V_188 -> V_194 ) ;
return ( V_205 >= V_240 ) ? ( V_240 - 1 ) : V_205 ;
}
static int F_91 ( struct V_3 * V_112 , struct V_241 * V_242 )
{
struct V_2 * V_188 = F_25 ( V_112 , struct V_2 , V_112 ) ;
if ( F_92 ( V_242 , L_55 ,
V_188 -> V_190 , V_188 -> V_193 , V_188 -> V_194 ) )
return - V_137 ;
if ( F_92 ( V_242 , L_56 , V_188 -> V_163 ) )
return - V_137 ;
if ( F_92 ( V_242 , L_57 , V_188 -> V_226 ) )
return - V_137 ;
if ( F_92 ( V_242 , L_58 , V_188 -> V_243 ) )
return - V_137 ;
if ( F_92 ( V_242 , L_59 ,
V_188 -> V_190 , V_188 -> V_125 , V_188 -> V_193 , V_188 -> V_194 ) )
return - V_137 ;
return 0 ;
}
static bool F_93 ( struct V_2 * V_188 )
{
switch ( V_188 -> V_193 ) {
case V_244 :
if ( V_188 -> V_194 >= V_245 &&
V_188 -> V_194 <= V_246 )
return true ;
break;
case V_247 :
if ( V_188 -> V_194 >= V_248 &&
V_188 -> V_194 <= V_249 )
return true ;
if ( V_188 -> V_194 == V_250 &&
! strcmp ( V_188 -> V_163 , L_60 ) )
return true ;
break;
case V_251 :
if ( V_188 -> V_194 >= V_252 &&
V_188 -> V_194 <= V_253 )
return true ;
break;
case V_254 :
if ( V_188 -> V_194 >= V_255 &&
V_188 -> V_194 <= V_256 )
return true ;
break;
case V_257 :
if ( V_188 -> V_194 == V_258 &&
V_188 -> type == V_259 )
return true ;
break;
}
if ( V_188 -> type == V_260 &&
F_62 ( V_188 , V_261 ) )
return true ;
return ! ! F_62 ( V_188 , V_262 ) ;
}
int F_94 ( struct V_2 * V_188 )
{
static T_7 V_4 = F_95 ( 0 ) ;
int V_98 ;
if ( F_41 ( V_188 -> V_110 & V_263 ) )
return - V_183 ;
if ( ! ( V_188 -> V_206 & V_264 )
&& ( F_93 ( V_188 ) || ( V_188 -> V_206 & V_265 ) ) )
return - V_181 ;
V_98 = V_188 -> V_266 -> V_267 ( V_188 ) ;
if ( V_98 )
return V_98 ;
if ( ! V_188 -> V_113 )
return - V_181 ;
if ( V_268 ||
! F_62 ( V_188 , V_269 ) ) {
V_98 = F_30 ( V_188 ) ;
if ( V_98 )
F_38 ( V_188 , L_61 , V_98 ) ;
}
F_96 ( & V_188 -> V_112 , L_62 , V_188 -> V_190 ,
V_188 -> V_193 , V_188 -> V_194 , F_97 ( & V_4 ) ) ;
F_98 ( V_188 , F_99 ( & V_188 -> V_112 ) ) ;
V_98 = F_100 ( & V_188 -> V_112 ) ;
if ( ! V_98 )
V_188 -> V_110 |= V_263 ;
else
F_101 ( V_188 ) ;
return V_98 ;
}
struct V_2 * F_102 ( void )
{
struct V_2 * V_188 ;
int V_98 = - V_137 ;
V_188 = F_2 ( sizeof( * V_188 ) , V_9 ) ;
if ( V_188 == NULL )
return F_103 ( V_98 ) ;
F_104 ( & V_188 -> V_112 ) ;
V_188 -> V_112 . V_270 = F_24 ;
V_188 -> V_112 . V_190 = & V_271 ;
F_22 ( V_188 ) ;
F_105 ( & V_188 -> V_272 ) ;
F_23 ( & V_188 -> V_273 ) ;
F_106 ( & V_188 -> V_182 , 1 ) ;
return V_188 ;
}
static void F_107 ( struct V_2 * V_188 )
{
if ( V_188 -> V_110 & V_263 ) {
F_108 ( & V_188 -> V_112 ) ;
F_101 ( V_188 ) ;
V_188 -> V_110 &= ~ V_263 ;
}
F_8 ( V_188 -> V_113 ) ;
V_188 -> V_113 = NULL ;
V_188 -> V_129 = 0 ;
}
void F_109 ( struct V_2 * V_188 )
{
F_107 ( V_188 ) ;
F_110 ( & V_188 -> V_112 ) ;
}
int F_111 ( struct V_160 * V_161 , struct V_274 * V_275 ,
const char * V_276 )
{
int V_98 ;
V_161 -> V_149 . V_163 = V_161 -> V_163 ;
V_161 -> V_149 . V_190 = & V_271 ;
V_161 -> V_149 . V_275 = V_275 ;
V_161 -> V_149 . V_276 = V_276 ;
F_23 ( & V_161 -> V_234 ) ;
F_112 ( & V_161 -> V_233 ) ;
V_98 = F_113 ( & V_161 -> V_149 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_114 ( & V_161 -> V_149 , & V_277 ) ;
if ( V_98 )
F_115 ( & V_161 -> V_149 ) ;
return V_98 ;
}
void F_116 ( struct V_160 * V_161 )
{
F_117 ( & V_161 -> V_149 , & V_277 ) ;
F_115 ( & V_161 -> V_149 ) ;
F_79 ( V_161 ) ;
}
int F_118 ( struct V_2 * V_59 )
{
struct V_278 * V_279 ;
int V_45 ;
if ( ! ( V_59 -> V_164 & V_165 ) )
return 0 ;
F_83 (hidinput, &hid->inputs, list) {
for ( V_45 = 0 ; V_45 < F_119 ( V_280 ) ; V_45 ++ )
if ( V_279 -> V_281 -> V_282 [ V_45 ] )
return 1 ;
}
return 0 ;
}
static int T_8 F_120 ( void )
{
int V_98 ;
if ( V_283 )
F_121 ( L_63
L_64 ) ;
V_98 = F_122 ( & V_271 ) ;
if ( V_98 ) {
F_123 ( L_65 ) ;
goto V_284;
}
V_98 = F_124 () ;
if ( V_98 )
goto V_285;
F_125 () ;
return 0 ;
V_285:
F_126 ( & V_271 ) ;
V_284:
return V_98 ;
}
static void T_9 F_127 ( void )
{
F_128 () ;
F_129 () ;
F_126 ( & V_271 ) ;
}
