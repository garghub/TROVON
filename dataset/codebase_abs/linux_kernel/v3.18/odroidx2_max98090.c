static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 [ 0 ] . V_4 ;
struct V_3 * V_6 = V_2 -> V_5 [ 0 ] . V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 , 0 , V_8 ,
V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_2 ( V_6 , V_10 ,
0 , V_11 ) ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 . V_17 ;
struct V_1 * V_2 = & V_18 ;
struct V_14 * V_19 , * V_20 ;
struct V_21 * V_22 ;
const struct V_23 * V_24 ;
int V_7 ;
V_24 = F_4 ( V_25 , V_15 ) ;
V_22 = (struct V_21 * ) V_24 -> V_26 ;
V_2 -> V_27 = V_22 -> V_27 ;
V_2 -> V_28 = V_22 -> V_28 ;
V_2 -> V_16 = & V_13 -> V_16 ;
V_7 = F_5 ( V_2 , L_1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , L_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_20 = F_7 ( V_15 , L_3 , 0 ) ;
if ( ! V_20 ) {
F_8 ( & V_13 -> V_16 ,
L_4 ) ;
return - V_29 ;
}
V_19 = F_7 ( V_15 , L_5 , 0 ) ;
if ( ! V_19 ) {
F_8 ( & V_13 -> V_16 ,
L_6 ) ;
V_7 = - V_29 ;
goto V_30;
}
V_31 [ 0 ] . V_32 = V_20 ;
V_31 [ 0 ] . V_33 = V_19 ;
V_31 [ 0 ] . V_34 = V_19 ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 ) {
F_8 ( & V_13 -> V_16 , L_7 ,
V_7 ) ;
goto V_35;
}
return 0 ;
V_35:
F_10 ( V_19 ) ;
V_30:
F_10 ( V_20 ) ;
return V_7 ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
F_13 ( V_2 ) ;
F_10 ( (struct V_14 * ) V_31 [ 0 ] . V_33 ) ;
F_10 ( (struct V_14 * ) V_31 [ 0 ] . V_32 ) ;
return 0 ;
}
