static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
V_4 -> V_5 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_6 )
return 0 ;
return V_4 -> V_6 ( V_2 ) ;
}
static void F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
V_10 -> V_11 |= V_12 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_3 ( V_2 ) ;
if ( V_13 )
return V_13 ;
return F_6 ( V_2 , F_4 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return F_8 ( V_2 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
const struct V_16 * V_17 ;
const struct V_18 * V_19 ;
struct V_9 * V_10 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_22 ;
int V_13 ;
int V_23 ;
if ( F_10 () )
return - V_24 ;
V_19 = & V_25 ;
V_23 = F_11 ( V_15 , 0 ) ;
if ( V_23 < 0 )
return - V_24 ;
if ( ! V_15 -> V_8 . V_26 )
V_13 = F_12 ( & V_15 -> V_8 ,
F_13 ( 64 ) ) ;
else
V_13 = F_14 ( & V_15 -> V_8 , F_13 ( 64 ) ) ;
if ( V_13 ) {
V_13 = F_14 ( & V_15 -> V_8 , F_13 ( 32 ) ) ;
if ( V_13 )
return V_13 ;
}
V_2 = F_15 ( V_19 , & V_15 -> V_8 , F_16 ( & V_15 -> V_8 ) ) ;
if ( ! V_2 )
return - V_27 ;
V_21 = F_17 ( V_15 , V_28 , 0 ) ;
V_2 -> V_29 = F_18 ( & V_15 -> V_8 , V_21 ) ;
if ( F_19 ( V_2 -> V_29 ) ) {
V_13 = F_20 ( V_2 -> V_29 ) ;
goto V_30;
}
V_2 -> V_31 = V_21 -> V_32 ;
V_2 -> V_33 = F_21 ( V_21 ) ;
V_22 = F_22 ( & V_15 -> V_8 , NULL ) ;
if ( ! F_19 ( V_22 ) ) {
V_13 = F_23 ( V_22 ) ;
if ( V_13 )
goto V_30;
} else if ( F_20 ( V_22 ) == - V_34 ) {
V_13 = - V_34 ;
goto V_30;
}
V_10 = F_24 ( V_2 ) ;
V_17 = F_25 ( V_35 , V_15 -> V_8 . V_36 ) ;
if ( V_17 ) {
const struct V_3 * V_37 = V_17 -> V_38 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_37 )
* V_4 = * V_37 ;
}
F_26 ( V_2 -> V_39 . V_40 ) ;
V_10 -> V_22 = V_22 ;
V_10 -> V_41 = V_2 ;
V_10 -> V_42 = F_27 ( V_19 , & V_15 -> V_8 ,
F_16 ( & V_15 -> V_8 ) , V_2 ) ;
if ( ! V_10 -> V_42 ) {
V_13 = - V_27 ;
goto V_43;
}
if ( F_28 ( & V_15 -> V_8 , L_1 ) )
V_10 -> V_11 |= V_44 ;
if ( F_28 ( & V_15 -> V_8 , L_2 ) )
V_10 -> V_11 |= V_45 ;
V_2 -> V_46 = F_29 ( & V_15 -> V_8 , L_3 , 0 ) ;
if ( F_19 ( V_2 -> V_46 ) ) {
V_13 = F_20 ( V_2 -> V_46 ) ;
if ( V_13 == - V_34 )
goto V_47;
V_2 -> V_46 = NULL ;
} else {
V_13 = F_30 ( V_2 -> V_46 ) ;
if ( V_13 )
goto V_47;
}
V_13 = F_31 ( V_2 , V_23 , V_48 ) ;
if ( V_13 )
goto V_49;
if ( F_32 ( V_10 -> V_50 ) >= 4 )
V_10 -> V_42 -> V_51 = 1 ;
V_13 = F_31 ( V_10 -> V_42 , V_23 , V_48 ) ;
if ( V_13 )
goto V_52;
return 0 ;
V_52:
F_33 ( V_2 ) ;
V_49:
F_34 ( V_2 -> V_46 ) ;
V_47:
F_35 ( V_10 -> V_42 ) ;
V_43:
if ( ! F_19 ( V_22 ) )
F_36 ( V_22 ) ;
V_30:
F_35 ( V_2 ) ;
return V_13 ;
}
static int F_37 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = F_38 ( V_8 ) ;
struct V_9 * V_10 = F_24 ( V_2 ) ;
struct V_22 * V_22 = V_10 -> V_22 ;
V_10 -> V_53 |= V_54 ;
F_33 ( V_10 -> V_42 ) ;
F_34 ( V_2 -> V_46 ) ;
F_33 ( V_2 ) ;
F_35 ( V_10 -> V_42 ) ;
if ( ! F_19 ( V_22 ) )
F_36 ( V_22 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_40 ( V_8 ) ;
struct V_9 * V_10 = F_24 ( V_2 ) ;
return F_41 ( V_10 , F_42 ( V_8 ) ) ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_40 ( V_8 ) ;
struct V_9 * V_10 = F_24 ( V_2 ) ;
return F_44 ( V_10 , 0 ) ;
}
static int T_1 F_45 ( void )
{
F_46 ( & V_25 , & V_55 ) ;
return F_47 ( & V_56 ) ;
}
static void T_2 F_48 ( void )
{
F_49 ( & V_56 ) ;
}
