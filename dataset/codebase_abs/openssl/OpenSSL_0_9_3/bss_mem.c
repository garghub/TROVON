T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
if ( ( V_3 = F_3 () ) == NULL )
return ( 0 ) ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = 1 ;
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = ( char * ) V_3 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_8 )
{
if ( V_8 == NULL ) return ( 0 ) ;
if ( V_8 -> V_4 )
{
if ( ( V_8 -> V_5 ) && ( V_8 -> V_7 != NULL ) )
{
F_5 ( ( T_3 * ) V_8 -> V_7 ) ;
V_8 -> V_7 = NULL ;
}
}
return ( 1 ) ;
}
static int F_6 ( T_2 * V_3 , char * V_9 , int V_10 )
{
int V_11 = - 1 ;
T_3 * V_12 ;
int V_13 ;
char * V_14 , * V_15 ;
V_12 = ( T_3 * ) V_3 -> V_7 ;
F_7 ( V_3 ) ;
V_11 = ( V_10 > V_12 -> V_16 ) ? V_12 -> V_16 : V_10 ;
if ( ( V_9 != NULL ) && ( V_11 > 0 ) )
{
memcpy ( V_9 , V_12 -> V_17 , V_11 ) ;
V_12 -> V_16 -= V_11 ;
V_14 = ( char * ) & ( V_12 -> V_17 [ V_11 ] ) ;
V_15 = ( char * ) & ( V_12 -> V_17 [ 0 ] ) ;
for ( V_13 = 0 ; V_13 < V_12 -> V_16 ; V_13 ++ )
V_15 [ V_13 ] = V_14 [ V_13 ] ;
}
else if ( V_12 -> V_16 == 0 )
{
if ( V_3 -> V_6 != 0 )
F_8 ( V_3 ) ;
V_11 = V_3 -> V_6 ;
}
return ( V_11 ) ;
}
static int F_9 ( T_2 * V_3 , char * V_18 , int V_19 )
{
int V_11 = - 1 ;
int V_20 ;
T_3 * V_12 ;
V_12 = ( T_3 * ) V_3 -> V_7 ;
if ( V_18 == NULL )
{
F_10 ( V_21 , V_22 ) ;
goto V_23;
}
F_7 ( V_3 ) ;
V_20 = V_12 -> V_16 ;
if ( F_11 ( V_12 , V_20 + V_19 ) != ( V_20 + V_19 ) )
goto V_23;
memcpy ( & ( V_12 -> V_17 [ V_20 ] ) , V_18 , V_19 ) ;
V_11 = V_19 ;
V_23:
return ( V_11 ) ;
}
static long F_12 ( T_2 * V_3 , int V_24 , long V_6 , char * V_7 )
{
long V_11 = 1 ;
char * * V_25 ;
T_3 * V_12 = ( T_3 * ) V_3 -> V_7 ;
switch ( V_24 )
{
case V_26 :
if ( V_12 -> V_17 != NULL )
memset ( V_12 -> V_17 , 0 , V_12 -> V_27 ) ;
V_12 -> V_16 = 0 ;
break;
case V_28 :
V_11 = ( long ) ( V_12 -> V_16 == 0 ) ;
break;
case V_29 :
V_3 -> V_6 = ( int ) V_6 ;
break;
case V_30 :
V_11 = ( long ) V_12 -> V_16 ;
if ( V_7 != NULL )
{
V_25 = ( char * * ) V_7 ;
* V_25 = ( char * ) & ( V_12 -> V_17 [ 0 ] ) ;
}
break;
case V_31 :
F_4 ( V_3 ) ;
V_3 -> V_4 = ( int ) V_6 ;
V_3 -> V_7 = V_7 ;
break;
case V_32 :
if ( V_7 != NULL )
{
V_25 = ( char * * ) V_7 ;
* V_25 = ( char * ) V_12 ;
}
break;
case V_33 :
V_11 = ( long ) V_3 -> V_4 ;
break;
case V_34 :
V_3 -> V_4 = ( int ) V_6 ;
break;
case V_35 :
V_11 = 0L ;
break;
case V_36 :
V_11 = ( long ) V_12 -> V_16 ;
break;
case V_37 :
case V_38 :
V_11 = 1 ;
break;
case V_39 :
case V_40 :
default:
V_11 = 0 ;
break;
}
return ( V_11 ) ;
}
static int F_13 ( T_2 * V_41 , char * V_42 , int V_43 )
{
int V_13 , V_44 ;
int V_11 = - 1 ;
char * V_45 ;
T_3 * V_12 = ( T_3 * ) V_41 -> V_7 ;
F_7 ( V_41 ) ;
V_44 = V_12 -> V_16 ;
if ( V_44 <= 0 ) return ( 0 ) ;
V_45 = V_12 -> V_17 ;
for ( V_13 = 0 ; V_13 < V_44 ; V_13 ++ )
{
if ( V_45 [ V_13 ] == '\n' ) break;
}
if ( V_13 == V_44 )
{
F_8 ( V_41 ) ;
}
else
V_13 ++ ;
if ( ( V_43 - 1 ) < V_13 ) V_13 = V_43 - 1 ;
V_13 = F_6 ( V_41 , V_42 , V_13 ) ;
if ( V_13 > 0 ) V_42 [ V_13 ] = '\0' ;
V_11 = V_13 ;
return ( V_11 ) ;
}
static int F_14 ( T_2 * V_41 , char * V_46 )
{
int V_47 , V_11 ;
V_47 = strlen ( V_46 ) ;
V_11 = F_9 ( V_41 , V_46 , V_47 ) ;
return ( V_11 ) ;
}
