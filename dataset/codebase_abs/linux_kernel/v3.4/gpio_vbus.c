static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
if ( ! V_5 )
return;
V_6 = V_2 -> V_7 ;
if ( V_3 ) {
F_2 ( V_5 , 0 , 1000 * V_3 ) ;
if ( ! V_6 ) {
F_3 ( V_5 ) ;
V_2 -> V_7 = 1 ;
}
} else {
if ( V_6 ) {
F_4 ( V_5 ) ;
V_2 -> V_7 = 0 ;
}
}
V_2 -> V_3 = V_3 ;
}
static int F_5 ( struct V_8 * V_9 )
{
int V_10 ;
V_10 = F_6 ( V_9 -> V_2 ) ;
if ( V_9 -> V_11 )
V_10 = ! V_10 ;
return V_10 ;
}
static void F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_2 =
F_8 ( V_13 , struct V_1 , V_13 ) ;
struct V_8 * V_9 = V_2 -> V_14 -> V_15 ;
int V_16 , V_17 ;
if ( ! V_2 -> V_18 . V_19 -> V_20 )
return;
V_16 = V_9 -> V_21 ;
if ( F_5 ( V_9 ) ) {
V_17 = V_22 ;
V_2 -> V_18 . V_23 = V_24 ;
V_2 -> V_18 . V_25 = V_17 ;
F_9 ( V_2 -> V_18 . V_19 -> V_20 ) ;
F_1 ( V_2 , 100 ) ;
if ( F_10 ( V_16 ) )
F_11 ( V_16 , ! V_9 -> V_26 ) ;
F_12 ( & V_2 -> V_18 . V_27 ,
V_17 , V_2 -> V_18 . V_19 -> V_20 ) ;
} else {
if ( F_10 ( V_16 ) )
F_11 ( V_16 , V_9 -> V_26 ) ;
F_1 ( V_2 , 0 ) ;
F_13 ( V_2 -> V_18 . V_19 -> V_20 ) ;
V_17 = V_28 ;
V_2 -> V_18 . V_23 = V_29 ;
V_2 -> V_18 . V_25 = V_17 ;
F_12 ( & V_2 -> V_18 . V_27 ,
V_17 , V_2 -> V_18 . V_19 -> V_20 ) ;
}
}
static T_1 F_14 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_8 * V_9 = V_33 -> V_14 . V_15 ;
struct V_1 * V_2 = F_15 ( V_33 ) ;
struct V_34 * V_19 = V_2 -> V_18 . V_19 ;
F_16 ( & V_33 -> V_14 , L_1 ,
F_5 ( V_9 ) ? L_2 : L_3 ,
V_19 -> V_20 ? V_19 -> V_20 -> V_35 : L_4 ) ;
if ( V_19 -> V_20 )
F_17 ( & V_2 -> V_13 ) ;
return V_36 ;
}
static int F_18 ( struct V_34 * V_19 ,
struct V_37 * V_20 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_32 * V_33 ;
int V_16 , V_30 ;
V_2 = F_8 ( V_19 -> V_18 , struct V_1 , V_18 ) ;
V_33 = F_19 ( V_2 -> V_14 ) ;
V_9 = V_2 -> V_14 -> V_15 ;
V_30 = F_20 ( V_9 -> V_2 ) ;
V_16 = V_9 -> V_21 ;
if ( ! V_20 ) {
F_16 ( & V_33 -> V_14 , L_5 ,
V_19 -> V_20 -> V_35 ) ;
if ( F_10 ( V_16 ) )
F_11 ( V_16 , V_9 -> V_26 ) ;
F_1 ( V_2 , 0 ) ;
F_13 ( V_19 -> V_20 ) ;
V_19 -> V_18 -> V_23 = V_38 ;
V_19 -> V_20 = NULL ;
return 0 ;
}
V_19 -> V_20 = V_20 ;
F_16 ( & V_33 -> V_14 , L_6 , V_20 -> V_35 ) ;
F_14 ( V_30 , V_33 ) ;
return 0 ;
}
static int F_21 ( struct V_39 * V_18 , unsigned V_3 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_18 , struct V_1 , V_18 ) ;
if ( V_18 -> V_23 == V_24 )
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_18 , int V_40 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_18 , struct V_1 , V_18 ) ;
return F_21 ( V_18 , V_40 ? 0 : V_2 -> V_3 ) ;
}
static int T_2 F_23 ( struct V_32 * V_33 )
{
struct V_8 * V_9 = V_33 -> V_14 . V_15 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_43 , V_16 , V_30 ;
if ( ! V_9 || ! F_10 ( V_9 -> V_2 ) )
return - V_44 ;
V_16 = V_9 -> V_2 ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_2 -> V_18 . V_19 = F_24 ( sizeof( struct V_34 ) , V_45 ) ;
if ( ! V_2 -> V_18 . V_19 ) {
F_25 ( V_2 ) ;
return - V_46 ;
}
F_26 ( V_33 , V_2 ) ;
V_2 -> V_14 = & V_33 -> V_14 ;
V_2 -> V_18 . V_47 = L_7 ;
V_2 -> V_18 . V_48 = F_21 ;
V_2 -> V_18 . V_49 = F_22 ;
V_2 -> V_18 . V_23 = V_38 ;
V_2 -> V_18 . V_19 -> V_18 = & V_2 -> V_18 ;
V_2 -> V_18 . V_19 -> V_50 = F_18 ;
V_43 = F_27 ( V_16 , L_8 ) ;
if ( V_43 ) {
F_28 ( & V_33 -> V_14 , L_9 ,
V_16 , V_43 ) ;
goto V_51;
}
F_29 ( V_16 ) ;
V_42 = F_30 ( V_33 , V_52 , 0 ) ;
if ( V_42 ) {
V_30 = V_42 -> V_53 ;
V_42 -> V_54 &= V_55 ;
V_42 -> V_54 |= V_56 | V_57 ;
} else
V_30 = F_20 ( V_16 ) ;
V_16 = V_9 -> V_21 ;
if ( F_10 ( V_16 ) ) {
V_43 = F_27 ( V_16 , L_10 ) ;
if ( V_43 ) {
F_28 ( & V_33 -> V_14 ,
L_11 ,
V_16 , V_43 ) ;
F_31 ( V_9 -> V_2 ) ;
goto V_51;
}
F_32 ( V_16 , V_9 -> V_26 ) ;
}
V_43 = F_33 ( V_30 , F_14 , V_58 ,
L_8 , V_33 ) ;
if ( V_43 ) {
F_28 ( & V_33 -> V_14 , L_12 ,
V_30 , V_43 ) ;
goto V_59;
}
F_34 ( & V_2 -> V_18 . V_27 ) ;
F_35 ( & V_2 -> V_13 , F_7 ) ;
V_2 -> V_5 = F_36 ( & V_33 -> V_14 , L_13 ) ;
if ( F_37 ( V_2 -> V_5 ) ) {
F_16 ( & V_33 -> V_14 , L_14 ,
F_38 ( V_2 -> V_5 ) ) ;
V_2 -> V_5 = NULL ;
}
V_43 = F_39 ( & V_2 -> V_18 ) ;
if ( V_43 ) {
F_28 ( & V_33 -> V_14 , L_15 ,
V_43 ) ;
goto V_60;
}
return 0 ;
V_60:
F_40 ( V_30 , & V_33 -> V_14 ) ;
V_59:
if ( F_10 ( V_9 -> V_21 ) )
F_31 ( V_9 -> V_21 ) ;
F_31 ( V_9 -> V_2 ) ;
V_51:
F_26 ( V_33 , NULL ) ;
F_25 ( V_2 -> V_18 . V_19 ) ;
F_25 ( V_2 ) ;
return V_43 ;
}
static int T_3 F_41 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_15 ( V_33 ) ;
struct V_8 * V_9 = V_33 -> V_14 . V_15 ;
int V_16 = V_9 -> V_2 ;
F_42 ( V_2 -> V_5 ) ;
F_39 ( NULL ) ;
F_40 ( F_20 ( V_16 ) , & V_33 -> V_14 ) ;
if ( F_10 ( V_9 -> V_21 ) )
F_31 ( V_9 -> V_21 ) ;
F_31 ( V_16 ) ;
F_26 ( V_33 , NULL ) ;
F_25 ( V_2 -> V_18 . V_19 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_61 , F_23 ) ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_61 ) ;
}
