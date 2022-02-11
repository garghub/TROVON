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
struct V_41 * V_42 = V_40 -> V_43 ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
static T_1 * V_44 , * V_13 ;
int V_45 = 0 , V_46 ;
T_3 V_47 ;
T_1 V_48 = 0 ;
switch ( V_40 -> V_49 ) {
case 0 :
case - V_50 :
break;
case - V_51 :
case - V_52 :
case - V_53 :
return;
default:
F_8 ( L_3 , V_40 -> V_49 ) ;
break;
}
V_13 = ( T_1 * ) V_40 -> V_54 ;
V_46 = ( ( V_40 -> V_55 / 8 ) > 4 )
? 4 : ( V_40 -> V_55 / 8 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; ++ V_45 ) {
V_44 = ( T_1 * ) & V_13 [ V_45 * 8 ] ;
F_13 ( 5 , L_4 ,
V_46 , V_45 , V_44 [ 0 ] , V_44 [ 1 ] ) ;
switch ( V_44 [ 0 ] ) {
case 0xaa :
F_16 ( 1 , L_5 , V_44 ) ;
if ( ( V_44 [ 4 ] + V_44 [ 5 ] ) == 0xff ) {
V_47 = F_17 ( ( V_44 [ 2 ] ^ 0xff ) << 8 |
( V_44 [ 3 ] > 0 ) ? ( V_44 [ 3 ] ^ 0xff ) : 0 ,
V_44 [ 5 ] ) ;
F_13 ( 1 , L_6 , V_47 ) ;
if ( F_18 ( V_42 ) -> V_56 != NULL )
F_19 ( F_18 ( V_42 ) -> V_56 ,
V_57 , V_47 , 0 ) ;
}
break;
case 0xbb :
switch ( V_16 -> V_58 ) {
case V_59 :
V_48 = V_44 [ 2 ] & F_20 ( 5 ) ;
V_16 -> V_60 = V_44 [ 4 ] ;
V_16 -> V_61 = V_44 [ 3 ] ;
V_16 -> V_62 = V_44 [ 7 ] ;
break;
case V_63 :
case V_64 :
if ( V_44 [ 1 ] == 0x03 ) {
V_48 = V_44 [ 2 ] & F_20 ( 4 ) ;
V_16 -> V_60 = V_44 [ 3 ] ;
V_16 -> V_61 = V_44 [ 4 ] ;
} else {
V_16 -> V_60 = V_44 [ 4 ] ;
V_16 -> V_61 = V_44 [ 5 ] ;
}
break;
case V_65 :
V_48 = V_44 [ 2 ] & 0xee ;
V_16 -> V_60 = V_44 [ 5 ] ;
V_16 -> V_61 = V_44 [ 4 ] ;
V_16 -> V_62 = V_44 [ 7 ] ;
default:
break;
}
V_48 |= V_44 [ 2 ] & F_20 ( 0 ) ;
if ( ! V_48 )
V_16 -> V_66 &= ~ V_67 ;
F_16 ( 5 , L_7 , V_44 ) ;
break;
case 0xcc :
F_16 ( 1 , L_8 , V_44 ) ;
break;
default:
F_16 ( 1 , L_9 , V_44 ) ;
break;
}
}
F_21 ( V_40 , V_68 ) ;
V_16 -> V_69 = V_70 + F_22 ( 200 ) ;
}
static int F_23 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_71 = F_15 ( V_42 ) ;
struct V_72 * V_73 ;
V_71 -> V_40 = F_24 ( 0 , V_68 ) ;
if ( V_71 -> V_40 == NULL )
return - V_21 ;
V_71 -> V_74 = F_25 ( V_10 -> V_24 , 128 , V_68 ,
& V_71 -> V_40 -> V_75 ) ;
if ( V_71 -> V_74 == NULL )
return - V_21 ;
F_26 ( V_71 -> V_40 ,
V_10 -> V_24 ,
F_27 ( V_10 -> V_24 , 0xa ) ,
V_71 -> V_74 ,
128 ,
F_14 ,
V_42 ,
8 ) ;
V_73 = F_28 ( V_10 -> V_24 , V_71 -> V_40 -> V_5 ) ;
if ( F_29 ( & V_73 -> V_76 ) == V_77 )
V_71 -> V_40 -> V_5 = F_5 ( V_10 -> V_24 , 0xa ) ,
V_71 -> V_40 -> V_78 |= V_79 ;
F_21 ( V_71 -> V_40 , V_68 ) ;
F_8 ( L_10 ) ;
return 0 ;
}
static int F_30 ( struct V_41 * V_42 , int V_80 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
static T_1 V_81 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 ;
F_13 ( 1 , L_11 ) ;
F_31 ( & V_10 -> V_82 ) ;
if ( ! V_80 ) {
V_6 |= F_6 ( V_10 , V_81 ,
sizeof( V_81 ) , V_13 , sizeof( V_13 ) ) ;
V_16 -> V_31 = true ;
} else
V_16 -> V_31 = false ;
V_16 -> V_38 = 0 ;
F_10 ( & V_10 -> V_82 ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_42 , int V_32 , T_2 V_83 ,
int V_80 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
int V_6 = 0 ;
F_13 ( 3 , L_12 , V_84 ,
V_83 , V_32 , V_80 ) ;
if ( V_80 ) {
F_31 ( & V_10 -> V_82 ) ;
V_6 |= F_12 ( V_10 , V_32 , V_83 ) ;
F_10 ( & V_10 -> V_82 ) ;
}
return V_6 ;
}
static int F_33 ( struct V_9 * V_10 )
{
int V_6 = 0 ;
T_1 * V_85 ;
V_85 = F_34 ( 10 , V_20 ) ;
if ( ! V_85 )
return - V_21 ;
V_6 |= F_35 ( V_10 -> V_24 , F_36 ( V_10 -> V_24 , 0 ) ,
0x06 , 0x80 , 0x0302 , 0x00 , V_85 , 0x0006 , 200 ) ;
F_8 ( L_13 , V_6 , V_85 [ 2 ] ) ;
V_6 = ( V_6 < 0 ) ? - V_25 : V_85 [ 2 ] ;
F_37 ( V_85 ) ;
return V_6 ;
}
static int F_38 ( struct V_9 * V_10 ,
T_1 * V_11 , int V_12 , T_1 * V_13 , int V_14 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
V_16 -> V_86 = 1 ;
return F_6 ( V_10 , V_11 , V_12 , V_13 , V_14 ) ;
}
static int F_39 ( struct V_87 * V_42 , struct V_88 V_89 [] ,
int V_90 )
{
struct V_9 * V_10 = F_40 ( V_42 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_91 [ 64 ] , V_44 [ 64 ] ;
int V_45 , V_92 , V_93 ;
T_2 V_4 ;
T_1 V_94 = V_16 -> V_95 ;
F_31 ( & V_10 -> V_82 ) ;
if ( V_94 == 0 )
V_94 = 5 ;
for ( V_45 = 0 ; V_45 < V_90 ; V_45 ++ ) {
V_93 = V_89 [ V_45 ] . V_96 & V_97 ;
V_92 = V_45 + 1 < V_90 && V_89 [ V_45 + 1 ] . V_96 & V_97 ;
V_92 |= V_93 ;
V_94 = ( V_89 [ V_45 ] . V_98 == V_16 -> V_99 )
? ( V_92 ) ? V_16 -> V_100
: V_16 -> V_101
: V_16 -> V_95 ;
V_91 [ 0 ] = V_94 | ( V_92 << 7 ) ;
if ( V_94 == 5 )
V_91 [ 1 ] = ( V_92 ) ? 2 : V_89 [ V_45 ] . V_4 + 1 ;
else
V_91 [ 1 ] = V_89 [ V_45 ] . V_4 + V_92 + 1 ;
V_91 [ 2 ] = V_89 [ V_45 ] . V_98 << 1 ;
if ( V_92 ) {
if ( V_93 )
V_4 = 3 ;
else {
memcpy ( & V_91 [ 3 ] , V_89 [ V_45 ] . V_102 , V_89 [ V_45 ] . V_4 ) ;
V_91 [ V_89 [ V_45 ] . V_4 + 3 ] = V_89 [ V_45 + 1 ] . V_4 ;
V_4 = V_89 [ V_45 ] . V_4 + 4 ;
}
} else {
memcpy ( & V_91 [ 3 ] , V_89 [ V_45 ] . V_102 , V_89 [ V_45 ] . V_4 ) ;
V_4 = V_89 [ V_45 ] . V_4 + 3 ;
}
if ( F_38 ( V_10 , V_91 , V_4 , V_44 , 64 ) < 0 ) {
F_13 ( 1 , L_14 ) ;
F_10 ( & V_10 -> V_82 ) ;
return - V_23 ;
}
if ( V_92 ) {
if ( V_93 )
memcpy ( V_89 [ V_45 ] . V_102 , & V_44 [ 1 ] , V_89 [ V_45 ] . V_4 ) ;
else {
memcpy ( V_89 [ V_45 + 1 ] . V_102 , & V_44 [ 1 ] , V_89 [ V_45 + 1 ] . V_4 ) ;
V_45 ++ ;
}
}
}
F_10 ( & V_10 -> V_82 ) ;
return V_45 ;
}
static T_3 F_41 ( struct V_87 * V_103 )
{
return V_104 ;
}
static int F_42 ( struct V_105 * V_106 , int V_80 )
{
struct V_41 * V_42 = F_43 ( V_106 ) ;
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
static T_1 V_107 [] = V_27 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_14 = sizeof( V_13 ) ;
F_13 ( 1 , L_15 , V_80 ) ;
if ( V_80 == 1 )
V_16 -> V_28 = 1 ;
else {
F_13 ( 1 , L_16 ) ;
F_31 ( & V_10 -> V_82 ) ;
V_6 = F_6 ( V_10 , V_107 ,
sizeof( V_107 ) , V_13 , V_14 ) ;
V_16 -> V_28 = 0 ;
V_16 -> V_86 = 1 ;
F_10 ( & V_10 -> V_82 ) ;
}
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static T_1 F_44 ( T_1 * V_108 , T_1 V_4 )
{
T_1 V_109 = 0 ;
while ( V_4 -- )
V_109 += * V_108 ++ ;
return V_109 ;
}
static int F_45 ( struct V_9 * V_10 ,
const struct V_110 * V_111 )
{
int V_6 = 0 ;
T_1 * V_85 ;
T_2 V_112 , V_12 , V_113 , V_114 , V_115 ;
T_1 V_116 , V_117 , V_45 ;
T_1 * V_118 ;
V_116 = 0x31 ;
V_113 = 1 ;
V_85 = F_34 ( 128 , V_20 ) ;
if ( ! V_85 ) {
F_8 ( L_17\
L_18 ) ;
return - V_21 ;
}
F_8 ( L_19 ) ;
for ( V_45 = 1 ; V_45 < 3 ; V_45 ++ ) {
V_114 = ( V_45 == 1 ) ? 0 : 512 ;
V_115 = ( V_45 == 1 ) ? 512 : V_111 -> V_119 ;
for ( V_112 = V_114 ; V_112 < V_115 ; V_112 += ( V_116 + 1 ) ) {
V_118 = ( T_1 * ) ( V_111 -> V_85 + V_112 ) ;
if ( ( V_115 - V_112 ) > V_116 ) {
V_85 [ 0 ] = V_45 ;
V_117 = V_116 ;
} else {
V_85 [ 0 ] = V_45 | 0x80 ;
V_117 = ( T_1 ) ( V_115 - V_112 ) - 1 ;
}
V_85 [ 1 ] = V_117 ;
memcpy ( & V_85 [ 2 ] , V_118 , V_117 + 1 ) ;
V_12 = ( T_1 ) V_117 + 4 ;
V_85 [ V_12 - 1 ] = F_44 ( V_118 , V_117 + 1 ) ;
F_13 ( 1 , L_20 , V_85 [ 3 ] ,
V_85 [ V_117 + 2 ] , V_85 [ V_117 + 3 ] ) ;
F_6 ( V_10 , V_85 , V_12 , V_85 , V_113 ) ;
V_6 |= ( V_85 [ 0 ] == 0x88 ) ? 0 : - 1 ;
}
}
V_85 [ 0 ] = 0x8a ;
V_113 = 1 ;
F_46 ( 2000 ) ;
F_6 ( V_10 , V_85 , V_113 , V_85 , V_113 ) ;
F_46 ( 400 ) ;
if ( V_6 < 0 )
F_8 ( L_21 , V_6 ) ;
else
F_8 ( L_22 ) ;
F_37 ( V_85 ) ;
return V_120 ;
}
static void F_47 ( struct V_9 * V_10 )
{
T_1 V_85 [ 1 ] = { 0 } ;
V_85 [ 0 ] = 0x0a ;
F_8 ( L_23 ) ;
F_6 ( V_10 , V_85 , sizeof( V_85 ) , V_85 , sizeof( V_85 ) ) ;
return;
}
static const char * F_48 ( struct V_9 * V_10 , int V_121 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_24 = V_10 -> V_24 ;
const struct V_110 * V_111 = NULL ;
const char * V_122 ;
int V_6 = 0 ;
V_121 = ( V_121 > 0 ) ? ( V_121 & 1 ) : 0 ;
switch ( F_49 ( V_24 -> V_123 . V_124 ) ) {
case 0x1122 :
switch ( V_16 -> V_125 ) {
default:
case V_64 :
V_122 = V_126 ;
V_6 = F_50 ( & V_111 , V_122 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_125 = V_64 ;
V_121 = 0 ;
break;
}
case V_59 :
V_122 = V_127 ;
V_6 = F_50 ( & V_111 , V_122 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_125 = V_59 ;
break;
}
V_16 -> V_125 = V_128 ;
break;
}
break;
case 0x1120 :
switch ( V_16 -> V_125 ) {
default:
case V_63 :
V_122 = V_129 ;
V_6 = F_50 ( & V_111 , V_122 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_125 = V_63 ;
V_121 = 0 ;
break;
}
case V_59 :
V_122 = V_130 ;
V_6 = F_50 ( & V_111 , V_122 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_125 = V_59 ;
break;
}
case V_64 :
V_122 = V_131 ;
V_6 = F_50 ( & V_111 , V_122 , & V_24 -> V_2 ) ;
if ( V_6 == 0 ) {
V_16 -> V_125 = V_64 ;
break;
}
V_16 -> V_125 = V_128 ;
V_121 = 0 ;
break;
}
break;
case 0x22f0 :
V_122 = V_132 ;
V_16 -> V_125 = V_65 ;
break;
default:
V_122 = V_129 ;
}
F_51 ( V_111 ) ;
if ( V_121 ) {
V_125 = V_16 -> V_125 ;
F_8 ( L_24 , V_122 ) ;
F_47 ( V_10 ) ;
return NULL ;
}
return V_122 ;
}
static int F_52 ( struct V_133 * V_134 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_134 -> V_135 ; V_45 ++ ) {
F_13 ( 3 , L_25 , V_45 ) ;
F_53 ( V_134 -> V_136 [ V_45 ] ) ;
}
V_134 -> V_135 = 0 ;
return 0 ;
}
static int F_54 ( struct V_105 * V_106 ,
T_4 V_137 )
{
struct V_9 * V_10 = F_55 ( V_106 ) ;
struct V_15 * V_16 = F_56 ( V_106 ) ;
static T_1 V_138 [] = V_139 ;
static T_1 V_140 [] = V_141 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_31 ( & V_10 -> V_82 ) ;
switch ( V_137 ) {
case V_142 :
V_6 |= F_6 ( V_10 ,
V_140 , V_4 , V_13 , V_14 ) ;
break;
case V_143 :
case V_144 :
default:
V_6 |= F_6 ( V_10 ,
V_138 , V_4 , V_13 , V_14 ) ;
break;
}
F_10 ( & V_10 -> V_82 ) ;
if ( V_16 -> V_58 == V_65 )
if ( V_16 -> V_145 )
V_16 -> V_145 ( V_106 , V_137 ) ;
return ( V_6 < 0 ) ? - V_25 : 0 ;
}
static int F_57 ( struct V_105 * V_106 , T_5 * V_49 )
{
struct V_9 * V_10 = F_55 ( V_106 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
int V_6 = 0 ;
if ( V_16 -> V_86 ) {
if ( V_16 -> V_146 ) {
V_6 = V_16 -> V_146 ( V_106 , V_49 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_16 -> V_66 = * V_49 ;
if ( * V_49 & V_67 && V_16 -> V_28 ) {
F_31 ( & V_10 -> V_82 ) ;
V_16 -> V_86 = 0 ;
V_6 = F_11 ( V_10 ) ;
F_10 ( & V_10 -> V_82 ) ;
}
return V_6 ;
}
if ( V_16 -> V_58 == V_65 &&
F_58 ( V_70 , V_16 -> V_69 ) )
V_16 -> V_66 &= ~ V_67 ;
* V_49 = V_16 -> V_66 ;
if ( ! ( * V_49 & V_67 ) )
V_16 -> V_86 = 1 ;
return V_6 ;
}
static int F_59 ( struct V_105 * V_106 , T_2 * V_147 )
{
struct V_15 * V_16 = F_56 ( V_106 ) ;
if ( V_16 -> V_148 && ! V_16 -> V_28 )
return V_16 -> V_148 ( V_106 , V_147 ) ;
switch ( V_16 -> V_58 ) {
case V_59 :
* V_147 = 0xff - V_16 -> V_60 ;
* V_147 |= * V_147 << 8 ;
break;
case V_63 :
case V_64 :
* V_147 = 0xffff - ( ( ( V_16 -> V_60 * 2 ) << 8 ) * 5 / 4 ) ;
break;
case V_65 :
* V_147 = ( T_2 ) ( ( T_3 ) V_16 -> V_60 * 0xffff / 0xff ) ;
}
return 0 ;
}
static int F_60 ( struct V_105 * V_106 , T_2 * V_149 )
{
struct V_15 * V_16 = F_56 ( V_106 ) ;
if ( V_16 -> V_150 && ! V_16 -> V_28 )
return V_16 -> V_150 ( V_106 , V_149 ) ;
switch ( V_16 -> V_58 ) {
case V_59 :
* V_149 = 0xff - V_16 -> V_61 ;
* V_149 |= * V_149 << 8 ;
break;
case V_63 :
case V_64 :
* V_149 = ( T_2 ) ( ( 0xff - V_16 -> V_61 - 0xa1 ) * 3 ) << 8 ;
break;
case V_65 :
* V_149 = ( T_2 ) ( ( T_3 ) V_16 -> V_61 * 0xffff / 0x7f ) ;
}
return 0 ;
}
static int F_61 ( struct V_105 * V_106 , T_3 * V_151 )
{
struct V_15 * V_16 = F_56 ( V_106 ) ;
if ( V_16 -> V_152 && ! V_16 -> V_28 )
return V_16 -> V_152 ( V_106 , V_151 ) ;
* V_151 = 0 ;
return 0 ;
}
static int F_62 ( struct V_105 * V_106 , T_3 * V_153 )
{
struct V_15 * V_16 = F_56 ( V_106 ) ;
if ( V_16 -> V_154 && ! V_16 -> V_28 )
return V_16 -> V_154 ( V_106 , V_153 ) ;
* V_153 = 0 ;
return 0 ;
}
static int F_63 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
const char * V_76 = V_10 -> V_155 ;
char * V_156 [] = { L_26 , L_27 , L_28 ,
L_29 , L_30 } ;
char * V_155 = V_42 -> V_106 [ 0 ] -> V_157 . F_8 . V_155 ;
F_64 ( V_155 , V_76 , 128 ) ;
F_65 ( V_155 , V_156 [ V_16 -> V_58 ] , 128 ) ;
return 0 ;
}
static int F_66 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = V_10 -> V_17 ;
int V_6 = 0 ;
V_16 -> V_86 = 1 ;
switch ( F_49 ( V_10 -> V_24 -> V_123 . V_124 ) ) {
case 0x1122 :
case 0x1120 :
V_16 -> V_95 = 4 ;
V_42 -> V_106 [ 0 ] = F_67 ( V_158 ,
& V_159 , & V_10 -> V_160 ) ;
if ( V_42 -> V_106 [ 0 ] ) {
F_8 ( L_31 ) ;
V_16 -> V_101 = 4 ;
V_16 -> V_100 = 4 ;
V_16 -> V_99 = 0x60 ;
V_16 -> V_58 = V_59 ;
if ( V_16 -> V_125 != V_59 ) {
V_16 -> V_125 = V_59 ;
V_6 = F_48 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
V_16 -> V_95 = 4 ;
V_42 -> V_106 [ 0 ] = F_67 ( V_161 ,
& V_162 , & V_10 -> V_160 ) ;
if ( V_42 -> V_106 [ 0 ] ) {
F_8 ( L_32 ) ;
V_16 -> V_101 = 4 ;
V_16 -> V_100 = 5 ;
V_16 -> V_99 = 0x60 ;
V_16 -> V_58 = V_64 ;
if ( V_16 -> V_125 != V_64 ) {
V_16 -> V_125 = V_64 ;
V_6 = F_48 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
V_16 -> V_95 = 5 ;
V_42 -> V_106 [ 0 ] = F_67 ( V_163 , & V_164 ,
& V_10 -> V_160 ) ;
if ( V_42 -> V_106 [ 0 ] ) {
F_8 ( L_33 ) ;
V_16 -> V_101 = 4 ;
V_16 -> V_100 = 5 ;
V_16 -> V_99 = 0x60 ;
V_16 -> V_58 = V_63 ;
if ( V_16 -> V_125 != V_63 ) {
V_16 -> V_125 = V_63 ;
V_6 = F_48 ( V_10 , 1 ) ? 0 : - V_25 ;
}
break;
}
case 0x22f0 :
V_16 -> V_95 = 5 ;
V_42 -> V_106 [ 0 ] = F_67 ( V_165 ,
& V_166 , & V_10 -> V_160 ) ;
if ( V_42 -> V_106 [ 0 ] ) {
F_8 ( L_34 ) ;
F_67 ( V_167 , V_42 -> V_106 [ 0 ] , & V_168 ,
& V_10 -> V_160 ) ;
V_16 -> V_101 = 5 ;
V_16 -> V_100 = 5 ;
V_16 -> V_99 = 0x60 ;
V_16 -> V_58 = V_65 ;
V_16 -> V_145 =
V_42 -> V_106 [ 0 ] -> V_157 . V_169 ;
}
break;
}
if ( V_42 -> V_106 [ 0 ] == NULL ) {
F_8 ( L_35 ) ;
return - V_25 ;
}
if ( V_6 ) {
if ( V_42 -> V_106 [ 0 ] ) {
F_68 ( V_42 -> V_106 [ 0 ] ) ;
V_42 -> V_106 [ 0 ] = NULL ;
}
V_10 -> V_170 = NULL ;
return - V_25 ;
}
V_16 -> V_146 = V_42 -> V_106 [ 0 ] -> V_157 . V_171 ;
V_16 -> V_148 = V_42 -> V_106 [ 0 ] -> V_157 . V_172 ;
V_16 -> V_150 = V_42 -> V_106 [ 0 ] -> V_157 . V_173 ;
V_16 -> V_152 = V_42 -> V_106 [ 0 ] -> V_157 . V_174 ;
V_16 -> V_154 = V_42 -> V_106 [ 0 ] -> V_157 . V_175 ;
V_42 -> V_106 [ 0 ] -> V_157 . V_171 = F_57 ;
V_42 -> V_106 [ 0 ] -> V_157 . V_172 = F_59 ;
V_42 -> V_106 [ 0 ] -> V_157 . V_173 = F_60 ;
V_42 -> V_106 [ 0 ] -> V_157 . V_174 = F_61 ;
V_42 -> V_106 [ 0 ] -> V_157 . V_175 = F_62 ;
V_42 -> V_106 [ 0 ] -> V_157 . V_169 = F_54 ;
V_6 = F_63 ( V_42 ) ;
return V_6 ;
}
static int F_69 ( struct V_41 * V_42 )
{
struct V_9 * V_10 = F_18 ( V_42 ) ;
struct V_15 * V_16 = F_15 ( V_42 ) ;
char * V_176 [] = { L_26 , L_36 , L_37 , L_38 , L_39 } ;
int V_6 = 0 ;
switch ( V_16 -> V_58 ) {
case V_59 :
if ( F_67 ( V_177 , V_42 -> V_106 [ 0 ] , 0x60 ,
& V_10 -> V_160 , 1 ) )
V_6 = V_16 -> V_58 ;
break;
case V_63 :
if ( F_67 ( V_178 , V_42 -> V_106 [ 0 ] , & V_179 ,
& V_10 -> V_160 ) )
V_6 = V_16 -> V_58 ;
break;
case V_64 :
if ( F_67 ( V_180 , V_42 -> V_106 [ 0 ] , 0x60 ,
& V_10 -> V_160 , V_181 ) )
V_6 = V_16 -> V_58 ;
break;
case V_65 :
V_6 = V_16 -> V_58 ;
break;
default:
break;
}
if ( V_6 )
F_8 ( L_40 , V_176 [ V_6 ] ) ;
else {
F_8 ( L_41 ) ;
F_47 ( V_10 ) ;
return - V_25 ;
}
V_6 = F_23 ( V_42 ) ;
if ( V_6 < 0 ) {
F_8 ( L_42 ) ;
return - V_25 ;
}
return V_6 ;
}
static int F_70 ( struct V_9 * V_10 , int V_80 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
static T_1 V_182 [] = V_183 ;
static T_1 V_184 [] = V_185 ;
static T_1 V_13 [ 1 ] ;
int V_6 = 0 , V_4 = 3 , V_14 = 1 ;
F_31 ( & V_10 -> V_82 ) ;
if ( V_80 )
V_6 = F_6 ( V_10 , V_182 , V_4 , V_13 , V_14 ) ;
else
V_6 = F_6 ( V_10 , V_184 , V_4 , V_13 , V_14 ) ;
V_16 -> V_86 = 1 ;
F_10 ( & V_10 -> V_82 ) ;
return V_6 ;
}
static int F_71 ( struct V_9 * V_10 )
{
return 1 ;
}
static int F_72 ( struct V_9 * V_10 , const char * * V_155 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_73 ( V_10 -> V_24 ) ;
F_74 ( V_10 -> V_24 ,
V_10 -> V_186 -> V_187 , 1 ) ;
V_16 -> V_125 = V_125 ;
if ( F_33 ( V_10 ) == 0x44 ) {
* V_155 = F_48 ( V_10 , 0 ) ;
return V_188 ;
}
return 0 ;
}
static int F_75 ( struct V_105 * V_106 , T_1 * V_189 ,
struct V_190 * V_134 )
{
struct V_41 * V_42 = F_43 ( V_106 ) ;
struct V_9 * V_10 ;
if ( V_42 == NULL )
return 0 ;
V_10 = F_18 ( V_42 ) ;
if ( V_191 == 2 ) {
V_42 -> V_192 = true ;
V_42 -> V_193 = 15 ;
}
if ( ! ( F_49 ( V_10 -> V_24 -> V_123 . V_124 )
== 0x1122 ) )
V_134 -> V_194 = 0x8 ;
return 0 ;
}
static int F_76 ( struct V_9 * V_10 ,
struct V_195 * V_196 )
{
V_196 -> V_197 = V_198 ;
return 0 ;
}
static void * F_77 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_41 * V_42 = & V_10 -> V_103 [ 0 ] ;
void * V_74 = NULL ;
if ( V_42 != NULL ) {
F_52 ( & V_42 -> V_134 ) ;
}
if ( V_16 -> V_19 != NULL ) {
V_16 -> V_86 = 1 ;
V_16 -> V_60 = 0 ;
V_16 -> V_61 = 0 ;
V_74 = V_16 -> V_19 ;
}
if ( V_16 -> V_40 != NULL ) {
F_53 ( V_16 -> V_40 ) ;
F_78 ( V_10 -> V_24 , 128 , V_16 -> V_74 ,
V_16 -> V_40 -> V_75 ) ;
F_8 ( L_43 ) ;
}
return V_74 ;
}
static void F_79 ( struct V_9 * V_10 )
{
void * V_19 ;
if ( V_10 != NULL ) {
V_19 = F_77 ( V_10 ) ;
F_37 ( V_19 ) ;
}
}
