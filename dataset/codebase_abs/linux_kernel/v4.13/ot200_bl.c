static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_2 -> V_6 . V_5 ;
if ( V_2 -> V_6 . V_7 & V_8 )
V_5 = 0 ;
if ( V_5 == 0 )
F_3 ( V_9 , V_10 , 0 ) ;
else if ( V_4 -> V_11 == 0 ) {
F_3 ( V_9 , V_12 , 0 ) ;
F_3 ( V_9 , V_10 ,
V_13 ) ;
}
F_3 ( V_9 , V_14 ,
V_15 - V_16 [ V_5 ] ) ;
V_4 -> V_11 = V_5 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_11 ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_19 V_6 ;
int V_20 = 0 ;
if ( F_6 ( & V_18 -> V_21 , V_22 ,
L_1 ) < 0 ) {
F_7 ( & V_18 -> V_21 , L_2 , V_22 ) ;
return - V_23 ;
}
V_9 = F_8 ( 7 , V_24 ) ;
if ( ! V_9 ) {
F_7 ( & V_18 -> V_21 , L_3 ) ;
return - V_23 ;
}
V_4 = F_9 ( & V_18 -> V_21 , sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 ) {
V_20 = - V_26 ;
goto V_27;
}
F_10 ( V_22 , V_28 ) ;
F_10 ( V_22 , V_29 ) ;
F_3 ( V_9 , V_14 , 0 ) ;
F_3 ( V_9 , V_30 , V_15 ) ;
F_3 ( V_9 , V_10 , V_31 ) ;
V_4 -> V_11 = 100 ;
V_6 . V_32 = 100 ;
V_6 . V_5 = 100 ;
V_6 . type = V_33 ;
V_2 = F_11 ( & V_18 -> V_21 , F_12 ( & V_18 -> V_21 ) ,
& V_18 -> V_21 , V_4 , & V_34 ,
& V_6 ) ;
if ( F_13 ( V_2 ) ) {
F_7 ( & V_18 -> V_21 , L_4 ) ;
V_20 = F_14 ( V_2 ) ;
goto V_27;
}
F_15 ( V_18 , V_2 ) ;
return 0 ;
V_27:
F_16 ( V_9 ) ;
return V_20 ;
}
static int F_17 ( struct V_17 * V_18 )
{
F_3 ( V_9 , V_12 , 0 ) ;
F_3 ( V_9 , V_10 , V_13 ) ;
F_3 ( V_9 , V_14 ,
V_15 - V_16 [ 100 ] ) ;
F_16 ( V_9 ) ;
return 0 ;
}
