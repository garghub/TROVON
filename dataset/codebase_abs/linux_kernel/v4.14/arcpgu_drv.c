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
static void F_5 ( struct V_1 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_5 ;
F_6 ( V_4 -> V_6 ) ;
}
static int F_7 ( struct V_1 * V_7 )
{
struct V_15 * V_16 = F_8 ( V_7 -> V_2 ) ;
struct V_3 * V_4 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 ;
V_4 = F_9 ( & V_16 -> V_2 , sizeof( * V_4 ) , V_22 ) ;
if ( V_4 == NULL )
return - V_23 ;
V_7 -> V_5 = V_4 ;
V_4 -> V_24 = F_10 ( V_7 -> V_2 , L_1 ) ;
if ( F_11 ( V_4 -> V_24 ) )
return F_12 ( V_4 -> V_24 ) ;
F_3 ( V_7 ) ;
V_20 = F_13 ( V_16 , V_25 , 0 ) ;
V_4 -> V_26 = F_14 ( & V_16 -> V_2 , V_20 ) ;
if ( F_11 ( V_4 -> V_26 ) )
return F_12 ( V_4 -> V_26 ) ;
F_15 ( V_7 -> V_2 , L_2 ,
F_16 ( V_4 , V_27 ) ) ;
V_21 = F_17 ( V_7 -> V_2 ) ;
if ( V_21 && V_21 != - V_28 )
return V_21 ;
if ( F_18 ( V_7 -> V_2 , F_19 ( 32 ) ) )
return - V_28 ;
if ( F_20 ( V_7 ) < 0 )
return - V_28 ;
V_18 = F_21 ( V_7 -> V_2 -> V_29 , L_3 , 0 ) ;
if ( V_18 ) {
V_21 = F_22 ( V_7 , V_18 ) ;
F_23 ( V_18 ) ;
if ( V_21 < 0 )
return V_21 ;
} else {
V_21 = F_24 ( V_7 , NULL ) ;
if ( V_21 < 0 )
return V_21 ;
}
F_25 ( V_7 ) ;
F_26 ( V_7 ) ;
V_4 -> V_6 = F_27 ( V_7 , 16 ,
V_7 -> V_8 . V_30 ) ;
if ( F_11 ( V_4 -> V_6 ) ) {
V_21 = F_12 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return - V_28 ;
}
F_28 ( V_16 , V_7 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_7 )
{
struct V_3 * V_4 = V_7 -> V_5 ;
if ( V_4 -> V_6 ) {
F_30 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_31 ( V_7 ) ;
F_32 ( V_7 ) ;
return 0 ;
}
static int F_33 ( struct V_31 * V_32 , void * V_33 )
{
struct V_34 * V_35 = (struct V_34 * ) V_32 -> V_36 ;
struct V_1 * V_7 = V_35 -> V_37 -> V_2 ;
struct V_3 * V_4 = V_7 -> V_5 ;
unsigned long V_38 = F_34 ( V_4 -> V_24 ) ;
unsigned long V_39 = V_4 -> V_40 . V_41 . V_42 * 1000 ;
F_35 ( V_32 , L_4 , V_38 ) ;
F_35 ( V_32 , L_5 , V_39 ) ;
return 0 ;
}
static int F_36 ( struct V_43 * V_37 )
{
return F_37 ( V_44 ,
F_38 ( V_44 ) , V_37 -> V_45 , V_37 ) ;
}
static int F_39 ( struct V_15 * V_16 )
{
struct V_1 * V_7 ;
int V_21 ;
V_7 = F_40 ( & V_46 , & V_16 -> V_2 ) ;
if ( F_11 ( V_7 ) )
return F_12 ( V_7 ) ;
V_21 = F_7 ( V_7 ) ;
if ( V_21 )
goto V_47;
V_21 = F_41 ( V_7 , 0 ) ;
if ( V_21 )
goto V_48;
return 0 ;
V_48:
F_29 ( V_7 ) ;
V_47:
F_42 ( V_7 ) ;
return V_21 ;
}
static int F_43 ( struct V_15 * V_16 )
{
struct V_1 * V_7 = F_44 ( V_16 ) ;
F_45 ( V_7 ) ;
F_29 ( V_7 ) ;
F_42 ( V_7 ) ;
return 0 ;
}
