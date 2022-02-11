void F_1 ( const char * V_1 )
{
if ( ! V_2 )
return;
if ( V_3 ) {
F_2 ( 1 , L_1 ) ;
return;
}
V_2 = 0 ;
F_3 ( L_2 , V_1 ) ;
F_4 () ;
}
static int T_1 F_5 ( char * V_4 )
{
F_1 ( L_3 ) ;
return 0 ;
}
bool F_6 ( void )
{
return ! ! V_2 ;
}
static int T_1 F_7 ( char * V_4 )
{
V_5 = 1 ;
return 0 ;
}
static inline enum V_6 F_8 ( struct V_7 * V_8 )
{
unsigned long V_9 = V_8 -> V_10 & V_11 ;
if ( V_9 == V_12 )
return V_13 ;
else if ( V_9 == V_14 )
return V_15 ;
else if ( V_9 == V_16 )
return V_17 ;
else
return V_18 ;
}
static inline void F_9 ( struct V_7 * V_8 ,
enum V_6 V_19 )
{
unsigned long V_20 ;
unsigned long V_21 ;
unsigned long V_22 ;
switch ( V_19 ) {
case V_15 :
V_20 = V_14 ;
break;
case V_17 :
V_20 = V_16 ;
break;
case V_18 :
V_20 = V_23 ;
break;
case V_13 :
default:
V_20 = V_12 ;
break;
}
do {
V_21 = V_8 -> V_10 ;
V_22 = ( V_21 & V_24 ) | V_20 ;
} while ( F_10 ( & V_8 -> V_10 , V_21 , V_22 ) != V_21 );
}
static inline enum V_6 F_8 ( struct V_7 * V_8 )
{
return - 1 ;
}
static inline void F_9 ( struct V_7 * V_8 ,
enum V_6 V_19 )
{
}
static enum V_6 F_11 ( unsigned V_25 , char * V_26 )
{
enum V_6 V_27 ;
char * V_28 ;
switch ( V_25 ) {
case V_29 : V_27 = F_12 ( V_30 ) ; V_28 = L_4 ; break;
case V_31 : V_27 = F_12 ( V_32 ) ; V_28 = L_5 ; break;
case V_33 : V_27 = F_12 ( V_34 ) ; V_28 = L_6 ; break;
case V_35 : V_27 = F_12 ( V_36 ) ; V_28 = L_7 ; break;
case V_37 : V_27 = F_12 ( V_38 ) ; V_28 = L_8 ; break;
case V_39 : V_27 = F_12 ( V_40 ) ; V_28 = L_9 ; break;
default: V_27 = F_12 ( V_38 ) ; V_28 = L_8 ; break;
}
memcpy ( V_26 , V_28 , 4 ) ;
return V_27 ;
}
static void F_13 ( T_2 V_41 )
{
enum V_6 V_27 ;
char V_42 [ 33 ] ;
int V_43 ;
V_42 [ 32 ] = 0 ;
for ( V_43 = 7 ; V_43 >= 0 ; V_43 -- ) {
V_27 = F_11 ( ( V_41 >> ( V_43 * 8 ) ) & 7 ,
V_42 + 4 * V_43 ) ;
F_14 ( V_43 , V_27 ) ;
}
F_3 ( L_10 , V_42 ) ;
}
static void F_15 ( T_2 V_41 )
{
T_2 V_44 ;
if ( ! F_16 ( V_45 ) ) {
F_1 ( L_11 ) ;
return;
}
F_17 ( V_46 , V_44 ) ;
if ( ! V_44 ) {
F_1 ( L_12 ) ;
return;
}
F_18 ( V_46 , V_41 ) ;
F_13 ( V_41 ) ;
}
static void F_19 ( T_2 V_41 )
{
if ( ! F_16 ( V_45 ) ) {
F_20 ( L_13 ) ;
}
F_18 ( V_46 , V_41 ) ;
}
static void F_4 ( void )
{
T_2 V_41 = 0 ;
static int V_47 ;
if ( V_47 )
return;
if ( F_16 ( V_45 ) ) {
F_17 ( V_46 , V_41 ) ;
}
if ( ! V_41 ) {
V_41 = F_21 ( 0 , V_38 ) | F_21 ( 1 , V_34 ) | F_21 ( 2 , V_40 ) | F_21 ( 3 , V_30 ) |
F_21 ( 4 , V_38 ) | F_21 ( 5 , V_34 ) | F_21 ( 6 , V_40 ) | F_21 ( 7 , V_30 ) ;
}
F_13 ( V_41 ) ;
V_47 = 1 ;
}
void F_22 ( void )
{
T_2 V_41 ;
struct V_48 * V_49 = & V_50 ;
if ( ! F_6 () ) {
F_4 () ;
return;
}
if ( ( V_49 -> V_51 == V_52 ) &&
( ( ( V_49 -> V_53 == 0x6 ) && ( V_49 -> V_54 <= 0xd ) ) ||
( ( V_49 -> V_53 == 0xf ) && ( V_49 -> V_54 <= 0x6 ) ) ) ) {
V_41 = F_21 ( 0 , V_38 ) | F_21 ( 1 , V_32 ) | F_21 ( 2 , V_40 ) | F_21 ( 3 , V_30 ) |
F_21 ( 4 , V_38 ) | F_21 ( 5 , V_32 ) | F_21 ( 6 , V_40 ) | F_21 ( 7 , V_30 ) ;
} else {
V_41 = F_21 ( 0 , V_38 ) | F_21 ( 1 , V_32 ) | F_21 ( 2 , V_40 ) | F_21 ( 3 , V_30 ) |
F_21 ( 4 , V_38 ) | F_21 ( 5 , V_32 ) | F_21 ( 6 , V_40 ) | F_21 ( 7 , V_34 ) ;
}
if ( ! V_3 ) {
F_15 ( V_41 ) ;
V_3 = true ;
} else {
F_19 ( V_41 ) ;
}
}
static unsigned long F_23 ( T_2 V_55 , T_2 V_56 ,
enum V_6 V_57 )
{
if ( V_57 == V_13 ) {
T_3 V_58 , V_59 ;
V_58 = F_24 ( V_55 , V_56 , & V_59 ) ;
if ( V_58 != V_60 )
return V_17 ;
return V_13 ;
}
return V_57 ;
}
static int
F_25 ( unsigned long V_61 , unsigned long V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
V_65 -> V_66 |= V_61 > V_65 -> V_67 ;
V_65 -> V_68 |= V_62 > 0 ;
V_65 -> V_67 = V_61 + V_62 ;
return V_65 -> V_68 && V_65 -> V_66 ;
}
static int F_26 ( T_4 V_55 , T_4 V_56 )
{
int V_69 = 0 ;
unsigned long V_70 = V_55 >> V_71 ;
unsigned long V_72 = ( V_56 + V_73 - 1 ) >> V_71 ;
struct V_64 V_65 = { V_70 , 0 , 0 } ;
if ( V_70 < V_74 > > V_71 )
V_70 = V_74 >> V_71 ;
if ( V_70 < V_72 ) {
V_69 = F_27 ( V_70 , V_72 - V_70 ,
& V_65 , F_25 ) ;
}
return ( V_69 > 0 ) ? - 1 : ( V_65 . V_68 ? 1 : 0 ) ;
}
static int F_28 ( T_2 V_55 , T_2 V_56 ,
enum V_6 V_57 ,
enum V_6 * V_75 )
{
struct V_7 * V_7 ;
T_2 V_76 ;
if ( V_57 == V_77 ) {
if ( V_75 )
* V_75 = V_17 ;
return - V_78 ;
}
if ( V_57 == V_79 ) {
F_29 ( 1 ) ;
V_57 = V_17 ;
}
for ( V_76 = ( V_55 >> V_71 ) ; V_76 < ( V_56 >> V_71 ) ; ++ V_76 ) {
enum V_6 type ;
V_7 = F_30 ( V_76 ) ;
type = F_8 ( V_7 ) ;
if ( type != V_13 ) {
F_3 ( L_14 ,
V_55 , V_56 - 1 , type , V_57 ) ;
if ( V_75 )
* V_75 = type ;
return - V_80 ;
}
}
if ( V_75 )
* V_75 = V_57 ;
for ( V_76 = ( V_55 >> V_71 ) ; V_76 < ( V_56 >> V_71 ) ; ++ V_76 ) {
V_7 = F_30 ( V_76 ) ;
F_9 ( V_7 , V_57 ) ;
}
return 0 ;
}
static int F_31 ( T_2 V_55 , T_2 V_56 )
{
struct V_7 * V_7 ;
T_2 V_76 ;
for ( V_76 = ( V_55 >> V_71 ) ; V_76 < ( V_56 >> V_71 ) ; ++ V_76 ) {
V_7 = F_30 ( V_76 ) ;
F_9 ( V_7 , V_13 ) ;
}
return 0 ;
}
int F_32 ( T_2 V_55 , T_2 V_56 , enum V_6 V_57 ,
enum V_6 * V_75 )
{
struct V_19 * V_81 ;
enum V_6 V_82 ;
int V_83 ;
int V_84 = 0 ;
F_33 ( V_55 >= V_56 ) ;
if ( ! F_6 () ) {
if ( V_75 )
* V_75 = V_57 ;
return 0 ;
}
if ( V_85 . V_86 ( V_55 , V_56 ) ) {
if ( V_75 )
* V_75 = V_13 ;
return 0 ;
}
V_82 = F_23 ( V_55 , V_56 , V_57 ) ;
if ( V_75 )
* V_75 = V_82 ;
V_83 = F_26 ( V_55 , V_56 ) ;
if ( V_83 == 1 ) {
V_84 = F_28 ( V_55 , V_56 , V_57 , V_75 ) ;
return V_84 ;
} else if ( V_83 < 0 ) {
return - V_78 ;
}
V_81 = F_34 ( sizeof( struct V_19 ) , V_87 ) ;
if ( ! V_81 )
return - V_88 ;
V_81 -> V_55 = V_55 ;
V_81 -> V_56 = V_56 ;
V_81 -> type = V_82 ;
F_35 ( & V_89 ) ;
V_84 = F_36 ( V_81 , V_75 ) ;
if ( V_84 ) {
F_3 ( L_15 ,
V_55 , V_56 - 1 ,
F_37 ( V_81 -> type ) , F_37 ( V_57 ) ) ;
F_38 ( V_81 ) ;
F_39 ( & V_89 ) ;
return V_84 ;
}
F_39 ( & V_89 ) ;
F_40 ( L_16 ,
V_55 , V_56 - 1 , F_37 ( V_81 -> type ) , F_37 ( V_57 ) ,
V_75 ? F_37 ( * V_75 ) : L_17 ) ;
return V_84 ;
}
int F_41 ( T_2 V_55 , T_2 V_56 )
{
int V_84 = - V_78 ;
int V_83 ;
struct V_19 * V_90 ;
if ( ! F_6 () )
return 0 ;
if ( V_85 . V_86 ( V_55 , V_56 ) )
return 0 ;
V_83 = F_26 ( V_55 , V_56 ) ;
if ( V_83 == 1 ) {
V_84 = F_31 ( V_55 , V_56 ) ;
return V_84 ;
} else if ( V_83 < 0 ) {
return - V_78 ;
}
F_35 ( & V_89 ) ;
V_90 = F_42 ( V_55 , V_56 ) ;
F_39 ( & V_89 ) ;
if ( F_43 ( V_90 ) ) {
F_3 ( L_18 ,
V_91 -> V_92 , V_91 -> V_93 , V_55 , V_56 - 1 ) ;
return - V_78 ;
}
F_38 ( V_90 ) ;
F_40 ( L_19 , V_55 , V_56 - 1 ) ;
return 0 ;
}
static enum V_6 F_44 ( T_2 V_94 )
{
enum V_6 V_95 = V_13 ;
struct V_19 * V_90 ;
if ( V_85 . V_86 ( V_94 , V_94 + V_73 ) )
return V_95 ;
if ( F_26 ( V_94 , V_94 + V_73 ) ) {
struct V_7 * V_7 ;
V_7 = F_30 ( V_94 >> V_71 ) ;
return F_8 ( V_7 ) ;
}
F_35 ( & V_89 ) ;
V_90 = F_45 ( V_94 ) ;
if ( V_90 != NULL )
V_95 = V_90 -> type ;
else
V_95 = V_17 ;
F_39 ( & V_89 ) ;
return V_95 ;
}
int F_46 ( T_4 V_55 , T_4 V_56 ,
enum V_6 * type )
{
T_4 V_96 = V_56 - V_55 ;
enum V_6 V_57 = * type ;
enum V_6 V_75 ;
int V_69 ;
F_29 ( F_47 ( V_55 , V_96 ) ) ;
V_69 = F_32 ( V_55 , V_56 , V_57 , & V_75 ) ;
if ( V_69 )
goto V_97;
if ( ! F_48 ( V_55 , V_96 , V_57 , V_75 ) )
goto V_98;
if ( F_49 ( V_55 , V_96 , V_75 ) < 0 )
goto V_98;
* type = V_75 ;
return 0 ;
V_98:
F_41 ( V_55 , V_56 ) ;
V_69 = - V_80 ;
V_97:
return V_69 ;
}
void F_50 ( T_4 V_55 , T_4 V_56 )
{
F_41 ( V_55 , V_56 ) ;
}
int F_51 ( T_4 V_55 , T_4 V_96 )
{
enum V_6 type = V_15 ;
return F_46 ( V_55 , V_55 + V_96 , & type ) ;
}
void F_52 ( T_4 V_55 , T_4 V_96 )
{
F_50 ( V_55 , V_55 + V_96 ) ;
}
T_5 F_53 ( struct V_99 * V_99 , unsigned long V_76 ,
unsigned long V_96 , T_5 V_100 )
{
return V_100 ;
}
static inline int F_54 ( unsigned long V_76 , unsigned long V_96 )
{
return 1 ;
}
static inline int F_54 ( unsigned long V_76 , unsigned long V_96 )
{
T_2 V_101 = ( ( T_2 ) V_76 ) << V_71 ;
T_2 V_102 = V_101 + V_96 ;
T_2 V_103 = V_101 ;
if ( ! F_6 () )
return 1 ;
while ( V_103 < V_102 ) {
if ( ! F_55 ( V_76 ) )
return 0 ;
V_103 += V_73 ;
V_76 ++ ;
}
return 1 ;
}
int F_56 ( struct V_99 * V_99 , unsigned long V_76 ,
unsigned long V_96 , T_5 * V_100 )
{
enum V_6 V_104 = V_13 ;
if ( ! F_54 ( V_76 , V_96 ) )
return 0 ;
if ( V_99 -> V_105 & V_106 )
V_104 = V_17 ;
* V_100 = F_57 ( ( F_58 ( * V_100 ) & ~ V_107 ) |
F_59 ( V_104 ) ) ;
return 1 ;
}
int F_49 ( T_2 V_108 , unsigned long V_96 ,
enum V_6 V_104 )
{
unsigned long V_109 ;
if ( V_108 > F_60 ( V_110 - 1 ) )
return 0 ;
if ( ! F_61 ( V_108 >> V_71 ) )
return 0 ;
V_109 = ( F_60 ( V_110 - 1 ) <= V_108 + V_96 ) ?
F_60 ( V_110 ) - V_108 :
V_96 ;
if ( F_62 ( ( unsigned long ) F_63 ( V_108 ) , V_109 , V_104 ) < 0 ) {
F_3 ( L_20 ,
V_91 -> V_92 , V_91 -> V_93 ,
F_37 ( V_104 ) ,
V_108 , ( unsigned long long ) ( V_108 + V_96 - 1 ) ) ;
return - V_78 ;
}
return 0 ;
}
static int F_64 ( T_2 V_94 , unsigned long V_96 , T_5 * V_100 ,
int V_111 )
{
int V_112 = 0 ;
int V_69 ;
enum V_6 V_113 = F_65 ( * V_100 ) ;
enum V_6 V_104 = V_113 ;
V_112 = F_26 ( V_94 , V_94 + V_96 ) ;
if ( V_112 ) {
if ( ! F_6 () )
return 0 ;
V_104 = F_44 ( V_94 ) ;
if ( V_113 != V_104 ) {
F_66 ( L_21 ,
V_91 -> V_92 , V_91 -> V_93 ,
F_37 ( V_113 ) ,
( unsigned long long ) V_94 ,
( unsigned long long ) ( V_94 + V_96 - 1 ) ,
F_37 ( V_104 ) ) ;
* V_100 = F_57 ( ( F_58 ( * V_100 ) &
( ~ V_107 ) ) |
F_59 ( V_104 ) ) ;
}
return 0 ;
}
V_69 = F_32 ( V_94 , V_94 + V_96 , V_113 , & V_104 ) ;
if ( V_69 )
return V_69 ;
if ( V_104 != V_113 ) {
if ( V_111 ||
! F_48 ( V_94 , V_96 , V_113 , V_104 ) ) {
F_41 ( V_94 , V_94 + V_96 ) ;
F_67 ( L_22 ,
V_91 -> V_92 , V_91 -> V_93 ,
F_37 ( V_113 ) ,
( unsigned long long ) V_94 ,
( unsigned long long ) ( V_94 + V_96 - 1 ) ,
F_37 ( V_104 ) ) ;
return - V_78 ;
}
* V_100 = F_57 ( ( F_58 ( * V_100 ) &
( ~ V_107 ) ) |
F_59 ( V_104 ) ) ;
}
if ( F_49 ( V_94 , V_96 , V_104 ) < 0 ) {
F_41 ( V_94 , V_94 + V_96 ) ;
return - V_78 ;
}
return 0 ;
}
static void F_68 ( T_2 V_94 , unsigned long V_96 )
{
int V_112 ;
V_112 = F_26 ( V_94 , V_94 + V_96 ) ;
if ( V_112 == 0 )
F_41 ( V_94 , V_94 + V_96 ) ;
}
int F_69 ( struct V_114 * V_115 )
{
T_4 V_94 ;
unsigned long V_116 ;
unsigned long V_117 = V_115 -> V_118 - V_115 -> V_119 ;
T_5 V_120 ;
if ( V_115 -> V_121 & V_122 ) {
if ( F_70 ( V_115 , V_115 -> V_119 , 0 , & V_116 , & V_94 ) ) {
F_29 ( 1 ) ;
return - V_78 ;
}
V_120 = F_57 ( V_116 ) ;
return F_64 ( V_94 , V_117 , & V_120 , 1 ) ;
}
return 0 ;
}
int F_71 ( struct V_114 * V_115 , T_5 * V_116 ,
unsigned long V_76 , unsigned long V_123 , unsigned long V_96 )
{
T_4 V_94 = ( T_4 ) V_76 << V_71 ;
enum V_6 V_104 ;
if ( ! V_115 || ( V_123 == V_115 -> V_119
&& V_96 == ( V_115 -> V_118 - V_115 -> V_119 ) ) ) {
int V_69 ;
V_69 = F_64 ( V_94 , V_96 , V_116 , 0 ) ;
if ( V_69 == 0 && V_115 )
V_115 -> V_121 |= V_122 ;
return V_69 ;
}
if ( ! F_6 () )
return 0 ;
V_104 = F_44 ( V_94 ) ;
while ( V_96 > V_73 ) {
V_96 -= V_73 ;
V_94 += V_73 ;
if ( V_104 != F_44 ( V_94 ) )
return - V_78 ;
}
* V_116 = F_57 ( ( F_58 ( * V_116 ) & ( ~ V_107 ) ) |
F_59 ( V_104 ) ) ;
return 0 ;
}
void F_72 ( struct V_114 * V_115 , T_5 * V_116 , T_6 V_76 )
{
enum V_6 V_104 ;
if ( ! F_6 () )
return;
V_104 = F_44 ( F_73 ( V_76 ) ) ;
* V_116 = F_57 ( ( F_58 ( * V_116 ) & ( ~ V_107 ) ) |
F_59 ( V_104 ) ) ;
}
void F_74 ( struct V_114 * V_115 , unsigned long V_76 ,
unsigned long V_96 )
{
T_4 V_94 ;
unsigned long V_116 ;
if ( V_115 && ! ( V_115 -> V_121 & V_122 ) )
return;
V_94 = ( T_4 ) V_76 << V_71 ;
if ( ! V_94 && ! V_96 ) {
if ( F_70 ( V_115 , V_115 -> V_119 , 0 , & V_116 , & V_94 ) ) {
F_29 ( 1 ) ;
return;
}
V_96 = V_115 -> V_118 - V_115 -> V_119 ;
}
F_68 ( V_94 , V_96 ) ;
if ( V_115 )
V_115 -> V_121 &= ~ V_122 ;
}
void F_75 ( struct V_114 * V_115 )
{
V_115 -> V_121 &= ~ V_122 ;
}
T_5 F_76 ( T_5 V_116 )
{
return F_57 ( F_58 ( V_116 ) |
F_59 ( V_15 ) ) ;
}
T_5 F_77 ( T_5 V_116 )
{
return F_57 ( F_58 ( V_116 ) |
F_59 ( V_18 ) ) ;
}
static struct V_19 * F_78 ( T_7 V_124 )
{
struct V_19 * V_125 ;
int V_69 ;
V_125 = F_34 ( sizeof( struct V_19 ) , V_87 ) ;
if ( ! V_125 )
return NULL ;
F_35 ( & V_89 ) ;
V_69 = F_79 ( V_125 , V_124 ) ;
F_39 ( & V_89 ) ;
if ( ! V_69 ) {
return V_125 ;
} else {
F_38 ( V_125 ) ;
return NULL ;
}
}
static void * F_80 ( struct V_126 * V_127 , T_7 * V_124 )
{
if ( * V_124 == 0 ) {
++ * V_124 ;
F_81 ( V_127 , L_23 ) ;
}
return F_78 ( * V_124 ) ;
}
static void * F_82 ( struct V_126 * V_127 , void * V_128 , T_7 * V_124 )
{
++ * V_124 ;
return F_78 ( * V_124 ) ;
}
static void F_83 ( struct V_126 * V_127 , void * V_128 )
{
}
static int F_84 ( struct V_126 * V_127 , void * V_128 )
{
struct V_19 * V_125 = (struct V_19 * ) V_128 ;
F_85 ( V_127 , L_24 , F_37 ( V_125 -> type ) ,
V_125 -> V_55 , V_125 -> V_56 ) ;
F_38 ( V_125 ) ;
return 0 ;
}
static int F_86 ( struct V_129 * V_129 , struct V_99 * V_99 )
{
return F_87 ( V_99 , & V_130 ) ;
}
static int T_1 F_88 ( void )
{
if ( F_6 () ) {
F_89 ( L_25 , V_131 ,
V_132 , NULL , & V_133 ) ;
}
return 0 ;
}
