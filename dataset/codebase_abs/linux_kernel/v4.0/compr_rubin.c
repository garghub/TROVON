static inline void F_1 ( struct V_1 * V_2 , char * V_3 ,
unsigned V_4 , unsigned V_5 ,
unsigned V_6 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_6 ;
}
static inline int F_2 ( struct V_1 * V_2 , int V_7 , int V_8 )
{
if ( V_2 -> V_5 >= V_2 -> V_4 - ( V_8 ? 0 : V_2 -> V_6 ) )
return - V_9 ;
if ( V_7 )
V_2 -> V_3 [ V_2 -> V_5 >> 3 ] |= ( 1 << ( 7 - ( V_2 -> V_5 & 7 ) ) ) ;
else
V_2 -> V_3 [ V_2 -> V_5 >> 3 ] &= ~ ( 1 << ( 7 - ( V_2 -> V_5 & 7 ) ) ) ;
V_2 -> V_5 ++ ;
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_5 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = ( V_2 -> V_3 [ V_2 -> V_5 >> 3 ] >> ( 7 - ( V_2 -> V_5 & 7 ) ) ) & 1 ;
V_2 -> V_5 ++ ;
return V_7 ;
}
static void F_5 ( struct V_10 * V_11 , int div , int * V_12 )
{
int V_13 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = ( long ) ( 2 * V_16 ) ;
V_11 -> V_17 = ( long ) 0 ;
V_11 -> V_18 = div ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ )
V_11 -> V_12 [ V_13 ] = V_12 [ V_13 ] ;
}
static int F_6 ( struct V_10 * V_11 , long V_19 , long V_20 , int V_21 )
{
long V_22 , V_23 ;
int V_24 ;
while ( ( V_11 -> V_14 >= V_16 ) ||
( ( V_11 -> V_15 + V_11 -> V_14 ) <= V_16 ) ) {
V_11 -> V_17 ++ ;
V_24 = F_2 ( & V_11 -> V_2 , ( V_11 -> V_14 & V_16 ) ? 1 : 0 , 0 ) ;
if ( V_24 )
return V_24 ;
V_11 -> V_14 &= V_25 ;
V_11 -> V_14 <<= 1 ;
V_11 -> V_15 <<= 1 ;
}
V_22 = V_19 * V_11 -> V_15 / ( V_19 + V_20 ) ;
if ( V_22 <= 0 )
V_22 = 1 ;
if ( V_22 >= V_11 -> V_15 )
V_22 = V_11 -> V_15 - 1 ;
V_23 = V_11 -> V_15 - V_22 ;
if ( V_21 == 0 )
V_11 -> V_15 = V_22 ;
else {
V_11 -> V_15 = V_23 ;
V_11 -> V_14 += V_22 ;
}
return 0 ;
}
static void F_7 ( struct V_10 * V_11 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
F_2 ( & V_11 -> V_2 , ( V_16 & V_11 -> V_14 ) ? 1 : 0 , 1 ) ;
V_11 -> V_14 &= V_25 ;
V_11 -> V_14 <<= 1 ;
}
}
static void F_8 ( struct V_10 * V_11 , int div , int * V_12 )
{
F_5 ( V_11 , div , V_12 ) ;
V_11 -> V_28 = 0 ;
for ( V_11 -> V_17 = 0 ; V_11 -> V_17 ++ < V_27 ;
V_11 -> V_28 = V_11 -> V_28 * 2 + ( long ) ( F_4 ( & V_11 -> V_2 ) ) )
;
}
static void F_9 ( struct V_10 * V_11 , unsigned long V_15 ,
unsigned long V_14 )
{
register unsigned long V_29 = V_25 ;
unsigned long V_28 ;
int V_13 , V_12 = 0 ;
do {
V_12 ++ ;
V_14 &= V_29 ;
V_14 <<= 1 ;
V_15 <<= 1 ;
} while ( ( V_14 >= V_16 ) || ( ( V_15 + V_14 ) <= V_16 ) );
V_11 -> V_15 = V_15 ;
V_11 -> V_14 = V_14 ;
V_11 -> V_17 += V_12 ;
V_28 = V_11 -> V_28 ;
do {
V_13 = F_4 ( & V_11 -> V_2 ) ;
V_28 &= V_29 ;
V_28 <<= 1 ;
V_28 += V_13 ;
} while ( -- V_12 );
V_11 -> V_28 = V_28 ;
}
static int F_10 ( struct V_10 * V_11 , long V_19 , long V_20 )
{
unsigned long V_15 = V_11 -> V_15 , V_14 = V_11 -> V_14 ;
long V_22 , V_30 ;
int V_21 ;
if ( V_14 >= V_16 || ( ( V_15 + V_14 ) <= V_16 ) )
F_9 ( V_11 , V_15 , V_14 ) ;
V_22 = V_19 * V_11 -> V_15 / ( V_19 + V_20 ) ;
if ( V_22 <= 0 )
V_22 = 1 ;
if ( V_22 >= V_11 -> V_15 )
V_22 = V_11 -> V_15 - 1 ;
V_30 = V_11 -> V_14 + V_22 ;
V_21 = V_11 -> V_28 >= V_30 ;
if ( V_11 -> V_28 >= V_30 ) {
V_11 -> V_14 += V_22 ;
V_22 = V_11 -> V_15 - V_22 ;
}
V_11 -> V_15 = V_22 ;
return V_21 ;
}
static int F_11 ( struct V_10 * V_11 , unsigned char V_31 )
{
int V_26 , V_24 ;
struct V_10 V_32 ;
V_32 = * V_11 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
V_24 = F_6 ( V_11 , V_11 -> V_18 - V_11 -> V_12 [ V_26 ] ,
V_11 -> V_12 [ V_26 ] , V_31 & 1 ) ;
if ( V_24 ) {
* V_11 = V_32 ;
return V_24 ;
}
V_31 >>= 1 ;
}
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
int V_26 , V_33 = 0 , V_18 = V_11 -> V_18 ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ )
V_33 |= F_10 ( V_11 , V_18 - V_11 -> V_12 [ V_26 ] ,
V_11 -> V_12 [ V_26 ] ) << V_26 ;
return V_33 ;
}
static int F_13 ( int V_18 , int * V_12 , unsigned char * V_34 ,
unsigned char * V_35 , T_1 * V_36 ,
T_1 * V_37 )
{
int V_38 = 0 ;
int V_39 = 0 ;
struct V_10 V_11 ;
F_1 ( & V_11 . V_2 , V_35 , * V_37 * 8 , 0 , 32 ) ;
F_5 ( & V_11 , V_18 , V_12 ) ;
while ( V_39 < ( * V_36 ) && ! F_11 ( & V_11 , V_34 [ V_39 ] ) )
V_39 ++ ;
F_7 ( & V_11 ) ;
if ( V_38 > V_39 ) {
return - 1 ;
}
V_38 = ( F_3 ( & V_11 . V_2 ) + 7 ) / 8 ;
if ( V_38 >= V_39 )
return - 1 ;
* V_36 = V_39 ;
* V_37 = V_38 ;
return 0 ;
}
static int F_14 ( unsigned char * V_34 ,
unsigned char * V_35 ,
T_1 * V_36 , T_1 * V_37 )
{
int V_12 [ 8 ] ;
unsigned char V_40 [ 256 ] ;
int V_26 ;
int V_24 ;
T_1 V_41 , V_42 ;
V_41 = * V_36 ;
V_42 = * V_37 - 8 ;
if ( * V_37 <= 12 )
return - 1 ;
memset ( V_40 , 0 , 256 ) ;
for ( V_26 = 0 ; V_26 < V_41 ; V_26 ++ )
V_40 [ V_34 [ V_26 ] ] ++ ;
memset ( V_12 , 0 , sizeof( int ) * 8 ) ;
for ( V_26 = 0 ; V_26 < 256 ; V_26 ++ ) {
if ( V_26 & 128 )
V_12 [ 7 ] += V_40 [ V_26 ] ;
if ( V_26 & 64 )
V_12 [ 6 ] += V_40 [ V_26 ] ;
if ( V_26 & 32 )
V_12 [ 5 ] += V_40 [ V_26 ] ;
if ( V_26 & 16 )
V_12 [ 4 ] += V_40 [ V_26 ] ;
if ( V_26 & 8 )
V_12 [ 3 ] += V_40 [ V_26 ] ;
if ( V_26 & 4 )
V_12 [ 2 ] += V_40 [ V_26 ] ;
if ( V_26 & 2 )
V_12 [ 1 ] += V_40 [ V_26 ] ;
if ( V_26 & 1 )
V_12 [ 0 ] += V_40 [ V_26 ] ;
}
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ ) {
V_12 [ V_26 ] = ( V_12 [ V_26 ] * 256 ) / V_41 ;
if ( ! V_12 [ V_26 ] ) V_12 [ V_26 ] = 1 ;
if ( V_12 [ V_26 ] > 255 ) V_12 [ V_26 ] = 255 ;
V_35 [ V_26 ] = V_12 [ V_26 ] ;
}
V_24 = F_13 ( 256 , V_12 , V_34 , V_35 + 8 , & V_41 ,
& V_42 ) ;
if ( V_24 )
return V_24 ;
V_42 += 8 ;
if ( V_41 <= V_42 ) {
return - 1 ;
}
* V_36 = V_41 ;
* V_37 = V_42 ;
return 0 ;
}
static void F_15 ( int V_18 , int * V_12 ,
unsigned char * V_43 ,
unsigned char * V_44 , T_1 V_45 ,
T_1 V_46 )
{
int V_38 = 0 ;
struct V_10 V_11 ;
F_1 ( & V_11 . V_2 , V_43 , V_45 , 0 , 0 ) ;
F_8 ( & V_11 , V_18 , V_12 ) ;
while ( V_38 < V_46 )
V_44 [ V_38 ++ ] = F_12 ( & V_11 ) ;
}
static int F_16 ( unsigned char * V_34 ,
unsigned char * V_35 ,
T_1 V_36 , T_1 V_37 )
{
F_15 ( V_47 , V_48 , V_34 ,
V_35 , V_36 , V_37 ) ;
return 0 ;
}
static int F_17 ( unsigned char * V_34 ,
unsigned char * V_35 ,
T_1 V_36 , T_1 V_37 )
{
int V_12 [ 8 ] ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ )
V_12 [ V_13 ] = V_34 [ V_13 ] ;
F_15 ( 256 , V_12 , V_34 + 8 , V_35 , V_36 - 8 ,
V_37 ) ;
return 0 ;
}
int F_18 ( void )
{
return F_19 ( & V_49 ) ;
}
void F_20 ( void )
{
F_21 ( & V_49 ) ;
}
int F_22 ( void )
{
return F_19 ( & V_50 ) ;
}
void F_23 ( void )
{
F_21 ( & V_50 ) ;
}
