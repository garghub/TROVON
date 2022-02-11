static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
int V_12 ;
V_2 -> V_13 = V_8 -> V_13 ;
V_11 -> V_14 = V_8 -> V_14 ;
V_11 -> V_15 = V_8 -> V_15 ;
V_11 -> V_16 = V_8 -> V_16 ;
if ( V_8 -> V_17 ) {
V_12 = V_8 -> V_17 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
}
V_11 -> V_18 = V_2 -> V_19 + V_8 -> V_20 ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( V_8 -> V_21 )
V_11 -> V_22 = 0 ;
return 0 ;
}
static int F_6 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_7 * V_8 ;
int V_25 ;
int V_26 = - V_27 ;
if ( F_7 () )
return - V_28 ;
if ( ! F_3 ( & V_9 -> V_9 ) )
V_9 -> V_9 . V_29 = & V_30 ;
if ( ! V_9 -> V_9 . V_31 )
V_9 -> V_9 . V_31 = & V_9 -> V_9 . V_32 ;
if ( ! V_9 -> V_9 . V_32 )
V_9 -> V_9 . V_32 = F_8 ( 32 ) ;
V_8 = F_3 ( & V_9 -> V_9 ) ;
V_25 = F_9 ( V_9 , 0 ) ;
if ( V_25 < 0 ) {
F_10 ( & V_9 -> V_9 , L_1 ) ;
return V_25 ;
}
V_24 = F_11 ( V_9 , V_33 , 0 ) ;
if ( ! V_24 ) {
F_10 ( & V_9 -> V_9 , L_2 ) ;
return - V_34 ;
}
if ( V_8 -> V_35 ) {
V_26 = V_8 -> V_35 ( V_9 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_2 = F_12 ( & V_36 , & V_9 -> V_9 ,
F_13 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_26 = - V_27 ;
goto V_37;
}
V_2 -> V_38 = V_24 -> V_39 ;
V_2 -> V_40 = F_14 ( V_24 ) ;
V_2 -> V_19 = F_15 ( & V_9 -> V_9 , V_24 ) ;
if ( F_16 ( V_2 -> V_19 ) ) {
V_26 = F_17 ( V_2 -> V_19 ) ;
goto V_41;
}
V_26 = F_18 ( V_2 , V_25 , V_42 ) ;
if ( V_26 )
goto V_41;
F_19 ( V_9 , V_2 ) ;
return V_26 ;
V_41:
F_20 ( V_2 ) ;
V_37:
if ( V_8 -> V_43 )
V_8 -> V_43 ( V_9 ) ;
return V_26 ;
}
static int F_21 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
F_23 ( V_2 ) ;
F_20 ( V_2 ) ;
if ( V_8 -> V_43 )
V_8 -> V_43 ( V_9 ) ;
if ( V_8 == & V_30 )
V_9 -> V_9 . V_29 = NULL ;
return 0 ;
}
static int F_24 ( struct V_44 * V_9 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_26 ( V_9 , struct V_3 , V_9 ) ;
bool V_45 = F_27 ( V_9 ) ;
int V_46 ;
V_46 = F_28 ( V_2 , V_45 ) ;
if ( V_8 -> V_47 )
V_8 -> V_47 ( V_4 ) ;
return V_46 ;
}
static int F_29 ( struct V_44 * V_9 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_26 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_35 ) {
int V_26 = V_8 -> V_35 ( V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_30 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_31 ( void )
{
if ( F_7 () )
return - V_28 ;
F_32 ( L_3 V_48 L_4 , V_49 ) ;
F_33 ( & V_36 , & V_50 ) ;
return F_34 ( & V_51 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_51 ) ;
}
