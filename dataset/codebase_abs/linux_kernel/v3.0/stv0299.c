static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_6 , . V_13 = 2 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1
L_2 , V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - V_16 : 0 ;
}
static int F_4 ( struct V_17 * V_18 , const T_1 V_6 [] , int V_13 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_13 != 2 )
return - V_20 ;
return F_1 ( V_2 , V_6 [ 0 ] , V_6 [ 1 ] ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_21 [] = { V_3 } ;
T_1 V_22 [] = { 0 } ;
struct V_7 V_8 [] = { { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_21 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_23 , . V_6 = V_22 , . V_13 = 1 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( L_3 ,
V_15 , V_3 , V_5 ) ;
return V_22 [ 0 ] ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_24 , T_1 * V_25 , T_1 V_13 )
{
int V_5 ;
struct V_7 V_8 [] = { { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = & V_24 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_23 , . V_6 = V_25 , . V_13 = V_13 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( L_4 , V_15 , V_5 ) ;
return V_5 == 2 ? 0 : V_5 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_26 )
{
F_3 ( L_5 , V_15 ) ;
switch ( V_26 ) {
case V_27 :
{
return F_1 ( V_2 , 0x31 , 0x1f ) ;
}
case V_28 :
{
return F_1 ( V_2 , 0x31 , 0x01 ) ;
}
case V_29 :
{
return F_1 ( V_2 , 0x31 , 0x02 ) ;
}
case V_30 :
{
return F_1 ( V_2 , 0x31 , 0x04 ) ;
}
case V_31 :
{
return F_1 ( V_2 , 0x31 , 0x08 ) ;
}
case V_32 :
{
return F_1 ( V_2 , 0x31 , 0x10 ) ;
}
default:
{
return - V_20 ;
}
}
}
static T_2 F_8 ( struct V_1 * V_2 )
{
static T_2 V_33 [] = { V_29 , V_30 , V_31 ,
V_32 , V_28 } ;
T_1 V_34 ;
F_3 ( L_5 , V_15 ) ;
V_34 = F_5 ( V_2 , 0x1b ) ;
V_34 &= 0x7 ;
if ( V_34 > 4 )
return V_27 ;
return V_33 [ V_34 ] ;
}
static int F_9 ( struct V_1 * V_2 , int V_35 )
{
unsigned long V_36 = V_37 ;
F_3 ( L_5 , V_15 ) ;
while ( F_5 ( V_2 , 0x0a ) & 1 ) {
if ( V_37 - V_36 > V_35 ) {
F_3 ( L_6 , V_15 ) ;
return - V_38 ;
}
F_10 ( 10 ) ;
} ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_35 )
{
unsigned long V_36 = V_37 ;
F_3 ( L_5 , V_15 ) ;
while ( ( F_5 ( V_2 , 0x0a ) & 3 ) != 2 ) {
if ( V_37 - V_36 > V_35 ) {
F_3 ( L_6 , V_15 ) ;
return - V_38 ;
}
F_10 ( 10 ) ;
} ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , T_3 V_39 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_4 V_40 = V_39 ;
T_3 V_41 ;
if ( ( V_39 < 1000000 ) || ( V_39 > 45000000 ) ) return - V_20 ;
V_40 = V_40 << 20 ;
V_40 += ( V_2 -> V_10 -> V_42 - 1 ) ;
F_13 ( V_40 , V_2 -> V_10 -> V_42 ) ;
V_41 = V_40 << 4 ;
return V_2 -> V_10 -> V_43 ( V_18 , V_39 , V_41 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_3 V_44 = V_2 -> V_10 -> V_42 / 4096L ;
T_3 V_39 ;
T_5 V_45 ;
T_1 V_46 [ 3 ] ;
T_6 V_47 ;
F_3 ( L_5 , V_15 ) ;
F_6 ( V_2 , 0x1f , V_46 , 3 ) ;
F_6 ( V_2 , 0x1a , ( T_1 * ) & V_47 , 1 ) ;
V_39 = ( V_46 [ 0 ] << 8 ) | V_46 [ 1 ] ;
V_39 *= V_44 ;
V_39 /= 16 ;
V_39 += ( V_46 [ 2 ] >> 4 ) * V_44 / 256 ;
V_45 = ( T_5 ) V_47 * ( V_39 / 4096L ) ;
V_45 /= 128 ;
F_3 ( L_7 , V_15 , V_39 ) ;
F_3 ( L_8 , V_15 , V_45 ) ;
V_39 += V_45 ;
V_39 += 1000 ;
V_39 /= 2000 ;
V_39 *= 2000 ;
return V_39 ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_50 ;
int V_51 ;
F_3 ( L_5 , V_15 ) ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_38 ;
V_50 = F_5 ( V_2 , 0x08 ) ;
if ( F_1 ( V_2 , 0x08 , ( V_50 & ~ 0x7 ) | 0x6 ) )
return - V_16 ;
for ( V_51 = 0 ; V_51 < V_49 -> V_52 ; V_51 ++ ) {
if ( F_9 ( V_2 , 100 ) < 0 )
return - V_38 ;
if ( F_1 ( V_2 , 0x09 , V_49 -> V_8 [ V_51 ] ) )
return - V_16 ;
}
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_38 ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 , T_7 V_53 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_50 ;
F_3 ( L_5 , V_15 ) ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_38 ;
V_50 = F_5 ( V_2 , 0x08 ) ;
if ( F_1 ( V_2 , 0x08 , ( V_50 & ~ 0x7 ) | 0x2 ) )
return - V_16 ;
if ( F_1 ( V_2 , 0x09 , V_53 == V_54 ? 0x00 : 0xff ) )
return - V_16 ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_38 ;
if ( F_1 ( V_2 , 0x08 , V_50 ) )
return - V_16 ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 , T_8 V_55 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_50 ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_38 ;
V_50 = F_5 ( V_2 , 0x08 ) ;
switch ( V_55 ) {
case V_56 :
return F_1 ( V_2 , 0x08 , V_50 | 0x3 ) ;
case V_57 :
return F_1 ( V_2 , 0x08 , ( V_50 & ~ 0x3 ) | 0x02 ) ;
default:
return - V_20 ;
}
}
static int F_18 ( struct V_17 * V_18 , T_9 V_58 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_59 ;
T_1 V_60 ;
F_3 ( L_9 , V_15 ,
V_58 == V_61 ? L_10 :
V_58 == V_62 ? L_11 : L_12 ) ;
V_59 = F_5 ( V_2 , 0x08 ) ;
V_60 = F_5 ( V_2 , 0x0c ) ;
V_60 &= 0x0f ;
V_59 = ( V_59 & 0x3f ) | ( V_2 -> V_10 -> V_63 << 6 ) ;
switch ( V_58 ) {
case V_61 :
if ( V_2 -> V_10 -> V_64 == V_65 )
V_60 |= 0x10 ;
else
V_60 |= 0x40 ;
break;
case V_62 :
V_60 |= 0x50 ;
break;
case V_66 :
V_59 = 0x00 ;
V_60 = 0x00 ;
break;
default:
return - V_20 ;
} ;
if ( V_2 -> V_10 -> V_67 )
V_60 &= ~ 0x10 ;
F_1 ( V_2 , 0x08 , V_59 ) ;
return F_1 ( V_2 , 0x0c , V_60 ) ;
}
static int F_19 ( struct V_17 * V_18 , unsigned long V_68 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_59 ;
T_1 V_60 ;
T_1 V_69 = 0x40 ;
T_1 V_70 = 1 ;
int V_51 ;
struct V_71 V_72 ;
struct V_71 V_73 [ 10 ] ;
V_59 = F_5 ( V_2 , 0x08 ) ;
V_60 = F_5 ( V_2 , 0x0c ) ;
V_60 &= 0x0f ;
F_1 ( V_2 , 0x08 , ( V_59 & 0x3f ) | ( V_2 -> V_10 -> V_63 << 6 ) ) ;
if ( V_2 -> V_10 -> V_64 == V_65 )
V_69 = 0x10 ;
V_68 = V_68 << 1 ;
if ( V_74 )
F_20 ( L_13 , V_15 , V_68 ) ;
F_21 ( & V_72 ) ;
if ( V_74 )
memcpy ( & V_73 [ 0 ] , & V_72 , sizeof ( struct V_71 ) ) ;
F_1 ( V_2 , 0x0c , V_60 | 0x50 ) ;
F_22 ( & V_72 , 32000 ) ;
for ( V_51 = 0 ; V_51 < 9 ; V_51 ++ ) {
if ( V_74 )
F_21 ( & V_73 [ V_51 + 1 ] ) ;
if( ( V_68 & 0x01 ) != V_70 ) {
F_1 ( V_2 , 0x0c , V_60 | ( V_70 ? V_69 : 0x50 ) ) ;
V_70 = ( V_70 ) ? 0 : 1 ;
}
V_68 = V_68 >> 1 ;
if ( V_51 != 8 )
F_22 ( & V_72 , 8000 ) ;
}
if ( V_74 ) {
F_20 ( L_14 ,
V_15 , V_18 -> V_75 -> V_76 ) ;
for ( V_51 = 1 ; V_51 < 10 ; V_51 ++ )
F_20 ( L_15 , V_51 , F_23 ( V_73 [ V_51 - 1 ] , V_73 [ V_51 ] ) ) ;
}
return 0 ;
}
static int F_24 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_51 ;
T_1 V_3 ;
T_1 V_50 ;
F_3 ( L_16 ) ;
F_1 ( V_2 , 0x02 , 0x30 | V_2 -> V_77 ) ;
F_10 ( 50 ) ;
for ( V_51 = 0 ; ; V_51 += 2 ) {
V_3 = V_2 -> V_10 -> V_78 [ V_51 ] ;
V_50 = V_2 -> V_10 -> V_78 [ V_51 + 1 ] ;
if ( V_3 == 0xff && V_50 == 0xff )
break;
if ( V_3 == 0x0c && V_2 -> V_10 -> V_67 )
V_50 &= ~ 0x10 ;
if ( V_3 == 0x2 )
V_2 -> V_77 = V_50 & 0xf ;
F_1 ( V_2 , V_3 , V_50 ) ;
}
return 0 ;
}
static int F_25 ( struct V_17 * V_18 , T_10 * V_79 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 signal = 0xff - F_5 ( V_2 , 0x18 ) ;
T_1 V_80 = F_5 ( V_2 , 0x1b ) ;
F_3 ( L_17 , V_15 , V_80 ) ;
* V_79 = 0 ;
if ( signal > 10 )
* V_79 |= V_81 ;
if ( V_80 & 0x80 )
* V_79 |= V_82 ;
if ( V_80 & 0x10 )
* V_79 |= V_83 ;
if ( V_80 & 0x08 )
* V_79 |= V_84 ;
if ( ( V_80 & 0x98 ) == 0x98 )
* V_79 |= V_85 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 , T_3 * V_86 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_2 -> V_87 != V_88 )
return - V_89 ;
* V_86 = F_5 ( V_2 , 0x1e ) | ( F_5 ( V_2 , 0x1d ) << 8 ) ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 , T_11 * V_90 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_5 signal = 0xffff - ( ( F_5 ( V_2 , 0x18 ) << 8 )
| F_5 ( V_2 , 0x19 ) ) ;
F_3 ( L_18 , V_15 ,
F_5 ( V_2 , 0x18 ) ,
F_5 ( V_2 , 0x19 ) , ( int ) signal ) ;
signal = signal * 5 / 4 ;
* V_90 = ( signal > 0xffff ) ? 0xffff : ( signal < 0 ) ? 0 : signal ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 , T_11 * V_91 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_5 V_92 = 0xffff - ( ( F_5 ( V_2 , 0x24 ) << 8 )
| F_5 ( V_2 , 0x25 ) ) ;
V_92 = 3 * ( V_92 - 0xa100 ) ;
* V_91 = ( V_92 > 0xffff ) ? 0xffff : ( V_92 < 0 ) ? 0 : V_92 ;
return 0 ;
}
static int F_29 ( struct V_17 * V_18 , T_3 * V_93 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_2 -> V_87 != V_94 )
return - V_89 ;
V_2 -> V_93 += F_5 ( V_2 , 0x1e ) ;
V_2 -> V_93 += ( F_5 ( V_2 , 0x1d ) << 8 ) ;
* V_93 = V_2 -> V_93 ;
return 0 ;
}
static int F_30 ( struct V_17 * V_18 , struct V_95 * V_96 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_97 = 0 ;
F_3 ( L_19 , V_15 ) ;
if ( V_2 -> V_10 -> V_98 )
V_2 -> V_10 -> V_98 ( V_18 , 0 ) ;
if ( V_96 -> V_99 == V_100 ) V_97 = 0 ;
else if ( V_96 -> V_99 == V_101 ) V_97 = 1 ;
else {
F_20 ( L_20 ) ;
return - V_20 ;
}
if ( V_2 -> V_10 -> V_102 ) V_97 = ( ~ V_97 ) & 1 ;
F_1 ( V_2 , 0x0c , ( F_5 ( V_2 , 0x0c ) & 0xfe ) | V_97 ) ;
if ( V_18 -> V_103 . V_104 . V_105 ) {
V_18 -> V_103 . V_104 . V_105 ( V_18 , V_96 ) ;
if ( V_18 -> V_103 . V_106 ) V_18 -> V_103 . V_106 ( V_18 , 0 ) ;
}
F_7 ( V_2 , V_96 -> V_107 . V_108 . V_109 ) ;
F_12 ( V_18 , V_96 -> V_107 . V_108 . V_110 ) ;
F_1 ( V_2 , 0x22 , 0x00 ) ;
F_1 ( V_2 , 0x23 , 0x00 ) ;
V_2 -> V_111 = V_96 -> V_112 ;
V_2 -> V_109 = V_96 -> V_107 . V_108 . V_109 ;
V_2 -> V_110 = V_96 -> V_107 . V_108 . V_110 ;
return 0 ;
}
static int F_31 ( struct V_17 * V_18 , struct V_95 * V_96 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_5 V_113 ;
int V_97 ;
V_113 = ( T_5 ) ( V_114 ) ( ( F_5 ( V_2 , 0x22 ) << 8 )
| F_5 ( V_2 , 0x23 ) ) ;
V_113 *= ( V_2 -> V_10 -> V_42 >> 16 ) ;
V_113 += 500 ;
V_113 /= 1000 ;
V_96 -> V_112 += V_113 ;
V_97 = F_5 ( V_2 , 0x0c ) & 1 ;
if ( V_2 -> V_10 -> V_102 ) V_97 = ( ~ V_97 ) & 1 ;
V_96 -> V_99 = V_97 ? V_101 : V_100 ;
V_96 -> V_107 . V_108 . V_109 = F_8 ( V_2 ) ;
V_96 -> V_107 . V_108 . V_110 = F_14 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_1 ( V_2 , 0x02 , 0xb0 | V_2 -> V_77 ) ;
V_2 -> V_115 = 0 ;
return 0 ;
}
static int F_33 ( struct V_17 * V_18 , int V_116 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_116 ) {
F_1 ( V_2 , 0x05 , 0xb5 ) ;
} else {
F_1 ( V_2 , 0x05 , 0x35 ) ;
}
F_34 ( 1 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_18 , struct V_117 * V_118 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
V_118 -> V_119 = V_2 -> V_10 -> V_119 ;
if ( V_118 -> V_120 . V_107 . V_108 . V_110 < 10000000 ) {
V_118 -> V_121 = V_118 -> V_120 . V_107 . V_108 . V_110 / 32000 ;
V_118 -> V_122 = 5000 ;
} else {
V_118 -> V_121 = V_118 -> V_120 . V_107 . V_108 . V_110 / 16000 ;
V_118 -> V_122 = V_118 -> V_120 . V_107 . V_108 . V_110 / 2000 ;
}
return 0 ;
}
static void F_36 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_37 ( V_2 ) ;
}
struct V_17 * F_38 ( const struct V_123 * V_10 ,
struct V_124 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_125 ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_126 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_115 = 0 ;
V_2 -> V_111 = 0 ;
V_2 -> V_110 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_87 = V_88 ;
F_1 ( V_2 , 0x02 , 0x30 ) ;
F_10 ( 200 ) ;
V_125 = F_5 ( V_2 , 0x00 ) ;
if ( V_125 != 0xa1 && V_125 != 0x80 ) goto error;
memcpy ( & V_2 -> V_127 . V_103 , & V_128 , sizeof( struct V_129 ) ) ;
V_2 -> V_127 . V_19 = V_2 ;
return & V_2 -> V_127 ;
error:
F_37 ( V_2 ) ;
return NULL ;
}
