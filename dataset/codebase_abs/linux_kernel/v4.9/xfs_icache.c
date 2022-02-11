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
V_5 -> V_20 = NULL ;
V_5 -> V_21 = 0 ;
V_5 -> V_22 = V_23 ;
memset ( & V_5 -> V_24 , 0 , sizeof( V_25 ) ) ;
V_5 -> V_26 = 0 ;
V_5 -> V_27 = 0 ;
memset ( & V_5 -> V_28 , 0 , sizeof( V_5 -> V_28 ) ) ;
return V_5 ;
}
STATIC void
F_11 (
struct V_29 * V_30 )
{
struct V_31 * V_31 = F_12 ( V_30 , struct V_31 , V_32 ) ;
struct V_1 * V_5 = F_13 ( V_31 ) ;
switch ( F_4 ( V_5 ) -> V_9 & V_33 ) {
case V_34 :
case V_35 :
case V_36 :
F_14 ( V_5 , V_37 ) ;
break;
}
if ( V_5 -> V_19 )
F_14 ( V_5 , V_38 ) ;
if ( V_5 -> V_20 )
F_14 ( V_5 , V_39 ) ;
if ( V_5 -> V_40 ) {
ASSERT ( ! ( V_5 -> V_40 -> V_41 . V_42 & V_43 ) ) ;
F_15 ( V_5 ) ;
V_5 -> V_40 = NULL ;
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
F_18 ( & F_4 ( V_5 ) -> V_32 , F_11 ) ;
}
void
F_19 (
struct V_1 * V_5 )
{
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_26 = V_44 ;
V_5 -> V_13 = 0 ;
F_21 ( & V_5 -> V_12 ) ;
F_16 ( V_5 ) ;
}
static void
F_22 (
struct V_2 * V_3 )
{
F_23 () ;
if ( F_24 ( & V_3 -> V_45 , V_46 ) ) {
F_25 ( V_3 -> V_47 , & V_3 -> V_48 ,
F_26 ( V_49 / 6 * 10 ) ) ;
}
F_27 () ;
}
void
F_28 (
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_12 ( F_29 ( V_51 ) ,
struct V_2 , V_48 ) ;
F_30 ( V_3 , V_52 ) ;
F_22 ( V_3 ) ;
}
static void
F_31 (
struct V_53 * V_54 )
{
struct V_2 * V_3 = V_54 -> V_55 ;
ASSERT ( F_8 ( & V_54 -> V_56 ) ) ;
if ( V_54 -> V_57 ++ )
return;
F_20 ( & V_3 -> V_58 ) ;
F_32 ( & V_3 -> V_45 , V_54 -> V_59 ,
V_46 ) ;
F_21 ( & V_3 -> V_58 ) ;
F_22 ( V_3 ) ;
F_33 ( V_3 , V_54 -> V_59 , - 1 , V_60 ) ;
}
static void
F_34 (
struct V_53 * V_54 )
{
struct V_2 * V_3 = V_54 -> V_55 ;
ASSERT ( F_8 ( & V_54 -> V_56 ) ) ;
if ( -- V_54 -> V_57 )
return;
F_20 ( & V_3 -> V_58 ) ;
F_35 ( & V_3 -> V_45 , V_54 -> V_59 ,
V_46 ) ;
F_21 ( & V_3 -> V_58 ) ;
F_36 ( V_3 , V_54 -> V_59 , - 1 , V_60 ) ;
}
void
F_37 (
struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_53 * V_54 ;
V_54 = F_38 ( V_3 , F_39 ( V_3 , V_5 -> V_13 ) ) ;
F_20 ( & V_54 -> V_56 ) ;
F_20 ( & V_5 -> V_12 ) ;
F_32 ( & V_54 -> V_61 , F_40 ( V_3 , V_5 -> V_13 ) ,
V_46 ) ;
F_31 ( V_54 ) ;
F_41 ( V_5 , V_62 ) ;
F_21 ( & V_5 -> V_12 ) ;
F_21 ( & V_54 -> V_56 ) ;
F_42 ( V_54 ) ;
}
STATIC void
F_43 (
struct V_53 * V_54 ,
T_1 V_4 )
{
F_35 ( & V_54 -> V_61 ,
F_40 ( V_54 -> V_55 , V_4 ) ,
V_46 ) ;
F_34 ( V_54 ) ;
}
static int
F_44 (
struct V_2 * V_3 ,
struct V_31 * V_31 )
{
int error ;
T_2 V_63 = V_31 -> V_64 ;
T_2 V_65 = V_31 -> V_66 ;
T_3 V_67 = V_31 -> V_68 ;
T_4 V_69 = V_31 -> V_9 ;
error = F_3 ( V_3 -> V_8 , V_31 ) ;
F_45 ( V_31 , V_63 ) ;
V_31 -> V_66 = V_65 ;
V_31 -> V_68 = V_67 ;
V_31 -> V_9 = V_69 ;
return error ;
}
static int
F_46 (
struct V_53 * V_54 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_70 ,
int V_71 ) __releases( T_5 )
{
struct V_31 * V_31 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_16 ;
int error ;
F_20 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_13 != V_4 ) {
F_47 ( V_5 ) ;
F_6 ( V_3 , V_72 ) ;
error = - V_73 ;
goto V_74;
}
if ( V_5 -> V_26 & ( V_75 | V_44 ) ) {
F_47 ( V_5 ) ;
F_6 ( V_3 , V_72 ) ;
error = - V_73 ;
goto V_74;
}
if ( F_4 ( V_5 ) -> V_9 == 0 && ! ( V_70 & V_76 ) ) {
error = - V_77 ;
goto V_74;
}
if ( V_5 -> V_26 & V_62 ) {
F_48 ( V_5 ) ;
V_5 -> V_26 |= V_44 ;
F_21 ( & V_5 -> V_12 ) ;
F_27 () ;
error = F_44 ( V_3 , V_31 ) ;
if ( error ) {
F_23 () ;
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_26 &= ~ ( V_75 | V_44 ) ;
ASSERT ( V_5 -> V_26 & V_62 ) ;
F_49 ( V_5 ) ;
goto V_74;
}
F_20 ( & V_54 -> V_56 ) ;
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_26 &= ~ V_78 ;
V_5 -> V_26 |= V_75 ;
F_43 ( V_54 , V_5 -> V_13 ) ;
V_31 -> V_79 = V_80 ;
ASSERT ( ! F_50 ( & V_5 -> V_14 . V_81 ) ) ;
F_10 ( & V_5 -> V_14 , V_15 , L_1 , V_5 -> V_13 ) ;
F_21 ( & V_5 -> V_12 ) ;
F_21 ( & V_54 -> V_56 ) ;
} else {
if ( ! F_51 ( V_31 ) ) {
F_47 ( V_5 ) ;
error = - V_73 ;
goto V_74;
}
F_21 ( & V_5 -> V_12 ) ;
F_27 () ;
F_52 ( V_5 ) ;
}
if ( V_71 != 0 )
F_53 ( V_5 , V_71 ) ;
F_54 ( V_5 , V_82 | V_83 ) ;
F_6 ( V_3 , V_84 ) ;
return 0 ;
V_74:
F_21 ( & V_5 -> V_12 ) ;
F_27 () ;
return error ;
}
static int
F_55 (
struct V_2 * V_3 ,
struct V_53 * V_54 ,
T_6 * V_85 ,
T_1 V_4 ,
struct V_1 * * V_86 ,
int V_70 ,
int V_71 )
{
struct V_1 * V_5 ;
int error ;
T_7 V_87 = F_40 ( V_3 , V_4 ) ;
int V_88 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_89 ;
error = F_56 ( V_3 , V_85 , V_5 , V_70 ) ;
if ( error )
goto V_90;
F_57 ( V_5 ) ;
if ( ( F_4 ( V_5 ) -> V_9 == 0 ) && ! ( V_70 & V_76 ) ) {
error = - V_77 ;
goto V_90;
}
if ( F_58 ( V_91 ) ) {
error = - V_73 ;
goto V_90;
}
if ( V_71 ) {
if ( ! F_59 ( V_5 , V_71 ) )
F_60 () ;
}
V_88 = V_75 ;
if ( V_70 & V_92 )
V_88 |= V_83 ;
V_5 -> V_93 = NULL ;
V_5 -> V_94 = NULL ;
V_5 -> V_95 = NULL ;
F_61 ( V_5 , V_88 ) ;
F_20 ( & V_54 -> V_56 ) ;
error = F_62 ( & V_54 -> V_61 , V_87 , V_5 ) ;
if ( F_63 ( error ) ) {
F_64 ( error != - V_96 ) ;
F_6 ( V_3 , V_97 ) ;
error = - V_73 ;
goto V_98;
}
F_21 ( & V_54 -> V_56 ) ;
F_65 () ;
* V_86 = V_5 ;
return 0 ;
V_98:
F_21 ( & V_54 -> V_56 ) ;
F_65 () ;
if ( V_71 )
F_66 ( V_5 , V_71 ) ;
V_90:
F_67 ( F_4 ( V_5 ) ) ;
F_19 ( V_5 ) ;
return error ;
}
int
F_68 (
T_8 * V_3 ,
T_6 * V_85 ,
T_1 V_4 ,
T_9 V_70 ,
T_9 V_71 ,
T_10 * * V_86 )
{
T_10 * V_5 ;
int error ;
T_11 * V_54 ;
T_7 V_87 ;
ASSERT ( ( V_71 & ( V_99 | V_100 ) ) == 0 ) ;
if ( ! V_4 || F_39 ( V_3 , V_4 ) >= V_3 -> V_101 . V_102 )
return - V_103 ;
F_6 ( V_3 , V_104 ) ;
V_54 = F_38 ( V_3 , F_39 ( V_3 , V_4 ) ) ;
V_87 = F_40 ( V_3 , V_4 ) ;
V_105:
error = 0 ;
F_23 () ;
V_5 = F_69 ( & V_54 -> V_61 , V_87 ) ;
if ( V_5 ) {
error = F_46 ( V_54 , V_5 , V_4 , V_70 , V_71 ) ;
if ( error )
goto V_106;
} else {
F_27 () ;
F_6 ( V_3 , V_107 ) ;
error = F_55 ( V_3 , V_54 , V_85 , V_4 , & V_5 ,
V_70 , V_71 ) ;
if ( error )
goto V_106;
}
F_42 ( V_54 ) ;
* V_86 = V_5 ;
if ( F_70 ( V_5 , V_75 ) && F_4 ( V_5 ) -> V_9 != 0 )
F_71 ( V_5 ) ;
return 0 ;
V_106:
if ( error == - V_73 ) {
F_72 ( 1 ) ;
goto V_105;
}
F_42 ( V_54 ) ;
return error ;
}
STATIC int
F_73 (
struct V_1 * V_5 )
{
struct V_31 * V_31 = F_4 ( V_5 ) ;
ASSERT ( F_74 () ) ;
F_20 ( & V_5 -> V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_108;
if ( F_75 ( V_5 , V_75 | V_62 | V_44 ) )
goto V_108;
F_21 ( & V_5 -> V_12 ) ;
if ( F_76 ( V_5 -> V_16 ) )
return - V_109 ;
if ( ! F_51 ( V_31 ) )
return - V_77 ;
return 0 ;
V_108:
F_21 ( & V_5 -> V_12 ) ;
return - V_77 ;
}
STATIC int
F_77 (
struct V_2 * V_3 ,
struct V_53 * V_54 ,
int (* F_78)( struct V_1 * V_5 , int V_70 ,
void * args ) ,
int V_70 ,
void * args ,
int V_110 )
{
T_2 V_111 ;
int V_112 = 0 ;
int V_113 ;
int V_114 ;
int V_115 ;
V_116:
V_114 = 0 ;
V_113 = 0 ;
V_111 = 0 ;
V_115 = 0 ;
do {
struct V_1 * V_117 [ V_118 ] ;
int error = 0 ;
int V_119 ;
F_23 () ;
if ( V_110 == - 1 )
V_115 = F_79 ( & V_54 -> V_61 ,
( void * * ) V_117 , V_111 ,
V_118 ) ;
else
V_115 = F_80 (
& V_54 -> V_61 ,
( void * * ) V_117 , V_111 ,
V_118 , V_110 ) ;
if ( ! V_115 ) {
F_27 () ;
break;
}
for ( V_119 = 0 ; V_119 < V_115 ; V_119 ++ ) {
struct V_1 * V_5 = V_117 [ V_119 ] ;
if ( V_114 || F_73 ( V_5 ) )
V_117 [ V_119 ] = NULL ;
if ( F_39 ( V_3 , V_5 -> V_13 ) != V_54 -> V_59 )
continue;
V_111 = F_40 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_111 < F_40 ( V_3 , V_5 -> V_13 ) )
V_114 = 1 ;
}
F_27 () ;
for ( V_119 = 0 ; V_119 < V_115 ; V_119 ++ ) {
if ( ! V_117 [ V_119 ] )
continue;
error = F_78 ( V_117 [ V_119 ] , V_70 , args ) ;
F_81 ( V_117 [ V_119 ] ) ;
if ( error == - V_73 ) {
V_113 ++ ;
continue;
}
if ( error && V_112 != - V_109 )
V_112 = error ;
}
if ( error == - V_109 )
break;
F_82 () ;
} while ( V_115 && ! V_114 );
if ( V_113 ) {
F_72 ( 1 ) ;
goto V_116;
}
return V_112 ;
}
void
F_83 (
struct V_2 * V_3 )
{
F_23 () ;
if ( F_24 ( & V_3 -> V_45 , V_120 ) )
F_25 ( V_3 -> V_121 ,
& V_3 -> V_122 ,
F_26 ( V_123 * 1000 ) ) ;
F_27 () ;
}
void
F_84 (
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_12 ( F_29 ( V_51 ) ,
struct V_2 , V_122 ) ;
F_85 ( V_3 , NULL ) ;
F_83 ( V_3 ) ;
}
STATIC void
F_86 (
struct V_2 * V_3 )
{
F_23 () ;
if ( F_24 ( & V_3 -> V_45 , V_124 ) )
F_25 ( V_3 -> V_121 ,
& V_3 -> V_125 ,
F_26 ( V_126 * 1000 ) ) ;
F_27 () ;
}
void
F_87 (
struct V_50 * V_51 )
{
struct V_2 * V_3 = F_12 ( F_29 ( V_51 ) ,
struct V_2 , V_125 ) ;
F_88 ( V_3 , NULL ) ;
F_86 ( V_3 ) ;
}
int
F_89 (
struct V_2 * V_3 ,
int (* F_78)( struct V_1 * V_5 , int V_70 ,
void * args ) ,
int V_70 ,
void * args )
{
struct V_53 * V_54 ;
int error = 0 ;
int V_112 = 0 ;
T_12 V_127 ;
V_127 = 0 ;
while ( ( V_54 = F_38 ( V_3 , V_127 ) ) ) {
V_127 = V_54 -> V_59 + 1 ;
error = F_77 ( V_3 , V_54 , F_78 , V_70 , args , - 1 ) ;
F_42 ( V_54 ) ;
if ( error ) {
V_112 = error ;
if ( error == - V_109 )
break;
}
}
return V_112 ;
}
int
F_90 (
struct V_2 * V_3 ,
int (* F_78)( struct V_1 * V_5 , int V_70 ,
void * args ) ,
int V_70 ,
void * args ,
int V_110 )
{
struct V_53 * V_54 ;
int error = 0 ;
int V_112 = 0 ;
T_12 V_127 ;
V_127 = 0 ;
while ( ( V_54 = F_91 ( V_3 , V_127 , V_110 ) ) ) {
V_127 = V_54 -> V_59 + 1 ;
error = F_77 ( V_3 , V_54 , F_78 , V_70 , args , V_110 ) ;
F_42 ( V_54 ) ;
if ( error ) {
V_112 = error ;
if ( error == - V_109 )
break;
}
}
return V_112 ;
}
STATIC int
F_92 (
struct V_1 * V_5 ,
int V_70 )
{
ASSERT ( F_74 () ) ;
if ( ! V_5 -> V_13 )
return 1 ;
if ( ( V_70 & V_52 ) &&
F_75 ( V_5 , V_128 | V_44 ) )
return 1 ;
F_20 ( & V_5 -> V_12 ) ;
if ( ! F_75 ( V_5 , V_62 ) ||
F_75 ( V_5 , V_44 ) ) {
F_21 ( & V_5 -> V_12 ) ;
return 1 ;
}
F_41 ( V_5 , V_44 ) ;
F_21 ( & V_5 -> V_12 ) ;
return 0 ;
}
STATIC int
F_93 (
struct V_1 * V_5 ,
struct V_53 * V_54 ,
int V_129 )
{
struct V_130 * V_131 = NULL ;
T_1 V_4 = V_5 -> V_13 ;
int error ;
V_116:
error = 0 ;
F_53 ( V_5 , V_132 ) ;
if ( ! F_94 ( V_5 ) ) {
if ( ! ( V_129 & V_133 ) )
goto V_134;
F_95 ( V_5 ) ;
}
if ( F_76 ( V_5 -> V_16 ) ) {
F_96 ( V_5 ) ;
F_97 ( V_5 , false ) ;
goto V_135;
}
if ( F_98 ( V_5 ) ) {
if ( ! ( V_129 & V_133 ) )
goto V_136;
F_96 ( V_5 ) ;
}
if ( F_70 ( V_5 , V_82 ) )
goto V_135;
if ( F_99 ( V_5 ) )
goto V_135;
if ( ! ( V_129 & V_133 ) )
goto V_136;
error = F_100 ( V_5 , & V_131 ) ;
if ( error == - V_73 ) {
F_66 ( V_5 , V_132 ) ;
F_72 ( 2 ) ;
goto V_116;
}
if ( ! error ) {
error = F_101 ( V_131 ) ;
F_102 ( V_131 ) ;
}
F_95 ( V_5 ) ;
V_135:
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_26 = V_44 ;
V_5 -> V_13 = 0 ;
F_21 ( & V_5 -> V_12 ) ;
F_103 ( V_5 ) ;
F_66 ( V_5 , V_132 ) ;
F_6 ( V_5 -> V_16 , V_137 ) ;
F_20 ( & V_54 -> V_56 ) ;
if ( ! F_104 ( & V_54 -> V_61 ,
F_40 ( V_5 -> V_16 , V_4 ) ) )
ASSERT ( 0 ) ;
F_34 ( V_54 ) ;
F_21 ( & V_54 -> V_56 ) ;
F_53 ( V_5 , V_132 ) ;
F_105 ( V_5 ) ;
F_66 ( V_5 , V_132 ) ;
F_16 ( V_5 ) ;
return error ;
V_136:
F_103 ( V_5 ) ;
V_134:
F_54 ( V_5 , V_44 ) ;
F_66 ( V_5 , V_132 ) ;
return 0 ;
}
STATIC int
F_106 (
struct V_2 * V_3 ,
int V_70 ,
int * V_138 )
{
struct V_53 * V_54 ;
int error = 0 ;
int V_112 = 0 ;
T_12 V_127 ;
int V_139 = V_70 & V_52 ;
int V_113 ;
V_116:
V_127 = 0 ;
V_113 = 0 ;
while ( ( V_54 = F_91 ( V_3 , V_127 , V_46 ) ) ) {
unsigned long V_111 = 0 ;
int V_114 = 0 ;
int V_115 = 0 ;
V_127 = V_54 -> V_59 + 1 ;
if ( V_139 ) {
if ( ! F_107 ( & V_54 -> V_140 ) ) {
V_113 ++ ;
F_42 ( V_54 ) ;
continue;
}
V_111 = V_54 -> V_141 ;
} else
F_108 ( & V_54 -> V_140 ) ;
do {
struct V_1 * V_117 [ V_118 ] ;
int V_119 ;
F_23 () ;
V_115 = F_80 (
& V_54 -> V_61 ,
( void * * ) V_117 , V_111 ,
V_118 ,
V_46 ) ;
if ( ! V_115 ) {
V_114 = 1 ;
F_27 () ;
break;
}
for ( V_119 = 0 ; V_119 < V_115 ; V_119 ++ ) {
struct V_1 * V_5 = V_117 [ V_119 ] ;
if ( V_114 || F_92 ( V_5 , V_70 ) )
V_117 [ V_119 ] = NULL ;
if ( F_39 ( V_3 , V_5 -> V_13 ) !=
V_54 -> V_59 )
continue;
V_111 = F_40 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_111 < F_40 ( V_3 , V_5 -> V_13 ) )
V_114 = 1 ;
}
F_27 () ;
for ( V_119 = 0 ; V_119 < V_115 ; V_119 ++ ) {
if ( ! V_117 [ V_119 ] )
continue;
error = F_93 ( V_117 [ V_119 ] , V_54 , V_70 ) ;
if ( error && V_112 != - V_109 )
V_112 = error ;
}
* V_138 -= V_118 ;
F_82 () ;
} while ( V_115 && ! V_114 && * V_138 > 0 );
if ( V_139 && ! V_114 )
V_54 -> V_141 = V_111 ;
else
V_54 -> V_141 = 0 ;
F_109 ( & V_54 -> V_140 ) ;
F_42 ( V_54 ) ;
}
if ( V_113 && ( V_70 & V_133 ) && * V_138 > 0 ) {
V_139 = 0 ;
goto V_116;
}
return V_112 ;
}
int
F_30 (
T_8 * V_3 ,
int V_69 )
{
int V_138 = V_142 ;
return F_106 ( V_3 , V_69 , & V_138 ) ;
}
long
F_110 (
struct V_2 * V_3 ,
int V_138 )
{
F_22 ( V_3 ) ;
F_111 ( V_3 -> V_143 ) ;
return F_106 ( V_3 , V_52 | V_133 , & V_138 ) ;
}
int
F_112 (
struct V_2 * V_3 )
{
struct V_53 * V_54 ;
T_12 V_127 = 0 ;
int V_144 = 0 ;
while ( ( V_54 = F_91 ( V_3 , V_127 , V_46 ) ) ) {
V_127 = V_54 -> V_59 + 1 ;
V_144 += V_54 -> V_57 ;
F_42 ( V_54 ) ;
}
return V_144 ;
}
STATIC int
F_113 (
struct V_1 * V_5 ,
struct V_145 * V_146 )
{
if ( ( V_146 -> V_147 & V_148 ) &&
! F_114 ( F_4 ( V_5 ) -> V_149 , V_146 -> V_150 ) )
return 0 ;
if ( ( V_146 -> V_147 & V_151 ) &&
! F_115 ( F_4 ( V_5 ) -> V_152 , V_146 -> V_153 ) )
return 0 ;
if ( ( V_146 -> V_147 & V_154 ) &&
F_116 ( V_5 ) != V_146 -> V_155 )
return 0 ;
return 1 ;
}
STATIC int
F_117 (
struct V_1 * V_5 ,
struct V_145 * V_146 )
{
if ( ( V_146 -> V_147 & V_148 ) &&
F_114 ( F_4 ( V_5 ) -> V_149 , V_146 -> V_150 ) )
return 1 ;
if ( ( V_146 -> V_147 & V_151 ) &&
F_115 ( F_4 ( V_5 ) -> V_152 , V_146 -> V_153 ) )
return 1 ;
if ( ( V_146 -> V_147 & V_154 ) &&
F_116 ( V_5 ) == V_146 -> V_155 )
return 1 ;
return 0 ;
}
STATIC int
F_118 (
struct V_1 * V_5 ,
int V_70 ,
void * args )
{
int V_156 ;
struct V_145 * V_146 = args ;
bool V_157 = true ;
int V_158 ;
ASSERT ( ! V_146 || ( V_146 && V_146 -> V_159 != 0 ) ) ;
if ( ! F_119 ( V_5 , false ) ) {
F_120 ( V_5 ) ;
F_121 ( V_5 ) ;
return 0 ;
}
if ( ! ( V_70 & V_133 ) &&
F_122 ( F_4 ( V_5 ) -> V_160 , V_161 ) )
return 0 ;
if ( V_146 ) {
if ( V_146 -> V_147 & V_162 )
V_158 = F_117 ( V_5 , V_146 ) ;
else
V_158 = F_113 ( V_5 , V_146 ) ;
if ( ! V_158 )
return 0 ;
if ( V_146 -> V_147 & V_163 &&
F_123 ( V_5 ) < V_146 -> V_164 )
return 0 ;
if ( V_146 -> V_159 == V_5 -> V_13 )
V_157 = false ;
}
V_156 = F_124 ( V_5 -> V_16 , V_5 , V_157 ) ;
if ( V_156 == - V_73 && ! ( V_70 & V_133 ) )
V_156 = 0 ;
return V_156 ;
}
static int
F_125 (
struct V_2 * V_3 ,
struct V_145 * V_146 ,
int (* F_78)( struct V_1 * V_5 , int V_70 ,
void * args ) ,
int V_110 )
{
int V_70 = V_52 ;
if ( V_146 && ( V_146 -> V_147 & V_165 ) )
V_70 = V_133 ;
return F_90 ( V_3 , F_78 , V_70 ,
V_146 , V_110 ) ;
}
int
F_85 (
struct V_2 * V_3 ,
struct V_145 * V_146 )
{
return F_125 ( V_3 , V_146 , F_118 ,
V_120 ) ;
}
static int
F_126 (
struct V_1 * V_5 ,
int (* F_78)( struct V_2 * V_3 ,
struct V_145 * V_146 ) )
{
int V_166 = 0 ;
struct V_145 V_146 = { 0 } ;
struct V_167 * V_168 ;
ASSERT ( F_127 ( V_5 , V_99 ) ) ;
V_146 . V_159 = V_5 -> V_13 ;
V_146 . V_147 = V_162 | V_165 ;
if ( F_128 ( V_5 -> V_16 ) ) {
V_168 = F_129 ( V_5 , V_169 ) ;
if ( V_168 && F_130 ( V_168 ) ) {
V_146 . V_150 = F_4 ( V_5 ) -> V_149 ;
V_146 . V_147 |= V_148 ;
V_166 = 1 ;
}
}
if ( F_131 ( V_5 -> V_16 ) ) {
V_168 = F_129 ( V_5 , V_170 ) ;
if ( V_168 && F_130 ( V_168 ) ) {
V_146 . V_153 = F_4 ( V_5 ) -> V_152 ;
V_146 . V_147 |= V_151 ;
V_166 = 1 ;
}
}
if ( V_166 )
F_78 ( V_5 -> V_16 , & V_146 ) ;
return V_166 ;
}
int
F_132 (
struct V_1 * V_5 )
{
return F_126 ( V_5 , F_85 ) ;
}
static void
F_133 (
T_10 * V_5 ,
void (* F_78)( struct V_2 * V_3 ) ,
void (* F_134)( struct V_2 * V_3 , T_12 V_171 ,
int error , unsigned long V_172 ) ,
int V_110 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_53 * V_54 ;
int V_173 ;
if ( V_5 -> V_26 & V_174 )
return;
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_26 |= V_174 ;
F_21 ( & V_5 -> V_12 ) ;
V_54 = F_38 ( V_3 , F_39 ( V_3 , V_5 -> V_13 ) ) ;
F_20 ( & V_54 -> V_56 ) ;
V_173 = F_24 ( & V_54 -> V_61 , V_110 ) ;
F_32 ( & V_54 -> V_61 ,
F_40 ( V_5 -> V_16 , V_5 -> V_13 ) , V_110 ) ;
if ( ! V_173 ) {
F_20 ( & V_5 -> V_16 -> V_58 ) ;
F_32 ( & V_5 -> V_16 -> V_45 ,
F_39 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_110 ) ;
F_21 ( & V_5 -> V_16 -> V_58 ) ;
F_78 ( V_5 -> V_16 ) ;
F_134 ( V_5 -> V_16 , V_54 -> V_59 , - 1 , V_60 ) ;
}
F_21 ( & V_54 -> V_56 ) ;
F_42 ( V_54 ) ;
}
void
F_135 (
T_10 * V_5 )
{
F_136 ( V_5 ) ;
return F_133 ( V_5 , F_83 ,
V_175 ,
V_120 ) ;
}
static void
F_137 (
T_10 * V_5 ,
void (* F_138)( struct V_2 * V_3 , T_12 V_171 ,
int error , unsigned long V_172 ) ,
int V_110 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_53 * V_54 ;
F_20 ( & V_5 -> V_12 ) ;
V_5 -> V_26 &= ~ V_174 ;
F_21 ( & V_5 -> V_12 ) ;
V_54 = F_38 ( V_3 , F_39 ( V_3 , V_5 -> V_13 ) ) ;
F_20 ( & V_54 -> V_56 ) ;
F_35 ( & V_54 -> V_61 ,
F_40 ( V_5 -> V_16 , V_5 -> V_13 ) , V_110 ) ;
if ( ! F_24 ( & V_54 -> V_61 , V_110 ) ) {
F_20 ( & V_5 -> V_16 -> V_58 ) ;
F_35 ( & V_5 -> V_16 -> V_45 ,
F_39 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_110 ) ;
F_21 ( & V_5 -> V_16 -> V_58 ) ;
F_138 ( V_5 -> V_16 , V_54 -> V_59 , - 1 , V_60 ) ;
}
F_21 ( & V_54 -> V_56 ) ;
F_42 ( V_54 ) ;
}
void
F_121 (
T_10 * V_5 )
{
F_139 ( V_5 ) ;
return F_137 ( V_5 ,
V_176 , V_120 ) ;
}
STATIC int
F_140 (
struct V_1 * V_5 ,
int V_70 ,
void * args )
{
int V_156 ;
struct V_145 * V_146 = args ;
bool V_157 = true ;
int V_158 ;
ASSERT ( ! V_146 || ( V_146 && V_146 -> V_159 != 0 ) ) ;
if ( ! F_141 ( V_5 ) ) {
F_142 ( V_5 ) ;
F_143 ( V_5 ) ;
return 0 ;
}
if ( F_122 ( F_4 ( V_5 ) -> V_160 , V_161 ) ||
F_122 ( F_4 ( V_5 ) -> V_160 , V_177 ) ||
F_7 ( & F_4 ( V_5 ) -> V_178 ) )
return 0 ;
if ( V_146 ) {
if ( V_146 -> V_147 & V_162 )
V_158 = F_117 ( V_5 , V_146 ) ;
else
V_158 = F_113 ( V_5 , V_146 ) ;
if ( ! V_158 )
return 0 ;
if ( V_146 -> V_147 & V_163 &&
F_123 ( V_5 ) < V_146 -> V_164 )
return 0 ;
if ( V_146 -> V_159 == V_5 -> V_13 )
V_157 = false ;
}
if ( V_157 ) {
F_53 ( V_5 , V_99 ) ;
F_53 ( V_5 , V_179 ) ;
}
V_156 = F_144 ( V_5 , 0 , V_180 ) ;
if ( V_157 ) {
F_66 ( V_5 , V_179 ) ;
F_66 ( V_5 , V_99 ) ;
}
return V_156 ;
}
int
F_88 (
struct V_2 * V_3 ,
struct V_145 * V_146 )
{
return F_125 ( V_3 , V_146 , F_140 ,
V_124 ) ;
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
return F_133 ( V_5 , F_86 ,
V_181 ,
V_124 ) ;
}
void
F_143 (
T_10 * V_5 )
{
F_148 ( V_5 ) ;
return F_137 ( V_5 ,
V_182 , V_124 ) ;
}
