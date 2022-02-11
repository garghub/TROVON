static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( & V_2 -> V_7 ,
V_4 -> V_8 ) ;
if ( V_6 >= V_4 -> V_8 )
return - V_9 ;
F_3 ( V_6 , & V_2 -> V_7 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , int V_6 )
{
F_5 ( V_6 , & V_2 -> V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
struct V_12 * V_13 = & V_11 -> V_13 ;
int V_14 ;
V_2 -> V_15 = F_8 ( V_13 , L_1 ) ;
if ( F_9 ( V_2 -> V_15 ) ) {
F_10 ( & V_11 -> V_13 , L_2 ,
V_16 , F_11 ( V_2 -> V_15 ) ) ;
return F_11 ( V_2 -> V_15 ) ;
}
V_14 = F_12 ( V_2 -> V_15 ) ;
if ( V_14 ) {
F_10 ( & V_11 -> V_13 , L_3 ,
V_16 , V_14 ) ;
return V_14 ;
}
V_2 -> V_17 = F_8 ( V_13 , L_4 ) ;
if ( F_9 ( V_2 -> V_17 ) ) {
F_10 ( & V_11 -> V_13 , L_5 ,
V_16 , F_11 ( V_2 -> V_17 ) ) ;
return F_11 ( V_2 -> V_17 ) ;
}
V_14 = F_12 ( V_2 -> V_17 ) ;
if ( V_14 ) {
F_10 ( & V_11 -> V_13 , L_6 ,
V_16 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_14 ( V_2 -> V_15 ) ;
F_14 ( V_2 -> V_17 ) ;
return 0 ;
}
