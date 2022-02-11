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
F_3 ( L_1 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
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
. V_13 = V_16 ,
. V_5 = V_5 ,
. V_7 = V_4 ,
}
} ;
V_6 = F_2 ( V_2 -> V_14 , V_9 , 2 ) ;
if ( V_6 == 2 ) {
V_6 = 0 ;
} else {
F_3 ( L_2 , V_6 , V_3 , V_5 ) ;
V_6 = - V_15 ;
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
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_17 )
{
int V_6 ;
T_1 V_18 ;
if ( V_17 != 0xff ) {
V_6 = F_4 ( V_2 , V_3 , & V_18 , 1 ) ;
if ( V_6 )
return V_6 ;
V_4 &= V_17 ;
V_18 &= ~ V_17 ;
V_4 |= V_18 ;
}
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_17 )
{
int V_6 , V_19 ;
T_1 V_18 ;
V_6 = F_4 ( V_2 , V_3 , & V_18 , 1 ) ;
if ( V_6 )
return V_6 ;
V_18 &= V_17 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( ( V_17 >> V_19 ) & 0x01 )
break;
}
* V_4 = V_18 >> V_19 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_18 ;
V_6 = F_6 ( V_2 , 0x26 , & V_18 ) ;
if ( V_6 )
goto V_20;
V_6 = F_5 ( V_2 , 0x26 , 0x0d ) ;
if ( V_6 )
goto V_20;
F_10 ( 10000 , 20000 ) ;
V_6 = F_5 ( V_2 , 0x26 , V_18 ) ;
if ( V_6 )
goto V_20;
return 0 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_22 * V_23 , int V_24 )
{
int V_6 , V_19 ;
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_18 ;
F_11 ( L_4 , V_21 , V_24 ) ;
if ( ! V_2 -> V_26 && V_24 ) {
V_6 = F_5 ( V_2 , 0x9d , V_2 -> V_11 . V_27 << 1 ) ;
if ( V_6 )
goto V_20;
V_2 -> V_26 = true ;
}
V_6 = F_5 ( V_2 , 0x9f , V_24 ) ;
if ( V_6 )
goto V_20;
for ( V_19 = 10 ; V_19 ; V_19 -- ) {
V_6 = F_6 ( V_2 , 0x9e , & V_18 ) ;
if ( V_6 )
goto V_20;
if ( V_18 == V_24 )
break;
F_10 ( 5000 , 10000 ) ;
}
F_11 ( L_5 , V_21 , V_19 ) ;
return V_6 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static int F_13 ( struct V_22 * V_23 , T_2 * V_28 )
{
int V_6 ;
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_7 [ 2 ] ;
* V_28 = 0 ;
V_6 = F_6 ( V_2 , 0x05 , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_20;
if ( V_7 [ 0 ] & 0x01 ) {
* V_28 |= V_29 | V_30 | V_31 |
V_32 | V_33 ;
} else {
V_6 = F_6 ( V_2 , 0x0d , & V_7 [ 1 ] ) ;
if ( V_6 )
goto V_20;
if ( ( V_7 [ 1 ] & 0xfe ) == 0x78 )
* V_28 |= V_29 | V_30 |
V_31 | V_32 ;
}
V_2 -> V_34 = * V_28 ;
return 0 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_22 * V_23 , T_3 * V_35 )
{
int V_6 ;
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_7 [ 2 ] ;
T_3 V_18 ;
if ( ! ( V_2 -> V_34 & V_33 ) ) {
* V_35 = 0 ;
V_6 = 0 ;
goto V_20;
}
V_6 = F_4 ( V_2 , 0x0b , V_7 , 2 ) ;
if ( V_6 )
goto V_20;
V_18 = ( V_7 [ 0 ] << 8 ) | V_7 [ 1 ] ;
#define F_15 72422627
if ( V_18 )
* V_35 = ( F_15 - F_16 ( V_18 ) ) / ( ( 1 << 24 ) / 100 ) ;
else
* V_35 = 0 ;
return 0 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static int F_17 ( struct V_22 * V_23 , T_3 * V_36 )
{
int V_6 ;
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_7 [ 2 ] ;
T_3 V_18 ;
* V_36 = 0 ;
V_6 = F_4 ( V_2 , 0xd5 , V_7 , 2 ) ;
if ( V_6 )
goto V_20;
V_18 = V_7 [ 0 ] << 8 | V_7 [ 1 ] ;
V_18 = ~ V_18 & 0x0fff ;
* V_36 = V_18 * 0xffff / 0x0fff ;
return 0 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_22 * V_23 , T_4 * V_37 )
{
int V_6 ;
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_7 [ 2 ] ;
if ( ! ( V_2 -> V_34 & V_32 ) ) {
* V_37 = 0 ;
V_6 = 0 ;
goto V_20;
}
V_6 = F_4 ( V_2 , 0xd9 , V_7 , 2 ) ;
if ( V_6 ) {
* V_37 = 0 ;
goto V_20;
}
* V_37 = ( ( V_7 [ 0 ] & 0x0f ) << 8 ) | V_7 [ 1 ] ;
return 0 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static int F_19 ( struct V_22 * V_23 , T_4 * V_38 )
{
* V_38 = 0 ;
return 0 ;
}
static enum V_39 F_20 ( struct V_22 * V_23 )
{
int V_6 , V_19 ;
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_40 * V_41 = & V_23 -> V_42 ;
T_1 V_18 , V_7 [ 3 ] ;
T_1 V_43 , V_44 , V_45 , V_46 , V_47 ;
T_5 V_48 ;
T_4 V_49 , V_50 ;
bool V_51 ;
F_11 ( L_6 \
L_7 ,
V_21 ,
V_41 -> V_52 , V_41 -> V_53 , V_41 -> V_54 ,
V_41 -> V_43 , V_41 -> V_55 , V_41 -> V_56 , V_41 -> V_45 ) ;
V_51 = true ;
if ( V_23 -> V_57 . V_58 . V_59 )
V_23 -> V_57 . V_58 . V_59 ( V_23 ) ;
if ( V_23 -> V_57 . V_58 . V_60 )
V_23 -> V_57 . V_58 . V_60 ( V_23 , & V_49 ) ;
else
V_49 = 0 ;
if ( V_49 ) {
V_48 = V_49 ;
V_48 *= 0x800000 ;
V_48 = F_21 ( V_48 , V_61 ) ;
V_48 -= 0x800000 ;
V_50 = V_48 ;
V_18 = 0xfc ;
} else {
V_50 = 0 ;
V_18 = 0xfe ;
}
V_7 [ 0 ] = ( ( V_50 >> 0 ) & 0xff ) ;
V_7 [ 1 ] = ( ( V_50 >> 8 ) & 0xff ) ;
V_7 [ 2 ] = ( ( V_50 >> 16 ) & 0xff ) ;
V_6 = F_1 ( V_2 , 0x14 , V_7 , 3 ) ;
if ( V_6 )
goto V_20;
V_6 = F_5 ( V_2 , 0xab , V_18 ) ;
if ( V_6 )
goto V_20;
F_11 ( L_8 , V_21 , V_49 , V_50 ) ;
if ( V_51 ) {
V_6 = F_7 ( V_2 , 0xac , 0 << 7 , 0x80 ) ;
if ( V_6 )
goto V_20;
V_6 = F_7 ( V_2 , 0x82 , 1 << 1 , 0x02 ) ;
if ( V_6 )
goto V_20;
V_6 = F_7 ( V_2 , 0x7d , 1 << 6 , 0x40 ) ;
if ( V_6 )
goto V_20;
V_6 = F_7 ( V_2 , 0x81 , 1 << 3 , 0x08 ) ;
if ( V_6 )
goto V_20;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
goto V_20;
for ( V_19 = 30 ; V_19 ; V_19 -- ) {
F_22 ( 100 ) ;
V_6 = F_6 ( V_2 , 0x0d , & V_18 ) ;
if ( V_6 )
goto V_20;
if ( ( ( ( V_18 & 0xf0 ) >= 0x10 ) &&
( ( V_18 & 0x0f ) == 0x08 ) ) || ( V_18 >= 0x2c ) )
break;
}
F_11 ( L_5 , V_21 , V_19 ) ;
if ( V_19 == 0 )
return V_62 ;
V_6 = F_8 ( V_2 , 0x7d , & V_43 , 0x07 ) ;
if ( V_6 )
goto V_20;
} else {
V_43 = V_63 ;
V_44 = V_64 ;
V_45 = V_65 ;
V_46 = V_66 ;
V_47 = V_67 ;
V_18 = ( V_47 << 3 ) | V_43 ;
V_6 = F_7 ( V_2 , 0x7d , V_18 , 0x5f ) ;
if ( V_6 )
goto V_20;
V_18 = ( V_44 << 2 ) | V_45 ;
V_6 = F_7 ( V_2 , 0x81 , V_18 , 0x0f ) ;
if ( V_6 )
goto V_20;
V_18 = V_46 ;
V_6 = F_7 ( V_2 , 0x82 , V_18 , 0x03 ) ;
if ( V_6 )
goto V_20;
}
if ( V_43 > ( F_23 ( V_68 [ 0 ] . V_4 ) - 1 ) ) {
F_11 ( L_9 , V_21 , V_43 ) ;
goto V_20;
}
for ( V_19 = 0 ; V_19 < F_23 ( V_68 ) ; V_19 ++ ) {
V_6 = F_5 ( V_2 , V_68 [ V_19 ] . V_3 ,
V_68 [ V_19 ] . V_4 [ V_43 ] ) ;
if ( V_6 )
goto V_20;
}
V_6 = F_8 ( V_2 , 0x81 , & V_45 , 0x03 ) ;
if ( V_6 )
goto V_20;
V_6 = F_8 ( V_2 , 0x81 , & V_44 , 0x04 ) ;
if ( V_6 )
goto V_20;
F_11 ( L_10 ,
V_21 , V_43 , V_45 , V_44 ) ;
if ( ( V_44 == V_64 ) && ( V_43 == V_63 ) &&
( V_45 == V_65 ) ) {
F_11 ( L_11 , V_21 ) ;
V_6 = F_5 ( V_2 , 0x42 , 0x33 ) ;
if ( V_6 )
goto V_20;
V_6 = F_5 ( V_2 , 0xdd , 0x01 ) ;
if ( V_6 )
goto V_20;
}
F_10 ( 10000 , 20000 ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
goto V_20;
for ( V_19 = 30 ; V_19 ; V_19 -- ) {
F_22 ( 100 ) ;
V_6 = F_8 ( V_2 , 0x05 , & V_18 , 0x01 ) ;
if ( V_6 )
goto V_20;
if ( V_18 )
break;
}
F_11 ( L_5 , V_21 , V_19 ) ;
if ( V_19 == 0 )
return V_69 ;
return V_70 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_71 ;
}
static int F_24 ( struct V_22 * V_23 )
{
return V_72 ;
}
static int F_25 ( struct V_22 * V_23 )
{
int V_6 ;
struct V_1 * V_2 = V_23 -> V_25 ;
struct V_40 * V_41 = & V_23 -> V_42 ;
T_1 V_7 [ 3 ] ;
T_4 V_50 ;
char * V_73 , * V_74 , * V_75 ,
* V_76 , * V_77 , * V_78 ,
* V_79 , * V_80 ;
V_6 = F_6 ( V_2 , 0x7d , & V_7 [ 0 ] ) ;
if ( V_6 )
goto V_20;
V_6 = F_4 ( V_2 , 0x81 , & V_7 [ 1 ] , 2 ) ;
if ( V_6 )
goto V_20;
switch ( ( V_7 [ 0 ] >> 0 ) & 0x07 ) {
case 0 :
V_73 = L_12 ;
V_41 -> V_43 = V_81 ;
break;
case 1 :
V_73 = L_13 ;
V_41 -> V_43 = V_82 ;
break;
case 2 :
V_73 = L_14 ;
V_41 -> V_43 = V_83 ;
break;
case 3 :
V_73 = L_15 ;
V_41 -> V_43 = V_84 ;
break;
case 4 :
V_73 = L_16 ;
V_41 -> V_43 = V_85 ;
break;
default:
V_73 = L_17 ;
}
switch ( ( V_7 [ 0 ] >> 3 ) & 0x03 ) {
case 0 :
V_74 = L_18 ;
V_41 -> V_56 = V_86 ;
break;
case 1 :
V_74 = L_19 ;
V_41 -> V_56 = V_87 ;
break;
case 2 :
V_74 = L_20 ;
V_41 -> V_56 = V_88 ;
break;
default:
V_74 = L_17 ;
}
switch ( ( V_7 [ 0 ] >> 6 ) & 0x01 ) {
case 0 :
V_75 = L_21 ;
break;
case 1 :
V_75 = L_22 ;
break;
default:
V_75 = L_17 ;
}
switch ( ( V_7 [ 1 ] >> 0 ) & 0x03 ) {
case 0 :
V_76 = L_23 ;
V_41 -> V_45 = V_89 ;
break;
case 1 :
V_76 = L_24 ;
V_41 -> V_45 = V_89 ;
break;
case 2 :
V_76 = L_25 ;
V_41 -> V_45 = V_89 ;
break;
default:
V_76 = L_17 ;
}
switch ( ( V_7 [ 1 ] >> 2 ) & 0x01 ) {
case 0 :
V_77 = L_26 ;
break;
case 1 :
V_77 = L_27 ;
break;
default:
V_77 = L_17 ;
}
switch ( ( V_7 [ 1 ] >> 3 ) & 0x01 ) {
case 0 :
V_78 = L_21 ;
break;
case 1 :
V_78 = L_22 ;
break;
default:
V_78 = L_17 ;
}
switch ( ( V_7 [ 2 ] >> 0 ) & 0x01 ) {
case 0 :
V_79 = L_28 ;
break;
case 1 :
V_79 = L_29 ;
break;
default:
V_79 = L_17 ;
}
switch ( ( V_7 [ 2 ] >> 1 ) & 0x01 ) {
case 0 :
V_80 = L_21 ;
break;
case 1 :
V_80 = L_22 ;
break;
default:
V_80 = L_17 ;
}
V_6 = F_4 ( V_2 , 0xb1 , & V_7 [ 0 ] , 3 ) ;
if ( V_6 )
goto V_20;
V_50 = ( V_7 [ 0 ] << 16 ) | ( ( V_7 [ 1 ] - 7 ) << 8 ) | V_7 [ 2 ] ;
F_11 ( L_30 , V_21 ,
V_73 , V_74 , V_75 ,
V_76 , V_77 , V_78 ,
V_79 , V_80 , V_50 ) ;
return 0 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static int F_26 ( struct V_22 * V_23 )
{
int V_6 , V_19 ;
struct V_1 * V_2 = V_23 -> V_25 ;
T_1 V_18 ;
static const struct V_90 V_91 [] = {
{ 0x3a , 0x06 } ,
{ 0x3b , 0x03 } ,
{ 0x3c , 0x04 } ,
{ 0xaf , 0x06 } ,
{ 0xb0 , 0x1b } ,
{ 0x80 , 0x64 } ,
{ 0x10 , 0x38 } ,
} ;
F_11 ( L_31 , V_21 ) ;
if ( V_23 -> V_92 ) {
V_6 = V_23 -> V_92 ( V_23 , V_93 , 0 , 0 ) ;
if ( V_6 )
goto V_20;
V_2 -> V_26 = false ;
}
for ( V_19 = 0 ; V_19 < F_23 ( V_91 ) ; V_19 ++ ) {
V_6 = F_5 ( V_2 , V_91 [ V_19 ] . V_3 , V_91 [ V_19 ] . V_4 ) ;
if ( V_6 )
goto V_20;
}
V_6 = F_6 ( V_2 , 0x36 , & V_18 ) ;
if ( V_6 )
goto V_20;
V_18 &= 0x1b ;
V_18 |= V_2 -> V_11 . V_94 ;
V_6 = F_5 ( V_2 , 0x36 , V_18 ) ;
if ( V_6 )
goto V_20;
V_6 = F_6 ( V_2 , 0x31 , & V_18 ) ;
V_18 &= 0xef ;
if ( ! ( V_2 -> V_11 . V_94 >> 7 ) )
V_18 |= 0x10 ;
V_6 = F_5 ( V_2 , 0x31 , V_18 ) ;
if ( V_6 )
goto V_20;
return V_6 ;
V_20:
F_11 ( L_3 , V_21 , V_6 ) ;
return V_6 ;
}
static void F_27 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_25 ;
F_28 ( V_2 ) ;
}
struct V_22 * F_29 ( const struct V_95 * V_96 ,
struct V_97 * V_14 )
{
int V_6 ;
struct V_1 * V_2 = NULL ;
T_1 V_18 ;
V_2 = F_30 ( sizeof( struct V_1 ) , V_98 ) ;
if ( V_2 == NULL )
goto V_20;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_11 , V_96 , sizeof( struct V_95 ) ) ;
V_6 = F_6 ( V_2 , 0x00 , & V_18 ) ;
if ( V_6 )
goto V_20;
memcpy ( & V_2 -> V_23 . V_57 , & V_99 , sizeof( struct V_100 ) ) ;
V_2 -> V_23 . V_25 = V_2 ;
return & V_2 -> V_23 ;
V_20:
F_28 ( V_2 ) ;
return NULL ;
}
