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
T_3 * V_119 = V_118 + V_62 -> V_135 ;
static int (* F_35 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_33 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
struct V_1 * F_36 ( struct V_2 * V_62 ,
unsigned int type , unsigned int V_4 ,
unsigned int V_136 ,
unsigned int V_137 )
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
V_7 = V_62 -> V_6 [ type ] . V_9 [ V_4 ] ;
if ( ! V_7 ) {
F_5 ( V_62 , L_23 , V_138 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_19 <= V_136 ) {
F_5 ( V_62 , L_24 ,
V_138 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_18 [ V_136 ] -> V_55 < V_137 ) {
F_5 ( V_62 , L_25 ,
V_138 [ type ] , V_4 , V_136 ) ;
return NULL ;
}
return V_7 ;
}
int F_37 ( struct V_2 * V_3 )
{
struct V_26 * V_27 ;
struct V_69 V_70 ;
unsigned int V_12 ;
T_3 * V_118 ;
T_3 * V_139 ;
T_3 * V_119 ;
int V_102 ;
static int (* F_35 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_20 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static V_25 F_38 ( V_53 V_24 , unsigned V_41 )
{
switch ( V_41 ) {
case 8 : return ( ( V_140 ) V_24 ) ;
case 16 : return ( ( V_141 ) V_24 ) ;
case 32 : return ( ( T_2 ) V_24 ) ;
}
return V_24 & ( 1 << ( V_41 - 1 ) ) ? V_24 | ( - 1 << V_41 ) : V_24 ;
}
V_25 F_18 ( V_53 V_24 , unsigned V_41 )
{
return F_38 ( V_24 , V_41 ) ;
}
static T_1 F_39 ( T_2 V_24 , unsigned V_41 )
{
V_25 V_142 = V_24 >> ( V_41 - 1 ) ;
if ( V_142 && V_142 != - 1 )
return V_24 < 0 ? 1 << ( V_41 - 1 ) : ( 1 << ( V_41 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_41 ) - 1 ) ;
}
static V_53 F_40 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 )
{
T_4 V_143 ;
if ( V_41 > 32 )
F_41 ( V_62 , L_26 ,
V_41 , V_144 -> V_145 ) ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_143 = F_42 ( V_7 ) ;
V_143 = ( V_143 >> V_47 ) & ( ( 1ULL << V_41 ) - 1 ) ;
return ( T_1 ) V_143 ;
}
static void F_43 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 , V_53 V_24 )
{
T_4 V_143 ;
T_4 V_146 = ( 1ULL << V_41 ) - 1 ;
if ( V_41 > 32 )
F_41 ( V_62 , L_27 ,
V_147 , V_41 , V_144 -> V_145 ) ;
if ( V_24 > V_146 )
F_41 ( V_62 , L_28 ,
V_147 , V_24 , V_144 -> V_145 ) ;
F_44 ( V_24 > V_146 ) ;
V_24 &= V_146 ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_143 = F_42 ( V_7 ) ;
V_143 &= ~ ( V_146 << V_47 ) ;
V_143 |= ( ( T_4 ) V_24 ) << V_47 ;
F_45 ( V_143 , V_7 ) ;
}
static int F_46 ( T_2 * V_148 , T_2 V_24 , unsigned V_41 )
{
while ( V_41 -- ) {
if ( * V_148 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_47 ( struct V_2 * V_62 , struct V_1 * V_7 )
{
const struct V_149 * V_4 = V_62 -> V_150 -> V_151 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_152 ; V_4 ++ )
if ( V_4 -> V_45 == V_153 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_48 ( struct V_2 * V_62 , struct V_21 * V_23 )
{
const struct V_154 * V_4 = V_62 -> V_150 -> V_155 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_156 != V_153 - 1 ; V_4 ++ )
if ( ( V_4 -> V_157 == V_153 ||
V_4 -> V_157 == V_23 -> V_62 ) &&
( V_4 -> V_156 == V_153 ||
V_4 -> V_156 == V_23 -> type ) &&
( V_4 -> V_158 == V_153 ||
V_4 -> V_158 == V_23 -> V_159 ) )
return 1 ;
return 0 ;
}
static void F_49 ( struct V_2 * V_62 , struct V_15 * V_18 ,
struct V_21 * V_23 , T_2 V_24 , int V_160 )
{
struct V_161 * V_162 = V_62 -> V_150 ;
int V_102 ;
if ( ! F_50 ( & V_62 -> V_163 ) )
F_51 ( V_62 , V_23 , V_24 ) ;
if ( V_162 && V_162 -> V_164 && F_48 ( V_62 , V_23 ) ) {
V_102 = V_162 -> V_164 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_102 != 0 ) {
if ( V_102 < 0 )
F_5 ( V_62 , L_29 ,
V_162 -> V_165 , V_102 ) ;
return;
}
}
if ( V_62 -> V_166 & V_167 )
F_52 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_62 -> V_166 & V_168 && V_160 && V_62 -> V_169 )
V_62 -> V_169 ( V_62 , V_18 , V_23 , V_24 ) ;
}
static void F_53 ( struct V_2 * V_62 , struct V_15 * V_18 ,
T_3 * V_71 , int V_160 )
{
unsigned V_41 ;
unsigned V_170 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
T_2 V_171 = V_18 -> V_51 ;
T_2 V_172 = V_18 -> V_52 ;
T_2 * V_24 ;
V_24 = F_7 ( sizeof( T_2 ) * V_170 , V_173 ) ;
if ( ! V_24 )
return;
for ( V_41 = 0 ; V_41 < V_170 ; V_41 ++ ) {
V_24 [ V_41 ] = V_171 < 0 ?
F_38 ( F_40 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ,
V_12 ) :
F_40 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ;
if ( ! ( V_18 -> V_46 & V_174 ) &&
V_24 [ V_41 ] >= V_171 && V_24 [ V_41 ] <= V_172 &&
V_18 -> V_23 [ V_24 [ V_41 ] - V_171 ] . V_62 == V_175 + 1 )
goto exit;
}
for ( V_41 = 0 ; V_41 < V_170 ; V_41 ++ ) {
if ( V_174 & V_18 -> V_46 ) {
F_49 ( V_62 , V_18 , & V_18 -> V_23 [ V_41 ] , V_24 [ V_41 ] , V_160 ) ;
continue;
}
if ( V_18 -> V_24 [ V_41 ] >= V_171 && V_18 -> V_24 [ V_41 ] <= V_172
&& V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_171 ] . V_62
&& F_46 ( V_24 , V_18 -> V_24 [ V_41 ] , V_170 ) )
F_49 ( V_62 , V_18 , & V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_171 ] , 0 , V_160 ) ;
if ( V_24 [ V_41 ] >= V_171 && V_24 [ V_41 ] <= V_172
&& V_18 -> V_23 [ V_24 [ V_41 ] - V_171 ] . V_62
&& F_46 ( V_18 -> V_24 , V_24 [ V_41 ] , V_170 ) )
F_49 ( V_62 , V_18 , & V_18 -> V_23 [ V_24 [ V_41 ] - V_171 ] , 1 , V_160 ) ;
}
memcpy ( V_18 -> V_24 , V_24 , V_170 * sizeof( T_2 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_54 ( const struct V_2 * V_62 ,
struct V_15 * V_18 , T_3 * V_71 )
{
unsigned V_170 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_170 ; V_41 ++ ) {
if ( V_18 -> V_51 < 0 )
F_43 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
F_39 ( V_18 -> V_24 [ V_41 ] , V_12 ) ) ;
else
F_43 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
V_18 -> V_24 [ V_41 ] ) ;
}
}
void F_55 ( struct V_1 * V_7 , T_3 * V_71 )
{
unsigned V_41 ;
if ( V_7 -> V_4 > 0 )
* V_71 ++ = V_7 -> V_4 ;
memset ( V_71 , 0 , ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ) ;
for ( V_41 = 0 ; V_41 < V_7 -> V_19 ; V_41 ++ )
F_54 ( V_7 -> V_3 , V_7 -> V_18 [ V_41 ] , V_71 ) ;
}
V_72 * F_56 ( struct V_1 * V_7 , T_5 V_46 )
{
int V_176 = ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 + ( V_7 -> V_4 > 0 ) + 7 ;
return F_7 ( V_176 , V_46 ) ;
}
int F_57 ( struct V_15 * V_18 , unsigned V_47 , T_2 V_24 )
{
unsigned V_12 ;
if ( ! V_18 )
return - 1 ;
V_12 = V_18 -> V_54 ;
F_51 ( V_18 -> V_7 -> V_3 , V_18 -> V_23 + V_47 , V_24 ) ;
if ( V_47 >= V_18 -> V_55 ) {
F_5 ( V_18 -> V_7 -> V_3 , L_30 ,
V_47 , V_18 -> V_55 ) ;
return - 1 ;
}
if ( V_18 -> V_51 < 0 ) {
if ( V_24 != F_38 ( F_39 ( V_24 , V_12 ) , V_12 ) ) {
F_5 ( V_18 -> V_7 -> V_3 , L_31 , V_24 ) ;
return - 1 ;
}
}
V_18 -> V_24 [ V_47 ] = V_24 ;
return 0 ;
}
static struct V_1 * F_58 ( struct V_5 * V_6 ,
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
int F_59 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 ,
int V_160 )
{
struct V_5 * V_6 = V_62 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_161 * V_162 ;
unsigned int V_142 ;
int V_113 , V_177 = V_12 ;
V_72 * V_178 = V_71 ;
int V_102 = 0 ;
V_7 = F_58 ( V_6 , V_71 ) ;
if ( ! V_7 )
goto V_179;
if ( V_6 -> V_11 ) {
V_178 ++ ;
V_177 -- ;
}
V_113 = ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ;
if ( V_113 > V_180 )
V_113 = V_180 ;
if ( V_177 < V_113 ) {
F_13 ( L_33 , V_7 -> V_4 ,
V_177 , V_113 ) ;
memset ( V_178 + V_177 , 0 , V_113 - V_177 ) ;
}
if ( ( V_62 -> V_166 & V_168 ) && V_62 -> V_181 )
V_62 -> V_181 ( V_62 , V_7 ) ;
if ( V_62 -> V_166 & V_182 ) {
V_102 = F_60 ( V_62 , V_71 , V_12 ) ;
if ( V_102 )
goto V_179;
}
if ( V_62 -> V_166 != V_182 && V_7 -> V_19 ) {
for ( V_142 = 0 ; V_142 < V_7 -> V_19 ; V_142 ++ )
F_53 ( V_62 , V_7 -> V_18 [ V_142 ] , V_178 , V_160 ) ;
V_162 = V_62 -> V_150 ;
if ( V_162 && V_162 -> V_7 )
V_162 -> V_7 ( V_62 , V_7 ) ;
}
if ( V_62 -> V_166 & V_167 )
F_61 ( V_62 , V_7 ) ;
V_179:
return V_102 ;
}
int F_62 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 , int V_160 )
{
struct V_5 * V_6 ;
struct V_161 * V_162 ;
struct V_1 * V_7 ;
int V_102 = 0 ;
if ( ! V_62 )
return - V_183 ;
if ( F_63 ( & V_62 -> V_184 ) )
return - V_185 ;
if ( ! V_62 -> V_150 ) {
V_102 = - V_183 ;
goto V_186;
}
V_6 = V_62 -> V_6 + type ;
V_162 = V_62 -> V_150 ;
if ( ! V_12 ) {
F_13 ( L_34 ) ;
V_102 = - 1 ;
goto V_186;
}
if ( ! F_50 ( & V_62 -> V_163 ) )
F_64 ( V_62 , type , V_71 , V_12 ) ;
V_7 = F_58 ( V_6 , V_71 ) ;
if ( ! V_7 ) {
V_102 = - 1 ;
goto V_186;
}
if ( V_162 && V_162 -> V_187 && F_47 ( V_62 , V_7 ) ) {
V_102 = V_162 -> V_187 ( V_62 , V_7 , V_71 , V_12 ) ;
if ( V_102 < 0 ) {
V_102 = V_102 < 0 ? V_102 : 0 ;
goto V_186;
}
}
V_102 = F_59 ( V_62 , type , V_71 , V_12 , V_160 ) ;
V_186:
F_65 ( & V_62 -> V_184 ) ;
return V_102 ;
}
static bool F_66 ( struct V_2 * V_188 ,
const struct V_189 * V_4 )
{
return ( V_4 -> V_190 == V_191 || V_4 -> V_190 == V_188 -> V_190 ) &&
( V_4 -> V_129 == V_192 || V_4 -> V_129 == V_188 -> V_129 ) &&
( V_4 -> V_193 == V_153 || V_4 -> V_193 == V_188 -> V_193 ) &&
( V_4 -> V_194 == V_153 || V_4 -> V_194 == V_188 -> V_194 ) ;
}
const struct V_189 * F_67 ( struct V_2 * V_188 ,
const struct V_189 * V_4 )
{
for (; V_4 -> V_190 ; V_4 ++ )
if ( F_66 ( V_188 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_68 ( struct V_2 * V_188 )
{
return ! ! F_67 ( V_188 , V_195 ) ;
}
static T_6
F_69 ( struct V_196 * V_197 , struct V_198 * V_199 ,
struct V_200 * V_201 ,
char * V_139 , T_7 V_202 , T_8 V_170 )
{
struct V_3 * V_116 = F_26 ( V_199 , struct V_3 , V_199 ) ;
struct V_2 * V_188 = F_26 ( V_116 , struct V_2 , V_116 ) ;
if ( V_202 >= V_188 -> V_113 )
return 0 ;
if ( V_202 + V_170 > V_188 -> V_113 )
V_170 = V_188 -> V_113 - V_202 ;
memcpy ( V_139 , V_188 -> V_112 + V_202 , V_170 ) ;
return V_170 ;
}
int F_70 ( struct V_2 * V_188 , unsigned int V_203 )
{
static const char * V_204 [] = { L_35 , L_36 , L_37 , L_35 ,
L_38 , L_39 , L_40 , L_41 ,
L_42
} ;
const char * type , * V_190 ;
char V_139 [ 64 ] ;
unsigned int V_48 ;
int V_176 ;
int V_102 ;
if ( V_188 -> V_205 & V_206 )
V_203 |= ( V_207 | V_208 ) ;
if ( V_188 -> V_205 & V_209 )
V_203 |= V_210 ;
if ( V_188 -> V_190 != V_211 )
V_203 &= ~ V_208 ;
if ( F_68 ( V_188 ) )
V_203 |= V_207 ;
if ( ( V_203 & V_212 ) && ! F_71 ( V_188 ,
V_203 & V_210 ) )
V_188 -> V_166 |= V_167 ;
if ( ( V_203 & V_208 ) && V_188 -> V_213 &&
! V_188 -> V_213 ( V_188 ,
V_203 & V_207 ) )
V_188 -> V_166 |= V_168 ;
if ( ( V_203 & V_214 ) && ! F_72 ( V_188 ) )
V_188 -> V_166 |= V_182 ;
if ( ! V_188 -> V_166 && ! V_188 -> V_150 -> V_187 ) {
F_5 ( V_188 , L_43 ) ;
return - V_183 ;
}
if ( ( V_188 -> V_166 & V_167 ) &&
( V_203 & V_215 ) && V_188 -> V_216 )
V_188 -> V_216 ( V_188 ) ;
V_176 = 0 ;
if ( V_188 -> V_166 & V_167 )
V_176 += sprintf ( V_139 + V_176 , L_44 ) ;
if ( V_188 -> V_166 & V_168 )
V_176 += sprintf ( V_139 + V_176 , L_45 , V_176 ? L_46 : L_47 ,
V_188 -> V_217 ) ;
if ( V_188 -> V_166 & V_182 )
V_176 += sprintf ( V_139 + V_176 , L_48 , V_176 ? L_46 : L_47 ,
( (struct V_218 * ) V_188 -> V_218 ) -> V_217 ) ;
type = L_35 ;
for ( V_48 = 0 ; V_48 < V_188 -> V_34 ; V_48 ++ ) {
struct V_28 * V_219 = & V_188 -> V_29 [ V_48 ] ;
if ( V_219 -> type == V_39 &&
( V_219 -> V_23 & V_220 ) == V_221 &&
( V_219 -> V_23 & 0xffff ) < F_73 ( V_204 ) ) {
type = V_204 [ V_219 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_188 -> V_190 ) {
case V_211 :
V_190 = L_49 ;
break;
case V_222 :
V_190 = L_50 ;
break;
default:
V_190 = L_51 ;
}
V_102 = F_74 ( & V_188 -> V_116 , & V_223 ) ;
if ( V_102 )
F_41 ( V_188 ,
L_52 , V_102 ) ;
F_75 ( V_188 , L_53 ,
V_139 , V_190 , V_188 -> V_224 >> 8 , V_188 -> V_224 & 0xff ,
type , V_188 -> V_165 , V_188 -> V_225 ) ;
return 0 ;
}
void F_76 ( struct V_2 * V_188 )
{
F_77 ( & V_188 -> V_116 , & V_223 ) ;
if ( V_188 -> V_166 & V_167 )
F_78 ( V_188 ) ;
if ( V_188 -> V_166 & V_168 )
V_188 -> V_226 ( V_188 ) ;
if ( V_188 -> V_166 & V_182 )
F_79 ( V_188 ) ;
}
static T_6 F_80 ( struct V_227 * V_228 , const char * V_139 ,
T_8 V_170 )
{
struct V_161 * V_162 = F_26 ( V_228 , struct V_161 , V_150 ) ;
struct V_229 * V_230 ;
V_53 V_190 , V_193 , V_194 ;
unsigned long V_231 = 0 ;
int V_102 ;
V_102 = sscanf ( V_139 , L_54 ,
& V_190 , & V_193 , & V_194 , & V_231 ) ;
if ( V_102 < 3 )
return - V_33 ;
V_230 = F_2 ( sizeof( * V_230 ) , V_10 ) ;
if ( ! V_230 )
return - V_36 ;
V_230 -> V_4 . V_190 = V_190 ;
V_230 -> V_4 . V_129 = V_192 ;
V_230 -> V_4 . V_193 = V_193 ;
V_230 -> V_4 . V_194 = V_194 ;
V_230 -> V_4 . V_231 = V_231 ;
F_81 ( & V_162 -> V_232 ) ;
F_3 ( & V_230 -> V_13 , & V_162 -> V_233 ) ;
F_82 ( & V_162 -> V_232 ) ;
V_102 = F_83 ( & V_162 -> V_150 ) ;
return V_102 ? : V_170 ;
}
static void F_84 ( struct V_161 * V_162 )
{
struct V_229 * V_230 , * V_41 ;
F_81 ( & V_162 -> V_232 ) ;
F_85 (dynid, n, &hdrv->dyn_list, list) {
F_86 ( & V_230 -> V_13 ) ;
F_8 ( V_230 ) ;
}
F_82 ( & V_162 -> V_232 ) ;
}
static const struct V_189 * F_87 ( struct V_2 * V_188 ,
struct V_161 * V_162 )
{
struct V_229 * V_230 ;
F_81 ( & V_162 -> V_232 ) ;
F_88 (dynid, &hdrv->dyn_list, list) {
if ( F_66 ( V_188 , & V_230 -> V_4 ) ) {
F_82 ( & V_162 -> V_232 ) ;
return & V_230 -> V_4 ;
}
}
F_82 ( & V_162 -> V_232 ) ;
return F_67 ( V_188 , V_162 -> V_234 ) ;
}
static int F_89 ( struct V_3 * V_116 , struct V_227 * V_228 )
{
struct V_161 * V_162 = F_26 ( V_228 , struct V_161 , V_150 ) ;
struct V_2 * V_188 = F_26 ( V_116 , struct V_2 , V_116 ) ;
return F_87 ( V_188 , V_162 ) != NULL ;
}
static int F_90 ( struct V_3 * V_116 )
{
struct V_161 * V_162 = F_26 ( V_116 -> V_150 ,
struct V_161 , V_150 ) ;
struct V_2 * V_188 = F_26 ( V_116 , struct V_2 , V_116 ) ;
const struct V_189 * V_4 ;
int V_102 = 0 ;
if ( F_91 ( & V_188 -> V_235 ) )
return - V_236 ;
if ( F_91 ( & V_188 -> V_184 ) ) {
V_102 = - V_236 ;
goto V_237;
}
V_188 -> V_238 = false ;
if ( ! V_188 -> V_150 ) {
V_4 = F_87 ( V_188 , V_162 ) ;
if ( V_4 == NULL ) {
V_102 = - V_183 ;
goto V_186;
}
V_188 -> V_150 = V_162 ;
if ( V_162 -> V_239 ) {
V_102 = V_162 -> V_239 ( V_188 , V_4 ) ;
} else {
V_102 = F_37 ( V_188 ) ;
if ( ! V_102 )
V_102 = F_92 ( V_188 , V_240 ) ;
}
if ( V_102 ) {
F_23 ( V_188 ) ;
V_188 -> V_150 = NULL ;
}
}
V_186:
if ( ! V_188 -> V_238 )
F_65 ( & V_188 -> V_184 ) ;
V_237:
F_65 ( & V_188 -> V_235 ) ;
return V_102 ;
}
static int F_93 ( struct V_3 * V_116 )
{
struct V_2 * V_188 = F_26 ( V_116 , struct V_2 , V_116 ) ;
struct V_161 * V_162 ;
int V_102 = 0 ;
if ( F_91 ( & V_188 -> V_235 ) )
return - V_236 ;
if ( F_91 ( & V_188 -> V_184 ) ) {
V_102 = - V_236 ;
goto V_237;
}
V_188 -> V_238 = false ;
V_162 = V_188 -> V_150 ;
if ( V_162 ) {
if ( V_162 -> remove )
V_162 -> remove ( V_188 ) ;
else
F_94 ( V_188 ) ;
F_23 ( V_188 ) ;
V_188 -> V_150 = NULL ;
}
if ( ! V_188 -> V_238 )
F_65 ( & V_188 -> V_184 ) ;
V_237:
F_65 ( & V_188 -> V_235 ) ;
return V_102 ;
}
static T_6 F_95 ( struct V_3 * V_116 , struct V_241 * V_142 ,
char * V_139 )
{
struct V_2 * V_188 = F_26 ( V_116 , struct V_2 , V_116 ) ;
int V_176 ;
V_176 = snprintf ( V_139 , V_242 , L_55 ,
V_188 -> V_190 , V_188 -> V_129 , V_188 -> V_193 , V_188 -> V_194 ) ;
return ( V_176 >= V_242 ) ? ( V_242 - 1 ) : V_176 ;
}
static int F_96 ( struct V_3 * V_116 , struct V_243 * V_244 )
{
struct V_2 * V_188 = F_26 ( V_116 , struct V_2 , V_116 ) ;
if ( F_97 ( V_244 , L_56 ,
V_188 -> V_190 , V_188 -> V_193 , V_188 -> V_194 ) )
return - V_36 ;
if ( F_97 ( V_244 , L_57 , V_188 -> V_165 ) )
return - V_36 ;
if ( F_97 ( V_244 , L_58 , V_188 -> V_225 ) )
return - V_36 ;
if ( F_97 ( V_244 , L_59 , V_188 -> V_245 ) )
return - V_36 ;
if ( F_97 ( V_244 , L_60 ,
V_188 -> V_190 , V_188 -> V_129 , V_188 -> V_193 , V_188 -> V_194 ) )
return - V_36 ;
return 0 ;
}
bool F_98 ( struct V_2 * V_188 )
{
if ( V_188 -> V_205 & V_246 )
return false ;
if ( V_188 -> V_205 & V_247 )
return true ;
switch ( V_188 -> V_193 ) {
case V_248 :
if ( V_188 -> V_194 >= V_249 &&
V_188 -> V_194 <= V_250 )
return true ;
break;
case V_251 :
if ( V_188 -> V_194 >= V_252 &&
V_188 -> V_194 <= V_253 )
return true ;
if ( V_188 -> V_194 == V_254 &&
! strcmp ( V_188 -> V_165 , L_61 ) )
return true ;
break;
case V_255 :
if ( V_188 -> V_194 >= V_256 &&
V_188 -> V_194 <= V_257 )
return true ;
break;
case V_258 :
if ( V_188 -> V_194 >= V_259 &&
V_188 -> V_194 <= V_260 )
return true ;
break;
case V_261 :
if ( V_188 -> V_194 == V_262 &&
V_188 -> type == V_263 )
return true ;
break;
case V_264 :
if ( ( V_188 -> V_194 == V_265 ||
V_188 -> V_194 == V_266 ) &&
V_188 -> type != V_267 )
return true ;
break;
case V_268 :
if ( ( V_188 -> V_194 >= V_269 &&
V_188 -> V_194 <= V_270 ) ||
( V_188 -> V_194 >= V_271 &&
V_188 -> V_194 <= V_272 ) )
return true ;
break;
case V_273 :
if ( V_188 -> V_194 == V_274 &&
V_188 -> V_190 == V_211 &&
strncmp ( V_188 -> V_165 , L_62 , 22 ) == 0 )
return true ;
break;
}
if ( V_188 -> type == V_267 &&
F_67 ( V_188 , V_275 ) )
return true ;
return ! ! F_67 ( V_188 , V_276 ) ;
}
int F_99 ( struct V_2 * V_188 )
{
static T_9 V_4 = F_100 ( 0 ) ;
int V_102 ;
if ( F_44 ( V_188 -> V_114 & V_277 ) )
return - V_185 ;
if ( F_98 ( V_188 ) )
return - V_183 ;
V_102 = V_188 -> V_278 -> V_279 ( V_188 ) ;
if ( V_102 )
return V_102 ;
if ( ! V_188 -> V_117 )
return - V_183 ;
if ( V_280 ||
! F_67 ( V_188 , V_281 ) ) {
V_102 = F_34 ( V_188 ) ;
if ( V_102 )
F_41 ( V_188 , L_63 , V_102 ) ;
}
F_101 ( & V_188 -> V_116 , L_64 , V_188 -> V_190 ,
V_188 -> V_193 , V_188 -> V_194 , F_102 ( & V_4 ) ) ;
F_103 ( V_188 , F_104 ( & V_188 -> V_116 ) ) ;
V_102 = F_105 ( & V_188 -> V_116 ) ;
if ( ! V_102 )
V_188 -> V_114 |= V_277 ;
else
F_106 ( V_188 ) ;
return V_102 ;
}
struct V_2 * F_107 ( void )
{
struct V_2 * V_188 ;
int V_102 = - V_36 ;
V_188 = F_2 ( sizeof( * V_188 ) , V_10 ) ;
if ( V_188 == NULL )
return F_108 ( V_102 ) ;
F_109 ( & V_188 -> V_116 ) ;
V_188 -> V_116 . V_282 = F_25 ;
V_188 -> V_116 . V_190 = & V_283 ;
F_23 ( V_188 ) ;
F_110 ( & V_188 -> V_284 ) ;
F_24 ( & V_188 -> V_163 ) ;
F_111 ( & V_188 -> V_285 ) ;
F_112 ( & V_188 -> V_235 , 1 ) ;
F_112 ( & V_188 -> V_184 , 1 ) ;
return V_188 ;
}
static void F_113 ( struct V_2 * V_188 )
{
if ( V_188 -> V_114 & V_277 ) {
F_114 ( & V_188 -> V_116 ) ;
F_106 ( V_188 ) ;
V_188 -> V_114 &= ~ V_277 ;
}
F_8 ( V_188 -> V_117 ) ;
V_188 -> V_117 = NULL ;
V_188 -> V_135 = 0 ;
}
void F_115 ( struct V_2 * V_188 )
{
F_113 ( V_188 ) ;
F_116 ( & V_188 -> V_116 ) ;
}
int F_117 ( struct V_161 * V_162 , struct V_286 * V_287 ,
const char * V_288 )
{
int V_102 ;
V_162 -> V_150 . V_165 = V_162 -> V_165 ;
V_162 -> V_150 . V_190 = & V_283 ;
V_162 -> V_150 . V_287 = V_287 ;
V_162 -> V_150 . V_288 = V_288 ;
F_24 ( & V_162 -> V_233 ) ;
F_111 ( & V_162 -> V_232 ) ;
V_102 = F_118 ( & V_162 -> V_150 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_119 ( & V_162 -> V_150 , & V_289 ) ;
if ( V_102 )
F_120 ( & V_162 -> V_150 ) ;
return V_102 ;
}
void F_121 ( struct V_161 * V_162 )
{
F_122 ( & V_162 -> V_150 , & V_289 ) ;
F_120 ( & V_162 -> V_150 ) ;
F_84 ( V_162 ) ;
}
int F_123 ( struct V_2 * V_62 )
{
struct V_290 * V_291 ;
int V_48 ;
if ( ! ( V_62 -> V_166 & V_167 ) )
return 0 ;
F_88 (hidinput, &hid->inputs, list) {
for ( V_48 = 0 ; V_48 < F_124 ( V_292 ) ; V_48 ++ )
if ( V_291 -> V_293 -> V_294 [ V_48 ] )
return 1 ;
}
return 0 ;
}
static int T_10 F_125 ( void )
{
int V_102 ;
if ( V_295 )
F_126 ( L_65
L_66 ) ;
V_102 = F_127 ( & V_283 ) ;
if ( V_102 ) {
F_128 ( L_67 ) ;
goto V_296;
}
V_102 = F_129 () ;
if ( V_102 )
goto V_297;
F_130 () ;
return 0 ;
V_297:
F_131 ( & V_283 ) ;
V_296:
return V_102 ;
}
static void T_11 F_132 ( void )
{
F_133 () ;
F_134 () ;
F_131 ( & V_283 ) ;
}
