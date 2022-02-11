static inline long F_1 ( unsigned long V_1 , T_1 V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_6 , int V_7 )
{
long V_8 = - V_9 ;
if ( ! F_2 ( V_3 ) )
goto V_10;
if ( V_7 ) {
if ( V_6 & ( ( 1 << V_7 ) - 1 ) )
goto V_10;
V_6 >>= V_7 ;
}
V_8 = F_3 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
V_10:
return V_8 ;
}
int
F_4 ( int V_11 , T_2 T_3 * V_12 , T_2 T_3 * V_13 , T_2 T_3 * exp , struct V_14 T_3 * V_15 )
{
if ( ( unsigned long ) V_11 >= 4096 )
{
unsigned long T_3 * V_16 = ( unsigned long T_3 * ) V_11 ;
if ( ! F_5 ( V_17 , V_16 , 5 *sizeof( unsigned long ) )
|| F_6 ( V_11 , V_16 )
|| F_6 ( V_12 , ( ( T_2 T_3 * T_3 * ) ( V_16 + 1 ) ) )
|| F_6 ( V_13 , ( ( T_2 T_3 * T_3 * ) ( V_16 + 2 ) ) )
|| F_6 ( exp , ( ( T_2 T_3 * T_3 * ) ( V_16 + 3 ) ) )
|| F_6 ( V_15 , ( (struct V_14 T_3 * T_3 * ) ( V_16 + 4 ) ) ) )
return - V_18 ;
}
return F_7 ( V_11 , V_12 , V_13 , exp , V_15 ) ;
}
long F_8 ( unsigned long V_19 )
{
long V_8 ;
if ( V_19 ( V_20 -> V_19 ) == V_21
&& V_19 ( V_19 ) == V_22 )
V_19 = ( V_19 & ~ V_23 ) | V_21 ;
V_8 = F_9 ( V_19 ) ;
if ( V_19 ( V_8 ) == V_21 )
V_8 = ( V_8 & ~ V_23 ) | V_22 ;
return V_8 ;
}
long F_10 ( int V_5 , int V_24 , T_4 V_25 , T_4 V_26 ,
T_4 V_27 , T_4 V_28 )
{
return F_11 ( V_5 , ( V_29 ) V_25 << 32 | V_26 ,
( V_29 ) V_27 << 32 | V_28 , V_24 ) ;
}
long F_12 ( void )
{
struct V_30 * V_31 ;
V_20 -> V_32 . V_33 -> V_34 ^= V_35 ;
V_31 = F_13 () ;
V_31 -> V_4 |= V_36 ;
return 0 ;
}
