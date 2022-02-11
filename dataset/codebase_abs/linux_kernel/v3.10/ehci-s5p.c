static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 ;
int V_6 ;
if ( ! V_4 -> V_7 )
return;
V_6 = F_2 ( V_4 -> V_7 , L_1 , 0 ) ;
if ( ! F_3 ( V_6 ) )
return;
V_5 = F_4 ( V_4 , V_6 , V_8 ,
L_2 ) ;
if ( V_5 )
F_5 ( V_4 , L_3 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_4 . V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
int V_5 ;
if ( ! V_2 -> V_4 . V_23 )
V_2 -> V_4 . V_23 = & V_2 -> V_4 . V_24 ;
if ( ! V_2 -> V_4 . V_24 )
V_2 -> V_4 . V_24 = F_7 ( 32 ) ;
F_1 ( V_2 ) ;
V_15 = F_8 ( & V_25 ,
& V_2 -> V_4 , F_9 ( & V_2 -> V_4 ) ) ;
if ( ! V_15 ) {
F_5 ( & V_2 -> V_4 , L_4 ) ;
return - V_26 ;
}
V_13 = F_10 ( V_15 ) ;
V_21 = F_11 ( & V_2 -> V_4 , V_27 ) ;
if ( F_12 ( V_21 ) ) {
if ( ! V_10 ) {
F_13 ( V_15 ) ;
F_14 ( & V_2 -> V_4 , L_5 ) ;
return - V_28 ;
} else {
V_13 -> V_10 = V_10 ;
}
} else {
V_13 -> V_21 = V_21 ;
V_13 -> V_29 = V_21 -> V_29 ;
}
V_13 -> V_30 = F_15 ( & V_2 -> V_4 , L_6 ) ;
if ( F_12 ( V_13 -> V_30 ) ) {
F_5 ( & V_2 -> V_4 , L_7 ) ;
V_5 = F_16 ( V_13 -> V_30 ) ;
goto V_31;
}
V_5 = F_17 ( V_13 -> V_30 ) ;
if ( V_5 )
goto V_31;
V_19 = F_18 ( V_2 , V_32 , 0 ) ;
if ( ! V_19 ) {
F_5 ( & V_2 -> V_4 , L_8 ) ;
V_5 = - V_33 ;
goto V_34;
}
V_15 -> V_35 = V_19 -> V_36 ;
V_15 -> V_37 = F_19 ( V_19 ) ;
V_15 -> V_38 = F_20 ( & V_2 -> V_4 , V_19 -> V_36 , V_15 -> V_37 ) ;
if ( ! V_15 -> V_38 ) {
F_5 ( & V_2 -> V_4 , L_9 ) ;
V_5 = - V_26 ;
goto V_34;
}
V_22 = F_21 ( V_2 , 0 ) ;
if ( ! V_22 ) {
F_5 ( & V_2 -> V_4 , L_10 ) ;
V_5 = - V_39 ;
goto V_34;
}
if ( V_13 -> V_29 )
V_13 -> V_29 -> V_40 ( V_13 -> V_29 , & V_15 -> V_41 ) ;
if ( V_13 -> V_21 )
F_22 ( V_13 -> V_21 ) ;
else if ( V_13 -> V_10 -> V_42 )
V_13 -> V_10 -> V_42 ( V_2 , V_43 ) ;
V_17 = F_23 ( V_15 ) ;
V_17 -> V_44 = V_15 -> V_38 ;
F_24 ( V_45 , F_25 ( V_15 -> V_38 ) ) ;
V_5 = F_26 ( V_15 , V_22 , V_46 ) ;
if ( V_5 ) {
F_5 ( & V_2 -> V_4 , L_11 ) ;
goto V_47;
}
F_27 ( V_2 , V_15 ) ;
return 0 ;
V_47:
if ( V_13 -> V_21 )
F_28 ( V_13 -> V_21 ) ;
else if ( V_13 -> V_10 -> V_48 )
V_13 -> V_10 -> V_48 ( V_2 , V_43 ) ;
V_34:
F_29 ( V_13 -> V_30 ) ;
V_31:
F_13 ( V_15 ) ;
return V_5 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_31 ( V_2 ) ;
struct V_12 * V_13 = F_10 ( V_15 ) ;
F_32 ( V_15 ) ;
if ( V_13 -> V_29 )
V_13 -> V_29 -> V_40 ( V_13 -> V_29 , & V_15 -> V_41 ) ;
if ( V_13 -> V_21 )
F_28 ( V_13 -> V_21 ) ;
else if ( V_13 -> V_10 -> V_48 )
V_13 -> V_10 -> V_48 ( V_2 , V_43 ) ;
F_29 ( V_13 -> V_30 ) ;
F_13 ( V_15 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_31 ( V_2 ) ;
if ( V_15 -> V_49 -> V_50 )
V_15 -> V_49 -> V_50 ( V_15 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_35 ( V_4 ) ;
struct V_12 * V_13 = F_10 ( V_15 ) ;
struct V_1 * V_2 = F_36 ( V_4 ) ;
bool V_51 = F_37 ( V_4 ) ;
int V_52 ;
V_52 = F_38 ( V_15 , V_51 ) ;
if ( V_13 -> V_29 )
V_13 -> V_29 -> V_40 ( V_13 -> V_29 , & V_15 -> V_41 ) ;
if ( V_13 -> V_21 )
F_28 ( V_13 -> V_21 ) ;
else if ( V_13 -> V_10 -> V_48 )
V_13 -> V_10 -> V_48 ( V_2 , V_43 ) ;
F_29 ( V_13 -> V_30 ) ;
return V_52 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = F_35 ( V_4 ) ;
struct V_12 * V_13 = F_10 ( V_15 ) ;
struct V_1 * V_2 = F_36 ( V_4 ) ;
F_17 ( V_13 -> V_30 ) ;
if ( V_13 -> V_29 )
V_13 -> V_29 -> V_40 ( V_13 -> V_29 , & V_15 -> V_41 ) ;
if ( V_13 -> V_21 )
F_22 ( V_13 -> V_21 ) ;
else if ( V_13 -> V_10 -> V_42 )
V_13 -> V_10 -> V_42 ( V_2 , V_43 ) ;
F_24 ( V_45 , F_25 ( V_15 -> V_38 ) ) ;
F_40 ( V_15 , false ) ;
return 0 ;
}
static int T_1 F_41 ( void )
{
if ( F_42 () )
return - V_39 ;
F_43 ( L_12 V_53 L_13 , V_54 ) ;
F_44 ( & V_25 , & V_55 ) ;
return F_45 ( & V_56 ) ;
}
static void T_2 F_46 ( void )
{
F_47 ( & V_56 ) ;
}
