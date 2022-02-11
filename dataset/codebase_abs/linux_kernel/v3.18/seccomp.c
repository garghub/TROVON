static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long args [ 6 ] ;
V_2 -> V_8 = F_3 ( V_4 , V_7 ) ;
V_2 -> V_9 = F_4 () ;
F_5 ( V_4 , V_7 , 0 , 6 , args ) ;
V_2 -> args [ 0 ] = args [ 0 ] ;
V_2 -> args [ 1 ] = args [ 1 ] ;
V_2 -> args [ 2 ] = args [ 2 ] ;
V_2 -> args [ 3 ] = args [ 3 ] ;
V_2 -> args [ 4 ] = args [ 4 ] ;
V_2 -> args [ 5 ] = args [ 5 ] ;
V_2 -> V_10 = F_6 ( V_4 ) ;
}
static int F_7 ( struct V_11 * V_12 , unsigned int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
struct V_11 * V_15 = & V_12 [ V_14 ] ;
T_1 V_16 = V_15 -> V_16 ;
T_2 V_17 = V_15 -> V_17 ;
switch ( V_16 ) {
case V_18 | V_19 | V_20 :
V_15 -> V_16 = V_21 | V_19 | V_20 ;
if ( V_17 >= sizeof( struct V_1 ) || V_17 & 3 )
return - V_22 ;
continue;
case V_18 | V_19 | V_23 :
V_15 -> V_16 = V_18 | V_24 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_21 | V_19 | V_23 :
V_15 -> V_16 = V_21 | V_24 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_25 | V_26 :
case V_25 | V_27 :
case V_28 | V_29 | V_26 :
case V_28 | V_29 | V_30 :
case V_28 | V_31 | V_26 :
case V_28 | V_31 | V_30 :
case V_28 | V_32 | V_26 :
case V_28 | V_32 | V_30 :
case V_28 | V_33 | V_26 :
case V_28 | V_33 | V_30 :
case V_28 | V_34 | V_26 :
case V_28 | V_34 | V_30 :
case V_28 | V_35 | V_26 :
case V_28 | V_35 | V_30 :
case V_28 | V_36 | V_26 :
case V_28 | V_36 | V_30 :
case V_28 | V_37 | V_26 :
case V_28 | V_37 | V_30 :
case V_28 | V_38 | V_26 :
case V_28 | V_38 | V_30 :
case V_28 | V_39 :
case V_18 | V_24 :
case V_21 | V_24 :
case V_40 | V_41 :
case V_40 | V_42 :
case V_18 | V_43 :
case V_21 | V_43 :
case V_44 :
case V_45 :
case V_46 | V_47 :
case V_46 | V_48 | V_26 :
case V_46 | V_48 | V_30 :
case V_46 | V_49 | V_26 :
case V_46 | V_49 | V_30 :
case V_46 | V_50 | V_26 :
case V_46 | V_50 | V_30 :
case V_46 | V_51 | V_26 :
case V_46 | V_51 | V_30 :
continue;
default:
return - V_22 ;
}
}
return 0 ;
}
static T_2 F_8 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_9 ( V_5 -> V_54 . V_12 ) ;
struct V_1 V_55 ;
T_2 V_56 = V_57 ;
if ( F_10 ( F_11 ( V_53 == NULL ) ) )
return V_58 ;
F_12 () ;
if ( ! V_2 ) {
F_1 ( & V_55 ) ;
V_2 = & V_55 ;
}
for (; V_53 ; V_53 = V_53 -> V_59 ) {
T_2 V_60 = F_13 ( V_53 -> V_61 , ( void * ) V_2 ) ;
if ( ( V_60 & V_62 ) < ( V_56 & V_62 ) )
V_56 = V_60 ;
}
return V_56 ;
}
static inline bool F_14 ( unsigned long V_63 )
{
F_15 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_5 -> V_54 . V_66 && V_5 -> V_54 . V_66 != V_63 )
return false ;
return true ;
}
static inline void F_16 ( struct V_3 * V_4 ,
unsigned long V_63 )
{
F_15 ( & V_4 -> V_64 -> V_65 ) ;
V_4 -> V_54 . V_66 = V_63 ;
F_17 () ;
F_18 ( V_4 , V_67 ) ;
}
static int F_19 ( struct V_52 * V_68 ,
struct V_52 * V_69 )
{
if ( V_68 == NULL )
return 1 ;
for (; V_69 ; V_69 = V_69 -> V_59 )
if ( V_69 == V_68 )
return 1 ;
return 0 ;
}
static inline T_3 F_20 ( void )
{
struct V_3 * V_70 , * V_71 ;
F_21 ( ! F_22 ( & V_5 -> signal -> V_72 ) ) ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_71 = V_5 ;
F_23 (caller, thread) {
T_3 V_73 ;
if ( V_70 == V_71 )
continue;
if ( V_70 -> V_54 . V_66 == V_74 ||
( V_70 -> V_54 . V_66 == V_75 &&
F_19 ( V_70 -> V_54 . V_12 ,
V_71 -> V_54 . V_12 ) ) )
continue;
V_73 = F_24 ( V_70 ) ;
if ( F_10 ( F_11 ( V_73 == 0 ) ) )
V_73 = - V_76 ;
return V_73 ;
}
return 0 ;
}
static inline void F_25 ( void )
{
struct V_3 * V_70 , * V_71 ;
F_21 ( ! F_22 ( & V_5 -> signal -> V_72 ) ) ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_71 = V_5 ;
F_23 (caller, thread) {
if ( V_70 == V_71 )
continue;
F_26 ( V_71 ) ;
F_27 ( V_70 ) ;
F_28 ( & V_70 -> V_54 . V_12 ,
V_71 -> V_54 . V_12 ) ;
if ( V_70 -> V_54 . V_66 == V_74 ) {
if ( F_29 ( V_71 ) )
F_30 ( V_70 ) ;
F_16 ( V_70 , V_75 ) ;
}
}
}
static struct V_52 * F_31 ( struct V_77 * V_78 )
{
struct V_52 * V_12 ;
unsigned long V_79 ;
struct V_11 * V_80 ;
int V_81 ;
long V_56 ;
if ( V_78 -> V_82 == 0 || V_78 -> V_82 > V_83 )
return F_32 ( - V_22 ) ;
F_21 ( V_84 / V_78 -> V_82 < sizeof( struct V_11 ) ) ;
V_79 = V_78 -> V_82 * sizeof( struct V_11 ) ;
if ( ! F_29 ( V_5 ) &&
F_33 ( F_34 () , F_35 () ,
V_85 ) != 0 )
return F_32 ( - V_86 ) ;
V_80 = F_36 ( V_79 , V_87 | V_88 ) ;
if ( ! V_80 )
return F_32 ( - V_89 ) ;
V_56 = - V_90 ;
if ( F_37 ( V_80 , V_78 -> V_12 , V_79 ) )
goto V_91;
V_56 = F_38 ( V_80 , V_78 -> V_82 ) ;
if ( V_56 )
goto V_91;
V_56 = F_7 ( V_80 , V_78 -> V_82 ) ;
if ( V_56 )
goto V_91;
V_56 = F_39 ( V_80 , V_78 -> V_82 , NULL , & V_81 ) ;
if ( V_56 )
goto V_91;
V_56 = - V_89 ;
V_12 = F_36 ( sizeof( struct V_52 ) ,
V_87 | V_88 ) ;
if ( ! V_12 )
goto V_91;
V_12 -> V_61 = F_40 ( F_41 ( V_81 ) , V_88 ) ;
if ( ! V_12 -> V_61 )
goto V_92;
V_56 = F_39 ( V_80 , V_78 -> V_82 , V_12 -> V_61 -> V_93 , & V_81 ) ;
if ( V_56 )
goto V_94;
F_42 ( V_80 ) ;
F_43 ( & V_12 -> V_95 , 1 ) ;
V_12 -> V_61 -> V_82 = V_81 ;
F_44 ( V_12 -> V_61 ) ;
return V_12 ;
V_94:
F_45 ( V_12 -> V_61 ) ;
V_92:
F_42 ( V_12 ) ;
V_91:
F_42 ( V_80 ) ;
return F_32 ( V_56 ) ;
}
static struct V_52 *
F_46 ( const char T_4 * V_96 )
{
struct V_77 V_78 ;
struct V_52 * V_12 = F_32 ( - V_90 ) ;
#ifdef F_47
if ( F_48 () ) {
struct V_97 V_98 ;
if ( F_37 ( & V_98 , V_96 , sizeof( V_98 ) ) )
goto V_99;
V_78 . V_82 = V_98 . V_82 ;
V_78 . V_12 = F_49 ( V_98 . V_12 ) ;
} else
#endif
if ( F_37 ( & V_78 , V_96 , sizeof( V_78 ) ) )
goto V_99;
V_12 = F_31 ( & V_78 ) ;
V_99:
return V_12 ;
}
static long F_50 ( unsigned int V_100 ,
struct V_52 * V_12 )
{
unsigned long V_101 ;
struct V_52 * V_102 ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_101 = V_12 -> V_61 -> V_82 ;
for ( V_102 = V_5 -> V_54 . V_12 ; V_102 ; V_102 = V_102 -> V_59 )
V_101 += V_102 -> V_61 -> V_82 + 4 ;
if ( V_101 > V_103 )
return - V_89 ;
if ( V_100 & V_104 ) {
int V_56 ;
V_56 = F_20 () ;
if ( V_56 )
return V_56 ;
}
V_12 -> V_59 = V_5 -> V_54 . V_12 ;
V_5 -> V_54 . V_12 = V_12 ;
if ( V_100 & V_104 )
F_25 () ;
return 0 ;
}
void F_26 ( struct V_3 * V_105 )
{
struct V_52 * V_106 = V_105 -> V_54 . V_12 ;
if ( ! V_106 )
return;
F_51 ( & V_106 -> V_95 ) ;
}
static inline void F_52 ( struct V_52 * V_12 )
{
if ( V_12 ) {
F_53 ( V_12 -> V_61 ) ;
F_42 ( V_12 ) ;
}
}
void F_27 ( struct V_3 * V_105 )
{
struct V_52 * V_106 = V_105 -> V_54 . V_12 ;
while ( V_106 && F_54 ( & V_106 -> V_95 ) ) {
struct V_52 * V_107 = V_106 ;
V_106 = V_106 -> V_59 ;
F_52 ( V_107 ) ;
}
}
static void F_55 ( int V_108 , int V_109 )
{
struct V_110 V_111 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_111 . V_112 = V_113 ;
V_111 . V_114 = V_115 ;
V_111 . V_116 = ( void T_4 * ) F_6 ( V_5 ) ;
V_111 . V_117 = V_109 ;
V_111 . V_118 = F_4 () ;
V_111 . V_119 = V_108 ;
F_56 ( V_113 , & V_111 , V_5 ) ;
}
static void F_57 ( int V_120 )
{
int * V_121 = V_122 ;
#ifdef F_47
if ( F_48 () )
V_121 = V_123 ;
#endif
do {
if ( * V_121 == V_120 )
return;
} while ( * ++ V_121 );
#ifdef F_58
F_59 () ;
#endif
F_60 ( V_120 , V_124 , V_58 ) ;
F_61 ( V_124 ) ;
}
void F_62 ( int V_120 )
{
int V_66 = V_5 -> V_54 . V_66 ;
if ( V_66 == 0 )
return;
else if ( V_66 == V_125 )
F_57 ( V_120 ) ;
else
F_63 () ;
}
int F_64 ( void )
{
T_2 V_126 = F_65 ( NULL ) ;
if ( F_66 ( V_126 == V_127 ) )
return 0 ;
else if ( F_66 ( V_126 == V_128 ) )
return - 1 ;
else
return F_67 ( V_126 ) ;
}
static T_2 F_68 ( int V_120 , struct V_1 * V_2 )
{
T_2 V_129 , V_130 ;
int V_131 ;
F_69 () ;
V_129 = F_8 ( V_2 ) ;
V_131 = V_129 & V_132 ;
V_130 = V_129 & V_62 ;
switch ( V_130 ) {
case V_133 :
F_70 ( V_5 , F_2 ( V_5 ) ,
- V_131 , 0 ) ;
goto V_134;
case V_135 :
F_71 ( V_5 , F_2 ( V_5 ) ) ;
F_55 ( V_120 , V_131 ) ;
goto V_134;
case V_136 :
return V_129 ;
case V_57 :
return V_127 ;
case V_58 :
default:
F_60 ( V_120 , V_113 , V_130 ) ;
F_61 ( V_113 ) ;
}
F_72 () ;
V_134:
F_60 ( V_120 , 0 , V_130 ) ;
return V_128 ;
}
T_2 F_65 ( struct V_1 * V_2 )
{
int V_66 = V_5 -> V_54 . V_66 ;
int V_120 = V_2 ? V_2 -> V_8 :
F_3 ( V_5 , F_2 ( V_5 ) ) ;
switch ( V_66 ) {
case V_125 :
F_57 ( V_120 ) ;
return V_127 ;
#ifdef F_73
case V_75 :
return F_68 ( V_120 , V_2 ) ;
#endif
default:
F_63 () ;
}
}
int F_67 ( T_2 V_126 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_2 V_130 = V_126 & V_62 ;
int V_131 = V_126 & V_132 ;
F_21 ( V_130 != V_136 ) ;
F_60 ( F_3 ( V_5 , V_7 ) , 0 , V_130 ) ;
if ( ! F_74 ( V_5 , V_137 ) ) {
F_70 ( V_5 , V_7 ,
- V_138 , 0 ) ;
return - 1 ;
}
F_75 ( V_137 , V_131 ) ;
if ( F_76 ( V_5 ) )
F_61 ( V_113 ) ;
if ( F_3 ( V_5 , V_7 ) < 0 )
return - 1 ;
return 0 ;
}
long F_77 ( void )
{
return V_5 -> V_54 . V_66 ;
}
static long F_78 ( void )
{
const unsigned long V_63 = V_125 ;
long V_56 = - V_22 ;
F_79 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_99;
#ifdef F_80
F_81 () ;
#endif
F_16 ( V_5 , V_63 ) ;
V_56 = 0 ;
V_99:
F_82 ( & V_5 -> V_64 -> V_65 ) ;
return V_56 ;
}
static long F_83 ( unsigned int V_100 ,
const char T_4 * V_12 )
{
const unsigned long V_63 = V_75 ;
struct V_52 * V_139 = NULL ;
long V_56 = - V_22 ;
if ( V_100 & ~ V_140 )
return - V_22 ;
V_139 = F_46 ( V_12 ) ;
if ( F_84 ( V_139 ) )
return F_85 ( V_139 ) ;
if ( V_100 & V_104 &&
F_86 ( & V_5 -> signal -> V_72 ) )
goto V_141;
F_79 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_99;
V_56 = F_50 ( V_100 , V_139 ) ;
if ( V_56 )
goto V_99;
V_139 = NULL ;
F_16 ( V_5 , V_63 ) ;
V_99:
F_82 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_100 & V_104 )
F_87 ( & V_5 -> signal -> V_72 ) ;
V_141:
F_52 ( V_139 ) ;
return V_56 ;
}
static inline long F_83 ( unsigned int V_100 ,
const char T_4 * V_12 )
{
return - V_22 ;
}
static long F_88 ( unsigned int V_142 , unsigned int V_100 ,
const char T_4 * V_143 )
{
switch ( V_142 ) {
case V_144 :
if ( V_100 != 0 || V_143 != NULL )
return - V_22 ;
return F_78 () ;
case V_145 :
return F_83 ( V_100 , V_143 ) ;
default:
return - V_22 ;
}
}
long F_89 ( unsigned long V_63 , char T_4 * V_12 )
{
unsigned int V_142 ;
char T_4 * V_143 ;
switch ( V_63 ) {
case V_125 :
V_142 = V_144 ;
V_143 = NULL ;
break;
case V_75 :
V_142 = V_145 ;
V_143 = V_12 ;
break;
default:
return - V_22 ;
}
return F_88 ( V_142 , 0 , V_143 ) ;
}
