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
struct V_9 * V_10 = F_7 ( & V_2 -> V_4 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 ;
int V_5 ;
if ( ! V_2 -> V_4 . V_22 )
V_2 -> V_4 . V_22 = & V_2 -> V_4 . V_23 ;
if ( ! V_2 -> V_4 . V_23 )
V_2 -> V_4 . V_23 = F_8 ( 32 ) ;
F_1 ( V_2 ) ;
V_14 = F_9 ( & V_24 ,
& V_2 -> V_4 , F_10 ( & V_2 -> V_4 ) ) ;
if ( ! V_14 ) {
F_5 ( & V_2 -> V_4 , L_4 ) ;
return - V_25 ;
}
V_12 = F_11 ( V_14 ) ;
if ( F_12 ( V_2 -> V_4 . V_7 ,
L_5 ) ) {
V_12 -> V_10 = & V_26 ;
goto V_27;
}
V_20 = F_13 ( & V_2 -> V_4 , V_28 ) ;
if ( F_14 ( V_20 ) ) {
if ( ! V_10 ) {
F_15 ( V_14 ) ;
F_16 ( & V_2 -> V_4 , L_6 ) ;
return - V_29 ;
} else {
V_12 -> V_10 = V_10 ;
}
} else {
V_12 -> V_20 = V_20 ;
V_12 -> V_30 = V_20 -> V_30 ;
}
V_27:
V_12 -> V_31 = F_17 ( & V_2 -> V_4 , L_7 ) ;
if ( F_14 ( V_12 -> V_31 ) ) {
F_5 ( & V_2 -> V_4 , L_8 ) ;
V_5 = F_18 ( V_12 -> V_31 ) ;
goto V_32;
}
V_5 = F_19 ( V_12 -> V_31 ) ;
if ( V_5 )
goto V_32;
V_18 = F_20 ( V_2 , V_33 , 0 ) ;
if ( ! V_18 ) {
F_5 ( & V_2 -> V_4 , L_9 ) ;
V_5 = - V_34 ;
goto V_35;
}
V_14 -> V_36 = V_18 -> V_37 ;
V_14 -> V_38 = F_21 ( V_18 ) ;
V_14 -> V_39 = F_22 ( & V_2 -> V_4 , V_18 -> V_37 , V_14 -> V_38 ) ;
if ( ! V_14 -> V_39 ) {
F_5 ( & V_2 -> V_4 , L_10 ) ;
V_5 = - V_25 ;
goto V_35;
}
V_21 = F_23 ( V_2 , 0 ) ;
if ( ! V_21 ) {
F_5 ( & V_2 -> V_4 , L_11 ) ;
V_5 = - V_40 ;
goto V_35;
}
if ( V_12 -> V_30 )
V_12 -> V_30 -> V_41 ( V_12 -> V_30 , & V_14 -> V_42 ) ;
if ( V_12 -> V_20 )
F_24 ( V_12 -> V_20 ) ;
else if ( V_12 -> V_10 -> V_43 )
V_12 -> V_10 -> V_43 ( V_2 , V_44 ) ;
V_16 = F_25 ( V_14 ) ;
V_16 -> V_45 = V_14 -> V_39 ;
F_26 ( V_46 , F_27 ( V_14 -> V_39 ) ) ;
V_5 = F_28 ( V_14 , V_21 , V_47 ) ;
if ( V_5 ) {
F_5 ( & V_2 -> V_4 , L_12 ) ;
goto V_48;
}
F_29 ( V_2 , V_14 ) ;
return 0 ;
V_48:
if ( V_12 -> V_20 )
F_30 ( V_12 -> V_20 ) ;
else if ( V_12 -> V_10 -> V_49 )
V_12 -> V_10 -> V_49 ( V_2 , V_44 ) ;
V_35:
F_31 ( V_12 -> V_31 ) ;
V_32:
F_15 ( V_14 ) ;
return V_5 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_33 ( V_2 ) ;
struct V_11 * V_12 = F_11 ( V_14 ) ;
F_34 ( V_14 ) ;
if ( V_12 -> V_30 )
V_12 -> V_30 -> V_41 ( V_12 -> V_30 , & V_14 -> V_42 ) ;
if ( V_12 -> V_20 )
F_30 ( V_12 -> V_20 ) ;
else if ( V_12 -> V_10 -> V_49 )
V_12 -> V_10 -> V_49 ( V_2 , V_44 ) ;
F_31 ( V_12 -> V_31 ) ;
F_15 ( V_14 ) ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_36 ( V_4 ) ;
struct V_11 * V_12 = F_11 ( V_14 ) ;
struct V_1 * V_2 = F_37 ( V_4 ) ;
bool V_50 = F_38 ( V_4 ) ;
int V_51 ;
V_51 = F_39 ( V_14 , V_50 ) ;
if ( V_12 -> V_30 )
V_12 -> V_30 -> V_41 ( V_12 -> V_30 , & V_14 -> V_42 ) ;
if ( V_12 -> V_20 )
F_30 ( V_12 -> V_20 ) ;
else if ( V_12 -> V_10 -> V_49 )
V_12 -> V_10 -> V_49 ( V_2 , V_44 ) ;
F_31 ( V_12 -> V_31 ) ;
return V_51 ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_36 ( V_4 ) ;
struct V_11 * V_12 = F_11 ( V_14 ) ;
struct V_1 * V_2 = F_37 ( V_4 ) ;
F_19 ( V_12 -> V_31 ) ;
if ( V_12 -> V_30 )
V_12 -> V_30 -> V_41 ( V_12 -> V_30 , & V_14 -> V_42 ) ;
if ( V_12 -> V_20 )
F_24 ( V_12 -> V_20 ) ;
else if ( V_12 -> V_10 -> V_43 )
V_12 -> V_10 -> V_43 ( V_2 , V_44 ) ;
F_26 ( V_46 , F_27 ( V_14 -> V_39 ) ) ;
F_41 ( V_14 , false ) ;
return 0 ;
}
static int T_1 F_42 ( void )
{
if ( F_43 () )
return - V_40 ;
F_44 ( L_13 V_52 L_14 , V_53 ) ;
F_45 ( & V_24 , & V_54 ) ;
return F_46 ( & V_55 ) ;
}
static void T_2 F_47 ( void )
{
F_48 ( & V_55 ) ;
}
