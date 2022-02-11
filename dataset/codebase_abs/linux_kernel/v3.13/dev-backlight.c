static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ,
struct V_7 , V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
V_3 = F_3 ( V_11 -> V_13 , L_1 ) ;
if ( V_3 ) {
F_4 ( V_14 L_2 ) ;
return V_3 ;
}
F_5 ( V_11 -> V_13 , V_11 -> V_15 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_5 ,
struct V_7 , V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
F_5 ( V_11 -> V_13 , V_16 ) ;
F_7 ( V_11 -> V_13 ) ;
}
void T_1 F_8 ( struct V_10 * V_12 ,
struct V_4 * V_17 )
{
int V_3 = 0 ;
struct V_18 * V_19 ;
struct V_7 * V_7 ;
struct V_4 * V_20 ;
V_19 = F_9 ( & V_21 ,
sizeof( struct V_18 ) , V_22 ) ;
if ( ! V_19 ) {
F_4 ( V_14 L_3 , V_23 ) ;
return;
}
V_7 = F_9 ( & V_24 ,
sizeof( V_24 ) , V_22 ) ;
if ( ! V_7 ) {
F_4 ( V_14 L_3 , V_23 ) ;
goto V_25;
}
V_19 -> V_2 . V_6 = & V_7 -> V_9 ;
V_7 -> V_12 = V_12 ;
V_20 = & V_7 -> V_9 ;
V_20 -> V_26 = V_17 -> V_26 ;
V_19 -> V_2 . V_27 = & V_28 . V_2 ;
if ( V_17 -> V_29 )
V_20 -> V_29 = V_17 -> V_29 ;
if ( V_17 -> V_30 )
V_20 -> V_30 = V_17 -> V_30 ;
if ( V_17 -> V_31 )
V_20 -> V_31 = V_17 -> V_31 ;
if ( V_17 -> V_32 )
V_20 -> V_32 = V_17 -> V_32 ;
if ( V_17 -> V_33 >= 0 )
V_20 -> V_33 = V_17 -> V_33 ;
if ( V_17 -> V_34 )
V_20 -> V_34 = V_17 -> V_34 ;
if ( V_17 -> V_35 )
V_20 -> V_35 = V_17 -> V_35 ;
if ( V_17 -> V_36 )
V_20 -> V_36 = V_17 -> V_36 ;
if ( V_17 -> V_37 )
V_20 -> V_37 = V_17 -> V_37 ;
if ( V_17 -> exit )
V_20 -> exit = V_17 -> exit ;
if ( V_17 -> V_38 )
V_20 -> V_38 = V_17 -> V_38 ;
V_3 = F_10 ( V_19 ) ;
if ( V_3 ) {
F_4 ( V_14 L_4 , V_3 ) ;
goto V_39;
}
return;
V_39:
F_11 ( V_20 ) ;
V_25:
F_11 ( V_19 ) ;
return;
}
