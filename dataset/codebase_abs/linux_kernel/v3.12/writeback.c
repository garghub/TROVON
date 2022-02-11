static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
T_1 V_6 = V_4 -> V_7 * V_4 -> V_8 . V_9 ;
T_1 V_10 =
F_2 ( V_6 * V_2 -> V_11 , 100 ) ;
T_2 V_12 = F_3 ( V_10 * F_4 ( V_2 -> V_13 ) ,
V_4 -> V_14 ) ;
int V_15 = 0 ;
T_2 error ;
T_2 V_16 = F_5 ( & V_2 -> V_5 ) ;
T_2 V_17 = V_16 - V_2 -> V_5 . V_18 ;
V_2 -> V_5 . V_18 = V_16 ;
V_17 *= V_2 -> V_19 ;
V_17 = F_6 ( V_17 , - V_16 , V_16 ) ;
V_17 = F_7 ( V_2 -> V_5 . V_20 , V_17 ,
V_2 -> V_21 , 0 ) ;
if ( ! V_12 )
goto V_22;
error = F_8 ( ( V_16 + V_17 - V_12 ) << 8 , V_12 ) ;
V_15 = F_9 ( ( V_2 -> V_23 . V_24 * error ) >> 8 ,
V_2 -> V_25 ) ;
if ( V_15 > 0 &&
F_10 ( F_11 () ,
V_2 -> V_23 . V_26 + 10 * V_27 ) )
V_15 = 0 ;
V_2 -> V_23 . V_24 =
F_12 ( T_2 , V_2 -> V_23 . V_24 + V_15 ,
1 , V_27 ) ;
V_22:
V_2 -> V_28 = V_17 ;
V_2 -> V_29 = V_15 ;
V_2 -> V_30 = V_12 ;
F_13 ( & V_2 -> V_31 ,
V_2 -> V_32 * V_33 ) ;
}
static void F_14 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_15 ( F_16 ( V_35 ) ,
struct V_1 ,
V_31 ) ;
F_17 ( & V_2 -> V_36 ) ;
if ( F_18 ( & V_2 -> V_37 ) &&
V_2 -> V_11 )
F_1 ( V_2 ) ;
F_19 ( & V_2 -> V_36 ) ;
}
static unsigned F_20 ( struct V_1 * V_2 , unsigned V_38 )
{
T_1 V_39 ;
if ( F_18 ( & V_2 -> V_5 . V_40 ) ||
! V_2 -> V_11 )
return 0 ;
V_39 = F_21 ( & V_2 -> V_23 , V_38 * 10000000ULL ) ;
return F_22 ( T_1 , V_39 , V_33 ) ;
}
static bool F_23 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
return F_24 ( V_44 ) ;
}
static bool F_25 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
T_1 V_45 ;
unsigned V_46 = F_26 ( V_44 ) ;
struct V_1 * V_2 = F_15 ( V_42 , struct V_1 ,
V_47 ) ;
unsigned V_48 = 1 << V_2 -> V_5 . V_49 ;
if ( ! F_24 ( V_44 ) )
return false ;
V_45 = F_27 ( V_44 ) >> V_2 -> V_5 . V_49 ;
while ( 1 ) {
if ( F_18 ( V_2 -> V_5 . V_50 + V_45 ) !=
V_48 )
return false ;
if ( V_46 <= V_48 )
return true ;
V_46 -= V_48 ;
V_45 ++ ;
}
}
static void F_28 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_56 * V_56 = & V_54 -> V_56 ;
F_29 ( V_56 ) ;
if ( ! V_54 -> V_2 -> V_11 )
F_30 ( V_56 , F_31 ( V_57 , 0 ) ) ;
V_56 -> V_58 = F_26 ( & V_52 -> V_59 ) << 9 ;
V_56 -> V_60 = F_32 ( F_26 ( & V_52 -> V_59 ) , V_61 ) ;
V_56 -> V_62 = V_52 ;
V_56 -> V_63 = V_56 -> V_64 ;
F_33 ( V_56 , NULL ) ;
}
static void F_34 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_15 ( V_66 , struct V_1 ,
V_67 . V_66 ) ;
struct V_41 * V_42 = & V_2 -> V_47 ;
bool V_68 = false ;
struct V_43 V_69 = V_70 ;
F_35 ( & V_69 , V_2 -> V_5 . V_71 ) ;
if ( ! F_18 ( & V_2 -> V_5 . V_40 ) &&
! V_2 -> V_72 )
F_36 ( V_66 ) ;
F_37 ( & V_2 -> V_36 ) ;
if ( ! F_18 ( & V_2 -> V_37 ) ) {
F_38 ( & V_2 -> V_8 , V_73 ) ;
F_39 ( V_2 , NULL ) ;
F_40 ( & V_2 -> V_36 ) ;
F_36 ( V_66 ) ;
}
if ( F_41 ( & V_42 -> V_74 , & V_69 ) >= 0 ) {
V_42 -> V_74 = F_42 ( V_2 -> V_5 . V_71 , 0 , 0 ) ;
V_68 = true ;
}
if ( V_2 -> V_75 ) {
T_1 V_76 ;
for ( V_76 = 0 ; V_76 < V_2 -> V_5 . V_77 ; V_76 ++ )
if ( F_18 ( V_2 -> V_5 . V_50 + V_76 ) ==
1 << V_2 -> V_5 . V_49 )
goto V_78;
goto V_79;
V_78:
F_43 ( V_2 -> V_5 . V_4 , V_42 , & V_69 ,
F_25 ) ;
} else {
V_79:
F_43 ( V_2 -> V_5 . V_4 , V_42 , & V_69 , F_23 ) ;
}
if ( F_41 ( & V_42 -> V_74 , & V_69 ) >= 0 && V_68 ) {
if ( F_44 ( & V_42 -> V_80 ) ) {
F_45 ( & V_2 -> V_37 , 0 ) ;
F_46 ( V_2 ) ;
}
if ( ! F_18 ( & V_2 -> V_5 . V_40 ) )
F_47 ( & V_2 -> V_67 , V_2 -> F_20 * V_33 ) ;
}
F_40 ( & V_2 -> V_36 ) ;
F_48 ( & V_2 -> V_23 ) ;
F_49 ( V_66 , V_81 , V_82 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
if ( F_51 ( & V_2 -> V_67 . V_66 , & V_2 -> V_5 . V_66 ) ) {
if ( ! F_18 ( & V_2 -> V_5 . V_40 ) )
F_47 ( & V_2 -> V_67 , V_2 -> F_20 * V_33 ) ;
F_49 ( & V_2 -> V_67 . V_66 , F_34 , V_82 ) ;
}
}
void F_52 ( struct V_1 * V_2 )
{
if ( ! F_18 ( & V_2 -> V_37 ) &&
! F_53 ( & V_2 -> V_37 , 1 ) ) {
F_54 ( & V_2 -> V_83 ) ;
if ( F_55 ( & V_2 -> V_8 ) != V_84 ) {
F_38 ( & V_2 -> V_8 , V_84 ) ;
F_39 ( V_2 , NULL ) ;
}
F_50 ( V_2 ) ;
if ( V_2 -> V_11 )
F_13 ( & V_2 -> V_31 ,
V_2 -> V_32 * V_33 ) ;
}
}
void F_56 ( struct V_3 * V_4 , unsigned V_85 ,
T_1 V_86 , int V_46 )
{
struct V_87 * V_88 = V_4 -> V_89 [ V_85 ] ;
unsigned V_48 , V_90 ;
T_1 V_45 ;
if ( ! V_88 )
return;
V_48 = 1 << V_88 -> V_49 ;
V_45 = V_86 >> V_88 -> V_49 ;
V_90 = V_86 & ( V_48 - 1 ) ;
while ( V_46 ) {
int V_91 = F_22 ( unsigned , abs ( V_46 ) ,
V_48 - V_90 ) ;
if ( V_46 < 0 )
V_91 = - V_91 ;
F_57 ( V_91 , V_88 -> V_50 + V_45 ) ;
V_46 -= V_91 ;
V_90 = 0 ;
V_45 ++ ;
}
}
static void F_58 ( struct V_65 * V_66 )
{
struct V_53 * V_54 = F_15 ( V_66 , struct V_53 , V_66 ) ;
F_59 ( V_54 ) ;
}
static void F_60 ( struct V_65 * V_66 )
{
struct V_53 * V_54 = F_15 ( V_66 , struct V_53 , V_66 ) ;
struct V_51 * V_52 = V_54 -> V_56 . V_62 ;
struct V_1 * V_2 = V_54 -> V_2 ;
struct V_92 * V_93 ;
int V_76 ;
F_61 (bv, &io->bio, i)
F_62 ( V_93 -> V_94 ) ;
if ( F_24 ( & V_52 -> V_59 ) ) {
unsigned V_76 ;
struct V_95 V_96 ;
F_63 ( & V_96 ) ;
V_96 . type = V_97 ;
F_64 ( & V_96 . V_98 , & V_52 -> V_59 ) ;
F_65 ( & V_52 -> V_59 , false ) ;
F_66 ( & V_96 . V_80 , & V_52 -> V_59 ) ;
for ( V_76 = 0 ; V_76 < F_67 ( & V_52 -> V_59 ) ; V_76 ++ )
F_54 ( & F_68 ( V_2 -> V_5 . V_4 , & V_52 -> V_59 , V_76 ) -> V_99 ) ;
F_69 ( & V_96 , V_2 -> V_5 . V_4 ) ;
F_70 ( & V_96 . V_66 ) ;
if ( V_96 . V_100 )
F_71 ( & V_52 -> V_59 ) ;
F_72 ( V_96 . V_100
? & V_2 -> V_5 . V_4 -> V_101
: & V_2 -> V_5 . V_4 -> V_102 ) ;
}
F_73 ( & V_2 -> V_47 , V_52 ) ;
F_74 ( & V_2 -> V_103 ) ;
F_75 ( V_66 , F_58 ) ;
}
static void F_76 ( struct V_56 * V_56 , int error )
{
struct V_51 * V_52 = V_56 -> V_62 ;
struct V_53 * V_54 = V_52 -> V_55 ;
if ( error )
F_65 ( & V_52 -> V_59 , false ) ;
F_77 ( & V_54 -> V_66 ) ;
}
static void F_78 ( struct V_65 * V_66 )
{
struct V_53 * V_54 = F_15 ( V_66 , struct V_53 , V_66 ) ;
struct V_51 * V_52 = V_54 -> V_56 . V_62 ;
F_28 ( V_52 ) ;
V_54 -> V_56 . V_104 = V_105 ;
V_54 -> V_56 . V_106 = F_27 ( & V_52 -> V_59 ) ;
V_54 -> V_56 . V_107 = V_54 -> V_2 -> V_13 ;
V_54 -> V_56 . V_108 = F_76 ;
F_79 ( & V_54 -> V_56 , V_66 , & V_54 -> V_2 -> V_5 ) ;
F_49 ( V_66 , F_60 , V_109 ) ;
}
static void F_80 ( struct V_56 * V_56 , int error )
{
struct V_51 * V_52 = V_56 -> V_62 ;
struct V_53 * V_54 = V_52 -> V_55 ;
F_81 ( F_82 ( V_54 -> V_2 -> V_5 . V_4 , & V_52 -> V_59 , 0 ) ,
error , L_1 ) ;
F_76 ( V_56 , error ) ;
}
static void F_83 ( struct V_65 * V_66 )
{
struct V_53 * V_54 = F_15 ( V_66 , struct V_53 , V_66 ) ;
F_79 ( & V_54 -> V_56 , V_66 , & V_54 -> V_2 -> V_5 ) ;
F_49 ( V_66 , F_78 , V_109 ) ;
}
static void V_81 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_15 ( V_66 , struct V_1 ,
V_67 . V_66 ) ;
unsigned V_110 = F_20 ( V_2 , 0 ) ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
while ( 1 ) {
V_52 = F_84 ( & V_2 -> V_47 ) ;
if ( ! V_52 )
break;
F_85 ( F_86 ( V_2 -> V_5 . V_4 , & V_52 -> V_59 , 0 ) ) ;
if ( V_110 > 0 &&
( F_27 ( & V_52 -> V_59 ) != V_2 -> V_111 ||
F_87 ( V_110 ) > 50 ) )
V_110 = F_88 ( V_110 ) ;
V_2 -> V_111 = F_89 ( & V_52 -> V_59 ) ;
V_54 = F_90 ( sizeof( struct V_53 ) + sizeof( struct V_92 )
* F_32 ( F_26 ( & V_52 -> V_59 ) , V_61 ) ,
V_112 ) ;
if ( ! V_54 )
goto V_113;
V_52 -> V_55 = V_54 ;
V_54 -> V_2 = V_2 ;
F_28 ( V_52 ) ;
V_54 -> V_56 . V_106 = F_91 ( & V_52 -> V_59 , 0 ) ;
V_54 -> V_56 . V_107 = F_82 ( V_2 -> V_5 . V_4 ,
& V_52 -> V_59 , 0 ) -> V_13 ;
V_54 -> V_56 . V_104 = V_114 ;
V_54 -> V_56 . V_108 = F_80 ;
if ( F_92 ( & V_54 -> V_56 , V_112 ) )
goto V_115;
F_93 ( & V_52 -> V_59 ) ;
F_94 ( & V_2 -> V_103 ) ;
F_95 ( & V_54 -> V_66 , F_83 , NULL , V_66 ) ;
V_110 = F_20 ( V_2 , F_26 ( & V_52 -> V_59 ) ) ;
}
if ( 0 ) {
V_115:
F_59 ( V_52 -> V_55 ) ;
V_113:
F_73 ( & V_2 -> V_47 , V_52 ) ;
}
F_49 ( V_66 , F_34 , V_82 ) ;
}
static int F_96 ( struct V_116 * V_117 , struct V_95 * V_96 ,
struct V_1 * V_2 )
{
struct V_43 * V_44 ;
struct V_118 V_119 ;
F_97 ( V_117 , & V_119 , & F_42 ( V_2 -> V_5 . V_71 , 0 , 0 ) ) ;
while ( ( V_44 = F_98 ( & V_119 , V_117 , V_120 ) ) )
if ( ! V_117 -> V_121 ) {
if ( F_99 ( V_44 ) > V_2 -> V_5 . V_71 )
break;
if ( F_24 ( V_44 ) )
F_56 ( V_117 -> V_4 , V_2 -> V_5 . V_71 ,
F_27 ( V_44 ) ,
F_26 ( V_44 ) ) ;
} else {
V_116 ( V_122 , V_44 , V_117 , V_96 , V_2 ) ;
if ( F_99 ( V_44 ) > V_2 -> V_5 . V_71 )
break;
F_100 () ;
}
return 0 ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_95 V_96 ;
F_63 ( & V_96 ) ;
F_102 ( V_122 , V_2 -> V_5 . V_4 , & V_96 , V_2 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_104 ( & V_2 -> V_103 , 64 ) ;
F_105 ( & V_2 -> V_67 ) ;
F_106 ( & V_2 -> V_36 ) ;
F_107 ( & V_2 -> V_47 ) ;
V_2 -> V_123 = true ;
V_2 -> V_72 = true ;
V_2 -> V_11 = 10 ;
V_2 -> F_20 = 30 ;
V_2 -> V_23 . V_24 = 1024 ;
V_2 -> V_32 = 30 ;
V_2 -> V_19 = 16 ;
V_2 -> V_25 = 64 ;
V_2 -> V_21 = 8 ;
F_108 ( & V_2 -> V_31 , F_14 ) ;
F_13 ( & V_2 -> V_31 ,
V_2 -> V_32 * V_33 ) ;
}
void F_109 ( void )
{
if ( V_82 )
F_110 ( V_82 ) ;
}
int T_3 F_111 ( void )
{
V_82 = F_112 ( L_2 ) ;
if ( ! V_82 )
return - V_124 ;
return 0 ;
}
