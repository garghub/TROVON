static void F_1 ( T_1 V_1 [ 8 ] )
{
F_2 ( V_1 , 16 , 4 ) ;
F_2 ( V_1 , 8 , 2 ) ;
F_2 ( V_1 , 4 , 1 ) ;
F_2 ( V_1 , 2 , 4 ) ;
F_2 ( V_1 , 1 , 2 ) ;
}
static inline void F_3 ( void * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_1 [ 8 ] )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ , V_2 += V_3 )
F_4 ( V_1 [ V_6 [ V_5 ] ] , V_2 ) ;
}
static inline void F_5 ( void * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_1 [ 8 ] , T_1 V_7 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ , V_2 += V_3 )
F_4 ( F_6 ( V_1 [ V_6 [ V_5 ] ] ,
F_7 ( V_2 ) , V_7 ) ,
V_2 ) ;
}
void F_8 ( void * V_2 , const void * V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 ,
T_1 V_12 , T_1 V_13 , T_1 V_14 ,
T_1 V_15 , T_1 V_4 )
{
union {
T_2 V_16 [ 32 ] ;
T_1 V_17 [ 8 ] ;
} V_1 ;
T_1 V_18 , V_19 , V_20 , V_21 ;
const T_2 * V_22 ;
void * V_23 ;
V_2 += V_10 * V_13 + ( V_9 & ~ 31 ) ;
V_18 = V_9 % 32 ;
V_19 = 0xffffffffU >> V_18 ;
V_20 = ~ ( 0xffffffffU >> ( ( V_18 + V_11 ) % 32 ) ) ;
while ( V_12 -- ) {
V_22 = V_8 ;
V_23 = V_2 ;
V_21 = V_11 ;
if ( V_18 + V_11 <= 32 ) {
V_19 &= V_20 ;
memset ( V_1 . V_16 , 0 , sizeof( V_1 ) ) ;
memcpy ( V_1 . V_16 + V_18 , V_22 , V_11 ) ;
V_22 += V_11 ;
F_1 ( V_1 . V_17 ) ;
F_5 ( V_23 , V_14 , V_4 , V_1 . V_17 ,
V_19 ) ;
V_23 += 4 ;
} else {
V_21 = V_11 ;
if ( V_18 ) {
V_21 = 32 - V_18 ;
memset ( V_1 . V_16 , 0 , V_18 ) ;
memcpy ( V_1 . V_16 + V_18 , V_22 , V_21 ) ;
V_22 += V_21 ;
F_1 ( V_1 . V_17 ) ;
F_5 ( V_23 , V_14 , V_4 ,
V_1 . V_17 , V_19 ) ;
V_23 += 4 ;
V_21 = V_11 - V_21 ;
}
while ( V_21 >= 32 ) {
memcpy ( V_1 . V_16 , V_22 , 32 ) ;
V_22 += 32 ;
F_1 ( V_1 . V_17 ) ;
F_3 ( V_23 , V_14 , V_4 , V_1 . V_17 ) ;
V_23 += 4 ;
V_21 -= 32 ;
}
V_21 %= 32 ;
if ( V_21 > 0 ) {
memcpy ( V_1 . V_16 , V_22 , V_21 ) ;
memset ( V_1 . V_16 + V_21 , 0 , 32 - V_21 ) ;
F_1 ( V_1 . V_17 ) ;
F_5 ( V_23 , V_14 , V_4 ,
V_1 . V_17 , V_20 ) ;
}
}
V_8 += V_15 ;
V_2 += V_13 ;
}
}
