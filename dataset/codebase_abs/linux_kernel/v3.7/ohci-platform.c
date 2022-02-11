static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = V_4 -> V_9 . V_10 ;
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_13 ;
if ( V_8 -> V_14 )
V_12 -> V_15 |= V_16 ;
if ( V_8 -> V_17 )
V_12 -> V_15 |= V_18 ;
if ( V_8 -> V_19 )
V_12 -> V_15 |= V_20 ;
F_4 ( V_12 ) ;
V_13 = F_5 ( V_12 ) ;
return V_13 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_13 ;
V_13 = F_7 ( V_12 ) ;
if ( V_13 < 0 ) {
F_8 ( V_12 , L_1 ) ;
F_9 ( V_2 ) ;
}
return V_13 ;
}
static int T_1 F_10 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
int V_23 ;
int V_13 = - V_24 ;
if ( ! V_8 ) {
F_11 ( 1 ) ;
return - V_25 ;
}
if ( F_12 () )
return - V_25 ;
V_23 = F_13 ( V_9 , 0 ) ;
if ( V_23 < 0 ) {
F_14 ( L_2 ) ;
return V_23 ;
}
V_22 = F_15 ( V_9 , V_26 , 0 ) ;
if ( ! V_22 ) {
F_14 ( L_3 ) ;
return - V_27 ;
}
if ( V_8 -> V_28 ) {
V_13 = V_8 -> V_28 ( V_9 ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_2 = F_16 ( & V_29 , & V_9 -> V_9 ,
F_17 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 ) {
V_13 = - V_24 ;
goto V_30;
}
V_2 -> V_31 = V_22 -> V_32 ;
V_2 -> V_33 = F_18 ( V_22 ) ;
if ( ! F_19 ( V_2 -> V_31 , V_2 -> V_33 , V_34 ) ) {
F_14 ( L_4 ) ;
V_13 = - V_35 ;
goto V_36;
}
V_2 -> V_37 = F_20 ( V_2 -> V_31 , V_2 -> V_33 ) ;
if ( ! V_2 -> V_37 ) {
V_13 = - V_24 ;
goto V_38;
}
V_13 = F_21 ( V_2 , V_23 , V_39 ) ;
if ( V_13 )
goto V_40;
F_22 ( V_9 , V_2 ) ;
return V_13 ;
V_40:
F_23 ( V_2 -> V_37 ) ;
V_38:
F_24 ( V_2 -> V_31 , V_2 -> V_33 ) ;
V_36:
F_25 ( V_2 ) ;
V_30:
if ( V_8 -> V_41 )
V_8 -> V_41 ( V_9 ) ;
return V_13 ;
}
static int T_2 F_26 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_27 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_9 . V_10 ;
F_28 ( V_2 ) ;
F_23 ( V_2 -> V_37 ) ;
F_24 ( V_2 -> V_31 , V_2 -> V_33 ) ;
F_25 ( V_2 ) ;
F_22 ( V_9 , NULL ) ;
if ( V_8 -> V_41 )
V_8 -> V_41 ( V_9 ) ;
return 0 ;
}
static int F_29 ( struct V_42 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_30 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_43 )
V_8 -> V_43 ( V_4 ) ;
return 0 ;
}
static int F_31 ( struct V_42 * V_9 )
{
struct V_1 * V_2 = F_32 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_10 ;
struct V_3 * V_4 =
F_30 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_28 ) {
int V_13 = V_8 -> V_28 ( V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
}
F_33 ( V_2 ) ;
return 0 ;
}
