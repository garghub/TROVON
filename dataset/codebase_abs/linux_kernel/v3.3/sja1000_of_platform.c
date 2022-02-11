static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
F_4 ( V_2 -> V_4 + V_3 , V_5 ) ;
}
static int T_2 F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( & V_7 -> V_9 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_10 * V_11 = V_7 -> V_9 . V_12 ;
struct V_13 V_14 ;
F_8 ( & V_7 -> V_9 , NULL ) ;
F_9 ( V_9 ) ;
F_10 ( V_9 ) ;
F_11 ( V_2 -> V_4 ) ;
F_12 ( V_9 -> V_15 ) ;
F_13 ( V_11 , 0 , & V_14 ) ;
F_14 ( V_14 . V_16 , F_15 ( & V_14 ) ) ;
return 0 ;
}
static int T_3 F_16 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_9 . V_12 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_13 V_14 ;
const T_4 * V_17 ;
int V_18 , V_15 , V_19 , V_20 ;
void T_5 * V_21 ;
V_18 = F_13 ( V_11 , 0 , & V_14 ) ;
if ( V_18 ) {
F_17 ( & V_7 -> V_9 , L_1 ) ;
return V_18 ;
}
V_19 = F_15 ( & V_14 ) ;
if ( ! F_18 ( V_14 . V_16 , V_19 , V_22 ) ) {
F_17 ( & V_7 -> V_9 , L_2 , & V_14 ) ;
return - V_23 ;
}
V_21 = F_19 ( V_14 . V_16 , V_19 ) ;
if ( ! V_21 ) {
F_17 ( & V_7 -> V_9 , L_3 , & V_14 ) ;
V_18 = - V_24 ;
goto V_25;
}
V_15 = F_20 ( V_11 , 0 ) ;
if ( V_15 == V_26 ) {
F_17 ( & V_7 -> V_9 , L_4 ) ;
V_18 = - V_27 ;
goto V_28;
}
V_9 = F_21 ( 0 ) ;
if ( ! V_9 ) {
V_18 = - V_24 ;
goto V_29;
}
V_2 = F_7 ( V_9 ) ;
V_2 -> V_30 = F_1 ;
V_2 -> V_31 = F_3 ;
V_17 = F_22 ( V_11 , L_5 , & V_20 ) ;
if ( V_17 && ( V_20 == sizeof( T_4 ) ) )
V_2 -> V_32 . clock . V_33 = * V_17 / 2 ;
else
V_2 -> V_32 . clock . V_33 = V_34 ;
V_17 = F_22 ( V_11 , L_6 , & V_20 ) ;
if ( V_17 && ( V_20 == sizeof( T_4 ) ) )
V_2 -> V_35 |= * V_17 & V_36 ;
else
V_2 -> V_35 |= V_37 ;
V_17 = F_22 ( V_11 , L_7 , & V_20 ) ;
if ( V_17 && ( V_20 == sizeof( T_4 ) ) )
V_2 -> V_35 |= ( * V_17 << V_38 ) & V_39 ;
else
V_2 -> V_35 |= V_40 ;
V_17 = F_22 ( V_11 , L_8 , & V_20 ) ;
if ( V_17 && ( V_20 == sizeof( T_4 ) ) && * V_17 ) {
T_4 V_41 = V_2 -> V_32 . clock . V_33 * 2 / * V_17 ;
if ( V_41 > 1 )
V_2 -> V_42 |= V_41 / 2 - 1 ;
else
V_2 -> V_42 |= V_43 ;
} else {
V_2 -> V_42 |= V_44 ;
}
V_17 = F_22 ( V_11 , L_9 , NULL ) ;
if ( ! V_17 )
V_2 -> V_42 |= V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_4 = V_21 ;
V_9 -> V_15 = V_15 ;
F_23 ( & V_7 -> V_9 ,
L_10 ,
V_2 -> V_4 , V_9 -> V_15 , V_2 -> V_32 . clock . V_33 ,
V_2 -> V_35 , V_2 -> V_42 ) ;
F_8 ( & V_7 -> V_9 , V_9 ) ;
F_24 ( V_9 , & V_7 -> V_9 ) ;
V_18 = F_25 ( V_9 ) ;
if ( V_18 ) {
F_17 ( & V_7 -> V_9 , L_11 ,
V_22 , V_18 ) ;
goto V_48;
}
return 0 ;
V_48:
F_10 ( V_9 ) ;
V_29:
F_12 ( V_15 ) ;
V_28:
F_11 ( V_21 ) ;
V_25:
F_14 ( V_14 . V_16 , V_19 ) ;
return V_18 ;
}
