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
return F_15 ( V_3 ) << V_19 ;
}
static int F_16 ( struct V_20 * V_20 )
{
return F_17 ( V_20 ) ;
}
static int F_18 ( struct V_20 * V_20 )
{
return F_19 ( V_20 ) ;
}
static void F_20 ( struct V_20 * V_20 , unsigned int * V_21 ,
enum V_22 * V_23 )
{
unsigned long V_24 ;
F_21 ( ! F_16 ( V_20 ) ) ;
V_24 = ( unsigned long ) V_20 -> V_25 ;
* V_23 = V_24 & V_26 ;
* V_21 = ( V_24 >> V_27 ) & V_28 ;
}
static void F_22 ( struct V_20 * V_20 , unsigned int V_21 ,
enum V_22 V_23 )
{
unsigned long V_24 ;
F_21 ( ! F_16 ( V_20 ) ) ;
V_24 = ( ( V_21 & V_28 ) << V_27 ) |
( V_23 & V_26 ) ;
V_20 -> V_25 = (struct V_29 * ) V_24 ;
}
static int F_23 ( int V_4 )
{
int V_30 = 0 ;
if ( F_24 ( V_4 > V_31 ) )
V_30 = F_25 ( V_4 - V_31 ,
V_32 ) ;
return V_30 ;
}
static enum V_22 F_26 ( struct V_20 * V_20 )
{
int V_33 , V_34 ;
enum V_22 V_35 ;
F_21 ( ! F_16 ( V_20 ) ) ;
V_33 = V_20 -> V_33 ;
V_34 = V_20 -> V_36 ;
if ( V_33 == 0 )
V_35 = V_37 ;
else if ( V_33 == V_34 )
V_35 = V_38 ;
else if ( V_33 <= V_34 / V_39 )
V_35 = V_40 ;
else
V_35 = V_41 ;
return V_35 ;
}
static void F_27 ( struct V_20 * V_20 , struct V_42 * V_43 ,
enum V_22 V_23 )
{
struct V_20 * * V_44 ;
F_21 ( ! F_16 ( V_20 ) ) ;
if ( V_23 >= V_45 )
return;
V_44 = & V_43 -> V_46 [ V_23 ] ;
if ( * V_44 )
F_28 ( & V_20 -> V_47 , & ( * V_44 ) -> V_47 ) ;
* V_44 = V_20 ;
}
static void F_29 ( struct V_20 * V_20 , struct V_42 * V_43 ,
enum V_22 V_23 )
{
struct V_20 * * V_44 ;
F_21 ( ! F_16 ( V_20 ) ) ;
if ( V_23 >= V_45 )
return;
V_44 = & V_43 -> V_46 [ V_23 ] ;
F_21 ( ! * V_44 ) ;
if ( F_30 ( & ( * V_44 ) -> V_47 ) )
* V_44 = NULL ;
else if ( * V_44 == V_20 )
* V_44 = (struct V_20 * ) F_31 ( ( * V_44 ) -> V_47 . V_48 ,
struct V_20 , V_47 ) ;
F_32 ( & V_20 -> V_47 ) ;
}
static enum V_22 F_33 ( struct V_49 * V_3 ,
struct V_20 * V_20 )
{
int V_21 ;
struct V_42 * V_43 ;
enum V_22 V_50 , V_51 ;
F_21 ( ! F_16 ( V_20 ) ) ;
F_20 ( V_20 , & V_21 , & V_50 ) ;
V_51 = F_26 ( V_20 ) ;
if ( V_51 == V_50 )
goto V_52;
V_43 = & V_3 -> V_42 [ V_21 ] ;
F_29 ( V_20 , V_43 , V_50 ) ;
F_27 ( V_20 , V_43 , V_51 ) ;
F_22 ( V_20 , V_21 , V_51 ) ;
V_52:
return V_51 ;
}
static int F_34 ( int V_53 )
{
int V_54 , V_55 = 0 ;
int V_56 = 1 ;
for ( V_54 = 1 ; V_54 <= V_57 ; V_54 ++ ) {
int V_58 ;
int V_59 , V_60 ;
V_58 = V_54 * V_61 ;
V_59 = V_58 % V_53 ;
V_60 = ( V_58 - V_59 ) * 100 / V_58 ;
if ( V_60 > V_55 ) {
V_55 = V_60 ;
V_56 = V_54 ;
}
}
return V_56 ;
}
static struct V_20 * F_35 ( struct V_20 * V_20 )
{
if ( F_16 ( V_20 ) )
return V_20 ;
else
return V_20 -> V_62 ;
}
static struct V_20 * F_36 ( struct V_20 * V_20 )
{
struct V_20 * V_48 ;
if ( F_18 ( V_20 ) )
V_48 = NULL ;
else if ( F_16 ( V_20 ) )
V_48 = (struct V_20 * ) F_37 ( V_20 ) ;
else
V_48 = F_31 ( V_20 -> V_47 . V_48 , struct V_20 , V_47 ) ;
return V_48 ;
}
static void * F_38 ( struct V_20 * V_20 , unsigned long V_63 )
{
unsigned long V_5 ;
if ( ! V_20 ) {
F_21 ( V_63 ) ;
return NULL ;
}
V_5 = F_39 ( V_20 ) << V_64 ;
V_5 |= ( ( V_63 + 1 ) & V_65 ) ;
return ( void * ) V_5 ;
}
static void F_40 ( unsigned long V_5 , struct V_20 * * V_20 ,
unsigned long * V_63 )
{
* V_20 = F_41 ( V_5 >> V_64 ) ;
* V_63 = ( V_5 & V_65 ) - 1 ;
}
static unsigned long F_42 ( struct V_20 * V_20 ,
unsigned long V_63 , int V_53 )
{
unsigned long V_66 = 0 ;
if ( ! F_16 ( V_20 ) )
V_66 = V_20 -> V_67 ;
return V_66 + V_63 * V_53 ;
}
static void F_43 ( struct V_20 * V_20 )
{
F_44 ( V_68 , & V_20 -> V_69 ) ;
F_44 ( V_70 , & V_20 -> V_69 ) ;
F_45 ( V_20 , 0 ) ;
V_20 -> V_25 = NULL ;
V_20 -> V_71 = NULL ;
F_46 ( V_20 ) ;
}
static void F_47 ( struct V_20 * V_62 )
{
struct V_20 * V_72 , * V_73 , * V_74 ;
F_21 ( ! F_16 ( V_62 ) ) ;
F_21 ( V_62 -> V_33 ) ;
V_74 = (struct V_20 * ) F_37 ( V_62 ) ;
F_43 ( V_62 ) ;
F_48 ( V_62 ) ;
if ( ! V_74 )
return;
F_49 (nextp, tmp, &head_extra->lru, lru) {
F_50 ( & V_72 -> V_47 ) ;
F_43 ( V_72 ) ;
F_48 ( V_72 ) ;
}
F_43 ( V_74 ) ;
F_48 ( V_74 ) ;
}
static void F_51 ( struct V_20 * V_62 , struct V_42 * V_43 )
{
unsigned long V_66 = 0 ;
struct V_20 * V_20 = V_62 ;
F_21 ( ! F_16 ( V_62 ) ) ;
while ( V_20 ) {
struct V_20 * V_75 ;
struct V_76 * V_77 ;
unsigned int V_54 = 1 ;
if ( V_20 != V_62 )
V_20 -> V_67 = V_66 ;
V_77 = (struct V_76 * ) F_52 ( V_20 ) +
V_66 / sizeof( * V_77 ) ;
while ( ( V_66 += V_43 -> V_4 ) < V_61 ) {
V_77 -> V_48 = F_38 ( V_20 , V_54 ++ ) ;
V_77 += V_43 -> V_4 / sizeof( * V_77 ) ;
}
V_75 = F_36 ( V_20 ) ;
V_77 -> V_48 = F_38 ( V_75 , 0 ) ;
F_53 ( V_77 ) ;
V_20 = V_75 ;
V_66 %= V_61 ;
}
}
static struct V_20 * F_54 ( struct V_42 * V_43 , T_1 V_69 )
{
int V_54 , error ;
struct V_20 * V_62 = NULL , * V_78 ( V_79 ) ;
error = - V_80 ;
for ( V_54 = 0 ; V_54 < V_43 -> V_81 ; V_54 ++ ) {
struct V_20 * V_20 ;
V_20 = F_55 ( V_69 ) ;
if ( ! V_20 )
goto V_82;
F_56 ( & V_20 -> V_47 ) ;
if ( V_54 == 0 ) {
F_57 ( V_20 ) ;
F_45 ( V_20 , 0 ) ;
V_62 = V_20 ;
V_62 -> V_33 = 0 ;
}
if ( V_54 == 1 )
F_45 ( V_62 , ( unsigned long ) V_20 ) ;
if ( V_54 >= 1 )
V_20 -> V_62 = V_62 ;
if ( V_54 >= 2 )
F_58 ( & V_20 -> V_47 , & V_79 -> V_47 ) ;
if ( V_54 == V_43 -> V_81 - 1 )
F_59 ( V_20 ) ;
V_79 = V_20 ;
}
F_51 ( V_62 , V_43 ) ;
V_62 -> V_71 = F_38 ( V_62 , 0 ) ;
V_62 -> V_36 = V_43 -> V_81 * V_61 / V_43 -> V_4 ;
error = 0 ;
V_82:
if ( F_60 ( error ) && V_62 ) {
F_47 ( V_62 ) ;
V_62 = NULL ;
}
return V_62 ;
}
static struct V_20 * F_61 ( struct V_42 * V_43 )
{
int V_54 ;
struct V_20 * V_20 ;
for ( V_54 = 0 ; V_54 < V_45 ; V_54 ++ ) {
V_20 = V_43 -> V_46 [ V_54 ] ;
if ( V_20 )
break;
}
return V_20 ;
}
static inline int F_62 ( struct V_83 * V_84 )
{
if ( V_84 -> V_85 )
return 0 ;
V_84 -> V_85 = F_63 ( V_61 * 2 , NULL ) ;
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
struct V_20 * V_6 [ 2 ] , int V_66 , int V_4 )
{
F_21 ( F_67 ( V_84 -> V_85 , V_86 , V_6 ) ) ;
V_84 -> V_87 = V_84 -> V_85 -> V_88 ;
return V_84 -> V_87 + V_66 ;
}
static inline void F_68 ( struct V_83 * V_84 ,
struct V_20 * V_6 [ 2 ] , int V_66 , int V_4 )
{
unsigned long V_88 = ( unsigned long ) V_84 -> V_87 ;
F_69 ( V_88 , V_61 * 2 ) ;
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
struct V_20 * V_6 [ 2 ] , int V_66 , int V_4 )
{
int V_91 [ 2 ] ;
void * V_88 ;
char * V_92 = V_84 -> V_89 ;
F_72 () ;
if ( V_84 -> V_93 == V_16 )
goto V_52;
V_91 [ 0 ] = V_61 - V_66 ;
V_91 [ 1 ] = V_4 - V_91 [ 0 ] ;
V_88 = F_52 ( V_6 [ 0 ] ) ;
memcpy ( V_92 , V_88 + V_66 , V_91 [ 0 ] ) ;
F_53 ( V_88 ) ;
V_88 = F_52 ( V_6 [ 1 ] ) ;
memcpy ( V_92 + V_91 [ 0 ] , V_88 , V_91 [ 1 ] ) ;
F_53 ( V_88 ) ;
V_52:
return V_84 -> V_89 ;
}
static void F_68 ( struct V_83 * V_84 ,
struct V_20 * V_6 [ 2 ] , int V_66 , int V_4 )
{
int V_91 [ 2 ] ;
void * V_88 ;
char * V_92 = V_84 -> V_89 ;
if ( V_84 -> V_93 == V_14 )
goto V_52;
V_91 [ 0 ] = V_61 - V_66 ;
V_91 [ 1 ] = V_4 - V_91 [ 0 ] ;
V_88 = F_52 ( V_6 [ 0 ] ) ;
memcpy ( V_88 + V_66 , V_92 , V_91 [ 0 ] ) ;
F_53 ( V_88 ) ;
V_88 = F_52 ( V_6 [ 1 ] ) ;
memcpy ( V_88 , V_92 + V_91 [ 0 ] , V_91 [ 1 ] ) ;
F_53 ( V_88 ) ;
V_52:
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
struct V_49 * F_2 ( T_1 V_69 )
{
int V_54 , V_108 ;
struct V_49 * V_3 ;
V_108 = F_88 ( sizeof( * V_3 ) , V_61 ) ;
V_3 = F_89 ( V_108 , V_90 ) ;
if ( ! V_3 )
return NULL ;
for ( V_54 = 0 ; V_54 < V_109 ; V_54 ++ ) {
int V_4 ;
struct V_42 * V_43 ;
V_4 = V_31 + V_54 * V_32 ;
if ( V_4 > V_110 )
V_4 = V_110 ;
V_43 = & V_3 -> V_42 [ V_54 ] ;
V_43 -> V_4 = V_4 ;
V_43 -> V_67 = V_54 ;
F_90 ( & V_43 -> V_111 ) ;
V_43 -> V_81 = F_34 ( V_4 ) ;
}
V_3 -> V_69 = V_69 ;
return V_3 ;
}
void F_4 ( struct V_49 * V_3 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_109 ; V_54 ++ ) {
int V_35 ;
struct V_42 * V_43 = & V_3 -> V_42 [ V_54 ] ;
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ ) {
if ( V_43 -> V_46 [ V_35 ] ) {
F_91 ( L_1 ,
V_43 -> V_4 , V_35 ) ;
}
}
}
F_92 ( V_3 ) ;
}
unsigned long F_6 ( struct V_49 * V_3 , T_2 V_4 )
{
unsigned long V_112 ;
struct V_76 * V_77 ;
int V_21 ;
struct V_42 * V_43 ;
struct V_20 * V_62 , * V_113 ;
unsigned long V_114 , V_115 ;
if ( F_60 ( ! V_4 || V_4 > V_110 ) )
return 0 ;
V_21 = F_23 ( V_4 ) ;
V_43 = & V_3 -> V_42 [ V_21 ] ;
F_21 ( V_21 != V_43 -> V_67 ) ;
F_93 ( & V_43 -> V_111 ) ;
V_62 = F_61 ( V_43 ) ;
if ( ! V_62 ) {
F_94 ( & V_43 -> V_111 ) ;
V_62 = F_54 ( V_43 , V_3 -> V_69 ) ;
if ( F_60 ( ! V_62 ) )
return 0 ;
F_22 ( V_62 , V_43 -> V_67 , V_37 ) ;
F_95 ( V_43 -> V_81 ,
& V_3 -> V_116 ) ;
F_93 ( & V_43 -> V_111 ) ;
}
V_112 = ( unsigned long ) V_62 -> V_71 ;
F_40 ( V_112 , & V_113 , & V_114 ) ;
V_115 = F_42 ( V_113 , V_114 , V_43 -> V_4 ) ;
V_77 = (struct V_76 * ) F_52 ( V_113 ) +
V_115 / sizeof( * V_77 ) ;
V_62 -> V_71 = V_77 -> V_48 ;
memset ( V_77 , V_117 , sizeof( * V_77 ) ) ;
F_53 ( V_77 ) ;
V_62 -> V_33 ++ ;
F_33 ( V_3 , V_62 ) ;
F_94 ( & V_43 -> V_111 ) ;
return V_112 ;
}
void F_8 ( struct V_49 * V_3 , unsigned long V_112 )
{
struct V_76 * V_77 ;
struct V_20 * V_62 , * V_118 ;
unsigned long V_119 , V_120 ;
int V_21 ;
struct V_42 * V_43 ;
enum V_22 V_23 ;
if ( F_60 ( ! V_112 ) )
return;
F_40 ( V_112 , & V_118 , & V_119 ) ;
V_62 = F_35 ( V_118 ) ;
F_20 ( V_62 , & V_21 , & V_23 ) ;
V_43 = & V_3 -> V_42 [ V_21 ] ;
V_120 = F_42 ( V_118 , V_119 , V_43 -> V_4 ) ;
F_93 ( & V_43 -> V_111 ) ;
V_77 = (struct V_76 * ) ( ( unsigned char * ) F_52 ( V_118 )
+ V_120 ) ;
V_77 -> V_48 = V_62 -> V_71 ;
F_53 ( V_77 ) ;
V_62 -> V_71 = ( void * ) V_112 ;
V_62 -> V_33 -- ;
V_23 = F_33 ( V_3 , V_62 ) ;
F_94 ( & V_43 -> V_111 ) ;
if ( V_23 == V_37 ) {
F_96 ( V_43 -> V_81 ,
& V_3 -> V_116 ) ;
F_47 ( V_62 ) ;
}
}
void * F_11 ( struct V_49 * V_3 , unsigned long V_5 ,
enum V_11 V_10 )
{
struct V_20 * V_20 ;
unsigned long V_63 , V_66 ;
unsigned int V_21 ;
enum V_22 V_35 ;
struct V_42 * V_43 ;
struct V_83 * V_84 ;
struct V_20 * V_6 [ 2 ] ;
F_21 ( ! V_5 ) ;
F_21 ( F_97 () ) ;
F_40 ( V_5 , & V_20 , & V_63 ) ;
F_20 ( F_35 ( V_20 ) , & V_21 , & V_35 ) ;
V_43 = & V_3 -> V_42 [ V_21 ] ;
V_66 = F_42 ( V_20 , V_63 , V_43 -> V_4 ) ;
V_84 = & F_98 ( V_101 ) ;
V_84 -> V_93 = V_10 ;
if ( V_66 + V_43 -> V_4 <= V_61 ) {
V_84 -> V_87 = F_52 ( V_20 ) ;
return V_84 -> V_87 + V_66 ;
}
V_6 [ 0 ] = V_20 ;
V_6 [ 1 ] = F_36 ( V_20 ) ;
F_21 ( ! V_6 [ 1 ] ) ;
return F_66 ( V_84 , V_6 , V_66 , V_43 -> V_4 ) ;
}
void F_13 ( struct V_49 * V_3 , unsigned long V_5 )
{
struct V_20 * V_20 ;
unsigned long V_63 , V_66 ;
unsigned int V_21 ;
enum V_22 V_35 ;
struct V_42 * V_43 ;
struct V_83 * V_84 ;
F_21 ( ! V_5 ) ;
F_40 ( V_5 , & V_20 , & V_63 ) ;
F_20 ( F_35 ( V_20 ) , & V_21 , & V_35 ) ;
V_43 = & V_3 -> V_42 [ V_21 ] ;
V_66 = F_42 ( V_20 , V_63 , V_43 -> V_4 ) ;
V_84 = F_99 ( & V_101 ) ;
if ( V_66 + V_43 -> V_4 <= V_61 )
F_53 ( V_84 -> V_87 ) ;
else {
struct V_20 * V_6 [ 2 ] ;
V_6 [ 0 ] = V_20 ;
V_6 [ 1 ] = F_36 ( V_20 ) ;
F_21 ( ! V_6 [ 1 ] ) ;
F_68 ( V_84 , V_6 , V_66 , V_43 -> V_4 ) ;
}
F_100 ( V_101 ) ;
}
unsigned long F_15 ( struct V_49 * V_3 )
{
return F_101 ( & V_3 -> V_116 ) ;
}
