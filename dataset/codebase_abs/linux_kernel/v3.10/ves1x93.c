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
static int F_7 ( struct V_1 * V_2 , T_2 V_22 )
{
T_1 V_23 ;
switch ( V_22 ) {
case V_24 :
V_23 = 0xc0 ;
break;
case V_25 :
V_23 = 0x80 ;
break;
case V_26 :
V_23 = 0x00 ;
break;
default:
return - V_27 ;
}
return F_1 ( V_2 , 0x0c , ( V_2 -> V_21 [ 0x0c ] & 0x3f ) | V_23 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_3 V_28 )
{
if ( V_28 == V_29 )
return F_1 ( V_2 , 0x0d , 0x08 ) ;
else if ( V_28 < V_30 || V_28 > V_31 )
return - V_27 ;
else
return F_1 ( V_2 , 0x0d , V_28 - V_30 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 )
{
return V_30 + ( ( F_4 ( V_2 , 0x0d ) >> 4 ) & 0x7 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_4 V_32 )
{
T_4 V_33 ;
T_4 V_34 ;
T_1 V_35 , V_36 , V_37 , V_38 ;
T_4 V_39 ;
T_4 V_40 ;
T_4 V_41 ;
F_3 ( L_2 , V_15 , ( unsigned int ) V_32 ) ;
if ( V_32 > V_2 -> V_9 -> V_42 / 2 )
V_32 = V_2 -> V_9 -> V_42 / 2 ;
if ( V_32 < 500000 )
V_32 = 500000 ;
#define F_11 (1UL<<26)
V_41 = ( V_2 -> V_9 -> V_42 + 6000 ) >> 4 ;
V_40 = V_32 << 6 ;
V_34 = V_40 / V_41 ;
V_40 = ( V_40 % V_41 ) << 8 ;
V_34 = ( V_34 << 8 ) + V_40 / V_41 ;
V_40 = ( V_40 % V_41 ) << 8 ;
V_34 = ( V_34 << 8 ) + V_40 / V_41 ;
V_37 = 0xff ;
if ( V_34 < F_11 / 3 ) V_37 = 0 ;
if ( V_34 < ( F_11 * 11 ) / 50 ) V_37 = 1 ;
if ( V_34 < F_11 / 6 ) V_37 = 2 ;
if ( V_34 < F_11 / 9 ) V_37 = 3 ;
if ( V_34 < F_11 / 12 ) V_37 = 4 ;
if ( V_34 < ( F_11 * 11 ) / 200 ) V_37 = 5 ;
if ( V_34 < F_11 / 24 ) V_37 = 6 ;
if ( V_34 < ( F_11 * 27 ) / 1000 ) V_37 = 7 ;
if ( V_34 < F_11 / 48 ) V_37 = 8 ;
if ( V_34 < ( F_11 * 137 ) / 10000 ) V_37 = 9 ;
if ( V_37 == 0xff ) {
V_35 = 0x89 ;
V_36 = 0x80 ;
V_37 = 0 ;
} else {
V_35 = 0x81 ;
V_36 = 0x88 | ( V_37 >> 1 ) | ( ( V_37 & 0x01 ) << 5 ) ;
}
V_33 = ( ( ( V_34 << ( V_37 >> 1 ) ) >> 4 ) + 1 ) >> 1 ;
V_39 = ( ( ( V_41 << 8 ) / ( ( V_32 << ( V_37 >> 1 ) ) >> 2 ) ) + 1 ) >> 1 ;
F_3 ( L_3 , V_37 ) ;
F_3 ( L_4 , ( unsigned int ) V_34 ) ;
F_3 ( L_5 , ( unsigned int ) V_33 ) ;
F_3 ( L_6 , ( unsigned int ) V_39 ) ;
if ( V_39 > 0xff )
V_39 = 0xff ;
F_1 ( V_2 , 0x06 , 0xff & V_33 ) ;
F_1 ( V_2 , 0x07 , 0xff & ( V_33 >> 8 ) ) ;
F_1 ( V_2 , 0x08 , 0x0f & ( V_33 >> 16 ) ) ;
F_1 ( V_2 , 0x09 , V_39 ) ;
F_1 ( V_2 , 0x20 , V_35 ) ;
F_1 ( V_2 , 0x21 , V_36 ) ;
V_38 = V_2 -> V_21 [ 0x05 ] ;
if ( V_2 -> V_9 -> V_43 )
V_38 |= 0x20 ;
if ( V_32 < 6000000 )
V_38 |= 0x80 ;
else
V_38 &= ~ 0x80 ;
F_1 ( V_2 , 0x05 , V_38 ) ;
if ( V_2 -> V_44 != V_45 )
F_5 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
int V_49 ;
int V_23 ;
F_3 ( L_7 , V_15 ) ;
for ( V_49 = 0 ; V_49 < V_2 -> V_50 ; V_49 ++ ) {
if ( V_2 -> V_51 [ V_49 ] ) {
V_23 = V_2 -> V_21 [ V_49 ] ;
if ( V_2 -> V_9 -> V_43 && ( V_49 == 0x05 ) ) V_23 |= 0x20 ;
F_1 ( V_2 , V_49 , V_23 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_46 * V_47 , T_5 V_52 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
switch ( V_52 ) {
case V_53 :
return F_1 ( V_2 , 0x1f , 0x20 ) ;
case V_54 :
return F_1 ( V_2 , 0x1f , 0x30 ) ;
case V_55 :
return F_1 ( V_2 , 0x1f , 0x00 ) ;
default:
return - V_27 ;
}
}
static int F_14 ( struct V_46 * V_47 , T_6 * V_56 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
T_1 V_57 = F_4 ( V_2 , 0x0e ) ;
int V_58 = 10 ;
while ( ( V_57 & 0x03 ) != 0x03 && ( V_57 & 0x0c ) && V_58 -- ) {
F_6 ( 10 ) ;
V_57 = F_4 ( V_2 , 0x0e ) ;
}
* V_56 = 0 ;
if ( V_57 & 1 )
* V_56 |= V_59 ;
if ( V_57 & 2 )
* V_56 |= V_60 ;
if ( V_57 & 4 )
* V_56 |= V_61 ;
if ( V_57 & 8 )
* V_56 |= V_62 ;
if ( ( V_57 & 0x1f ) == 0x1f )
* V_56 |= V_63 ;
return 0 ;
}
static int F_15 ( struct V_46 * V_47 , T_4 * V_64 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
* V_64 = F_4 ( V_2 , 0x15 ) ;
* V_64 |= ( F_4 ( V_2 , 0x16 ) << 8 ) ;
* V_64 |= ( ( F_4 ( V_2 , 0x17 ) & 0x0F ) << 16 ) ;
* V_64 *= 10 ;
return 0 ;
}
static int F_16 ( struct V_46 * V_47 , T_7 * V_65 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
T_1 signal = ~ F_4 ( V_2 , 0x0b ) ;
* V_65 = ( signal << 8 ) | signal ;
return 0 ;
}
static int F_17 ( struct V_46 * V_47 , T_7 * V_66 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
T_1 V_67 = ~ F_4 ( V_2 , 0x1c ) ;
* V_66 = ( V_67 << 8 ) | V_67 ;
return 0 ;
}
static int F_18 ( struct V_46 * V_47 , T_4 * V_68 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
* V_68 = F_4 ( V_2 , 0x18 ) & 0x7f ;
if ( * V_68 == 0x7f )
* V_68 = 0xffffffff ;
F_1 ( V_2 , 0x18 , 0x00 ) ;
F_1 ( V_2 , 0x18 , 0x80 ) ;
return 0 ;
}
static int F_19 ( struct V_46 * V_47 )
{
struct V_69 * V_70 = & V_47 -> V_71 ;
struct V_1 * V_2 = V_47 -> V_48 ;
if ( V_47 -> V_72 . V_73 . V_74 ) {
V_47 -> V_72 . V_73 . V_74 ( V_47 ) ;
if ( V_47 -> V_72 . V_75 ) V_47 -> V_72 . V_75 ( V_47 , 0 ) ;
}
F_7 ( V_2 , V_70 -> V_22 ) ;
F_8 ( V_2 , V_70 -> V_76 ) ;
F_10 ( V_2 , V_70 -> V_77 ) ;
V_2 -> V_22 = V_70 -> V_22 ;
V_2 -> V_78 = V_70 -> V_78 ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 )
{
struct V_69 * V_70 = & V_47 -> V_71 ;
struct V_1 * V_2 = V_47 -> V_48 ;
int V_79 ;
V_79 = ( ( int ) ( ( char ) ( F_4 ( V_2 , 0x0a ) << 1 ) ) ) / 2 ;
V_79 = ( V_79 * ( int ) ( V_70 -> V_77 / 1000 / 8 ) ) / 16 ;
V_70 -> V_78 = V_2 -> V_78 - V_79 ;
if ( V_2 -> V_22 == V_26 )
V_70 -> V_22 = ( F_4 ( V_2 , 0x0f ) & 2 ) ?
V_24 : V_25 ;
V_70 -> V_76 = F_9 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
return F_1 ( V_2 , 0x00 , 0x08 ) ;
}
static void F_22 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_46 * V_47 , int V_80 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
if ( V_80 ) {
return F_1 ( V_2 , 0x00 , 0x11 ) ;
} else {
return F_1 ( V_2 , 0x00 , 0x01 ) ;
}
}
struct V_46 * F_25 ( const struct V_81 * V_9 ,
struct V_82 * V_14 )
{
struct V_1 * V_2 = NULL ;
T_1 V_83 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_84 ) ;
if ( V_2 == NULL ) goto error;
V_2 -> V_9 = V_9 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_22 = V_24 ;
V_83 = F_4 ( V_2 , 0x1e ) ;
switch ( V_83 ) {
case 0xdc :
F_27 ( L_8 ) ;
V_2 -> V_44 = V_85 ;
V_2 -> V_21 = V_86 ;
V_2 -> V_51 = V_87 ;
V_2 -> V_50 = sizeof( V_86 ) ;
break;
case 0xdd :
F_27 ( L_9 ) ;
V_2 -> V_44 = V_85 ;
V_2 -> V_21 = V_86 ;
V_2 -> V_51 = V_87 ;
V_2 -> V_50 = sizeof( V_86 ) ;
break;
case 0xde :
F_27 ( L_10 ) ;
V_2 -> V_44 = V_45 ;
V_2 -> V_21 = V_88 ;
V_2 -> V_51 = V_89 ;
V_2 -> V_50 = sizeof( V_88 ) ;
break;
default:
goto error;
}
memcpy ( & V_2 -> V_90 . V_72 , & V_91 , sizeof( struct V_92 ) ) ;
V_2 -> V_90 . V_48 = V_2 ;
return & V_2 -> V_90 ;
error:
F_23 ( V_2 ) ;
return NULL ;
}
