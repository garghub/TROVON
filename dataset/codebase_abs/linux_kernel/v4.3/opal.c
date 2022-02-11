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
int F_17 ( enum V_39 V_40 ,
struct V_41 * V_42 )
{
if ( ! V_42 || V_40 >= V_43 ) {
F_18 ( L_17 ,
V_44 , V_40 ) ;
return - V_45 ;
}
return F_19 (
& V_46 [ V_40 ] , V_42 ) ;
}
int F_20 ( enum V_39 V_40 ,
struct V_41 * V_42 )
{
return F_21 (
& V_46 [ V_40 ] , V_42 ) ;
}
static void F_22 ( T_3 V_40 , void * V_47 )
{
F_23 ( & V_46 [ V_40 ] ,
V_40 , V_47 ) ;
}
static void F_24 ( void )
{
T_4 V_48 ;
static struct V_49 V_47 ;
T_5 type ;
V_48 = F_25 ( F_26 ( & V_47 ) , sizeof( V_47 ) ) ;
if ( V_48 == V_50 )
return;
if ( V_48 ) {
F_18 ( L_18 ,
V_44 , V_48 ) ;
return;
}
type = F_27 ( V_47 . V_40 ) ;
if ( type >= V_43 ) {
F_18 ( L_19 , V_44 , type ) ;
return;
}
F_22 ( type , ( void * ) & V_47 ) ;
}
static T_6 F_28 ( int V_51 , void * V_6 )
{
F_24 () ;
return V_52 ;
}
static int T_1 F_29 ( void )
{
int V_48 , V_23 , V_51 ;
for ( V_23 = 0 ; V_23 < V_43 ; V_23 ++ )
F_30 ( & V_46 [ V_23 ] ) ;
V_51 = F_31 ( F_32 ( V_53 ) ) ;
if ( ! V_51 ) {
F_33 ( L_20 ,
V_44 , V_51 ) ;
return V_51 ;
}
V_48 = F_34 ( V_51 , F_28 ,
V_54 , L_21 , NULL ) ;
if ( V_48 ) {
F_33 ( L_22 ,
V_44 , V_48 ) ;
return V_48 ;
}
return 0 ;
}
int F_35 ( T_3 V_55 , char * V_56 , int V_57 )
{
T_4 V_58 ;
T_7 V_59 , V_60 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_36 ( & V_59 ) ;
if ( ( F_37 ( V_59 ) & V_61 ) == 0 )
return 0 ;
V_60 = F_38 ( V_57 ) ;
V_58 = F_39 ( V_55 , & V_60 , V_56 ) ;
if ( V_58 == V_62 )
return F_37 ( V_60 ) ;
return 0 ;
}
int F_40 ( T_3 V_55 , const char * V_6 , int V_63 )
{
int V_64 = 0 ;
T_7 V_65 ;
T_4 V_60 , V_58 ;
unsigned long V_66 ;
T_7 V_59 ;
if ( ! V_13 . V_15 )
return - V_35 ;
F_41 ( & V_67 , V_66 ) ;
if ( F_42 ( V_19 ) ) {
V_58 = F_43 ( V_55 , & V_65 ) ;
V_60 = F_37 ( V_65 ) ;
if ( V_58 || V_60 < V_63 ) {
F_44 ( & V_67 , V_66 ) ;
if ( V_58 )
return V_63 ;
F_36 ( NULL ) ;
return - V_68 ;
}
}
V_58 = V_69 ;
while( V_63 > 0 && ( V_58 == V_69 ||
V_58 == V_70 || V_58 == V_62 ) ) {
V_65 = F_38 ( V_63 ) ;
V_58 = F_45 ( V_55 , & V_65 , V_6 ) ;
V_60 = F_37 ( V_65 ) ;
if ( V_58 != V_62 && V_58 != V_69 &&
V_58 != V_70 ) {
V_64 = V_63 ;
break;
}
if ( V_58 == V_62 ) {
V_63 -= V_60 ;
V_6 += V_60 ;
V_64 += V_60 ;
}
do
F_36 ( & V_59 ) ;
while( V_58 == V_62 &&
( F_37 ( V_59 ) & V_71 ) );
}
F_44 ( & V_67 , V_66 ) ;
return V_64 ;
}
static int F_46 ( struct V_72 * V_73 ,
struct V_74 * V_59 )
{
int V_75 = 0 ;
T_8 V_76 = F_47 ( V_59 ) ;
if ( ! ( V_73 -> V_77 & V_78 ) ) {
V_75 = 0 ;
} else if ( V_59 -> V_79 == V_80 ) {
V_75 = 1 ;
} else if ( V_76 && ! F_48 ( V_76 ) ) {
if ( F_49 ( V_73 ) && ! F_50 ( V_81 ) ) {
F_51 ( V_82 , V_73 , V_83 , V_73 -> V_84 ) ;
V_75 = 1 ;
} else
V_75 = 0 ;
} else if ( F_49 ( V_73 ) && ! F_50 ( V_81 ) &&
V_59 -> V_85 == V_86 ) {
F_51 ( V_82 , V_73 , V_83 , V_73 -> V_84 ) ;
V_75 = 1 ;
}
return V_75 ;
}
int F_52 ( struct V_72 * V_73 )
{
struct V_74 V_59 ;
int V_48 ;
if ( ! F_53 ( & V_59 , V_87 ) )
return 0 ;
if ( V_59 . V_88 != V_89 ) {
F_33 ( L_23 ,
V_59 . V_88 ) ;
return 0 ;
}
F_54 ( & V_59 ) ;
if ( F_46 ( V_73 , & V_59 ) )
return 1 ;
V_48 = F_55 ( V_90 ,
L_24 ) ;
if ( V_48 == V_91 ) {
F_56 ( L_25 ,
V_90 ) ;
}
F_57 ( L_26 ) ;
return 0 ;
}
int F_58 ( struct V_72 * V_73 )
{
T_4 V_58 ;
V_58 = F_59 () ;
if ( V_58 == V_62 ) {
V_92 -> V_93 = 1 ;
return 1 ;
}
return 0 ;
}
int F_60 ( struct V_72 * V_73 )
{
T_4 V_58 ;
T_7 V_59 = 0 ;
if ( ! V_92 -> V_93 )
return 0 ;
V_92 -> V_93 = 0 ;
V_58 = F_36 ( & V_59 ) ;
if ( V_58 == V_62 && V_59 )
F_61 ( F_37 ( V_59 ) ) ;
return 1 ;
}
static T_8 F_62 ( T_8 V_84 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ )
if ( ( V_84 >= V_28 [ V_23 ] . V_31 ) &&
( V_84 < V_28 [ V_23 ] . V_32 ) )
return V_28 [ V_23 ] . V_33 ;
return 0 ;
}
bool F_63 ( struct V_72 * V_73 )
{
T_8 V_33 = 0 ;
if ( ! V_13 . V_14 || ! V_13 . V_16 )
goto V_94;
if ( ( V_73 -> V_84 >= V_13 . V_14 ) &&
( V_73 -> V_84 <= ( V_13 . V_14 + V_13 . V_16 ) ) )
V_33 = F_62 ( V_73 -> V_84 ) ;
if ( V_33 )
V_73 -> V_84 = V_33 ;
V_94:
return ! ! V_33 ;
}
static int F_64 ( void )
{
V_95 = F_65 ( L_27 , V_96 ) ;
if ( ! V_95 ) {
F_66 ( L_28 ) ;
return - V_97 ;
}
return 0 ;
}
static T_9 F_67 ( struct V_98 * V_99 , struct V_100 * V_101 ,
struct V_102 * V_103 ,
char * V_56 , T_10 V_104 , T_11 V_57 )
{
return F_68 ( V_56 , V_57 , & V_104 , V_103 -> V_105 ,
V_103 -> V_16 ) ;
}
static void F_69 ( void )
{
const T_7 * V_106 ;
unsigned int V_16 ;
struct V_107 * V_108 ;
int V_58 ;
V_108 = F_70 ( L_29 ) ;
if ( ! V_108 )
return;
V_106 = F_71 ( V_108 , L_30 , & V_16 ) ;
if ( ! V_106 || V_16 != 2 * sizeof( T_7 ) )
return;
V_109 . V_105 = F_11 ( F_37 ( V_106 [ 0 ] ) ) ;
V_109 . V_16 = F_37 ( V_106 [ 1 ] ) ;
V_58 = F_72 ( V_95 , & V_109 ) ;
if ( V_58 )
F_66 ( L_31 , V_58 ) ;
}
static void T_1 F_73 ( void )
{
void * V_110 ;
T_8 V_16 ;
int V_58 ;
if ( ! F_15 ( V_111 ) )
return;
V_110 = F_74 () ;
if ( V_110 == NULL )
return;
V_16 = F_75 () ;
if ( V_16 == 0 )
return;
V_58 = F_76 ( V_112 ,
F_26 ( V_110 ) , V_16 ) ;
if ( V_58 && V_58 != V_91 )
F_66 ( L_32
L_33 , V_58 ) ;
}
static void F_77 ( struct V_107 * V_113 ,
const char * V_114 )
{
struct V_107 * V_115 ;
F_78 (opal_node, np)
if ( F_79 ( V_115 , V_114 ) )
F_80 ( V_115 , NULL , NULL ) ;
}
static void F_81 ( void )
{
struct V_107 * V_115 ;
F_82 (np, NULL, L_34 )
F_80 ( V_115 , NULL , NULL ) ;
}
static int F_83 ( void * V_116 )
{
T_7 V_117 ;
F_84 () ;
do {
F_85 () ;
F_36 ( & V_117 ) ;
F_61 ( F_37 ( V_117 ) ) ;
F_86 ( V_118 ) ;
} while ( ! F_87 () );
return 0 ;
}
static void F_88 ( void )
{
if ( F_89 ( V_113 , L_35 ,
& V_118 ) != 0 )
V_118 = 0 ;
if ( V_118 )
F_90 ( F_83 , NULL , L_36 ) ;
}
static int T_1 F_91 ( void )
{
struct V_107 * V_115 , * V_119 , * V_120 ;
int V_58 ;
V_113 = F_70 ( L_37 ) ;
if ( ! V_113 ) {
F_66 ( L_38 ) ;
return - V_35 ;
}
if ( F_42 ( V_19 ) )
V_119 = F_70 ( L_39 ) ;
else
V_119 = F_92 ( V_113 ) ;
if ( V_119 ) {
F_78 (consoles, np) {
if ( strcmp ( V_115 -> V_121 , L_40 ) )
continue;
F_80 ( V_115 , NULL , NULL ) ;
}
F_93 ( V_119 ) ;
}
F_29 () ;
F_94 () ;
F_95 () ;
F_96 () ;
F_81 () ;
F_88 () ;
V_120 = F_70 ( L_41 ) ;
if ( V_120 ) {
F_80 ( V_120 , L_42 , NULL ) ;
F_93 ( V_120 ) ;
}
V_58 = F_64 () ;
if ( V_58 == 0 ) {
F_69 () ;
F_73 () ;
V_58 = F_97 () ;
F_98 () ;
F_99 () ;
F_100 () ;
F_101 () ;
}
F_77 ( V_113 , L_43 ) ;
F_77 ( V_113 , L_44 ) ;
F_77 ( V_113 , L_45 ) ;
return 0 ;
}
void F_102 ( void )
{
long V_58 = V_69 ;
F_103 () ;
while ( V_58 == V_69 || V_58 == V_70 ) {
V_58 = F_104 () ;
if ( V_58 == V_69 )
F_36 ( NULL ) ;
else
F_105 ( 10 ) ;
}
if ( F_15 ( V_122 ) )
F_106 ( V_112 ) ;
}
struct V_123 * F_107 ( void * V_124 ,
unsigned long V_125 )
{
struct V_123 * V_126 , * V_127 = NULL ;
unsigned long V_23 = 0 ;
V_126 = F_108 ( V_128 , V_129 ) ;
if ( ! V_126 )
goto V_130;
V_127 = V_126 ;
while ( V_125 > 0 ) {
T_8 V_6 = F_109 ( V_124 ) << V_131 ;
T_8 V_132 = F_110 ( V_125 , V_128 ) ;
V_126 -> V_15 [ V_23 ] . V_6 = F_38 ( V_6 ) ;
V_126 -> V_15 [ V_23 ] . V_132 = F_38 ( V_132 ) ;
V_23 ++ ;
if ( V_23 >= V_133 ) {
struct V_123 * V_134 ;
V_134 = F_108 ( V_128 , V_129 ) ;
if ( ! V_134 )
goto V_130;
V_126 -> V_132 = F_38 (
V_23 * sizeof( struct V_135 ) + 16 ) ;
V_23 = 0 ;
V_126 -> V_134 = F_38 ( F_26 ( V_134 ) ) ;
V_126 = V_134 ;
}
V_124 += V_132 ;
V_125 -= V_132 ;
}
V_126 -> V_132 = F_38 ( V_23 * sizeof( struct V_135 ) + 16 ) ;
return V_127 ;
V_130:
F_33 ( L_46 , V_44 ) ;
F_111 ( V_127 ) ;
return NULL ;
}
void F_111 ( struct V_123 * V_126 )
{
while ( V_126 ) {
T_8 V_134 = F_37 ( V_126 -> V_134 ) ;
F_112 ( V_126 ) ;
if ( V_134 )
V_126 = F_11 ( V_134 ) ;
else
V_126 = NULL ;
}
}
int F_113 ( int V_58 )
{
switch ( V_58 ) {
case V_62 : return 0 ;
case V_136 : return - V_45 ;
case V_137 : return - V_138 ;
case V_70 : return - V_139 ;
case V_140 : return - V_97 ;
case V_141 : return - V_142 ;
case V_91 : return - V_143 ;
case V_144 : return - V_143 ;
case V_145 : return - V_143 ;
default:
F_33 ( L_47 , V_44 , V_58 ) ;
return - V_143 ;
}
}
