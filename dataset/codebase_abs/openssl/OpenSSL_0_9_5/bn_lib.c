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
T_1 * F_17 ( T_1 * V_41 , int V_42 )
{
T_2 * V_43 , * V_24 ;
const T_2 * V_44 ;
int V_25 ;
F_10 ( V_41 ) ;
if ( V_42 > V_41 -> V_32 )
{
F_10 ( V_41 ) ;
if ( F_12 ( V_41 , V_33 ) )
{
F_16 ( V_45 , V_46 ) ;
return ( NULL ) ;
}
V_24 = V_43 = ( T_2 * ) Malloc ( sizeof( T_2 ) * ( V_42 + 1 ) ) ;
if ( V_43 == NULL )
{
F_16 ( V_45 , V_39 ) ;
return ( NULL ) ;
}
#if 1
V_44 = V_41 -> V_27 ;
if ( V_44 != NULL )
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
for ( V_25 = V_41 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_43 += 4 , V_44 += 4 )
{
T_2 V_47 , V_48 , V_49 , V_50 ;
V_47 = V_44 [ 0 ] ; V_48 = V_44 [ 1 ] ; V_49 = V_44 [ 2 ] ; V_50 = V_44 [ 3 ] ;
V_43 [ 0 ] = V_47 ; V_43 [ 1 ] = V_48 ; V_43 [ 2 ] = V_49 ; V_43 [ 3 ] = V_50 ;
}
switch ( V_41 -> V_26 & 3 )
{
case 3 : V_43 [ 2 ] = V_44 [ 2 ] ;
case 2 : V_43 [ 1 ] = V_44 [ 1 ] ;
case 1 : V_43 [ 0 ] = V_44 [ 0 ] ;
case 0 : ;
}
#endif
Free ( V_41 -> V_27 ) ;
}
V_41 -> V_27 = V_24 ;
V_41 -> V_32 = V_42 ;
V_43 = & ( V_41 -> V_27 [ V_41 -> V_26 ] ) ;
for ( V_25 = ( V_41 -> V_32 - V_41 -> V_26 ) >> 3 ; V_25 > 0 ; V_25 -- , V_43 += 8 )
{
V_43 [ 0 ] = 0 ; V_43 [ 1 ] = 0 ; V_43 [ 2 ] = 0 ; V_43 [ 3 ] = 0 ;
V_43 [ 4 ] = 0 ; V_43 [ 5 ] = 0 ; V_43 [ 6 ] = 0 ; V_43 [ 7 ] = 0 ;
}
for ( V_25 = ( V_41 -> V_32 - V_41 -> V_26 ) & 7 ; V_25 > 0 ; V_25 -- , V_43 ++ )
V_43 [ 0 ] = 0 ;
#else
memset ( V_43 , 0 , sizeof( T_2 ) * ( V_42 + 1 ) ) ;
memcpy ( V_43 , V_41 -> V_27 , sizeof( V_41 -> V_27 [ 0 ] ) * V_41 -> V_26 ) ;
V_41 -> V_27 = V_24 ;
V_41 -> V_32 = V_42 ;
#endif
}
return ( V_41 ) ;
}
T_1 * F_18 ( const T_1 * V_24 )
{
T_1 * V_51 ;
if ( V_24 == NULL ) return NULL ;
F_10 ( V_24 ) ;
V_51 = F_15 () ;
if ( V_51 == NULL ) return ( NULL ) ;
return ( ( T_1 * ) F_19 ( V_51 , V_24 ) ) ;
}
T_1 * F_19 ( T_1 * V_24 , const T_1 * V_41 )
{
int V_25 ;
T_2 * V_43 ;
const T_2 * V_44 ;
F_10 ( V_41 ) ;
if ( V_24 == V_41 ) return ( V_24 ) ;
if ( F_20 ( V_24 , V_41 -> V_26 ) == NULL ) return ( NULL ) ;
#if 1
V_43 = V_24 -> V_27 ;
V_44 = V_41 -> V_27 ;
for ( V_25 = V_41 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_43 += 4 , V_44 += 4 )
{
T_2 V_47 , V_48 , V_49 , V_50 ;
V_47 = V_44 [ 0 ] ; V_48 = V_44 [ 1 ] ; V_49 = V_44 [ 2 ] ; V_50 = V_44 [ 3 ] ;
V_43 [ 0 ] = V_47 ; V_43 [ 1 ] = V_48 ; V_43 [ 2 ] = V_49 ; V_43 [ 3 ] = V_50 ;
}
switch ( V_41 -> V_26 & 3 )
{
case 3 : V_43 [ 2 ] = V_44 [ 2 ] ;
case 2 : V_43 [ 1 ] = V_44 [ 1 ] ;
case 1 : V_43 [ 0 ] = V_44 [ 0 ] ;
case 0 : ;
}
#else
memcpy ( V_24 -> V_27 , V_41 -> V_27 , sizeof( V_41 -> V_27 [ 0 ] ) * V_41 -> V_26 ) ;
#endif
V_24 -> V_26 = V_41 -> V_26 ;
if ( ( V_24 -> V_26 == 0 ) && ( V_24 -> V_27 != NULL ) )
V_24 -> V_27 [ 0 ] = 0 ;
V_24 -> V_40 = V_41 -> V_40 ;
return ( V_24 ) ;
}
void F_21 ( T_1 * V_24 )
{
if ( V_24 -> V_27 != NULL )
memset ( V_24 -> V_27 , 0 , V_24 -> V_32 * sizeof( V_24 -> V_27 [ 0 ] ) ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_40 = 0 ;
}
T_2 F_22 ( T_1 * V_24 )
{
int V_25 , V_52 ;
T_2 V_37 = 0 ;
V_52 = F_23 ( V_24 ) ;
if ( V_52 > sizeof( T_2 ) )
return ( V_53 ) ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
#ifndef F_8
V_37 <<= V_54 ;
V_37 <<= V_54 ;
#else
V_37 = 0 ;
#endif
V_37 |= V_24 -> V_27 [ V_25 ] ;
}
return ( V_37 ) ;
}
int F_24 ( T_1 * V_24 , T_2 V_55 )
{
int V_25 , V_52 ;
if ( F_25 ( V_24 , sizeof( T_2 ) * 8 ) == NULL ) return ( 0 ) ;
V_52 = sizeof( T_2 ) / V_56 ;
V_24 -> V_40 = 0 ;
V_24 -> V_26 = 0 ;
V_24 -> V_27 [ 0 ] = ( T_2 ) V_55 & V_53 ;
if ( V_24 -> V_27 [ 0 ] != 0 ) V_24 -> V_26 = 1 ;
for ( V_25 = 1 ; V_25 < V_52 ; V_25 ++ )
{
#ifndef F_8
V_55 >>= V_54 ;
V_55 >>= V_54 ;
#else
V_55 = 0 ;
#endif
V_24 -> V_27 [ V_25 ] = ( T_2 ) V_55 & V_53 ;
if ( V_24 -> V_27 [ V_25 ] != 0 ) V_24 -> V_26 = V_25 + 1 ;
}
return ( 1 ) ;
}
T_1 * F_26 ( const unsigned char * V_57 , int V_58 , T_1 * V_37 )
{
unsigned int V_25 , V_59 ;
unsigned int V_52 ;
T_2 V_19 ;
if ( V_37 == NULL ) V_37 = F_15 () ;
if ( V_37 == NULL ) return ( NULL ) ;
V_19 = 0 ;
V_52 = V_58 ;
if ( V_52 == 0 )
{
V_37 -> V_26 = 0 ;
return ( V_37 ) ;
}
if ( F_25 ( V_37 , ( int ) ( V_52 + 2 ) * 8 ) == NULL )
return ( NULL ) ;
V_25 = ( ( V_52 - 1 ) / V_56 ) + 1 ;
V_59 = ( ( V_52 - 1 ) % ( V_56 ) ) ;
V_37 -> V_26 = V_25 ;
while ( V_52 -- > 0 )
{
V_19 = ( V_19 << 8L ) | * ( V_57 ++ ) ;
if ( V_59 -- == 0 )
{
V_37 -> V_27 [ -- V_25 ] = V_19 ;
V_19 = 0 ;
V_59 = V_56 - 1 ;
}
}
F_27 ( V_37 ) ;
return ( V_37 ) ;
}
int F_28 ( const T_1 * V_24 , unsigned char * V_60 )
{
int V_52 , V_25 ;
T_2 V_19 ;
V_52 = V_25 = F_23 ( V_24 ) ;
while ( V_25 -- > 0 )
{
V_19 = V_24 -> V_27 [ V_25 / V_56 ] ;
* ( V_60 ++ ) = ( unsigned char ) ( V_19 >> ( 8 * ( V_25 % V_56 ) ) ) & 0xff ;
}
return ( V_52 ) ;
}
int F_29 ( const T_1 * V_24 , const T_1 * V_41 )
{
int V_25 ;
T_2 V_61 , V_62 , * V_63 , * V_64 ;
F_10 ( V_24 ) ;
F_10 ( V_41 ) ;
V_25 = V_24 -> V_26 - V_41 -> V_26 ;
if ( V_25 != 0 ) return ( V_25 ) ;
V_63 = V_24 -> V_27 ;
V_64 = V_41 -> V_27 ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_61 = V_63 [ V_25 ] ;
V_62 = V_64 [ V_25 ] ;
if ( V_61 != V_62 )
return ( V_61 > V_62 ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_30 ( const T_1 * V_24 , const T_1 * V_41 )
{
int V_25 ;
int V_65 , V_66 ;
T_2 V_61 , V_62 ;
if ( ( V_24 == NULL ) || ( V_41 == NULL ) )
{
if ( V_24 != NULL )
return ( - 1 ) ;
else if ( V_41 != NULL )
return ( 1 ) ;
else
return ( 0 ) ;
}
F_10 ( V_24 ) ;
F_10 ( V_41 ) ;
if ( V_24 -> V_40 != V_41 -> V_40 )
{
if ( V_24 -> V_40 )
return ( - 1 ) ;
else return ( 1 ) ;
}
if ( V_24 -> V_40 == 0 )
{ V_65 = 1 ; V_66 = - 1 ; }
else { V_65 = - 1 ; V_66 = 1 ; }
if ( V_24 -> V_26 > V_41 -> V_26 ) return ( V_65 ) ;
if ( V_24 -> V_26 < V_41 -> V_26 ) return ( V_66 ) ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_61 = V_24 -> V_27 [ V_25 ] ;
V_62 = V_41 -> V_27 [ V_25 ] ;
if ( V_61 > V_62 ) return ( V_65 ) ;
if ( V_61 < V_62 ) return ( V_66 ) ;
}
return ( 0 ) ;
}
int F_31 ( T_1 * V_24 , int V_52 )
{
int V_25 , V_67 , V_68 ;
V_25 = V_52 / V_28 ;
V_67 = V_52 % V_28 ;
if ( V_24 -> V_26 <= V_25 )
{
if ( F_20 ( V_24 , V_25 + 1 ) == NULL ) return ( 0 ) ;
for( V_68 = V_24 -> V_26 ; V_68 < V_25 + 1 ; V_68 ++ )
V_24 -> V_27 [ V_68 ] = 0 ;
V_24 -> V_26 = V_25 + 1 ;
}
V_24 -> V_27 [ V_25 ] |= ( ( ( T_2 ) 1 ) << V_67 ) ;
return ( 1 ) ;
}
int F_32 ( T_1 * V_24 , int V_52 )
{
int V_25 , V_67 ;
V_25 = V_52 / V_28 ;
V_67 = V_52 % V_28 ;
if ( V_24 -> V_26 <= V_25 ) return ( 0 ) ;
V_24 -> V_27 [ V_25 ] &= ( ~ ( ( ( T_2 ) 1 ) << V_67 ) ) ;
F_27 ( V_24 ) ;
return ( 1 ) ;
}
int F_33 ( const T_1 * V_24 , int V_52 )
{
int V_25 , V_67 ;
if ( V_52 < 0 ) return ( 0 ) ;
V_25 = V_52 / V_28 ;
V_67 = V_52 % V_28 ;
if ( V_24 -> V_26 <= V_25 ) return ( 0 ) ;
return ( ( V_24 -> V_27 [ V_25 ] & ( ( ( T_2 ) 1 ) << V_67 ) ) ? 1 : 0 ) ;
}
int F_34 ( T_1 * V_24 , int V_52 )
{
int V_41 , V_55 ;
V_55 = V_52 / V_28 ;
V_41 = V_52 % V_28 ;
if ( V_55 >= V_24 -> V_26 ) return ( 0 ) ;
if ( V_41 == 0 )
V_24 -> V_26 = V_55 ;
else
{
V_24 -> V_26 = V_55 + 1 ;
V_24 -> V_27 [ V_55 ] &= ~ ( V_53 << V_41 ) ;
}
F_27 ( V_24 ) ;
return ( 1 ) ;
}
int F_35 ( T_2 * V_24 , T_2 * V_41 , int V_52 )
{
int V_25 ;
T_2 V_69 , V_70 ;
V_69 = V_24 [ V_52 - 1 ] ;
V_70 = V_41 [ V_52 - 1 ] ;
if ( V_69 != V_70 ) return ( ( V_69 > V_70 ) ? 1 : - 1 ) ;
for ( V_25 = V_52 - 2 ; V_25 >= 0 ; V_25 -- )
{
V_69 = V_24 [ V_25 ] ;
V_70 = V_41 [ V_25 ] ;
if ( V_69 != V_70 ) return ( ( V_69 > V_70 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
