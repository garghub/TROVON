static inline void F_1 ( const char * V_1 )
{
V_2 = 0 ;
F_2 ( V_3 L_1 , V_1 ) ;
}
static int T_1 F_3 ( char * V_4 )
{
F_1 ( L_2 ) ;
return 0 ;
}
static inline void F_1 ( const char * V_1 )
{
( void ) V_1 ;
}
static int T_1 F_4 ( char * V_4 )
{
V_5 = 1 ;
return 0 ;
}
static inline enum V_6 F_5 ( struct V_7 * V_8 )
{
unsigned long V_9 = V_8 -> V_10 & V_11 ;
if ( V_9 == V_12 )
return - 1 ;
else if ( V_9 == V_13 )
return V_14 ;
else if ( V_9 == V_15 )
return V_16 ;
else
return V_17 ;
}
static inline void F_6 ( struct V_7 * V_8 ,
enum V_6 V_18 )
{
unsigned long V_19 ;
unsigned long V_20 ;
unsigned long V_21 ;
switch ( V_18 ) {
case V_14 :
V_19 = V_13 ;
break;
case V_16 :
V_19 = V_15 ;
break;
case V_17 :
V_19 = V_22 ;
break;
default:
V_19 = V_12 ;
break;
}
do {
V_20 = V_8 -> V_10 ;
V_21 = ( V_20 & V_23 ) | V_19 ;
} while ( F_7 ( & V_8 -> V_10 , V_20 , V_21 ) != V_20 );
}
static inline enum V_6 F_5 ( struct V_7 * V_8 )
{
return - 1 ;
}
static inline void F_6 ( struct V_7 * V_8 ,
enum V_6 V_18 )
{
}
static enum V_6 F_8 ( unsigned V_24 , char * V_25 )
{
enum V_6 V_26 ;
char * V_27 ;
switch ( V_24 ) {
case V_28 : V_26 = F_9 ( V_29 ) ; V_27 = L_3 ; break;
case V_30 : V_26 = F_9 ( V_31 ) ; V_27 = L_4 ; break;
case V_32 : V_26 = F_9 ( V_33 ) ; V_27 = L_5 ; break;
case V_34 : V_26 = F_9 ( V_35 ) ; V_27 = L_6 ; break;
case V_36 : V_26 = F_9 ( V_37 ) ; V_27 = L_7 ; break;
case V_38 : V_26 = F_9 ( V_39 ) ; V_27 = L_8 ; break;
default: V_26 = F_9 ( V_37 ) ; V_27 = L_7 ; break;
}
memcpy ( V_25 , V_27 , 4 ) ;
return V_26 ;
}
void F_10 ( void )
{
int V_40 ;
enum V_6 V_26 ;
char V_41 [ 33 ] ;
T_2 V_42 ;
F_11 ( V_43 , V_42 ) ;
V_41 [ 32 ] = 0 ;
for ( V_40 = 7 ; V_40 >= 0 ; V_40 -- ) {
V_26 = F_8 ( ( V_42 >> ( V_40 * 8 ) ) & 7 ,
V_41 + 4 * V_40 ) ;
F_12 ( V_40 , V_26 ) ;
}
F_13 ( L_9 , V_41 ) ;
}
void F_14 ( void )
{
T_2 V_42 ;
bool V_44 = ! V_45 ;
if ( ! V_2 )
return;
if ( ! V_46 ) {
if ( ! V_45 ) {
F_1 ( L_10 ) ;
return;
} else {
F_2 ( V_47 L_11
L_12 ) ;
F_15 () ;
}
}
V_42 = F_16 ( 0 , V_37 ) | F_16 ( 1 , V_31 ) | F_16 ( 2 , V_39 ) | F_16 ( 3 , V_29 ) |
F_16 ( 4 , V_37 ) | F_16 ( 5 , V_31 ) | F_16 ( 6 , V_39 ) | F_16 ( 7 , V_29 ) ;
if ( ! V_45 ) {
F_11 ( V_43 , V_45 ) ;
if ( ! V_45 ) {
F_1 ( L_13 ) ;
return;
}
}
F_17 ( V_43 , V_42 ) ;
if ( V_44 )
F_10 () ;
}
static unsigned long F_18 ( T_2 V_48 , T_2 V_49 ,
enum V_6 V_50 )
{
if ( V_50 == V_17 ) {
T_3 V_51 ;
V_51 = F_19 ( V_48 , V_49 ) ;
if ( V_51 != V_52 )
return V_16 ;
return V_17 ;
}
return V_50 ;
}
static int
F_20 ( unsigned long V_53 , unsigned long V_54 , void * V_55 )
{
struct V_56 * V_57 = V_55 ;
V_57 -> V_58 |= V_53 > V_57 -> V_59 ;
V_57 -> V_60 |= V_54 > 0 ;
V_57 -> V_59 = V_53 + V_54 ;
return V_57 -> V_60 && V_57 -> V_58 ;
}
static int F_21 ( T_4 V_48 , T_4 V_49 )
{
int V_61 = 0 ;
unsigned long V_62 = V_48 >> V_63 ;
unsigned long V_64 = ( V_49 + V_65 - 1 ) >> V_63 ;
struct V_56 V_57 = { V_62 , 0 , 0 } ;
if ( V_62 < V_66 > > V_63 )
V_62 = V_66 >> V_63 ;
if ( V_62 < V_64 ) {
V_61 = F_22 ( V_62 , V_64 - V_62 ,
& V_57 , F_20 ) ;
}
return ( V_61 > 0 ) ? - 1 : ( V_57 . V_60 ? 1 : 0 ) ;
}
static int F_23 ( T_2 V_48 , T_2 V_49 ,
enum V_6 V_50 ,
enum V_6 * V_67 )
{
struct V_7 * V_7 ;
T_2 V_68 ;
if ( V_50 == V_69 ) {
F_24 ( 1 ) ;
V_50 = V_16 ;
}
for ( V_68 = ( V_48 >> V_63 ) ; V_68 < ( V_49 >> V_63 ) ; ++ V_68 ) {
enum V_6 type ;
V_7 = F_25 ( V_68 ) ;
type = F_5 ( V_7 ) ;
if ( type != - 1 ) {
F_13 ( L_14 ,
V_48 , V_49 - 1 , type , V_50 ) ;
if ( V_67 )
* V_67 = type ;
return - V_70 ;
}
}
if ( V_67 )
* V_67 = V_50 ;
for ( V_68 = ( V_48 >> V_63 ) ; V_68 < ( V_49 >> V_63 ) ; ++ V_68 ) {
V_7 = F_25 ( V_68 ) ;
F_6 ( V_7 , V_50 ) ;
}
return 0 ;
}
static int F_26 ( T_2 V_48 , T_2 V_49 )
{
struct V_7 * V_7 ;
T_2 V_68 ;
for ( V_68 = ( V_48 >> V_63 ) ; V_68 < ( V_49 >> V_63 ) ; ++ V_68 ) {
V_7 = F_25 ( V_68 ) ;
F_6 ( V_7 , - 1 ) ;
}
return 0 ;
}
int F_27 ( T_2 V_48 , T_2 V_49 , enum V_6 V_50 ,
enum V_6 * V_67 )
{
struct V_18 * V_71 ;
enum V_6 V_72 ;
int V_73 ;
int V_74 = 0 ;
F_28 ( V_48 >= V_49 ) ;
if ( ! V_2 ) {
if ( V_67 ) {
if ( V_50 == V_14 )
* V_67 = V_16 ;
else
* V_67 = V_50 ;
}
return 0 ;
}
if ( V_75 . V_76 ( V_48 , V_49 ) ) {
if ( V_67 )
* V_67 = V_17 ;
return 0 ;
}
V_72 = F_18 ( V_48 , V_49 , V_50 ) ;
if ( V_67 )
* V_67 = V_72 ;
V_73 = F_21 ( V_48 , V_49 ) ;
if ( V_73 == 1 ) {
V_74 = F_23 ( V_48 , V_49 , V_50 , V_67 ) ;
return V_74 ;
} else if ( V_73 < 0 ) {
return - V_77 ;
}
V_71 = F_29 ( sizeof( struct V_18 ) , V_78 ) ;
if ( ! V_71 )
return - V_79 ;
V_71 -> V_48 = V_48 ;
V_71 -> V_49 = V_49 ;
V_71 -> type = V_72 ;
F_30 ( & V_80 ) ;
V_74 = F_31 ( V_71 , V_67 ) ;
if ( V_74 ) {
F_2 ( V_3 L_15 ,
V_48 , V_49 - 1 ,
F_32 ( V_71 -> type ) , F_32 ( V_50 ) ) ;
F_33 ( V_71 ) ;
F_34 ( & V_80 ) ;
return V_74 ;
}
F_34 ( & V_80 ) ;
F_35 ( L_16 ,
V_48 , V_49 - 1 , F_32 ( V_71 -> type ) , F_32 ( V_50 ) ,
V_67 ? F_32 ( * V_67 ) : L_17 ) ;
return V_74 ;
}
int F_36 ( T_2 V_48 , T_2 V_49 )
{
int V_74 = - V_77 ;
int V_73 ;
struct V_18 * V_81 ;
if ( ! V_2 )
return 0 ;
if ( V_75 . V_76 ( V_48 , V_49 ) )
return 0 ;
V_73 = F_21 ( V_48 , V_49 ) ;
if ( V_73 == 1 ) {
V_74 = F_26 ( V_48 , V_49 ) ;
return V_74 ;
} else if ( V_73 < 0 ) {
return - V_77 ;
}
F_30 ( & V_80 ) ;
V_81 = F_37 ( V_48 , V_49 ) ;
F_34 ( & V_80 ) ;
if ( ! V_81 ) {
F_2 ( V_3 L_18 ,
V_82 -> V_83 , V_82 -> V_84 , V_48 , V_49 - 1 ) ;
return - V_77 ;
}
F_33 ( V_81 ) ;
F_35 ( L_19 , V_48 , V_49 - 1 ) ;
return 0 ;
}
static enum V_6 F_38 ( T_2 V_85 )
{
enum V_6 V_86 = V_17 ;
struct V_18 * V_81 ;
if ( V_75 . V_76 ( V_85 , V_85 + V_65 ) )
return V_86 ;
if ( F_21 ( V_85 , V_85 + V_65 ) ) {
struct V_7 * V_7 ;
V_7 = F_25 ( V_85 >> V_63 ) ;
V_86 = F_5 ( V_7 ) ;
if ( V_86 == - 1 )
V_86 = V_17 ;
return V_86 ;
}
F_30 ( & V_80 ) ;
V_81 = F_39 ( V_85 ) ;
if ( V_81 != NULL )
V_86 = V_81 -> type ;
else
V_86 = V_16 ;
F_34 ( & V_80 ) ;
return V_86 ;
}
int F_40 ( T_4 V_48 , T_4 V_49 ,
enum V_6 * type )
{
T_4 V_87 = V_49 - V_48 ;
enum V_6 V_50 = * type ;
enum V_6 V_67 ;
int V_61 ;
F_24 ( F_41 ( V_48 , V_87 ) ) ;
V_61 = F_27 ( V_48 , V_49 , V_50 , & V_67 ) ;
if ( V_61 )
goto V_88;
if ( ! F_42 ( V_48 , V_87 , V_50 , V_67 ) )
goto V_89;
if ( F_43 ( V_48 , V_87 , V_67 ) < 0 )
goto V_89;
* type = V_67 ;
return 0 ;
V_89:
F_36 ( V_48 , V_49 ) ;
V_61 = - V_70 ;
V_88:
return V_61 ;
}
void F_44 ( T_4 V_48 , T_4 V_49 )
{
F_36 ( V_48 , V_49 ) ;
}
T_5 F_45 ( struct V_90 * V_90 , unsigned long V_68 ,
unsigned long V_87 , T_5 V_91 )
{
return V_91 ;
}
static inline int F_46 ( unsigned long V_68 , unsigned long V_87 )
{
return 1 ;
}
static inline int F_46 ( unsigned long V_68 , unsigned long V_87 )
{
T_2 V_92 = ( ( T_2 ) V_68 ) << V_63 ;
T_2 V_93 = V_92 + V_87 ;
T_2 V_94 = V_92 ;
if ( ! V_2 )
return 1 ;
while ( V_94 < V_93 ) {
if ( ! F_47 ( V_68 ) ) {
F_2 ( V_3 L_20 ,
V_82 -> V_83 , V_92 , V_93 - 1 ) ;
return 0 ;
}
V_94 += V_65 ;
V_68 ++ ;
}
return 1 ;
}
int F_48 ( struct V_90 * V_90 , unsigned long V_68 ,
unsigned long V_87 , T_5 * V_91 )
{
enum V_6 V_95 = V_17 ;
if ( ! F_46 ( V_68 , V_87 ) )
return 0 ;
if ( V_90 -> V_96 & V_97 )
V_95 = V_16 ;
#ifdef F_49
if ( ! V_2 &&
! ( F_50 ( V_98 ) ||
F_50 ( V_99 ) ||
F_50 ( V_100 ) ||
F_50 ( V_101 ) ) &&
( V_68 << V_63 ) >= F_51 ( V_102 ) ) {
V_95 = V_69 ;
}
#endif
* V_91 = F_52 ( ( F_53 ( * V_91 ) & ~ V_103 ) |
F_54 ( V_95 ) ) ;
return 1 ;
}
int F_43 ( T_2 V_104 , unsigned long V_87 ,
enum V_6 V_95 )
{
unsigned long V_105 ;
if ( V_104 > F_51 ( V_102 - 1 ) )
return 0 ;
if ( ! F_55 ( V_104 >> V_63 ) )
return 0 ;
V_105 = ( F_51 ( V_102 - 1 ) <= V_104 + V_87 ) ?
F_51 ( V_102 ) - V_104 :
V_87 ;
if ( F_56 ( ( unsigned long ) F_57 ( V_104 ) , V_105 , V_95 ) < 0 ) {
F_2 ( V_3 L_21
L_22 ,
V_82 -> V_83 , V_82 -> V_84 ,
F_32 ( V_95 ) ,
V_104 , ( unsigned long long ) ( V_104 + V_87 - 1 ) ) ;
return - V_77 ;
}
return 0 ;
}
static int F_58 ( T_2 V_85 , unsigned long V_87 , T_5 * V_91 ,
int V_106 )
{
int V_107 = 0 ;
int V_61 ;
enum V_6 V_108 = F_59 ( * V_91 ) ;
enum V_6 V_95 = V_108 ;
V_107 = F_21 ( V_85 , V_85 + V_87 ) ;
if ( V_107 ) {
if ( ! V_2 )
return 0 ;
V_95 = F_38 ( V_85 ) ;
if ( V_108 != V_95 ) {
F_2 ( V_109 L_23 ,
V_82 -> V_83 , V_82 -> V_84 ,
F_32 ( V_108 ) ,
( unsigned long long ) V_85 ,
( unsigned long long ) ( V_85 + V_87 - 1 ) ,
F_32 ( V_95 ) ) ;
* V_91 = F_52 ( ( F_53 ( * V_91 ) &
( ~ V_103 ) ) |
F_54 ( V_95 ) ) ;
}
return 0 ;
}
V_61 = F_27 ( V_85 , V_85 + V_87 , V_108 , & V_95 ) ;
if ( V_61 )
return V_61 ;
if ( V_95 != V_108 ) {
if ( V_106 ||
! F_42 ( V_85 , V_87 , V_108 , V_95 ) ) {
F_36 ( V_85 , V_85 + V_87 ) ;
F_2 ( V_47 L_24
L_25 ,
V_82 -> V_83 , V_82 -> V_84 ,
F_32 ( V_108 ) ,
( unsigned long long ) V_85 ,
( unsigned long long ) ( V_85 + V_87 - 1 ) ,
F_32 ( V_95 ) ) ;
return - V_77 ;
}
* V_91 = F_52 ( ( F_53 ( * V_91 ) &
( ~ V_103 ) ) |
F_54 ( V_95 ) ) ;
}
if ( F_43 ( V_85 , V_87 , V_95 ) < 0 ) {
F_36 ( V_85 , V_85 + V_87 ) ;
return - V_77 ;
}
return 0 ;
}
static void F_60 ( T_2 V_85 , unsigned long V_87 )
{
int V_107 ;
V_107 = F_21 ( V_85 , V_85 + V_87 ) ;
if ( V_107 == 0 )
F_36 ( V_85 , V_85 + V_87 ) ;
}
int F_61 ( struct V_110 * V_111 )
{
T_4 V_85 ;
unsigned long V_112 ;
unsigned long V_113 = V_111 -> V_114 - V_111 -> V_115 ;
T_5 V_116 ;
if ( V_111 -> V_117 & V_118 ) {
if ( F_62 ( V_111 , V_111 -> V_115 , 0 , & V_112 , & V_85 ) ) {
F_24 ( 1 ) ;
return - V_77 ;
}
V_116 = F_52 ( V_112 ) ;
return F_58 ( V_85 , V_113 , & V_116 , 1 ) ;
}
return 0 ;
}
int F_63 ( struct V_110 * V_111 , T_5 * V_112 ,
unsigned long V_68 , unsigned long V_119 , unsigned long V_87 )
{
T_4 V_85 = ( T_4 ) V_68 << V_63 ;
enum V_6 V_95 ;
if ( V_119 == V_111 -> V_115 && V_87 == ( V_111 -> V_114 - V_111 -> V_115 ) ) {
int V_61 ;
V_61 = F_58 ( V_85 , V_87 , V_112 , 0 ) ;
if ( ! V_61 )
V_111 -> V_117 |= V_118 ;
return V_61 ;
}
if ( ! V_2 )
return 0 ;
V_95 = F_38 ( V_85 ) ;
while ( V_87 > V_65 ) {
V_87 -= V_65 ;
V_85 += V_65 ;
if ( V_95 != F_38 ( V_85 ) )
return - V_77 ;
}
* V_112 = F_52 ( ( F_53 ( V_111 -> V_120 ) & ( ~ V_103 ) ) |
F_54 ( V_95 ) ) ;
return 0 ;
}
int F_64 ( struct V_110 * V_111 , T_5 * V_112 ,
unsigned long V_68 )
{
enum V_6 V_95 ;
if ( ! V_2 )
return 0 ;
V_95 = F_38 ( ( T_4 ) V_68 << V_63 ) ;
* V_112 = F_52 ( ( F_53 ( V_111 -> V_120 ) & ( ~ V_103 ) ) |
F_54 ( V_95 ) ) ;
return 0 ;
}
void F_65 ( struct V_110 * V_111 , unsigned long V_68 ,
unsigned long V_87 )
{
T_4 V_85 ;
unsigned long V_112 ;
if ( ! ( V_111 -> V_117 & V_118 ) )
return;
V_85 = ( T_4 ) V_68 << V_63 ;
if ( ! V_85 && ! V_87 ) {
if ( F_62 ( V_111 , V_111 -> V_115 , 0 , & V_112 , & V_85 ) ) {
F_24 ( 1 ) ;
return;
}
V_87 = V_111 -> V_114 - V_111 -> V_115 ;
}
F_60 ( V_85 , V_87 ) ;
V_111 -> V_117 &= ~ V_118 ;
}
T_5 F_66 ( T_5 V_112 )
{
if ( V_2 )
return F_52 ( F_53 ( V_112 ) |
F_54 ( V_14 ) ) ;
else
return F_67 ( V_112 ) ;
}
static struct V_18 * F_68 ( T_6 V_121 )
{
struct V_18 * V_122 ;
int V_61 ;
V_122 = F_29 ( sizeof( struct V_18 ) , V_78 ) ;
if ( ! V_122 )
return NULL ;
F_30 ( & V_80 ) ;
V_61 = F_69 ( V_122 , V_121 ) ;
F_34 ( & V_80 ) ;
if ( ! V_61 ) {
return V_122 ;
} else {
F_33 ( V_122 ) ;
return NULL ;
}
}
static void * F_70 ( struct V_123 * V_124 , T_6 * V_121 )
{
if ( * V_121 == 0 ) {
++ * V_121 ;
F_71 ( V_124 , L_26 ) ;
}
return F_68 ( * V_121 ) ;
}
static void * F_72 ( struct V_123 * V_124 , void * V_125 , T_6 * V_121 )
{
++ * V_121 ;
return F_68 ( * V_121 ) ;
}
static void F_73 ( struct V_123 * V_124 , void * V_125 )
{
}
static int F_74 ( struct V_123 * V_124 , void * V_125 )
{
struct V_18 * V_122 = (struct V_18 * ) V_125 ;
F_75 ( V_124 , L_27 , F_32 ( V_122 -> type ) ,
V_122 -> V_48 , V_122 -> V_49 ) ;
F_33 ( V_122 ) ;
return 0 ;
}
static int F_76 ( struct V_126 * V_126 , struct V_90 * V_90 )
{
return F_77 ( V_90 , & V_127 ) ;
}
static int T_1 F_78 ( void )
{
if ( V_2 ) {
F_79 ( L_28 , V_128 ,
V_129 , NULL , & V_130 ) ;
}
return 0 ;
}
