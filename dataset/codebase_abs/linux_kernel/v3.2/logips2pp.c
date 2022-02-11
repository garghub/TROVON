static T_1 F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
if ( V_1 -> V_5 < 3 )
return V_6 ;
if ( ( V_4 [ 0 ] & 0x48 ) == 0x48 && ( V_4 [ 1 ] & 0x02 ) == 0x02 ) {
switch ( ( V_4 [ 1 ] >> 4 ) | ( V_4 [ 0 ] & 0x30 ) ) {
case 0x0d :
F_2 ( V_3 , V_4 [ 2 ] & 0x80 ? V_7 : V_8 ,
( int ) ( V_4 [ 2 ] & 8 ) - ( int ) ( V_4 [ 2 ] & 7 ) ) ;
F_3 ( V_3 , V_9 , ( V_4 [ 2 ] >> 4 ) & 1 ) ;
F_3 ( V_3 , V_10 , ( V_4 [ 2 ] >> 5 ) & 1 ) ;
break;
case 0x0e :
F_3 ( V_3 , V_9 , ( V_4 [ 2 ] ) & 1 ) ;
F_3 ( V_3 , V_10 , ( V_4 [ 2 ] >> 1 ) & 1 ) ;
F_3 ( V_3 , V_11 , ( V_4 [ 2 ] >> 3 ) & 1 ) ;
F_3 ( V_3 , V_12 , ( V_4 [ 2 ] >> 4 ) & 1 ) ;
F_3 ( V_3 , V_13 , ( V_4 [ 2 ] >> 2 ) & 1 ) ;
break;
case 0x0f :
F_2 ( V_3 , V_4 [ 2 ] & 0x08 ? V_7 : V_8 ,
( int ) ( ( V_4 [ 2 ] >> 4 ) & 8 ) - ( int ) ( ( V_4 [ 2 ] >> 4 ) & 7 ) ) ;
V_4 [ 0 ] = V_4 [ 2 ] | 0x08 ;
break;
default:
F_4 ( V_1 ,
L_1 ,
( V_4 [ 1 ] >> 4 ) | ( V_4 [ 0 ] & 0x30 ) ) ;
break;
}
} else {
F_2 ( V_3 , V_14 , V_4 [ 1 ] ? ( int ) V_4 [ 1 ] - ( int ) ( ( V_4 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_2 ( V_3 , V_15 , V_4 [ 2 ] ? ( int ) ( ( V_4 [ 0 ] << 3 ) & 0x100 ) - ( int ) V_4 [ 2 ] : 0 ) ;
}
F_3 ( V_3 , V_16 , V_4 [ 0 ] & 1 ) ;
F_3 ( V_3 , V_17 , ( V_4 [ 0 ] >> 2 ) & 1 ) ;
F_3 ( V_3 , V_18 , ( V_4 [ 0 ] >> 1 ) & 1 ) ;
F_5 ( V_3 ) ;
return V_19 ;
}
static int F_6 ( struct V_1 * V_1 , unsigned char * V_20 , unsigned char V_21 )
{
if ( F_7 ( V_1 , V_21 ) )
return - 1 ;
if ( F_8 ( & V_1 -> V_22 , V_20 , V_23 | 0x0300 ) )
return - 1 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_1 , bool V_24 )
{
struct V_22 * V_22 = & V_1 -> V_22 ;
unsigned char V_20 [ 4 ] ;
F_6 ( V_1 , V_20 , 0x32 ) ;
V_20 [ 0 ] = 0 ;
F_8 ( V_22 , V_20 , V_25 ) ;
F_8 ( V_22 , V_20 , V_25 ) ;
F_8 ( V_22 , V_20 , V_25 ) ;
V_20 [ 0 ] = V_24 ;
F_8 ( V_22 , V_20 , V_25 ) ;
}
static T_2 F_10 ( struct V_1 * V_1 ,
void * V_26 , char * V_27 )
{
return sprintf ( V_27 , L_2 , V_1 -> V_24 ) ;
}
static T_2 F_11 ( struct V_1 * V_1 , void * V_26 ,
const char * V_27 , T_3 V_28 )
{
unsigned long V_29 ;
if ( F_12 ( V_27 , 10 , & V_29 ) || V_29 > 1 )
return - V_30 ;
F_9 ( V_1 , V_29 ) ;
V_1 -> V_24 = V_29 ;
return V_28 ;
}
static void F_13 ( struct V_1 * V_1 , unsigned int V_31 )
{
if ( V_31 > 400 ) {
struct V_22 * V_22 = & V_1 -> V_22 ;
unsigned char V_20 = 3 ;
F_8 ( V_22 , NULL , V_32 ) ;
F_8 ( V_22 , NULL , V_32 ) ;
F_8 ( V_22 , NULL , V_32 ) ;
F_8 ( V_22 , & V_20 , V_25 ) ;
V_1 -> V_31 = 800 ;
} else
F_14 ( V_1 , V_31 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
F_16 ( & V_1 -> V_22 . V_33 -> V_3 , & V_34 . V_35 ) ;
}
static const struct V_36 * F_17 ( unsigned char V_37 )
{
static const struct V_36 V_38 [] = {
{ 1 , 0 , 0 } ,
{ 12 , 0 , V_39 } ,
{ 13 , 0 , 0 } ,
{ 15 , V_40 ,
V_41 | V_39 | V_42 |
V_43 | V_44 | V_45 } ,
{ 40 , 0 , V_39 } ,
{ 41 , 0 , V_39 } ,
{ 42 , 0 , V_39 } ,
{ 43 , 0 , V_39 } ,
{ 50 , 0 , 0 } ,
{ 51 , 0 , 0 } ,
{ 52 , V_46 , V_39 | V_41 } ,
{ 53 , V_46 , V_41 } ,
{ 56 , V_46 , V_39 | V_41 } ,
{ 61 , V_40 ,
V_41 | V_39 | V_42 |
V_43 | V_44 } ,
{ 66 , V_40 ,
V_41 | V_39 | V_42 |
V_43 | V_44 | V_45 } ,
{ 72 , V_47 , 0 } ,
{ 73 , V_47 , V_39 } ,
{ 75 , V_46 , V_41 } ,
{ 76 , V_46 , V_41 } ,
{ 79 , V_47 , V_41 } ,
{ 80 , V_46 , V_39 | V_41 } ,
{ 81 , V_46 , V_41 } ,
{ 83 , V_46 , V_41 } ,
{ 85 , V_46 , V_41 } ,
{ 86 , V_46 , V_41 } ,
{ 87 , V_46 , V_41 } ,
{ 88 , V_46 , V_41 } ,
{ 96 , 0 , 0 } ,
{ 97 , V_48 , V_41 | V_45 } ,
{ 99 , V_46 , V_41 } ,
{ 100 , V_40 ,
V_41 | V_39 | V_42 |
V_43 | V_44 } ,
{ 111 , V_40 , V_41 | V_39 } ,
{ 112 , V_40 ,
V_41 | V_39 | V_42 |
V_43 | V_44 } ,
{ 114 , V_40 ,
V_41 | V_39 |
V_42 | V_43 }
} ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_18 ( V_38 ) ; V_49 ++ )
if ( V_37 == V_38 [ V_49 ] . V_37 )
return & V_38 [ V_49 ] ;
return NULL ;
}
static void F_19 ( struct V_1 * V_1 ,
const struct V_36 * V_50 ,
bool V_51 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
if ( V_50 -> V_52 & V_39 )
F_20 ( V_9 , V_2 -> V_53 ) ;
if ( V_50 -> V_52 & V_43 )
F_20 ( V_10 , V_2 -> V_53 ) ;
if ( V_50 -> V_52 & V_42 )
F_20 ( V_13 , V_2 -> V_53 ) ;
if ( V_50 -> V_52 & V_44 ) {
F_20 ( V_12 , V_2 -> V_53 ) ;
F_20 ( V_11 , V_2 -> V_53 ) ;
}
if ( V_50 -> V_52 & V_41 )
F_20 ( V_8 , V_2 -> V_54 ) ;
if ( V_50 -> V_52 & V_45 )
F_20 ( V_7 , V_2 -> V_54 ) ;
switch ( V_50 -> V_55 ) {
case V_46 :
V_1 -> V_56 = L_3 ;
break;
case V_40 :
V_1 -> V_56 = L_4 ;
break;
case V_48 :
V_1 -> V_56 = L_5 ;
break;
case V_47 :
V_1 -> V_56 = L_6 ;
break;
default:
if ( V_51 )
V_1 -> V_56 = L_7 ;
break;
}
}
int F_21 ( struct V_1 * V_1 , bool V_57 )
{
struct V_22 * V_22 = & V_1 -> V_22 ;
unsigned char V_20 [ 4 ] ;
unsigned char V_37 , V_58 ;
const struct V_36 * V_50 ;
bool V_59 = false ;
int error ;
V_20 [ 0 ] = 0 ;
F_8 ( V_22 , V_20 , V_25 ) ;
F_8 ( V_22 , NULL , V_32 ) ;
F_8 ( V_22 , NULL , V_32 ) ;
F_8 ( V_22 , NULL , V_32 ) ;
V_20 [ 1 ] = 0 ;
F_8 ( V_22 , V_20 , V_60 ) ;
V_37 = ( ( V_20 [ 0 ] >> 4 ) & 0x07 ) | ( ( V_20 [ 0 ] << 3 ) & 0x78 ) ;
V_58 = V_20 [ 1 ] ;
if ( ! V_37 || ! V_58 )
return - 1 ;
V_50 = F_17 ( V_37 ) ;
if ( V_50 ) {
if ( V_50 -> V_55 == V_48 ) {
V_20 [ 0 ] = 0x11 ; V_20 [ 1 ] = 0x04 ; V_20 [ 2 ] = 0x68 ;
F_8 ( V_22 , V_20 , 0x30d1 ) ;
V_20 [ 0 ] = 0x11 ; V_20 [ 1 ] = 0x05 ; V_20 [ 2 ] = 0x0b ;
F_8 ( V_22 , V_20 , 0x30d1 ) ;
V_20 [ 0 ] = 0x11 ; V_20 [ 1 ] = 0x09 ; V_20 [ 2 ] = 0xc3 ;
F_8 ( V_22 , V_20 , 0x30d1 ) ;
V_20 [ 0 ] = 0 ;
if ( ! F_8 ( V_22 , V_20 , 0x13d1 ) &&
V_20 [ 0 ] == 0x06 && V_20 [ 1 ] == 0x00 && V_20 [ 2 ] == 0x14 ) {
V_59 = true ;
}
} else {
V_20 [ 0 ] = V_20 [ 1 ] = V_20 [ 2 ] = 0 ;
F_6 ( V_1 , V_20 , 0x39 ) ;
F_6 ( V_1 , V_20 , 0xDB ) ;
if ( ( V_20 [ 0 ] & 0x78 ) == 0x48 &&
( V_20 [ 1 ] & 0xf3 ) == 0xc2 &&
( V_20 [ 2 ] & 0x03 ) == ( ( V_20 [ 1 ] >> 2 ) & 3 ) ) {
F_9 ( V_1 , false ) ;
V_59 = true ;
}
}
} else {
F_22 ( V_1 , L_8 , V_37 ) ;
}
if ( V_57 ) {
V_1 -> V_61 = L_9 ;
V_1 -> V_37 = V_37 ;
if ( V_59 ) {
V_1 -> V_62 = F_1 ;
V_1 -> V_63 = 3 ;
if ( V_50 -> V_55 != V_48 ) {
V_1 -> V_64 = F_13 ;
V_1 -> V_65 = F_15 ;
error = F_23 ( & V_1 -> V_22 . V_33 -> V_3 ,
& V_34 . V_35 ) ;
if ( error ) {
F_24 ( V_1 ,
L_10 ,
error ) ;
return - 1 ;
}
}
}
if ( V_58 >= 3 )
F_20 ( V_17 , V_1 -> V_3 -> V_53 ) ;
if ( V_50 )
F_19 ( V_1 , V_50 , V_59 ) ;
}
return V_59 ? 0 : - 1 ;
}
