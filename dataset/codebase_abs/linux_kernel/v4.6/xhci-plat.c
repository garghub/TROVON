static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_4 -> V_7 |= V_8 ;
if ( F_3 ( V_6 , V_9 ) ||
F_3 ( V_6 , V_10 ) )
V_4 -> V_7 |= V_11 ;
}
static int F_4 ( struct V_5 * V_6 )
{
int V_12 ;
if ( F_3 ( V_6 , V_9 ) ||
F_3 ( V_6 , V_10 ) ) {
V_12 = F_5 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
return F_6 ( V_6 , F_1 ) ;
}
static int F_7 ( struct V_5 * V_6 )
{
if ( F_3 ( V_6 , V_9 ) ||
F_3 ( V_6 , V_10 ) )
F_8 ( V_6 ) ;
return F_9 ( V_6 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_2 . V_17 ;
struct V_18 * V_19 = F_11 ( & V_14 -> V_2 ) ;
const struct V_20 * V_21 ;
const struct V_22 * V_23 ;
struct V_3 * V_4 ;
struct V_24 * V_25 ;
struct V_5 * V_6 ;
struct V_26 * V_26 ;
int V_12 ;
int V_27 ;
if ( F_12 () )
return - V_28 ;
V_23 = & V_29 ;
V_27 = F_13 ( V_14 , 0 ) ;
if ( V_27 < 0 )
return - V_28 ;
if ( F_14 ( ! V_14 -> V_2 . V_30 ) )
V_12 = F_15 ( & V_14 -> V_2 ,
F_16 ( 64 ) ) ;
else
V_12 = F_17 ( & V_14 -> V_2 , F_16 ( 64 ) ) ;
if ( V_12 ) {
V_12 = F_17 ( & V_14 -> V_2 , F_16 ( 32 ) ) ;
if ( V_12 )
return V_12 ;
}
V_6 = F_18 ( V_23 , & V_14 -> V_2 , F_19 ( & V_14 -> V_2 ) ) ;
if ( ! V_6 )
return - V_31 ;
V_25 = F_20 ( V_14 , V_32 , 0 ) ;
V_6 -> V_33 = F_21 ( & V_14 -> V_2 , V_25 ) ;
if ( F_22 ( V_6 -> V_33 ) ) {
V_12 = F_23 ( V_6 -> V_33 ) ;
goto V_34;
}
V_6 -> V_35 = V_25 -> V_36 ;
V_6 -> V_37 = F_24 ( V_25 ) ;
V_26 = F_25 ( & V_14 -> V_2 , NULL ) ;
if ( ! F_22 ( V_26 ) ) {
V_12 = F_26 ( V_26 ) ;
if ( V_12 )
goto V_34;
}
V_4 = F_27 ( V_6 ) ;
V_21 = F_28 ( V_38 , V_16 ) ;
if ( V_21 ) {
const struct V_39 * V_40 = V_21 -> V_41 ;
struct V_39 * V_42 = F_29 ( V_6 ) ;
if ( V_40 )
* V_42 = * V_40 ;
}
if ( F_3 ( V_6 , V_43 ) ) {
V_12 = F_30 ( V_14 ) ;
if ( V_12 )
goto V_44;
}
F_31 ( V_6 -> V_45 . V_46 ) ;
V_4 -> V_26 = V_26 ;
V_4 -> V_47 = V_6 ;
V_4 -> V_48 = F_32 ( V_23 , & V_14 -> V_2 ,
F_19 ( & V_14 -> V_2 ) , V_6 ) ;
if ( ! V_4 -> V_48 ) {
V_12 = - V_31 ;
goto V_44;
}
if ( ( V_16 && F_33 ( V_16 , L_1 ) ) ||
( V_19 && V_19 -> V_49 ) )
V_4 -> V_7 |= V_50 ;
if ( F_34 ( V_4 -> V_51 ) >= 4 )
V_4 -> V_48 -> V_52 = 1 ;
V_6 -> V_53 = F_35 ( & V_14 -> V_2 , L_2 , 0 ) ;
if ( F_22 ( V_6 -> V_53 ) ) {
V_12 = F_23 ( V_6 -> V_53 ) ;
if ( V_12 == - V_54 )
goto V_55;
V_6 -> V_53 = NULL ;
} else {
V_12 = F_36 ( V_6 -> V_53 ) ;
if ( V_12 )
goto V_55;
}
V_12 = F_37 ( V_6 , V_27 , V_56 ) ;
if ( V_12 )
goto V_57;
V_12 = F_37 ( V_4 -> V_48 , V_27 , V_56 ) ;
if ( V_12 )
goto V_58;
return 0 ;
V_58:
F_38 ( V_6 ) ;
V_57:
F_39 ( V_6 -> V_53 ) ;
V_55:
F_40 ( V_4 -> V_48 ) ;
V_44:
if ( ! F_22 ( V_26 ) )
F_41 ( V_26 ) ;
V_34:
F_40 ( V_6 ) ;
return V_12 ;
}
static int F_42 ( struct V_13 * V_2 )
{
struct V_5 * V_6 = F_43 ( V_2 ) ;
struct V_3 * V_4 = F_27 ( V_6 ) ;
struct V_26 * V_26 = V_4 -> V_26 ;
F_38 ( V_4 -> V_48 ) ;
F_39 ( V_6 -> V_53 ) ;
F_38 ( V_6 ) ;
F_40 ( V_4 -> V_48 ) ;
if ( ! F_22 ( V_26 ) )
F_41 ( V_26 ) ;
F_40 ( V_6 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_45 ( V_2 ) ;
struct V_3 * V_4 = F_27 ( V_6 ) ;
return F_46 ( V_4 , F_47 ( V_2 ) ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_45 ( V_2 ) ;
struct V_3 * V_4 = F_27 ( V_6 ) ;
return F_49 ( V_4 , 0 ) ;
}
static int T_1 F_50 ( void )
{
F_51 ( & V_29 , & V_59 ) ;
return F_52 ( & V_60 ) ;
}
static void T_2 F_53 ( void )
{
F_54 ( & V_60 ) ;
}
