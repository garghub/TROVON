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
V_14 = F_13 ( V_1 , V_15 | V_16 , V_13 ) ;
if ( V_14 )
return V_14 ;
F_7 ( V_1 ) ;
return NULL ;
}
static void F_14 ( void * V_17 , T_1 V_1 )
{
if ( ! V_17 )
return;
F_7 ( V_1 ) ;
F_15 ( V_17 ) ;
}
static void F_16 ( struct V_18 * V_19 )
{
int V_20 ;
struct V_21 * V_22 = F_17 ( V_19 , struct V_21 , V_18 ) ;
F_18 ( V_22 -> V_23 ) ;
F_18 ( V_22 -> V_24 ) ;
F_18 ( V_22 -> V_25 ) ;
F_19 (cpu) {
F_14 ( V_22 -> V_26 [ V_20 ] [ 0 ] . V_27 , V_22 -> V_28 ) ;
F_14 ( V_22 -> V_26 [ V_20 ] , V_22 -> V_29 ) ;
}
F_14 ( V_22 -> V_30 [ 0 ] . V_31 . V_27 , V_22 -> V_28 ) ;
F_14 ( V_22 , V_22 -> V_32 ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
return F_21 ( & V_34 -> V_35 [ V_36 ] ) +
F_21 ( & V_34 -> V_35 [ V_37 ] ) ;
}
void F_22 ( struct V_38 * V_39 )
{
int V_20 ;
struct V_40 * V_41 ;
F_23 ( & V_39 -> V_42 ) ;
F_24 ( & V_39 -> V_43 ) ;
V_39 -> V_41 = F_25 ( struct V_40 ) ;
F_19 (cpu) {
V_41 = F_26 ( V_39 -> V_41 , V_20 ) ;
V_41 -> V_44 = ( V_45 ) V_46 ;
V_41 -> V_47 = V_48 ;
}
}
void F_27 ( struct V_38 * V_39 )
{
T_1 V_49 ;
struct V_21 * V_22 ;
struct V_33 * V_34 ;
while ( ! F_28 ( & V_39 -> V_43 ) ) {
V_22 = F_17 ( V_39 -> V_43 . V_50 , struct V_21 , V_51 ) ;
F_29 ( & V_22 -> V_51 ) ;
for ( V_49 = 0 ; V_49 < V_22 -> V_52 ; V_49 ++ ) {
V_34 = & V_22 -> V_30 [ V_49 ] ;
if ( F_30 ( F_20 ( V_34 ) ) ) {
F_11 ( L_2
L_3 ,
( unsigned long ) V_49 ,
( unsigned long long ) V_22 -> V_53 ,
( unsigned long long ) V_22 -> V_54 ,
( unsigned long long ) V_22 -> V_55 ,
F_21 ( & V_34 -> V_35 [ V_36 ] ) ,
F_21 ( & V_34 -> V_35 [ V_37 ] ) ) ;
}
}
F_16 ( & V_22 -> V_18 ) ;
}
F_31 ( V_39 -> V_41 ) ;
}
static int F_32 ( struct V_38 * V_39 , V_45 V_53 , V_45 V_54 ,
V_45 V_55 , unsigned V_56 ,
unsigned V_57 ,
unsigned long long * V_23 ,
const char * V_24 , const char * V_25 ,
void (* F_33)( struct V_58 * ) ,
void (* F_34)( struct V_58 * ) ,
struct V_58 * V_59 )
{
struct V_60 * V_61 ;
struct V_21 * V_22 , * V_62 ;
V_45 V_52 ;
T_1 V_49 ;
T_1 V_32 ;
T_1 V_29 ;
T_1 V_28 ;
struct V_63 * V_14 ;
int V_20 ;
int V_64 ;
int V_65 ;
if ( V_54 < V_53 || ! V_55 )
return - V_66 ;
V_52 = V_54 - V_53 ;
if ( F_35 ( V_52 , V_55 ) )
V_52 ++ ;
if ( V_52 != ( T_1 ) V_52 || ! ( T_1 ) ( V_52 + 1 ) )
return - V_67 ;
V_32 = sizeof( struct V_21 ) + ( T_1 ) V_52 * sizeof( struct V_33 ) ;
if ( ( V_32 - sizeof( struct V_21 ) ) / sizeof( struct V_33 ) != V_52 )
return - V_67 ;
V_29 = ( T_1 ) V_52 * sizeof( struct V_63 ) ;
if ( V_29 / sizeof( struct V_63 ) != V_52 )
return - V_67 ;
V_28 = ( V_57 + 1 ) * ( T_1 ) V_52 * sizeof( unsigned long long ) ;
if ( V_28 / ( V_57 + 1 ) != ( T_1 ) V_52 * sizeof( unsigned long long ) )
return - V_67 ;
if ( ! F_3 ( V_32 + V_28 +
F_36 () * ( V_29 + V_28 ) ) )
return - V_68 ;
V_22 = F_12 ( V_32 , V_69 ) ;
if ( ! V_22 )
return - V_68 ;
V_22 -> V_56 = V_56 ;
V_22 -> V_52 = V_52 ;
V_22 -> V_53 = V_53 ;
V_22 -> V_54 = V_54 ;
V_22 -> V_55 = V_55 ;
V_22 -> V_32 = V_32 ;
V_22 -> V_29 = V_29 ;
V_22 -> V_28 = V_28 ;
V_22 -> V_57 = V_57 ;
V_22 -> V_23 = F_37 ( V_23 ,
V_22 -> V_57 * sizeof( unsigned long long ) , V_15 ) ;
if ( ! V_22 -> V_23 ) {
V_65 = - V_68 ;
goto V_70;
}
V_22 -> V_24 = F_38 ( V_24 , V_15 ) ;
if ( ! V_22 -> V_24 ) {
V_65 = - V_68 ;
goto V_70;
}
V_22 -> V_25 = F_38 ( V_25 , V_15 ) ;
if ( ! V_22 -> V_25 ) {
V_65 = - V_68 ;
goto V_70;
}
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
F_39 ( & V_22 -> V_30 [ V_49 ] . V_35 [ V_36 ] , 0 ) ;
F_39 ( & V_22 -> V_30 [ V_49 ] . V_35 [ V_37 ] , 0 ) ;
}
if ( V_22 -> V_57 ) {
unsigned long long * V_71 ;
V_71 = F_12 ( V_22 -> V_28 , V_69 ) ;
if ( ! V_71 ) {
V_65 = - V_68 ;
goto V_70;
}
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_22 -> V_30 [ V_49 ] . V_31 . V_27 = V_71 ;
V_71 += V_22 -> V_57 + 1 ;
}
}
F_19 (cpu) {
V_14 = F_12 ( V_29 , F_40 ( V_20 ) ) ;
if ( ! V_14 ) {
V_65 = - V_68 ;
goto V_70;
}
V_22 -> V_26 [ V_20 ] = V_14 ;
if ( V_22 -> V_57 ) {
unsigned long long * V_71 ;
V_71 = F_12 ( V_22 -> V_28 , F_40 ( V_20 ) ) ;
if ( ! V_71 ) {
V_65 = - V_68 ;
goto V_70;
}
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ ) {
V_14 [ V_49 ] . V_27 = V_71 ;
V_71 += V_22 -> V_57 + 1 ;
}
}
}
F_33 ( V_59 ) ;
F_41 ( & V_39 -> V_42 ) ;
V_22 -> V_72 = 0 ;
F_42 (l, &stats->list) {
V_62 = F_17 ( V_61 , struct V_21 , V_51 ) ;
if ( F_30 ( V_62 -> V_72 < V_22 -> V_72 ) ) {
V_65 = - V_66 ;
goto V_73;
}
if ( V_62 -> V_72 > V_22 -> V_72 )
break;
if ( F_43 ( V_22 -> V_72 == V_74 ) ) {
V_65 = - V_75 ;
goto V_73;
}
V_22 -> V_72 ++ ;
}
V_64 = V_22 -> V_72 ;
F_44 ( & V_22 -> V_51 , V_61 ) ;
F_45 ( & V_39 -> V_42 ) ;
F_34 ( V_59 ) ;
return V_64 ;
V_73:
F_45 ( & V_39 -> V_42 ) ;
F_34 ( V_59 ) ;
V_70:
F_16 ( & V_22 -> V_18 ) ;
return V_65 ;
}
static struct V_21 * F_46 ( struct V_38 * V_39 , int V_72 )
{
struct V_21 * V_22 ;
F_47 (s, &stats->list, list_entry) {
if ( V_22 -> V_72 > V_72 )
break;
if ( V_22 -> V_72 == V_72 )
return V_22 ;
}
return NULL ;
}
static int F_48 ( struct V_38 * V_39 , int V_72 )
{
struct V_21 * V_22 ;
int V_20 ;
F_41 ( & V_39 -> V_42 ) ;
V_22 = F_46 ( V_39 , V_72 ) ;
if ( ! V_22 ) {
F_45 ( & V_39 -> V_42 ) ;
return - V_76 ;
}
F_49 ( & V_22 -> V_51 ) ;
F_45 ( & V_39 -> V_42 ) ;
F_19 (cpu)
if ( F_50 ( V_22 -> V_26 ) ||
F_50 ( V_22 -> V_26 [ V_20 ] [ 0 ] . V_27 ) )
goto V_77;
if ( F_50 ( V_22 ) ||
F_50 ( V_22 -> V_30 [ 0 ] . V_31 . V_27 ) ) {
V_77:
F_51 () ;
F_16 ( & V_22 -> V_18 ) ;
} else {
F_52 ( V_78 ) = 1 ;
F_53 ( & V_22 -> V_18 , F_16 ) ;
}
return 0 ;
}
static int F_54 ( struct V_38 * V_39 , const char * V_79 ,
char * V_80 , unsigned V_81 )
{
struct V_21 * V_22 ;
V_45 V_82 ;
unsigned V_83 = 0 ;
F_41 ( & V_39 -> V_42 ) ;
F_47 (s, &stats->list, list_entry) {
if ( ! V_79 || ! strcmp ( V_79 , V_22 -> V_24 ) ) {
V_82 = V_22 -> V_54 - V_22 -> V_53 ;
F_55 ( L_4 , V_22 -> V_72 ,
( unsigned long long ) V_22 -> V_53 ,
( unsigned long long ) V_82 ,
( unsigned long long ) V_22 -> V_55 ,
V_22 -> V_24 ,
V_22 -> V_25 ) ;
if ( V_22 -> V_56 & V_84 )
F_55 ( L_5 ) ;
if ( V_22 -> V_57 ) {
unsigned V_85 ;
F_55 ( L_6 ) ;
for ( V_85 = 0 ; V_85 < V_22 -> V_57 ; V_85 ++ ) {
if ( V_85 )
F_55 ( L_7 ) ;
F_55 ( L_8 , V_22 -> V_23 [ V_85 ] ) ;
}
}
F_55 ( L_9 ) ;
}
}
F_45 ( & V_39 -> V_42 ) ;
return 1 ;
}
static void F_56 ( struct V_21 * V_22 , struct V_33 * V_34 ,
struct V_63 * V_14 )
{
unsigned long long V_86 , V_87 ;
unsigned V_88 , V_89 ;
if ( F_57 ( ! ( V_22 -> V_56 & V_84 ) ) )
V_86 = V_90 ;
else
V_86 = F_58 ( F_59 () ) ;
V_87 = V_86 - V_34 -> V_91 ;
if ( ! V_87 )
return;
V_88 = ( unsigned ) F_21 ( & V_34 -> V_35 [ V_36 ] ) ;
V_89 = ( unsigned ) F_21 ( & V_34 -> V_35 [ V_37 ] ) ;
if ( V_88 )
V_14 -> V_92 [ V_36 ] += V_87 ;
if ( V_89 )
V_14 -> V_92 [ V_37 ] += V_87 ;
if ( V_88 + V_89 ) {
V_14 -> V_93 += V_87 ;
V_14 -> V_94 += ( V_88 + V_89 ) * V_87 ;
}
V_34 -> V_91 = V_86 ;
}
static void F_60 ( struct V_21 * V_22 , T_1 V_95 ,
int V_96 , V_45 V_82 ,
struct V_97 * V_98 , bool V_54 ,
unsigned long V_99 )
{
struct V_33 * V_34 = & V_22 -> V_30 [ V_95 ] ;
struct V_63 * V_14 ;
#if V_100 == 32
unsigned long V_12 ;
F_61 ( V_12 ) ;
#else
F_62 () ;
#endif
V_14 = & V_22 -> V_26 [ F_63 () ] [ V_95 ] ;
if ( ! V_54 ) {
F_56 ( V_22 , V_34 , V_14 ) ;
F_64 ( & V_34 -> V_35 [ V_96 ] ) ;
} else {
unsigned long long V_101 ;
F_56 ( V_22 , V_34 , V_14 ) ;
F_65 ( & V_34 -> V_35 [ V_96 ] ) ;
V_14 -> V_102 [ V_96 ] += V_82 ;
V_14 -> V_103 [ V_96 ] += 1 ;
V_14 -> V_104 [ V_96 ] += V_98 -> V_105 ;
if ( ! ( V_22 -> V_56 & V_84 ) ) {
V_14 -> V_106 [ V_96 ] += V_99 ;
V_101 = F_66 ( V_99 ) ;
} else {
V_14 -> V_106 [ V_96 ] += V_98 -> V_107 ;
V_101 = V_98 -> V_107 ;
}
if ( V_22 -> V_57 ) {
unsigned V_108 = 0 , V_71 = V_22 -> V_57 + 1 ;
while ( V_108 + 1 < V_71 ) {
unsigned V_109 = ( V_108 + V_71 ) / 2 ;
if ( V_22 -> V_23 [ V_109 - 1 ] > V_101 ) {
V_71 = V_109 ;
} else {
V_108 = V_109 ;
}
}
V_14 -> V_27 [ V_108 ] ++ ;
}
}
#if V_100 == 32
F_67 ( V_12 ) ;
#else
F_68 () ;
#endif
}
static void F_69 ( struct V_21 * V_22 , int V_110 ,
V_45 V_111 , V_45 V_112 ,
bool V_54 , unsigned long V_99 ,
struct V_97 * V_98 )
{
V_45 V_113 , V_114 , V_115 , V_116 ;
T_1 V_95 ;
if ( V_112 <= V_22 -> V_53 || V_111 >= V_22 -> V_54 )
return;
if ( F_43 ( V_111 < V_22 -> V_53 ) ) {
V_113 = 0 ;
V_115 = V_112 - V_22 -> V_53 ;
} else {
V_113 = V_111 - V_22 -> V_53 ;
V_115 = V_112 - V_111 ;
}
if ( F_43 ( V_112 > V_22 -> V_54 ) )
V_115 -= ( V_112 - V_22 -> V_54 ) ;
V_114 = F_35 ( V_113 , V_22 -> V_55 ) ;
V_95 = V_113 ;
do {
if ( F_9 ( V_95 >= V_22 -> V_52 ) ) {
F_11 ( L_10 , V_22 -> V_72 ) ;
return;
}
V_116 = V_115 ;
if ( V_116 > V_22 -> V_55 - V_114 )
V_116 = V_22 -> V_55 - V_114 ;
F_60 ( V_22 , V_95 , V_110 , V_116 ,
V_98 , V_54 , V_99 ) ;
V_115 -= V_116 ;
V_95 ++ ;
V_114 = 0 ;
} while ( F_43 ( V_115 != 0 ) );
}
void F_70 ( struct V_38 * V_39 , unsigned long V_110 ,
V_45 V_111 , unsigned V_117 , bool V_54 ,
unsigned long V_99 ,
struct V_97 * V_98 )
{
struct V_21 * V_22 ;
V_45 V_112 ;
struct V_40 * V_41 ;
bool V_118 ;
if ( F_43 ( ! V_117 ) )
return;
V_112 = V_111 + V_117 ;
if ( ! V_54 ) {
V_41 = F_71 ( V_39 -> V_41 ) ;
V_98 -> V_105 =
( V_111 == ( F_52 ( V_41 -> V_44 ) &&
( ( V_110 == V_37 ) ==
( F_52 ( V_41 -> V_47 ) == V_37 ) )
) ) ;
F_52 ( V_41 -> V_44 ) = V_112 ;
F_52 ( V_41 -> V_47 ) = V_110 ;
}
F_72 () ;
V_118 = false ;
F_73 (s, &stats->list, list_entry) {
if ( V_22 -> V_56 & V_84 && ! V_118 ) {
if ( ! V_54 )
V_98 -> V_107 = F_58 ( F_59 () ) ;
else
V_98 -> V_107 = F_58 ( F_59 () ) - V_98 -> V_107 ;
V_118 = true ;
}
F_69 ( V_22 , V_110 , V_111 , V_112 , V_54 , V_99 , V_98 ) ;
}
F_74 () ;
}
static void F_75 ( struct V_33 * V_34 ,
struct V_21 * V_22 , T_1 V_119 )
{
int V_20 ;
struct V_63 * V_14 ;
F_76 () ;
V_14 = & V_22 -> V_26 [ F_63 () ] [ V_119 ] ;
F_56 ( V_22 , V_34 , V_14 ) ;
F_77 () ;
V_34 -> V_31 . V_102 [ V_36 ] = 0 ;
V_34 -> V_31 . V_102 [ V_37 ] = 0 ;
V_34 -> V_31 . V_103 [ V_36 ] = 0 ;
V_34 -> V_31 . V_103 [ V_37 ] = 0 ;
V_34 -> V_31 . V_104 [ V_36 ] = 0 ;
V_34 -> V_31 . V_104 [ V_37 ] = 0 ;
V_34 -> V_31 . V_106 [ V_36 ] = 0 ;
V_34 -> V_31 . V_106 [ V_37 ] = 0 ;
V_34 -> V_31 . V_92 [ V_36 ] = 0 ;
V_34 -> V_31 . V_92 [ V_37 ] = 0 ;
V_34 -> V_31 . V_93 = 0 ;
V_34 -> V_31 . V_94 = 0 ;
if ( V_22 -> V_57 )
memset ( V_34 -> V_31 . V_27 , 0 , ( V_22 -> V_57 + 1 ) * sizeof( unsigned long long ) ) ;
F_19 (cpu) {
V_14 = & V_22 -> V_26 [ V_20 ] [ V_119 ] ;
V_34 -> V_31 . V_102 [ V_36 ] += F_52 ( V_14 -> V_102 [ V_36 ] ) ;
V_34 -> V_31 . V_102 [ V_37 ] += F_52 ( V_14 -> V_102 [ V_37 ] ) ;
V_34 -> V_31 . V_103 [ V_36 ] += F_52 ( V_14 -> V_103 [ V_36 ] ) ;
V_34 -> V_31 . V_103 [ V_37 ] += F_52 ( V_14 -> V_103 [ V_37 ] ) ;
V_34 -> V_31 . V_104 [ V_36 ] += F_52 ( V_14 -> V_104 [ V_36 ] ) ;
V_34 -> V_31 . V_104 [ V_37 ] += F_52 ( V_14 -> V_104 [ V_37 ] ) ;
V_34 -> V_31 . V_106 [ V_36 ] += F_52 ( V_14 -> V_106 [ V_36 ] ) ;
V_34 -> V_31 . V_106 [ V_37 ] += F_52 ( V_14 -> V_106 [ V_37 ] ) ;
V_34 -> V_31 . V_92 [ V_36 ] += F_52 ( V_14 -> V_92 [ V_36 ] ) ;
V_34 -> V_31 . V_92 [ V_37 ] += F_52 ( V_14 -> V_92 [ V_37 ] ) ;
V_34 -> V_31 . V_93 += F_52 ( V_14 -> V_93 ) ;
V_34 -> V_31 . V_94 += F_52 ( V_14 -> V_94 ) ;
if ( V_22 -> V_57 ) {
unsigned V_85 ;
for ( V_85 = 0 ; V_85 < V_22 -> V_57 + 1 ; V_85 ++ )
V_34 -> V_31 . V_27 [ V_85 ] += F_52 ( V_14 -> V_27 [ V_85 ] ) ;
}
}
}
static void F_78 ( struct V_21 * V_22 , T_1 V_120 , T_1 V_121 ,
bool V_122 )
{
T_1 V_119 ;
struct V_33 * V_34 ;
struct V_63 * V_14 ;
for ( V_119 = V_120 ; V_119 < V_121 ; V_119 ++ ) {
V_34 = & V_22 -> V_30 [ V_119 ] ;
if ( V_122 )
F_75 ( V_34 , V_22 , V_119 ) ;
F_76 () ;
V_14 = & V_22 -> V_26 [ F_63 () ] [ V_119 ] ;
V_14 -> V_102 [ V_36 ] -= V_34 -> V_31 . V_102 [ V_36 ] ;
V_14 -> V_102 [ V_37 ] -= V_34 -> V_31 . V_102 [ V_37 ] ;
V_14 -> V_103 [ V_36 ] -= V_34 -> V_31 . V_103 [ V_36 ] ;
V_14 -> V_103 [ V_37 ] -= V_34 -> V_31 . V_103 [ V_37 ] ;
V_14 -> V_104 [ V_36 ] -= V_34 -> V_31 . V_104 [ V_36 ] ;
V_14 -> V_104 [ V_37 ] -= V_34 -> V_31 . V_104 [ V_37 ] ;
V_14 -> V_106 [ V_36 ] -= V_34 -> V_31 . V_106 [ V_36 ] ;
V_14 -> V_106 [ V_37 ] -= V_34 -> V_31 . V_106 [ V_37 ] ;
V_14 -> V_92 [ V_36 ] -= V_34 -> V_31 . V_92 [ V_36 ] ;
V_14 -> V_92 [ V_37 ] -= V_34 -> V_31 . V_92 [ V_37 ] ;
V_14 -> V_93 -= V_34 -> V_31 . V_93 ;
V_14 -> V_94 -= V_34 -> V_31 . V_94 ;
F_77 () ;
if ( V_22 -> V_57 ) {
unsigned V_85 ;
for ( V_85 = 0 ; V_85 < V_22 -> V_57 + 1 ; V_85 ++ ) {
F_76 () ;
V_14 = & V_22 -> V_26 [ F_63 () ] [ V_119 ] ;
V_14 -> V_27 [ V_85 ] -= V_34 -> V_31 . V_27 [ V_85 ] ;
F_77 () ;
}
}
}
}
static int F_79 ( struct V_38 * V_39 , int V_72 )
{
struct V_21 * V_22 ;
F_41 ( & V_39 -> V_42 ) ;
V_22 = F_46 ( V_39 , V_72 ) ;
if ( ! V_22 ) {
F_45 ( & V_39 -> V_42 ) ;
return - V_76 ;
}
F_78 ( V_22 , 0 , V_22 -> V_52 , true ) ;
F_45 ( & V_39 -> V_42 ) ;
return 1 ;
}
static unsigned long long F_80 ( struct V_21 * V_22 , unsigned long long V_123 )
{
unsigned long long V_80 ;
unsigned V_124 ;
if ( V_22 -> V_56 & V_84 )
return V_123 ;
V_80 = 0 ;
if ( V_123 )
V_80 = F_66 ( V_123 & 0x3fffff ) ;
if ( V_123 >= 1 << 22 ) {
V_124 = F_66 ( 1 << 22 ) ;
V_80 += ( unsigned long long ) V_124 * ( unsigned long long ) F_66 ( ( V_123 >> 22 ) & 0x3fffff ) ;
}
if ( V_123 >= 1ULL << 44 )
V_80 += ( unsigned long long ) V_124 * ( unsigned long long ) V_124 * ( unsigned long long ) F_66 ( V_123 >> 44 ) ;
return V_80 ;
}
static int F_81 ( struct V_38 * V_39 , int V_72 ,
T_1 V_120 , T_1 V_125 ,
bool V_126 , char * V_80 , unsigned V_81 )
{
unsigned V_83 = 0 ;
struct V_21 * V_22 ;
T_1 V_119 ;
V_45 V_53 , V_54 , V_55 ;
T_1 V_121 ;
struct V_33 * V_34 ;
F_41 ( & V_39 -> V_42 ) ;
V_22 = F_46 ( V_39 , V_72 ) ;
if ( ! V_22 ) {
F_45 ( & V_39 -> V_42 ) ;
return - V_76 ;
}
V_121 = V_120 + V_125 ;
if ( V_121 < V_120 ||
V_121 > V_22 -> V_52 )
V_121 = V_22 -> V_52 ;
if ( V_120 > V_121 )
V_120 = V_121 ;
V_55 = V_22 -> V_55 ;
V_53 = V_22 -> V_53 + ( V_55 * V_120 ) ;
for ( V_119 = V_120 ; V_119 < V_121 ; V_119 ++ , V_53 = V_54 ) {
V_34 = & V_22 -> V_30 [ V_119 ] ;
V_54 = V_53 + V_55 ;
if ( F_43 ( V_54 > V_22 -> V_54 ) )
V_54 = V_22 -> V_54 ;
F_75 ( V_34 , V_22 , V_119 ) ;
F_55 ( L_11 ,
( unsigned long long ) V_53 ,
( unsigned long long ) V_55 ,
V_34 -> V_31 . V_103 [ V_36 ] ,
V_34 -> V_31 . V_104 [ V_36 ] ,
V_34 -> V_31 . V_102 [ V_36 ] ,
F_80 ( V_22 , V_34 -> V_31 . V_106 [ V_36 ] ) ,
V_34 -> V_31 . V_103 [ V_37 ] ,
V_34 -> V_31 . V_104 [ V_37 ] ,
V_34 -> V_31 . V_102 [ V_37 ] ,
F_80 ( V_22 , V_34 -> V_31 . V_106 [ V_37 ] ) ,
F_20 ( V_34 ) ,
F_80 ( V_22 , V_34 -> V_31 . V_93 ) ,
F_80 ( V_22 , V_34 -> V_31 . V_94 ) ,
F_80 ( V_22 , V_34 -> V_31 . V_92 [ V_36 ] ) ,
F_80 ( V_22 , V_34 -> V_31 . V_92 [ V_37 ] ) ) ;
if ( V_22 -> V_57 ) {
unsigned V_85 ;
for ( V_85 = 0 ; V_85 < V_22 -> V_57 + 1 ; V_85 ++ ) {
F_55 ( L_12 , ! V_85 ? L_13 : L_14 , V_34 -> V_31 . V_27 [ V_85 ] ) ;
}
}
F_55 ( L_9 ) ;
if ( F_43 ( V_83 + 1 >= V_81 ) )
goto V_127;
}
if ( V_126 )
F_78 ( V_22 , V_120 , V_121 , false ) ;
V_127:
F_45 ( & V_39 -> V_42 ) ;
return 1 ;
}
static int F_82 ( struct V_38 * V_39 , int V_72 , const char * V_25 )
{
struct V_21 * V_22 ;
const char * V_128 ;
F_41 ( & V_39 -> V_42 ) ;
V_22 = F_46 ( V_39 , V_72 ) ;
if ( ! V_22 ) {
F_45 ( & V_39 -> V_42 ) ;
return - V_76 ;
}
V_128 = F_38 ( V_25 , V_15 ) ;
if ( ! V_128 ) {
F_45 ( & V_39 -> V_42 ) ;
return - V_68 ;
}
F_18 ( V_22 -> V_25 ) ;
V_22 -> V_25 = V_128 ;
F_45 ( & V_39 -> V_42 ) ;
return 0 ;
}
static int F_83 ( const char * V_129 , unsigned * V_57 ,
unsigned long long * * V_23 )
{
const char * V_130 ;
unsigned V_131 ;
unsigned long long V_41 ;
* V_57 = 1 ;
for ( V_130 = V_129 ; * V_130 ; V_130 ++ )
if ( * V_130 == ',' )
( * V_57 ) ++ ;
* V_23 = F_84 ( * V_57 * sizeof( unsigned long long ) , V_15 ) ;
if ( ! * V_23 )
return - V_68 ;
V_131 = 0 ;
V_41 = 0 ;
while ( 1 ) {
unsigned long long V_71 ;
int V_22 ;
char V_132 ;
V_22 = sscanf ( V_129 , L_15 , & V_71 , & V_132 ) ;
if ( ! V_22 || ( V_22 == 2 && V_132 != ',' ) )
return - V_66 ;
if ( V_71 <= V_41 )
return - V_66 ;
V_41 = V_71 ;
( * V_23 ) [ V_131 ] = V_71 ;
if ( V_22 == 1 )
return 0 ;
V_129 = strchr ( V_129 , ',' ) + 1 ;
V_131 ++ ;
}
}
static int F_85 ( struct V_58 * V_59 ,
unsigned V_133 , char * * V_134 ,
char * V_80 , unsigned V_81 )
{
int V_65 ;
int V_72 ;
char V_135 ;
unsigned long long V_53 , V_54 , V_82 , V_55 ;
unsigned V_136 ;
const char * V_24 , * V_25 ;
unsigned V_56 = 0 ;
unsigned V_57 = 0 ;
unsigned long long * V_23 = NULL ;
struct V_137 V_138 , V_139 ;
const char * V_2 ;
unsigned V_140 ;
if ( V_133 < 3 )
goto V_141;
V_138 . V_133 = V_133 ;
V_138 . V_134 = V_134 ;
F_86 ( & V_138 , 1 ) ;
V_2 = F_87 ( & V_138 ) ;
if ( ! strcmp ( V_2 , L_16 ) ) {
V_53 = 0 ;
V_82 = F_88 ( V_59 ) ;
if ( ! V_82 )
V_82 = 1 ;
} else if ( sscanf ( V_2 , L_17 , & V_53 , & V_82 , & V_135 ) != 2 ||
V_53 != ( V_45 ) V_53 || V_82 != ( V_45 ) V_82 )
goto V_141;
V_54 = V_53 + V_82 ;
if ( V_53 >= V_54 )
goto V_141;
V_2 = F_87 ( & V_138 ) ;
if ( sscanf ( V_2 , L_18 , & V_136 , & V_135 ) == 1 ) {
if ( ! V_136 )
return - V_66 ;
V_55 = V_54 - V_53 ;
if ( F_89 ( V_55 , V_136 ) )
V_55 ++ ;
if ( ! V_55 )
V_55 = 1 ;
} else if ( sscanf ( V_2 , L_15 , & V_55 , & V_135 ) != 1 ||
V_55 != ( V_45 ) V_55 || ! V_55 )
goto V_141;
V_139 = V_138 ;
V_2 = F_87 ( & V_138 ) ;
if ( V_2 && sscanf ( V_2 , L_19 , & V_140 , & V_135 ) == 1 ) {
while ( V_140 -- ) {
V_2 = F_87 ( & V_138 ) ;
if ( ! V_2 )
goto V_141;
if ( ! strcasecmp ( V_2 , L_20 ) )
V_56 |= V_84 ;
else if ( ! strncasecmp ( V_2 , L_21 , 10 ) ) {
if ( V_57 )
goto V_141;
if ( ( V_65 = F_83 ( V_2 + 10 , & V_57 , & V_23 ) ) )
goto V_10;
} else
goto V_141;
}
} else {
V_138 = V_139 ;
}
V_24 = L_16 ;
V_25 = L_16 ;
V_2 = F_87 ( & V_138 ) ;
if ( V_2 )
V_24 = V_2 ;
V_2 = F_87 ( & V_138 ) ;
if ( V_2 )
V_25 = V_2 ;
if ( V_138 . V_133 )
goto V_141;
snprintf ( V_80 , V_81 , L_22 , V_74 ) ;
if ( F_90 ( V_80 , V_81 ) ) {
V_65 = 1 ;
goto V_10;
}
V_72 = F_32 ( F_91 ( V_59 ) , V_53 , V_54 , V_55 , V_56 ,
V_57 , V_23 , V_24 , V_25 ,
V_142 , V_143 , V_59 ) ;
if ( V_72 < 0 ) {
V_65 = V_72 ;
goto V_10;
}
snprintf ( V_80 , V_81 , L_22 , V_72 ) ;
V_65 = 1 ;
goto V_10;
V_141:
V_65 = - V_66 ;
V_10:
F_18 ( V_23 ) ;
return V_65 ;
}
static int F_92 ( struct V_58 * V_59 ,
unsigned V_133 , char * * V_134 )
{
int V_72 ;
char V_135 ;
if ( V_133 != 2 )
return - V_66 ;
if ( sscanf ( V_134 [ 1 ] , L_23 , & V_72 , & V_135 ) != 1 || V_72 < 0 )
return - V_66 ;
return F_48 ( F_91 ( V_59 ) , V_72 ) ;
}
static int F_93 ( struct V_58 * V_59 ,
unsigned V_133 , char * * V_134 )
{
int V_72 ;
char V_135 ;
if ( V_133 != 2 )
return - V_66 ;
if ( sscanf ( V_134 [ 1 ] , L_23 , & V_72 , & V_135 ) != 1 || V_72 < 0 )
return - V_66 ;
return F_79 ( F_91 ( V_59 ) , V_72 ) ;
}
static int F_94 ( struct V_58 * V_59 ,
unsigned V_133 , char * * V_134 ,
char * V_80 , unsigned V_81 )
{
int V_65 ;
const char * V_79 = NULL ;
if ( V_133 < 1 || V_133 > 2 )
return - V_66 ;
if ( V_133 > 1 ) {
V_79 = F_38 ( V_134 [ 1 ] , V_15 ) ;
if ( ! V_79 )
return - V_68 ;
}
V_65 = F_54 ( F_91 ( V_59 ) , V_79 , V_80 , V_81 ) ;
F_18 ( V_79 ) ;
return V_65 ;
}
static int F_95 ( struct V_58 * V_59 ,
unsigned V_133 , char * * V_134 , bool V_126 ,
char * V_80 , unsigned V_81 )
{
int V_72 ;
char V_135 ;
unsigned long V_120 = 0 , V_125 = V_144 ;
if ( V_133 != 2 && V_133 != 4 )
return - V_66 ;
if ( sscanf ( V_134 [ 1 ] , L_23 , & V_72 , & V_135 ) != 1 || V_72 < 0 )
return - V_66 ;
if ( V_133 > 3 ) {
if ( strcmp ( V_134 [ 2 ] , L_16 ) &&
sscanf ( V_134 [ 2 ] , L_24 , & V_120 , & V_135 ) != 1 )
return - V_66 ;
if ( strcmp ( V_134 [ 3 ] , L_16 ) &&
sscanf ( V_134 [ 3 ] , L_24 , & V_125 , & V_135 ) != 1 )
return - V_66 ;
}
return F_81 ( F_91 ( V_59 ) , V_72 , V_120 , V_125 , V_126 ,
V_80 , V_81 ) ;
}
static int F_96 ( struct V_58 * V_59 ,
unsigned V_133 , char * * V_134 )
{
int V_72 ;
char V_135 ;
if ( V_133 != 3 )
return - V_66 ;
if ( sscanf ( V_134 [ 1 ] , L_23 , & V_72 , & V_135 ) != 1 || V_72 < 0 )
return - V_66 ;
return F_82 ( F_91 ( V_59 ) , V_72 , V_134 [ 2 ] ) ;
}
int F_97 ( struct V_58 * V_59 , unsigned V_133 , char * * V_134 ,
char * V_80 , unsigned V_81 )
{
int V_65 ;
if ( ! strcasecmp ( V_134 [ 0 ] , L_25 ) )
V_65 = F_85 ( V_59 , V_133 , V_134 , V_80 , V_81 ) ;
else if ( ! strcasecmp ( V_134 [ 0 ] , L_26 ) )
V_65 = F_92 ( V_59 , V_133 , V_134 ) ;
else if ( ! strcasecmp ( V_134 [ 0 ] , L_27 ) )
V_65 = F_93 ( V_59 , V_133 , V_134 ) ;
else if ( ! strcasecmp ( V_134 [ 0 ] , L_28 ) )
V_65 = F_94 ( V_59 , V_133 , V_134 , V_80 , V_81 ) ;
else if ( ! strcasecmp ( V_134 [ 0 ] , L_29 ) )
V_65 = F_95 ( V_59 , V_133 , V_134 , false , V_80 , V_81 ) ;
else if ( ! strcasecmp ( V_134 [ 0 ] , L_30 ) )
V_65 = F_95 ( V_59 , V_133 , V_134 , true , V_80 , V_81 ) ;
else if ( ! strcasecmp ( V_134 [ 0 ] , L_31 ) )
V_65 = F_96 ( V_59 , V_133 , V_134 ) ;
else
return 2 ;
if ( V_65 == - V_66 )
F_98 ( L_32 , V_134 [ 0 ] ) ;
return V_65 ;
}
int T_2 F_99 ( void )
{
V_3 = 0 ;
V_78 = 0 ;
return 0 ;
}
void F_100 ( void )
{
if ( V_78 )
F_101 () ;
if ( F_30 ( V_3 ) )
F_11 ( L_33 , V_3 ) ;
}
