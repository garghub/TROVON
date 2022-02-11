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
V_22 += V_30 ;
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
static void F_14 ( struct V_31 * V_32 , T_1 V_33 , T_3 * V_34 )
{
int V_35 ;
switch ( V_33 ) {
case V_36 :
memcpy ( V_34 , * V_37 , V_38 * V_39 ) ;
break;
case V_40 :
for ( V_35 = 0 ; V_35 < V_41 ; V_35 ++ ) {
memcpy ( V_34 + V_35 * V_39 ,
V_42 [ V_35 ] . V_43 ,
V_39 ) ;
}
break;
}
}
static int F_15 ( struct V_31 * V_32 , int V_44 )
{
switch ( V_44 ) {
case V_36 :
return V_38 ;
case V_40 :
return V_41 ;
default:
return - V_45 ;
}
}
static void
F_16 ( struct V_31 * V_7 ,
struct V_46 * V_47 , T_2 * V_21 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
int V_35 , V_48 ;
V_48 = V_41 ;
F_7 ( V_2 ) ;
for ( V_35 = 0 ; V_35 < V_48 ; V_35 ++ ) {
char * V_49 = ( char * ) V_2 +
V_42 [ V_35 ] . V_50 ;
* V_21 ++ = ( V_42 [ V_35 ] . V_51 ==
sizeof( T_2 ) ) ? * ( T_2 * ) V_49 : ( * ( T_1 * ) V_49 ) ;
}
}
static int F_18 ( struct V_31 * V_7 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
V_53 -> V_54 = V_55 ;
V_53 -> V_56 = V_57 ;
V_53 -> V_58 = V_59 ;
if ( ( V_2 -> V_60 & V_61 ) ==
V_62 ) {
V_53 -> V_54 |= ( V_63 | V_64 ) ;
V_53 -> V_56 |= ( V_65 | V_66 ) ;
V_53 -> V_67 = V_68 ;
V_53 -> V_69 = V_70 ;
} else {
V_53 -> V_54 |= V_71 ;
V_53 -> V_56 |= V_72 ;
V_53 -> V_67 = V_73 ;
}
F_19 ( V_53 , V_74 ) ;
V_53 -> V_75 = V_76 ;
return 0 ;
}
static void F_20 ( struct V_31 * V_7 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
F_21 ( V_78 -> V_79 , V_80 , sizeof( V_78 -> V_79 ) ) ;
F_21 ( V_78 -> V_81 , V_82 ,
sizeof( V_78 -> V_81 ) ) ;
snprintf ( V_78 -> V_83 , sizeof( V_78 -> V_83 ) ,
L_4 ,
( V_2 -> V_84 & 0x00ff0000 ) >> 16 ,
( V_2 -> V_84 & 0x0000ff00 ) >> 8 ,
( V_2 -> V_84 & 0x000000ff ) ) ;
F_21 ( V_78 -> V_85 , F_22 ( V_2 -> V_86 ) ,
sizeof( V_78 -> V_85 ) ) ;
}
static void F_23 ( struct V_31 * V_7 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
unsigned short V_89 = V_2 -> V_86 -> V_90 ;
if ( V_89 == V_91 ||
V_89 == V_92 ) {
V_88 -> V_54 = V_93 ;
V_88 -> V_94 = V_2 -> V_88 ;
}
}
static int F_24 ( struct V_31 * V_7 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
unsigned short V_89 = V_2 -> V_86 -> V_90 ;
if ( V_89 != V_91 &&
V_89 != V_92 ) {
F_25 ( V_2 , V_27 , V_2 -> V_7 ,
L_5 ) ;
return - V_45 ;
}
if ( V_88 -> V_94 & ~ V_93 )
return - V_95 ;
V_2 -> V_88 = V_88 -> V_94 ;
F_25 ( V_2 , V_27 , V_2 -> V_7 , L_6 , V_2 -> V_88 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_7 ,
enum V_96 V_97 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
switch ( V_97 ) {
case V_98 :
if ( F_27 ( V_2 ) )
return - V_99 ;
F_28 ( V_2 , V_100 ) ;
return 0 ;
case V_101 :
if ( F_28 ( V_2 , V_2 -> V_102 ) )
return - V_99 ;
return 0 ;
default:
return - V_95 ;
}
}
static int F_29 ( struct V_1 * V_2 )
{
if ( F_30 ( V_2 -> V_7 ) ) {
F_31 ( V_103 , & V_2 -> V_14 ) ;
F_32 ( V_2 -> V_7 ) ;
} else
F_33 ( V_103 , & V_2 -> V_14 ) ;
V_2 -> V_104 |= V_105 ;
return F_34 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_104 &= ~ V_105 ;
F_34 ( V_2 ) ;
if ( F_36 ( V_103 , & V_2 -> V_14 ) ) {
F_37 ( V_2 -> V_7 ) ;
F_33 ( V_103 , & V_2 -> V_14 ) ;
}
}
static void F_38 ( struct V_106 * V_107 ,
unsigned int V_108 )
{
memset ( V_107 -> V_21 , 0xFF , V_108 ) ;
V_108 &= ~ 1 ;
memset ( & V_107 -> V_21 [ V_108 / 2 ] , 0xAA , V_108 / 2 - 1 ) ;
memset ( & V_107 -> V_21 [ V_108 / 2 + 10 ] , 0xBE , 1 ) ;
memset ( & V_107 -> V_21 [ V_108 / 2 + 12 ] , 0xAF , 1 ) ;
}
void F_39 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
unsigned int V_108 = V_107 -> V_109 ;
if ( ( * ( V_107 -> V_21 + 3 ) == 0xFF ) &&
( * ( V_107 -> V_21 + V_108 / 2 + 10 ) == 0xBE ) &&
( * ( V_107 -> V_21 + V_108 / 2 + 12 ) == 0xAF ) ) {
F_40 ( & V_2 -> V_110 ) ;
return;
}
}
static int F_41 ( struct V_1 * V_2 )
{
int V_3 ;
T_4 V_111 ;
struct V_106 * V_107 ;
unsigned int V_112 = V_113 ;
for ( V_3 = 0 ; V_3 < 64 ; V_3 ++ ) {
V_107 = F_42 ( V_2 -> V_7 , V_112 ) ;
if ( ! V_107 )
return - V_114 ;
V_107 -> V_115 = 0 ;
F_43 ( V_107 , V_112 ) ;
F_38 ( V_107 , V_112 ) ;
V_111 = F_44 ( V_107 , V_2 -> V_7 ) ;
if ( V_111 != V_116 )
return - V_117 ;
F_45 ( & V_2 -> V_110 ) ;
}
F_46 ( 2 ) ;
F_47 ( & V_2 -> V_5 [ 0 ] , 128 ) ;
return F_48 ( & V_2 -> V_110 ) ? - V_99 : 0 ;
}
static int F_49 ( struct V_1 * V_2 , T_2 * V_21 )
{
* V_21 = F_29 ( V_2 ) ;
if ( * V_21 )
goto V_118;
* V_21 = F_41 ( V_2 ) ;
V_118:
F_35 ( V_2 ) ;
return * V_21 ;
}
static void F_50 ( struct V_31 * V_7 ,
struct V_119 * V_120 , T_2 * V_21 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
memset ( V_21 , 0 , sizeof( T_2 ) * V_38 ) ;
if ( F_2 ( V_7 ) ) {
F_31 ( V_121 , & V_2 -> V_14 ) ;
if ( V_120 -> V_14 == V_122 ) {
if ( F_49 ( V_2 , & V_21 [ 0 ] ) )
V_120 -> V_14 |= V_123 ;
} else {
V_21 [ 0 ] = 0 ;
}
F_33 ( V_121 , & V_2 -> V_14 ) ;
F_51 ( 4 * 1000 ) ;
} else {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_7 ) ;
V_120 -> V_14 |= V_123 ;
}
}
static int F_52 ( struct V_31 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
if ( ! F_36 ( V_124 , & V_2 -> V_14 ) )
return sizeof( struct V_125 ) ;
else
return sizeof( struct V_126 ) ;
}
static void F_53 ( struct V_31 * V_7 ,
struct V_127 * V_128 , void * V_49 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
F_54 ( V_2 , V_49 ) ;
V_2 -> V_129 = 0 ;
if ( ! F_36 ( V_124 , & V_2 -> V_14 ) )
V_128 -> V_109 = sizeof( struct V_125 ) ;
else
V_128 -> V_109 = sizeof( struct V_126 ) ;
}
static int F_55 ( struct V_31 * V_32 , struct V_130 * V_131 )
{
struct V_1 * V_2 = F_17 ( V_32 ) ;
V_131 -> V_19 = V_2 -> V_19 ;
V_131 -> V_10 = V_2 -> V_10 ;
V_131 -> V_20 = V_2 -> V_20 ;
V_131 -> V_12 = V_2 -> V_12 ;
return 0 ;
}
static int F_56 ( struct V_31 * V_7 , struct V_130 * V_131 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
if ( V_131 -> V_19 > V_2 -> V_132 / 2 )
return - V_95 ;
if ( V_131 -> V_20 > V_133 )
return - V_95 ;
if ( V_131 -> V_10 > V_2 -> V_134 / 2 )
return - V_95 ;
if ( V_131 -> V_12 > V_133 )
return - V_95 ;
if ( V_2 -> V_19 == V_131 -> V_19 &&
V_2 -> V_10 == V_131 -> V_10 &&
V_2 -> V_20 == V_131 -> V_20 &&
V_2 -> V_12 == V_131 -> V_12 )
return 0 ;
V_2 -> V_19 = V_131 -> V_19 ;
V_2 -> V_10 = V_131 -> V_10 ;
V_2 -> V_20 = V_131 -> V_20 ;
V_2 -> V_12 = V_131 -> V_12 ;
return F_1 ( V_2 ) ;
}
static void F_57 ( struct V_31 * V_135 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_17 ( V_135 ) ;
F_58 ( V_2 ) ;
if ( V_2 -> V_104 & V_138 ) {
V_137 -> V_139 = 1 ;
V_137 -> V_140 = 1 ;
}
}
static int F_59 ( struct V_31 * V_135 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_17 ( V_135 ) ;
int V_4 = 0 ;
if ( ( V_137 -> V_139 ) && ( V_137 -> V_140 ) )
V_2 -> V_104 |= V_138 ;
else if ( ! V_137 -> V_139 && ! V_137 -> V_140 )
V_2 -> V_104 &= ~ V_138 ;
else
return - V_95 ;
V_4 = F_34 ( V_2 ) ;
return V_4 ;
}
static T_1 F_60 ( struct V_31 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
return V_2 -> V_141 ;
}
static void F_61 ( struct V_31 * V_7 , T_1 V_142 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
V_2 -> V_141 = V_142 ;
}
