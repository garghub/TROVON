static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_1 V_6 = V_4 -> V_7 * V_4 -> V_8 . V_9 ;
T_1 V_10 =
F_2 ( V_6 * V_2 -> V_11 , 100 ) ;
T_2 V_12 = F_3 ( V_10 * F_4 ( V_2 -> V_13 ) ,
V_4 -> V_14 ) ;
T_2 V_15 = F_5 ( & V_2 -> V_5 ) ;
T_2 V_16 = V_15 - V_2 -> V_5 . V_17 ;
T_2 V_18 = V_15 - V_12 ;
T_2 V_19 ;
V_2 -> V_5 . V_17 = V_15 ;
V_18 *= V_2 -> V_20 ;
V_18 = F_6 ( V_18 , V_2 -> V_21 ) ;
V_16 = F_6 ( V_16 , V_2 -> V_20 ) ;
V_16 = F_7 ( V_2 -> V_5 . V_22 , V_16 ,
( V_2 -> V_23 /
V_2 -> V_20 ) ? : 1 , 0 ) ;
V_16 *= V_2 -> V_23 ;
V_16 = F_6 ( V_16 , V_2 -> V_21 ) ;
V_19 = V_18 + V_16 ;
if ( V_19 > 0 &&
F_8 ( F_9 () ,
V_2 -> V_24 . V_25 + V_26 ) )
V_19 = 0 ;
V_2 -> V_24 . V_27 =
F_10 ( T_2 , ( T_2 ) V_2 -> V_24 . V_27 + V_19 ,
1 , V_26 ) ;
V_2 -> V_28 = V_18 ;
V_2 -> V_29 = V_16 ;
V_2 -> V_30 = V_19 ;
V_2 -> V_31 = V_12 ;
}
static void F_11 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_12 ( F_13 ( V_33 ) ,
struct V_1 ,
V_34 ) ;
F_14 ( & V_2 -> V_35 ) ;
if ( F_15 ( & V_2 -> V_36 ) &&
V_2 -> V_11 )
F_1 ( V_2 ) ;
F_16 ( & V_2 -> V_35 ) ;
F_17 ( & V_2 -> V_34 ,
V_2 -> V_20 * V_37 ) ;
}
static unsigned F_18 ( struct V_1 * V_2 , unsigned V_38 )
{
if ( F_19 ( V_39 , & V_2 -> V_5 . V_40 ) ||
! V_2 -> V_11 )
return 0 ;
return F_20 ( & V_2 -> V_24 , V_38 ) ;
}
static void F_21 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_46 * V_46 = & V_44 -> V_46 ;
F_22 ( V_46 ) ;
if ( ! V_44 -> V_2 -> V_11 )
F_23 ( V_46 , F_24 ( V_47 , 0 ) ) ;
V_46 -> V_48 = F_25 ( & V_42 -> V_49 ) << 9 ;
V_46 -> V_50 = F_26 ( F_25 ( & V_42 -> V_49 ) , V_51 ) ;
V_46 -> V_52 = V_42 ;
V_46 -> V_53 = V_46 -> V_54 ;
F_27 ( V_46 , NULL ) ;
}
static void F_28 ( struct V_55 * V_56 )
{
struct V_43 * V_44 = F_12 ( V_56 , struct V_43 , V_56 ) ;
F_29 ( V_44 ) ;
}
static void F_30 ( struct V_55 * V_56 )
{
struct V_43 * V_44 = F_12 ( V_56 , struct V_43 , V_56 ) ;
struct V_41 * V_42 = V_44 -> V_46 . V_52 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_57 * V_58 ;
int V_59 ;
F_31 (bv, &io->bio, i)
F_32 ( V_58 -> V_60 ) ;
if ( F_33 ( & V_42 -> V_49 ) ) {
int V_61 ;
unsigned V_59 ;
struct V_62 V_63 ;
F_34 ( & V_63 ) ;
F_35 ( V_63 . V_64 , & V_42 -> V_49 ) ;
F_36 ( V_63 . V_64 , false ) ;
F_37 ( & V_63 ) ;
for ( V_59 = 0 ; V_59 < F_38 ( & V_42 -> V_49 ) ; V_59 ++ )
F_39 ( & F_40 ( V_2 -> V_5 . V_4 , & V_42 -> V_49 , V_59 ) -> V_65 ) ;
V_61 = F_41 ( V_2 -> V_5 . V_4 , & V_63 , NULL , & V_42 -> V_49 ) ;
if ( V_61 )
F_42 ( & V_42 -> V_49 ) ;
F_43 ( V_61
? & V_2 -> V_5 . V_4 -> V_66
: & V_2 -> V_5 . V_4 -> V_67 ) ;
}
F_44 ( & V_2 -> V_68 , V_42 ) ;
F_45 ( & V_2 -> V_69 ) ;
F_46 ( V_56 , F_28 ) ;
}
static void F_47 ( struct V_46 * V_46 , int error )
{
struct V_41 * V_42 = V_46 -> V_52 ;
struct V_43 * V_44 = V_42 -> V_45 ;
if ( error )
F_36 ( & V_42 -> V_49 , false ) ;
F_48 ( & V_44 -> V_56 ) ;
}
static void F_49 ( struct V_55 * V_56 )
{
struct V_43 * V_44 = F_12 ( V_56 , struct V_43 , V_56 ) ;
struct V_41 * V_42 = V_44 -> V_46 . V_52 ;
F_21 ( V_42 ) ;
V_44 -> V_46 . V_70 = V_71 ;
V_44 -> V_46 . V_72 = F_50 ( & V_42 -> V_49 ) ;
V_44 -> V_46 . V_73 = V_44 -> V_2 -> V_13 ;
V_44 -> V_46 . V_74 = F_47 ;
F_51 ( & V_44 -> V_46 , V_56 , & V_44 -> V_2 -> V_5 ) ;
F_52 ( V_56 , F_30 , V_75 ) ;
}
static void F_53 ( struct V_46 * V_46 , int error )
{
struct V_41 * V_42 = V_46 -> V_52 ;
struct V_43 * V_44 = V_42 -> V_45 ;
F_54 ( F_55 ( V_44 -> V_2 -> V_5 . V_4 , & V_42 -> V_49 , 0 ) ,
error , L_1 ) ;
F_47 ( V_46 , error ) ;
}
static void F_56 ( struct V_55 * V_56 )
{
struct V_43 * V_44 = F_12 ( V_56 , struct V_43 , V_56 ) ;
F_51 ( & V_44 -> V_46 , V_56 , & V_44 -> V_2 -> V_5 ) ;
F_52 ( V_56 , F_49 , V_75 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned V_76 = 0 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_55 V_56 ;
F_58 ( & V_56 ) ;
while ( ! F_59 () ) {
F_60 () ;
V_42 = F_61 ( & V_2 -> V_68 ) ;
if ( ! V_42 )
break;
F_62 ( F_63 ( V_2 -> V_5 . V_4 , & V_42 -> V_49 , 0 ) ) ;
if ( F_50 ( & V_42 -> V_49 ) != V_2 -> V_77 ||
F_64 ( V_76 ) > 50 )
while ( ! F_59 () && V_76 )
V_76 = F_65 ( V_76 ) ;
V_2 -> V_77 = F_66 ( & V_42 -> V_49 ) ;
V_44 = F_67 ( sizeof( struct V_43 ) + sizeof( struct V_57 )
* F_26 ( F_25 ( & V_42 -> V_49 ) , V_51 ) ,
V_78 ) ;
if ( ! V_44 )
goto V_79;
V_42 -> V_45 = V_44 ;
V_44 -> V_2 = V_2 ;
F_21 ( V_42 ) ;
V_44 -> V_46 . V_72 = F_68 ( & V_42 -> V_49 , 0 ) ;
V_44 -> V_46 . V_73 = F_55 ( V_2 -> V_5 . V_4 ,
& V_42 -> V_49 , 0 ) -> V_13 ;
V_44 -> V_46 . V_70 = V_80 ;
V_44 -> V_46 . V_74 = F_53 ;
if ( F_69 ( & V_44 -> V_46 , V_78 ) )
goto V_81;
F_70 ( & V_42 -> V_49 ) ;
F_71 ( & V_2 -> V_69 ) ;
F_72 ( & V_44 -> V_56 , F_56 , NULL , & V_56 ) ;
V_76 = F_18 ( V_2 , F_25 ( & V_42 -> V_49 ) ) ;
}
if ( 0 ) {
V_81:
F_29 ( V_42 -> V_45 ) ;
V_79:
F_44 ( & V_2 -> V_68 , V_42 ) ;
}
F_73 ( & V_56 ) ;
}
void F_74 ( struct V_3 * V_4 , unsigned V_82 ,
T_1 V_83 , int V_84 )
{
struct V_85 * V_86 = V_4 -> V_87 [ V_82 ] ;
unsigned V_88 , V_89 , V_90 ;
if ( ! V_86 )
return;
V_89 = F_75 ( V_86 , V_83 ) ;
V_88 = V_83 & ( V_86 -> V_91 - 1 ) ;
while ( V_84 ) {
int V_92 = F_76 ( unsigned , abs ( V_84 ) ,
V_86 -> V_91 - V_88 ) ;
if ( V_84 < 0 )
V_92 = - V_92 ;
if ( V_89 >= V_86 -> V_93 )
return;
V_90 = F_77 ( V_92 ,
V_86 -> V_94 + V_89 ) ;
if ( V_90 == V_86 -> V_91 )
F_78 ( V_89 , V_86 -> V_95 ) ;
else
F_79 ( V_89 , V_86 -> V_95 ) ;
V_84 -= V_92 ;
V_88 = 0 ;
V_89 ++ ;
}
}
static bool F_80 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
return F_33 ( V_99 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = & V_2 -> V_68 ;
unsigned V_100 , V_89 , V_101 ;
bool V_102 = false ;
V_89 = F_75 ( & V_2 -> V_5 , F_66 ( & V_97 -> V_103 ) ) ;
if ( V_89 >= V_2 -> V_5 . V_93 )
V_89 = 0 ;
V_100 = V_89 ;
while ( 1 ) {
V_89 = F_82 ( V_2 -> V_5 . V_95 ,
V_2 -> V_5 . V_93 , V_89 ) ;
if ( V_89 == V_2 -> V_5 . V_93 )
goto V_25;
V_101 = F_83 ( V_2 -> V_5 . V_95 ,
V_2 -> V_5 . V_93 , V_89 ) ;
V_97 -> V_103 = F_84 ( V_2 -> V_5 . V_104 ,
V_89 * V_2 -> V_5 . V_91 , 0 ) ;
F_85 ( V_2 -> V_5 . V_4 , V_97 ,
& F_84 ( V_2 -> V_5 . V_104 ,
V_101 * V_2 -> V_5 . V_91 , 0 ) ,
F_80 ) ;
if ( F_86 ( & V_97 -> V_105 ) )
return;
V_89 = V_101 ;
V_25:
if ( V_102 && V_89 > V_100 )
return;
if ( V_89 == V_2 -> V_5 . V_93 ) {
V_89 = 0 ;
V_102 = true ;
}
}
}
static bool F_87 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = & V_2 -> V_68 ;
struct V_98 V_106 = F_84 ( V_2 -> V_5 . V_104 , V_107 , 0 ) ;
bool V_108 = false ;
if ( V_2 -> V_109 ) {
F_81 ( V_2 ) ;
if ( F_86 ( & V_97 -> V_105 ) )
return false ;
}
if ( F_88 ( & V_97 -> V_103 , & V_106 ) >= 0 ) {
V_97 -> V_103 = F_84 ( V_2 -> V_5 . V_104 , 0 , 0 ) ;
V_108 = true ;
}
F_85 ( V_2 -> V_5 . V_4 , V_97 , & V_106 , F_80 ) ;
return F_88 ( & V_97 -> V_103 , & V_106 ) >= 0 && V_108 ;
}
static int F_89 ( void * V_110 )
{
struct V_1 * V_2 = V_110 ;
bool V_111 ;
while ( ! F_59 () ) {
F_90 ( & V_2 -> V_35 ) ;
if ( ! F_15 ( & V_2 -> V_36 ) ||
( ! F_19 ( V_39 , & V_2 -> V_5 . V_40 ) &&
! V_2 -> V_112 ) ) {
F_91 ( & V_2 -> V_35 ) ;
F_92 ( V_113 ) ;
if ( F_59 () )
return 0 ;
F_60 () ;
F_93 () ;
continue;
}
V_111 = F_87 ( V_2 ) ;
if ( V_111 &&
F_94 ( & V_2 -> V_68 . V_63 ) ) {
F_95 ( & V_2 -> V_36 , 0 ) ;
F_96 ( V_2 ) ;
F_97 ( & V_2 -> V_8 , V_114 ) ;
F_98 ( V_2 , NULL ) ;
}
F_91 ( & V_2 -> V_35 ) ;
F_99 ( & V_2 -> V_24 ) ;
F_57 ( V_2 ) ;
if ( V_111 ) {
unsigned V_76 = V_2 -> F_18 * V_37 ;
while ( V_76 &&
! F_59 () &&
! F_19 ( V_39 , & V_2 -> V_5 . V_40 ) )
V_76 = F_65 ( V_76 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_115 * V_116 , struct V_117 * V_118 ,
struct V_98 * V_99 )
{
struct V_119 * V_120 = F_12 ( V_116 ,
struct V_119 , V_120 ) ;
if ( F_101 ( V_99 ) > V_120 -> V_82 )
return V_121 ;
if ( F_33 ( V_99 ) )
F_74 ( V_118 -> V_4 , F_101 ( V_99 ) ,
F_50 ( V_99 ) , F_25 ( V_99 ) ) ;
return V_122 ;
}
void F_102 ( struct V_1 * V_2 )
{
struct V_119 V_120 ;
F_103 ( & V_120 . V_120 , - 1 ) ;
V_120 . V_82 = V_2 -> V_5 . V_104 ;
F_104 ( & V_120 . V_120 , V_2 -> V_5 . V_4 , & F_84 ( V_120 . V_82 , 0 , 0 ) ,
F_100 , 0 ) ;
V_2 -> V_5 . V_17 = F_5 ( & V_2 -> V_5 ) ;
}
int F_105 ( struct V_1 * V_2 )
{
F_106 ( & V_2 -> V_69 , 64 ) ;
F_107 ( & V_2 -> V_35 ) ;
F_108 ( & V_2 -> V_68 ) ;
V_2 -> V_123 = true ;
V_2 -> V_112 = true ;
V_2 -> V_11 = 10 ;
V_2 -> F_18 = 30 ;
V_2 -> V_24 . V_27 = 1024 ;
V_2 -> V_20 = 5 ;
V_2 -> V_23 = 30 ;
V_2 -> V_21 = 6000 ;
V_2 -> V_124 = F_109 ( F_89 , V_2 ,
L_2 ) ;
if ( F_110 ( V_2 -> V_124 ) )
return F_111 ( V_2 -> V_124 ) ;
F_112 ( & V_2 -> V_34 , F_11 ) ;
F_17 ( & V_2 -> V_34 ,
V_2 -> V_20 * V_37 ) ;
return 0 ;
}
