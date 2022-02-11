const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_3 ( sizeof( * V_3 ) ) ;
if ( V_3 == NULL )
return 0 ;
V_3 -> V_4 = F_4 () ;
if ( V_3 -> V_4 == NULL ) {
F_5 ( V_3 ) ;
return 0 ;
}
V_3 -> V_5 = 1 ;
V_3 -> V_6 = 1 ;
V_3 -> V_7 = V_3 -> V_8 = & ( V_3 -> V_9 [ V_10 ] ) ;
F_6 ( V_2 , V_3 ) ;
F_7 ( V_2 , 1 ) ;
return 1 ;
}
static int F_8 ( T_2 * V_11 )
{
T_3 * V_12 ;
if ( V_11 == NULL )
return 0 ;
V_12 = F_9 ( V_11 ) ;
if ( V_12 == NULL )
return 0 ;
F_10 ( V_12 -> V_4 ) ;
F_11 ( V_12 , sizeof( T_3 ) ) ;
F_6 ( V_11 , NULL ) ;
F_7 ( V_11 , 0 ) ;
return 1 ;
}
static int F_12 ( T_2 * V_12 , char * V_13 , int V_14 )
{
int V_15 = 0 , V_16 , V_17 ;
T_3 * V_3 ;
T_2 * V_18 ;
if ( V_13 == NULL )
return ( 0 ) ;
V_3 = F_9 ( V_12 ) ;
V_18 = F_13 ( V_12 ) ;
if ( ( V_3 == NULL ) || ( V_18 == NULL ) )
return 0 ;
if ( V_3 -> V_19 > 0 ) {
V_16 = V_3 -> V_19 - V_3 -> V_20 ;
if ( V_16 > V_14 )
V_16 = V_14 ;
memcpy ( V_13 , & ( V_3 -> V_9 [ V_3 -> V_20 ] ) , V_16 ) ;
V_15 = V_16 ;
V_13 += V_16 ;
V_14 -= V_16 ;
V_3 -> V_20 += V_16 ;
if ( V_3 -> V_19 == V_3 -> V_20 ) {
V_3 -> V_19 = 0 ;
V_3 -> V_20 = 0 ;
}
}
V_17 = F_14 ( V_3 -> V_4 ) ;
if ( V_17 == 1 )
V_17 = 0 ;
while ( V_14 > 0 ) {
if ( V_3 -> V_5 <= 0 )
break;
if ( V_3 -> V_8 == V_3 -> V_7 ) {
V_3 -> V_7 = V_3 -> V_8 = & ( V_3 -> V_9 [ V_10 ] ) ;
V_16 = F_15 ( V_18 , V_3 -> V_8 , V_21 ) ;
if ( V_16 > 0 )
V_3 -> V_7 += V_16 ;
} else {
V_16 = V_3 -> V_7 - V_3 -> V_8 ;
}
if ( V_16 <= 0 ) {
if ( ! F_16 ( V_18 ) ) {
V_3 -> V_5 = V_16 ;
V_16 = F_17 ( V_3 -> V_4 ,
V_3 -> V_9 , & ( V_3 -> V_19 ) ) ;
V_3 -> V_6 = V_16 ;
V_3 -> V_20 = 0 ;
} else {
V_15 = ( V_15 == 0 ) ? V_16 : V_15 ;
break;
}
} else {
if ( V_14 > V_22 ) {
int V_23 = V_14 - V_17 , V_19 ;
if ( ! F_18 ( V_3 -> V_4 ,
( unsigned char * ) V_13 , & V_19 ,
V_3 -> V_8 , V_16 > V_23 ? V_23 : V_16 ) ) {
F_19 ( V_12 ) ;
return 0 ;
}
V_15 += V_19 ;
V_13 += V_19 ;
V_14 -= V_19 ;
if ( ( V_16 -= V_23 ) <= 0 ) {
V_3 -> V_8 = V_3 -> V_7 ;
continue;
}
V_3 -> V_8 += V_23 ;
}
if ( V_16 > V_22 )
V_16 = V_22 ;
if ( ! F_18 ( V_3 -> V_4 ,
V_3 -> V_9 , & V_3 -> V_19 ,
V_3 -> V_8 , V_16 ) ) {
F_19 ( V_12 ) ;
V_3 -> V_6 = 0 ;
return 0 ;
}
V_3 -> V_8 += V_16 ;
V_3 -> V_5 = 1 ;
if ( V_3 -> V_19 == 0 )
continue;
}
if ( V_3 -> V_19 <= V_14 )
V_16 = V_3 -> V_19 ;
else
V_16 = V_14 ;
if ( V_16 <= 0 )
break;
memcpy ( V_13 , V_3 -> V_9 , V_16 ) ;
V_15 += V_16 ;
V_3 -> V_20 = V_16 ;
V_14 -= V_16 ;
V_13 += V_16 ;
}
F_19 ( V_12 ) ;
F_20 ( V_12 ) ;
return ( ( V_15 == 0 ) ? V_3 -> V_5 : V_15 ) ;
}
static int F_21 ( T_2 * V_12 , const char * V_24 , int V_25 )
{
int V_15 = 0 , V_26 , V_16 ;
T_3 * V_3 ;
T_2 * V_18 ;
V_3 = F_9 ( V_12 ) ;
V_18 = F_13 ( V_12 ) ;
if ( ( V_3 == NULL ) || ( V_18 == NULL ) )
return 0 ;
V_15 = V_25 ;
F_19 ( V_12 ) ;
V_26 = V_3 -> V_19 - V_3 -> V_20 ;
while ( V_26 > 0 ) {
V_16 = F_22 ( V_18 , & ( V_3 -> V_9 [ V_3 -> V_20 ] ) , V_26 ) ;
if ( V_16 <= 0 ) {
F_20 ( V_12 ) ;
return ( V_16 ) ;
}
V_3 -> V_20 += V_16 ;
V_26 -= V_16 ;
}
if ( ( V_24 == NULL ) || ( V_25 <= 0 ) )
return ( 0 ) ;
V_3 -> V_20 = 0 ;
while ( V_25 > 0 ) {
V_26 = ( V_25 > V_21 ) ? V_21 : V_25 ;
if ( ! F_18 ( V_3 -> V_4 ,
V_3 -> V_9 , & V_3 -> V_19 ,
( const unsigned char * ) V_24 , V_26 ) ) {
F_19 ( V_12 ) ;
V_3 -> V_6 = 0 ;
return 0 ;
}
V_25 -= V_26 ;
V_24 += V_26 ;
V_3 -> V_20 = 0 ;
V_26 = V_3 -> V_19 ;
while ( V_26 > 0 ) {
V_16 = F_22 ( V_18 , & ( V_3 -> V_9 [ V_3 -> V_20 ] ) , V_26 ) ;
if ( V_16 <= 0 ) {
F_20 ( V_12 ) ;
return ( V_15 == V_25 ) ? V_16 : V_15 - V_25 ;
}
V_26 -= V_16 ;
V_3 -> V_20 += V_16 ;
}
V_3 -> V_19 = 0 ;
V_3 -> V_20 = 0 ;
}
F_20 ( V_12 ) ;
return ( V_15 ) ;
}
static long F_23 ( T_2 * V_12 , int V_27 , long V_28 , void * V_29 )
{
T_2 * V_30 ;
T_3 * V_3 , * V_31 ;
long V_15 = 1 ;
int V_16 ;
T_4 * * V_32 ;
T_2 * V_18 ;
V_3 = F_9 ( V_12 ) ;
V_18 = F_13 ( V_12 ) ;
if ( V_3 == NULL )
return 0 ;
switch ( V_27 ) {
case V_33 :
V_3 -> V_6 = 1 ;
V_3 -> V_34 = 0 ;
if ( ! F_24 ( V_3 -> V_4 , NULL , NULL , NULL , NULL ,
F_25 ( V_3 -> V_4 ) ) )
return 0 ;
V_15 = F_26 ( V_18 , V_27 , V_28 , V_29 ) ;
break;
case V_35 :
if ( V_3 -> V_5 <= 0 )
V_15 = 1 ;
else
V_15 = F_26 ( V_18 , V_27 , V_28 , V_29 ) ;
break;
case V_36 :
V_15 = V_3 -> V_19 - V_3 -> V_20 ;
if ( V_15 <= 0 )
V_15 = F_26 ( V_18 , V_27 , V_28 , V_29 ) ;
break;
case V_37 :
V_15 = V_3 -> V_19 - V_3 -> V_20 ;
if ( V_15 <= 0 )
V_15 = F_26 ( V_18 , V_27 , V_28 , V_29 ) ;
break;
case V_38 :
V_39:
while ( V_3 -> V_19 != V_3 -> V_20 ) {
V_16 = F_21 ( V_12 , NULL , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
}
if ( ! V_3 -> V_34 ) {
V_3 -> V_34 = 1 ;
V_3 -> V_20 = 0 ;
V_15 = F_17 ( V_3 -> V_4 ,
( unsigned char * ) V_3 -> V_9 ,
& ( V_3 -> V_19 ) ) ;
V_3 -> V_6 = ( int ) V_15 ;
if ( V_15 <= 0 )
break;
goto V_39;
}
V_15 = F_26 ( V_18 , V_27 , V_28 , V_29 ) ;
break;
case V_40 :
V_15 = ( long ) V_3 -> V_6 ;
break;
case V_41 :
F_19 ( V_12 ) ;
V_15 = F_26 ( V_18 , V_27 , V_28 , V_29 ) ;
F_20 ( V_12 ) ;
break;
case V_42 :
V_32 = ( T_4 * * ) V_29 ;
* V_32 = V_3 -> V_4 ;
F_7 ( V_12 , 1 ) ;
break;
case V_43 :
V_30 = ( T_2 * ) V_29 ;
V_31 = F_9 ( V_30 ) ;
V_31 -> V_4 = F_4 () ;
if ( V_31 -> V_4 == NULL )
return 0 ;
V_15 = F_27 ( V_31 -> V_4 , V_3 -> V_4 ) ;
if ( V_15 )
F_7 ( V_30 , 1 ) ;
break;
default:
V_15 = F_26 ( V_18 , V_27 , V_28 , V_29 ) ;
break;
}
return ( V_15 ) ;
}
static long F_28 ( T_2 * V_12 , int V_27 , T_5 * V_44 )
{
long V_15 = 1 ;
T_2 * V_18 = F_13 ( V_12 ) ;
if ( V_18 == NULL )
return ( 0 ) ;
switch ( V_27 ) {
default:
V_15 = F_29 ( V_18 , V_27 , V_44 ) ;
break;
}
return ( V_15 ) ;
}
int F_30 ( T_2 * V_12 , const T_6 * V_45 , const unsigned char * V_46 ,
const unsigned char * V_16 , int V_47 )
{
T_3 * V_3 ;
long (* F_31) ( struct V_48 * , int , const char * , int , long , long );
V_3 = F_9 ( V_12 ) ;
if ( V_3 == NULL )
return 0 ;
F_31 = F_32 ( V_12 ) ;
if ( ( F_31 != NULL ) &&
( F_31 ( V_12 , V_49 , ( const char * ) V_45 , V_50 , V_47 ,
0L ) <= 0 ) )
return 0 ;
F_7 ( V_12 , 1 ) ;
if ( ! F_24 ( V_3 -> V_4 , V_45 , NULL , V_46 , V_16 , V_47 ) )
return 0 ;
if ( F_31 != NULL )
return F_31 ( V_12 , V_49 , ( const char * ) V_45 , V_50 , V_47 , 1L ) ;
return 1 ;
}
