static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_6 , T_1 V_7 , T_2 * V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_9 ;
F_5 ( V_5 , V_6 , V_7 * 2 , ( T_1 * ) V_8 ) ;
for ( V_9 = 0 ; V_9 < V_7 ; ++ V_9 )
V_8 [ V_9 ] = F_6 ( V_8 [ V_9 ] ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_8 ( V_5 , V_3 , V_10 ) ;
}
static int F_9 ( struct V_4 * V_5 ,
const struct V_11 * V_12 )
{
struct V_13 * V_14 ;
if ( ! F_10 ( V_5 -> V_15 ,
V_16 ) ) {
F_11 ( & V_5 -> V_2 , L_1 ) ;
return - V_17 ;
}
V_14 = F_12 ( & V_5 -> V_2 , V_18 , V_5 -> V_19 ,
& V_20 ) ;
if ( F_13 ( V_14 ) )
return F_14 ( V_14 ) ;
F_15 ( V_5 , V_14 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_17 ( V_5 ) ;
F_18 ( V_14 ) ;
return 0 ;
}
