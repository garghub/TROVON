int
F_1 (
struct V_1 * V_2 ,
int V_3 )
{
int V_4 = F_2 ( V_2 , V_2 -> V_5 . V_6 ) ;
return ( V_3 + V_4 - 1 ) / V_4 ;
}
static int
F_3 (
struct V_1 * V_2 ,
T_1 V_7 ,
T_2 V_8 ,
T_2 V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return 0 ;
V_13 -> V_15 = F_5 ( V_16 ) ;
V_13 -> V_17 = F_5 ( V_8 ) ;
V_13 -> V_18 = F_5 ( V_9 ) ;
F_6 ( & V_13 -> V_19 , & V_2 -> V_5 . V_20 ) ;
V_13 -> V_21 = F_7 ( V_7 ) ;
V_13 -> V_22 = F_7 ( V_11 -> V_23 ) ;
V_11 -> V_24 = & V_25 ;
return sizeof( struct V_12 ) ;
}
bool
F_8 (
struct V_1 * V_2 ,
T_1 V_7 ,
T_2 V_8 ,
T_2 V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_8 != F_9 ( V_13 -> V_17 ) )
return false ;
if ( V_9 != F_9 ( V_13 -> V_18 ) )
return false ;
if ( V_7 != F_10 ( V_13 -> V_21 ) )
return false ;
return true ;
}
static bool
F_11 (
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_26 -> V_27 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return false ;
if ( V_13 -> V_15 != F_5 ( V_16 ) )
return false ;
if ( ! F_12 ( & V_13 -> V_19 , & V_2 -> V_5 . V_20 ) )
return false ;
if ( V_11 -> V_23 != F_10 ( V_13 -> V_22 ) )
return false ;
if ( F_9 ( V_13 -> V_17 ) +
F_9 ( V_13 -> V_18 ) >= V_28 )
return false ;
if ( V_13 -> V_21 == 0 )
return false ;
return true ;
}
static void
F_13 (
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_26 -> V_27 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return;
if ( ! F_14 ( V_11 -> V_14 , F_15 ( V_11 -> V_29 ) ,
F_16 ( struct V_12 , V_30 ) ) ||
! F_11 ( V_11 ) ) {
F_17 ( V_31 , V_32 , V_2 , V_11 -> V_14 ) ;
F_18 ( V_11 , V_33 ) ;
}
}
static void
F_19 (
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_26 -> V_27 ;
struct V_34 * V_35 = V_11 -> V_36 ;
if ( ! F_4 ( & V_2 -> V_5 ) )
return;
if ( ! F_11 ( V_11 ) ) {
F_17 ( V_31 , V_32 , V_2 , V_11 -> V_14 ) ;
F_18 ( V_11 , V_33 ) ;
return;
}
if ( V_35 ) {
struct V_12 * V_13 = V_11 -> V_14 ;
V_13 -> V_37 = F_7 ( V_35 -> V_38 . V_39 ) ;
}
F_20 ( V_11 -> V_14 , F_15 ( V_11 -> V_29 ) ,
F_16 ( struct V_12 , V_30 ) ) ;
}
void
F_21 (
struct V_40 * V_41 ,
struct V_10 * V_11 ,
struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = V_43 -> V_46 ;
char * V_47 ;
if ( ! F_4 ( & V_2 -> V_5 ) ) {
V_11 -> V_24 = NULL ;
memcpy ( V_11 -> V_14 , V_45 -> V_48 . V_49 , V_45 -> V_50 ) ;
return;
}
ASSERT ( F_15 ( V_11 -> V_29 ) >=
V_45 -> V_50 + sizeof( struct V_12 ) ) ;
V_11 -> V_24 = & V_25 ;
V_47 = V_11 -> V_14 ;
V_47 += F_3 ( V_2 , V_43 -> V_51 , 0 , V_45 -> V_50 , V_11 ) ;
memcpy ( V_47 , V_45 -> V_48 . V_49 , V_45 -> V_50 ) ;
}
STATIC int
F_22 (
struct V_42 * V_43 ,
char * V_52 )
{
struct V_1 * V_2 = V_43 -> V_46 ;
struct V_53 V_54 [ V_55 ] ;
struct V_10 * V_11 ;
T_3 V_56 ;
char * V_57 ;
int V_3 = V_43 -> V_58 . V_59 ;
int V_60 = V_55 ;
int V_61 ;
int V_62 ;
int error = 0 ;
int V_63 = 0 ;
int V_8 ;
V_63 = F_1 ( V_2 , V_3 ) ;
error = F_23 ( V_43 , 0 , V_63 , V_54 , & V_60 , 0 ) ;
if ( error )
goto V_64;
V_8 = 0 ;
for ( V_62 = 0 ; V_62 < V_60 ; V_62 ++ ) {
V_56 = F_24 ( V_2 , V_54 [ V_62 ] . V_65 ) ;
V_61 = F_25 ( V_2 , V_54 [ V_62 ] . V_66 ) ;
V_11 = F_26 ( V_2 -> V_67 , V_56 , F_27 ( V_61 ) , 0 ,
& V_25 ) ;
if ( ! V_11 )
return F_28 ( V_68 ) ;
error = V_11 -> V_69 ;
if ( error ) {
F_29 ( V_11 , V_31 ) ;
F_30 ( V_11 ) ;
goto V_64;
}
V_61 = F_2 ( V_2 , V_61 ) ;
if ( V_3 < V_61 )
V_61 = V_3 ;
V_57 = V_11 -> V_14 ;
if ( F_4 ( & V_2 -> V_5 ) ) {
if ( ! F_8 ( V_2 , V_43 -> V_51 , V_8 ,
V_61 , V_11 ) ) {
error = V_33 ;
F_31 ( V_2 ,
L_1 ,
V_8 , V_61 , V_43 -> V_51 ) ;
F_30 ( V_11 ) ;
goto V_64;
}
V_57 += sizeof( struct V_12 ) ;
}
memcpy ( V_52 + V_8 , V_11 -> V_14 , V_61 ) ;
V_3 -= V_61 ;
V_8 += V_61 ;
F_30 ( V_11 ) ;
}
ASSERT ( V_3 == 0 ) ;
V_52 [ V_43 -> V_58 . V_59 ] = '\0' ;
error = 0 ;
V_64:
return error ;
}
int
F_32 (
struct V_42 * V_43 ,
char * V_52 )
{
struct V_1 * V_2 = V_43 -> V_46 ;
T_4 V_3 ;
int error = 0 ;
F_33 ( V_43 ) ;
if ( F_34 ( V_2 ) )
return F_28 ( V_70 ) ;
F_35 ( V_43 , V_71 ) ;
V_3 = V_43 -> V_58 . V_59 ;
if ( ! V_3 )
goto V_64;
if ( V_3 < 0 || V_3 > V_28 ) {
F_31 ( V_2 , L_2 ,
V_31 , ( unsigned long long ) V_43 -> V_51 ,
( long long ) V_3 ) ;
ASSERT ( 0 ) ;
error = F_28 ( V_33 ) ;
goto V_64;
}
if ( V_43 -> V_72 . V_73 & V_74 ) {
memcpy ( V_52 , V_43 -> V_72 . V_48 . V_49 , V_3 ) ;
V_52 [ V_3 ] = '\0' ;
} else {
error = F_22 ( V_43 , V_52 ) ;
}
V_64:
F_36 ( V_43 , V_71 ) ;
return error ;
}
int
F_37 (
struct V_42 * V_75 ,
struct V_76 * V_77 ,
const char * V_78 ,
T_5 V_79 ,
struct V_42 * * V_80 )
{
struct V_1 * V_2 = V_75 -> V_46 ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 = NULL ;
int error = 0 ;
int V_3 ;
struct V_81 V_82 ;
T_6 V_83 ;
bool V_84 = false ;
T_7 V_85 ;
int V_86 ;
T_8 V_87 ;
T_9 V_88 ;
int V_60 ;
struct V_53 V_54 [ V_55 ] ;
T_3 V_56 ;
const char * V_57 ;
int V_61 ;
int V_62 ;
T_10 * V_11 ;
T_11 V_89 ;
struct V_90 * V_91 , * V_92 ;
T_7 V_93 ;
* V_80 = NULL ;
F_38 ( V_75 , V_77 ) ;
if ( F_34 ( V_2 ) )
return F_28 ( V_70 ) ;
V_3 = strlen ( V_78 ) ;
if ( V_3 >= V_28 )
return F_28 ( V_94 ) ;
V_91 = V_92 = NULL ;
if ( V_75 -> V_58 . V_95 & V_96 )
V_89 = F_39 ( V_75 ) ;
else
V_89 = V_97 ;
error = F_40 ( V_75 , F_41 () , F_42 () , V_89 ,
V_98 | V_99 , & V_91 , & V_92 ) ;
if ( error )
goto V_100;
V_41 = F_43 ( V_2 , V_101 ) ;
V_85 = V_102 ;
if ( V_3 <= F_44 ( V_2 , V_75 -> V_58 . V_103 ) )
V_88 = 0 ;
else
V_88 = F_1 ( V_2 , V_3 ) ;
V_93 = F_45 ( V_2 , V_77 -> V_104 , V_88 ) ;
error = F_46 ( V_41 , V_93 , F_47 ( V_2 ) , 0 ,
V_105 , V_106 ) ;
if ( error == V_107 && V_88 == 0 ) {
V_93 = 0 ;
error = F_46 ( V_41 , 0 , F_47 ( V_2 ) , 0 ,
V_105 , V_106 ) ;
}
if ( error ) {
V_85 = 0 ;
goto V_108;
}
F_35 ( V_75 , V_109 | V_110 ) ;
V_84 = true ;
if ( V_75 -> V_58 . V_95 & V_111 ) {
error = F_28 ( V_112 ) ;
goto V_108;
}
error = F_48 ( V_41 , V_2 , V_91 , V_92 , V_93 , 1 , 0 ) ;
if ( error )
goto V_108;
error = F_49 ( V_41 , V_75 , V_77 , V_93 ) ;
if ( error )
goto V_108;
F_50 ( & V_82 , & V_83 ) ;
error = F_51 ( & V_41 , V_75 , V_113 | ( V_79 & ~ V_114 ) , 1 , 0 ,
V_89 , V_93 > 0 , & V_43 , NULL ) ;
if ( error ) {
if ( error == V_107 )
goto V_108;
goto V_115;
}
F_52 ( V_41 , V_75 , V_109 ) ;
V_84 = false ;
F_53 ( V_41 , V_43 , V_91 , V_92 ) ;
if ( V_93 )
V_93 -= F_54 ( V_2 ) ;
if ( V_3 <= F_55 ( V_43 ) ) {
F_56 ( V_43 , V_3 , V_116 ) ;
memcpy ( V_43 -> V_72 . V_48 . V_49 , V_78 , V_3 ) ;
V_43 -> V_58 . V_59 = V_3 ;
V_43 -> V_72 . V_73 &= ~ ( V_117 | V_118 ) ;
V_43 -> V_72 . V_73 |= V_74 ;
V_43 -> V_58 . V_119 = V_120 ;
F_57 ( V_41 , V_43 , V_121 | V_122 ) ;
} else {
int V_8 ;
V_87 = 0 ;
V_60 = V_55 ;
error = F_58 ( V_41 , V_43 , V_87 , V_88 ,
V_123 , & V_83 , V_93 ,
V_54 , & V_60 , & V_82 ) ;
if ( error )
goto V_124;
if ( V_93 )
V_93 -= V_88 ;
V_43 -> V_58 . V_59 = V_3 ;
F_57 ( V_41 , V_43 , V_122 ) ;
V_57 = V_78 ;
V_8 = 0 ;
for ( V_62 = 0 ; V_62 < V_60 ; V_62 ++ ) {
char * V_47 ;
V_56 = F_24 ( V_2 , V_54 [ V_62 ] . V_65 ) ;
V_61 = F_25 ( V_2 , V_54 [ V_62 ] . V_66 ) ;
V_11 = F_59 ( V_41 , V_2 -> V_67 , V_56 ,
F_27 ( V_61 ) , 0 ) ;
if ( ! V_11 ) {
error = V_68 ;
goto V_124;
}
V_11 -> V_24 = & V_25 ;
V_61 = F_2 ( V_2 , V_61 ) ;
V_61 = F_60 ( V_61 , V_3 ) ;
V_47 = V_11 -> V_14 ;
V_47 += F_3 ( V_2 , V_43 -> V_51 , V_8 ,
V_61 , V_11 ) ;
memcpy ( V_47 , V_57 , V_61 ) ;
V_57 += V_61 ;
V_3 -= V_61 ;
V_8 += V_61 ;
F_61 ( V_41 , V_11 , 0 , ( V_47 + V_61 - 1 ) -
( char * ) V_11 -> V_14 ) ;
}
ASSERT ( V_3 == 0 ) ;
}
error = F_62 ( V_41 , V_75 , V_77 , V_43 -> V_51 ,
& V_83 , & V_82 , V_93 ) ;
if ( error )
goto V_124;
F_63 ( V_41 , V_75 , V_125 | V_126 ) ;
F_57 ( V_41 , V_75 , V_122 ) ;
if ( V_2 -> V_127 & ( V_128 | V_129 ) ) {
F_64 ( V_41 ) ;
}
error = F_65 ( & V_41 , & V_82 , & V_86 ) ;
if ( error ) {
goto V_124;
}
error = F_66 ( V_41 , V_102 ) ;
F_67 ( V_91 ) ;
F_67 ( V_92 ) ;
* V_80 = V_43 ;
return 0 ;
V_124:
F_68 ( V_43 ) ;
V_115:
F_69 ( & V_82 ) ;
V_85 |= V_130 ;
V_108:
F_70 ( V_41 , V_85 ) ;
F_67 ( V_91 ) ;
F_67 ( V_92 ) ;
if ( V_84 )
F_36 ( V_75 , V_109 ) ;
V_100:
return error ;
}
int
F_71 (
T_12 * V_43 ,
T_13 * * V_131 )
{
T_10 * V_11 ;
int V_86 ;
int V_132 ;
int error ;
T_6 V_83 ;
T_14 V_82 ;
int V_133 ;
T_15 * V_2 ;
T_16 V_54 [ V_55 ] ;
int V_60 ;
T_13 * V_134 ;
int V_9 ;
T_13 * V_41 ;
V_41 = * V_131 ;
V_2 = V_43 -> V_46 ;
ASSERT ( V_43 -> V_58 . V_59 > F_55 ( V_43 ) ) ;
ASSERT ( V_43 -> V_58 . V_135 > 0 && V_43 -> V_58 . V_135 <= 2 ) ;
V_9 = ( int ) V_43 -> V_58 . V_59 ;
V_43 -> V_58 . V_59 = 0 ;
F_57 ( V_41 , V_43 , V_122 ) ;
V_132 = 0 ;
F_50 ( & V_82 , & V_83 ) ;
V_60 = F_72 ( V_54 ) ;
error = F_23 ( V_43 , 0 , F_1 ( V_2 , V_9 ) ,
V_54 , & V_60 , 0 ) ;
if ( error )
goto V_136;
for ( V_133 = 0 ; V_133 < V_60 ; V_133 ++ ) {
V_11 = F_59 ( V_41 , V_2 -> V_67 ,
F_24 ( V_2 , V_54 [ V_133 ] . V_65 ) ,
F_73 ( V_2 , V_54 [ V_133 ] . V_66 ) , 0 ) ;
if ( ! V_11 ) {
error = V_68 ;
goto V_115;
}
F_74 ( V_41 , V_11 ) ;
}
if ( ( error = F_75 ( V_41 , V_43 , 0 , V_9 , V_123 , V_60 ,
& V_83 , & V_82 , & V_132 ) ) )
goto V_115;
ASSERT ( V_132 ) ;
if ( ( error = F_65 ( & V_41 , & V_82 , & V_86 ) ) )
goto V_115;
ASSERT ( V_86 ) ;
F_52 ( V_41 , V_43 , 0 ) ;
F_57 ( V_41 , V_43 , V_122 ) ;
V_134 = F_76 ( V_41 ) ;
error = F_66 ( V_41 , 0 ) ;
V_41 = V_134 ;
if ( error ) {
ASSERT ( F_34 ( V_2 ) ) ;
goto V_136;
}
F_77 ( V_41 -> V_137 ) ;
if ( V_43 -> V_72 . V_50 )
F_56 ( V_43 , - V_43 -> V_72 . V_50 , V_116 ) ;
ASSERT ( V_43 -> V_72 . V_50 == 0 ) ;
if ( ( error = F_46 ( V_41 , 0 , F_78 ( V_2 ) , 0 ,
V_105 , V_138 ) ) ) {
ASSERT ( F_34 ( V_2 ) ) ;
goto V_136;
}
F_52 ( V_41 , V_43 , 0 ) ;
* V_131 = V_41 ;
return 0 ;
V_115:
F_69 ( & V_82 ) ;
V_136:
return error ;
}
