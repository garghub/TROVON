T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ;
F_4 ( & V_3 -> V_4 ) ;
if ( V_3 == NULL ) return ( 0 ) ;
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 1 ;
V_3 -> V_8 = 0 ;
V_3 -> V_9 = 1 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = ( char * ) V_3 ;
V_2 -> V_12 = 0 ;
return ( 1 ) ;
}
static int F_5 ( T_2 * V_13 )
{
T_3 * V_14 ;
if ( V_13 == NULL ) return ( 0 ) ;
V_14 = ( T_3 * ) V_13 -> V_11 ;
F_6 ( & ( V_14 -> V_4 ) ) ;
memset ( V_13 -> V_11 , 0 , sizeof( T_3 ) ) ;
F_7 ( V_13 -> V_11 ) ;
V_13 -> V_11 = NULL ;
V_13 -> V_10 = 0 ;
V_13 -> V_12 = 0 ;
return ( 1 ) ;
}
static int F_8 ( T_2 * V_14 , char * V_15 , int V_16 )
{
int V_17 = 0 , V_18 ;
T_3 * V_3 ;
if ( V_15 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_14 -> V_11 ;
if ( ( V_3 == NULL ) || ( V_14 -> V_19 == NULL ) ) return ( 0 ) ;
if ( V_3 -> V_5 > 0 )
{
V_18 = V_3 -> V_5 - V_3 -> V_6 ;
if ( V_18 > V_16 ) V_18 = V_16 ;
memcpy ( V_15 , & ( V_3 -> V_20 [ V_3 -> V_6 ] ) , V_18 ) ;
V_17 = V_18 ;
V_15 += V_18 ;
V_16 -= V_18 ;
V_3 -> V_6 += V_18 ;
if ( V_3 -> V_5 == V_3 -> V_6 )
{
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
}
}
while ( V_16 > 0 )
{
if ( V_3 -> V_7 <= 0 ) break;
V_18 = F_9 ( V_14 -> V_19 , & ( V_3 -> V_20 [ 8 ] ) , V_21 ) ;
if ( V_18 <= 0 )
{
if ( ! F_10 ( V_14 -> V_19 ) )
{
V_3 -> V_7 = V_18 ;
V_18 = F_11 ( & ( V_3 -> V_4 ) ,
( unsigned char * ) V_3 -> V_20 ,
& ( V_3 -> V_5 ) ) ;
V_3 -> V_9 = V_18 ;
V_3 -> V_6 = 0 ;
}
else
{
V_17 = ( V_17 == 0 ) ? V_18 : V_17 ;
break;
}
}
else
{
F_12 ( & ( V_3 -> V_4 ) ,
( unsigned char * ) V_3 -> V_20 , & V_3 -> V_5 ,
( unsigned char * ) & ( V_3 -> V_20 [ 8 ] ) , V_18 ) ;
V_3 -> V_7 = 1 ;
if( V_3 -> V_5 == 0 ) continue;
}
if ( V_3 -> V_5 <= V_16 )
V_18 = V_3 -> V_5 ;
else
V_18 = V_16 ;
if ( V_18 <= 0 ) break;
memcpy ( V_15 , V_3 -> V_20 , V_18 ) ;
V_17 += V_18 ;
V_3 -> V_6 = V_18 ;
V_16 -= V_18 ;
V_15 += V_18 ;
}
F_13 ( V_14 ) ;
F_14 ( V_14 ) ;
return ( ( V_17 == 0 ) ? V_3 -> V_7 : V_17 ) ;
}
static int F_15 ( T_2 * V_14 , const char * V_22 , int V_23 )
{
int V_17 = 0 , V_24 , V_18 ;
T_3 * V_3 ;
V_3 = ( T_3 * ) V_14 -> V_11 ;
V_17 = V_23 ;
F_13 ( V_14 ) ;
V_24 = V_3 -> V_5 - V_3 -> V_6 ;
while ( V_24 > 0 )
{
V_18 = F_16 ( V_14 -> V_19 , & ( V_3 -> V_20 [ V_3 -> V_6 ] ) , V_24 ) ;
if ( V_18 <= 0 )
{
F_14 ( V_14 ) ;
return ( V_18 ) ;
}
V_3 -> V_6 += V_18 ;
V_24 -= V_18 ;
}
if ( ( V_22 == NULL ) || ( V_23 <= 0 ) ) return ( 0 ) ;
V_3 -> V_6 = 0 ;
while ( V_23 > 0 )
{
V_24 = ( V_23 > V_21 ) ? V_21 : V_23 ;
F_12 ( & ( V_3 -> V_4 ) ,
( unsigned char * ) V_3 -> V_20 , & V_3 -> V_5 ,
( unsigned char * ) V_22 , V_24 ) ;
V_23 -= V_24 ;
V_22 += V_24 ;
V_3 -> V_6 = 0 ;
V_24 = V_3 -> V_5 ;
while ( V_24 > 0 )
{
V_18 = F_16 ( V_14 -> V_19 , & ( V_3 -> V_20 [ V_3 -> V_6 ] ) , V_24 ) ;
if ( V_18 <= 0 )
{
F_14 ( V_14 ) ;
return ( V_18 ) ;
}
V_24 -= V_18 ;
V_3 -> V_6 += V_18 ;
}
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
}
F_14 ( V_14 ) ;
return ( V_17 ) ;
}
static long F_17 ( T_2 * V_14 , int V_25 , long V_26 , void * V_11 )
{
T_2 * V_27 ;
T_3 * V_3 , * V_28 ;
long V_17 = 1 ;
int V_18 ;
T_4 * * V_29 ;
V_3 = ( T_3 * ) V_14 -> V_11 ;
switch ( V_25 )
{
case V_30 :
V_3 -> V_9 = 1 ;
V_3 -> V_8 = 0 ;
F_18 ( & ( V_3 -> V_4 ) , NULL , NULL , NULL ,
V_3 -> V_4 . V_31 ) ;
V_17 = F_19 ( V_14 -> V_19 , V_25 , V_26 , V_11 ) ;
break;
case V_32 :
if ( V_3 -> V_7 <= 0 )
V_17 = 1 ;
else
V_17 = F_19 ( V_14 -> V_19 , V_25 , V_26 , V_11 ) ;
break;
case V_33 :
V_17 = V_3 -> V_5 - V_3 -> V_6 ;
if ( V_17 <= 0 )
V_17 = F_19 ( V_14 -> V_19 , V_25 , V_26 , V_11 ) ;
break;
case V_34 :
V_17 = V_3 -> V_5 - V_3 -> V_6 ;
if ( V_17 <= 0 )
V_17 = F_19 ( V_14 -> V_19 , V_25 , V_26 , V_11 ) ;
break;
case V_35 :
V_36:
while ( V_3 -> V_5 != V_3 -> V_6 )
{
V_18 = F_15 ( V_14 , NULL , 0 ) ;
if ( V_18 < 0 )
{
V_17 = V_18 ;
break;
}
}
if ( ! V_3 -> V_8 )
{
V_3 -> V_8 = 1 ;
V_3 -> V_6 = 0 ;
V_17 = F_11 ( & ( V_3 -> V_4 ) ,
( unsigned char * ) V_3 -> V_20 ,
& ( V_3 -> V_5 ) ) ;
V_3 -> V_9 = ( int ) V_17 ;
if ( V_17 <= 0 ) break;
goto V_36;
}
V_17 = F_19 ( V_14 -> V_19 , V_25 , V_26 , V_11 ) ;
break;
case V_37 :
V_17 = ( long ) V_3 -> V_9 ;
break;
case V_38 :
F_13 ( V_14 ) ;
V_17 = F_19 ( V_14 -> V_19 , V_25 , V_26 , V_11 ) ;
F_14 ( V_14 ) ;
break;
case V_39 :
V_29 = ( T_4 * * ) V_11 ;
( * V_29 ) = & ( V_3 -> V_4 ) ;
V_14 -> V_10 = 1 ;
break;
case V_40 :
V_27 = ( T_2 * ) V_11 ;
V_28 = ( T_3 * ) V_27 -> V_11 ;
memcpy ( & ( V_28 -> V_4 ) , & ( V_3 -> V_4 ) , sizeof( V_3 -> V_4 ) ) ;
V_27 -> V_10 = 1 ;
break;
default:
V_17 = F_19 ( V_14 -> V_19 , V_25 , V_26 , V_11 ) ;
break;
}
return ( V_17 ) ;
}
static long F_20 ( T_2 * V_14 , int V_25 , T_5 * V_41 )
{
long V_17 = 1 ;
if ( V_14 -> V_19 == NULL ) return ( 0 ) ;
switch ( V_25 )
{
default:
V_17 = F_21 ( V_14 -> V_19 , V_25 , V_41 ) ;
break;
}
return ( V_17 ) ;
}
void F_22 ( T_2 * V_14 , const T_6 * V_42 , unsigned char * V_43 ,
unsigned char * V_18 , int V_44 )
{
T_3 * V_3 ;
if ( V_14 == NULL ) return;
if ( ( V_14 -> V_45 != NULL ) &&
( V_14 -> V_45 ( V_14 , V_46 , ( const char * ) V_42 , V_47 , V_44 , 0L ) <= 0 ) )
return;
V_14 -> V_10 = 1 ;
V_3 = ( T_3 * ) V_14 -> V_11 ;
F_18 ( & ( V_3 -> V_4 ) , V_42 , V_43 , V_18 , V_44 ) ;
if ( V_14 -> V_45 != NULL )
V_14 -> V_45 ( V_14 , V_46 , ( const char * ) V_42 , V_47 , V_44 , 1L ) ;
}
