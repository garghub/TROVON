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
struct V_12 * V_13 = F_2 ( V_6 -> V_11 ) ;
F_12 ( V_6 -> V_11 , L_3 , V_29 ,
& V_30 ,
& V_31 , 1 ) ;
if ( F_8 ( V_13 -> V_32 ) ) {
V_33 . V_34 = V_13 -> V_32 ;
F_13 ( & V_30 , 1 ,
& V_33 ) ;
}
F_12 ( V_6 -> V_11 , L_4 , V_35 ,
& V_36 ,
& V_37 , 1 ) ;
if ( F_8 ( V_13 -> V_38 ) ) {
V_39 . V_34 = V_13 -> V_38 ;
F_13 ( & V_36 , 1 ,
& V_39 ) ;
}
F_14 ( & V_6 -> V_11 -> V_27 , L_5 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_2 ( V_11 ) ;
if ( F_8 ( V_13 -> V_32 ) ) {
F_16 ( & V_30 , 1 ,
& V_33 ) ;
}
if ( F_8 ( V_13 -> V_38 ) ) {
F_16 ( & V_36 , 1 ,
& V_39 ) ;
}
return 0 ;
}
static int F_17 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_18 . V_44 ;
struct V_10 * V_11 = & V_45 ;
struct V_12 * V_13 ;
int V_46 ;
V_13 = F_18 ( & V_41 -> V_18 ,
sizeof( struct V_12 ) , V_47 ) ;
if ( ! V_13 )
return - V_48 ;
V_11 -> V_18 = & V_41 -> V_18 ;
F_19 ( V_41 , V_11 ) ;
F_20 ( V_11 , V_13 ) ;
V_13 -> V_32 = F_21 ( V_43 , L_6 , 0 ) ;
if ( V_13 -> V_32 == - V_49 )
return - V_49 ;
V_13 -> V_38 = F_21 ( V_43 ,
L_7 , 0 ) ;
if ( V_13 -> V_38 == - V_49 )
return - V_49 ;
V_13 -> V_28 = F_21 ( V_43 , L_8 , 0 ) ;
if ( V_13 -> V_28 == - V_49 )
return - V_49 ;
if ( F_8 ( V_13 -> V_28 ) ) {
V_46 = F_22 ( & V_41 -> V_18 , V_13 -> V_28 ,
V_50 , L_9 ) ;
if ( V_46 ) {
F_5 ( V_11 -> V_18 , L_10 ) ;
return V_46 ;
}
}
V_13 -> V_51 = F_21 ( V_43 ,
L_11 , 0 ) ;
if ( V_13 -> V_51 == - V_49 )
return - V_49 ;
if ( F_8 ( V_13 -> V_51 ) ) {
V_46 = F_22 ( & V_41 -> V_18 ,
V_13 -> V_51 ,
V_52 , L_12 ) ;
if ( V_46 ) {
F_5 ( V_11 -> V_18 , L_13 ) ;
return V_46 ;
}
}
V_46 = F_23 ( V_11 , L_14 ) ;
if ( V_46 )
goto V_16;
V_46 = F_24 ( V_11 , L_15 ) ;
if ( V_46 )
goto V_16;
V_53 . V_54 = F_25 ( V_43 ,
L_16 , 0 ) ;
if ( ! V_53 . V_54 ) {
F_5 ( & V_41 -> V_18 ,
L_17 ) ;
V_46 = - V_55 ;
goto V_16;
}
V_53 . V_56 = F_25 ( V_43 ,
L_18 , 0 ) ;
if ( ! V_53 . V_56 ) {
F_5 ( & V_41 -> V_18 ,
L_19 ) ;
V_46 = - V_55 ;
goto V_16;
}
V_53 . V_57 = V_53 . V_56 ;
V_46 = F_26 ( & V_13 -> V_17 , & V_41 -> V_18 ) ;
if ( V_46 )
goto V_16;
V_46 = F_27 ( V_11 ) ;
if ( V_46 ) {
F_5 ( & V_41 -> V_18 , L_20 ,
V_46 ) ;
goto V_58;
}
return 0 ;
V_58:
F_28 ( & V_13 -> V_17 ) ;
V_16:
return V_46 ;
}
static int F_29 ( struct V_40 * V_41 )
{
struct V_10 * V_11 = F_30 ( V_41 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_31 ( V_11 ) ;
F_28 ( & V_13 -> V_17 ) ;
return 0 ;
}
