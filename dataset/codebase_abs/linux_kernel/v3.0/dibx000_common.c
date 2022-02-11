static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
V_2 -> V_5 [ 0 ] = ( V_3 >> 8 ) & 0xff ;
V_2 -> V_5 [ 1 ] = V_3 & 0xff ;
V_2 -> V_5 [ 2 ] = ( V_4 >> 8 ) & 0xff ;
V_2 -> V_5 [ 3 ] = V_4 & 0xff ;
memset ( V_2 -> V_6 , 0 , sizeof( struct V_7 ) ) ;
V_2 -> V_6 [ 0 ] . V_8 = V_2 -> V_9 ;
V_2 -> V_6 [ 0 ] . V_10 = 0 ;
V_2 -> V_6 [ 0 ] . V_11 = V_2 -> V_5 ;
V_2 -> V_6 [ 0 ] . V_12 = 4 ;
return F_2 ( V_2 -> V_13 , V_2 -> V_6 , 1 ) != 1 ? - V_14 : 0 ;
}
static T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_5 [ 0 ] = V_3 >> 8 ;
V_2 -> V_5 [ 1 ] = V_3 & 0xff ;
memset ( V_2 -> V_6 , 0 , 2 * sizeof( struct V_7 ) ) ;
V_2 -> V_6 [ 0 ] . V_8 = V_2 -> V_9 ;
V_2 -> V_6 [ 0 ] . V_10 = 0 ;
V_2 -> V_6 [ 0 ] . V_11 = V_2 -> V_5 ;
V_2 -> V_6 [ 0 ] . V_12 = 2 ;
V_2 -> V_6 [ 1 ] . V_8 = V_2 -> V_9 ;
V_2 -> V_6 [ 1 ] . V_10 = V_15 ;
V_2 -> V_6 [ 1 ] . V_11 = V_2 -> V_16 ;
V_2 -> V_6 [ 1 ] . V_12 = 2 ;
if ( F_2 ( V_2 -> V_13 , V_2 -> V_6 , 2 ) != 2 )
F_4 ( L_1 , V_3 ) ;
return ( V_2 -> V_16 [ 0 ] << 8 ) | V_2 -> V_16 [ 1 ] ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_17 = 100 ;
T_1 V_18 ;
while ( ( ( V_18 = F_3 ( V_2 , V_2 -> V_19 + 2 ) ) & 0x0100 ) == 0 && -- V_17 > 0 )
;
if ( V_17 == 0 )
return - V_14 ;
if ( ( V_18 & 0x0080 ) == 0 )
return - V_14 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_7 * V_6 , T_2 V_20 )
{
T_1 V_21 ;
T_1 V_22 ;
T_1 V_17 ;
T_1 V_23 = V_6 -> V_12 , V_12 ;
const T_2 * V_24 = V_6 -> V_11 ;
while ( V_23 ) {
F_3 ( V_2 , V_2 -> V_19 + 2 ) ;
V_12 = V_23 > 8 ? 8 : V_23 ;
for ( V_17 = 0 ; V_17 < V_12 ; V_17 += 2 ) {
V_21 = * V_24 ++ << 8 ;
if ( V_17 + 1 < V_12 )
V_21 |= * V_24 ++ ;
F_1 ( V_2 , V_2 -> V_19 , V_21 ) ;
}
V_22 = ( ( ( T_2 ) ( V_6 -> V_8 ) ) << 9 ) |
( 1 << 8 ) |
( 1 << 7 ) |
( 0 << 6 ) |
( 0 << 5 ) |
( ( V_12 & 0x7 ) << 2 ) |
( 0 << 1 ) |
( 0 << 0 ) ;
if ( V_23 == V_6 -> V_12 )
V_22 |= 1 << 5 ;
if ( V_23 - V_12 == 0 && V_20 )
V_22 |= 1 << 6 ;
F_1 ( V_2 , V_2 -> V_19 + 1 , V_22 ) ;
if ( F_5 ( V_2 ) != 0 )
return - V_14 ;
V_23 -= V_12 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_7 * V_6 )
{
T_1 V_22 ;
T_2 * V_24 = V_6 -> V_11 ;
T_1 V_25 = V_6 -> V_12 , V_12 ;
while ( V_25 ) {
V_12 = V_25 > 8 ? 8 : V_25 ;
V_22 = ( ( ( T_2 ) ( V_6 -> V_8 ) ) << 9 ) |
( 1 << 8 ) |
( 1 << 7 ) |
( 0 << 6 ) |
( 0 << 5 ) |
( ( V_12 & 0x7 ) << 2 ) |
( 1 << 1 ) |
( 0 << 0 ) ;
if ( V_25 == V_6 -> V_12 )
V_22 |= 1 << 5 ;
if ( V_25 - V_12 == 0 )
V_22 |= 1 << 6 ;
F_1 ( V_2 , V_2 -> V_19 + 1 , V_22 ) ;
if ( F_5 ( V_2 ) != 0 )
return - V_14 ;
V_25 -= V_12 ;
while ( V_12 ) {
V_22 = F_3 ( V_2 , V_2 -> V_19 ) ;
* V_24 ++ = ( V_22 >> 8 ) & 0xff ;
V_12 -- ;
if ( V_12 >= 1 ) {
* V_24 ++ = V_22 & 0xff ;
V_12 -- ;
}
}
}
return 0 ;
}
int F_8 ( struct V_26 * V_13 , T_1 V_27 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
if ( V_2 -> V_28 < V_29 && V_27 < 235 )
V_27 = 235 ;
return F_1 ( V_2 , V_2 -> V_19 + 3 , ( T_1 ) ( 60000 / V_27 ) ) ;
}
static T_3 F_10 ( struct V_26 * V_30 )
{
return V_31 ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
if ( V_2 -> V_28 > V_34 && V_2 -> V_35 != V_33 ) {
F_4 ( L_2 , V_33 ) ;
V_2 -> V_35 = V_33 ;
return F_1 ( V_2 , V_2 -> V_19 + 4 , V_33 ) ;
}
return 0 ;
}
static int F_12 ( struct V_26 * V_13 , struct V_7 V_6 [] , int V_36 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
int V_37 ;
int V_38 = 0 ;
F_11 ( V_2 , V_39 ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
if ( V_6 [ V_37 ] . V_10 & V_15 ) {
V_38 = F_7 ( V_2 , & V_6 [ V_37 ] ) ;
if ( V_38 != 0 )
return 0 ;
} else {
V_38 = F_6 ( V_2 , & V_6 [ V_37 ] , 1 ) ;
if ( V_38 != 0 )
return 0 ;
}
}
return V_36 ;
}
static int F_13 ( struct V_26 * V_13 , struct V_7 V_6 [] , int V_36 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
int V_37 ;
int V_38 = 0 ;
F_11 ( V_2 , V_40 ) ;
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
if ( V_6 [ V_37 ] . V_10 & V_15 ) {
V_38 = F_7 ( V_2 , & V_6 [ V_37 ] ) ;
if ( V_38 != 0 )
return 0 ;
} else {
V_38 = F_6 ( V_2 , & V_6 [ V_37 ] , 1 ) ;
if ( V_38 != 0 )
return 0 ;
}
}
return V_36 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_41 [ 4 ] ,
T_2 V_8 , int V_42 )
{
T_1 V_4 ;
if ( V_42 )
V_4 = V_8 << 8 ;
else
V_4 = 1 << 7 ;
if ( V_2 -> V_28 > V_43 )
V_4 <<= 1 ;
V_41 [ 0 ] = ( ( ( V_2 -> V_19 + 1 ) >> 8 ) & 0xff ) ;
V_41 [ 1 ] = ( ( V_2 -> V_19 + 1 ) & 0xff ) ;
V_41 [ 2 ] = V_4 >> 8 ;
V_41 [ 3 ] = V_4 & 0xff ;
return 0 ;
}
static int F_15 ( struct V_26 * V_13 ,
struct V_7 V_6 [] , int V_36 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
if ( V_36 > 32 ) {
F_4 ( L_3 , V_44 , V_36 ) ;
return - V_45 ;
}
memset ( V_2 -> V_6 , 0 , sizeof( struct V_7 ) * ( 2 + V_36 ) ) ;
F_11 ( V_2 , V_46 ) ;
F_14 ( V_2 , & V_2 -> V_5 [ 0 ] , V_6 [ 0 ] . V_8 , 1 ) ;
V_2 -> V_6 [ 0 ] . V_8 = V_2 -> V_9 ;
V_2 -> V_6 [ 0 ] . V_11 = & V_2 -> V_5 [ 0 ] ;
V_2 -> V_6 [ 0 ] . V_12 = 4 ;
memcpy ( & V_2 -> V_6 [ 1 ] , V_6 , sizeof( struct V_7 ) * V_36 ) ;
F_14 ( V_2 , & V_2 -> V_5 [ 4 ] , 0 , 0 ) ;
V_2 -> V_6 [ V_36 + 1 ] . V_8 = V_2 -> V_9 ;
V_2 -> V_6 [ V_36 + 1 ] . V_11 = & V_2 -> V_5 [ 4 ] ;
V_2 -> V_6 [ V_36 + 1 ] . V_12 = 4 ;
return F_2 ( V_2 -> V_13 , V_2 -> V_6 , 2 + V_36 ) == 2 + V_36 ? V_36 : - V_47 ;
}
static int F_16 ( struct V_26 * V_13 ,
struct V_7 V_6 [] , int V_36 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
if ( V_36 > 32 ) {
F_4 ( L_3 , V_44 , V_36 ) ;
return - V_45 ;
}
memset ( V_2 -> V_6 , 0 , sizeof( struct V_7 ) * ( 2 + V_36 ) ) ;
F_11 ( V_2 , V_48 ) ;
F_14 ( V_2 , & V_2 -> V_5 [ 0 ] , V_6 [ 0 ] . V_8 , 1 ) ;
V_2 -> V_6 [ 0 ] . V_8 = V_2 -> V_9 ;
V_2 -> V_6 [ 0 ] . V_11 = & V_2 -> V_5 [ 0 ] ;
V_2 -> V_6 [ 0 ] . V_12 = 4 ;
memcpy ( & V_2 -> V_6 [ 1 ] , V_6 , sizeof( struct V_7 ) * V_36 ) ;
F_14 ( V_2 , & V_2 -> V_5 [ 4 ] , 0 , 0 ) ;
V_2 -> V_6 [ V_36 + 1 ] . V_8 = V_2 -> V_9 ;
V_2 -> V_6 [ V_36 + 1 ] . V_11 = & V_2 -> V_5 [ 4 ] ;
V_2 -> V_6 [ V_36 + 1 ] . V_12 = 4 ;
return F_2 ( V_2 -> V_13 , V_2 -> V_6 , 2 + V_36 ) == 2 + V_36 ? V_36 : - V_47 ;
}
struct V_26 * F_17 ( struct V_1 * V_2 ,
enum V_32 V_33 ,
int V_49 )
{
struct V_26 * V_50 = NULL ;
switch ( V_33 ) {
case V_48 :
if ( V_49 )
V_50 = & V_2 -> V_51 ;
break;
case V_39 :
if ( ! V_49 )
V_50 = & V_2 -> V_52 ;
break;
case V_40 :
if ( ! V_49 )
V_50 = & V_2 -> V_53 ;
break;
case V_46 :
if ( V_49 )
V_50 = & V_2 -> V_54 ;
break;
default:
F_18 ( V_55 L_4 ) ;
break;
}
return V_50 ;
}
void F_19 ( struct V_1 * V_2 )
{
T_2 V_41 [ 4 ] ;
struct V_7 V_56 = { . V_8 = V_2 -> V_9 , . V_11 = V_41 , . V_12 = 4 } ;
F_14 ( V_2 , V_41 , 0 , 0 ) ;
F_2 ( V_2 -> V_13 , & V_56 , 1 ) ;
V_2 -> V_35 = 0xff ;
F_11 ( V_2 , V_48 ) ;
}
static int F_20 ( struct V_26 * V_13 ,
struct V_57 * V_58 , const char * V_59 ,
struct V_1 * V_2 )
{
strncpy ( V_13 -> V_59 , V_59 , sizeof( V_13 -> V_59 ) ) ;
V_13 -> V_58 = V_58 ;
V_13 -> V_60 = NULL ;
F_21 ( V_13 , V_2 ) ;
if ( F_22 ( V_13 ) < 0 )
return - V_61 ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_28 ,
struct V_26 * V_13 , T_2 V_9 )
{
T_2 V_41 [ 4 ] ;
struct V_7 V_56 = { . V_8 = V_9 >> 1 , . V_11 = V_41 , . V_12 = 4 } ;
V_2 -> V_28 = V_28 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_9 = V_9 >> 1 ;
if ( V_28 == V_62 || V_28 == V_63 )
V_2 -> V_19 = 1024 ;
else
V_2 -> V_19 = 768 ;
V_2 -> V_51 . V_64 . V_65 = V_2 -> V_13 -> V_64 . V_65 ;
if ( F_20
( & V_2 -> V_51 , & V_66 ,
L_5 , V_2 ) != 0 )
F_18 ( V_55
L_6 ) ;
V_2 -> V_52 . V_64 . V_65 = V_2 -> V_13 -> V_64 . V_65 ;
if ( F_20
( & V_2 -> V_52 , & V_67 ,
L_7 , V_2 ) != 0 )
F_18 ( V_55
L_8 ) ;
V_2 -> V_53 . V_64 . V_65 = V_2 -> V_13 -> V_64 . V_65 ;
if ( F_20
( & V_2 -> V_53 , & V_68 ,
L_9 , V_2 ) != 0 )
F_18 ( V_55
L_8 ) ;
V_2 -> V_54 . V_64 . V_65 = V_2 -> V_13 -> V_64 . V_65 ;
if ( F_20
( & V_2 -> V_54 , & V_69 ,
L_10 , V_2 ) != 0 )
F_18 ( V_55
L_8 ) ;
F_14 ( V_2 , V_41 , 0 , 0 ) ;
return F_2 ( V_13 , & V_56 , 1 ) == 1 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_51 ) ;
F_25 ( & V_2 -> V_52 ) ;
F_25 ( & V_2 -> V_53 ) ;
F_25 ( & V_2 -> V_54 ) ;
}
T_3 F_26 ( void )
{
struct V_70 V_71 ;
V_71 = F_27 () ;
return ( V_71 . V_72 * 10000 ) + ( V_71 . V_73 / 100000 ) ;
}
