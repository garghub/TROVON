static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 |= V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 -> V_10 ;
int V_13 ;
if ( F_3 ( V_10 , L_1 ) ||
F_3 ( V_10 , L_2 ) ) {
V_13 = F_4 ( V_8 ) ;
if ( V_13 )
return V_13 ;
}
return F_5 ( V_8 , F_1 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 -> V_10 ;
if ( F_3 ( V_10 , L_1 ) ||
F_3 ( V_10 , L_2 ) )
F_7 ( V_8 ) ;
return F_8 ( V_8 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_9 * V_16 = V_15 -> V_2 . V_10 ;
struct V_17 * V_18 = F_10 ( & V_15 -> V_2 ) ;
const struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
struct V_7 * V_8 ;
struct V_23 * V_23 ;
int V_13 ;
int V_24 ;
if ( F_11 () )
return - V_25 ;
V_20 = & V_26 ;
V_24 = F_12 ( V_15 , 0 ) ;
if ( V_24 < 0 )
return - V_25 ;
if ( F_13 ( ! V_15 -> V_2 . V_27 ) )
V_13 = F_14 ( & V_15 -> V_2 ,
F_15 ( 64 ) ) ;
else
V_13 = F_16 ( & V_15 -> V_2 , F_15 ( 64 ) ) ;
if ( V_13 ) {
V_13 = F_16 ( & V_15 -> V_2 , F_15 ( 32 ) ) ;
if ( V_13 )
return V_13 ;
}
V_8 = F_17 ( V_20 , & V_15 -> V_2 , F_18 ( & V_15 -> V_2 ) ) ;
if ( ! V_8 )
return - V_28 ;
V_22 = F_19 ( V_15 , V_29 , 0 ) ;
V_8 -> V_30 = F_20 ( & V_15 -> V_2 , V_22 ) ;
if ( F_21 ( V_8 -> V_30 ) ) {
V_13 = F_22 ( V_8 -> V_30 ) ;
goto V_31;
}
V_8 -> V_32 = V_22 -> V_33 ;
V_8 -> V_34 = F_23 ( V_22 ) ;
V_23 = F_24 ( & V_15 -> V_2 , NULL ) ;
if ( ! F_21 ( V_23 ) ) {
V_13 = F_25 ( V_23 ) ;
if ( V_13 )
goto V_31;
}
if ( F_3 ( V_15 -> V_2 . V_10 ,
L_3 ) ||
F_3 ( V_15 -> V_2 . V_10 ,
L_4 ) ) {
V_13 = F_26 ( V_15 ) ;
if ( V_13 )
goto V_35;
}
F_27 ( V_8 -> V_11 . V_12 ) ;
V_4 = F_28 ( V_8 ) ;
V_4 -> V_23 = V_23 ;
V_4 -> V_36 = V_8 ;
V_4 -> V_37 = F_29 ( V_20 , & V_15 -> V_2 ,
F_18 ( & V_15 -> V_2 ) , V_8 ) ;
if ( ! V_4 -> V_37 ) {
V_13 = - V_28 ;
goto V_35;
}
if ( ( V_16 && F_30 ( V_16 , L_5 ) ) ||
( V_18 && V_18 -> V_38 ) )
V_4 -> V_5 |= V_39 ;
if ( F_31 ( V_4 -> V_40 ) >= 4 )
V_4 -> V_37 -> V_41 = 1 ;
V_8 -> V_42 = F_32 ( & V_15 -> V_2 , L_6 , 0 ) ;
if ( F_21 ( V_8 -> V_42 ) ) {
V_13 = F_22 ( V_8 -> V_42 ) ;
if ( V_13 == - V_43 )
goto V_44;
V_8 -> V_42 = NULL ;
} else {
V_13 = F_33 ( V_8 -> V_42 ) ;
if ( V_13 )
goto V_44;
}
V_13 = F_34 ( V_8 , V_24 , V_45 ) ;
if ( V_13 )
goto V_46;
V_13 = F_34 ( V_4 -> V_37 , V_24 , V_45 ) ;
if ( V_13 )
goto V_47;
return 0 ;
V_47:
F_35 ( V_8 ) ;
V_46:
F_36 ( V_8 -> V_42 ) ;
V_44:
F_37 ( V_4 -> V_37 ) ;
V_35:
if ( ! F_21 ( V_23 ) )
F_38 ( V_23 ) ;
V_31:
F_37 ( V_8 ) ;
return V_13 ;
}
static int F_39 ( struct V_14 * V_2 )
{
struct V_7 * V_8 = F_40 ( V_2 ) ;
struct V_3 * V_4 = F_28 ( V_8 ) ;
struct V_23 * V_23 = V_4 -> V_23 ;
F_35 ( V_4 -> V_37 ) ;
F_36 ( V_8 -> V_42 ) ;
F_35 ( V_8 ) ;
F_37 ( V_4 -> V_37 ) ;
if ( ! F_21 ( V_23 ) )
F_38 ( V_23 ) ;
F_37 ( V_8 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_42 ( V_2 ) ;
struct V_3 * V_4 = F_28 ( V_8 ) ;
return F_43 ( V_4 , F_44 ( V_2 ) ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_42 ( V_2 ) ;
struct V_3 * V_4 = F_28 ( V_8 ) ;
return F_46 ( V_4 , 0 ) ;
}
static int T_1 F_47 ( void )
{
F_48 ( & V_26 , & V_48 ) ;
return F_49 ( & V_49 ) ;
}
static void T_2 F_50 ( void )
{
F_51 ( & V_49 ) ;
}
