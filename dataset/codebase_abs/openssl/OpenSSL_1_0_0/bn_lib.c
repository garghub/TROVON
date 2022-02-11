void F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
if ( V_1 >= 0 )
{
if ( V_1 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_1 = sizeof( int ) * 8 - 1 ;
V_5 = V_1 ;
V_6 = 1 << V_1 ;
}
if ( V_2 >= 0 )
{
if ( V_2 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_2 = sizeof( int ) * 8 - 1 ;
V_7 = V_2 ;
V_8 = 1 << V_2 ;
}
if ( V_3 >= 0 )
{
if ( V_3 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_3 = sizeof( int ) * 8 - 1 ;
V_9 = V_3 ;
V_10 = 1 << V_3 ;
}
if ( V_4 >= 0 )
{
if ( V_4 > ( int ) ( sizeof( int ) * 8 ) - 1 )
V_4 = sizeof( int ) * 8 - 1 ;
V_11 = V_4 ;
V_12 = 1 << V_4 ;
}
}
int F_2 ( int V_13 )
{
if ( V_13 == 0 ) return ( V_5 ) ;
else if ( V_13 == 1 ) return ( V_7 ) ;
else if ( V_13 == 2 ) return ( V_9 ) ;
else if ( V_13 == 3 ) return ( V_11 ) ;
else return ( 0 ) ;
}
const T_1 * F_3 ( void )
{
static const T_2 V_14 = 1L ;
static const T_1 V_15 = { ( T_2 * ) & V_14 , 1 , 1 , 0 , V_16 } ;
return ( & V_15 ) ;
}
char * F_4 ( void )
{
static int V_17 = 0 ;
static char V_18 [ 16 ] ;
if ( ! V_17 )
{
V_17 ++ ;
#ifdef F_5
F_6 ( V_18 , sizeof V_18 , L_1 ,
( int ) sizeof( V_19 ) * 8 , ( int ) sizeof( T_2 ) * 8 ) ;
#else
F_6 ( V_18 , sizeof V_18 , L_1 ,
( int ) sizeof( T_2 ) * 8 , ( int ) sizeof( T_2 ) * 8 ) ;
#endif
}
return ( V_18 ) ;
}
int F_7 ( T_2 V_20 )
{
static const unsigned char V_21 [ 256 ] = {
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
#if F_8 ( V_22 )
if ( V_20 & 0xffffffff00000000L )
{
if ( V_20 & 0xffff000000000000L )
{
if ( V_20 & 0xff00000000000000L )
{
return ( V_21 [ ( int ) ( V_20 >> 56 ) ] + 56 ) ;
}
else return ( V_21 [ ( int ) ( V_20 >> 48 ) ] + 48 ) ;
}
else
{
if ( V_20 & 0x0000ff0000000000L )
{
return ( V_21 [ ( int ) ( V_20 >> 40 ) ] + 40 ) ;
}
else return ( V_21 [ ( int ) ( V_20 >> 32 ) ] + 32 ) ;
}
}
else
#else
#ifdef F_9
if ( V_20 & 0xffffffff00000000LL )
{
if ( V_20 & 0xffff000000000000LL )
{
if ( V_20 & 0xff00000000000000LL )
{
return ( V_21 [ ( int ) ( V_20 >> 56 ) ] + 56 ) ;
}
else return ( V_21 [ ( int ) ( V_20 >> 48 ) ] + 48 ) ;
}
else
{
if ( V_20 & 0x0000ff0000000000LL )
{
return ( V_21 [ ( int ) ( V_20 >> 40 ) ] + 40 ) ;
}
else return ( V_21 [ ( int ) ( V_20 >> 32 ) ] + 32 ) ;
}
}
else
#endif
#endif
{
#if F_8 ( V_23 ) || F_8 ( F_9 ) || F_8 ( V_22 )
if ( V_20 & 0xffff0000L )
{
if ( V_20 & 0xff000000L )
return ( V_21 [ ( int ) ( V_20 >> 24L ) ] + 24 ) ;
else return ( V_21 [ ( int ) ( V_20 >> 16L ) ] + 16 ) ;
}
else
#endif
{
#if F_8 ( V_23 ) || F_8 ( F_9 ) || F_8 ( V_22 )
if ( V_20 & 0xff00L )
return ( V_21 [ ( int ) ( V_20 >> 8 ) ] + 8 ) ;
else
#endif
return ( V_21 [ ( int ) ( V_20 ) ] ) ;
}
}
}
int F_10 ( const T_1 * V_24 )
{
int V_25 = V_24 -> V_26 - 1 ;
F_11 ( V_24 ) ;
if ( F_12 ( V_24 ) ) return 0 ;
return ( ( V_25 * V_27 ) + F_7 ( V_24 -> V_28 [ V_25 ] ) ) ;
}
void F_13 ( T_1 * V_24 )
{
int V_25 ;
if ( V_24 == NULL ) return;
F_11 ( V_24 ) ;
if ( V_24 -> V_28 != NULL )
{
F_14 ( V_24 -> V_28 , V_24 -> V_29 * sizeof( V_24 -> V_28 [ 0 ] ) ) ;
if ( ! ( F_15 ( V_24 , V_16 ) ) )
F_16 ( V_24 -> V_28 ) ;
}
V_25 = F_15 ( V_24 , V_30 ) ;
F_14 ( V_24 , sizeof( T_1 ) ) ;
if ( V_25 )
F_16 ( V_24 ) ;
}
void F_17 ( T_1 * V_24 )
{
if ( V_24 == NULL ) return;
F_11 ( V_24 ) ;
if ( ( V_24 -> V_28 != NULL ) && ! ( F_15 ( V_24 , V_16 ) ) )
F_16 ( V_24 -> V_28 ) ;
if ( V_24 -> V_31 & V_30 )
F_16 ( V_24 ) ;
else
{
#ifndef F_18
V_24 -> V_31 |= V_32 ;
#endif
V_24 -> V_28 = NULL ;
}
}
void F_19 ( T_1 * V_24 )
{
memset ( V_24 , 0 , sizeof( T_1 ) ) ;
F_11 ( V_24 ) ;
}
T_1 * F_20 ( void )
{
T_1 * V_33 ;
if ( ( V_33 = ( T_1 * ) F_21 ( sizeof( T_1 ) ) ) == NULL )
{
F_22 ( V_34 , V_35 ) ;
return ( NULL ) ;
}
V_33 -> V_31 = V_30 ;
V_33 -> V_26 = 0 ;
V_33 -> V_36 = 0 ;
V_33 -> V_29 = 0 ;
V_33 -> V_28 = NULL ;
F_11 ( V_33 ) ;
return ( V_33 ) ;
}
static T_2 * F_23 ( const T_1 * V_37 , int V_38 )
{
T_2 * V_39 , * V_24 = NULL ;
const T_2 * V_40 ;
int V_25 ;
F_11 ( V_37 ) ;
if ( V_38 > ( V_41 / ( 4 * V_27 ) ) )
{
F_22 ( V_42 , V_43 ) ;
return NULL ;
}
if ( F_15 ( V_37 , V_16 ) )
{
F_22 ( V_42 , V_44 ) ;
return ( NULL ) ;
}
V_24 = V_39 = ( T_2 * ) F_21 ( sizeof( T_2 ) * V_38 ) ;
if ( V_39 == NULL )
{
F_22 ( V_42 , V_35 ) ;
return ( NULL ) ;
}
#if 1
V_40 = V_37 -> V_28 ;
if ( V_40 != NULL )
{
for ( V_25 = V_37 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_39 += 4 , V_40 += 4 )
{
T_2 V_45 , V_46 , V_47 , V_48 ;
V_45 = V_40 [ 0 ] ; V_46 = V_40 [ 1 ] ; V_47 = V_40 [ 2 ] ; V_48 = V_40 [ 3 ] ;
V_39 [ 0 ] = V_45 ; V_39 [ 1 ] = V_46 ; V_39 [ 2 ] = V_47 ; V_39 [ 3 ] = V_48 ;
}
switch ( V_37 -> V_26 & 3 )
{
case 3 : V_39 [ 2 ] = V_40 [ 2 ] ;
case 2 : V_39 [ 1 ] = V_40 [ 1 ] ;
case 1 : V_39 [ 0 ] = V_40 [ 0 ] ;
case 0 :
;
}
}
#else
memset ( V_39 , 0 , sizeof( T_2 ) * V_38 ) ;
memcpy ( V_39 , V_37 -> V_28 , sizeof( V_37 -> V_28 [ 0 ] ) * V_37 -> V_26 ) ;
#endif
return ( V_24 ) ;
}
T_1 * F_24 ( const T_1 * V_37 , int V_38 )
{
T_1 * V_49 = NULL ;
F_11 ( V_37 ) ;
if ( V_38 > V_37 -> V_29 )
{
T_2 * V_24 = F_23 ( V_37 , V_38 ) ;
if ( V_24 )
{
V_49 = F_20 () ;
if ( V_49 )
{
V_49 -> V_26 = V_37 -> V_26 ;
V_49 -> V_29 = V_38 ;
V_49 -> V_36 = V_37 -> V_36 ;
V_49 -> V_28 = V_24 ;
}
else
{
F_16 ( V_24 ) ;
}
}
}
else
{
V_49 = F_25 ( V_37 ) ;
}
F_11 ( V_49 ) ;
return V_49 ;
}
T_1 * F_26 ( T_1 * V_37 , int V_38 )
{
F_11 ( V_37 ) ;
if ( V_38 > V_37 -> V_29 )
{
T_2 * V_24 = F_23 ( V_37 , V_38 ) ;
if( ! V_24 ) return NULL ;
if( V_37 -> V_28 ) F_16 ( V_37 -> V_28 ) ;
V_37 -> V_28 = V_24 ;
V_37 -> V_29 = V_38 ;
}
#if 0
if (b->top < b->dmax)
{
int i;
BN_ULONG *A = &(b->d[b->top]);
for (i=(b->dmax - b->top)>>3; i>0; i--,A+=8)
{
A[0]=0; A[1]=0; A[2]=0; A[3]=0;
A[4]=0; A[5]=0; A[6]=0; A[7]=0;
}
for (i=(b->dmax - b->top)&7; i>0; i--,A++)
A[0]=0;
assert(A == &(b->d[b->dmax]));
}
#endif
F_11 ( V_37 ) ;
return V_37 ;
}
T_1 * F_25 ( const T_1 * V_24 )
{
T_1 * V_50 ;
if ( V_24 == NULL ) return NULL ;
F_11 ( V_24 ) ;
V_50 = F_20 () ;
if ( V_50 == NULL ) return NULL ;
if( ! F_27 ( V_50 , V_24 ) )
{
F_17 ( V_50 ) ;
return NULL ;
}
F_11 ( V_50 ) ;
return V_50 ;
}
T_1 * F_27 ( T_1 * V_24 , const T_1 * V_37 )
{
int V_25 ;
T_2 * V_39 ;
const T_2 * V_40 ;
F_11 ( V_37 ) ;
if ( V_24 == V_37 ) return ( V_24 ) ;
if ( F_28 ( V_24 , V_37 -> V_26 ) == NULL ) return ( NULL ) ;
#if 1
V_39 = V_24 -> V_28 ;
V_40 = V_37 -> V_28 ;
for ( V_25 = V_37 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_39 += 4 , V_40 += 4 )
{
T_2 V_45 , V_46 , V_47 , V_48 ;
V_45 = V_40 [ 0 ] ; V_46 = V_40 [ 1 ] ; V_47 = V_40 [ 2 ] ; V_48 = V_40 [ 3 ] ;
V_39 [ 0 ] = V_45 ; V_39 [ 1 ] = V_46 ; V_39 [ 2 ] = V_47 ; V_39 [ 3 ] = V_48 ;
}
switch ( V_37 -> V_26 & 3 )
{
case 3 : V_39 [ 2 ] = V_40 [ 2 ] ;
case 2 : V_39 [ 1 ] = V_40 [ 1 ] ;
case 1 : V_39 [ 0 ] = V_40 [ 0 ] ;
case 0 : ;
}
#else
memcpy ( V_24 -> V_28 , V_37 -> V_28 , sizeof( V_37 -> V_28 [ 0 ] ) * V_37 -> V_26 ) ;
#endif
V_24 -> V_26 = V_37 -> V_26 ;
V_24 -> V_36 = V_37 -> V_36 ;
F_11 ( V_24 ) ;
return ( V_24 ) ;
}
void F_29 ( T_1 * V_24 , T_1 * V_37 )
{
int V_51 , V_52 ;
T_2 * V_53 ;
int V_54 , V_55 , V_56 ;
F_11 ( V_24 ) ;
F_11 ( V_37 ) ;
V_51 = V_24 -> V_31 ;
V_52 = V_37 -> V_31 ;
V_53 = V_24 -> V_28 ;
V_54 = V_24 -> V_26 ;
V_55 = V_24 -> V_29 ;
V_56 = V_24 -> V_36 ;
V_24 -> V_28 = V_37 -> V_28 ;
V_24 -> V_26 = V_37 -> V_26 ;
V_24 -> V_29 = V_37 -> V_29 ;
V_24 -> V_36 = V_37 -> V_36 ;
V_37 -> V_28 = V_53 ;
V_37 -> V_26 = V_54 ;
V_37 -> V_29 = V_55 ;
V_37 -> V_36 = V_56 ;
V_24 -> V_31 = ( V_51 & V_30 ) | ( V_52 & V_16 ) ;
V_37 -> V_31 = ( V_52 & V_30 ) | ( V_51 & V_16 ) ;
F_11 ( V_24 ) ;
F_11 ( V_37 ) ;
}
void F_30 ( T_1 * V_24 )
{
F_11 ( V_24 ) ;
if ( V_24 -> V_28 != NULL )
memset ( V_24 -> V_28 , 0 , V_24 -> V_29 * sizeof( V_24 -> V_28 [ 0 ] ) ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_36 = 0 ;
}
T_2 F_31 ( const T_1 * V_24 )
{
if ( V_24 -> V_26 > 1 )
return V_57 ;
else if ( V_24 -> V_26 == 1 )
return V_24 -> V_28 [ 0 ] ;
return 0 ;
}
int F_32 ( T_1 * V_24 , T_2 V_58 )
{
F_11 ( V_24 ) ;
if ( F_33 ( V_24 , ( int ) sizeof( T_2 ) * 8 ) == NULL ) return ( 0 ) ;
V_24 -> V_36 = 0 ;
V_24 -> V_28 [ 0 ] = V_58 ;
V_24 -> V_26 = ( V_58 ? 1 : 0 ) ;
F_11 ( V_24 ) ;
return ( 1 ) ;
}
T_1 * F_34 ( const unsigned char * V_59 , int V_60 , T_1 * V_33 )
{
unsigned int V_25 , V_61 ;
unsigned int V_62 ;
T_2 V_20 ;
T_1 * V_63 = NULL ;
if ( V_33 == NULL )
V_33 = V_63 = F_20 () ;
if ( V_33 == NULL ) return ( NULL ) ;
F_11 ( V_33 ) ;
V_20 = 0 ;
V_62 = V_60 ;
if ( V_62 == 0 )
{
V_33 -> V_26 = 0 ;
return ( V_33 ) ;
}
V_25 = ( ( V_62 - 1 ) / V_64 ) + 1 ;
V_61 = ( ( V_62 - 1 ) % ( V_64 ) ) ;
if ( F_28 ( V_33 , ( int ) V_25 ) == NULL )
{
if ( V_63 ) F_17 ( V_63 ) ;
return NULL ;
}
V_33 -> V_26 = V_25 ;
V_33 -> V_36 = 0 ;
while ( V_62 -- )
{
V_20 = ( V_20 << 8L ) | * ( V_59 ++ ) ;
if ( V_61 -- == 0 )
{
V_33 -> V_28 [ -- V_25 ] = V_20 ;
V_20 = 0 ;
V_61 = V_64 - 1 ;
}
}
F_35 ( V_33 ) ;
return ( V_33 ) ;
}
int F_36 ( const T_1 * V_24 , unsigned char * V_65 )
{
int V_62 , V_25 ;
T_2 V_20 ;
F_11 ( V_24 ) ;
V_62 = V_25 = F_37 ( V_24 ) ;
while ( V_25 -- )
{
V_20 = V_24 -> V_28 [ V_25 / V_64 ] ;
* ( V_65 ++ ) = ( unsigned char ) ( V_20 >> ( 8 * ( V_25 % V_64 ) ) ) & 0xff ;
}
return ( V_62 ) ;
}
int F_38 ( const T_1 * V_24 , const T_1 * V_37 )
{
int V_25 ;
T_2 V_66 , V_67 , * V_68 , * V_69 ;
F_11 ( V_24 ) ;
F_11 ( V_37 ) ;
V_25 = V_24 -> V_26 - V_37 -> V_26 ;
if ( V_25 != 0 ) return ( V_25 ) ;
V_68 = V_24 -> V_28 ;
V_69 = V_37 -> V_28 ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_66 = V_68 [ V_25 ] ;
V_67 = V_69 [ V_25 ] ;
if ( V_66 != V_67 )
return ( ( V_66 > V_67 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_39 ( const T_1 * V_24 , const T_1 * V_37 )
{
int V_25 ;
int V_70 , V_71 ;
T_2 V_66 , V_67 ;
if ( ( V_24 == NULL ) || ( V_37 == NULL ) )
{
if ( V_24 != NULL )
return ( - 1 ) ;
else if ( V_37 != NULL )
return ( 1 ) ;
else
return ( 0 ) ;
}
F_11 ( V_24 ) ;
F_11 ( V_37 ) ;
if ( V_24 -> V_36 != V_37 -> V_36 )
{
if ( V_24 -> V_36 )
return ( - 1 ) ;
else return ( 1 ) ;
}
if ( V_24 -> V_36 == 0 )
{ V_70 = 1 ; V_71 = - 1 ; }
else { V_70 = - 1 ; V_71 = 1 ; }
if ( V_24 -> V_26 > V_37 -> V_26 ) return ( V_70 ) ;
if ( V_24 -> V_26 < V_37 -> V_26 ) return ( V_71 ) ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_66 = V_24 -> V_28 [ V_25 ] ;
V_67 = V_37 -> V_28 [ V_25 ] ;
if ( V_66 > V_67 ) return ( V_70 ) ;
if ( V_66 < V_67 ) return ( V_71 ) ;
}
return ( 0 ) ;
}
int F_40 ( T_1 * V_24 , int V_62 )
{
int V_25 , V_72 , V_73 ;
if ( V_62 < 0 )
return 0 ;
V_25 = V_62 / V_27 ;
V_72 = V_62 % V_27 ;
if ( V_24 -> V_26 <= V_25 )
{
if ( F_28 ( V_24 , V_25 + 1 ) == NULL ) return ( 0 ) ;
for( V_73 = V_24 -> V_26 ; V_73 < V_25 + 1 ; V_73 ++ )
V_24 -> V_28 [ V_73 ] = 0 ;
V_24 -> V_26 = V_25 + 1 ;
}
V_24 -> V_28 [ V_25 ] |= ( ( ( T_2 ) 1 ) << V_72 ) ;
F_11 ( V_24 ) ;
return ( 1 ) ;
}
int F_41 ( T_1 * V_24 , int V_62 )
{
int V_25 , V_72 ;
F_11 ( V_24 ) ;
if ( V_62 < 0 ) return 0 ;
V_25 = V_62 / V_27 ;
V_72 = V_62 % V_27 ;
if ( V_24 -> V_26 <= V_25 ) return ( 0 ) ;
V_24 -> V_28 [ V_25 ] &= ( ~ ( ( ( T_2 ) 1 ) << V_72 ) ) ;
F_35 ( V_24 ) ;
return ( 1 ) ;
}
int F_42 ( const T_1 * V_24 , int V_62 )
{
int V_25 , V_72 ;
F_11 ( V_24 ) ;
if ( V_62 < 0 ) return 0 ;
V_25 = V_62 / V_27 ;
V_72 = V_62 % V_27 ;
if ( V_24 -> V_26 <= V_25 ) return 0 ;
return ( int ) ( ( ( V_24 -> V_28 [ V_25 ] ) >> V_72 ) & ( ( T_2 ) 1 ) ) ;
}
int F_43 ( T_1 * V_24 , int V_62 )
{
int V_37 , V_58 ;
F_11 ( V_24 ) ;
if ( V_62 < 0 ) return 0 ;
V_58 = V_62 / V_27 ;
V_37 = V_62 % V_27 ;
if ( V_58 >= V_24 -> V_26 ) return 0 ;
if ( V_37 == 0 )
V_24 -> V_26 = V_58 ;
else
{
V_24 -> V_26 = V_58 + 1 ;
V_24 -> V_28 [ V_58 ] &= ~ ( V_57 << V_37 ) ;
}
F_35 ( V_24 ) ;
return ( 1 ) ;
}
void F_44 ( T_1 * V_24 , int V_37 )
{
if ( V_37 && ! F_12 ( V_24 ) )
V_24 -> V_36 = 1 ;
else
V_24 -> V_36 = 0 ;
}
int F_45 ( const T_2 * V_24 , const T_2 * V_37 , int V_62 )
{
int V_25 ;
T_2 V_74 , V_75 ;
V_74 = V_24 [ V_62 - 1 ] ;
V_75 = V_37 [ V_62 - 1 ] ;
if ( V_74 != V_75 ) return ( ( V_74 > V_75 ) ? 1 : - 1 ) ;
for ( V_25 = V_62 - 2 ; V_25 >= 0 ; V_25 -- )
{
V_74 = V_24 [ V_25 ] ;
V_75 = V_37 [ V_25 ] ;
if ( V_74 != V_75 ) return ( ( V_74 > V_75 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_46 ( const T_2 * V_24 , const T_2 * V_37 ,
int V_76 , int V_77 )
{
int V_62 , V_25 ;
V_62 = V_76 - 1 ;
if ( V_77 < 0 )
{
for ( V_25 = V_77 ; V_25 < 0 ; V_25 ++ )
{
if ( V_37 [ V_62 - V_25 ] != 0 )
return - 1 ;
}
}
if ( V_77 > 0 )
{
for ( V_25 = V_77 ; V_25 > 0 ; V_25 -- )
{
if ( V_24 [ V_62 + V_25 ] != 0 )
return 1 ;
}
}
return F_45 ( V_24 , V_37 , V_76 ) ;
}
