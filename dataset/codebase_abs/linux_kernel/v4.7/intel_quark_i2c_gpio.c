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
const char * V_15 = F_12 ( V_16 ) ;
const struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) V_14 -> V_23 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
V_22 [ V_24 ] . V_25 =
F_13 ( V_12 , V_26 ) ;
V_22 [ V_24 ] . V_27 =
F_14 ( V_12 , V_26 ) ;
V_22 [ V_28 ] . V_25 = V_12 -> V_29 ;
V_22 [ V_28 ] . V_27 = V_12 -> V_29 ;
V_20 = F_15 ( V_2 , sizeof( * V_20 ) , V_30 ) ;
if ( ! V_20 )
return - V_10 ;
V_20 -> V_31 = 100000 ;
if ( V_15 ) {
for ( V_18 = V_32 ; V_18 -> V_33 ; V_18 ++ ) {
if ( ! strcmp ( V_15 , V_18 -> V_33 ) ) {
V_20 -> V_31 = V_18 -> V_31 ;
break;
}
}
}
V_14 -> V_34 = V_20 ;
V_14 -> V_35 = sizeof( * V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_36 * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) V_14 -> V_23 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
V_22 [ V_24 ] . V_25 =
F_13 ( V_12 , V_37 ) ;
V_22 [ V_24 ] . V_27 =
F_14 ( V_12 , V_37 ) ;
V_20 = F_15 ( V_2 , sizeof( * V_20 ) , V_30 ) ;
if ( ! V_20 )
return - V_10 ;
V_20 -> V_38 = V_39 ;
V_20 -> V_40 = F_17 ( V_2 , V_20 -> V_38 ,
sizeof( * V_20 -> V_40 ) ,
V_30 ) ;
if ( ! V_20 -> V_40 )
return - V_10 ;
V_20 -> V_40 -> V_41 = NULL ;
V_20 -> V_40 -> V_42 = 0 ;
V_20 -> V_40 -> V_43 = V_44 ;
V_20 -> V_40 -> V_45 = V_46 ;
V_20 -> V_40 -> V_29 = V_12 -> V_29 ;
V_20 -> V_40 -> V_47 = true ;
V_14 -> V_34 = V_20 ;
V_14 -> V_35 = sizeof( * V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_12 ,
const struct V_48 * V_49 )
{
struct V_3 * V_4 ;
int V_50 ;
V_50 = F_19 ( V_12 ) ;
if ( V_50 )
return V_50 ;
V_4 = F_15 ( & V_12 -> V_2 , sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return - V_10 ;
V_4 -> V_2 = & V_12 -> V_2 ;
F_20 ( & V_12 -> V_2 , V_4 ) ;
V_50 = F_1 ( & V_12 -> V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_11 ( V_12 , & V_51 [ 1 ] ) ;
if ( V_50 )
goto V_52;
V_50 = F_16 ( V_12 , & V_51 [ 0 ] ) ;
if ( V_50 )
goto V_52;
V_50 = F_21 ( & V_12 -> V_2 , 0 , V_51 ,
F_22 ( V_51 ) , NULL , 0 ,
NULL ) ;
if ( V_50 )
goto V_52;
return 0 ;
V_52:
F_9 ( & V_12 -> V_2 ) ;
return V_50 ;
}
static void F_23 ( struct V_11 * V_12 )
{
F_9 ( & V_12 -> V_2 ) ;
F_24 ( & V_12 -> V_2 ) ;
}
