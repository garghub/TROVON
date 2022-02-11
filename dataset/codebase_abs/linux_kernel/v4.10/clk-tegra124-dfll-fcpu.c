static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 , V_6 ;
struct V_7 * V_8 ;
V_3 = V_9 . V_10 ;
V_4 = V_9 . V_11 ;
V_5 = V_9 . V_12 ;
if ( V_4 >= F_2 ( V_13 ) ) {
F_3 ( & V_2 -> V_14 , L_1 ,
V_4 ) ;
return - V_15 ;
}
V_8 = F_4 ( & V_2 -> V_14 , sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 )
return - V_17 ;
V_8 -> V_14 = F_5 ( 0 ) ;
if ( ! V_8 -> V_14 ) {
F_3 ( & V_2 -> V_14 , L_2 ) ;
return - V_15 ;
}
V_8 -> V_18 = V_13 [ V_4 ] ;
V_8 -> V_19 = F_6 ( V_8 -> V_14 , V_20 ,
F_2 ( V_20 ) ,
V_3 , V_4 , V_5 ,
V_8 -> V_18 ) ;
if ( F_7 ( V_8 -> V_19 ) ) {
F_3 ( & V_2 -> V_14 , L_3 ,
F_8 ( V_8 -> V_19 ) ) ;
return F_8 ( V_8 -> V_19 ) ;
}
V_6 = F_9 ( V_2 , V_8 ) ;
if ( V_6 < 0 ) {
F_10 ( V_8 -> V_14 , V_8 -> V_19 , V_8 -> V_18 ) ;
return V_6 ;
}
F_11 ( V_2 , V_8 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_13 ( V_2 ) ;
int V_6 ;
V_6 = F_14 ( V_2 ) ;
if ( V_6 < 0 )
F_3 ( & V_2 -> V_14 , L_4 , V_6 ) ;
F_10 ( V_8 -> V_14 , V_8 -> V_19 , V_8 -> V_18 ) ;
return 0 ;
}
