static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 = F_3 ( V_6 -> V_7 ) >> V_6 -> V_8 ;
V_4 &= F_4 ( V_6 -> V_9 ) ;
return F_5 ( V_2 , V_3 , V_4 , V_6 -> V_10 ,
V_11 ) ;
}
static long F_6 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_7 ( V_2 , V_12 , V_13 , V_6 -> V_10 ,
V_6 -> V_9 , V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_3 )
{
int V_14 ;
unsigned long V_15 = 0 ;
T_1 V_16 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_14 = F_9 ( V_12 , V_3 , V_6 -> V_10 ,
V_6 -> V_9 , V_11 ) ;
if ( V_6 -> V_17 )
F_10 ( V_6 -> V_17 , V_15 ) ;
V_16 = F_3 ( V_6 -> V_7 ) ;
V_16 &= ~ ( F_4 ( V_6 -> V_9 ) << V_6 -> V_8 ) ;
V_16 |= V_14 << V_6 -> V_8 ;
V_16 |= V_6 -> V_18 ;
F_11 ( V_16 , V_6 -> V_7 ) ;
if ( V_6 -> V_17 )
F_12 ( V_6 -> V_17 , V_15 ) ;
return 0 ;
}
struct V_19 * F_13 ( struct V_20 * V_21 , const char * V_22 ,
const char * V_23 , unsigned long V_15 , void T_2 * V_7 ,
T_3 V_8 , T_3 V_9 , T_1 V_24 , T_4 * V_17 )
{
struct V_5 * div ;
struct V_19 * V_19 ;
struct V_25 V_26 ;
struct V_27 * V_10 ;
T_1 V_28 , V_29 ;
int V_30 ;
div = F_14 ( sizeof( * div ) , V_31 ) ;
if ( ! div )
return F_15 ( - V_32 ) ;
V_28 = F_4 ( V_9 ) + 1 ;
V_29 = 1 ;
V_10 = F_16 ( V_28 + 1 , sizeof( * V_10 ) , V_31 ) ;
if ( ! V_10 ) {
F_17 ( div ) ;
return F_15 ( - V_32 ) ;
}
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ ) {
V_10 [ V_30 ] . div = V_29 + V_30 ;
V_10 [ V_30 ] . V_4 = V_10 [ V_30 ] . div - 1 ;
}
V_26 . V_22 = V_22 ;
V_26 . V_33 = & V_34 ;
V_26 . V_15 = V_15 ;
V_26 . V_35 = V_23 ? & V_23 : NULL ;
V_26 . V_36 = V_23 ? 1 : 0 ;
div -> V_7 = V_7 ;
div -> V_8 = V_8 ;
div -> V_9 = V_9 ;
div -> V_18 = V_24 ? F_18 ( V_24 ) : 0 ;
div -> V_17 = V_17 ;
div -> V_2 . V_26 = & V_26 ;
div -> V_10 = V_10 ;
V_19 = F_19 ( V_21 , & div -> V_2 ) ;
if ( F_20 ( V_19 ) ) {
F_17 ( V_10 ) ;
F_17 ( div ) ;
}
return V_19 ;
}
