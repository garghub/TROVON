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
struct V_7 * V_8 ;
int V_25 ;
int V_26 = - V_27 ;
if ( F_6 () )
return - V_28 ;
if ( ! V_9 -> V_9 . V_10 )
V_9 -> V_9 . V_10 = & V_29 ;
if ( ! V_9 -> V_9 . V_30 )
V_9 -> V_9 . V_30 = & V_9 -> V_9 . V_31 ;
if ( ! V_9 -> V_9 . V_31 )
V_9 -> V_9 . V_31 = F_7 ( 32 ) ;
V_8 = V_9 -> V_9 . V_10 ;
V_25 = F_8 ( V_9 , 0 ) ;
if ( V_25 < 0 ) {
F_9 ( & V_9 -> V_9 , L_1 ) ;
return V_25 ;
}
V_24 = F_10 ( V_9 , V_32 , 0 ) ;
if ( ! V_24 ) {
F_9 ( & V_9 -> V_9 , L_2 ) ;
return - V_33 ;
}
if ( V_8 -> V_34 ) {
V_26 = V_8 -> V_34 ( V_9 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_2 = F_11 ( & V_35 , & V_9 -> V_9 ,
F_12 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_26 = - V_27 ;
goto V_36;
}
V_2 -> V_37 = V_24 -> V_38 ;
V_2 -> V_39 = F_13 ( V_24 ) ;
V_2 -> V_19 = F_14 ( & V_9 -> V_9 , V_24 ) ;
if ( F_15 ( V_2 -> V_19 ) ) {
V_26 = F_16 ( V_2 -> V_19 ) ;
goto V_40;
}
V_26 = F_17 ( V_2 , V_25 , V_41 ) ;
if ( V_26 )
goto V_40;
F_18 ( V_9 , V_2 ) ;
return V_26 ;
V_40:
F_19 ( V_2 ) ;
V_36:
if ( V_8 -> V_42 )
V_8 -> V_42 ( V_9 ) ;
return V_26 ;
}
static int F_20 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_21 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
F_22 ( V_2 ) ;
F_19 ( V_2 ) ;
F_18 ( V_9 , NULL ) ;
if ( V_8 -> V_42 )
V_8 -> V_42 ( V_9 ) ;
if ( V_8 == & V_29 )
V_9 -> V_9 . V_10 = NULL ;
return 0 ;
}
static int F_23 ( struct V_43 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_25 ( V_9 , struct V_3 , V_9 ) ;
bool V_44 = F_26 ( V_9 ) ;
int V_45 ;
V_45 = F_27 ( V_2 , V_44 ) ;
if ( V_8 -> V_46 )
V_8 -> V_46 ( V_4 ) ;
return V_45 ;
}
static int F_28 ( struct V_43 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_25 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_34 ) {
int V_26 = V_8 -> V_34 ( V_4 ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_29 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_30 ( void )
{
if ( F_6 () )
return - V_28 ;
F_31 ( L_3 V_47 L_4 , V_48 ) ;
F_32 ( & V_35 , & V_49 ) ;
return F_33 ( & V_50 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_50 ) ;
}
