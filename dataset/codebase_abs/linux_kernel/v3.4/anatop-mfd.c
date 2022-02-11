T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
int V_5 )
{
T_1 V_6 , V_7 ;
if ( V_5 == 32 )
V_7 = ~ 0 ;
else
V_7 = ( 1 << V_5 ) - 1 ;
V_6 = F_2 ( V_2 -> V_8 + V_3 ) ;
V_6 = ( V_6 >> V_4 ) & V_7 ;
return V_6 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
int V_5 , T_1 V_9 )
{
T_1 V_6 , V_7 ;
if ( V_5 == 32 )
V_7 = ~ 0 ;
else
V_7 = ( 1 << V_5 ) - 1 ;
F_4 ( & V_2 -> V_10 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_3 ) & ~ ( V_7 << V_4 ) ;
F_5 ( ( V_9 << V_4 ) | V_6 , V_2 -> V_8 + V_3 ) ;
F_6 ( & V_2 -> V_10 ) ;
}
static int T_2 F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 ;
void * V_8 ;
struct V_1 * V_18 ;
V_8 = F_8 ( V_16 , 0 ) ;
if ( ! V_8 )
return - V_19 ;
V_18 = F_9 ( V_14 , sizeof( * V_18 ) , V_20 ) ;
if ( ! V_18 )
return - V_21 ;
V_18 -> V_8 = V_8 ;
F_10 ( & V_18 -> V_10 ) ;
F_11 ( V_12 , V_18 ) ;
F_12 ( V_16 , V_22 , NULL , V_14 ) ;
return 0 ;
}
static int T_3 F_13 ( struct V_11 * V_12 )
{
struct V_1 * V_18 ;
V_18 = F_14 ( V_12 ) ;
F_15 ( V_18 -> V_8 ) ;
return 0 ;
}
static int T_4 F_16 ( void )
{
return F_17 ( & V_23 ) ;
}
static void T_5 F_18 ( void )
{
F_19 ( & V_23 ) ;
}
