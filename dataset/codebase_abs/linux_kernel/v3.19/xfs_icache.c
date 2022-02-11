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
F_6 ( V_9 ) ;
ASSERT ( F_7 ( & V_5 -> V_10 ) == 0 ) ;
ASSERT ( ! F_8 ( & V_5 -> V_11 ) ) ;
ASSERT ( ! F_9 ( V_5 ) ) ;
ASSERT ( V_5 -> V_12 == 0 ) ;
F_10 ( & V_5 -> V_13 , V_14 , L_1 , V_5 -> V_12 ) ;
V_5 -> V_12 = V_4 ;
V_5 -> V_15 = V_3 ;
memset ( & V_5 -> V_16 , 0 , sizeof( struct V_17 ) ) ;
V_5 -> V_18 = NULL ;
memset ( & V_5 -> V_19 , 0 , sizeof( V_20 ) ) ;
V_5 -> V_21 = 0 ;
V_5 -> V_22 = 0 ;
memset ( & V_5 -> V_23 , 0 , sizeof( V_24 ) ) ;
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
switch ( V_5 -> V_23 . V_29 & V_30 ) {
case V_31 :
case V_32 :
case V_33 :
F_15 ( V_5 , V_34 ) ;
break;
}
if ( V_5 -> V_18 )
F_15 ( V_5 , V_35 ) ;
if ( V_5 -> V_36 ) {
ASSERT ( ! ( V_5 -> V_36 -> V_37 . V_38 & V_39 ) ) ;
F_16 ( V_5 ) ;
V_5 -> V_36 = NULL ;
}
F_17 ( & V_5 -> V_11 ) ;
V_5 -> V_21 = V_40 ;
V_5 -> V_12 = 0 ;
F_18 ( & V_5 -> V_11 ) ;
ASSERT ( F_7 ( & V_5 -> V_10 ) == 0 ) ;
ASSERT ( ! F_9 ( V_5 ) ) ;
F_19 ( V_9 ) ;
F_20 ( & F_4 ( V_5 ) -> V_28 , F_11 ) ;
}
static int
F_21 (
struct V_41 * V_42 ,
struct V_1 * V_5 ,
T_1 V_4 ,
int V_43 ,
int V_44 ) __releases( T_2 )
{
struct V_27 * V_27 = F_4 ( V_5 ) ;
struct V_2 * V_3 = V_5 -> V_15 ;
int error ;
F_17 ( & V_5 -> V_11 ) ;
if ( V_5 -> V_12 != V_4 ) {
F_22 ( V_5 ) ;
F_6 ( V_45 ) ;
error = - V_46 ;
goto V_47;
}
if ( V_5 -> V_21 & ( V_48 | V_40 ) ) {
F_22 ( V_5 ) ;
F_6 ( V_45 ) ;
error = - V_46 ;
goto V_47;
}
if ( V_5 -> V_23 . V_29 == 0 && ! ( V_43 & V_49 ) ) {
error = - V_50 ;
goto V_47;
}
if ( V_5 -> V_21 & V_51 ) {
F_23 ( V_5 ) ;
V_5 -> V_21 |= V_40 ;
F_18 ( & V_5 -> V_11 ) ;
F_24 () ;
error = F_3 ( V_3 -> V_8 , V_27 ) ;
if ( error ) {
F_25 () ;
F_17 ( & V_5 -> V_11 ) ;
V_5 -> V_21 &= ~ ( V_48 | V_40 ) ;
ASSERT ( V_5 -> V_21 & V_51 ) ;
F_26 ( V_5 ) ;
goto V_47;
}
F_17 ( & V_42 -> V_52 ) ;
F_17 ( & V_5 -> V_11 ) ;
V_5 -> V_21 &= ~ V_53 ;
V_5 -> V_21 |= V_48 ;
F_27 ( V_3 , V_42 , V_5 ) ;
V_27 -> V_54 = V_55 ;
ASSERT ( ! F_28 ( & V_5 -> V_13 . V_56 ) ) ;
F_10 ( & V_5 -> V_13 , V_14 , L_1 , V_5 -> V_12 ) ;
F_18 ( & V_5 -> V_11 ) ;
F_18 ( & V_42 -> V_52 ) ;
} else {
if ( ! F_29 ( V_27 ) ) {
F_22 ( V_5 ) ;
error = - V_46 ;
goto V_47;
}
F_18 ( & V_5 -> V_11 ) ;
F_24 () ;
F_30 ( V_5 ) ;
}
if ( V_44 != 0 )
F_31 ( V_5 , V_44 ) ;
F_32 ( V_5 , V_57 | V_58 ) ;
F_6 ( V_59 ) ;
return 0 ;
V_47:
F_18 ( & V_5 -> V_11 ) ;
F_24 () ;
return error ;
}
static int
F_33 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
T_3 * V_60 ,
T_1 V_4 ,
struct V_1 * * V_61 ,
int V_43 ,
int V_44 )
{
struct V_1 * V_5 ;
int error ;
T_4 V_62 = F_34 ( V_3 , V_4 ) ;
int V_63 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return - V_64 ;
error = F_35 ( V_3 , V_60 , V_5 , V_43 ) ;
if ( error )
goto V_65;
F_36 ( V_5 ) ;
if ( ( V_5 -> V_23 . V_29 == 0 ) && ! ( V_43 & V_49 ) ) {
error = - V_50 ;
goto V_65;
}
if ( F_37 ( V_66 ) ) {
error = - V_46 ;
goto V_65;
}
if ( V_44 ) {
if ( ! F_38 ( V_5 , V_44 ) )
F_39 () ;
}
V_63 = V_48 ;
if ( V_43 & V_67 )
V_63 |= V_58 ;
V_5 -> V_68 = NULL ;
V_5 -> V_69 = NULL ;
V_5 -> V_70 = NULL ;
F_40 ( V_5 , V_63 ) ;
F_17 ( & V_42 -> V_52 ) ;
error = F_41 ( & V_42 -> V_71 , V_62 , V_5 ) ;
if ( F_42 ( error ) ) {
F_43 ( error != - V_72 ) ;
F_6 ( V_73 ) ;
error = - V_46 ;
goto V_74;
}
F_18 ( & V_42 -> V_52 ) ;
F_44 () ;
* V_61 = V_5 ;
return 0 ;
V_74:
F_18 ( & V_42 -> V_52 ) ;
F_44 () ;
if ( V_44 )
F_45 ( V_5 , V_44 ) ;
V_65:
F_46 ( F_4 ( V_5 ) ) ;
F_14 ( V_5 ) ;
return error ;
}
int
F_47 (
T_5 * V_3 ,
T_3 * V_60 ,
T_1 V_4 ,
T_6 V_43 ,
T_6 V_44 ,
T_7 * * V_61 )
{
T_7 * V_5 ;
int error ;
T_8 * V_42 ;
T_4 V_62 ;
ASSERT ( ( V_44 & ( V_75 | V_76 ) ) == 0 ) ;
if ( ! V_4 || F_48 ( V_3 , V_4 ) >= V_3 -> V_77 . V_78 )
return - V_79 ;
V_42 = F_49 ( V_3 , F_48 ( V_3 , V_4 ) ) ;
V_62 = F_34 ( V_3 , V_4 ) ;
V_80:
error = 0 ;
F_25 () ;
V_5 = F_50 ( & V_42 -> V_71 , V_62 ) ;
if ( V_5 ) {
error = F_21 ( V_42 , V_5 , V_4 , V_43 , V_44 ) ;
if ( error )
goto V_81;
} else {
F_24 () ;
F_6 ( V_82 ) ;
error = F_33 ( V_3 , V_42 , V_60 , V_4 , & V_5 ,
V_43 , V_44 ) ;
if ( error )
goto V_81;
}
F_51 ( V_42 ) ;
* V_61 = V_5 ;
if ( F_52 ( V_5 , V_48 ) && V_5 -> V_23 . V_29 != 0 )
F_53 ( V_5 ) ;
return 0 ;
V_81:
if ( error == - V_46 ) {
F_54 ( 1 ) ;
goto V_80;
}
F_51 ( V_42 ) ;
return error ;
}
STATIC int
F_55 (
struct V_1 * V_5 )
{
struct V_27 * V_27 = F_4 ( V_5 ) ;
ASSERT ( F_56 () ) ;
F_17 ( & V_5 -> V_11 ) ;
if ( ! V_5 -> V_12 )
goto V_83;
if ( F_57 ( V_5 , V_48 | V_51 | V_40 ) )
goto V_83;
F_18 ( & V_5 -> V_11 ) ;
if ( F_58 ( V_5 -> V_15 ) )
return - V_84 ;
if ( ! F_29 ( V_27 ) )
return - V_50 ;
return 0 ;
V_83:
F_18 ( & V_5 -> V_11 ) ;
return - V_50 ;
}
STATIC int
F_59 (
struct V_2 * V_3 ,
struct V_41 * V_42 ,
int (* F_60)( struct V_1 * V_5 , int V_43 ,
void * args ) ,
int V_43 ,
void * args ,
int V_85 )
{
T_9 V_86 ;
int V_87 = 0 ;
int V_88 ;
int V_89 ;
int V_90 ;
V_91:
V_89 = 0 ;
V_88 = 0 ;
V_86 = 0 ;
V_90 = 0 ;
do {
struct V_1 * V_92 [ V_93 ] ;
int error = 0 ;
int V_94 ;
F_25 () ;
if ( V_85 == - 1 )
V_90 = F_61 ( & V_42 -> V_71 ,
( void * * ) V_92 , V_86 ,
V_93 ) ;
else
V_90 = F_62 (
& V_42 -> V_71 ,
( void * * ) V_92 , V_86 ,
V_93 , V_85 ) ;
if ( ! V_90 ) {
F_24 () ;
break;
}
for ( V_94 = 0 ; V_94 < V_90 ; V_94 ++ ) {
struct V_1 * V_5 = V_92 [ V_94 ] ;
if ( V_89 || F_55 ( V_5 ) )
V_92 [ V_94 ] = NULL ;
if ( F_48 ( V_3 , V_5 -> V_12 ) != V_42 -> V_95 )
continue;
V_86 = F_34 ( V_3 , V_5 -> V_12 + 1 ) ;
if ( V_86 < F_34 ( V_3 , V_5 -> V_12 ) )
V_89 = 1 ;
}
F_24 () ;
for ( V_94 = 0 ; V_94 < V_90 ; V_94 ++ ) {
if ( ! V_92 [ V_94 ] )
continue;
error = F_60 ( V_92 [ V_94 ] , V_43 , args ) ;
F_63 ( V_92 [ V_94 ] ) ;
if ( error == - V_46 ) {
V_88 ++ ;
continue;
}
if ( error && V_87 != - V_84 )
V_87 = error ;
}
if ( error == - V_84 )
break;
F_64 () ;
} while ( V_90 && ! V_89 );
if ( V_88 ) {
F_54 ( 1 ) ;
goto V_91;
}
return V_87 ;
}
STATIC void
F_65 (
struct V_2 * V_3 )
{
F_25 () ;
if ( F_66 ( & V_3 -> V_96 , V_97 ) )
F_67 ( V_3 -> V_98 ,
& V_3 -> V_99 ,
F_68 ( V_100 * 1000 ) ) ;
F_24 () ;
}
void
F_69 (
struct V_101 * V_102 )
{
struct V_2 * V_3 = F_12 ( F_70 ( V_102 ) ,
struct V_2 , V_99 ) ;
F_71 ( V_3 , NULL ) ;
F_65 ( V_3 ) ;
}
int
F_72 (
struct V_2 * V_3 ,
int (* F_60)( struct V_1 * V_5 , int V_43 ,
void * args ) ,
int V_43 ,
void * args )
{
struct V_41 * V_42 ;
int error = 0 ;
int V_87 = 0 ;
T_10 V_103 ;
V_103 = 0 ;
while ( ( V_42 = F_49 ( V_3 , V_103 ) ) ) {
V_103 = V_42 -> V_95 + 1 ;
error = F_59 ( V_3 , V_42 , F_60 , V_43 , args , - 1 ) ;
F_51 ( V_42 ) ;
if ( error ) {
V_87 = error ;
if ( error == - V_84 )
break;
}
}
return V_87 ;
}
int
F_73 (
struct V_2 * V_3 ,
int (* F_60)( struct V_1 * V_5 , int V_43 ,
void * args ) ,
int V_43 ,
void * args ,
int V_85 )
{
struct V_41 * V_42 ;
int error = 0 ;
int V_87 = 0 ;
T_10 V_103 ;
V_103 = 0 ;
while ( ( V_42 = F_74 ( V_3 , V_103 , V_85 ) ) ) {
V_103 = V_42 -> V_95 + 1 ;
error = F_59 ( V_3 , V_42 , F_60 , V_43 , args , V_85 ) ;
F_51 ( V_42 ) ;
if ( error ) {
V_87 = error ;
if ( error == - V_84 )
break;
}
}
return V_87 ;
}
static void
F_75 (
struct V_2 * V_3 )
{
F_25 () ;
if ( F_66 ( & V_3 -> V_96 , V_104 ) ) {
F_67 ( V_3 -> V_105 , & V_3 -> V_106 ,
F_68 ( V_107 / 6 * 10 ) ) ;
}
F_24 () ;
}
void
F_76 (
struct V_101 * V_102 )
{
struct V_2 * V_3 = F_12 ( F_70 ( V_102 ) ,
struct V_2 , V_106 ) ;
F_77 ( V_3 , V_108 ) ;
F_75 ( V_3 ) ;
}
static void
F_78 (
struct V_41 * V_42 ,
struct V_1 * V_5 )
{
F_79 ( & V_42 -> V_71 ,
F_34 ( V_5 -> V_15 , V_5 -> V_12 ) ,
V_104 ) ;
if ( ! V_42 -> V_109 ) {
F_17 ( & V_5 -> V_15 -> V_110 ) ;
F_79 ( & V_5 -> V_15 -> V_96 ,
F_48 ( V_5 -> V_15 , V_5 -> V_12 ) ,
V_104 ) ;
F_18 ( & V_5 -> V_15 -> V_110 ) ;
F_75 ( V_5 -> V_15 ) ;
F_80 ( V_5 -> V_15 , V_42 -> V_95 ,
- 1 , V_111 ) ;
}
V_42 -> V_109 ++ ;
}
void
F_81 (
T_7 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_15 ;
struct V_41 * V_42 ;
V_42 = F_49 ( V_3 , F_48 ( V_3 , V_5 -> V_12 ) ) ;
F_17 ( & V_42 -> V_52 ) ;
F_17 ( & V_5 -> V_11 ) ;
F_78 ( V_42 , V_5 ) ;
F_82 ( V_5 , V_51 ) ;
F_18 ( & V_5 -> V_11 ) ;
F_18 ( & V_42 -> V_52 ) ;
F_51 ( V_42 ) ;
}
STATIC void
F_83 (
T_8 * V_42 ,
T_7 * V_5 )
{
V_42 -> V_109 -- ;
if ( ! V_42 -> V_109 ) {
F_17 ( & V_5 -> V_15 -> V_110 ) ;
F_84 ( & V_5 -> V_15 -> V_96 ,
F_48 ( V_5 -> V_15 , V_5 -> V_12 ) ,
V_104 ) ;
F_18 ( & V_5 -> V_15 -> V_110 ) ;
F_85 ( V_5 -> V_15 , V_42 -> V_95 ,
- 1 , V_111 ) ;
}
}
STATIC void
F_27 (
T_5 * V_3 ,
T_8 * V_42 ,
T_7 * V_5 )
{
F_84 ( & V_42 -> V_71 ,
F_34 ( V_3 , V_5 -> V_12 ) , V_104 ) ;
F_83 ( V_42 , V_5 ) ;
}
STATIC int
F_86 (
struct V_1 * V_5 ,
int V_43 )
{
ASSERT ( F_56 () ) ;
if ( ! V_5 -> V_12 )
return 1 ;
if ( ( V_43 & V_108 ) &&
F_57 ( V_5 , V_112 | V_40 ) )
return 1 ;
F_17 ( & V_5 -> V_11 ) ;
if ( ! F_57 ( V_5 , V_51 ) ||
F_57 ( V_5 , V_40 ) ) {
F_18 ( & V_5 -> V_11 ) ;
return 1 ;
}
F_82 ( V_5 , V_40 ) ;
F_18 ( & V_5 -> V_11 ) ;
return 0 ;
}
STATIC int
F_87 (
struct V_1 * V_5 ,
struct V_41 * V_42 ,
int V_113 )
{
struct V_114 * V_115 = NULL ;
int error ;
V_91:
error = 0 ;
F_31 ( V_5 , V_116 ) ;
if ( ! F_88 ( V_5 ) ) {
if ( ! ( V_113 & V_117 ) )
goto V_118;
F_89 ( V_5 ) ;
}
if ( F_58 ( V_5 -> V_15 ) ) {
F_90 ( V_5 ) ;
F_91 ( V_5 , false ) ;
goto V_119;
}
if ( F_92 ( V_5 ) ) {
if ( ! ( V_113 & V_117 ) )
goto V_120;
F_90 ( V_5 ) ;
}
if ( F_52 ( V_5 , V_57 ) )
goto V_119;
if ( F_93 ( V_5 ) )
goto V_119;
if ( ! ( V_113 & V_117 ) )
goto V_120;
error = F_94 ( V_5 , & V_115 ) ;
if ( error == - V_46 ) {
F_45 ( V_5 , V_116 ) ;
F_54 ( 2 ) ;
goto V_91;
}
if ( ! error ) {
error = F_95 ( V_115 ) ;
F_96 ( V_115 ) ;
}
F_89 ( V_5 ) ;
V_119:
F_97 ( V_5 ) ;
F_45 ( V_5 , V_116 ) ;
F_6 ( V_121 ) ;
F_17 ( & V_42 -> V_52 ) ;
if ( ! F_98 ( & V_42 -> V_71 ,
F_34 ( V_5 -> V_15 , V_5 -> V_12 ) ) )
ASSERT ( 0 ) ;
F_83 ( V_42 , V_5 ) ;
F_18 ( & V_42 -> V_52 ) ;
F_31 ( V_5 , V_116 ) ;
F_99 ( V_5 ) ;
F_45 ( V_5 , V_116 ) ;
F_14 ( V_5 ) ;
return error ;
V_120:
F_97 ( V_5 ) ;
V_118:
F_32 ( V_5 , V_40 ) ;
F_45 ( V_5 , V_116 ) ;
return 0 ;
}
STATIC int
F_100 (
struct V_2 * V_3 ,
int V_43 ,
int * V_122 )
{
struct V_41 * V_42 ;
int error = 0 ;
int V_87 = 0 ;
T_10 V_103 ;
int V_123 = V_43 & V_108 ;
int V_88 ;
V_91:
V_103 = 0 ;
V_88 = 0 ;
while ( ( V_42 = F_74 ( V_3 , V_103 , V_104 ) ) ) {
unsigned long V_86 = 0 ;
int V_89 = 0 ;
int V_90 = 0 ;
V_103 = V_42 -> V_95 + 1 ;
if ( V_123 ) {
if ( ! F_101 ( & V_42 -> V_124 ) ) {
V_88 ++ ;
F_51 ( V_42 ) ;
continue;
}
V_86 = V_42 -> V_125 ;
} else
F_102 ( & V_42 -> V_124 ) ;
do {
struct V_1 * V_92 [ V_93 ] ;
int V_94 ;
F_25 () ;
V_90 = F_62 (
& V_42 -> V_71 ,
( void * * ) V_92 , V_86 ,
V_93 ,
V_104 ) ;
if ( ! V_90 ) {
V_89 = 1 ;
F_24 () ;
break;
}
for ( V_94 = 0 ; V_94 < V_90 ; V_94 ++ ) {
struct V_1 * V_5 = V_92 [ V_94 ] ;
if ( V_89 || F_86 ( V_5 , V_43 ) )
V_92 [ V_94 ] = NULL ;
if ( F_48 ( V_3 , V_5 -> V_12 ) !=
V_42 -> V_95 )
continue;
V_86 = F_34 ( V_3 , V_5 -> V_12 + 1 ) ;
if ( V_86 < F_34 ( V_3 , V_5 -> V_12 ) )
V_89 = 1 ;
}
F_24 () ;
for ( V_94 = 0 ; V_94 < V_90 ; V_94 ++ ) {
if ( ! V_92 [ V_94 ] )
continue;
error = F_87 ( V_92 [ V_94 ] , V_42 , V_43 ) ;
if ( error && V_87 != - V_84 )
V_87 = error ;
}
* V_122 -= V_93 ;
F_64 () ;
} while ( V_90 && ! V_89 && * V_122 > 0 );
if ( V_123 && ! V_89 )
V_42 -> V_125 = V_86 ;
else
V_42 -> V_125 = 0 ;
F_103 ( & V_42 -> V_124 ) ;
F_51 ( V_42 ) ;
}
if ( V_88 && ( V_43 & V_117 ) && * V_122 > 0 ) {
V_123 = 0 ;
goto V_91;
}
return V_87 ;
}
int
F_77 (
T_5 * V_3 ,
int V_126 )
{
int V_122 = V_127 ;
return F_100 ( V_3 , V_126 , & V_122 ) ;
}
long
F_104 (
struct V_2 * V_3 ,
int V_122 )
{
F_75 ( V_3 ) ;
F_105 ( V_3 -> V_128 ) ;
return F_100 ( V_3 , V_108 | V_117 , & V_122 ) ;
}
int
F_106 (
struct V_2 * V_3 )
{
struct V_41 * V_42 ;
T_10 V_103 = 0 ;
int V_129 = 0 ;
while ( ( V_42 = F_74 ( V_3 , V_103 , V_104 ) ) ) {
V_103 = V_42 -> V_95 + 1 ;
V_129 += V_42 -> V_109 ;
F_51 ( V_42 ) ;
}
return V_129 ;
}
STATIC int
F_107 (
struct V_1 * V_5 ,
struct V_130 * V_131 )
{
if ( ( V_131 -> V_132 & V_133 ) &&
! F_108 ( F_4 ( V_5 ) -> V_134 , V_131 -> V_135 ) )
return 0 ;
if ( ( V_131 -> V_132 & V_136 ) &&
! F_109 ( F_4 ( V_5 ) -> V_137 , V_131 -> V_138 ) )
return 0 ;
if ( ( V_131 -> V_132 & V_139 ) &&
F_110 ( V_5 ) != V_131 -> V_140 )
return 0 ;
return 1 ;
}
STATIC int
F_111 (
struct V_1 * V_5 ,
struct V_130 * V_131 )
{
if ( ( V_131 -> V_132 & V_133 ) &&
F_108 ( F_4 ( V_5 ) -> V_134 , V_131 -> V_135 ) )
return 1 ;
if ( ( V_131 -> V_132 & V_136 ) &&
F_109 ( F_4 ( V_5 ) -> V_137 , V_131 -> V_138 ) )
return 1 ;
if ( ( V_131 -> V_132 & V_139 ) &&
F_110 ( V_5 ) == V_131 -> V_140 )
return 1 ;
return 0 ;
}
STATIC int
F_112 (
struct V_1 * V_5 ,
int V_43 ,
void * args )
{
int V_141 ;
struct V_130 * V_131 = args ;
bool V_142 = true ;
int V_143 ;
ASSERT ( ! V_131 || ( V_131 && V_131 -> V_144 != 0 ) ) ;
if ( ! F_113 ( V_5 , false ) ) {
F_114 ( V_5 ) ;
F_115 ( V_5 ) ;
return 0 ;
}
if ( ! ( V_43 & V_117 ) &&
F_116 ( F_4 ( V_5 ) -> V_145 , V_146 ) )
return 0 ;
if ( V_131 ) {
if ( V_131 -> V_132 & V_147 )
V_143 = F_111 ( V_5 , V_131 ) ;
else
V_143 = F_107 ( V_5 , V_131 ) ;
if ( ! V_143 )
return 0 ;
if ( V_131 -> V_132 & V_148 &&
F_117 ( V_5 ) < V_131 -> V_149 )
return 0 ;
if ( V_131 -> V_144 == V_5 -> V_12 )
V_142 = false ;
}
V_141 = F_118 ( V_5 -> V_15 , V_5 , V_142 ) ;
if ( V_141 == - V_46 && ! ( V_43 & V_117 ) )
V_141 = 0 ;
return V_141 ;
}
int
F_71 (
struct V_2 * V_3 ,
struct V_130 * V_131 )
{
int V_43 = V_108 ;
if ( V_131 && ( V_131 -> V_132 & V_150 ) )
V_43 = V_117 ;
return F_73 ( V_3 , F_112 , V_43 ,
V_131 , V_97 ) ;
}
int
F_119 (
struct V_1 * V_5 )
{
int V_151 = 0 ;
struct V_130 V_131 = { 0 } ;
struct V_152 * V_153 ;
ASSERT ( F_120 ( V_5 , V_75 ) ) ;
V_131 . V_144 = V_5 -> V_12 ;
V_131 . V_132 = V_147 | V_150 ;
if ( F_121 ( V_5 -> V_15 ) ) {
V_153 = F_122 ( V_5 , V_154 ) ;
if ( V_153 && F_123 ( V_153 ) ) {
V_131 . V_135 = F_4 ( V_5 ) -> V_134 ;
V_131 . V_132 |= V_133 ;
V_151 = 1 ;
}
}
if ( F_124 ( V_5 -> V_15 ) ) {
V_153 = F_122 ( V_5 , V_155 ) ;
if ( V_153 && F_123 ( V_153 ) ) {
V_131 . V_138 = F_4 ( V_5 ) -> V_137 ;
V_131 . V_132 |= V_136 ;
V_151 = 1 ;
}
}
if ( V_151 )
F_71 ( V_5 -> V_15 , & V_131 ) ;
return V_151 ;
}
void
F_125 (
T_7 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_15 ;
struct V_41 * V_42 ;
int V_156 ;
V_42 = F_49 ( V_3 , F_48 ( V_3 , V_5 -> V_12 ) ) ;
F_17 ( & V_42 -> V_52 ) ;
F_126 ( V_5 ) ;
V_156 = F_66 ( & V_42 -> V_71 ,
V_97 ) ;
F_79 ( & V_42 -> V_71 ,
F_34 ( V_5 -> V_15 , V_5 -> V_12 ) ,
V_97 ) ;
if ( ! V_156 ) {
F_17 ( & V_5 -> V_15 -> V_110 ) ;
F_79 ( & V_5 -> V_15 -> V_96 ,
F_48 ( V_5 -> V_15 , V_5 -> V_12 ) ,
V_97 ) ;
F_18 ( & V_5 -> V_15 -> V_110 ) ;
F_65 ( V_5 -> V_15 ) ;
F_127 ( V_5 -> V_15 , V_42 -> V_95 ,
- 1 , V_111 ) ;
}
F_18 ( & V_42 -> V_52 ) ;
F_51 ( V_42 ) ;
}
void
F_115 (
T_7 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_15 ;
struct V_41 * V_42 ;
V_42 = F_49 ( V_3 , F_48 ( V_3 , V_5 -> V_12 ) ) ;
F_17 ( & V_42 -> V_52 ) ;
F_128 ( V_5 ) ;
F_84 ( & V_42 -> V_71 ,
F_34 ( V_5 -> V_15 , V_5 -> V_12 ) ,
V_97 ) ;
if ( ! F_66 ( & V_42 -> V_71 , V_97 ) ) {
F_17 ( & V_5 -> V_15 -> V_110 ) ;
F_84 ( & V_5 -> V_15 -> V_96 ,
F_48 ( V_5 -> V_15 , V_5 -> V_12 ) ,
V_97 ) ;
F_18 ( & V_5 -> V_15 -> V_110 ) ;
F_129 ( V_5 -> V_15 , V_42 -> V_95 ,
- 1 , V_111 ) ;
}
F_18 ( & V_42 -> V_52 ) ;
F_51 ( V_42 ) ;
}
