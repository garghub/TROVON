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
struct V_52 * V_79 ;
int V_56 ;
if ( V_78 -> V_80 == 0 || V_78 -> V_80 > V_81 )
return F_32 ( - V_22 ) ;
F_21 ( V_82 / V_78 -> V_80 < sizeof( struct V_11 ) ) ;
if ( ! F_29 ( V_5 ) &&
F_33 ( F_34 () , F_35 () ,
V_83 ) != 0 )
return F_32 ( - V_84 ) ;
V_79 = F_36 ( sizeof( * V_79 ) , V_85 | V_86 ) ;
if ( ! V_79 )
return F_32 ( - V_87 ) ;
V_56 = F_37 ( & V_79 -> V_61 , V_78 ,
F_7 ) ;
if ( V_56 < 0 ) {
F_38 ( V_79 ) ;
return F_32 ( V_56 ) ;
}
F_39 ( & V_79 -> V_88 , 1 ) ;
return V_79 ;
}
static struct V_52 *
F_40 ( const char T_4 * V_89 )
{
struct V_77 V_78 ;
struct V_52 * V_12 = F_32 ( - V_90 ) ;
#ifdef F_41
if ( F_42 () ) {
struct V_91 V_92 ;
if ( F_43 ( & V_92 , V_89 , sizeof( V_92 ) ) )
goto V_93;
V_78 . V_80 = V_92 . V_80 ;
V_78 . V_12 = F_44 ( V_92 . V_12 ) ;
} else
#endif
if ( F_43 ( & V_78 , V_89 , sizeof( V_78 ) ) )
goto V_93;
V_12 = F_31 ( & V_78 ) ;
V_93:
return V_12 ;
}
static long F_45 ( unsigned int V_94 ,
struct V_52 * V_12 )
{
unsigned long V_95 ;
struct V_52 * V_96 ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_95 = V_12 -> V_61 -> V_80 ;
for ( V_96 = V_5 -> V_54 . V_12 ; V_96 ; V_96 = V_96 -> V_59 )
V_95 += V_96 -> V_61 -> V_80 + 4 ;
if ( V_95 > V_97 )
return - V_87 ;
if ( V_94 & V_98 ) {
int V_56 ;
V_56 = F_20 () ;
if ( V_56 )
return V_56 ;
}
V_12 -> V_59 = V_5 -> V_54 . V_12 ;
V_5 -> V_54 . V_12 = V_12 ;
if ( V_94 & V_98 )
F_25 () ;
return 0 ;
}
void F_26 ( struct V_3 * V_99 )
{
struct V_52 * V_100 = V_99 -> V_54 . V_12 ;
if ( ! V_100 )
return;
F_46 ( & V_100 -> V_88 ) ;
}
static inline void F_47 ( struct V_52 * V_12 )
{
if ( V_12 ) {
F_48 ( V_12 -> V_61 ) ;
F_38 ( V_12 ) ;
}
}
void F_27 ( struct V_3 * V_99 )
{
struct V_52 * V_100 = V_99 -> V_54 . V_12 ;
while ( V_100 && F_49 ( & V_100 -> V_88 ) ) {
struct V_52 * V_101 = V_100 ;
V_100 = V_100 -> V_59 ;
F_47 ( V_101 ) ;
}
}
static void F_50 ( int V_102 , int V_103 )
{
struct V_104 V_105 ;
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
V_105 . V_106 = V_107 ;
V_105 . V_108 = V_109 ;
V_105 . V_110 = ( void T_4 * ) F_6 ( V_5 ) ;
V_105 . V_111 = V_103 ;
V_105 . V_112 = F_4 () ;
V_105 . V_113 = V_102 ;
F_51 ( V_107 , & V_105 , V_5 ) ;
}
static void F_52 ( int V_114 )
{
int * V_115 = V_116 ;
#ifdef F_41
if ( F_42 () )
V_115 = V_117 ;
#endif
do {
if ( * V_115 == V_114 )
return;
} while ( * ++ V_115 );
#ifdef F_53
F_54 () ;
#endif
F_55 ( V_114 , V_118 , V_58 ) ;
F_56 ( V_118 ) ;
}
void F_57 ( int V_114 )
{
int V_66 = V_5 -> V_54 . V_66 ;
if ( V_66 == 0 )
return;
else if ( V_66 == V_119 )
F_52 ( V_114 ) ;
else
F_58 () ;
}
int F_59 ( void )
{
T_2 V_120 = F_60 ( NULL ) ;
if ( F_61 ( V_120 == V_121 ) )
return 0 ;
else if ( F_61 ( V_120 == V_122 ) )
return - 1 ;
else
return F_62 ( V_120 ) ;
}
static T_2 F_63 ( int V_114 , struct V_1 * V_2 )
{
T_2 V_123 , V_124 ;
int V_125 ;
F_64 () ;
V_123 = F_8 ( V_2 ) ;
V_125 = V_123 & V_126 ;
V_124 = V_123 & V_62 ;
switch ( V_124 ) {
case V_127 :
if ( V_125 > V_128 )
V_125 = V_128 ;
F_65 ( V_5 , F_2 ( V_5 ) ,
- V_125 , 0 ) ;
goto V_129;
case V_130 :
F_66 ( V_5 , F_2 ( V_5 ) ) ;
F_50 ( V_114 , V_125 ) ;
goto V_129;
case V_131 :
return V_123 ;
case V_57 :
return V_121 ;
case V_58 :
default:
F_55 ( V_114 , V_107 , V_124 ) ;
F_56 ( V_107 ) ;
}
F_67 () ;
V_129:
F_55 ( V_114 , 0 , V_124 ) ;
return V_122 ;
}
T_2 F_60 ( struct V_1 * V_2 )
{
int V_66 = V_5 -> V_54 . V_66 ;
int V_114 = V_2 ? V_2 -> V_8 :
F_3 ( V_5 , F_2 ( V_5 ) ) ;
switch ( V_66 ) {
case V_119 :
F_52 ( V_114 ) ;
return V_121 ;
#ifdef F_68
case V_75 :
return F_63 ( V_114 , V_2 ) ;
#endif
default:
F_58 () ;
}
}
int F_62 ( T_2 V_120 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_2 V_124 = V_120 & V_62 ;
int V_125 = V_120 & V_126 ;
F_21 ( V_124 != V_131 ) ;
F_55 ( F_3 ( V_5 , V_7 ) , 0 , V_124 ) ;
if ( ! F_69 ( V_5 , V_132 ) ) {
F_65 ( V_5 , V_7 ,
- V_133 , 0 ) ;
return - 1 ;
}
F_70 ( V_132 , V_125 ) ;
if ( F_71 ( V_5 ) )
F_56 ( V_107 ) ;
if ( F_3 ( V_5 , V_7 ) < 0 )
return - 1 ;
return 0 ;
}
long F_72 ( void )
{
return V_5 -> V_54 . V_66 ;
}
static long F_73 ( void )
{
const unsigned long V_63 = V_119 ;
long V_56 = - V_22 ;
F_74 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_93;
#ifdef F_75
F_76 () ;
#endif
F_16 ( V_5 , V_63 ) ;
V_56 = 0 ;
V_93:
F_77 ( & V_5 -> V_64 -> V_65 ) ;
return V_56 ;
}
static long F_78 ( unsigned int V_94 ,
const char T_4 * V_12 )
{
const unsigned long V_63 = V_75 ;
struct V_52 * V_134 = NULL ;
long V_56 = - V_22 ;
if ( V_94 & ~ V_135 )
return - V_22 ;
V_134 = F_40 ( V_12 ) ;
if ( F_79 ( V_134 ) )
return F_80 ( V_134 ) ;
if ( V_94 & V_98 &&
F_81 ( & V_5 -> signal -> V_72 ) )
goto V_136;
F_74 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_93;
V_56 = F_45 ( V_94 , V_134 ) ;
if ( V_56 )
goto V_93;
V_134 = NULL ;
F_16 ( V_5 , V_63 ) ;
V_93:
F_77 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_94 & V_98 )
F_82 ( & V_5 -> signal -> V_72 ) ;
V_136:
F_47 ( V_134 ) ;
return V_56 ;
}
static inline long F_78 ( unsigned int V_94 ,
const char T_4 * V_12 )
{
return - V_22 ;
}
static long F_83 ( unsigned int V_137 , unsigned int V_94 ,
const char T_4 * V_138 )
{
switch ( V_137 ) {
case V_139 :
if ( V_94 != 0 || V_138 != NULL )
return - V_22 ;
return F_73 () ;
case V_140 :
return F_78 ( V_94 , V_138 ) ;
default:
return - V_22 ;
}
}
long F_84 ( unsigned long V_63 , char T_4 * V_12 )
{
unsigned int V_137 ;
char T_4 * V_138 ;
switch ( V_63 ) {
case V_119 :
V_137 = V_139 ;
V_138 = NULL ;
break;
case V_75 :
V_137 = V_140 ;
V_138 = V_12 ;
break;
default:
return - V_22 ;
}
return F_83 ( V_137 , 0 , V_138 ) ;
}
