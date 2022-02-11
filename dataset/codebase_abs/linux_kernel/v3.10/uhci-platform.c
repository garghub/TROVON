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
if ( ! V_14 -> V_19 . V_20 )
V_14 -> V_19 . V_20 = & V_14 -> V_19 . V_21 ;
if ( ! V_14 -> V_19 . V_21 )
V_14 -> V_19 . V_21 = F_6 ( 32 ) ;
V_2 = F_7 ( & V_22 , & V_14 -> V_19 ,
V_14 -> V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_16 = F_8 ( V_14 , V_25 , 0 ) ;
V_2 -> V_26 = V_16 -> V_27 ;
V_2 -> V_28 = F_9 ( V_16 ) ;
if ( ! F_10 ( V_2 -> V_26 , V_2 -> V_28 , V_29 ) ) {
F_11 ( L_1 , V_30 ) ;
V_17 = - V_31 ;
goto V_32;
}
V_2 -> V_33 = F_12 ( V_2 -> V_26 , V_2 -> V_28 ) ;
if ( ! V_2 -> V_33 ) {
F_11 ( L_2 , V_30 ) ;
V_17 = - V_24 ;
goto V_34;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_33 = V_2 -> V_33 ;
V_17 = F_13 ( V_2 , V_14 -> V_15 [ 1 ] . V_27 , V_35 |
V_36 ) ;
if ( V_17 )
goto V_37;
return 0 ;
V_37:
F_14 ( V_2 -> V_33 ) ;
V_34:
F_15 ( V_2 -> V_26 , V_2 -> V_28 ) ;
V_32:
F_16 ( V_2 ) ;
return V_17 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_18 ( V_14 ) ;
F_19 ( V_2 ) ;
F_14 ( V_2 -> V_33 ) ;
F_15 ( V_2 -> V_26 , V_2 -> V_28 ) ;
F_16 ( V_2 ) ;
F_20 ( V_14 , NULL ) ;
return 0 ;
}
static void F_21 ( struct V_13 * V_38 )
{
struct V_1 * V_2 = F_22 ( & V_38 -> V_19 ) ;
F_23 ( F_2 ( V_2 ) ) ;
}
