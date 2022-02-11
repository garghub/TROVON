static void F_1 ( struct V_1 * V_2 , int V_3 )
{
}
static void F_2 ( struct V_1 * V_2 , int V_4 , unsigned int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_8 ;
if ( V_4 == V_11 )
return;
if ( V_5 & V_12 )
F_3 ( V_4 , V_10 -> V_13 ) ;
else
F_3 ( V_4 , V_10 -> V_14 ) ;
}
static int F_4 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 . V_20 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_21 * V_22 ;
int V_23 = 0 ;
V_10 = F_5 ( sizeof( struct V_9 ) , V_24 ) ;
if ( ! V_10 ) {
F_6 ( & V_16 -> V_19 , L_1 ) ;
return - V_25 ;
}
if ( V_18 -> V_26 )
V_23 = V_18 -> V_26 () ;
if ( V_23 < 0 ) {
F_6 ( & V_16 -> V_19 , L_2 ) ;
goto V_27;
}
V_22 = F_7 ( V_16 , V_28 , L_3 ) ;
if ( ! V_22 ) {
V_23 = - V_29 ;
goto V_30;
}
V_10 -> V_14 = F_8 ( V_22 -> V_31 , F_9 ( V_22 ) ) ;
V_22 = F_7 ( V_16 , V_28 , L_4 ) ;
if ( ! V_22 ) {
V_23 = - V_29 ;
goto V_30;
}
V_10 -> V_32 = F_8 ( V_22 -> V_31 , F_9 ( V_22 ) ) ;
V_22 = F_7 ( V_16 , V_28 , L_5 ) ;
if ( ! V_22 ) {
V_23 = - V_29 ;
goto V_30;
}
V_10 -> V_13 = F_8 ( V_22 -> V_31 , F_9 ( V_22 ) ) ;
if ( ! V_10 -> V_14 || ! V_10 -> V_32 || ! V_10 -> V_13 ) {
V_23 = - V_25 ;
goto V_30;
}
V_2 = & V_10 -> V_2 ;
V_7 = & V_10 -> V_7 ;
V_2 -> V_8 = V_7 ;
V_7 -> V_8 = V_10 ;
V_10 -> V_2 . V_33 = V_34 ;
V_7 -> V_35 = V_10 -> V_32 ;
V_7 -> V_36 = V_10 -> V_32 ;
V_7 -> V_37 = F_2 ;
V_7 -> V_38 . V_3 = V_39 ;
V_7 -> V_38 . V_40 = & V_41 ;
V_7 -> V_38 . V_42 = F_1 ;
V_7 -> V_38 . V_43 = 512 ;
V_7 -> V_38 . V_44 = 3 ;
V_7 -> V_45 = V_18 -> V_45 ;
if ( F_10 ( & V_10 -> V_2 , 1 ) ) {
V_23 = - V_46 ;
goto V_30;
}
F_11 ( & V_10 -> V_2 , V_18 -> V_47 , V_18 -> V_48 ) ;
F_12 ( V_16 , V_10 ) ;
return 0 ;
V_30:
if ( V_10 -> V_13 )
F_13 ( V_10 -> V_13 ) ;
if ( V_10 -> V_32 )
F_13 ( V_10 -> V_32 ) ;
if ( V_10 -> V_14 )
F_13 ( V_10 -> V_14 ) ;
V_27:
F_14 ( V_10 ) ;
return V_23 ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = F_16 ( V_16 ) ;
struct V_17 * V_18 = V_16 -> V_19 . V_20 ;
if ( V_18 -> exit )
V_18 -> exit () ;
if ( V_10 ) {
F_17 ( & V_10 -> V_2 ) ;
F_13 ( V_10 -> V_13 ) ;
F_13 ( V_10 -> V_32 ) ;
F_13 ( V_10 -> V_14 ) ;
F_14 ( V_10 ) ;
}
return 0 ;
}
static int F_18 ( struct V_49 * V_19 )
{
struct V_9 * V_10 = F_19 ( V_19 ) ;
int V_23 = 0 ;
if ( V_10 )
V_23 = V_10 -> V_2 . V_50 ( & V_10 -> V_2 ) ;
return V_23 ;
}
static int F_20 ( struct V_49 * V_19 )
{
struct V_9 * V_10 = F_19 ( V_19 ) ;
if ( V_10 )
V_10 -> V_2 . V_51 ( & V_10 -> V_2 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
F_22 ( L_6 ) ;
return F_23 ( & V_52 ) ;
}
static void T_2 F_24 ( void )
{
F_25 ( & V_52 ) ;
}
