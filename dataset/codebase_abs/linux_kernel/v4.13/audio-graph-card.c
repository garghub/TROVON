static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 -> V_10 ) ;
switch ( V_5 ) {
case V_11 :
F_3 ( V_9 -> V_12 , 1 ) ;
break;
case V_13 :
F_3 ( V_9 -> V_12 , 0 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_8 * V_9 = F_2 ( V_18 -> V_10 ) ;
struct V_20 * V_21 = F_5 ( V_9 , V_18 -> V_22 ) ;
int V_23 ;
V_23 = F_6 ( & V_21 -> V_24 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_6 ( & V_21 -> V_25 ) ;
if ( V_23 )
F_7 ( & V_21 -> V_24 ) ;
return V_23 ;
}
static void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_8 * V_9 = F_2 ( V_18 -> V_10 ) ;
struct V_20 * V_21 = F_5 ( V_9 , V_18 -> V_22 ) ;
F_7 ( & V_21 -> V_24 ) ;
F_7 ( & V_21 -> V_25 ) ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_8 * V_9 = F_2 ( V_18 -> V_10 ) ;
struct V_26 * V_27 = V_18 -> V_25 ;
struct V_26 * V_28 = V_18 -> V_24 ;
struct V_20 * V_21 =
F_5 ( V_9 , V_18 -> V_22 ) ;
int V_23 ;
V_23 = F_10 ( V_27 , & V_21 -> V_25 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_10 ( V_28 , & V_21 -> V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static int F_11 ( struct V_29 * V_30 ,
struct V_8 * V_9 ,
int V_31 )
{
struct V_32 * V_33 = F_12 ( V_9 ) ;
struct V_34 * V_35 = F_13 ( V_9 , V_31 ) ;
struct V_20 * V_21 = F_5 ( V_9 , V_31 ) ;
struct V_36 * V_24 = & V_21 -> V_24 ;
struct V_36 * V_25 = & V_21 -> V_25 ;
struct V_29 * V_37 = F_14 ( V_30 , NULL ) ;
struct V_29 * V_38 = F_15 ( V_37 ) ;
struct V_29 * V_39 = F_15 ( V_38 ) ;
int V_23 ;
if ( V_39 != V_37 ) {
F_16 ( V_33 , L_1 ,
V_37 -> V_40 , V_38 -> V_40 , V_39 -> V_40 ) ;
V_23 = - V_14 ;
goto V_41;
}
V_23 = F_17 ( V_33 , V_37 , V_38 ,
NULL , & V_35 -> V_42 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_18 ( V_37 , V_35 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_19 ( V_38 , V_35 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_20 ( V_37 , V_24 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_20 ( V_38 , V_25 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_21 ( V_33 , V_37 , V_35 , V_24 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_22 ( V_33 , V_38 , V_35 , V_25 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_23 ( V_35 ) ;
if ( V_23 < 0 )
goto V_41;
V_23 = F_24 ( V_33 , V_35 ,
L_2 ,
V_35 -> V_43 ,
V_35 -> V_44 ) ;
if ( V_23 < 0 )
goto V_41;
V_35 -> V_45 = & V_46 ;
V_35 -> V_47 = F_9 ;
F_25 ( V_35 ,
F_26 ( V_35 -> V_48 ) == 1 ) ;
V_41:
F_27 ( V_37 ) ;
F_27 ( V_39 ) ;
F_27 ( V_38 ) ;
return V_23 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_49 V_50 ;
struct V_32 * V_33 = F_12 ( V_9 ) ;
struct V_51 * V_10 = F_29 ( V_9 ) ;
struct V_29 * V_52 = V_33 -> V_53 ;
int V_54 , V_31 = 0 ;
int V_23 ;
V_23 = F_30 ( V_10 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_31 ( V_10 , NULL , 1 ) ;
if ( V_23 < 0 )
return V_23 ;
F_32 (&it, rc, node, L_3 , NULL, 0 ) {
V_23 = F_11 ( V_50 . V_52 , V_9 , V_31 ++ ) ;
if ( V_23 < 0 ) {
F_27 ( V_50 . V_52 ) ;
return V_23 ;
}
}
return F_33 ( V_10 , NULL ) ;
}
static int F_34 ( struct V_32 * V_33 )
{
struct V_49 V_50 ;
struct V_29 * V_52 = V_33 -> V_53 ;
int V_55 = 0 ;
int V_54 ;
F_32 (&it, rc, node, L_3 , NULL, 0 )
V_55 ++ ;
return V_55 ;
}
static int F_35 ( struct V_56 * V_57 )
{
struct V_8 * V_9 ;
struct V_34 * V_35 ;
struct V_20 * V_21 ;
struct V_32 * V_33 = & V_57 -> V_33 ;
struct V_51 * V_10 ;
int V_22 , V_23 ;
V_9 = F_36 ( V_33 , sizeof( * V_9 ) , V_58 ) ;
if ( ! V_9 )
return - V_59 ;
V_22 = F_34 ( V_33 ) ;
if ( V_22 == 0 )
return - V_14 ;
V_21 = F_36 ( V_33 , sizeof( * V_21 ) * V_22 , V_58 ) ;
V_35 = F_36 ( V_33 , sizeof( * V_35 ) * V_22 , V_58 ) ;
if ( ! V_21 || ! V_35 )
return - V_59 ;
V_9 -> V_12 = F_37 ( V_33 , L_4 , V_60 ) ;
if ( F_38 ( V_9 -> V_12 ) ) {
V_23 = F_39 ( V_9 -> V_12 ) ;
F_16 ( V_33 , L_5 , V_23 ) ;
return V_23 ;
}
V_9 -> V_21 = V_21 ;
V_9 -> V_35 = V_35 ;
V_10 = F_29 ( V_9 ) ;
V_10 -> V_61 = V_62 ;
V_10 -> V_33 = V_33 ;
V_10 -> V_35 = V_35 ;
V_10 -> V_63 = V_22 ;
V_10 -> V_64 = V_65 ;
V_10 -> V_66 = F_40 ( V_65 ) ;
V_23 = F_28 ( V_9 ) ;
if ( V_23 < 0 ) {
if ( V_23 != - V_67 )
F_16 ( V_33 , L_6 , V_23 ) ;
goto V_68;
}
F_41 ( V_10 , V_9 ) ;
V_23 = F_42 ( V_33 , V_10 ) ;
if ( V_23 < 0 )
goto V_68;
return 0 ;
V_68:
F_43 ( V_10 ) ;
return V_23 ;
}
static int F_44 ( struct V_56 * V_57 )
{
struct V_51 * V_10 = F_45 ( V_57 ) ;
return F_43 ( V_10 ) ;
}
