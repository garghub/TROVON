static unsigned int F_1 ( struct V_1 * V_2 )
{
const T_1 * V_3 = NULL ;
V_3 = F_2 ( V_2 -> V_4 , L_1 , NULL ) ;
return ! V_3 ? V_2 -> V_5 : F_3 ( * V_3 ) ;
}
static struct V_6 * F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_5 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_2 -> V_9 = & V_10 ;
V_7 -> V_11 = V_2 ;
V_7 -> V_12 = V_2 -> V_12 ;
V_7 -> type = V_13 ;
V_7 -> V_5 = V_2 -> V_5 ;
V_7 -> V_14 = V_15 ;
V_7 -> V_16 = V_17 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_20 = V_21 ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = V_25 ;
V_7 -> V_26 = F_1 ( V_2 ) ;
V_7 -> V_27 = 1 ;
V_7 -> V_28 = 1 ;
F_6 ( V_29 ) ;
return V_7 ;
}
static unsigned long V_15 ( struct V_6 * V_7 ,
unsigned long V_30 ,
unsigned long V_31 ,
unsigned long V_24 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
return ( unsigned long ) V_2 -> V_32 + V_31 ;
}
static int V_17 ( struct V_6 * V_7 , T_2 V_33 , T_3 V_30 , T_3 * V_34 , T_4 * V_35 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
F_7 ( V_2 , V_35 , V_33 , V_30 ) ;
* V_34 = V_30 ;
return 0 ;
}
static void V_21 ( struct V_6 * V_7 )
{
}
static int V_19 ( struct V_6 * V_7 , T_2 V_36 , T_3 V_30 , T_3 * V_34 , const T_4 * V_35 )
{
return - V_37 ;
}
static int V_23 ( struct V_6 * V_7 , struct V_38 * V_39 )
{
return - V_37 ;
}
static int T_5 F_8 ( void )
{
F_9 ( & V_10 ) ;
return 0 ;
}
static void T_6 F_10 ( void )
{
F_11 ( & V_10 ) ;
}
