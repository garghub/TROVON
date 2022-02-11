int F_1 ( const T_1 * V_1 )
{
return ( ( V_1 != NULL &&
V_1 -> V_2 != NULL &&
V_1 -> V_2 -> V_3 != NULL )
? ( ( V_1 -> V_2 -> V_3 [ 0 ] << 8 ) |
( V_1 -> V_2 -> V_3 [ 1 ] ) )
: 0 ) ;
}
static int F_2 ( unsigned char * V_4 ,
const T_2 * V_5 ,
const int V_6 ,
const unsigned char V_7 )
{
if ( V_5 -> V_6 < 0 || V_5 -> V_6 > V_6 )
return 0 ;
if ( V_5 -> V_6 > 0 ) {
memcpy ( V_4 , V_5 -> V_3 , V_5 -> V_6 ) ;
if ( ( V_5 -> V_8 & 7 ) != 0 ) {
unsigned char V_9 = 0xFF >> ( 8 - ( V_5 -> V_8 & 7 ) ) ;
if ( V_7 == 0 )
V_4 [ V_5 -> V_6 - 1 ] &= ~ V_9 ;
else
V_4 [ V_5 -> V_6 - 1 ] |= V_9 ;
}
}
memset ( V_4 + V_5 -> V_6 , V_7 , V_6 - V_5 -> V_6 ) ;
return 1 ;
}
static int F_3 ( T_3 * V_10 ,
const unsigned V_11 ,
const unsigned char V_7 ,
const T_2 * V_5 )
{
unsigned char V_4 [ V_12 ] ;
int V_13 , V_14 ;
if ( V_5 -> V_6 < 0 )
return 0 ;
switch ( V_11 ) {
case V_15 :
if ( ! F_2 ( V_4 , V_5 , 4 , V_7 ) )
return 0 ;
F_4 ( V_10 , L_1 , V_4 [ 0 ] , V_4 [ 1 ] , V_4 [ 2 ] , V_4 [ 3 ] ) ;
break;
case V_16 :
if ( ! F_2 ( V_4 , V_5 , 16 , V_7 ) )
return 0 ;
for ( V_14 = 16 ; V_14 > 1 && V_4 [ V_14 - 1 ] == 0x00 && V_4 [ V_14 - 2 ] == 0x00 ; V_14 -= 2 )
;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 += 2 )
F_4 ( V_10 , L_2 , ( V_4 [ V_13 ] << 8 ) | V_4 [ V_13 + 1 ] , ( V_13 < 14 ? L_3 : L_4 ) ) ;
if ( V_13 < 16 )
F_5 ( V_10 , L_3 ) ;
if ( V_13 == 0 )
F_5 ( V_10 , L_3 ) ;
break;
default:
for ( V_13 = 0 ; V_13 < V_5 -> V_6 ; V_13 ++ )
F_4 ( V_10 , L_5 , ( V_13 > 0 ? L_3 : L_4 ) , V_5 -> V_3 [ V_13 ] ) ;
F_4 ( V_10 , L_6 , ( int ) ( V_5 -> V_8 & 7 ) ) ;
break;
}
return 1 ;
}
static int F_6 ( T_3 * V_10 ,
const int V_17 ,
const T_4 * V_18 ,
const unsigned V_11 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_7 ( V_18 ) ; V_13 ++ ) {
const T_5 * V_19 = F_8 ( V_18 , V_13 ) ;
F_4 ( V_10 , L_7 , V_17 , L_4 ) ;
switch ( V_19 -> type ) {
case V_20 :
if ( ! F_3 ( V_10 , V_11 , 0x00 , V_19 -> V_21 . V_22 ) )
return 0 ;
F_4 ( V_10 , L_8 , F_9 ( V_19 -> V_21 . V_22 ) ) ;
continue;
case V_23 :
if ( ! F_3 ( V_10 , V_11 , 0x00 , V_19 -> V_21 . V_24 -> V_25 ) )
return 0 ;
F_5 ( V_10 , L_9 ) ;
if ( ! F_3 ( V_10 , V_11 , 0xFF , V_19 -> V_21 . V_24 -> V_26 ) )
return 0 ;
F_5 ( V_10 , L_10 ) ;
continue;
}
}
return 1 ;
}
static int F_10 ( const T_6 * V_27 ,
void * V_28 ,
T_3 * V_10 ,
int V_17 )
{
const T_7 * V_4 = V_28 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < F_11 ( V_4 ) ; V_13 ++ ) {
T_1 * V_1 = F_12 ( V_4 , V_13 ) ;
const unsigned int V_11 = F_1 ( V_1 ) ;
switch ( V_11 ) {
case V_15 :
F_4 ( V_10 , L_11 , V_17 , L_4 ) ;
break;
case V_16 :
F_4 ( V_10 , L_12 , V_17 , L_4 ) ;
break;
default:
F_4 ( V_10 , L_13 , V_17 , L_4 , V_11 ) ;
break;
}
if ( V_1 -> V_2 -> V_6 > 2 ) {
switch ( V_1 -> V_2 -> V_3 [ 2 ] ) {
case 1 :
F_5 ( V_10 , L_14 ) ;
break;
case 2 :
F_5 ( V_10 , L_15 ) ;
break;
case 3 :
F_5 ( V_10 , L_16 ) ;
break;
case 4 :
F_5 ( V_10 , L_17 ) ;
break;
case 64 :
F_5 ( V_10 , L_18 ) ;
break;
case 65 :
F_5 ( V_10 , L_19 ) ;
break;
case 66 :
F_5 ( V_10 , L_20 ) ;
break;
case 128 :
F_5 ( V_10 , L_21 ) ;
break;
default:
F_4 ( V_10 , L_22 ,
( unsigned ) V_1 -> V_2 -> V_3 [ 2 ] ) ;
break;
}
}
switch ( V_1 -> V_29 -> type ) {
case V_30 :
F_5 ( V_10 , L_23 ) ;
break;
case V_31 :
F_5 ( V_10 , L_24 ) ;
if ( ! F_6 ( V_10 ,
V_17 + 2 ,
V_1 -> V_29 -> V_21 . V_32 ,
V_11 ) )
return 0 ;
break;
}
}
return 1 ;
}
static int F_13 ( const T_5 * V_33 ,
const T_5 * V_34 ,
const int V_6 )
{
unsigned char V_35 [ V_12 ] , V_36 [ V_12 ] ;
int V_37 = 0 , V_38 = 0 ;
int V_39 ;
switch ( V_33 -> type ) {
case V_20 :
if ( ! F_2 ( V_35 , V_33 -> V_21 . V_22 , V_6 , 0x00 ) )
return - 1 ;
V_37 = F_9 ( V_33 -> V_21 . V_22 ) ;
break;
case V_23 :
if ( ! F_2 ( V_35 , V_33 -> V_21 . V_24 -> V_25 , V_6 , 0x00 ) )
return - 1 ;
V_37 = V_6 * 8 ;
break;
}
switch ( V_34 -> type ) {
case V_20 :
if ( ! F_2 ( V_36 , V_34 -> V_21 . V_22 , V_6 , 0x00 ) )
return - 1 ;
V_38 = F_9 ( V_34 -> V_21 . V_22 ) ;
break;
case V_23 :
if ( ! F_2 ( V_36 , V_34 -> V_21 . V_24 -> V_25 , V_6 , 0x00 ) )
return - 1 ;
V_38 = V_6 * 8 ;
break;
}
if ( ( V_39 = memcmp ( V_35 , V_36 , V_6 ) ) != 0 )
return V_39 ;
else
return V_37 - V_38 ;
}
static int F_14 ( const T_5 * const * V_33 ,
const T_5 * const * V_34 )
{
return F_13 ( * V_33 , * V_34 , 4 ) ;
}
static int F_15 ( const T_5 * const * V_33 ,
const T_5 * const * V_34 )
{
return F_13 ( * V_33 , * V_34 , 16 ) ;
}
static int F_16 ( const unsigned char * V_25 ,
const unsigned char * V_26 ,
const int V_6 )
{
unsigned char V_9 ;
int V_13 , V_40 ;
F_17 ( memcmp ( V_25 , V_26 , V_6 ) <= 0 ) ;
for ( V_13 = 0 ; V_13 < V_6 && V_25 [ V_13 ] == V_26 [ V_13 ] ; V_13 ++ )
;
for ( V_40 = V_6 - 1 ; V_40 >= 0 && V_25 [ V_40 ] == 0x00 && V_26 [ V_40 ] == 0xFF ; V_40 -- )
;
if ( V_13 < V_40 )
return - 1 ;
if ( V_13 > V_40 )
return V_13 * 8 ;
V_9 = V_25 [ V_13 ] ^ V_26 [ V_13 ] ;
switch ( V_9 ) {
case 0x01 : V_40 = 7 ; break;
case 0x03 : V_40 = 6 ; break;
case 0x07 : V_40 = 5 ; break;
case 0x0F : V_40 = 4 ; break;
case 0x1F : V_40 = 3 ; break;
case 0x3F : V_40 = 2 ; break;
case 0x7F : V_40 = 1 ; break;
default: return - 1 ;
}
if ( ( V_25 [ V_13 ] & V_9 ) != 0 || ( V_26 [ V_13 ] & V_9 ) != V_9 )
return - 1 ;
else
return V_13 * 8 + V_40 ;
}
static int F_18 ( T_5 * * V_41 ,
unsigned char * V_4 ,
const int V_42 )
{
int V_43 = ( V_42 + 7 ) / 8 , V_44 = V_42 % 8 ;
T_5 * V_19 = F_19 () ;
if ( V_19 == NULL )
return 0 ;
V_19 -> type = V_20 ;
if ( V_19 -> V_21 . V_22 == NULL &&
( V_19 -> V_21 . V_22 = F_20 () ) == NULL )
goto V_45;
if ( ! F_21 ( V_19 -> V_21 . V_22 , V_4 , V_43 ) )
goto V_45;
V_19 -> V_21 . V_22 -> V_8 &= ~ 7 ;
V_19 -> V_21 . V_22 -> V_8 |= V_46 ;
if ( V_44 > 0 ) {
V_19 -> V_21 . V_22 -> V_3 [ V_43 - 1 ] &= ~ ( 0xFF >> V_44 ) ;
V_19 -> V_21 . V_22 -> V_8 |= 8 - V_44 ;
}
* V_41 = V_19 ;
return 1 ;
V_45:
F_22 ( V_19 ) ;
return 0 ;
}
static int F_23 ( T_5 * * V_41 ,
unsigned char * V_25 ,
unsigned char * V_26 ,
const int V_6 )
{
T_5 * V_19 ;
int V_13 , V_42 ;
if ( ( V_42 = F_16 ( V_25 , V_26 , V_6 ) ) >= 0 )
return F_18 ( V_41 , V_25 , V_42 ) ;
if ( ( V_19 = F_19 () ) == NULL )
return 0 ;
V_19 -> type = V_23 ;
F_17 ( V_19 -> V_21 . V_24 == NULL ) ;
if ( ( V_19 -> V_21 . V_24 = F_24 () ) == NULL )
goto V_45;
if ( V_19 -> V_21 . V_24 -> V_25 == NULL &&
( V_19 -> V_21 . V_24 -> V_25 = F_20 () ) == NULL )
goto V_45;
if ( V_19 -> V_21 . V_24 -> V_26 == NULL &&
( V_19 -> V_21 . V_24 -> V_26 = F_20 () ) == NULL )
goto V_45;
for ( V_13 = V_6 ; V_13 > 0 && V_25 [ V_13 - 1 ] == 0x00 ; -- V_13 )
;
if ( ! F_21 ( V_19 -> V_21 . V_24 -> V_25 , V_25 , V_13 ) )
goto V_45;
V_19 -> V_21 . V_24 -> V_25 -> V_8 &= ~ 7 ;
V_19 -> V_21 . V_24 -> V_25 -> V_8 |= V_46 ;
if ( V_13 > 0 ) {
unsigned char V_34 = V_25 [ V_13 - 1 ] ;
int V_40 = 1 ;
while ( ( V_34 & ( 0xFFU >> V_40 ) ) != 0 )
++ V_40 ;
V_19 -> V_21 . V_24 -> V_25 -> V_8 |= 8 - V_40 ;
}
for ( V_13 = V_6 ; V_13 > 0 && V_26 [ V_13 - 1 ] == 0xFF ; -- V_13 )
;
if ( ! F_21 ( V_19 -> V_21 . V_24 -> V_26 , V_26 , V_13 ) )
goto V_45;
V_19 -> V_21 . V_24 -> V_26 -> V_8 &= ~ 7 ;
V_19 -> V_21 . V_24 -> V_26 -> V_8 |= V_46 ;
if ( V_13 > 0 ) {
unsigned char V_34 = V_26 [ V_13 - 1 ] ;
int V_40 = 1 ;
while ( ( V_34 & ( 0xFFU >> V_40 ) ) != ( 0xFFU >> V_40 ) )
++ V_40 ;
V_19 -> V_21 . V_24 -> V_26 -> V_8 |= 8 - V_40 ;
}
* V_41 = V_19 ;
return 1 ;
V_45:
F_22 ( V_19 ) ;
return 0 ;
}
static T_1 * F_25 ( T_7 * V_4 ,
const unsigned V_11 ,
const unsigned * V_47 )
{
T_1 * V_1 ;
unsigned char V_48 [ 3 ] ;
unsigned V_49 ;
int V_13 ;
V_48 [ 0 ] = ( V_11 >> 8 ) & 0xFF ;
V_48 [ 1 ] = V_11 & 0xFF ;
if ( V_47 != NULL ) {
V_48 [ 2 ] = * V_47 & 0xFF ;
V_49 = 3 ;
} else {
V_49 = 2 ;
}
for ( V_13 = 0 ; V_13 < F_11 ( V_4 ) ; V_13 ++ ) {
V_1 = F_12 ( V_4 , V_13 ) ;
F_17 ( V_1 -> V_2 -> V_3 != NULL ) ;
if ( V_1 -> V_2 -> V_6 == V_49 &&
! memcmp ( V_1 -> V_2 -> V_3 , V_48 , V_49 ) )
return V_1 ;
}
if ( ( V_1 = F_26 () ) == NULL )
goto V_45;
if ( V_1 -> V_29 == NULL &&
( V_1 -> V_29 = F_27 () ) == NULL )
goto V_45;
if ( V_1 -> V_2 == NULL &&
( V_1 -> V_2 = F_28 () ) == NULL )
goto V_45;
if ( ! F_29 ( V_1 -> V_2 , V_48 , V_49 ) )
goto V_45;
if ( ! F_30 ( V_4 , V_1 ) )
goto V_45;
return V_1 ;
V_45:
F_31 ( V_1 ) ;
return NULL ;
}
int F_32 ( T_7 * V_4 ,
const unsigned V_11 ,
const unsigned * V_47 )
{
T_1 * V_1 = F_25 ( V_4 , V_11 , V_47 ) ;
if ( V_1 == NULL ||
V_1 -> V_29 == NULL ||
( V_1 -> V_29 -> type == V_31 &&
V_1 -> V_29 -> V_21 . V_32 != NULL ) )
return 0 ;
if ( V_1 -> V_29 -> type == V_30 &&
V_1 -> V_29 -> V_21 . V_50 != NULL )
return 1 ;
if ( V_1 -> V_29 -> V_21 . V_50 == NULL &&
( V_1 -> V_29 -> V_21 . V_50 = F_33 () ) == NULL )
return 0 ;
V_1 -> V_29 -> type = V_30 ;
return 1 ;
}
static T_4 * F_34 ( T_7 * V_4 ,
const unsigned V_11 ,
const unsigned * V_47 )
{
T_1 * V_1 = F_25 ( V_4 , V_11 , V_47 ) ;
T_4 * V_18 = NULL ;
if ( V_1 == NULL ||
V_1 -> V_29 == NULL ||
( V_1 -> V_29 -> type == V_30 &&
V_1 -> V_29 -> V_21 . V_50 != NULL ) )
return NULL ;
if ( V_1 -> V_29 -> type == V_31 )
V_18 = V_1 -> V_29 -> V_21 . V_32 ;
if ( V_18 != NULL )
return V_18 ;
if ( ( V_18 = F_35 () ) == NULL )
return NULL ;
switch ( V_11 ) {
case V_15 :
( void ) F_36 ( V_18 , F_14 ) ;
break;
case V_16 :
( void ) F_36 ( V_18 , F_15 ) ;
break;
}
V_1 -> V_29 -> type = V_31 ;
V_1 -> V_29 -> V_21 . V_32 = V_18 ;
return V_18 ;
}
int F_37 ( T_7 * V_4 ,
const unsigned V_11 ,
const unsigned * V_47 ,
unsigned char * V_33 ,
const int V_42 )
{
T_4 * V_18 = F_34 ( V_4 , V_11 , V_47 ) ;
T_5 * V_19 ;
if ( V_18 == NULL || ! F_18 ( & V_19 , V_33 , V_42 ) )
return 0 ;
if ( F_38 ( V_18 , V_19 ) )
return 1 ;
F_22 ( V_19 ) ;
return 0 ;
}
int F_39 ( T_7 * V_4 ,
const unsigned V_11 ,
const unsigned * V_47 ,
unsigned char * V_25 ,
unsigned char * V_26 )
{
T_4 * V_18 = F_34 ( V_4 , V_11 , V_47 ) ;
T_5 * V_19 ;
int V_6 = F_40 ( V_11 ) ;
if ( V_18 == NULL )
return 0 ;
if ( ! F_23 ( & V_19 , V_25 , V_26 , V_6 ) )
return 0 ;
if ( F_38 ( V_18 , V_19 ) )
return 1 ;
F_22 ( V_19 ) ;
return 0 ;
}
static int F_41 ( T_5 * V_19 ,
unsigned char * V_25 ,
unsigned char * V_26 ,
int V_6 )
{
if ( V_19 == NULL || V_25 == NULL || V_26 == NULL )
return 0 ;
switch ( V_19 -> type ) {
case V_20 :
return ( F_2 ( V_25 , V_19 -> V_21 . V_22 , V_6 , 0x00 ) &&
F_2 ( V_26 , V_19 -> V_21 . V_22 , V_6 , 0xFF ) ) ;
case V_23 :
return ( F_2 ( V_25 , V_19 -> V_21 . V_24 -> V_25 , V_6 , 0x00 ) &&
F_2 ( V_26 , V_19 -> V_21 . V_24 -> V_26 , V_6 , 0xFF ) ) ;
}
return 0 ;
}
int F_42 ( T_5 * V_19 ,
const unsigned V_11 ,
unsigned char * V_25 ,
unsigned char * V_26 ,
const int V_6 )
{
int V_51 = F_40 ( V_11 ) ;
if ( V_19 == NULL || V_25 == NULL || V_26 == NULL ||
V_51 == 0 || V_6 < V_51 ||
( V_19 -> type != V_20 &&
V_19 -> type != V_23 ) ||
! F_41 ( V_19 , V_25 , V_26 , V_51 ) )
return 0 ;
return V_51 ;
}
static int F_43 ( const T_1 * const * V_52 ,
const T_1 * const * V_53 )
{
const T_8 * V_33 = ( * V_52 ) -> V_2 ;
const T_8 * V_34 = ( * V_53 ) -> V_2 ;
int V_54 = ( ( V_33 -> V_6 <= V_34 -> V_6 ) ? V_33 -> V_6 : V_34 -> V_6 ) ;
int V_55 = memcmp ( V_33 -> V_3 , V_34 -> V_3 , V_54 ) ;
return V_55 ? V_55 : V_33 -> V_6 - V_34 -> V_6 ;
}
int F_44 ( T_7 * V_4 )
{
unsigned char V_56 [ V_12 ] , V_57 [ V_12 ] ;
unsigned char V_58 [ V_12 ] , V_59 [ V_12 ] ;
T_4 * V_18 ;
int V_13 , V_40 , V_60 ;
if ( V_4 == NULL )
return 1 ;
for ( V_13 = 0 ; V_13 < F_11 ( V_4 ) - 1 ; V_13 ++ ) {
const T_1 * V_33 = F_12 ( V_4 , V_13 ) ;
const T_1 * V_34 = F_12 ( V_4 , V_13 + 1 ) ;
if ( F_43 ( & V_33 , & V_34 ) >= 0 )
return 0 ;
}
for ( V_13 = 0 ; V_13 < F_11 ( V_4 ) ; V_13 ++ ) {
T_1 * V_1 = F_12 ( V_4 , V_13 ) ;
int V_6 = F_40 ( F_1 ( V_1 ) ) ;
if ( V_1 == NULL || V_1 -> V_29 == NULL )
return 0 ;
switch ( V_1 -> V_29 -> type ) {
case V_30 :
continue;
case V_31 :
break;
default:
return 0 ;
}
V_18 = V_1 -> V_29 -> V_21 . V_32 ;
if ( F_7 ( V_18 ) == 0 )
return 0 ;
for ( V_40 = 0 ; V_40 < F_7 ( V_18 ) - 1 ; V_40 ++ ) {
T_5 * V_33 = F_8 ( V_18 , V_40 ) ;
T_5 * V_34 = F_8 ( V_18 , V_40 + 1 ) ;
if ( ! F_41 ( V_33 , V_56 , V_57 , V_6 ) ||
! F_41 ( V_34 , V_58 , V_59 , V_6 ) )
return 0 ;
if ( memcmp ( V_56 , V_58 , V_6 ) >= 0 ||
memcmp ( V_56 , V_57 , V_6 ) > 0 ||
memcmp ( V_58 , V_59 , V_6 ) > 0 )
return 0 ;
for ( V_60 = V_6 - 1 ; V_60 >= 0 && V_58 [ V_60 ] -- == 0x00 ; V_60 -- )
;
if ( memcmp ( V_57 , V_58 , V_6 ) >= 0 )
return 0 ;
if ( V_33 -> type == V_23 &&
F_16 ( V_56 , V_57 , V_6 ) >= 0 )
return 0 ;
}
V_40 = F_7 ( V_18 ) - 1 ;
{
T_5 * V_33 = F_8 ( V_18 , V_40 ) ;
if ( V_33 != NULL && V_33 -> type == V_23 ) {
if ( ! F_41 ( V_33 , V_56 , V_57 , V_6 ) )
return 0 ;
if ( memcmp ( V_56 , V_57 , V_6 ) > 0 ||
F_16 ( V_56 , V_57 , V_6 ) >= 0 )
return 0 ;
}
}
}
return 1 ;
}
static int F_45 ( T_4 * V_18 ,
const unsigned V_11 )
{
int V_13 , V_40 , V_6 = F_40 ( V_11 ) ;
F_46 ( V_18 ) ;
for ( V_13 = 0 ; V_13 < F_7 ( V_18 ) - 1 ; V_13 ++ ) {
T_5 * V_33 = F_8 ( V_18 , V_13 ) ;
T_5 * V_34 = F_8 ( V_18 , V_13 + 1 ) ;
unsigned char V_56 [ V_12 ] , V_57 [ V_12 ] ;
unsigned char V_58 [ V_12 ] , V_59 [ V_12 ] ;
if ( ! F_41 ( V_33 , V_56 , V_57 , V_6 ) ||
! F_41 ( V_34 , V_58 , V_59 , V_6 ) )
return 0 ;
if ( memcmp ( V_56 , V_57 , V_6 ) > 0 ||
memcmp ( V_58 , V_59 , V_6 ) > 0 )
return 0 ;
if ( memcmp ( V_57 , V_58 , V_6 ) >= 0 )
return 0 ;
for ( V_40 = V_6 - 1 ; V_40 >= 0 && V_58 [ V_40 ] -- == 0x00 ; V_40 -- )
;
if ( memcmp ( V_57 , V_58 , V_6 ) == 0 ) {
T_5 * V_61 ;
if ( ! F_23 ( & V_61 , V_56 , V_59 , V_6 ) )
return 0 ;
( void ) F_47 ( V_18 , V_13 , V_61 ) ;
( void ) F_48 ( V_18 , V_13 + 1 ) ;
F_22 ( V_33 ) ;
F_22 ( V_34 ) ;
-- V_13 ;
continue;
}
}
V_40 = F_7 ( V_18 ) - 1 ;
{
T_5 * V_33 = F_8 ( V_18 , V_40 ) ;
if ( V_33 != NULL && V_33 -> type == V_23 ) {
unsigned char V_56 [ V_12 ] , V_57 [ V_12 ] ;
F_41 ( V_33 , V_56 , V_57 , V_6 ) ;
if ( memcmp ( V_56 , V_57 , V_6 ) > 0 )
return 0 ;
}
}
return 1 ;
}
int F_49 ( T_7 * V_4 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < F_11 ( V_4 ) ; V_13 ++ ) {
T_1 * V_1 = F_12 ( V_4 , V_13 ) ;
if ( V_1 -> V_29 -> type == V_31 &&
! F_45 ( V_1 -> V_29 -> V_21 . V_32 ,
F_1 ( V_1 ) ) )
return 0 ;
}
( void ) F_50 ( V_4 , F_43 ) ;
F_51 ( V_4 ) ;
F_17 ( F_44 ( V_4 ) ) ;
return 1 ;
}
int F_52 ( T_7 * V_4 )
{
int V_13 ;
if ( V_4 == NULL )
return 0 ;
for ( V_13 = 0 ; V_13 < F_11 ( V_4 ) ; V_13 ++ ) {
T_1 * V_1 = F_12 ( V_4 , V_13 ) ;
if ( V_1 -> V_29 -> type == V_30 )
return 1 ;
}
return 0 ;
}
static int F_53 ( T_4 * V_62 ,
T_4 * V_63 ,
int V_6 )
{
unsigned char V_64 [ V_12 ] , V_65 [ V_12 ] ;
unsigned char V_66 [ V_12 ] , V_67 [ V_12 ] ;
int V_68 , V_69 ;
if ( V_63 == NULL || V_62 == V_63 )
return 1 ;
if ( V_62 == NULL )
return 0 ;
V_68 = 0 ;
for ( V_69 = 0 ; V_69 < F_7 ( V_63 ) ; V_69 ++ ) {
if ( ! F_41 ( F_8 ( V_63 , V_69 ) ,
V_66 , V_67 , V_6 ) )
return - 1 ;
for (; ; V_68 ++ ) {
if ( V_68 >= F_7 ( V_62 ) )
return 0 ;
if ( ! F_41 ( F_8 ( V_62 , V_68 ) ,
V_64 , V_65 , V_6 ) )
return 0 ;
if ( memcmp ( V_65 , V_67 , V_6 ) < 0 )
continue;
if ( memcmp ( V_64 , V_66 , V_6 ) > 0 )
return 0 ;
break;
}
}
return 1 ;
}
int F_54 ( T_7 * V_33 , T_7 * V_34 )
{
int V_13 ;
if ( V_33 == NULL || V_33 == V_34 )
return 1 ;
if ( V_34 == NULL || F_52 ( V_33 ) || F_52 ( V_34 ) )
return 0 ;
( void ) F_50 ( V_34 , F_43 ) ;
for ( V_13 = 0 ; V_13 < F_11 ( V_33 ) ; V_13 ++ ) {
T_1 * V_70 = F_12 ( V_33 , V_13 ) ;
int V_40 = F_55 ( V_34 , V_70 ) ;
T_1 * V_71 ;
V_71 = F_12 ( V_34 , V_40 ) ;
if ( V_71 == NULL )
return 0 ;
if ( ! F_53 ( V_71 -> V_29 -> V_21 . V_32 ,
V_70 -> V_29 -> V_21 . V_32 ,
F_40 ( F_1 ( V_71 ) ) ) )
return 0 ;
}
return 1 ;
}
int F_56 ( T_9 * V_72 )
{
return F_57 ( V_72 , V_72 -> V_73 , NULL ) ;
}
