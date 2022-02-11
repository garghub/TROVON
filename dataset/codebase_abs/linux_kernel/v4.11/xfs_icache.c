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
V_5 -> V_13 = V_4 ;
V_5 -> V_14 = V_3 ;
memset ( & V_5 -> V_15 , 0 , sizeof( struct V_16 ) ) ;
V_5 -> V_17 = NULL ;
V_5 -> V_18 = NULL ;
V_5 -> V_19 = 0 ;
V_5 -> V_20 = V_21 ;
memset ( & V_5 -> V_22 , 0 , sizeof( V_23 ) ) ;
V_5 -> V_24 = 0 ;
V_5 -> V_25 = 0 ;
memset ( & V_5 -> V_26 , 0 , sizeof( V_5 -> V_26 ) ) ;
return V_5 ;
}
STATIC void
F_10 (
struct V_27 * V_28 )
{
struct V_29 * V_29 = F_11 ( V_28 , struct V_29 , V_30 ) ;
struct V_1 * V_5 = F_12 ( V_29 ) ;
switch ( F_4 ( V_5 ) -> V_9 & V_31 ) {
case V_32 :
case V_33 :
case V_34 :
F_13 ( V_5 , V_35 ) ;
break;
}
if ( V_5 -> V_17 )
F_13 ( V_5 , V_36 ) ;
if ( V_5 -> V_18 )
F_13 ( V_5 , V_37 ) ;
if ( V_5 -> V_38 ) {
ASSERT ( ! ( V_5 -> V_38 -> V_39 . V_40 & V_41 ) ) ;
F_14 ( V_5 ) ;
V_5 -> V_38 = NULL ;
}
F_5 ( V_6 , V_5 ) ;
}
static void
F_15 (
struct V_1 * V_5 )
{
ASSERT ( F_7 ( & V_5 -> V_11 ) == 0 ) ;
F_16 ( V_5 -> V_14 , V_10 ) ;
F_17 ( & F_4 ( V_5 ) -> V_30 , F_10 ) ;
}
void
F_18 (
struct V_1 * V_5 )
{
ASSERT ( ! F_9 ( V_5 ) ) ;
F_19 ( & V_5 -> V_12 ) ;
V_5 -> V_24 = V_42 ;
V_5 -> V_13 = 0 ;
F_20 ( & V_5 -> V_12 ) ;
F_15 ( V_5 ) ;
}
static void
F_21 (
struct V_2 * V_3 )
{
F_22 () ;
if ( F_23 ( & V_3 -> V_43 , V_44 ) ) {
F_24 ( V_3 -> V_45 , & V_3 -> V_46 ,
F_25 ( V_47 / 6 * 10 ) ) ;
}
F_26 () ;
}
void
F_27 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_11 ( F_28 ( V_49 ) ,
struct V_2 , V_46 ) ;
F_29 ( V_3 , V_50 ) ;
F_21 ( V_3 ) ;
}
static void
F_30 (
struct V_51 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_53 ;
ASSERT ( F_8 ( & V_52 -> V_54 ) ) ;
if ( V_52 -> V_55 ++ )
return;
F_19 ( & V_3 -> V_56 ) ;
F_31 ( & V_3 -> V_43 , V_52 -> V_57 ,
V_44 ) ;
F_20 ( & V_3 -> V_56 ) ;
F_21 ( V_3 ) ;
F_32 ( V_3 , V_52 -> V_57 , - 1 , V_58 ) ;
}
static void
F_33 (
struct V_51 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_53 ;
ASSERT ( F_8 ( & V_52 -> V_54 ) ) ;
if ( -- V_52 -> V_55 )
return;
F_19 ( & V_3 -> V_56 ) ;
F_34 ( & V_3 -> V_43 , V_52 -> V_57 ,
V_44 ) ;
F_20 ( & V_3 -> V_56 ) ;
F_35 ( V_3 , V_52 -> V_57 , - 1 , V_58 ) ;
}
void
F_36 (
struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_14 ;
struct V_51 * V_52 ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_13 ) ) ;
F_19 ( & V_52 -> V_54 ) ;
F_19 ( & V_5 -> V_12 ) ;
F_31 ( & V_52 -> V_59 , F_39 ( V_3 , V_5 -> V_13 ) ,
V_44 ) ;
F_30 ( V_52 ) ;
F_40 ( V_5 , V_60 ) ;
F_20 ( & V_5 -> V_12 ) ;
F_20 ( & V_52 -> V_54 ) ;
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
static int
F_43 (
struct V_2 * V_3 ,
struct V_29 * V_29 )
{
int error ;
T_2 V_61 = V_29 -> V_62 ;
T_2 V_63 = V_29 -> V_64 ;
T_3 V_65 = V_29 -> V_66 ;
T_4 V_67 = V_29 -> V_9 ;
error = F_3 ( V_3 -> V_8 , V_29 ) ;
F_44 ( V_29 , V_61 ) ;
V_29 -> V_64 = V_63 ;
V_29 -> V_66 = V_65 ;
V_29 -> V_9 = V_67 ;
return error ;
}
static int
F_45 (
struct V_51 * V_52 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_68 ,
int V_69 ) __releases( T_5 )
{
struct V_29 * V_29 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_14 ;
int error ;
F_19 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_13 != V_4 ) {
F_46 ( V_5 ) ;
F_6 ( V_3 , V_70 ) ;
error = - V_71 ;
goto V_72;
}
if ( V_5 -> V_24 & ( V_73 | V_42 ) ) {
F_46 ( V_5 ) ;
F_6 ( V_3 , V_70 ) ;
error = - V_71 ;
goto V_72;
}
if ( F_4 ( V_5 ) -> V_9 == 0 && ! ( V_68 & V_74 ) ) {
error = - V_75 ;
goto V_72;
}
if ( V_5 -> V_24 & V_60 ) {
F_47 ( V_5 ) ;
V_5 -> V_24 |= V_42 ;
F_20 ( & V_5 -> V_12 ) ;
F_26 () ;
error = F_43 ( V_3 , V_29 ) ;
if ( error ) {
F_22 () ;
F_19 ( & V_5 -> V_12 ) ;
V_5 -> V_24 &= ~ ( V_73 | V_42 ) ;
ASSERT ( V_5 -> V_24 & V_60 ) ;
F_48 ( V_5 ) ;
goto V_72;
}
F_19 ( & V_52 -> V_54 ) ;
F_19 ( & V_5 -> V_12 ) ;
V_5 -> V_24 &= ~ V_76 ;
V_5 -> V_24 |= V_73 ;
F_42 ( V_52 , V_5 -> V_13 ) ;
V_29 -> V_77 = V_78 ;
ASSERT ( ! F_49 ( & V_29 -> V_79 ) ) ;
F_50 ( & V_29 -> V_79 ) ;
F_20 ( & V_5 -> V_12 ) ;
F_20 ( & V_52 -> V_54 ) ;
} else {
if ( ! F_51 ( V_29 ) ) {
F_46 ( V_5 ) ;
error = - V_71 ;
goto V_72;
}
F_20 ( & V_5 -> V_12 ) ;
F_26 () ;
F_52 ( V_5 ) ;
}
if ( V_69 != 0 )
F_53 ( V_5 , V_69 ) ;
F_54 ( V_5 , V_80 | V_81 ) ;
F_6 ( V_3 , V_82 ) ;
return 0 ;
V_72:
F_20 ( & V_5 -> V_12 ) ;
F_26 () ;
return error ;
}
static int
F_55 (
struct V_2 * V_3 ,
struct V_51 * V_52 ,
T_6 * V_83 ,
T_1 V_4 ,
struct V_1 * * V_84 ,
int V_68 ,
int V_69 )
{
struct V_1 * V_5 ;
int error ;
T_7 V_85 = F_39 ( V_3 , V_4 ) ;
int V_86 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_87 ;
error = F_56 ( V_3 , V_83 , V_5 , V_68 ) ;
if ( error )
goto V_88;
F_57 ( V_5 ) ;
if ( ( F_4 ( V_5 ) -> V_9 == 0 ) && ! ( V_68 & V_74 ) ) {
error = - V_75 ;
goto V_88;
}
if ( F_58 ( V_89 ) ) {
error = - V_71 ;
goto V_88;
}
if ( V_69 ) {
if ( ! F_59 ( V_5 , V_69 ) )
F_60 () ;
}
V_86 = V_73 ;
if ( V_68 & V_90 )
V_86 |= V_81 ;
V_5 -> V_91 = NULL ;
V_5 -> V_92 = NULL ;
V_5 -> V_93 = NULL ;
F_61 ( V_5 , V_86 ) ;
F_19 ( & V_52 -> V_54 ) ;
error = F_62 ( & V_52 -> V_59 , V_85 , V_5 ) ;
if ( F_63 ( error ) ) {
F_64 ( error != - V_94 ) ;
F_6 ( V_3 , V_95 ) ;
error = - V_71 ;
goto V_96;
}
F_20 ( & V_52 -> V_54 ) ;
F_65 () ;
* V_84 = V_5 ;
return 0 ;
V_96:
F_20 ( & V_52 -> V_54 ) ;
F_65 () ;
if ( V_69 )
F_66 ( V_5 , V_69 ) ;
V_88:
F_67 ( F_4 ( V_5 ) ) ;
F_18 ( V_5 ) ;
return error ;
}
int
F_68 (
T_8 * V_3 ,
T_6 * V_83 ,
T_1 V_4 ,
T_9 V_68 ,
T_9 V_69 ,
T_10 * * V_84 )
{
T_10 * V_5 ;
int error ;
T_11 * V_52 ;
T_7 V_85 ;
ASSERT ( ( V_69 & ( V_97 | V_98 ) ) == 0 ) ;
if ( ! V_4 || F_38 ( V_3 , V_4 ) >= V_3 -> V_99 . V_100 )
return - V_101 ;
F_6 ( V_3 , V_102 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_4 ) ) ;
V_85 = F_39 ( V_3 , V_4 ) ;
V_103:
error = 0 ;
F_22 () ;
V_5 = F_69 ( & V_52 -> V_59 , V_85 ) ;
if ( V_5 ) {
error = F_45 ( V_52 , V_5 , V_4 , V_68 , V_69 ) ;
if ( error )
goto V_104;
} else {
F_26 () ;
F_6 ( V_3 , V_105 ) ;
error = F_55 ( V_3 , V_52 , V_83 , V_4 , & V_5 ,
V_68 , V_69 ) ;
if ( error )
goto V_104;
}
F_41 ( V_52 ) ;
* V_84 = V_5 ;
if ( F_70 ( V_5 , V_73 ) && F_4 ( V_5 ) -> V_9 != 0 )
F_71 ( V_5 ) ;
return 0 ;
V_104:
if ( error == - V_71 ) {
F_72 ( 1 ) ;
goto V_103;
}
F_41 ( V_52 ) ;
return error ;
}
STATIC int
F_73 (
struct V_1 * V_5 )
{
struct V_29 * V_29 = F_4 ( V_5 ) ;
ASSERT ( F_74 () ) ;
F_19 ( & V_5 -> V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_106;
if ( F_75 ( V_5 , V_73 | V_60 | V_42 ) )
goto V_106;
F_20 ( & V_5 -> V_12 ) ;
if ( F_76 ( V_5 -> V_14 ) )
return - V_107 ;
if ( ! F_51 ( V_29 ) )
return - V_75 ;
return 0 ;
V_106:
F_20 ( & V_5 -> V_12 ) ;
return - V_75 ;
}
STATIC int
F_77 (
struct V_2 * V_3 ,
struct V_51 * V_52 ,
int (* F_78)( struct V_1 * V_5 , int V_68 ,
void * args ) ,
int V_68 ,
void * args ,
int V_108 )
{
T_2 V_109 ;
int V_110 = 0 ;
int V_111 ;
int V_112 ;
int V_113 ;
V_114:
V_112 = 0 ;
V_111 = 0 ;
V_109 = 0 ;
V_113 = 0 ;
do {
struct V_1 * V_115 [ V_116 ] ;
int error = 0 ;
int V_117 ;
F_22 () ;
if ( V_108 == - 1 )
V_113 = F_79 ( & V_52 -> V_59 ,
( void * * ) V_115 , V_109 ,
V_116 ) ;
else
V_113 = F_80 (
& V_52 -> V_59 ,
( void * * ) V_115 , V_109 ,
V_116 , V_108 ) ;
if ( ! V_113 ) {
F_26 () ;
break;
}
for ( V_117 = 0 ; V_117 < V_113 ; V_117 ++ ) {
struct V_1 * V_5 = V_115 [ V_117 ] ;
if ( V_112 || F_73 ( V_5 ) )
V_115 [ V_117 ] = NULL ;
if ( F_38 ( V_3 , V_5 -> V_13 ) != V_52 -> V_57 )
continue;
V_109 = F_39 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_109 < F_39 ( V_3 , V_5 -> V_13 ) )
V_112 = 1 ;
}
F_26 () ;
for ( V_117 = 0 ; V_117 < V_113 ; V_117 ++ ) {
if ( ! V_115 [ V_117 ] )
continue;
error = F_78 ( V_115 [ V_117 ] , V_68 , args ) ;
F_81 ( V_115 [ V_117 ] ) ;
if ( error == - V_71 ) {
V_111 ++ ;
continue;
}
if ( error && V_110 != - V_107 )
V_110 = error ;
}
if ( error == - V_107 )
break;
F_82 () ;
} while ( V_113 && ! V_112 );
if ( V_111 ) {
F_72 ( 1 ) ;
goto V_114;
}
return V_110 ;
}
void
F_83 (
struct V_2 * V_3 )
{
F_22 () ;
if ( F_23 ( & V_3 -> V_43 , V_118 ) )
F_24 ( V_3 -> V_119 ,
& V_3 -> V_120 ,
F_25 ( V_121 * 1000 ) ) ;
F_26 () ;
}
void
F_84 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_11 ( F_28 ( V_49 ) ,
struct V_2 , V_120 ) ;
F_85 ( V_3 , NULL ) ;
F_83 ( V_3 ) ;
}
STATIC void
F_86 (
struct V_2 * V_3 )
{
F_22 () ;
if ( F_23 ( & V_3 -> V_43 , V_122 ) )
F_24 ( V_3 -> V_119 ,
& V_3 -> V_123 ,
F_25 ( V_124 * 1000 ) ) ;
F_26 () ;
}
void
F_87 (
struct V_48 * V_49 )
{
struct V_2 * V_3 = F_11 ( F_28 ( V_49 ) ,
struct V_2 , V_123 ) ;
F_88 ( V_3 , NULL ) ;
F_86 ( V_3 ) ;
}
int
F_89 (
struct V_2 * V_3 ,
int (* F_78)( struct V_1 * V_5 , int V_68 ,
void * args ) ,
int V_68 ,
void * args )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_110 = 0 ;
T_12 V_125 ;
V_125 = 0 ;
while ( ( V_52 = F_37 ( V_3 , V_125 ) ) ) {
V_125 = V_52 -> V_57 + 1 ;
error = F_77 ( V_3 , V_52 , F_78 , V_68 , args , - 1 ) ;
F_41 ( V_52 ) ;
if ( error ) {
V_110 = error ;
if ( error == - V_107 )
break;
}
}
return V_110 ;
}
int
F_90 (
struct V_2 * V_3 ,
int (* F_78)( struct V_1 * V_5 , int V_68 ,
void * args ) ,
int V_68 ,
void * args ,
int V_108 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_110 = 0 ;
T_12 V_125 ;
V_125 = 0 ;
while ( ( V_52 = F_91 ( V_3 , V_125 , V_108 ) ) ) {
V_125 = V_52 -> V_57 + 1 ;
error = F_77 ( V_3 , V_52 , F_78 , V_68 , args , V_108 ) ;
F_41 ( V_52 ) ;
if ( error ) {
V_110 = error ;
if ( error == - V_107 )
break;
}
}
return V_110 ;
}
STATIC int
F_92 (
struct V_1 * V_5 ,
int V_68 )
{
ASSERT ( F_74 () ) ;
if ( ! V_5 -> V_13 )
return 1 ;
if ( ( V_68 & V_50 ) &&
F_75 ( V_5 , V_126 | V_42 ) )
return 1 ;
F_19 ( & V_5 -> V_12 ) ;
if ( ! F_75 ( V_5 , V_60 ) ||
F_75 ( V_5 , V_42 ) ) {
F_20 ( & V_5 -> V_12 ) ;
return 1 ;
}
F_40 ( V_5 , V_42 ) ;
F_20 ( & V_5 -> V_12 ) ;
return 0 ;
}
STATIC int
F_93 (
struct V_1 * V_5 ,
struct V_51 * V_52 ,
int V_127 )
{
struct V_128 * V_129 = NULL ;
T_1 V_4 = V_5 -> V_13 ;
int error ;
V_114:
error = 0 ;
F_53 ( V_5 , V_130 ) ;
if ( ! F_94 ( V_5 ) ) {
if ( ! ( V_127 & V_131 ) )
goto V_132;
F_95 ( V_5 ) ;
}
if ( F_76 ( V_5 -> V_14 ) ) {
F_96 ( V_5 ) ;
F_97 ( V_5 , false ) ;
goto V_133;
}
if ( F_98 ( V_5 ) ) {
if ( ! ( V_127 & V_131 ) )
goto V_134;
F_96 ( V_5 ) ;
}
if ( F_70 ( V_5 , V_80 ) || F_99 ( V_5 ) ) {
F_100 ( V_5 ) ;
goto V_133;
}
if ( ! ( V_127 & V_131 ) )
goto V_134;
error = F_101 ( V_5 , & V_129 ) ;
if ( error == - V_71 ) {
F_66 ( V_5 , V_130 ) ;
F_72 ( 2 ) ;
goto V_114;
}
if ( ! error ) {
error = F_102 ( V_129 ) ;
F_103 ( V_129 ) ;
}
V_133:
ASSERT ( ! F_9 ( V_5 ) ) ;
F_19 ( & V_5 -> V_12 ) ;
V_5 -> V_24 = V_42 ;
V_5 -> V_13 = 0 ;
F_20 ( & V_5 -> V_12 ) ;
F_66 ( V_5 , V_130 ) ;
F_6 ( V_5 -> V_14 , V_135 ) ;
F_19 ( & V_52 -> V_54 ) ;
if ( ! F_104 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_14 , V_4 ) ) )
ASSERT ( 0 ) ;
F_33 ( V_52 ) ;
F_20 ( & V_52 -> V_54 ) ;
F_53 ( V_5 , V_130 ) ;
F_105 ( V_5 ) ;
F_66 ( V_5 , V_130 ) ;
F_15 ( V_5 ) ;
return error ;
V_134:
F_100 ( V_5 ) ;
V_132:
F_54 ( V_5 , V_42 ) ;
F_66 ( V_5 , V_130 ) ;
return 0 ;
}
STATIC int
F_106 (
struct V_2 * V_3 ,
int V_68 ,
int * V_136 )
{
struct V_51 * V_52 ;
int error = 0 ;
int V_110 = 0 ;
T_12 V_125 ;
int V_137 = V_68 & V_50 ;
int V_111 ;
V_114:
V_125 = 0 ;
V_111 = 0 ;
while ( ( V_52 = F_91 ( V_3 , V_125 , V_44 ) ) ) {
unsigned long V_109 = 0 ;
int V_112 = 0 ;
int V_113 = 0 ;
V_125 = V_52 -> V_57 + 1 ;
if ( V_137 ) {
if ( ! F_107 ( & V_52 -> V_138 ) ) {
V_111 ++ ;
F_41 ( V_52 ) ;
continue;
}
V_109 = V_52 -> V_139 ;
} else
F_108 ( & V_52 -> V_138 ) ;
do {
struct V_1 * V_115 [ V_116 ] ;
int V_117 ;
F_22 () ;
V_113 = F_80 (
& V_52 -> V_59 ,
( void * * ) V_115 , V_109 ,
V_116 ,
V_44 ) ;
if ( ! V_113 ) {
V_112 = 1 ;
F_26 () ;
break;
}
for ( V_117 = 0 ; V_117 < V_113 ; V_117 ++ ) {
struct V_1 * V_5 = V_115 [ V_117 ] ;
if ( V_112 || F_92 ( V_5 , V_68 ) )
V_115 [ V_117 ] = NULL ;
if ( F_38 ( V_3 , V_5 -> V_13 ) !=
V_52 -> V_57 )
continue;
V_109 = F_39 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_109 < F_39 ( V_3 , V_5 -> V_13 ) )
V_112 = 1 ;
}
F_26 () ;
for ( V_117 = 0 ; V_117 < V_113 ; V_117 ++ ) {
if ( ! V_115 [ V_117 ] )
continue;
error = F_93 ( V_115 [ V_117 ] , V_52 , V_68 ) ;
if ( error && V_110 != - V_107 )
V_110 = error ;
}
* V_136 -= V_116 ;
F_82 () ;
} while ( V_113 && ! V_112 && * V_136 > 0 );
if ( V_137 && ! V_112 )
V_52 -> V_139 = V_109 ;
else
V_52 -> V_139 = 0 ;
F_109 ( & V_52 -> V_138 ) ;
F_41 ( V_52 ) ;
}
if ( V_111 && ( V_68 & V_131 ) && * V_136 > 0 ) {
V_137 = 0 ;
goto V_114;
}
return V_110 ;
}
int
F_29 (
T_8 * V_3 ,
int V_67 )
{
int V_136 = V_140 ;
return F_106 ( V_3 , V_67 , & V_136 ) ;
}
long
F_110 (
struct V_2 * V_3 ,
int V_136 )
{
F_21 ( V_3 ) ;
F_111 ( V_3 -> V_141 ) ;
return F_106 ( V_3 , V_50 | V_131 , & V_136 ) ;
}
int
F_112 (
struct V_2 * V_3 )
{
struct V_51 * V_52 ;
T_12 V_125 = 0 ;
int V_142 = 0 ;
while ( ( V_52 = F_91 ( V_3 , V_125 , V_44 ) ) ) {
V_125 = V_52 -> V_57 + 1 ;
V_142 += V_52 -> V_55 ;
F_41 ( V_52 ) ;
}
return V_142 ;
}
STATIC int
F_113 (
struct V_1 * V_5 ,
struct V_143 * V_144 )
{
if ( ( V_144 -> V_145 & V_146 ) &&
! F_114 ( F_4 ( V_5 ) -> V_147 , V_144 -> V_148 ) )
return 0 ;
if ( ( V_144 -> V_145 & V_149 ) &&
! F_115 ( F_4 ( V_5 ) -> V_150 , V_144 -> V_151 ) )
return 0 ;
if ( ( V_144 -> V_145 & V_152 ) &&
F_116 ( V_5 ) != V_144 -> V_153 )
return 0 ;
return 1 ;
}
STATIC int
F_117 (
struct V_1 * V_5 ,
struct V_143 * V_144 )
{
if ( ( V_144 -> V_145 & V_146 ) &&
F_114 ( F_4 ( V_5 ) -> V_147 , V_144 -> V_148 ) )
return 1 ;
if ( ( V_144 -> V_145 & V_149 ) &&
F_115 ( F_4 ( V_5 ) -> V_150 , V_144 -> V_151 ) )
return 1 ;
if ( ( V_144 -> V_145 & V_152 ) &&
F_116 ( V_5 ) == V_144 -> V_153 )
return 1 ;
return 0 ;
}
STATIC int
F_118 (
struct V_1 * V_5 ,
int V_68 ,
void * args )
{
int V_154 = 0 ;
struct V_143 * V_144 = args ;
int V_155 ;
if ( ! F_119 ( V_5 , false ) ) {
F_120 ( V_5 ) ;
F_121 ( V_5 ) ;
return 0 ;
}
if ( ! ( V_68 & V_131 ) &&
F_122 ( F_4 ( V_5 ) -> V_156 , V_157 ) )
return 0 ;
if ( V_144 ) {
if ( V_144 -> V_145 & V_158 )
V_155 = F_117 ( V_5 , V_144 ) ;
else
V_155 = F_113 ( V_5 , V_144 ) ;
if ( ! V_155 )
return 0 ;
if ( V_144 -> V_145 & V_159 &&
F_123 ( V_5 ) < V_144 -> V_160 )
return 0 ;
}
if ( ! F_59 ( V_5 , V_97 ) ) {
if ( V_68 & V_131 )
V_154 = - V_71 ;
return V_154 ;
}
V_154 = F_124 ( V_5 ) ;
F_66 ( V_5 , V_97 ) ;
return V_154 ;
}
static int
F_125 (
struct V_2 * V_3 ,
struct V_143 * V_144 ,
int (* F_78)( struct V_1 * V_5 , int V_68 ,
void * args ) ,
int V_108 )
{
int V_68 = V_50 ;
if ( V_144 && ( V_144 -> V_145 & V_161 ) )
V_68 = V_131 ;
return F_90 ( V_3 , F_78 , V_68 ,
V_144 , V_108 ) ;
}
int
F_85 (
struct V_2 * V_3 ,
struct V_143 * V_144 )
{
return F_125 ( V_3 , V_144 , F_118 ,
V_118 ) ;
}
static int
F_126 (
struct V_1 * V_5 ,
int (* F_78)( struct V_2 * V_3 ,
struct V_143 * V_144 ) )
{
int V_162 = 0 ;
struct V_143 V_144 = { 0 } ;
struct V_163 * V_164 ;
V_144 . V_145 = V_158 | V_161 ;
if ( F_127 ( V_5 -> V_14 ) ) {
V_164 = F_128 ( V_5 , V_165 ) ;
if ( V_164 && F_129 ( V_164 ) ) {
V_144 . V_148 = F_4 ( V_5 ) -> V_147 ;
V_144 . V_145 |= V_146 ;
V_162 = 1 ;
}
}
if ( F_130 ( V_5 -> V_14 ) ) {
V_164 = F_128 ( V_5 , V_166 ) ;
if ( V_164 && F_129 ( V_164 ) ) {
V_144 . V_151 = F_4 ( V_5 ) -> V_150 ;
V_144 . V_145 |= V_149 ;
V_162 = 1 ;
}
}
if ( V_162 )
F_78 ( V_5 -> V_14 , & V_144 ) ;
return V_162 ;
}
int
F_131 (
struct V_1 * V_5 )
{
return F_126 ( V_5 , F_85 ) ;
}
static void
F_132 (
T_10 * V_5 ,
void (* F_78)( struct V_2 * V_3 ) ,
void (* F_133)( struct V_2 * V_3 , T_12 V_167 ,
int error , unsigned long V_168 ) ,
int V_108 )
{
struct V_2 * V_3 = V_5 -> V_14 ;
struct V_51 * V_52 ;
int V_169 ;
if ( V_5 -> V_24 & V_170 )
return;
F_19 ( & V_5 -> V_12 ) ;
V_5 -> V_24 |= V_170 ;
F_20 ( & V_5 -> V_12 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_13 ) ) ;
F_19 ( & V_52 -> V_54 ) ;
V_169 = F_23 ( & V_52 -> V_59 , V_108 ) ;
F_31 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_14 , V_5 -> V_13 ) , V_108 ) ;
if ( ! V_169 ) {
F_19 ( & V_5 -> V_14 -> V_56 ) ;
F_31 ( & V_5 -> V_14 -> V_43 ,
F_38 ( V_5 -> V_14 , V_5 -> V_13 ) ,
V_108 ) ;
F_20 ( & V_5 -> V_14 -> V_56 ) ;
F_78 ( V_5 -> V_14 ) ;
F_133 ( V_5 -> V_14 , V_52 -> V_57 , - 1 , V_58 ) ;
}
F_20 ( & V_52 -> V_54 ) ;
F_41 ( V_52 ) ;
}
void
F_134 (
T_10 * V_5 )
{
F_135 ( V_5 ) ;
return F_132 ( V_5 , F_83 ,
V_171 ,
V_118 ) ;
}
static void
F_136 (
T_10 * V_5 ,
void (* F_137)( struct V_2 * V_3 , T_12 V_167 ,
int error , unsigned long V_168 ) ,
int V_108 )
{
struct V_2 * V_3 = V_5 -> V_14 ;
struct V_51 * V_52 ;
F_19 ( & V_5 -> V_12 ) ;
V_5 -> V_24 &= ~ V_170 ;
F_20 ( & V_5 -> V_12 ) ;
V_52 = F_37 ( V_3 , F_38 ( V_3 , V_5 -> V_13 ) ) ;
F_19 ( & V_52 -> V_54 ) ;
F_34 ( & V_52 -> V_59 ,
F_39 ( V_5 -> V_14 , V_5 -> V_13 ) , V_108 ) ;
if ( ! F_23 ( & V_52 -> V_59 , V_108 ) ) {
F_19 ( & V_5 -> V_14 -> V_56 ) ;
F_34 ( & V_5 -> V_14 -> V_43 ,
F_38 ( V_5 -> V_14 , V_5 -> V_13 ) ,
V_108 ) ;
F_20 ( & V_5 -> V_14 -> V_56 ) ;
F_137 ( V_5 -> V_14 , V_52 -> V_57 , - 1 , V_58 ) ;
}
F_20 ( & V_52 -> V_54 ) ;
F_41 ( V_52 ) ;
}
void
F_121 (
T_10 * V_5 )
{
F_138 ( V_5 ) ;
return F_136 ( V_5 ,
V_172 , V_118 ) ;
}
STATIC int
F_139 (
struct V_1 * V_5 ,
int V_68 ,
void * args )
{
int V_154 ;
struct V_143 * V_144 = args ;
int V_155 ;
struct V_173 * V_174 = F_140 ( V_5 , V_37 ) ;
if ( ! F_141 ( V_5 ) || ! V_174 -> V_175 ) {
F_142 ( V_5 ) ;
F_143 ( V_5 ) ;
return 0 ;
}
if ( ( F_4 ( V_5 ) -> V_77 & V_176 ) ||
F_122 ( F_4 ( V_5 ) -> V_156 , V_157 ) ||
F_122 ( F_4 ( V_5 ) -> V_156 , V_177 ) ||
F_7 ( & F_4 ( V_5 ) -> V_178 ) )
return 0 ;
if ( V_144 ) {
if ( V_144 -> V_145 & V_158 )
V_155 = F_117 ( V_5 , V_144 ) ;
else
V_155 = F_113 ( V_5 , V_144 ) ;
if ( ! V_155 )
return 0 ;
if ( V_144 -> V_145 & V_159 &&
F_123 ( V_5 ) < V_144 -> V_160 )
return 0 ;
}
F_53 ( V_5 , V_97 ) ;
F_53 ( V_5 , V_179 ) ;
V_154 = F_144 ( V_5 , 0 , V_180 , false ) ;
F_66 ( V_5 , V_179 ) ;
F_66 ( V_5 , V_97 ) ;
return V_154 ;
}
int
F_88 (
struct V_2 * V_3 ,
struct V_143 * V_144 )
{
return F_125 ( V_3 , V_144 , F_139 ,
V_122 ) ;
}
int
F_145 (
struct V_1 * V_5 )
{
return F_126 ( V_5 , F_88 ) ;
}
void
F_146 (
T_10 * V_5 )
{
F_147 ( V_5 ) ;
return F_132 ( V_5 , F_86 ,
V_181 ,
V_122 ) ;
}
void
F_143 (
T_10 * V_5 )
{
F_148 ( V_5 ) ;
return F_136 ( V_5 ,
V_182 , V_122 ) ;
}
