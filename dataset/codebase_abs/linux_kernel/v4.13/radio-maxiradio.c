static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_7 = V_5 -> V_8 ;
T_1 V_9 = 0 ;
V_9 |= ( V_6 & V_10 ) ? V_11 : 0 ;
V_9 |= ( V_6 & V_12 ) ? V_13 : 0 ;
V_9 |= ( V_6 & V_14 ) ? V_15 : 0 ;
V_9 |= V_16 ;
F_4 ( V_9 , V_7 -> V_17 ) ;
}
static T_1 F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_7 = V_5 -> V_8 ;
T_1 V_9 = F_6 ( V_7 -> V_17 ) ;
return ( ( V_9 & V_11 ) ? V_10 : 0 ) |
( ( V_9 & V_18 ) ? V_19 : 0 ) ;
}
static void F_7 ( struct V_4 * V_5 , bool V_20 )
{
}
static int F_8 ( struct V_21 * V_22 ,
const struct V_23 * V_24 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
int V_25 = - V_26 ;
V_7 = F_9 ( sizeof( * V_7 ) , V_27 ) ;
if ( V_7 == NULL ) {
F_10 ( & V_22 -> V_7 , L_1 ) ;
return - V_26 ;
}
V_3 = & V_7 -> V_3 ;
F_11 ( V_3 , L_2 , & V_28 ) ;
V_25 = F_12 ( & V_22 -> V_7 , V_3 ) ;
if ( V_25 < 0 ) {
F_13 ( V_3 , L_3 ) ;
goto V_29;
}
V_7 -> V_5 . V_8 = V_7 ;
V_7 -> V_5 . V_30 = & V_31 ;
V_7 -> V_5 . V_32 = true ;
V_7 -> V_5 . V_3 = V_3 ;
V_7 -> V_5 . V_33 = V_33 ;
F_14 ( V_7 -> V_5 . V_34 , L_4 , sizeof( V_7 -> V_5 . V_34 ) ) ;
snprintf ( V_7 -> V_5 . V_35 , sizeof( V_7 -> V_5 . V_35 ) ,
L_5 , F_15 ( V_22 ) ) ;
V_25 = - V_36 ;
if ( ! F_16 ( F_17 ( V_22 , 0 ) ,
F_18 ( V_22 , 0 ) , V_3 -> V_37 ) ) {
F_10 ( & V_22 -> V_7 , L_6 ) ;
goto V_38;
}
if ( F_19 ( V_22 ) )
goto V_39;
V_7 -> V_17 = F_17 ( V_22 , 0 ) ;
if ( F_20 ( & V_7 -> V_5 , V_40 ) ) {
F_21 ( V_41 L_7 ) ;
goto V_39;
}
return 0 ;
V_39:
F_22 ( F_17 ( V_22 , 0 ) , F_18 ( V_22 , 0 ) ) ;
V_38:
F_23 ( V_3 ) ;
V_29:
F_24 ( V_7 ) ;
return V_25 ;
}
static void F_25 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = F_26 ( & V_22 -> V_7 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_27 ( & V_7 -> V_5 ) ;
F_4 ( 0 , V_7 -> V_17 ) ;
F_23 ( V_3 ) ;
F_22 ( F_17 ( V_22 , 0 ) , F_18 ( V_22 , 0 ) ) ;
F_24 ( V_7 ) ;
}
