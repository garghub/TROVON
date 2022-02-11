static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_3 -> V_6 = & V_7 ;
V_4 -> V_8 = V_3 ;
V_4 -> V_9 = V_3 -> V_9 ;
V_4 -> type = V_10 ;
V_4 -> V_11 = V_3 -> V_11 ;
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = V_19 ;
V_4 -> V_20 = V_21 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = V_3 -> V_11 ;
V_4 -> V_25 = 1 ;
F_3 ( V_26 ) ;
return V_4 ;
}
static unsigned long V_13 ( struct V_1 * V_4 ,
unsigned long V_27 ,
unsigned long V_28 ,
unsigned long V_22 )
{
struct V_2 * V_3 = V_4 -> V_8 ;
return ( unsigned long ) V_3 -> V_29 + V_28 ;
}
static int V_15 ( struct V_1 * V_4 , T_1 V_30 , T_2 V_27 , T_2 * V_31 , T_3 * V_32 )
{
struct V_2 * V_3 = V_4 -> V_8 ;
F_4 ( V_3 , V_32 , V_30 , V_27 ) ;
* V_31 = V_27 ;
return 0 ;
}
static void V_19 ( struct V_1 * V_4 )
{
}
static int V_17 ( struct V_1 * V_4 , T_1 V_33 , T_2 V_27 , T_2 * V_31 , const T_3 * V_32 )
{
F_5 ( V_34 L_1 ) ;
return - V_35 ;
}
static int V_21 ( struct V_1 * V_4 , struct V_36 * V_37 )
{
return - V_38 ;
}
static int T_4 F_6 ( void )
{
F_7 ( & V_7 ) ;
return 0 ;
}
static void T_5 F_8 ( void )
{
F_9 ( & V_7 ) ;
}
