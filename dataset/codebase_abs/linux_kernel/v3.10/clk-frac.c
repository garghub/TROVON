static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 div ;
div = F_3 ( V_5 -> V_6 ) >> V_5 -> V_7 ;
div &= ( 1 << V_5 -> V_8 ) - 1 ;
return ( V_3 >> V_5 -> V_8 ) * div ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_3 = * V_10 ;
T_1 div ;
T_2 V_11 ;
if ( V_9 > V_3 )
return - V_12 ;
V_11 = V_9 ;
V_11 <<= V_5 -> V_8 ;
F_5 ( V_11 , V_3 ) ;
div = V_11 ;
if ( ! div )
return - V_12 ;
return ( V_3 >> V_5 -> V_8 ) * div ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_13 ;
T_1 div , V_14 ;
T_2 V_11 ;
if ( V_9 > V_3 )
return - V_12 ;
V_11 = V_9 ;
V_11 <<= V_5 -> V_8 ;
F_5 ( V_11 , V_3 ) ;
div = V_11 ;
if ( ! div )
return - V_12 ;
F_7 ( & V_15 , V_13 ) ;
V_14 = F_3 ( V_5 -> V_6 ) ;
V_14 &= ~ ( ( ( 1 << V_5 -> V_8 ) - 1 ) << V_5 -> V_7 ) ;
V_14 |= div << V_5 -> V_7 ;
F_8 ( V_14 , V_5 -> V_6 ) ;
F_9 ( & V_15 , V_13 ) ;
return F_10 ( V_5 -> V_6 , V_5 -> V_16 ) ;
}
struct V_17 * F_11 ( const char * V_18 , const char * V_19 ,
void T_3 * V_6 , T_4 V_7 , T_4 V_8 , T_4 V_16 )
{
struct V_4 * V_5 ;
struct V_17 * V_17 ;
struct V_20 V_21 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return F_13 ( - V_23 ) ;
V_21 . V_18 = V_18 ;
V_21 . V_24 = & V_25 ;
V_21 . V_13 = V_26 ;
V_21 . V_27 = ( V_19 ? & V_19 : NULL ) ;
V_21 . V_28 = ( V_19 ? 1 : 0 ) ;
V_5 -> V_6 = V_6 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_2 . V_21 = & V_21 ;
V_17 = F_14 ( NULL , & V_5 -> V_2 ) ;
if ( F_15 ( V_17 ) )
F_16 ( V_5 ) ;
return V_17 ;
}
