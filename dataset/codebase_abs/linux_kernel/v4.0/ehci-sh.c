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
V_15 = F_6 ( V_8 , 0 ) ;
if ( V_15 <= 0 ) {
F_7 ( & V_8 -> V_18 ,
L_1 ,
F_8 ( & V_8 -> V_18 ) ) ;
V_16 = - V_17 ;
goto V_19;
}
V_14 = F_9 ( & V_8 -> V_18 ) ;
V_2 = F_10 ( & V_20 , & V_8 -> V_18 ,
F_8 ( & V_8 -> V_18 ) ) ;
if ( ! V_2 ) {
V_16 = - V_21 ;
goto V_19;
}
V_10 = F_11 ( V_8 , V_22 , 0 ) ;
V_2 -> V_6 = F_12 ( & V_8 -> V_18 , V_10 ) ;
if ( F_13 ( V_2 -> V_6 ) ) {
V_16 = F_14 ( V_2 -> V_6 ) ;
goto V_23;
}
V_2 -> V_24 = V_10 -> V_25 ;
V_2 -> V_26 = F_15 ( V_10 ) ;
V_12 = F_16 ( & V_8 -> V_18 , sizeof( struct V_11 ) ,
V_27 ) ;
if ( ! V_12 ) {
V_16 = - V_21 ;
goto V_23;
}
V_12 -> V_28 = F_17 ( & V_8 -> V_18 , L_2 ) ;
if ( F_13 ( V_12 -> V_28 ) )
V_12 -> V_28 = NULL ;
V_12 -> V_29 = F_17 ( & V_8 -> V_18 , L_3 ) ;
if ( F_13 ( V_12 -> V_29 ) )
V_12 -> V_29 = NULL ;
F_18 ( V_12 -> V_28 ) ;
F_18 ( V_12 -> V_29 ) ;
if ( V_14 && V_14 -> V_30 )
V_14 -> V_30 () ;
V_16 = F_19 ( V_2 , V_15 , V_31 ) ;
if ( V_16 != 0 ) {
F_7 ( & V_8 -> V_18 , L_4 ) ;
goto V_32;
}
F_20 ( V_2 -> V_33 . V_34 ) ;
V_12 -> V_2 = V_2 ;
F_21 ( V_8 , V_12 ) ;
return V_16 ;
V_32:
F_22 ( V_12 -> V_29 ) ;
F_22 ( V_12 -> V_28 ) ;
V_23:
F_23 ( V_2 ) ;
V_19:
F_7 ( & V_8 -> V_18 , L_5 , F_8 ( & V_8 -> V_18 ) , V_16 ) ;
return V_16 ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_25 ( V_8 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
F_26 ( V_2 ) ;
F_23 ( V_2 ) ;
F_22 ( V_12 -> V_28 ) ;
F_22 ( V_12 -> V_29 ) ;
return 0 ;
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = F_25 ( V_8 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_2 -> V_35 -> V_36 )
V_2 -> V_35 -> V_36 ( V_2 ) ;
}
