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
if ( ! V_17 )
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
unsigned long V_55 = 0 , V_63 ;
unsigned long V_56 = V_7 ;
int V_57 = F_67 ( V_8 ) ;
for (; V_57 < V_64 ; V_57 ++ , V_8 = V_63 ) {
unsigned long V_65 ;
T_6 * V_26 = V_61 + F_67 ( V_8 ) ;
T_7 * V_27 ;
T_8 V_66 = V_33 ;
if ( V_8 >= V_7 ) {
if ( ! V_17 ) {
for (; V_57 < V_64 ; V_57 ++ , V_26 ++ )
F_47 ( V_26 , F_48 ( 0 ) ) ;
}
break;
}
V_63 = ( V_8 & V_34 ) + V_35 ;
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
if ( V_62 & ( 1 << V_67 ) ) {
if ( ! V_17 )
V_55 ++ ;
V_56 = V_63 ;
continue;
}
V_66 = F_71 ( F_72 ( * ( T_7 * ) V_26 ) ) ;
}
if ( V_62 & ( 1 << V_67 ) ) {
V_55 ++ ;
F_7 ( & V_24 . V_15 ) ;
F_35 ( ( T_7 * ) V_26 ,
F_64 ( V_8 >> V_43 ,
F_73 ( F_49 ( V_33 ) | V_68 ) ) ) ;
F_15 ( & V_24 . V_15 ) ;
V_56 = V_63 ;
continue;
}
V_27 = F_54 ( & V_65 ) ;
V_56 = F_60 ( V_27 , V_8 , V_7 , V_66 ) ;
F_58 ( V_27 ) ;
F_7 ( & V_24 . V_15 ) ;
F_31 ( & V_24 , V_26 , F_42 ( V_65 ) ) ;
F_15 ( & V_24 . V_15 ) ;
}
F_65 ( V_67 , V_55 ) ;
return V_56 ;
}
static unsigned long T_9
F_74 ( T_5 * V_28 , unsigned long V_54 , unsigned long V_7 ,
unsigned long V_62 )
{
unsigned long V_55 = 0 , V_63 ;
unsigned long V_56 = V_7 ;
int V_57 = F_34 ( V_54 ) ;
for (; V_57 < V_69 ; V_57 ++ , V_54 = V_63 ) {
unsigned long V_70 ;
T_5 * V_23 = V_28 + F_34 ( V_54 ) ;
T_6 * V_26 ;
T_8 V_33 = V_59 ;
if ( V_54 >= V_7 )
break;
V_63 = ( V_54 & V_71 ) + V_72 ;
if ( ! V_17 && ! F_75 ( V_54 , V_63 , 0 ) ) {
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
if ( V_62 & ( 1 << V_73 ) ) {
if ( ! V_17 )
V_55 ++ ;
V_56 = V_63 ;
continue;
}
V_33 = F_71 ( F_72 ( * ( T_7 * ) V_23 ) ) ;
}
if ( V_62 & ( 1 << V_73 ) ) {
V_55 ++ ;
F_7 ( & V_24 . V_15 ) ;
F_35 ( ( T_7 * ) V_23 ,
F_64 ( V_54 >> V_43 , V_38 ) ) ;
F_15 ( & V_24 . V_15 ) ;
V_56 = V_63 ;
continue;
}
V_26 = F_54 ( & V_70 ) ;
V_56 = F_66 ( V_26 , V_54 , V_7 , V_62 ,
V_33 ) ;
F_58 ( V_26 ) ;
F_7 ( & V_24 . V_15 ) ;
F_27 ( & V_24 , V_23 , F_42 ( V_70 ) ) ;
F_15 ( & V_24 . V_15 ) ;
}
F_78 () ;
F_65 ( V_73 , V_55 ) ;
return V_56 ;
}
unsigned long T_9
F_79 ( unsigned long V_6 ,
unsigned long V_7 ,
unsigned long V_62 )
{
bool V_74 = false ;
unsigned long V_63 , V_56 = V_7 ;
unsigned long V_54 ;
V_6 = ( unsigned long ) F_42 ( V_6 ) ;
V_7 = ( unsigned long ) F_42 ( V_7 ) ;
V_54 = V_6 ;
for (; V_6 < V_7 ; V_6 = V_63 ) {
T_2 * V_13 = F_5 ( V_6 ) ;
unsigned long V_75 ;
T_5 * V_23 ;
V_63 = ( V_6 + V_9 ) & V_76 ;
if ( V_63 > V_7 )
V_63 = V_7 ;
if ( F_80 ( * V_13 ) ) {
V_23 = F_57 ( ( T_5 * ) F_14 ( * V_13 ) ) ;
V_56 = F_74 ( V_23 , F_44 ( V_6 ) ,
F_44 ( V_7 ) , V_62 ) ;
F_58 ( V_23 ) ;
continue;
}
V_23 = F_54 ( & V_75 ) ;
V_56 = F_74 ( V_23 , F_44 ( V_6 ) , F_44 ( V_63 ) ,
V_62 ) ;
F_58 ( V_23 ) ;
F_7 ( & V_24 . V_15 ) ;
F_22 ( & V_24 , V_13 , F_42 ( V_75 ) ) ;
F_15 ( & V_24 . V_15 ) ;
V_74 = true ;
}
if ( V_74 )
F_4 ( V_54 , V_7 ) ;
F_78 () ;
return V_56 ;
}
void T_1 F_81 ( void )
{
F_82 ( 0 , ( V_77 ) V_78 , 0 ) ;
}
void T_1 F_83 ( void )
{
F_84 ( V_79 ) ;
F_85 () ;
F_86 ( 0 , V_80 ) ;
F_87 () ;
}
static void F_88 ( T_10 V_6 , T_10 V_32 )
{
unsigned long V_81 = F_89 ( V_6 + V_32 ) ;
if ( V_81 > V_82 ) {
V_82 = V_81 ;
V_83 = V_81 ;
V_84 = ( void * ) F_42 ( V_82 * V_20 - 1 ) + 1 ;
}
}
int F_90 ( int V_85 , T_10 V_6 , T_10 V_32 )
{
struct V_86 * V_87 = F_91 ( V_85 ) ;
struct V_88 * V_88 = V_87 -> V_89 + V_90 ;
unsigned long V_91 , V_92 = V_6 >> V_43 ;
unsigned long V_93 = V_32 >> V_43 ;
int V_94 ;
V_91 = F_92 ( V_6 , V_6 + V_32 ) ;
if ( V_91 > V_42 )
V_42 = V_91 ;
V_94 = F_93 ( V_85 , V_88 , V_92 , V_93 ) ;
F_94 ( V_94 ) ;
F_88 ( V_6 , V_32 ) ;
return V_94 ;
}
void T_1 F_95 ( void )
{
long V_95 , V_96 , V_97 , V_98 ;
unsigned long V_99 ;
F_96 () ;
V_96 = 0 ;
#ifdef F_97
V_100 = F_98 () ;
#else
V_100 = F_99 () ;
#endif
V_99 = F_100 ( 0 , V_82 ) ;
V_96 = V_82 - V_100 - V_99 ;
V_17 = 1 ;
V_95 = ( unsigned long ) & V_101 - ( unsigned long ) & V_46 ;
V_97 = ( unsigned long ) & V_102 - ( unsigned long ) & V_101 ;
V_98 = ( unsigned long ) & V_103 - ( unsigned long ) & V_104 ;
F_101 ( & V_105 , ( void * ) V_106 ,
V_107 - V_106 , V_108 ) ;
F_24 ( V_109 L_14
L_15 ,
F_102 () << ( V_43 - 10 ) ,
V_82 << ( V_43 - 10 ) ,
V_95 >> 10 ,
V_99 << ( V_43 - 10 ) ,
V_96 << ( V_43 - 10 ) ,
V_97 >> 10 ,
V_98 >> 10 ) ;
}
void F_103 ( void )
{
unsigned long V_6 = F_104 ( V_46 ) ;
unsigned long V_7 = F_104 ( V_110 ) ;
if ( ! V_111 )
return;
F_20 ( L_16 ,
V_6 , V_7 ) ;
F_105 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
}
void F_106 ( void )
{
unsigned long V_6 = F_104 ( V_46 ) ;
unsigned long V_7 = F_104 ( V_110 ) ;
if ( ! V_111 )
return;
F_20 ( L_17 ,
V_6 , V_7 ) ;
F_107 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
}
void F_108 ( void )
{
unsigned long V_6 = F_104 ( V_46 ) ;
unsigned long V_112 =
( ( unsigned long ) V_113 + V_20 - 1 ) & V_21 ;
unsigned long V_7 = ( unsigned long ) & V_114 ;
unsigned long V_115 = F_109 ( ( unsigned long ) & V_110 ) ;
unsigned long V_116 = F_109 ( ( unsigned long ) & V_117 ) ;
unsigned long V_118 = ( unsigned long ) & V_119 ;
F_24 ( V_109 L_18 ,
( V_7 - V_6 ) >> 10 ) ;
F_107 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
V_111 = 1 ;
F_110 ( V_112 , ( V_7 - V_112 ) >> V_43 ) ;
F_111 () ;
#ifdef F_112
F_24 ( V_109 L_19 , V_6 , V_7 ) ;
F_105 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
F_24 ( V_109 L_20 ) ;
F_107 ( V_6 , ( V_7 - V_6 ) >> V_43 ) ;
#endif
F_113 ( L_21 ,
( unsigned long ) F_9 ( F_114 ( V_115 ) ) ,
( unsigned long )
F_9 ( F_114 ( V_112 ) ) ) ;
F_113 ( L_21 ,
( unsigned long ) F_9 ( F_114 ( V_116 ) ) ,
( unsigned long ) F_9 ( F_114 ( V_118 ) ) ) ;
}
int F_115 ( unsigned long V_54 )
{
unsigned long V_120 = ( ( long ) V_54 ) >> V_121 ;
T_2 * V_13 ;
T_5 * V_23 ;
T_6 * V_26 ;
T_7 * V_27 ;
if ( V_120 != 0 && V_120 != - 1UL )
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
return F_116 ( F_117 ( * V_26 ) ) ;
V_27 = F_32 ( V_26 , V_54 ) ;
if ( F_118 ( * V_27 ) )
return 0 ;
return F_116 ( F_119 ( * V_27 ) ) ;
}
struct V_122 * F_120 ( struct V_123 * V_124 )
{
#ifdef F_121
if ( ! V_124 || V_124 -> V_125 . V_126 )
return NULL ;
#endif
return & V_127 ;
}
int F_122 ( struct V_123 * V_124 , unsigned long V_54 )
{
struct V_122 * V_128 = F_120 ( V_124 ) ;
if ( ! V_128 )
return 0 ;
return ( V_54 >= V_128 -> V_129 ) && ( V_54 < V_128 -> V_130 ) ;
}
int F_123 ( unsigned long V_54 )
{
return ( V_54 >= V_106 ) && ( V_54 < V_107 ) ;
}
const char * F_124 ( struct V_122 * V_128 )
{
if ( V_128 -> V_131 && V_128 -> V_129 == ( long ) V_128 -> V_131 -> V_125 . V_132 )
return L_22 ;
if ( V_128 == & V_127 )
return L_23 ;
return NULL ;
}
unsigned long F_125 ( void )
{
if ( F_126 () ) {
F_24 ( V_109 L_24 ) ;
return 2UL * 1024 * 1024 * 1024 ;
}
return V_133 ;
}
int T_9
F_127 ( struct V_11 * V_134 , unsigned long V_32 , int V_135 )
{
unsigned long V_54 = ( unsigned long ) V_134 ;
unsigned long V_7 = ( unsigned long ) ( V_134 + V_32 ) ;
unsigned long V_63 ;
T_2 * V_13 ;
T_5 * V_23 ;
T_6 * V_26 ;
for (; V_54 < V_7 ; V_54 = V_63 ) {
void * V_136 = NULL ;
V_13 = F_128 ( V_54 , V_135 ) ;
if ( ! V_13 )
return - V_137 ;
V_23 = F_129 ( V_13 , V_54 , V_135 ) ;
if ( ! V_23 )
return - V_137 ;
if ( ! V_138 ) {
V_63 = ( V_54 + V_20 ) & V_21 ;
V_26 = F_130 ( V_23 , V_54 , V_135 ) ;
if ( ! V_26 )
return - V_137 ;
V_136 = F_131 ( V_26 , V_54 , V_135 ) ;
if ( ! V_136 )
return - V_137 ;
V_139 = V_54 + V_20 ;
V_140 = V_136 + V_20 ;
} else {
V_63 = F_132 ( V_54 , V_7 ) ;
V_26 = F_28 ( V_23 , V_54 ) ;
if ( F_30 ( * V_26 ) ) {
T_7 V_141 ;
V_136 = F_133 ( V_35 , V_135 ) ;
if ( ! V_136 )
return - V_137 ;
V_141 = F_64 ( F_44 ( V_136 ) >> V_43 ,
V_38 ) ;
F_47 ( V_26 , F_48 ( F_63 ( V_141 ) ) ) ;
if ( V_140 != V_136 || V_142 != V_135 ) {
if ( V_143 )
F_24 ( V_144 L_25 ,
V_145 , V_139 - 1 , V_143 , V_140 - 1 , V_142 ) ;
V_145 = V_54 ;
V_142 = V_135 ;
V_143 = V_136 ;
}
V_139 = V_54 + V_35 ;
V_140 = V_136 + V_35 ;
} else
F_134 ( ( T_7 * ) V_26 , V_135 , V_54 , V_63 ) ;
}
}
F_4 ( ( unsigned long ) V_134 , V_7 ) ;
return 0 ;
}
void T_9 F_135 ( void )
{
if ( V_143 ) {
F_24 ( V_144 L_25 ,
V_145 , V_139 - 1 , V_143 , V_140 - 1 , V_142 ) ;
V_143 = NULL ;
V_140 = NULL ;
V_142 = 0 ;
}
}
