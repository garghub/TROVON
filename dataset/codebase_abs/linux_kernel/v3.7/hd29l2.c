static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ 2 + V_5 ] ;
struct V_8 V_9 [ 1 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = sizeof( V_7 ) ,
. V_7 = V_7 ,
}
} ;
V_7 [ 0 ] = 0x00 ;
V_7 [ 1 ] = V_3 ;
memcpy ( & V_7 [ 2 ] , V_4 , V_5 ) ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 1 ) ;
if ( V_6 == 1 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 ,
L_1 ,
V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
T_1 V_7 [ 2 ] = { 0x00 , V_3 } ;
struct V_8 V_9 [ 2 ] = {
{
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = 0 ,
. V_5 = 2 ,
. V_7 = V_7 ,
} , {
. V_10 = V_2 -> V_11 . V_12 ,
. V_13 = V_18 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_3 ( & V_2 -> V_14 -> V_15 ,
L_2 ,
V_16 , V_6 , V_3 , V_5 ) ;
V_6 = - V_17 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_4 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_19 )
{
int V_6 ;
T_1 V_20 ;
if ( V_19 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_19 ;
V_20 &= ~ V_19 ;
V_4 |= V_20 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_19 )
{
int V_6 , V_21 ;
T_1 V_20 ;
V_6 = F_4 ( V_2 , V_3 , & V_20 , 1 ) ;
if ( V_6 )
return V_6 ;
V_20 &= V_19 ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
if ( ( V_19 >> V_21 ) & 0x01 )
break;
}
* V_4 = V_20 >> V_21 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_20 ;
V_6 = F_6 ( V_2 , 0x26 , & V_20 ) ;
if ( V_6 )
goto V_22;
V_6 = F_5 ( V_2 , 0x26 , 0x0d ) ;
if ( V_6 )
goto V_22;
F_10 ( 10000 , 20000 ) ;
V_6 = F_5 ( V_2 , 0x26 , V_20 ) ;
if ( V_6 )
goto V_22;
return 0 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_24 * V_25 , int V_26 )
{
int V_6 , V_21 ;
struct V_1 * V_2 = V_25 -> V_27 ;
T_1 V_20 ;
F_11 ( & V_2 -> V_14 -> V_15 , L_4 , V_23 , V_26 ) ;
if ( ! V_2 -> V_28 && V_26 ) {
V_6 = F_5 ( V_2 , 0x9d , V_2 -> V_11 . V_29 << 1 ) ;
if ( V_6 )
goto V_22;
V_2 -> V_28 = true ;
}
V_6 = F_5 ( V_2 , 0x9f , V_26 ) ;
if ( V_6 )
goto V_22;
for ( V_21 = 10 ; V_21 ; V_21 -- ) {
V_6 = F_6 ( V_2 , 0x9e , & V_20 ) ;
if ( V_6 )
goto V_22;
if ( V_20 == V_26 )
break;
F_10 ( 5000 , 10000 ) ;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_23 , V_21 ) ;
return V_6 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_24 * V_25 , T_2 * V_30 )
{
int V_6 ;
struct V_1 * V_2 = V_25 -> V_27 ;
T_1 V_7 [ 2 ] ;
* V_30 = 0 ;
V_6 = F_6 ( V_2 , 0x05 , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_22;
if ( V_7 [ 0 ] & 0x01 ) {
* V_30 |= V_31 | V_32 | V_33 |
V_34 | V_35 ;
} else {
V_6 = F_6 ( V_2 , 0x0d , & V_7 [ 1 ] ) ;
if ( V_6 )
goto V_22;
if ( ( V_7 [ 1 ] & 0xfe ) == 0x78 )
* V_30 |= V_31 | V_32 |
V_33 | V_34 ;
}
V_2 -> V_36 = * V_30 ;
return 0 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_24 * V_25 , T_3 * V_37 )
{
int V_6 ;
struct V_1 * V_2 = V_25 -> V_27 ;
T_1 V_7 [ 2 ] ;
T_3 V_20 ;
if ( ! ( V_2 -> V_36 & V_35 ) ) {
* V_37 = 0 ;
V_6 = 0 ;
goto V_22;
}
V_6 = F_4 ( V_2 , 0x0b , V_7 , 2 ) ;
if ( V_6 )
goto V_22;
V_20 = ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ;
#define F_15 72422627
if ( V_20 )
* V_37 = ( F_15 - F_16 ( V_20 ) ) / ( ( 1 << 24 ) / 100 ) ;
else
* V_37 = 0 ;
return 0 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_24 * V_25 , T_3 * V_38 )
{
int V_6 ;
struct V_1 * V_2 = V_25 -> V_27 ;
T_1 V_7 [ 2 ] ;
T_3 V_20 ;
* V_38 = 0 ;
V_6 = F_4 ( V_2 , 0xd5 , V_7 , 2 ) ;
if ( V_6 )
goto V_22;
V_20 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
V_20 = ~ V_20 & 0x0fff ;
* V_38 = V_20 * 0xffff / 0x0fff ;
return 0 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_24 * V_25 , T_4 * V_39 )
{
int V_6 ;
struct V_1 * V_2 = V_25 -> V_27 ;
T_1 V_7 [ 2 ] ;
if ( ! ( V_2 -> V_36 & V_34 ) ) {
* V_39 = 0 ;
V_6 = 0 ;
goto V_22;
}
V_6 = F_4 ( V_2 , 0xd9 , V_7 , 2 ) ;
if ( V_6 ) {
* V_39 = 0 ;
goto V_22;
}
* V_39 = ( ( V_7 [ 0 ] & 0x0f ) << 8 ) | V_7 [ 1 ] ;
return 0 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_24 * V_25 , T_4 * V_40 )
{
* V_40 = 0 ;
return 0 ;
}
static enum V_41 F_20 ( struct V_24 * V_25 )
{
int V_6 , V_21 ;
struct V_1 * V_2 = V_25 -> V_27 ;
struct V_42 * V_43 = & V_25 -> V_44 ;
T_1 V_20 , V_7 [ 3 ] ;
T_1 V_45 , V_46 , V_47 , V_48 , V_49 ;
T_5 V_50 ;
T_4 V_51 , V_52 ;
bool V_53 ;
F_11 ( & V_2 -> V_14 -> V_15 , L_6 \
L_7 \
L_8 , V_23 ,
V_43 -> V_54 , V_43 -> V_55 , V_43 -> V_56 ,
V_43 -> V_45 , V_43 -> V_57 , V_43 -> V_58 ,
V_43 -> V_47 ) ;
V_53 = true ;
if ( V_25 -> V_59 . V_60 . V_61 )
V_25 -> V_59 . V_60 . V_61 ( V_25 ) ;
if ( V_25 -> V_59 . V_60 . V_62 )
V_25 -> V_59 . V_60 . V_62 ( V_25 , & V_51 ) ;
else
V_51 = 0 ;
if ( V_51 ) {
V_50 = V_51 ;
V_50 *= 0x800000 ;
V_50 = F_21 ( V_50 , V_63 ) ;
V_50 -= 0x800000 ;
V_52 = V_50 ;
V_20 = 0xfc ;
} else {
V_52 = 0 ;
V_20 = 0xfe ;
}
V_7 [ 0 ] = ( ( V_52 >> 0 ) & 0xff ) ;
V_7 [ 1 ] = ( ( V_52 >> 8 ) & 0xff ) ;
V_7 [ 2 ] = ( ( V_52 >> 16 ) & 0xff ) ;
V_6 = F_1 ( V_2 , 0x14 , V_7 , 3 ) ;
if ( V_6 )
goto V_22;
V_6 = F_5 ( V_2 , 0xab , V_20 ) ;
if ( V_6 )
goto V_22;
F_11 ( & V_2 -> V_14 -> V_15 , L_9 ,
V_23 , V_51 , V_52 ) ;
if ( V_53 ) {
V_6 = F_7 ( V_2 , 0xac , 0 << 7 , 0x80 ) ;
if ( V_6 )
goto V_22;
V_6 = F_7 ( V_2 , 0x82 , 1 << 1 , 0x02 ) ;
if ( V_6 )
goto V_22;
V_6 = F_7 ( V_2 , 0x7d , 1 << 6 , 0x40 ) ;
if ( V_6 )
goto V_22;
V_6 = F_7 ( V_2 , 0x81 , 1 << 3 , 0x08 ) ;
if ( V_6 )
goto V_22;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
goto V_22;
for ( V_21 = 30 ; V_21 ; V_21 -- ) {
F_22 ( 100 ) ;
V_6 = F_6 ( V_2 , 0x0d , & V_20 ) ;
if ( V_6 )
goto V_22;
if ( ( ( ( V_20 & 0xf0 ) >= 0x10 ) &&
( ( V_20 & 0x0f ) == 0x08 ) ) || ( V_20 >= 0x2c ) )
break;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_23 , V_21 ) ;
if ( V_21 == 0 )
return V_64 ;
V_6 = F_8 ( V_2 , 0x7d , & V_45 , 0x07 ) ;
if ( V_6 )
goto V_22;
} else {
V_45 = V_65 ;
V_46 = V_66 ;
V_47 = V_67 ;
V_48 = V_68 ;
V_49 = V_69 ;
V_20 = ( V_49 << 3 ) | V_45 ;
V_6 = F_7 ( V_2 , 0x7d , V_20 , 0x5f ) ;
if ( V_6 )
goto V_22;
V_20 = ( V_46 << 2 ) | V_47 ;
V_6 = F_7 ( V_2 , 0x81 , V_20 , 0x0f ) ;
if ( V_6 )
goto V_22;
V_20 = V_48 ;
V_6 = F_7 ( V_2 , 0x82 , V_20 , 0x03 ) ;
if ( V_6 )
goto V_22;
}
if ( V_45 > ( F_23 ( V_70 [ 0 ] . V_4 ) - 1 ) ) {
F_11 ( & V_2 -> V_14 -> V_15 , L_10 ,
V_23 , V_45 ) ;
goto V_22;
}
for ( V_21 = 0 ; V_21 < F_23 ( V_70 ) ; V_21 ++ ) {
V_6 = F_5 ( V_2 , V_70 [ V_21 ] . V_3 ,
V_70 [ V_21 ] . V_4 [ V_45 ] ) ;
if ( V_6 )
goto V_22;
}
V_6 = F_8 ( V_2 , 0x81 , & V_47 , 0x03 ) ;
if ( V_6 )
goto V_22;
V_6 = F_8 ( V_2 , 0x81 , & V_46 , 0x04 ) ;
if ( V_6 )
goto V_22;
F_11 ( & V_2 -> V_14 -> V_15 ,
L_11 ,
V_23 , V_45 , V_47 , V_46 ) ;
if ( ( V_46 == V_66 ) && ( V_45 == V_65 ) &&
( V_47 == V_67 ) ) {
F_11 ( & V_2 -> V_14 -> V_15 , L_12 ,
V_23 ) ;
V_6 = F_5 ( V_2 , 0x42 , 0x33 ) ;
if ( V_6 )
goto V_22;
V_6 = F_5 ( V_2 , 0xdd , 0x01 ) ;
if ( V_6 )
goto V_22;
}
F_10 ( 10000 , 20000 ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
goto V_22;
for ( V_21 = 30 ; V_21 ; V_21 -- ) {
F_22 ( 100 ) ;
V_6 = F_8 ( V_2 , 0x05 , & V_20 , 0x01 ) ;
if ( V_6 )
goto V_22;
if ( V_20 )
break;
}
F_11 ( & V_2 -> V_14 -> V_15 , L_5 , V_23 , V_21 ) ;
if ( V_21 == 0 )
return V_71 ;
return V_72 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_73 ;
}
static int F_24 ( struct V_24 * V_25 )
{
return V_74 ;
}
static int F_25 ( struct V_24 * V_25 )
{
int V_6 ;
struct V_1 * V_2 = V_25 -> V_27 ;
struct V_42 * V_43 = & V_25 -> V_44 ;
T_1 V_7 [ 3 ] ;
T_4 V_52 ;
char * V_75 , * V_76 , * V_77 ,
* V_78 , * V_79 , * V_80 ,
* V_81 , * V_82 ;
V_6 = F_6 ( V_2 , 0x7d , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_22;
V_6 = F_4 ( V_2 , 0x81 , & V_7 [ 1 ] , 2 ) ;
if ( V_6 )
goto V_22;
switch ( ( V_7 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_75 = L_13 ;
V_43 -> V_45 = V_83 ;
break;
case 1 :
V_75 = L_14 ;
V_43 -> V_45 = V_84 ;
break;
case 2 :
V_75 = L_15 ;
V_43 -> V_45 = V_85 ;
break;
case 3 :
V_75 = L_16 ;
V_43 -> V_45 = V_86 ;
break;
case 4 :
V_75 = L_17 ;
V_43 -> V_45 = V_87 ;
break;
default:
V_75 = L_18 ;
}
switch ( ( V_7 [ 0 ] >> 3 ) & 0x03 ) {
case 0 :
V_76 = L_19 ;
V_43 -> V_58 = V_88 ;
break;
case 1 :
V_76 = L_20 ;
V_43 -> V_58 = V_89 ;
break;
case 2 :
V_76 = L_21 ;
V_43 -> V_58 = V_90 ;
break;
default:
V_76 = L_18 ;
}
switch ( ( V_7 [ 0 ] >> 6 ) & 0x01 ) {
case 0 :
V_77 = L_22 ;
break;
case 1 :
V_77 = L_23 ;
break;
default:
V_77 = L_18 ;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 0x03 ) {
case 0 :
V_78 = L_24 ;
V_43 -> V_47 = V_91 ;
break;
case 1 :
V_78 = L_25 ;
V_43 -> V_47 = V_91 ;
break;
case 2 :
V_78 = L_26 ;
V_43 -> V_47 = V_91 ;
break;
default:
V_78 = L_18 ;
}
switch ( ( V_7 [ 1 ] >> 2 ) & 0x01 ) {
case 0 :
V_79 = L_27 ;
break;
case 1 :
V_79 = L_28 ;
break;
default:
V_79 = L_18 ;
}
switch ( ( V_7 [ 1 ] >> 3 ) & 0x01 ) {
case 0 :
V_80 = L_22 ;
break;
case 1 :
V_80 = L_23 ;
break;
default:
V_80 = L_18 ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 0x01 ) {
case 0 :
V_81 = L_29 ;
break;
case 1 :
V_81 = L_30 ;
break;
default:
V_81 = L_18 ;
}
switch ( ( V_7 [ 2 ] >> 1 ) & 0x01 ) {
case 0 :
V_82 = L_22 ;
break;
case 1 :
V_82 = L_23 ;
break;
default:
V_82 = L_18 ;
}
V_6 = F_4 ( V_2 , 0xb1 , & V_7 [ 0 ] , 3 ) ;
if ( V_6 )
goto V_22;
V_52 = ( V_7 [ 0 ] << 16 ) | ( ( V_7 [ 1 ] - 7 ) << 8 ) | V_7 [ 2 ] ;
F_11 ( & V_2 -> V_14 -> V_15 , L_31 ,
V_23 , V_75 , V_76 ,
V_77 , V_78 ,
V_79 , V_80 , V_81 ,
V_82 , V_52 ) ;
return 0 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_24 * V_25 )
{
int V_6 , V_21 ;
struct V_1 * V_2 = V_25 -> V_27 ;
T_1 V_20 ;
static const struct V_92 V_93 [] = {
{ 0x3a , 0x06 } ,
{ 0x3b , 0x03 } ,
{ 0x3c , 0x04 } ,
{ 0xaf , 0x06 } ,
{ 0xb0 , 0x1b } ,
{ 0x80 , 0x64 } ,
{ 0x10 , 0x38 } ,
} ;
F_11 ( & V_2 -> V_14 -> V_15 , L_32 , V_23 ) ;
if ( V_25 -> V_94 ) {
V_6 = V_25 -> V_94 ( V_25 , V_95 , 0 , 0 ) ;
if ( V_6 )
goto V_22;
V_2 -> V_28 = false ;
}
for ( V_21 = 0 ; V_21 < F_23 ( V_93 ) ; V_21 ++ ) {
V_6 = F_5 ( V_2 , V_93 [ V_21 ] . V_3 , V_93 [ V_21 ] . V_4 ) ;
if ( V_6 )
goto V_22;
}
V_6 = F_6 ( V_2 , 0x36 , & V_20 ) ;
if ( V_6 )
goto V_22;
V_20 &= 0x1b ;
V_20 |= V_2 -> V_11 . V_96 ;
V_6 = F_5 ( V_2 , 0x36 , V_20 ) ;
if ( V_6 )
goto V_22;
V_6 = F_6 ( V_2 , 0x31 , & V_20 ) ;
V_20 &= 0xef ;
if ( ! ( V_2 -> V_11 . V_96 >> 7 ) )
V_20 |= 0x10 ;
V_6 = F_5 ( V_2 , 0x31 , V_20 ) ;
if ( V_6 )
goto V_22;
return V_6 ;
V_22:
F_11 ( & V_2 -> V_14 -> V_15 , L_3 , V_23 , V_6 ) ;
return V_6 ;
}
static void F_27 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
F_28 ( V_2 ) ;
}
struct V_24 * F_29 ( const struct V_97 * V_98 ,
struct V_99 * V_14 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_20 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_100 ) ;
if ( V_2 == NULL )
goto V_22;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_98 , sizeof( struct V_97 ) ) ;
V_6 = F_6 ( V_2 , 0x00 , & V_20 ) ;
if ( V_6 )
goto V_22;
memcpy ( & V_2 -> V_25 . V_59 , & V_101 , sizeof( struct V_102 ) ) ;
V_2 -> V_25 . V_27 = V_2 ;
return & V_2 -> V_25 ;
V_22:
F_28 ( V_2 ) ;
return NULL ;
}
