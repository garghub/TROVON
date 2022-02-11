static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
T_1 V_7 , V_8 , V_9 ;
T_2 V_10 ;
if ( V_5 -> V_11 )
F_3 ( V_5 -> V_11 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_12 ) ;
if ( V_5 -> V_11 )
F_5 ( V_5 -> V_11 , V_6 ) ;
V_8 = ( V_7 & V_5 -> V_13 ) >> V_5 -> V_14 ;
V_9 = ( V_7 & V_5 -> V_15 ) >> V_5 -> V_16 ;
if ( ! V_9 || ! V_8 )
return V_3 ;
V_10 = ( T_2 ) V_3 * V_8 ;
F_6 ( V_10 , V_9 ) ;
return V_10 ;
}
static long F_7 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long * V_18 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_19 = ( V_5 -> V_15 >> V_5 -> V_16 ) + 1 ;
unsigned div ;
if ( ! V_17 || V_17 >= * V_18 )
return * V_18 ;
div = F_8 ( * V_18 , V_17 ) ;
while ( ( * V_18 / div ) > V_19 ) {
div <<= 1 ;
V_17 <<= 1 ;
}
return V_17 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
unsigned long div ;
unsigned V_9 , V_8 ;
T_1 V_7 ;
div = F_8 ( V_3 , V_17 ) ;
V_8 = V_17 / div ;
V_9 = V_3 / div ;
if ( V_5 -> V_11 )
F_3 ( V_5 -> V_11 , V_6 ) ;
V_7 = F_4 ( V_5 -> V_12 ) ;
V_7 &= ~ ( V_5 -> V_13 | V_5 -> V_15 ) ;
V_7 |= ( V_8 << V_5 -> V_14 ) | ( V_9 << V_5 -> V_16 ) ;
F_10 ( V_7 , V_5 -> V_12 ) ;
if ( V_5 -> V_11 )
F_5 ( V_5 -> V_11 , V_6 ) ;
return 0 ;
}
struct V_20 * F_11 ( struct V_21 * V_22 ,
const char * V_23 , const char * V_24 , unsigned long V_6 ,
void T_3 * V_12 , T_4 V_14 , T_4 V_25 , T_4 V_16 , T_4 V_26 ,
T_4 V_27 , T_5 * V_11 )
{
struct V_4 * V_5 ;
struct V_28 V_29 ;
struct V_20 * V_20 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_30 ) ;
if ( ! V_5 ) {
F_13 ( V_22 , L_1 ) ;
return F_14 ( - V_31 ) ;
}
V_29 . V_23 = V_23 ;
V_29 . V_32 = & V_33 ;
V_29 . V_6 = V_6 | V_34 ;
V_29 . V_35 = V_24 ? & V_24 : NULL ;
V_29 . V_36 = V_24 ? 1 : 0 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_14 = V_14 ;
V_5 -> V_13 = ( F_15 ( V_25 ) - 1 ) << V_14 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_15 = ( F_15 ( V_26 ) - 1 ) << V_16 ;
V_5 -> V_6 = V_27 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_2 . V_29 = & V_29 ;
V_20 = F_16 ( V_22 , & V_5 -> V_2 ) ;
if ( F_17 ( V_20 ) )
F_18 ( V_5 ) ;
return V_20 ;
}
