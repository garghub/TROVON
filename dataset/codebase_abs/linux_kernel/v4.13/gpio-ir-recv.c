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
F_8 ( & V_20 -> V_28 ,
V_29 + F_9 ( V_20 -> V_27 -> V_30 ) ) ;
F_10 ( V_20 -> V_27 ) ;
V_25:
return V_31 ;
}
static void V_28 ( unsigned long V_32 )
{
struct V_19 * V_20 = (struct V_19 * ) V_32 ;
F_11 ( V_33 ) ;
V_33 . V_30 = true ;
V_33 . V_34 = V_20 -> V_27 -> V_30 ;
F_12 ( V_20 -> V_27 , & V_33 ) ;
F_10 ( V_20 -> V_27 ) ;
}
static int F_13 ( struct V_35 * V_36 )
{
struct V_19 * V_20 ;
struct V_37 * V_27 ;
const struct V_3 * V_4 =
V_36 -> V_2 . V_38 ;
int V_22 ;
if ( V_36 -> V_2 . V_7 ) {
struct V_3 * V_39 =
F_14 ( & V_36 -> V_2 , sizeof( * V_39 ) , V_40 ) ;
if ( ! V_39 )
return - V_41 ;
V_22 = F_1 ( & V_36 -> V_2 , V_39 ) ;
if ( V_22 )
return V_22 ;
V_4 = V_39 ;
}
if ( ! V_4 )
return - V_42 ;
if ( V_4 -> V_12 < 0 )
return - V_42 ;
V_20 = F_15 ( sizeof( struct V_19 ) , V_40 ) ;
if ( ! V_20 )
return - V_41 ;
V_27 = F_16 ( V_43 ) ;
if ( ! V_27 ) {
V_22 = - V_41 ;
goto V_44;
}
V_27 -> V_45 = V_20 ;
V_27 -> V_46 = V_47 ;
V_27 -> V_48 = V_47 L_3 ;
V_27 -> V_49 . V_50 = V_51 ;
V_27 -> V_49 . V_52 = 0x0001 ;
V_27 -> V_49 . V_53 = 0x0001 ;
V_27 -> V_49 . V_54 = 0x0100 ;
V_27 -> V_2 . V_55 = & V_36 -> V_2 ;
V_27 -> V_56 = V_57 ;
V_27 -> V_58 = 1 ;
V_27 -> V_30 = V_59 ;
V_27 -> V_60 = 10 * V_59 ;
if ( V_4 -> V_16 )
V_27 -> V_61 = V_4 -> V_16 ;
else
V_27 -> V_61 = V_62 ;
V_27 -> V_15 = V_4 -> V_15 ? : V_63 ;
V_20 -> V_27 = V_27 ;
V_20 -> V_12 = V_4 -> V_12 ;
V_20 -> V_13 = V_4 -> V_13 ;
F_17 ( & V_20 -> V_28 , V_28 ,
( unsigned long ) V_20 ) ;
V_22 = F_18 ( V_4 -> V_12 , L_4 ) ;
if ( V_22 < 0 )
goto V_64;
V_22 = F_19 ( V_4 -> V_12 ) ;
if ( V_22 < 0 )
goto V_65;
V_22 = F_20 ( V_27 ) ;
if ( V_22 < 0 ) {
F_3 ( & V_36 -> V_2 , L_5 ) ;
goto V_66;
}
F_21 ( V_36 , V_20 ) ;
V_22 = F_22 ( F_23 ( V_4 -> V_12 ) ,
F_5 ,
V_67 | V_68 ,
L_6 , V_20 ) ;
if ( V_22 < 0 )
goto V_69;
return 0 ;
V_69:
F_24 ( V_27 ) ;
V_27 = NULL ;
V_66:
V_65:
F_25 ( V_4 -> V_12 ) ;
V_64:
F_26 ( V_27 ) ;
V_44:
F_27 ( V_20 ) ;
return V_22 ;
}
static int F_28 ( struct V_35 * V_36 )
{
struct V_19 * V_20 = F_29 ( V_36 ) ;
F_30 ( F_23 ( V_20 -> V_12 ) , V_20 ) ;
F_31 ( & V_20 -> V_28 ) ;
F_24 ( V_20 -> V_27 ) ;
F_25 ( V_20 -> V_12 ) ;
F_27 ( V_20 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_33 ( V_2 ) ;
struct V_19 * V_20 = F_29 ( V_36 ) ;
if ( F_34 ( V_2 ) )
F_35 ( F_23 ( V_20 -> V_12 ) ) ;
else
F_36 ( F_23 ( V_20 -> V_12 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_33 ( V_2 ) ;
struct V_19 * V_20 = F_29 ( V_36 ) ;
if ( F_34 ( V_2 ) )
F_38 ( F_23 ( V_20 -> V_12 ) ) ;
else
F_39 ( F_23 ( V_20 -> V_12 ) ) ;
return 0 ;
}
