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
enum V_18 V_19 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_15 = F_3 ( V_6 , 0 , & V_10 ) ;
if ( V_15 )
return - V_22 ;
V_14 = F_4 ( & V_10 ) ;
V_9 = F_5 ( V_10 . V_23 , V_14 , F_6 ( & V_2 -> V_2 ) ) ;
if ( ! V_9 )
return - V_24 ;
if ( F_7 ( V_6 , 0 , & V_12 ) ) {
V_15 = - V_25 ;
goto V_26;
}
V_13 = F_8 ( V_12 . V_27 , V_12 . V_28 ,
V_12 . V_29 ) ;
if ( F_9 ( V_6 , L_1 ) )
V_17 |= V_30 ;
V_16 = F_10 ( V_6 , L_2 , NULL ) ;
if ( V_16 && * V_16 == 16 )
V_17 |= V_31 ;
if ( F_10 ( V_6 , L_3 , NULL ) != NULL )
V_17 |= V_32 ;
if ( F_10 ( V_6 , L_4 , NULL ) != NULL )
V_17 |= V_33 ;
if ( F_10 ( V_6 , L_5 , NULL ) != NULL )
V_17 |= V_34 ;
if ( F_10 ( V_6 , L_6 , NULL ) != NULL )
V_17 |= V_35 ;
V_4 -> V_36 = F_11 ( V_6 , 0 , & V_19 ) ;
if ( F_12 ( V_4 -> V_36 ) ) {
V_15 = F_13 ( V_4 -> V_36 , F_6 ( & V_2 -> V_2 ) ) ;
if ( ! V_15 ) {
if ( ! ( V_19 & V_37 ) ) {
V_17 |= V_38 ;
F_14 ( V_4 -> V_36 , 0 ) ;
} else {
F_14 ( V_4 -> V_36 , 1 ) ;
}
} else {
V_4 -> V_36 = V_15 ;
}
}
V_4 -> V_39 = F_15 ( V_10 . V_23 , V_14 , V_13 ,
V_40 , V_4 -> V_36 ,
& V_2 -> V_2 , F_6 ( & V_2 -> V_2 ) ,
V_17 ) ;
if ( F_16 ( V_4 -> V_39 ) ) {
V_15 = F_17 ( V_4 -> V_39 ) ;
goto V_41;
}
F_18 ( & V_2 -> V_2 , V_4 ) ;
return V_15 ;
V_41:
if ( F_12 ( V_4 -> V_36 ) )
F_19 ( V_4 -> V_36 ) ;
V_26:
F_20 ( V_10 . V_23 , V_14 ) ;
F_21 ( V_4 ) ;
return V_15 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_23 ( & V_2 -> V_2 ) ;
F_18 ( & V_2 -> V_2 , NULL ) ;
F_24 ( V_4 -> V_39 ) ;
F_25 ( V_4 -> V_39 -> V_42 ) ;
F_20 ( V_4 -> V_39 -> V_43 , V_4 -> V_39 -> V_44 ) ;
F_26 ( V_4 -> V_39 ) ;
if ( F_12 ( V_4 -> V_36 ) )
F_19 ( V_4 -> V_36 ) ;
F_21 ( V_4 ) ;
return 0 ;
}
static int T_2 F_27 ( struct V_45 * V_2 ,
const struct V_46 * V_47 )
{
T_3 V_48 , V_49 ;
T_4 V_50 ;
int V_51 ;
struct V_52 * V_39 ;
unsigned int V_17 = 0 ;
int V_53 = 0 ;
T_1 V_54 ;
T_1 V_55 ;
T_3 T_5 * V_56 ;
T_3 T_5 * V_57 ;
T_1 V_58 ;
T_1 V_59 ;
if ( F_28 () )
return - V_25 ;
if ( F_29 ( V_2 ) < 0 )
return - V_25 ;
if ( ! V_2 -> V_60 )
return - V_25 ;
V_58 = F_30 ( V_2 , 0 ) ;
V_59 = F_31 ( V_2 , 0 ) ;
if ( ! F_5 ( V_58 , V_59 , L_7 ) ) {
F_32 ( V_61 L_8 ) ;
return - V_24 ;
}
V_57 = F_33 ( V_58 , V_59 ) ;
if ( ! V_57 ) {
F_32 ( V_61 L_9 ) ;
V_53 = - V_21 ;
goto V_62;
}
V_54 = F_30 ( V_2 , 3 ) ;
V_55 = F_31 ( V_2 , 3 ) ;
if ( V_55 < 0xffff ) {
F_32 ( V_61 L_10 ) ;
V_53 = - V_21 ;
goto V_63;
}
if ( ! F_5 ( V_54 , V_55 , L_11 ) ) {
F_32 ( V_61 L_12 ) ;
V_53 = - V_24 ;
goto V_63;
}
V_56 = F_33 ( V_54 , V_55 ) ;
if ( ! V_56 ) {
F_32 ( V_61 L_13 ) ;
V_53 = - V_21 ;
goto V_64;
}
F_34 ( V_2 , V_65 , & V_48 ) ;
if ( V_48 ) {
F_34 ( V_2 , V_66 , & V_49 ) ;
if ( V_49 && V_49 < V_48 )
F_35 ( V_2 , V_65 , V_49 ) ;
}
V_51 = 20 ;
V_50 = 0 ;
while ( ( V_50 != 0xFACE ) && V_51 ) {
F_36 ( 0xface , V_56 + V_67 ) ;
F_37 ( 100 ) ;
V_50 = F_38 ( V_56 + V_67 ) & 0x0000ffff ;
V_51 -- ;
}
F_25 ( V_56 ) ;
if ( V_50 != 0xFACE ) {
F_39 ( & V_2 -> V_2 , L_14 , V_50 ) ;
V_53 = - V_21 ;
goto V_64;
}
F_40 ( V_2 ) ;
#define F_41 0x68
V_50 = F_38 ( V_57 + F_41 ) ;
V_50 |= 0x900 ;
F_36 ( V_50 , V_57 + F_41 ) ;
V_2 -> V_2 . V_68 = NULL ;
V_39 = F_15 ( V_54 , V_55 , V_2 -> V_60 ,
V_40 , - V_69 , & V_2 -> V_2 , F_6 ( & V_2 -> V_2 ) ,
V_17 ) ;
if ( F_16 ( V_39 ) ) {
V_53 = - V_25 ;
goto V_64;
}
F_25 ( V_57 ) ;
F_20 ( V_58 , V_59 ) ;
F_42 ( V_2 , V_39 ) ;
return 0 ;
V_64:
F_20 ( V_54 , V_55 ) ;
V_63:
F_25 ( V_57 ) ;
V_62:
F_20 ( V_58 , V_59 ) ;
return V_53 ;
}
static void F_43 ( struct V_45 * V_2 )
{
struct V_52 * V_39 ;
V_39 = F_44 ( V_2 ) ;
F_24 ( V_39 ) ;
F_25 ( V_39 -> V_42 ) ;
F_20 ( V_39 -> V_43 , V_39 -> V_44 ) ;
F_26 ( V_39 ) ;
F_45 ( V_2 ) ;
}
static void F_46 ( struct V_45 * V_2 )
{
F_32 ( V_61 L_15 ) ;
}
static int T_2 F_47 ( struct V_1 * V_70 )
{
int V_15 = 0 ;
struct V_52 * V_39 ;
struct V_8 * V_71 ;
struct V_8 * V_72 ;
T_1 V_73 ;
struct V_74 * V_75 = V_70 -> V_2 . V_76 ;
unsigned int V_17 = 0 ;
unsigned long V_77 = V_40 ;
V_71 = F_48 ( V_70 , V_78 , 0 ) ;
if ( ! V_71 ) {
F_49 ( L_16 ) ;
V_15 = - V_25 ;
goto V_79;
}
V_73 = F_4 ( V_71 ) ;
if ( ! F_5 ( V_71 -> V_23 , V_73 , L_17 ) ) {
F_49 ( L_18 ) ;
V_15 = - V_24 ;
goto V_79;
}
V_72 = F_48 ( V_70 , V_80 , 0 ) ;
if ( ! V_72 ) {
F_49 ( L_19 ) ;
return - V_25 ;
}
V_77 |= V_72 -> V_81 & V_82 ;
if ( V_75 ) {
if ( V_75 -> V_83 )
V_17 |= V_30 ;
if ( V_75 -> V_84 )
V_17 |= V_31 ;
if ( V_75 -> V_85 )
V_17 |= V_32 ;
if ( V_75 -> V_86 )
V_17 |= V_33 ;
if ( V_75 -> V_87 )
V_17 |= V_34 ;
if ( V_75 -> V_88 )
V_17 |= V_35 ;
}
V_39 = F_15 ( V_71 -> V_23 , V_73 , V_72 -> V_23 ,
V_77 , - V_69 ,
& V_70 -> V_2 , F_6 ( & V_70 -> V_2 ) , V_17 ) ;
if ( F_16 ( V_39 ) ) {
F_49 ( L_20 ) ;
V_15 = - V_25 ;
goto V_89;
}
F_50 ( L_21 ) ;
return V_15 ;
V_89:
F_20 ( V_71 -> V_23 , V_73 ) ;
V_79:
return V_15 ;
}
static int T_6 F_51 ( struct V_1 * V_70 )
{
struct V_8 * V_71 ;
T_1 V_73 ;
V_71 = F_48 ( V_70 , V_78 , 0 ) ;
V_73 = F_4 ( V_71 ) ;
F_20 ( V_71 -> V_23 , V_73 ) ;
return 0 ;
}
static int T_7 F_52 ( void )
{
int V_15 , V_90 = - V_25 ;
F_53 () ;
V_15 = F_54 ( & V_91 ) ;
if ( ! V_15 )
V_90 = 0 ;
#if F_55 ( V_92 ) && F_55 ( V_93 )
V_15 = F_54 ( & V_94 ) ;
if ( ! V_15 )
V_90 = 0 ;
#endif
#ifdef F_56
V_15 = F_57 ( & V_95 ) ;
if ( ! V_15 )
V_90 = 0 ;
#endif
if ( V_90 )
F_58 () ;
return V_90 ;
}
static void T_8 F_59 ( void )
{
F_60 ( & V_91 ) ;
#if F_55 ( V_92 ) && F_55 ( V_93 )
F_60 ( & V_94 ) ;
#endif
#ifdef F_56
F_61 ( & V_95 ) ;
#endif
F_58 () ;
}
