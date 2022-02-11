static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_3 )
{
int V_4 ;
V_4 = F_2 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_2 V_6 ,
T_2 V_3 )
{
int V_4 ;
V_4 = F_5 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 ,
& V_6 , 1 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_4 ;
T_2 V_3 ;
V_4 = F_7 ( ( T_2 ) ( V_2 >> 8 ) , ( T_2 ) ( V_2 & 0xFF ) , & V_3 , 1 ) ;
if ( V_4 < 0 ) {
F_3 ( V_1 -> V_5 , L_1 , V_4 ) ;
return V_4 ;
}
return ( int ) V_3 ;
}
static int T_3 F_8 ( struct V_7 * V_8 )
{
const struct V_9 * V_10 = F_9 ( V_8 ) ;
struct V_1 * V_1 ;
struct V_11 * V_11 ;
int V_4 ;
V_1 = F_10 ( sizeof *V_1 , V_12 ) ;
if ( ! V_1 )
return - V_13 ;
V_1 -> V_5 = & V_8 -> V_5 ;
V_11 = F_11 ( V_8 , V_14 , 0 ) ;
if ( ! V_11 ) {
F_12 ( V_1 ) ;
return - V_15 ;
}
V_1 -> V_16 = V_11 -> V_17 ;
V_1 -> V_18 = F_6 ;
V_1 -> V_19 = F_1 ;
V_1 -> V_20 = F_4 ;
F_13 ( V_8 , V_1 ) ;
V_4 = F_14 ( V_1 , V_10 -> V_21 ) ;
if ( V_4 )
F_12 ( V_1 ) ;
return V_4 ;
}
static int T_4 F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_16 ( V_8 ) ;
F_17 ( V_1 ) ;
F_12 ( V_1 ) ;
return 0 ;
}
static int T_5 F_18 ( void )
{
return F_19 ( & V_22 ) ;
}
static void T_6 F_20 ( void )
{
F_21 ( & V_22 ) ;
}
