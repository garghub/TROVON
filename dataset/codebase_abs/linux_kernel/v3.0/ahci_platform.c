static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_9 = {
. V_10 = V_11 ,
. V_12 = V_13 ,
. V_14 = V_15 ,
. V_16 = & V_17 ,
} ;
const struct V_8 * V_18 [] = { & V_9 , NULL } ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
V_24 = F_2 ( V_2 , V_29 , 0 ) ;
if ( ! V_24 ) {
F_3 ( V_4 , L_1 ) ;
return - V_30 ;
}
V_25 = F_4 ( V_2 , 0 ) ;
if ( V_25 <= 0 ) {
F_3 ( V_4 , L_2 ) ;
return - V_30 ;
}
if ( V_6 && V_6 -> V_8 )
V_9 = * V_6 -> V_8 ;
V_20 = F_5 ( V_4 , sizeof( * V_20 ) , V_31 ) ;
if ( ! V_20 ) {
F_3 ( V_4 , L_3 ) ;
return - V_32 ;
}
V_20 -> V_10 |= ( unsigned long ) V_9 . V_33 ;
V_20 -> V_34 = F_6 ( V_4 , V_24 -> V_35 , F_7 ( V_24 ) ) ;
if ( ! V_20 -> V_34 ) {
F_3 ( V_4 , L_4 , V_24 ) ;
return - V_32 ;
}
if ( V_6 && V_6 -> V_36 ) {
V_28 = V_6 -> V_36 ( V_4 , V_20 -> V_34 ) ;
if ( V_28 )
return V_28 ;
}
F_8 ( V_4 , V_20 ,
V_6 ? V_6 -> V_37 : 0 ,
V_6 ? V_6 -> V_38 : 0 ) ;
if ( V_20 -> V_39 & V_40 )
V_9 . V_10 |= V_41 ;
if ( V_20 -> V_39 & V_42 )
V_9 . V_10 |= V_43 ;
F_9 ( V_20 , & V_9 ) ;
V_26 = F_10 ( F_11 ( V_20 -> V_39 ) , F_12 ( V_20 -> V_44 ) ) ;
V_22 = F_13 ( V_4 , V_18 , V_26 ) ;
if ( ! V_22 ) {
V_28 = - V_32 ;
goto V_45;
}
V_22 -> V_33 = V_20 ;
if ( ! ( V_20 -> V_39 & V_46 ) || V_47 )
V_22 -> V_10 |= V_48 ;
else
F_14 ( V_49 L_5 ) ;
if ( V_9 . V_10 & V_50 )
F_15 ( V_22 ) ;
for ( V_27 = 0 ; V_27 < V_22 -> V_26 ; V_27 ++ ) {
struct V_51 * V_52 = V_22 -> V_53 [ V_27 ] ;
F_16 ( V_52 , L_6 , V_24 ) ;
F_16 ( V_52 , L_7 , 0x100 + V_52 -> V_54 * 0x80 ) ;
if ( V_52 -> V_10 & V_50 )
V_52 -> V_55 = V_20 -> V_56 ;
if ( ! ( V_20 -> V_44 & ( 1 << V_27 ) ) )
V_52 -> V_57 = & V_58 ;
}
V_28 = F_17 ( V_22 ) ;
if ( V_28 )
goto V_45;
F_18 ( V_22 ) ;
F_19 ( V_22 , L_8 ) ;
V_28 = F_20 ( V_22 , V_25 , V_59 , V_60 ,
& V_61 ) ;
if ( V_28 )
goto V_45;
return 0 ;
V_45:
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_4 ) ;
return V_28 ;
}
static int T_2 F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_21 * V_22 = F_22 ( V_4 ) ;
F_23 ( V_22 ) ;
if ( V_6 && V_6 -> exit )
V_6 -> exit ( V_4 ) ;
return 0 ;
}
static int T_1 F_24 ( void )
{
return F_25 ( & V_62 , F_1 ) ;
}
static void T_3 F_26 ( void )
{
F_27 ( & V_62 ) ;
}
