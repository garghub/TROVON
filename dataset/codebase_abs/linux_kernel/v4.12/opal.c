void F_1 ( void )
{
#ifdef F_2
F_3 ( V_1 ) ;
#else
F_3 ( V_2 ) ;
#endif
if ( V_3 -> V_4 )
V_3 -> V_4 () ;
}
int T_1 F_4 ( unsigned long V_5 ,
const char * V_6 , int V_7 , void * V_8 )
{
const void * V_9 , * V_10 , * V_11 ;
int V_12 , V_13 , V_14 ;
if ( V_7 != 1 || strcmp ( V_6 , L_1 ) != 0 )
return 0 ;
V_9 = F_5 ( V_5 , L_2 , & V_12 ) ;
V_10 = F_5 ( V_5 , L_3 , & V_13 ) ;
V_11 = F_5 ( V_5 , L_4 , & V_14 ) ;
if ( ! V_9 || ! V_10 || ! V_11 )
return 1 ;
V_15 . V_16 = F_6 ( V_9 , V_12 / 4 ) ;
V_15 . V_17 = F_6 ( V_10 , V_13 / 4 ) ;
V_15 . V_18 = F_6 ( V_11 , V_14 / 4 ) ;
F_7 ( L_5 ,
V_15 . V_16 , V_9 , V_12 ) ;
F_7 ( L_6 ,
V_15 . V_17 , V_10 , V_13 ) ;
F_7 ( L_7 ,
V_15 . V_18 , V_11 , V_14 ) ;
if ( F_8 ( V_5 , L_8 ) ) {
V_19 |= V_20 ;
F_9 ( L_9 ) ;
} else {
F_10 ( L_10 ) ;
}
return 1 ;
}
int T_1 F_11 ( unsigned long V_5 ,
const char * V_6 , int V_7 , void * V_8 )
{
int V_21 , V_22 , V_18 ;
const T_2 * V_23 ;
if ( V_7 != 1 || strcmp ( V_6 , L_1 ) != 0 )
return 0 ;
V_23 = F_5 ( V_5 , L_11 , & V_22 ) ;
if ( ! V_23 )
return 1 ;
F_7 ( L_12 ) ;
V_24 = V_22 / ( sizeof( * V_23 ) * 5 ) ;
if ( ! V_24 )
return 1 ;
V_18 = V_24 *
sizeof( struct V_25 ) ;
V_26 = F_12 ( F_13 ( V_18 , F_14 ( V_27 ) ,
V_28 ) ) ;
memset ( V_26 , 0 , V_18 ) ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ ) {
V_26 [ V_21 ] . V_29 =
F_6 ( V_23 + ( V_21 * 5 ) + 0 , 2 ) ;
V_26 [ V_21 ] . V_30 =
V_26 [ V_21 ] . V_29 +
F_6 ( V_23 + ( V_21 * 5 ) + 2 , 1 ) ;
V_26 [ V_21 ] . V_31 =
F_6 ( V_23 + ( V_21 * 5 ) + 3 , 2 ) ;
F_7 ( L_13 ,
V_26 [ V_21 ] . V_29 ,
V_26 [ V_21 ] . V_30 ,
V_26 [ V_21 ] . V_31 ) ;
}
return 1 ;
}
static int T_1 F_15 ( void )
{
#ifdef F_2
V_27 V_32 ;
if ( ! ( V_19 & V_20 ) )
return - V_33 ;
V_32 = 0x7000 ;
if ( ! F_16 ( V_34 ) ) {
F_9 ( L_14 ) ;
F_17 (
V_35 ,
0 , V_32 ) ;
V_32 += 128 ;
}
F_17 ( V_36 , 0 , V_32 ) ;
#endif
return 0 ;
}
int F_18 ( enum V_37 V_38 ,
struct V_39 * V_40 )
{
if ( ! V_40 || V_38 >= V_41 ) {
F_19 ( L_15 ,
V_42 , V_38 ) ;
return - V_43 ;
}
return F_20 (
& V_44 [ V_38 ] , V_40 ) ;
}
int F_21 ( enum V_37 V_38 ,
struct V_39 * V_40 )
{
return F_22 (
& V_44 [ V_38 ] , V_40 ) ;
}
static void F_23 ( T_3 V_38 , void * V_45 )
{
F_24 ( & V_44 [ V_38 ] ,
V_38 , V_45 ) ;
}
static void F_25 ( void )
{
T_4 V_46 ;
static struct V_47 V_45 ;
T_5 type ;
V_46 = F_26 ( F_27 ( & V_45 ) , sizeof( V_45 ) ) ;
if ( V_46 == V_48 )
return;
if ( V_46 ) {
F_19 ( L_16 ,
V_42 , V_46 ) ;
return;
}
type = F_28 ( V_45 . V_38 ) ;
if ( type >= V_41 ) {
F_29 ( L_17 , V_42 , type ) ;
return;
}
F_23 ( type , ( void * ) & V_45 ) ;
}
static T_6 F_30 ( int V_49 , void * V_8 )
{
F_25 () ;
return V_50 ;
}
static int T_1 F_31 ( void )
{
int V_46 , V_21 , V_49 ;
for ( V_21 = 0 ; V_21 < V_41 ; V_21 ++ )
F_32 ( & V_44 [ V_21 ] ) ;
V_49 = F_33 ( F_34 ( V_51 ) ) ;
if ( ! V_49 ) {
F_35 ( L_18 ,
V_42 , V_49 ) ;
return V_49 ;
}
V_46 = F_36 ( V_49 , F_30 ,
V_52 , L_19 , NULL ) ;
if ( V_46 ) {
F_35 ( L_20 ,
V_42 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
int F_37 ( T_3 V_53 , char * V_54 , int V_55 )
{
T_4 V_56 ;
T_7 V_57 , V_58 ;
if ( ! V_15 . V_17 )
return - V_33 ;
F_38 ( & V_57 ) ;
if ( ( F_39 ( V_57 ) & V_59 ) == 0 )
return 0 ;
V_58 = F_40 ( V_55 ) ;
V_56 = F_41 ( V_53 , & V_58 , V_54 ) ;
if ( V_56 == V_60 )
return F_39 ( V_58 ) ;
return 0 ;
}
int F_42 ( T_3 V_53 , const char * V_8 , int V_61 )
{
int V_62 = 0 ;
T_7 V_63 ;
T_4 V_58 , V_56 ;
unsigned long V_64 ;
T_7 V_57 ;
if ( ! V_15 . V_17 )
return - V_33 ;
F_43 ( & V_65 , V_64 ) ;
V_56 = F_44 ( V_53 , & V_63 ) ;
V_58 = F_39 ( V_63 ) ;
if ( V_56 || V_58 < V_61 ) {
F_45 ( & V_65 , V_64 ) ;
if ( V_56 )
return V_61 ;
F_38 ( NULL ) ;
return - V_66 ;
}
V_56 = V_67 ;
while( V_61 > 0 && ( V_56 == V_67 ||
V_56 == V_68 || V_56 == V_60 ) ) {
V_63 = F_40 ( V_61 ) ;
V_56 = F_46 ( V_53 , & V_63 , V_8 ) ;
V_58 = F_39 ( V_63 ) ;
if ( V_56 != V_60 && V_56 != V_67 &&
V_56 != V_68 ) {
V_62 = V_61 ;
break;
}
if ( V_56 == V_60 ) {
V_61 -= V_58 ;
V_8 += V_58 ;
V_62 += V_58 ;
}
do
F_38 ( & V_57 ) ;
while( V_56 == V_60 &&
( F_39 ( V_57 ) & V_69 ) );
}
F_45 ( & V_65 , V_64 ) ;
return V_62 ;
}
static int F_47 ( struct V_70 * V_71 ,
struct V_72 * V_57 )
{
int V_73 = 0 ;
if ( ! ( V_71 -> V_74 & V_75 ) ) {
F_35 ( L_21 ) ;
V_73 = 0 ;
} else if ( V_57 -> V_76 == V_77 ) {
V_73 = 1 ;
} else if ( V_57 -> V_78 == V_79 ) {
F_35 ( L_22 ) ;
V_73 = 0 ;
} else if ( ( V_57 -> V_78 == V_80 ) &&
( F_48 ( V_71 ) && ! F_49 ( V_81 ) ) ) {
F_50 ( V_82 , V_71 , V_83 , V_71 -> V_84 ) ;
V_73 = 1 ;
}
return V_73 ;
}
int F_51 ( struct V_70 * V_71 )
{
struct V_72 V_57 ;
int V_46 ;
if ( ! F_52 ( & V_57 , V_85 ) )
return 0 ;
if ( V_57 . V_86 != V_87 ) {
F_35 ( L_23 ,
V_57 . V_86 ) ;
return 0 ;
}
F_53 ( & V_57 , F_48 ( V_71 ) ) ;
if ( F_47 ( V_71 , & V_57 ) )
return 1 ;
V_46 = F_54 ( V_88 ,
L_24 ) ;
if ( V_46 == V_89 ) {
F_55 ( L_25 ,
V_88 ) ;
}
F_10 ( L_26 ) ;
return 0 ;
}
int F_56 ( struct V_70 * V_71 )
{
T_4 V_56 ;
V_56 = F_57 () ;
if ( V_56 == V_60 ) {
V_90 -> V_91 = 1 ;
return 1 ;
}
return 0 ;
}
int F_58 ( struct V_70 * V_71 )
{
T_4 V_56 ;
T_7 V_57 = 0 ;
if ( ! V_90 -> V_91 )
return 0 ;
V_90 -> V_91 = 0 ;
V_56 = F_38 ( & V_57 ) ;
if ( V_56 == V_60 && V_57 )
F_59 ( F_39 ( V_57 ) ) ;
return 1 ;
}
static T_8 F_60 ( T_8 V_84 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
if ( ( V_84 >= V_26 [ V_21 ] . V_29 ) &&
( V_84 < V_26 [ V_21 ] . V_30 ) )
return V_26 [ V_21 ] . V_31 ;
return 0 ;
}
bool F_61 ( struct V_70 * V_71 )
{
T_8 V_31 = 0 ;
if ( ! V_15 . V_16 || ! V_15 . V_18 )
goto V_92;
if ( ( V_71 -> V_84 >= V_15 . V_16 ) &&
( V_71 -> V_84 < ( V_15 . V_16 + V_15 . V_18 ) ) )
V_31 = F_60 ( V_71 -> V_84 ) ;
if ( V_31 )
V_71 -> V_84 = V_31 ;
V_92:
return ! ! V_31 ;
}
static int F_62 ( void )
{
V_93 = F_63 ( L_27 , V_94 ) ;
if ( ! V_93 ) {
F_64 ( L_28 ) ;
return - V_95 ;
}
return 0 ;
}
static T_9 F_65 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 ,
char * V_54 , T_10 V_102 , T_11 V_55 )
{
return F_66 ( V_54 , V_55 , & V_102 , V_101 -> V_103 ,
V_101 -> V_18 ) ;
}
static void F_67 ( void )
{
const T_7 * V_104 ;
unsigned int V_18 ;
struct V_105 * V_106 ;
int V_56 ;
V_106 = F_68 ( L_29 ) ;
if ( ! V_106 )
return;
V_104 = F_69 ( V_106 , L_30 , & V_18 ) ;
if ( ! V_104 || V_18 != 2 * sizeof( T_7 ) )
return;
V_107 . V_103 = F_12 ( F_39 ( V_104 [ 0 ] ) ) ;
V_107 . V_18 = F_39 ( V_104 [ 1 ] ) ;
V_56 = F_70 ( V_93 , & V_107 ) ;
if ( V_56 )
F_64 ( L_31 , V_56 ) ;
}
static T_9 F_71 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 , char * V_54 ,
T_10 V_102 , T_11 V_55 )
{
return F_66 ( V_54 , V_55 , & V_102 , V_101 -> V_103 ,
V_101 -> V_18 ) ;
}
static void F_72 ( void )
{
struct V_100 * V_108 ;
struct V_105 * V_109 ;
struct V_110 * V_23 ;
struct V_98 * V_99 ;
V_27 V_111 [ 2 ] ;
int V_56 ;
V_109 = F_68 ( L_32 ) ;
if ( ! V_109 )
return;
V_99 = F_63 ( L_33 , V_93 ) ;
if ( ! V_99 ) {
F_64 ( L_34 ) ;
return;
}
F_73 (np, prop) {
if ( ! strcmp ( V_23 -> V_112 , L_35 ) || ! strcmp ( V_23 -> V_112 , L_36 ) )
continue;
if ( F_74 ( V_109 , V_23 -> V_112 , & V_111 [ 0 ] , 2 ) )
continue;
V_108 = F_75 ( sizeof( * V_108 ) , V_113 ) ;
if ( V_108 == NULL ) {
F_64 ( L_37 ) ;
continue;
}
F_76 ( V_108 ) ;
V_108 -> V_108 . V_112 = F_77 ( V_23 -> V_112 , V_113 ) ;
V_108 -> V_108 . V_114 = 0400 ;
V_108 -> V_115 = F_71 ;
V_108 -> V_103 = F_12 ( V_111 [ 0 ] ) ;
V_108 -> V_18 = V_111 [ 1 ] ;
if ( V_108 -> V_108 . V_112 == NULL ) {
F_64 ( L_38 ) ;
F_78 ( V_108 ) ;
continue;
}
V_56 = F_70 ( V_99 , V_108 ) ;
if ( V_56 ) {
F_64 ( L_39 ,
V_56 , V_23 -> V_112 ) ;
F_78 ( V_108 -> V_108 . V_112 ) ;
F_78 ( V_108 ) ;
}
}
F_79 ( V_109 ) ;
}
static void T_1 F_80 ( void )
{
void * V_116 ;
T_8 V_18 ;
int V_56 ;
if ( ! F_16 ( V_117 ) )
return;
V_116 = F_81 () ;
if ( V_116 == NULL )
return;
V_18 = F_82 () ;
if ( V_18 == 0 )
return;
V_56 = F_83 ( V_118 ,
F_27 ( V_116 ) , V_18 ) ;
if ( V_56 && V_56 != V_89 )
F_64 ( L_40
L_41 , V_56 ) ;
}
static void F_84 ( const char * V_119 )
{
struct V_105 * V_109 ;
F_85 (np, NULL, compatible)
F_86 ( V_109 , NULL , NULL ) ;
}
static int F_87 ( void * V_120 )
{
unsigned long V_121 = F_88 ( V_122 ) + 1 ;
T_7 V_123 ;
F_89 () ;
do {
F_90 () ;
F_38 ( & V_123 ) ;
F_59 ( F_39 ( V_123 ) ) ;
F_91 ( V_121 ) ;
} while ( ! F_92 () );
return 0 ;
}
void F_93 ( void )
{
if ( V_124 )
F_94 ( V_124 ) ;
}
static void F_95 ( void )
{
if ( F_96 ( V_125 , L_42 ,
& V_122 ) != 0 )
V_122 = 0 ;
if ( V_122 )
V_124 = F_97 ( F_87 , NULL , L_43 ) ;
}
static int T_1 F_98 ( void )
{
struct V_105 * V_109 , * V_126 , * V_127 ;
int V_56 ;
V_125 = F_68 ( L_44 ) ;
if ( ! V_125 ) {
F_64 ( L_45 ) ;
return - V_33 ;
}
V_126 = F_68 ( L_46 ) ;
if ( V_126 ) {
F_99 (consoles, np) {
if ( strcmp ( V_109 -> V_112 , L_47 ) )
continue;
F_86 ( V_109 , NULL , NULL ) ;
}
F_79 ( V_126 ) ;
}
F_31 () ;
F_100 () ;
F_101 () ;
F_102 () ;
F_84 ( L_48 ) ;
F_95 () ;
V_127 = F_68 ( L_49 ) ;
if ( V_127 ) {
F_86 ( V_127 , L_50 , NULL ) ;
F_79 ( V_127 ) ;
}
F_103 () ;
V_56 = F_62 () ;
if ( V_56 == 0 ) {
F_67 () ;
F_80 () ;
V_56 = F_104 () ;
F_105 () ;
F_106 () ;
F_107 () ;
F_108 () ;
}
F_72 () ;
F_84 ( L_51 ) ;
F_84 ( L_52 ) ;
F_84 ( L_53 ) ;
F_84 ( L_54 ) ;
F_109 () ;
return 0 ;
}
void F_110 ( void )
{
long V_56 = V_67 ;
F_111 () ;
while ( V_56 == V_67 || V_56 == V_68 ) {
V_56 = F_112 () ;
if ( V_56 == V_67 )
F_38 ( NULL ) ;
else
F_113 ( 10 ) ;
}
if ( F_16 ( V_128 ) )
F_114 ( V_118 ) ;
}
struct V_129 * F_115 ( void * V_130 ,
unsigned long V_131 )
{
struct V_129 * V_132 , * V_133 = NULL ;
unsigned long V_21 = 0 ;
V_132 = F_75 ( V_134 , V_113 ) ;
if ( ! V_132 )
goto V_135;
V_133 = V_132 ;
while ( V_131 > 0 ) {
T_8 V_8 = F_116 ( V_130 ) << V_136 ;
T_8 V_137 = F_117 ( V_131 , V_134 ) ;
V_132 -> V_17 [ V_21 ] . V_8 = F_40 ( V_8 ) ;
V_132 -> V_17 [ V_21 ] . V_137 = F_40 ( V_137 ) ;
V_21 ++ ;
if ( V_21 >= V_138 ) {
struct V_129 * V_139 ;
V_139 = F_75 ( V_134 , V_113 ) ;
if ( ! V_139 )
goto V_135;
V_132 -> V_137 = F_40 (
V_21 * sizeof( struct V_140 ) + 16 ) ;
V_21 = 0 ;
V_132 -> V_139 = F_40 ( F_27 ( V_139 ) ) ;
V_132 = V_139 ;
}
V_130 += V_137 ;
V_131 -= V_137 ;
}
V_132 -> V_137 = F_40 ( V_21 * sizeof( struct V_140 ) + 16 ) ;
return V_133 ;
V_135:
F_35 ( L_55 , V_42 ) ;
F_118 ( V_133 ) ;
return NULL ;
}
void F_118 ( struct V_129 * V_132 )
{
while ( V_132 ) {
T_8 V_139 = F_39 ( V_132 -> V_139 ) ;
F_78 ( V_132 ) ;
if ( V_139 )
V_132 = F_12 ( V_139 ) ;
else
V_132 = NULL ;
}
}
int F_119 ( int V_56 )
{
switch ( V_56 ) {
case V_60 : return 0 ;
case V_141 : return - V_43 ;
case V_142 : return - V_143 ;
case V_68 : return - V_144 ;
case V_145 : return - V_95 ;
case V_146 : return - V_147 ;
case V_89 : return - V_148 ;
case V_149 : return - V_148 ;
case V_150 : return - V_148 ;
default:
F_35 ( L_56 , V_42 , V_56 ) ;
return - V_148 ;
}
}
void F_120 ( unsigned long V_151 )
{
int V_56 ;
if ( F_121 ( V_20 ) ) {
V_56 = F_122 ( - 1UL , V_151 ) ;
if ( V_56 != V_60 && V_56 != V_89 )
F_64 ( L_57 , V_42 ) ;
}
}
