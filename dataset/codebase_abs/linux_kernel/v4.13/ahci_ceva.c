static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
int V_8 ;
V_7 = V_9 | V_10 | V_11 | V_12 ;
F_2 ( V_7 , V_3 + V_13 ) ;
V_7 = F_3 ( V_3 + V_14 ) ;
V_7 |= V_15 ;
F_2 ( V_7 , V_3 + V_14 ) ;
for ( V_8 = 0 ; V_8 < V_16 ; V_8 ++ ) {
V_7 = V_17 | V_18 | ( V_19 + V_8 ) ;
F_2 ( V_7 , V_3 + V_20 ) ;
V_7 = V_21 | V_22 | V_23 ;
F_2 ( V_7 , V_3 + V_24 ) ;
V_7 = V_25 | V_26 | V_27 | V_28 ;
F_2 ( V_7 , V_3 + V_29 ) ;
V_7 = V_30 | V_31 | V_32 | V_33 ;
F_2 ( V_7 , V_3 + V_34 ) ;
V_7 = V_35 | V_36 | V_37 | V_38 ;
F_2 ( V_7 , V_3 + V_39 ) ;
V_7 = V_40 | V_41 ;
F_2 ( V_7 , V_3 + V_42 ) ;
V_7 = V_43 | V_44 ;
F_2 ( V_7 , V_3 + V_45 ) ;
V_7 = V_46 | V_47 ;
if ( V_5 -> V_48 & V_49 )
V_7 = V_50 | V_47 ;
F_2 ( V_7 , V_3 + V_51 + V_52 + V_53 * V_8 ) ;
}
}
static int F_4 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = V_55 -> V_58 . V_59 ;
struct V_60 * V_58 = & V_55 -> V_58 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_61 ;
V_5 = F_5 ( V_58 , sizeof( * V_5 ) , V_62 ) ;
if ( ! V_5 )
return - V_63 ;
V_5 -> V_64 = V_55 ;
V_2 = F_6 ( V_55 ) ;
if ( F_7 ( V_2 ) )
return F_8 ( V_2 ) ;
V_61 = F_9 ( V_2 ) ;
if ( V_61 )
return V_61 ;
if ( F_10 ( V_57 , L_1 ) )
V_5 -> V_48 = V_49 ;
V_2 -> V_6 = V_5 ;
F_1 ( V_2 ) ;
V_61 = F_11 ( V_55 , V_2 , & V_65 ,
& V_66 ) ;
if ( V_61 )
goto V_67;
return 0 ;
V_67:
F_12 ( V_2 ) ;
return V_61 ;
}
static int T_3 F_13 ( struct V_60 * V_58 )
{
return F_14 ( V_58 ) ;
}
static int T_3 F_15 ( struct V_60 * V_58 )
{
return F_16 ( V_58 ) ;
}
