static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_5 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 = V_4 -> V_8 % V_9 ;
V_4 -> V_8 += V_6 ;
if ( ( V_7 + V_6 ) >= V_9 ) {
struct V_10 * V_11 = F_4 ( V_2 -> V_12 ) ;
int V_13 ;
if ( V_7 ) {
int V_14 = V_9 - V_7 ;
memcpy ( V_4 -> V_15 + V_7 , V_5 , V_14 ) ;
V_5 += V_14 ;
V_6 -= V_14 ;
}
V_13 = V_6 / V_9 ;
V_6 %= V_9 ;
F_5 ( 8 ) ;
F_6 ( V_13 , V_4 -> V_16 , V_5 , V_11 ,
V_7 ? V_4 -> V_15 : NULL ) ;
F_7 () ;
V_5 += V_13 * V_9 ;
V_7 = 0 ;
}
if ( V_6 )
memcpy ( V_4 -> V_15 + V_7 , V_5 , V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_7 = V_4 -> V_8 % V_9 ;
if ( V_7 ) {
struct V_10 * V_11 = F_4 ( V_2 -> V_12 ) ;
memset ( V_4 -> V_15 + V_7 , 0 , V_9 - V_7 ) ;
F_5 ( 8 ) ;
F_6 ( 1 , V_4 -> V_16 , V_4 -> V_15 , V_11 , NULL ) ;
F_7 () ;
}
F_9 ( V_4 -> V_16 [ 1 ] , V_17 ) ;
F_9 ( V_4 -> V_16 [ 0 ] , V_17 + 8 ) ;
* V_4 = (struct V_3 ) {} ;
return 0 ;
}
static int F_10 ( struct V_18 * V_12 ,
const T_1 * V_19 , unsigned int V_20 )
{
struct V_10 * V_11 = F_4 ( V_12 ) ;
T_2 V_21 , V_22 ;
if ( V_20 != V_9 ) {
F_11 ( V_12 , V_23 ) ;
return - V_24 ;
}
V_22 = F_12 ( V_19 ) ;
V_21 = F_12 ( V_19 + 8 ) ;
V_11 -> V_21 = ( V_21 << 1 ) | ( V_22 >> 63 ) ;
V_11 -> V_22 = ( V_22 << 1 ) | ( V_21 >> 63 ) ;
if ( V_22 >> 63 )
V_11 -> V_22 ^= 0xc200000000000000UL ;
return 0 ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_25 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_25 ) ;
}
