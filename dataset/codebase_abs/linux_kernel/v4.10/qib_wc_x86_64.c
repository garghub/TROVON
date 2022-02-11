int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_1 V_4 , V_5 ;
unsigned V_6 ;
const unsigned long V_7 = F_2 ( V_2 -> V_8 , 0 ) ;
const T_2 V_9 = F_3 ( V_2 -> V_8 , 0 ) ;
if ( V_2 -> V_10 && V_2 -> V_11 ) {
unsigned long V_12 , V_13 ;
V_12 = V_2 -> V_14 & 0xffffffffUL ;
V_13 = ( V_2 -> V_14 >> 32 ) & 0xffffffffUL ;
if ( V_12 < V_13 ) {
V_4 = V_7 + V_12 ;
V_5 = V_13 - V_12 +
V_2 -> V_11 * V_2 -> V_15 ;
} else {
V_4 = V_7 + V_13 ;
V_5 = V_12 - V_13 +
V_2 -> V_10 * V_2 -> V_16 ;
}
} else {
V_4 = V_7 + V_2 -> V_14 ;
V_5 = V_2 -> V_10 * V_2 -> V_16 +
V_2 -> V_11 * V_2 -> V_15 ;
}
for ( V_6 = 0 ; ! ( V_5 & ( 1ULL << V_6 ) ) ; V_6 ++ )
;
if ( V_5 != ( 1ULL << V_6 ) ) {
V_5 >>= V_6 ;
while ( V_5 >>= 1 )
V_6 ++ ;
V_5 = 1ULL << ( V_6 + 1 ) ;
}
if ( V_4 & ( V_5 - 1 ) ) {
T_1 V_17 = V_4 & ~ ( V_5 - 1 ) ;
if ( V_17 < V_7 || ( V_17 + V_5 ) > ( V_7 + V_9 ) ) {
F_4 ( V_2 ,
L_1 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_5 << 1 ) ;
V_3 = - V_18 ;
} else {
V_4 = V_17 ;
V_5 <<= 1 ;
}
}
if ( ! V_3 ) {
V_2 -> V_19 = F_5 ( V_4 , V_5 ) ;
if ( V_2 -> V_19 < 0 )
V_3 = V_2 -> V_19 ;
}
return V_3 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_19 ) ;
}
int F_8 ( void )
{
return V_20 . V_21 != V_22 ;
}
