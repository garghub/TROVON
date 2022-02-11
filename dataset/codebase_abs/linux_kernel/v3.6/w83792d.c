static inline T_1
F_1 ( long V_1 , int div )
{
if ( V_1 == 0 )
return 255 ;
V_1 = F_2 ( V_1 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_1 * div / 2 ) / ( V_1 * div ) , 1 , 254 ) ;
}
static inline T_1
F_3 ( long V_2 )
{
int V_3 ;
V_2 = F_2 ( V_2 , 1 , 128 ) >> 1 ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
if ( V_2 == 0 )
break;
V_2 >>= 1 ;
}
return ( T_1 ) V_3 ;
}
static inline long F_4 ( int V_4 , struct V_5 * V_6 )
{
return ( V_6 -> V_7 [ V_4 ] << 2 ) | ( ( V_6 -> V_8 >> ( 2 * V_4 ) ) & 0x03 ) ;
}
static inline int F_5 ( struct V_9 * V_10 , T_1 V_11 )
{
return F_6 ( V_10 , V_11 ) ;
}
static inline int
F_7 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 )
{
return F_8 ( V_10 , V_11 , V_12 ) ;
}
static T_2 F_9 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 ,
F_12 ( V_4 , F_4 ( V_4 , V_6 ) ) ) ;
}
static T_2
F_13 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_24 [ V_4 ] = F_1 ( V_2 , F_18 ( V_6 -> V_25 [ V_4 ] ) ) ;
F_7 ( V_10 , V_26 [ V_4 ] ,
V_6 -> V_24 [ V_4 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_20 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_2 , F_18 ( V_6 -> V_25 [ V_4 - 1 ] ) ) ;
}
static T_2
F_21 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
unsigned long V_27 ;
T_1 V_28 = 0 ;
T_1 V_29 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_27 = F_22 ( V_6 -> V_24 [ V_4 ] ,
F_18 ( V_6 -> V_25 [ V_4 ] ) ) ;
V_6 -> V_25 [ V_4 ] = F_3 ( V_2 ) ;
V_28 = F_5 ( V_10 , V_30 [ V_4 >> 1 ] ) ;
V_28 &= ( V_4 & 0x01 ) ? 0x8f : 0xf8 ;
V_29 = ( V_4 & 0x01 ) ? ( ( ( V_6 -> V_25 [ V_4 ] ) << 4 ) & 0x70 )
: ( ( V_6 -> V_25 [ V_4 ] ) & 0x07 ) ;
F_7 ( V_10 , V_30 [ V_4 >> 1 ] ,
V_28 | V_29 ) ;
V_6 -> V_24 [ V_4 ] = F_1 ( V_27 , F_18 ( V_6 -> V_25 [ V_4 ] ) ) ;
F_7 ( V_10 , V_26 [ V_4 ] , V_6 -> V_24 [ V_4 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2 F_23 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 , F_24 ( V_6 -> V_31 [ V_4 ] ) ) ;
}
static T_2 F_25 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
long V_2 ;
int V_22 ;
V_22 = F_26 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_31 [ V_4 ] = F_27 ( V_2 ) ;
F_7 ( V_10 , V_32 [ V_4 ] ,
V_6 -> V_31 [ V_4 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2 F_28 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 ,
( long ) F_30 ( V_6 -> V_34 [ V_4 ] [ V_20 ] ,
V_6 -> V_34 [ V_4 ] [ V_20 + 1 ] ) ) ;
}
static T_2 F_31 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
long V_2 ;
int V_22 ;
V_22 = F_26 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_34 [ V_4 ] [ V_20 ] = F_32 ( V_2 ) ;
V_6 -> V_34 [ V_4 ] [ V_20 + 1 ] = F_33 ( V_2 ) ;
F_7 ( V_10 , V_35 [ V_4 ] [ V_20 ] ,
V_6 -> V_34 [ V_4 ] [ V_20 ] ) ;
F_7 ( V_10 , V_35 [ V_4 ] [ V_20 + 1 ] ,
V_6 -> V_34 [ V_4 ] [ V_20 + 1 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_34 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 , V_6 -> V_36 ) ;
}
static T_2 F_35 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 , ( V_6 -> V_36 >> V_4 ) & 1 ) ;
}
static T_2
F_36 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 , ( V_6 -> V_37 [ V_4 ] & 0x0f ) << 4 ) ;
}
static T_2
F_37 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
long V_38 = 1 ;
switch ( V_6 -> V_39 [ V_4 ] ) {
case 0 :
V_38 = 1 ;
break;
case 1 :
V_38 = 3 ;
break;
case 2 :
V_38 = 2 ;
break;
}
return sprintf ( V_17 , L_1 , V_38 ) ;
}
static T_2
F_38 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
V_2 = F_2 ( V_2 , 0 , 255 ) >> 4 ;
F_17 ( & V_6 -> V_23 ) ;
V_2 |= F_5 ( V_10 , V_40 [ V_4 ] ) & 0xf0 ;
V_6 -> V_37 [ V_4 ] = V_2 ;
F_7 ( V_10 , V_40 [ V_4 ] , V_6 -> V_37 [ V_4 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_39 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_41 , V_42 , V_43 , V_44 , V_45 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
if ( V_2 < 1 || V_2 > 3 )
return - V_46 ;
F_17 ( & V_6 -> V_23 ) ;
switch ( V_2 ) {
case 1 :
V_6 -> V_39 [ V_4 ] = 0 ;
break;
case 2 :
V_6 -> V_39 [ V_4 ] = 2 ;
break;
case 3 :
V_6 -> V_39 [ V_4 ] = 1 ;
break;
}
V_42 = V_6 -> V_39 [ 0 ] ;
V_43 = ( V_6 -> V_39 [ 1 ] ) << 2 ;
V_44 = ( V_6 -> V_39 [ 2 ] ) << 4 ;
V_45 = F_5 ( V_10 , V_47 ) & 0xc0 ;
V_41 = ( ( V_45 | V_44 ) | V_43 ) | V_42 ;
F_7 ( V_10 , V_47 , V_41 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_40 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 , V_6 -> V_37 [ V_4 ] >> 7 ) ;
}
static T_2
F_41 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
if ( V_2 > 1 )
return - V_46 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_37 [ V_4 ] = F_5 ( V_10 , V_40 [ V_4 ] ) ;
if ( V_2 ) {
V_6 -> V_37 [ V_4 ] |= 0x80 ;
} else {
V_6 -> V_37 [ V_4 ] &= 0x7f ;
}
F_7 ( V_10 , V_40 [ V_4 ] , V_6 -> V_37 [ V_4 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_42 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 , V_6 -> V_48 ) ;
}
static T_2
F_43 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
F_44 ( V_14 ,
L_4 ,
L_5 ) ;
return F_42 ( V_14 , V_16 , V_17 ) ;
}
static T_2
F_45 ( struct V_13 * V_14 , struct V_15 * V_16 , char * V_17 )
{
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 , V_6 -> V_49 ) ;
}
static T_2
F_46 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
unsigned long V_2 ;
int V_22 ;
T_1 V_31 = 0 , V_50 = 0 ;
F_44 ( V_14 ,
L_4 ,
L_6 ) ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_49 = F_2 ( V_2 , 0 , 1 ) ;
V_31 = ( ( V_6 -> V_49 ) << 7 ) & 0x80 ;
V_50 = F_5 ( V_10 ,
V_51 ) & 0x7f ;
F_7 ( V_10 , V_51 , V_31 | V_50 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_47 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
unsigned long V_2 ;
T_1 V_11 ;
if ( F_16 ( V_17 , 10 , & V_2 ) || V_2 != 0 )
return - V_46 ;
F_17 ( & V_6 -> V_23 ) ;
V_11 = F_5 ( V_10 , V_51 ) ;
F_7 ( V_10 , V_51 , V_11 | 0x80 ) ;
V_6 -> V_52 = 0 ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_48 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 , ( long ) V_6 -> V_53 [ V_4 - 1 ] ) ;
}
static T_2
F_49 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_54 = 0 , V_55 = 0 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
V_54 = V_2 ;
V_54 = V_54 & 0x7f ;
F_17 ( & V_6 -> V_23 ) ;
V_55 = F_5 ( V_10 ,
V_56 [ V_4 ] ) & 0x80 ;
V_6 -> V_53 [ V_4 ] = F_2 ( V_54 , 0 , 255 ) ;
F_7 ( V_10 , V_56 [ V_4 ] ,
( V_6 -> V_53 [ V_4 ] ) | V_55 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_50 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 , ( long ) V_6 -> V_57 [ V_4 - 1 ] ) ;
}
static T_2
F_51 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_58 , V_59 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_59 = F_5 ( V_10 ,
V_60 [ V_4 ] ) & ( ( V_4 == 1 ) ? 0x0f : 0xf0 ) ;
V_58 = F_2 ( V_2 , 0 , 15 ) ;
V_58 &= 0x0f ;
V_6 -> V_57 [ V_4 ] = V_58 ;
if ( V_4 == 1 )
V_58 <<= 4 ;
F_7 ( V_10 , V_60 [ V_4 ] ,
V_59 | V_58 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_52 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 , ( long ) V_6 -> V_61 [ V_20 - 1 ] [ V_4 - 1 ] ) ;
}
static T_2
F_53 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 - 1 ;
int V_20 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_62 = 0 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_61 [ V_20 ] [ V_4 ] = F_2 ( V_2 , 0 , 127 ) ;
V_62 = F_5 ( V_10 ,
V_63 [ V_20 ] [ V_4 ] ) & 0x80 ;
F_7 ( V_10 , V_63 [ V_20 ] [ V_4 ] ,
V_62 | V_6 -> V_61 [ V_20 ] [ V_4 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_54 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 ,
( ( ( V_6 -> V_64 [ V_20 - 1 ] [ V_4 ] ) * 100 ) / 15 ) ) ;
}
static T_2
F_55 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_62 = 0 , V_65 = 0 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_64 [ V_20 ] [ V_4 ] = F_2 ( ( V_2 * 15 ) / 100 , 0 , 15 ) ;
V_62 = F_5 ( V_10 , V_66 [ V_20 ] [ V_4 ] )
& ( ( V_4 == 3 ) ? 0xf0 : 0x0f ) ;
if ( V_4 == 3 )
V_65 = V_6 -> V_64 [ V_20 ] [ V_4 ] ;
else
V_65 = V_6 -> V_64 [ V_20 ] [ V_4 ] << 4 ;
F_7 ( V_10 , V_66 [ V_20 ] [ V_4 ] ,
V_65 | V_62 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static int
F_56 ( struct V_9 * V_67 )
{
int V_3 , V_68 , V_22 ;
int V_69 = V_67 -> V_70 ;
T_1 V_2 ;
struct V_71 * V_72 = V_67 -> V_72 ;
struct V_5 * V_6 = F_15 ( V_67 ) ;
V_68 = F_57 ( V_72 ) ;
if ( V_73 [ 0 ] == V_68 && V_73 [ 1 ] == V_69 ) {
for ( V_3 = 2 ; V_3 <= 3 ; V_3 ++ ) {
if ( V_73 [ V_3 ] < 0x48 ||
V_73 [ V_3 ] > 0x4f ) {
F_58 ( & V_67 -> V_14 , L_7
L_8 ,
V_73 [ V_3 ] ) ;
V_22 = - V_74 ;
goto V_75;
}
}
F_7 ( V_67 , V_76 ,
( V_73 [ 2 ] & 0x07 ) |
( ( V_73 [ 3 ] & 0x07 ) << 4 ) ) ;
}
V_2 = F_5 ( V_67 , V_76 ) ;
if ( ! ( V_2 & 0x08 ) )
V_6 -> V_77 [ 0 ] = F_59 ( V_72 , 0x48 + ( V_2 & 0x7 ) ) ;
if ( ! ( V_2 & 0x80 ) ) {
if ( ( V_6 -> V_77 [ 0 ] != NULL ) &&
( ( V_2 & 0x7 ) == ( ( V_2 >> 4 ) & 0x7 ) ) ) {
F_58 ( & V_67 -> V_14 , L_9
L_10 , V_6 -> V_77 [ 0 ] -> V_70 ) ;
V_22 = - V_74 ;
goto V_78;
}
V_6 -> V_77 [ 1 ] = F_59 ( V_72 ,
0x48 + ( ( V_2 >> 4 ) & 0x7 ) ) ;
}
return 0 ;
V_78:
if ( V_6 -> V_77 [ 0 ] != NULL )
F_60 ( V_6 -> V_77 [ 0 ] ) ;
V_75:
return V_22 ;
}
static int
F_61 ( struct V_9 * V_10 , struct V_79 * V_80 )
{
struct V_71 * V_72 = V_10 -> V_72 ;
int V_81 , V_82 ;
unsigned short V_69 = V_10 -> V_70 ;
if ( ! F_62 ( V_72 , V_83 ) )
return - V_74 ;
if ( F_5 ( V_10 , V_84 ) & 0x80 )
return - V_74 ;
V_81 = F_5 ( V_10 , V_85 ) ;
V_82 = F_5 ( V_10 , V_86 ) ;
if ( ! ( V_81 & 0x07 ) ) {
if ( ( ! ( V_81 & 0x80 ) && V_82 != 0xa3 ) ||
( ( V_81 & 0x80 ) && V_82 != 0x5c ) )
return - V_74 ;
}
if ( F_5 ( V_10 , V_87 ) != V_69 )
return - V_74 ;
F_7 ( V_10 ,
V_85 ,
( F_5 ( V_10 ,
V_85 ) & 0x78 ) | 0x80 ) ;
V_81 = F_5 ( V_10 , V_88 ) ;
V_82 = F_5 ( V_10 , V_86 ) ;
if ( V_81 != 0x7a || V_82 != 0x5c )
return - V_74 ;
F_63 ( V_80 -> type , L_11 , V_89 ) ;
return 0 ;
}
static int
F_64 ( struct V_9 * V_10 , const struct V_90 * V_68 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 = & V_10 -> V_14 ;
int V_3 , V_81 , V_22 ;
V_6 = F_65 ( V_14 , sizeof( struct V_5 ) , V_91 ) ;
if ( ! V_6 )
return - V_92 ;
F_66 ( V_10 , V_6 ) ;
V_6 -> V_52 = 0 ;
F_67 ( & V_6 -> V_23 ) ;
V_22 = F_56 ( V_10 ) ;
if ( V_22 )
return V_22 ;
F_68 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
V_6 -> V_24 [ V_3 ] = F_5 ( V_10 ,
V_26 [ V_3 ] ) ;
}
V_22 = F_69 ( & V_14 -> V_93 , & V_94 ) ;
if ( V_22 )
goto V_95;
V_81 = F_5 ( V_10 , V_96 ) ;
if ( ! ( V_81 & 0x40 ) ) {
V_22 = F_69 ( & V_14 -> V_93 , & V_97 [ 0 ] ) ;
if ( V_22 )
goto V_98;
}
if ( ! ( V_81 & 0x20 ) ) {
V_22 = F_69 ( & V_14 -> V_93 , & V_97 [ 1 ] ) ;
if ( V_22 )
goto V_98;
}
V_81 = F_5 ( V_10 , V_99 ) ;
if ( V_81 & 0x40 ) {
V_22 = F_69 ( & V_14 -> V_93 , & V_97 [ 2 ] ) ;
if ( V_22 )
goto V_98;
}
if ( V_81 & 0x04 ) {
V_22 = F_69 ( & V_14 -> V_93 , & V_97 [ 3 ] ) ;
if ( V_22 )
goto V_98;
}
V_6 -> V_100 = F_70 ( V_14 ) ;
if ( F_71 ( V_6 -> V_100 ) ) {
V_22 = F_72 ( V_6 -> V_100 ) ;
goto V_98;
}
return 0 ;
V_98:
F_73 ( & V_14 -> V_93 , & V_94 ) ;
for ( V_3 = 0 ; V_3 < F_74 ( V_97 ) ; V_3 ++ )
F_73 ( & V_14 -> V_93 , & V_97 [ V_3 ] ) ;
V_95:
if ( V_6 -> V_77 [ 0 ] != NULL )
F_60 ( V_6 -> V_77 [ 0 ] ) ;
if ( V_6 -> V_77 [ 1 ] != NULL )
F_60 ( V_6 -> V_77 [ 1 ] ) ;
return V_22 ;
}
static int
F_75 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = F_15 ( V_10 ) ;
int V_3 ;
F_76 ( V_6 -> V_100 ) ;
F_73 ( & V_10 -> V_14 . V_93 , & V_94 ) ;
for ( V_3 = 0 ; V_3 < F_74 ( V_97 ) ; V_3 ++ )
F_73 ( & V_10 -> V_14 . V_93 ,
& V_97 [ V_3 ] ) ;
if ( V_6 -> V_77 [ 0 ] != NULL )
F_60 ( V_6 -> V_77 [ 0 ] ) ;
if ( V_6 -> V_77 [ 1 ] != NULL )
F_60 ( V_6 -> V_77 [ 1 ] ) ;
return 0 ;
}
static void
F_68 ( struct V_9 * V_10 )
{
T_1 V_101 , V_102 , V_103 ;
if ( V_104 )
F_7 ( V_10 , V_84 , 0x80 ) ;
V_103 = F_5 ( V_10 , V_105 ) ;
F_7 ( V_10 , V_105 ,
V_103 & 0xbf ) ;
V_101 = F_5 ( V_10 , V_106 ) ;
V_102 = F_5 ( V_10 , V_107 ) ;
F_7 ( V_10 , V_106 ,
V_101 & 0xe6 ) ;
F_7 ( V_10 , V_107 ,
V_102 & 0xe6 ) ;
F_7 ( V_10 , V_84 ,
( F_5 ( V_10 ,
V_84 ) & 0xf7 )
| 0x01 ) ;
}
static struct V_5 * F_11 ( struct V_13 * V_14 )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
int V_3 , V_108 ;
T_1 V_109 [ 4 ] , V_110 ;
F_17 ( & V_6 -> V_23 ) ;
if ( F_77
( V_111 - V_6 -> V_112 , ( unsigned long ) ( V_113 * 3 ) )
|| F_78 ( V_111 , V_6 -> V_112 ) || ! V_6 -> V_52 ) {
F_79 ( V_14 , L_12 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ ) {
V_6 -> V_7 [ V_3 ] = F_5 ( V_10 ,
V_114 [ V_3 ] ) ;
V_6 -> V_115 [ V_3 ] = F_5 ( V_10 ,
V_116 [ V_3 ] ) ;
V_6 -> V_117 [ V_3 ] = F_5 ( V_10 ,
V_118 [ V_3 ] ) ;
}
V_6 -> V_8 = F_5 ( V_10 ,
V_119 ) +
( F_5 ( V_10 ,
V_120 ) << 8 ) ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
V_6 -> V_121 [ V_3 ] = F_5 ( V_10 ,
V_122 [ V_3 ] ) ;
V_6 -> V_24 [ V_3 ] = F_5 ( V_10 ,
V_26 [ V_3 ] ) ;
V_6 -> V_37 [ V_3 ] = F_5 ( V_10 ,
V_40 [ V_3 ] ) ;
}
V_110 = F_5 ( V_10 , V_47 ) ;
V_6 -> V_39 [ 0 ] = V_110 & 0x03 ;
V_6 -> V_39 [ 1 ] = ( V_110 >> 2 ) & 0x03 ;
V_6 -> V_39 [ 2 ] = ( V_110 >> 4 ) & 0x03 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_6 -> V_31 [ V_3 ] = F_5 ( V_10 ,
V_32 [ V_3 ] ) ;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
for ( V_108 = 0 ; V_108 < 6 ; V_108 ++ ) {
V_6 -> V_34 [ V_3 ] [ V_108 ] = F_5 (
V_10 , V_35 [ V_3 ] [ V_108 ] ) ;
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_109 [ V_3 ] = F_5 ( V_10 ,
V_30 [ V_3 ] ) ;
}
V_6 -> V_25 [ 0 ] = V_109 [ 0 ] & 0x07 ;
V_6 -> V_25 [ 1 ] = ( V_109 [ 0 ] >> 4 ) & 0x07 ;
V_6 -> V_25 [ 2 ] = V_109 [ 1 ] & 0x07 ;
V_6 -> V_25 [ 3 ] = ( V_109 [ 1 ] >> 4 ) & 0x07 ;
V_6 -> V_25 [ 4 ] = V_109 [ 2 ] & 0x07 ;
V_6 -> V_25 [ 5 ] = ( V_109 [ 2 ] >> 4 ) & 0x07 ;
V_6 -> V_25 [ 6 ] = V_109 [ 3 ] & 0x07 ;
V_6 -> V_36 = F_5 ( V_10 , V_123 ) +
( F_5 ( V_10 , V_124 ) << 8 ) +
( F_5 ( V_10 , V_125 ) << 16 ) ;
V_6 -> V_48 = ( F_5 ( V_10 ,
V_126 ) >> 5 ) & 0x01 ;
V_6 -> V_49 = ( F_5 ( V_10 ,
V_51 ) >> 7 ) & 0x01 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_6 -> V_53 [ V_3 ] =
F_5 ( V_10 ,
V_56 [ V_3 ] ) & 0x7f ;
}
V_110 = F_5 ( V_10 , V_60 [ 0 ] ) ;
V_6 -> V_57 [ 0 ] = V_110 & 0x0f ;
V_6 -> V_57 [ 1 ] = ( V_110 >> 4 ) & 0x0f ;
V_6 -> V_57 [ 2 ] = F_5 ( V_10 ,
V_60 [ 2 ] ) & 0x0f ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
for ( V_108 = 0 ; V_108 < 4 ; V_108 ++ ) {
V_6 -> V_61 [ V_3 ] [ V_108 ]
= F_5 ( V_10 ,
V_63 [ V_3 ] [ V_108 ] ) & 0x7f ;
}
}
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_110 = F_5 ( V_10 ,
V_66 [ V_3 ] [ 0 ] ) ;
V_6 -> V_64 [ V_3 ] [ 0 ] = V_110 & 0x0f ;
V_6 -> V_64 [ V_3 ] [ 1 ] = ( V_110 >> 4 ) & 0x0f ;
V_110 = F_5 ( V_10 ,
V_66 [ V_3 ] [ 2 ] ) ;
V_6 -> V_64 [ V_3 ] [ 2 ] = ( V_110 >> 4 ) & 0x0f ;
V_6 -> V_64 [ V_3 ] [ 3 ] = V_110 & 0x0f ;
}
V_6 -> V_112 = V_111 ;
V_6 -> V_52 = 1 ;
}
F_19 ( & V_6 -> V_23 ) ;
#ifdef F_80
F_81 ( V_6 , V_14 ) ;
#endif
return V_6 ;
}
static void F_81 ( struct V_5 * V_6 , struct V_13 * V_14 )
{
int V_3 = 0 , V_108 = 0 ;
F_79 ( V_14 , L_13 ) ;
F_79 ( V_14 , L_14 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ ) {
F_79 ( V_14 , L_15 , V_3 , V_6 -> V_7 [ V_3 ] ) ;
F_79 ( V_14 , L_16 , V_3 , V_6 -> V_115 [ V_3 ] ) ;
F_79 ( V_14 , L_17 , V_3 , V_6 -> V_117 [ V_3 ] ) ;
}
F_79 ( V_14 , L_18 , V_6 -> V_8 & 0xff ) ;
F_79 ( V_14 , L_19 , V_6 -> V_8 >> 8 ) ;
F_79 ( V_14 , L_20 ) ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
F_79 ( V_14 , L_21 , V_3 , V_6 -> V_121 [ V_3 ] ) ;
F_79 ( V_14 , L_22 , V_3 , V_6 -> V_24 [ V_3 ] ) ;
F_79 ( V_14 , L_23 , V_3 , V_6 -> V_37 [ V_3 ] ) ;
}
F_79 ( V_14 , L_24 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_79 ( V_14 , L_25 , V_3 , V_6 -> V_31 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
for ( V_108 = 0 ; V_108 < 6 ; V_108 ++ ) {
F_79 ( V_14 , L_26 , V_3 , V_108 ,
V_6 -> V_34 [ V_3 ] [ V_108 ] ) ;
}
}
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ )
F_79 ( V_14 , L_27 , V_3 , V_6 -> V_25 [ V_3 ] ) ;
F_79 ( V_14 , L_28 ) ;
F_79 ( V_14 , L_29 ) ;
}
