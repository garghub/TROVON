static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static T_1 F_3 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
struct V_3 * V_4 = V_2 -> V_5 ;
( void ) F_4 ( V_4 -> V_9 + F_5 ( V_10 ) ) ;
F_6 ( V_4 ) ;
return V_11 ;
}
static bool F_7 ( struct V_12 * V_2 )
{
struct V_13 * V_14 , * V_15 ;
F_8 (dev->of_node, ep) {
V_15 = F_9 ( V_14 ) ;
if ( V_15 )
return true ;
}
return false ;
}
static int F_10 ( struct V_12 * V_2 , bool V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_1 * V_19 ;
struct V_20 * V_21 ;
void T_2 * V_22 ;
int V_23 ;
if ( ! F_7 ( V_2 ) ) {
F_12 ( V_2 , L_1 ) ;
return - V_24 ;
}
V_19 = F_13 ( & V_25 , V_2 ) ;
if ( F_14 ( V_19 ) )
return F_15 ( V_19 ) ;
V_4 = F_16 ( V_2 , sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 ) {
V_23 = - V_27 ;
goto V_28;
}
V_19 -> V_5 = V_4 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_2 = V_2 ;
V_21 = F_17 ( V_18 , V_29 , L_2 ) ;
V_22 = F_18 ( V_2 , V_21 ) ;
if ( F_14 ( V_22 ) )
return F_15 ( V_22 ) ;
V_4 -> V_9 = V_22 ;
V_21 = F_17 ( V_18 , V_29 , L_3 ) ;
V_22 = F_19 ( V_2 , V_21 -> V_30 , F_20 ( V_21 ) ) ;
if ( ! V_22 )
return - V_31 ;
V_4 -> V_32 = F_21 ( V_2 , V_22 ,
& V_33 ) ;
if ( F_14 ( V_4 -> V_32 ) ) {
F_12 ( & V_18 -> V_2 , L_4 ) ;
return F_15 ( V_4 -> V_32 ) ;
}
V_21 = F_17 ( V_18 , V_29 , L_5 ) ;
V_22 = F_19 ( V_2 , V_21 -> V_30 , F_20 ( V_21 ) ) ;
if ( ! V_22 )
return - V_31 ;
V_4 -> V_34 = F_21 ( V_2 , V_22 ,
& V_33 ) ;
if ( F_14 ( V_4 -> V_34 ) ) {
F_12 ( & V_18 -> V_2 , L_6 ) ;
return F_15 ( V_4 -> V_34 ) ;
}
V_4 -> V_35 = F_22 ( V_18 , 0 ) ;
F_23 ( V_19 , 1 ) ;
F_24 ( V_19 ) ;
V_19 -> V_36 . V_37 = 3840 ;
V_19 -> V_36 . V_38 = 2160 ;
V_19 -> V_36 . V_39 = & V_40 ;
F_25 ( V_4 ) ;
F_26 ( V_4 ) ;
F_27 ( V_4 ) ;
V_23 = F_28 ( V_4 ) ;
if ( V_23 )
goto V_28;
if ( V_16 ) {
V_23 = F_29 ( V_19 -> V_2 , V_19 ) ;
if ( V_23 ) {
F_12 ( V_19 -> V_2 , L_7 ) ;
goto V_28;
}
}
V_23 = F_30 ( V_4 ) ;
if ( V_23 )
goto V_28;
V_23 = F_31 ( V_4 ) ;
if ( V_23 )
goto V_28;
V_23 = F_32 ( V_19 , V_4 -> V_35 ) ;
if ( V_23 )
goto V_28;
F_33 ( V_19 ) ;
V_4 -> V_6 = F_34 ( V_19 , 32 ,
V_19 -> V_36 . V_41 ) ;
if ( F_14 ( V_4 -> V_6 ) ) {
V_23 = F_15 ( V_4 -> V_6 ) ;
goto V_28;
}
F_35 ( V_19 ) ;
F_36 ( V_18 , V_4 ) ;
V_23 = F_37 ( V_19 , 0 ) ;
if ( V_23 )
goto V_28;
return 0 ;
V_28:
F_38 ( V_19 ) ;
return V_23 ;
}
static int F_39 ( struct V_12 * V_2 )
{
return F_10 ( V_2 , true ) ;
}
static void F_40 ( struct V_12 * V_2 )
{
struct V_1 * V_19 = F_41 ( V_2 ) ;
struct V_3 * V_4 = V_19 -> V_5 ;
F_42 ( V_19 ) ;
F_43 ( V_19 ) ;
F_44 ( V_4 -> V_6 ) ;
F_45 ( V_19 ) ;
F_38 ( V_19 ) ;
}
static int F_46 ( struct V_12 * V_2 , void * V_42 )
{
F_47 ( L_8 ,
V_2 -> V_43 , V_42 ) ;
return V_2 -> V_43 == V_42 ;
}
static int F_48 ( struct V_17 * V_18 ,
struct V_44 * * V_45 ,
struct V_13 * V_46 ,
struct V_13 * V_15 )
{
struct V_13 * V_14 , * V_47 ;
int V_48 = 1 ;
if ( F_49 ( V_49 , V_15 ) )
return 1 ;
F_50 ( & V_18 -> V_2 , V_45 , F_46 , V_15 ) ;
F_8 (remote, ep) {
V_47 = F_51 ( V_14 ) ;
if ( ! V_47 ||
V_47 == V_46 ||
! F_52 ( V_47 ) )
continue;
V_48 += F_48 ( V_18 , V_45 , V_15 , V_47 ) ;
F_53 ( V_47 ) ;
}
return V_48 ;
}
static int F_54 ( struct V_17 * V_18 )
{
struct V_44 * V_45 = NULL ;
struct V_13 * V_50 = V_18 -> V_2 . V_43 ;
struct V_13 * V_14 , * V_15 ;
int V_48 = 0 ;
F_8 (np, ep) {
V_15 = F_51 ( V_14 ) ;
if ( ! V_15 || ! F_52 ( V_15 ) )
continue;
V_48 += F_48 ( V_18 , & V_45 , V_50 , V_15 ) ;
}
if ( V_48 && ! V_45 )
return F_10 ( & V_18 -> V_2 , false ) ;
if ( V_48 ) {
F_55 ( & V_18 -> V_2 , L_9 , V_48 ) ;
return F_56 ( & V_18 -> V_2 ,
& V_51 ,
V_45 ) ;
}
return 0 ;
}
