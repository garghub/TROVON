static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_3 ( V_4 , L_1 , V_4 ) ;
V_5 = F_4 ( V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_5 ( V_4 ) ;
if ( V_5 < 0 ) {
F_6 ( L_2 , V_2 -> V_6 . V_7 ) ;
F_7 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int T_1 F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_14 * V_15 ;
int V_16 ;
int F_6 ;
V_11 = V_9 -> V_17 . V_18 ;
if ( ! V_11 ) {
F_9 ( & V_9 -> V_17 , L_3 ) ;
return - V_19 ;
}
V_13 = F_10 ( sizeof( struct V_12 ) , V_20 ) ;
if ( ! V_13 )
return - V_21 ;
V_13 -> V_17 = & V_9 -> V_17 ;
V_2 = F_11 ( & V_22 , & V_9 -> V_17 ,
F_12 ( & V_9 -> V_17 ) ) ;
if ( ! V_2 ) {
F_9 ( & V_9 -> V_17 , L_4 ) ;
F_6 = - V_21 ;
goto V_23;
}
V_13 -> V_2 = V_2 ;
V_13 -> V_24 = F_13 ( & V_9 -> V_17 , L_5 ) ;
if ( F_14 ( V_13 -> V_24 ) ) {
F_9 ( & V_9 -> V_17 , L_6 ) ;
F_6 = F_15 ( V_13 -> V_24 ) ;
goto V_25;
}
F_6 = F_16 ( V_13 -> V_24 ) ;
if ( F_6 )
goto V_26;
V_15 = F_17 ( V_9 , V_27 , 0 ) ;
if ( ! V_15 ) {
F_9 ( & V_9 -> V_17 , L_7 ) ;
F_6 = - V_28 ;
goto V_29;
}
V_2 -> V_30 = V_15 -> V_31 ;
V_2 -> V_32 = F_18 ( V_15 ) ;
V_2 -> V_33 = F_19 ( V_15 -> V_31 , F_18 ( V_15 ) ) ;
if ( ! V_2 -> V_33 ) {
F_9 ( & V_9 -> V_17 , L_8 ) ;
F_6 = - V_21 ;
goto V_29;
}
V_16 = F_20 ( V_9 , 0 ) ;
if ( ! V_16 ) {
F_9 ( & V_9 -> V_17 , L_9 ) ;
F_6 = - V_34 ;
goto V_35;
}
if ( V_11 -> V_36 )
V_11 -> V_36 ( V_9 , V_37 ) ;
V_4 = F_2 ( V_2 ) ;
F_21 ( V_4 ) ;
F_6 = F_22 ( V_2 , V_16 , V_38 ) ;
if ( F_6 ) {
F_9 ( & V_9 -> V_17 , L_10 ) ;
goto V_35;
}
F_23 ( V_9 , V_13 ) ;
return 0 ;
V_35:
F_24 ( V_2 -> V_33 ) ;
V_29:
F_25 ( V_13 -> V_24 ) ;
V_26:
F_26 ( V_13 -> V_24 ) ;
V_25:
F_27 ( V_2 ) ;
V_23:
F_28 ( V_13 ) ;
return F_6 ;
}
static int T_2 F_29 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_17 . V_18 ;
struct V_12 * V_13 = F_30 ( V_9 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_31 ( V_2 ) ;
if ( V_11 && V_11 -> V_39 )
V_11 -> V_39 ( V_9 , V_37 ) ;
F_24 ( V_2 -> V_33 ) ;
F_25 ( V_13 -> V_24 ) ;
F_26 ( V_13 -> V_24 ) ;
F_27 ( V_2 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
static void F_32 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_30 ( V_9 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
if ( V_2 -> V_40 -> V_41 )
V_2 -> V_40 -> V_41 ( V_2 ) ;
}
static int F_33 ( struct V_42 * V_17 )
{
struct V_12 * V_13 = F_34 ( V_17 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_35 ( V_17 ) ;
struct V_10 * V_11 = V_9 -> V_17 . V_18 ;
unsigned long V_43 ;
int V_44 = 0 ;
F_36 ( & V_4 -> V_45 , V_43 ) ;
if ( V_2 -> V_46 != V_47 && V_2 -> V_46 != V_48 ) {
V_44 = - V_19 ;
goto V_35;
}
F_37 ( V_49 , & V_2 -> V_43 ) ;
if ( V_11 && V_11 -> V_39 )
V_11 -> V_39 ( V_9 , V_37 ) ;
V_35:
F_38 ( & V_4 -> V_45 , V_43 ) ;
return V_44 ;
}
static int F_39 ( struct V_42 * V_17 )
{
struct V_12 * V_13 = F_34 ( V_17 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_8 * V_9 = F_35 ( V_17 ) ;
struct V_10 * V_11 = V_9 -> V_17 . V_18 ;
if ( V_11 && V_11 -> V_36 )
V_11 -> V_36 ( V_9 , V_37 ) ;
F_40 ( V_49 , & V_2 -> V_43 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
