void F_1 ( void )
{
T_1 V_1 = 0 ;
#ifdef F_2
V_1 |= V_2 ;
#else
V_1 |= V_3 ;
#endif
if ( F_3 ( V_4 ) ) {
V_1 |= V_5 ;
if ( F_4 () )
V_1 |= V_6 ;
}
F_5 ( V_1 ) ;
if ( V_7 -> V_8 )
V_7 -> V_8 () ;
}
int T_2 F_6 ( unsigned long V_9 ,
const char * V_10 , int V_11 , void * V_12 )
{
const void * V_13 , * V_14 , * V_15 ;
int V_16 , V_17 , V_18 ;
if ( V_11 != 1 || strcmp ( V_10 , L_1 ) != 0 )
return 0 ;
V_13 = F_7 ( V_9 , L_2 , & V_16 ) ;
V_14 = F_7 ( V_9 , L_3 , & V_17 ) ;
V_15 = F_7 ( V_9 , L_4 , & V_18 ) ;
if ( ! V_13 || ! V_14 || ! V_15 )
return 1 ;
V_19 . V_20 = F_8 ( V_13 , V_16 / 4 ) ;
V_19 . V_21 = F_8 ( V_14 , V_17 / 4 ) ;
V_19 . V_22 = F_8 ( V_15 , V_18 / 4 ) ;
F_9 ( L_5 ,
V_19 . V_20 , V_13 , V_16 ) ;
F_9 ( L_6 ,
V_19 . V_21 , V_14 , V_17 ) ;
F_9 ( L_7 ,
V_19 . V_22 , V_15 , V_18 ) ;
if ( F_10 ( V_9 , L_8 ) ) {
V_23 |= V_24 ;
F_11 ( L_9 ) ;
} else {
F_12 ( L_10 ) ;
}
return 1 ;
}
int T_2 F_13 ( unsigned long V_9 ,
const char * V_10 , int V_11 , void * V_12 )
{
int V_25 , V_26 , V_22 ;
const T_3 * V_27 ;
if ( V_11 != 1 || strcmp ( V_10 , L_1 ) != 0 )
return 0 ;
V_27 = F_7 ( V_9 , L_11 , & V_26 ) ;
if ( ! V_27 )
return 1 ;
F_9 ( L_12 ) ;
V_28 = V_26 / ( sizeof( * V_27 ) * 5 ) ;
if ( ! V_28 )
return 1 ;
V_22 = V_28 *
sizeof( struct V_29 ) ;
V_30 = F_14 ( F_15 ( V_22 , F_16 ( T_1 ) ,
V_31 ) ) ;
memset ( V_30 , 0 , V_22 ) ;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ ) {
V_30 [ V_25 ] . V_32 =
F_8 ( V_27 + ( V_25 * 5 ) + 0 , 2 ) ;
V_30 [ V_25 ] . V_33 =
V_30 [ V_25 ] . V_32 +
F_8 ( V_27 + ( V_25 * 5 ) + 2 , 1 ) ;
V_30 [ V_25 ] . V_34 =
F_8 ( V_27 + ( V_25 * 5 ) + 3 , 2 ) ;
F_9 ( L_13 ,
V_30 [ V_25 ] . V_32 ,
V_30 [ V_25 ] . V_33 ,
V_30 [ V_25 ] . V_34 ) ;
}
return 1 ;
}
static int T_2 F_17 ( void )
{
#ifdef F_2
T_1 V_35 ;
if ( ! ( V_23 & V_24 ) )
return - V_36 ;
V_35 = 0x7000 ;
if ( ! F_18 ( V_37 ) ) {
F_11 ( L_14 ) ;
F_19 (
V_38 ,
0 , V_35 ) ;
V_35 += 128 ;
}
F_19 ( V_39 , 0 , V_35 ) ;
#endif
return 0 ;
}
int F_20 ( enum V_40 V_41 ,
struct V_42 * V_43 )
{
if ( ! V_43 || V_41 >= V_44 ) {
F_21 ( L_15 ,
V_45 , V_41 ) ;
return - V_46 ;
}
return F_22 (
& V_47 [ V_41 ] , V_43 ) ;
}
int F_23 ( enum V_40 V_41 ,
struct V_42 * V_43 )
{
return F_24 (
& V_47 [ V_41 ] , V_43 ) ;
}
static void F_25 ( T_4 V_41 , void * V_48 )
{
F_26 ( & V_47 [ V_41 ] ,
V_41 , V_48 ) ;
}
static void F_27 ( void )
{
T_5 V_49 ;
static struct V_50 V_48 ;
T_6 type ;
V_49 = F_28 ( F_29 ( & V_48 ) , sizeof( V_48 ) ) ;
if ( V_49 == V_51 )
return;
if ( V_49 ) {
F_21 ( L_16 ,
V_45 , V_49 ) ;
return;
}
type = F_30 ( V_48 . V_41 ) ;
if ( type >= V_44 ) {
F_31 ( L_17 , V_45 , type ) ;
return;
}
F_25 ( type , ( void * ) & V_48 ) ;
}
static T_7 F_32 ( int V_52 , void * V_12 )
{
F_27 () ;
return V_53 ;
}
static int T_2 F_33 ( void )
{
int V_49 , V_25 , V_52 ;
for ( V_25 = 0 ; V_25 < V_44 ; V_25 ++ )
F_34 ( & V_47 [ V_25 ] ) ;
V_52 = F_35 ( F_36 ( V_54 ) ) ;
if ( ! V_52 ) {
F_37 ( L_18 ,
V_45 , V_52 ) ;
return V_52 ;
}
V_49 = F_38 ( V_52 , F_32 ,
V_55 , L_19 , NULL ) ;
if ( V_49 ) {
F_37 ( L_20 ,
V_45 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
int F_39 ( T_4 V_56 , char * V_57 , int V_58 )
{
T_5 V_59 ;
T_8 V_60 , V_61 ;
if ( ! V_19 . V_21 )
return - V_36 ;
F_40 ( & V_60 ) ;
if ( ( F_41 ( V_60 ) & V_62 ) == 0 )
return 0 ;
V_61 = F_42 ( V_58 ) ;
V_59 = F_43 ( V_56 , & V_61 , V_57 ) ;
if ( V_59 == V_63 )
return F_41 ( V_61 ) ;
return 0 ;
}
int F_44 ( T_4 V_56 , const char * V_12 , int V_64 )
{
int V_65 = 0 ;
T_8 V_66 ;
T_5 V_61 , V_59 ;
unsigned long V_67 ;
T_8 V_60 ;
if ( ! V_19 . V_21 )
return - V_36 ;
F_45 ( & V_68 , V_67 ) ;
V_59 = F_46 ( V_56 , & V_66 ) ;
V_61 = F_41 ( V_66 ) ;
if ( V_59 || V_61 < V_64 ) {
F_47 ( & V_68 , V_67 ) ;
if ( V_59 )
return V_64 ;
F_40 ( NULL ) ;
return - V_69 ;
}
V_59 = V_70 ;
while( V_64 > 0 && ( V_59 == V_70 ||
V_59 == V_71 || V_59 == V_63 ) ) {
V_66 = F_42 ( V_64 ) ;
V_59 = F_48 ( V_56 , & V_66 , V_12 ) ;
V_61 = F_41 ( V_66 ) ;
if ( V_59 != V_63 && V_59 != V_70 &&
V_59 != V_71 ) {
V_65 = V_64 ;
break;
}
if ( V_59 == V_63 ) {
V_64 -= V_61 ;
V_12 += V_61 ;
V_65 += V_61 ;
}
do
F_40 ( & V_60 ) ;
while( V_59 == V_63 &&
( F_41 ( V_60 ) & V_72 ) );
}
F_47 ( & V_68 , V_67 ) ;
return V_65 ;
}
static int F_49 ( struct V_73 * V_74 ,
struct V_75 * V_60 )
{
int V_76 = 0 ;
if ( ! ( V_74 -> V_77 & V_78 ) ) {
F_37 ( L_21 ) ;
V_76 = 0 ;
} else if ( V_60 -> V_79 == V_80 ) {
V_76 = 1 ;
} else if ( V_60 -> V_81 == V_82 ) {
F_37 ( L_22 ) ;
V_76 = 0 ;
} else if ( ( V_60 -> V_81 == V_83 ) &&
( F_50 ( V_74 ) && ! F_51 ( V_84 ) ) ) {
F_52 ( V_85 , V_74 , V_86 , V_74 -> V_87 ) ;
V_76 = 1 ;
}
return V_76 ;
}
int F_53 ( struct V_73 * V_74 )
{
struct V_75 V_60 ;
int V_49 ;
if ( ! F_54 ( & V_60 , V_88 ) )
return 0 ;
if ( V_60 . V_89 != V_90 ) {
F_37 ( L_23 ,
V_60 . V_89 ) ;
return 0 ;
}
F_55 ( & V_60 , F_50 ( V_74 ) ) ;
if ( F_49 ( V_74 , & V_60 ) )
return 1 ;
V_49 = F_56 ( V_91 ,
L_24 ) ;
if ( V_49 == V_92 ) {
F_57 ( L_25 ,
V_91 ) ;
}
F_12 ( L_26 ) ;
return 0 ;
}
int F_58 ( struct V_73 * V_74 )
{
T_5 V_59 ;
V_59 = F_59 () ;
if ( V_59 == V_63 ) {
V_93 -> V_94 = 1 ;
return 1 ;
}
return 0 ;
}
int F_60 ( struct V_73 * V_74 )
{
T_5 V_59 ;
T_8 V_60 = 0 ;
if ( ! V_93 -> V_94 )
return 0 ;
V_93 -> V_94 = 0 ;
V_59 = F_40 ( & V_60 ) ;
if ( V_59 == V_63 && V_60 )
F_61 ( F_41 ( V_60 ) ) ;
return 1 ;
}
static T_9 F_62 ( T_9 V_87 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ )
if ( ( V_87 >= V_30 [ V_25 ] . V_32 ) &&
( V_87 < V_30 [ V_25 ] . V_33 ) )
return V_30 [ V_25 ] . V_34 ;
return 0 ;
}
bool F_63 ( struct V_73 * V_74 )
{
T_9 V_34 = 0 ;
if ( ! V_19 . V_20 || ! V_19 . V_22 )
goto V_95;
if ( ( V_74 -> V_87 >= V_19 . V_20 ) &&
( V_74 -> V_87 < ( V_19 . V_20 + V_19 . V_22 ) ) )
V_34 = F_62 ( V_74 -> V_87 ) ;
if ( V_34 )
V_74 -> V_87 = V_34 ;
V_95:
return ! ! V_34 ;
}
static int F_64 ( void )
{
V_96 = F_65 ( L_27 , V_97 ) ;
if ( ! V_96 ) {
F_66 ( L_28 ) ;
return - V_98 ;
}
return 0 ;
}
static T_10 F_67 ( struct V_99 * V_100 , struct V_101 * V_102 ,
struct V_103 * V_104 ,
char * V_57 , T_11 V_105 , T_12 V_58 )
{
return F_68 ( V_57 , V_58 , & V_105 , V_104 -> V_106 ,
V_104 -> V_22 ) ;
}
static void F_69 ( void )
{
const T_8 * V_107 ;
unsigned int V_22 ;
struct V_108 * V_109 ;
int V_59 ;
V_109 = F_70 ( L_29 ) ;
if ( ! V_109 )
return;
V_107 = F_71 ( V_109 , L_30 , & V_22 ) ;
if ( ! V_107 || V_22 != 2 * sizeof( T_8 ) )
return;
V_110 . V_106 = F_14 ( F_41 ( V_107 [ 0 ] ) ) ;
V_110 . V_22 = F_41 ( V_107 [ 1 ] ) ;
V_59 = F_72 ( V_96 , & V_110 ) ;
if ( V_59 )
F_66 ( L_31 , V_59 ) ;
}
static T_10 F_73 ( struct V_99 * V_100 , struct V_101 * V_102 ,
struct V_103 * V_104 , char * V_57 ,
T_11 V_105 , T_12 V_58 )
{
return F_68 ( V_57 , V_58 , & V_105 , V_104 -> V_106 ,
V_104 -> V_22 ) ;
}
static void F_74 ( void )
{
struct V_103 * V_111 ;
struct V_108 * V_112 ;
struct V_113 * V_27 ;
struct V_101 * V_102 ;
T_1 V_114 [ 2 ] ;
int V_59 ;
V_112 = F_70 ( L_32 ) ;
if ( ! V_112 )
return;
V_102 = F_65 ( L_33 , V_96 ) ;
if ( ! V_102 ) {
F_66 ( L_34 ) ;
return;
}
F_75 (np, prop) {
if ( ! strcmp ( V_27 -> V_115 , L_35 ) || ! strcmp ( V_27 -> V_115 , L_36 ) )
continue;
if ( F_76 ( V_112 , V_27 -> V_115 , & V_114 [ 0 ] , 2 ) )
continue;
V_111 = F_77 ( sizeof( * V_111 ) , V_116 ) ;
if ( V_111 == NULL ) {
F_66 ( L_37 ) ;
continue;
}
F_78 ( V_111 ) ;
V_111 -> V_111 . V_115 = F_79 ( V_27 -> V_115 , V_116 ) ;
V_111 -> V_111 . V_117 = 0400 ;
V_111 -> V_118 = F_73 ;
V_111 -> V_106 = F_14 ( V_114 [ 0 ] ) ;
V_111 -> V_22 = V_114 [ 1 ] ;
if ( V_111 -> V_111 . V_115 == NULL ) {
F_66 ( L_38 ) ;
F_80 ( V_111 ) ;
continue;
}
V_59 = F_72 ( V_102 , V_111 ) ;
if ( V_59 ) {
F_66 ( L_39 ,
V_59 , V_27 -> V_115 ) ;
F_80 ( V_111 -> V_111 . V_115 ) ;
F_80 ( V_111 ) ;
}
}
F_81 ( V_112 ) ;
}
static void T_2 F_82 ( void )
{
void * V_119 ;
T_9 V_22 ;
int V_59 ;
if ( ! F_18 ( V_120 ) )
return;
V_119 = F_83 () ;
if ( V_119 == NULL )
return;
V_22 = F_84 () ;
if ( V_22 == 0 )
return;
V_59 = F_85 ( V_121 ,
F_29 ( V_119 ) , V_22 ) ;
if ( V_59 && V_59 != V_92 )
F_66 ( L_40
L_41 , V_59 ) ;
}
static void F_86 ( const char * V_122 )
{
struct V_108 * V_112 ;
F_87 (np, NULL, compatible)
F_88 ( V_112 , NULL , NULL ) ;
}
static int F_89 ( void * V_123 )
{
unsigned long V_124 = F_90 ( V_125 ) + 1 ;
T_8 V_126 ;
F_91 () ;
do {
F_92 () ;
F_40 ( & V_126 ) ;
F_61 ( F_41 ( V_126 ) ) ;
F_93 ( V_124 ) ;
} while ( ! F_94 () );
return 0 ;
}
void F_95 ( void )
{
if ( V_127 )
F_96 ( V_127 ) ;
}
static void F_97 ( void )
{
if ( F_98 ( V_128 , L_42 ,
& V_125 ) != 0 )
V_125 = 0 ;
if ( V_125 )
V_127 = F_99 ( F_89 , NULL , L_43 ) ;
}
static int T_2 F_100 ( void )
{
struct V_108 * V_112 , * V_129 , * V_130 ;
int V_59 ;
V_128 = F_70 ( L_44 ) ;
if ( ! V_128 ) {
F_66 ( L_45 ) ;
return - V_36 ;
}
V_129 = F_70 ( L_46 ) ;
if ( V_129 ) {
F_101 (consoles, np) {
if ( strcmp ( V_112 -> V_115 , L_47 ) )
continue;
F_88 ( V_112 , NULL , NULL ) ;
}
F_81 ( V_129 ) ;
}
F_33 () ;
F_102 () ;
F_103 () ;
F_104 () ;
F_86 ( L_48 ) ;
F_97 () ;
V_130 = F_70 ( L_49 ) ;
if ( V_130 ) {
F_88 ( V_130 , L_50 , NULL ) ;
F_81 ( V_130 ) ;
}
F_105 () ;
V_59 = F_64 () ;
if ( V_59 == 0 ) {
F_69 () ;
F_82 () ;
V_59 = F_106 () ;
F_107 () ;
F_108 () ;
F_109 () ;
F_110 () ;
}
F_74 () ;
F_86 ( L_51 ) ;
F_86 ( L_52 ) ;
F_86 ( L_53 ) ;
F_86 ( L_54 ) ;
F_111 () ;
return 0 ;
}
void F_112 ( void )
{
long V_59 = V_70 ;
F_113 () ;
while ( V_59 == V_70 || V_59 == V_71 ) {
V_59 = F_114 () ;
if ( V_59 == V_70 )
F_40 ( NULL ) ;
else
F_115 ( 10 ) ;
}
if ( F_18 ( V_131 ) )
F_116 ( V_121 ) ;
}
struct V_132 * F_117 ( void * V_133 ,
unsigned long V_134 )
{
struct V_132 * V_135 , * V_136 = NULL ;
unsigned long V_25 = 0 ;
V_135 = F_77 ( V_137 , V_116 ) ;
if ( ! V_135 )
goto V_138;
V_136 = V_135 ;
while ( V_134 > 0 ) {
T_9 V_12 = F_118 ( V_133 ) << V_139 ;
T_9 V_140 = F_119 ( V_134 , V_137 ) ;
V_135 -> V_21 [ V_25 ] . V_12 = F_42 ( V_12 ) ;
V_135 -> V_21 [ V_25 ] . V_140 = F_42 ( V_140 ) ;
V_25 ++ ;
if ( V_25 >= V_141 ) {
struct V_132 * V_142 ;
V_142 = F_77 ( V_137 , V_116 ) ;
if ( ! V_142 )
goto V_138;
V_135 -> V_140 = F_42 (
V_25 * sizeof( struct V_143 ) + 16 ) ;
V_25 = 0 ;
V_135 -> V_142 = F_42 ( F_29 ( V_142 ) ) ;
V_135 = V_142 ;
}
V_133 += V_140 ;
V_134 -= V_140 ;
}
V_135 -> V_140 = F_42 ( V_25 * sizeof( struct V_143 ) + 16 ) ;
return V_136 ;
V_138:
F_37 ( L_55 , V_45 ) ;
F_120 ( V_136 ) ;
return NULL ;
}
void F_120 ( struct V_132 * V_135 )
{
while ( V_135 ) {
T_9 V_142 = F_41 ( V_135 -> V_142 ) ;
F_80 ( V_135 ) ;
if ( V_142 )
V_135 = F_14 ( V_142 ) ;
else
V_135 = NULL ;
}
}
int F_121 ( int V_59 )
{
switch ( V_59 ) {
case V_63 : return 0 ;
case V_144 : return - V_46 ;
case V_145 : return - V_146 ;
case V_71 : return - V_147 ;
case V_148 : return - V_98 ;
case V_149 : return - V_150 ;
case V_92 : return - V_151 ;
case V_152 : return - V_151 ;
case V_153 : return - V_151 ;
default:
F_37 ( L_56 , V_45 , V_59 ) ;
return - V_151 ;
}
}
void F_122 ( unsigned long V_154 )
{
int V_59 ;
if ( F_123 ( V_24 ) ) {
V_59 = F_124 ( - 1UL , V_154 ) ;
if ( V_59 != V_63 && V_59 != V_92 )
F_66 ( L_57 , V_45 ) ;
}
}
