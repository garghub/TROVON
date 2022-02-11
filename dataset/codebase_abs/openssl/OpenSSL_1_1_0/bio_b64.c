const T_1 * F_1 ( void )
{
return & V_1 ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_3 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
return 0 ;
V_3 -> V_4 = 1 ;
V_3 -> V_5 = 1 ;
V_3 -> V_6 = F_4 () ;
if ( V_3 -> V_6 == NULL ) {
F_5 ( V_3 ) ;
return 0 ;
}
F_6 ( V_2 , V_3 ) ;
F_7 ( V_2 , 1 ) ;
return 1 ;
}
static int F_8 ( T_2 * V_7 )
{
T_3 * V_3 ;
if ( V_7 == NULL )
return 0 ;
V_3 = F_9 ( V_7 ) ;
if ( V_3 == NULL )
return 0 ;
F_10 ( V_3 -> V_6 ) ;
F_5 ( V_3 ) ;
F_6 ( V_7 , NULL ) ;
F_7 ( V_7 , 0 ) ;
return 1 ;
}
static int F_11 ( T_2 * V_8 , char * V_9 , int V_10 )
{
int V_11 = 0 , V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 , V_19 = 0 ;
T_3 * V_3 ;
unsigned char * V_20 , * V_21 ;
T_2 * V_22 ;
if ( V_9 == NULL )
return ( 0 ) ;
V_3 = ( T_3 * ) F_9 ( V_8 ) ;
V_22 = F_12 ( V_8 ) ;
if ( ( V_3 == NULL ) || ( V_22 == NULL ) )
return 0 ;
F_13 ( V_8 ) ;
if ( V_3 -> V_23 != V_24 ) {
V_3 -> V_23 = V_24 ;
V_3 -> V_25 = 0 ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = 0 ;
F_14 ( V_3 -> V_6 ) ;
}
if ( V_3 -> V_25 > 0 ) {
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_12 = V_3 -> V_25 - V_3 -> V_26 ;
if ( V_12 > V_10 )
V_12 = V_10 ;
F_15 ( V_3 -> V_26 + V_12 < ( int ) sizeof( V_3 -> V_28 ) ) ;
memcpy ( V_9 , & ( V_3 -> V_28 [ V_3 -> V_26 ] ) , V_12 ) ;
V_11 = V_12 ;
V_9 += V_12 ;
V_10 -= V_12 ;
V_3 -> V_26 += V_12 ;
if ( V_3 -> V_25 == V_3 -> V_26 ) {
V_3 -> V_25 = 0 ;
V_3 -> V_26 = 0 ;
}
}
V_19 = 0 ;
while ( V_10 > 0 ) {
if ( V_3 -> V_4 <= 0 )
break;
V_12 = F_16 ( V_22 , & ( V_3 -> V_29 [ V_3 -> V_27 ] ) ,
V_30 - V_3 -> V_27 ) ;
if ( V_12 <= 0 ) {
V_19 = V_12 ;
if ( ! F_17 ( V_22 ) ) {
V_3 -> V_4 = V_12 ;
if ( V_3 -> V_27 == 0 )
break;
else
V_12 = 0 ;
}
else
break;
}
V_12 += V_3 -> V_27 ;
V_3 -> V_27 = V_12 ;
if ( V_3 -> V_5 && ( F_18 ( V_8 ) & V_31 ) ) {
V_3 -> V_27 = 0 ;
} else if ( V_3 -> V_5 ) {
V_21 = V_20 = ( unsigned char * ) V_3 -> V_29 ;
V_18 = 0 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
if ( * ( V_21 ++ ) != '\n' )
continue;
if ( V_3 -> V_32 ) {
V_20 = V_21 ;
V_3 -> V_32 = 0 ;
continue;
}
V_15 = F_19 ( V_3 -> V_6 ,
( unsigned char * ) V_3 -> V_28 ,
& V_18 , V_20 , V_21 - V_20 ) ;
if ( ( V_15 <= 0 ) && ( V_18 == 0 ) && ( V_3 -> V_5 ) )
F_14 ( V_3 -> V_6 ) ;
else {
if ( V_20 != ( unsigned char * )
& ( V_3 -> V_29 [ 0 ] ) ) {
V_12 -= ( V_20 - ( unsigned char * )
& ( V_3 -> V_29 [ 0 ] ) ) ;
for ( V_16 = 0 ; V_16 < V_12 ; V_16 ++ )
V_3 -> V_29 [ V_16 ] = V_20 [ V_16 ] ;
}
F_14 ( V_3 -> V_6 ) ;
V_3 -> V_5 = 0 ;
break;
}
V_20 = V_21 ;
}
if ( ( V_14 == V_12 ) && ( V_18 == 0 ) ) {
if ( V_20 == ( unsigned char * ) & ( V_3 -> V_29 [ 0 ] ) ) {
if ( V_12 == V_30 ) {
V_3 -> V_32 = 1 ;
V_3 -> V_27 = 0 ;
}
} else if ( V_20 != V_21 ) {
V_17 = V_21 - V_20 ;
for ( V_13 = 0 ; V_13 < V_17 ; V_13 ++ )
V_3 -> V_29 [ V_13 ] = V_20 [ V_13 ] ;
V_3 -> V_27 = V_17 ;
}
continue;
} else {
V_3 -> V_27 = 0 ;
}
} else if ( ( V_12 < V_30 ) && ( V_3 -> V_4 > 0 ) ) {
continue;
}
if ( F_18 ( V_8 ) & V_31 ) {
int V_33 , V_34 ;
V_34 = V_12 & ~ 3 ;
V_33 = F_20 ( ( unsigned char * ) V_3 -> V_28 ,
( unsigned char * ) V_3 -> V_29 , V_34 ) ;
if ( V_34 > 2 ) {
if ( V_3 -> V_29 [ V_34 - 1 ] == '=' ) {
V_33 -- ;
if ( V_3 -> V_29 [ V_34 - 2 ] == '=' )
V_33 -- ;
}
}
if ( V_34 != V_12 ) {
memmove ( V_3 -> V_29 , & V_3 -> V_29 [ V_34 ] , V_12 - V_34 ) ;
V_3 -> V_27 = V_12 - V_34 ;
}
V_3 -> V_25 = 0 ;
if ( V_33 > 0 ) {
V_3 -> V_25 = V_33 ;
}
V_12 = V_33 ;
} else {
V_12 = F_19 ( V_3 -> V_6 ,
( unsigned char * ) V_3 -> V_28 , & V_3 -> V_25 ,
( unsigned char * ) V_3 -> V_29 , V_12 ) ;
V_3 -> V_27 = 0 ;
}
V_3 -> V_26 = 0 ;
if ( V_12 < 0 ) {
V_19 = 0 ;
V_3 -> V_25 = 0 ;
break;
}
if ( V_3 -> V_25 <= V_10 )
V_12 = V_3 -> V_25 ;
else
V_12 = V_10 ;
memcpy ( V_9 , V_3 -> V_28 , V_12 ) ;
V_11 += V_12 ;
V_3 -> V_26 = V_12 ;
if ( V_3 -> V_26 == V_3 -> V_25 ) {
V_3 -> V_25 = 0 ;
V_3 -> V_26 = 0 ;
}
V_10 -= V_12 ;
V_9 += V_12 ;
}
F_21 ( V_8 ) ;
return ( ( V_11 == 0 ) ? V_19 : V_11 ) ;
}
static int F_22 ( T_2 * V_8 , const char * V_35 , int V_36 )
{
int V_11 = 0 ;
int V_17 ;
int V_12 ;
T_3 * V_3 ;
T_2 * V_22 ;
V_3 = ( T_3 * ) F_9 ( V_8 ) ;
V_22 = F_12 ( V_8 ) ;
if ( ( V_3 == NULL ) || ( V_22 == NULL ) )
return 0 ;
F_13 ( V_8 ) ;
if ( V_3 -> V_23 != V_37 ) {
V_3 -> V_23 = V_37 ;
V_3 -> V_25 = 0 ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = 0 ;
F_23 ( V_3 -> V_6 ) ;
}
F_15 ( V_3 -> V_26 < ( int ) sizeof( V_3 -> V_28 ) ) ;
F_15 ( V_3 -> V_25 <= ( int ) sizeof( V_3 -> V_28 ) ) ;
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_17 = V_3 -> V_25 - V_3 -> V_26 ;
while ( V_17 > 0 ) {
V_12 = F_24 ( V_22 , & ( V_3 -> V_28 [ V_3 -> V_26 ] ) , V_17 ) ;
if ( V_12 <= 0 ) {
F_21 ( V_8 ) ;
return ( V_12 ) ;
}
F_15 ( V_12 <= V_17 ) ;
V_3 -> V_26 += V_12 ;
F_15 ( V_3 -> V_26 <= ( int ) sizeof( V_3 -> V_28 ) ) ;
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_17 -= V_12 ;
}
V_3 -> V_26 = 0 ;
V_3 -> V_25 = 0 ;
if ( ( V_35 == NULL ) || ( V_36 <= 0 ) )
return ( 0 ) ;
while ( V_36 > 0 ) {
V_17 = ( V_36 > V_30 ) ? V_30 : V_36 ;
if ( F_18 ( V_8 ) & V_31 ) {
if ( V_3 -> V_27 > 0 ) {
F_15 ( V_3 -> V_27 <= 3 ) ;
V_17 = 3 - V_3 -> V_27 ;
if ( V_17 > V_36 )
V_17 = V_36 ;
memcpy ( & ( V_3 -> V_29 [ V_3 -> V_27 ] ) , V_35 , V_17 ) ;
V_3 -> V_27 += V_17 ;
V_11 += V_17 ;
if ( V_3 -> V_27 < 3 )
break;
V_3 -> V_25 =
F_25 ( ( unsigned char * ) V_3 -> V_28 ,
( unsigned char * ) V_3 -> V_29 , V_3 -> V_27 ) ;
F_15 ( V_3 -> V_25 <= ( int ) sizeof( V_3 -> V_28 ) ) ;
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_3 -> V_27 = 0 ;
} else {
if ( V_17 < 3 ) {
memcpy ( V_3 -> V_29 , V_35 , V_17 ) ;
V_3 -> V_27 = V_17 ;
V_11 += V_17 ;
break;
}
V_17 -= V_17 % 3 ;
V_3 -> V_25 =
F_25 ( ( unsigned char * ) V_3 -> V_28 ,
( const unsigned char * ) V_35 , V_17 ) ;
F_15 ( V_3 -> V_25 <= ( int ) sizeof( V_3 -> V_28 ) ) ;
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_11 += V_17 ;
}
} else {
if ( ! F_26 ( V_3 -> V_6 ,
( unsigned char * ) V_3 -> V_28 , & V_3 -> V_25 ,
( unsigned char * ) V_35 , V_17 ) )
return ( ( V_11 == 0 ) ? - 1 : V_11 ) ;
F_15 ( V_3 -> V_25 <= ( int ) sizeof( V_3 -> V_28 ) ) ;
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_11 += V_17 ;
}
V_36 -= V_17 ;
V_35 += V_17 ;
V_3 -> V_26 = 0 ;
V_17 = V_3 -> V_25 ;
while ( V_17 > 0 ) {
V_12 = F_24 ( V_22 , & ( V_3 -> V_28 [ V_3 -> V_26 ] ) , V_17 ) ;
if ( V_12 <= 0 ) {
F_21 ( V_8 ) ;
return ( ( V_11 == 0 ) ? V_12 : V_11 ) ;
}
F_15 ( V_12 <= V_17 ) ;
V_17 -= V_12 ;
V_3 -> V_26 += V_12 ;
F_15 ( V_3 -> V_26 <= ( int ) sizeof( V_3 -> V_28 ) ) ;
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
}
V_3 -> V_25 = 0 ;
V_3 -> V_26 = 0 ;
}
return ( V_11 ) ;
}
static long F_27 ( T_2 * V_8 , int V_38 , long V_18 , void * V_39 )
{
T_3 * V_3 ;
long V_11 = 1 ;
int V_12 ;
T_2 * V_22 ;
V_3 = ( T_3 * ) F_9 ( V_8 ) ;
V_22 = F_12 ( V_8 ) ;
if ( ( V_3 == NULL ) || ( V_22 == NULL ) )
return 0 ;
switch ( V_38 ) {
case V_40 :
V_3 -> V_4 = 1 ;
V_3 -> V_5 = 1 ;
V_3 -> V_23 = V_41 ;
V_11 = F_28 ( V_22 , V_38 , V_18 , V_39 ) ;
break;
case V_42 :
if ( V_3 -> V_4 <= 0 )
V_11 = 1 ;
else
V_11 = F_28 ( V_22 , V_38 , V_18 , V_39 ) ;
break;
case V_43 :
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_11 = V_3 -> V_25 - V_3 -> V_26 ;
if ( ( V_11 == 0 ) && ( V_3 -> V_23 != V_41 )
&& ( F_29 ( V_3 -> V_6 ) != 0 ) )
V_11 = 1 ;
else if ( V_11 <= 0 )
V_11 = F_28 ( V_22 , V_38 , V_18 , V_39 ) ;
break;
case V_44 :
F_15 ( V_3 -> V_25 >= V_3 -> V_26 ) ;
V_11 = V_3 -> V_25 - V_3 -> V_26 ;
if ( V_11 <= 0 )
V_11 = F_28 ( V_22 , V_38 , V_18 , V_39 ) ;
break;
case V_45 :
V_46:
while ( V_3 -> V_25 != V_3 -> V_26 ) {
V_12 = F_22 ( V_8 , NULL , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( F_18 ( V_8 ) & V_31 ) {
if ( V_3 -> V_27 != 0 ) {
V_3 -> V_25 = F_25 ( ( unsigned char * ) V_3 -> V_28 ,
( unsigned char * ) V_3 -> V_29 ,
V_3 -> V_27 ) ;
V_3 -> V_26 = 0 ;
V_3 -> V_27 = 0 ;
goto V_46;
}
} else if ( V_3 -> V_23 != V_41
&& F_29 ( V_3 -> V_6 ) != 0 ) {
V_3 -> V_26 = 0 ;
F_30 ( V_3 -> V_6 ,
( unsigned char * ) V_3 -> V_28 , & ( V_3 -> V_25 ) ) ;
goto V_46;
}
V_11 = F_28 ( V_22 , V_38 , V_18 , V_39 ) ;
break;
case V_47 :
F_13 ( V_8 ) ;
V_11 = F_28 ( V_22 , V_38 , V_18 , V_39 ) ;
F_21 ( V_8 ) ;
break;
case V_48 :
break;
case V_49 :
case V_50 :
case V_51 :
default:
V_11 = F_28 ( V_22 , V_38 , V_18 , V_39 ) ;
break;
}
return V_11 ;
}
static long F_31 ( T_2 * V_8 , int V_38 , T_4 * V_52 )
{
long V_11 = 1 ;
T_2 * V_22 = F_12 ( V_8 ) ;
if ( V_22 == NULL )
return 0 ;
switch ( V_38 ) {
default:
V_11 = F_32 ( V_22 , V_38 , V_52 ) ;
break;
}
return ( V_11 ) ;
}
static int F_33 ( T_2 * V_8 , const char * V_53 )
{
return F_22 ( V_8 , V_53 , strlen ( V_53 ) ) ;
}
