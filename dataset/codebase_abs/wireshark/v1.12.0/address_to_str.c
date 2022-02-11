const T_1 *
F_1 ( const T_2 * V_1 )
{
return F_2 ( V_1 , 6 , ':' ) ;
}
const T_1 *
F_3 ( T_3 * V_2 , const T_4 V_3 )
{
return F_2 ( F_4 ( V_2 , V_3 , 6 ) , 6 , ':' ) ;
}
const T_1 *
F_5 ( const T_2 * V_1 ) {
T_1 * V_4 ;
V_4 = ( T_1 * ) F_6 ( V_5 ) ;
F_7 ( V_1 , V_4 , V_5 ) ;
return V_4 ;
}
const T_1 *
F_8 ( T_3 * V_2 , const T_4 V_3 )
{
T_1 * V_4 ;
V_4 = ( T_1 * ) F_6 ( V_5 ) ;
F_7 ( F_4 ( V_2 , V_3 , V_6 ) , V_4 , V_5 ) ;
return V_4 ;
}
const T_1 *
F_9 ( const struct V_7 * V_1 ) {
T_1 * V_8 ;
V_8 = ( T_1 * ) F_6 ( V_9 ) ;
F_10 ( V_1 , V_8 ) ;
return V_8 ;
}
const T_1 *
F_11 ( const T_2 * V_1 ) {
T_1 * V_8 ;
V_8 = ( T_1 * ) F_6 ( V_9 ) ;
F_12 ( ( const V_10 * ) V_1 , V_8 , V_9 ) ;
return V_8 ;
}
const T_1 *
F_13 ( T_3 * V_2 , const T_4 V_3 )
{
T_1 * V_4 ;
V_4 = ( T_1 * ) F_6 ( V_9 ) ;
F_10 ( ( const struct V_7 * ) F_4 ( V_2 , V_3 , V_11 ) , V_4 ) ;
return V_4 ;
}
static void
F_12 ( const V_10 * V_12 , char * V_4 , T_5 V_13 )
{
struct { int V_14 , V_15 ; } V_16 , V_17 ;
T_6 V_18 [ 8 ] ;
int V_19 ;
if ( V_13 < V_9 ) {
F_14 ( V_4 , V_20 , V_13 ) ;
return;
}
for ( V_19 = 0 ; V_19 < 16 ; V_19 += 2 ) {
V_18 [ V_19 / 2 ] = ( V_12 [ V_19 + 1 ] << 0 ) ;
V_18 [ V_19 / 2 ] |= ( V_12 [ V_19 ] << 8 ) ;
}
V_16 . V_14 = - 1 ; V_16 . V_15 = 0 ;
V_17 . V_14 = - 1 ; V_17 . V_15 = 0 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( V_18 [ V_19 ] == 0 ) {
if ( V_17 . V_14 == - 1 ) {
V_17 . V_14 = V_19 ;
V_17 . V_15 = 1 ;
} else
V_17 . V_15 ++ ;
} else {
if ( V_17 . V_14 != - 1 ) {
if ( V_16 . V_14 == - 1 || V_17 . V_15 > V_16 . V_15 )
V_16 = V_17 ;
V_17 . V_14 = - 1 ;
}
}
}
if ( V_17 . V_14 != - 1 ) {
if ( V_16 . V_14 == - 1 || V_17 . V_15 > V_16 . V_15 )
V_16 = V_17 ;
}
if ( V_16 . V_14 != - 1 && V_16 . V_15 < 2 )
V_16 . V_14 = - 1 ;
if ( V_16 . V_14 == 0 && ( V_16 . V_15 == 6 || ( V_16 . V_15 == 5 && V_18 [ 5 ] == 0xffff ) ) )
{
V_4 = F_15 ( V_4 , L_1 ) ;
if ( V_16 . V_15 == 5 )
V_4 = F_15 ( V_4 , L_2 ) ;
F_7 ( V_12 + 12 , V_4 , V_5 ) ;
return;
}
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
if ( V_19 == V_16 . V_14 ) {
* V_4 ++ = ':' ;
V_19 += V_16 . V_15 ;
if ( V_19 == 8 ) {
* V_4 ++ = ':' ;
break;
}
}
if ( V_19 != 0 )
* V_4 ++ = ':' ;
V_4 = F_16 ( V_4 , V_18 [ V_19 ] ) ;
}
* V_4 = '\0' ;
}
void
F_10 ( const struct V_7 * V_1 , T_1 * V_4 )
{
F_12 ( ( const V_10 * ) V_1 , V_4 , V_9 ) ;
}
T_1 *
F_17 ( const T_7 V_21 , const T_2 * V_1 )
{
T_1 * V_4 ;
char * V_22 ;
V_22 = F_18 ( V_1 ) ;
if ( V_22 ) {
V_4 = F_19 ( L_3 , F_20 ( V_21 ) , V_22 ) ;
}
else {
V_4 = F_19 ( L_3 , F_20 ( V_21 ) ,
F_2 ( V_1 , 6 , '\0' ) ) ;
}
return V_4 ;
}
T_1 *
F_21 ( const T_2 * V_1 )
{
T_7 V_23 = F_22 ( V_1 ) ;
return F_23 ( V_23 , ' ' ) ;
}
T_1 *
F_24 ( T_3 * V_2 , const T_4 V_3 )
{
return F_23 ( F_25 ( V_2 , V_3 ) , ' ' ) ;
}
T_1 *
F_23 ( const T_7 V_1 , const char V_24 )
{
T_1 * V_4 = ( T_1 * ) F_6 ( 12 ) ;
* F_26 ( V_4 , V_1 , V_24 ) = '\0' ;
return V_4 ;
}
static void
F_27 ( const T_2 * V_25 , T_1 * V_4 , int V_13 )
{
if ( V_13 < 14 ) {
F_14 ( V_4 , V_20 , V_13 ) ;
return;
}
V_4 = F_28 ( V_4 , F_22 ( & V_25 [ 0 ] ) ) ;
* V_4 ++ = '.' ;
V_4 = F_29 ( V_4 , F_30 ( & V_25 [ 4 ] ) ) ;
* V_4 = '\0' ;
}
T_1 *
F_31 ( T_3 * V_2 , const T_4 V_3 )
{
T_1 * V_4 ;
V_4 = ( T_1 * ) F_6 ( 214 ) ;
F_27 ( F_4 ( V_2 , V_3 , V_26 ) , V_4 , 214 ) ;
return V_4 ;
}
T_1 *
F_32 ( const T_8 V_1 ) {
T_1 * V_4 ;
T_2 * V_27 ;
V_27 = ( T_2 * ) F_6 ( 8 ) ;
V_4 = ( T_1 * ) F_6 ( V_28 ) ;
* ( T_8 * ) ( void * ) ( V_27 ) = F_33 ( & ( V_1 ) ) ;
F_34 ( V_4 , V_28 , L_4 ,
V_27 [ 0 ] , V_27 [ 1 ] , V_27 [ 2 ] , V_27 [ 3 ] ,
V_27 [ 4 ] , V_27 [ 5 ] , V_27 [ 6 ] , V_27 [ 7 ] ) ;
return V_4 ;
}
T_1 *
F_35 ( T_3 * V_2 , const T_4 V_3 , const T_6 V_29 )
{
if( V_29 )
{
return F_32 ( F_36 ( V_2 , V_3 ) ) ;
} else {
return F_32 ( F_37 ( V_2 , V_3 ) ) ;
}
}
static void
F_38 ( const T_2 * V_25 , T_1 * V_4 , int V_13 )
{
if( F_39 ( & V_25 [ 0 ] ) == 0xffffffff ) {
F_34 ( V_4 , V_13 , L_5 ) ;
} else {
F_34 ( V_4 , V_13 , L_6 , F_39 ( & V_25 [ 0 ] ) , F_39 ( & V_25 [ 4 ] ) ) ;
}
}
static void
F_40 ( const T_2 * V_30 , T_1 * V_4 , int V_13 ) {
T_2 V_31 ;
T_9 V_32 ;
T_9 V_33 ;
T_7 V_34 ;
V_34 = V_30 [ 0 ] ;
V_34 = ( V_34 << 8 ) ^ V_30 [ 1 ] ;
V_34 = ( V_34 << 8 ) ^ V_30 [ 2 ] ;
V_34 = ( V_34 << 8 ) ^ V_30 [ 3 ] ;
V_33 = V_34 & 0x0fff ;
V_34 = V_34 >> 12 ;
V_32 = V_34 & 0x0fff ;
V_34 = V_34 >> 12 ;
V_31 = V_34 & 0xff ;
F_34 ( V_4 , V_13 , L_7 , V_31 , V_32 , V_33 ) ;
}
static void
F_41 ( const T_10 * V_23 , T_1 * V_4 , int V_13 ) {
if ( V_23 -> V_15 >= 16 ) {
#define F_42 ((int)(sizeof("GID: ") - 1))
F_34 ( V_4 , V_13 , L_8 ) ;
if ( V_13 < F_42 ||
F_43 ( V_35 , V_23 -> V_30 , V_4 + F_42 ,
V_13 - F_42 ) == NULL )
F_34 ( V_4 , V_13 , V_20 ) ;
} else {
T_9 V_36 ;
memcpy ( ( void * ) & V_36 , V_23 -> V_30 , sizeof V_36 ) ;
F_34 ( V_4 , V_13 , L_9 , V_36 ) ;
}
}
const T_1 *
F_44 ( const T_2 * V_1 )
{
return F_2 ( V_1 , 3 , '.' ) ;
}
const T_1 *
F_45 ( T_3 * V_2 , const T_4 V_3 )
{
return F_2 ( F_4 ( V_2 , V_3 , 3 ) , 3 , '.' ) ;
}
T_1 *
F_46 ( const T_2 * V_1 )
{
int V_37 ;
T_2 V_38 [ 6 ] ;
T_1 * V_39 ;
T_1 * V_40 ;
if ( V_1 == NULL ) return NULL ;
V_39 = ( T_1 * ) F_6 ( 512 ) ;
V_40 = F_47 ( V_39 , V_1 , 8 , ':' ) ;
V_37 = ( V_1 [ 0 ] & 0xF0 ) >> 4 ;
switch ( V_37 ) {
case V_41 :
case V_42 :
memcpy ( V_38 , & V_1 [ 2 ] , 6 ) ;
F_34 ( V_40 , 512 - 23 , L_10 , F_48 ( V_38 ) ) ;
break;
case V_43 :
V_38 [ 0 ] = ( ( V_1 [ 0 ] & 0x0F ) << 4 ) | ( ( V_1 [ 1 ] & 0xF0 ) >> 4 ) ;
V_38 [ 1 ] = ( ( V_1 [ 1 ] & 0x0F ) << 4 ) | ( ( V_1 [ 2 ] & 0xF0 ) >> 4 ) ;
V_38 [ 2 ] = ( ( V_1 [ 2 ] & 0x0F ) << 4 ) | ( ( V_1 [ 3 ] & 0xF0 ) >> 4 ) ;
V_38 [ 3 ] = ( ( V_1 [ 3 ] & 0x0F ) << 4 ) | ( ( V_1 [ 4 ] & 0xF0 ) >> 4 ) ;
V_38 [ 4 ] = ( ( V_1 [ 4 ] & 0x0F ) << 4 ) | ( ( V_1 [ 5 ] & 0xF0 ) >> 4 ) ;
V_38 [ 5 ] = ( ( V_1 [ 5 ] & 0x0F ) << 4 ) | ( ( V_1 [ 6 ] & 0xF0 ) >> 4 ) ;
F_34 ( V_40 , 512 - 23 , L_10 , F_48 ( V_38 ) ) ;
break;
default:
* V_40 = '\0' ;
break;
}
return ( V_39 ) ;
}
T_1 *
F_49 ( T_3 * V_2 , const T_4 V_3 )
{
return F_46 ( F_4 ( V_2 , V_3 , 8 ) ) ;
}
const T_1 *
F_50 ( const T_2 * V_1 )
{
return F_2 ( V_1 , 7 , ':' ) ;
}
T_1 *
F_51 ( const T_2 * V_1 )
{
T_10 V_23 ;
V_23 . type = V_44 ;
V_23 . V_15 = 7 ;
V_23 . V_30 = V_1 ;
return F_52 ( & V_23 ) ;
}
T_1 *
F_53 ( T_11 * V_45 , const T_10 * V_23 )
{
T_1 * V_8 ;
V_8 = ( T_1 * ) F_54 ( V_45 , V_46 ) ;
F_55 ( V_23 , V_8 , V_46 ) ;
return V_8 ;
}
T_1 *
F_52 ( const T_10 * V_23 )
{
T_1 * V_8 ;
V_8 = ( T_1 * ) F_6 ( V_46 ) ;
F_55 ( V_23 , V_8 , V_46 ) ;
return V_8 ;
}
void
F_55 ( const T_10 * V_23 , T_1 * V_4 , int V_13 )
{
const T_2 * V_47 ;
struct V_48 V_49 ;
T_9 V_50 ;
char V_51 [ 32 ] ;
char * V_52 = V_51 ;
if ( ! V_4 || ! V_13 )
return;
switch( V_23 -> type ) {
case V_53 :
V_4 [ 0 ] = '\0' ;
break;
case V_54 :
V_52 = F_47 ( V_52 , ( const T_2 * ) V_23 -> V_30 , 6 , ':' ) ;
break;
case V_55 :
F_7 ( ( const T_2 * ) V_23 -> V_30 , V_4 , V_13 ) ;
break;
case V_56 :
F_12 ( ( const V_10 * ) V_23 -> V_30 , V_4 , V_13 ) ;
break;
case V_57 :
V_47 = ( const T_2 * ) V_23 -> V_30 ;
V_52 = F_56 ( V_52 , & V_47 [ 0 ] , 4 ) ;
* V_52 ++ = '.' ;
V_52 = F_56 ( V_52 , & V_47 [ 4 ] , 6 ) ;
break;
case V_58 :
F_57 ( V_23 , V_4 , V_13 ) ;
break;
case V_59 :
memcpy ( & V_49 , V_23 -> V_30 , sizeof V_49 ) ;
F_58 ( & V_49 , V_4 , V_13 ) ;
break;
case V_60 :
F_27 ( ( const T_2 * ) V_23 -> V_30 , V_4 , V_13 ) ;
break;
case V_61 :
F_38 ( ( const T_2 * ) V_23 -> V_30 , V_4 , V_13 ) ;
break;
case V_62 :
F_59 ( ( const T_2 * ) V_23 -> V_30 , V_23 -> V_15 , V_4 , V_13 ) ;
break;
case V_63 :
V_52 = F_15 ( V_52 , L_11 ) ;
V_52 = F_56 ( V_52 , ( const T_2 * ) V_23 -> V_30 , 1 ) ;
break;
case V_64 :
V_52 = F_47 ( V_52 , ( const T_2 * ) V_23 -> V_30 , 3 , '.' ) ;
break;
case V_65 :
F_60 ( ( const V_66 * ) V_23 -> V_30 , V_4 , V_13 ) ;
break;
case V_67 :
F_14 ( V_4 , ( const T_1 * ) V_23 -> V_30 , V_13 ) ;
break;
case V_68 :
V_52 = F_47 ( V_52 , ( const T_2 * ) V_23 -> V_30 , 8 , ':' ) ;
break;
case V_69 : {
int V_70 = V_23 -> V_15 < ( V_13 - 1 ) ? V_23 -> V_15 : ( V_13 - 1 ) ;
memcpy ( V_4 , V_23 -> V_30 , V_70 ) ;
V_4 [ V_70 ] = '\0' ;
}
break;
case V_71 :
F_40 ( ( const T_2 * ) V_23 -> V_30 , V_4 , V_13 ) ;
break;
case V_72 :
F_41 ( V_23 , V_4 , V_13 ) ;
break;
case V_44 :
V_47 = ( const T_2 * ) V_23 -> V_30 ;
F_34 ( V_4 , V_13 , L_12 ,
( V_47 [ 0 ] >> 1 ) & 0x7f , ( V_47 [ 1 ] >> 1 ) & 0x7f , ( V_47 [ 2 ] >> 1 ) & 0x7f ,
( V_47 [ 3 ] >> 1 ) & 0x7f , ( V_47 [ 4 ] >> 1 ) & 0x7f , ( V_47 [ 5 ] >> 1 ) & 0x7f ,
( V_47 [ 6 ] >> 1 ) & 0x0f ) ;
break;
case V_73 :
V_50 = F_61 ( V_23 -> V_30 ) ;
if ( V_50 == 0xffff )
F_34 ( V_4 , V_13 , L_13 ) ;
else
F_34 ( V_4 , V_13 , L_14 , V_50 ) ;
break;
case V_74 :
V_47 = ( const T_2 * ) V_23 -> V_30 ;
F_34 ( V_4 , V_13 , L_15 , V_47 [ 0 ] ) ;
break;
case V_75 :
V_47 = ( const T_2 * ) V_23 -> V_30 ;
F_34 ( V_4 , V_13 , L_15 , V_47 [ 0 ] & 0x3f ) ;
break;
default:
F_62 () ;
}
if ( V_52 != V_51 ) {
T_5 V_76 = ( T_5 ) ( V_52 - V_51 ) ;
if ( V_76 < ( T_5 ) V_13 ) {
memcpy ( V_4 , V_51 , V_76 ) ;
V_4 [ V_76 ] = '\0' ;
} else
F_14 ( V_4 , V_20 , V_13 ) ;
}
}
