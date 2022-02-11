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
if ( F_13 ( V_2 -> V_6 ) ) {
V_19 = F_14 ( V_2 -> V_6 ) ;
goto V_29;
}
V_15 = F_15 ( & V_8 -> V_22 , sizeof( struct V_14 ) ,
V_30 ) ;
if ( ! V_15 ) {
F_16 ( & V_8 -> V_22 , L_3 ) ;
V_19 = - V_25 ;
goto V_29;
}
V_15 -> V_31 = F_17 ( & V_8 -> V_22 , L_4 ) ;
if ( F_13 ( V_15 -> V_31 ) )
V_15 -> V_31 = NULL ;
V_15 -> V_32 = F_17 ( & V_8 -> V_22 , L_5 ) ;
if ( F_13 ( V_15 -> V_32 ) )
V_15 -> V_32 = NULL ;
F_18 ( V_15 -> V_31 ) ;
F_18 ( V_15 -> V_32 ) ;
if ( V_17 && V_17 -> V_33 )
V_17 -> V_33 () ;
V_19 = F_19 ( V_2 , V_18 , V_34 ) ;
if ( V_19 != 0 ) {
F_7 ( & V_8 -> V_22 , L_6 ) ;
goto V_35;
}
V_15 -> V_2 = V_2 ;
F_20 ( V_8 , V_15 ) ;
return V_19 ;
V_35:
F_21 ( V_15 -> V_32 ) ;
F_21 ( V_15 -> V_31 ) ;
V_29:
F_22 ( V_2 ) ;
V_23:
F_7 ( & V_8 -> V_22 , L_7 , F_8 ( & V_8 -> V_22 ) , V_19 ) ;
return V_19 ;
}
static int T_1 F_23 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_24 ( V_8 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
F_25 ( V_2 ) ;
F_22 ( V_2 ) ;
F_20 ( V_8 , NULL ) ;
F_21 ( V_15 -> V_31 ) ;
F_21 ( V_15 -> V_32 ) ;
return 0 ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = F_24 ( V_8 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
if ( V_2 -> V_10 -> V_36 )
V_2 -> V_10 -> V_36 ( V_2 ) ;
}
