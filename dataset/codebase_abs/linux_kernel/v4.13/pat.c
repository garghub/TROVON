void F_1 ( const char * V_1 )
{
if ( V_2 )
return;
if ( V_3 ) {
F_2 ( 1 , L_1 ) ;
return;
}
V_2 = true ;
F_3 ( L_2 , V_1 ) ;
}
static int T_1 F_4 ( char * V_4 )
{
F_1 ( L_3 ) ;
return 0 ;
}
bool F_5 ( void )
{
return V_5 ;
}
static int T_1 F_6 ( char * V_4 )
{
V_6 = 1 ;
return 0 ;
}
static inline enum V_7 F_7 ( struct V_8 * V_9 )
{
unsigned long V_10 = V_9 -> V_11 & V_12 ;
if ( V_10 == V_13 )
return V_14 ;
else if ( V_10 == V_15 )
return V_16 ;
else if ( V_10 == V_17 )
return V_18 ;
else
return V_19 ;
}
static inline void F_8 ( struct V_8 * V_9 ,
enum V_7 V_20 )
{
unsigned long V_21 ;
unsigned long V_22 ;
unsigned long V_23 ;
switch ( V_20 ) {
case V_16 :
V_21 = V_15 ;
break;
case V_18 :
V_21 = V_17 ;
break;
case V_19 :
V_21 = V_24 ;
break;
case V_14 :
default:
V_21 = V_13 ;
break;
}
do {
V_22 = V_9 -> V_11 ;
V_23 = ( V_22 & V_25 ) | V_21 ;
} while ( F_9 ( & V_9 -> V_11 , V_22 , V_23 ) != V_22 );
}
static inline enum V_7 F_7 ( struct V_8 * V_9 )
{
return - 1 ;
}
static inline void F_8 ( struct V_8 * V_9 ,
enum V_7 V_20 )
{
}
static enum V_7 F_10 ( unsigned V_26 , char * V_27 )
{
enum V_7 V_28 ;
char * V_29 ;
switch ( V_26 ) {
case V_30 : V_28 = F_11 ( V_31 ) ; V_29 = L_4 ; break;
case V_32 : V_28 = F_11 ( V_33 ) ; V_29 = L_5 ; break;
case V_34 : V_28 = F_11 ( V_35 ) ; V_29 = L_6 ; break;
case V_36 : V_28 = F_11 ( V_37 ) ; V_29 = L_7 ; break;
case V_38 : V_28 = F_11 ( V_39 ) ; V_29 = L_8 ; break;
case V_40 : V_28 = F_11 ( V_41 ) ; V_29 = L_9 ; break;
default: V_28 = F_11 ( V_39 ) ; V_29 = L_8 ; break;
}
memcpy ( V_27 , V_29 , 4 ) ;
return V_28 ;
}
static void F_12 ( T_2 V_42 )
{
enum V_7 V_28 ;
char V_43 [ 33 ] ;
int V_44 ;
V_43 [ 32 ] = 0 ;
for ( V_44 = 7 ; V_44 >= 0 ; V_44 -- ) {
V_28 = F_10 ( ( V_42 >> ( V_44 * 8 ) ) & 7 ,
V_43 + 4 * V_44 ) ;
F_13 ( V_44 , V_28 ) ;
}
F_3 ( L_10 , V_43 ) ;
V_45 = true ;
}
static void F_14 ( T_2 V_42 )
{
T_2 V_46 ;
if ( ! F_15 ( V_47 ) ) {
F_1 ( L_11 ) ;
return;
}
F_16 ( V_48 , V_46 ) ;
if ( ! V_46 ) {
F_1 ( L_12 ) ;
return;
}
F_17 ( V_48 , V_42 ) ;
V_5 = true ;
F_12 ( V_42 ) ;
}
static void F_18 ( T_2 V_42 )
{
if ( ! F_15 ( V_47 ) ) {
F_19 ( L_13 ) ;
}
F_17 ( V_48 , V_42 ) ;
}
void F_20 ( void )
{
T_2 V_42 = 0 ;
if ( V_45 )
return;
if ( F_15 ( V_47 ) ) {
F_16 ( V_48 , V_42 ) ;
}
if ( ! V_42 ) {
V_42 = F_21 ( 0 , V_39 ) | F_21 ( 1 , V_35 ) | F_21 ( 2 , V_41 ) | F_21 ( 3 , V_31 ) |
F_21 ( 4 , V_39 ) | F_21 ( 5 , V_35 ) | F_21 ( 6 , V_41 ) | F_21 ( 7 , V_31 ) ;
}
F_12 ( V_42 ) ;
}
void F_22 ( void )
{
T_2 V_42 ;
struct V_49 * V_50 = & V_51 ;
if ( V_2 )
return;
if ( ( V_50 -> V_52 == V_53 ) &&
( ( ( V_50 -> V_54 == 0x6 ) && ( V_50 -> V_55 <= 0xd ) ) ||
( ( V_50 -> V_54 == 0xf ) && ( V_50 -> V_55 <= 0x6 ) ) ) ) {
V_42 = F_21 ( 0 , V_39 ) | F_21 ( 1 , V_33 ) | F_21 ( 2 , V_41 ) | F_21 ( 3 , V_31 ) |
F_21 ( 4 , V_39 ) | F_21 ( 5 , V_33 ) | F_21 ( 6 , V_41 ) | F_21 ( 7 , V_31 ) ;
} else {
V_42 = F_21 ( 0 , V_39 ) | F_21 ( 1 , V_33 ) | F_21 ( 2 , V_41 ) | F_21 ( 3 , V_31 ) |
F_21 ( 4 , V_39 ) | F_21 ( 5 , V_33 ) | F_21 ( 6 , V_41 ) | F_21 ( 7 , V_35 ) ;
}
if ( ! V_3 ) {
F_14 ( V_42 ) ;
V_3 = true ;
} else {
F_18 ( V_42 ) ;
}
}
static unsigned long F_23 ( T_2 V_56 , T_2 V_57 ,
enum V_7 V_58 )
{
if ( V_58 == V_14 ) {
T_3 V_59 , V_60 ;
V_59 = F_24 ( V_56 , V_57 , & V_60 ) ;
if ( V_59 != V_61 )
return V_18 ;
return V_14 ;
}
return V_58 ;
}
static int
F_25 ( unsigned long V_62 , unsigned long V_63 , void * V_64 )
{
struct V_65 * V_66 = V_64 ;
V_66 -> V_67 |= V_62 > V_66 -> V_68 ;
V_66 -> V_69 |= V_63 > 0 ;
V_66 -> V_68 = V_62 + V_63 ;
return V_66 -> V_69 && V_66 -> V_67 ;
}
static int F_26 ( T_4 V_56 , T_4 V_57 )
{
int V_70 = 0 ;
unsigned long V_71 = V_56 >> V_72 ;
unsigned long V_73 = ( V_57 + V_74 - 1 ) >> V_72 ;
struct V_65 V_66 = { V_71 , 0 , 0 } ;
if ( V_71 < V_75 > > V_72 )
V_71 = V_75 >> V_72 ;
if ( V_71 < V_73 ) {
V_70 = F_27 ( V_71 , V_73 - V_71 ,
& V_66 , F_25 ) ;
}
return ( V_70 > 0 ) ? - 1 : ( V_66 . V_69 ? 1 : 0 ) ;
}
static int F_28 ( T_2 V_56 , T_2 V_57 ,
enum V_7 V_58 ,
enum V_7 * V_76 )
{
struct V_8 * V_8 ;
T_2 V_77 ;
if ( V_58 == V_78 ) {
if ( V_76 )
* V_76 = V_18 ;
return - V_79 ;
}
if ( V_58 == V_80 ) {
F_29 ( 1 ) ;
V_58 = V_18 ;
}
for ( V_77 = ( V_56 >> V_72 ) ; V_77 < ( V_57 >> V_72 ) ; ++ V_77 ) {
enum V_7 type ;
V_8 = F_30 ( V_77 ) ;
type = F_7 ( V_8 ) ;
if ( type != V_14 ) {
F_3 ( L_14 ,
V_56 , V_57 - 1 , type , V_58 ) ;
if ( V_76 )
* V_76 = type ;
return - V_81 ;
}
}
if ( V_76 )
* V_76 = V_58 ;
for ( V_77 = ( V_56 >> V_72 ) ; V_77 < ( V_57 >> V_72 ) ; ++ V_77 ) {
V_8 = F_30 ( V_77 ) ;
F_8 ( V_8 , V_58 ) ;
}
return 0 ;
}
static int F_31 ( T_2 V_56 , T_2 V_57 )
{
struct V_8 * V_8 ;
T_2 V_77 ;
for ( V_77 = ( V_56 >> V_72 ) ; V_77 < ( V_57 >> V_72 ) ; ++ V_77 ) {
V_8 = F_30 ( V_77 ) ;
F_8 ( V_8 , V_14 ) ;
}
return 0 ;
}
int F_32 ( T_2 V_56 , T_2 V_57 , enum V_7 V_58 ,
enum V_7 * V_76 )
{
struct V_20 * V_82 ;
enum V_7 V_83 ;
int V_84 ;
int V_85 = 0 ;
F_33 ( V_56 >= V_57 ) ;
if ( ! F_5 () ) {
if ( V_76 )
* V_76 = V_58 ;
return 0 ;
}
if ( V_86 . V_87 ( V_56 , V_57 ) ) {
if ( V_76 )
* V_76 = V_14 ;
return 0 ;
}
V_83 = F_23 ( V_56 , V_57 , V_58 ) ;
if ( V_76 )
* V_76 = V_83 ;
V_84 = F_26 ( V_56 , V_57 ) ;
if ( V_84 == 1 ) {
V_85 = F_28 ( V_56 , V_57 , V_58 , V_76 ) ;
return V_85 ;
} else if ( V_84 < 0 ) {
return - V_79 ;
}
V_82 = F_34 ( sizeof( struct V_20 ) , V_88 ) ;
if ( ! V_82 )
return - V_89 ;
V_82 -> V_56 = V_56 ;
V_82 -> V_57 = V_57 ;
V_82 -> type = V_83 ;
F_35 ( & V_90 ) ;
V_85 = F_36 ( V_82 , V_76 ) ;
if ( V_85 ) {
F_3 ( L_15 ,
V_56 , V_57 - 1 ,
F_37 ( V_82 -> type ) , F_37 ( V_58 ) ) ;
F_38 ( V_82 ) ;
F_39 ( & V_90 ) ;
return V_85 ;
}
F_39 ( & V_90 ) ;
F_40 ( L_16 ,
V_56 , V_57 - 1 , F_37 ( V_82 -> type ) , F_37 ( V_58 ) ,
V_76 ? F_37 ( * V_76 ) : L_17 ) ;
return V_85 ;
}
int F_41 ( T_2 V_56 , T_2 V_57 )
{
int V_85 = - V_79 ;
int V_84 ;
struct V_20 * V_91 ;
if ( ! F_5 () )
return 0 ;
if ( V_86 . V_87 ( V_56 , V_57 ) )
return 0 ;
V_84 = F_26 ( V_56 , V_57 ) ;
if ( V_84 == 1 ) {
V_85 = F_31 ( V_56 , V_57 ) ;
return V_85 ;
} else if ( V_84 < 0 ) {
return - V_79 ;
}
F_35 ( & V_90 ) ;
V_91 = F_42 ( V_56 , V_57 ) ;
F_39 ( & V_90 ) ;
if ( F_43 ( V_91 ) ) {
F_3 ( L_18 ,
V_92 -> V_93 , V_92 -> V_94 , V_56 , V_57 - 1 ) ;
return - V_79 ;
}
F_38 ( V_91 ) ;
F_40 ( L_19 , V_56 , V_57 - 1 ) ;
return 0 ;
}
static enum V_7 F_44 ( T_2 V_95 )
{
enum V_7 V_96 = V_14 ;
struct V_20 * V_91 ;
if ( V_86 . V_87 ( V_95 , V_95 + V_74 ) )
return V_96 ;
if ( F_26 ( V_95 , V_95 + V_74 ) ) {
struct V_8 * V_8 ;
V_8 = F_30 ( V_95 >> V_72 ) ;
return F_7 ( V_8 ) ;
}
F_35 ( & V_90 ) ;
V_91 = F_45 ( V_95 ) ;
if ( V_91 != NULL )
V_96 = V_91 -> type ;
else
V_96 = V_18 ;
F_39 ( & V_90 ) ;
return V_96 ;
}
int F_46 ( T_4 V_56 , T_4 V_57 ,
enum V_7 * type )
{
T_4 V_97 = V_57 - V_56 ;
enum V_7 V_58 = * type ;
enum V_7 V_76 ;
int V_70 ;
F_29 ( F_47 ( V_56 , V_97 ) ) ;
V_70 = F_32 ( V_56 , V_57 , V_58 , & V_76 ) ;
if ( V_70 )
goto V_98;
if ( ! F_48 ( V_56 , V_97 , V_58 , V_76 ) )
goto V_99;
if ( F_49 ( V_56 , V_97 , V_76 ) < 0 )
goto V_99;
* type = V_76 ;
return 0 ;
V_99:
F_41 ( V_56 , V_57 ) ;
V_70 = - V_81 ;
V_98:
return V_70 ;
}
void F_50 ( T_4 V_56 , T_4 V_57 )
{
F_41 ( V_56 , V_57 ) ;
}
int F_51 ( T_4 V_56 , T_4 V_97 )
{
enum V_7 type = V_16 ;
return F_46 ( V_56 , V_56 + V_97 , & type ) ;
}
void F_52 ( T_4 V_56 , T_4 V_97 )
{
F_50 ( V_56 , V_56 + V_97 ) ;
}
T_5 F_53 ( struct V_100 * V_100 , unsigned long V_77 ,
unsigned long V_97 , T_5 V_101 )
{
return V_101 ;
}
static inline int F_54 ( unsigned long V_77 , unsigned long V_97 )
{
return 1 ;
}
static inline int F_54 ( unsigned long V_77 , unsigned long V_97 )
{
T_2 V_102 = ( ( T_2 ) V_77 ) << V_72 ;
T_2 V_103 = V_102 + V_97 ;
T_2 V_104 = V_102 ;
if ( ! F_5 () )
return 1 ;
while ( V_104 < V_103 ) {
if ( ! F_55 ( V_77 ) )
return 0 ;
V_104 += V_74 ;
V_77 ++ ;
}
return 1 ;
}
int F_56 ( struct V_100 * V_100 , unsigned long V_77 ,
unsigned long V_97 , T_5 * V_101 )
{
enum V_7 V_105 = V_14 ;
if ( ! F_54 ( V_77 , V_97 ) )
return 0 ;
if ( V_100 -> V_106 & V_107 )
V_105 = V_18 ;
* V_101 = F_57 ( ( F_58 ( * V_101 ) & ~ V_108 ) |
F_59 ( V_105 ) ) ;
return 1 ;
}
int F_49 ( T_2 V_109 , unsigned long V_97 ,
enum V_7 V_105 )
{
unsigned long V_110 ;
if ( V_109 > F_60 ( V_111 - 1 ) )
return 0 ;
if ( ! F_61 ( V_109 >> V_72 ) )
return 0 ;
V_110 = ( F_60 ( V_111 - 1 ) <= V_109 + V_97 ) ?
F_60 ( V_111 ) - V_109 :
V_97 ;
if ( F_62 ( ( unsigned long ) F_63 ( V_109 ) , V_110 , V_105 ) < 0 ) {
F_3 ( L_20 ,
V_92 -> V_93 , V_92 -> V_94 ,
F_37 ( V_105 ) ,
V_109 , ( unsigned long long ) ( V_109 + V_97 - 1 ) ) ;
return - V_79 ;
}
return 0 ;
}
static int F_64 ( T_2 V_95 , unsigned long V_97 , T_5 * V_101 ,
int V_112 )
{
int V_113 = 0 ;
int V_70 ;
enum V_7 V_114 = F_65 ( * V_101 ) ;
enum V_7 V_105 = V_114 ;
V_113 = F_26 ( V_95 , V_95 + V_97 ) ;
if ( V_113 ) {
if ( ! F_5 () )
return 0 ;
V_105 = F_44 ( V_95 ) ;
if ( V_114 != V_105 ) {
F_66 ( L_21 ,
V_92 -> V_93 , V_92 -> V_94 ,
F_37 ( V_114 ) ,
( unsigned long long ) V_95 ,
( unsigned long long ) ( V_95 + V_97 - 1 ) ,
F_37 ( V_105 ) ) ;
* V_101 = F_57 ( ( F_58 ( * V_101 ) &
( ~ V_108 ) ) |
F_59 ( V_105 ) ) ;
}
return 0 ;
}
V_70 = F_32 ( V_95 , V_95 + V_97 , V_114 , & V_105 ) ;
if ( V_70 )
return V_70 ;
if ( V_105 != V_114 ) {
if ( V_112 ||
! F_48 ( V_95 , V_97 , V_114 , V_105 ) ) {
F_41 ( V_95 , V_95 + V_97 ) ;
F_67 ( L_22 ,
V_92 -> V_93 , V_92 -> V_94 ,
F_37 ( V_114 ) ,
( unsigned long long ) V_95 ,
( unsigned long long ) ( V_95 + V_97 - 1 ) ,
F_37 ( V_105 ) ) ;
return - V_79 ;
}
* V_101 = F_57 ( ( F_58 ( * V_101 ) &
( ~ V_108 ) ) |
F_59 ( V_105 ) ) ;
}
if ( F_49 ( V_95 , V_97 , V_105 ) < 0 ) {
F_41 ( V_95 , V_95 + V_97 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_68 ( T_2 V_95 , unsigned long V_97 )
{
int V_113 ;
V_113 = F_26 ( V_95 , V_95 + V_97 ) ;
if ( V_113 == 0 )
F_41 ( V_95 , V_95 + V_97 ) ;
}
int F_69 ( struct V_115 * V_116 )
{
T_4 V_95 ;
unsigned long V_117 ;
unsigned long V_118 = V_116 -> V_119 - V_116 -> V_120 ;
T_5 V_121 ;
if ( V_116 -> V_122 & V_123 ) {
if ( F_70 ( V_116 , V_116 -> V_120 , 0 , & V_117 , & V_95 ) ) {
F_29 ( 1 ) ;
return - V_79 ;
}
V_121 = F_57 ( V_117 ) ;
return F_64 ( V_95 , V_118 , & V_121 , 1 ) ;
}
return 0 ;
}
int F_71 ( struct V_115 * V_116 , T_5 * V_117 ,
unsigned long V_77 , unsigned long V_124 , unsigned long V_97 )
{
T_4 V_95 = ( T_4 ) V_77 << V_72 ;
enum V_7 V_105 ;
if ( ! V_116 || ( V_124 == V_116 -> V_120
&& V_97 == ( V_116 -> V_119 - V_116 -> V_120 ) ) ) {
int V_70 ;
V_70 = F_64 ( V_95 , V_97 , V_117 , 0 ) ;
if ( V_70 == 0 && V_116 )
V_116 -> V_122 |= V_123 ;
return V_70 ;
}
if ( ! F_5 () )
return 0 ;
V_105 = F_44 ( V_95 ) ;
while ( V_97 > V_74 ) {
V_97 -= V_74 ;
V_95 += V_74 ;
if ( V_105 != F_44 ( V_95 ) )
return - V_79 ;
}
* V_117 = F_57 ( ( F_58 ( * V_117 ) & ( ~ V_108 ) ) |
F_59 ( V_105 ) ) ;
return 0 ;
}
void F_72 ( struct V_115 * V_116 , T_5 * V_117 , T_6 V_77 )
{
enum V_7 V_105 ;
if ( ! F_5 () )
return;
V_105 = F_44 ( F_73 ( V_77 ) ) ;
* V_117 = F_57 ( ( F_58 ( * V_117 ) & ( ~ V_108 ) ) |
F_59 ( V_105 ) ) ;
}
void F_74 ( struct V_115 * V_116 , unsigned long V_77 ,
unsigned long V_97 )
{
T_4 V_95 ;
unsigned long V_117 ;
if ( V_116 && ! ( V_116 -> V_122 & V_123 ) )
return;
V_95 = ( T_4 ) V_77 << V_72 ;
if ( ! V_95 && ! V_97 ) {
if ( F_70 ( V_116 , V_116 -> V_120 , 0 , & V_117 , & V_95 ) ) {
F_29 ( 1 ) ;
return;
}
V_97 = V_116 -> V_119 - V_116 -> V_120 ;
}
F_68 ( V_95 , V_97 ) ;
if ( V_116 )
V_116 -> V_122 &= ~ V_123 ;
}
void F_75 ( struct V_115 * V_116 )
{
V_116 -> V_122 &= ~ V_123 ;
}
T_5 F_76 ( T_5 V_117 )
{
return F_57 ( F_58 ( V_117 ) |
F_59 ( V_16 ) ) ;
}
T_5 F_77 ( T_5 V_117 )
{
return F_57 ( F_58 ( V_117 ) |
F_59 ( V_19 ) ) ;
}
static struct V_20 * F_78 ( T_7 V_125 )
{
struct V_20 * V_126 ;
int V_70 ;
V_126 = F_34 ( sizeof( struct V_20 ) , V_88 ) ;
if ( ! V_126 )
return NULL ;
F_35 ( & V_90 ) ;
V_70 = F_79 ( V_126 , V_125 ) ;
F_39 ( & V_90 ) ;
if ( ! V_70 ) {
return V_126 ;
} else {
F_38 ( V_126 ) ;
return NULL ;
}
}
static void * F_80 ( struct V_127 * V_128 , T_7 * V_125 )
{
if ( * V_125 == 0 ) {
++ * V_125 ;
F_81 ( V_128 , L_23 ) ;
}
return F_78 ( * V_125 ) ;
}
static void * F_82 ( struct V_127 * V_128 , void * V_129 , T_7 * V_125 )
{
++ * V_125 ;
return F_78 ( * V_125 ) ;
}
static void F_83 ( struct V_127 * V_128 , void * V_129 )
{
}
static int F_84 ( struct V_127 * V_128 , void * V_129 )
{
struct V_20 * V_126 = (struct V_20 * ) V_129 ;
F_85 ( V_128 , L_24 , F_37 ( V_126 -> type ) ,
V_126 -> V_56 , V_126 -> V_57 ) ;
F_38 ( V_126 ) ;
return 0 ;
}
static int F_86 ( struct V_130 * V_130 , struct V_100 * V_100 )
{
return F_87 ( V_100 , & V_131 ) ;
}
static int T_1 F_88 ( void )
{
if ( F_5 () ) {
F_89 ( L_25 , V_132 ,
V_133 , NULL , & V_134 ) ;
}
return 0 ;
}
