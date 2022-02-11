T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ;
if ( V_3 == NULL ) return ( 0 ) ;
V_3 -> V_4 = 0 ;
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 1 ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 1 ;
F_4 ( & V_3 -> V_12 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = ( char * ) V_3 ;
V_2 -> V_15 = 0 ;
return ( 1 ) ;
}
static int F_5 ( T_2 * V_16 )
{
if ( V_16 == NULL ) return ( 0 ) ;
F_6 ( & ( ( T_3 * ) V_16 -> V_14 ) -> V_12 ) ;
F_7 ( V_16 -> V_14 , sizeof( T_3 ) ) ;
F_8 ( V_16 -> V_14 ) ;
V_16 -> V_14 = NULL ;
V_16 -> V_13 = 0 ;
V_16 -> V_15 = 0 ;
return ( 1 ) ;
}
static int F_9 ( T_2 * V_17 , char * V_18 , int V_19 )
{
int V_20 = 0 , V_21 , V_22 ;
T_3 * V_3 ;
if ( V_18 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_17 -> V_14 ;
if ( ( V_3 == NULL ) || ( V_17 -> V_23 == NULL ) || ( V_17 -> V_13 == 0 ) ) return ( 0 ) ;
while( V_19 > 0 )
{
if ( V_3 -> V_10 )
{
V_21 = V_3 -> V_4 - V_3 -> V_5 ;
if ( V_21 > V_19 ) V_21 = V_19 ;
memcpy ( V_18 , & ( V_3 -> V_24 [ V_3 -> V_5 ] ) , V_21 ) ;
V_20 += V_21 ;
V_18 += V_21 ;
V_19 -= V_21 ;
V_3 -> V_5 += V_21 ;
if ( V_3 -> V_4 == V_3 -> V_5 )
{
V_3 -> V_5 = 0 ;
if( V_3 -> V_6 - V_3 -> V_7 > 0 )
{
V_3 -> V_4 = V_3 -> V_6 - V_3 -> V_7 ;
memmove ( V_3 -> V_24 , & ( V_3 -> V_24 [ V_3 -> V_7 ] ) ,
V_3 -> V_4 ) ;
}
else
{
V_3 -> V_4 = 0 ;
}
V_3 -> V_10 = 0 ;
}
}
if ( V_19 == 0 ) break;
V_22 = V_25 - V_3 -> V_4 ;
V_21 = F_10 ( V_17 -> V_23 , & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , V_22 ) ;
if ( V_21 <= 0 ) break;
V_3 -> V_4 += V_21 ;
if ( V_3 -> V_11 == 1 ) F_11 ( V_17 ) ;
if ( V_3 -> V_11 == 0 ) F_12 ( V_17 ) ;
if ( V_3 -> V_8 <= 0 ) break;
}
F_13 ( V_17 ) ;
F_14 ( V_17 ) ;
return ( V_20 ) ;
}
static int F_15 ( T_2 * V_17 , const char * V_26 , int V_27 )
{
int V_20 = 0 , V_22 , V_21 ;
T_3 * V_3 ;
if ( V_27 <= 0 ) return V_27 ;
V_3 = ( T_3 * ) V_17 -> V_14 ;
V_20 = V_27 ;
if ( ( V_3 == NULL ) || ( V_17 -> V_23 == NULL ) || ( V_17 -> V_13 == 0 ) ) return ( 0 ) ;
if( V_3 -> V_11 ) F_16 ( V_17 ) ;
do{
F_13 ( V_17 ) ;
V_22 = V_3 -> V_4 - V_3 -> V_5 ;
while ( V_3 -> V_10 && V_22 > 0 )
{
V_21 = F_17 ( V_17 -> V_23 , & ( V_3 -> V_24 [ V_3 -> V_5 ] ) , V_22 ) ;
if ( V_21 <= 0 )
{
F_14 ( V_17 ) ;
if( ! F_18 ( V_17 ) )
V_3 -> V_8 = 0 ;
return ( V_21 ) ;
}
V_3 -> V_5 += V_21 ;
V_22 -= V_21 ;
}
V_3 -> V_10 = 0 ;
if ( V_3 -> V_4 == V_3 -> V_5 )
{
V_3 -> V_4 = V_28 ;
V_3 -> V_5 = 0 ;
}
if ( ( V_26 == NULL ) || ( V_27 <= 0 ) ) return ( 0 ) ;
V_22 = ( V_27 + V_3 -> V_4 > V_29 + V_28 ) ?
( int ) ( V_29 + V_28 - V_3 -> V_4 ) : V_27 ;
memcpy ( ( unsigned char * ) ( & ( V_3 -> V_24 [ V_3 -> V_4 ] ) ) , ( unsigned char * ) V_26 , V_22 ) ;
V_3 -> V_4 += V_22 ;
V_27 -= V_22 ;
V_26 += V_22 ;
if( V_3 -> V_4 >= V_29 + V_28 )
{
F_19 ( V_17 ) ;
}
}while( V_27 > 0 );
F_13 ( V_17 ) ;
F_14 ( V_17 ) ;
return ( V_20 ) ;
}
static long F_20 ( T_2 * V_17 , int V_30 , long V_31 , void * V_14 )
{
T_3 * V_3 ;
T_4 * V_12 ;
const T_4 * * V_32 ;
long V_20 = 1 ;
int V_21 ;
V_3 = V_17 -> V_14 ;
switch ( V_30 )
{
case V_33 :
V_3 -> V_4 = 0 ;
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 1 ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 1 ;
V_20 = F_21 ( V_17 -> V_23 , V_30 , V_31 , V_14 ) ;
break;
case V_34 :
if ( V_3 -> V_8 <= 0 )
V_20 = 1 ;
else
V_20 = F_21 ( V_17 -> V_23 , V_30 , V_31 , V_14 ) ;
break;
case V_35 :
case V_36 :
V_20 = V_3 -> V_10 ? V_3 -> V_4 - V_3 -> V_5 : 0 ;
if ( V_20 <= 0 )
V_20 = F_21 ( V_17 -> V_23 , V_30 , V_31 , V_14 ) ;
break;
case V_37 :
if( V_3 -> V_10 == 0 )
F_19 ( V_17 ) ;
while ( V_3 -> V_10 )
{
V_21 = F_15 ( V_17 , NULL , 0 ) ;
if ( V_21 < 0 )
{
V_20 = V_21 ;
break;
}
}
V_3 -> V_9 = 1 ;
V_3 -> V_5 = V_3 -> V_4 = 0 ;
V_3 -> V_8 = ( int ) V_20 ;
V_20 = F_21 ( V_17 -> V_23 , V_30 , V_31 , V_14 ) ;
break;
case V_38 :
F_13 ( V_17 ) ;
V_20 = F_21 ( V_17 -> V_23 , V_30 , V_31 , V_14 ) ;
F_14 ( V_17 ) ;
break;
case V_39 :
V_20 = ( long ) V_3 -> V_8 ;
break;
case V_40 :
V_12 = V_14 ;
F_22 ( & V_3 -> V_12 , V_12 , NULL ) ;
V_17 -> V_13 = 1 ;
break;
case V_41 :
if ( V_17 -> V_13 )
{
V_32 = V_14 ;
* V_32 = V_3 -> V_12 . V_42 ;
}
else
V_20 = 0 ;
break;
default:
V_20 = F_21 ( V_17 -> V_23 , V_30 , V_31 , V_14 ) ;
break;
}
return ( V_20 ) ;
}
static long F_23 ( T_2 * V_17 , int V_30 , T_5 * V_43 )
{
long V_20 = 1 ;
if ( V_17 -> V_23 == NULL ) return ( 0 ) ;
switch ( V_30 )
{
default:
V_20 = F_24 ( V_17 -> V_23 , V_30 , V_43 ) ;
break;
}
return ( V_20 ) ;
}
static void F_25 ( void * V_44 , T_6 V_45 )
{ const union { long V_46 ; char V_47 ; } V_48 = { 1 } ;
if ( V_48 . V_47 ) {
T_6 V_21 ;
unsigned char * V_49 = V_44 , V_50 ;
for( V_21 = 0 ; V_21 < V_45 ; V_21 += 4 ) {
V_50 = V_49 [ 0 ] , V_49 [ 0 ] = V_49 [ 3 ] , V_49 [ 3 ] = V_50 ;
V_50 = V_49 [ 1 ] , V_49 [ 1 ] = V_49 [ 2 ] , V_49 [ 2 ] = V_50 ;
}
}
}
static void F_16 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
if( V_3 -> V_4 + 2 * V_12 -> V_42 -> V_51 > V_29 ) return;
F_22 ( V_12 , V_12 -> V_42 , NULL ) ;
F_26 ( V_12 -> V_52 , V_12 -> V_42 -> V_51 ) ;
memcpy ( & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , V_12 -> V_52 , V_12 -> V_42 -> V_51 ) ;
F_25 ( & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , V_12 -> V_42 -> V_51 ) ;
V_3 -> V_4 += V_12 -> V_42 -> V_51 ;
F_27 ( V_12 , V_53 , strlen ( V_53 ) ) ;
F_28 ( V_12 , & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , NULL ) ;
V_3 -> V_4 += V_12 -> V_42 -> V_51 ;
V_3 -> V_10 = 1 ;
V_3 -> V_11 = 0 ;
}
static void F_11 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
unsigned char V_54 [ V_55 ] ;
int V_20 = 0 ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
if( ( int ) ( V_3 -> V_4 - V_3 -> V_5 ) < 2 * V_12 -> V_42 -> V_51 ) return;
F_22 ( V_12 , V_12 -> V_42 , NULL ) ;
memcpy ( V_12 -> V_52 , & ( V_3 -> V_24 [ V_3 -> V_5 ] ) , V_12 -> V_42 -> V_51 ) ;
F_25 ( V_12 -> V_52 , V_12 -> V_42 -> V_51 ) ;
V_3 -> V_5 += V_12 -> V_42 -> V_51 ;
F_27 ( V_12 , V_53 , strlen ( V_53 ) ) ;
F_28 ( V_12 , V_54 , NULL ) ;
V_20 = memcmp ( & ( V_3 -> V_24 [ V_3 -> V_5 ] ) , V_54 , V_12 -> V_42 -> V_51 ) == 0 ;
V_3 -> V_5 += V_12 -> V_42 -> V_51 ;
if( V_20 == 1 )
{
V_3 -> V_11 = 0 ;
if( V_3 -> V_4 != V_3 -> V_5 )
{
memmove ( V_3 -> V_24 , & ( V_3 -> V_24 [ V_3 -> V_5 ] ) , V_3 -> V_4 - V_3 -> V_5 ) ;
}
V_3 -> V_4 -= V_3 -> V_5 ;
V_3 -> V_5 = 0 ;
}
else
{
V_3 -> V_8 = 0 ;
}
}
static void F_19 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
unsigned long V_56 ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
V_56 = V_3 -> V_4 - V_28 ;
V_3 -> V_24 [ 0 ] = ( unsigned char ) ( V_56 >> 24 ) ;
V_3 -> V_24 [ 1 ] = ( unsigned char ) ( V_56 >> 16 ) ;
V_3 -> V_24 [ 2 ] = ( unsigned char ) ( V_56 >> 8 ) ;
V_3 -> V_24 [ 3 ] = ( unsigned char ) ( V_56 ) ;
F_27 ( V_12 , ( unsigned char * ) & ( V_3 -> V_24 [ V_28 ] ) , V_56 ) ;
F_28 ( V_12 , & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , NULL ) ;
V_3 -> V_4 += V_12 -> V_42 -> V_51 ;
V_3 -> V_10 = 1 ;
}
static void F_12 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
unsigned long V_56 = 0 ;
unsigned char V_54 [ V_55 ] ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
assert ( sizeof( V_56 ) >= V_28 ) ;
V_56 = V_3 -> V_24 [ 0 ] ; V_56 <<= 8 ;
V_56 |= V_3 -> V_24 [ 1 ] ; V_56 <<= 8 ;
V_56 |= V_3 -> V_24 [ 2 ] ; V_56 <<= 8 ;
V_56 |= V_3 -> V_24 [ 3 ] ;
if ( V_3 -> V_4 < V_56 + V_28 + V_12 -> V_42 -> V_51 ) return;
F_27 ( V_12 , ( unsigned char * ) & ( V_3 -> V_24 [ V_28 ] ) , V_56 ) ;
F_28 ( V_12 , V_54 , NULL ) ;
if( memcmp ( & ( V_3 -> V_24 [ V_56 + V_28 ] ) , V_54 , V_12 -> V_42 -> V_51 ) == 0 )
{
V_3 -> V_7 = V_56 + V_28 + V_12 -> V_42 -> V_51 ;
V_3 -> V_6 = V_3 -> V_4 ;
V_3 -> V_5 = V_28 ;
V_3 -> V_4 = V_56 + V_28 ;
V_3 -> V_10 = 1 ;
}
else
{
V_3 -> V_8 = 0 ;
}
}
