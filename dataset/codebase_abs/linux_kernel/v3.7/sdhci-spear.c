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
static struct V_21 * T_2
F_8 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_9 . V_24 ;
struct V_21 * V_25 = NULL ;
int V_26 ;
V_26 = F_9 ( V_23 , L_1 , 0 ) ;
if ( ! F_10 ( V_26 ) )
V_26 = - 1 ;
if ( V_26 != - 1 ) {
V_25 = F_11 ( & V_4 -> V_9 , sizeof( * V_25 ) , V_27 ) ;
if ( ! V_25 ) {
F_12 ( & V_4 -> V_9 , L_2 ) ;
return F_13 ( - V_28 ) ;
}
}
V_25 -> V_13 = V_26 ;
return V_25 ;
}
static struct V_21 * T_2
F_8 ( struct V_3 * V_4 )
{
return F_13 ( - V_29 ) ;
}
static int T_2 F_14 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_9 . V_24 ;
struct V_5 * V_6 ;
struct V_30 * V_31 ;
struct V_7 * V_8 ;
int V_32 ;
V_31 = F_15 ( V_4 , V_33 , 0 ) ;
if ( ! V_31 ) {
V_32 = - V_28 ;
F_16 ( & V_4 -> V_9 , L_3 ) ;
goto V_34;
}
if ( ! F_17 ( & V_4 -> V_9 , V_31 -> V_35 ,
F_18 ( V_31 ) , L_4 ) ) {
V_32 = - V_36 ;
F_16 ( & V_4 -> V_9 , L_5 ) ;
goto V_34;
}
V_8 = F_11 ( & V_4 -> V_9 , sizeof( * V_8 ) , V_27 ) ;
if ( ! V_8 ) {
V_32 = - V_28 ;
F_16 ( & V_4 -> V_9 , L_6 ) ;
goto V_34;
}
V_8 -> V_37 = F_19 ( & V_4 -> V_9 , NULL ) ;
if ( F_20 ( V_8 -> V_37 ) ) {
V_32 = F_21 ( V_8 -> V_37 ) ;
F_16 ( & V_4 -> V_9 , L_7 ) ;
goto V_34;
}
V_32 = F_22 ( V_8 -> V_37 ) ;
if ( V_32 ) {
F_16 ( & V_4 -> V_9 , L_8 ) ;
goto V_38;
}
if ( V_23 ) {
V_8 -> V_12 = F_8 ( V_4 ) ;
if ( F_20 ( V_8 -> V_12 ) ) {
F_12 ( & V_4 -> V_9 , L_9 ) ;
return - V_39 ;
}
} else {
V_8 -> V_12 = F_3 ( & V_4 -> V_9 ) ;
}
V_4 -> V_9 . V_40 = V_8 ;
if ( V_4 -> V_9 . V_41 )
V_6 = F_23 ( V_4 -> V_9 . V_41 , 0 ) ;
else
V_6 = F_23 ( & V_4 -> V_9 , 0 ) ;
if ( F_20 ( V_6 ) ) {
V_32 = F_21 ( V_6 ) ;
F_16 ( & V_4 -> V_9 , L_10 ) ;
goto V_42;
}
V_6 -> V_43 = L_11 ;
V_6 -> V_44 = & V_45 ;
V_6 -> V_1 = F_24 ( V_4 , 0 ) ;
V_6 -> V_46 = V_47 ;
V_6 -> V_48 = F_25 ( & V_4 -> V_9 , V_31 -> V_35 ,
F_18 ( V_31 ) ) ;
if ( ! V_6 -> V_48 ) {
V_32 = - V_28 ;
F_16 ( & V_4 -> V_9 , L_12 ) ;
goto V_49;
}
V_32 = F_26 ( V_6 ) ;
if ( V_32 ) {
F_16 ( & V_4 -> V_9 , L_13 ) ;
goto V_49;
}
F_27 ( V_4 , V_6 ) ;
if ( ! V_8 -> V_12 )
return 0 ;
if ( V_8 -> V_12 -> V_16 >= 0 ) {
int V_11 = 0 ;
V_32 = F_28 ( & V_4 -> V_9 ,
V_8 -> V_12 -> V_16 , L_11 ) ;
if ( V_32 < 0 ) {
F_16 ( & V_4 -> V_9 , L_14 ,
V_8 -> V_12 -> V_16 ) ;
goto V_50;
}
if ( V_8 -> V_12 -> V_17 )
V_11 = V_8 -> V_12 -> V_18 ;
else
V_11 = ! V_8 -> V_12 -> V_18 ;
V_32 = F_29 ( V_8 -> V_12 -> V_16 , V_11 ) ;
if ( V_32 ) {
F_16 ( & V_4 -> V_9 , L_15 ,
V_8 -> V_12 -> V_16 ) ;
goto V_50;
}
}
if ( V_8 -> V_12 -> V_13 >= 0 ) {
V_32 = F_28 ( & V_4 -> V_9 , V_8 -> V_12 -> V_13 ,
L_11 ) ;
if ( V_32 < 0 ) {
F_16 ( & V_4 -> V_9 , L_14 ,
V_8 -> V_12 -> V_13 ) ;
goto V_50;
}
V_32 = F_30 ( V_8 -> V_12 -> V_13 ) ;
if ( V_32 ) {
F_16 ( & V_4 -> V_9 , L_15 ,
V_8 -> V_12 -> V_13 ) ;
goto V_50;
}
V_32 = F_31 ( & V_4 -> V_9 ,
F_32 ( V_8 -> V_12 -> V_13 ) ,
F_1 , V_14 ,
F_33 ( V_6 -> V_51 ) , V_4 ) ;
if ( V_32 ) {
F_16 ( & V_4 -> V_9 , L_16 ,
V_8 -> V_12 -> V_13 ) ;
goto V_50;
}
}
return 0 ;
V_50:
F_27 ( V_4 , NULL ) ;
F_34 ( V_6 , 1 ) ;
V_49:
F_35 ( V_6 ) ;
V_42:
F_36 ( V_8 -> V_37 ) ;
V_38:
F_37 ( V_8 -> V_37 ) ;
V_34:
F_12 ( & V_4 -> V_9 , L_17 , V_32 ) ;
return V_32 ;
}
static int T_3 F_38 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
int V_52 = 0 ;
T_4 V_53 ;
F_27 ( V_4 , NULL ) ;
V_53 = F_39 ( V_6 -> V_48 + V_54 ) ;
if ( V_53 == ( T_4 ) - 1 )
V_52 = 1 ;
F_34 ( V_6 , V_52 ) ;
F_35 ( V_6 ) ;
F_36 ( V_8 -> V_37 ) ;
F_37 ( V_8 -> V_37 ) ;
return 0 ;
}
static int F_40 ( struct V_55 * V_9 )
{
struct V_5 * V_6 = F_41 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
int V_32 ;
V_32 = F_42 ( V_6 ) ;
if ( ! V_32 )
F_36 ( V_8 -> V_37 ) ;
return V_32 ;
}
static int F_43 ( struct V_55 * V_9 )
{
struct V_5 * V_6 = F_41 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
int V_32 ;
V_32 = F_22 ( V_8 -> V_37 ) ;
if ( V_32 ) {
F_16 ( V_9 , L_18 ) ;
return V_32 ;
}
return F_44 ( V_6 ) ;
}
