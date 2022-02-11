static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( V_4 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_6 ( V_4 ) ;
}
static T_1 F_7 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
struct V_3 * V_4 = V_2 -> V_5 ;
( void ) F_8 ( V_4 -> V_10 + F_9 ( V_11 ) ) ;
F_10 ( V_4 ) ;
return V_12 ;
}
static bool F_11 ( struct V_13 * V_2 )
{
struct V_14 * V_15 , * V_16 ;
F_12 (dev->of_node, ep) {
V_16 = F_13 ( V_15 ) ;
if ( V_16 )
return true ;
}
return false ;
}
static int F_14 ( struct V_17 * V_18 )
{
struct V_13 * V_2 = & V_18 -> V_2 ;
struct V_3 * V_4 ;
struct V_1 * V_19 ;
struct V_20 * V_21 ;
void T_2 * V_22 ;
int V_23 ;
if ( ! F_11 ( V_2 ) ) {
F_15 ( V_2 , L_1 ) ;
return - V_24 ;
}
V_19 = F_16 ( & V_25 , V_2 ) ;
if ( F_17 ( V_19 ) )
return F_18 ( V_19 ) ;
V_4 = F_19 ( V_2 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 ) {
V_23 = - V_27 ;
goto V_28;
}
V_19 -> V_5 = V_4 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_2 = V_2 ;
V_21 = F_20 ( V_18 , V_29 , L_2 ) ;
V_22 = F_21 ( V_2 , V_21 ) ;
if ( F_17 ( V_22 ) )
return F_18 ( V_22 ) ;
V_4 -> V_10 = V_22 ;
V_21 = F_20 ( V_18 , V_29 , L_3 ) ;
V_22 = F_22 ( V_2 , V_21 -> V_30 , F_23 ( V_21 ) ) ;
if ( ! V_22 )
return - V_31 ;
V_4 -> V_32 = F_24 ( V_2 , V_22 ,
& V_33 ) ;
if ( F_17 ( V_4 -> V_32 ) ) {
F_15 ( & V_18 -> V_2 , L_4 ) ;
return F_18 ( V_4 -> V_32 ) ;
}
V_21 = F_20 ( V_18 , V_29 , L_5 ) ;
V_22 = F_22 ( V_2 , V_21 -> V_30 , F_23 ( V_21 ) ) ;
if ( ! V_22 )
return - V_31 ;
V_4 -> V_34 = F_24 ( V_2 , V_22 ,
& V_33 ) ;
if ( F_17 ( V_4 -> V_34 ) ) {
F_15 ( & V_18 -> V_2 , L_6 ) ;
return F_18 ( V_4 -> V_34 ) ;
}
V_4 -> V_35 = F_25 ( V_18 , 0 ) ;
F_26 ( V_19 , 1 ) ;
F_27 ( V_19 ) ;
V_23 = F_28 ( V_4 ) ;
if ( V_23 )
goto V_28;
F_29 ( V_4 ) ;
F_30 ( V_4 ) ;
F_31 ( V_4 ) ;
V_23 = F_32 ( V_4 ) ;
if ( V_23 )
goto V_28;
V_23 = F_33 ( V_4 ) ;
if ( V_23 )
goto V_28;
V_23 = F_34 ( V_19 , V_4 -> V_35 ) ;
if ( V_23 )
goto V_28;
F_35 ( V_19 ) ;
V_19 -> V_36 . V_37 = 8192 ;
V_19 -> V_36 . V_38 = 8192 ;
V_19 -> V_36 . V_39 = & V_40 ;
V_4 -> V_6 = F_36 ( V_19 , 32 ,
V_19 -> V_36 . V_41 ,
V_19 -> V_36 . V_42 ) ;
if ( F_17 ( V_4 -> V_6 ) ) {
V_23 = F_18 ( V_4 -> V_6 ) ;
goto V_28;
}
F_37 ( V_19 ) ;
F_38 ( V_18 , V_4 ) ;
V_23 = F_39 ( V_19 , 0 ) ;
if ( V_23 )
goto V_28;
return 0 ;
V_28:
F_40 ( V_19 ) ;
return V_23 ;
}
static int F_41 ( struct V_17 * V_18 )
{
struct V_1 * V_19 = F_42 ( & V_18 -> V_2 ) ;
struct V_3 * V_4 = V_19 -> V_5 ;
F_43 ( V_19 ) ;
F_44 ( V_19 ) ;
F_45 ( V_4 -> V_6 ) ;
F_46 ( V_19 ) ;
F_47 ( V_19 ) ;
F_40 ( V_19 ) ;
return 0 ;
}
