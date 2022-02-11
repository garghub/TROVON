static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( F_3 ( V_2 ) ,
struct V_3 ,
V_5 ) ;
T_1 V_6 = 0 ;
int V_7 , V_8 ;
int V_9 ;
V_7 = F_4 ( V_4 -> V_10 , & V_8 ) ;
if ( V_7 < 0 ) {
F_5 ( V_4 -> V_11 . V_12 , L_1 , V_7 ) ;
return;
}
for ( V_9 = 0 ; V_9 < V_4 -> V_13 ; V_9 ++ ) {
struct V_14 * V_15 = & V_4 -> V_16 [ V_9 ] ;
if ( ! V_15 -> V_6 )
break;
if ( V_15 -> V_17 <= V_8 && V_15 -> V_18 >= V_8 ) {
V_6 = V_15 -> V_6 ;
break;
}
}
F_6 ( & V_4 -> V_11 , V_6 ) ;
}
static T_2 F_7 ( int V_19 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
F_8 ( & V_4 -> V_5 , V_4 -> V_21 ) ;
return V_22 ;
}
static int T_3 F_9 ( struct V_23 * V_24 )
{
struct V_3 * V_4 ;
struct V_25 * V_26 = V_24 -> V_12 . V_27 ;
int V_9 , V_28 = 0 ;
V_4 = F_10 ( & V_24 -> V_12 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_11 . V_31 = V_26 -> V_31 ;
if ( ! V_26 -> V_32 ) {
V_28 = - V_33 ;
F_5 ( & V_24 -> V_12 , L_2 ) ;
goto V_34;
}
V_4 -> V_11 . V_35 = V_26 -> V_32 ;
for ( V_9 = 0 ; V_4 -> V_11 . V_35 [ V_9 ] ; V_9 ++ )
;
if ( V_9 == 0 || V_9 > V_36 ) {
V_28 = - V_33 ;
F_5 ( & V_24 -> V_12 , L_3 ,
V_9 - 1 ) ;
goto V_34;
}
V_4 -> V_37 = V_9 ;
if ( ! V_26 -> V_16 ||
! V_26 -> V_16 [ 0 ] . V_6 ) {
V_28 = - V_33 ;
F_5 ( & V_24 -> V_12 , L_4 ) ;
goto V_34;
}
V_4 -> V_16 = V_26 -> V_16 ;
for ( V_9 = 0 ; V_4 -> V_16 [ V_9 ] . V_6 ; V_9 ++ )
;
V_4 -> V_13 = V_9 ;
V_4 -> V_10 = F_11 ( F_12 ( & V_24 -> V_12 ) ,
V_26 -> V_38 ) ;
if ( F_13 ( V_4 -> V_10 ) ) {
V_28 = F_14 ( V_4 -> V_10 ) ;
goto V_34;
}
V_4 -> V_21 = F_15 ( V_26 -> V_39 ) ;
F_16 ( & V_4 -> V_5 , F_1 ) ;
F_17 ( V_24 , V_4 ) ;
V_28 = F_18 ( & V_4 -> V_11 , & V_24 -> V_12 ) ;
if ( V_28 )
goto V_34;
V_4 -> V_19 = F_19 ( V_24 , 0 ) ;
if ( ! V_4 -> V_19 ) {
F_5 ( & V_24 -> V_12 , L_5 ) ;
V_28 = - V_40 ;
goto V_41;
}
V_28 = F_20 ( V_4 -> V_19 , F_7 ,
V_26 -> V_42 , V_26 -> V_31 , V_4 ) ;
if ( V_28 < 0 ) {
F_5 ( & V_24 -> V_12 , L_6 , V_4 -> V_19 ) ;
goto V_41;
}
return 0 ;
V_41:
F_21 ( & V_4 -> V_11 ) ;
V_34:
return V_28 ;
}
static int T_4 F_22 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = F_23 ( V_24 ) ;
F_24 ( V_4 -> V_19 , V_4 ) ;
F_25 ( & V_4 -> V_5 . V_2 ) ;
F_21 ( & V_4 -> V_11 ) ;
return 0 ;
}
