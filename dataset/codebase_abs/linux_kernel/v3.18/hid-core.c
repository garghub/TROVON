struct V_1 * F_1 ( struct V_2 * V_3 , unsigned type , unsigned V_4 )
{
struct V_5 * V_6 = V_3 -> V_6 + type ;
struct V_1 * V_7 ;
if ( V_4 >= V_8 )
return NULL ;
if ( V_6 -> V_9 [ V_4 ] )
return V_6 -> V_9 [ V_4 ] ;
V_7 = F_2 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_7 )
return NULL ;
if ( V_4 != 0 )
V_6 -> V_11 = 1 ;
V_7 -> V_4 = V_4 ;
V_7 -> type = type ;
V_7 -> V_12 = 0 ;
V_7 -> V_3 = V_3 ;
V_6 -> V_9 [ V_4 ] = V_7 ;
F_3 ( & V_7 -> V_13 , & V_6 -> V_14 ) ;
return V_7 ;
}
static struct V_15 * F_4 ( struct V_1 * V_7 , unsigned V_16 , unsigned V_17 )
{
struct V_15 * V_18 ;
if ( V_7 -> V_19 == V_20 ) {
F_5 ( V_7 -> V_3 , L_1 ) ;
return NULL ;
}
V_18 = F_2 ( ( sizeof( struct V_15 ) +
V_16 * sizeof( struct V_21 ) +
V_17 * sizeof( unsigned ) ) , V_10 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_22 = V_7 -> V_19 ++ ;
V_7 -> V_18 [ V_18 -> V_22 ] = V_18 ;
V_18 -> V_23 = (struct V_21 * ) ( V_18 + 1 ) ;
V_18 -> V_24 = ( V_25 * ) ( V_18 -> V_23 + V_16 ) ;
V_18 -> V_7 = V_7 ;
return V_18 ;
}
static int F_6 ( struct V_26 * V_27 , unsigned type )
{
struct V_28 * V_29 ;
unsigned V_23 ;
V_23 = V_27 -> V_30 . V_23 [ 0 ] ;
if ( V_27 -> V_31 == V_32 ) {
F_5 ( V_27 -> V_3 , L_2 ) ;
return - V_33 ;
}
if ( V_27 -> V_3 -> V_34 == V_27 -> V_3 -> V_35 ) {
V_29 = F_7 ( sizeof( struct V_28 ) *
V_27 -> V_3 -> V_35 * 2 , V_10 ) ;
if ( V_29 == NULL ) {
F_5 ( V_27 -> V_3 , L_3 ) ;
return - V_36 ;
}
memcpy ( V_29 , V_27 -> V_3 -> V_29 ,
sizeof( struct V_28 ) *
V_27 -> V_3 -> V_35 ) ;
memset ( V_29 + V_27 -> V_3 -> V_35 , 0 ,
sizeof( struct V_28 ) *
V_27 -> V_3 -> V_35 ) ;
F_8 ( V_27 -> V_3 -> V_29 ) ;
V_27 -> V_3 -> V_29 = V_29 ;
V_27 -> V_3 -> V_35 *= 2 ;
}
V_27 -> V_37 [ V_27 -> V_31 ++ ] =
V_27 -> V_3 -> V_34 ;
V_29 = V_27 -> V_3 -> V_29 +
V_27 -> V_3 -> V_34 ++ ;
V_29 -> type = type ;
V_29 -> V_23 = V_23 ;
V_29 -> V_38 = V_27 -> V_31 - 1 ;
if ( type == V_39 )
V_27 -> V_3 -> V_40 ++ ;
return 0 ;
}
static int F_9 ( struct V_26 * V_27 )
{
if ( ! V_27 -> V_31 ) {
F_5 ( V_27 -> V_3 , L_4 ) ;
return - V_33 ;
}
V_27 -> V_31 -- ;
return 0 ;
}
static unsigned F_10 ( struct V_26 * V_27 , unsigned type )
{
struct V_28 * V_29 = V_27 -> V_3 -> V_29 ;
int V_41 ;
for ( V_41 = V_27 -> V_31 - 1 ; V_41 >= 0 ; V_41 -- ) {
unsigned V_22 = V_27 -> V_37 [ V_41 ] ;
if ( V_29 [ V_22 ] . type == type )
return V_29 [ V_22 ] . V_23 ;
}
return 0 ;
}
static int F_11 ( struct V_26 * V_27 , unsigned V_23 )
{
if ( V_27 -> V_30 . V_42 >= V_43 ) {
F_5 ( V_27 -> V_3 , L_5 ) ;
return - 1 ;
}
V_27 -> V_30 . V_23 [ V_27 -> V_30 . V_42 ] = V_23 ;
V_27 -> V_30 . V_44 [ V_27 -> V_30 . V_42 ] =
V_27 -> V_31 ?
V_27 -> V_37 [ V_27 -> V_31 - 1 ] : 0 ;
V_27 -> V_30 . V_42 ++ ;
return 0 ;
}
static int F_12 ( struct V_26 * V_27 , unsigned V_45 , unsigned V_46 )
{
struct V_1 * V_7 ;
struct V_15 * V_18 ;
unsigned V_16 ;
unsigned V_47 ;
unsigned V_48 ;
V_7 = F_1 ( V_27 -> V_3 , V_45 , V_27 -> V_49 . V_50 ) ;
if ( ! V_7 ) {
F_5 ( V_27 -> V_3 , L_6 ) ;
return - 1 ;
}
if ( ( V_27 -> V_49 . V_51 < 0 &&
V_27 -> V_49 . V_52 <
V_27 -> V_49 . V_51 ) ||
( V_27 -> V_49 . V_51 >= 0 &&
( V_53 ) V_27 -> V_49 . V_52 <
( V_53 ) V_27 -> V_49 . V_51 ) ) {
F_13 ( L_7 ,
V_27 -> V_49 . V_51 ,
V_27 -> V_49 . V_52 ) ;
return - 1 ;
}
V_47 = V_7 -> V_12 ;
V_7 -> V_12 += V_27 -> V_49 . V_54 * V_27 -> V_49 . V_55 ;
if ( ! V_27 -> V_30 . V_42 )
return 0 ;
V_16 = F_14 ( unsigned , V_27 -> V_30 . V_42 ,
V_27 -> V_49 . V_55 ) ;
V_18 = F_4 ( V_7 , V_16 , V_27 -> V_49 . V_55 ) ;
if ( ! V_18 )
return 0 ;
V_18 -> V_56 = F_10 ( V_27 , V_57 ) ;
V_18 -> V_58 = F_10 ( V_27 , V_59 ) ;
V_18 -> V_60 = F_10 ( V_27 , V_39 ) ;
for ( V_48 = 0 ; V_48 < V_16 ; V_48 ++ ) {
unsigned V_61 = V_48 ;
if ( V_48 >= V_27 -> V_30 . V_42 )
V_61 = V_27 -> V_30 . V_42 - 1 ;
V_18 -> V_23 [ V_48 ] . V_62 = V_27 -> V_30 . V_23 [ V_61 ] ;
V_18 -> V_23 [ V_48 ] . V_44 =
V_27 -> V_30 . V_44 [ V_61 ] ;
V_18 -> V_23 [ V_48 ] . V_42 = V_48 ;
}
V_18 -> V_63 = V_16 ;
V_18 -> V_46 = V_46 ;
V_18 -> V_64 = V_47 ;
V_18 -> V_45 = V_45 ;
V_18 -> V_54 = V_27 -> V_49 . V_54 ;
V_18 -> V_55 = V_27 -> V_49 . V_55 ;
V_18 -> V_51 = V_27 -> V_49 . V_51 ;
V_18 -> V_52 = V_27 -> V_49 . V_52 ;
V_18 -> V_65 = V_27 -> V_49 . V_65 ;
V_18 -> V_66 = V_27 -> V_49 . V_66 ;
V_18 -> V_67 = V_27 -> V_49 . V_67 ;
V_18 -> V_68 = V_27 -> V_49 . V_68 ;
return 0 ;
}
static T_1 F_15 ( struct V_69 * V_70 )
{
switch ( V_70 -> V_12 ) {
case 1 : return V_70 -> V_71 . V_72 ;
case 2 : return V_70 -> V_71 . V_73 ;
case 4 : return V_70 -> V_71 . T_1 ;
}
return 0 ;
}
static V_25 F_16 ( struct V_69 * V_70 )
{
switch ( V_70 -> V_12 ) {
case 1 : return V_70 -> V_71 . V_74 ;
case 2 : return V_70 -> V_71 . V_75 ;
case 4 : return V_70 -> V_71 . V_25 ;
}
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
T_2 V_76 ;
switch ( V_70 -> V_77 ) {
case V_78 :
if ( V_27 -> V_79 == V_80 ) {
F_5 ( V_27 -> V_3 , L_8 ) ;
return - 1 ;
}
memcpy ( V_27 -> V_81 + V_27 -> V_79 ++ ,
& V_27 -> V_49 , sizeof( struct V_82 ) ) ;
return 0 ;
case V_83 :
if ( ! V_27 -> V_79 ) {
F_5 ( V_27 -> V_3 , L_9 ) ;
return - 1 ;
}
memcpy ( & V_27 -> V_49 , V_27 -> V_81 +
-- V_27 -> V_79 , sizeof( struct V_82 ) ) ;
return 0 ;
case V_84 :
V_27 -> V_49 . V_85 = F_15 ( V_70 ) ;
return 0 ;
case V_86 :
V_27 -> V_49 . V_51 = F_16 ( V_70 ) ;
return 0 ;
case V_87 :
if ( V_27 -> V_49 . V_51 < 0 )
V_27 -> V_49 . V_52 = F_16 ( V_70 ) ;
else
V_27 -> V_49 . V_52 = F_15 ( V_70 ) ;
return 0 ;
case V_88 :
V_27 -> V_49 . V_65 = F_16 ( V_70 ) ;
return 0 ;
case V_89 :
if ( V_27 -> V_49 . V_65 < 0 )
V_27 -> V_49 . V_66 = F_16 ( V_70 ) ;
else
V_27 -> V_49 . V_66 = F_15 ( V_70 ) ;
return 0 ;
case V_90 :
V_76 = F_16 ( V_70 ) ;
if ( ! ( V_76 & 0xfffffff0 ) )
V_27 -> V_49 . V_67 = F_18 ( V_76 , 4 ) ;
else
V_27 -> V_49 . V_67 = V_76 ;
return 0 ;
case V_91 :
V_27 -> V_49 . V_68 = F_15 ( V_70 ) ;
return 0 ;
case V_92 :
V_27 -> V_49 . V_54 = F_15 ( V_70 ) ;
if ( V_27 -> V_49 . V_54 > 128 ) {
F_5 ( V_27 -> V_3 , L_10 ,
V_27 -> V_49 . V_54 ) ;
return - 1 ;
}
return 0 ;
case V_93 :
V_27 -> V_49 . V_55 = F_15 ( V_70 ) ;
if ( V_27 -> V_49 . V_55 > V_43 ) {
F_5 ( V_27 -> V_3 , L_11 ,
V_27 -> V_49 . V_55 ) ;
return - 1 ;
}
return 0 ;
case V_94 :
V_27 -> V_49 . V_50 = F_15 ( V_70 ) ;
if ( V_27 -> V_49 . V_50 == 0 ||
V_27 -> V_49 . V_50 >= V_8 ) {
F_5 ( V_27 -> V_3 , L_12 ,
V_27 -> V_49 . V_50 ) ;
return - 1 ;
}
return 0 ;
default:
F_5 ( V_27 -> V_3 , L_13 , V_70 -> V_77 ) ;
return - 1 ;
}
}
static int F_19 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
V_53 V_71 ;
unsigned V_41 ;
V_71 = F_15 ( V_70 ) ;
switch ( V_70 -> V_77 ) {
case V_95 :
if ( V_71 ) {
if ( V_27 -> V_30 . V_96 != 0 ) {
F_5 ( V_27 -> V_3 , L_14 ) ;
return - 1 ;
}
V_27 -> V_30 . V_96 ++ ;
V_27 -> V_30 . V_97 ++ ;
} else {
if ( V_27 -> V_30 . V_96 < 1 ) {
F_5 ( V_27 -> V_3 , L_15 ) ;
return - 1 ;
}
V_27 -> V_30 . V_96 -- ;
}
return 0 ;
case V_98 :
if ( V_27 -> V_30 . V_97 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_70 -> V_12 <= 2 )
V_71 = ( V_27 -> V_49 . V_85 << 16 ) + V_71 ;
return F_11 ( V_27 , V_71 ) ;
case V_99 :
if ( V_27 -> V_30 . V_97 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_70 -> V_12 <= 2 )
V_71 = ( V_27 -> V_49 . V_85 << 16 ) + V_71 ;
V_27 -> V_30 . V_100 = V_71 ;
return 0 ;
case V_101 :
if ( V_27 -> V_30 . V_97 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_70 -> V_12 <= 2 )
V_71 = ( V_27 -> V_49 . V_85 << 16 ) + V_71 ;
for ( V_41 = V_27 -> V_30 . V_100 ; V_41 <= V_71 ; V_41 ++ )
if ( F_11 ( V_27 , V_41 ) ) {
F_13 ( L_17 ) ;
return - 1 ;
}
return 0 ;
default:
F_13 ( L_18 , V_70 -> V_77 ) ;
return 0 ;
}
return 0 ;
}
static int F_20 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
V_53 V_71 ;
int V_102 ;
V_71 = F_15 ( V_70 ) ;
switch ( V_70 -> V_77 ) {
case V_103 :
V_102 = F_6 ( V_27 , V_71 & 0xff ) ;
break;
case V_104 :
V_102 = F_9 ( V_27 ) ;
break;
case V_105 :
V_102 = F_12 ( V_27 , V_106 , V_71 ) ;
break;
case V_107 :
V_102 = F_12 ( V_27 , V_108 , V_71 ) ;
break;
case V_109 :
V_102 = F_12 ( V_27 , V_110 , V_71 ) ;
break;
default:
F_5 ( V_27 -> V_3 , L_19 , V_70 -> V_77 ) ;
V_102 = 0 ;
}
memset ( & V_27 -> V_30 , 0 , sizeof( V_27 -> V_30 ) ) ;
return V_102 ;
}
static int F_21 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
F_13 ( L_20 , V_70 -> V_77 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_7 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_19 ; V_41 ++ )
F_8 ( V_7 -> V_18 [ V_41 ] ) ;
F_8 ( V_7 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
unsigned V_48 , V_61 ;
for ( V_48 = 0 ; V_48 < V_111 ; V_48 ++ ) {
struct V_5 * V_6 = V_3 -> V_6 + V_48 ;
for ( V_61 = 0 ; V_61 < V_8 ; V_61 ++ ) {
struct V_1 * V_7 = V_6 -> V_9 [ V_61 ] ;
if ( V_7 )
F_22 ( V_7 ) ;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_24 ( & V_6 -> V_14 ) ;
}
F_8 ( V_3 -> V_112 ) ;
V_3 -> V_112 = NULL ;
V_3 -> V_113 = 0 ;
F_8 ( V_3 -> V_29 ) ;
V_3 -> V_29 = NULL ;
V_3 -> V_35 = 0 ;
V_3 -> V_34 = 0 ;
V_3 -> V_40 = 0 ;
V_3 -> V_114 &= ~ V_115 ;
}
static void F_25 ( struct V_3 * V_116 )
{
struct V_2 * V_62 = F_26 ( V_116 , struct V_2 , V_116 ) ;
F_23 ( V_62 ) ;
F_8 ( V_62 -> V_117 ) ;
F_8 ( V_62 ) ;
}
static V_72 * F_27 ( T_3 * V_118 , T_3 * V_119 , struct V_69 * V_70 )
{
V_72 V_120 ;
if ( ( V_119 - V_118 ) <= 0 )
return NULL ;
V_120 = * V_118 ++ ;
V_70 -> type = ( V_120 >> 2 ) & 3 ;
V_70 -> V_77 = ( V_120 >> 4 ) & 15 ;
if ( V_70 -> V_77 == V_121 ) {
V_70 -> V_122 = V_123 ;
if ( ( V_119 - V_118 ) < 2 )
return NULL ;
V_70 -> V_12 = * V_118 ++ ;
V_70 -> V_77 = * V_118 ++ ;
if ( ( V_119 - V_118 ) < V_70 -> V_12 )
return NULL ;
V_70 -> V_71 . V_124 = V_118 ;
V_118 += V_70 -> V_12 ;
return V_118 ;
}
V_70 -> V_122 = V_125 ;
V_70 -> V_12 = V_120 & 3 ;
switch ( V_70 -> V_12 ) {
case 0 :
return V_118 ;
case 1 :
if ( ( V_119 - V_118 ) < 1 )
return NULL ;
V_70 -> V_71 . V_72 = * V_118 ++ ;
return V_118 ;
case 2 :
if ( ( V_119 - V_118 ) < 2 )
return NULL ;
V_70 -> V_71 . V_73 = F_28 ( V_118 ) ;
V_118 = ( T_3 * ) ( ( V_126 * ) V_118 + 1 ) ;
return V_118 ;
case 3 :
V_70 -> V_12 ++ ;
if ( ( V_119 - V_118 ) < 4 )
return NULL ;
V_70 -> V_71 . T_1 = F_29 ( V_118 ) ;
V_118 = ( T_3 * ) ( ( V_127 * ) V_118 + 1 ) ;
return V_118 ;
}
return NULL ;
}
static void F_30 ( struct V_26 * V_27 , T_1 V_23 )
{
struct V_2 * V_62 = V_27 -> V_3 ;
if ( V_23 == V_128 )
V_62 -> V_129 = V_130 ;
}
static void F_31 ( struct V_26 * V_27 , T_1 V_23 )
{
if ( V_23 == 0xff0000c5 && V_27 -> V_49 . V_55 == 256 &&
V_27 -> V_49 . V_54 == 8 )
V_27 -> V_131 |= V_132 ;
}
static void F_32 ( struct V_26 * V_27 , unsigned type )
{
struct V_2 * V_62 = V_27 -> V_3 ;
if ( ( ( V_27 -> V_49 . V_85 << 16 ) == V_133 ) &&
type == V_57 )
V_62 -> V_129 = V_134 ;
}
static int F_33 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
V_53 V_71 ;
int V_48 ;
V_71 = F_15 ( V_70 ) ;
switch ( V_70 -> V_77 ) {
case V_103 :
F_32 ( V_27 , V_71 & 0xff ) ;
break;
case V_104 :
break;
case V_105 :
if ( V_71 & V_135 )
break;
for ( V_48 = 0 ; V_48 < V_27 -> V_30 . V_42 ; V_48 ++ )
F_30 ( V_27 , V_27 -> V_30 . V_23 [ V_48 ] ) ;
break;
case V_107 :
break;
case V_109 :
for ( V_48 = 0 ; V_48 < V_27 -> V_30 . V_42 ; V_48 ++ )
F_31 ( V_27 , V_27 -> V_30 . V_23 [ V_48 ] ) ;
break;
}
memset ( & V_27 -> V_30 , 0 , sizeof( V_27 -> V_30 ) ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_62 )
{
struct V_26 * V_27 ;
struct V_69 V_70 ;
T_3 * V_118 = V_62 -> V_117 ;
T_3 * V_119 = V_118 + V_62 -> V_136 ;
static int (* F_35 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_33 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
struct V_1 * F_36 ( struct V_2 * V_62 ,
unsigned int type , unsigned int V_4 ,
unsigned int V_137 ,
unsigned int V_138 )
{
struct V_1 * V_7 ;
if ( type > V_110 ) {
F_5 ( V_62 , L_21 , type ) ;
return NULL ;
}
if ( V_4 >= V_8 ) {
F_5 ( V_62 , L_22 , V_4 ) ;
return NULL ;
}
if ( V_4 == 0 ) {
V_7 = F_37 (
V_62 -> V_6 [ type ] . V_14 . V_139 ,
struct V_1 , V_13 ) ;
} else {
V_7 = V_62 -> V_6 [ type ] . V_9 [ V_4 ] ;
}
if ( ! V_7 ) {
F_5 ( V_62 , L_23 , V_140 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_19 <= V_137 ) {
F_5 ( V_62 , L_24 ,
V_140 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_18 [ V_137 ] -> V_55 < V_138 ) {
F_5 ( V_62 , L_25 ,
V_140 [ type ] , V_4 , V_137 ) ;
return NULL ;
}
return V_7 ;
}
int F_38 ( struct V_2 * V_3 )
{
struct V_26 * V_27 ;
struct V_69 V_70 ;
unsigned int V_12 ;
T_3 * V_118 ;
T_3 * V_141 ;
T_3 * V_119 ;
int V_102 ;
static int (* F_35 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_20 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static V_25 F_39 ( V_53 V_24 , unsigned V_41 )
{
switch ( V_41 ) {
case 8 : return ( ( V_142 ) V_24 ) ;
case 16 : return ( ( V_143 ) V_24 ) ;
case 32 : return ( ( T_2 ) V_24 ) ;
}
return V_24 & ( 1 << ( V_41 - 1 ) ) ? V_24 | ( - 1 << V_41 ) : V_24 ;
}
V_25 F_18 ( V_53 V_24 , unsigned V_41 )
{
return F_39 ( V_24 , V_41 ) ;
}
static T_1 F_40 ( T_2 V_24 , unsigned V_41 )
{
V_25 V_144 = V_24 >> ( V_41 - 1 ) ;
if ( V_144 && V_144 != - 1 )
return V_24 < 0 ? 1 << ( V_41 - 1 ) : ( 1 << ( V_41 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_41 ) - 1 ) ;
}
static V_53 F_41 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 )
{
T_4 V_145 ;
if ( V_41 > 32 )
F_42 ( V_62 , L_26 ,
V_41 , V_146 -> V_147 ) ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_145 = F_43 ( V_7 ) ;
V_145 = ( V_145 >> V_47 ) & ( ( 1ULL << V_41 ) - 1 ) ;
return ( T_1 ) V_145 ;
}
static void F_44 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 , V_53 V_24 )
{
T_4 V_145 ;
T_4 V_148 = ( 1ULL << V_41 ) - 1 ;
if ( V_41 > 32 )
F_42 ( V_62 , L_27 ,
V_149 , V_41 , V_146 -> V_147 ) ;
if ( V_24 > V_148 )
F_42 ( V_62 , L_28 ,
V_149 , V_24 , V_146 -> V_147 ) ;
F_45 ( V_24 > V_148 ) ;
V_24 &= V_148 ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_145 = F_43 ( V_7 ) ;
V_145 &= ~ ( V_148 << V_47 ) ;
V_145 |= ( ( T_4 ) V_24 ) << V_47 ;
F_46 ( V_145 , V_7 ) ;
}
static int F_47 ( T_2 * V_150 , T_2 V_24 , unsigned V_41 )
{
while ( V_41 -- ) {
if ( * V_150 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_48 ( struct V_2 * V_62 , struct V_1 * V_7 )
{
const struct V_151 * V_4 = V_62 -> V_152 -> V_153 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_154 ; V_4 ++ )
if ( V_4 -> V_45 == V_155 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_49 ( struct V_2 * V_62 , struct V_21 * V_23 )
{
const struct V_156 * V_4 = V_62 -> V_152 -> V_157 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_158 != V_155 - 1 ; V_4 ++ )
if ( ( V_4 -> V_159 == V_155 ||
V_4 -> V_159 == V_23 -> V_62 ) &&
( V_4 -> V_158 == V_155 ||
V_4 -> V_158 == V_23 -> type ) &&
( V_4 -> V_160 == V_155 ||
V_4 -> V_160 == V_23 -> V_161 ) )
return 1 ;
return 0 ;
}
static void F_50 ( struct V_2 * V_62 , struct V_15 * V_18 ,
struct V_21 * V_23 , T_2 V_24 , int V_162 )
{
struct V_163 * V_164 = V_62 -> V_152 ;
int V_102 ;
if ( ! F_51 ( & V_62 -> V_165 ) )
F_52 ( V_62 , V_23 , V_24 ) ;
if ( V_164 && V_164 -> V_166 && F_49 ( V_62 , V_23 ) ) {
V_102 = V_164 -> V_166 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_102 != 0 ) {
if ( V_102 < 0 )
F_5 ( V_62 , L_29 ,
V_164 -> V_167 , V_102 ) ;
return;
}
}
if ( V_62 -> V_168 & V_169 )
F_53 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_62 -> V_168 & V_170 && V_162 && V_62 -> V_171 )
V_62 -> V_171 ( V_62 , V_18 , V_23 , V_24 ) ;
}
static void F_54 ( struct V_2 * V_62 , struct V_15 * V_18 ,
T_3 * V_71 , int V_162 )
{
unsigned V_41 ;
unsigned V_172 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
T_2 V_173 = V_18 -> V_51 ;
T_2 V_174 = V_18 -> V_52 ;
T_2 * V_24 ;
V_24 = F_7 ( sizeof( T_2 ) * V_172 , V_175 ) ;
if ( ! V_24 )
return;
for ( V_41 = 0 ; V_41 < V_172 ; V_41 ++ ) {
V_24 [ V_41 ] = V_173 < 0 ?
F_39 ( F_41 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ,
V_12 ) :
F_41 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ;
if ( ! ( V_18 -> V_46 & V_176 ) &&
V_24 [ V_41 ] >= V_173 && V_24 [ V_41 ] <= V_174 &&
V_18 -> V_23 [ V_24 [ V_41 ] - V_173 ] . V_62 == V_177 + 1 )
goto exit;
}
for ( V_41 = 0 ; V_41 < V_172 ; V_41 ++ ) {
if ( V_176 & V_18 -> V_46 ) {
F_50 ( V_62 , V_18 , & V_18 -> V_23 [ V_41 ] , V_24 [ V_41 ] , V_162 ) ;
continue;
}
if ( V_18 -> V_24 [ V_41 ] >= V_173 && V_18 -> V_24 [ V_41 ] <= V_174
&& V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_173 ] . V_62
&& F_47 ( V_24 , V_18 -> V_24 [ V_41 ] , V_172 ) )
F_50 ( V_62 , V_18 , & V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_173 ] , 0 , V_162 ) ;
if ( V_24 [ V_41 ] >= V_173 && V_24 [ V_41 ] <= V_174
&& V_18 -> V_23 [ V_24 [ V_41 ] - V_173 ] . V_62
&& F_47 ( V_18 -> V_24 , V_24 [ V_41 ] , V_172 ) )
F_50 ( V_62 , V_18 , & V_18 -> V_23 [ V_24 [ V_41 ] - V_173 ] , 1 , V_162 ) ;
}
memcpy ( V_18 -> V_24 , V_24 , V_172 * sizeof( T_2 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_55 ( const struct V_2 * V_62 ,
struct V_15 * V_18 , T_3 * V_71 )
{
unsigned V_172 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_172 ; V_41 ++ ) {
if ( V_18 -> V_51 < 0 )
F_44 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
F_40 ( V_18 -> V_24 [ V_41 ] , V_12 ) ) ;
else
F_44 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
V_18 -> V_24 [ V_41 ] ) ;
}
}
void F_56 ( struct V_1 * V_7 , T_3 * V_71 )
{
unsigned V_41 ;
if ( V_7 -> V_4 > 0 )
* V_71 ++ = V_7 -> V_4 ;
memset ( V_71 , 0 , ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ) ;
for ( V_41 = 0 ; V_41 < V_7 -> V_19 ; V_41 ++ )
F_55 ( V_7 -> V_3 , V_7 -> V_18 [ V_41 ] , V_71 ) ;
}
static int F_57 ( struct V_1 * V_7 )
{
return ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 + ( V_7 -> V_4 > 0 ) ;
}
V_72 * F_58 ( struct V_1 * V_7 , T_5 V_46 )
{
int V_178 = F_57 ( V_7 ) + 7 ;
return F_7 ( V_178 , V_46 ) ;
}
int F_59 ( struct V_15 * V_18 , unsigned V_47 , T_2 V_24 )
{
unsigned V_12 ;
if ( ! V_18 )
return - 1 ;
V_12 = V_18 -> V_54 ;
F_52 ( V_18 -> V_7 -> V_3 , V_18 -> V_23 + V_47 , V_24 ) ;
if ( V_47 >= V_18 -> V_55 ) {
F_5 ( V_18 -> V_7 -> V_3 , L_30 ,
V_47 , V_18 -> V_55 ) ;
return - 1 ;
}
if ( V_18 -> V_51 < 0 ) {
if ( V_24 != F_39 ( F_40 ( V_24 , V_12 ) , V_12 ) ) {
F_5 ( V_18 -> V_7 -> V_3 , L_31 , V_24 ) ;
return - 1 ;
}
}
V_18 -> V_24 [ V_47 ] = V_24 ;
return 0 ;
}
static struct V_1 * F_60 ( struct V_5 * V_6 ,
const V_72 * V_71 )
{
struct V_1 * V_7 ;
unsigned int V_41 = 0 ;
if ( V_6 -> V_11 )
V_41 = * V_71 ;
V_7 = V_6 -> V_9 [ V_41 ] ;
if ( V_7 == NULL )
F_13 ( L_32 , V_41 ) ;
return V_7 ;
}
void F_61 ( struct V_2 * V_62 , struct V_1 * V_7 ,
int V_179 )
{
char * V_141 ;
int V_102 ;
int V_178 ;
V_141 = F_58 ( V_7 , V_10 ) ;
if ( ! V_141 )
return;
V_178 = F_57 ( V_7 ) ;
if ( V_179 == V_180 )
F_56 ( V_7 , V_141 ) ;
V_102 = V_62 -> V_181 -> V_182 ( V_62 , V_7 -> V_4 , V_141 , V_178 ,
V_7 -> type , V_179 ) ;
if ( V_102 < 0 ) {
F_13 ( L_33 , V_102 ) ;
goto V_183;
}
if ( V_179 == V_184 )
F_62 ( V_62 , V_7 -> type , V_141 , V_102 , 0 ) ;
V_183:
F_8 ( V_141 ) ;
}
int F_63 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 ,
int V_162 )
{
struct V_5 * V_6 = V_62 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_163 * V_164 ;
unsigned int V_144 ;
int V_113 , V_185 = V_12 ;
V_72 * V_186 = V_71 ;
int V_102 = 0 ;
V_7 = F_60 ( V_6 , V_71 ) ;
if ( ! V_7 )
goto V_183;
if ( V_6 -> V_11 ) {
V_186 ++ ;
V_185 -- ;
}
V_113 = ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ;
if ( V_113 > V_187 )
V_113 = V_187 ;
if ( V_185 < V_113 ) {
F_13 ( L_34 , V_7 -> V_4 ,
V_185 , V_113 ) ;
memset ( V_186 + V_185 , 0 , V_113 - V_185 ) ;
}
if ( ( V_62 -> V_168 & V_170 ) && V_62 -> V_188 )
V_62 -> V_188 ( V_62 , V_7 ) ;
if ( V_62 -> V_168 & V_189 ) {
V_102 = F_64 ( V_62 , V_71 , V_12 ) ;
if ( V_102 )
goto V_183;
}
if ( V_62 -> V_168 != V_189 && V_7 -> V_19 ) {
for ( V_144 = 0 ; V_144 < V_7 -> V_19 ; V_144 ++ )
F_54 ( V_62 , V_7 -> V_18 [ V_144 ] , V_186 , V_162 ) ;
V_164 = V_62 -> V_152 ;
if ( V_164 && V_164 -> V_7 )
V_164 -> V_7 ( V_62 , V_7 ) ;
}
if ( V_62 -> V_168 & V_169 )
F_65 ( V_62 , V_7 ) ;
V_183:
return V_102 ;
}
int F_62 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 , int V_162 )
{
struct V_5 * V_6 ;
struct V_163 * V_164 ;
struct V_1 * V_7 ;
int V_102 = 0 ;
if ( ! V_62 )
return - V_190 ;
if ( F_66 ( & V_62 -> V_191 ) )
return - V_192 ;
if ( ! V_62 -> V_152 ) {
V_102 = - V_190 ;
goto V_193;
}
V_6 = V_62 -> V_6 + type ;
V_164 = V_62 -> V_152 ;
if ( ! V_12 ) {
F_13 ( L_35 ) ;
V_102 = - 1 ;
goto V_193;
}
if ( ! F_51 ( & V_62 -> V_165 ) )
F_67 ( V_62 , type , V_71 , V_12 ) ;
V_7 = F_60 ( V_6 , V_71 ) ;
if ( ! V_7 ) {
V_102 = - 1 ;
goto V_193;
}
if ( V_164 && V_164 -> V_194 && F_48 ( V_62 , V_7 ) ) {
V_102 = V_164 -> V_194 ( V_62 , V_7 , V_71 , V_12 ) ;
if ( V_102 < 0 )
goto V_193;
}
V_102 = F_63 ( V_62 , type , V_71 , V_12 , V_162 ) ;
V_193:
F_68 ( & V_62 -> V_191 ) ;
return V_102 ;
}
static bool F_69 ( struct V_2 * V_195 ,
const struct V_196 * V_4 )
{
return ( V_4 -> V_197 == V_198 || V_4 -> V_197 == V_195 -> V_197 ) &&
( V_4 -> V_129 == V_199 || V_4 -> V_129 == V_195 -> V_129 ) &&
( V_4 -> V_200 == V_155 || V_4 -> V_200 == V_195 -> V_200 ) &&
( V_4 -> V_201 == V_155 || V_4 -> V_201 == V_195 -> V_201 ) ;
}
const struct V_196 * F_70 ( struct V_2 * V_195 ,
const struct V_196 * V_4 )
{
for (; V_4 -> V_197 ; V_4 ++ )
if ( F_69 ( V_195 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_71 ( struct V_2 * V_195 )
{
return ! ! F_70 ( V_195 , V_202 ) ;
}
static T_6
F_72 ( struct V_203 * V_204 , struct V_205 * V_206 ,
struct V_207 * V_208 ,
char * V_141 , T_7 V_209 , T_8 V_172 )
{
struct V_3 * V_116 = F_26 ( V_206 , struct V_3 , V_206 ) ;
struct V_2 * V_195 = F_26 ( V_116 , struct V_2 , V_116 ) ;
if ( V_209 >= V_195 -> V_113 )
return 0 ;
if ( V_209 + V_172 > V_195 -> V_113 )
V_172 = V_195 -> V_113 - V_209 ;
memcpy ( V_141 , V_195 -> V_112 + V_209 , V_172 ) ;
return V_172 ;
}
int F_73 ( struct V_2 * V_195 , unsigned int V_210 )
{
static const char * V_211 [] = { L_36 , L_37 , L_38 , L_36 ,
L_39 , L_40 , L_41 , L_42 ,
L_43
} ;
const char * type , * V_197 ;
char V_141 [ 64 ] ;
unsigned int V_48 ;
int V_178 ;
int V_102 ;
if ( V_195 -> V_212 & V_213 )
V_210 |= ( V_214 | V_215 ) ;
if ( V_195 -> V_212 & V_216 )
V_210 |= V_217 ;
if ( V_195 -> V_197 != V_218 )
V_210 &= ~ V_215 ;
if ( F_71 ( V_195 ) )
V_210 |= V_214 ;
if ( ( V_210 & V_219 ) && ! F_74 ( V_195 ,
V_210 & V_217 ) )
V_195 -> V_168 |= V_169 ;
if ( ( V_210 & V_215 ) && V_195 -> V_220 &&
! V_195 -> V_220 ( V_195 ,
V_210 & V_214 ) )
V_195 -> V_168 |= V_170 ;
if ( ( V_210 & V_221 ) && ! F_75 ( V_195 ) )
V_195 -> V_168 |= V_189 ;
if ( V_210 & V_222 )
V_195 -> V_168 |= V_223 ;
if ( ! V_195 -> V_168 && ! V_195 -> V_152 -> V_194 ) {
F_5 ( V_195 , L_44 ) ;
return - V_190 ;
}
if ( ( V_195 -> V_168 & V_169 ) &&
( V_210 & V_224 ) && V_195 -> V_225 )
V_195 -> V_225 ( V_195 ) ;
V_178 = 0 ;
if ( V_195 -> V_168 & V_169 )
V_178 += sprintf ( V_141 + V_178 , L_45 ) ;
if ( V_195 -> V_168 & V_170 )
V_178 += sprintf ( V_141 + V_178 , L_46 , V_178 ? L_47 : L_48 ,
V_195 -> V_226 ) ;
if ( V_195 -> V_168 & V_189 )
V_178 += sprintf ( V_141 + V_178 , L_49 , V_178 ? L_47 : L_48 ,
( (struct V_227 * ) V_195 -> V_227 ) -> V_226 ) ;
type = L_36 ;
for ( V_48 = 0 ; V_48 < V_195 -> V_34 ; V_48 ++ ) {
struct V_28 * V_228 = & V_195 -> V_29 [ V_48 ] ;
if ( V_228 -> type == V_39 &&
( V_228 -> V_23 & V_229 ) == V_230 &&
( V_228 -> V_23 & 0xffff ) < F_76 ( V_211 ) ) {
type = V_211 [ V_228 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_195 -> V_197 ) {
case V_218 :
V_197 = L_50 ;
break;
case V_231 :
V_197 = L_51 ;
break;
default:
V_197 = L_52 ;
}
V_102 = F_77 ( & V_195 -> V_116 , & V_232 ) ;
if ( V_102 )
F_42 ( V_195 ,
L_53 , V_102 ) ;
F_78 ( V_195 , L_54 ,
V_141 , V_197 , V_195 -> V_233 >> 8 , V_195 -> V_233 & 0xff ,
type , V_195 -> V_167 , V_195 -> V_234 ) ;
return 0 ;
}
void F_79 ( struct V_2 * V_195 )
{
F_80 ( & V_195 -> V_116 , & V_232 ) ;
if ( V_195 -> V_168 & V_169 )
F_81 ( V_195 ) ;
if ( V_195 -> V_168 & V_170 )
V_195 -> V_235 ( V_195 ) ;
if ( V_195 -> V_168 & V_189 )
F_82 ( V_195 ) ;
V_195 -> V_168 = 0 ;
}
static T_6 F_83 ( struct V_236 * V_237 , const char * V_141 ,
T_8 V_172 )
{
struct V_163 * V_164 = F_26 ( V_237 , struct V_163 , V_152 ) ;
struct V_238 * V_239 ;
V_53 V_197 , V_200 , V_201 ;
unsigned long V_240 = 0 ;
int V_102 ;
V_102 = sscanf ( V_141 , L_55 ,
& V_197 , & V_200 , & V_201 , & V_240 ) ;
if ( V_102 < 3 )
return - V_33 ;
V_239 = F_2 ( sizeof( * V_239 ) , V_10 ) ;
if ( ! V_239 )
return - V_36 ;
V_239 -> V_4 . V_197 = V_197 ;
V_239 -> V_4 . V_129 = V_199 ;
V_239 -> V_4 . V_200 = V_200 ;
V_239 -> V_4 . V_201 = V_201 ;
V_239 -> V_4 . V_240 = V_240 ;
F_84 ( & V_164 -> V_241 ) ;
F_3 ( & V_239 -> V_13 , & V_164 -> V_242 ) ;
F_85 ( & V_164 -> V_241 ) ;
V_102 = F_86 ( & V_164 -> V_152 ) ;
return V_102 ? : V_172 ;
}
static void F_87 ( struct V_163 * V_164 )
{
struct V_238 * V_239 , * V_41 ;
F_84 ( & V_164 -> V_241 ) ;
F_88 (dynid, n, &hdrv->dyn_list, list) {
F_89 ( & V_239 -> V_13 ) ;
F_8 ( V_239 ) ;
}
F_85 ( & V_164 -> V_241 ) ;
}
static const struct V_196 * F_90 ( struct V_2 * V_195 ,
struct V_163 * V_164 )
{
struct V_238 * V_239 ;
F_84 ( & V_164 -> V_241 ) ;
F_91 (dynid, &hdrv->dyn_list, list) {
if ( F_69 ( V_195 , & V_239 -> V_4 ) ) {
F_85 ( & V_164 -> V_241 ) ;
return & V_239 -> V_4 ;
}
}
F_85 ( & V_164 -> V_241 ) ;
return F_70 ( V_195 , V_164 -> V_243 ) ;
}
static int F_92 ( struct V_3 * V_116 , struct V_236 * V_237 )
{
struct V_163 * V_164 = F_26 ( V_237 , struct V_163 , V_152 ) ;
struct V_2 * V_195 = F_26 ( V_116 , struct V_2 , V_116 ) ;
return F_90 ( V_195 , V_164 ) != NULL ;
}
static int F_93 ( struct V_3 * V_116 )
{
struct V_163 * V_164 = F_26 ( V_116 -> V_152 ,
struct V_163 , V_152 ) ;
struct V_2 * V_195 = F_26 ( V_116 , struct V_2 , V_116 ) ;
const struct V_196 * V_4 ;
int V_102 = 0 ;
if ( F_94 ( & V_195 -> V_244 ) )
return - V_245 ;
if ( F_94 ( & V_195 -> V_191 ) ) {
V_102 = - V_245 ;
goto V_246;
}
V_195 -> V_247 = false ;
if ( ! V_195 -> V_152 ) {
V_4 = F_90 ( V_195 , V_164 ) ;
if ( V_4 == NULL ) {
V_102 = - V_190 ;
goto V_193;
}
V_195 -> V_152 = V_164 ;
if ( V_164 -> V_248 ) {
V_102 = V_164 -> V_248 ( V_195 , V_4 ) ;
} else {
V_102 = F_38 ( V_195 ) ;
if ( ! V_102 )
V_102 = F_95 ( V_195 , V_249 ) ;
}
if ( V_102 ) {
F_23 ( V_195 ) ;
V_195 -> V_152 = NULL ;
}
}
V_193:
if ( ! V_195 -> V_247 )
F_68 ( & V_195 -> V_191 ) ;
V_246:
F_68 ( & V_195 -> V_244 ) ;
return V_102 ;
}
static int F_96 ( struct V_3 * V_116 )
{
struct V_2 * V_195 = F_26 ( V_116 , struct V_2 , V_116 ) ;
struct V_163 * V_164 ;
int V_102 = 0 ;
if ( F_94 ( & V_195 -> V_244 ) )
return - V_245 ;
if ( F_94 ( & V_195 -> V_191 ) ) {
V_102 = - V_245 ;
goto V_246;
}
V_195 -> V_247 = false ;
V_164 = V_195 -> V_152 ;
if ( V_164 ) {
if ( V_164 -> remove )
V_164 -> remove ( V_195 ) ;
else
F_97 ( V_195 ) ;
F_23 ( V_195 ) ;
V_195 -> V_152 = NULL ;
}
if ( ! V_195 -> V_247 )
F_68 ( & V_195 -> V_191 ) ;
V_246:
F_68 ( & V_195 -> V_244 ) ;
return V_102 ;
}
static T_6 F_98 ( struct V_3 * V_116 , struct V_250 * V_144 ,
char * V_141 )
{
struct V_2 * V_195 = F_26 ( V_116 , struct V_2 , V_116 ) ;
int V_178 ;
V_178 = snprintf ( V_141 , V_251 , L_56 ,
V_195 -> V_197 , V_195 -> V_129 , V_195 -> V_200 , V_195 -> V_201 ) ;
return ( V_178 >= V_251 ) ? ( V_251 - 1 ) : V_178 ;
}
static int F_99 ( struct V_3 * V_116 , struct V_252 * V_253 )
{
struct V_2 * V_195 = F_26 ( V_116 , struct V_2 , V_116 ) ;
if ( F_100 ( V_253 , L_57 ,
V_195 -> V_197 , V_195 -> V_200 , V_195 -> V_201 ) )
return - V_36 ;
if ( F_100 ( V_253 , L_58 , V_195 -> V_167 ) )
return - V_36 ;
if ( F_100 ( V_253 , L_59 , V_195 -> V_234 ) )
return - V_36 ;
if ( F_100 ( V_253 , L_60 , V_195 -> V_254 ) )
return - V_36 ;
if ( F_100 ( V_253 , L_61 ,
V_195 -> V_197 , V_195 -> V_129 , V_195 -> V_200 , V_195 -> V_201 ) )
return - V_36 ;
return 0 ;
}
bool F_101 ( struct V_2 * V_195 )
{
if ( V_195 -> V_212 & V_255 )
return false ;
if ( V_195 -> V_212 & V_256 )
return true ;
switch ( V_195 -> V_200 ) {
case V_257 :
if ( V_195 -> V_201 >= V_258 &&
V_195 -> V_201 <= V_259 )
return true ;
break;
case V_260 :
if ( V_195 -> V_201 >= V_261 &&
V_195 -> V_201 <= V_262 )
return true ;
if ( V_195 -> V_201 == V_263 &&
! strcmp ( V_195 -> V_167 , L_62 ) )
return true ;
break;
case V_264 :
if ( V_195 -> V_201 >= V_265 &&
V_195 -> V_201 <= V_266 )
return true ;
break;
case V_267 :
if ( V_195 -> V_201 >= V_268 &&
V_195 -> V_201 <= V_269 )
return true ;
break;
case V_270 :
if ( V_195 -> V_201 == V_271 &&
V_195 -> type == V_272 )
return true ;
break;
case V_273 :
if ( ( V_195 -> V_201 >= V_274 &&
V_195 -> V_201 <= V_275 ) ||
( V_195 -> V_201 >= V_276 &&
V_195 -> V_201 <= V_277 ) )
return true ;
break;
case V_278 :
if ( V_195 -> V_201 == V_279 &&
V_195 -> V_197 == V_218 &&
strncmp ( V_195 -> V_167 , L_63 , 22 ) == 0 )
return true ;
break;
}
if ( V_195 -> type == V_280 &&
F_70 ( V_195 , V_281 ) )
return true ;
return ! ! F_70 ( V_195 , V_282 ) ;
}
int F_102 ( struct V_2 * V_195 )
{
static T_9 V_4 = F_103 ( 0 ) ;
int V_102 ;
if ( F_45 ( V_195 -> V_114 & V_283 ) )
return - V_192 ;
if ( F_101 ( V_195 ) )
return - V_190 ;
if ( ! V_195 -> V_181 -> V_182 ) {
F_5 ( V_195 , L_64 ) ;
return - V_33 ;
}
V_102 = V_195 -> V_181 -> V_284 ( V_195 ) ;
if ( V_102 )
return V_102 ;
if ( ! V_195 -> V_117 )
return - V_190 ;
if ( V_285 ||
! F_70 ( V_195 , V_286 ) ) {
V_102 = F_34 ( V_195 ) ;
if ( V_102 )
F_42 ( V_195 , L_65 , V_102 ) ;
}
F_104 ( & V_195 -> V_116 , L_66 , V_195 -> V_197 ,
V_195 -> V_200 , V_195 -> V_201 , F_105 ( & V_4 ) ) ;
F_106 ( V_195 , F_107 ( & V_195 -> V_116 ) ) ;
V_102 = F_108 ( & V_195 -> V_116 ) ;
if ( ! V_102 )
V_195 -> V_114 |= V_283 ;
else
F_109 ( V_195 ) ;
return V_102 ;
}
struct V_2 * F_110 ( void )
{
struct V_2 * V_195 ;
int V_102 = - V_36 ;
V_195 = F_2 ( sizeof( * V_195 ) , V_10 ) ;
if ( V_195 == NULL )
return F_111 ( V_102 ) ;
F_112 ( & V_195 -> V_116 ) ;
V_195 -> V_116 . V_287 = F_25 ;
V_195 -> V_116 . V_197 = & V_288 ;
F_23 ( V_195 ) ;
F_113 ( & V_195 -> V_289 ) ;
F_24 ( & V_195 -> V_165 ) ;
F_114 ( & V_195 -> V_290 ) ;
F_115 ( & V_195 -> V_244 , 1 ) ;
F_115 ( & V_195 -> V_191 , 1 ) ;
return V_195 ;
}
static void F_116 ( struct V_2 * V_195 )
{
if ( V_195 -> V_114 & V_283 ) {
F_117 ( & V_195 -> V_116 ) ;
F_109 ( V_195 ) ;
V_195 -> V_114 &= ~ V_283 ;
}
F_8 ( V_195 -> V_117 ) ;
V_195 -> V_117 = NULL ;
V_195 -> V_136 = 0 ;
}
void F_118 ( struct V_2 * V_195 )
{
F_116 ( V_195 ) ;
F_119 ( & V_195 -> V_116 ) ;
}
int F_120 ( struct V_163 * V_164 , struct V_291 * V_292 ,
const char * V_293 )
{
int V_102 ;
V_164 -> V_152 . V_167 = V_164 -> V_167 ;
V_164 -> V_152 . V_197 = & V_288 ;
V_164 -> V_152 . V_292 = V_292 ;
V_164 -> V_152 . V_293 = V_293 ;
F_24 ( & V_164 -> V_242 ) ;
F_114 ( & V_164 -> V_241 ) ;
V_102 = F_121 ( & V_164 -> V_152 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_122 ( & V_164 -> V_152 , & V_294 ) ;
if ( V_102 )
F_123 ( & V_164 -> V_152 ) ;
return V_102 ;
}
void F_124 ( struct V_163 * V_164 )
{
F_125 ( & V_164 -> V_152 , & V_294 ) ;
F_123 ( & V_164 -> V_152 ) ;
F_87 ( V_164 ) ;
}
int F_126 ( struct V_2 * V_62 )
{
struct V_295 * V_296 ;
int V_48 ;
if ( ! ( V_62 -> V_168 & V_169 ) )
return 0 ;
F_91 (hidinput, &hid->inputs, list) {
for ( V_48 = 0 ; V_48 < F_127 ( V_297 ) ; V_48 ++ )
if ( V_296 -> V_298 -> V_299 [ V_48 ] )
return 1 ;
}
return 0 ;
}
static int T_10 F_128 ( void )
{
int V_102 ;
if ( V_300 )
F_129 ( L_67
L_68 ) ;
V_102 = F_130 ( & V_288 ) ;
if ( V_102 ) {
F_131 ( L_69 ) ;
goto V_301;
}
V_102 = F_132 () ;
if ( V_102 )
goto V_302;
F_133 () ;
return 0 ;
V_302:
F_134 ( & V_288 ) ;
V_301:
return V_102 ;
}
static void T_11 F_135 ( void )
{
F_136 () ;
F_137 () ;
F_134 ( & V_288 ) ;
}
