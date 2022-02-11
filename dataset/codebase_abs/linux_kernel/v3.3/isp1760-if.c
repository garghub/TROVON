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
unsigned int V_16 = 0 ;
enum V_17 V_18 ;
T_2 V_19 = 0 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_15 = F_3 ( V_6 , 0 , & V_10 ) ;
if ( V_15 ) {
V_15 = - V_22 ;
goto V_23;
}
V_14 = F_4 ( & V_10 ) ;
V_9 = F_5 ( V_10 . V_24 , V_14 , F_6 ( & V_2 -> V_2 ) ) ;
if ( ! V_9 ) {
V_15 = - V_25 ;
goto V_23;
}
if ( F_7 ( V_6 , 0 , & V_12 ) ) {
V_15 = - V_26 ;
goto V_27;
}
V_13 = F_8 ( V_12 . V_28 , V_12 . V_29 ,
V_12 . V_30 ) ;
if ( F_9 ( V_6 , L_1 ) )
V_16 |= V_31 ;
F_10 ( V_6 , L_2 , & V_19 ) ;
if ( V_19 == 16 )
V_16 |= V_32 ;
if ( F_11 ( V_6 , L_3 , NULL ) != NULL )
V_16 |= V_33 ;
if ( F_11 ( V_6 , L_4 , NULL ) != NULL )
V_16 |= V_34 ;
if ( F_11 ( V_6 , L_5 , NULL ) != NULL )
V_16 |= V_35 ;
if ( F_11 ( V_6 , L_6 , NULL ) != NULL )
V_16 |= V_36 ;
V_4 -> V_37 = F_12 ( V_6 , 0 , & V_18 ) ;
if ( F_13 ( V_4 -> V_37 ) ) {
V_15 = F_14 ( V_4 -> V_37 , F_6 ( & V_2 -> V_2 ) ) ;
if ( ! V_15 ) {
if ( ! ( V_18 & V_38 ) ) {
V_16 |= V_39 ;
F_15 ( V_4 -> V_37 , 0 ) ;
} else {
F_15 ( V_4 -> V_37 , 1 ) ;
}
} else {
V_4 -> V_37 = V_15 ;
}
}
V_4 -> V_40 = F_16 ( V_10 . V_24 , V_14 , V_13 ,
V_41 , V_4 -> V_37 ,
& V_2 -> V_2 , F_6 ( & V_2 -> V_2 ) ,
V_16 ) ;
if ( F_17 ( V_4 -> V_40 ) ) {
V_15 = F_18 ( V_4 -> V_40 ) ;
goto V_42;
}
F_19 ( & V_2 -> V_2 , V_4 ) ;
return V_15 ;
V_42:
if ( F_13 ( V_4 -> V_37 ) )
F_20 ( V_4 -> V_37 ) ;
V_27:
F_21 ( V_10 . V_24 , V_14 ) ;
V_23:
F_22 ( V_4 ) ;
return V_15 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_24 ( & V_2 -> V_2 ) ;
F_19 ( & V_2 -> V_2 , NULL ) ;
F_25 ( V_4 -> V_40 ) ;
F_26 ( V_4 -> V_40 -> V_43 ) ;
F_21 ( V_4 -> V_40 -> V_44 , V_4 -> V_40 -> V_45 ) ;
F_27 ( V_4 -> V_40 ) ;
if ( F_13 ( V_4 -> V_37 ) )
F_20 ( V_4 -> V_37 ) ;
F_22 ( V_4 ) ;
return 0 ;
}
static int T_3 F_28 ( struct V_46 * V_2 ,
const struct V_47 * V_48 )
{
T_4 V_49 , V_50 ;
T_5 V_51 ;
int V_52 ;
struct V_53 * V_40 ;
unsigned int V_16 = 0 ;
int V_54 = 0 ;
T_1 V_55 ;
T_1 V_56 ;
T_4 T_6 * V_57 ;
T_4 T_6 * V_58 ;
T_1 V_59 ;
T_1 V_60 ;
if ( F_29 () )
return - V_26 ;
if ( F_30 ( V_2 ) < 0 )
return - V_26 ;
if ( ! V_2 -> V_61 )
return - V_26 ;
V_59 = F_31 ( V_2 , 0 ) ;
V_60 = F_32 ( V_2 , 0 ) ;
if ( ! F_5 ( V_59 , V_60 , L_7 ) ) {
F_33 ( V_62 L_8 ) ;
return - V_25 ;
}
V_58 = F_34 ( V_59 , V_60 ) ;
if ( ! V_58 ) {
F_33 ( V_62 L_9 ) ;
V_54 = - V_21 ;
goto V_63;
}
V_55 = F_31 ( V_2 , 3 ) ;
V_56 = F_32 ( V_2 , 3 ) ;
if ( V_56 < 0xffff ) {
F_33 ( V_62 L_10 ) ;
V_54 = - V_21 ;
goto V_64;
}
if ( ! F_5 ( V_55 , V_56 , L_11 ) ) {
F_33 ( V_62 L_12 ) ;
V_54 = - V_25 ;
goto V_64;
}
V_57 = F_34 ( V_55 , V_56 ) ;
if ( ! V_57 ) {
F_33 ( V_62 L_13 ) ;
V_54 = - V_21 ;
goto V_65;
}
F_35 ( V_2 , V_66 , & V_49 ) ;
if ( V_49 ) {
F_35 ( V_2 , V_67 , & V_50 ) ;
if ( V_50 && V_50 < V_49 )
F_36 ( V_2 , V_66 , V_50 ) ;
}
V_52 = 20 ;
V_51 = 0 ;
while ( ( V_51 != 0xFACE ) && V_52 ) {
F_37 ( 0xface , V_57 + V_68 ) ;
F_38 ( 100 ) ;
V_51 = F_39 ( V_57 + V_68 ) & 0x0000ffff ;
V_52 -- ;
}
F_26 ( V_57 ) ;
if ( V_51 != 0xFACE ) {
F_40 ( & V_2 -> V_2 , L_14 , V_51 ) ;
V_54 = - V_21 ;
goto V_65;
}
F_41 ( V_2 ) ;
#define F_42 0x68
V_51 = F_39 ( V_58 + F_42 ) ;
V_51 |= 0x900 ;
F_37 ( V_51 , V_58 + F_42 ) ;
V_2 -> V_2 . V_69 = NULL ;
V_40 = F_16 ( V_55 , V_56 , V_2 -> V_61 ,
V_41 , - V_70 , & V_2 -> V_2 , F_6 ( & V_2 -> V_2 ) ,
V_16 ) ;
if ( F_17 ( V_40 ) ) {
V_54 = - V_26 ;
goto V_65;
}
F_26 ( V_58 ) ;
F_21 ( V_59 , V_60 ) ;
F_43 ( V_2 , V_40 ) ;
return 0 ;
V_65:
F_21 ( V_55 , V_56 ) ;
V_64:
F_26 ( V_58 ) ;
V_63:
F_21 ( V_59 , V_60 ) ;
return V_54 ;
}
static void F_44 ( struct V_46 * V_2 )
{
struct V_53 * V_40 ;
V_40 = F_45 ( V_2 ) ;
F_25 ( V_40 ) ;
F_26 ( V_40 -> V_43 ) ;
F_21 ( V_40 -> V_44 , V_40 -> V_45 ) ;
F_27 ( V_40 ) ;
F_46 ( V_2 ) ;
}
static void F_47 ( struct V_46 * V_2 )
{
F_33 ( V_62 L_15 ) ;
}
static int T_3 F_48 ( struct V_1 * V_71 )
{
int V_15 = 0 ;
struct V_53 * V_40 ;
struct V_8 * V_72 ;
struct V_8 * V_73 ;
T_1 V_74 ;
struct V_75 * V_76 = V_71 -> V_2 . V_77 ;
unsigned int V_16 = 0 ;
unsigned long V_78 = V_41 ;
V_72 = F_49 ( V_71 , V_79 , 0 ) ;
if ( ! V_72 ) {
F_50 ( L_16 ) ;
V_15 = - V_26 ;
goto V_80;
}
V_74 = F_4 ( V_72 ) ;
if ( ! F_5 ( V_72 -> V_24 , V_74 , L_17 ) ) {
F_50 ( L_18 ) ;
V_15 = - V_25 ;
goto V_80;
}
V_73 = F_49 ( V_71 , V_81 , 0 ) ;
if ( ! V_73 ) {
F_50 ( L_19 ) ;
return - V_26 ;
}
V_78 |= V_73 -> V_82 & V_83 ;
if ( V_76 ) {
if ( V_76 -> V_84 )
V_16 |= V_31 ;
if ( V_76 -> V_85 )
V_16 |= V_32 ;
if ( V_76 -> V_86 )
V_16 |= V_33 ;
if ( V_76 -> V_87 )
V_16 |= V_34 ;
if ( V_76 -> V_88 )
V_16 |= V_35 ;
if ( V_76 -> V_89 )
V_16 |= V_36 ;
}
V_40 = F_16 ( V_72 -> V_24 , V_74 , V_73 -> V_24 ,
V_78 , - V_70 ,
& V_71 -> V_2 , F_6 ( & V_71 -> V_2 ) , V_16 ) ;
if ( F_17 ( V_40 ) ) {
F_50 ( L_20 ) ;
V_15 = - V_26 ;
goto V_90;
}
F_51 ( L_21 ) ;
return V_15 ;
V_90:
F_21 ( V_72 -> V_24 , V_74 ) ;
V_80:
return V_15 ;
}
static int T_7 F_52 ( struct V_1 * V_71 )
{
struct V_8 * V_72 ;
T_1 V_74 ;
V_72 = F_49 ( V_71 , V_79 , 0 ) ;
V_74 = F_4 ( V_72 ) ;
F_21 ( V_72 -> V_24 , V_74 ) ;
return 0 ;
}
static int T_8 F_53 ( void )
{
int V_15 , V_91 = - V_26 ;
F_54 () ;
V_15 = F_55 ( & V_92 ) ;
if ( ! V_15 )
V_91 = 0 ;
#if F_56 ( V_93 ) && F_56 ( V_94 )
V_15 = F_55 ( & V_95 ) ;
if ( ! V_15 )
V_91 = 0 ;
#endif
#ifdef F_57
V_15 = F_58 ( & V_96 ) ;
if ( ! V_15 )
V_91 = 0 ;
#endif
if ( V_91 )
F_59 () ;
return V_91 ;
}
static void T_9 F_60 ( void )
{
F_61 ( & V_92 ) ;
#if F_56 ( V_93 ) && F_56 ( V_94 )
F_61 ( & V_95 ) ;
#endif
#ifdef F_57
F_62 ( & V_96 ) ;
#endif
F_59 () ;
}
