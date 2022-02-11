static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_16 , V_17 ;
int V_18 ;
V_16 = F_3 ( V_4 ) ;
V_17 = 256 * V_16 ;
V_18 = F_4 ( & V_15 -> V_19 , V_16 , V_17 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_1 ) ;
return V_18 ;
}
V_18 = F_6 ( V_9 , V_21 , V_17 ,
V_22 ) ;
if ( V_18 < 0 ) {
F_5 ( V_13 -> V_20 , L_2 ) ;
return V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_14 * V_15 = F_2 ( V_11 -> V_13 ) ;
F_8 ( V_11 , L_3 , V_23 ,
& V_24 ) ;
F_9 ( & V_24 ,
F_10 ( V_25 ) ,
V_25 ) ;
if ( F_11 ( V_15 -> V_26 ) ) {
V_27 . V_28 = V_15 -> V_26 ;
F_12 ( & V_24 ,
1 ,
& V_27 ) ;
}
return 0 ;
}
static int F_13 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_20 . V_33 ;
struct V_12 * V_13 = & V_34 ;
struct V_14 * V_15 ;
int V_35 ;
V_15 = F_14 ( & V_30 -> V_20 ,
sizeof( struct V_14 ) , V_36 ) ;
if ( ! V_15 ) {
F_5 ( & V_30 -> V_20 , L_4 ) ;
return - V_37 ;
}
V_13 -> V_20 = & V_30 -> V_20 ;
F_15 ( V_30 , V_13 ) ;
F_16 ( V_13 , V_15 ) ;
V_15 -> V_26 = F_17 ( V_32 , L_5 , 0 ) ;
if ( V_15 -> V_26 == - V_38 )
return - V_38 ;
V_35 = F_18 ( V_13 , L_6 ) ;
if ( V_35 )
goto V_18;
V_35 = F_19 ( V_13 , L_7 ) ;
if ( V_35 )
goto V_18;
V_39 . V_40 = F_20 ( V_32 ,
L_8 , 0 ) ;
if ( ! V_39 . V_40 ) {
F_5 ( & V_30 -> V_20 ,
L_9 ) ;
V_35 = - V_41 ;
goto V_18;
}
V_39 . V_42 = F_20 ( V_32 ,
L_10 , 0 ) ;
if ( ! V_39 . V_42 ) {
F_5 ( & V_30 -> V_20 ,
L_11 ) ;
V_35 = - V_41 ;
goto V_18;
}
V_39 . V_43 = V_39 . V_42 ;
V_35 = F_21 ( & V_15 -> V_19 , & V_30 -> V_20 ) ;
if ( V_35 )
goto V_18;
V_35 = F_22 ( V_13 ) ;
if ( V_35 ) {
F_5 ( & V_30 -> V_20 , L_12 ,
V_35 ) ;
goto V_44;
}
return 0 ;
V_44:
F_23 ( & V_15 -> V_19 ) ;
V_18:
return V_35 ;
}
static int F_24 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = F_25 ( V_30 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
F_26 ( & V_24 , 1 ,
& V_27 ) ;
F_27 ( V_13 ) ;
F_23 ( & V_15 -> V_19 ) ;
return 0 ;
}
