static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
struct V_4 V_5 ;
int V_6 = V_2 -> V_7 -> V_8 ( V_2 -> V_9 . V_10 , & V_5 ) ;
unsigned long long V_11 , V_12 ;
unsigned int V_13 = V_14 ;
unsigned int V_15 = V_16 ;
struct V_17 * V_18 = V_2 -> V_18 ;
if ( V_6 )
return V_6 ;
if ( V_18 ) {
if ( V_18 -> V_19 )
V_13 = V_18 -> V_19 ;
if ( V_18 -> V_20 )
V_15 = V_18 -> V_20 ;
}
if ( V_13 > 100 ||
V_13 < V_15 )
return - V_21 ;
if ( V_5 . V_22 == 0 ) {
* V_3 = V_23 ;
return 0 ;
}
if ( V_5 . V_24 >= ( 1 << 24 ) || V_5 . V_22 >= ( 1 << 24 ) ) {
V_5 . V_24 >>= 7 ;
V_5 . V_22 >>= 7 ;
}
if ( V_5 . V_24 * 100 >
V_5 . V_22 * V_13 ) {
* V_3 = V_23 ;
return 0 ;
}
if ( V_5 . V_25 == 0 ) {
* V_3 = V_23 ;
return 0 ;
}
if ( V_5 . V_24 * 100 >
V_5 . V_22 * ( V_13 - V_15 ) ) {
* V_3 = V_5 . V_25 ;
return 0 ;
}
V_11 = V_5 . V_24 ;
V_11 *= V_5 . V_25 ;
V_12 = F_2 ( V_11 , V_5 . V_22 ) ;
V_12 *= 100 ;
V_12 = F_2 ( V_12 , ( V_13 - V_15 / 2 ) ) ;
* V_3 = ( unsigned long ) V_12 ;
return 0 ;
}
