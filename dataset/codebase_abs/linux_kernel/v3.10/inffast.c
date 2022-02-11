static inline unsigned short
F_1 ( const unsigned short * V_1 )
{
union V_2 V_3 ;
unsigned char * V_4 = ( unsigned char * ) V_1 ;
V_3 . V_4 [ 0 ] = V_4 [ 0 ] ;
V_3 . V_4 [ 1 ] = V_4 [ 1 ] ;
return V_3 . V_5 ;
}
void F_2 ( T_1 V_6 , unsigned V_7 )
{
struct V_8 * V_9 ;
const unsigned char * V_10 ;
const unsigned char * V_11 ;
unsigned char * V_12 ;
unsigned char * V_13 ;
unsigned char * V_14 ;
#ifdef F_3
unsigned V_15 ;
#endif
unsigned V_16 ;
unsigned V_17 ;
unsigned V_18 ;
unsigned char * V_19 ;
unsigned long V_20 ;
unsigned V_21 ;
T_2 const * V_22 ;
T_2 const * V_23 ;
unsigned V_24 ;
unsigned V_25 ;
T_2 V_26 ;
unsigned V_27 ;
unsigned V_28 ;
unsigned V_29 ;
unsigned char * V_30 ;
V_9 = (struct V_8 * ) V_6 -> V_9 ;
V_10 = V_6 -> V_31 - V_32 ;
V_11 = V_10 + ( V_6 -> V_33 - 5 ) ;
V_12 = V_6 -> V_34 - V_32 ;
V_13 = V_12 - ( V_7 - V_6 -> V_35 ) ;
V_14 = V_12 + ( V_6 -> V_35 - 257 ) ;
#ifdef F_3
V_15 = V_9 -> V_15 ;
#endif
V_16 = V_9 -> V_16 ;
V_17 = V_9 -> V_17 ;
V_18 = V_9 -> V_18 ;
V_19 = V_9 -> V_19 ;
V_20 = V_9 -> V_20 ;
V_21 = V_9 -> V_21 ;
V_22 = V_9 -> V_36 ;
V_23 = V_9 -> V_37 ;
V_24 = ( 1U << V_9 -> V_38 ) - 1 ;
V_25 = ( 1U << V_9 -> V_39 ) - 1 ;
do {
if ( V_21 < 15 ) {
V_20 += ( unsigned long ) ( F_4 ( V_10 ) ) << V_21 ;
V_21 += 8 ;
V_20 += ( unsigned long ) ( F_4 ( V_10 ) ) << V_21 ;
V_21 += 8 ;
}
V_26 = V_22 [ V_20 & V_24 ] ;
V_40:
V_27 = ( unsigned ) ( V_26 . V_21 ) ;
V_20 >>= V_27 ;
V_21 -= V_27 ;
V_27 = ( unsigned ) ( V_26 . V_27 ) ;
if ( V_27 == 0 ) {
F_4 ( V_12 ) = ( unsigned char ) ( V_26 . V_41 ) ;
}
else if ( V_27 & 16 ) {
V_28 = ( unsigned ) ( V_26 . V_41 ) ;
V_27 &= 15 ;
if ( V_27 ) {
if ( V_21 < V_27 ) {
V_20 += ( unsigned long ) ( F_4 ( V_10 ) ) << V_21 ;
V_21 += 8 ;
}
V_28 += ( unsigned ) V_20 & ( ( 1U << V_27 ) - 1 ) ;
V_20 >>= V_27 ;
V_21 -= V_27 ;
}
if ( V_21 < 15 ) {
V_20 += ( unsigned long ) ( F_4 ( V_10 ) ) << V_21 ;
V_21 += 8 ;
V_20 += ( unsigned long ) ( F_4 ( V_10 ) ) << V_21 ;
V_21 += 8 ;
}
V_26 = V_23 [ V_20 & V_25 ] ;
V_42:
V_27 = ( unsigned ) ( V_26 . V_21 ) ;
V_20 >>= V_27 ;
V_21 -= V_27 ;
V_27 = ( unsigned ) ( V_26 . V_27 ) ;
if ( V_27 & 16 ) {
V_29 = ( unsigned ) ( V_26 . V_41 ) ;
V_27 &= 15 ;
if ( V_21 < V_27 ) {
V_20 += ( unsigned long ) ( F_4 ( V_10 ) ) << V_21 ;
V_21 += 8 ;
if ( V_21 < V_27 ) {
V_20 += ( unsigned long ) ( F_4 ( V_10 ) ) << V_21 ;
V_21 += 8 ;
}
}
V_29 += ( unsigned ) V_20 & ( ( 1U << V_27 ) - 1 ) ;
#ifdef F_3
if ( V_29 > V_15 ) {
V_6 -> V_43 = ( char * ) L_1 ;
V_9 -> V_44 = V_45 ;
break;
}
#endif
V_20 >>= V_27 ;
V_21 -= V_27 ;
V_27 = ( unsigned ) ( V_12 - V_13 ) ;
if ( V_29 > V_27 ) {
V_27 = V_29 - V_27 ;
if ( V_27 > V_17 ) {
V_6 -> V_43 = ( char * ) L_1 ;
V_9 -> V_44 = V_45 ;
break;
}
V_30 = V_19 - V_32 ;
if ( V_18 == 0 ) {
V_30 += V_16 - V_27 ;
if ( V_27 < V_28 ) {
V_28 -= V_27 ;
do {
F_4 ( V_12 ) = F_4 ( V_30 ) ;
} while ( -- V_27 );
V_30 = V_12 - V_29 ;
}
}
else if ( V_18 < V_27 ) {
V_30 += V_16 + V_18 - V_27 ;
V_27 -= V_18 ;
if ( V_27 < V_28 ) {
V_28 -= V_27 ;
do {
F_4 ( V_12 ) = F_4 ( V_30 ) ;
} while ( -- V_27 );
V_30 = V_19 - V_32 ;
if ( V_18 < V_28 ) {
V_27 = V_18 ;
V_28 -= V_27 ;
do {
F_4 ( V_12 ) = F_4 ( V_30 ) ;
} while ( -- V_27 );
V_30 = V_12 - V_29 ;
}
}
}
else {
V_30 += V_18 - V_27 ;
if ( V_27 < V_28 ) {
V_28 -= V_27 ;
do {
F_4 ( V_12 ) = F_4 ( V_30 ) ;
} while ( -- V_27 );
V_30 = V_12 - V_29 ;
}
}
while ( V_28 > 2 ) {
F_4 ( V_12 ) = F_4 ( V_30 ) ;
F_4 ( V_12 ) = F_4 ( V_30 ) ;
F_4 ( V_12 ) = F_4 ( V_30 ) ;
V_28 -= 3 ;
}
if ( V_28 ) {
F_4 ( V_12 ) = F_4 ( V_30 ) ;
if ( V_28 > 1 )
F_4 ( V_12 ) = F_4 ( V_30 ) ;
}
}
else {
unsigned short * V_46 ;
unsigned long V_47 ;
V_30 = V_12 - V_29 ;
if ( ! ( ( long ) ( V_12 - 1 + V_32 ) & 1 ) ) {
F_4 ( V_12 ) = F_4 ( V_30 ) ;
V_28 -- ;
}
V_46 = ( unsigned short * ) ( V_12 - V_32 ) ;
if ( V_29 > 2 ) {
unsigned short * V_48 ;
V_48 = ( unsigned short * ) ( V_30 - V_32 ) ;
V_47 = V_28 >> 1 ;
do
#ifdef F_5
F_4 ( V_46 ) = F_4 ( V_48 ) ;
#else
PUP(sout) = UP_UNALIGNED(sfrom ) ;
#endif
while ( -- V_47 ) ;
V_12 = ( unsigned char * ) V_46 + V_32 ;
V_30 = ( unsigned char * ) V_48 + V_32 ;
} else {
unsigned short V_49 ;
V_49 = * ( V_46 - 1 + V_32 ) ;
if ( V_29 == 1 ) {
union V_2 V_3 ;
V_3 . V_5 = V_49 ;
V_3 . V_4 [ 0 ] = V_3 . V_4 [ 1 ] ;
V_49 = V_3 . V_5 ;
}
V_47 = V_28 >> 1 ;
do
F_4 ( V_46 ) = V_49 ;
while ( -- V_47 );
V_12 = ( unsigned char * ) V_46 + V_32 ;
}
if ( V_28 & 1 )
F_4 ( V_12 ) = F_4 ( V_30 ) ;
}
}
else if ((op & 64) == 0
