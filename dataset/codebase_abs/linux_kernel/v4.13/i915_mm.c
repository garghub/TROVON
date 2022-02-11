static int F_1 ( T_1 * V_1 , T_2 V_2 ,
unsigned long V_3 , void * V_4 )
{
struct F_1 * V_5 = V_4 ;
F_2 ( V_5 -> V_6 , V_3 , V_1 , F_3 ( F_4 ( V_5 -> V_7 , V_5 -> V_8 ) ) ) ;
V_5 -> V_7 ++ ;
return 0 ;
}
int F_5 ( struct V_9 * V_10 ,
unsigned long V_3 , unsigned long V_7 , unsigned long V_11 ,
struct V_12 * V_13 )
{
struct F_1 V_5 ;
int V_14 ;
F_6 ( ( V_10 -> V_15 &
( V_16 | V_17 | V_18 | V_19 ) ) !=
( V_16 | V_17 | V_18 | V_19 ) ) ;
V_5 . V_6 = V_10 -> V_20 ;
V_5 . V_7 = V_7 ;
V_5 . V_8 = F_7 ( ( F_8 ( V_13 -> V_8 ) & V_21 ) |
( F_8 ( V_10 -> V_22 ) & ~ V_21 ) ) ;
V_14 = F_9 ( V_5 . V_6 , V_3 , V_11 , F_1 , & V_5 ) ;
if ( F_10 ( V_14 ) ) {
F_11 ( V_10 , V_3 , ( V_5 . V_7 - V_7 ) << V_23 ) ;
return V_14 ;
}
return 0 ;
}
