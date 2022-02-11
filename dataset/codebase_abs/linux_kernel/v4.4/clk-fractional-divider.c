static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
unsigned long V_7 , V_8 ;
T_1 V_9 ;
T_2 V_10 ;
if ( V_5 -> V_11 )
F_3 ( V_5 -> V_11 , V_6 ) ;
else
F_4 ( V_5 -> V_11 ) ;
V_9 = F_5 ( V_5 -> V_12 ) ;
if ( V_5 -> V_11 )
F_6 ( V_5 -> V_11 , V_6 ) ;
else
F_7 ( V_5 -> V_11 ) ;
V_7 = ( V_9 & V_5 -> V_13 ) >> V_5 -> V_14 ;
V_8 = ( V_9 & V_5 -> V_15 ) >> V_5 -> V_16 ;
if ( ! V_8 || ! V_7 )
return V_3 ;
V_10 = ( T_2 ) V_3 * V_7 ;
F_8 ( V_10 , V_8 ) ;
return V_10 ;
}
static long F_9 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_18 ;
unsigned long V_7 , V_8 ;
T_2 V_10 ;
if ( ! V_17 || V_17 >= * V_3 )
return * V_3 ;
V_18 = F_10 ( * V_3 / V_17 - 1 ) ;
if ( V_18 > V_5 -> V_19 )
V_17 <<= V_18 - V_5 -> V_19 ;
F_11 ( V_17 , * V_3 ,
F_12 ( V_5 -> V_20 - 1 , 0 ) , F_12 ( V_5 -> V_19 - 1 , 0 ) ,
& V_7 , & V_8 ) ;
V_10 = ( T_2 ) * V_3 * V_7 ;
F_8 ( V_10 , V_8 ) ;
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
unsigned long V_7 , V_8 ;
T_1 V_9 ;
F_11 ( V_17 , V_3 ,
F_12 ( V_5 -> V_20 - 1 , 0 ) , F_12 ( V_5 -> V_19 - 1 , 0 ) ,
& V_7 , & V_8 ) ;
if ( V_5 -> V_11 )
F_3 ( V_5 -> V_11 , V_6 ) ;
else
F_4 ( V_5 -> V_11 ) ;
V_9 = F_5 ( V_5 -> V_12 ) ;
V_9 &= ~ ( V_5 -> V_13 | V_5 -> V_15 ) ;
V_9 |= ( V_7 << V_5 -> V_14 ) | ( V_8 << V_5 -> V_16 ) ;
F_14 ( V_9 , V_5 -> V_12 ) ;
if ( V_5 -> V_11 )
F_6 ( V_5 -> V_11 , V_6 ) ;
else
F_7 ( V_5 -> V_11 ) ;
return 0 ;
}
struct V_21 * F_15 ( struct V_22 * V_23 ,
const char * V_24 , const char * V_25 , unsigned long V_6 ,
void T_3 * V_12 , T_4 V_14 , T_4 V_20 , T_4 V_16 , T_4 V_19 ,
T_4 V_26 , T_5 * V_11 )
{
struct V_4 * V_5 ;
struct V_27 V_28 ;
struct V_21 * V_21 ;
V_5 = F_16 ( sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return F_17 ( - V_30 ) ;
V_28 . V_24 = V_24 ;
V_28 . V_31 = & V_32 ;
V_28 . V_6 = V_6 | V_33 ;
V_28 . V_34 = V_25 ? & V_25 : NULL ;
V_28 . V_35 = V_25 ? 1 : 0 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_14 = V_14 ;
V_5 -> V_20 = V_20 ;
V_5 -> V_13 = F_12 ( V_20 - 1 , 0 ) << V_14 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_19 = V_19 ;
V_5 -> V_15 = F_12 ( V_19 - 1 , 0 ) << V_16 ;
V_5 -> V_6 = V_26 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_2 . V_28 = & V_28 ;
V_21 = F_18 ( V_23 , & V_5 -> V_2 ) ;
if ( F_19 ( V_21 ) )
F_20 ( V_5 ) ;
return V_21 ;
}
