static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = V_4 -> V_9 . V_10 ;
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_13 ;
V_2 -> V_14 = V_8 -> V_14 ;
V_12 -> V_15 = V_8 -> V_15 ;
V_12 -> V_16 = V_8 -> V_16 ;
V_12 -> V_17 = V_8 -> V_17 ;
if ( V_8 -> V_18 ) {
V_13 = V_8 -> V_18 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_12 -> V_19 = V_2 -> V_20 + V_8 -> V_21 ;
V_13 = F_4 ( V_2 ) ;
if ( V_13 )
return V_13 ;
if ( V_8 -> V_22 )
V_12 -> V_23 = 0 ;
return 0 ;
}
static int F_5 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 ;
struct V_7 * V_8 ;
int V_26 ;
int V_27 = - V_28 ;
if ( F_6 () )
return - V_29 ;
if ( ! V_9 -> V_9 . V_10 )
V_9 -> V_9 . V_10 = & V_30 ;
if ( ! V_9 -> V_9 . V_31 )
V_9 -> V_9 . V_31 = & V_9 -> V_9 . V_32 ;
if ( ! V_9 -> V_9 . V_32 )
V_9 -> V_9 . V_32 = F_7 ( 32 ) ;
V_8 = V_9 -> V_9 . V_10 ;
V_26 = F_8 ( V_9 , 0 ) ;
if ( V_26 < 0 ) {
F_9 ( & V_9 -> V_9 , L_1 ) ;
return V_26 ;
}
V_25 = F_10 ( V_9 , V_33 , 0 ) ;
if ( ! V_25 ) {
F_9 ( & V_9 -> V_9 , L_2 ) ;
return - V_34 ;
}
if ( V_8 -> V_35 ) {
V_27 = V_8 -> V_35 ( V_9 ) ;
if ( V_27 < 0 )
return V_27 ;
}
V_2 = F_11 ( & V_36 , & V_9 -> V_9 ,
F_12 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_27 = - V_28 ;
goto V_37;
}
V_2 -> V_38 = V_25 -> V_39 ;
V_2 -> V_40 = F_13 ( V_25 ) ;
V_2 -> V_20 = F_14 ( & V_9 -> V_9 , V_25 ) ;
if ( F_15 ( V_2 -> V_20 ) ) {
V_27 = F_16 ( V_2 -> V_20 ) ;
goto V_41;
}
V_27 = F_17 ( V_2 , V_26 , V_42 ) ;
if ( V_27 )
goto V_41;
F_18 ( V_9 , V_2 ) ;
return V_27 ;
V_41:
F_19 ( V_2 ) ;
V_37:
if ( V_8 -> V_43 )
V_8 -> V_43 ( V_9 ) ;
return V_27 ;
}
static int F_20 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_21 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
if ( V_8 -> V_43 )
V_8 -> V_43 ( V_9 ) ;
if ( V_8 == & V_30 )
V_9 -> V_9 . V_10 = NULL ;
return 0 ;
}
static int F_23 ( struct V_44 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_25 ( V_9 , struct V_3 , V_9 ) ;
bool V_45 = F_26 ( V_9 ) ;
int V_46 ;
V_46 = F_27 ( V_2 , V_45 ) ;
if ( V_8 -> V_47 )
V_8 -> V_47 ( V_4 ) ;
return V_46 ;
}
static int F_28 ( struct V_44 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_25 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_35 ) {
int V_27 = V_8 -> V_35 ( V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
}
F_29 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
if ( F_6 () )
return - V_29 ;
F_31 ( L_3 V_48 L_4 , V_49 ) ;
F_32 ( & V_36 , & V_50 ) ;
return F_33 ( & V_51 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_51 ) ;
}
