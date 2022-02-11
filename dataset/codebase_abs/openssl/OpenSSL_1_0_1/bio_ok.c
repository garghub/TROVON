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
if ( V_3 -> V_11 == 1 )
{
if ( ! F_11 ( V_17 ) )
{
F_12 ( V_17 ) ;
return 0 ;
}
}
if ( V_3 -> V_11 == 0 )
{
if ( ! F_13 ( V_17 ) )
{
F_12 ( V_17 ) ;
return 0 ;
}
}
if ( V_3 -> V_8 <= 0 ) break;
}
F_12 ( V_17 ) ;
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
if( V_3 -> V_11 && ! F_16 ( V_17 ) )
return 0 ;
do{
F_12 ( V_17 ) ;
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
if ( ! F_19 ( V_17 ) )
{
F_12 ( V_17 ) ;
return 0 ;
}
}
}while( V_27 > 0 );
F_12 ( V_17 ) ;
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
if ( ! F_19 ( V_17 ) )
return 0 ;
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
F_12 ( V_17 ) ;
V_20 = F_21 ( V_17 -> V_23 , V_30 , V_31 , V_14 ) ;
F_14 ( V_17 ) ;
break;
case V_39 :
V_20 = ( long ) V_3 -> V_8 ;
break;
case V_40 :
V_12 = V_14 ;
if ( ! F_22 ( & V_3 -> V_12 , V_12 , NULL ) )
return 0 ;
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
static int F_16 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
if( V_3 -> V_4 + 2 * V_12 -> V_42 -> V_51 > V_29 ) return 1 ;
if ( ! F_22 ( V_12 , V_12 -> V_42 , NULL ) )
goto V_52;
F_26 ( V_12 -> V_53 , V_12 -> V_42 -> V_51 ) ;
memcpy ( & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , V_12 -> V_53 , V_12 -> V_42 -> V_51 ) ;
F_25 ( & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , V_12 -> V_42 -> V_51 ) ;
V_3 -> V_4 += V_12 -> V_42 -> V_51 ;
if ( ! F_27 ( V_12 , V_54 , strlen ( V_54 ) ) )
goto V_52;
if ( ! F_28 ( V_12 , & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , NULL ) )
goto V_52;
V_3 -> V_4 += V_12 -> V_42 -> V_51 ;
V_3 -> V_10 = 1 ;
V_3 -> V_11 = 0 ;
return 1 ;
V_52:
F_12 ( V_17 ) ;
return 0 ;
}
static int F_11 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
unsigned char V_55 [ V_56 ] ;
int V_20 = 0 ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
if( ( int ) ( V_3 -> V_4 - V_3 -> V_5 ) < 2 * V_12 -> V_42 -> V_51 ) return 1 ;
if ( ! F_22 ( V_12 , V_12 -> V_42 , NULL ) )
goto V_52;
memcpy ( V_12 -> V_53 , & ( V_3 -> V_24 [ V_3 -> V_5 ] ) , V_12 -> V_42 -> V_51 ) ;
F_25 ( V_12 -> V_53 , V_12 -> V_42 -> V_51 ) ;
V_3 -> V_5 += V_12 -> V_42 -> V_51 ;
if ( ! F_27 ( V_12 , V_54 , strlen ( V_54 ) ) )
goto V_52;
if ( ! F_28 ( V_12 , V_55 , NULL ) )
goto V_52;
V_20 = memcmp ( & ( V_3 -> V_24 [ V_3 -> V_5 ] ) , V_55 , V_12 -> V_42 -> V_51 ) == 0 ;
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
return 1 ;
V_52:
F_12 ( V_17 ) ;
return 0 ;
}
static int F_19 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
unsigned long V_57 ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
V_57 = V_3 -> V_4 - V_28 ;
V_3 -> V_24 [ 0 ] = ( unsigned char ) ( V_57 >> 24 ) ;
V_3 -> V_24 [ 1 ] = ( unsigned char ) ( V_57 >> 16 ) ;
V_3 -> V_24 [ 2 ] = ( unsigned char ) ( V_57 >> 8 ) ;
V_3 -> V_24 [ 3 ] = ( unsigned char ) ( V_57 ) ;
if ( ! F_27 ( V_12 ,
( unsigned char * ) & ( V_3 -> V_24 [ V_28 ] ) , V_57 ) )
goto V_52;
if ( ! F_28 ( V_12 , & ( V_3 -> V_24 [ V_3 -> V_4 ] ) , NULL ) )
goto V_52;
V_3 -> V_4 += V_12 -> V_42 -> V_51 ;
V_3 -> V_10 = 1 ;
return 1 ;
V_52:
F_12 ( V_17 ) ;
return 0 ;
}
static int F_13 ( T_2 * V_17 )
{
T_3 * V_3 ;
T_7 * V_12 ;
unsigned long V_57 = 0 ;
unsigned char V_55 [ V_56 ] ;
V_3 = V_17 -> V_14 ;
V_12 = & V_3 -> V_12 ;
assert ( sizeof( V_57 ) >= V_28 ) ;
V_57 = V_3 -> V_24 [ 0 ] ; V_57 <<= 8 ;
V_57 |= V_3 -> V_24 [ 1 ] ; V_57 <<= 8 ;
V_57 |= V_3 -> V_24 [ 2 ] ; V_57 <<= 8 ;
V_57 |= V_3 -> V_24 [ 3 ] ;
if ( V_3 -> V_4 < V_57 + V_28 + V_12 -> V_42 -> V_51 ) return 1 ;
if ( ! F_27 ( V_12 ,
( unsigned char * ) & ( V_3 -> V_24 [ V_28 ] ) , V_57 ) )
goto V_52;
if ( ! F_28 ( V_12 , V_55 , NULL ) )
goto V_52;
if( memcmp ( & ( V_3 -> V_24 [ V_57 + V_28 ] ) , V_55 , V_12 -> V_42 -> V_51 ) == 0 )
{
V_3 -> V_7 = V_57 + V_28 + V_12 -> V_42 -> V_51 ;
V_3 -> V_6 = V_3 -> V_4 ;
V_3 -> V_5 = V_28 ;
V_3 -> V_4 = V_57 + V_28 ;
V_3 -> V_10 = 1 ;
}
else
{
V_3 -> V_8 = 0 ;
}
return 1 ;
V_52:
F_12 ( V_17 ) ;
return 0 ;
}
