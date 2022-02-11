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
const T_1 * F_3 ( void )
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
assert ( V_19 != 0 ) ;
V_25 = ( V_24 -> V_26 - 1 ) * V_28 ;
return ( V_25 + F_6 ( V_19 ) ) ;
}
void F_11 ( T_1 * V_24 )
{
int V_25 ;
if ( V_24 == NULL ) return;
if ( V_24 -> V_27 != NULL )
{
F_12 ( V_24 -> V_27 , V_24 -> V_29 * sizeof( V_24 -> V_27 [ 0 ] ) ) ;
if ( ! ( F_13 ( V_24 , V_30 ) ) )
F_14 ( V_24 -> V_27 ) ;
}
V_25 = F_13 ( V_24 , V_31 ) ;
F_12 ( V_24 , sizeof( T_1 ) ) ;
if ( V_25 )
F_14 ( V_24 ) ;
}
void F_15 ( T_1 * V_24 )
{
if ( V_24 == NULL ) return;
if ( ( V_24 -> V_27 != NULL ) && ! ( F_13 ( V_24 , V_30 ) ) )
F_14 ( V_24 -> V_27 ) ;
V_24 -> V_32 |= V_33 ;
if ( V_24 -> V_32 & V_31 )
F_14 ( V_24 ) ;
}
void F_16 ( T_1 * V_24 )
{
memset ( V_24 , 0 , sizeof( T_1 ) ) ;
}
T_1 * F_17 ( void )
{
T_1 * V_34 ;
if ( ( V_34 = ( T_1 * ) F_18 ( sizeof( T_1 ) ) ) == NULL )
{
F_19 ( V_35 , V_36 ) ;
return ( NULL ) ;
}
V_34 -> V_32 = V_31 ;
V_34 -> V_26 = 0 ;
V_34 -> V_37 = 0 ;
V_34 -> V_29 = 0 ;
V_34 -> V_27 = NULL ;
return ( V_34 ) ;
}
static T_2 * F_20 ( const T_1 * V_38 , int V_39 )
{
T_2 * V_40 , * V_24 = NULL ;
const T_2 * V_41 ;
int V_25 ;
if ( V_39 > ( V_42 / ( 4 * V_28 ) ) )
{
F_19 ( V_43 , V_44 ) ;
return NULL ;
}
F_10 ( V_38 ) ;
if ( F_13 ( V_38 , V_30 ) )
{
F_19 ( V_43 , V_45 ) ;
return ( NULL ) ;
}
V_24 = V_40 = ( T_2 * ) F_18 ( sizeof( T_2 ) * ( V_39 + 1 ) ) ;
if ( V_40 == NULL )
{
F_19 ( V_43 , V_36 ) ;
return ( NULL ) ;
}
#if 1
V_41 = V_38 -> V_27 ;
if ( V_41 != NULL )
{
for ( V_25 = V_38 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_40 += 4 , V_41 += 4 )
{
T_2 V_46 , V_47 , V_48 , V_49 ;
V_46 = V_41 [ 0 ] ; V_47 = V_41 [ 1 ] ; V_48 = V_41 [ 2 ] ; V_49 = V_41 [ 3 ] ;
V_40 [ 0 ] = V_46 ; V_40 [ 1 ] = V_47 ; V_40 [ 2 ] = V_48 ; V_40 [ 3 ] = V_49 ;
}
switch ( V_38 -> V_26 & 3 )
{
case 3 : V_40 [ 2 ] = V_41 [ 2 ] ;
case 2 : V_40 [ 1 ] = V_41 [ 1 ] ;
case 1 : V_40 [ 0 ] = V_41 [ 0 ] ;
case 0 :
;
}
}
V_40 = & ( V_24 [ V_38 -> V_26 ] ) ;
for ( V_25 = ( V_39 - V_38 -> V_26 ) >> 3 ; V_25 > 0 ; V_25 -- , V_40 += 8 )
{
V_40 [ 0 ] = 0 ; V_40 [ 1 ] = 0 ; V_40 [ 2 ] = 0 ; V_40 [ 3 ] = 0 ;
V_40 [ 4 ] = 0 ; V_40 [ 5 ] = 0 ; V_40 [ 6 ] = 0 ; V_40 [ 7 ] = 0 ;
}
for ( V_25 = ( V_39 - V_38 -> V_26 ) & 7 ; V_25 > 0 ; V_25 -- , V_40 ++ )
V_40 [ 0 ] = 0 ;
#else
memset ( V_40 , 0 , sizeof( T_2 ) * ( V_39 + 1 ) ) ;
memcpy ( V_40 , V_38 -> V_27 , sizeof( V_38 -> V_27 [ 0 ] ) * V_38 -> V_26 ) ;
#endif
return ( V_24 ) ;
}
T_1 * F_21 ( const T_1 * V_38 , int V_39 )
{
T_1 * V_50 = NULL ;
if ( V_39 > V_38 -> V_29 )
{
T_2 * V_24 = F_20 ( V_38 , V_39 ) ;
if ( V_24 )
{
V_50 = F_17 () ;
if ( V_50 )
{
V_50 -> V_26 = V_38 -> V_26 ;
V_50 -> V_29 = V_39 ;
V_50 -> V_37 = V_38 -> V_37 ;
V_50 -> V_27 = V_24 ;
}
else
{
F_14 ( V_24 ) ;
}
}
}
else
{
V_50 = F_22 ( V_38 ) ;
}
return V_50 ;
}
T_1 * F_23 ( T_1 * V_38 , int V_39 )
{
if ( V_39 > V_38 -> V_29 )
{
T_2 * V_24 = F_20 ( V_38 , V_39 ) ;
if ( V_24 )
{
if ( V_38 -> V_27 )
F_14 ( V_38 -> V_27 ) ;
V_38 -> V_27 = V_24 ;
V_38 -> V_29 = V_39 ;
}
else
V_38 = NULL ;
}
return V_38 ;
}
T_1 * F_22 ( const T_1 * V_24 )
{
T_1 * V_50 , * V_51 ;
if ( V_24 == NULL ) return NULL ;
F_10 ( V_24 ) ;
V_51 = F_17 () ;
if ( V_51 == NULL ) return ( NULL ) ;
V_50 = F_24 ( V_51 , V_24 ) ;
if ( V_50 == NULL )
F_15 ( V_51 ) ;
return V_50 ;
}
T_1 * F_24 ( T_1 * V_24 , const T_1 * V_38 )
{
int V_25 ;
T_2 * V_40 ;
const T_2 * V_41 ;
F_10 ( V_38 ) ;
if ( V_24 == V_38 ) return ( V_24 ) ;
if ( F_25 ( V_24 , V_38 -> V_26 ) == NULL ) return ( NULL ) ;
#if 1
V_40 = V_24 -> V_27 ;
V_41 = V_38 -> V_27 ;
for ( V_25 = V_38 -> V_26 >> 2 ; V_25 > 0 ; V_25 -- , V_40 += 4 , V_41 += 4 )
{
T_2 V_46 , V_47 , V_48 , V_49 ;
V_46 = V_41 [ 0 ] ; V_47 = V_41 [ 1 ] ; V_48 = V_41 [ 2 ] ; V_49 = V_41 [ 3 ] ;
V_40 [ 0 ] = V_46 ; V_40 [ 1 ] = V_47 ; V_40 [ 2 ] = V_48 ; V_40 [ 3 ] = V_49 ;
}
switch ( V_38 -> V_26 & 3 )
{
case 3 : V_40 [ 2 ] = V_41 [ 2 ] ;
case 2 : V_40 [ 1 ] = V_41 [ 1 ] ;
case 1 : V_40 [ 0 ] = V_41 [ 0 ] ;
case 0 : ;
}
#else
memcpy ( V_24 -> V_27 , V_38 -> V_27 , sizeof( V_38 -> V_27 [ 0 ] ) * V_38 -> V_26 ) ;
#endif
V_24 -> V_26 = V_38 -> V_26 ;
if ( ( V_24 -> V_26 == 0 ) && ( V_24 -> V_27 != NULL ) )
V_24 -> V_27 [ 0 ] = 0 ;
V_24 -> V_37 = V_38 -> V_37 ;
return ( V_24 ) ;
}
void F_26 ( T_1 * V_24 , T_1 * V_38 )
{
int V_52 , V_53 ;
T_2 * V_54 ;
int V_55 , V_56 , V_57 ;
V_52 = V_24 -> V_32 ;
V_53 = V_38 -> V_32 ;
V_54 = V_24 -> V_27 ;
V_55 = V_24 -> V_26 ;
V_56 = V_24 -> V_29 ;
V_57 = V_24 -> V_37 ;
V_24 -> V_27 = V_38 -> V_27 ;
V_24 -> V_26 = V_38 -> V_26 ;
V_24 -> V_29 = V_38 -> V_29 ;
V_24 -> V_37 = V_38 -> V_37 ;
V_38 -> V_27 = V_54 ;
V_38 -> V_26 = V_55 ;
V_38 -> V_29 = V_56 ;
V_38 -> V_37 = V_57 ;
V_24 -> V_32 = ( V_52 & V_31 ) | ( V_53 & V_30 ) ;
V_38 -> V_32 = ( V_53 & V_31 ) | ( V_52 & V_30 ) ;
}
void F_27 ( T_1 * V_24 )
{
if ( V_24 -> V_27 != NULL )
memset ( V_24 -> V_27 , 0 , V_24 -> V_29 * sizeof( V_24 -> V_27 [ 0 ] ) ) ;
V_24 -> V_26 = 0 ;
V_24 -> V_37 = 0 ;
}
T_2 F_28 ( const T_1 * V_24 )
{
int V_25 , V_58 ;
T_2 V_34 = 0 ;
V_58 = F_29 ( V_24 ) ;
if ( V_58 > sizeof( T_2 ) )
return ( V_59 ) ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
#ifndef F_8
V_34 <<= V_60 ;
V_34 <<= V_60 ;
#else
V_34 = 0 ;
#endif
V_34 |= V_24 -> V_27 [ V_25 ] ;
}
return ( V_34 ) ;
}
int F_30 ( T_1 * V_24 , T_2 V_61 )
{
int V_25 , V_58 ;
if ( F_31 ( V_24 , sizeof( T_2 ) * 8 ) == NULL ) return ( 0 ) ;
V_58 = sizeof( T_2 ) / V_62 ;
V_24 -> V_37 = 0 ;
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
T_1 * F_32 ( const unsigned char * V_63 , int V_64 , T_1 * V_34 )
{
unsigned int V_25 , V_65 ;
unsigned int V_58 ;
T_2 V_19 ;
if ( V_34 == NULL ) V_34 = F_17 () ;
if ( V_34 == NULL ) return ( NULL ) ;
V_19 = 0 ;
V_58 = V_64 ;
if ( V_58 == 0 )
{
V_34 -> V_26 = 0 ;
return ( V_34 ) ;
}
if ( F_31 ( V_34 , ( int ) ( V_58 + 2 ) * 8 ) == NULL )
return ( NULL ) ;
V_25 = ( ( V_58 - 1 ) / V_62 ) + 1 ;
V_65 = ( ( V_58 - 1 ) % ( V_62 ) ) ;
V_34 -> V_26 = V_25 ;
V_34 -> V_37 = 0 ;
while ( V_58 -- > 0 )
{
V_19 = ( V_19 << 8L ) | * ( V_63 ++ ) ;
if ( V_65 -- == 0 )
{
V_34 -> V_27 [ -- V_25 ] = V_19 ;
V_19 = 0 ;
V_65 = V_62 - 1 ;
}
}
F_33 ( V_34 ) ;
return ( V_34 ) ;
}
int F_34 ( const T_1 * V_24 , unsigned char * V_66 )
{
int V_58 , V_25 ;
T_2 V_19 ;
V_58 = V_25 = F_29 ( V_24 ) ;
while ( V_25 -- > 0 )
{
V_19 = V_24 -> V_27 [ V_25 / V_62 ] ;
* ( V_66 ++ ) = ( unsigned char ) ( V_19 >> ( 8 * ( V_25 % V_62 ) ) ) & 0xff ;
}
return ( V_58 ) ;
}
int F_35 ( const T_1 * V_24 , const T_1 * V_38 )
{
int V_25 ;
T_2 V_67 , V_68 , * V_69 , * V_70 ;
F_10 ( V_24 ) ;
F_10 ( V_38 ) ;
V_25 = V_24 -> V_26 - V_38 -> V_26 ;
if ( V_25 != 0 ) return ( V_25 ) ;
V_69 = V_24 -> V_27 ;
V_70 = V_38 -> V_27 ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_67 = V_69 [ V_25 ] ;
V_68 = V_70 [ V_25 ] ;
if ( V_67 != V_68 )
return ( V_67 > V_68 ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_36 ( const T_1 * V_24 , const T_1 * V_38 )
{
int V_25 ;
int V_71 , V_72 ;
T_2 V_67 , V_68 ;
if ( ( V_24 == NULL ) || ( V_38 == NULL ) )
{
if ( V_24 != NULL )
return ( - 1 ) ;
else if ( V_38 != NULL )
return ( 1 ) ;
else
return ( 0 ) ;
}
F_10 ( V_24 ) ;
F_10 ( V_38 ) ;
if ( V_24 -> V_37 != V_38 -> V_37 )
{
if ( V_24 -> V_37 )
return ( - 1 ) ;
else return ( 1 ) ;
}
if ( V_24 -> V_37 == 0 )
{ V_71 = 1 ; V_72 = - 1 ; }
else { V_71 = - 1 ; V_72 = 1 ; }
if ( V_24 -> V_26 > V_38 -> V_26 ) return ( V_71 ) ;
if ( V_24 -> V_26 < V_38 -> V_26 ) return ( V_72 ) ;
for ( V_25 = V_24 -> V_26 - 1 ; V_25 >= 0 ; V_25 -- )
{
V_67 = V_24 -> V_27 [ V_25 ] ;
V_68 = V_38 -> V_27 [ V_25 ] ;
if ( V_67 > V_68 ) return ( V_71 ) ;
if ( V_67 < V_68 ) return ( V_72 ) ;
}
return ( 0 ) ;
}
int F_37 ( T_1 * V_24 , int V_58 )
{
int V_25 , V_73 , V_74 ;
V_25 = V_58 / V_28 ;
V_73 = V_58 % V_28 ;
if ( V_24 -> V_26 <= V_25 )
{
if ( F_25 ( V_24 , V_25 + 1 ) == NULL ) return ( 0 ) ;
for( V_74 = V_24 -> V_26 ; V_74 < V_25 + 1 ; V_74 ++ )
V_24 -> V_27 [ V_74 ] = 0 ;
V_24 -> V_26 = V_25 + 1 ;
}
V_24 -> V_27 [ V_25 ] |= ( ( ( T_2 ) 1 ) << V_73 ) ;
return ( 1 ) ;
}
int F_38 ( T_1 * V_24 , int V_58 )
{
int V_25 , V_73 ;
V_25 = V_58 / V_28 ;
V_73 = V_58 % V_28 ;
if ( V_24 -> V_26 <= V_25 ) return ( 0 ) ;
V_24 -> V_27 [ V_25 ] &= ( ~ ( ( ( T_2 ) 1 ) << V_73 ) ) ;
F_33 ( V_24 ) ;
return ( 1 ) ;
}
int F_39 ( const T_1 * V_24 , int V_58 )
{
int V_25 , V_73 ;
if ( V_58 < 0 ) return ( 0 ) ;
V_25 = V_58 / V_28 ;
V_73 = V_58 % V_28 ;
if ( V_24 -> V_26 <= V_25 ) return ( 0 ) ;
return ( ( V_24 -> V_27 [ V_25 ] & ( ( ( T_2 ) 1 ) << V_73 ) ) ? 1 : 0 ) ;
}
int F_40 ( T_1 * V_24 , int V_58 )
{
int V_38 , V_61 ;
V_61 = V_58 / V_28 ;
V_38 = V_58 % V_28 ;
if ( V_61 >= V_24 -> V_26 ) return ( 0 ) ;
if ( V_38 == 0 )
V_24 -> V_26 = V_61 ;
else
{
V_24 -> V_26 = V_61 + 1 ;
V_24 -> V_27 [ V_61 ] &= ~ ( V_59 << V_38 ) ;
}
F_33 ( V_24 ) ;
return ( 1 ) ;
}
int F_41 ( const T_2 * V_24 , const T_2 * V_38 , int V_58 )
{
int V_25 ;
T_2 V_75 , V_76 ;
V_75 = V_24 [ V_58 - 1 ] ;
V_76 = V_38 [ V_58 - 1 ] ;
if ( V_75 != V_76 ) return ( ( V_75 > V_76 ) ? 1 : - 1 ) ;
for ( V_25 = V_58 - 2 ; V_25 >= 0 ; V_25 -- )
{
V_75 = V_24 [ V_25 ] ;
V_76 = V_38 [ V_25 ] ;
if ( V_75 != V_76 ) return ( ( V_75 > V_76 ) ? 1 : - 1 ) ;
}
return ( 0 ) ;
}
int F_42 ( const T_2 * V_24 , const T_2 * V_38 ,
int V_77 , int V_78 )
{
int V_58 , V_25 ;
V_58 = V_77 - 1 ;
if ( V_78 < 0 )
{
for ( V_25 = V_78 ; V_25 < 0 ; V_25 ++ )
{
if ( V_38 [ V_58 - V_25 ] != 0 )
return - 1 ;
}
}
if ( V_78 > 0 )
{
for ( V_25 = V_78 ; V_25 > 0 ; V_25 -- )
{
if ( V_24 [ V_58 + V_25 ] != 0 )
return 1 ;
}
}
return F_41 ( V_24 , V_38 , V_77 ) ;
}
