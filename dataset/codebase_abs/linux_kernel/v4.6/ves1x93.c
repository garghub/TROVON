static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [] = { 0x00 , V_3 , V_4 } ;
struct V_6 V_7 = { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_5 , . V_12 = 3 } ;
int V_13 ;
if ( ( V_13 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ) != 1 ) {
F_3 ( L_1 , V_15 , V_13 , V_3 , V_4 ) ;
return - V_16 ;
}
return 0 ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_17 ;
T_1 V_18 [] = { 0x00 , V_3 } ;
T_1 V_19 [] = { 0 } ;
struct V_6 V_7 [] = { { . V_8 = V_2 -> V_9 -> V_10 , . V_11 = 0 , . V_5 = V_18 , . V_12 = 2 } ,
{ . V_8 = V_2 -> V_9 -> V_10 , . V_11 = V_20 , . V_5 = V_19 , . V_12 = 1 } } ;
V_17 = F_2 ( V_2 -> V_14 , V_7 , 2 ) ;
if ( V_17 != 2 ) return V_17 ;
return V_19 [ 0 ] ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( 10 ) ;
F_1 ( V_2 , 0 , V_2 -> V_21 [ 0 ] & 0xfe ) ;
F_1 ( V_2 , 0 , V_2 -> V_21 [ 0 ] ) ;
F_6 ( 50 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_22 V_23 )
{
T_1 V_24 ;
switch ( V_23 ) {
case V_25 :
V_24 = 0xc0 ;
break;
case V_26 :
V_24 = 0x80 ;
break;
case V_27 :
V_24 = 0x00 ;
break;
default:
return - V_28 ;
}
return F_1 ( V_2 , 0x0c , ( V_2 -> V_21 [ 0x0c ] & 0x3f ) | V_24 ) ;
}
static int F_8 ( struct V_1 * V_2 , enum V_29 V_30 )
{
if ( V_30 == V_31 )
return F_1 ( V_2 , 0x0d , 0x08 ) ;
else if ( V_30 < V_32 || V_30 > V_33 )
return - V_28 ;
else
return F_1 ( V_2 , 0x0d , V_30 - V_32 ) ;
}
static enum V_29 F_9 ( struct V_1 * V_2 )
{
return V_32 + ( ( F_4 ( V_2 , 0x0d ) >> 4 ) & 0x7 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_34 )
{
T_2 V_35 ;
T_2 V_36 ;
T_1 V_37 , V_38 , V_39 , V_40 ;
T_2 V_41 ;
T_2 V_42 ;
T_2 V_43 ;
F_3 ( L_2 , V_15 , ( unsigned int ) V_34 ) ;
if ( V_34 > V_2 -> V_9 -> V_44 / 2 )
V_34 = V_2 -> V_9 -> V_44 / 2 ;
if ( V_34 < 500000 )
V_34 = 500000 ;
#define F_11 (1UL<<26)
V_43 = ( V_2 -> V_9 -> V_44 + 6000 ) >> 4 ;
V_42 = V_34 << 6 ;
V_36 = V_42 / V_43 ;
V_42 = ( V_42 % V_43 ) << 8 ;
V_36 = ( V_36 << 8 ) + V_42 / V_43 ;
V_42 = ( V_42 % V_43 ) << 8 ;
V_36 = ( V_36 << 8 ) + V_42 / V_43 ;
V_39 = 0xff ;
if ( V_36 < F_11 / 3 ) V_39 = 0 ;
if ( V_36 < ( F_11 * 11 ) / 50 ) V_39 = 1 ;
if ( V_36 < F_11 / 6 ) V_39 = 2 ;
if ( V_36 < F_11 / 9 ) V_39 = 3 ;
if ( V_36 < F_11 / 12 ) V_39 = 4 ;
if ( V_36 < ( F_11 * 11 ) / 200 ) V_39 = 5 ;
if ( V_36 < F_11 / 24 ) V_39 = 6 ;
if ( V_36 < ( F_11 * 27 ) / 1000 ) V_39 = 7 ;
if ( V_36 < F_11 / 48 ) V_39 = 8 ;
if ( V_36 < ( F_11 * 137 ) / 10000 ) V_39 = 9 ;
if ( V_39 == 0xff ) {
V_37 = 0x89 ;
V_38 = 0x80 ;
V_39 = 0 ;
} else {
V_37 = 0x81 ;
V_38 = 0x88 | ( V_39 >> 1 ) | ( ( V_39 & 0x01 ) << 5 ) ;
}
V_35 = ( ( ( V_36 << ( V_39 >> 1 ) ) >> 4 ) + 1 ) >> 1 ;
V_41 = ( ( ( V_43 << 8 ) / ( ( V_34 << ( V_39 >> 1 ) ) >> 2 ) ) + 1 ) >> 1 ;
F_3 ( L_3 , V_39 ) ;
F_3 ( L_4 , ( unsigned int ) V_36 ) ;
F_3 ( L_5 , ( unsigned int ) V_35 ) ;
F_3 ( L_6 , ( unsigned int ) V_41 ) ;
if ( V_41 > 0xff )
V_41 = 0xff ;
F_1 ( V_2 , 0x06 , 0xff & V_35 ) ;
F_1 ( V_2 , 0x07 , 0xff & ( V_35 >> 8 ) ) ;
F_1 ( V_2 , 0x08 , 0x0f & ( V_35 >> 16 ) ) ;
F_1 ( V_2 , 0x09 , V_41 ) ;
F_1 ( V_2 , 0x20 , V_37 ) ;
F_1 ( V_2 , 0x21 , V_38 ) ;
V_40 = V_2 -> V_21 [ 0x05 ] ;
if ( V_2 -> V_9 -> V_45 )
V_40 |= 0x20 ;
if ( V_34 < 6000000 )
V_40 |= 0x80 ;
else
V_40 &= ~ 0x80 ;
F_1 ( V_2 , 0x05 , V_40 ) ;
if ( V_2 -> V_46 != V_47 )
F_5 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_51 ;
int V_24 ;
F_3 ( L_7 , V_15 ) ;
for ( V_51 = 0 ; V_51 < V_2 -> V_52 ; V_51 ++ ) {
if ( V_2 -> V_53 [ V_51 ] ) {
V_24 = V_2 -> V_21 [ V_51 ] ;
if ( V_2 -> V_9 -> V_45 && ( V_51 == 0x05 ) ) V_24 |= 0x20 ;
F_1 ( V_2 , V_51 , V_24 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_48 * V_49 ,
enum V_54 V_55 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
switch ( V_55 ) {
case V_56 :
return F_1 ( V_2 , 0x1f , 0x20 ) ;
case V_57 :
return F_1 ( V_2 , 0x1f , 0x30 ) ;
case V_58 :
return F_1 ( V_2 , 0x1f , 0x00 ) ;
default:
return - V_28 ;
}
}
static int F_14 ( struct V_48 * V_49 ,
enum V_59 * V_60 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
T_1 V_61 = F_4 ( V_2 , 0x0e ) ;
int V_62 = 10 ;
while ( ( V_61 & 0x03 ) != 0x03 && ( V_61 & 0x0c ) && V_62 -- ) {
F_6 ( 10 ) ;
V_61 = F_4 ( V_2 , 0x0e ) ;
}
* V_60 = 0 ;
if ( V_61 & 1 )
* V_60 |= V_63 ;
if ( V_61 & 2 )
* V_60 |= V_64 ;
if ( V_61 & 4 )
* V_60 |= V_65 ;
if ( V_61 & 8 )
* V_60 |= V_66 ;
if ( ( V_61 & 0x1f ) == 0x1f )
* V_60 |= V_67 ;
return 0 ;
}
static int F_15 ( struct V_48 * V_49 , T_2 * V_68 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
* V_68 = F_4 ( V_2 , 0x15 ) ;
* V_68 |= ( F_4 ( V_2 , 0x16 ) << 8 ) ;
* V_68 |= ( ( F_4 ( V_2 , 0x17 ) & 0x0F ) << 16 ) ;
* V_68 *= 10 ;
return 0 ;
}
static int F_16 ( struct V_48 * V_49 , T_3 * V_69 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
T_1 signal = ~ F_4 ( V_2 , 0x0b ) ;
* V_69 = ( signal << 8 ) | signal ;
return 0 ;
}
static int F_17 ( struct V_48 * V_49 , T_3 * V_70 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
T_1 V_71 = ~ F_4 ( V_2 , 0x1c ) ;
* V_70 = ( V_71 << 8 ) | V_71 ;
return 0 ;
}
static int F_18 ( struct V_48 * V_49 , T_2 * V_72 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
* V_72 = F_4 ( V_2 , 0x18 ) & 0x7f ;
if ( * V_72 == 0x7f )
* V_72 = 0xffffffff ;
F_1 ( V_2 , 0x18 , 0x00 ) ;
F_1 ( V_2 , 0x18 , 0x80 ) ;
return 0 ;
}
static int F_19 ( struct V_48 * V_49 )
{
struct V_73 * V_74 = & V_49 -> V_75 ;
struct V_1 * V_2 = V_49 -> V_50 ;
if ( V_49 -> V_76 . V_77 . V_78 ) {
V_49 -> V_76 . V_77 . V_78 ( V_49 ) ;
if ( V_49 -> V_76 . V_79 ) V_49 -> V_76 . V_79 ( V_49 , 0 ) ;
}
F_7 ( V_2 , V_74 -> V_23 ) ;
F_8 ( V_2 , V_74 -> V_80 ) ;
F_10 ( V_2 , V_74 -> V_81 ) ;
V_2 -> V_23 = V_74 -> V_23 ;
V_2 -> V_82 = V_74 -> V_82 ;
return 0 ;
}
static int F_20 ( struct V_48 * V_49 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
int V_83 ;
V_83 = ( ( int ) ( ( char ) ( F_4 ( V_2 , 0x0a ) << 1 ) ) ) / 2 ;
V_83 = ( V_83 * ( int ) ( V_74 -> V_81 / 1000 / 8 ) ) / 16 ;
V_74 -> V_82 = V_2 -> V_82 - V_83 ;
if ( V_2 -> V_23 == V_27 )
V_74 -> V_23 = ( F_4 ( V_2 , 0x0f ) & 2 ) ?
V_25 : V_26 ;
V_74 -> V_80 = F_9 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
return F_1 ( V_2 , 0x00 , 0x08 ) ;
}
static void F_22 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_48 * V_49 , int V_84 )
{
struct V_1 * V_2 = V_49 -> V_50 ;
if ( V_84 ) {
return F_1 ( V_2 , 0x00 , 0x11 ) ;
} else {
return F_1 ( V_2 , 0x00 , 0x01 ) ;
}
}
struct V_48 * F_25 ( const struct V_85 * V_9 ,
struct V_86 * V_14 )
{
struct V_1 * V_2 = NULL ;
T_1 V_87 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_88 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_23 = V_25 ;
V_87 = F_4 ( V_2 , 0x1e ) ;
switch ( V_87 ) {
case 0xdc :
F_27 ( L_8 ) ;
V_2 -> V_46 = V_89 ;
V_2 -> V_21 = V_90 ;
V_2 -> V_53 = V_91 ;
V_2 -> V_52 = sizeof( V_90 ) ;
break;
case 0xdd :
F_27 ( L_9 ) ;
V_2 -> V_46 = V_89 ;
V_2 -> V_21 = V_90 ;
V_2 -> V_53 = V_91 ;
V_2 -> V_52 = sizeof( V_90 ) ;
break;
case 0xde :
F_27 ( L_10 ) ;
V_2 -> V_46 = V_47 ;
V_2 -> V_21 = V_92 ;
V_2 -> V_53 = V_93 ;
V_2 -> V_52 = sizeof( V_92 ) ;
break;
default:
goto error;
}
memcpy ( & V_2 -> V_94 . V_76 , & V_95 , sizeof( struct V_96 ) ) ;
V_2 -> V_94 . V_50 = V_2 ;
return & V_2 -> V_94 ;
error:
F_23 ( V_2 ) ;
return NULL ;
}
