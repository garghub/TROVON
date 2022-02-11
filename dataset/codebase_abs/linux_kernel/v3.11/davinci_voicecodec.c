T_1 F_1 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_1 -> V_3 + V_2 ) ;
}
void F_3 ( struct V_1 * V_1 ,
int V_2 , T_1 V_4 )
{
F_4 ( V_4 , V_1 -> V_3 + V_2 ) ;
}
static int T_2 F_5 ( struct V_5 * V_6 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
int V_11 ;
V_1 = F_6 ( & V_6 -> V_12 ,
sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_1 ) {
F_7 ( & V_6 -> V_12 ,
L_1 ) ;
return - V_14 ;
}
V_1 -> V_15 = F_8 ( & V_6 -> V_12 , NULL ) ;
if ( F_9 ( V_1 -> V_15 ) ) {
F_7 ( & V_6 -> V_12 ,
L_2 ) ;
return - V_16 ;
}
F_10 ( V_1 -> V_15 ) ;
V_8 = F_11 ( V_6 , V_17 , 0 ) ;
V_1 -> V_3 = F_12 ( & V_6 -> V_12 , V_8 ) ;
if ( F_9 ( V_1 -> V_3 ) ) {
V_11 = F_13 ( V_1 -> V_3 ) ;
goto V_18;
}
V_8 = F_11 ( V_6 , V_19 , 0 ) ;
if ( ! V_8 ) {
F_14 ( & V_6 -> V_12 , L_3 ) ;
V_11 = - V_20 ;
goto V_18;
}
V_1 -> V_21 . V_22 = V_8 -> V_23 ;
V_1 -> V_21 . V_24 =
( V_25 ) ( F_15 ( V_1 -> V_3 ) + V_26 ) ;
V_8 = F_11 ( V_6 , V_19 , 1 ) ;
if ( ! V_8 ) {
F_14 ( & V_6 -> V_12 , L_3 ) ;
V_11 = - V_20 ;
goto V_18;
}
V_1 -> V_21 . V_27 = V_8 -> V_23 ;
V_1 -> V_21 . V_28 =
( V_25 ) ( F_15 ( V_1 -> V_3 ) + V_29 ) ;
V_1 -> V_12 = & V_6 -> V_12 ;
V_1 -> V_6 = V_6 ;
V_10 = & V_1 -> V_30 [ V_31 ] ;
V_10 -> V_32 = L_4 ;
V_10 -> V_33 = V_1 ;
V_10 -> V_34 = sizeof( * V_1 ) ;
V_10 = & V_1 -> V_30 [ V_35 ] ;
V_10 -> V_32 = L_5 ;
V_10 -> V_33 = V_1 ;
V_10 -> V_34 = sizeof( * V_1 ) ;
V_11 = F_16 ( & V_6 -> V_12 , V_6 -> V_36 , V_1 -> V_30 ,
V_37 , NULL , 0 , NULL ) ;
if ( V_11 != 0 ) {
F_14 ( & V_6 -> V_12 , L_6 ) ;
goto V_18;
}
return 0 ;
V_18:
F_17 ( V_1 -> V_15 ) ;
return V_11 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_19 ( V_6 ) ;
F_20 ( & V_6 -> V_12 ) ;
F_17 ( V_1 -> V_15 ) ;
return 0 ;
}
