static inline void F_1 ( T_1 * V_1 , T_1 * V_2 )
{
typedef struct { T_1 _ [ 256 ] ; } T_2;
asm volatile(
" xc 0(256,%[p1]),0(%[p2])\n"
: "+m" (*(addrtype *) p1) : "m" (*(addrtype *) p2),
[p1] "a" (p1), [p2] "a" (p2) : "cc");
}
static void F_2 ( int V_3 , T_3 V_4 , int V_5 ,
int V_6 , void * * V_7 )
{
T_1 * V_8 , * V_9 , * V_10 , * V_11 ;
const T_1 * V_12 ;
const T_1 * V_13 ;
int V_14 ;
V_8 = ( T_1 * ) V_7 [ V_3 - 2 ] ;
V_9 = ( T_1 * ) V_7 [ V_3 - 1 ] ;
V_10 = ( T_1 * ) V_7 [ V_5 ] ;
V_7 [ V_5 ] = ( void * ) V_15 ;
V_7 [ V_3 - 2 ] = V_10 ;
V_11 = ( T_1 * ) V_7 [ V_6 ] ;
V_7 [ V_6 ] = ( void * ) V_15 ;
V_7 [ V_3 - 1 ] = V_11 ;
V_16 . V_17 ( V_3 , V_4 , V_7 ) ;
V_7 [ V_5 ] = V_10 ;
V_7 [ V_6 ] = V_11 ;
V_7 [ V_3 - 2 ] = V_8 ;
V_7 [ V_3 - 1 ] = V_9 ;
V_12 = V_18 [ V_19 [ V_6 - V_5 ] ] ;
V_13 = V_18 [ V_20 [ V_21 [ V_5 ] ^ V_21 [ V_6 ] ] ] ;
while ( V_4 ) {
F_1 ( V_10 , V_8 ) ;
F_1 ( V_11 , V_9 ) ;
for ( V_14 = 0 ; V_14 < 256 ; V_14 ++ )
V_11 [ V_14 ] = V_12 [ V_10 [ V_14 ] ] ^ V_13 [ V_11 [ V_14 ] ] ;
F_1 ( V_10 , V_11 ) ;
V_8 += 256 ;
V_9 += 256 ;
V_10 += 256 ;
V_11 += 256 ;
V_4 -= 256 ;
}
}
static void F_3 ( int V_3 , T_3 V_4 , int V_5 ,
void * * V_7 )
{
T_1 * V_8 , * V_9 , * V_11 ;
const T_1 * V_13 ;
int V_14 ;
V_8 = ( T_1 * ) V_7 [ V_3 - 2 ] ;
V_9 = ( T_1 * ) V_7 [ V_3 - 1 ] ;
V_11 = ( T_1 * ) V_7 [ V_5 ] ;
V_7 [ V_5 ] = ( void * ) V_15 ;
V_7 [ V_3 - 1 ] = V_11 ;
V_16 . V_17 ( V_3 , V_4 , V_7 ) ;
V_7 [ V_5 ] = V_11 ;
V_7 [ V_3 - 1 ] = V_9 ;
V_13 = V_18 [ V_20 [ V_21 [ V_5 ] ] ] ;
while ( V_4 ) {
F_1 ( V_11 , V_9 ) ;
for ( V_14 = 0 ; V_14 < 256 ; V_14 ++ )
V_11 [ V_14 ] = V_13 [ V_11 [ V_14 ] ] ;
F_1 ( V_8 , V_11 ) ;
V_8 += 256 ;
V_9 += 256 ;
V_11 += 256 ;
V_4 -= 256 ;
}
}
