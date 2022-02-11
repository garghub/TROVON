static int F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
return F_2 ( V_2 -> V_4 , V_2 -> V_5 ,
V_6 | ( V_3 ? V_7 : V_8 ) ) ;
}
static int F_3 ( struct V_2 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
int V_10 = 0 ;
V_10 = F_1 ( V_2 , 1 ) ;
if ( V_10 )
return V_10 ;
F_5 ( V_2 -> V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_2 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
int V_10 = 0 ;
V_10 = F_7 ( V_2 -> V_11 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_1 ( V_2 , 0 ) ;
if ( V_10 ) {
F_5 ( V_2 -> V_11 ) ;
return V_10 ;
}
return 0 ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_13 -> V_15 ;
struct V_1 * V_16 ;
struct V_17 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
unsigned int V_5 ;
V_21 = F_9 ( V_15 -> V_22 , L_1 ) ;
if ( F_10 ( V_21 ) ) {
F_11 ( & V_13 -> V_15 , L_2 ) ;
return F_12 ( V_21 ) ;
}
F_13 (dev->of_node, child) {
V_16 = F_14 ( V_15 , sizeof( * V_16 ) , V_23 ) ;
if ( ! V_16 )
return - V_24 ;
if ( F_15 ( V_19 , L_3 , & V_5 ) ) {
F_11 ( V_15 , L_4 ,
V_19 -> V_25 ) ;
return - V_26 ;
}
V_16 -> V_5 = V_5 ;
V_16 -> V_4 = V_21 ;
V_16 -> V_11 = F_16 ( V_19 , L_5 ) ;
if ( F_10 ( V_16 -> V_11 ) )
V_16 -> V_11 = NULL ;
V_16 -> V_2 = F_17 ( V_15 , V_19 , & V_27 ) ;
if ( F_10 ( V_16 -> V_2 ) ) {
F_11 ( V_15 , L_6 ) ;
return F_12 ( V_16 -> V_2 ) ;
}
F_18 ( V_16 -> V_2 , V_16 ) ;
}
V_17 = F_19 ( V_15 , V_28 ) ;
return F_20 ( V_17 ) ;
}
