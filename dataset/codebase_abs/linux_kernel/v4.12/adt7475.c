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
static int F_13 ( long V_3 , const int * V_17 , int V_18 )
{
int V_19 ;
if ( V_3 < V_17 [ 0 ] )
return 0 ;
if ( V_3 > V_17 [ V_18 - 1 ] )
return V_18 - 1 ;
for ( V_19 = 0 ; V_19 < V_18 - 1 ; V_19 ++ ) {
int V_20 , V_21 ;
if ( V_3 > V_17 [ V_19 + 1 ] )
continue;
V_20 = V_3 - V_17 [ V_19 ] ;
V_21 = V_17 [ V_19 + 1 ] - V_3 ;
return ( V_20 <= V_21 ) ? V_19 : V_19 + 1 ;
}
return 0 ;
}
static T_3 F_14 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
unsigned short V_3 ;
switch ( V_28 -> V_29 ) {
case V_30 :
return sprintf ( V_26 , L_1 ,
( V_2 -> V_31 >> V_28 -> V_32 ) & 1 ) ;
default:
V_3 = V_2 -> V_33 [ V_28 -> V_29 ] [ V_28 -> V_32 ] ;
return sprintf ( V_26 , L_1 ,
F_6 ( V_28 -> V_32 , V_3 , V_2 -> V_11 ) ) ;
}
}
static T_3 F_17 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_27 * V_28 = F_16 ( V_25 ) ;
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
unsigned char V_7 ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_33 [ V_28 -> V_29 ] [ V_28 -> V_32 ] =
F_8 ( V_28 -> V_32 , V_3 , V_2 -> V_11 ) ;
if ( V_28 -> V_32 < V_37 ) {
if ( V_28 -> V_29 == V_38 )
V_7 = F_22 ( V_28 -> V_32 ) ;
else
V_7 = F_23 ( V_28 -> V_32 ) ;
} else {
if ( V_28 -> V_29 == V_38 )
V_7 = V_39 ;
else
V_7 = V_40 ;
}
F_12 ( V_16 , V_7 ,
V_2 -> V_33 [ V_28 -> V_29 ] [ V_28 -> V_32 ] >> 2 ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_25 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
int V_41 ;
switch ( V_28 -> V_29 ) {
case V_42 :
F_21 ( & V_2 -> V_36 ) ;
V_41 = V_2 -> V_43 [ V_28 -> V_29 ] [ V_28 -> V_32 ] ;
if ( V_28 -> V_32 != 1 )
V_41 = ( V_41 >> 4 ) & 0xF ;
else
V_41 = ( V_41 & 0xF ) ;
V_41 = F_3 ( V_2 , V_2 -> V_43 [ V_44 ] [ V_28 -> V_32 ] ) -
V_41 * 1000 ;
F_24 ( & V_2 -> V_36 ) ;
break;
case V_45 :
F_21 ( & V_2 -> V_36 ) ;
V_41 = ( V_46 ) V_2 -> V_43 [ V_28 -> V_29 ] [ V_28 -> V_32 ] ;
if ( V_2 -> V_5 & V_47 )
V_41 *= 1000 ;
else
V_41 *= 500 ;
F_24 ( & V_2 -> V_36 ) ;
break;
case V_30 :
V_41 = ( V_2 -> V_31 >> ( V_28 -> V_32 + 4 ) ) & 1 ;
break;
case V_48 :
V_41 = ! ! ( V_2 -> V_31 & ( V_28 -> V_32 ? 0x8000 : 0x4000 ) ) ;
break;
default:
V_41 = F_3 ( V_2 , V_2 -> V_43 [ V_28 -> V_29 ] [ V_28 -> V_32 ] ) ;
}
return sprintf ( V_26 , L_1 , V_41 ) ;
}
static T_3 F_26 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_27 * V_28 = F_16 ( V_25 ) ;
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
unsigned char V_7 = 0 ;
T_2 V_41 ;
int V_43 ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_5 = F_27 ( V_49 ) ;
switch ( V_28 -> V_29 ) {
case V_45 :
if ( V_2 -> V_5 & V_47 ) {
V_3 = F_2 ( V_3 , - 63000 , 127000 ) ;
V_41 = V_2 -> V_43 [ V_45 ] [ V_28 -> V_32 ] = V_3 / 1000 ;
} else {
V_3 = F_2 ( V_3 , - 63000 , 64000 ) ;
V_41 = V_2 -> V_43 [ V_45 ] [ V_28 -> V_32 ] = V_3 / 500 ;
}
break;
case V_42 :
V_2 -> V_43 [ V_44 ] [ V_28 -> V_32 ] =
F_27 ( F_28 ( V_28 -> V_32 ) ) << 2 ;
F_29 ( V_16 ) ;
V_43 = F_3 ( V_2 , V_2 -> V_43 [ V_44 ] [ V_28 -> V_32 ] ) ;
V_3 = F_2 ( V_3 , V_43 - 15000 , V_43 ) ;
V_3 = ( V_43 - V_3 ) / 1000 ;
if ( V_28 -> V_32 != 1 ) {
V_2 -> V_43 [ V_42 ] [ V_28 -> V_32 ] &= 0xF0 ;
V_2 -> V_43 [ V_42 ] [ V_28 -> V_32 ] |= ( V_3 & 0xF ) << 4 ;
} else {
V_2 -> V_43 [ V_42 ] [ V_28 -> V_32 ] &= 0x0F ;
V_2 -> V_43 [ V_42 ] [ V_28 -> V_32 ] |= ( V_3 & 0xF ) ;
}
V_41 = V_2 -> V_43 [ V_42 ] [ V_28 -> V_32 ] ;
break;
default:
V_2 -> V_43 [ V_28 -> V_29 ] [ V_28 -> V_32 ] = F_1 ( V_2 , V_3 ) ;
V_41 = ( T_2 ) ( V_2 -> V_43 [ V_28 -> V_29 ] [ V_28 -> V_32 ] >> 2 ) ;
}
switch ( V_28 -> V_29 ) {
case V_38 :
V_7 = F_30 ( V_28 -> V_32 ) ;
break;
case V_50 :
V_7 = F_31 ( V_28 -> V_32 ) ;
break;
case V_45 :
V_7 = F_32 ( V_28 -> V_32 ) ;
break;
case V_51 :
V_7 = F_33 ( V_28 -> V_32 ) ;
break;
case V_44 :
V_7 = F_28 ( V_28 -> V_32 ) ;
break;
case V_42 :
if ( V_28 -> V_32 != 2 )
V_7 = V_52 ;
else
V_7 = V_53 ;
break;
}
F_12 ( V_16 , V_7 , V_41 ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_34 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
int V_41 , V_3 ;
F_21 ( & V_2 -> V_36 ) ;
V_41 = ( V_2 -> V_54 [ V_28 -> V_32 ] >> 4 ) & 0x0F ;
V_3 = F_3 ( V_2 , V_2 -> V_43 [ V_51 ] [ V_28 -> V_32 ] ) ;
F_24 ( & V_2 -> V_36 ) ;
return sprintf ( V_26 , L_1 , V_3 + V_55 [ V_41 ] ) ;
}
static T_3 F_35 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
int V_43 ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_5 = F_27 ( V_49 ) ;
V_2 -> V_43 [ V_51 ] [ V_28 -> V_32 ] =
F_27 ( F_33 ( V_28 -> V_32 ) ) << 2 ;
V_2 -> V_54 [ V_28 -> V_32 ] =
F_27 ( F_36 ( V_28 -> V_32 ) ) ;
V_43 = F_3 ( V_2 , V_2 -> V_43 [ V_51 ] [ V_28 -> V_32 ] ) ;
V_3 = F_2 ( V_3 , V_43 + V_55 [ 0 ] ,
V_43 + V_55 [ F_37 ( V_55 ) - 1 ] ) ;
V_3 -= V_43 ;
V_3 = F_13 ( V_3 , V_55 , F_37 ( V_55 ) ) ;
V_2 -> V_54 [ V_28 -> V_32 ] &= ~ 0xF0 ;
V_2 -> V_54 [ V_28 -> V_32 ] |= V_3 << 4 ;
F_12 ( V_16 , F_36 ( V_28 -> V_32 ) ,
V_2 -> V_54 [ V_28 -> V_32 ] ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_38 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
int V_41 ;
if ( V_28 -> V_29 == V_30 )
V_41 = ( V_2 -> V_31 >> ( V_28 -> V_32 + 10 ) ) & 1 ;
else
V_41 = F_4 ( V_2 -> V_8 [ V_28 -> V_29 ] [ V_28 -> V_32 ] ) ;
return sprintf ( V_26 , L_1 , V_41 ) ;
}
static T_3 F_39 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_27 * V_28 = F_16 ( V_25 ) ;
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
unsigned long V_3 ;
if ( F_40 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_8 [ V_38 ] [ V_28 -> V_32 ] = F_5 ( V_3 ) ;
F_11 ( V_16 , F_41 ( V_28 -> V_32 ) ,
V_2 -> V_8 [ V_38 ] [ V_28 -> V_32 ] ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_42 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
return sprintf ( V_26 , L_1 , V_2 -> V_56 [ V_28 -> V_29 ] [ V_28 -> V_32 ] ) ;
}
static T_3 F_43 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
return sprintf ( V_26 , L_1 , V_2 -> V_57 [ V_28 -> V_32 ] ) ;
}
static T_3 F_44 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
return sprintf ( V_26 , L_1 , V_2 -> V_58 [ V_28 -> V_32 ] ) ;
}
static T_3 F_45 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_27 * V_28 = F_16 ( V_25 ) ;
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
unsigned char V_7 = 0 ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
switch ( V_28 -> V_29 ) {
case V_59 :
V_2 -> V_56 [ V_60 ] [ V_28 -> V_32 ] =
F_27 ( F_46 ( V_28 -> V_32 ) ) ;
if ( ( ( V_2 -> V_56 [ V_60 ] [ V_28 -> V_32 ] >> 5 ) & 7 ) != 7 ) {
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
V_7 = F_47 ( V_28 -> V_32 ) ;
break;
case V_38 :
V_7 = F_48 ( V_28 -> V_32 ) ;
break;
case V_50 :
V_7 = F_49 ( V_28 -> V_32 ) ;
break;
}
V_2 -> V_56 [ V_28 -> V_29 ] [ V_28 -> V_32 ] = F_2 ( V_3 , 0 , 0xFF ) ;
F_12 ( V_16 , V_7 ,
V_2 -> V_56 [ V_28 -> V_29 ] [ V_28 -> V_32 ] ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static int F_50 ( struct V_15 * V_16 , int V_32 ,
unsigned int V_58 , unsigned int V_57 )
{
struct V_1 * V_2 = F_19 ( V_16 ) ;
long V_3 = 0 ;
switch ( V_58 ) {
case 0 :
V_3 = 0x03 ;
break;
case 1 :
V_3 = 0x07 ;
break;
case 2 :
switch ( V_57 ) {
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
return - V_35 ;
}
break;
default:
return - V_35 ;
}
V_2 -> V_58 [ V_32 ] = V_58 ;
V_2 -> V_57 [ V_32 ] = V_57 ;
V_2 -> V_56 [ V_60 ] [ V_32 ] &= ~ 0xE0 ;
V_2 -> V_56 [ V_60 ] [ V_32 ] |= ( V_3 & 7 ) << 5 ;
F_12 ( V_16 , F_46 ( V_32 ) ,
V_2 -> V_56 [ V_60 ] [ V_32 ] ) ;
return 0 ;
}
static T_3 F_51 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_27 * V_28 = F_16 ( V_25 ) ;
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
int V_12 ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
F_52 ( V_16 , V_28 -> V_32 ) ;
V_12 = F_50 ( V_16 , V_28 -> V_32 , V_2 -> V_58 [ V_28 -> V_32 ] , V_3 ) ;
if ( V_12 )
V_34 = V_12 ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_53 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_27 * V_28 = F_16 ( V_25 ) ;
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
int V_12 ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
F_52 ( V_16 , V_28 -> V_32 ) ;
V_12 = F_50 ( V_16 , V_28 -> V_32 , V_3 , V_2 -> V_57 [ V_28 -> V_32 ] ) ;
if ( V_12 )
V_34 = V_12 ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_54 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_27 * V_28 = F_16 ( V_25 ) ;
return sprintf ( V_26 , L_1 ,
V_61 [ V_2 -> V_54 [ V_28 -> V_32 ] & 7 ] ) ;
}
static T_3 F_55 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_4 V_34 )
{
struct V_27 * V_28 = F_16 ( V_25 ) ;
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
int V_41 ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
V_41 = F_13 ( V_3 , V_61 , F_37 ( V_61 ) ) ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_54 [ V_28 -> V_32 ] =
F_27 ( F_36 ( V_28 -> V_32 ) ) ;
V_2 -> V_54 [ V_28 -> V_32 ] &= ~ 7 ;
V_2 -> V_54 [ V_28 -> V_32 ] |= V_41 ;
F_12 ( V_16 , F_36 ( V_28 -> V_32 ) ,
V_2 -> V_54 [ V_28 -> V_32 ] ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_56 ( struct V_22 * V_23 ,
struct V_24 * V_62 ,
char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
return sprintf ( V_26 , L_1 , ! ! ( V_2 -> V_63 & V_64 ) ) ;
}
static T_3 F_57 ( struct V_22 * V_23 ,
struct V_24 * V_62 ,
const char * V_26 , T_4 V_34 )
{
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
if ( V_3 != 0 && V_3 != 1 )
return - V_35 ;
F_21 ( & V_2 -> V_36 ) ;
V_2 -> V_63 = F_10 ( V_16 , V_65 ) ;
if ( V_3 )
V_2 -> V_63 |= V_64 ;
else
V_2 -> V_63 &= ~ V_64 ;
F_12 ( V_16 , V_65 , V_2 -> V_63 ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_34 ;
}
static T_3 F_58 ( struct V_22 * V_23 , struct V_24 * V_62 ,
char * V_26 )
{
struct V_1 * V_2 = F_59 ( V_23 ) ;
return sprintf ( V_26 , L_1 , ( int ) V_2 -> V_66 ) ;
}
static T_3 F_60 ( struct V_22 * V_23 , struct V_24 * V_62 ,
const char * V_26 , T_4 V_34 )
{
struct V_1 * V_2 = F_59 ( V_23 ) ;
long V_3 ;
if ( F_20 ( V_26 , 10 , & V_3 ) )
return - V_35 ;
if ( V_3 < 0 || V_3 > 255 )
return - V_35 ;
V_2 -> V_66 = V_3 ;
return V_34 ;
}
static T_3 F_61 ( struct V_22 * V_23 ,
struct V_24 * V_62 , char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
return sprintf ( V_26 , L_1 , F_62 ( V_2 -> V_67 , V_2 -> V_66 ) ) ;
}
static int F_63 ( struct V_15 * V_16 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 = V_16 -> V_71 ;
int V_72 , V_73 , V_74 ;
const char * V_75 ;
if ( ! F_64 ( V_71 , V_76 ) )
return - V_77 ;
V_72 = F_27 ( V_78 ) ;
V_74 = F_27 ( V_79 ) ;
if ( V_72 != 0x41 ||
( V_74 & 0xf8 ) != 0x68 )
return - V_77 ;
V_73 = F_27 ( V_80 ) ;
if ( V_73 == 0x73 )
V_75 = L_2 ;
else if ( V_73 == 0x75 && V_16 -> V_81 == 0x2e )
V_75 = L_3 ;
else if ( V_73 == 0x76 )
V_75 = L_4 ;
else if ( ( V_74 & 0xfc ) == 0x6c )
V_75 = L_5 ;
else {
F_65 ( & V_71 -> V_23 ,
L_6
L_7 , ( unsigned int ) V_16 -> V_81 ) ;
return - V_77 ;
}
F_66 ( V_69 -> type , V_75 , V_82 ) ;
return 0 ;
}
static void F_67 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_68 ( & V_16 -> V_23 . V_83 , & V_84 ) ;
if ( V_2 -> V_85 )
F_68 ( & V_16 -> V_23 . V_83 , & V_86 ) ;
if ( V_2 -> V_87 )
F_68 ( & V_16 -> V_23 . V_83 , & V_88 ) ;
if ( V_2 -> V_89 & ( 1 << 0 ) )
F_68 ( & V_16 -> V_23 . V_83 , & V_90 ) ;
if ( V_2 -> V_89 & ( 1 << 3 ) )
F_68 ( & V_16 -> V_23 . V_83 , & V_91 ) ;
if ( V_2 -> V_89 & ( 1 << 4 ) )
F_68 ( & V_16 -> V_23 . V_83 , & V_92 ) ;
if ( V_2 -> V_89 & ( 1 << 5 ) )
F_68 ( & V_16 -> V_23 . V_83 , & V_93 ) ;
if ( V_2 -> V_94 )
F_68 ( & V_16 -> V_23 . V_83 , & V_95 ) ;
}
static int F_69 ( struct V_15 * V_16 ,
const struct V_96 * V_97 )
{
enum V_98 V_99 ;
static const char * const V_100 [] = {
[ V_101 ] = L_8 ,
[ V_102 ] = L_9 ,
[ V_103 ] = L_10 ,
[ V_104 ] = L_11 ,
} ;
struct V_1 * V_2 ;
int V_19 , V_4 = 0 , V_105 ;
T_2 V_106 , V_107 ;
V_2 = F_70 ( & V_16 -> V_23 , sizeof( * V_2 ) , V_108 ) ;
if ( V_2 == NULL )
return - V_109 ;
F_71 ( & V_2 -> V_36 ) ;
F_72 ( V_16 , V_2 ) ;
if ( V_16 -> V_23 . V_110 )
V_99 = (enum V_98 ) F_73 ( & V_16 -> V_23 ) ;
else
V_99 = V_97 -> V_111 ;
switch ( V_99 ) {
case V_103 :
V_2 -> V_89 = 0x0e ;
V_105 = F_27 ( V_79 ) & 0x07 ;
break;
case V_104 :
V_2 -> V_89 = 0x3e ;
V_105 = F_27 ( V_79 ) & 0x03 ;
if ( V_105 == 0x03 )
V_105 += F_27 ( V_112 ) ;
break;
default:
V_2 -> V_89 = 0x06 ;
V_105 = F_27 ( V_79 ) & 0x07 ;
}
V_107 = F_27 ( V_113 ) ;
if ( ! ( V_107 & V_114 ) )
V_2 -> V_87 = 1 ;
if ( V_97 -> V_111 == V_101 && V_105 >= 1 )
V_2 -> V_87 = ! V_2 -> V_87 ;
V_2 -> V_63 = F_27 ( V_65 ) ;
if ( ( V_2 -> V_63 & V_115 ) == 0x0 )
V_2 -> V_85 = 1 ;
if ( V_97 -> V_111 == V_104 ) {
if ( ( V_2 -> V_63 & V_115 ) == 0x1 &&
! ( V_107 & V_116 ) )
V_2 -> V_85 = 1 ;
}
if ( V_97 -> V_111 == V_103 || V_97 -> V_111 == V_104 ) {
if ( ! ( V_107 & V_116 ) ||
( V_2 -> V_63 & V_115 ) == 0x1 )
V_2 -> V_89 |= ( 1 << 0 ) ;
}
if ( V_97 -> V_111 == V_103 ) {
T_2 V_67 = F_27 ( V_117 ) ;
if ( ! ( V_67 & V_118 ) )
V_2 -> V_89 |= ( 1 << 4 ) ;
V_2 -> V_94 = ! ( F_27 ( V_49 ) & V_119 ) ;
}
V_106 = F_27 ( V_120 ) ;
if ( V_106 & V_121 ) {
V_2 -> V_11 = ( 0x3 << 3 ) | 0x3 ;
} else {
V_2 -> V_11 = ( ( V_2 -> V_63 & V_122 ) >> 4 ) |
( ( V_2 -> V_63 & V_123 ) >> 3 ) ;
}
V_2 -> V_11 &= V_2 -> V_89 ;
for ( V_19 = 0 ; V_19 < V_124 ; V_19 ++ )
F_52 ( V_16 , V_19 ) ;
switch ( V_99 ) {
case V_102 :
case V_103 :
F_12 ( V_16 , V_125 ,
F_27 ( V_125 ) | 0x01 ) ;
break;
default:
break;
}
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_84 ) ;
if ( V_4 )
return V_4 ;
if ( V_2 -> V_85 ) {
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_86 ) ;
if ( V_4 )
goto V_126;
}
if ( V_2 -> V_87 ) {
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_88 ) ;
if ( V_4 )
goto V_126;
}
if ( V_2 -> V_89 & ( 1 << 0 ) ) {
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_90 ) ;
if ( V_4 )
goto V_126;
}
if ( V_2 -> V_89 & ( 1 << 3 ) ) {
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_91 ) ;
if ( V_4 )
goto V_126;
}
if ( V_2 -> V_89 & ( 1 << 4 ) ) {
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_92 ) ;
if ( V_4 )
goto V_126;
}
if ( V_2 -> V_89 & ( 1 << 5 ) ) {
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_93 ) ;
if ( V_4 )
goto V_126;
}
if ( V_2 -> V_94 ) {
V_2 -> V_66 = F_75 () ;
V_4 = F_74 ( & V_16 -> V_23 . V_83 , & V_95 ) ;
if ( V_4 )
goto V_126;
}
V_2 -> V_127 = F_76 ( & V_16 -> V_23 ) ;
if ( F_77 ( V_2 -> V_127 ) ) {
V_4 = F_78 ( V_2 -> V_127 ) ;
goto V_126;
}
F_79 ( & V_16 -> V_23 , L_12 ,
V_100 [ V_97 -> V_111 ] , V_105 ) ;
if ( ( V_2 -> V_89 & 0x11 ) || V_2 -> V_85 || V_2 -> V_87 )
F_79 ( & V_16 -> V_23 , L_13 ,
( V_2 -> V_89 & ( 1 << 0 ) ) ? L_14 : L_15 ,
( V_2 -> V_89 & ( 1 << 4 ) ) ? L_16 : L_15 ,
V_2 -> V_85 ? L_17 : L_15 ,
V_2 -> V_87 ? L_18 : L_15 ,
V_2 -> V_94 ? L_19 : L_15 ) ;
if ( V_2 -> V_11 )
F_79 ( & V_16 -> V_23 , L_20 ,
( V_2 -> V_11 & ( 1 << 0 ) ) ? L_14 : L_15 ,
( V_2 -> V_11 & ( 1 << 1 ) ) ? L_21 : L_15 ,
( V_2 -> V_11 & ( 1 << 3 ) ) ? L_22 : L_15 ,
( V_2 -> V_11 & ( 1 << 4 ) ) ? L_16 : L_15 ) ;
return 0 ;
V_126:
F_67 ( V_16 , V_2 ) ;
return V_4 ;
}
static int F_80 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_19 ( V_16 ) ;
F_81 ( V_2 -> V_127 ) ;
F_67 ( V_16 , V_2 ) ;
return 0 ;
}
static void F_29 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_19 ( V_16 ) ;
V_2 -> V_43 [ V_42 ] [ 0 ] = ( T_1 ) F_27 ( V_52 ) ;
V_2 -> V_43 [ V_42 ] [ 1 ] = V_2 -> V_43 [ V_42 ] [ 0 ] ;
V_2 -> V_43 [ V_42 ] [ 2 ] = ( T_1 ) F_27 ( V_53 ) ;
}
static void F_52 ( struct V_15 * V_16 , int V_32 )
{
struct V_1 * V_2 = F_19 ( V_16 ) ;
unsigned int V_128 ;
V_2 -> V_56 [ V_60 ] [ V_32 ] = F_27 ( F_46 ( V_32 ) ) ;
V_128 = ( V_2 -> V_56 [ V_60 ] [ V_32 ] >> 5 ) & 7 ;
if ( V_128 == 3 )
V_2 -> V_58 [ V_32 ] = 0 ;
else if ( V_128 == 7 )
V_2 -> V_58 [ V_32 ] = 1 ;
else if ( V_128 == 4 ) {
V_2 -> V_56 [ V_59 ] [ V_32 ] = 0 ;
V_2 -> V_56 [ V_60 ] [ V_32 ] &= ~ 0xE0 ;
V_2 -> V_56 [ V_60 ] [ V_32 ] |= ( 7 << 5 ) ;
F_12 ( V_16 , F_46 ( V_32 ) ,
V_2 -> V_56 [ V_59 ] [ V_32 ] ) ;
F_12 ( V_16 , F_46 ( V_32 ) ,
V_2 -> V_56 [ V_60 ] [ V_32 ] ) ;
V_2 -> V_58 [ V_32 ] = 1 ;
} else {
V_2 -> V_58 [ V_32 ] = 2 ;
switch ( V_128 ) {
case 0 :
V_2 -> V_57 [ V_32 ] = 1 ;
break;
case 1 :
V_2 -> V_57 [ V_32 ] = 2 ;
break;
case 2 :
V_2 -> V_57 [ V_32 ] = 4 ;
break;
case 5 :
V_2 -> V_57 [ V_32 ] = 6 ;
break;
case 6 :
V_2 -> V_57 [ V_32 ] = 7 ;
break;
}
}
}
static struct V_1 * F_15 ( struct V_22 * V_23 )
{
struct V_15 * V_16 = F_18 ( V_23 ) ;
struct V_1 * V_2 = F_19 ( V_16 ) ;
T_1 V_129 ;
int V_19 ;
F_21 ( & V_2 -> V_36 ) ;
if ( F_82 ( V_130 , V_2 -> V_131 + V_132 * 2 ) ||
! V_2 -> V_133 ) {
V_2 -> V_31 = F_27 ( V_134 ) << 8 ;
V_2 -> V_31 |= F_27 ( V_135 ) ;
V_129 = ( F_27 ( V_136 ) << 8 ) |
F_27 ( V_137 ) ;
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ ) {
if ( ! ( V_2 -> V_89 & ( 1 << V_19 ) ) )
continue;
V_2 -> V_33 [ V_59 ] [ V_19 ] =
( F_27 ( F_83 ( V_19 ) ) << 2 ) |
( ( V_129 >> ( V_19 * 2 ) ) & 3 ) ;
}
for ( V_19 = 0 ; V_19 < V_138 ; V_19 ++ )
V_2 -> V_43 [ V_59 ] [ V_19 ] =
( F_27 ( F_84 ( V_19 ) ) << 2 ) |
( ( V_129 >> ( ( V_19 + 5 ) * 2 ) ) & 3 ) ;
if ( V_2 -> V_89 & ( 1 << 5 ) ) {
V_2 -> V_31 |= F_27 ( V_139 ) << 24 ;
V_129 = F_27 ( V_140 ) ;
V_2 -> V_33 [ V_59 ] [ 5 ] = F_27 ( V_141 ) << 2 |
( ( V_129 >> 4 ) & 3 ) ;
}
for ( V_19 = 0 ; V_19 < V_142 ; V_19 ++ ) {
if ( V_19 == 3 && ! V_2 -> V_85 )
continue;
V_2 -> V_8 [ V_59 ] [ V_19 ] =
F_9 ( V_16 , F_85 ( V_19 ) ) ;
}
for ( V_19 = 0 ; V_19 < V_124 ; V_19 ++ ) {
if ( V_19 == 1 && ! V_2 -> V_87 )
continue;
V_2 -> V_56 [ V_59 ] [ V_19 ] = F_27 ( F_47 ( V_19 ) ) ;
}
if ( V_2 -> V_94 )
V_2 -> V_67 = F_27 ( V_117 ) & 0x3f ;
V_2 -> V_131 = V_130 ;
}
if ( F_82 ( V_130 , V_2 -> V_143 + V_132 * 60 ) ||
! V_2 -> V_133 ) {
V_2 -> V_63 = F_27 ( V_65 ) ;
V_2 -> V_5 = F_27 ( V_49 ) ;
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ ) {
if ( ! ( V_2 -> V_89 & ( 1 << V_19 ) ) )
continue;
V_2 -> V_33 [ V_38 ] [ V_19 ] =
F_27 ( F_22 ( V_19 ) ) << 2 ;
V_2 -> V_33 [ V_50 ] [ V_19 ] =
F_27 ( F_23 ( V_19 ) ) << 2 ;
}
if ( V_2 -> V_89 & ( 1 << 5 ) ) {
V_2 -> V_33 [ V_38 ] [ 5 ] = F_27 ( V_39 ) << 2 ;
V_2 -> V_33 [ V_50 ] [ 5 ] = F_27 ( V_40 ) << 2 ;
}
for ( V_19 = 0 ; V_19 < V_138 ; V_19 ++ ) {
V_2 -> V_43 [ V_38 ] [ V_19 ] =
F_27 ( F_30 ( V_19 ) ) << 2 ;
V_2 -> V_43 [ V_50 ] [ V_19 ] =
F_27 ( F_31 ( V_19 ) ) << 2 ;
V_2 -> V_43 [ V_51 ] [ V_19 ] =
F_27 ( F_33 ( V_19 ) ) << 2 ;
V_2 -> V_43 [ V_44 ] [ V_19 ] =
F_27 ( F_28 ( V_19 ) ) << 2 ;
V_2 -> V_43 [ V_45 ] [ V_19 ] =
F_27 ( F_32 ( V_19 ) ) ;
}
F_29 ( V_16 ) ;
for ( V_19 = 0 ; V_19 < V_142 ; V_19 ++ ) {
if ( V_19 == 3 && ! V_2 -> V_85 )
continue;
V_2 -> V_8 [ V_38 ] [ V_19 ] =
F_9 ( V_16 , F_41 ( V_19 ) ) ;
}
for ( V_19 = 0 ; V_19 < V_124 ; V_19 ++ ) {
if ( V_19 == 1 && ! V_2 -> V_87 )
continue;
V_2 -> V_56 [ V_50 ] [ V_19 ] = F_27 ( F_49 ( V_19 ) ) ;
V_2 -> V_56 [ V_38 ] [ V_19 ] = F_27 ( F_48 ( V_19 ) ) ;
F_52 ( V_16 , V_19 ) ;
}
V_2 -> V_54 [ 0 ] = F_27 ( F_36 ( 0 ) ) ;
V_2 -> V_54 [ 1 ] = F_27 ( F_36 ( 1 ) ) ;
V_2 -> V_54 [ 2 ] = F_27 ( F_36 ( 2 ) ) ;
V_2 -> V_143 = V_130 ;
V_2 -> V_133 = 1 ;
}
F_24 ( & V_2 -> V_36 ) ;
return V_2 ;
}
