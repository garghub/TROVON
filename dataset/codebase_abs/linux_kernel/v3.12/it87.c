static inline int F_1 ( int V_1 )
{
F_2 ( V_1 , V_2 ) ;
return F_3 ( V_3 ) ;
}
static inline void F_4 ( int V_1 , int V_4 )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_4 , V_3 ) ;
}
static int F_5 ( int V_1 )
{
int V_4 ;
F_2 ( V_1 ++ , V_2 ) ;
V_4 = F_3 ( V_3 ) << 8 ;
F_2 ( V_1 , V_2 ) ;
V_4 |= F_3 ( V_3 ) ;
return V_4 ;
}
static inline void F_6 ( int V_5 )
{
F_2 ( V_6 , V_2 ) ;
F_2 ( V_5 , V_3 ) ;
}
static inline int F_7 ( void )
{
if ( ! F_8 ( V_2 , 2 , V_7 ) )
return - V_8 ;
F_2 ( 0x87 , V_2 ) ;
F_2 ( 0x01 , V_2 ) ;
F_2 ( 0x55 , V_2 ) ;
F_2 ( 0x55 , V_2 ) ;
return 0 ;
}
static inline void F_9 ( void )
{
F_2 ( 0x02 , V_2 ) ;
F_2 ( 0x02 , V_3 ) ;
F_10 ( V_2 , 2 ) ;
}
static int F_11 ( const struct V_9 * V_10 , int V_11 )
{
int V_12 = F_12 ( V_10 ) ? 12 : 16 ;
if ( V_10 -> V_13 & ( 1 << V_11 ) )
V_12 <<= 1 ;
return V_12 ;
}
static T_1 F_13 ( const struct V_9 * V_10 , int V_11 , long V_4 )
{
V_4 = F_14 ( V_4 , F_11 ( V_10 , V_11 ) ) ;
return F_15 ( V_4 , 0 , 255 ) ;
}
static int F_16 ( const struct V_9 * V_10 , int V_11 , int V_4 )
{
return V_4 * F_11 ( V_10 , V_11 ) ;
}
static inline T_1 F_17 ( long V_14 , int div )
{
if ( V_14 == 0 )
return 255 ;
V_14 = F_15 ( V_14 , 1 , 1000000 ) ;
return F_15 ( ( 1350000 + V_14 * div / 2 ) / ( V_14 * div ) , 1 , 254 ) ;
}
static inline T_2 F_18 ( long V_14 )
{
if ( V_14 == 0 )
return 0xffff ;
return F_15 ( ( 1350000 + V_14 ) / ( V_14 * 2 ) , 1 , 0xfffe ) ;
}
static T_1 F_19 ( const struct V_9 * V_10 , long V_4 )
{
if ( F_20 ( V_10 ) )
return V_4 ;
else
return V_4 >> 1 ;
}
static int F_21 ( const struct V_9 * V_10 , T_1 V_1 )
{
if ( F_20 ( V_10 ) )
return V_1 ;
else
return ( V_1 & 0x7f ) << 1 ;
}
static int F_22 ( int V_4 )
{
int V_15 = 0 ;
while ( V_15 < 7 && ( V_4 >>= 1 ) )
V_15 ++ ;
return V_15 ;
}
static T_3 F_23 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_24 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_16 ( V_10 , V_11 , V_10 -> V_24 [ V_11 ] [ V_23 ] ) ) ;
}
static T_3 F_26 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_21 * V_22 = F_24 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
unsigned long V_4 ;
if ( F_28 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_24 [ V_11 ] [ V_23 ] = F_13 ( V_10 , V_11 , V_4 ) ;
F_30 ( V_10 ,
V_23 == 1 ? F_31 ( V_11 )
: F_32 ( V_11 ) ,
V_10 -> V_24 [ V_11 ] [ V_23 ] ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_34 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_24 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_35 ( V_10 -> V_28 [ V_11 ] [ V_23 ] ) ) ;
}
static T_3 F_36 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_21 * V_22 = F_24 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
T_1 V_1 , V_29 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
switch ( V_23 ) {
default:
case 1 :
V_1 = F_38 ( V_11 ) ;
break;
case 2 :
V_1 = F_39 ( V_11 ) ;
break;
case 3 :
V_29 = F_40 ( V_10 , V_30 ) ;
if ( ! ( V_29 & 0x80 ) ) {
V_29 |= 0x80 ;
F_30 ( V_10 , V_30 , V_29 ) ;
}
V_10 -> V_31 = 0 ;
V_1 = V_32 [ V_11 ] ;
break;
}
V_10 -> V_28 [ V_11 ] [ V_23 ] = F_41 ( V_4 ) ;
F_30 ( V_10 , V_1 , V_10 -> V_28 [ V_11 ] [ V_23 ] ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_42 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
T_1 V_1 = V_10 -> V_35 ;
T_1 V_36 = V_10 -> V_36 ;
if ( ( F_44 ( V_10 , V_11 ) && ( V_1 >> 6 == V_11 + 1 ) )
|| ( F_45 ( V_10 , V_11 ) && ( V_36 & 0x80 ) ) )
return sprintf ( V_20 , L_2 ) ;
if ( V_1 & ( 1 << V_11 ) )
return sprintf ( V_20 , L_3 ) ;
if ( V_1 & ( 8 << V_11 ) )
return sprintf ( V_20 , L_4 ) ;
return sprintf ( V_20 , L_5 ) ;
}
static T_3 F_46 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
T_1 V_1 , V_36 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
V_1 = F_40 ( V_10 , V_37 ) ;
V_1 &= ~ ( 1 << V_11 ) ;
V_1 &= ~ ( 8 << V_11 ) ;
if ( F_44 ( V_10 , V_11 ) && ( V_1 >> 6 == V_11 + 1 || V_4 == 6 ) )
V_1 &= 0x3f ;
V_36 = F_40 ( V_10 , V_38 ) ;
if ( F_45 ( V_10 , V_11 ) && ( ( V_36 & 0x80 ) || V_4 == 6 ) )
V_36 &= 0x7f ;
if ( V_4 == 2 ) {
F_47 ( V_17 ,
L_6 ) ;
V_4 = 4 ;
}
if ( V_4 == 3 )
V_1 |= 1 << V_11 ;
else if ( V_4 == 4 )
V_1 |= 8 << V_11 ;
else if ( F_44 ( V_10 , V_11 ) && V_4 == 6 )
V_1 |= ( V_11 + 1 ) << 6 ;
else if ( F_45 ( V_10 , V_11 ) && V_4 == 6 )
V_36 |= 0x80 ;
else if ( V_4 != 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_35 = V_1 ;
V_10 -> V_36 = V_36 ;
F_30 ( V_10 , V_37 , V_10 -> V_35 ) ;
if ( F_45 ( V_10 , V_11 ) )
F_30 ( V_10 , V_38 , V_10 -> V_36 ) ;
V_10 -> V_31 = 0 ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static int F_48 ( const struct V_9 * V_10 , int V_11 )
{
int V_39 = V_10 -> V_40 & ( 1 << V_11 ) ;
if ( V_39 == 0 )
return 0 ;
if ( V_10 -> V_41 [ V_11 ] & 0x80 )
return 2 ;
else
return 1 ;
}
static T_3 F_49 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_24 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
int V_42 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
V_42 = F_50 ( V_10 ) ?
F_51 ( V_10 -> V_43 [ V_11 ] [ V_23 ] ) :
F_52 ( V_10 -> V_43 [ V_11 ] [ V_23 ] ,
F_53 ( V_10 -> V_44 [ V_11 ] ) ) ;
return sprintf ( V_20 , L_1 , V_42 ) ;
}
static T_3 F_54 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_53 ( V_10 -> V_44 [ V_11 ] ) ) ;
}
static T_3 F_55 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_48 ( V_10 , V_11 ) ) ;
}
static T_3 F_56 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_1 ,
F_21 ( V_10 , V_10 -> V_45 [ V_11 ] ) ) ;
}
static T_3 F_57 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
int V_23 = ( V_10 -> V_46 >> 4 ) & 0x07 ;
return sprintf ( V_20 , L_7 , V_47 [ V_23 ] ) ;
}
static T_3 F_58 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_21 * V_22 = F_24 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
if ( F_50 ( V_10 ) ) {
V_10 -> V_43 [ V_11 ] [ V_23 ] = F_18 ( V_4 ) ;
F_30 ( V_10 , V_48 [ V_11 ] ,
V_10 -> V_43 [ V_11 ] [ V_23 ] & 0xff ) ;
F_30 ( V_10 , V_49 [ V_11 ] ,
V_10 -> V_43 [ V_11 ] [ V_23 ] >> 8 ) ;
} else {
V_1 = F_40 ( V_10 , V_50 ) ;
switch ( V_11 ) {
case 0 :
V_10 -> V_44 [ V_11 ] = V_1 & 0x07 ;
break;
case 1 :
V_10 -> V_44 [ V_11 ] = ( V_1 >> 3 ) & 0x07 ;
break;
case 2 :
V_10 -> V_44 [ V_11 ] = ( V_1 & 0x40 ) ? 3 : 1 ;
break;
}
V_10 -> V_43 [ V_11 ] [ V_23 ] =
F_17 ( V_4 , F_53 ( V_10 -> V_44 [ V_11 ] ) ) ;
F_30 ( V_10 , V_48 [ V_11 ] ,
V_10 -> V_43 [ V_11 ] [ V_23 ] ) ;
}
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_59 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
unsigned long V_4 ;
int V_51 ;
T_1 V_52 ;
if ( F_28 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_52 = F_40 ( V_10 , V_50 ) ;
V_51 = F_52 ( V_10 -> V_43 [ V_11 ] [ 1 ] , F_53 ( V_10 -> V_44 [ V_11 ] ) ) ;
switch ( V_11 ) {
case 0 :
case 1 :
V_10 -> V_44 [ V_11 ] = F_22 ( V_4 ) ;
break;
case 2 :
if ( V_4 < 8 )
V_10 -> V_44 [ V_11 ] = 1 ;
else
V_10 -> V_44 [ V_11 ] = 3 ;
}
V_4 = V_52 & 0x80 ;
V_4 |= ( V_10 -> V_44 [ 0 ] & 0x07 ) ;
V_4 |= ( V_10 -> V_44 [ 1 ] & 0x07 ) << 3 ;
if ( V_10 -> V_44 [ 2 ] == 3 )
V_4 |= 0x1 << 6 ;
F_30 ( V_10 , V_50 , V_4 ) ;
V_10 -> V_43 [ V_11 ] [ 1 ] = F_17 ( V_51 , F_53 ( V_10 -> V_44 [ V_11 ] ) ) ;
F_30 ( V_10 , V_48 [ V_11 ] , V_10 -> V_43 [ V_11 ] [ 1 ] ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static int F_60 ( struct V_16 * V_17 , int V_11 )
{
const struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_53 , V_54 = 0 ;
if ( F_61 ( V_10 ) ) {
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_10 -> V_55 [ V_11 ] [ V_53 ] > V_10 -> V_55 [ V_11 ] [ V_53 + 1 ] )
V_54 = - V_26 ;
}
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
if ( V_10 -> V_56 [ V_11 ] [ V_53 ] > V_10 -> V_56 [ V_11 ] [ V_53 + 1 ] )
V_54 = - V_26 ;
}
}
if ( V_54 ) {
F_62 ( V_17 ,
L_8 ) ;
F_62 ( V_17 , L_9 ) ;
}
return V_54 ;
}
static T_3 F_63 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 2 )
return - V_26 ;
if ( V_4 == 2 ) {
if ( F_60 ( V_17 , V_11 ) < 0 )
return - V_26 ;
}
F_29 ( & V_10 -> V_27 ) ;
if ( V_4 == 0 ) {
int V_57 ;
V_57 = F_40 ( V_10 , V_58 ) ;
F_30 ( V_10 , V_58 , V_57 | ( 1 << V_11 ) ) ;
V_10 -> V_40 &= ~ ( 1 << V_11 ) ;
F_30 ( V_10 , V_59 ,
V_10 -> V_40 ) ;
} else {
if ( V_4 == 1 )
V_10 -> V_41 [ V_11 ] = F_20 ( V_10 ) ?
V_10 -> V_60 [ V_11 ] :
V_10 -> V_45 [ V_11 ] ;
else
V_10 -> V_41 [ V_11 ] = 0x80 | V_10 -> V_60 [ V_11 ] ;
F_30 ( V_10 , F_64 ( V_11 ) , V_10 -> V_41 [ V_11 ] ) ;
V_10 -> V_40 |= ( 1 << V_11 ) ;
F_30 ( V_10 , V_59 ,
V_10 -> V_40 ) ;
}
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_65 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
if ( F_20 ( V_10 ) ) {
if ( V_10 -> V_41 [ V_11 ] & 0x80 ) {
F_33 ( & V_10 -> V_27 ) ;
return - V_8 ;
}
V_10 -> V_45 [ V_11 ] = F_19 ( V_10 , V_4 ) ;
F_30 ( V_10 , F_66 ( V_11 ) ,
V_10 -> V_45 [ V_11 ] ) ;
} else {
V_10 -> V_45 [ V_11 ] = F_19 ( V_10 , V_4 ) ;
if ( ! ( V_10 -> V_41 [ V_11 ] & 0x80 ) ) {
V_10 -> V_41 [ V_11 ] = V_10 -> V_45 [ V_11 ] ;
F_30 ( V_10 , F_64 ( V_11 ) ,
V_10 -> V_41 [ V_11 ] ) ;
}
}
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_67 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
unsigned long V_4 ;
int V_53 ;
if ( F_28 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
for ( V_53 = 0 ; V_53 < 7 ; V_53 ++ ) {
if ( V_4 > ( V_47 [ V_53 ] + V_47 [ V_53 + 1 ] ) / 2 )
break;
}
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_46 = F_40 ( V_10 , V_58 ) & 0x8f ;
V_10 -> V_46 |= V_53 << 4 ;
F_30 ( V_10 , V_58 , V_10 -> V_46 ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_68 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
int V_61 ;
if ( V_10 -> V_60 [ V_11 ] < 3 )
V_61 = 1 << V_10 -> V_60 [ V_11 ] ;
else
V_61 = 0 ;
return sprintf ( V_20 , L_1 , V_61 ) ;
}
static T_3 F_69 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
T_1 V_1 ;
if ( ! F_61 ( V_10 ) ) {
F_70 ( V_17 , L_10 ) ;
return - V_26 ;
}
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
switch ( V_4 ) {
case ( 1 << 0 ) :
V_1 = 0x00 ;
break;
case ( 1 << 1 ) :
V_1 = 0x01 ;
break;
case ( 1 << 2 ) :
V_1 = 0x02 ;
break;
default:
return - V_26 ;
}
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_60 [ V_11 ] = V_1 ;
if ( V_10 -> V_41 [ V_11 ] & 0x80 ) {
V_10 -> V_41 [ V_11 ] = 0x80 | V_10 -> V_60 [ V_11 ] ;
F_30 ( V_10 , F_64 ( V_11 ) , V_10 -> V_41 [ V_11 ] ) ;
}
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_71 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
struct V_21 * V_34 =
F_24 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_62 = V_34 -> V_23 ;
return sprintf ( V_20 , L_1 ,
F_21 ( V_10 , V_10 -> V_56 [ V_11 ] [ V_62 ] ) ) ;
}
static T_3 F_72 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
struct V_21 * V_34 =
F_24 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_62 = V_34 -> V_23 ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_56 [ V_11 ] [ V_62 ] = F_19 ( V_10 , V_4 ) ;
F_30 ( V_10 , F_73 ( V_11 , V_62 ) ,
V_10 -> V_56 [ V_11 ] [ V_62 ] ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_74 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
struct V_21 * V_34 =
F_24 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_62 = V_34 -> V_23 ;
return sprintf ( V_20 , L_1 , F_35 ( V_10 -> V_55 [ V_11 ] [ V_62 ] ) ) ;
}
static T_3 F_75 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
struct V_21 * V_34 =
F_24 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_62 = V_34 -> V_23 ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 < - 128000 || V_4 > 127000 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_55 [ V_11 ] [ V_62 ] = F_41 ( V_4 ) ;
F_30 ( V_10 , F_76 ( V_11 , V_62 ) ,
V_10 -> V_55 [ V_11 ] [ V_62 ] ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_77 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_7 , V_10 -> V_63 ) ;
}
static T_3 F_78 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
int V_64 = F_43 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_7 , ( V_10 -> V_63 >> V_64 ) & 1 ) ;
}
static T_3 F_79 ( struct V_16 * V_17 , struct V_18
* V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
int V_65 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 != 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_65 = F_40 ( V_10 , V_66 ) ;
if ( V_65 < 0 ) {
V_25 = V_65 ;
} else {
V_65 |= 1 << 5 ;
F_30 ( V_10 , V_66 , V_65 ) ;
V_10 -> V_31 = 0 ;
}
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_80 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
int V_64 = F_43 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_7 , ( V_10 -> V_67 >> V_64 ) & 1 ) ;
}
static T_3 F_81 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
int V_64 = F_43 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0
|| ( V_4 != 0 && V_4 != 1 ) )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_67 = F_40 ( V_10 , V_30 ) ;
if ( V_4 )
V_10 -> V_67 |= ( 1 << V_64 ) ;
else
V_10 -> V_67 &= ~ ( 1 << V_64 ) ;
F_30 ( V_10 , V_30 , V_10 -> V_67 ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_82 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
return sprintf ( V_20 , L_7 , V_10 -> V_68 ) ;
}
static T_3 F_83 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
unsigned long V_4 ;
if ( F_28 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
V_10 -> V_68 = V_4 ;
return V_25 ;
}
static T_3 F_84 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_11 , ( long ) F_85 ( V_10 -> V_69 , V_10 -> V_68 ) ) ;
}
static T_3 F_86 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
static const char * const V_70 [] = {
L_12 ,
L_13 ,
L_14 ,
} ;
static const char * const V_71 [] = {
L_15 ,
L_16 ,
L_14 ,
} ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_11 = F_43 ( V_19 ) -> V_23 ;
return sprintf ( V_20 , L_17 , F_12 ( V_10 ) ? V_71 [ V_11 ]
: V_70 [ V_11 ] ) ;
}
static T_3 F_87 ( struct V_16 * V_17 , struct V_18
* V_72 , char * V_20 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
return sprintf ( V_20 , L_17 , V_10 -> V_73 ) ;
}
static int T_5 F_88 ( unsigned short * V_74 ,
struct V_75 * V_76 )
{
int V_54 ;
T_2 V_77 ;
const char * V_78 , * V_79 ;
V_54 = F_7 () ;
if ( V_54 )
return V_54 ;
V_54 = - V_80 ;
V_77 = V_81 ? V_81 : F_5 ( V_82 ) ;
switch ( V_77 ) {
case V_83 :
V_76 -> type = V_84 ;
break;
case V_85 :
V_76 -> type = V_86 ;
break;
case V_87 :
case V_88 :
V_76 -> type = V_89 ;
break;
case V_90 :
V_76 -> type = V_91 ;
break;
case V_92 :
V_76 -> type = V_93 ;
break;
case V_94 :
V_76 -> type = V_95 ;
break;
case V_96 :
V_76 -> type = V_97 ;
break;
case V_98 :
V_76 -> type = V_99 ;
break;
case V_100 :
V_76 -> type = V_101 ;
break;
case V_102 :
V_76 -> type = V_103 ;
break;
case V_104 :
V_76 -> type = V_105 ;
break;
case 0xffff :
goto exit;
default:
F_89 ( L_18 , V_77 ) ;
goto exit;
}
F_6 ( V_106 ) ;
if ( ! ( F_1 ( V_107 ) & 0x01 ) ) {
F_90 ( L_19 ) ;
goto exit;
}
* V_74 = F_5 ( V_108 ) & ~ ( V_109 - 1 ) ;
if ( * V_74 == 0 ) {
F_90 ( L_20 ) ;
goto exit;
}
V_54 = 0 ;
V_76 -> V_110 = F_1 ( V_111 ) & 0x0f ;
F_90 ( L_21 ,
V_77 , * V_74 , V_76 -> V_110 ) ;
V_76 -> V_112 = ( 1 << 2 ) ;
if ( V_76 -> type == V_84 ) {
V_76 -> V_113 = 1 ;
F_6 ( 5 ) ;
V_76 -> V_114 = F_1 ( V_115 ) & 0x3f ;
} else if ( V_76 -> type == V_105 ) {
int V_116 , V_117 , V_118 , V_119 , V_120 ;
V_76 -> V_113 = 1 ;
F_6 ( V_121 ) ;
V_116 = F_1 ( V_122 ) ;
V_117 = F_1 ( V_123 ) ;
V_118 = F_1 ( V_124 ) ;
V_119 = F_1 ( V_125 ) ;
V_120 = F_1 ( V_126 ) ;
if ( ( V_117 & ( 1 << 0 ) ) || ! ( V_119 & ( 1 << 2 ) ) )
V_76 -> V_127 |= ( 1 << 2 ) ;
if ( ( V_116 & ( 1 << 4 ) )
|| ( ! ( V_118 & ( 1 << 1 ) ) && ( V_120 & ( 1 << 0 ) ) ) )
V_76 -> V_128 |= ( 1 << 2 ) ;
if ( V_117 & ( 1 << 7 ) )
V_76 -> V_127 |= ( 1 << 1 ) ;
if ( V_117 & ( 1 << 3 ) )
V_76 -> V_128 |= ( 1 << 1 ) ;
if ( ( V_117 & ( 1 << 0 ) ) || ( V_119 & ( 1 << 2 ) ) )
V_76 -> V_129 |= ( 1 << 5 ) ;
if ( V_117 & ( 1 << 1 ) )
V_76 -> V_129 |= ( 1 << 6 ) ;
if ( V_117 & ( 1 << 2 ) ) {
if ( ! ( V_119 & ( 1 << 1 ) ) ) {
V_119 |= ( 1 << 1 ) ;
F_4 ( V_125 , V_119 ) ;
F_91 ( L_22 ) ;
}
F_91 ( L_23 ) ;
F_91 ( L_24 ) ;
}
if ( V_119 & ( 1 << 0 ) )
V_76 -> V_112 |= ( 1 << 0 ) ;
if ( V_119 & ( 1 << 1 ) )
V_76 -> V_112 |= ( 1 << 1 ) ;
V_76 -> V_114 = F_1 ( V_115 ) & 0x3f ;
} else {
int V_1 ;
bool V_130 ;
F_6 ( V_121 ) ;
V_1 = F_1 ( V_123 ) ;
if ( V_76 -> type == V_95 || V_76 -> type == V_97 ||
V_76 -> type == V_99 || V_76 -> type == V_101 ||
V_76 -> type == V_103 ) {
V_76 -> V_113 = 1 ;
} else {
if ( V_1 & 0x0f ) {
F_90 ( L_25 ) ;
V_76 -> V_113 = 1 ;
}
}
if ( V_1 & ( 1 << 6 ) )
V_76 -> V_128 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_76 -> V_127 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_131 ) ;
if ( V_1 & ( 1 << 1 ) )
V_76 -> V_128 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_76 -> V_127 |= ( 1 << 1 ) ;
if ( ( V_76 -> type == V_91 || V_76 -> type == V_93 )
&& ! ( V_76 -> V_113 ) )
V_76 -> V_132 = F_1 ( V_133 ) ;
V_1 = F_1 ( V_125 ) ;
V_130 = V_76 -> type == V_103 && ( V_1 & ( 1 << 2 ) ) ;
if ( ( V_76 -> type == V_93 || V_130 ) && ! ( V_1 & ( 1 << 1 ) ) ) {
V_1 |= ( 1 << 1 ) ;
F_4 ( V_125 , V_1 ) ;
F_91 ( L_26 ) ;
}
if ( V_1 & ( 1 << 0 ) )
V_76 -> V_112 |= ( 1 << 0 ) ;
if ( ( V_1 & ( 1 << 1 ) ) || V_76 -> type == V_95 ||
V_76 -> type == V_97 ||
V_76 -> type == V_99 ||
V_76 -> type == V_101 )
V_76 -> V_112 |= ( 1 << 1 ) ;
if ( V_130 ) {
V_76 -> V_129 |= ( 1 << 5 ) | ( 1 << 6 ) ;
V_76 -> V_134 |= ( 1 << 2 ) ;
}
V_76 -> V_114 = F_1 ( V_115 ) & 0x3f ;
}
if ( V_76 -> V_114 )
F_90 ( L_27 ) ;
V_78 = F_92 ( V_135 ) ;
V_79 = F_92 ( V_136 ) ;
if ( V_78 && V_79 ) {
if ( strcmp ( V_78 , L_28 ) == 0
&& strcmp ( V_79 , L_29 ) == 0 ) {
F_90 ( L_30 ) ;
V_76 -> V_128 = ( 1 << 1 ) ;
}
}
exit:
F_9 () ;
return V_54 ;
}
static void F_93 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_94 ( V_137 ) ;
struct V_75 * V_76 = F_95 ( V_17 ) ;
int V_53 ;
F_96 ( & V_17 -> V_138 , & V_139 ) ;
for ( V_53 = 0 ; V_53 < 9 ; V_53 ++ ) {
if ( V_76 -> V_129 & ( 1 << V_53 ) )
continue;
F_96 ( & V_17 -> V_138 , & V_140 [ V_53 ] ) ;
if ( V_141 [ V_53 ] )
F_97 ( & V_17 -> V_138 ,
V_141 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( ! ( V_10 -> V_142 & ( 1 << V_53 ) ) )
continue;
F_96 ( & V_17 -> V_138 , & V_143 [ V_53 ] ) ;
if ( F_98 ( V_10 ) )
F_97 ( & V_17 -> V_138 ,
V_144 [ V_53 ] ) ;
if ( V_76 -> V_114 )
F_97 ( & V_17 -> V_138 ,
V_145 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < 5 ; V_53 ++ ) {
if ( ! ( V_10 -> V_146 & ( 1 << V_53 ) ) )
continue;
F_96 ( & V_17 -> V_138 , & V_147 [ V_53 ] ) ;
if ( V_76 -> V_114 )
F_97 ( & V_17 -> V_138 ,
V_148 [ V_53 ] ) ;
if ( V_53 < 3 && ! F_50 ( V_10 ) )
F_97 ( & V_17 -> V_138 ,
V_149 [ V_53 ] ) ;
}
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_76 -> V_128 & ( 1 << 0 ) )
continue;
F_96 ( & V_17 -> V_138 , & V_150 [ V_53 ] ) ;
if ( F_61 ( V_10 ) )
F_96 ( & V_17 -> V_138 ,
& V_151 [ V_53 ] ) ;
}
if ( ! V_76 -> V_113 )
F_96 ( & V_17 -> V_138 , & V_152 ) ;
F_96 ( & V_17 -> V_138 , & V_153 ) ;
}
static int F_99 ( struct V_154 * V_137 )
{
struct V_9 * V_10 ;
struct V_155 * V_156 ;
struct V_16 * V_17 = & V_137 -> V_17 ;
struct V_75 * V_76 = F_95 ( V_17 ) ;
int V_54 = 0 , V_53 ;
int V_157 ;
int V_158 ;
V_156 = F_100 ( V_137 , V_159 , 0 ) ;
if ( ! F_101 ( & V_137 -> V_17 , V_156 -> V_160 , V_161 ,
V_7 ) ) {
F_62 ( V_17 , L_31 ,
( unsigned long ) V_156 -> V_160 ,
( unsigned long ) ( V_156 -> V_160 + V_161 - 1 ) ) ;
return - V_8 ;
}
V_10 = F_102 ( & V_137 -> V_17 , sizeof( struct V_9 ) , V_162 ) ;
if ( ! V_10 )
return - V_163 ;
V_10 -> V_164 = V_156 -> V_160 ;
V_10 -> type = V_76 -> type ;
V_10 -> V_165 = V_166 [ V_76 -> type ] . V_165 ;
V_10 -> V_167 = V_166 [ V_76 -> type ] . V_167 ;
V_10 -> V_168 = V_166 [ V_76 -> type ] . V_168 ;
V_10 -> V_73 = V_166 [ V_76 -> type ] . V_73 ;
switch ( V_10 -> type ) {
case V_84 :
if ( V_76 -> V_110 >= 0x03 ) {
V_10 -> V_165 &= ~ V_169 ;
V_10 -> V_165 |= V_170 ;
}
break;
case V_86 :
if ( V_76 -> V_110 >= 0x08 ) {
V_10 -> V_165 &= ~ V_169 ;
V_10 -> V_165 |= V_170 ;
}
break;
default:
break;
}
if ( ( F_40 ( V_10 , V_66 ) & 0x80 )
|| F_40 ( V_10 , V_171 ) != 0x90 )
return - V_80 ;
F_103 ( V_137 , V_10 ) ;
F_104 ( & V_10 -> V_27 ) ;
V_157 = F_105 ( V_17 ) ;
if ( F_12 ( V_10 ) ) {
if ( V_76 -> V_112 & ( 1 << 0 ) )
V_10 -> V_13 |= ( 1 << 3 ) ;
if ( V_76 -> V_112 & ( 1 << 1 ) )
V_10 -> V_13 |= ( 1 << 7 ) ;
if ( V_76 -> V_112 & ( 1 << 2 ) )
V_10 -> V_13 |= ( 1 << 8 ) ;
} else if ( V_76 -> type == V_103 || V_76 -> type == V_105 ) {
if ( V_76 -> V_112 & ( 1 << 0 ) )
V_10 -> V_13 |= ( 1 << 3 ) ;
if ( V_76 -> V_112 & ( 1 << 1 ) )
V_10 -> V_13 |= ( 1 << 7 ) ;
}
V_10 -> V_142 = 0x07 ;
if ( V_76 -> V_134 & ( 1 << 2 ) ) {
if ( V_76 -> type == V_103
&& ! ( F_40 ( V_10 , V_38 ) & 0x80 ) )
V_10 -> V_142 &= ~ ( 1 << 2 ) ;
}
F_106 ( V_137 ) ;
V_54 = F_107 ( & V_17 -> V_138 , & V_139 ) ;
if ( V_54 )
return V_54 ;
for ( V_53 = 0 ; V_53 < 9 ; V_53 ++ ) {
if ( V_76 -> V_129 & ( 1 << V_53 ) )
continue;
V_54 = F_107 ( & V_17 -> V_138 , & V_140 [ V_53 ] ) ;
if ( V_54 )
goto error;
if ( V_76 -> V_114 && V_141 [ V_53 ] ) {
V_54 = F_108 ( & V_17 -> V_138 ,
V_141 [ V_53 ] ) ;
if ( V_54 )
goto error;
}
}
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( ! ( V_10 -> V_142 & ( 1 << V_53 ) ) )
continue;
V_54 = F_107 ( & V_17 -> V_138 , & V_143 [ V_53 ] ) ;
if ( V_54 )
goto error;
if ( F_98 ( V_10 ) ) {
V_54 = F_108 ( & V_17 -> V_138 ,
V_144 [ V_53 ] ) ;
if ( V_54 )
goto error;
}
if ( V_76 -> V_114 ) {
V_54 = F_108 ( & V_17 -> V_138 ,
V_145 [ V_53 ] ) ;
if ( V_54 )
goto error;
}
}
V_158 = 1 ;
for ( V_53 = 0 ; V_53 < 5 ; V_53 ++ ) {
if ( ! ( V_10 -> V_146 & ( 1 << V_53 ) ) )
continue;
V_54 = F_107 ( & V_17 -> V_138 , & V_147 [ V_53 ] ) ;
if ( V_54 )
goto error;
if ( V_53 < 3 && ! F_50 ( V_10 ) ) {
V_54 = F_108 ( & V_17 -> V_138 ,
V_149 [ V_53 ] ) ;
if ( V_54 )
goto error;
}
if ( V_76 -> V_114 ) {
V_54 = F_108 ( & V_17 -> V_138 ,
V_148 [ V_53 ] ) ;
if ( V_54 )
goto error;
if ( ! V_158 )
continue;
if ( F_109 ( & V_17 -> V_138 ,
V_148 [ V_53 ] ,
V_172 | V_173 ) )
F_110 ( V_17 , L_32 ,
V_53 + 1 ) ;
V_158 = 0 ;
}
}
if ( V_157 ) {
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_76 -> V_128 & ( 1 << V_53 ) )
continue;
V_54 = F_107 ( & V_17 -> V_138 ,
& V_150 [ V_53 ] ) ;
if ( V_54 )
goto error;
if ( ! F_61 ( V_10 ) )
continue;
V_54 = F_107 ( & V_17 -> V_138 ,
& V_151 [ V_53 ] ) ;
if ( V_54 )
goto error;
}
}
if ( ! V_76 -> V_113 ) {
V_10 -> V_68 = F_111 () ;
V_10 -> V_69 = V_76 -> V_132 ;
V_54 = F_107 ( & V_17 -> V_138 , & V_152 ) ;
if ( V_54 )
goto error;
}
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( ! ( V_76 -> V_112 & ( 1 << V_53 ) ) )
continue;
V_54 = F_108 ( & V_17 -> V_138 ,
V_174 [ V_53 ] ) ;
if ( V_54 )
goto error;
}
V_10 -> V_175 = F_112 ( V_17 ) ;
if ( F_113 ( V_10 -> V_175 ) ) {
V_54 = F_114 ( V_10 -> V_175 ) ;
goto error;
}
return 0 ;
error:
F_93 ( V_17 ) ;
return V_54 ;
}
static int F_115 ( struct V_154 * V_137 )
{
struct V_9 * V_10 = F_94 ( V_137 ) ;
F_116 ( V_10 -> V_175 ) ;
F_93 ( & V_137 -> V_17 ) ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 , T_1 V_1 )
{
F_117 ( V_1 , V_10 -> V_164 + V_176 ) ;
return F_118 ( V_10 -> V_164 + V_177 ) ;
}
static void F_30 ( struct V_9 * V_10 , T_1 V_1 , T_1 V_178 )
{
F_117 ( V_1 , V_10 -> V_164 + V_176 ) ;
F_117 ( V_178 , V_10 -> V_164 + V_177 ) ;
}
static int F_105 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_57 = F_40 ( V_10 , V_58 ) ;
if ( ( V_57 & 0x87 ) == 0 ) {
if ( V_179 ) {
int V_53 ;
T_1 V_180 [ 3 ] ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ )
V_180 [ V_53 ] = F_40 ( V_10 ,
F_64 ( V_53 ) ) ;
if ( ! ( ( V_180 [ 0 ] | V_180 [ 1 ] | V_180 [ 2 ] ) & 0x80 ) ) {
F_119 ( V_17 ,
L_33 ) ;
F_30 ( V_10 , V_58 ,
V_57 | 0x87 ) ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ )
F_30 ( V_10 ,
F_64 ( V_53 ) ,
0x7f & ~ V_180 [ V_53 ] ) ;
return 1 ;
}
F_119 ( V_17 ,
L_34 ) ;
}
F_119 ( V_17 ,
L_35 ) ;
return 0 ;
} else if ( V_179 ) {
F_119 ( V_17 ,
L_36 ) ;
}
return 1 ;
}
static void F_106 ( struct V_154 * V_137 )
{
struct V_75 * V_76 = F_95 ( & V_137 -> V_17 ) ;
struct V_9 * V_10 = F_94 ( V_137 ) ;
int V_57 , V_53 ;
T_1 V_181 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
V_10 -> V_60 [ V_53 ] = V_53 ;
V_10 -> V_45 [ V_53 ] = 0x7f ;
V_10 -> V_56 [ V_53 ] [ 3 ] = 0x7f ;
}
for ( V_53 = 0 ; V_53 < 8 ; V_53 ++ ) {
V_57 = F_40 ( V_10 , F_31 ( V_53 ) ) ;
if ( V_57 == 0xff )
F_30 ( V_10 , F_31 ( V_53 ) , 0 ) ;
}
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
V_57 = F_40 ( V_10 , F_39 ( V_53 ) ) ;
if ( V_57 == 0xff )
F_30 ( V_10 , F_39 ( V_53 ) , 127 ) ;
}
V_57 = F_40 ( V_10 , V_182 ) ;
if ( ( V_57 & 0xff ) == 0 ) {
F_30 ( V_10 , V_182 , 0xff ) ;
}
V_181 = 0x70 & ~ ( V_76 -> V_127 << 4 ) ;
V_10 -> V_40 = F_40 ( V_10 , V_59 ) ;
if ( ( V_10 -> V_40 & V_181 ) == 0 ) {
V_10 -> V_40 |= V_181 ;
F_30 ( V_10 , V_59 ,
V_10 -> V_40 ) ;
}
V_10 -> V_146 = ( V_10 -> V_40 >> 4 ) & 0x07 ;
if ( F_50 ( V_10 ) ) {
V_57 = F_40 ( V_10 , V_183 ) ;
if ( ~ V_57 & 0x07 & V_10 -> V_146 ) {
F_110 ( & V_137 -> V_17 ,
L_37 ) ;
F_30 ( V_10 , V_183 ,
V_57 | 0x07 ) ;
}
if ( V_10 -> type != V_84 && V_10 -> type != V_103 &&
V_10 -> type != V_105 ) {
if ( V_57 & ( 1 << 4 ) )
V_10 -> V_146 |= ( 1 << 3 ) ;
if ( V_57 & ( 1 << 5 ) )
V_10 -> V_146 |= ( 1 << 4 ) ;
}
}
V_10 -> V_146 &= ~ V_76 -> V_127 ;
F_30 ( V_10 , V_66 ,
( F_40 ( V_10 , V_66 ) & 0x3e )
| ( V_184 ? 0x41 : 0x01 ) ) ;
}
static void F_120 ( struct V_9 * V_10 , int V_11 )
{
V_10 -> V_41 [ V_11 ] = F_40 ( V_10 , F_64 ( V_11 ) ) ;
if ( F_20 ( V_10 ) ) {
V_10 -> V_60 [ V_11 ] = V_10 -> V_41 [ V_11 ] & 0x03 ;
V_10 -> V_45 [ V_11 ] = F_40 ( V_10 ,
F_66 ( V_11 ) ) ;
} else {
if ( V_10 -> V_41 [ V_11 ] & 0x80 )
V_10 -> V_60 [ V_11 ] = V_10 -> V_41 [ V_11 ] & 0x03 ;
else
V_10 -> V_45 [ V_11 ] = V_10 -> V_41 [ V_11 ] & 0x7f ;
}
if ( F_61 ( V_10 ) ) {
int V_53 ;
for ( V_53 = 0 ; V_53 < 5 ; V_53 ++ )
V_10 -> V_55 [ V_11 ] [ V_53 ] = F_40 ( V_10 ,
F_76 ( V_11 , V_53 ) ) ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ )
V_10 -> V_56 [ V_11 ] [ V_53 ] = F_40 ( V_10 ,
F_73 ( V_11 , V_53 ) ) ;
}
}
static struct V_9 * F_25 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_53 ;
F_29 ( & V_10 -> V_27 ) ;
if ( F_121 ( V_185 , V_10 -> V_186 + V_187 + V_187 / 2 )
|| ! V_10 -> V_31 ) {
if ( V_184 ) {
F_30 ( V_10 , V_66 ,
F_40 ( V_10 , V_66 ) | 0x40 ) ;
}
for ( V_53 = 0 ; V_53 <= 7 ; V_53 ++ ) {
V_10 -> V_24 [ V_53 ] [ 0 ] =
F_40 ( V_10 , F_122 ( V_53 ) ) ;
V_10 -> V_24 [ V_53 ] [ 1 ] =
F_40 ( V_10 , F_31 ( V_53 ) ) ;
V_10 -> V_24 [ V_53 ] [ 2 ] =
F_40 ( V_10 , F_32 ( V_53 ) ) ;
}
V_10 -> V_24 [ 8 ] [ 0 ] = F_40 ( V_10 , F_122 ( 8 ) ) ;
for ( V_53 = 0 ; V_53 < 5 ; V_53 ++ ) {
if ( ! ( V_10 -> V_146 & ( 1 << V_53 ) ) )
continue;
V_10 -> V_43 [ V_53 ] [ 1 ] =
F_40 ( V_10 , V_48 [ V_53 ] ) ;
V_10 -> V_43 [ V_53 ] [ 0 ] = F_40 ( V_10 ,
V_188 [ V_53 ] ) ;
if ( F_50 ( V_10 ) ) {
V_10 -> V_43 [ V_53 ] [ 0 ] |= F_40 ( V_10 ,
V_189 [ V_53 ] ) << 8 ;
V_10 -> V_43 [ V_53 ] [ 1 ] |= F_40 ( V_10 ,
V_49 [ V_53 ] ) << 8 ;
}
}
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( ! ( V_10 -> V_142 & ( 1 << V_53 ) ) )
continue;
V_10 -> V_28 [ V_53 ] [ 0 ] =
F_40 ( V_10 , F_123 ( V_53 ) ) ;
V_10 -> V_28 [ V_53 ] [ 1 ] =
F_40 ( V_10 , F_38 ( V_53 ) ) ;
V_10 -> V_28 [ V_53 ] [ 2 ] =
F_40 ( V_10 , F_39 ( V_53 ) ) ;
if ( F_98 ( V_10 ) )
V_10 -> V_28 [ V_53 ] [ 3 ] =
F_40 ( V_10 ,
V_32 [ V_53 ] ) ;
}
if ( ( V_10 -> V_146 & 0x07 ) && ! F_50 ( V_10 ) ) {
V_53 = F_40 ( V_10 , V_50 ) ;
V_10 -> V_44 [ 0 ] = V_53 & 0x07 ;
V_10 -> V_44 [ 1 ] = ( V_53 >> 3 ) & 0x07 ;
V_10 -> V_44 [ 2 ] = ( V_53 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_63 =
F_40 ( V_10 , V_190 ) |
( F_40 ( V_10 , V_191 ) << 8 ) |
( F_40 ( V_10 , V_192 ) << 16 ) ;
V_10 -> V_67 = F_40 ( V_10 , V_30 ) ;
V_10 -> V_40 = F_40 ( V_10 ,
V_59 ) ;
V_10 -> V_46 = F_40 ( V_10 , V_58 ) ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ )
F_120 ( V_10 , V_53 ) ;
V_10 -> V_35 = F_40 ( V_10 , V_37 ) ;
V_10 -> V_36 = F_40 ( V_10 , V_38 ) ;
if ( V_10 -> type == V_86 || V_10 -> type == V_89 ) {
V_10 -> V_69 = F_40 ( V_10 , V_193 ) ;
V_10 -> V_69 &= 0x3f ;
}
V_10 -> V_186 = V_185 ;
V_10 -> V_31 = 1 ;
}
F_33 ( & V_10 -> V_27 ) ;
return V_10 ;
}
static int T_5 F_124 ( unsigned short V_74 ,
const struct V_75 * V_76 )
{
struct V_155 V_156 = {
. V_160 = V_74 + V_194 ,
. V_195 = V_74 + V_194 + V_161 - 1 ,
. V_73 = V_7 ,
. V_196 = V_159 ,
} ;
int V_54 ;
V_54 = F_125 ( & V_156 ) ;
if ( V_54 )
goto exit;
V_137 = F_126 ( V_7 , V_74 ) ;
if ( ! V_137 ) {
V_54 = - V_163 ;
F_127 ( L_38 ) ;
goto exit;
}
V_54 = F_128 ( V_137 , & V_156 , 1 ) ;
if ( V_54 ) {
F_127 ( L_39 , V_54 ) ;
goto V_197;
}
V_54 = F_129 ( V_137 , V_76 ,
sizeof( struct V_75 ) ) ;
if ( V_54 ) {
F_127 ( L_40 ) ;
goto V_197;
}
V_54 = F_130 ( V_137 ) ;
if ( V_54 ) {
F_127 ( L_41 , V_54 ) ;
goto V_197;
}
return 0 ;
V_197:
F_131 ( V_137 ) ;
exit:
return V_54 ;
}
static int T_5 F_132 ( void )
{
int V_54 ;
unsigned short V_198 = 0 ;
struct V_75 V_76 ;
memset ( & V_76 , 0 , sizeof( struct V_75 ) ) ;
V_54 = F_88 ( & V_198 , & V_76 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_133 ( & V_199 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_124 ( V_198 , & V_76 ) ;
if ( V_54 ) {
F_134 ( & V_199 ) ;
return V_54 ;
}
return 0 ;
}
static void T_6 F_135 ( void )
{
F_136 ( V_137 ) ;
F_134 ( & V_199 ) ;
}
