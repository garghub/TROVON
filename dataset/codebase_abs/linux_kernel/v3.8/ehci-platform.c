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
V_12 -> V_18 = V_2 -> V_19 + V_8 -> V_20 ;
V_13 = F_4 ( V_2 ) ;
if ( V_13 )
return V_13 ;
if ( V_8 -> V_21 )
V_12 -> V_22 = 0 ;
return 0 ;
}
static int F_5 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
int V_25 ;
int V_26 = - V_27 ;
if ( ! V_8 ) {
F_6 ( 1 ) ;
return - V_28 ;
}
if ( F_7 () )
return - V_28 ;
V_25 = F_8 ( V_9 , 0 ) ;
if ( V_25 < 0 ) {
F_9 ( & V_9 -> V_9 , L_1 ) ;
return V_25 ;
}
V_24 = F_10 ( V_9 , V_29 , 0 ) ;
if ( ! V_24 ) {
F_9 ( & V_9 -> V_9 , L_2 ) ;
return - V_30 ;
}
if ( V_8 -> V_31 ) {
V_26 = V_8 -> V_31 ( V_9 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_2 = F_11 ( & V_32 , & V_9 -> V_9 ,
F_12 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_26 = - V_27 ;
goto V_33;
}
V_2 -> V_34 = V_24 -> V_35 ;
V_2 -> V_36 = F_13 ( V_24 ) ;
V_2 -> V_19 = F_14 ( & V_9 -> V_9 , V_24 ) ;
if ( ! V_2 -> V_19 ) {
V_26 = - V_27 ;
goto V_37;
}
V_26 = F_15 ( V_2 , V_25 , V_38 ) ;
if ( V_26 )
goto V_37;
F_16 ( V_9 , V_2 ) ;
return V_26 ;
V_37:
F_17 ( V_2 ) ;
V_33:
if ( V_8 -> V_39 )
V_8 -> V_39 ( V_9 ) ;
return V_26 ;
}
static int F_18 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_19 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
F_20 ( V_2 ) ;
F_17 ( V_2 ) ;
F_16 ( V_9 , NULL ) ;
if ( V_8 -> V_39 )
V_8 -> V_39 ( V_9 ) ;
return 0 ;
}
static int F_21 ( struct V_40 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_23 ( V_9 , struct V_3 , V_9 ) ;
bool V_41 = F_24 ( V_9 ) ;
int V_42 ;
V_42 = F_25 ( V_2 , V_41 ) ;
if ( V_8 -> V_43 )
V_8 -> V_43 ( V_4 ) ;
return V_42 ;
}
static int F_26 ( struct V_40 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_23 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_31 ) {
int V_26 = V_8 -> V_31 ( V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_27 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( F_7 () )
return - V_28 ;
F_29 ( L_3 V_44 L_4 , V_45 ) ;
F_30 ( & V_32 , & V_46 ) ;
return F_31 ( & V_47 ) ;
}
static void T_2 F_32 ( void )
{
F_33 ( & V_47 ) ;
}
