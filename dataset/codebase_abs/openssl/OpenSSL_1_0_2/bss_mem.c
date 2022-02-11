T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
T_2 * F_2 ( void * V_2 , int V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_4 V_6 ;
if ( ! V_2 ) {
F_3 ( V_7 , V_8 ) ;
return NULL ;
}
V_6 = ( V_3 < 0 ) ? strlen ( V_2 ) : ( T_4 ) V_3 ;
if ( ! ( V_4 = F_4 ( F_1 () ) ) )
return NULL ;
V_5 = ( T_3 * ) V_4 -> V_9 ;
V_5 -> V_10 = V_2 ;
V_5 -> V_11 = V_6 ;
V_5 -> V_12 = V_6 ;
V_4 -> V_13 |= V_14 ;
V_4 -> V_15 = 0 ;
return V_4 ;
}
static int F_5 ( T_2 * V_16 )
{
T_3 * V_5 ;
if ( ( V_5 = F_6 () ) == NULL )
return ( 0 ) ;
V_16 -> V_17 = 1 ;
V_16 -> V_18 = 1 ;
V_16 -> V_15 = - 1 ;
V_16 -> V_9 = ( char * ) V_5 ;
return ( 1 ) ;
}
static int F_7 ( T_2 * V_19 )
{
if ( V_19 == NULL )
return ( 0 ) ;
if ( V_19 -> V_17 ) {
if ( ( V_19 -> V_18 ) && ( V_19 -> V_9 != NULL ) ) {
T_3 * V_5 ;
V_5 = ( T_3 * ) V_19 -> V_9 ;
if ( V_19 -> V_13 & V_14 )
V_5 -> V_10 = NULL ;
F_8 ( V_5 ) ;
V_19 -> V_9 = NULL ;
}
}
return ( 1 ) ;
}
static int F_9 ( T_2 * V_5 , char * V_20 , int V_21 )
{
int V_4 = - 1 ;
T_3 * V_22 ;
V_22 = ( T_3 * ) V_5 -> V_9 ;
F_10 ( V_5 ) ;
V_4 = ( V_21 >= 0 && ( T_4 ) V_21 > V_22 -> V_11 ) ? ( int ) V_22 -> V_11 : V_21 ;
if ( ( V_20 != NULL ) && ( V_4 > 0 ) ) {
memcpy ( V_20 , V_22 -> V_10 , V_4 ) ;
V_22 -> V_11 -= V_4 ;
if ( V_5 -> V_13 & V_14 )
V_22 -> V_10 += V_4 ;
else {
memmove ( & ( V_22 -> V_10 [ 0 ] ) , & ( V_22 -> V_10 [ V_4 ] ) , V_22 -> V_11 ) ;
}
} else if ( V_22 -> V_11 == 0 ) {
V_4 = V_5 -> V_15 ;
if ( V_4 != 0 )
F_11 ( V_5 ) ;
}
return ( V_4 ) ;
}
static int F_12 ( T_2 * V_5 , const char * V_23 , int V_24 )
{
int V_4 = - 1 ;
int V_25 ;
T_3 * V_22 ;
V_22 = ( T_3 * ) V_5 -> V_9 ;
if ( V_23 == NULL ) {
F_3 ( V_26 , V_8 ) ;
goto V_27;
}
if ( V_5 -> V_13 & V_14 ) {
F_3 ( V_26 , V_28 ) ;
goto V_27;
}
F_10 ( V_5 ) ;
V_25 = V_22 -> V_11 ;
if ( F_13 ( V_22 , V_25 + V_24 ) != ( V_25 + V_24 ) )
goto V_27;
memcpy ( & ( V_22 -> V_10 [ V_25 ] ) , V_23 , V_24 ) ;
V_4 = V_24 ;
V_27:
return ( V_4 ) ;
}
static long F_14 ( T_2 * V_5 , int V_29 , long V_15 , void * V_9 )
{
long V_4 = 1 ;
char * * V_30 ;
T_3 * V_22 = ( T_3 * ) V_5 -> V_9 ;
switch ( V_29 ) {
case V_31 :
if ( V_22 -> V_10 != NULL ) {
if ( V_5 -> V_13 & V_14 ) {
V_22 -> V_10 -= V_22 -> V_12 - V_22 -> V_11 ;
V_22 -> V_11 = V_22 -> V_12 ;
} else {
memset ( V_22 -> V_10 , 0 , V_22 -> V_12 ) ;
V_22 -> V_11 = 0 ;
}
}
break;
case V_32 :
V_4 = ( long ) ( V_22 -> V_11 == 0 ) ;
break;
case V_33 :
V_5 -> V_15 = ( int ) V_15 ;
break;
case V_34 :
V_4 = ( long ) V_22 -> V_11 ;
if ( V_9 != NULL ) {
V_30 = ( char * * ) V_9 ;
* V_30 = ( char * ) & ( V_22 -> V_10 [ 0 ] ) ;
}
break;
case V_35 :
F_7 ( V_5 ) ;
V_5 -> V_17 = ( int ) V_15 ;
V_5 -> V_9 = V_9 ;
break;
case V_36 :
if ( V_9 != NULL ) {
V_30 = ( char * * ) V_9 ;
* V_30 = ( char * ) V_22 ;
}
break;
case V_37 :
V_4 = ( long ) V_5 -> V_17 ;
break;
case V_38 :
V_5 -> V_17 = ( int ) V_15 ;
break;
case V_39 :
V_4 = 0L ;
break;
case V_40 :
V_4 = ( long ) V_22 -> V_11 ;
break;
case V_41 :
case V_42 :
V_4 = 1 ;
break;
case V_43 :
case V_44 :
default:
V_4 = 0 ;
break;
}
return ( V_4 ) ;
}
static int F_15 ( T_2 * V_45 , char * V_2 , int V_46 )
{
int V_47 , V_48 ;
int V_4 = - 1 ;
char * V_49 ;
T_3 * V_22 = ( T_3 * ) V_45 -> V_9 ;
F_10 ( V_45 ) ;
V_48 = V_22 -> V_11 ;
if ( ( V_46 - 1 ) < V_48 )
V_48 = V_46 - 1 ;
if ( V_48 <= 0 ) {
* V_2 = '\0' ;
return 0 ;
}
V_49 = V_22 -> V_10 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
if ( V_49 [ V_47 ] == '\n' ) {
V_47 ++ ;
break;
}
}
V_47 = F_9 ( V_45 , V_2 , V_47 ) ;
if ( V_47 > 0 )
V_2 [ V_47 ] = '\0' ;
V_4 = V_47 ;
return ( V_4 ) ;
}
static int F_16 ( T_2 * V_45 , const char * V_50 )
{
int V_51 , V_4 ;
V_51 = strlen ( V_50 ) ;
V_4 = F_12 ( V_45 , V_50 , V_51 ) ;
return ( V_4 ) ;
}
