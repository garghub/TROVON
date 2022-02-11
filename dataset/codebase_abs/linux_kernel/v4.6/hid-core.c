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
( V_62 -> V_138 == V_139 ||
V_62 -> V_138 == V_140 ||
V_62 -> V_138 == V_141 ||
V_62 -> V_138 == V_142 ||
V_62 -> V_138 == V_143 ) &&
V_62 -> V_130 == V_131 )
V_62 -> V_130 = V_144 ;
if ( ( V_27 -> V_49 . V_85 << 16 ) == V_145 )
for ( V_48 = 0 ; V_48 < V_27 -> V_30 . V_42 ; V_48 ++ )
if ( V_27 -> V_30 . V_23 [ V_48 ] == V_146 )
V_27 -> V_132 |= V_147 ;
if ( ( V_27 -> V_49 . V_85 << 16 ) >= V_148 )
V_27 -> V_132 |= V_149 ;
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
if ( V_71 & V_150 )
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
T_3 * V_120 = V_119 + V_62 -> V_151 ;
static int (* F_37 [])( struct V_26 * V_27 ,
struct V_69 * V_70 ) = {
F_35 ,
hid_parser_global,
hid_parser_local,
hid_parser_reserved
}
struct V_1 * F_38 ( struct V_2 * V_62 ,
unsigned int type , unsigned int V_4 ,
unsigned int V_152 ,
unsigned int V_153 )
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
V_62 -> V_6 [ type ] . V_14 . V_154 ,
struct V_1 , V_13 ) ;
} else {
V_7 = V_62 -> V_6 [ type ] . V_9 [ V_4 ] ;
}
if ( ! V_7 ) {
F_5 ( V_62 , L_25 , V_155 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_19 <= V_152 ) {
F_5 ( V_62 , L_26 ,
V_155 [ type ] , V_4 ) ;
return NULL ;
}
if ( V_7 -> V_18 [ V_152 ] -> V_55 < V_153 ) {
F_5 ( V_62 , L_27 ,
V_155 [ type ] , V_4 , V_152 ) ;
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
T_3 * V_156 ;
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
case 8 : return ( ( V_157 ) V_24 ) ;
case 16 : return ( ( V_158 ) V_24 ) ;
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
V_25 V_159 = V_24 >> ( V_41 - 1 ) ;
if ( V_159 && V_159 != - 1 )
return V_24 < 0 ? 1 << ( V_41 - 1 ) : ( 1 << ( V_41 - 1 ) ) - 1 ;
return V_24 & ( ( 1 << V_41 ) - 1 ) ;
}
static T_1 F_43 ( V_72 * V_7 , unsigned V_47 , int V_41 )
{
unsigned int V_160 = V_47 / 8 ;
unsigned int V_161 = 0 ;
unsigned int V_162 = V_47 % 8 ;
int V_163 = 8 - V_162 ;
T_1 V_24 = 0 ;
T_1 V_164 = V_41 < 32 ? ( 1U << V_41 ) - 1 : ~ 0U ;
while ( V_41 > 0 ) {
V_24 |= ( ( T_1 ) V_7 [ V_160 ] >> V_162 ) << V_161 ;
V_41 -= V_163 ;
V_161 += V_163 ;
V_163 = 8 ;
V_162 = 0 ;
V_160 ++ ;
}
return V_24 & V_164 ;
}
T_1 F_44 ( const struct V_2 * V_62 , V_72 * V_7 ,
unsigned V_47 , unsigned V_41 )
{
if ( V_41 > 32 ) {
F_21 ( V_62 , L_28 ,
V_41 , V_165 -> V_166 ) ;
V_41 = 32 ;
}
return F_43 ( V_7 , V_47 , V_41 ) ;
}
static void F_45 ( V_72 * V_7 , unsigned V_47 , int V_41 , T_1 V_24 )
{
unsigned int V_160 = V_47 / 8 ;
unsigned int V_12 = V_47 + V_41 ;
unsigned int V_162 = V_47 % 8 ;
int V_167 = 8 - V_162 ;
V_72 V_168 = 0xff << V_162 ;
while ( V_41 - V_167 >= 0 ) {
V_7 [ V_160 ] &= ~ V_168 ;
V_7 [ V_160 ] |= V_24 << V_162 ;
V_24 >>= V_167 ;
V_41 -= V_167 ;
V_167 = 8 ;
V_168 = 0xff ;
V_162 = 0 ;
V_160 ++ ;
}
if ( V_41 ) {
if ( V_12 % 8 )
V_168 &= ( 1U << ( V_12 % 8 ) ) - 1 ;
V_7 [ V_160 ] &= ~ V_168 ;
V_7 [ V_160 ] |= ( V_24 << V_162 ) & V_168 ;
}
}
static void F_46 ( const struct V_2 * V_62 , V_72 * V_7 ,
unsigned V_47 , unsigned V_41 , T_1 V_24 )
{
T_4 V_169 ;
if ( V_41 > 32 ) {
F_21 ( V_62 , L_29 ,
V_170 , V_41 , V_165 -> V_166 ) ;
V_41 = 32 ;
}
V_169 = ( 1ULL << V_41 ) - 1 ;
if ( V_24 > V_169 )
F_21 ( V_62 , L_30 ,
V_170 , V_24 , V_165 -> V_166 ) ;
F_47 ( V_24 > V_169 ) ;
V_24 &= V_169 ;
F_45 ( V_7 , V_47 , V_41 , V_24 ) ;
}
static int F_48 ( T_2 * V_171 , T_2 V_24 , unsigned V_41 )
{
while ( V_41 -- ) {
if ( * V_171 ++ == V_24 )
return 0 ;
}
return - 1 ;
}
static int F_49 ( struct V_2 * V_62 , struct V_1 * V_7 )
{
const struct V_172 * V_4 = V_62 -> V_173 -> V_174 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_45 != V_175 ; V_4 ++ )
if ( V_4 -> V_45 == V_176 ||
V_4 -> V_45 == V_7 -> type )
return 1 ;
return 0 ;
}
static int F_50 ( struct V_2 * V_62 , struct V_21 * V_23 )
{
const struct V_177 * V_4 = V_62 -> V_173 -> V_178 ;
if ( ! V_4 )
return 1 ;
for (; V_4 -> V_179 != V_176 - 1 ; V_4 ++ )
if ( ( V_4 -> V_180 == V_176 ||
V_4 -> V_180 == V_23 -> V_62 ) &&
( V_4 -> V_179 == V_176 ||
V_4 -> V_179 == V_23 -> type ) &&
( V_4 -> V_181 == V_176 ||
V_4 -> V_181 == V_23 -> V_182 ) )
return 1 ;
return 0 ;
}
static void F_51 ( struct V_2 * V_62 , struct V_15 * V_18 ,
struct V_21 * V_23 , T_2 V_24 , int V_183 )
{
struct V_184 * V_185 = V_62 -> V_173 ;
int V_104 ;
if ( ! F_52 ( & V_62 -> V_186 ) )
F_53 ( V_62 , V_23 , V_24 ) ;
if ( V_185 && V_185 -> V_187 && F_50 ( V_62 , V_23 ) ) {
V_104 = V_185 -> V_187 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_104 != 0 ) {
if ( V_104 < 0 )
F_5 ( V_62 , L_31 ,
V_185 -> V_188 , V_104 ) ;
return;
}
}
if ( V_62 -> V_189 & V_190 )
F_54 ( V_62 , V_18 , V_23 , V_24 ) ;
if ( V_62 -> V_189 & V_191 && V_183 && V_62 -> V_192 )
V_62 -> V_192 ( V_62 , V_18 , V_23 , V_24 ) ;
}
static void F_55 ( struct V_2 * V_62 , struct V_15 * V_18 ,
T_3 * V_71 , int V_183 )
{
unsigned V_41 ;
unsigned V_95 = V_18 -> V_55 ;
unsigned V_47 = V_18 -> V_64 ;
unsigned V_12 = V_18 -> V_54 ;
T_2 V_193 = V_18 -> V_51 ;
T_2 V_194 = V_18 -> V_52 ;
T_2 * V_24 ;
V_24 = F_7 ( sizeof( T_2 ) * V_95 , V_195 ) ;
if ( ! V_24 )
return;
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
V_24 [ V_41 ] = V_193 < 0 ?
F_41 ( F_44 ( V_62 , V_71 , V_47 + V_41 * V_12 ,
V_12 ) , V_12 ) :
F_44 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ) ;
if ( ! ( V_18 -> V_46 & V_196 ) &&
V_24 [ V_41 ] >= V_193 && V_24 [ V_41 ] <= V_194 &&
V_24 [ V_41 ] - V_193 < V_18 -> V_63 &&
V_18 -> V_23 [ V_24 [ V_41 ] - V_193 ] . V_62 == V_197 + 1 )
goto exit;
}
for ( V_41 = 0 ; V_41 < V_95 ; V_41 ++ ) {
if ( V_196 & V_18 -> V_46 ) {
F_51 ( V_62 , V_18 , & V_18 -> V_23 [ V_41 ] , V_24 [ V_41 ] , V_183 ) ;
continue;
}
if ( V_18 -> V_24 [ V_41 ] >= V_193 && V_18 -> V_24 [ V_41 ] <= V_194
&& V_18 -> V_24 [ V_41 ] - V_193 < V_18 -> V_63
&& V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_193 ] . V_62
&& F_48 ( V_24 , V_18 -> V_24 [ V_41 ] , V_95 ) )
F_51 ( V_62 , V_18 , & V_18 -> V_23 [ V_18 -> V_24 [ V_41 ] - V_193 ] , 0 , V_183 ) ;
if ( V_24 [ V_41 ] >= V_193 && V_24 [ V_41 ] <= V_194
&& V_24 [ V_41 ] - V_193 < V_18 -> V_63
&& V_18 -> V_23 [ V_24 [ V_41 ] - V_193 ] . V_62
&& F_48 ( V_18 -> V_24 , V_24 [ V_41 ] , V_95 ) )
F_51 ( V_62 , V_18 , & V_18 -> V_23 [ V_24 [ V_41 ] - V_193 ] , 1 , V_183 ) ;
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
F_46 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
F_42 ( V_18 -> V_24 [ V_41 ] , V_12 ) ) ;
else
F_46 ( V_62 , V_71 , V_47 + V_41 * V_12 , V_12 ,
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
int V_198 = F_59 ( V_7 ) + 7 ;
return F_7 ( V_198 , V_46 ) ;
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
int V_199 )
{
char * V_156 ;
int V_104 ;
int V_198 ;
V_156 = F_58 ( V_7 , V_10 ) ;
if ( ! V_156 )
return;
V_198 = F_59 ( V_7 ) ;
if ( V_199 == V_200 )
F_57 ( V_7 , V_156 ) ;
V_104 = V_62 -> V_201 -> V_202 ( V_62 , V_7 -> V_4 , V_156 , V_198 ,
V_7 -> type , V_199 ) ;
if ( V_104 < 0 ) {
F_13 ( L_35 , V_104 ) ;
goto V_203;
}
if ( V_199 == V_204 )
F_63 ( V_62 , V_7 -> type , V_156 , V_104 , 0 ) ;
V_203:
F_8 ( V_156 ) ;
}
int F_64 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 ,
int V_183 )
{
struct V_5 * V_6 = V_62 -> V_6 + type ;
struct V_1 * V_7 ;
struct V_184 * V_185 ;
unsigned int V_159 ;
int V_115 , V_205 = V_12 ;
V_72 * V_206 = V_71 ;
int V_104 = 0 ;
V_7 = F_61 ( V_6 , V_71 ) ;
if ( ! V_7 )
goto V_203;
if ( V_6 -> V_11 ) {
V_206 ++ ;
V_205 -- ;
}
V_115 = ( ( V_7 -> V_12 - 1 ) >> 3 ) + 1 ;
if ( V_115 > V_207 )
V_115 = V_207 ;
if ( V_205 < V_115 ) {
F_13 ( L_36 , V_7 -> V_4 ,
V_205 , V_115 ) ;
memset ( V_206 + V_205 , 0 , V_115 - V_205 ) ;
}
if ( ( V_62 -> V_189 & V_191 ) && V_62 -> V_208 )
V_62 -> V_208 ( V_62 , V_7 ) ;
if ( V_62 -> V_189 & V_209 ) {
V_104 = F_65 ( V_62 , V_71 , V_12 ) ;
if ( V_104 )
goto V_203;
}
if ( V_62 -> V_189 != V_209 && V_7 -> V_19 ) {
for ( V_159 = 0 ; V_159 < V_7 -> V_19 ; V_159 ++ )
F_55 ( V_62 , V_7 -> V_18 [ V_159 ] , V_206 , V_183 ) ;
V_185 = V_62 -> V_173 ;
if ( V_185 && V_185 -> V_7 )
V_185 -> V_7 ( V_62 , V_7 ) ;
}
if ( V_62 -> V_189 & V_190 )
F_66 ( V_62 , V_7 ) ;
V_203:
return V_104 ;
}
int F_63 ( struct V_2 * V_62 , int type , V_72 * V_71 , int V_12 , int V_183 )
{
struct V_5 * V_6 ;
struct V_184 * V_185 ;
struct V_1 * V_7 ;
int V_104 = 0 ;
if ( ! V_62 )
return - V_210 ;
if ( F_67 ( & V_62 -> V_211 ) )
return - V_212 ;
if ( ! V_62 -> V_173 ) {
V_104 = - V_210 ;
goto V_213;
}
V_6 = V_62 -> V_6 + type ;
V_185 = V_62 -> V_173 ;
if ( ! V_12 ) {
F_13 ( L_37 ) ;
V_104 = - 1 ;
goto V_213;
}
if ( ! F_52 ( & V_62 -> V_186 ) )
F_68 ( V_62 , type , V_71 , V_12 ) ;
V_7 = F_61 ( V_6 , V_71 ) ;
if ( ! V_7 ) {
V_104 = - 1 ;
goto V_213;
}
if ( V_185 && V_185 -> V_214 && F_49 ( V_62 , V_7 ) ) {
V_104 = V_185 -> V_214 ( V_62 , V_7 , V_71 , V_12 ) ;
if ( V_104 < 0 )
goto V_213;
}
V_104 = F_64 ( V_62 , type , V_71 , V_12 , V_183 ) ;
V_213:
F_69 ( & V_62 -> V_211 ) ;
return V_104 ;
}
static bool F_70 ( struct V_2 * V_215 ,
const struct V_216 * V_4 )
{
return ( V_4 -> V_217 == V_218 || V_4 -> V_217 == V_215 -> V_217 ) &&
( V_4 -> V_130 == V_219 || V_4 -> V_130 == V_215 -> V_130 ) &&
( V_4 -> V_136 == V_176 || V_4 -> V_136 == V_215 -> V_136 ) &&
( V_4 -> V_138 == V_176 || V_4 -> V_138 == V_215 -> V_138 ) ;
}
const struct V_216 * F_71 ( struct V_2 * V_215 ,
const struct V_216 * V_4 )
{
for (; V_4 -> V_217 ; V_4 ++ )
if ( F_70 ( V_215 , V_4 ) )
return V_4 ;
return NULL ;
}
static bool F_72 ( struct V_2 * V_215 )
{
return ! ! F_71 ( V_215 , V_220 ) ;
}
static T_6
F_73 ( struct V_221 * V_222 , struct V_223 * V_224 ,
struct V_225 * V_226 ,
char * V_156 , T_7 V_227 , T_8 V_95 )
{
struct V_3 * V_103 = F_74 ( V_224 ) ;
struct V_2 * V_215 = F_28 ( V_103 ) ;
if ( V_227 >= V_215 -> V_115 )
return 0 ;
if ( V_227 + V_95 > V_215 -> V_115 )
V_95 = V_215 -> V_115 - V_227 ;
memcpy ( V_156 , V_215 -> V_114 + V_227 , V_95 ) ;
return V_95 ;
}
static T_6
F_75 ( struct V_3 * V_103 , struct V_228 * V_226 ,
char * V_156 )
{
struct V_2 * V_215 = F_28 ( V_103 ) ;
return sprintf ( V_156 , L_38 , V_215 -> V_229 & 0xff ) ;
}
int F_76 ( struct V_2 * V_215 , unsigned int V_230 )
{
static const char * V_231 [] = { L_39 , L_40 , L_41 , L_39 ,
L_42 , L_43 , L_44 , L_45 ,
L_46
} ;
const char * type , * V_217 ;
char V_156 [ 64 ] = L_47 ;
unsigned int V_48 ;
int V_198 ;
int V_104 ;
if ( V_215 -> V_232 & V_233 )
V_230 |= ( V_234 | V_235 ) ;
if ( V_215 -> V_232 & V_236 )
V_230 |= V_237 ;
if ( V_215 -> V_217 != V_238 )
V_230 &= ~ V_235 ;
if ( F_72 ( V_215 ) )
V_230 |= V_234 ;
if ( ( V_230 & V_239 ) && ! F_77 ( V_215 ,
V_230 & V_237 ) )
V_215 -> V_189 |= V_190 ;
if ( ( V_230 & V_235 ) && V_215 -> V_240 &&
! V_215 -> V_240 ( V_215 ,
V_230 & V_234 ) )
V_215 -> V_189 |= V_191 ;
if ( ( V_230 & V_241 ) && ! F_78 ( V_215 ) )
V_215 -> V_189 |= V_209 ;
if ( V_230 & V_242 )
V_215 -> V_189 |= V_243 ;
if ( ! V_215 -> V_189 && ! V_215 -> V_173 -> V_214 ) {
F_5 ( V_215 , L_48 ) ;
return - V_210 ;
}
if ( ( V_215 -> V_189 & V_190 ) &&
( V_230 & V_244 ) && V_215 -> V_245 )
V_215 -> V_245 ( V_215 ) ;
V_198 = 0 ;
if ( V_215 -> V_189 & V_190 )
V_198 += sprintf ( V_156 + V_198 , L_49 ) ;
if ( V_215 -> V_189 & V_191 )
V_198 += sprintf ( V_156 + V_198 , L_50 , V_198 ? L_51 : L_47 ,
V_215 -> V_246 ) ;
if ( V_215 -> V_189 & V_209 )
V_198 += sprintf ( V_156 + V_198 , L_52 , V_198 ? L_51 : L_47 ,
( (struct V_247 * ) V_215 -> V_247 ) -> V_246 ) ;
type = L_39 ;
for ( V_48 = 0 ; V_48 < V_215 -> V_34 ; V_48 ++ ) {
struct V_28 * V_248 = & V_215 -> V_29 [ V_48 ] ;
if ( V_248 -> type == V_39 &&
( V_248 -> V_23 & V_249 ) == V_145 &&
( V_248 -> V_23 & 0xffff ) < F_79 ( V_231 ) ) {
type = V_231 [ V_248 -> V_23 & 0xffff ] ;
break;
}
}
switch ( V_215 -> V_217 ) {
case V_238 :
V_217 = L_53 ;
break;
case V_250 :
V_217 = L_54 ;
break;
case V_251 :
V_217 = L_55 ;
break;
default:
V_217 = L_56 ;
}
V_104 = F_80 ( & V_215 -> V_103 , & V_252 ) ;
if ( V_104 )
F_21 ( V_215 ,
L_57 , V_104 ) ;
F_81 ( V_215 , L_58 ,
V_156 , V_217 , V_215 -> V_253 >> 8 , V_215 -> V_253 & 0xff ,
type , V_215 -> V_188 , V_215 -> V_254 ) ;
return 0 ;
}
void F_82 ( struct V_2 * V_215 )
{
F_83 ( & V_215 -> V_103 , & V_252 ) ;
if ( V_215 -> V_189 & V_190 )
F_84 ( V_215 ) ;
if ( V_215 -> V_189 & V_191 )
V_215 -> V_255 ( V_215 ) ;
if ( V_215 -> V_189 & V_209 )
F_85 ( V_215 ) ;
V_215 -> V_189 = 0 ;
}
static T_6 F_86 ( struct V_256 * V_257 , const char * V_156 ,
T_8 V_95 )
{
struct V_184 * V_185 = F_87 ( V_257 ) ;
struct V_258 * V_259 ;
V_53 V_217 , V_136 , V_138 ;
unsigned long V_260 = 0 ;
int V_104 ;
V_104 = sscanf ( V_156 , L_59 ,
& V_217 , & V_136 , & V_138 , & V_260 ) ;
if ( V_104 < 3 )
return - V_33 ;
V_259 = F_2 ( sizeof( * V_259 ) , V_10 ) ;
if ( ! V_259 )
return - V_36 ;
V_259 -> V_4 . V_217 = V_217 ;
V_259 -> V_4 . V_130 = V_219 ;
V_259 -> V_4 . V_136 = V_136 ;
V_259 -> V_4 . V_138 = V_138 ;
V_259 -> V_4 . V_260 = V_260 ;
F_88 ( & V_185 -> V_261 ) ;
F_3 ( & V_259 -> V_13 , & V_185 -> V_262 ) ;
F_89 ( & V_185 -> V_261 ) ;
V_104 = F_90 ( & V_185 -> V_173 ) ;
return V_104 ? : V_95 ;
}
static void F_91 ( struct V_184 * V_185 )
{
struct V_258 * V_259 , * V_41 ;
F_88 ( & V_185 -> V_261 ) ;
F_92 (dynid, n, &hdrv->dyn_list, list) {
F_93 ( & V_259 -> V_13 ) ;
F_8 ( V_259 ) ;
}
F_89 ( & V_185 -> V_261 ) ;
}
static const struct V_216 * F_94 ( struct V_2 * V_215 ,
struct V_184 * V_185 )
{
struct V_258 * V_259 ;
F_88 ( & V_185 -> V_261 ) ;
F_95 (dynid, &hdrv->dyn_list, list) {
if ( F_70 ( V_215 , & V_259 -> V_4 ) ) {
F_89 ( & V_185 -> V_261 ) ;
return & V_259 -> V_4 ;
}
}
F_89 ( & V_185 -> V_261 ) ;
return F_71 ( V_215 , V_185 -> V_263 ) ;
}
static int F_96 ( struct V_3 * V_103 , struct V_256 * V_257 )
{
struct V_184 * V_185 = F_87 ( V_257 ) ;
struct V_2 * V_215 = F_28 ( V_103 ) ;
return F_94 ( V_215 , V_185 ) != NULL ;
}
static int F_97 ( struct V_3 * V_103 )
{
struct V_184 * V_185 = F_87 ( V_103 -> V_173 ) ;
struct V_2 * V_215 = F_28 ( V_103 ) ;
const struct V_216 * V_4 ;
int V_104 = 0 ;
if ( F_98 ( & V_215 -> V_264 ) )
return - V_265 ;
if ( F_98 ( & V_215 -> V_211 ) ) {
V_104 = - V_265 ;
goto V_266;
}
V_215 -> V_267 = false ;
if ( ! V_215 -> V_173 ) {
V_4 = F_94 ( V_215 , V_185 ) ;
if ( V_4 == NULL ) {
V_104 = - V_210 ;
goto V_213;
}
V_215 -> V_173 = V_185 ;
if ( V_185 -> V_268 ) {
V_104 = V_185 -> V_268 ( V_215 , V_4 ) ;
} else {
V_104 = F_40 ( V_215 ) ;
if ( ! V_104 )
V_104 = F_99 ( V_215 , V_269 ) ;
}
if ( V_104 ) {
F_25 ( V_215 ) ;
V_215 -> V_173 = NULL ;
}
}
V_213:
if ( ! V_215 -> V_267 )
F_69 ( & V_215 -> V_211 ) ;
V_266:
F_69 ( & V_215 -> V_264 ) ;
return V_104 ;
}
static int F_100 ( struct V_3 * V_103 )
{
struct V_2 * V_215 = F_28 ( V_103 ) ;
struct V_184 * V_185 ;
int V_104 = 0 ;
if ( F_98 ( & V_215 -> V_264 ) )
return - V_265 ;
if ( F_98 ( & V_215 -> V_211 ) ) {
V_104 = - V_265 ;
goto V_266;
}
V_215 -> V_267 = false ;
V_185 = V_215 -> V_173 ;
if ( V_185 ) {
if ( V_185 -> remove )
V_185 -> remove ( V_215 ) ;
else
F_101 ( V_215 ) ;
F_25 ( V_215 ) ;
V_215 -> V_173 = NULL ;
}
if ( ! V_215 -> V_267 )
F_69 ( & V_215 -> V_211 ) ;
V_266:
F_69 ( & V_215 -> V_264 ) ;
return V_104 ;
}
static T_6 F_102 ( struct V_3 * V_103 , struct V_228 * V_159 ,
char * V_156 )
{
struct V_2 * V_215 = F_103 ( V_103 , struct V_2 , V_103 ) ;
return F_104 ( V_156 , V_270 , L_60 ,
V_215 -> V_217 , V_215 -> V_130 , V_215 -> V_136 , V_215 -> V_138 ) ;
}
static int F_105 ( struct V_3 * V_103 , struct V_271 * V_272 )
{
struct V_2 * V_215 = F_28 ( V_103 ) ;
if ( F_106 ( V_272 , L_61 ,
V_215 -> V_217 , V_215 -> V_136 , V_215 -> V_138 ) )
return - V_36 ;
if ( F_106 ( V_272 , L_62 , V_215 -> V_188 ) )
return - V_36 ;
if ( F_106 ( V_272 , L_63 , V_215 -> V_254 ) )
return - V_36 ;
if ( F_106 ( V_272 , L_64 , V_215 -> V_273 ) )
return - V_36 ;
if ( F_106 ( V_272 , L_65 ,
V_215 -> V_217 , V_215 -> V_130 , V_215 -> V_136 , V_215 -> V_138 ) )
return - V_36 ;
return 0 ;
}
bool F_107 ( struct V_2 * V_215 )
{
if ( V_215 -> V_232 & V_274 )
return false ;
if ( V_215 -> V_232 & V_275 )
return true ;
switch ( V_215 -> V_136 ) {
case V_276 :
if ( V_215 -> V_138 >= V_277 &&
V_215 -> V_138 <= V_278 )
return true ;
break;
case V_279 :
if ( V_215 -> V_138 >= V_280 &&
V_215 -> V_138 <= V_281 )
return true ;
if ( V_215 -> V_138 == V_282 &&
! strcmp ( V_215 -> V_188 , L_66 ) )
return true ;
break;
case V_283 :
if ( V_215 -> V_138 >= V_284 &&
V_215 -> V_138 <= V_285 )
return true ;
break;
case V_286 :
if ( V_215 -> V_138 >= V_287 &&
V_215 -> V_138 <= V_288 )
return true ;
break;
case V_289 :
if ( V_215 -> V_138 == V_290 &&
V_215 -> type == V_291 )
return true ;
break;
case V_292 :
if ( ( V_215 -> V_138 >= V_293 &&
V_215 -> V_138 <= V_294 ) ||
( V_215 -> V_138 >= V_295 &&
V_215 -> V_138 <= V_296 ) )
return true ;
break;
case V_297 :
if ( V_215 -> V_138 == V_298 &&
V_215 -> V_217 == V_238 &&
strncmp ( V_215 -> V_188 , L_67 , 22 ) == 0 )
return true ;
break;
}
if ( V_215 -> type == V_299 &&
F_71 ( V_215 , V_300 ) )
return true ;
return ! ! F_71 ( V_215 , V_301 ) ;
}
int F_108 ( struct V_2 * V_215 )
{
static T_9 V_4 = F_109 ( 0 ) ;
int V_104 ;
if ( F_47 ( V_215 -> V_116 & V_302 ) )
return - V_212 ;
if ( F_107 ( V_215 ) )
return - V_210 ;
if ( ! V_215 -> V_201 -> V_202 ) {
F_5 ( V_215 , L_68 ) ;
return - V_33 ;
}
V_104 = V_215 -> V_201 -> V_303 ( V_215 ) ;
if ( V_104 )
return V_104 ;
if ( ! V_215 -> V_118 )
return - V_210 ;
if ( V_304 ) {
V_215 -> V_130 = V_144 ;
} else if ( ! V_215 -> V_130 &&
! F_71 ( V_215 , V_305 ) ) {
V_104 = F_36 ( V_215 ) ;
if ( V_104 )
F_21 ( V_215 , L_69 , V_104 ) ;
}
F_110 ( & V_215 -> V_103 , L_70 , V_215 -> V_217 ,
V_215 -> V_136 , V_215 -> V_138 , F_111 ( & V_4 ) ) ;
F_112 ( V_215 , F_20 ( & V_215 -> V_103 ) ) ;
V_104 = F_113 ( & V_215 -> V_103 ) ;
if ( ! V_104 )
V_215 -> V_116 |= V_302 ;
else
F_114 ( V_215 ) ;
return V_104 ;
}
struct V_2 * F_115 ( void )
{
struct V_2 * V_215 ;
int V_104 = - V_36 ;
V_215 = F_2 ( sizeof( * V_215 ) , V_10 ) ;
if ( V_215 == NULL )
return F_116 ( V_104 ) ;
F_117 ( & V_215 -> V_103 ) ;
V_215 -> V_103 . V_306 = F_27 ;
V_215 -> V_103 . V_217 = & V_307 ;
F_118 ( & V_215 -> V_103 ) ;
F_25 ( V_215 ) ;
F_119 ( & V_215 -> V_308 ) ;
F_26 ( & V_215 -> V_186 ) ;
F_120 ( & V_215 -> V_309 ) ;
F_121 ( & V_215 -> V_264 , 1 ) ;
F_121 ( & V_215 -> V_211 , 1 ) ;
return V_215 ;
}
static void F_122 ( struct V_2 * V_215 )
{
if ( V_215 -> V_116 & V_302 ) {
F_123 ( & V_215 -> V_103 ) ;
F_114 ( V_215 ) ;
V_215 -> V_116 &= ~ V_302 ;
}
F_8 ( V_215 -> V_118 ) ;
V_215 -> V_118 = NULL ;
V_215 -> V_151 = 0 ;
}
void F_124 ( struct V_2 * V_215 )
{
F_122 ( V_215 ) ;
F_125 ( & V_215 -> V_103 ) ;
}
int F_126 ( struct V_184 * V_185 , struct V_310 * V_311 ,
const char * V_312 )
{
int V_104 ;
V_185 -> V_173 . V_188 = V_185 -> V_188 ;
V_185 -> V_173 . V_217 = & V_307 ;
V_185 -> V_173 . V_311 = V_311 ;
V_185 -> V_173 . V_312 = V_312 ;
F_26 ( & V_185 -> V_262 ) ;
F_120 ( & V_185 -> V_261 ) ;
V_104 = F_127 ( & V_185 -> V_173 ) ;
if ( V_104 )
return V_104 ;
V_104 = F_128 ( & V_185 -> V_173 , & V_313 ) ;
if ( V_104 )
F_129 ( & V_185 -> V_173 ) ;
return V_104 ;
}
void F_130 ( struct V_184 * V_185 )
{
F_131 ( & V_185 -> V_173 , & V_313 ) ;
F_129 ( & V_185 -> V_173 ) ;
F_91 ( V_185 ) ;
}
int F_132 ( struct V_2 * V_62 )
{
struct V_314 * V_315 ;
int V_48 ;
if ( ! ( V_62 -> V_189 & V_190 ) )
return 0 ;
F_95 (hidinput, &hid->inputs, list) {
for ( V_48 = 0 ; V_48 < F_133 ( V_316 ) ; V_48 ++ )
if ( V_315 -> V_317 -> V_318 [ V_48 ] )
return 1 ;
}
return 0 ;
}
static int T_10 F_134 ( void )
{
int V_104 ;
if ( V_319 )
F_135 ( L_71
L_72 ) ;
V_104 = F_136 ( & V_307 ) ;
if ( V_104 ) {
F_137 ( L_73 ) ;
goto V_320;
}
V_104 = F_138 () ;
if ( V_104 )
goto V_321;
F_139 () ;
return 0 ;
V_321:
F_140 ( & V_307 ) ;
V_320:
return V_104 ;
}
static void T_11 F_141 ( void )
{
F_142 () ;
F_143 () ;
F_140 ( & V_307 ) ;
}
