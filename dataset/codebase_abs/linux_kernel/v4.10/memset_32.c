void * memset ( void * V_1 , int V_2 , T_1 V_3 )
{
T_2 * V_4 ;
int V_5 ;
T_2 V_6 , V_7 ;
T_3 * V_8 = V_1 ;
int V_9 ;
#define F_1 20
#if F_1 < 3
#error "BYTE_CUTOFF is too small"
#endif
if ( V_3 < F_1 ) {
if ( V_3 != 0 ) {
do {
* V_8 = V_2 ;
V_8 ++ ;
} while ( -- V_3 != 0 );
}
return V_1 ;
}
while ( ( ( V_10 ) V_8 & 3 ) != 0 ) {
* V_8 ++ = V_2 ;
-- V_3 ;
}
while ( V_3 & 3 )
V_8 [ -- V_3 ] = V_2 ;
V_4 = ( T_2 * ) V_8 ;
V_5 = V_3 >> 2 ;
V_6 = F_2 ( V_2 , V_2 ) ;
V_7 = F_3 ( V_6 , V_6 ) ;
#define F_4 (CHIP_L2_LINE_SIZE() / 4)
V_9 =
( - ( ( V_10 ) V_4 >> 2 ) ) & ( F_4 - 1 ) ;
if ( V_9 <= V_5 - F_4 ) {
int V_11 ;
V_5 -= V_9 ;
for (; V_9 != 0 ; V_9 -- ) {
* V_4 = V_7 ;
V_4 ++ ;
}
V_11 = ( unsigned ) V_5 / F_4 ;
do {
int V_12 = ( ( V_11 < F_5 () )
? V_11
: F_5 () ) ;
T_2 * V_13 = V_4 ;
int V_14 = V_12 ;
int V_15 ;
V_11 -= V_12 ;
do {
F_6 ( V_13 ) ;
V_13 += F_4 ;
} while ( -- V_14 );
for ( V_15 = V_12 * ( F_4 / 4 ) ;
V_15 != 0 ; V_15 -- ) {
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
}
} while ( V_11 != 0 );
V_5 &= F_4 - 1 ;
}
if ( V_5 != 0 ) {
do {
* V_4 = V_7 ;
V_4 ++ ;
} while ( -- V_5 != 0 );
}
return V_1 ;
}
