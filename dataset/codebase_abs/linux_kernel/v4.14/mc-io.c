static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int error ;
if ( F_2 ( ! V_4 ) )
return - V_5 ;
if ( F_2 ( V_2 -> V_4 ) )
return - V_5 ;
if ( F_2 ( V_4 -> V_2 ) )
return - V_5 ;
error = F_3 ( V_2 ,
0 ,
V_4 -> V_6 . V_7 ,
& V_4 -> V_8 ) ;
if ( error < 0 )
return error ;
V_2 -> V_4 = V_4 ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
int error ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_2 ( ! V_4 ) )
return;
if ( F_2 ( V_4 -> V_2 != V_2 ) )
return;
error = F_5 ( V_2 ,
0 ,
V_4 -> V_8 ) ;
if ( error < 0 ) {
F_6 ( & V_4 -> V_9 , L_1 ,
error ) ;
}
V_2 -> V_4 = NULL ;
V_4 -> V_2 = NULL ;
}
int T_1 F_7 ( struct V_10 * V_9 ,
T_2 V_11 ,
T_3 V_12 ,
struct V_3 * V_4 ,
T_3 V_13 , struct V_1 * * V_14 )
{
int error ;
struct V_1 * V_2 ;
void T_4 * V_15 ;
struct V_16 * V_17 ;
V_2 = F_8 ( V_9 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 )
return - V_19 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_20 = V_11 ;
V_2 -> V_21 = V_12 ;
if ( V_13 & V_22 )
F_9 ( & V_2 -> V_23 ) ;
else
F_10 ( & V_2 -> V_24 ) ;
V_17 = F_11 ( V_9 ,
V_11 ,
V_12 ,
L_2 ) ;
if ( ! V_17 ) {
F_6 ( V_9 ,
L_3 ,
& V_11 ) ;
return - V_25 ;
}
V_15 = F_12 ( V_9 ,
V_11 ,
V_12 ) ;
if ( ! V_15 ) {
F_6 ( V_9 ,
L_4 ,
& V_11 ) ;
return - V_26 ;
}
V_2 -> V_27 = V_15 ;
if ( V_4 ) {
error = F_1 ( V_2 , V_4 ) ;
if ( error < 0 )
goto V_28;
}
* V_14 = V_2 ;
return 0 ;
V_28:
F_13 ( V_2 ) ;
return error ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 )
F_4 ( V_2 ) ;
F_14 ( V_2 -> V_9 , V_2 -> V_27 ) ;
F_15 ( V_2 -> V_9 ,
V_2 -> V_20 ,
V_2 -> V_21 ) ;
V_2 -> V_27 = NULL ;
F_16 ( V_2 -> V_9 , V_2 ) ;
}
int T_1 F_17 ( struct V_3 * V_29 ,
T_5 V_30 ,
struct V_1 * * V_14 )
{
struct V_3 * V_31 ;
struct V_32 * V_33 ;
T_2 V_11 ;
T_6 V_12 ;
struct V_3 * V_4 ;
int error = - V_5 ;
struct V_34 * V_16 = NULL ;
struct V_1 * V_2 = NULL ;
if ( V_29 -> V_13 & V_35 ) {
V_31 = V_29 ;
} else {
if ( F_2 ( ! F_18 ( V_29 -> V_9 . V_36 ) ) )
return error ;
V_31 = F_19 ( V_29 -> V_9 . V_36 ) ;
}
V_33 = F_20 ( V_31 ) ;
* V_14 = NULL ;
error = F_21 ( V_33 , V_37 , & V_16 ) ;
if ( error < 0 )
return error ;
error = - V_5 ;
V_4 = V_16 -> V_38 ;
if ( F_2 ( ! V_4 ) )
goto V_39;
if ( V_4 -> V_6 . V_40 < V_41 ||
( V_4 -> V_6 . V_40 == V_41 &&
V_4 -> V_6 . V_42 < V_43 ) ) {
F_6 ( & V_4 -> V_9 ,
L_5 ,
V_4 -> V_6 . V_40 ,
V_4 -> V_6 . V_42 ) ;
error = - V_44 ;
goto V_39;
}
if ( F_2 ( V_4 -> V_6 . V_45 == 0 ) )
goto V_39;
V_11 = V_4 -> V_46 [ 0 ] . V_47 ;
V_12 = F_22 ( V_4 -> V_46 ) ;
if ( F_2 ( V_12 != V_31 -> V_2 -> V_21 ) )
goto V_39;
error = F_7 ( & V_31 -> V_9 ,
V_11 ,
V_12 , V_4 ,
V_30 , & V_2 ) ;
if ( error < 0 )
goto V_39;
* V_14 = V_2 ;
return 0 ;
V_39:
F_23 ( V_16 ) ;
return error ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_34 * V_16 ;
V_4 = V_2 -> V_4 ;
if ( F_2 ( ! V_4 ) )
return;
V_16 = V_4 -> V_16 ;
if ( F_2 ( ! V_16 || V_16 -> type != V_37 ) )
return;
if ( F_2 ( V_16 -> V_38 != V_4 ) )
return;
F_13 ( V_2 ) ;
F_23 ( V_16 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
int error ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_2 ( ! V_4 ) )
return - V_5 ;
error = F_26 ( V_2 , 0 , V_4 -> V_8 ) ;
if ( error < 0 ) {
F_6 ( & V_4 -> V_9 , L_6 , error ) ;
return error ;
}
return 0 ;
}
