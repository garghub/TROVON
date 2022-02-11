static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_2 , 0 ) ;
if ( ! V_3 )
return - V_5 ;
V_4 = F_3 ( V_2 , 1 ) ;
F_4 ( V_4 | V_6 , V_3 + V_7 ) ;
F_5 ( V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 ,
unsigned long V_10 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
const struct V_11 * V_12 = NULL ;
struct V_13 * V_14 ;
int V_15 ;
if ( V_10 < F_8 ( V_16 ) )
V_12 = & V_16 [ V_10 ] ;
if ( ! V_12 )
return - V_17 ;
V_9 -> V_18 = V_12 ;
V_9 -> V_19 = V_12 -> V_20 ;
V_15 = F_9 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_9 -> V_21 = F_2 ( V_2 , 1 ) ;
if ( ! V_9 -> V_21 )
return - V_5 ;
V_14 = F_10 ( V_9 , sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_5 ;
return F_11 ( V_9 , V_2 -> V_22 , V_23 ) ;
}
static int F_12 ( struct V_1 * V_9 ,
const struct V_24 * V_25 )
{
return F_13 ( V_9 , & V_26 ,
V_25 -> V_27 ) ;
}
