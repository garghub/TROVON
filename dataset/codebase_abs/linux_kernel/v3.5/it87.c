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
static inline int F_11 ( const struct V_9 * V_10 )
{
return V_10 -> type == V_11
|| V_10 -> type == V_12 ;
}
static inline int F_12 ( const struct V_9 * V_10 )
{
return V_10 -> type == V_11
|| V_10 -> type == V_12 ;
}
static int F_13 ( const struct V_9 * V_10 , int V_13 )
{
int V_14 = F_11 ( V_10 ) ? 12 : 16 ;
if ( V_10 -> V_15 & ( 1 << V_13 ) )
V_14 <<= 1 ;
return V_14 ;
}
static T_1 F_14 ( const struct V_9 * V_10 , int V_13 , long V_4 )
{
V_4 = F_15 ( V_4 , F_13 ( V_10 , V_13 ) ) ;
return F_16 ( V_4 , 0 , 255 ) ;
}
static int F_17 ( const struct V_9 * V_10 , int V_13 , int V_4 )
{
return V_4 * F_13 ( V_10 , V_13 ) ;
}
static inline T_1 F_18 ( long V_16 , int div )
{
if ( V_16 == 0 )
return 255 ;
V_16 = F_16 ( V_16 , 1 , 1000000 ) ;
return F_16 ( ( 1350000 + V_16 * div / 2 ) / ( V_16 * div ) , 1 ,
254 ) ;
}
static inline T_2 F_19 ( long V_16 )
{
if ( V_16 == 0 )
return 0xffff ;
return F_16 ( ( 1350000 + V_16 ) / ( V_16 * 2 ) , 1 , 0xfffe ) ;
}
static T_1 F_20 ( const struct V_9 * V_10 , long V_4 )
{
if ( F_12 ( V_10 ) )
return V_4 ;
else
return V_4 >> 1 ;
}
static int F_21 ( const struct V_9 * V_10 , T_1 V_1 )
{
if ( F_12 ( V_10 ) )
return V_1 ;
else
return ( V_1 & 0x7f ) << 1 ;
}
static int F_22 ( int V_4 )
{
int V_17 = 0 ;
while ( V_17 < 7 && ( V_4 >>= 1 ) )
V_17 ++ ;
return V_17 ;
}
static inline int F_23 ( const struct V_9 * V_10 )
{
return ( V_10 -> type == V_18 && V_10 -> V_19 >= 0x03 )
|| ( V_10 -> type == V_20 && V_10 -> V_19 >= 0x08 )
|| V_10 -> type == V_21
|| V_10 -> type == V_22
|| V_10 -> type == V_23
|| V_10 -> type == V_11
|| V_10 -> type == V_12
|| V_10 -> type == V_24
|| V_10 -> type == V_25 ;
}
static inline int F_24 ( const struct V_9 * V_10 )
{
return ( V_10 -> type == V_18 && V_10 -> V_19 < 0x03 )
|| ( V_10 -> type == V_20 && V_10 -> V_19 < 0x08 ) ;
}
static T_3 F_25 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_17 ( V_10 , V_13 , V_10 -> V_34 [ V_13 ] ) ) ;
}
static T_3 F_28 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_17 ( V_10 , V_13 , V_10 -> V_35 [ V_13 ] ) ) ;
}
static T_3 F_29 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_17 ( V_10 , V_13 , V_10 -> V_36 [ V_13 ] ) ) ;
}
static T_3 F_30 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
unsigned long V_4 ;
if ( F_32 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_35 [ V_13 ] = F_14 ( V_10 , V_13 , V_4 ) ;
F_34 ( V_10 , F_35 ( V_13 ) ,
V_10 -> V_35 [ V_13 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_37 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
unsigned long V_4 ;
if ( F_32 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_36 [ V_13 ] = F_14 ( V_10 , V_13 , V_4 ) ;
F_34 ( V_10 , F_38 ( V_13 ) ,
V_10 -> V_36 [ V_13 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_39 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_40 ( V_10 -> V_40 [ V_13 ] ) ) ;
}
static T_3 F_41 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_40 ( V_10 -> V_41 [ V_13 ] ) ) ;
}
static T_3 F_42 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_40 ( V_10 -> V_42 [ V_13 ] ) ) ;
}
static T_3 F_43 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_41 [ V_13 ] = F_45 ( V_4 ) ;
F_34 ( V_10 , F_46 ( V_13 ) , V_10 -> V_41 [ V_13 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_47 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_42 [ V_13 ] = F_45 ( V_4 ) ;
F_34 ( V_10 , F_48 ( V_13 ) , V_10 -> V_42 [ V_13 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_49 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
T_1 V_1 = V_10 -> V_43 ;
if ( V_1 & ( 1 << V_13 ) )
return sprintf ( V_30 , L_2 ) ;
if ( V_1 & ( 8 << V_13 ) )
return sprintf ( V_30 , L_3 ) ;
return sprintf ( V_30 , L_4 ) ;
}
static T_3 F_50 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
V_1 = F_51 ( V_10 , V_44 ) ;
V_1 &= ~ ( 1 << V_13 ) ;
V_1 &= ~ ( 8 << V_13 ) ;
if ( V_4 == 2 ) {
F_52 ( V_27 , L_5
L_6 ) ;
V_4 = 4 ;
}
if ( V_4 == 3 )
V_1 |= 1 << V_13 ;
else if ( V_4 == 4 )
V_1 |= 8 << V_13 ;
else if ( V_4 != 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_43 = V_1 ;
F_34 ( V_10 , V_44 , V_10 -> V_43 ) ;
V_10 -> V_45 = 0 ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static int F_53 ( const struct V_9 * V_10 , int V_13 )
{
int V_46 = V_10 -> V_47 & ( 1 << V_13 ) ;
if ( V_46 == 0 )
return 0 ;
if ( V_10 -> V_48 [ V_13 ] & 0x80 )
return 2 ;
else
return 1 ;
}
static T_3 F_54 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_55 ( V_10 -> V_49 [ V_13 ] ,
F_56 ( V_10 -> V_50 [ V_13 ] ) ) ) ;
}
static T_3 F_57 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_55 ( V_10 -> V_51 [ V_13 ] ,
F_56 ( V_10 -> V_50 [ V_13 ] ) ) ) ;
}
static T_3 F_58 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_56 ( V_10 -> V_50 [ V_13 ] ) ) ;
}
static T_3 F_59 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_53 ( V_10 , V_13 ) ) ;
}
static T_3 F_60 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 ,
F_21 ( V_10 , V_10 -> V_52 [ V_13 ] ) ) ;
}
static T_3 F_61 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_9 * V_10 = F_27 ( V_27 ) ;
int V_33 = ( V_10 -> V_53 >> 4 ) & 0x07 ;
return sprintf ( V_30 , L_7 , V_54 [ V_33 ] ) ;
}
static T_3 F_62 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_1 = F_51 ( V_10 , V_55 ) ;
switch ( V_13 ) {
case 0 :
V_10 -> V_50 [ V_13 ] = V_1 & 0x07 ;
break;
case 1 :
V_10 -> V_50 [ V_13 ] = ( V_1 >> 3 ) & 0x07 ;
break;
case 2 :
V_10 -> V_50 [ V_13 ] = ( V_1 & 0x40 ) ? 3 : 1 ;
break;
}
V_10 -> V_51 [ V_13 ] = F_18 ( V_4 , F_56 ( V_10 -> V_50 [ V_13 ] ) ) ;
F_34 ( V_10 , V_56 [ V_13 ] , V_10 -> V_51 [ V_13 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_63 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
unsigned long V_4 ;
int V_57 ;
T_1 V_58 ;
if ( F_32 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_58 = F_51 ( V_10 , V_55 ) ;
V_57 = F_55 ( V_10 -> V_51 [ V_13 ] , F_56 ( V_10 -> V_50 [ V_13 ] ) ) ;
switch ( V_13 ) {
case 0 :
case 1 :
V_10 -> V_50 [ V_13 ] = F_22 ( V_4 ) ;
break;
case 2 :
if ( V_4 < 8 )
V_10 -> V_50 [ V_13 ] = 1 ;
else
V_10 -> V_50 [ V_13 ] = 3 ;
}
V_4 = V_58 & 0x80 ;
V_4 |= ( V_10 -> V_50 [ 0 ] & 0x07 ) ;
V_4 |= ( V_10 -> V_50 [ 1 ] & 0x07 ) << 3 ;
if ( V_10 -> V_50 [ 2 ] == 3 )
V_4 |= 0x1 << 6 ;
F_34 ( V_10 , V_55 , V_4 ) ;
V_10 -> V_51 [ V_13 ] = F_18 ( V_57 , F_56 ( V_10 -> V_50 [ V_13 ] ) ) ;
F_34 ( V_10 , V_56 [ V_13 ] , V_10 -> V_51 [ V_13 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static int F_64 ( struct V_26 * V_27 , int V_13 )
{
const struct V_9 * V_10 = F_31 ( V_27 ) ;
int V_59 , V_60 = 0 ;
if ( F_24 ( V_10 ) ) {
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( V_10 -> V_61 [ V_13 ] [ V_59 ] > V_10 -> V_61 [ V_13 ] [ V_59 + 1 ] )
V_60 = - V_38 ;
}
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
if ( V_10 -> V_62 [ V_13 ] [ V_59 ] > V_10 -> V_62 [ V_13 ] [ V_59 + 1 ] )
V_60 = - V_38 ;
}
}
if ( V_60 ) {
F_65 ( V_27 , L_8
L_9 ) ;
F_65 ( V_27 , L_10 ) ;
}
return V_60 ;
}
static T_3 F_66 ( struct V_26 * V_27 ,
struct V_28 * V_29 , const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 2 )
return - V_38 ;
if ( V_4 == 2 ) {
if ( F_64 ( V_27 , V_13 ) < 0 )
return - V_38 ;
}
F_33 ( & V_10 -> V_39 ) ;
if ( V_4 == 0 ) {
int V_63 ;
V_63 = F_51 ( V_10 , V_64 ) ;
F_34 ( V_10 , V_64 , V_63 | ( 1 << V_13 ) ) ;
V_10 -> V_47 &= ~ ( 1 << V_13 ) ;
F_34 ( V_10 , V_65 ,
V_10 -> V_47 ) ;
} else {
if ( V_4 == 1 )
V_10 -> V_48 [ V_13 ] = F_12 ( V_10 ) ?
V_10 -> V_66 [ V_13 ] :
V_10 -> V_52 [ V_13 ] ;
else
V_10 -> V_48 [ V_13 ] = 0x80 | V_10 -> V_66 [ V_13 ] ;
F_34 ( V_10 , F_67 ( V_13 ) , V_10 -> V_48 [ V_13 ] ) ;
V_10 -> V_47 |= ( 1 << V_13 ) ;
F_34 ( V_10 , V_65 ,
V_10 -> V_47 ) ;
}
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_68 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
if ( F_12 ( V_10 ) ) {
if ( V_10 -> V_48 [ V_13 ] & 0x80 ) {
F_36 ( & V_10 -> V_39 ) ;
return - V_8 ;
}
V_10 -> V_52 [ V_13 ] = F_20 ( V_10 , V_4 ) ;
F_34 ( V_10 , F_69 ( V_13 ) ,
V_10 -> V_52 [ V_13 ] ) ;
} else {
V_10 -> V_52 [ V_13 ] = F_20 ( V_10 , V_4 ) ;
if ( ! ( V_10 -> V_48 [ V_13 ] & 0x80 ) ) {
V_10 -> V_48 [ V_13 ] = V_10 -> V_52 [ V_13 ] ;
F_34 ( V_10 , F_67 ( V_13 ) ,
V_10 -> V_48 [ V_13 ] ) ;
}
}
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_70 ( struct V_26 * V_27 ,
struct V_28 * V_29 , const char * V_30 , T_4 V_37 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
unsigned long V_4 ;
int V_59 ;
if ( F_32 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
for ( V_59 = 0 ; V_59 < 7 ; V_59 ++ ) {
if ( V_4 > ( V_54 [ V_59 ] + V_54 [ V_59 + 1 ] ) / 2 )
break;
}
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_53 = F_51 ( V_10 , V_64 ) & 0x8f ;
V_10 -> V_53 |= V_59 << 4 ;
F_34 ( V_10 , V_64 , V_10 -> V_53 ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_71 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
int V_67 ;
if ( V_10 -> V_66 [ V_13 ] < 3 )
V_67 = 1 << V_10 -> V_66 [ V_13 ] ;
else
V_67 = 0 ;
return sprintf ( V_30 , L_1 , V_67 ) ;
}
static T_3 F_72 ( struct V_26 * V_27 ,
struct V_28 * V_29 , const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
T_1 V_1 ;
if ( ! F_24 ( V_10 ) ) {
F_73 ( V_27 , L_11 ) ;
return - V_38 ;
}
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
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
return - V_38 ;
}
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_66 [ V_13 ] = V_1 ;
if ( V_10 -> V_48 [ V_13 ] & 0x80 ) {
V_10 -> V_48 [ V_13 ] = 0x80 | V_10 -> V_66 [ V_13 ] ;
F_34 ( V_10 , F_67 ( V_13 ) , V_10 -> V_48 [ V_13 ] ) ;
}
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_74 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_9 * V_10 = F_27 ( V_27 ) ;
struct V_68 * V_32 =
F_75 ( V_29 ) ;
int V_13 = V_32 -> V_13 ;
int V_69 = V_32 -> V_33 ;
return sprintf ( V_30 , L_1 ,
F_21 ( V_10 , V_10 -> V_62 [ V_13 ] [ V_69 ] ) ) ;
}
static T_3 F_76 ( struct V_26 * V_27 ,
struct V_28 * V_29 , const char * V_30 , T_4 V_37 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
struct V_68 * V_32 =
F_75 ( V_29 ) ;
int V_13 = V_32 -> V_13 ;
int V_69 = V_32 -> V_33 ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_62 [ V_13 ] [ V_69 ] = F_20 ( V_10 , V_4 ) ;
F_34 ( V_10 , F_77 ( V_13 , V_69 ) ,
V_10 -> V_62 [ V_13 ] [ V_69 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_78 ( struct V_26 * V_27 ,
struct V_28 * V_29 , char * V_30 )
{
struct V_9 * V_10 = F_27 ( V_27 ) ;
struct V_68 * V_32 =
F_75 ( V_29 ) ;
int V_13 = V_32 -> V_13 ;
int V_69 = V_32 -> V_33 ;
return sprintf ( V_30 , L_1 , F_40 ( V_10 -> V_61 [ V_13 ] [ V_69 ] ) ) ;
}
static T_3 F_79 ( struct V_26 * V_27 ,
struct V_28 * V_29 , const char * V_30 , T_4 V_37 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
struct V_68 * V_32 =
F_75 ( V_29 ) ;
int V_13 = V_32 -> V_13 ;
int V_69 = V_32 -> V_33 ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 || V_4 < - 128000 || V_4 > 127000 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_61 [ V_13 ] [ V_69 ] = F_45 ( V_4 ) ;
F_34 ( V_10 , F_80 ( V_13 , V_69 ) ,
V_10 -> V_61 [ V_13 ] [ V_69 ] ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_81 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_82 ( V_10 -> V_49 [ V_13 ] ) ) ;
}
static T_3 F_83 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_1 , F_82 ( V_10 -> V_51 [ V_13 ] ) ) ;
}
static T_3 F_84 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_31 * V_32 = F_26 ( V_29 ) ;
int V_13 = V_32 -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_51 [ V_13 ] = F_19 ( V_4 ) ;
F_34 ( V_10 , V_56 [ V_13 ] ,
V_10 -> V_51 [ V_13 ] & 0xff ) ;
F_34 ( V_10 , V_70 [ V_13 ] ,
V_10 -> V_51 [ V_13 ] >> 8 ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_85 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_7 , V_10 -> V_71 ) ;
}
static T_3 F_86 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
int V_72 = F_26 ( V_29 ) -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_7 , ( V_10 -> V_71 >> V_72 ) & 1 ) ;
}
static T_3 F_87 ( struct V_26 * V_27 , struct V_28
* V_29 , const char * V_30 , T_4 V_37 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
int V_73 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0 || V_4 != 0 )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_73 = F_51 ( V_10 , V_74 ) ;
if ( V_73 < 0 ) {
V_37 = V_73 ;
} else {
V_73 |= 1 << 5 ;
F_34 ( V_10 , V_74 , V_73 ) ;
V_10 -> V_45 = 0 ;
}
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_88 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
int V_72 = F_26 ( V_29 ) -> V_33 ;
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_7 , ( V_10 -> V_75 >> V_72 ) & 1 ) ;
}
static T_3 F_89 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
int V_72 = F_26 ( V_29 ) -> V_33 ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
long V_4 ;
if ( F_44 ( V_30 , 10 , & V_4 ) < 0
|| ( V_4 != 0 && V_4 != 1 ) )
return - V_38 ;
F_33 ( & V_10 -> V_39 ) ;
V_10 -> V_75 = F_51 ( V_10 , V_76 ) ;
if ( V_4 )
V_10 -> V_75 |= ( 1 << V_72 ) ;
else
V_10 -> V_75 &= ~ ( 1 << V_72 ) ;
F_34 ( V_10 , V_76 , V_10 -> V_75 ) ;
F_36 ( & V_10 -> V_39 ) ;
return V_37 ;
}
static T_3 F_90 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
return sprintf ( V_30 , L_7 , V_10 -> V_77 ) ;
}
static T_3 F_91 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const char * V_30 , T_4 V_37 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
unsigned long V_4 ;
if ( F_32 ( V_30 , 10 , & V_4 ) < 0 )
return - V_38 ;
V_10 -> V_77 = V_4 ;
return V_37 ;
}
static T_3 F_92 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_9 * V_10 = F_27 ( V_27 ) ;
return sprintf ( V_30 , L_12 , ( long ) F_93 ( V_10 -> V_78 , V_10 -> V_77 ) ) ;
}
static T_3 F_94 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
static const char * const V_79 [] = {
L_13 ,
L_14 ,
L_15 ,
} ;
static const char * const V_80 [] = {
L_16 ,
L_17 ,
L_15 ,
} ;
struct V_9 * V_10 = F_31 ( V_27 ) ;
int V_13 = F_26 ( V_29 ) -> V_33 ;
return sprintf ( V_30 , L_18 , F_11 ( V_10 ) ? V_80 [ V_13 ]
: V_79 [ V_13 ] ) ;
}
static T_3 F_95 ( struct V_26 * V_27 , struct V_28
* V_81 , char * V_30 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
return sprintf ( V_30 , L_18 , V_10 -> V_82 ) ;
}
static const struct V_83 *
F_96 ( const struct V_9 * V_10 )
{
return F_23 ( V_10 ) ? V_84 : V_85 ;
}
static int T_5 F_97 ( unsigned short * V_86 ,
struct V_87 * V_88 )
{
int V_60 ;
T_2 V_89 ;
const char * V_90 , * V_91 ;
V_60 = F_7 () ;
if ( V_60 )
return V_60 ;
V_60 = - V_92 ;
V_89 = V_93 ? V_93 : F_5 ( V_94 ) ;
switch ( V_89 ) {
case V_95 :
V_88 -> type = V_18 ;
break;
case V_96 :
V_88 -> type = V_20 ;
break;
case V_97 :
case V_98 :
V_88 -> type = V_21 ;
break;
case V_99 :
V_88 -> type = V_22 ;
break;
case V_100 :
V_88 -> type = V_23 ;
break;
case V_101 :
V_88 -> type = V_11 ;
break;
case V_102 :
V_88 -> type = V_12 ;
break;
case V_103 :
V_88 -> type = V_24 ;
break;
case V_104 :
V_88 -> type = V_25 ;
break;
case 0xffff :
goto exit;
default:
F_98 ( L_19 , V_89 ) ;
goto exit;
}
F_6 ( V_105 ) ;
if ( ! ( F_1 ( V_106 ) & 0x01 ) ) {
F_99 ( L_20 ) ;
goto exit;
}
* V_86 = F_5 ( V_107 ) & ~ ( V_108 - 1 ) ;
if ( * V_86 == 0 ) {
F_99 ( L_21 ) ;
goto exit;
}
V_60 = 0 ;
V_88 -> V_19 = F_1 ( V_109 ) & 0x0f ;
F_99 ( L_22 ,
V_89 , * V_86 , V_88 -> V_19 ) ;
V_88 -> V_110 = ( 1 << 2 ) ;
if ( V_88 -> type == V_18 ) {
V_88 -> V_111 = 1 ;
F_6 ( 5 ) ;
V_88 -> V_112 = F_1 ( V_113 ) & 0x3f ;
} else if ( V_88 -> type == V_25 ) {
int V_114 , V_115 , V_116 , V_117 , V_118 ;
V_88 -> V_111 = 1 ;
F_6 ( V_119 ) ;
V_114 = F_1 ( V_120 ) ;
V_115 = F_1 ( V_121 ) ;
V_116 = F_1 ( V_122 ) ;
V_117 = F_1 ( V_123 ) ;
V_118 = F_1 ( V_124 ) ;
if ( ( V_115 & ( 1 << 0 ) ) || ! ( V_117 & ( 1 << 2 ) ) )
V_88 -> V_125 |= ( 1 << 2 ) ;
if ( ( V_114 & ( 1 << 4 ) )
|| ( ! ( V_116 & ( 1 << 1 ) ) && ( V_118 & ( 1 << 0 ) ) ) )
V_88 -> V_126 |= ( 1 << 2 ) ;
if ( V_115 & ( 1 << 7 ) )
V_88 -> V_125 |= ( 1 << 1 ) ;
if ( V_115 & ( 1 << 3 ) )
V_88 -> V_126 |= ( 1 << 1 ) ;
if ( ( V_115 & ( 1 << 0 ) ) || ( V_117 & ( 1 << 2 ) ) )
V_88 -> V_127 |= ( 1 << 5 ) ;
if ( V_115 & ( 1 << 1 ) )
V_88 -> V_127 |= ( 1 << 6 ) ;
if ( V_115 & ( 1 << 2 ) ) {
if ( ! ( V_117 & ( 1 << 1 ) ) ) {
V_117 |= ( 1 << 1 ) ;
F_4 ( V_123 , V_117 ) ;
F_100 ( L_23 ) ;
}
F_100 ( L_24 ) ;
F_100 ( L_25 ) ;
}
if ( V_117 & ( 1 << 0 ) )
V_88 -> V_110 |= ( 1 << 0 ) ;
if ( V_117 & ( 1 << 1 ) )
V_88 -> V_110 |= ( 1 << 1 ) ;
V_88 -> V_112 = F_1 ( V_113 ) & 0x3f ;
} else {
int V_1 ;
bool V_128 ;
F_6 ( V_119 ) ;
V_1 = F_1 ( V_121 ) ;
if ( V_88 -> type == V_11 || V_88 -> type == V_12 ||
V_88 -> type == V_24 ) {
V_88 -> V_111 = 1 ;
} else {
if ( V_1 & 0x0f ) {
F_99 ( L_26 ) ;
V_88 -> V_111 = 1 ;
}
}
if ( V_1 & ( 1 << 6 ) )
V_88 -> V_126 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_88 -> V_125 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_129 ) ;
if ( V_1 & ( 1 << 1 ) )
V_88 -> V_126 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_88 -> V_125 |= ( 1 << 1 ) ;
if ( ( V_88 -> type == V_22 || V_88 -> type == V_23 )
&& ! ( V_88 -> V_111 ) )
V_88 -> V_130 = F_1 ( V_131 ) ;
V_1 = F_1 ( V_123 ) ;
V_128 = V_88 -> type == V_24 && ( V_1 & ( 1 << 2 ) ) ;
if ( ( V_88 -> type == V_23 || V_128 ) && ! ( V_1 & ( 1 << 1 ) ) ) {
V_1 |= ( 1 << 1 ) ;
F_4 ( V_123 , V_1 ) ;
F_100 ( L_27 ) ;
}
if ( V_1 & ( 1 << 0 ) )
V_88 -> V_110 |= ( 1 << 0 ) ;
if ( ( V_1 & ( 1 << 1 ) ) || V_88 -> type == V_11 ||
V_88 -> type == V_12 )
V_88 -> V_110 |= ( 1 << 1 ) ;
if ( V_128 ) {
V_88 -> V_127 |= ( 1 << 5 ) | ( 1 << 6 ) ;
V_88 -> V_132 |= ( 1 << 2 ) ;
}
V_88 -> V_112 = F_1 ( V_113 ) & 0x3f ;
}
if ( V_88 -> V_112 )
F_99 ( L_28 ) ;
V_90 = F_101 ( V_133 ) ;
V_91 = F_101 ( V_134 ) ;
if ( V_90 && V_91 ) {
if ( strcmp ( V_90 , L_29 ) == 0
&& strcmp ( V_91 , L_30 ) == 0 ) {
F_99 ( L_31 ) ;
V_88 -> V_126 = ( 1 << 1 ) ;
}
}
exit:
F_9 () ;
return V_60 ;
}
static void F_102 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_103 ( V_135 ) ;
struct V_87 * V_88 = V_27 -> V_136 ;
const struct V_83 * V_137 = F_96 ( V_10 ) ;
int V_59 ;
F_104 ( & V_27 -> V_138 , & V_139 ) ;
for ( V_59 = 0 ; V_59 < 9 ; V_59 ++ ) {
if ( V_88 -> V_127 & ( 1 << V_59 ) )
continue;
F_104 ( & V_27 -> V_138 , & V_140 [ V_59 ] ) ;
if ( V_141 [ V_59 ] )
F_105 ( & V_27 -> V_138 ,
V_141 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( ! ( V_10 -> V_142 & ( 1 << V_59 ) ) )
continue;
F_104 ( & V_27 -> V_138 , & V_143 [ V_59 ] ) ;
if ( V_88 -> V_112 )
F_105 ( & V_27 -> V_138 ,
V_144 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < 5 ; V_59 ++ ) {
if ( ! ( V_10 -> V_145 & ( 1 << V_59 ) ) )
continue;
F_104 ( & V_27 -> V_138 , & V_137 [ V_59 ] ) ;
if ( V_88 -> V_112 )
F_105 ( & V_27 -> V_138 ,
V_146 [ V_59 ] ) ;
}
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( V_88 -> V_126 & ( 1 << 0 ) )
continue;
F_104 ( & V_27 -> V_138 , & V_147 [ V_59 ] ) ;
if ( F_24 ( V_10 ) )
F_104 ( & V_27 -> V_138 ,
& V_148 [ V_59 ] ) ;
}
if ( ! V_88 -> V_111 )
F_104 ( & V_27 -> V_138 , & V_149 ) ;
F_104 ( & V_27 -> V_138 , & V_150 ) ;
}
static int T_6 F_106 ( struct V_151 * V_135 )
{
struct V_9 * V_10 ;
struct V_152 * V_153 ;
struct V_26 * V_27 = & V_135 -> V_27 ;
struct V_87 * V_88 = V_27 -> V_136 ;
const struct V_83 * V_137 ;
int V_60 = 0 , V_59 ;
int V_154 ;
int V_155 ;
static const char * const V_156 [] = {
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
} ;
V_153 = F_107 ( V_135 , V_157 , 0 ) ;
if ( ! F_108 ( & V_135 -> V_27 , V_153 -> V_158 , V_159 ,
V_7 ) ) {
F_65 ( V_27 , L_41 ,
( unsigned long ) V_153 -> V_158 ,
( unsigned long ) ( V_153 -> V_158 + V_159 - 1 ) ) ;
return - V_8 ;
}
V_10 = F_109 ( & V_135 -> V_27 , sizeof( struct V_9 ) , V_160 ) ;
if ( ! V_10 )
return - V_161 ;
V_10 -> V_162 = V_153 -> V_158 ;
V_10 -> type = V_88 -> type ;
V_10 -> V_19 = V_88 -> V_19 ;
V_10 -> V_82 = V_156 [ V_88 -> type ] ;
if ( ( F_51 ( V_10 , V_74 ) & 0x80 )
|| F_51 ( V_10 , V_163 ) != 0x90 )
return - V_92 ;
F_110 ( V_135 , V_10 ) ;
F_111 ( & V_10 -> V_39 ) ;
V_154 = F_112 ( V_27 ) ;
if ( F_11 ( V_10 ) ) {
if ( V_88 -> V_110 & ( 1 << 0 ) )
V_10 -> V_15 |= ( 1 << 3 ) ;
if ( V_88 -> V_110 & ( 1 << 1 ) )
V_10 -> V_15 |= ( 1 << 7 ) ;
if ( V_88 -> V_110 & ( 1 << 2 ) )
V_10 -> V_15 |= ( 1 << 8 ) ;
} else if ( V_88 -> type == V_24 || V_88 -> type == V_25 ) {
if ( V_88 -> V_110 & ( 1 << 0 ) )
V_10 -> V_15 |= ( 1 << 3 ) ;
if ( V_88 -> V_110 & ( 1 << 1 ) )
V_10 -> V_15 |= ( 1 << 7 ) ;
}
V_10 -> V_142 = 0x07 ;
if ( V_88 -> V_132 & ( 1 << 2 ) ) {
if ( V_88 -> type == V_24
&& ! ( F_51 ( V_10 , V_164 ) & 0x80 ) )
V_10 -> V_142 &= ~ ( 1 << 2 ) ;
}
F_113 ( V_135 ) ;
V_60 = F_114 ( & V_27 -> V_138 , & V_139 ) ;
if ( V_60 )
return V_60 ;
for ( V_59 = 0 ; V_59 < 9 ; V_59 ++ ) {
if ( V_88 -> V_127 & ( 1 << V_59 ) )
continue;
V_60 = F_114 ( & V_27 -> V_138 , & V_140 [ V_59 ] ) ;
if ( V_60 )
goto error;
if ( V_88 -> V_112 && V_141 [ V_59 ] ) {
V_60 = F_115 ( & V_27 -> V_138 ,
V_141 [ V_59 ] ) ;
if ( V_60 )
goto error;
}
}
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( ! ( V_10 -> V_142 & ( 1 << V_59 ) ) )
continue;
V_60 = F_114 ( & V_27 -> V_138 , & V_143 [ V_59 ] ) ;
if ( V_60 )
goto error;
if ( V_88 -> V_112 ) {
V_60 = F_115 ( & V_27 -> V_138 ,
V_144 [ V_59 ] ) ;
if ( V_60 )
goto error;
}
}
V_137 = F_96 ( V_10 ) ;
V_155 = 1 ;
for ( V_59 = 0 ; V_59 < 5 ; V_59 ++ ) {
if ( ! ( V_10 -> V_145 & ( 1 << V_59 ) ) )
continue;
V_60 = F_114 ( & V_27 -> V_138 , & V_137 [ V_59 ] ) ;
if ( V_60 )
goto error;
if ( V_88 -> V_112 ) {
V_60 = F_115 ( & V_27 -> V_138 ,
V_146 [ V_59 ] ) ;
if ( V_60 )
goto error;
if ( ! V_155 )
continue;
if ( F_116 ( & V_27 -> V_138 ,
V_146 [ V_59 ] ,
V_165 | V_166 ) )
F_117 ( V_27 , L_42 ,
V_59 + 1 ) ;
V_155 = 0 ;
}
}
if ( V_154 ) {
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( V_88 -> V_126 & ( 1 << V_59 ) )
continue;
V_60 = F_114 ( & V_27 -> V_138 ,
& V_147 [ V_59 ] ) ;
if ( V_60 )
goto error;
if ( ! F_24 ( V_10 ) )
continue;
V_60 = F_114 ( & V_27 -> V_138 ,
& V_148 [ V_59 ] ) ;
if ( V_60 )
goto error;
}
}
if ( ! V_88 -> V_111 ) {
V_10 -> V_77 = F_118 () ;
V_10 -> V_78 = V_88 -> V_130 ;
V_60 = F_114 ( & V_27 -> V_138 , & V_149 ) ;
if ( V_60 )
goto error;
}
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( ! ( V_88 -> V_110 & ( 1 << V_59 ) ) )
continue;
V_60 = F_115 ( & V_27 -> V_138 ,
V_167 [ V_59 ] ) ;
if ( V_60 )
goto error;
}
V_10 -> V_168 = F_119 ( V_27 ) ;
if ( F_120 ( V_10 -> V_168 ) ) {
V_60 = F_121 ( V_10 -> V_168 ) ;
goto error;
}
return 0 ;
error:
F_102 ( V_27 ) ;
return V_60 ;
}
static int T_7 F_122 ( struct V_151 * V_135 )
{
struct V_9 * V_10 = F_103 ( V_135 ) ;
F_123 ( V_10 -> V_168 ) ;
F_102 ( & V_135 -> V_27 ) ;
return 0 ;
}
static int F_51 ( struct V_9 * V_10 , T_1 V_1 )
{
F_124 ( V_1 , V_10 -> V_162 + V_169 ) ;
return F_125 ( V_10 -> V_162 + V_170 ) ;
}
static void F_34 ( struct V_9 * V_10 , T_1 V_1 , T_1 V_171 )
{
F_124 ( V_1 , V_10 -> V_162 + V_169 ) ;
F_124 ( V_171 , V_10 -> V_162 + V_170 ) ;
}
static int T_6 F_112 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
int V_63 = F_51 ( V_10 , V_64 ) ;
if ( ( V_63 & 0x87 ) == 0 ) {
if ( V_172 ) {
int V_59 ;
T_1 V_173 [ 3 ] ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ )
V_173 [ V_59 ] = F_51 ( V_10 ,
F_67 ( V_59 ) ) ;
if ( ! ( ( V_173 [ 0 ] | V_173 [ 1 ] | V_173 [ 2 ] ) & 0x80 ) ) {
F_126 ( V_27 , L_43
L_44 ) ;
F_34 ( V_10 , V_64 ,
V_63 | 0x87 ) ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ )
F_34 ( V_10 ,
F_67 ( V_59 ) ,
0x7f & ~ V_173 [ V_59 ] ) ;
return 1 ;
}
F_126 ( V_27 , L_45
L_46 ) ;
}
F_126 ( V_27 , L_47
L_48 ) ;
return 0 ;
} else if ( V_172 ) {
F_126 ( V_27 , L_49
L_50 ) ;
}
return 1 ;
}
static void T_6 F_113 ( struct V_151 * V_135 )
{
struct V_87 * V_88 = V_135 -> V_27 . V_136 ;
struct V_9 * V_10 = F_103 ( V_135 ) ;
int V_63 , V_59 ;
T_1 V_174 ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
V_10 -> V_66 [ V_59 ] = V_59 ;
V_10 -> V_52 [ V_59 ] = 0x7f ;
V_10 -> V_62 [ V_59 ] [ 3 ] = 0x7f ;
}
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
V_63 = F_51 ( V_10 , F_35 ( V_59 ) ) ;
if ( V_63 == 0xff )
F_34 ( V_10 , F_35 ( V_59 ) , 0 ) ;
}
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
V_63 = F_51 ( V_10 , F_46 ( V_59 ) ) ;
if ( V_63 == 0xff )
F_34 ( V_10 , F_46 ( V_59 ) , 127 ) ;
}
V_63 = F_51 ( V_10 , V_175 ) ;
if ( ( V_63 & 0xff ) == 0 ) {
F_34 ( V_10 , V_175 , 0xff ) ;
}
V_174 = 0x70 & ~ ( V_88 -> V_125 << 4 ) ;
V_10 -> V_47 = F_51 ( V_10 , V_65 ) ;
if ( ( V_10 -> V_47 & V_174 ) == 0 ) {
V_10 -> V_47 |= V_174 ;
F_34 ( V_10 , V_65 ,
V_10 -> V_47 ) ;
}
V_10 -> V_145 = ( V_10 -> V_47 >> 4 ) & 0x07 ;
if ( F_23 ( V_10 ) ) {
V_63 = F_51 ( V_10 , V_176 ) ;
if ( ~ V_63 & 0x07 & V_10 -> V_145 ) {
F_117 ( & V_135 -> V_27 ,
L_51 ) ;
F_34 ( V_10 , V_176 ,
V_63 | 0x07 ) ;
}
if ( V_10 -> type != V_18 && V_10 -> type != V_24 &&
V_10 -> type != V_25 ) {
if ( V_63 & ( 1 << 4 ) )
V_10 -> V_145 |= ( 1 << 3 ) ;
if ( V_63 & ( 1 << 5 ) )
V_10 -> V_145 |= ( 1 << 4 ) ;
}
}
V_10 -> V_145 &= ~ V_88 -> V_125 ;
F_34 ( V_10 , V_74 ,
( F_51 ( V_10 , V_74 ) & 0x3e )
| ( V_177 ? 0x41 : 0x01 ) ) ;
}
static void F_127 ( struct V_9 * V_10 , int V_13 )
{
V_10 -> V_48 [ V_13 ] = F_51 ( V_10 , F_67 ( V_13 ) ) ;
if ( F_12 ( V_10 ) ) {
V_10 -> V_66 [ V_13 ] = V_10 -> V_48 [ V_13 ] & 0x03 ;
V_10 -> V_52 [ V_13 ] = F_51 ( V_10 ,
F_69 ( V_13 ) ) ;
} else {
if ( V_10 -> V_48 [ V_13 ] & 0x80 )
V_10 -> V_66 [ V_13 ] = V_10 -> V_48 [ V_13 ] & 0x03 ;
else
V_10 -> V_52 [ V_13 ] = V_10 -> V_48 [ V_13 ] & 0x7f ;
}
if ( F_24 ( V_10 ) ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < 5 ; V_59 ++ )
V_10 -> V_61 [ V_13 ] [ V_59 ] = F_51 ( V_10 ,
F_80 ( V_13 , V_59 ) ) ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ )
V_10 -> V_62 [ V_13 ] [ V_59 ] = F_51 ( V_10 ,
F_77 ( V_13 , V_59 ) ) ;
}
}
static struct V_9 * F_27 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = F_31 ( V_27 ) ;
int V_59 ;
F_33 ( & V_10 -> V_39 ) ;
if ( F_128 ( V_178 , V_10 -> V_179 + V_180 + V_180 / 2 )
|| ! V_10 -> V_45 ) {
if ( V_177 ) {
F_34 ( V_10 , V_74 ,
F_51 ( V_10 , V_74 ) | 0x40 ) ;
}
for ( V_59 = 0 ; V_59 <= 7 ; V_59 ++ ) {
V_10 -> V_34 [ V_59 ] =
F_51 ( V_10 , F_129 ( V_59 ) ) ;
V_10 -> V_35 [ V_59 ] =
F_51 ( V_10 , F_35 ( V_59 ) ) ;
V_10 -> V_36 [ V_59 ] =
F_51 ( V_10 , F_38 ( V_59 ) ) ;
}
V_10 -> V_34 [ 8 ] = F_51 ( V_10 , F_129 ( 8 ) ) ;
for ( V_59 = 0 ; V_59 < 5 ; V_59 ++ ) {
if ( ! ( V_10 -> V_145 & ( 1 << V_59 ) ) )
continue;
V_10 -> V_51 [ V_59 ] =
F_51 ( V_10 , V_56 [ V_59 ] ) ;
V_10 -> V_49 [ V_59 ] = F_51 ( V_10 ,
V_181 [ V_59 ] ) ;
if ( F_23 ( V_10 ) ) {
V_10 -> V_49 [ V_59 ] |= F_51 ( V_10 ,
V_182 [ V_59 ] ) << 8 ;
V_10 -> V_51 [ V_59 ] |= F_51 ( V_10 ,
V_70 [ V_59 ] ) << 8 ;
}
}
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( ! ( V_10 -> V_142 & ( 1 << V_59 ) ) )
continue;
V_10 -> V_40 [ V_59 ] =
F_51 ( V_10 , F_130 ( V_59 ) ) ;
V_10 -> V_41 [ V_59 ] =
F_51 ( V_10 , F_46 ( V_59 ) ) ;
V_10 -> V_42 [ V_59 ] =
F_51 ( V_10 , F_48 ( V_59 ) ) ;
}
if ( ( V_10 -> V_145 & 0x07 ) && ! F_23 ( V_10 ) ) {
V_59 = F_51 ( V_10 , V_55 ) ;
V_10 -> V_50 [ 0 ] = V_59 & 0x07 ;
V_10 -> V_50 [ 1 ] = ( V_59 >> 3 ) & 0x07 ;
V_10 -> V_50 [ 2 ] = ( V_59 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_71 =
F_51 ( V_10 , V_183 ) |
( F_51 ( V_10 , V_184 ) << 8 ) |
( F_51 ( V_10 , V_185 ) << 16 ) ;
V_10 -> V_75 = F_51 ( V_10 , V_76 ) ;
V_10 -> V_47 = F_51 ( V_10 ,
V_65 ) ;
V_10 -> V_53 = F_51 ( V_10 , V_64 ) ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ )
F_127 ( V_10 , V_59 ) ;
V_10 -> V_43 = F_51 ( V_10 , V_44 ) ;
if ( V_10 -> type == V_20 || V_10 -> type == V_21 ) {
V_10 -> V_78 = F_51 ( V_10 , V_186 ) ;
V_10 -> V_78 &= 0x3f ;
}
V_10 -> V_179 = V_178 ;
V_10 -> V_45 = 1 ;
}
F_36 ( & V_10 -> V_39 ) ;
return V_10 ;
}
static int T_5 F_131 ( unsigned short V_86 ,
const struct V_87 * V_88 )
{
struct V_152 V_153 = {
. V_158 = V_86 + V_187 ,
. V_188 = V_86 + V_187 + V_159 - 1 ,
. V_82 = V_7 ,
. V_189 = V_157 ,
} ;
int V_60 ;
V_60 = F_132 ( & V_153 ) ;
if ( V_60 )
goto exit;
V_135 = F_133 ( V_7 , V_86 ) ;
if ( ! V_135 ) {
V_60 = - V_161 ;
F_134 ( L_52 ) ;
goto exit;
}
V_60 = F_135 ( V_135 , & V_153 , 1 ) ;
if ( V_60 ) {
F_134 ( L_53 , V_60 ) ;
goto V_190;
}
V_60 = F_136 ( V_135 , V_88 ,
sizeof( struct V_87 ) ) ;
if ( V_60 ) {
F_134 ( L_54 ) ;
goto V_190;
}
V_60 = F_137 ( V_135 ) ;
if ( V_60 ) {
F_134 ( L_55 , V_60 ) ;
goto V_190;
}
return 0 ;
V_190:
F_138 ( V_135 ) ;
exit:
return V_60 ;
}
static int T_5 F_139 ( void )
{
int V_60 ;
unsigned short V_191 = 0 ;
struct V_87 V_88 ;
memset ( & V_88 , 0 , sizeof( struct V_87 ) ) ;
V_60 = F_97 ( & V_191 , & V_88 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_140 ( & V_192 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_131 ( V_191 , & V_88 ) ;
if ( V_60 ) {
F_141 ( & V_192 ) ;
return V_60 ;
}
return 0 ;
}
static void T_8 F_142 ( void )
{
F_143 ( V_135 ) ;
F_141 ( & V_192 ) ;
}
