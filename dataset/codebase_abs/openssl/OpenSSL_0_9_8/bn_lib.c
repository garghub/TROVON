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
static T_2 V_14 = 1L ;
static T_1 V_15 = { & V_14 , 1 , 1 , 0 , V_16 } ;
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
static const char V_21 [ 256 ] = {
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
#if F_8 ( V_24 ) || F_8 ( V_23 ) || F_8 ( F_9 ) || F_8 ( V_22 )
if ( V_20 & 0xff00L )
return ( V_21 [ ( int ) ( V_20 >> 8 ) ] + 8 ) ;
else
#endif
return ( V_21 [ ( int ) ( V_20 ) ] ) ;
}
}
}
int F_10 ( const T_1 * V_25 )
{
int V_26 = V_25 -> V_27 - 1 ;
F_11 ( V_25 ) ;
if ( F_12 ( V_25 ) ) return 0 ;
return ( ( V_26 * V_28 ) + F_7 ( V_25 -> V_29 [ V_26 ] ) ) ;
}
void F_13 ( T_1 * V_25 )
{
int V_26 ;
if ( V_25 == NULL ) return;
F_11 ( V_25 ) ;
if ( V_25 -> V_29 != NULL )
{
F_14 ( V_25 -> V_29 , V_25 -> V_30 * sizeof( V_25 -> V_29 [ 0 ] ) ) ;
if ( ! ( F_15 ( V_25 , V_16 ) ) )
F_16 ( V_25 -> V_29 ) ;
}
V_26 = F_15 ( V_25 , V_31 ) ;
F_14 ( V_25 , sizeof( T_1 ) ) ;
if ( V_26 )
F_16 ( V_25 ) ;
}
void F_17 ( T_1 * V_25 )
{
if ( V_25 == NULL ) return;
F_11 ( V_25 ) ;
if ( ( V_25 -> V_29 != NULL ) && ! ( F_15 ( V_25 , V_16 ) ) )
F_16 ( V_25 -> V_29 ) ;
if ( V_25 -> V_32 & V_31 )
F_16 ( V_25 ) ;
else
{
#ifndef F_18
V_25 -> V_32 |= V_33 ;
#endif
V_25 -> V_29 = NULL ;
}
}
void F_19 ( T_1 * V_25 )
{
memset ( V_25 , 0 , sizeof( T_1 ) ) ;
F_11 ( V_25 ) ;
}
T_1 * F_20 ( void )
{
T_1 * V_34 ;
if ( ( V_34 = ( T_1 * ) F_21 ( sizeof( T_1 ) ) ) == NULL )
{
F_22 ( V_35 , V_36 ) ;
return ( NULL ) ;
}
V_34 -> V_32 = V_31 ;
V_34 -> V_27 = 0 ;
V_34 -> V_37 = 0 ;
V_34 -> V_30 = 0 ;
V_34 -> V_29 = NULL ;
F_11 ( V_34 ) ;
return ( V_34 ) ;
}
static T_2 * F_23 ( const T_1 * V_38 , int V_39 )
{
T_2 * V_40 , * V_25 = NULL ;
const T_2 * V_41 ;
int V_26 ;
F_11 ( V_38 ) ;
if ( V_39 > ( V_42 / ( 4 * V_28 ) ) )
{
F_22 ( V_43 , V_44 ) ;
return NULL ;
}
if ( F_15 ( V_38 , V_16 ) )
{
F_22 ( V_43 , V_45 ) ;
return ( NULL ) ;
}
V_25 = V_40 = ( T_2 * ) F_21 ( sizeof( T_2 ) * V_39 ) ;
if ( V_40 == NULL )
{
F_22 ( V_43 , V_36 ) ;
return ( NULL ) ;
}
#if 1
V_41 = V_38 -> V_29 ;
if ( V_41 != NULL )
{
for ( V_26 = V_38 -> V_27 >> 2 ; V_26 > 0 ; V_26 -- , V_40 += 4 , V_41 += 4 )
{
T_2 V_46 , V_47 , V_48 , V_49 ;
V_46 = V_41 [ 0 ] ; V_47 = V_41 [ 1 ] ; V_48 = V_41 [ 2 ] ; V_49 = V_41 [ 3 ] ;
V_40 [ 0 ] = V_46 ; V_40 [ 1 ] = V_47 ; V_40 [ 2 ] = V_48 ; V_40 [ 3 ] = V_49 ;
}
switch ( V_38 -> V_27 & 3 )
{
case 3 : V_40 [ 2 ] = V_41 [ 2 ] ;
case 2 : V_40 [ 1 ] = V_41 [ 1 ] ;
case 1 : V_40 [ 0 ] = V_41 [ 0 ] ;
case 0 :
;
}
}
#else
memset ( V_40 , 0 , sizeof( T_2 ) * V_39 ) ;
memcpy ( V_40 , V_38 -> V_29 , sizeof( V_38 -> V_29 [ 0 ] ) * V_38 -> V_27 ) ;
#endif
return ( V_25 ) ;
}
T_1 * F_24 ( const T_1 * V_38 , int V_39 )
{
T_1 * V_50 = NULL ;
F_11 ( V_38 ) ;
if ( V_39 > V_38 -> V_30 )
{
T_2 * V_25 = F_23 ( V_38 , V_39 ) ;
if ( V_25 )
{
V_50 = F_20 () ;
if ( V_50 )
{
V_50 -> V_27 = V_38 -> V_27 ;
V_50 -> V_30 = V_39 ;
V_50 -> V_37 = V_38 -> V_37 ;
V_50 -> V_29 = V_25 ;
}
else
{
F_16 ( V_25 ) ;
}
}
}
else
{
V_50 = F_25 ( V_38 ) ;
}
F_11 ( V_50 ) ;
return V_50 ;
}
T_1 * F_26 ( T_1 * V_38 , int V_39 )
{
F_11 ( V_38 ) ;
if ( V_39 > V_38 -> V_30 )
{
T_2 * V_25 = F_23 ( V_38 , V_39 ) ;
if( ! V_25 ) return NULL ;
if( V_38 -> V_29 ) F_16 ( V_38 -> V_29 ) ;
V_38 -> V_29 = V_25 ;
V_38 -> V_30 = V_39 ;
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
F_11 ( V_38 ) ;
return V_38 ;
}
T_1 * F_25 ( const T_1 * V_25 )
{
T_1 * V_51 ;
if ( V_25 == NULL ) return NULL ;
F_11 ( V_25 ) ;
V_51 = F_20 () ;
if ( V_51 == NULL ) return NULL ;
if( ! F_27 ( V_51 , V_25 ) )
{
F_17 ( V_51 ) ;
return NULL ;
}
F_11 ( V_51 ) ;
return V_51 ;
}
T_1 * F_27 ( T_1 * V_25 , const T_1 * V_38 )
{
int V_26 ;
T_2 * V_40 ;
const T_2 * V_41 ;
F_11 ( V_38 ) ;
if ( V_25 == V_38 ) return ( V_25 ) ;
if ( F_28 ( V_25 , V_38 -> V_27 ) == NULL ) return ( NULL ) ;
#if 1
V_40 = V_25 -> V_29 ;
V_41 = V_38 -> V_29 ;
for ( V_26 = V_38 -> V_27 >> 2 ; V_26 > 0 ; V_26 -- , V_40 += 4 , V_41 += 4 )
{
T_2 V_46 , V_47 , V_48 , V_49 ;
V_46 = V_41 [ 0 ] ; V_47 = V_41 [ 1 ] ; V_48 = V_41 [ 2 ] ; V_49 = V_41 [ 3 ] ;
V_40 [ 0 ] = V_46 ; V_40 [ 1 ] = V_47 ; V_40 [ 2 ] = V_48 ; V_40 [ 3 ] = V_49 ;
}
switch ( V_38 -> V_27 & 3 )
{
case 3 : V_40 [ 2 ] = V_41 [ 2 ] ;
case 2 : V_40 [ 1 ] = V_41 [ 1 ] ;
case 1 : V_40 [ 0 ] = V_41 [ 0 ] ;
case 0 : ;
}
#else
memcpy ( V_25 -> V_29 , V_38 -> V_29 , sizeof( V_38 -> V_29 [ 0 ] ) * V_38 -> V_27 ) ;
#endif
V_25 -> V_27 = V_38 -> V_27 ;
V_25 -> V_37 = V_38 -> V_37 ;
F_11 ( V_25 ) ;
return ( V_25 ) ;
}
void F_29 ( T_1 * V_25 , T_1 * V_38 )
{
int V_52 , V_53 ;
T_2 * V_54 ;
int V_55 , V_56 , V_57 ;
F_11 ( V_25 ) ;
F_11 ( V_38 ) ;
V_52 = V_25 -> V_32 ;
V_53 = V_38 -> V_32 ;
V_54 = V_25 -> V_29 ;
V_55 = V_25 -> V_27 ;
V_56 = V_25 -> V_30 ;
V_57 = V_25 -> V_37 ;
V_25 -> V_29 = V_38 -> V_29 ;
V_25 -> V_27 = V_38 -> V_27 ;
V_25 -> V_30 = V_38 -> V_30 ;
V_25 -> V_37 = V_38 -> V_37 ;
V_38 -> V_29 = V_54 ;
V_38 -> V_27 = V_55 ;
V_38 -> V_30 = V_56 ;
V_38 -> V_37 = V_57 ;
V_25 -> V_32 = ( V_52 & V_31 ) | ( V_53 & V_16 ) ;
V_38 -> V_32 = ( V_53 & V_31 ) | ( V_52 & V_16 ) ;
F_11 ( V_25 ) ;
F_11 ( V_38 ) ;
}
void F_30 ( T_1 * V_25 )
{
F_11 ( V_25 ) ;
if ( V_25 -> V_29 != NULL )
memset ( V_25 -> V_29 , 0 , V_25 -> V_30 * sizeof( V_25 -> V_29 [ 0 ] ) ) ;
V_25 -> V_27 = 0 ;
V_25 -> V_37 = 0 ;
}
T_2 F_31 ( const T_1 * V_25 )
{
if ( V_25 -> V_27 > 1 )
return V_58 ;
else if ( V_25 -> V_27 == 1 )
return V_25 -> V_29 [ 0 ] ;
return 0 ;
}
int F_32 ( T_1 * V_25 , T_2 V_59 )
{
F_11 ( V_25 ) ;
if ( F_33 ( V_25 , ( int ) sizeof( T_2 ) * 8 ) == NULL ) return ( 0 ) ;
V_25 -> V_37 = 0 ;
V_25 -> V_29 [ 0 ] = V_59 ;
V_25 -> V_27 = ( V_59 ? 1 : 0 ) ;
F_11 ( V_25 ) ;
return ( 1 ) ;
}
T_1 * F_34 ( const unsigned char * V_60 , int V_61 , T_1 * V_34 )
{
unsigned int V_26 , V_62 ;
unsigned int V_63 ;
T_2 V_20 ;
T_1 * V_64 = NULL ;
if ( V_34 == NULL )
V_34 = V_64 = F_20 () ;
if ( V_34 == NULL ) return ( NULL ) ;
F_11 ( V_34 ) ;
V_20 = 0 ;
V_63 = V_61 ;
if ( V_63 == 0 )
{
V_34 -> V_27 = 0 ;
return ( V_34 ) ;
}
V_26 = ( ( V_63 - 1 ) / V_65 ) + 1 ;
V_62 = ( ( V_63 - 1 ) % ( V_65 ) ) ;
if ( F_28 ( V_34 , ( int ) V_26 ) == NULL )
{
if ( V_64 ) F_17 ( V_64 ) ;
return NULL ;
}
V_34 -> V_27 = V_26 ;
V_34 -> V_37 = 0 ;
while ( V_63 -- )
{
V_20 = ( V_20 << 8L ) | * ( V_60 ++ ) ;
if ( V_62 -- == 0 )
{
V_34 -> V_29 [ -- V_26 ] = V_20 ;
V_20 = 0 ;
V_62 = V_65 - 1 ;
}
}
F_35 ( V_34 ) ;
return ( V_34 ) ;
}
int F_36 ( const T_1 * V_25 , unsigned char * V_66 )
{
int V_63 , V_26 ;
T_2 V_20 ;
F_11 ( V_25 ) ;
V_63 = V_26 = F_37 ( V_25 ) ;
while ( V_26 -- )
{
V_20 = V_25 -> V_29 [ V_26 / V_65 ] ;
* ( V_66 ++ ) = ( unsigned char ) ( V_20 >> ( 8 * ( V_26 % V_65 ) ) ) & 0xff ;
}
return ( V_63 ) ;
}
int F_38 ( const T_1 * V_25 , const T_1 * V_38 )
{
int V_26 ;
T_2 V_67 , V_68 , * V_69 , * V_70 ;
F_11 ( V_25 ) ;
F_11 ( V_38 ) ;
V_26 = V_25 -> V_27 - V_38 -> V_27 ;
if ( V_26 != 0 ) return ( V_26 ) ;
V_69 = V_25 -> V_29 ;
V_70 = V_38 -> V_29 ;
for ( V_26 = V_25 -> V_27 - 1 ; V_26 >= 0 ; V_26 -- )
{
V_67 = V_69 [ V_26 ] ;
V_68 = V_70 [ V_26 ] ;
if ( V_67 != V_68 )
return ( ( V_67 > V_68 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_39 ( const T_1 * V_25 , const T_1 * V_38 )
{
int V_26 ;
int V_71 , V_72 ;
T_2 V_67 , V_68 ;
if ( ( V_25 == NULL ) || ( V_38 == NULL ) )
{
if ( V_25 != NULL )
return ( - 1 ) ;
else if ( V_38 != NULL )
return ( 1 ) ;
else
return ( 0 ) ;
}
F_11 ( V_25 ) ;
F_11 ( V_38 ) ;
if ( V_25 -> V_37 != V_38 -> V_37 )
{
if ( V_25 -> V_37 )
return ( - 1 ) ;
else return ( 1 ) ;
}
if ( V_25 -> V_37 == 0 )
{ V_71 = 1 ; V_72 = - 1 ; }
else { V_71 = - 1 ; V_72 = 1 ; }
if ( V_25 -> V_27 > V_38 -> V_27 ) return ( V_71 ) ;
if ( V_25 -> V_27 < V_38 -> V_27 ) return ( V_72 ) ;
for ( V_26 = V_25 -> V_27 - 1 ; V_26 >= 0 ; V_26 -- )
{
V_67 = V_25 -> V_29 [ V_26 ] ;
V_68 = V_38 -> V_29 [ V_26 ] ;
if ( V_67 > V_68 ) return ( V_71 ) ;
if ( V_67 < V_68 ) return ( V_72 ) ;
}
return ( 0 ) ;
}
int F_40 ( T_1 * V_25 , int V_63 )
{
int V_26 , V_73 , V_74 ;
if ( V_63 < 0 )
return 0 ;
V_26 = V_63 / V_28 ;
V_73 = V_63 % V_28 ;
if ( V_25 -> V_27 <= V_26 )
{
if ( F_28 ( V_25 , V_26 + 1 ) == NULL ) return ( 0 ) ;
for( V_74 = V_25 -> V_27 ; V_74 < V_26 + 1 ; V_74 ++ )
V_25 -> V_29 [ V_74 ] = 0 ;
V_25 -> V_27 = V_26 + 1 ;
}
V_25 -> V_29 [ V_26 ] |= ( ( ( T_2 ) 1 ) << V_73 ) ;
F_11 ( V_25 ) ;
return ( 1 ) ;
}
int F_41 ( T_1 * V_25 , int V_63 )
{
int V_26 , V_73 ;
F_11 ( V_25 ) ;
if ( V_63 < 0 ) return 0 ;
V_26 = V_63 / V_28 ;
V_73 = V_63 % V_28 ;
if ( V_25 -> V_27 <= V_26 ) return ( 0 ) ;
V_25 -> V_29 [ V_26 ] &= ( ~ ( ( ( T_2 ) 1 ) << V_73 ) ) ;
F_35 ( V_25 ) ;
return ( 1 ) ;
}
int F_42 ( const T_1 * V_25 , int V_63 )
{
int V_26 , V_73 ;
F_11 ( V_25 ) ;
if ( V_63 < 0 ) return 0 ;
V_26 = V_63 / V_28 ;
V_73 = V_63 % V_28 ;
if ( V_25 -> V_27 <= V_26 ) return 0 ;
return ( ( V_25 -> V_29 [ V_26 ] & ( ( ( T_2 ) 1 ) << V_73 ) ) ? 1 : 0 ) ;
}
int F_43 ( T_1 * V_25 , int V_63 )
{
int V_38 , V_59 ;
F_11 ( V_25 ) ;
if ( V_63 < 0 ) return 0 ;
V_59 = V_63 / V_28 ;
V_38 = V_63 % V_28 ;
if ( V_59 >= V_25 -> V_27 ) return 0 ;
if ( V_38 == 0 )
V_25 -> V_27 = V_59 ;
else
{
V_25 -> V_27 = V_59 + 1 ;
V_25 -> V_29 [ V_59 ] &= ~ ( V_58 << V_38 ) ;
}
F_35 ( V_25 ) ;
return ( 1 ) ;
}
void F_44 ( T_1 * V_25 , int V_38 )
{
if ( V_38 && ! F_12 ( V_25 ) )
V_25 -> V_37 = 1 ;
else
V_25 -> V_37 = 0 ;
}
int F_45 ( const T_2 * V_25 , const T_2 * V_38 , int V_63 )
{
int V_26 ;
T_2 V_75 , V_76 ;
V_75 = V_25 [ V_63 - 1 ] ;
V_76 = V_38 [ V_63 - 1 ] ;
if ( V_75 != V_76 ) return ( ( V_75 > V_76 ) ? 1 : - 1 ) ;
for ( V_26 = V_63 - 2 ; V_26 >= 0 ; V_26 -- )
{
V_75 = V_25 [ V_26 ] ;
V_76 = V_38 [ V_26 ] ;
if ( V_75 != V_76 ) return ( ( V_75 > V_76 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_46 ( const T_2 * V_25 , const T_2 * V_38 ,
int V_77 , int V_78 )
{
int V_63 , V_26 ;
V_63 = V_77 - 1 ;
if ( V_78 < 0 )
{
for ( V_26 = V_78 ; V_26 < 0 ; V_26 ++ )
{
if ( V_38 [ V_63 - V_26 ] != 0 )
return - 1 ;
}
}
if ( V_78 > 0 )
{
for ( V_26 = V_78 ; V_26 > 0 ; V_26 -- )
{
if ( V_25 [ V_63 + V_26 ] != 0 )
return 1 ;
}
}
return F_45 ( V_25 , V_38 , V_77 ) ;
}
