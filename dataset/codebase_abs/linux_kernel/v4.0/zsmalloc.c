static void * F_1 ( char * V_1 , T_1 V_2 , struct V_3 * V_3 )
{
return F_2 ( V_1 , V_2 ) ;
}
static void F_3 ( void * V_4 )
{
F_4 ( V_4 ) ;
}
static int F_5 ( void * V_4 , T_2 V_5 , T_1 V_2 ,
unsigned long * V_6 )
{
* V_6 = F_6 ( V_4 , V_5 ) ;
return * V_6 ? 0 : - 1 ;
}
static void F_7 ( void * V_4 , unsigned long V_6 )
{
F_8 ( V_4 , V_6 ) ;
}
static int F_9 ( void * V_4 , unsigned int V_7 ,
unsigned int * V_8 )
{
return - V_9 ;
}
static void * F_10 ( void * V_4 , unsigned long V_6 ,
enum V_10 V_11 )
{
enum V_12 V_13 ;
switch ( V_11 ) {
case V_14 :
V_13 = V_15 ;
break;
case V_16 :
V_13 = V_17 ;
break;
case V_18 :
default:
V_13 = V_19 ;
break;
}
return F_11 ( V_4 , V_6 , V_13 ) ;
}
static void F_12 ( void * V_4 , unsigned long V_6 )
{
F_13 ( V_4 , V_6 ) ;
}
static T_3 F_14 ( void * V_4 )
{
return F_15 ( V_4 ) << V_20 ;
}
static int F_16 ( struct V_21 * V_21 )
{
return F_17 ( V_21 ) ;
}
static int F_18 ( struct V_21 * V_21 )
{
return F_19 ( V_21 ) ;
}
static void F_20 ( struct V_21 * V_21 , unsigned int * V_22 ,
enum V_23 * V_24 )
{
unsigned long V_25 ;
F_21 ( ! F_16 ( V_21 ) ) ;
V_25 = ( unsigned long ) V_21 -> V_26 ;
* V_24 = V_25 & V_27 ;
* V_22 = ( V_25 >> V_28 ) & V_29 ;
}
static void F_22 ( struct V_21 * V_21 , unsigned int V_22 ,
enum V_23 V_24 )
{
unsigned long V_25 ;
F_21 ( ! F_16 ( V_21 ) ) ;
V_25 = ( ( V_22 & V_29 ) << V_28 ) |
( V_24 & V_27 ) ;
V_21 -> V_26 = (struct V_30 * ) V_25 ;
}
static int F_23 ( int V_5 )
{
int V_31 = 0 ;
if ( F_24 ( V_5 > V_32 ) )
V_31 = F_25 ( V_5 - V_32 ,
V_33 ) ;
return V_31 ;
}
static enum V_23 F_26 ( struct V_21 * V_21 )
{
int V_34 , V_35 ;
enum V_23 V_36 ;
F_21 ( ! F_16 ( V_21 ) ) ;
V_34 = V_21 -> V_34 ;
V_35 = V_21 -> V_37 ;
if ( V_34 == 0 )
V_36 = V_38 ;
else if ( V_34 == V_35 )
V_36 = V_39 ;
else if ( V_34 <= V_35 / V_40 )
V_36 = V_41 ;
else
V_36 = V_42 ;
return V_36 ;
}
static void F_27 ( struct V_21 * V_21 , struct V_43 * V_44 ,
enum V_23 V_24 )
{
struct V_21 * * V_45 ;
F_21 ( ! F_16 ( V_21 ) ) ;
if ( V_24 >= V_46 )
return;
V_45 = & V_44 -> V_47 [ V_24 ] ;
if ( * V_45 )
F_28 ( & V_21 -> V_48 , & ( * V_45 ) -> V_48 ) ;
* V_45 = V_21 ;
}
static void F_29 ( struct V_21 * V_21 , struct V_43 * V_44 ,
enum V_23 V_24 )
{
struct V_21 * * V_45 ;
F_21 ( ! F_16 ( V_21 ) ) ;
if ( V_24 >= V_46 )
return;
V_45 = & V_44 -> V_47 [ V_24 ] ;
F_21 ( ! * V_45 ) ;
if ( F_30 ( & ( * V_45 ) -> V_48 ) )
* V_45 = NULL ;
else if ( * V_45 == V_21 )
* V_45 = (struct V_21 * ) F_31 ( ( * V_45 ) -> V_48 . V_49 ,
struct V_21 , V_48 ) ;
F_32 ( & V_21 -> V_48 ) ;
}
static enum V_23 F_33 ( struct V_50 * V_4 ,
struct V_21 * V_21 )
{
int V_22 ;
struct V_43 * V_44 ;
enum V_23 V_51 , V_52 ;
F_21 ( ! F_16 ( V_21 ) ) ;
F_20 ( V_21 , & V_22 , & V_51 ) ;
V_52 = F_26 ( V_21 ) ;
if ( V_52 == V_51 )
goto V_53;
V_44 = V_4 -> V_43 [ V_22 ] ;
F_29 ( V_21 , V_44 , V_51 ) ;
F_27 ( V_21 , V_44 , V_52 ) ;
F_22 ( V_21 , V_22 , V_52 ) ;
V_53:
return V_52 ;
}
static int F_34 ( int V_54 )
{
int V_55 , V_56 = 0 ;
int V_57 = 1 ;
for ( V_55 = 1 ; V_55 <= V_58 ; V_55 ++ ) {
int V_59 ;
int V_60 , V_61 ;
V_59 = V_55 * V_62 ;
V_60 = V_59 % V_54 ;
V_61 = ( V_59 - V_60 ) * 100 / V_59 ;
if ( V_61 > V_56 ) {
V_56 = V_61 ;
V_57 = V_55 ;
}
}
return V_57 ;
}
static struct V_21 * F_35 ( struct V_21 * V_21 )
{
if ( F_16 ( V_21 ) )
return V_21 ;
else
return V_21 -> V_63 ;
}
static struct V_21 * F_36 ( struct V_21 * V_21 )
{
struct V_21 * V_49 ;
if ( F_18 ( V_21 ) )
V_49 = NULL ;
else if ( F_16 ( V_21 ) )
V_49 = (struct V_21 * ) F_37 ( V_21 ) ;
else
V_49 = F_31 ( V_21 -> V_48 . V_49 , struct V_21 , V_48 ) ;
return V_49 ;
}
static void * F_38 ( struct V_21 * V_21 , unsigned long V_64 )
{
unsigned long V_6 ;
if ( ! V_21 ) {
F_21 ( V_64 ) ;
return NULL ;
}
V_6 = F_39 ( V_21 ) << V_65 ;
V_6 |= ( ( V_64 + 1 ) & V_66 ) ;
return ( void * ) V_6 ;
}
static void F_40 ( unsigned long V_6 , struct V_21 * * V_21 ,
unsigned long * V_64 )
{
* V_21 = F_41 ( V_6 >> V_65 ) ;
* V_64 = ( V_6 & V_66 ) - 1 ;
}
static unsigned long F_42 ( struct V_21 * V_21 ,
unsigned long V_64 , int V_54 )
{
unsigned long V_67 = 0 ;
if ( ! F_16 ( V_21 ) )
V_67 = V_21 -> V_68 ;
return V_67 + V_64 * V_54 ;
}
static void F_43 ( struct V_21 * V_21 )
{
F_44 ( V_69 , & V_21 -> V_70 ) ;
F_44 ( V_71 , & V_21 -> V_70 ) ;
F_45 ( V_21 , 0 ) ;
V_21 -> V_26 = NULL ;
V_21 -> V_72 = NULL ;
F_46 ( V_21 ) ;
}
static void F_47 ( struct V_21 * V_63 )
{
struct V_21 * V_73 , * V_74 , * V_75 ;
F_21 ( ! F_16 ( V_63 ) ) ;
F_21 ( V_63 -> V_34 ) ;
V_75 = (struct V_21 * ) F_37 ( V_63 ) ;
F_43 ( V_63 ) ;
F_48 ( V_63 ) ;
if ( ! V_75 )
return;
F_49 (nextp, tmp, &head_extra->lru, lru) {
F_50 ( & V_73 -> V_48 ) ;
F_43 ( V_73 ) ;
F_48 ( V_73 ) ;
}
F_43 ( V_75 ) ;
F_48 ( V_75 ) ;
}
static void F_51 ( struct V_21 * V_63 , struct V_43 * V_44 )
{
unsigned long V_67 = 0 ;
struct V_21 * V_21 = V_63 ;
F_21 ( ! F_16 ( V_63 ) ) ;
while ( V_21 ) {
struct V_21 * V_76 ;
struct V_77 * V_78 ;
unsigned int V_55 = 1 ;
void * V_79 ;
if ( V_21 != V_63 )
V_21 -> V_68 = V_67 ;
V_79 = F_52 ( V_21 ) ;
V_78 = (struct V_77 * ) V_79 + V_67 / sizeof( * V_78 ) ;
while ( ( V_67 += V_44 -> V_5 ) < V_62 ) {
V_78 -> V_49 = F_38 ( V_21 , V_55 ++ ) ;
V_78 += V_44 -> V_5 / sizeof( * V_78 ) ;
}
V_76 = F_36 ( V_21 ) ;
V_78 -> V_49 = F_38 ( V_76 , 0 ) ;
F_53 ( V_79 ) ;
V_21 = V_76 ;
V_67 %= V_62 ;
}
}
static struct V_21 * F_54 ( struct V_43 * V_44 , T_1 V_70 )
{
int V_55 , error ;
struct V_21 * V_63 = NULL , * V_80 ( V_81 ) ;
error = - V_82 ;
for ( V_55 = 0 ; V_55 < V_44 -> V_83 ; V_55 ++ ) {
struct V_21 * V_21 ;
V_21 = F_55 ( V_70 ) ;
if ( ! V_21 )
goto V_84;
F_56 ( & V_21 -> V_48 ) ;
if ( V_55 == 0 ) {
F_57 ( V_21 ) ;
F_45 ( V_21 , 0 ) ;
V_63 = V_21 ;
V_63 -> V_34 = 0 ;
}
if ( V_55 == 1 )
F_45 ( V_63 , ( unsigned long ) V_21 ) ;
if ( V_55 >= 1 )
V_21 -> V_63 = V_63 ;
if ( V_55 >= 2 )
F_58 ( & V_21 -> V_48 , & V_81 -> V_48 ) ;
if ( V_55 == V_44 -> V_83 - 1 )
F_59 ( V_21 ) ;
V_81 = V_21 ;
}
F_51 ( V_63 , V_44 ) ;
V_63 -> V_72 = F_38 ( V_63 , 0 ) ;
V_63 -> V_37 = V_44 -> V_83 * V_62 / V_44 -> V_5 ;
error = 0 ;
V_84:
if ( F_60 ( error ) && V_63 ) {
F_47 ( V_63 ) ;
V_63 = NULL ;
}
return V_63 ;
}
static struct V_21 * F_61 ( struct V_43 * V_44 )
{
int V_55 ;
struct V_21 * V_21 ;
for ( V_55 = 0 ; V_55 < V_46 ; V_55 ++ ) {
V_21 = V_44 -> V_47 [ V_55 ] ;
if ( V_21 )
break;
}
return V_21 ;
}
static inline int F_62 ( struct V_85 * V_86 )
{
if ( V_86 -> V_87 )
return 0 ;
V_86 -> V_87 = F_63 ( V_62 * 2 , NULL ) ;
if ( ! V_86 -> V_87 )
return - V_82 ;
return 0 ;
}
static inline void F_64 ( struct V_85 * V_86 )
{
if ( V_86 -> V_87 )
F_65 ( V_86 -> V_87 ) ;
V_86 -> V_87 = NULL ;
}
static inline void * F_66 ( struct V_85 * V_86 ,
struct V_21 * V_7 [ 2 ] , int V_67 , int V_5 )
{
F_21 ( F_67 ( V_86 -> V_87 , V_88 , V_7 ) ) ;
V_86 -> V_89 = V_86 -> V_87 -> V_90 ;
return V_86 -> V_89 + V_67 ;
}
static inline void F_68 ( struct V_85 * V_86 ,
struct V_21 * V_7 [ 2 ] , int V_67 , int V_5 )
{
unsigned long V_90 = ( unsigned long ) V_86 -> V_89 ;
F_69 ( V_90 , V_62 * 2 ) ;
}
static inline int F_62 ( struct V_85 * V_86 )
{
if ( V_86 -> V_91 )
return 0 ;
V_86 -> V_91 = F_70 ( V_92 , V_93 ) ;
if ( ! V_86 -> V_91 )
return - V_82 ;
return 0 ;
}
static inline void F_64 ( struct V_85 * V_86 )
{
F_71 ( V_86 -> V_91 ) ;
V_86 -> V_91 = NULL ;
}
static void * F_66 ( struct V_85 * V_86 ,
struct V_21 * V_7 [ 2 ] , int V_67 , int V_5 )
{
int V_94 [ 2 ] ;
void * V_90 ;
char * V_95 = V_86 -> V_91 ;
F_72 () ;
if ( V_86 -> V_96 == V_17 )
goto V_53;
V_94 [ 0 ] = V_62 - V_67 ;
V_94 [ 1 ] = V_5 - V_94 [ 0 ] ;
V_90 = F_52 ( V_7 [ 0 ] ) ;
memcpy ( V_95 , V_90 + V_67 , V_94 [ 0 ] ) ;
F_53 ( V_90 ) ;
V_90 = F_52 ( V_7 [ 1 ] ) ;
memcpy ( V_95 + V_94 [ 0 ] , V_90 , V_94 [ 1 ] ) ;
F_53 ( V_90 ) ;
V_53:
return V_86 -> V_91 ;
}
static void F_68 ( struct V_85 * V_86 ,
struct V_21 * V_7 [ 2 ] , int V_67 , int V_5 )
{
int V_94 [ 2 ] ;
void * V_90 ;
char * V_95 = V_86 -> V_91 ;
if ( V_86 -> V_96 == V_15 )
goto V_53;
V_94 [ 0 ] = V_62 - V_67 ;
V_94 [ 1 ] = V_5 - V_94 [ 0 ] ;
V_90 = F_52 ( V_7 [ 0 ] ) ;
memcpy ( V_90 + V_67 , V_95 , V_94 [ 0 ] ) ;
F_53 ( V_90 ) ;
V_90 = F_52 ( V_7 [ 1 ] ) ;
memcpy ( V_90 , V_95 + V_94 [ 0 ] , V_94 [ 1 ] ) ;
F_53 ( V_90 ) ;
V_53:
F_73 () ;
}
static int F_74 ( struct V_97 * V_98 , unsigned long V_99 ,
void * V_100 )
{
int V_101 , V_102 = ( long ) V_100 ;
struct V_85 * V_86 ;
switch ( V_99 ) {
case V_103 :
V_86 = & F_75 ( V_104 , V_102 ) ;
V_101 = F_62 ( V_86 ) ;
if ( V_101 )
return F_76 ( V_101 ) ;
break;
case V_105 :
case V_106 :
V_86 = & F_75 ( V_104 , V_102 ) ;
F_64 ( V_86 ) ;
break;
}
return V_107 ;
}
static int F_77 ( void )
{
int V_102 , V_80 ( V_101 ) ;
F_78 () ;
F_79 ( & V_108 ) ;
F_80 (cpu) {
V_101 = F_74 ( NULL , V_103 , ( void * ) ( long ) V_102 ) ;
if ( F_81 ( V_101 ) )
break;
}
F_82 () ;
return F_81 ( V_101 ) ;
}
static void F_83 ( void )
{
int V_102 ;
F_78 () ;
F_80 (cpu)
F_74 ( NULL , V_105 , ( void * ) ( long ) V_102 ) ;
F_84 ( & V_108 ) ;
F_82 () ;
}
static void F_85 ( void )
{
int V_109 ;
V_109 = ( V_92 - V_32 ) / V_33 + 1 ;
if ( ( V_92 - V_32 ) % V_33 )
V_109 += 1 ;
V_110 = V_109 ;
}
static unsigned int F_86 ( int V_5 , int V_83 )
{
return V_83 * V_62 / V_5 ;
}
static bool F_87 ( struct V_43 * V_111 , int V_5 , int V_83 )
{
if ( V_111 -> V_83 != V_83 )
return false ;
if ( F_86 ( V_111 -> V_5 , V_111 -> V_83 )
!= F_86 ( V_5 , V_83 ) )
return false ;
return true ;
}
static inline void F_88 ( struct V_43 * V_44 ,
enum V_112 type , unsigned long V_113 )
{
V_44 -> V_114 . V_115 [ type ] += V_113 ;
}
static inline void F_89 ( struct V_43 * V_44 ,
enum V_112 type , unsigned long V_113 )
{
V_44 -> V_114 . V_115 [ type ] -= V_113 ;
}
static inline unsigned long F_90 ( struct V_43 * V_44 ,
enum V_112 type )
{
return V_44 -> V_114 . V_115 [ type ] ;
}
static int T_4 F_91 ( void )
{
if ( ! F_92 () )
return - V_116 ;
V_117 = F_93 ( L_1 , NULL ) ;
if ( ! V_117 )
return - V_82 ;
return 0 ;
}
static void T_5 F_94 ( void )
{
F_95 ( V_117 ) ;
}
static int F_96 ( struct V_118 * V_119 , void * V_120 )
{
int V_55 ;
struct V_50 * V_4 = V_119 -> V_121 ;
struct V_43 * V_44 ;
int V_122 ;
unsigned long V_123 , V_124 , V_125 ;
unsigned long V_126 = 0 , V_127 = 0 , V_128 = 0 ;
F_97 ( V_119 , L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 ) ;
for ( V_55 = 0 ; V_55 < V_110 ; V_55 ++ ) {
V_44 = V_4 -> V_43 [ V_55 ] ;
if ( V_44 -> V_68 != V_55 )
continue;
F_98 ( & V_44 -> V_129 ) ;
V_123 = F_90 ( V_44 , V_130 ) ;
V_124 = F_90 ( V_44 , V_131 ) ;
F_99 ( & V_44 -> V_129 ) ;
V_122 = F_86 ( V_44 -> V_5 ,
V_44 -> V_83 ) ;
V_125 = V_123 / V_122 *
V_44 -> V_83 ;
F_97 ( V_119 , L_8 , V_55 ,
V_44 -> V_5 , V_123 , V_124 , V_125 ) ;
V_126 += V_123 ;
V_127 += V_124 ;
V_128 += V_125 ;
}
F_100 ( V_119 , L_9 ) ;
F_97 ( V_119 , L_10 , L_11 , L_12 ,
V_126 , V_127 , V_128 ) ;
return 0 ;
}
static int F_101 ( struct V_132 * V_132 , struct V_133 * V_133 )
{
return F_102 ( V_133 , F_96 , V_132 -> V_134 ) ;
}
static int F_103 ( char * V_1 , struct V_50 * V_4 )
{
struct V_135 * V_136 ;
if ( ! V_117 )
return - V_116 ;
V_136 = F_93 ( V_1 , V_117 ) ;
if ( ! V_136 ) {
F_104 ( L_13 , V_1 ) ;
return - V_82 ;
}
V_4 -> V_137 = V_136 ;
V_136 = F_105 ( L_14 , V_138 | V_139 ,
V_4 -> V_137 , V_4 , & V_140 ) ;
if ( ! V_136 ) {
F_104 ( L_15 ,
V_1 , L_14 ) ;
return - V_82 ;
}
return 0 ;
}
static void F_106 ( struct V_50 * V_4 )
{
F_95 ( V_4 -> V_137 ) ;
}
static inline void F_88 ( struct V_43 * V_44 ,
enum V_112 type , unsigned long V_113 )
{
}
static inline void F_89 ( struct V_43 * V_44 ,
enum V_112 type , unsigned long V_113 )
{
}
static inline unsigned long F_90 ( struct V_43 * V_44 ,
enum V_112 type )
{
return 0 ;
}
static int T_4 F_91 ( void )
{
return 0 ;
}
static void T_5 F_94 ( void )
{
}
static inline int F_103 ( char * V_1 , struct V_50 * V_4 )
{
return 0 ;
}
static inline void F_106 ( struct V_50 * V_4 )
{
}
unsigned long F_15 ( struct V_50 * V_4 )
{
return F_107 ( & V_4 -> V_141 ) ;
}
void * F_11 ( struct V_50 * V_4 , unsigned long V_6 ,
enum V_12 V_11 )
{
struct V_21 * V_21 ;
unsigned long V_64 , V_67 ;
unsigned int V_22 ;
enum V_23 V_36 ;
struct V_43 * V_44 ;
struct V_85 * V_86 ;
struct V_21 * V_7 [ 2 ] ;
F_21 ( ! V_6 ) ;
F_21 ( F_108 () ) ;
F_40 ( V_6 , & V_21 , & V_64 ) ;
F_20 ( F_35 ( V_21 ) , & V_22 , & V_36 ) ;
V_44 = V_4 -> V_43 [ V_22 ] ;
V_67 = F_42 ( V_21 , V_64 , V_44 -> V_5 ) ;
V_86 = & F_109 ( V_104 ) ;
V_86 -> V_96 = V_11 ;
if ( V_67 + V_44 -> V_5 <= V_62 ) {
V_86 -> V_89 = F_52 ( V_21 ) ;
return V_86 -> V_89 + V_67 ;
}
V_7 [ 0 ] = V_21 ;
V_7 [ 1 ] = F_36 ( V_21 ) ;
F_21 ( ! V_7 [ 1 ] ) ;
return F_66 ( V_86 , V_7 , V_67 , V_44 -> V_5 ) ;
}
void F_13 ( struct V_50 * V_4 , unsigned long V_6 )
{
struct V_21 * V_21 ;
unsigned long V_64 , V_67 ;
unsigned int V_22 ;
enum V_23 V_36 ;
struct V_43 * V_44 ;
struct V_85 * V_86 ;
F_21 ( ! V_6 ) ;
F_40 ( V_6 , & V_21 , & V_64 ) ;
F_20 ( F_35 ( V_21 ) , & V_22 , & V_36 ) ;
V_44 = V_4 -> V_43 [ V_22 ] ;
V_67 = F_42 ( V_21 , V_64 , V_44 -> V_5 ) ;
V_86 = F_110 ( & V_104 ) ;
if ( V_67 + V_44 -> V_5 <= V_62 )
F_53 ( V_86 -> V_89 ) ;
else {
struct V_21 * V_7 [ 2 ] ;
V_7 [ 0 ] = V_21 ;
V_7 [ 1 ] = F_36 ( V_21 ) ;
F_21 ( ! V_7 [ 1 ] ) ;
F_68 ( V_86 , V_7 , V_67 , V_44 -> V_5 ) ;
}
F_111 ( V_104 ) ;
}
unsigned long F_6 ( struct V_50 * V_4 , T_2 V_5 )
{
unsigned long V_142 ;
struct V_77 * V_78 ;
struct V_43 * V_44 ;
void * V_79 ;
struct V_21 * V_63 , * V_143 ;
unsigned long V_144 , V_145 ;
if ( F_60 ( ! V_5 || V_5 > V_92 ) )
return 0 ;
V_44 = V_4 -> V_43 [ F_23 ( V_5 ) ] ;
F_98 ( & V_44 -> V_129 ) ;
V_63 = F_61 ( V_44 ) ;
if ( ! V_63 ) {
F_99 ( & V_44 -> V_129 ) ;
V_63 = F_54 ( V_44 , V_4 -> V_70 ) ;
if ( F_60 ( ! V_63 ) )
return 0 ;
F_22 ( V_63 , V_44 -> V_68 , V_38 ) ;
F_112 ( V_44 -> V_83 ,
& V_4 -> V_141 ) ;
F_98 ( & V_44 -> V_129 ) ;
F_88 ( V_44 , V_130 , F_86 (
V_44 -> V_5 , V_44 -> V_83 ) ) ;
}
V_142 = ( unsigned long ) V_63 -> V_72 ;
F_40 ( V_142 , & V_143 , & V_144 ) ;
V_145 = F_42 ( V_143 , V_144 , V_44 -> V_5 ) ;
V_79 = F_52 ( V_143 ) ;
V_78 = (struct V_77 * ) V_79 + V_145 / sizeof( * V_78 ) ;
V_63 -> V_72 = V_78 -> V_49 ;
memset ( V_78 , V_146 , sizeof( * V_78 ) ) ;
F_53 ( V_79 ) ;
V_63 -> V_34 ++ ;
F_88 ( V_44 , V_131 , 1 ) ;
F_33 ( V_4 , V_63 ) ;
F_99 ( & V_44 -> V_129 ) ;
return V_142 ;
}
void F_8 ( struct V_50 * V_4 , unsigned long V_142 )
{
struct V_77 * V_78 ;
struct V_21 * V_63 , * V_147 ;
unsigned long V_148 , V_149 ;
void * V_79 ;
int V_22 ;
struct V_43 * V_44 ;
enum V_23 V_24 ;
if ( F_60 ( ! V_142 ) )
return;
F_40 ( V_142 , & V_147 , & V_148 ) ;
V_63 = F_35 ( V_147 ) ;
F_20 ( V_63 , & V_22 , & V_24 ) ;
V_44 = V_4 -> V_43 [ V_22 ] ;
V_149 = F_42 ( V_147 , V_148 , V_44 -> V_5 ) ;
F_98 ( & V_44 -> V_129 ) ;
V_79 = F_52 ( V_147 ) ;
V_78 = (struct V_77 * ) ( V_79 + V_149 ) ;
V_78 -> V_49 = V_63 -> V_72 ;
F_53 ( V_79 ) ;
V_63 -> V_72 = ( void * ) V_142 ;
V_63 -> V_34 -- ;
V_24 = F_33 ( V_4 , V_63 ) ;
F_89 ( V_44 , V_131 , 1 ) ;
if ( V_24 == V_38 )
F_89 ( V_44 , V_130 , F_86 (
V_44 -> V_5 , V_44 -> V_83 ) ) ;
F_99 ( & V_44 -> V_129 ) ;
if ( V_24 == V_38 ) {
F_113 ( V_44 -> V_83 ,
& V_4 -> V_141 ) ;
F_47 ( V_63 ) ;
}
}
struct V_50 * F_2 ( char * V_1 , T_1 V_70 )
{
int V_55 ;
struct V_50 * V_4 ;
struct V_43 * V_150 = NULL ;
V_4 = F_114 ( sizeof( * V_4 ) , V_93 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_1 = F_115 ( V_1 , V_93 ) ;
if ( ! V_4 -> V_1 ) {
F_71 ( V_4 ) ;
return NULL ;
}
V_4 -> V_43 = F_116 ( V_110 , sizeof( struct V_43 * ) ,
V_93 ) ;
if ( ! V_4 -> V_43 ) {
F_71 ( V_4 -> V_1 ) ;
F_71 ( V_4 ) ;
return NULL ;
}
for ( V_55 = V_110 - 1 ; V_55 >= 0 ; V_55 -- ) {
int V_5 ;
int V_83 ;
struct V_43 * V_44 ;
V_5 = V_32 + V_55 * V_33 ;
if ( V_5 > V_92 )
V_5 = V_92 ;
V_83 = F_34 ( V_5 ) ;
if ( V_150 ) {
if ( F_87 ( V_150 , V_5 , V_83 ) ) {
V_4 -> V_43 [ V_55 ] = V_150 ;
continue;
}
}
V_44 = F_114 ( sizeof( struct V_43 ) , V_93 ) ;
if ( ! V_44 )
goto V_151;
V_44 -> V_5 = V_5 ;
V_44 -> V_68 = V_55 ;
V_44 -> V_83 = V_83 ;
F_117 ( & V_44 -> V_129 ) ;
V_4 -> V_43 [ V_55 ] = V_44 ;
V_150 = V_44 ;
}
V_4 -> V_70 = V_70 ;
if ( F_103 ( V_1 , V_4 ) )
goto V_151;
return V_4 ;
V_151:
F_4 ( V_4 ) ;
return NULL ;
}
void F_4 ( struct V_50 * V_4 )
{
int V_55 ;
F_106 ( V_4 ) ;
for ( V_55 = 0 ; V_55 < V_110 ; V_55 ++ ) {
int V_36 ;
struct V_43 * V_44 = V_4 -> V_43 [ V_55 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_68 != V_55 )
continue;
for ( V_36 = 0 ; V_36 < V_46 ; V_36 ++ ) {
if ( V_44 -> V_47 [ V_36 ] ) {
F_118 ( L_16 ,
V_44 -> V_5 , V_36 ) ;
}
}
F_71 ( V_44 ) ;
}
F_71 ( V_4 -> V_43 ) ;
F_71 ( V_4 -> V_1 ) ;
F_71 ( V_4 ) ;
}
static int T_4 F_119 ( void )
{
int V_101 = F_77 () ;
if ( V_101 )
goto V_152;
F_85 () ;
#ifdef F_120
F_121 ( & V_153 ) ;
#endif
V_101 = F_91 () ;
if ( V_101 ) {
F_122 ( L_17 ) ;
goto V_154;
}
return 0 ;
V_154:
#ifdef F_120
F_123 ( & V_153 ) ;
#endif
V_152:
F_83 () ;
return V_101 ;
}
static void T_5 F_124 ( void )
{
#ifdef F_120
F_123 ( & V_153 ) ;
#endif
F_83 () ;
F_94 () ;
}
