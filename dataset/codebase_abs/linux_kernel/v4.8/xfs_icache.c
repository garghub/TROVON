struct V_1 *
F_1 (
struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( V_6 , V_7 ) ;
if ( ! V_5 )
return NULL ;
if ( F_3 ( V_3 -> V_8 , F_4 ( V_5 ) ) ) {
F_5 ( V_6 , V_5 ) ;
return NULL ;
}
F_4 ( V_5 ) -> V_9 = 0 ;
F_6 ( V_3 , V_10 ) ;
ASSERT ( F_7 ( & V_5 -> V_11 ) == 0 ) ;
ASSERT ( ! F_8 ( & V_5 -> V_12 ) ) ;
ASSERT ( ! F_9 ( V_5 ) ) ;
ASSERT ( V_5 -> V_13 == 0 ) ;
F_10 ( & V_5 -> V_14 , V_15 , L_1 , V_5 -> V_13 ) ;
V_5 -> V_13 = V_4 ;
V_5 -> V_16 = V_3 ;
memset ( & V_5 -> V_17 , 0 , sizeof( struct V_18 ) ) ;
V_5 -> V_19 = NULL ;
memset ( & V_5 -> V_20 , 0 , sizeof( V_21 ) ) ;
V_5 -> V_22 = 0 ;
V_5 -> V_23 = 0 ;
memset ( & V_5 -> V_24 , 0 , sizeof( V_5 -> V_24 ) ) ;
return V_5 ;
}
STATIC void
F_11 (
struct V_25 * V_26 )
{
struct V_27 * V_27 = F_12 ( V_26 , struct V_27 , V_28 ) ;
struct V_1 * V_5 = F_13 ( V_27 ) ;
switch ( F_4 ( V_5 ) -> V_9 & V_29 ) {
case V_30 :
case V_31 :
case V_32 :
F_14 ( V_5 , V_33 ) ;
break;
}
if ( V_5 -> V_19 )
F_14 ( V_5 , V_34 ) ;
if ( V_5 -> V_35 ) {
ASSERT ( ! ( V_5 -> V_35 -> V_36 . V_37 & V_38 ) ) ;
F_15 ( V_5 ) ;
V_5 -> V_35 = NULL ;
}
F_5 ( V_6 , V_5 ) ;
}
static void
F_16 (
struct V_1 * V_5 )
{
ASSERT ( F_7 ( & V_5 -> V_11 ) == 0 ) ;
ASSERT ( ! F_9 ( V_5 ) ) ;
F_17 ( V_5 -> V_16 , V_10 ) ;
F_18 ( & F_4 ( V_5 ) -> V_28 , F_11 ) ;
}
void
F_19 (
struct V_1 * V_5 )
{
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_22 = V_39 ;
V_5 -> V_13 = 0 ;
F_21 ( & V_5 -> V_12 ) ;
F_16 ( V_5 ) ;
}
static void
F_22 (
struct V_2 * V_3 )
{
F_23 () ;
if ( F_24 ( & V_3 -> V_40 , V_41 ) ) {
F_25 ( V_3 -> V_42 , & V_3 -> V_43 ,
F_26 ( V_44 / 6 * 10 ) ) ;
}
F_27 () ;
}
void
F_28 (
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_12 ( F_29 ( V_46 ) ,
struct V_2 , V_43 ) ;
F_30 ( V_3 , V_47 ) ;
F_22 ( V_3 ) ;
}
static void
F_31 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_50 ;
ASSERT ( F_8 ( & V_49 -> V_51 ) ) ;
if ( V_49 -> V_52 ++ )
return;
F_20 ( & V_3 -> V_53 ) ;
F_32 ( & V_3 -> V_40 , V_49 -> V_54 ,
V_41 ) ;
F_21 ( & V_3 -> V_53 ) ;
F_22 ( V_3 ) ;
F_33 ( V_3 , V_49 -> V_54 , - 1 , V_55 ) ;
}
static void
F_34 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = V_49 -> V_50 ;
ASSERT ( F_8 ( & V_49 -> V_51 ) ) ;
if ( -- V_49 -> V_52 )
return;
F_20 ( & V_3 -> V_53 ) ;
F_35 ( & V_3 -> V_40 , V_49 -> V_54 ,
V_41 ) ;
F_21 ( & V_3 -> V_53 ) ;
F_36 ( V_3 , V_49 -> V_54 , - 1 , V_55 ) ;
}
void
F_37 (
struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_48 * V_49 ;
V_49 = F_38 ( V_3 , F_39 ( V_3 , V_5 -> V_13 ) ) ;
F_20 ( & V_49 -> V_51 ) ;
F_20 ( & V_5 -> V_12 ) ;
F_32 ( & V_49 -> V_56 , F_40 ( V_3 , V_5 -> V_13 ) ,
V_41 ) ;
F_31 ( V_49 ) ;
F_41 ( V_5 , V_57 ) ;
F_21 ( & V_5 -> V_12 ) ;
F_21 ( & V_49 -> V_51 ) ;
F_42 ( V_49 ) ;
}
STATIC void
F_43 (
struct V_48 * V_49 ,
T_1 V_4 )
{
F_35 ( & V_49 -> V_56 ,
F_40 ( V_49 -> V_50 , V_4 ) ,
V_41 ) ;
F_34 ( V_49 ) ;
}
static int
F_44 (
struct V_2 * V_3 ,
struct V_27 * V_27 )
{
int error ;
T_2 V_58 = V_27 -> V_59 ;
T_2 V_60 = V_27 -> V_61 ;
T_3 V_62 = V_27 -> V_63 ;
T_4 V_64 = V_27 -> V_9 ;
error = F_3 ( V_3 -> V_8 , V_27 ) ;
F_45 ( V_27 , V_58 ) ;
V_27 -> V_61 = V_60 ;
V_27 -> V_63 = V_62 ;
V_27 -> V_9 = V_64 ;
return error ;
}
static int
F_46 (
struct V_48 * V_49 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_65 ,
int V_66 ) __releases( T_5 )
{
struct V_27 * V_27 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_16 ;
int error ;
F_20 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_13 != V_4 ) {
F_47 ( V_5 ) ;
F_6 ( V_3 , V_67 ) ;
error = - V_68 ;
goto V_69;
}
if ( V_5 -> V_22 & ( V_70 | V_39 ) ) {
F_47 ( V_5 ) ;
F_6 ( V_3 , V_67 ) ;
error = - V_68 ;
goto V_69;
}
if ( F_4 ( V_5 ) -> V_9 == 0 && ! ( V_65 & V_71 ) ) {
error = - V_72 ;
goto V_69;
}
if ( V_5 -> V_22 & V_57 ) {
F_48 ( V_5 ) ;
V_5 -> V_22 |= V_39 ;
F_21 ( & V_5 -> V_12 ) ;
F_27 () ;
error = F_44 ( V_3 , V_27 ) ;
if ( error ) {
F_23 () ;
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_22 &= ~ ( V_70 | V_39 ) ;
ASSERT ( V_5 -> V_22 & V_57 ) ;
F_49 ( V_5 ) ;
goto V_69;
}
F_20 ( & V_49 -> V_51 ) ;
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_22 &= ~ V_73 ;
V_5 -> V_22 |= V_70 ;
F_43 ( V_49 , V_5 -> V_13 ) ;
V_27 -> V_74 = V_75 ;
ASSERT ( ! F_50 ( & V_5 -> V_14 . V_76 ) ) ;
F_10 ( & V_5 -> V_14 , V_15 , L_1 , V_5 -> V_13 ) ;
F_21 ( & V_5 -> V_12 ) ;
F_21 ( & V_49 -> V_51 ) ;
} else {
if ( ! F_51 ( V_27 ) ) {
F_47 ( V_5 ) ;
error = - V_68 ;
goto V_69;
}
F_21 ( & V_5 -> V_12 ) ;
F_27 () ;
F_52 ( V_5 ) ;
}
if ( V_66 != 0 )
F_53 ( V_5 , V_66 ) ;
F_54 ( V_5 , V_77 | V_78 ) ;
F_6 ( V_3 , V_79 ) ;
return 0 ;
V_69:
F_21 ( & V_5 -> V_12 ) ;
F_27 () ;
return error ;
}
static int
F_55 (
struct V_2 * V_3 ,
struct V_48 * V_49 ,
T_6 * V_80 ,
T_1 V_4 ,
struct V_1 * * V_81 ,
int V_65 ,
int V_66 )
{
struct V_1 * V_5 ;
int error ;
T_7 V_82 = F_40 ( V_3 , V_4 ) ;
int V_83 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_84 ;
error = F_56 ( V_3 , V_80 , V_5 , V_65 ) ;
if ( error )
goto V_85;
F_57 ( V_5 ) ;
if ( ( F_4 ( V_5 ) -> V_9 == 0 ) && ! ( V_65 & V_71 ) ) {
error = - V_72 ;
goto V_85;
}
if ( F_58 ( V_86 ) ) {
error = - V_68 ;
goto V_85;
}
if ( V_66 ) {
if ( ! F_59 ( V_5 , V_66 ) )
F_60 () ;
}
V_83 = V_70 ;
if ( V_65 & V_87 )
V_83 |= V_78 ;
V_5 -> V_88 = NULL ;
V_5 -> V_89 = NULL ;
V_5 -> V_90 = NULL ;
F_61 ( V_5 , V_83 ) ;
F_20 ( & V_49 -> V_51 ) ;
error = F_62 ( & V_49 -> V_56 , V_82 , V_5 ) ;
if ( F_63 ( error ) ) {
F_64 ( error != - V_91 ) ;
F_6 ( V_3 , V_92 ) ;
error = - V_68 ;
goto V_93;
}
F_21 ( & V_49 -> V_51 ) ;
F_65 () ;
* V_81 = V_5 ;
return 0 ;
V_93:
F_21 ( & V_49 -> V_51 ) ;
F_65 () ;
if ( V_66 )
F_66 ( V_5 , V_66 ) ;
V_85:
F_67 ( F_4 ( V_5 ) ) ;
F_19 ( V_5 ) ;
return error ;
}
int
F_68 (
T_8 * V_3 ,
T_6 * V_80 ,
T_1 V_4 ,
T_9 V_65 ,
T_9 V_66 ,
T_10 * * V_81 )
{
T_10 * V_5 ;
int error ;
T_11 * V_49 ;
T_7 V_82 ;
ASSERT ( ( V_66 & ( V_94 | V_95 ) ) == 0 ) ;
if ( ! V_4 || F_39 ( V_3 , V_4 ) >= V_3 -> V_96 . V_97 )
return - V_98 ;
F_6 ( V_3 , V_99 ) ;
V_49 = F_38 ( V_3 , F_39 ( V_3 , V_4 ) ) ;
V_82 = F_40 ( V_3 , V_4 ) ;
V_100:
error = 0 ;
F_23 () ;
V_5 = F_69 ( & V_49 -> V_56 , V_82 ) ;
if ( V_5 ) {
error = F_46 ( V_49 , V_5 , V_4 , V_65 , V_66 ) ;
if ( error )
goto V_101;
} else {
F_27 () ;
F_6 ( V_3 , V_102 ) ;
error = F_55 ( V_3 , V_49 , V_80 , V_4 , & V_5 ,
V_65 , V_66 ) ;
if ( error )
goto V_101;
}
F_42 ( V_49 ) ;
* V_81 = V_5 ;
if ( F_70 ( V_5 , V_70 ) && F_4 ( V_5 ) -> V_9 != 0 )
F_71 ( V_5 ) ;
return 0 ;
V_101:
if ( error == - V_68 ) {
F_72 ( 1 ) ;
goto V_100;
}
F_42 ( V_49 ) ;
return error ;
}
STATIC int
F_73 (
struct V_1 * V_5 )
{
struct V_27 * V_27 = F_4 ( V_5 ) ;
ASSERT ( F_74 () ) ;
F_20 ( & V_5 -> V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_103;
if ( F_75 ( V_5 , V_70 | V_57 | V_39 ) )
goto V_103;
F_21 ( & V_5 -> V_12 ) ;
if ( F_76 ( V_5 -> V_16 ) )
return - V_104 ;
if ( ! F_51 ( V_27 ) )
return - V_72 ;
return 0 ;
V_103:
F_21 ( & V_5 -> V_12 ) ;
return - V_72 ;
}
STATIC int
F_77 (
struct V_2 * V_3 ,
struct V_48 * V_49 ,
int (* F_78)( struct V_1 * V_5 , int V_65 ,
void * args ) ,
int V_65 ,
void * args ,
int V_105 )
{
T_2 V_106 ;
int V_107 = 0 ;
int V_108 ;
int V_109 ;
int V_110 ;
V_111:
V_109 = 0 ;
V_108 = 0 ;
V_106 = 0 ;
V_110 = 0 ;
do {
struct V_1 * V_112 [ V_113 ] ;
int error = 0 ;
int V_114 ;
F_23 () ;
if ( V_105 == - 1 )
V_110 = F_79 ( & V_49 -> V_56 ,
( void * * ) V_112 , V_106 ,
V_113 ) ;
else
V_110 = F_80 (
& V_49 -> V_56 ,
( void * * ) V_112 , V_106 ,
V_113 , V_105 ) ;
if ( ! V_110 ) {
F_27 () ;
break;
}
for ( V_114 = 0 ; V_114 < V_110 ; V_114 ++ ) {
struct V_1 * V_5 = V_112 [ V_114 ] ;
if ( V_109 || F_73 ( V_5 ) )
V_112 [ V_114 ] = NULL ;
if ( F_39 ( V_3 , V_5 -> V_13 ) != V_49 -> V_54 )
continue;
V_106 = F_40 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_106 < F_40 ( V_3 , V_5 -> V_13 ) )
V_109 = 1 ;
}
F_27 () ;
for ( V_114 = 0 ; V_114 < V_110 ; V_114 ++ ) {
if ( ! V_112 [ V_114 ] )
continue;
error = F_78 ( V_112 [ V_114 ] , V_65 , args ) ;
F_81 ( V_112 [ V_114 ] ) ;
if ( error == - V_68 ) {
V_108 ++ ;
continue;
}
if ( error && V_107 != - V_104 )
V_107 = error ;
}
if ( error == - V_104 )
break;
F_82 () ;
} while ( V_110 && ! V_109 );
if ( V_108 ) {
F_72 ( 1 ) ;
goto V_111;
}
return V_107 ;
}
void
F_83 (
struct V_2 * V_3 )
{
F_23 () ;
if ( F_24 ( & V_3 -> V_40 , V_115 ) )
F_25 ( V_3 -> V_116 ,
& V_3 -> V_117 ,
F_26 ( V_118 * 1000 ) ) ;
F_27 () ;
}
void
F_84 (
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_12 ( F_29 ( V_46 ) ,
struct V_2 , V_117 ) ;
F_85 ( V_3 , NULL ) ;
F_83 ( V_3 ) ;
}
int
F_86 (
struct V_2 * V_3 ,
int (* F_78)( struct V_1 * V_5 , int V_65 ,
void * args ) ,
int V_65 ,
void * args )
{
struct V_48 * V_49 ;
int error = 0 ;
int V_107 = 0 ;
T_12 V_119 ;
V_119 = 0 ;
while ( ( V_49 = F_38 ( V_3 , V_119 ) ) ) {
V_119 = V_49 -> V_54 + 1 ;
error = F_77 ( V_3 , V_49 , F_78 , V_65 , args , - 1 ) ;
F_42 ( V_49 ) ;
if ( error ) {
V_107 = error ;
if ( error == - V_104 )
break;
}
}
return V_107 ;
}
int
F_87 (
struct V_2 * V_3 ,
int (* F_78)( struct V_1 * V_5 , int V_65 ,
void * args ) ,
int V_65 ,
void * args ,
int V_105 )
{
struct V_48 * V_49 ;
int error = 0 ;
int V_107 = 0 ;
T_12 V_119 ;
V_119 = 0 ;
while ( ( V_49 = F_88 ( V_3 , V_119 , V_105 ) ) ) {
V_119 = V_49 -> V_54 + 1 ;
error = F_77 ( V_3 , V_49 , F_78 , V_65 , args , V_105 ) ;
F_42 ( V_49 ) ;
if ( error ) {
V_107 = error ;
if ( error == - V_104 )
break;
}
}
return V_107 ;
}
STATIC int
F_89 (
struct V_1 * V_5 ,
int V_65 )
{
ASSERT ( F_74 () ) ;
if ( ! V_5 -> V_13 )
return 1 ;
if ( ( V_65 & V_47 ) &&
F_75 ( V_5 , V_120 | V_39 ) )
return 1 ;
F_20 ( & V_5 -> V_12 ) ;
if ( ! F_75 ( V_5 , V_57 ) ||
F_75 ( V_5 , V_39 ) ) {
F_21 ( & V_5 -> V_12 ) ;
return 1 ;
}
F_41 ( V_5 , V_39 ) ;
F_21 ( & V_5 -> V_12 ) ;
return 0 ;
}
STATIC int
F_90 (
struct V_1 * V_5 ,
struct V_48 * V_49 ,
int V_121 )
{
struct V_122 * V_123 = NULL ;
T_1 V_4 = V_5 -> V_13 ;
int error ;
V_111:
error = 0 ;
F_53 ( V_5 , V_124 ) ;
if ( ! F_91 ( V_5 ) ) {
if ( ! ( V_121 & V_125 ) )
goto V_126;
F_92 ( V_5 ) ;
}
if ( F_76 ( V_5 -> V_16 ) ) {
F_93 ( V_5 ) ;
F_94 ( V_5 , false ) ;
goto V_127;
}
if ( F_95 ( V_5 ) ) {
if ( ! ( V_121 & V_125 ) )
goto V_128;
F_93 ( V_5 ) ;
}
if ( F_70 ( V_5 , V_77 ) )
goto V_127;
if ( F_96 ( V_5 ) )
goto V_127;
if ( ! ( V_121 & V_125 ) )
goto V_128;
error = F_97 ( V_5 , & V_123 ) ;
if ( error == - V_68 ) {
F_66 ( V_5 , V_124 ) ;
F_72 ( 2 ) ;
goto V_111;
}
if ( ! error ) {
error = F_98 ( V_123 ) ;
F_99 ( V_123 ) ;
}
F_92 ( V_5 ) ;
V_127:
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_22 = V_39 ;
V_5 -> V_13 = 0 ;
F_21 ( & V_5 -> V_12 ) ;
F_100 ( V_5 ) ;
F_66 ( V_5 , V_124 ) ;
F_6 ( V_5 -> V_16 , V_129 ) ;
F_20 ( & V_49 -> V_51 ) ;
if ( ! F_101 ( & V_49 -> V_56 ,
F_40 ( V_5 -> V_16 , V_4 ) ) )
ASSERT ( 0 ) ;
F_34 ( V_49 ) ;
F_21 ( & V_49 -> V_51 ) ;
F_53 ( V_5 , V_124 ) ;
F_102 ( V_5 ) ;
F_66 ( V_5 , V_124 ) ;
F_16 ( V_5 ) ;
return error ;
V_128:
F_100 ( V_5 ) ;
V_126:
F_54 ( V_5 , V_39 ) ;
F_66 ( V_5 , V_124 ) ;
return 0 ;
}
STATIC int
F_103 (
struct V_2 * V_3 ,
int V_65 ,
int * V_130 )
{
struct V_48 * V_49 ;
int error = 0 ;
int V_107 = 0 ;
T_12 V_119 ;
int V_131 = V_65 & V_47 ;
int V_108 ;
V_111:
V_119 = 0 ;
V_108 = 0 ;
while ( ( V_49 = F_88 ( V_3 , V_119 , V_41 ) ) ) {
unsigned long V_106 = 0 ;
int V_109 = 0 ;
int V_110 = 0 ;
V_119 = V_49 -> V_54 + 1 ;
if ( V_131 ) {
if ( ! F_104 ( & V_49 -> V_132 ) ) {
V_108 ++ ;
F_42 ( V_49 ) ;
continue;
}
V_106 = V_49 -> V_133 ;
} else
F_105 ( & V_49 -> V_132 ) ;
do {
struct V_1 * V_112 [ V_113 ] ;
int V_114 ;
F_23 () ;
V_110 = F_80 (
& V_49 -> V_56 ,
( void * * ) V_112 , V_106 ,
V_113 ,
V_41 ) ;
if ( ! V_110 ) {
V_109 = 1 ;
F_27 () ;
break;
}
for ( V_114 = 0 ; V_114 < V_110 ; V_114 ++ ) {
struct V_1 * V_5 = V_112 [ V_114 ] ;
if ( V_109 || F_89 ( V_5 , V_65 ) )
V_112 [ V_114 ] = NULL ;
if ( F_39 ( V_3 , V_5 -> V_13 ) !=
V_49 -> V_54 )
continue;
V_106 = F_40 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_106 < F_40 ( V_3 , V_5 -> V_13 ) )
V_109 = 1 ;
}
F_27 () ;
for ( V_114 = 0 ; V_114 < V_110 ; V_114 ++ ) {
if ( ! V_112 [ V_114 ] )
continue;
error = F_90 ( V_112 [ V_114 ] , V_49 , V_65 ) ;
if ( error && V_107 != - V_104 )
V_107 = error ;
}
* V_130 -= V_113 ;
F_82 () ;
} while ( V_110 && ! V_109 && * V_130 > 0 );
if ( V_131 && ! V_109 )
V_49 -> V_133 = V_106 ;
else
V_49 -> V_133 = 0 ;
F_106 ( & V_49 -> V_132 ) ;
F_42 ( V_49 ) ;
}
if ( V_108 && ( V_65 & V_125 ) && * V_130 > 0 ) {
V_131 = 0 ;
goto V_111;
}
return V_107 ;
}
int
F_30 (
T_8 * V_3 ,
int V_64 )
{
int V_130 = V_134 ;
return F_103 ( V_3 , V_64 , & V_130 ) ;
}
long
F_107 (
struct V_2 * V_3 ,
int V_130 )
{
F_22 ( V_3 ) ;
F_108 ( V_3 -> V_135 ) ;
return F_103 ( V_3 , V_47 | V_125 , & V_130 ) ;
}
int
F_109 (
struct V_2 * V_3 )
{
struct V_48 * V_49 ;
T_12 V_119 = 0 ;
int V_136 = 0 ;
while ( ( V_49 = F_88 ( V_3 , V_119 , V_41 ) ) ) {
V_119 = V_49 -> V_54 + 1 ;
V_136 += V_49 -> V_52 ;
F_42 ( V_49 ) ;
}
return V_136 ;
}
STATIC int
F_110 (
struct V_1 * V_5 ,
struct V_137 * V_138 )
{
if ( ( V_138 -> V_139 & V_140 ) &&
! F_111 ( F_4 ( V_5 ) -> V_141 , V_138 -> V_142 ) )
return 0 ;
if ( ( V_138 -> V_139 & V_143 ) &&
! F_112 ( F_4 ( V_5 ) -> V_144 , V_138 -> V_145 ) )
return 0 ;
if ( ( V_138 -> V_139 & V_146 ) &&
F_113 ( V_5 ) != V_138 -> V_147 )
return 0 ;
return 1 ;
}
STATIC int
F_114 (
struct V_1 * V_5 ,
struct V_137 * V_138 )
{
if ( ( V_138 -> V_139 & V_140 ) &&
F_111 ( F_4 ( V_5 ) -> V_141 , V_138 -> V_142 ) )
return 1 ;
if ( ( V_138 -> V_139 & V_143 ) &&
F_112 ( F_4 ( V_5 ) -> V_144 , V_138 -> V_145 ) )
return 1 ;
if ( ( V_138 -> V_139 & V_146 ) &&
F_113 ( V_5 ) == V_138 -> V_147 )
return 1 ;
return 0 ;
}
STATIC int
F_115 (
struct V_1 * V_5 ,
int V_65 ,
void * args )
{
int V_148 ;
struct V_137 * V_138 = args ;
bool V_149 = true ;
int V_150 ;
ASSERT ( ! V_138 || ( V_138 && V_138 -> V_151 != 0 ) ) ;
if ( ! F_116 ( V_5 , false ) ) {
F_117 ( V_5 ) ;
F_118 ( V_5 ) ;
return 0 ;
}
if ( ! ( V_65 & V_125 ) &&
F_119 ( F_4 ( V_5 ) -> V_152 , V_153 ) )
return 0 ;
if ( V_138 ) {
if ( V_138 -> V_139 & V_154 )
V_150 = F_114 ( V_5 , V_138 ) ;
else
V_150 = F_110 ( V_5 , V_138 ) ;
if ( ! V_150 )
return 0 ;
if ( V_138 -> V_139 & V_155 &&
F_120 ( V_5 ) < V_138 -> V_156 )
return 0 ;
if ( V_138 -> V_151 == V_5 -> V_13 )
V_149 = false ;
}
V_148 = F_121 ( V_5 -> V_16 , V_5 , V_149 ) ;
if ( V_148 == - V_68 && ! ( V_65 & V_125 ) )
V_148 = 0 ;
return V_148 ;
}
int
F_85 (
struct V_2 * V_3 ,
struct V_137 * V_138 )
{
int V_65 = V_47 ;
if ( V_138 && ( V_138 -> V_139 & V_157 ) )
V_65 = V_125 ;
return F_87 ( V_3 , F_115 , V_65 ,
V_138 , V_115 ) ;
}
int
F_122 (
struct V_1 * V_5 )
{
int V_158 = 0 ;
struct V_137 V_138 = { 0 } ;
struct V_159 * V_160 ;
ASSERT ( F_123 ( V_5 , V_94 ) ) ;
V_138 . V_151 = V_5 -> V_13 ;
V_138 . V_139 = V_154 | V_157 ;
if ( F_124 ( V_5 -> V_16 ) ) {
V_160 = F_125 ( V_5 , V_161 ) ;
if ( V_160 && F_126 ( V_160 ) ) {
V_138 . V_142 = F_4 ( V_5 ) -> V_141 ;
V_138 . V_139 |= V_140 ;
V_158 = 1 ;
}
}
if ( F_127 ( V_5 -> V_16 ) ) {
V_160 = F_125 ( V_5 , V_162 ) ;
if ( V_160 && F_126 ( V_160 ) ) {
V_138 . V_145 = F_4 ( V_5 ) -> V_144 ;
V_138 . V_139 |= V_143 ;
V_158 = 1 ;
}
}
if ( V_158 )
F_85 ( V_5 -> V_16 , & V_138 ) ;
return V_158 ;
}
void
F_128 (
T_10 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_48 * V_49 ;
int V_163 ;
V_49 = F_38 ( V_3 , F_39 ( V_3 , V_5 -> V_13 ) ) ;
F_20 ( & V_49 -> V_51 ) ;
F_129 ( V_5 ) ;
V_163 = F_24 ( & V_49 -> V_56 ,
V_115 ) ;
F_32 ( & V_49 -> V_56 ,
F_40 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_115 ) ;
if ( ! V_163 ) {
F_20 ( & V_5 -> V_16 -> V_53 ) ;
F_32 ( & V_5 -> V_16 -> V_40 ,
F_39 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_115 ) ;
F_21 ( & V_5 -> V_16 -> V_53 ) ;
F_83 ( V_5 -> V_16 ) ;
F_130 ( V_5 -> V_16 , V_49 -> V_54 ,
- 1 , V_55 ) ;
}
F_21 ( & V_49 -> V_51 ) ;
F_42 ( V_49 ) ;
}
void
F_118 (
T_10 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_48 * V_49 ;
V_49 = F_38 ( V_3 , F_39 ( V_3 , V_5 -> V_13 ) ) ;
F_20 ( & V_49 -> V_51 ) ;
F_131 ( V_5 ) ;
F_35 ( & V_49 -> V_56 ,
F_40 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_115 ) ;
if ( ! F_24 ( & V_49 -> V_56 , V_115 ) ) {
F_20 ( & V_5 -> V_16 -> V_53 ) ;
F_35 ( & V_5 -> V_16 -> V_40 ,
F_39 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_115 ) ;
F_21 ( & V_5 -> V_16 -> V_53 ) ;
F_132 ( V_5 -> V_16 , V_49 -> V_54 ,
- 1 , V_55 ) ;
}
F_21 ( & V_49 -> V_51 ) ;
F_42 ( V_49 ) ;
}
