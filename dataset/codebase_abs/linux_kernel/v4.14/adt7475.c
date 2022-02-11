static inline T_1 F_1 ( struct V_1 * V_2 , long V_3 )
{
T_1 V_4 ;
if ( ! ( V_2 -> V_5 & V_6 ) ) {
V_3 = F_2 ( V_3 , - 64000 , 191000 ) ;
V_4 = ( V_3 + 64500 ) / 1000 ;
} else {
V_3 = F_2 ( V_3 , - 128000 , 127000 ) ;
if ( V_3 < - 500 )
V_4 = ( 256500 + V_3 ) / 1000 ;
else
V_4 = ( V_3 + 500 ) / 1000 ;
}
return V_4 << 2 ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
if ( V_2 -> V_5 & V_6 ) {
if ( V_7 >= 512 )
return ( V_7 - 1024 ) * 250 ;
else
return V_7 * 250 ;
} else
return ( V_7 - 256 ) * 250 ;
}
static inline int F_4 ( T_1 V_8 )
{
if ( V_8 == 0 || V_8 == 0xFFFF )
return 0 ;
return ( 90000 * 60 ) / V_8 ;
}
static inline T_1 F_5 ( unsigned long V_9 )
{
if ( V_9 == 0 )
return 0 ;
return F_2 ( ( 90000 * 60 ) / V_9 , 1 , 0xFFFF ) ;
}
static inline int F_6 ( int V_10 , T_1 V_7 , T_2 V_11 )
{
const int * V_12 = V_13 [ V_10 ] ;
if ( V_11 & ( 1 << V_10 ) )
return F_7 ( V_7 * 2250 , 1024 ) ;
return F_7 ( V_7 * ( V_12 [ 0 ] + V_12 [ 1 ] ) * 2250 , V_12 [ 1 ] * 1024 ) ;
}
static inline T_1 F_8 ( int V_10 , long V_14 , T_2 V_11 )
{
const int * V_12 = V_13 [ V_10 ] ;
long V_7 ;
if ( V_11 & ( 1 << V_10 ) )
V_7 = ( V_14 * 1024 ) / 2250 ;
else
V_7 = ( V_14 * V_12 [ 1 ] * 1024 ) / ( ( V_12 [ 0 ] + V_12 [ 1 ] ) * 2250 ) ;
return F_2 ( V_7 , 0 , 1023 ) & ( 0xff << 2 ) ;
}
static T_1 F_9 ( struct V_15 * V_16 , int V_7 )
{
T_1 V_3 ;
V_3 = F_10 ( V_16 , V_7 ) ;
V_3 |= ( F_10 ( V_16 , V_7 + 1 ) << 8 ) ;
return V_3 ;
}
static void F_11 ( struct V_15 * V_16 , int V_7 , T_1 V_3 )
{
F_12 ( V_16 , V_7 + 1 , V_3 >> 8 ) ;
F_12 ( V_16 , V_7 , V_3 & 0xFF ) ;
}
static T_3 F_13 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
unsigned short V_3 ;
switch ( V_23 -> V_24 ) {
case V_25 :
return sprintf ( V_21 , L_1 ,
( V_2 -> V_26 >> V_23 -> V_27 ) & 1 ) ;
default:
V_3 = V_2 -> V_28 [ V_23 -> V_24 ] [ V_23 -> V_27 ] ;
return sprintf ( V_21 , L_1 ,
F_6 ( V_23 -> V_27 , V_3 , V_2 -> V_11 ) ) ;
}
}
static T_3 F_16 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
unsigned char V_7 ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_28 [ V_23 -> V_24 ] [ V_23 -> V_27 ] =
F_8 ( V_23 -> V_27 , V_3 , V_2 -> V_11 ) ;
if ( V_23 -> V_27 < V_32 ) {
if ( V_23 -> V_24 == V_33 )
V_7 = F_21 ( V_23 -> V_27 ) ;
else
V_7 = F_22 ( V_23 -> V_27 ) ;
} else {
if ( V_23 -> V_24 == V_33 )
V_7 = V_34 ;
else
V_7 = V_35 ;
}
F_12 ( V_16 , V_7 ,
V_2 -> V_28 [ V_23 -> V_24 ] [ V_23 -> V_27 ] >> 2 ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_24 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
int V_36 ;
switch ( V_23 -> V_24 ) {
case V_37 :
F_20 ( & V_2 -> V_31 ) ;
V_36 = V_2 -> V_38 [ V_23 -> V_24 ] [ V_23 -> V_27 ] ;
if ( V_23 -> V_27 != 1 )
V_36 = ( V_36 >> 4 ) & 0xF ;
else
V_36 = ( V_36 & 0xF ) ;
V_36 = F_3 ( V_2 , V_2 -> V_38 [ V_39 ] [ V_23 -> V_27 ] ) -
V_36 * 1000 ;
F_23 ( & V_2 -> V_31 ) ;
break;
case V_40 :
F_20 ( & V_2 -> V_31 ) ;
V_36 = ( V_41 ) V_2 -> V_38 [ V_23 -> V_24 ] [ V_23 -> V_27 ] ;
if ( V_2 -> V_5 & V_42 )
V_36 *= 1000 ;
else
V_36 *= 500 ;
F_23 ( & V_2 -> V_31 ) ;
break;
case V_25 :
V_36 = ( V_2 -> V_26 >> ( V_23 -> V_27 + 4 ) ) & 1 ;
break;
case V_43 :
V_36 = ! ! ( V_2 -> V_26 & ( V_23 -> V_27 ? 0x8000 : 0x4000 ) ) ;
break;
default:
V_36 = F_3 ( V_2 , V_2 -> V_38 [ V_23 -> V_24 ] [ V_23 -> V_27 ] ) ;
}
return sprintf ( V_21 , L_1 , V_36 ) ;
}
static T_3 F_25 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
unsigned char V_7 = 0 ;
T_2 V_36 ;
int V_38 ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_5 = F_26 ( V_44 ) ;
switch ( V_23 -> V_24 ) {
case V_40 :
if ( V_2 -> V_5 & V_42 ) {
V_3 = F_2 ( V_3 , - 63000 , 127000 ) ;
V_36 = V_2 -> V_38 [ V_40 ] [ V_23 -> V_27 ] = V_3 / 1000 ;
} else {
V_3 = F_2 ( V_3 , - 63000 , 64000 ) ;
V_36 = V_2 -> V_38 [ V_40 ] [ V_23 -> V_27 ] = V_3 / 500 ;
}
break;
case V_37 :
V_2 -> V_38 [ V_39 ] [ V_23 -> V_27 ] =
F_26 ( F_27 ( V_23 -> V_27 ) ) << 2 ;
F_28 ( V_16 ) ;
V_38 = F_3 ( V_2 , V_2 -> V_38 [ V_39 ] [ V_23 -> V_27 ] ) ;
V_3 = F_2 ( V_3 , V_38 - 15000 , V_38 ) ;
V_3 = ( V_38 - V_3 ) / 1000 ;
if ( V_23 -> V_27 != 1 ) {
V_2 -> V_38 [ V_37 ] [ V_23 -> V_27 ] &= 0xF0 ;
V_2 -> V_38 [ V_37 ] [ V_23 -> V_27 ] |= ( V_3 & 0xF ) << 4 ;
} else {
V_2 -> V_38 [ V_37 ] [ V_23 -> V_27 ] &= 0x0F ;
V_2 -> V_38 [ V_37 ] [ V_23 -> V_27 ] |= ( V_3 & 0xF ) ;
}
V_36 = V_2 -> V_38 [ V_37 ] [ V_23 -> V_27 ] ;
break;
default:
V_2 -> V_38 [ V_23 -> V_24 ] [ V_23 -> V_27 ] = F_1 ( V_2 , V_3 ) ;
V_36 = ( T_2 ) ( V_2 -> V_38 [ V_23 -> V_24 ] [ V_23 -> V_27 ] >> 2 ) ;
}
switch ( V_23 -> V_24 ) {
case V_33 :
V_7 = F_29 ( V_23 -> V_27 ) ;
break;
case V_45 :
V_7 = F_30 ( V_23 -> V_27 ) ;
break;
case V_40 :
V_7 = F_31 ( V_23 -> V_27 ) ;
break;
case V_46 :
V_7 = F_32 ( V_23 -> V_27 ) ;
break;
case V_39 :
V_7 = F_27 ( V_23 -> V_27 ) ;
break;
case V_37 :
if ( V_23 -> V_27 != 2 )
V_7 = V_47 ;
else
V_7 = V_48 ;
break;
}
F_12 ( V_16 , V_7 , V_36 ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_33 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
long V_3 ;
switch ( V_23 -> V_27 ) {
case 0 :
V_3 = V_2 -> V_49 [ 0 ] & 0xf ;
break;
case 1 :
V_3 = ( V_2 -> V_49 [ 1 ] >> 4 ) & 0xf ;
break;
case 2 :
default:
V_3 = V_2 -> V_49 [ 1 ] & 0xf ;
break;
}
if ( V_3 & 0x8 )
return sprintf ( V_21 , L_1 , V_50 [ V_3 & 0x7 ] ) ;
else
return sprintf ( V_21 , L_2 ) ;
}
static T_3 F_34 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
unsigned char V_7 ;
int V_51 , V_52 ;
T_5 V_3 ;
if ( F_35 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
switch ( V_23 -> V_27 ) {
case 0 :
V_7 = V_53 ;
V_51 = 0 ;
V_52 = 0 ;
break;
case 1 :
V_7 = V_54 ;
V_51 = 0 ;
V_52 = 1 ;
break;
case 2 :
default:
V_7 = V_54 ;
V_51 = 4 ;
V_52 = 1 ;
break;
}
if ( V_3 > 0 ) {
V_3 = F_36 ( V_3 , V_50 ,
F_37 ( V_50 ) ) ;
V_3 |= 0x8 ;
}
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_49 [ V_52 ] &= ~ ( 0xf << V_51 ) ;
V_2 -> V_49 [ V_52 ] |= ( V_3 << V_51 ) ;
F_12 ( V_16 , V_7 , V_2 -> V_49 [ V_52 ] ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_38 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
int V_36 , V_3 ;
F_20 ( & V_2 -> V_31 ) ;
V_36 = ( V_2 -> V_55 [ V_23 -> V_27 ] >> 4 ) & 0x0F ;
V_3 = F_3 ( V_2 , V_2 -> V_38 [ V_46 ] [ V_23 -> V_27 ] ) ;
F_23 ( & V_2 -> V_31 ) ;
return sprintf ( V_21 , L_1 , V_3 + V_56 [ V_36 ] ) ;
}
static T_3 F_39 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
int V_38 ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_5 = F_26 ( V_44 ) ;
V_2 -> V_38 [ V_46 ] [ V_23 -> V_27 ] =
F_26 ( F_32 ( V_23 -> V_27 ) ) << 2 ;
V_2 -> V_55 [ V_23 -> V_27 ] =
F_26 ( F_40 ( V_23 -> V_27 ) ) ;
V_38 = F_3 ( V_2 , V_2 -> V_38 [ V_46 ] [ V_23 -> V_27 ] ) ;
V_3 = F_2 ( V_3 , V_38 + V_56 [ 0 ] ,
V_38 + V_56 [ F_37 ( V_56 ) - 1 ] ) ;
V_3 -= V_38 ;
V_3 = F_41 ( V_3 , V_56 , F_37 ( V_56 ) ) ;
V_2 -> V_55 [ V_23 -> V_27 ] &= ~ 0xF0 ;
V_2 -> V_55 [ V_23 -> V_27 ] |= V_3 << 4 ;
F_12 ( V_16 , F_40 ( V_23 -> V_27 ) ,
V_2 -> V_55 [ V_23 -> V_27 ] ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_42 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
int V_36 ;
if ( V_23 -> V_24 == V_25 )
V_36 = ( V_2 -> V_26 >> ( V_23 -> V_27 + 10 ) ) & 1 ;
else
V_36 = F_4 ( V_2 -> V_8 [ V_23 -> V_24 ] [ V_23 -> V_27 ] ) ;
return sprintf ( V_21 , L_1 , V_36 ) ;
}
static T_3 F_43 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
unsigned long V_3 ;
if ( F_35 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_8 [ V_33 ] [ V_23 -> V_27 ] = F_5 ( V_3 ) ;
F_11 ( V_16 , F_44 ( V_23 -> V_27 ) ,
V_2 -> V_8 [ V_33 ] [ V_23 -> V_27 ] ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_45 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
return sprintf ( V_21 , L_1 , V_2 -> V_57 [ V_23 -> V_24 ] [ V_23 -> V_27 ] ) ;
}
static T_3 F_46 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
return sprintf ( V_21 , L_1 , V_2 -> V_58 [ V_23 -> V_27 ] ) ;
}
static T_3 F_47 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
return sprintf ( V_21 , L_1 , V_2 -> V_59 [ V_23 -> V_27 ] ) ;
}
static T_3 F_48 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
unsigned char V_7 = 0 ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
switch ( V_23 -> V_24 ) {
case V_60 :
V_2 -> V_57 [ V_61 ] [ V_23 -> V_27 ] =
F_26 ( F_49 ( V_23 -> V_27 ) ) ;
if ( ( ( V_2 -> V_57 [ V_61 ] [ V_23 -> V_27 ] >> 5 ) & 7 ) != 7 ) {
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
V_7 = F_50 ( V_23 -> V_27 ) ;
break;
case V_33 :
V_7 = F_51 ( V_23 -> V_27 ) ;
break;
case V_45 :
V_7 = F_52 ( V_23 -> V_27 ) ;
break;
}
V_2 -> V_57 [ V_23 -> V_24 ] [ V_23 -> V_27 ] = F_2 ( V_3 , 0 , 0xFF ) ;
F_12 ( V_16 , V_7 ,
V_2 -> V_57 [ V_23 -> V_24 ] [ V_23 -> V_27 ] ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_53 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
T_2 V_62 = F_54 ( 5 + V_23 -> V_27 ) ;
return sprintf ( V_21 , L_1 , ! ! ( V_2 -> V_49 [ 0 ] & V_62 ) ) ;
}
static T_3 F_55 ( struct V_17 * V_18 ,
struct V_19 * V_20 , const char * V_21 ,
T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
long V_3 ;
T_2 V_62 = F_54 ( 5 + V_23 -> V_27 ) ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_49 [ 0 ] &= ~ V_62 ;
if ( V_3 )
V_2 -> V_49 [ 0 ] |= V_62 ;
F_12 ( V_16 , V_53 ,
V_2 -> V_49 [ 0 ] ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static int F_56 ( struct V_15 * V_16 , int V_27 ,
unsigned int V_59 , unsigned int V_58 )
{
struct V_1 * V_2 = F_18 ( V_16 ) ;
long V_3 = 0 ;
switch ( V_59 ) {
case 0 :
V_3 = 0x03 ;
break;
case 1 :
V_3 = 0x07 ;
break;
case 2 :
switch ( V_58 ) {
case 1 :
V_3 = 0x00 ;
break;
case 2 :
V_3 = 0x01 ;
break;
case 4 :
V_3 = 0x02 ;
break;
case 6 :
V_3 = 0x05 ;
break;
case 7 :
V_3 = 0x06 ;
break;
default:
return - V_30 ;
}
break;
default:
return - V_30 ;
}
V_2 -> V_59 [ V_27 ] = V_59 ;
V_2 -> V_58 [ V_27 ] = V_58 ;
V_2 -> V_57 [ V_61 ] [ V_27 ] &= ~ 0xE0 ;
V_2 -> V_57 [ V_61 ] [ V_27 ] |= ( V_3 & 7 ) << 5 ;
F_12 ( V_16 , F_49 ( V_27 ) ,
V_2 -> V_57 [ V_61 ] [ V_27 ] ) ;
return 0 ;
}
static T_3 F_57 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
int V_12 ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
F_58 ( V_16 , V_23 -> V_27 ) ;
V_12 = F_56 ( V_16 , V_23 -> V_27 , V_2 -> V_59 [ V_23 -> V_27 ] , V_3 ) ;
if ( V_12 )
V_29 = V_12 ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_59 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
int V_12 ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
F_58 ( V_16 , V_23 -> V_27 ) ;
V_12 = F_56 ( V_16 , V_23 -> V_27 , V_3 , V_2 -> V_58 [ V_23 -> V_27 ] ) ;
if ( V_12 )
V_29 = V_12 ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_60 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
struct V_22 * V_23 = F_15 ( V_20 ) ;
int V_63 = F_2 ( V_2 -> V_55 [ V_23 -> V_27 ] & 0xf , 0 ,
F_37 ( V_64 ) - 1 ) ;
return sprintf ( V_21 , L_1 , V_64 [ V_63 ] ) ;
}
static T_3 F_61 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_4 V_29 )
{
struct V_22 * V_23 = F_15 ( V_20 ) ;
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
int V_36 ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
V_36 = F_41 ( V_3 , V_64 , F_37 ( V_64 ) ) ;
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_55 [ V_23 -> V_27 ] =
F_26 ( F_40 ( V_23 -> V_27 ) ) ;
V_2 -> V_55 [ V_23 -> V_27 ] &= ~ 0xf ;
V_2 -> V_55 [ V_23 -> V_27 ] |= V_36 ;
F_12 ( V_16 , F_40 ( V_23 -> V_27 ) ,
V_2 -> V_55 [ V_23 -> V_27 ] ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_62 ( struct V_17 * V_18 ,
struct V_19 * V_65 ,
char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ! ! ( V_2 -> V_66 & V_67 ) ) ;
}
static T_3 F_63 ( struct V_17 * V_18 ,
struct V_19 * V_65 ,
const char * V_21 , T_4 V_29 )
{
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
if ( V_3 != 0 && V_3 != 1 )
return - V_30 ;
F_20 ( & V_2 -> V_31 ) ;
V_2 -> V_66 = F_10 ( V_16 , V_68 ) ;
if ( V_3 )
V_2 -> V_66 |= V_67 ;
else
V_2 -> V_66 &= ~ V_67 ;
F_12 ( V_16 , V_68 , V_2 -> V_66 ) ;
F_23 ( & V_2 -> V_31 ) ;
return V_29 ;
}
static T_3 F_64 ( struct V_17 * V_18 , struct V_19 * V_65 ,
char * V_21 )
{
struct V_1 * V_2 = F_65 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( int ) V_2 -> V_69 ) ;
}
static T_3 F_66 ( struct V_17 * V_18 , struct V_19 * V_65 ,
const char * V_21 , T_4 V_29 )
{
struct V_1 * V_2 = F_65 ( V_18 ) ;
long V_3 ;
if ( F_19 ( V_21 , 10 , & V_3 ) )
return - V_30 ;
if ( V_3 < 0 || V_3 > 255 )
return - V_30 ;
V_2 -> V_69 = V_3 ;
return V_29 ;
}
static T_3 F_67 ( struct V_17 * V_18 ,
struct V_19 * V_65 , char * V_21 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
return sprintf ( V_21 , L_1 , F_68 ( V_2 -> V_70 , V_2 -> V_69 ) ) ;
}
static int F_69 ( struct V_15 * V_16 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 = V_16 -> V_74 ;
int V_75 , V_76 , V_77 ;
const char * V_78 ;
if ( ! F_70 ( V_74 , V_79 ) )
return - V_80 ;
V_75 = F_26 ( V_81 ) ;
V_77 = F_26 ( V_82 ) ;
if ( V_75 != 0x41 ||
( V_77 & 0xf8 ) != 0x68 )
return - V_80 ;
V_76 = F_26 ( V_83 ) ;
if ( V_76 == 0x73 )
V_78 = L_3 ;
else if ( V_76 == 0x75 && V_16 -> V_84 == 0x2e )
V_78 = L_4 ;
else if ( V_76 == 0x76 )
V_78 = L_5 ;
else if ( ( V_77 & 0xfc ) == 0x6c )
V_78 = L_6 ;
else {
F_71 ( & V_74 -> V_18 ,
L_7
L_8 , ( unsigned int ) V_16 -> V_84 ) ;
return - V_80 ;
}
F_72 ( V_72 -> type , V_78 , V_85 ) ;
return 0 ;
}
static void F_73 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_74 ( & V_16 -> V_18 . V_86 , & V_87 ) ;
if ( V_2 -> V_88 )
F_74 ( & V_16 -> V_18 . V_86 , & V_89 ) ;
if ( V_2 -> V_90 )
F_74 ( & V_16 -> V_18 . V_86 , & V_91 ) ;
if ( V_2 -> V_92 & ( 1 << 0 ) )
F_74 ( & V_16 -> V_18 . V_86 , & V_93 ) ;
if ( V_2 -> V_92 & ( 1 << 3 ) )
F_74 ( & V_16 -> V_18 . V_86 , & V_94 ) ;
if ( V_2 -> V_92 & ( 1 << 4 ) )
F_74 ( & V_16 -> V_18 . V_86 , & V_95 ) ;
if ( V_2 -> V_92 & ( 1 << 5 ) )
F_74 ( & V_16 -> V_18 . V_86 , & V_96 ) ;
if ( V_2 -> V_97 )
F_74 ( & V_16 -> V_18 . V_86 , & V_98 ) ;
}
static int F_75 ( struct V_15 * V_16 ,
const struct V_99 * V_100 )
{
enum V_101 V_102 ;
static const char * const V_103 [] = {
[ V_104 ] = L_9 ,
[ V_105 ] = L_10 ,
[ V_106 ] = L_11 ,
[ V_107 ] = L_12 ,
} ;
struct V_1 * V_2 ;
int V_63 , V_4 = 0 , V_108 ;
T_2 V_109 , V_110 ;
V_2 = F_76 ( & V_16 -> V_18 , sizeof( * V_2 ) , V_111 ) ;
if ( V_2 == NULL )
return - V_112 ;
F_77 ( & V_2 -> V_31 ) ;
F_78 ( V_16 , V_2 ) ;
if ( V_16 -> V_18 . V_113 )
V_102 = (enum V_101 ) F_79 ( & V_16 -> V_18 ) ;
else
V_102 = V_100 -> V_114 ;
switch ( V_102 ) {
case V_106 :
V_2 -> V_92 = 0x0e ;
V_108 = F_26 ( V_82 ) & 0x07 ;
break;
case V_107 :
V_2 -> V_92 = 0x3e ;
V_108 = F_26 ( V_82 ) & 0x03 ;
if ( V_108 == 0x03 )
V_108 += F_26 ( V_115 ) ;
break;
default:
V_2 -> V_92 = 0x06 ;
V_108 = F_26 ( V_82 ) & 0x07 ;
}
V_110 = F_26 ( V_116 ) ;
if ( ! ( V_110 & V_117 ) )
V_2 -> V_90 = 1 ;
if ( V_100 -> V_114 == V_104 && V_108 >= 1 )
V_2 -> V_90 = ! V_2 -> V_90 ;
V_2 -> V_66 = F_26 ( V_68 ) ;
if ( ( V_2 -> V_66 & V_118 ) == 0x0 )
V_2 -> V_88 = 1 ;
if ( V_100 -> V_114 == V_107 ) {
if ( ( V_2 -> V_66 & V_118 ) == 0x1 &&
! ( V_110 & V_119 ) )
V_2 -> V_88 = 1 ;
}
if ( V_100 -> V_114 == V_106 || V_100 -> V_114 == V_107 ) {
if ( ! ( V_110 & V_119 ) ||
( V_2 -> V_66 & V_118 ) == 0x1 )
V_2 -> V_92 |= ( 1 << 0 ) ;
}
if ( V_100 -> V_114 == V_106 ) {
T_2 V_70 = F_26 ( V_120 ) ;
if ( ! ( V_70 & V_121 ) )
V_2 -> V_92 |= ( 1 << 4 ) ;
V_2 -> V_97 = ! ( F_26 ( V_44 ) & V_122 ) ;
}
V_109 = F_26 ( V_123 ) ;
if ( V_109 & V_124 ) {
V_2 -> V_11 = ( 0x3 << 3 ) | 0x3 ;
} else {
V_2 -> V_11 = ( ( V_2 -> V_66 & V_125 ) >> 4 ) |
( ( V_2 -> V_66 & V_126 ) >> 3 ) ;
}
V_2 -> V_11 &= V_2 -> V_92 ;
for ( V_63 = 0 ; V_63 < V_127 ; V_63 ++ )
F_58 ( V_16 , V_63 ) ;
switch ( V_102 ) {
case V_105 :
case V_106 :
F_12 ( V_16 , V_128 ,
F_26 ( V_128 ) | 0x01 ) ;
break;
default:
break;
}
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_87 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_88 ) {
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_89 ) ;
if ( V_4 )
goto V_129;
}
if ( V_2 -> V_90 ) {
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_91 ) ;
if ( V_4 )
goto V_129;
}
if ( V_2 -> V_92 & ( 1 << 0 ) ) {
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_93 ) ;
if ( V_4 )
goto V_129;
}
if ( V_2 -> V_92 & ( 1 << 3 ) ) {
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_94 ) ;
if ( V_4 )
goto V_129;
}
if ( V_2 -> V_92 & ( 1 << 4 ) ) {
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_95 ) ;
if ( V_4 )
goto V_129;
}
if ( V_2 -> V_92 & ( 1 << 5 ) ) {
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_96 ) ;
if ( V_4 )
goto V_129;
}
if ( V_2 -> V_97 ) {
V_2 -> V_69 = F_81 () ;
V_4 = F_80 ( & V_16 -> V_18 . V_86 , & V_98 ) ;
if ( V_4 )
goto V_129;
}
V_2 -> V_130 = F_82 ( & V_16 -> V_18 ) ;
if ( F_83 ( V_2 -> V_130 ) ) {
V_4 = F_84 ( V_2 -> V_130 ) ;
goto V_129;
}
F_85 ( & V_16 -> V_18 , L_13 ,
V_103 [ V_100 -> V_114 ] , V_108 ) ;
if ( ( V_2 -> V_92 & 0x11 ) || V_2 -> V_88 || V_2 -> V_90 )
F_85 ( & V_16 -> V_18 , L_14 ,
( V_2 -> V_92 & ( 1 << 0 ) ) ? L_15 : L_16 ,
( V_2 -> V_92 & ( 1 << 4 ) ) ? L_17 : L_16 ,
V_2 -> V_88 ? L_18 : L_16 ,
V_2 -> V_90 ? L_19 : L_16 ,
V_2 -> V_97 ? L_20 : L_16 ) ;
if ( V_2 -> V_11 )
F_85 ( & V_16 -> V_18 , L_21 ,
( V_2 -> V_11 & ( 1 << 0 ) ) ? L_15 : L_16 ,
( V_2 -> V_11 & ( 1 << 1 ) ) ? L_22 : L_16 ,
( V_2 -> V_11 & ( 1 << 3 ) ) ? L_23 : L_16 ,
( V_2 -> V_11 & ( 1 << 4 ) ) ? L_17 : L_16 ) ;
return 0 ;
V_129:
F_73 ( V_16 , V_2 ) ;
return V_4 ;
}
static int F_86 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_18 ( V_16 ) ;
F_87 ( V_2 -> V_130 ) ;
F_73 ( V_16 , V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_18 ( V_16 ) ;
V_2 -> V_38 [ V_37 ] [ 0 ] = ( T_1 ) F_26 ( V_47 ) ;
V_2 -> V_38 [ V_37 ] [ 1 ] = V_2 -> V_38 [ V_37 ] [ 0 ] ;
V_2 -> V_38 [ V_37 ] [ 2 ] = ( T_1 ) F_26 ( V_48 ) ;
}
static void F_58 ( struct V_15 * V_16 , int V_27 )
{
struct V_1 * V_2 = F_18 ( V_16 ) ;
unsigned int V_131 ;
V_2 -> V_57 [ V_61 ] [ V_27 ] = F_26 ( F_49 ( V_27 ) ) ;
V_131 = ( V_2 -> V_57 [ V_61 ] [ V_27 ] >> 5 ) & 7 ;
if ( V_131 == 3 )
V_2 -> V_59 [ V_27 ] = 0 ;
else if ( V_131 == 7 )
V_2 -> V_59 [ V_27 ] = 1 ;
else if ( V_131 == 4 ) {
V_2 -> V_57 [ V_60 ] [ V_27 ] = 0 ;
V_2 -> V_57 [ V_61 ] [ V_27 ] &= ~ 0xE0 ;
V_2 -> V_57 [ V_61 ] [ V_27 ] |= ( 7 << 5 ) ;
F_12 ( V_16 , F_49 ( V_27 ) ,
V_2 -> V_57 [ V_60 ] [ V_27 ] ) ;
F_12 ( V_16 , F_49 ( V_27 ) ,
V_2 -> V_57 [ V_61 ] [ V_27 ] ) ;
V_2 -> V_59 [ V_27 ] = 1 ;
} else {
V_2 -> V_59 [ V_27 ] = 2 ;
switch ( V_131 ) {
case 0 :
V_2 -> V_58 [ V_27 ] = 1 ;
break;
case 1 :
V_2 -> V_58 [ V_27 ] = 2 ;
break;
case 2 :
V_2 -> V_58 [ V_27 ] = 4 ;
break;
case 5 :
V_2 -> V_58 [ V_27 ] = 6 ;
break;
case 6 :
V_2 -> V_58 [ V_27 ] = 7 ;
break;
}
}
}
static struct V_1 * F_14 ( struct V_17 * V_18 )
{
struct V_15 * V_16 = F_17 ( V_18 ) ;
struct V_1 * V_2 = F_18 ( V_16 ) ;
T_1 V_132 ;
int V_63 ;
F_20 ( & V_2 -> V_31 ) ;
if ( F_88 ( V_133 , V_2 -> V_134 + V_135 * 2 ) ||
! V_2 -> V_136 ) {
V_2 -> V_26 = F_26 ( V_137 ) << 8 ;
V_2 -> V_26 |= F_26 ( V_138 ) ;
V_132 = ( F_26 ( V_139 ) << 8 ) |
F_26 ( V_140 ) ;
for ( V_63 = 0 ; V_63 < V_32 ; V_63 ++ ) {
if ( ! ( V_2 -> V_92 & ( 1 << V_63 ) ) )
continue;
V_2 -> V_28 [ V_60 ] [ V_63 ] =
( F_26 ( F_89 ( V_63 ) ) << 2 ) |
( ( V_132 >> ( V_63 * 2 ) ) & 3 ) ;
}
for ( V_63 = 0 ; V_63 < V_141 ; V_63 ++ )
V_2 -> V_38 [ V_60 ] [ V_63 ] =
( F_26 ( F_90 ( V_63 ) ) << 2 ) |
( ( V_132 >> ( ( V_63 + 5 ) * 2 ) ) & 3 ) ;
if ( V_2 -> V_92 & ( 1 << 5 ) ) {
V_2 -> V_26 |= F_26 ( V_142 ) << 24 ;
V_132 = F_26 ( V_143 ) ;
V_2 -> V_28 [ V_60 ] [ 5 ] = F_26 ( V_144 ) << 2 |
( ( V_132 >> 4 ) & 3 ) ;
}
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
if ( V_63 == 3 && ! V_2 -> V_88 )
continue;
V_2 -> V_8 [ V_60 ] [ V_63 ] =
F_9 ( V_16 , F_91 ( V_63 ) ) ;
}
for ( V_63 = 0 ; V_63 < V_127 ; V_63 ++ ) {
if ( V_63 == 1 && ! V_2 -> V_90 )
continue;
V_2 -> V_57 [ V_60 ] [ V_63 ] = F_26 ( F_50 ( V_63 ) ) ;
}
if ( V_2 -> V_97 )
V_2 -> V_70 = F_26 ( V_120 ) & 0x3f ;
V_2 -> V_134 = V_133 ;
}
if ( F_88 ( V_133 , V_2 -> V_146 + V_135 * 60 ) ||
! V_2 -> V_136 ) {
V_2 -> V_66 = F_26 ( V_68 ) ;
V_2 -> V_5 = F_26 ( V_44 ) ;
for ( V_63 = 0 ; V_63 < V_32 ; V_63 ++ ) {
if ( ! ( V_2 -> V_92 & ( 1 << V_63 ) ) )
continue;
V_2 -> V_28 [ V_33 ] [ V_63 ] =
F_26 ( F_21 ( V_63 ) ) << 2 ;
V_2 -> V_28 [ V_45 ] [ V_63 ] =
F_26 ( F_22 ( V_63 ) ) << 2 ;
}
if ( V_2 -> V_92 & ( 1 << 5 ) ) {
V_2 -> V_28 [ V_33 ] [ 5 ] = F_26 ( V_34 ) << 2 ;
V_2 -> V_28 [ V_45 ] [ 5 ] = F_26 ( V_35 ) << 2 ;
}
for ( V_63 = 0 ; V_63 < V_141 ; V_63 ++ ) {
V_2 -> V_38 [ V_33 ] [ V_63 ] =
F_26 ( F_29 ( V_63 ) ) << 2 ;
V_2 -> V_38 [ V_45 ] [ V_63 ] =
F_26 ( F_30 ( V_63 ) ) << 2 ;
V_2 -> V_38 [ V_46 ] [ V_63 ] =
F_26 ( F_32 ( V_63 ) ) << 2 ;
V_2 -> V_38 [ V_39 ] [ V_63 ] =
F_26 ( F_27 ( V_63 ) ) << 2 ;
V_2 -> V_38 [ V_40 ] [ V_63 ] =
F_26 ( F_31 ( V_63 ) ) ;
}
F_28 ( V_16 ) ;
for ( V_63 = 0 ; V_63 < V_145 ; V_63 ++ ) {
if ( V_63 == 3 && ! V_2 -> V_88 )
continue;
V_2 -> V_8 [ V_33 ] [ V_63 ] =
F_9 ( V_16 , F_44 ( V_63 ) ) ;
}
for ( V_63 = 0 ; V_63 < V_127 ; V_63 ++ ) {
if ( V_63 == 1 && ! V_2 -> V_90 )
continue;
V_2 -> V_57 [ V_45 ] [ V_63 ] = F_26 ( F_52 ( V_63 ) ) ;
V_2 -> V_57 [ V_33 ] [ V_63 ] = F_26 ( F_51 ( V_63 ) ) ;
F_58 ( V_16 , V_63 ) ;
}
V_2 -> V_55 [ 0 ] = F_26 ( F_40 ( 0 ) ) ;
V_2 -> V_55 [ 1 ] = F_26 ( F_40 ( 1 ) ) ;
V_2 -> V_55 [ 2 ] = F_26 ( F_40 ( 2 ) ) ;
V_2 -> V_146 = V_133 ;
V_2 -> V_136 = 1 ;
}
F_23 ( & V_2 -> V_31 ) ;
return V_2 ;
}
