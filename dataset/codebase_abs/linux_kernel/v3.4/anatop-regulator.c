static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , unsigned * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 , V_9 ;
int V_10 ;
V_10 = V_3 ;
F_3 ( & V_2 -> V_11 , L_1 , V_12 ,
V_10 , V_7 -> V_13 ,
V_7 -> V_14 ) ;
if ( V_10 < V_7 -> V_13 ) {
if ( V_4 > V_7 -> V_13 )
V_10 = V_7 -> V_13 ;
else
return - V_15 ;
}
if ( ! V_7 -> V_16 )
return - V_17 ;
V_9 = F_4 ( V_10 - V_7 -> V_13 , 25000 ) ;
if ( V_9 * 25000 + V_7 -> V_13 > V_7 -> V_14 )
return - V_15 ;
V_8 = V_7 -> V_18 + V_9 ;
* V_5 = V_9 ;
F_3 ( & V_2 -> V_11 , L_2 , V_12 , V_8 ) ;
F_5 ( V_7 -> V_19 ,
V_7 -> V_16 ,
V_7 -> V_20 ,
V_7 -> V_21 ,
V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_8 ;
if ( ! V_7 -> V_16 )
return - V_17 ;
V_8 = F_7 ( V_7 -> V_19 ,
V_7 -> V_16 ,
V_7 -> V_20 ,
V_7 -> V_21 ) ;
return V_8 - V_7 -> V_18 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = V_7 -> V_13 + V_5 * 25000 ;
F_3 ( & V_2 -> V_11 , L_3 , V_10 , V_5 ) ;
return V_10 ;
}
static int T_2 F_9 ( struct V_22 * V_23 )
{
struct V_24 * V_11 = & V_23 -> V_11 ;
struct V_25 * V_26 = V_11 -> V_27 ;
struct V_28 * V_29 ;
struct V_1 * V_30 ;
struct V_6 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 = F_10 ( V_23 -> V_11 . V_36 ) ;
int V_37 = 0 ;
V_33 = F_11 ( V_11 , V_26 ) ;
V_31 = F_12 ( V_11 , sizeof( * V_31 ) , V_38 ) ;
if ( ! V_31 )
return - V_39 ;
V_31 -> V_33 = V_33 ;
V_31 -> V_40 = F_13 ( F_14 ( V_26 , L_4 , NULL ) ,
V_38 ) ;
V_29 = & V_31 -> V_29 ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_40 = V_31 -> V_40 ;
V_29 -> V_41 = & V_42 ;
V_29 -> type = V_43 ;
V_29 -> V_44 = V_45 ;
V_31 -> V_19 = V_35 ;
V_37 = F_15 ( V_26 , L_5 ,
& V_31 -> V_16 ) ;
if ( V_37 ) {
F_16 ( V_11 , L_6 ) ;
goto V_46;
}
V_37 = F_15 ( V_26 , L_7 ,
& V_31 -> V_21 ) ;
if ( V_37 ) {
F_16 ( V_11 , L_8 ) ;
goto V_46;
}
V_37 = F_15 ( V_26 , L_9 ,
& V_31 -> V_20 ) ;
if ( V_37 ) {
F_16 ( V_11 , L_10 ) ;
goto V_46;
}
V_37 = F_15 ( V_26 , L_11 ,
& V_31 -> V_18 ) ;
if ( V_37 ) {
F_16 ( V_11 , L_12 ) ;
goto V_46;
}
V_37 = F_15 ( V_26 , L_13 ,
& V_31 -> V_13 ) ;
if ( V_37 ) {
F_16 ( V_11 , L_14 ) ;
goto V_46;
}
V_37 = F_15 ( V_26 , L_15 ,
& V_31 -> V_14 ) ;
if ( V_37 ) {
F_16 ( V_11 , L_16 ) ;
goto V_46;
}
V_29 -> V_47 = ( V_31 -> V_14 - V_31 -> V_13 )
/ 25000 + 1 ;
V_30 = F_17 ( V_29 , V_11 ,
V_33 , V_31 , V_23 -> V_11 . V_27 ) ;
if ( F_18 ( V_30 ) ) {
F_16 ( V_11 , L_17 ,
V_29 -> V_40 ) ;
V_37 = F_19 ( V_30 ) ;
goto V_46;
}
F_20 ( V_23 , V_30 ) ;
V_46:
if ( V_37 )
F_21 ( V_31 -> V_40 ) ;
return V_37 ;
}
static int T_3 F_22 ( struct V_22 * V_23 )
{
struct V_1 * V_30 = F_23 ( V_23 ) ;
struct V_6 * V_31 = F_2 ( V_30 ) ;
const char * V_40 = V_31 -> V_40 ;
F_24 ( V_30 ) ;
F_21 ( V_40 ) ;
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_48 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_48 ) ;
}
