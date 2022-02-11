static bool F_1 ( T_1 V_1 )
{
T_1 V_2 ;
V_2 = V_3 + V_1 ;
if ( V_2 < V_3 )
return false ;
if ( V_2 >> V_4 > V_5 / V_6 )
return false ;
#ifdef F_2
if ( V_2 > ( V_7 - V_8 ) / V_9 )
return false ;
#endif
return true ;
}
static bool F_3 ( T_1 V_1 )
{
bool V_10 ;
F_4 ( & V_11 ) ;
V_10 = F_1 ( V_1 ) ;
F_5 ( & V_11 ) ;
return V_10 ;
}
static bool F_6 ( T_1 V_1 )
{
F_4 ( & V_11 ) ;
if ( ! F_1 ( V_1 ) ) {
F_5 ( & V_11 ) ;
return false ;
}
V_3 += V_1 ;
F_5 ( & V_11 ) ;
return true ;
}
static void F_7 ( T_1 V_1 )
{
unsigned long V_12 ;
F_8 ( & V_11 , V_12 ) ;
if ( F_9 ( V_3 < V_1 ) ) {
F_10 ( & V_11 , V_12 ) ;
F_11 ( L_1 ) ;
return;
}
V_3 -= V_1 ;
F_10 ( & V_11 , V_12 ) ;
}
static void * F_12 ( T_1 V_1 , int V_13 )
{
void * V_14 ;
if ( ! F_6 ( V_1 ) )
return NULL ;
if ( V_1 <= V_15 ) {
V_14 = F_13 ( V_1 , V_16 | V_17 | V_18 | V_19 , V_13 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_14 ( V_1 , V_13 ) ;
if ( V_14 )
return V_14 ;
F_7 ( V_1 ) ;
return NULL ;
}
static void F_15 ( void * V_20 , T_1 V_1 )
{
if ( ! V_20 )
return;
F_7 ( V_1 ) ;
if ( F_16 ( V_20 ) )
F_17 ( V_20 ) ;
else
F_18 ( V_20 ) ;
}
static void F_19 ( struct V_21 * V_22 )
{
int V_23 ;
struct V_24 * V_25 = F_20 ( V_22 , struct V_24 , V_21 ) ;
F_18 ( V_25 -> V_26 ) ;
F_18 ( V_25 -> V_27 ) ;
F_21 (cpu)
F_15 ( V_25 -> V_28 [ V_23 ] , V_25 -> V_29 ) ;
F_15 ( V_25 , V_25 -> V_30 ) ;
}
static int F_22 ( struct V_31 * V_32 )
{
return F_23 ( & V_32 -> V_33 [ V_34 ] ) +
F_23 ( & V_32 -> V_33 [ V_35 ] ) ;
}
void F_24 ( struct V_36 * V_37 )
{
int V_23 ;
struct V_38 * V_39 ;
F_25 ( & V_37 -> V_40 ) ;
F_26 ( & V_37 -> V_41 ) ;
V_37 -> V_39 = F_27 ( struct V_38 ) ;
F_21 (cpu) {
V_39 = F_28 ( V_37 -> V_39 , V_23 ) ;
V_39 -> V_42 = ( V_43 ) V_44 ;
V_39 -> V_45 = V_46 ;
}
}
void F_29 ( struct V_36 * V_37 )
{
T_1 V_47 ;
struct V_24 * V_25 ;
struct V_31 * V_32 ;
while ( ! F_30 ( & V_37 -> V_41 ) ) {
V_25 = F_20 ( V_37 -> V_41 . V_48 , struct V_24 , V_49 ) ;
F_31 ( & V_25 -> V_49 ) ;
for ( V_47 = 0 ; V_47 < V_25 -> V_50 ; V_47 ++ ) {
V_32 = & V_25 -> V_51 [ V_47 ] ;
if ( F_32 ( F_22 ( V_32 ) ) ) {
F_11 ( L_2
L_3 ,
( unsigned long ) V_47 ,
( unsigned long long ) V_25 -> V_52 ,
( unsigned long long ) V_25 -> V_53 ,
( unsigned long long ) V_25 -> V_54 ,
F_23 ( & V_32 -> V_33 [ V_34 ] ) ,
F_23 ( & V_32 -> V_33 [ V_35 ] ) ) ;
}
}
F_19 ( & V_25 -> V_21 ) ;
}
F_33 ( V_37 -> V_39 ) ;
}
static int F_34 ( struct V_36 * V_37 , V_43 V_52 , V_43 V_53 ,
V_43 V_54 , const char * V_26 , const char * V_27 ,
void (* F_35)( struct V_55 * ) ,
void (* F_36)( struct V_55 * ) ,
struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_24 * V_25 , * V_59 ;
V_43 V_50 ;
T_1 V_47 ;
T_1 V_30 ;
T_1 V_29 ;
struct V_60 * V_14 ;
int V_23 ;
int V_61 ;
int V_62 ;
if ( V_53 < V_52 || ! V_54 )
return - V_63 ;
V_50 = V_53 - V_52 ;
if ( F_37 ( V_50 , V_54 ) )
V_50 ++ ;
if ( V_50 != ( T_1 ) V_50 || ! ( T_1 ) ( V_50 + 1 ) )
return - V_64 ;
V_30 = sizeof( struct V_24 ) + ( T_1 ) V_50 * sizeof( struct V_31 ) ;
if ( ( V_30 - sizeof( struct V_24 ) ) / sizeof( struct V_31 ) != V_50 )
return - V_64 ;
V_29 = ( T_1 ) V_50 * sizeof( struct V_60 ) ;
if ( V_29 / sizeof( struct V_60 ) != V_50 )
return - V_64 ;
if ( ! F_3 ( V_30 + F_38 () * V_29 ) )
return - V_65 ;
V_25 = F_12 ( V_30 , V_66 ) ;
if ( ! V_25 )
return - V_65 ;
V_25 -> V_50 = V_50 ;
V_25 -> V_52 = V_52 ;
V_25 -> V_53 = V_53 ;
V_25 -> V_54 = V_54 ;
V_25 -> V_30 = V_30 ;
V_25 -> V_29 = V_29 ;
V_25 -> V_26 = F_39 ( V_26 , V_16 ) ;
if ( ! V_25 -> V_26 ) {
V_62 = - V_65 ;
goto V_67;
}
V_25 -> V_27 = F_39 ( V_27 , V_16 ) ;
if ( ! V_25 -> V_27 ) {
V_62 = - V_65 ;
goto V_67;
}
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
F_40 ( & V_25 -> V_51 [ V_47 ] . V_33 [ V_34 ] , 0 ) ;
F_40 ( & V_25 -> V_51 [ V_47 ] . V_33 [ V_35 ] , 0 ) ;
}
F_21 (cpu) {
V_14 = F_12 ( V_29 , F_41 ( V_23 ) ) ;
if ( ! V_14 ) {
V_62 = - V_65 ;
goto V_67;
}
V_25 -> V_28 [ V_23 ] = V_14 ;
}
F_35 ( V_56 ) ;
F_42 ( & V_37 -> V_40 ) ;
V_25 -> V_68 = 0 ;
F_43 (l, &stats->list) {
V_59 = F_20 ( V_58 , struct V_24 , V_49 ) ;
if ( F_32 ( V_59 -> V_68 < V_25 -> V_68 ) ) {
V_62 = - V_63 ;
goto V_69;
}
if ( V_59 -> V_68 > V_25 -> V_68 )
break;
if ( F_44 ( V_25 -> V_68 == V_70 ) ) {
V_62 = - V_71 ;
goto V_69;
}
V_25 -> V_68 ++ ;
}
V_61 = V_25 -> V_68 ;
F_45 ( & V_25 -> V_49 , V_58 ) ;
F_46 ( & V_37 -> V_40 ) ;
F_36 ( V_56 ) ;
return V_61 ;
V_69:
F_46 ( & V_37 -> V_40 ) ;
F_36 ( V_56 ) ;
V_67:
F_19 ( & V_25 -> V_21 ) ;
return V_62 ;
}
static struct V_24 * F_47 ( struct V_36 * V_37 , int V_68 )
{
struct V_24 * V_25 ;
F_48 (s, &stats->list, list_entry) {
if ( V_25 -> V_68 > V_68 )
break;
if ( V_25 -> V_68 == V_68 )
return V_25 ;
}
return NULL ;
}
static int F_49 ( struct V_36 * V_37 , int V_68 )
{
struct V_24 * V_25 ;
int V_23 ;
F_42 ( & V_37 -> V_40 ) ;
V_25 = F_47 ( V_37 , V_68 ) ;
if ( ! V_25 ) {
F_46 ( & V_37 -> V_40 ) ;
return - V_72 ;
}
F_50 ( & V_25 -> V_49 ) ;
F_46 ( & V_37 -> V_40 ) ;
F_21 (cpu)
if ( F_16 ( V_25 -> V_28 ) )
goto V_73;
if ( F_16 ( V_25 ) ) {
V_73:
F_51 () ;
F_19 ( & V_25 -> V_21 ) ;
} else {
F_52 ( V_74 ) = 1 ;
F_53 ( & V_25 -> V_21 , F_19 ) ;
}
return 0 ;
}
static int F_54 ( struct V_36 * V_37 , const char * V_75 ,
char * V_76 , unsigned V_77 )
{
struct V_24 * V_25 ;
V_43 V_78 ;
unsigned V_79 = 0 ;
F_42 ( & V_37 -> V_40 ) ;
F_48 (s, &stats->list, list_entry) {
if ( ! V_75 || ! strcmp ( V_75 , V_25 -> V_26 ) ) {
V_78 = V_25 -> V_53 - V_25 -> V_52 ;
F_55 ( L_4 , V_25 -> V_68 ,
( unsigned long long ) V_25 -> V_52 ,
( unsigned long long ) V_78 ,
( unsigned long long ) V_25 -> V_54 ,
V_25 -> V_26 ,
V_25 -> V_27 ) ;
}
}
F_46 ( & V_37 -> V_40 ) ;
return 1 ;
}
static void F_56 ( struct V_31 * V_32 , struct V_60 * V_14 )
{
unsigned long V_80 = V_81 ;
unsigned V_82 ;
unsigned V_83 ;
unsigned long V_84 = V_80 - V_32 -> V_85 ;
if ( ! V_84 )
return;
V_82 = ( unsigned ) F_23 ( & V_32 -> V_33 [ V_34 ] ) ;
V_83 = ( unsigned ) F_23 ( & V_32 -> V_33 [ V_35 ] ) ;
if ( V_82 )
V_14 -> V_86 [ V_34 ] += V_84 ;
if ( V_83 )
V_14 -> V_86 [ V_35 ] += V_84 ;
if ( V_82 + V_83 ) {
V_14 -> V_87 += V_84 ;
V_14 -> V_88 += ( V_82 + V_83 ) * V_84 ;
}
V_32 -> V_85 = V_80 ;
}
static void F_57 ( struct V_24 * V_25 , T_1 V_89 ,
unsigned long V_90 , V_43 V_78 , bool V_91 ,
bool V_53 , unsigned long V_92 )
{
unsigned long V_93 = V_90 & V_94 ;
struct V_31 * V_32 = & V_25 -> V_51 [ V_89 ] ;
struct V_60 * V_14 ;
#if V_95 == 32
unsigned long V_12 ;
F_58 ( V_12 ) ;
#else
F_59 () ;
#endif
V_14 = & V_25 -> V_28 [ F_60 () ] [ V_89 ] ;
if ( ! V_53 ) {
F_56 ( V_32 , V_14 ) ;
F_61 ( & V_32 -> V_33 [ V_93 ] ) ;
} else {
F_56 ( V_32 , V_14 ) ;
F_62 ( & V_32 -> V_33 [ V_93 ] ) ;
V_14 -> V_96 [ V_93 ] += V_78 ;
V_14 -> V_97 [ V_93 ] += 1 ;
V_14 -> V_98 [ V_93 ] += V_91 ;
V_14 -> V_99 [ V_93 ] += V_92 ;
}
#if V_95 == 32
F_63 ( V_12 ) ;
#else
F_64 () ;
#endif
}
static void F_65 ( struct V_24 * V_25 , unsigned long V_90 ,
V_43 V_100 , V_43 V_101 ,
bool V_53 , unsigned long V_92 ,
struct V_102 * V_103 )
{
V_43 V_104 , V_105 , V_106 , V_107 ;
T_1 V_89 ;
if ( V_101 <= V_25 -> V_52 || V_100 >= V_25 -> V_53 )
return;
if ( F_44 ( V_100 < V_25 -> V_52 ) ) {
V_104 = 0 ;
V_106 = V_101 - V_25 -> V_52 ;
} else {
V_104 = V_100 - V_25 -> V_52 ;
V_106 = V_101 - V_100 ;
}
if ( F_44 ( V_101 > V_25 -> V_53 ) )
V_106 -= ( V_101 - V_25 -> V_53 ) ;
V_105 = F_37 ( V_104 , V_25 -> V_54 ) ;
V_89 = V_104 ;
do {
if ( F_9 ( V_89 >= V_25 -> V_50 ) ) {
F_11 ( L_5 , V_25 -> V_68 ) ;
return;
}
V_107 = V_106 ;
if ( V_107 > V_25 -> V_54 - V_105 )
V_107 = V_25 -> V_54 - V_105 ;
F_57 ( V_25 , V_89 , V_90 , V_107 ,
V_103 -> V_91 , V_53 , V_92 ) ;
V_106 -= V_107 ;
V_89 ++ ;
V_105 = 0 ;
} while ( F_44 ( V_106 != 0 ) );
}
void F_66 ( struct V_36 * V_37 , unsigned long V_90 ,
V_43 V_100 , unsigned V_108 , bool V_53 ,
unsigned long V_92 , struct V_102 * V_103 )
{
struct V_24 * V_25 ;
V_43 V_101 ;
struct V_38 * V_39 ;
if ( F_44 ( ! V_108 ) )
return;
V_101 = V_100 + V_108 ;
if ( ! V_53 ) {
V_39 = F_67 ( V_37 -> V_39 ) ;
V_103 -> V_91 =
( V_100 == ( F_52 ( V_39 -> V_42 ) &&
( ( V_90 & ( V_94 | V_109 ) ) ==
( F_52 ( V_39 -> V_45 ) & ( V_94 | V_109 ) ) )
) ) ;
F_52 ( V_39 -> V_42 ) = V_101 ;
F_52 ( V_39 -> V_45 ) = V_90 ;
}
F_68 () ;
F_69 (s, &stats->list, list_entry)
F_65 ( V_25 , V_90 , V_100 , V_101 , V_53 , V_92 , V_103 ) ;
F_70 () ;
}
static void F_71 ( struct V_31 * V_32 ,
struct V_24 * V_25 , T_1 V_110 )
{
int V_23 ;
struct V_60 * V_14 ;
F_72 () ;
V_14 = & V_25 -> V_28 [ F_60 () ] [ V_110 ] ;
F_56 ( V_32 , V_14 ) ;
F_73 () ;
memset ( & V_32 -> V_111 , 0 , sizeof( V_32 -> V_111 ) ) ;
F_21 (cpu) {
V_14 = & V_25 -> V_28 [ V_23 ] [ V_110 ] ;
V_32 -> V_111 . V_96 [ V_34 ] += F_52 ( V_14 -> V_96 [ V_34 ] ) ;
V_32 -> V_111 . V_96 [ V_35 ] += F_52 ( V_14 -> V_96 [ V_35 ] ) ;
V_32 -> V_111 . V_97 [ V_34 ] += F_52 ( V_14 -> V_97 [ V_34 ] ) ;
V_32 -> V_111 . V_97 [ V_35 ] += F_52 ( V_14 -> V_97 [ V_35 ] ) ;
V_32 -> V_111 . V_98 [ V_34 ] += F_52 ( V_14 -> V_98 [ V_34 ] ) ;
V_32 -> V_111 . V_98 [ V_35 ] += F_52 ( V_14 -> V_98 [ V_35 ] ) ;
V_32 -> V_111 . V_99 [ V_34 ] += F_52 ( V_14 -> V_99 [ V_34 ] ) ;
V_32 -> V_111 . V_99 [ V_35 ] += F_52 ( V_14 -> V_99 [ V_35 ] ) ;
V_32 -> V_111 . V_86 [ V_34 ] += F_52 ( V_14 -> V_86 [ V_34 ] ) ;
V_32 -> V_111 . V_86 [ V_35 ] += F_52 ( V_14 -> V_86 [ V_35 ] ) ;
V_32 -> V_111 . V_87 += F_52 ( V_14 -> V_87 ) ;
V_32 -> V_111 . V_88 += F_52 ( V_14 -> V_88 ) ;
}
}
static void F_74 ( struct V_24 * V_25 , T_1 V_112 , T_1 V_113 ,
bool V_114 )
{
T_1 V_110 ;
struct V_31 * V_32 ;
struct V_60 * V_14 ;
for ( V_110 = V_112 ; V_110 < V_113 ; V_110 ++ ) {
V_32 = & V_25 -> V_51 [ V_110 ] ;
if ( V_114 )
F_71 ( V_32 , V_25 , V_110 ) ;
F_72 () ;
V_14 = & V_25 -> V_28 [ F_60 () ] [ V_110 ] ;
V_14 -> V_96 [ V_34 ] -= V_32 -> V_111 . V_96 [ V_34 ] ;
V_14 -> V_96 [ V_35 ] -= V_32 -> V_111 . V_96 [ V_35 ] ;
V_14 -> V_97 [ V_34 ] -= V_32 -> V_111 . V_97 [ V_34 ] ;
V_14 -> V_97 [ V_35 ] -= V_32 -> V_111 . V_97 [ V_35 ] ;
V_14 -> V_98 [ V_34 ] -= V_32 -> V_111 . V_98 [ V_34 ] ;
V_14 -> V_98 [ V_35 ] -= V_32 -> V_111 . V_98 [ V_35 ] ;
V_14 -> V_99 [ V_34 ] -= V_32 -> V_111 . V_99 [ V_34 ] ;
V_14 -> V_99 [ V_35 ] -= V_32 -> V_111 . V_99 [ V_35 ] ;
V_14 -> V_86 [ V_34 ] -= V_32 -> V_111 . V_86 [ V_34 ] ;
V_14 -> V_86 [ V_35 ] -= V_32 -> V_111 . V_86 [ V_35 ] ;
V_14 -> V_87 -= V_32 -> V_111 . V_87 ;
V_14 -> V_88 -= V_32 -> V_111 . V_88 ;
F_73 () ;
}
}
static int F_75 ( struct V_36 * V_37 , int V_68 )
{
struct V_24 * V_25 ;
F_42 ( & V_37 -> V_40 ) ;
V_25 = F_47 ( V_37 , V_68 ) ;
if ( ! V_25 ) {
F_46 ( & V_37 -> V_40 ) ;
return - V_72 ;
}
F_74 ( V_25 , 0 , V_25 -> V_50 , true ) ;
F_46 ( & V_37 -> V_40 ) ;
return 1 ;
}
static unsigned long long F_76 ( unsigned long long V_115 )
{
unsigned long long V_76 = 0 ;
unsigned V_116 ;
if ( V_115 )
V_76 = F_77 ( V_115 & 0x3fffff ) ;
if ( V_115 >= 1 << 22 ) {
V_116 = F_77 ( 1 << 22 ) ;
V_76 += ( unsigned long long ) V_116 * ( unsigned long long ) F_77 ( ( V_115 >> 22 ) & 0x3fffff ) ;
}
if ( V_115 >= 1ULL << 44 )
V_76 += ( unsigned long long ) V_116 * ( unsigned long long ) V_116 * ( unsigned long long ) F_77 ( V_115 >> 44 ) ;
return V_76 ;
}
static int F_78 ( struct V_36 * V_37 , int V_68 ,
T_1 V_112 , T_1 V_117 ,
bool V_118 , char * V_76 , unsigned V_77 )
{
unsigned V_79 = 0 ;
struct V_24 * V_25 ;
T_1 V_110 ;
V_43 V_52 , V_53 , V_54 ;
T_1 V_113 ;
struct V_31 * V_32 ;
F_42 ( & V_37 -> V_40 ) ;
V_25 = F_47 ( V_37 , V_68 ) ;
if ( ! V_25 ) {
F_46 ( & V_37 -> V_40 ) ;
return - V_72 ;
}
V_113 = V_112 + V_117 ;
if ( V_113 < V_112 ||
V_113 > V_25 -> V_50 )
V_113 = V_25 -> V_50 ;
if ( V_112 > V_113 )
V_112 = V_113 ;
V_54 = V_25 -> V_54 ;
V_52 = V_25 -> V_52 + ( V_54 * V_112 ) ;
for ( V_110 = V_112 ; V_110 < V_113 ; V_110 ++ , V_52 = V_53 ) {
V_32 = & V_25 -> V_51 [ V_110 ] ;
V_53 = V_52 + V_54 ;
if ( F_44 ( V_53 > V_25 -> V_53 ) )
V_53 = V_25 -> V_53 ;
F_71 ( V_32 , V_25 , V_110 ) ;
F_55 ( L_6 ,
( unsigned long long ) V_52 ,
( unsigned long long ) V_54 ,
V_32 -> V_111 . V_97 [ V_34 ] ,
V_32 -> V_111 . V_98 [ V_34 ] ,
V_32 -> V_111 . V_96 [ V_34 ] ,
F_76 ( V_32 -> V_111 . V_99 [ V_34 ] ) ,
V_32 -> V_111 . V_97 [ V_35 ] ,
V_32 -> V_111 . V_98 [ V_35 ] ,
V_32 -> V_111 . V_96 [ V_35 ] ,
F_76 ( V_32 -> V_111 . V_99 [ V_35 ] ) ,
F_22 ( V_32 ) ,
F_76 ( V_32 -> V_111 . V_87 ) ,
F_76 ( V_32 -> V_111 . V_88 ) ,
F_76 ( V_32 -> V_111 . V_86 [ V_34 ] ) ,
F_76 ( V_32 -> V_111 . V_86 [ V_35 ] ) ) ;
if ( F_44 ( V_79 + 1 >= V_77 ) )
goto V_119;
}
if ( V_118 )
F_74 ( V_25 , V_112 , V_113 , false ) ;
V_119:
F_46 ( & V_37 -> V_40 ) ;
return 1 ;
}
static int F_79 ( struct V_36 * V_37 , int V_68 , const char * V_27 )
{
struct V_24 * V_25 ;
const char * V_120 ;
F_42 ( & V_37 -> V_40 ) ;
V_25 = F_47 ( V_37 , V_68 ) ;
if ( ! V_25 ) {
F_46 ( & V_37 -> V_40 ) ;
return - V_72 ;
}
V_120 = F_39 ( V_27 , V_16 ) ;
if ( ! V_120 ) {
F_46 ( & V_37 -> V_40 ) ;
return - V_65 ;
}
F_18 ( V_25 -> V_27 ) ;
V_25 -> V_27 = V_120 ;
F_46 ( & V_37 -> V_40 ) ;
return 0 ;
}
static int F_80 ( struct V_55 * V_56 ,
unsigned V_121 , char * * V_122 ,
char * V_76 , unsigned V_77 )
{
int V_68 ;
char V_123 ;
unsigned long long V_52 , V_53 , V_78 , V_54 ;
unsigned V_124 ;
const char * V_26 , * V_27 ;
if ( V_121 < 3 || V_121 > 5 )
return - V_63 ;
if ( ! strcmp ( V_122 [ 1 ] , L_7 ) ) {
V_52 = 0 ;
V_78 = F_81 ( V_56 ) ;
if ( ! V_78 )
V_78 = 1 ;
} else if ( sscanf ( V_122 [ 1 ] , L_8 , & V_52 , & V_78 , & V_123 ) != 2 ||
V_52 != ( V_43 ) V_52 || V_78 != ( V_43 ) V_78 )
return - V_63 ;
V_53 = V_52 + V_78 ;
if ( V_52 >= V_53 )
return - V_63 ;
if ( sscanf ( V_122 [ 2 ] , L_9 , & V_124 , & V_123 ) == 1 ) {
V_54 = V_53 - V_52 ;
if ( F_82 ( V_54 , V_124 ) )
V_54 ++ ;
if ( ! V_54 )
V_54 = 1 ;
} else if ( sscanf ( V_122 [ 2 ] , L_10 , & V_54 , & V_123 ) != 1 ||
V_54 != ( V_43 ) V_54 || ! V_54 )
return - V_63 ;
V_26 = L_7 ;
V_27 = L_7 ;
if ( V_121 > 3 )
V_26 = V_122 [ 3 ] ;
if ( V_121 > 4 )
V_27 = V_122 [ 4 ] ;
snprintf ( V_76 , V_77 , L_11 , V_70 ) ;
if ( F_83 ( V_76 , V_77 ) )
return 1 ;
V_68 = F_34 ( F_84 ( V_56 ) , V_52 , V_53 , V_54 , V_26 , V_27 ,
V_125 , V_126 , V_56 ) ;
if ( V_68 < 0 )
return V_68 ;
snprintf ( V_76 , V_77 , L_11 , V_68 ) ;
return 1 ;
}
static int F_85 ( struct V_55 * V_56 ,
unsigned V_121 , char * * V_122 )
{
int V_68 ;
char V_123 ;
if ( V_121 != 2 )
return - V_63 ;
if ( sscanf ( V_122 [ 1 ] , L_12 , & V_68 , & V_123 ) != 1 || V_68 < 0 )
return - V_63 ;
return F_49 ( F_84 ( V_56 ) , V_68 ) ;
}
static int F_86 ( struct V_55 * V_56 ,
unsigned V_121 , char * * V_122 )
{
int V_68 ;
char V_123 ;
if ( V_121 != 2 )
return - V_63 ;
if ( sscanf ( V_122 [ 1 ] , L_12 , & V_68 , & V_123 ) != 1 || V_68 < 0 )
return - V_63 ;
return F_75 ( F_84 ( V_56 ) , V_68 ) ;
}
static int F_87 ( struct V_55 * V_56 ,
unsigned V_121 , char * * V_122 ,
char * V_76 , unsigned V_77 )
{
int V_62 ;
const char * V_75 = NULL ;
if ( V_121 < 1 || V_121 > 2 )
return - V_63 ;
if ( V_121 > 1 ) {
V_75 = F_39 ( V_122 [ 1 ] , V_16 ) ;
if ( ! V_75 )
return - V_65 ;
}
V_62 = F_54 ( F_84 ( V_56 ) , V_75 , V_76 , V_77 ) ;
F_18 ( V_75 ) ;
return V_62 ;
}
static int F_88 ( struct V_55 * V_56 ,
unsigned V_121 , char * * V_122 , bool V_118 ,
char * V_76 , unsigned V_77 )
{
int V_68 ;
char V_123 ;
unsigned long V_112 = 0 , V_117 = V_127 ;
if ( V_121 != 2 && V_121 != 4 )
return - V_63 ;
if ( sscanf ( V_122 [ 1 ] , L_12 , & V_68 , & V_123 ) != 1 || V_68 < 0 )
return - V_63 ;
if ( V_121 > 3 ) {
if ( strcmp ( V_122 [ 2 ] , L_7 ) &&
sscanf ( V_122 [ 2 ] , L_13 , & V_112 , & V_123 ) != 1 )
return - V_63 ;
if ( strcmp ( V_122 [ 3 ] , L_7 ) &&
sscanf ( V_122 [ 3 ] , L_13 , & V_117 , & V_123 ) != 1 )
return - V_63 ;
}
return F_78 ( F_84 ( V_56 ) , V_68 , V_112 , V_117 , V_118 ,
V_76 , V_77 ) ;
}
static int F_89 ( struct V_55 * V_56 ,
unsigned V_121 , char * * V_122 )
{
int V_68 ;
char V_123 ;
if ( V_121 != 3 )
return - V_63 ;
if ( sscanf ( V_122 [ 1 ] , L_12 , & V_68 , & V_123 ) != 1 || V_68 < 0 )
return - V_63 ;
return F_79 ( F_84 ( V_56 ) , V_68 , V_122 [ 2 ] ) ;
}
int F_90 ( struct V_55 * V_56 , unsigned V_121 , char * * V_122 ,
char * V_76 , unsigned V_77 )
{
int V_62 ;
if ( F_91 ( V_56 ) ) {
F_92 ( L_14 ) ;
return - V_128 ;
}
if ( ! strcasecmp ( V_122 [ 0 ] , L_15 ) )
V_62 = F_80 ( V_56 , V_121 , V_122 , V_76 , V_77 ) ;
else if ( ! strcasecmp ( V_122 [ 0 ] , L_16 ) )
V_62 = F_85 ( V_56 , V_121 , V_122 ) ;
else if ( ! strcasecmp ( V_122 [ 0 ] , L_17 ) )
V_62 = F_86 ( V_56 , V_121 , V_122 ) ;
else if ( ! strcasecmp ( V_122 [ 0 ] , L_18 ) )
V_62 = F_87 ( V_56 , V_121 , V_122 , V_76 , V_77 ) ;
else if ( ! strcasecmp ( V_122 [ 0 ] , L_19 ) )
V_62 = F_88 ( V_56 , V_121 , V_122 , false , V_76 , V_77 ) ;
else if ( ! strcasecmp ( V_122 [ 0 ] , L_20 ) )
V_62 = F_88 ( V_56 , V_121 , V_122 , true , V_76 , V_77 ) ;
else if ( ! strcasecmp ( V_122 [ 0 ] , L_21 ) )
V_62 = F_89 ( V_56 , V_121 , V_122 ) ;
else
return 2 ;
if ( V_62 == - V_63 )
F_92 ( L_22 , V_122 [ 0 ] ) ;
return V_62 ;
}
int T_2 F_93 ( void )
{
V_3 = 0 ;
V_74 = 0 ;
return 0 ;
}
void F_94 ( void )
{
if ( V_74 )
F_95 () ;
if ( F_32 ( V_3 ) )
F_11 ( L_23 , V_3 ) ;
}
