static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_5 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_11 ;
V_11 = F_5 ( V_9 -> V_12 , V_13 ,
V_14 ,
F_6 ( V_15 ) ) ;
if ( V_11 )
F_7 ( V_9 -> V_7 , L_1 ) ;
V_11 = F_8 ( V_9 -> V_12 , V_16 ,
V_17 ) ;
if ( V_11 )
F_7 ( V_9 -> V_7 , L_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_11 ;
V_11 = F_5 ( V_9 -> V_12 , V_13 ,
V_14 ,
F_6 ( V_18 ) ) ;
if ( V_11 )
F_7 ( V_9 -> V_7 , L_2 ) ;
V_11 = F_8 ( V_9 -> V_12 , V_16 ,
V_17 ) ;
if ( V_11 )
F_7 ( V_9 -> V_7 , L_2 ) ;
}
static bool F_10 ( struct V_1 * V_2 ,
const struct V_19 * V_20 ,
struct V_19 * V_21 )
{
return true ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_19 * V_20 = & V_2 -> V_5 -> V_20 ;
unsigned int V_22 , V_23 , V_24 , V_25 , V_26 , V_27 , div , V_28 ;
unsigned long V_29 ;
int V_11 ;
V_28 = F_12 ( V_2 ) ;
V_29 = F_13 ( V_9 -> V_30 ) ;
div = V_29 / V_20 -> clock / 1000 ;
V_22 = V_20 -> V_31 - V_20 -> V_32 ;
V_23 = V_20 -> V_33 - V_20 -> V_34 ;
V_24 = V_20 -> V_32 - V_20 -> V_33 ;
V_25 = V_20 -> V_35 - V_20 -> V_36 ;
V_26 = V_20 -> V_37 - V_20 -> V_38 ;
V_27 = V_20 -> V_36 - V_20 -> V_37 ;
V_11 = F_8 ( V_9 -> V_12 , V_39 ,
F_14 ( V_22 ) |
F_15 ( V_24 ) |
F_16 ( V_23 ) ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_41 ,
F_17 ( V_25 ) |
F_18 ( V_27 ) |
F_19 ( V_26 ) ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_42 ,
F_20 ( V_20 -> V_38 ) |
F_21 ( V_20 -> V_34 ) ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_43 , div ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_44 ,
V_45 | V_46 ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_47 , F_22 ( 0 ) |
F_23 ( 0 ) | F_24 ( 0 ) ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_13 ,
F_25 ( 1 ) | V_48 ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_49 ,
F_26 ( V_50 ) |
F_27 ( V_51 ) |
F_28 ( V_52 ) ) ;
if ( V_11 )
goto V_40;
V_11 = F_8 ( V_9 -> V_12 , V_16 ,
V_17 ) ;
if ( V_11 )
goto V_40;
return;
V_40:
F_7 ( V_7 -> V_7 , L_3 ) ;
}
int F_29 ( struct V_8 * V_9 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 = & V_9 -> V_2 ;
unsigned int V_55 , V_56 , V_57 ;
int V_11 ;
V_54 = F_30 ( V_9 -> V_58 ) ;
V_11 = F_31 ( V_9 -> V_58 , V_2 , V_54 , NULL ,
& V_59 ) ;
if ( V_11 < 0 )
return V_11 ;
F_32 ( V_2 , & V_60 ) ;
if ( ! strcmp ( V_9 -> V_61 -> V_62 , L_4 ) )
V_57 = V_63 ;
else
V_57 = V_64 ;
for ( V_55 = 0 ; V_55 <= V_9 -> V_61 -> V_65 ; V_55 ++ ) {
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ ) {
V_11 = F_8 ( V_9 -> V_12 ,
F_33 ( V_55 , V_56 ) , 0 ) ;
if ( V_11 )
goto V_66;
}
}
V_11 = F_5 ( V_9 -> V_12 , V_13 ,
V_14 ,
F_6 ( V_15 ) ) ;
if ( V_11 )
goto V_66;
V_11 = F_8 ( V_9 -> V_12 , V_16 ,
V_17 ) ;
if ( V_11 )
goto V_66;
return 0 ;
V_66:
F_7 ( V_9 -> V_7 , L_5 ) ;
return V_11 ;
}
