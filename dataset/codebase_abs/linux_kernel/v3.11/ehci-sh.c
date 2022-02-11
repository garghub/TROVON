static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_2 -> V_6 ;
return F_3 ( V_2 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_15 , V_16 ;
if ( F_5 () )
return - V_17 ;
V_10 = F_6 ( V_8 , V_18 , 0 ) ;
if ( ! V_10 ) {
F_7 ( & V_8 -> V_19 ,
L_1 ,
F_8 ( & V_8 -> V_19 ) ) ;
V_16 = - V_17 ;
goto V_20;
}
V_15 = F_9 ( V_8 , 0 ) ;
if ( V_15 <= 0 ) {
F_7 ( & V_8 -> V_19 ,
L_2 ,
F_8 ( & V_8 -> V_19 ) ) ;
V_16 = - V_17 ;
goto V_20;
}
V_14 = V_8 -> V_19 . V_21 ;
V_2 = F_10 ( & V_22 , & V_8 -> V_19 ,
F_8 ( & V_8 -> V_19 ) ) ;
if ( ! V_2 ) {
V_16 = - V_23 ;
goto V_20;
}
V_2 -> V_24 = V_10 -> V_25 ;
V_2 -> V_26 = F_11 ( V_10 ) ;
V_2 -> V_6 = F_12 ( & V_8 -> V_19 , V_10 ) ;
if ( F_13 ( V_2 -> V_6 ) ) {
V_16 = F_14 ( V_2 -> V_6 ) ;
goto V_27;
}
V_12 = F_15 ( & V_8 -> V_19 , sizeof( struct V_11 ) ,
V_28 ) ;
if ( ! V_12 ) {
F_16 ( & V_8 -> V_19 , L_3 ) ;
V_16 = - V_23 ;
goto V_27;
}
V_12 -> V_29 = F_17 ( & V_8 -> V_19 , L_4 ) ;
if ( F_13 ( V_12 -> V_29 ) )
V_12 -> V_29 = NULL ;
V_12 -> V_30 = F_17 ( & V_8 -> V_19 , L_5 ) ;
if ( F_13 ( V_12 -> V_30 ) )
V_12 -> V_30 = NULL ;
F_18 ( V_12 -> V_29 ) ;
F_18 ( V_12 -> V_30 ) ;
if ( V_14 && V_14 -> V_31 )
V_14 -> V_31 () ;
V_16 = F_19 ( V_2 , V_15 , V_32 ) ;
if ( V_16 != 0 ) {
F_7 ( & V_8 -> V_19 , L_6 ) ;
goto V_33;
}
V_12 -> V_2 = V_2 ;
F_20 ( V_8 , V_12 ) ;
return V_16 ;
V_33:
F_21 ( V_12 -> V_30 ) ;
F_21 ( V_12 -> V_29 ) ;
V_27:
F_22 ( V_2 ) ;
V_20:
F_7 ( & V_8 -> V_19 , L_7 , F_8 ( & V_8 -> V_19 ) , V_16 ) ;
return V_16 ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_24 ( V_8 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_25 ( V_2 ) ;
F_22 ( V_2 ) ;
F_21 ( V_12 -> V_29 ) ;
F_21 ( V_12 -> V_30 ) ;
return 0 ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_24 ( V_8 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_2 -> V_34 -> V_35 )
V_2 -> V_34 -> V_35 ( V_2 ) ;
}
