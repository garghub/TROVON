static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( void )
{
T_2 V_6 ;
T_1 V_7 ;
F_6 ( L_1 ) ;
V_6 = V_8 + V_9 ;
V_7 = F_7 ( V_6 ) ;
V_7 &= V_10 ;
V_7 |= V_11 ;
V_7 |= V_12 ;
F_8 ( V_7 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_13 , ( T_1 ) V_14 ) ;
}
static int F_10 ( struct V_15 * V_16 , void * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_1 V_19 , V_20 , V_21 ;
T_1 V_22 , V_23 , V_24 ;
int V_25 , V_26 , V_27 ;
V_19 = F_1 ( V_2 , V_28 ) ;
V_20 = F_1 ( V_2 , V_29 ) ;
V_22 = F_1 ( V_2 , V_30 ) ;
V_23 = F_1 ( V_2 , V_31 ) ;
V_25 = F_11 ( V_32 ) ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
V_27 = V_26 / V_33 ;
if ( V_27 ) {
V_21 = V_20 ;
V_24 = V_23 ;
} else {
V_21 = V_19 ;
V_24 = V_22 ;
}
F_12 ( V_16 , L_2 ,
V_32 [ V_26 ] . V_34 ,
V_32 [ V_26 ] . V_35 & V_21 ?
L_3 : L_4 ,
V_32 [ V_26 ] . V_35 & V_24 ?
L_5 : L_6 ) ;
}
return 0 ;
}
static int F_13 ( struct V_36 * V_36 , struct V_37 * V_37 )
{
return F_14 ( V_37 , F_10 , V_36 -> V_38 ) ;
}
static int F_15 ( struct V_15 * V_16 , void * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_3 V_39 , V_40 , V_41 , V_42 , V_43 ;
V_39 = ( T_3 ) F_1 ( V_2 , V_44 ) << V_45 ;
V_40 = ( T_3 ) F_1 ( V_2 , V_46 ) << V_45 ;
V_41 = ( T_3 ) F_1 ( V_2 , V_47 ) << V_45 ;
V_42 = ( T_3 ) F_1 ( V_2 , V_48 ) << V_45 ;
V_43 = ( T_3 ) F_1 ( V_2 , V_49 ) << V_45 ;
F_12 ( V_16 , L_7 , V_39 ) ;
F_12 ( V_16 , L_8 , V_40 ) ;
F_12 ( V_16 , L_9 , V_41 ) ;
F_12 ( V_16 , L_10 , V_42 ) ;
F_12 ( V_16 , L_11 , V_43 ) ;
return 0 ;
}
static int F_16 ( struct V_36 * V_36 , struct V_37 * V_37 )
{
return F_14 ( V_37 , F_15 , V_36 -> V_38 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_50 )
return;
F_18 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
}
static int F_19 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
struct V_53 * V_54 , * V_55 ;
V_54 = F_20 ( L_12 , NULL ) ;
if ( ! V_54 )
return - V_56 ;
V_55 = F_21 ( L_13 , V_57 | V_58 ,
V_54 , V_2 , & V_59 ) ;
if ( ! V_55 ) {
F_22 ( & V_52 -> V_60 , L_14 ) ;
goto V_61;
}
V_55 = F_21 ( L_15 , V_57 | V_58 ,
V_54 , V_2 , & V_62 ) ;
if ( ! V_55 ) {
F_22 ( & V_52 -> V_60 , L_16 ) ;
goto V_61;
}
V_2 -> V_50 = V_54 ;
return 0 ;
V_61:
F_17 ( V_2 ) ;
return - V_63 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_51 * V_52 )
{
return 0 ;
}
static int F_23 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = & V_64 ;
int V_65 ;
F_24 ( V_52 , V_66 , & V_8 ) ;
V_8 &= V_67 ;
if ( V_8 != 0 && V_68 == NULL )
V_68 = F_5 ;
F_24 ( V_52 , V_69 , & V_2 -> V_70 ) ;
V_2 -> V_70 &= V_71 ;
V_2 -> V_4 = F_25 ( V_2 -> V_70 , V_72 ) ;
if ( ! V_2 -> V_4 ) {
F_22 ( & V_52 -> V_60 , L_17 ) ;
return - V_56 ;
}
F_9 ( V_2 ) ;
V_65 = F_19 ( V_2 , V_52 ) ;
if ( V_65 ) {
F_26 ( V_2 -> V_4 ) ;
}
return V_65 ;
}
static int T_4 F_27 ( void )
{
int V_61 = - V_63 ;
struct V_51 * V_52 = NULL ;
const struct V_73 * V_74 ;
F_28 (pdev) {
V_74 = F_29 ( V_75 , V_52 ) ;
if ( V_74 ) {
V_61 = F_23 ( V_52 ) ;
goto V_76;
}
}
V_76:
return V_61 ;
}
