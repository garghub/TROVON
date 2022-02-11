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
V_46 -> V_47 = F_24 ( V_46 -> V_47 ) ;
F_22 ( V_43 , L_3
L_4 , V_44 , V_12 ,
V_46 -> V_48 , V_46 -> V_49 , V_46 -> V_47 ,
V_46 -> V_50 ) ;
V_13 = F_25 ( V_46 , V_46 -> V_48 , V_46 -> V_51 ,
V_46 -> V_49 - V_46 -> V_48 ,
V_46 -> V_47 ) ;
if ( V_13 != 0 )
V_13 = - V_52 ;
return V_13 ;
}
static void F_26 ( struct V_53 * V_54 )
{
struct V_55 * V_56 ;
struct V_57 * V_58 ;
if ( F_27 ( & V_33 ) ) {
F_28 ( V_37 ) ;
while ( ! F_29 ( & V_37 ,
F_30 ( V_59 ) ) )
F_31 ( L_5 ,
V_44 , F_27 ( & V_33 ) ) ;
}
V_56 = F_32 () ;
F_33 ( V_56 , & V_58 ) ;
if ( ! V_58 || F_34 ( V_58 , V_56 ) )
F_35 ( L_6 ) ;
V_16 = false ;
F_36 ( & V_17 ) ;
}
void F_37 ( void )
{
F_28 ( V_17 ) ;
V_16 = true ;
F_38 ( V_60 , & V_61 ) ;
}
static int F_39 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
struct V_66 * V_67 =
V_68 -> V_56 . V_69 ;
if ( V_70 == V_64 && V_67 -> V_71 )
F_40 ( V_72 , V_67 -> V_71 () ) ;
return 0 ;
}
static int F_41 ( struct V_73 * V_74 )
{
struct V_66 * V_67 = V_74 -> V_56 . V_69 ;
struct V_75 * V_76 = NULL ;
T_1 V_77 , V_78 ;
int V_35 ;
#ifdef F_4
V_60 = F_42 ( L_7 ) ;
F_43 ( & V_61 , F_26 ) ;
F_28 ( V_37 ) ;
#endif
#ifdef F_19
V_42 . V_5 = 0 ;
F_44 ( & V_42 . V_9 ) ;
#ifdef F_45
for ( V_79 = 0 ; V_79 < 6 ; V_79 ++ )
V_67 -> V_80 [ V_79 ] = V_81 [ V_79 ] . V_82 ;
V_35 = F_46 ( & V_83 ,
V_84 ) ;
if ( V_35 )
F_35 ( L_8 ,
V_44 ) ;
#endif
#endif
F_47 () ;
V_76 = F_6 ( sizeof( struct V_75 ) , V_19 ) ;
if ( ! V_76 ) {
V_35 = - V_20 ;
goto V_29;
}
V_76 -> V_85 = V_85 ;
V_76 -> V_86 = V_86 ;
if ( V_87 ) {
V_76 -> V_87 = F_48 ( strlen ( V_87 ) + 1 , V_19 ) ;
if ( ! V_76 -> V_87 ) {
V_35 = - V_20 ;
goto V_31;
}
strncpy ( V_76 -> V_87 , V_87 , strlen ( V_87 ) + 1 ) ;
}
F_49 ( V_43 , V_76 ) ;
if ( V_85 < 0x10000 ) {
V_35 = - V_88 ;
F_35 ( L_9 , V_44 ) ;
goto V_89;
}
F_22 ( V_43 , L_10 , V_44 , V_85 ) ;
V_77 = V_67 -> V_90 ;
V_78 = V_67 -> V_91 ;
if ( V_77 > 0 && V_78 > 0 )
F_50 ( V_77 , V_78 ) ;
if ( V_86 )
F_22 ( V_43 , L_11 , V_44 ) ;
V_92 = F_51 ( & V_35 ) ;
if ( V_35 ) {
F_35 ( L_12 ) ;
goto V_93;
}
return 0 ;
V_93:
F_52 () ;
V_89:
F_11 ( V_76 -> V_87 ) ;
V_31:
F_11 ( V_76 ) ;
V_29:
#ifdef F_45
F_53 ( & V_83 ,
V_84 ) ;
#endif
F_54 () ;
return V_35 ;
}
static int T_2 F_55 ( struct V_73 * V_74 )
{
int V_35 ;
T_3 V_56 = 0 ;
#ifdef F_45
int V_79 = 0 ;
#endif
V_68 = V_74 ;
V_43 = & V_68 -> V_56 ;
V_35 = F_41 ( V_74 ) ;
if ( V_35 )
goto V_29;
V_35 = F_56 ( & V_56 , 0 , 1 , L_13 ) ;
if ( V_35 ) {
F_35 ( L_14 , V_44 , V_94 ) ;
goto V_29;
}
F_57 ( & V_95 , & V_96 ) ;
V_95 . V_97 = V_98 ;
V_35 = F_58 ( & V_95 , V_56 , 1 ) ;
if ( V_35 ) {
F_35 ( L_15 , V_44 ) ;
goto V_31;
}
V_99 = F_59 ( V_98 , L_16 ) ;
if ( F_60 ( V_99 ) ) {
F_35 ( L_17 , V_44 ) ;
goto V_89;
}
V_94 = F_61 ( V_56 ) ;
F_62 ( V_99 , NULL , F_63 ( V_94 , 0 ) ,
NULL , L_13 ) ;
F_31 ( L_18 ) ;
return 0 ;
V_89:
F_64 ( & V_95 ) ;
V_31:
F_65 ( V_56 , 1 ) ;
V_29:
return V_35 ;
}
static int T_4 F_66 ( struct V_73 * V_74 )
{
T_3 V_100 ;
int V_13 = 0 ;
struct V_75 * V_76 = F_67 ( V_43 ) ;
if ( ! V_76 || ! V_76 -> V_101 ) {
V_13 = - V_102 ;
F_35 ( L_19 , V_44 ) ;
goto V_103;
}
#ifdef F_45
if ( F_53 ( & V_83 ,
V_84 ) )
F_35 ( L_20 ,
V_44 ) ;
#endif
if ( V_92 ) {
F_68 ( V_92 ) ;
V_92 = 0 ;
}
F_11 ( V_76 ) ;
F_49 ( V_43 , NULL ) ;
V_103:
F_52 () ;
F_54 () ;
V_100 = F_63 ( V_94 , 0 ) ;
F_64 ( & V_95 ) ;
F_65 ( V_100 , 1 ) ;
if ( V_99 ) {
F_69 ( V_99 , F_63 ( V_94 , 0 ) ) ;
F_70 ( V_99 ) ;
}
return 0 ;
}
static int F_71 ( struct V_73 * V_74 , T_5 V_104 )
{
T_1 V_13 ;
T_1 V_105 = V_106 ;
V_13 = F_72 ( V_105 , V_107 ) ;
if ( V_13 )
return - 1 ;
V_42 . V_5 = 1 ;
return 0 ;
}
static int F_73 ( struct V_73 * V_74 )
{
T_1 V_13 ;
V_13 = F_74 ( V_107 ) ;
if ( V_13 )
return - 1 ;
V_42 . V_5 = 0 ;
F_75 ( & V_42 . V_9 ) ;
return 0 ;
}
int F_14 ( void * V_108 )
{
int V_13 = 0 ;
struct V_14 * V_109 = (struct V_14 * ) V_108 ;
F_76 ( V_109 ) ;
F_77 ( V_109 ) ;
F_78 ( V_109 ) ;
V_109 -> V_21 = V_110 ;
return V_13 ;
}
