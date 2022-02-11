static inline unsigned short F_1 ( unsigned long V_1 )
{
union {
unsigned long V_2 ;
unsigned int V_3 [ 2 ] ;
unsigned short V_4 [ 4 ] ;
} V_5 , V_6 , V_7 ;
V_5 . V_2 = V_1 ;
V_6 . V_2 = ( unsigned long ) V_5 . V_3 [ 0 ] + ( unsigned long ) V_5 . V_3 [ 1 ] ;
V_7 . V_2 = ( unsigned long ) V_6 . V_4 [ 0 ] + ( unsigned long ) V_6 . V_4 [ 1 ]
+ ( unsigned long ) V_6 . V_4 [ 2 ] ;
return V_7 . V_4 [ 0 ] + V_7 . V_4 [ 1 ] ;
}
static inline unsigned long
F_2 ( const unsigned long T_1 * V_8 , unsigned long * V_9 ,
long V_10 , unsigned long V_11 ,
int * V_12 )
{
unsigned long V_13 = 0 ;
int V_14 = 0 ;
while ( V_10 >= 0 ) {
unsigned long V_15 ;
V_14 |= F_3 ( V_15 , V_8 ) ;
V_11 += V_13 ;
V_8 ++ ;
V_11 += V_15 ;
V_10 -= 8 ;
V_13 = V_11 < V_15 ;
* V_9 = V_15 ;
V_9 ++ ;
}
V_10 += 8 ;
V_11 += V_13 ;
if ( V_10 ) {
unsigned long V_15 , V_16 ;
V_14 |= F_3 ( V_15 , V_8 ) ;
V_16 = * V_9 ;
F_4 ( V_15 , V_10 , V_15 ) ;
V_11 += V_15 ;
F_5 ( V_16 , V_10 , V_16 ) ;
V_13 = V_11 < V_15 ;
* V_9 = V_15 | V_16 ;
V_11 += V_13 ;
}
if ( V_14 ) * V_12 = V_14 ;
return V_11 ;
}
static inline unsigned long
F_6 ( const unsigned long T_1 * V_8 ,
unsigned long * V_9 ,
unsigned long V_17 ,
long V_10 , unsigned long V_11 ,
int * V_12 )
{
unsigned long V_18 ;
unsigned long V_15 , V_13 ;
unsigned long V_19 = 7 + V_10 + ( unsigned long ) V_8 ;
int V_14 = 0 ;
V_14 |= F_7 ( V_18 , V_8 ) ;
V_13 = 0 ;
while ( V_10 >= 0 ) {
unsigned long V_20 ;
V_14 |= F_7 ( V_20 , V_8 + 1 ) ;
F_8 ( V_18 , V_17 , V_15 ) ;
V_10 -= 8 ;
V_8 ++ ;
F_9 ( V_20 , V_17 , V_18 ) ;
V_11 += V_13 ;
V_15 |= V_18 ;
V_18 = V_20 ;
V_11 += V_15 ;
* V_9 = V_15 ;
V_9 ++ ;
V_13 = V_11 < V_15 ;
}
V_10 += 8 ;
V_11 += V_13 ;
if ( V_10 ) {
unsigned long V_16 ;
unsigned long V_20 ;
V_14 |= F_7 ( V_20 , V_19 ) ;
V_16 = * V_9 ;
F_8 ( V_18 , V_17 , V_15 ) ;
F_9 ( V_20 , V_17 , V_18 ) ;
V_15 |= V_18 ;
F_4 ( V_15 , V_10 , V_15 ) ;
V_11 += V_15 ;
F_5 ( V_16 , V_10 , V_16 ) ;
V_13 = V_11 < V_15 ;
* V_9 = V_15 | V_16 ;
V_11 += V_13 ;
}
if ( V_14 ) * V_12 = V_14 ;
return V_11 ;
}
static inline unsigned long
F_10 ( const unsigned long T_1 * V_8 ,
unsigned long * V_9 ,
unsigned long V_21 ,
long V_10 , unsigned long V_11 ,
unsigned long V_22 ,
int * V_12 )
{
unsigned long V_13 = 0 ;
unsigned long V_15 ;
unsigned long V_23 ;
int V_14 = 0 ;
F_4 ( V_22 , V_21 , V_22 ) ;
while ( V_10 >= 0 ) {
V_14 |= F_3 ( V_15 , V_8 ) ;
V_10 -= 8 ;
F_11 ( V_15 , V_21 , V_23 ) ;
V_11 += V_13 ;
F_12 ( V_22 | V_23 , V_9 ) ;
V_8 ++ ;
V_11 += V_15 ;
F_13 ( V_15 , V_21 , V_22 ) ;
V_13 = V_11 < V_15 ;
V_9 ++ ;
}
V_10 += 8 ;
if ( V_10 ) {
V_11 += V_13 ;
V_14 |= F_3 ( V_15 , V_8 ) ;
F_4 ( V_15 , V_10 , V_15 ) ;
V_10 -= 8 ;
V_11 += V_15 ;
F_11 ( V_15 , V_21 , V_23 ) ;
V_10 += V_21 ;
V_13 = V_11 < V_15 ;
V_22 |= V_23 ;
if ( V_10 >= 0 ) {
F_12 ( V_22 , V_9 ) ;
if ( ! V_10 ) goto V_24;
V_9 ++ ;
F_13 ( V_15 , V_21 , V_22 ) ;
}
V_21 = V_10 ;
}
F_14 ( V_23 , V_9 ) ;
F_5 ( V_23 , V_21 , V_23 ) ;
F_12 ( V_22 | V_23 , V_9 ) ;
V_24:
V_11 += V_13 ;
if ( V_14 ) * V_12 = V_14 ;
return V_11 ;
}
static inline unsigned long
F_15 ( const unsigned long T_1 * V_8 ,
unsigned long * V_9 ,
unsigned long V_17 , unsigned long V_21 ,
long V_10 , unsigned long V_11 ,
unsigned long V_22 ,
int * V_12 )
{
unsigned long V_13 = 0 ;
unsigned long V_18 ;
unsigned long V_19 ;
int V_14 = 0 ;
V_14 |= F_7 ( V_18 , V_8 ) ;
V_19 = 7 + V_10 + ( unsigned long ) V_8 ;
F_4 ( V_22 , V_21 , V_22 ) ;
while ( V_10 >= 0 ) {
unsigned long V_20 , V_15 ;
unsigned long V_23 ;
V_14 |= F_7 ( V_20 , V_8 + 1 ) ;
F_8 ( V_18 , V_17 , V_15 ) ;
V_11 += V_13 ;
V_10 -= 8 ;
F_9 ( V_20 , V_17 , V_18 ) ;
V_8 ++ ;
V_15 |= V_18 ;
V_18 = V_20 ;
F_11 ( V_15 , V_21 , V_23 ) ;
V_11 += V_15 ;
F_12 ( V_22 | V_23 , V_9 ) ;
V_13 = V_11 < V_15 ;
F_13 ( V_15 , V_21 , V_22 ) ;
V_9 ++ ;
}
V_10 += V_21 ;
V_11 += V_13 ;
if ( V_10 >= 0 ) {
unsigned long V_20 , V_15 ;
unsigned long V_23 ;
V_14 |= F_7 ( V_20 , V_19 ) ;
F_8 ( V_18 , V_17 , V_15 ) ;
F_9 ( V_20 , V_17 , V_18 ) ;
V_15 |= V_18 ;
V_18 = V_20 ;
F_4 ( V_15 , V_10 - V_21 , V_15 ) ;
V_11 += V_15 ;
F_11 ( V_15 , V_21 , V_23 ) ;
V_13 = V_11 < V_15 ;
F_12 ( V_22 | V_23 , V_9 ) ;
if ( V_10 ) {
F_14 ( V_23 , V_9 + 1 ) ;
F_13 ( V_15 , V_21 , V_22 ) ;
F_5 ( V_23 , V_10 , V_23 ) ;
F_12 ( V_22 | V_23 , V_9 + 1 ) ;
}
V_11 += V_13 ;
} else {
unsigned long V_20 , V_15 ;
unsigned long V_23 ;
V_14 |= F_7 ( V_20 , V_19 ) ;
F_8 ( V_18 , V_17 , V_15 ) ;
F_9 ( V_20 , V_17 , V_18 ) ;
V_15 |= V_18 ;
F_14 ( V_23 , V_9 ) ;
F_4 ( V_15 , V_10 - V_21 , V_15 ) ;
V_11 += V_15 ;
F_5 ( V_23 , V_10 , V_23 ) ;
V_13 = V_11 < V_15 ;
F_11 ( V_15 , V_21 , V_15 ) ;
F_12 ( V_22 | V_15 | V_23 , V_9 ) ;
V_11 += V_13 ;
}
if ( V_14 ) * V_12 = V_14 ;
return V_11 ;
}
T_2
F_16 ( const void T_1 * V_8 , void * V_9 , int V_10 ,
T_2 V_25 , int * V_12 )
{
unsigned long V_11 = ( V_26 V_27 ) V_25 ;
unsigned long V_17 = 7 & ( unsigned long ) V_8 ;
unsigned long V_21 = 7 & ( unsigned long ) V_9 ;
if ( V_10 ) {
if ( ! F_17 ( V_28 , V_8 , V_10 ) ) {
* V_12 = - V_29 ;
memset ( V_9 , 0 , V_10 ) ;
return V_25 ;
}
if ( ! V_21 ) {
if ( ! V_17 )
V_11 = F_2 (
( const unsigned long T_1 * ) V_8 ,
( unsigned long * ) V_9 ,
V_10 - 8 , V_11 , V_12 ) ;
else
V_11 = F_6 (
( const unsigned long T_1 * ) V_8 ,
( unsigned long * ) V_9 ,
V_17 , V_10 - 8 , V_11 , V_12 ) ;
} else {
unsigned long V_22 ;
F_14 ( V_22 , V_9 ) ;
if ( ! V_17 )
V_11 = F_10 (
( const unsigned long T_1 * ) V_8 ,
( unsigned long * ) V_9 ,
V_21 , V_10 - 8 , V_11 ,
V_22 , V_12 ) ;
else
V_11 = F_15 (
( const unsigned long T_1 * ) V_8 ,
( unsigned long * ) V_9 ,
V_17 , V_21 , V_10 - 8 , V_11 ,
V_22 , V_12 ) ;
}
V_11 = F_1 ( V_11 ) ;
}
return ( V_26 T_2 ) V_11 ;
}
T_2
F_18 ( const void * V_8 , void * V_9 , int V_10 , T_2 V_25 )
{
return F_16 ( ( V_26 const void T_1 * ) V_8 ,
V_9 , V_10 , V_25 , NULL ) ;
}
