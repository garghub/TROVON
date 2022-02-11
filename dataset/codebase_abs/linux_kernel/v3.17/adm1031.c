static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline int
F_3 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static struct V_5 * F_5 ( struct V_6 * V_7 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_9 ;
int V_10 ;
F_7 ( & V_8 -> V_11 ) ;
V_9 = V_8 -> V_12
+ F_8 ( V_8 -> V_13 ) ;
if ( F_9 ( V_14 , V_9 ) || ! V_8 -> V_15 ) {
F_10 ( & V_2 -> V_7 , L_1 ) ;
for ( V_10 = 0 ;
V_10 < ( ( V_8 -> V_16 == V_17 ) ? 3 : 2 ) ; V_10 ++ ) {
T_1 V_18 , V_19 ;
V_18 =
F_1 ( V_2 , F_11 ( V_10 ) ) ;
V_8 -> V_20 [ V_10 ] =
F_1 ( V_2 , V_21 ) ;
V_19 =
F_1 ( V_2 , F_11 ( V_10 ) ) ;
if ( V_19 != V_18 ) {
V_8 -> V_20 [ V_10 ] =
F_1 ( V_2 ,
V_21 ) ;
#ifdef F_12
V_18 =
F_1 ( V_2 ,
F_11 ( V_10 ) ) ;
if ( V_19 != V_18 )
F_13 ( & V_2 -> V_7 ,
L_2 ) ;
#endif
}
V_8 -> V_22 [ V_10 ] = V_19 ;
V_8 -> V_23 [ V_10 ] =
F_1 ( V_2 ,
F_14 ( V_10 ) ) ;
V_8 -> V_24 [ V_10 ] =
F_1 ( V_2 ,
F_15 ( V_10 ) ) ;
V_8 -> V_25 [ V_10 ] =
F_1 ( V_2 ,
F_16 ( V_10 ) ) ;
V_8 -> V_26 [ V_10 ] =
F_1 ( V_2 ,
F_17 ( V_10 ) ) ;
V_8 -> V_27 [ V_10 ] =
F_1 ( V_2 ,
F_18 ( V_10 ) ) ;
}
V_8 -> V_28 = F_1 ( V_2 , V_29 ) ;
V_8 -> V_30 = F_1 ( V_2 , V_31 ) ;
V_8 -> V_32 = F_1 ( V_2 , F_19 ( 0 ) )
| ( F_1 ( V_2 , F_19 ( 1 ) ) << 8 ) ;
if ( V_8 -> V_16 == V_33 )
V_8 -> V_32 &= 0xc0ff ;
for ( V_10 = 0 ; V_10 < ( V_8 -> V_16 == V_33 ? 1 : 2 ) ;
V_10 ++ ) {
V_8 -> V_34 [ V_10 ] =
F_1 ( V_2 ,
F_20 ( V_10 ) ) ;
V_8 -> V_35 [ V_10 ] =
F_1 ( V_2 ,
F_21 ( V_10 ) ) ;
V_8 -> V_36 [ V_10 ] =
F_1 ( V_2 ,
F_22 ( V_10 ) ) ;
V_8 -> V_37 [ V_10 ] =
( F_1 ( V_2 ,
V_38 ) >> ( 4 * V_10 ) ) & 0x0f ;
}
V_8 -> V_12 = V_14 ;
V_8 -> V_15 = 1 ;
}
F_23 ( & V_8 -> V_11 ) ;
return V_8 ;
}
static int F_24 ( int V_3 , int div )
{
int V_39 ;
V_39 = F_25 ( F_26 ( V_3 , 0 , 65535 ) , div ) ;
return V_39 > 255 ? 255 : V_39 ;
}
static int F_27 ( int V_40 , int V_3 , int V_37 )
{
int V_41 ;
int V_42 = V_40 - F_28 ( V_3 ) ;
V_42 = ( ( V_40 - F_28 ( V_3 ) ) * 10 ) / ( 16 - V_37 ) ;
V_41 = ( ( V_3 & 0xf8 ) |
( V_42 < 10000 ? 0 :
V_42 < 20000 ? 1 :
V_42 < 40000 ? 2 : V_42 < 80000 ? 3 : 4 ) ) ;
return V_41 ;
}
static int
F_29 ( struct V_5 * V_8 , int V_10 , T_1 V_40 , T_1 V_3 )
{
int V_43 ;
int V_44 = - 1 , V_45 = - 1 ;
T_1 V_46 =
( * V_8 -> V_47 ) [ F_30 ( V_3 ) ] [ V_10 ? 0 : 1 ] ;
if ( V_40 == 0 )
return 0 ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
if ( ( V_40 == ( * V_8 -> V_47 ) [ V_43 ] [ V_10 ] ) &&
( ( * V_8 -> V_47 ) [ V_43 ] [ V_10 ? 0 : 1 ] ==
V_46 ) ) {
V_45 = V_43 ;
break;
} else if ( V_40 == ( * V_8 -> V_47 ) [ V_43 ] [ V_10 ] &&
V_44 == - 1 ) {
V_44 = V_43 ;
}
}
if ( V_45 >= 0 )
return V_45 ;
else if ( V_44 >= 0 )
return V_44 ;
return - V_48 ;
}
static T_2 F_31 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , F_33 ( V_8 , V_52 ) ) ;
}
static T_2
F_34 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
T_1 V_3 ;
int V_41 ;
T_1 V_55 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_55 = V_8 -> V_28 ;
F_7 ( & V_8 -> V_11 ) ;
V_41 = F_29 ( V_8 , V_52 , V_40 , V_8 -> V_28 ) ;
if ( V_41 < 0 ) {
F_23 ( & V_8 -> V_11 ) ;
return V_41 ;
}
V_3 = V_41 ;
V_8 -> V_28 = F_36 ( V_3 , V_8 -> V_28 ) ;
if ( ( V_8 -> V_28 & V_56 ) ^
( V_55 & V_56 ) ) {
if ( V_8 -> V_28 & V_56 ) {
V_8 -> V_57 [ 0 ] = V_8 -> V_37 [ 0 ] ;
V_8 -> V_57 [ 1 ] = V_8 -> V_37 [ 1 ] ;
F_3 ( V_2 , V_38 , 0x55 ) ;
} else {
V_8 -> V_37 [ 0 ] = V_8 -> V_57 [ 0 ] ;
V_8 -> V_37 [ 1 ] = V_8 -> V_57 [ 1 ] ;
F_3 ( V_2 , V_38 ,
V_8 -> V_37 [ 0 ] | ( V_8 -> V_37 [ 1 ] << 4 ) ) ;
}
}
V_8 -> V_28 = F_36 ( V_3 , V_8 -> V_28 ) ;
F_3 ( V_2 , V_29 , V_8 -> V_28 ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_37 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 ,
F_38 ( V_8 -> V_27 [ V_52 ] ) ) ;
}
static T_2 F_39 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 ,
F_28 ( V_8 -> V_27 [ V_52 ] ) ) ;
}
static T_2
F_40 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_40 = F_26 ( V_40 , 0 , 127000 ) ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_27 [ V_52 ] = F_41 ( V_40 , V_8 -> V_27 [ V_52 ] ) ;
F_3 ( V_2 , F_18 ( V_52 ) ,
V_8 -> V_27 [ V_52 ] ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_42 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 ,
F_43 ( V_8 -> V_27 [ V_52 ] ) ) ;
}
static T_2
F_44 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_40 = F_26 ( V_40 , 0 , 127000 ) ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_25 [ V_52 ] = F_27 ( V_40 , V_8 -> V_27 [ V_52 ] ,
V_8 -> V_37 [ V_52 ] ) ;
F_3 ( V_2 , F_18 ( V_52 ) ,
V_8 -> V_25 [ V_52 ] ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_45 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , F_46 ( V_8 -> V_37 [ V_52 ] ) ) ;
}
static T_2 F_47 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 , V_3 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
F_7 ( & V_8 -> V_11 ) ;
if ( ( V_8 -> V_28 & V_56 ) &&
( ( ( V_40 >> 4 ) & 0xf ) != 5 ) ) {
F_23 ( & V_8 -> V_11 ) ;
return - V_48 ;
}
V_8 -> V_37 [ V_52 ] = F_48 ( V_40 ) ;
V_3 = F_1 ( V_2 , V_38 ) ;
F_3 ( V_2 , V_38 ,
V_52 ? ( ( V_8 -> V_37 [ V_52 ] << 4 ) & 0xf0 ) | ( V_3 & 0xf )
: ( V_8 -> V_37 [ V_52 ] & 0xf ) | ( V_3 & 0xf0 ) ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static int F_49 ( struct V_5 * V_8 , int V_10 )
{
int V_58 = 0 ;
if ( V_8 -> V_28 & V_56 ) {
switch ( V_8 -> V_28 & 0x60 ) {
case 0x00 :
V_58 = V_8 -> V_22 [ V_10 + 1 ] >=
F_50 ( V_8 -> V_27 [ V_10 + 1 ] ) ;
break;
case 0x20 :
V_58 =
V_8 -> V_22 [ 1 ] >=
F_50 ( V_8 -> V_27 [ 1 ] ) ;
break;
case 0x40 :
V_58 =
V_8 -> V_22 [ 2 ] >=
F_50 ( V_8 -> V_27 [ 2 ] ) ;
break;
case 0x60 :
V_58 =
V_8 -> V_22 [ 0 ] >=
F_50 ( V_8 -> V_27 [ 0 ] )
|| V_8 -> V_22 [ 1 ] >=
F_50 ( V_8 -> V_27 [ 1 ] )
|| ( V_8 -> V_16 == V_17
&& V_8 -> V_22 [ 2 ] >=
F_50 ( V_8 -> V_27 [ 2 ] ) ) ;
break;
}
} else {
V_58 = V_8 -> V_37 [ V_10 ] > 0 ;
}
return V_58 ;
}
static T_2 F_51 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_4 ;
V_4 = F_49 ( V_8 , V_52 ) ? F_25 ( V_8 -> V_36 [ V_52 ] ,
F_52 ( V_8 -> V_34 [ V_52 ] ) ) : 0 ;
return sprintf ( V_51 , L_3 , V_4 ) ;
}
static T_2 F_53 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , F_52 ( V_8 -> V_34 [ V_52 ] ) ) ;
}
static T_2 F_54 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 ,
F_25 ( V_8 -> V_35 [ V_52 ] ,
F_52 ( V_8 -> V_34 [ V_52 ] ) ) ) ;
}
static T_2 F_55 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
F_7 ( & V_8 -> V_11 ) ;
if ( V_40 ) {
V_8 -> V_35 [ V_52 ] =
F_24 ( V_40 , F_52 ( V_8 -> V_34 [ V_52 ] ) ) ;
} else {
V_8 -> V_35 [ V_52 ] = 0xff ;
}
F_3 ( V_2 , F_21 ( V_52 ) , V_8 -> V_35 [ V_52 ] ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_56 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
T_1 V_39 ;
int V_59 ;
int V_60 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_39 = V_40 == 8 ? 0xc0 :
V_40 == 4 ? 0x80 :
V_40 == 2 ? 0x40 :
V_40 == 1 ? 0x00 :
0xff ;
if ( V_39 == 0xff )
return - V_48 ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_34 [ V_52 ] = F_1 ( V_2 ,
F_20 ( V_52 ) ) ;
V_8 -> V_35 [ V_52 ] = F_1 ( V_2 ,
F_21 ( V_52 ) ) ;
V_59 = F_52 ( V_8 -> V_34 [ V_52 ] ) ;
V_8 -> V_34 [ V_52 ] = V_39 | ( 0x3f & V_8 -> V_34 [ V_52 ] ) ;
V_60 = V_8 -> V_35 [ V_52 ] * V_59 / V_40 ;
V_8 -> V_35 [ V_52 ] = V_60 > 0xff ? 0xff : V_60 ;
F_3 ( V_2 , F_20 ( V_52 ) ,
V_8 -> V_34 [ V_52 ] ) ;
F_3 ( V_2 , F_21 ( V_52 ) ,
V_8 -> V_35 [ V_52 ] ) ;
V_8 -> V_15 = 0 ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_57 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
int V_61 ;
V_61 = V_52 == 0 ?
( ( V_8 -> V_20 [ V_52 ] >> 6 ) & 0x3 ) * 2 :
( ( ( V_8 -> V_20 [ V_52 ] >> ( ( V_52 - 1 ) * 3 ) ) & 7 ) ) ;
return sprintf ( V_51 , L_3 , F_58 ( V_8 -> V_22 [ V_52 ] , V_61 ) ) ;
}
static T_2 F_59 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 ,
F_60 ( V_8 -> V_23 [ V_52 ] ) ) ;
}
static T_2 F_61 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , F_62 ( V_8 -> V_24 [ V_52 ] ) ) ;
}
static T_2 F_63 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , F_62 ( V_8 -> V_25 [ V_52 ] ) ) ;
}
static T_2 F_64 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_52 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , F_62 ( V_8 -> V_26 [ V_52 ] ) ) ;
}
static T_2 F_65 ( struct V_6 * V_7 ,
struct V_49 * V_50 , const char * V_51 ,
T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_40 = F_26 ( V_40 , - 15000 , 15000 ) ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_23 [ V_52 ] = F_66 ( V_40 ) ;
F_3 ( V_2 , F_14 ( V_52 ) ,
V_8 -> V_23 [ V_52 ] ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_67 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_40 = F_26 ( V_40 , - 55000 , 127000 ) ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_24 [ V_52 ] = F_68 ( V_40 ) ;
F_3 ( V_2 , F_15 ( V_52 ) ,
V_8 -> V_24 [ V_52 ] ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_69 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_40 = F_26 ( V_40 , - 55000 , 127000 ) ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_25 [ V_52 ] = F_68 ( V_40 ) ;
F_3 ( V_2 , F_16 ( V_52 ) ,
V_8 -> V_25 [ V_52 ] ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_70 ( struct V_6 * V_7 , struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_52 = F_32 ( V_50 ) -> V_53 ;
long V_40 ;
int V_41 ;
V_41 = F_35 ( V_51 , 10 , & V_40 ) ;
if ( V_41 )
return V_41 ;
V_40 = F_26 ( V_40 , - 55000 , 127000 ) ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_26 [ V_52 ] = F_68 ( V_40 ) ;
F_3 ( V_2 , F_17 ( V_52 ) ,
V_8 -> V_26 [ V_52 ] ) ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static T_2 F_71 ( struct V_6 * V_7 , struct V_49 * V_50 ,
char * V_51 )
{
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , V_8 -> V_32 ) ;
}
static T_2 F_72 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
int V_62 = F_32 ( V_50 ) -> V_53 ;
struct V_5 * V_8 = F_5 ( V_7 ) ;
return sprintf ( V_51 , L_3 , ( V_8 -> V_32 >> V_62 ) & 1 ) ;
}
static T_2 F_73 ( struct V_6 * V_7 ,
struct V_49 * V_50 , char * V_51 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
return sprintf ( V_51 , L_4 , V_8 -> V_13 ) ;
}
static T_2 F_74 ( struct V_6 * V_7 ,
struct V_49 * V_50 ,
const char * V_51 , T_3 V_54 )
{
struct V_5 * V_8 = F_6 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_40 ;
int V_43 , V_63 ;
T_1 V_3 ;
V_63 = F_75 ( V_51 , 10 , & V_40 ) ;
if ( V_63 )
return V_63 ;
for ( V_43 = 0 ; V_43 < F_76 ( V_64 ) - 1 ; V_43 ++ ) {
if ( V_40 >= V_64 [ V_43 ] )
break;
}
V_3 = F_1 ( V_2 , V_65 ) ;
V_3 &= ~ V_66 ;
V_3 |= V_43 << V_67 ;
F_3 ( V_2 , V_65 , V_3 ) ;
F_7 ( & V_8 -> V_11 ) ;
V_8 -> V_13 = V_64 [ V_43 ] ;
F_23 ( & V_8 -> V_11 ) ;
return V_54 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 = V_2 -> V_71 ;
const char * V_72 ;
int V_73 , V_74 ;
if ( ! F_78 ( V_71 , V_75 ) )
return - V_76 ;
V_73 = F_2 ( V_2 , 0x3d ) ;
V_74 = F_2 ( V_2 , 0x3e ) ;
if ( ! ( ( V_73 == 0x31 || V_73 == 0x30 ) && V_74 == 0x41 ) )
return - V_76 ;
V_72 = ( V_73 == 0x30 ) ? L_5 : L_6 ;
F_79 ( V_69 -> type , V_72 , V_77 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
unsigned int V_78 ;
unsigned int V_79 ;
int V_43 ;
struct V_5 * V_8 = F_81 ( V_2 ) ;
V_79 = ( V_80 | V_81 ) ;
if ( V_8 -> V_16 == V_17 ) {
V_79 |= ( V_82 |
V_83 ) ;
}
V_78 = F_1 ( V_2 , V_31 ) ;
if ( ( V_78 | V_79 ) != V_78 )
F_3 ( V_2 , V_31 , V_78 | V_79 ) ;
V_78 = F_1 ( V_2 , V_29 ) ;
if ( ( V_78 | V_84 ) != V_78 ) {
F_3 ( V_2 , V_29 ,
V_78 | V_84 ) ;
}
V_79 = V_66 ;
V_78 = F_1 ( V_2 , V_65 ) ;
V_43 = ( V_78 & V_79 ) >> V_67 ;
V_8 -> V_13 = V_64 [ V_43 ] ;
}
static int F_82 ( struct V_1 * V_2 ,
const struct V_85 * V_73 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_6 * V_86 ;
struct V_5 * V_8 ;
V_8 = F_83 ( V_7 , sizeof( struct V_5 ) , V_87 ) ;
if ( ! V_8 )
return - V_88 ;
F_84 ( V_2 , V_8 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_16 = V_73 -> V_89 ;
F_85 ( & V_8 -> V_11 ) ;
if ( V_8 -> V_16 == V_33 )
V_8 -> V_47 = & V_90 ;
else
V_8 -> V_47 = & V_91 ;
F_80 ( V_2 ) ;
V_8 -> V_92 [ 0 ] = & V_93 ;
if ( V_8 -> V_16 == V_17 )
V_8 -> V_92 [ 1 ] = & V_94 ;
V_86 = F_86 ( V_7 , V_2 -> V_72 ,
V_8 , V_8 -> V_92 ) ;
return F_87 ( V_86 ) ;
}
