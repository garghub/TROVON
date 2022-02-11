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
static T_2 F_8 ( const struct V_1 * V_2 )
{
struct V_1 V_52 ;
T_2 V_53 = V_54 ;
struct V_55 * V_56 =
F_9 ( V_5 -> V_57 . V_12 ) ;
if ( F_10 ( F_11 ( V_56 == NULL ) ) )
return V_58 ;
if ( ! V_2 ) {
F_1 ( & V_52 ) ;
V_2 = & V_52 ;
}
for (; V_56 ; V_56 = V_56 -> V_59 ) {
T_2 V_60 = F_12 ( V_56 -> V_61 , V_2 ) ;
if ( ( V_60 & V_62 ) < ( V_53 & V_62 ) )
V_53 = V_60 ;
}
return V_53 ;
}
static inline bool F_13 ( unsigned long V_63 )
{
F_14 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_5 -> V_57 . V_66 && V_5 -> V_57 . V_66 != V_63 )
return false ;
return true ;
}
static inline void F_15 ( struct V_3 * V_4 ,
unsigned long V_63 )
{
F_14 ( & V_4 -> V_64 -> V_65 ) ;
V_4 -> V_57 . V_66 = V_63 ;
F_16 () ;
F_17 ( V_4 , V_67 ) ;
}
static int F_18 ( struct V_55 * V_68 ,
struct V_55 * V_69 )
{
if ( V_68 == NULL )
return 1 ;
for (; V_69 ; V_69 = V_69 -> V_59 )
if ( V_69 == V_68 )
return 1 ;
return 0 ;
}
static inline T_3 F_19 ( void )
{
struct V_3 * V_70 , * V_71 ;
F_20 ( ! F_21 ( & V_5 -> signal -> V_72 ) ) ;
F_14 ( & V_5 -> V_64 -> V_65 ) ;
V_71 = V_5 ;
F_22 (caller, thread) {
T_3 V_73 ;
if ( V_70 == V_71 )
continue;
if ( V_70 -> V_57 . V_66 == V_74 ||
( V_70 -> V_57 . V_66 == V_75 &&
F_18 ( V_70 -> V_57 . V_12 ,
V_71 -> V_57 . V_12 ) ) )
continue;
V_73 = F_23 ( V_70 ) ;
if ( F_10 ( F_11 ( V_73 == 0 ) ) )
V_73 = - V_76 ;
return V_73 ;
}
return 0 ;
}
static inline void F_24 ( void )
{
struct V_3 * V_70 , * V_71 ;
F_20 ( ! F_21 ( & V_5 -> signal -> V_72 ) ) ;
F_14 ( & V_5 -> V_64 -> V_65 ) ;
V_71 = V_5 ;
F_22 (caller, thread) {
if ( V_70 == V_71 )
continue;
F_25 ( V_71 ) ;
F_26 ( V_70 ) ;
F_27 ( & V_70 -> V_57 . V_12 ,
V_71 -> V_57 . V_12 ) ;
if ( F_28 ( V_71 ) )
F_29 ( V_70 ) ;
if ( V_70 -> V_57 . V_66 == V_74 )
F_15 ( V_70 , V_75 ) ;
}
}
static struct V_55 * F_30 ( struct V_77 * V_78 )
{
struct V_55 * V_79 ;
int V_53 ;
const bool V_80 = F_31 ( V_81 ) ;
if ( V_78 -> V_82 == 0 || V_78 -> V_82 > V_83 )
return F_32 ( - V_22 ) ;
F_20 ( V_84 / V_78 -> V_82 < sizeof( struct V_11 ) ) ;
if ( ! F_28 ( V_5 ) &&
F_33 ( F_34 () , F_35 () ,
V_85 ) != 0 )
return F_32 ( - V_86 ) ;
V_79 = F_36 ( sizeof( * V_79 ) , V_87 | V_88 ) ;
if ( ! V_79 )
return F_32 ( - V_89 ) ;
V_53 = F_37 ( & V_79 -> V_61 , V_78 ,
F_7 , V_80 ) ;
if ( V_53 < 0 ) {
F_38 ( V_79 ) ;
return F_32 ( V_53 ) ;
}
F_39 ( & V_79 -> V_90 , 1 ) ;
return V_79 ;
}
static struct V_55 *
F_40 ( const char T_4 * V_91 )
{
struct V_77 V_78 ;
struct V_55 * V_12 = F_32 ( - V_92 ) ;
#ifdef F_41
if ( F_42 () ) {
struct V_93 V_94 ;
if ( F_43 ( & V_94 , V_91 , sizeof( V_94 ) ) )
goto V_95;
V_78 . V_82 = V_94 . V_82 ;
V_78 . V_12 = F_44 ( V_94 . V_12 ) ;
} else
#endif
if ( F_43 ( & V_78 , V_91 , sizeof( V_78 ) ) )
goto V_95;
V_12 = F_30 ( & V_78 ) ;
V_95:
return V_12 ;
}
static long F_45 ( unsigned int V_96 ,
struct V_55 * V_12 )
{
unsigned long V_97 ;
struct V_55 * V_98 ;
F_14 ( & V_5 -> V_64 -> V_65 ) ;
V_97 = V_12 -> V_61 -> V_82 ;
for ( V_98 = V_5 -> V_57 . V_12 ; V_98 ; V_98 = V_98 -> V_59 )
V_97 += V_98 -> V_61 -> V_82 + 4 ;
if ( V_97 > V_99 )
return - V_89 ;
if ( V_96 & V_100 ) {
int V_53 ;
V_53 = F_19 () ;
if ( V_53 )
return V_53 ;
}
V_12 -> V_59 = V_5 -> V_57 . V_12 ;
V_5 -> V_57 . V_12 = V_12 ;
if ( V_96 & V_100 )
F_24 () ;
return 0 ;
}
void F_25 ( struct V_3 * V_101 )
{
struct V_55 * V_102 = V_101 -> V_57 . V_12 ;
if ( ! V_102 )
return;
F_46 ( & V_102 -> V_90 ) ;
}
static inline void F_47 ( struct V_55 * V_12 )
{
if ( V_12 ) {
F_48 ( V_12 -> V_61 ) ;
F_38 ( V_12 ) ;
}
}
void F_26 ( struct V_3 * V_101 )
{
struct V_55 * V_102 = V_101 -> V_57 . V_12 ;
while ( V_102 && F_49 ( & V_102 -> V_90 ) ) {
struct V_55 * V_103 = V_102 ;
V_102 = V_102 -> V_59 ;
F_47 ( V_103 ) ;
}
}
static void F_50 ( T_5 * V_104 , int V_105 , int V_106 )
{
memset ( V_104 , 0 , sizeof( * V_104 ) ) ;
V_104 -> V_107 = V_108 ;
V_104 -> V_109 = V_110 ;
V_104 -> V_111 = ( void T_4 * ) F_6 ( V_5 ) ;
V_104 -> V_112 = V_106 ;
V_104 -> V_113 = F_4 () ;
V_104 -> V_114 = V_105 ;
}
static void F_51 ( int V_105 , int V_106 )
{
struct V_115 V_104 ;
F_50 ( & V_104 , V_105 , V_106 ) ;
F_52 ( V_108 , & V_104 , V_5 ) ;
}
static void F_53 ( int V_116 )
{
const int * V_117 = V_118 ;
#ifdef F_41
if ( F_42 () )
V_117 = F_54 () ;
#endif
do {
if ( * V_117 == V_116 )
return;
} while ( * ++ V_117 );
#ifdef F_55
F_56 () ;
#endif
F_57 ( V_116 , V_119 , V_58 ) ;
F_58 ( V_119 ) ;
}
void F_59 ( int V_116 )
{
int V_66 = V_5 -> V_57 . V_66 ;
if ( F_31 ( V_81 ) &&
F_10 ( V_5 -> V_120 & V_121 ) )
return;
if ( V_66 == V_74 )
return;
else if ( V_66 == V_122 )
F_53 ( V_116 ) ;
else
F_60 () ;
}
static int F_61 ( int V_116 , const struct V_1 * V_2 ,
const bool V_123 )
{
T_2 V_124 , V_125 ;
int V_126 ;
F_62 () ;
V_124 = F_8 ( V_2 ) ;
V_126 = V_124 & V_127 ;
V_125 = V_124 & V_62 ;
switch ( V_125 ) {
case V_128 :
if ( V_126 > V_129 )
V_126 = V_129 ;
F_63 ( V_5 , F_2 ( V_5 ) ,
- V_126 , 0 ) ;
goto V_130;
case V_131 :
F_64 ( V_5 , F_2 ( V_5 ) ) ;
F_51 ( V_116 , V_126 ) ;
goto V_130;
case V_132 :
if ( V_123 )
return 0 ;
if ( ! F_65 ( V_5 , V_133 ) ) {
F_63 ( V_5 ,
F_2 ( V_5 ) ,
- V_134 , 0 ) ;
goto V_130;
}
F_66 ( V_133 , V_126 ) ;
if ( F_67 ( V_5 ) )
goto V_130;
V_116 = F_3 ( V_5 , F_2 ( V_5 ) ) ;
if ( V_116 < 0 )
goto V_130;
if ( F_61 ( V_116 , NULL , true ) )
return - 1 ;
return 0 ;
case V_54 :
return 0 ;
case V_58 :
default:
F_57 ( V_116 , V_108 , V_125 ) ;
if ( F_68 ( V_5 ) == 1 ) {
T_5 V_104 ;
F_64 ( V_5 , F_2 ( V_5 ) ) ;
F_50 ( & V_104 , V_116 , V_126 ) ;
F_69 ( & V_104 ) ;
}
F_58 ( V_108 ) ;
}
F_70 () ;
V_130:
F_57 ( V_116 , 0 , V_125 ) ;
return - 1 ;
}
static int F_61 ( int V_116 , const struct V_1 * V_2 ,
const bool V_123 )
{
F_60 () ;
}
int F_71 ( const struct V_1 * V_2 )
{
int V_66 = V_5 -> V_57 . V_66 ;
int V_116 ;
if ( F_31 ( V_81 ) &&
F_10 ( V_5 -> V_120 & V_121 ) )
return 0 ;
V_116 = V_2 ? V_2 -> V_8 :
F_3 ( V_5 , F_2 ( V_5 ) ) ;
switch ( V_66 ) {
case V_122 :
F_53 ( V_116 ) ;
return 0 ;
case V_75 :
return F_61 ( V_116 , V_2 , false ) ;
default:
F_60 () ;
}
}
long F_72 ( void )
{
return V_5 -> V_57 . V_66 ;
}
static long F_73 ( void )
{
const unsigned long V_63 = V_122 ;
long V_53 = - V_22 ;
F_74 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_13 ( V_63 ) )
goto V_95;
#ifdef F_75
F_76 () ;
#endif
F_15 ( V_5 , V_63 ) ;
V_53 = 0 ;
V_95:
F_77 ( & V_5 -> V_64 -> V_65 ) ;
return V_53 ;
}
static long F_78 ( unsigned int V_96 ,
const char T_4 * V_12 )
{
const unsigned long V_63 = V_75 ;
struct V_55 * V_135 = NULL ;
long V_53 = - V_22 ;
if ( V_96 & ~ V_136 )
return - V_22 ;
V_135 = F_40 ( V_12 ) ;
if ( F_79 ( V_135 ) )
return F_80 ( V_135 ) ;
if ( V_96 & V_100 &&
F_81 ( & V_5 -> signal -> V_72 ) )
goto V_137;
F_74 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_13 ( V_63 ) )
goto V_95;
V_53 = F_45 ( V_96 , V_135 ) ;
if ( V_53 )
goto V_95;
V_135 = NULL ;
F_15 ( V_5 , V_63 ) ;
V_95:
F_77 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_96 & V_100 )
F_82 ( & V_5 -> signal -> V_72 ) ;
V_137:
F_47 ( V_135 ) ;
return V_53 ;
}
static inline long F_78 ( unsigned int V_96 ,
const char T_4 * V_12 )
{
return - V_22 ;
}
static long F_83 ( unsigned int V_138 , unsigned int V_96 ,
const char T_4 * V_139 )
{
switch ( V_138 ) {
case V_140 :
if ( V_96 != 0 || V_139 != NULL )
return - V_22 ;
return F_73 () ;
case V_141 :
return F_78 ( V_96 , V_139 ) ;
default:
return - V_22 ;
}
}
long F_84 ( unsigned long V_63 , char T_4 * V_12 )
{
unsigned int V_138 ;
char T_4 * V_139 ;
switch ( V_63 ) {
case V_122 :
V_138 = V_140 ;
V_139 = NULL ;
break;
case V_75 :
V_138 = V_141 ;
V_139 = V_12 ;
break;
default:
return - V_22 ;
}
return F_83 ( V_138 , 0 , V_139 ) ;
}
long F_85 ( struct V_3 * V_4 , unsigned long V_142 ,
void T_4 * V_126 )
{
struct V_55 * V_12 ;
struct V_143 * V_78 ;
long V_53 ;
unsigned long V_144 = 0 ;
if ( ! F_86 ( V_85 ) ||
V_5 -> V_57 . V_66 != V_74 ) {
return - V_86 ;
}
F_74 ( & V_4 -> V_64 -> V_65 ) ;
if ( V_4 -> V_57 . V_66 != V_75 ) {
V_53 = - V_22 ;
goto V_95;
}
V_12 = V_4 -> V_57 . V_12 ;
while ( V_12 ) {
V_12 = V_12 -> V_59 ;
V_144 ++ ;
}
if ( V_142 >= V_144 ) {
V_53 = - V_145 ;
goto V_95;
}
V_144 -= V_142 ;
V_12 = V_4 -> V_57 . V_12 ;
while ( V_12 && V_144 > 1 ) {
V_12 = V_12 -> V_59 ;
V_144 -- ;
}
if ( F_11 ( V_144 != 1 || ! V_12 ) ) {
V_53 = - V_145 ;
goto V_95;
}
V_78 = V_12 -> V_61 -> V_146 ;
if ( ! V_78 ) {
V_53 = - V_147 ;
goto V_95;
}
V_53 = V_78 -> V_82 ;
if ( ! V_126 )
goto V_95;
F_25 ( V_4 ) ;
F_77 ( & V_4 -> V_64 -> V_65 ) ;
if ( F_87 ( V_126 , V_78 -> V_12 , F_88 ( V_78 ) ) )
V_53 = - V_92 ;
F_26 ( V_4 ) ;
return V_53 ;
V_95:
F_77 ( & V_4 -> V_64 -> V_65 ) ;
return V_53 ;
}
