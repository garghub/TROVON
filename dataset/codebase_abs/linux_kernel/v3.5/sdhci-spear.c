static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
unsigned long V_10 ;
int V_11 ;
V_11 = F_4 ( V_8 -> V_12 -> V_13 ) ;
V_10 = V_11 ? V_14 : V_15 ;
F_5 ( V_1 , V_10 ) ;
if ( V_8 -> V_12 -> V_16 >= 0 ) {
if ( ! V_8 -> V_12 -> V_17 ) {
V_11 = V_8 -> V_12 -> V_18 ? ! V_11 : V_11 ;
F_6 ( V_8 -> V_12 -> V_16 , V_11 ) ;
}
}
F_7 ( & V_6 -> V_19 ) ;
return V_20 ;
}
static int T_2 F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_21 * V_22 ;
struct V_7 * V_8 ;
int V_23 ;
V_22 = F_9 ( V_4 , V_24 , 0 ) ;
if ( ! V_22 ) {
V_23 = - V_25 ;
F_10 ( & V_4 -> V_9 , L_1 ) ;
goto V_26;
}
if ( ! F_11 ( & V_4 -> V_9 , V_22 -> V_27 ,
F_12 ( V_22 ) , L_2 ) ) {
V_23 = - V_28 ;
F_10 ( & V_4 -> V_9 , L_3 ) ;
goto V_26;
}
V_8 = F_13 ( & V_4 -> V_9 , sizeof( * V_8 ) , V_29 ) ;
if ( ! V_8 ) {
V_23 = - V_25 ;
F_10 ( & V_4 -> V_9 , L_4 ) ;
goto V_26;
}
V_8 -> V_30 = F_14 ( & V_4 -> V_9 , NULL ) ;
if ( F_15 ( V_8 -> V_30 ) ) {
V_23 = F_16 ( V_8 -> V_30 ) ;
F_10 ( & V_4 -> V_9 , L_5 ) ;
goto V_26;
}
V_23 = F_17 ( V_8 -> V_30 ) ;
if ( V_23 ) {
F_10 ( & V_4 -> V_9 , L_6 ) ;
goto V_31;
}
V_8 -> V_12 = F_3 ( & V_4 -> V_9 ) ;
V_4 -> V_9 . V_32 = V_8 ;
if ( V_4 -> V_9 . V_33 )
V_6 = F_18 ( V_4 -> V_9 . V_33 , 0 ) ;
else
V_6 = F_18 ( & V_4 -> V_9 , 0 ) ;
if ( F_15 ( V_6 ) ) {
V_23 = F_16 ( V_6 ) ;
F_10 ( & V_4 -> V_9 , L_7 ) ;
goto V_34;
}
V_6 -> V_35 = L_8 ;
V_6 -> V_36 = & V_37 ;
V_6 -> V_1 = F_19 ( V_4 , 0 ) ;
V_6 -> V_38 = V_39 ;
V_6 -> V_40 = F_20 ( & V_4 -> V_9 , V_22 -> V_27 ,
F_12 ( V_22 ) ) ;
if ( ! V_6 -> V_40 ) {
V_23 = - V_25 ;
F_10 ( & V_4 -> V_9 , L_9 ) ;
goto V_41;
}
V_23 = F_21 ( V_6 ) ;
if ( V_23 ) {
F_10 ( & V_4 -> V_9 , L_10 ) ;
goto V_41;
}
F_22 ( V_4 , V_6 ) ;
if ( ! V_8 -> V_12 )
return 0 ;
if ( V_8 -> V_12 -> V_16 >= 0 ) {
int V_11 = 0 ;
V_23 = F_23 ( & V_4 -> V_9 ,
V_8 -> V_12 -> V_16 , L_8 ) ;
if ( V_23 < 0 ) {
F_10 ( & V_4 -> V_9 , L_11 ,
V_8 -> V_12 -> V_16 ) ;
goto V_42;
}
if ( V_8 -> V_12 -> V_17 )
V_11 = V_8 -> V_12 -> V_18 ;
else
V_11 = ! V_8 -> V_12 -> V_18 ;
V_23 = F_24 ( V_8 -> V_12 -> V_16 , V_11 ) ;
if ( V_23 ) {
F_10 ( & V_4 -> V_9 , L_12 ,
V_8 -> V_12 -> V_16 ) ;
goto V_42;
}
}
if ( V_8 -> V_12 -> V_13 >= 0 ) {
V_23 = F_23 ( & V_4 -> V_9 , V_8 -> V_12 -> V_13 ,
L_8 ) ;
if ( V_23 < 0 ) {
F_10 ( & V_4 -> V_9 , L_11 ,
V_8 -> V_12 -> V_13 ) ;
goto V_42;
}
V_23 = F_25 ( V_8 -> V_12 -> V_13 ) ;
if ( V_23 ) {
F_10 ( & V_4 -> V_9 , L_12 ,
V_8 -> V_12 -> V_13 ) ;
goto V_42;
}
V_23 = F_26 ( & V_4 -> V_9 ,
F_27 ( V_8 -> V_12 -> V_13 ) ,
F_1 , V_14 ,
F_28 ( V_6 -> V_43 ) , V_4 ) ;
if ( V_23 ) {
F_10 ( & V_4 -> V_9 , L_13 ,
V_8 -> V_12 -> V_13 ) ;
goto V_42;
}
}
return 0 ;
V_42:
F_22 ( V_4 , NULL ) ;
F_29 ( V_6 , 1 ) ;
V_41:
F_30 ( V_6 ) ;
V_34:
F_31 ( V_8 -> V_30 ) ;
V_31:
F_32 ( V_8 -> V_30 ) ;
V_26:
F_33 ( & V_4 -> V_9 , L_14 , V_23 ) ;
return V_23 ;
}
static int T_3 F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
int V_44 = 0 ;
T_4 V_45 ;
F_22 ( V_4 , NULL ) ;
V_45 = F_35 ( V_6 -> V_40 + V_46 ) ;
if ( V_45 == ( T_4 ) - 1 )
V_44 = 1 ;
F_29 ( V_6 , V_44 ) ;
F_30 ( V_6 ) ;
F_31 ( V_8 -> V_30 ) ;
F_32 ( V_8 -> V_30 ) ;
return 0 ;
}
static int F_36 ( struct V_47 * V_9 )
{
struct V_5 * V_6 = F_37 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
int V_23 ;
V_23 = F_38 ( V_6 ) ;
if ( ! V_23 )
F_31 ( V_8 -> V_30 ) ;
return V_23 ;
}
static int F_39 ( struct V_47 * V_9 )
{
struct V_5 * V_6 = F_37 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
int V_23 ;
V_23 = F_17 ( V_8 -> V_30 ) ;
if ( V_23 ) {
F_10 ( V_9 , L_15 ) ;
return V_23 ;
}
return F_40 ( V_6 ) ;
}
