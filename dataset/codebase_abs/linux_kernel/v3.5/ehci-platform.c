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
F_5 ( V_12 , 1 ) ;
if ( V_8 -> V_22 )
F_5 ( V_12 , 0 ) ;
return 0 ;
}
static int T_1 F_6 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_25 ;
int V_26 = - V_27 ;
F_7 ( ! V_9 -> V_9 . V_10 ) ;
if ( F_8 () )
return - V_28 ;
V_25 = F_9 ( V_9 , 0 ) ;
if ( V_25 < 0 ) {
F_10 ( L_1 ) ;
return V_25 ;
}
V_24 = F_11 ( V_9 , V_29 , 0 ) ;
if ( ! V_24 ) {
F_10 ( L_2 ) ;
return - V_30 ;
}
V_2 = F_12 ( & V_31 , & V_9 -> V_9 ,
F_13 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_27 ;
V_2 -> V_32 = V_24 -> V_33 ;
V_2 -> V_34 = F_14 ( V_24 ) ;
if ( ! F_15 ( V_2 -> V_32 , V_2 -> V_34 , V_35 ) ) {
F_10 ( L_3 ) ;
V_26 = - V_36 ;
goto V_37;
}
V_2 -> V_19 = F_16 ( V_2 -> V_32 , V_2 -> V_34 ) ;
if ( ! V_2 -> V_19 )
goto V_38;
V_26 = F_17 ( V_2 , V_25 , V_39 ) ;
if ( V_26 )
goto V_40;
F_18 ( V_9 , V_2 ) ;
return V_26 ;
V_40:
F_19 ( V_2 -> V_19 ) ;
V_38:
F_20 ( V_2 -> V_32 , V_2 -> V_34 ) ;
V_37:
F_21 ( V_2 ) ;
return V_26 ;
}
static int T_2 F_22 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_23 ( V_9 ) ;
F_24 ( V_2 ) ;
F_19 ( V_2 -> V_19 ) ;
F_20 ( V_2 -> V_32 , V_2 -> V_34 ) ;
F_21 ( V_2 ) ;
F_18 ( V_9 , NULL ) ;
return 0 ;
}
static int F_25 ( struct V_41 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
bool V_42 = F_27 ( V_9 ) ;
F_28 ( F_3 ( V_2 ) , V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_41 * V_9 )
{
struct V_1 * V_2 = F_26 ( V_9 ) ;
F_30 ( F_3 ( V_2 ) ) ;
return 0 ;
}
