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
ASSERT ( ! F_8 ( V_5 ) ) ;
ASSERT ( V_5 -> V_12 == 0 ) ;
V_5 -> V_12 = V_4 ;
V_5 -> V_13 = V_3 ;
memset ( & V_5 -> V_14 , 0 , sizeof( struct V_15 ) ) ;
V_5 -> V_16 = NULL ;
V_5 -> V_17 = NULL ;
V_5 -> V_18 = 0 ;
V_5 -> V_19 = V_20 ;
memset ( & V_5 -> V_21 , 0 , sizeof( V_22 ) ) ;
V_5 -> V_23 = 0 ;
V_5 -> V_24 = 0 ;
memset ( & V_5 -> V_25 , 0 , sizeof( V_5 -> V_25 ) ) ;
return V_5 ;
}
STATIC void
F_9 (
struct V_26 * V_27 )
{
struct V_28 * V_28 = F_10 ( V_27 , struct V_28 , V_29 ) ;
struct V_1 * V_5 = F_11 ( V_28 ) ;
switch ( F_4 ( V_5 ) -> V_9 & V_30 ) {
case V_31 :
case V_32 :
case V_33 :
F_12 ( V_5 , V_34 ) ;
break;
}
if ( V_5 -> V_16 )
F_12 ( V_5 , V_35 ) ;
if ( V_5 -> V_17 )
F_12 ( V_5 , V_36 ) ;
if ( V_5 -> V_37 ) {
ASSERT ( ! ( V_5 -> V_37 -> V_38 . V_39 & V_40 ) ) ;
F_13 ( V_5 ) ;
V_5 -> V_37 = NULL ;
}
F_5 ( V_6 , V_5 ) ;
}
static void
F_14 (
struct V_1 * V_5 )
{
ASSERT ( F_7 ( & V_5 -> V_11 ) == 0 ) ;
F_15 ( V_5 -> V_13 , V_10 ) ;
F_16 ( & F_4 ( V_5 ) -> V_29 , F_9 ) ;
}
void
F_17 (
struct V_1 * V_5 )
{
ASSERT ( ! F_8 ( V_5 ) ) ;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 = V_42 ;
V_5 -> V_12 = 0 ;
F_19 ( & V_5 -> V_41 ) ;
F_14 ( V_5 ) ;
}
static void
F_20 (
struct V_2 * V_3 )
{
F_21 () ;
if ( F_22 ( & V_3 -> V_43 , V_44 ) ) {
F_23 ( V_3 -> V_45 , & V_3 -> V_46 ,
F_24 ( V_47 / 6 * 10 ) ) ;
}
F_25 () ;
}
void
F_26 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_10 ( F_27 ( V_49 ) ,
struct V_2 , V_46 ) ;
F_28 ( V_3 , V_50 ) ;
F_20 ( V_3 ) ;
}
static void
F_29 (
struct V_51 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_53 ;
F_30 ( & V_52 -> V_54 ) ;
if ( V_52 -> V_55 ++ )
return;
F_18 ( & V_3 -> V_56 ) ;
F_31 ( & V_3 -> V_43 , V_52 -> V_57 ,
V_44 ) ;
F_19 ( & V_3 -> V_56 ) ;
F_20 ( V_3 ) ;
F_32 ( V_3 , V_52 -> V_57 , - 1 , V_58 ) ;
}
static void
F_33 (
struct V_51 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_53 ;
F_30 ( & V_52 -> V_54 ) ;
if ( -- V_52 -> V_55 )
return;
F_18 ( & V_3 -> V_56 ) ;
F_34 ( & V_3 -> V_43 , V_52 -> V_57 ,
V_44 ) ;
F_19 ( & V_3 -> V_56 ) ;
F_35 ( V_3 , V_52 -> V_57 , - 1 , V_58 ) ;
}
void
F_36 (
struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_13 ;
struct V_51 * V_52 ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_12 ) ) ;
F_18 ( & V_52 -> V_54 ) ;
F_18 ( & V_5 -> V_41 ) ;
F_31 ( & V_52 -> V_59 , F_39 ( V_3 , V_5 -> V_12 ) ,
V_44 ) ;
F_29 ( V_52 ) ;
F_40 ( V_5 , V_60 ) ;
F_19 ( & V_5 -> V_41 ) ;
F_19 ( & V_52 -> V_54 ) ;
F_41 ( V_52 ) ;
}
STATIC void
F_42 (
struct V_51 * V_52 ,
T_1 V_4 )
{
F_34 ( & V_52 -> V_59 ,
F_39 ( V_52 -> V_53 , V_4 ) ,
V_44 ) ;
F_33 ( V_52 ) ;
}
static void
F_43 (
struct V_1 * V_5 )
{
T_2 * V_61 = F_44 ( & V_5 -> V_23 , V_62 ) ;
F_45 ( V_63 , & V_5 -> V_23 , V_62 ) ;
do {
F_46 ( V_61 , & V_63 . V_63 , V_64 ) ;
if ( ! F_47 ( V_5 , V_65 ) )
break;
F_48 () ;
} while ( true );
F_49 ( V_61 , & V_63 . V_63 ) ;
}
static int
F_50 (
struct V_2 * V_3 ,
struct V_28 * V_28 )
{
int error ;
T_3 V_66 = V_28 -> V_67 ;
T_3 V_68 = V_28 -> V_69 ;
T_4 V_70 = V_28 -> V_71 ;
T_5 V_72 = V_28 -> V_9 ;
error = F_3 ( V_3 -> V_8 , V_28 ) ;
F_51 ( V_28 , V_66 ) ;
V_28 -> V_69 = V_68 ;
V_28 -> V_71 = V_70 ;
V_28 -> V_9 = V_72 ;
return error ;
}
static int
F_52 (
struct V_51 * V_52 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_73 ,
int V_74 ) __releases( T_6 )
{
struct V_28 * V_28 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_13 ;
int error ;
F_18 ( & V_5 -> V_41 ) ;
if ( V_5 -> V_12 != V_4 ) {
F_53 ( V_5 ) ;
F_6 ( V_3 , V_75 ) ;
error = - V_76 ;
goto V_77;
}
if ( V_5 -> V_23 & ( V_65 | V_42 ) ) {
F_53 ( V_5 ) ;
F_6 ( V_3 , V_75 ) ;
error = - V_76 ;
goto V_77;
}
if ( F_4 ( V_5 ) -> V_9 == 0 && ! ( V_73 & V_78 ) ) {
error = - V_79 ;
goto V_77;
}
if ( V_5 -> V_23 & V_60 ) {
F_54 ( V_5 ) ;
V_5 -> V_23 |= V_42 ;
F_19 ( & V_5 -> V_41 ) ;
F_25 () ;
error = F_50 ( V_3 , V_28 ) ;
if ( error ) {
bool V_80 ;
F_21 () ;
F_18 ( & V_5 -> V_41 ) ;
V_80 = ! ! F_55 ( V_5 , V_65 ) ;
V_5 -> V_23 &= ~ ( V_65 | V_42 ) ;
if ( V_80 )
F_56 ( & V_5 -> V_23 , V_62 ) ;
ASSERT ( V_5 -> V_23 & V_60 ) ;
F_57 ( V_5 ) ;
goto V_77;
}
F_18 ( & V_52 -> V_54 ) ;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 &= ~ V_81 ;
V_5 -> V_23 |= V_65 ;
F_42 ( V_52 , V_5 -> V_12 ) ;
V_28 -> V_82 = V_83 ;
ASSERT ( ! F_58 ( & V_28 -> V_84 ) ) ;
F_59 ( & V_28 -> V_84 ) ;
F_19 ( & V_5 -> V_41 ) ;
F_19 ( & V_52 -> V_54 ) ;
} else {
if ( ! F_60 ( V_28 ) ) {
F_53 ( V_5 ) ;
error = - V_76 ;
goto V_77;
}
F_19 ( & V_5 -> V_41 ) ;
F_25 () ;
F_61 ( V_5 ) ;
}
if ( V_74 != 0 )
F_62 ( V_5 , V_74 ) ;
F_63 ( V_5 , V_85 | V_86 ) ;
F_6 ( V_3 , V_87 ) ;
return 0 ;
V_77:
F_19 ( & V_5 -> V_41 ) ;
F_25 () ;
return error ;
}
static int
F_64 (
struct V_2 * V_3 ,
struct V_51 * V_52 ,
T_7 * V_88 ,
T_1 V_4 ,
struct V_1 * * V_89 ,
int V_73 ,
int V_74 )
{
struct V_1 * V_5 ;
int error ;
T_8 V_90 = F_39 ( V_3 , V_4 ) ;
int V_91 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_92 ;
error = F_65 ( V_3 , V_88 , V_5 , V_73 ) ;
if ( error )
goto V_93;
F_66 ( V_5 ) ;
if ( ( F_4 ( V_5 ) -> V_9 == 0 ) && ! ( V_73 & V_78 ) ) {
error = - V_79 ;
goto V_93;
}
if ( F_67 ( V_94 ) ) {
error = - V_76 ;
goto V_93;
}
if ( V_74 ) {
if ( ! F_68 ( V_5 , V_74 ) )
F_69 () ;
}
V_91 = V_65 ;
if ( V_73 & V_95 )
V_91 |= V_86 ;
V_5 -> V_96 = NULL ;
V_5 -> V_97 = NULL ;
V_5 -> V_98 = NULL ;
F_70 ( V_5 , V_91 ) ;
F_18 ( & V_52 -> V_54 ) ;
error = F_71 ( & V_52 -> V_59 , V_90 , V_5 ) ;
if ( F_72 ( error ) ) {
F_73 ( error != - V_99 ) ;
F_6 ( V_3 , V_100 ) ;
error = - V_76 ;
goto V_101;
}
F_19 ( & V_52 -> V_54 ) ;
F_74 () ;
* V_89 = V_5 ;
return 0 ;
V_101:
F_19 ( & V_52 -> V_54 ) ;
F_74 () ;
if ( V_74 )
F_75 ( V_5 , V_74 ) ;
V_93:
F_76 ( F_4 ( V_5 ) ) ;
F_17 ( V_5 ) ;
return error ;
}
int
F_77 (
T_9 * V_3 ,
T_7 * V_88 ,
T_1 V_4 ,
T_10 V_73 ,
T_10 V_74 ,
T_11 * * V_89 )
{
T_11 * V_5 ;
int error ;
T_12 * V_52 ;
T_8 V_90 ;
ASSERT ( ( V_74 & ( V_102 | V_103 ) ) == 0 ) ;
if ( ! V_4 || F_38 ( V_3 , V_4 ) >= V_3 -> V_104 . V_105 )
return - V_106 ;
F_6 ( V_3 , V_107 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_4 ) ) ;
V_90 = F_39 ( V_3 , V_4 ) ;
V_108:
error = 0 ;
F_21 () ;
V_5 = F_78 ( & V_52 -> V_59 , V_90 ) ;
if ( V_5 ) {
error = F_52 ( V_52 , V_5 , V_4 , V_73 , V_74 ) ;
if ( error )
goto V_109;
} else {
F_25 () ;
F_6 ( V_3 , V_110 ) ;
error = F_64 ( V_3 , V_52 , V_88 , V_4 , & V_5 ,
V_73 , V_74 ) ;
if ( error )
goto V_109;
}
F_41 ( V_52 ) ;
* V_89 = V_5 ;
if ( F_47 ( V_5 , V_65 ) && F_4 ( V_5 ) -> V_9 != 0 )
F_79 ( V_5 ) ;
return 0 ;
V_109:
if ( error == - V_76 ) {
F_80 ( 1 ) ;
goto V_108;
}
F_41 ( V_52 ) ;
return error ;
}
STATIC int
F_81 (
struct V_1 * V_5 ,
int V_73 )
{
struct V_28 * V_28 = F_4 ( V_5 ) ;
bool V_111 = ! ! ( V_73 & V_112 ) ;
ASSERT ( F_82 () ) ;
F_18 ( & V_5 -> V_41 ) ;
if ( ! V_5 -> V_12 )
goto V_113;
if ( ( ! V_111 && F_55 ( V_5 , V_65 ) ) ||
F_55 ( V_5 , V_60 | V_42 ) )
goto V_113;
F_19 ( & V_5 -> V_41 ) ;
if ( F_83 ( V_5 -> V_13 ) )
return - V_114 ;
if ( ! F_60 ( V_28 ) )
return - V_79 ;
return 0 ;
V_113:
F_19 ( & V_5 -> V_41 ) ;
return - V_79 ;
}
STATIC int
F_84 (
struct V_2 * V_3 ,
struct V_51 * V_52 ,
int (* F_85)( struct V_1 * V_5 , int V_73 ,
void * args ) ,
int V_73 ,
void * args ,
int V_115 ,
int V_116 )
{
T_3 V_117 ;
int V_118 = 0 ;
int V_119 ;
int V_120 ;
int V_121 ;
V_122:
V_120 = 0 ;
V_119 = 0 ;
V_117 = 0 ;
V_121 = 0 ;
do {
struct V_1 * V_123 [ V_124 ] ;
int error = 0 ;
int V_125 ;
F_21 () ;
if ( V_115 == - 1 )
V_121 = F_86 ( & V_52 -> V_59 ,
( void * * ) V_123 , V_117 ,
V_124 ) ;
else
V_121 = F_87 (
& V_52 -> V_59 ,
( void * * ) V_123 , V_117 ,
V_124 , V_115 ) ;
if ( ! V_121 ) {
F_25 () ;
break;
}
for ( V_125 = 0 ; V_125 < V_121 ; V_125 ++ ) {
struct V_1 * V_5 = V_123 [ V_125 ] ;
if ( V_120 || F_81 ( V_5 , V_116 ) )
V_123 [ V_125 ] = NULL ;
if ( F_38 ( V_3 , V_5 -> V_12 ) != V_52 -> V_57 )
continue;
V_117 = F_39 ( V_3 , V_5 -> V_12 + 1 ) ;
if ( V_117 < F_39 ( V_3 , V_5 -> V_12 ) )
V_120 = 1 ;
}
F_25 () ;
for ( V_125 = 0 ; V_125 < V_121 ; V_125 ++ ) {
if ( ! V_123 [ V_125 ] )
continue;
if ( ( V_116 & V_112 ) &&
F_47 ( V_123 [ V_125 ] , V_65 ) )
F_43 ( V_123 [ V_125 ] ) ;
error = F_85 ( V_123 [ V_125 ] , V_73 , args ) ;
F_88 ( V_123 [ V_125 ] ) ;
if ( error == - V_76 ) {
V_119 ++ ;
continue;
}
if ( error && V_118 != - V_114 )
V_118 = error ;
}
if ( error == - V_114 )
break;
F_89 () ;
} while ( V_121 && ! V_120 );
if ( V_119 ) {
F_80 ( 1 ) ;
goto V_122;
}
return V_118 ;
}
void
F_90 (
struct V_2 * V_3 )
{
F_21 () ;
if ( F_22 ( & V_3 -> V_43 , V_126 ) )
F_23 ( V_3 -> V_127 ,
& V_3 -> V_128 ,
F_24 ( V_129 * 1000 ) ) ;
F_25 () ;
}
void
F_91 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_10 ( F_27 ( V_49 ) ,
struct V_2 , V_128 ) ;
F_92 ( V_3 , NULL ) ;
F_90 ( V_3 ) ;
}
STATIC void
F_93 (
struct V_2 * V_3 )
{
F_21 () ;
if ( F_22 ( & V_3 -> V_43 , V_130 ) )
F_23 ( V_3 -> V_127 ,
& V_3 -> V_131 ,
F_24 ( V_132 * 1000 ) ) ;
F_25 () ;
}
void
F_94 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_10 ( F_27 ( V_49 ) ,
struct V_2 , V_131 ) ;
F_95 ( V_3 , NULL ) ;
F_93 ( V_3 ) ;
}
int
F_96 (
struct V_2 * V_3 ,
int (* F_85)( struct V_1 * V_5 , int V_73 ,
void * args ) ,
int V_73 ,
void * args ,
int V_116 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_118 = 0 ;
T_13 V_133 ;
V_133 = 0 ;
while ( ( V_52 = F_37 ( V_3 , V_133 ) ) ) {
V_133 = V_52 -> V_57 + 1 ;
error = F_84 ( V_3 , V_52 , F_85 , V_73 , args , - 1 ,
V_116 ) ;
F_41 ( V_52 ) ;
if ( error ) {
V_118 = error ;
if ( error == - V_114 )
break;
}
}
return V_118 ;
}
int
F_97 (
struct V_2 * V_3 ,
int (* F_85)( struct V_1 * V_5 , int V_73 ,
void * args ) ,
int V_73 ,
void * args )
{
return F_96 ( V_3 , F_85 , V_73 , args , 0 ) ;
}
int
F_98 (
struct V_2 * V_3 ,
int (* F_85)( struct V_1 * V_5 , int V_73 ,
void * args ) ,
int V_73 ,
void * args ,
int V_115 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_118 = 0 ;
T_13 V_133 ;
V_133 = 0 ;
while ( ( V_52 = F_99 ( V_3 , V_133 , V_115 ) ) ) {
V_133 = V_52 -> V_57 + 1 ;
error = F_84 ( V_3 , V_52 , F_85 , V_73 , args , V_115 ,
0 ) ;
F_41 ( V_52 ) ;
if ( error ) {
V_118 = error ;
if ( error == - V_114 )
break;
}
}
return V_118 ;
}
STATIC int
F_100 (
struct V_1 * V_5 ,
int V_73 )
{
ASSERT ( F_82 () ) ;
if ( ! V_5 -> V_12 )
return 1 ;
if ( ( V_73 & V_50 ) &&
F_55 ( V_5 , V_134 | V_42 ) )
return 1 ;
F_18 ( & V_5 -> V_41 ) ;
if ( ! F_55 ( V_5 , V_60 ) ||
F_55 ( V_5 , V_42 ) ) {
F_19 ( & V_5 -> V_41 ) ;
return 1 ;
}
F_40 ( V_5 , V_42 ) ;
F_19 ( & V_5 -> V_41 ) ;
return 0 ;
}
STATIC int
F_101 (
struct V_1 * V_5 ,
struct V_51 * V_52 ,
int V_135 )
{
struct V_136 * V_137 = NULL ;
T_1 V_4 = V_5 -> V_12 ;
int error ;
V_122:
error = 0 ;
F_62 ( V_5 , V_138 ) ;
if ( ! F_102 ( V_5 ) ) {
if ( ! ( V_135 & V_139 ) )
goto V_140;
F_103 ( V_5 ) ;
}
if ( F_83 ( V_5 -> V_13 ) ) {
F_104 ( V_5 ) ;
F_105 ( V_5 , false ) ;
goto V_141;
}
if ( F_106 ( V_5 ) ) {
if ( ! ( V_135 & V_139 ) )
goto V_142;
F_104 ( V_5 ) ;
}
if ( F_47 ( V_5 , V_85 ) || F_107 ( V_5 ) ) {
F_108 ( V_5 ) ;
goto V_141;
}
if ( ! ( V_135 & V_139 ) )
goto V_142;
error = F_109 ( V_5 , & V_137 ) ;
if ( error == - V_76 ) {
F_75 ( V_5 , V_138 ) ;
F_80 ( 2 ) ;
goto V_122;
}
if ( ! error ) {
error = F_110 ( V_137 ) ;
F_111 ( V_137 ) ;
}
V_141:
ASSERT ( ! F_8 ( V_5 ) ) ;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 = V_42 ;
V_5 -> V_12 = 0 ;
F_19 ( & V_5 -> V_41 ) ;
F_75 ( V_5 , V_138 ) ;
F_6 ( V_5 -> V_13 , V_143 ) ;
F_18 ( & V_52 -> V_54 ) ;
if ( ! F_112 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_13 , V_4 ) ) )
ASSERT ( 0 ) ;
F_33 ( V_52 ) ;
F_19 ( & V_52 -> V_54 ) ;
F_62 ( V_5 , V_138 ) ;
F_113 ( V_5 ) ;
F_75 ( V_5 , V_138 ) ;
F_14 ( V_5 ) ;
return error ;
V_142:
F_108 ( V_5 ) ;
V_140:
F_63 ( V_5 , V_42 ) ;
F_75 ( V_5 , V_138 ) ;
return 0 ;
}
STATIC int
F_114 (
struct V_2 * V_3 ,
int V_73 ,
int * V_144 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_118 = 0 ;
T_13 V_133 ;
int V_145 = V_73 & V_50 ;
int V_119 ;
V_122:
V_133 = 0 ;
V_119 = 0 ;
while ( ( V_52 = F_99 ( V_3 , V_133 , V_44 ) ) ) {
unsigned long V_117 = 0 ;
int V_120 = 0 ;
int V_121 = 0 ;
V_133 = V_52 -> V_57 + 1 ;
if ( V_145 ) {
if ( ! F_115 ( & V_52 -> V_146 ) ) {
V_119 ++ ;
F_41 ( V_52 ) ;
continue;
}
V_117 = V_52 -> V_147 ;
} else
F_116 ( & V_52 -> V_146 ) ;
do {
struct V_1 * V_123 [ V_124 ] ;
int V_125 ;
F_21 () ;
V_121 = F_87 (
& V_52 -> V_59 ,
( void * * ) V_123 , V_117 ,
V_124 ,
V_44 ) ;
if ( ! V_121 ) {
V_120 = 1 ;
F_25 () ;
break;
}
for ( V_125 = 0 ; V_125 < V_121 ; V_125 ++ ) {
struct V_1 * V_5 = V_123 [ V_125 ] ;
if ( V_120 || F_100 ( V_5 , V_73 ) )
V_123 [ V_125 ] = NULL ;
if ( F_38 ( V_3 , V_5 -> V_12 ) !=
V_52 -> V_57 )
continue;
V_117 = F_39 ( V_3 , V_5 -> V_12 + 1 ) ;
if ( V_117 < F_39 ( V_3 , V_5 -> V_12 ) )
V_120 = 1 ;
}
F_25 () ;
for ( V_125 = 0 ; V_125 < V_121 ; V_125 ++ ) {
if ( ! V_123 [ V_125 ] )
continue;
error = F_101 ( V_123 [ V_125 ] , V_52 , V_73 ) ;
if ( error && V_118 != - V_114 )
V_118 = error ;
}
* V_144 -= V_124 ;
F_89 () ;
} while ( V_121 && ! V_120 && * V_144 > 0 );
if ( V_145 && ! V_120 )
V_52 -> V_147 = V_117 ;
else
V_52 -> V_147 = 0 ;
F_117 ( & V_52 -> V_146 ) ;
F_41 ( V_52 ) ;
}
if ( V_119 && ( V_73 & V_139 ) && * V_144 > 0 ) {
V_145 = 0 ;
goto V_122;
}
return V_118 ;
}
int
F_28 (
T_9 * V_3 ,
int V_72 )
{
int V_144 = V_148 ;
return F_114 ( V_3 , V_72 , & V_144 ) ;
}
long
F_118 (
struct V_2 * V_3 ,
int V_144 )
{
F_20 ( V_3 ) ;
F_119 ( V_3 -> V_149 ) ;
return F_114 ( V_3 , V_50 | V_139 , & V_144 ) ;
}
int
F_120 (
struct V_2 * V_3 )
{
struct V_51 * V_52 ;
T_13 V_133 = 0 ;
int V_150 = 0 ;
while ( ( V_52 = F_99 ( V_3 , V_133 , V_44 ) ) ) {
V_133 = V_52 -> V_57 + 1 ;
V_150 += V_52 -> V_55 ;
F_41 ( V_52 ) ;
}
return V_150 ;
}
STATIC int
F_121 (
struct V_1 * V_5 ,
struct V_151 * V_152 )
{
if ( ( V_152 -> V_153 & V_154 ) &&
! F_122 ( F_4 ( V_5 ) -> V_155 , V_152 -> V_156 ) )
return 0 ;
if ( ( V_152 -> V_153 & V_157 ) &&
! F_123 ( F_4 ( V_5 ) -> V_158 , V_152 -> V_159 ) )
return 0 ;
if ( ( V_152 -> V_153 & V_160 ) &&
F_124 ( V_5 ) != V_152 -> V_161 )
return 0 ;
return 1 ;
}
STATIC int
F_125 (
struct V_1 * V_5 ,
struct V_151 * V_152 )
{
if ( ( V_152 -> V_153 & V_154 ) &&
F_122 ( F_4 ( V_5 ) -> V_155 , V_152 -> V_156 ) )
return 1 ;
if ( ( V_152 -> V_153 & V_157 ) &&
F_123 ( F_4 ( V_5 ) -> V_158 , V_152 -> V_159 ) )
return 1 ;
if ( ( V_152 -> V_153 & V_160 ) &&
F_124 ( V_5 ) == V_152 -> V_161 )
return 1 ;
return 0 ;
}
STATIC int
F_126 (
struct V_1 * V_5 ,
int V_73 ,
void * args )
{
int V_162 = 0 ;
struct V_151 * V_152 = args ;
int V_163 ;
if ( ! F_127 ( V_5 , false ) ) {
F_128 ( V_5 ) ;
F_129 ( V_5 ) ;
return 0 ;
}
if ( ! ( V_73 & V_139 ) &&
F_130 ( F_4 ( V_5 ) -> V_164 , V_165 ) )
return 0 ;
if ( V_152 ) {
if ( V_152 -> V_153 & V_166 )
V_163 = F_125 ( V_5 , V_152 ) ;
else
V_163 = F_121 ( V_5 , V_152 ) ;
if ( ! V_163 )
return 0 ;
if ( V_152 -> V_153 & V_167 &&
F_131 ( V_5 ) < V_152 -> V_168 )
return 0 ;
}
if ( ! F_68 ( V_5 , V_102 ) ) {
if ( V_73 & V_139 )
V_162 = - V_76 ;
return V_162 ;
}
V_162 = F_132 ( V_5 ) ;
F_75 ( V_5 , V_102 ) ;
return V_162 ;
}
static int
F_133 (
struct V_2 * V_3 ,
struct V_151 * V_152 ,
int (* F_85)( struct V_1 * V_5 , int V_73 ,
void * args ) ,
int V_115 )
{
int V_73 = V_50 ;
if ( V_152 && ( V_152 -> V_153 & V_169 ) )
V_73 = V_139 ;
return F_98 ( V_3 , F_85 , V_73 ,
V_152 , V_115 ) ;
}
int
F_92 (
struct V_2 * V_3 ,
struct V_151 * V_152 )
{
return F_133 ( V_3 , V_152 , F_126 ,
V_126 ) ;
}
static int
F_134 (
struct V_1 * V_5 ,
int (* F_85)( struct V_2 * V_3 ,
struct V_151 * V_152 ) )
{
int V_170 = 0 ;
struct V_151 V_152 = { 0 } ;
struct V_171 * V_172 ;
V_152 . V_153 = V_166 | V_169 ;
if ( F_135 ( V_5 -> V_13 ) ) {
V_172 = F_136 ( V_5 , V_173 ) ;
if ( V_172 && F_137 ( V_172 ) ) {
V_152 . V_156 = F_4 ( V_5 ) -> V_155 ;
V_152 . V_153 |= V_154 ;
V_170 = 1 ;
}
}
if ( F_138 ( V_5 -> V_13 ) ) {
V_172 = F_136 ( V_5 , V_174 ) ;
if ( V_172 && F_137 ( V_172 ) ) {
V_152 . V_159 = F_4 ( V_5 ) -> V_158 ;
V_152 . V_153 |= V_157 ;
V_170 = 1 ;
}
}
if ( V_170 )
F_85 ( V_5 -> V_13 , & V_152 ) ;
return V_170 ;
}
int
F_139 (
struct V_1 * V_5 )
{
return F_134 ( V_5 , F_92 ) ;
}
static void
F_140 (
T_11 * V_5 ,
void (* F_85)( struct V_2 * V_3 ) ,
void (* F_141)( struct V_2 * V_3 , T_13 V_175 ,
int error , unsigned long V_176 ) ,
int V_115 )
{
struct V_2 * V_3 = V_5 -> V_13 ;
struct V_51 * V_52 ;
int V_177 ;
if ( V_5 -> V_23 & V_178 )
return;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 |= V_178 ;
F_19 ( & V_5 -> V_41 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_12 ) ) ;
F_18 ( & V_52 -> V_54 ) ;
V_177 = F_22 ( & V_52 -> V_59 , V_115 ) ;
F_31 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_13 , V_5 -> V_12 ) , V_115 ) ;
if ( ! V_177 ) {
F_18 ( & V_5 -> V_13 -> V_56 ) ;
F_31 ( & V_5 -> V_13 -> V_43 ,
F_38 ( V_5 -> V_13 , V_5 -> V_12 ) ,
V_115 ) ;
F_19 ( & V_5 -> V_13 -> V_56 ) ;
F_85 ( V_5 -> V_13 ) ;
F_141 ( V_5 -> V_13 , V_52 -> V_57 , - 1 , V_58 ) ;
}
F_19 ( & V_52 -> V_54 ) ;
F_41 ( V_52 ) ;
}
void
F_142 (
T_11 * V_5 )
{
F_143 ( V_5 ) ;
return F_140 ( V_5 , F_90 ,
V_179 ,
V_126 ) ;
}
static void
F_144 (
T_11 * V_5 ,
void (* F_145)( struct V_2 * V_3 , T_13 V_175 ,
int error , unsigned long V_176 ) ,
int V_115 )
{
struct V_2 * V_3 = V_5 -> V_13 ;
struct V_51 * V_52 ;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 &= ~ V_178 ;
F_19 ( & V_5 -> V_41 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_12 ) ) ;
F_18 ( & V_52 -> V_54 ) ;
F_34 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_13 , V_5 -> V_12 ) , V_115 ) ;
if ( ! F_22 ( & V_52 -> V_59 , V_115 ) ) {
F_18 ( & V_5 -> V_13 -> V_56 ) ;
F_34 ( & V_5 -> V_13 -> V_43 ,
F_38 ( V_5 -> V_13 , V_5 -> V_12 ) ,
V_115 ) ;
F_19 ( & V_5 -> V_13 -> V_56 ) ;
F_145 ( V_5 -> V_13 , V_52 -> V_57 , - 1 , V_58 ) ;
}
F_19 ( & V_52 -> V_54 ) ;
F_41 ( V_52 ) ;
}
void
F_129 (
T_11 * V_5 )
{
F_146 ( V_5 ) ;
return F_144 ( V_5 ,
V_180 , V_126 ) ;
}
STATIC int
F_147 (
struct V_1 * V_5 ,
int V_73 ,
void * args )
{
int V_162 ;
struct V_151 * V_152 = args ;
int V_163 ;
struct V_181 * V_182 = F_148 ( V_5 , V_36 ) ;
if ( ! F_149 ( V_5 ) || ! V_182 -> V_183 ) {
F_150 ( V_5 ) ;
F_151 ( V_5 ) ;
return 0 ;
}
if ( ( F_4 ( V_5 ) -> V_82 & V_184 ) ||
F_130 ( F_4 ( V_5 ) -> V_164 , V_165 ) ||
F_130 ( F_4 ( V_5 ) -> V_164 , V_185 ) ||
F_7 ( & F_4 ( V_5 ) -> V_186 ) )
return 0 ;
if ( V_152 ) {
if ( V_152 -> V_153 & V_166 )
V_163 = F_125 ( V_5 , V_152 ) ;
else
V_163 = F_121 ( V_5 , V_152 ) ;
if ( ! V_163 )
return 0 ;
if ( V_152 -> V_153 & V_167 &&
F_131 ( V_5 ) < V_152 -> V_168 )
return 0 ;
}
F_62 ( V_5 , V_102 ) ;
F_62 ( V_5 , V_187 ) ;
V_162 = F_152 ( V_5 , 0 , V_188 , false ) ;
F_75 ( V_5 , V_187 ) ;
F_75 ( V_5 , V_102 ) ;
return V_162 ;
}
int
F_95 (
struct V_2 * V_3 ,
struct V_151 * V_152 )
{
return F_133 ( V_3 , V_152 , F_147 ,
V_130 ) ;
}
int
F_153 (
struct V_1 * V_5 )
{
return F_134 ( V_5 , F_95 ) ;
}
void
F_154 (
T_11 * V_5 )
{
F_155 ( V_5 ) ;
return F_140 ( V_5 , F_93 ,
V_189 ,
V_130 ) ;
}
void
F_151 (
T_11 * V_5 )
{
F_156 ( V_5 ) ;
return F_144 ( V_5 ,
V_190 , V_130 ) ;
}
