void
F_1 (
T_1 * V_1 ,
T_2 * V_2 )
{
int V_3 ;
int V_4 ;
T_3 * V_5 ;
V_4 = V_1 -> V_6 >> V_1 -> V_7 . V_8 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_5 = F_2 ( V_2 , V_3 * V_1 -> V_7 . V_9 ) ;
if ( ! V_5 -> V_10 ) {
F_3 ( V_1 ,
L_1 ,
V_3 , ( long long ) V_2 -> V_11 ) ;
}
}
}
bool
F_4 (
struct V_12 * V_1 ,
T_4 V_13 )
{
if ( F_5 ( & V_1 -> V_7 ) )
return V_13 == 3 ;
return V_13 == 1 || V_13 == 2 ;
}
static void
F_6 (
struct V_14 * V_2 ,
bool V_15 )
{
struct V_12 * V_1 = V_2 -> V_16 -> V_17 ;
int V_3 ;
int V_18 ;
V_18 = F_7 ( V_1 , V_2 -> V_19 ) * V_1 -> V_7 . V_20 ;
for ( V_3 = 0 ; V_3 < V_18 ; V_3 ++ ) {
int V_21 ;
T_3 * V_5 ;
V_5 = F_2 ( V_2 , ( V_3 << V_1 -> V_7 . V_8 ) ) ;
V_21 = V_5 -> V_22 == F_8 ( V_23 ) &&
F_4 ( V_1 , V_5 -> V_24 ) ;
if ( F_9 ( F_10 ( ! V_21 , V_1 ,
V_25 ) ) ) {
if ( V_15 ) {
V_2 -> V_26 &= ~ V_27 ;
F_11 ( V_2 , - V_28 ) ;
return;
}
F_11 ( V_2 , - V_29 ) ;
F_12 ( V_2 ) ;
#ifdef F_13
F_3 ( V_1 ,
L_2 ,
( unsigned long long ) V_2 -> V_11 , V_3 ,
F_14 ( V_5 -> V_22 ) ) ;
#endif
}
}
F_1 ( V_1 , V_2 ) ;
}
static void
F_15 (
struct V_14 * V_2 )
{
F_6 ( V_2 , false ) ;
}
static void
F_16 (
struct V_14 * V_2 )
{
F_6 ( V_2 , true ) ;
}
static void
F_17 (
struct V_14 * V_2 )
{
F_6 ( V_2 , false ) ;
}
int
F_18 (
struct V_12 * V_1 ,
struct V_30 * V_31 ,
struct V_32 * V_33 ,
struct V_34 * * V_35 ,
struct V_14 * * V_36 ,
T_5 V_37 ,
T_5 V_38 )
{
struct V_14 * V_2 ;
int error ;
V_37 |= V_39 ;
error = F_19 ( V_1 , V_31 , V_1 -> V_40 , V_33 -> V_41 ,
( int ) V_33 -> V_42 , V_37 , & V_2 ,
& V_43 ) ;
if ( error ) {
if ( error == - V_44 ) {
ASSERT ( V_37 & V_45 ) ;
return error ;
}
if ( error == - V_29 &&
( V_38 & V_46 ) )
return - V_47 ;
F_20 ( V_1 , L_3 ,
V_48 , error ) ;
return error ;
}
* V_36 = V_2 ;
* V_35 = F_2 ( V_2 , V_33 -> V_49 ) ;
return 0 ;
}
void
F_21 (
struct V_50 * V_51 ,
struct V_34 * V_52 )
{
struct V_53 * V_54 = & V_51 -> V_55 ;
struct V_56 * V_56 = F_22 ( V_51 ) ;
V_54 -> V_24 = V_52 -> V_24 ;
if ( V_54 -> V_24 == 1 ) {
F_23 ( V_56 , F_14 ( V_52 -> V_57 ) ) ;
V_54 -> V_58 = 0 ;
V_54 -> V_59 = 0 ;
V_54 -> V_24 = 2 ;
} else {
F_23 ( V_56 , F_24 ( V_52 -> V_60 ) ) ;
V_54 -> V_58 = F_14 ( V_52 -> V_58 ) ;
V_54 -> V_59 = F_14 ( V_52 -> V_59 ) ;
}
V_54 -> V_61 = V_52 -> V_61 ;
V_54 -> V_62 = F_24 ( V_52 -> V_62 ) ;
V_54 -> V_63 = F_24 ( V_52 -> V_63 ) ;
V_54 -> V_64 = F_14 ( V_52 -> V_64 ) ;
V_56 -> V_65 . V_66 = ( int ) F_24 ( V_52 -> V_67 . V_68 ) ;
V_56 -> V_65 . V_69 = ( int ) F_24 ( V_52 -> V_67 . V_70 ) ;
V_56 -> V_71 . V_66 = ( int ) F_24 ( V_52 -> V_72 . V_68 ) ;
V_56 -> V_71 . V_69 = ( int ) F_24 ( V_52 -> V_72 . V_70 ) ;
V_56 -> V_73 . V_66 = ( int ) F_24 ( V_52 -> V_74 . V_68 ) ;
V_56 -> V_73 . V_69 = ( int ) F_24 ( V_52 -> V_74 . V_70 ) ;
V_56 -> V_75 = F_24 ( V_52 -> V_76 ) ;
V_56 -> V_77 = F_14 ( V_52 -> V_78 ) ;
V_54 -> V_79 = F_25 ( V_52 -> V_79 ) ;
V_54 -> V_80 = F_25 ( V_52 -> V_80 ) ;
V_54 -> V_81 = F_24 ( V_52 -> V_81 ) ;
V_54 -> V_82 = F_24 ( V_52 -> V_82 ) ;
V_54 -> V_83 = F_14 ( V_52 -> V_83 ) ;
V_54 -> V_84 = V_52 -> V_84 ;
V_54 -> V_85 = V_52 -> V_85 ;
V_54 -> V_86 = F_24 ( V_52 -> V_86 ) ;
V_54 -> V_87 = F_14 ( V_52 -> V_87 ) ;
V_54 -> V_88 = F_14 ( V_52 -> V_88 ) ;
if ( V_54 -> V_24 == 3 ) {
V_56 -> V_89 = F_25 ( V_52 -> V_90 ) ;
V_54 -> V_91 . V_68 = F_24 ( V_52 -> V_91 . V_68 ) ;
V_54 -> V_91 . V_70 = F_24 ( V_52 -> V_91 . V_70 ) ;
V_54 -> V_92 = F_25 ( V_52 -> V_92 ) ;
V_54 -> V_93 = F_24 ( V_52 -> V_93 ) ;
}
}
void
F_26 (
struct V_50 * V_51 ,
struct V_34 * V_54 ,
T_6 V_94 )
{
struct V_53 * V_52 = & V_51 -> V_55 ;
struct V_56 * V_56 = F_22 ( V_51 ) ;
V_54 -> V_22 = F_8 ( V_23 ) ;
V_54 -> V_57 = 0 ;
V_54 -> V_24 = V_52 -> V_24 ;
V_54 -> V_61 = V_52 -> V_61 ;
V_54 -> V_62 = F_27 ( V_52 -> V_62 ) ;
V_54 -> V_63 = F_27 ( V_52 -> V_63 ) ;
V_54 -> V_58 = F_8 ( V_52 -> V_58 ) ;
V_54 -> V_59 = F_8 ( V_52 -> V_59 ) ;
memset ( V_54 -> V_95 , 0 , sizeof( V_54 -> V_95 ) ) ;
V_54 -> V_67 . V_68 = F_27 ( V_56 -> V_65 . V_66 ) ;
V_54 -> V_67 . V_70 = F_27 ( V_56 -> V_65 . V_69 ) ;
V_54 -> V_72 . V_68 = F_27 ( V_56 -> V_71 . V_66 ) ;
V_54 -> V_72 . V_70 = F_27 ( V_56 -> V_71 . V_69 ) ;
V_54 -> V_74 . V_68 = F_27 ( V_56 -> V_73 . V_66 ) ;
V_54 -> V_74 . V_70 = F_27 ( V_56 -> V_73 . V_69 ) ;
V_54 -> V_60 = F_27 ( V_56 -> V_96 ) ;
V_54 -> V_76 = F_27 ( V_56 -> V_75 ) ;
V_54 -> V_78 = F_8 ( V_56 -> V_77 ) ;
V_54 -> V_79 = F_28 ( V_52 -> V_79 ) ;
V_54 -> V_80 = F_28 ( V_52 -> V_80 ) ;
V_54 -> V_81 = F_27 ( V_52 -> V_81 ) ;
V_54 -> V_82 = F_27 ( V_52 -> V_82 ) ;
V_54 -> V_83 = F_8 ( V_52 -> V_83 ) ;
V_54 -> V_84 = V_52 -> V_84 ;
V_54 -> V_85 = V_52 -> V_85 ;
V_54 -> V_86 = F_27 ( V_52 -> V_86 ) ;
V_54 -> V_87 = F_8 ( V_52 -> V_87 ) ;
V_54 -> V_88 = F_8 ( V_52 -> V_88 ) ;
if ( V_52 -> V_24 == 3 ) {
V_54 -> V_90 = F_28 ( V_56 -> V_89 ) ;
V_54 -> V_91 . V_68 = F_27 ( V_52 -> V_91 . V_68 ) ;
V_54 -> V_91 . V_70 = F_27 ( V_52 -> V_91 . V_70 ) ;
V_54 -> V_92 = F_28 ( V_52 -> V_92 ) ;
V_54 -> V_93 = F_27 ( V_52 -> V_93 ) ;
V_54 -> V_97 = F_28 ( V_51 -> V_98 ) ;
V_54 -> V_99 = F_28 ( V_94 ) ;
memset ( V_54 -> V_100 , 0 , sizeof( V_54 -> V_100 ) ) ;
F_29 ( & V_54 -> V_101 , & V_51 -> V_102 -> V_7 . V_103 ) ;
V_54 -> V_64 = 0 ;
} else {
V_54 -> V_64 = F_8 ( V_52 -> V_64 ) ;
}
}
void
F_30 (
struct V_104 * V_52 ,
struct V_34 * V_54 )
{
V_54 -> V_22 = F_8 ( V_52 -> V_22 ) ;
V_54 -> V_78 = F_8 ( V_52 -> V_78 ) ;
V_54 -> V_24 = V_52 -> V_24 ;
V_54 -> V_61 = V_52 -> V_61 ;
V_54 -> V_57 = 0 ;
V_54 -> V_62 = F_27 ( V_52 -> V_62 ) ;
V_54 -> V_63 = F_27 ( V_52 -> V_63 ) ;
V_54 -> V_60 = F_27 ( V_52 -> V_60 ) ;
V_54 -> V_58 = F_8 ( V_52 -> V_58 ) ;
V_54 -> V_59 = F_8 ( V_52 -> V_59 ) ;
memcpy ( V_54 -> V_95 , V_52 -> V_95 , sizeof( V_54 -> V_95 ) ) ;
V_54 -> V_67 . V_68 = F_27 ( V_52 -> V_67 . V_68 ) ;
V_54 -> V_67 . V_70 = F_27 ( V_52 -> V_67 . V_70 ) ;
V_54 -> V_72 . V_68 = F_27 ( V_52 -> V_72 . V_68 ) ;
V_54 -> V_72 . V_70 = F_27 ( V_52 -> V_72 . V_70 ) ;
V_54 -> V_74 . V_68 = F_27 ( V_52 -> V_74 . V_68 ) ;
V_54 -> V_74 . V_70 = F_27 ( V_52 -> V_74 . V_70 ) ;
V_54 -> V_79 = F_28 ( V_52 -> V_79 ) ;
V_54 -> V_80 = F_28 ( V_52 -> V_80 ) ;
V_54 -> V_81 = F_27 ( V_52 -> V_81 ) ;
V_54 -> V_82 = F_27 ( V_52 -> V_82 ) ;
V_54 -> V_83 = F_8 ( V_52 -> V_83 ) ;
V_54 -> V_84 = V_52 -> V_84 ;
V_54 -> V_85 = V_52 -> V_85 ;
V_54 -> V_86 = F_27 ( V_52 -> V_86 ) ;
V_54 -> V_87 = F_8 ( V_52 -> V_87 ) ;
V_54 -> V_88 = F_8 ( V_52 -> V_88 ) ;
V_54 -> V_76 = F_27 ( V_52 -> V_76 ) ;
if ( V_52 -> V_24 == 3 ) {
V_54 -> V_90 = F_28 ( V_52 -> V_90 ) ;
V_54 -> V_91 . V_68 = F_27 ( V_52 -> V_91 . V_68 ) ;
V_54 -> V_91 . V_70 = F_27 ( V_52 -> V_91 . V_70 ) ;
V_54 -> V_92 = F_28 ( V_52 -> V_92 ) ;
V_54 -> V_93 = F_27 ( V_52 -> V_93 ) ;
V_54 -> V_97 = F_28 ( V_52 -> V_97 ) ;
V_54 -> V_99 = F_28 ( V_52 -> V_99 ) ;
memcpy ( V_54 -> V_100 , V_52 -> V_100 , sizeof( V_54 -> V_100 ) ) ;
F_29 ( & V_54 -> V_101 , & V_52 -> V_101 ) ;
V_54 -> V_64 = 0 ;
} else {
V_54 -> V_64 = F_8 ( V_52 -> V_64 ) ;
}
}
bool
F_31 (
struct V_12 * V_1 ,
T_7 V_105 ,
struct V_34 * V_5 )
{
T_8 V_106 ;
T_8 V_107 ;
T_9 V_108 ;
if ( V_5 -> V_22 != F_8 ( V_23 ) )
return false ;
if ( F_25 ( V_5 -> V_79 ) & ( 1ULL << 63 ) )
return false ;
V_106 = F_14 ( V_5 -> V_78 ) ;
if ( V_106 && F_32 ( V_106 ) == V_109 )
return false ;
if ( ( F_33 ( V_106 ) || F_34 ( V_106 ) ) && V_5 -> V_79 == 0 )
return false ;
if ( V_5 -> V_24 < 3 )
return true ;
if ( ! F_5 ( & V_1 -> V_7 ) )
return false ;
if ( ! F_35 ( ( char * ) V_5 , V_1 -> V_7 . V_9 ,
V_110 ) )
return false ;
if ( F_25 ( V_5 -> V_97 ) != V_105 )
return false ;
if ( ! F_36 ( & V_5 -> V_101 , & V_1 -> V_7 . V_103 ) )
return false ;
V_107 = F_14 ( V_5 -> V_88 ) ;
V_108 = F_25 ( V_5 -> V_92 ) ;
if ( ( V_108 & ( V_111 | V_112 ) ) &&
! F_37 ( & V_1 -> V_7 ) )
return false ;
if ( ( V_108 & V_111 ) && ( V_107 & V_113 ) )
return false ;
if ( ( V_108 & V_111 ) && ( V_108 & V_114 ) )
return false ;
return true ;
}
void
F_38 (
struct V_12 * V_1 ,
struct V_34 * V_5 )
{
T_10 V_115 ;
if ( V_5 -> V_24 < 3 )
return;
ASSERT ( F_5 ( & V_1 -> V_7 ) ) ;
V_115 = F_39 ( ( char * ) V_5 , V_1 -> V_7 . V_9 ,
V_110 ) ;
V_5 -> V_116 = F_40 ( V_115 ) ;
}
int
F_41 (
T_1 * V_1 ,
T_11 * V_31 ,
T_12 * V_51 ,
T_5 V_38 )
{
T_2 * V_2 ;
T_3 * V_5 ;
int error ;
error = V_32 ( V_1 , V_31 , V_51 -> V_98 , & V_51 -> V_117 , V_38 ) ;
if ( error )
return error ;
if ( ( V_38 & V_118 ) &&
F_5 ( & V_1 -> V_7 ) &&
! ( V_1 -> V_119 & V_120 ) ) {
memset ( & V_51 -> V_55 , 0 , sizeof( V_51 -> V_55 ) ) ;
F_22 ( V_51 ) -> V_75 = F_42 () ;
if ( F_5 ( & V_1 -> V_7 ) )
V_51 -> V_55 . V_24 = 3 ;
else
V_51 -> V_55 . V_24 = 2 ;
return 0 ;
}
error = F_18 ( V_1 , V_31 , & V_51 -> V_117 , & V_5 , & V_2 , 0 , V_38 ) ;
if ( error )
return error ;
if ( ! F_31 ( V_1 , V_51 -> V_98 , V_5 ) ) {
F_3 ( V_1 , L_4 ,
V_48 , V_51 -> V_98 ) ;
F_43 ( V_48 , V_121 , V_1 , V_5 ) ;
error = - V_29 ;
goto V_122;
}
if ( V_5 -> V_78 ) {
F_21 ( V_51 , V_5 ) ;
error = F_44 ( V_51 , V_5 ) ;
if ( error ) {
#ifdef F_13
F_3 ( V_1 , L_5 ,
V_48 , error ) ;
#endif
goto V_122;
}
} else {
V_51 -> V_55 . V_24 = V_5 -> V_24 ;
F_22 ( V_51 ) -> V_75 = F_24 ( V_5 -> V_76 ) ;
V_51 -> V_55 . V_64 = F_14 ( V_5 -> V_64 ) ;
F_22 ( V_51 ) -> V_77 = 0 ;
}
ASSERT ( V_51 -> V_55 . V_24 >= 2 ) ;
V_51 -> V_123 = 0 ;
F_45 ( V_2 , V_124 ) ;
V_122:
F_46 ( V_31 , V_2 ) ;
return error ;
}
