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
const char * V_17 , T_3 V_21 )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
unsigned long V_2 ;
T_1 V_11 ;
if ( F_16 ( V_17 , 10 , & V_2 ) || V_2 != 0 )
return - V_46 ;
F_17 ( & V_6 -> V_23 ) ;
V_11 = F_5 ( V_10 , V_49 ) ;
F_7 ( V_10 , V_49 , V_11 | 0x80 ) ;
V_6 -> V_50 = 0 ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_44 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 , ( long ) V_6 -> V_51 [ V_4 - 1 ] ) ;
}
static T_2
F_45 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_52 = 0 , V_53 = 0 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
V_52 = V_2 ;
V_52 = V_52 & 0x7f ;
F_17 ( & V_6 -> V_23 ) ;
V_53 = F_5 ( V_10 ,
V_54 [ V_4 ] ) & 0x80 ;
V_6 -> V_51 [ V_4 ] = F_2 ( V_52 , 0 , 255 ) ;
F_7 ( V_10 , V_54 [ V_4 ] ,
( V_6 -> V_51 [ V_4 ] ) | V_53 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_46 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 , ( long ) V_6 -> V_55 [ V_4 - 1 ] ) ;
}
static T_2
F_47 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_18 * V_19 = F_10 ( V_16 ) ;
int V_4 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_56 , V_57 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_57 = F_5 ( V_10 ,
V_58 [ V_4 ] ) & ( ( V_4 == 1 ) ? 0x0f : 0xf0 ) ;
V_56 = F_2 ( V_2 , 0 , 15 ) ;
V_56 &= 0x0f ;
V_6 -> V_55 [ V_4 ] = V_56 ;
if ( V_4 == 1 )
V_56 <<= 4 ;
F_7 ( V_10 , V_58 [ V_4 ] ,
V_57 | V_56 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_48 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_1 , ( long ) V_6 -> V_59 [ V_20 - 1 ] [ V_4 - 1 ] ) ;
}
static T_2
F_49 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 - 1 ;
int V_20 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_60 = 0 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_59 [ V_20 ] [ V_4 ] = F_2 ( V_2 , 0 , 127 ) ;
V_60 = F_5 ( V_10 ,
V_61 [ V_20 ] [ V_4 ] ) & 0x80 ;
F_7 ( V_10 , V_61 [ V_20 ] [ V_4 ] ,
V_60 | V_6 -> V_59 [ V_20 ] [ V_4 ] ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static T_2
F_50 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 ;
struct V_5 * V_6 = F_11 ( V_14 ) ;
return sprintf ( V_17 , L_3 ,
( ( ( V_6 -> V_62 [ V_20 - 1 ] [ V_4 ] ) * 100 ) / 15 ) ) ;
}
static T_2
F_51 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_21 )
{
struct V_33 * V_19
= F_29 ( V_16 ) ;
int V_4 = V_19 -> V_4 ;
int V_20 = V_19 -> V_20 - 1 ;
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
T_1 V_60 = 0 , V_63 = 0 ;
unsigned long V_2 ;
int V_22 ;
V_22 = F_16 ( V_17 , 10 , & V_2 ) ;
if ( V_22 )
return V_22 ;
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_62 [ V_20 ] [ V_4 ] = F_2 ( ( V_2 * 15 ) / 100 , 0 , 15 ) ;
V_60 = F_5 ( V_10 , V_64 [ V_20 ] [ V_4 ] )
& ( ( V_4 == 3 ) ? 0xf0 : 0x0f ) ;
if ( V_4 == 3 )
V_63 = V_6 -> V_62 [ V_20 ] [ V_4 ] ;
else
V_63 = V_6 -> V_62 [ V_20 ] [ V_4 ] << 4 ;
F_7 ( V_10 , V_64 [ V_20 ] [ V_4 ] ,
V_63 | V_60 ) ;
F_19 ( & V_6 -> V_23 ) ;
return V_21 ;
}
static int
F_52 ( struct V_9 * V_65 )
{
int V_3 , V_66 , V_22 ;
int V_67 = V_65 -> V_68 ;
T_1 V_2 ;
struct V_69 * V_70 = V_65 -> V_70 ;
struct V_5 * V_6 = F_15 ( V_65 ) ;
V_66 = F_53 ( V_70 ) ;
if ( V_71 [ 0 ] == V_66 && V_71 [ 1 ] == V_67 ) {
for ( V_3 = 2 ; V_3 <= 3 ; V_3 ++ ) {
if ( V_71 [ V_3 ] < 0x48 ||
V_71 [ V_3 ] > 0x4f ) {
F_54 ( & V_65 -> V_14 ,
L_4 ,
V_71 [ V_3 ] ) ;
V_22 = - V_72 ;
goto V_73;
}
}
F_7 ( V_65 , V_74 ,
( V_71 [ 2 ] & 0x07 ) |
( ( V_71 [ 3 ] & 0x07 ) << 4 ) ) ;
}
V_2 = F_5 ( V_65 , V_74 ) ;
if ( ! ( V_2 & 0x08 ) )
V_6 -> V_75 [ 0 ] = F_55 ( V_70 , 0x48 + ( V_2 & 0x7 ) ) ;
if ( ! ( V_2 & 0x80 ) ) {
if ( ( V_6 -> V_75 [ 0 ] != NULL ) &&
( ( V_2 & 0x7 ) == ( ( V_2 >> 4 ) & 0x7 ) ) ) {
F_54 ( & V_65 -> V_14 ,
L_5 ,
V_6 -> V_75 [ 0 ] -> V_68 ) ;
V_22 = - V_72 ;
goto V_76;
}
V_6 -> V_75 [ 1 ] = F_55 ( V_70 ,
0x48 + ( ( V_2 >> 4 ) & 0x7 ) ) ;
}
return 0 ;
V_76:
if ( V_6 -> V_75 [ 0 ] != NULL )
F_56 ( V_6 -> V_75 [ 0 ] ) ;
V_73:
return V_22 ;
}
static int
F_57 ( struct V_9 * V_10 , struct V_77 * V_78 )
{
struct V_69 * V_70 = V_10 -> V_70 ;
int V_79 , V_80 ;
unsigned short V_67 = V_10 -> V_68 ;
if ( ! F_58 ( V_70 , V_81 ) )
return - V_72 ;
if ( F_5 ( V_10 , V_82 ) & 0x80 )
return - V_72 ;
V_79 = F_5 ( V_10 , V_83 ) ;
V_80 = F_5 ( V_10 , V_84 ) ;
if ( ! ( V_79 & 0x07 ) ) {
if ( ( ! ( V_79 & 0x80 ) && V_80 != 0xa3 ) ||
( ( V_79 & 0x80 ) && V_80 != 0x5c ) )
return - V_72 ;
}
if ( F_5 ( V_10 , V_85 ) != V_67 )
return - V_72 ;
F_7 ( V_10 ,
V_83 ,
( F_5 ( V_10 ,
V_83 ) & 0x78 ) | 0x80 ) ;
V_79 = F_5 ( V_10 , V_86 ) ;
V_80 = F_5 ( V_10 , V_84 ) ;
if ( V_79 != 0x7a || V_80 != 0x5c )
return - V_72 ;
F_59 ( V_78 -> type , L_6 , V_87 ) ;
return 0 ;
}
static int
F_60 ( struct V_9 * V_10 , const struct V_88 * V_66 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 = & V_10 -> V_14 ;
int V_3 , V_79 , V_22 ;
V_6 = F_61 ( V_14 , sizeof( struct V_5 ) , V_89 ) ;
if ( ! V_6 )
return - V_90 ;
F_62 ( V_10 , V_6 ) ;
F_63 ( & V_6 -> V_23 ) ;
V_22 = F_52 ( V_10 ) ;
if ( V_22 )
return V_22 ;
F_64 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
V_6 -> V_24 [ V_3 ] = F_5 ( V_10 ,
V_26 [ V_3 ] ) ;
}
V_22 = F_65 ( & V_14 -> V_91 , & V_92 ) ;
if ( V_22 )
goto V_93;
V_79 = F_5 ( V_10 , V_94 ) ;
if ( ! ( V_79 & 0x40 ) ) {
V_22 = F_65 ( & V_14 -> V_91 , & V_95 [ 0 ] ) ;
if ( V_22 )
goto V_96;
}
if ( ! ( V_79 & 0x20 ) ) {
V_22 = F_65 ( & V_14 -> V_91 , & V_95 [ 1 ] ) ;
if ( V_22 )
goto V_96;
}
V_79 = F_5 ( V_10 , V_97 ) ;
if ( V_79 & 0x40 ) {
V_22 = F_65 ( & V_14 -> V_91 , & V_95 [ 2 ] ) ;
if ( V_22 )
goto V_96;
}
if ( V_79 & 0x04 ) {
V_22 = F_65 ( & V_14 -> V_91 , & V_95 [ 3 ] ) ;
if ( V_22 )
goto V_96;
}
V_6 -> V_98 = F_66 ( V_14 ) ;
if ( F_67 ( V_6 -> V_98 ) ) {
V_22 = F_68 ( V_6 -> V_98 ) ;
goto V_96;
}
return 0 ;
V_96:
F_69 ( & V_14 -> V_91 , & V_92 ) ;
for ( V_3 = 0 ; V_3 < F_70 ( V_95 ) ; V_3 ++ )
F_69 ( & V_14 -> V_91 , & V_95 [ V_3 ] ) ;
V_93:
if ( V_6 -> V_75 [ 0 ] != NULL )
F_56 ( V_6 -> V_75 [ 0 ] ) ;
if ( V_6 -> V_75 [ 1 ] != NULL )
F_56 ( V_6 -> V_75 [ 1 ] ) ;
return V_22 ;
}
static int
F_71 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = F_15 ( V_10 ) ;
int V_3 ;
F_72 ( V_6 -> V_98 ) ;
F_69 ( & V_10 -> V_14 . V_91 , & V_92 ) ;
for ( V_3 = 0 ; V_3 < F_70 ( V_95 ) ; V_3 ++ )
F_69 ( & V_10 -> V_14 . V_91 ,
& V_95 [ V_3 ] ) ;
if ( V_6 -> V_75 [ 0 ] != NULL )
F_56 ( V_6 -> V_75 [ 0 ] ) ;
if ( V_6 -> V_75 [ 1 ] != NULL )
F_56 ( V_6 -> V_75 [ 1 ] ) ;
return 0 ;
}
static void
F_64 ( struct V_9 * V_10 )
{
T_1 V_99 , V_100 , V_101 ;
if ( V_102 )
F_7 ( V_10 , V_82 , 0x80 ) ;
V_101 = F_5 ( V_10 , V_103 ) ;
F_7 ( V_10 , V_103 ,
V_101 & 0xbf ) ;
V_99 = F_5 ( V_10 , V_104 ) ;
V_100 = F_5 ( V_10 , V_105 ) ;
F_7 ( V_10 , V_104 ,
V_99 & 0xe6 ) ;
F_7 ( V_10 , V_105 ,
V_100 & 0xe6 ) ;
F_7 ( V_10 , V_82 ,
( F_5 ( V_10 ,
V_82 ) & 0xf7 )
| 0x01 ) ;
}
static struct V_5 * F_11 ( struct V_13 * V_14 )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
struct V_5 * V_6 = F_15 ( V_10 ) ;
int V_3 , V_106 ;
T_1 V_107 [ 4 ] , V_108 ;
F_17 ( & V_6 -> V_23 ) ;
if ( F_73
( V_109 - V_6 -> V_110 , ( unsigned long ) ( V_111 * 3 ) )
|| F_74 ( V_109 , V_6 -> V_110 ) || ! V_6 -> V_50 ) {
F_75 ( V_14 , L_7 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ ) {
V_6 -> V_7 [ V_3 ] = F_5 ( V_10 ,
V_112 [ V_3 ] ) ;
V_6 -> V_113 [ V_3 ] = F_5 ( V_10 ,
V_114 [ V_3 ] ) ;
V_6 -> V_115 [ V_3 ] = F_5 ( V_10 ,
V_116 [ V_3 ] ) ;
}
V_6 -> V_8 = F_5 ( V_10 ,
V_117 ) +
( F_5 ( V_10 ,
V_118 ) << 8 ) ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
V_6 -> V_119 [ V_3 ] = F_5 ( V_10 ,
V_120 [ V_3 ] ) ;
V_6 -> V_24 [ V_3 ] = F_5 ( V_10 ,
V_26 [ V_3 ] ) ;
V_6 -> V_37 [ V_3 ] = F_5 ( V_10 ,
V_40 [ V_3 ] ) ;
}
V_108 = F_5 ( V_10 , V_47 ) ;
V_6 -> V_39 [ 0 ] = V_108 & 0x03 ;
V_6 -> V_39 [ 1 ] = ( V_108 >> 2 ) & 0x03 ;
V_6 -> V_39 [ 2 ] = ( V_108 >> 4 ) & 0x03 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_6 -> V_31 [ V_3 ] = F_5 ( V_10 ,
V_32 [ V_3 ] ) ;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
for ( V_106 = 0 ; V_106 < 6 ; V_106 ++ ) {
V_6 -> V_34 [ V_3 ] [ V_106 ] = F_5 (
V_10 , V_35 [ V_3 ] [ V_106 ] ) ;
}
}
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_107 [ V_3 ] = F_5 ( V_10 ,
V_30 [ V_3 ] ) ;
}
V_6 -> V_25 [ 0 ] = V_107 [ 0 ] & 0x07 ;
V_6 -> V_25 [ 1 ] = ( V_107 [ 0 ] >> 4 ) & 0x07 ;
V_6 -> V_25 [ 2 ] = V_107 [ 1 ] & 0x07 ;
V_6 -> V_25 [ 3 ] = ( V_107 [ 1 ] >> 4 ) & 0x07 ;
V_6 -> V_25 [ 4 ] = V_107 [ 2 ] & 0x07 ;
V_6 -> V_25 [ 5 ] = ( V_107 [ 2 ] >> 4 ) & 0x07 ;
V_6 -> V_25 [ 6 ] = V_107 [ 3 ] & 0x07 ;
V_6 -> V_36 = F_5 ( V_10 , V_121 ) +
( F_5 ( V_10 , V_122 ) << 8 ) +
( F_5 ( V_10 , V_123 ) << 16 ) ;
V_6 -> V_48 = ( F_5 ( V_10 ,
V_124 ) >> 5 ) & 0x01 ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_6 -> V_51 [ V_3 ] =
F_5 ( V_10 ,
V_54 [ V_3 ] ) & 0x7f ;
}
V_108 = F_5 ( V_10 , V_58 [ 0 ] ) ;
V_6 -> V_55 [ 0 ] = V_108 & 0x0f ;
V_6 -> V_55 [ 1 ] = ( V_108 >> 4 ) & 0x0f ;
V_6 -> V_55 [ 2 ] = F_5 ( V_10 ,
V_58 [ 2 ] ) & 0x0f ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
for ( V_106 = 0 ; V_106 < 4 ; V_106 ++ ) {
V_6 -> V_59 [ V_3 ] [ V_106 ]
= F_5 ( V_10 ,
V_61 [ V_3 ] [ V_106 ] ) & 0x7f ;
}
}
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_108 = F_5 ( V_10 ,
V_64 [ V_3 ] [ 0 ] ) ;
V_6 -> V_62 [ V_3 ] [ 0 ] = V_108 & 0x0f ;
V_6 -> V_62 [ V_3 ] [ 1 ] = ( V_108 >> 4 ) & 0x0f ;
V_108 = F_5 ( V_10 ,
V_64 [ V_3 ] [ 2 ] ) ;
V_6 -> V_62 [ V_3 ] [ 2 ] = ( V_108 >> 4 ) & 0x0f ;
V_6 -> V_62 [ V_3 ] [ 3 ] = V_108 & 0x0f ;
}
V_6 -> V_110 = V_109 ;
V_6 -> V_50 = 1 ;
}
F_19 ( & V_6 -> V_23 ) ;
#ifdef F_76
F_77 ( V_6 , V_14 ) ;
#endif
return V_6 ;
}
static void F_77 ( struct V_5 * V_6 , struct V_13 * V_14 )
{
int V_3 = 0 , V_106 = 0 ;
F_75 ( V_14 , L_8 ) ;
F_75 ( V_14 , L_9 ) ;
for ( V_3 = 0 ; V_3 < 9 ; V_3 ++ ) {
F_75 ( V_14 , L_10 , V_3 , V_6 -> V_7 [ V_3 ] ) ;
F_75 ( V_14 , L_11 , V_3 , V_6 -> V_113 [ V_3 ] ) ;
F_75 ( V_14 , L_12 , V_3 , V_6 -> V_115 [ V_3 ] ) ;
}
F_75 ( V_14 , L_13 , V_6 -> V_8 & 0xff ) ;
F_75 ( V_14 , L_14 , V_6 -> V_8 >> 8 ) ;
F_75 ( V_14 , L_15 ) ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
F_75 ( V_14 , L_16 , V_3 , V_6 -> V_119 [ V_3 ] ) ;
F_75 ( V_14 , L_17 , V_3 , V_6 -> V_24 [ V_3 ] ) ;
F_75 ( V_14 , L_18 , V_3 , V_6 -> V_37 [ V_3 ] ) ;
}
F_75 ( V_14 , L_19 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ )
F_75 ( V_14 , L_20 , V_3 , V_6 -> V_31 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
for ( V_106 = 0 ; V_106 < 6 ; V_106 ++ ) {
F_75 ( V_14 , L_21 , V_3 , V_106 ,
V_6 -> V_34 [ V_3 ] [ V_106 ] ) ;
}
}
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ )
F_75 ( V_14 , L_22 , V_3 , V_6 -> V_25 [ V_3 ] ) ;
F_75 ( V_14 , L_23 ) ;
F_75 ( V_14 , L_24 ) ;
}
