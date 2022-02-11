static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 1 ;
V_2 -> V_4 ( V_2 ) ;
F_2 ( 450 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 ( V_2 ) ;
F_2 ( 450 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_3 = 0 ;
V_2 -> V_8 = 1 ;
V_2 -> V_9 = 1 ;
V_2 -> V_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_8 = 0 ;
V_2 -> V_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
const T_1 V_10 , const T_1 V_11 )
{
unsigned int V_12 ;
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_9 = 1 ;
for ( V_12 = V_11 ; V_12 > 0 ; V_12 -- ) {
V_2 -> V_6 = ! ! ( V_10 & ( 1 << ( V_12 - 1 ) ) ) ;
V_2 -> V_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_3 ( V_2 ) ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_4 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 * V_10 , const T_1 V_11 )
{
unsigned int V_12 ;
T_1 V_13 = 0 ;
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_9 = 0 ;
for ( V_12 = V_11 ; V_12 > 0 ; V_12 -- ) {
F_1 ( V_2 ) ;
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
if ( V_2 -> V_7 )
V_13 |= ( 1 << ( V_12 - 1 ) ) ;
F_3 ( V_2 ) ;
}
* V_10 = V_13 ;
}
void F_8 ( struct V_1 * V_2 , const T_2 V_14 ,
T_1 * V_10 )
{
T_1 V_15 ;
F_4 ( V_2 ) ;
V_15 = ( V_16 << V_2 -> V_17 ) | V_14 ;
F_6 ( V_2 , V_15 ,
V_18 + V_2 -> V_17 ) ;
F_7 ( V_2 , V_10 , 16 ) ;
F_5 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 , const T_2 V_14 ,
T_3 * V_10 , const T_1 V_19 )
{
unsigned int V_12 ;
T_1 V_20 ;
for ( V_12 = 0 ; V_12 < V_19 ; V_12 ++ ) {
V_20 = 0 ;
F_8 ( V_2 , V_14 + V_12 , & V_20 ) ;
V_10 [ V_12 ] = F_10 ( V_20 ) ;
}
}
void F_11 ( struct V_1 * V_2 , const T_2 V_21 ,
T_2 * V_10 )
{
T_1 V_15 ;
T_1 V_20 ;
F_4 ( V_2 ) ;
V_15 = ( V_16 << ( V_2 -> V_17 + 1 ) ) | V_21 ;
F_6 ( V_2 , V_15 ,
V_18 + V_2 -> V_17 + 1 ) ;
F_7 ( V_2 , & V_20 , 8 ) ;
* V_10 = V_20 & 0xff ;
F_5 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 , const T_2 V_21 ,
T_2 * V_10 , const T_1 V_22 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_22 ; V_12 ++ )
F_11 ( V_2 , V_21 + V_12 , & V_10 [ V_12 ] ) ;
}
void F_13 ( struct V_1 * V_2 , bool V_23 )
{
T_1 V_15 ;
F_4 ( V_2 ) ;
V_15 = V_23 ? V_24 : V_25 ;
V_15 <<= ( V_2 -> V_17 - 2 ) ;
F_6 ( V_2 , V_15 ,
V_18 + V_2 -> V_17 ) ;
F_5 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 , T_2 V_26 , T_1 V_10 )
{
int V_27 = 100 ;
T_1 V_15 ;
F_4 ( V_2 ) ;
V_15 = V_28 << V_2 -> V_17 ;
V_15 |= V_26 ;
F_6 ( V_2 , V_15 ,
V_18 + V_2 -> V_17 ) ;
F_6 ( V_2 , V_10 , 16 ) ;
V_2 -> V_9 = 0 ;
V_2 -> V_8 = 1 ;
V_2 -> V_4 ( V_2 ) ;
F_15 ( 1000 , 2000 ) ;
while ( true ) {
V_2 -> V_5 ( V_2 ) ;
if ( V_2 -> V_7 )
break;
F_15 ( 1000 , 2000 ) ;
if ( -- V_27 <= 0 ) {
F_16 ( V_29 L_1 , V_30 ) ;
break;
}
}
F_5 ( V_2 ) ;
}
