static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_14 , V_15 ;
int V_16 ;
V_14 = F_3 ( V_4 ) ;
V_15 = 256 * V_14 ;
V_16 = F_4 ( & V_13 -> V_17 , V_14 , V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_1 ) ;
return V_16 ;
}
V_16 = F_6 ( V_9 , V_19 , V_15 ,
V_20 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_2 ( V_6 -> V_11 ) ;
F_8 ( V_6 -> V_11 , L_3 , V_21 ,
& V_22 , V_23 ,
F_9 ( V_23 ) ) ;
if ( F_10 ( V_13 -> V_24 ) ) {
V_25 . V_26 = V_13 -> V_24 ;
V_25 . V_27 =
! ! ( V_13 -> V_28 & V_29 ) ;
F_11 ( & V_22 ,
1 ,
& V_25 ) ;
}
return 0 ;
}
static int F_12 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_18 . V_34 ;
struct V_10 * V_11 = & V_35 ;
struct V_12 * V_13 ;
int V_36 ;
V_13 = F_13 ( & V_31 -> V_18 ,
sizeof( struct V_12 ) , V_37 ) ;
if ( ! V_13 )
return - V_38 ;
V_11 -> V_18 = & V_31 -> V_18 ;
F_14 ( V_11 , V_13 ) ;
V_13 -> V_24 = F_15 (
V_33 , L_4 , 0 , & V_13 -> V_28 ) ;
if ( V_13 -> V_24 == - V_39 )
return - V_39 ;
V_36 = F_16 ( V_11 , L_5 ) ;
if ( V_36 )
goto V_16;
V_36 = F_17 ( V_11 , L_6 ) ;
if ( V_36 )
goto V_16;
V_40 . V_41 = F_18 ( V_33 ,
L_7 , 0 ) ;
if ( ! V_40 . V_41 ) {
F_5 ( & V_31 -> V_18 ,
L_8 ) ;
V_36 = - V_42 ;
goto V_16;
}
V_40 . V_43 = F_18 ( V_33 ,
L_9 , 0 ) ;
if ( ! V_40 . V_43 ) {
F_5 ( & V_31 -> V_18 ,
L_10 ) ;
V_36 = - V_42 ;
goto V_16;
}
V_40 . V_44 = V_40 . V_43 ;
V_36 = F_19 ( & V_13 -> V_17 , & V_31 -> V_18 ) ;
if ( V_36 )
goto V_16;
V_36 = F_20 ( V_11 ) ;
if ( V_36 ) {
F_5 ( & V_31 -> V_18 , L_11 ,
V_36 ) ;
goto V_45;
}
return 0 ;
V_45:
F_21 ( & V_13 -> V_17 ) ;
V_16:
return V_36 ;
}
static int F_22 ( struct V_30 * V_31 )
{
struct V_10 * V_11 = F_23 ( V_31 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_24 ( V_11 ) ;
F_21 ( & V_13 -> V_17 ) ;
return 0 ;
}
