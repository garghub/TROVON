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
if ( F_8 ( V_3 , L_8 ) ) {
V_17 |= V_18 ;
F_9 ( L_9 ) ;
} else {
F_10 ( L_10 ) ;
}
F_1 () ;
if ( V_19 -> V_20 )
V_19 -> V_20 () ;
return 1 ;
}
int T_1 F_11 ( unsigned long V_3 ,
const char * V_4 , int V_5 , void * V_6 )
{
int V_21 , V_22 , V_16 ;
const T_2 * V_23 ;
if ( V_5 != 1 || strcmp ( V_4 , L_1 ) != 0 )
return 0 ;
V_23 = F_5 ( V_3 , L_11 , & V_22 ) ;
if ( ! V_23 )
return 1 ;
F_7 ( L_12 ) ;
V_24 = V_22 / ( sizeof( * V_23 ) * 5 ) ;
if ( ! V_24 )
return 1 ;
V_16 = V_24 *
sizeof( struct V_25 ) ;
V_26 = F_12 ( F_13 ( V_16 , F_14 ( V_27 ) ,
V_28 ) ) ;
memset ( V_26 , 0 , V_16 ) ;
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
if ( ! ( V_17 & V_18 ) )
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
static T_6 F_30 ( int V_49 , void * V_6 )
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
if ( ! V_13 . V_15 )
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
int F_42 ( T_3 V_53 , const char * V_6 , int V_61 )
{
int V_62 = 0 ;
T_7 V_63 ;
T_4 V_58 , V_56 ;
unsigned long V_64 ;
T_7 V_57 ;
if ( ! V_13 . V_15 )
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
V_56 = F_46 ( V_53 , & V_63 , V_6 ) ;
V_58 = F_39 ( V_63 ) ;
if ( V_56 != V_60 && V_56 != V_67 &&
V_56 != V_68 ) {
V_62 = V_61 ;
break;
}
if ( V_56 == V_60 ) {
V_61 -= V_58 ;
V_6 += V_58 ;
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
T_8 V_74 = F_48 ( V_57 ) ;
if ( ! ( V_71 -> V_75 & V_76 ) ) {
V_73 = 0 ;
} else if ( V_57 -> V_77 == V_78 ) {
V_73 = 1 ;
} else if ( V_74 && ! F_49 ( V_74 ) ) {
if ( F_50 ( V_71 ) && ! F_51 ( V_79 ) ) {
F_52 ( V_80 , V_71 , V_81 , V_71 -> V_82 ) ;
V_73 = 1 ;
} else
V_73 = 0 ;
} else if ( F_50 ( V_71 ) && ! F_51 ( V_79 ) &&
V_57 -> V_83 == V_84 ) {
F_52 ( V_80 , V_71 , V_81 , V_71 -> V_82 ) ;
V_73 = 1 ;
}
return V_73 ;
}
int F_53 ( struct V_70 * V_71 )
{
struct V_72 V_57 ;
int V_46 ;
if ( ! F_54 ( & V_57 , V_85 ) )
return 0 ;
if ( V_57 . V_86 != V_87 ) {
F_35 ( L_21 ,
V_57 . V_86 ) ;
return 0 ;
}
F_55 ( & V_57 ) ;
if ( F_47 ( V_71 , & V_57 ) )
return 1 ;
V_46 = F_56 ( V_88 ,
L_22 ) ;
if ( V_46 == V_89 ) {
F_57 ( L_23 ,
V_88 ) ;
}
F_10 ( L_24 ) ;
return 0 ;
}
int F_58 ( struct V_70 * V_71 )
{
T_4 V_56 ;
V_56 = F_59 () ;
if ( V_56 == V_60 ) {
V_90 -> V_91 = 1 ;
return 1 ;
}
return 0 ;
}
int F_60 ( struct V_70 * V_71 )
{
T_4 V_56 ;
T_7 V_57 = 0 ;
if ( ! V_90 -> V_91 )
return 0 ;
V_90 -> V_91 = 0 ;
V_56 = F_38 ( & V_57 ) ;
if ( V_56 == V_60 && V_57 )
F_61 ( F_39 ( V_57 ) ) ;
return 1 ;
}
static T_8 F_62 ( T_8 V_82 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_24 ; V_21 ++ )
if ( ( V_82 >= V_26 [ V_21 ] . V_29 ) &&
( V_82 < V_26 [ V_21 ] . V_30 ) )
return V_26 [ V_21 ] . V_31 ;
return 0 ;
}
bool F_63 ( struct V_70 * V_71 )
{
T_8 V_31 = 0 ;
if ( ! V_13 . V_14 || ! V_13 . V_16 )
goto V_92;
if ( ( V_71 -> V_82 >= V_13 . V_14 ) &&
( V_71 -> V_82 < ( V_13 . V_14 + V_13 . V_16 ) ) )
V_31 = F_62 ( V_71 -> V_82 ) ;
if ( V_31 )
V_71 -> V_82 = V_31 ;
V_92:
return ! ! V_31 ;
}
static int F_64 ( void )
{
V_93 = F_65 ( L_25 , V_94 ) ;
if ( ! V_93 ) {
F_66 ( L_26 ) ;
return - V_95 ;
}
return 0 ;
}
static T_9 F_67 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 ,
char * V_54 , T_10 V_102 , T_11 V_55 )
{
return F_68 ( V_54 , V_55 , & V_102 , V_101 -> V_103 ,
V_101 -> V_16 ) ;
}
static void F_69 ( void )
{
const T_7 * V_104 ;
unsigned int V_16 ;
struct V_105 * V_106 ;
int V_56 ;
V_106 = F_70 ( L_27 ) ;
if ( ! V_106 )
return;
V_104 = F_71 ( V_106 , L_28 , & V_16 ) ;
if ( ! V_104 || V_16 != 2 * sizeof( T_7 ) )
return;
V_107 . V_103 = F_12 ( F_39 ( V_104 [ 0 ] ) ) ;
V_107 . V_16 = F_39 ( V_104 [ 1 ] ) ;
V_56 = F_72 ( V_93 , & V_107 ) ;
if ( V_56 )
F_66 ( L_29 , V_56 ) ;
}
static void T_1 F_73 ( void )
{
void * V_108 ;
T_8 V_16 ;
int V_56 ;
if ( ! F_16 ( V_109 ) )
return;
V_108 = F_74 () ;
if ( V_108 == NULL )
return;
V_16 = F_75 () ;
if ( V_16 == 0 )
return;
V_56 = F_76 ( V_110 ,
F_27 ( V_108 ) , V_16 ) ;
if ( V_56 && V_56 != V_89 )
F_66 ( L_30
L_31 , V_56 ) ;
}
static void F_77 ( struct V_105 * V_111 ,
const char * V_112 )
{
struct V_105 * V_113 ;
F_78 (opal_node, np)
if ( F_79 ( V_113 , V_112 ) )
F_80 ( V_113 , NULL , NULL ) ;
}
static void F_81 ( void )
{
struct V_105 * V_113 ;
F_82 (np, NULL, L_32 )
F_80 ( V_113 , NULL , NULL ) ;
}
static int F_83 ( void * V_114 )
{
T_7 V_115 ;
F_84 () ;
do {
F_85 () ;
F_38 ( & V_115 ) ;
F_61 ( F_39 ( V_115 ) ) ;
F_86 ( V_116 ) ;
} while ( ! F_87 () );
return 0 ;
}
static void F_88 ( void )
{
if ( F_89 ( V_111 , L_33 ,
& V_116 ) != 0 )
V_116 = 0 ;
if ( V_116 )
F_90 ( F_83 , NULL , L_34 ) ;
}
static int T_1 F_91 ( void )
{
struct V_105 * V_113 , * V_117 , * V_118 ;
int V_56 ;
V_111 = F_70 ( L_35 ) ;
if ( ! V_111 ) {
F_66 ( L_36 ) ;
return - V_33 ;
}
V_117 = F_70 ( L_37 ) ;
if ( V_117 ) {
F_78 (consoles, np) {
if ( strcmp ( V_113 -> V_119 , L_38 ) )
continue;
F_80 ( V_113 , NULL , NULL ) ;
}
F_92 ( V_117 ) ;
}
F_31 () ;
F_93 () ;
F_94 () ;
F_95 () ;
F_81 () ;
F_88 () ;
V_118 = F_70 ( L_39 ) ;
if ( V_118 ) {
F_80 ( V_118 , L_40 , NULL ) ;
F_92 ( V_118 ) ;
}
V_56 = F_64 () ;
if ( V_56 == 0 ) {
F_69 () ;
F_73 () ;
V_56 = F_96 () ;
F_97 () ;
F_98 () ;
F_99 () ;
F_100 () ;
}
F_77 ( V_111 , L_41 ) ;
F_77 ( V_111 , L_42 ) ;
F_77 ( V_111 , L_43 ) ;
F_101 () ;
return 0 ;
}
void F_102 ( void )
{
long V_56 = V_67 ;
F_103 () ;
while ( V_56 == V_67 || V_56 == V_68 ) {
V_56 = F_104 () ;
if ( V_56 == V_67 )
F_38 ( NULL ) ;
else
F_105 ( 10 ) ;
}
if ( F_16 ( V_120 ) )
F_106 ( V_110 ) ;
}
struct V_121 * F_107 ( void * V_122 ,
unsigned long V_123 )
{
struct V_121 * V_124 , * V_125 = NULL ;
unsigned long V_21 = 0 ;
V_124 = F_108 ( V_126 , V_127 ) ;
if ( ! V_124 )
goto V_128;
V_125 = V_124 ;
while ( V_123 > 0 ) {
T_8 V_6 = F_109 ( V_122 ) << V_129 ;
T_8 V_130 = F_110 ( V_123 , V_126 ) ;
V_124 -> V_15 [ V_21 ] . V_6 = F_40 ( V_6 ) ;
V_124 -> V_15 [ V_21 ] . V_130 = F_40 ( V_130 ) ;
V_21 ++ ;
if ( V_21 >= V_131 ) {
struct V_121 * V_132 ;
V_132 = F_108 ( V_126 , V_127 ) ;
if ( ! V_132 )
goto V_128;
V_124 -> V_130 = F_40 (
V_21 * sizeof( struct V_133 ) + 16 ) ;
V_21 = 0 ;
V_124 -> V_132 = F_40 ( F_27 ( V_132 ) ) ;
V_124 = V_132 ;
}
V_122 += V_130 ;
V_123 -= V_130 ;
}
V_124 -> V_130 = F_40 ( V_21 * sizeof( struct V_133 ) + 16 ) ;
return V_125 ;
V_128:
F_35 ( L_44 , V_42 ) ;
F_111 ( V_125 ) ;
return NULL ;
}
void F_111 ( struct V_121 * V_124 )
{
while ( V_124 ) {
T_8 V_132 = F_39 ( V_124 -> V_132 ) ;
F_112 ( V_124 ) ;
if ( V_132 )
V_124 = F_12 ( V_132 ) ;
else
V_124 = NULL ;
}
}
int F_113 ( int V_56 )
{
switch ( V_56 ) {
case V_60 : return 0 ;
case V_134 : return - V_43 ;
case V_135 : return - V_136 ;
case V_68 : return - V_137 ;
case V_138 : return - V_95 ;
case V_139 : return - V_140 ;
case V_89 : return - V_141 ;
case V_142 : return - V_141 ;
case V_143 : return - V_141 ;
default:
F_35 ( L_45 , V_42 , V_56 ) ;
return - V_141 ;
}
}
