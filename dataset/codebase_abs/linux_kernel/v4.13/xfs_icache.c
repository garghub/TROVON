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
F_46 ( V_61 , & V_63 . V_64 , V_65 ) ;
if ( ! F_47 ( V_5 , V_66 ) )
break;
F_48 () ;
} while ( true );
F_49 ( V_61 , & V_63 . V_64 ) ;
}
static int
F_50 (
struct V_2 * V_3 ,
struct V_28 * V_28 )
{
int error ;
T_3 V_67 = V_28 -> V_68 ;
T_3 V_69 = V_28 -> V_70 ;
T_4 V_71 = V_28 -> V_72 ;
T_5 V_73 = V_28 -> V_9 ;
error = F_3 ( V_3 -> V_8 , V_28 ) ;
F_51 ( V_28 , V_67 ) ;
V_28 -> V_70 = V_69 ;
V_28 -> V_72 = V_71 ;
V_28 -> V_9 = V_73 ;
return error ;
}
static int
F_52 (
struct V_51 * V_52 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_74 ,
int V_75 ) __releases( T_6 )
{
struct V_28 * V_28 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_13 ;
int error ;
F_18 ( & V_5 -> V_41 ) ;
if ( V_5 -> V_12 != V_4 ) {
F_53 ( V_5 ) ;
F_6 ( V_3 , V_76 ) ;
error = - V_77 ;
goto V_78;
}
if ( V_5 -> V_23 & ( V_66 | V_42 ) ) {
F_53 ( V_5 ) ;
F_6 ( V_3 , V_76 ) ;
error = - V_77 ;
goto V_78;
}
if ( F_4 ( V_5 ) -> V_9 == 0 && ! ( V_74 & V_79 ) ) {
error = - V_80 ;
goto V_78;
}
if ( V_5 -> V_23 & V_60 ) {
F_54 ( V_5 ) ;
if ( V_74 & V_81 ) {
error = - V_77 ;
goto V_78;
}
V_5 -> V_23 |= V_42 ;
F_19 ( & V_5 -> V_41 ) ;
F_25 () ;
error = F_50 ( V_3 , V_28 ) ;
if ( error ) {
bool V_82 ;
F_21 () ;
F_18 ( & V_5 -> V_41 ) ;
V_82 = ! ! F_55 ( V_5 , V_66 ) ;
V_5 -> V_23 &= ~ ( V_66 | V_42 ) ;
if ( V_82 )
F_56 ( & V_5 -> V_23 , V_62 ) ;
ASSERT ( V_5 -> V_23 & V_60 ) ;
F_57 ( V_5 ) ;
goto V_78;
}
F_18 ( & V_52 -> V_54 ) ;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 &= ~ V_83 ;
V_5 -> V_23 |= V_66 ;
F_42 ( V_52 , V_5 -> V_12 ) ;
V_28 -> V_84 = V_85 ;
ASSERT ( ! F_58 ( & V_28 -> V_86 ) ) ;
F_59 ( & V_28 -> V_86 ) ;
F_19 ( & V_5 -> V_41 ) ;
F_19 ( & V_52 -> V_54 ) ;
} else {
if ( ! F_60 ( V_28 ) ) {
F_53 ( V_5 ) ;
error = - V_77 ;
goto V_78;
}
F_19 ( & V_5 -> V_41 ) ;
F_25 () ;
F_61 ( V_5 ) ;
}
if ( V_75 != 0 )
F_62 ( V_5 , V_75 ) ;
if ( ! ( V_74 & V_81 ) )
F_63 ( V_5 , V_87 | V_88 ) ;
F_6 ( V_3 , V_89 ) ;
return 0 ;
V_78:
F_19 ( & V_5 -> V_41 ) ;
F_25 () ;
return error ;
}
static int
F_64 (
struct V_2 * V_3 ,
struct V_51 * V_52 ,
T_7 * V_90 ,
T_1 V_4 ,
struct V_1 * * V_91 ,
int V_74 ,
int V_75 )
{
struct V_1 * V_5 ;
int error ;
T_8 V_92 = F_39 ( V_3 , V_4 ) ;
int V_93 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_94 ;
error = F_65 ( V_3 , V_90 , V_5 , V_74 ) ;
if ( error )
goto V_95;
F_66 ( V_5 ) ;
if ( ( F_4 ( V_5 ) -> V_9 == 0 ) && ! ( V_74 & V_79 ) ) {
error = - V_80 ;
goto V_95;
}
if ( F_67 ( V_96 ) ) {
error = - V_77 ;
goto V_95;
}
if ( V_75 ) {
if ( ! F_68 ( V_5 , V_75 ) )
F_69 () ;
}
V_93 = V_66 ;
if ( V_74 & V_97 )
V_93 |= V_88 ;
V_5 -> V_98 = NULL ;
V_5 -> V_99 = NULL ;
V_5 -> V_100 = NULL ;
F_70 ( V_5 , V_93 ) ;
F_18 ( & V_52 -> V_54 ) ;
error = F_71 ( & V_52 -> V_59 , V_92 , V_5 ) ;
if ( F_72 ( error ) ) {
F_73 ( error != - V_101 ) ;
F_6 ( V_3 , V_102 ) ;
error = - V_77 ;
goto V_103;
}
F_19 ( & V_52 -> V_54 ) ;
F_74 () ;
* V_91 = V_5 ;
return 0 ;
V_103:
F_19 ( & V_52 -> V_54 ) ;
F_74 () ;
if ( V_75 )
F_75 ( V_5 , V_75 ) ;
V_95:
F_76 ( F_4 ( V_5 ) ) ;
F_17 ( V_5 ) ;
return error ;
}
int
F_77 (
T_9 * V_3 ,
T_7 * V_90 ,
T_1 V_4 ,
T_10 V_74 ,
T_10 V_75 ,
T_11 * * V_91 )
{
T_11 * V_5 ;
int error ;
T_12 * V_52 ;
T_8 V_92 ;
ASSERT ( ( V_75 & ( V_104 | V_105 ) ) == 0 ) ;
if ( ! V_4 || F_38 ( V_3 , V_4 ) >= V_3 -> V_106 . V_107 )
return - V_108 ;
F_6 ( V_3 , V_109 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_4 ) ) ;
V_92 = F_39 ( V_3 , V_4 ) ;
V_110:
error = 0 ;
F_21 () ;
V_5 = F_78 ( & V_52 -> V_59 , V_92 ) ;
if ( V_5 ) {
error = F_52 ( V_52 , V_5 , V_4 , V_74 , V_75 ) ;
if ( error )
goto V_111;
} else {
F_25 () ;
if ( V_74 & V_81 ) {
error = - V_80 ;
goto V_111;
}
F_6 ( V_3 , V_112 ) ;
error = F_64 ( V_3 , V_52 , V_90 , V_4 , & V_5 ,
V_74 , V_75 ) ;
if ( error )
goto V_111;
}
F_41 ( V_52 ) ;
* V_91 = V_5 ;
if ( F_47 ( V_5 , V_66 ) && F_4 ( V_5 ) -> V_9 != 0 )
F_79 ( V_5 ) ;
return 0 ;
V_111:
if ( ! ( V_74 & V_81 ) && error == - V_77 ) {
F_80 ( 1 ) ;
goto V_110;
}
F_41 ( V_52 ) ;
return error ;
}
int
F_81 (
struct V_2 * V_3 ,
struct V_113 * V_90 ,
T_1 V_4 ,
bool * V_114 )
{
struct V_1 * V_5 ;
int error ;
error = F_77 ( V_3 , V_90 , V_4 , V_81 , 0 , & V_5 ) ;
if ( error )
return error ;
* V_114 = ! ! ( F_4 ( V_5 ) -> V_9 ) ;
F_82 ( V_5 ) ;
return 0 ;
}
STATIC int
F_83 (
struct V_1 * V_5 ,
int V_74 )
{
struct V_28 * V_28 = F_4 ( V_5 ) ;
bool V_115 = ! ! ( V_74 & V_116 ) ;
ASSERT ( F_84 () ) ;
F_18 ( & V_5 -> V_41 ) ;
if ( ! V_5 -> V_12 )
goto V_117;
if ( ( ! V_115 && F_55 ( V_5 , V_66 ) ) ||
F_55 ( V_5 , V_60 | V_42 ) )
goto V_117;
F_19 ( & V_5 -> V_41 ) ;
if ( F_85 ( V_5 -> V_13 ) )
return - V_118 ;
if ( ! F_60 ( V_28 ) )
return - V_80 ;
return 0 ;
V_117:
F_19 ( & V_5 -> V_41 ) ;
return - V_80 ;
}
STATIC int
F_86 (
struct V_2 * V_3 ,
struct V_51 * V_52 ,
int (* F_87)( struct V_1 * V_5 , int V_74 ,
void * args ) ,
int V_74 ,
void * args ,
int V_119 ,
int V_120 )
{
T_3 V_121 ;
int V_122 = 0 ;
int V_123 ;
int V_124 ;
int V_125 ;
V_126:
V_124 = 0 ;
V_123 = 0 ;
V_121 = 0 ;
V_125 = 0 ;
do {
struct V_1 * V_127 [ V_128 ] ;
int error = 0 ;
int V_129 ;
F_21 () ;
if ( V_119 == - 1 )
V_125 = F_88 ( & V_52 -> V_59 ,
( void * * ) V_127 , V_121 ,
V_128 ) ;
else
V_125 = F_89 (
& V_52 -> V_59 ,
( void * * ) V_127 , V_121 ,
V_128 , V_119 ) ;
if ( ! V_125 ) {
F_25 () ;
break;
}
for ( V_129 = 0 ; V_129 < V_125 ; V_129 ++ ) {
struct V_1 * V_5 = V_127 [ V_129 ] ;
if ( V_124 || F_83 ( V_5 , V_120 ) )
V_127 [ V_129 ] = NULL ;
if ( F_38 ( V_3 , V_5 -> V_12 ) != V_52 -> V_57 )
continue;
V_121 = F_39 ( V_3 , V_5 -> V_12 + 1 ) ;
if ( V_121 < F_39 ( V_3 , V_5 -> V_12 ) )
V_124 = 1 ;
}
F_25 () ;
for ( V_129 = 0 ; V_129 < V_125 ; V_129 ++ ) {
if ( ! V_127 [ V_129 ] )
continue;
if ( ( V_120 & V_116 ) &&
F_47 ( V_127 [ V_129 ] , V_66 ) )
F_43 ( V_127 [ V_129 ] ) ;
error = F_87 ( V_127 [ V_129 ] , V_74 , args ) ;
F_82 ( V_127 [ V_129 ] ) ;
if ( error == - V_77 ) {
V_123 ++ ;
continue;
}
if ( error && V_122 != - V_118 )
V_122 = error ;
}
if ( error == - V_118 )
break;
F_90 () ;
} while ( V_125 && ! V_124 );
if ( V_123 ) {
F_80 ( 1 ) ;
goto V_126;
}
return V_122 ;
}
void
F_91 (
struct V_2 * V_3 )
{
F_21 () ;
if ( F_22 ( & V_3 -> V_43 , V_130 ) )
F_23 ( V_3 -> V_131 ,
& V_3 -> V_132 ,
F_24 ( V_133 * 1000 ) ) ;
F_25 () ;
}
void
F_92 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_10 ( F_27 ( V_49 ) ,
struct V_2 , V_132 ) ;
F_93 ( V_3 , NULL ) ;
F_91 ( V_3 ) ;
}
STATIC void
F_94 (
struct V_2 * V_3 )
{
F_21 () ;
if ( F_22 ( & V_3 -> V_43 , V_134 ) )
F_23 ( V_3 -> V_131 ,
& V_3 -> V_135 ,
F_24 ( V_136 * 1000 ) ) ;
F_25 () ;
}
void
F_95 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_10 ( F_27 ( V_49 ) ,
struct V_2 , V_135 ) ;
F_96 ( V_3 , NULL ) ;
F_94 ( V_3 ) ;
}
int
F_97 (
struct V_2 * V_3 ,
int (* F_87)( struct V_1 * V_5 , int V_74 ,
void * args ) ,
int V_74 ,
void * args ,
int V_120 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_122 = 0 ;
T_13 V_137 ;
V_137 = 0 ;
while ( ( V_52 = F_37 ( V_3 , V_137 ) ) ) {
V_137 = V_52 -> V_57 + 1 ;
error = F_86 ( V_3 , V_52 , F_87 , V_74 , args , - 1 ,
V_120 ) ;
F_41 ( V_52 ) ;
if ( error ) {
V_122 = error ;
if ( error == - V_118 )
break;
}
}
return V_122 ;
}
int
F_98 (
struct V_2 * V_3 ,
int (* F_87)( struct V_1 * V_5 , int V_74 ,
void * args ) ,
int V_74 ,
void * args )
{
return F_97 ( V_3 , F_87 , V_74 , args , 0 ) ;
}
int
F_99 (
struct V_2 * V_3 ,
int (* F_87)( struct V_1 * V_5 , int V_74 ,
void * args ) ,
int V_74 ,
void * args ,
int V_119 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_122 = 0 ;
T_13 V_137 ;
V_137 = 0 ;
while ( ( V_52 = F_100 ( V_3 , V_137 , V_119 ) ) ) {
V_137 = V_52 -> V_57 + 1 ;
error = F_86 ( V_3 , V_52 , F_87 , V_74 , args , V_119 ,
0 ) ;
F_41 ( V_52 ) ;
if ( error ) {
V_122 = error ;
if ( error == - V_118 )
break;
}
}
return V_122 ;
}
STATIC int
F_101 (
struct V_1 * V_5 ,
int V_74 )
{
ASSERT ( F_84 () ) ;
if ( ! V_5 -> V_12 )
return 1 ;
if ( ( V_74 & V_50 ) &&
F_55 ( V_5 , V_138 | V_42 ) )
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
F_102 (
struct V_1 * V_5 ,
struct V_51 * V_52 ,
int V_139 )
{
struct V_140 * V_141 = NULL ;
T_1 V_4 = V_5 -> V_12 ;
int error ;
V_126:
error = 0 ;
F_62 ( V_5 , V_142 ) ;
if ( ! F_103 ( V_5 ) ) {
if ( ! ( V_139 & V_143 ) )
goto V_144;
F_104 ( V_5 ) ;
}
if ( F_85 ( V_5 -> V_13 ) ) {
F_105 ( V_5 ) ;
F_106 ( V_5 , false ) ;
goto V_145;
}
if ( F_107 ( V_5 ) ) {
if ( ! ( V_139 & V_143 ) )
goto V_146;
F_105 ( V_5 ) ;
}
if ( F_47 ( V_5 , V_87 ) || F_108 ( V_5 ) ) {
F_109 ( V_5 ) ;
goto V_145;
}
if ( ! ( V_139 & V_143 ) )
goto V_146;
error = F_110 ( V_5 , & V_141 ) ;
if ( error == - V_77 ) {
F_75 ( V_5 , V_142 ) ;
F_80 ( 2 ) ;
goto V_126;
}
if ( ! error ) {
error = F_111 ( V_141 ) ;
F_112 ( V_141 ) ;
}
V_145:
ASSERT ( ! F_8 ( V_5 ) ) ;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 = V_42 ;
V_5 -> V_12 = 0 ;
F_19 ( & V_5 -> V_41 ) ;
F_75 ( V_5 , V_142 ) ;
F_6 ( V_5 -> V_13 , V_147 ) ;
F_18 ( & V_52 -> V_54 ) ;
if ( ! F_113 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_13 , V_4 ) ) )
ASSERT ( 0 ) ;
F_33 ( V_52 ) ;
F_19 ( & V_52 -> V_54 ) ;
F_62 ( V_5 , V_142 ) ;
F_114 ( V_5 ) ;
F_75 ( V_5 , V_142 ) ;
F_14 ( V_5 ) ;
return error ;
V_146:
F_109 ( V_5 ) ;
V_144:
F_63 ( V_5 , V_42 ) ;
F_75 ( V_5 , V_142 ) ;
return 0 ;
}
STATIC int
F_115 (
struct V_2 * V_3 ,
int V_74 ,
int * V_148 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_122 = 0 ;
T_13 V_137 ;
int V_149 = V_74 & V_50 ;
int V_123 ;
V_126:
V_137 = 0 ;
V_123 = 0 ;
while ( ( V_52 = F_100 ( V_3 , V_137 , V_44 ) ) ) {
unsigned long V_121 = 0 ;
int V_124 = 0 ;
int V_125 = 0 ;
V_137 = V_52 -> V_57 + 1 ;
if ( V_149 ) {
if ( ! F_116 ( & V_52 -> V_150 ) ) {
V_123 ++ ;
F_41 ( V_52 ) ;
continue;
}
V_121 = V_52 -> V_151 ;
} else
F_117 ( & V_52 -> V_150 ) ;
do {
struct V_1 * V_127 [ V_128 ] ;
int V_129 ;
F_21 () ;
V_125 = F_89 (
& V_52 -> V_59 ,
( void * * ) V_127 , V_121 ,
V_128 ,
V_44 ) ;
if ( ! V_125 ) {
V_124 = 1 ;
F_25 () ;
break;
}
for ( V_129 = 0 ; V_129 < V_125 ; V_129 ++ ) {
struct V_1 * V_5 = V_127 [ V_129 ] ;
if ( V_124 || F_101 ( V_5 , V_74 ) )
V_127 [ V_129 ] = NULL ;
if ( F_38 ( V_3 , V_5 -> V_12 ) !=
V_52 -> V_57 )
continue;
V_121 = F_39 ( V_3 , V_5 -> V_12 + 1 ) ;
if ( V_121 < F_39 ( V_3 , V_5 -> V_12 ) )
V_124 = 1 ;
}
F_25 () ;
for ( V_129 = 0 ; V_129 < V_125 ; V_129 ++ ) {
if ( ! V_127 [ V_129 ] )
continue;
error = F_102 ( V_127 [ V_129 ] , V_52 , V_74 ) ;
if ( error && V_122 != - V_118 )
V_122 = error ;
}
* V_148 -= V_128 ;
F_90 () ;
} while ( V_125 && ! V_124 && * V_148 > 0 );
if ( V_149 && ! V_124 )
V_52 -> V_151 = V_121 ;
else
V_52 -> V_151 = 0 ;
F_118 ( & V_52 -> V_150 ) ;
F_41 ( V_52 ) ;
}
if ( V_123 && ( V_74 & V_143 ) && * V_148 > 0 ) {
V_149 = 0 ;
goto V_126;
}
return V_122 ;
}
int
F_28 (
T_9 * V_3 ,
int V_73 )
{
int V_148 = V_152 ;
return F_115 ( V_3 , V_73 , & V_148 ) ;
}
long
F_119 (
struct V_2 * V_3 ,
int V_148 )
{
F_20 ( V_3 ) ;
F_120 ( V_3 -> V_153 ) ;
return F_115 ( V_3 , V_50 | V_143 , & V_148 ) ;
}
int
F_121 (
struct V_2 * V_3 )
{
struct V_51 * V_52 ;
T_13 V_137 = 0 ;
int V_154 = 0 ;
while ( ( V_52 = F_100 ( V_3 , V_137 , V_44 ) ) ) {
V_137 = V_52 -> V_57 + 1 ;
V_154 += V_52 -> V_55 ;
F_41 ( V_52 ) ;
}
return V_154 ;
}
STATIC int
F_122 (
struct V_1 * V_5 ,
struct V_155 * V_156 )
{
if ( ( V_156 -> V_157 & V_158 ) &&
! F_123 ( F_4 ( V_5 ) -> V_159 , V_156 -> V_160 ) )
return 0 ;
if ( ( V_156 -> V_157 & V_161 ) &&
! F_124 ( F_4 ( V_5 ) -> V_162 , V_156 -> V_163 ) )
return 0 ;
if ( ( V_156 -> V_157 & V_164 ) &&
F_125 ( V_5 ) != V_156 -> V_165 )
return 0 ;
return 1 ;
}
STATIC int
F_126 (
struct V_1 * V_5 ,
struct V_155 * V_156 )
{
if ( ( V_156 -> V_157 & V_158 ) &&
F_123 ( F_4 ( V_5 ) -> V_159 , V_156 -> V_160 ) )
return 1 ;
if ( ( V_156 -> V_157 & V_161 ) &&
F_124 ( F_4 ( V_5 ) -> V_162 , V_156 -> V_163 ) )
return 1 ;
if ( ( V_156 -> V_157 & V_164 ) &&
F_125 ( V_5 ) == V_156 -> V_165 )
return 1 ;
return 0 ;
}
STATIC int
F_127 (
struct V_1 * V_5 ,
int V_74 ,
void * args )
{
int V_166 = 0 ;
struct V_155 * V_156 = args ;
int V_167 ;
if ( ! F_128 ( V_5 , false ) ) {
F_129 ( V_5 ) ;
F_130 ( V_5 ) ;
return 0 ;
}
if ( ! ( V_74 & V_143 ) &&
F_131 ( F_4 ( V_5 ) -> V_168 , V_169 ) )
return 0 ;
if ( V_156 ) {
if ( V_156 -> V_157 & V_170 )
V_167 = F_126 ( V_5 , V_156 ) ;
else
V_167 = F_122 ( V_5 , V_156 ) ;
if ( ! V_167 )
return 0 ;
if ( V_156 -> V_157 & V_171 &&
F_132 ( V_5 ) < V_156 -> V_172 )
return 0 ;
}
if ( ! F_68 ( V_5 , V_104 ) ) {
if ( V_74 & V_143 )
V_166 = - V_77 ;
return V_166 ;
}
V_166 = F_133 ( V_5 ) ;
F_75 ( V_5 , V_104 ) ;
return V_166 ;
}
static int
F_134 (
struct V_2 * V_3 ,
struct V_155 * V_156 ,
int (* F_87)( struct V_1 * V_5 , int V_74 ,
void * args ) ,
int V_119 )
{
int V_74 = V_50 ;
if ( V_156 && ( V_156 -> V_157 & V_173 ) )
V_74 = V_143 ;
return F_99 ( V_3 , F_87 , V_74 ,
V_156 , V_119 ) ;
}
int
F_93 (
struct V_2 * V_3 ,
struct V_155 * V_156 )
{
return F_134 ( V_3 , V_156 , F_127 ,
V_130 ) ;
}
static int
F_135 (
struct V_1 * V_5 ,
int (* F_87)( struct V_2 * V_3 ,
struct V_155 * V_156 ) )
{
int V_174 = 0 ;
struct V_155 V_156 = { 0 } ;
struct V_175 * V_176 ;
V_156 . V_157 = V_170 | V_173 ;
if ( F_136 ( V_5 -> V_13 ) ) {
V_176 = F_137 ( V_5 , V_177 ) ;
if ( V_176 && F_138 ( V_176 ) ) {
V_156 . V_160 = F_4 ( V_5 ) -> V_159 ;
V_156 . V_157 |= V_158 ;
V_174 = 1 ;
}
}
if ( F_139 ( V_5 -> V_13 ) ) {
V_176 = F_137 ( V_5 , V_178 ) ;
if ( V_176 && F_138 ( V_176 ) ) {
V_156 . V_163 = F_4 ( V_5 ) -> V_162 ;
V_156 . V_157 |= V_161 ;
V_174 = 1 ;
}
}
if ( V_174 )
F_87 ( V_5 -> V_13 , & V_156 ) ;
return V_174 ;
}
int
F_140 (
struct V_1 * V_5 )
{
return F_135 ( V_5 , F_93 ) ;
}
static void
F_141 (
T_11 * V_5 ,
void (* F_87)( struct V_2 * V_3 ) ,
void (* F_142)( struct V_2 * V_3 , T_13 V_179 ,
int error , unsigned long V_180 ) ,
int V_119 )
{
struct V_2 * V_3 = V_5 -> V_13 ;
struct V_51 * V_52 ;
int V_181 ;
if ( V_5 -> V_23 & V_182 )
return;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 |= V_182 ;
F_19 ( & V_5 -> V_41 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_12 ) ) ;
F_18 ( & V_52 -> V_54 ) ;
V_181 = F_22 ( & V_52 -> V_59 , V_119 ) ;
F_31 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_13 , V_5 -> V_12 ) , V_119 ) ;
if ( ! V_181 ) {
F_18 ( & V_5 -> V_13 -> V_56 ) ;
F_31 ( & V_5 -> V_13 -> V_43 ,
F_38 ( V_5 -> V_13 , V_5 -> V_12 ) ,
V_119 ) ;
F_19 ( & V_5 -> V_13 -> V_56 ) ;
F_87 ( V_5 -> V_13 ) ;
F_142 ( V_5 -> V_13 , V_52 -> V_57 , - 1 , V_58 ) ;
}
F_19 ( & V_52 -> V_54 ) ;
F_41 ( V_52 ) ;
}
void
F_143 (
T_11 * V_5 )
{
F_144 ( V_5 ) ;
return F_141 ( V_5 , F_91 ,
V_183 ,
V_130 ) ;
}
static void
F_145 (
T_11 * V_5 ,
void (* F_146)( struct V_2 * V_3 , T_13 V_179 ,
int error , unsigned long V_180 ) ,
int V_119 )
{
struct V_2 * V_3 = V_5 -> V_13 ;
struct V_51 * V_52 ;
F_18 ( & V_5 -> V_41 ) ;
V_5 -> V_23 &= ~ V_182 ;
F_19 ( & V_5 -> V_41 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_12 ) ) ;
F_18 ( & V_52 -> V_54 ) ;
F_34 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_13 , V_5 -> V_12 ) , V_119 ) ;
if ( ! F_22 ( & V_52 -> V_59 , V_119 ) ) {
F_18 ( & V_5 -> V_13 -> V_56 ) ;
F_34 ( & V_5 -> V_13 -> V_43 ,
F_38 ( V_5 -> V_13 , V_5 -> V_12 ) ,
V_119 ) ;
F_19 ( & V_5 -> V_13 -> V_56 ) ;
F_146 ( V_5 -> V_13 , V_52 -> V_57 , - 1 , V_58 ) ;
}
F_19 ( & V_52 -> V_54 ) ;
F_41 ( V_52 ) ;
}
void
F_130 (
T_11 * V_5 )
{
F_147 ( V_5 ) ;
return F_145 ( V_5 ,
V_184 , V_130 ) ;
}
STATIC int
F_148 (
struct V_1 * V_5 ,
int V_74 ,
void * args )
{
int V_166 ;
struct V_155 * V_156 = args ;
int V_167 ;
struct V_185 * V_186 = F_149 ( V_5 , V_36 ) ;
if ( ! F_150 ( V_5 ) || ! V_186 -> V_187 ) {
F_151 ( V_5 ) ;
F_152 ( V_5 ) ;
return 0 ;
}
if ( ( F_4 ( V_5 ) -> V_84 & V_188 ) ||
F_131 ( F_4 ( V_5 ) -> V_168 , V_169 ) ||
F_131 ( F_4 ( V_5 ) -> V_168 , V_189 ) ||
F_7 ( & F_4 ( V_5 ) -> V_190 ) )
return 0 ;
if ( V_156 ) {
if ( V_156 -> V_157 & V_170 )
V_167 = F_126 ( V_5 , V_156 ) ;
else
V_167 = F_122 ( V_5 , V_156 ) ;
if ( ! V_167 )
return 0 ;
if ( V_156 -> V_157 & V_171 &&
F_132 ( V_5 ) < V_156 -> V_172 )
return 0 ;
}
F_62 ( V_5 , V_104 ) ;
F_62 ( V_5 , V_191 ) ;
V_166 = F_153 ( V_5 , 0 , V_192 , false ) ;
F_75 ( V_5 , V_191 ) ;
F_75 ( V_5 , V_104 ) ;
return V_166 ;
}
int
F_96 (
struct V_2 * V_3 ,
struct V_155 * V_156 )
{
return F_134 ( V_3 , V_156 , F_148 ,
V_134 ) ;
}
int
F_154 (
struct V_1 * V_5 )
{
return F_135 ( V_5 , F_96 ) ;
}
void
F_155 (
T_11 * V_5 )
{
F_156 ( V_5 ) ;
return F_141 ( V_5 , F_94 ,
V_193 ,
V_134 ) ;
}
void
F_152 (
T_11 * V_5 )
{
F_157 ( V_5 ) ;
return F_145 ( V_5 ,
V_194 , V_134 ) ;
}
