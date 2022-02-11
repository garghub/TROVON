static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = { . V_9 = 0 , . V_10 = V_6 , . V_11 = 2 } ;
V_8 . V_12 = V_2 -> V_13 -> V_14 ;
V_5 = F_2 ( V_2 -> V_15 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1 ,
V_16 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? V_5 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_5 ;
T_1 V_6 [] = { V_3 } ;
T_1 V_17 [] = { 0 } ;
struct V_7 V_8 [] = { { . V_9 = 0 , . V_10 = V_6 , . V_11 = 1 } ,
{ . V_9 = V_18 , . V_10 = V_17 , . V_11 = 1 } } ;
V_8 [ 0 ] . V_12 = V_2 -> V_13 -> V_14 ;
V_8 [ 1 ] . V_12 = V_2 -> V_13 -> V_14 ;
V_5 = F_2 ( V_2 -> V_15 , V_8 , 2 ) ;
if ( V_5 != 2 ) {
F_3 ( L_2 , V_16 , V_3 ,
V_5 ) ;
return V_5 ;
}
return V_17 [ 0 ] ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_19 , int V_4 )
{
int V_20 ;
V_20 = F_4 ( V_2 , V_3 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = V_20 & ~ V_19 ;
V_20 |= V_4 & 0xff ;
return F_1 ( V_2 , V_3 , V_20 ) ;
}
static int F_6 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_24 = 0x80 ;
F_3 ( L_3 , V_16 ) ;
if ( V_2 -> V_13 -> V_25 )
V_24 = 0 ;
F_1 ( V_2 , 0x00 , 0x00 ) ;
F_7 ( 10 ) ;
F_1 ( V_2 , 0x01 , 0x94 ) ;
F_1 ( V_2 , 0x02 , 0x35 ) ;
F_1 ( V_2 , 0x03 , 0xe4 ) ;
F_1 ( V_2 , 0x04 , 0x43 ) ;
F_1 ( V_2 , 0x0c , 0x0c ) ;
F_1 ( V_2 , 0x1b , 0xb0 ) ;
F_1 ( V_2 , 0x20 , 0x89 ) ;
F_1 ( V_2 , 0x30 , 0x04 ) ;
F_1 ( V_2 , 0x32 , 0x00 ) ;
F_1 ( V_2 , 0x31 , 0x56 ) ;
F_1 ( V_2 , 0x55 , 0x2c ) ;
if ( V_2 -> V_13 -> V_26 == V_27 ) {
F_1 ( V_2 , 0x3a , 0x0b ) ;
F_1 ( V_2 , 0x3b , 0x01 ) ;
} else {
F_1 ( V_2 , 0x3a , 0x17 ) ;
F_1 ( V_2 , 0x3b , 0x00 ) ;
}
F_5 ( V_2 , 0x55 , 0x20 , 0x00 ) ;
F_1 ( V_2 , 0x11 , 0x81 ) ;
F_1 ( V_2 , 0x12 , 0x81 ) ;
F_1 ( V_2 , 0x19 , 0x40 ) ;
F_1 ( V_2 , 0x56 , 0x80 ) ;
F_1 ( V_2 , 0x57 , 0x08 ) ;
F_1 ( V_2 , 0x10 , 0x2a ) ;
F_1 ( V_2 , 0x58 , 0x61 ) ;
F_5 ( V_2 , 0x58 , 0x01 , 0x00 ) ;
F_1 ( V_2 , 0x05 , 0x0B ) ;
F_1 ( V_2 , 0x37 , 0x63 ) ;
F_1 ( V_2 , 0x3f , 0x0a ) ;
F_1 ( V_2 , 0x40 , 0x64 ) ;
F_1 ( V_2 , 0x41 , 0x4f ) ;
F_1 ( V_2 , 0x42 , 0x43 ) ;
F_1 ( V_2 , 0x1a , 0x11 ) ;
F_1 ( V_2 , 0x3d , 0x80 ) ;
F_1 ( V_2 , 0x36 , V_24 ) ;
F_1 ( V_2 , 0x34 , ( ( ( 1 << 19 ) * ( 22000 / 1000 ) ) / ( V_28 / 1000 ) ) ) ;
F_1 ( V_2 , 0x35 , ( ( ( 1 << 19 ) * ( 22000 / 1000 ) ) / ( V_28 / 1000 ) ) >> 8 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_29 = V_30 + F_9 ( 200 ) ;
while ( ! ( F_4 ( V_2 , 0x50 ) & 0x01 ) ) {
if( F_10 ( V_30 , V_29 ) ) {
F_11 ( L_4 , V_16 ) ;
break;
}
F_7 ( 10 ) ;
}
}
static int F_12 ( struct V_21 * V_22 ,
enum V_31 V_32 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_24 = 0x80 ;
F_3 ( L_3 , V_16 ) ;
if ( V_2 -> V_13 -> V_25 )
V_24 = 0 ;
switch ( V_32 ) {
case V_33 :
F_1 ( V_2 , 0x36 , V_24 ) ;
break;
case V_34 :
F_1 ( V_2 , 0x36 , 0x01 + V_24 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_21 * V_22 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_37 ;
T_1 V_38 ;
T_1 V_24 = 0x80 ;
F_3 ( L_3 , V_16 ) ;
if ( V_2 -> V_13 -> V_25 )
V_24 = 0 ;
if ( V_36 -> V_39 > 6 )
return - V_40 ;
V_38 = F_4 ( V_2 , 0x36 ) ;
for( V_37 = 0 ; V_37 < V_36 -> V_39 ; V_37 ++ ) {
F_1 ( V_2 , 0x48 + V_37 , V_36 -> V_8 [ V_37 ] ) ;
}
F_1 ( V_2 , 0x36 , ( 0x08 + V_24 )
| ( ( V_36 -> V_39 - 1 ) << 4 ) ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 , 0x36 , V_38 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 ,
enum V_41 V_42 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_38 = F_4 ( V_2 , 0x36 ) ;
T_1 V_24 = 0x80 ;
F_3 ( L_3 , V_16 ) ;
if ( V_2 -> V_13 -> V_25 )
V_24 = 0 ;
switch( V_42 ) {
case V_43 :
F_1 ( V_2 , 0x36 , 0x04 + V_24 ) ;
break;
case V_44 :
F_1 ( V_2 , 0x36 , 0x06 + V_24 ) ;
break;
}
F_8 ( V_2 ) ;
F_1 ( V_2 , 0x36 , V_38 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_1 V_47 = 0x80 ;
F_3 ( L_5 , V_16 , V_46 -> V_48 , V_2 -> V_13 -> V_49 ) ;
switch( V_46 -> V_48 ) {
case V_50 :
if ( V_2 -> V_13 -> V_49 )
V_47 = 0x40 ;
break;
case V_51 :
if ( ! V_2 -> V_13 -> V_49 )
V_47 = 0x40 ;
break;
case V_52 :
V_47 = 0x00 ;
break;
}
F_5 ( V_2 , 0x0c , 0xc0 , V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_1 V_53 = 0 ;
T_1 V_54 = 0 ;
T_1 V_55 = 0 ;
T_1 V_56 = 0x43 ;
T_1 V_57 = 0x43 ;
T_2 V_58 ;
T_3 V_59 ;
T_3 V_60 ;
T_3 V_61 ;
T_3 V_62 = V_46 -> V_62 ;
F_3 ( L_6 , V_16 , V_62 ) ;
if ( V_62 < ( T_3 ) ( V_28 * 0.0137 ) ) {
V_53 = 4 ;
V_54 = 1 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.0208 ) ) {
V_53 = 4 ;
V_54 = 0 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.0270 ) ) {
V_53 = 3 ;
V_54 = 1 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.0416 ) ) {
V_53 = 3 ;
V_54 = 0 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.0550 ) ) {
V_53 = 2 ;
V_54 = 1 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.0833 ) ) {
V_53 = 2 ;
V_54 = 0 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.1100 ) ) {
V_53 = 1 ;
V_54 = 1 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.1666 ) ) {
V_53 = 1 ;
V_54 = 0 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.2200 ) ) {
V_53 = 0 ;
V_54 = 1 ;
} else if ( V_62 < ( T_3 ) ( V_28 * 0.3333 ) ) {
V_53 = 0 ;
V_54 = 0 ;
} else {
V_56 = 0x63 ;
V_57 = 0x4f ;
V_55 = 1 ;
}
V_58 = ( 1ULL << 21 ) * ( ( T_2 ) V_62 / 1000ULL ) * ( 1ULL << V_53 ) ;
V_58 += ( ( V_28 / 1000ULL ) - 1ULL ) ;
F_17 ( V_58 , ( V_28 / 1000ULL ) ) ;
V_60 = V_58 & 0xfffff ;
V_59 = ( 1 << V_53 ) * ( V_62 / 1000 ) ;
V_61 = ( ( 32 * ( V_28 / 1000 ) ) + ( V_59 - 1 ) ) / V_59 ;
F_1 ( V_2 , 0x21 , ( V_54 << 7 ) | V_53 ) ;
F_5 ( V_2 , 0x20 , 0x08 , V_55 << 3 ) ;
F_1 ( V_2 , 0x06 , V_60 ) ;
F_1 ( V_2 , 0x07 , V_60 >> 8 ) ;
F_1 ( V_2 , 0x08 , V_60 >> 16 ) ;
F_1 ( V_2 , 0x09 , V_61 ) ;
F_1 ( V_2 , 0x37 , V_56 ) ;
F_1 ( V_2 , 0x42 , V_57 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_1 V_63 ;
F_3 ( L_6 , V_16 , V_46 -> V_64 ) ;
switch ( V_46 -> V_64 ) {
case V_65 :
V_63 = 0x00 ;
break;
case V_66 :
V_63 = 0x01 ;
break;
case V_67 :
V_63 = 0x02 ;
break;
case V_68 :
V_63 = 0x03 ;
break;
case V_69 :
V_63 = 0x04 ;
break;
case V_70 :
V_63 = 0x05 ;
break;
case V_71 :
V_63 = 0x06 ;
break;
case V_72 :
V_63 = 0x07 ;
break;
case V_73 :
V_63 = 0x08 ;
break;
default:
return - 1 ;
}
F_1 ( V_2 , 0x0d , V_63 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_45 * V_46 = & V_22 -> V_74 ;
struct V_1 * V_2 = V_22 -> V_23 ;
int V_5 ;
T_3 V_75 = 0 ;
int V_76 ;
F_3 ( L_3 , V_16 ) ;
F_1 ( V_2 , 0x02 , 0x35 ) ;
V_2 -> V_77 = false ;
if ( V_22 -> V_78 . V_79 . V_80 ) {
V_22 -> V_78 . V_79 . V_80 ( V_22 ) ;
if ( V_22 -> V_78 . V_81 )
V_22 -> V_78 . V_81 ( V_22 , 0 ) ;
if ( V_22 -> V_78 . V_79 . V_82 )
V_22 -> V_78 . V_79 . V_82 ( V_22 , & V_75 ) ;
if ( V_22 -> V_78 . V_81 )
V_22 -> V_78 . V_81 ( V_22 , 0 ) ;
}
V_76 = V_46 -> V_83 - V_75 ;
V_76 = ( ( 1 << 16 ) * V_76 ) / ( V_28 / 1000 ) ;
F_1 ( V_2 , 0x3d , 0x80 | ( ( V_76 >> 8 ) & 0x7f ) ) ;
F_1 ( V_2 , 0x3e , V_76 ) ;
if ( ( V_5 = F_15 ( V_2 , V_46 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_16 ( V_2 , V_46 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_18 ( V_2 , V_46 ) ) < 0 )
return V_5 ;
F_5 ( V_2 , 0x10 , 0x40 , 0x40 ) ;
F_5 ( V_2 , 0x00 , 0x01 , 0x00 ) ;
V_2 -> V_62 = V_46 -> V_62 ;
V_2 -> V_83 = V_46 -> V_83 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_20 ;
int V_59 ;
T_2 V_84 ;
F_3 ( L_3 , V_16 ) ;
if ( V_46 -> V_62 < 500000 )
return - V_40 ;
V_84 = ( ( T_2 ) F_4 ( V_2 , 0x52 )
| ( F_4 ( V_2 , 0x51 ) << 8 ) ) ;
if ( V_84 & 0x8000 )
V_84 |= 0xffffffffffff0000ULL ;
V_84 = ( V_84 * ( V_28 / 1000ULL ) ) ;
F_17 ( V_84 , ( 1ULL << 15 ) * ( 1ULL << 1 ) ) ;
V_46 -> V_83 = ( int ) V_2 -> V_83 + ( int ) V_84 ;
V_20 = F_4 ( V_2 , 0x0c ) ;
if ( V_20 & 0x80 ) {
switch( V_20 & 0x40 ) {
case 0x00 :
V_46 -> V_48 = V_50 ;
if ( V_2 -> V_13 -> V_49 )
V_46 -> V_48 = V_51 ;
break;
default:
V_46 -> V_48 = V_51 ;
if ( V_2 -> V_13 -> V_49 )
V_46 -> V_48 = V_50 ;
break;
}
} else {
F_4 ( V_2 , 0x0f ) ;
switch( V_20 & 0x02 ) {
case 0x00 :
V_46 -> V_48 = V_50 ;
if ( V_2 -> V_13 -> V_49 )
V_46 -> V_48 = V_51 ;
break;
default:
V_46 -> V_48 = V_51 ;
if ( V_2 -> V_13 -> V_49 )
V_46 -> V_48 = V_50 ;
break;
}
}
V_59 = F_4 ( V_2 , 0x1d ) ;
if ( V_59 & 0x80 )
V_59 |= 0xffffff00 ;
V_59 = ( V_59 * 480 * ( 1 << 1 ) ) / 128 ;
V_59 = ( ( V_2 -> V_62 / 1000 ) * V_59 ) / ( 1000000 / 1000 ) ;
V_46 -> V_62 = V_2 -> V_62 + V_59 ;
V_20 = ( F_4 ( V_2 , 0x0d ) & 0x70 ) >> 4 ;
switch( V_20 ) {
case 0x00 :
V_46 -> V_64 = V_65 ;
break;
case 0x01 :
V_46 -> V_64 = V_66 ;
break;
case 0x02 :
V_46 -> V_64 = V_67 ;
break;
case 0x03 :
V_46 -> V_64 = V_68 ;
break;
case 0x04 :
V_46 -> V_64 = V_69 ;
break;
case 0x05 :
V_46 -> V_64 = V_70 ;
break;
case 0x06 :
V_46 -> V_64 = V_71 ;
break;
case 0x07 :
V_46 -> V_64 = V_72 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_21 * V_22 ,
enum V_85 * V_85 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_20 ;
F_3 ( L_3 , V_16 ) ;
V_20 = F_4 ( V_2 , 0x0e ) ;
* V_85 = 0 ;
if ( V_20 & 0x01 )
* V_85 |= V_86 ;
if ( V_20 & 0x02 )
* V_85 |= V_87 ;
if ( V_20 & 0x04 )
* V_85 |= V_88 ;
if ( V_20 & 0x08 )
* V_85 |= V_89 ;
if ( V_20 & 0x10 ) {
* V_85 |= V_90 ;
if ( ! V_2 -> V_77 ) {
V_2 -> V_77 = true ;
F_1 ( V_2 , 0x02 , 0x00 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_21 * V_22 , T_4 * signal )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_91 ;
F_3 ( L_3 , V_16 ) ;
V_91 = 0xff - F_4 ( V_2 , 0x43 ) ;
* signal = ( V_91 << 8 ) | V_91 ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 , T_4 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_93 ;
F_3 ( L_3 , V_16 ) ;
V_93 = 0xff - F_4 ( V_2 , 0x1c ) ;
* V_92 = ( V_93 << 8 ) | V_93 ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 , T_3 * V_94 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
* V_94 = F_4 ( V_2 , 0x18 ) & 0x7f ;
F_1 ( V_2 , 0x18 , 0x00 ) ;
F_1 ( V_2 , 0x18 , 0x80 ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 , T_3 * V_95 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
* V_95 = 0 ;
* V_95 |= F_4 ( V_2 , 0x15 ) ;
* V_95 |= F_4 ( V_2 , 0x16 ) << 8 ;
* V_95 |= ( F_4 ( V_2 , 0x17 ) & 0xf ) << 16 ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
F_5 ( V_2 , 0x00 , 0x08 , 0x08 ) ;
return 0 ;
}
static int F_27 ( struct V_21 * V_22 , int V_96 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
if ( V_96 ) {
F_5 ( V_2 , 0x00 , 0x10 , 0x10 ) ;
} else {
F_5 ( V_2 , 0x00 , 0x10 , 0x00 ) ;
}
return 0 ;
}
static int F_28 ( struct V_21 * V_22 , struct V_97 * V_98 )
{
struct V_45 * V_99 = & V_22 -> V_74 ;
if ( V_99 -> V_62 > 20000000 ) {
V_98 -> V_100 = 50 ;
V_98 -> V_101 = 2000 ;
V_98 -> V_102 = 8000 ;
} else if ( V_99 -> V_62 > 12000000 ) {
V_98 -> V_100 = 100 ;
V_98 -> V_101 = 1500 ;
V_98 -> V_102 = 9000 ;
} else if ( V_99 -> V_62 > 8000000 ) {
V_98 -> V_100 = 100 ;
V_98 -> V_101 = 1000 ;
V_98 -> V_102 = 8000 ;
} else if ( V_99 -> V_62 > 4000000 ) {
V_98 -> V_100 = 100 ;
V_98 -> V_101 = 500 ;
V_98 -> V_102 = 7000 ;
} else if ( V_99 -> V_62 > 2000000 ) {
V_98 -> V_100 = 200 ;
V_98 -> V_101 = V_99 -> V_62 / 8000 ;
V_98 -> V_102 = 14 * V_98 -> V_101 ;
} else {
V_98 -> V_100 = 200 ;
V_98 -> V_101 = V_99 -> V_62 / 8000 ;
V_98 -> V_102 = 18 * V_98 -> V_101 ;
}
return 0 ;
}
static void F_29 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_26 ( V_22 ) ;
F_30 ( V_2 ) ;
}
struct V_21 * F_31 ( const struct V_103 * V_13 ,
struct V_104 * V_15 )
{
struct V_1 * V_2 ;
F_3 ( L_3 , V_16 ) ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_105 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
if ( F_4 ( V_2 , 0x1e ) != 0xe1 ) {
F_30 ( V_2 ) ;
return NULL ;
}
memcpy ( & V_2 -> V_106 . V_78 , & V_107 , sizeof( struct V_108 ) ) ;
V_2 -> V_106 . V_23 = V_2 ;
return & V_2 -> V_106 ;
}
