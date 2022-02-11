static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = F_3 ( V_2 ) ;
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = NULL ;
V_4 -> V_11 = NULL ;
V_4 -> V_12 = NULL ;
V_8 ( V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_17 ;
if ( F_5 () )
return - V_18 ;
V_17 = F_6 ( & V_14 -> V_19 , F_7 ( 32 ) ) ;
if ( V_17 )
return V_17 ;
V_2 = F_8 ( & V_20 , & V_14 -> V_19 ,
V_14 -> V_21 ) ;
if ( ! V_2 )
return - V_22 ;
V_16 = F_9 ( V_14 , V_23 , 0 ) ;
V_2 -> V_24 = V_16 -> V_25 ;
V_2 -> V_26 = F_10 ( V_16 ) ;
V_2 -> V_27 = F_11 ( & V_14 -> V_19 , V_16 ) ;
if ( F_12 ( V_2 -> V_27 ) ) {
V_17 = F_13 ( V_2 -> V_27 ) ;
goto V_28;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_27 = V_2 -> V_27 ;
V_17 = F_14 ( V_2 , V_14 -> V_15 [ 1 ] . V_25 , V_29 ) ;
if ( V_17 )
goto V_28;
F_15 ( V_2 -> V_30 . V_31 ) ;
return 0 ;
V_28:
F_16 ( V_2 ) ;
return V_17 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_18 ( V_14 ) ;
F_19 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_20 ( struct V_13 * V_32 )
{
struct V_1 * V_2 = F_18 ( V_32 ) ;
F_21 ( F_2 ( V_2 ) ) ;
}
