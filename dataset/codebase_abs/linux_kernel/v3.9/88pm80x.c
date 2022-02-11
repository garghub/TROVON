int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
V_6 =
F_2 ( & V_2 -> V_10 , sizeof( struct V_5 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
V_8 = F_3 ( V_2 , & V_13 ) ;
if ( F_4 ( V_8 ) ) {
V_9 = F_5 ( V_8 ) ;
F_6 ( & V_2 -> V_10 , L_1 ,
V_9 ) ;
return V_9 ;
}
V_6 -> V_4 = V_4 -> V_14 ;
if ( V_6 -> V_4 < V_15 || V_6 -> V_4 > V_16 )
return - V_17 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_7 = V_8 ;
V_6 -> V_18 = V_2 -> V_18 ;
V_6 -> V_10 = & V_2 -> V_10 ;
F_7 ( V_6 -> V_10 , V_6 ) ;
F_8 ( V_6 -> V_2 , V_6 ) ;
F_9 ( & V_2 -> V_10 , 1 ) ;
if ( ! V_19 )
V_19 = V_6 ;
else {
V_6 -> V_20 = V_19 -> V_2 ;
V_19 -> V_20 = V_6 -> V_2 ;
}
return 0 ;
}
int F_10 ( void )
{
if ( V_19 -> V_20 )
V_19 -> V_20 = NULL ;
else
V_19 = NULL ;
return 0 ;
}
static int F_11 ( struct V_21 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 , struct V_1 , V_10 ) ;
struct V_5 * V_6 = F_13 ( V_2 ) ;
if ( V_6 && V_6 -> V_22 )
if ( F_14 ( V_6 -> V_10 ) )
F_15 ( V_6 -> V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_21 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 , struct V_1 , V_10 ) ;
struct V_5 * V_6 = F_13 ( V_2 ) ;
if ( V_6 && V_6 -> V_22 )
if ( F_14 ( V_6 -> V_10 ) )
F_17 ( V_6 -> V_18 ) ;
return 0 ;
}
