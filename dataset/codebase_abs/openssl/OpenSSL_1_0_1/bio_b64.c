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
V_2 -> V_14 = 0 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_15 )
{
if ( V_15 == NULL ) return ( 0 ) ;
F_5 ( V_15 -> V_12 ) ;
V_15 -> V_12 = NULL ;
V_15 -> V_11 = 0 ;
V_15 -> V_13 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_16 , char * V_17 , int V_18 )
{
int V_19 = 0 , V_20 , V_21 , V_22 , V_23 , V_24 , V_25 , V_14 , V_26 = 0 ;
T_3 * V_3 ;
unsigned char * V_27 , * V_28 ;
if ( V_17 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_16 -> V_12 ;
if ( ( V_3 == NULL ) || ( V_16 -> V_29 == NULL ) ) return ( 0 ) ;
F_7 ( V_16 ) ;
if ( V_3 -> V_10 != V_30 )
{
V_3 -> V_10 = V_30 ;
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_5 = 0 ;
F_8 ( & ( V_3 -> V_31 ) ) ;
}
if ( V_3 -> V_4 > 0 )
{
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_20 = V_3 -> V_4 - V_3 -> V_7 ;
if ( V_20 > V_18 ) V_20 = V_18 ;
F_9 ( V_3 -> V_7 + V_20 < ( int ) sizeof( V_3 -> V_32 ) ) ;
memcpy ( V_17 , & ( V_3 -> V_32 [ V_3 -> V_7 ] ) , V_20 ) ;
V_19 = V_20 ;
V_17 += V_20 ;
V_18 -= V_20 ;
V_3 -> V_7 += V_20 ;
if ( V_3 -> V_4 == V_3 -> V_7 )
{
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
}
}
V_26 = 0 ;
while ( V_18 > 0 )
{
if ( V_3 -> V_8 <= 0 )
break;
V_20 = F_10 ( V_16 -> V_29 , & ( V_3 -> V_33 [ V_3 -> V_5 ] ) ,
V_34 - V_3 -> V_5 ) ;
if ( V_20 <= 0 )
{
V_26 = V_20 ;
if ( ! F_11 ( V_16 -> V_29 ) )
{
V_3 -> V_8 = V_20 ;
if( V_3 -> V_5 == 0 )
break;
else
V_20 = 0 ;
}
else
break;
}
V_20 += V_3 -> V_5 ;
V_3 -> V_5 = V_20 ;
if ( V_3 -> V_9 && ( F_12 ( V_16 ) & V_35 ) )
{
V_3 -> V_5 = 0 ;
}
else if ( V_3 -> V_9 )
{
V_28 = V_27 = ( unsigned char * ) V_3 -> V_33 ;
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
{
if ( * ( V_28 ++ ) != '\n' ) continue;
if ( V_3 -> V_6 )
{
V_27 = V_28 ;
V_3 -> V_6 = 0 ;
continue;
}
V_23 = F_13 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 ,
& V_14 , V_27 , V_28 - V_27 ) ;
if ( ( V_23 <= 0 ) && ( V_14 == 0 ) && ( V_3 -> V_9 ) )
F_8 ( & V_3 -> V_31 ) ;
else
{
if ( V_27 != ( unsigned char * )
& ( V_3 -> V_33 [ 0 ] ) )
{
V_20 -= ( V_27 - ( unsigned char * )
& ( V_3 -> V_33 [ 0 ] ) ) ;
for ( V_24 = 0 ; V_24 < V_20 ; V_24 ++ )
V_3 -> V_33 [ V_24 ] = V_27 [ V_24 ] ;
}
F_8 ( & V_3 -> V_31 ) ;
V_3 -> V_9 = 0 ;
break;
}
V_27 = V_28 ;
}
if ( V_22 == V_20 )
{
if ( V_27 == ( unsigned char * ) & ( V_3 -> V_33 [ 0 ] ) )
{
if ( V_20 == V_34 )
{
V_3 -> V_6 = 1 ;
V_3 -> V_5 = 0 ;
}
}
else if ( V_27 != V_28 )
{
V_25 = V_28 - V_27 ;
for ( V_21 = 0 ; V_21 < V_25 ; V_21 ++ )
V_3 -> V_33 [ V_21 ] = V_27 [ V_21 ] ;
V_3 -> V_5 = V_25 ;
}
continue;
}
else
{
V_3 -> V_5 = 0 ;
}
}
else if ( ( V_20 < V_34 ) && ( V_3 -> V_8 > 0 ) )
{
continue;
}
if ( F_12 ( V_16 ) & V_35 )
{
int V_36 , V_37 ;
#if 0
jj=(i>>2)<<2;
#else
V_37 = V_20 & ~ 3 ;
#endif
V_36 = F_14 ( ( unsigned char * ) V_3 -> V_32 ,
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
if ( V_37 != V_20 )
{
memmove ( V_3 -> V_33 , & V_3 -> V_33 [ V_37 ] , V_20 - V_37 ) ;
V_3 -> V_5 = V_20 - V_37 ;
}
V_3 -> V_4 = 0 ;
if ( V_36 > 0 )
{
V_3 -> V_4 = V_36 ;
}
V_20 = V_36 ;
}
else
{
V_20 = F_13 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 , & V_3 -> V_4 ,
( unsigned char * ) V_3 -> V_33 , V_20 ) ;
V_3 -> V_5 = 0 ;
}
V_3 -> V_7 = 0 ;
if ( V_20 < 0 )
{
V_26 = 0 ;
V_3 -> V_4 = 0 ;
break;
}
if ( V_3 -> V_4 <= V_18 )
V_20 = V_3 -> V_4 ;
else
V_20 = V_18 ;
memcpy ( V_17 , V_3 -> V_32 , V_20 ) ;
V_19 += V_20 ;
V_3 -> V_7 = V_20 ;
if ( V_3 -> V_7 == V_3 -> V_4 )
{
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
}
V_18 -= V_20 ;
V_17 += V_20 ;
}
F_15 ( V_16 ) ;
return ( ( V_19 == 0 ) ? V_26 : V_19 ) ;
}
static int F_16 ( T_2 * V_16 , const char * V_38 , int V_39 )
{
int V_19 = 0 ;
int V_25 ;
int V_20 ;
T_3 * V_3 ;
V_3 = ( T_3 * ) V_16 -> V_12 ;
F_7 ( V_16 ) ;
if ( V_3 -> V_10 != V_40 )
{
V_3 -> V_10 = V_40 ;
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_5 = 0 ;
F_17 ( & ( V_3 -> V_31 ) ) ;
}
F_9 ( V_3 -> V_7 < ( int ) sizeof( V_3 -> V_32 ) ) ;
F_9 ( V_3 -> V_4 <= ( int ) sizeof( V_3 -> V_32 ) ) ;
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_25 = V_3 -> V_4 - V_3 -> V_7 ;
while ( V_25 > 0 )
{
V_20 = F_18 ( V_16 -> V_29 , & ( V_3 -> V_32 [ V_3 -> V_7 ] ) , V_25 ) ;
if ( V_20 <= 0 )
{
F_15 ( V_16 ) ;
return ( V_20 ) ;
}
F_9 ( V_20 <= V_25 ) ;
V_3 -> V_7 += V_20 ;
F_9 ( V_3 -> V_7 <= ( int ) sizeof( V_3 -> V_32 ) ) ;
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_25 -= V_20 ;
}
V_3 -> V_7 = 0 ;
V_3 -> V_4 = 0 ;
if ( ( V_38 == NULL ) || ( V_39 <= 0 ) ) return ( 0 ) ;
while ( V_39 > 0 )
{
V_25 = ( V_39 > V_34 ) ? V_34 : V_39 ;
if ( F_12 ( V_16 ) & V_35 )
{
if ( V_3 -> V_5 > 0 )
{
F_9 ( V_3 -> V_5 <= 3 ) ;
V_25 = 3 - V_3 -> V_5 ;
if ( V_25 > V_39 )
V_25 = V_39 ;
memcpy ( & ( V_3 -> V_33 [ V_3 -> V_5 ] ) , V_38 , V_25 ) ;
V_3 -> V_5 += V_25 ;
V_19 += V_25 ;
if ( V_3 -> V_5 < 3 )
break;
V_3 -> V_4 = F_19 ( ( unsigned char * ) V_3 -> V_32 , ( unsigned char * ) V_3 -> V_33 , V_3 -> V_5 ) ;
F_9 ( V_3 -> V_4 <= ( int ) sizeof( V_3 -> V_32 ) ) ;
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_3 -> V_5 = 0 ;
}
else
{
if ( V_25 < 3 )
{
memcpy ( V_3 -> V_33 , V_38 , V_25 ) ;
V_3 -> V_5 = V_25 ;
V_19 += V_25 ;
break;
}
V_25 -= V_25 % 3 ;
V_3 -> V_4 = F_19 ( ( unsigned char * ) V_3 -> V_32 , ( const unsigned char * ) V_38 , V_25 ) ;
F_9 ( V_3 -> V_4 <= ( int ) sizeof( V_3 -> V_32 ) ) ;
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_19 += V_25 ;
}
}
else
{
F_20 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 , & V_3 -> V_4 ,
( unsigned char * ) V_38 , V_25 ) ;
F_9 ( V_3 -> V_4 <= ( int ) sizeof( V_3 -> V_32 ) ) ;
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_19 += V_25 ;
}
V_39 -= V_25 ;
V_38 += V_25 ;
V_3 -> V_7 = 0 ;
V_25 = V_3 -> V_4 ;
while ( V_25 > 0 )
{
V_20 = F_18 ( V_16 -> V_29 , & ( V_3 -> V_32 [ V_3 -> V_7 ] ) , V_25 ) ;
if ( V_20 <= 0 )
{
F_15 ( V_16 ) ;
return ( ( V_19 == 0 ) ? V_20 : V_19 ) ;
}
F_9 ( V_20 <= V_25 ) ;
V_25 -= V_20 ;
V_3 -> V_7 += V_20 ;
F_9 ( V_3 -> V_7 <= ( int ) sizeof( V_3 -> V_32 ) ) ;
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
}
V_3 -> V_4 = 0 ;
V_3 -> V_7 = 0 ;
}
return ( V_19 ) ;
}
static long F_21 ( T_2 * V_16 , int V_41 , long V_14 , void * V_12 )
{
T_3 * V_3 ;
long V_19 = 1 ;
int V_20 ;
V_3 = ( T_3 * ) V_16 -> V_12 ;
switch ( V_41 )
{
case V_42 :
V_3 -> V_8 = 1 ;
V_3 -> V_9 = 1 ;
V_3 -> V_10 = V_43 ;
V_19 = F_22 ( V_16 -> V_29 , V_41 , V_14 , V_12 ) ;
break;
case V_44 :
if ( V_3 -> V_8 <= 0 )
V_19 = 1 ;
else
V_19 = F_22 ( V_16 -> V_29 , V_41 , V_14 , V_12 ) ;
break;
case V_45 :
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_19 = V_3 -> V_4 - V_3 -> V_7 ;
if ( ( V_19 == 0 ) && ( V_3 -> V_10 != V_43 )
&& ( V_3 -> V_31 . V_14 != 0 ) )
V_19 = 1 ;
else if ( V_19 <= 0 )
V_19 = F_22 ( V_16 -> V_29 , V_41 , V_14 , V_12 ) ;
break;
case V_46 :
F_9 ( V_3 -> V_4 >= V_3 -> V_7 ) ;
V_19 = V_3 -> V_4 - V_3 -> V_7 ;
if ( V_19 <= 0 )
V_19 = F_22 ( V_16 -> V_29 , V_41 , V_14 , V_12 ) ;
break;
case V_47 :
V_48:
while ( V_3 -> V_4 != V_3 -> V_7 )
{
V_20 = F_16 ( V_16 , NULL , 0 ) ;
if ( V_20 < 0 )
return V_20 ;
}
if ( F_12 ( V_16 ) & V_35 )
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
else if ( V_3 -> V_10 != V_43 && V_3 -> V_31 . V_14 != 0 )
{
V_3 -> V_7 = 0 ;
F_23 ( & ( V_3 -> V_31 ) ,
( unsigned char * ) V_3 -> V_32 ,
& ( V_3 -> V_4 ) ) ;
goto V_48;
}
V_19 = F_22 ( V_16 -> V_29 , V_41 , V_14 , V_12 ) ;
break;
case V_49 :
F_7 ( V_16 ) ;
V_19 = F_22 ( V_16 -> V_29 , V_41 , V_14 , V_12 ) ;
F_15 ( V_16 ) ;
break;
case V_50 :
break;
case V_51 :
case V_52 :
case V_53 :
default:
V_19 = F_22 ( V_16 -> V_29 , V_41 , V_14 , V_12 ) ;
break;
}
return ( V_19 ) ;
}
static long F_24 ( T_2 * V_16 , int V_41 , T_4 * V_54 )
{
long V_19 = 1 ;
if ( V_16 -> V_29 == NULL ) return ( 0 ) ;
switch ( V_41 )
{
default:
V_19 = F_25 ( V_16 -> V_29 , V_41 , V_54 ) ;
break;
}
return ( V_19 ) ;
}
static int F_26 ( T_2 * V_16 , const char * V_55 )
{
return F_16 ( V_16 , V_55 , strlen ( V_55 ) ) ;
}
