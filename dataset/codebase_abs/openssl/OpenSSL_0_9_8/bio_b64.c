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
V_3 -> V_9 = 1 ;
V_3 -> V_10 = 0 ;
V_2 -> V_11 = 1 ;
V_2 -> V_12 = ( char * ) V_3 ;
V_2 -> V_13 = 0 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_14 )
{
if ( V_14 == NULL ) return ( 0 ) ;
F_5 ( V_14 -> V_12 ) ;
V_14 -> V_12 = NULL ;
V_14 -> V_11 = 0 ;
V_14 -> V_13 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_15 , char * V_16 , int V_17 )
{
int V_18 = 0 , V_19 , V_20 , V_21 , V_22 , V_23 , V_24 , V_25 , V_26 = 0 ;
T_3 * V_3 ;
unsigned char * V_27 , * V_28 ;
if ( V_16 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_15 -> V_12 ;
if ( ( V_3 == NULL ) || ( V_15 -> V_29 == NULL ) ) return ( 0 ) ;
if ( V_3 -> V_10 != V_30 )
{
V_3 -> V_10 = V_30 ;
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_5 = 0 ;
F_7 ( & ( V_3 -> V_31 ) ) ;
}
if ( V_3 -> V_4 > 0 )
{
V_19 = V_3 -> V_4 - V_3 -> V_7 ;
if ( V_19 > V_17 ) V_19 = V_17 ;
F_8 ( V_3 -> V_7 + V_19 < ( int ) sizeof( V_3 -> V_32 ) ) ;
memcpy ( V_16 , & ( V_3 -> V_32 [ V_3 -> V_7 ] ) , V_19 ) ;
V_18 = V_19 ;
V_16 += V_19 ;
V_17 -= V_19 ;
V_3 -> V_7 += V_19 ;
if ( V_3 -> V_4 == V_3 -> V_7 )
{
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
}
}
V_26 = 0 ;
while ( V_17 > 0 )
{
if ( V_3 -> V_8 <= 0 )
break;
V_19 = F_9 ( V_15 -> V_29 , & ( V_3 -> V_33 [ V_3 -> V_5 ] ) ,
V_34 - V_3 -> V_5 ) ;
if ( V_19 <= 0 )
{
V_26 = V_19 ;
if ( ! F_10 ( V_15 -> V_29 ) )
{
V_3 -> V_8 = V_19 ;
if( V_3 -> V_5 == 0 )
break;
else
V_19 = 0 ;
}
else
break;
}
V_19 += V_3 -> V_5 ;
V_3 -> V_5 = V_19 ;
if ( V_3 -> V_9 && ( F_11 ( V_15 ) & V_35 ) )
{
V_3 -> V_5 = 0 ;
}
else if ( V_3 -> V_9 )
{
V_28 = V_27 = ( unsigned char * ) V_3 -> V_33 ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
{
if ( * ( V_28 ++ ) != '\n' ) continue;
if ( V_3 -> V_6 )
{
V_27 = V_28 ;
V_3 -> V_6 = 0 ;
continue;
}
V_22 = F_12 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 ,
& V_25 , V_27 , V_28 - V_27 ) ;
if ( ( V_22 <= 0 ) && ( V_25 == 0 ) && ( V_3 -> V_9 ) )
F_7 ( & V_3 -> V_31 ) ;
else
{
if ( V_27 != ( unsigned char * )
& ( V_3 -> V_33 [ 0 ] ) )
{
V_19 -= ( V_27 - ( unsigned char * )
& ( V_3 -> V_33 [ 0 ] ) ) ;
for ( V_23 = 0 ; V_23 < V_19 ; V_23 ++ )
V_3 -> V_33 [ V_23 ] = V_27 [ V_23 ] ;
}
F_7 ( & V_3 -> V_31 ) ;
V_3 -> V_9 = 0 ;
break;
}
V_27 = V_28 ;
}
if ( V_21 == V_19 )
{
if ( V_27 == ( unsigned char * ) & ( V_3 -> V_33 [ 0 ] ) )
{
if ( V_19 == V_34 )
{
V_3 -> V_6 = 1 ;
V_3 -> V_5 = 0 ;
}
}
else if ( V_27 != V_28 )
{
V_24 = V_28 - V_27 ;
for ( V_20 = 0 ; V_20 < V_24 ; V_20 ++ )
V_3 -> V_33 [ V_20 ] = V_27 [ V_20 ] ;
V_3 -> V_5 = V_24 ;
}
continue;
}
else
V_3 -> V_5 = 0 ;
}
else if ( ( V_19 < V_34 ) && ( V_3 -> V_8 > 0 ) )
continue;
if ( F_11 ( V_15 ) & V_35 )
{
int V_36 , V_37 ;
V_37 = ( V_19 >> 2 ) << 2 ;
V_36 = F_13 ( ( unsigned char * ) V_3 -> V_32 ,
( unsigned char * ) V_3 -> V_33 , V_37 ) ;
if ( V_37 > 2 )
{
if ( V_3 -> V_33 [ V_37 - 1 ] == '=' )
{
V_36 -- ;
if ( V_3 -> V_33 [ V_37 - 2 ] == '=' )
V_36 -- ;
}
}
if ( V_37 != V_19 )
{
memcpy ( ( unsigned char * ) V_3 -> V_33 ,
( unsigned char * ) & ( V_3 -> V_33 [ V_37 ] ) , V_19 - V_37 ) ;
V_3 -> V_5 = V_19 - V_37 ;
}
V_3 -> V_4 = 0 ;
if ( V_36 > 0 )
{
V_3 -> V_4 = V_36 ;
V_19 = 1 ;
}
else
V_19 = V_36 ;
}
else
{
V_19 = F_12 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 , & V_3 -> V_4 ,
( unsigned char * ) V_3 -> V_33 , V_19 ) ;
V_3 -> V_5 = 0 ;
}
V_3 -> V_7 = 0 ;
if ( V_19 < 0 )
{
V_26 = 0 ;
V_3 -> V_4 = 0 ;
break;
}
if ( V_3 -> V_4 <= V_17 )
V_19 = V_3 -> V_4 ;
else
V_19 = V_17 ;
memcpy ( V_16 , V_3 -> V_32 , V_19 ) ;
V_18 += V_19 ;
V_3 -> V_7 = V_19 ;
if ( V_3 -> V_7 == V_3 -> V_4 )
{
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
}
V_17 -= V_19 ;
V_16 += V_19 ;
}
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
return ( ( V_18 == 0 ) ? V_26 : V_18 ) ;
}
static int F_16 ( T_2 * V_15 , const char * V_38 , int V_39 )
{
int V_18 = V_39 , V_24 , V_19 ;
T_3 * V_3 ;
V_3 = ( T_3 * ) V_15 -> V_12 ;
F_14 ( V_15 ) ;
if ( V_3 -> V_10 != V_40 )
{
V_3 -> V_10 = V_40 ;
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_5 = 0 ;
F_17 ( & ( V_3 -> V_31 ) ) ;
}
V_24 = V_3 -> V_4 - V_3 -> V_7 ;
while ( V_24 > 0 )
{
V_19 = F_18 ( V_15 -> V_29 , & ( V_3 -> V_32 [ V_3 -> V_7 ] ) , V_24 ) ;
if ( V_19 <= 0 )
{
F_15 ( V_15 ) ;
return ( V_19 ) ;
}
V_3 -> V_7 += V_19 ;
V_24 -= V_19 ;
}
V_3 -> V_7 = 0 ;
V_3 -> V_4 = 0 ;
if ( ( V_38 == NULL ) || ( V_39 <= 0 ) ) return ( 0 ) ;
while ( V_39 > 0 )
{
V_24 = ( V_39 > V_34 ) ? V_34 : V_39 ;
if ( F_11 ( V_15 ) & V_35 )
{
if ( V_3 -> V_5 > 0 )
{
V_24 = 3 - V_3 -> V_5 ;
if ( V_24 > V_39 )
V_24 = V_39 ;
memcpy ( & ( V_3 -> V_33 [ V_3 -> V_5 ] ) , V_38 , V_24 ) ;
V_3 -> V_5 += V_24 ;
if ( V_3 -> V_5 < 3 )
break;
V_3 -> V_4 = F_19 (
( unsigned char * ) V_3 -> V_32 ,
( unsigned char * ) V_3 -> V_33 ,
V_3 -> V_5 ) ;
V_3 -> V_5 = 0 ;
}
else
{
if ( V_24 < 3 )
{
memcpy ( & ( V_3 -> V_33 [ 0 ] ) , V_38 , V_24 ) ;
V_3 -> V_5 = V_24 ;
break;
}
V_24 -= V_24 % 3 ;
V_3 -> V_4 = F_19 (
( unsigned char * ) V_3 -> V_32 ,
( unsigned char * ) V_38 , V_24 ) ;
}
}
else
{
F_20 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 , & V_3 -> V_4 ,
( unsigned char * ) V_38 , V_24 ) ;
}
V_39 -= V_24 ;
V_38 += V_24 ;
V_3 -> V_7 = 0 ;
V_24 = V_3 -> V_4 ;
while ( V_24 > 0 )
{
V_19 = F_18 ( V_15 -> V_29 , & ( V_3 -> V_32 [ V_3 -> V_7 ] ) , V_24 ) ;
if ( V_19 <= 0 )
{
F_15 ( V_15 ) ;
return ( ( V_18 == 0 ) ? V_19 : V_18 ) ;
}
V_24 -= V_19 ;
V_3 -> V_7 += V_19 ;
}
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
}
return ( V_18 ) ;
}
static long F_21 ( T_2 * V_15 , int V_41 , long V_25 , void * V_12 )
{
T_3 * V_3 ;
long V_18 = 1 ;
int V_19 ;
V_3 = ( T_3 * ) V_15 -> V_12 ;
switch ( V_41 )
{
case V_42 :
V_3 -> V_8 = 1 ;
V_3 -> V_9 = 1 ;
V_3 -> V_10 = V_43 ;
V_18 = F_22 ( V_15 -> V_29 , V_41 , V_25 , V_12 ) ;
break;
case V_44 :
if ( V_3 -> V_8 <= 0 )
V_18 = 1 ;
else
V_18 = F_22 ( V_15 -> V_29 , V_41 , V_25 , V_12 ) ;
break;
case V_45 :
V_18 = V_3 -> V_4 - V_3 -> V_7 ;
if ( ( V_18 == 0 ) && ( V_3 -> V_10 != V_43 )
&& ( V_3 -> V_31 . V_25 != 0 ) )
V_18 = 1 ;
else if ( V_18 <= 0 )
V_18 = F_22 ( V_15 -> V_29 , V_41 , V_25 , V_12 ) ;
break;
case V_46 :
V_18 = V_3 -> V_4 - V_3 -> V_7 ;
if ( V_18 <= 0 )
V_18 = F_22 ( V_15 -> V_29 , V_41 , V_25 , V_12 ) ;
break;
case V_47 :
V_48:
while ( V_3 -> V_4 != V_3 -> V_7 )
{
V_19 = F_16 ( V_15 , NULL , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
}
if ( F_11 ( V_15 ) & V_35 )
{
if ( V_3 -> V_5 != 0 )
{
V_3 -> V_4 = F_19 (
( unsigned char * ) V_3 -> V_32 ,
( unsigned char * ) V_3 -> V_33 ,
V_3 -> V_5 ) ;
V_3 -> V_7 = 0 ;
V_3 -> V_5 = 0 ;
goto V_48;
}
}
else if ( V_3 -> V_10 != V_43 && V_3 -> V_31 . V_25 != 0 )
{
V_3 -> V_7 = 0 ;
F_23 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 ,
& ( V_3 -> V_4 ) ) ;
goto V_48;
}
V_18 = F_22 ( V_15 -> V_29 , V_41 , V_25 , V_12 ) ;
break;
case V_49 :
F_14 ( V_15 ) ;
V_18 = F_22 ( V_15 -> V_29 , V_41 , V_25 , V_12 ) ;
F_15 ( V_15 ) ;
break;
case V_50 :
break;
case V_51 :
case V_52 :
case V_53 :
default:
V_18 = F_22 ( V_15 -> V_29 , V_41 , V_25 , V_12 ) ;
break;
}
return ( V_18 ) ;
}
static long F_24 ( T_2 * V_15 , int V_41 , T_4 * V_54 )
{
long V_18 = 1 ;
if ( V_15 -> V_29 == NULL ) return ( 0 ) ;
switch ( V_41 )
{
default:
V_18 = F_25 ( V_15 -> V_29 , V_41 , V_54 ) ;
break;
}
return ( V_18 ) ;
}
