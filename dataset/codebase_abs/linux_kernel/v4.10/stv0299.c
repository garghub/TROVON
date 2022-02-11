static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 , . V_6 = V_6 , . V_13 = 2 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1 ,
V_15 , V_3 , V_4 , V_5 ) ;
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
F_3 ( L_2 ,
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
F_3 ( L_3 , V_15 , V_5 ) ;
return V_5 == 2 ? 0 : V_5 ;
}
static int F_7 ( struct V_1 * V_2 , enum V_26 V_27 )
{
F_3 ( L_4 , V_15 ) ;
switch ( V_27 ) {
case V_28 :
{
return F_1 ( V_2 , 0x31 , 0x1f ) ;
}
case V_29 :
{
return F_1 ( V_2 , 0x31 , 0x01 ) ;
}
case V_30 :
{
return F_1 ( V_2 , 0x31 , 0x02 ) ;
}
case V_31 :
{
return F_1 ( V_2 , 0x31 , 0x04 ) ;
}
case V_32 :
{
return F_1 ( V_2 , 0x31 , 0x08 ) ;
}
case V_33 :
{
return F_1 ( V_2 , 0x31 , 0x10 ) ;
}
default:
{
return - V_20 ;
}
}
}
static enum V_26 F_8 ( struct V_1 * V_2 )
{
static enum V_26 V_34 [] = { V_30 , V_31 , V_32 ,
V_33 , V_29 } ;
T_1 V_35 ;
F_3 ( L_4 , V_15 ) ;
V_35 = F_5 ( V_2 , 0x1b ) ;
V_35 &= 0x7 ;
if ( V_35 > 4 )
return V_28 ;
return V_34 [ V_35 ] ;
}
static int F_9 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_37 = V_38 ;
F_3 ( L_4 , V_15 ) ;
while ( F_5 ( V_2 , 0x0a ) & 1 ) {
if ( V_38 - V_37 > V_36 ) {
F_3 ( L_5 , V_15 ) ;
return - V_39 ;
}
F_10 ( 10 ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_37 = V_38 ;
F_3 ( L_4 , V_15 ) ;
while ( ( F_5 ( V_2 , 0x0a ) & 3 ) != 2 ) {
if ( V_38 - V_37 > V_36 ) {
F_3 ( L_5 , V_15 ) ;
return - V_39 ;
}
F_10 ( 10 ) ;
}
return 0 ;
}
static int F_12 ( struct V_17 * V_18 , T_2 V_40 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_3 V_41 = V_40 ;
T_2 V_42 ;
if ( ( V_40 < 1000000 ) || ( V_40 > 45000000 ) ) return - V_20 ;
V_41 = V_41 << 20 ;
V_41 += ( V_2 -> V_10 -> V_43 - 1 ) ;
F_13 ( V_41 , V_2 -> V_10 -> V_43 ) ;
V_42 = V_41 << 4 ;
return V_2 -> V_10 -> V_44 ( V_18 , V_40 , V_42 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_2 V_45 = V_2 -> V_10 -> V_43 / 4096L ;
T_2 V_40 ;
T_4 V_46 ;
T_1 V_47 [ 3 ] ;
T_5 V_48 ;
F_3 ( L_4 , V_15 ) ;
F_6 ( V_2 , 0x1f , V_47 , 3 ) ;
F_6 ( V_2 , 0x1a , ( T_1 * ) & V_48 , 1 ) ;
V_40 = ( V_47 [ 0 ] << 8 ) | V_47 [ 1 ] ;
V_40 *= V_45 ;
V_40 /= 16 ;
V_40 += ( V_47 [ 2 ] >> 4 ) * V_45 / 256 ;
V_46 = ( T_4 ) V_48 * ( V_40 / 4096L ) ;
V_46 /= 128 ;
F_3 ( L_6 , V_15 , V_40 ) ;
F_3 ( L_7 , V_15 , V_46 ) ;
V_40 += V_46 ;
V_40 += 1000 ;
V_40 /= 2000 ;
V_40 *= 2000 ;
return V_40 ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_51 ;
int V_52 ;
F_3 ( L_4 , V_15 ) ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_39 ;
V_51 = F_5 ( V_2 , 0x08 ) ;
if ( F_1 ( V_2 , 0x08 , ( V_51 & ~ 0x7 ) | 0x6 ) )
return - V_16 ;
for ( V_52 = 0 ; V_52 < V_50 -> V_53 ; V_52 ++ ) {
if ( F_9 ( V_2 , 100 ) < 0 )
return - V_39 ;
if ( F_1 ( V_2 , 0x09 , V_50 -> V_8 [ V_52 ] ) )
return - V_16 ;
}
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_39 ;
return 0 ;
}
static int F_16 ( struct V_17 * V_18 ,
enum V_54 V_55 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_51 ;
F_3 ( L_4 , V_15 ) ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_39 ;
V_51 = F_5 ( V_2 , 0x08 ) ;
if ( F_1 ( V_2 , 0x08 , ( V_51 & ~ 0x7 ) | 0x2 ) )
return - V_16 ;
if ( F_1 ( V_2 , 0x09 , V_55 == V_56 ? 0x00 : 0xff ) )
return - V_16 ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_39 ;
if ( F_1 ( V_2 , 0x08 , V_51 ) )
return - V_16 ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 ,
enum V_57 V_58 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_51 ;
if ( F_11 ( V_2 , 100 ) < 0 )
return - V_39 ;
V_51 = F_5 ( V_2 , 0x08 ) ;
switch ( V_58 ) {
case V_59 :
return F_1 ( V_2 , 0x08 , V_51 | 0x3 ) ;
case V_60 :
return F_1 ( V_2 , 0x08 , ( V_51 & ~ 0x3 ) | 0x02 ) ;
default:
return - V_20 ;
}
}
static int F_18 ( struct V_17 * V_18 ,
enum V_61 V_62 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_63 ;
T_1 V_64 ;
F_3 ( L_8 , V_15 ,
V_62 == V_65 ? L_9 :
V_62 == V_66 ? L_10 : L_11 ) ;
V_63 = F_5 ( V_2 , 0x08 ) ;
V_64 = F_5 ( V_2 , 0x0c ) ;
V_64 &= 0x0f ;
V_63 = ( V_63 & 0x3f ) | ( V_2 -> V_10 -> V_67 << 6 ) ;
switch ( V_62 ) {
case V_65 :
if ( V_2 -> V_10 -> V_68 == V_69 )
V_64 |= 0x10 ;
else
V_64 |= 0x40 ;
break;
case V_66 :
V_64 |= 0x50 ;
break;
case V_70 :
V_63 = 0x00 ;
V_64 = 0x00 ;
break;
default:
return - V_20 ;
}
if ( V_2 -> V_10 -> V_71 )
V_64 &= ~ 0x10 ;
F_1 ( V_2 , 0x08 , V_63 ) ;
return F_1 ( V_2 , 0x0c , V_64 ) ;
}
static int F_19 ( struct V_17 * V_18 , unsigned long V_72 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_63 ;
T_1 V_64 ;
T_1 V_73 = 0x40 ;
T_1 V_74 = 1 ;
int V_52 ;
T_6 V_75 ;
T_6 V_76 [ 10 ] ;
V_63 = F_5 ( V_2 , 0x08 ) ;
V_64 = F_5 ( V_2 , 0x0c ) ;
V_64 &= 0x0f ;
F_1 ( V_2 , 0x08 , ( V_63 & 0x3f ) | ( V_2 -> V_10 -> V_67 << 6 ) ) ;
if ( V_2 -> V_10 -> V_68 == V_69 )
V_73 = 0x10 ;
V_72 = V_72 << 1 ;
if ( V_77 )
F_20 ( L_12 , V_15 , V_72 ) ;
V_75 = F_21 () ;
if ( V_77 )
V_76 [ 0 ] = V_75 ;
F_1 ( V_2 , 0x0c , V_64 | 0x50 ) ;
F_22 ( & V_75 , 32000 ) ;
for ( V_52 = 0 ; V_52 < 9 ; V_52 ++ ) {
if ( V_77 )
V_76 [ V_52 + 1 ] = F_21 () ;
if( ( V_72 & 0x01 ) != V_74 ) {
F_1 ( V_2 , 0x0c , V_64 | ( V_74 ? V_73 : 0x50 ) ) ;
V_74 = ( V_74 ) ? 0 : 1 ;
}
V_72 = V_72 >> 1 ;
if ( V_52 != 8 )
F_22 ( & V_75 , 8000 ) ;
}
if ( V_77 ) {
F_20 ( L_13 ,
V_15 , V_18 -> V_78 -> V_79 ) ;
for ( V_52 = 1 ; V_52 < 10 ; V_52 ++ )
F_20 ( L_14 , V_52 ,
( int ) F_23 ( V_76 [ V_52 ] , V_76 [ V_52 - 1 ] ) ) ;
}
return 0 ;
}
static int F_24 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
int V_52 ;
T_1 V_3 ;
T_1 V_51 ;
F_3 ( L_15 ) ;
F_1 ( V_2 , 0x02 , 0x30 | V_2 -> V_80 ) ;
F_10 ( 50 ) ;
for ( V_52 = 0 ; ; V_52 += 2 ) {
V_3 = V_2 -> V_10 -> V_81 [ V_52 ] ;
V_51 = V_2 -> V_10 -> V_81 [ V_52 + 1 ] ;
if ( V_3 == 0xff && V_51 == 0xff )
break;
if ( V_3 == 0x0c && V_2 -> V_10 -> V_71 )
V_51 &= ~ 0x10 ;
if ( V_3 == 0x2 )
V_2 -> V_80 = V_51 & 0xf ;
F_1 ( V_2 , V_3 , V_51 ) ;
}
return 0 ;
}
static int F_25 ( struct V_17 * V_18 ,
enum V_82 * V_83 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 signal = 0xff - F_5 ( V_2 , 0x18 ) ;
T_1 V_84 = F_5 ( V_2 , 0x1b ) ;
F_3 ( L_16 , V_15 , V_84 ) ;
* V_83 = 0 ;
if ( signal > 10 )
* V_83 |= V_85 ;
if ( V_84 & 0x80 )
* V_83 |= V_86 ;
if ( V_84 & 0x10 )
* V_83 |= V_87 ;
if ( V_84 & 0x08 )
* V_83 |= V_88 ;
if ( ( V_84 & 0x98 ) == 0x98 )
* V_83 |= V_89 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 , T_2 * V_90 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_2 -> V_91 != V_92 )
return - V_93 ;
* V_90 = F_5 ( V_2 , 0x1e ) | ( F_5 ( V_2 , 0x1d ) << 8 ) ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 , T_7 * V_94 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_4 signal = 0xffff - ( ( F_5 ( V_2 , 0x18 ) << 8 )
| F_5 ( V_2 , 0x19 ) ) ;
F_3 ( L_17 , V_15 ,
F_5 ( V_2 , 0x18 ) ,
F_5 ( V_2 , 0x19 ) , ( int ) signal ) ;
signal = signal * 5 / 4 ;
* V_94 = ( signal > 0xffff ) ? 0xffff : ( signal < 0 ) ? 0 : signal ;
return 0 ;
}
static int F_28 ( struct V_17 * V_18 , T_7 * V_95 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_4 V_96 = 0xffff - ( ( F_5 ( V_2 , 0x24 ) << 8 )
| F_5 ( V_2 , 0x25 ) ) ;
V_96 = 3 * ( V_96 - 0xa100 ) ;
* V_95 = ( V_96 > 0xffff ) ? 0xffff : ( V_96 < 0 ) ? 0 : V_96 ;
return 0 ;
}
static int F_29 ( struct V_17 * V_18 , T_2 * V_97 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_2 -> V_91 != V_98 )
return - V_93 ;
V_2 -> V_97 += F_5 ( V_2 , 0x1e ) ;
V_2 -> V_97 += ( F_5 ( V_2 , 0x1d ) << 8 ) ;
* V_97 = V_2 -> V_97 ;
return 0 ;
}
static int F_30 ( struct V_17 * V_18 )
{
struct V_99 * V_100 = & V_18 -> V_101 ;
struct V_1 * V_2 = V_18 -> V_19 ;
int V_102 = 0 ;
F_3 ( L_18 , V_15 ) ;
if ( V_2 -> V_10 -> V_103 )
V_2 -> V_10 -> V_103 ( V_18 , 0 ) ;
if ( V_100 -> V_104 == V_105 ) V_102 = 0 ;
else if ( V_100 -> V_104 == V_106 ) V_102 = 1 ;
else {
F_20 ( L_19 ) ;
return - V_20 ;
}
if ( V_2 -> V_10 -> V_107 ) V_102 = ( ~ V_102 ) & 1 ;
F_1 ( V_2 , 0x0c , ( F_5 ( V_2 , 0x0c ) & 0xfe ) | V_102 ) ;
if ( V_18 -> V_108 . V_109 . V_110 ) {
V_18 -> V_108 . V_109 . V_110 ( V_18 ) ;
if ( V_18 -> V_108 . V_111 ) V_18 -> V_108 . V_111 ( V_18 , 0 ) ;
}
F_7 ( V_2 , V_100 -> V_112 ) ;
F_12 ( V_18 , V_100 -> V_113 ) ;
F_1 ( V_2 , 0x22 , 0x00 ) ;
F_1 ( V_2 , 0x23 , 0x00 ) ;
V_2 -> V_114 = V_100 -> V_115 ;
V_2 -> V_112 = V_100 -> V_112 ;
V_2 -> V_113 = V_100 -> V_113 ;
return 0 ;
}
static int F_31 ( struct V_17 * V_18 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
T_4 V_116 ;
int V_102 ;
V_116 = ( T_4 ) ( V_117 ) ( ( F_5 ( V_2 , 0x22 ) << 8 )
| F_5 ( V_2 , 0x23 ) ) ;
V_116 *= ( V_2 -> V_10 -> V_43 >> 16 ) ;
V_116 += 500 ;
V_116 /= 1000 ;
V_100 -> V_115 += V_116 ;
V_102 = F_5 ( V_2 , 0x0c ) & 1 ;
if ( V_2 -> V_10 -> V_107 ) V_102 = ( ~ V_102 ) & 1 ;
V_100 -> V_104 = V_102 ? V_106 : V_105 ;
V_100 -> V_112 = F_8 ( V_2 ) ;
V_100 -> V_113 = F_14 ( V_2 ) ;
return 0 ;
}
static int F_32 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_1 ( V_2 , 0x02 , 0xb0 | V_2 -> V_80 ) ;
V_2 -> V_118 = 0 ;
return 0 ;
}
static int F_33 ( struct V_17 * V_18 , int V_119 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
if ( V_119 ) {
F_1 ( V_2 , 0x05 , 0xb5 ) ;
} else {
F_1 ( V_2 , 0x05 , 0x35 ) ;
}
F_34 ( 1 ) ;
return 0 ;
}
static int F_35 ( struct V_17 * V_18 , struct V_120 * V_121 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
struct V_99 * V_100 = & V_18 -> V_101 ;
V_121 -> V_122 = V_2 -> V_10 -> V_122 ;
if ( V_100 -> V_113 < 10000000 ) {
V_121 -> V_123 = V_100 -> V_113 / 32000 ;
V_121 -> V_124 = 5000 ;
} else {
V_121 -> V_123 = V_100 -> V_113 / 16000 ;
V_121 -> V_124 = V_100 -> V_113 / 2000 ;
}
return 0 ;
}
static void F_36 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
F_37 ( V_2 ) ;
}
struct V_17 * F_38 ( const struct V_125 * V_10 ,
struct V_126 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_127 ;
V_2 = F_39 ( sizeof( struct V_1 ) , V_128 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_118 = 0 ;
V_2 -> V_114 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_112 = 0 ;
V_2 -> V_91 = V_92 ;
F_1 ( V_2 , 0x02 , 0x30 ) ;
F_10 ( 200 ) ;
V_127 = F_5 ( V_2 , 0x00 ) ;
if ( V_127 != 0xa1 && V_127 != 0x80 ) goto error;
memcpy ( & V_2 -> V_129 . V_108 , & V_130 , sizeof( struct V_131 ) ) ;
V_2 -> V_129 . V_19 = V_2 ;
return & V_2 -> V_129 ;
error:
F_37 ( V_2 ) ;
return NULL ;
}
