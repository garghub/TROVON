void * memset ( void * V_1 , int V_2 , T_1 V_3 )
{
T_2 * V_4 ;
int V_5 ;
T_2 V_6 , V_7 ;
T_3 * V_8 = V_1 ;
#if ! F_1 ()
int V_9 ;
#else
int V_10 ;
#endif
#define F_2 20
#if F_2 < 3
#error "BYTE_CUTOFF is too small"
#endif
if ( V_3 < F_2 ) {
if ( V_3 != 0 ) {
do {
* V_8 = V_2 ;
V_8 ++ ;
} while ( -- V_3 != 0 );
}
return V_1 ;
}
#if ! F_1 ()
F_3 ( V_8 ) ;
F_3 ( & V_8 [ V_3 - 1 ] ) ;
#endif
while ( ( ( V_11 ) V_8 & 3 ) != 0 ) {
* V_8 ++ = V_2 ;
-- V_3 ;
}
while ( V_3 & 3 )
V_8 [ -- V_3 ] = V_2 ;
V_4 = ( T_2 * ) V_8 ;
V_5 = V_3 >> 2 ;
V_6 = F_4 ( V_2 , V_2 ) ;
V_7 = F_5 ( V_6 , V_6 ) ;
#define F_6 (CHIP_L2_LINE_SIZE() / 4)
#if ! F_1 ()
V_9 = F_6 ;
if ( V_5 > F_6 * 2 ) {
int V_12 ;
#define F_7 5
V_9 = V_5 & - F_6 ;
if ( V_9 > F_7 * F_6 )
V_9 = F_7 * F_6 ;
for ( V_12 = F_6 ;
V_12 < V_9 ; V_12 += F_6 )
F_3 ( & V_4 [ V_12 ] ) ;
}
if ( V_5 > V_9 ) {
while ( 1 ) {
int V_13 ;
F_3 ( & V_4 [ V_9 ] ) ;
#if F_6 % 4 != 0
#error "Unhandled CACHE_LINE_SIZE_IN_WORDS"
#endif
V_5 -= F_6 ;
for ( V_13 = F_6 / 4 ; V_13 > 0 ; V_13 -- ) {
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
}
if ( V_5 <= V_9 ) {
if ( V_5 < F_6 )
break;
V_9 = F_6 - 1 ;
}
}
}
#else
V_10 =
( - ( ( V_11 ) V_4 >> 2 ) ) & ( F_6 - 1 ) ;
if ( V_10 <= V_5 - F_6 ) {
int V_14 ;
V_5 -= V_10 ;
for (; V_10 != 0 ; V_10 -- ) {
* V_4 = V_7 ;
V_4 ++ ;
}
V_14 = ( unsigned ) V_5 / F_6 ;
do {
int V_15 = ( ( V_14 < F_8 () )
? V_14
: F_8 () ) ;
T_2 * V_16 = V_4 ;
int V_12 = V_15 ;
int V_13 ;
V_14 -= V_15 ;
do {
F_9 ( V_16 ) ;
V_16 += F_6 ;
} while ( -- V_12 );
for ( V_13 = V_15 * ( F_6 / 4 ) ;
V_13 != 0 ; V_13 -- ) {
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
}
} while ( V_14 != 0 );
V_5 &= F_6 - 1 ;
}
#endif
if ( V_5 != 0 ) {
do {
* V_4 = V_7 ;
V_4 ++ ;
} while ( -- V_5 != 0 );
}
return V_1 ;
}
