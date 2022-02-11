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
if ( V_39 == 0 && V_10 -> type != V_41 )
return 0 ;
if ( V_10 -> V_42 [ V_11 ] & 0x80 )
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
int V_43 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
V_43 = F_50 ( V_10 ) ?
F_51 ( V_10 -> V_44 [ V_11 ] [ V_23 ] ) :
F_52 ( V_10 -> V_44 [ V_11 ] [ V_23 ] ,
F_53 ( V_10 -> V_45 [ V_11 ] ) ) ;
return sprintf ( V_20 , L_1 , V_43 ) ;
}
static T_3 F_54 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_53 ( V_10 -> V_45 [ V_11 ] ) ) ;
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
F_21 ( V_10 , V_10 -> V_46 [ V_11 ] ) ) ;
}
static T_3 F_57 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
int V_23 = ( V_10 -> V_47 >> 4 ) & 0x07 ;
unsigned int V_48 ;
V_48 = V_49 [ V_23 ] / ( F_20 ( V_10 ) ? 256 : 128 ) ;
return sprintf ( V_20 , L_7 , V_48 ) ;
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
V_10 -> V_44 [ V_11 ] [ V_23 ] = F_18 ( V_4 ) ;
F_30 ( V_10 , V_50 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_23 ] & 0xff ) ;
F_30 ( V_10 , V_51 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_23 ] >> 8 ) ;
} else {
V_1 = F_40 ( V_10 , V_52 ) ;
switch ( V_11 ) {
case 0 :
V_10 -> V_45 [ V_11 ] = V_1 & 0x07 ;
break;
case 1 :
V_10 -> V_45 [ V_11 ] = ( V_1 >> 3 ) & 0x07 ;
break;
case 2 :
V_10 -> V_45 [ V_11 ] = ( V_1 & 0x40 ) ? 3 : 1 ;
break;
}
V_10 -> V_44 [ V_11 ] [ V_23 ] =
F_17 ( V_4 , F_53 ( V_10 -> V_45 [ V_11 ] ) ) ;
F_30 ( V_10 , V_50 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_23 ] ) ;
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
int V_53 ;
T_1 V_54 ;
if ( F_28 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_54 = F_40 ( V_10 , V_52 ) ;
V_53 = F_52 ( V_10 -> V_44 [ V_11 ] [ 1 ] , F_53 ( V_10 -> V_45 [ V_11 ] ) ) ;
switch ( V_11 ) {
case 0 :
case 1 :
V_10 -> V_45 [ V_11 ] = F_22 ( V_4 ) ;
break;
case 2 :
if ( V_4 < 8 )
V_10 -> V_45 [ V_11 ] = 1 ;
else
V_10 -> V_45 [ V_11 ] = 3 ;
}
V_4 = V_54 & 0x80 ;
V_4 |= ( V_10 -> V_45 [ 0 ] & 0x07 ) ;
V_4 |= ( V_10 -> V_45 [ 1 ] & 0x07 ) << 3 ;
if ( V_10 -> V_45 [ 2 ] == 3 )
V_4 |= 0x1 << 6 ;
F_30 ( V_10 , V_52 , V_4 ) ;
V_10 -> V_44 [ V_11 ] [ 1 ] = F_17 ( V_53 , F_53 ( V_10 -> V_45 [ V_11 ] ) ) ;
F_30 ( V_10 , V_50 [ V_11 ] , V_10 -> V_44 [ V_11 ] [ 1 ] ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static int F_60 ( struct V_16 * V_17 , int V_11 )
{
const struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_55 , V_56 = 0 ;
if ( F_61 ( V_10 ) ) {
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_10 -> V_57 [ V_11 ] [ V_55 ] > V_10 -> V_57 [ V_11 ] [ V_55 + 1 ] )
V_56 = - V_26 ;
}
for ( V_55 = 0 ; V_55 < 2 ; V_55 ++ ) {
if ( V_10 -> V_58 [ V_11 ] [ V_55 ] > V_10 -> V_58 [ V_11 ] [ V_55 + 1 ] )
V_56 = - V_26 ;
}
}
if ( V_56 ) {
F_62 ( V_17 ,
L_8 ) ;
F_62 ( V_17 , L_9 ) ;
}
return V_56 ;
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
if ( V_4 == 0 && V_10 -> type == V_41 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
if ( V_4 == 0 ) {
int V_59 ;
V_59 = F_40 ( V_10 , V_60 ) ;
F_30 ( V_10 , V_60 , V_59 | ( 1 << V_11 ) ) ;
V_10 -> V_40 &= ~ ( 1 << V_11 ) ;
F_30 ( V_10 , V_61 ,
V_10 -> V_40 ) ;
} else {
if ( V_4 == 1 )
V_10 -> V_42 [ V_11 ] = F_20 ( V_10 ) ?
V_10 -> V_62 [ V_11 ] :
V_10 -> V_46 [ V_11 ] ;
else
V_10 -> V_42 [ V_11 ] = 0x80 | V_10 -> V_62 [ V_11 ] ;
F_30 ( V_10 , F_64 ( V_11 ) , V_10 -> V_42 [ V_11 ] ) ;
if ( V_10 -> type != V_41 ) {
V_10 -> V_40 |= ( 1 << V_11 ) ;
F_30 ( V_10 , V_61 ,
V_10 -> V_40 ) ;
}
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
if ( V_10 -> V_42 [ V_11 ] & 0x80 ) {
F_33 ( & V_10 -> V_27 ) ;
return - V_8 ;
}
V_10 -> V_46 [ V_11 ] = F_19 ( V_10 , V_4 ) ;
F_30 ( V_10 , F_66 ( V_11 ) ,
V_10 -> V_46 [ V_11 ] ) ;
} else {
V_10 -> V_46 [ V_11 ] = F_19 ( V_10 , V_4 ) ;
if ( ! ( V_10 -> V_42 [ V_11 ] & 0x80 ) ) {
V_10 -> V_42 [ V_11 ] = V_10 -> V_46 [ V_11 ] ;
F_30 ( V_10 , F_64 ( V_11 ) ,
V_10 -> V_42 [ V_11 ] ) ;
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
int V_55 ;
if ( F_28 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
V_4 = F_15 ( V_4 , 0 , 1000000 ) ;
V_4 *= F_20 ( V_10 ) ? 256 : 128 ;
for ( V_55 = 0 ; V_55 < 7 ; V_55 ++ ) {
if ( V_4 > ( V_49 [ V_55 ] + V_49 [ V_55 + 1 ] ) / 2 )
break;
}
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_47 = F_40 ( V_10 , V_60 ) & 0x8f ;
V_10 -> V_47 |= V_55 << 4 ;
F_30 ( V_10 , V_60 , V_10 -> V_47 ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_68 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_33 * V_34 = F_43 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
int V_63 ;
if ( V_10 -> V_62 [ V_11 ] < 3 )
V_63 = 1 << V_10 -> V_62 [ V_11 ] ;
else
V_63 = 0 ;
return sprintf ( V_20 , L_1 , V_63 ) ;
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
V_10 -> V_62 [ V_11 ] = V_1 ;
if ( V_10 -> V_42 [ V_11 ] & 0x80 ) {
V_10 -> V_42 [ V_11 ] = 0x80 | V_10 -> V_62 [ V_11 ] ;
F_30 ( V_10 , F_64 ( V_11 ) , V_10 -> V_42 [ V_11 ] ) ;
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
int V_64 = V_34 -> V_23 ;
return sprintf ( V_20 , L_1 ,
F_21 ( V_10 , V_10 -> V_58 [ V_11 ] [ V_64 ] ) ) ;
}
static T_3 F_72 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
struct V_21 * V_34 =
F_24 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_64 = V_34 -> V_23 ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_58 [ V_11 ] [ V_64 ] = F_19 ( V_10 , V_4 ) ;
F_30 ( V_10 , F_73 ( V_11 , V_64 ) ,
V_10 -> V_58 [ V_11 ] [ V_64 ] ) ;
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
int V_64 = V_34 -> V_23 ;
return sprintf ( V_20 , L_1 , F_35 ( V_10 -> V_57 [ V_11 ] [ V_64 ] ) ) ;
}
static T_3 F_75 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
struct V_21 * V_34 =
F_24 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_64 = V_34 -> V_23 ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 < - 128000 || V_4 > 127000 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_57 [ V_11 ] [ V_64 ] = F_41 ( V_4 ) ;
F_30 ( V_10 , F_76 ( V_11 , V_64 ) ,
V_10 -> V_57 [ V_11 ] [ V_64 ] ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_77 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_7 , V_10 -> V_65 ) ;
}
static T_3 F_78 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
int V_66 = F_43 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_7 , ( V_10 -> V_65 >> V_66 ) & 1 ) ;
}
static T_3 F_79 ( struct V_16 * V_17 , struct V_18
* V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
int V_67 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0 || V_4 != 0 )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_67 = F_40 ( V_10 , V_68 ) ;
if ( V_67 < 0 ) {
V_25 = V_67 ;
} else {
V_67 |= 1 << 5 ;
F_30 ( V_10 , V_68 , V_67 ) ;
V_10 -> V_31 = 0 ;
}
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_80 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
int V_66 = F_43 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_7 , ( V_10 -> V_69 >> V_66 ) & 1 ) ;
}
static T_3 F_81 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
int V_66 = F_43 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
long V_4 ;
if ( F_37 ( V_20 , 10 , & V_4 ) < 0
|| ( V_4 != 0 && V_4 != 1 ) )
return - V_26 ;
F_29 ( & V_10 -> V_27 ) ;
V_10 -> V_69 = F_40 ( V_10 , V_30 ) ;
if ( V_4 )
V_10 -> V_69 |= ( 1 << V_66 ) ;
else
V_10 -> V_69 &= ~ ( 1 << V_66 ) ;
F_30 ( V_10 , V_30 , V_10 -> V_69 ) ;
F_33 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_82 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
return sprintf ( V_20 , L_7 , V_10 -> V_70 ) ;
}
static T_3 F_83 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
unsigned long V_4 ;
if ( F_28 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
V_10 -> V_70 = V_4 ;
return V_25 ;
}
static T_3 F_84 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_25 ( V_17 ) ;
return sprintf ( V_20 , L_11 , ( long ) F_85 ( V_10 -> V_71 , V_10 -> V_70 ) ) ;
}
static T_3 F_86 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
static const char * const V_72 [] = {
L_12 ,
L_13 ,
L_14 ,
} ;
static const char * const V_73 [] = {
L_15 ,
L_16 ,
L_14 ,
} ;
struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_11 = F_43 ( V_19 ) -> V_23 ;
return sprintf ( V_20 , L_17 , F_12 ( V_10 ) ? V_73 [ V_11 ]
: V_72 [ V_11 ] ) ;
}
static T_3 F_87 ( struct V_16 * V_17 , struct V_18
* V_74 , char * V_20 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
return sprintf ( V_20 , L_17 , V_10 -> V_75 ) ;
}
static int T_5 F_88 ( unsigned short * V_76 ,
struct V_77 * V_78 )
{
int V_56 ;
T_2 V_79 ;
const char * V_80 , * V_81 ;
const struct V_82 * V_67 ;
V_56 = F_7 () ;
if ( V_56 )
return V_56 ;
V_56 = - V_83 ;
V_79 = V_84 ? V_84 : F_5 ( V_85 ) ;
switch ( V_79 ) {
case V_86 :
V_78 -> type = V_87 ;
break;
case V_88 :
V_78 -> type = V_89 ;
break;
case V_90 :
case V_91 :
V_78 -> type = V_92 ;
break;
case V_93 :
V_78 -> type = V_94 ;
break;
case V_95 :
V_78 -> type = V_96 ;
break;
case V_97 :
V_78 -> type = V_98 ;
break;
case V_99 :
V_78 -> type = V_100 ;
break;
case V_101 :
V_78 -> type = V_102 ;
break;
case V_103 :
V_78 -> type = V_104 ;
break;
case V_105 :
V_78 -> type = V_106 ;
break;
case V_107 :
V_78 -> type = V_108 ;
break;
case V_109 :
V_78 -> type = V_110 ;
break;
case V_111 :
V_78 -> type = V_112 ;
break;
case V_113 :
V_78 -> type = V_114 ;
break;
case V_115 :
case V_116 :
V_78 -> type = V_41 ;
break;
case V_117 :
V_78 -> type = V_118 ;
break;
case 0xffff :
goto exit;
default:
F_89 ( L_18 , V_79 ) ;
goto exit;
}
F_6 ( V_119 ) ;
if ( ! ( F_1 ( V_120 ) & 0x01 ) ) {
F_90 ( L_19 ) ;
goto exit;
}
* V_76 = F_5 ( V_121 ) & ~ ( V_122 - 1 ) ;
if ( * V_76 == 0 ) {
F_90 ( L_20 ) ;
goto exit;
}
V_56 = 0 ;
V_78 -> V_123 = F_1 ( V_124 ) & 0x0f ;
F_90 ( L_21 , V_79 ,
V_82 [ V_78 -> type ] . V_125 ,
* V_76 , V_78 -> V_123 ) ;
V_67 = & V_82 [ V_78 -> type ] ;
if ( F_91 ( V_67 ) )
V_78 -> V_126 |= ( 1 << 1 ) ;
V_78 -> V_126 |= ( 1 << 2 ) ;
if ( V_78 -> type != V_41 )
V_78 -> V_127 |= ( 1 << 9 ) ;
if ( ! F_92 ( V_67 ) )
V_78 -> V_128 = 1 ;
if ( V_78 -> type == V_87 ) {
F_6 ( 5 ) ;
V_78 -> V_129 = F_1 ( V_130 ) & 0x3f ;
} else if ( V_78 -> type == V_110 ) {
int V_131 , V_132 , V_133 , V_134 , V_135 ;
F_6 ( V_136 ) ;
V_131 = F_1 ( V_137 ) ;
V_132 = F_1 ( V_138 ) ;
V_133 = F_1 ( V_139 ) ;
V_134 = F_1 ( V_140 ) ;
V_135 = F_1 ( V_141 ) ;
if ( ( V_132 & ( 1 << 0 ) ) || ! ( V_134 & ( 1 << 2 ) ) )
V_78 -> V_142 |= ( 1 << 2 ) ;
if ( ( V_131 & ( 1 << 4 ) )
|| ( ! ( V_133 & ( 1 << 1 ) ) && ( V_135 & ( 1 << 0 ) ) ) )
V_78 -> V_143 |= ( 1 << 2 ) ;
if ( V_132 & ( 1 << 7 ) )
V_78 -> V_142 |= ( 1 << 1 ) ;
if ( V_132 & ( 1 << 3 ) )
V_78 -> V_143 |= ( 1 << 1 ) ;
if ( ( V_132 & ( 1 << 0 ) ) || ( V_134 & ( 1 << 2 ) ) )
V_78 -> V_127 |= ( 1 << 5 ) ;
if ( V_132 & ( 1 << 1 ) )
V_78 -> V_127 |= ( 1 << 6 ) ;
if ( V_132 & ( 1 << 2 ) ) {
if ( ! ( V_134 & ( 1 << 1 ) ) ) {
V_134 |= ( 1 << 1 ) ;
F_4 ( V_140 , V_134 ) ;
F_93 ( L_22 ) ;
}
F_93 ( L_23 ) ;
F_93 ( L_24 ) ;
}
if ( V_134 & ( 1 << 0 ) )
V_78 -> V_126 |= ( 1 << 0 ) ;
if ( V_134 & ( 1 << 1 ) )
V_78 -> V_126 |= ( 1 << 1 ) ;
V_78 -> V_129 = F_1 ( V_130 ) & 0x3f ;
} else if ( V_78 -> type == V_41 ) {
int V_132 , V_144 ;
F_6 ( V_136 ) ;
V_132 = F_1 ( V_138 ) ;
if ( V_132 & ( 1 << 6 ) )
V_78 -> V_143 |= ( 1 << 2 ) ;
if ( V_132 & ( 1 << 7 ) )
V_78 -> V_142 |= ( 1 << 2 ) ;
V_144 = F_1 ( V_145 ) ;
if ( V_144 & ( 1 << 1 ) )
V_78 -> V_143 |= ( 1 << 1 ) ;
if ( V_144 & ( 1 << 2 ) )
V_78 -> V_142 |= ( 1 << 1 ) ;
V_78 -> V_127 |= ( 1 << 5 ) ;
V_78 -> V_127 |= ( 1 << 6 ) ;
V_78 -> V_126 |= ( 1 << 3 ) ;
V_78 -> V_129 = F_1 ( V_130 ) & 0x3f ;
} else if ( V_78 -> type == V_118 ) {
int V_1 ;
F_6 ( V_136 ) ;
V_1 = F_1 ( V_146 ) ;
if ( ! ( V_1 & ( 1 << 5 ) ) )
V_78 -> V_142 |= ( 1 << 3 ) ;
if ( ! ( V_1 & ( 1 << 4 ) ) )
V_78 -> V_142 |= ( 1 << 4 ) ;
V_1 = F_1 ( V_138 ) ;
if ( V_1 & ( 1 << 6 ) )
V_78 -> V_143 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_78 -> V_142 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_145 ) ;
if ( V_1 & ( 1 << 1 ) )
V_78 -> V_143 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_78 -> V_142 |= ( 1 << 1 ) ;
V_78 -> V_129 = F_1 ( V_130 ) & 0x3f ;
} else {
int V_1 ;
bool V_147 ;
F_6 ( V_136 ) ;
V_1 = F_1 ( V_138 ) ;
if ( ! V_78 -> V_128 ) {
if ( V_1 & 0x0f ) {
F_90 ( L_25 ) ;
V_78 -> V_128 = 1 ;
}
}
if ( V_1 & ( 1 << 6 ) )
V_78 -> V_143 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_78 -> V_142 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_145 ) ;
if ( V_1 & ( 1 << 1 ) )
V_78 -> V_143 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_78 -> V_142 |= ( 1 << 1 ) ;
if ( ( V_78 -> type == V_94 || V_78 -> type == V_96 )
&& ! ( V_78 -> V_128 ) )
V_78 -> V_148 = F_1 ( V_149 ) ;
V_1 = F_1 ( V_140 ) ;
V_147 = V_78 -> type == V_108 && ( V_1 & ( 1 << 2 ) ) ;
if ( ( V_78 -> type == V_96 || V_147 ) && ! ( V_1 & ( 1 << 1 ) ) ) {
V_1 |= ( 1 << 1 ) ;
F_4 ( V_140 , V_1 ) ;
F_93 ( L_26 ) ;
}
if ( V_1 & ( 1 << 0 ) )
V_78 -> V_126 |= ( 1 << 0 ) ;
if ( V_1 & ( 1 << 1 ) )
V_78 -> V_126 |= ( 1 << 1 ) ;
if ( V_147 ) {
V_78 -> V_127 |= ( 1 << 5 ) | ( 1 << 6 ) ;
V_78 -> V_150 |= ( 1 << 2 ) ;
}
V_78 -> V_129 = F_1 ( V_130 ) & 0x3f ;
}
if ( V_78 -> V_129 )
F_90 ( L_27 ) ;
V_80 = F_94 ( V_151 ) ;
V_81 = F_94 ( V_152 ) ;
if ( V_80 && V_81 ) {
if ( strcmp ( V_80 , L_28 ) == 0
&& strcmp ( V_81 , L_29 ) == 0 ) {
F_90 ( L_30 ) ;
V_78 -> V_143 = ( 1 << 1 ) ;
}
}
exit:
F_9 () ;
return V_56 ;
}
static void F_95 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_96 ( V_153 ) ;
struct V_77 * V_78 = F_97 ( V_17 ) ;
int V_55 ;
F_98 ( & V_17 -> V_154 , & V_155 ) ;
for ( V_55 = 0 ; V_55 < 10 ; V_55 ++ ) {
if ( V_78 -> V_127 & ( 1 << V_55 ) )
continue;
F_98 ( & V_17 -> V_154 , & V_156 [ V_55 ] ) ;
if ( V_157 [ V_55 ] )
F_99 ( & V_17 -> V_154 ,
V_157 [ V_55 ] ) ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ! ( V_10 -> V_158 & ( 1 << V_55 ) ) )
continue;
F_98 ( & V_17 -> V_154 , & V_159 [ V_55 ] ) ;
if ( F_100 ( V_10 ) )
F_99 ( & V_17 -> V_154 ,
V_160 [ V_55 ] ) ;
if ( V_78 -> V_129 )
F_99 ( & V_17 -> V_154 ,
V_161 [ V_55 ] ) ;
}
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ ) {
if ( ! ( V_10 -> V_162 & ( 1 << V_55 ) ) )
continue;
F_98 ( & V_17 -> V_154 , & V_163 [ V_55 ] ) ;
if ( V_78 -> V_129 )
F_99 ( & V_17 -> V_154 ,
V_164 [ V_55 ] ) ;
if ( V_55 < 3 && ! F_50 ( V_10 ) )
F_99 ( & V_17 -> V_154 ,
V_165 [ V_55 ] ) ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_78 -> V_143 & ( 1 << V_55 ) )
continue;
F_98 ( & V_17 -> V_154 , & V_166 [ V_55 ] ) ;
if ( F_61 ( V_10 ) )
F_98 ( & V_17 -> V_154 ,
& V_167 [ V_55 ] ) ;
}
if ( ! V_78 -> V_128 )
F_98 ( & V_17 -> V_154 , & V_168 ) ;
F_98 ( & V_17 -> V_154 , & V_169 ) ;
}
static int F_101 ( struct V_170 * V_153 )
{
struct V_9 * V_10 ;
struct V_171 * V_172 ;
struct V_16 * V_17 = & V_153 -> V_17 ;
struct V_77 * V_78 = F_97 ( V_17 ) ;
int V_56 = 0 , V_55 ;
int V_173 ;
int V_174 ;
V_172 = F_102 ( V_153 , V_175 , 0 ) ;
if ( ! F_103 ( & V_153 -> V_17 , V_172 -> V_176 , V_177 ,
V_7 ) ) {
F_62 ( V_17 , L_31 ,
( unsigned long ) V_172 -> V_176 ,
( unsigned long ) ( V_172 -> V_176 + V_177 - 1 ) ) ;
return - V_8 ;
}
V_10 = F_104 ( & V_153 -> V_17 , sizeof( struct V_9 ) , V_178 ) ;
if ( ! V_10 )
return - V_179 ;
V_10 -> V_180 = V_172 -> V_176 ;
V_10 -> type = V_78 -> type ;
V_10 -> V_181 = V_82 [ V_78 -> type ] . V_181 ;
V_10 -> V_182 = V_82 [ V_78 -> type ] . V_182 ;
V_10 -> V_183 = V_82 [ V_78 -> type ] . V_183 ;
V_10 -> V_75 = V_82 [ V_78 -> type ] . V_75 ;
switch ( V_10 -> type ) {
case V_87 :
if ( V_78 -> V_123 >= 0x03 ) {
V_10 -> V_181 &= ~ V_184 ;
V_10 -> V_181 |= V_185 | V_186 ;
}
break;
case V_89 :
if ( V_78 -> V_123 >= 0x08 ) {
V_10 -> V_181 &= ~ V_184 ;
V_10 -> V_181 |= V_185 | V_186 |
V_187 ;
}
break;
default:
break;
}
if ( ( F_40 ( V_10 , V_68 ) & 0x80 )
|| F_40 ( V_10 , V_188 ) != 0x90 )
return - V_83 ;
F_105 ( V_153 , V_10 ) ;
F_106 ( & V_10 -> V_27 ) ;
V_173 = F_107 ( V_17 ) ;
if ( F_12 ( V_10 ) ) {
if ( V_78 -> V_126 & ( 1 << 0 ) )
V_10 -> V_13 |= ( 1 << 3 ) ;
if ( V_78 -> V_126 & ( 1 << 1 ) )
V_10 -> V_13 |= ( 1 << 7 ) ;
if ( V_78 -> V_126 & ( 1 << 2 ) )
V_10 -> V_13 |= ( 1 << 8 ) ;
if ( V_78 -> V_126 & ( 1 << 3 ) )
V_10 -> V_13 |= ( 1 << 9 ) ;
} else if ( V_78 -> type == V_106 || V_78 -> type == V_108 ||
V_78 -> type == V_110 ) {
if ( V_78 -> V_126 & ( 1 << 0 ) )
V_10 -> V_13 |= ( 1 << 3 ) ;
if ( V_78 -> V_126 & ( 1 << 1 ) )
V_10 -> V_13 |= ( 1 << 7 ) ;
}
V_10 -> V_158 = 0x07 ;
if ( V_78 -> V_150 & ( 1 << 2 ) ) {
if ( V_78 -> type == V_108
&& ! ( F_40 ( V_10 , V_38 ) & 0x80 ) )
V_10 -> V_158 &= ~ ( 1 << 2 ) ;
}
F_108 ( V_153 ) ;
V_56 = F_109 ( & V_17 -> V_154 , & V_155 ) ;
if ( V_56 )
return V_56 ;
for ( V_55 = 0 ; V_55 < 10 ; V_55 ++ ) {
if ( V_78 -> V_127 & ( 1 << V_55 ) )
continue;
V_56 = F_109 ( & V_17 -> V_154 , & V_156 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( V_78 -> V_129 && V_157 [ V_55 ] ) {
V_56 = F_110 ( & V_17 -> V_154 ,
V_157 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ! ( V_10 -> V_158 & ( 1 << V_55 ) ) )
continue;
V_56 = F_109 ( & V_17 -> V_154 , & V_159 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( F_100 ( V_10 ) ) {
V_56 = F_110 ( & V_17 -> V_154 ,
V_160 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
if ( V_78 -> V_129 ) {
V_56 = F_110 ( & V_17 -> V_154 ,
V_161 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
}
V_174 = 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ ) {
if ( ! ( V_10 -> V_162 & ( 1 << V_55 ) ) )
continue;
V_56 = F_109 ( & V_17 -> V_154 , & V_163 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( V_55 < 3 && ! F_50 ( V_10 ) ) {
V_56 = F_110 ( & V_17 -> V_154 ,
V_165 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
if ( V_78 -> V_129 ) {
V_56 = F_110 ( & V_17 -> V_154 ,
V_164 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( ! V_174 )
continue;
if ( F_111 ( & V_17 -> V_154 ,
V_164 [ V_55 ] ,
V_189 | V_190 ) )
F_112 ( V_17 , L_32 ,
V_55 + 1 ) ;
V_174 = 0 ;
}
}
if ( V_173 ) {
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_78 -> V_143 & ( 1 << V_55 ) )
continue;
V_56 = F_109 ( & V_17 -> V_154 ,
& V_166 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( ! F_61 ( V_10 ) )
continue;
V_56 = F_109 ( & V_17 -> V_154 ,
& V_167 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
}
if ( ! V_78 -> V_128 ) {
V_10 -> V_70 = F_113 () ;
V_10 -> V_71 = V_78 -> V_148 ;
V_56 = F_109 ( & V_17 -> V_154 , & V_168 ) ;
if ( V_56 )
goto error;
}
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
if ( ! ( V_78 -> V_126 & ( 1 << V_55 ) ) )
continue;
V_56 = F_110 ( & V_17 -> V_154 ,
V_191 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
V_10 -> V_192 = F_114 ( V_17 ) ;
if ( F_115 ( V_10 -> V_192 ) ) {
V_56 = F_116 ( V_10 -> V_192 ) ;
goto error;
}
return 0 ;
error:
F_95 ( V_17 ) ;
return V_56 ;
}
static int F_117 ( struct V_170 * V_153 )
{
struct V_9 * V_10 = F_96 ( V_153 ) ;
F_118 ( V_10 -> V_192 ) ;
F_95 ( & V_153 -> V_17 ) ;
return 0 ;
}
static int F_40 ( struct V_9 * V_10 , T_1 V_1 )
{
F_119 ( V_1 , V_10 -> V_180 + V_193 ) ;
return F_120 ( V_10 -> V_180 + V_194 ) ;
}
static void F_30 ( struct V_9 * V_10 , T_1 V_1 , T_1 V_195 )
{
F_119 ( V_1 , V_10 -> V_180 + V_193 ) ;
F_119 ( V_195 , V_10 -> V_180 + V_194 ) ;
}
static int F_107 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_59 = F_40 ( V_10 , V_60 ) ;
if ( ( V_59 & 0x87 ) == 0 ) {
if ( V_196 ) {
int V_55 ;
T_1 V_197 [ 3 ] ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
V_197 [ V_55 ] = F_40 ( V_10 ,
F_64 ( V_55 ) ) ;
if ( ! ( ( V_197 [ 0 ] | V_197 [ 1 ] | V_197 [ 2 ] ) & 0x80 ) ) {
F_121 ( V_17 ,
L_33 ) ;
F_30 ( V_10 , V_60 ,
V_59 | 0x87 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
F_30 ( V_10 ,
F_64 ( V_55 ) ,
0x7f & ~ V_197 [ V_55 ] ) ;
return 1 ;
}
F_121 ( V_17 ,
L_34 ) ;
}
F_121 ( V_17 ,
L_35 ) ;
return 0 ;
} else if ( V_196 ) {
F_121 ( V_17 ,
L_36 ) ;
}
return 1 ;
}
static void F_108 ( struct V_170 * V_153 )
{
struct V_77 * V_78 = F_97 ( & V_153 -> V_17 ) ;
struct V_9 * V_10 = F_96 ( V_153 ) ;
int V_59 , V_55 ;
T_1 V_198 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_10 -> V_62 [ V_55 ] = V_55 ;
V_10 -> V_46 [ V_55 ] = 0x7f ;
V_10 -> V_58 [ V_55 ] [ 3 ] = 0x7f ;
}
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
V_59 = F_40 ( V_10 , F_31 ( V_55 ) ) ;
if ( V_59 == 0xff )
F_30 ( V_10 , F_31 ( V_55 ) , 0 ) ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_59 = F_40 ( V_10 , F_39 ( V_55 ) ) ;
if ( V_59 == 0xff )
F_30 ( V_10 , F_39 ( V_55 ) , 127 ) ;
}
V_59 = F_40 ( V_10 , V_199 ) ;
if ( ( V_59 & 0xff ) == 0 ) {
F_30 ( V_10 , V_199 , 0xff ) ;
}
V_198 = 0x70 & ~ ( V_78 -> V_142 << 4 ) ;
V_10 -> V_40 = F_40 ( V_10 , V_61 ) ;
if ( ( V_10 -> V_40 & V_198 ) == 0 ) {
V_10 -> V_40 |= V_198 ;
F_30 ( V_10 , V_61 ,
V_10 -> V_40 ) ;
}
V_10 -> V_162 = ( V_10 -> V_40 >> 4 ) & 0x07 ;
V_59 = F_40 ( V_10 , V_200 ) ;
if ( F_122 ( V_10 ) ) {
if ( ~ V_59 & 0x07 & V_10 -> V_162 ) {
F_112 ( & V_153 -> V_17 ,
L_37 ) ;
F_30 ( V_10 , V_200 ,
V_59 | 0x07 ) ;
}
}
if ( F_123 ( V_10 ) ) {
if ( V_59 & ( 1 << 4 ) )
V_10 -> V_162 |= ( 1 << 3 ) ;
if ( V_59 & ( 1 << 5 ) )
V_10 -> V_162 |= ( 1 << 4 ) ;
if ( F_124 ( V_10 ) && ( V_59 & ( 1 << 2 ) ) )
V_10 -> V_162 |= ( 1 << 5 ) ;
}
V_10 -> V_162 &= ~ V_78 -> V_142 ;
F_30 ( V_10 , V_68 ,
( F_40 ( V_10 , V_68 ) & 0x3e )
| ( V_201 ? 0x41 : 0x01 ) ) ;
}
static void F_125 ( struct V_9 * V_10 , int V_11 )
{
V_10 -> V_42 [ V_11 ] = F_40 ( V_10 , F_64 ( V_11 ) ) ;
if ( F_20 ( V_10 ) ) {
V_10 -> V_62 [ V_11 ] = V_10 -> V_42 [ V_11 ] & 0x03 ;
V_10 -> V_46 [ V_11 ] = F_40 ( V_10 ,
F_66 ( V_11 ) ) ;
} else {
if ( V_10 -> V_42 [ V_11 ] & 0x80 )
V_10 -> V_62 [ V_11 ] = V_10 -> V_42 [ V_11 ] & 0x03 ;
else
V_10 -> V_46 [ V_11 ] = V_10 -> V_42 [ V_11 ] & 0x7f ;
}
if ( F_61 ( V_10 ) ) {
int V_55 ;
for ( V_55 = 0 ; V_55 < 5 ; V_55 ++ )
V_10 -> V_57 [ V_11 ] [ V_55 ] = F_40 ( V_10 ,
F_76 ( V_11 , V_55 ) ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
V_10 -> V_58 [ V_11 ] [ V_55 ] = F_40 ( V_10 ,
F_73 ( V_11 , V_55 ) ) ;
}
}
static struct V_9 * F_25 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_27 ( V_17 ) ;
int V_55 ;
F_29 ( & V_10 -> V_27 ) ;
if ( F_126 ( V_202 , V_10 -> V_203 + V_204 + V_204 / 2 )
|| ! V_10 -> V_31 ) {
if ( V_201 ) {
F_30 ( V_10 , V_68 ,
F_40 ( V_10 , V_68 ) | 0x40 ) ;
}
for ( V_55 = 0 ; V_55 <= 7 ; V_55 ++ ) {
V_10 -> V_24 [ V_55 ] [ 0 ] =
F_40 ( V_10 , F_127 ( V_55 ) ) ;
V_10 -> V_24 [ V_55 ] [ 1 ] =
F_40 ( V_10 , F_31 ( V_55 ) ) ;
V_10 -> V_24 [ V_55 ] [ 2 ] =
F_40 ( V_10 , F_32 ( V_55 ) ) ;
}
V_10 -> V_24 [ 8 ] [ 0 ] = F_40 ( V_10 , F_127 ( 8 ) ) ;
if ( V_10 -> type == V_41 )
V_10 -> V_24 [ 9 ] [ 0 ] = F_40 ( V_10 , 0x2f ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ ) {
if ( ! ( V_10 -> V_162 & ( 1 << V_55 ) ) )
continue;
V_10 -> V_44 [ V_55 ] [ 1 ] =
F_40 ( V_10 , V_50 [ V_55 ] ) ;
V_10 -> V_44 [ V_55 ] [ 0 ] = F_40 ( V_10 ,
V_205 [ V_55 ] ) ;
if ( F_50 ( V_10 ) ) {
V_10 -> V_44 [ V_55 ] [ 0 ] |= F_40 ( V_10 ,
V_206 [ V_55 ] ) << 8 ;
V_10 -> V_44 [ V_55 ] [ 1 ] |= F_40 ( V_10 ,
V_51 [ V_55 ] ) << 8 ;
}
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ! ( V_10 -> V_158 & ( 1 << V_55 ) ) )
continue;
V_10 -> V_28 [ V_55 ] [ 0 ] =
F_40 ( V_10 , F_128 ( V_55 ) ) ;
V_10 -> V_28 [ V_55 ] [ 1 ] =
F_40 ( V_10 , F_38 ( V_55 ) ) ;
V_10 -> V_28 [ V_55 ] [ 2 ] =
F_40 ( V_10 , F_39 ( V_55 ) ) ;
if ( F_100 ( V_10 ) )
V_10 -> V_28 [ V_55 ] [ 3 ] =
F_40 ( V_10 ,
V_32 [ V_55 ] ) ;
}
if ( ( V_10 -> V_162 & 0x07 ) && ! F_50 ( V_10 ) ) {
V_55 = F_40 ( V_10 , V_52 ) ;
V_10 -> V_45 [ 0 ] = V_55 & 0x07 ;
V_10 -> V_45 [ 1 ] = ( V_55 >> 3 ) & 0x07 ;
V_10 -> V_45 [ 2 ] = ( V_55 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_65 =
F_40 ( V_10 , V_207 ) |
( F_40 ( V_10 , V_208 ) << 8 ) |
( F_40 ( V_10 , V_209 ) << 16 ) ;
V_10 -> V_69 = F_40 ( V_10 , V_30 ) ;
V_10 -> V_40 = F_40 ( V_10 ,
V_61 ) ;
V_10 -> V_47 = F_40 ( V_10 , V_60 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
F_125 ( V_10 , V_55 ) ;
V_10 -> V_35 = F_40 ( V_10 , V_37 ) ;
V_10 -> V_36 = F_40 ( V_10 , V_38 ) ;
if ( V_10 -> type == V_89 || V_10 -> type == V_92 ) {
V_10 -> V_71 = F_40 ( V_10 , V_210 ) ;
V_10 -> V_71 &= 0x3f ;
}
V_10 -> V_203 = V_202 ;
V_10 -> V_31 = 1 ;
}
F_33 ( & V_10 -> V_27 ) ;
return V_10 ;
}
static int T_5 F_129 ( unsigned short V_76 ,
const struct V_77 * V_78 )
{
struct V_171 V_172 = {
. V_176 = V_76 + V_211 ,
. V_212 = V_76 + V_211 + V_177 - 1 ,
. V_75 = V_7 ,
. V_213 = V_175 ,
} ;
int V_56 ;
V_56 = F_130 ( & V_172 ) ;
if ( V_56 )
goto exit;
V_153 = F_131 ( V_7 , V_76 ) ;
if ( ! V_153 ) {
V_56 = - V_179 ;
F_132 ( L_38 ) ;
goto exit;
}
V_56 = F_133 ( V_153 , & V_172 , 1 ) ;
if ( V_56 ) {
F_132 ( L_39 , V_56 ) ;
goto V_214;
}
V_56 = F_134 ( V_153 , V_78 ,
sizeof( struct V_77 ) ) ;
if ( V_56 ) {
F_132 ( L_40 ) ;
goto V_214;
}
V_56 = F_135 ( V_153 ) ;
if ( V_56 ) {
F_132 ( L_41 , V_56 ) ;
goto V_214;
}
return 0 ;
V_214:
F_136 ( V_153 ) ;
exit:
return V_56 ;
}
static int T_5 F_137 ( void )
{
int V_56 ;
unsigned short V_215 = 0 ;
struct V_77 V_78 ;
memset ( & V_78 , 0 , sizeof( struct V_77 ) ) ;
V_56 = F_88 ( & V_215 , & V_78 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_138 ( & V_216 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_129 ( V_215 , & V_78 ) ;
if ( V_56 ) {
F_139 ( & V_216 ) ;
return V_56 ;
}
return 0 ;
}
static void T_6 F_140 ( void )
{
F_141 ( V_153 ) ;
F_139 ( & V_216 ) ;
}
