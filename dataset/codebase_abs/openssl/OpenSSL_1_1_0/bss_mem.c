const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
const T_1 * F_2 ( void )
{
return ( & V_2 ) ;
}
T_2 * F_3 ( const void * V_3 , int V_4 )
{
T_2 * V_5 ;
T_3 * V_6 ;
T_4 * V_7 ;
T_5 V_8 ;
if ( V_3 == NULL ) {
F_4 ( V_9 , V_10 ) ;
return NULL ;
}
V_8 = ( V_4 < 0 ) ? strlen ( V_3 ) : ( T_5 ) V_4 ;
if ( ( V_5 = F_5 ( F_1 () ) ) == NULL )
return NULL ;
V_7 = ( T_4 * ) V_5 -> V_11 ;
V_6 = V_7 -> V_3 ;
V_6 -> V_12 = ( void * ) V_3 ;
V_6 -> V_13 = V_8 ;
V_6 -> V_14 = V_8 ;
* V_7 -> V_15 = * V_7 -> V_3 ;
V_5 -> V_16 |= V_17 ;
V_5 -> V_18 = 0 ;
return V_5 ;
}
static int F_6 ( T_2 * V_19 , unsigned long V_16 )
{
T_4 * V_7 = F_7 ( sizeof( * V_7 ) ) ;
if ( V_7 == NULL )
return 0 ;
if ( ( V_7 -> V_3 = F_8 ( V_16 ) ) == NULL ) {
F_9 ( V_7 ) ;
return 0 ;
}
if ( ( V_7 -> V_15 = F_7 ( sizeof( * V_7 -> V_15 ) ) ) == NULL ) {
F_10 ( V_7 -> V_3 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
* V_7 -> V_15 = * V_7 -> V_3 ;
V_19 -> V_20 = 1 ;
V_19 -> V_21 = 1 ;
V_19 -> V_18 = - 1 ;
V_19 -> V_11 = ( char * ) V_7 ;
return 1 ;
}
static int F_11 ( T_2 * V_19 )
{
return ( F_6 ( V_19 , 0L ) ) ;
}
static int F_12 ( T_2 * V_19 )
{
return ( F_6 ( V_19 , V_22 ) ) ;
}
static int F_13 ( T_2 * V_23 )
{
return ( F_14 ( V_23 , 1 ) ) ;
}
static int F_14 ( T_2 * V_23 , int V_24 )
{
if ( V_23 == NULL )
return ( 0 ) ;
if ( V_23 -> V_20 ) {
if ( ( V_23 -> V_21 ) && ( V_23 -> V_11 != NULL ) ) {
T_3 * V_6 ;
T_4 * V_7 = ( T_4 * ) V_23 -> V_11 ;
if ( V_7 != NULL ) {
V_6 = V_7 -> V_3 ;
if ( V_23 -> V_16 & V_17 )
V_6 -> V_12 = NULL ;
F_10 ( V_6 ) ;
if ( V_24 ) {
F_9 ( V_7 -> V_15 ) ;
F_9 ( V_7 ) ;
}
}
V_23 -> V_11 = NULL ;
}
}
return ( 1 ) ;
}
static int F_15 ( T_2 * V_6 )
{
if ( V_6 != NULL && V_6 -> V_21 != 0 && V_6 -> V_11 != NULL ) {
T_4 * V_25 = ( T_4 * ) V_6 -> V_11 ;
if ( V_25 -> V_15 -> V_12 != V_25 -> V_3 -> V_12 ) {
memmove ( V_25 -> V_3 -> V_12 , V_25 -> V_15 -> V_12 , V_25 -> V_15 -> V_13 ) ;
V_25 -> V_3 -> V_13 = V_25 -> V_15 -> V_13 ;
V_25 -> V_15 -> V_12 = V_25 -> V_3 -> V_12 ;
}
}
return ( 0 ) ;
}
static int F_16 ( T_2 * V_6 , char * V_26 , int V_27 )
{
int V_5 = - 1 ;
T_4 * V_25 = ( T_4 * ) V_6 -> V_11 ;
T_3 * V_28 = V_25 -> V_15 ;
F_17 ( V_6 ) ;
V_5 = ( V_27 >= 0 && ( T_5 ) V_27 > V_28 -> V_13 ) ? ( int ) V_28 -> V_13 : V_27 ;
if ( ( V_26 != NULL ) && ( V_5 > 0 ) ) {
memcpy ( V_26 , V_28 -> V_12 , V_5 ) ;
V_28 -> V_13 -= V_5 ;
V_28 -> V_12 += V_5 ;
} else if ( V_28 -> V_13 == 0 ) {
V_5 = V_6 -> V_18 ;
if ( V_5 != 0 )
F_18 ( V_6 ) ;
}
return ( V_5 ) ;
}
static int F_19 ( T_2 * V_6 , const char * V_29 , int V_30 )
{
int V_5 = - 1 ;
int V_31 ;
T_4 * V_25 = ( T_4 * ) V_6 -> V_11 ;
if ( V_29 == NULL ) {
F_4 ( V_32 , V_10 ) ;
goto V_33;
}
if ( V_6 -> V_16 & V_17 ) {
F_4 ( V_32 , V_34 ) ;
goto V_33;
}
F_17 ( V_6 ) ;
V_31 = V_25 -> V_15 -> V_13 ;
F_15 ( V_6 ) ;
if ( F_20 ( V_25 -> V_3 , V_31 + V_30 ) == 0 )
goto V_33;
memcpy ( V_25 -> V_3 -> V_12 + V_31 , V_29 , V_30 ) ;
* V_25 -> V_15 = * V_25 -> V_3 ;
V_5 = V_30 ;
V_33:
return ( V_5 ) ;
}
static long F_21 ( T_2 * V_6 , int V_35 , long V_18 , void * V_11 )
{
long V_5 = 1 ;
char * * V_36 ;
T_4 * V_25 = ( T_4 * ) V_6 -> V_11 ;
T_3 * V_28 ;
switch ( V_35 ) {
case V_37 :
V_28 = V_25 -> V_3 ;
if ( V_28 -> V_12 != NULL ) {
if ( ( V_6 -> V_16 & V_17 ) || ( V_6 -> V_16 & V_38 ) ) {
V_28 -> V_13 = V_28 -> V_14 ;
} else {
memset ( V_28 -> V_12 , 0 , V_28 -> V_14 ) ;
V_28 -> V_13 = 0 ;
}
* V_25 -> V_15 = * V_25 -> V_3 ;
}
break;
case V_39 :
V_28 = V_25 -> V_15 ;
V_5 = ( long ) ( V_28 -> V_13 == 0 ) ;
break;
case V_40 :
V_6 -> V_18 = ( int ) V_18 ;
break;
case V_41 :
V_28 = V_25 -> V_15 ;
V_5 = ( long ) V_28 -> V_13 ;
if ( V_11 != NULL ) {
V_36 = ( char * * ) V_11 ;
* V_36 = ( char * ) & ( V_28 -> V_12 [ 0 ] ) ;
}
break;
case V_42 :
F_14 ( V_6 , 0 ) ;
V_6 -> V_20 = ( int ) V_18 ;
V_25 -> V_3 = V_11 ;
* V_25 -> V_15 = * V_25 -> V_3 ;
V_6 -> V_11 = V_25 ;
break;
case V_43 :
if ( V_11 != NULL ) {
F_15 ( V_6 ) ;
V_28 = V_25 -> V_15 ;
V_36 = ( char * * ) V_11 ;
* V_36 = ( char * ) V_28 ;
}
break;
case V_44 :
V_5 = ( long ) V_6 -> V_20 ;
break;
case V_45 :
V_6 -> V_20 = ( int ) V_18 ;
break;
case V_46 :
V_5 = 0L ;
break;
case V_47 :
V_28 = V_25 -> V_15 ;
V_5 = ( long ) V_28 -> V_13 ;
break;
case V_48 :
case V_49 :
V_5 = 1 ;
break;
case V_50 :
case V_51 :
default:
V_5 = 0 ;
break;
}
return ( V_5 ) ;
}
static int F_22 ( T_2 * V_52 , char * V_3 , int V_53 )
{
int V_54 , V_55 ;
int V_5 = - 1 ;
char * V_56 ;
T_4 * V_25 = ( T_4 * ) V_52 -> V_11 ;
T_3 * V_28 = V_25 -> V_15 ;
F_17 ( V_52 ) ;
V_55 = V_28 -> V_13 ;
if ( ( V_53 - 1 ) < V_55 )
V_55 = V_53 - 1 ;
if ( V_55 <= 0 ) {
* V_3 = '\0' ;
return 0 ;
}
V_56 = V_28 -> V_12 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
if ( V_56 [ V_54 ] == '\n' ) {
V_54 ++ ;
break;
}
}
V_54 = F_16 ( V_52 , V_3 , V_54 ) ;
if ( V_54 > 0 )
V_3 [ V_54 ] = '\0' ;
V_5 = V_54 ;
return ( V_5 ) ;
}
static int F_23 ( T_2 * V_52 , const char * V_57 )
{
int V_58 , V_5 ;
V_58 = strlen ( V_57 ) ;
V_5 = F_19 ( V_52 , V_57 , V_58 ) ;
return ( V_5 ) ;
}
