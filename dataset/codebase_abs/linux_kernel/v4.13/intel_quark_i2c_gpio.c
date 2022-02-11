static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
V_6 = F_3 ( V_2 ,
V_7 , NULL ,
0 , V_8 ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
V_4 -> V_6 = V_6 ;
V_4 -> V_9 = F_6 ( V_6 , NULL ,
V_7 ) ;
if ( ! V_4 -> V_9 ) {
F_7 ( V_4 -> V_6 ) ;
F_8 ( V_2 , L_1 ) ;
return - V_10 ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_9 )
return;
F_10 ( V_4 -> V_9 ) ;
F_7 ( V_4 -> V_6 ) ;
}
static int F_11 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
const struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 = (struct V_19 * ) V_14 -> V_21 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
V_20 [ V_22 ] . V_23 =
F_12 ( V_12 , V_24 ) ;
V_20 [ V_22 ] . V_25 =
F_13 ( V_12 , V_24 ) ;
V_20 [ V_26 ] . V_23 = V_12 -> V_27 ;
V_20 [ V_26 ] . V_25 = V_12 -> V_27 ;
V_18 = F_14 ( V_2 , sizeof( * V_18 ) , V_28 ) ;
if ( ! V_18 )
return - V_10 ;
V_18 -> V_29 = 100000 ;
V_16 = F_15 ( V_30 ) ;
if ( V_16 )
V_18 -> V_29 = ( V_31 ) V_16 -> V_32 ;
V_14 -> V_33 = V_18 ;
V_14 -> V_34 = sizeof( * V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_35 * V_18 ;
struct V_19 * V_20 = (struct V_19 * ) V_14 -> V_21 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
V_20 [ V_22 ] . V_23 =
F_12 ( V_12 , V_36 ) ;
V_20 [ V_22 ] . V_25 =
F_13 ( V_12 , V_36 ) ;
V_18 = F_14 ( V_2 , sizeof( * V_18 ) , V_28 ) ;
if ( ! V_18 )
return - V_10 ;
V_18 -> V_37 = V_38 ;
V_18 -> V_39 = F_17 ( V_2 , V_18 -> V_37 ,
sizeof( * V_18 -> V_39 ) ,
V_28 ) ;
if ( ! V_18 -> V_39 )
return - V_10 ;
V_18 -> V_39 -> V_40 = NULL ;
V_18 -> V_39 -> V_41 = 0 ;
V_18 -> V_39 -> V_42 = V_43 ;
V_18 -> V_39 -> V_44 = V_45 ;
V_18 -> V_39 -> V_27 = V_12 -> V_27 ;
V_18 -> V_39 -> V_46 = true ;
V_14 -> V_33 = V_18 ;
V_14 -> V_34 = sizeof( * V_18 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 ,
const struct V_47 * V_48 )
{
struct V_3 * V_4 ;
int V_49 ;
V_49 = F_19 ( V_12 ) ;
if ( V_49 )
return V_49 ;
V_4 = F_14 ( & V_12 -> V_2 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return - V_10 ;
V_4 -> V_2 = & V_12 -> V_2 ;
F_20 ( & V_12 -> V_2 , V_4 ) ;
V_49 = F_1 ( & V_12 -> V_2 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_11 ( V_12 , & V_50 [ 1 ] ) ;
if ( V_49 )
goto V_51;
V_49 = F_16 ( V_12 , & V_50 [ 0 ] ) ;
if ( V_49 )
goto V_51;
V_49 = F_21 ( & V_12 -> V_2 , 0 , V_50 ,
F_22 ( V_50 ) , NULL , 0 ,
NULL ) ;
if ( V_49 )
goto V_51;
return 0 ;
V_51:
F_9 ( & V_12 -> V_2 ) ;
return V_49 ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_9 ( & V_12 -> V_2 ) ;
F_24 ( & V_12 -> V_2 ) ;
}
