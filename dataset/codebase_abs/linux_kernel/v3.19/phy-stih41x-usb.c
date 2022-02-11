static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return F_3 ( V_3 -> V_4 , V_3 -> V_5 -> V_6 ,
V_3 -> V_5 -> V_7 , V_3 -> V_5 -> V_5 ) ;
}
static int F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_8 ;
V_8 = F_5 ( V_3 -> V_9 ) ;
if ( V_8 ) {
F_6 ( V_3 -> V_10 , L_1 ) ;
return V_8 ;
}
return F_3 ( V_3 -> V_4 , V_3 -> V_5 -> V_6 ,
V_3 -> V_5 -> V_11 , V_3 -> V_5 -> V_11 ) ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_8 ;
V_8 = F_3 ( V_3 -> V_4 , V_3 -> V_5 -> V_6 ,
V_3 -> V_5 -> V_11 , 0 ) ;
if ( V_8 ) {
F_6 ( V_3 -> V_10 , L_2 ) ;
return V_8 ;
}
F_8 ( V_3 -> V_9 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_10 . V_16 ;
const struct V_17 * V_18 ;
struct V_2 * V_3 ;
struct V_19 * V_10 = & V_13 -> V_10 ;
struct V_20 * V_20 ;
struct V_1 * V_1 ;
V_3 = F_10 ( V_10 , sizeof( * V_3 ) , V_21 ) ;
if ( ! V_3 )
return - V_22 ;
V_18 = F_11 ( V_23 , & V_13 -> V_10 ) ;
if ( ! V_18 )
return - V_24 ;
V_3 -> V_5 = V_18 -> V_25 ;
V_3 -> V_4 = F_12 ( V_15 , L_3 ) ;
if ( F_13 ( V_3 -> V_4 ) ) {
F_6 ( V_10 , L_4 ) ;
return F_14 ( V_3 -> V_4 ) ;
}
V_3 -> V_9 = F_15 ( V_10 , L_5 ) ;
if ( F_13 ( V_3 -> V_9 ) ) {
F_6 ( V_10 , L_6 ) ;
return F_14 ( V_3 -> V_9 ) ;
}
V_1 = F_16 ( V_10 , NULL , & V_26 ) ;
if ( F_13 ( V_1 ) ) {
F_6 ( V_10 , L_7 ) ;
return F_14 ( V_1 ) ;
}
V_3 -> V_10 = V_10 ;
F_17 ( V_1 , V_3 ) ;
V_20 = F_18 ( V_10 , V_27 ) ;
return F_19 ( V_20 ) ;
}
