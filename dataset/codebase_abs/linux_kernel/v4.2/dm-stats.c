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
F_16 ( V_20 ) ;
}
static void F_17 ( struct V_21 * V_22 )
{
int V_23 ;
struct V_24 * V_25 = F_18 ( V_22 , struct V_24 , V_21 ) ;
F_19 ( V_25 -> V_26 ) ;
F_19 ( V_25 -> V_27 ) ;
F_20 (cpu) {
F_15 ( V_25 -> V_28 [ V_23 ] [ 0 ] . V_29 , V_25 -> V_30 ) ;
F_15 ( V_25 -> V_28 [ V_23 ] , V_25 -> V_31 ) ;
}
F_15 ( V_25 -> V_32 [ 0 ] . V_33 . V_29 , V_25 -> V_30 ) ;
F_15 ( V_25 , V_25 -> V_34 ) ;
}
static int F_21 ( struct V_35 * V_36 )
{
return F_22 ( & V_36 -> V_37 [ V_38 ] ) +
F_22 ( & V_36 -> V_37 [ V_39 ] ) ;
}
void F_23 ( struct V_40 * V_41 )
{
int V_23 ;
struct V_42 * V_43 ;
F_24 ( & V_41 -> V_44 ) ;
F_25 ( & V_41 -> V_45 ) ;
V_41 -> V_43 = F_26 ( struct V_42 ) ;
F_20 (cpu) {
V_43 = F_27 ( V_41 -> V_43 , V_23 ) ;
V_43 -> V_46 = ( V_47 ) V_48 ;
V_43 -> V_49 = V_50 ;
}
}
void F_28 ( struct V_40 * V_41 )
{
T_1 V_51 ;
struct V_24 * V_25 ;
struct V_35 * V_36 ;
while ( ! F_29 ( & V_41 -> V_45 ) ) {
V_25 = F_18 ( V_41 -> V_45 . V_52 , struct V_24 , V_53 ) ;
F_30 ( & V_25 -> V_53 ) ;
for ( V_51 = 0 ; V_51 < V_25 -> V_54 ; V_51 ++ ) {
V_36 = & V_25 -> V_32 [ V_51 ] ;
if ( F_31 ( F_21 ( V_36 ) ) ) {
F_11 ( L_2
L_3 ,
( unsigned long ) V_51 ,
( unsigned long long ) V_25 -> V_55 ,
( unsigned long long ) V_25 -> V_56 ,
( unsigned long long ) V_25 -> V_57 ,
F_22 ( & V_36 -> V_37 [ V_38 ] ) ,
F_22 ( & V_36 -> V_37 [ V_39 ] ) ) ;
}
}
F_17 ( & V_25 -> V_21 ) ;
}
F_32 ( V_41 -> V_43 ) ;
}
static int F_33 ( struct V_40 * V_41 , V_47 V_55 , V_47 V_56 ,
V_47 V_57 , unsigned V_58 ,
unsigned V_59 ,
unsigned long long * V_60 ,
const char * V_26 , const char * V_27 ,
void (* F_34)( struct V_61 * ) ,
void (* F_35)( struct V_61 * ) ,
struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_24 * V_25 , * V_65 ;
V_47 V_54 ;
T_1 V_51 ;
T_1 V_34 ;
T_1 V_31 ;
T_1 V_30 ;
struct V_66 * V_14 ;
int V_23 ;
int V_67 ;
int V_68 ;
if ( V_56 < V_55 || ! V_57 )
return - V_69 ;
V_54 = V_56 - V_55 ;
if ( F_36 ( V_54 , V_57 ) )
V_54 ++ ;
if ( V_54 != ( T_1 ) V_54 || ! ( T_1 ) ( V_54 + 1 ) )
return - V_70 ;
V_34 = sizeof( struct V_24 ) + ( T_1 ) V_54 * sizeof( struct V_35 ) ;
if ( ( V_34 - sizeof( struct V_24 ) ) / sizeof( struct V_35 ) != V_54 )
return - V_70 ;
V_31 = ( T_1 ) V_54 * sizeof( struct V_66 ) ;
if ( V_31 / sizeof( struct V_66 ) != V_54 )
return - V_70 ;
V_30 = ( V_59 + 1 ) * ( T_1 ) V_54 * sizeof( unsigned long long ) ;
if ( V_30 / ( V_59 + 1 ) != ( T_1 ) V_54 * sizeof( unsigned long long ) )
return - V_70 ;
if ( ! F_3 ( V_34 + V_30 +
F_37 () * ( V_31 + V_30 ) ) )
return - V_71 ;
V_25 = F_12 ( V_34 , V_72 ) ;
if ( ! V_25 )
return - V_71 ;
V_25 -> V_58 = V_58 ;
V_25 -> V_54 = V_54 ;
V_25 -> V_55 = V_55 ;
V_25 -> V_56 = V_56 ;
V_25 -> V_57 = V_57 ;
V_25 -> V_34 = V_34 ;
V_25 -> V_31 = V_31 ;
V_25 -> V_30 = V_30 ;
V_25 -> V_59 = V_59 ;
V_25 -> V_60 = F_38 ( V_60 ,
V_25 -> V_59 * sizeof( unsigned long long ) , V_16 ) ;
if ( ! V_25 -> V_60 ) {
V_68 = - V_71 ;
goto V_73;
}
V_25 -> V_26 = F_39 ( V_26 , V_16 ) ;
if ( ! V_25 -> V_26 ) {
V_68 = - V_71 ;
goto V_73;
}
V_25 -> V_27 = F_39 ( V_27 , V_16 ) ;
if ( ! V_25 -> V_27 ) {
V_68 = - V_71 ;
goto V_73;
}
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
F_40 ( & V_25 -> V_32 [ V_51 ] . V_37 [ V_38 ] , 0 ) ;
F_40 ( & V_25 -> V_32 [ V_51 ] . V_37 [ V_39 ] , 0 ) ;
}
if ( V_25 -> V_59 ) {
unsigned long long * V_74 ;
V_74 = F_12 ( V_25 -> V_30 , V_72 ) ;
if ( ! V_74 ) {
V_68 = - V_71 ;
goto V_73;
}
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
V_25 -> V_32 [ V_51 ] . V_33 . V_29 = V_74 ;
V_74 += V_25 -> V_59 + 1 ;
}
}
F_20 (cpu) {
V_14 = F_12 ( V_31 , F_41 ( V_23 ) ) ;
if ( ! V_14 ) {
V_68 = - V_71 ;
goto V_73;
}
V_25 -> V_28 [ V_23 ] = V_14 ;
if ( V_25 -> V_59 ) {
unsigned long long * V_74 ;
V_74 = F_12 ( V_25 -> V_30 , F_41 ( V_23 ) ) ;
if ( ! V_74 ) {
V_68 = - V_71 ;
goto V_73;
}
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
V_14 [ V_51 ] . V_29 = V_74 ;
V_74 += V_25 -> V_59 + 1 ;
}
}
}
F_34 ( V_62 ) ;
F_42 ( & V_41 -> V_44 ) ;
V_25 -> V_75 = 0 ;
F_43 (l, &stats->list) {
V_65 = F_18 ( V_64 , struct V_24 , V_53 ) ;
if ( F_31 ( V_65 -> V_75 < V_25 -> V_75 ) ) {
V_68 = - V_69 ;
goto V_76;
}
if ( V_65 -> V_75 > V_25 -> V_75 )
break;
if ( F_44 ( V_25 -> V_75 == V_77 ) ) {
V_68 = - V_78 ;
goto V_76;
}
V_25 -> V_75 ++ ;
}
V_67 = V_25 -> V_75 ;
F_45 ( & V_25 -> V_53 , V_64 ) ;
F_46 ( & V_41 -> V_44 ) ;
F_35 ( V_62 ) ;
return V_67 ;
V_76:
F_46 ( & V_41 -> V_44 ) ;
F_35 ( V_62 ) ;
V_73:
F_17 ( & V_25 -> V_21 ) ;
return V_68 ;
}
static struct V_24 * F_47 ( struct V_40 * V_41 , int V_75 )
{
struct V_24 * V_25 ;
F_48 (s, &stats->list, list_entry) {
if ( V_25 -> V_75 > V_75 )
break;
if ( V_25 -> V_75 == V_75 )
return V_25 ;
}
return NULL ;
}
static int F_49 ( struct V_40 * V_41 , int V_75 )
{
struct V_24 * V_25 ;
int V_23 ;
F_42 ( & V_41 -> V_44 ) ;
V_25 = F_47 ( V_41 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_41 -> V_44 ) ;
return - V_79 ;
}
F_50 ( & V_25 -> V_53 ) ;
F_46 ( & V_41 -> V_44 ) ;
F_20 (cpu)
if ( F_51 ( V_25 -> V_28 ) ||
F_51 ( V_25 -> V_28 [ V_23 ] [ 0 ] . V_29 ) )
goto V_80;
if ( F_51 ( V_25 ) ||
F_51 ( V_25 -> V_32 [ 0 ] . V_33 . V_29 ) ) {
V_80:
F_52 () ;
F_17 ( & V_25 -> V_21 ) ;
} else {
F_53 ( V_81 ) = 1 ;
F_54 ( & V_25 -> V_21 , F_17 ) ;
}
return 0 ;
}
static int F_55 ( struct V_40 * V_41 , const char * V_82 ,
char * V_83 , unsigned V_84 )
{
struct V_24 * V_25 ;
V_47 V_85 ;
unsigned V_86 = 0 ;
F_42 ( & V_41 -> V_44 ) ;
F_48 (s, &stats->list, list_entry) {
if ( ! V_82 || ! strcmp ( V_82 , V_25 -> V_26 ) ) {
V_85 = V_25 -> V_56 - V_25 -> V_55 ;
F_56 ( L_4 , V_25 -> V_75 ,
( unsigned long long ) V_25 -> V_55 ,
( unsigned long long ) V_85 ,
( unsigned long long ) V_25 -> V_57 ,
V_25 -> V_26 ,
V_25 -> V_27 ) ;
}
}
F_46 ( & V_41 -> V_44 ) ;
return 1 ;
}
static void F_57 ( struct V_24 * V_25 , struct V_35 * V_36 ,
struct V_66 * V_14 )
{
unsigned long long V_87 , V_88 ;
unsigned V_89 , V_90 ;
if ( F_58 ( ! ( V_25 -> V_58 & V_91 ) ) )
V_87 = V_92 ;
else
V_87 = F_59 ( F_60 () ) ;
V_88 = V_87 - V_36 -> V_93 ;
if ( ! V_88 )
return;
V_89 = ( unsigned ) F_22 ( & V_36 -> V_37 [ V_38 ] ) ;
V_90 = ( unsigned ) F_22 ( & V_36 -> V_37 [ V_39 ] ) ;
if ( V_89 )
V_14 -> V_94 [ V_38 ] += V_88 ;
if ( V_90 )
V_14 -> V_94 [ V_39 ] += V_88 ;
if ( V_89 + V_90 ) {
V_14 -> V_95 += V_88 ;
V_14 -> V_96 += ( V_89 + V_90 ) * V_88 ;
}
V_36 -> V_93 = V_87 ;
}
static void F_61 ( struct V_24 * V_25 , T_1 V_97 ,
unsigned long V_98 , V_47 V_85 ,
struct V_99 * V_100 , bool V_56 ,
unsigned long V_101 )
{
unsigned long V_102 = V_98 & V_103 ;
struct V_35 * V_36 = & V_25 -> V_32 [ V_97 ] ;
struct V_66 * V_14 ;
#if V_104 == 32
unsigned long V_12 ;
F_62 ( V_12 ) ;
#else
F_63 () ;
#endif
V_14 = & V_25 -> V_28 [ F_64 () ] [ V_97 ] ;
if ( ! V_56 ) {
F_57 ( V_25 , V_36 , V_14 ) ;
F_65 ( & V_36 -> V_37 [ V_102 ] ) ;
} else {
unsigned long long V_105 ;
F_57 ( V_25 , V_36 , V_14 ) ;
F_66 ( & V_36 -> V_37 [ V_102 ] ) ;
V_14 -> V_106 [ V_102 ] += V_85 ;
V_14 -> V_107 [ V_102 ] += 1 ;
V_14 -> V_108 [ V_102 ] += V_100 -> V_109 ;
if ( ! ( V_25 -> V_58 & V_91 ) ) {
V_14 -> V_110 [ V_102 ] += V_101 ;
V_105 = F_67 ( V_101 ) ;
} else {
V_14 -> V_110 [ V_102 ] += V_100 -> V_111 ;
V_105 = V_100 -> V_111 ;
}
if ( V_25 -> V_59 ) {
unsigned V_112 = 0 , V_74 = V_25 -> V_59 + 1 ;
while ( V_112 + 1 < V_74 ) {
unsigned V_113 = ( V_112 + V_74 ) / 2 ;
if ( V_25 -> V_60 [ V_113 - 1 ] > V_105 ) {
V_74 = V_113 ;
} else {
V_112 = V_113 ;
}
}
V_14 -> V_29 [ V_112 ] ++ ;
}
}
#if V_104 == 32
F_68 ( V_12 ) ;
#else
F_69 () ;
#endif
}
static void F_70 ( struct V_24 * V_25 , unsigned long V_98 ,
V_47 V_114 , V_47 V_115 ,
bool V_56 , unsigned long V_101 ,
struct V_99 * V_100 )
{
V_47 V_116 , V_117 , V_118 , V_119 ;
T_1 V_97 ;
if ( V_115 <= V_25 -> V_55 || V_114 >= V_25 -> V_56 )
return;
if ( F_44 ( V_114 < V_25 -> V_55 ) ) {
V_116 = 0 ;
V_118 = V_115 - V_25 -> V_55 ;
} else {
V_116 = V_114 - V_25 -> V_55 ;
V_118 = V_115 - V_114 ;
}
if ( F_44 ( V_115 > V_25 -> V_56 ) )
V_118 -= ( V_115 - V_25 -> V_56 ) ;
V_117 = F_36 ( V_116 , V_25 -> V_57 ) ;
V_97 = V_116 ;
do {
if ( F_9 ( V_97 >= V_25 -> V_54 ) ) {
F_11 ( L_5 , V_25 -> V_75 ) ;
return;
}
V_119 = V_118 ;
if ( V_119 > V_25 -> V_57 - V_117 )
V_119 = V_25 -> V_57 - V_117 ;
F_61 ( V_25 , V_97 , V_98 , V_119 ,
V_100 , V_56 , V_101 ) ;
V_118 -= V_119 ;
V_97 ++ ;
V_117 = 0 ;
} while ( F_44 ( V_118 != 0 ) );
}
void F_71 ( struct V_40 * V_41 , unsigned long V_98 ,
V_47 V_114 , unsigned V_120 , bool V_56 ,
unsigned long V_101 ,
struct V_99 * V_100 )
{
struct V_24 * V_25 ;
V_47 V_115 ;
struct V_42 * V_43 ;
bool V_121 ;
if ( F_44 ( ! V_120 ) )
return;
V_115 = V_114 + V_120 ;
if ( ! V_56 ) {
V_43 = F_72 ( V_41 -> V_43 ) ;
V_100 -> V_109 =
( V_114 == ( F_53 ( V_43 -> V_46 ) &&
( ( V_98 & ( V_103 | V_122 ) ) ==
( F_53 ( V_43 -> V_49 ) & ( V_103 | V_122 ) ) )
) ) ;
F_53 ( V_43 -> V_46 ) = V_115 ;
F_53 ( V_43 -> V_49 ) = V_98 ;
}
F_73 () ;
V_121 = false ;
F_74 (s, &stats->list, list_entry) {
if ( V_25 -> V_58 & V_91 && ! V_121 ) {
if ( ! V_56 )
V_100 -> V_111 = F_59 ( F_60 () ) ;
else
V_100 -> V_111 = F_59 ( F_60 () ) - V_100 -> V_111 ;
V_121 = true ;
}
F_70 ( V_25 , V_98 , V_114 , V_115 , V_56 , V_101 , V_100 ) ;
}
F_75 () ;
}
static void F_76 ( struct V_35 * V_36 ,
struct V_24 * V_25 , T_1 V_123 )
{
int V_23 ;
struct V_66 * V_14 ;
F_77 () ;
V_14 = & V_25 -> V_28 [ F_64 () ] [ V_123 ] ;
F_57 ( V_25 , V_36 , V_14 ) ;
F_78 () ;
V_36 -> V_33 . V_106 [ V_38 ] = 0 ;
V_36 -> V_33 . V_106 [ V_39 ] = 0 ;
V_36 -> V_33 . V_107 [ V_38 ] = 0 ;
V_36 -> V_33 . V_107 [ V_39 ] = 0 ;
V_36 -> V_33 . V_108 [ V_38 ] = 0 ;
V_36 -> V_33 . V_108 [ V_39 ] = 0 ;
V_36 -> V_33 . V_110 [ V_38 ] = 0 ;
V_36 -> V_33 . V_110 [ V_39 ] = 0 ;
V_36 -> V_33 . V_94 [ V_38 ] = 0 ;
V_36 -> V_33 . V_94 [ V_39 ] = 0 ;
V_36 -> V_33 . V_95 = 0 ;
V_36 -> V_33 . V_96 = 0 ;
if ( V_25 -> V_59 )
memset ( V_36 -> V_33 . V_29 , 0 , ( V_25 -> V_59 + 1 ) * sizeof( unsigned long long ) ) ;
F_20 (cpu) {
V_14 = & V_25 -> V_28 [ V_23 ] [ V_123 ] ;
V_36 -> V_33 . V_106 [ V_38 ] += F_53 ( V_14 -> V_106 [ V_38 ] ) ;
V_36 -> V_33 . V_106 [ V_39 ] += F_53 ( V_14 -> V_106 [ V_39 ] ) ;
V_36 -> V_33 . V_107 [ V_38 ] += F_53 ( V_14 -> V_107 [ V_38 ] ) ;
V_36 -> V_33 . V_107 [ V_39 ] += F_53 ( V_14 -> V_107 [ V_39 ] ) ;
V_36 -> V_33 . V_108 [ V_38 ] += F_53 ( V_14 -> V_108 [ V_38 ] ) ;
V_36 -> V_33 . V_108 [ V_39 ] += F_53 ( V_14 -> V_108 [ V_39 ] ) ;
V_36 -> V_33 . V_110 [ V_38 ] += F_53 ( V_14 -> V_110 [ V_38 ] ) ;
V_36 -> V_33 . V_110 [ V_39 ] += F_53 ( V_14 -> V_110 [ V_39 ] ) ;
V_36 -> V_33 . V_94 [ V_38 ] += F_53 ( V_14 -> V_94 [ V_38 ] ) ;
V_36 -> V_33 . V_94 [ V_39 ] += F_53 ( V_14 -> V_94 [ V_39 ] ) ;
V_36 -> V_33 . V_95 += F_53 ( V_14 -> V_95 ) ;
V_36 -> V_33 . V_96 += F_53 ( V_14 -> V_96 ) ;
if ( V_25 -> V_59 ) {
unsigned V_124 ;
for ( V_124 = 0 ; V_124 < V_25 -> V_59 + 1 ; V_124 ++ )
V_36 -> V_33 . V_29 [ V_124 ] += F_53 ( V_14 -> V_29 [ V_124 ] ) ;
}
}
}
static void F_79 ( struct V_24 * V_25 , T_1 V_125 , T_1 V_126 ,
bool V_127 )
{
T_1 V_123 ;
struct V_35 * V_36 ;
struct V_66 * V_14 ;
for ( V_123 = V_125 ; V_123 < V_126 ; V_123 ++ ) {
V_36 = & V_25 -> V_32 [ V_123 ] ;
if ( V_127 )
F_76 ( V_36 , V_25 , V_123 ) ;
F_77 () ;
V_14 = & V_25 -> V_28 [ F_64 () ] [ V_123 ] ;
V_14 -> V_106 [ V_38 ] -= V_36 -> V_33 . V_106 [ V_38 ] ;
V_14 -> V_106 [ V_39 ] -= V_36 -> V_33 . V_106 [ V_39 ] ;
V_14 -> V_107 [ V_38 ] -= V_36 -> V_33 . V_107 [ V_38 ] ;
V_14 -> V_107 [ V_39 ] -= V_36 -> V_33 . V_107 [ V_39 ] ;
V_14 -> V_108 [ V_38 ] -= V_36 -> V_33 . V_108 [ V_38 ] ;
V_14 -> V_108 [ V_39 ] -= V_36 -> V_33 . V_108 [ V_39 ] ;
V_14 -> V_110 [ V_38 ] -= V_36 -> V_33 . V_110 [ V_38 ] ;
V_14 -> V_110 [ V_39 ] -= V_36 -> V_33 . V_110 [ V_39 ] ;
V_14 -> V_94 [ V_38 ] -= V_36 -> V_33 . V_94 [ V_38 ] ;
V_14 -> V_94 [ V_39 ] -= V_36 -> V_33 . V_94 [ V_39 ] ;
V_14 -> V_95 -= V_36 -> V_33 . V_95 ;
V_14 -> V_96 -= V_36 -> V_33 . V_96 ;
F_78 () ;
if ( V_25 -> V_59 ) {
unsigned V_124 ;
for ( V_124 = 0 ; V_124 < V_25 -> V_59 + 1 ; V_124 ++ ) {
F_77 () ;
V_14 = & V_25 -> V_28 [ F_64 () ] [ V_123 ] ;
V_14 -> V_29 [ V_124 ] -= V_36 -> V_33 . V_29 [ V_124 ] ;
F_78 () ;
}
}
}
}
static int F_80 ( struct V_40 * V_41 , int V_75 )
{
struct V_24 * V_25 ;
F_42 ( & V_41 -> V_44 ) ;
V_25 = F_47 ( V_41 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_41 -> V_44 ) ;
return - V_79 ;
}
F_79 ( V_25 , 0 , V_25 -> V_54 , true ) ;
F_46 ( & V_41 -> V_44 ) ;
return 1 ;
}
static unsigned long long F_81 ( struct V_24 * V_25 , unsigned long long V_128 )
{
unsigned long long V_83 ;
unsigned V_129 ;
if ( V_25 -> V_58 & V_91 )
return V_128 ;
V_83 = 0 ;
if ( V_128 )
V_83 = F_67 ( V_128 & 0x3fffff ) ;
if ( V_128 >= 1 << 22 ) {
V_129 = F_67 ( 1 << 22 ) ;
V_83 += ( unsigned long long ) V_129 * ( unsigned long long ) F_67 ( ( V_128 >> 22 ) & 0x3fffff ) ;
}
if ( V_128 >= 1ULL << 44 )
V_83 += ( unsigned long long ) V_129 * ( unsigned long long ) V_129 * ( unsigned long long ) F_67 ( V_128 >> 44 ) ;
return V_83 ;
}
static int F_82 ( struct V_40 * V_41 , int V_75 ,
T_1 V_125 , T_1 V_130 ,
bool V_131 , char * V_83 , unsigned V_84 )
{
unsigned V_86 = 0 ;
struct V_24 * V_25 ;
T_1 V_123 ;
V_47 V_55 , V_56 , V_57 ;
T_1 V_126 ;
struct V_35 * V_36 ;
F_42 ( & V_41 -> V_44 ) ;
V_25 = F_47 ( V_41 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_41 -> V_44 ) ;
return - V_79 ;
}
V_126 = V_125 + V_130 ;
if ( V_126 < V_125 ||
V_126 > V_25 -> V_54 )
V_126 = V_25 -> V_54 ;
if ( V_125 > V_126 )
V_125 = V_126 ;
V_57 = V_25 -> V_57 ;
V_55 = V_25 -> V_55 + ( V_57 * V_125 ) ;
for ( V_123 = V_125 ; V_123 < V_126 ; V_123 ++ , V_55 = V_56 ) {
V_36 = & V_25 -> V_32 [ V_123 ] ;
V_56 = V_55 + V_57 ;
if ( F_44 ( V_56 > V_25 -> V_56 ) )
V_56 = V_25 -> V_56 ;
F_76 ( V_36 , V_25 , V_123 ) ;
F_56 ( L_6 ,
( unsigned long long ) V_55 ,
( unsigned long long ) V_57 ,
V_36 -> V_33 . V_107 [ V_38 ] ,
V_36 -> V_33 . V_108 [ V_38 ] ,
V_36 -> V_33 . V_106 [ V_38 ] ,
F_81 ( V_25 , V_36 -> V_33 . V_110 [ V_38 ] ) ,
V_36 -> V_33 . V_107 [ V_39 ] ,
V_36 -> V_33 . V_108 [ V_39 ] ,
V_36 -> V_33 . V_106 [ V_39 ] ,
F_81 ( V_25 , V_36 -> V_33 . V_110 [ V_39 ] ) ,
F_21 ( V_36 ) ,
F_81 ( V_25 , V_36 -> V_33 . V_95 ) ,
F_81 ( V_25 , V_36 -> V_33 . V_96 ) ,
F_81 ( V_25 , V_36 -> V_33 . V_94 [ V_38 ] ) ,
F_81 ( V_25 , V_36 -> V_33 . V_94 [ V_39 ] ) ) ;
if ( V_25 -> V_59 ) {
unsigned V_124 ;
for ( V_124 = 0 ; V_124 < V_25 -> V_59 + 1 ; V_124 ++ ) {
F_56 ( L_7 , ! V_124 ? L_8 : L_9 , V_36 -> V_33 . V_29 [ V_124 ] ) ;
}
}
F_56 ( L_10 ) ;
if ( F_44 ( V_86 + 1 >= V_84 ) )
goto V_132;
}
if ( V_131 )
F_79 ( V_25 , V_125 , V_126 , false ) ;
V_132:
F_46 ( & V_41 -> V_44 ) ;
return 1 ;
}
static int F_83 ( struct V_40 * V_41 , int V_75 , const char * V_27 )
{
struct V_24 * V_25 ;
const char * V_133 ;
F_42 ( & V_41 -> V_44 ) ;
V_25 = F_47 ( V_41 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_41 -> V_44 ) ;
return - V_79 ;
}
V_133 = F_39 ( V_27 , V_16 ) ;
if ( ! V_133 ) {
F_46 ( & V_41 -> V_44 ) ;
return - V_71 ;
}
F_19 ( V_25 -> V_27 ) ;
V_25 -> V_27 = V_133 ;
F_46 ( & V_41 -> V_44 ) ;
return 0 ;
}
static int F_84 ( const char * V_134 , unsigned * V_59 ,
unsigned long long * * V_60 )
{
const char * V_135 ;
unsigned V_136 ;
unsigned long long V_43 ;
* V_59 = 1 ;
for ( V_135 = V_134 ; * V_135 ; V_135 ++ )
if ( * V_135 == ',' )
( * V_59 ) ++ ;
* V_60 = F_85 ( * V_59 * sizeof( unsigned long long ) , V_16 ) ;
if ( ! * V_60 )
return - V_71 ;
V_136 = 0 ;
V_43 = 0 ;
while ( 1 ) {
unsigned long long V_74 ;
int V_25 ;
char V_137 ;
V_25 = sscanf ( V_134 , L_11 , & V_74 , & V_137 ) ;
if ( ! V_25 || ( V_25 == 2 && V_137 != ',' ) )
return - V_69 ;
if ( V_74 <= V_43 )
return - V_69 ;
V_43 = V_74 ;
( * V_60 ) [ V_136 ] = V_74 ;
if ( V_25 == 1 )
return 0 ;
V_134 = strchr ( V_134 , ',' ) + 1 ;
V_136 ++ ;
}
}
static int F_86 ( struct V_61 * V_62 ,
unsigned V_138 , char * * V_139 ,
char * V_83 , unsigned V_84 )
{
int V_68 ;
int V_75 ;
char V_140 ;
unsigned long long V_55 , V_56 , V_85 , V_57 ;
unsigned V_141 ;
const char * V_26 , * V_27 ;
unsigned V_58 = 0 ;
unsigned V_59 = 0 ;
unsigned long long * V_60 = NULL ;
struct V_142 V_143 , V_144 ;
const char * V_2 ;
unsigned V_145 ;
if ( V_138 < 3 )
goto V_146;
V_143 . V_138 = V_138 ;
V_143 . V_139 = V_139 ;
F_87 ( & V_143 , 1 ) ;
V_2 = F_88 ( & V_143 ) ;
if ( ! strcmp ( V_2 , L_12 ) ) {
V_55 = 0 ;
V_85 = F_89 ( V_62 ) ;
if ( ! V_85 )
V_85 = 1 ;
} else if ( sscanf ( V_2 , L_13 , & V_55 , & V_85 , & V_140 ) != 2 ||
V_55 != ( V_47 ) V_55 || V_85 != ( V_47 ) V_85 )
goto V_146;
V_56 = V_55 + V_85 ;
if ( V_55 >= V_56 )
goto V_146;
V_2 = F_88 ( & V_143 ) ;
if ( sscanf ( V_2 , L_14 , & V_141 , & V_140 ) == 1 ) {
if ( ! V_141 )
return - V_69 ;
V_57 = V_56 - V_55 ;
if ( F_90 ( V_57 , V_141 ) )
V_57 ++ ;
if ( ! V_57 )
V_57 = 1 ;
} else if ( sscanf ( V_2 , L_11 , & V_57 , & V_140 ) != 1 ||
V_57 != ( V_47 ) V_57 || ! V_57 )
goto V_146;
V_144 = V_143 ;
V_2 = F_88 ( & V_143 ) ;
if ( V_2 && sscanf ( V_2 , L_15 , & V_145 , & V_140 ) == 1 ) {
while ( V_145 -- ) {
V_2 = F_88 ( & V_143 ) ;
if ( ! V_2 )
goto V_146;
if ( ! strcasecmp ( V_2 , L_16 ) )
V_58 |= V_91 ;
else if ( ! strncasecmp ( V_2 , L_17 , 10 ) ) {
if ( V_59 )
goto V_146;
if ( ( V_68 = F_84 ( V_2 + 10 , & V_59 , & V_60 ) ) )
goto V_10;
} else
goto V_146;
}
} else {
V_143 = V_144 ;
}
V_26 = L_12 ;
V_27 = L_12 ;
V_2 = F_88 ( & V_143 ) ;
if ( V_2 )
V_26 = V_2 ;
V_2 = F_88 ( & V_143 ) ;
if ( V_2 )
V_27 = V_2 ;
if ( V_143 . V_138 )
goto V_146;
snprintf ( V_83 , V_84 , L_18 , V_77 ) ;
if ( F_91 ( V_83 , V_84 ) ) {
V_68 = 1 ;
goto V_10;
}
V_75 = F_33 ( F_92 ( V_62 ) , V_55 , V_56 , V_57 , V_58 ,
V_59 , V_60 , V_26 , V_27 ,
V_147 , V_148 , V_62 ) ;
if ( V_75 < 0 ) {
V_68 = V_75 ;
goto V_10;
}
snprintf ( V_83 , V_84 , L_18 , V_75 ) ;
V_68 = 1 ;
goto V_10;
V_146:
V_68 = - V_69 ;
V_10:
F_19 ( V_60 ) ;
return V_68 ;
}
static int F_93 ( struct V_61 * V_62 ,
unsigned V_138 , char * * V_139 )
{
int V_75 ;
char V_140 ;
if ( V_138 != 2 )
return - V_69 ;
if ( sscanf ( V_139 [ 1 ] , L_19 , & V_75 , & V_140 ) != 1 || V_75 < 0 )
return - V_69 ;
return F_49 ( F_92 ( V_62 ) , V_75 ) ;
}
static int F_94 ( struct V_61 * V_62 ,
unsigned V_138 , char * * V_139 )
{
int V_75 ;
char V_140 ;
if ( V_138 != 2 )
return - V_69 ;
if ( sscanf ( V_139 [ 1 ] , L_19 , & V_75 , & V_140 ) != 1 || V_75 < 0 )
return - V_69 ;
return F_80 ( F_92 ( V_62 ) , V_75 ) ;
}
static int F_95 ( struct V_61 * V_62 ,
unsigned V_138 , char * * V_139 ,
char * V_83 , unsigned V_84 )
{
int V_68 ;
const char * V_82 = NULL ;
if ( V_138 < 1 || V_138 > 2 )
return - V_69 ;
if ( V_138 > 1 ) {
V_82 = F_39 ( V_139 [ 1 ] , V_16 ) ;
if ( ! V_82 )
return - V_71 ;
}
V_68 = F_55 ( F_92 ( V_62 ) , V_82 , V_83 , V_84 ) ;
F_19 ( V_82 ) ;
return V_68 ;
}
static int F_96 ( struct V_61 * V_62 ,
unsigned V_138 , char * * V_139 , bool V_131 ,
char * V_83 , unsigned V_84 )
{
int V_75 ;
char V_140 ;
unsigned long V_125 = 0 , V_130 = V_149 ;
if ( V_138 != 2 && V_138 != 4 )
return - V_69 ;
if ( sscanf ( V_139 [ 1 ] , L_19 , & V_75 , & V_140 ) != 1 || V_75 < 0 )
return - V_69 ;
if ( V_138 > 3 ) {
if ( strcmp ( V_139 [ 2 ] , L_12 ) &&
sscanf ( V_139 [ 2 ] , L_20 , & V_125 , & V_140 ) != 1 )
return - V_69 ;
if ( strcmp ( V_139 [ 3 ] , L_12 ) &&
sscanf ( V_139 [ 3 ] , L_20 , & V_130 , & V_140 ) != 1 )
return - V_69 ;
}
return F_82 ( F_92 ( V_62 ) , V_75 , V_125 , V_130 , V_131 ,
V_83 , V_84 ) ;
}
static int F_97 ( struct V_61 * V_62 ,
unsigned V_138 , char * * V_139 )
{
int V_75 ;
char V_140 ;
if ( V_138 != 3 )
return - V_69 ;
if ( sscanf ( V_139 [ 1 ] , L_19 , & V_75 , & V_140 ) != 1 || V_75 < 0 )
return - V_69 ;
return F_83 ( F_92 ( V_62 ) , V_75 , V_139 [ 2 ] ) ;
}
int F_98 ( struct V_61 * V_62 , unsigned V_138 , char * * V_139 ,
char * V_83 , unsigned V_84 )
{
int V_68 ;
if ( ! strcasecmp ( V_139 [ 0 ] , L_21 ) )
V_68 = F_86 ( V_62 , V_138 , V_139 , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_139 [ 0 ] , L_22 ) )
V_68 = F_93 ( V_62 , V_138 , V_139 ) ;
else if ( ! strcasecmp ( V_139 [ 0 ] , L_23 ) )
V_68 = F_94 ( V_62 , V_138 , V_139 ) ;
else if ( ! strcasecmp ( V_139 [ 0 ] , L_24 ) )
V_68 = F_95 ( V_62 , V_138 , V_139 , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_139 [ 0 ] , L_25 ) )
V_68 = F_96 ( V_62 , V_138 , V_139 , false , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_139 [ 0 ] , L_26 ) )
V_68 = F_96 ( V_62 , V_138 , V_139 , true , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_139 [ 0 ] , L_27 ) )
V_68 = F_97 ( V_62 , V_138 , V_139 ) ;
else
return 2 ;
if ( V_68 == - V_69 )
F_99 ( L_28 , V_139 [ 0 ] ) ;
return V_68 ;
}
int T_2 F_100 ( void )
{
V_3 = 0 ;
V_81 = 0 ;
return 0 ;
}
void F_101 ( void )
{
if ( V_81 )
F_102 () ;
if ( F_31 ( V_3 ) )
F_11 ( L_29 , V_3 ) ;
}
