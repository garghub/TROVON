void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
if ( ! V_3 )
return;
F_2 ( F_3 ( V_2 -> V_5 + V_2 -> V_4 , V_4 ,
V_4 & V_3 , 100 , 70000 ) ) ;
}
int F_4 ( struct V_6 * V_7 , void T_2 * V_4 ,
const struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_14 ; V_12 ++ ) {
struct V_1 * V_15 = V_9 -> V_16 [ V_12 ] ;
if ( ! V_15 )
continue;
V_15 -> V_5 = V_4 ;
V_15 -> V_3 = & V_17 ;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_18 -> V_19 ; V_12 ++ ) {
struct V_20 * V_21 = V_9 -> V_18 -> V_22 [ V_12 ] ;
if ( ! V_21 )
continue;
V_13 = F_5 ( NULL , V_21 ) ;
if ( V_13 ) {
F_6 ( L_1 ,
F_7 ( V_21 ) ) ;
goto V_23;
}
}
V_13 = F_8 ( V_7 , V_24 ,
V_9 -> V_18 ) ;
if ( V_13 )
goto V_23;
V_11 = F_9 ( sizeof( * V_11 ) , V_25 ) ;
V_11 -> V_26 . V_27 = V_7 ;
V_11 -> V_26 . V_28 = & V_29 ;
V_11 -> V_26 . V_30 = V_31 ;
V_11 -> V_26 . V_32 = V_9 -> V_33 ;
V_11 -> V_5 = V_4 ;
V_11 -> V_3 = & V_17 ;
V_11 -> V_34 = V_9 -> V_35 ;
V_13 = F_10 ( & V_11 -> V_26 ) ;
if ( V_13 )
goto V_36;
return 0 ;
V_36:
V_23:
return V_13 ;
}
