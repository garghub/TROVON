static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_2 . V_7 ;
struct V_8 * V_9 ;
struct V_8 V_10 ;
struct V_11 V_12 ;
int V_13 ;
T_1 V_14 ;
int V_15 ;
const unsigned int * V_16 ;
unsigned int V_17 = 0 ;
V_15 = F_2 ( V_6 , 0 , & V_10 ) ;
if ( V_15 )
return - V_18 ;
V_14 = F_3 ( & V_10 ) ;
V_9 = F_4 ( V_10 . V_19 , V_14 , F_5 ( & V_2 -> V_2 ) ) ;
if ( ! V_9 )
return - V_20 ;
if ( F_6 ( V_6 , 0 , & V_12 ) ) {
V_15 = - V_21 ;
goto V_22;
}
V_13 = F_7 ( V_12 . V_23 , V_12 . V_24 ,
V_12 . V_25 ) ;
if ( F_8 ( V_6 , L_1 ) )
V_17 |= V_26 ;
V_16 = F_9 ( V_6 , L_2 , NULL ) ;
if ( V_16 && * V_16 == 16 )
V_17 |= V_27 ;
if ( F_9 ( V_6 , L_3 , NULL ) != NULL )
V_17 |= V_28 ;
if ( F_9 ( V_6 , L_4 , NULL ) != NULL )
V_17 |= V_29 ;
if ( F_9 ( V_6 , L_5 , NULL ) != NULL )
V_17 |= V_30 ;
if ( F_9 ( V_6 , L_6 , NULL ) != NULL )
V_17 |= V_31 ;
V_4 = F_10 ( V_10 . V_19 , V_14 , V_13 ,
V_32 | V_33 , & V_2 -> V_2 , F_5 ( & V_2 -> V_2 ) ,
V_17 ) ;
if ( F_11 ( V_4 ) ) {
V_15 = F_12 ( V_4 ) ;
goto V_22;
}
F_13 ( & V_2 -> V_2 , V_4 ) ;
return V_15 ;
V_22:
F_14 ( V_10 . V_19 , V_14 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_16 ( & V_2 -> V_2 ) ;
F_13 ( & V_2 -> V_2 , NULL ) ;
F_17 ( V_4 ) ;
F_18 ( V_4 -> V_34 ) ;
F_14 ( V_4 -> V_35 , V_4 -> V_36 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int T_2 F_20 ( struct V_37 * V_2 ,
const struct V_38 * V_39 )
{
T_3 V_40 , V_41 ;
T_4 V_42 ;
int V_43 ;
struct V_3 * V_4 ;
unsigned int V_17 = 0 ;
int V_44 = 0 ;
T_1 V_45 ;
T_1 V_46 ;
T_3 T_5 * V_47 ;
T_3 T_5 * V_48 ;
T_1 V_49 ;
T_1 V_50 ;
if ( F_21 () )
return - V_21 ;
if ( F_22 ( V_2 ) < 0 )
return - V_21 ;
if ( ! V_2 -> V_51 )
return - V_21 ;
V_49 = F_23 ( V_2 , 0 ) ;
V_50 = F_24 ( V_2 , 0 ) ;
if ( ! F_4 ( V_49 , V_50 , L_7 ) ) {
F_25 ( V_52 L_8 ) ;
return - V_20 ;
}
V_48 = F_26 ( V_49 , V_50 ) ;
if ( ! V_48 ) {
F_25 ( V_52 L_9 ) ;
V_44 = - V_53 ;
goto V_54;
}
V_45 = F_23 ( V_2 , 3 ) ;
V_46 = F_24 ( V_2 , 3 ) ;
if ( V_46 < 0xffff ) {
F_25 ( V_52 L_10 ) ;
V_44 = - V_53 ;
goto V_55;
}
if ( ! F_4 ( V_45 , V_46 , L_11 ) ) {
F_25 ( V_52 L_12 ) ;
V_44 = - V_20 ;
goto V_55;
}
V_47 = F_26 ( V_45 , V_46 ) ;
if ( ! V_47 ) {
F_25 ( V_52 L_13 ) ;
V_44 = - V_53 ;
goto V_56;
}
F_27 ( V_2 , V_57 , & V_40 ) ;
if ( V_40 ) {
F_27 ( V_2 , V_58 , & V_41 ) ;
if ( V_41 && V_41 < V_40 )
F_28 ( V_2 , V_57 , V_41 ) ;
}
V_43 = 20 ;
V_42 = 0 ;
while ( ( V_42 != 0xFACE ) && V_43 ) {
F_29 ( 0xface , V_47 + V_59 ) ;
F_30 ( 100 ) ;
V_42 = F_31 ( V_47 + V_59 ) & 0x0000ffff ;
V_43 -- ;
}
F_18 ( V_47 ) ;
if ( V_42 != 0xFACE ) {
F_32 ( & V_2 -> V_2 , L_14 , V_42 ) ;
V_44 = - V_53 ;
goto V_56;
}
F_33 ( V_2 ) ;
#define F_34 0x68
V_42 = F_31 ( V_48 + F_34 ) ;
V_42 |= 0x900 ;
F_29 ( V_42 , V_48 + F_34 ) ;
V_2 -> V_2 . V_60 = NULL ;
V_4 = F_10 ( V_45 , V_46 , V_2 -> V_51 ,
V_32 | V_33 , & V_2 -> V_2 , F_5 ( & V_2 -> V_2 ) ,
V_17 ) ;
if ( F_11 ( V_4 ) ) {
V_44 = - V_21 ;
goto V_56;
}
F_18 ( V_48 ) ;
F_14 ( V_49 , V_50 ) ;
F_35 ( V_2 , V_4 ) ;
return 0 ;
V_56:
F_14 ( V_45 , V_46 ) ;
V_55:
F_18 ( V_48 ) ;
V_54:
F_14 ( V_49 , V_50 ) ;
return V_44 ;
}
static void F_36 ( struct V_37 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_37 ( V_2 ) ;
F_17 ( V_4 ) ;
F_18 ( V_4 -> V_34 ) ;
F_14 ( V_4 -> V_35 , V_4 -> V_36 ) ;
F_19 ( V_4 ) ;
F_38 ( V_2 ) ;
}
static void F_39 ( struct V_37 * V_2 )
{
F_25 ( V_52 L_15 ) ;
}
static int T_2 F_40 ( struct V_1 * V_61 )
{
int V_15 = 0 ;
struct V_3 * V_4 ;
struct V_8 * V_62 ;
struct V_8 * V_63 ;
T_1 V_64 ;
struct V_65 * V_66 = V_61 -> V_2 . V_67 ;
unsigned int V_17 = 0 ;
unsigned long V_68 = V_32 | V_33 ;
V_62 = F_41 ( V_61 , V_69 , 0 ) ;
if ( ! V_62 ) {
F_42 ( L_16 ) ;
V_15 = - V_21 ;
goto V_70;
}
V_64 = F_3 ( V_62 ) ;
if ( ! F_4 ( V_62 -> V_19 , V_64 , L_17 ) ) {
F_42 ( L_18 ) ;
V_15 = - V_20 ;
goto V_70;
}
V_63 = F_41 ( V_61 , V_71 , 0 ) ;
if ( ! V_63 ) {
F_42 ( L_19 ) ;
return - V_21 ;
}
V_68 |= V_63 -> V_72 & V_73 ;
if ( V_66 ) {
if ( V_66 -> V_74 )
V_17 |= V_26 ;
if ( V_66 -> V_75 )
V_17 |= V_27 ;
if ( V_66 -> V_76 )
V_17 |= V_28 ;
if ( V_66 -> V_77 )
V_17 |= V_29 ;
if ( V_66 -> V_78 )
V_17 |= V_30 ;
if ( V_66 -> V_79 )
V_17 |= V_31 ;
}
V_4 = F_10 ( V_62 -> V_19 , V_64 , V_63 -> V_19 ,
V_68 , & V_61 -> V_2 , F_5 ( & V_61 -> V_2 ) , V_17 ) ;
if ( F_11 ( V_4 ) ) {
F_42 ( L_20 ) ;
V_15 = - V_21 ;
goto V_80;
}
F_43 ( L_21 ) ;
return V_15 ;
V_80:
F_14 ( V_62 -> V_19 , V_64 ) ;
V_70:
return V_15 ;
}
static int T_6 F_44 ( struct V_1 * V_61 )
{
struct V_8 * V_62 ;
T_1 V_64 ;
V_62 = F_41 ( V_61 , V_69 , 0 ) ;
V_64 = F_3 ( V_62 ) ;
F_14 ( V_62 -> V_19 , V_64 ) ;
return 0 ;
}
static int T_7 F_45 ( void )
{
int V_15 , V_81 = - V_21 ;
F_46 () ;
V_15 = F_47 ( & V_82 ) ;
if ( ! V_15 )
V_81 = 0 ;
#ifdef F_48
V_15 = F_47 ( & V_83 ) ;
if ( ! V_15 )
V_81 = 0 ;
#endif
#ifdef F_49
V_15 = F_50 ( & V_84 ) ;
if ( ! V_15 )
V_81 = 0 ;
#endif
if ( V_81 )
F_51 () ;
return V_81 ;
}
static void T_8 F_52 ( void )
{
F_53 ( & V_82 ) ;
#ifdef F_48
F_53 ( & V_83 ) ;
#endif
#ifdef F_49
F_54 ( & V_84 ) ;
#endif
F_51 () ;
}
