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
static void F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
if ( F_4 ( & V_16 ) ) {
F_5 ( V_17 ) ;
while ( ! F_6 ( & V_17 ,
F_7 ( V_18 ) ) )
F_8 ( L_1 ,
V_19 , F_4 ( & V_16 ) ) ;
}
V_13 = F_9 () ;
F_10 ( V_13 , & V_15 ) ;
if ( ! V_15 || F_11 ( V_15 , V_13 ) )
F_12 ( L_2 ) ;
V_20 = false ;
F_13 ( & V_21 ) ;
}
void F_14 ( void )
{
F_5 ( V_21 ) ;
V_20 = true ;
F_15 ( V_22 , & V_23 ) ;
}
static int F_16 ( struct V_24 * V_25 ,
unsigned long V_26 , void * V_27 )
{
struct V_28 * V_29 =
V_30 -> V_13 . V_31 ;
if ( V_32 == V_26 && V_29 -> V_33 )
F_17 ( V_34 , V_29 -> V_33 () ) ;
return 0 ;
}
static int F_18 ( struct V_35 * V_36 )
{
struct V_28 * V_29 = V_36 -> V_13 . V_31 ;
struct V_37 * V_38 = NULL ;
T_1 V_39 , V_40 ;
int V_41 ;
#ifdef F_19
V_22 = F_20 ( L_3 ) ;
F_21 ( & V_23 , F_3 ) ;
F_5 ( V_17 ) ;
#endif
#ifdef F_22
V_42 . V_5 = 0 ;
F_23 ( & V_42 . V_9 ) ;
#ifdef F_24
for ( V_43 = 0 ; V_43 < 6 ; V_43 ++ )
V_29 -> V_44 [ V_43 ] = V_45 [ V_43 ] . V_46 ;
V_41 = F_25 ( & V_47 ,
V_48 ) ;
if ( V_41 )
F_12 ( L_4 ,
V_19 ) ;
#endif
#endif
F_26 () ;
V_38 = F_27 ( sizeof( struct V_37 ) , V_49 ) ;
if ( ! V_38 ) {
V_41 = - V_50 ;
goto V_51;
}
V_38 -> V_52 = V_52 ;
V_38 -> V_53 = V_53 ;
if ( V_54 ) {
V_38 -> V_54 = F_28 ( strlen ( V_54 ) + 1 , V_49 ) ;
if ( ! V_38 -> V_54 ) {
V_41 = - V_50 ;
goto V_55;
}
strncpy ( V_38 -> V_54 , V_54 , strlen ( V_54 ) + 1 ) ;
}
F_29 ( V_56 , V_38 ) ;
if ( V_52 < 0x10000 ) {
V_41 = - V_57 ;
F_12 ( L_5 , V_19 ) ;
goto V_58;
}
F_30 ( V_56 , L_6 , V_19 , V_52 ) ;
V_39 = V_29 -> V_59 ;
V_40 = V_29 -> V_60 ;
if ( V_39 > 0 && V_40 > 0 )
F_31 ( V_39 , V_40 ) ;
if ( V_53 )
F_30 ( V_56 , L_7 , V_19 ) ;
V_61 = F_32 ( & V_41 ) ;
if ( V_41 ) {
F_12 ( L_8 ) ;
goto V_62;
}
return 0 ;
V_62:
F_33 () ;
V_58:
F_34 ( V_38 -> V_54 ) ;
V_55:
F_34 ( V_38 ) ;
V_51:
#ifdef F_24
F_35 ( & V_47 ,
V_48 ) ;
#endif
F_36 () ;
return V_41 ;
}
static int T_2 F_37 ( struct V_35 * V_36 )
{
int V_41 ;
T_3 V_13 = 0 ;
#ifdef F_24
int V_43 = 0 ;
#endif
V_30 = V_36 ;
V_56 = & V_30 -> V_13 ;
V_41 = F_18 ( V_36 ) ;
if ( V_41 )
goto V_51;
V_41 = F_38 ( & V_13 , 0 , 1 , V_63 ) ;
if ( V_41 ) {
F_12 ( L_9 , V_19 , V_64 ) ;
goto V_51;
}
F_39 ( & V_65 , & V_66 ) ;
V_65 . V_67 = V_68 ;
V_41 = F_40 ( & V_65 , V_13 , 1 ) ;
if ( V_41 ) {
F_12 ( L_10 , V_19 ) ;
goto V_55;
}
V_69 = F_41 ( V_68 , L_11 ) ;
if ( F_42 ( V_69 ) ) {
F_12 ( L_12 , V_19 ) ;
goto V_58;
}
V_64 = F_43 ( V_13 ) ;
F_44 ( V_69 , NULL , F_45 ( V_64 , 0 ) ,
NULL , L_13 ) ;
F_8 ( L_14 ) ;
return 0 ;
V_58:
F_46 ( & V_65 ) ;
V_55:
F_47 ( V_13 , 1 ) ;
V_51:
return V_41 ;
}
static int T_4 F_48 ( struct V_35 * V_36 )
{
T_3 V_70 ;
bool V_71 ;
int V_72 = 0 ;
struct V_37 * V_38 = F_49 ( V_56 ) ;
if ( ! V_38 || ! V_38 -> V_73 ) {
V_72 = - V_74 ;
F_12 ( L_15 , V_19 ) ;
goto V_75;
}
#ifdef F_24
if ( F_35 ( & V_47 ,
V_48 ) )
F_12 ( L_16 ,
V_19 ) ;
#endif
if ( V_61 ) {
V_71 = F_50 ( V_61 ) ;
V_61 = 0 ;
F_51 ( V_71 == true ) ;
}
V_75:
F_33 () ;
F_36 () ;
V_70 = F_45 ( V_64 , 0 ) ;
F_46 ( & V_65 ) ;
F_47 ( V_70 , 1 ) ;
if ( V_69 ) {
F_52 ( V_69 , F_45 ( V_64 , 0 ) ) ;
F_53 ( V_69 ) ;
}
return 0 ;
}
static int F_54 ( struct V_35 * V_36 , T_5 V_76 )
{
T_1 V_72 ;
T_1 V_77 = V_78 ;
V_72 = F_55 ( V_77 , V_79 ) ;
if ( V_72 )
return - 1 ;
V_42 . V_5 = 1 ;
return 0 ;
}
static int F_56 ( struct V_35 * V_36 )
{
T_1 V_72 ;
V_72 = F_57 ( V_79 ) ;
if ( V_72 )
return - 1 ;
V_42 . V_5 = 0 ;
F_58 ( & V_42 . V_9 ) ;
return 0 ;
}
static int T_6 F_59 ( void )
{
return F_60 ( & V_80 ) ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_80 ) ;
}
static int F_63 ( struct V_81 * V_82 , struct V_3 * V_83 )
{
int V_72 = 0 ;
struct V_84 * V_85 = NULL ;
#ifdef F_19
if ( V_20 ) {
if ( V_83 -> V_6 & V_7 ||
F_64 ( & V_21 ) )
return - V_86 ;
}
#endif
V_85 = F_27 ( sizeof( struct V_84 ) , V_49 ) ;
if ( V_85 ) {
V_85 -> V_87 = V_88 ;
F_65 ( & V_85 -> V_89 ) ;
F_66 ( & V_85 -> V_90 ) ;
F_65 ( & V_85 -> V_91 ) ;
F_66 ( & V_85 -> V_92 ) ;
V_85 -> V_93 = F_27 ( sizeof( struct V_94 ) , V_49 ) ;
if ( V_85 -> V_93 ) {
F_67 ( V_85 -> V_93 ) ;
} else {
V_72 = - V_50 ;
goto V_41;
}
V_85 -> V_95 = F_27 ( sizeof( struct V_94 ) , V_49 ) ;
if ( V_85 -> V_95 )
F_67 ( V_85 -> V_95 ) ;
else
V_72 = - V_50 ;
} else {
V_72 = - V_50 ;
}
V_41:
V_83 -> V_96 = V_85 ;
#ifdef F_19
if ( ! V_72 )
F_68 ( & V_16 ) ;
#endif
return V_72 ;
}
static int F_69 ( struct V_81 * V_82 , struct V_3 * V_83 )
{
int V_72 = 0 ;
struct V_84 * V_85 ;
if ( ! V_83 -> V_96 ) {
V_72 = - V_97 ;
goto V_41;
}
V_85 = V_83 -> V_96 ;
F_70 ( V_98 ) ;
F_71 ( V_85 ) ;
F_72 ( V_85 ) ;
F_34 ( V_85 ) ;
V_83 -> V_96 = NULL ;
V_41:
#ifdef F_19
if ( ! F_73 ( & V_16 ) )
F_74 ( & V_17 ) ;
#endif
return V_72 ;
}
static long F_75 ( struct V_3 * V_83 , unsigned int V_99 ,
unsigned long args )
{
int V_72 ;
T_1 V_100 = 0 ;
union V_101 V_102 ;
F_76 ( V_83 != NULL ) ;
#ifdef F_19
if ( V_20 ) {
V_72 = - V_97 ;
goto V_41;
}
#endif
#ifdef F_22
V_72 = F_1 ( & V_42 , V_83 ) ;
if ( V_72 != 0 )
return V_72 ;
#endif
if ( ! V_83 -> V_96 ) {
V_72 = - V_97 ;
goto V_41;
}
V_72 = F_77 ( & V_102 , (union V_101 * ) args ,
sizeof( union V_101 ) ) ;
if ( ! V_72 ) {
V_72 = F_78 ( V_99 , & V_102 , & V_100 ,
V_83 -> V_96 ) ;
if ( ! V_72 ) {
V_72 = V_100 ;
} else {
F_30 ( V_56 , L_17
L_18 , V_19 , V_99 , V_72 ) ;
V_72 = - 1 ;
}
}
V_41:
return V_72 ;
}
static int F_79 ( struct V_3 * V_83 , struct V_103 * V_104 )
{
T_1 V_105 = V_104 -> V_106 << V_107 ;
T_1 V_72 ;
F_51 ( V_104 -> V_108 < V_104 -> V_109 ) ;
V_104 -> V_110 |= V_111 | V_112 ;
V_104 -> V_113 = F_80 ( V_104 -> V_113 ) ;
F_30 ( V_56 , L_19
L_20 , V_19 , V_83 , V_105 ,
V_104 -> V_108 , V_104 -> V_109 , V_104 -> V_113 , V_104 -> V_110 ) ;
V_72 = F_81 ( V_104 , V_104 -> V_108 , V_104 -> V_106 ,
V_104 -> V_109 - V_104 -> V_108 ,
V_104 -> V_113 ) ;
if ( V_72 != 0 )
V_72 = - V_114 ;
return V_72 ;
}
int F_71 ( void * V_115 )
{
int V_72 = 0 ;
struct V_84 * V_116 = (struct V_84 * ) V_115 ;
F_82 ( V_116 ) ;
F_83 ( V_116 ) ;
F_84 ( V_116 ) ;
V_116 -> V_87 = V_117 ;
return V_72 ;
}
