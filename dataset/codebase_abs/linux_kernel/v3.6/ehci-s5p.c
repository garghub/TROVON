static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
if ( ! V_2 -> V_5 . V_6 )
return;
V_4 = F_2 ( V_2 -> V_5 . V_6 ,
L_1 , 0 ) ;
if ( ! F_3 ( V_4 ) )
return;
V_3 = F_4 ( V_4 , V_7 , L_2 ) ;
if ( V_3 )
F_5 ( & V_2 -> V_5 , L_3 , V_4 ) ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
int V_18 ;
int V_3 ;
V_9 = V_2 -> V_5 . V_19 ;
if ( ! V_9 ) {
F_5 ( & V_2 -> V_5 , L_4 ) ;
return - V_20 ;
}
if ( ! V_2 -> V_5 . V_21 )
V_2 -> V_5 . V_21 = & V_22 ;
if ( ! V_2 -> V_5 . V_23 )
V_2 -> V_5 . V_23 = F_7 ( 32 ) ;
F_1 ( V_2 ) ;
V_11 = F_8 ( & V_2 -> V_5 , sizeof( struct V_10 ) ,
V_24 ) ;
if ( ! V_11 )
return - V_25 ;
V_11 -> V_5 = & V_2 -> V_5 ;
V_13 = F_9 ( & V_26 , & V_2 -> V_5 ,
F_10 ( & V_2 -> V_5 ) ) ;
if ( ! V_13 ) {
F_5 ( & V_2 -> V_5 , L_5 ) ;
return - V_25 ;
}
V_11 -> V_13 = V_13 ;
V_11 -> V_27 = F_11 ( & V_2 -> V_5 , L_6 ) ;
if ( F_12 ( V_11 -> V_27 ) ) {
F_5 ( & V_2 -> V_5 , L_7 ) ;
V_3 = F_13 ( V_11 -> V_27 ) ;
goto V_28;
}
V_3 = F_14 ( V_11 -> V_27 ) ;
if ( V_3 )
goto V_29;
V_17 = F_15 ( V_2 , V_30 , 0 ) ;
if ( ! V_17 ) {
F_5 ( & V_2 -> V_5 , L_8 ) ;
V_3 = - V_31 ;
goto V_32;
}
V_13 -> V_33 = V_17 -> V_34 ;
V_13 -> V_35 = F_16 ( V_17 ) ;
V_13 -> V_36 = F_17 ( & V_2 -> V_5 , V_17 -> V_34 , V_13 -> V_35 ) ;
if ( ! V_13 -> V_36 ) {
F_5 ( & V_2 -> V_5 , L_9 ) ;
V_3 = - V_25 ;
goto V_32;
}
V_18 = F_18 ( V_2 , 0 ) ;
if ( ! V_18 ) {
F_5 ( & V_2 -> V_5 , L_10 ) ;
V_3 = - V_37 ;
goto V_32;
}
if ( V_9 -> V_38 )
V_9 -> V_38 ( V_2 , V_39 ) ;
V_15 = F_19 ( V_13 ) ;
V_15 -> V_40 = V_13 -> V_36 ;
F_20 ( V_41 , F_21 ( V_13 -> V_36 ) ) ;
V_3 = F_22 ( V_13 , V_18 , V_42 ) ;
if ( V_3 ) {
F_5 ( & V_2 -> V_5 , L_11 ) ;
goto V_32;
}
F_23 ( V_2 , V_11 ) ;
return 0 ;
V_32:
F_24 ( V_11 -> V_27 ) ;
V_29:
F_25 ( V_11 -> V_27 ) ;
V_28:
F_26 ( V_13 ) ;
return V_3 ;
}
static int T_2 F_27 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_5 . V_19 ;
struct V_10 * V_11 = F_28 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
F_29 ( V_13 ) ;
if ( V_9 && V_9 -> V_43 )
V_9 -> V_43 ( V_2 , V_39 ) ;
F_24 ( V_11 -> V_27 ) ;
F_25 ( V_11 -> V_27 ) ;
F_26 ( V_13 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_28 ( V_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
if ( V_13 -> V_44 -> V_45 )
V_13 -> V_44 -> V_45 ( V_13 ) ;
}
static int F_31 ( struct V_46 * V_5 )
{
struct V_10 * V_11 = F_32 ( V_5 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
bool V_47 = F_33 ( V_5 ) ;
struct V_1 * V_2 = F_34 ( V_5 ) ;
struct V_8 * V_9 = V_2 -> V_5 . V_19 ;
int V_48 ;
V_48 = F_35 ( V_13 , V_47 ) ;
if ( V_9 && V_9 -> V_43 )
V_9 -> V_43 ( V_2 , V_39 ) ;
F_24 ( V_11 -> V_27 ) ;
return V_48 ;
}
static int F_36 ( struct V_46 * V_5 )
{
struct V_10 * V_11 = F_32 ( V_5 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_1 * V_2 = F_34 ( V_5 ) ;
struct V_8 * V_9 = V_2 -> V_5 . V_19 ;
F_14 ( V_11 -> V_27 ) ;
if ( V_9 && V_9 -> V_38 )
V_9 -> V_38 ( V_2 , V_39 ) ;
F_20 ( V_41 , F_21 ( V_13 -> V_36 ) ) ;
F_37 ( V_13 , false ) ;
return 0 ;
}
