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
static int F_11 ( void )
{
struct V_16 * V_17 = F_12 ( L_1 , NULL ) ;
if ( V_17 == NULL )
return - V_18 ;
F_13 ( L_2 , V_19 , V_17 , & V_20 ) ;
F_13 ( L_3 , V_19 , V_17 , & V_21 ) ;
F_13 ( L_4 , V_19 , V_17 , & V_22 ) ;
F_13 ( L_5 , V_19 , V_17 , & V_23 ) ;
F_13 ( L_6 , V_19 , V_17 , & V_24 ) ;
F_13 ( L_7 , V_19 , V_17 , & V_25 ) ;
F_13 ( L_8 , V_19 , V_17 , & V_26 ) ;
F_13 ( L_9 , V_19 , V_17 , & V_27 ) ;
F_13 ( L_10 , V_19 , V_17 , & V_28 ) ;
F_13 ( L_11 , V_19 , V_17 , & V_29 ) ;
F_13 ( L_12 , V_19 , V_17 ,
& V_30 ) ;
F_13 ( L_13 , V_19 , V_17 , & V_31 ) ;
F_13 ( L_14 , V_19 , V_17 , & V_32 ) ;
F_13 ( L_15 , V_19 , V_17 , & V_33 ) ;
F_13 ( L_16 , V_19 , V_17 , & V_34 ) ;
F_13 ( L_17 , V_19 , V_17 , & V_35 ) ;
F_13 ( L_18 , V_19 , V_17 , & V_36 ) ;
F_13 ( L_19 , V_19 , V_17 , & V_37 ) ;
F_13 ( L_20 , V_19 , V_17 , & V_38 ) ;
F_13 ( L_21 , V_19 , V_17 , & V_39 ) ;
F_13 ( L_22 , V_19 , V_17 ,
& V_40 ) ;
F_13 ( L_23 , V_19 , V_17 , & V_41 ) ;
F_13 ( L_24 , V_19 , V_17 , & V_42 ) ;
F_13 ( L_25 , V_19 , V_17 , & V_43 ) ;
F_13 ( L_26 , V_19 , V_17 , & V_44 ) ;
F_13 ( L_27 , V_19 , V_17 , & V_45 ) ;
F_13 ( L_28 , V_19 , V_17 , & V_46 ) ;
F_13 ( L_29 , V_19 , V_17 , & V_47 ) ;
F_13 ( L_30 , V_19 , V_17 , & V_48 ) ;
F_13 ( L_31 , V_19 , V_17 ,
& V_49 ) ;
F_13 ( L_32 , V_19 , V_17 ,
& V_50 ) ;
F_13 ( L_33 , V_19 , V_17 ,
& V_51 ) ;
F_13 ( L_34 , V_19 , V_17 ,
& V_52 ) ;
F_13 ( L_35 , V_19 , V_17 ,
& V_53 ) ;
F_13 ( L_36 , V_19 , V_17 ,
& V_54 ) ;
F_14 ( L_37 , V_19 , V_17 , & V_55 ) ;
F_14 ( L_38 , V_19 , V_17 , & V_56 ) ;
F_14 ( L_39 , V_19 , V_17 , & V_57 ) ;
F_14 ( L_40 , V_19 , V_17 , & V_58 ) ;
F_13 ( L_41 , V_19 , V_17 ,
& V_59 ) ;
F_13 ( L_42 , V_19 , V_17 , & V_60 ) ;
return 0 ;
}
void F_15 ( void )
{
F_16 ( L_43 , V_20 ) ;
F_16 ( L_44 , V_21 ) ;
F_16 ( L_45 , V_22 ) ;
F_16 ( L_46 , V_23 ) ;
F_16 ( L_47 , V_24 ) ;
F_16 ( L_48 , V_25 ) ;
F_16 ( L_49 , V_26 ) ;
F_16 ( L_50 , V_27 ) ;
F_16 ( L_51 , V_28 ) ;
F_16 ( L_52 , V_29 ) ;
F_16 ( L_53 ,
V_30 ) ;
F_16 ( L_54 , V_31 ) ;
F_16 ( L_55 , V_32 ) ;
F_16 ( L_56 , V_33 ) ;
F_16 ( L_57 ,
V_34 ) ;
F_16 ( L_58 , V_35 ) ;
F_16 ( L_59 ,
V_36 ) ;
F_16 ( L_60 , V_37 ) ;
F_16 ( L_61 ,
V_38 ) ;
F_16 ( L_62 , V_39 ) ;
F_16 ( L_63 ,
V_40 ) ;
F_16 ( L_64 , V_41 ) ;
F_16 ( L_65 , V_42 ) ;
F_16 ( L_66 , V_43 ) ;
F_16 ( L_67 ,
V_44 ) ;
F_16 ( L_68 , V_45 ) ;
F_16 ( L_69 , V_46 ) ;
F_16 ( L_70 , V_47 ) ;
F_16 ( L_71 , V_48 ) ;
F_16 ( L_72 ,
V_49 ) ;
F_16 ( L_73 ,
V_50 ) ;
F_16 ( L_74 ,
V_51 ) ;
F_16 ( L_75 ,
V_52 ) ;
F_16 ( L_76 ,
V_53 ) ;
F_16 ( L_77 ,
V_54 ) ;
F_16 ( L_78 ,
V_55 ) ;
F_16 ( L_79 ,
V_56 ) ;
F_16 ( L_80 ,
V_57 ) ;
F_16 ( L_81 ,
V_58 ) ;
F_16 ( L_82 ,
V_59 ) ;
F_16 ( L_83 , V_60 ) ;
}
static inline bool F_17 ( struct V_61 * V_62 )
{
return V_62 == & V_63 ;
}
static struct V_61 * F_18 ( T_2 V_64 )
{
struct V_61 * V_62 = & V_63 ;
if ( V_64 != V_65 ) {
if ( V_64 >= V_66 )
goto V_67;
V_62 = & V_68 [ V_64 ] ;
}
V_67:
return V_62 ;
}
struct V_69 * F_19 ( T_2 V_64 , T_2 V_70 )
{
struct V_69 * V_71 = NULL ;
struct V_61 * V_62 = NULL ;
V_62 = F_18 ( V_64 ) ;
if ( V_62 == NULL )
goto V_67;
if ( ! F_17 ( V_62 ) )
F_20 ( & V_62 -> V_72 ) ;
if ( V_70 < V_73 ) {
V_71 = V_62 -> V_74 [ V_70 ] ;
if ( V_71 != NULL )
F_20 ( & V_71 -> V_72 ) ;
}
V_67:
return V_71 ;
}
void F_21 ( struct V_69 * V_71 )
{
struct V_61 * V_62 = NULL ;
if ( V_71 == NULL )
F_22 () ;
V_62 = V_71 -> V_75 ;
F_23 ( & V_71 -> V_72 ) ;
if ( ! F_17 ( V_62 ) )
F_23 ( & V_62 -> V_72 ) ;
}
int F_24 ( T_2 V_64 )
{
struct V_61 * V_62 ;
int V_11 = - 1 ;
V_62 = F_18 ( V_64 ) ;
if ( V_62 == NULL )
goto V_67;
if ( V_62 -> V_76 )
goto V_67;
V_62 -> V_76 = 1 ;
V_11 = 0 ;
V_67:
return V_11 ;
}
static struct V_77 * F_25 ( struct V_69 * V_71 )
{
struct V_77 * V_78 = NULL ;
struct V_79 * V_80 ;
int V_81 ;
V_80 = & F_26 ( V_82 ) ;
for ( V_81 = 0 ; V_81 < F_27 ( V_80 -> V_83 ) ; V_81 ++ ) {
V_78 = V_80 -> V_83 [ V_81 ] ;
if ( V_78 != NULL ) {
V_80 -> V_83 [ V_81 ] = NULL ;
break;
}
}
F_5 ( V_78 == NULL ) ;
V_22 = F_28 ( & V_84 ) ;
if ( V_22 > V_23 )
V_23 = V_22 ;
return V_78 ;
}
static void F_29 ( struct V_77 * V_78 ,
struct V_69 * V_71 )
{
V_22 =
F_30 ( & V_84 ) ;
F_5 ( V_22 < 0 ) ;
F_31 ( V_85 , V_78 ) ;
}
static struct V_86 * F_32 ( struct V_69 * V_71 )
{
struct V_86 * V_87 = NULL ;
struct V_79 * V_80 ;
V_80 = & F_26 ( V_82 ) ;
V_87 = V_80 -> V_87 ;
F_5 ( V_87 == NULL ) ;
V_80 -> V_87 = NULL ;
V_20 = F_28 ( & V_88 ) ;
if ( V_20 > V_21 )
V_21 = V_20 ;
return V_87 ;
}
static void F_33 ( struct V_86 * V_87 , struct V_69 * V_71 )
{
V_20 =
F_30 ( & V_88 ) ;
F_5 ( V_20 < 0 ) ;
F_31 ( V_89 , V_87 ) ;
}
static struct V_1 * F_34 ( void )
{
struct V_1 * V_1 = F_35 ( V_90 ) ;
if ( V_1 != NULL )
V_91 =
F_28 ( & V_92 ) ;
return V_1 ;
}
static void F_36 ( struct V_1 * V_1 )
{
long V_93 ;
static long V_94 , V_95 ;
if ( V_1 == NULL )
F_22 () ;
F_37 ( V_1 ) ;
V_96 =
F_28 ( & V_97 ) ;
V_93 = V_91 -
F_38 ( & V_97 ) -
F_38 ( & V_98 ) -
F_38 ( & V_99 ) ;
if ( V_93 > V_94 )
V_94 = V_93 ;
if ( V_93 < V_95 )
V_95 = V_93 ;
#ifdef F_39
if ( V_93 > 2L || V_93 < - 2L ) {
}
#endif
}
static void * F_40 ( char * V_100 , T_3 V_101 , bool V_102 ,
struct V_103 * V_104 )
{
void * V_105 = NULL , * V_106 = V_100 ;
unsigned V_107 = V_101 ;
struct V_1 * V_1 = (struct V_1 * ) ( V_100 ) , * V_108 ;
if ( ! V_102 ) {
F_41 ( V_1 , & V_106 , & V_107 ) ;
if ( V_107 > F_42 () ) {
V_33 ++ ;
goto V_67;
}
} else {
F_5 ( V_107 > F_42 () ) ;
}
V_105 = ( void * ) F_43 ( V_104 , true , V_106 , V_107 ) ;
if ( V_105 != NULL )
goto V_109;
V_108 = F_34 () ;
if ( V_108 != NULL )
goto V_110;
V_30 ++ ;
V_108 = F_44 () ;
if ( V_108 == NULL ) {
V_36 ++ ;
goto V_67;
}
V_35 ++ ;
V_110:
V_105 = ( void * ) F_45 ( V_104 , true , V_106 , V_107 , V_108 ) ;
F_5 ( V_105 == NULL ) ;
V_41 =
F_28 ( & V_98 ) ;
if ( V_41 > V_42 )
V_42 = V_41 ;
V_109:
V_55 =
F_46 ( V_107 , & V_111 ) ;
if ( V_55 > V_56 )
V_56 = V_55 ;
V_45 = F_28 ( & V_112 ) ;
if ( V_45 > V_46 )
V_46 = V_45 ;
if ( V_113 && V_102 )
F_47 ( true , 1 ) ;
V_67:
return V_105 ;
}
static void * F_48 ( char * V_100 , T_3 V_101 , bool V_102 ,
struct V_103 * V_104 )
{
void * V_105 = NULL , * V_106 = V_100 ;
unsigned V_107 = V_101 ;
struct V_1 * V_1 = (struct V_1 * ) ( V_100 ) , * V_108 ;
unsigned long V_114 ;
unsigned long V_115 , V_116 ;
if ( V_100 == NULL ) {
F_5 ( ! V_113 ) ;
goto V_117;
}
V_115 = V_47 ;
if ( ! V_102 )
F_41 ( V_1 , & V_106 , & V_107 ) ;
if ( V_107 > V_118 ) {
V_33 ++ ;
goto V_67;
}
if ( ( V_107 > V_119 ) && ( V_115 > 0 ) ) {
V_116 = V_57 ;
if ( ( long ) V_116 < 0 )
V_116 = 0 ;
V_114 = F_49 ( V_116 ,
V_115 ) ;
if ( V_114 > V_119 ) {
V_34 ++ ;
goto V_67;
}
}
V_117:
V_105 = ( void * ) F_43 ( V_104 , false , V_106 , V_107 ) ;
if ( V_105 != NULL )
goto V_109;
V_108 = F_34 () ;
if ( V_108 != NULL )
goto V_110;
V_30 ++ ;
V_108 = F_44 () ;
if ( V_108 == NULL ) {
V_38 ++ ;
goto V_67;
}
V_37 ++ ;
V_110:
V_105 = ( void * ) F_45 ( V_104 , false , V_106 , V_107 , V_108 ) ;
F_5 ( V_105 == NULL ) ;
V_43 =
F_28 ( & V_99 ) ;
if ( V_43 > V_44 )
V_44 = V_43 ;
V_109:
V_47 = F_28 ( & V_120 ) ;
if ( V_47 > V_48 )
V_48 = V_47 ;
V_57 =
F_46 ( V_107 , & V_121 ) ;
if ( V_57 > V_58 )
V_58 = V_57 ;
if ( V_113 && V_102 )
F_47 ( false , 1 ) ;
V_67:
return V_105 ;
}
void * F_50 ( char * V_100 , unsigned int V_101 , bool V_102 ,
int V_122 , struct V_103 * V_104 )
{
void * V_105 = NULL ;
struct V_79 * V_80 ;
struct V_77 * V_78 ;
struct V_86 * V_87 ;
int V_81 ;
F_5 ( ! F_51 () ) ;
F_5 ( V_85 == NULL ) ;
F_5 ( V_89 == NULL ) ;
V_80 = & F_26 ( V_82 ) ;
for ( V_81 = 0 ; V_81 < F_27 ( V_80 -> V_83 ) ; V_81 ++ ) {
V_78 = V_80 -> V_83 [ V_81 ] ;
if ( V_78 == NULL ) {
V_78 = F_52 ( V_85 ,
V_90 ) ;
if ( F_53 ( V_78 == NULL ) ) {
V_31 ++ ;
goto V_67;
}
V_80 -> V_83 [ V_81 ] = V_78 ;
}
}
if ( V_80 -> V_87 == NULL ) {
V_87 = F_52 ( V_89 , V_90 ) ;
V_80 -> V_87 = V_87 ;
}
if ( F_53 ( V_80 -> V_87 == NULL ) ) {
V_31 ++ ;
goto V_67;
}
if ( V_122 )
V_105 = F_40 ( V_100 , V_101 , V_102 , V_104 ) ;
else
V_105 = F_48 ( V_100 , V_101 , V_102 , V_104 ) ;
V_67:
return V_105 ;
}
void F_54 ( void * V_105 , bool V_122 )
{
F_55 ( (struct V_123 * ) V_105 , V_122 ) ;
}
static void F_56 ( char * V_124 , unsigned int V_101 , char * V_125 )
{
int V_11 ;
unsigned int V_126 = V_127 ;
V_11 = F_4 ( V_14 , V_124 , V_101 ,
V_125 , & V_126 ) ;
F_5 ( V_11 ) ;
F_5 ( V_126 != V_127 ) ;
}
void F_57 ( char * V_124 , unsigned int V_101 ,
struct V_1 * V_128 )
{
char * V_125 = F_58 ( V_128 ) ;
F_56 ( V_124 , V_101 , V_125 ) ;
F_59 ( V_125 ) ;
}
static int F_60 ( char * V_100 , T_3 * V_129 , bool V_102 ,
void * V_105 , struct V_69 * V_71 ,
struct V_130 * V_131 , T_4 V_132 )
{
int V_11 ;
bool V_122 = ! F_61 ( V_71 ) ;
F_5 ( F_62 () ) ;
F_5 ( V_122 ) ;
F_5 ( F_63 ( V_105 ) ) ;
if ( V_102 )
V_11 = F_64 ( V_100 , (struct V_123 * ) V_105 ,
V_129 , V_122 ) ;
else {
V_11 = F_65 ( (struct V_1 * ) ( V_100 ) ,
(struct V_123 * ) V_105 , false ,
F_56 ) ;
* V_129 = V_127 ;
}
return V_11 ;
}
static int F_66 ( char * V_100 , T_3 * V_129 , bool V_102 ,
void * V_105 , struct V_69 * V_71 ,
struct V_130 * V_131 , T_4 V_132 )
{
int V_11 ;
bool V_122 = ! F_61 ( V_71 ) ;
struct V_1 * V_1 = NULL ;
unsigned int V_133 , V_134 ;
F_5 ( F_62 () ) ;
F_5 ( F_63 ( V_105 ) ) ;
if ( V_102 )
V_11 = F_64 ( V_100 , (struct V_123 * ) V_105 ,
V_129 , V_122 ) ;
else {
V_11 = F_65 ( (struct V_1 * ) ( V_100 ) ,
(struct V_123 * ) V_105 , V_122 ,
F_56 ) ;
* V_129 = V_127 ;
}
V_1 = F_67 ( (struct V_123 * ) V_105 , V_122 ,
& V_133 , & V_134 ) ;
if ( V_122 ) {
if ( V_1 )
V_41 =
F_30 ( & V_98 ) ;
V_45 =
F_68 ( V_134 , & V_112 ) ;
V_55 =
F_69 ( V_133 , & V_111 ) ;
} else {
if ( V_1 )
V_43 =
F_30 ( & V_99 ) ;
V_47 =
F_68 ( V_134 , & V_120 ) ;
V_57 =
F_69 ( V_133 , & V_121 ) ;
}
if ( ! F_17 ( V_71 -> V_75 ) )
F_47 ( V_122 , - 1 ) ;
if ( V_1 )
F_36 ( V_1 ) ;
return V_11 ;
}
static void F_70 ( void * V_105 , struct V_69 * V_71 ,
struct V_130 * V_131 , T_4 V_132 , bool V_135 )
{
struct V_1 * V_1 = NULL ;
unsigned int V_133 , V_134 ;
F_5 ( F_62 () ) ;
if ( F_63 ( V_105 ) ) {
F_5 ( ! V_113 ) ;
V_105 = F_71 ( V_105 , V_71 , V_131 , V_132 , V_135 ) ;
if ( V_105 == NULL )
return;
}
if ( F_72 ( V_71 ) ) {
V_1 = F_67 ( (struct V_123 * ) V_105 ,
true , & V_133 , & V_134 ) ;
if ( V_1 )
V_41 =
F_30 ( & V_98 ) ;
V_45 =
F_68 ( V_134 , & V_112 ) ;
V_55 =
F_69 ( V_133 , & V_111 ) ;
} else {
V_1 = F_67 ( (struct V_123 * ) V_105 ,
false , & V_133 , & V_134 ) ;
if ( V_1 )
V_43 =
F_30 ( & V_99 ) ;
V_47 =
F_68 ( V_134 , & V_120 ) ;
V_57 =
F_69 ( V_133 , & V_121 ) ;
}
if ( ! F_17 ( V_71 -> V_75 ) )
F_47 ( F_72 ( V_71 ) , - 1 ) ;
if ( V_1 )
F_36 ( V_1 ) ;
}
static void F_41 ( struct V_1 * V_136 , void * * V_137 , unsigned * V_138 )
{
int V_11 ;
unsigned char * V_139 = F_26 ( V_140 ) ;
char * V_124 ;
F_5 ( ! F_51 () ) ;
F_5 ( V_139 == NULL ) ;
* V_138 = V_127 << V_141 ;
V_124 = F_58 ( V_136 ) ;
F_73 () ;
V_11 = F_4 ( V_13 , V_124 , V_127 , V_139 ,
V_138 ) ;
F_5 ( V_11 ) ;
* V_137 = V_139 ;
F_59 ( V_124 ) ;
}
static int F_74 ( int V_142 )
{
struct V_9 * V_10 ;
V_10 = F_75 ( V_143 , 0 , 0 ) ;
if ( F_76 ( V_10 ) )
return V_144 ;
* F_6 ( V_12 , V_142 ) = V_10 ;
return V_145 ;
}
static void F_77 ( int V_142 )
{
struct V_9 * V_10 ;
V_10 = * F_6 ( V_12 , V_142 ) ;
F_78 ( V_10 ) ;
* F_6 ( V_12 , V_142 ) = NULL ;
}
static int F_79 ( struct V_146 * V_147 ,
unsigned long V_148 , void * V_149 )
{
int V_11 , V_81 , V_142 = ( long ) V_149 ;
struct V_79 * V_80 ;
switch ( V_148 ) {
case V_150 :
V_11 = F_74 ( V_142 ) ;
if ( V_11 != V_145 ) {
F_80 ( L_84 ,
V_151 ) ;
return V_11 ;
}
F_81 ( V_140 , V_142 ) = ( void * ) F_82 (
V_152 | V_153 , V_141 ) ;
if ( V_113 )
F_83 ( V_142 ) ;
break;
case V_154 :
case V_155 :
F_77 ( V_142 ) ;
F_84 ( ( unsigned long ) F_81 ( V_140 , V_142 ) ,
V_141 ) ;
F_81 ( V_140 , V_142 ) = NULL ;
V_80 = & F_81 ( V_82 , V_142 ) ;
for ( V_81 = 0 ; V_81 < F_27 ( V_80 -> V_83 ) ; V_81 ++ ) {
if ( V_80 -> V_83 [ V_81 ] )
F_31 ( V_85 ,
V_80 -> V_83 [ V_81 ] ) ;
}
if ( V_80 -> V_87 ) {
F_31 ( V_89 , V_80 -> V_87 ) ;
V_80 -> V_87 = NULL ;
}
if ( V_113 )
F_85 ( V_142 ) ;
break;
default:
break;
}
return V_145 ;
}
static struct V_1 * F_44 ( void )
{
struct V_1 * V_1 ;
unsigned int V_133 = 0 , V_134 = 0 ;
V_1 = F_86 ( & V_133 , & V_134 ) ;
if ( V_1 == NULL )
goto V_67;
V_55 = F_69 ( V_133 ,
& V_111 ) ;
V_45 = F_68 ( V_134 ,
& V_112 ) ;
V_39 += V_134 ;
V_41 =
F_30 ( & V_98 ) ;
V_40 ++ ;
V_67:
return V_1 ;
}
static void F_87 ( struct V_156 * V_156 , int V_157 )
{
F_88 ( V_156 , V_157 ) ;
V_59 =
F_30 ( & V_158 ) ;
V_60 ++ ;
}
static int F_89 ( int type , T_5 V_159 ,
struct V_1 * V_160 )
{
struct V_1 * V_161 ;
T_6 V_162 = F_90 ( type , V_159 ) ;
int V_157 ;
F_5 ( V_160 == NULL ) ;
do {
V_161 = F_91 ( & V_163 , V_162 . V_164 ) ;
if ( V_161 )
return 0 ;
V_157 = F_92 ( V_152 ) ;
if ( V_157 )
break;
V_157 = F_93 ( V_162 ) ;
if ( V_157 == - V_165 ) {
F_94 () ;
continue;
}
if ( V_157 ) {
F_94 () ;
break;
}
F_95 ( V_160 ) ;
F_96 ( V_160 ) ;
V_157 = F_97 ( V_160 , V_162 ) ;
if ( F_98 ( ! V_157 ) ) {
F_94 () ;
F_99 ( V_160 ) ;
return 1 ;
}
F_94 () ;
F_100 ( V_160 ) ;
F_101 ( V_160 ) ;
F_102 ( V_162 , NULL ) ;
} while ( V_157 != - V_166 );
return - V_166 ;
}
static int F_103 ( int type , T_5 V_159 ,
struct V_1 * V_108 )
{
struct V_1 * V_1 = V_108 ;
int V_11 ;
struct V_167 V_168 = {
. V_169 = V_170 ,
} ;
V_11 = F_89 ( type , V_159 , V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
else if ( V_11 == 0 ) {
F_104 ( type , V_159 ) ;
return 1 ;
}
F_5 ( ! V_171 ) ;
F_105 ( V_1 ) ;
F_106 ( V_1 ) ;
F_107 ( V_1 ) ;
( void ) F_108 ( V_1 , & V_168 , F_87 ) ;
F_109 ( V_1 ) ;
V_59 =
F_28 ( & V_158 ) ;
return 0 ;
}
static int F_110 ( void )
{
struct V_103 V_104 [ 2 ] ;
int V_11 = 0 ;
int V_172 , V_173 ;
unsigned type ;
struct V_1 * V_174 = NULL , * V_175 = NULL ;
struct V_1 * V_176 = NULL , * V_177 = NULL ;
struct V_1 * V_178 = NULL , * V_179 = NULL ;
struct V_1 * V_180 = NULL , * V_181 = NULL ;
T_5 V_159 ;
V_174 = F_35 ( V_90 ) ;
V_175 = F_35 ( V_90 ) ;
if ( V_174 == NULL )
V_176 = F_44 () ;
if ( V_175 == NULL )
V_177 = F_44 () ;
if ( ( V_176 == NULL || V_177 == NULL ) &&
F_38 ( & V_158 ) >
V_182 ) {
goto V_183;
}
if ( V_174 == NULL && V_176 == NULL )
V_178 = F_35 ( V_152 ) ;
if ( V_175 == NULL && V_177 == NULL )
V_179 = F_35 ( V_152 ) ;
if ( V_178 == NULL || V_179 == NULL )
goto V_183;
V_172 = F_111 ( & V_104 [ 0 ] , NULL , NULL , false ) ;
if ( V_172 == 0 ) {
V_11 = - V_184 ;
goto V_183;
}
F_112 ( V_104 [ 0 ] . V_131 , V_104 [ 0 ] . V_132 , & type , & V_159 ) ;
V_180 = ( V_174 != NULL ) ? V_174 :
( ( V_178 != NULL ) ? V_178 : V_176 ) ;
V_173 = F_103 ( type , V_159 , V_180 ) ;
if ( V_173 < 0 ) {
V_11 = - V_166 ;
goto V_183;
}
if ( V_176 != NULL )
V_96 =
F_28 ( & V_97 ) ;
if ( V_173 == 0 ) {
V_174 = NULL ;
V_178 = NULL ;
V_176 = NULL ;
}
if ( V_172 < 2 )
goto V_183;
F_112 ( V_104 [ 1 ] . V_131 , V_104 [ 1 ] . V_132 , & type , & V_159 ) ;
V_181 = ( V_175 != NULL ) ? V_175 :
( ( V_179 != NULL ) ? V_179 : V_177 ) ;
V_173 = F_103 ( type , V_159 , V_181 ) ;
if ( V_173 < 0 ) {
V_11 = - V_166 ;
goto V_183;
}
if ( V_177 != NULL )
V_96 =
F_28 ( & V_97 ) ;
if ( V_173 == 0 ) {
V_175 = NULL ;
V_179 = NULL ;
V_177 = NULL ;
}
V_183:
if ( V_174 != NULL )
F_109 ( V_174 ) ;
if ( V_175 != NULL )
F_109 ( V_175 ) ;
if ( V_178 != NULL )
F_109 ( V_178 ) ;
if ( V_179 != NULL )
F_109 ( V_179 ) ;
if ( V_176 != NULL )
F_36 ( V_176 ) ;
if ( V_177 != NULL )
F_36 ( V_177 ) ;
return V_11 ;
}
static int F_113 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
static bool V_189 ;
int V_11 = - 1 ;
int V_190 = V_188 -> V_191 ;
int V_192 = 0 ;
int V_193 = 0 ;
struct V_1 * V_1 ;
int V_194 , V_195 ;
if ( V_190 <= 0 )
goto V_196;
if ( V_189 )
goto V_196;
V_189 = true ;
V_49 =
F_114 ( V_197 + V_198 ) ;
V_50 =
F_114 ( V_197 + V_199 ) ;
V_194 = V_49 +
V_50 ;
if ( V_41 > V_194 )
V_192 = V_41 - V_194 ;
else
V_192 = 0 ;
while ( V_192 -- > 0 ) {
V_1 = F_44 () ;
if ( V_1 == NULL )
break;
F_36 ( V_1 ) ;
}
V_51 =
F_114 ( V_197 + V_200 ) ;
V_52 =
F_114 ( V_197 + V_201 ) ;
V_195 = V_51 +
V_52 ;
if ( V_43 > V_195 )
V_193 = V_43 - V_195 ;
else
V_193 = 0 ;
while ( V_193 -- > 0 ) {
#ifdef F_115
int V_173 ;
V_173 = F_110 () ;
if ( V_173 == - V_166 )
#endif
break;
}
V_189 = false ;
V_196:
V_49 =
F_114 ( V_197 + V_198 ) ;
V_50 =
F_114 ( V_197 + V_199 ) ;
V_11 = V_41 - V_49 +
V_50 ;
if ( V_11 < 0 )
V_11 = 0 ;
return V_11 ;
}
int F_116 ( int V_64 , int V_202 , struct V_130 * V_203 ,
T_4 V_132 , void * V_1 ,
unsigned int V_101 , bool V_102 , int V_204 )
{
struct V_69 * V_71 ;
struct V_103 V_104 ;
int V_11 = - 1 ;
void * V_105 = NULL ;
F_5 ( ! F_51 () ) ;
V_71 = F_19 ( V_64 , V_202 ) ;
if ( F_53 ( V_71 == NULL ) )
goto V_67;
if ( ! V_205 ) {
V_11 = 0 ;
V_104 . V_206 = V_64 ;
V_104 . V_202 = V_202 ;
V_104 . V_131 = * V_203 ;
V_104 . V_132 = V_132 ;
V_105 = F_50 ( ( char * ) V_1 , V_101 , V_102 ,
V_204 , & V_104 ) ;
if ( V_105 == NULL ) {
V_11 = - V_166 ;
if ( V_204 )
V_28 ++ ;
else
V_29 ++ ;
} else {
if ( V_113 )
F_117 ( V_71 ) ;
V_11 = F_118 ( V_71 , V_203 , V_132 , 0 , V_105 ) ;
if ( V_11 < 0 )
F_22 () ;
}
F_21 ( V_71 ) ;
} else {
V_32 ++ ;
if ( V_113 )
F_117 ( V_71 ) ;
if ( F_38 ( & V_71 -> V_207 ) > 0 )
( void ) F_119 ( V_71 , V_203 , V_132 ) ;
F_21 ( V_71 ) ;
}
V_67:
return V_11 ;
}
int F_120 ( int V_64 , int V_202 , struct V_130 * V_203 ,
T_4 V_132 , void * V_1 ,
T_3 * V_129 , bool V_102 , int V_208 )
{
struct V_69 * V_71 ;
int V_11 = - 1 ;
bool V_122 ;
if ( ! V_102 ) {
F_5 ( F_51 () ) ;
F_5 ( F_121 () ) ;
}
V_71 = F_19 ( V_64 , V_202 ) ;
V_122 = F_72 ( V_71 ) ;
if ( F_98 ( V_71 != NULL ) ) {
if ( F_38 ( & V_71 -> V_207 ) > 0 )
V_11 = F_122 ( V_71 , V_203 , V_132 , ( char * ) ( V_1 ) ,
V_129 , V_102 , V_208 ) ;
F_21 ( V_71 ) ;
}
F_123 ( ( ! F_72 ( V_71 ) && ( V_11 != 0 ) ) ,
L_85
L_86 ) ;
#ifdef F_124
if ( V_11 != 0 && V_11 != - 1 && ! ( V_11 == - V_15 && F_72 ( V_71 ) ) )
F_80 ( L_87 , V_11 ) ;
#endif
return V_11 ;
}
int F_125 ( int V_64 , int V_202 ,
struct V_130 * V_203 , T_4 V_132 )
{
struct V_69 * V_71 ;
int V_11 = - 1 ;
unsigned long V_209 ;
F_126 ( V_209 ) ;
V_24 ++ ;
V_71 = F_19 ( V_64 , V_202 ) ;
if ( V_113 )
F_117 ( V_71 ) ;
if ( F_98 ( V_71 != NULL ) ) {
if ( F_38 ( & V_71 -> V_207 ) > 0 )
V_11 = F_119 ( V_71 , V_203 , V_132 ) ;
F_21 ( V_71 ) ;
}
if ( V_11 >= 0 )
V_25 ++ ;
F_127 ( V_209 ) ;
return V_11 ;
}
int F_128 ( int V_64 , int V_202 ,
struct V_130 * V_203 )
{
struct V_69 * V_71 ;
int V_11 = - 1 ;
unsigned long V_209 ;
F_126 ( V_209 ) ;
V_26 ++ ;
V_71 = F_19 ( V_64 , V_202 ) ;
if ( V_113 )
F_117 ( V_71 ) ;
if ( F_98 ( V_71 != NULL ) ) {
if ( F_38 ( & V_71 -> V_207 ) > 0 )
V_11 = F_129 ( V_71 , V_203 ) ;
F_21 ( V_71 ) ;
}
if ( V_11 >= 0 )
V_27 ++ ;
F_127 ( V_209 ) ;
return V_11 ;
}
static int F_130 ( int V_64 , int V_202 )
{
struct V_69 * V_71 = NULL ;
struct V_61 * V_62 = NULL ;
int V_11 = - 1 ;
if ( V_202 < 0 )
goto V_67;
if ( V_64 == V_65 )
V_62 = & V_63 ;
else if ( ( unsigned int ) V_64 < V_66 )
V_62 = & V_68 [ V_64 ] ;
if ( V_62 == NULL )
goto V_67;
F_20 ( & V_62 -> V_72 ) ;
V_71 = V_62 -> V_74 [ V_202 ] ;
if ( V_71 == NULL )
goto V_67;
V_62 -> V_74 [ V_202 ] = NULL ;
while ( F_38 ( & V_71 -> V_72 ) != 0 )
;
F_23 ( & V_62 -> V_72 ) ;
F_131 () ;
V_11 = F_132 ( V_71 ) ;
F_133 () ;
F_134 ( V_71 ) ;
if ( V_64 == V_65 )
F_16 ( L_88 , V_151 , V_202 ) ;
else
F_16 ( L_89 ,
V_151 , V_202 , V_64 ) ;
V_67:
return V_11 ;
}
int F_135 ( T_2 V_64 , T_4 V_209 )
{
int V_70 = - 1 ;
struct V_69 * V_71 ;
struct V_61 * V_62 = NULL ;
if ( V_64 == V_65 )
V_62 = & V_63 ;
else if ( ( unsigned int ) V_64 < V_66 )
V_62 = & V_68 [ V_64 ] ;
if ( V_62 == NULL )
goto V_67;
F_20 ( & V_62 -> V_72 ) ;
V_71 = F_136 ( sizeof( struct V_69 ) , V_210 ) ;
if ( V_71 == NULL )
goto V_67;
for ( V_70 = 0 ; V_70 < V_73 ; V_70 ++ )
if ( V_62 -> V_74 [ V_70 ] == NULL )
break;
if ( V_70 >= V_73 ) {
F_16 ( L_90 , V_151 ) ;
F_134 ( V_71 ) ;
V_70 = - 1 ;
goto V_67;
}
F_137 ( & V_71 -> V_72 , 0 ) ;
V_71 -> V_75 = V_62 ;
V_71 -> V_202 = V_70 ;
F_138 ( V_71 , V_209 ) ;
V_62 -> V_74 [ V_70 ] = V_71 ;
if ( V_64 == V_65 )
F_16 ( L_91 , V_151 ,
V_209 & V_211 ? L_92 : L_93 ,
V_70 ) ;
else
F_16 ( L_94 , V_151 ,
V_209 & V_211 ? L_92 : L_93 ,
V_70 , V_64 ) ;
V_67:
if ( V_62 != NULL )
F_23 ( & V_62 -> V_72 ) ;
return V_70 ;
}
static int F_139 ( T_4 V_209 )
{
return F_135 ( V_65 , V_209 ) ;
}
int F_140 ( unsigned int V_64 , unsigned int V_202 , bool V_122 )
{
struct V_69 * V_71 ;
struct V_61 * V_62 ;
T_4 V_209 = V_122 ? 0 : V_211 ;
int V_11 = - 1 ;
F_5 ( ! V_113 ) ;
if ( V_64 == V_65 )
goto V_67;
if ( V_202 >= V_73 )
goto V_67;
if ( V_64 >= V_66 )
goto V_67;
V_62 = & V_68 [ V_64 ] ;
if ( ( V_122 && V_212 ) || ( ! V_122 && V_213 ) ) {
F_80 ( L_95 ) ;
goto V_67;
}
if ( ! V_62 -> V_76 ) {
if ( F_24 ( V_64 ) ) {
F_80 ( L_96 ) ;
goto V_67;
}
V_62 = & V_68 [ V_64 ] ;
}
F_20 ( & V_62 -> V_72 ) ;
V_71 = V_62 -> V_74 [ V_202 ] ;
if ( V_71 != NULL ) {
if ( V_71 -> V_214 && V_122 ) {
F_80 ( L_97 ) ;
goto V_67;
}
V_11 = 0 ;
goto V_67;
}
V_71 = F_136 ( sizeof( struct V_69 ) , V_152 ) ;
if ( V_71 == NULL )
goto V_67;
F_137 ( & V_71 -> V_72 , 0 ) ;
V_71 -> V_75 = V_62 ;
V_71 -> V_202 = V_202 ;
F_138 ( V_71 , V_209 ) ;
V_62 -> V_74 [ V_202 ] = V_71 ;
F_16 ( L_98 ,
V_151 , V_209 & V_211 ? L_92 : L_93 ,
V_202 , V_64 ) ;
V_11 = 0 ;
V_67:
if ( V_62 != NULL )
F_23 ( & V_62 -> V_72 ) ;
return V_11 ;
}
static void F_141 ( int V_202 ,
struct V_215 V_216 ,
T_5 V_132 , struct V_1 * V_1 )
{
T_7 V_217 = ( T_7 ) V_132 ;
struct V_130 V_131 = * (struct V_130 * ) & V_216 ;
if ( ! V_218 && ! F_1 ( V_1 ) ) {
V_53 ++ ;
return;
}
if ( F_98 ( V_217 == V_132 ) )
( void ) F_116 ( V_65 , V_202 , & V_131 , V_132 ,
V_1 , V_127 , false , 1 ) ;
}
static int F_142 ( int V_202 ,
struct V_215 V_216 ,
T_5 V_132 , struct V_1 * V_1 )
{
T_7 V_217 = ( T_7 ) V_132 ;
struct V_130 V_131 = * (struct V_130 * ) & V_216 ;
T_3 V_101 ;
int V_11 = - 1 ;
if ( F_98 ( V_217 == V_132 ) ) {
V_11 = F_120 ( V_65 , V_202 , & V_131 , V_132 ,
V_1 , & V_101 , false , 0 ) ;
F_5 ( V_11 >= 0 && V_101 != V_127 ) ;
if ( V_11 == 0 )
F_2 ( V_1 ) ;
}
return V_11 ;
}
static void F_143 ( int V_202 ,
struct V_215 V_216 ,
T_5 V_132 )
{
T_7 V_217 = ( T_7 ) V_132 ;
struct V_130 V_131 = * (struct V_130 * ) & V_216 ;
if ( F_98 ( V_217 == V_132 ) )
( void ) F_125 ( V_65 , V_202 , & V_131 , V_217 ) ;
}
static void F_144 ( int V_202 ,
struct V_215 V_216 )
{
struct V_130 V_131 = * (struct V_130 * ) & V_216 ;
( void ) F_128 ( V_65 , V_202 , & V_131 ) ;
}
static void F_145 ( int V_202 )
{
if ( V_202 >= 0 )
( void ) F_130 ( V_65 , V_202 ) ;
}
static int F_146 ( T_3 V_219 )
{
F_5 ( sizeof( struct V_215 ) !=
sizeof( struct V_130 ) ) ;
F_5 ( V_219 != V_127 ) ;
return F_139 ( 0 ) ;
}
static int F_147 ( char * V_220 , T_3 V_219 )
{
F_5 ( sizeof( struct V_215 ) !=
sizeof( struct V_130 ) ) ;
F_5 ( V_219 != V_127 ) ;
return F_139 ( 0 ) ;
}
struct V_221 F_148 ( void )
{
struct V_221 V_222 =
F_149 ( & V_223 ) ;
return V_222 ;
}
static inline struct V_130 F_150 ( unsigned type , T_7 V_217 )
{
struct V_130 V_131 = { . V_131 = { 0 } } ;
V_131 . V_131 [ 0 ] = F_151 ( type , V_217 ) ;
return V_131 ;
}
static void F_112 ( struct V_130 V_131 , T_7 V_132 ,
unsigned * type , T_5 * V_159 )
{
* type = ( unsigned ) ( V_131 . V_131 [ 0 ] >> V_224 ) ;
* V_159 = ( T_5 ) ( ( V_132 << V_224 ) |
( V_131 . V_131 [ 0 ] & V_225 ) ) ;
}
static int F_152 ( unsigned type , T_5 V_159 ,
struct V_1 * V_1 )
{
T_8 V_226 = ( T_8 ) V_159 ;
T_7 V_217 = ( T_7 ) V_159 ;
struct V_130 V_131 = F_150 ( type , V_217 ) ;
int V_11 = - 1 ;
unsigned long V_209 ;
F_5 ( ! F_153 ( V_1 ) ) ;
if ( ! V_227 && ! F_1 ( V_1 ) ) {
V_54 ++ ;
V_11 = - V_228 ;
goto V_67;
}
if ( F_98 ( V_226 == V_217 ) ) {
F_126 ( V_209 ) ;
V_11 = F_116 ( V_65 , V_229 ,
& V_131 , F_154 ( V_217 ) ,
V_1 , V_127 , false , 0 ) ;
F_127 ( V_209 ) ;
}
V_67:
return V_11 ;
}
static int F_155 ( unsigned type , T_5 V_159 ,
struct V_1 * V_1 )
{
T_8 V_226 = ( T_8 ) V_159 ;
T_7 V_217 = ( T_7 ) V_159 ;
struct V_130 V_131 = F_150 ( type , V_217 ) ;
T_3 V_101 ;
int V_11 = - 1 , V_208 ;
if ( V_171 )
V_208 = 1 ;
else
V_208 = - 1 ;
F_5 ( ! F_153 ( V_1 ) ) ;
if ( F_98 ( V_226 == V_217 ) ) {
V_11 = F_120 ( V_65 , V_229 ,
& V_131 , F_154 ( V_217 ) ,
V_1 , & V_101 , false , V_208 ) ;
F_5 ( V_11 >= 0 && V_101 != V_127 ) ;
}
return V_11 ;
}
static void F_156 ( unsigned type , T_5 V_159 )
{
T_8 V_226 = ( T_8 ) V_159 ;
T_7 V_217 = ( T_7 ) V_159 ;
struct V_130 V_131 = F_150 ( type , V_217 ) ;
if ( F_98 ( V_226 == V_217 ) )
( void ) F_125 ( V_65 , V_229 ,
& V_131 , F_154 ( V_217 ) ) ;
}
static void F_157 ( unsigned type )
{
struct V_130 V_131 ;
int V_217 ;
for ( V_217 = V_225 ; V_217 >= 0 ; V_217 -- ) {
V_131 = F_150 ( type , V_217 ) ;
( void ) F_128 ( V_65 ,
V_229 , & V_131 ) ;
}
}
static void F_158 ( unsigned V_230 )
{
if ( V_229 < 0 )
V_229 =
F_139 ( V_211 ) ;
}
struct V_231 F_159 ( void )
{
struct V_231 V_222 =
F_160 ( & V_232 ) ;
return V_222 ;
}
static int T_9 F_161 ( char * V_233 )
{
V_234 = 1 ;
return 1 ;
}
static int T_9 F_162 ( char * V_233 )
{
V_234 = 1 ;
#ifdef F_163
V_113 = 1 ;
#endif
return 1 ;
}
static int T_9 F_164 ( char * V_233 )
{
V_212 = 1 ;
return 1 ;
}
static int T_9 F_165 ( char * V_233 )
{
V_213 = 1 ;
return 1 ;
}
static int T_9 F_166 ( char * V_233 )
{
V_171 = false ;
return 1 ;
}
static int T_9 F_167 ( char * V_233 )
{
V_227 = 1 ;
return 1 ;
}
static int T_9 F_168 ( char * V_233 )
{
V_218 = 1 ;
return 1 ;
}
static int T_9 F_169 ( char * V_233 )
{
strncpy ( V_143 , V_233 , V_235 ) ;
V_234 = 1 ;
return 1 ;
}
static int T_9 F_170 ( void )
{
int V_11 = 0 ;
if ( * V_143 != '\0' ) {
V_11 = F_171 ( V_143 , 0 , 0 ) ;
if ( ! V_11 )
F_16 ( L_99 ,
V_143 ) ;
}
if ( ! V_11 )
strcpy ( V_143 , L_100 ) ;
V_11 = F_171 ( V_143 , 0 , 0 ) ;
if ( ! V_11 ) {
V_11 = 1 ;
goto V_67;
}
F_16 ( L_101 , V_143 ) ;
V_11 = 0 ;
V_12 = F_172 ( struct V_9 * ) ;
if ( ! V_12 )
V_11 = 1 ;
V_67:
return V_11 ;
}
static int T_9 F_173 ( void )
{
int V_11 = 0 ;
if ( V_113 ) {
V_151 = L_102 ;
F_174 ( & V_236 ) ;
}
#ifdef F_175
F_11 () ;
#endif
if ( V_234 ) {
unsigned int V_142 ;
F_176 ( & V_237 ) ;
F_177 ( & V_236 ) ;
V_11 = F_178 ( & V_238 ) ;
if ( V_11 ) {
F_80 ( L_103 , V_151 ) ;
goto V_67;
}
V_11 = F_170 () ;
if ( V_11 ) {
F_80 ( L_104 ,
V_151 ) ;
goto V_67;
}
F_179 (cpu) {
void * V_149 = ( void * ) ( long ) V_142 ;
F_79 ( & V_238 ,
V_150 , V_149 ) ;
}
}
V_85 = F_180 ( L_105 ,
sizeof( struct V_77 ) , 0 , 0 , NULL ) ;
V_89 = F_180 ( L_106 ,
sizeof( struct V_86 ) , 0 , 0 , NULL ) ;
V_11 = F_24 ( V_65 ) ;
if ( V_11 ) {
F_80 ( L_107 , V_151 ) ;
goto V_67;
}
F_181 () ;
if ( V_234 && ! V_212 ) {
struct V_221 V_222 ;
F_182 ( & V_239 ) ;
V_222 = F_148 () ;
F_16 ( L_108
L_109 , V_151 ) ;
#ifdef F_39
F_16 ( L_110 ,
V_151 , ! V_218 ) ;
#endif
if ( V_222 . V_240 != NULL )
F_183 ( L_111 , V_151 ) ;
}
if ( V_234 && ! V_213 ) {
struct V_231 V_222 ;
V_222 = F_159 () ;
if ( V_171 )
F_3 ( true ) ;
F_16 ( L_112
L_109 , V_151 ) ;
#ifdef F_39
F_16 ( L_113 ,
V_151 , V_171 ,
! V_227 ) ;
#endif
if ( V_222 . V_241 != NULL )
F_183 ( L_114 , V_151 ) ;
}
if ( V_113 )
F_184 ( ! V_212 , ! V_213 ,
V_171 ) ;
V_67:
return V_11 ;
}
