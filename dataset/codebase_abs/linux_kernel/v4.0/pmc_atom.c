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
T_1 V_39 = F_1 ( V_2 , V_40 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_11 ( V_42 ) ; V_41 ++ ) {
F_12 ( V_16 , L_7 ,
V_42 [ V_41 ] . V_34 ,
V_42 [ V_41 ] . V_35 & V_39 ? L_8 : L_9 ) ;
}
return 0 ;
}
static int F_16 ( struct V_36 * V_36 , struct V_37 * V_37 )
{
return F_14 ( V_37 , F_15 , V_36 -> V_38 ) ;
}
static int F_17 ( struct V_15 * V_16 , void * V_17 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
T_3 V_43 , V_44 , V_45 , V_46 , V_47 ;
V_43 = ( T_3 ) F_1 ( V_2 , V_48 ) << V_49 ;
V_44 = ( T_3 ) F_1 ( V_2 , V_50 ) << V_49 ;
V_45 = ( T_3 ) F_1 ( V_2 , V_51 ) << V_49 ;
V_46 = ( T_3 ) F_1 ( V_2 , V_52 ) << V_49 ;
V_47 = ( T_3 ) F_1 ( V_2 , V_53 ) << V_49 ;
F_12 ( V_16 , L_10 , V_43 ) ;
F_12 ( V_16 , L_11 , V_44 ) ;
F_12 ( V_16 , L_12 , V_45 ) ;
F_12 ( V_16 , L_13 , V_46 ) ;
F_12 ( V_16 , L_14 , V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_36 * V_36 , struct V_37 * V_37 )
{
return F_14 ( V_37 , F_17 , V_36 -> V_38 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_54 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_57 * V_58 , * V_59 ;
V_58 = F_22 ( L_15 , NULL ) ;
if ( ! V_58 )
return - V_60 ;
V_2 -> V_54 = V_58 ;
V_59 = F_23 ( L_16 , V_61 | V_62 ,
V_58 , V_2 , & V_63 ) ;
if ( ! V_59 ) {
F_24 ( & V_56 -> V_64 , L_17 ) ;
goto V_65;
}
V_59 = F_23 ( L_18 , V_61 | V_62 ,
V_58 , V_2 , & V_66 ) ;
if ( ! V_59 ) {
F_24 ( & V_56 -> V_64 , L_19 ) ;
goto V_65;
}
V_59 = F_23 ( L_20 , V_61 | V_62 ,
V_58 , V_2 , & V_67 ) ;
if ( ! V_59 ) {
F_24 ( & V_56 -> V_64 , L_21 ) ;
goto V_65;
}
return 0 ;
V_65:
F_19 ( V_2 ) ;
return - V_68 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
return 0 ;
}
static int F_25 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = & V_69 ;
int V_70 ;
F_26 ( V_56 , V_71 , & V_8 ) ;
V_8 &= V_72 ;
if ( V_8 != 0 && V_73 == NULL )
V_73 = F_5 ;
F_26 ( V_56 , V_74 , & V_2 -> V_75 ) ;
V_2 -> V_75 &= V_76 ;
V_2 -> V_4 = F_27 ( V_2 -> V_75 , V_77 ) ;
if ( ! V_2 -> V_4 ) {
F_24 ( & V_56 -> V_64 , L_22 ) ;
return - V_60 ;
}
F_9 ( V_2 ) ;
V_70 = F_21 ( V_2 , V_56 ) ;
if ( V_70 ) {
F_28 ( V_2 -> V_4 ) ;
}
return V_70 ;
}
static int T_4 F_29 ( void )
{
struct V_55 * V_56 = NULL ;
const struct V_78 * V_79 ;
F_30 (pdev) {
V_79 = F_31 ( V_80 , V_56 ) ;
if ( V_79 )
return F_25 ( V_56 ) ;
}
return - V_68 ;
}
