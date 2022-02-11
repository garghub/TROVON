static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
if ( F_2 ( V_2 -> V_5 ) )
return;
V_4 = V_3 ? 0 : V_6 ;
F_3 ( V_2 -> V_5 , V_2 -> V_7 -> V_8 ,
V_6 , V_4 ) ;
}
static int F_4 ( struct V_9 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_1 ( V_2 , 1 ) ;
return 0 ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_12 * V_13 = & V_11 -> V_13 ;
const struct V_14 * V_15 ;
struct V_16 * V_16 ;
struct V_9 * V_9 ;
V_2 = F_8 ( V_13 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
V_2 -> V_5 = F_9 ( V_13 -> V_19 ,
L_1 ) ;
if ( F_2 ( V_2 -> V_5 ) ) {
F_10 ( V_13 , L_2 ) ;
return F_11 ( V_2 -> V_5 ) ;
}
V_15 = F_12 ( V_20 , V_13 -> V_19 ) ;
V_2 -> V_7 = V_15 -> V_21 ;
V_9 = F_13 ( V_13 , NULL , & V_22 ) ;
if ( F_2 ( V_9 ) ) {
F_10 ( V_13 , L_3 ) ;
return F_11 ( V_9 ) ;
}
F_14 ( V_9 , V_2 ) ;
V_16 = F_15 ( V_13 , V_23 ) ;
return F_16 ( V_16 ) ;
}
