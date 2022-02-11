static void F_1 ( void )
{
#ifdef F_2
F_3 ( V_1 ) ;
#else
F_3 ( V_2 ) ;
#endif
}
int T_1 F_4 ( unsigned long V_3 ,
const char * V_4 , int V_5 , void * V_6 )
{
const void * V_7 , * V_8 , * V_9 ;
int V_10 , V_11 , V_12 ;
if ( V_5 != 1 || strcmp ( V_4 , L_1 ) != 0 )
return 0 ;
V_7 = F_5 ( V_3 , L_2 , & V_10 ) ;
V_8 = F_5 ( V_3 , L_3 , & V_11 ) ;
V_9 = F_5 ( V_3 , L_4 , & V_12 ) ;
if ( ! V_7 || ! V_8 || ! V_9 )
return 1 ;
V_13 . V_14 = F_6 ( V_7 , V_10 / 4 ) ;
V_13 . V_15 = F_6 ( V_8 , V_11 / 4 ) ;
V_13 . V_16 = F_6 ( V_9 , V_12 / 4 ) ;
F_7 ( L_5 ,
V_13 . V_14 , V_7 , V_10 ) ;
F_7 ( L_6 ,
V_13 . V_15 , V_8 , V_11 ) ;
F_7 ( L_7 ,
V_13 . V_16 , V_9 , V_12 ) ;
V_17 |= V_18 ;
if ( F_8 ( V_3 , L_8 ) ) {
V_17 |= V_19 ;
V_17 |= V_20 ;
F_9 ( L_9 ) ;
} else if ( F_8 ( V_3 , L_10 ) ) {
V_17 |= V_19 ;
F_9 ( L_11 ) ;
} else {
F_9 ( L_12 ) ;
}
F_1 () ;
if ( V_21 -> V_22 )
V_21 -> V_22 () ;
return 1 ;
}
int T_1 F_10 ( unsigned long V_3 ,
const char * V_4 , int V_5 , void * V_6 )
{
int V_23 , V_24 , V_16 ;
const T_2 * V_25 ;
if ( V_5 != 1 || strcmp ( V_4 , L_1 ) != 0 )
return 0 ;
V_25 = F_5 ( V_3 , L_13 , & V_24 ) ;
if ( ! V_25 )
return 1 ;
F_7 ( L_14 ) ;
V_26 = V_24 / ( sizeof( * V_25 ) * 5 ) ;
if ( ! V_26 )
return 1 ;
V_16 = V_26 *
sizeof( struct V_27 ) ;
V_28 = F_11 ( F_12 ( V_16 , F_13 ( V_29 ) ,
V_30 ) ) ;
memset ( V_28 , 0 , V_16 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_28 [ V_23 ] . V_31 =
F_6 ( V_25 + ( V_23 * 5 ) + 0 , 2 ) ;
V_28 [ V_23 ] . V_32 =
V_28 [ V_23 ] . V_31 +
F_6 ( V_25 + ( V_23 * 5 ) + 2 , 1 ) ;
V_28 [ V_23 ] . V_33 =
F_6 ( V_25 + ( V_23 * 5 ) + 3 , 2 ) ;
F_7 ( L_15 ,
V_28 [ V_23 ] . V_31 ,
V_28 [ V_23 ] . V_32 ,
V_28 [ V_23 ] . V_33 ) ;
}
return 1 ;
}
static int T_1 F_14 ( void )
{
#ifdef F_2
V_29 V_34 ;
if ( ! ( V_17 & V_18 ) )
return - V_35 ;
V_34 = 0x7000 ;
if ( ! F_15 ( V_36 ) ) {
F_9 ( L_16 ) ;
F_16 (
V_37 ,
0 , V_34 ) ;
V_34 += 128 ;
}
F_16 ( V_38 , 0 , V_34 ) ;
#endif
return 0 ;
}
int F_17 ( struct V_39 * V_40 )
{
if ( ! V_40 ) {
F_18 ( L_17 ,
V_41 , V_40 ) ;
return - V_42 ;
}
F_19 ( & V_43 , V_40 ) ;
return 0 ;
}
int F_20 ( struct V_39 * V_40 )
{
if ( ! V_40 ) {
F_18 ( L_17 ,
V_41 , V_40 ) ;
return - V_42 ;
}
F_21 ( & V_43 , V_40 ) ;
return 0 ;
}
static void F_22 ( T_3 V_44 )
{
unsigned long V_45 ;
T_3 V_46 ;
if ( F_23 ( & V_47 ) )
return;
F_24 ( & V_48 , V_45 ) ;
V_46 = V_49 ^ V_44 ;
V_49 = V_44 ;
F_25 ( & V_48 , V_45 ) ;
F_26 ( & V_43 ,
V_44 , ( void * ) V_46 ) ;
}
void F_27 ( T_3 V_50 ,
T_3 V_51 )
{
unsigned long V_45 ;
F_24 ( & V_48 , V_45 ) ;
V_49 &= ~ V_50 ;
V_49 |= V_51 ;
F_25 ( & V_48 , V_45 ) ;
}
void F_28 ( void )
{
T_4 V_52 ;
T_5 V_53 = 0 ;
F_29 ( & V_47 , 0 ) ;
V_52 = F_30 ( & V_53 ) ;
if ( V_52 == V_54 && V_53 )
F_22 ( F_31 ( V_53 ) ) ;
}
void F_32 ( void )
{
F_29 ( & V_47 , 1 ) ;
}
int F_33 ( enum V_55 V_56 ,
struct V_39 * V_40 )
{
if ( ! V_40 ) {
F_18 ( L_17 ,
V_41 , V_40 ) ;
return - V_42 ;
}
if ( V_56 > V_57 ) {
F_18 ( L_18 ,
V_41 , V_56 ) ;
return - V_42 ;
}
return F_19 (
& V_58 [ V_56 ] , V_40 ) ;
}
static void F_34 ( T_6 V_56 , void * V_59 )
{
F_26 ( & V_58 [ V_56 ] ,
V_56 , V_59 ) ;
}
static void F_35 ( void )
{
T_7 V_60 ;
static struct V_61 V_59 ;
T_8 type ;
V_60 = F_36 ( F_37 ( & V_59 ) , sizeof( V_59 ) ) ;
if ( V_60 == V_62 )
return;
if ( V_60 ) {
F_18 ( L_19 ,
V_41 , V_60 ) ;
return;
}
type = F_38 ( V_59 . V_56 ) ;
if ( type > V_57 ) {
F_18 ( L_20 , V_41 , type ) ;
return;
}
F_34 ( type , ( void * ) & V_59 ) ;
}
static int F_39 ( struct V_39 * V_40 ,
unsigned long V_44 , void * V_63 )
{
if ( V_44 & V_64 )
F_35 () ;
return 0 ;
}
static int T_1 F_40 ( void )
{
int V_60 , V_23 ;
for ( V_23 = 0 ; V_23 < V_57 ; V_23 ++ )
F_41 ( & V_58 [ V_23 ] ) ;
V_60 = F_17 ( & V_65 ) ;
if ( V_60 ) {
F_42 ( L_21 ,
V_41 , V_60 ) ;
return V_60 ;
}
return 0 ;
}
int F_43 ( T_6 V_66 , char * V_67 , int V_68 )
{
T_7 V_52 ;
T_5 V_53 , V_69 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_30 ( & V_53 ) ;
if ( ( F_31 ( V_53 ) & V_70 ) == 0 )
return 0 ;
V_69 = F_44 ( V_68 ) ;
V_52 = F_45 ( V_66 , & V_69 , V_67 ) ;
if ( V_52 == V_54 )
return F_31 ( V_69 ) ;
return 0 ;
}
int F_46 ( T_6 V_66 , const char * V_6 , int V_71 )
{
int V_72 = 0 ;
T_5 V_73 ;
T_7 V_69 , V_52 ;
unsigned long V_45 ;
T_5 V_53 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_24 ( & V_74 , V_45 ) ;
if ( F_47 ( V_19 ) ) {
V_52 = F_48 ( V_66 , & V_73 ) ;
V_69 = F_31 ( V_73 ) ;
if ( V_52 || V_69 < V_71 ) {
F_25 ( & V_74 , V_45 ) ;
if ( V_52 )
return V_71 ;
F_30 ( NULL ) ;
return - V_75 ;
}
}
V_52 = V_76 ;
while( V_71 > 0 && ( V_52 == V_76 ||
V_52 == V_77 || V_52 == V_54 ) ) {
V_73 = F_44 ( V_71 ) ;
V_52 = F_49 ( V_66 , & V_73 , V_6 ) ;
V_69 = F_31 ( V_73 ) ;
if ( V_52 != V_54 && V_52 != V_76 &&
V_52 != V_77 ) {
V_72 = V_71 ;
break;
}
if ( V_52 == V_54 ) {
V_71 -= V_69 ;
V_6 += V_69 ;
V_72 += V_69 ;
}
do
F_30 ( & V_53 ) ;
while( V_52 == V_54 &&
( F_31 ( V_53 ) & V_78 ) );
}
F_25 ( & V_74 , V_45 ) ;
return V_72 ;
}
static int F_50 ( struct V_79 * V_80 ,
struct V_81 * V_53 )
{
int V_82 = 0 ;
T_3 V_83 = F_51 ( V_53 ) ;
if ( ! ( V_80 -> V_84 & V_85 ) ) {
V_82 = 0 ;
} else if ( V_53 -> V_86 == V_87 ) {
V_82 = 1 ;
} else if ( V_83 && ! F_52 ( V_83 ) ) {
if ( F_53 ( V_80 ) && ! F_54 ( V_88 ) ) {
F_55 ( V_89 , V_80 , V_90 , V_80 -> V_91 ) ;
V_82 = 1 ;
} else
V_82 = 0 ;
} else if ( F_53 ( V_80 ) && ! F_54 ( V_88 ) &&
V_53 -> V_92 == V_93 ) {
F_55 ( V_89 , V_80 , V_90 , V_80 -> V_91 ) ;
V_82 = 1 ;
}
return V_82 ;
}
int F_56 ( struct V_79 * V_80 )
{
struct V_81 V_53 ;
if ( ! F_57 ( & V_53 , V_94 ) )
return 0 ;
if ( V_53 . V_95 != V_96 ) {
F_42 ( L_22 ,
V_53 . V_95 ) ;
return 0 ;
}
F_58 ( & V_53 ) ;
if ( F_50 ( V_80 , & V_53 ) )
return 1 ;
return 0 ;
}
int F_59 ( struct V_79 * V_80 )
{
T_7 V_52 ;
V_52 = F_60 () ;
if ( V_52 == V_54 ) {
V_97 -> V_98 = 1 ;
return 1 ;
}
return 0 ;
}
int F_61 ( struct V_79 * V_80 )
{
T_7 V_52 ;
T_5 V_53 = 0 ;
if ( ! V_97 -> V_98 )
return 0 ;
V_97 -> V_98 = 0 ;
V_52 = F_30 ( & V_53 ) ;
if ( V_52 == V_54 && V_53 )
F_22 ( F_31 ( V_53 ) ) ;
return 1 ;
}
static T_3 F_62 ( T_3 V_91 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ )
if ( ( V_91 >= V_28 [ V_23 ] . V_31 ) &&
( V_91 < V_28 [ V_23 ] . V_32 ) )
return V_28 [ V_23 ] . V_33 ;
return 0 ;
}
bool F_63 ( struct V_79 * V_80 )
{
T_3 V_33 = 0 ;
if ( ! V_13 . V_14 || ! V_13 . V_16 )
goto V_99;
if ( ( V_80 -> V_91 >= V_13 . V_14 ) &&
( V_80 -> V_91 <= ( V_13 . V_14 + V_13 . V_16 ) ) )
V_33 = F_62 ( V_80 -> V_91 ) ;
if ( V_33 )
V_80 -> V_91 = V_33 ;
V_99:
return ! ! V_33 ;
}
static T_9 F_64 ( int V_100 , void * V_6 )
{
T_5 V_44 ;
F_65 ( F_66 ( V_100 ) , & V_44 ) ;
F_22 ( F_31 ( V_44 ) ) ;
return V_101 ;
}
static int F_67 ( void )
{
V_102 = F_68 ( L_23 , V_103 ) ;
if ( ! V_102 ) {
F_69 ( L_24 ) ;
return - V_104 ;
}
return 0 ;
}
static T_10 F_70 ( struct V_105 * V_106 , struct V_107 * V_108 ,
struct V_109 * V_110 ,
char * V_67 , T_11 V_111 , T_12 V_68 )
{
return F_71 ( V_67 , V_68 , & V_111 , V_110 -> V_112 ,
V_110 -> V_16 ) ;
}
static void F_72 ( void )
{
const T_5 * V_113 ;
unsigned int V_16 ;
struct V_114 * V_115 ;
int V_52 ;
V_115 = F_73 ( L_25 ) ;
if ( ! V_115 )
return;
V_113 = F_74 ( V_115 , L_26 , & V_16 ) ;
if ( ! V_113 || V_16 != 2 * sizeof( T_5 ) )
return;
V_116 . V_112 = F_11 ( F_31 ( V_113 [ 0 ] ) ) ;
V_116 . V_16 = F_31 ( V_113 [ 1 ] ) ;
V_52 = F_75 ( V_102 , & V_116 ) ;
if ( V_52 )
F_69 ( L_27 , V_52 ) ;
}
static void T_1 F_76 ( void )
{
void * V_117 ;
T_3 V_16 ;
int V_52 ;
V_117 = F_77 () ;
if ( V_117 == NULL )
return;
V_16 = F_78 () ;
if ( V_16 == 0 )
return;
V_52 = F_79 ( V_118 ,
F_37 ( V_117 ) , V_16 ) ;
if ( V_52 && V_52 != V_119 )
F_69 ( L_28
L_29 , V_52 ) ;
}
static void F_80 ( struct V_114 * V_120 )
{
struct V_114 * V_121 ;
F_81 (opal_node, np)
if ( F_82 ( V_121 , L_30 ) )
F_83 ( V_121 , NULL , NULL ) ;
}
static void F_84 ( void )
{
struct V_114 * V_121 ;
F_85 (np, NULL, L_31 )
F_83 ( V_121 , NULL , NULL ) ;
}
static void T_1 F_86 ( struct V_114 * V_122 )
{
const T_2 * V_123 ;
int V_23 , V_124 ;
V_123 = F_74 ( V_120 , L_32 , & V_124 ) ;
V_125 = V_123 ? ( V_124 / 4 ) : 0 ;
F_7 ( L_33 , V_125 ) ;
if ( ! V_125 )
return;
V_126 = F_87 ( V_125 * sizeof( unsigned int ) , V_127 ) ;
for ( V_23 = 0 ; V_123 && V_23 < V_125 ; V_23 ++ , V_123 ++ ) {
unsigned int V_100 , V_128 ;
int V_52 ;
V_100 = F_88 ( V_123 ) ;
V_128 = F_89 ( NULL , V_100 ) ;
if ( V_128 == V_129 ) {
F_69 ( L_34 , V_100 ) ;
continue;
}
V_52 = F_90 ( V_128 , F_64 , 0 , L_23 , NULL ) ;
if ( V_52 ) {
F_91 ( V_128 ) ;
F_69 ( L_35 ,
V_52 , V_128 , V_100 ) ;
continue;
}
V_126 [ V_23 ] = V_128 ;
}
}
static int T_1 F_92 ( void )
{
struct V_114 * V_121 , * V_130 ;
int V_52 ;
V_120 = F_73 ( L_36 ) ;
if ( ! V_120 ) {
F_69 ( L_37 ) ;
return - V_35 ;
}
if ( F_47 ( V_19 ) )
V_130 = F_73 ( L_38 ) ;
else
V_130 = F_93 ( V_120 ) ;
if ( V_130 ) {
F_81 (consoles, np) {
if ( strcmp ( V_121 -> V_131 , L_39 ) )
continue;
F_83 ( V_121 , NULL , NULL ) ;
}
F_94 ( V_130 ) ;
}
F_84 () ;
F_86 ( V_120 ) ;
V_52 = F_67 () ;
if ( V_52 == 0 ) {
F_72 () ;
F_76 () ;
V_52 = F_95 () ;
F_96 () ;
F_97 () ;
F_98 () ;
F_99 () ;
}
F_80 ( V_120 ) ;
return 0 ;
}
void F_100 ( void )
{
unsigned int V_23 ;
long V_52 = V_76 ;
for ( V_23 = 0 ; V_23 < V_125 ; V_23 ++ ) {
if ( V_126 [ V_23 ] )
F_101 ( V_126 [ V_23 ] , NULL ) ;
V_126 [ V_23 ] = 0 ;
}
while ( V_52 == V_76 || V_52 == V_77 ) {
V_52 = F_102 () ;
if ( V_52 == V_76 )
F_30 ( NULL ) ;
else
F_103 ( 10 ) ;
}
F_104 ( V_118 ) ;
}
struct V_132 * F_105 ( void * V_133 ,
unsigned long V_134 )
{
struct V_132 * V_135 , * V_136 = NULL ;
unsigned long V_23 = 0 ;
V_135 = F_87 ( V_137 , V_127 ) ;
if ( ! V_135 )
goto V_138;
V_136 = V_135 ;
while ( V_134 > 0 ) {
T_3 V_6 = F_106 ( V_133 ) << V_139 ;
T_3 V_140 = F_107 ( V_134 , V_137 ) ;
V_135 -> V_15 [ V_23 ] . V_6 = F_44 ( V_6 ) ;
V_135 -> V_15 [ V_23 ] . V_140 = F_44 ( V_140 ) ;
V_23 ++ ;
if ( V_23 >= V_141 ) {
struct V_132 * V_142 ;
V_142 = F_87 ( V_137 , V_127 ) ;
if ( ! V_142 )
goto V_138;
V_135 -> V_140 = F_44 (
V_23 * sizeof( struct V_143 ) + 16 ) ;
V_23 = 0 ;
V_135 -> V_142 = F_44 ( F_37 ( V_142 ) ) ;
V_135 = V_142 ;
}
V_133 += V_140 ;
V_134 -= V_140 ;
}
V_135 -> V_140 = F_44 ( V_23 * sizeof( struct V_143 ) + 16 ) ;
return V_136 ;
V_138:
F_42 ( L_40 , V_41 ) ;
F_108 ( V_136 ) ;
return NULL ;
}
void F_108 ( struct V_132 * V_135 )
{
while ( V_135 ) {
T_3 V_142 = F_31 ( V_135 -> V_142 ) ;
F_109 ( V_135 ) ;
if ( V_142 )
V_135 = F_11 ( V_142 ) ;
else
V_135 = NULL ;
}
}
