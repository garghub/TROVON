static void F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
int V_7 ;
if ( ! V_5 )
return;
V_6 = V_2 -> V_8 ;
if ( V_3 ) {
F_2 ( V_5 , 0 , 1000 * V_3 ) ;
if ( ! V_6 ) {
V_7 = F_3 ( V_5 ) ;
if ( V_7 < 0 )
return;
V_2 -> V_8 = 1 ;
}
} else {
if ( V_6 ) {
V_7 = F_4 ( V_5 ) ;
if ( V_7 < 0 )
return;
V_2 -> V_8 = 0 ;
}
}
V_2 -> V_3 = V_3 ;
}
static int F_5 ( struct V_9 * V_10 )
{
int V_11 ;
V_11 = F_6 ( V_10 -> V_2 ) ;
if ( V_10 -> V_12 )
V_11 = ! V_11 ;
return V_11 ;
}
static void F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_2 =
F_8 ( V_14 , struct V_1 , V_14 . V_14 ) ;
struct V_9 * V_10 = F_9 ( V_2 -> V_15 ) ;
int V_16 , V_17 , V_11 ;
if ( ! V_2 -> V_18 . V_19 -> V_20 )
return;
V_11 = F_5 ( V_10 ) ;
if ( ( V_11 ^ V_2 -> V_11 ) == 0 )
return;
V_2 -> V_11 = V_11 ;
V_16 = V_10 -> V_21 ;
if ( V_11 ) {
V_17 = V_22 ;
V_2 -> V_18 . V_23 = V_24 ;
V_2 -> V_18 . V_25 = V_17 ;
F_10 ( V_2 -> V_18 . V_19 -> V_20 ) ;
F_1 ( V_2 , 100 ) ;
if ( F_11 ( V_16 ) )
F_12 ( V_16 , ! V_10 -> V_26 ) ;
F_13 ( & V_2 -> V_18 . V_27 ,
V_17 , V_2 -> V_18 . V_19 -> V_20 ) ;
} else {
if ( F_11 ( V_16 ) )
F_12 ( V_16 , V_10 -> V_26 ) ;
F_1 ( V_2 , 0 ) ;
F_14 ( V_2 -> V_18 . V_19 -> V_20 ) ;
V_17 = V_28 ;
V_2 -> V_18 . V_23 = V_29 ;
V_2 -> V_18 . V_25 = V_17 ;
F_13 ( & V_2 -> V_18 . V_27 ,
V_17 , V_2 -> V_18 . V_19 -> V_20 ) ;
}
}
static T_1 F_15 ( int V_30 , void * V_31 )
{
struct V_32 * V_33 = V_31 ;
struct V_9 * V_10 = F_9 ( & V_33 -> V_15 ) ;
struct V_1 * V_2 = F_16 ( V_33 ) ;
struct V_34 * V_19 = V_2 -> V_18 . V_19 ;
F_17 ( & V_33 -> V_15 , L_1 ,
F_5 ( V_10 ) ? L_2 : L_3 ,
V_19 -> V_20 ? V_19 -> V_20 -> V_35 : L_4 ) ;
if ( V_19 -> V_20 )
F_18 ( & V_2 -> V_14 , F_19 ( 100 ) ) ;
return V_36 ;
}
static int F_20 ( struct V_34 * V_19 ,
struct V_37 * V_20 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_32 * V_33 ;
int V_16 ;
V_2 = F_8 ( V_19 -> V_18 , struct V_1 , V_18 ) ;
V_33 = F_21 ( V_2 -> V_15 ) ;
V_10 = F_9 ( V_2 -> V_15 ) ;
V_16 = V_10 -> V_21 ;
if ( ! V_20 ) {
F_17 ( & V_33 -> V_15 , L_5 ,
V_19 -> V_20 -> V_35 ) ;
if ( F_11 ( V_16 ) )
F_12 ( V_16 , V_10 -> V_26 ) ;
F_1 ( V_2 , 0 ) ;
F_14 ( V_19 -> V_20 ) ;
V_19 -> V_18 -> V_23 = V_38 ;
V_19 -> V_20 = NULL ;
return 0 ;
}
V_19 -> V_20 = V_20 ;
F_17 ( & V_33 -> V_15 , L_6 , V_20 -> V_35 ) ;
V_2 -> V_11 = 0 ;
F_15 ( V_2 -> V_30 , V_33 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_18 , unsigned V_3 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_18 , struct V_1 , V_18 ) ;
if ( V_18 -> V_23 == V_24 )
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_39 * V_18 , int V_40 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_18 , struct V_1 , V_18 ) ;
return F_22 ( V_18 , V_40 ? 0 : V_2 -> V_3 ) ;
}
static int F_24 ( struct V_32 * V_33 )
{
struct V_9 * V_10 = F_9 ( & V_33 -> V_15 ) ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_43 , V_16 , V_30 ;
unsigned long V_44 ;
if ( ! V_10 || ! F_11 ( V_10 -> V_2 ) )
return - V_45 ;
V_16 = V_10 -> V_2 ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_18 . V_19 = F_25 ( sizeof( struct V_34 ) , V_46 ) ;
if ( ! V_2 -> V_18 . V_19 ) {
F_26 ( V_2 ) ;
return - V_47 ;
}
F_27 ( V_33 , V_2 ) ;
V_2 -> V_15 = & V_33 -> V_15 ;
V_2 -> V_18 . V_48 = L_7 ;
V_2 -> V_18 . V_15 = V_2 -> V_15 ;
V_2 -> V_18 . V_49 = F_22 ;
V_2 -> V_18 . V_50 = F_23 ;
V_2 -> V_18 . V_23 = V_38 ;
V_2 -> V_18 . V_19 -> V_18 = & V_2 -> V_18 ;
V_2 -> V_18 . V_19 -> V_51 = F_20 ;
V_43 = F_28 ( V_16 , L_8 ) ;
if ( V_43 ) {
F_29 ( & V_33 -> V_15 , L_9 ,
V_16 , V_43 ) ;
goto V_52;
}
F_30 ( V_16 ) ;
V_42 = F_31 ( V_33 , V_53 , 0 ) ;
if ( V_42 ) {
V_30 = V_42 -> V_54 ;
V_44 = ( V_42 -> V_55 & V_56 ) | V_57 ;
} else {
V_30 = F_32 ( V_16 ) ;
V_44 = V_58 ;
}
V_2 -> V_30 = V_30 ;
V_16 = V_10 -> V_21 ;
if ( F_11 ( V_16 ) ) {
V_43 = F_28 ( V_16 , L_10 ) ;
if ( V_43 ) {
F_29 ( & V_33 -> V_15 ,
L_11 ,
V_16 , V_43 ) ;
F_33 ( V_10 -> V_2 ) ;
goto V_52;
}
F_34 ( V_16 , V_10 -> V_26 ) ;
}
V_43 = F_35 ( V_30 , F_15 , V_44 , L_8 , V_33 ) ;
if ( V_43 ) {
F_29 ( & V_33 -> V_15 , L_12 ,
V_30 , V_43 ) ;
goto V_59;
}
F_36 ( & V_2 -> V_14 , F_7 ) ;
V_2 -> V_5 = F_37 ( & V_33 -> V_15 , L_13 ) ;
if ( F_38 ( V_2 -> V_5 ) ) {
F_17 ( & V_33 -> V_15 , L_14 ,
F_39 ( V_2 -> V_5 ) ) ;
V_2 -> V_5 = NULL ;
}
V_43 = F_40 ( & V_2 -> V_18 , V_60 ) ;
if ( V_43 ) {
F_29 ( & V_33 -> V_15 , L_15 ,
V_43 ) ;
goto V_61;
}
F_41 ( & V_33 -> V_15 , V_10 -> V_62 ) ;
return 0 ;
V_61:
F_42 ( V_2 -> V_5 ) ;
F_43 ( V_30 , V_33 ) ;
V_59:
if ( F_11 ( V_10 -> V_21 ) )
F_33 ( V_10 -> V_21 ) ;
F_33 ( V_10 -> V_2 ) ;
V_52:
F_26 ( V_2 -> V_18 . V_19 ) ;
F_26 ( V_2 ) ;
return V_43 ;
}
static int F_44 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_16 ( V_33 ) ;
struct V_9 * V_10 = F_9 ( & V_33 -> V_15 ) ;
int V_16 = V_10 -> V_2 ;
F_41 ( & V_33 -> V_15 , 0 ) ;
F_45 ( & V_2 -> V_14 ) ;
F_42 ( V_2 -> V_5 ) ;
F_46 ( & V_2 -> V_18 ) ;
F_43 ( V_2 -> V_30 , V_33 ) ;
if ( F_11 ( V_10 -> V_21 ) )
F_33 ( V_10 -> V_21 ) ;
F_33 ( V_16 ) ;
F_26 ( V_2 -> V_18 . V_19 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_63 * V_15 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
if ( F_49 ( V_15 ) )
F_50 ( V_2 -> V_30 ) ;
return 0 ;
}
static int F_51 ( struct V_63 * V_15 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
if ( F_49 ( V_15 ) )
F_52 ( V_2 -> V_30 ) ;
return 0 ;
}
