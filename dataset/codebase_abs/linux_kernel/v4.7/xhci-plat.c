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
struct V_16 * V_17 = V_15 -> V_8 . V_18 ;
struct V_19 * V_20 = F_10 ( & V_15 -> V_8 ) ;
const struct V_21 * V_22 ;
const struct V_23 * V_24 ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
struct V_1 * V_2 ;
struct V_27 * V_27 ;
int V_13 ;
int V_28 ;
if ( F_11 () )
return - V_29 ;
V_24 = & V_30 ;
V_28 = F_12 ( V_15 , 0 ) ;
if ( V_28 < 0 )
return - V_29 ;
if ( F_13 ( ! V_15 -> V_8 . V_31 ) )
V_13 = F_14 ( & V_15 -> V_8 ,
F_15 ( 64 ) ) ;
else
V_13 = F_16 ( & V_15 -> V_8 , F_15 ( 64 ) ) ;
if ( V_13 ) {
V_13 = F_16 ( & V_15 -> V_8 , F_15 ( 32 ) ) ;
if ( V_13 )
return V_13 ;
}
V_2 = F_17 ( V_24 , & V_15 -> V_8 , F_18 ( & V_15 -> V_8 ) ) ;
if ( ! V_2 )
return - V_32 ;
V_26 = F_19 ( V_15 , V_33 , 0 ) ;
V_2 -> V_34 = F_20 ( & V_15 -> V_8 , V_26 ) ;
if ( F_21 ( V_2 -> V_34 ) ) {
V_13 = F_22 ( V_2 -> V_34 ) ;
goto V_35;
}
V_2 -> V_36 = V_26 -> V_37 ;
V_2 -> V_38 = F_23 ( V_26 ) ;
V_27 = F_24 ( & V_15 -> V_8 , NULL ) ;
if ( ! F_21 ( V_27 ) ) {
V_13 = F_25 ( V_27 ) ;
if ( V_13 )
goto V_35;
} else if ( F_22 ( V_27 ) == - V_39 ) {
V_13 = - V_39 ;
goto V_35;
}
V_10 = F_26 ( V_2 ) ;
V_22 = F_27 ( V_40 , V_17 ) ;
if ( V_22 ) {
const struct V_3 * V_41 = V_22 -> V_42 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_41 )
* V_4 = * V_41 ;
}
F_28 ( V_2 -> V_43 . V_44 ) ;
V_10 -> V_27 = V_27 ;
V_10 -> V_45 = V_2 ;
V_10 -> V_46 = F_29 ( V_24 , & V_15 -> V_8 ,
F_18 ( & V_15 -> V_8 ) , V_2 ) ;
if ( ! V_10 -> V_46 ) {
V_13 = - V_32 ;
goto V_47;
}
if ( ( V_17 && F_30 ( V_17 , L_1 ) ) ||
( V_20 && V_20 -> V_48 ) )
V_10 -> V_11 |= V_49 ;
if ( F_31 ( V_10 -> V_50 ) >= 4 )
V_10 -> V_46 -> V_51 = 1 ;
V_2 -> V_52 = F_32 ( & V_15 -> V_8 , L_2 , 0 ) ;
if ( F_21 ( V_2 -> V_52 ) ) {
V_13 = F_22 ( V_2 -> V_52 ) ;
if ( V_13 == - V_39 )
goto V_53;
V_2 -> V_52 = NULL ;
} else {
V_13 = F_33 ( V_2 -> V_52 ) ;
if ( V_13 )
goto V_53;
}
V_13 = F_34 ( V_2 , V_28 , V_54 ) ;
if ( V_13 )
goto V_55;
V_13 = F_34 ( V_10 -> V_46 , V_28 , V_54 ) ;
if ( V_13 )
goto V_56;
return 0 ;
V_56:
F_35 ( V_2 ) ;
V_55:
F_36 ( V_2 -> V_52 ) ;
V_53:
F_37 ( V_10 -> V_46 ) ;
V_47:
if ( ! F_21 ( V_27 ) )
F_38 ( V_27 ) ;
V_35:
F_37 ( V_2 ) ;
return V_13 ;
}
static int F_39 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = F_40 ( V_8 ) ;
struct V_9 * V_10 = F_26 ( V_2 ) ;
struct V_27 * V_27 = V_10 -> V_27 ;
F_35 ( V_10 -> V_46 ) ;
F_36 ( V_2 -> V_52 ) ;
F_35 ( V_2 ) ;
F_37 ( V_10 -> V_46 ) ;
if ( ! F_21 ( V_27 ) )
F_38 ( V_27 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_42 ( V_8 ) ;
struct V_9 * V_10 = F_26 ( V_2 ) ;
return F_43 ( V_10 , F_44 ( V_8 ) ) ;
}
static int F_45 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_42 ( V_8 ) ;
struct V_9 * V_10 = F_26 ( V_2 ) ;
return F_46 ( V_10 , 0 ) ;
}
static int T_1 F_47 ( void )
{
F_48 ( & V_30 , & V_57 ) ;
return F_49 ( & V_58 ) ;
}
static void T_2 F_50 ( void )
{
F_51 ( & V_58 ) ;
}
