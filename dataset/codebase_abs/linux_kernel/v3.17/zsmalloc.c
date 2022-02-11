static void * F_1 ( T_1 V_1 , struct V_2 * V_2 )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( void * V_3 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( void * V_3 , T_2 V_4 , T_1 V_1 ,
unsigned long * V_5 )
{
* V_5 = F_6 ( V_3 , V_4 ) ;
return * V_5 ? 0 : - 1 ;
}
static void F_7 ( void * V_3 , unsigned long V_5 )
{
F_8 ( V_3 , V_5 ) ;
}
static int F_9 ( void * V_3 , unsigned int V_6 ,
unsigned int * V_7 )
{
return - V_8 ;
}
static void * F_10 ( void * V_3 , unsigned long V_5 ,
enum V_9 V_10 )
{
enum V_11 V_12 ;
switch ( V_10 ) {
case V_13 :
V_12 = V_14 ;
break;
case V_15 :
V_12 = V_16 ;
break;
case V_17 :
default:
V_12 = V_18 ;
break;
}
return F_11 ( V_3 , V_5 , V_12 ) ;
}
static void F_12 ( void * V_3 , unsigned long V_5 )
{
F_13 ( V_3 , V_5 ) ;
}
static T_3 F_14 ( void * V_3 )
{
return F_15 ( V_3 ) ;
}
static int F_16 ( struct V_19 * V_19 )
{
return F_17 ( V_19 ) ;
}
static int F_18 ( struct V_19 * V_19 )
{
return F_19 ( V_19 ) ;
}
static void F_20 ( struct V_19 * V_19 , unsigned int * V_20 ,
enum V_21 * V_22 )
{
unsigned long V_23 ;
F_21 ( ! F_16 ( V_19 ) ) ;
V_23 = ( unsigned long ) V_19 -> V_24 ;
* V_22 = V_23 & V_25 ;
* V_20 = ( V_23 >> V_26 ) & V_27 ;
}
static void F_22 ( struct V_19 * V_19 , unsigned int V_20 ,
enum V_21 V_22 )
{
unsigned long V_23 ;
F_21 ( ! F_16 ( V_19 ) ) ;
V_23 = ( ( V_20 & V_27 ) << V_26 ) |
( V_22 & V_25 ) ;
V_19 -> V_24 = (struct V_28 * ) V_23 ;
}
static int F_23 ( int V_4 )
{
int V_29 = 0 ;
if ( F_24 ( V_4 > V_30 ) )
V_29 = F_25 ( V_4 - V_30 ,
V_31 ) ;
return V_29 ;
}
static enum V_21 F_26 ( struct V_19 * V_19 )
{
int V_32 , V_33 ;
enum V_21 V_34 ;
F_21 ( ! F_16 ( V_19 ) ) ;
V_32 = V_19 -> V_32 ;
V_33 = V_19 -> V_35 ;
if ( V_32 == 0 )
V_34 = V_36 ;
else if ( V_32 == V_33 )
V_34 = V_37 ;
else if ( V_32 <= V_33 / V_38 )
V_34 = V_39 ;
else
V_34 = V_40 ;
return V_34 ;
}
static void F_27 ( struct V_19 * V_19 , struct V_41 * V_42 ,
enum V_21 V_22 )
{
struct V_19 * * V_43 ;
F_21 ( ! F_16 ( V_19 ) ) ;
if ( V_22 >= V_44 )
return;
V_43 = & V_42 -> V_45 [ V_22 ] ;
if ( * V_43 )
F_28 ( & V_19 -> V_46 , & ( * V_43 ) -> V_46 ) ;
* V_43 = V_19 ;
}
static void F_29 ( struct V_19 * V_19 , struct V_41 * V_42 ,
enum V_21 V_22 )
{
struct V_19 * * V_43 ;
F_21 ( ! F_16 ( V_19 ) ) ;
if ( V_22 >= V_44 )
return;
V_43 = & V_42 -> V_45 [ V_22 ] ;
F_21 ( ! * V_43 ) ;
if ( F_30 ( & ( * V_43 ) -> V_46 ) )
* V_43 = NULL ;
else if ( * V_43 == V_19 )
* V_43 = (struct V_19 * ) F_31 ( ( * V_43 ) -> V_46 . V_47 ,
struct V_19 , V_46 ) ;
F_32 ( & V_19 -> V_46 ) ;
}
static enum V_21 F_33 ( struct V_48 * V_3 ,
struct V_19 * V_19 )
{
int V_20 ;
struct V_41 * V_42 ;
enum V_21 V_49 , V_50 ;
F_21 ( ! F_16 ( V_19 ) ) ;
F_20 ( V_19 , & V_20 , & V_49 ) ;
V_50 = F_26 ( V_19 ) ;
if ( V_50 == V_49 )
goto V_51;
V_42 = & V_3 -> V_41 [ V_20 ] ;
F_29 ( V_19 , V_42 , V_49 ) ;
F_27 ( V_19 , V_42 , V_50 ) ;
F_22 ( V_19 , V_20 , V_50 ) ;
V_51:
return V_50 ;
}
static int F_34 ( int V_52 )
{
int V_53 , V_54 = 0 ;
int V_55 = 1 ;
for ( V_53 = 1 ; V_53 <= V_56 ; V_53 ++ ) {
int V_57 ;
int V_58 , V_59 ;
V_57 = V_53 * V_60 ;
V_58 = V_57 % V_52 ;
V_59 = ( V_57 - V_58 ) * 100 / V_57 ;
if ( V_59 > V_54 ) {
V_54 = V_59 ;
V_55 = V_53 ;
}
}
return V_55 ;
}
static struct V_19 * F_35 ( struct V_19 * V_19 )
{
if ( F_16 ( V_19 ) )
return V_19 ;
else
return V_19 -> V_61 ;
}
static struct V_19 * F_36 ( struct V_19 * V_19 )
{
struct V_19 * V_47 ;
if ( F_18 ( V_19 ) )
V_47 = NULL ;
else if ( F_16 ( V_19 ) )
V_47 = (struct V_19 * ) F_37 ( V_19 ) ;
else
V_47 = F_31 ( V_19 -> V_46 . V_47 , struct V_19 , V_46 ) ;
return V_47 ;
}
static void * F_38 ( struct V_19 * V_19 , unsigned long V_62 )
{
unsigned long V_5 ;
if ( ! V_19 ) {
F_21 ( V_62 ) ;
return NULL ;
}
V_5 = F_39 ( V_19 ) << V_63 ;
V_5 |= ( ( V_62 + 1 ) & V_64 ) ;
return ( void * ) V_5 ;
}
static void F_40 ( unsigned long V_5 , struct V_19 * * V_19 ,
unsigned long * V_62 )
{
* V_19 = F_41 ( V_5 >> V_63 ) ;
* V_62 = ( V_5 & V_64 ) - 1 ;
}
static unsigned long F_42 ( struct V_19 * V_19 ,
unsigned long V_62 , int V_52 )
{
unsigned long V_65 = 0 ;
if ( ! F_16 ( V_19 ) )
V_65 = V_19 -> V_66 ;
return V_65 + V_62 * V_52 ;
}
static void F_43 ( struct V_19 * V_19 )
{
F_44 ( V_67 , & V_19 -> V_68 ) ;
F_44 ( V_69 , & V_19 -> V_68 ) ;
F_45 ( V_19 , 0 ) ;
V_19 -> V_24 = NULL ;
V_19 -> V_70 = NULL ;
F_46 ( V_19 ) ;
}
static void F_47 ( struct V_19 * V_61 )
{
struct V_19 * V_71 , * V_72 , * V_73 ;
F_21 ( ! F_16 ( V_61 ) ) ;
F_21 ( V_61 -> V_32 ) ;
V_73 = (struct V_19 * ) F_37 ( V_61 ) ;
F_43 ( V_61 ) ;
F_48 ( V_61 ) ;
if ( ! V_73 )
return;
F_49 (nextp, tmp, &head_extra->lru, lru) {
F_50 ( & V_71 -> V_46 ) ;
F_43 ( V_71 ) ;
F_48 ( V_71 ) ;
}
F_43 ( V_73 ) ;
F_48 ( V_73 ) ;
}
static void F_51 ( struct V_19 * V_61 , struct V_41 * V_42 )
{
unsigned long V_65 = 0 ;
struct V_19 * V_19 = V_61 ;
F_21 ( ! F_16 ( V_61 ) ) ;
while ( V_19 ) {
struct V_19 * V_74 ;
struct V_75 * V_76 ;
unsigned int V_53 , V_77 ;
if ( V_19 != V_61 )
V_19 -> V_66 = V_65 ;
V_76 = (struct V_75 * ) F_52 ( V_19 ) +
V_65 / sizeof( * V_76 ) ;
V_77 = ( V_60 - V_65 ) / V_42 -> V_4 ;
for ( V_53 = 1 ; V_53 <= V_77 ; V_53 ++ ) {
V_65 += V_42 -> V_4 ;
if ( V_65 < V_60 ) {
V_76 -> V_47 = F_38 ( V_19 , V_53 ) ;
V_76 += V_42 -> V_4 / sizeof( * V_76 ) ;
}
}
V_74 = F_36 ( V_19 ) ;
V_76 -> V_47 = F_38 ( V_74 , 0 ) ;
F_53 ( V_76 ) ;
V_19 = V_74 ;
V_65 = ( V_65 + V_42 -> V_4 ) % V_60 ;
}
}
static struct V_19 * F_54 ( struct V_41 * V_42 , T_1 V_68 )
{
int V_53 , error ;
struct V_19 * V_61 = NULL , * V_78 ( V_79 ) ;
error = - V_80 ;
for ( V_53 = 0 ; V_53 < V_42 -> V_81 ; V_53 ++ ) {
struct V_19 * V_19 ;
V_19 = F_55 ( V_68 ) ;
if ( ! V_19 )
goto V_82;
F_56 ( & V_19 -> V_46 ) ;
if ( V_53 == 0 ) {
F_57 ( V_19 ) ;
F_45 ( V_19 , 0 ) ;
V_61 = V_19 ;
V_61 -> V_32 = 0 ;
}
if ( V_53 == 1 )
F_45 ( V_61 , ( unsigned long ) V_19 ) ;
if ( V_53 >= 1 )
V_19 -> V_61 = V_61 ;
if ( V_53 >= 2 )
F_58 ( & V_19 -> V_46 , & V_79 -> V_46 ) ;
if ( V_53 == V_42 -> V_81 - 1 )
F_59 ( V_19 ) ;
V_79 = V_19 ;
}
F_51 ( V_61 , V_42 ) ;
V_61 -> V_70 = F_38 ( V_61 , 0 ) ;
V_61 -> V_35 = V_42 -> V_81 * V_60 / V_42 -> V_4 ;
error = 0 ;
V_82:
if ( F_60 ( error ) && V_61 ) {
F_47 ( V_61 ) ;
V_61 = NULL ;
}
return V_61 ;
}
static struct V_19 * F_61 ( struct V_41 * V_42 )
{
int V_53 ;
struct V_19 * V_19 ;
for ( V_53 = 0 ; V_53 < V_44 ; V_53 ++ ) {
V_19 = V_42 -> V_45 [ V_53 ] ;
if ( V_19 )
break;
}
return V_19 ;
}
static inline int F_62 ( struct V_83 * V_84 )
{
if ( V_84 -> V_85 )
return 0 ;
V_84 -> V_85 = F_63 ( V_60 * 2 , NULL ) ;
if ( ! V_84 -> V_85 )
return - V_80 ;
return 0 ;
}
static inline void F_64 ( struct V_83 * V_84 )
{
if ( V_84 -> V_85 )
F_65 ( V_84 -> V_85 ) ;
V_84 -> V_85 = NULL ;
}
static inline void * F_66 ( struct V_83 * V_84 ,
struct V_19 * V_6 [ 2 ] , int V_65 , int V_4 )
{
F_21 ( F_67 ( V_84 -> V_85 , V_86 , V_6 ) ) ;
V_84 -> V_87 = V_84 -> V_85 -> V_88 ;
return V_84 -> V_87 + V_65 ;
}
static inline void F_68 ( struct V_83 * V_84 ,
struct V_19 * V_6 [ 2 ] , int V_65 , int V_4 )
{
unsigned long V_88 = ( unsigned long ) V_84 -> V_87 ;
F_69 ( V_88 , V_60 * 2 ) ;
}
static inline int F_62 ( struct V_83 * V_84 )
{
if ( V_84 -> V_89 )
return 0 ;
V_84 -> V_89 = ( char * ) F_70 ( V_90 ) ;
if ( ! V_84 -> V_89 )
return - V_80 ;
return 0 ;
}
static inline void F_64 ( struct V_83 * V_84 )
{
if ( V_84 -> V_89 )
F_71 ( ( unsigned long ) V_84 -> V_89 ) ;
V_84 -> V_89 = NULL ;
}
static void * F_66 ( struct V_83 * V_84 ,
struct V_19 * V_6 [ 2 ] , int V_65 , int V_4 )
{
int V_91 [ 2 ] ;
void * V_88 ;
char * V_92 = V_84 -> V_89 ;
F_72 () ;
if ( V_84 -> V_93 == V_16 )
goto V_51;
V_91 [ 0 ] = V_60 - V_65 ;
V_91 [ 1 ] = V_4 - V_91 [ 0 ] ;
V_88 = F_52 ( V_6 [ 0 ] ) ;
memcpy ( V_92 , V_88 + V_65 , V_91 [ 0 ] ) ;
F_53 ( V_88 ) ;
V_88 = F_52 ( V_6 [ 1 ] ) ;
memcpy ( V_92 + V_91 [ 0 ] , V_88 , V_91 [ 1 ] ) ;
F_53 ( V_88 ) ;
V_51:
return V_84 -> V_89 ;
}
static void F_68 ( struct V_83 * V_84 ,
struct V_19 * V_6 [ 2 ] , int V_65 , int V_4 )
{
int V_91 [ 2 ] ;
void * V_88 ;
char * V_92 = V_84 -> V_89 ;
if ( V_84 -> V_93 == V_14 )
goto V_51;
V_91 [ 0 ] = V_60 - V_65 ;
V_91 [ 1 ] = V_4 - V_91 [ 0 ] ;
V_88 = F_52 ( V_6 [ 0 ] ) ;
memcpy ( V_88 + V_65 , V_92 , V_91 [ 0 ] ) ;
F_53 ( V_88 ) ;
V_88 = F_52 ( V_6 [ 1 ] ) ;
memcpy ( V_88 , V_92 + V_91 [ 0 ] , V_91 [ 1 ] ) ;
F_53 ( V_88 ) ;
V_51:
F_73 () ;
}
static int F_74 ( struct V_94 * V_95 , unsigned long V_96 ,
void * V_97 )
{
int V_98 , V_99 = ( long ) V_97 ;
struct V_83 * V_84 ;
switch ( V_96 ) {
case V_100 :
V_84 = & F_75 ( V_101 , V_99 ) ;
V_98 = F_62 ( V_84 ) ;
if ( V_98 )
return F_76 ( V_98 ) ;
break;
case V_102 :
case V_103 :
V_84 = & F_75 ( V_101 , V_99 ) ;
F_64 ( V_84 ) ;
break;
}
return V_104 ;
}
static void F_77 ( void )
{
int V_99 ;
#ifdef F_78
F_79 ( & V_105 ) ;
#endif
F_80 () ;
F_81 (cpu)
F_74 ( NULL , V_102 , ( void * ) ( long ) V_99 ) ;
F_82 ( & V_106 ) ;
F_83 () ;
}
static int F_84 ( void )
{
int V_99 , V_98 ;
F_80 () ;
F_85 ( & V_106 ) ;
F_81 (cpu) {
V_98 = F_74 ( NULL , V_100 , ( void * ) ( long ) V_99 ) ;
if ( F_86 ( V_98 ) ) {
F_83 () ;
goto V_107;
}
}
F_83 () ;
#ifdef F_78
F_87 ( & V_105 ) ;
#endif
return 0 ;
V_107:
F_77 () ;
return F_86 ( V_98 ) ;
}
struct V_48 * F_2 ( T_1 V_68 )
{
int V_53 , V_108 ;
struct V_48 * V_3 ;
V_108 = F_88 ( sizeof( * V_3 ) , V_60 ) ;
V_3 = F_89 ( V_108 , V_90 ) ;
if ( ! V_3 )
return NULL ;
for ( V_53 = 0 ; V_53 < V_109 ; V_53 ++ ) {
int V_4 ;
struct V_41 * V_42 ;
V_4 = V_30 + V_53 * V_31 ;
if ( V_4 > V_110 )
V_4 = V_110 ;
V_42 = & V_3 -> V_41 [ V_53 ] ;
V_42 -> V_4 = V_4 ;
V_42 -> V_66 = V_53 ;
F_90 ( & V_42 -> V_111 ) ;
V_42 -> V_81 = F_34 ( V_4 ) ;
}
V_3 -> V_68 = V_68 ;
return V_3 ;
}
void F_4 ( struct V_48 * V_3 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < V_109 ; V_53 ++ ) {
int V_34 ;
struct V_41 * V_42 = & V_3 -> V_41 [ V_53 ] ;
for ( V_34 = 0 ; V_34 < V_44 ; V_34 ++ ) {
if ( V_42 -> V_45 [ V_34 ] ) {
F_91 ( L_1 ,
V_42 -> V_4 , V_34 ) ;
}
}
}
F_92 ( V_3 ) ;
}
unsigned long F_6 ( struct V_48 * V_3 , T_2 V_4 )
{
unsigned long V_112 ;
struct V_75 * V_76 ;
int V_20 ;
struct V_41 * V_42 ;
struct V_19 * V_61 , * V_113 ;
unsigned long V_114 , V_115 ;
if ( F_60 ( ! V_4 || V_4 > V_110 ) )
return 0 ;
V_20 = F_23 ( V_4 ) ;
V_42 = & V_3 -> V_41 [ V_20 ] ;
F_21 ( V_20 != V_42 -> V_66 ) ;
F_93 ( & V_42 -> V_111 ) ;
V_61 = F_61 ( V_42 ) ;
if ( ! V_61 ) {
F_94 ( & V_42 -> V_111 ) ;
V_61 = F_54 ( V_42 , V_3 -> V_68 ) ;
if ( F_60 ( ! V_61 ) )
return 0 ;
F_22 ( V_61 , V_42 -> V_66 , V_36 ) ;
F_93 ( & V_42 -> V_111 ) ;
V_42 -> V_116 += V_42 -> V_81 ;
}
V_112 = ( unsigned long ) V_61 -> V_70 ;
F_40 ( V_112 , & V_113 , & V_114 ) ;
V_115 = F_42 ( V_113 , V_114 , V_42 -> V_4 ) ;
V_76 = (struct V_75 * ) F_52 ( V_113 ) +
V_115 / sizeof( * V_76 ) ;
V_61 -> V_70 = V_76 -> V_47 ;
memset ( V_76 , V_117 , sizeof( * V_76 ) ) ;
F_53 ( V_76 ) ;
V_61 -> V_32 ++ ;
F_33 ( V_3 , V_61 ) ;
F_94 ( & V_42 -> V_111 ) ;
return V_112 ;
}
void F_8 ( struct V_48 * V_3 , unsigned long V_112 )
{
struct V_75 * V_76 ;
struct V_19 * V_61 , * V_118 ;
unsigned long V_119 , V_120 ;
int V_20 ;
struct V_41 * V_42 ;
enum V_21 V_22 ;
if ( F_60 ( ! V_112 ) )
return;
F_40 ( V_112 , & V_118 , & V_119 ) ;
V_61 = F_35 ( V_118 ) ;
F_20 ( V_61 , & V_20 , & V_22 ) ;
V_42 = & V_3 -> V_41 [ V_20 ] ;
V_120 = F_42 ( V_118 , V_119 , V_42 -> V_4 ) ;
F_93 ( & V_42 -> V_111 ) ;
V_76 = (struct V_75 * ) ( ( unsigned char * ) F_52 ( V_118 )
+ V_120 ) ;
V_76 -> V_47 = V_61 -> V_70 ;
F_53 ( V_76 ) ;
V_61 -> V_70 = ( void * ) V_112 ;
V_61 -> V_32 -- ;
V_22 = F_33 ( V_3 , V_61 ) ;
if ( V_22 == V_36 )
V_42 -> V_116 -= V_42 -> V_81 ;
F_94 ( & V_42 -> V_111 ) ;
if ( V_22 == V_36 )
F_47 ( V_61 ) ;
}
void * F_11 ( struct V_48 * V_3 , unsigned long V_5 ,
enum V_11 V_10 )
{
struct V_19 * V_19 ;
unsigned long V_62 , V_65 ;
unsigned int V_20 ;
enum V_21 V_34 ;
struct V_41 * V_42 ;
struct V_83 * V_84 ;
struct V_19 * V_6 [ 2 ] ;
F_21 ( ! V_5 ) ;
F_21 ( F_95 () ) ;
F_40 ( V_5 , & V_19 , & V_62 ) ;
F_20 ( F_35 ( V_19 ) , & V_20 , & V_34 ) ;
V_42 = & V_3 -> V_41 [ V_20 ] ;
V_65 = F_42 ( V_19 , V_62 , V_42 -> V_4 ) ;
V_84 = & F_96 ( V_101 ) ;
V_84 -> V_93 = V_10 ;
if ( V_65 + V_42 -> V_4 <= V_60 ) {
V_84 -> V_87 = F_52 ( V_19 ) ;
return V_84 -> V_87 + V_65 ;
}
V_6 [ 0 ] = V_19 ;
V_6 [ 1 ] = F_36 ( V_19 ) ;
F_21 ( ! V_6 [ 1 ] ) ;
return F_66 ( V_84 , V_6 , V_65 , V_42 -> V_4 ) ;
}
void F_13 ( struct V_48 * V_3 , unsigned long V_5 )
{
struct V_19 * V_19 ;
unsigned long V_62 , V_65 ;
unsigned int V_20 ;
enum V_21 V_34 ;
struct V_41 * V_42 ;
struct V_83 * V_84 ;
F_21 ( ! V_5 ) ;
F_40 ( V_5 , & V_19 , & V_62 ) ;
F_20 ( F_35 ( V_19 ) , & V_20 , & V_34 ) ;
V_42 = & V_3 -> V_41 [ V_20 ] ;
V_65 = F_42 ( V_19 , V_62 , V_42 -> V_4 ) ;
V_84 = F_97 ( & V_101 ) ;
if ( V_65 + V_42 -> V_4 <= V_60 )
F_53 ( V_84 -> V_87 ) ;
else {
struct V_19 * V_6 [ 2 ] ;
V_6 [ 0 ] = V_19 ;
V_6 [ 1 ] = F_36 ( V_19 ) ;
F_21 ( ! V_6 [ 1 ] ) ;
F_68 ( V_84 , V_6 , V_65 , V_42 -> V_4 ) ;
}
F_98 ( V_101 ) ;
}
T_3 F_15 ( struct V_48 * V_3 )
{
int V_53 ;
T_3 V_121 = 0 ;
for ( V_53 = 0 ; V_53 < V_109 ; V_53 ++ )
V_121 += V_3 -> V_41 [ V_53 ] . V_116 ;
return V_121 << V_122 ;
}
