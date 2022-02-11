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
F_5 ( V_6 , V_5 ) ;
}
void
F_14 (
struct V_1 * V_5 )
{
switch ( F_4 ( V_5 ) -> V_9 & V_29 ) {
case V_30 :
case V_31 :
case V_32 :
F_15 ( V_5 , V_33 ) ;
break;
}
if ( V_5 -> V_19 )
F_15 ( V_5 , V_34 ) ;
if ( V_5 -> V_35 ) {
ASSERT ( ! ( V_5 -> V_35 -> V_36 . V_37 & V_38 ) ) ;
F_16 ( V_5 ) ;
V_5 -> V_35 = NULL ;
}
F_17 ( & V_5 -> V_12 ) ;
V_5 -> V_22 = V_39 ;
V_5 -> V_13 = 0 ;
F_18 ( & V_5 -> V_12 ) ;
ASSERT ( F_7 ( & V_5 -> V_11 ) == 0 ) ;
ASSERT ( ! F_9 ( V_5 ) ) ;
F_19 ( V_5 -> V_16 , V_10 ) ;
F_20 ( & F_4 ( V_5 ) -> V_28 , F_11 ) ;
}
static int
F_21 (
struct V_2 * V_3 ,
struct V_27 * V_27 )
{
int error ;
T_2 V_40 = V_27 -> V_41 ;
T_2 V_42 = V_27 -> V_43 ;
T_3 V_44 = V_27 -> V_45 ;
T_4 V_46 = V_27 -> V_9 ;
error = F_3 ( V_3 -> V_8 , V_27 ) ;
F_22 ( V_27 , V_40 ) ;
V_27 -> V_43 = V_42 ;
V_27 -> V_45 = V_44 ;
V_27 -> V_9 = V_46 ;
return error ;
}
static int
F_23 (
struct V_47 * V_48 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_49 ,
int V_50 ) __releases( T_5 )
{
struct V_27 * V_27 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_16 ;
int error ;
F_17 ( & V_5 -> V_12 ) ;
if ( V_5 -> V_13 != V_4 ) {
F_24 ( V_5 ) ;
F_6 ( V_3 , V_51 ) ;
error = - V_52 ;
goto V_53;
}
if ( V_5 -> V_22 & ( V_54 | V_39 ) ) {
F_24 ( V_5 ) ;
F_6 ( V_3 , V_51 ) ;
error = - V_52 ;
goto V_53;
}
if ( F_4 ( V_5 ) -> V_9 == 0 && ! ( V_49 & V_55 ) ) {
error = - V_56 ;
goto V_53;
}
if ( V_5 -> V_22 & V_57 ) {
F_25 ( V_5 ) ;
V_5 -> V_22 |= V_39 ;
F_18 ( & V_5 -> V_12 ) ;
F_26 () ;
error = F_21 ( V_3 , V_27 ) ;
if ( error ) {
F_27 () ;
F_17 ( & V_5 -> V_12 ) ;
V_5 -> V_22 &= ~ ( V_54 | V_39 ) ;
ASSERT ( V_5 -> V_22 & V_57 ) ;
F_28 ( V_5 ) ;
goto V_53;
}
F_17 ( & V_48 -> V_58 ) ;
F_17 ( & V_5 -> V_12 ) ;
V_5 -> V_22 &= ~ V_59 ;
V_5 -> V_22 |= V_54 ;
F_29 ( V_3 , V_48 , V_5 ) ;
V_27 -> V_60 = V_61 ;
ASSERT ( ! F_30 ( & V_5 -> V_14 . V_62 ) ) ;
F_10 ( & V_5 -> V_14 , V_15 , L_1 , V_5 -> V_13 ) ;
F_18 ( & V_5 -> V_12 ) ;
F_18 ( & V_48 -> V_58 ) ;
} else {
if ( ! F_31 ( V_27 ) ) {
F_24 ( V_5 ) ;
error = - V_52 ;
goto V_53;
}
F_18 ( & V_5 -> V_12 ) ;
F_26 () ;
F_32 ( V_5 ) ;
}
if ( V_50 != 0 )
F_33 ( V_5 , V_50 ) ;
F_34 ( V_5 , V_63 | V_64 ) ;
F_6 ( V_3 , V_65 ) ;
return 0 ;
V_53:
F_18 ( & V_5 -> V_12 ) ;
F_26 () ;
return error ;
}
static int
F_35 (
struct V_2 * V_3 ,
struct V_47 * V_48 ,
T_6 * V_66 ,
T_1 V_4 ,
struct V_1 * * V_67 ,
int V_49 ,
int V_50 )
{
struct V_1 * V_5 ;
int error ;
T_7 V_68 = F_36 ( V_3 , V_4 ) ;
int V_69 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_70 ;
error = F_37 ( V_3 , V_66 , V_5 , V_49 ) ;
if ( error )
goto V_71;
F_38 ( V_5 ) ;
if ( ( F_4 ( V_5 ) -> V_9 == 0 ) && ! ( V_49 & V_55 ) ) {
error = - V_56 ;
goto V_71;
}
if ( F_39 ( V_72 ) ) {
error = - V_52 ;
goto V_71;
}
if ( V_50 ) {
if ( ! F_40 ( V_5 , V_50 ) )
F_41 () ;
}
V_69 = V_54 ;
if ( V_49 & V_73 )
V_69 |= V_64 ;
V_5 -> V_74 = NULL ;
V_5 -> V_75 = NULL ;
V_5 -> V_76 = NULL ;
F_42 ( V_5 , V_69 ) ;
F_17 ( & V_48 -> V_58 ) ;
error = F_43 ( & V_48 -> V_77 , V_68 , V_5 ) ;
if ( F_44 ( error ) ) {
F_45 ( error != - V_78 ) ;
F_6 ( V_3 , V_79 ) ;
error = - V_52 ;
goto V_80;
}
F_18 ( & V_48 -> V_58 ) ;
F_46 () ;
* V_67 = V_5 ;
return 0 ;
V_80:
F_18 ( & V_48 -> V_58 ) ;
F_46 () ;
if ( V_50 )
F_47 ( V_5 , V_50 ) ;
V_71:
F_48 ( F_4 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return error ;
}
int
F_49 (
T_8 * V_3 ,
T_6 * V_66 ,
T_1 V_4 ,
T_9 V_49 ,
T_9 V_50 ,
T_10 * * V_67 )
{
T_10 * V_5 ;
int error ;
T_11 * V_48 ;
T_7 V_68 ;
ASSERT ( ( V_50 & ( V_81 | V_82 ) ) == 0 ) ;
if ( ! V_4 || F_50 ( V_3 , V_4 ) >= V_3 -> V_83 . V_84 )
return - V_85 ;
F_6 ( V_3 , V_86 ) ;
V_48 = F_51 ( V_3 , F_50 ( V_3 , V_4 ) ) ;
V_68 = F_36 ( V_3 , V_4 ) ;
V_87:
error = 0 ;
F_27 () ;
V_5 = F_52 ( & V_48 -> V_77 , V_68 ) ;
if ( V_5 ) {
error = F_23 ( V_48 , V_5 , V_4 , V_49 , V_50 ) ;
if ( error )
goto V_88;
} else {
F_26 () ;
F_6 ( V_3 , V_89 ) ;
error = F_35 ( V_3 , V_48 , V_66 , V_4 , & V_5 ,
V_49 , V_50 ) ;
if ( error )
goto V_88;
}
F_53 ( V_48 ) ;
* V_67 = V_5 ;
if ( F_54 ( V_5 , V_54 ) && F_4 ( V_5 ) -> V_9 != 0 )
F_55 ( V_5 ) ;
return 0 ;
V_88:
if ( error == - V_52 ) {
F_56 ( 1 ) ;
goto V_87;
}
F_53 ( V_48 ) ;
return error ;
}
STATIC int
F_57 (
struct V_1 * V_5 )
{
struct V_27 * V_27 = F_4 ( V_5 ) ;
ASSERT ( F_58 () ) ;
F_17 ( & V_5 -> V_12 ) ;
if ( ! V_5 -> V_13 )
goto V_90;
if ( F_59 ( V_5 , V_54 | V_57 | V_39 ) )
goto V_90;
F_18 ( & V_5 -> V_12 ) ;
if ( F_60 ( V_5 -> V_16 ) )
return - V_91 ;
if ( ! F_31 ( V_27 ) )
return - V_56 ;
return 0 ;
V_90:
F_18 ( & V_5 -> V_12 ) ;
return - V_56 ;
}
STATIC int
F_61 (
struct V_2 * V_3 ,
struct V_47 * V_48 ,
int (* F_62)( struct V_1 * V_5 , int V_49 ,
void * args ) ,
int V_49 ,
void * args ,
int V_92 )
{
T_2 V_93 ;
int V_94 = 0 ;
int V_95 ;
int V_96 ;
int V_97 ;
V_98:
V_96 = 0 ;
V_95 = 0 ;
V_93 = 0 ;
V_97 = 0 ;
do {
struct V_1 * V_99 [ V_100 ] ;
int error = 0 ;
int V_101 ;
F_27 () ;
if ( V_92 == - 1 )
V_97 = F_63 ( & V_48 -> V_77 ,
( void * * ) V_99 , V_93 ,
V_100 ) ;
else
V_97 = F_64 (
& V_48 -> V_77 ,
( void * * ) V_99 , V_93 ,
V_100 , V_92 ) ;
if ( ! V_97 ) {
F_26 () ;
break;
}
for ( V_101 = 0 ; V_101 < V_97 ; V_101 ++ ) {
struct V_1 * V_5 = V_99 [ V_101 ] ;
if ( V_96 || F_57 ( V_5 ) )
V_99 [ V_101 ] = NULL ;
if ( F_50 ( V_3 , V_5 -> V_13 ) != V_48 -> V_102 )
continue;
V_93 = F_36 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_93 < F_36 ( V_3 , V_5 -> V_13 ) )
V_96 = 1 ;
}
F_26 () ;
for ( V_101 = 0 ; V_101 < V_97 ; V_101 ++ ) {
if ( ! V_99 [ V_101 ] )
continue;
error = F_62 ( V_99 [ V_101 ] , V_49 , args ) ;
F_65 ( V_99 [ V_101 ] ) ;
if ( error == - V_52 ) {
V_95 ++ ;
continue;
}
if ( error && V_94 != - V_91 )
V_94 = error ;
}
if ( error == - V_91 )
break;
F_66 () ;
} while ( V_97 && ! V_96 );
if ( V_95 ) {
F_56 ( 1 ) ;
goto V_98;
}
return V_94 ;
}
STATIC void
F_67 (
struct V_2 * V_3 )
{
F_27 () ;
if ( F_68 ( & V_3 -> V_103 , V_104 ) )
F_69 ( V_3 -> V_105 ,
& V_3 -> V_106 ,
F_70 ( V_107 * 1000 ) ) ;
F_26 () ;
}
void
F_71 (
struct V_108 * V_109 )
{
struct V_2 * V_3 = F_12 ( F_72 ( V_109 ) ,
struct V_2 , V_106 ) ;
F_73 ( V_3 , NULL ) ;
F_67 ( V_3 ) ;
}
int
F_74 (
struct V_2 * V_3 ,
int (* F_62)( struct V_1 * V_5 , int V_49 ,
void * args ) ,
int V_49 ,
void * args )
{
struct V_47 * V_48 ;
int error = 0 ;
int V_94 = 0 ;
T_12 V_110 ;
V_110 = 0 ;
while ( ( V_48 = F_51 ( V_3 , V_110 ) ) ) {
V_110 = V_48 -> V_102 + 1 ;
error = F_61 ( V_3 , V_48 , F_62 , V_49 , args , - 1 ) ;
F_53 ( V_48 ) ;
if ( error ) {
V_94 = error ;
if ( error == - V_91 )
break;
}
}
return V_94 ;
}
int
F_75 (
struct V_2 * V_3 ,
int (* F_62)( struct V_1 * V_5 , int V_49 ,
void * args ) ,
int V_49 ,
void * args ,
int V_92 )
{
struct V_47 * V_48 ;
int error = 0 ;
int V_94 = 0 ;
T_12 V_110 ;
V_110 = 0 ;
while ( ( V_48 = F_76 ( V_3 , V_110 , V_92 ) ) ) {
V_110 = V_48 -> V_102 + 1 ;
error = F_61 ( V_3 , V_48 , F_62 , V_49 , args , V_92 ) ;
F_53 ( V_48 ) ;
if ( error ) {
V_94 = error ;
if ( error == - V_91 )
break;
}
}
return V_94 ;
}
static void
F_77 (
struct V_2 * V_3 )
{
F_27 () ;
if ( F_68 ( & V_3 -> V_103 , V_111 ) ) {
F_69 ( V_3 -> V_112 , & V_3 -> V_113 ,
F_70 ( V_114 / 6 * 10 ) ) ;
}
F_26 () ;
}
void
F_78 (
struct V_108 * V_109 )
{
struct V_2 * V_3 = F_12 ( F_72 ( V_109 ) ,
struct V_2 , V_113 ) ;
F_79 ( V_3 , V_115 ) ;
F_77 ( V_3 ) ;
}
static void
F_80 (
struct V_47 * V_48 ,
struct V_1 * V_5 )
{
F_81 ( & V_48 -> V_77 ,
F_36 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_111 ) ;
if ( ! V_48 -> V_116 ) {
F_17 ( & V_5 -> V_16 -> V_117 ) ;
F_81 ( & V_5 -> V_16 -> V_103 ,
F_50 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_111 ) ;
F_18 ( & V_5 -> V_16 -> V_117 ) ;
F_77 ( V_5 -> V_16 ) ;
F_82 ( V_5 -> V_16 , V_48 -> V_102 ,
- 1 , V_118 ) ;
}
V_48 -> V_116 ++ ;
}
void
F_83 (
T_10 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_47 * V_48 ;
V_48 = F_51 ( V_3 , F_50 ( V_3 , V_5 -> V_13 ) ) ;
F_17 ( & V_48 -> V_58 ) ;
F_17 ( & V_5 -> V_12 ) ;
F_80 ( V_48 , V_5 ) ;
F_84 ( V_5 , V_57 ) ;
F_18 ( & V_5 -> V_12 ) ;
F_18 ( & V_48 -> V_58 ) ;
F_53 ( V_48 ) ;
}
STATIC void
F_85 (
T_11 * V_48 ,
T_10 * V_5 )
{
V_48 -> V_116 -- ;
if ( ! V_48 -> V_116 ) {
F_17 ( & V_5 -> V_16 -> V_117 ) ;
F_86 ( & V_5 -> V_16 -> V_103 ,
F_50 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_111 ) ;
F_18 ( & V_5 -> V_16 -> V_117 ) ;
F_87 ( V_5 -> V_16 , V_48 -> V_102 ,
- 1 , V_118 ) ;
}
}
STATIC void
F_29 (
T_8 * V_3 ,
T_11 * V_48 ,
T_10 * V_5 )
{
F_86 ( & V_48 -> V_77 ,
F_36 ( V_3 , V_5 -> V_13 ) , V_111 ) ;
F_85 ( V_48 , V_5 ) ;
}
STATIC int
F_88 (
struct V_1 * V_5 ,
int V_49 )
{
ASSERT ( F_58 () ) ;
if ( ! V_5 -> V_13 )
return 1 ;
if ( ( V_49 & V_115 ) &&
F_59 ( V_5 , V_119 | V_39 ) )
return 1 ;
F_17 ( & V_5 -> V_12 ) ;
if ( ! F_59 ( V_5 , V_57 ) ||
F_59 ( V_5 , V_39 ) ) {
F_18 ( & V_5 -> V_12 ) ;
return 1 ;
}
F_84 ( V_5 , V_39 ) ;
F_18 ( & V_5 -> V_12 ) ;
return 0 ;
}
STATIC int
F_89 (
struct V_1 * V_5 ,
struct V_47 * V_48 ,
int V_120 )
{
struct V_121 * V_122 = NULL ;
int error ;
V_98:
error = 0 ;
F_33 ( V_5 , V_123 ) ;
if ( ! F_90 ( V_5 ) ) {
if ( ! ( V_120 & V_124 ) )
goto V_125;
F_91 ( V_5 ) ;
}
if ( F_60 ( V_5 -> V_16 ) ) {
F_92 ( V_5 ) ;
F_93 ( V_5 , false ) ;
goto V_126;
}
if ( F_94 ( V_5 ) ) {
if ( ! ( V_120 & V_124 ) )
goto V_127;
F_92 ( V_5 ) ;
}
if ( F_54 ( V_5 , V_63 ) )
goto V_126;
if ( F_95 ( V_5 ) )
goto V_126;
if ( ! ( V_120 & V_124 ) )
goto V_127;
error = F_96 ( V_5 , & V_122 ) ;
if ( error == - V_52 ) {
F_47 ( V_5 , V_123 ) ;
F_56 ( 2 ) ;
goto V_98;
}
if ( ! error ) {
error = F_97 ( V_122 ) ;
F_98 ( V_122 ) ;
}
F_91 ( V_5 ) ;
V_126:
F_99 ( V_5 ) ;
F_47 ( V_5 , V_123 ) ;
F_6 ( V_5 -> V_16 , V_128 ) ;
F_17 ( & V_48 -> V_58 ) ;
if ( ! F_100 ( & V_48 -> V_77 ,
F_36 ( V_5 -> V_16 , V_5 -> V_13 ) ) )
ASSERT ( 0 ) ;
F_85 ( V_48 , V_5 ) ;
F_18 ( & V_48 -> V_58 ) ;
F_33 ( V_5 , V_123 ) ;
F_101 ( V_5 ) ;
F_47 ( V_5 , V_123 ) ;
F_14 ( V_5 ) ;
return error ;
V_127:
F_99 ( V_5 ) ;
V_125:
F_34 ( V_5 , V_39 ) ;
F_47 ( V_5 , V_123 ) ;
return 0 ;
}
STATIC int
F_102 (
struct V_2 * V_3 ,
int V_49 ,
int * V_129 )
{
struct V_47 * V_48 ;
int error = 0 ;
int V_94 = 0 ;
T_12 V_110 ;
int V_130 = V_49 & V_115 ;
int V_95 ;
V_98:
V_110 = 0 ;
V_95 = 0 ;
while ( ( V_48 = F_76 ( V_3 , V_110 , V_111 ) ) ) {
unsigned long V_93 = 0 ;
int V_96 = 0 ;
int V_97 = 0 ;
V_110 = V_48 -> V_102 + 1 ;
if ( V_130 ) {
if ( ! F_103 ( & V_48 -> V_131 ) ) {
V_95 ++ ;
F_53 ( V_48 ) ;
continue;
}
V_93 = V_48 -> V_132 ;
} else
F_104 ( & V_48 -> V_131 ) ;
do {
struct V_1 * V_99 [ V_100 ] ;
int V_101 ;
F_27 () ;
V_97 = F_64 (
& V_48 -> V_77 ,
( void * * ) V_99 , V_93 ,
V_100 ,
V_111 ) ;
if ( ! V_97 ) {
V_96 = 1 ;
F_26 () ;
break;
}
for ( V_101 = 0 ; V_101 < V_97 ; V_101 ++ ) {
struct V_1 * V_5 = V_99 [ V_101 ] ;
if ( V_96 || F_88 ( V_5 , V_49 ) )
V_99 [ V_101 ] = NULL ;
if ( F_50 ( V_3 , V_5 -> V_13 ) !=
V_48 -> V_102 )
continue;
V_93 = F_36 ( V_3 , V_5 -> V_13 + 1 ) ;
if ( V_93 < F_36 ( V_3 , V_5 -> V_13 ) )
V_96 = 1 ;
}
F_26 () ;
for ( V_101 = 0 ; V_101 < V_97 ; V_101 ++ ) {
if ( ! V_99 [ V_101 ] )
continue;
error = F_89 ( V_99 [ V_101 ] , V_48 , V_49 ) ;
if ( error && V_94 != - V_91 )
V_94 = error ;
}
* V_129 -= V_100 ;
F_66 () ;
} while ( V_97 && ! V_96 && * V_129 > 0 );
if ( V_130 && ! V_96 )
V_48 -> V_132 = V_93 ;
else
V_48 -> V_132 = 0 ;
F_105 ( & V_48 -> V_131 ) ;
F_53 ( V_48 ) ;
}
if ( V_95 && ( V_49 & V_124 ) && * V_129 > 0 ) {
V_130 = 0 ;
goto V_98;
}
return V_94 ;
}
int
F_79 (
T_8 * V_3 ,
int V_46 )
{
int V_129 = V_133 ;
return F_102 ( V_3 , V_46 , & V_129 ) ;
}
long
F_106 (
struct V_2 * V_3 ,
int V_129 )
{
F_77 ( V_3 ) ;
F_107 ( V_3 -> V_134 ) ;
return F_102 ( V_3 , V_115 | V_124 , & V_129 ) ;
}
int
F_108 (
struct V_2 * V_3 )
{
struct V_47 * V_48 ;
T_12 V_110 = 0 ;
int V_135 = 0 ;
while ( ( V_48 = F_76 ( V_3 , V_110 , V_111 ) ) ) {
V_110 = V_48 -> V_102 + 1 ;
V_135 += V_48 -> V_116 ;
F_53 ( V_48 ) ;
}
return V_135 ;
}
STATIC int
F_109 (
struct V_1 * V_5 ,
struct V_136 * V_137 )
{
if ( ( V_137 -> V_138 & V_139 ) &&
! F_110 ( F_4 ( V_5 ) -> V_140 , V_137 -> V_141 ) )
return 0 ;
if ( ( V_137 -> V_138 & V_142 ) &&
! F_111 ( F_4 ( V_5 ) -> V_143 , V_137 -> V_144 ) )
return 0 ;
if ( ( V_137 -> V_138 & V_145 ) &&
F_112 ( V_5 ) != V_137 -> V_146 )
return 0 ;
return 1 ;
}
STATIC int
F_113 (
struct V_1 * V_5 ,
struct V_136 * V_137 )
{
if ( ( V_137 -> V_138 & V_139 ) &&
F_110 ( F_4 ( V_5 ) -> V_140 , V_137 -> V_141 ) )
return 1 ;
if ( ( V_137 -> V_138 & V_142 ) &&
F_111 ( F_4 ( V_5 ) -> V_143 , V_137 -> V_144 ) )
return 1 ;
if ( ( V_137 -> V_138 & V_145 ) &&
F_112 ( V_5 ) == V_137 -> V_146 )
return 1 ;
return 0 ;
}
STATIC int
F_114 (
struct V_1 * V_5 ,
int V_49 ,
void * args )
{
int V_147 ;
struct V_136 * V_137 = args ;
bool V_148 = true ;
int V_149 ;
ASSERT ( ! V_137 || ( V_137 && V_137 -> V_150 != 0 ) ) ;
if ( ! F_115 ( V_5 , false ) ) {
F_116 ( V_5 ) ;
F_117 ( V_5 ) ;
return 0 ;
}
if ( ! ( V_49 & V_124 ) &&
F_118 ( F_4 ( V_5 ) -> V_151 , V_152 ) )
return 0 ;
if ( V_137 ) {
if ( V_137 -> V_138 & V_153 )
V_149 = F_113 ( V_5 , V_137 ) ;
else
V_149 = F_109 ( V_5 , V_137 ) ;
if ( ! V_149 )
return 0 ;
if ( V_137 -> V_138 & V_154 &&
F_119 ( V_5 ) < V_137 -> V_155 )
return 0 ;
if ( V_137 -> V_150 == V_5 -> V_13 )
V_148 = false ;
}
V_147 = F_120 ( V_5 -> V_16 , V_5 , V_148 ) ;
if ( V_147 == - V_52 && ! ( V_49 & V_124 ) )
V_147 = 0 ;
return V_147 ;
}
int
F_73 (
struct V_2 * V_3 ,
struct V_136 * V_137 )
{
int V_49 = V_115 ;
if ( V_137 && ( V_137 -> V_138 & V_156 ) )
V_49 = V_124 ;
return F_75 ( V_3 , F_114 , V_49 ,
V_137 , V_104 ) ;
}
int
F_121 (
struct V_1 * V_5 )
{
int V_157 = 0 ;
struct V_136 V_137 = { 0 } ;
struct V_158 * V_159 ;
ASSERT ( F_122 ( V_5 , V_81 ) ) ;
V_137 . V_150 = V_5 -> V_13 ;
V_137 . V_138 = V_153 | V_156 ;
if ( F_123 ( V_5 -> V_16 ) ) {
V_159 = F_124 ( V_5 , V_160 ) ;
if ( V_159 && F_125 ( V_159 ) ) {
V_137 . V_141 = F_4 ( V_5 ) -> V_140 ;
V_137 . V_138 |= V_139 ;
V_157 = 1 ;
}
}
if ( F_126 ( V_5 -> V_16 ) ) {
V_159 = F_124 ( V_5 , V_161 ) ;
if ( V_159 && F_125 ( V_159 ) ) {
V_137 . V_144 = F_4 ( V_5 ) -> V_143 ;
V_137 . V_138 |= V_142 ;
V_157 = 1 ;
}
}
if ( V_157 )
F_73 ( V_5 -> V_16 , & V_137 ) ;
return V_157 ;
}
void
F_127 (
T_10 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_47 * V_48 ;
int V_162 ;
V_48 = F_51 ( V_3 , F_50 ( V_3 , V_5 -> V_13 ) ) ;
F_17 ( & V_48 -> V_58 ) ;
F_128 ( V_5 ) ;
V_162 = F_68 ( & V_48 -> V_77 ,
V_104 ) ;
F_81 ( & V_48 -> V_77 ,
F_36 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_104 ) ;
if ( ! V_162 ) {
F_17 ( & V_5 -> V_16 -> V_117 ) ;
F_81 ( & V_5 -> V_16 -> V_103 ,
F_50 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_104 ) ;
F_18 ( & V_5 -> V_16 -> V_117 ) ;
F_67 ( V_5 -> V_16 ) ;
F_129 ( V_5 -> V_16 , V_48 -> V_102 ,
- 1 , V_118 ) ;
}
F_18 ( & V_48 -> V_58 ) ;
F_53 ( V_48 ) ;
}
void
F_117 (
T_10 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_16 ;
struct V_47 * V_48 ;
V_48 = F_51 ( V_3 , F_50 ( V_3 , V_5 -> V_13 ) ) ;
F_17 ( & V_48 -> V_58 ) ;
F_130 ( V_5 ) ;
F_86 ( & V_48 -> V_77 ,
F_36 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_104 ) ;
if ( ! F_68 ( & V_48 -> V_77 , V_104 ) ) {
F_17 ( & V_5 -> V_16 -> V_117 ) ;
F_86 ( & V_5 -> V_16 -> V_103 ,
F_50 ( V_5 -> V_16 , V_5 -> V_13 ) ,
V_104 ) ;
F_18 ( & V_5 -> V_16 -> V_117 ) ;
F_131 ( V_5 -> V_16 , V_48 -> V_102 ,
- 1 , V_118 ) ;
}
F_18 ( & V_48 -> V_58 ) ;
F_53 ( V_48 ) ;
}
