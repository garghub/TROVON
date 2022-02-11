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
void F_10 ( T_1 * V_21 )
{
int V_22 ;
if ( V_21 == NULL )
return;
F_8 ( V_21 ) ;
if ( V_21 -> V_25 != NULL ) {
F_11 ( V_21 -> V_25 , V_21 -> V_26 * sizeof( V_21 -> V_25 [ 0 ] ) ) ;
if ( ! ( F_12 ( V_21 , V_16 ) ) )
F_13 ( V_21 -> V_25 ) ;
}
V_22 = F_12 ( V_21 , V_27 ) ;
F_11 ( V_21 , sizeof( T_1 ) ) ;
if ( V_22 )
F_13 ( V_21 ) ;
}
void F_14 ( T_1 * V_21 )
{
if ( V_21 == NULL )
return;
F_8 ( V_21 ) ;
if ( ( V_21 -> V_25 != NULL ) && ! ( F_12 ( V_21 , V_16 ) ) )
F_13 ( V_21 -> V_25 ) ;
if ( V_21 -> V_28 & V_27 )
F_13 ( V_21 ) ;
else {
#ifndef F_15
V_21 -> V_28 |= V_29 ;
#endif
V_21 -> V_25 = NULL ;
}
}
void F_16 ( T_1 * V_21 )
{
memset ( V_21 , 0 , sizeof( T_1 ) ) ;
F_8 ( V_21 ) ;
}
T_1 * F_17 ( void )
{
T_1 * V_30 ;
if ( ( V_30 = ( T_1 * ) F_18 ( sizeof( T_1 ) ) ) == NULL ) {
F_19 ( V_31 , V_32 ) ;
return ( NULL ) ;
}
V_30 -> V_28 = V_27 ;
V_30 -> V_23 = 0 ;
V_30 -> V_33 = 0 ;
V_30 -> V_26 = 0 ;
V_30 -> V_25 = NULL ;
F_8 ( V_30 ) ;
return ( V_30 ) ;
}
static T_2 * F_20 ( const T_1 * V_34 , int V_35 )
{
T_2 * V_36 , * V_21 = NULL ;
const T_2 * V_37 ;
int V_22 ;
F_8 ( V_34 ) ;
if ( V_35 > ( V_38 / ( 4 * V_24 ) ) ) {
F_19 ( V_39 , V_40 ) ;
return NULL ;
}
if ( F_12 ( V_34 , V_16 ) ) {
F_19 ( V_39 , V_41 ) ;
return ( NULL ) ;
}
V_21 = V_36 = ( T_2 * ) F_18 ( sizeof( T_2 ) * V_35 ) ;
if ( V_36 == NULL ) {
F_19 ( V_39 , V_32 ) ;
return ( NULL ) ;
}
#ifdef F_21
memset ( V_21 , 0 , sizeof( T_2 ) * V_35 ) ;
#endif
#if 1
V_37 = V_34 -> V_25 ;
if ( V_37 != NULL ) {
for ( V_22 = V_34 -> V_23 >> 2 ; V_22 > 0 ; V_22 -- , V_36 += 4 , V_37 += 4 ) {
T_2 V_42 , V_43 , V_44 , V_45 ;
V_42 = V_37 [ 0 ] ;
V_43 = V_37 [ 1 ] ;
V_44 = V_37 [ 2 ] ;
V_45 = V_37 [ 3 ] ;
V_36 [ 0 ] = V_42 ;
V_36 [ 1 ] = V_43 ;
V_36 [ 2 ] = V_44 ;
V_36 [ 3 ] = V_45 ;
}
switch ( V_34 -> V_23 & 3 ) {
case 3 :
V_36 [ 2 ] = V_37 [ 2 ] ;
case 2 :
V_36 [ 1 ] = V_37 [ 1 ] ;
case 1 :
V_36 [ 0 ] = V_37 [ 0 ] ;
case 0 :
;
}
}
#else
memset ( V_36 , 0 , sizeof( T_2 ) * V_35 ) ;
memcpy ( V_36 , V_34 -> V_25 , sizeof( V_34 -> V_25 [ 0 ] ) * V_34 -> V_23 ) ;
#endif
return ( V_21 ) ;
}
T_1 * F_22 ( const T_1 * V_34 , int V_35 )
{
T_1 * V_46 = NULL ;
F_8 ( V_34 ) ;
if ( V_35 > V_34 -> V_26 ) {
T_2 * V_21 = F_20 ( V_34 , V_35 ) ;
if ( V_21 ) {
V_46 = F_17 () ;
if ( V_46 ) {
V_46 -> V_23 = V_34 -> V_23 ;
V_46 -> V_26 = V_35 ;
V_46 -> V_33 = V_34 -> V_33 ;
V_46 -> V_25 = V_21 ;
} else {
F_13 ( V_21 ) ;
}
}
} else {
V_46 = F_23 ( V_34 ) ;
}
F_8 ( V_46 ) ;
return V_46 ;
}
T_1 * F_24 ( T_1 * V_34 , int V_35 )
{
F_8 ( V_34 ) ;
if ( V_35 > V_34 -> V_26 ) {
T_2 * V_21 = F_20 ( V_34 , V_35 ) ;
if ( ! V_21 )
return NULL ;
if ( V_34 -> V_25 )
F_13 ( V_34 -> V_25 ) ;
V_34 -> V_25 = V_21 ;
V_34 -> V_26 = V_35 ;
}
#if 0
if (b->top < b->dmax) {
int i;
BN_ULONG *A = &(b->d[b->top]);
for (i = (b->dmax - b->top) >> 3; i > 0; i--, A += 8) {
A[0] = 0;
A[1] = 0;
A[2] = 0;
A[3] = 0;
A[4] = 0;
A[5] = 0;
A[6] = 0;
A[7] = 0;
}
for (i = (b->dmax - b->top) & 7; i > 0; i--, A++)
A[0] = 0;
assert(A == &(b->d[b->dmax]));
}
#endif
F_8 ( V_34 ) ;
return V_34 ;
}
T_1 * F_23 ( const T_1 * V_21 )
{
T_1 * V_47 ;
if ( V_21 == NULL )
return NULL ;
F_8 ( V_21 ) ;
V_47 = F_17 () ;
if ( V_47 == NULL )
return NULL ;
if ( ! F_25 ( V_47 , V_21 ) ) {
F_14 ( V_47 ) ;
return NULL ;
}
F_8 ( V_47 ) ;
return V_47 ;
}
T_1 * F_25 ( T_1 * V_21 , const T_1 * V_34 )
{
int V_22 ;
T_2 * V_36 ;
const T_2 * V_37 ;
F_8 ( V_34 ) ;
if ( V_21 == V_34 )
return ( V_21 ) ;
if ( F_26 ( V_21 , V_34 -> V_23 ) == NULL )
return ( NULL ) ;
#if 1
V_36 = V_21 -> V_25 ;
V_37 = V_34 -> V_25 ;
for ( V_22 = V_34 -> V_23 >> 2 ; V_22 > 0 ; V_22 -- , V_36 += 4 , V_37 += 4 ) {
T_2 V_42 , V_43 , V_44 , V_45 ;
V_42 = V_37 [ 0 ] ;
V_43 = V_37 [ 1 ] ;
V_44 = V_37 [ 2 ] ;
V_45 = V_37 [ 3 ] ;
V_36 [ 0 ] = V_42 ;
V_36 [ 1 ] = V_43 ;
V_36 [ 2 ] = V_44 ;
V_36 [ 3 ] = V_45 ;
}
switch ( V_34 -> V_23 & 3 ) {
case 3 :
V_36 [ 2 ] = V_37 [ 2 ] ;
case 2 :
V_36 [ 1 ] = V_37 [ 1 ] ;
case 1 :
V_36 [ 0 ] = V_37 [ 0 ] ;
case 0 : ;
}
#else
memcpy ( V_21 -> V_25 , V_34 -> V_25 , sizeof( V_34 -> V_25 [ 0 ] ) * V_34 -> V_23 ) ;
#endif
V_21 -> V_23 = V_34 -> V_23 ;
V_21 -> V_33 = V_34 -> V_33 ;
F_8 ( V_21 ) ;
return ( V_21 ) ;
}
void F_27 ( T_1 * V_21 , T_1 * V_34 )
{
int V_48 , V_49 ;
T_2 * V_50 ;
int V_51 , V_52 , V_53 ;
F_8 ( V_21 ) ;
F_8 ( V_34 ) ;
V_48 = V_21 -> V_28 ;
V_49 = V_34 -> V_28 ;
V_50 = V_21 -> V_25 ;
V_51 = V_21 -> V_23 ;
V_52 = V_21 -> V_26 ;
V_53 = V_21 -> V_33 ;
V_21 -> V_25 = V_34 -> V_25 ;
V_21 -> V_23 = V_34 -> V_23 ;
V_21 -> V_26 = V_34 -> V_26 ;
V_21 -> V_33 = V_34 -> V_33 ;
V_34 -> V_25 = V_50 ;
V_34 -> V_23 = V_51 ;
V_34 -> V_26 = V_52 ;
V_34 -> V_33 = V_53 ;
V_21 -> V_28 =
( V_48 & V_27 ) | ( V_49 & V_16 ) ;
V_34 -> V_28 =
( V_49 & V_27 ) | ( V_48 & V_16 ) ;
F_8 ( V_21 ) ;
F_8 ( V_34 ) ;
}
void F_28 ( T_1 * V_21 )
{
F_8 ( V_21 ) ;
if ( V_21 -> V_25 != NULL )
memset ( V_21 -> V_25 , 0 , V_21 -> V_26 * sizeof( V_21 -> V_25 [ 0 ] ) ) ;
V_21 -> V_23 = 0 ;
V_21 -> V_33 = 0 ;
}
T_2 F_29 ( const T_1 * V_21 )
{
if ( V_21 -> V_23 > 1 )
return V_54 ;
else if ( V_21 -> V_23 == 1 )
return V_21 -> V_25 [ 0 ] ;
return 0 ;
}
int F_30 ( T_1 * V_21 , T_2 V_55 )
{
F_8 ( V_21 ) ;
if ( F_31 ( V_21 , ( int ) sizeof( T_2 ) * 8 ) == NULL )
return ( 0 ) ;
V_21 -> V_33 = 0 ;
V_21 -> V_25 [ 0 ] = V_55 ;
V_21 -> V_23 = ( V_55 ? 1 : 0 ) ;
F_8 ( V_21 ) ;
return ( 1 ) ;
}
T_1 * F_32 ( const unsigned char * V_56 , int V_57 , T_1 * V_30 )
{
unsigned int V_22 , V_58 ;
unsigned int V_59 ;
T_2 V_17 ;
T_1 * V_60 = NULL ;
if ( V_30 == NULL )
V_30 = V_60 = F_17 () ;
if ( V_30 == NULL )
return ( NULL ) ;
F_8 ( V_30 ) ;
V_17 = 0 ;
V_59 = V_57 ;
if ( V_59 == 0 ) {
V_30 -> V_23 = 0 ;
return ( V_30 ) ;
}
V_22 = ( ( V_59 - 1 ) / V_61 ) + 1 ;
V_58 = ( ( V_59 - 1 ) % ( V_61 ) ) ;
if ( F_26 ( V_30 , ( int ) V_22 ) == NULL ) {
if ( V_60 )
F_14 ( V_60 ) ;
return NULL ;
}
V_30 -> V_23 = V_22 ;
V_30 -> V_33 = 0 ;
while ( V_59 -- ) {
V_17 = ( V_17 << 8L ) | * ( V_56 ++ ) ;
if ( V_58 -- == 0 ) {
V_30 -> V_25 [ -- V_22 ] = V_17 ;
V_17 = 0 ;
V_58 = V_61 - 1 ;
}
}
F_33 ( V_30 ) ;
return ( V_30 ) ;
}
int F_34 ( const T_1 * V_21 , unsigned char * V_62 )
{
int V_59 , V_22 ;
T_2 V_17 ;
F_8 ( V_21 ) ;
V_59 = V_22 = F_35 ( V_21 ) ;
while ( V_22 -- ) {
V_17 = V_21 -> V_25 [ V_22 / V_61 ] ;
* ( V_62 ++ ) = ( unsigned char ) ( V_17 >> ( 8 * ( V_22 % V_61 ) ) ) & 0xff ;
}
return ( V_59 ) ;
}
int F_36 ( const T_1 * V_21 , const T_1 * V_34 )
{
int V_22 ;
T_2 V_63 , V_64 , * V_65 , * V_66 ;
F_8 ( V_21 ) ;
F_8 ( V_34 ) ;
V_22 = V_21 -> V_23 - V_34 -> V_23 ;
if ( V_22 != 0 )
return ( V_22 ) ;
V_65 = V_21 -> V_25 ;
V_66 = V_34 -> V_25 ;
for ( V_22 = V_21 -> V_23 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_63 = V_65 [ V_22 ] ;
V_64 = V_66 [ V_22 ] ;
if ( V_63 != V_64 )
return ( ( V_63 > V_64 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_37 ( const T_1 * V_21 , const T_1 * V_34 )
{
int V_22 ;
int V_67 , V_68 ;
T_2 V_63 , V_64 ;
if ( ( V_21 == NULL ) || ( V_34 == NULL ) ) {
if ( V_21 != NULL )
return ( - 1 ) ;
else if ( V_34 != NULL )
return ( 1 ) ;
else
return ( 0 ) ;
}
F_8 ( V_21 ) ;
F_8 ( V_34 ) ;
if ( V_21 -> V_33 != V_34 -> V_33 ) {
if ( V_21 -> V_33 )
return ( - 1 ) ;
else
return ( 1 ) ;
}
if ( V_21 -> V_33 == 0 ) {
V_67 = 1 ;
V_68 = - 1 ;
} else {
V_67 = - 1 ;
V_68 = 1 ;
}
if ( V_21 -> V_23 > V_34 -> V_23 )
return ( V_67 ) ;
if ( V_21 -> V_23 < V_34 -> V_23 )
return ( V_68 ) ;
for ( V_22 = V_21 -> V_23 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_63 = V_21 -> V_25 [ V_22 ] ;
V_64 = V_34 -> V_25 [ V_22 ] ;
if ( V_63 > V_64 )
return ( V_67 ) ;
if ( V_63 < V_64 )
return ( V_68 ) ;
}
return ( 0 ) ;
}
int F_38 ( T_1 * V_21 , int V_59 )
{
int V_22 , V_69 , V_70 ;
if ( V_59 < 0 )
return 0 ;
V_22 = V_59 / V_24 ;
V_69 = V_59 % V_24 ;
if ( V_21 -> V_23 <= V_22 ) {
if ( F_26 ( V_21 , V_22 + 1 ) == NULL )
return ( 0 ) ;
for ( V_70 = V_21 -> V_23 ; V_70 < V_22 + 1 ; V_70 ++ )
V_21 -> V_25 [ V_70 ] = 0 ;
V_21 -> V_23 = V_22 + 1 ;
}
V_21 -> V_25 [ V_22 ] |= ( ( ( T_2 ) 1 ) << V_69 ) ;
F_8 ( V_21 ) ;
return ( 1 ) ;
}
int F_39 ( T_1 * V_21 , int V_59 )
{
int V_22 , V_69 ;
F_8 ( V_21 ) ;
if ( V_59 < 0 )
return 0 ;
V_22 = V_59 / V_24 ;
V_69 = V_59 % V_24 ;
if ( V_21 -> V_23 <= V_22 )
return ( 0 ) ;
V_21 -> V_25 [ V_22 ] &= ( ~ ( ( ( T_2 ) 1 ) << V_69 ) ) ;
F_33 ( V_21 ) ;
return ( 1 ) ;
}
int F_40 ( const T_1 * V_21 , int V_59 )
{
int V_22 , V_69 ;
F_8 ( V_21 ) ;
if ( V_59 < 0 )
return 0 ;
V_22 = V_59 / V_24 ;
V_69 = V_59 % V_24 ;
if ( V_21 -> V_23 <= V_22 )
return 0 ;
return ( int ) ( ( ( V_21 -> V_25 [ V_22 ] ) >> V_69 ) & ( ( T_2 ) 1 ) ) ;
}
int F_41 ( T_1 * V_21 , int V_59 )
{
int V_34 , V_55 ;
F_8 ( V_21 ) ;
if ( V_59 < 0 )
return 0 ;
V_55 = V_59 / V_24 ;
V_34 = V_59 % V_24 ;
if ( V_55 >= V_21 -> V_23 )
return 0 ;
if ( V_34 == 0 )
V_21 -> V_23 = V_55 ;
else {
V_21 -> V_23 = V_55 + 1 ;
V_21 -> V_25 [ V_55 ] &= ~ ( V_54 << V_34 ) ;
}
F_33 ( V_21 ) ;
return ( 1 ) ;
}
void F_42 ( T_1 * V_21 , int V_34 )
{
if ( V_34 && ! F_9 ( V_21 ) )
V_21 -> V_33 = 1 ;
else
V_21 -> V_33 = 0 ;
}
int F_43 ( const T_2 * V_21 , const T_2 * V_34 , int V_59 )
{
int V_22 ;
T_2 V_71 , V_72 ;
V_71 = V_21 [ V_59 - 1 ] ;
V_72 = V_34 [ V_59 - 1 ] ;
if ( V_71 != V_72 )
return ( ( V_71 > V_72 ) ? 1 : - 1 ) ;
for ( V_22 = V_59 - 2 ; V_22 >= 0 ; V_22 -- ) {
V_71 = V_21 [ V_22 ] ;
V_72 = V_34 [ V_22 ] ;
if ( V_71 != V_72 )
return ( ( V_71 > V_72 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_44 ( const T_2 * V_21 , const T_2 * V_34 , int V_73 , int V_74 )
{
int V_59 , V_22 ;
V_59 = V_73 - 1 ;
if ( V_74 < 0 ) {
for ( V_22 = V_74 ; V_22 < 0 ; V_22 ++ ) {
if ( V_34 [ V_59 - V_22 ] != 0 )
return - 1 ;
}
}
if ( V_74 > 0 ) {
for ( V_22 = V_74 ; V_22 > 0 ; V_22 -- ) {
if ( V_21 [ V_59 + V_22 ] != 0 )
return 1 ;
}
}
return F_43 ( V_21 , V_34 , V_73 ) ;
}
void F_45 ( T_2 V_75 , T_1 * V_21 , T_1 * V_34 , int V_76 )
{
T_2 V_47 ;
int V_22 ;
F_46 ( V_21 , V_76 ) ;
F_46 ( V_34 , V_76 ) ;
assert ( V_21 != V_34 ) ;
assert ( ( V_75 & ( V_75 - 1 ) ) == 0 ) ;
assert ( sizeof( T_2 ) >= sizeof( int ) ) ;
V_75 = ( ( V_75 - 1 ) >> ( V_24 - 1 ) ) - 1 ;
V_47 = ( V_21 -> V_23 ^ V_34 -> V_23 ) & V_75 ;
V_21 -> V_23 ^= V_47 ;
V_34 -> V_23 ^= V_47 ;
#define F_47 ( T_3 ) \
do { \
t = (a->d[ind] ^ b->d[ind]) & condition; \
a->d[ind] ^= t; \
b->d[ind] ^= t; \
} while (0)
switch ( V_76 ) {
default:
for ( V_22 = 10 ; V_22 < V_76 ; V_22 ++ )
F_47 ( V_22 ) ;
case 10 :
F_47 ( 9 ) ;
case 9 :
F_47 ( 8 ) ;
case 8 :
F_47 ( 7 ) ;
case 7 :
F_47 ( 6 ) ;
case 6 :
F_47 ( 5 ) ;
case 5 :
F_47 ( 4 ) ;
case 4 :
F_47 ( 3 ) ;
case 3 :
F_47 ( 2 ) ;
case 2 :
F_47 ( 1 ) ;
case 1 :
F_47 ( 0 ) ;
}
#undef F_47
}
