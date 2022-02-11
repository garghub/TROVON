const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 = F_3 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
return ( 0 ) ;
V_3 -> V_4 = V_5 ;
V_3 -> V_6 = F_4 ( V_5 ) ;
if ( V_3 -> V_6 == NULL ) {
F_5 ( V_3 ) ;
return ( 0 ) ;
}
V_3 -> V_7 = V_5 ;
V_3 -> V_8 = F_4 ( V_5 ) ;
if ( V_3 -> V_8 == NULL ) {
F_5 ( V_3 -> V_6 ) ;
F_5 ( V_3 ) ;
return ( 0 ) ;
}
V_2 -> V_9 = 1 ;
V_2 -> V_10 = ( char * ) V_3 ;
V_2 -> V_11 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_12 )
{
T_3 * V_13 ;
if ( V_12 == NULL )
return ( 0 ) ;
V_13 = ( T_3 * ) V_12 -> V_10 ;
F_5 ( V_13 -> V_6 ) ;
F_5 ( V_13 -> V_8 ) ;
F_5 ( V_12 -> V_10 ) ;
V_12 -> V_10 = NULL ;
V_12 -> V_9 = 0 ;
V_12 -> V_11 = 0 ;
return ( 1 ) ;
}
static int F_7 ( T_2 * V_13 , char * V_14 , int V_15 )
{
int V_16 , V_17 = 0 ;
T_3 * V_3 ;
if ( V_14 == NULL )
return ( 0 ) ;
V_3 = ( T_3 * ) V_13 -> V_10 ;
if ( ( V_3 == NULL ) || ( V_13 -> V_18 == NULL ) )
return ( 0 ) ;
V_17 = 0 ;
F_8 ( V_13 ) ;
V_19:
V_16 = V_3 -> V_20 ;
if ( V_16 != 0 ) {
if ( V_16 > V_15 )
V_16 = V_15 ;
memcpy ( V_14 , & ( V_3 -> V_6 [ V_3 -> V_21 ] ) , V_16 ) ;
V_3 -> V_21 += V_16 ;
V_3 -> V_20 -= V_16 ;
V_17 += V_16 ;
if ( V_15 == V_16 )
return ( V_17 ) ;
V_15 -= V_16 ;
V_14 += V_16 ;
}
if ( V_15 > V_3 -> V_4 ) {
for (; ; ) {
V_16 = F_9 ( V_13 -> V_18 , V_14 , V_15 ) ;
if ( V_16 <= 0 ) {
F_10 ( V_13 ) ;
if ( V_16 < 0 )
return ( ( V_17 > 0 ) ? V_17 : V_16 ) ;
if ( V_16 == 0 )
return ( V_17 ) ;
}
V_17 += V_16 ;
if ( V_15 == V_16 )
return ( V_17 ) ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
}
V_16 = F_9 ( V_13 -> V_18 , V_3 -> V_6 , V_3 -> V_4 ) ;
if ( V_16 <= 0 ) {
F_10 ( V_13 ) ;
if ( V_16 < 0 )
return ( ( V_17 > 0 ) ? V_17 : V_16 ) ;
if ( V_16 == 0 )
return ( V_17 ) ;
}
V_3 -> V_21 = 0 ;
V_3 -> V_20 = V_16 ;
goto V_19;
}
static int F_11 ( T_2 * V_13 , const char * V_22 , int V_23 )
{
int V_16 , V_17 = 0 ;
T_3 * V_3 ;
if ( ( V_22 == NULL ) || ( V_23 <= 0 ) )
return ( 0 ) ;
V_3 = ( T_3 * ) V_13 -> V_10 ;
if ( ( V_3 == NULL ) || ( V_13 -> V_18 == NULL ) )
return ( 0 ) ;
F_8 ( V_13 ) ;
V_19:
V_16 = V_3 -> V_7 - ( V_3 -> V_24 + V_3 -> V_25 ) ;
if ( V_16 >= V_23 ) {
memcpy ( & ( V_3 -> V_8 [ V_3 -> V_25 + V_3 -> V_24 ] ) , V_22 , V_23 ) ;
V_3 -> V_24 += V_23 ;
return ( V_17 + V_23 ) ;
}
if ( V_3 -> V_24 != 0 ) {
if ( V_16 > 0 ) {
memcpy ( & ( V_3 -> V_8 [ V_3 -> V_25 + V_3 -> V_24 ] ) , V_22 , V_16 ) ;
V_22 += V_16 ;
V_23 -= V_16 ;
V_17 += V_16 ;
V_3 -> V_24 += V_16 ;
}
for (; ; ) {
V_16 = F_12 ( V_13 -> V_18 , & ( V_3 -> V_8 [ V_3 -> V_25 ] ) ,
V_3 -> V_24 ) ;
if ( V_16 <= 0 ) {
F_10 ( V_13 ) ;
if ( V_16 < 0 )
return ( ( V_17 > 0 ) ? V_17 : V_16 ) ;
if ( V_16 == 0 )
return ( V_17 ) ;
}
V_3 -> V_25 += V_16 ;
V_3 -> V_24 -= V_16 ;
if ( V_3 -> V_24 == 0 )
break;
}
}
V_3 -> V_25 = 0 ;
while ( V_23 >= V_3 -> V_7 ) {
V_16 = F_12 ( V_13 -> V_18 , V_22 , V_23 ) ;
if ( V_16 <= 0 ) {
F_10 ( V_13 ) ;
if ( V_16 < 0 )
return ( ( V_17 > 0 ) ? V_17 : V_16 ) ;
if ( V_16 == 0 )
return ( V_17 ) ;
}
V_17 += V_16 ;
V_22 += V_16 ;
V_23 -= V_16 ;
if ( V_23 == 0 )
return ( V_17 ) ;
}
goto V_19;
}
static long F_13 ( T_2 * V_13 , int V_26 , long V_17 , void * V_10 )
{
T_2 * V_27 ;
T_3 * V_3 ;
long V_28 = 1 ;
char * V_29 , * V_30 ;
int V_31 , V_16 , * V_32 ;
int V_33 , V_34 ;
V_3 = ( T_3 * ) V_13 -> V_10 ;
switch ( V_26 ) {
case V_35 :
V_3 -> V_21 = 0 ;
V_3 -> V_20 = 0 ;
V_3 -> V_25 = 0 ;
V_3 -> V_24 = 0 ;
if ( V_13 -> V_18 == NULL )
return ( 0 ) ;
V_28 = F_14 ( V_13 -> V_18 , V_26 , V_17 , V_10 ) ;
break;
case V_36 :
V_28 = ( long ) V_3 -> V_24 ;
break;
case V_37 :
V_28 = 0 ;
V_29 = V_3 -> V_6 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_20 ; V_16 ++ ) {
if ( V_29 [ V_3 -> V_21 + V_16 ] == '\n' )
V_28 ++ ;
}
break;
case V_38 :
V_28 = ( long ) V_3 -> V_24 ;
if ( V_28 == 0 ) {
if ( V_13 -> V_18 == NULL )
return ( 0 ) ;
V_28 = F_14 ( V_13 -> V_18 , V_26 , V_17 , V_10 ) ;
}
break;
case V_39 :
V_28 = ( long ) V_3 -> V_20 ;
if ( V_28 == 0 ) {
if ( V_13 -> V_18 == NULL )
return ( 0 ) ;
V_28 = F_14 ( V_13 -> V_18 , V_26 , V_17 , V_10 ) ;
}
break;
case V_40 :
if ( V_17 > V_3 -> V_4 ) {
V_29 = F_4 ( ( int ) V_17 ) ;
if ( V_29 == NULL )
goto V_41;
F_5 ( V_3 -> V_6 ) ;
V_3 -> V_6 = V_29 ;
}
V_3 -> V_21 = 0 ;
V_3 -> V_20 = ( int ) V_17 ;
memcpy ( V_3 -> V_6 , V_10 , ( int ) V_17 ) ;
V_28 = 1 ;
break;
case V_42 :
if ( V_10 != NULL ) {
V_32 = ( int * ) V_10 ;
if ( * V_32 == 0 ) {
V_33 = ( int ) V_17 ;
V_34 = V_3 -> V_7 ;
} else {
V_33 = V_3 -> V_4 ;
V_34 = ( int ) V_17 ;
}
} else {
V_33 = ( int ) V_17 ;
V_34 = ( int ) V_17 ;
}
V_29 = V_3 -> V_6 ;
V_30 = V_3 -> V_8 ;
if ( ( V_33 > V_5 ) && ( V_33 != V_3 -> V_4 ) ) {
V_29 = F_4 ( ( int ) V_17 ) ;
if ( V_29 == NULL )
goto V_41;
}
if ( ( V_34 > V_5 ) && ( V_34 != V_3 -> V_7 ) ) {
V_30 = F_4 ( ( int ) V_17 ) ;
if ( V_30 == NULL ) {
if ( V_29 != V_3 -> V_6 )
F_5 ( V_29 ) ;
goto V_41;
}
}
if ( V_3 -> V_6 != V_29 ) {
F_5 ( V_3 -> V_6 ) ;
V_3 -> V_6 = V_29 ;
V_3 -> V_21 = 0 ;
V_3 -> V_20 = 0 ;
V_3 -> V_4 = V_33 ;
}
if ( V_3 -> V_8 != V_30 ) {
F_5 ( V_3 -> V_8 ) ;
V_3 -> V_8 = V_30 ;
V_3 -> V_25 = 0 ;
V_3 -> V_24 = 0 ;
V_3 -> V_7 = V_34 ;
}
break;
case V_43 :
if ( V_13 -> V_18 == NULL )
return ( 0 ) ;
F_8 ( V_13 ) ;
V_28 = F_14 ( V_13 -> V_18 , V_26 , V_17 , V_10 ) ;
F_10 ( V_13 ) ;
break;
case V_44 :
if ( V_13 -> V_18 == NULL )
return ( 0 ) ;
if ( V_3 -> V_24 <= 0 ) {
V_28 = F_14 ( V_13 -> V_18 , V_26 , V_17 , V_10 ) ;
break;
}
for (; ; ) {
F_8 ( V_13 ) ;
if ( V_3 -> V_24 > 0 ) {
V_31 = F_12 ( V_13 -> V_18 ,
& ( V_3 -> V_8 [ V_3 -> V_25 ] ) , V_3 -> V_24 ) ;
F_10 ( V_13 ) ;
if ( V_31 <= 0 )
return ( ( long ) V_31 ) ;
V_3 -> V_25 += V_31 ;
V_3 -> V_24 -= V_31 ;
} else {
V_3 -> V_24 = 0 ;
V_3 -> V_25 = 0 ;
break;
}
}
V_28 = F_14 ( V_13 -> V_18 , V_26 , V_17 , V_10 ) ;
break;
case V_45 :
V_27 = ( T_2 * ) V_10 ;
if ( ! F_15 ( V_27 , V_3 -> V_4 ) ||
! F_16 ( V_27 , V_3 -> V_7 ) )
V_28 = 0 ;
break;
default:
if ( V_13 -> V_18 == NULL )
return ( 0 ) ;
V_28 = F_14 ( V_13 -> V_18 , V_26 , V_17 , V_10 ) ;
break;
}
return ( V_28 ) ;
V_41:
F_17 ( V_46 , V_47 ) ;
return ( 0 ) ;
}
static long F_18 ( T_2 * V_13 , int V_26 , T_4 * V_48 )
{
long V_28 = 1 ;
if ( V_13 -> V_18 == NULL )
return ( 0 ) ;
switch ( V_26 ) {
default:
V_28 = F_19 ( V_13 -> V_18 , V_26 , V_48 ) ;
break;
}
return ( V_28 ) ;
}
static int F_20 ( T_2 * V_13 , char * V_49 , int V_50 )
{
T_3 * V_3 ;
int V_17 = 0 , V_16 , V_51 ;
char * V_52 ;
V_3 = ( T_3 * ) V_13 -> V_10 ;
V_50 -- ;
F_8 ( V_13 ) ;
for (; ; ) {
if ( V_3 -> V_20 > 0 ) {
V_52 = & ( V_3 -> V_6 [ V_3 -> V_21 ] ) ;
V_51 = 0 ;
for ( V_16 = 0 ; ( V_16 < V_3 -> V_20 ) && ( V_16 < V_50 ) ; V_16 ++ ) {
* ( V_49 ++ ) = V_52 [ V_16 ] ;
if ( V_52 [ V_16 ] == '\n' ) {
V_51 = 1 ;
V_16 ++ ;
break;
}
}
V_17 += V_16 ;
V_50 -= V_16 ;
V_3 -> V_20 -= V_16 ;
V_3 -> V_21 += V_16 ;
if ( V_51 || V_50 == 0 ) {
* V_49 = '\0' ;
return ( V_17 ) ;
}
} else {
V_16 = F_9 ( V_13 -> V_18 , V_3 -> V_6 , V_3 -> V_4 ) ;
if ( V_16 <= 0 ) {
F_10 ( V_13 ) ;
* V_49 = '\0' ;
if ( V_16 < 0 )
return ( ( V_17 > 0 ) ? V_17 : V_16 ) ;
if ( V_16 == 0 )
return ( V_17 ) ;
}
V_3 -> V_20 = V_16 ;
V_3 -> V_21 = 0 ;
}
}
}
static int F_21 ( T_2 * V_13 , const char * V_53 )
{
return ( F_11 ( V_13 , V_53 , strlen ( V_53 ) ) ) ;
}
