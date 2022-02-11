static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
int V_5 ;
if ( V_2 ) {
V_5 = F_3 ( V_4 -> V_6 , V_7 ,
V_8 |
V_9 ) ;
if ( V_5 < 0 ) {
F_4 ( V_4 -> V_10 , L_1 , V_5 ) ;
return V_5 ;
}
V_5 = F_5 ( V_4 -> V_11 ) ;
} else {
F_6 ( V_4 -> V_11 ) ;
V_5 = F_3 ( V_4 -> V_6 , V_7 ,
V_8 |
V_12 ) ;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , true ) ;
}
static int F_8 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , false ) ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_15 * V_10 = & V_14 -> V_10 ;
struct V_16 * V_17 = V_10 -> V_18 ;
struct V_19 * V_19 ;
struct V_3 * V_4 ;
struct V_1 * V_1 ;
int V_5 ;
if ( ! V_17 )
return - V_20 ;
if ( ! V_10 -> V_21 || ! V_10 -> V_21 -> V_18 )
return - V_20 ;
V_4 = F_10 ( V_10 , sizeof( * V_4 ) , V_22 ) ;
if ( F_11 ( V_4 ) )
return - V_23 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = F_12 ( V_10 , L_2 ) ;
if ( F_11 ( V_4 -> V_11 ) ) {
F_4 ( V_10 , L_3 ) ;
return F_13 ( V_4 -> V_11 ) ;
}
V_5 = F_14 ( V_4 -> V_11 , 24000000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_4 -> V_10 , L_4 , V_5 ) ;
return V_5 ;
}
V_4 -> V_6 = F_15 ( V_10 -> V_21 -> V_18 ) ;
if ( F_11 ( V_4 -> V_6 ) ) {
F_4 ( V_10 , L_5 ) ;
return F_13 ( V_4 -> V_6 ) ;
}
V_5 = F_3 ( V_4 -> V_6 , V_7 , V_24 |
V_25 ) ;
if ( V_5 != 0 ) {
F_4 ( V_4 -> V_10 , L_6 , V_5 ) ;
return V_5 ;
}
V_1 = F_16 ( V_10 , V_17 , & V_26 ) ;
if ( F_11 ( V_1 ) ) {
F_4 ( V_10 , L_7 ) ;
return F_13 ( V_1 ) ;
}
F_17 ( V_1 , V_4 ) ;
V_19 = F_18 ( V_10 , V_27 ) ;
return F_19 ( V_19 ) ;
}
