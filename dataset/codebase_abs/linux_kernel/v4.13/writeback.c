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
F_22 ( V_46 , V_46 -> V_47 ,
F_23 ( F_24 ( & V_42 -> V_48 ) , V_49 ) ) ;
if ( ! V_44 -> V_2 -> V_11 )
F_25 ( V_46 , F_26 ( V_50 , 0 ) ) ;
V_46 -> V_51 . V_52 = F_24 ( & V_42 -> V_48 ) << 9 ;
V_46 -> V_53 = V_42 ;
F_27 ( V_46 , NULL ) ;
}
static void F_28 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = F_12 ( V_55 , struct V_43 , V_55 ) ;
F_29 ( V_44 ) ;
}
static void F_30 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = F_12 ( V_55 , struct V_43 , V_55 ) ;
struct V_41 * V_42 = V_44 -> V_46 . V_53 ;
struct V_1 * V_2 = V_44 -> V_2 ;
F_31 ( & V_44 -> V_46 ) ;
if ( F_32 ( & V_42 -> V_48 ) ) {
int V_56 ;
unsigned V_57 ;
struct V_58 V_59 ;
F_33 ( & V_59 ) ;
F_34 ( V_59 . V_60 , & V_42 -> V_48 ) ;
F_35 ( V_59 . V_60 , false ) ;
F_36 ( & V_59 ) ;
for ( V_57 = 0 ; V_57 < F_37 ( & V_42 -> V_48 ) ; V_57 ++ )
F_38 ( & F_39 ( V_2 -> V_5 . V_4 , & V_42 -> V_48 , V_57 ) -> V_61 ) ;
V_56 = F_40 ( V_2 -> V_5 . V_4 , & V_59 , NULL , & V_42 -> V_48 ) ;
if ( V_56 )
F_41 ( & V_42 -> V_48 ) ;
F_42 ( V_56
? & V_2 -> V_5 . V_4 -> V_62
: & V_2 -> V_5 . V_4 -> V_63 ) ;
}
F_43 ( & V_2 -> V_64 , V_42 ) ;
F_44 ( & V_2 -> V_65 ) ;
F_45 ( V_55 , F_28 ) ;
}
static void F_46 ( struct V_46 * V_46 )
{
struct V_41 * V_42 = V_46 -> V_53 ;
struct V_43 * V_44 = V_42 -> V_45 ;
if ( V_46 -> V_66 )
F_35 ( & V_42 -> V_48 , false ) ;
F_47 ( & V_44 -> V_55 ) ;
}
static void F_48 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = F_12 ( V_55 , struct V_43 , V_55 ) ;
struct V_41 * V_42 = V_44 -> V_46 . V_53 ;
F_21 ( V_42 ) ;
F_49 ( & V_44 -> V_46 , V_67 , 0 ) ;
V_44 -> V_46 . V_51 . V_68 = F_50 ( & V_42 -> V_48 ) ;
V_44 -> V_46 . V_69 = V_44 -> V_2 -> V_13 ;
V_44 -> V_46 . V_70 = F_46 ;
F_51 ( & V_44 -> V_46 , V_55 ) ;
F_52 ( V_55 , F_30 , V_71 ) ;
}
static void F_53 ( struct V_46 * V_46 )
{
struct V_41 * V_42 = V_46 -> V_53 ;
struct V_43 * V_44 = V_42 -> V_45 ;
F_54 ( F_55 ( V_44 -> V_2 -> V_5 . V_4 , & V_42 -> V_48 , 0 ) ,
V_46 -> V_66 , L_1 ) ;
F_46 ( V_46 ) ;
}
static void F_56 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = F_12 ( V_55 , struct V_43 , V_55 ) ;
F_51 ( & V_44 -> V_46 , V_55 ) ;
F_52 ( V_55 , F_48 , V_71 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned V_72 = 0 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_54 V_55 ;
F_58 ( & V_55 ) ;
while ( ! F_59 () ) {
V_42 = F_60 ( & V_2 -> V_64 ) ;
if ( ! V_42 )
break;
F_61 ( F_62 ( V_2 -> V_5 . V_4 , & V_42 -> V_48 , 0 ) ) ;
if ( F_50 ( & V_42 -> V_48 ) != V_2 -> V_73 ||
F_63 ( V_72 ) > 50 )
while ( ! F_59 () && V_72 )
V_72 = F_64 ( V_72 ) ;
V_2 -> V_73 = F_65 ( & V_42 -> V_48 ) ;
V_44 = F_66 ( sizeof( struct V_43 ) + sizeof( struct V_74 )
* F_23 ( F_24 ( & V_42 -> V_48 ) , V_49 ) ,
V_75 ) ;
if ( ! V_44 )
goto V_76;
V_42 -> V_45 = V_44 ;
V_44 -> V_2 = V_2 ;
F_21 ( V_42 ) ;
F_49 ( & V_44 -> V_46 , V_77 , 0 ) ;
V_44 -> V_46 . V_51 . V_68 = F_67 ( & V_42 -> V_48 , 0 ) ;
V_44 -> V_46 . V_69 = F_55 ( V_2 -> V_5 . V_4 ,
& V_42 -> V_48 , 0 ) -> V_13 ;
V_44 -> V_46 . V_70 = F_53 ;
if ( F_68 ( & V_44 -> V_46 , V_75 ) )
goto V_78;
F_69 ( & V_42 -> V_48 ) ;
F_70 ( & V_2 -> V_65 ) ;
F_71 ( & V_44 -> V_55 , F_56 , NULL , & V_55 ) ;
V_72 = F_18 ( V_2 , F_24 ( & V_42 -> V_48 ) ) ;
}
if ( 0 ) {
V_78:
F_29 ( V_42 -> V_45 ) ;
V_76:
F_43 ( & V_2 -> V_64 , V_42 ) ;
}
F_72 ( & V_55 ) ;
}
void F_73 ( struct V_3 * V_4 , unsigned V_79 ,
T_1 V_80 , int V_81 )
{
struct V_82 * V_83 = V_4 -> V_84 [ V_79 ] ;
unsigned V_85 , V_86 , V_87 ;
if ( ! V_83 )
return;
V_86 = F_74 ( V_83 , V_80 ) ;
V_85 = V_80 & ( V_83 -> V_88 - 1 ) ;
while ( V_81 ) {
int V_89 = F_75 ( unsigned , abs ( V_81 ) ,
V_83 -> V_88 - V_85 ) ;
if ( V_81 < 0 )
V_89 = - V_89 ;
if ( V_86 >= V_83 -> V_90 )
return;
V_87 = F_76 ( V_89 ,
V_83 -> V_91 + V_86 ) ;
if ( V_87 == V_83 -> V_88 )
F_77 ( V_86 , V_83 -> V_92 ) ;
else
F_78 ( V_86 , V_83 -> V_92 ) ;
V_81 -= V_89 ;
V_85 = 0 ;
V_86 ++ ;
}
}
static bool F_79 ( struct V_93 * V_94 , struct V_95 * V_96 )
{
struct V_1 * V_2 = F_12 ( V_94 , struct V_1 , V_64 ) ;
F_61 ( F_80 ( V_96 ) != V_2 -> V_5 . V_97 ) ;
return F_32 ( V_96 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = & V_2 -> V_64 ;
unsigned V_98 , V_86 , V_99 ;
bool V_100 = false ;
V_86 = F_74 ( & V_2 -> V_5 , F_65 ( & V_94 -> V_101 ) ) ;
if ( V_86 >= V_2 -> V_5 . V_90 )
V_86 = 0 ;
V_98 = V_86 ;
while ( 1 ) {
V_86 = F_82 ( V_2 -> V_5 . V_92 ,
V_2 -> V_5 . V_90 , V_86 ) ;
if ( V_86 == V_2 -> V_5 . V_90 )
goto V_25;
V_99 = F_83 ( V_2 -> V_5 . V_92 ,
V_2 -> V_5 . V_90 , V_86 ) ;
V_94 -> V_101 = F_84 ( V_2 -> V_5 . V_97 ,
V_86 * V_2 -> V_5 . V_88 , 0 ) ;
F_85 ( V_2 -> V_5 . V_4 , V_94 ,
& F_84 ( V_2 -> V_5 . V_97 ,
V_99 * V_2 -> V_5 . V_88 , 0 ) ,
F_79 ) ;
if ( F_86 ( & V_94 -> V_102 ) )
return;
V_86 = V_99 ;
V_25:
if ( V_100 && V_86 > V_98 )
return;
if ( V_86 == V_2 -> V_5 . V_90 ) {
V_86 = 0 ;
V_100 = true ;
}
}
}
static bool F_87 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = & V_2 -> V_64 ;
struct V_95 V_103 = F_84 ( V_2 -> V_5 . V_97 , 0 , 0 ) ;
struct V_95 V_104 = F_84 ( V_2 -> V_5 . V_97 , V_105 , 0 ) ;
struct V_95 V_106 ;
if ( F_88 ( & V_94 -> V_101 , & V_103 ) < 0 ||
F_88 ( & V_94 -> V_101 , & V_104 ) > 0 )
V_94 -> V_101 = V_103 ;
if ( V_2 -> V_107 ) {
F_81 ( V_2 ) ;
if ( F_86 ( & V_94 -> V_102 ) )
return false ;
}
V_106 = V_94 -> V_101 ;
F_85 ( V_2 -> V_5 . V_4 , V_94 , & V_104 , F_79 ) ;
if ( F_88 ( & V_94 -> V_101 , & V_104 ) < 0 )
return false ;
V_94 -> V_101 = V_103 ;
F_85 ( V_2 -> V_5 . V_4 , V_94 , & V_106 , F_79 ) ;
return F_88 ( & V_94 -> V_101 , & V_106 ) >= 0 ;
}
static int F_89 ( void * V_108 )
{
struct V_1 * V_2 = V_108 ;
bool V_109 ;
while ( ! F_59 () ) {
F_90 ( & V_2 -> V_35 ) ;
if ( ! F_15 ( & V_2 -> V_36 ) ||
( ! F_19 ( V_39 , & V_2 -> V_5 . V_40 ) &&
! V_2 -> V_110 ) ) {
F_91 ( & V_2 -> V_35 ) ;
F_92 ( V_111 ) ;
if ( F_59 () )
return 0 ;
F_93 () ;
continue;
}
V_109 = F_87 ( V_2 ) ;
if ( V_109 &&
F_94 ( & V_2 -> V_64 . V_59 ) ) {
F_95 ( & V_2 -> V_36 , 0 ) ;
F_96 ( V_2 ) ;
F_97 ( & V_2 -> V_8 , V_112 ) ;
F_98 ( V_2 , NULL ) ;
}
F_91 ( & V_2 -> V_35 ) ;
F_99 ( & V_2 -> V_24 ) ;
F_57 ( V_2 ) ;
if ( V_109 ) {
unsigned V_72 = V_2 -> F_18 * V_37 ;
while ( V_72 &&
! F_59 () &&
! F_19 ( V_39 , & V_2 -> V_5 . V_40 ) )
V_72 = F_64 ( V_72 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_113 * V_114 , struct V_115 * V_116 ,
struct V_95 * V_96 )
{
struct V_117 * V_118 = F_12 ( V_114 ,
struct V_117 , V_118 ) ;
if ( F_80 ( V_96 ) > V_118 -> V_79 )
return V_119 ;
if ( F_32 ( V_96 ) )
F_73 ( V_116 -> V_4 , F_80 ( V_96 ) ,
F_50 ( V_96 ) , F_24 ( V_96 ) ) ;
return V_120 ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_117 V_118 ;
F_102 ( & V_118 . V_118 , - 1 ) ;
V_118 . V_79 = V_2 -> V_5 . V_97 ;
F_103 ( & V_118 . V_118 , V_2 -> V_5 . V_4 , & F_84 ( V_118 . V_79 , 0 , 0 ) ,
F_100 , 0 ) ;
V_2 -> V_5 . V_17 = F_5 ( & V_2 -> V_5 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_65 , 64 ) ;
F_106 ( & V_2 -> V_35 ) ;
F_107 ( & V_2 -> V_64 ) ;
V_2 -> V_121 = true ;
V_2 -> V_110 = true ;
V_2 -> V_11 = 10 ;
V_2 -> F_18 = 30 ;
V_2 -> V_24 . V_27 = 1024 ;
V_2 -> V_20 = 5 ;
V_2 -> V_23 = 30 ;
V_2 -> V_21 = 6000 ;
F_108 ( & V_2 -> V_34 , F_11 ) ;
}
int F_109 ( struct V_1 * V_2 )
{
V_2 -> V_122 = F_110 ( F_89 , V_2 ,
L_2 ) ;
if ( F_111 ( V_2 -> V_122 ) )
return F_112 ( V_2 -> V_122 ) ;
F_17 ( & V_2 -> V_34 ,
V_2 -> V_20 * V_37 ) ;
F_113 ( V_2 ) ;
return 0 ;
}
