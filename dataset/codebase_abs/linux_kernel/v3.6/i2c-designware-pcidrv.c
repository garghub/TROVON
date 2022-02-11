static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_4 ( V_6 ) ;
V_7 = F_5 ( V_4 ) ;
if ( V_7 ) {
F_6 ( & V_4 -> V_2 , L_1 ) ;
return V_7 ;
}
V_7 = F_7 ( V_4 , V_8 ) ;
if ( V_7 ) {
F_6 ( & V_4 -> V_2 , L_2 ) ;
return V_7 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
T_1 V_9 ;
V_9 = F_9 ( V_6 ) ;
if ( V_9 )
return 0 ;
V_7 = F_7 ( V_4 , V_10 ) ;
if ( V_7 ) {
F_6 ( & V_4 -> V_2 , L_3 ) ;
return V_7 ;
}
F_10 ( V_4 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_7 = F_13 ( V_2 , 500 ) ;
F_14 ( V_2 , L_4 ) ;
if ( V_7 != 0 )
return 0 ;
return - V_11 ;
}
static T_1 F_15 ( struct V_5 * V_2 )
{
return V_2 -> V_12 -> V_13 ;
}
static int T_2 F_16 ( struct V_3 * V_4 ,
const struct V_14 * V_15 )
{
struct V_5 * V_2 ;
struct V_16 * V_17 ;
unsigned long V_18 , V_19 ;
void T_3 * V_20 ;
int V_21 ;
struct V_22 * V_12 ;
if ( V_15 -> V_23 >= F_17 ( V_24 ) ) {
F_18 ( V_25 L_5 ,
V_15 -> V_23 ) ;
return - V_26 ;
}
V_12 = & V_24 [ V_15 -> V_23 ] ;
V_21 = F_19 ( V_4 ) ;
if ( V_21 ) {
F_6 ( & V_4 -> V_2 , L_6 ,
V_21 ) ;
goto exit;
}
V_18 = F_20 ( V_4 , 0 ) ;
V_19 = F_21 ( V_4 , 0 ) ;
if ( ! V_18 || V_19 == 0 ) {
F_6 ( & V_4 -> V_2 , L_7 ) ;
V_21 = - V_27 ;
goto exit;
}
V_21 = F_22 ( V_4 , 0 , V_28 ) ;
if ( V_21 ) {
F_6 ( & V_4 -> V_2 , L_8
L_9 , V_18 ,
( unsigned long ) F_23 ( V_4 , 0 ) ) ;
goto exit;
}
V_20 = F_24 ( V_18 , V_19 ) ;
if ( ! V_20 ) {
F_6 ( & V_4 -> V_2 , L_10 ) ;
V_21 = - V_29 ;
goto V_30;
}
V_2 = F_25 ( sizeof( struct V_5 ) , V_31 ) ;
if ( ! V_2 ) {
V_21 = - V_29 ;
goto V_30;
}
F_26 ( & V_2 -> V_32 ) ;
F_27 ( & V_2 -> V_33 ) ;
V_2 -> V_34 = NULL ;
V_2 -> V_12 = V_12 ;
V_2 -> V_35 = F_15 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_2 = F_28 ( & V_4 -> V_2 ) ;
V_2 -> V_36 =
V_37 |
V_38 |
V_39 |
V_40 |
V_41 ;
V_2 -> V_42 = V_12 -> V_43 ;
F_29 ( V_4 , V_2 ) ;
V_2 -> V_44 = V_12 -> V_44 ;
V_2 -> V_45 = V_12 -> V_45 ;
V_21 = F_11 ( V_2 ) ;
if ( V_21 )
goto V_46;
V_17 = & V_2 -> V_47 ;
F_30 ( V_17 , V_2 ) ;
V_17 -> V_48 = V_49 ;
V_17 -> V_50 = 0 ;
V_17 -> V_51 = & V_52 ;
V_17 -> V_2 . V_53 = & V_4 -> V_2 ;
V_17 -> V_54 = V_12 -> V_55 ;
snprintf ( V_17 -> V_56 , sizeof( V_17 -> V_56 ) , L_11 ,
V_17 -> V_54 ) ;
V_21 = F_31 ( V_4 -> V_57 , V_58 , V_59 , V_17 -> V_56 , V_2 ) ;
if ( V_21 ) {
F_6 ( & V_4 -> V_2 , L_12 , V_2 -> V_57 ) ;
goto V_46;
}
F_32 ( V_2 ) ;
F_33 ( V_2 ) ;
V_21 = F_34 ( V_17 ) ;
if ( V_21 ) {
F_6 ( & V_4 -> V_2 , L_13 ) ;
goto V_60;
}
F_35 ( & V_4 -> V_2 ) ;
F_36 ( & V_4 -> V_2 ) ;
return 0 ;
V_60:
F_37 ( V_4 -> V_57 , V_2 ) ;
V_46:
F_38 ( V_2 -> V_20 ) ;
F_29 ( V_4 , NULL ) ;
F_39 ( & V_4 -> V_2 ) ;
F_40 ( V_2 ) ;
V_30:
F_41 ( V_4 , 0 ) ;
exit:
return V_21 ;
}
static void T_4 F_42 ( struct V_3 * V_4 )
{
struct V_5 * V_2 = F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
F_43 ( & V_4 -> V_2 ) ;
F_44 ( & V_4 -> V_2 ) ;
F_29 ( V_4 , NULL ) ;
F_45 ( & V_2 -> V_47 ) ;
F_39 ( & V_4 -> V_2 ) ;
F_37 ( V_2 -> V_57 , V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_4 , 0 ) ;
}
