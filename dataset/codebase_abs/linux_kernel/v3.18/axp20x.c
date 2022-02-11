static void F_1 ( void )
{
F_2 ( V_1 -> V_2 , V_3 ,
V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_9 * V_10 ;
const struct V_11 * V_12 ;
int V_13 ;
V_10 = F_4 ( & V_6 -> V_14 , sizeof( * V_10 ) , V_15 ) ;
if ( ! V_10 )
return - V_16 ;
V_12 = F_5 ( V_17 , & V_6 -> V_14 ) ;
if ( ! V_12 ) {
F_6 ( & V_6 -> V_14 , L_1 ) ;
return - V_18 ;
}
V_10 -> V_19 = ( long ) V_12 -> V_20 ;
V_10 -> V_5 = V_6 ;
V_10 -> V_14 = & V_6 -> V_14 ;
F_7 ( V_10 -> V_14 , V_10 ) ;
V_10 -> V_2 = F_8 ( V_6 , & V_21 ) ;
if ( F_9 ( V_10 -> V_2 ) ) {
V_13 = F_10 ( V_10 -> V_2 ) ;
F_6 ( & V_6 -> V_14 , L_2 , V_13 ) ;
return V_13 ;
}
V_13 = F_11 ( V_10 -> V_2 , V_6 -> V_22 ,
V_23 | V_24 , - 1 ,
& V_25 ,
& V_10 -> V_26 ) ;
if ( V_13 ) {
F_6 ( & V_6 -> V_14 , L_3 , V_13 ) ;
return V_13 ;
}
V_13 = F_12 ( V_10 -> V_14 , - 1 , V_27 ,
F_13 ( V_27 ) , NULL , 0 , NULL ) ;
if ( V_13 ) {
F_6 ( & V_6 -> V_14 , L_4 , V_13 ) ;
F_14 ( V_6 -> V_22 , V_10 -> V_26 ) ;
return V_13 ;
}
if ( ! V_28 ) {
V_1 = V_10 ;
V_28 = F_1 ;
}
F_15 ( & V_6 -> V_14 , L_5 ) ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_17 ( V_6 ) ;
if ( V_10 == V_1 ) {
V_1 = NULL ;
V_28 = NULL ;
}
F_18 ( V_10 -> V_14 ) ;
F_14 ( V_10 -> V_5 -> V_22 , V_10 -> V_26 ) ;
return 0 ;
}
