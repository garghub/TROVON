static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 [ 0 ] . V_4 ;
struct V_3 * V_6 = V_2 -> V_5 [ 0 ] . V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 , 0 , V_8 ,
V_9 ) ;
if ( V_7 < 0 || F_3 ( V_10 [ 0 ] . V_11 ,
L_1 , NULL ) )
return V_7 ;
return F_2 ( V_6 , V_12 ,
0 , V_13 ) ;
}
static int F_4 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 . V_19 ;
struct V_1 * V_2 = & V_20 ;
struct V_16 * V_21 , * V_22 ;
struct V_23 * V_24 ;
const struct V_25 * V_26 ;
int V_7 ;
V_26 = F_5 ( V_27 , V_17 ) ;
V_24 = (struct V_23 * ) V_26 -> V_28 ;
V_2 -> V_29 = V_24 -> V_29 ;
V_2 -> V_30 = V_24 -> V_30 ;
V_2 -> V_18 = & V_15 -> V_18 ;
V_7 = F_6 ( V_2 , L_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_7 ( V_2 , L_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 = F_8 ( V_17 , L_4 , 0 ) ;
if ( ! V_22 ) {
F_9 ( & V_15 -> V_18 ,
L_5 ) ;
return - V_31 ;
}
V_21 = F_8 ( V_17 , L_6 , 0 ) ;
if ( ! V_21 ) {
F_9 ( & V_15 -> V_18 ,
L_7 ) ;
V_7 = - V_31 ;
goto V_32;
}
V_10 [ 0 ] . V_11 = V_22 ;
V_10 [ 0 ] . V_33 = V_21 ;
V_10 [ 0 ] . V_34 = V_21 ;
V_7 = F_10 ( V_2 ) ;
if ( V_7 ) {
F_9 ( & V_15 -> V_18 , L_8 ,
V_7 ) ;
goto V_35;
}
return 0 ;
V_35:
F_11 ( V_21 ) ;
V_32:
F_11 ( V_22 ) ;
return V_7 ;
}
static int F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_14 ( V_2 ) ;
F_11 ( V_10 [ 0 ] . V_33 ) ;
F_11 ( V_10 [ 0 ] . V_11 ) ;
return 0 ;
}
