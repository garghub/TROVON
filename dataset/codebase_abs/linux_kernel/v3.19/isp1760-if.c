static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_2 . V_7 ;
struct V_8 * V_9 ;
struct V_8 V_10 ;
int V_11 ;
T_1 V_12 ;
int V_13 ;
unsigned int V_14 = 0 ;
enum V_15 V_16 ;
T_2 V_17 = 0 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
V_13 = F_3 ( V_6 , 0 , & V_10 ) ;
if ( V_13 ) {
V_13 = - V_20 ;
goto V_21;
}
V_12 = F_4 ( & V_10 ) ;
V_9 = F_5 ( V_10 . V_22 , V_12 , F_6 ( & V_2 -> V_2 ) ) ;
if ( ! V_9 ) {
V_13 = - V_23 ;
goto V_21;
}
V_11 = F_7 ( V_6 , 0 ) ;
if ( ! V_11 ) {
V_13 = - V_24 ;
goto V_25;
}
if ( F_8 ( V_6 , L_1 ) )
V_14 |= V_26 ;
F_9 ( V_6 , L_2 , & V_17 ) ;
if ( V_17 == 16 )
V_14 |= V_27 ;
if ( F_10 ( V_6 , L_3 , NULL ) != NULL )
V_14 |= V_28 ;
if ( F_10 ( V_6 , L_4 , NULL ) != NULL )
V_14 |= V_29 ;
if ( F_10 ( V_6 , L_5 , NULL ) != NULL )
V_14 |= V_30 ;
if ( F_10 ( V_6 , L_6 , NULL ) != NULL )
V_14 |= V_31 ;
V_4 -> V_32 = F_11 ( V_6 , 0 , & V_16 ) ;
if ( F_12 ( V_4 -> V_32 ) ) {
V_13 = F_13 ( V_4 -> V_32 , F_6 ( & V_2 -> V_2 ) ) ;
if ( ! V_13 ) {
if ( ! ( V_16 & V_33 ) ) {
V_14 |= V_34 ;
F_14 ( V_4 -> V_32 , 0 ) ;
} else {
F_14 ( V_4 -> V_32 , 1 ) ;
}
} else {
V_4 -> V_32 = V_13 ;
}
}
V_4 -> V_35 = F_15 ( V_10 . V_22 , V_12 , V_11 ,
V_36 , V_4 -> V_32 ,
& V_2 -> V_2 , F_6 ( & V_2 -> V_2 ) ,
V_14 ) ;
if ( F_16 ( V_4 -> V_35 ) ) {
V_13 = F_17 ( V_4 -> V_35 ) ;
goto V_37;
}
F_18 ( V_2 , V_4 ) ;
return V_13 ;
V_37:
if ( F_12 ( V_4 -> V_32 ) )
F_19 ( V_4 -> V_32 ) ;
V_25:
F_20 ( V_10 . V_22 , V_12 ) ;
V_21:
F_21 ( V_4 ) ;
return V_13 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_23 ( V_2 ) ;
F_24 ( V_4 -> V_35 ) ;
F_25 ( V_4 -> V_35 -> V_38 ) ;
F_20 ( V_4 -> V_35 -> V_39 , V_4 -> V_35 -> V_40 ) ;
F_26 ( V_4 -> V_35 ) ;
if ( F_12 ( V_4 -> V_32 ) )
F_19 ( V_4 -> V_32 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
static int F_27 ( struct V_41 * V_2 ,
const struct V_42 * V_43 )
{
T_3 V_44 , V_45 ;
T_4 V_46 ;
int V_47 ;
struct V_48 * V_35 ;
unsigned int V_14 = 0 ;
int V_49 = 0 ;
T_1 V_50 ;
T_1 V_51 ;
T_3 T_5 * V_52 ;
T_3 T_5 * V_53 ;
T_1 V_54 ;
T_1 V_55 ;
if ( F_28 () )
return - V_24 ;
if ( F_29 ( V_2 ) < 0 )
return - V_24 ;
if ( ! V_2 -> V_56 )
return - V_24 ;
V_54 = F_30 ( V_2 , 0 ) ;
V_55 = F_31 ( V_2 , 0 ) ;
if ( ! F_5 ( V_54 , V_55 , L_7 ) ) {
F_32 ( V_57 L_8 ) ;
return - V_23 ;
}
V_53 = F_33 ( V_54 , V_55 ) ;
if ( ! V_53 ) {
F_32 ( V_57 L_9 ) ;
V_49 = - V_19 ;
goto V_58;
}
V_50 = F_30 ( V_2 , 3 ) ;
V_51 = F_31 ( V_2 , 3 ) ;
if ( V_51 < 0xffff ) {
F_32 ( V_57 L_10 ) ;
V_49 = - V_19 ;
goto V_59;
}
if ( ! F_5 ( V_50 , V_51 , L_11 ) ) {
F_32 ( V_57 L_12 ) ;
V_49 = - V_23 ;
goto V_59;
}
V_52 = F_33 ( V_50 , V_51 ) ;
if ( ! V_52 ) {
F_32 ( V_57 L_13 ) ;
V_49 = - V_19 ;
goto V_60;
}
F_34 ( V_2 , V_61 , & V_44 ) ;
if ( V_44 ) {
F_34 ( V_2 , V_62 , & V_45 ) ;
if ( V_45 && V_45 < V_44 )
F_35 ( V_2 , V_61 , V_45 ) ;
}
V_47 = 20 ;
V_46 = 0 ;
while ( ( V_46 != 0xFACE ) && V_47 ) {
F_36 ( 0xface , V_52 + V_63 ) ;
F_37 ( 100 ) ;
V_46 = F_38 ( V_52 + V_63 ) & 0x0000ffff ;
V_47 -- ;
}
F_25 ( V_52 ) ;
if ( V_46 != 0xFACE ) {
F_39 ( & V_2 -> V_2 , L_14 , V_46 ) ;
V_49 = - V_19 ;
goto V_60;
}
F_40 ( V_2 ) ;
#define F_41 0x68
V_46 = F_38 ( V_53 + F_41 ) ;
V_46 |= 0x900 ;
F_36 ( V_46 , V_53 + F_41 ) ;
V_2 -> V_2 . V_64 = NULL ;
V_35 = F_15 ( V_50 , V_51 , V_2 -> V_56 ,
V_36 , - V_65 , & V_2 -> V_2 , F_6 ( & V_2 -> V_2 ) ,
V_14 ) ;
if ( F_16 ( V_35 ) ) {
V_49 = - V_24 ;
goto V_60;
}
F_25 ( V_53 ) ;
F_20 ( V_54 , V_55 ) ;
F_42 ( V_2 , V_35 ) ;
return 0 ;
V_60:
F_20 ( V_50 , V_51 ) ;
V_59:
F_25 ( V_53 ) ;
V_58:
F_20 ( V_54 , V_55 ) ;
return V_49 ;
}
static void F_43 ( struct V_41 * V_2 )
{
struct V_48 * V_35 ;
V_35 = F_44 ( V_2 ) ;
F_24 ( V_35 ) ;
F_25 ( V_35 -> V_38 ) ;
F_20 ( V_35 -> V_39 , V_35 -> V_40 ) ;
F_26 ( V_35 ) ;
F_45 ( V_2 ) ;
}
static void F_46 ( struct V_41 * V_2 )
{
F_32 ( V_57 L_15 ) ;
}
static int F_47 ( struct V_1 * V_66 )
{
int V_13 = 0 ;
struct V_48 * V_35 ;
struct V_8 * V_67 ;
struct V_8 * V_68 ;
T_1 V_69 ;
struct V_70 * V_71 = F_48 ( & V_66 -> V_2 ) ;
unsigned int V_14 = 0 ;
unsigned long V_72 = V_36 ;
V_67 = F_49 ( V_66 , V_73 , 0 ) ;
if ( ! V_67 ) {
F_50 ( L_16 ) ;
V_13 = - V_24 ;
goto V_74;
}
V_69 = F_4 ( V_67 ) ;
if ( ! F_5 ( V_67 -> V_22 , V_69 , L_17 ) ) {
F_50 ( L_18 ) ;
V_13 = - V_23 ;
goto V_74;
}
V_68 = F_49 ( V_66 , V_75 , 0 ) ;
if ( ! V_68 ) {
F_50 ( L_19 ) ;
V_13 = - V_24 ;
goto V_76;
}
V_72 |= V_68 -> V_77 & V_78 ;
if ( V_71 ) {
if ( V_71 -> V_79 )
V_14 |= V_26 ;
if ( V_71 -> V_80 )
V_14 |= V_27 ;
if ( V_71 -> V_81 )
V_14 |= V_28 ;
if ( V_71 -> V_82 )
V_14 |= V_29 ;
if ( V_71 -> V_83 )
V_14 |= V_30 ;
if ( V_71 -> V_84 )
V_14 |= V_31 ;
}
V_35 = F_15 ( V_67 -> V_22 , V_69 , V_68 -> V_22 ,
V_72 , - V_65 ,
& V_66 -> V_2 , F_6 ( & V_66 -> V_2 ) , V_14 ) ;
F_18 ( V_66 , V_35 ) ;
if ( F_16 ( V_35 ) ) {
F_50 ( L_20 ) ;
V_13 = - V_24 ;
goto V_76;
}
F_51 ( L_21 ) ;
return V_13 ;
V_76:
F_20 ( V_67 -> V_22 , V_69 ) ;
V_74:
return V_13 ;
}
static int F_52 ( struct V_1 * V_66 )
{
struct V_8 * V_67 ;
T_1 V_69 ;
struct V_48 * V_35 = F_23 ( V_66 ) ;
F_24 ( V_35 ) ;
V_67 = F_49 ( V_66 , V_73 , 0 ) ;
V_69 = F_4 ( V_67 ) ;
F_20 ( V_67 -> V_22 , V_69 ) ;
F_26 ( V_35 ) ;
return 0 ;
}
static int T_6 F_53 ( void )
{
int V_13 , V_85 = - V_24 ;
F_54 () ;
V_13 = F_55 ( & V_86 ) ;
if ( ! V_13 )
V_85 = 0 ;
#if F_56 ( V_87 ) && F_56 ( V_88 )
V_13 = F_55 ( & V_89 ) ;
if ( ! V_13 )
V_85 = 0 ;
#endif
#ifdef F_57
V_13 = F_58 ( & V_90 ) ;
if ( ! V_13 )
V_85 = 0 ;
#endif
if ( V_85 )
F_59 () ;
return V_85 ;
}
static void T_7 F_60 ( void )
{
F_61 ( & V_86 ) ;
#if F_56 ( V_87 ) && F_56 ( V_88 )
F_61 ( & V_89 ) ;
#endif
#ifdef F_57
F_62 ( & V_90 ) ;
#endif
F_59 () ;
}
