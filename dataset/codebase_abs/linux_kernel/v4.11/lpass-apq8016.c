static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( V_3 == V_8 ) {
V_7 = F_2 ( & V_2 -> V_9 ,
V_5 -> V_10 ) ;
if ( V_7 >= V_5 -> V_10 )
return - V_11 ;
} else {
V_7 = F_3 ( & V_2 -> V_9 ,
V_5 -> V_12 +
V_5 -> V_13 ,
V_5 -> V_12 ) ;
if ( V_7 >= V_5 -> V_12 + V_5 -> V_13 )
return - V_11 ;
}
F_4 ( V_7 , & V_2 -> V_9 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , int V_7 )
{
F_6 ( V_7 , & V_2 -> V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
struct V_16 * V_17 = & V_15 -> V_17 ;
int V_18 ;
V_2 -> V_19 = F_9 ( V_17 , L_1 ) ;
if ( F_10 ( V_2 -> V_19 ) ) {
F_11 ( & V_15 -> V_17 , L_2 ,
F_12 ( V_2 -> V_19 ) ) ;
return F_12 ( V_2 -> V_19 ) ;
}
V_18 = F_13 ( V_2 -> V_19 ) ;
if ( V_18 ) {
F_11 ( & V_15 -> V_17 , L_3 ,
V_18 ) ;
return V_18 ;
}
V_2 -> V_20 = F_9 ( V_17 , L_4 ) ;
if ( F_10 ( V_2 -> V_20 ) ) {
F_11 ( & V_15 -> V_17 , L_5 ,
F_12 ( V_2 -> V_20 ) ) ;
return F_12 ( V_2 -> V_20 ) ;
}
V_18 = F_13 ( V_2 -> V_20 ) ;
if ( V_18 ) {
F_11 ( & V_15 -> V_17 , L_6 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_8 ( V_15 ) ;
F_15 ( V_2 -> V_19 ) ;
F_15 ( V_2 -> V_20 ) ;
return 0 ;
}
