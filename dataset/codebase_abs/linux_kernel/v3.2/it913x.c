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
static T_2 F_6 ( T_1 * V_9 , T_1 V_4 )
{
T_2 V_10 = 0 ;
T_1 V_11 = 1 ;
while ( V_11 < V_4 )
V_10 += ( V_11 ++ & 1 ) ? ( * V_9 ++ ) << 8 : * V_9 ++ ;
return ~ V_10 ;
}
static int F_7 ( struct V_1 * V_12 , T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_3 V_16 , T_1 V_17 , T_1 * V_18 , T_1 V_4 )
{
int V_6 = 0 , V_11 , V_19 = 1 ;
T_1 * V_20 ;
T_1 V_21 ;
T_2 V_22 ;
V_20 = F_8 ( 256 , V_23 ) ;
if ( ! V_20 ) {
F_9 ( L_1 ) ;
return - V_24 ;
}
V_20 [ V_19 ++ ] = V_14 ;
V_20 [ V_19 ++ ] = V_15 ;
V_20 [ V_19 ++ ] = V_25 ;
switch ( V_13 ) {
case V_26 :
case V_27 :
V_20 [ V_19 ++ ] = V_4 ;
V_20 [ V_19 ++ ] = 2 ;
V_20 [ V_19 ++ ] = ( V_16 >> 24 ) ;
V_20 [ V_19 ++ ] = ( V_16 >> 16 ) & 0xff ;
V_20 [ V_19 ++ ] = ( V_16 >> 8 ) & 0xff ;
V_20 [ V_19 ++ ] = V_16 & 0xff ;
break;
case V_28 :
V_20 [ V_19 ++ ] = V_17 ;
break;
case V_29 :
V_20 [ V_19 ++ ] = V_4 ;
V_20 [ V_19 ++ ] = V_17 ;
V_20 [ V_19 ++ ] = ( V_16 >> 8 ) & 0xff ;
V_20 [ V_19 ++ ] = V_16 & 0xff ;
break;
case V_30 :
case V_31 :
break;
case V_32 :
V_13 = 7 ;
break;
default:
F_10 ( V_20 ) ;
return - V_33 ;
}
if ( V_13 & 1 ) {
for ( V_11 = 0 ; V_11 < V_4 ; V_11 ++ )
V_20 [ V_19 ++ ] = V_18 [ V_11 ] ;
}
V_22 = F_6 ( & V_20 [ 1 ] , V_19 ) ;
V_20 [ V_19 ++ ] = V_22 >> 8 ;
V_20 [ 0 ] = V_19 ;
V_20 [ V_19 ++ ] = ( V_22 & 0xff ) ;
V_6 = F_1 ( V_12 , V_20 , V_19 , 0x02 ) ;
V_6 |= F_4 ( V_12 , V_20 , ( V_13 & 1 ) ?
5 : V_4 + 5 , 0x01 ) ;
V_21 = ( V_13 & 0x1 ) ? 0x1 : V_4 ;
if ( V_13 & 1 )
V_6 |= V_20 [ 2 ] ;
else
memcpy ( V_18 , & V_20 [ 3 ] , V_21 ) ;
V_25 ++ ;
F_10 ( V_20 ) ;
return ( V_6 < 0 ) ? - V_34 : 0 ;
}
static int F_11 ( struct V_1 * V_12 , T_1 V_14 , T_3 V_16 , T_1 V_18 )
{
int V_6 ;
T_1 V_35 [ 1 ] ;
V_35 [ 0 ] = V_18 ;
V_6 = F_7 ( V_12 , V_27 , V_14 ,
V_36 , V_16 , 0 , V_35 , sizeof( V_35 ) ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_12 , T_3 V_16 )
{
int V_6 ;
T_1 V_18 [ 1 ] ;
V_6 = F_7 ( V_12 , V_26 , V_37 ,
V_38 , V_16 , 0 , & V_18 [ 0 ] , 1 ) ;
return ( V_6 < 0 ) ? V_6 : V_18 [ 0 ] ;
}
static T_3 F_13 ( struct V_1 * V_12 , T_1 V_14 )
{
int V_6 ;
T_1 V_18 [ 4 ] ;
V_6 = F_7 ( V_12 , V_26 , V_14 , V_38 ,
0x1222 , 0 , & V_18 [ 0 ] , 3 ) ;
V_39 . V_40 = V_18 [ 0 ] ;
V_39 . V_41 = ( T_2 ) ( V_18 [ 2 ] << 8 ) + V_18 [ 1 ] ;
F_9 ( L_2 , V_39 . V_40 ,
V_39 . V_41 ) ;
V_6 |= F_7 ( V_12 , V_28 , V_14 ,
V_42 , 0 , 0x1 , & V_18 [ 0 ] , 4 ) ;
V_39 . V_43 = ( V_18 [ 0 ] << 24 ) + ( V_18 [ 1 ] << 16 ) +
( V_18 [ 2 ] << 8 ) + V_18 [ 3 ] ;
return ( V_6 < 0 ) ? 0 : V_39 . V_43 ;
}
static int F_14 ( struct V_44 * V_45 , int V_46 )
{
int V_6 = 0 ;
T_1 V_14 = ( V_45 -> V_47 == 0 ) ? V_48 : V_49 ;
if ( F_15 ( & V_45 -> V_2 -> V_50 ) < 0 )
return - V_51 ;
F_16 ( 1 , L_3 , V_46 ) ;
if ( ! V_46 )
V_6 = F_11 ( V_45 -> V_2 -> V_12 , V_14 , V_52 , 0x1 ) ;
F_17 ( & V_45 -> V_2 -> V_50 ) ;
return V_6 ;
}
static int F_18 ( struct V_44 * V_45 ,
int V_53 , T_2 V_54 , int V_46 )
{
struct V_1 * V_12 = V_45 -> V_2 -> V_12 ;
int V_6 = 0 ;
T_1 V_14 = ( V_45 -> V_47 == 0 ) ? V_48 : V_49 ;
if ( V_55 > 0 )
return 0 ;
if ( F_15 ( & V_45 -> V_2 -> V_50 ) < 0 )
return - V_51 ;
F_16 ( 1 , L_4 , V_46 ) ;
if ( V_46 ) {
V_6 = F_11 ( V_12 , V_14 , V_56 , 0x1 ) ;
V_6 |= F_11 ( V_12 , V_14 , V_57 , ( T_1 ) ( V_54 & 0xff ) ) ;
V_6 |= F_11 ( V_12 , V_14 , V_58 , ( T_1 ) ( V_54 >> 8 ) ) ;
V_6 |= F_11 ( V_12 , V_14 , V_59 , ( T_1 ) V_46 ) ;
V_6 |= F_11 ( V_12 , V_14 , V_60 , ( T_1 ) ( V_53 & 0x1f ) ) ;
}
F_17 ( & V_45 -> V_2 -> V_50 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_12 )
{
T_3 V_61 = 0 ;
V_61 = F_13 ( V_12 , V_37 ) ;
if ( V_61 > 0 )
F_9 ( L_5 , V_61 ) ;
return ( V_61 > 0 ) ? V_61 : 0 ;
}
static int F_20 ( struct V_62 * V_45 , struct V_63 V_64 [] ,
int V_65 )
{
struct V_66 * V_67 = F_21 ( V_45 ) ;
static T_1 V_18 [ 256 ] ;
int V_6 ;
T_3 V_16 ;
T_1 V_14 ;
if ( F_15 ( & V_67 -> V_50 ) < 0 )
return - V_51 ;
F_22 ( 1 , L_6 , V_64 [ 0 ] . V_68 ) ;
F_16 ( 2 , L_7 , V_65 , V_64 [ 0 ] . V_17 ) ;
V_14 = ( V_64 [ 0 ] . V_17 & 0x2 ) ? V_48 : 0x0 ;
V_14 |= ( V_64 [ 0 ] . V_17 & 0x20 ) ? V_69 : V_37 ;
memcpy ( V_18 , V_64 [ 0 ] . V_68 , V_64 [ 0 ] . V_4 ) ;
V_16 = ( V_18 [ 0 ] << 24 ) + ( V_18 [ 1 ] << 16 ) +
( V_18 [ 2 ] << 8 ) + V_18 [ 3 ] ;
if ( V_65 == 2 ) {
V_6 = F_7 ( V_67 -> V_12 , V_26 , V_14 ,
V_38 , V_16 , 0 , V_18 , V_64 [ 1 ] . V_4 ) ;
memcpy ( V_64 [ 1 ] . V_68 , V_18 , V_64 [ 1 ] . V_4 ) ;
} else
V_6 = F_7 ( V_67 -> V_12 , V_27 , V_14 , V_36 ,
V_16 , 0 , & V_18 [ 4 ] , V_64 [ 0 ] . V_4 - 4 ) ;
F_17 ( & V_67 -> V_50 ) ;
return V_6 ;
}
static T_3 F_23 ( struct V_62 * V_70 )
{
return V_71 ;
}
static int F_24 ( struct V_66 * V_67 )
{
T_1 V_72 [ 4 ] ;
int V_6 ;
T_3 V_73 ;
if ( F_15 ( & V_67 -> V_50 ) < 0 )
return - V_51 ;
V_6 = F_7 ( V_67 -> V_12 , V_26 , V_74 , V_75 ,
0 , 0 , & V_72 [ 0 ] , sizeof( V_72 ) ) ;
if ( ( V_72 [ 2 ] + V_72 [ 3 ] ) == 0xff ) {
V_73 = V_72 [ 2 ] ;
V_73 += V_72 [ 0 ] << 8 ;
F_16 ( 1 , L_8 , V_73 ) ;
if ( V_67 -> V_76 != NULL )
F_25 ( V_67 -> V_76 , V_73 , 0 ) ;
}
F_17 ( & V_67 -> V_50 ) ;
return V_6 ;
}
static int F_26 ( struct V_1 * V_12 ,
struct V_77 * V_78 ,
struct V_79 * * V_80 ,
int * V_81 )
{
int V_6 = 0 , V_82 ;
T_1 V_16 , V_83 ;
V_82 = F_19 ( V_12 ) ;
V_39 . V_84 = F_12 ( V_12 , 0x49c5 ) ;
V_83 = F_12 ( V_12 , 0x49ac ) ;
if ( V_83 == 0 )
V_78 -> V_85 . V_86 . V_87 = NULL ;
V_39 . V_88 = F_12 ( V_12 , 0x49d0 ) ;
F_9 ( L_9 , V_39 . V_84
, V_83 , V_39 . V_88 ) ;
if ( V_82 > 0 ) {
* V_81 = 0 ;
return 0 ;
}
if ( V_39 . V_84 ) {
V_39 . V_89 = F_12 ( V_12 , 0x49e0 ) ;
V_6 = F_11 ( V_12 , V_37 , V_90 , 0x1 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_91 , 0x1 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_92 , 0x1 ) ;
F_27 ( 50 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_92 , 0x0 ) ;
F_27 ( 50 ) ;
V_16 = F_12 ( V_12 , V_92 ) ;
if ( V_16 == 0 ) {
V_6 |= F_11 ( V_12 , V_37 , V_92 , 0x1 ) ;
V_6 |= F_19 ( V_12 ) ;
if ( V_6 != 0 )
V_6 = F_11 ( V_12 , V_37 ,
V_92 , 0x0 ) ;
}
V_78 -> V_93 = 2 ;
} else
V_78 -> V_93 = 1 ;
V_16 = F_12 ( V_12 , V_94 ) ;
if ( V_39 . V_84 ) {
V_6 |= F_11 ( V_12 , V_37 , 0x4bfb , V_95 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_96 , 0x1 ) ;
} else {
V_6 |= F_11 ( V_12 , V_37 , 0x4bfb , 0x0 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_96 , 0x0 ) ;
}
* V_81 = 1 ;
return ( V_6 < 0 ) ? - V_34 : 0 ;
}
static int F_28 ( struct V_44 * V_45 , int V_46 )
{
int V_6 = 0 ;
T_1 V_14 = ( V_45 -> V_47 == 0 ) ? V_48 : V_49 ;
if ( F_15 ( & V_45 -> V_2 -> V_50 ) < 0 )
return - V_51 ;
F_16 ( 1 , L_10 , V_46 ) ;
if ( ! V_46 )
V_6 = F_11 ( V_45 -> V_2 -> V_12 , V_14 , V_52 , 0x1 ) ;
F_17 ( & V_45 -> V_2 -> V_50 ) ;
return V_6 ;
}
static int F_29 ( struct V_1 * V_12 ,
const struct V_43 * V_97 )
{
int V_6 = 0 , V_11 ;
T_1 V_98 , V_99 ;
T_1 * V_100 ;
V_98 = 0x29 ;
V_6 = F_11 ( V_12 , V_37 , V_101 , V_102 ) ;
F_9 ( L_11 ) ;
for ( V_11 = 0 ; V_11 < V_97 -> V_103 ; V_11 += V_98 ) {
if ( V_11 > 0 )
V_98 = 0x39 ;
V_100 = ( T_1 * ) ( V_97 -> V_18 + V_11 ) ;
V_99 = ( ( V_11 + V_98 ) > V_97 -> V_103 )
? ( V_97 -> V_103 - V_11 ) : V_98 ;
V_6 |= F_7 ( V_12 , V_31 , V_37 ,
V_104 , 0 , 0 , V_100 , V_99 ) ;
F_30 ( 1000 ) ;
}
V_6 |= F_7 ( V_12 , V_32 , V_37 ,
V_105 , 0 , 0 , NULL , 0 ) ;
F_27 ( 100 ) ;
if ( V_6 < 0 )
F_9 ( L_12 , V_6 ) ;
else
F_9 ( L_13 ) ;
V_6 |= F_19 ( V_12 ) ;
F_27 ( 30 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_101 , V_106 ) ;
if ( V_39 . V_84 )
V_6 |= F_11 ( V_12 , V_48 , 0xec4c , 0xa0 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_107 , 0x0 ) ;
V_6 |= F_11 ( V_12 , V_37 , V_108 , 0x0 ) ;
if ( V_39 . V_84 ) {
V_6 |= F_11 ( V_12 , V_69 , V_107 , 0x0 ) ;
V_6 |= F_11 ( V_12 , V_69 , V_108 , 0x0 ) ;
}
return ( V_6 < 0 ) ? - V_34 : 0 ;
}
static int F_31 ( struct V_44 * V_45 )
{
const char * V_80 = V_45 -> V_2 -> V_80 -> V_109 ;
char * V_110 [] = { L_14 , L_15 , L_16 , L_17 } ;
char * V_109 = V_45 -> V_111 [ 0 ] . V_112 -> V_113 . F_9 . V_109 ;
F_32 ( V_109 , V_80 , 128 ) ;
F_33 ( V_109 , V_110 [ V_45 -> V_47 ] , 128 ) ;
return 0 ;
}
static int F_34 ( struct V_44 * V_45 )
{
struct V_1 * V_12 = V_45 -> V_2 -> V_12 ;
int V_6 = 0 ;
T_1 V_114 = F_12 ( V_12 , V_94 ) ;
T_1 V_115 = V_116 + ( V_45 -> V_47 << 5 ) ;
T_2 V_117 = V_45 -> V_78 . V_112 [ 0 ] . V_118 . V_119 . V_120 . V_121 ;
T_1 V_122 , V_123 ;
if ( V_45 -> V_47 == 0 )
V_122 = V_39 . V_88 ;
else
V_122 = V_39 . V_89 ;
switch ( V_122 ) {
case 0x51 :
case 0x52 :
case 0x60 :
case 0x61 :
case 0x62 :
default:
case 0x38 :
V_123 = V_124 ;
}
V_45 -> V_111 [ 0 ] . V_112 = F_35 ( V_125 ,
& V_45 -> V_2 -> V_126 , V_115 , V_114 , V_123 ) ;
if ( V_45 -> V_47 == 0 && V_45 -> V_111 [ 0 ] . V_112 ) {
V_6 = F_11 ( V_12 , V_48 , V_127 , 0x1 ) ;
V_6 = F_11 ( V_12 , V_48 , V_128 , 0x1 ) ;
V_6 = F_11 ( V_12 , V_37 , V_129 , 0x0f ) ;
V_6 = F_11 ( V_12 , V_37 , V_130 , 0x1b ) ;
V_6 = F_11 ( V_12 , V_37 , V_129 , 0x2f ) ;
V_6 = F_11 ( V_12 , V_37 , V_131 ,
V_117 & 0xff ) ;
V_6 = F_11 ( V_12 , V_37 , V_132 , V_117 >> 8 ) ;
V_6 = F_11 ( V_12 , V_37 , V_133 , 0x80 ) ;
} else if ( V_45 -> V_47 == 1 && V_45 -> V_111 [ 0 ] . V_112 ) {
V_6 = F_11 ( V_12 , V_37 , V_129 , 0x6f ) ;
V_6 = F_11 ( V_12 , V_37 , V_134 ,
V_117 & 0xff ) ;
V_6 = F_11 ( V_12 , V_37 , V_135 , V_117 >> 8 ) ;
V_6 = F_11 ( V_12 , V_37 , V_136 , 0x80 ) ;
V_6 = F_11 ( V_12 , V_48 , V_137 , 0x1 ) ;
V_6 = F_11 ( V_12 , V_49 , V_138 , 0x1 ) ;
V_6 = F_11 ( V_12 , V_69 , V_139 , 0x1 ) ;
V_6 = F_11 ( V_12 , V_48 , V_140 , 0x1 ) ;
V_6 = F_11 ( V_12 , V_48 , V_127 , 0x0 ) ;
V_6 = F_11 ( V_12 , V_48 , V_128 , 0x0 ) ;
V_6 = F_11 ( V_12 , V_48 , V_141 , 0x0 ) ;
V_6 = F_11 ( V_12 , V_48 , V_142 , 0x1 ) ;
V_6 = F_11 ( V_12 , V_49 , V_143 , 0x0 ) ;
V_6 = F_11 ( V_12 , V_49 , V_142 , 0x0 ) ;
} else
return - V_34 ;
V_6 = F_31 ( V_45 ) ;
return V_6 ;
}
static int F_36 ( struct V_144 * V_145 ,
const struct V_146 * V_47 )
{
V_25 = 0 ;
if ( 0 == F_37 ( V_145 , & V_147 ,
V_148 , NULL , V_149 ) ) {
F_9 ( L_18 ) ;
return 0 ;
}
F_9 ( L_19 ) ;
return - V_34 ;
}
static int T_4 F_38 ( void )
{
int V_150 = F_39 ( & V_151 ) ;
if ( V_150 ) {
F_40 ( L_20 , V_150 ) ;
return V_150 ;
}
return 0 ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_151 ) ;
}
