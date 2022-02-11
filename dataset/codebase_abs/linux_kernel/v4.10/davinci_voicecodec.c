static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = NULL ;
int V_8 ;
V_3 = F_2 ( & V_2 -> V_9 ,
sizeof( struct V_3 ) , V_10 ) ;
if ( ! V_3 )
return - V_11 ;
V_3 -> V_12 = F_3 ( & V_2 -> V_9 , NULL ) ;
if ( F_4 ( V_3 -> V_12 ) ) {
F_5 ( & V_2 -> V_9 ,
L_1 ) ;
return - V_13 ;
}
F_6 ( V_3 -> V_12 ) ;
V_5 = F_7 ( V_2 , V_14 , 0 ) ;
V_3 -> V_15 = F_8 ( & V_2 -> V_9 , V_5 ) ;
if ( F_4 ( V_3 -> V_15 ) ) {
V_8 = F_9 ( V_3 -> V_15 ) ;
goto V_16;
}
V_3 -> V_17 = F_10 ( & V_2 -> V_9 ,
V_3 -> V_15 ,
& V_18 ) ;
if ( F_4 ( V_3 -> V_17 ) ) {
V_8 = F_9 ( V_3 -> V_17 ) ;
goto V_16;
}
V_5 = F_7 ( V_2 , V_19 , 0 ) ;
if ( ! V_5 ) {
F_11 ( & V_2 -> V_9 , L_2 ) ;
V_8 = - V_20 ;
goto V_16;
}
V_3 -> V_21 . V_22 = V_5 -> V_23 ;
V_3 -> V_21 . V_24 =
( V_25 ) ( F_12 ( V_3 -> V_15 ) + V_26 ) ;
V_5 = F_7 ( V_2 , V_19 , 1 ) ;
if ( ! V_5 ) {
F_11 ( & V_2 -> V_9 , L_2 ) ;
V_8 = - V_20 ;
goto V_16;
}
V_3 -> V_21 . V_27 = V_5 -> V_23 ;
V_3 -> V_21 . V_28 =
( V_25 ) ( F_12 ( V_3 -> V_15 ) + V_29 ) ;
V_3 -> V_9 = & V_2 -> V_9 ;
V_3 -> V_2 = V_2 ;
V_7 = & V_3 -> V_30 [ V_31 ] ;
V_7 -> V_32 = L_3 ;
V_7 -> V_33 = V_3 ;
V_7 -> V_34 = sizeof( * V_3 ) ;
V_7 = & V_3 -> V_30 [ V_35 ] ;
V_7 -> V_32 = L_4 ;
V_7 -> V_33 = V_3 ;
V_7 -> V_34 = sizeof( * V_3 ) ;
V_8 = F_13 ( & V_2 -> V_9 , V_2 -> V_36 , V_3 -> V_30 ,
V_37 , NULL , 0 , NULL ) ;
if ( V_8 != 0 ) {
F_11 ( & V_2 -> V_9 , L_5 ) ;
goto V_16;
}
return 0 ;
V_16:
F_14 ( V_3 -> V_12 ) ;
return V_8 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_16 ( V_2 ) ;
F_17 ( & V_2 -> V_9 ) ;
F_14 ( V_3 -> V_12 ) ;
return 0 ;
}
