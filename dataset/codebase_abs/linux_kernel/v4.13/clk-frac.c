static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 div ;
T_2 V_6 ;
div = F_3 ( V_5 -> V_7 ) >> V_5 -> V_8 ;
div &= ( 1 << V_5 -> V_9 ) - 1 ;
V_6 = ( T_2 ) V_3 * div ;
return V_6 >> V_5 -> V_9 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_3 = * V_11 ;
T_1 div ;
T_2 V_12 , V_6 , V_13 ;
if ( V_10 > V_3 )
return - V_14 ;
V_12 = V_10 ;
V_12 <<= V_5 -> V_9 ;
F_5 ( V_12 , V_3 ) ;
div = V_12 ;
if ( ! div )
return - V_14 ;
V_6 = ( T_2 ) V_3 * div ;
V_13 = V_6 >> V_5 -> V_9 ;
if ( ( V_13 << V_5 -> V_9 ) < V_6 )
V_13 += 1 ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_15 ;
T_1 div , V_16 ;
T_2 V_12 ;
if ( V_10 > V_3 )
return - V_14 ;
V_12 = V_10 ;
V_12 <<= V_5 -> V_9 ;
F_5 ( V_12 , V_3 ) ;
div = V_12 ;
if ( ! div )
return - V_14 ;
F_7 ( & V_17 , V_15 ) ;
V_16 = F_3 ( V_5 -> V_7 ) ;
V_16 &= ~ ( ( ( 1 << V_5 -> V_9 ) - 1 ) << V_5 -> V_8 ) ;
V_16 |= div << V_5 -> V_8 ;
F_8 ( V_16 , V_5 -> V_7 ) ;
F_9 ( & V_17 , V_15 ) ;
return F_10 ( V_5 -> V_7 , V_5 -> V_18 ) ;
}
struct V_19 * F_11 ( const char * V_20 , const char * V_21 ,
void T_3 * V_7 , T_4 V_8 , T_4 V_9 , T_4 V_18 )
{
struct V_4 * V_5 ;
struct V_19 * V_19 ;
struct V_22 V_23 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
return F_13 ( - V_25 ) ;
V_23 . V_20 = V_20 ;
V_23 . V_26 = & V_27 ;
V_23 . V_15 = V_28 ;
V_23 . V_29 = ( V_21 ? & V_21 : NULL ) ;
V_23 . V_30 = ( V_21 ? 1 : 0 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_18 = V_18 ;
V_5 -> V_2 . V_23 = & V_23 ;
V_19 = F_14 ( NULL , & V_5 -> V_2 ) ;
if ( F_15 ( V_19 ) )
F_16 ( V_5 ) ;
return V_19 ;
}
