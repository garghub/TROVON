static inline bool F_1 ( struct V_1 * V_1 )
{
return true ;
}
static inline void F_2 ( struct V_1 * V_1 )
{
}
static inline void F_3 ( bool V_2 )
{
}
static inline int F_4 ( enum V_3 V_4 ,
const T_1 * V_5 , unsigned int V_6 ,
T_1 * V_7 , unsigned int * V_8 )
{
struct V_9 * V_10 ;
int V_11 = - 1 ;
F_5 ( ! V_12 ) ;
V_10 = * F_6 ( V_12 , F_7 () ) ;
F_5 ( ! V_10 ) ;
switch ( V_4 ) {
case V_13 :
V_11 = F_8 ( V_10 , V_5 , V_6 , V_7 , V_8 ) ;
break;
case V_14 :
V_11 = F_9 ( V_10 , V_5 , V_6 , V_7 , V_8 ) ;
break;
default:
V_11 = - V_15 ;
}
F_10 () ;
return V_11 ;
}
static inline bool F_11 ( struct V_16 * V_17 )
{
return V_17 == & V_18 ;
}
static struct V_16 * F_12 ( T_2 V_19 )
{
struct V_16 * V_17 = & V_18 ;
if ( V_19 != V_20 ) {
if ( V_19 >= V_21 )
goto V_22;
V_17 = & V_23 [ V_19 ] ;
}
V_22:
return V_17 ;
}
struct V_24 * F_13 ( T_2 V_19 , T_2 V_25 )
{
struct V_24 * V_26 = NULL ;
struct V_16 * V_17 = NULL ;
V_17 = F_12 ( V_19 ) ;
if ( V_17 == NULL )
goto V_22;
if ( ! F_11 ( V_17 ) )
F_14 ( & V_17 -> V_27 ) ;
if ( V_25 < V_28 ) {
V_26 = V_17 -> V_29 [ V_25 ] ;
if ( V_26 != NULL )
F_14 ( & V_26 -> V_27 ) ;
}
V_22:
return V_26 ;
}
void F_15 ( struct V_24 * V_26 )
{
struct V_16 * V_17 = NULL ;
if ( V_26 == NULL )
F_16 () ;
V_17 = V_26 -> V_30 ;
F_17 ( & V_26 -> V_27 ) ;
if ( ! F_11 ( V_17 ) )
F_17 ( & V_17 -> V_27 ) ;
}
int F_18 ( T_2 V_19 )
{
struct V_16 * V_17 ;
int V_11 = - 1 ;
V_17 = F_12 ( V_19 ) ;
if ( V_17 == NULL )
goto V_22;
if ( V_17 -> V_31 )
goto V_22;
V_17 -> V_31 = 1 ;
V_11 = 0 ;
V_22:
return V_11 ;
}
static struct V_32 * F_19 ( struct V_24 * V_26 )
{
struct V_32 * V_33 = NULL ;
struct V_34 * V_35 ;
int V_36 ;
V_35 = & F_20 ( V_37 ) ;
for ( V_36 = 0 ; V_36 < F_21 ( V_35 -> V_38 ) ; V_36 ++ ) {
V_33 = V_35 -> V_38 [ V_36 ] ;
if ( V_33 != NULL ) {
V_35 -> V_38 [ V_36 ] = NULL ;
break;
}
}
F_5 ( V_33 == NULL ) ;
F_22 () ;
return V_33 ;
}
static void F_23 ( struct V_32 * V_33 ,
struct V_24 * V_26 )
{
F_24 () ;
F_25 ( V_39 , V_33 ) ;
}
static struct V_40 * F_26 ( struct V_24 * V_26 )
{
struct V_40 * V_41 = NULL ;
struct V_34 * V_35 ;
V_35 = & F_20 ( V_37 ) ;
V_41 = V_35 -> V_41 ;
F_5 ( V_41 == NULL ) ;
V_35 -> V_41 = NULL ;
F_27 () ;
return V_41 ;
}
static void F_28 ( struct V_40 * V_41 , struct V_24 * V_26 )
{
F_29 () ;
F_25 ( V_42 , V_41 ) ;
}
static bool F_30 ( struct V_1 * V_43 )
{
unsigned int V_44 ;
char * V_1 ;
V_1 = F_31 ( V_43 ) ;
for ( V_44 = 0 ; V_44 < V_45 / sizeof( * V_1 ) ; V_44 ++ ) {
if ( V_1 [ V_44 ] ) {
F_32 ( V_1 ) ;
return false ;
}
}
F_32 ( V_1 ) ;
return true ;
}
static void F_33 ( void * V_43 )
{
void * V_46 ;
struct V_1 * V_1 = (struct V_1 * ) V_43 ;
V_46 = F_31 ( V_1 ) ;
memset ( V_46 , 0 , V_45 ) ;
F_32 ( V_46 ) ;
F_34 ( V_1 ) ;
}
static struct V_1 * F_35 ( void )
{
struct V_1 * V_1 = F_36 ( V_47 ) ;
if ( V_1 != NULL )
F_37 () ;
return V_1 ;
}
static void F_38 ( struct V_1 * V_1 )
{
long V_48 ;
static long V_49 , V_50 ;
if ( V_1 == NULL )
F_16 () ;
F_39 ( V_1 ) ;
F_40 () ;
V_48 = F_41 () ;
if ( V_48 > V_49 )
V_49 = V_48 ;
if ( V_48 < V_50 )
V_50 = V_48 ;
#ifdef F_42
if ( V_48 > 2L || V_48 < - 2L ) {
}
#endif
}
static void * F_43 ( char * V_51 , T_3 V_52 , bool V_53 ,
struct V_54 * V_55 )
{
void * V_56 = NULL , * V_57 = V_51 ;
unsigned V_58 = V_52 ;
bool V_59 = false ;
struct V_1 * V_1 = (struct V_1 * ) ( V_51 ) , * V_60 ;
if ( F_30 ( V_1 ) ) {
V_58 = 0 ;
V_59 = true ;
F_44 () ;
goto V_61;
}
if ( ! V_53 ) {
F_45 ( V_1 , & V_57 , & V_58 ) ;
if ( V_58 > F_46 () ) {
F_47 () ;
goto V_22;
}
} else {
F_5 ( V_58 > F_46 () ) ;
}
V_56 = ( void * ) F_48 ( V_55 , true , V_57 , V_58 ) ;
if ( V_56 != NULL )
goto V_61;
V_60 = F_35 () ;
if ( V_60 != NULL )
goto V_62;
F_49 () ;
V_60 = F_50 () ;
if ( V_60 == NULL ) {
F_51 () ;
goto V_22;
}
F_52 () ;
V_62:
V_56 = ( void * ) F_53 ( V_55 , true , V_57 , V_58 , V_60 ) ;
F_5 ( V_56 == NULL ) ;
F_54 () ;
V_61:
F_55 ( V_58 ) ;
F_56 () ;
if ( V_63 && V_53 && ! V_59 )
F_57 ( true , 1 ) ;
if ( V_59 )
V_56 = ( void * ) V_64 ;
V_22:
return V_56 ;
}
static void * F_58 ( char * V_51 , T_3 V_52 , bool V_53 ,
struct V_54 * V_55 )
{
void * V_56 = NULL , * V_57 = V_51 ;
unsigned V_58 = V_52 ;
bool V_59 = false ;
struct V_1 * V_1 = (struct V_1 * ) ( V_51 ) , * V_60 ;
unsigned long V_65 ;
unsigned long V_66 , V_67 ;
if ( V_51 == NULL ) {
F_5 ( ! V_63 ) ;
goto V_68;
}
if ( F_30 ( V_1 ) ) {
V_58 = 0 ;
V_59 = true ;
F_44 () ;
goto V_61;
}
V_66 = V_69 ;
if ( ! V_53 )
F_45 ( V_1 , & V_57 , & V_58 ) ;
if ( V_58 > V_70 ) {
F_47 () ;
goto V_22;
}
if ( ( V_58 > V_71 ) && ( V_66 > 0 ) ) {
V_67 = V_72 ;
if ( ( long ) V_67 < 0 )
V_67 = 0 ;
V_65 = F_59 ( V_67 ,
V_66 ) ;
if ( V_65 > V_71 ) {
F_60 () ;
goto V_22;
}
}
V_68:
V_56 = ( void * ) F_48 ( V_55 , false , V_57 , V_58 ) ;
if ( V_56 != NULL )
goto V_61;
V_60 = F_35 () ;
if ( V_60 != NULL )
goto V_62;
F_49 () ;
V_60 = F_50 () ;
if ( V_60 == NULL ) {
F_61 () ;
goto V_22;
}
F_62 () ;
V_62:
V_56 = ( void * ) F_53 ( V_55 , false , V_57 , V_58 , V_60 ) ;
F_5 ( V_56 == NULL ) ;
F_63 () ;
V_61:
F_64 () ;
F_65 ( V_58 ) ;
if ( V_63 && V_53 && ! V_59 )
F_57 ( false , 1 ) ;
if ( V_59 )
V_56 = ( void * ) V_64 ;
V_22:
return V_56 ;
}
void * F_66 ( char * V_51 , unsigned int V_52 , bool V_53 ,
int V_73 , struct V_54 * V_55 )
{
void * V_56 = NULL ;
struct V_34 * V_35 ;
struct V_32 * V_33 ;
struct V_40 * V_41 ;
int V_36 ;
F_5 ( ! F_67 () ) ;
F_5 ( V_39 == NULL ) ;
F_5 ( V_42 == NULL ) ;
V_35 = & F_20 ( V_37 ) ;
for ( V_36 = 0 ; V_36 < F_21 ( V_35 -> V_38 ) ; V_36 ++ ) {
V_33 = V_35 -> V_38 [ V_36 ] ;
if ( V_33 == NULL ) {
V_33 = F_68 ( V_39 ,
V_47 ) ;
if ( F_69 ( V_33 == NULL ) ) {
F_70 () ;
goto V_22;
}
V_35 -> V_38 [ V_36 ] = V_33 ;
}
}
if ( V_35 -> V_41 == NULL ) {
V_41 = F_68 ( V_42 , V_47 ) ;
V_35 -> V_41 = V_41 ;
}
if ( F_69 ( V_35 -> V_41 == NULL ) ) {
F_70 () ;
goto V_22;
}
if ( V_73 )
V_56 = F_43 ( V_51 , V_52 , V_53 , V_55 ) ;
else
V_56 = F_58 ( V_51 , V_52 , V_53 , V_55 ) ;
V_22:
return V_56 ;
}
void F_71 ( void * V_56 , bool V_73 )
{
if ( V_56 != ( void * ) V_64 )
F_72 ( (struct V_74 * ) V_56 , V_73 ) ;
}
static void F_73 ( char * V_75 , unsigned int V_52 , char * V_76 )
{
int V_11 ;
unsigned int V_77 = V_45 ;
V_11 = F_4 ( V_14 , V_75 , V_52 ,
V_76 , & V_77 ) ;
F_5 ( V_11 ) ;
F_5 ( V_77 != V_45 ) ;
}
void F_74 ( char * V_75 , unsigned int V_52 ,
struct V_1 * V_78 )
{
char * V_76 = F_31 ( V_78 ) ;
F_73 ( V_75 , V_52 , V_76 ) ;
F_32 ( V_76 ) ;
}
static int F_75 ( char * V_51 , T_3 * V_79 , bool V_53 ,
void * V_56 , struct V_24 * V_26 ,
struct V_80 * V_81 , T_4 V_82 )
{
int V_11 ;
bool V_73 = ! F_76 ( V_26 ) ;
F_5 ( F_77 () ) ;
F_5 ( V_73 ) ;
F_5 ( F_78 ( V_56 ) ) ;
if ( V_56 == ( void * ) V_64 ) {
F_33 ( V_51 ) ;
if ( ! V_53 )
* V_79 = V_45 ;
return 0 ;
}
if ( V_53 )
V_11 = F_79 ( V_51 , (struct V_74 * ) V_56 ,
V_79 , V_73 ) ;
else {
V_11 = F_80 ( (struct V_1 * ) ( V_51 ) ,
(struct V_74 * ) V_56 , false ,
F_73 ) ;
* V_79 = V_45 ;
}
return V_11 ;
}
static int F_81 ( char * V_51 , T_3 * V_79 , bool V_53 ,
void * V_56 , struct V_24 * V_26 ,
struct V_80 * V_81 , T_4 V_82 )
{
int V_11 = 0 ;
bool V_73 = ! F_76 ( V_26 ) , V_59 = false ;
struct V_1 * V_1 = NULL ;
unsigned int V_83 , V_84 ;
F_5 ( F_77 () ) ;
F_5 ( F_78 ( V_56 ) ) ;
if ( V_56 == ( void * ) V_64 ) {
F_33 ( V_51 ) ;
V_59 = true ;
V_83 = 0 ;
V_84 = 1 ;
if ( ! V_53 )
* V_79 = V_45 ;
F_82 () ;
goto V_85;
}
if ( V_53 )
V_11 = F_79 ( V_51 , (struct V_74 * ) V_56 ,
V_79 , V_73 ) ;
else {
V_11 = F_80 ( (struct V_1 * ) ( V_51 ) ,
(struct V_74 * ) V_56 , V_73 ,
F_73 ) ;
* V_79 = V_45 ;
}
V_1 = F_83 ( (struct V_74 * ) V_56 , V_73 ,
& V_83 , & V_84 ) ;
V_85:
if ( V_73 ) {
if ( V_1 )
F_84 () ;
F_85 ( V_84 ) ;
F_86 ( V_83 ) ;
} else {
if ( V_1 )
F_87 () ;
F_88 ( V_84 ) ;
F_89 ( V_83 ) ;
}
if ( ! F_11 ( V_26 -> V_30 ) && ! V_59 )
F_57 ( V_73 , - 1 ) ;
if ( V_1 && ! V_59 )
F_38 ( V_1 ) ;
return V_11 ;
}
static void F_90 ( void * V_56 , struct V_24 * V_26 ,
struct V_80 * V_81 , T_4 V_82 , bool V_86 )
{
struct V_1 * V_1 = NULL ;
unsigned int V_83 , V_84 ;
bool V_59 = false ;
F_5 ( F_77 () ) ;
if ( V_56 == ( void * ) V_64 ) {
V_59 = true ;
V_83 = 0 ;
V_84 = 1 ;
F_82 () ;
}
if ( F_78 ( V_56 ) && ! V_59 ) {
F_5 ( ! V_63 ) ;
V_56 = F_91 ( V_56 , V_26 , V_81 , V_82 , V_86 ) ;
if ( V_56 == NULL )
return;
}
if ( F_92 ( V_26 ) ) {
if ( ! V_59 )
V_1 = F_83 ( (struct V_74 * ) V_56 ,
true , & V_83 , & V_84 ) ;
if ( V_1 )
F_84 () ;
F_85 ( V_84 ) ;
F_86 ( V_83 ) ;
} else {
if ( ! V_59 )
V_1 = F_83 ( (struct V_74 * ) V_56 ,
false , & V_83 , & V_84 ) ;
if ( V_1 )
F_87 () ;
F_88 ( V_84 ) ;
F_89 ( V_83 ) ;
}
if ( ! F_11 ( V_26 -> V_30 ) && ! V_59 )
F_57 ( F_92 ( V_26 ) , - 1 ) ;
if ( V_1 && ! V_59 )
F_38 ( V_1 ) ;
}
static void F_45 ( struct V_1 * V_87 , void * * V_88 , unsigned * V_89 )
{
int V_11 ;
unsigned char * V_90 = F_20 ( V_91 ) ;
char * V_75 ;
F_5 ( ! F_67 () ) ;
F_5 ( V_90 == NULL ) ;
* V_89 = V_45 << V_92 ;
V_75 = F_31 ( V_87 ) ;
F_93 () ;
V_11 = F_4 ( V_13 , V_75 , V_45 , V_90 ,
V_89 ) ;
F_5 ( V_11 ) ;
* V_88 = V_90 ;
F_32 ( V_75 ) ;
}
static int F_94 ( int V_93 )
{
struct V_9 * V_10 ;
V_10 = F_95 ( V_94 , 0 , 0 ) ;
if ( F_96 ( V_10 ) )
return V_95 ;
* F_6 ( V_12 , V_93 ) = V_10 ;
return V_96 ;
}
static void F_97 ( int V_93 )
{
struct V_9 * V_10 ;
V_10 = * F_6 ( V_12 , V_93 ) ;
F_98 ( V_10 ) ;
* F_6 ( V_12 , V_93 ) = NULL ;
}
static int F_99 ( struct V_97 * V_98 ,
unsigned long V_99 , void * V_100 )
{
int V_11 , V_36 , V_93 = ( long ) V_100 ;
struct V_34 * V_35 ;
switch ( V_99 ) {
case V_101 :
V_11 = F_94 ( V_93 ) ;
if ( V_11 != V_96 ) {
F_100 ( L_1 ,
V_102 ) ;
return V_11 ;
}
F_101 ( V_91 , V_93 ) = ( void * ) F_102 (
V_103 | V_104 , V_92 ) ;
if ( V_63 )
F_103 ( V_93 ) ;
break;
case V_105 :
case V_106 :
F_97 ( V_93 ) ;
F_104 ( ( unsigned long ) F_101 ( V_91 , V_93 ) ,
V_92 ) ;
F_101 ( V_91 , V_93 ) = NULL ;
V_35 = & F_101 ( V_37 , V_93 ) ;
for ( V_36 = 0 ; V_36 < F_21 ( V_35 -> V_38 ) ; V_36 ++ ) {
if ( V_35 -> V_38 [ V_36 ] )
F_25 ( V_39 ,
V_35 -> V_38 [ V_36 ] ) ;
}
if ( V_35 -> V_41 ) {
F_25 ( V_42 , V_35 -> V_41 ) ;
V_35 -> V_41 = NULL ;
}
if ( V_63 )
F_105 ( V_93 ) ;
break;
default:
break;
}
return V_96 ;
}
static struct V_1 * F_50 ( void )
{
struct V_1 * V_1 ;
unsigned int V_83 = 0 , V_84 = 0 ;
V_1 = F_106 ( & V_83 , & V_84 ) ;
if ( V_1 == NULL )
goto V_22;
F_86 ( V_83 ) ;
F_85 ( V_84 ) ;
F_107 ( V_84 ) ;
F_84 () ;
F_108 () ;
V_22:
return V_1 ;
}
static inline void F_109 ( void )
{
V_107 =
F_110 ( & V_108 ) ;
}
static inline void F_111 ( void )
{
V_107 =
F_112 ( & V_108 ) ;
}
static void F_113 ( struct V_109 * V_109 , int V_110 )
{
F_114 ( V_109 , V_110 ) ;
F_111 () ;
V_111 ++ ;
}
static int F_115 ( int type , T_5 V_112 ,
struct V_1 * V_113 )
{
struct V_1 * V_114 ;
T_6 V_115 = F_116 ( type , V_112 ) ;
int V_110 ;
F_5 ( V_113 == NULL ) ;
do {
V_114 = F_117 ( & V_116 , V_115 . V_117 ) ;
if ( V_114 )
return 0 ;
V_110 = F_118 ( V_103 ) ;
if ( V_110 )
break;
V_110 = F_119 ( V_115 ) ;
if ( V_110 == - V_118 ) {
F_120 () ;
continue;
}
if ( V_110 ) {
F_120 () ;
break;
}
F_121 ( V_113 ) ;
F_122 ( V_113 ) ;
V_110 = F_123 ( V_113 , V_115 ) ;
if ( F_124 ( ! V_110 ) ) {
F_120 () ;
F_125 ( V_113 ) ;
return 1 ;
}
F_120 () ;
F_126 ( V_113 ) ;
F_127 ( V_113 ) ;
F_128 ( V_115 , NULL ) ;
} while ( V_110 != - V_119 );
return - V_119 ;
}
static int F_129 ( int type , T_5 V_112 ,
struct V_1 * V_60 )
{
struct V_1 * V_1 = V_60 ;
int V_11 ;
struct V_120 V_121 = {
. V_122 = V_123 ,
} ;
V_11 = F_115 ( type , V_112 , V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
else if ( V_11 == 0 ) {
F_130 ( type , V_112 ) ;
return 1 ;
}
F_5 ( ! V_124 ) ;
F_131 ( V_1 ) ;
F_132 ( V_1 ) ;
F_133 ( V_1 ) ;
( void ) F_134 ( V_1 , & V_121 , F_113 ) ;
F_135 ( V_1 ) ;
F_109 () ;
return 0 ;
}
static int F_136 ( void )
{
struct V_54 V_55 [ 2 ] ;
int V_11 = 0 ;
int V_125 , V_126 ;
unsigned type ;
struct V_1 * V_127 = NULL , * V_128 = NULL ;
struct V_1 * V_129 = NULL , * V_130 = NULL ;
struct V_1 * V_131 = NULL , * V_132 = NULL ;
struct V_1 * V_133 = NULL , * V_134 = NULL ;
T_5 V_112 ;
V_127 = F_36 ( V_47 ) ;
V_128 = F_36 ( V_47 ) ;
if ( V_127 == NULL )
V_129 = F_50 () ;
if ( V_128 == NULL )
V_130 = F_50 () ;
if ( ( V_129 == NULL || V_130 == NULL ) &&
F_137 ( & V_108 ) >
V_135 ) {
goto V_136;
}
if ( V_127 == NULL && V_129 == NULL )
V_131 = F_36 ( V_103 ) ;
if ( V_128 == NULL && V_130 == NULL )
V_132 = F_36 ( V_103 ) ;
if ( V_131 == NULL || V_132 == NULL )
goto V_136;
V_125 = F_138 ( & V_55 [ 0 ] , NULL , NULL , false ) ;
if ( V_125 == 0 ) {
V_11 = - V_137 ;
goto V_136;
}
F_139 ( V_55 [ 0 ] . V_81 , V_55 [ 0 ] . V_82 , & type , & V_112 ) ;
V_133 = ( V_127 != NULL ) ? V_127 :
( ( V_131 != NULL ) ? V_131 : V_129 ) ;
V_126 = F_129 ( type , V_112 , V_133 ) ;
if ( V_126 < 0 ) {
V_11 = - V_119 ;
goto V_136;
}
if ( V_129 != NULL )
V_138 =
F_110 ( & V_139 ) ;
if ( V_126 == 0 ) {
V_127 = NULL ;
V_131 = NULL ;
V_129 = NULL ;
}
if ( V_125 < 2 )
goto V_136;
F_139 ( V_55 [ 1 ] . V_81 , V_55 [ 1 ] . V_82 , & type , & V_112 ) ;
V_134 = ( V_128 != NULL ) ? V_128 :
( ( V_132 != NULL ) ? V_132 : V_130 ) ;
V_126 = F_129 ( type , V_112 , V_134 ) ;
if ( V_126 < 0 ) {
V_11 = - V_119 ;
goto V_136;
}
if ( V_130 != NULL )
V_138 =
F_110 ( & V_139 ) ;
if ( V_126 == 0 ) {
V_128 = NULL ;
V_132 = NULL ;
V_130 = NULL ;
}
V_136:
if ( V_127 != NULL )
F_135 ( V_127 ) ;
if ( V_128 != NULL )
F_135 ( V_128 ) ;
if ( V_131 != NULL )
F_135 ( V_131 ) ;
if ( V_132 != NULL )
F_135 ( V_132 ) ;
if ( V_129 != NULL )
F_38 ( V_129 ) ;
if ( V_130 != NULL )
F_38 ( V_130 ) ;
return V_11 ;
}
static int F_140 ( struct V_140 * V_141 ,
struct V_142 * V_143 )
{
static bool V_144 ;
int V_11 = - 1 ;
int V_145 = V_143 -> V_146 ;
int V_147 = 0 ;
int V_148 = 0 ;
struct V_1 * V_1 ;
int V_149 , V_150 ;
if ( V_145 <= 0 )
goto V_151;
if ( V_144 )
goto V_151;
V_144 = true ;
V_152 =
F_141 ( V_153 + V_154 ) ;
V_155 =
F_141 ( V_153 + V_156 ) ;
V_149 = V_152 +
V_155 ;
if ( V_157 > V_149 )
V_147 = V_157 - V_149 ;
else
V_147 = 0 ;
while ( V_147 -- > 0 ) {
V_1 = F_50 () ;
if ( V_1 == NULL )
break;
F_38 ( V_1 ) ;
}
V_158 =
F_141 ( V_153 + V_159 ) ;
V_160 =
F_141 ( V_153 + V_161 ) ;
V_150 = V_158 +
V_160 ;
if ( V_162 > V_150 )
V_148 = V_162 - V_150 ;
else
V_148 = 0 ;
while ( V_148 -- > 0 ) {
#ifdef F_142
int V_126 ;
V_126 = F_136 () ;
if ( V_126 == - V_119 )
#endif
break;
}
V_144 = false ;
V_151:
V_152 =
F_141 ( V_153 + V_154 ) ;
V_155 =
F_141 ( V_153 + V_156 ) ;
V_11 = V_157 - V_152 +
V_155 ;
if ( V_11 < 0 )
V_11 = 0 ;
return V_11 ;
}
int F_143 ( int V_19 , int V_163 , struct V_80 * V_164 ,
T_4 V_82 , void * V_1 ,
unsigned int V_52 , bool V_53 , int V_165 )
{
struct V_24 * V_26 ;
struct V_54 V_55 ;
int V_11 = - 1 ;
void * V_56 = NULL ;
F_5 ( ! F_67 () ) ;
V_26 = F_13 ( V_19 , V_163 ) ;
if ( F_69 ( V_26 == NULL ) )
goto V_22;
if ( ! V_166 ) {
V_11 = 0 ;
V_55 . V_167 = V_19 ;
V_55 . V_163 = V_163 ;
V_55 . V_81 = * V_164 ;
V_55 . V_82 = V_82 ;
V_56 = F_66 ( ( char * ) V_1 , V_52 , V_53 ,
V_165 , & V_55 ) ;
if ( V_56 == NULL ) {
V_11 = - V_119 ;
if ( V_165 )
F_144 () ;
else
F_145 () ;
} else {
if ( V_63 )
F_146 ( V_26 ) ;
V_11 = F_147 ( V_26 , V_164 , V_82 , 0 , V_56 ) ;
if ( V_11 < 0 )
F_16 () ;
}
F_15 ( V_26 ) ;
} else {
F_148 () ;
if ( V_63 )
F_146 ( V_26 ) ;
if ( F_137 ( & V_26 -> V_168 ) > 0 )
( void ) F_149 ( V_26 , V_164 , V_82 ) ;
F_15 ( V_26 ) ;
}
V_22:
return V_11 ;
}
int F_150 ( int V_19 , int V_163 , struct V_80 * V_164 ,
T_4 V_82 , void * V_1 ,
T_3 * V_79 , bool V_53 , int V_169 )
{
struct V_24 * V_26 ;
int V_11 = - 1 ;
bool V_73 ;
if ( ! V_53 ) {
F_5 ( F_67 () ) ;
F_5 ( F_151 () ) ;
}
V_26 = F_13 ( V_19 , V_163 ) ;
V_73 = F_92 ( V_26 ) ;
if ( F_124 ( V_26 != NULL ) ) {
if ( F_137 ( & V_26 -> V_168 ) > 0 )
V_11 = F_152 ( V_26 , V_164 , V_82 , ( char * ) ( V_1 ) ,
V_79 , V_53 , V_169 ) ;
F_15 ( V_26 ) ;
}
F_153 ( ( ! F_92 ( V_26 ) && ( V_11 != 0 ) ) ,
L_2
L_3 ) ;
#ifdef F_154
if ( V_11 != 0 && V_11 != - 1 && ! ( V_11 == - V_15 && F_92 ( V_26 ) ) )
F_100 ( L_4 , V_11 ) ;
#endif
return V_11 ;
}
int F_155 ( int V_19 , int V_163 ,
struct V_80 * V_164 , T_4 V_82 )
{
struct V_24 * V_26 ;
int V_11 = - 1 ;
unsigned long V_170 ;
F_156 ( V_170 ) ;
F_157 () ;
V_26 = F_13 ( V_19 , V_163 ) ;
if ( V_63 )
F_146 ( V_26 ) ;
if ( F_124 ( V_26 != NULL ) ) {
if ( F_137 ( & V_26 -> V_168 ) > 0 )
V_11 = F_149 ( V_26 , V_164 , V_82 ) ;
F_15 ( V_26 ) ;
}
if ( V_11 >= 0 )
F_158 () ;
F_159 ( V_170 ) ;
return V_11 ;
}
int F_160 ( int V_19 , int V_163 ,
struct V_80 * V_164 )
{
struct V_24 * V_26 ;
int V_11 = - 1 ;
unsigned long V_170 ;
F_156 ( V_170 ) ;
F_161 () ;
V_26 = F_13 ( V_19 , V_163 ) ;
if ( V_63 )
F_146 ( V_26 ) ;
if ( F_124 ( V_26 != NULL ) ) {
if ( F_137 ( & V_26 -> V_168 ) > 0 )
V_11 = F_162 ( V_26 , V_164 ) ;
F_15 ( V_26 ) ;
}
if ( V_11 >= 0 )
F_163 () ;
F_159 ( V_170 ) ;
return V_11 ;
}
static int F_164 ( int V_19 , int V_163 )
{
struct V_24 * V_26 = NULL ;
struct V_16 * V_17 = NULL ;
int V_11 = - 1 ;
if ( V_163 < 0 )
goto V_22;
if ( V_19 == V_20 )
V_17 = & V_18 ;
else if ( ( unsigned int ) V_19 < V_21 )
V_17 = & V_23 [ V_19 ] ;
if ( V_17 == NULL )
goto V_22;
F_14 ( & V_17 -> V_27 ) ;
V_26 = V_17 -> V_29 [ V_163 ] ;
if ( V_26 == NULL )
goto V_22;
V_17 -> V_29 [ V_163 ] = NULL ;
while ( F_137 ( & V_26 -> V_27 ) != 0 )
;
F_17 ( & V_17 -> V_27 ) ;
F_165 () ;
V_11 = F_166 ( V_26 ) ;
F_167 () ;
F_168 ( V_26 ) ;
if ( V_19 == V_20 )
F_169 ( L_5 , V_102 , V_163 ) ;
else
F_169 ( L_6 ,
V_102 , V_163 , V_19 ) ;
V_22:
return V_11 ;
}
int F_170 ( T_2 V_19 , T_4 V_170 )
{
int V_25 = - 1 ;
struct V_24 * V_26 ;
struct V_16 * V_17 = NULL ;
if ( V_19 == V_20 )
V_17 = & V_18 ;
else if ( ( unsigned int ) V_19 < V_21 )
V_17 = & V_23 [ V_19 ] ;
if ( V_17 == NULL )
goto V_22;
F_14 ( & V_17 -> V_27 ) ;
V_26 = F_171 ( sizeof( struct V_24 ) , V_171 ) ;
if ( V_26 == NULL )
goto V_22;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ )
if ( V_17 -> V_29 [ V_25 ] == NULL )
break;
if ( V_25 >= V_28 ) {
F_169 ( L_7 , V_102 ) ;
F_168 ( V_26 ) ;
V_25 = - 1 ;
goto V_22;
}
F_172 ( & V_26 -> V_27 , 0 ) ;
V_26 -> V_30 = V_17 ;
V_26 -> V_163 = V_25 ;
F_173 ( V_26 , V_170 ) ;
V_17 -> V_29 [ V_25 ] = V_26 ;
if ( V_19 == V_20 )
F_169 ( L_8 , V_102 ,
V_170 & V_172 ? L_9 : L_10 ,
V_25 ) ;
else
F_169 ( L_11 , V_102 ,
V_170 & V_172 ? L_9 : L_10 ,
V_25 , V_19 ) ;
V_22:
if ( V_17 != NULL )
F_17 ( & V_17 -> V_27 ) ;
return V_25 ;
}
static int F_174 ( T_4 V_170 )
{
return F_170 ( V_20 , V_170 ) ;
}
int F_175 ( unsigned int V_19 , unsigned int V_163 , bool V_73 )
{
struct V_24 * V_26 ;
struct V_16 * V_17 = NULL ;
T_4 V_170 = V_73 ? 0 : V_172 ;
int V_11 = - 1 ;
F_5 ( ! V_63 ) ;
if ( V_19 == V_20 )
goto V_22;
if ( V_163 >= V_28 )
goto V_22;
if ( V_19 >= V_21 )
goto V_22;
V_17 = & V_23 [ V_19 ] ;
if ( ( V_73 && V_173 ) || ( ! V_73 && V_174 ) ) {
F_100 ( L_12 ) ;
goto V_22;
}
if ( ! V_17 -> V_31 ) {
if ( F_18 ( V_19 ) ) {
F_100 ( L_13 ) ;
goto V_22;
}
V_17 = & V_23 [ V_19 ] ;
}
F_14 ( & V_17 -> V_27 ) ;
V_26 = V_17 -> V_29 [ V_163 ] ;
if ( V_26 != NULL ) {
if ( V_26 -> V_175 && V_73 ) {
F_100 ( L_14 ) ;
goto V_22;
}
V_11 = 0 ;
goto V_22;
}
V_26 = F_171 ( sizeof( struct V_24 ) , V_103 ) ;
if ( V_26 == NULL )
goto V_22;
F_172 ( & V_26 -> V_27 , 0 ) ;
V_26 -> V_30 = V_17 ;
V_26 -> V_163 = V_163 ;
F_173 ( V_26 , V_170 ) ;
V_17 -> V_29 [ V_163 ] = V_26 ;
F_169 ( L_15 ,
V_102 , V_170 & V_172 ? L_9 : L_10 ,
V_163 , V_19 ) ;
V_11 = 0 ;
V_22:
if ( V_17 != NULL )
F_17 ( & V_17 -> V_27 ) ;
return V_11 ;
}
static void F_176 ( int V_163 ,
struct V_176 V_177 ,
T_5 V_82 , struct V_1 * V_1 )
{
T_7 V_178 = ( T_7 ) V_82 ;
struct V_80 V_81 = * (struct V_80 * ) & V_177 ;
if ( ! V_179 && ! F_1 ( V_1 ) ) {
F_177 () ;
return;
}
if ( F_124 ( V_178 == V_82 ) )
( void ) F_143 ( V_20 , V_163 , & V_81 , V_82 ,
V_1 , V_45 , false , 1 ) ;
}
static int F_178 ( int V_163 ,
struct V_176 V_177 ,
T_5 V_82 , struct V_1 * V_1 )
{
T_7 V_178 = ( T_7 ) V_82 ;
struct V_80 V_81 = * (struct V_80 * ) & V_177 ;
T_3 V_52 ;
int V_11 = - 1 ;
if ( F_124 ( V_178 == V_82 ) ) {
V_11 = F_150 ( V_20 , V_163 , & V_81 , V_82 ,
V_1 , & V_52 , false , 0 ) ;
F_5 ( V_11 >= 0 && V_52 != V_45 ) ;
if ( V_11 == 0 )
F_2 ( V_1 ) ;
}
return V_11 ;
}
static void F_179 ( int V_163 ,
struct V_176 V_177 ,
T_5 V_82 )
{
T_7 V_178 = ( T_7 ) V_82 ;
struct V_80 V_81 = * (struct V_80 * ) & V_177 ;
if ( F_124 ( V_178 == V_82 ) )
( void ) F_155 ( V_20 , V_163 , & V_81 , V_178 ) ;
}
static void F_180 ( int V_163 ,
struct V_176 V_177 )
{
struct V_80 V_81 = * (struct V_80 * ) & V_177 ;
( void ) F_160 ( V_20 , V_163 , & V_81 ) ;
}
static void F_181 ( int V_163 )
{
if ( V_163 >= 0 )
( void ) F_164 ( V_20 , V_163 ) ;
}
static int F_182 ( T_3 V_180 )
{
F_5 ( sizeof( struct V_176 ) !=
sizeof( struct V_80 ) ) ;
F_5 ( V_180 != V_45 ) ;
return F_174 ( 0 ) ;
}
static int F_183 ( char * V_181 , T_3 V_180 )
{
F_5 ( sizeof( struct V_176 ) !=
sizeof( struct V_80 ) ) ;
F_5 ( V_180 != V_45 ) ;
return F_174 ( 0 ) ;
}
struct V_182 * F_184 ( void )
{
struct V_182 * V_183 =
F_185 ( & V_184 ) ;
return V_183 ;
}
static inline struct V_80 F_186 ( unsigned type , T_7 V_178 )
{
struct V_80 V_81 = { . V_81 = { 0 } } ;
V_81 . V_81 [ 0 ] = F_187 ( type , V_178 ) ;
return V_81 ;
}
static void F_139 ( struct V_80 V_81 , T_7 V_82 ,
unsigned * type , T_5 * V_112 )
{
* type = ( unsigned ) ( V_81 . V_81 [ 0 ] >> V_185 ) ;
* V_112 = ( T_5 ) ( ( V_82 << V_185 ) |
( V_81 . V_81 [ 0 ] & V_186 ) ) ;
}
static int F_188 ( unsigned type , T_5 V_112 ,
struct V_1 * V_1 )
{
T_8 V_187 = ( T_8 ) V_112 ;
T_7 V_178 = ( T_7 ) V_112 ;
struct V_80 V_81 = F_186 ( type , V_178 ) ;
int V_11 = - 1 ;
unsigned long V_170 ;
F_5 ( ! F_189 ( V_1 ) ) ;
if ( ! V_188 && ! F_1 ( V_1 ) ) {
F_190 () ;
V_11 = - V_189 ;
goto V_22;
}
if ( F_124 ( V_187 == V_178 ) ) {
F_156 ( V_170 ) ;
V_11 = F_143 ( V_20 , V_190 ,
& V_81 , F_191 ( V_178 ) ,
V_1 , V_45 , false , 0 ) ;
F_159 ( V_170 ) ;
}
V_22:
return V_11 ;
}
static int F_192 ( unsigned type , T_5 V_112 ,
struct V_1 * V_1 )
{
T_8 V_187 = ( T_8 ) V_112 ;
T_7 V_178 = ( T_7 ) V_112 ;
struct V_80 V_81 = F_186 ( type , V_178 ) ;
T_3 V_52 ;
int V_11 = - 1 , V_169 ;
if ( V_124 )
V_169 = 1 ;
else
V_169 = - 1 ;
F_5 ( ! F_189 ( V_1 ) ) ;
if ( F_124 ( V_187 == V_178 ) ) {
V_11 = F_150 ( V_20 , V_190 ,
& V_81 , F_191 ( V_178 ) ,
V_1 , & V_52 , false , V_169 ) ;
F_5 ( V_11 >= 0 && V_52 != V_45 ) ;
}
return V_11 ;
}
static void F_193 ( unsigned type , T_5 V_112 )
{
T_8 V_187 = ( T_8 ) V_112 ;
T_7 V_178 = ( T_7 ) V_112 ;
struct V_80 V_81 = F_186 ( type , V_178 ) ;
if ( F_124 ( V_187 == V_178 ) )
( void ) F_155 ( V_20 , V_190 ,
& V_81 , F_191 ( V_178 ) ) ;
}
static void F_194 ( unsigned type )
{
struct V_80 V_81 ;
int V_178 ;
for ( V_178 = V_186 ; V_178 >= 0 ; V_178 -- ) {
V_81 = F_186 ( type , V_178 ) ;
( void ) F_160 ( V_20 ,
V_190 , & V_81 ) ;
}
}
static void F_195 ( unsigned V_191 )
{
if ( V_190 < 0 )
V_190 =
F_174 ( V_172 ) ;
}
struct V_192 * F_196 ( void )
{
struct V_192 * V_183 =
F_197 ( & V_193 ) ;
return V_183 ;
}
static int T_9 F_198 ( char * V_194 )
{
V_195 = true ;
return 1 ;
}
static int T_9 F_199 ( char * V_194 )
{
V_195 = true ;
#ifdef F_200
V_63 = true ;
#endif
return 1 ;
}
static int T_9 F_201 ( char * V_194 )
{
V_173 = true ;
return 1 ;
}
static int T_9 F_202 ( char * V_194 )
{
V_174 = true ;
return 1 ;
}
static int T_9 F_203 ( char * V_194 )
{
V_124 = false ;
return 1 ;
}
static int T_9 F_204 ( char * V_194 )
{
V_188 = true ;
return 1 ;
}
static int T_9 F_205 ( char * V_194 )
{
V_179 = true ;
return 1 ;
}
static int T_9 F_206 ( char * V_194 )
{
F_207 ( V_94 , V_194 , sizeof( V_94 ) ) ;
V_195 = true ;
return 1 ;
}
static int F_208 ( void )
{
int V_11 = 0 ;
#ifdef F_209
V_11 = F_210 ( V_94 , 0 , 0 ) ;
if ( ! V_11 ) {
V_11 = - 1 ;
goto V_22;
}
#else
if ( * V_94 != '\0' ) {
V_11 = F_210 ( V_94 , 0 , 0 ) ;
if ( ! V_11 ) {
F_169 ( L_16 ,
V_94 ) ;
V_11 = 1 ;
goto V_22;
}
}
if ( ! V_11 )
strcpy ( V_94 , L_17 ) ;
V_11 = F_210 ( V_94 , 0 , 0 ) ;
if ( ! V_11 ) {
V_11 = 1 ;
goto V_22;
}
#endif
F_169 ( L_18 , V_94 ) ;
V_11 = 0 ;
V_12 = F_211 ( struct V_9 * ) ;
if ( ! V_12 )
V_11 = 1 ;
V_22:
return V_11 ;
}
static int F_212 ( void )
{
int V_11 = 0 ;
#ifdef F_209
V_195 = 1 ;
#endif
if ( V_63 ) {
V_102 = L_19 ;
F_213 ( & V_196 ) ;
}
F_214 () ;
if ( V_195 ) {
unsigned int V_93 ;
F_215 ( & V_197 ) ;
F_216 ( & V_196 ) ;
V_11 = F_217 ( & V_198 ) ;
if ( V_11 ) {
F_100 ( L_20 , V_102 ) ;
goto V_22;
}
V_11 = F_208 () ;
if ( V_11 ) {
F_100 ( L_21 ,
V_102 ) ;
goto V_22;
}
F_218 (cpu) {
void * V_100 = ( void * ) ( long ) V_93 ;
F_99 ( & V_198 ,
V_101 , V_100 ) ;
}
}
V_39 = F_219 ( L_22 ,
sizeof( struct V_32 ) , 0 , 0 , NULL ) ;
V_42 = F_219 ( L_23 ,
sizeof( struct V_40 ) , 0 , 0 , NULL ) ;
V_11 = F_18 ( V_20 ) ;
if ( V_11 ) {
F_100 ( L_24 , V_102 ) ;
goto V_22;
}
F_220 () ;
if ( V_195 && ! V_173 ) {
struct V_182 * V_183 ;
F_221 ( & V_199 ) ;
V_183 = F_184 () ;
F_169 ( L_25
L_26 , V_102 ) ;
#ifdef F_42
F_169 ( L_27 ,
V_102 , ! V_179 ) ;
#endif
if ( V_183 != NULL )
F_222 ( L_28 , V_102 ) ;
}
if ( V_195 && ! V_174 ) {
struct V_192 * V_183 ;
V_183 = F_196 () ;
if ( V_124 )
F_3 ( true ) ;
F_169 ( L_29
L_26 , V_102 ) ;
#ifdef F_42
F_169 ( L_30 ,
V_102 , V_124 ,
! V_188 ) ;
#endif
if ( F_96 ( V_183 ) || V_183 ) {
if ( F_96 ( V_183 ) )
return F_223 ( V_183 ) ;
F_222 ( L_31 , V_102 ) ;
}
}
if ( V_63 )
F_224 ( ! V_173 , ! V_174 ,
V_124 ,
! V_200 ) ;
V_22:
return V_11 ;
}
