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
if ( F_18 ( & V_2 -> V_5 . V_39 ) ||
! V_2 -> V_11 )
return 0 ;
return F_21 ( & V_2 -> V_23 , V_38 * 10000000ULL ) ;
}
static bool F_22 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
return F_23 ( V_43 ) ;
}
static bool F_24 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
T_1 V_44 ;
unsigned V_45 = F_25 ( V_43 ) ;
struct V_1 * V_2 = F_15 ( V_41 , struct V_1 ,
V_46 ) ;
unsigned V_47 = 1 << V_2 -> V_5 . V_48 ;
if ( ! F_23 ( V_43 ) )
return false ;
V_44 = F_26 ( V_43 ) >> V_2 -> V_5 . V_48 ;
while ( 1 ) {
if ( F_18 ( V_2 -> V_5 . V_49 + V_44 ) !=
V_47 )
return false ;
if ( V_45 <= V_47 )
return true ;
V_45 -= V_47 ;
V_44 ++ ;
}
}
static void F_27 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_54 ;
struct V_55 * V_55 = & V_53 -> V_55 ;
F_28 ( V_55 ) ;
if ( ! V_53 -> V_2 -> V_11 )
F_29 ( V_55 , F_30 ( V_56 , 0 ) ) ;
V_55 -> V_57 = F_25 ( & V_51 -> V_58 ) << 9 ;
V_55 -> V_59 = F_31 ( F_25 ( & V_51 -> V_58 ) , V_60 ) ;
V_55 -> V_61 = V_51 ;
V_55 -> V_62 = V_55 -> V_63 ;
F_32 ( V_55 , NULL ) ;
}
static void F_33 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_15 ( V_65 , struct V_1 ,
V_66 . V_65 ) ;
struct V_40 * V_41 = & V_2 -> V_46 ;
bool V_67 = false ;
struct V_42 V_68 = V_69 ;
F_34 ( & V_68 , V_2 -> V_5 . V_70 ) ;
if ( ! F_18 ( & V_2 -> V_5 . V_39 ) &&
! V_2 -> V_71 )
F_35 ( V_65 ) ;
F_36 ( & V_2 -> V_36 ) ;
if ( ! F_18 ( & V_2 -> V_37 ) ) {
F_37 ( & V_2 -> V_8 , V_72 ) ;
F_38 ( V_2 , NULL ) ;
F_39 ( & V_2 -> V_36 ) ;
F_35 ( V_65 ) ;
}
if ( F_40 ( & V_41 -> V_73 , & V_68 ) >= 0 ) {
V_41 -> V_73 = F_41 ( V_2 -> V_5 . V_70 , 0 , 0 ) ;
V_67 = true ;
}
if ( V_2 -> V_74 ) {
T_1 V_75 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_5 . V_76 ; V_75 ++ )
if ( F_18 ( V_2 -> V_5 . V_49 + V_75 ) ==
1 << V_2 -> V_5 . V_48 )
goto V_77;
goto V_78;
V_77:
F_42 ( V_2 -> V_5 . V_4 , V_41 , & V_68 ,
F_24 ) ;
} else {
V_78:
F_42 ( V_2 -> V_5 . V_4 , V_41 , & V_68 , F_22 ) ;
}
if ( F_40 ( & V_41 -> V_73 , & V_68 ) >= 0 && V_67 ) {
if ( F_43 ( & V_41 -> V_79 ) ) {
F_44 ( & V_2 -> V_37 , 0 ) ;
F_45 ( V_2 ) ;
}
if ( ! F_18 ( & V_2 -> V_5 . V_39 ) )
F_46 ( & V_2 -> V_66 , V_2 -> F_20 * V_33 ) ;
}
F_39 ( & V_2 -> V_36 ) ;
F_47 ( & V_2 -> V_23 ) ;
F_48 ( V_65 , V_80 , V_81 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
if ( F_50 ( & V_2 -> V_66 . V_65 , & V_2 -> V_5 . V_65 ) ) {
if ( ! F_18 ( & V_2 -> V_5 . V_39 ) )
F_46 ( & V_2 -> V_66 , V_2 -> F_20 * V_33 ) ;
F_48 ( & V_2 -> V_66 . V_65 , F_33 , V_81 ) ;
}
}
void F_51 ( struct V_1 * V_2 )
{
if ( ! F_18 ( & V_2 -> V_37 ) &&
! F_52 ( & V_2 -> V_37 , 1 ) ) {
F_53 ( & V_2 -> V_82 ) ;
if ( F_54 ( & V_2 -> V_8 ) != V_83 ) {
F_37 ( & V_2 -> V_8 , V_83 ) ;
F_38 ( V_2 , NULL ) ;
}
F_49 ( V_2 ) ;
if ( V_2 -> V_11 )
F_13 ( & V_2 -> V_31 ,
V_2 -> V_32 * V_33 ) ;
}
}
void F_55 ( struct V_3 * V_4 , unsigned V_84 ,
T_1 V_85 , int V_45 )
{
struct V_86 * V_87 = V_4 -> V_88 [ V_84 ] ;
unsigned V_47 , V_89 ;
T_1 V_44 ;
if ( ! V_87 )
return;
V_47 = 1 << V_87 -> V_48 ;
V_44 = V_85 >> V_87 -> V_48 ;
V_89 = V_85 & ( V_47 - 1 ) ;
while ( V_45 ) {
int V_90 = F_56 ( unsigned , abs ( V_45 ) ,
V_47 - V_89 ) ;
if ( V_45 < 0 )
V_90 = - V_90 ;
F_57 ( V_90 , V_87 -> V_49 + V_44 ) ;
V_45 -= V_90 ;
V_89 = 0 ;
V_44 ++ ;
}
}
static void F_58 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = F_15 ( V_65 , struct V_52 , V_65 ) ;
F_59 ( V_53 ) ;
}
static void F_60 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = F_15 ( V_65 , struct V_52 , V_65 ) ;
struct V_50 * V_51 = V_53 -> V_55 . V_61 ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_91 * V_92 ;
int V_75 ;
F_61 (bv, &io->bio, i)
F_62 ( V_92 -> V_93 ) ;
if ( F_23 ( & V_51 -> V_58 ) ) {
unsigned V_75 ;
struct V_94 V_95 ;
F_63 ( & V_95 ) ;
V_95 . type = V_96 ;
F_64 ( & V_95 . V_97 , & V_51 -> V_58 ) ;
F_65 ( & V_51 -> V_58 , false ) ;
F_66 ( & V_95 . V_79 , & V_51 -> V_58 ) ;
for ( V_75 = 0 ; V_75 < F_67 ( & V_51 -> V_58 ) ; V_75 ++ )
F_53 ( & F_68 ( V_2 -> V_5 . V_4 , & V_51 -> V_58 , V_75 ) -> V_98 ) ;
F_69 ( & V_95 , V_2 -> V_5 . V_4 ) ;
F_70 ( & V_95 . V_65 ) ;
if ( V_95 . V_99 )
F_71 ( & V_51 -> V_58 ) ;
F_72 ( V_95 . V_99
? & V_2 -> V_5 . V_4 -> V_100
: & V_2 -> V_5 . V_4 -> V_101 ) ;
}
F_73 ( & V_2 -> V_46 , V_51 ) ;
F_74 ( & V_2 -> V_102 ) ;
F_75 ( & V_2 -> V_103 ) ;
F_76 ( V_65 , F_58 ) ;
}
static void F_77 ( struct V_55 * V_55 , int error )
{
struct V_50 * V_51 = V_55 -> V_61 ;
struct V_52 * V_53 = V_51 -> V_54 ;
if ( error )
F_65 ( & V_51 -> V_58 , false ) ;
F_78 ( & V_53 -> V_65 ) ;
}
static void F_79 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = F_15 ( V_65 , struct V_52 , V_65 ) ;
struct V_50 * V_51 = V_53 -> V_55 . V_61 ;
F_27 ( V_51 ) ;
V_53 -> V_55 . V_104 = V_105 ;
V_53 -> V_55 . V_106 = F_26 ( & V_51 -> V_58 ) ;
V_53 -> V_55 . V_107 = V_53 -> V_2 -> V_13 ;
V_53 -> V_55 . V_108 = F_77 ;
F_80 ( & V_53 -> V_55 , V_65 , & V_53 -> V_2 -> V_5 ) ;
F_48 ( V_65 , F_60 , V_81 ) ;
}
static void F_81 ( struct V_55 * V_55 , int error )
{
struct V_50 * V_51 = V_55 -> V_61 ;
struct V_52 * V_53 = V_51 -> V_54 ;
F_82 ( F_83 ( V_53 -> V_2 -> V_5 . V_4 , & V_51 -> V_58 , 0 ) ,
error , L_1 ) ;
F_77 ( V_55 , error ) ;
}
static void F_84 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = F_15 ( V_65 , struct V_52 , V_65 ) ;
F_80 ( & V_53 -> V_55 , V_65 , & V_53 -> V_2 -> V_5 ) ;
F_48 ( V_65 , F_79 , V_81 ) ;
}
static void V_80 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_15 ( V_65 , struct V_1 ,
V_66 . V_65 ) ;
unsigned V_109 = F_20 ( V_2 , 0 ) ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
while ( 1 ) {
V_51 = F_85 ( & V_2 -> V_46 ) ;
if ( ! V_51 )
break;
F_86 ( F_87 ( V_2 -> V_5 . V_4 , & V_51 -> V_58 , 0 ) ) ;
if ( V_109 > 0 &&
( F_26 ( & V_51 -> V_58 ) != V_2 -> V_110 ||
F_88 ( V_109 ) > 50 ) ) {
V_51 -> V_54 = NULL ;
F_46 ( & V_2 -> V_66 , V_109 ) ;
F_48 ( V_65 , V_80 , V_81 ) ;
}
V_2 -> V_110 = F_89 ( & V_51 -> V_58 ) ;
V_53 = F_90 ( sizeof( struct V_52 ) + sizeof( struct V_91 )
* F_31 ( F_25 ( & V_51 -> V_58 ) , V_60 ) ,
V_111 ) ;
if ( ! V_53 )
goto V_112;
V_51 -> V_54 = V_53 ;
V_53 -> V_2 = V_2 ;
F_27 ( V_51 ) ;
V_53 -> V_55 . V_106 = F_91 ( & V_51 -> V_58 , 0 ) ;
V_53 -> V_55 . V_107 = F_83 ( V_2 -> V_5 . V_4 ,
& V_51 -> V_58 , 0 ) -> V_13 ;
V_53 -> V_55 . V_104 = V_113 ;
V_53 -> V_55 . V_108 = F_81 ;
if ( F_92 ( & V_53 -> V_55 , V_111 ) )
goto V_114;
F_93 ( & V_51 -> V_58 ) ;
F_94 ( & V_53 -> V_65 , F_84 , NULL , & V_2 -> V_5 . V_65 ) ;
V_109 = F_20 ( V_2 , F_25 ( & V_51 -> V_58 ) ) ;
F_53 ( & V_2 -> V_102 ) ;
if ( ! F_95 ( & V_2 -> V_103 , V_65 ,
F_18 ( & V_2 -> V_102 ) < 64 ) )
F_48 ( V_65 , V_80 , V_81 ) ;
}
if ( 0 ) {
V_114:
F_59 ( V_51 -> V_54 ) ;
V_112:
F_73 ( & V_2 -> V_46 , V_51 ) ;
}
F_33 ( V_65 ) ;
}
static int F_96 ( struct V_115 * V_116 , struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 ;
struct V_117 V_118 ;
F_97 ( V_116 , & V_118 , & F_41 ( V_2 -> V_5 . V_70 , 0 , 0 ) ) ;
while ( ( V_43 = F_98 ( & V_118 , V_116 , V_119 ) ) )
if ( ! V_116 -> V_120 ) {
if ( F_99 ( V_43 ) > V_2 -> V_5 . V_70 )
break;
if ( F_23 ( V_43 ) )
F_55 ( V_116 -> V_4 , V_2 -> V_5 . V_70 ,
F_26 ( V_43 ) ,
F_25 ( V_43 ) ) ;
} else {
V_115 ( V_121 , V_43 , V_116 , V_95 , V_2 ) ;
if ( F_99 ( V_43 ) > V_2 -> V_5 . V_70 )
break;
F_100 () ;
}
return 0 ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_94 V_95 ;
F_63 ( & V_95 ) ;
F_102 ( V_121 , V_2 -> V_5 . V_4 , & V_95 , V_2 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_104 ( & V_2 -> V_66 ) ;
F_105 ( & V_2 -> V_36 ) ;
F_106 ( & V_2 -> V_46 ) ;
V_2 -> V_122 = true ;
V_2 -> V_71 = true ;
V_2 -> V_11 = 10 ;
V_2 -> F_20 = 30 ;
V_2 -> V_23 . V_24 = 1024 ;
V_2 -> V_32 = 30 ;
V_2 -> V_19 = 16 ;
V_2 -> V_25 = 64 ;
V_2 -> V_21 = 8 ;
F_107 ( & V_2 -> V_31 , F_14 ) ;
F_13 ( & V_2 -> V_31 ,
V_2 -> V_32 * V_33 ) ;
}
void F_108 ( void )
{
if ( V_81 )
F_109 ( V_81 ) ;
}
int T_3 F_110 ( void )
{
V_81 = F_111 ( L_2 ) ;
if ( ! V_81 )
return - V_123 ;
return 0 ;
}
