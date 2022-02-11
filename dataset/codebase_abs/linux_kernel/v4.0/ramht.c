static T_1
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
while ( V_4 ) {
V_5 ^= ( V_4 & ( ( 1 << V_2 -> V_6 ) - 1 ) ) ;
V_4 >>= V_2 -> V_6 ;
}
V_5 ^= V_3 << ( V_2 -> V_6 - 4 ) ;
V_5 = V_5 << 3 ;
return V_5 ;
}
int
F_2 ( struct V_1 * V_2 , int V_3 , T_1 V_4 , T_1 V_7 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
T_1 V_10 , V_11 ;
V_10 = V_11 = F_1 ( V_2 , V_3 , V_4 ) ;
do {
if ( ! F_3 ( V_2 , V_10 + 4 ) ) {
F_4 ( V_2 , V_10 + 0 , V_4 ) ;
F_4 ( V_2 , V_10 + 4 , V_7 ) ;
if ( V_9 )
V_9 -> V_12 ( V_9 ) ;
return V_10 ;
}
V_10 += 8 ;
if ( V_10 >= F_5 ( V_2 ) -> V_13 )
V_10 = 0 ;
} while ( V_10 != V_11 );
return - V_14 ;
}
void
F_6 ( struct V_1 * V_2 , int V_15 )
{
struct V_8 * V_9 = V_8 ( V_2 ) ;
F_4 ( V_2 , V_15 + 0 , 0x00000000 ) ;
F_4 ( V_2 , V_15 + 4 , 0x00000000 ) ;
if ( V_9 )
V_9 -> V_12 ( V_9 ) ;
}
int
F_7 ( struct V_16 * V_17 , struct V_16 * V_18 ,
T_1 V_13 , T_1 V_19 , struct V_1 * * V_20 )
{
struct V_1 * V_2 ;
int V_21 ;
V_21 = F_8 ( V_17 , V_17 -> V_22 ?
& V_17 -> V_22 -> V_23 . V_24 : V_17 ,
& V_25 , 0 , V_18 , V_13 ,
V_19 , V_26 , & V_2 ) ;
* V_20 = V_2 ;
if ( V_21 )
return V_21 ;
V_2 -> V_6 = F_9 ( F_5 ( V_2 ) -> V_13 >> 3 ) ;
return 0 ;
}
