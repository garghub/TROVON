static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( & V_4 -> V_7 ,
V_8 , NULL ,
V_9 , V_10 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_11 = F_5 ( V_6 , NULL ,
V_8 ) ;
if ( ! V_2 -> V_11 ) {
F_6 ( & V_4 -> V_7 , L_1 ) ;
return - V_12 ;
}
return 0 ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_8 ( & V_4 -> V_7 ) ;
if ( ! V_2 -> V_6 || ! V_2 -> V_11 )
return;
F_9 ( V_2 -> V_11 ) ;
F_10 ( V_2 -> V_6 ) ;
}
static int F_11 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
const char * V_15 = F_12 ( V_16 ) ;
const struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) V_14 -> V_23 ;
struct V_24 * V_7 = & V_4 -> V_7 ;
V_22 [ V_25 ] . V_26 =
F_13 ( V_4 , V_27 ) ;
V_22 [ V_25 ] . V_28 =
F_14 ( V_4 , V_27 ) ;
V_22 [ V_29 ] . V_26 = V_4 -> V_30 ;
V_22 [ V_29 ] . V_28 = V_4 -> V_30 ;
V_20 = F_15 ( V_7 , sizeof( * V_20 ) , V_31 ) ;
if ( ! V_20 )
return - V_12 ;
V_20 -> V_32 = 100000 ;
if ( V_15 ) {
for ( V_18 = V_33 ; V_18 -> V_34 ; V_18 ++ ) {
if ( ! strcmp ( V_15 , V_18 -> V_34 ) ) {
V_20 -> V_32 = V_18 -> V_32 ;
break;
}
}
}
V_14 -> V_35 = V_20 ;
V_14 -> V_36 = sizeof( * V_20 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
struct V_37 * V_20 ;
struct V_21 * V_22 = (struct V_21 * ) V_14 -> V_23 ;
struct V_24 * V_7 = & V_4 -> V_7 ;
V_22 [ V_25 ] . V_26 =
F_13 ( V_4 , V_38 ) ;
V_22 [ V_25 ] . V_28 =
F_14 ( V_4 , V_38 ) ;
V_20 = F_15 ( V_7 , sizeof( * V_20 ) , V_31 ) ;
if ( ! V_20 )
return - V_12 ;
V_20 -> V_39 = V_40 ;
V_20 -> V_41 = F_17 ( V_7 , V_20 -> V_39 ,
sizeof( * V_20 -> V_41 ) ,
V_31 ) ;
if ( ! V_20 -> V_41 )
return - V_12 ;
V_20 -> V_41 -> V_42 = NULL ;
V_20 -> V_41 -> V_34 = L_2 ;
V_20 -> V_41 -> V_43 = 0 ;
V_20 -> V_41 -> V_44 = V_45 ;
V_20 -> V_41 -> V_46 = V_47 ;
V_20 -> V_41 -> V_30 = V_4 -> V_30 ;
V_20 -> V_41 -> V_48 = true ;
V_14 -> V_35 = V_20 ;
V_14 -> V_36 = sizeof( * V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 ,
const struct V_49 * V_50 )
{
struct V_1 * V_2 ;
int V_51 ;
V_51 = F_19 ( V_4 ) ;
if ( V_51 )
return V_51 ;
V_2 = F_15 ( & V_4 -> V_7 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_12 ;
V_2 -> V_4 = V_4 ;
V_51 = F_1 ( V_2 ) ;
if ( V_51 )
return V_51 ;
F_20 ( & V_4 -> V_7 , V_2 ) ;
V_51 = F_11 ( V_4 , & V_52 [ 1 ] ) ;
if ( V_51 )
return V_51 ;
V_51 = F_16 ( V_4 , & V_52 [ 0 ] ) ;
if ( V_51 )
return V_51 ;
return F_21 ( & V_4 -> V_7 , 0 , V_52 ,
F_22 ( V_52 ) , NULL , 0 ,
NULL ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
F_7 ( V_4 ) ;
F_24 ( & V_4 -> V_7 ) ;
}
