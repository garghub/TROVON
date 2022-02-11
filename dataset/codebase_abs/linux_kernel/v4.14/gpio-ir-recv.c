static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
enum V_8 V_9 ;
int V_10 ;
V_10 = F_2 ( V_6 , 0 , & V_9 ) ;
if ( V_10 < 0 ) {
if ( V_10 != - V_11 )
F_3 ( V_2 , L_1 , V_10 ) ;
return V_10 ;
}
V_4 -> V_12 = V_10 ;
V_4 -> V_13 = ( V_9 & V_14 ) ;
V_4 -> V_15 = F_4 ( V_6 , L_2 , NULL ) ;
V_4 -> V_16 = 0 ;
return 0 ;
}
static T_1 F_5 ( int V_17 , void * V_18 )
{
struct V_19 * V_20 = V_18 ;
int V_21 ;
int V_22 = 0 ;
V_21 = F_6 ( V_20 -> V_12 ) ;
if ( V_21 < 0 )
goto V_23;
if ( V_20 -> V_13 )
V_21 = ! V_21 ;
V_22 = F_7 ( V_20 -> V_24 , V_21 == 1 ) ;
if ( V_22 < 0 )
goto V_23;
V_23:
return V_25 ;
}
static int F_8 ( struct V_26 * V_27 )
{
struct V_19 * V_20 ;
struct V_28 * V_24 ;
const struct V_3 * V_4 =
V_27 -> V_2 . V_29 ;
int V_22 ;
if ( V_27 -> V_2 . V_7 ) {
struct V_3 * V_30 =
F_9 ( & V_27 -> V_2 , sizeof( * V_30 ) , V_31 ) ;
if ( ! V_30 )
return - V_32 ;
V_22 = F_1 ( & V_27 -> V_2 , V_30 ) ;
if ( V_22 )
return V_22 ;
V_4 = V_30 ;
}
if ( ! V_4 )
return - V_33 ;
if ( V_4 -> V_12 < 0 )
return - V_33 ;
V_20 = F_10 ( sizeof( struct V_19 ) , V_31 ) ;
if ( ! V_20 )
return - V_32 ;
V_24 = F_11 ( V_34 ) ;
if ( ! V_24 ) {
V_22 = - V_32 ;
goto V_35;
}
V_24 -> V_36 = V_20 ;
V_24 -> V_37 = V_38 ;
V_24 -> V_39 = V_38 L_3 ;
V_24 -> V_40 . V_41 = V_42 ;
V_24 -> V_40 . V_43 = 0x0001 ;
V_24 -> V_40 . V_44 = 0x0001 ;
V_24 -> V_40 . V_45 = 0x0100 ;
V_24 -> V_2 . V_46 = & V_27 -> V_2 ;
V_24 -> V_47 = V_48 ;
V_24 -> V_49 = 1 ;
V_24 -> V_50 = V_51 ;
V_24 -> V_52 = 10 * V_51 ;
if ( V_4 -> V_16 )
V_24 -> V_53 = V_4 -> V_16 ;
else
V_24 -> V_53 = V_54 ;
V_24 -> V_15 = V_4 -> V_15 ? : V_55 ;
V_20 -> V_24 = V_24 ;
V_20 -> V_12 = V_4 -> V_12 ;
V_20 -> V_13 = V_4 -> V_13 ;
V_22 = F_12 ( V_4 -> V_12 , L_4 ) ;
if ( V_22 < 0 )
goto V_56;
V_22 = F_13 ( V_4 -> V_12 ) ;
if ( V_22 < 0 )
goto V_57;
V_22 = F_14 ( V_24 ) ;
if ( V_22 < 0 ) {
F_3 ( & V_27 -> V_2 , L_5 ) ;
goto V_58;
}
F_15 ( V_27 , V_20 ) ;
V_22 = F_16 ( F_17 ( V_4 -> V_12 ) ,
F_5 ,
V_59 | V_60 ,
L_6 , V_20 ) ;
if ( V_22 < 0 )
goto V_61;
return 0 ;
V_61:
F_18 ( V_24 ) ;
V_24 = NULL ;
V_58:
V_57:
F_19 ( V_4 -> V_12 ) ;
V_56:
F_20 ( V_24 ) ;
V_35:
F_21 ( V_20 ) ;
return V_22 ;
}
static int F_22 ( struct V_26 * V_27 )
{
struct V_19 * V_20 = F_23 ( V_27 ) ;
F_24 ( F_17 ( V_20 -> V_12 ) , V_20 ) ;
F_18 ( V_20 -> V_24 ) ;
F_19 ( V_20 -> V_12 ) ;
F_21 ( V_20 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_26 ( V_2 ) ;
struct V_19 * V_20 = F_23 ( V_27 ) ;
if ( F_27 ( V_2 ) )
F_28 ( F_17 ( V_20 -> V_12 ) ) ;
else
F_29 ( F_17 ( V_20 -> V_12 ) ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_26 ( V_2 ) ;
struct V_19 * V_20 = F_23 ( V_27 ) ;
if ( F_27 ( V_2 ) )
F_31 ( F_17 ( V_20 -> V_12 ) ) ;
else
F_32 ( F_17 ( V_20 -> V_12 ) ) ;
return 0 ;
}
