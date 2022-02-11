static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) / 1000 ;
}
static int T_2 F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_8 * V_9 , * V_10 ;
int V_11 , V_12 ;
V_9 = F_4 ( V_5 , V_13 , 0 ) ;
if ( ! V_9 ) {
F_5 ( & V_5 -> V_2 , L_1 ) ;
return - V_14 ;
}
V_11 = F_6 ( V_5 , 0 ) ;
if ( V_11 < 0 ) {
F_5 ( & V_5 -> V_2 , L_2 ) ;
return V_11 ;
}
V_10 = F_7 ( V_9 -> V_15 , F_8 ( V_9 ) ,
V_5 -> V_16 ) ;
if ( ! V_10 ) {
F_5 ( & V_5 -> V_2 , L_3 ) ;
return - V_17 ;
}
V_2 = F_9 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_2 ) {
V_12 = - V_19 ;
goto V_20;
}
F_10 ( & V_2 -> V_21 ) ;
F_11 ( & V_2 -> V_22 ) ;
V_2 -> V_2 = F_12 ( & V_5 -> V_2 ) ;
V_2 -> V_11 = V_11 ;
F_13 ( V_5 , V_2 ) ;
V_2 -> V_3 = F_14 ( & V_5 -> V_2 , NULL ) ;
V_2 -> V_23 = F_1 ;
if ( F_15 ( V_2 -> V_3 ) ) {
V_12 = - V_24 ;
goto V_25;
}
F_16 ( V_2 -> V_3 ) ;
V_2 -> V_26 =
V_27 |
V_28 |
V_29 |
V_30 |
V_31 |
V_32 ;
V_2 -> V_33 = V_34 | V_35 |
V_36 | V_37 ;
V_2 -> V_38 = F_17 ( V_9 -> V_15 , F_8 ( V_9 ) ) ;
if ( V_2 -> V_38 == NULL ) {
F_5 ( & V_5 -> V_2 , L_4 ) ;
V_12 = - V_17 ;
goto V_39;
}
{
T_1 V_40 = F_18 ( V_2 ) ;
V_2 -> V_41 = ( ( V_40 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_42 = ( ( V_40 >> 8 ) & 0xff ) + 1 ;
}
V_12 = F_19 ( V_2 ) ;
if ( V_12 )
goto V_43;
F_20 ( V_2 ) ;
V_12 = F_21 ( V_2 -> V_11 , V_44 , V_45 , V_5 -> V_16 , V_2 ) ;
if ( V_12 ) {
F_5 ( & V_5 -> V_2 , L_5 , V_2 -> V_11 ) ;
goto V_43;
}
V_7 = & V_2 -> V_46 ;
F_22 ( V_7 , V_2 ) ;
V_7 -> V_47 = V_48 ;
V_7 -> V_49 = V_50 ;
F_23 ( V_7 -> V_16 , L_6 ,
sizeof( V_7 -> V_16 ) ) ;
V_7 -> V_51 = & V_52 ;
V_7 -> V_2 . V_53 = & V_5 -> V_2 ;
V_7 -> V_2 . V_54 = V_5 -> V_2 . V_54 ;
V_7 -> V_55 = V_5 -> V_56 ;
V_12 = F_24 ( V_7 ) ;
if ( V_12 ) {
F_5 ( & V_5 -> V_2 , L_7 ) ;
goto V_57;
}
F_25 ( V_7 ) ;
return 0 ;
V_57:
F_26 ( V_2 -> V_11 , V_2 ) ;
V_43:
F_27 ( V_2 -> V_38 ) ;
V_39:
F_28 ( V_2 -> V_3 ) ;
F_29 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_25:
F_13 ( V_5 , NULL ) ;
F_30 ( & V_5 -> V_2 ) ;
F_31 ( V_2 ) ;
V_20:
F_32 ( V_9 -> V_15 , F_8 ( V_9 ) ) ;
return V_12 ;
}
static int T_3 F_33 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_34 ( V_5 ) ;
struct V_8 * V_9 ;
F_13 ( V_5 , NULL ) ;
F_35 ( & V_2 -> V_46 ) ;
F_30 ( & V_5 -> V_2 ) ;
F_28 ( V_2 -> V_3 ) ;
F_29 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
F_36 ( V_2 ) ;
F_26 ( V_2 -> V_11 , V_2 ) ;
F_31 ( V_2 ) ;
V_9 = F_4 ( V_5 , V_13 , 0 ) ;
F_32 ( V_9 -> V_15 , F_8 ( V_9 ) ) ;
return 0 ;
}
static int F_37 ( struct V_58 * V_2 )
{
struct V_4 * V_5 = F_38 ( V_2 ) ;
struct V_1 * V_59 = F_34 ( V_5 ) ;
F_28 ( V_59 -> V_3 ) ;
return 0 ;
}
static int F_39 ( struct V_58 * V_2 )
{
struct V_4 * V_5 = F_38 ( V_2 ) ;
struct V_1 * V_59 = F_34 ( V_5 ) ;
F_16 ( V_59 -> V_3 ) ;
F_19 ( V_59 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_60 , F_3 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_60 ) ;
}
