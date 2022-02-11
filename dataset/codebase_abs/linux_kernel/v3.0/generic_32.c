static inline void F_1 ( struct V_1 * V_2 , T_1 * V_3 , unsigned long V_4 , unsigned long V_5 ,
unsigned long V_6 , T_2 V_7 , int V_8 )
{
unsigned long V_9 ;
V_4 &= ~ V_10 ;
V_9 = V_4 + V_5 ;
if ( V_9 > V_11 )
V_9 = V_11 ;
do {
F_2 ( V_2 , V_4 , V_3 , F_3 ( V_6 , V_7 , V_8 ) ) ;
V_4 += V_12 ;
V_6 += V_12 ;
V_3 ++ ;
} while ( V_4 < V_9 );
}
static inline int F_4 ( struct V_1 * V_2 , T_3 * V_13 , unsigned long V_4 , unsigned long V_5 ,
unsigned long V_6 , T_2 V_7 , int V_8 )
{
unsigned long V_9 ;
V_4 &= ~ V_14 ;
V_9 = V_4 + V_5 ;
if ( V_9 > V_15 )
V_9 = V_15 ;
V_6 -= V_4 ;
do {
T_1 * V_3 = F_5 ( V_2 , NULL , V_13 , V_4 ) ;
if ( ! V_3 )
return - V_16 ;
F_1 ( V_2 , V_3 , V_4 , V_9 - V_4 , V_4 + V_6 , V_7 , V_8 ) ;
V_4 = ( V_4 + V_11 ) & V_10 ;
V_13 ++ ;
} while ( V_4 < V_9 );
return 0 ;
}
int F_6 ( struct V_17 * V_18 , unsigned long V_19 ,
unsigned long V_20 , unsigned long V_5 , T_2 V_7 )
{
int error = 0 ;
T_4 * V_21 ;
unsigned long V_22 = V_19 ;
unsigned long V_9 = V_19 + V_5 ;
struct V_1 * V_2 = V_18 -> V_23 ;
int V_8 = F_7 ( V_20 ) ;
unsigned long V_6 = F_8 ( V_20 ) << V_24 ;
V_18 -> V_25 |= V_26 | V_27 | V_28 ;
V_18 -> V_29 = ( V_6 >> V_24 ) |
( ( unsigned long ) V_8 << 28UL ) ;
V_6 -= V_19 ;
V_21 = F_9 ( V_2 , V_19 ) ;
F_10 ( V_18 , V_22 , V_9 ) ;
while ( V_19 < V_9 ) {
T_3 * V_13 = F_11 ( V_2 , V_21 , V_19 ) ;
error = - V_16 ;
if ( ! V_13 )
break;
error = F_4 ( V_2 , V_13 , V_19 , V_9 - V_19 , V_6 + V_19 , V_7 , V_8 ) ;
if ( error )
break;
V_19 = ( V_19 + V_15 ) & V_14 ;
V_21 ++ ;
}
F_12 ( V_18 , V_22 , V_9 ) ;
return error ;
}
