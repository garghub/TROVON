static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , const char * V_5 ,
T_1 V_6 , T_1 V_7 , int V_8 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
int V_11 ;
T_1 V_12 ;
if ( ! F_3 ( V_4 , V_5 , & V_12 ) ) {
V_11 = F_4 ( V_12 * V_10 -> V_13 , V_14 ) - V_8 ;
if ( V_11 < 0 ) {
V_11 = 0 ;
} else if ( V_11 > V_7 ) {
F_5 ( & V_2 -> V_15 , L_1 , V_5 ) ;
return - V_16 ;
}
F_6 ( V_11 , V_10 -> V_17 + V_6 ) ;
}
F_7 ( & V_2 -> V_15 , L_2 , V_5 , V_8 +
F_8 ( V_10 -> V_17 + V_6 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_18 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
T_1 V_19 ;
int V_20 ;
if ( ! F_3 ( V_4 , L_3 , & V_19 ) ) {
if ( V_19 == 8 ) {
V_19 = V_21 ;
} else if ( V_19 == 16 ) {
V_19 = V_22 ;
} else if ( V_19 == 32 ) {
V_19 = V_23 ;
} else {
F_5 ( & V_2 -> V_15 , L_4 , V_18 ) ;
return - V_16 ;
}
} else {
F_5 ( & V_2 -> V_15 , L_5 ) ;
return - V_16 ;
}
if ( F_10 ( V_4 , L_6 ) )
V_19 |= V_24 ;
if ( F_10 ( V_4 , L_7 ) )
V_19 |= V_25 ;
if ( F_10 ( V_4 , L_8 ) )
V_19 |= V_26 ;
if ( F_10 ( V_4 , L_9 ) )
V_19 |= V_27 ;
if ( F_11 ( V_2 ) == 0x172 &&
F_10 ( V_4 , L_10 ) )
V_19 |= V_28 ;
if ( F_10 ( V_4 , L_11 ) )
V_19 |= V_29 ;
F_6 ( V_19 , V_10 -> V_17 + F_12 ( V_18 ) ) ;
F_7 ( & V_2 -> V_15 , L_12 , V_18 , V_19 ) ;
V_20 = F_1 ( V_2 , V_4 , L_13 ,
F_13 ( V_18 ) ,
V_30 , 1 ) ;
if ( V_20 )
goto V_31;
V_20 = F_1 ( V_2 , V_4 , L_14 ,
F_14 ( V_18 ) ,
V_32 , 0 ) ;
if ( V_20 )
goto V_31;
V_20 = F_1 ( V_2 , V_4 , L_15 ,
F_15 ( V_18 ) ,
V_33 , 1 ) ;
if ( V_20 )
goto V_31;
V_20 = F_1 ( V_2 , V_4 , L_16 ,
F_16 ( V_18 ) ,
V_34 , 1 ) ;
if ( V_20 )
goto V_31;
V_20 = F_1 ( V_2 , V_4 , L_17 ,
F_17 ( V_18 ) ,
V_35 , 2 ) ;
if ( V_20 )
goto V_31;
V_20 = F_1 ( V_2 , V_4 , L_18 ,
F_18 ( V_18 ) ,
V_36 , 1 ) ;
if ( V_20 )
goto V_31;
return 0 ;
V_31:
F_5 ( & V_2 -> V_15 , L_19 , V_18 ) ;
return V_20 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_18 ;
if ( ! F_3 ( V_4 , L_20 , & V_18 ) ) {
if ( V_18 >= V_37 ) {
F_5 ( & V_2 -> V_15 , L_21 , V_18 ) ;
return - V_16 ;
}
return F_9 ( V_2 , V_4 , V_18 ) ;
}
F_5 ( & V_2 -> V_15 , L_22 ) ;
return - V_16 ;
}
static int F_20 ( struct V_1 * V_2 , const struct V_38 * V_39 )
{
struct V_3 * V_40 , * V_4 = V_2 -> V_15 . V_41 ;
struct V_42 * V_15 = & V_2 -> V_15 ;
static const char * V_43 = L_23 ;
struct V_9 * V_10 ;
int V_20 ;
if ( F_11 ( V_2 ) == 0x172 ) {
if ( F_21 ( V_2 ) < F_22 ( V_44 ) )
V_43 = V_44 [ F_21 ( V_2 ) ] ;
} else if ( F_11 ( V_2 ) == 0x175 ) {
if ( F_21 ( V_2 ) < F_22 ( V_45 ) )
V_43 = V_45 [ F_21 ( V_2 ) ] ;
} else if ( F_11 ( V_2 ) == 0x176 ) {
if ( F_21 ( V_2 ) < F_22 ( V_46 ) )
V_43 = V_46 [ F_21 ( V_2 ) ] ;
}
F_23 ( V_15 , L_24 , F_11 ( V_2 ) , V_43 ) ;
V_10 = F_24 ( V_15 , sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
return - V_48 ;
V_10 -> V_49 = F_25 ( V_15 , L_25 ) ;
if ( F_26 ( V_10 -> V_49 ) ) {
F_5 ( V_15 , L_26 ) ;
return F_27 ( V_10 -> V_49 ) ;
}
V_20 = F_28 ( V_10 -> V_49 ) ;
if ( V_20 ) {
F_5 ( V_15 , L_27 ) ;
return V_20 ;
}
V_10 -> V_13 = F_29 ( V_10 -> V_49 ) / V_50 ;
if ( ! V_10 -> V_13 ) {
F_5 ( V_15 , L_28 ) ;
V_20 = - V_16 ;
goto V_51;
}
V_20 = F_30 ( V_2 , NULL ) ;
if ( V_20 ) {
F_5 ( V_15 , L_29 ) ;
goto V_51;
}
V_10 -> V_17 = F_31 ( V_15 , V_2 -> V_52 . V_8 ,
F_32 ( & V_2 -> V_52 ) ) ;
if ( ! V_10 -> V_17 ) {
F_5 ( V_15 , L_30 ) ;
V_20 = - V_48 ;
goto V_53;
}
F_33 ( V_2 , V_10 ) ;
F_34 (np, child_np) {
V_20 = F_19 ( V_2 , V_40 ) ;
if ( V_20 )
continue;
F_35 ( V_40 , NULL , NULL , V_15 ) ;
}
return 0 ;
V_53:
F_36 ( V_2 ) ;
V_51:
F_37 ( V_10 -> V_49 ) ;
return V_20 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_37 ( V_10 -> V_49 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
