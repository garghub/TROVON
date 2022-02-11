static int T_1 F_1 ( char * V_1 )
{
V_2 = 0 ;
return 0 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static int T_1 F_3 ( char * V_3 )
{
if ( ! strcmp ( V_3 , L_1 ) )
V_4 &= ~ V_5 ;
else if ( ! strcmp ( V_3 , L_2 ) )
V_4 |= V_5 ;
return 1 ;
}
void F_4 ( unsigned long V_6 , unsigned long V_7 )
{
unsigned long V_8 ;
for ( V_8 = V_6 ; V_8 <= V_7 ; V_8 += V_9 ) {
const T_2 * V_10 = F_5 ( V_8 ) ;
struct V_11 * V_11 ;
if ( F_6 ( * V_10 ) )
continue;
F_7 ( & V_12 ) ;
F_8 (page, &pgd_list, lru) {
T_2 * V_13 ;
T_3 * V_14 ;
V_13 = ( T_2 * ) F_9 ( V_11 ) + F_10 ( V_8 ) ;
V_14 = & F_11 ( V_11 ) -> V_15 ;
F_7 ( V_14 ) ;
if ( F_6 ( * V_13 ) )
F_12 ( V_13 , * V_10 ) ;
else
F_13 ( F_14 ( * V_13 )
!= F_14 ( * V_10 ) ) ;
F_15 ( V_14 ) ;
}
F_15 ( & V_12 ) ;
}
}
static T_4 void * F_16 ( void )
{
void * V_16 ;
if ( V_17 )
V_16 = ( void * ) F_17 ( V_18 | V_19 ) ;
else
V_16 = F_18 ( V_20 ) ;
if ( ! V_16 || ( ( unsigned long ) V_16 & ~ V_21 ) ) {
F_19 ( L_3 ,
V_17 ? L_4 : L_5 ) ;
}
F_20 ( L_6 , V_16 ) ;
return V_16 ;
}
static T_5 * F_21 ( T_2 * V_13 , unsigned long V_22 )
{
if ( F_6 ( * V_13 ) ) {
T_5 * V_23 = ( T_5 * ) F_16 () ;
F_22 ( & V_24 , V_13 , V_23 ) ;
if ( V_23 != F_23 ( V_13 , 0 ) )
F_24 ( V_25 L_7 ,
V_23 , F_23 ( V_13 , 0 ) ) ;
}
return F_23 ( V_13 , V_22 ) ;
}
static T_6 * F_25 ( T_5 * V_23 , unsigned long V_22 )
{
if ( F_26 ( * V_23 ) ) {
T_6 * V_26 = ( T_6 * ) F_16 () ;
F_27 ( & V_24 , V_23 , V_26 ) ;
if ( V_26 != F_28 ( V_23 , 0 ) )
F_24 ( V_25 L_8 ,
V_26 , F_28 ( V_23 , 0 ) ) ;
}
return F_28 ( V_23 , V_22 ) ;
}
static T_7 * F_29 ( T_6 * V_26 , unsigned long V_22 )
{
if ( F_30 ( * V_26 ) ) {
T_7 * V_27 = ( T_7 * ) F_16 () ;
F_31 ( & V_24 , V_26 , V_27 ) ;
if ( V_27 != F_32 ( V_26 , 0 ) )
F_24 ( V_25 L_9 ) ;
}
return F_32 ( V_26 , V_22 ) ;
}
void F_33 ( T_5 * V_28 , unsigned long V_22 , T_7 V_29 )
{
T_5 * V_23 ;
T_6 * V_26 ;
T_7 * V_27 ;
V_23 = V_28 + F_34 ( V_22 ) ;
V_26 = F_25 ( V_23 , V_22 ) ;
V_27 = F_29 ( V_26 , V_22 ) ;
F_35 ( V_27 , V_29 ) ;
F_36 ( V_22 ) ;
}
void F_37 ( unsigned long V_22 , T_7 V_30 )
{
T_2 * V_13 ;
T_5 * V_28 ;
F_20 ( L_10 , V_22 , F_38 ( V_30 ) ) ;
V_13 = F_5 ( V_22 ) ;
if ( F_6 ( * V_13 ) ) {
F_24 ( V_25
L_11 ) ;
return;
}
V_28 = ( T_5 * ) F_14 ( * V_13 ) ;
F_33 ( V_28 , V_22 , V_30 ) ;
}
T_6 * T_1 F_39 ( unsigned long V_22 )
{
T_2 * V_13 ;
T_5 * V_23 ;
V_13 = F_5 ( V_22 ) ;
V_23 = F_21 ( V_13 , V_22 ) ;
return F_25 ( V_23 , V_22 ) ;
}
T_7 * T_1 F_40 ( unsigned long V_22 )
{
T_6 * V_26 ;
V_26 = F_39 ( V_22 ) ;
return F_29 ( V_26 , V_22 ) ;
}
static void T_1 F_41 ( unsigned long V_31 , unsigned long V_32 ,
T_8 V_33 )
{
T_2 * V_13 ;
T_5 * V_23 ;
T_6 * V_26 ;
F_13 ( ( V_31 & ~ V_34 ) || ( V_32 & ~ V_34 ) ) ;
for (; V_32 ; V_31 += V_35 , V_32 -= V_35 ) {
V_13 = F_5 ( ( unsigned long ) F_42 ( V_31 ) ) ;
if ( F_6 ( * V_13 ) ) {
V_23 = ( T_5 * ) F_16 () ;
F_12 ( V_13 , F_43 ( F_44 ( V_23 ) | V_36 |
V_37 ) ) ;
}
V_23 = F_23 ( V_13 , ( unsigned long ) F_42 ( V_31 ) ) ;
if ( F_26 ( * V_23 ) ) {
V_26 = ( T_6 * ) F_16 () ;
F_45 ( V_23 , F_46 ( F_44 ( V_26 ) | V_36 |
V_37 ) ) ;
}
V_26 = F_28 ( V_23 , V_31 ) ;
F_13 ( ! F_30 ( * V_26 ) ) ;
F_47 ( V_26 , F_48 ( V_31 | F_49 ( V_33 ) ) ) ;
}
}
void T_1 F_50 ( unsigned long V_31 , unsigned long V_32 )
{
F_41 ( V_31 , V_32 , V_38 ) ;
}
void T_1 F_51 ( unsigned long V_31 , unsigned long V_32 )
{
F_41 ( V_31 , V_32 , V_39 ) ;
}
void T_1 F_52 ( void )
{
unsigned long V_22 = V_40 ;
unsigned long V_41 = V_40 + ( V_42 << V_43 ) ;
unsigned long V_7 = F_53 ( ( unsigned long ) V_44 , V_35 ) - 1 ;
T_6 * V_26 = V_45 ;
for (; V_22 + V_35 - 1 < V_41 ; V_26 ++ , V_22 += V_35 ) {
if ( F_30 ( * V_26 ) )
continue;
if ( V_22 < ( unsigned long ) V_46 || V_22 > V_7 )
F_47 ( V_26 , F_48 ( 0 ) ) ;
}
}
static T_4 void * F_54 ( unsigned long * V_31 )
{
unsigned long V_47 = V_48 ++ ;
void * V_49 ;
if ( V_17 ) {
V_49 = ( void * ) F_17 ( V_18 | V_19 ) ;
* V_31 = F_44 ( V_49 ) ;
return V_49 ;
}
if ( V_47 >= V_50 )
F_19 ( L_12 ) ;
V_49 = F_55 ( V_47 * V_20 , V_20 ) ;
F_56 ( V_49 ) ;
* V_31 = V_47 * V_20 ;
return V_49 ;
}
static T_4 void * F_57 ( void * V_51 )
{
void * V_49 ;
unsigned long V_31 , V_52 ;
if ( V_17 )
return V_51 ;
V_31 = F_44 ( V_51 ) ;
V_52 = V_31 & ( V_20 - 1 ) ;
V_49 = F_55 ( V_31 & V_21 , V_20 ) ;
V_49 = ( void * ) ( ( ( unsigned long ) V_49 ) | V_52 ) ;
return V_49 ;
}
static T_4 void F_58 ( void * V_49 )
{
if ( V_17 )
return;
F_59 ( ( void * ) ( ( unsigned long ) V_49 & V_21 ) , V_20 ) ;
}
static unsigned long T_9
F_60 ( T_7 * V_53 , unsigned long V_54 , unsigned long V_7 ,
T_8 V_33 )
{
unsigned V_55 = 0 ;
unsigned long V_56 = V_7 ;
int V_57 ;
T_7 * V_27 = V_53 + F_61 ( V_54 ) ;
for( V_57 = F_61 ( V_54 ) ; V_57 < V_58 ; V_57 ++ , V_54 += V_20 , V_27 ++ ) {
if ( V_54 >= V_7 ) {
if ( ! V_17 ) {
for(; V_57 < V_58 ; V_57 ++ , V_27 ++ )
F_35 ( V_27 , F_62 ( 0 ) ) ;
}
break;
}
if ( F_63 ( * V_27 ) ) {
V_55 ++ ;
continue;
}
if ( 0 )
F_24 ( L_13 ,
V_27 , V_54 , F_64 ( V_54 >> V_43 , V_59 ) . V_27 ) ;
V_55 ++ ;
F_35 ( V_27 , F_64 ( V_54 >> V_43 , V_33 ) ) ;
V_56 = ( V_54 & V_21 ) + V_20 ;
}
F_65 ( V_60 , V_55 ) ;
return V_56 ;
}
static unsigned long T_9
F_66 ( T_6 * V_61 , unsigned long V_8 , unsigned long V_7 ,
unsigned long V_62 , T_8 V_33 )
{
unsigned long V_55 = 0 ;
unsigned long V_56 = V_7 ;
int V_57 = F_67 ( V_8 ) ;
for (; V_57 < V_63 ; V_57 ++ , V_8 += V_35 ) {
unsigned long V_64 ;
T_6 * V_26 = V_61 + F_67 ( V_8 ) ;
T_7 * V_27 ;
T_8 V_65 = V_33 ;
if ( V_8 >= V_7 ) {
if ( ! V_17 ) {
for (; V_57 < V_63 ; V_57 ++ , V_26 ++ )
F_47 ( V_26 , F_48 ( 0 ) ) ;
}
break;
}
if ( F_68 ( * V_26 ) ) {
if ( ! F_69 ( * V_26 ) ) {
F_7 ( & V_24 . V_15 ) ;
V_27 = F_57 ( ( T_7 * ) F_70 ( * V_26 ) ) ;
V_56 = F_60 ( V_27 , V_8 ,
V_7 , V_33 ) ;
F_58 ( V_27 ) ;
F_15 ( & V_24 . V_15 ) ;
continue;
}
if ( V_62 & ( 1 << V_66 ) ) {
V_55 ++ ;
continue;
}
V_65 = F_71 ( F_72 ( * ( T_7 * ) V_26 ) ) ;
}
if ( V_62 & ( 1 << V_66 ) ) {
V_55 ++ ;
F_7 ( & V_24 . V_15 ) ;
F_35 ( ( T_7 * ) V_26 ,
F_64 ( V_8 >> V_43 ,
F_73 ( F_49 ( V_33 ) | V_67 ) ) ) ;
F_15 ( & V_24 . V_15 ) ;
V_56 = ( V_8 & V_34 ) + V_35 ;
continue;
}
V_27 = F_54 ( & V_64 ) ;
V_56 = F_60 ( V_27 , V_8 , V_7 , V_65 ) ;
F_58 ( V_27 ) ;
F_7 ( & V_24 . V_15 ) ;
F_31 ( & V_24 , V_26 , F_42 ( V_64 ) ) ;
F_15 ( & V_24 . V_15 ) ;
}
F_65 ( V_66 , V_55 ) ;
return V_56 ;
}
static unsigned long T_9
F_74 ( T_5 * V_28 , unsigned long V_54 , unsigned long V_7 ,
unsigned long V_62 )
{
unsigned long V_55 = 0 ;
unsigned long V_56 = V_7 ;
int V_57 = F_34 ( V_54 ) ;
for (; V_57 < V_68 ; V_57 ++ , V_54 = ( V_54 & V_69 ) + V_70 ) {
unsigned long V_71 ;
T_5 * V_23 = V_28 + F_34 ( V_54 ) ;
T_6 * V_26 ;
T_8 V_33 = V_59 ;
if ( V_54 >= V_7 )
break;
if ( ! V_17 &&
! F_75 ( V_54 , V_54 + V_70 , 0 ) ) {
F_45 ( V_23 , F_46 ( 0 ) ) ;
continue;
}
if ( F_76 ( * V_23 ) ) {
if ( ! F_77 ( * V_23 ) ) {
V_26 = F_57 ( F_28 ( V_23 , 0 ) ) ;
V_56 = F_66 ( V_26 , V_54 , V_7 ,
V_62 , V_33 ) ;
F_58 ( V_26 ) ;
F_78 () ;
continue;
}
if ( V_62 & ( 1 << V_72 ) ) {
V_55 ++ ;
continue;
}
V_33 = F_71 ( F_72 ( * ( T_7 * ) V_23 ) ) ;
}
if ( V_62 & ( 1 << V_72 ) ) {
V_55 ++ ;
F_7 ( & V_24 . V_15 ) ;
F_35 ( ( T_7 * ) V_23 ,
F_64 ( V_54 >> V_43 , V_38 ) ) ;
F_15 ( & V_24 . V_15 ) ;
V_56 = ( V_54 & V_69 ) + V_70 ;
continue;
}
V_26 = F_54 ( & V_71 ) ;
V_56 = F_66 ( V_26 , V_54 , V_7 , V_62 ,
V_33 ) ;
F_58 ( V_26 ) ;
F_7 ( & V_24 . V_15 ) ;
F_27 ( & V_24 , V_23 , F_42 ( V_71 ) ) ;
F_15 ( & V_24 . V_15 ) ;
}
F_78 () ;
F_65 ( V_72 , V_55 ) ;
return V_56 ;
}
unsigned long T_9
F_79 ( unsigned long V_6 ,
unsigned long V_7 ,
unsigned long V_62 )
{
bool V_73 = false ;
unsigned long V_74 , V_56 = V_7 ;
unsigned long V_54 ;
V_6 = ( unsigned long ) F_42 ( V_6 ) ;
V_7 = ( unsigned long ) F_42 ( V_7 ) ;
V_54 = V_6 ;
for (; V_6 < V_7 ; V_6 = V_74 ) {
T_2 * V_13 = F_5 ( V_6 ) ;
unsigned long V_75 ;
T_5 * V_23 ;
V_74 = ( V_6 + V_9 ) & V_76 ;
if ( V_74 > V_7 )
V_74 = V_7 ;
if ( F_80 ( * V_13 ) ) {
V_23 = F_57 ( ( T_5 * ) F_14 ( * V_13 ) ) ;
V_56 = F_74 ( V_23 , F_44 ( V_6 ) ,
F_44 ( V_7 ) , V_62 ) ;
F_58 ( V_23 ) ;
continue;
}
V_23 = F_54 ( & V_75 ) ;
V_56 = F_74 ( V_23 , F_44 ( V_6 ) , F_44 ( V_74 ) ,
V_62 ) ;
F_58 ( V_23 ) ;
F_7 ( & V_24 . V_15 ) ;
F_22 ( & V_24 , V_13 , F_42 ( V_75 ) ) ;
F_15 ( & V_24 . V_15 ) ;
V_73 = true ;
}
if ( V_73 )
F_4 ( V_54 , V_7 ) ;
F_78 () ;
return V_56 ;
}
void T_1 F_81 ( void )
{
F_82 ( 0 , 0 , V_77 ) ;
}
void T_1 F_83 ( void )
{
unsigned long V_78 [ V_79 ] ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
#ifdef F_84
V_78 [ V_80 ] = V_81 ;
#endif
V_78 [ V_82 ] = V_83 ;
V_78 [ V_84 ] = V_77 ;
F_85 ( V_85 ) ;
F_86 () ;
F_87 ( 0 , V_86 ) ;
F_88 ( V_78 ) ;
}
static void F_89 ( T_10 V_6 , T_10 V_32 )
{
unsigned long V_87 = F_90 ( V_6 + V_32 ) ;
if ( V_87 > V_77 ) {
V_77 = V_87 ;
V_88 = V_87 ;
V_89 = ( void * ) F_42 ( V_77 * V_20 - 1 ) + 1 ;
}
}
int F_91 ( int V_90 , T_10 V_6 , T_10 V_32 )
{
struct V_91 * V_92 = F_92 ( V_90 ) ;
struct V_93 * V_93 = V_92 -> V_94 + V_84 ;
unsigned long V_95 , V_96 = V_6 >> V_43 ;
unsigned long V_97 = V_32 >> V_43 ;
int V_98 ;
V_95 = F_93 ( V_6 , V_6 + V_32 ) ;
if ( V_95 > V_42 )
V_42 = V_95 ;
V_98 = F_94 ( V_90 , V_93 , V_96 , V_97 ) ;
F_95 ( V_98 ) ;
F_89 ( V_6 , V_32 ) ;
return V_98 ;
}
void T_1 F_96 ( void )
{
long V_99 , V_100 , V_101 , V_102 ;
unsigned long V_103 ;
F_97 () ;
V_100 = 0 ;
#ifdef F_98
V_104 = F_99 () ;
#else
V_104 = F_100 () ;
#endif
V_103 = F_101 ( 0 , V_77 ) ;
V_100 = V_77 - V_104 - V_103 ;
V_17 = 1 ;
V_99 = ( unsigned long ) & V_105 - ( unsigned long ) & V_46 ;
V_101 = ( unsigned long ) & V_106 - ( unsigned long ) & V_105 ;
V_102 = ( unsigned long ) & V_107 - ( unsigned long ) & V_108 ;
F_102 ( & V_109 , ( void * ) V_110 ,
V_111 - V_110 , V_112 ) ;
F_24 ( V_113 L_14
L_15 ,
F_103 () << ( V_43 - 10 ) ,
V_77 << ( V_43 - 10 ) ,
V_99 >> 10 ,
V_103 << ( V_43 - 10 ) ,
V_100 << ( V_43 - 10 ) ,
V_101 >> 10 ,
V_102 >> 10 ) ;
}
void F_104 ( void )
{
unsigned long V_6 = F_105 ( V_46 ) ;
unsigned long V_7 = F_105 ( V_114 ) ;
if ( ! V_115 )
return;
F_20 ( L_16 ,
V_6 , V_7 ) ;
F_106 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
}
void F_107 ( void )
{
unsigned long V_6 = F_105 ( V_46 ) ;
unsigned long V_7 = F_105 ( V_114 ) ;
if ( ! V_115 )
return;
F_20 ( L_17 ,
V_6 , V_7 ) ;
F_108 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
}
void F_109 ( void )
{
unsigned long V_6 = F_105 ( V_46 ) ;
unsigned long V_116 =
( ( unsigned long ) V_117 + V_20 - 1 ) & V_21 ;
unsigned long V_7 = ( unsigned long ) & V_118 ;
unsigned long V_119 = F_110 ( ( unsigned long ) & V_114 ) ;
unsigned long V_120 = F_110 ( ( unsigned long ) & V_121 ) ;
unsigned long V_122 = ( unsigned long ) & V_123 ;
F_24 ( V_113 L_18 ,
( V_7 - V_6 ) >> 10 ) ;
F_108 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
V_115 = 1 ;
F_111 ( V_116 , ( V_7 - V_116 ) >> V_43 ) ;
F_112 () ;
#ifdef F_113
F_24 ( V_113 L_19 , V_6 , V_7 ) ;
F_106 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
F_24 ( V_113 L_20 ) ;
F_108 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
#endif
F_114 ( L_21 ,
( unsigned long ) F_9 ( F_115 ( V_119 ) ) ,
( unsigned long )
F_9 ( F_115 ( V_116 ) ) ) ;
F_114 ( L_21 ,
( unsigned long ) F_9 ( F_115 ( V_120 ) ) ,
( unsigned long ) F_9 ( F_115 ( V_122 ) ) ) ;
}
int F_116 ( unsigned long V_54 )
{
unsigned long V_124 = ( ( long ) V_54 ) >> V_125 ;
T_2 * V_13 ;
T_5 * V_23 ;
T_6 * V_26 ;
T_7 * V_27 ;
if ( V_124 != 0 && V_124 != - 1UL )
return 0 ;
V_13 = F_5 ( V_54 ) ;
if ( F_6 ( * V_13 ) )
return 0 ;
V_23 = F_23 ( V_13 , V_54 ) ;
if ( F_26 ( * V_23 ) )
return 0 ;
V_26 = F_28 ( V_23 , V_54 ) ;
if ( F_30 ( * V_26 ) )
return 0 ;
if ( F_69 ( * V_26 ) )
return F_117 ( F_118 ( * V_26 ) ) ;
V_27 = F_32 ( V_26 , V_54 ) ;
if ( F_119 ( * V_27 ) )
return 0 ;
return F_117 ( F_120 ( * V_27 ) ) ;
}
struct V_126 * F_121 ( struct V_127 * V_128 )
{
#ifdef F_122
if ( ! V_128 || V_128 -> V_129 . V_130 )
return NULL ;
#endif
return & V_131 ;
}
int F_123 ( struct V_127 * V_128 , unsigned long V_54 )
{
struct V_126 * V_132 = F_121 ( V_128 ) ;
if ( ! V_132 )
return 0 ;
return ( V_54 >= V_132 -> V_133 ) && ( V_54 < V_132 -> V_134 ) ;
}
int F_124 ( unsigned long V_54 )
{
return ( V_54 >= V_110 ) && ( V_54 < V_111 ) ;
}
const char * F_125 ( struct V_126 * V_132 )
{
if ( V_132 -> V_135 && V_132 -> V_133 == ( long ) V_132 -> V_135 -> V_129 . V_136 )
return L_22 ;
if ( V_132 == & V_131 )
return L_23 ;
return NULL ;
}
unsigned long F_126 ( void )
{
if ( F_127 () ) {
F_24 ( V_113 L_24 ) ;
return 2UL * 1024 * 1024 * 1024 ;
}
return V_137 ;
}
int T_9
F_128 ( struct V_11 * V_138 , unsigned long V_32 , int V_139 )
{
unsigned long V_54 = ( unsigned long ) V_138 ;
unsigned long V_7 = ( unsigned long ) ( V_138 + V_32 ) ;
unsigned long V_74 ;
T_2 * V_13 ;
T_5 * V_23 ;
T_6 * V_26 ;
for (; V_54 < V_7 ; V_54 = V_74 ) {
void * V_140 = NULL ;
V_13 = F_129 ( V_54 , V_139 ) ;
if ( ! V_13 )
return - V_141 ;
V_23 = F_130 ( V_13 , V_54 , V_139 ) ;
if ( ! V_23 )
return - V_141 ;
if ( ! V_142 ) {
V_74 = ( V_54 + V_20 ) & V_21 ;
V_26 = F_131 ( V_23 , V_54 , V_139 ) ;
if ( ! V_26 )
return - V_141 ;
V_140 = F_132 ( V_26 , V_54 , V_139 ) ;
if ( ! V_140 )
return - V_141 ;
V_143 = V_54 + V_20 ;
V_144 = V_140 + V_20 ;
} else {
V_74 = F_133 ( V_54 , V_7 ) ;
V_26 = F_28 ( V_23 , V_54 ) ;
if ( F_30 ( * V_26 ) ) {
T_7 V_145 ;
V_140 = F_134 ( V_35 , V_139 ) ;
if ( ! V_140 )
return - V_141 ;
V_145 = F_64 ( F_44 ( V_140 ) >> V_43 ,
V_38 ) ;
F_47 ( V_26 , F_48 ( F_63 ( V_145 ) ) ) ;
if ( V_144 != V_140 || V_146 != V_139 ) {
if ( V_147 )
F_24 ( V_148 L_25 ,
V_149 , V_143 - 1 , V_147 , V_144 - 1 , V_146 ) ;
V_149 = V_54 ;
V_146 = V_139 ;
V_147 = V_140 ;
}
V_143 = V_54 + V_35 ;
V_144 = V_140 + V_35 ;
} else
F_135 ( ( T_7 * ) V_26 , V_139 , V_54 , V_74 ) ;
}
}
F_4 ( ( unsigned long ) V_138 , V_7 ) ;
return 0 ;
}
void T_9 F_136 ( void )
{
if ( V_147 ) {
F_24 ( V_148 L_25 ,
V_149 , V_143 - 1 , V_147 , V_144 - 1 , V_146 ) ;
V_147 = NULL ;
V_144 = NULL ;
V_146 = 0 ;
}
}
