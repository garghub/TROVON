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
V_53 V_95 ;
V_71 = F_15 ( V_70 ) ;
switch ( V_70 -> V_77 ) {
case V_96 :
if ( V_71 ) {
if ( V_27 -> V_30 . V_97 != 0 ) {
F_5 ( V_27 -> V_3 , L_14 ) ;
return - 1 ;
}
V_27 -> V_30 . V_97 ++ ;
V_27 -> V_30 . V_98 ++ ;
} else {
if ( V_27 -> V_30 . V_97 < 1 ) {
F_5 ( V_27 -> V_3 , L_15 ) ;
return - 1 ;
}
V_27 -> V_30 . V_97 -- ;
}
return 0 ;
case V_99 :
if ( V_27 -> V_30 . V_98 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_70 -> V_12 <= 2 )
V_71 = ( V_27 -> V_49 . V_85 << 16 ) + V_71 ;
return F_11 ( V_27 , V_71 ) ;
case V_100 :
if ( V_27 -> V_30 . V_98 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_70 -> V_12 <= 2 )
V_71 = ( V_27 -> V_49 . V_85 << 16 ) + V_71 ;
V_27 -> V_30 . V_101 = V_71 ;
return 0 ;
case V_102 :
if ( V_27 -> V_30 . V_98 > 1 ) {
F_13 ( L_16 ) ;
return 0 ;
}
if ( V_70 -> V_12 <= 2 )
V_71 = ( V_27 -> V_49 . V_85 << 16 ) + V_71 ;
V_95 = V_71 - V_27 -> V_30 . V_101 ;
if ( V_95 + V_27 -> V_30 . V_42 >= V_43 ) {
if ( F_20 ( & V_27 -> V_3 -> V_103 ) )
F_21 ( V_27 -> V_3 ,
L_17 ) ;
V_71 = V_43 - V_27 -> V_30 . V_42 +
V_27 -> V_30 . V_101 - 1 ;
if ( V_71 <= 0 ) {
F_5 ( V_27 -> V_3 ,
L_18 ) ;
return - 1 ;
}
}
for ( V_41 = V_27 -> V_30 . V_101 ; V_41 <= V_71 ; V_41 ++ )
if ( F_11 ( V_27 , V_41 ) ) {
F_13 ( L_19 ) ;
return - 1 ;
}
return 0 ;
default:
F_13 ( L_20 , V_70 -> V_77 ) ;
return 0 ;
}
return 0 ;
}
static int F_22 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
V_53 V_71 ;
int V_104 ;
V_71 = F_15 ( V_70 ) ;
switch ( V_70 -> V_77 ) {
case V_105 :
V_104 = F_6 ( V_27 , V_71 & 0xff ) ;
break;
case V_106 :
V_104 = F_9 ( V_27 ) ;
break;
case V_107 :
V_104 = F_12 ( V_27 , V_108 , V_71 ) ;
break;
case V_109 :
V_104 = F_12 ( V_27 , V_110 , V_71 ) ;
break;
case V_111 :
V_104 = F_12 ( V_27 , V_112 , V_71 ) ;
break;
default:
F_5 ( V_27 -> V_3 , L_21 , V_70 -> V_77 ) ;
V_104 = 0 ;
}
memset ( & V_27 -> V_30 , 0 , sizeof( V_27 -> V_30 ) ) ;
return V_104 ;
}
static int F_23 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
F_13 ( L_22 , V_70 -> V_77 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_7 )
{
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_19 ; V_41 ++ )
F_8 ( V_7 -> V_18 [ V_41 ] ) ;
F_8 ( V_7 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
unsigned V_48 , V_61 ;
for ( V_48 = 0 ; V_48 < V_113 ; V_48 ++ ) {
struct V_5 * V_6 = V_3 -> V_6 + V_48 ;
for ( V_61 = 0 ; V_61 < V_8 ; V_61 ++ ) {
struct V_1 * V_7 = V_6 -> V_9 [ V_61 ] ;
if ( V_7 )
F_24 ( V_7 ) ;
}
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_26 ( & V_6 -> V_14 ) ;
}
F_8 ( V_3 -> V_114 ) ;
V_3 -> V_114 = NULL ;
V_3 -> V_115 = 0 ;
F_8 ( V_3 -> V_29 ) ;
V_3 -> V_29 = NULL ;
V_3 -> V_35 = 0 ;
V_3 -> V_34 = 0 ;
V_3 -> V_40 = 0 ;
V_3 -> V_116 &= ~ V_117 ;
}
static void F_27 ( struct V_3 * V_103 )
{
struct V_2 * V_62 = F_28 ( V_103 ) ;
F_25 ( V_62 ) ;
F_8 ( V_62 -> V_118 ) ;
F_8 ( V_62 ) ;
}
static V_72 * F_29 ( T_3 * V_119 , T_3 * V_120 , struct V_69 * V_70 )
{
V_72 V_121 ;
if ( ( V_120 - V_119 ) <= 0 )
return NULL ;
V_121 = * V_119 ++ ;
V_70 -> type = ( V_121 >> 2 ) & 3 ;
V_70 -> V_77 = ( V_121 >> 4 ) & 15 ;
if ( V_70 -> V_77 == V_122 ) {
V_70 -> V_123 = V_124 ;
if ( ( V_120 - V_119 ) < 2 )
return NULL ;
V_70 -> V_12 = * V_119 ++ ;
V_70 -> V_77 = * V_119 ++ ;
if ( ( V_120 - V_119 ) < V_70 -> V_12 )
return NULL ;
V_70 -> V_71 . V_125 = V_119 ;
V_119 += V_70 -> V_12 ;
return V_119 ;
}
V_70 -> V_123 = V_126 ;
V_70 -> V_12 = V_121 & 3 ;
switch ( V_70 -> V_12 ) {
case 0 :
return V_119 ;
case 1 :
if ( ( V_120 - V_119 ) < 1 )
return NULL ;
V_70 -> V_71 . V_72 = * V_119 ++ ;
return V_119 ;
case 2 :
if ( ( V_120 - V_119 ) < 2 )
return NULL ;
V_70 -> V_71 . V_73 = F_30 ( V_119 ) ;
V_119 = ( T_3 * ) ( ( V_127 * ) V_119 + 1 ) ;
return V_119 ;
case 3 :
V_70 -> V_12 ++ ;
if ( ( V_120 - V_119 ) < 4 )
return NULL ;
V_70 -> V_71 . T_1 = F_31 ( V_119 ) ;
V_119 = ( T_3 * ) ( ( V_128 * ) V_119 + 1 ) ;
return V_119 ;
}
return NULL ;
}
static void F_32 ( struct V_26 * V_27 , T_1 V_23 )
{
struct V_2 * V_62 = V_27 -> V_3 ;
if ( V_23 == V_129 )
V_62 -> V_130 = V_131 ;
}
static void F_33 ( struct V_26 * V_27 , T_1 V_23 )
{
if ( V_23 == 0xff0000c5 && V_27 -> V_49 . V_55 == 256 &&
V_27 -> V_49 . V_54 == 8 )
V_27 -> V_132 |= V_133 ;
}
static void F_34 ( struct V_26 * V_27 , unsigned type )
{
struct V_2 * V_62 = V_27 -> V_3 ;
int V_48 ;
if ( ( ( V_27 -> V_49 . V_85 << 16 ) == V_134 ) &&
type == V_57 )
V_62 -> V_130 = V_135 ;
if ( V_62 -> V_136 == V_137 &&
V_62 -> V_138 == V_139 &&
V_62 -> V_130 == V_131 )
V_62 -> V_130 = V_140 ;
if ( ( V_27 -> V_49 . V_85 << 16 ) == V_141 )
for ( V_48 = 0 ; V_48 < V_27 -> V_30 . V_42 ; V_48 ++ )
if ( V_27 -> V_30 . V_23 [ V_48 ] == V_142 )
V_27 -> V_132 |= V_143 ;
if ( ( V_27 -> V_49 . V_85 << 16 ) >= V_144 )
V_27 -> V_132 |= V_145 ;
}
static int F_35 ( struct V_26 * V_27 , struct V_69 * V_70 )
{
V_53 V_71 ;
int V_48 ;
V_71 = F_15 ( V_70 ) ;
switch ( V_70 -> V_77 ) {
case V_105 :
F_34 ( V_27 , V_71 & 0xff ) ;
break;
case V_106 :
break;
case V_107 :
if ( V_71 & V_146 )
break;
for ( V_48 = 0 ; V_48 < V_27 -> V_30 . V_42 ; V_48 ++ )
F_32 ( V_27 , V_27 -> V_30 . V_23 [ V_48 ] ) ;
break;
case V_109 :
break;
case V_111 :
for ( V_48 = 0 ; V_48 < V_27 -> V_30 . V_42 ; V_48 ++ )
F_33 ( V_27 , V_27 -> V_30 . V_23 [ V_48 ] ) ;
break;
}
memset ( & V_27 -> V_30 , 0 , sizeof( V_27 -> V_30 ) ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_62 )
{
struct V_26 * V_27 ;
struct V_69 V_70 ;
T_3 * V_119 = V_62 -> V_118 ;
T_3 * V_120 = V_119 + V_62 -> V_147 ;
static int (* F_37 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_35 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
struct V_1 * F_38 ( struct V_2 * V_62 ,
unsigned int type , unsigned int V_4 ,
unsigned int V_148 ,
unsigned int V_149 )
{
struct V_1 * V_7 ;
if ( type > V_112 ) {
F_5 ( V_62 , L_23 , type ) ;
return NULL ;
}
if ( V_4 >= V_8 ) {
F_5 ( V_62 , L_24 , V_4 ) ;
return NULL ;
}
if ( V_4 == 0 ) {
V_7 = F_39 (
V_62 -> V_6 [ type ] . V_14 . V_150 ,
struct V_1 , V_13 ) ;
} else {
V_7 = V_62 -> V_6 [ type ] . V_9 [ V_4 ] ;
}
if ( ! V_7 ) {
F_5 ( V_62 , L_25 , V_151 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_19 <= V_148 ) {
F_5 ( V_62 , L_26 ,
V_151 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_18 [ V_148 ] -> V_55 < V_149 ) {
F_5 ( V_62 , L_27 ,
V_151 [ type ] , V_4 , V_148 ) ;
return NULL ;
}
return V_7 ;
}
int F_40 ( struct V_2 * V_3 )
{
struct V_26 * V_27 ;
struct V_69 V_70 ;
unsigned int V_12 ;
T_3 * V_119 ;
T_3 * V_152 ;
T_3 * V_120 ;
int V_104 ;
static int (* F_37 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_22 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
static V_25 F_41 ( V_53 V_24 , unsigned V_41 )
{
switch ( V_41 ) {
case 8 : return ( ( V_153 ) V_24 ) ;
case 16 : return ( ( V_154 ) V_24 ) ;
case 32 : return ( ( T_2 ) V_24 ) ;
}
return V_24 & ( 1 << ( V_41 - 1 ) ) ? V_24 | ( - 1 << V_41 ) : V_24 ;
}
V_25 F_18 ( V_53 V_24 , unsigned V_41 )
{
return F_41 ( V_24 , V_41 ) ;
}
static T_1 F_42 ( T_2 V_24 , unsigned V_41 )
{
V_25 V_155 = V_24 >> ( V_41 - 1 ) ;
if ( V_155 && V_155 != - 1 )
return V_24 < 0 ? 1 << ( V_41 - 1 ) : ( 1 << ( V_41 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_41 ) - 1 ) ;
}
static T_1 F_43 ( V_72 * V_7 , unsigned V_47 , int V_41 )
{
unsigned int V_156 = V_47 / 8 ;
unsigned int V_157 = 0 ;
unsigned int V_158 = V_47 % 8 ;
int V_159 = 8 - V_158 ;
T_1 V_24 = 0 ;
T_1 V_160 = V_41 < 32 ? ( 1U << V_41 ) - 1 : ~ 0U ;
while ( V_41 > 0 ) {
V_24 |= ( ( T_1 ) V_7 [ V_156 ] >> V_158 ) << V_157 ;
V_41 -= V_159 ;
V_157 += V_159 ;
V_159 = 8 ;
V_158 = 0 ;
V_156 ++ ;
}
return V_24 & V_160 ;
}
T_1 F_44 ( const struct V_2 * V_62 , V_72 * V_7 ,
unsigned V_47 , unsigned V_41 )
{
if ( V_41 > 32 ) {
F_21 ( V_62 , L_28 ,
V_41 , V_161 -> V_162 ) ;
V_41 = 32 ;
}
return F_43 ( V_7 , V_47 , V_41 ) ;
}
static void F_45 ( V_72 * V_7 , unsigned V_47 , int V_41 , T_1 V_24 )
{
unsigned int V_156 = V_47 / 8 ;
unsigned int V_158 = V_47 % 8 ;
int V_163 = 8 - V_158 ;
while ( V_41 - V_163 >= 0 ) {
V_7 [ V_156 ] &= ~ ( 0xff << V_158 ) ;
V_7 [ V_156 ] |= V_24 << V_158 ;
V_24 >>= V_163 ;
V_41 -= V_163 ;
V_163 = 8 ;
V_158 = 0 ;
V_156 ++ ;
}
if ( V_41 ) {
V_72 V_164 = ( ( 1U << V_41 ) - 1 ) ;
V_7 [ V_156 ] &= ~ ( V_164 << V_158 ) ;
V_7 [ V_156 ] |= V_24 << V_158 ;
}
}
static void F_46 ( const struct V_2 * V_62 , V_72 * V_7 ,
unsigned V_47 , unsigned V_41 , T_1 V_24 )
{
if ( F_47 ( V_41 > 32 ) ) {
F_21 ( V_62 , L_29 ,
V_165 , V_41 , V_161 -> V_162 ) ;
V_41 = 32 ;
} else if ( V_41 < 32 ) {
T_1 V_166 = ( 1U << V_41 ) - 1 ;
if ( F_47 ( V_24 > V_166 ) ) {
F_21 ( V_62 ,
L_30 ,
V_165 , V_24 , V_41 , V_161 -> V_162 ) ;
F_48 ( 1 ) ;
V_24 &= V_166 ;
}
}
F_45 ( V_7 , V_47 , V_41 , V_24 ) ;
}
static int F_49 ( T_2 * V_167 , T_2 V_24 , unsigned V_41 )
{
while ( V_41 -- ) {
if ( * V_167 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_50 ( struct V_2 * V_62 , struct V_1 * V_7 )
{
const struct V_168 * V_4 = V_62 -> V_169 -> V_170 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_171 ; V_4 ++ )
if ( V_4 -> V_45 == V_172 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_51 ( struct V_2 * V_62 , struct V_21 * V_23 )
{
const struct V_173 * V_4 = V_62 -> V_169 -> V_174 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_175 != V_172 - 1 ; V_4 ++ )
if ( ( V_4 -> V_176 == V_172 ||
V_4 -> V_176 == V_23 -> V_62 ) &&
( V_4 -> V_175 == V_172 ||
V_4 -> V_175 == V_23 -> type ) &&
( V_4 -> V_177 == V_172 ||
V_4 -> V_177 == V_23 -> V_178 ) )
return 1 ;
return 0 ;
}
static void F_52 ( struct V_2 * V_62 , struct V_15 * V_18 ,
struct V_21 * V_23 , T_2 V_24 , int V_179 )
{
struct V_180 * V_181 = V_62 -> V_169 ;
int V_104 ;
if ( ! F_53 ( & V_62 -> V_182 ) )
F_54 ( V_62 , V_23 , V_24 ) ;
if ( V_181 && V_181 -> V_183 && F_51 ( V_62 , V_23 ) ) {
V_104 = V_181 -> V_183 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_104 != 0 ) {
if ( V_104 < 0 )
F_5 ( V_62 , L_31 ,
V_181 -> V_184 , V_104 ) ;
return;
}
}
if ( V_62 -> V_185 & V_186 )
F_55 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_62 -> V_185 & V_187 && V_179 && V_62 -> V_188 )
V_62 -> V_188 ( V_62 , V_18 , V_23 , V_24 ) ;
}
static void F_56 ( struct V_2 * V_62 , struct V_15 * V_18 ,
T_3 * V_71 , int V_179 )
{
unsigned V_41 ;
unsigned V_95 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
T_2 V_189 = V_18 -> V_51 ;
T_2 V_190 = V_18 -> V_52 ;
T_2 * V_24 ;
V_24 = F_7 ( sizeof( T_2 ) * V_95 , V_191 ) ;
if ( ! V_24 )
return;
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
V_24 [ V_41 ] = V_189 < 0 ?
F_41 ( F_44 ( V_62 , V_71 , V_47 + V_41 * V_12 ,
V_12 ) , V_12 ) :
F_44 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ;
if ( ! ( V_18 -> V_46 & V_192 ) &&
V_24 [ V_41 ] >= V_189 && V_24 [ V_41 ] <= V_190 &&
V_24 [ V_41 ] - V_189 < V_18 -> V_63 &&
V_18 -> V_23 [ V_24 [ V_41 ] - V_189 ] . V_62 == V_193 + 1 )
goto exit;
}
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
if ( V_192 & V_18 -> V_46 ) {
F_52 ( V_62 , V_18 , & V_18 -> V_23 [ V_41 ] , V_24 [ V_41 ] , V_179 ) ;
continue;
}
if ( V_18 -> V_24 [ V_41 ] >= V_189 && V_18 -> V_24 [ V_41 ] <= V_190
&& V_18 -> V_24 [ V_41 ] - V_189 < V_18 -> V_63
&& V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_189 ] . V_62
&& F_49 ( V_24 , V_18 -> V_24 [ V_41 ] , V_95 ) )
F_52 ( V_62 , V_18 , & V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_189 ] , 0 , V_179 ) ;
if ( V_24 [ V_41 ] >= V_189 && V_24 [ V_41 ] <= V_190
&& V_24 [ V_41 ] - V_189 < V_18 -> V_63
&& V_18 -> V_23 [ V_24 [ V_41 ] - V_189 ] . V_62
&& F_49 ( V_18 -> V_24 , V_24 [ V_41 ] , V_95 ) )
F_52 ( V_62 , V_18 , & V_18 -> V_23 [ V_24 [ V_41 ] - V_189 ] , 1 , V_179 ) ;
}
memcpy ( V_18 -> V_24 , V_24 , V_95 * sizeof( T_2 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_57 ( const struct V_2 * V_62 ,
struct V_15 * V_18 , T_3 * V_71 )
{
unsigned V_95 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
if ( V_18 -> V_51 < 0 )
F_46 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
F_42 ( V_18 -> V_24 [ V_41 ] , V_12 ) ) ;
else
F_46 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
V_18 -> V_24 [ V_41 ] ) ;
}
}
void F_58 ( struct V_1 * V_7 , T_3 * V_71 )
{
unsigned V_41 ;
if ( V_7 -> V_4 > 0 )
* V_71 ++ = V_7 -> V_4 ;
memset ( V_71 , 0 , ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ) ;
for ( V_41 = 0 ; V_41 < V_7 -> V_19 ; V_41 ++ )
F_57 ( V_7 -> V_3 , V_7 -> V_18 [ V_41 ] , V_71 ) ;
}
V_72 * F_59 ( struct V_1 * V_7 , T_4 V_46 )
{
int V_194 = F_60 ( V_7 ) + 7 ;
return F_7 ( V_194 , V_46 ) ;
}
int F_61 ( struct V_15 * V_18 , unsigned V_47 , T_2 V_24 )
{
unsigned V_12 ;
if ( ! V_18 )
return - 1 ;
V_12 = V_18 -> V_54 ;
F_54 ( V_18 -> V_7 -> V_3 , V_18 -> V_23 + V_47 , V_24 ) ;
if ( V_47 >= V_18 -> V_55 ) {
F_5 ( V_18 -> V_7 -> V_3 , L_32 ,
V_47 , V_18 -> V_55 ) ;
return - 1 ;
}
if ( V_18 -> V_51 < 0 ) {
if ( V_24 != F_41 ( F_42 ( V_24 , V_12 ) , V_12 ) ) {
F_5 ( V_18 -> V_7 -> V_3 , L_33 , V_24 ) ;
return - 1 ;
}
}
V_18 -> V_24 [ V_47 ] = V_24 ;
return 0 ;
}
static struct V_1 * F_62 ( struct V_5 * V_6 ,
const V_72 * V_71 )
{
struct V_1 * V_7 ;
unsigned int V_41 = 0 ;
if ( V_6 -> V_11 )
V_41 = * V_71 ;
V_7 = V_6 -> V_9 [ V_41 ] ;
if ( V_7 == NULL )
F_13 ( L_34 , V_41 ) ;
return V_7 ;
}
void F_63 ( struct V_2 * V_62 , struct V_1 * V_7 ,
int V_195 )
{
char * V_152 ;
int V_104 ;
int V_194 ;
V_152 = F_59 ( V_7 , V_10 ) ;
if ( ! V_152 )
return;
V_194 = F_60 ( V_7 ) ;
if ( V_195 == V_196 )
F_58 ( V_7 , V_152 ) ;
V_104 = V_62 -> V_197 -> V_198 ( V_62 , V_7 -> V_4 , V_152 , V_194 ,
V_7 -> type , V_195 ) ;
if ( V_104 < 0 ) {
F_13 ( L_35 , V_104 ) ;
goto V_199;
}
if ( V_195 == V_200 )
F_64 ( V_62 , V_7 -> type , V_152 , V_104 , 0 ) ;
V_199:
F_8 ( V_152 ) ;
}
int F_65 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 ,
int V_179 )
{
struct V_5 * V_6 = V_62 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_180 * V_181 ;
unsigned int V_155 ;
int V_115 , V_201 = V_12 ;
V_72 * V_202 = V_71 ;
int V_104 = 0 ;
V_7 = F_62 ( V_6 , V_71 ) ;
if ( ! V_7 )
goto V_199;
if ( V_6 -> V_11 ) {
V_202 ++ ;
V_201 -- ;
}
V_115 = ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ;
if ( V_115 > V_203 )
V_115 = V_203 ;
if ( V_201 < V_115 ) {
F_13 ( L_36 , V_7 -> V_4 ,
V_201 , V_115 ) ;
memset ( V_202 + V_201 , 0 , V_115 - V_201 ) ;
}
if ( ( V_62 -> V_185 & V_187 ) && V_62 -> V_204 )
V_62 -> V_204 ( V_62 , V_7 ) ;
if ( V_62 -> V_185 & V_205 ) {
V_104 = F_66 ( V_62 , V_71 , V_12 ) ;
if ( V_104 )
goto V_199;
}
if ( V_62 -> V_185 != V_205 && V_7 -> V_19 ) {
for ( V_155 = 0 ; V_155 < V_7 -> V_19 ; V_155 ++ )
F_56 ( V_62 , V_7 -> V_18 [ V_155 ] , V_202 , V_179 ) ;
V_181 = V_62 -> V_169 ;
if ( V_181 && V_181 -> V_7 )
V_181 -> V_7 ( V_62 , V_7 ) ;
}
if ( V_62 -> V_185 & V_186 )
F_67 ( V_62 , V_7 ) ;
V_199:
return V_104 ;
}
int F_64 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 , int V_179 )
{
struct V_5 * V_6 ;
struct V_180 * V_181 ;
struct V_1 * V_7 ;
int V_104 = 0 ;
if ( ! V_62 )
return - V_206 ;
if ( F_68 ( & V_62 -> V_207 ) )
return - V_208 ;
if ( ! V_62 -> V_169 ) {
V_104 = - V_206 ;
goto V_209;
}
V_6 = V_62 -> V_6 + type ;
V_181 = V_62 -> V_169 ;
if ( ! V_12 ) {
F_13 ( L_37 ) ;
V_104 = - 1 ;
goto V_209;
}
if ( ! F_53 ( & V_62 -> V_182 ) )
F_69 ( V_62 , type , V_71 , V_12 ) ;
V_7 = F_62 ( V_6 , V_71 ) ;
if ( ! V_7 ) {
V_104 = - 1 ;
goto V_209;
}
if ( V_181 && V_181 -> V_210 && F_50 ( V_62 , V_7 ) ) {
V_104 = V_181 -> V_210 ( V_62 , V_7 , V_71 , V_12 ) ;
if ( V_104 < 0 )
goto V_209;
}
V_104 = F_65 ( V_62 , type , V_71 , V_12 , V_179 ) ;
V_209:
F_70 ( & V_62 -> V_207 ) ;
return V_104 ;
}
static bool F_71 ( struct V_2 * V_211 ,
const struct V_212 * V_4 )
{
return ( V_4 -> V_213 == V_214 || V_4 -> V_213 == V_211 -> V_213 ) &&
( V_4 -> V_130 == V_215 || V_4 -> V_130 == V_211 -> V_130 ) &&
( V_4 -> V_136 == V_172 || V_4 -> V_136 == V_211 -> V_136 ) &&
( V_4 -> V_138 == V_172 || V_4 -> V_138 == V_211 -> V_138 ) ;
}
const struct V_212 * F_72 ( struct V_2 * V_211 ,
const struct V_212 * V_4 )
{
for (; V_4 -> V_213 ; V_4 ++ )
if ( F_71 ( V_211 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_73 ( struct V_2 * V_211 )
{
return ! ! F_72 ( V_211 , V_216 ) ;
}
static T_5
F_74 ( struct V_217 * V_218 , struct V_219 * V_220 ,
struct V_221 * V_222 ,
char * V_152 , T_6 V_223 , T_7 V_95 )
{
struct V_3 * V_103 = F_75 ( V_220 ) ;
struct V_2 * V_211 = F_28 ( V_103 ) ;
if ( V_223 >= V_211 -> V_115 )
return 0 ;
if ( V_223 + V_95 > V_211 -> V_115 )
V_95 = V_211 -> V_115 - V_223 ;
memcpy ( V_152 , V_211 -> V_114 + V_223 , V_95 ) ;
return V_95 ;
}
static T_5
F_76 ( struct V_3 * V_103 , struct V_224 * V_222 ,
char * V_152 )
{
struct V_2 * V_211 = F_28 ( V_103 ) ;
return sprintf ( V_152 , L_38 , V_211 -> V_225 & 0xff ) ;
}
int F_77 ( struct V_2 * V_211 , unsigned int V_226 )
{
static const char * V_227 [] = { L_39 , L_40 , L_41 , L_39 ,
L_42 , L_43 , L_44 , L_45 ,
L_46
} ;
const char * type , * V_213 ;
char V_152 [ 64 ] = L_47 ;
unsigned int V_48 ;
int V_194 ;
int V_104 ;
if ( V_211 -> V_228 & V_229 )
V_226 |= ( V_230 | V_231 ) ;
if ( V_211 -> V_228 & V_232 )
V_226 |= V_233 ;
if ( V_211 -> V_213 != V_234 )
V_226 &= ~ V_231 ;
if ( F_73 ( V_211 ) )
V_226 |= V_230 ;
if ( ( V_226 & V_235 ) && ! F_78 ( V_211 ,
V_226 & V_233 ) )
V_211 -> V_185 |= V_186 ;
if ( ( V_226 & V_231 ) && V_211 -> V_236 &&
! V_211 -> V_236 ( V_211 ,
V_226 & V_230 ) )
V_211 -> V_185 |= V_187 ;
if ( ( V_226 & V_237 ) && ! F_79 ( V_211 ) )
V_211 -> V_185 |= V_205 ;
if ( V_226 & V_238 )
V_211 -> V_185 |= V_239 ;
if ( ! V_211 -> V_185 && ! V_211 -> V_169 -> V_210 ) {
F_5 ( V_211 , L_48 ) ;
return - V_206 ;
}
if ( ( V_211 -> V_185 & V_186 ) &&
( V_226 & V_240 ) && V_211 -> V_241 )
V_211 -> V_241 ( V_211 ) ;
V_194 = 0 ;
if ( V_211 -> V_185 & V_186 )
V_194 += sprintf ( V_152 + V_194 , L_49 ) ;
if ( V_211 -> V_185 & V_187 )
V_194 += sprintf ( V_152 + V_194 , L_50 , V_194 ? L_51 : L_47 ,
( (struct V_242 * ) V_211 -> V_242 ) -> V_243 ) ;
if ( V_211 -> V_185 & V_205 )
V_194 += sprintf ( V_152 + V_194 , L_52 , V_194 ? L_51 : L_47 ,
( (struct V_244 * ) V_211 -> V_244 ) -> V_243 ) ;
type = L_39 ;
for ( V_48 = 0 ; V_48 < V_211 -> V_34 ; V_48 ++ ) {
struct V_28 * V_245 = & V_211 -> V_29 [ V_48 ] ;
if ( V_245 -> type == V_39 &&
( V_245 -> V_23 & V_246 ) == V_141 &&
( V_245 -> V_23 & 0xffff ) < F_80 ( V_227 ) ) {
type = V_227 [ V_245 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_211 -> V_213 ) {
case V_234 :
V_213 = L_53 ;
break;
case V_247 :
V_213 = L_54 ;
break;
case V_248 :
V_213 = L_55 ;
break;
default:
V_213 = L_56 ;
}
V_104 = F_81 ( & V_211 -> V_103 , & V_249 ) ;
if ( V_104 )
F_21 ( V_211 ,
L_57 , V_104 ) ;
F_82 ( V_211 , L_58 ,
V_152 , V_213 , V_211 -> V_250 >> 8 , V_211 -> V_250 & 0xff ,
type , V_211 -> V_184 , V_211 -> V_251 ) ;
return 0 ;
}
void F_83 ( struct V_2 * V_211 )
{
F_84 ( & V_211 -> V_103 , & V_249 ) ;
if ( V_211 -> V_185 & V_186 )
F_85 ( V_211 ) ;
if ( V_211 -> V_185 & V_187 )
V_211 -> V_252 ( V_211 ) ;
if ( V_211 -> V_185 & V_205 )
F_86 ( V_211 ) ;
V_211 -> V_185 = 0 ;
}
static T_5 F_87 ( struct V_253 * V_254 , const char * V_152 ,
T_7 V_95 )
{
struct V_180 * V_181 = F_88 ( V_254 ) ;
struct V_255 * V_256 ;
V_53 V_213 , V_136 , V_138 ;
unsigned long V_257 = 0 ;
int V_104 ;
V_104 = sscanf ( V_152 , L_59 ,
& V_213 , & V_136 , & V_138 , & V_257 ) ;
if ( V_104 < 3 )
return - V_33 ;
V_256 = F_2 ( sizeof( * V_256 ) , V_10 ) ;
if ( ! V_256 )
return - V_36 ;
V_256 -> V_4 . V_213 = V_213 ;
V_256 -> V_4 . V_130 = V_215 ;
V_256 -> V_4 . V_136 = V_136 ;
V_256 -> V_4 . V_138 = V_138 ;
V_256 -> V_4 . V_257 = V_257 ;
F_89 ( & V_181 -> V_258 ) ;
F_3 ( & V_256 -> V_13 , & V_181 -> V_259 ) ;
F_90 ( & V_181 -> V_258 ) ;
V_104 = F_91 ( & V_181 -> V_169 ) ;
return V_104 ? : V_95 ;
}
static void F_92 ( struct V_180 * V_181 )
{
struct V_255 * V_256 , * V_41 ;
F_89 ( & V_181 -> V_258 ) ;
F_93 (dynid, n, &hdrv->dyn_list, list) {
F_94 ( & V_256 -> V_13 ) ;
F_8 ( V_256 ) ;
}
F_90 ( & V_181 -> V_258 ) ;
}
static const struct V_212 * F_95 ( struct V_2 * V_211 ,
struct V_180 * V_181 )
{
struct V_255 * V_256 ;
F_89 ( & V_181 -> V_258 ) ;
F_96 (dynid, &hdrv->dyn_list, list) {
if ( F_71 ( V_211 , & V_256 -> V_4 ) ) {
F_90 ( & V_181 -> V_258 ) ;
return & V_256 -> V_4 ;
}
}
F_90 ( & V_181 -> V_258 ) ;
return F_72 ( V_211 , V_181 -> V_260 ) ;
}
static int F_97 ( struct V_3 * V_103 , struct V_253 * V_254 )
{
struct V_180 * V_181 = F_88 ( V_254 ) ;
struct V_2 * V_211 = F_28 ( V_103 ) ;
return F_95 ( V_211 , V_181 ) != NULL ;
}
static int F_98 ( struct V_3 * V_103 )
{
struct V_180 * V_181 = F_88 ( V_103 -> V_169 ) ;
struct V_2 * V_211 = F_28 ( V_103 ) ;
const struct V_212 * V_4 ;
int V_104 = 0 ;
if ( F_99 ( & V_211 -> V_261 ) )
return - V_262 ;
if ( F_99 ( & V_211 -> V_207 ) ) {
V_104 = - V_262 ;
goto V_263;
}
V_211 -> V_264 = false ;
if ( ! V_211 -> V_169 ) {
V_4 = F_95 ( V_211 , V_181 ) ;
if ( V_4 == NULL ) {
V_104 = - V_206 ;
goto V_209;
}
V_211 -> V_169 = V_181 ;
if ( V_181 -> V_265 ) {
V_104 = V_181 -> V_265 ( V_211 , V_4 ) ;
} else {
V_104 = F_40 ( V_211 ) ;
if ( ! V_104 )
V_104 = F_100 ( V_211 , V_266 ) ;
}
if ( V_104 ) {
F_25 ( V_211 ) ;
V_211 -> V_169 = NULL ;
}
}
V_209:
if ( ! V_211 -> V_264 )
F_70 ( & V_211 -> V_207 ) ;
V_263:
F_70 ( & V_211 -> V_261 ) ;
return V_104 ;
}
static int F_101 ( struct V_3 * V_103 )
{
struct V_2 * V_211 = F_28 ( V_103 ) ;
struct V_180 * V_181 ;
int V_104 = 0 ;
if ( F_99 ( & V_211 -> V_261 ) )
return - V_262 ;
if ( F_99 ( & V_211 -> V_207 ) ) {
V_104 = - V_262 ;
goto V_263;
}
V_211 -> V_264 = false ;
V_181 = V_211 -> V_169 ;
if ( V_181 ) {
if ( V_181 -> remove )
V_181 -> remove ( V_211 ) ;
else
F_102 ( V_211 ) ;
F_25 ( V_211 ) ;
V_211 -> V_169 = NULL ;
}
if ( ! V_211 -> V_264 )
F_70 ( & V_211 -> V_207 ) ;
V_263:
F_70 ( & V_211 -> V_261 ) ;
return V_104 ;
}
static T_5 F_103 ( struct V_3 * V_103 , struct V_224 * V_155 ,
char * V_152 )
{
struct V_2 * V_211 = F_104 ( V_103 , struct V_2 , V_103 ) ;
return F_105 ( V_152 , V_267 , L_60 ,
V_211 -> V_213 , V_211 -> V_130 , V_211 -> V_136 , V_211 -> V_138 ) ;
}
static int F_106 ( struct V_3 * V_103 , struct V_268 * V_269 )
{
struct V_2 * V_211 = F_28 ( V_103 ) ;
if ( F_107 ( V_269 , L_61 ,
V_211 -> V_213 , V_211 -> V_136 , V_211 -> V_138 ) )
return - V_36 ;
if ( F_107 ( V_269 , L_62 , V_211 -> V_184 ) )
return - V_36 ;
if ( F_107 ( V_269 , L_63 , V_211 -> V_251 ) )
return - V_36 ;
if ( F_107 ( V_269 , L_64 , V_211 -> V_270 ) )
return - V_36 ;
if ( F_107 ( V_269 , L_65 ,
V_211 -> V_213 , V_211 -> V_130 , V_211 -> V_136 , V_211 -> V_138 ) )
return - V_36 ;
return 0 ;
}
bool F_108 ( struct V_2 * V_211 )
{
if ( V_211 -> V_228 & V_271 )
return false ;
if ( V_211 -> V_228 & V_272 )
return true ;
switch ( V_211 -> V_136 ) {
case V_273 :
if ( V_211 -> V_138 >= V_274 &&
V_211 -> V_138 <= V_275 )
return true ;
break;
case V_276 :
if ( V_211 -> V_138 >= V_277 &&
V_211 -> V_138 <= V_278 )
return true ;
if ( V_211 -> V_138 == V_279 &&
! strcmp ( V_211 -> V_184 , L_66 ) )
return true ;
break;
case V_280 :
if ( V_211 -> V_138 >= V_281 &&
V_211 -> V_138 <= V_282 )
return true ;
break;
case V_283 :
if ( V_211 -> V_138 >= V_284 &&
V_211 -> V_138 <= V_285 )
return true ;
break;
case V_286 :
if ( V_211 -> V_138 == V_287 &&
V_211 -> type == V_288 )
return true ;
break;
case V_289 :
if ( ( V_211 -> V_138 >= V_290 &&
V_211 -> V_138 <= V_291 ) ||
( V_211 -> V_138 >= V_292 &&
V_211 -> V_138 <= V_293 ) )
return true ;
break;
case V_294 :
if ( V_211 -> V_138 == V_295 &&
V_211 -> V_213 == V_234 &&
strncmp ( V_211 -> V_184 , L_67 , 22 ) == 0 )
return true ;
break;
}
if ( V_211 -> type == V_296 &&
F_72 ( V_211 , V_297 ) )
return true ;
return ! ! F_72 ( V_211 , V_298 ) ;
}
int F_109 ( struct V_2 * V_211 )
{
static T_8 V_4 = F_110 ( 0 ) ;
int V_104 ;
if ( F_48 ( V_211 -> V_116 & V_299 ) )
return - V_208 ;
if ( F_108 ( V_211 ) )
return - V_206 ;
if ( ! V_211 -> V_197 -> V_198 ) {
F_5 ( V_211 , L_68 ) ;
return - V_33 ;
}
V_104 = V_211 -> V_197 -> V_300 ( V_211 ) ;
if ( V_104 )
return V_104 ;
if ( ! V_211 -> V_118 )
return - V_206 ;
if ( V_301 ) {
V_211 -> V_130 = V_140 ;
} else if ( ! V_211 -> V_130 &&
! F_72 ( V_211 , V_302 ) ) {
V_104 = F_36 ( V_211 ) ;
if ( V_104 )
F_21 ( V_211 , L_69 , V_104 ) ;
}
F_111 ( & V_211 -> V_103 , L_70 , V_211 -> V_213 ,
V_211 -> V_136 , V_211 -> V_138 , F_112 ( & V_4 ) ) ;
F_113 ( V_211 , F_20 ( & V_211 -> V_103 ) ) ;
V_104 = F_114 ( & V_211 -> V_103 ) ;
if ( ! V_104 )
V_211 -> V_116 |= V_299 ;
else
F_115 ( V_211 ) ;
return V_104 ;
}
struct V_2 * F_116 ( void )
{
struct V_2 * V_211 ;
int V_104 = - V_36 ;
V_211 = F_2 ( sizeof( * V_211 ) , V_10 ) ;
if ( V_211 == NULL )
return F_117 ( V_104 ) ;
F_118 ( & V_211 -> V_103 ) ;
V_211 -> V_103 . V_303 = F_27 ;
V_211 -> V_103 . V_213 = & V_304 ;
F_119 ( & V_211 -> V_103 ) ;
F_25 ( V_211 ) ;
F_120 ( & V_211 -> V_305 ) ;
F_26 ( & V_211 -> V_182 ) ;
F_121 ( & V_211 -> V_306 ) ;
F_122 ( & V_211 -> V_261 , 1 ) ;
F_122 ( & V_211 -> V_207 , 1 ) ;
return V_211 ;
}
static void F_123 ( struct V_2 * V_211 )
{
if ( V_211 -> V_116 & V_299 ) {
F_124 ( & V_211 -> V_103 ) ;
F_115 ( V_211 ) ;
V_211 -> V_116 &= ~ V_299 ;
}
F_8 ( V_211 -> V_118 ) ;
V_211 -> V_118 = NULL ;
V_211 -> V_147 = 0 ;
}
void F_125 ( struct V_2 * V_211 )
{
F_123 ( V_211 ) ;
F_126 ( & V_211 -> V_103 ) ;
}
int F_127 ( struct V_180 * V_181 , struct V_307 * V_308 ,
const char * V_309 )
{
int V_104 ;
V_181 -> V_169 . V_184 = V_181 -> V_184 ;
V_181 -> V_169 . V_213 = & V_304 ;
V_181 -> V_169 . V_308 = V_308 ;
V_181 -> V_169 . V_309 = V_309 ;
F_26 ( & V_181 -> V_259 ) ;
F_121 ( & V_181 -> V_258 ) ;
V_104 = F_128 ( & V_181 -> V_169 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_129 ( & V_181 -> V_169 , & V_310 ) ;
if ( V_104 )
F_130 ( & V_181 -> V_169 ) ;
return V_104 ;
}
void F_131 ( struct V_180 * V_181 )
{
F_132 ( & V_181 -> V_169 , & V_310 ) ;
F_130 ( & V_181 -> V_169 ) ;
F_92 ( V_181 ) ;
}
int F_133 ( struct V_2 * V_62 )
{
struct V_311 * V_312 ;
int V_48 ;
if ( ! ( V_62 -> V_185 & V_186 ) )
return 0 ;
F_96 (hidinput, &hid->inputs, list) {
for ( V_48 = 0 ; V_48 < F_134 ( V_313 ) ; V_48 ++ )
if ( V_312 -> V_314 -> V_315 [ V_48 ] )
return 1 ;
}
return 0 ;
}
static int T_9 F_135 ( void )
{
int V_104 ;
if ( V_316 )
F_136 ( L_71
L_72 ) ;
V_104 = F_137 ( & V_304 ) ;
if ( V_104 ) {
F_138 ( L_73 ) ;
goto V_317;
}
V_104 = F_139 () ;
if ( V_104 )
goto V_318;
F_140 () ;
return 0 ;
V_318:
F_141 ( & V_304 ) ;
V_317:
return V_104 ;
}
static void T_10 F_142 ( void )
{
F_143 () ;
F_144 () ;
F_141 ( & V_304 ) ;
}
