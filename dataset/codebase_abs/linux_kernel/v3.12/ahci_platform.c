static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
const struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 V_10 = V_11 [ V_8 ? V_8 -> V_12 : 0 ] ;
const struct V_9 * V_13 [] = { & V_10 , NULL } ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
int V_21 ;
int V_22 ;
int V_23 ;
V_19 = F_4 ( V_2 , V_24 , 0 ) ;
if ( ! V_19 ) {
F_5 ( V_4 , L_1 ) ;
return - V_25 ;
}
V_20 = F_6 ( V_2 , 0 ) ;
if ( V_20 <= 0 ) {
F_5 ( V_4 , L_2 ) ;
return - V_25 ;
}
if ( V_6 && V_6 -> V_9 )
V_10 = * V_6 -> V_9 ;
V_15 = F_7 ( V_4 , sizeof( * V_15 ) , V_26 ) ;
if ( ! V_15 ) {
F_5 ( V_4 , L_3 ) ;
return - V_27 ;
}
V_15 -> V_28 |= ( unsigned long ) V_10 . V_29 ;
V_15 -> V_30 = F_8 ( V_4 , V_19 -> V_31 , F_9 ( V_19 ) ) ;
if ( ! V_15 -> V_30 ) {
F_5 ( V_4 , L_4 , V_19 ) ;
return - V_27 ;
}
V_15 -> V_32 = F_10 ( V_4 , NULL ) ;
if ( F_11 ( V_15 -> V_32 ) ) {
F_5 ( V_4 , L_5 ) ;
} else {
V_23 = F_12 ( V_15 -> V_32 ) ;
if ( V_23 ) {
F_5 ( V_4 , L_6 ) ;
goto V_33;
}
}
if ( V_6 && V_6 -> V_34 ) {
V_23 = V_6 -> V_34 ( V_4 , V_15 -> V_30 ) ;
if ( V_23 )
goto V_35;
}
F_13 ( V_4 , V_15 ,
V_6 ? V_6 -> V_36 : 0 ,
V_6 ? V_6 -> V_37 : 0 ) ;
if ( V_15 -> V_38 & V_39 )
V_10 . V_28 |= V_40 ;
if ( V_15 -> V_38 & V_41 )
V_10 . V_28 |= V_42 ;
F_14 ( V_15 , & V_10 ) ;
V_21 = F_15 ( F_16 ( V_15 -> V_38 ) , F_17 ( V_15 -> V_43 ) ) ;
V_17 = F_18 ( V_4 , V_13 , V_21 ) ;
if ( ! V_17 ) {
V_23 = - V_27 ;
goto V_44;
}
V_17 -> V_29 = V_15 ;
if ( ! ( V_15 -> V_38 & V_45 ) || V_46 )
V_17 -> V_28 |= V_47 ;
else
F_19 ( V_4 , L_7 ) ;
if ( V_10 . V_28 & V_48 )
F_20 ( V_17 ) ;
for ( V_22 = 0 ; V_22 < V_17 -> V_21 ; V_22 ++ ) {
struct V_49 * V_50 = V_17 -> V_51 [ V_22 ] ;
F_21 ( V_50 , L_8 , V_19 ) ;
F_21 ( V_50 , L_9 , 0x100 + V_50 -> V_52 * 0x80 ) ;
if ( V_50 -> V_28 & V_48 )
V_50 -> V_53 = V_15 -> V_54 ;
if ( ! ( V_15 -> V_43 & ( 1 << V_22 ) ) )
V_50 -> V_55 = & V_56 ;
}
V_23 = F_22 ( V_17 ) ;
if ( V_23 )
goto V_44;
F_23 ( V_17 ) ;
F_24 ( V_17 , L_10 ) ;
V_23 = F_25 ( V_17 , V_20 , V_57 , V_58 ,
& V_59 ) ;
if ( V_23 )
goto V_44;
return 0 ;
V_44:
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_4 ) ;
V_35:
if ( ! F_11 ( V_15 -> V_32 ) )
F_26 ( V_15 -> V_32 ) ;
V_33:
if ( ! F_11 ( V_15 -> V_32 ) )
F_27 ( V_15 -> V_32 ) ;
return V_23 ;
}
static void F_28 ( struct V_16 * V_17 )
{
struct V_3 * V_4 = V_17 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_14 * V_15 = V_17 -> V_29 ;
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_4 ) ;
if ( ! F_11 ( V_15 -> V_32 ) ) {
F_26 ( V_15 -> V_32 ) ;
F_27 ( V_15 -> V_32 ) ;
}
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_16 * V_17 = F_30 ( V_4 ) ;
struct V_14 * V_15 = V_17 -> V_29 ;
void T_1 * V_30 = V_15 -> V_30 ;
T_2 V_60 ;
int V_23 ;
if ( V_15 -> V_28 & V_61 ) {
F_5 ( V_4 , L_11 ) ;
return - V_62 ;
}
V_60 = F_31 ( V_30 + V_63 ) ;
V_60 &= ~ V_64 ;
F_32 ( V_60 , V_30 + V_63 ) ;
F_31 ( V_30 + V_63 ) ;
V_23 = F_33 ( V_17 , V_65 ) ;
if ( V_23 )
return V_23 ;
if ( V_6 && V_6 -> V_66 )
return V_6 -> V_66 ( V_4 ) ;
if ( ! F_11 ( V_15 -> V_32 ) )
F_26 ( V_15 -> V_32 ) ;
return 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_16 * V_17 = F_30 ( V_4 ) ;
struct V_14 * V_15 = V_17 -> V_29 ;
int V_23 ;
if ( ! F_11 ( V_15 -> V_32 ) ) {
V_23 = F_12 ( V_15 -> V_32 ) ;
if ( V_23 ) {
F_5 ( V_4 , L_6 ) ;
return V_23 ;
}
}
if ( V_6 && V_6 -> V_67 ) {
V_23 = V_6 -> V_67 ( V_4 ) ;
if ( V_23 )
goto V_35;
}
if ( V_4 -> V_68 . V_69 . V_70 == V_71 ) {
V_23 = F_22 ( V_17 ) ;
if ( V_23 )
goto V_35;
F_23 ( V_17 ) ;
}
F_35 ( V_17 ) ;
return 0 ;
V_35:
if ( ! F_11 ( V_15 -> V_32 ) )
F_26 ( V_15 -> V_32 ) ;
return V_23 ;
}
