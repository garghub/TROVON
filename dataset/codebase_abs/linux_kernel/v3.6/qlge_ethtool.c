static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
struct V_5 * V_5 ;
struct V_6 * V_6 ;
if ( ! F_2 ( V_2 -> V_7 ) )
return V_4 ;
V_6 = (struct V_6 * ) & V_2 -> V_5 [ V_2 -> V_8 ] ;
if ( F_3 ( V_6 -> V_9 ) != V_2 -> V_10 ||
F_3 ( V_6 -> V_11 ) !=
V_2 -> V_12 ) {
for ( V_3 = V_2 -> V_8 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_5 = & V_2 -> V_5 [ V_3 ] ;
V_6 = (struct V_6 * ) V_5 ;
V_6 -> V_9 = F_4 ( V_2 -> V_10 ) ;
V_6 -> V_11 =
F_4 ( V_2 -> V_12 ) ;
V_6 -> V_14 = V_15 ;
V_4 = F_5 ( V_2 , V_6 , sizeof( * V_6 ) ,
V_16 , V_5 -> V_17 ) ;
if ( V_4 ) {
F_6 ( V_2 , V_18 , V_2 -> V_7 ,
L_1 ) ;
goto exit;
}
}
}
V_6 = (struct V_6 * ) & V_2 -> V_5 [ 0 ] ;
if ( F_3 ( V_6 -> V_9 ) != V_2 -> V_19 ||
F_3 ( V_6 -> V_11 ) !=
V_2 -> V_20 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_8 ; V_3 ++ , V_5 ++ ) {
V_5 = & V_2 -> V_5 [ V_3 ] ;
V_6 = (struct V_6 * ) V_5 ;
V_6 -> V_9 = F_4 ( V_2 -> V_19 ) ;
V_6 -> V_11 =
F_4 ( V_2 -> V_20 ) ;
V_6 -> V_14 = V_15 ;
V_4 = F_5 ( V_2 , V_6 , sizeof( * V_6 ) ,
V_16 , V_5 -> V_17 ) ;
if ( V_4 ) {
F_6 ( V_2 , V_18 , V_2 -> V_7 ,
L_1 ) ;
goto exit;
}
}
}
exit:
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_21 ;
T_2 * V_22 = & V_2 -> V_23 . V_24 ;
F_8 ( & V_2 -> V_25 ) ;
if ( F_9 ( V_2 , V_2 -> V_26 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_2 ) ;
goto V_28;
}
for ( V_3 = 0x200 ; V_3 < 0x280 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
for ( V_3 = 0x300 ; V_3 < 0x3d0 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
for ( V_3 = 0x500 ; V_3 < 0x540 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
for ( V_3 = 0x568 ; V_3 < 0x5a8 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
if ( F_10 ( V_2 , 0x5b8 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 , V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_29:
F_11 ( V_2 , V_2 -> V_26 ) ;
V_28:
F_12 ( & V_2 -> V_25 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_30 * V_31 , T_1 V_32 , T_3 * V_33 )
{
int V_34 ;
switch ( V_32 ) {
case V_35 :
memcpy ( V_33 , * V_36 , V_37 * V_38 ) ;
break;
case V_39 :
for ( V_34 = 0 ; V_34 < V_40 ; V_34 ++ ) {
memcpy ( V_33 + V_34 * V_38 ,
V_41 [ V_34 ] . V_42 ,
V_38 ) ;
}
break;
}
}
static int F_15 ( struct V_30 * V_31 , int V_43 )
{
switch ( V_43 ) {
case V_35 :
return V_37 ;
case V_39 :
return V_40 ;
default:
return - V_44 ;
}
}
static void
F_16 ( struct V_30 * V_7 ,
struct V_45 * V_46 , T_2 * V_21 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
int V_34 , V_47 ;
V_47 = V_40 ;
F_7 ( V_2 ) ;
for ( V_34 = 0 ; V_34 < V_47 ; V_34 ++ ) {
char * V_48 = ( char * ) V_2 +
V_41 [ V_34 ] . V_49 ;
* V_21 ++ = ( V_41 [ V_34 ] . V_50 ==
sizeof( T_2 ) ) ? * ( T_2 * ) V_48 : ( * ( T_1 * ) V_48 ) ;
}
}
static int F_18 ( struct V_30 * V_7 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
V_52 -> V_53 = V_54 ;
V_52 -> V_55 = V_56 ;
V_52 -> V_57 = V_58 ;
V_52 -> V_59 = V_60 ;
if ( ( V_2 -> V_61 & V_62 ) ==
V_63 ) {
V_52 -> V_53 |= ( V_64 | V_65 ) ;
V_52 -> V_55 |= ( V_66 | V_67 ) ;
V_52 -> V_68 = V_69 ;
} else {
V_52 -> V_53 |= V_70 ;
V_52 -> V_55 |= V_71 ;
V_52 -> V_68 = V_72 ;
}
F_19 ( V_52 , V_73 ) ;
V_52 -> V_74 = V_75 ;
return 0 ;
}
static void F_20 ( struct V_30 * V_7 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
F_21 ( V_77 -> V_78 , V_79 , sizeof( V_77 -> V_78 ) ) ;
F_21 ( V_77 -> V_80 , V_81 ,
sizeof( V_77 -> V_80 ) ) ;
snprintf ( V_77 -> V_82 , sizeof( V_77 -> V_82 ) ,
L_4 ,
( V_2 -> V_83 & 0x00ff0000 ) >> 16 ,
( V_2 -> V_83 & 0x0000ff00 ) >> 8 ,
( V_2 -> V_83 & 0x000000ff ) ) ;
F_21 ( V_77 -> V_84 , F_22 ( V_2 -> V_85 ) ,
sizeof( V_77 -> V_84 ) ) ;
V_77 -> V_86 = 0 ;
V_77 -> V_87 = 0 ;
if ( ! F_23 ( V_88 , & V_2 -> V_14 ) )
V_77 -> V_89 = sizeof( struct V_90 ) ;
else
V_77 -> V_89 = sizeof( struct V_91 ) ;
V_77 -> V_92 = 0 ;
}
static void F_24 ( struct V_30 * V_7 , struct V_93 * V_94 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
unsigned short V_95 = V_2 -> V_85 -> V_96 ;
if ( V_95 == V_97 ||
V_95 == V_98 ) {
V_94 -> V_53 = V_99 ;
V_94 -> V_100 = V_2 -> V_94 ;
}
}
static int F_25 ( struct V_30 * V_7 , struct V_93 * V_94 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
unsigned short V_95 = V_2 -> V_85 -> V_96 ;
if ( V_95 != V_97 &&
V_95 != V_98 ) {
F_26 ( V_2 , V_27 , V_2 -> V_7 ,
L_5 ) ;
return - V_44 ;
}
if ( V_94 -> V_100 & ~ V_99 )
return - V_101 ;
V_2 -> V_94 = V_94 -> V_100 ;
F_26 ( V_2 , V_27 , V_2 -> V_7 , L_6 , V_2 -> V_94 ) ;
return 0 ;
}
static int F_27 ( struct V_30 * V_7 ,
enum V_102 V_103 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
switch ( V_103 ) {
case V_104 :
if ( F_28 ( V_2 ) )
return - V_105 ;
F_29 ( V_2 , V_106 ) ;
return 0 ;
case V_107 :
if ( F_29 ( V_2 , V_2 -> V_108 ) )
return - V_105 ;
return 0 ;
default:
return - V_101 ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
if ( F_31 ( V_2 -> V_7 ) ) {
F_32 ( V_109 , & V_2 -> V_14 ) ;
F_33 ( V_2 -> V_7 ) ;
} else
F_34 ( V_109 , & V_2 -> V_14 ) ;
V_2 -> V_110 |= V_111 ;
return F_35 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
V_2 -> V_110 &= ~ V_111 ;
F_35 ( V_2 ) ;
if ( F_23 ( V_109 , & V_2 -> V_14 ) ) {
F_37 ( V_2 -> V_7 ) ;
F_34 ( V_109 , & V_2 -> V_14 ) ;
}
}
static void F_38 ( struct V_112 * V_113 ,
unsigned int V_114 )
{
memset ( V_113 -> V_21 , 0xFF , V_114 ) ;
V_114 &= ~ 1 ;
memset ( & V_113 -> V_21 [ V_114 / 2 ] , 0xAA , V_114 / 2 - 1 ) ;
memset ( & V_113 -> V_21 [ V_114 / 2 + 10 ] , 0xBE , 1 ) ;
memset ( & V_113 -> V_21 [ V_114 / 2 + 12 ] , 0xAF , 1 ) ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
unsigned int V_114 = V_113 -> V_115 ;
if ( ( * ( V_113 -> V_21 + 3 ) == 0xFF ) &&
( * ( V_113 -> V_21 + V_114 / 2 + 10 ) == 0xBE ) &&
( * ( V_113 -> V_21 + V_114 / 2 + 12 ) == 0xAF ) ) {
F_40 ( & V_2 -> V_116 ) ;
return;
}
}
static int F_41 ( struct V_1 * V_2 )
{
int V_3 ;
T_4 V_117 ;
struct V_112 * V_113 ;
unsigned int V_118 = V_119 ;
for ( V_3 = 0 ; V_3 < 64 ; V_3 ++ ) {
V_113 = F_42 ( V_2 -> V_7 , V_118 ) ;
if ( ! V_113 )
return - V_120 ;
V_113 -> V_121 = 0 ;
F_43 ( V_113 , V_118 ) ;
F_38 ( V_113 , V_118 ) ;
V_117 = F_44 ( V_113 , V_2 -> V_7 ) ;
if ( V_117 != V_122 )
return - V_123 ;
F_45 ( & V_2 -> V_116 ) ;
}
F_46 ( 2 ) ;
F_47 ( & V_2 -> V_5 [ 0 ] , 128 ) ;
return F_48 ( & V_2 -> V_116 ) ? - V_105 : 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_2 * V_21 )
{
* V_21 = F_30 ( V_2 ) ;
if ( * V_21 )
goto V_124;
* V_21 = F_41 ( V_2 ) ;
V_124:
F_36 ( V_2 ) ;
return * V_21 ;
}
static void F_50 ( struct V_30 * V_7 ,
struct V_125 * V_126 , T_2 * V_21 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
memset ( V_21 , 0 , sizeof( T_2 ) * V_37 ) ;
if ( F_2 ( V_7 ) ) {
F_32 ( V_127 , & V_2 -> V_14 ) ;
if ( V_126 -> V_14 == V_128 ) {
if ( F_49 ( V_2 , & V_21 [ 0 ] ) )
V_126 -> V_14 |= V_129 ;
} else {
V_21 [ 0 ] = 0 ;
}
F_34 ( V_127 , & V_2 -> V_14 ) ;
F_51 ( 4 * 1000 ) ;
} else {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_7 ) ;
V_126 -> V_14 |= V_129 ;
}
}
static int F_52 ( struct V_30 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
if ( ! F_23 ( V_88 , & V_2 -> V_14 ) )
return sizeof( struct V_90 ) ;
else
return sizeof( struct V_91 ) ;
}
static void F_53 ( struct V_30 * V_7 ,
struct V_130 * V_131 , void * V_48 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
F_54 ( V_2 , V_48 ) ;
V_2 -> V_132 = 0 ;
if ( ! F_23 ( V_88 , & V_2 -> V_14 ) )
V_131 -> V_115 = sizeof( struct V_90 ) ;
else
V_131 -> V_115 = sizeof( struct V_91 ) ;
}
static int F_55 ( struct V_30 * V_31 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_17 ( V_31 ) ;
V_134 -> V_19 = V_2 -> V_19 ;
V_134 -> V_10 = V_2 -> V_10 ;
V_134 -> V_20 = V_2 -> V_20 ;
V_134 -> V_12 = V_2 -> V_12 ;
return 0 ;
}
static int F_56 ( struct V_30 * V_7 , struct V_133 * V_134 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
if ( V_134 -> V_19 > V_2 -> V_135 / 2 )
return - V_101 ;
if ( V_134 -> V_20 > V_136 )
return - V_101 ;
if ( V_134 -> V_10 > V_2 -> V_137 / 2 )
return - V_101 ;
if ( V_134 -> V_12 > V_136 )
return - V_101 ;
if ( V_2 -> V_19 == V_134 -> V_19 &&
V_2 -> V_10 == V_134 -> V_10 &&
V_2 -> V_20 == V_134 -> V_20 &&
V_2 -> V_12 == V_134 -> V_12 )
return 0 ;
V_2 -> V_19 = V_134 -> V_19 ;
V_2 -> V_10 = V_134 -> V_10 ;
V_2 -> V_20 = V_134 -> V_20 ;
V_2 -> V_12 = V_134 -> V_12 ;
return F_1 ( V_2 ) ;
}
static void F_57 ( struct V_30 * V_138 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_17 ( V_138 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_110 & V_141 ) {
V_140 -> V_142 = 1 ;
V_140 -> V_143 = 1 ;
}
}
static int F_59 ( struct V_30 * V_138 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_17 ( V_138 ) ;
int V_4 = 0 ;
if ( ( V_140 -> V_142 ) && ( V_140 -> V_143 ) )
V_2 -> V_110 |= V_141 ;
else if ( ! V_140 -> V_142 && ! V_140 -> V_143 )
V_2 -> V_110 &= ~ V_141 ;
else
return - V_101 ;
V_4 = F_35 ( V_2 ) ;
return V_4 ;
}
static T_1 F_60 ( struct V_30 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
return V_2 -> V_144 ;
}
static void F_61 ( struct V_30 * V_7 , T_1 V_145 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
V_2 -> V_144 = V_145 ;
}
