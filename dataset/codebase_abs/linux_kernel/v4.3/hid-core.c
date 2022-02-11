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
struct V_2 * V_62 = F_28 ( V_103 , struct V_2 , V_103 ) ;
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
( V_62 -> V_138 == V_139 ||
V_62 -> V_138 == V_140 ||
V_62 -> V_138 == V_141 ||
V_62 -> V_138 == V_142 ) &&
V_62 -> V_130 == V_131 )
V_62 -> V_130 = V_143 ;
if ( ( V_27 -> V_49 . V_85 << 16 ) == V_144 )
for ( V_48 = 0 ; V_48 < V_27 -> V_30 . V_42 ; V_48 ++ )
if ( V_27 -> V_30 . V_23 [ V_48 ] == V_145 )
V_27 -> V_132 |= V_146 ;
if ( ( V_27 -> V_49 . V_85 << 16 ) >= V_147 )
V_27 -> V_132 |= V_148 ;
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
if ( V_71 & V_149 )
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
T_3 * V_120 = V_119 + V_62 -> V_150 ;
static int (* F_37 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_35 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
struct V_1 * F_38 ( struct V_2 * V_62 ,
unsigned int type , unsigned int V_4 ,
unsigned int V_151 ,
unsigned int V_152 )
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
V_62 -> V_6 [ type ] . V_14 . V_153 ,
struct V_1 , V_13 ) ;
} else {
V_7 = V_62 -> V_6 [ type ] . V_9 [ V_4 ] ;
}
if ( ! V_7 ) {
F_5 ( V_62 , L_25 , V_154 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_19 <= V_151 ) {
F_5 ( V_62 , L_26 ,
V_154 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_18 [ V_151 ] -> V_55 < V_152 ) {
F_5 ( V_62 , L_27 ,
V_154 [ type ] , V_4 , V_151 ) ;
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
T_3 * V_155 ;
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
case 8 : return ( ( V_156 ) V_24 ) ;
case 16 : return ( ( V_157 ) V_24 ) ;
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
V_25 V_158 = V_24 >> ( V_41 - 1 ) ;
if ( V_158 && V_158 != - 1 )
return V_24 < 0 ? 1 << ( V_41 - 1 ) : ( 1 << ( V_41 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_41 ) - 1 ) ;
}
V_53 F_43 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 )
{
T_4 V_159 ;
if ( V_41 > 32 )
F_21 ( V_62 , L_28 ,
V_41 , V_160 -> V_161 ) ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_159 = F_44 ( V_7 ) ;
V_159 = ( V_159 >> V_47 ) & ( ( 1ULL << V_41 ) - 1 ) ;
return ( T_1 ) V_159 ;
}
static void F_45 ( const struct V_2 * V_62 , T_3 * V_7 ,
unsigned V_47 , unsigned V_41 , V_53 V_24 )
{
T_4 V_159 ;
T_4 V_162 = ( 1ULL << V_41 ) - 1 ;
if ( V_41 > 32 )
F_21 ( V_62 , L_29 ,
V_163 , V_41 , V_160 -> V_161 ) ;
if ( V_24 > V_162 )
F_21 ( V_62 , L_30 ,
V_163 , V_24 , V_160 -> V_161 ) ;
F_46 ( V_24 > V_162 ) ;
V_24 &= V_162 ;
V_7 += V_47 >> 3 ;
V_47 &= 7 ;
V_159 = F_44 ( V_7 ) ;
V_159 &= ~ ( V_162 << V_47 ) ;
V_159 |= ( ( T_4 ) V_24 ) << V_47 ;
F_47 ( V_159 , V_7 ) ;
}
static int F_48 ( T_2 * V_164 , T_2 V_24 , unsigned V_41 )
{
while ( V_41 -- ) {
if ( * V_164 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_49 ( struct V_2 * V_62 , struct V_1 * V_7 )
{
const struct V_165 * V_4 = V_62 -> V_166 -> V_167 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_168 ; V_4 ++ )
if ( V_4 -> V_45 == V_169 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_50 ( struct V_2 * V_62 , struct V_21 * V_23 )
{
const struct V_170 * V_4 = V_62 -> V_166 -> V_171 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_172 != V_169 - 1 ; V_4 ++ )
if ( ( V_4 -> V_173 == V_169 ||
V_4 -> V_173 == V_23 -> V_62 ) &&
( V_4 -> V_172 == V_169 ||
V_4 -> V_172 == V_23 -> type ) &&
( V_4 -> V_174 == V_169 ||
V_4 -> V_174 == V_23 -> V_175 ) )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_2 * V_62 , struct V_15 * V_18 ,
struct V_21 * V_23 , T_2 V_24 , int V_176 )
{
struct V_177 * V_178 = V_62 -> V_166 ;
int V_104 ;
if ( ! F_52 ( & V_62 -> V_179 ) )
F_53 ( V_62 , V_23 , V_24 ) ;
if ( V_178 && V_178 -> V_180 && F_50 ( V_62 , V_23 ) ) {
V_104 = V_178 -> V_180 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_104 != 0 ) {
if ( V_104 < 0 )
F_5 ( V_62 , L_31 ,
V_178 -> V_181 , V_104 ) ;
return;
}
}
if ( V_62 -> V_182 & V_183 )
F_54 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_62 -> V_182 & V_184 && V_176 && V_62 -> V_185 )
V_62 -> V_185 ( V_62 , V_18 , V_23 , V_24 ) ;
}
static void F_55 ( struct V_2 * V_62 , struct V_15 * V_18 ,
T_3 * V_71 , int V_176 )
{
unsigned V_41 ;
unsigned V_95 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
T_2 V_186 = V_18 -> V_51 ;
T_2 V_187 = V_18 -> V_52 ;
T_2 * V_24 ;
V_24 = F_7 ( sizeof( T_2 ) * V_95 , V_188 ) ;
if ( ! V_24 )
return;
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
V_24 [ V_41 ] = V_186 < 0 ?
F_41 ( F_43 ( V_62 , V_71 , V_47 + V_41 * V_12 ,
V_12 ) , V_12 ) :
F_43 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ;
if ( ! ( V_18 -> V_46 & V_189 ) &&
V_24 [ V_41 ] >= V_186 && V_24 [ V_41 ] <= V_187 &&
V_18 -> V_23 [ V_24 [ V_41 ] - V_186 ] . V_62 == V_190 + 1 )
goto exit;
}
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
if ( V_189 & V_18 -> V_46 ) {
F_51 ( V_62 , V_18 , & V_18 -> V_23 [ V_41 ] , V_24 [ V_41 ] , V_176 ) ;
continue;
}
if ( V_18 -> V_24 [ V_41 ] >= V_186 && V_18 -> V_24 [ V_41 ] <= V_187
&& V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_186 ] . V_62
&& F_48 ( V_24 , V_18 -> V_24 [ V_41 ] , V_95 ) )
F_51 ( V_62 , V_18 , & V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_186 ] , 0 , V_176 ) ;
if ( V_24 [ V_41 ] >= V_186 && V_24 [ V_41 ] <= V_187
&& V_18 -> V_23 [ V_24 [ V_41 ] - V_186 ] . V_62
&& F_48 ( V_18 -> V_24 , V_24 [ V_41 ] , V_95 ) )
F_51 ( V_62 , V_18 , & V_18 -> V_23 [ V_24 [ V_41 ] - V_186 ] , 1 , V_176 ) ;
}
memcpy ( V_18 -> V_24 , V_24 , V_95 * sizeof( T_2 ) ) ;
exit:
F_8 ( V_24 ) ;
}
static void F_56 ( const struct V_2 * V_62 ,
struct V_15 * V_18 , T_3 * V_71 )
{
unsigned V_95 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
unsigned V_41 ;
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
if ( V_18 -> V_51 < 0 )
F_45 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
F_42 ( V_18 -> V_24 [ V_41 ] , V_12 ) ) ;
else
F_45 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
V_18 -> V_24 [ V_41 ] ) ;
}
}
void F_57 ( struct V_1 * V_7 , T_3 * V_71 )
{
unsigned V_41 ;
if ( V_7 -> V_4 > 0 )
* V_71 ++ = V_7 -> V_4 ;
memset ( V_71 , 0 , ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ) ;
for ( V_41 = 0 ; V_41 < V_7 -> V_19 ; V_41 ++ )
F_56 ( V_7 -> V_3 , V_7 -> V_18 [ V_41 ] , V_71 ) ;
}
V_72 * F_58 ( struct V_1 * V_7 , T_5 V_46 )
{
int V_191 = F_59 ( V_7 ) + 7 ;
return F_7 ( V_191 , V_46 ) ;
}
int F_60 ( struct V_15 * V_18 , unsigned V_47 , T_2 V_24 )
{
unsigned V_12 ;
if ( ! V_18 )
return - 1 ;
V_12 = V_18 -> V_54 ;
F_53 ( V_18 -> V_7 -> V_3 , V_18 -> V_23 + V_47 , V_24 ) ;
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
static struct V_1 * F_61 ( struct V_5 * V_6 ,
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
void F_62 ( struct V_2 * V_62 , struct V_1 * V_7 ,
int V_192 )
{
char * V_155 ;
int V_104 ;
int V_191 ;
V_155 = F_58 ( V_7 , V_10 ) ;
if ( ! V_155 )
return;
V_191 = F_59 ( V_7 ) ;
if ( V_192 == V_193 )
F_57 ( V_7 , V_155 ) ;
V_104 = V_62 -> V_194 -> V_195 ( V_62 , V_7 -> V_4 , V_155 , V_191 ,
V_7 -> type , V_192 ) ;
if ( V_104 < 0 ) {
F_13 ( L_35 , V_104 ) ;
goto V_196;
}
if ( V_192 == V_197 )
F_63 ( V_62 , V_7 -> type , V_155 , V_104 , 0 ) ;
V_196:
F_8 ( V_155 ) ;
}
int F_64 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 ,
int V_176 )
{
struct V_5 * V_6 = V_62 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_177 * V_178 ;
unsigned int V_158 ;
int V_115 , V_198 = V_12 ;
V_72 * V_199 = V_71 ;
int V_104 = 0 ;
V_7 = F_61 ( V_6 , V_71 ) ;
if ( ! V_7 )
goto V_196;
if ( V_6 -> V_11 ) {
V_199 ++ ;
V_198 -- ;
}
V_115 = ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ;
if ( V_115 > V_200 )
V_115 = V_200 ;
if ( V_198 < V_115 ) {
F_13 ( L_36 , V_7 -> V_4 ,
V_198 , V_115 ) ;
memset ( V_199 + V_198 , 0 , V_115 - V_198 ) ;
}
if ( ( V_62 -> V_182 & V_184 ) && V_62 -> V_201 )
V_62 -> V_201 ( V_62 , V_7 ) ;
if ( V_62 -> V_182 & V_202 ) {
V_104 = F_65 ( V_62 , V_71 , V_12 ) ;
if ( V_104 )
goto V_196;
}
if ( V_62 -> V_182 != V_202 && V_7 -> V_19 ) {
for ( V_158 = 0 ; V_158 < V_7 -> V_19 ; V_158 ++ )
F_55 ( V_62 , V_7 -> V_18 [ V_158 ] , V_199 , V_176 ) ;
V_178 = V_62 -> V_166 ;
if ( V_178 && V_178 -> V_7 )
V_178 -> V_7 ( V_62 , V_7 ) ;
}
if ( V_62 -> V_182 & V_183 )
F_66 ( V_62 , V_7 ) ;
V_196:
return V_104 ;
}
int F_63 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 , int V_176 )
{
struct V_5 * V_6 ;
struct V_177 * V_178 ;
struct V_1 * V_7 ;
int V_104 = 0 ;
if ( ! V_62 )
return - V_203 ;
if ( F_67 ( & V_62 -> V_204 ) )
return - V_205 ;
if ( ! V_62 -> V_166 ) {
V_104 = - V_203 ;
goto V_206;
}
V_6 = V_62 -> V_6 + type ;
V_178 = V_62 -> V_166 ;
if ( ! V_12 ) {
F_13 ( L_37 ) ;
V_104 = - 1 ;
goto V_206;
}
if ( ! F_52 ( & V_62 -> V_179 ) )
F_68 ( V_62 , type , V_71 , V_12 ) ;
V_7 = F_61 ( V_6 , V_71 ) ;
if ( ! V_7 ) {
V_104 = - 1 ;
goto V_206;
}
if ( V_178 && V_178 -> V_207 && F_49 ( V_62 , V_7 ) ) {
V_104 = V_178 -> V_207 ( V_62 , V_7 , V_71 , V_12 ) ;
if ( V_104 < 0 )
goto V_206;
}
V_104 = F_64 ( V_62 , type , V_71 , V_12 , V_176 ) ;
V_206:
F_69 ( & V_62 -> V_204 ) ;
return V_104 ;
}
static bool F_70 ( struct V_2 * V_208 ,
const struct V_209 * V_4 )
{
return ( V_4 -> V_210 == V_211 || V_4 -> V_210 == V_208 -> V_210 ) &&
( V_4 -> V_130 == V_212 || V_4 -> V_130 == V_208 -> V_130 ) &&
( V_4 -> V_136 == V_169 || V_4 -> V_136 == V_208 -> V_136 ) &&
( V_4 -> V_138 == V_169 || V_4 -> V_138 == V_208 -> V_138 ) ;
}
const struct V_209 * F_71 ( struct V_2 * V_208 ,
const struct V_209 * V_4 )
{
for (; V_4 -> V_210 ; V_4 ++ )
if ( F_70 ( V_208 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_72 ( struct V_2 * V_208 )
{
return ! ! F_71 ( V_208 , V_213 ) ;
}
static T_6
F_73 ( struct V_214 * V_215 , struct V_216 * V_217 ,
struct V_218 * V_219 ,
char * V_155 , T_7 V_220 , T_8 V_95 )
{
struct V_3 * V_103 = F_28 ( V_217 , struct V_3 , V_217 ) ;
struct V_2 * V_208 = F_28 ( V_103 , struct V_2 , V_103 ) ;
if ( V_220 >= V_208 -> V_115 )
return 0 ;
if ( V_220 + V_95 > V_208 -> V_115 )
V_95 = V_208 -> V_115 - V_220 ;
memcpy ( V_155 , V_208 -> V_114 + V_220 , V_95 ) ;
return V_95 ;
}
static T_6
F_74 ( struct V_3 * V_103 , struct V_221 * V_219 ,
char * V_155 )
{
struct V_2 * V_208 = F_28 ( V_103 , struct V_2 , V_103 ) ;
return sprintf ( V_155 , L_38 , V_208 -> V_222 & 0xff ) ;
}
int F_75 ( struct V_2 * V_208 , unsigned int V_223 )
{
static const char * V_224 [] = { L_39 , L_40 , L_41 , L_39 ,
L_42 , L_43 , L_44 , L_45 ,
L_46
} ;
const char * type , * V_210 ;
char V_155 [ 64 ] ;
unsigned int V_48 ;
int V_191 ;
int V_104 ;
if ( V_208 -> V_225 & V_226 )
V_223 |= ( V_227 | V_228 ) ;
if ( V_208 -> V_225 & V_229 )
V_223 |= V_230 ;
if ( V_208 -> V_210 != V_231 )
V_223 &= ~ V_228 ;
if ( F_72 ( V_208 ) )
V_223 |= V_227 ;
if ( ( V_223 & V_232 ) && ! F_76 ( V_208 ,
V_223 & V_230 ) )
V_208 -> V_182 |= V_183 ;
if ( ( V_223 & V_228 ) && V_208 -> V_233 &&
! V_208 -> V_233 ( V_208 ,
V_223 & V_227 ) )
V_208 -> V_182 |= V_184 ;
if ( ( V_223 & V_234 ) && ! F_77 ( V_208 ) )
V_208 -> V_182 |= V_202 ;
if ( V_223 & V_235 )
V_208 -> V_182 |= V_236 ;
if ( ! V_208 -> V_182 && ! V_208 -> V_166 -> V_207 ) {
F_5 ( V_208 , L_47 ) ;
return - V_203 ;
}
if ( ( V_208 -> V_182 & V_183 ) &&
( V_223 & V_237 ) && V_208 -> V_238 )
V_208 -> V_238 ( V_208 ) ;
V_191 = 0 ;
if ( V_208 -> V_182 & V_183 )
V_191 += sprintf ( V_155 + V_191 , L_48 ) ;
if ( V_208 -> V_182 & V_184 )
V_191 += sprintf ( V_155 + V_191 , L_49 , V_191 ? L_50 : L_51 ,
V_208 -> V_239 ) ;
if ( V_208 -> V_182 & V_202 )
V_191 += sprintf ( V_155 + V_191 , L_52 , V_191 ? L_50 : L_51 ,
( (struct V_240 * ) V_208 -> V_240 ) -> V_239 ) ;
type = L_39 ;
for ( V_48 = 0 ; V_48 < V_208 -> V_34 ; V_48 ++ ) {
struct V_28 * V_241 = & V_208 -> V_29 [ V_48 ] ;
if ( V_241 -> type == V_39 &&
( V_241 -> V_23 & V_242 ) == V_144 &&
( V_241 -> V_23 & 0xffff ) < F_78 ( V_224 ) ) {
type = V_224 [ V_241 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_208 -> V_210 ) {
case V_231 :
V_210 = L_53 ;
break;
case V_243 :
V_210 = L_54 ;
break;
default:
V_210 = L_55 ;
}
V_104 = F_79 ( & V_208 -> V_103 , & V_244 ) ;
if ( V_104 )
F_21 ( V_208 ,
L_56 , V_104 ) ;
V_104 = F_80 ( & V_208 -> V_103 , & V_245 ) ;
if ( V_104 )
F_21 ( V_208 ,
L_57 , V_104 ) ;
F_81 ( V_208 , L_58 ,
V_155 , V_210 , V_208 -> V_246 >> 8 , V_208 -> V_246 & 0xff ,
type , V_208 -> V_181 , V_208 -> V_247 ) ;
return 0 ;
}
void F_82 ( struct V_2 * V_208 )
{
F_83 ( & V_208 -> V_103 , & V_244 ) ;
F_84 ( & V_208 -> V_103 , & V_245 ) ;
if ( V_208 -> V_182 & V_183 )
F_85 ( V_208 ) ;
if ( V_208 -> V_182 & V_184 )
V_208 -> V_248 ( V_208 ) ;
if ( V_208 -> V_182 & V_202 )
F_86 ( V_208 ) ;
V_208 -> V_182 = 0 ;
}
static T_6 F_87 ( struct V_249 * V_250 , const char * V_155 ,
T_8 V_95 )
{
struct V_177 * V_178 = F_28 ( V_250 , struct V_177 , V_166 ) ;
struct V_251 * V_252 ;
V_53 V_210 , V_136 , V_138 ;
unsigned long V_253 = 0 ;
int V_104 ;
V_104 = sscanf ( V_155 , L_59 ,
& V_210 , & V_136 , & V_138 , & V_253 ) ;
if ( V_104 < 3 )
return - V_33 ;
V_252 = F_2 ( sizeof( * V_252 ) , V_10 ) ;
if ( ! V_252 )
return - V_36 ;
V_252 -> V_4 . V_210 = V_210 ;
V_252 -> V_4 . V_130 = V_212 ;
V_252 -> V_4 . V_136 = V_136 ;
V_252 -> V_4 . V_138 = V_138 ;
V_252 -> V_4 . V_253 = V_253 ;
F_88 ( & V_178 -> V_254 ) ;
F_3 ( & V_252 -> V_13 , & V_178 -> V_255 ) ;
F_89 ( & V_178 -> V_254 ) ;
V_104 = F_90 ( & V_178 -> V_166 ) ;
return V_104 ? : V_95 ;
}
static void F_91 ( struct V_177 * V_178 )
{
struct V_251 * V_252 , * V_41 ;
F_88 ( & V_178 -> V_254 ) ;
F_92 (dynid, n, &hdrv->dyn_list, list) {
F_93 ( & V_252 -> V_13 ) ;
F_8 ( V_252 ) ;
}
F_89 ( & V_178 -> V_254 ) ;
}
static const struct V_209 * F_94 ( struct V_2 * V_208 ,
struct V_177 * V_178 )
{
struct V_251 * V_252 ;
F_88 ( & V_178 -> V_254 ) ;
F_95 (dynid, &hdrv->dyn_list, list) {
if ( F_70 ( V_208 , & V_252 -> V_4 ) ) {
F_89 ( & V_178 -> V_254 ) ;
return & V_252 -> V_4 ;
}
}
F_89 ( & V_178 -> V_254 ) ;
return F_71 ( V_208 , V_178 -> V_256 ) ;
}
static int F_96 ( struct V_3 * V_103 , struct V_249 * V_250 )
{
struct V_177 * V_178 = F_28 ( V_250 , struct V_177 , V_166 ) ;
struct V_2 * V_208 = F_28 ( V_103 , struct V_2 , V_103 ) ;
return F_94 ( V_208 , V_178 ) != NULL ;
}
static int F_97 ( struct V_3 * V_103 )
{
struct V_177 * V_178 = F_28 ( V_103 -> V_166 ,
struct V_177 , V_166 ) ;
struct V_2 * V_208 = F_28 ( V_103 , struct V_2 , V_103 ) ;
const struct V_209 * V_4 ;
int V_104 = 0 ;
if ( F_98 ( & V_208 -> V_257 ) )
return - V_258 ;
if ( F_98 ( & V_208 -> V_204 ) ) {
V_104 = - V_258 ;
goto V_259;
}
V_208 -> V_260 = false ;
if ( ! V_208 -> V_166 ) {
V_4 = F_94 ( V_208 , V_178 ) ;
if ( V_4 == NULL ) {
V_104 = - V_203 ;
goto V_206;
}
V_208 -> V_166 = V_178 ;
if ( V_178 -> V_261 ) {
V_104 = V_178 -> V_261 ( V_208 , V_4 ) ;
} else {
V_104 = F_40 ( V_208 ) ;
if ( ! V_104 )
V_104 = F_99 ( V_208 , V_262 ) ;
}
if ( V_104 ) {
F_25 ( V_208 ) ;
V_208 -> V_166 = NULL ;
}
}
V_206:
if ( ! V_208 -> V_260 )
F_69 ( & V_208 -> V_204 ) ;
V_259:
F_69 ( & V_208 -> V_257 ) ;
return V_104 ;
}
static int F_100 ( struct V_3 * V_103 )
{
struct V_2 * V_208 = F_28 ( V_103 , struct V_2 , V_103 ) ;
struct V_177 * V_178 ;
int V_104 = 0 ;
if ( F_98 ( & V_208 -> V_257 ) )
return - V_258 ;
if ( F_98 ( & V_208 -> V_204 ) ) {
V_104 = - V_258 ;
goto V_259;
}
V_208 -> V_260 = false ;
V_178 = V_208 -> V_166 ;
if ( V_178 ) {
if ( V_178 -> remove )
V_178 -> remove ( V_208 ) ;
else
F_101 ( V_208 ) ;
F_25 ( V_208 ) ;
V_208 -> V_166 = NULL ;
}
if ( ! V_208 -> V_260 )
F_69 ( & V_208 -> V_204 ) ;
V_259:
F_69 ( & V_208 -> V_257 ) ;
return V_104 ;
}
static T_6 F_102 ( struct V_3 * V_103 , struct V_221 * V_158 ,
char * V_155 )
{
struct V_2 * V_208 = F_28 ( V_103 , struct V_2 , V_103 ) ;
int V_191 ;
V_191 = snprintf ( V_155 , V_263 , L_60 ,
V_208 -> V_210 , V_208 -> V_130 , V_208 -> V_136 , V_208 -> V_138 ) ;
return ( V_191 >= V_263 ) ? ( V_263 - 1 ) : V_191 ;
}
static int F_103 ( struct V_3 * V_103 , struct V_264 * V_265 )
{
struct V_2 * V_208 = F_28 ( V_103 , struct V_2 , V_103 ) ;
if ( F_104 ( V_265 , L_61 ,
V_208 -> V_210 , V_208 -> V_136 , V_208 -> V_138 ) )
return - V_36 ;
if ( F_104 ( V_265 , L_62 , V_208 -> V_181 ) )
return - V_36 ;
if ( F_104 ( V_265 , L_63 , V_208 -> V_247 ) )
return - V_36 ;
if ( F_104 ( V_265 , L_64 , V_208 -> V_266 ) )
return - V_36 ;
if ( F_104 ( V_265 , L_65 ,
V_208 -> V_210 , V_208 -> V_130 , V_208 -> V_136 , V_208 -> V_138 ) )
return - V_36 ;
return 0 ;
}
bool F_105 ( struct V_2 * V_208 )
{
if ( V_208 -> V_225 & V_267 )
return false ;
if ( V_208 -> V_225 & V_268 )
return true ;
switch ( V_208 -> V_136 ) {
case V_269 :
if ( V_208 -> V_138 >= V_270 &&
V_208 -> V_138 <= V_271 )
return true ;
break;
case V_272 :
if ( V_208 -> V_138 >= V_273 &&
V_208 -> V_138 <= V_274 )
return true ;
if ( V_208 -> V_138 == V_275 &&
! strcmp ( V_208 -> V_181 , L_66 ) )
return true ;
break;
case V_276 :
if ( V_208 -> V_138 >= V_277 &&
V_208 -> V_138 <= V_278 )
return true ;
break;
case V_279 :
if ( V_208 -> V_138 >= V_280 &&
V_208 -> V_138 <= V_281 )
return true ;
break;
case V_282 :
if ( V_208 -> V_138 == V_283 &&
V_208 -> type == V_284 )
return true ;
break;
case V_285 :
if ( ( V_208 -> V_138 >= V_286 &&
V_208 -> V_138 <= V_287 ) ||
( V_208 -> V_138 >= V_288 &&
V_208 -> V_138 <= V_289 ) )
return true ;
break;
case V_290 :
if ( V_208 -> V_138 == V_291 &&
V_208 -> V_210 == V_231 &&
strncmp ( V_208 -> V_181 , L_67 , 22 ) == 0 )
return true ;
break;
}
if ( V_208 -> type == V_292 &&
F_71 ( V_208 , V_293 ) )
return true ;
return ! ! F_71 ( V_208 , V_294 ) ;
}
int F_106 ( struct V_2 * V_208 )
{
static T_9 V_4 = F_107 ( 0 ) ;
int V_104 ;
if ( F_46 ( V_208 -> V_116 & V_295 ) )
return - V_205 ;
if ( F_105 ( V_208 ) )
return - V_203 ;
if ( ! V_208 -> V_194 -> V_195 ) {
F_5 ( V_208 , L_68 ) ;
return - V_33 ;
}
V_104 = V_208 -> V_194 -> V_296 ( V_208 ) ;
if ( V_104 )
return V_104 ;
if ( ! V_208 -> V_118 )
return - V_203 ;
if ( V_297 ||
( ! V_208 -> V_130 &&
! F_71 ( V_208 , V_298 ) ) ) {
V_104 = F_36 ( V_208 ) ;
if ( V_104 )
F_21 ( V_208 , L_69 , V_104 ) ;
}
F_108 ( & V_208 -> V_103 , L_70 , V_208 -> V_210 ,
V_208 -> V_136 , V_208 -> V_138 , F_109 ( & V_4 ) ) ;
F_110 ( V_208 , F_20 ( & V_208 -> V_103 ) ) ;
V_104 = F_111 ( & V_208 -> V_103 ) ;
if ( ! V_104 )
V_208 -> V_116 |= V_295 ;
else
F_112 ( V_208 ) ;
return V_104 ;
}
struct V_2 * F_113 ( void )
{
struct V_2 * V_208 ;
int V_104 = - V_36 ;
V_208 = F_2 ( sizeof( * V_208 ) , V_10 ) ;
if ( V_208 == NULL )
return F_114 ( V_104 ) ;
F_115 ( & V_208 -> V_103 ) ;
V_208 -> V_103 . V_299 = F_27 ;
V_208 -> V_103 . V_210 = & V_300 ;
F_25 ( V_208 ) ;
F_116 ( & V_208 -> V_301 ) ;
F_26 ( & V_208 -> V_179 ) ;
F_117 ( & V_208 -> V_302 ) ;
F_118 ( & V_208 -> V_257 , 1 ) ;
F_118 ( & V_208 -> V_204 , 1 ) ;
return V_208 ;
}
static void F_119 ( struct V_2 * V_208 )
{
if ( V_208 -> V_116 & V_295 ) {
F_120 ( & V_208 -> V_103 ) ;
F_112 ( V_208 ) ;
V_208 -> V_116 &= ~ V_295 ;
}
F_8 ( V_208 -> V_118 ) ;
V_208 -> V_118 = NULL ;
V_208 -> V_150 = 0 ;
}
void F_121 ( struct V_2 * V_208 )
{
F_119 ( V_208 ) ;
F_122 ( & V_208 -> V_103 ) ;
}
int F_123 ( struct V_177 * V_178 , struct V_303 * V_304 ,
const char * V_305 )
{
int V_104 ;
V_178 -> V_166 . V_181 = V_178 -> V_181 ;
V_178 -> V_166 . V_210 = & V_300 ;
V_178 -> V_166 . V_304 = V_304 ;
V_178 -> V_166 . V_305 = V_305 ;
F_26 ( & V_178 -> V_255 ) ;
F_117 ( & V_178 -> V_254 ) ;
V_104 = F_124 ( & V_178 -> V_166 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_125 ( & V_178 -> V_166 , & V_306 ) ;
if ( V_104 )
F_126 ( & V_178 -> V_166 ) ;
return V_104 ;
}
void F_127 ( struct V_177 * V_178 )
{
F_128 ( & V_178 -> V_166 , & V_306 ) ;
F_126 ( & V_178 -> V_166 ) ;
F_91 ( V_178 ) ;
}
int F_129 ( struct V_2 * V_62 )
{
struct V_307 * V_308 ;
int V_48 ;
if ( ! ( V_62 -> V_182 & V_183 ) )
return 0 ;
F_95 (hidinput, &hid->inputs, list) {
for ( V_48 = 0 ; V_48 < F_130 ( V_309 ) ; V_48 ++ )
if ( V_308 -> V_310 -> V_311 [ V_48 ] )
return 1 ;
}
return 0 ;
}
static int T_10 F_131 ( void )
{
int V_104 ;
if ( V_312 )
F_132 ( L_71
L_72 ) ;
V_104 = F_133 ( & V_300 ) ;
if ( V_104 ) {
F_134 ( L_73 ) ;
goto V_313;
}
V_104 = F_135 () ;
if ( V_104 )
goto V_314;
F_136 () ;
return 0 ;
V_314:
F_137 ( & V_300 ) ;
V_313:
return V_104 ;
}
static void T_11 F_138 ( void )
{
F_139 () ;
F_140 () ;
F_137 ( & V_300 ) ;
}
