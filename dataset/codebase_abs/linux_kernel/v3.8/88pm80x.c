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
goto V_14;
}
V_6 -> V_4 = V_4 -> V_15 ;
if ( V_6 -> V_4 < V_16 || V_6 -> V_4 > V_17 ) {
V_9 = - V_18 ;
goto V_19;
}
V_6 -> V_2 = V_2 ;
V_6 -> V_7 = V_8 ;
V_6 -> V_20 = V_2 -> V_20 ;
V_6 -> V_10 = & V_2 -> V_10 ;
F_7 ( V_6 -> V_10 , V_6 ) ;
F_8 ( V_6 -> V_2 , V_6 ) ;
F_9 ( & V_2 -> V_10 , 1 ) ;
if ( ! V_21 )
V_21 = V_6 ;
else {
V_6 -> V_22 = V_21 -> V_2 ;
V_21 -> V_22 = V_6 -> V_2 ;
}
return 0 ;
V_19:
F_10 ( V_8 ) ;
V_14:
F_11 ( & V_2 -> V_10 , V_6 ) ;
return V_9 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
if ( V_21 -> V_22 )
V_21 -> V_22 = NULL ;
else
V_21 = NULL ;
F_10 ( V_6 -> V_7 ) ;
F_11 ( & V_2 -> V_10 , V_6 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_10 )
{
struct V_1 * V_2 = F_15 ( V_10 , struct V_1 , V_10 ) ;
struct V_5 * V_6 = F_13 ( V_2 ) ;
if ( V_6 && V_6 -> V_24 )
if ( F_16 ( V_6 -> V_10 ) )
F_17 ( V_6 -> V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_23 * V_10 )
{
struct V_1 * V_2 = F_15 ( V_10 , struct V_1 , V_10 ) ;
struct V_5 * V_6 = F_13 ( V_2 ) ;
if ( V_6 && V_6 -> V_24 )
if ( F_16 ( V_6 -> V_10 ) )
F_19 ( V_6 -> V_20 ) ;
return 0 ;
}
