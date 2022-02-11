static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_2 -> V_6 ;
return F_3 ( V_2 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
const struct V_9 * V_10 = & V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_18 , V_19 ;
if ( F_5 () )
return - V_20 ;
V_13 = F_6 ( V_8 , V_21 , 0 ) ;
if ( ! V_13 ) {
F_7 ( & V_8 -> V_22 ,
L_1 ,
F_8 ( & V_8 -> V_22 ) ) ;
V_19 = - V_20 ;
goto V_23;
}
V_18 = F_9 ( V_8 , 0 ) ;
if ( V_18 <= 0 ) {
F_7 ( & V_8 -> V_22 ,
L_2 ,
F_8 ( & V_8 -> V_22 ) ) ;
V_19 = - V_20 ;
goto V_23;
}
V_17 = V_8 -> V_22 . V_24 ;
V_2 = F_10 ( & V_11 , & V_8 -> V_22 ,
F_8 ( & V_8 -> V_22 ) ) ;
if ( ! V_2 ) {
V_19 = - V_25 ;
goto V_23;
}
V_2 -> V_26 = V_13 -> V_27 ;
V_2 -> V_28 = F_11 ( V_13 ) ;
V_2 -> V_6 = F_12 ( & V_8 -> V_22 , V_13 ) ;
if ( V_2 -> V_6 == NULL ) {
F_13 ( & V_8 -> V_22 , L_3 ) ;
V_19 = - V_29 ;
goto V_30;
}
V_15 = F_14 ( & V_8 -> V_22 , sizeof( struct V_14 ) ,
V_31 ) ;
if ( ! V_15 ) {
F_13 ( & V_8 -> V_22 , L_4 ) ;
V_19 = - V_25 ;
goto V_30;
}
V_15 -> V_32 = F_15 ( & V_8 -> V_22 , L_5 ) ;
if ( F_16 ( V_15 -> V_32 ) )
V_15 -> V_32 = NULL ;
V_15 -> V_33 = F_15 ( & V_8 -> V_22 , L_6 ) ;
if ( F_16 ( V_15 -> V_33 ) )
V_15 -> V_33 = NULL ;
F_17 ( V_15 -> V_32 ) ;
F_17 ( V_15 -> V_33 ) ;
if ( V_17 && V_17 -> V_34 )
V_17 -> V_34 () ;
V_19 = F_18 ( V_2 , V_18 , V_35 ) ;
if ( V_19 != 0 ) {
F_7 ( & V_8 -> V_22 , L_7 ) ;
goto V_36;
}
V_15 -> V_2 = V_2 ;
F_19 ( V_8 , V_15 ) ;
return V_19 ;
V_36:
F_20 ( V_15 -> V_33 ) ;
F_20 ( V_15 -> V_32 ) ;
V_30:
F_21 ( V_2 ) ;
V_23:
F_7 ( & V_8 -> V_22 , L_8 , F_8 ( & V_8 -> V_22 ) , V_19 ) ;
return V_19 ;
}
static int T_1 F_22 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_23 ( V_8 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_24 ( V_2 ) ;
F_21 ( V_2 ) ;
F_19 ( V_8 , NULL ) ;
F_20 ( V_15 -> V_32 ) ;
F_20 ( V_15 -> V_33 ) ;
return 0 ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_23 ( V_8 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_2 -> V_10 -> V_37 )
V_2 -> V_10 -> V_37 ( V_2 ) ;
}
