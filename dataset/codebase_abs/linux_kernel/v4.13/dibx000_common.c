static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
if ( F_2 ( & V_2 -> V_6 ) < 0 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
V_2 -> V_8 [ 0 ] = ( V_3 >> 8 ) & 0xff ;
V_2 -> V_8 [ 1 ] = V_3 & 0xff ;
V_2 -> V_8 [ 2 ] = ( V_4 >> 8 ) & 0xff ;
V_2 -> V_8 [ 3 ] = V_4 & 0xff ;
memset ( V_2 -> V_9 , 0 , sizeof( struct V_10 ) ) ;
V_2 -> V_9 [ 0 ] . V_11 = V_2 -> V_12 ;
V_2 -> V_9 [ 0 ] . V_13 = 0 ;
V_2 -> V_9 [ 0 ] . V_14 = V_2 -> V_8 ;
V_2 -> V_9 [ 0 ] . V_15 = 4 ;
V_5 = F_4 ( V_2 -> V_16 , V_2 -> V_9 , 1 ) != 1 ? - V_17 : 0 ;
F_5 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_5 ;
if ( F_2 ( & V_2 -> V_6 ) < 0 ) {
F_3 ( L_1 ) ;
return 0 ;
}
V_2 -> V_8 [ 0 ] = V_3 >> 8 ;
V_2 -> V_8 [ 1 ] = V_3 & 0xff ;
memset ( V_2 -> V_9 , 0 , 2 * sizeof( struct V_10 ) ) ;
V_2 -> V_9 [ 0 ] . V_11 = V_2 -> V_12 ;
V_2 -> V_9 [ 0 ] . V_13 = 0 ;
V_2 -> V_9 [ 0 ] . V_14 = V_2 -> V_8 ;
V_2 -> V_9 [ 0 ] . V_15 = 2 ;
V_2 -> V_9 [ 1 ] . V_11 = V_2 -> V_12 ;
V_2 -> V_9 [ 1 ] . V_13 = V_18 ;
V_2 -> V_9 [ 1 ] . V_14 = V_2 -> V_19 ;
V_2 -> V_9 [ 1 ] . V_15 = 2 ;
if ( F_4 ( V_2 -> V_16 , V_2 -> V_9 , 2 ) != 2 )
F_3 ( L_2 , V_3 ) ;
V_5 = ( V_2 -> V_19 [ 0 ] << 8 ) | V_2 -> V_19 [ 1 ] ;
F_5 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_20 = 100 ;
T_1 V_21 ;
while ( ( ( V_21 = F_6 ( V_2 , V_2 -> V_22 + 2 ) ) & 0x0100 ) == 0 && -- V_20 > 0 )
;
if ( V_20 == 0 )
return - V_17 ;
if ( ( V_21 & 0x0080 ) == 0 )
return - V_17 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_10 * V_9 , T_2 V_23 )
{
T_1 V_24 ;
T_1 V_25 ;
T_1 V_20 ;
T_1 V_26 = V_9 -> V_15 , V_15 ;
const T_2 * V_27 = V_9 -> V_14 ;
while ( V_26 ) {
F_6 ( V_2 , V_2 -> V_22 + 2 ) ;
V_15 = V_26 > 8 ? 8 : V_26 ;
for ( V_20 = 0 ; V_20 < V_15 ; V_20 += 2 ) {
V_24 = * V_27 ++ << 8 ;
if ( V_20 + 1 < V_15 )
V_24 |= * V_27 ++ ;
F_1 ( V_2 , V_2 -> V_22 , V_24 ) ;
}
V_25 = ( ( ( T_2 ) ( V_9 -> V_11 ) ) << 9 ) |
( 1 << 8 ) |
( 1 << 7 ) |
( 0 << 6 ) |
( 0 << 5 ) |
( ( V_15 & 0x7 ) << 2 ) |
( 0 << 1 ) |
( 0 << 0 ) ;
if ( V_26 == V_9 -> V_15 )
V_25 |= 1 << 5 ;
if ( V_26 - V_15 == 0 && V_23 )
V_25 |= 1 << 6 ;
F_1 ( V_2 , V_2 -> V_22 + 1 , V_25 ) ;
if ( F_7 ( V_2 ) != 0 )
return - V_17 ;
V_26 -= V_15 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_10 * V_9 )
{
T_1 V_25 ;
T_2 * V_27 = V_9 -> V_14 ;
T_1 V_28 = V_9 -> V_15 , V_15 ;
while ( V_28 ) {
V_15 = V_28 > 8 ? 8 : V_28 ;
V_25 = ( ( ( T_2 ) ( V_9 -> V_11 ) ) << 9 ) |
( 1 << 8 ) |
( 1 << 7 ) |
( 0 << 6 ) |
( 0 << 5 ) |
( ( V_15 & 0x7 ) << 2 ) |
( 1 << 1 ) |
( 0 << 0 ) ;
if ( V_28 == V_9 -> V_15 )
V_25 |= 1 << 5 ;
if ( V_28 - V_15 == 0 )
V_25 |= 1 << 6 ;
F_1 ( V_2 , V_2 -> V_22 + 1 , V_25 ) ;
if ( F_7 ( V_2 ) != 0 )
return - V_17 ;
V_28 -= V_15 ;
while ( V_15 ) {
V_25 = F_6 ( V_2 , V_2 -> V_22 ) ;
* V_27 ++ = ( V_25 >> 8 ) & 0xff ;
V_15 -- ;
if ( V_15 >= 1 ) {
* V_27 ++ = V_25 & 0xff ;
V_15 -- ;
}
}
}
return 0 ;
}
int F_10 ( struct V_29 * V_16 , T_1 V_30 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
if ( V_2 -> V_31 < V_32 && V_30 < 235 )
V_30 = 235 ;
return F_1 ( V_2 , V_2 -> V_22 + 3 , ( T_1 ) ( 60000 / V_30 ) ) ;
}
static T_3 F_12 ( struct V_29 * V_33 )
{
return V_34 ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_35 V_36 )
{
if ( V_2 -> V_31 > V_37 && V_2 -> V_38 != V_36 ) {
F_3 ( L_3 , V_36 ) ;
V_2 -> V_38 = V_36 ;
return F_1 ( V_2 , V_2 -> V_22 + 4 , V_36 ) ;
}
return 0 ;
}
static int F_14 ( struct V_29 * V_16 , struct V_10 V_9 [] , int V_39 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
int V_40 ;
int V_5 = 0 ;
F_13 ( V_2 , V_41 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
if ( V_9 [ V_40 ] . V_13 & V_18 ) {
V_5 = F_9 ( V_2 , & V_9 [ V_40 ] ) ;
if ( V_5 != 0 )
return 0 ;
} else {
V_5 = F_8 ( V_2 , & V_9 [ V_40 ] , 1 ) ;
if ( V_5 != 0 )
return 0 ;
}
}
return V_39 ;
}
static int F_15 ( struct V_29 * V_16 , struct V_10 V_9 [] , int V_39 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
int V_40 ;
int V_5 = 0 ;
F_13 ( V_2 , V_42 ) ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
if ( V_9 [ V_40 ] . V_13 & V_18 ) {
V_5 = F_9 ( V_2 , & V_9 [ V_40 ] ) ;
if ( V_5 != 0 )
return 0 ;
} else {
V_5 = F_8 ( V_2 , & V_9 [ V_40 ] , 1 ) ;
if ( V_5 != 0 )
return 0 ;
}
}
return V_39 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_43 [ 4 ] ,
T_2 V_11 , int V_44 )
{
T_1 V_4 ;
if ( V_44 )
V_4 = V_11 << 8 ;
else
V_4 = 1 << 7 ;
if ( V_2 -> V_31 > V_45 )
V_4 <<= 1 ;
V_43 [ 0 ] = ( ( ( V_2 -> V_22 + 1 ) >> 8 ) & 0xff ) ;
V_43 [ 1 ] = ( ( V_2 -> V_22 + 1 ) & 0xff ) ;
V_43 [ 2 ] = V_4 >> 8 ;
V_43 [ 3 ] = V_4 & 0xff ;
return 0 ;
}
static int F_17 ( struct V_29 * V_16 ,
struct V_10 V_9 [] , int V_39 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
int V_5 ;
if ( V_39 > 32 ) {
F_3 ( L_4 , V_46 , V_39 ) ;
return - V_47 ;
}
F_13 ( V_2 , V_48 ) ;
if ( F_2 ( & V_2 -> V_6 ) < 0 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
memset ( V_2 -> V_9 , 0 , sizeof( struct V_10 ) * ( 2 + V_39 ) ) ;
F_16 ( V_2 , & V_2 -> V_8 [ 0 ] , V_9 [ 0 ] . V_11 , 1 ) ;
V_2 -> V_9 [ 0 ] . V_11 = V_2 -> V_12 ;
V_2 -> V_9 [ 0 ] . V_14 = & V_2 -> V_8 [ 0 ] ;
V_2 -> V_9 [ 0 ] . V_15 = 4 ;
memcpy ( & V_2 -> V_9 [ 1 ] , V_9 , sizeof( struct V_10 ) * V_39 ) ;
F_16 ( V_2 , & V_2 -> V_8 [ 4 ] , 0 , 0 ) ;
V_2 -> V_9 [ V_39 + 1 ] . V_11 = V_2 -> V_12 ;
V_2 -> V_9 [ V_39 + 1 ] . V_14 = & V_2 -> V_8 [ 4 ] ;
V_2 -> V_9 [ V_39 + 1 ] . V_15 = 4 ;
V_5 = ( F_4 ( V_2 -> V_16 , V_2 -> V_9 , 2 + V_39 ) == 2 + V_39 ?
V_39 : - V_49 ) ;
F_5 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_18 ( struct V_29 * V_16 ,
struct V_10 V_9 [] , int V_39 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
int V_5 ;
if ( V_39 > 32 ) {
F_3 ( L_4 , V_46 , V_39 ) ;
return - V_47 ;
}
F_13 ( V_2 , V_50 ) ;
if ( F_2 ( & V_2 -> V_6 ) < 0 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
memset ( V_2 -> V_9 , 0 , sizeof( struct V_10 ) * ( 2 + V_39 ) ) ;
F_16 ( V_2 , & V_2 -> V_8 [ 0 ] , V_9 [ 0 ] . V_11 , 1 ) ;
V_2 -> V_9 [ 0 ] . V_11 = V_2 -> V_12 ;
V_2 -> V_9 [ 0 ] . V_14 = & V_2 -> V_8 [ 0 ] ;
V_2 -> V_9 [ 0 ] . V_15 = 4 ;
memcpy ( & V_2 -> V_9 [ 1 ] , V_9 , sizeof( struct V_10 ) * V_39 ) ;
F_16 ( V_2 , & V_2 -> V_8 [ 4 ] , 0 , 0 ) ;
V_2 -> V_9 [ V_39 + 1 ] . V_11 = V_2 -> V_12 ;
V_2 -> V_9 [ V_39 + 1 ] . V_14 = & V_2 -> V_8 [ 4 ] ;
V_2 -> V_9 [ V_39 + 1 ] . V_15 = 4 ;
V_5 = ( F_4 ( V_2 -> V_16 , V_2 -> V_9 , 2 + V_39 ) == 2 + V_39 ?
V_39 : - V_49 ) ;
F_5 ( & V_2 -> V_6 ) ;
return V_5 ;
}
struct V_29 * F_19 ( struct V_1 * V_2 ,
enum V_35 V_36 ,
int V_51 )
{
struct V_29 * V_52 = NULL ;
switch ( V_36 ) {
case V_50 :
if ( V_51 )
V_52 = & V_2 -> V_53 ;
break;
case V_41 :
if ( ! V_51 )
V_52 = & V_2 -> V_54 ;
break;
case V_42 :
if ( ! V_51 )
V_52 = & V_2 -> V_55 ;
break;
case V_48 :
if ( V_51 )
V_52 = & V_2 -> V_56 ;
break;
default:
F_20 ( L_5 ) ;
break;
}
return V_52 ;
}
void F_21 ( struct V_1 * V_2 )
{
T_2 V_43 [ 4 ] ;
struct V_10 V_57 = { . V_11 = V_2 -> V_12 , . V_14 = V_43 , . V_15 = 4 } ;
F_16 ( V_2 , V_43 , 0 , 0 ) ;
F_4 ( V_2 -> V_16 , & V_57 , 1 ) ;
V_2 -> V_38 = 0xff ;
F_13 ( V_2 , V_50 ) ;
}
static int F_22 ( struct V_29 * V_16 ,
struct V_58 * V_59 , const char * V_60 ,
struct V_1 * V_2 )
{
strncpy ( V_16 -> V_60 , V_60 , sizeof( V_16 -> V_60 ) ) ;
V_16 -> V_59 = V_59 ;
V_16 -> V_61 = NULL ;
F_23 ( V_16 , V_2 ) ;
if ( F_24 ( V_16 ) < 0 )
return - V_62 ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_31 ,
struct V_29 * V_16 , T_2 V_12 )
{
int V_5 ;
F_26 ( & V_2 -> V_6 ) ;
if ( F_2 ( & V_2 -> V_6 ) < 0 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
memset ( V_2 -> V_9 , 0 , sizeof( struct V_10 ) ) ;
V_2 -> V_9 [ 0 ] . V_11 = V_12 >> 1 ;
V_2 -> V_9 [ 0 ] . V_13 = 0 ;
V_2 -> V_9 [ 0 ] . V_14 = V_2 -> V_8 ;
V_2 -> V_9 [ 0 ] . V_15 = 4 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_12 = V_12 >> 1 ;
if ( V_31 == V_63 || V_31 == V_64 )
V_2 -> V_22 = 1024 ;
else
V_2 -> V_22 = 768 ;
V_2 -> V_53 . V_65 . V_66 = V_2 -> V_16 -> V_65 . V_66 ;
if ( F_22
( & V_2 -> V_53 , & V_67 ,
L_6 , V_2 ) != 0 )
F_20 ( L_7 ) ;
V_2 -> V_54 . V_65 . V_66 = V_2 -> V_16 -> V_65 . V_66 ;
if ( F_22
( & V_2 -> V_54 , & V_68 ,
L_8 , V_2 ) != 0 )
F_20 ( L_9 ) ;
V_2 -> V_55 . V_65 . V_66 = V_2 -> V_16 -> V_65 . V_66 ;
if ( F_22
( & V_2 -> V_55 , & V_69 ,
L_10 , V_2 ) != 0 )
F_20 ( L_9 ) ;
V_2 -> V_56 . V_65 . V_66 = V_2 -> V_16 -> V_65 . V_66 ;
if ( F_22
( & V_2 -> V_56 , & V_70 ,
L_11 , V_2 ) != 0 )
F_20 ( L_9 ) ;
F_16 ( V_2 , V_2 -> V_8 , 0 , 0 ) ;
V_5 = ( F_4 ( V_16 , V_2 -> V_9 , 1 ) == 1 ) ;
F_5 ( & V_2 -> V_6 ) ;
return V_5 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_53 ) ;
F_28 ( & V_2 -> V_54 ) ;
F_28 ( & V_2 -> V_55 ) ;
F_28 ( & V_2 -> V_56 ) ;
}
