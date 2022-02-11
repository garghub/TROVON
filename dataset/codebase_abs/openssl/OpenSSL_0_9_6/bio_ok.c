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
V_2 -> V_12 = 0 ;
V_2 -> V_13 = ( char * ) V_3 ;
V_2 -> V_14 = 0 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_15 )
{
if ( V_15 == NULL ) return ( 0 ) ;
memset ( V_15 -> V_13 , 0 , sizeof( T_3 ) ) ;
F_5 ( V_15 -> V_13 ) ;
V_15 -> V_13 = NULL ;
V_15 -> V_12 = 0 ;
V_15 -> V_14 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_16 , char * V_17 , int V_18 )
{
int V_19 = 0 , V_20 , V_21 ;
T_3 * V_3 ;
if ( V_17 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_16 -> V_13 ;
if ( ( V_3 == NULL ) || ( V_16 -> V_22 == NULL ) || ( V_16 -> V_12 == 0 ) ) return ( 0 ) ;
while( V_18 > 0 )
{
if ( V_3 -> V_10 )
{
V_20 = V_3 -> V_4 - V_3 -> V_5 ;
if ( V_20 > V_18 ) V_20 = V_18 ;
memcpy ( V_17 , & ( V_3 -> V_23 [ V_3 -> V_5 ] ) , V_20 ) ;
V_19 += V_20 ;
V_17 += V_20 ;
V_18 -= V_20 ;
V_3 -> V_5 += V_20 ;
if ( V_3 -> V_4 == V_3 -> V_5 )
{
V_3 -> V_5 = 0 ;
if( V_3 -> V_6 - V_3 -> V_7 > 0 )
{
V_3 -> V_4 = V_3 -> V_6 - V_3 -> V_7 ;
memmove ( V_3 -> V_23 , & ( V_3 -> V_23 [ V_3 -> V_7 ] ) ,
V_3 -> V_4 ) ;
}
else
{
V_3 -> V_4 = 0 ;
}
V_3 -> V_10 = 0 ;
}
}
if ( V_18 == 0 ) break;
V_21 = V_24 - V_3 -> V_4 ;
V_20 = F_7 ( V_16 -> V_22 , & ( V_3 -> V_23 [ V_3 -> V_4 ] ) , V_21 ) ;
if ( V_20 <= 0 ) break;
V_3 -> V_4 += V_20 ;
if ( V_3 -> V_11 == 1 ) F_8 ( V_16 ) ;
if ( V_3 -> V_11 == 0 ) F_9 ( V_16 ) ;
if ( V_3 -> V_8 <= 0 ) break;
}
F_10 ( V_16 ) ;
F_11 ( V_16 ) ;
return ( V_19 ) ;
}
static int F_12 ( T_2 * V_16 , const char * V_25 , int V_26 )
{
int V_19 = 0 , V_21 , V_20 ;
T_3 * V_3 ;
V_3 = ( T_3 * ) V_16 -> V_13 ;
V_19 = V_26 ;
if ( ( V_3 == NULL ) || ( V_16 -> V_22 == NULL ) || ( V_16 -> V_12 == 0 ) ) return ( 0 ) ;
if( V_3 -> V_11 ) F_13 ( V_16 ) ;
do{
F_10 ( V_16 ) ;
V_21 = V_3 -> V_4 - V_3 -> V_5 ;
while ( V_3 -> V_10 && V_21 > 0 )
{
V_20 = F_14 ( V_16 -> V_22 , & ( V_3 -> V_23 [ V_3 -> V_5 ] ) , V_21 ) ;
if ( V_20 <= 0 )
{
F_11 ( V_16 ) ;
if( ! F_15 ( V_16 ) )
V_3 -> V_8 = 0 ;
return ( V_20 ) ;
}
V_3 -> V_5 += V_20 ;
V_21 -= V_20 ;
}
V_3 -> V_10 = 0 ;
if ( V_3 -> V_4 == V_3 -> V_5 )
{
V_3 -> V_4 = V_27 ;
V_3 -> V_5 = 0 ;
}
if ( ( V_25 == NULL ) || ( V_26 <= 0 ) ) return ( 0 ) ;
V_21 = ( V_26 + V_3 -> V_4 > V_28 + V_27 ) ?
V_28 + V_27 - V_3 -> V_4 : V_26 ;
memcpy ( ( unsigned char * ) ( & ( V_3 -> V_23 [ V_3 -> V_4 ] ) ) , ( unsigned char * ) V_25 , V_21 ) ;
V_3 -> V_4 += V_21 ;
V_26 -= V_21 ;
V_25 += V_21 ;
if( V_3 -> V_4 >= V_28 + V_27 )
{
F_16 ( V_16 ) ;
}
}while( V_26 > 0 );
F_10 ( V_16 ) ;
F_11 ( V_16 ) ;
return ( V_19 ) ;
}
static long F_17 ( T_2 * V_16 , int V_29 , long V_30 , void * V_13 )
{
T_3 * V_3 ;
T_4 * V_31 ;
const T_4 * * V_32 ;
long V_19 = 1 ;
int V_20 ;
V_3 = ( T_3 * ) V_16 -> V_13 ;
switch ( V_29 )
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
V_19 = F_18 ( V_16 -> V_22 , V_29 , V_30 , V_13 ) ;
break;
case V_34 :
if ( V_3 -> V_8 <= 0 )
V_19 = 1 ;
else
V_19 = F_18 ( V_16 -> V_22 , V_29 , V_30 , V_13 ) ;
break;
case V_35 :
case V_36 :
V_19 = V_3 -> V_10 ? V_3 -> V_4 - V_3 -> V_5 : 0 ;
if ( V_19 <= 0 )
V_19 = F_18 ( V_16 -> V_22 , V_29 , V_30 , V_13 ) ;
break;
case V_37 :
if( V_3 -> V_10 == 0 )
F_16 ( V_16 ) ;
while ( V_3 -> V_10 )
{
V_20 = F_12 ( V_16 , NULL , 0 ) ;
if ( V_20 < 0 )
{
V_19 = V_20 ;
break;
}
}
V_3 -> V_9 = 1 ;
V_3 -> V_5 = V_3 -> V_4 = 0 ;
V_3 -> V_8 = ( int ) V_19 ;
V_19 = F_18 ( V_16 -> V_22 , V_29 , V_30 , V_13 ) ;
break;
case V_38 :
F_10 ( V_16 ) ;
V_19 = F_18 ( V_16 -> V_22 , V_29 , V_30 , V_13 ) ;
F_11 ( V_16 ) ;
break;
case V_39 :
V_19 = ( long ) V_3 -> V_8 ;
break;
case V_40 :
V_31 = ( T_4 * ) V_13 ;
F_19 ( & ( V_3 -> V_31 ) , V_31 ) ;
V_16 -> V_12 = 1 ;
break;
case V_41 :
if ( V_16 -> V_12 )
{
V_32 = ( const T_4 * * ) V_13 ;
* V_32 = V_3 -> V_31 . V_42 ;
}
else
V_19 = 0 ;
break;
default:
V_19 = F_18 ( V_16 -> V_22 , V_29 , V_30 , V_13 ) ;
break;
}
return ( V_19 ) ;
}
static long F_20 ( T_2 * V_16 , int V_29 , T_5 * V_43 )
{
long V_19 = 1 ;
if ( V_16 -> V_22 == NULL ) return ( 0 ) ;
switch ( V_29 )
{
default:
V_19 = F_21 ( V_16 -> V_22 , V_29 , V_43 ) ;
break;
}
return ( V_19 ) ;
}
static void F_22 ( void * V_44 , int V_45 )
{
#ifndef F_23
int V_20 ;
char * V_13 = V_44 ;
for( V_20 = 0 ; V_20 < V_45 ; V_20 += 4 ) {
* ( ( unsigned long * ) & ( V_13 [ V_20 ] ) ) = F_24 ( * ( ( unsigned long * ) & ( V_13 [ V_20 ] ) ) ) ;
}
#endif
}
static void F_13 ( T_2 * V_16 )
{
T_3 * V_3 ;
T_6 * V_31 ;
V_3 = ( T_3 * ) V_16 -> V_13 ;
V_31 = & ( V_3 -> V_31 ) ;
if( V_3 -> V_4 + 2 * V_31 -> V_42 -> V_46 > V_28 ) return;
F_19 ( V_31 , V_31 -> V_42 ) ;
F_25 ( & ( V_31 -> V_31 . V_47 [ 0 ] ) , V_31 -> V_42 -> V_46 ) ;
memcpy ( & ( V_3 -> V_23 [ V_3 -> V_4 ] ) , & ( V_31 -> V_31 . V_47 [ 0 ] ) , V_31 -> V_42 -> V_46 ) ;
F_22 ( & ( V_3 -> V_23 [ V_3 -> V_4 ] ) , V_31 -> V_42 -> V_46 ) ;
V_3 -> V_4 += V_31 -> V_42 -> V_46 ;
F_26 ( V_31 , V_48 , strlen ( V_48 ) ) ;
V_31 -> V_42 -> V_49 ( & ( V_3 -> V_23 [ V_3 -> V_4 ] ) , & ( V_31 -> V_31 . V_47 [ 0 ] ) ) ;
V_3 -> V_4 += V_31 -> V_42 -> V_46 ;
V_3 -> V_10 = 1 ;
V_3 -> V_11 = 0 ;
}
static void F_8 ( T_2 * V_16 )
{
T_3 * V_3 ;
T_6 * V_31 ;
unsigned char V_50 [ V_51 ] ;
int V_19 = 0 ;
V_3 = ( T_3 * ) V_16 -> V_13 ;
V_31 = & ( V_3 -> V_31 ) ;
if( V_3 -> V_4 - V_3 -> V_5 < 2 * V_31 -> V_42 -> V_46 ) return;
F_19 ( V_31 , V_31 -> V_42 ) ;
memcpy ( & ( V_31 -> V_31 . V_47 [ 0 ] ) , & ( V_3 -> V_23 [ V_3 -> V_5 ] ) , V_31 -> V_42 -> V_46 ) ;
F_22 ( & ( V_31 -> V_31 . V_47 [ 0 ] ) , V_31 -> V_42 -> V_46 ) ;
V_3 -> V_5 += V_31 -> V_42 -> V_46 ;
F_26 ( V_31 , V_48 , strlen ( V_48 ) ) ;
V_31 -> V_42 -> V_49 ( V_50 , & ( V_31 -> V_31 . V_47 [ 0 ] ) ) ;
V_19 = memcmp ( & ( V_3 -> V_23 [ V_3 -> V_5 ] ) , V_50 , V_31 -> V_42 -> V_46 ) == 0 ;
V_3 -> V_5 += V_31 -> V_42 -> V_46 ;
if( V_19 == 1 )
{
V_3 -> V_11 = 0 ;
if( V_3 -> V_4 != V_3 -> V_5 )
{
memmove ( V_3 -> V_23 , & ( V_3 -> V_23 [ V_3 -> V_5 ] ) , V_3 -> V_4 - V_3 -> V_5 ) ;
}
V_3 -> V_4 -= V_3 -> V_5 ;
V_3 -> V_5 = 0 ;
}
else
{
V_3 -> V_8 = 0 ;
}
}
static void F_16 ( T_2 * V_16 )
{
T_3 * V_3 ;
T_6 * V_31 ;
unsigned long V_52 ;
V_3 = ( T_3 * ) V_16 -> V_13 ;
V_31 = & ( V_3 -> V_31 ) ;
V_52 = V_3 -> V_4 - V_27 ;
V_52 = F_24 ( V_52 ) ;
memcpy ( V_3 -> V_23 , & V_52 , V_27 ) ;
V_52 = F_24 ( V_52 ) ;
F_26 ( V_31 , ( unsigned char * ) & ( V_3 -> V_23 [ V_27 ] ) , V_52 ) ;
V_31 -> V_42 -> V_49 ( & ( V_3 -> V_23 [ V_3 -> V_4 ] ) , & ( V_31 -> V_31 . V_47 [ 0 ] ) ) ;
V_3 -> V_4 += V_31 -> V_42 -> V_46 ;
V_3 -> V_10 = 1 ;
}
static void F_9 ( T_2 * V_16 )
{
T_3 * V_3 ;
T_6 * V_31 ;
long V_52 = 0 ;
unsigned char V_50 [ V_51 ] ;
V_3 = ( T_3 * ) V_16 -> V_13 ;
V_31 = & ( V_3 -> V_31 ) ;
memcpy ( & V_52 , V_3 -> V_23 , V_27 ) ;
V_52 = F_24 ( V_52 ) ;
if ( V_3 -> V_4 < V_52 + V_27 + V_31 -> V_42 -> V_46 ) return;
F_26 ( V_31 , ( unsigned char * ) & ( V_3 -> V_23 [ V_27 ] ) , V_52 ) ;
V_31 -> V_42 -> V_49 ( V_50 , & ( V_31 -> V_31 . V_47 [ 0 ] ) ) ;
if( memcmp ( & ( V_3 -> V_23 [ V_52 + V_27 ] ) , V_50 , V_31 -> V_42 -> V_46 ) == 0 )
{
V_3 -> V_7 = V_52 + V_27 + V_31 -> V_42 -> V_46 ;
V_3 -> V_6 = V_3 -> V_4 ;
V_3 -> V_5 = V_27 ;
V_3 -> V_4 = V_52 + V_27 ;
V_3 -> V_10 = 1 ;
}
else
{
V_3 -> V_8 = 0 ;
}
}
