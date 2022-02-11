static void F_1 ( T_1 * V_1 , T_2 * V_2 ,
int V_3 ,
unsigned char * V_4 , int V_5 ,
const T_3 * V_6 )
{
if ( V_2 && V_2 -> V_7 ) {
V_2 -> V_7 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
}
}
static void
F_2 ( void * V_9 ,
T_4 * V_4 , T_5 V_5 ,
const T_3 * V_6 )
{
T_1 * V_1 = ( T_1 * ) V_9 ;
int V_10 , V_3 ;
int V_11 ;
T_6 V_12 ;
T_4 V_13 = FALSE , V_14 = FALSE ;
F_3 () ;
F_4 ( V_1 , V_15 , L_1
L_2 ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 0 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 1 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 2 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 3 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 4 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 5 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 6 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 7 ) & 0xFFFF ,
V_5 ) ;
V_3 = F_5 ( ( V_4 ) + sizeof( T_6 ) ) & 0xFF00 ;
V_11 = ( V_3 & 0x0F00 ) >> V_16 ;
V_12 = F_5 ( V_4 ) ;
if ( V_12 == V_17 )
{
#define F_6 14
T_4 V_18 ;
T_7 * V_19 ;
V_18 = ( F_5 ( V_4 + F_6 ) ) & 0xff ;
V_19 = V_1 -> V_19 [ V_18 ] ;
#ifdef F_7
if ( V_19 -> V_20 == V_21 )
{
T_4 * V_22 ;
V_22 = ( T_4 * ) V_6 -> V_23 [ 0 ] . V_24 + V_25 ;
F_4 ( V_1 , V_15 ,
L_3 ,
V_18 , V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] , V_22 [ 3 ] , V_22 [ 4 ] , V_22 [ 5 ] ) ;
F_8 ( V_1 , V_18 , V_22 ) ;
}
#endif
V_13 = F_9 ( V_1 , V_4 , V_6 , & V_14 , V_19 ) ;
F_4 ( V_1 , V_26 , L_4 , ( V_13 ) ? L_5 : L_6 ) ;
}
if ( V_13 )
{
if( V_4 != NULL && V_6 != NULL ) {
F_1 ( V_1 , V_1 -> V_27 , V_3 , V_4 , V_5 , V_6 ) ;
}
else{
F_10 ( V_1 , L_7 ) ;
}
#ifdef F_11
F_1 ( V_1 , V_1 -> V_28 ,
V_3 ,
V_4 , V_5 , V_6 ) ;
#endif
}
else
{
if ( ! V_3 ) {
if( V_12 == V_29 ) {
F_12 ( V_1 , V_4 , V_5 ) ;
}
else if ( V_12 != V_17 ) {
F_1 ( V_1 , V_1 -> V_27 , V_3 , V_4 , V_5 , V_6 ) ;
#ifdef F_11
F_1 ( V_1 , V_1 -> V_28 ,
V_3 ,
V_4 , V_5 , V_6 ) ;
#endif
}
else
{
#if ( F_13 ( F_7 ) && F_13 ( V_30 ) )
#define F_14 sizeof(CSR_SIGNAL_PRIMITIVE_HEADER) + 22
T_7 * V_19 ;
T_4 V_18 ;
T_8 V_31 = V_32 ;
V_18 = ( F_5 ( V_4 + F_6 ) ) & 0xff ;
V_19 = V_1 -> V_19 [ V_18 ] ;
V_31 = F_5 ( V_4 + F_14 ) ;
if ( ( ! V_14 ) &&
( V_19 -> V_20 == V_33 ) &&
( V_31 == V_34 ) &&
( ( V_1 -> V_35 == 1 )
#ifdef F_15
|| ( V_1 -> V_36 == 1 )
#endif
) )
{
T_9 signal ;
T_4 * V_37 ;
T_10 V_38 ;
T_8 V_18 = 0 ;
T_4 V_39 = TRUE ;
F_4 ( V_1 , V_26 , L_8 ) ;
V_38 = F_16 ( V_4 , & signal ) ;
if ( V_38 ) {
F_10 ( V_1 , L_9 ,
F_5 ( V_4 ) ) ;
return;
}
V_37 = ( T_4 * ) V_6 -> V_23 [ 0 ] . V_24 + V_40 ;
V_39 = ( V_37 [ 0 ] & 0x01 ) ? TRUE : FALSE ;
F_4 ( V_1 , V_26 ,
L_10 ,
( ( V_39 ) ? L_11 : L_12 ) ,
( ( V_1 -> V_35 ) ? L_13 : L_14 ) ,
( ( V_1 -> V_36 ) ? L_13 : L_14 ) ) ;
if ( ( ( V_39 ) && ( V_1 -> V_35 == 1 ) )
#ifdef F_15
|| ( ( ! V_39 ) && ( V_1 -> V_36 == 1 ) )
#endif
)
{
F_4 ( V_1 , V_41 , L_15 ) ;
F_17 ( V_1 -> V_42 , 0 , V_18 , V_5 , V_4 , V_6 -> V_23 [ 0 ] . V_43 , ( T_4 * ) V_6 -> V_23 [ 0 ] . V_24 ) ;
for ( V_10 = 0 ; V_10 < V_44 ; V_10 ++ ) {
if ( V_6 -> V_23 [ V_10 ] . V_43 != 0 ) {
F_18 ( V_1 , ( void * ) & V_6 -> V_23 [ V_10 ] ) ;
}
}
F_19 () ;
return;
}
}
#endif
}
}
if( ! V_14 ) {
if ( ( V_11 < V_45 ) &&
( & V_1 -> V_46 [ V_11 ] != V_1 -> V_47 ) ) {
F_4 ( V_1 , V_26 , L_16 ) ;
F_1 ( V_1 , & V_1 -> V_46 [ V_11 ] ,
V_3 ,
V_4 , V_5 , V_6 ) ;
}
}
}
switch ( V_12 )
{
#ifdef F_20
case V_48 :
#endif
break;
case V_17 :
if ( ! V_14 )
{
break;
}
default:
for ( V_10 = 0 ; V_10 < V_44 ; V_10 ++ ) {
if ( V_6 -> V_23 [ V_10 ] . V_43 != 0 ) {
F_18 ( V_1 , ( void * ) & V_6 -> V_23 [ V_10 ] ) ;
}
}
}
F_19 () ;
}
static T_4 F_21 ( T_1 * V_1 )
{
return ( ( ( V_1 -> V_49 . V_50 + 1 ) % V_1 -> V_49 . V_51 ) == ( V_1 -> V_49 . V_52 ) ) ;
}
void F_22 ( void * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 ;
F_3 () ;
F_4 ( V_1 , V_41 , L_17 ,
V_1 -> V_49 . V_52 , V_1 -> V_49 . V_50 ) ;
if( V_1 != NULL ) {
T_4 V_52 = V_1 -> V_49 . V_52 ;
while ( V_52 != V_1 -> V_49 . V_50 )
{
T_11 * V_53 = & V_1 -> V_49 . V_54 [ V_52 ] ;
F_4 ( V_1 , V_26 , L_17 ,
V_52 , V_1 -> V_49 . V_50 ) ;
F_2 ( V_1 , V_53 -> V_55 , V_53 -> V_56 , & V_53 -> V_57 ) ;
V_52 ++ ;
if( V_52 >= V_1 -> V_49 . V_51 ) {
V_52 = 0 ;
}
}
V_1 -> V_49 . V_52 = V_52 ;
}
F_19 () ;
}
void F_23 ( struct V_58 * V_59 )
{
T_1 * V_1 = F_24 ( V_59 , T_1 , V_60 ) ;
F_22 ( V_1 ) ;
}
void
F_25 ( void * V_9 ,
T_4 * V_4 , T_5 V_5 ,
const T_3 * V_6 )
{
#ifdef F_26
T_1 * V_1 = ( T_1 * ) V_9 ;
T_4 V_50 ;
int V_10 ;
T_11 * V_54 ;
F_3 () ;
F_4 ( V_1 , V_15 , L_18
L_2 ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 0 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 1 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 2 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 3 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 4 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 5 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 6 ) & 0xFFFF ,
F_5 ( ( V_4 ) + sizeof( T_6 ) * 7 ) & 0xFFFF , V_5 ) ;
if( F_21 ( V_1 ) ) {
F_10 ( V_1 , L_19 ) ;
for ( V_10 = 0 ; V_10 < V_44 ; V_10 ++ ) {
if ( V_6 -> V_23 [ V_10 ] . V_43 != 0 ) {
F_18 ( V_1 , ( void * ) & V_6 -> V_23 [ V_10 ] ) ;
}
}
return;
}
V_50 = V_1 -> V_49 . V_50 ;
V_54 = & V_1 -> V_49 . V_54 [ V_50 ] ;
memcpy ( V_54 -> V_55 , V_4 , V_5 ) ;
V_54 -> V_56 = V_5 ;
V_54 -> V_57 = * V_6 ;
V_50 ++ ;
if( V_50 >= V_1 -> V_49 . V_51 ) {
V_50 = 0 ;
}
F_4 ( V_1 , V_41 , L_20 , V_1 -> V_49 . V_50 ) ;
V_1 -> V_49 . V_50 = V_50 ;
#ifndef F_27
F_28 ( V_1 -> V_61 , & V_1 -> V_60 ) ;
#endif
#else
F_2 ( V_9 , V_4 , V_5 , V_6 ) ;
#endif
F_19 () ;
}
