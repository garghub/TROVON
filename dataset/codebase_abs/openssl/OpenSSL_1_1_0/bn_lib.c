void F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
if ( V_1 >= 0 ) {
if ( V_1 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_1 = sizeof( int ) * 8 - 1 ;
V_5 = V_1 ;
V_6 = 1 << V_1 ;
}
if ( V_2 >= 0 ) {
if ( V_2 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_2 = sizeof( int ) * 8 - 1 ;
V_7 = V_2 ;
V_8 = 1 << V_2 ;
}
if ( V_3 >= 0 ) {
if ( V_3 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_3 = sizeof( int ) * 8 - 1 ;
V_9 = V_3 ;
V_10 = 1 << V_3 ;
}
if ( V_4 >= 0 ) {
if ( V_4 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_4 = sizeof( int ) * 8 - 1 ;
V_11 = V_4 ;
V_12 = 1 << V_4 ;
}
}
int F_2 ( int V_13 )
{
if ( V_13 == 0 )
return ( V_5 ) ;
else if ( V_13 == 1 )
return ( V_7 ) ;
else if ( V_13 == 2 )
return ( V_9 ) ;
else if ( V_13 == 3 )
return ( V_11 ) ;
else
return ( 0 ) ;
}
const T_1 * F_3 ( void )
{
static const T_2 V_14 = 1L ;
static const T_1 V_15 =
{ ( T_2 * ) & V_14 , 1 , 1 , 0 , V_16 } ;
return ( & V_15 ) ;
}
int F_4 ( T_2 V_17 )
{
static const unsigned char V_18 [ 256 ] = {
0 , 1 , 2 , 2 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 ,
5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 , 5 ,
6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 ,
6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 , 6 ,
7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 ,
7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 ,
7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 ,
7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 , 7 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 ,
} ;
#if F_5 ( V_19 )
if ( V_17 & 0xffffffff00000000L ) {
if ( V_17 & 0xffff000000000000L ) {
if ( V_17 & 0xff00000000000000L ) {
return ( V_18 [ ( int ) ( V_17 >> 56 ) ] + 56 ) ;
} else
return ( V_18 [ ( int ) ( V_17 >> 48 ) ] + 48 ) ;
} else {
if ( V_17 & 0x0000ff0000000000L ) {
return ( V_18 [ ( int ) ( V_17 >> 40 ) ] + 40 ) ;
} else
return ( V_18 [ ( int ) ( V_17 >> 32 ) ] + 32 ) ;
}
} else
#else
# ifdef F_6
if ( V_17 & 0xffffffff00000000LL ) {
if ( V_17 & 0xffff000000000000LL ) {
if ( V_17 & 0xff00000000000000LL ) {
return ( V_18 [ ( int ) ( V_17 >> 56 ) ] + 56 ) ;
} else
return ( V_18 [ ( int ) ( V_17 >> 48 ) ] + 48 ) ;
} else {
if ( V_17 & 0x0000ff0000000000LL ) {
return ( V_18 [ ( int ) ( V_17 >> 40 ) ] + 40 ) ;
} else
return ( V_18 [ ( int ) ( V_17 >> 32 ) ] + 32 ) ;
}
} else
# endif
#endif
{
#if F_5 ( V_20 ) || F_5 ( F_6 ) || F_5 ( V_19 )
if ( V_17 & 0xffff0000L ) {
if ( V_17 & 0xff000000L )
return ( V_18 [ ( int ) ( V_17 >> 24L ) ] + 24 ) ;
else
return ( V_18 [ ( int ) ( V_17 >> 16L ) ] + 16 ) ;
} else
#endif
{
#if F_5 ( V_20 ) || F_5 ( F_6 ) || F_5 ( V_19 )
if ( V_17 & 0xff00L )
return ( V_18 [ ( int ) ( V_17 >> 8 ) ] + 8 ) ;
else
#endif
return ( V_18 [ ( int ) ( V_17 ) ] ) ;
}
}
}
int F_7 ( const T_1 * V_21 )
{
int V_22 = V_21 -> V_23 - 1 ;
F_8 ( V_21 ) ;
if ( F_9 ( V_21 ) )
return 0 ;
return ( ( V_22 * V_24 ) + F_4 ( V_21 -> V_25 [ V_22 ] ) ) ;
}
static void F_10 ( T_1 * V_21 )
{
if ( F_11 ( V_21 , V_26 ) )
F_12 ( V_21 -> V_25 ) ;
else
F_13 ( V_21 -> V_25 ) ;
}
void F_14 ( T_1 * V_21 )
{
int V_22 ;
if ( V_21 == NULL )
return;
F_8 ( V_21 ) ;
if ( V_21 -> V_25 != NULL ) {
F_15 ( V_21 -> V_25 , V_21 -> V_27 * sizeof( V_21 -> V_25 [ 0 ] ) ) ;
if ( ! F_11 ( V_21 , V_16 ) )
F_10 ( V_21 ) ;
}
V_22 = F_11 ( V_21 , V_28 ) ;
F_15 ( V_21 , sizeof( * V_21 ) ) ;
if ( V_22 )
F_13 ( V_21 ) ;
}
void F_16 ( T_1 * V_21 )
{
if ( V_21 == NULL )
return;
F_8 ( V_21 ) ;
if ( ! F_11 ( V_21 , V_16 ) )
F_10 ( V_21 ) ;
if ( V_21 -> V_29 & V_28 )
F_13 ( V_21 ) ;
else {
#if V_30 < 0x00908000L
V_21 -> V_29 |= V_31 ;
#endif
V_21 -> V_25 = NULL ;
}
}
void F_17 ( T_1 * V_21 )
{
static T_1 V_32 ;
* V_21 = V_32 ;
F_8 ( V_21 ) ;
}
T_1 * F_18 ( void )
{
T_1 * V_33 ;
if ( ( V_33 = F_19 ( sizeof( * V_33 ) ) ) == NULL ) {
F_20 ( V_34 , V_35 ) ;
return ( NULL ) ;
}
V_33 -> V_29 = V_28 ;
F_8 ( V_33 ) ;
return ( V_33 ) ;
}
T_1 * F_21 ( void )
{
T_1 * V_33 = F_18 () ;
if ( V_33 != NULL )
V_33 -> V_29 |= V_26 ;
return ( V_33 ) ;
}
static T_2 * F_22 ( const T_1 * V_36 , int V_37 )
{
T_2 * V_38 , * V_21 = NULL ;
const T_2 * V_39 ;
int V_22 ;
F_8 ( V_36 ) ;
if ( V_37 > ( V_40 / ( 4 * V_24 ) ) ) {
F_20 ( V_41 , V_42 ) ;
return NULL ;
}
if ( F_11 ( V_36 , V_16 ) ) {
F_20 ( V_41 , V_43 ) ;
return ( NULL ) ;
}
if ( F_11 ( V_36 , V_26 ) )
V_21 = V_38 = F_23 ( V_37 * sizeof( * V_21 ) ) ;
else
V_21 = V_38 = F_19 ( V_37 * sizeof( * V_21 ) ) ;
if ( V_38 == NULL ) {
F_20 ( V_41 , V_35 ) ;
return ( NULL ) ;
}
#if 1
V_39 = V_36 -> V_25 ;
if ( V_39 != NULL ) {
for ( V_22 = V_36 -> V_23 >> 2 ; V_22 > 0 ; V_22 -- , V_38 += 4 , V_39 += 4 ) {
T_2 V_44 , V_45 , V_46 , V_47 ;
V_44 = V_39 [ 0 ] ;
V_45 = V_39 [ 1 ] ;
V_46 = V_39 [ 2 ] ;
V_47 = V_39 [ 3 ] ;
V_38 [ 0 ] = V_44 ;
V_38 [ 1 ] = V_45 ;
V_38 [ 2 ] = V_46 ;
V_38 [ 3 ] = V_47 ;
}
switch ( V_36 -> V_23 & 3 ) {
case 3 :
V_38 [ 2 ] = V_39 [ 2 ] ;
case 2 :
V_38 [ 1 ] = V_39 [ 1 ] ;
case 1 :
V_38 [ 0 ] = V_39 [ 0 ] ;
case 0 :
;
}
}
#else
memset ( V_38 , 0 , sizeof( * V_38 ) * V_37 ) ;
memcpy ( V_38 , V_36 -> V_25 , sizeof( V_36 -> V_25 [ 0 ] ) * V_36 -> V_23 ) ;
#endif
return ( V_21 ) ;
}
T_1 * F_24 ( T_1 * V_36 , int V_37 )
{
F_8 ( V_36 ) ;
if ( V_37 > V_36 -> V_27 ) {
T_2 * V_21 = F_22 ( V_36 , V_37 ) ;
if ( ! V_21 )
return NULL ;
if ( V_36 -> V_25 ) {
F_15 ( V_36 -> V_25 , V_36 -> V_27 * sizeof( V_36 -> V_25 [ 0 ] ) ) ;
F_10 ( V_36 ) ;
}
V_36 -> V_25 = V_21 ;
V_36 -> V_27 = V_37 ;
}
F_8 ( V_36 ) ;
return V_36 ;
}
T_1 * F_25 ( const T_1 * V_21 )
{
T_1 * V_48 ;
if ( V_21 == NULL )
return NULL ;
F_8 ( V_21 ) ;
V_48 = F_11 ( V_21 , V_26 ) ? F_21 () : F_18 () ;
if ( V_48 == NULL )
return NULL ;
if ( ! F_26 ( V_48 , V_21 ) ) {
F_16 ( V_48 ) ;
return NULL ;
}
F_8 ( V_48 ) ;
return V_48 ;
}
T_1 * F_26 ( T_1 * V_21 , const T_1 * V_36 )
{
int V_22 ;
T_2 * V_38 ;
const T_2 * V_39 ;
F_8 ( V_36 ) ;
if ( V_21 == V_36 )
return ( V_21 ) ;
if ( F_27 ( V_21 , V_36 -> V_23 ) == NULL )
return ( NULL ) ;
#if 1
V_38 = V_21 -> V_25 ;
V_39 = V_36 -> V_25 ;
for ( V_22 = V_36 -> V_23 >> 2 ; V_22 > 0 ; V_22 -- , V_38 += 4 , V_39 += 4 ) {
T_2 V_44 , V_45 , V_46 , V_47 ;
V_44 = V_39 [ 0 ] ;
V_45 = V_39 [ 1 ] ;
V_46 = V_39 [ 2 ] ;
V_47 = V_39 [ 3 ] ;
V_38 [ 0 ] = V_44 ;
V_38 [ 1 ] = V_45 ;
V_38 [ 2 ] = V_46 ;
V_38 [ 3 ] = V_47 ;
}
switch ( V_36 -> V_23 & 3 ) {
case 3 :
V_38 [ 2 ] = V_39 [ 2 ] ;
case 2 :
V_38 [ 1 ] = V_39 [ 1 ] ;
case 1 :
V_38 [ 0 ] = V_39 [ 0 ] ;
case 0 : ;
}
#else
memcpy ( V_21 -> V_25 , V_36 -> V_25 , sizeof( V_36 -> V_25 [ 0 ] ) * V_36 -> V_23 ) ;
#endif
V_21 -> V_23 = V_36 -> V_23 ;
V_21 -> V_49 = V_36 -> V_49 ;
F_8 ( V_21 ) ;
return ( V_21 ) ;
}
void F_28 ( T_1 * V_21 , T_1 * V_36 )
{
int V_50 , V_51 ;
T_2 * V_52 ;
int V_53 , V_54 , V_55 ;
F_8 ( V_21 ) ;
F_8 ( V_36 ) ;
V_50 = V_21 -> V_29 ;
V_51 = V_36 -> V_29 ;
V_52 = V_21 -> V_25 ;
V_53 = V_21 -> V_23 ;
V_54 = V_21 -> V_27 ;
V_55 = V_21 -> V_49 ;
V_21 -> V_25 = V_36 -> V_25 ;
V_21 -> V_23 = V_36 -> V_23 ;
V_21 -> V_27 = V_36 -> V_27 ;
V_21 -> V_49 = V_36 -> V_49 ;
V_36 -> V_25 = V_52 ;
V_36 -> V_23 = V_53 ;
V_36 -> V_27 = V_54 ;
V_36 -> V_49 = V_55 ;
V_21 -> V_29 =
( V_50 & V_28 ) | ( V_51 & V_16 ) ;
V_36 -> V_29 =
( V_51 & V_28 ) | ( V_50 & V_16 ) ;
F_8 ( V_21 ) ;
F_8 ( V_36 ) ;
}
void F_29 ( T_1 * V_21 )
{
F_8 ( V_21 ) ;
if ( V_21 -> V_25 != NULL )
F_15 ( V_21 -> V_25 , sizeof( * V_21 -> V_25 ) * V_21 -> V_27 ) ;
V_21 -> V_23 = 0 ;
V_21 -> V_49 = 0 ;
}
T_2 F_30 ( const T_1 * V_21 )
{
if ( V_21 -> V_23 > 1 )
return V_56 ;
else if ( V_21 -> V_23 == 1 )
return V_21 -> V_25 [ 0 ] ;
return 0 ;
}
int F_31 ( T_1 * V_21 , T_2 V_57 )
{
F_8 ( V_21 ) ;
if ( F_32 ( V_21 , ( int ) sizeof( T_2 ) * 8 ) == NULL )
return ( 0 ) ;
V_21 -> V_49 = 0 ;
V_21 -> V_25 [ 0 ] = V_57 ;
V_21 -> V_23 = ( V_57 ? 1 : 0 ) ;
F_8 ( V_21 ) ;
return ( 1 ) ;
}
T_1 * F_33 ( const unsigned char * V_58 , int V_59 , T_1 * V_33 )
{
unsigned int V_22 , V_60 ;
unsigned int V_61 ;
T_2 V_17 ;
T_1 * V_62 = NULL ;
if ( V_33 == NULL )
V_33 = V_62 = F_18 () ;
if ( V_33 == NULL )
return ( NULL ) ;
F_8 ( V_33 ) ;
for ( ; V_59 > 0 && * V_58 == 0 ; V_58 ++ , V_59 -- )
continue;
V_61 = V_59 ;
if ( V_61 == 0 ) {
V_33 -> V_23 = 0 ;
return ( V_33 ) ;
}
V_22 = ( ( V_61 - 1 ) / V_63 ) + 1 ;
V_60 = ( ( V_61 - 1 ) % ( V_63 ) ) ;
if ( F_27 ( V_33 , ( int ) V_22 ) == NULL ) {
F_16 ( V_62 ) ;
return NULL ;
}
V_33 -> V_23 = V_22 ;
V_33 -> V_49 = 0 ;
V_17 = 0 ;
while ( V_61 -- ) {
V_17 = ( V_17 << 8L ) | * ( V_58 ++ ) ;
if ( V_60 -- == 0 ) {
V_33 -> V_25 [ -- V_22 ] = V_17 ;
V_17 = 0 ;
V_60 = V_63 - 1 ;
}
}
F_34 ( V_33 ) ;
return ( V_33 ) ;
}
static int F_35 ( const T_1 * V_21 , unsigned char * V_64 , int V_65 )
{
int V_22 ;
T_2 V_17 ;
F_8 ( V_21 ) ;
V_22 = F_36 ( V_21 ) ;
if ( V_65 == - 1 )
V_65 = V_22 ;
else if ( V_65 < V_22 )
return - 1 ;
if ( V_65 > V_22 ) {
memset ( V_64 , 0 , V_65 - V_22 ) ;
V_64 += V_65 - V_22 ;
}
while ( V_22 -- ) {
V_17 = V_21 -> V_25 [ V_22 / V_63 ] ;
* ( V_64 ++ ) = ( unsigned char ) ( V_17 >> ( 8 * ( V_22 % V_63 ) ) ) & 0xff ;
}
return V_65 ;
}
int F_37 ( const T_1 * V_21 , unsigned char * V_64 , int V_65 )
{
if ( V_65 < 0 )
return - 1 ;
return F_35 ( V_21 , V_64 , V_65 ) ;
}
int F_38 ( const T_1 * V_21 , unsigned char * V_64 )
{
return F_35 ( V_21 , V_64 , - 1 ) ;
}
T_1 * F_39 ( const unsigned char * V_58 , int V_59 , T_1 * V_33 )
{
unsigned int V_22 , V_60 ;
unsigned int V_61 ;
T_2 V_17 ;
T_1 * V_62 = NULL ;
if ( V_33 == NULL )
V_33 = V_62 = F_18 () ;
if ( V_33 == NULL )
return ( NULL ) ;
F_8 ( V_33 ) ;
V_58 += V_59 ;
for ( ; V_59 > 0 && V_58 [ - 1 ] == 0 ; V_58 -- , V_59 -- )
continue;
V_61 = V_59 ;
if ( V_61 == 0 ) {
V_33 -> V_23 = 0 ;
return V_33 ;
}
V_22 = ( ( V_61 - 1 ) / V_63 ) + 1 ;
V_60 = ( ( V_61 - 1 ) % ( V_63 ) ) ;
if ( F_27 ( V_33 , ( int ) V_22 ) == NULL ) {
F_16 ( V_62 ) ;
return NULL ;
}
V_33 -> V_23 = V_22 ;
V_33 -> V_49 = 0 ;
V_17 = 0 ;
while ( V_61 -- ) {
V_58 -- ;
V_17 = ( V_17 << 8L ) | * V_58 ;
if ( V_60 -- == 0 ) {
V_33 -> V_25 [ -- V_22 ] = V_17 ;
V_17 = 0 ;
V_60 = V_63 - 1 ;
}
}
F_34 ( V_33 ) ;
return V_33 ;
}
int F_40 ( const T_1 * V_21 , unsigned char * V_64 , int V_65 )
{
int V_22 ;
T_2 V_17 ;
F_8 ( V_21 ) ;
V_22 = F_36 ( V_21 ) ;
if ( V_65 < V_22 )
return - 1 ;
if ( V_65 > V_22 )
memset ( V_64 + V_22 , 0 , V_65 - V_22 ) ;
V_64 += V_22 ;
while ( V_22 -- ) {
V_17 = V_21 -> V_25 [ V_22 / V_63 ] ;
V_64 -- ;
* V_64 = ( unsigned char ) ( V_17 >> ( 8 * ( V_22 % V_63 ) ) ) & 0xff ;
}
return V_65 ;
}
int F_41 ( const T_1 * V_21 , const T_1 * V_36 )
{
int V_22 ;
T_2 V_66 , V_67 , * V_68 , * V_69 ;
F_8 ( V_21 ) ;
F_8 ( V_36 ) ;
V_22 = V_21 -> V_23 - V_36 -> V_23 ;
if ( V_22 != 0 )
return ( V_22 ) ;
V_68 = V_21 -> V_25 ;
V_69 = V_36 -> V_25 ;
for ( V_22 = V_21 -> V_23 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_66 = V_68 [ V_22 ] ;
V_67 = V_69 [ V_22 ] ;
if ( V_66 != V_67 )
return ( ( V_66 > V_67 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_42 ( const T_1 * V_21 , const T_1 * V_36 )
{
int V_22 ;
int V_70 , V_71 ;
T_2 V_66 , V_67 ;
if ( ( V_21 == NULL ) || ( V_36 == NULL ) ) {
if ( V_21 != NULL )
return ( - 1 ) ;
else if ( V_36 != NULL )
return ( 1 ) ;
else
return ( 0 ) ;
}
F_8 ( V_21 ) ;
F_8 ( V_36 ) ;
if ( V_21 -> V_49 != V_36 -> V_49 ) {
if ( V_21 -> V_49 )
return ( - 1 ) ;
else
return ( 1 ) ;
}
if ( V_21 -> V_49 == 0 ) {
V_70 = 1 ;
V_71 = - 1 ;
} else {
V_70 = - 1 ;
V_71 = 1 ;
}
if ( V_21 -> V_23 > V_36 -> V_23 )
return ( V_70 ) ;
if ( V_21 -> V_23 < V_36 -> V_23 )
return ( V_71 ) ;
for ( V_22 = V_21 -> V_23 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_66 = V_21 -> V_25 [ V_22 ] ;
V_67 = V_36 -> V_25 [ V_22 ] ;
if ( V_66 > V_67 )
return ( V_70 ) ;
if ( V_66 < V_67 )
return ( V_71 ) ;
}
return ( 0 ) ;
}
int F_43 ( T_1 * V_21 , int V_61 )
{
int V_22 , V_72 , V_73 ;
if ( V_61 < 0 )
return 0 ;
V_22 = V_61 / V_24 ;
V_72 = V_61 % V_24 ;
if ( V_21 -> V_23 <= V_22 ) {
if ( F_27 ( V_21 , V_22 + 1 ) == NULL )
return ( 0 ) ;
for ( V_73 = V_21 -> V_23 ; V_73 < V_22 + 1 ; V_73 ++ )
V_21 -> V_25 [ V_73 ] = 0 ;
V_21 -> V_23 = V_22 + 1 ;
}
V_21 -> V_25 [ V_22 ] |= ( ( ( T_2 ) 1 ) << V_72 ) ;
F_8 ( V_21 ) ;
return ( 1 ) ;
}
int F_44 ( T_1 * V_21 , int V_61 )
{
int V_22 , V_72 ;
F_8 ( V_21 ) ;
if ( V_61 < 0 )
return 0 ;
V_22 = V_61 / V_24 ;
V_72 = V_61 % V_24 ;
if ( V_21 -> V_23 <= V_22 )
return ( 0 ) ;
V_21 -> V_25 [ V_22 ] &= ( ~ ( ( ( T_2 ) 1 ) << V_72 ) ) ;
F_34 ( V_21 ) ;
return ( 1 ) ;
}
int F_45 ( const T_1 * V_21 , int V_61 )
{
int V_22 , V_72 ;
F_8 ( V_21 ) ;
if ( V_61 < 0 )
return 0 ;
V_22 = V_61 / V_24 ;
V_72 = V_61 % V_24 ;
if ( V_21 -> V_23 <= V_22 )
return 0 ;
return ( int ) ( ( ( V_21 -> V_25 [ V_22 ] ) >> V_72 ) & ( ( T_2 ) 1 ) ) ;
}
int F_46 ( T_1 * V_21 , int V_61 )
{
int V_36 , V_57 ;
F_8 ( V_21 ) ;
if ( V_61 < 0 )
return 0 ;
V_57 = V_61 / V_24 ;
V_36 = V_61 % V_24 ;
if ( V_57 >= V_21 -> V_23 )
return 0 ;
if ( V_36 == 0 )
V_21 -> V_23 = V_57 ;
else {
V_21 -> V_23 = V_57 + 1 ;
V_21 -> V_25 [ V_57 ] &= ~ ( V_56 << V_36 ) ;
}
F_34 ( V_21 ) ;
return ( 1 ) ;
}
void F_47 ( T_1 * V_21 , int V_36 )
{
if ( V_36 && ! F_9 ( V_21 ) )
V_21 -> V_49 = 1 ;
else
V_21 -> V_49 = 0 ;
}
int F_48 ( const T_2 * V_21 , const T_2 * V_36 , int V_61 )
{
int V_22 ;
T_2 V_74 , V_75 ;
V_74 = V_21 [ V_61 - 1 ] ;
V_75 = V_36 [ V_61 - 1 ] ;
if ( V_74 != V_75 )
return ( ( V_74 > V_75 ) ? 1 : - 1 ) ;
for ( V_22 = V_61 - 2 ; V_22 >= 0 ; V_22 -- ) {
V_74 = V_21 [ V_22 ] ;
V_75 = V_36 [ V_22 ] ;
if ( V_74 != V_75 )
return ( ( V_74 > V_75 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_49 ( const T_2 * V_21 , const T_2 * V_36 , int V_76 , int V_77 )
{
int V_61 , V_22 ;
V_61 = V_76 - 1 ;
if ( V_77 < 0 ) {
for ( V_22 = V_77 ; V_22 < 0 ; V_22 ++ ) {
if ( V_36 [ V_61 - V_22 ] != 0 )
return - 1 ;
}
}
if ( V_77 > 0 ) {
for ( V_22 = V_77 ; V_22 > 0 ; V_22 -- ) {
if ( V_21 [ V_61 + V_22 ] != 0 )
return 1 ;
}
}
return F_48 ( V_21 , V_36 , V_76 ) ;
}
void F_50 ( T_2 V_78 , T_1 * V_21 , T_1 * V_36 , int V_79 )
{
T_2 V_48 ;
int V_22 ;
F_51 ( V_21 , V_79 ) ;
F_51 ( V_36 , V_79 ) ;
assert ( V_21 != V_36 ) ;
assert ( ( V_78 & ( V_78 - 1 ) ) == 0 ) ;
assert ( sizeof( T_2 ) >= sizeof( int ) ) ;
V_78 = ( ( V_78 - 1 ) >> ( V_24 - 1 ) ) - 1 ;
V_48 = ( V_21 -> V_23 ^ V_36 -> V_23 ) & V_78 ;
V_21 -> V_23 ^= V_48 ;
V_36 -> V_23 ^= V_48 ;
#define F_52 ( T_3 ) \
do { \
t = (a->d[ind] ^ b->d[ind]) & condition; \
a->d[ind] ^= t; \
b->d[ind] ^= t; \
} while (0)
switch ( V_79 ) {
default:
for ( V_22 = 10 ; V_22 < V_79 ; V_22 ++ )
F_52 ( V_22 ) ;
case 10 :
F_52 ( 9 ) ;
case 9 :
F_52 ( 8 ) ;
case 8 :
F_52 ( 7 ) ;
case 7 :
F_52 ( 6 ) ;
case 6 :
F_52 ( 5 ) ;
case 5 :
F_52 ( 4 ) ;
case 4 :
F_52 ( 3 ) ;
case 3 :
F_52 ( 2 ) ;
case 2 :
F_52 ( 1 ) ;
case 1 :
F_52 ( 0 ) ;
}
#undef F_52
}
int F_53 ( int V_80 , int V_81 )
{
int V_82 , V_18 ;
if ( V_80 >= 15360 )
V_82 = 256 ;
else if ( V_80 >= 7690 )
V_82 = 192 ;
else if ( V_80 >= 3072 )
V_82 = 128 ;
else if ( V_80 >= 2048 )
V_82 = 112 ;
else if ( V_80 >= 1024 )
V_82 = 80 ;
else
return 0 ;
if ( V_81 == - 1 )
return V_82 ;
V_18 = V_81 / 2 ;
if ( V_18 < 80 )
return 0 ;
return V_18 >= V_82 ? V_82 : V_18 ;
}
void F_54 ( T_1 * V_21 )
{
V_21 -> V_23 = 0 ;
V_21 -> V_49 = 0 ;
}
int F_55 ( const T_1 * V_21 , const T_2 V_57 )
{
return ( ( V_21 -> V_23 == 1 ) && ( V_21 -> V_25 [ 0 ] == V_57 ) ) || ( ( V_57 == 0 ) && ( V_21 -> V_23 == 0 ) ) ;
}
int F_9 ( const T_1 * V_21 )
{
return V_21 -> V_23 == 0 ;
}
int F_56 ( const T_1 * V_21 )
{
return F_55 ( V_21 , 1 ) && ! V_21 -> V_49 ;
}
int F_57 ( const T_1 * V_21 , const T_2 V_57 )
{
return F_55 ( V_21 , V_57 ) && ( ! V_57 || ! V_21 -> V_49 ) ;
}
int F_58 ( const T_1 * V_21 )
{
return ( V_21 -> V_23 > 0 ) && ( V_21 -> V_25 [ 0 ] & 1 ) ;
}
int F_59 ( const T_1 * V_21 )
{
return ( V_21 -> V_49 != 0 ) ;
}
int F_60 ( T_1 * V_83 , const T_1 * V_21 , T_4 * V_4 ,
T_5 * V_84 )
{
return F_61 ( V_83 , V_21 , & ( V_4 -> V_85 ) , V_4 , V_84 ) ;
}
void F_62 ( T_1 * V_86 , const T_1 * V_36 , int V_29 )
{
V_86 -> V_25 = V_36 -> V_25 ;
V_86 -> V_23 = V_36 -> V_23 ;
V_86 -> V_27 = V_36 -> V_27 ;
V_86 -> V_49 = V_36 -> V_49 ;
V_86 -> V_29 = ( ( V_86 -> V_29 & V_28 )
| ( V_36 -> V_29 & ~ V_28 )
| V_16 | V_29 ) ;
}
T_6 * F_63 ( void )
{
T_6 * V_33 ;
if ( ( V_33 = F_64 ( sizeof( * V_33 ) ) ) == NULL ) {
F_20 ( V_87 , V_35 ) ;
return ( NULL ) ;
}
return V_33 ;
}
void F_65 ( T_6 * V_88 )
{
if ( V_88 == NULL )
return;
F_13 ( V_88 ) ;
}
void F_66 ( T_1 * V_36 , int V_61 )
{
V_36 -> V_29 |= V_61 ;
}
int F_11 ( const T_1 * V_36 , int V_61 )
{
return V_36 -> V_29 & V_61 ;
}
void F_67 ( T_6 * V_89 , void (* F_68) ( int , int , void * ) ,
void * V_90 )
{
T_6 * V_91 = V_89 ;
V_91 -> V_92 = 1 ;
V_91 -> V_93 = V_90 ;
V_91 -> V_88 . V_94 = F_68 ;
}
void F_69 ( T_6 * V_89 , int (* F_68) ( int , int , T_6 * ) ,
void * V_90 )
{
T_6 * V_91 = V_89 ;
V_91 -> V_92 = 2 ;
V_91 -> V_93 = V_90 ;
V_91 -> V_88 . V_95 = F_68 ;
}
void * F_70 ( T_6 * V_88 )
{
return V_88 -> V_93 ;
}
T_1 * F_27 ( T_1 * V_21 , int V_37 )
{
return ( V_37 <= V_21 -> V_27 ) ? V_21 : F_24 ( V_21 , V_37 ) ;
}
void F_34 ( T_1 * V_21 )
{
T_2 * V_96 ;
int V_53 = V_21 -> V_23 ;
if ( V_53 > 0 ) {
for ( V_96 = & ( V_21 -> V_25 [ V_53 ] ) ; V_53 > 0 ; V_53 -- ) {
V_96 -- ;
if ( * V_96 != 0 )
break;
}
V_21 -> V_23 = V_53 ;
}
F_71 ( V_21 ) ;
}
