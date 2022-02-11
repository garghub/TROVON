static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
int V_6 = 0 ;
enum V_7 type = V_8 ;
V_5 = F_2 ( V_4 -> V_9 ) ;
if ( V_5 < 0 )
goto V_10;
if ( V_4 -> V_11 )
V_5 = ! V_5 ;
if ( V_5 == 1 )
type = V_12 ;
V_6 = F_3 ( V_4 -> V_13 , type ) ;
if ( V_6 < 0 )
goto V_10;
F_4 ( V_4 -> V_13 ) ;
V_10:
return V_14 ;
}
static int F_5 ( struct V_15 * V_16 )
{
struct V_3 * V_4 ;
struct V_17 * V_13 ;
const struct V_18 * V_19 =
V_16 -> V_20 . V_21 ;
int V_6 ;
if ( ! V_19 )
return - V_22 ;
if ( V_19 -> V_9 < 0 )
return - V_22 ;
V_4 = F_6 ( sizeof( struct V_3 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_13 = F_7 () ;
if ( ! V_13 ) {
V_6 = - V_24 ;
goto V_25;
}
V_13 -> V_26 = V_4 ;
V_13 -> V_27 = V_28 ;
V_13 -> V_29 = V_30 ;
V_13 -> V_31 = V_30 L_1 ;
V_13 -> V_32 . V_33 = V_34 ;
V_13 -> V_32 . V_35 = 0x0001 ;
V_13 -> V_32 . V_36 = 0x0001 ;
V_13 -> V_32 . V_37 = 0x0100 ;
V_13 -> V_20 . V_38 = & V_16 -> V_20 ;
V_13 -> V_39 = V_40 ;
if ( V_19 -> V_41 )
V_13 -> V_41 = V_19 -> V_41 ;
else
V_13 -> V_41 = V_42 ;
V_13 -> V_43 = V_19 -> V_43 ? : V_44 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_9 = V_19 -> V_9 ;
V_4 -> V_11 = V_19 -> V_11 ;
V_6 = F_8 ( V_19 -> V_9 , L_2 ) ;
if ( V_6 < 0 )
goto V_45;
V_6 = F_9 ( V_19 -> V_9 ) ;
if ( V_6 < 0 )
goto V_46;
V_6 = F_10 ( V_13 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_16 -> V_20 , L_3 ) ;
goto V_47;
}
F_12 ( V_16 , V_4 ) ;
V_6 = F_13 ( F_14 ( V_19 -> V_9 ) ,
F_1 ,
V_48 | V_49 ,
L_4 , V_4 ) ;
if ( V_6 < 0 )
goto V_50;
return 0 ;
V_50:
F_12 ( V_16 , NULL ) ;
F_15 ( V_13 ) ;
V_47:
V_46:
F_16 ( V_19 -> V_9 ) ;
V_45:
F_17 ( V_13 ) ;
V_13 = NULL ;
V_25:
F_18 ( V_4 ) ;
return V_6 ;
}
static int F_19 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_20 ( V_16 ) ;
F_21 ( F_14 ( V_4 -> V_9 ) , V_4 ) ;
F_12 ( V_16 , NULL ) ;
F_15 ( V_4 -> V_13 ) ;
F_16 ( V_4 -> V_9 ) ;
F_17 ( V_4 -> V_13 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
static int F_22 ( struct V_51 * V_20 )
{
struct V_15 * V_16 = F_23 ( V_20 ) ;
struct V_3 * V_4 = F_20 ( V_16 ) ;
if ( F_24 ( V_20 ) )
F_25 ( F_14 ( V_4 -> V_9 ) ) ;
else
F_26 ( F_14 ( V_4 -> V_9 ) ) ;
return 0 ;
}
static int F_27 ( struct V_51 * V_20 )
{
struct V_15 * V_16 = F_23 ( V_20 ) ;
struct V_3 * V_4 = F_20 ( V_16 ) ;
if ( F_24 ( V_20 ) )
F_28 ( F_14 ( V_4 -> V_9 ) ) ;
else
F_29 ( F_14 ( V_4 -> V_9 ) ) ;
return 0 ;
}
