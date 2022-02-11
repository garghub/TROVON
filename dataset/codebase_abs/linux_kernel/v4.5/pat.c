static inline void F_1 ( const char * V_1 )
{
V_2 = 0 ;
F_2 ( L_1 , V_1 ) ;
}
static int T_1 F_3 ( char * V_3 )
{
F_1 ( L_2 ) ;
return 0 ;
}
bool F_4 ( void )
{
return ! ! V_2 ;
}
static int T_1 F_5 ( char * V_3 )
{
V_4 = 1 ;
return 0 ;
}
static inline enum V_5 F_6 ( struct V_6 * V_7 )
{
unsigned long V_8 = V_7 -> V_9 & V_10 ;
if ( V_8 == V_11 )
return V_12 ;
else if ( V_8 == V_13 )
return V_14 ;
else if ( V_8 == V_15 )
return V_16 ;
else
return V_17 ;
}
static inline void F_7 ( struct V_6 * V_7 ,
enum V_5 V_18 )
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
case V_12 :
default:
V_19 = V_11 ;
break;
}
do {
V_20 = V_7 -> V_9 ;
V_21 = ( V_20 & V_23 ) | V_19 ;
} while ( F_8 ( & V_7 -> V_9 , V_20 , V_21 ) != V_20 );
}
static inline enum V_5 F_6 ( struct V_6 * V_7 )
{
return - 1 ;
}
static inline void F_7 ( struct V_6 * V_7 ,
enum V_5 V_18 )
{
}
static enum V_5 F_9 ( unsigned V_24 , char * V_25 )
{
enum V_5 V_26 ;
char * V_27 ;
switch ( V_24 ) {
case V_28 : V_26 = F_10 ( V_29 ) ; V_27 = L_3 ; break;
case V_30 : V_26 = F_10 ( V_31 ) ; V_27 = L_4 ; break;
case V_32 : V_26 = F_10 ( V_33 ) ; V_27 = L_5 ; break;
case V_34 : V_26 = F_10 ( V_35 ) ; V_27 = L_6 ; break;
case V_36 : V_26 = F_10 ( V_37 ) ; V_27 = L_7 ; break;
case V_38 : V_26 = F_10 ( V_39 ) ; V_27 = L_8 ; break;
default: V_26 = F_10 ( V_37 ) ; V_27 = L_7 ; break;
}
memcpy ( V_25 , V_27 , 4 ) ;
return V_26 ;
}
void F_11 ( T_2 V_40 )
{
enum V_5 V_26 ;
char V_41 [ 33 ] ;
int V_42 ;
V_41 [ 32 ] = 0 ;
for ( V_42 = 7 ; V_42 >= 0 ; V_42 -- ) {
V_26 = F_9 ( ( V_40 >> ( V_42 * 8 ) ) & 7 ,
V_41 + 4 * V_42 ) ;
F_12 ( V_42 , V_26 ) ;
}
F_2 ( L_9 , V_41 ) ;
}
static void F_13 ( T_2 V_40 )
{
T_2 V_43 ;
if ( ! V_44 ) {
F_1 ( L_10 ) ;
return;
}
if ( ! F_4 () )
goto V_45;
F_14 ( V_46 , V_43 ) ;
if ( ! V_43 ) {
F_1 ( L_11 ) ;
return;
}
F_15 ( V_46 , V_40 ) ;
V_45:
F_11 ( V_40 ) ;
}
static void F_16 ( T_2 V_40 )
{
if ( ! F_4 () )
return;
if ( ! V_44 ) {
F_17 ( L_12 ) ;
}
F_15 ( V_46 , V_40 ) ;
}
void F_18 ( void )
{
T_2 V_40 ;
struct V_47 * V_48 = & V_49 ;
if ( ! F_4 () ) {
V_40 = F_19 ( 0 , V_37 ) | F_19 ( 1 , V_33 ) | F_19 ( 2 , V_39 ) | F_19 ( 3 , V_29 ) |
F_19 ( 4 , V_37 ) | F_19 ( 5 , V_33 ) | F_19 ( 6 , V_39 ) | F_19 ( 7 , V_29 ) ;
} else if ( ( V_48 -> V_50 == V_51 ) &&
( ( ( V_48 -> V_52 == 0x6 ) && ( V_48 -> V_53 <= 0xd ) ) ||
( ( V_48 -> V_52 == 0xf ) && ( V_48 -> V_53 <= 0x6 ) ) ) ) {
V_40 = F_19 ( 0 , V_37 ) | F_19 ( 1 , V_31 ) | F_19 ( 2 , V_39 ) | F_19 ( 3 , V_29 ) |
F_19 ( 4 , V_37 ) | F_19 ( 5 , V_31 ) | F_19 ( 6 , V_39 ) | F_19 ( 7 , V_29 ) ;
} else {
V_40 = F_19 ( 0 , V_37 ) | F_19 ( 1 , V_31 ) | F_19 ( 2 , V_39 ) | F_19 ( 3 , V_29 ) |
F_19 ( 4 , V_37 ) | F_19 ( 5 , V_31 ) | F_19 ( 6 , V_39 ) | F_19 ( 7 , V_33 ) ;
}
if ( ! V_54 ) {
F_13 ( V_40 ) ;
V_54 = true ;
} else {
F_16 ( V_40 ) ;
}
}
static unsigned long F_20 ( T_2 V_55 , T_2 V_56 ,
enum V_5 V_57 )
{
if ( V_57 == V_12 ) {
T_3 V_58 , V_59 ;
V_58 = F_21 ( V_55 , V_56 , & V_59 ) ;
if ( V_58 != V_60 )
return V_16 ;
return V_12 ;
}
return V_57 ;
}
static int
F_22 ( unsigned long V_61 , unsigned long V_62 , void * V_63 )
{
struct V_64 * V_65 = V_63 ;
V_65 -> V_66 |= V_61 > V_65 -> V_67 ;
V_65 -> V_68 |= V_62 > 0 ;
V_65 -> V_67 = V_61 + V_62 ;
return V_65 -> V_68 && V_65 -> V_66 ;
}
static int F_23 ( T_4 V_55 , T_4 V_56 )
{
int V_69 = 0 ;
unsigned long V_70 = V_55 >> V_71 ;
unsigned long V_72 = ( V_56 + V_73 - 1 ) >> V_71 ;
struct V_64 V_65 = { V_70 , 0 , 0 } ;
if ( V_70 < V_74 > > V_71 )
V_70 = V_74 >> V_71 ;
if ( V_70 < V_72 ) {
V_69 = F_24 ( V_70 , V_72 - V_70 ,
& V_65 , F_22 ) ;
}
return ( V_69 > 0 ) ? - 1 : ( V_65 . V_68 ? 1 : 0 ) ;
}
static int F_25 ( T_2 V_55 , T_2 V_56 ,
enum V_5 V_57 ,
enum V_5 * V_75 )
{
struct V_6 * V_6 ;
T_2 V_76 ;
if ( V_57 == V_77 ) {
if ( V_75 )
* V_75 = V_16 ;
return - V_78 ;
}
if ( V_57 == V_79 ) {
F_26 ( 1 ) ;
V_57 = V_16 ;
}
for ( V_76 = ( V_55 >> V_71 ) ; V_76 < ( V_56 >> V_71 ) ; ++ V_76 ) {
enum V_5 type ;
V_6 = F_27 ( V_76 ) ;
type = F_6 ( V_6 ) ;
if ( type != V_12 ) {
F_2 ( L_13 ,
V_55 , V_56 - 1 , type , V_57 ) ;
if ( V_75 )
* V_75 = type ;
return - V_80 ;
}
}
if ( V_75 )
* V_75 = V_57 ;
for ( V_76 = ( V_55 >> V_71 ) ; V_76 < ( V_56 >> V_71 ) ; ++ V_76 ) {
V_6 = F_27 ( V_76 ) ;
F_7 ( V_6 , V_57 ) ;
}
return 0 ;
}
static int F_28 ( T_2 V_55 , T_2 V_56 )
{
struct V_6 * V_6 ;
T_2 V_76 ;
for ( V_76 = ( V_55 >> V_71 ) ; V_76 < ( V_56 >> V_71 ) ; ++ V_76 ) {
V_6 = F_27 ( V_76 ) ;
F_7 ( V_6 , V_12 ) ;
}
return 0 ;
}
int F_29 ( T_2 V_55 , T_2 V_56 , enum V_5 V_57 ,
enum V_5 * V_75 )
{
struct V_18 * V_81 ;
enum V_5 V_82 ;
int V_83 ;
int V_84 = 0 ;
F_30 ( V_55 >= V_56 ) ;
if ( ! F_4 () ) {
if ( V_75 )
* V_75 = V_57 ;
return 0 ;
}
if ( V_85 . V_86 ( V_55 , V_56 ) ) {
if ( V_75 )
* V_75 = V_12 ;
return 0 ;
}
V_82 = F_20 ( V_55 , V_56 , V_57 ) ;
if ( V_75 )
* V_75 = V_82 ;
V_83 = F_23 ( V_55 , V_56 ) ;
if ( V_83 == 1 ) {
V_84 = F_25 ( V_55 , V_56 , V_57 , V_75 ) ;
return V_84 ;
} else if ( V_83 < 0 ) {
return - V_78 ;
}
V_81 = F_31 ( sizeof( struct V_18 ) , V_87 ) ;
if ( ! V_81 )
return - V_88 ;
V_81 -> V_55 = V_55 ;
V_81 -> V_56 = V_56 ;
V_81 -> type = V_82 ;
F_32 ( & V_89 ) ;
V_84 = F_33 ( V_81 , V_75 ) ;
if ( V_84 ) {
F_2 ( L_14 ,
V_55 , V_56 - 1 ,
F_34 ( V_81 -> type ) , F_34 ( V_57 ) ) ;
F_35 ( V_81 ) ;
F_36 ( & V_89 ) ;
return V_84 ;
}
F_36 ( & V_89 ) ;
F_37 ( L_15 ,
V_55 , V_56 - 1 , F_34 ( V_81 -> type ) , F_34 ( V_57 ) ,
V_75 ? F_34 ( * V_75 ) : L_16 ) ;
return V_84 ;
}
int F_38 ( T_2 V_55 , T_2 V_56 )
{
int V_84 = - V_78 ;
int V_83 ;
struct V_18 * V_90 ;
if ( ! F_4 () )
return 0 ;
if ( V_85 . V_86 ( V_55 , V_56 ) )
return 0 ;
V_83 = F_23 ( V_55 , V_56 ) ;
if ( V_83 == 1 ) {
V_84 = F_28 ( V_55 , V_56 ) ;
return V_84 ;
} else if ( V_83 < 0 ) {
return - V_78 ;
}
F_32 ( & V_89 ) ;
V_90 = F_39 ( V_55 , V_56 ) ;
F_36 ( & V_89 ) ;
if ( F_40 ( V_90 ) ) {
F_2 ( L_17 ,
V_91 -> V_92 , V_91 -> V_93 , V_55 , V_56 - 1 ) ;
return - V_78 ;
}
F_35 ( V_90 ) ;
F_37 ( L_18 , V_55 , V_56 - 1 ) ;
return 0 ;
}
static enum V_5 F_41 ( T_2 V_94 )
{
enum V_5 V_95 = V_12 ;
struct V_18 * V_90 ;
if ( V_85 . V_86 ( V_94 , V_94 + V_73 ) )
return V_95 ;
if ( F_23 ( V_94 , V_94 + V_73 ) ) {
struct V_6 * V_6 ;
V_6 = F_27 ( V_94 >> V_71 ) ;
return F_6 ( V_6 ) ;
}
F_32 ( & V_89 ) ;
V_90 = F_42 ( V_94 ) ;
if ( V_90 != NULL )
V_95 = V_90 -> type ;
else
V_95 = V_16 ;
F_36 ( & V_89 ) ;
return V_95 ;
}
int F_43 ( T_4 V_55 , T_4 V_56 ,
enum V_5 * type )
{
T_4 V_96 = V_56 - V_55 ;
enum V_5 V_57 = * type ;
enum V_5 V_75 ;
int V_69 ;
F_26 ( F_44 ( V_55 , V_96 ) ) ;
V_69 = F_29 ( V_55 , V_56 , V_57 , & V_75 ) ;
if ( V_69 )
goto V_97;
if ( ! F_45 ( V_55 , V_96 , V_57 , V_75 ) )
goto V_98;
if ( F_46 ( V_55 , V_96 , V_75 ) < 0 )
goto V_98;
* type = V_75 ;
return 0 ;
V_98:
F_38 ( V_55 , V_56 ) ;
V_69 = - V_80 ;
V_97:
return V_69 ;
}
void F_47 ( T_4 V_55 , T_4 V_56 )
{
F_38 ( V_55 , V_56 ) ;
}
T_5 F_48 ( struct V_99 * V_99 , unsigned long V_76 ,
unsigned long V_96 , T_5 V_100 )
{
return V_100 ;
}
static inline int F_49 ( unsigned long V_76 , unsigned long V_96 )
{
return 1 ;
}
static inline int F_49 ( unsigned long V_76 , unsigned long V_96 )
{
T_2 V_101 = ( ( T_2 ) V_76 ) << V_71 ;
T_2 V_102 = V_101 + V_96 ;
T_2 V_103 = V_101 ;
if ( ! F_4 () )
return 1 ;
while ( V_103 < V_102 ) {
if ( ! F_50 ( V_76 ) ) {
F_2 ( L_19 ,
V_91 -> V_92 , V_101 , V_102 - 1 ) ;
return 0 ;
}
V_103 += V_73 ;
V_76 ++ ;
}
return 1 ;
}
int F_51 ( struct V_99 * V_99 , unsigned long V_76 ,
unsigned long V_96 , T_5 * V_100 )
{
enum V_5 V_104 = V_12 ;
if ( ! F_49 ( V_76 , V_96 ) )
return 0 ;
if ( V_99 -> V_105 & V_106 )
V_104 = V_16 ;
#ifdef F_52
if ( ! F_4 () &&
! ( F_53 ( V_107 ) ||
F_53 ( V_108 ) ||
F_53 ( V_109 ) ||
F_53 ( V_110 ) ) &&
( V_76 << V_71 ) >= F_54 ( V_111 ) ) {
V_104 = V_79 ;
}
#endif
* V_100 = F_55 ( ( F_56 ( * V_100 ) & ~ V_112 ) |
F_57 ( V_104 ) ) ;
return 1 ;
}
int F_46 ( T_2 V_113 , unsigned long V_96 ,
enum V_5 V_104 )
{
unsigned long V_114 ;
if ( V_113 > F_54 ( V_111 - 1 ) )
return 0 ;
if ( ! F_58 ( V_113 >> V_71 ) )
return 0 ;
V_114 = ( F_54 ( V_111 - 1 ) <= V_113 + V_96 ) ?
F_54 ( V_111 ) - V_113 :
V_96 ;
if ( F_59 ( ( unsigned long ) F_60 ( V_113 ) , V_114 , V_104 ) < 0 ) {
F_2 ( L_20 ,
V_91 -> V_92 , V_91 -> V_93 ,
F_34 ( V_104 ) ,
V_113 , ( unsigned long long ) ( V_113 + V_96 - 1 ) ) ;
return - V_78 ;
}
return 0 ;
}
static int F_61 ( T_2 V_94 , unsigned long V_96 , T_5 * V_100 ,
int V_115 )
{
int V_116 = 0 ;
int V_69 ;
enum V_5 V_117 = F_62 ( * V_100 ) ;
enum V_5 V_104 = V_117 ;
V_116 = F_23 ( V_94 , V_94 + V_96 ) ;
if ( V_116 ) {
if ( ! F_4 () )
return 0 ;
V_104 = F_41 ( V_94 ) ;
if ( V_117 != V_104 ) {
F_63 ( L_21 ,
V_91 -> V_92 , V_91 -> V_93 ,
F_34 ( V_117 ) ,
( unsigned long long ) V_94 ,
( unsigned long long ) ( V_94 + V_96 - 1 ) ,
F_34 ( V_104 ) ) ;
* V_100 = F_55 ( ( F_56 ( * V_100 ) &
( ~ V_112 ) ) |
F_57 ( V_104 ) ) ;
}
return 0 ;
}
V_69 = F_29 ( V_94 , V_94 + V_96 , V_117 , & V_104 ) ;
if ( V_69 )
return V_69 ;
if ( V_104 != V_117 ) {
if ( V_115 ||
! F_45 ( V_94 , V_96 , V_117 , V_104 ) ) {
F_38 ( V_94 , V_94 + V_96 ) ;
F_64 ( L_22 ,
V_91 -> V_92 , V_91 -> V_93 ,
F_34 ( V_117 ) ,
( unsigned long long ) V_94 ,
( unsigned long long ) ( V_94 + V_96 - 1 ) ,
F_34 ( V_104 ) ) ;
return - V_78 ;
}
* V_100 = F_55 ( ( F_56 ( * V_100 ) &
( ~ V_112 ) ) |
F_57 ( V_104 ) ) ;
}
if ( F_46 ( V_94 , V_96 , V_104 ) < 0 ) {
F_38 ( V_94 , V_94 + V_96 ) ;
return - V_78 ;
}
return 0 ;
}
static void F_65 ( T_2 V_94 , unsigned long V_96 )
{
int V_116 ;
V_116 = F_23 ( V_94 , V_94 + V_96 ) ;
if ( V_116 == 0 )
F_38 ( V_94 , V_94 + V_96 ) ;
}
int F_66 ( struct V_118 * V_119 )
{
T_4 V_94 ;
unsigned long V_120 ;
unsigned long V_121 = V_119 -> V_122 - V_119 -> V_123 ;
T_5 V_124 ;
if ( V_119 -> V_125 & V_126 ) {
if ( F_67 ( V_119 , V_119 -> V_123 , 0 , & V_120 , & V_94 ) ) {
F_26 ( 1 ) ;
return - V_78 ;
}
V_124 = F_55 ( V_120 ) ;
return F_61 ( V_94 , V_121 , & V_124 , 1 ) ;
}
return 0 ;
}
int F_68 ( struct V_118 * V_119 , T_5 * V_120 ,
unsigned long V_76 , unsigned long V_127 , unsigned long V_96 )
{
T_4 V_94 = ( T_4 ) V_76 << V_71 ;
enum V_5 V_104 ;
if ( V_127 == V_119 -> V_123 && V_96 == ( V_119 -> V_122 - V_119 -> V_123 ) ) {
int V_69 ;
V_69 = F_61 ( V_94 , V_96 , V_120 , 0 ) ;
if ( ! V_69 )
V_119 -> V_125 |= V_126 ;
return V_69 ;
}
if ( ! F_4 () )
return 0 ;
V_104 = F_41 ( V_94 ) ;
while ( V_96 > V_73 ) {
V_96 -= V_73 ;
V_94 += V_73 ;
if ( V_104 != F_41 ( V_94 ) )
return - V_78 ;
}
* V_120 = F_55 ( ( F_56 ( V_119 -> V_128 ) & ( ~ V_112 ) ) |
F_57 ( V_104 ) ) ;
return 0 ;
}
int F_69 ( struct V_118 * V_119 , T_5 * V_120 ,
T_6 V_76 )
{
enum V_5 V_104 ;
if ( ! F_4 () )
return 0 ;
V_104 = F_41 ( F_70 ( V_76 ) ) ;
* V_120 = F_55 ( ( F_56 ( V_119 -> V_128 ) & ( ~ V_112 ) ) |
F_57 ( V_104 ) ) ;
return 0 ;
}
void F_71 ( struct V_118 * V_119 , unsigned long V_76 ,
unsigned long V_96 )
{
T_4 V_94 ;
unsigned long V_120 ;
if ( ! ( V_119 -> V_125 & V_126 ) )
return;
V_94 = ( T_4 ) V_76 << V_71 ;
if ( ! V_94 && ! V_96 ) {
if ( F_67 ( V_119 , V_119 -> V_123 , 0 , & V_120 , & V_94 ) ) {
F_26 ( 1 ) ;
return;
}
V_96 = V_119 -> V_122 - V_119 -> V_123 ;
}
F_65 ( V_94 , V_96 ) ;
V_119 -> V_125 &= ~ V_126 ;
}
void F_72 ( struct V_118 * V_119 )
{
V_119 -> V_125 &= ~ V_126 ;
}
T_5 F_73 ( T_5 V_120 )
{
return F_55 ( F_56 ( V_120 ) |
F_57 ( V_14 ) ) ;
}
T_5 F_74 ( T_5 V_120 )
{
return F_55 ( F_56 ( V_120 ) |
F_57 ( V_17 ) ) ;
}
static struct V_18 * F_75 ( T_7 V_129 )
{
struct V_18 * V_130 ;
int V_69 ;
V_130 = F_31 ( sizeof( struct V_18 ) , V_87 ) ;
if ( ! V_130 )
return NULL ;
F_32 ( & V_89 ) ;
V_69 = F_76 ( V_130 , V_129 ) ;
F_36 ( & V_89 ) ;
if ( ! V_69 ) {
return V_130 ;
} else {
F_35 ( V_130 ) ;
return NULL ;
}
}
static void * F_77 ( struct V_131 * V_132 , T_7 * V_129 )
{
if ( * V_129 == 0 ) {
++ * V_129 ;
F_78 ( V_132 , L_23 ) ;
}
return F_75 ( * V_129 ) ;
}
static void * F_79 ( struct V_131 * V_132 , void * V_133 , T_7 * V_129 )
{
++ * V_129 ;
return F_75 ( * V_129 ) ;
}
static void F_80 ( struct V_131 * V_132 , void * V_133 )
{
}
static int F_81 ( struct V_131 * V_132 , void * V_133 )
{
struct V_18 * V_130 = (struct V_18 * ) V_133 ;
F_82 ( V_132 , L_24 , F_34 ( V_130 -> type ) ,
V_130 -> V_55 , V_130 -> V_56 ) ;
F_35 ( V_130 ) ;
return 0 ;
}
static int F_83 ( struct V_134 * V_134 , struct V_99 * V_99 )
{
return F_84 ( V_99 , & V_135 ) ;
}
static int T_1 F_85 ( void )
{
if ( F_4 () ) {
F_86 ( L_25 , V_136 ,
V_137 , NULL , & V_138 ) ;
}
return 0 ;
}
