static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_6 = F_2 ( & V_4 -> V_10 , V_11 ,
sizeof( * V_6 ) , V_12 ) ;
if ( ! V_6 )
return - V_13 ;
V_6 [ 0 ] . V_14 = V_15 ;
V_8 = F_3 ( & V_4 -> V_10 ,
V_15 , NULL ,
V_16 , V_17 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = V_8 ;
V_9 = F_4 ( V_8 , V_6 ,
V_11 ) ;
if ( V_9 )
F_5 ( & V_4 -> V_10 , L_1 , V_9 ) ;
return V_9 ;
}
static void F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( & V_4 -> V_10 ) ;
if ( ! V_2 -> V_8 || ! V_2 -> V_6 )
return;
F_8 ( V_2 -> V_6 ) ;
F_9 ( V_2 -> V_8 ) ;
}
static int F_10 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
const char * V_20 = F_11 ( V_21 ) ;
const struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 = (struct V_26 * ) V_19 -> V_28 ;
struct V_29 * V_10 = & V_4 -> V_10 ;
V_27 [ V_30 ] . V_31 =
F_12 ( V_4 , V_32 ) ;
V_27 [ V_30 ] . V_33 =
F_13 ( V_4 , V_32 ) ;
V_27 [ V_34 ] . V_31 = V_4 -> V_35 ;
V_27 [ V_34 ] . V_33 = V_4 -> V_35 ;
V_25 = F_14 ( V_10 , sizeof( * V_25 ) , V_12 ) ;
if ( ! V_25 )
return - V_13 ;
V_25 -> V_36 = 100000 ;
if ( V_20 ) {
for ( V_23 = V_37 ; V_23 -> V_38 ; V_23 ++ ) {
if ( ! strcmp ( V_20 , V_23 -> V_38 ) ) {
V_25 -> V_36 = V_23 -> V_36 ;
break;
}
}
}
V_19 -> V_39 = V_25 ;
V_19 -> V_40 = sizeof( * V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , struct V_18 * V_19 )
{
struct V_41 * V_25 ;
struct V_26 * V_27 = (struct V_26 * ) V_19 -> V_28 ;
struct V_29 * V_10 = & V_4 -> V_10 ;
V_27 [ V_30 ] . V_31 =
F_12 ( V_4 , V_42 ) ;
V_27 [ V_30 ] . V_33 =
F_13 ( V_4 , V_42 ) ;
V_25 = F_14 ( V_10 , sizeof( * V_25 ) , V_12 ) ;
if ( ! V_25 )
return - V_13 ;
V_25 -> V_43 = V_44 ;
V_25 -> V_45 = F_2 ( V_10 , V_25 -> V_43 ,
sizeof( * V_25 -> V_45 ) ,
V_12 ) ;
if ( ! V_25 -> V_45 )
return - V_13 ;
V_25 -> V_45 -> V_46 = NULL ;
V_25 -> V_45 -> V_38 = L_2 ;
V_25 -> V_45 -> V_47 = 0 ;
V_25 -> V_45 -> V_48 = V_49 ;
V_25 -> V_45 -> V_50 = V_51 ;
V_25 -> V_45 -> V_35 = V_4 -> V_35 ;
V_25 -> V_45 -> V_52 = true ;
V_19 -> V_39 = V_25 ;
V_19 -> V_40 = sizeof( * V_25 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 ,
const struct V_53 * V_54 )
{
struct V_1 * V_2 ;
int V_9 ;
V_9 = F_17 ( V_4 ) ;
if ( V_9 )
return V_9 ;
V_2 = F_14 ( & V_4 -> V_10 , sizeof( * V_2 ) , V_12 ) ;
if ( ! V_2 )
return - V_13 ;
V_2 -> V_4 = V_4 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 )
return V_9 ;
F_18 ( & V_4 -> V_10 , V_2 ) ;
V_9 = F_10 ( V_4 , & V_55 [ 1 ] ) ;
if ( V_9 )
return V_9 ;
V_9 = F_15 ( V_4 , & V_55 [ 0 ] ) ;
if ( V_9 )
return V_9 ;
return F_19 ( & V_4 -> V_10 , 0 , V_55 ,
F_20 ( V_55 ) , NULL , 0 ,
NULL ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
F_6 ( V_4 ) ;
F_22 ( & V_4 -> V_10 ) ;
}
