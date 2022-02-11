static int F_1 ( struct V_1
* V_2 , struct V_3 * V_4 )
{
if ( ( V_2 ) -> V_5 ) {
if ( ( V_4 ) -> V_6 & V_7 )
return - V_8 ;
F_2 ( ( V_2 ) -> V_9 , ( V_2 ) -> V_5 == 0 ) ;
}
return 0 ;
}
static int F_3 ( struct V_10 * V_11 , struct V_3 * V_12 )
{
int V_13 = 0 ;
struct V_14 * V_15 = NULL ;
#ifdef F_4
if ( V_16 ) {
if ( V_12 -> V_6 & V_7 ||
F_5 ( & V_17 ) )
return - V_18 ;
}
#endif
V_15 = F_6 ( sizeof( struct V_14 ) , V_19 ) ;
if ( ! V_15 )
return - V_20 ;
V_15 -> V_21 = V_22 ;
F_7 ( & V_15 -> V_23 ) ;
F_8 ( & V_15 -> V_24 ) ;
F_7 ( & V_15 -> V_25 ) ;
F_8 ( & V_15 -> V_26 ) ;
V_15 -> V_27 = F_6 ( sizeof( struct V_28 ) , V_19 ) ;
if ( ! V_15 -> V_27 ) {
V_13 = - V_20 ;
goto V_29;
}
F_9 ( V_15 -> V_27 ) ;
V_15 -> V_30 = F_6 ( sizeof( struct V_28 ) , V_19 ) ;
if ( ! V_15 -> V_30 ) {
V_13 = - V_20 ;
goto V_31;
}
F_9 ( V_15 -> V_30 ) ;
V_12 -> V_32 = V_15 ;
#ifdef F_4
F_10 ( & V_33 ) ;
#endif
return 0 ;
V_31:
F_11 ( V_15 -> V_27 ) ;
V_29:
F_11 ( V_15 ) ;
return V_13 ;
}
static int F_12 ( struct V_10 * V_11 , struct V_3 * V_12 )
{
int V_13 = 0 ;
struct V_14 * V_15 ;
if ( ! V_12 -> V_32 ) {
V_13 = - V_34 ;
goto V_35;
}
V_15 = V_12 -> V_32 ;
F_13 ( V_36 ) ;
F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_11 ( V_15 -> V_27 ) ;
F_11 ( V_15 -> V_30 ) ;
F_11 ( V_15 ) ;
V_12 -> V_32 = NULL ;
V_35:
#ifdef F_4
if ( ! F_16 ( & V_33 ) )
F_17 ( & V_37 ) ;
#endif
return V_13 ;
}
static long F_18 ( struct V_3 * V_12 , unsigned int V_38 ,
unsigned long args )
{
int V_13 ;
T_1 V_39 = 0 ;
union V_40 V_41 ;
#ifdef F_4
if ( V_16 ) {
V_13 = - V_34 ;
goto V_35;
}
#endif
#ifdef F_19
V_13 = F_1 ( & V_42 , V_12 ) ;
if ( V_13 != 0 )
return V_13 ;
#endif
if ( ! V_12 -> V_32 ) {
V_13 = - V_34 ;
goto V_35;
}
V_13 = F_20 ( & V_41 , (union V_40 * ) args ,
sizeof( union V_40 ) ) ;
if ( ! V_13 ) {
V_13 = F_21 ( V_38 , & V_41 , & V_39 ,
V_12 -> V_32 ) ;
if ( ! V_13 ) {
V_13 = V_39 ;
} else {
F_22 ( V_43 , L_1
L_2 , V_44 , V_38 , V_13 ) ;
V_13 = - 1 ;
}
}
V_35:
return V_13 ;
}
static int F_23 ( struct V_3 * V_12 , struct V_45 * V_46 )
{
T_1 V_13 ;
V_46 -> V_47 |= V_48 | V_49 ;
V_46 -> V_50 = F_24 ( V_46 -> V_50 ) ;
F_22 ( V_43 , L_3
L_4 , V_44 , V_12 ,
V_46 -> V_51 , V_46 -> V_52 , V_46 -> V_50 ,
V_46 -> V_47 ) ;
V_13 = F_25 ( V_46 , V_46 -> V_51 , V_46 -> V_53 ,
V_46 -> V_52 - V_46 -> V_51 ,
V_46 -> V_50 ) ;
if ( V_13 != 0 )
V_13 = - V_54 ;
return V_13 ;
}
static void F_26 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_59 * V_60 ;
if ( F_27 ( & V_33 ) ) {
F_28 ( V_37 ) ;
while ( ! F_29 ( & V_37 ,
F_30 ( V_61 ) ) )
F_31 ( L_5 ,
V_44 , F_27 ( & V_33 ) ) ;
}
V_58 = F_32 () ;
F_33 ( V_58 , & V_60 ) ;
if ( ! V_60 || F_34 ( V_60 , V_58 ) )
F_35 ( L_6 ) ;
V_16 = false ;
F_36 ( & V_17 ) ;
}
void F_37 ( void )
{
F_28 ( V_17 ) ;
V_16 = true ;
F_38 ( V_62 , & V_63 ) ;
}
static int F_39 ( struct V_64 * V_65 ,
unsigned long V_66 , void * V_67 )
{
struct V_68 * V_69 =
V_70 -> V_58 . V_71 ;
if ( V_72 == V_66 && V_69 -> V_73 )
F_40 ( V_74 , V_69 -> V_73 () ) ;
return 0 ;
}
static int F_41 ( struct V_75 * V_76 )
{
struct V_68 * V_69 = V_76 -> V_58 . V_71 ;
struct V_77 * V_78 = NULL ;
T_1 V_79 , V_80 ;
int V_35 ;
#ifdef F_4
V_62 = F_42 ( L_7 ) ;
F_43 ( & V_63 , F_26 ) ;
F_28 ( V_37 ) ;
#endif
#ifdef F_19
V_42 . V_5 = 0 ;
F_44 ( & V_42 . V_9 ) ;
#ifdef F_45
for ( V_81 = 0 ; V_81 < 6 ; V_81 ++ )
V_69 -> V_82 [ V_81 ] = V_83 [ V_81 ] . V_84 ;
V_35 = F_46 ( & V_85 ,
V_86 ) ;
if ( V_35 )
F_35 ( L_8 ,
V_44 ) ;
#endif
#endif
F_47 () ;
V_78 = F_6 ( sizeof( struct V_77 ) , V_19 ) ;
if ( ! V_78 ) {
V_35 = - V_20 ;
goto V_29;
}
V_78 -> V_87 = V_87 ;
V_78 -> V_88 = V_88 ;
if ( V_89 ) {
V_78 -> V_89 = F_48 ( strlen ( V_89 ) + 1 , V_19 ) ;
if ( ! V_78 -> V_89 ) {
V_35 = - V_20 ;
goto V_31;
}
strncpy ( V_78 -> V_89 , V_89 , strlen ( V_89 ) + 1 ) ;
}
F_49 ( V_43 , V_78 ) ;
if ( V_87 < 0x10000 ) {
V_35 = - V_90 ;
F_35 ( L_9 , V_44 ) ;
goto V_91;
}
F_22 ( V_43 , L_10 , V_44 , V_87 ) ;
V_79 = V_69 -> V_92 ;
V_80 = V_69 -> V_93 ;
if ( V_79 > 0 && V_80 > 0 )
F_50 ( V_79 , V_80 ) ;
if ( V_88 )
F_22 ( V_43 , L_11 , V_44 ) ;
V_94 = F_51 ( & V_35 ) ;
if ( V_35 ) {
F_35 ( L_12 ) ;
goto V_95;
}
return 0 ;
V_95:
F_52 () ;
V_91:
F_11 ( V_78 -> V_89 ) ;
V_31:
F_11 ( V_78 ) ;
V_29:
#ifdef F_45
F_53 ( & V_85 ,
V_86 ) ;
#endif
F_54 () ;
return V_35 ;
}
static int T_2 F_55 ( struct V_75 * V_76 )
{
int V_35 ;
T_3 V_58 = 0 ;
#ifdef F_45
int V_81 = 0 ;
#endif
V_70 = V_76 ;
V_43 = & V_70 -> V_58 ;
V_35 = F_41 ( V_76 ) ;
if ( V_35 )
goto V_29;
V_35 = F_56 ( & V_58 , 0 , 1 , L_13 ) ;
if ( V_35 ) {
F_35 ( L_14 , V_44 , V_96 ) ;
goto V_29;
}
F_57 ( & V_97 , & V_98 ) ;
V_97 . V_99 = V_100 ;
V_35 = F_58 ( & V_97 , V_58 , 1 ) ;
if ( V_35 ) {
F_35 ( L_15 , V_44 ) ;
goto V_31;
}
V_101 = F_59 ( V_100 , L_16 ) ;
if ( F_60 ( V_101 ) ) {
F_35 ( L_17 , V_44 ) ;
goto V_91;
}
V_96 = F_61 ( V_58 ) ;
F_62 ( V_101 , NULL , F_63 ( V_96 , 0 ) ,
NULL , L_13 ) ;
F_31 ( L_18 ) ;
return 0 ;
V_91:
F_64 ( & V_97 ) ;
V_31:
F_65 ( V_58 , 1 ) ;
V_29:
return V_35 ;
}
static int T_4 F_66 ( struct V_75 * V_76 )
{
T_3 V_102 ;
int V_13 = 0 ;
struct V_77 * V_78 = F_67 ( V_43 ) ;
if ( ! V_78 || ! V_78 -> V_103 ) {
V_13 = - V_104 ;
F_35 ( L_19 , V_44 ) ;
goto V_105;
}
#ifdef F_45
if ( F_53 ( & V_85 ,
V_86 ) )
F_35 ( L_20 ,
V_44 ) ;
#endif
if ( V_94 ) {
F_68 ( V_94 ) ;
V_94 = 0 ;
}
F_11 ( V_78 ) ;
F_49 ( V_43 , NULL ) ;
V_105:
F_52 () ;
F_54 () ;
V_102 = F_63 ( V_96 , 0 ) ;
F_64 ( & V_97 ) ;
F_65 ( V_102 , 1 ) ;
if ( V_101 ) {
F_69 ( V_101 , F_63 ( V_96 , 0 ) ) ;
F_70 ( V_101 ) ;
}
return 0 ;
}
static int F_71 ( struct V_75 * V_76 , T_5 V_106 )
{
T_1 V_13 ;
T_1 V_107 = V_108 ;
V_13 = F_72 ( V_107 , V_109 ) ;
if ( V_13 )
return - 1 ;
V_42 . V_5 = 1 ;
return 0 ;
}
static int F_73 ( struct V_75 * V_76 )
{
T_1 V_13 ;
V_13 = F_74 ( V_109 ) ;
if ( V_13 )
return - 1 ;
V_42 . V_5 = 0 ;
F_75 ( & V_42 . V_9 ) ;
return 0 ;
}
static int T_6 F_76 ( void )
{
return F_77 ( & V_110 ) ;
}
static void T_7 F_78 ( void )
{
F_79 ( & V_110 ) ;
}
int F_14 ( void * V_111 )
{
int V_13 = 0 ;
struct V_14 * V_112 = (struct V_14 * ) V_111 ;
F_80 ( V_112 ) ;
F_81 ( V_112 ) ;
F_82 ( V_112 ) ;
V_112 -> V_21 = V_113 ;
return V_13 ;
}
