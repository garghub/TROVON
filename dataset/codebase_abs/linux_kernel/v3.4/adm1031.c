static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline int
F_3 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static int F_5 ( int V_3 , int div )
{
int V_5 ;
V_5 = F_6 ( F_7 ( V_3 , 0 , 65535 ) , div ) ;
return V_5 > 255 ? 255 : V_5 ;
}
static int F_8 ( int V_6 , int V_3 , int V_7 )
{
int V_8 ;
int V_9 = V_6 - F_9 ( V_3 ) ;
V_9 = ( ( V_6 - F_9 ( V_3 ) ) * 10 ) / ( 16 - V_7 ) ;
V_8 = ( ( V_3 & 0xf8 ) |
( V_9 < 10000 ? 0 :
V_9 < 20000 ? 1 :
V_9 < 40000 ? 2 : V_9 < 80000 ? 3 : 4 ) ) ;
return V_8 ;
}
static int
F_10 ( struct V_10 * V_11 , int V_12 , T_1 V_6 , T_1 V_3 )
{
int V_13 ;
int V_14 = - 1 , V_15 = - 1 ;
T_1 V_16 =
( * V_11 -> V_17 ) [ F_11 ( V_3 ) ] [ V_12 ? 0 : 1 ] ;
if ( V_6 == 0 )
return 0 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
if ( ( V_6 == ( * V_11 -> V_17 ) [ V_13 ] [ V_12 ] ) &&
( ( * V_11 -> V_17 ) [ V_13 ] [ V_12 ? 0 : 1 ] ==
V_16 ) ) {
V_15 = V_13 ;
break;
} else if ( V_6 == ( * V_11 -> V_17 ) [ V_13 ] [ V_12 ] &&
V_14 == - 1 ) {
V_14 = V_13 ;
}
}
if ( V_15 >= 0 )
return V_15 ;
else if ( V_14 >= 0 )
return V_14 ;
return - V_18 ;
}
static T_2 F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , F_15 ( V_11 , V_24 ) ) ;
}
static T_2
F_16 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
T_1 V_3 ;
int V_8 ;
T_1 V_27 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
V_27 = V_11 -> V_28 ;
F_20 ( & V_11 -> V_29 ) ;
V_8 = F_10 ( V_11 , V_24 , V_6 , V_11 -> V_28 ) ;
if ( V_8 < 0 ) {
F_21 ( & V_11 -> V_29 ) ;
return V_8 ;
}
V_3 = V_8 ;
V_11 -> V_28 = F_22 ( V_3 , V_11 -> V_28 ) ;
if ( ( V_11 -> V_28 & V_30 ) ^
( V_27 & V_30 ) ) {
if ( V_11 -> V_28 & V_30 ) {
V_11 -> V_31 [ 0 ] = V_11 -> V_7 [ 0 ] ;
V_11 -> V_31 [ 1 ] = V_11 -> V_7 [ 1 ] ;
F_3 ( V_2 , V_32 , 0x55 ) ;
} else {
V_11 -> V_7 [ 0 ] = V_11 -> V_31 [ 0 ] ;
V_11 -> V_7 [ 1 ] = V_11 -> V_31 [ 1 ] ;
F_3 ( V_2 , V_32 ,
V_11 -> V_7 [ 0 ] | ( V_11 -> V_7 [ 1 ] << 4 ) ) ;
}
}
V_11 -> V_28 = F_22 ( V_3 , V_11 -> V_28 ) ;
F_3 ( V_2 , V_33 , V_11 -> V_28 ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_23 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 ,
F_24 ( V_11 -> V_34 [ V_24 ] ) ) ;
}
static T_2 F_25 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 ,
F_9 ( V_11 -> V_34 [ V_24 ] ) ) ;
}
static T_2
F_26 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_34 [ V_24 ] = F_27 ( V_6 , V_11 -> V_34 [ V_24 ] ) ;
F_3 ( V_2 , F_28 ( V_24 ) ,
V_11 -> V_34 [ V_24 ] ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_29 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 ,
F_30 ( V_11 -> V_34 [ V_24 ] ) ) ;
}
static T_2
F_31 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_35 [ V_24 ] = F_8 ( V_6 , V_11 -> V_34 [ V_24 ] ,
V_11 -> V_7 [ V_24 ] ) ;
F_3 ( V_2 , F_28 ( V_24 ) ,
V_11 -> V_35 [ V_24 ] ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_32 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , F_33 ( V_11 -> V_7 [ V_24 ] ) ) ;
}
static T_2 F_34 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 , V_3 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
F_20 ( & V_11 -> V_29 ) ;
if ( ( V_11 -> V_28 & V_30 ) &&
( ( ( V_6 >> 4 ) & 0xf ) != 5 ) ) {
F_21 ( & V_11 -> V_29 ) ;
return - V_18 ;
}
V_11 -> V_7 [ V_24 ] = F_35 ( V_6 ) ;
V_3 = F_1 ( V_2 , V_32 ) ;
F_3 ( V_2 , V_32 ,
V_24 ? ( ( V_11 -> V_7 [ V_24 ] << 4 ) & 0xf0 ) | ( V_3 & 0xf )
: ( V_11 -> V_7 [ V_24 ] & 0xf ) | ( V_3 & 0xf0 ) ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static int F_36 ( struct V_10 * V_11 , int V_12 )
{
int V_36 = 0 ;
if ( V_11 -> V_28 & V_30 ) {
switch ( V_11 -> V_28 & 0x60 ) {
case 0x00 :
V_36 = V_11 -> V_37 [ V_12 + 1 ] >=
F_37 ( V_11 -> V_34 [ V_12 + 1 ] ) ;
break;
case 0x20 :
V_36 =
V_11 -> V_37 [ 1 ] >=
F_37 ( V_11 -> V_34 [ 1 ] ) ;
break;
case 0x40 :
V_36 =
V_11 -> V_37 [ 2 ] >=
F_37 ( V_11 -> V_34 [ 2 ] ) ;
break;
case 0x60 :
V_36 =
V_11 -> V_37 [ 0 ] >=
F_37 ( V_11 -> V_34 [ 0 ] )
|| V_11 -> V_37 [ 1 ] >=
F_37 ( V_11 -> V_34 [ 1 ] )
|| ( V_11 -> V_38 == V_39
&& V_11 -> V_37 [ 2 ] >=
F_37 ( V_11 -> V_34 [ 2 ] ) ) ;
break;
}
} else {
V_36 = V_11 -> V_7 [ V_12 ] > 0 ;
}
return V_36 ;
}
static T_2 F_38 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
int V_4 ;
V_4 = F_36 ( V_11 , V_24 ) ? F_6 ( V_11 -> V_40 [ V_24 ] ,
F_39 ( V_11 -> V_41 [ V_24 ] ) ) : 0 ;
return sprintf ( V_23 , L_1 , V_4 ) ;
}
static T_2 F_40 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , F_39 ( V_11 -> V_41 [ V_24 ] ) ) ;
}
static T_2 F_41 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 ,
F_6 ( V_11 -> V_42 [ V_24 ] ,
F_39 ( V_11 -> V_41 [ V_24 ] ) ) ) ;
}
static T_2 F_42 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
F_20 ( & V_11 -> V_29 ) ;
if ( V_6 ) {
V_11 -> V_42 [ V_24 ] =
F_5 ( V_6 , F_39 ( V_11 -> V_41 [ V_24 ] ) ) ;
} else {
V_11 -> V_42 [ V_24 ] = 0xff ;
}
F_3 ( V_2 , F_43 ( V_24 ) , V_11 -> V_42 [ V_24 ] ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_44 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
T_1 V_5 ;
int V_43 ;
int V_44 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
V_5 = V_6 == 8 ? 0xc0 :
V_6 == 4 ? 0x80 :
V_6 == 2 ? 0x40 :
V_6 == 1 ? 0x00 :
0xff ;
if ( V_5 == 0xff )
return - V_18 ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_41 [ V_24 ] = F_1 ( V_2 ,
F_45 ( V_24 ) ) ;
V_11 -> V_42 [ V_24 ] = F_1 ( V_2 ,
F_43 ( V_24 ) ) ;
V_43 = F_39 ( V_11 -> V_41 [ V_24 ] ) ;
V_11 -> V_41 [ V_24 ] = V_5 | ( 0x3f & V_11 -> V_41 [ V_24 ] ) ;
V_44 = V_11 -> V_42 [ V_24 ] * V_43 / V_6 ;
V_11 -> V_42 [ V_24 ] = V_44 > 0xff ? 0xff : V_44 ;
F_3 ( V_2 , F_45 ( V_24 ) ,
V_11 -> V_41 [ V_24 ] ) ;
F_3 ( V_2 , F_43 ( V_24 ) ,
V_11 -> V_42 [ V_24 ] ) ;
V_11 -> V_45 = 0 ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_46 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
int V_46 ;
V_46 = V_24 == 0 ?
( ( V_11 -> V_47 [ V_24 ] >> 6 ) & 0x3 ) * 2 :
( ( ( V_11 -> V_47 [ V_24 ] >> ( ( V_24 - 1 ) * 3 ) ) & 7 ) ) ;
return sprintf ( V_23 , L_1 , F_47 ( V_11 -> V_37 [ V_24 ] , V_46 ) ) ;
}
static T_2 F_48 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 ,
F_49 ( V_11 -> V_48 [ V_24 ] ) ) ;
}
static T_2 F_50 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , F_51 ( V_11 -> V_49 [ V_24 ] ) ) ;
}
static T_2 F_52 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , F_51 ( V_11 -> V_35 [ V_24 ] ) ) ;
}
static T_2 F_53 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_24 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , F_51 ( V_11 -> V_50 [ V_24 ] ) ) ;
}
static T_2 F_54 ( struct V_19 * V_20 ,
struct V_21 * V_22 , const char * V_23 ,
T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
V_6 = F_7 ( V_6 , - 15000 , 15000 ) ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_48 [ V_24 ] = F_55 ( V_6 ) ;
F_3 ( V_2 , F_56 ( V_24 ) ,
V_11 -> V_48 [ V_24 ] ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_57 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
V_6 = F_7 ( V_6 , - 55000 , V_24 == 0 ? 127750 : 127875 ) ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_49 [ V_24 ] = F_58 ( V_6 ) ;
F_3 ( V_2 , F_59 ( V_24 ) ,
V_11 -> V_49 [ V_24 ] ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_60 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
V_6 = F_7 ( V_6 , - 55000 , V_24 == 0 ? 127750 : 127875 ) ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_35 [ V_24 ] = F_58 ( V_6 ) ;
F_3 ( V_2 , F_61 ( V_24 ) ,
V_11 -> V_35 [ V_24 ] ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_62 ( struct V_19 * V_20 , struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
int V_24 = F_13 ( V_22 ) -> V_25 ;
long V_6 ;
int V_8 ;
V_8 = F_19 ( V_23 , 10 , & V_6 ) ;
if ( V_8 )
return V_8 ;
V_6 = F_7 ( V_6 , - 55000 , V_24 == 0 ? 127750 : 127875 ) ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_50 [ V_24 ] = F_58 ( V_6 ) ;
F_3 ( V_2 , F_63 ( V_24 ) ,
V_11 -> V_50 [ V_24 ] ) ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static T_2 F_64 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , V_11 -> V_51 ) ;
}
static T_2 F_65 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
int V_52 = F_13 ( V_22 ) -> V_25 ;
struct V_10 * V_11 = F_14 ( V_20 ) ;
return sprintf ( V_23 , L_1 , ( V_11 -> V_51 >> V_52 ) & 1 ) ;
}
static T_2 F_66 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_23 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
return sprintf ( V_23 , L_2 , V_11 -> V_53 ) ;
}
static T_2 F_67 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 , T_3 V_26 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
unsigned long V_6 ;
int V_13 , V_54 ;
T_1 V_3 ;
V_54 = F_68 ( V_23 , 10 , & V_6 ) ;
if ( V_54 )
return V_54 ;
for ( V_13 = 0 ; V_13 < F_69 ( V_55 ) - 1 ; V_13 ++ ) {
if ( V_6 >= V_55 [ V_13 ] )
break;
}
V_3 = F_1 ( V_2 , V_56 ) ;
V_3 &= ~ V_57 ;
V_3 |= V_13 << V_58 ;
F_3 ( V_2 , V_56 , V_3 ) ;
F_20 ( & V_11 -> V_29 ) ;
V_11 -> V_53 = V_55 [ V_13 ] ;
F_21 ( & V_11 -> V_29 ) ;
return V_26 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_61 * V_62 = V_2 -> V_62 ;
const char * V_63 ;
int V_64 , V_65 ;
if ( ! F_71 ( V_62 , V_66 ) )
return - V_67 ;
V_64 = F_2 ( V_2 , 0x3d ) ;
V_65 = F_2 ( V_2 , 0x3e ) ;
if ( ! ( ( V_64 == 0x31 || V_64 == 0x30 ) && V_65 == 0x41 ) )
return - V_67 ;
V_63 = ( V_64 == 0x30 ) ? L_3 : L_4 ;
F_72 ( V_60 -> type , V_63 , V_68 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
const struct V_69 * V_64 )
{
struct V_10 * V_11 ;
int V_54 ;
V_11 = F_74 ( sizeof( struct V_10 ) , V_70 ) ;
if ( ! V_11 ) {
V_54 = - V_71 ;
goto exit;
}
F_75 ( V_2 , V_11 ) ;
V_11 -> V_38 = V_64 -> V_72 ;
F_76 ( & V_11 -> V_29 ) ;
if ( V_11 -> V_38 == V_73 )
V_11 -> V_17 = & V_74 ;
else
V_11 -> V_17 = & V_75 ;
F_77 ( V_2 ) ;
V_54 = F_78 ( & V_2 -> V_20 . V_76 , & V_77 ) ;
if ( V_54 )
goto V_78;
if ( V_11 -> V_38 == V_39 ) {
V_54 = F_78 ( & V_2 -> V_20 . V_76 , & V_79 ) ;
if ( V_54 )
goto V_80;
}
V_11 -> V_81 = F_79 ( & V_2 -> V_20 ) ;
if ( F_80 ( V_11 -> V_81 ) ) {
V_54 = F_81 ( V_11 -> V_81 ) ;
goto V_80;
}
return 0 ;
V_80:
F_82 ( & V_2 -> V_20 . V_76 , & V_77 ) ;
F_82 ( & V_2 -> V_20 . V_76 , & V_79 ) ;
V_78:
F_83 ( V_11 ) ;
exit:
return V_54 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_18 ( V_2 ) ;
F_85 ( V_11 -> V_81 ) ;
F_82 ( & V_2 -> V_20 . V_76 , & V_77 ) ;
F_82 ( & V_2 -> V_20 . V_76 , & V_79 ) ;
F_83 ( V_11 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
unsigned int V_82 ;
unsigned int V_83 ;
int V_13 ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
V_83 = ( V_84 | V_85 ) ;
if ( V_11 -> V_38 == V_39 ) {
V_83 |= ( V_86 |
V_87 ) ;
}
V_82 = F_1 ( V_2 , V_88 ) ;
if ( ( V_82 | V_83 ) != V_82 )
F_3 ( V_2 , V_88 , V_82 | V_83 ) ;
V_82 = F_1 ( V_2 , V_33 ) ;
if ( ( V_82 | V_89 ) != V_82 ) {
F_3 ( V_2 , V_33 ,
V_82 | V_89 ) ;
}
V_83 = V_57 ;
V_82 = F_1 ( V_2 , V_56 ) ;
V_13 = ( V_82 & V_83 ) >> V_58 ;
V_11 -> V_53 = V_55 [ V_13 ] ;
}
static struct V_10 * F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_17 ( V_20 ) ;
struct V_10 * V_11 = F_18 ( V_2 ) ;
unsigned long V_90 ;
int V_12 ;
F_20 ( & V_11 -> V_29 ) ;
V_90 = V_11 -> V_91
+ F_86 ( V_11 -> V_53 ) ;
if ( F_87 ( V_92 , V_90 ) || ! V_11 -> V_45 ) {
F_88 ( & V_2 -> V_20 , L_5 ) ;
for ( V_12 = 0 ;
V_12 < ( ( V_11 -> V_38 == V_39 ) ? 3 : 2 ) ; V_12 ++ ) {
T_1 V_93 , V_94 ;
V_93 =
F_1 ( V_2 , F_89 ( V_12 ) ) ;
V_11 -> V_47 [ V_12 ] =
F_1 ( V_2 , V_95 ) ;
V_94 =
F_1 ( V_2 , F_89 ( V_12 ) ) ;
if ( V_94 != V_93 ) {
V_11 -> V_47 [ V_12 ] =
F_1 ( V_2 ,
V_95 ) ;
#ifdef F_90
V_93 =
F_1 ( V_2 ,
F_89 ( V_12 ) ) ;
if ( V_94 != V_93 )
F_91 ( & V_2 -> V_20 ,
L_6 ) ;
#endif
}
V_11 -> V_37 [ V_12 ] = V_94 ;
V_11 -> V_48 [ V_12 ] =
F_1 ( V_2 ,
F_56 ( V_12 ) ) ;
V_11 -> V_49 [ V_12 ] =
F_1 ( V_2 ,
F_59 ( V_12 ) ) ;
V_11 -> V_35 [ V_12 ] =
F_1 ( V_2 ,
F_61 ( V_12 ) ) ;
V_11 -> V_50 [ V_12 ] =
F_1 ( V_2 ,
F_63 ( V_12 ) ) ;
V_11 -> V_34 [ V_12 ] =
F_1 ( V_2 ,
F_28 ( V_12 ) ) ;
}
V_11 -> V_28 = F_1 ( V_2 , V_33 ) ;
V_11 -> V_96 = F_1 ( V_2 , V_88 ) ;
V_11 -> V_51 = F_1 ( V_2 , F_92 ( 0 ) )
| ( F_1 ( V_2 , F_92 ( 1 ) ) << 8 ) ;
if ( V_11 -> V_38 == V_73 )
V_11 -> V_51 &= 0xc0ff ;
for ( V_12 = 0 ; V_12 < ( V_11 -> V_38 == V_73 ? 1 : 2 ) ;
V_12 ++ ) {
V_11 -> V_41 [ V_12 ] =
F_1 ( V_2 ,
F_45 ( V_12 ) ) ;
V_11 -> V_42 [ V_12 ] =
F_1 ( V_2 ,
F_43 ( V_12 ) ) ;
V_11 -> V_40 [ V_12 ] =
F_1 ( V_2 ,
F_93 ( V_12 ) ) ;
V_11 -> V_7 [ V_12 ] =
( F_1 ( V_2 ,
V_32 ) >> ( 4 * V_12 ) ) & 0x0f ;
}
V_11 -> V_91 = V_92 ;
V_11 -> V_45 = 1 ;
}
F_21 ( & V_11 -> V_29 ) ;
return V_11 ;
}
