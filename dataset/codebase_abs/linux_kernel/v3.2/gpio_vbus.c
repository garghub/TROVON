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
int V_16 ;
if ( ! V_2 -> V_17 . V_18 )
return;
V_16 = V_9 -> V_19 ;
if ( F_5 ( V_9 ) ) {
V_2 -> V_17 . V_20 = V_21 ;
F_9 ( V_2 -> V_17 . V_18 ) ;
F_1 ( V_2 , 100 ) ;
if ( F_10 ( V_16 ) )
F_11 ( V_16 , ! V_9 -> V_22 ) ;
} else {
if ( F_10 ( V_16 ) )
F_11 ( V_16 , V_9 -> V_22 ) ;
F_1 ( V_2 , 0 ) ;
F_12 ( V_2 -> V_17 . V_18 ) ;
V_2 -> V_17 . V_20 = V_23 ;
}
}
static T_1 F_13 ( int V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_8 * V_9 = V_27 -> V_14 . V_15 ;
struct V_1 * V_2 = F_14 ( V_27 ) ;
F_15 ( & V_27 -> V_14 , L_1 ,
F_5 ( V_9 ) ? L_2 : L_3 ,
V_2 -> V_17 . V_18 ? V_2 -> V_17 . V_18 -> V_28 : L_4 ) ;
if ( V_2 -> V_17 . V_18 )
F_16 ( & V_2 -> V_13 ) ;
return V_29 ;
}
static int F_17 ( struct V_30 * V_17 ,
struct V_31 * V_18 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_26 * V_27 ;
int V_16 , V_24 ;
V_2 = F_8 ( V_17 , struct V_1 , V_17 ) ;
V_27 = F_18 ( V_2 -> V_14 ) ;
V_9 = V_2 -> V_14 -> V_15 ;
V_24 = F_19 ( V_9 -> V_2 ) ;
V_16 = V_9 -> V_19 ;
if ( ! V_18 ) {
F_15 ( & V_27 -> V_14 , L_5 ,
V_17 -> V_18 -> V_28 ) ;
if ( F_10 ( V_16 ) )
F_11 ( V_16 , V_9 -> V_22 ) ;
F_1 ( V_2 , 0 ) ;
F_12 ( V_17 -> V_18 ) ;
V_17 -> V_20 = V_32 ;
V_17 -> V_18 = NULL ;
return 0 ;
}
V_17 -> V_18 = V_18 ;
F_15 ( & V_27 -> V_14 , L_6 , V_18 -> V_28 ) ;
F_13 ( V_24 , V_27 ) ;
return 0 ;
}
static int F_20 ( struct V_30 * V_17 , unsigned V_3 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_17 , struct V_1 , V_17 ) ;
if ( V_17 -> V_20 == V_21 )
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_17 , int V_33 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_17 , struct V_1 , V_17 ) ;
return F_20 ( V_17 , V_33 ? 0 : V_2 -> V_3 ) ;
}
static int T_2 F_22 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = V_27 -> V_14 . V_15 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
int V_36 , V_16 , V_24 ;
if ( ! V_9 || ! F_10 ( V_9 -> V_2 ) )
return - V_37 ;
V_16 = V_9 -> V_2 ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
F_24 ( V_27 , V_2 ) ;
V_2 -> V_14 = & V_27 -> V_14 ;
V_2 -> V_17 . V_40 = L_7 ;
V_2 -> V_17 . V_20 = V_32 ;
V_2 -> V_17 . V_41 = F_17 ;
V_2 -> V_17 . V_42 = F_20 ;
V_2 -> V_17 . V_43 = F_21 ;
V_36 = F_25 ( V_16 , L_8 ) ;
if ( V_36 ) {
F_26 ( & V_27 -> V_14 , L_9 ,
V_16 , V_36 ) ;
goto V_44;
}
F_27 ( V_16 ) ;
V_35 = F_28 ( V_27 , V_45 , 0 ) ;
if ( V_35 ) {
V_24 = V_35 -> V_46 ;
V_35 -> V_47 &= V_48 ;
V_35 -> V_47 |= V_49 | V_50 ;
} else
V_24 = F_19 ( V_16 ) ;
V_16 = V_9 -> V_19 ;
if ( F_10 ( V_16 ) ) {
V_36 = F_25 ( V_16 , L_10 ) ;
if ( V_36 ) {
F_26 ( & V_27 -> V_14 ,
L_11 ,
V_16 , V_36 ) ;
F_29 ( V_9 -> V_2 ) ;
goto V_44;
}
F_30 ( V_16 , V_9 -> V_22 ) ;
}
V_36 = F_31 ( V_24 , F_13 , V_51 ,
L_8 , V_27 ) ;
if ( V_36 ) {
F_26 ( & V_27 -> V_14 , L_12 ,
V_24 , V_36 ) ;
goto V_52;
}
F_32 ( & V_2 -> V_13 , F_7 ) ;
V_2 -> V_5 = F_33 ( & V_27 -> V_14 , L_13 ) ;
if ( F_34 ( V_2 -> V_5 ) ) {
F_15 ( & V_27 -> V_14 , L_14 ,
F_35 ( V_2 -> V_5 ) ) ;
V_2 -> V_5 = NULL ;
}
V_36 = F_36 ( & V_2 -> V_17 ) ;
if ( V_36 ) {
F_26 ( & V_27 -> V_14 , L_15 ,
V_36 ) ;
goto V_53;
}
return 0 ;
V_53:
F_37 ( V_24 , & V_27 -> V_14 ) ;
V_52:
if ( F_10 ( V_9 -> V_19 ) )
F_29 ( V_9 -> V_19 ) ;
F_29 ( V_9 -> V_2 ) ;
V_44:
F_24 ( V_27 , NULL ) ;
F_38 ( V_2 ) ;
return V_36 ;
}
static int T_3 F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_14 ( V_27 ) ;
struct V_8 * V_9 = V_27 -> V_14 . V_15 ;
int V_16 = V_9 -> V_2 ;
F_40 ( V_2 -> V_5 ) ;
F_36 ( NULL ) ;
F_37 ( F_19 ( V_16 ) , & V_27 -> V_14 ) ;
if ( F_10 ( V_9 -> V_19 ) )
F_29 ( V_9 -> V_19 ) ;
F_29 ( V_16 ) ;
F_24 ( V_27 , NULL ) ;
F_38 ( V_2 ) ;
return 0 ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_54 , F_22 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_54 ) ;
}
