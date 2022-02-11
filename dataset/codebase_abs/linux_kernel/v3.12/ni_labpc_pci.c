static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 = NULL ;
struct V_8 * V_9 ;
int V_10 ;
if ( V_3 < F_3 ( V_11 ) )
V_7 = & V_11 [ V_3 ] ;
if ( ! V_7 )
return - V_12 ;
V_2 -> V_13 = V_7 ;
V_2 -> V_14 = V_7 -> V_15 ;
V_10 = F_4 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_9 = F_5 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_16 ;
V_9 -> V_17 = F_6 ( V_5 ) ;
if ( ! V_9 -> V_17 )
return - V_16 ;
V_10 = F_7 ( V_9 -> V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_18 = ( unsigned long ) V_9 -> V_17 -> V_19 ;
return F_8 ( V_2 , F_9 ( V_9 -> V_17 ) , V_20 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_21 ;
if ( V_9 && V_9 -> V_17 ) {
F_11 ( V_9 -> V_17 ) ;
F_12 ( V_9 -> V_17 ) ;
}
if ( V_2 -> V_22 )
F_13 ( V_2 -> V_22 , V_2 ) ;
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_4 * V_2 ,
const struct V_23 * V_24 )
{
return F_16 ( V_2 , & V_25 ,
V_24 -> V_26 ) ;
}
