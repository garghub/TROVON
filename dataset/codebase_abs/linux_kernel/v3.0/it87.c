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
static T_1 F_11 ( const struct V_9 * V_10 , int V_11 , long V_4 )
{
long V_12 ;
if ( V_10 -> type == V_13 ) {
if ( V_10 -> V_14 & ( 1 << V_11 ) )
V_12 = 24 ;
else
V_12 = 12 ;
} else
V_12 = 16 ;
V_4 = F_12 ( V_4 , V_12 ) ;
return F_13 ( V_4 , 0 , 255 ) ;
}
static int F_14 ( const struct V_9 * V_10 , int V_11 , int V_4 )
{
if ( V_10 -> type == V_13 ) {
if ( V_10 -> V_14 & ( 1 << V_11 ) )
return V_4 * 24 ;
else
return V_4 * 12 ;
} else
return V_4 * 16 ;
}
static inline T_1 F_15 ( long V_15 , int div )
{
if ( V_15 == 0 )
return 255 ;
V_15 = F_13 ( V_15 , 1 , 1000000 ) ;
return F_13 ( ( 1350000 + V_15 * div / 2 ) / ( V_15 * div ) , 1 ,
254 ) ;
}
static inline T_2 F_16 ( long V_15 )
{
if ( V_15 == 0 )
return 0xffff ;
return F_13 ( ( 1350000 + V_15 ) / ( V_15 * 2 ) , 1 , 0xfffe ) ;
}
static T_1 F_17 ( const struct V_9 * V_10 , long V_4 )
{
if ( V_10 -> type == V_13 )
return V_4 ;
else
return V_4 >> 1 ;
}
static int F_18 ( const struct V_9 * V_10 , T_1 V_1 )
{
if ( V_10 -> type == V_13 )
return V_1 ;
else
return ( V_1 & 0x7f ) << 1 ;
}
static int F_19 ( int V_4 )
{
int V_16 = 0 ;
while ( V_16 < 7 && ( V_4 >>= 1 ) )
V_16 ++ ;
return V_16 ;
}
static inline int F_20 ( const struct V_9 * V_10 )
{
return ( V_10 -> type == V_17 && V_10 -> V_18 >= 0x03 )
|| ( V_10 -> type == V_19 && V_10 -> V_18 >= 0x08 )
|| V_10 -> type == V_20
|| V_10 -> type == V_21
|| V_10 -> type == V_22
|| V_10 -> type == V_13 ;
}
static inline int F_21 ( const struct V_9 * V_10 )
{
return ( V_10 -> type == V_17 && V_10 -> V_18 < 0x03 )
|| ( V_10 -> type == V_19 && V_10 -> V_18 < 0x08 ) ;
}
static T_3 F_22 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_14 ( V_10 , V_11 , V_10 -> V_31 [ V_11 ] ) ) ;
}
static T_3 F_25 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_14 ( V_10 , V_11 , V_10 -> V_32 [ V_11 ] ) ) ;
}
static T_3 F_26 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_14 ( V_10 , V_11 , V_10 -> V_33 [ V_11 ] ) ) ;
}
static T_3 F_27 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
unsigned long V_4 ;
if ( F_29 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_32 [ V_11 ] = F_11 ( V_10 , V_11 , V_4 ) ;
F_31 ( V_10 , F_32 ( V_11 ) ,
V_10 -> V_32 [ V_11 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_34 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
unsigned long V_4 ;
if ( F_29 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_33 [ V_11 ] = F_11 ( V_10 , V_11 , V_4 ) ;
F_31 ( V_10 , F_35 ( V_11 ) ,
V_10 -> V_33 [ V_11 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_36 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_37 ( V_10 -> V_37 [ V_11 ] ) ) ;
}
static T_3 F_38 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_37 ( V_10 -> V_38 [ V_11 ] ) ) ;
}
static T_3 F_39 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_37 ( V_10 -> V_39 [ V_11 ] ) ) ;
}
static T_3 F_40 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_38 [ V_11 ] = F_42 ( V_4 ) ;
F_31 ( V_10 , F_43 ( V_11 ) , V_10 -> V_38 [ V_11 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_44 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_39 [ V_11 ] = F_42 ( V_4 ) ;
F_31 ( V_10 , F_45 ( V_11 ) , V_10 -> V_39 [ V_11 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_46 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
T_1 V_1 = V_10 -> V_40 ;
if ( V_1 & ( 1 << V_11 ) )
return sprintf ( V_27 , L_2 ) ;
if ( V_1 & ( 8 << V_11 ) )
return sprintf ( V_27 , L_3 ) ;
return sprintf ( V_27 , L_4 ) ;
}
static T_3 F_47 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
V_1 = F_48 ( V_10 , V_41 ) ;
V_1 &= ~ ( 1 << V_11 ) ;
V_1 &= ~ ( 8 << V_11 ) ;
if ( V_4 == 2 ) {
F_49 ( V_24 , L_5
L_6 ) ;
V_4 = 4 ;
}
if ( V_4 == 3 )
V_1 |= 1 << V_11 ;
else if ( V_4 == 4 )
V_1 |= 8 << V_11 ;
else if ( V_4 != 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_40 = V_1 ;
F_31 ( V_10 , V_41 , V_10 -> V_40 ) ;
V_10 -> V_42 = 0 ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static int F_50 ( const struct V_9 * V_10 , int V_11 )
{
int V_43 = V_10 -> V_44 & ( 1 << V_11 ) ;
if ( V_43 == 0 )
return 0 ;
if ( V_10 -> V_45 [ V_11 ] & 0x80 )
return 2 ;
else
return 1 ;
}
static T_3 F_51 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_52 ( V_10 -> V_46 [ V_11 ] ,
F_53 ( V_10 -> V_47 [ V_11 ] ) ) ) ;
}
static T_3 F_54 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_52 ( V_10 -> V_48 [ V_11 ] ,
F_53 ( V_10 -> V_47 [ V_11 ] ) ) ) ;
}
static T_3 F_55 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_53 ( V_10 -> V_47 [ V_11 ] ) ) ;
}
static T_3 F_56 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_50 ( V_10 , V_11 ) ) ;
}
static T_3 F_57 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 ,
F_18 ( V_10 , V_10 -> V_49 [ V_11 ] ) ) ;
}
static T_3 F_58 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_9 * V_10 = F_24 ( V_24 ) ;
int V_30 = ( V_10 -> V_50 >> 4 ) & 0x07 ;
return sprintf ( V_27 , L_7 , V_51 [ V_30 ] ) ;
}
static T_3 F_59 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
T_1 V_1 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_1 = F_48 ( V_10 , V_52 ) ;
switch ( V_11 ) {
case 0 :
V_10 -> V_47 [ V_11 ] = V_1 & 0x07 ;
break;
case 1 :
V_10 -> V_47 [ V_11 ] = ( V_1 >> 3 ) & 0x07 ;
break;
case 2 :
V_10 -> V_47 [ V_11 ] = ( V_1 & 0x40 ) ? 3 : 1 ;
break;
}
V_10 -> V_48 [ V_11 ] = F_15 ( V_4 , F_53 ( V_10 -> V_47 [ V_11 ] ) ) ;
F_31 ( V_10 , V_53 [ V_11 ] , V_10 -> V_48 [ V_11 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_60 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
unsigned long V_4 ;
int V_54 ;
T_1 V_55 ;
if ( F_29 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_55 = F_48 ( V_10 , V_52 ) ;
V_54 = F_52 ( V_10 -> V_48 [ V_11 ] , F_53 ( V_10 -> V_47 [ V_11 ] ) ) ;
switch ( V_11 ) {
case 0 :
case 1 :
V_10 -> V_47 [ V_11 ] = F_19 ( V_4 ) ;
break;
case 2 :
if ( V_4 < 8 )
V_10 -> V_47 [ V_11 ] = 1 ;
else
V_10 -> V_47 [ V_11 ] = 3 ;
}
V_4 = V_55 & 0x80 ;
V_4 |= ( V_10 -> V_47 [ 0 ] & 0x07 ) ;
V_4 |= ( V_10 -> V_47 [ 1 ] & 0x07 ) << 3 ;
if ( V_10 -> V_47 [ 2 ] == 3 )
V_4 |= 0x1 << 6 ;
F_31 ( V_10 , V_52 , V_4 ) ;
V_10 -> V_48 [ V_11 ] = F_15 ( V_54 , F_53 ( V_10 -> V_47 [ V_11 ] ) ) ;
F_31 ( V_10 , V_53 [ V_11 ] , V_10 -> V_48 [ V_11 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static int F_61 ( struct V_23 * V_24 , int V_11 )
{
const struct V_9 * V_10 = F_28 ( V_24 ) ;
int V_56 , V_57 = 0 ;
if ( F_21 ( V_10 ) ) {
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( V_10 -> V_58 [ V_11 ] [ V_56 ] > V_10 -> V_58 [ V_11 ] [ V_56 + 1 ] )
V_57 = - V_35 ;
}
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
if ( V_10 -> V_59 [ V_11 ] [ V_56 ] > V_10 -> V_59 [ V_11 ] [ V_56 + 1 ] )
V_57 = - V_35 ;
}
}
if ( V_57 ) {
F_62 ( V_24 , L_8
L_9 ) ;
F_62 ( V_24 , L_10 ) ;
}
return V_57 ;
}
static T_3 F_63 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 2 )
return - V_35 ;
if ( V_4 == 2 ) {
if ( F_61 ( V_24 , V_11 ) < 0 )
return - V_35 ;
}
F_30 ( & V_10 -> V_36 ) ;
if ( V_4 == 0 ) {
int V_60 ;
V_60 = F_48 ( V_10 , V_61 ) ;
F_31 ( V_10 , V_61 , V_60 | ( 1 << V_11 ) ) ;
V_10 -> V_44 &= ~ ( 1 << V_11 ) ;
F_31 ( V_10 , V_62 ,
V_10 -> V_44 ) ;
} else {
if ( V_4 == 1 )
V_10 -> V_45 [ V_11 ] = V_10 -> type == V_13 ?
V_10 -> V_63 [ V_11 ] :
V_10 -> V_49 [ V_11 ] ;
else
V_10 -> V_45 [ V_11 ] = 0x80 | V_10 -> V_63 [ V_11 ] ;
F_31 ( V_10 , F_64 ( V_11 ) , V_10 -> V_45 [ V_11 ] ) ;
V_10 -> V_44 |= ( 1 << V_11 ) ;
F_31 ( V_10 , V_62 ,
V_10 -> V_44 ) ;
}
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_65 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
if ( V_10 -> type == V_13 ) {
if ( V_10 -> V_45 [ V_11 ] & 0x80 ) {
F_33 ( & V_10 -> V_36 ) ;
return - V_8 ;
}
V_10 -> V_49 [ V_11 ] = F_17 ( V_10 , V_4 ) ;
F_31 ( V_10 , F_66 ( V_11 ) ,
V_10 -> V_49 [ V_11 ] ) ;
} else {
V_10 -> V_49 [ V_11 ] = F_17 ( V_10 , V_4 ) ;
if ( ! ( V_10 -> V_45 [ V_11 ] & 0x80 ) ) {
V_10 -> V_45 [ V_11 ] = V_10 -> V_49 [ V_11 ] ;
F_31 ( V_10 , F_64 ( V_11 ) ,
V_10 -> V_45 [ V_11 ] ) ;
}
}
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_67 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_4 V_34 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
unsigned long V_4 ;
int V_56 ;
if ( F_29 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
for ( V_56 = 0 ; V_56 < 7 ; V_56 ++ ) {
if ( V_4 > ( V_51 [ V_56 ] + V_51 [ V_56 + 1 ] ) / 2 )
break;
}
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_50 = F_48 ( V_10 , V_61 ) & 0x8f ;
V_10 -> V_50 |= V_56 << 4 ;
F_31 ( V_10 , V_61 , V_10 -> V_50 ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_68 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
int V_64 ;
if ( V_10 -> V_63 [ V_11 ] < 3 )
V_64 = 1 << V_10 -> V_63 [ V_11 ] ;
else
V_64 = 0 ;
return sprintf ( V_27 , L_1 , V_64 ) ;
}
static T_3 F_69 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
T_1 V_1 ;
if ( ! F_21 ( V_10 ) ) {
F_70 ( V_24 , L_11 ) ;
return - V_35 ;
}
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
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
return - V_35 ;
}
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_63 [ V_11 ] = V_1 ;
if ( V_10 -> V_45 [ V_11 ] & 0x80 ) {
V_10 -> V_45 [ V_11 ] = 0x80 | V_10 -> V_63 [ V_11 ] ;
F_31 ( V_10 , F_64 ( V_11 ) , V_10 -> V_45 [ V_11 ] ) ;
}
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_71 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_9 * V_10 = F_24 ( V_24 ) ;
struct V_65 * V_29 =
F_72 ( V_26 ) ;
int V_11 = V_29 -> V_11 ;
int V_66 = V_29 -> V_30 ;
return sprintf ( V_27 , L_1 ,
F_18 ( V_10 , V_10 -> V_59 [ V_11 ] [ V_66 ] ) ) ;
}
static T_3 F_73 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_4 V_34 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
struct V_65 * V_29 =
F_72 ( V_26 ) ;
int V_11 = V_29 -> V_11 ;
int V_66 = V_29 -> V_30 ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 || V_4 < 0 || V_4 > 255 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_59 [ V_11 ] [ V_66 ] = F_17 ( V_10 , V_4 ) ;
F_31 ( V_10 , F_74 ( V_11 , V_66 ) ,
V_10 -> V_59 [ V_11 ] [ V_66 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_75 ( struct V_23 * V_24 ,
struct V_25 * V_26 , char * V_27 )
{
struct V_9 * V_10 = F_24 ( V_24 ) ;
struct V_65 * V_29 =
F_72 ( V_26 ) ;
int V_11 = V_29 -> V_11 ;
int V_66 = V_29 -> V_30 ;
return sprintf ( V_27 , L_1 , F_37 ( V_10 -> V_58 [ V_11 ] [ V_66 ] ) ) ;
}
static T_3 F_76 ( struct V_23 * V_24 ,
struct V_25 * V_26 , const char * V_27 , T_4 V_34 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
struct V_65 * V_29 =
F_72 ( V_26 ) ;
int V_11 = V_29 -> V_11 ;
int V_66 = V_29 -> V_30 ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 || V_4 < - 128000 || V_4 > 127000 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_58 [ V_11 ] [ V_66 ] = F_42 ( V_4 ) ;
F_31 ( V_10 , F_77 ( V_11 , V_66 ) ,
V_10 -> V_58 [ V_11 ] [ V_66 ] ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_78 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_79 ( V_10 -> V_46 [ V_11 ] ) ) ;
}
static T_3 F_80 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_1 , F_79 ( V_10 -> V_48 [ V_11 ] ) ) ;
}
static T_3 F_81 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_28 * V_29 = F_23 ( V_26 ) ;
int V_11 = V_29 -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_48 [ V_11 ] = F_16 ( V_4 ) ;
F_31 ( V_10 , V_53 [ V_11 ] ,
V_10 -> V_48 [ V_11 ] & 0xff ) ;
F_31 ( V_10 , V_67 [ V_11 ] ,
V_10 -> V_48 [ V_11 ] >> 8 ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_82 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_7 , V_10 -> V_68 ) ;
}
static T_3 F_83 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
int V_69 = F_23 ( V_26 ) -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_7 , ( V_10 -> V_68 >> V_69 ) & 1 ) ;
}
static T_3 F_84 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
int V_69 = F_23 ( V_26 ) -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_7 , ( V_10 -> V_70 >> V_69 ) & 1 ) ;
}
static T_3 F_85 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
int V_69 = F_23 ( V_26 ) -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0
|| ( V_4 != 0 && V_4 != 1 ) )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_70 = F_48 ( V_10 , V_71 ) ;
if ( V_4 )
V_10 -> V_70 |= ( 1 << V_69 ) ;
else
V_10 -> V_70 &= ~ ( 1 << V_69 ) ;
F_31 ( V_10 , V_71 , V_10 -> V_70 ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_86 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
return sprintf ( V_27 , L_7 , V_10 -> V_72 ) ;
}
static T_3 F_87 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
unsigned long V_4 ;
if ( F_29 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
V_10 -> V_72 = V_4 ;
return V_34 ;
}
static T_3 F_88 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_12 , ( long ) F_89 ( V_10 -> V_73 , V_10 -> V_72 ) ) ;
}
static T_3 F_90 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
static const char * V_74 [] = {
L_13 ,
L_14 ,
L_15 ,
} ;
static const char * V_75 [] = {
L_16 ,
L_17 ,
L_15 ,
} ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
int V_11 = F_23 ( V_26 ) -> V_30 ;
return sprintf ( V_27 , L_18 , V_10 -> type == V_13 ? V_75 [ V_11 ]
: V_74 [ V_11 ] ) ;
}
static T_3 F_91 ( struct V_23 * V_24 , struct V_25
* V_76 , char * V_27 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
return sprintf ( V_27 , L_18 , V_10 -> V_77 ) ;
}
static const struct V_78 *
F_92 ( const struct V_9 * V_10 )
{
return F_20 ( V_10 ) ? V_79 : V_80 ;
}
static int T_5 F_93 ( unsigned short * V_81 ,
struct V_82 * V_83 )
{
int V_57 ;
T_2 V_84 ;
const char * V_85 , * V_86 ;
V_57 = F_7 () ;
if ( V_57 )
return V_57 ;
V_57 = - V_87 ;
V_84 = V_88 ? V_88 : F_5 ( V_89 ) ;
switch ( V_84 ) {
case V_90 :
V_83 -> type = V_17 ;
break;
case V_91 :
V_83 -> type = V_19 ;
break;
case V_92 :
case V_93 :
V_83 -> type = V_20 ;
break;
case V_94 :
V_83 -> type = V_21 ;
break;
case V_95 :
V_83 -> type = V_22 ;
break;
case V_96 :
V_83 -> type = V_13 ;
break;
case 0xffff :
goto exit;
default:
F_94 ( L_19 , V_84 ) ;
goto exit;
}
F_6 ( V_97 ) ;
if ( ! ( F_1 ( V_98 ) & 0x01 ) ) {
F_95 ( L_20 ) ;
goto exit;
}
* V_81 = F_5 ( V_99 ) & ~ ( V_100 - 1 ) ;
if ( * V_81 == 0 ) {
F_95 ( L_21 ) ;
goto exit;
}
V_57 = 0 ;
V_83 -> V_18 = F_1 ( V_101 ) & 0x0f ;
F_95 ( L_22 ,
V_84 , * V_81 , V_83 -> V_18 ) ;
V_83 -> V_102 = ( 1 << 2 ) ;
if ( V_83 -> type == V_17 ) {
V_83 -> V_103 = 1 ;
F_6 ( 5 ) ;
V_83 -> V_104 = F_1 ( V_105 ) & 0x3f ;
} else {
int V_1 ;
F_6 ( V_106 ) ;
V_1 = F_1 ( V_107 ) ;
if ( V_83 -> type == V_13 ) {
V_83 -> V_103 = 1 ;
} else {
if ( V_1 & 0x0f ) {
F_95 ( L_23 ) ;
V_83 -> V_103 = 1 ;
}
}
if ( V_1 & ( 1 << 6 ) )
V_83 -> V_108 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_83 -> V_109 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_110 ) ;
if ( V_1 & ( 1 << 1 ) )
V_83 -> V_108 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_83 -> V_109 |= ( 1 << 1 ) ;
if ( ( V_83 -> type == V_21 || V_83 -> type == V_22 )
&& ! ( V_83 -> V_103 ) )
V_83 -> V_111 = F_1 ( V_112 ) ;
V_1 = F_1 ( V_113 ) ;
if ( V_83 -> type == V_22 && ! ( V_1 & ( 1 << 1 ) ) ) {
V_1 |= ( 1 << 1 ) ;
F_4 ( V_113 , V_1 ) ;
F_96 ( L_24 ) ;
}
if ( V_1 & ( 1 << 0 ) )
V_83 -> V_102 |= ( 1 << 0 ) ;
if ( ( V_1 & ( 1 << 1 ) ) || V_83 -> type == V_13 )
V_83 -> V_102 |= ( 1 << 1 ) ;
V_83 -> V_104 = F_1 ( V_105 ) & 0x3f ;
}
if ( V_83 -> V_104 )
F_95 ( L_25 ) ;
V_85 = F_97 ( V_114 ) ;
V_86 = F_97 ( V_115 ) ;
if ( V_85 && V_86 ) {
if ( strcmp ( V_85 , L_26 ) == 0
&& strcmp ( V_86 , L_27 ) == 0 ) {
F_95 ( L_28 ) ;
V_83 -> V_108 = ( 1 << 1 ) ;
}
}
exit:
F_9 () ;
return V_57 ;
}
static void F_98 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = F_99 ( V_116 ) ;
struct V_82 * V_83 = V_24 -> V_117 ;
const struct V_78 * V_118 = F_92 ( V_10 ) ;
int V_56 ;
F_100 ( & V_24 -> V_119 , & V_120 ) ;
if ( V_83 -> V_104 )
F_100 ( & V_24 -> V_119 , & V_121 ) ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
if ( ! ( V_10 -> V_122 & ( 1 << V_56 ) ) )
continue;
F_100 ( & V_24 -> V_119 , & V_118 [ V_56 ] ) ;
if ( V_83 -> V_104 )
F_101 ( & V_24 -> V_119 ,
V_123 [ V_56 ] ) ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( V_83 -> V_108 & ( 1 << 0 ) )
continue;
F_100 ( & V_24 -> V_119 , & V_124 [ V_56 ] ) ;
if ( F_21 ( V_10 ) )
F_100 ( & V_24 -> V_119 ,
& V_125 [ V_56 ] ) ;
}
if ( ! V_83 -> V_103 )
F_100 ( & V_24 -> V_119 , & V_126 ) ;
F_100 ( & V_24 -> V_119 , & V_127 ) ;
}
static int T_6 F_102 ( struct V_128 * V_116 )
{
struct V_9 * V_10 ;
struct V_129 * V_130 ;
struct V_23 * V_24 = & V_116 -> V_24 ;
struct V_82 * V_83 = V_24 -> V_117 ;
const struct V_78 * V_118 ;
int V_57 = 0 , V_56 ;
int V_131 ;
int V_132 ;
static const char * V_133 [] = {
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
} ;
V_130 = F_103 ( V_116 , V_134 , 0 ) ;
if ( ! F_104 ( V_130 -> V_135 , V_136 , V_7 ) ) {
F_62 ( V_24 , L_35 ,
( unsigned long ) V_130 -> V_135 ,
( unsigned long ) ( V_130 -> V_135 + V_136 - 1 ) ) ;
V_57 = - V_8 ;
goto V_137;
}
V_10 = F_105 ( sizeof( struct V_9 ) , V_138 ) ;
if ( ! V_10 ) {
V_57 = - V_139 ;
goto V_140;
}
V_10 -> V_141 = V_130 -> V_135 ;
V_10 -> type = V_83 -> type ;
V_10 -> V_18 = V_83 -> V_18 ;
V_10 -> V_77 = V_133 [ V_83 -> type ] ;
if ( ( F_48 ( V_10 , V_142 ) & 0x80 )
|| F_48 ( V_10 , V_143 ) != 0x90 ) {
V_57 = - V_87 ;
goto V_144;
}
F_106 ( V_116 , V_10 ) ;
F_107 ( & V_10 -> V_36 ) ;
V_131 = F_108 ( V_24 ) ;
if ( V_10 -> type == V_13 ) {
if ( V_83 -> V_102 & ( 1 << 0 ) )
V_10 -> V_14 |= ( 1 << 3 ) ;
if ( V_83 -> V_102 & ( 1 << 1 ) )
V_10 -> V_14 |= ( 1 << 7 ) ;
if ( V_83 -> V_102 & ( 1 << 2 ) )
V_10 -> V_14 |= ( 1 << 8 ) ;
}
F_109 ( V_116 ) ;
V_57 = F_110 ( & V_24 -> V_119 , & V_120 ) ;
if ( V_57 )
goto V_144;
if ( V_83 -> V_104 ) {
V_57 = F_110 ( & V_24 -> V_119 , & V_121 ) ;
if ( V_57 )
goto V_145;
}
V_118 = F_92 ( V_10 ) ;
V_132 = 1 ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
if ( ! ( V_10 -> V_122 & ( 1 << V_56 ) ) )
continue;
V_57 = F_110 ( & V_24 -> V_119 , & V_118 [ V_56 ] ) ;
if ( V_57 )
goto V_145;
if ( V_83 -> V_104 ) {
V_57 = F_111 ( & V_24 -> V_119 ,
V_123 [ V_56 ] ) ;
if ( V_57 )
goto V_145;
if ( ! V_132 )
continue;
if ( F_112 ( & V_24 -> V_119 ,
V_123 [ V_56 ] ,
V_146 | V_147 ) )
F_113 ( V_24 , L_36 ,
V_56 + 1 ) ;
V_132 = 0 ;
}
}
if ( V_131 ) {
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( V_83 -> V_108 & ( 1 << V_56 ) )
continue;
V_57 = F_110 ( & V_24 -> V_119 ,
& V_124 [ V_56 ] ) ;
if ( V_57 )
goto V_145;
if ( ! F_21 ( V_10 ) )
continue;
V_57 = F_110 ( & V_24 -> V_119 ,
& V_125 [ V_56 ] ) ;
if ( V_57 )
goto V_145;
}
}
if ( ! V_83 -> V_103 ) {
V_10 -> V_72 = F_114 () ;
V_10 -> V_73 = V_83 -> V_111 ;
V_57 = F_110 ( & V_24 -> V_119 , & V_126 ) ;
if ( V_57 )
goto V_145;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( ! ( V_83 -> V_102 & ( 1 << V_56 ) ) )
continue;
V_57 = F_111 ( & V_24 -> V_119 ,
V_148 [ V_56 ] ) ;
if ( V_57 )
goto V_145;
}
V_10 -> V_149 = F_115 ( V_24 ) ;
if ( F_116 ( V_10 -> V_149 ) ) {
V_57 = F_117 ( V_10 -> V_149 ) ;
goto V_145;
}
return 0 ;
V_145:
F_98 ( V_24 ) ;
V_144:
F_106 ( V_116 , NULL ) ;
F_118 ( V_10 ) ;
V_140:
F_10 ( V_130 -> V_135 , V_136 ) ;
V_137:
return V_57 ;
}
static int T_7 F_119 ( struct V_128 * V_116 )
{
struct V_9 * V_10 = F_99 ( V_116 ) ;
F_120 ( V_10 -> V_149 ) ;
F_98 ( & V_116 -> V_24 ) ;
F_10 ( V_10 -> V_141 , V_136 ) ;
F_106 ( V_116 , NULL ) ;
F_118 ( V_10 ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 , T_1 V_1 )
{
F_121 ( V_1 , V_10 -> V_141 + V_150 ) ;
return F_122 ( V_10 -> V_141 + V_151 ) ;
}
static void F_31 ( struct V_9 * V_10 , T_1 V_1 , T_1 V_152 )
{
F_121 ( V_1 , V_10 -> V_141 + V_150 ) ;
F_121 ( V_152 , V_10 -> V_141 + V_151 ) ;
}
static int T_6 F_108 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
int V_60 = F_48 ( V_10 , V_61 ) ;
if ( ( V_60 & 0x87 ) == 0 ) {
if ( V_153 ) {
int V_56 ;
T_1 V_154 [ 3 ] ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ )
V_154 [ V_56 ] = F_48 ( V_10 ,
F_64 ( V_56 ) ) ;
if ( ! ( ( V_154 [ 0 ] | V_154 [ 1 ] | V_154 [ 2 ] ) & 0x80 ) ) {
F_123 ( V_24 , L_37
L_38 ) ;
F_31 ( V_10 , V_61 ,
V_60 | 0x87 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ )
F_31 ( V_10 ,
F_64 ( V_56 ) ,
0x7f & ~ V_154 [ V_56 ] ) ;
return 1 ;
}
F_123 ( V_24 , L_39
L_40 ) ;
}
F_123 ( V_24 , L_41
L_42 ) ;
return 0 ;
} else if ( V_153 ) {
F_123 ( V_24 , L_43
L_44 ) ;
}
return 1 ;
}
static void T_6 F_109 ( struct V_128 * V_116 )
{
struct V_82 * V_83 = V_116 -> V_24 . V_117 ;
struct V_9 * V_10 = F_99 ( V_116 ) ;
int V_60 , V_56 ;
T_1 V_155 ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_10 -> V_63 [ V_56 ] = V_56 ;
V_10 -> V_49 [ V_56 ] = 0x7f ;
V_10 -> V_59 [ V_56 ] [ 3 ] = 0x7f ;
}
for ( V_56 = 0 ; V_56 < 8 ; V_56 ++ ) {
V_60 = F_48 ( V_10 , F_32 ( V_56 ) ) ;
if ( V_60 == 0xff )
F_31 ( V_10 , F_32 ( V_56 ) , 0 ) ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_60 = F_48 ( V_10 , F_43 ( V_56 ) ) ;
if ( V_60 == 0xff )
F_31 ( V_10 , F_43 ( V_56 ) , 127 ) ;
}
V_60 = F_48 ( V_10 , V_156 ) ;
if ( ( V_60 & 0xff ) == 0 ) {
F_31 ( V_10 , V_156 , 0xff ) ;
}
V_155 = 0x70 & ~ ( V_83 -> V_109 << 4 ) ;
V_10 -> V_44 = F_48 ( V_10 , V_62 ) ;
if ( ( V_10 -> V_44 & V_155 ) == 0 ) {
V_10 -> V_44 |= V_155 ;
F_31 ( V_10 , V_62 ,
V_10 -> V_44 ) ;
}
V_10 -> V_122 = ( V_10 -> V_44 >> 4 ) & 0x07 ;
if ( F_20 ( V_10 ) ) {
V_60 = F_48 ( V_10 , V_157 ) ;
if ( ~ V_60 & 0x07 & V_10 -> V_122 ) {
F_113 ( & V_116 -> V_24 ,
L_45 ) ;
F_31 ( V_10 , V_157 ,
V_60 | 0x07 ) ;
}
if ( V_10 -> type != V_17 ) {
if ( V_60 & ( 1 << 4 ) )
V_10 -> V_122 |= ( 1 << 3 ) ;
if ( V_60 & ( 1 << 5 ) )
V_10 -> V_122 |= ( 1 << 4 ) ;
}
}
V_10 -> V_122 &= ~ V_83 -> V_109 ;
F_31 ( V_10 , V_142 ,
( F_48 ( V_10 , V_142 ) & 0x36 )
| ( V_158 ? 0x41 : 0x01 ) ) ;
}
static void F_124 ( struct V_9 * V_10 , int V_11 )
{
V_10 -> V_45 [ V_11 ] = F_48 ( V_10 , F_64 ( V_11 ) ) ;
if ( V_10 -> type == V_13 ) {
V_10 -> V_63 [ V_11 ] = V_10 -> V_45 [ V_11 ] & 0x03 ;
V_10 -> V_49 [ V_11 ] = F_48 ( V_10 ,
F_66 ( V_11 ) ) ;
} else {
if ( V_10 -> V_45 [ V_11 ] & 0x80 )
V_10 -> V_63 [ V_11 ] = V_10 -> V_45 [ V_11 ] & 0x03 ;
else
V_10 -> V_49 [ V_11 ] = V_10 -> V_45 [ V_11 ] & 0x7f ;
}
if ( F_21 ( V_10 ) ) {
int V_56 ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ )
V_10 -> V_58 [ V_11 ] [ V_56 ] = F_48 ( V_10 ,
F_77 ( V_11 , V_56 ) ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ )
V_10 -> V_59 [ V_11 ] [ V_56 ] = F_48 ( V_10 ,
F_74 ( V_11 , V_56 ) ) ;
}
}
static struct V_9 * F_24 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
int V_56 ;
F_30 ( & V_10 -> V_36 ) ;
if ( F_125 ( V_159 , V_10 -> V_160 + V_161 + V_161 / 2 )
|| ! V_10 -> V_42 ) {
if ( V_158 ) {
F_31 ( V_10 , V_142 ,
F_48 ( V_10 , V_142 ) | 0x40 ) ;
}
for ( V_56 = 0 ; V_56 <= 7 ; V_56 ++ ) {
V_10 -> V_31 [ V_56 ] =
F_48 ( V_10 , F_126 ( V_56 ) ) ;
V_10 -> V_32 [ V_56 ] =
F_48 ( V_10 , F_32 ( V_56 ) ) ;
V_10 -> V_33 [ V_56 ] =
F_48 ( V_10 , F_35 ( V_56 ) ) ;
}
V_10 -> V_31 [ 8 ] = F_48 ( V_10 , F_126 ( 8 ) ) ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
if ( ! ( V_10 -> V_122 & ( 1 << V_56 ) ) )
continue;
V_10 -> V_48 [ V_56 ] =
F_48 ( V_10 , V_53 [ V_56 ] ) ;
V_10 -> V_46 [ V_56 ] = F_48 ( V_10 ,
V_162 [ V_56 ] ) ;
if ( F_20 ( V_10 ) ) {
V_10 -> V_46 [ V_56 ] |= F_48 ( V_10 ,
V_163 [ V_56 ] ) << 8 ;
V_10 -> V_48 [ V_56 ] |= F_48 ( V_10 ,
V_67 [ V_56 ] ) << 8 ;
}
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_10 -> V_37 [ V_56 ] =
F_48 ( V_10 , F_127 ( V_56 ) ) ;
V_10 -> V_38 [ V_56 ] =
F_48 ( V_10 , F_43 ( V_56 ) ) ;
V_10 -> V_39 [ V_56 ] =
F_48 ( V_10 , F_45 ( V_56 ) ) ;
}
if ( ( V_10 -> V_122 & 0x07 ) && ! F_20 ( V_10 ) ) {
V_56 = F_48 ( V_10 , V_52 ) ;
V_10 -> V_47 [ 0 ] = V_56 & 0x07 ;
V_10 -> V_47 [ 1 ] = ( V_56 >> 3 ) & 0x07 ;
V_10 -> V_47 [ 2 ] = ( V_56 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_68 =
F_48 ( V_10 , V_164 ) |
( F_48 ( V_10 , V_165 ) << 8 ) |
( F_48 ( V_10 , V_166 ) << 16 ) ;
V_10 -> V_70 = F_48 ( V_10 , V_71 ) ;
V_10 -> V_44 = F_48 ( V_10 ,
V_62 ) ;
V_10 -> V_50 = F_48 ( V_10 , V_61 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ )
F_124 ( V_10 , V_56 ) ;
V_10 -> V_40 = F_48 ( V_10 , V_41 ) ;
if ( V_10 -> type == V_19 || V_10 -> type == V_20 ) {
V_10 -> V_73 = F_48 ( V_10 , V_167 ) ;
V_10 -> V_73 &= 0x3f ;
}
V_10 -> V_160 = V_159 ;
V_10 -> V_42 = 1 ;
}
F_33 ( & V_10 -> V_36 ) ;
return V_10 ;
}
static int T_5 F_128 ( unsigned short V_81 ,
const struct V_82 * V_83 )
{
struct V_129 V_130 = {
. V_135 = V_81 + V_168 ,
. V_169 = V_81 + V_168 + V_136 - 1 ,
. V_77 = V_7 ,
. V_170 = V_134 ,
} ;
int V_57 ;
V_57 = F_129 ( & V_130 ) ;
if ( V_57 )
goto exit;
V_116 = F_130 ( V_7 , V_81 ) ;
if ( ! V_116 ) {
V_57 = - V_139 ;
F_131 ( L_46 ) ;
goto exit;
}
V_57 = F_132 ( V_116 , & V_130 , 1 ) ;
if ( V_57 ) {
F_131 ( L_47 , V_57 ) ;
goto V_171;
}
V_57 = F_133 ( V_116 , V_83 ,
sizeof( struct V_82 ) ) ;
if ( V_57 ) {
F_131 ( L_48 ) ;
goto V_171;
}
V_57 = F_134 ( V_116 ) ;
if ( V_57 ) {
F_131 ( L_49 , V_57 ) ;
goto V_171;
}
return 0 ;
V_171:
F_135 ( V_116 ) ;
exit:
return V_57 ;
}
static int T_5 F_136 ( void )
{
int V_57 ;
unsigned short V_172 = 0 ;
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_57 = F_93 ( & V_172 , & V_83 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_137 ( & V_173 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_128 ( V_172 , & V_83 ) ;
if ( V_57 ) {
F_138 ( & V_173 ) ;
return V_57 ;
}
return 0 ;
}
static void T_8 F_139 ( void )
{
F_140 ( V_116 ) ;
F_138 ( & V_173 ) ;
}
