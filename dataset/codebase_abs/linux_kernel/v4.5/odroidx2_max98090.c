static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_5 * V_7 ;
int V_8 ;
V_4 = F_2 ( V_2 , V_2 -> V_9 [ 0 ] . V_10 ) ;
V_6 = V_4 -> V_6 ;
V_7 = V_4 -> V_7 ;
V_8 = F_3 ( V_6 , 0 , V_11 ,
V_12 ) ;
if ( V_8 < 0 || F_4 ( V_13 [ 0 ] . V_14 ,
L_1 , NULL ) )
return V_8 ;
return F_3 ( V_7 , V_15 ,
0 , V_16 ) ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 . V_22 ;
struct V_1 * V_2 = & V_23 ;
struct V_19 * V_24 , * V_25 ;
struct V_26 * V_27 ;
const struct V_28 * V_29 ;
int V_8 ;
V_29 = F_6 ( V_30 , V_20 ) ;
V_27 = (struct V_26 * ) V_29 -> V_31 ;
V_2 -> V_32 = V_27 -> V_32 ;
V_2 -> V_33 = V_27 -> V_33 ;
V_2 -> V_21 = & V_18 -> V_21 ;
V_8 = F_7 ( V_2 , L_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_8 ( V_2 , L_3 ) ;
if ( V_8 < 0 )
return V_8 ;
V_25 = F_9 ( V_20 , L_4 , 0 ) ;
if ( ! V_25 ) {
F_10 ( & V_18 -> V_21 ,
L_5 ) ;
return - V_34 ;
}
V_24 = F_9 ( V_20 , L_6 , 0 ) ;
if ( ! V_24 ) {
F_10 ( & V_18 -> V_21 ,
L_7 ) ;
V_8 = - V_34 ;
goto V_35;
}
V_13 [ 0 ] . V_14 = V_25 ;
V_13 [ 0 ] . V_36 = V_24 ;
V_13 [ 0 ] . V_37 = V_24 ;
V_8 = F_11 ( V_2 ) ;
if ( V_8 ) {
F_10 ( & V_18 -> V_21 , L_8 ,
V_8 ) ;
goto V_38;
}
return 0 ;
V_38:
F_12 ( V_24 ) ;
V_35:
F_12 ( V_25 ) ;
return V_8 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_14 ( V_18 ) ;
F_15 ( V_2 ) ;
F_12 ( V_13 [ 0 ] . V_36 ) ;
F_12 ( V_13 [ 0 ] . V_14 ) ;
return 0 ;
}
