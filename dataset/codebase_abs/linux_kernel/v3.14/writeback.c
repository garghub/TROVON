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
V_46 -> V_48 . V_49 = F_25 ( & V_42 -> V_50 ) << 9 ;
V_46 -> V_51 = F_26 ( F_25 ( & V_42 -> V_50 ) , V_52 ) ;
V_46 -> V_53 = V_42 ;
V_46 -> V_54 = V_46 -> V_55 ;
F_27 ( V_46 , NULL ) ;
}
static void F_28 ( struct V_56 * V_57 )
{
struct V_43 * V_44 = F_12 ( V_57 , struct V_43 , V_57 ) ;
F_29 ( V_44 ) ;
}
static void F_30 ( struct V_56 * V_57 )
{
struct V_43 * V_44 = F_12 ( V_57 , struct V_43 , V_57 ) ;
struct V_41 * V_42 = V_44 -> V_46 . V_53 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_58 * V_59 ;
int V_60 ;
F_31 (bv, &io->bio, i)
F_32 ( V_59 -> V_61 ) ;
if ( F_33 ( & V_42 -> V_50 ) ) {
int V_62 ;
unsigned V_60 ;
struct V_63 V_64 ;
F_34 ( & V_64 ) ;
F_35 ( V_64 . V_65 , & V_42 -> V_50 ) ;
F_36 ( V_64 . V_65 , false ) ;
F_37 ( & V_64 ) ;
for ( V_60 = 0 ; V_60 < F_38 ( & V_42 -> V_50 ) ; V_60 ++ )
F_39 ( & F_40 ( V_2 -> V_5 . V_4 , & V_42 -> V_50 , V_60 ) -> V_66 ) ;
V_62 = F_41 ( V_2 -> V_5 . V_4 , & V_64 , NULL , & V_42 -> V_50 ) ;
if ( V_62 )
F_42 ( & V_42 -> V_50 ) ;
F_43 ( V_62
? & V_2 -> V_5 . V_4 -> V_67
: & V_2 -> V_5 . V_4 -> V_68 ) ;
}
F_44 ( & V_2 -> V_69 , V_42 ) ;
F_45 ( & V_2 -> V_70 ) ;
F_46 ( V_57 , F_28 ) ;
}
static void F_47 ( struct V_46 * V_46 , int error )
{
struct V_41 * V_42 = V_46 -> V_53 ;
struct V_43 * V_44 = V_42 -> V_45 ;
if ( error )
F_36 ( & V_42 -> V_50 , false ) ;
F_48 ( & V_44 -> V_57 ) ;
}
static void F_49 ( struct V_56 * V_57 )
{
struct V_43 * V_44 = F_12 ( V_57 , struct V_43 , V_57 ) ;
struct V_41 * V_42 = V_44 -> V_46 . V_53 ;
F_21 ( V_42 ) ;
V_44 -> V_46 . V_71 = V_72 ;
V_44 -> V_46 . V_48 . V_73 = F_50 ( & V_42 -> V_50 ) ;
V_44 -> V_46 . V_74 = V_44 -> V_2 -> V_13 ;
V_44 -> V_46 . V_75 = F_47 ;
F_51 ( & V_44 -> V_46 , V_57 , & V_44 -> V_2 -> V_5 ) ;
F_52 ( V_57 , F_30 , V_76 ) ;
}
static void F_53 ( struct V_46 * V_46 , int error )
{
struct V_41 * V_42 = V_46 -> V_53 ;
struct V_43 * V_44 = V_42 -> V_45 ;
F_54 ( F_55 ( V_44 -> V_2 -> V_5 . V_4 , & V_42 -> V_50 , 0 ) ,
error , L_1 ) ;
F_47 ( V_46 , error ) ;
}
static void F_56 ( struct V_56 * V_57 )
{
struct V_43 * V_44 = F_12 ( V_57 , struct V_43 , V_57 ) ;
F_51 ( & V_44 -> V_46 , V_57 , & V_44 -> V_2 -> V_5 ) ;
F_52 ( V_57 , F_49 , V_76 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned V_77 = 0 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_56 V_57 ;
F_58 ( & V_57 ) ;
while ( ! F_59 () ) {
F_60 () ;
V_42 = F_61 ( & V_2 -> V_69 ) ;
if ( ! V_42 )
break;
F_62 ( F_63 ( V_2 -> V_5 . V_4 , & V_42 -> V_50 , 0 ) ) ;
if ( F_50 ( & V_42 -> V_50 ) != V_2 -> V_78 ||
F_64 ( V_77 ) > 50 )
while ( ! F_59 () && V_77 )
V_77 = F_65 ( V_77 ) ;
V_2 -> V_78 = F_66 ( & V_42 -> V_50 ) ;
V_44 = F_67 ( sizeof( struct V_43 ) + sizeof( struct V_58 )
* F_26 ( F_25 ( & V_42 -> V_50 ) , V_52 ) ,
V_79 ) ;
if ( ! V_44 )
goto V_80;
V_42 -> V_45 = V_44 ;
V_44 -> V_2 = V_2 ;
F_21 ( V_42 ) ;
V_44 -> V_46 . V_48 . V_73 = F_68 ( & V_42 -> V_50 , 0 ) ;
V_44 -> V_46 . V_74 = F_55 ( V_2 -> V_5 . V_4 ,
& V_42 -> V_50 , 0 ) -> V_13 ;
V_44 -> V_46 . V_71 = V_81 ;
V_44 -> V_46 . V_75 = F_53 ;
if ( F_69 ( & V_44 -> V_46 , V_79 ) )
goto V_82;
F_70 ( & V_42 -> V_50 ) ;
F_71 ( & V_2 -> V_70 ) ;
F_72 ( & V_44 -> V_57 , F_56 , NULL , & V_57 ) ;
V_77 = F_18 ( V_2 , F_25 ( & V_42 -> V_50 ) ) ;
}
if ( 0 ) {
V_82:
F_29 ( V_42 -> V_45 ) ;
V_80:
F_44 ( & V_2 -> V_69 , V_42 ) ;
}
F_73 ( & V_57 ) ;
}
void F_74 ( struct V_3 * V_4 , unsigned V_83 ,
T_1 V_84 , int V_85 )
{
struct V_86 * V_87 = V_4 -> V_88 [ V_83 ] ;
unsigned V_89 , V_90 , V_91 ;
if ( ! V_87 )
return;
V_90 = F_75 ( V_87 , V_84 ) ;
V_89 = V_84 & ( V_87 -> V_92 - 1 ) ;
while ( V_85 ) {
int V_93 = F_76 ( unsigned , abs ( V_85 ) ,
V_87 -> V_92 - V_89 ) ;
if ( V_85 < 0 )
V_93 = - V_93 ;
if ( V_90 >= V_87 -> V_94 )
return;
V_91 = F_77 ( V_93 ,
V_87 -> V_95 + V_90 ) ;
if ( V_91 == V_87 -> V_92 )
F_78 ( V_90 , V_87 -> V_96 ) ;
else
F_79 ( V_90 , V_87 -> V_96 ) ;
V_85 -= V_93 ;
V_89 = 0 ;
V_90 ++ ;
}
}
static bool F_80 ( struct V_97 * V_98 , struct V_99 * V_100 )
{
return F_33 ( V_100 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_69 ;
unsigned V_101 , V_90 , V_102 ;
bool V_103 = false ;
V_90 = F_75 ( & V_2 -> V_5 , F_66 ( & V_98 -> V_104 ) ) ;
if ( V_90 >= V_2 -> V_5 . V_94 )
V_90 = 0 ;
V_101 = V_90 ;
while ( 1 ) {
V_90 = F_82 ( V_2 -> V_5 . V_96 ,
V_2 -> V_5 . V_94 , V_90 ) ;
if ( V_90 == V_2 -> V_5 . V_94 )
goto V_25;
V_102 = F_83 ( V_2 -> V_5 . V_96 ,
V_2 -> V_5 . V_94 , V_90 ) ;
V_98 -> V_104 = F_84 ( V_2 -> V_5 . V_105 ,
V_90 * V_2 -> V_5 . V_92 , 0 ) ;
F_85 ( V_2 -> V_5 . V_4 , V_98 ,
& F_84 ( V_2 -> V_5 . V_105 ,
V_102 * V_2 -> V_5 . V_92 , 0 ) ,
F_80 ) ;
if ( F_86 ( & V_98 -> V_106 ) )
return;
V_90 = V_102 ;
V_25:
if ( V_103 && V_90 > V_101 )
return;
if ( V_90 == V_2 -> V_5 . V_94 ) {
V_90 = 0 ;
V_103 = true ;
}
}
}
static bool F_87 ( struct V_1 * V_2 )
{
struct V_97 * V_98 = & V_2 -> V_69 ;
struct V_99 V_107 = F_84 ( V_2 -> V_5 . V_105 , V_108 , 0 ) ;
bool V_109 = false ;
if ( V_2 -> V_110 ) {
F_81 ( V_2 ) ;
if ( F_86 ( & V_98 -> V_106 ) )
return false ;
}
if ( F_88 ( & V_98 -> V_104 , & V_107 ) >= 0 ) {
V_98 -> V_104 = F_84 ( V_2 -> V_5 . V_105 , 0 , 0 ) ;
V_109 = true ;
}
F_85 ( V_2 -> V_5 . V_4 , V_98 , & V_107 , F_80 ) ;
return F_88 ( & V_98 -> V_104 , & V_107 ) >= 0 && V_109 ;
}
static int F_89 ( void * V_111 )
{
struct V_1 * V_2 = V_111 ;
bool V_112 ;
while ( ! F_59 () ) {
F_90 ( & V_2 -> V_35 ) ;
if ( ! F_15 ( & V_2 -> V_36 ) ||
( ! F_19 ( V_39 , & V_2 -> V_5 . V_40 ) &&
! V_2 -> V_113 ) ) {
F_91 ( & V_2 -> V_35 ) ;
F_92 ( V_114 ) ;
if ( F_59 () )
return 0 ;
F_60 () ;
F_93 () ;
continue;
}
V_112 = F_87 ( V_2 ) ;
if ( V_112 &&
F_94 ( & V_2 -> V_69 . V_64 ) ) {
F_95 ( & V_2 -> V_36 , 0 ) ;
F_96 ( V_2 ) ;
F_97 ( & V_2 -> V_8 , V_115 ) ;
F_98 ( V_2 , NULL ) ;
}
F_91 ( & V_2 -> V_35 ) ;
F_99 ( & V_2 -> V_24 ) ;
F_57 ( V_2 ) ;
if ( V_112 ) {
unsigned V_77 = V_2 -> F_18 * V_37 ;
while ( V_77 &&
! F_59 () &&
! F_19 ( V_39 , & V_2 -> V_5 . V_40 ) )
V_77 = F_65 ( V_77 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_116 * V_117 , struct V_118 * V_119 ,
struct V_99 * V_100 )
{
struct V_120 * V_121 = F_12 ( V_117 ,
struct V_120 , V_121 ) ;
if ( F_101 ( V_100 ) > V_121 -> V_83 )
return V_122 ;
if ( F_33 ( V_100 ) )
F_74 ( V_119 -> V_4 , F_101 ( V_100 ) ,
F_50 ( V_100 ) , F_25 ( V_100 ) ) ;
return V_123 ;
}
void F_102 ( struct V_1 * V_2 )
{
struct V_120 V_121 ;
F_103 ( & V_121 . V_121 , - 1 ) ;
V_121 . V_83 = V_2 -> V_5 . V_105 ;
F_104 ( & V_121 . V_121 , V_2 -> V_5 . V_4 , & F_84 ( V_121 . V_83 , 0 , 0 ) ,
F_100 , 0 ) ;
V_2 -> V_5 . V_17 = F_5 ( & V_2 -> V_5 ) ;
}
int F_105 ( struct V_1 * V_2 )
{
F_106 ( & V_2 -> V_70 , 64 ) ;
F_107 ( & V_2 -> V_35 ) ;
F_108 ( & V_2 -> V_69 ) ;
V_2 -> V_124 = true ;
V_2 -> V_113 = true ;
V_2 -> V_11 = 10 ;
V_2 -> F_18 = 30 ;
V_2 -> V_24 . V_27 = 1024 ;
V_2 -> V_20 = 5 ;
V_2 -> V_23 = 30 ;
V_2 -> V_21 = 6000 ;
V_2 -> V_125 = F_109 ( F_89 , V_2 ,
L_2 ) ;
if ( F_110 ( V_2 -> V_125 ) )
return F_111 ( V_2 -> V_125 ) ;
F_112 ( & V_2 -> V_34 , F_11 ) ;
F_17 ( & V_2 -> V_34 ,
V_2 -> V_20 * V_37 ) ;
return 0 ;
}
