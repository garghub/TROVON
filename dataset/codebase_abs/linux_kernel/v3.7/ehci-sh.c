static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_4 -> V_6 = V_2 -> V_7 ;
V_5 = F_3 ( V_2 ) ;
if ( F_4 ( V_5 ) )
return V_5 ;
F_5 ( V_4 , 0 ) ;
return V_5 ;
}
static int F_6 ( struct V_8 * V_9 )
{
const struct V_10 * V_11 = & V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_19 , V_5 ;
if ( F_7 () )
return - V_20 ;
V_14 = F_8 ( V_9 , V_21 , 0 ) ;
if ( ! V_14 ) {
F_9 ( & V_9 -> V_22 ,
L_1 ,
F_10 ( & V_9 -> V_22 ) ) ;
V_5 = - V_20 ;
goto V_23;
}
V_19 = F_11 ( V_9 , 0 ) ;
if ( V_19 <= 0 ) {
F_9 ( & V_9 -> V_22 ,
L_2 ,
F_10 ( & V_9 -> V_22 ) ) ;
V_5 = - V_20 ;
goto V_23;
}
V_18 = V_9 -> V_22 . V_24 ;
V_2 = F_12 ( & V_12 , & V_9 -> V_22 ,
F_10 ( & V_9 -> V_22 ) ) ;
if ( ! V_2 ) {
V_5 = - V_25 ;
goto V_23;
}
V_2 -> V_26 = V_14 -> V_27 ;
V_2 -> V_28 = F_13 ( V_14 ) ;
V_2 -> V_7 = F_14 ( & V_9 -> V_22 , V_14 ) ;
if ( V_2 -> V_7 == NULL ) {
F_15 ( & V_9 -> V_22 , L_3 ) ;
V_5 = - V_29 ;
goto V_30;
}
V_16 = F_16 ( & V_9 -> V_22 , sizeof( struct V_15 ) ,
V_31 ) ;
if ( ! V_16 ) {
F_15 ( & V_9 -> V_22 , L_4 ) ;
V_5 = - V_25 ;
goto V_30;
}
V_16 -> V_32 = F_17 ( & V_9 -> V_22 , L_5 ) ;
if ( F_18 ( V_16 -> V_32 ) )
V_16 -> V_32 = NULL ;
V_16 -> V_33 = F_17 ( & V_9 -> V_22 , L_6 ) ;
if ( F_18 ( V_16 -> V_33 ) )
V_16 -> V_33 = NULL ;
F_19 ( V_16 -> V_32 ) ;
F_19 ( V_16 -> V_33 ) ;
if ( V_18 && V_18 -> V_34 )
V_18 -> V_34 () ;
V_5 = F_20 ( V_2 , V_19 , V_35 ) ;
if ( V_5 != 0 ) {
F_9 ( & V_9 -> V_22 , L_7 ) ;
goto V_36;
}
V_16 -> V_2 = V_2 ;
F_21 ( V_9 , V_16 ) ;
return V_5 ;
V_36:
F_22 ( V_16 -> V_33 ) ;
F_22 ( V_16 -> V_32 ) ;
V_30:
F_23 ( V_2 ) ;
V_23:
F_9 ( & V_9 -> V_22 , L_8 , F_10 ( & V_9 -> V_22 ) , V_5 ) ;
return V_5 ;
}
static int T_1 F_24 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = F_25 ( V_9 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
F_26 ( V_2 ) ;
F_23 ( V_2 ) ;
F_21 ( V_9 , NULL ) ;
F_22 ( V_16 -> V_32 ) ;
F_22 ( V_16 -> V_33 ) ;
return 0 ;
}
static void F_27 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = F_25 ( V_9 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
if ( V_2 -> V_11 -> V_37 )
V_2 -> V_11 -> V_37 ( V_2 ) ;
}
