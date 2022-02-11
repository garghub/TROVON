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
V_7 = V_62 -> V_6 [ type ] . V_9 [ V_4 ] ;
if ( ! V_7 ) {
F_5 ( V_62 , L_23 , V_139 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_19 <= V_137 ) {
F_5 ( V_62 , L_24 ,
V_139 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_18 [ V_137 ] -> V_55 < V_138 ) {
F_5 ( V_62 , L_25 ,
V_139 [ type ] , V_4 , V_137 ) ;
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
T_3 * V_140 ;
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
case 8 : return ( ( V_141 ) V_24 ) ;
case 16 : return ( ( V_142 ) V_24 ) ;
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
V_25 V_143 = V_24 >> ( V_41 - 1 ) ;
if ( V_143 && V_143 != - 1 )
return V_24 < 0 ? 1 << ( V_41 - 1 ) : ( 1 << ( V_41 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_41 ) - 1 ) ;
}
static V_53 F_40 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 )
{
T_4 V_144 ;
if ( V_41 > 32 )
F_41 ( V_62 , L_26 ,
V_41 , V_145 -> V_146 ) ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_144 = F_42 ( V_7 ) ;
V_144 = ( V_144 >> V_47 ) & ( ( 1ULL << V_41 ) - 1 ) ;
return ( T_1 ) V_144 ;
}
static void F_43 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 , V_53 V_24 )
{
T_4 V_144 ;
T_4 V_147 = ( 1ULL << V_41 ) - 1 ;
if ( V_41 > 32 )
F_41 ( V_62 , L_27 ,
V_148 , V_41 , V_145 -> V_146 ) ;
if ( V_24 > V_147 )
F_41 ( V_62 , L_28 ,
V_148 , V_24 , V_145 -> V_146 ) ;
F_44 ( V_24 > V_147 ) ;
V_24 &= V_147 ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_144 = F_42 ( V_7 ) ;
V_144 &= ~ ( V_147 << V_47 ) ;
V_144 |= ( ( T_4 ) V_24 ) << V_47 ;
F_45 ( V_144 , V_7 ) ;
}
static int F_46 ( T_2 * V_149 , T_2 V_24 , unsigned V_41 )
{
while ( V_41 -- ) {
if ( * V_149 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_47 ( struct V_2 * V_62 , struct V_1 * V_7 )
{
const struct V_150 * V_4 = V_62 -> V_151 -> V_152 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_153 ; V_4 ++ )
if ( V_4 -> V_45 == V_154 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_48 ( struct V_2 * V_62 , struct V_21 * V_23 )
{
const struct V_155 * V_4 = V_62 -> V_151 -> V_156 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_157 != V_154 - 1 ; V_4 ++ )
if ( ( V_4 -> V_158 == V_154 ||
V_4 -> V_158 == V_23 -> V_62 ) &&
( V_4 -> V_157 == V_154 ||
V_4 -> V_157 == V_23 -> type ) &&
( V_4 -> V_159 == V_154 ||
V_4 -> V_159 == V_23 -> V_160 ) )
return 1 ;
return 0 ;
}
static void F_49 ( struct V_2 * V_62 , struct V_15 * V_18 ,
struct V_21 * V_23 , T_2 V_24 , int V_161 )
{
struct V_162 * V_163 = V_62 -> V_151 ;
int V_102 ;
if ( ! F_50 ( & V_62 -> V_164 ) )
F_51 ( V_62 , V_23 , V_24 ) ;
if ( V_163 && V_163 -> V_165 && F_48 ( V_62 , V_23 ) ) {
V_102 = V_163 -> V_165 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_102 != 0 ) {
if ( V_102 < 0 )
F_5 ( V_62 , L_29 ,
V_163 -> V_166 , V_102 ) ;
return;
}
}
if ( V_62 -> V_167 & V_168 )
F_52 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_62 -> V_167 & V_169 && V_161 && V_62 -> V_170 )
V_62 -> V_170 ( V_62 , V_18 , V_23 , V_24 ) ;
}
static void F_53 ( struct V_2 * V_62 , struct V_15 * V_18 ,
T_3 * V_71 , int V_161 )
{
unsigned V_41 ;
unsigned V_171 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
T_2 V_172 = V_18 -> V_51 ;
T_2 V_173 = V_18 -> V_52 ;
T_2 * V_24 ;
V_24 = F_7 ( sizeof( T_2 ) * V_171 , V_174 ) ;
if ( ! V_24 )
return;
for ( V_41 = 0 ; V_41 < V_171 ; V_41 ++ ) {
V_24 [ V_41 ] = V_172 < 0 ?
F_38 ( F_40 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ,
V_12 ) :
F_40 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ;
if ( ! ( V_18 -> V_46 & V_175 ) &&
V_24 [ V_41 ] >= V_172 && V_24 [ V_41 ] <= V_173 &&
V_18 -> V_23 [ V_24 [ V_41 ] - V_172 ] . V_62 == V_176 + 1 )
goto exit;
}
for ( V_41 = 0 ; V_41 < V_171 ; V_41 ++ ) {
if ( V_175 & V_18 -> V_46 ) {
F_49 ( V_62 , V_18 , & V_18 -> V_23 [ V_41 ] , V_24 [ V_41 ] , V_161 ) ;
continue;
}
if ( V_18 -> V_24 [ V_41 ] >= V_172 && V_18 -> V_24 [ V_41 ] <= V_173
&& V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_172 ] . V_62
&& F_46 ( V_24 , V_18 -> V_24 [ V_41 ] , V_171 ) )
F_49 ( V_62 , V_18 , & V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_172 ] , 0 , V_161 ) ;
if ( V_24 [ V_41 ] >= V_172 && V_24 [ V_41 ] <= V_173
&& V_18 -> V_23 [ V_24 [ V_41 ] - V_172 ] . V_62
&& F_46 ( V_18 -> V_24 , V_24 [ V_41 ] , V_171 ) )
F_49 ( V_62 , V_18 , & V_18 -> V_23 [ V_24 [ V_41 ] - V_172 ] , 1 , V_161 ) ;
}
memcpy ( V_18 -> V_24 , V_24 , V_171 * sizeof( T_2 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_54 ( const struct V_2 * V_62 ,
struct V_15 * V_18 , T_3 * V_71 )
{
unsigned V_171 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_171 ; V_41 ++ ) {
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
static int F_56 ( struct V_1 * V_7 )
{
return ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 + ( V_7 -> V_4 > 0 ) ;
}
V_72 * F_57 ( struct V_1 * V_7 , T_5 V_46 )
{
int V_177 = F_56 ( V_7 ) + 7 ;
return F_7 ( V_177 , V_46 ) ;
}
int F_58 ( struct V_15 * V_18 , unsigned V_47 , T_2 V_24 )
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
static struct V_1 * F_59 ( struct V_5 * V_6 ,
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
void F_60 ( struct V_2 * V_62 , struct V_1 * V_7 ,
int V_178 )
{
char * V_140 ;
int V_102 ;
int V_177 ;
V_140 = F_57 ( V_7 , V_10 ) ;
if ( ! V_140 )
return;
V_177 = F_56 ( V_7 ) ;
if ( V_178 == V_179 )
F_55 ( V_7 , V_140 ) ;
V_102 = V_62 -> V_180 -> V_181 ( V_62 , V_7 -> V_4 , V_140 , V_177 ,
V_7 -> type , V_178 ) ;
if ( V_102 < 0 ) {
F_13 ( L_33 , V_102 ) ;
goto V_182;
}
if ( V_178 == V_183 )
F_61 ( V_62 , V_7 -> type , V_140 , V_102 , 0 ) ;
V_182:
F_8 ( V_140 ) ;
}
int F_62 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 ,
int V_161 )
{
struct V_5 * V_6 = V_62 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_162 * V_163 ;
unsigned int V_143 ;
int V_113 , V_184 = V_12 ;
V_72 * V_185 = V_71 ;
int V_102 = 0 ;
V_7 = F_59 ( V_6 , V_71 ) ;
if ( ! V_7 )
goto V_182;
if ( V_6 -> V_11 ) {
V_185 ++ ;
V_184 -- ;
}
V_113 = ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ;
if ( V_113 > V_186 )
V_113 = V_186 ;
if ( V_184 < V_113 ) {
F_13 ( L_34 , V_7 -> V_4 ,
V_184 , V_113 ) ;
memset ( V_185 + V_184 , 0 , V_113 - V_184 ) ;
}
if ( ( V_62 -> V_167 & V_169 ) && V_62 -> V_187 )
V_62 -> V_187 ( V_62 , V_7 ) ;
if ( V_62 -> V_167 & V_188 ) {
V_102 = F_63 ( V_62 , V_71 , V_12 ) ;
if ( V_102 )
goto V_182;
}
if ( V_62 -> V_167 != V_188 && V_7 -> V_19 ) {
for ( V_143 = 0 ; V_143 < V_7 -> V_19 ; V_143 ++ )
F_53 ( V_62 , V_7 -> V_18 [ V_143 ] , V_185 , V_161 ) ;
V_163 = V_62 -> V_151 ;
if ( V_163 && V_163 -> V_7 )
V_163 -> V_7 ( V_62 , V_7 ) ;
}
if ( V_62 -> V_167 & V_168 )
F_64 ( V_62 , V_7 ) ;
V_182:
return V_102 ;
}
int F_61 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 , int V_161 )
{
struct V_5 * V_6 ;
struct V_162 * V_163 ;
struct V_1 * V_7 ;
int V_102 = 0 ;
if ( ! V_62 )
return - V_189 ;
if ( F_65 ( & V_62 -> V_190 ) )
return - V_191 ;
if ( ! V_62 -> V_151 ) {
V_102 = - V_189 ;
goto V_192;
}
V_6 = V_62 -> V_6 + type ;
V_163 = V_62 -> V_151 ;
if ( ! V_12 ) {
F_13 ( L_35 ) ;
V_102 = - 1 ;
goto V_192;
}
if ( ! F_50 ( & V_62 -> V_164 ) )
F_66 ( V_62 , type , V_71 , V_12 ) ;
V_7 = F_59 ( V_6 , V_71 ) ;
if ( ! V_7 ) {
V_102 = - 1 ;
goto V_192;
}
if ( V_163 && V_163 -> V_193 && F_47 ( V_62 , V_7 ) ) {
V_102 = V_163 -> V_193 ( V_62 , V_7 , V_71 , V_12 ) ;
if ( V_102 < 0 )
goto V_192;
}
V_102 = F_62 ( V_62 , type , V_71 , V_12 , V_161 ) ;
V_192:
F_67 ( & V_62 -> V_190 ) ;
return V_102 ;
}
static bool F_68 ( struct V_2 * V_194 ,
const struct V_195 * V_4 )
{
return ( V_4 -> V_196 == V_197 || V_4 -> V_196 == V_194 -> V_196 ) &&
( V_4 -> V_129 == V_198 || V_4 -> V_129 == V_194 -> V_129 ) &&
( V_4 -> V_199 == V_154 || V_4 -> V_199 == V_194 -> V_199 ) &&
( V_4 -> V_200 == V_154 || V_4 -> V_200 == V_194 -> V_200 ) ;
}
const struct V_195 * F_69 ( struct V_2 * V_194 ,
const struct V_195 * V_4 )
{
for (; V_4 -> V_196 ; V_4 ++ )
if ( F_68 ( V_194 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_70 ( struct V_2 * V_194 )
{
return ! ! F_69 ( V_194 , V_201 ) ;
}
static T_6
F_71 ( struct V_202 * V_203 , struct V_204 * V_205 ,
struct V_206 * V_207 ,
char * V_140 , T_7 V_208 , T_8 V_171 )
{
struct V_3 * V_116 = F_26 ( V_205 , struct V_3 , V_205 ) ;
struct V_2 * V_194 = F_26 ( V_116 , struct V_2 , V_116 ) ;
if ( V_208 >= V_194 -> V_113 )
return 0 ;
if ( V_208 + V_171 > V_194 -> V_113 )
V_171 = V_194 -> V_113 - V_208 ;
memcpy ( V_140 , V_194 -> V_112 + V_208 , V_171 ) ;
return V_171 ;
}
int F_72 ( struct V_2 * V_194 , unsigned int V_209 )
{
static const char * V_210 [] = { L_36 , L_37 , L_38 , L_36 ,
L_39 , L_40 , L_41 , L_42 ,
L_43
} ;
const char * type , * V_196 ;
char V_140 [ 64 ] ;
unsigned int V_48 ;
int V_177 ;
int V_102 ;
if ( V_194 -> V_211 & V_212 )
V_209 |= ( V_213 | V_214 ) ;
if ( V_194 -> V_211 & V_215 )
V_209 |= V_216 ;
if ( V_194 -> V_196 != V_217 )
V_209 &= ~ V_214 ;
if ( F_70 ( V_194 ) )
V_209 |= V_213 ;
if ( ( V_209 & V_218 ) && ! F_73 ( V_194 ,
V_209 & V_216 ) )
V_194 -> V_167 |= V_168 ;
if ( ( V_209 & V_214 ) && V_194 -> V_219 &&
! V_194 -> V_219 ( V_194 ,
V_209 & V_213 ) )
V_194 -> V_167 |= V_169 ;
if ( ( V_209 & V_220 ) && ! F_74 ( V_194 ) )
V_194 -> V_167 |= V_188 ;
if ( ! V_194 -> V_167 && ! V_194 -> V_151 -> V_193 ) {
F_5 ( V_194 , L_44 ) ;
return - V_189 ;
}
if ( ( V_194 -> V_167 & V_168 ) &&
( V_209 & V_221 ) && V_194 -> V_222 )
V_194 -> V_222 ( V_194 ) ;
V_177 = 0 ;
if ( V_194 -> V_167 & V_168 )
V_177 += sprintf ( V_140 + V_177 , L_45 ) ;
if ( V_194 -> V_167 & V_169 )
V_177 += sprintf ( V_140 + V_177 , L_46 , V_177 ? L_47 : L_48 ,
V_194 -> V_223 ) ;
if ( V_194 -> V_167 & V_188 )
V_177 += sprintf ( V_140 + V_177 , L_49 , V_177 ? L_47 : L_48 ,
( (struct V_224 * ) V_194 -> V_224 ) -> V_223 ) ;
type = L_36 ;
for ( V_48 = 0 ; V_48 < V_194 -> V_34 ; V_48 ++ ) {
struct V_28 * V_225 = & V_194 -> V_29 [ V_48 ] ;
if ( V_225 -> type == V_39 &&
( V_225 -> V_23 & V_226 ) == V_227 &&
( V_225 -> V_23 & 0xffff ) < F_75 ( V_210 ) ) {
type = V_210 [ V_225 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_194 -> V_196 ) {
case V_217 :
V_196 = L_50 ;
break;
case V_228 :
V_196 = L_51 ;
break;
default:
V_196 = L_52 ;
}
V_102 = F_76 ( & V_194 -> V_116 , & V_229 ) ;
if ( V_102 )
F_41 ( V_194 ,
L_53 , V_102 ) ;
F_77 ( V_194 , L_54 ,
V_140 , V_196 , V_194 -> V_230 >> 8 , V_194 -> V_230 & 0xff ,
type , V_194 -> V_166 , V_194 -> V_231 ) ;
return 0 ;
}
void F_78 ( struct V_2 * V_194 )
{
F_79 ( & V_194 -> V_116 , & V_229 ) ;
if ( V_194 -> V_167 & V_168 )
F_80 ( V_194 ) ;
if ( V_194 -> V_167 & V_169 )
V_194 -> V_232 ( V_194 ) ;
if ( V_194 -> V_167 & V_188 )
F_81 ( V_194 ) ;
}
static T_6 F_82 ( struct V_233 * V_234 , const char * V_140 ,
T_8 V_171 )
{
struct V_162 * V_163 = F_26 ( V_234 , struct V_162 , V_151 ) ;
struct V_235 * V_236 ;
V_53 V_196 , V_199 , V_200 ;
unsigned long V_237 = 0 ;
int V_102 ;
V_102 = sscanf ( V_140 , L_55 ,
& V_196 , & V_199 , & V_200 , & V_237 ) ;
if ( V_102 < 3 )
return - V_33 ;
V_236 = F_2 ( sizeof( * V_236 ) , V_10 ) ;
if ( ! V_236 )
return - V_36 ;
V_236 -> V_4 . V_196 = V_196 ;
V_236 -> V_4 . V_129 = V_198 ;
V_236 -> V_4 . V_199 = V_199 ;
V_236 -> V_4 . V_200 = V_200 ;
V_236 -> V_4 . V_237 = V_237 ;
F_83 ( & V_163 -> V_238 ) ;
F_3 ( & V_236 -> V_13 , & V_163 -> V_239 ) ;
F_84 ( & V_163 -> V_238 ) ;
V_102 = F_85 ( & V_163 -> V_151 ) ;
return V_102 ? : V_171 ;
}
static void F_86 ( struct V_162 * V_163 )
{
struct V_235 * V_236 , * V_41 ;
F_83 ( & V_163 -> V_238 ) ;
F_87 (dynid, n, &hdrv->dyn_list, list) {
F_88 ( & V_236 -> V_13 ) ;
F_8 ( V_236 ) ;
}
F_84 ( & V_163 -> V_238 ) ;
}
static const struct V_195 * F_89 ( struct V_2 * V_194 ,
struct V_162 * V_163 )
{
struct V_235 * V_236 ;
F_83 ( & V_163 -> V_238 ) ;
F_90 (dynid, &hdrv->dyn_list, list) {
if ( F_68 ( V_194 , & V_236 -> V_4 ) ) {
F_84 ( & V_163 -> V_238 ) ;
return & V_236 -> V_4 ;
}
}
F_84 ( & V_163 -> V_238 ) ;
return F_69 ( V_194 , V_163 -> V_240 ) ;
}
static int F_91 ( struct V_3 * V_116 , struct V_233 * V_234 )
{
struct V_162 * V_163 = F_26 ( V_234 , struct V_162 , V_151 ) ;
struct V_2 * V_194 = F_26 ( V_116 , struct V_2 , V_116 ) ;
return F_89 ( V_194 , V_163 ) != NULL ;
}
static int F_92 ( struct V_3 * V_116 )
{
struct V_162 * V_163 = F_26 ( V_116 -> V_151 ,
struct V_162 , V_151 ) ;
struct V_2 * V_194 = F_26 ( V_116 , struct V_2 , V_116 ) ;
const struct V_195 * V_4 ;
int V_102 = 0 ;
if ( F_93 ( & V_194 -> V_241 ) )
return - V_242 ;
if ( F_93 ( & V_194 -> V_190 ) ) {
V_102 = - V_242 ;
goto V_243;
}
V_194 -> V_244 = false ;
if ( ! V_194 -> V_151 ) {
V_4 = F_89 ( V_194 , V_163 ) ;
if ( V_4 == NULL ) {
V_102 = - V_189 ;
goto V_192;
}
V_194 -> V_151 = V_163 ;
if ( V_163 -> V_245 ) {
V_102 = V_163 -> V_245 ( V_194 , V_4 ) ;
} else {
V_102 = F_37 ( V_194 ) ;
if ( ! V_102 )
V_102 = F_94 ( V_194 , V_246 ) ;
}
if ( V_102 ) {
F_23 ( V_194 ) ;
V_194 -> V_151 = NULL ;
}
}
V_192:
if ( ! V_194 -> V_244 )
F_67 ( & V_194 -> V_190 ) ;
V_243:
F_67 ( & V_194 -> V_241 ) ;
return V_102 ;
}
static int F_95 ( struct V_3 * V_116 )
{
struct V_2 * V_194 = F_26 ( V_116 , struct V_2 , V_116 ) ;
struct V_162 * V_163 ;
int V_102 = 0 ;
if ( F_93 ( & V_194 -> V_241 ) )
return - V_242 ;
if ( F_93 ( & V_194 -> V_190 ) ) {
V_102 = - V_242 ;
goto V_243;
}
V_194 -> V_244 = false ;
V_163 = V_194 -> V_151 ;
if ( V_163 ) {
if ( V_163 -> remove )
V_163 -> remove ( V_194 ) ;
else
F_96 ( V_194 ) ;
F_23 ( V_194 ) ;
V_194 -> V_151 = NULL ;
}
if ( ! V_194 -> V_244 )
F_67 ( & V_194 -> V_190 ) ;
V_243:
F_67 ( & V_194 -> V_241 ) ;
return V_102 ;
}
static T_6 F_97 ( struct V_3 * V_116 , struct V_247 * V_143 ,
char * V_140 )
{
struct V_2 * V_194 = F_26 ( V_116 , struct V_2 , V_116 ) ;
int V_177 ;
V_177 = snprintf ( V_140 , V_248 , L_56 ,
V_194 -> V_196 , V_194 -> V_129 , V_194 -> V_199 , V_194 -> V_200 ) ;
return ( V_177 >= V_248 ) ? ( V_248 - 1 ) : V_177 ;
}
static int F_98 ( struct V_3 * V_116 , struct V_249 * V_250 )
{
struct V_2 * V_194 = F_26 ( V_116 , struct V_2 , V_116 ) ;
if ( F_99 ( V_250 , L_57 ,
V_194 -> V_196 , V_194 -> V_199 , V_194 -> V_200 ) )
return - V_36 ;
if ( F_99 ( V_250 , L_58 , V_194 -> V_166 ) )
return - V_36 ;
if ( F_99 ( V_250 , L_59 , V_194 -> V_231 ) )
return - V_36 ;
if ( F_99 ( V_250 , L_60 , V_194 -> V_251 ) )
return - V_36 ;
if ( F_99 ( V_250 , L_61 ,
V_194 -> V_196 , V_194 -> V_129 , V_194 -> V_199 , V_194 -> V_200 ) )
return - V_36 ;
return 0 ;
}
bool F_100 ( struct V_2 * V_194 )
{
if ( V_194 -> V_211 & V_252 )
return false ;
if ( V_194 -> V_211 & V_253 )
return true ;
switch ( V_194 -> V_199 ) {
case V_254 :
if ( V_194 -> V_200 >= V_255 &&
V_194 -> V_200 <= V_256 )
return true ;
break;
case V_257 :
if ( V_194 -> V_200 >= V_258 &&
V_194 -> V_200 <= V_259 )
return true ;
if ( V_194 -> V_200 == V_260 &&
! strcmp ( V_194 -> V_166 , L_62 ) )
return true ;
break;
case V_261 :
if ( V_194 -> V_200 >= V_262 &&
V_194 -> V_200 <= V_263 )
return true ;
break;
case V_264 :
if ( V_194 -> V_200 >= V_265 &&
V_194 -> V_200 <= V_266 )
return true ;
break;
case V_267 :
if ( V_194 -> V_200 == V_268 &&
V_194 -> type == V_269 )
return true ;
break;
case V_270 :
if ( ( V_194 -> V_200 >= V_271 &&
V_194 -> V_200 <= V_272 ) ||
( V_194 -> V_200 >= V_273 &&
V_194 -> V_200 <= V_274 ) )
return true ;
break;
case V_275 :
if ( V_194 -> V_200 == V_276 &&
V_194 -> V_196 == V_217 &&
strncmp ( V_194 -> V_166 , L_63 , 22 ) == 0 )
return true ;
break;
}
if ( V_194 -> type == V_277 &&
F_69 ( V_194 , V_278 ) )
return true ;
return ! ! F_69 ( V_194 , V_279 ) ;
}
int F_101 ( struct V_2 * V_194 )
{
static T_9 V_4 = F_102 ( 0 ) ;
int V_102 ;
if ( F_44 ( V_194 -> V_114 & V_280 ) )
return - V_191 ;
if ( F_100 ( V_194 ) )
return - V_189 ;
if ( ! V_194 -> V_180 -> V_181 ) {
F_5 ( V_194 , L_64 ) ;
return - V_33 ;
}
V_102 = V_194 -> V_180 -> V_281 ( V_194 ) ;
if ( V_102 )
return V_102 ;
if ( ! V_194 -> V_117 )
return - V_189 ;
if ( V_282 ||
! F_69 ( V_194 , V_283 ) ) {
V_102 = F_34 ( V_194 ) ;
if ( V_102 )
F_41 ( V_194 , L_65 , V_102 ) ;
}
F_103 ( & V_194 -> V_116 , L_66 , V_194 -> V_196 ,
V_194 -> V_199 , V_194 -> V_200 , F_104 ( & V_4 ) ) ;
F_105 ( V_194 , F_106 ( & V_194 -> V_116 ) ) ;
V_102 = F_107 ( & V_194 -> V_116 ) ;
if ( ! V_102 )
V_194 -> V_114 |= V_280 ;
else
F_108 ( V_194 ) ;
return V_102 ;
}
struct V_2 * F_109 ( void )
{
struct V_2 * V_194 ;
int V_102 = - V_36 ;
V_194 = F_2 ( sizeof( * V_194 ) , V_10 ) ;
if ( V_194 == NULL )
return F_110 ( V_102 ) ;
F_111 ( & V_194 -> V_116 ) ;
V_194 -> V_116 . V_284 = F_25 ;
V_194 -> V_116 . V_196 = & V_285 ;
F_23 ( V_194 ) ;
F_112 ( & V_194 -> V_286 ) ;
F_24 ( & V_194 -> V_164 ) ;
F_113 ( & V_194 -> V_287 ) ;
F_114 ( & V_194 -> V_241 , 1 ) ;
F_114 ( & V_194 -> V_190 , 1 ) ;
return V_194 ;
}
static void F_115 ( struct V_2 * V_194 )
{
if ( V_194 -> V_114 & V_280 ) {
F_116 ( & V_194 -> V_116 ) ;
F_108 ( V_194 ) ;
V_194 -> V_114 &= ~ V_280 ;
}
F_8 ( V_194 -> V_117 ) ;
V_194 -> V_117 = NULL ;
V_194 -> V_136 = 0 ;
}
void F_117 ( struct V_2 * V_194 )
{
F_115 ( V_194 ) ;
F_118 ( & V_194 -> V_116 ) ;
}
int F_119 ( struct V_162 * V_163 , struct V_288 * V_289 ,
const char * V_290 )
{
int V_102 ;
V_163 -> V_151 . V_166 = V_163 -> V_166 ;
V_163 -> V_151 . V_196 = & V_285 ;
V_163 -> V_151 . V_289 = V_289 ;
V_163 -> V_151 . V_290 = V_290 ;
F_24 ( & V_163 -> V_239 ) ;
F_113 ( & V_163 -> V_238 ) ;
V_102 = F_120 ( & V_163 -> V_151 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_121 ( & V_163 -> V_151 , & V_291 ) ;
if ( V_102 )
F_122 ( & V_163 -> V_151 ) ;
return V_102 ;
}
void F_123 ( struct V_162 * V_163 )
{
F_124 ( & V_163 -> V_151 , & V_291 ) ;
F_122 ( & V_163 -> V_151 ) ;
F_86 ( V_163 ) ;
}
int F_125 ( struct V_2 * V_62 )
{
struct V_292 * V_293 ;
int V_48 ;
if ( ! ( V_62 -> V_167 & V_168 ) )
return 0 ;
F_90 (hidinput, &hid->inputs, list) {
for ( V_48 = 0 ; V_48 < F_126 ( V_294 ) ; V_48 ++ )
if ( V_293 -> V_295 -> V_296 [ V_48 ] )
return 1 ;
}
return 0 ;
}
static int T_10 F_127 ( void )
{
int V_102 ;
if ( V_297 )
F_128 ( L_67
L_68 ) ;
V_102 = F_129 ( & V_285 ) ;
if ( V_102 ) {
F_130 ( L_69 ) ;
goto V_298;
}
V_102 = F_131 () ;
if ( V_102 )
goto V_299;
F_132 () ;
return 0 ;
V_299:
F_133 ( & V_285 ) ;
V_298:
return V_102 ;
}
static void T_11 F_134 ( void )
{
F_135 () ;
F_136 () ;
F_133 ( & V_285 ) ;
}
