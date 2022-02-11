static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
int V_4 ;
V_4 = F_2 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_4 ;
T_2 V_3 ;
V_4 = F_5 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
return ( int ) V_3 ;
}
static int T_3 F_6 ( struct V_6 * V_7 )
{
struct V_1 * V_1 ;
struct V_8 * V_8 ;
int V_4 ;
V_1 = F_7 ( sizeof *V_1 , V_9 ) ;
if ( ! V_1 )
return - V_10 ;
V_1 -> V_5 = & V_7 -> V_5 ;
V_8 = F_8 ( V_7 , V_11 , 0 ) ;
if ( ! V_8 ) {
F_9 ( V_1 ) ;
return - V_12 ;
}
V_1 -> V_13 = V_8 -> V_14 ;
V_1 -> V_15 = F_4 ;
V_1 -> V_16 = F_1 ;
F_10 ( V_7 , V_1 ) ;
V_4 = F_11 ( V_1 ) ;
if ( V_4 )
F_9 ( V_1 ) ;
return V_4 ;
}
static int T_4 F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_13 ( V_7 ) ;
F_14 ( V_1 ) ;
F_9 ( V_1 ) ;
return 0 ;
}
static int T_5 F_15 ( void )
{
return F_16 ( & V_17 ) ;
}
static void T_6 F_17 ( void )
{
F_18 ( & V_17 ) ;
}
