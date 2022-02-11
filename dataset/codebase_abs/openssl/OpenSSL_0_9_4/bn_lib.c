void F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
if ( V_1 >= 0 )
{
if ( V_1 > ( sizeof( int ) * 8 ) - 1 )
V_1 = sizeof( int ) * 8 - 1 ;
V_5 = V_1 ;
V_6 = 1 << V_1 ;
}
if ( V_2 >= 0 )
{
if ( V_2 > ( sizeof( int ) * 8 ) - 1 )
V_2 = sizeof( int ) * 8 - 1 ;
V_7 = V_2 ;
V_8 = 1 << V_2 ;
}
if ( V_3 >= 0 )
{
if ( V_3 > ( sizeof( int ) * 8 ) - 1 )
V_3 = sizeof( int ) * 8 - 1 ;
V_9 = V_3 ;
V_10 = 1 << V_3 ;
}
if ( V_4 >= 0 )
{
if ( V_4 > ( sizeof( int ) * 8 ) - 1 )
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
T_1 * F_3 ( void )
{
static T_2 V_14 = 1L ;
static T_1 V_15 = { & V_14 , 1 , 1 , 0 } ;
return ( & V_15 ) ;
}
char * F_4 ( void )
{
static int V_16 = 0 ;
static char V_17 [ 16 ] ;
if ( ! V_16 )
{
V_16 ++ ;
#ifdef F_5
sprintf ( V_17 , L_1 , ( int ) sizeof( V_18 ) * 8 ,
( int ) sizeof( T_2 ) * 8 ) ;
#else
sprintf ( V_17 , L_1 , ( int ) sizeof( T_2 ) * 8 ,
( int ) sizeof( T_2 ) * 8 ) ;
#endif
}
return ( V_17 ) ;
}
int F_6 ( T_2 V_19 )
{
static const char V_20 [ 256 ] = {
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
#if F_7 ( V_21 )
if ( V_19 & 0xffffffff00000000L )
{
if ( V_19 & 0xffff000000000000L )
{
if ( V_19 & 0xff00000000000000L )
{
return ( V_20 [ ( int ) ( V_19 >> 56 ) ] + 56 ) ;
}
else return ( V_20 [ ( int ) ( V_19 >> 48 ) ] + 48 ) ;
}
else
{
if ( V_19 & 0x0000ff0000000000L )
{
return ( V_20 [ ( int ) ( V_19 >> 40 ) ] + 40 ) ;
}
else return ( V_20 [ ( int ) ( V_19 >> 32 ) ] + 32 ) ;
}
}
else
#else
#ifdef F_8
if ( V_19 & 0xffffffff00000000LL )
{
if ( V_19 & 0xffff000000000000LL )
{
if ( V_19 & 0xff00000000000000LL )
{
return ( V_20 [ ( int ) ( V_19 >> 56 ) ] + 56 ) ;
}
else return ( V_20 [ ( int ) ( V_19 >> 48 ) ] + 48 ) ;
}
else
{
if ( V_19 & 0x0000ff0000000000LL )
{
return ( V_20 [ ( int ) ( V_19 >> 40 ) ] + 40 ) ;
}
else return ( V_20 [ ( int ) ( V_19 >> 32 ) ] + 32 ) ;
}
}
else
#endif
#endif
{
#if F_7 ( V_22 ) || F_7 ( F_8 ) || F_7 ( V_21 )
if ( V_19 & 0xffff0000L )
{
if ( V_19 & 0xff000000L )
return ( V_20 [ ( int ) ( V_19 >> 24L ) ] + 24 ) ;
else return ( V_20 [ ( int ) ( V_19 >> 16L ) ] + 16 ) ;
}
else
#endif
{
#if F_7 ( V_23 ) || F_7 ( V_22 ) || F_7 ( F_8 ) || F_7 ( V_21 )
if ( V_19 & 0xff00L )
return ( V_20 [ ( int ) ( V_19 >> 8 ) ] + 8 ) ;
else
#endif
return ( V_20 [ ( int ) ( V_19 ) ] ) ;
}
}
}
int F_9 ( const T_1 * V_24 )
{
T_2 V_19 ;
int V_25 ;
F_10 ( V_24 ) ;
if ( V_24 -> V_26 == 0 ) return ( 0 ) ;
V_19 = V_24 -> V_27 [ V_24 -> V_26 - 1 ] ;
V_25 = ( V_24 -> V_26 - 1 ) * V_28 ;
if ( V_19 == 0 )
{
#if ! F_7 ( V_29 ) && ! F_7 ( V_30 )
fprintf ( V_31 , L_2 ) ;
#endif
abort () ;
}
return ( V_25 + F_6 ( V_19 ) ) ;
}
void F_11 ( T_1 * V_24 )
{
int V_25 ;
if ( V_24 == NULL ) return;
if ( V_24 -> V_27 != NULL )
{
memset ( V_24 -> V_27 , 0 , V_24 -> V_32 * sizeof( V_24 -> V_27 [ 0 ] ) ) ;
if ( ! ( F_12 ( V_24 , V_33 ) ) )
Free ( V_24 -> V_27 ) ;
}
V_25 = F_12 ( V_24 , V_34 ) ;
memset ( V_24 , 0 , sizeof( T_1 ) ) ;
if ( V_25 )
Free ( V_24 ) ;
}
void F_13 ( T_1 * V_24 )
{
if ( V_24 == NULL ) return;
if ( ( V_24 -> V_27 != NULL ) && ! ( F_12 ( V_24 , V_33 ) ) )
Free ( V_24 -> V_27 ) ;
V_24 -> V_35 |= V_36 ;
if ( V_24 -> V_35 & V_34 )
Free ( V_24 ) ;
}
void F_14 ( T_1 * V_24 )
{
memset ( V_24 , 0 , sizeof( T_1 ) ) ;
}
T_1 * F_15 ( void )
{
T_1 * V_37 ;
if ( ( V_37 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ) == NULL )
{
F_16 ( V_38 , V_39 ) ;
return ( NULL ) ;
}
V_37 -> V_35 = V_34 ;
V_37 -> V_26 = 0 ;
V_37 -> V_40 = 0 ;
V_37 -> V_32 = 0 ;
V_37 -> V_27 = NULL ;
return ( V_37 ) ;
}
T_3 * F_17 ( void )
{
T_3 * V_37 ;
V_37 = ( T_3 * ) Malloc ( sizeof( T_3 ) ) ;
if ( V_37 == NULL )
{
F_16 ( V_41 , V_39 ) ;
return ( NULL ) ;
}
F_18 ( V_37 ) ;
V_37 -> V_35 = V_34 ;
return ( V_37 ) ;
}
void F_18 ( T_3 * V_42 )
{
memset ( V_42 , 0 , sizeof( T_3 ) ) ;
V_42 -> V_43 = 0 ;
V_42 -> V_35 = 0 ;
}
void F_19 ( T_3 * V_44 )
{
int V_25 ;
if( V_44 == NULL )
return;
for ( V_25 = 0 ; V_25 < V_45 ; V_25 ++ )
F_11 ( & ( V_44 -> V_46 [ V_25 ] ) ) ;
if ( V_44 -> V_35 & V_34 )
Free ( V_44 ) ;
}
T_1 * F_20 ( T_1 * V_47 , int V_48 )
{
T_2 * V_49 , * V_24 ;
const T_2 * V_50 ;
int V_25 ;
F_10 ( V_47 ) ;
if ( V_48 > V_47 -> V_32 )
{
F_10 ( V_47 ) ;
if ( F_12 ( V_47 , V_33 ) )
{
F_16 ( V_51 , V_52 ) ;
return ( NULL ) ;
}
V_24 = V_49 = ( T_2 * ) Malloc ( sizeof( T_2 ) * ( V_48 + 1 ) ) ;
if ( V_49 == NULL )
{
F_16 ( V_51 , V_39 ) ;
return ( NULL ) ;
}
#if 1
V_50 = V_47 -> V_27 ;
if ( V_50 != NULL )
{
#if 0
for (i=b->top&(~7); i>0; i-=8)
{
A[0]=B[0]; A[1]=B[1]; A[2]=B[2]; A[3]=B[3];
A[4]=B[4]; A[5]=B[5]; A[6]=B[6]; A[7]=B[7];
A+=8;
B+=8;
}
switch (b->top&7)
{
case 7:
A[6]=B[6];
case 6:
A[5]=B[5];
case 5:
A[4]=B[4];
case 4:
A[3]=B[3];
case 3:
A[2]=B[2];
case 2:
A[1]=B[1];
case 1:
A[0]=B[0];
case 0:
;
}
#else
for ( V_25 = V_47 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_49 += 4 , V_50 += 4 )
{
T_2 V_53 , V_54 , V_55 , V_56 ;
V_53 = V_50 [ 0 ] ; V_54 = V_50 [ 1 ] ; V_55 = V_50 [ 2 ] ; V_56 = V_50 [ 3 ] ;
V_49 [ 0 ] = V_53 ; V_49 [ 1 ] = V_54 ; V_49 [ 2 ] = V_55 ; V_49 [ 3 ] = V_56 ;
}
switch ( V_47 -> V_26 & 3 )
{
case 3 : V_49 [ 2 ] = V_50 [ 2 ] ;
case 2 : V_49 [ 1 ] = V_50 [ 1 ] ;
case 1 : V_49 [ 0 ] = V_50 [ 0 ] ;
case 0 : ;
}
#endif
Free ( V_47 -> V_27 ) ;
}
V_47 -> V_27 = V_24 ;
V_47 -> V_32 = V_48 ;
V_49 = & ( V_47 -> V_27 [ V_47 -> V_26 ] ) ;
for ( V_25 = ( V_47 -> V_32 - V_47 -> V_26 ) >> 3 ; V_25 > 0 ; V_25 -- , V_49 += 8 )
{
V_49 [ 0 ] = 0 ; V_49 [ 1 ] = 0 ; V_49 [ 2 ] = 0 ; V_49 [ 3 ] = 0 ;
V_49 [ 4 ] = 0 ; V_49 [ 5 ] = 0 ; V_49 [ 6 ] = 0 ; V_49 [ 7 ] = 0 ;
}
for ( V_25 = ( V_47 -> V_32 - V_47 -> V_26 ) & 7 ; V_25 > 0 ; V_25 -- , V_49 ++ )
V_49 [ 0 ] = 0 ;
#else
memset ( V_49 , 0 , sizeof( T_2 ) * ( V_48 + 1 ) ) ;
memcpy ( V_49 , V_47 -> V_27 , sizeof( V_47 -> V_27 [ 0 ] ) * V_47 -> V_26 ) ;
V_47 -> V_27 = V_24 ;
V_47 -> V_32 = V_48 ;
#endif
}
return ( V_47 ) ;
}
T_1 * F_21 ( const T_1 * V_24 )
{
T_1 * V_57 ;
if ( V_24 == NULL ) return NULL ;
F_10 ( V_24 ) ;
V_57 = F_15 () ;
if ( V_57 == NULL ) return ( NULL ) ;
return ( ( T_1 * ) F_22 ( V_57 , V_24 ) ) ;
}
T_1 * F_22 ( T_1 * V_24 , const T_1 * V_47 )
{
int V_25 ;
T_2 * V_49 ;
const T_2 * V_50 ;
F_10 ( V_47 ) ;
if ( V_24 == V_47 ) return ( V_24 ) ;
if ( F_23 ( V_24 , V_47 -> V_26 ) == NULL ) return ( NULL ) ;
#if 1
V_49 = V_24 -> V_27 ;
V_50 = V_47 -> V_27 ;
for ( V_25 = V_47 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_49 += 4 , V_50 += 4 )
{
T_2 V_53 , V_54 , V_55 , V_56 ;
V_53 = V_50 [ 0 ] ; V_54 = V_50 [ 1 ] ; V_55 = V_50 [ 2 ] ; V_56 = V_50 [ 3 ] ;
V_49 [ 0 ] = V_53 ; V_49 [ 1 ] = V_54 ; V_49 [ 2 ] = V_55 ; V_49 [ 3 ] = V_56 ;
}
switch ( V_47 -> V_26 & 3 )
{
case 3 : V_49 [ 2 ] = V_50 [ 2 ] ;
case 2 : V_49 [ 1 ] = V_50 [ 1 ] ;
case 1 : V_49 [ 0 ] = V_50 [ 0 ] ;
case 0 : ;
}
#else
memcpy ( V_24 -> V_27 , V_47 -> V_27 , sizeof( V_47 -> V_27 [ 0 ] ) * V_47 -> V_26 ) ;
#endif
V_24 -> V_26 = V_47 -> V_26 ;
if ( ( V_24 -> V_26 == 0 ) && ( V_24 -> V_27 != NULL ) )
V_24 -> V_27 [ 0 ] = 0 ;
V_24 -> V_40 = V_47 -> V_40 ;
return ( V_24 ) ;
}
void F_24 ( T_1 * V_24 )
{
if ( V_24 -> V_27 != NULL )
memset ( V_24 -> V_27 , 0 , V_24 -> V_32 * sizeof( V_24 -> V_27 [ 0 ] ) ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_40 = 0 ;
}
T_2 F_25 ( T_1 * V_24 )
{
int V_25 , V_58 ;
T_2 V_37 = 0 ;
V_58 = F_26 ( V_24 ) ;
if ( V_58 > sizeof( T_2 ) )
return ( V_59 ) ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
#ifndef F_8
V_37 <<= V_60 ;
V_37 <<= V_60 ;
#else
V_37 = 0 ;
#endif
V_37 |= V_24 -> V_27 [ V_25 ] ;
}
return ( V_37 ) ;
}
int F_27 ( T_1 * V_24 , T_2 V_61 )
{
int V_25 , V_58 ;
if ( F_28 ( V_24 , sizeof( T_2 ) * 8 ) == NULL ) return ( 0 ) ;
V_58 = sizeof( T_2 ) / V_62 ;
V_24 -> V_40 = 0 ;
V_24 -> V_26 = 0 ;
V_24 -> V_27 [ 0 ] = ( T_2 ) V_61 & V_59 ;
if ( V_24 -> V_27 [ 0 ] != 0 ) V_24 -> V_26 = 1 ;
for ( V_25 = 1 ; V_25 < V_58 ; V_25 ++ )
{
#ifndef F_8
V_61 >>= V_60 ;
V_61 >>= V_60 ;
#else
V_61 = 0 ;
#endif
V_24 -> V_27 [ V_25 ] = ( T_2 ) V_61 & V_59 ;
if ( V_24 -> V_27 [ V_25 ] != 0 ) V_24 -> V_26 = V_25 + 1 ;
}
return ( 1 ) ;
}
T_1 * F_29 ( const unsigned char * V_63 , int V_64 , T_1 * V_37 )
{
unsigned int V_25 , V_65 ;
unsigned int V_58 ;
T_2 V_19 ;
if ( V_37 == NULL ) V_37 = F_15 () ;
if ( V_37 == NULL ) return ( NULL ) ;
V_19 = 0 ;
V_58 = V_64 ;
if ( V_58 == 0 )
{
V_37 -> V_26 = 0 ;
return ( V_37 ) ;
}
if ( F_28 ( V_37 , ( int ) ( V_58 + 2 ) * 8 ) == NULL )
return ( NULL ) ;
V_25 = ( ( V_58 - 1 ) / V_62 ) + 1 ;
V_65 = ( ( V_58 - 1 ) % ( V_62 ) ) ;
V_37 -> V_26 = V_25 ;
while ( V_58 -- > 0 )
{
V_19 = ( V_19 << 8L ) | * ( V_63 ++ ) ;
if ( V_65 -- == 0 )
{
V_37 -> V_27 [ -- V_25 ] = V_19 ;
V_19 = 0 ;
V_65 = V_62 - 1 ;
}
}
F_30 ( V_37 ) ;
return ( V_37 ) ;
}
int F_31 ( const T_1 * V_24 , unsigned char * V_66 )
{
int V_58 , V_25 ;
T_2 V_19 ;
V_58 = V_25 = F_26 ( V_24 ) ;
while ( V_25 -- > 0 )
{
V_19 = V_24 -> V_27 [ V_25 / V_62 ] ;
* ( V_66 ++ ) = ( unsigned char ) ( V_19 >> ( 8 * ( V_25 % V_62 ) ) ) & 0xff ;
}
return ( V_58 ) ;
}
int F_32 ( const T_1 * V_24 , const T_1 * V_47 )
{
int V_25 ;
T_2 V_67 , V_68 , * V_69 , * V_70 ;
F_10 ( V_24 ) ;
F_10 ( V_47 ) ;
V_25 = V_24 -> V_26 - V_47 -> V_26 ;
if ( V_25 != 0 ) return ( V_25 ) ;
V_69 = V_24 -> V_27 ;
V_70 = V_47 -> V_27 ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_67 = V_69 [ V_25 ] ;
V_68 = V_70 [ V_25 ] ;
if ( V_67 != V_68 )
return ( V_67 > V_68 ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_33 ( const T_1 * V_24 , const T_1 * V_47 )
{
int V_25 ;
int V_71 , V_72 ;
T_2 V_67 , V_68 ;
if ( ( V_24 == NULL ) || ( V_47 == NULL ) )
{
if ( V_24 != NULL )
return ( - 1 ) ;
else if ( V_47 != NULL )
return ( 1 ) ;
else
return ( 0 ) ;
}
F_10 ( V_24 ) ;
F_10 ( V_47 ) ;
if ( V_24 -> V_40 != V_47 -> V_40 )
{
if ( V_24 -> V_40 )
return ( - 1 ) ;
else return ( 1 ) ;
}
if ( V_24 -> V_40 == 0 )
{ V_71 = 1 ; V_72 = - 1 ; }
else { V_71 = - 1 ; V_72 = 1 ; }
if ( V_24 -> V_26 > V_47 -> V_26 ) return ( V_71 ) ;
if ( V_24 -> V_26 < V_47 -> V_26 ) return ( V_72 ) ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_67 = V_24 -> V_27 [ V_25 ] ;
V_68 = V_47 -> V_27 [ V_25 ] ;
if ( V_67 > V_68 ) return ( V_71 ) ;
if ( V_67 < V_68 ) return ( V_72 ) ;
}
return ( 0 ) ;
}
int F_34 ( T_1 * V_24 , int V_58 )
{
int V_25 , V_73 , V_74 ;
V_25 = V_58 / V_28 ;
V_73 = V_58 % V_28 ;
if ( V_24 -> V_26 <= V_25 )
{
if ( F_23 ( V_24 , V_25 + 1 ) == NULL ) return ( 0 ) ;
for( V_74 = V_24 -> V_26 ; V_74 < V_25 + 1 ; V_74 ++ )
V_24 -> V_27 [ V_74 ] = 0 ;
V_24 -> V_26 = V_25 + 1 ;
}
V_24 -> V_27 [ V_25 ] |= ( ( ( T_2 ) 1 ) << V_73 ) ;
return ( 1 ) ;
}
int F_35 ( T_1 * V_24 , int V_58 )
{
int V_25 , V_73 ;
V_25 = V_58 / V_28 ;
V_73 = V_58 % V_28 ;
if ( V_24 -> V_26 <= V_25 ) return ( 0 ) ;
V_24 -> V_27 [ V_25 ] &= ( ~ ( ( ( T_2 ) 1 ) << V_73 ) ) ;
F_30 ( V_24 ) ;
return ( 1 ) ;
}
int F_36 ( const T_1 * V_24 , int V_58 )
{
int V_25 , V_73 ;
if ( V_58 < 0 ) return ( 0 ) ;
V_25 = V_58 / V_28 ;
V_73 = V_58 % V_28 ;
if ( V_24 -> V_26 <= V_25 ) return ( 0 ) ;
return ( ( V_24 -> V_27 [ V_25 ] & ( ( ( T_2 ) 1 ) << V_73 ) ) ? 1 : 0 ) ;
}
int F_37 ( T_1 * V_24 , int V_58 )
{
int V_47 , V_61 ;
V_61 = V_58 / V_28 ;
V_47 = V_58 % V_28 ;
if ( V_61 >= V_24 -> V_26 ) return ( 0 ) ;
if ( V_47 == 0 )
V_24 -> V_26 = V_61 ;
else
{
V_24 -> V_26 = V_61 + 1 ;
V_24 -> V_27 [ V_61 ] &= ~ ( V_59 << V_47 ) ;
}
F_30 ( V_24 ) ;
return ( 1 ) ;
}
int F_38 ( T_2 * V_24 , T_2 * V_47 , int V_58 )
{
int V_25 ;
T_2 V_75 , V_76 ;
V_75 = V_24 [ V_58 - 1 ] ;
V_76 = V_47 [ V_58 - 1 ] ;
if ( V_75 != V_76 ) return ( ( V_75 > V_76 ) ? 1 : - 1 ) ;
for ( V_25 = V_58 - 2 ; V_25 >= 0 ; V_25 -- )
{
V_75 = V_24 [ V_25 ] ;
V_76 = V_47 [ V_25 ] ;
if ( V_75 != V_76 ) return ( ( V_75 > V_76 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
