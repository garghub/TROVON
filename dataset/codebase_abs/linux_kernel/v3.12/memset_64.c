void * memset ( void * V_1 , int V_2 , T_1 V_3 )
{
T_2 * V_4 ;
int V_5 , V_6 ;
T_2 V_7 ;
T_3 * V_8 = V_1 ;
#define F_1 20
#if F_1 < 7
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
while ( ( ( V_9 ) V_8 & 7 ) != 0 ) {
* V_8 ++ = V_2 ;
-- V_3 ;
}
while ( V_3 & 7 )
V_8 [ -- V_3 ] = V_2 ;
V_4 = ( T_2 * ) V_8 ;
V_5 = V_3 >> 3 ;
V_7 = F_2 ( V_2 ) ;
#define F_3 (CHIP_L2_LINE_SIZE() / 8)
V_6 = ( - ( ( V_9 ) V_4 >> 3 ) ) &
( F_3 - 1 ) ;
if ( V_6 <= V_5 - F_3 ) {
int V_10 ;
V_5 -= V_6 ;
for (; V_6 != 0 ; V_6 -- ) {
* V_4 = V_7 ;
V_4 ++ ;
}
V_10 = ( unsigned ) V_5 / F_3 ;
do {
int V_11 = ( ( V_10 < F_4 () )
? V_10
: F_4 () ) ;
T_2 * V_12 = V_4 ;
int V_13 = V_11 ;
int V_14 ;
V_10 -= V_11 ;
do {
F_5 ( V_12 ) ;
V_12 += F_3 ;
} while ( -- V_13 );
for ( V_14 = V_11 * ( F_3 / 4 ) ;
V_14 != 0 ; V_14 -- ) {
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
* V_4 ++ = V_7 ;
}
} while ( V_10 != 0 );
V_5 &= F_3 - 1 ;
}
if ( V_5 != 0 ) {
do {
* V_4 = V_7 ;
V_4 ++ ;
} while ( -- V_5 != 0 );
}
return V_1 ;
}
