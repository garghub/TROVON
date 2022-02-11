static void F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_2 -> V_5 + V_4 ;
V_2 -> V_7 = 8 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_5 - V_2 -> V_3 ;
}
static void F_3 ( struct V_1 * V_2 , int V_8 , T_1 V_9 )
{
if ( V_2 -> V_5 >= V_2 -> V_6 - 4 )
return;
while ( V_8 > 0 ) {
if ( V_8 < 32 )
V_9 &= ( 1 << V_8 ) - 1 ;
if ( V_8 < V_2 -> V_7 ) {
* V_2 -> V_5 = ( * V_2 -> V_5 << V_8 ) | V_9 ;
V_2 -> V_7 -= V_8 ;
break;
}
* V_2 -> V_5 = ( * V_2 -> V_5 << V_2 -> V_7 ) |
( V_9 >> ( V_8 - V_2 -> V_7 ) ) ;
V_8 -= V_2 -> V_7 ;
V_2 -> V_5 ++ ;
V_2 -> V_7 = 8 ;
}
}
static void F_4 ( struct V_1 * V_2 , T_1 V_10 )
{
if ( V_2 -> V_5 < V_2 -> V_6 ) {
* V_2 -> V_5 <<= 1 ;
* V_2 -> V_5 |= V_10 ;
V_2 -> V_7 -- ;
if ( V_2 -> V_7 == 0 ) {
V_2 -> V_5 ++ ;
V_2 -> V_7 = 8 ;
}
}
}
static void F_5 ( struct V_1 * V_2 , T_1 V_11 )
{
if ( V_11 == 0 ) {
F_4 ( V_2 , 1 ) ;
} else {
V_11 ++ ;
F_3 ( V_2 , 2 * F_6 ( V_11 ) - 1 , V_11 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , int V_11 )
{
F_5 ( V_2 , V_11 <= 0 ? - V_11 * 2 : V_11 * 2 - 1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 1 ) ;
if ( V_2 -> V_7 != 8 )
F_3 ( V_2 , V_2 -> V_7 , 0x00 ) ;
}
static int F_9 ( T_2 * V_3 , T_3 V_4 , int V_12 , int V_13 )
{
struct V_1 V_1 , * V_2 ;
V_2 = & V_1 ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_3 ( V_2 , 8 , 0x42 ) ;
F_3 ( V_2 , 1 , 1 ) ;
F_3 ( V_2 , 1 , 1 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_3 ( V_2 , 5 , 0 ) ;
F_3 ( V_2 , 8 , 0x1e ) ;
F_5 ( V_2 , 0 ) ;
F_5 ( V_2 , F_10 ( V_14 ) - 4 ) ;
F_5 ( V_2 , 0 ) ;
F_5 ( V_2 , F_10 ( V_14 ) - 4 ) ;
F_5 ( V_2 , 1 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_5 ( V_2 , V_12 / 16 - 1 ) ;
F_5 ( V_2 , V_13 / 16 - 1 ) ;
F_3 ( V_2 , 1 , 1 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_8 ( V_2 ) ;
return F_2 ( V_2 ) ;
}
static int F_11 ( T_2 * V_3 , T_3 V_4 , int V_15 )
{
struct V_1 V_1 , * V_2 ;
V_2 = & V_1 ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_5 ( V_2 , 0 ) ;
F_5 ( V_2 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_5 ( V_2 , 0 ) ;
F_5 ( V_2 , 0 ) ;
F_5 ( V_2 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_3 ( V_2 , 2 , 0 ) ;
F_7 ( V_2 , V_15 - 26 ) ;
F_7 ( V_2 , V_15 - 26 ) ;
F_7 ( V_2 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_3 ( V_2 , 1 , 0 ) ;
F_8 ( V_2 ) ;
return F_2 ( V_2 ) ;
}
static int F_12 ( T_2 * V_3 , T_3 V_4 ,
unsigned int V_16 ,
unsigned int V_17 ,
int * V_18 , T_2 * V_19 )
{
struct V_1 V_1 , * V_2 ;
int V_20 = V_17 == 0 ;
V_2 = & V_1 ;
F_1 ( V_2 , V_3 , V_4 ) ;
F_5 ( V_2 , 0 ) ;
F_5 ( V_2 , V_20 ? 2 : 5 ) ;
F_5 ( V_2 , 0 ) ;
F_3 ( V_2 , F_10 ( V_14 ) , V_17 ) ;
if ( V_20 )
F_5 ( V_2 , V_16 ) ;
F_3 ( V_2 , F_10 ( V_14 ) , V_17 ) ;
if ( V_20 ) {
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
} else {
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
}
F_7 ( V_2 , 0 ) ;
if ( V_2 -> V_7 != 8 ) {
* V_19 = ( ( V_2 -> V_5 [ 0 ] ) << V_2 -> V_7 ) ;
* V_18 = 8 - V_2 -> V_7 ;
} else {
* V_19 = 0 ;
* V_18 = 0 ;
}
return F_2 ( V_2 ) ;
}
void F_13 ( T_2 * * V_3 , T_3 * V_21 , int V_15 ,
int V_12 , int V_13 )
{
int V_22 ;
memcpy ( * V_3 , V_23 , sizeof( V_23 ) ) ;
* V_3 += 4 ;
* V_21 -= 4 ;
* * V_3 = 0x67 ;
* V_3 += 1 ;
* V_21 -= 1 ;
V_22 = F_9 ( * V_3 , * V_21 , V_12 , V_13 ) ;
* V_3 += V_22 ;
* V_21 -= V_22 ;
memcpy ( * V_3 , V_23 , sizeof( V_23 ) ) ;
* V_3 += 4 ;
* V_21 -= 4 ;
* * V_3 = 0x68 ;
* V_3 += 1 ;
* V_21 -= 1 ;
V_22 = F_11 ( * V_3 , * V_21 , V_15 ) ;
* V_3 += V_22 ;
* V_21 -= V_22 ;
}
void F_14 ( T_2 * * V_3 , T_3 * V_21 ,
unsigned int V_16 ,
unsigned int V_17 ,
int * V_18 , T_2 * V_19 )
{
int V_22 ;
memcpy ( * V_3 , V_23 , sizeof( V_23 ) ) ;
* V_3 += 4 ;
* V_21 -= 4 ;
* * V_3 = ( V_17 == 0 ) ? 0x25 : 0x21 ;
* V_3 += 1 ;
* V_21 -= 1 ;
V_22 = F_12 ( * V_3 , * V_21 , V_16 ,
V_17 , V_18 ,
V_19 ) ;
* V_3 += V_22 ;
* V_21 -= V_22 ;
}
