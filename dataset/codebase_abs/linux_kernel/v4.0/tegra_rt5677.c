static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_14 , V_15 , V_16 ;
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
static int F_7 ( struct V_21 * V_22 ,
struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = V_22 -> V_27 ;
struct V_10 * V_11 = V_27 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( ! F_8 ( V_13 -> V_28 ) )
return 0 ;
F_9 ( V_13 -> V_28 ,
F_10 ( V_25 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_29 * V_30 = V_9 -> V_30 ;
struct V_26 * V_27 = & V_30 -> V_27 ;
struct V_12 * V_13 = F_2 ( V_6 -> V_11 ) ;
F_12 ( V_30 , L_3 , V_31 ,
& V_32 ) ;
F_13 ( & V_32 , 1 ,
& V_33 ) ;
if ( F_8 ( V_13 -> V_34 ) ) {
V_35 . V_36 = V_13 -> V_34 ;
F_14 ( & V_32 , 1 ,
& V_35 ) ;
}
F_12 ( V_30 , L_4 , V_37 ,
& V_38 ) ;
F_13 ( & V_38 , 1 ,
& V_39 ) ;
if ( F_8 ( V_13 -> V_40 ) ) {
V_41 . V_36 = V_13 -> V_40 ;
F_14 ( & V_38 , 1 ,
& V_41 ) ;
}
F_15 ( V_27 , L_5 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_8 ( V_13 -> V_34 ) ) {
F_17 ( & V_32 , 1 ,
& V_35 ) ;
}
if ( F_8 ( V_13 -> V_40 ) ) {
F_17 ( & V_38 , 1 ,
& V_41 ) ;
}
return 0 ;
}
static int F_18 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_18 . V_46 ;
struct V_10 * V_11 = & V_47 ;
struct V_12 * V_13 ;
int V_48 ;
V_13 = F_19 ( & V_43 -> V_18 ,
sizeof( struct V_12 ) , V_49 ) ;
if ( ! V_13 )
return - V_50 ;
V_11 -> V_18 = & V_43 -> V_18 ;
F_20 ( V_43 , V_11 ) ;
F_21 ( V_11 , V_13 ) ;
V_13 -> V_34 = F_22 ( V_45 , L_6 , 0 ) ;
if ( V_13 -> V_34 == - V_51 )
return - V_51 ;
V_13 -> V_40 = F_22 ( V_45 ,
L_7 , 0 ) ;
if ( V_13 -> V_40 == - V_51 )
return - V_51 ;
V_13 -> V_28 = F_22 ( V_45 , L_8 , 0 ) ;
if ( V_13 -> V_28 == - V_51 )
return - V_51 ;
if ( F_8 ( V_13 -> V_28 ) ) {
V_48 = F_23 ( & V_43 -> V_18 , V_13 -> V_28 ,
V_52 , L_9 ) ;
if ( V_48 ) {
F_5 ( V_11 -> V_18 , L_10 ) ;
return V_48 ;
}
}
V_13 -> V_53 = F_22 ( V_45 ,
L_11 , 0 ) ;
if ( V_13 -> V_53 == - V_51 )
return - V_51 ;
if ( F_8 ( V_13 -> V_53 ) ) {
V_48 = F_23 ( & V_43 -> V_18 ,
V_13 -> V_53 ,
V_54 , L_12 ) ;
if ( V_48 ) {
F_5 ( V_11 -> V_18 , L_13 ) ;
return V_48 ;
}
}
V_48 = F_24 ( V_11 , L_14 ) ;
if ( V_48 )
goto V_16;
V_48 = F_25 ( V_11 , L_15 ) ;
if ( V_48 )
goto V_16;
V_55 . V_56 = F_26 ( V_45 ,
L_16 , 0 ) ;
if ( ! V_55 . V_56 ) {
F_5 ( & V_43 -> V_18 ,
L_17 ) ;
V_48 = - V_57 ;
goto V_16;
}
V_55 . V_58 = F_26 ( V_45 ,
L_18 , 0 ) ;
if ( ! V_55 . V_58 ) {
F_5 ( & V_43 -> V_18 ,
L_19 ) ;
V_48 = - V_57 ;
goto V_16;
}
V_55 . V_59 = V_55 . V_58 ;
V_48 = F_27 ( & V_13 -> V_17 , & V_43 -> V_18 ) ;
if ( V_48 )
goto V_16;
V_48 = F_28 ( V_11 ) ;
if ( V_48 ) {
F_5 ( & V_43 -> V_18 , L_20 ,
V_48 ) ;
goto V_60;
}
return 0 ;
V_60:
F_29 ( & V_13 -> V_17 ) ;
V_16:
return V_48 ;
}
static int F_30 ( struct V_42 * V_43 )
{
struct V_10 * V_11 = F_31 ( V_43 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_32 ( V_11 ) ;
F_29 ( & V_13 -> V_17 ) ;
return 0 ;
}
