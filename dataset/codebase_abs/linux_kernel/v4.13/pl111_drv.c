static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
F_2 ( V_2 ) ;
V_4 = & V_2 -> V_4 ;
V_4 -> V_9 = & V_10 ;
V_4 -> V_11 = 1 ;
V_4 -> V_12 = 1024 ;
V_4 -> V_13 = 1 ;
V_4 -> V_14 = 768 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_2 , L_1 ) ;
goto V_15;
}
if ( ! V_6 -> V_16 . V_17 ) {
F_5 ( V_2 -> V_2 ,
L_2 ) ;
V_8 = - V_18 ;
goto V_15;
}
V_8 = F_6 ( V_2 ) ;
if ( V_8 != 0 ) {
F_4 ( V_2 -> V_2 , L_3 ) ;
goto V_15;
}
V_8 = F_7 ( V_2 , 1 ) ;
if ( V_8 != 0 ) {
F_4 ( V_2 -> V_2 , L_4 ) ;
goto V_15;
}
F_8 ( V_2 ) ;
V_6 -> V_19 = F_9 ( V_2 , 32 ,
V_2 -> V_4 . V_20 ) ;
F_10 ( V_2 ) ;
goto V_21;
V_15:
F_11 ( V_2 ) ;
V_21:
return V_8 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_13 ( V_6 -> V_19 ) ;
}
static int F_14 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_2 = & V_23 -> V_2 ;
struct V_5 * V_6 ;
struct V_1 * V_27 ;
int V_8 ;
V_6 = F_15 ( V_2 , sizeof( * V_6 ) , V_28 ) ;
if ( ! V_6 )
return - V_29 ;
V_27 = F_16 ( & V_30 , V_2 ) ;
if ( F_17 ( V_27 ) )
return F_18 ( V_27 ) ;
F_19 ( V_23 , V_27 ) ;
V_6 -> V_27 = V_27 ;
V_27 -> V_7 = V_6 ;
V_6 -> V_31 = F_20 ( V_2 , & V_23 -> V_32 ) ;
if ( F_17 ( V_6 -> V_31 ) ) {
F_4 ( V_2 , L_5 , V_33 ) ;
return F_18 ( V_6 -> V_31 ) ;
}
F_21 ( 0 , V_6 -> V_31 + V_34 ) ;
V_8 = F_22 ( V_2 , V_23 -> V_35 [ 0 ] , V_36 , 0 ,
L_6 , V_6 ) ;
if ( V_8 != 0 ) {
F_4 ( V_2 , L_7 , V_33 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_27 ) ;
if ( V_8 != 0 )
goto V_37;
V_8 = F_23 ( V_27 , 0 ) ;
if ( V_8 < 0 )
goto V_37;
return 0 ;
V_37:
F_24 ( V_27 ) ;
return V_8 ;
}
static int F_25 ( struct V_22 * V_23 )
{
struct V_1 * V_27 = F_26 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_7 ;
F_27 ( V_27 ) ;
if ( V_6 -> V_19 )
F_28 ( V_6 -> V_19 ) ;
F_11 ( V_27 ) ;
F_24 ( V_27 ) ;
return 0 ;
}
