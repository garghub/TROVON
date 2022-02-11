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
T_1 V_17 ;
F_4 ( L_1
L_2 ,
( unsigned long long ) V_4 ,
( unsigned long long ) V_5 ) ;
V_17 = V_4 & ~ ( V_5 - 1 ) ;
if ( V_17 < V_7 || ( V_17 + V_5 ) > ( V_7 + V_9 ) ) {
F_5 ( V_2 , L_3
L_4 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_5 << 1 ) ;
V_3 = - V_18 ;
} else {
F_4 ( L_5
L_6 ,
( unsigned long long ) V_4 ,
( unsigned long long ) V_17 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_5 << 1 ) ;
V_4 = V_17 ;
V_5 <<= 1 ;
}
}
if ( ! V_3 ) {
V_2 -> V_19 = F_6 ( V_4 , V_5 ) ;
if ( V_2 -> V_19 < 0 ) {
F_5 ( V_2 , L_7 ) ;
V_3 = - V_18 ;
} else if ( V_2 -> V_19 == 0 )
F_7 ( V_20 , L_8 ) ;
else
F_7 ( V_20 , L_9 ) ;
}
return V_3 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_19 ) ;
}
