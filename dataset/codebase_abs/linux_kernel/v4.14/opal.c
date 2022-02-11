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
V_30 = F_14 ( F_15 ( V_22 , F_16 ( T_1 ) ) ) ;
memset ( V_30 , 0 , V_22 ) ;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ ) {
V_30 [ V_25 ] . V_31 =
F_8 ( V_27 + ( V_25 * 5 ) + 0 , 2 ) ;
V_30 [ V_25 ] . V_32 =
V_30 [ V_25 ] . V_31 +
F_8 ( V_27 + ( V_25 * 5 ) + 2 , 1 ) ;
V_30 [ V_25 ] . V_33 =
F_8 ( V_27 + ( V_25 * 5 ) + 3 , 2 ) ;
F_9 ( L_13 ,
V_30 [ V_25 ] . V_31 ,
V_30 [ V_25 ] . V_32 ,
V_30 [ V_25 ] . V_33 ) ;
}
return 1 ;
}
static int T_2 F_17 ( void )
{
#ifdef F_2
T_1 V_34 ;
if ( ! ( V_23 & V_24 ) )
return - V_35 ;
V_34 = 0x7000 ;
if ( ! F_18 ( V_36 ) ) {
F_11 ( L_14 ) ;
F_19 (
V_37 ,
0 , V_34 ) ;
V_34 += 128 ;
}
F_19 ( V_38 , 0 , V_34 ) ;
#endif
return 0 ;
}
int F_20 ( enum V_39 V_40 ,
struct V_41 * V_42 )
{
if ( ! V_42 || V_40 >= V_43 ) {
F_21 ( L_15 ,
V_44 , V_40 ) ;
return - V_45 ;
}
return F_22 (
& V_46 [ V_40 ] , V_42 ) ;
}
int F_23 ( enum V_39 V_40 ,
struct V_41 * V_42 )
{
return F_24 (
& V_46 [ V_40 ] , V_42 ) ;
}
static void F_25 ( T_4 V_40 , void * V_47 )
{
F_26 ( & V_46 [ V_40 ] ,
V_40 , V_47 ) ;
}
static void F_27 ( void )
{
T_5 V_48 ;
static struct V_49 V_47 ;
T_6 type ;
V_48 = F_28 ( F_29 ( & V_47 ) , sizeof( V_47 ) ) ;
if ( V_48 == V_50 )
return;
if ( V_48 ) {
F_21 ( L_16 ,
V_44 , V_48 ) ;
return;
}
type = F_30 ( V_47 . V_40 ) ;
if ( type >= V_43 ) {
F_31 ( L_17 , V_44 , type ) ;
return;
}
F_25 ( type , ( void * ) & V_47 ) ;
}
static T_7 F_32 ( int V_51 , void * V_12 )
{
F_27 () ;
return V_52 ;
}
static int T_2 F_33 ( void )
{
int V_48 , V_25 , V_51 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ )
F_34 ( & V_46 [ V_25 ] ) ;
V_51 = F_35 ( F_36 ( V_53 ) ) ;
if ( ! V_51 ) {
F_37 ( L_18 ,
V_44 , V_51 ) ;
return V_51 ;
}
V_48 = F_38 ( V_51 , F_32 ,
V_54 , L_19 , NULL ) ;
if ( V_48 ) {
F_37 ( L_20 ,
V_44 , V_48 ) ;
return V_48 ;
}
return 0 ;
}
int F_39 ( T_4 V_55 , char * V_56 , int V_57 )
{
T_5 V_58 ;
T_8 V_59 , V_60 ;
if ( ! V_19 . V_21 )
return - V_35 ;
F_40 ( & V_59 ) ;
if ( ( F_41 ( V_59 ) & V_61 ) == 0 )
return 0 ;
V_60 = F_42 ( V_57 ) ;
V_58 = F_43 ( V_55 , & V_60 , V_56 ) ;
if ( V_58 == V_62 )
return F_41 ( V_60 ) ;
return 0 ;
}
int F_44 ( T_4 V_55 , const char * V_12 , int V_63 )
{
int V_64 = 0 ;
T_8 V_65 ;
T_5 V_60 , V_58 ;
unsigned long V_66 ;
T_8 V_59 ;
if ( ! V_19 . V_21 )
return - V_35 ;
F_45 ( & V_67 , V_66 ) ;
V_58 = F_46 ( V_55 , & V_65 ) ;
V_60 = F_41 ( V_65 ) ;
if ( V_58 || V_60 < V_63 ) {
F_47 ( & V_67 , V_66 ) ;
if ( V_58 )
return V_63 ;
F_40 ( NULL ) ;
return - V_68 ;
}
V_58 = V_69 ;
while( V_63 > 0 && ( V_58 == V_69 ||
V_58 == V_70 || V_58 == V_62 ) ) {
V_65 = F_42 ( V_63 ) ;
V_58 = F_48 ( V_55 , & V_65 , V_12 ) ;
V_60 = F_41 ( V_65 ) ;
if ( V_58 != V_62 && V_58 != V_69 &&
V_58 != V_70 ) {
V_64 = V_63 ;
break;
}
if ( V_58 == V_62 ) {
V_63 -= V_60 ;
V_12 += V_60 ;
V_64 += V_60 ;
}
do
F_40 ( & V_59 ) ;
while( V_58 == V_62 &&
( F_41 ( V_59 ) & V_71 ) );
}
F_47 ( & V_67 , V_66 ) ;
return V_64 ;
}
static int F_49 ( struct V_72 * V_73 ,
struct V_74 * V_59 )
{
int V_75 = 0 ;
if ( ! ( V_73 -> V_76 & V_77 ) ) {
F_37 ( L_21 ) ;
V_75 = 0 ;
} else if ( V_59 -> V_78 == V_79 ) {
V_75 = 1 ;
} else if ( V_59 -> V_80 == V_81 ) {
F_37 ( L_22 ) ;
V_75 = 0 ;
}
if ( ! V_75 && V_59 -> V_80 == V_82 ) {
if ( ( F_50 ( V_73 ) ) ) {
F_51 ( V_83 , V_73 , V_84 , V_73 -> V_85 ) ;
V_75 = 1 ;
} else if ( F_52 () ) {
V_75 = 0 ;
} else {
F_53 ( L_23 , V_73 , V_83 ) ;
V_75 = 1 ;
}
}
return V_75 ;
}
void F_54 ( struct V_72 * V_73 , const char * V_47 )
{
F_55 () ;
F_56 ( 1 ) ;
F_57 ( L_24 , V_47 ) ;
if ( V_73 )
F_58 ( V_73 ) ;
F_59 () ;
F_60 () ;
F_61 ( V_86 ) ;
F_56 ( 0 ) ;
F_62 () ;
F_63 () ;
if ( F_64 ( V_87 , V_47 )
== V_88 ) {
F_57 ( L_25 ,
V_87 , V_47 ) ;
}
V_89 . V_90 ( NULL ) ;
}
int F_65 ( struct V_72 * V_73 )
{
struct V_74 V_59 ;
if ( ! F_66 ( & V_59 , V_91 ) )
return 0 ;
if ( V_59 . V_92 != V_93 ) {
F_37 ( L_26 ,
V_59 . V_92 ) ;
return 0 ;
}
F_67 ( & V_59 , F_50 ( V_73 ) ) ;
if ( F_49 ( V_73 , & V_59 ) )
return 1 ;
F_54 ( V_73 , L_27 ) ;
}
int F_68 ( struct V_72 * V_73 )
{
T_5 V_58 ;
V_58 = F_69 () ;
if ( V_58 == V_62 ) {
V_94 -> V_95 = 1 ;
return 1 ;
}
return 0 ;
}
int F_70 ( struct V_72 * V_73 )
{
T_5 V_58 ;
T_8 V_59 = 0 ;
if ( ! V_94 -> V_95 )
return 0 ;
V_94 -> V_95 = 0 ;
V_58 = F_40 ( & V_59 ) ;
if ( V_58 == V_62 && V_59 )
F_71 ( F_41 ( V_59 ) ) ;
return 1 ;
}
static T_9 F_72 ( T_9 V_85 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ )
if ( ( V_85 >= V_30 [ V_25 ] . V_31 ) &&
( V_85 < V_30 [ V_25 ] . V_32 ) )
return V_30 [ V_25 ] . V_33 ;
return 0 ;
}
bool F_73 ( struct V_72 * V_73 )
{
T_9 V_33 = 0 ;
if ( ! V_19 . V_20 || ! V_19 . V_22 )
goto V_96;
if ( ( V_73 -> V_85 >= V_19 . V_20 ) &&
( V_73 -> V_85 < ( V_19 . V_20 + V_19 . V_22 ) ) )
V_33 = F_72 ( V_73 -> V_85 ) ;
if ( V_33 )
V_73 -> V_85 = V_33 ;
V_96:
return ! ! V_33 ;
}
static int F_74 ( void )
{
V_97 = F_75 ( L_28 , V_98 ) ;
if ( ! V_97 ) {
F_76 ( L_29 ) ;
return - V_99 ;
}
return 0 ;
}
static T_10 F_77 ( struct V_100 * V_101 , struct V_102 * V_103 ,
struct V_104 * V_105 ,
char * V_56 , T_11 V_106 , T_12 V_57 )
{
return F_78 ( V_56 , V_57 , & V_106 , V_105 -> V_107 ,
V_105 -> V_22 ) ;
}
static void F_79 ( void )
{
const T_8 * V_108 ;
unsigned int V_22 ;
struct V_109 * V_110 ;
int V_58 ;
V_110 = F_80 ( L_30 ) ;
if ( ! V_110 )
return;
V_108 = F_81 ( V_110 , L_31 , & V_22 ) ;
if ( ! V_108 || V_22 != 2 * sizeof( T_8 ) )
return;
V_111 . V_107 = F_14 ( F_41 ( V_108 [ 0 ] ) ) ;
V_111 . V_22 = F_41 ( V_108 [ 1 ] ) ;
V_58 = F_82 ( V_97 , & V_111 ) ;
if ( V_58 )
F_76 ( L_32 , V_58 ) ;
}
static T_10 F_83 ( struct V_100 * V_101 , struct V_102 * V_103 ,
struct V_104 * V_105 , char * V_56 ,
T_11 V_106 , T_12 V_57 )
{
return F_78 ( V_56 , V_57 , & V_106 , V_105 -> V_107 ,
V_105 -> V_22 ) ;
}
static void F_84 ( void )
{
struct V_104 * V_112 ;
struct V_109 * V_113 ;
struct V_114 * V_27 ;
struct V_102 * V_103 ;
T_1 V_115 [ 2 ] ;
int V_58 ;
V_113 = F_80 ( L_33 ) ;
if ( ! V_113 )
return;
V_103 = F_75 ( L_34 , V_97 ) ;
if ( ! V_103 ) {
F_76 ( L_35 ) ;
return;
}
F_85 (np, prop) {
if ( ! strcmp ( V_27 -> V_116 , L_36 ) || ! strcmp ( V_27 -> V_116 , L_37 ) )
continue;
if ( F_86 ( V_113 , V_27 -> V_116 , & V_115 [ 0 ] , 2 ) )
continue;
V_112 = F_87 ( sizeof( * V_112 ) , V_117 ) ;
if ( V_112 == NULL ) {
F_76 ( L_38 ) ;
continue;
}
F_88 ( V_112 ) ;
V_112 -> V_112 . V_116 = F_89 ( V_27 -> V_116 , V_117 ) ;
V_112 -> V_112 . V_118 = 0400 ;
V_112 -> V_119 = F_83 ;
V_112 -> V_107 = F_14 ( V_115 [ 0 ] ) ;
V_112 -> V_22 = V_115 [ 1 ] ;
if ( V_112 -> V_112 . V_116 == NULL ) {
F_76 ( L_39 ) ;
F_90 ( V_112 ) ;
continue;
}
V_58 = F_82 ( V_103 , V_112 ) ;
if ( V_58 ) {
F_76 ( L_40 ,
V_58 , V_27 -> V_116 ) ;
F_90 ( V_112 -> V_112 . V_116 ) ;
F_90 ( V_112 ) ;
}
}
F_91 ( V_113 ) ;
}
static void T_2 F_92 ( void )
{
void * V_120 ;
T_9 V_22 ;
int V_58 ;
if ( ! F_18 ( V_121 ) )
return;
V_120 = F_93 () ;
if ( V_120 == NULL )
return;
V_22 = F_94 () ;
if ( V_22 == 0 )
return;
V_58 = F_95 ( V_122 ,
F_29 ( V_120 ) , V_22 ) ;
if ( V_58 && V_58 != V_88 )
F_76 ( L_41
L_42 , V_58 ) ;
}
static void F_96 ( const char * V_123 )
{
struct V_109 * V_113 ;
F_97 (np, NULL, compatible)
F_98 ( V_113 , NULL , NULL ) ;
}
static void T_2 F_99 ( void )
{
struct V_109 * V_113 ;
V_113 = F_100 ( NULL , NULL , V_124 ) ;
if ( V_113 )
F_98 ( V_113 , NULL , NULL ) ;
}
static int F_101 ( void * V_125 )
{
unsigned long V_126 = F_102 ( V_127 ) + 1 ;
T_8 V_128 ;
F_103 () ;
do {
F_104 () ;
F_40 ( & V_128 ) ;
F_71 ( F_41 ( V_128 ) ) ;
F_105 ( V_126 ) ;
} while ( ! F_106 () );
return 0 ;
}
void F_107 ( void )
{
if ( V_129 )
F_108 ( V_129 ) ;
}
static void F_109 ( void )
{
if ( F_110 ( V_130 , L_43 ,
& V_127 ) != 0 )
V_127 = 0 ;
if ( V_127 )
V_129 = F_111 ( F_101 , NULL , L_44 ) ;
}
static int T_2 F_112 ( void )
{
struct V_109 * V_113 , * V_131 , * V_132 ;
int V_58 ;
V_130 = F_80 ( L_45 ) ;
if ( ! V_130 ) {
F_76 ( L_46 ) ;
return - V_35 ;
}
V_131 = F_80 ( L_47 ) ;
if ( V_131 ) {
F_113 (consoles, np) {
if ( strcmp ( V_113 -> V_116 , L_48 ) )
continue;
F_98 ( V_113 , NULL , NULL ) ;
}
F_91 ( V_131 ) ;
}
F_33 () ;
F_114 () ;
F_115 () ;
F_116 () ;
F_96 ( L_49 ) ;
F_109 () ;
F_99 () ;
V_132 = F_80 ( L_50 ) ;
if ( V_132 ) {
F_98 ( V_132 , L_51 , NULL ) ;
F_91 ( V_132 ) ;
}
F_117 () ;
V_58 = F_74 () ;
if ( V_58 == 0 ) {
F_79 () ;
F_92 () ;
V_58 = F_118 () ;
F_119 () ;
F_120 () ;
F_121 () ;
F_122 () ;
}
F_84 () ;
F_96 ( L_52 ) ;
F_96 ( L_53 ) ;
F_96 ( L_54 ) ;
F_96 ( L_55 ) ;
F_123 () ;
F_124 () ;
F_125 () ;
F_126 () ;
return 0 ;
}
void F_127 ( void )
{
long V_58 = V_69 ;
F_128 () ;
while ( V_58 == V_69 || V_58 == V_70 ) {
V_58 = F_129 () ;
if ( V_58 == V_69 )
F_40 ( NULL ) ;
else
F_130 ( 10 ) ;
}
if ( F_18 ( V_133 ) )
F_131 ( V_122 ) ;
}
struct V_134 * F_132 ( void * V_135 ,
unsigned long V_136 )
{
struct V_134 * V_137 , * V_138 = NULL ;
unsigned long V_25 = 0 ;
V_137 = F_87 ( V_139 , V_117 ) ;
if ( ! V_137 )
goto V_140;
V_138 = V_137 ;
while ( V_136 > 0 ) {
T_9 V_12 = F_133 ( V_135 ) << V_141 ;
T_9 V_142 = F_134 ( V_136 , V_139 ) ;
V_137 -> V_21 [ V_25 ] . V_12 = F_42 ( V_12 ) ;
V_137 -> V_21 [ V_25 ] . V_142 = F_42 ( V_142 ) ;
V_25 ++ ;
if ( V_25 >= V_143 ) {
struct V_134 * V_144 ;
V_144 = F_87 ( V_139 , V_117 ) ;
if ( ! V_144 )
goto V_140;
V_137 -> V_142 = F_42 (
V_25 * sizeof( struct V_145 ) + 16 ) ;
V_25 = 0 ;
V_137 -> V_144 = F_42 ( F_29 ( V_144 ) ) ;
V_137 = V_144 ;
}
V_135 += V_142 ;
V_136 -= V_142 ;
}
V_137 -> V_142 = F_42 ( V_25 * sizeof( struct V_145 ) + 16 ) ;
return V_138 ;
V_140:
F_37 ( L_56 , V_44 ) ;
F_135 ( V_138 ) ;
return NULL ;
}
void F_135 ( struct V_134 * V_137 )
{
while ( V_137 ) {
T_9 V_144 = F_41 ( V_137 -> V_144 ) ;
F_90 ( V_137 ) ;
if ( V_144 )
V_137 = F_14 ( V_144 ) ;
else
V_137 = NULL ;
}
}
int F_136 ( int V_58 )
{
switch ( V_58 ) {
case V_62 : return 0 ;
case V_146 : return - V_45 ;
case V_147 : return - V_148 ;
case V_70 : return - V_149 ;
case V_150 : return - V_99 ;
case V_151 : return - V_152 ;
case V_88 : return - V_153 ;
case V_154 : return - V_153 ;
case V_155 : return - V_153 ;
case V_156 : return - V_157 ;
default:
F_37 ( L_57 , V_44 , V_58 ) ;
return - V_153 ;
}
}
void F_137 ( unsigned long V_158 )
{
int V_58 ;
if ( F_138 ( V_24 ) ) {
V_58 = F_139 ( - 1UL , V_158 ) ;
if ( V_58 != V_62 && V_58 != V_88 )
F_76 ( L_58 , V_44 ) ;
}
}
