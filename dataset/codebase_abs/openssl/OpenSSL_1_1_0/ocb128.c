static T_1 F_1 ( T_2 V_1 )
{
T_1 V_2 = 0 ;
while ( ! ( V_1 & 1 ) ) {
V_1 >>= 1 ;
V_2 ++ ;
}
return V_2 ;
}
static void F_2 ( const unsigned char * V_3 , T_3 V_4 ,
unsigned char * V_5 )
{
unsigned char V_6 ;
int V_7 ;
unsigned char V_8 [ 15 ] ;
V_6 = 0xff ;
V_6 <<= ( 8 - V_4 ) ;
for ( V_7 = 15 ; V_7 >= 0 ; V_7 -- ) {
if ( V_7 > 0 ) {
V_8 [ V_7 - 1 ] = V_3 [ V_7 ] & V_6 ;
V_8 [ V_7 - 1 ] >>= 8 - V_4 ;
}
V_5 [ V_7 ] = V_3 [ V_7 ] << V_4 ;
if ( V_7 != 15 ) {
V_5 [ V_7 ] ^= V_8 [ V_7 ] ;
}
}
}
static void F_3 ( T_4 * V_3 , T_4 * V_5 )
{
unsigned char V_8 ;
V_8 = V_3 -> V_9 [ 0 ] & 0x80 ;
V_8 >>= 7 ;
V_8 *= 135 ;
F_2 ( V_3 -> V_9 , 1 , V_5 -> V_9 ) ;
V_5 -> V_9 [ 15 ] ^= V_8 ;
}
static void F_4 ( const unsigned char * V_10 ,
const unsigned char * V_11 , T_3 V_12 ,
unsigned char * V_5 )
{
T_3 V_7 ;
for ( V_7 = 0 ; V_7 < V_12 ; V_7 ++ ) {
V_5 [ V_7 ] = V_10 [ V_7 ] ^ V_11 [ V_7 ] ;
}
}
static T_4 * F_5 ( T_5 * V_13 , T_3 V_14 )
{
T_3 V_15 = V_13 -> V_15 ;
if ( V_14 <= V_15 ) {
return V_13 -> V_16 + V_14 ;
}
if ( V_14 >= V_13 -> V_17 ) {
void * V_18 ;
V_13 -> V_17 += ( V_14 - V_13 -> V_17 + 4 ) & ~ 3 ;
V_18 =
F_6 ( V_13 -> V_16 , V_13 -> V_17 * sizeof( T_4 ) ) ;
if ( V_18 == NULL )
return NULL ;
V_13 -> V_16 = V_18 ;
}
while ( V_15 < V_14 ) {
F_3 ( V_13 -> V_16 + V_15 , V_13 -> V_16 + V_15 + 1 ) ;
V_15 ++ ;
}
V_13 -> V_15 = V_15 ;
return V_13 -> V_16 + V_14 ;
}
T_5 * F_7 ( void * V_19 , void * V_20 ,
T_6 V_21 , T_6 V_22 ,
T_7 V_23 )
{
T_5 * V_24 ;
int V_25 ;
if ( ( V_24 = F_8 ( sizeof( * V_24 ) ) ) != NULL ) {
V_25 = F_9 ( V_24 , V_19 , V_20 , V_21 , V_22 ,
V_23 ) ;
if ( V_25 )
return V_24 ;
F_10 ( V_24 ) ;
}
return NULL ;
}
int F_9 ( T_5 * V_13 , void * V_19 , void * V_20 ,
T_6 V_21 , T_6 V_22 ,
T_7 V_23 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_15 = 0 ;
V_13 -> V_17 = 5 ;
V_13 -> V_16 = F_8 ( V_13 -> V_17 * 16 ) ;
if ( V_13 -> V_16 == NULL )
return 0 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_22 = V_22 ;
V_13 -> V_23 = V_23 ;
V_13 -> V_19 = V_19 ;
V_13 -> V_20 = V_20 ;
V_13 -> V_21 ( V_13 -> V_26 . V_9 , V_13 -> V_26 . V_9 , V_13 -> V_19 ) ;
F_3 ( & V_13 -> V_26 , & V_13 -> V_27 ) ;
F_3 ( & V_13 -> V_27 , V_13 -> V_16 ) ;
F_3 ( V_13 -> V_16 , V_13 -> V_16 + 1 ) ;
F_3 ( V_13 -> V_16 + 1 , V_13 -> V_16 + 2 ) ;
F_3 ( V_13 -> V_16 + 2 , V_13 -> V_16 + 3 ) ;
F_3 ( V_13 -> V_16 + 3 , V_13 -> V_16 + 4 ) ;
V_13 -> V_15 = 4 ;
return 1 ;
}
int F_11 ( T_5 * V_28 , T_5 * V_29 ,
void * V_19 , void * V_20 )
{
memcpy ( V_28 , V_29 , sizeof( T_5 ) ) ;
if ( V_19 )
V_28 -> V_19 = V_19 ;
if ( V_20 )
V_28 -> V_20 = V_20 ;
if ( V_29 -> V_16 ) {
V_28 -> V_16 = F_8 ( V_29 -> V_17 * 16 ) ;
if ( V_28 -> V_16 == NULL )
return 0 ;
memcpy ( V_28 -> V_16 , V_29 -> V_16 , ( V_29 -> V_15 + 1 ) * 16 ) ;
}
return 1 ;
}
int F_12 ( T_5 * V_13 , const unsigned char * V_30 ,
T_3 V_12 , T_3 V_31 )
{
unsigned char V_32 [ 16 ] , V_33 [ 16 ] , V_8 ;
unsigned char V_34 [ 24 ] , V_35 [ 16 ] ;
T_3 V_36 , V_4 ;
if ( ( V_12 > 15 ) || ( V_12 < 1 ) || ( V_31 > 16 ) || ( V_31 < 1 ) ) {
return - 1 ;
}
V_35 [ 0 ] = ( ( V_31 * 8 ) % 128 ) << 1 ;
memset ( V_35 + 1 , 0 , 15 ) ;
memcpy ( V_35 + 16 - V_12 , V_30 , V_12 ) ;
V_35 [ 15 - V_12 ] |= 1 ;
memcpy ( V_33 , V_35 , 16 ) ;
V_33 [ 15 ] &= 0xc0 ;
V_13 -> V_21 ( V_33 , V_32 , V_13 -> V_19 ) ;
memcpy ( V_34 , V_32 , 16 ) ;
F_4 ( V_32 , V_32 + 1 , 8 , V_34 + 16 ) ;
V_36 = V_35 [ 15 ] & 0x3f ;
V_4 = V_36 % 8 ;
F_2 ( V_34 + ( V_36 / 8 ) , V_4 , V_13 -> V_37 . V_9 ) ;
V_8 = 0xff ;
V_8 <<= 8 - V_4 ;
V_13 -> V_37 . V_9 [ 15 ] |=
( * ( V_34 + ( V_36 / 8 ) + 16 ) & V_8 ) >> ( 8 - V_4 ) ;
return 1 ;
}
int F_13 ( T_5 * V_13 , const unsigned char * V_38 ,
T_3 V_12 )
{
T_2 V_7 , V_39 ;
T_3 V_40 , V_41 ;
T_4 V_42 ;
T_4 V_43 ;
V_40 = V_12 / 16 ;
V_39 = V_40 + V_13 -> V_44 ;
for ( V_7 = V_13 -> V_44 + 1 ; V_7 <= V_39 ; V_7 ++ ) {
T_4 * V_45 ;
T_4 * V_46 ;
V_45 = F_5 ( V_13 , F_1 ( V_7 ) ) ;
if ( V_45 == NULL )
return 0 ;
F_14 ( & V_13 -> V_47 , V_45 , & V_13 -> V_47 ) ;
V_46 = ( T_4 * ) ( V_38 + ( ( V_7 - V_13 -> V_44 - 1 ) * 16 ) ) ;
F_14 ( & V_13 -> V_47 , V_46 , & V_42 ) ;
V_13 -> V_21 ( V_42 . V_9 , V_43 . V_9 , V_13 -> V_19 ) ;
F_14 ( & V_13 -> V_48 , & V_43 , & V_13 -> V_48 ) ;
}
V_41 = V_12 % 16 ;
if ( V_41 > 0 ) {
F_14 ( & V_13 -> V_47 , & V_13 -> V_26 , & V_13 -> V_47 ) ;
memset ( & V_42 , 0 , 16 ) ;
memcpy ( & V_42 , V_38 + ( V_40 * 16 ) , V_41 ) ;
( ( unsigned char * ) & V_42 ) [ V_41 ] = 0x80 ;
F_14 ( & V_13 -> V_47 , & V_42 , & V_43 ) ;
V_13 -> V_21 ( V_43 . V_9 , V_42 . V_9 , V_13 -> V_19 ) ;
F_14 ( & V_13 -> V_48 , & V_42 , & V_13 -> V_48 ) ;
}
V_13 -> V_44 = V_39 ;
return 1 ;
}
int F_15 ( T_5 * V_13 ,
const unsigned char * V_3 , unsigned char * V_5 ,
T_3 V_12 )
{
T_2 V_7 , V_39 ;
T_3 V_40 , V_41 ;
T_4 V_42 ;
T_4 V_43 ;
T_4 V_49 ;
V_40 = V_12 / 16 ;
V_39 = V_40 + V_13 -> V_50 ;
if ( V_40 && V_39 == ( T_3 ) V_39
&& V_13 -> V_23 != NULL ) {
T_3 V_51 = 0 , V_52 = ( T_3 ) V_39 ;
while ( V_52 >>= 1 )
V_51 ++ ;
if ( F_5 ( V_13 , V_51 ) == NULL )
return 0 ;
V_13 -> V_23 ( V_3 , V_5 , V_40 , V_13 -> V_19 ,
( T_3 ) V_13 -> V_50 + 1 , V_13 -> V_37 . V_9 ,
( const unsigned char ( * ) [ 16 ] ) V_13 -> V_16 , V_13 -> V_53 . V_9 ) ;
} else {
for ( V_7 = V_13 -> V_50 + 1 ; V_7 <= V_39 ; V_7 ++ ) {
T_4 * V_45 ;
T_4 * V_54 ;
T_4 * V_55 ;
V_45 = F_5 ( V_13 , F_1 ( V_7 ) ) ;
if ( V_45 == NULL )
return 0 ;
F_14 ( & V_13 -> V_37 , V_45 , & V_13 -> V_37 ) ;
V_54 =
( T_4 * ) ( V_3 + ( ( V_7 - V_13 -> V_50 - 1 ) * 16 ) ) ;
F_16 ( & V_13 -> V_37 , V_54 , & V_42 ) ;
F_16 ( & V_13 -> V_53 , V_54 , & V_13 -> V_53 ) ;
V_13 -> V_21 ( V_42 . V_9 , V_43 . V_9 , V_13 -> V_19 ) ;
V_55 =
( T_4 * ) ( V_5 + ( ( V_7 - V_13 -> V_50 - 1 ) * 16 ) ) ;
F_16 ( & V_13 -> V_37 , & V_43 , V_55 ) ;
}
}
V_41 = V_12 % 16 ;
if ( V_41 > 0 ) {
F_14 ( & V_13 -> V_37 , & V_13 -> V_26 , & V_13 -> V_37 ) ;
V_13 -> V_21 ( V_13 -> V_37 . V_9 , V_49 . V_9 , V_13 -> V_19 ) ;
F_4 ( V_3 + ( V_12 / 16 ) * 16 , ( unsigned char * ) & V_49 , V_41 ,
V_5 + ( V_40 * 16 ) ) ;
memset ( & V_42 , 0 , 16 ) ;
memcpy ( & V_42 , V_3 + ( V_12 / 16 ) * 16 , V_41 ) ;
( ( unsigned char * ) ( & V_42 ) ) [ V_41 ] = 0x80 ;
F_14 ( & V_13 -> V_53 , & V_42 , & V_13 -> V_53 ) ;
}
V_13 -> V_50 = V_39 ;
return 1 ;
}
int F_17 ( T_5 * V_13 ,
const unsigned char * V_3 , unsigned char * V_5 ,
T_3 V_12 )
{
T_2 V_7 , V_39 ;
T_3 V_40 , V_41 ;
T_4 V_42 ;
T_4 V_43 ;
T_4 V_49 ;
V_40 = V_12 / 16 ;
V_39 = V_40 + V_13 -> V_50 ;
if ( V_40 && V_39 == ( T_3 ) V_39
&& V_13 -> V_23 != NULL ) {
T_3 V_51 = 0 , V_52 = ( T_3 ) V_39 ;
while ( V_52 >>= 1 )
V_51 ++ ;
if ( F_5 ( V_13 , V_51 ) == NULL )
return 0 ;
V_13 -> V_23 ( V_3 , V_5 , V_40 , V_13 -> V_20 ,
( T_3 ) V_13 -> V_50 + 1 , V_13 -> V_37 . V_9 ,
( const unsigned char ( * ) [ 16 ] ) V_13 -> V_16 , V_13 -> V_53 . V_9 ) ;
} else {
for ( V_7 = V_13 -> V_50 + 1 ; V_7 <= V_39 ; V_7 ++ ) {
T_4 * V_54 ;
T_4 * V_55 ;
T_4 * V_45 = F_5 ( V_13 , F_1 ( V_7 ) ) ;
if ( V_45 == NULL )
return 0 ;
F_14 ( & V_13 -> V_37 , V_45 , & V_13 -> V_37 ) ;
V_54 =
( T_4 * ) ( V_3 + ( ( V_7 - V_13 -> V_50 - 1 ) * 16 ) ) ;
F_16 ( & V_13 -> V_37 , V_54 , & V_42 ) ;
V_13 -> V_22 ( V_42 . V_9 , V_43 . V_9 , V_13 -> V_20 ) ;
V_55 =
( T_4 * ) ( V_5 + ( ( V_7 - V_13 -> V_50 - 1 ) * 16 ) ) ;
F_16 ( & V_13 -> V_37 , & V_43 , V_55 ) ;
F_16 ( & V_13 -> V_53 , V_55 , & V_13 -> V_53 ) ;
}
}
V_41 = V_12 % 16 ;
if ( V_41 > 0 ) {
F_14 ( & V_13 -> V_37 , & V_13 -> V_26 , & V_13 -> V_37 ) ;
V_13 -> V_21 ( V_13 -> V_37 . V_9 , V_49 . V_9 , V_13 -> V_19 ) ;
F_4 ( V_3 + ( V_12 / 16 ) * 16 , ( unsigned char * ) & V_49 , V_41 ,
V_5 + ( V_40 * 16 ) ) ;
memset ( & V_42 , 0 , 16 ) ;
memcpy ( & V_42 , V_5 + ( V_12 / 16 ) * 16 , V_41 ) ;
( ( unsigned char * ) ( & V_42 ) ) [ V_41 ] = 0x80 ;
F_14 ( & V_13 -> V_53 , & V_42 , & V_13 -> V_53 ) ;
}
V_13 -> V_50 = V_39 ;
return 1 ;
}
int F_18 ( T_5 * V_13 , const unsigned char * V_56 ,
T_3 V_12 )
{
T_4 V_42 , V_43 ;
F_14 ( & V_13 -> V_53 , & V_13 -> V_37 , & V_42 ) ;
F_14 ( & V_42 , & V_13 -> V_27 , & V_43 ) ;
V_13 -> V_21 ( V_43 . V_9 , V_42 . V_9 , V_13 -> V_19 ) ;
F_14 ( & V_42 , & V_13 -> V_48 , & V_13 -> V_56 ) ;
if ( V_12 > 16 || V_12 < 1 ) {
return - 1 ;
}
if ( V_56 )
return F_19 ( & V_13 -> V_56 , V_56 , V_12 ) ;
else
return - 1 ;
}
int F_20 ( T_5 * V_13 , unsigned char * V_56 , T_3 V_12 )
{
if ( V_12 > 16 || V_12 < 1 ) {
return - 1 ;
}
F_18 ( V_13 , NULL , 0 ) ;
memcpy ( V_56 , & V_13 -> V_56 , V_12 ) ;
return 1 ;
}
void F_21 ( T_5 * V_13 )
{
if ( V_13 ) {
F_22 ( V_13 -> V_16 , V_13 -> V_17 * 16 ) ;
F_23 ( V_13 , sizeof( * V_13 ) ) ;
}
}
