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
static T_2 F_8 ( int V_52 )
{
struct V_53 * V_54 = F_9 ( V_5 -> V_55 . V_12 ) ;
struct V_1 V_2 ;
T_2 V_56 = V_57 ;
if ( F_10 ( F_11 ( V_54 == NULL ) ) )
return V_58 ;
F_12 () ;
F_1 ( & V_2 ) ;
for (; V_54 ; V_54 = V_54 -> V_59 ) {
T_2 V_60 = F_13 ( V_54 -> V_61 , ( void * ) & V_2 ) ;
if ( ( V_60 & V_62 ) < ( V_56 & V_62 ) )
V_56 = V_60 ;
}
return V_56 ;
}
static inline bool F_14 ( unsigned long V_63 )
{
F_15 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_5 -> V_55 . V_66 && V_5 -> V_55 . V_66 != V_63 )
return false ;
return true ;
}
static inline void F_16 ( struct V_3 * V_4 ,
unsigned long V_63 )
{
F_15 ( & V_4 -> V_64 -> V_65 ) ;
V_4 -> V_55 . V_66 = V_63 ;
F_17 () ;
F_18 ( V_4 , V_67 ) ;
}
static int F_19 ( struct V_53 * V_68 ,
struct V_53 * V_69 )
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
if ( V_70 -> V_55 . V_66 == V_74 ||
( V_70 -> V_55 . V_66 == V_75 &&
F_19 ( V_70 -> V_55 . V_12 ,
V_71 -> V_55 . V_12 ) ) )
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
F_28 ( & V_70 -> V_55 . V_12 ,
V_71 -> V_55 . V_12 ) ;
if ( V_70 -> V_55 . V_66 == V_74 ) {
if ( F_29 ( V_71 ) )
F_30 ( V_70 ) ;
F_16 ( V_70 , V_75 ) ;
}
}
}
static struct V_53 * F_31 ( struct V_77 * V_78 )
{
struct V_53 * V_12 ;
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
V_12 = F_36 ( sizeof( struct V_53 ) ,
V_87 | V_88 ) ;
if ( ! V_12 )
goto V_91;
V_12 -> V_61 = F_36 ( F_40 ( V_81 ) ,
V_87 | V_88 ) ;
if ( ! V_12 -> V_61 )
goto V_92;
V_56 = F_39 ( V_80 , V_78 -> V_82 , V_12 -> V_61 -> V_93 , & V_81 ) ;
if ( V_56 )
goto V_94;
F_41 ( V_80 ) ;
F_42 ( & V_12 -> V_95 , 1 ) ;
V_12 -> V_61 -> V_82 = V_81 ;
F_43 ( V_12 -> V_61 ) ;
return V_12 ;
V_94:
F_41 ( V_12 -> V_61 ) ;
V_92:
F_41 ( V_12 ) ;
V_91:
F_41 ( V_80 ) ;
return F_32 ( V_56 ) ;
}
static struct V_53 *
F_44 ( const char T_4 * V_96 )
{
struct V_77 V_78 ;
struct V_53 * V_12 = F_32 ( - V_90 ) ;
#ifdef F_45
if ( F_46 () ) {
struct V_97 V_98 ;
if ( F_37 ( & V_98 , V_96 , sizeof( V_98 ) ) )
goto V_99;
V_78 . V_82 = V_98 . V_82 ;
V_78 . V_12 = F_47 ( V_98 . V_12 ) ;
} else
#endif
if ( F_37 ( & V_78 , V_96 , sizeof( V_78 ) ) )
goto V_99;
V_12 = F_31 ( & V_78 ) ;
V_99:
return V_12 ;
}
static long F_48 ( unsigned int V_100 ,
struct V_53 * V_12 )
{
unsigned long V_101 ;
struct V_53 * V_102 ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_101 = V_12 -> V_61 -> V_82 ;
for ( V_102 = V_5 -> V_55 . V_12 ; V_102 ; V_102 = V_102 -> V_59 )
V_101 += V_102 -> V_61 -> V_82 + 4 ;
if ( V_101 > V_103 )
return - V_89 ;
if ( V_100 & V_104 ) {
int V_56 ;
V_56 = F_20 () ;
if ( V_56 )
return V_56 ;
}
V_12 -> V_59 = V_5 -> V_55 . V_12 ;
V_5 -> V_55 . V_12 = V_12 ;
if ( V_100 & V_104 )
F_25 () ;
return 0 ;
}
void F_26 ( struct V_3 * V_105 )
{
struct V_53 * V_106 = V_105 -> V_55 . V_12 ;
if ( ! V_106 )
return;
F_49 ( & V_106 -> V_95 ) ;
}
static inline void F_50 ( struct V_53 * V_12 )
{
if ( V_12 ) {
F_51 ( V_12 -> V_61 ) ;
F_41 ( V_12 ) ;
}
}
void F_27 ( struct V_3 * V_105 )
{
struct V_53 * V_106 = V_105 -> V_55 . V_12 ;
while ( V_106 && F_52 ( & V_106 -> V_95 ) ) {
struct V_53 * V_107 = V_106 ;
V_106 = V_106 -> V_59 ;
F_50 ( V_107 ) ;
}
}
static void F_53 ( int V_52 , int V_108 )
{
struct V_109 V_110 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_111 = V_112 ;
V_110 . V_113 = V_114 ;
V_110 . V_115 = ( void T_4 * ) F_6 ( V_5 ) ;
V_110 . V_116 = V_108 ;
V_110 . V_117 = F_4 () ;
V_110 . V_118 = V_52 ;
F_54 ( V_112 , & V_110 , V_5 ) ;
}
int F_55 ( int V_119 )
{
int V_120 = 0 ;
int * V_52 ;
T_2 V_56 ;
F_56 () ;
switch ( V_5 -> V_55 . V_66 ) {
case V_121 :
V_52 = V_122 ;
#ifdef F_45
if ( F_46 () )
V_52 = V_123 ;
#endif
do {
if ( * V_52 == V_119 )
return 0 ;
} while ( * ++ V_52 );
V_120 = V_124 ;
V_56 = V_58 ;
break;
#ifdef F_57
case V_75 : {
int V_125 ;
struct V_6 * V_7 = F_2 ( V_5 ) ;
V_56 = F_8 ( V_119 ) ;
V_125 = V_56 & V_126 ;
V_56 &= V_62 ;
switch ( V_56 ) {
case V_127 :
F_58 ( V_5 , V_7 ,
- V_125 , 0 ) ;
goto V_128;
case V_129 :
F_59 ( V_5 , V_7 ) ;
F_53 ( V_119 , V_125 ) ;
goto V_128;
case V_130 :
if ( ! F_60 ( V_5 , V_131 ) ) {
F_58 ( V_5 , V_7 ,
- V_132 , 0 ) ;
goto V_128;
}
F_61 ( V_131 , V_125 ) ;
if ( F_62 ( V_5 ) )
break;
if ( F_3 ( V_5 , V_7 ) < 0 )
goto V_128;
return 0 ;
case V_57 :
return 0 ;
case V_58 :
default:
break;
}
V_120 = V_112 ;
break;
}
#endif
default:
F_63 () ;
}
#ifdef F_64
F_65 () ;
#endif
F_66 ( V_119 , V_120 , V_56 ) ;
F_67 ( V_120 ) ;
#ifdef F_57
V_128:
F_66 ( V_119 , V_120 , V_56 ) ;
#endif
return - 1 ;
}
long F_68 ( void )
{
return V_5 -> V_55 . V_66 ;
}
static long F_69 ( void )
{
const unsigned long V_63 = V_121 ;
long V_56 = - V_22 ;
F_70 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_99;
#ifdef F_71
F_72 () ;
#endif
F_16 ( V_5 , V_63 ) ;
V_56 = 0 ;
V_99:
F_73 ( & V_5 -> V_64 -> V_65 ) ;
return V_56 ;
}
static long F_74 ( unsigned int V_100 ,
const char T_4 * V_12 )
{
const unsigned long V_63 = V_75 ;
struct V_53 * V_133 = NULL ;
long V_56 = - V_22 ;
if ( V_100 & ~ V_134 )
return - V_22 ;
V_133 = F_44 ( V_12 ) ;
if ( F_75 ( V_133 ) )
return F_76 ( V_133 ) ;
if ( V_100 & V_104 &&
F_77 ( & V_5 -> signal -> V_72 ) )
goto V_135;
F_70 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_99;
V_56 = F_48 ( V_100 , V_133 ) ;
if ( V_56 )
goto V_99;
V_133 = NULL ;
F_16 ( V_5 , V_63 ) ;
V_99:
F_73 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_100 & V_104 )
F_78 ( & V_5 -> signal -> V_72 ) ;
V_135:
F_50 ( V_133 ) ;
return V_56 ;
}
static inline long F_74 ( unsigned int V_100 ,
const char T_4 * V_12 )
{
return - V_22 ;
}
static long F_79 ( unsigned int V_136 , unsigned int V_100 ,
const char T_4 * V_137 )
{
switch ( V_136 ) {
case V_138 :
if ( V_100 != 0 || V_137 != NULL )
return - V_22 ;
return F_69 () ;
case V_139 :
return F_74 ( V_100 , V_137 ) ;
default:
return - V_22 ;
}
}
long F_80 ( unsigned long V_63 , char T_4 * V_12 )
{
unsigned int V_136 ;
char T_4 * V_137 ;
switch ( V_63 ) {
case V_121 :
V_136 = V_138 ;
V_137 = NULL ;
break;
case V_75 :
V_136 = V_139 ;
V_137 = V_12 ;
break;
default:
return - V_22 ;
}
return F_79 ( V_136 , 0 , V_137 ) ;
}
