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
static int F_12 ( struct V_21 * V_22 , T_2 V_31 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_24 = 0x80 ;
F_3 ( L_3 , V_16 ) ;
if ( V_2 -> V_13 -> V_25 )
V_24 = 0 ;
switch ( V_31 ) {
case V_32 :
F_1 ( V_2 , 0x36 , V_24 ) ;
break;
case V_33 :
F_1 ( V_2 , 0x36 , 0x01 + V_24 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_21 * V_22 ,
struct V_34 * V_35 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
int V_36 ;
T_1 V_37 ;
T_1 V_24 = 0x80 ;
F_3 ( L_3 , V_16 ) ;
if ( V_2 -> V_13 -> V_25 )
V_24 = 0 ;
if ( V_35 -> V_38 > 6 )
return - V_39 ;
V_37 = F_4 ( V_2 , 0x36 ) ;
for( V_36 = 0 ; V_36 < V_35 -> V_38 ; V_36 ++ ) {
F_1 ( V_2 , 0x48 + V_36 , V_35 -> V_8 [ V_36 ] ) ;
}
F_1 ( V_2 , 0x36 , ( 0x08 + V_24 )
| ( ( V_35 -> V_38 - 1 ) << 4 ) ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 , 0x36 , V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_21 * V_22 , T_3 V_40 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_37 = F_4 ( V_2 , 0x36 ) ;
T_1 V_24 = 0x80 ;
F_3 ( L_3 , V_16 ) ;
if ( V_2 -> V_13 -> V_25 )
V_24 = 0 ;
switch( V_40 ) {
case V_41 :
F_1 ( V_2 , 0x36 , 0x04 + V_24 ) ;
break;
case V_42 :
F_1 ( V_2 , 0x36 , 0x06 + V_24 ) ;
break;
}
F_8 ( V_2 ) ;
F_1 ( V_2 , 0x36 , V_37 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_1 V_45 = 0x80 ;
F_3 ( L_5 , V_16 , V_44 -> V_46 , V_2 -> V_13 -> V_47 ) ;
switch( V_44 -> V_46 ) {
case V_48 :
if ( V_2 -> V_13 -> V_47 )
V_45 = 0x40 ;
break;
case V_49 :
if ( ! V_2 -> V_13 -> V_47 )
V_45 = 0x40 ;
break;
case V_50 :
V_45 = 0x00 ;
break;
}
F_5 ( V_2 , 0x0c , 0xc0 , V_45 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_1 V_51 = 0 ;
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 = 0x43 ;
T_1 V_55 = 0x43 ;
T_4 V_56 ;
T_5 V_57 ;
T_5 V_58 ;
T_5 V_59 ;
T_5 V_60 = V_44 -> V_60 ;
F_3 ( L_6 , V_16 , V_60 ) ;
if ( V_60 < ( T_5 ) ( V_28 * 0.0137 ) ) {
V_51 = 4 ;
V_52 = 1 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.0208 ) ) {
V_51 = 4 ;
V_52 = 0 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.0270 ) ) {
V_51 = 3 ;
V_52 = 1 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.0416 ) ) {
V_51 = 3 ;
V_52 = 0 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.0550 ) ) {
V_51 = 2 ;
V_52 = 1 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.0833 ) ) {
V_51 = 2 ;
V_52 = 0 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.1100 ) ) {
V_51 = 1 ;
V_52 = 1 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.1666 ) ) {
V_51 = 1 ;
V_52 = 0 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.2200 ) ) {
V_51 = 0 ;
V_52 = 1 ;
} else if ( V_60 < ( T_5 ) ( V_28 * 0.3333 ) ) {
V_51 = 0 ;
V_52 = 0 ;
} else {
V_54 = 0x63 ;
V_55 = 0x4f ;
V_53 = 1 ;
}
V_56 = ( 1ULL << 21 ) * ( ( T_4 ) V_60 / 1000ULL ) * ( 1ULL << V_51 ) ;
V_56 += ( ( V_28 / 1000ULL ) - 1ULL ) ;
F_17 ( V_56 , ( V_28 / 1000ULL ) ) ;
V_58 = V_56 & 0xfffff ;
V_57 = ( 1 << V_51 ) * ( V_60 / 1000 ) ;
V_59 = ( ( 32 * ( V_28 / 1000 ) ) + ( V_57 - 1 ) ) / V_57 ;
F_1 ( V_2 , 0x21 , ( V_52 << 7 ) | V_51 ) ;
F_5 ( V_2 , 0x20 , 0x08 , V_53 << 3 ) ;
F_1 ( V_2 , 0x06 , V_58 ) ;
F_1 ( V_2 , 0x07 , V_58 >> 8 ) ;
F_1 ( V_2 , 0x08 , V_58 >> 16 ) ;
F_1 ( V_2 , 0x09 , V_59 ) ;
F_1 ( V_2 , 0x37 , V_54 ) ;
F_1 ( V_2 , 0x42 , V_55 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
T_1 V_61 ;
F_3 ( L_6 , V_16 , V_44 -> V_62 ) ;
switch ( V_44 -> V_62 ) {
case V_63 :
V_61 = 0x00 ;
break;
case V_64 :
V_61 = 0x01 ;
break;
case V_65 :
V_61 = 0x02 ;
break;
case V_66 :
V_61 = 0x03 ;
break;
case V_67 :
V_61 = 0x04 ;
break;
case V_68 :
V_61 = 0x05 ;
break;
case V_69 :
V_61 = 0x06 ;
break;
case V_70 :
V_61 = 0x07 ;
break;
case V_71 :
V_61 = 0x08 ;
break;
default:
return - 1 ;
}
F_1 ( V_2 , 0x0d , V_61 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_43 * V_44 = & V_22 -> V_72 ;
struct V_1 * V_2 = V_22 -> V_23 ;
int V_5 ;
T_5 V_73 = 0 ;
int V_74 ;
F_3 ( L_3 , V_16 ) ;
F_1 ( V_2 , 0x02 , 0x35 ) ;
V_2 -> V_75 = false ;
if ( V_22 -> V_76 . V_77 . V_78 ) {
V_22 -> V_76 . V_77 . V_78 ( V_22 ) ;
if ( V_22 -> V_76 . V_79 )
V_22 -> V_76 . V_79 ( V_22 , 0 ) ;
if ( V_22 -> V_76 . V_77 . V_80 )
V_22 -> V_76 . V_77 . V_80 ( V_22 , & V_73 ) ;
if ( V_22 -> V_76 . V_79 )
V_22 -> V_76 . V_79 ( V_22 , 0 ) ;
}
V_74 = V_44 -> V_81 - V_73 ;
V_74 = ( ( 1 << 16 ) * V_74 ) / ( V_28 / 1000 ) ;
F_1 ( V_2 , 0x3d , 0x80 | ( ( V_74 >> 8 ) & 0x7f ) ) ;
F_1 ( V_2 , 0x3e , V_74 ) ;
if ( ( V_5 = F_15 ( V_2 , V_44 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_16 ( V_2 , V_44 ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_18 ( V_2 , V_44 ) ) < 0 )
return V_5 ;
F_5 ( V_2 , 0x10 , 0x40 , 0x40 ) ;
F_5 ( V_2 , 0x00 , 0x01 , 0x00 ) ;
V_2 -> V_60 = V_44 -> V_60 ;
V_2 -> V_81 = V_44 -> V_81 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 )
{
struct V_43 * V_44 = & V_22 -> V_72 ;
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_20 ;
int V_57 ;
T_4 V_82 ;
F_3 ( L_3 , V_16 ) ;
if ( V_44 -> V_60 < 500000 )
return - V_39 ;
V_82 = F_4 ( V_2 , 0x52 ) ;
V_82 |= ( F_4 ( V_2 , 0x51 ) << 8 ) ;
if ( V_82 & 0x8000 )
V_82 |= 0xffffffffffff0000ULL ;
V_82 = ( V_82 * ( V_28 / 1000ULL ) ) ;
F_17 ( V_82 , ( 1ULL << 15 ) * ( 1ULL << 1 ) ) ;
V_44 -> V_81 = ( int ) V_2 -> V_81 + ( int ) V_82 ;
V_20 = F_4 ( V_2 , 0x0c ) ;
if ( V_20 & 0x80 ) {
switch( V_20 & 0x40 ) {
case 0x00 :
V_44 -> V_46 = V_48 ;
if ( V_2 -> V_13 -> V_47 )
V_44 -> V_46 = V_49 ;
break;
default:
V_44 -> V_46 = V_49 ;
if ( V_2 -> V_13 -> V_47 )
V_44 -> V_46 = V_48 ;
break;
}
} else {
F_4 ( V_2 , 0x0f ) ;
switch( V_20 & 0x02 ) {
case 0x00 :
V_44 -> V_46 = V_48 ;
if ( V_2 -> V_13 -> V_47 )
V_44 -> V_46 = V_49 ;
break;
default:
V_44 -> V_46 = V_49 ;
if ( V_2 -> V_13 -> V_47 )
V_44 -> V_46 = V_48 ;
break;
}
}
V_57 = F_4 ( V_2 , 0x1d ) ;
if ( V_57 & 0x80 )
V_57 |= 0xffffff00 ;
V_57 = ( V_57 * 480 * ( 1 << 1 ) ) / 128 ;
V_57 = ( ( V_2 -> V_60 / 1000 ) * V_57 ) / ( 1000000 / 1000 ) ;
V_44 -> V_60 = V_2 -> V_60 + V_57 ;
V_20 = ( F_4 ( V_2 , 0x0d ) & 0x70 ) >> 4 ;
switch( V_20 ) {
case 0x00 :
V_44 -> V_62 = V_63 ;
break;
case 0x01 :
V_44 -> V_62 = V_64 ;
break;
case 0x02 :
V_44 -> V_62 = V_65 ;
break;
case 0x03 :
V_44 -> V_62 = V_66 ;
break;
case 0x04 :
V_44 -> V_62 = V_67 ;
break;
case 0x05 :
V_44 -> V_62 = V_68 ;
break;
case 0x06 :
V_44 -> V_62 = V_69 ;
break;
case 0x07 :
V_44 -> V_62 = V_70 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_21 * V_22 , T_6 * V_83 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_20 ;
F_3 ( L_3 , V_16 ) ;
V_20 = F_4 ( V_2 , 0x0e ) ;
* V_83 = 0 ;
if ( V_20 & 0x01 )
* V_83 |= V_84 ;
if ( V_20 & 0x02 )
* V_83 |= V_85 ;
if ( V_20 & 0x04 )
* V_83 |= V_86 ;
if ( V_20 & 0x08 )
* V_83 |= V_87 ;
if ( V_20 & 0x10 ) {
* V_83 |= V_88 ;
if ( ! V_2 -> V_75 ) {
V_2 -> V_75 = true ;
F_1 ( V_2 , 0x02 , 0x00 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_21 * V_22 , T_7 * signal )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_89 ;
F_3 ( L_3 , V_16 ) ;
V_89 = 0xff - F_4 ( V_2 , 0x43 ) ;
* signal = ( V_89 << 8 ) | V_89 ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 , T_7 * V_90 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
T_1 V_91 ;
F_3 ( L_3 , V_16 ) ;
V_91 = 0xff - F_4 ( V_2 , 0x1c ) ;
* V_90 = ( V_91 << 8 ) | V_91 ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 , T_5 * V_92 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
* V_92 = F_4 ( V_2 , 0x18 ) & 0x7f ;
F_1 ( V_2 , 0x18 , 0x00 ) ;
F_1 ( V_2 , 0x18 , 0x80 ) ;
return 0 ;
}
static int F_25 ( struct V_21 * V_22 , T_5 * V_93 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
* V_93 = 0 ;
* V_93 |= F_4 ( V_2 , 0x15 ) ;
* V_93 |= F_4 ( V_2 , 0x16 ) << 8 ;
* V_93 |= ( F_4 ( V_2 , 0x17 ) & 0xf ) << 16 ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
F_5 ( V_2 , 0x00 , 0x08 , 0x08 ) ;
return 0 ;
}
static int F_27 ( struct V_21 * V_22 , int V_94 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_3 ( L_3 , V_16 ) ;
if ( V_94 ) {
F_5 ( V_2 , 0x00 , 0x10 , 0x10 ) ;
} else {
F_5 ( V_2 , 0x00 , 0x10 , 0x00 ) ;
}
return 0 ;
}
static int F_28 ( struct V_21 * V_22 , struct V_95 * V_96 )
{
struct V_43 * V_97 = & V_22 -> V_72 ;
if ( V_97 -> V_60 > 20000000 ) {
V_96 -> V_98 = 50 ;
V_96 -> V_99 = 2000 ;
V_96 -> V_100 = 8000 ;
} else if ( V_97 -> V_60 > 12000000 ) {
V_96 -> V_98 = 100 ;
V_96 -> V_99 = 1500 ;
V_96 -> V_100 = 9000 ;
} else if ( V_97 -> V_60 > 8000000 ) {
V_96 -> V_98 = 100 ;
V_96 -> V_99 = 1000 ;
V_96 -> V_100 = 8000 ;
} else if ( V_97 -> V_60 > 4000000 ) {
V_96 -> V_98 = 100 ;
V_96 -> V_99 = 500 ;
V_96 -> V_100 = 7000 ;
} else if ( V_97 -> V_60 > 2000000 ) {
V_96 -> V_98 = 200 ;
V_96 -> V_99 = V_97 -> V_60 / 8000 ;
V_96 -> V_100 = 14 * V_96 -> V_99 ;
} else {
V_96 -> V_98 = 200 ;
V_96 -> V_99 = V_97 -> V_60 / 8000 ;
V_96 -> V_100 = 18 * V_96 -> V_99 ;
}
return 0 ;
}
static void F_29 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
F_26 ( V_22 ) ;
F_30 ( V_2 ) ;
}
struct V_21 * F_31 ( const struct V_101 * V_13 ,
struct V_102 * V_15 )
{
struct V_1 * V_2 ;
F_3 ( L_3 , V_16 ) ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_103 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_13 = V_13 ;
V_2 -> V_15 = V_15 ;
if ( F_4 ( V_2 , 0x1e ) != 0xe1 ) {
F_30 ( V_2 ) ;
return NULL ;
}
memcpy ( & V_2 -> V_104 . V_76 , & V_105 , sizeof( struct V_106 ) ) ;
V_2 -> V_104 . V_23 = V_2 ;
return & V_2 -> V_104 ;
}
