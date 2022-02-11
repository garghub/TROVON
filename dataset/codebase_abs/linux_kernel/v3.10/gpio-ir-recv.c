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
enum V_23 type = V_24 ;
V_21 = F_6 ( V_20 -> V_12 ) ;
if ( V_21 < 0 )
goto V_25;
if ( V_20 -> V_13 )
V_21 = ! V_21 ;
if ( V_21 == 1 )
type = V_26 ;
V_22 = F_7 ( V_20 -> V_27 , type ) ;
if ( V_22 < 0 )
goto V_25;
F_8 ( V_20 -> V_27 ) ;
V_25:
return V_28 ;
}
static int F_9 ( struct V_29 * V_30 )
{
struct V_19 * V_20 ;
struct V_31 * V_27 ;
const struct V_3 * V_4 =
V_30 -> V_2 . V_32 ;
int V_22 ;
if ( V_30 -> V_2 . V_7 ) {
struct V_3 * V_33 =
F_10 ( & V_30 -> V_2 , sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 )
return - V_35 ;
V_22 = F_1 ( & V_30 -> V_2 , V_33 ) ;
if ( V_22 )
return V_22 ;
V_4 = V_33 ;
}
if ( ! V_4 )
return - V_36 ;
if ( V_4 -> V_12 < 0 )
return - V_36 ;
V_20 = F_11 ( sizeof( struct V_19 ) , V_34 ) ;
if ( ! V_20 )
return - V_35 ;
V_27 = F_12 () ;
if ( ! V_27 ) {
V_22 = - V_35 ;
goto V_37;
}
V_27 -> V_38 = V_20 ;
V_27 -> V_39 = V_40 ;
V_27 -> V_41 = V_42 ;
V_27 -> V_43 = V_42 L_3 ;
V_27 -> V_44 . V_45 = V_46 ;
V_27 -> V_44 . V_47 = 0x0001 ;
V_27 -> V_44 . V_48 = 0x0001 ;
V_27 -> V_44 . V_49 = 0x0100 ;
V_27 -> V_2 . V_50 = & V_30 -> V_2 ;
V_27 -> V_51 = V_52 ;
if ( V_4 -> V_16 )
V_27 -> V_16 = V_4 -> V_16 ;
else
V_27 -> V_16 = V_53 ;
V_27 -> V_15 = V_4 -> V_15 ? : V_54 ;
V_20 -> V_27 = V_27 ;
V_20 -> V_12 = V_4 -> V_12 ;
V_20 -> V_13 = V_4 -> V_13 ;
V_22 = F_13 ( V_4 -> V_12 , L_4 ) ;
if ( V_22 < 0 )
goto V_55;
V_22 = F_14 ( V_4 -> V_12 ) ;
if ( V_22 < 0 )
goto V_56;
V_22 = F_15 ( V_27 ) ;
if ( V_22 < 0 ) {
F_3 ( & V_30 -> V_2 , L_5 ) ;
goto V_57;
}
F_16 ( V_30 , V_20 ) ;
V_22 = F_17 ( F_18 ( V_4 -> V_12 ) ,
F_5 ,
V_58 | V_59 ,
L_6 , V_20 ) ;
if ( V_22 < 0 )
goto V_60;
return 0 ;
V_60:
F_16 ( V_30 , NULL ) ;
F_19 ( V_27 ) ;
V_27 = NULL ;
V_57:
V_56:
F_20 ( V_4 -> V_12 ) ;
V_55:
F_21 ( V_27 ) ;
V_37:
F_22 ( V_20 ) ;
return V_22 ;
}
static int F_23 ( struct V_29 * V_30 )
{
struct V_19 * V_20 = F_24 ( V_30 ) ;
F_25 ( F_18 ( V_20 -> V_12 ) , V_20 ) ;
F_16 ( V_30 , NULL ) ;
F_19 ( V_20 -> V_27 ) ;
F_20 ( V_20 -> V_12 ) ;
F_22 ( V_20 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_27 ( V_2 ) ;
struct V_19 * V_20 = F_24 ( V_30 ) ;
if ( F_28 ( V_2 ) )
F_29 ( F_18 ( V_20 -> V_12 ) ) ;
else
F_30 ( F_18 ( V_20 -> V_12 ) ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_27 ( V_2 ) ;
struct V_19 * V_20 = F_24 ( V_30 ) ;
if ( F_28 ( V_2 ) )
F_32 ( F_18 ( V_20 -> V_12 ) ) ;
else
F_33 ( F_18 ( V_20 -> V_12 ) ) ;
return 0 ;
}
