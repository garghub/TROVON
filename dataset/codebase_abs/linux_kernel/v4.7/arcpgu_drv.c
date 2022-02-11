static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 , bool V_9 )
{
return F_4 ( V_2 , V_8 , false ) ;
}
static void F_5 ( struct V_1 * V_10 )
{
F_6 ( V_10 ) ;
V_10 -> V_11 . V_12 = 0 ;
V_10 -> V_11 . V_13 = 0 ;
V_10 -> V_11 . V_14 = 1920 ;
V_10 -> V_11 . V_15 = 1080 ;
V_10 -> V_11 . V_16 = & V_17 ;
}
int F_7 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
int V_22 ;
V_22 = F_8 ( V_19 , V_21 ) ;
if ( V_22 )
return V_22 ;
V_21 -> V_23 = F_9 ( F_10 ( V_21 -> V_24 ) ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_10 , struct V_25 * V_18 )
{
struct V_3 * V_4 = V_10 -> V_5 ;
struct V_26 * V_27 , * V_28 ;
unsigned long V_29 ;
F_12 ( & V_10 -> V_30 , V_29 ) ;
F_13 (e, t, &arcpgu->event_list, base.link) {
if ( V_27 -> V_31 . V_32 != V_18 )
continue;
F_14 ( & V_27 -> V_31 . V_33 ) ;
V_27 -> V_31 . V_34 ( & V_27 -> V_31 ) ;
}
F_15 ( & V_10 -> V_30 , V_29 ) ;
}
static void F_16 ( struct V_1 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_5 ;
F_17 ( V_4 -> V_6 ) ;
}
static int F_18 ( struct V_1 * V_10 )
{
struct V_35 * V_36 = F_19 ( V_10 -> V_2 ) ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_22 ;
V_4 = F_20 ( & V_36 -> V_2 , sizeof( * V_4 ) , V_41 ) ;
if ( V_4 == NULL )
return - V_42 ;
V_10 -> V_5 = V_4 ;
V_4 -> V_43 = F_21 ( V_10 -> V_2 , L_1 ) ;
if ( F_22 ( V_4 -> V_43 ) )
return F_23 ( V_4 -> V_43 ) ;
F_24 ( & V_4 -> V_44 ) ;
F_5 ( V_10 ) ;
V_40 = F_25 ( V_36 , V_45 , 0 ) ;
V_4 -> V_46 = F_26 ( & V_36 -> V_2 , V_40 ) ;
if ( F_22 ( V_4 -> V_46 ) ) {
F_27 ( V_10 -> V_2 , L_2 ) ;
return F_23 ( V_4 -> V_46 ) ;
}
F_28 ( V_10 -> V_2 , L_3 ,
F_29 ( V_4 , V_47 ) ) ;
V_22 = F_30 ( V_10 -> V_2 ) ;
if ( V_22 && V_22 != - V_48 )
return V_22 ;
if ( F_31 ( V_10 -> V_2 , F_32 ( 32 ) ) )
return - V_48 ;
if ( F_33 ( V_10 ) < 0 )
return - V_48 ;
V_38 = F_34 ( V_10 -> V_2 -> V_49 , L_4 , 0 ) ;
if ( ! V_38 ) {
F_27 ( V_10 -> V_2 , L_5 ) ;
return - V_48 ;
}
V_22 = F_35 ( V_10 , V_38 ) ;
if ( V_22 < 0 )
return V_22 ;
F_36 ( V_10 ) ;
F_37 ( V_10 ) ;
V_4 -> V_6 = F_38 ( V_10 , 16 ,
V_10 -> V_11 . V_50 ,
V_10 -> V_11 . V_51 ) ;
if ( F_22 ( V_4 -> V_6 ) ) {
V_22 = F_23 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return - V_48 ;
}
F_39 ( V_36 , V_4 ) ;
return 0 ;
}
int F_40 ( struct V_1 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_5 ;
if ( V_4 -> V_6 ) {
F_41 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_42 ( V_10 ) ;
F_43 ( V_10 ) ;
F_44 ( V_10 ) ;
return 0 ;
}
static int F_45 ( struct V_35 * V_36 )
{
struct V_1 * V_10 ;
int V_22 ;
V_10 = F_46 ( & V_52 , & V_36 -> V_2 ) ;
if ( ! V_10 )
return - V_42 ;
V_22 = F_18 ( V_10 ) ;
if ( V_22 )
goto V_53;
V_22 = F_47 ( V_10 , 0 ) ;
if ( V_22 )
goto V_54;
V_22 = F_48 ( V_10 ) ;
if ( V_22 )
goto V_55;
return 0 ;
V_55:
F_49 ( V_10 ) ;
V_54:
F_40 ( V_10 ) ;
V_53:
F_50 ( V_10 ) ;
return V_22 ;
}
static int F_51 ( struct V_35 * V_36 )
{
struct V_1 * V_10 = F_52 ( V_36 ) ;
F_53 ( V_10 ) ;
F_49 ( V_10 ) ;
F_40 ( V_10 ) ;
F_50 ( V_10 ) ;
return 0 ;
}
