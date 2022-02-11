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
V_15 = 512 * V_14 ;
V_16 = F_4 ( & V_13 -> V_17 , V_14 , V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_1 ) ;
return V_16 ;
}
V_16 = F_6 ( V_9 , 0 , V_15 ,
V_19 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_20 * V_21 = V_9 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_12 * V_24 = F_2 ( V_6 -> V_11 ) ;
F_8 ( V_21 , L_3 , V_25 ,
& V_26 ) ;
F_9 ( & V_26 ,
F_10 ( V_27 ) ,
V_27 ) ;
if ( F_11 ( V_24 -> V_28 ) ) {
V_29 . V_30 = V_24 -> V_28 ;
F_12 ( & V_26 ,
1 ,
& V_29 ) ;
}
F_13 ( V_23 , L_4 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 )
{
struct V_12 * V_24 = F_2 ( V_11 ) ;
if ( F_11 ( V_24 -> V_28 ) ) {
F_15 ( & V_26 , 1 ,
& V_29 ) ;
}
return 0 ;
}
static int F_16 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_18 . V_35 ;
struct V_10 * V_11 = & V_36 ;
struct V_12 * V_13 ;
int V_37 ;
V_13 = F_17 ( & V_32 -> V_18 ,
sizeof( struct V_12 ) , V_38 ) ;
if ( ! V_13 ) {
F_5 ( & V_32 -> V_18 , L_5 ) ;
return - V_39 ;
}
V_11 -> V_18 = & V_32 -> V_18 ;
F_18 ( V_32 , V_11 ) ;
F_19 ( V_11 , V_13 ) ;
V_13 -> V_28 = F_20 ( V_34 , L_6 , 0 ) ;
if ( V_13 -> V_28 == - V_40 )
return - V_40 ;
V_37 = F_21 ( V_11 , L_7 ) ;
if ( V_37 )
goto V_16;
V_37 = F_22 ( V_11 , L_8 ) ;
if ( V_37 )
goto V_16;
V_41 . V_42 = F_23 (
V_32 -> V_18 . V_35 , L_9 , 0 ) ;
if ( ! V_41 . V_42 ) {
F_5 ( & V_32 -> V_18 ,
L_10 ) ;
V_37 = - V_43 ;
goto V_16;
}
V_41 . V_44 = F_23 ( V_34 ,
L_11 , 0 ) ;
if ( ! V_41 . V_44 ) {
F_5 ( & V_32 -> V_18 ,
L_12 ) ;
V_37 = - V_43 ;
goto V_16;
}
V_41 . V_45 = V_41 . V_44 ;
V_37 = F_24 ( & V_13 -> V_17 , & V_32 -> V_18 ) ;
if ( V_37 )
goto V_16;
V_37 = F_25 ( V_11 ) ;
if ( V_37 ) {
F_5 ( & V_32 -> V_18 , L_13 ,
V_37 ) ;
goto V_46;
}
return 0 ;
V_46:
F_26 ( & V_13 -> V_17 ) ;
V_16:
return V_37 ;
}
static int F_27 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = F_28 ( V_32 ) ;
struct V_12 * V_24 = F_2 ( V_11 ) ;
F_29 ( V_11 ) ;
F_26 ( & V_24 -> V_17 ) ;
return 0 ;
}
