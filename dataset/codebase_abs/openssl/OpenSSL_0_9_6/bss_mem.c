T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( void * V_2 , int V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
if ( ! V_2 ) {
F_3 ( V_6 , V_7 ) ;
return NULL ;
}
if( V_3 == - 1 ) V_3 = strlen ( V_2 ) ;
if( ! ( V_4 = F_4 ( F_1 () ) ) ) return NULL ;
V_5 = ( T_3 * ) V_4 -> V_8 ;
V_5 -> V_9 = V_2 ;
V_5 -> V_10 = V_3 ;
V_5 -> V_11 = V_3 ;
V_4 -> V_12 |= V_13 ;
V_4 -> V_14 = 0 ;
return V_4 ;
}
static int F_5 ( T_2 * V_15 )
{
T_3 * V_5 ;
if ( ( V_5 = F_6 () ) == NULL )
return ( 0 ) ;
V_15 -> V_16 = 1 ;
V_15 -> V_17 = 1 ;
V_15 -> V_14 = - 1 ;
V_15 -> V_8 = ( char * ) V_5 ;
return ( 1 ) ;
}
static int F_7 ( T_2 * V_18 )
{
if ( V_18 == NULL ) return ( 0 ) ;
if ( V_18 -> V_16 )
{
if ( ( V_18 -> V_17 ) && ( V_18 -> V_8 != NULL ) )
{
T_3 * V_5 ;
V_5 = ( T_3 * ) V_18 -> V_8 ;
if( V_18 -> V_12 & V_13 ) V_5 -> V_9 = NULL ;
F_8 ( V_5 ) ;
V_18 -> V_8 = NULL ;
}
}
return ( 1 ) ;
}
static int F_9 ( T_2 * V_5 , char * V_19 , int V_20 )
{
int V_4 = - 1 ;
T_3 * V_21 ;
int V_22 ;
char * V_23 , * V_24 ;
V_21 = ( T_3 * ) V_5 -> V_8 ;
F_10 ( V_5 ) ;
V_4 = ( V_20 > V_21 -> V_10 ) ? V_21 -> V_10 : V_20 ;
if ( ( V_19 != NULL ) && ( V_4 > 0 ) ) {
memcpy ( V_19 , V_21 -> V_9 , V_4 ) ;
V_21 -> V_10 -= V_4 ;
if( V_5 -> V_12 & V_13 ) V_21 -> V_9 += V_4 ;
else {
V_23 = ( char * ) & ( V_21 -> V_9 [ V_4 ] ) ;
V_24 = ( char * ) & ( V_21 -> V_9 [ 0 ] ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_10 ; V_22 ++ )
V_24 [ V_22 ] = V_23 [ V_22 ] ;
}
} else if ( V_21 -> V_10 == 0 )
{
V_4 = V_5 -> V_14 ;
if ( V_4 != 0 )
F_11 ( V_5 ) ;
}
return ( V_4 ) ;
}
static int F_12 ( T_2 * V_5 , const char * V_25 , int V_26 )
{
int V_4 = - 1 ;
int V_27 ;
T_3 * V_21 ;
V_21 = ( T_3 * ) V_5 -> V_8 ;
if ( V_25 == NULL )
{
F_3 ( V_28 , V_7 ) ;
goto V_29;
}
if( V_5 -> V_12 & V_13 ) {
F_3 ( V_28 , V_30 ) ;
goto V_29;
}
F_10 ( V_5 ) ;
V_27 = V_21 -> V_10 ;
if ( F_13 ( V_21 , V_27 + V_26 ) != ( V_27 + V_26 ) )
goto V_29;
memcpy ( & ( V_21 -> V_9 [ V_27 ] ) , V_25 , V_26 ) ;
V_4 = V_26 ;
V_29:
return ( V_4 ) ;
}
static long F_14 ( T_2 * V_5 , int V_31 , long V_14 , void * V_8 )
{
long V_4 = 1 ;
char * * V_32 ;
T_3 * V_21 = ( T_3 * ) V_5 -> V_8 ;
switch ( V_31 )
{
case V_33 :
if ( V_21 -> V_9 != NULL )
{
if( V_5 -> V_12 & V_13 )
{
V_21 -> V_9 -= V_21 -> V_11 - V_21 -> V_10 ;
V_21 -> V_10 = V_21 -> V_11 ;
}
else
{
memset ( V_21 -> V_9 , 0 , V_21 -> V_11 ) ;
V_21 -> V_10 = 0 ;
}
}
break;
case V_34 :
V_4 = ( long ) ( V_21 -> V_10 == 0 ) ;
break;
case V_35 :
V_5 -> V_14 = ( int ) V_14 ;
break;
case V_36 :
V_4 = ( long ) V_21 -> V_10 ;
if ( V_8 != NULL )
{
V_32 = ( char * * ) V_8 ;
* V_32 = ( char * ) & ( V_21 -> V_9 [ 0 ] ) ;
}
break;
case V_37 :
F_7 ( V_5 ) ;
V_5 -> V_16 = ( int ) V_14 ;
V_5 -> V_8 = V_8 ;
break;
case V_38 :
if ( V_8 != NULL )
{
V_32 = ( char * * ) V_8 ;
* V_32 = ( char * ) V_21 ;
}
break;
case V_39 :
V_4 = ( long ) V_5 -> V_16 ;
break;
case V_40 :
V_5 -> V_16 = ( int ) V_14 ;
break;
case V_41 :
V_4 = 0L ;
break;
case V_42 :
V_4 = ( long ) V_21 -> V_10 ;
break;
case V_43 :
case V_44 :
V_4 = 1 ;
break;
case V_45 :
case V_46 :
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_15 ( T_2 * V_47 , char * V_2 , int V_48 )
{
int V_22 , V_49 ;
int V_4 = - 1 ;
char * V_50 ;
T_3 * V_21 = ( T_3 * ) V_47 -> V_8 ;
F_10 ( V_47 ) ;
V_49 = V_21 -> V_10 ;
if ( V_49 <= 0 ) return ( 0 ) ;
V_50 = V_21 -> V_9 ;
for ( V_22 = 0 ; V_22 < V_49 ; V_22 ++ )
{
if ( V_50 [ V_22 ] == '\n' ) break;
}
if ( V_22 == V_49 )
{
F_11 ( V_47 ) ;
}
else
V_22 ++ ;
if ( ( V_48 - 1 ) < V_22 ) V_22 = V_48 - 1 ;
V_22 = F_9 ( V_47 , V_2 , V_22 ) ;
if ( V_22 > 0 ) V_2 [ V_22 ] = '\0' ;
V_4 = V_22 ;
return ( V_4 ) ;
}
static int F_16 ( T_2 * V_47 , const char * V_51 )
{
int V_52 , V_4 ;
V_52 = strlen ( V_51 ) ;
V_4 = F_12 ( V_47 , V_51 , V_52 ) ;
return ( V_4 ) ;
}
