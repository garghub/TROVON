static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_1 V_6 ;
F_2 ( V_3 -> V_7 , V_8 , & V_6 ) ;
V_6 = V_6 & V_9 ? 1 : 0 ;
if ( V_6 ^ V_3 -> V_10 ) {
V_3 -> V_10 = V_6 ;
F_3 ( V_5 , V_11 , V_3 -> V_12 , V_6 ) ;
F_4 ( V_5 ) ;
F_5 ( V_3 -> V_5 -> V_13 . V_14 ) ;
}
if ( V_6 ) {
F_6 ( & V_3 -> V_15 ,
V_16 + F_7 ( V_17 ) ) ;
}
}
static T_2 F_8 ( int V_18 , void * V_19 )
{
struct V_20 * V_21 = V_19 ;
struct V_2 * V_3 = F_9 ( V_21 ) ;
T_1 V_22 ;
F_10 ( V_3 -> V_5 -> V_13 . V_14 , 0 ) ;
F_2 ( V_3 -> V_7 , V_23 , & V_22 ) ;
if ( V_22 & V_24 )
F_6 ( & V_3 -> V_15 , V_16 + F_7 ( V_25 ) ) ;
F_11 ( V_3 -> V_7 , V_23 , V_24 ) ;
return V_26 ;
}
static void F_12 ( void * V_3 )
{
struct V_2 * V_27 = V_3 ;
F_13 ( & V_27 -> V_15 ) ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = NULL ;
struct V_4 * V_5 = NULL ;
struct V_28 * V_29 ;
int error ;
V_29 = V_21 -> V_13 . V_30 ;
if ( ! V_29 )
return - V_31 ;
V_3 = F_15 ( & V_21 -> V_13 , sizeof( * V_3 ) , V_32 ) ;
if ( ! V_3 )
return - V_33 ;
V_3 -> V_7 = F_16 ( V_29 , L_1 ) ;
if ( ! V_3 -> V_7 ) {
F_17 ( & V_21 -> V_13 , L_2 ) ;
return - V_31 ;
}
if ( F_18 ( V_29 , L_3 , & V_3 -> V_12 ) ) {
V_3 -> V_12 = V_34 ;
F_19 ( & V_21 -> V_13 , L_4 ) ;
}
V_3 -> V_35 = F_20 ( V_29 , L_5 ) ;
V_3 -> V_18 = F_21 ( V_21 , 0 ) ;
if ( V_3 -> V_18 < 0 ) {
F_17 ( & V_21 -> V_13 , L_6 ) ;
return - V_36 ;
}
F_22 ( V_3 -> V_7 , V_37 , V_38 , V_38 ) ;
F_11 ( V_3 -> V_7 , V_23 , V_24 ) ;
F_23 ( & V_3 -> V_15 ,
F_1 , ( unsigned long ) V_3 ) ;
V_5 = F_24 ( & V_21 -> V_13 ) ;
if ( ! V_5 ) {
F_17 ( & V_21 -> V_13 , L_7 ) ;
return - V_33 ;
}
V_5 -> V_39 = V_21 -> V_39 ;
V_5 -> V_40 = L_8 ;
V_5 -> V_41 . V_42 = V_43 ;
F_25 ( V_5 , V_11 , V_3 -> V_12 ) ;
error = F_26 ( & V_21 -> V_13 , F_12 , V_3 ) ;
if ( error ) {
F_17 ( & V_21 -> V_13 , L_9 ) ;
return error ;
}
error = F_27 ( & V_21 -> V_13 , V_3 -> V_18 ,
F_8 ,
0 , V_21 -> V_39 , V_21 ) ;
if ( error ) {
F_17 ( & V_21 -> V_13 , L_10 ) ;
return error ;
}
error = F_28 ( V_5 ) ;
if ( error < 0 ) {
F_17 ( & V_21 -> V_13 , L_11 ) ;
F_29 ( V_5 ) ;
return error ;
}
V_3 -> V_5 = V_5 ;
F_30 ( V_21 , V_3 ) ;
F_31 ( & V_21 -> V_13 , V_3 -> V_35 ) ;
return 0 ;
}
static int F_32 ( struct V_44 * V_13 )
{
struct V_20 * V_21 = F_33 ( V_13 ) ;
struct V_2 * V_3 = F_9 ( V_21 ) ;
if ( F_34 ( & V_21 -> V_13 ) )
F_35 ( V_3 -> V_18 ) ;
return 0 ;
}
static int F_36 ( struct V_44 * V_13 )
{
struct V_20 * V_21 = F_33 ( V_13 ) ;
struct V_2 * V_3 = F_9 ( V_21 ) ;
if ( F_34 ( & V_21 -> V_13 ) )
F_37 ( V_3 -> V_18 ) ;
return 0 ;
}
