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
V_3 -> V_4 = 1 ;
V_3 -> V_5 = 1 ;
V_3 -> V_6 = F_4 () ;
if ( V_3 -> V_6 == NULL ) {
F_5 ( V_3 ) ;
return 0 ;
}
F_6 ( V_2 , 0 ) ;
F_7 ( V_2 , V_3 ) ;
return 1 ;
}
static int F_8 ( T_2 * V_7 )
{
T_3 * V_3 ;
if ( V_7 == NULL )
return 0 ;
V_3 = F_9 ( V_7 ) ;
F_10 ( V_3 -> V_6 ) ;
F_11 ( V_3 , sizeof( T_3 ) ) ;
F_7 ( V_7 , NULL ) ;
F_6 ( V_7 , 0 ) ;
return 1 ;
}
static int F_12 ( T_2 * V_8 , char * V_9 , int V_10 )
{
int V_11 = 0 , V_12 , V_13 ;
T_3 * V_3 ;
T_2 * V_14 ;
if ( V_9 == NULL )
return 0 ;
V_3 = F_9 ( V_8 ) ;
V_14 = F_13 ( V_8 ) ;
if ( ( V_3 == NULL ) || ( V_14 == NULL ) || ( F_14 ( V_8 ) == 0 ) )
return 0 ;
while ( V_10 > 0 ) {
if ( V_3 -> V_15 ) {
V_12 = V_3 -> V_16 - V_3 -> V_17 ;
if ( V_12 > V_10 )
V_12 = V_10 ;
memcpy ( V_9 , & ( V_3 -> V_18 [ V_3 -> V_17 ] ) , V_12 ) ;
V_11 += V_12 ;
V_9 += V_12 ;
V_10 -= V_12 ;
V_3 -> V_17 += V_12 ;
if ( V_3 -> V_16 == V_3 -> V_17 ) {
V_3 -> V_17 = 0 ;
if ( V_3 -> V_19 - V_3 -> V_20 > 0 ) {
V_3 -> V_16 = V_3 -> V_19 - V_3 -> V_20 ;
memmove ( V_3 -> V_18 , & ( V_3 -> V_18 [ V_3 -> V_20 ] ) ,
V_3 -> V_16 ) ;
} else {
V_3 -> V_16 = 0 ;
}
V_3 -> V_15 = 0 ;
}
}
if ( V_10 == 0 )
break;
V_13 = V_21 - V_3 -> V_16 ;
V_12 = F_15 ( V_14 , & ( V_3 -> V_18 [ V_3 -> V_16 ] ) , V_13 ) ;
if ( V_12 <= 0 )
break;
V_3 -> V_16 += V_12 ;
if ( V_3 -> V_5 == 1 ) {
if ( ! F_16 ( V_8 ) ) {
F_17 ( V_8 ) ;
return 0 ;
}
}
if ( V_3 -> V_5 == 0 ) {
if ( ! F_18 ( V_8 ) ) {
F_17 ( V_8 ) ;
return 0 ;
}
}
if ( V_3 -> V_4 <= 0 )
break;
}
F_17 ( V_8 ) ;
F_19 ( V_8 ) ;
return V_11 ;
}
static int F_20 ( T_2 * V_8 , const char * V_22 , int V_23 )
{
int V_11 = 0 , V_13 , V_12 ;
T_3 * V_3 ;
T_2 * V_14 ;
if ( V_23 <= 0 )
return V_23 ;
V_3 = F_9 ( V_8 ) ;
V_14 = F_13 ( V_8 ) ;
V_11 = V_23 ;
if ( ( V_3 == NULL ) || ( V_14 == NULL ) || ( F_14 ( V_8 ) == 0 ) )
return ( 0 ) ;
if ( V_3 -> V_5 && ! F_21 ( V_8 ) )
return 0 ;
do {
F_17 ( V_8 ) ;
V_13 = V_3 -> V_16 - V_3 -> V_17 ;
while ( V_3 -> V_15 && V_13 > 0 ) {
V_12 = F_22 ( V_14 , & ( V_3 -> V_18 [ V_3 -> V_17 ] ) , V_13 ) ;
if ( V_12 <= 0 ) {
F_19 ( V_8 ) ;
if ( ! F_23 ( V_8 ) )
V_3 -> V_4 = 0 ;
return ( V_12 ) ;
}
V_3 -> V_17 += V_12 ;
V_13 -= V_12 ;
}
V_3 -> V_15 = 0 ;
if ( V_3 -> V_16 == V_3 -> V_17 ) {
V_3 -> V_16 = V_24 ;
V_3 -> V_17 = 0 ;
}
if ( ( V_22 == NULL ) || ( V_23 <= 0 ) )
return ( 0 ) ;
V_13 = ( V_23 + V_3 -> V_16 > V_25 + V_24 ) ?
( int ) ( V_25 + V_24 - V_3 -> V_16 ) : V_23 ;
memcpy ( & V_3 -> V_18 [ V_3 -> V_16 ] , V_22 , V_13 ) ;
V_3 -> V_16 += V_13 ;
V_23 -= V_13 ;
V_22 += V_13 ;
if ( V_3 -> V_16 >= V_25 + V_24 ) {
if ( ! F_24 ( V_8 ) ) {
F_17 ( V_8 ) ;
return 0 ;
}
}
} while ( V_23 > 0 );
F_17 ( V_8 ) ;
F_19 ( V_8 ) ;
return ( V_11 ) ;
}
static long F_25 ( T_2 * V_8 , int V_26 , long V_27 , void * V_28 )
{
T_3 * V_3 ;
T_4 * V_6 ;
const T_4 * * V_29 ;
long V_11 = 1 ;
int V_12 ;
T_2 * V_14 ;
V_3 = F_9 ( V_8 ) ;
V_14 = F_13 ( V_8 ) ;
switch ( V_26 ) {
case V_30 :
V_3 -> V_16 = 0 ;
V_3 -> V_17 = 0 ;
V_3 -> V_19 = 0 ;
V_3 -> V_20 = 0 ;
V_3 -> V_4 = 1 ;
V_3 -> V_31 = 0 ;
V_3 -> V_15 = 0 ;
V_3 -> V_5 = 1 ;
V_11 = F_26 ( V_14 , V_26 , V_27 , V_28 ) ;
break;
case V_32 :
if ( V_3 -> V_4 <= 0 )
V_11 = 1 ;
else
V_11 = F_26 ( V_14 , V_26 , V_27 , V_28 ) ;
break;
case V_33 :
case V_34 :
V_11 = V_3 -> V_15 ? V_3 -> V_16 - V_3 -> V_17 : 0 ;
if ( V_11 <= 0 )
V_11 = F_26 ( V_14 , V_26 , V_27 , V_28 ) ;
break;
case V_35 :
if ( V_3 -> V_15 == 0 )
if ( ! F_24 ( V_8 ) )
return 0 ;
while ( V_3 -> V_15 ) {
V_12 = F_20 ( V_8 , NULL , 0 ) ;
if ( V_12 < 0 ) {
V_11 = V_12 ;
break;
}
}
V_3 -> V_31 = 1 ;
V_3 -> V_17 = V_3 -> V_16 = 0 ;
V_3 -> V_4 = ( int ) V_11 ;
V_11 = F_26 ( V_14 , V_26 , V_27 , V_28 ) ;
break;
case V_36 :
F_17 ( V_8 ) ;
V_11 = F_26 ( V_14 , V_26 , V_27 , V_28 ) ;
F_19 ( V_8 ) ;
break;
case V_37 :
V_11 = ( long ) V_3 -> V_4 ;
break;
case V_38 :
V_6 = V_28 ;
if ( ! F_27 ( V_3 -> V_6 , V_6 , NULL ) )
return 0 ;
F_6 ( V_8 , 1 ) ;
break;
case V_39 :
if ( F_14 ( V_8 ) ) {
V_29 = V_28 ;
* V_29 = F_28 ( V_3 -> V_6 ) ;
} else
V_11 = 0 ;
break;
default:
V_11 = F_26 ( V_14 , V_26 , V_27 , V_28 ) ;
break;
}
return V_11 ;
}
static long F_29 ( T_2 * V_8 , int V_26 , T_5 * V_40 )
{
long V_11 = 1 ;
T_2 * V_14 ;
V_14 = F_13 ( V_8 ) ;
if ( V_14 == NULL )
return 0 ;
switch ( V_26 ) {
default:
V_11 = F_30 ( V_14 , V_26 , V_40 ) ;
break;
}
return V_11 ;
}
static void F_31 ( void * V_41 , T_6 V_42 )
{
const union {
long V_43 ;
char V_44 ;
} V_45 = {
1
} ;
if ( V_45 . V_44 ) {
T_6 V_12 ;
unsigned char * V_46 = V_41 , V_47 ;
for ( V_12 = 0 ; V_12 < V_42 ; V_12 += 4 ) {
V_47 = V_46 [ 0 ] , V_46 [ 0 ] = V_46 [ 3 ] , V_46 [ 3 ] = V_47 ;
V_47 = V_46 [ 1 ] , V_46 [ 1 ] = V_46 [ 2 ] , V_46 [ 2 ] = V_47 ;
}
}
}
static int F_21 ( T_2 * V_8 )
{
T_3 * V_3 ;
T_7 * V_6 ;
const T_4 * V_48 ;
int V_49 ;
void * V_50 ;
V_3 = F_9 ( V_8 ) ;
V_6 = V_3 -> V_6 ;
V_48 = F_28 ( V_6 ) ;
V_49 = F_32 ( V_48 ) ;
V_50 = F_33 ( V_6 ) ;
if ( V_3 -> V_16 + 2 * V_49 > V_25 )
return 1 ;
if ( ! F_27 ( V_6 , V_48 , NULL ) )
goto V_51;
if ( F_34 ( V_50 , V_49 ) <= 0 )
goto V_51;
memcpy ( & ( V_3 -> V_18 [ V_3 -> V_16 ] ) , V_50 , V_49 ) ;
F_31 ( & ( V_3 -> V_18 [ V_3 -> V_16 ] ) , V_49 ) ;
V_3 -> V_16 += V_49 ;
if ( ! F_35 ( V_6 , V_52 , strlen ( V_52 ) ) )
goto V_51;
if ( ! F_36 ( V_6 , & ( V_3 -> V_18 [ V_3 -> V_16 ] ) , NULL ) )
goto V_51;
V_3 -> V_16 += V_49 ;
V_3 -> V_15 = 1 ;
V_3 -> V_5 = 0 ;
return 1 ;
V_51:
F_17 ( V_8 ) ;
return 0 ;
}
static int F_16 ( T_2 * V_8 )
{
T_3 * V_3 ;
T_7 * V_6 ;
unsigned char V_53 [ V_54 ] ;
int V_11 = 0 ;
const T_4 * V_48 ;
int V_49 ;
void * V_50 ;
V_3 = F_9 ( V_8 ) ;
V_6 = V_3 -> V_6 ;
V_48 = F_28 ( V_6 ) ;
V_49 = F_32 ( V_48 ) ;
V_50 = F_33 ( V_6 ) ;
if ( ( int ) ( V_3 -> V_16 - V_3 -> V_17 ) < 2 * V_49 )
return 1 ;
if ( ! F_27 ( V_6 , V_48 , NULL ) )
goto V_51;
memcpy ( V_50 , & ( V_3 -> V_18 [ V_3 -> V_17 ] ) , V_49 ) ;
F_31 ( V_50 , V_49 ) ;
V_3 -> V_17 += V_49 ;
if ( ! F_35 ( V_6 , V_52 , strlen ( V_52 ) ) )
goto V_51;
if ( ! F_36 ( V_6 , V_53 , NULL ) )
goto V_51;
V_11 = memcmp ( & ( V_3 -> V_18 [ V_3 -> V_17 ] ) , V_53 , V_49 ) == 0 ;
V_3 -> V_17 += V_49 ;
if ( V_11 == 1 ) {
V_3 -> V_5 = 0 ;
if ( V_3 -> V_16 != V_3 -> V_17 ) {
memmove ( V_3 -> V_18 , & ( V_3 -> V_18 [ V_3 -> V_17 ] ) ,
V_3 -> V_16 - V_3 -> V_17 ) ;
}
V_3 -> V_16 -= V_3 -> V_17 ;
V_3 -> V_17 = 0 ;
} else {
V_3 -> V_4 = 0 ;
}
return 1 ;
V_51:
F_17 ( V_8 ) ;
return 0 ;
}
static int F_24 ( T_2 * V_8 )
{
T_3 * V_3 ;
T_7 * V_6 ;
unsigned long V_55 ;
const T_4 * V_48 ;
int V_49 ;
V_3 = F_9 ( V_8 ) ;
V_6 = V_3 -> V_6 ;
V_48 = F_28 ( V_6 ) ;
V_49 = F_32 ( V_48 ) ;
V_55 = V_3 -> V_16 - V_24 ;
V_3 -> V_18 [ 0 ] = ( unsigned char ) ( V_55 >> 24 ) ;
V_3 -> V_18 [ 1 ] = ( unsigned char ) ( V_55 >> 16 ) ;
V_3 -> V_18 [ 2 ] = ( unsigned char ) ( V_55 >> 8 ) ;
V_3 -> V_18 [ 3 ] = ( unsigned char ) ( V_55 ) ;
if ( ! F_35 ( V_6 ,
( unsigned char * ) & ( V_3 -> V_18 [ V_24 ] ) , V_55 ) )
goto V_51;
if ( ! F_36 ( V_6 , & ( V_3 -> V_18 [ V_3 -> V_16 ] ) , NULL ) )
goto V_51;
V_3 -> V_16 += V_49 ;
V_3 -> V_15 = 1 ;
return 1 ;
V_51:
F_17 ( V_8 ) ;
return 0 ;
}
static int F_18 ( T_2 * V_8 )
{
T_3 * V_3 ;
T_7 * V_6 ;
unsigned long V_55 = 0 ;
unsigned char V_53 [ V_54 ] ;
int V_49 ;
V_3 = F_9 ( V_8 ) ;
V_6 = V_3 -> V_6 ;
V_49 = F_32 ( F_28 ( V_6 ) ) ;
assert ( sizeof( V_55 ) >= V_24 ) ;
V_55 = V_3 -> V_18 [ 0 ] ;
V_55 <<= 8 ;
V_55 |= V_3 -> V_18 [ 1 ] ;
V_55 <<= 8 ;
V_55 |= V_3 -> V_18 [ 2 ] ;
V_55 <<= 8 ;
V_55 |= V_3 -> V_18 [ 3 ] ;
if ( V_3 -> V_16 < V_55 + V_24 + V_49 )
return 1 ;
if ( ! F_35 ( V_6 ,
( unsigned char * ) & ( V_3 -> V_18 [ V_24 ] ) , V_55 ) )
goto V_51;
if ( ! F_36 ( V_6 , V_53 , NULL ) )
goto V_51;
if ( memcmp ( & ( V_3 -> V_18 [ V_55 + V_24 ] ) , V_53 , V_49 ) == 0 ) {
V_3 -> V_20 = V_55 + V_24 + V_49 ;
V_3 -> V_19 = V_3 -> V_16 ;
V_3 -> V_17 = V_24 ;
V_3 -> V_16 = V_55 + V_24 ;
V_3 -> V_15 = 1 ;
} else {
V_3 -> V_4 = 0 ;
}
return 1 ;
V_51:
F_17 ( V_8 ) ;
return 0 ;
}
