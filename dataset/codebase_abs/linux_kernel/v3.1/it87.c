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
static T_3 F_84 ( struct V_23 * V_24 , struct V_25
* V_26 , const char * V_27 , T_4 V_34 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
int V_70 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0 || V_4 != 0 )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_70 = F_48 ( V_10 , V_71 ) ;
if ( V_70 < 0 ) {
V_34 = V_70 ;
} else {
V_70 |= 1 << 5 ;
F_31 ( V_10 , V_71 , V_70 ) ;
V_10 -> V_42 = 0 ;
}
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_85 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
int V_69 = F_23 ( V_26 ) -> V_30 ;
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_7 , ( V_10 -> V_72 >> V_69 ) & 1 ) ;
}
static T_3 F_86 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
int V_69 = F_23 ( V_26 ) -> V_30 ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
long V_4 ;
if ( F_41 ( V_27 , 10 , & V_4 ) < 0
|| ( V_4 != 0 && V_4 != 1 ) )
return - V_35 ;
F_30 ( & V_10 -> V_36 ) ;
V_10 -> V_72 = F_48 ( V_10 , V_73 ) ;
if ( V_4 )
V_10 -> V_72 |= ( 1 << V_69 ) ;
else
V_10 -> V_72 &= ~ ( 1 << V_69 ) ;
F_31 ( V_10 , V_73 , V_10 -> V_72 ) ;
F_33 ( & V_10 -> V_36 ) ;
return V_34 ;
}
static T_3 F_87 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
return sprintf ( V_27 , L_7 , V_10 -> V_74 ) ;
}
static T_3 F_88 ( struct V_23 * V_24 , struct V_25 * V_26 ,
const char * V_27 , T_4 V_34 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
unsigned long V_4 ;
if ( F_29 ( V_27 , 10 , & V_4 ) < 0 )
return - V_35 ;
V_10 -> V_74 = V_4 ;
return V_34 ;
}
static T_3 F_89 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
struct V_9 * V_10 = F_24 ( V_24 ) ;
return sprintf ( V_27 , L_12 , ( long ) F_90 ( V_10 -> V_75 , V_10 -> V_74 ) ) ;
}
static T_3 F_91 ( struct V_23 * V_24 , struct V_25 * V_26 ,
char * V_27 )
{
static const char * V_76 [] = {
L_13 ,
L_14 ,
L_15 ,
} ;
static const char * V_77 [] = {
L_16 ,
L_17 ,
L_15 ,
} ;
struct V_9 * V_10 = F_28 ( V_24 ) ;
int V_11 = F_23 ( V_26 ) -> V_30 ;
return sprintf ( V_27 , L_18 , V_10 -> type == V_13 ? V_77 [ V_11 ]
: V_76 [ V_11 ] ) ;
}
static T_3 F_92 ( struct V_23 * V_24 , struct V_25
* V_78 , char * V_27 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
return sprintf ( V_27 , L_18 , V_10 -> V_79 ) ;
}
static const struct V_80 *
F_93 ( const struct V_9 * V_10 )
{
return F_20 ( V_10 ) ? V_81 : V_82 ;
}
static int T_5 F_94 ( unsigned short * V_83 ,
struct V_84 * V_85 )
{
int V_57 ;
T_2 V_86 ;
const char * V_87 , * V_88 ;
V_57 = F_7 () ;
if ( V_57 )
return V_57 ;
V_57 = - V_89 ;
V_86 = V_90 ? V_90 : F_5 ( V_91 ) ;
switch ( V_86 ) {
case V_92 :
V_85 -> type = V_17 ;
break;
case V_93 :
V_85 -> type = V_19 ;
break;
case V_94 :
case V_95 :
V_85 -> type = V_20 ;
break;
case V_96 :
V_85 -> type = V_21 ;
break;
case V_97 :
V_85 -> type = V_22 ;
break;
case V_98 :
V_85 -> type = V_13 ;
break;
case 0xffff :
goto exit;
default:
F_95 ( L_19 , V_86 ) ;
goto exit;
}
F_6 ( V_99 ) ;
if ( ! ( F_1 ( V_100 ) & 0x01 ) ) {
F_96 ( L_20 ) ;
goto exit;
}
* V_83 = F_5 ( V_101 ) & ~ ( V_102 - 1 ) ;
if ( * V_83 == 0 ) {
F_96 ( L_21 ) ;
goto exit;
}
V_57 = 0 ;
V_85 -> V_18 = F_1 ( V_103 ) & 0x0f ;
F_96 ( L_22 ,
V_86 , * V_83 , V_85 -> V_18 ) ;
V_85 -> V_104 = ( 1 << 2 ) ;
if ( V_85 -> type == V_17 ) {
V_85 -> V_105 = 1 ;
F_6 ( 5 ) ;
V_85 -> V_106 = F_1 ( V_107 ) & 0x3f ;
} else {
int V_1 ;
F_6 ( V_108 ) ;
V_1 = F_1 ( V_109 ) ;
if ( V_85 -> type == V_13 ) {
V_85 -> V_105 = 1 ;
} else {
if ( V_1 & 0x0f ) {
F_96 ( L_23 ) ;
V_85 -> V_105 = 1 ;
}
}
if ( V_1 & ( 1 << 6 ) )
V_85 -> V_110 |= ( 1 << 2 ) ;
if ( V_1 & ( 1 << 7 ) )
V_85 -> V_111 |= ( 1 << 2 ) ;
V_1 = F_1 ( V_112 ) ;
if ( V_1 & ( 1 << 1 ) )
V_85 -> V_110 |= ( 1 << 1 ) ;
if ( V_1 & ( 1 << 2 ) )
V_85 -> V_111 |= ( 1 << 1 ) ;
if ( ( V_85 -> type == V_21 || V_85 -> type == V_22 )
&& ! ( V_85 -> V_105 ) )
V_85 -> V_113 = F_1 ( V_114 ) ;
V_1 = F_1 ( V_115 ) ;
if ( V_85 -> type == V_22 && ! ( V_1 & ( 1 << 1 ) ) ) {
V_1 |= ( 1 << 1 ) ;
F_4 ( V_115 , V_1 ) ;
F_97 ( L_24 ) ;
}
if ( V_1 & ( 1 << 0 ) )
V_85 -> V_104 |= ( 1 << 0 ) ;
if ( ( V_1 & ( 1 << 1 ) ) || V_85 -> type == V_13 )
V_85 -> V_104 |= ( 1 << 1 ) ;
V_85 -> V_106 = F_1 ( V_107 ) & 0x3f ;
}
if ( V_85 -> V_106 )
F_96 ( L_25 ) ;
V_87 = F_98 ( V_116 ) ;
V_88 = F_98 ( V_117 ) ;
if ( V_87 && V_88 ) {
if ( strcmp ( V_87 , L_26 ) == 0
&& strcmp ( V_88 , L_27 ) == 0 ) {
F_96 ( L_28 ) ;
V_85 -> V_110 = ( 1 << 1 ) ;
}
}
exit:
F_9 () ;
return V_57 ;
}
static void F_99 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = F_100 ( V_118 ) ;
struct V_84 * V_85 = V_24 -> V_119 ;
const struct V_80 * V_120 = F_93 ( V_10 ) ;
int V_56 ;
F_101 ( & V_24 -> V_121 , & V_122 ) ;
if ( V_85 -> V_106 )
F_101 ( & V_24 -> V_121 , & V_123 ) ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
if ( ! ( V_10 -> V_124 & ( 1 << V_56 ) ) )
continue;
F_101 ( & V_24 -> V_121 , & V_120 [ V_56 ] ) ;
if ( V_85 -> V_106 )
F_102 ( & V_24 -> V_121 ,
V_125 [ V_56 ] ) ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( V_85 -> V_110 & ( 1 << 0 ) )
continue;
F_101 ( & V_24 -> V_121 , & V_126 [ V_56 ] ) ;
if ( F_21 ( V_10 ) )
F_101 ( & V_24 -> V_121 ,
& V_127 [ V_56 ] ) ;
}
if ( ! V_85 -> V_105 )
F_101 ( & V_24 -> V_121 , & V_128 ) ;
F_101 ( & V_24 -> V_121 , & V_129 ) ;
}
static int T_6 F_103 ( struct V_130 * V_118 )
{
struct V_9 * V_10 ;
struct V_131 * V_132 ;
struct V_23 * V_24 = & V_118 -> V_24 ;
struct V_84 * V_85 = V_24 -> V_119 ;
const struct V_80 * V_120 ;
int V_57 = 0 , V_56 ;
int V_133 ;
int V_134 ;
static const char * V_135 [] = {
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
} ;
V_132 = F_104 ( V_118 , V_136 , 0 ) ;
if ( ! F_105 ( V_132 -> V_137 , V_138 , V_7 ) ) {
F_62 ( V_24 , L_35 ,
( unsigned long ) V_132 -> V_137 ,
( unsigned long ) ( V_132 -> V_137 + V_138 - 1 ) ) ;
V_57 = - V_8 ;
goto V_139;
}
V_10 = F_106 ( sizeof( struct V_9 ) , V_140 ) ;
if ( ! V_10 ) {
V_57 = - V_141 ;
goto V_142;
}
V_10 -> V_143 = V_132 -> V_137 ;
V_10 -> type = V_85 -> type ;
V_10 -> V_18 = V_85 -> V_18 ;
V_10 -> V_79 = V_135 [ V_85 -> type ] ;
if ( ( F_48 ( V_10 , V_71 ) & 0x80 )
|| F_48 ( V_10 , V_144 ) != 0x90 ) {
V_57 = - V_89 ;
goto V_145;
}
F_107 ( V_118 , V_10 ) ;
F_108 ( & V_10 -> V_36 ) ;
V_133 = F_109 ( V_24 ) ;
if ( V_10 -> type == V_13 ) {
if ( V_85 -> V_104 & ( 1 << 0 ) )
V_10 -> V_14 |= ( 1 << 3 ) ;
if ( V_85 -> V_104 & ( 1 << 1 ) )
V_10 -> V_14 |= ( 1 << 7 ) ;
if ( V_85 -> V_104 & ( 1 << 2 ) )
V_10 -> V_14 |= ( 1 << 8 ) ;
}
F_110 ( V_118 ) ;
V_57 = F_111 ( & V_24 -> V_121 , & V_122 ) ;
if ( V_57 )
goto V_145;
if ( V_85 -> V_106 ) {
V_57 = F_111 ( & V_24 -> V_121 , & V_123 ) ;
if ( V_57 )
goto V_146;
}
V_120 = F_93 ( V_10 ) ;
V_134 = 1 ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
if ( ! ( V_10 -> V_124 & ( 1 << V_56 ) ) )
continue;
V_57 = F_111 ( & V_24 -> V_121 , & V_120 [ V_56 ] ) ;
if ( V_57 )
goto V_146;
if ( V_85 -> V_106 ) {
V_57 = F_112 ( & V_24 -> V_121 ,
V_125 [ V_56 ] ) ;
if ( V_57 )
goto V_146;
if ( ! V_134 )
continue;
if ( F_113 ( & V_24 -> V_121 ,
V_125 [ V_56 ] ,
V_147 | V_148 ) )
F_114 ( V_24 , L_36 ,
V_56 + 1 ) ;
V_134 = 0 ;
}
}
if ( V_133 ) {
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( V_85 -> V_110 & ( 1 << V_56 ) )
continue;
V_57 = F_111 ( & V_24 -> V_121 ,
& V_126 [ V_56 ] ) ;
if ( V_57 )
goto V_146;
if ( ! F_21 ( V_10 ) )
continue;
V_57 = F_111 ( & V_24 -> V_121 ,
& V_127 [ V_56 ] ) ;
if ( V_57 )
goto V_146;
}
}
if ( ! V_85 -> V_105 ) {
V_10 -> V_74 = F_115 () ;
V_10 -> V_75 = V_85 -> V_113 ;
V_57 = F_111 ( & V_24 -> V_121 , & V_128 ) ;
if ( V_57 )
goto V_146;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( ! ( V_85 -> V_104 & ( 1 << V_56 ) ) )
continue;
V_57 = F_112 ( & V_24 -> V_121 ,
V_149 [ V_56 ] ) ;
if ( V_57 )
goto V_146;
}
V_10 -> V_150 = F_116 ( V_24 ) ;
if ( F_117 ( V_10 -> V_150 ) ) {
V_57 = F_118 ( V_10 -> V_150 ) ;
goto V_146;
}
return 0 ;
V_146:
F_99 ( V_24 ) ;
V_145:
F_107 ( V_118 , NULL ) ;
F_119 ( V_10 ) ;
V_142:
F_10 ( V_132 -> V_137 , V_138 ) ;
V_139:
return V_57 ;
}
static int T_7 F_120 ( struct V_130 * V_118 )
{
struct V_9 * V_10 = F_100 ( V_118 ) ;
F_121 ( V_10 -> V_150 ) ;
F_99 ( & V_118 -> V_24 ) ;
F_10 ( V_10 -> V_143 , V_138 ) ;
F_107 ( V_118 , NULL ) ;
F_119 ( V_10 ) ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 , T_1 V_1 )
{
F_122 ( V_1 , V_10 -> V_143 + V_151 ) ;
return F_123 ( V_10 -> V_143 + V_152 ) ;
}
static void F_31 ( struct V_9 * V_10 , T_1 V_1 , T_1 V_153 )
{
F_122 ( V_1 , V_10 -> V_143 + V_151 ) ;
F_122 ( V_153 , V_10 -> V_143 + V_152 ) ;
}
static int T_6 F_109 ( struct V_23 * V_24 )
{
struct V_9 * V_10 = F_28 ( V_24 ) ;
int V_60 = F_48 ( V_10 , V_61 ) ;
if ( ( V_60 & 0x87 ) == 0 ) {
if ( V_154 ) {
int V_56 ;
T_1 V_155 [ 3 ] ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ )
V_155 [ V_56 ] = F_48 ( V_10 ,
F_64 ( V_56 ) ) ;
if ( ! ( ( V_155 [ 0 ] | V_155 [ 1 ] | V_155 [ 2 ] ) & 0x80 ) ) {
F_124 ( V_24 , L_37
L_38 ) ;
F_31 ( V_10 , V_61 ,
V_60 | 0x87 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ )
F_31 ( V_10 ,
F_64 ( V_56 ) ,
0x7f & ~ V_155 [ V_56 ] ) ;
return 1 ;
}
F_124 ( V_24 , L_39
L_40 ) ;
}
F_124 ( V_24 , L_41
L_42 ) ;
return 0 ;
} else if ( V_154 ) {
F_124 ( V_24 , L_43
L_44 ) ;
}
return 1 ;
}
static void T_6 F_110 ( struct V_130 * V_118 )
{
struct V_84 * V_85 = V_118 -> V_24 . V_119 ;
struct V_9 * V_10 = F_100 ( V_118 ) ;
int V_60 , V_56 ;
T_1 V_156 ;
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
V_60 = F_48 ( V_10 , V_157 ) ;
if ( ( V_60 & 0xff ) == 0 ) {
F_31 ( V_10 , V_157 , 0xff ) ;
}
V_156 = 0x70 & ~ ( V_85 -> V_111 << 4 ) ;
V_10 -> V_44 = F_48 ( V_10 , V_62 ) ;
if ( ( V_10 -> V_44 & V_156 ) == 0 ) {
V_10 -> V_44 |= V_156 ;
F_31 ( V_10 , V_62 ,
V_10 -> V_44 ) ;
}
V_10 -> V_124 = ( V_10 -> V_44 >> 4 ) & 0x07 ;
if ( F_20 ( V_10 ) ) {
V_60 = F_48 ( V_10 , V_158 ) ;
if ( ~ V_60 & 0x07 & V_10 -> V_124 ) {
F_114 ( & V_118 -> V_24 ,
L_45 ) ;
F_31 ( V_10 , V_158 ,
V_60 | 0x07 ) ;
}
if ( V_10 -> type != V_17 ) {
if ( V_60 & ( 1 << 4 ) )
V_10 -> V_124 |= ( 1 << 3 ) ;
if ( V_60 & ( 1 << 5 ) )
V_10 -> V_124 |= ( 1 << 4 ) ;
}
}
V_10 -> V_124 &= ~ V_85 -> V_111 ;
F_31 ( V_10 , V_71 ,
( F_48 ( V_10 , V_71 ) & 0x36 )
| ( V_159 ? 0x41 : 0x01 ) ) ;
}
static void F_125 ( struct V_9 * V_10 , int V_11 )
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
if ( F_126 ( V_160 , V_10 -> V_161 + V_162 + V_162 / 2 )
|| ! V_10 -> V_42 ) {
if ( V_159 ) {
F_31 ( V_10 , V_71 ,
F_48 ( V_10 , V_71 ) | 0x40 ) ;
}
for ( V_56 = 0 ; V_56 <= 7 ; V_56 ++ ) {
V_10 -> V_31 [ V_56 ] =
F_48 ( V_10 , F_127 ( V_56 ) ) ;
V_10 -> V_32 [ V_56 ] =
F_48 ( V_10 , F_32 ( V_56 ) ) ;
V_10 -> V_33 [ V_56 ] =
F_48 ( V_10 , F_35 ( V_56 ) ) ;
}
V_10 -> V_31 [ 8 ] = F_48 ( V_10 , F_127 ( 8 ) ) ;
for ( V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
if ( ! ( V_10 -> V_124 & ( 1 << V_56 ) ) )
continue;
V_10 -> V_48 [ V_56 ] =
F_48 ( V_10 , V_53 [ V_56 ] ) ;
V_10 -> V_46 [ V_56 ] = F_48 ( V_10 ,
V_163 [ V_56 ] ) ;
if ( F_20 ( V_10 ) ) {
V_10 -> V_46 [ V_56 ] |= F_48 ( V_10 ,
V_164 [ V_56 ] ) << 8 ;
V_10 -> V_48 [ V_56 ] |= F_48 ( V_10 ,
V_67 [ V_56 ] ) << 8 ;
}
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_10 -> V_37 [ V_56 ] =
F_48 ( V_10 , F_128 ( V_56 ) ) ;
V_10 -> V_38 [ V_56 ] =
F_48 ( V_10 , F_43 ( V_56 ) ) ;
V_10 -> V_39 [ V_56 ] =
F_48 ( V_10 , F_45 ( V_56 ) ) ;
}
if ( ( V_10 -> V_124 & 0x07 ) && ! F_20 ( V_10 ) ) {
V_56 = F_48 ( V_10 , V_52 ) ;
V_10 -> V_47 [ 0 ] = V_56 & 0x07 ;
V_10 -> V_47 [ 1 ] = ( V_56 >> 3 ) & 0x07 ;
V_10 -> V_47 [ 2 ] = ( V_56 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_68 =
F_48 ( V_10 , V_165 ) |
( F_48 ( V_10 , V_166 ) << 8 ) |
( F_48 ( V_10 , V_167 ) << 16 ) ;
V_10 -> V_72 = F_48 ( V_10 , V_73 ) ;
V_10 -> V_44 = F_48 ( V_10 ,
V_62 ) ;
V_10 -> V_50 = F_48 ( V_10 , V_61 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ )
F_125 ( V_10 , V_56 ) ;
V_10 -> V_40 = F_48 ( V_10 , V_41 ) ;
if ( V_10 -> type == V_19 || V_10 -> type == V_20 ) {
V_10 -> V_75 = F_48 ( V_10 , V_168 ) ;
V_10 -> V_75 &= 0x3f ;
}
V_10 -> V_161 = V_160 ;
V_10 -> V_42 = 1 ;
}
F_33 ( & V_10 -> V_36 ) ;
return V_10 ;
}
static int T_5 F_129 ( unsigned short V_83 ,
const struct V_84 * V_85 )
{
struct V_131 V_132 = {
. V_137 = V_83 + V_169 ,
. V_170 = V_83 + V_169 + V_138 - 1 ,
. V_79 = V_7 ,
. V_171 = V_136 ,
} ;
int V_57 ;
V_57 = F_130 ( & V_132 ) ;
if ( V_57 )
goto exit;
V_118 = F_131 ( V_7 , V_83 ) ;
if ( ! V_118 ) {
V_57 = - V_141 ;
F_132 ( L_46 ) ;
goto exit;
}
V_57 = F_133 ( V_118 , & V_132 , 1 ) ;
if ( V_57 ) {
F_132 ( L_47 , V_57 ) ;
goto V_172;
}
V_57 = F_134 ( V_118 , V_85 ,
sizeof( struct V_84 ) ) ;
if ( V_57 ) {
F_132 ( L_48 ) ;
goto V_172;
}
V_57 = F_135 ( V_118 ) ;
if ( V_57 ) {
F_132 ( L_49 , V_57 ) ;
goto V_172;
}
return 0 ;
V_172:
F_136 ( V_118 ) ;
exit:
return V_57 ;
}
static int T_5 F_137 ( void )
{
int V_57 ;
unsigned short V_173 = 0 ;
struct V_84 V_85 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_57 = F_94 ( & V_173 , & V_85 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_138 ( & V_174 ) ;
if ( V_57 )
return V_57 ;
V_57 = F_129 ( V_173 , & V_85 ) ;
if ( V_57 ) {
F_139 ( & V_174 ) ;
return V_57 ;
}
return 0 ;
}
static void T_8 F_140 ( void )
{
F_141 ( V_118 ) ;
F_139 ( & V_174 ) ;
}
