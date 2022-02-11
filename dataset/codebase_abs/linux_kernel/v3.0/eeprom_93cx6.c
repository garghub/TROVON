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
const T_1 V_9 , const T_1 V_10 )
{
unsigned int V_11 ;
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
for ( V_11 = V_10 ; V_11 > 0 ; V_11 -- ) {
V_2 -> V_6 = ! ! ( V_9 & ( 1 << ( V_11 - 1 ) ) ) ;
V_2 -> V_4 ( V_2 ) ;
F_1 ( V_2 ) ;
F_3 ( V_2 ) ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_4 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 * V_9 , const T_1 V_10 )
{
unsigned int V_11 ;
T_1 V_12 = 0 ;
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
for ( V_11 = V_10 ; V_11 > 0 ; V_11 -- ) {
F_1 ( V_2 ) ;
V_2 -> V_5 ( V_2 ) ;
V_2 -> V_6 = 0 ;
if ( V_2 -> V_7 )
V_12 |= ( 1 << ( V_11 - 1 ) ) ;
F_3 ( V_2 ) ;
}
* V_9 = V_12 ;
}
void F_8 ( struct V_1 * V_2 , const T_2 V_13 ,
T_1 * V_9 )
{
T_1 V_14 ;
F_4 ( V_2 ) ;
V_14 = ( V_15 << V_2 -> V_16 ) | V_13 ;
F_6 ( V_2 , V_14 ,
V_17 + V_2 -> V_16 ) ;
F_7 ( V_2 , V_9 , 16 ) ;
F_5 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 , const T_2 V_13 ,
T_3 * V_9 , const T_1 V_18 )
{
unsigned int V_11 ;
T_1 V_19 ;
for ( V_11 = 0 ; V_11 < V_18 ; V_11 ++ ) {
V_19 = 0 ;
F_8 ( V_2 , V_13 + V_11 , & V_19 ) ;
V_9 [ V_11 ] = F_10 ( V_19 ) ;
}
}
