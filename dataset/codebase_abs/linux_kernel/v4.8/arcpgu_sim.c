static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 , V_5 ) ;
F_3 ( V_2 , V_6 , V_7 ) ;
return V_3 ;
}
static enum V_8
F_4 ( struct V_1 * V_2 , bool V_9 )
{
return V_10 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
int F_8 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_19 ;
V_18 = F_9 ( V_12 -> V_20 , sizeof( * V_18 ) , V_21 ) ;
if ( V_18 == NULL )
return - V_22 ;
V_18 -> V_23 . V_24 = 1 ;
V_18 -> V_23 . V_25 = 0 ;
V_19 = F_10 ( V_12 , & V_18 -> V_23 , & V_26 ,
V_27 , NULL ) ;
if ( V_19 )
return V_19 ;
V_16 = F_9 ( V_12 -> V_20 , sizeof( * V_16 ) ,
V_21 ) ;
if ( ! V_16 ) {
V_19 = - V_22 ;
goto V_28;
}
V_2 = & V_16 -> V_2 ;
F_11 ( V_2 , & V_29 ) ;
V_19 = F_12 ( V_12 , V_2 , & V_30 ,
V_31 ) ;
if ( V_19 < 0 ) {
F_13 ( V_12 -> V_20 , L_1 ) ;
goto V_28;
}
V_19 = F_14 ( V_2 , & V_18 -> V_23 ) ;
if ( V_19 < 0 ) {
F_13 ( V_12 -> V_20 , L_2 ) ;
F_6 ( V_2 ) ;
goto V_32;
}
V_16 -> V_33 = V_18 ;
return 0 ;
V_32:
F_7 ( V_2 ) ;
V_28:
F_15 ( & V_18 -> V_23 ) ;
return V_19 ;
}
