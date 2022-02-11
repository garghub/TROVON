static int T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
if ( V_4 && V_4 -> V_14 )
V_6 = ( void * ) V_4 -> V_14 ;
else
V_6 = V_2 -> V_15 . V_16 ;
V_12 = F_3 ( V_2 , V_17 , 0 ) ;
if ( ! V_12 ) {
V_13 = - V_18 ;
goto V_19;
}
if ( F_4 ( V_12 ) < 0x100 )
F_5 ( & V_2 -> V_15 , L_1
L_2 ) ;
if ( V_2 -> V_15 . V_20 != & V_21 )
V_8 = F_6 ( V_2 -> V_15 . V_20 , sizeof( * V_10 ) ) ;
else
V_8 = F_6 ( & V_2 -> V_15 , sizeof( * V_10 ) ) ;
if ( F_7 ( V_8 ) ) {
V_13 = F_8 ( V_8 ) ;
goto V_19;
}
V_10 = F_9 ( V_8 ) ;
V_8 -> V_22 = L_3 ;
if ( V_6 && V_6 -> V_23 )
V_8 -> V_23 = V_6 -> V_23 ;
else
V_8 -> V_23 = & V_24 ;
if ( V_6 )
V_8 -> V_25 = V_6 -> V_25 ;
V_8 -> V_26 = F_10 ( V_2 , 0 ) ;
if ( ! F_11 ( V_12 -> V_27 , F_4 ( V_12 ) ,
F_12 ( V_8 -> V_28 ) ) ) {
F_5 ( & V_2 -> V_15 , L_4 ) ;
V_13 = - V_29 ;
goto V_30;
}
V_8 -> V_31 = F_13 ( V_12 -> V_27 , F_4 ( V_12 ) ) ;
if ( ! V_8 -> V_31 ) {
F_5 ( & V_2 -> V_15 , L_5 ) ;
V_13 = - V_18 ;
goto V_32;
}
if ( V_6 && V_6 -> V_33 ) {
V_13 = V_6 -> V_33 ( V_8 , V_6 ) ;
if ( V_13 )
goto V_34;
}
V_13 = F_14 ( V_8 ) ;
if ( V_13 )
goto V_35;
F_15 ( V_2 , V_8 ) ;
return 0 ;
V_35:
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_8 ) ;
V_34:
F_16 ( V_8 -> V_31 ) ;
V_32:
F_17 ( V_12 -> V_27 , F_4 ( V_12 ) ) ;
V_30:
F_18 ( V_8 ) ;
V_19:
F_19 ( V_36 L_6 , V_13 ) ;
return V_13 ;
}
static int T_2 F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_15 . V_16 ;
struct V_7 * V_8 = F_21 ( V_2 ) ;
struct V_11 * V_12 = F_3 ( V_2 , V_17 , 0 ) ;
int V_37 ;
T_3 V_38 ;
V_37 = 0 ;
V_38 = F_22 ( V_8 -> V_31 + V_39 ) ;
if ( V_38 == ( T_3 ) - 1 )
V_37 = 1 ;
F_23 ( V_8 , V_37 ) ;
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_8 ) ;
F_16 ( V_8 -> V_31 ) ;
F_17 ( V_12 -> V_27 , F_4 ( V_12 ) ) ;
F_18 ( V_8 ) ;
F_15 ( V_2 , NULL ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_15 , T_4 V_40 )
{
struct V_7 * V_8 = F_21 ( V_15 ) ;
return F_25 ( V_8 , V_40 ) ;
}
static int F_26 ( struct V_1 * V_15 )
{
struct V_7 * V_8 = F_21 ( V_15 ) ;
return F_27 ( V_8 ) ;
}
static int T_5 F_28 ( void )
{
return F_29 ( & V_41 ) ;
}
static void T_6 F_30 ( void )
{
F_31 ( & V_41 ) ;
}
