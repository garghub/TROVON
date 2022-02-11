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
int V_26 ;
if ( F_7 () )
return - V_27 ;
if ( ! F_3 ( & V_9 -> V_9 ) )
V_9 -> V_9 . V_28 = & V_29 ;
V_26 = F_8 ( & V_9 -> V_9 , F_9 ( 32 ) ) ;
if ( V_26 )
return V_26 ;
V_8 = F_3 ( & V_9 -> V_9 ) ;
V_25 = F_10 ( V_9 , 0 ) ;
if ( V_25 < 0 ) {
F_11 ( & V_9 -> V_9 , L_1 ) ;
return V_25 ;
}
V_24 = F_12 ( V_9 , V_30 , 0 ) ;
if ( ! V_24 ) {
F_11 ( & V_9 -> V_9 , L_2 ) ;
return - V_31 ;
}
if ( V_8 -> V_32 ) {
V_26 = V_8 -> V_32 ( V_9 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_2 = F_13 ( & V_33 , & V_9 -> V_9 ,
F_14 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_26 = - V_34 ;
goto V_35;
}
V_2 -> V_36 = V_24 -> V_37 ;
V_2 -> V_38 = F_15 ( V_24 ) ;
V_2 -> V_19 = F_16 ( & V_9 -> V_9 , V_24 ) ;
if ( F_17 ( V_2 -> V_19 ) ) {
V_26 = F_18 ( V_2 -> V_19 ) ;
goto V_39;
}
V_26 = F_19 ( V_2 , V_25 , V_40 ) ;
if ( V_26 )
goto V_39;
F_20 ( V_2 -> V_5 . V_6 ) ;
F_21 ( V_9 , V_2 ) ;
return V_26 ;
V_39:
F_22 ( V_2 ) ;
V_35:
if ( V_8 -> V_41 )
V_8 -> V_41 ( V_9 ) ;
return V_26 ;
}
static int F_23 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
F_25 ( V_2 ) ;
F_22 ( V_2 ) ;
if ( V_8 -> V_41 )
V_8 -> V_41 ( V_9 ) ;
if ( V_8 == & V_29 )
V_9 -> V_9 . V_28 = NULL ;
return 0 ;
}
static int F_26 ( struct V_42 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_28 ( V_9 , struct V_3 , V_9 ) ;
bool V_43 = F_29 ( V_9 ) ;
int V_44 ;
V_44 = F_30 ( V_2 , V_43 ) ;
if ( V_8 -> V_45 )
V_8 -> V_45 ( V_4 ) ;
return V_44 ;
}
static int F_31 ( struct V_42 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_28 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_32 ) {
int V_26 = V_8 -> V_32 ( V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_32 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_33 ( void )
{
if ( F_7 () )
return - V_27 ;
F_34 ( L_3 V_46 L_4 , V_47 ) ;
F_35 ( & V_33 , & V_48 ) ;
return F_36 ( & V_49 ) ;
}
static void T_2 F_37 ( void )
{
F_38 ( & V_49 ) ;
}
