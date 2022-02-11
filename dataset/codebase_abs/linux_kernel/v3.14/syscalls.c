static inline unsigned long F_1 ( unsigned long V_1 , T_1 V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_6 , int V_7 )
{
unsigned long V_8 = - V_9 ;
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
unsigned long F_4 ( unsigned long V_1 , T_1 V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , unsigned long V_11 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_11 , V_12 - 12 ) ;
}
unsigned long F_5 ( unsigned long V_1 , T_1 V_2 ,
unsigned long V_3 , unsigned long V_4 ,
unsigned long V_5 , T_2 V_13 )
{
return F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_13 , V_12 ) ;
}
int
F_6 ( int V_14 , T_3 T_4 * V_15 , T_3 T_4 * V_16 , T_3 T_4 * exp , struct V_17 T_4 * V_18 )
{
if ( ( unsigned long ) V_14 >= 4096 )
{
unsigned long T_4 * V_19 = ( unsigned long T_4 * ) V_14 ;
if ( ! F_7 ( V_20 , V_19 , 5 *sizeof( unsigned long ) )
|| F_8 ( V_14 , V_19 )
|| F_8 ( V_15 , ( ( T_3 T_4 * T_4 * ) ( V_19 + 1 ) ) )
|| F_8 ( V_16 , ( ( T_3 T_4 * T_4 * ) ( V_19 + 2 ) ) )
|| F_8 ( exp , ( ( T_3 T_4 * T_4 * ) ( V_19 + 3 ) ) )
|| F_8 ( V_18 , ( (struct V_17 T_4 * T_4 * ) ( V_19 + 4 ) ) ) )
return - V_21 ;
}
return F_9 ( V_14 , V_15 , V_16 , exp , V_18 ) ;
}
long F_10 ( unsigned long V_22 )
{
long V_8 ;
if ( V_22 ( V_23 -> V_22 ) == V_24
&& V_22 ( V_22 ) == V_25 )
V_22 = ( V_22 & ~ V_26 ) | V_24 ;
V_8 = F_11 ( V_22 ) ;
if ( V_22 ( V_8 ) == V_24 )
V_8 = ( V_8 & ~ V_26 ) | V_25 ;
return V_8 ;
}
long F_12 ( int V_5 , int V_27 , T_5 V_28 , T_5 V_29 ,
T_5 V_30 , T_5 V_31 )
{
return F_13 ( V_5 , ( V_32 ) V_28 << 32 | V_29 ,
( V_32 ) V_30 << 32 | V_31 , V_27 ) ;
}
void F_14 ( unsigned long V_33 , unsigned long V_34 , unsigned long V_35 ,
unsigned long V_36 , unsigned long V_37 , unsigned long V_38 ,
struct V_39 * V_40 )
{
F_15 ( L_1
L_2 , V_40 -> V_41 [ 0 ] , V_33 , V_34 , V_35 , V_36 , V_37 , V_38 , V_40 ,
V_23 , F_16 () ) ;
}
void F_17 ( unsigned long V_33 )
{
F_15 ( L_3 , V_33 , V_23 , F_16 () ) ;
}
