static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , int V_4 , T_1 V_5 )
{
int V_6 , V_7 ;
V_6 = F_2 ( V_2 , F_3 ( V_2 , V_5 ) ,
V_3 , V_4 , & V_7 , 100 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 * V_8 , int V_4 , T_1 V_5 )
{
int V_6 , V_7 ;
V_6 = F_2 ( V_2 , F_5 ( V_2 , V_5 ) ,
V_8 , V_4 , & V_7 , 200 ) ;
return V_6 ;
}
static int F_6 ( struct V_9 * V_10 ,
T_1 * V_11 , int V_12 , T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
T_1 * V_18 ;
int V_6 = 0 ;
if ( V_16 -> V_19 == NULL ) {
V_16 -> V_19 = F_7 ( 64 , V_20 ) ;
if ( V_16 -> V_19 == NULL ) {
F_8 ( L_1 ) ;
return - V_21 ;
}
}
V_18 = V_16 -> V_19 ;
V_6 = F_9 ( & V_10 -> V_22 ) ;
if ( V_6 < 0 )
return - V_23 ;
memcpy ( V_18 , V_11 , ( V_12 < 64 ) ? V_12 : 64 ) ;
V_6 |= F_1 ( V_10 -> V_24 , V_18 , V_12 , 0x01 ) ;
V_6 |= F_4 ( V_10 -> V_24 , V_18 , ( V_14 < 64 ) ?
V_14 : 64 , 0x01 ) ;
if ( V_14 > 0 )
memcpy ( V_13 , V_18 , V_14 ) ;
F_10 ( & V_10 -> V_22 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
T_1 V_26 [] = V_27 ;
T_1 V_28 [] = V_29 ;
int V_6 ;
T_1 V_30 [ 1 ] ;
if ( V_16 -> V_31 )
V_6 = F_6 ( V_10 , V_26 , sizeof( V_26 ) ,
V_30 , sizeof( V_30 ) ) ;
V_6 = F_6 ( V_10 , V_28 , sizeof( V_28 ) ,
V_30 , sizeof( V_30 ) ) ;
return V_6 ;
}
static int F_12 ( struct V_9 * V_10 , T_1 V_32 , T_2 V_33 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_34 [] = V_35 ;
static T_1 V_13 [ 1 ] ;
T_1 V_36 = V_32 * 2 ;
T_1 V_37 = V_36 + 2 ;
int V_6 = 0 ;
F_13 ( 1 , L_2 , V_33 ) ;
if ( V_16 -> V_38 == 0 )
V_6 |= F_11 ( V_10 ) ;
V_34 [ 2 ] = V_36 ;
V_34 [ 3 ] = ( T_1 ) V_33 & 0xff ;
V_34 [ 4 ] = V_36 + 1 ;
V_34 [ 5 ] = ( T_1 ) ( V_33 >> 8 ) ;
if ( V_37 > V_16 -> V_38 )
V_16 -> V_38 = V_37 ;
V_34 [ 7 ] = 0x80 + V_16 -> V_38 ;
V_6 |= F_6 ( V_10 , V_34 ,
sizeof( V_34 ) , V_13 , sizeof( V_13 ) ) ;
if ( V_16 -> V_28 )
V_6 |= F_11 ( V_10 ) ;
return V_6 ;
}
static void F_14 ( struct V_39 * V_40 )
{
struct V_15 * V_16 = F_15 ( V_40 ) ;
struct V_41 * V_42 = V_40 -> V_42 [ 0 ] ;
struct V_43 * V_44 ;
T_3 V_45 = 0 , V_46 = 0 ;
if ( ! V_42 )
return;
V_44 = & V_42 -> V_47 ;
V_44 -> V_48 . V_4 = 1 ;
V_44 -> V_48 . V_49 [ 0 ] . V_50 = V_51 ;
V_44 -> V_52 . V_4 = 1 ;
V_44 -> V_52 . V_49 [ 0 ] . V_50 = V_51 ;
V_44 -> V_53 . V_4 = 1 ;
V_44 -> V_53 . V_49 [ 0 ] . V_50 = V_51 ;
V_44 -> V_54 . V_4 = 1 ;
V_44 -> V_54 . V_49 [ 0 ] . V_50 = V_51 ;
if ( V_16 -> V_55 ) {
V_44 -> V_56 . V_4 = 1 ;
V_44 -> V_56 . V_49 [ 0 ] . V_50 = V_51 ;
V_44 -> V_57 . V_4 = 1 ;
V_44 -> V_57 . V_49 [ 0 ] . V_50 = V_51 ;
return;
}
switch ( V_16 -> V_58 ) {
case V_59 :
V_45 = F_16 ( 0xff - V_16 -> V_60 ) ;
V_46 = F_16 ( 0xff - V_16 -> V_61 ) ;
break;
case V_62 :
case V_63 :
V_45 = 0xffff - ( ( ( V_16 -> V_60 * 2 ) << 8 ) * 5 / 4 ) ;
V_46 = F_16 ( ( 0xff - V_16 -> V_61 - 0xa1 ) * 3 ) ;
break;
case V_64 :
V_45 = F_16 ( V_16 -> V_60 ) ;
V_46 = F_16 ( V_16 -> V_61 ) ;
}
V_44 -> V_56 . V_4 = 1 ;
V_44 -> V_56 . V_49 [ 0 ] . V_50 = V_65 ;
V_44 -> V_56 . V_49 [ 0 ] . V_66 = ( V_67 ) V_45 ;
V_44 -> V_57 . V_4 = 1 ;
V_44 -> V_57 . V_49 [ 0 ] . V_50 = V_65 ;
V_44 -> V_57 . V_49 [ 0 ] . V_66 = ( V_67 ) V_46 ;
}
static void F_17 ( struct V_68 * V_69 )
{
struct V_39 * V_40 = V_69 -> V_70 ;
struct V_15 * V_16 = F_15 ( V_40 ) ;
static T_1 * V_71 , * V_13 ;
int V_72 = 0 , V_73 ;
T_3 V_74 ;
T_1 V_75 = 0 ;
switch ( V_69 -> V_76 ) {
case 0 :
case - V_77 :
break;
case - V_78 :
case - V_79 :
case - V_80 :
return;
default:
F_8 ( L_3 , V_69 -> V_76 ) ;
break;
}
V_13 = ( T_1 * ) V_69 -> V_81 ;
V_73 = ( ( V_69 -> V_82 / 8 ) > 4 )
? 4 : ( V_69 -> V_82 / 8 ) ;
for ( V_72 = 0 ; V_72 < V_73 ; ++ V_72 ) {
V_71 = ( T_1 * ) & V_13 [ V_72 * 8 ] ;
F_13 ( 5 , L_4 ,
V_73 , V_72 , V_71 [ 0 ] , V_71 [ 1 ] ) ;
switch ( V_71 [ 0 ] ) {
case 0xaa :
F_18 ( 1 , L_5 , V_71 ) ;
if ( ( V_71 [ 4 ] + V_71 [ 5 ] ) == 0xff ) {
V_74 = F_19 ( ( V_71 [ 2 ] ^ 0xff ) << 8 |
( V_71 [ 3 ] > 0 ) ? ( V_71 [ 3 ] ^ 0xff ) : 0 ,
V_71 [ 5 ] ) ;
F_13 ( 1 , L_6 , V_74 ) ;
if ( F_20 ( V_40 ) -> V_83 != NULL )
F_21 ( F_20 ( V_40 ) -> V_83 ,
V_84 , V_74 , 0 ) ;
}
break;
case 0xbb :
switch ( V_16 -> V_58 ) {
case V_59 :
V_75 = V_71 [ 2 ] & F_22 ( 5 ) ;
V_16 -> V_60 = V_71 [ 4 ] ;
V_16 -> V_61 = V_71 [ 3 ] ;
V_16 -> V_85 = V_71 [ 7 ] ;
break;
case V_62 :
case V_63 :
if ( V_71 [ 1 ] == 0x03 ) {
V_75 = V_71 [ 2 ] & F_22 ( 4 ) ;
V_16 -> V_60 = V_71 [ 3 ] ;
V_16 -> V_61 = V_71 [ 4 ] ;
} else {
V_16 -> V_60 = V_71 [ 4 ] ;
V_16 -> V_61 = V_71 [ 5 ] ;
}
break;
case V_64 :
V_75 = V_71 [ 2 ] & 0xee ;
V_16 -> V_60 = V_71 [ 5 ] ;
V_16 -> V_61 = V_71 [ 4 ] ;
V_16 -> V_85 = V_71 [ 7 ] ;
default:
break;
}
V_75 |= V_71 [ 2 ] & F_22 ( 0 ) ;
if ( ! V_75 )
V_16 -> V_86 &= ~ V_87 ;
F_14 ( V_40 ) ;
F_18 ( 5 , L_7 , V_71 ) ;
break;
case 0xcc :
F_18 ( 1 , L_8 , V_71 ) ;
break;
default:
F_18 ( 1 , L_9 , V_71 ) ;
break;
}
}
F_23 ( V_69 , V_88 ) ;
V_16 -> V_89 = V_90 + F_24 ( 200 ) ;
}
static int F_25 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_20 ( V_40 ) ;
struct V_15 * V_91 = F_15 ( V_40 ) ;
struct V_92 * V_93 ;
V_91 -> V_69 = F_26 ( 0 , V_88 ) ;
if ( V_91 -> V_69 == NULL )
return - V_21 ;
V_91 -> V_94 = F_27 ( V_10 -> V_24 , 128 , V_88 ,
& V_91 -> V_69 -> V_95 ) ;
if ( V_91 -> V_94 == NULL )
return - V_21 ;
F_28 ( V_91 -> V_69 ,
V_10 -> V_24 ,
F_29 ( V_10 -> V_24 , 0xa ) ,
V_91 -> V_94 ,
128 ,
F_17 ,
V_40 ,
8 ) ;
V_93 = F_30 ( V_10 -> V_24 , V_91 -> V_69 -> V_5 ) ;
if ( F_31 ( & V_93 -> V_96 ) == V_97 )
V_91 -> V_69 -> V_5 = F_5 ( V_10 -> V_24 , 0xa ) ,
V_91 -> V_69 -> V_98 |= V_99 ;
F_23 ( V_91 -> V_69 , V_88 ) ;
F_8 ( L_10 ) ;
return 0 ;
}
static int F_32 ( struct V_39 * V_40 , int V_100 )
{
struct V_9 * V_10 = F_20 ( V_40 ) ;
struct V_15 * V_16 = F_15 ( V_40 ) ;
static T_1 V_101 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 ;
F_13 ( 1 , L_11 ) ;
F_33 ( & V_10 -> V_102 ) ;
if ( ! V_100 ) {
V_6 |= F_6 ( V_10 , V_101 ,
sizeof( V_101 ) , V_13 , sizeof( V_13 ) ) ;
V_16 -> V_31 = true ;
} else
V_16 -> V_31 = false ;
V_16 -> V_38 = 0 ;
F_10 ( & V_10 -> V_102 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_40 , int V_32 , T_2 V_103 ,
int V_100 )
{
struct V_9 * V_10 = F_20 ( V_40 ) ;
int V_6 = 0 ;
F_13 ( 3 , L_12 , V_104 ,
V_103 , V_32 , V_100 ) ;
if ( V_100 ) {
F_33 ( & V_10 -> V_102 ) ;
V_6 |= F_12 ( V_10 , V_32 , V_103 ) ;
F_10 ( & V_10 -> V_102 ) ;
}
return V_6 ;
}
static int F_35 ( struct V_9 * V_10 )
{
int V_6 = 0 ;
T_1 * V_105 ;
V_105 = F_36 ( 10 , V_20 ) ;
if ( ! V_105 )
return - V_21 ;
V_6 |= F_37 ( V_10 -> V_24 , F_38 ( V_10 -> V_24 , 0 ) ,
0x06 , 0x80 , 0x0302 , 0x00 , V_105 , 0x0006 , 200 ) ;
F_8 ( L_13 , V_6 , V_105 [ 2 ] ) ;
V_6 = ( V_6 < 0 ) ? - V_25 : V_105 [ 2 ] ;
F_39 ( V_105 ) ;
return V_6 ;
}
static int F_40 ( struct V_9 * V_10 ,
T_1 * V_11 , int V_12 , T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
V_16 -> V_55 = 1 ;
return F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
}
static int F_41 ( struct V_106 * V_40 , struct V_107 V_108 [] ,
int V_109 )
{
struct V_9 * V_10 = F_42 ( V_40 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_110 [ 64 ] , V_71 [ 64 ] ;
int V_72 , V_111 , V_112 ;
T_2 V_4 ;
T_1 V_113 = V_16 -> V_114 ;
F_33 ( & V_10 -> V_102 ) ;
if ( V_113 == 0 )
V_113 = 5 ;
for ( V_72 = 0 ; V_72 < V_109 ; V_72 ++ ) {
V_112 = V_108 [ V_72 ] . V_115 & V_116 ;
V_111 = V_72 + 1 < V_109 && V_108 [ V_72 + 1 ] . V_115 & V_116 ;
V_111 |= V_112 ;
V_113 = ( V_108 [ V_72 ] . V_117 == V_16 -> V_118 )
? ( V_111 ) ? V_16 -> V_119
: V_16 -> V_120
: V_16 -> V_114 ;
V_110 [ 0 ] = V_113 | ( V_111 << 7 ) ;
if ( V_113 == 5 )
V_110 [ 1 ] = ( V_111 ) ? 2 : V_108 [ V_72 ] . V_4 + 1 ;
else
V_110 [ 1 ] = V_108 [ V_72 ] . V_4 + V_111 + 1 ;
V_110 [ 2 ] = V_108 [ V_72 ] . V_117 << 1 ;
if ( V_111 ) {
if ( V_112 )
V_4 = 3 ;
else {
memcpy ( & V_110 [ 3 ] , V_108 [ V_72 ] . V_121 , V_108 [ V_72 ] . V_4 ) ;
V_110 [ V_108 [ V_72 ] . V_4 + 3 ] = V_108 [ V_72 + 1 ] . V_4 ;
V_4 = V_108 [ V_72 ] . V_4 + 4 ;
}
} else {
memcpy ( & V_110 [ 3 ] , V_108 [ V_72 ] . V_121 , V_108 [ V_72 ] . V_4 ) ;
V_4 = V_108 [ V_72 ] . V_4 + 3 ;
}
if ( F_40 ( V_10 , V_110 , V_4 , V_71 , 64 ) < 0 ) {
F_13 ( 1 , L_14 ) ;
F_10 ( & V_10 -> V_102 ) ;
return - V_23 ;
}
if ( V_111 ) {
if ( V_112 )
memcpy ( V_108 [ V_72 ] . V_121 , & V_71 [ 1 ] , V_108 [ V_72 ] . V_4 ) ;
else {
memcpy ( V_108 [ V_72 + 1 ] . V_121 , & V_71 [ 1 ] , V_108 [ V_72 + 1 ] . V_4 ) ;
V_72 ++ ;
}
}
}
F_10 ( & V_10 -> V_102 ) ;
return V_72 ;
}
static T_3 F_43 ( struct V_106 * V_122 )
{
return V_123 ;
}
static int F_44 ( struct V_41 * V_42 , int V_100 )
{
struct V_39 * V_40 = F_45 ( V_42 ) ;
struct V_9 * V_10 = F_20 ( V_40 ) ;
struct V_15 * V_16 = F_15 ( V_40 ) ;
static T_1 V_124 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_14 = sizeof( V_13 ) ;
F_13 ( 1 , L_15 , V_100 ) ;
if ( V_100 == 1 )
V_16 -> V_28 = 1 ;
else {
F_13 ( 1 , L_16 ) ;
F_33 ( & V_10 -> V_102 ) ;
V_6 = F_6 ( V_10 , V_124 ,
sizeof( V_124 ) , V_13 , V_14 ) ;
V_16 -> V_28 = 0 ;
V_16 -> V_55 = 1 ;
F_10 ( & V_10 -> V_102 ) ;
}
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static T_1 F_46 ( T_1 * V_125 , T_1 V_4 )
{
T_1 V_126 = 0 ;
while ( V_4 -- )
V_126 += * V_125 ++ ;
return V_126 ;
}
static int F_47 ( struct V_9 * V_10 ,
const struct V_127 * V_128 )
{
int V_6 = 0 ;
T_1 * V_105 ;
T_2 V_129 , V_12 , V_130 , V_131 , V_132 ;
T_1 V_133 , V_134 , V_72 ;
T_1 * V_135 ;
V_133 = 0x31 ;
V_130 = 1 ;
V_105 = F_36 ( 128 , V_20 ) ;
if ( ! V_105 ) {
F_8 ( L_17\
L_18 ) ;
return - V_21 ;
}
F_8 ( L_19 ) ;
for ( V_72 = 1 ; V_72 < 3 ; V_72 ++ ) {
V_131 = ( V_72 == 1 ) ? 0 : 512 ;
V_132 = ( V_72 == 1 ) ? 512 : V_128 -> V_136 ;
for ( V_129 = V_131 ; V_129 < V_132 ; V_129 += ( V_133 + 1 ) ) {
V_135 = ( T_1 * ) ( V_128 -> V_105 + V_129 ) ;
if ( ( V_132 - V_129 ) > V_133 ) {
V_105 [ 0 ] = V_72 ;
V_134 = V_133 ;
} else {
V_105 [ 0 ] = V_72 | 0x80 ;
V_134 = ( T_1 ) ( V_132 - V_129 ) - 1 ;
}
V_105 [ 1 ] = V_134 ;
memcpy ( & V_105 [ 2 ] , V_135 , V_134 + 1 ) ;
V_12 = ( T_1 ) V_134 + 4 ;
V_105 [ V_12 - 1 ] = F_46 ( V_135 , V_134 + 1 ) ;
F_13 ( 1 , L_20 , V_105 [ 3 ] ,
V_105 [ V_134 + 2 ] , V_105 [ V_134 + 3 ] ) ;
F_6 ( V_10 , V_105 , V_12 , V_105 , V_130 ) ;
V_6 |= ( V_105 [ 0 ] == 0x88 ) ? 0 : - 1 ;
}
}
V_105 [ 0 ] = 0x8a ;
V_130 = 1 ;
F_48 ( 2000 ) ;
F_6 ( V_10 , V_105 , V_130 , V_105 , V_130 ) ;
F_48 ( 400 ) ;
if ( V_6 < 0 )
F_8 ( L_21 , V_6 ) ;
else
F_8 ( L_22 ) ;
F_39 ( V_105 ) ;
return V_137 ;
}
static void F_49 ( struct V_9 * V_10 )
{
T_1 V_105 [ 1 ] = { 0 } ;
V_105 [ 0 ] = 0x0a ;
F_8 ( L_23 ) ;
F_6 ( V_10 , V_105 , sizeof( V_105 ) , V_105 , sizeof( V_105 ) ) ;
return;
}
static const char * F_50 ( struct V_9 * V_10 , int V_138 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_24 = V_10 -> V_24 ;
const struct V_127 * V_128 = NULL ;
const char * V_139 ;
int V_6 = 0 ;
V_138 = ( V_138 > 0 ) ? ( V_138 & 1 ) : 0 ;
switch ( F_51 ( V_24 -> V_140 . V_141 ) ) {
case 0x1122 :
switch ( V_16 -> V_142 ) {
default:
case V_63 :
V_139 = V_143 ;
V_6 = F_52 ( & V_128 , V_139 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_142 = V_63 ;
V_138 = 0 ;
break;
}
case V_59 :
V_139 = V_144 ;
V_6 = F_52 ( & V_128 , V_139 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_142 = V_59 ;
break;
}
V_16 -> V_142 = V_145 ;
break;
}
break;
case 0x1120 :
switch ( V_16 -> V_142 ) {
default:
case V_62 :
V_139 = V_146 ;
V_6 = F_52 ( & V_128 , V_139 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_142 = V_62 ;
V_138 = 0 ;
break;
}
case V_59 :
V_139 = V_147 ;
V_6 = F_52 ( & V_128 , V_139 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_142 = V_59 ;
break;
}
case V_63 :
V_139 = V_148 ;
V_6 = F_52 ( & V_128 , V_139 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_142 = V_63 ;
break;
}
V_16 -> V_142 = V_145 ;
V_138 = 0 ;
break;
}
break;
case 0x22f0 :
V_139 = V_149 ;
V_16 -> V_142 = V_64 ;
break;
default:
V_139 = V_146 ;
}
F_53 ( V_128 ) ;
if ( V_138 ) {
V_142 = V_16 -> V_142 ;
F_8 ( L_24 , V_139 ) ;
F_49 ( V_10 ) ;
return NULL ;
}
return V_139 ;
}
static int F_54 ( struct V_150 * V_151 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_151 -> V_152 ; V_72 ++ ) {
F_13 ( 3 , L_25 , V_72 ) ;
F_55 ( V_151 -> V_153 [ V_72 ] ) ;
}
V_151 -> V_152 = 0 ;
return 0 ;
}
static int F_56 ( struct V_41 * V_42 ,
enum V_154 V_155 )
{
struct V_9 * V_10 = F_57 ( V_42 ) ;
struct V_15 * V_16 = F_58 ( V_42 ) ;
static T_1 V_156 [] = V_157 ;
static T_1 V_158 [] = V_159 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_33 ( & V_10 -> V_102 ) ;
switch ( V_155 ) {
case V_160 :
V_6 |= F_6 ( V_10 ,
V_158 , V_4 , V_13 , V_14 ) ;
break;
case V_161 :
case V_162 :
default:
V_6 |= F_6 ( V_10 ,
V_156 , V_4 , V_13 , V_14 ) ;
break;
}
F_10 ( & V_10 -> V_102 ) ;
if ( V_16 -> V_58 == V_64 )
if ( V_16 -> V_163 )
V_16 -> V_163 ( V_42 , V_155 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_59 ( struct V_41 * V_42 , enum V_164 * V_76 )
{
struct V_9 * V_10 = F_57 ( V_42 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
int V_6 = 0 ;
if ( V_16 -> V_55 ) {
if ( V_16 -> V_165 ) {
V_6 = V_16 -> V_165 ( V_42 , V_76 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_16 -> V_86 = * V_76 ;
if ( * V_76 & V_87 && V_16 -> V_28 ) {
F_33 ( & V_10 -> V_102 ) ;
V_16 -> V_55 = 0 ;
V_6 = F_11 ( V_10 ) ;
F_10 ( & V_10 -> V_102 ) ;
}
return V_6 ;
}
if ( V_16 -> V_58 == V_64 &&
F_60 ( V_90 , V_16 -> V_89 ) )
V_16 -> V_86 &= ~ V_87 ;
* V_76 = V_16 -> V_86 ;
if ( ! ( * V_76 & V_87 ) ) {
struct V_39 * V_40 = F_45 ( V_42 ) ;
V_16 -> V_55 = 1 ;
F_14 ( V_40 ) ;
}
return V_6 ;
}
static int F_61 ( struct V_41 * V_42 , T_2 * V_56 )
{
struct V_43 * V_44 = & V_42 -> V_47 ;
struct V_15 * V_16 = F_58 ( V_42 ) ;
if ( V_16 -> V_166 && ! V_16 -> V_28 )
return V_16 -> V_166 ( V_42 , V_56 ) ;
if ( V_44 -> V_56 . V_49 [ 0 ] . V_50 == V_65 )
* V_56 = ( T_2 ) V_44 -> V_56 . V_49 [ 0 ] . V_66 ;
else
* V_56 = 0 ;
return 0 ;
}
static int F_62 ( struct V_41 * V_42 , T_2 * V_167 )
{
struct V_43 * V_44 = & V_42 -> V_47 ;
struct V_15 * V_16 = F_58 ( V_42 ) ;
if ( V_16 -> V_168 && ! V_16 -> V_28 )
return V_16 -> V_168 ( V_42 , V_167 ) ;
if ( V_44 -> V_57 . V_49 [ 0 ] . V_50 == V_65 )
* V_167 = ( T_2 ) V_44 -> V_57 . V_49 [ 0 ] . V_66 ;
else
* V_167 = 0 ;
return 0 ;
}
static int F_63 ( struct V_41 * V_42 , T_3 * V_169 )
{
struct V_15 * V_16 = F_58 ( V_42 ) ;
if ( V_16 -> V_170 && ! V_16 -> V_28 )
return V_16 -> V_170 ( V_42 , V_169 ) ;
* V_169 = 0 ;
return 0 ;
}
static int F_64 ( struct V_41 * V_42 , T_3 * V_171 )
{
struct V_15 * V_16 = F_58 ( V_42 ) ;
if ( V_16 -> V_172 && ! V_16 -> V_28 )
return V_16 -> V_172 ( V_42 , V_171 ) ;
* V_171 = 0 ;
return 0 ;
}
static int F_65 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_20 ( V_40 ) ;
struct V_15 * V_16 = F_15 ( V_40 ) ;
const char * V_96 = V_10 -> V_173 ;
char * V_174 [] = { L_26 , L_27 , L_28 ,
L_29 , L_30 } ;
char * V_173 = V_40 -> V_42 [ 0 ] -> V_175 . F_8 . V_173 ;
F_66 ( V_173 , V_96 , 128 ) ;
F_67 ( V_173 , V_174 [ V_16 -> V_58 ] , 128 ) ;
return 0 ;
}
static int F_68 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_20 ( V_40 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
int V_6 = 0 ;
V_16 -> V_55 = 1 ;
switch ( F_51 ( V_10 -> V_24 -> V_140 . V_141 ) ) {
case 0x1122 :
case 0x1120 :
V_16 -> V_114 = 4 ;
V_40 -> V_42 [ 0 ] = F_69 ( V_176 ,
& V_177 , & V_10 -> V_178 ) ;
if ( V_40 -> V_42 [ 0 ] ) {
F_8 ( L_31 ) ;
V_16 -> V_120 = 4 ;
V_16 -> V_119 = 4 ;
V_16 -> V_118 = 0x60 ;
V_16 -> V_58 = V_59 ;
if ( V_16 -> V_142 != V_59 ) {
V_16 -> V_142 = V_59 ;
V_6 = F_50 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
V_16 -> V_114 = 4 ;
V_40 -> V_42 [ 0 ] = F_69 ( V_179 ,
& V_180 , & V_10 -> V_178 ) ;
if ( V_40 -> V_42 [ 0 ] ) {
F_8 ( L_32 ) ;
V_16 -> V_120 = 4 ;
V_16 -> V_119 = 5 ;
V_16 -> V_118 = 0x60 ;
V_16 -> V_58 = V_63 ;
if ( V_16 -> V_142 != V_63 ) {
V_16 -> V_142 = V_63 ;
V_6 = F_50 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
V_16 -> V_114 = 5 ;
V_40 -> V_42 [ 0 ] = F_69 ( V_181 , & V_182 ,
& V_10 -> V_178 ) ;
if ( V_40 -> V_42 [ 0 ] ) {
F_8 ( L_33 ) ;
V_16 -> V_120 = 4 ;
V_16 -> V_119 = 5 ;
V_16 -> V_118 = 0x60 ;
V_16 -> V_58 = V_62 ;
if ( V_16 -> V_142 != V_62 ) {
V_16 -> V_142 = V_62 ;
V_6 = F_50 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
case 0x22f0 :
V_16 -> V_114 = 5 ;
V_40 -> V_42 [ 0 ] = F_69 ( V_183 ,
& V_184 , & V_10 -> V_178 ) ;
if ( V_40 -> V_42 [ 0 ] ) {
F_8 ( L_34 ) ;
F_69 ( V_185 , V_40 -> V_42 [ 0 ] , & V_186 ,
& V_10 -> V_178 ) ;
V_16 -> V_120 = 5 ;
V_16 -> V_119 = 5 ;
V_16 -> V_118 = 0x60 ;
V_16 -> V_58 = V_64 ;
V_16 -> V_163 =
V_40 -> V_42 [ 0 ] -> V_175 . V_187 ;
}
break;
}
if ( V_40 -> V_42 [ 0 ] == NULL ) {
F_8 ( L_35 ) ;
return - V_25 ;
}
if ( V_6 ) {
if ( V_40 -> V_42 [ 0 ] ) {
F_70 ( V_40 -> V_42 [ 0 ] ) ;
V_40 -> V_42 [ 0 ] = NULL ;
}
V_10 -> V_188 = NULL ;
return - V_25 ;
}
V_16 -> V_165 = V_40 -> V_42 [ 0 ] -> V_175 . V_189 ;
V_16 -> V_166 = V_40 -> V_42 [ 0 ] -> V_175 . V_190 ;
V_16 -> V_168 = V_40 -> V_42 [ 0 ] -> V_175 . V_191 ;
V_16 -> V_170 = V_40 -> V_42 [ 0 ] -> V_175 . V_192 ;
V_16 -> V_172 = V_40 -> V_42 [ 0 ] -> V_175 . V_193 ;
V_40 -> V_42 [ 0 ] -> V_175 . V_189 = F_59 ;
V_40 -> V_42 [ 0 ] -> V_175 . V_190 = F_61 ;
V_40 -> V_42 [ 0 ] -> V_175 . V_191 = F_62 ;
V_40 -> V_42 [ 0 ] -> V_175 . V_192 = F_63 ;
V_40 -> V_42 [ 0 ] -> V_175 . V_193 = F_64 ;
V_40 -> V_42 [ 0 ] -> V_175 . V_187 = F_56 ;
V_6 = F_65 ( V_40 ) ;
return V_6 ;
}
static int F_71 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_20 ( V_40 ) ;
struct V_15 * V_16 = F_15 ( V_40 ) ;
char * V_194 [] = { L_26 , L_36 , L_37 , L_38 , L_39 } ;
int V_6 = 0 ;
switch ( V_16 -> V_58 ) {
case V_59 :
if ( F_69 ( V_195 , V_40 -> V_42 [ 0 ] , 0x60 ,
& V_10 -> V_178 , 1 ) )
V_6 = V_16 -> V_58 ;
break;
case V_62 :
if ( F_69 ( V_196 , V_40 -> V_42 [ 0 ] , & V_197 ,
& V_10 -> V_178 ) )
V_6 = V_16 -> V_58 ;
break;
case V_63 :
if ( F_69 ( V_198 , V_40 -> V_42 [ 0 ] , 0x60 ,
& V_10 -> V_178 , V_199 ) )
V_6 = V_16 -> V_58 ;
break;
case V_64 :
V_6 = V_16 -> V_58 ;
break;
default:
break;
}
if ( V_6 )
F_8 ( L_40 , V_194 [ V_6 ] ) ;
else {
F_8 ( L_41 ) ;
F_49 ( V_10 ) ;
return - V_25 ;
}
V_6 = F_25 ( V_40 ) ;
if ( V_6 < 0 ) {
F_8 ( L_42 ) ;
return - V_25 ;
}
return V_6 ;
}
static int F_72 ( struct V_9 * V_10 , int V_100 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_200 [] = V_201 ;
static T_1 V_202 [] = V_203 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_33 ( & V_10 -> V_102 ) ;
if ( V_100 )
V_6 = F_6 ( V_10 , V_200 , V_4 , V_13 , V_14 ) ;
else
V_6 = F_6 ( V_10 , V_202 , V_4 , V_13 , V_14 ) ;
V_16 -> V_55 = 1 ;
F_10 ( & V_10 -> V_102 ) ;
return V_6 ;
}
static int F_73 ( struct V_9 * V_10 )
{
return 1 ;
}
static int F_74 ( struct V_9 * V_10 , const char * * V_173 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_75 ( V_10 -> V_24 ) ;
F_76 ( V_10 -> V_24 ,
V_10 -> V_204 -> V_205 , 1 ) ;
V_16 -> V_142 = V_142 ;
if ( F_35 ( V_10 ) == 0x44 ) {
* V_173 = F_50 ( V_10 , 0 ) ;
return V_206 ;
}
return 0 ;
}
static int F_77 ( struct V_41 * V_42 , T_1 * V_207 ,
struct V_208 * V_151 )
{
struct V_39 * V_40 = F_45 ( V_42 ) ;
struct V_9 * V_10 ;
if ( V_40 == NULL )
return 0 ;
V_10 = F_20 ( V_40 ) ;
if ( V_209 == 2 ) {
V_40 -> V_210 = true ;
V_40 -> V_211 = 15 ;
}
if ( ! ( F_51 ( V_10 -> V_24 -> V_140 . V_141 )
== 0x1122 ) )
V_151 -> V_212 = 0x8 ;
return 0 ;
}
static int F_78 ( struct V_9 * V_10 ,
struct V_213 * V_214 )
{
V_214 -> V_215 = V_216 ;
return 0 ;
}
static void * F_79 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_39 * V_40 = & V_10 -> V_122 [ 0 ] ;
void * V_94 = NULL ;
if ( V_40 != NULL ) {
F_54 ( & V_40 -> V_151 ) ;
}
if ( V_16 -> V_19 != NULL ) {
V_16 -> V_55 = 1 ;
V_16 -> V_60 = 0 ;
V_16 -> V_61 = 0 ;
V_94 = V_16 -> V_19 ;
}
if ( V_16 -> V_69 != NULL ) {
F_55 ( V_16 -> V_69 ) ;
F_80 ( V_10 -> V_24 , 128 , V_16 -> V_94 ,
V_16 -> V_69 -> V_95 ) ;
F_8 ( L_43 ) ;
}
return V_94 ;
}
static void F_81 ( struct V_9 * V_10 )
{
void * V_19 ;
if ( V_10 != NULL ) {
V_19 = F_79 ( V_10 ) ;
F_39 ( V_19 ) ;
}
}
