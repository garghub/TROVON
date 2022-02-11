static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_7 -> V_10 . V_11 ;
const T_2 * V_12 ;
int V_13 ;
T_2 V_14 ;
V_12 = F_6 ( V_9 , L_1 ,
& V_13 ) ;
if ( V_12 && ( V_13 == sizeof( T_2 ) ) )
V_14 = * V_12 ;
else
V_14 = V_15 ;
V_2 -> V_16 . clock . V_17 = V_14 ;
if ( V_2 -> V_16 . clock . V_17 > 10000000 ) {
V_2 -> V_18 |= V_19 ;
V_2 -> V_16 . clock . V_17 /= 2 ;
}
if ( V_2 -> V_16 . clock . V_17 > 8000000 )
V_2 -> V_18 |= V_20 ;
if ( F_6 ( V_9 , L_2 , NULL ) )
V_2 -> V_18 |= V_20 ;
if ( F_6 ( V_9 , L_3 , NULL ) )
V_2 -> V_18 |= V_21 ;
if ( ! F_6 ( V_9 , L_4 , NULL ) )
V_2 -> V_22 |= V_23 ;
if ( F_6 ( V_9 , L_5 , NULL ) )
V_2 -> V_22 |= V_24 ;
if ( F_6 ( V_9 , L_6 , NULL ) )
V_2 -> V_22 |= V_25 ;
if ( F_6 ( V_9 , L_7 , NULL ) )
V_2 -> V_22 |= V_26 ;
if ( F_6 ( V_9 , L_8 , NULL ) )
V_2 -> V_22 |= V_27 ;
V_12 = F_6 ( V_9 , L_9 , & V_13 ) ;
if ( V_12 && ( V_13 == sizeof( T_2 ) ) && * V_12 > 0 ) {
T_2 V_28 = V_14 / * V_12 ;
int V_29 ;
if ( V_28 > 0 && V_28 < 16 ) {
V_2 -> V_18 |= V_30 ;
V_2 -> V_31 |= ( V_28 - 1 ) & V_32 ;
V_12 = F_6 ( V_9 , L_10 ,
& V_13 ) ;
if ( V_12 && ( V_13 == sizeof( T_2 ) ) ) {
V_29 = * V_12 ;
} else {
V_29 = ( V_33 >>
V_34 ) -
( ( V_28 * V_14 - 1 ) / 8000000 ) ;
if ( V_29 < 0 )
V_29 = 0 ;
}
V_2 -> V_31 |= ( V_29 << V_34 ) &
V_33 ;
} else {
F_7 ( & V_7 -> V_10 , L_11 ) ;
}
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_35 * V_36 = F_9 ( & V_7 -> V_10 ) ;
V_2 -> V_16 . clock . V_17 = V_36 -> V_37 ;
if ( V_2 -> V_18 & V_19 )
V_2 -> V_16 . clock . V_17 /= 2 ;
V_2 -> V_31 = V_36 -> V_38 ;
V_2 -> V_22 = V_36 -> V_39 ;
V_2 -> V_18 = V_36 -> V_40 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_41 * V_10 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
T_3 V_44 ;
void T_4 * V_45 ;
int V_46 , V_47 ;
V_43 = F_11 ( V_7 , V_48 , 0 ) ;
V_47 = F_12 ( V_7 , 0 ) ;
if ( ! V_43 || V_47 <= 0 )
return - V_49 ;
V_44 = F_13 ( V_43 ) ;
if ( ! F_14 ( V_43 -> V_50 , V_44 , V_7 -> V_51 ) )
return - V_52 ;
V_45 = F_15 ( V_43 -> V_50 , V_44 ) ;
if ( ! V_45 ) {
V_46 = - V_53 ;
goto V_54;
}
V_10 = F_16 ( 0 ) ;
if ( ! V_10 ) {
V_46 = - V_53 ;
goto V_55;
}
V_10 -> V_47 = V_47 ;
V_2 = F_17 ( V_10 ) ;
V_2 -> V_56 = F_1 ;
V_2 -> V_57 = F_3 ;
V_2 -> V_58 = V_59 ;
V_2 -> V_4 = V_45 ;
if ( V_7 -> V_10 . V_11 )
V_46 = F_5 ( V_7 , V_2 ) ;
else if ( F_9 ( & V_7 -> V_10 ) )
V_46 = F_8 ( V_7 , V_2 ) ;
else
V_46 = - V_49 ;
if ( V_46 )
goto V_60;
F_7 ( & V_7 -> V_10 ,
L_12
L_13 ,
V_2 -> V_4 , V_10 -> V_47 , V_2 -> V_16 . clock . V_17 ,
V_2 -> V_18 , V_2 -> V_22 , V_2 -> V_31 ) ;
F_18 ( V_7 , V_10 ) ;
F_19 ( V_10 , & V_7 -> V_10 ) ;
V_46 = F_20 ( V_10 ) ;
if ( V_46 ) {
F_21 ( & V_7 -> V_10 ,
L_14 , V_46 ) ;
goto V_60;
}
return 0 ;
V_60:
F_22 ( V_10 ) ;
V_55:
F_23 ( V_45 ) ;
V_54:
F_24 ( V_43 -> V_50 , V_44 ) ;
return V_46 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_41 * V_10 = F_26 ( V_7 ) ;
struct V_1 * V_2 = F_17 ( V_10 ) ;
struct V_42 * V_43 ;
F_27 ( V_10 ) ;
F_23 ( V_2 -> V_4 ) ;
F_22 ( V_10 ) ;
V_43 = F_11 ( V_7 , V_48 , 0 ) ;
F_24 ( V_43 -> V_50 , F_13 ( V_43 ) ) ;
return 0 ;
}
