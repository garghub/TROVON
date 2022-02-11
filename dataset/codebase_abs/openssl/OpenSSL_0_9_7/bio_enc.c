T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ;
if ( V_3 == NULL ) return ( 0 ) ;
F_4 ( & V_3 -> V_4 ) ;
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
F_7 ( V_13 -> V_11 , sizeof( T_3 ) ) ;
F_8 ( V_13 -> V_11 ) ;
V_13 -> V_11 = NULL ;
V_13 -> V_10 = 0 ;
V_13 -> V_12 = 0 ;
return ( 1 ) ;
}
static int F_9 ( T_2 * V_14 , char * V_15 , int V_16 )
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
V_18 = F_10 ( V_14 -> V_19 , & ( V_3 -> V_20 [ V_21 ] ) , V_22 ) ;
if ( V_18 <= 0 )
{
if ( ! F_11 ( V_14 -> V_19 ) )
{
V_3 -> V_7 = V_18 ;
V_18 = F_12 ( & ( V_3 -> V_4 ) ,
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
F_13 ( & ( V_3 -> V_4 ) ,
( unsigned char * ) V_3 -> V_20 , & V_3 -> V_5 ,
( unsigned char * ) & ( V_3 -> V_20 [ V_21 ] ) , V_18 ) ;
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
F_14 ( V_14 ) ;
F_15 ( V_14 ) ;
return ( ( V_17 == 0 ) ? V_3 -> V_7 : V_17 ) ;
}
static int F_16 ( T_2 * V_14 , const char * V_23 , int V_24 )
{
int V_17 = 0 , V_25 , V_18 ;
T_3 * V_3 ;
V_3 = ( T_3 * ) V_14 -> V_11 ;
V_17 = V_24 ;
F_14 ( V_14 ) ;
V_25 = V_3 -> V_5 - V_3 -> V_6 ;
while ( V_25 > 0 )
{
V_18 = F_17 ( V_14 -> V_19 , & ( V_3 -> V_20 [ V_3 -> V_6 ] ) , V_25 ) ;
if ( V_18 <= 0 )
{
F_15 ( V_14 ) ;
return ( V_18 ) ;
}
V_3 -> V_6 += V_18 ;
V_25 -= V_18 ;
}
if ( ( V_23 == NULL ) || ( V_24 <= 0 ) ) return ( 0 ) ;
V_3 -> V_6 = 0 ;
while ( V_24 > 0 )
{
V_25 = ( V_24 > V_22 ) ? V_22 : V_24 ;
F_13 ( & ( V_3 -> V_4 ) ,
( unsigned char * ) V_3 -> V_20 , & V_3 -> V_5 ,
( unsigned char * ) V_23 , V_25 ) ;
V_24 -= V_25 ;
V_23 += V_25 ;
V_3 -> V_6 = 0 ;
V_25 = V_3 -> V_5 ;
while ( V_25 > 0 )
{
V_18 = F_17 ( V_14 -> V_19 , & ( V_3 -> V_20 [ V_3 -> V_6 ] ) , V_25 ) ;
if ( V_18 <= 0 )
{
F_15 ( V_14 ) ;
return ( V_18 ) ;
}
V_25 -= V_18 ;
V_3 -> V_6 += V_18 ;
}
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0 ;
}
F_15 ( V_14 ) ;
return ( V_17 ) ;
}
static long F_18 ( T_2 * V_14 , int V_26 , long V_27 , void * V_11 )
{
T_2 * V_28 ;
T_3 * V_3 , * V_29 ;
long V_17 = 1 ;
int V_18 ;
T_4 * * V_30 ;
V_3 = ( T_3 * ) V_14 -> V_11 ;
switch ( V_26 )
{
case V_31 :
V_3 -> V_9 = 1 ;
V_3 -> V_8 = 0 ;
F_19 ( & ( V_3 -> V_4 ) , NULL , NULL , NULL , NULL ,
V_3 -> V_4 . V_32 ) ;
V_17 = F_20 ( V_14 -> V_19 , V_26 , V_27 , V_11 ) ;
break;
case V_33 :
if ( V_3 -> V_7 <= 0 )
V_17 = 1 ;
else
V_17 = F_20 ( V_14 -> V_19 , V_26 , V_27 , V_11 ) ;
break;
case V_34 :
V_17 = V_3 -> V_5 - V_3 -> V_6 ;
if ( V_17 <= 0 )
V_17 = F_20 ( V_14 -> V_19 , V_26 , V_27 , V_11 ) ;
break;
case V_35 :
V_17 = V_3 -> V_5 - V_3 -> V_6 ;
if ( V_17 <= 0 )
V_17 = F_20 ( V_14 -> V_19 , V_26 , V_27 , V_11 ) ;
break;
case V_36 :
V_37:
while ( V_3 -> V_5 != V_3 -> V_6 )
{
V_18 = F_16 ( V_14 , NULL , 0 ) ;
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
V_17 = F_12 ( & ( V_3 -> V_4 ) ,
( unsigned char * ) V_3 -> V_20 ,
& ( V_3 -> V_5 ) ) ;
V_3 -> V_9 = ( int ) V_17 ;
if ( V_17 <= 0 ) break;
goto V_37;
}
V_17 = F_20 ( V_14 -> V_19 , V_26 , V_27 , V_11 ) ;
break;
case V_38 :
V_17 = ( long ) V_3 -> V_9 ;
break;
case V_39 :
F_14 ( V_14 ) ;
V_17 = F_20 ( V_14 -> V_19 , V_26 , V_27 , V_11 ) ;
F_15 ( V_14 ) ;
break;
case V_40 :
V_30 = ( T_4 * * ) V_11 ;
( * V_30 ) = & ( V_3 -> V_4 ) ;
V_14 -> V_10 = 1 ;
break;
case V_41 :
V_28 = ( T_2 * ) V_11 ;
V_29 = ( T_3 * ) V_28 -> V_11 ;
memcpy ( & ( V_29 -> V_4 ) , & ( V_3 -> V_4 ) , sizeof( V_3 -> V_4 ) ) ;
V_28 -> V_10 = 1 ;
break;
default:
V_17 = F_20 ( V_14 -> V_19 , V_26 , V_27 , V_11 ) ;
break;
}
return ( V_17 ) ;
}
static long F_21 ( T_2 * V_14 , int V_26 , T_5 * V_42 )
{
long V_17 = 1 ;
if ( V_14 -> V_19 == NULL ) return ( 0 ) ;
switch ( V_26 )
{
default:
V_17 = F_22 ( V_14 -> V_19 , V_26 , V_42 ) ;
break;
}
return ( V_17 ) ;
}
void F_23 ( T_2 * V_14 , const T_6 * V_43 , unsigned char * V_44 ,
unsigned char * V_18 , int V_45 )
{
T_3 * V_3 ;
if ( V_14 == NULL ) return;
if ( ( V_14 -> V_46 != NULL ) &&
( V_14 -> V_46 ( V_14 , V_47 , ( const char * ) V_43 , V_48 , V_45 , 0L ) <= 0 ) )
return;
V_14 -> V_10 = 1 ;
V_3 = ( T_3 * ) V_14 -> V_11 ;
F_19 ( & ( V_3 -> V_4 ) , V_43 , NULL , V_44 , V_18 , V_45 ) ;
if ( V_14 -> V_46 != NULL )
V_14 -> V_46 ( V_14 , V_47 , ( const char * ) V_43 , V_48 , V_45 , 1L ) ;
}
