static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_7 )
{
F_4 ( V_7 ) ;
V_7 -> V_8 . V_9 = 0 ;
V_7 -> V_8 . V_10 = 0 ;
V_7 -> V_8 . V_11 = 1920 ;
V_7 -> V_8 . V_12 = 1080 ;
V_7 -> V_8 . V_13 = & V_14 ;
}
static int F_5 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_19 ;
V_19 = F_6 ( V_16 , V_18 ) ;
if ( V_19 )
return V_19 ;
V_18 -> V_20 = F_7 ( F_8 ( V_18 -> V_21 ) ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_5 ;
F_10 ( V_4 -> V_6 ) ;
}
static int F_11 ( struct V_1 * V_7 )
{
struct V_22 * V_23 = F_12 ( V_7 -> V_2 ) ;
struct V_3 * V_4 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_19 ;
V_4 = F_13 ( & V_23 -> V_2 , sizeof( * V_4 ) , V_28 ) ;
if ( V_4 == NULL )
return - V_29 ;
V_7 -> V_5 = V_4 ;
V_4 -> V_30 = F_14 ( V_7 -> V_2 , L_1 ) ;
if ( F_15 ( V_4 -> V_30 ) )
return F_16 ( V_4 -> V_30 ) ;
F_3 ( V_7 ) ;
V_27 = F_17 ( V_23 , V_31 , 0 ) ;
V_4 -> V_32 = F_18 ( & V_23 -> V_2 , V_27 ) ;
if ( F_15 ( V_4 -> V_32 ) )
return F_16 ( V_4 -> V_32 ) ;
F_19 ( V_7 -> V_2 , L_2 ,
F_20 ( V_4 , V_33 ) ) ;
V_19 = F_21 ( V_7 -> V_2 ) ;
if ( V_19 && V_19 != - V_34 )
return V_19 ;
if ( F_22 ( V_7 -> V_2 , F_23 ( 32 ) ) )
return - V_34 ;
if ( F_24 ( V_7 ) < 0 )
return - V_34 ;
V_25 = F_25 ( V_7 -> V_2 -> V_35 , L_3 , 0 ) ;
if ( V_25 ) {
V_19 = F_26 ( V_7 , V_25 ) ;
F_27 ( V_25 ) ;
if ( V_19 < 0 )
return V_19 ;
} else {
V_19 = F_28 ( V_7 , NULL ) ;
if ( V_19 < 0 )
return V_19 ;
}
F_29 ( V_7 ) ;
F_30 ( V_7 ) ;
V_4 -> V_6 = F_31 ( V_7 , 16 ,
V_7 -> V_8 . V_36 ,
V_7 -> V_8 . V_37 ) ;
if ( F_15 ( V_4 -> V_6 ) ) {
V_19 = F_16 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return - V_34 ;
}
F_32 ( V_23 , V_4 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_5 ;
if ( V_4 -> V_6 ) {
F_34 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_35 ( V_7 ) ;
F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
return 0 ;
}
static int F_38 ( struct V_22 * V_23 )
{
struct V_1 * V_7 ;
int V_19 ;
V_7 = F_39 ( & V_38 , & V_23 -> V_2 ) ;
if ( F_15 ( V_7 ) )
return F_16 ( V_7 ) ;
V_19 = F_11 ( V_7 ) ;
if ( V_19 )
goto V_39;
V_19 = F_40 ( V_7 , 0 ) ;
if ( V_19 )
goto V_40;
return 0 ;
V_40:
F_33 ( V_7 ) ;
V_39:
F_41 ( V_7 ) ;
return V_19 ;
}
static int F_42 ( struct V_22 * V_23 )
{
struct V_1 * V_7 = F_43 ( V_23 ) ;
F_44 ( V_7 ) ;
F_33 ( V_7 ) ;
F_41 ( V_7 ) ;
return 0 ;
}
