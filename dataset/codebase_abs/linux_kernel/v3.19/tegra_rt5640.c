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
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_21 * V_22 = V_9 -> V_22 ;
struct V_12 * V_13 = F_2 ( V_6 -> V_11 ) ;
F_8 ( V_22 , L_3 , V_23 ,
& V_24 ) ;
F_9 ( & V_24 ,
F_10 ( V_25 ) ,
V_25 ) ;
if ( F_11 ( V_13 -> V_26 ) ) {
V_27 . V_28 = V_13 -> V_26 ;
V_27 . V_29 =
! ! ( V_13 -> V_30 & V_31 ) ;
F_12 ( & V_24 ,
1 ,
& V_27 ) ;
}
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_11 ( V_13 -> V_26 ) ) {
F_14 ( & V_24 , 1 ,
& V_27 ) ;
}
return 0 ;
}
static int F_15 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_18 . V_36 ;
struct V_10 * V_11 = & V_37 ;
struct V_12 * V_13 ;
int V_38 ;
V_13 = F_16 ( & V_33 -> V_18 ,
sizeof( struct V_12 ) , V_39 ) ;
if ( ! V_13 ) {
F_5 ( & V_33 -> V_18 , L_4 ) ;
return - V_40 ;
}
V_11 -> V_18 = & V_33 -> V_18 ;
F_17 ( V_33 , V_11 ) ;
F_18 ( V_11 , V_13 ) ;
V_13 -> V_26 = F_19 (
V_35 , L_5 , 0 , & V_13 -> V_30 ) ;
if ( V_13 -> V_26 == - V_41 )
return - V_41 ;
V_38 = F_20 ( V_11 , L_6 ) ;
if ( V_38 )
goto V_16;
V_38 = F_21 ( V_11 , L_7 ) ;
if ( V_38 )
goto V_16;
V_42 . V_43 = F_22 ( V_35 ,
L_8 , 0 ) ;
if ( ! V_42 . V_43 ) {
F_5 ( & V_33 -> V_18 ,
L_9 ) ;
V_38 = - V_44 ;
goto V_16;
}
V_42 . V_45 = F_22 ( V_35 ,
L_10 , 0 ) ;
if ( ! V_42 . V_45 ) {
F_5 ( & V_33 -> V_18 ,
L_11 ) ;
V_38 = - V_44 ;
goto V_16;
}
V_42 . V_46 = V_42 . V_45 ;
V_38 = F_23 ( & V_13 -> V_17 , & V_33 -> V_18 ) ;
if ( V_38 )
goto V_16;
V_38 = F_24 ( V_11 ) ;
if ( V_38 ) {
F_5 ( & V_33 -> V_18 , L_12 ,
V_38 ) ;
goto V_47;
}
return 0 ;
V_47:
F_25 ( & V_13 -> V_17 ) ;
V_16:
return V_38 ;
}
static int F_26 ( struct V_32 * V_33 )
{
struct V_10 * V_11 = F_27 ( V_33 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_28 ( V_11 ) ;
F_25 ( & V_13 -> V_17 ) ;
return 0 ;
}
