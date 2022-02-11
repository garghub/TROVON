T_1 *
F_1 ( const T_2 * V_1 )
{
return F_2 ( V_1 , 6 , ':' ) ;
}
T_1 *
F_3 ( T_3 * V_2 , const T_4 V_3 )
{
return F_2 ( F_4 ( V_2 , V_3 , 6 ) , 6 , ':' ) ;
}
const T_1 *
F_5 ( const T_2 * V_1 ) {
T_1 * V_4 ;
V_4 = F_6 ( V_5 ) ;
F_7 ( V_1 , V_4 , V_5 ) ;
return V_4 ;
}
const T_1 *
F_8 ( T_3 * V_2 , const T_4 V_3 )
{
T_1 * V_4 ;
V_4 = F_6 ( V_5 ) ;
F_7 ( F_4 ( V_2 , V_3 , V_6 ) , V_4 , V_5 ) ;
return V_4 ;
}
T_1 *
F_9 ( const struct V_7 * V_1 ) {
T_1 * V_8 ;
V_8 = F_6 ( V_9 ) ;
F_10 ( V_1 , V_8 ) ;
return V_8 ;
}
T_1 *
F_11 ( T_3 * V_2 , const T_4 V_3 )
{
T_1 * V_4 ;
V_4 = F_6 ( V_9 ) ;
F_10 ( ( const struct V_7 * ) F_4 ( V_2 , V_3 , V_10 ) , V_4 ) ;
return V_4 ;
}
static void
F_12 ( const T_5 * V_11 , char * V_4 , T_6 V_12 )
{
struct { int V_13 , V_14 ; } V_15 , V_16 ;
T_7 V_17 [ 8 ] ;
int V_18 ;
if ( V_12 < V_9 ) {
F_13 ( V_4 , V_19 , V_12 ) ;
return;
}
for ( V_18 = 0 ; V_18 < 16 ; V_18 += 2 ) {
V_17 [ V_18 / 2 ] = ( V_11 [ V_18 + 1 ] << 0 ) ;
V_17 [ V_18 / 2 ] |= ( V_11 [ V_18 ] << 8 ) ;
}
V_15 . V_13 = - 1 ; V_15 . V_14 = 0 ;
V_16 . V_13 = - 1 ; V_16 . V_14 = 0 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
if ( V_17 [ V_18 ] == 0 ) {
if ( V_16 . V_13 == - 1 ) {
V_16 . V_13 = V_18 ;
V_16 . V_14 = 1 ;
} else
V_16 . V_14 ++ ;
} else {
if ( V_16 . V_13 != - 1 ) {
if ( V_15 . V_13 == - 1 || V_16 . V_14 > V_15 . V_14 )
V_15 = V_16 ;
V_16 . V_13 = - 1 ;
}
}
}
if ( V_16 . V_13 != - 1 ) {
if ( V_15 . V_13 == - 1 || V_16 . V_14 > V_15 . V_14 )
V_15 = V_16 ;
}
if ( V_15 . V_13 != - 1 && V_15 . V_14 < 2 )
V_15 . V_13 = - 1 ;
if ( V_15 . V_13 == 0 && ( V_15 . V_14 == 6 || ( V_15 . V_14 == 5 && V_17 [ 5 ] == 0xffff ) ) )
{
V_4 = F_14 ( V_4 , L_1 ) ;
if ( V_15 . V_14 == 5 )
V_4 = F_14 ( V_4 , L_2 ) ;
F_7 ( V_11 + 12 , V_4 , V_5 ) ;
return;
}
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
if ( V_18 == V_15 . V_13 ) {
* V_4 ++ = ':' ;
V_18 += V_15 . V_14 ;
if ( V_18 == 8 ) {
* V_4 ++ = ':' ;
break;
}
}
if ( V_18 != 0 )
* V_4 ++ = ':' ;
V_4 = F_15 ( V_4 , V_17 [ V_18 ] ) ;
}
* V_4 = '\0' ;
}
void
F_10 ( const struct V_7 * V_1 , T_1 * V_4 )
{
F_12 ( ( const T_5 * ) V_1 , V_4 , V_9 ) ;
}
T_1 *
F_16 ( const T_8 V_20 , const T_2 * V_1 )
{
T_1 * V_4 ;
char * V_21 ;
V_21 = F_17 ( V_1 ) ;
if ( V_21 ) {
V_4 = F_18 ( L_3 , F_19 ( V_20 ) , V_21 ) ;
}
else {
V_4 = F_18 ( L_3 , F_19 ( V_20 ) ,
F_2 ( V_1 , 6 , '\0' ) ) ;
}
return V_4 ;
}
T_1 *
F_20 ( const T_2 * V_1 )
{
T_8 V_22 = F_21 ( V_1 ) ;
return F_22 ( V_22 , ' ' ) ;
}
T_1 *
F_22 ( const T_8 V_1 , const char V_23 )
{
T_1 * V_4 = F_6 ( 12 ) ;
* F_23 ( V_4 , V_1 , V_23 ) = '\0' ;
return V_4 ;
}
static void
F_24 ( const T_2 * V_24 , T_1 * V_4 , int V_12 )
{
if ( V_12 < 14 ) {
F_13 ( V_4 , V_19 , V_12 ) ;
return;
}
V_4 = F_25 ( V_4 , F_21 ( & V_24 [ 0 ] ) ) ;
* V_4 ++ = '.' ;
V_4 = F_26 ( V_4 , F_27 ( & V_24 [ 4 ] ) ) ;
* V_4 = '\0' ;
}
T_1 *
F_28 ( T_3 * V_2 , const T_4 V_3 )
{
T_1 * V_4 ;
V_4 = F_6 ( 214 ) ;
F_24 ( F_4 ( V_2 , V_3 , V_25 ) , V_4 , 214 ) ;
return V_4 ;
}
T_1 *
F_29 ( const T_9 V_1 ) {
T_1 * V_4 ;
T_2 * V_26 ;
V_26 = F_6 ( 8 ) ;
V_4 = F_6 ( V_27 ) ;
* ( T_9 * ) ( void * ) ( V_26 ) = F_30 ( & ( V_1 ) ) ;
F_31 ( V_4 , V_27 , L_4 ,
V_26 [ 0 ] , V_26 [ 1 ] , V_26 [ 2 ] , V_26 [ 3 ] ,
V_26 [ 4 ] , V_26 [ 5 ] , V_26 [ 6 ] , V_26 [ 7 ] ) ;
return V_4 ;
}
T_1 *
F_32 ( T_3 * V_2 , const T_4 V_3 , const T_7 V_28 )
{
if( V_28 )
{
return F_29 ( F_33 ( V_2 , V_3 ) ) ;
} else {
return F_29 ( F_34 ( V_2 , V_3 ) ) ;
}
}
static void
F_35 ( const T_2 * V_24 , T_1 * V_4 , int V_12 )
{
if( F_36 ( & V_24 [ 0 ] ) == 0xffffffff ) {
F_31 ( V_4 , V_12 , L_5 ) ;
} else {
F_31 ( V_4 , V_12 , L_6 , F_36 ( & V_24 [ 0 ] ) , F_36 ( & V_24 [ 4 ] ) ) ;
}
}
static void
F_37 ( const T_2 * V_29 , T_1 * V_4 , int V_12 ) {
T_2 V_30 ;
T_10 V_31 ;
T_10 V_32 ;
T_8 V_33 ;
V_33 = V_29 [ 0 ] ;
V_33 = ( V_33 << 8 ) ^ V_29 [ 1 ] ;
V_33 = ( V_33 << 8 ) ^ V_29 [ 2 ] ;
V_33 = ( V_33 << 8 ) ^ V_29 [ 3 ] ;
V_32 = V_33 & 0x0fff ;
V_33 = V_33 >> 12 ;
V_31 = V_33 & 0x0fff ;
V_33 = V_33 >> 12 ;
V_30 = V_33 & 0xff ;
F_31 ( V_4 , V_12 , L_7 , V_30 , V_31 , V_32 ) ;
}
static void
F_38 ( const T_11 * V_22 , T_1 * V_4 , int V_12 ) {
if ( V_22 -> V_14 >= 16 ) {
#define F_39 (sizeof("GID: ") - 1)
F_31 ( V_4 , V_12 , L_8 ) ;
if ( V_12 < ( int ) F_39 ||
F_40 ( V_34 , V_22 -> V_29 , V_4 + F_39 ,
V_12 - F_39 ) == NULL )
F_31 ( V_4 , V_12 , V_19 ) ;
} else {
T_10 V_35 ;
memcpy ( ( void * ) & V_35 , V_22 -> V_29 , sizeof V_35 ) ;
F_31 ( V_4 , V_12 , L_9 , V_35 ) ;
}
}
T_1 *
F_41 ( const T_2 * V_1 )
{
return F_2 ( V_1 , 3 , '.' ) ;
}
T_1 *
F_42 ( T_3 * V_2 , const T_4 V_3 )
{
return F_2 ( F_4 ( V_2 , V_3 , 3 ) , 3 , '.' ) ;
}
T_1 *
F_43 ( const T_2 * V_1 )
{
int V_36 ;
T_2 V_37 [ 6 ] ;
T_1 * V_38 ;
T_1 * V_39 ;
if ( V_1 == NULL ) return NULL ;
V_38 = F_6 ( 512 ) ;
V_39 = F_44 ( V_38 , V_1 , 8 , ':' ) ;
V_36 = ( V_1 [ 0 ] & 0xF0 ) >> 4 ;
switch ( V_36 ) {
case V_40 :
case V_41 :
memcpy ( V_37 , & V_1 [ 2 ] , 6 ) ;
F_31 ( V_39 , 512 - 23 , L_10 , F_45 ( V_37 ) ) ;
break;
case V_42 :
V_37 [ 0 ] = ( ( V_1 [ 0 ] & 0x0F ) << 4 ) | ( ( V_1 [ 1 ] & 0xF0 ) >> 4 ) ;
V_37 [ 1 ] = ( ( V_1 [ 1 ] & 0x0F ) << 4 ) | ( ( V_1 [ 2 ] & 0xF0 ) >> 4 ) ;
V_37 [ 2 ] = ( ( V_1 [ 2 ] & 0x0F ) << 4 ) | ( ( V_1 [ 3 ] & 0xF0 ) >> 4 ) ;
V_37 [ 3 ] = ( ( V_1 [ 3 ] & 0x0F ) << 4 ) | ( ( V_1 [ 4 ] & 0xF0 ) >> 4 ) ;
V_37 [ 4 ] = ( ( V_1 [ 4 ] & 0x0F ) << 4 ) | ( ( V_1 [ 5 ] & 0xF0 ) >> 4 ) ;
V_37 [ 5 ] = ( ( V_1 [ 5 ] & 0x0F ) << 4 ) | ( ( V_1 [ 6 ] & 0xF0 ) >> 4 ) ;
F_31 ( V_39 , 512 - 23 , L_10 , F_45 ( V_37 ) ) ;
break;
default:
* V_39 = '\0' ;
break;
}
return ( V_38 ) ;
}
T_1 *
F_46 ( T_3 * V_2 , const T_4 V_3 )
{
return F_43 ( F_4 ( V_2 , V_3 , 8 ) ) ;
}
T_1 *
F_47 ( const T_11 * V_22 )
{
T_1 * V_8 ;
V_8 = F_6 ( V_43 ) ;
F_48 ( V_22 , V_8 , V_43 ) ;
return V_8 ;
}
T_1 *
F_49 ( const T_11 * V_22 )
{
T_1 * V_8 ;
V_8 = F_50 ( V_43 ) ;
F_48 ( V_22 , V_8 , V_43 ) ;
return V_8 ;
}
void
F_48 ( const T_11 * V_22 , T_1 * V_4 , int V_12 )
{
const T_2 * V_44 ;
struct V_45 V_46 ;
char V_47 [ 32 ] ;
char * V_48 = V_47 ;
if ( ! V_4 || ! V_12 )
return;
switch( V_22 -> type ) {
case V_49 :
V_4 [ 0 ] = '\0' ;
break;
case V_50 :
V_48 = F_44 ( V_48 , V_22 -> V_29 , 6 , ':' ) ;
break;
case V_51 :
F_7 ( V_22 -> V_29 , V_4 , V_12 ) ;
break;
case V_52 :
F_12 ( V_22 -> V_29 , V_4 , V_12 ) ;
break;
case V_53 :
V_44 = V_22 -> V_29 ;
V_48 = F_51 ( V_48 , & V_44 [ 0 ] , 4 ) ;
* V_48 ++ = '.' ;
V_48 = F_51 ( V_48 , & V_44 [ 4 ] , 6 ) ;
break;
case V_54 :
F_52 ( V_22 , V_4 , V_12 ) ;
break;
case V_55 :
memcpy ( & V_46 , V_22 -> V_29 , sizeof V_46 ) ;
F_53 ( & V_46 , V_4 , V_12 ) ;
break;
case V_56 :
F_24 ( V_22 -> V_29 , V_4 , V_12 ) ;
break;
case V_57 :
F_35 ( V_22 -> V_29 , V_4 , V_12 ) ;
break;
case V_58 :
F_54 ( V_22 -> V_29 , V_22 -> V_14 , V_4 , V_12 ) ;
break;
case V_59 :
V_48 = F_14 ( V_48 , L_11 ) ;
V_48 = F_51 ( V_48 , V_22 -> V_29 , 1 ) ;
break;
case V_60 :
V_48 = F_44 ( V_48 , V_22 -> V_29 , 3 , '.' ) ;
break;
case V_61 :
F_55 ( ( const V_62 * ) V_22 -> V_29 , V_4 , V_12 ) ;
break;
case V_63 :
F_13 ( V_4 , V_22 -> V_29 , V_12 ) ;
break;
case V_64 :
V_48 = F_44 ( V_48 , V_22 -> V_29 , 8 , ':' ) ;
break;
case V_65 : {
int V_66 = V_22 -> V_14 < ( V_12 - 1 ) ? V_22 -> V_14 : ( V_12 - 1 ) ;
memcpy ( V_4 , V_22 -> V_29 , V_66 ) ;
V_4 [ V_66 ] = '\0' ;
}
break;
case V_67 :
F_37 ( V_22 -> V_29 , V_4 , V_12 ) ;
break;
case V_68 :
F_38 ( V_22 , V_4 , V_12 ) ;
break;
default:
F_56 () ;
}
if ( V_48 != V_47 ) {
T_6 V_69 = ( T_6 ) ( V_48 - V_47 ) ;
if ( V_69 < ( T_6 ) V_12 ) {
memcpy ( V_4 , V_47 , V_69 ) ;
V_4 [ V_69 ] = '\0' ;
} else
F_13 ( V_4 , V_19 , V_12 ) ;
}
}
