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
int V_12 ;
if ( F_12 ( V_10 ) )
V_12 = 120 ;
else if ( F_13 ( V_10 ) )
V_12 = 109 ;
else
V_12 = 160 ;
if ( V_10 -> V_13 & ( 1 << V_11 ) )
V_12 <<= 1 ;
return V_12 ;
}
static T_1 F_14 ( const struct V_9 * V_10 , int V_11 , long V_4 )
{
V_4 = F_15 ( V_4 * 10 , F_11 ( V_10 , V_11 ) ) ;
return F_16 ( V_4 , 0 , 255 ) ;
}
static int F_17 ( const struct V_9 * V_10 , int V_11 , int V_4 )
{
return F_15 ( V_4 * F_11 ( V_10 , V_11 ) , 10 ) ;
}
static inline T_1 F_18 ( long V_14 , int div )
{
if ( V_14 == 0 )
return 255 ;
V_14 = F_16 ( V_14 , 1 , 1000000 ) ;
return F_16 ( ( 1350000 + V_14 * div / 2 ) / ( V_14 * div ) , 1 , 254 ) ;
}
static inline T_2 F_19 ( long V_14 )
{
if ( V_14 == 0 )
return 0xffff ;
return F_16 ( ( 1350000 + V_14 ) / ( V_14 * 2 ) , 1 , 0xfffe ) ;
}
static T_1 F_20 ( const struct V_9 * V_10 , long V_4 )
{
if ( F_21 ( V_10 ) )
return V_4 ;
else
return V_4 >> 1 ;
}
static int F_22 ( const struct V_9 * V_10 , T_1 V_1 )
{
if ( F_21 ( V_10 ) )
return V_1 ;
else
return ( V_1 & 0x7f ) << 1 ;
}
static int F_23 ( int V_4 )
{
int V_15 = 0 ;
while ( V_15 < 7 && ( V_4 >>= 1 ) )
V_15 ++ ;
return V_15 ;
}
static T_3 F_24 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_25 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_17 ( V_10 , V_11 , V_10 -> V_24 [ V_11 ] [ V_23 ] ) ) ;
}
static T_3 F_27 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_21 * V_22 = F_25 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
unsigned long V_4 ;
if ( F_29 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
V_10 -> V_24 [ V_11 ] [ V_23 ] = F_14 ( V_10 , V_11 , V_4 ) ;
F_31 ( V_10 ,
V_23 == 1 ? F_32 ( V_11 )
: F_33 ( V_11 ) ,
V_10 -> V_24 [ V_11 ] [ V_23 ] ) ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_35 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_25 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_36 ( V_10 -> V_28 [ V_11 ] [ V_23 ] ) ) ;
}
static T_3 F_37 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_21 * V_22 = F_25 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
T_1 V_1 , V_29 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
switch ( V_23 ) {
default:
case 1 :
V_1 = F_39 ( V_11 ) ;
break;
case 2 :
V_1 = F_40 ( V_11 ) ;
break;
case 3 :
V_29 = F_41 ( V_10 , V_30 ) ;
if ( ! ( V_29 & 0x80 ) ) {
V_29 |= 0x80 ;
F_31 ( V_10 , V_30 , V_29 ) ;
}
V_10 -> V_31 = 0 ;
V_1 = V_32 [ V_11 ] ;
break;
}
V_10 -> V_28 [ V_11 ] [ V_23 ] = F_42 ( V_4 ) ;
F_31 ( V_10 , V_1 , V_10 -> V_28 [ V_11 ] [ V_23 ] ) ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_43 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
T_1 V_1 = V_10 -> V_35 ;
T_1 V_36 = V_10 -> V_36 ;
if ( ( F_45 ( V_10 , V_11 ) && ( V_1 >> 6 == V_11 + 1 ) )
|| ( F_46 ( V_10 , V_11 ) && ( V_36 & 0x80 ) ) )
return sprintf ( V_20 , L_2 ) ;
if ( V_1 & ( 1 << V_11 ) )
return sprintf ( V_20 , L_3 ) ;
if ( V_1 & ( 8 << V_11 ) )
return sprintf ( V_20 , L_4 ) ;
return sprintf ( V_20 , L_5 ) ;
}
static T_3 F_47 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
T_1 V_1 , V_36 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
V_1 = F_41 ( V_10 , V_37 ) ;
V_1 &= ~ ( 1 << V_11 ) ;
V_1 &= ~ ( 8 << V_11 ) ;
if ( F_45 ( V_10 , V_11 ) && ( V_1 >> 6 == V_11 + 1 || V_4 == 6 ) )
V_1 &= 0x3f ;
V_36 = F_41 ( V_10 , V_38 ) ;
if ( F_46 ( V_10 , V_11 ) && ( ( V_36 & 0x80 ) || V_4 == 6 ) )
V_36 &= 0x7f ;
if ( V_4 == 2 ) {
F_48 ( V_17 ,
L_6 ) ;
V_4 = 4 ;
}
if ( V_4 == 3 )
V_1 |= 1 << V_11 ;
else if ( V_4 == 4 )
V_1 |= 8 << V_11 ;
else if ( F_45 ( V_10 , V_11 ) && V_4 == 6 )
V_1 |= ( V_11 + 1 ) << 6 ;
else if ( F_46 ( V_10 , V_11 ) && V_4 == 6 )
V_36 |= 0x80 ;
else if ( V_4 != 0 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
V_10 -> V_35 = V_1 ;
V_10 -> V_36 = V_36 ;
F_31 ( V_10 , V_37 , V_10 -> V_35 ) ;
if ( F_46 ( V_10 , V_11 ) )
F_31 ( V_10 , V_38 , V_10 -> V_36 ) ;
V_10 -> V_31 = 0 ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static int F_49 ( const struct V_9 * V_10 , int V_11 )
{
int V_39 = V_10 -> V_40 & ( 1 << V_11 ) ;
if ( V_39 == 0 && V_10 -> type != V_41 )
return 0 ;
if ( V_10 -> V_42 [ V_11 ] & 0x80 )
return 2 ;
else
return 1 ;
}
static T_3 F_50 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_25 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
int V_43 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
V_43 = F_51 ( V_10 ) ?
F_52 ( V_10 -> V_44 [ V_11 ] [ V_23 ] ) :
F_53 ( V_10 -> V_44 [ V_11 ] [ V_23 ] ,
F_54 ( V_10 -> V_45 [ V_11 ] ) ) ;
return sprintf ( V_20 , L_1 , V_43 ) ;
}
static T_3 F_55 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_54 ( V_10 -> V_45 [ V_11 ] ) ) ;
}
static T_3 F_56 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_1 , F_49 ( V_10 , V_11 ) ) ;
}
static T_3 F_57 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_1 ,
F_22 ( V_10 , V_10 -> V_46 [ V_11 ] ) ) ;
}
static T_3 F_58 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_26 ( V_17 ) ;
int V_23 = ( V_10 -> V_47 >> 4 ) & 0x07 ;
unsigned int V_48 ;
V_48 = V_49 [ V_23 ] / ( F_21 ( V_10 ) ? 256 : 128 ) ;
return sprintf ( V_20 , L_7 , V_48 ) ;
}
static T_3 F_59 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_21 * V_22 = F_25 ( V_19 ) ;
int V_11 = V_22 -> V_11 ;
int V_23 = V_22 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
if ( F_51 ( V_10 ) ) {
V_10 -> V_44 [ V_11 ] [ V_23 ] = F_19 ( V_4 ) ;
F_31 ( V_10 , V_50 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_23 ] & 0xff ) ;
F_31 ( V_10 , V_51 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_23 ] >> 8 ) ;
} else {
V_1 = F_41 ( V_10 , V_52 ) ;
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
F_18 ( V_4 , F_54 ( V_10 -> V_45 [ V_11 ] ) ) ;
F_31 ( V_10 , V_50 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_23 ] ) ;
}
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_60 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
unsigned long V_4 ;
int V_53 ;
T_1 V_54 ;
if ( F_29 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
V_54 = F_41 ( V_10 , V_52 ) ;
V_53 = F_53 ( V_10 -> V_44 [ V_11 ] [ 1 ] , F_54 ( V_10 -> V_45 [ V_11 ] ) ) ;
switch ( V_11 ) {
case 0 :
case 1 :
V_10 -> V_45 [ V_11 ] = F_23 ( V_4 ) ;
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
F_31 ( V_10 , V_52 , V_4 ) ;
V_10 -> V_44 [ V_11 ] [ 1 ] = F_18 ( V_53 , F_54 ( V_10 -> V_45 [ V_11 ] ) ) ;
F_31 ( V_10 , V_50 [ V_11 ] , V_10 -> V_44 [ V_11 ] [ 1 ] ) ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static int F_61 ( struct V_16 * V_17 , int V_11 )
{
const struct V_9 * V_10 = F_28 ( V_17 ) ;
int V_55 , V_56 = 0 ;
if ( F_62 ( V_10 ) ) {
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
F_63 ( V_17 ,
L_8 ) ;
F_63 ( V_17 , L_9 ) ;
}
return V_56 ;
}
static T_3 F_64 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 2 )
return - V_26 ;
if ( V_4 == 2 ) {
if ( F_61 ( V_17 , V_11 ) < 0 )
return - V_26 ;
}
if ( V_4 == 0 && V_10 -> type == V_41 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
if ( V_4 == 0 ) {
int V_59 ;
V_59 = F_41 ( V_10 , V_60 ) ;
F_31 ( V_10 , V_60 , V_59 | ( 1 << V_11 ) ) ;
V_10 -> V_40 &= ~ ( 1 << V_11 ) ;
F_31 ( V_10 , V_61 ,
V_10 -> V_40 ) ;
} else {
if ( V_4 == 1 )
V_10 -> V_42 [ V_11 ] = F_21 ( V_10 ) ?
V_10 -> V_62 [ V_11 ] :
V_10 -> V_46 [ V_11 ] ;
else
V_10 -> V_42 [ V_11 ] = 0x80 | V_10 -> V_62 [ V_11 ] ;
F_31 ( V_10 , F_65 ( V_11 ) , V_10 -> V_42 [ V_11 ] ) ;
if ( V_10 -> type != V_41 ) {
V_10 -> V_40 |= ( 1 << V_11 ) ;
F_31 ( V_10 , V_61 ,
V_10 -> V_40 ) ;
}
}
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_66 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
if ( F_21 ( V_10 ) ) {
if ( V_10 -> V_42 [ V_11 ] & 0x80 ) {
F_34 ( & V_10 -> V_27 ) ;
return - V_8 ;
}
V_10 -> V_46 [ V_11 ] = F_20 ( V_10 , V_4 ) ;
F_31 ( V_10 , F_67 ( V_11 ) ,
V_10 -> V_46 [ V_11 ] ) ;
} else {
V_10 -> V_46 [ V_11 ] = F_20 ( V_10 , V_4 ) ;
if ( ! ( V_10 -> V_42 [ V_11 ] & 0x80 ) ) {
V_10 -> V_42 [ V_11 ] = V_10 -> V_46 [ V_11 ] ;
F_31 ( V_10 , F_65 ( V_11 ) ,
V_10 -> V_42 [ V_11 ] ) ;
}
}
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_68 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
unsigned long V_4 ;
int V_55 ;
if ( F_29 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
V_4 = F_16 ( V_4 , 0 , 1000000 ) ;
V_4 *= F_21 ( V_10 ) ? 256 : 128 ;
for ( V_55 = 0 ; V_55 < 7 ; V_55 ++ ) {
if ( V_4 > ( V_49 [ V_55 ] + V_49 [ V_55 + 1 ] ) / 2 )
break;
}
F_30 ( & V_10 -> V_27 ) ;
V_10 -> V_47 = F_41 ( V_10 , V_60 ) & 0x8f ;
V_10 -> V_47 |= V_55 << 4 ;
F_31 ( V_10 , V_60 , V_10 -> V_47 ) ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_69 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
int V_63 ;
if ( V_10 -> V_62 [ V_11 ] < 3 )
V_63 = 1 << V_10 -> V_62 [ V_11 ] ;
else
V_63 = 0 ;
return sprintf ( V_20 , L_1 , V_63 ) ;
}
static T_3 F_70 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_33 * V_34 = F_44 ( V_19 ) ;
int V_11 = V_34 -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
T_1 V_1 ;
if ( ! F_62 ( V_10 ) ) {
F_71 ( V_17 , L_10 ) ;
return - V_26 ;
}
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 )
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
F_30 ( & V_10 -> V_27 ) ;
V_10 -> V_62 [ V_11 ] = V_1 ;
if ( V_10 -> V_42 [ V_11 ] & 0x80 ) {
V_10 -> V_42 [ V_11 ] = 0x80 | V_10 -> V_62 [ V_11 ] ;
F_31 ( V_10 , F_65 ( V_11 ) , V_10 -> V_42 [ V_11 ] ) ;
}
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_72 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_9 * V_10 = F_26 ( V_17 ) ;
struct V_21 * V_34 =
F_25 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_64 = V_34 -> V_23 ;
return sprintf ( V_20 , L_1 ,
F_22 ( V_10 , V_10 -> V_58 [ V_11 ] [ V_64 ] ) ) ;
}
static T_3 F_73 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
struct V_21 * V_34 =
F_25 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_64 = V_34 -> V_23 ;
long V_4 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
V_10 -> V_58 [ V_11 ] [ V_64 ] = F_20 ( V_10 , V_4 ) ;
F_31 ( V_10 , F_74 ( V_11 , V_64 ) ,
V_10 -> V_58 [ V_11 ] [ V_64 ] ) ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_75 ( struct V_16 * V_17 ,
struct V_18 * V_19 , char * V_20 )
{
struct V_9 * V_10 = F_26 ( V_17 ) ;
struct V_21 * V_34 =
F_25 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_64 = V_34 -> V_23 ;
return sprintf ( V_20 , L_1 , F_36 ( V_10 -> V_57 [ V_11 ] [ V_64 ] ) ) ;
}
static T_3 F_76 ( struct V_16 * V_17 ,
struct V_18 * V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
struct V_21 * V_34 =
F_25 ( V_19 ) ;
int V_11 = V_34 -> V_11 ;
int V_64 = V_34 -> V_23 ;
long V_4 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 || V_4 < - 128000 || V_4 > 127000 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
V_10 -> V_57 [ V_11 ] [ V_64 ] = F_42 ( V_4 ) ;
F_31 ( V_10 , F_77 ( V_11 , V_64 ) ,
V_10 -> V_57 [ V_11 ] [ V_64 ] ) ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_78 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_7 , V_10 -> V_65 ) ;
}
static T_3 F_79 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
int V_66 = F_44 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_7 , ( V_10 -> V_65 >> V_66 ) & 1 ) ;
}
static T_3 F_80 ( struct V_16 * V_17 , struct V_18
* V_19 , const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
int V_67 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0 || V_4 != 0 )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
V_67 = F_41 ( V_10 , V_68 ) ;
if ( V_67 < 0 ) {
V_25 = V_67 ;
} else {
V_67 |= 1 << 5 ;
F_31 ( V_10 , V_68 , V_67 ) ;
V_10 -> V_31 = 0 ;
}
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_81 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
int V_66 = F_44 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_7 , ( V_10 -> V_69 >> V_66 ) & 1 ) ;
}
static T_3 F_82 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
int V_66 = F_44 ( V_19 ) -> V_23 ;
struct V_9 * V_10 = F_28 ( V_17 ) ;
long V_4 ;
if ( F_38 ( V_20 , 10 , & V_4 ) < 0
|| ( V_4 != 0 && V_4 != 1 ) )
return - V_26 ;
F_30 ( & V_10 -> V_27 ) ;
V_10 -> V_69 = F_41 ( V_10 , V_30 ) ;
if ( V_4 )
V_10 -> V_69 |= ( 1 << V_66 ) ;
else
V_10 -> V_69 &= ~ ( 1 << V_66 ) ;
F_31 ( V_10 , V_30 , V_10 -> V_69 ) ;
F_34 ( & V_10 -> V_27 ) ;
return V_25 ;
}
static T_3 F_83 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
return sprintf ( V_20 , L_7 , V_10 -> V_70 ) ;
}
static T_3 F_84 ( struct V_16 * V_17 , struct V_18 * V_19 ,
const char * V_20 , T_4 V_25 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
unsigned long V_4 ;
if ( F_29 ( V_20 , 10 , & V_4 ) < 0 )
return - V_26 ;
V_10 -> V_70 = V_4 ;
return V_25 ;
}
static T_3 F_85 ( struct V_16 * V_17 , struct V_18 * V_19 ,
char * V_20 )
{
struct V_9 * V_10 = F_26 ( V_17 ) ;
return sprintf ( V_20 , L_11 , ( long ) F_86 ( V_10 -> V_71 , V_10 -> V_70 ) ) ;
}
static T_3 F_87 ( struct V_16 * V_17 , struct V_18 * V_19 ,
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
struct V_9 * V_10 = F_28 ( V_17 ) ;
int V_11 = F_44 ( V_19 ) -> V_23 ;
const char * V_74 ;
if ( F_12 ( V_10 ) || F_13 ( V_10 ) )
V_74 = V_73 [ V_11 ] ;
else
V_74 = V_72 [ V_11 ] ;
return sprintf ( V_20 , L_17 , V_74 ) ;
}
static T_3 F_88 ( struct V_16 * V_17 , struct V_18
* V_75 , char * V_20 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
return sprintf ( V_20 , L_17 , V_10 -> V_76 ) ;
}
static int T_5 F_89 ( unsigned short * V_77 ,
struct V_78 * V_79 )
{
int V_56 ;
T_2 V_80 ;
const char * V_81 , * V_82 ;
const struct V_83 * V_67 ;
V_56 = F_7 () ;
if ( V_56 )
return V_56 ;
V_56 = - V_84 ;
V_80 = V_85 ? V_85 : F_5 ( V_86 ) ;
switch ( V_80 ) {
case V_87 :
V_79 -> type = V_88 ;
break;
case V_89 :
V_79 -> type = V_90 ;
break;
case V_91 :
case V_92 :
V_79 -> type = V_93 ;
break;
case V_94 :
V_79 -> type = V_95 ;
break;
case V_96 :
V_79 -> type = V_97 ;
break;
case V_98 :
V_79 -> type = V_99 ;
break;
case V_100 :
V_79 -> type = V_101 ;
break;
case V_102 :
V_79 -> type = V_103 ;
break;
case V_104 :
V_79 -> type = V_105 ;
break;
case V_106 :
V_79 -> type = V_107 ;
break;
case V_108 :
V_79 -> type = V_109 ;
break;
case V_110 :
V_79 -> type = V_111 ;
break;
case V_112 :
V_79 -> type = V_113 ;
break;
case V_114 :
V_79 -> type = V_115 ;
break;
case V_116 :
V_79 -> type = V_117 ;
break;
case V_118 :
case V_119 :
V_79 -> type = V_41 ;
break;
case V_120 :
V_79 -> type = V_121 ;
break;
case 0xffff :
goto exit;
default:
F_90 ( L_18 , V_80 ) ;
goto exit;
}
F_6 ( V_122 ) ;
if ( ! ( F_1 ( V_123 ) & 0x01 ) ) {
F_91 ( L_19 ) ;
goto exit;
}
* V_77 = F_5 ( V_124 ) & ~ ( V_125 - 1 ) ;
if ( * V_77 == 0 ) {
F_91 ( L_20 ) ;
goto exit;
}
V_56 = 0 ;
V_79 -> V_126 = F_1 ( V_127 ) & 0x0f ;
F_91 ( L_21 , V_80 ,
V_83 [ V_79 -> type ] . V_128 ,
* V_77 , V_79 -> V_126 ) ;
V_67 = & V_83 [ V_79 -> type ] ;
if ( F_92 ( V_67 ) )
V_79 -> V_129 |= ( 1 << 1 ) ;
V_79 -> V_129 |= ( 1 << 2 ) ;
if ( V_79 -> type != V_41 )
V_79 -> V_130 |= ( 1 << 9 ) ;
if ( ! F_93 ( V_67 ) )
V_79 -> V_131 = 1 ;
if ( V_79 -> type == V_88 ) {
F_6 ( 5 ) ;
V_79 -> V_132 = F_1 ( V_133 ) & 0x3f ;
} else if ( V_79 -> type == V_113 ) {
int V_134 , V_135 , V_136 , V_137 , V_138 ;
F_6 ( V_139 ) ;
V_134 = F_1 ( V_140 ) ;
V_135 = F_1 ( V_141 ) ;
V_136 = F_1 ( V_142 ) ;
V_137 = F_1 ( V_143 ) ;
V_138 = F_1 ( V_144 ) ;
if ( ( V_135 & ( 1 << 0 ) ) || ! ( V_137 & ( 1 << 2 ) ) )
V_79 -> V_145 |= ( 1 << 2 ) ;
if ( ( V_134 & ( 1 << 4 ) )
|| ( ! ( V_136 & ( 1 << 1 ) ) && ( V_138 & ( 1 << 0 ) ) ) )
V_79 -> V_146 |= ( 1 << 2 ) ;
if ( V_135 & ( 1 << 7 ) )
V_79 -> V_145 |= ( 1 << 1 ) ;
if ( V_135 & ( 1 << 3 ) )
V_79 -> V_146 |= ( 1 << 1 ) ;
if ( ( V_135 & ( 1 << 0 ) ) || ( V_137 & ( 1 << 2 ) ) )
V_79 -> V_130 |= ( 1 << 5 ) ;
if ( V_135 & ( 1 << 1 ) )
V_79 -> V_130 |= ( 1 << 6 ) ;
if ( V_135 & ( 1 << 2 ) ) {
if ( ! ( V_137 & ( 1 << 1 ) ) ) {
V_137 |= ( 1 << 1 ) ;
F_4 ( V_143 , V_137 ) ;
F_94 ( L_22 ) ;
}
F_94 ( L_23 ) ;
F_94 ( L_24 ) ;
}
if ( V_137 & ( 1 << 0 ) )
V_79 -> V_129 |= ( 1 << 0 ) ;
if ( V_137 & ( 1 << 1 ) )
V_79 -> V_129 |= ( 1 << 1 ) ;
V_79 -> V_132 = F_1 ( V_133 ) & 0x3f ;
} else if ( V_79 -> type == V_41 ) {
int V_135 , V_147 ;
F_6 ( V_139 ) ;
V_135 = F_1 ( V_141 ) ;
if ( V_135 & ( 1 << 6 ) )
V_79 -> V_146 |= ( 1 << 2 ) ;
if ( V_135 & ( 1 << 7 ) )
V_79 -> V_145 |= ( 1 << 2 ) ;
V_147 = F_1 ( V_148 ) ;
if ( V_147 & ( 1 << 1 ) )
V_79 -> V_146 |= ( 1 << 1 ) ;
if ( V_147 & ( 1 << 2 ) )
V_79 -> V_145 |= ( 1 << 1 ) ;
V_79 -> V_130 |= ( 1 << 5 ) ;
V_79 -> V_130 |= ( 1 << 6 ) ;
V_79 -> V_129 |= ( 1 << 3 ) ;
V_79 -> V_132 = F_1 ( V_133 ) & 0x3f ;
} else if ( V_79 -> type == V_121 ) {
int V_1 ;
F_6 ( V_139 ) ;
V_1 = F_1 ( V_149 ) ;
if ( ! ( V_1 & ( 1 << 5 ) ) )
V_79 -> V_145 |= ( 1 << 3 ) ;
if ( ! ( V_1 & ( 1 << 4 ) ) )
V_79 -> V_145 |= ( 1 << 4 ) ;
V_1 = F_1 ( V_141 ) ;
if ( V_1 & ( 1 << 6 ) )
V_79 -> V_146 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_79 -> V_145 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_148 ) ;
if ( V_1 & ( 1 << 1 ) )
V_79 -> V_146 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_79 -> V_145 |= ( 1 << 1 ) ;
V_79 -> V_132 = F_1 ( V_133 ) & 0x3f ;
} else {
int V_1 ;
bool V_150 ;
F_6 ( V_139 ) ;
V_1 = F_1 ( V_141 ) ;
if ( ! V_79 -> V_131 ) {
if ( V_1 & 0x0f ) {
F_91 ( L_25 ) ;
V_79 -> V_131 = 1 ;
}
}
if ( V_1 & ( 1 << 6 ) )
V_79 -> V_146 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_79 -> V_145 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_148 ) ;
if ( V_1 & ( 1 << 1 ) )
V_79 -> V_146 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_79 -> V_145 |= ( 1 << 1 ) ;
if ( ( V_79 -> type == V_95 || V_79 -> type == V_97 )
&& ! ( V_79 -> V_131 ) )
V_79 -> V_151 = F_1 ( V_152 ) ;
V_1 = F_1 ( V_143 ) ;
V_150 = V_79 -> type == V_111 && ( V_1 & ( 1 << 2 ) ) ;
if ( ( V_79 -> type == V_97 || V_150 ) && ! ( V_1 & ( 1 << 1 ) ) ) {
V_1 |= ( 1 << 1 ) ;
F_4 ( V_143 , V_1 ) ;
F_94 ( L_26 ) ;
}
if ( V_1 & ( 1 << 0 ) )
V_79 -> V_129 |= ( 1 << 0 ) ;
if ( V_1 & ( 1 << 1 ) )
V_79 -> V_129 |= ( 1 << 1 ) ;
if ( V_150 ) {
V_79 -> V_130 |= ( 1 << 5 ) | ( 1 << 6 ) ;
V_79 -> V_153 |= ( 1 << 2 ) ;
}
V_79 -> V_132 = F_1 ( V_133 ) & 0x3f ;
}
if ( V_79 -> V_132 )
F_91 ( L_27 ) ;
V_81 = F_95 ( V_154 ) ;
V_82 = F_95 ( V_155 ) ;
if ( V_81 && V_82 ) {
if ( strcmp ( V_81 , L_28 ) == 0
&& strcmp ( V_82 , L_29 ) == 0 ) {
F_91 ( L_30 ) ;
V_79 -> V_146 = ( 1 << 1 ) ;
}
}
exit:
F_9 () ;
return V_56 ;
}
static void F_96 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_97 ( V_156 ) ;
struct V_78 * V_79 = F_98 ( V_17 ) ;
int V_55 ;
F_99 ( & V_17 -> V_157 , & V_158 ) ;
for ( V_55 = 0 ; V_55 < 10 ; V_55 ++ ) {
if ( V_79 -> V_130 & ( 1 << V_55 ) )
continue;
F_99 ( & V_17 -> V_157 , & V_159 [ V_55 ] ) ;
if ( V_160 [ V_55 ] )
F_100 ( & V_17 -> V_157 ,
V_160 [ V_55 ] ) ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ! ( V_10 -> V_161 & ( 1 << V_55 ) ) )
continue;
F_99 ( & V_17 -> V_157 , & V_162 [ V_55 ] ) ;
if ( F_101 ( V_10 ) )
F_100 ( & V_17 -> V_157 ,
V_163 [ V_55 ] ) ;
if ( V_79 -> V_132 )
F_100 ( & V_17 -> V_157 ,
V_164 [ V_55 ] ) ;
}
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ ) {
if ( ! ( V_10 -> V_165 & ( 1 << V_55 ) ) )
continue;
F_99 ( & V_17 -> V_157 , & V_166 [ V_55 ] ) ;
if ( V_79 -> V_132 )
F_100 ( & V_17 -> V_157 ,
V_167 [ V_55 ] ) ;
if ( V_55 < 3 && ! F_51 ( V_10 ) )
F_100 ( & V_17 -> V_157 ,
V_168 [ V_55 ] ) ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_79 -> V_146 & ( 1 << V_55 ) )
continue;
F_99 ( & V_17 -> V_157 , & V_169 [ V_55 ] ) ;
if ( F_62 ( V_10 ) )
F_99 ( & V_17 -> V_157 ,
& V_170 [ V_55 ] ) ;
}
if ( ! V_79 -> V_131 )
F_99 ( & V_17 -> V_157 , & V_171 ) ;
F_99 ( & V_17 -> V_157 , & V_172 ) ;
}
static int F_102 ( struct V_173 * V_156 )
{
struct V_9 * V_10 ;
struct V_174 * V_175 ;
struct V_16 * V_17 = & V_156 -> V_17 ;
struct V_78 * V_79 = F_98 ( V_17 ) ;
int V_56 = 0 , V_55 ;
int V_176 ;
int V_177 ;
V_175 = F_103 ( V_156 , V_178 , 0 ) ;
if ( ! F_104 ( & V_156 -> V_17 , V_175 -> V_179 , V_180 ,
V_7 ) ) {
F_63 ( V_17 , L_31 ,
( unsigned long ) V_175 -> V_179 ,
( unsigned long ) ( V_175 -> V_179 + V_180 - 1 ) ) ;
return - V_8 ;
}
V_10 = F_105 ( & V_156 -> V_17 , sizeof( struct V_9 ) , V_181 ) ;
if ( ! V_10 )
return - V_182 ;
V_10 -> V_183 = V_175 -> V_179 ;
V_10 -> type = V_79 -> type ;
V_10 -> V_184 = V_83 [ V_79 -> type ] . V_184 ;
V_10 -> V_185 = V_83 [ V_79 -> type ] . V_185 ;
V_10 -> V_186 = V_83 [ V_79 -> type ] . V_186 ;
V_10 -> V_76 = V_83 [ V_79 -> type ] . V_76 ;
switch ( V_10 -> type ) {
case V_88 :
if ( V_79 -> V_126 >= 0x03 ) {
V_10 -> V_184 &= ~ V_187 ;
V_10 -> V_184 |= V_188 | V_189 ;
}
break;
case V_90 :
if ( V_79 -> V_126 >= 0x08 ) {
V_10 -> V_184 &= ~ V_187 ;
V_10 -> V_184 |= V_188 | V_189 |
V_190 ;
}
break;
default:
break;
}
if ( ( F_41 ( V_10 , V_68 ) & 0x80 )
|| F_41 ( V_10 , V_191 ) != 0x90 )
return - V_84 ;
F_106 ( V_156 , V_10 ) ;
F_107 ( & V_10 -> V_27 ) ;
V_176 = F_108 ( V_17 ) ;
if ( F_12 ( V_10 ) ) {
if ( V_79 -> V_129 & ( 1 << 0 ) )
V_10 -> V_13 |= ( 1 << 3 ) ;
if ( V_79 -> V_129 & ( 1 << 1 ) )
V_10 -> V_13 |= ( 1 << 7 ) ;
if ( V_79 -> V_129 & ( 1 << 2 ) )
V_10 -> V_13 |= ( 1 << 8 ) ;
if ( V_79 -> V_129 & ( 1 << 3 ) )
V_10 -> V_13 |= ( 1 << 9 ) ;
} else if ( V_79 -> type == V_109 || V_79 -> type == V_111 ||
V_79 -> type == V_113 ) {
if ( V_79 -> V_129 & ( 1 << 0 ) )
V_10 -> V_13 |= ( 1 << 3 ) ;
if ( V_79 -> V_129 & ( 1 << 1 ) )
V_10 -> V_13 |= ( 1 << 7 ) ;
}
V_10 -> V_161 = 0x07 ;
if ( V_79 -> V_153 & ( 1 << 2 ) ) {
if ( V_79 -> type == V_111
&& ! ( F_41 ( V_10 , V_38 ) & 0x80 ) )
V_10 -> V_161 &= ~ ( 1 << 2 ) ;
}
F_109 ( V_156 ) ;
V_56 = F_110 ( & V_17 -> V_157 , & V_158 ) ;
if ( V_56 )
return V_56 ;
for ( V_55 = 0 ; V_55 < 10 ; V_55 ++ ) {
if ( V_79 -> V_130 & ( 1 << V_55 ) )
continue;
V_56 = F_110 ( & V_17 -> V_157 , & V_159 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( V_79 -> V_132 && V_160 [ V_55 ] ) {
V_56 = F_111 ( & V_17 -> V_157 ,
V_160 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ! ( V_10 -> V_161 & ( 1 << V_55 ) ) )
continue;
V_56 = F_110 ( & V_17 -> V_157 , & V_162 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( F_101 ( V_10 ) ) {
V_56 = F_111 ( & V_17 -> V_157 ,
V_163 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
if ( V_79 -> V_132 ) {
V_56 = F_111 ( & V_17 -> V_157 ,
V_164 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
}
V_177 = 1 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ ) {
if ( ! ( V_10 -> V_165 & ( 1 << V_55 ) ) )
continue;
V_56 = F_110 ( & V_17 -> V_157 , & V_166 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( V_55 < 3 && ! F_51 ( V_10 ) ) {
V_56 = F_111 ( & V_17 -> V_157 ,
V_168 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
if ( V_79 -> V_132 ) {
V_56 = F_111 ( & V_17 -> V_157 ,
V_167 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( ! V_177 )
continue;
if ( F_112 ( & V_17 -> V_157 ,
V_167 [ V_55 ] ,
V_192 | V_193 ) )
F_113 ( V_17 , L_32 ,
V_55 + 1 ) ;
V_177 = 0 ;
}
}
if ( V_176 ) {
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( V_79 -> V_146 & ( 1 << V_55 ) )
continue;
V_56 = F_110 ( & V_17 -> V_157 ,
& V_169 [ V_55 ] ) ;
if ( V_56 )
goto error;
if ( ! F_62 ( V_10 ) )
continue;
V_56 = F_110 ( & V_17 -> V_157 ,
& V_170 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
}
if ( ! V_79 -> V_131 ) {
V_10 -> V_70 = F_114 () ;
V_10 -> V_71 = V_79 -> V_151 ;
V_56 = F_110 ( & V_17 -> V_157 , & V_171 ) ;
if ( V_56 )
goto error;
}
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
if ( ! ( V_79 -> V_129 & ( 1 << V_55 ) ) )
continue;
V_56 = F_111 ( & V_17 -> V_157 ,
V_194 [ V_55 ] ) ;
if ( V_56 )
goto error;
}
V_10 -> V_195 = F_115 ( V_17 ) ;
if ( F_116 ( V_10 -> V_195 ) ) {
V_56 = F_117 ( V_10 -> V_195 ) ;
goto error;
}
return 0 ;
error:
F_96 ( V_17 ) ;
return V_56 ;
}
static int F_118 ( struct V_173 * V_156 )
{
struct V_9 * V_10 = F_97 ( V_156 ) ;
F_119 ( V_10 -> V_195 ) ;
F_96 ( & V_156 -> V_17 ) ;
return 0 ;
}
static int F_41 ( struct V_9 * V_10 , T_1 V_1 )
{
F_120 ( V_1 , V_10 -> V_183 + V_196 ) ;
return F_121 ( V_10 -> V_183 + V_197 ) ;
}
static void F_31 ( struct V_9 * V_10 , T_1 V_1 , T_1 V_198 )
{
F_120 ( V_1 , V_10 -> V_183 + V_196 ) ;
F_120 ( V_198 , V_10 -> V_183 + V_197 ) ;
}
static int F_108 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
int V_59 = F_41 ( V_10 , V_60 ) ;
if ( ( V_59 & 0x87 ) == 0 ) {
if ( V_199 ) {
int V_55 ;
T_1 V_200 [ 3 ] ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
V_200 [ V_55 ] = F_41 ( V_10 ,
F_65 ( V_55 ) ) ;
if ( ! ( ( V_200 [ 0 ] | V_200 [ 1 ] | V_200 [ 2 ] ) & 0x80 ) ) {
F_122 ( V_17 ,
L_33 ) ;
F_31 ( V_10 , V_60 ,
V_59 | 0x87 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
F_31 ( V_10 ,
F_65 ( V_55 ) ,
0x7f & ~ V_200 [ V_55 ] ) ;
return 1 ;
}
F_122 ( V_17 ,
L_34 ) ;
}
F_122 ( V_17 ,
L_35 ) ;
return 0 ;
} else if ( V_199 ) {
F_122 ( V_17 ,
L_36 ) ;
}
return 1 ;
}
static void F_109 ( struct V_173 * V_156 )
{
struct V_78 * V_79 = F_98 ( & V_156 -> V_17 ) ;
struct V_9 * V_10 = F_97 ( V_156 ) ;
int V_59 , V_55 ;
T_1 V_201 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_10 -> V_62 [ V_55 ] = V_55 ;
V_10 -> V_46 [ V_55 ] = 0x7f ;
V_10 -> V_58 [ V_55 ] [ 3 ] = 0x7f ;
}
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
V_59 = F_41 ( V_10 , F_32 ( V_55 ) ) ;
if ( V_59 == 0xff )
F_31 ( V_10 , F_32 ( V_55 ) , 0 ) ;
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_59 = F_41 ( V_10 , F_40 ( V_55 ) ) ;
if ( V_59 == 0xff )
F_31 ( V_10 , F_40 ( V_55 ) , 127 ) ;
}
V_59 = F_41 ( V_10 , V_202 ) ;
if ( ( V_59 & 0xff ) == 0 ) {
F_31 ( V_10 , V_202 , 0xff ) ;
}
V_201 = 0x70 & ~ ( V_79 -> V_145 << 4 ) ;
V_10 -> V_40 = F_41 ( V_10 , V_61 ) ;
if ( ( V_10 -> V_40 & V_201 ) == 0 ) {
V_10 -> V_40 |= V_201 ;
F_31 ( V_10 , V_61 ,
V_10 -> V_40 ) ;
}
V_10 -> V_165 = ( V_10 -> V_40 >> 4 ) & 0x07 ;
V_59 = F_41 ( V_10 , V_203 ) ;
if ( F_123 ( V_10 ) ) {
if ( ~ V_59 & 0x07 & V_10 -> V_165 ) {
F_113 ( & V_156 -> V_17 ,
L_37 ) ;
F_31 ( V_10 , V_203 ,
V_59 | 0x07 ) ;
}
}
if ( F_124 ( V_10 ) ) {
if ( V_59 & ( 1 << 4 ) )
V_10 -> V_165 |= ( 1 << 3 ) ;
if ( V_59 & ( 1 << 5 ) )
V_10 -> V_165 |= ( 1 << 4 ) ;
if ( F_125 ( V_10 ) && ( V_59 & ( 1 << 2 ) ) )
V_10 -> V_165 |= ( 1 << 5 ) ;
}
V_10 -> V_165 &= ~ V_79 -> V_145 ;
F_31 ( V_10 , V_68 ,
( F_41 ( V_10 , V_68 ) & 0x3e )
| ( V_204 ? 0x41 : 0x01 ) ) ;
}
static void F_126 ( struct V_9 * V_10 , int V_11 )
{
V_10 -> V_42 [ V_11 ] = F_41 ( V_10 , F_65 ( V_11 ) ) ;
if ( F_21 ( V_10 ) ) {
V_10 -> V_62 [ V_11 ] = V_10 -> V_42 [ V_11 ] & 0x03 ;
V_10 -> V_46 [ V_11 ] = F_41 ( V_10 ,
F_67 ( V_11 ) ) ;
} else {
if ( V_10 -> V_42 [ V_11 ] & 0x80 )
V_10 -> V_62 [ V_11 ] = V_10 -> V_42 [ V_11 ] & 0x03 ;
else
V_10 -> V_46 [ V_11 ] = V_10 -> V_42 [ V_11 ] & 0x7f ;
}
if ( F_62 ( V_10 ) ) {
int V_55 ;
for ( V_55 = 0 ; V_55 < 5 ; V_55 ++ )
V_10 -> V_57 [ V_11 ] [ V_55 ] = F_41 ( V_10 ,
F_77 ( V_11 , V_55 ) ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
V_10 -> V_58 [ V_11 ] [ V_55 ] = F_41 ( V_10 ,
F_74 ( V_11 , V_55 ) ) ;
}
}
static struct V_9 * F_26 ( struct V_16 * V_17 )
{
struct V_9 * V_10 = F_28 ( V_17 ) ;
int V_55 ;
F_30 ( & V_10 -> V_27 ) ;
if ( F_127 ( V_205 , V_10 -> V_206 + V_207 + V_207 / 2 )
|| ! V_10 -> V_31 ) {
if ( V_204 ) {
F_31 ( V_10 , V_68 ,
F_41 ( V_10 , V_68 ) | 0x40 ) ;
}
for ( V_55 = 0 ; V_55 <= 7 ; V_55 ++ ) {
V_10 -> V_24 [ V_55 ] [ 0 ] =
F_41 ( V_10 , F_128 ( V_55 ) ) ;
V_10 -> V_24 [ V_55 ] [ 1 ] =
F_41 ( V_10 , F_32 ( V_55 ) ) ;
V_10 -> V_24 [ V_55 ] [ 2 ] =
F_41 ( V_10 , F_33 ( V_55 ) ) ;
}
V_10 -> V_24 [ 8 ] [ 0 ] = F_41 ( V_10 , F_128 ( 8 ) ) ;
if ( V_10 -> type == V_41 )
V_10 -> V_24 [ 9 ] [ 0 ] = F_41 ( V_10 , 0x2f ) ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ ) {
if ( ! ( V_10 -> V_165 & ( 1 << V_55 ) ) )
continue;
V_10 -> V_44 [ V_55 ] [ 1 ] =
F_41 ( V_10 , V_50 [ V_55 ] ) ;
V_10 -> V_44 [ V_55 ] [ 0 ] = F_41 ( V_10 ,
V_208 [ V_55 ] ) ;
if ( F_51 ( V_10 ) ) {
V_10 -> V_44 [ V_55 ] [ 0 ] |= F_41 ( V_10 ,
V_209 [ V_55 ] ) << 8 ;
V_10 -> V_44 [ V_55 ] [ 1 ] |= F_41 ( V_10 ,
V_51 [ V_55 ] ) << 8 ;
}
}
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ! ( V_10 -> V_161 & ( 1 << V_55 ) ) )
continue;
V_10 -> V_28 [ V_55 ] [ 0 ] =
F_41 ( V_10 , F_129 ( V_55 ) ) ;
V_10 -> V_28 [ V_55 ] [ 1 ] =
F_41 ( V_10 , F_39 ( V_55 ) ) ;
V_10 -> V_28 [ V_55 ] [ 2 ] =
F_41 ( V_10 , F_40 ( V_55 ) ) ;
if ( F_101 ( V_10 ) )
V_10 -> V_28 [ V_55 ] [ 3 ] =
F_41 ( V_10 ,
V_32 [ V_55 ] ) ;
}
if ( ( V_10 -> V_165 & 0x07 ) && ! F_51 ( V_10 ) ) {
V_55 = F_41 ( V_10 , V_52 ) ;
V_10 -> V_45 [ 0 ] = V_55 & 0x07 ;
V_10 -> V_45 [ 1 ] = ( V_55 >> 3 ) & 0x07 ;
V_10 -> V_45 [ 2 ] = ( V_55 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_65 =
F_41 ( V_10 , V_210 ) |
( F_41 ( V_10 , V_211 ) << 8 ) |
( F_41 ( V_10 , V_212 ) << 16 ) ;
V_10 -> V_69 = F_41 ( V_10 , V_30 ) ;
V_10 -> V_40 = F_41 ( V_10 ,
V_61 ) ;
V_10 -> V_47 = F_41 ( V_10 , V_60 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ )
F_126 ( V_10 , V_55 ) ;
V_10 -> V_35 = F_41 ( V_10 , V_37 ) ;
V_10 -> V_36 = F_41 ( V_10 , V_38 ) ;
if ( V_10 -> type == V_90 || V_10 -> type == V_93 ) {
V_10 -> V_71 = F_41 ( V_10 , V_213 ) ;
V_10 -> V_71 &= 0x3f ;
}
V_10 -> V_206 = V_205 ;
V_10 -> V_31 = 1 ;
}
F_34 ( & V_10 -> V_27 ) ;
return V_10 ;
}
static int T_5 F_130 ( unsigned short V_77 ,
const struct V_78 * V_79 )
{
struct V_174 V_175 = {
. V_179 = V_77 + V_214 ,
. V_215 = V_77 + V_214 + V_180 - 1 ,
. V_76 = V_7 ,
. V_216 = V_178 ,
} ;
int V_56 ;
V_56 = F_131 ( & V_175 ) ;
if ( V_56 )
goto exit;
V_156 = F_132 ( V_7 , V_77 ) ;
if ( ! V_156 ) {
V_56 = - V_182 ;
F_133 ( L_38 ) ;
goto exit;
}
V_56 = F_134 ( V_156 , & V_175 , 1 ) ;
if ( V_56 ) {
F_133 ( L_39 , V_56 ) ;
goto V_217;
}
V_56 = F_135 ( V_156 , V_79 ,
sizeof( struct V_78 ) ) ;
if ( V_56 ) {
F_133 ( L_40 ) ;
goto V_217;
}
V_56 = F_136 ( V_156 ) ;
if ( V_56 ) {
F_133 ( L_41 , V_56 ) ;
goto V_217;
}
return 0 ;
V_217:
F_137 ( V_156 ) ;
exit:
return V_56 ;
}
static int T_5 F_138 ( void )
{
int V_56 ;
unsigned short V_218 = 0 ;
struct V_78 V_79 ;
memset ( & V_79 , 0 , sizeof( struct V_78 ) ) ;
V_56 = F_89 ( & V_218 , & V_79 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_139 ( & V_219 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_130 ( V_218 , & V_79 ) ;
if ( V_56 ) {
F_140 ( & V_219 ) ;
return V_56 ;
}
return 0 ;
}
static void T_6 F_141 ( void )
{
F_142 ( V_156 ) ;
F_140 ( & V_219 ) ;
}
