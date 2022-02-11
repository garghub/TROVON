static void F_1 ( T_1 clock , int * V_1 , int V_2 , int V_3 )
{
if ( * V_1 == 0 )
* V_1 = clock * V_2 / ( 128 * V_3 ) * 1000 ;
F_2 ( L_1 ,
V_2 , * V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 , T_1 clock )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = F_4 ( V_5 ) -> V_12 ;
int V_1 ;
int V_2 ;
int V_13 ;
for ( V_13 = 0 ; V_14 [ V_13 ] . Clock != clock && V_14 [ V_13 ] . Clock != 0 ; V_13 ++ ) ;
V_1 = V_14 [ V_13 ] . V_15 ;
V_2 = V_14 [ V_13 ] . V_16 ;
F_1 ( clock , & V_1 , V_2 , 32000 ) ;
F_5 ( V_11 + V_17 , V_1 << 12 ) ;
F_5 ( V_11 + V_18 , V_2 ) ;
V_1 = V_14 [ V_13 ] . V_19 ;
V_2 = V_14 [ V_13 ] . V_20 ;
F_1 ( clock , & V_1 , V_2 , 44100 ) ;
F_5 ( V_11 + V_21 , V_1 << 12 ) ;
F_5 ( V_11 + V_22 , V_2 ) ;
V_1 = V_14 [ V_13 ] . V_23 ;
V_2 = V_14 [ V_13 ] . V_24 ;
F_1 ( clock , & V_1 , V_2 , 48000 ) ;
F_5 ( V_11 + V_25 , V_1 << 12 ) ;
F_5 ( V_11 + V_26 , V_2 ) ;
}
static void F_6 ( T_2 V_27 ,
T_2 V_28 ,
T_2 V_29 ,
T_2 * V_30 )
{
int V_13 ;
V_30 [ 0 ] = V_27 + V_28 + V_29 ;
for ( V_13 = 1 ; V_13 <= V_29 ; V_13 ++ )
V_30 [ 0 ] += V_30 [ V_13 ] ;
V_30 [ 0 ] = 0x100 - V_30 [ 0 ] ;
}
static void F_7 (
struct V_4 * V_5 ,
enum V_31 V_32 ,
int V_33 ,
T_2 V_34 ,
T_2 V_35 ,
T_2 V_36 ,
T_2 V_37 ,
T_2 V_38 ,
int V_39 ,
T_2 V_40 ,
T_2 V_41 ,
T_2 V_42 ,
T_2 V_43 ,
T_2 V_44 ,
T_3 V_45 ,
T_3 V_46 ,
T_3 V_47 ,
T_3 V_48
)
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = F_4 ( V_5 ) -> V_12 ;
T_2 V_30 [ 14 ] ;
V_30 [ 0x0 ] = 0 ;
V_30 [ 0x1 ] =
( V_35 & 0x3 ) |
( ( V_44 & 0x3 ) << 2 ) |
( ( V_33 & 0x1 ) << 4 ) |
( ( V_32 & 0x3 ) << 5 ) ;
V_30 [ 0x2 ] =
( V_34 & 0xF ) |
( ( V_40 & 0x3 ) << 4 ) |
( ( V_36 & 0x3 ) << 6 ) ;
V_30 [ 0x3 ] =
( V_43 & 0x3 ) |
( ( V_38 & 0x3 ) << 2 ) |
( ( V_37 & 0x7 ) << 4 ) |
( ( V_39 & 0x1 ) << 7 ) ;
V_30 [ 0x4 ] = ( V_41 & 0x7F ) ;
V_30 [ 0x5 ] = ( V_42 & 0xF ) ;
V_30 [ 0x6 ] = ( V_45 & 0xFF ) ;
V_30 [ 0x7 ] = ( V_45 >> 8 ) ;
V_30 [ 0x8 ] = ( V_46 & 0xFF ) ;
V_30 [ 0x9 ] = ( V_46 >> 8 ) ;
V_30 [ 0xA ] = ( V_47 & 0xFF ) ;
V_30 [ 0xB ] = ( V_47 >> 8 ) ;
V_30 [ 0xC ] = ( V_48 & 0xFF ) ;
V_30 [ 0xD ] = ( V_48 >> 8 ) ;
F_6 ( 0x82 , 0x02 , 0x0D , V_30 ) ;
V_30 [ 0x0 ] += 2 ;
F_5 ( V_11 + V_49 ,
V_30 [ 0x0 ] | ( V_30 [ 0x1 ] << 8 ) | ( V_30 [ 0x2 ] << 16 ) | ( V_30 [ 0x3 ] << 24 ) ) ;
F_5 ( V_11 + V_50 ,
V_30 [ 0x4 ] | ( V_30 [ 0x5 ] << 8 ) | ( V_30 [ 0x6 ] << 16 ) | ( V_30 [ 0x7 ] << 24 ) ) ;
F_5 ( V_11 + V_51 ,
V_30 [ 0x8 ] | ( V_30 [ 0x9 ] << 8 ) | ( V_30 [ 0xA ] << 16 ) | ( V_30 [ 0xB ] << 24 ) ) ;
F_5 ( V_11 + V_52 ,
V_30 [ 0xC ] | ( V_30 [ 0xD ] << 8 ) ) ;
}
static void F_8 (
struct V_4 * V_5 ,
T_2 V_53 ,
T_2 V_54 ,
T_2 V_55 ,
T_2 V_56 ,
T_2 V_57 ,
T_2 V_58 ,
T_2 V_59 ,
int V_60
)
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = F_4 ( V_5 ) -> V_12 ;
T_2 V_30 [ 11 ] ;
V_30 [ 0x0 ] = 0 ;
V_30 [ 0x1 ] = ( V_53 & 0x7 ) | ( ( V_54 & 0xF ) << 4 ) ;
V_30 [ 0x2 ] = ( V_55 & 0x3 ) | ( ( V_56 & 0x7 ) << 2 ) ;
V_30 [ 0x3 ] = V_57 ;
V_30 [ 0x4 ] = V_58 ;
V_30 [ 0x5 ] = ( ( V_59 & 0xF ) << 3 ) | ( ( V_60 & 0x1 ) << 7 ) ;
V_30 [ 0x6 ] = 0 ;
V_30 [ 0x7 ] = 0 ;
V_30 [ 0x8 ] = 0 ;
V_30 [ 0x9 ] = 0 ;
V_30 [ 0xA ] = 0 ;
F_6 ( 0x84 , 0x01 , 0x0A , V_30 ) ;
F_5 ( V_11 + V_61 ,
V_30 [ 0x0 ] | ( V_30 [ 0x1 ] << 8 ) | ( V_30 [ 0x2 ] << 16 ) | ( V_30 [ 0x3 ] << 24 ) ) ;
F_5 ( V_11 + V_62 ,
V_30 [ 0x4 ] | ( V_30 [ 0x5 ] << 8 ) | ( V_30 [ 0x6 ] << 16 ) | ( V_30 [ 0x8 ] << 24 ) ) ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = F_4 ( V_5 ) -> V_12 ;
return ( F_10 ( V_11 + V_63 ) & 0x10 ) != 0 ;
}
int F_11 ( struct V_4 * V_5 )
{
struct V_64 * V_64 = F_4 ( V_5 ) ;
int V_65 , V_66 ;
if ( ! V_64 -> V_12 )
return 0 ;
V_65 = F_9 ( V_5 ) ;
V_66 = V_64 -> V_67 != V_65 ;
V_64 -> V_67 = V_65 ;
return V_66 ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_64 * V_64 = F_4 ( V_5 ) ;
T_1 V_11 = V_64 -> V_12 ;
if ( ! V_11 )
return;
if ( ! V_64 -> V_68 ||
F_9 ( V_5 ) ) {
F_13 ( V_11 + V_69 , 0x00000001 , ~ 0x00001001 ) ;
} else {
F_13 ( V_11 + V_69 , 0x00001001 , ~ 0x00001001 ) ;
}
}
void F_14 ( struct V_4 * V_5 , struct V_70 * V_71 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = F_4 ( V_5 ) -> V_12 ;
if ( F_15 ( V_9 ) )
return;
if ( ! V_11 )
return;
F_16 ( V_5 , V_71 -> clock ) ;
F_5 ( V_11 + V_72 , 0x1000 ) ;
F_5 ( V_11 + V_73 , 0x0 ) ;
F_5 ( V_11 + V_74 , 0x1000 ) ;
F_3 ( V_5 , V_71 -> clock ) ;
F_5 ( V_11 + V_75 , 0x13 ) ;
F_5 ( V_11 + V_76 , 0x202 ) ;
F_7 ( V_5 , V_77 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
F_5 ( V_11 + V_78 , 0x00FFFFFF ) ;
F_5 ( V_11 + V_79 , 0x007FFFFF ) ;
F_5 ( V_11 + V_80 , 0x00000001 ) ;
F_5 ( V_11 + V_81 , 0x00000001 ) ;
F_12 ( V_5 ) ;
F_13 ( V_11 + V_69 , 0x00040000 , ~ 0x001F0000 ) ;
}
void F_17 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 = F_4 ( V_5 ) -> V_12 ;
int V_82 = F_18 ( V_9 ) ;
int V_83 = F_19 ( V_9 ) ;
int V_84 = F_20 ( V_9 ) ;
T_2 V_85 = F_21 ( V_9 ) ;
T_2 V_86 = F_22 ( V_9 ) ;
T_1 V_87 ;
if ( ! V_11 )
return;
F_2 ( L_2 ,
F_9 ( V_5 ) ? L_3 : L_4 ,
V_82 , V_83 , V_84 ) ;
F_2 ( L_5 ,
( int ) V_85 , ( int ) V_86 ) ;
V_87 = 0 ;
if ( V_85 & V_88 )
V_87 |= 1 << 0 ;
if ( V_85 & V_89 )
V_87 |= 1 << 1 ;
if ( V_85 & V_90 )
V_87 |= 1 << 2 ;
if ( V_85 & V_91 )
V_87 |= 1 << 3 ;
V_87 |= V_86 << 8 ;
switch ( V_83 ) {
case 32000 : V_87 |= 0x3 << 24 ; break;
case 44100 : V_87 |= 0x0 << 24 ; break;
case 88200 : V_87 |= 0x8 << 24 ; break;
case 176400 : V_87 |= 0xc << 24 ; break;
case 48000 : V_87 |= 0x2 << 24 ; break;
case 96000 : V_87 |= 0xa << 24 ; break;
case 192000 : V_87 |= 0xe << 24 ; break;
}
F_5 ( V_11 + V_92 , V_87 ) ;
V_87 = 0 ;
switch ( V_84 ) {
case 16 : V_87 |= 0x2 ; break;
case 20 : V_87 |= 0x3 ; break;
case 24 : V_87 |= 0xb ; break;
}
if ( V_85 & V_93 )
V_87 |= 0x5 << 16 ;
F_13 ( V_11 + V_94 , V_87 , ~ 0x5000f ) ;
F_5 ( V_11 + V_95 , 0x31 ) ;
F_8 ( V_5 , V_82 - 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ;
F_12 ( V_5 ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_4 * V_5 ;
struct V_64 * V_64 ;
bool V_96 [ 3 ] = { true , true , true } ;
F_24 (encoder, &dev->mode_config.encoder_list, head) {
V_64 = F_4 ( V_5 ) ;
switch ( V_64 -> V_12 ) {
case V_97 :
V_96 [ 0 ] = false ;
break;
case V_98 :
V_96 [ 1 ] = false ;
break;
case V_99 :
V_96 [ 2 ] = false ;
break;
}
}
if ( V_9 -> V_100 == V_101 || V_9 -> V_100 == V_102 ||
V_9 -> V_100 == V_103 ) {
return V_96 [ 0 ] ? V_97 : 0 ;
} else if ( V_9 -> V_100 >= V_104 ) {
if ( V_96 [ 0 ] )
return V_97 ;
else if ( V_96 [ 1 ] )
return V_98 ;
}
return 0 ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_64 * V_64 = F_4 ( V_5 ) ;
struct V_105 * V_106 = V_64 -> V_107 ;
T_4 V_108 [] = {
V_109 ,
V_110 ,
V_111 ,
V_112 ,
V_113 ,
V_114 ,
} ;
if ( ! V_106 ) {
F_26 ( V_9 -> V_7 , L_6 ) ;
return;
}
if ( F_15 ( V_9 ) ) {
} else if ( F_27 ( V_9 ) ) {
if ( V_106 -> V_115 >= F_28 ( V_108 ) ) {
F_26 ( V_9 -> V_7 , L_7 ) ;
return;
}
V_64 -> V_12 = V_116 +
V_108 [ V_106 -> V_115 ] ;
V_64 -> V_117 = V_64 -> V_12
+ V_118 ;
} else if ( F_29 ( V_9 ) ) {
V_64 -> V_12 = V_106 -> V_115 ?
V_99 : V_97 ;
if ( F_30 ( V_9 ) )
V_64 -> V_117 = V_106 -> V_115 ?
V_119 : V_120 ;
} else if ( V_9 -> V_100 >= V_104 || V_9 -> V_100 == V_101 ||
V_9 -> V_100 == V_102 || V_9 -> V_100 == V_103 ) {
V_64 -> V_12 = F_23 ( V_7 ) ;
}
}
void F_31 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_64 * V_64 = F_4 ( V_5 ) ;
T_1 V_11 ;
if ( F_15 ( V_9 ) )
return;
if ( ! V_64 -> V_12 ) {
F_25 ( V_5 ) ;
if ( ! V_64 -> V_12 ) {
F_32 ( V_9 -> V_7 , L_8
L_9 , V_64 -> V_121 ) ;
return;
}
}
V_11 = V_64 -> V_12 ;
if ( F_15 ( V_9 ) ) {
} else if ( F_27 ( V_9 ) ) {
F_13 ( V_64 -> V_117 + 0xc , 0x1 , ~ 0x1 ) ;
} else if ( F_30 ( V_9 ) ) {
F_13 ( V_64 -> V_117 + 0x4 , 0x1 , ~ 0x1 ) ;
} else if ( F_29 ( V_9 ) ) {
} else if ( V_9 -> V_100 >= V_104 ) {
switch ( V_64 -> V_121 ) {
case V_122 :
F_13 ( V_123 , V_124 ,
~ V_124 ) ;
F_5 ( V_11 + V_125 , 0x101 ) ;
break;
case V_126 :
F_13 ( V_127 , V_128 ,
~ V_128 ) ;
F_5 ( V_11 + V_125 , 0x105 ) ;
break;
default:
F_26 ( V_9 -> V_7 , L_10 ) ;
break;
}
}
if ( V_9 -> V_129 . V_130
&& V_9 -> V_100 != V_101
&& V_9 -> V_100 != V_102
&& V_9 -> V_100 != V_103
&& ! F_27 ( V_9 ) ) {
V_9 -> V_129 . V_131 [ V_11 == V_97 ? 0 : 1 ] = true ;
F_33 ( V_9 ) ;
F_34 ( V_5 ) ;
} else {
F_35 ( V_5 ) ;
}
F_2 ( L_11 ,
V_64 -> V_12 , V_64 -> V_121 ) ;
}
void F_36 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_64 * V_64 = F_4 ( V_5 ) ;
T_1 V_11 ;
if ( F_15 ( V_9 ) )
return;
V_11 = V_64 -> V_12 ;
if ( ! V_11 ) {
F_26 ( V_9 -> V_7 , L_12 ) ;
return;
}
F_2 ( L_13 ,
V_11 , V_64 -> V_121 ) ;
V_9 -> V_129 . V_131 [ V_11 == V_97 ? 0 : 1 ] = false ;
F_33 ( V_9 ) ;
F_34 ( V_5 ) ;
if ( F_15 ( V_9 ) ) {
} else if ( F_27 ( V_9 ) ) {
F_13 ( V_64 -> V_117 + 0xc , 0 , ~ 0x1 ) ;
} else if ( F_30 ( V_9 ) ) {
F_13 ( V_64 -> V_117 + 0x4 , 0 , ~ 0x1 ) ;
} else if ( V_9 -> V_100 >= V_104 && ! F_29 ( V_9 ) ) {
switch ( V_64 -> V_121 ) {
case V_122 :
F_13 ( V_123 , 0 ,
~ V_124 ) ;
F_5 ( V_11 + V_125 , 0 ) ;
break;
case V_126 :
F_13 ( V_127 , 0 ,
~ V_128 ) ;
F_5 ( V_11 + V_125 , 0 ) ;
break;
default:
F_26 ( V_9 -> V_7 , L_10 ) ;
break;
}
}
V_64 -> V_12 = 0 ;
V_64 -> V_117 = 0 ;
}
