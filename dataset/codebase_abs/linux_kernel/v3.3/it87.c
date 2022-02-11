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
static T_1 F_13 ( const struct V_9 * V_10 , int V_13 , long V_4 )
{
long V_14 ;
if ( F_11 ( V_10 ) ) {
if ( V_10 -> V_15 & ( 1 << V_13 ) )
V_14 = 24 ;
else
V_14 = 12 ;
} else
V_14 = 16 ;
V_4 = F_14 ( V_4 , V_14 ) ;
return F_15 ( V_4 , 0 , 255 ) ;
}
static int F_16 ( const struct V_9 * V_10 , int V_13 , int V_4 )
{
if ( F_11 ( V_10 ) ) {
if ( V_10 -> V_15 & ( 1 << V_13 ) )
return V_4 * 24 ;
else
return V_4 * 12 ;
} else
return V_4 * 16 ;
}
static inline T_1 F_17 ( long V_16 , int div )
{
if ( V_16 == 0 )
return 255 ;
V_16 = F_15 ( V_16 , 1 , 1000000 ) ;
return F_15 ( ( 1350000 + V_16 * div / 2 ) / ( V_16 * div ) , 1 ,
254 ) ;
}
static inline T_2 F_18 ( long V_16 )
{
if ( V_16 == 0 )
return 0xffff ;
return F_15 ( ( 1350000 + V_16 ) / ( V_16 * 2 ) , 1 , 0xfffe ) ;
}
static T_1 F_19 ( const struct V_9 * V_10 , long V_4 )
{
if ( F_12 ( V_10 ) )
return V_4 ;
else
return V_4 >> 1 ;
}
static int F_20 ( const struct V_9 * V_10 , T_1 V_1 )
{
if ( F_12 ( V_10 ) )
return V_1 ;
else
return ( V_1 & 0x7f ) << 1 ;
}
static int F_21 ( int V_4 )
{
int V_17 = 0 ;
while ( V_17 < 7 && ( V_4 >>= 1 ) )
V_17 ++ ;
return V_17 ;
}
static inline int F_22 ( const struct V_9 * V_10 )
{
return ( V_10 -> type == V_18 && V_10 -> V_19 >= 0x03 )
|| ( V_10 -> type == V_20 && V_10 -> V_19 >= 0x08 )
|| V_10 -> type == V_21
|| V_10 -> type == V_22
|| V_10 -> type == V_23
|| V_10 -> type == V_11
|| V_10 -> type == V_12 ;
}
static inline int F_23 ( const struct V_9 * V_10 )
{
return ( V_10 -> type == V_18 && V_10 -> V_19 < 0x03 )
|| ( V_10 -> type == V_20 && V_10 -> V_19 < 0x08 ) ;
}
static T_3 F_24 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_16 ( V_10 , V_13 , V_10 -> V_32 [ V_13 ] ) ) ;
}
static T_3 F_27 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_16 ( V_10 , V_13 , V_10 -> V_33 [ V_13 ] ) ) ;
}
static T_3 F_28 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_16 ( V_10 , V_13 , V_10 -> V_34 [ V_13 ] ) ) ;
}
static T_3 F_29 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
unsigned long V_4 ;
if ( F_31 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_33 [ V_13 ] = F_13 ( V_10 , V_13 , V_4 ) ;
F_33 ( V_10 , F_34 ( V_13 ) ,
V_10 -> V_33 [ V_13 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_36 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
unsigned long V_4 ;
if ( F_31 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_34 [ V_13 ] = F_13 ( V_10 , V_13 , V_4 ) ;
F_33 ( V_10 , F_37 ( V_13 ) ,
V_10 -> V_34 [ V_13 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_38 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_39 ( V_10 -> V_38 [ V_13 ] ) ) ;
}
static T_3 F_40 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_39 ( V_10 -> V_39 [ V_13 ] ) ) ;
}
static T_3 F_41 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_39 ( V_10 -> V_40 [ V_13 ] ) ) ;
}
static T_3 F_42 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_39 [ V_13 ] = F_44 ( V_4 ) ;
F_33 ( V_10 , F_45 ( V_13 ) , V_10 -> V_39 [ V_13 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_46 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_40 [ V_13 ] = F_44 ( V_4 ) ;
F_33 ( V_10 , F_47 ( V_13 ) , V_10 -> V_40 [ V_13 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_48 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
T_1 V_1 = V_10 -> V_41 ;
if ( V_1 & ( 1 << V_13 ) )
return sprintf ( V_28 , L_2 ) ;
if ( V_1 & ( 8 << V_13 ) )
return sprintf ( V_28 , L_3 ) ;
return sprintf ( V_28 , L_4 ) ;
}
static T_3 F_49 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
V_1 = F_50 ( V_10 , V_42 ) ;
V_1 &= ~ ( 1 << V_13 ) ;
V_1 &= ~ ( 8 << V_13 ) ;
if ( V_4 == 2 ) {
F_51 ( V_25 , L_5
L_6 ) ;
V_4 = 4 ;
}
if ( V_4 == 3 )
V_1 |= 1 << V_13 ;
else if ( V_4 == 4 )
V_1 |= 8 << V_13 ;
else if ( V_4 != 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_41 = V_1 ;
F_33 ( V_10 , V_42 , V_10 -> V_41 ) ;
V_10 -> V_43 = 0 ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static int F_52 ( const struct V_9 * V_10 , int V_13 )
{
int V_44 = V_10 -> V_45 & ( 1 << V_13 ) ;
if ( V_44 == 0 )
return 0 ;
if ( V_10 -> V_46 [ V_13 ] & 0x80 )
return 2 ;
else
return 1 ;
}
static T_3 F_53 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_54 ( V_10 -> V_47 [ V_13 ] ,
F_55 ( V_10 -> V_48 [ V_13 ] ) ) ) ;
}
static T_3 F_56 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_54 ( V_10 -> V_49 [ V_13 ] ,
F_55 ( V_10 -> V_48 [ V_13 ] ) ) ) ;
}
static T_3 F_57 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_55 ( V_10 -> V_48 [ V_13 ] ) ) ;
}
static T_3 F_58 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_52 ( V_10 , V_13 ) ) ;
}
static T_3 F_59 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 ,
F_20 ( V_10 , V_10 -> V_50 [ V_13 ] ) ) ;
}
static T_3 F_60 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
int V_31 = ( V_10 -> V_51 >> 4 ) & 0x07 ;
return sprintf ( V_28 , L_7 , V_52 [ V_31 ] ) ;
}
static T_3 F_61 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_1 = F_50 ( V_10 , V_53 ) ;
switch ( V_13 ) {
case 0 :
V_10 -> V_48 [ V_13 ] = V_1 & 0x07 ;
break;
case 1 :
V_10 -> V_48 [ V_13 ] = ( V_1 >> 3 ) & 0x07 ;
break;
case 2 :
V_10 -> V_48 [ V_13 ] = ( V_1 & 0x40 ) ? 3 : 1 ;
break;
}
V_10 -> V_49 [ V_13 ] = F_17 ( V_4 , F_55 ( V_10 -> V_48 [ V_13 ] ) ) ;
F_33 ( V_10 , V_54 [ V_13 ] , V_10 -> V_49 [ V_13 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_62 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
unsigned long V_4 ;
int V_55 ;
T_1 V_56 ;
if ( F_31 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_56 = F_50 ( V_10 , V_53 ) ;
V_55 = F_54 ( V_10 -> V_49 [ V_13 ] , F_55 ( V_10 -> V_48 [ V_13 ] ) ) ;
switch ( V_13 ) {
case 0 :
case 1 :
V_10 -> V_48 [ V_13 ] = F_21 ( V_4 ) ;
break;
case 2 :
if ( V_4 < 8 )
V_10 -> V_48 [ V_13 ] = 1 ;
else
V_10 -> V_48 [ V_13 ] = 3 ;
}
V_4 = V_56 & 0x80 ;
V_4 |= ( V_10 -> V_48 [ 0 ] & 0x07 ) ;
V_4 |= ( V_10 -> V_48 [ 1 ] & 0x07 ) << 3 ;
if ( V_10 -> V_48 [ 2 ] == 3 )
V_4 |= 0x1 << 6 ;
F_33 ( V_10 , V_53 , V_4 ) ;
V_10 -> V_49 [ V_13 ] = F_17 ( V_55 , F_55 ( V_10 -> V_48 [ V_13 ] ) ) ;
F_33 ( V_10 , V_54 [ V_13 ] , V_10 -> V_49 [ V_13 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static int F_63 ( struct V_24 * V_25 , int V_13 )
{
const struct V_9 * V_10 = F_30 ( V_25 ) ;
int V_57 , V_58 = 0 ;
if ( F_23 ( V_10 ) ) {
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
if ( V_10 -> V_59 [ V_13 ] [ V_57 ] > V_10 -> V_59 [ V_13 ] [ V_57 + 1 ] )
V_58 = - V_36 ;
}
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
if ( V_10 -> V_60 [ V_13 ] [ V_57 ] > V_10 -> V_60 [ V_13 ] [ V_57 + 1 ] )
V_58 = - V_36 ;
}
}
if ( V_58 ) {
F_64 ( V_25 , L_8
L_9 ) ;
F_64 ( V_25 , L_10 ) ;
}
return V_58 ;
}
static T_3 F_65 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 2 )
return - V_36 ;
if ( V_4 == 2 ) {
if ( F_63 ( V_25 , V_13 ) < 0 )
return - V_36 ;
}
F_32 ( & V_10 -> V_37 ) ;
if ( V_4 == 0 ) {
int V_61 ;
V_61 = F_50 ( V_10 , V_62 ) ;
F_33 ( V_10 , V_62 , V_61 | ( 1 << V_13 ) ) ;
V_10 -> V_45 &= ~ ( 1 << V_13 ) ;
F_33 ( V_10 , V_63 ,
V_10 -> V_45 ) ;
} else {
if ( V_4 == 1 )
V_10 -> V_46 [ V_13 ] = F_12 ( V_10 ) ?
V_10 -> V_64 [ V_13 ] :
V_10 -> V_50 [ V_13 ] ;
else
V_10 -> V_46 [ V_13 ] = 0x80 | V_10 -> V_64 [ V_13 ] ;
F_33 ( V_10 , F_66 ( V_13 ) , V_10 -> V_46 [ V_13 ] ) ;
V_10 -> V_45 |= ( 1 << V_13 ) ;
F_33 ( V_10 , V_63 ,
V_10 -> V_45 ) ;
}
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_67 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
if ( F_12 ( V_10 ) ) {
if ( V_10 -> V_46 [ V_13 ] & 0x80 ) {
F_35 ( & V_10 -> V_37 ) ;
return - V_8 ;
}
V_10 -> V_50 [ V_13 ] = F_19 ( V_10 , V_4 ) ;
F_33 ( V_10 , F_68 ( V_13 ) ,
V_10 -> V_50 [ V_13 ] ) ;
} else {
V_10 -> V_50 [ V_13 ] = F_19 ( V_10 , V_4 ) ;
if ( ! ( V_10 -> V_46 [ V_13 ] & 0x80 ) ) {
V_10 -> V_46 [ V_13 ] = V_10 -> V_50 [ V_13 ] ;
F_33 ( V_10 , F_66 ( V_13 ) ,
V_10 -> V_46 [ V_13 ] ) ;
}
}
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_69 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_35 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
unsigned long V_4 ;
int V_57 ;
if ( F_31 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
for ( V_57 = 0 ; V_57 < 7 ; V_57 ++ ) {
if ( V_4 > ( V_52 [ V_57 ] + V_52 [ V_57 + 1 ] ) / 2 )
break;
}
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_51 = F_50 ( V_10 , V_62 ) & 0x8f ;
V_10 -> V_51 |= V_57 << 4 ;
F_33 ( V_10 , V_62 , V_10 -> V_51 ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_70 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
int V_65 ;
if ( V_10 -> V_64 [ V_13 ] < 3 )
V_65 = 1 << V_10 -> V_64 [ V_13 ] ;
else
V_65 = 0 ;
return sprintf ( V_28 , L_1 , V_65 ) ;
}
static T_3 F_71 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
T_1 V_1 ;
if ( ! F_23 ( V_10 ) ) {
F_72 ( V_25 , L_11 ) ;
return - V_36 ;
}
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
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
return - V_36 ;
}
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_64 [ V_13 ] = V_1 ;
if ( V_10 -> V_46 [ V_13 ] & 0x80 ) {
V_10 -> V_46 [ V_13 ] = 0x80 | V_10 -> V_64 [ V_13 ] ;
F_33 ( V_10 , F_66 ( V_13 ) , V_10 -> V_46 [ V_13 ] ) ;
}
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_73 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
struct V_66 * V_30 =
F_74 ( V_27 ) ;
int V_13 = V_30 -> V_13 ;
int V_67 = V_30 -> V_31 ;
return sprintf ( V_28 , L_1 ,
F_20 ( V_10 , V_10 -> V_60 [ V_13 ] [ V_67 ] ) ) ;
}
static T_3 F_75 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_35 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
struct V_66 * V_30 =
F_74 ( V_27 ) ;
int V_13 = V_30 -> V_13 ;
int V_67 = V_30 -> V_31 ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_60 [ V_13 ] [ V_67 ] = F_19 ( V_10 , V_4 ) ;
F_33 ( V_10 , F_76 ( V_13 , V_67 ) ,
V_10 -> V_60 [ V_13 ] [ V_67 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_77 ( struct V_24 * V_25 ,
struct V_26 * V_27 , char * V_28 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
struct V_66 * V_30 =
F_74 ( V_27 ) ;
int V_13 = V_30 -> V_13 ;
int V_67 = V_30 -> V_31 ;
return sprintf ( V_28 , L_1 , F_39 ( V_10 -> V_59 [ V_13 ] [ V_67 ] ) ) ;
}
static T_3 F_78 ( struct V_24 * V_25 ,
struct V_26 * V_27 , const char * V_28 , T_4 V_35 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
struct V_66 * V_30 =
F_74 ( V_27 ) ;
int V_13 = V_30 -> V_13 ;
int V_67 = V_30 -> V_31 ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 || V_4 < - 128000 || V_4 > 127000 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_59 [ V_13 ] [ V_67 ] = F_44 ( V_4 ) ;
F_33 ( V_10 , F_79 ( V_13 , V_67 ) ,
V_10 -> V_59 [ V_13 ] [ V_67 ] ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_80 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_81 ( V_10 -> V_47 [ V_13 ] ) ) ;
}
static T_3 F_82 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_1 , F_81 ( V_10 -> V_49 [ V_13 ] ) ) ;
}
static T_3 F_83 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_29 * V_30 = F_25 ( V_27 ) ;
int V_13 = V_30 -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_49 [ V_13 ] = F_18 ( V_4 ) ;
F_33 ( V_10 , V_54 [ V_13 ] ,
V_10 -> V_49 [ V_13 ] & 0xff ) ;
F_33 ( V_10 , V_68 [ V_13 ] ,
V_10 -> V_49 [ V_13 ] >> 8 ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_84 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_7 , V_10 -> V_69 ) ;
}
static T_3 F_85 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
int V_70 = F_25 ( V_27 ) -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_7 , ( V_10 -> V_69 >> V_70 ) & 1 ) ;
}
static T_3 F_86 ( struct V_24 * V_25 , struct V_26
* V_27 , const char * V_28 , T_4 V_35 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
int V_71 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0 || V_4 != 0 )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_71 = F_50 ( V_10 , V_72 ) ;
if ( V_71 < 0 ) {
V_35 = V_71 ;
} else {
V_71 |= 1 << 5 ;
F_33 ( V_10 , V_72 , V_71 ) ;
V_10 -> V_43 = 0 ;
}
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_87 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
int V_70 = F_25 ( V_27 ) -> V_31 ;
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_7 , ( V_10 -> V_73 >> V_70 ) & 1 ) ;
}
static T_3 F_88 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
int V_70 = F_25 ( V_27 ) -> V_31 ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
long V_4 ;
if ( F_43 ( V_28 , 10 , & V_4 ) < 0
|| ( V_4 != 0 && V_4 != 1 ) )
return - V_36 ;
F_32 ( & V_10 -> V_37 ) ;
V_10 -> V_73 = F_50 ( V_10 , V_74 ) ;
if ( V_4 )
V_10 -> V_73 |= ( 1 << V_70 ) ;
else
V_10 -> V_73 &= ~ ( 1 << V_70 ) ;
F_33 ( V_10 , V_74 , V_10 -> V_73 ) ;
F_35 ( & V_10 -> V_37 ) ;
return V_35 ;
}
static T_3 F_89 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
return sprintf ( V_28 , L_7 , V_10 -> V_75 ) ;
}
static T_3 F_90 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_4 V_35 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
unsigned long V_4 ;
if ( F_31 ( V_28 , 10 , & V_4 ) < 0 )
return - V_36 ;
V_10 -> V_75 = V_4 ;
return V_35 ;
}
static T_3 F_91 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_9 * V_10 = F_26 ( V_25 ) ;
return sprintf ( V_28 , L_12 , ( long ) F_92 ( V_10 -> V_76 , V_10 -> V_75 ) ) ;
}
static T_3 F_93 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
static const char * V_77 [] = {
L_13 ,
L_14 ,
L_15 ,
} ;
static const char * V_78 [] = {
L_16 ,
L_17 ,
L_15 ,
} ;
struct V_9 * V_10 = F_30 ( V_25 ) ;
int V_13 = F_25 ( V_27 ) -> V_31 ;
return sprintf ( V_28 , L_18 , F_11 ( V_10 ) ? V_78 [ V_13 ]
: V_77 [ V_13 ] ) ;
}
static T_3 F_94 ( struct V_24 * V_25 , struct V_26
* V_79 , char * V_28 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
return sprintf ( V_28 , L_18 , V_10 -> V_80 ) ;
}
static const struct V_81 *
F_95 ( const struct V_9 * V_10 )
{
return F_22 ( V_10 ) ? V_82 : V_83 ;
}
static int T_5 F_96 ( unsigned short * V_84 ,
struct V_85 * V_86 )
{
int V_58 ;
T_2 V_87 ;
const char * V_88 , * V_89 ;
V_58 = F_7 () ;
if ( V_58 )
return V_58 ;
V_58 = - V_90 ;
V_87 = V_91 ? V_91 : F_5 ( V_92 ) ;
switch ( V_87 ) {
case V_93 :
V_86 -> type = V_18 ;
break;
case V_94 :
V_86 -> type = V_20 ;
break;
case V_95 :
case V_96 :
V_86 -> type = V_21 ;
break;
case V_97 :
V_86 -> type = V_22 ;
break;
case V_98 :
V_86 -> type = V_23 ;
break;
case V_99 :
V_86 -> type = V_11 ;
break;
case V_100 :
V_86 -> type = V_12 ;
break;
case 0xffff :
goto exit;
default:
F_97 ( L_19 , V_87 ) ;
goto exit;
}
F_6 ( V_101 ) ;
if ( ! ( F_1 ( V_102 ) & 0x01 ) ) {
F_98 ( L_20 ) ;
goto exit;
}
* V_84 = F_5 ( V_103 ) & ~ ( V_104 - 1 ) ;
if ( * V_84 == 0 ) {
F_98 ( L_21 ) ;
goto exit;
}
V_58 = 0 ;
V_86 -> V_19 = F_1 ( V_105 ) & 0x0f ;
F_98 ( L_22 ,
V_87 , * V_84 , V_86 -> V_19 ) ;
V_86 -> V_106 = ( 1 << 2 ) ;
if ( V_86 -> type == V_18 ) {
V_86 -> V_107 = 1 ;
F_6 ( 5 ) ;
V_86 -> V_108 = F_1 ( V_109 ) & 0x3f ;
} else {
int V_1 ;
F_6 ( V_110 ) ;
V_1 = F_1 ( V_111 ) ;
if ( V_86 -> type == V_11 || V_86 -> type == V_12 ) {
V_86 -> V_107 = 1 ;
} else {
if ( V_1 & 0x0f ) {
F_98 ( L_23 ) ;
V_86 -> V_107 = 1 ;
}
}
if ( V_1 & ( 1 << 6 ) )
V_86 -> V_112 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_86 -> V_113 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_114 ) ;
if ( V_1 & ( 1 << 1 ) )
V_86 -> V_112 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_86 -> V_113 |= ( 1 << 1 ) ;
if ( ( V_86 -> type == V_22 || V_86 -> type == V_23 )
&& ! ( V_86 -> V_107 ) )
V_86 -> V_115 = F_1 ( V_116 ) ;
V_1 = F_1 ( V_117 ) ;
if ( V_86 -> type == V_23 && ! ( V_1 & ( 1 << 1 ) ) ) {
V_1 |= ( 1 << 1 ) ;
F_4 ( V_117 , V_1 ) ;
F_99 ( L_24 ) ;
}
if ( V_1 & ( 1 << 0 ) )
V_86 -> V_106 |= ( 1 << 0 ) ;
if ( ( V_1 & ( 1 << 1 ) ) || V_86 -> type == V_11 ||
V_86 -> type == V_12 )
V_86 -> V_106 |= ( 1 << 1 ) ;
V_86 -> V_108 = F_1 ( V_109 ) & 0x3f ;
}
if ( V_86 -> V_108 )
F_98 ( L_25 ) ;
V_88 = F_100 ( V_118 ) ;
V_89 = F_100 ( V_119 ) ;
if ( V_88 && V_89 ) {
if ( strcmp ( V_88 , L_26 ) == 0
&& strcmp ( V_89 , L_27 ) == 0 ) {
F_98 ( L_28 ) ;
V_86 -> V_112 = ( 1 << 1 ) ;
}
}
exit:
F_9 () ;
return V_58 ;
}
static void F_101 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_102 ( V_120 ) ;
struct V_85 * V_86 = V_25 -> V_121 ;
const struct V_81 * V_122 = F_95 ( V_10 ) ;
int V_57 ;
F_103 ( & V_25 -> V_123 , & V_124 ) ;
if ( V_86 -> V_108 )
F_103 ( & V_25 -> V_123 , & V_125 ) ;
for ( V_57 = 0 ; V_57 < 5 ; V_57 ++ ) {
if ( ! ( V_10 -> V_126 & ( 1 << V_57 ) ) )
continue;
F_103 ( & V_25 -> V_123 , & V_122 [ V_57 ] ) ;
if ( V_86 -> V_108 )
F_104 ( & V_25 -> V_123 ,
V_127 [ V_57 ] ) ;
}
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
if ( V_86 -> V_112 & ( 1 << 0 ) )
continue;
F_103 ( & V_25 -> V_123 , & V_128 [ V_57 ] ) ;
if ( F_23 ( V_10 ) )
F_103 ( & V_25 -> V_123 ,
& V_129 [ V_57 ] ) ;
}
if ( ! V_86 -> V_107 )
F_103 ( & V_25 -> V_123 , & V_130 ) ;
F_103 ( & V_25 -> V_123 , & V_131 ) ;
}
static int T_6 F_105 ( struct V_132 * V_120 )
{
struct V_9 * V_10 ;
struct V_133 * V_134 ;
struct V_24 * V_25 = & V_120 -> V_25 ;
struct V_85 * V_86 = V_25 -> V_121 ;
const struct V_81 * V_122 ;
int V_58 = 0 , V_57 ;
int V_135 ;
int V_136 ;
static const char * V_137 [] = {
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
} ;
V_134 = F_106 ( V_120 , V_138 , 0 ) ;
if ( ! F_107 ( V_134 -> V_139 , V_140 , V_7 ) ) {
F_64 ( V_25 , L_36 ,
( unsigned long ) V_134 -> V_139 ,
( unsigned long ) ( V_134 -> V_139 + V_140 - 1 ) ) ;
V_58 = - V_8 ;
goto V_141;
}
V_10 = F_108 ( sizeof( struct V_9 ) , V_142 ) ;
if ( ! V_10 ) {
V_58 = - V_143 ;
goto V_144;
}
V_10 -> V_145 = V_134 -> V_139 ;
V_10 -> type = V_86 -> type ;
V_10 -> V_19 = V_86 -> V_19 ;
V_10 -> V_80 = V_137 [ V_86 -> type ] ;
if ( ( F_50 ( V_10 , V_72 ) & 0x80 )
|| F_50 ( V_10 , V_146 ) != 0x90 ) {
V_58 = - V_90 ;
goto V_147;
}
F_109 ( V_120 , V_10 ) ;
F_110 ( & V_10 -> V_37 ) ;
V_135 = F_111 ( V_25 ) ;
if ( F_11 ( V_10 ) ) {
if ( V_86 -> V_106 & ( 1 << 0 ) )
V_10 -> V_15 |= ( 1 << 3 ) ;
if ( V_86 -> V_106 & ( 1 << 1 ) )
V_10 -> V_15 |= ( 1 << 7 ) ;
if ( V_86 -> V_106 & ( 1 << 2 ) )
V_10 -> V_15 |= ( 1 << 8 ) ;
}
F_112 ( V_120 ) ;
V_58 = F_113 ( & V_25 -> V_123 , & V_124 ) ;
if ( V_58 )
goto V_147;
if ( V_86 -> V_108 ) {
V_58 = F_113 ( & V_25 -> V_123 , & V_125 ) ;
if ( V_58 )
goto V_148;
}
V_122 = F_95 ( V_10 ) ;
V_136 = 1 ;
for ( V_57 = 0 ; V_57 < 5 ; V_57 ++ ) {
if ( ! ( V_10 -> V_126 & ( 1 << V_57 ) ) )
continue;
V_58 = F_113 ( & V_25 -> V_123 , & V_122 [ V_57 ] ) ;
if ( V_58 )
goto V_148;
if ( V_86 -> V_108 ) {
V_58 = F_114 ( & V_25 -> V_123 ,
V_127 [ V_57 ] ) ;
if ( V_58 )
goto V_148;
if ( ! V_136 )
continue;
if ( F_115 ( & V_25 -> V_123 ,
V_127 [ V_57 ] ,
V_149 | V_150 ) )
F_116 ( V_25 , L_37 ,
V_57 + 1 ) ;
V_136 = 0 ;
}
}
if ( V_135 ) {
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
if ( V_86 -> V_112 & ( 1 << V_57 ) )
continue;
V_58 = F_113 ( & V_25 -> V_123 ,
& V_128 [ V_57 ] ) ;
if ( V_58 )
goto V_148;
if ( ! F_23 ( V_10 ) )
continue;
V_58 = F_113 ( & V_25 -> V_123 ,
& V_129 [ V_57 ] ) ;
if ( V_58 )
goto V_148;
}
}
if ( ! V_86 -> V_107 ) {
V_10 -> V_75 = F_117 () ;
V_10 -> V_76 = V_86 -> V_115 ;
V_58 = F_113 ( & V_25 -> V_123 , & V_130 ) ;
if ( V_58 )
goto V_148;
}
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
if ( ! ( V_86 -> V_106 & ( 1 << V_57 ) ) )
continue;
V_58 = F_114 ( & V_25 -> V_123 ,
V_151 [ V_57 ] ) ;
if ( V_58 )
goto V_148;
}
V_10 -> V_152 = F_118 ( V_25 ) ;
if ( F_119 ( V_10 -> V_152 ) ) {
V_58 = F_120 ( V_10 -> V_152 ) ;
goto V_148;
}
return 0 ;
V_148:
F_101 ( V_25 ) ;
V_147:
F_109 ( V_120 , NULL ) ;
F_121 ( V_10 ) ;
V_144:
F_10 ( V_134 -> V_139 , V_140 ) ;
V_141:
return V_58 ;
}
static int T_7 F_122 ( struct V_132 * V_120 )
{
struct V_9 * V_10 = F_102 ( V_120 ) ;
F_123 ( V_10 -> V_152 ) ;
F_101 ( & V_120 -> V_25 ) ;
F_10 ( V_10 -> V_145 , V_140 ) ;
F_109 ( V_120 , NULL ) ;
F_121 ( V_10 ) ;
return 0 ;
}
static int F_50 ( struct V_9 * V_10 , T_1 V_1 )
{
F_124 ( V_1 , V_10 -> V_145 + V_153 ) ;
return F_125 ( V_10 -> V_145 + V_154 ) ;
}
static void F_33 ( struct V_9 * V_10 , T_1 V_1 , T_1 V_155 )
{
F_124 ( V_1 , V_10 -> V_145 + V_153 ) ;
F_124 ( V_155 , V_10 -> V_145 + V_154 ) ;
}
static int T_6 F_111 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
int V_61 = F_50 ( V_10 , V_62 ) ;
if ( ( V_61 & 0x87 ) == 0 ) {
if ( V_156 ) {
int V_57 ;
T_1 V_157 [ 3 ] ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ )
V_157 [ V_57 ] = F_50 ( V_10 ,
F_66 ( V_57 ) ) ;
if ( ! ( ( V_157 [ 0 ] | V_157 [ 1 ] | V_157 [ 2 ] ) & 0x80 ) ) {
F_126 ( V_25 , L_38
L_39 ) ;
F_33 ( V_10 , V_62 ,
V_61 | 0x87 ) ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ )
F_33 ( V_10 ,
F_66 ( V_57 ) ,
0x7f & ~ V_157 [ V_57 ] ) ;
return 1 ;
}
F_126 ( V_25 , L_40
L_41 ) ;
}
F_126 ( V_25 , L_42
L_43 ) ;
return 0 ;
} else if ( V_156 ) {
F_126 ( V_25 , L_44
L_45 ) ;
}
return 1 ;
}
static void T_6 F_112 ( struct V_132 * V_120 )
{
struct V_85 * V_86 = V_120 -> V_25 . V_121 ;
struct V_9 * V_10 = F_102 ( V_120 ) ;
int V_61 , V_57 ;
T_1 V_158 ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
V_10 -> V_64 [ V_57 ] = V_57 ;
V_10 -> V_50 [ V_57 ] = 0x7f ;
V_10 -> V_60 [ V_57 ] [ 3 ] = 0x7f ;
}
for ( V_57 = 0 ; V_57 < 8 ; V_57 ++ ) {
V_61 = F_50 ( V_10 , F_34 ( V_57 ) ) ;
if ( V_61 == 0xff )
F_33 ( V_10 , F_34 ( V_57 ) , 0 ) ;
}
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
V_61 = F_50 ( V_10 , F_45 ( V_57 ) ) ;
if ( V_61 == 0xff )
F_33 ( V_10 , F_45 ( V_57 ) , 127 ) ;
}
V_61 = F_50 ( V_10 , V_159 ) ;
if ( ( V_61 & 0xff ) == 0 ) {
F_33 ( V_10 , V_159 , 0xff ) ;
}
V_158 = 0x70 & ~ ( V_86 -> V_113 << 4 ) ;
V_10 -> V_45 = F_50 ( V_10 , V_63 ) ;
if ( ( V_10 -> V_45 & V_158 ) == 0 ) {
V_10 -> V_45 |= V_158 ;
F_33 ( V_10 , V_63 ,
V_10 -> V_45 ) ;
}
V_10 -> V_126 = ( V_10 -> V_45 >> 4 ) & 0x07 ;
if ( F_22 ( V_10 ) ) {
V_61 = F_50 ( V_10 , V_160 ) ;
if ( ~ V_61 & 0x07 & V_10 -> V_126 ) {
F_116 ( & V_120 -> V_25 ,
L_46 ) ;
F_33 ( V_10 , V_160 ,
V_61 | 0x07 ) ;
}
if ( V_10 -> type != V_18 ) {
if ( V_61 & ( 1 << 4 ) )
V_10 -> V_126 |= ( 1 << 3 ) ;
if ( V_61 & ( 1 << 5 ) )
V_10 -> V_126 |= ( 1 << 4 ) ;
}
}
V_10 -> V_126 &= ~ V_86 -> V_113 ;
F_33 ( V_10 , V_72 ,
( F_50 ( V_10 , V_72 ) & 0x36 )
| ( V_161 ? 0x41 : 0x01 ) ) ;
}
static void F_127 ( struct V_9 * V_10 , int V_13 )
{
V_10 -> V_46 [ V_13 ] = F_50 ( V_10 , F_66 ( V_13 ) ) ;
if ( F_12 ( V_10 ) ) {
V_10 -> V_64 [ V_13 ] = V_10 -> V_46 [ V_13 ] & 0x03 ;
V_10 -> V_50 [ V_13 ] = F_50 ( V_10 ,
F_68 ( V_13 ) ) ;
} else {
if ( V_10 -> V_46 [ V_13 ] & 0x80 )
V_10 -> V_64 [ V_13 ] = V_10 -> V_46 [ V_13 ] & 0x03 ;
else
V_10 -> V_50 [ V_13 ] = V_10 -> V_46 [ V_13 ] & 0x7f ;
}
if ( F_23 ( V_10 ) ) {
int V_57 ;
for ( V_57 = 0 ; V_57 < 5 ; V_57 ++ )
V_10 -> V_59 [ V_13 ] [ V_57 ] = F_50 ( V_10 ,
F_79 ( V_13 , V_57 ) ) ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ )
V_10 -> V_60 [ V_13 ] [ V_57 ] = F_50 ( V_10 ,
F_76 ( V_13 , V_57 ) ) ;
}
}
static struct V_9 * F_26 ( struct V_24 * V_25 )
{
struct V_9 * V_10 = F_30 ( V_25 ) ;
int V_57 ;
F_32 ( & V_10 -> V_37 ) ;
if ( F_128 ( V_162 , V_10 -> V_163 + V_164 + V_164 / 2 )
|| ! V_10 -> V_43 ) {
if ( V_161 ) {
F_33 ( V_10 , V_72 ,
F_50 ( V_10 , V_72 ) | 0x40 ) ;
}
for ( V_57 = 0 ; V_57 <= 7 ; V_57 ++ ) {
V_10 -> V_32 [ V_57 ] =
F_50 ( V_10 , F_129 ( V_57 ) ) ;
V_10 -> V_33 [ V_57 ] =
F_50 ( V_10 , F_34 ( V_57 ) ) ;
V_10 -> V_34 [ V_57 ] =
F_50 ( V_10 , F_37 ( V_57 ) ) ;
}
V_10 -> V_32 [ 8 ] = F_50 ( V_10 , F_129 ( 8 ) ) ;
for ( V_57 = 0 ; V_57 < 5 ; V_57 ++ ) {
if ( ! ( V_10 -> V_126 & ( 1 << V_57 ) ) )
continue;
V_10 -> V_49 [ V_57 ] =
F_50 ( V_10 , V_54 [ V_57 ] ) ;
V_10 -> V_47 [ V_57 ] = F_50 ( V_10 ,
V_165 [ V_57 ] ) ;
if ( F_22 ( V_10 ) ) {
V_10 -> V_47 [ V_57 ] |= F_50 ( V_10 ,
V_166 [ V_57 ] ) << 8 ;
V_10 -> V_49 [ V_57 ] |= F_50 ( V_10 ,
V_68 [ V_57 ] ) << 8 ;
}
}
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
V_10 -> V_38 [ V_57 ] =
F_50 ( V_10 , F_130 ( V_57 ) ) ;
V_10 -> V_39 [ V_57 ] =
F_50 ( V_10 , F_45 ( V_57 ) ) ;
V_10 -> V_40 [ V_57 ] =
F_50 ( V_10 , F_47 ( V_57 ) ) ;
}
if ( ( V_10 -> V_126 & 0x07 ) && ! F_22 ( V_10 ) ) {
V_57 = F_50 ( V_10 , V_53 ) ;
V_10 -> V_48 [ 0 ] = V_57 & 0x07 ;
V_10 -> V_48 [ 1 ] = ( V_57 >> 3 ) & 0x07 ;
V_10 -> V_48 [ 2 ] = ( V_57 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_69 =
F_50 ( V_10 , V_167 ) |
( F_50 ( V_10 , V_168 ) << 8 ) |
( F_50 ( V_10 , V_169 ) << 16 ) ;
V_10 -> V_73 = F_50 ( V_10 , V_74 ) ;
V_10 -> V_45 = F_50 ( V_10 ,
V_63 ) ;
V_10 -> V_51 = F_50 ( V_10 , V_62 ) ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ )
F_127 ( V_10 , V_57 ) ;
V_10 -> V_41 = F_50 ( V_10 , V_42 ) ;
if ( V_10 -> type == V_20 || V_10 -> type == V_21 ) {
V_10 -> V_76 = F_50 ( V_10 , V_170 ) ;
V_10 -> V_76 &= 0x3f ;
}
V_10 -> V_163 = V_162 ;
V_10 -> V_43 = 1 ;
}
F_35 ( & V_10 -> V_37 ) ;
return V_10 ;
}
static int T_5 F_131 ( unsigned short V_84 ,
const struct V_85 * V_86 )
{
struct V_133 V_134 = {
. V_139 = V_84 + V_171 ,
. V_172 = V_84 + V_171 + V_140 - 1 ,
. V_80 = V_7 ,
. V_173 = V_138 ,
} ;
int V_58 ;
V_58 = F_132 ( & V_134 ) ;
if ( V_58 )
goto exit;
V_120 = F_133 ( V_7 , V_84 ) ;
if ( ! V_120 ) {
V_58 = - V_143 ;
F_134 ( L_47 ) ;
goto exit;
}
V_58 = F_135 ( V_120 , & V_134 , 1 ) ;
if ( V_58 ) {
F_134 ( L_48 , V_58 ) ;
goto V_174;
}
V_58 = F_136 ( V_120 , V_86 ,
sizeof( struct V_85 ) ) ;
if ( V_58 ) {
F_134 ( L_49 ) ;
goto V_174;
}
V_58 = F_137 ( V_120 ) ;
if ( V_58 ) {
F_134 ( L_50 , V_58 ) ;
goto V_174;
}
return 0 ;
V_174:
F_138 ( V_120 ) ;
exit:
return V_58 ;
}
static int T_5 F_139 ( void )
{
int V_58 ;
unsigned short V_175 = 0 ;
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_58 = F_96 ( & V_175 , & V_86 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_140 ( & V_176 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_131 ( V_175 , & V_86 ) ;
if ( V_58 ) {
F_141 ( & V_176 ) ;
return V_58 ;
}
return 0 ;
}
static void T_8 F_142 ( void )
{
F_143 ( V_120 ) ;
F_141 ( & V_176 ) ;
}
