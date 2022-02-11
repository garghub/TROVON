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
F_19 ( V_25 -> V_28 ) ;
F_20 (cpu) {
F_15 ( V_25 -> V_29 [ V_23 ] [ 0 ] . V_30 , V_25 -> V_31 ) ;
F_15 ( V_25 -> V_29 [ V_23 ] , V_25 -> V_32 ) ;
}
F_15 ( V_25 -> V_33 [ 0 ] . V_34 . V_30 , V_25 -> V_31 ) ;
F_15 ( V_25 , V_25 -> V_35 ) ;
}
static int F_21 ( struct V_36 * V_37 )
{
return F_22 ( & V_37 -> V_38 [ V_39 ] ) +
F_22 ( & V_37 -> V_38 [ V_40 ] ) ;
}
void F_23 ( struct V_41 * V_42 )
{
int V_23 ;
struct V_43 * V_44 ;
F_24 ( & V_42 -> V_45 ) ;
F_25 ( & V_42 -> V_46 ) ;
V_42 -> V_44 = F_26 ( struct V_43 ) ;
F_20 (cpu) {
V_44 = F_27 ( V_42 -> V_44 , V_23 ) ;
V_44 -> V_47 = ( V_48 ) V_49 ;
V_44 -> V_50 = V_51 ;
}
}
void F_28 ( struct V_41 * V_42 )
{
T_1 V_52 ;
struct V_24 * V_25 ;
struct V_36 * V_37 ;
while ( ! F_29 ( & V_42 -> V_46 ) ) {
V_25 = F_18 ( V_42 -> V_46 . V_53 , struct V_24 , V_54 ) ;
F_30 ( & V_25 -> V_54 ) ;
for ( V_52 = 0 ; V_52 < V_25 -> V_55 ; V_52 ++ ) {
V_37 = & V_25 -> V_33 [ V_52 ] ;
if ( F_31 ( F_21 ( V_37 ) ) ) {
F_11 ( L_2
L_3 ,
( unsigned long ) V_52 ,
( unsigned long long ) V_25 -> V_56 ,
( unsigned long long ) V_25 -> V_57 ,
( unsigned long long ) V_25 -> V_58 ,
F_22 ( & V_37 -> V_38 [ V_39 ] ) ,
F_22 ( & V_37 -> V_38 [ V_40 ] ) ) ;
}
}
F_17 ( & V_25 -> V_21 ) ;
}
F_32 ( V_42 -> V_44 ) ;
}
static int F_33 ( struct V_41 * V_42 , V_48 V_56 , V_48 V_57 ,
V_48 V_58 , unsigned V_59 ,
unsigned V_60 ,
unsigned long long * V_26 ,
const char * V_27 , const char * V_28 ,
void (* F_34)( struct V_61 * ) ,
void (* F_35)( struct V_61 * ) ,
struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_24 * V_25 , * V_65 ;
V_48 V_55 ;
T_1 V_52 ;
T_1 V_35 ;
T_1 V_32 ;
T_1 V_31 ;
struct V_66 * V_14 ;
int V_23 ;
int V_67 ;
int V_68 ;
if ( V_57 < V_56 || ! V_58 )
return - V_69 ;
V_55 = V_57 - V_56 ;
if ( F_36 ( V_55 , V_58 ) )
V_55 ++ ;
if ( V_55 != ( T_1 ) V_55 || ! ( T_1 ) ( V_55 + 1 ) )
return - V_70 ;
V_35 = sizeof( struct V_24 ) + ( T_1 ) V_55 * sizeof( struct V_36 ) ;
if ( ( V_35 - sizeof( struct V_24 ) ) / sizeof( struct V_36 ) != V_55 )
return - V_70 ;
V_32 = ( T_1 ) V_55 * sizeof( struct V_66 ) ;
if ( V_32 / sizeof( struct V_66 ) != V_55 )
return - V_70 ;
V_31 = ( V_60 + 1 ) * ( T_1 ) V_55 * sizeof( unsigned long long ) ;
if ( V_31 / ( V_60 + 1 ) != ( T_1 ) V_55 * sizeof( unsigned long long ) )
return - V_70 ;
if ( ! F_3 ( V_35 + V_31 +
F_37 () * ( V_32 + V_31 ) ) )
return - V_71 ;
V_25 = F_12 ( V_35 , V_72 ) ;
if ( ! V_25 )
return - V_71 ;
V_25 -> V_59 = V_59 ;
V_25 -> V_55 = V_55 ;
V_25 -> V_56 = V_56 ;
V_25 -> V_57 = V_57 ;
V_25 -> V_58 = V_58 ;
V_25 -> V_35 = V_35 ;
V_25 -> V_32 = V_32 ;
V_25 -> V_31 = V_31 ;
V_25 -> V_60 = V_60 ;
V_25 -> V_26 = F_38 ( V_26 ,
V_25 -> V_60 * sizeof( unsigned long long ) , V_16 ) ;
if ( ! V_25 -> V_26 ) {
V_68 = - V_71 ;
goto V_73;
}
V_25 -> V_27 = F_39 ( V_27 , V_16 ) ;
if ( ! V_25 -> V_27 ) {
V_68 = - V_71 ;
goto V_73;
}
V_25 -> V_28 = F_39 ( V_28 , V_16 ) ;
if ( ! V_25 -> V_28 ) {
V_68 = - V_71 ;
goto V_73;
}
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ ) {
F_40 ( & V_25 -> V_33 [ V_52 ] . V_38 [ V_39 ] , 0 ) ;
F_40 ( & V_25 -> V_33 [ V_52 ] . V_38 [ V_40 ] , 0 ) ;
}
if ( V_25 -> V_60 ) {
unsigned long long * V_74 ;
V_74 = F_12 ( V_25 -> V_31 , V_72 ) ;
if ( ! V_74 ) {
V_68 = - V_71 ;
goto V_73;
}
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ ) {
V_25 -> V_33 [ V_52 ] . V_34 . V_30 = V_74 ;
V_74 += V_25 -> V_60 + 1 ;
}
}
F_20 (cpu) {
V_14 = F_12 ( V_32 , F_41 ( V_23 ) ) ;
if ( ! V_14 ) {
V_68 = - V_71 ;
goto V_73;
}
V_25 -> V_29 [ V_23 ] = V_14 ;
if ( V_25 -> V_60 ) {
unsigned long long * V_74 ;
V_74 = F_12 ( V_25 -> V_31 , F_41 ( V_23 ) ) ;
if ( ! V_74 ) {
V_68 = - V_71 ;
goto V_73;
}
for ( V_52 = 0 ; V_52 < V_55 ; V_52 ++ ) {
V_14 [ V_52 ] . V_30 = V_74 ;
V_74 += V_25 -> V_60 + 1 ;
}
}
}
F_34 ( V_62 ) ;
F_42 ( & V_42 -> V_45 ) ;
V_25 -> V_75 = 0 ;
F_43 (l, &stats->list) {
V_65 = F_18 ( V_64 , struct V_24 , V_54 ) ;
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
F_45 ( & V_25 -> V_54 , V_64 ) ;
F_46 ( & V_42 -> V_45 ) ;
F_35 ( V_62 ) ;
return V_67 ;
V_76:
F_46 ( & V_42 -> V_45 ) ;
F_35 ( V_62 ) ;
V_73:
F_17 ( & V_25 -> V_21 ) ;
return V_68 ;
}
static struct V_24 * F_47 ( struct V_41 * V_42 , int V_75 )
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
static int F_49 ( struct V_41 * V_42 , int V_75 )
{
struct V_24 * V_25 ;
int V_23 ;
F_42 ( & V_42 -> V_45 ) ;
V_25 = F_47 ( V_42 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_42 -> V_45 ) ;
return - V_79 ;
}
F_50 ( & V_25 -> V_54 ) ;
F_46 ( & V_42 -> V_45 ) ;
F_20 (cpu)
if ( F_51 ( V_25 -> V_29 ) ||
F_51 ( V_25 -> V_29 [ V_23 ] [ 0 ] . V_30 ) )
goto V_80;
if ( F_51 ( V_25 ) ||
F_51 ( V_25 -> V_33 [ 0 ] . V_34 . V_30 ) ) {
V_80:
F_52 () ;
F_17 ( & V_25 -> V_21 ) ;
} else {
F_53 ( V_81 ) = 1 ;
F_54 ( & V_25 -> V_21 , F_17 ) ;
}
return 0 ;
}
static int F_55 ( struct V_41 * V_42 , const char * V_82 ,
char * V_83 , unsigned V_84 )
{
struct V_24 * V_25 ;
V_48 V_85 ;
unsigned V_86 = 0 ;
F_42 ( & V_42 -> V_45 ) ;
F_48 (s, &stats->list, list_entry) {
if ( ! V_82 || ! strcmp ( V_82 , V_25 -> V_27 ) ) {
V_85 = V_25 -> V_57 - V_25 -> V_56 ;
F_56 ( L_4 , V_25 -> V_75 ,
( unsigned long long ) V_25 -> V_56 ,
( unsigned long long ) V_85 ,
( unsigned long long ) V_25 -> V_58 ,
V_25 -> V_27 ,
V_25 -> V_28 ) ;
if ( V_25 -> V_59 & V_87 )
F_56 ( L_5 ) ;
if ( V_25 -> V_60 ) {
unsigned V_88 ;
F_56 ( L_6 ) ;
for ( V_88 = 0 ; V_88 < V_25 -> V_60 ; V_88 ++ ) {
if ( V_88 )
F_56 ( L_7 ) ;
F_56 ( L_8 , V_25 -> V_26 [ V_88 ] ) ;
}
}
F_56 ( L_9 ) ;
}
}
F_46 ( & V_42 -> V_45 ) ;
return 1 ;
}
static void F_57 ( struct V_24 * V_25 , struct V_36 * V_37 ,
struct V_66 * V_14 )
{
unsigned long long V_89 , V_90 ;
unsigned V_91 , V_92 ;
if ( F_58 ( ! ( V_25 -> V_59 & V_87 ) ) )
V_89 = V_93 ;
else
V_89 = F_59 ( F_60 () ) ;
V_90 = V_89 - V_37 -> V_94 ;
if ( ! V_90 )
return;
V_91 = ( unsigned ) F_22 ( & V_37 -> V_38 [ V_39 ] ) ;
V_92 = ( unsigned ) F_22 ( & V_37 -> V_38 [ V_40 ] ) ;
if ( V_91 )
V_14 -> V_95 [ V_39 ] += V_90 ;
if ( V_92 )
V_14 -> V_95 [ V_40 ] += V_90 ;
if ( V_91 + V_92 ) {
V_14 -> V_96 += V_90 ;
V_14 -> V_97 += ( V_91 + V_92 ) * V_90 ;
}
V_37 -> V_94 = V_89 ;
}
static void F_61 ( struct V_24 * V_25 , T_1 V_98 ,
int V_99 , V_48 V_85 ,
struct V_100 * V_101 , bool V_57 ,
unsigned long V_102 )
{
struct V_36 * V_37 = & V_25 -> V_33 [ V_98 ] ;
struct V_66 * V_14 ;
#if V_103 == 32
unsigned long V_12 ;
F_62 ( V_12 ) ;
#else
F_63 () ;
#endif
V_14 = & V_25 -> V_29 [ F_64 () ] [ V_98 ] ;
if ( ! V_57 ) {
F_57 ( V_25 , V_37 , V_14 ) ;
F_65 ( & V_37 -> V_38 [ V_99 ] ) ;
} else {
unsigned long long V_104 ;
F_57 ( V_25 , V_37 , V_14 ) ;
F_66 ( & V_37 -> V_38 [ V_99 ] ) ;
V_14 -> V_105 [ V_99 ] += V_85 ;
V_14 -> V_106 [ V_99 ] += 1 ;
V_14 -> V_107 [ V_99 ] += V_101 -> V_108 ;
if ( ! ( V_25 -> V_59 & V_87 ) ) {
V_14 -> V_109 [ V_99 ] += V_102 ;
V_104 = F_67 ( V_102 ) ;
} else {
V_14 -> V_109 [ V_99 ] += V_101 -> V_110 ;
V_104 = V_101 -> V_110 ;
}
if ( V_25 -> V_60 ) {
unsigned V_111 = 0 , V_74 = V_25 -> V_60 + 1 ;
while ( V_111 + 1 < V_74 ) {
unsigned V_112 = ( V_111 + V_74 ) / 2 ;
if ( V_25 -> V_26 [ V_112 - 1 ] > V_104 ) {
V_74 = V_112 ;
} else {
V_111 = V_112 ;
}
}
V_14 -> V_30 [ V_111 ] ++ ;
}
}
#if V_103 == 32
F_68 ( V_12 ) ;
#else
F_69 () ;
#endif
}
static void F_70 ( struct V_24 * V_25 , int V_113 ,
V_48 V_114 , V_48 V_115 ,
bool V_57 , unsigned long V_102 ,
struct V_100 * V_101 )
{
V_48 V_116 , V_117 , V_118 , V_119 ;
T_1 V_98 ;
if ( V_115 <= V_25 -> V_56 || V_114 >= V_25 -> V_57 )
return;
if ( F_44 ( V_114 < V_25 -> V_56 ) ) {
V_116 = 0 ;
V_118 = V_115 - V_25 -> V_56 ;
} else {
V_116 = V_114 - V_25 -> V_56 ;
V_118 = V_115 - V_114 ;
}
if ( F_44 ( V_115 > V_25 -> V_57 ) )
V_118 -= ( V_115 - V_25 -> V_57 ) ;
V_117 = F_36 ( V_116 , V_25 -> V_58 ) ;
V_98 = V_116 ;
do {
if ( F_9 ( V_98 >= V_25 -> V_55 ) ) {
F_11 ( L_10 , V_25 -> V_75 ) ;
return;
}
V_119 = V_118 ;
if ( V_119 > V_25 -> V_58 - V_117 )
V_119 = V_25 -> V_58 - V_117 ;
F_61 ( V_25 , V_98 , V_113 , V_119 ,
V_101 , V_57 , V_102 ) ;
V_118 -= V_119 ;
V_98 ++ ;
V_117 = 0 ;
} while ( F_44 ( V_118 != 0 ) );
}
void F_71 ( struct V_41 * V_42 , unsigned long V_113 ,
V_48 V_114 , unsigned V_120 , bool V_57 ,
unsigned long V_102 ,
struct V_100 * V_101 )
{
struct V_24 * V_25 ;
V_48 V_115 ;
struct V_43 * V_44 ;
bool V_121 ;
if ( F_44 ( ! V_120 ) )
return;
V_115 = V_114 + V_120 ;
if ( ! V_57 ) {
V_44 = F_72 ( V_42 -> V_44 ) ;
V_101 -> V_108 =
( V_114 == ( F_53 ( V_44 -> V_47 ) &&
( ( V_113 == V_40 ) ==
( F_53 ( V_44 -> V_50 ) == V_40 ) )
) ) ;
F_53 ( V_44 -> V_47 ) = V_115 ;
F_53 ( V_44 -> V_50 ) = V_113 ;
}
F_73 () ;
V_121 = false ;
F_74 (s, &stats->list, list_entry) {
if ( V_25 -> V_59 & V_87 && ! V_121 ) {
if ( ! V_57 )
V_101 -> V_110 = F_59 ( F_60 () ) ;
else
V_101 -> V_110 = F_59 ( F_60 () ) - V_101 -> V_110 ;
V_121 = true ;
}
F_70 ( V_25 , V_113 , V_114 , V_115 , V_57 , V_102 , V_101 ) ;
}
F_75 () ;
}
static void F_76 ( struct V_36 * V_37 ,
struct V_24 * V_25 , T_1 V_122 )
{
int V_23 ;
struct V_66 * V_14 ;
F_77 () ;
V_14 = & V_25 -> V_29 [ F_64 () ] [ V_122 ] ;
F_57 ( V_25 , V_37 , V_14 ) ;
F_78 () ;
V_37 -> V_34 . V_105 [ V_39 ] = 0 ;
V_37 -> V_34 . V_105 [ V_40 ] = 0 ;
V_37 -> V_34 . V_106 [ V_39 ] = 0 ;
V_37 -> V_34 . V_106 [ V_40 ] = 0 ;
V_37 -> V_34 . V_107 [ V_39 ] = 0 ;
V_37 -> V_34 . V_107 [ V_40 ] = 0 ;
V_37 -> V_34 . V_109 [ V_39 ] = 0 ;
V_37 -> V_34 . V_109 [ V_40 ] = 0 ;
V_37 -> V_34 . V_95 [ V_39 ] = 0 ;
V_37 -> V_34 . V_95 [ V_40 ] = 0 ;
V_37 -> V_34 . V_96 = 0 ;
V_37 -> V_34 . V_97 = 0 ;
if ( V_25 -> V_60 )
memset ( V_37 -> V_34 . V_30 , 0 , ( V_25 -> V_60 + 1 ) * sizeof( unsigned long long ) ) ;
F_20 (cpu) {
V_14 = & V_25 -> V_29 [ V_23 ] [ V_122 ] ;
V_37 -> V_34 . V_105 [ V_39 ] += F_53 ( V_14 -> V_105 [ V_39 ] ) ;
V_37 -> V_34 . V_105 [ V_40 ] += F_53 ( V_14 -> V_105 [ V_40 ] ) ;
V_37 -> V_34 . V_106 [ V_39 ] += F_53 ( V_14 -> V_106 [ V_39 ] ) ;
V_37 -> V_34 . V_106 [ V_40 ] += F_53 ( V_14 -> V_106 [ V_40 ] ) ;
V_37 -> V_34 . V_107 [ V_39 ] += F_53 ( V_14 -> V_107 [ V_39 ] ) ;
V_37 -> V_34 . V_107 [ V_40 ] += F_53 ( V_14 -> V_107 [ V_40 ] ) ;
V_37 -> V_34 . V_109 [ V_39 ] += F_53 ( V_14 -> V_109 [ V_39 ] ) ;
V_37 -> V_34 . V_109 [ V_40 ] += F_53 ( V_14 -> V_109 [ V_40 ] ) ;
V_37 -> V_34 . V_95 [ V_39 ] += F_53 ( V_14 -> V_95 [ V_39 ] ) ;
V_37 -> V_34 . V_95 [ V_40 ] += F_53 ( V_14 -> V_95 [ V_40 ] ) ;
V_37 -> V_34 . V_96 += F_53 ( V_14 -> V_96 ) ;
V_37 -> V_34 . V_97 += F_53 ( V_14 -> V_97 ) ;
if ( V_25 -> V_60 ) {
unsigned V_88 ;
for ( V_88 = 0 ; V_88 < V_25 -> V_60 + 1 ; V_88 ++ )
V_37 -> V_34 . V_30 [ V_88 ] += F_53 ( V_14 -> V_30 [ V_88 ] ) ;
}
}
}
static void F_79 ( struct V_24 * V_25 , T_1 V_123 , T_1 V_124 ,
bool V_125 )
{
T_1 V_122 ;
struct V_36 * V_37 ;
struct V_66 * V_14 ;
for ( V_122 = V_123 ; V_122 < V_124 ; V_122 ++ ) {
V_37 = & V_25 -> V_33 [ V_122 ] ;
if ( V_125 )
F_76 ( V_37 , V_25 , V_122 ) ;
F_77 () ;
V_14 = & V_25 -> V_29 [ F_64 () ] [ V_122 ] ;
V_14 -> V_105 [ V_39 ] -= V_37 -> V_34 . V_105 [ V_39 ] ;
V_14 -> V_105 [ V_40 ] -= V_37 -> V_34 . V_105 [ V_40 ] ;
V_14 -> V_106 [ V_39 ] -= V_37 -> V_34 . V_106 [ V_39 ] ;
V_14 -> V_106 [ V_40 ] -= V_37 -> V_34 . V_106 [ V_40 ] ;
V_14 -> V_107 [ V_39 ] -= V_37 -> V_34 . V_107 [ V_39 ] ;
V_14 -> V_107 [ V_40 ] -= V_37 -> V_34 . V_107 [ V_40 ] ;
V_14 -> V_109 [ V_39 ] -= V_37 -> V_34 . V_109 [ V_39 ] ;
V_14 -> V_109 [ V_40 ] -= V_37 -> V_34 . V_109 [ V_40 ] ;
V_14 -> V_95 [ V_39 ] -= V_37 -> V_34 . V_95 [ V_39 ] ;
V_14 -> V_95 [ V_40 ] -= V_37 -> V_34 . V_95 [ V_40 ] ;
V_14 -> V_96 -= V_37 -> V_34 . V_96 ;
V_14 -> V_97 -= V_37 -> V_34 . V_97 ;
F_78 () ;
if ( V_25 -> V_60 ) {
unsigned V_88 ;
for ( V_88 = 0 ; V_88 < V_25 -> V_60 + 1 ; V_88 ++ ) {
F_77 () ;
V_14 = & V_25 -> V_29 [ F_64 () ] [ V_122 ] ;
V_14 -> V_30 [ V_88 ] -= V_37 -> V_34 . V_30 [ V_88 ] ;
F_78 () ;
}
}
}
}
static int F_80 ( struct V_41 * V_42 , int V_75 )
{
struct V_24 * V_25 ;
F_42 ( & V_42 -> V_45 ) ;
V_25 = F_47 ( V_42 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_42 -> V_45 ) ;
return - V_79 ;
}
F_79 ( V_25 , 0 , V_25 -> V_55 , true ) ;
F_46 ( & V_42 -> V_45 ) ;
return 1 ;
}
static unsigned long long F_81 ( struct V_24 * V_25 , unsigned long long V_126 )
{
unsigned long long V_83 ;
unsigned V_127 ;
if ( V_25 -> V_59 & V_87 )
return V_126 ;
V_83 = 0 ;
if ( V_126 )
V_83 = F_67 ( V_126 & 0x3fffff ) ;
if ( V_126 >= 1 << 22 ) {
V_127 = F_67 ( 1 << 22 ) ;
V_83 += ( unsigned long long ) V_127 * ( unsigned long long ) F_67 ( ( V_126 >> 22 ) & 0x3fffff ) ;
}
if ( V_126 >= 1ULL << 44 )
V_83 += ( unsigned long long ) V_127 * ( unsigned long long ) V_127 * ( unsigned long long ) F_67 ( V_126 >> 44 ) ;
return V_83 ;
}
static int F_82 ( struct V_41 * V_42 , int V_75 ,
T_1 V_123 , T_1 V_128 ,
bool V_129 , char * V_83 , unsigned V_84 )
{
unsigned V_86 = 0 ;
struct V_24 * V_25 ;
T_1 V_122 ;
V_48 V_56 , V_57 , V_58 ;
T_1 V_124 ;
struct V_36 * V_37 ;
F_42 ( & V_42 -> V_45 ) ;
V_25 = F_47 ( V_42 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_42 -> V_45 ) ;
return - V_79 ;
}
V_124 = V_123 + V_128 ;
if ( V_124 < V_123 ||
V_124 > V_25 -> V_55 )
V_124 = V_25 -> V_55 ;
if ( V_123 > V_124 )
V_123 = V_124 ;
V_58 = V_25 -> V_58 ;
V_56 = V_25 -> V_56 + ( V_58 * V_123 ) ;
for ( V_122 = V_123 ; V_122 < V_124 ; V_122 ++ , V_56 = V_57 ) {
V_37 = & V_25 -> V_33 [ V_122 ] ;
V_57 = V_56 + V_58 ;
if ( F_44 ( V_57 > V_25 -> V_57 ) )
V_57 = V_25 -> V_57 ;
F_76 ( V_37 , V_25 , V_122 ) ;
F_56 ( L_11 ,
( unsigned long long ) V_56 ,
( unsigned long long ) V_58 ,
V_37 -> V_34 . V_106 [ V_39 ] ,
V_37 -> V_34 . V_107 [ V_39 ] ,
V_37 -> V_34 . V_105 [ V_39 ] ,
F_81 ( V_25 , V_37 -> V_34 . V_109 [ V_39 ] ) ,
V_37 -> V_34 . V_106 [ V_40 ] ,
V_37 -> V_34 . V_107 [ V_40 ] ,
V_37 -> V_34 . V_105 [ V_40 ] ,
F_81 ( V_25 , V_37 -> V_34 . V_109 [ V_40 ] ) ,
F_21 ( V_37 ) ,
F_81 ( V_25 , V_37 -> V_34 . V_96 ) ,
F_81 ( V_25 , V_37 -> V_34 . V_97 ) ,
F_81 ( V_25 , V_37 -> V_34 . V_95 [ V_39 ] ) ,
F_81 ( V_25 , V_37 -> V_34 . V_95 [ V_40 ] ) ) ;
if ( V_25 -> V_60 ) {
unsigned V_88 ;
for ( V_88 = 0 ; V_88 < V_25 -> V_60 + 1 ; V_88 ++ ) {
F_56 ( L_12 , ! V_88 ? L_13 : L_14 , V_37 -> V_34 . V_30 [ V_88 ] ) ;
}
}
F_56 ( L_9 ) ;
if ( F_44 ( V_86 + 1 >= V_84 ) )
goto V_130;
}
if ( V_129 )
F_79 ( V_25 , V_123 , V_124 , false ) ;
V_130:
F_46 ( & V_42 -> V_45 ) ;
return 1 ;
}
static int F_83 ( struct V_41 * V_42 , int V_75 , const char * V_28 )
{
struct V_24 * V_25 ;
const char * V_131 ;
F_42 ( & V_42 -> V_45 ) ;
V_25 = F_47 ( V_42 , V_75 ) ;
if ( ! V_25 ) {
F_46 ( & V_42 -> V_45 ) ;
return - V_79 ;
}
V_131 = F_39 ( V_28 , V_16 ) ;
if ( ! V_131 ) {
F_46 ( & V_42 -> V_45 ) ;
return - V_71 ;
}
F_19 ( V_25 -> V_28 ) ;
V_25 -> V_28 = V_131 ;
F_46 ( & V_42 -> V_45 ) ;
return 0 ;
}
static int F_84 ( const char * V_132 , unsigned * V_60 ,
unsigned long long * * V_26 )
{
const char * V_133 ;
unsigned V_134 ;
unsigned long long V_44 ;
* V_60 = 1 ;
for ( V_133 = V_132 ; * V_133 ; V_133 ++ )
if ( * V_133 == ',' )
( * V_60 ) ++ ;
* V_26 = F_85 ( * V_60 * sizeof( unsigned long long ) , V_16 ) ;
if ( ! * V_26 )
return - V_71 ;
V_134 = 0 ;
V_44 = 0 ;
while ( 1 ) {
unsigned long long V_74 ;
int V_25 ;
char V_135 ;
V_25 = sscanf ( V_132 , L_15 , & V_74 , & V_135 ) ;
if ( ! V_25 || ( V_25 == 2 && V_135 != ',' ) )
return - V_69 ;
if ( V_74 <= V_44 )
return - V_69 ;
V_44 = V_74 ;
( * V_26 ) [ V_134 ] = V_74 ;
if ( V_25 == 1 )
return 0 ;
V_132 = strchr ( V_132 , ',' ) + 1 ;
V_134 ++ ;
}
}
static int F_86 ( struct V_61 * V_62 ,
unsigned V_136 , char * * V_137 ,
char * V_83 , unsigned V_84 )
{
int V_68 ;
int V_75 ;
char V_138 ;
unsigned long long V_56 , V_57 , V_85 , V_58 ;
unsigned V_139 ;
const char * V_27 , * V_28 ;
unsigned V_59 = 0 ;
unsigned V_60 = 0 ;
unsigned long long * V_26 = NULL ;
struct V_140 V_141 , V_142 ;
const char * V_2 ;
unsigned V_143 ;
if ( V_136 < 3 )
goto V_144;
V_141 . V_136 = V_136 ;
V_141 . V_137 = V_137 ;
F_87 ( & V_141 , 1 ) ;
V_2 = F_88 ( & V_141 ) ;
if ( ! strcmp ( V_2 , L_16 ) ) {
V_56 = 0 ;
V_85 = F_89 ( V_62 ) ;
if ( ! V_85 )
V_85 = 1 ;
} else if ( sscanf ( V_2 , L_17 , & V_56 , & V_85 , & V_138 ) != 2 ||
V_56 != ( V_48 ) V_56 || V_85 != ( V_48 ) V_85 )
goto V_144;
V_57 = V_56 + V_85 ;
if ( V_56 >= V_57 )
goto V_144;
V_2 = F_88 ( & V_141 ) ;
if ( sscanf ( V_2 , L_18 , & V_139 , & V_138 ) == 1 ) {
if ( ! V_139 )
return - V_69 ;
V_58 = V_57 - V_56 ;
if ( F_90 ( V_58 , V_139 ) )
V_58 ++ ;
if ( ! V_58 )
V_58 = 1 ;
} else if ( sscanf ( V_2 , L_15 , & V_58 , & V_138 ) != 1 ||
V_58 != ( V_48 ) V_58 || ! V_58 )
goto V_144;
V_142 = V_141 ;
V_2 = F_88 ( & V_141 ) ;
if ( V_2 && sscanf ( V_2 , L_19 , & V_143 , & V_138 ) == 1 ) {
while ( V_143 -- ) {
V_2 = F_88 ( & V_141 ) ;
if ( ! V_2 )
goto V_144;
if ( ! strcasecmp ( V_2 , L_20 ) )
V_59 |= V_87 ;
else if ( ! strncasecmp ( V_2 , L_21 , 10 ) ) {
if ( V_60 )
goto V_144;
if ( ( V_68 = F_84 ( V_2 + 10 , & V_60 , & V_26 ) ) )
goto V_10;
} else
goto V_144;
}
} else {
V_141 = V_142 ;
}
V_27 = L_16 ;
V_28 = L_16 ;
V_2 = F_88 ( & V_141 ) ;
if ( V_2 )
V_27 = V_2 ;
V_2 = F_88 ( & V_141 ) ;
if ( V_2 )
V_28 = V_2 ;
if ( V_141 . V_136 )
goto V_144;
snprintf ( V_83 , V_84 , L_22 , V_77 ) ;
if ( F_91 ( V_83 , V_84 ) ) {
V_68 = 1 ;
goto V_10;
}
V_75 = F_33 ( F_92 ( V_62 ) , V_56 , V_57 , V_58 , V_59 ,
V_60 , V_26 , V_27 , V_28 ,
V_145 , V_146 , V_62 ) ;
if ( V_75 < 0 ) {
V_68 = V_75 ;
goto V_10;
}
snprintf ( V_83 , V_84 , L_22 , V_75 ) ;
V_68 = 1 ;
goto V_10;
V_144:
V_68 = - V_69 ;
V_10:
F_19 ( V_26 ) ;
return V_68 ;
}
static int F_93 ( struct V_61 * V_62 ,
unsigned V_136 , char * * V_137 )
{
int V_75 ;
char V_138 ;
if ( V_136 != 2 )
return - V_69 ;
if ( sscanf ( V_137 [ 1 ] , L_23 , & V_75 , & V_138 ) != 1 || V_75 < 0 )
return - V_69 ;
return F_49 ( F_92 ( V_62 ) , V_75 ) ;
}
static int F_94 ( struct V_61 * V_62 ,
unsigned V_136 , char * * V_137 )
{
int V_75 ;
char V_138 ;
if ( V_136 != 2 )
return - V_69 ;
if ( sscanf ( V_137 [ 1 ] , L_23 , & V_75 , & V_138 ) != 1 || V_75 < 0 )
return - V_69 ;
return F_80 ( F_92 ( V_62 ) , V_75 ) ;
}
static int F_95 ( struct V_61 * V_62 ,
unsigned V_136 , char * * V_137 ,
char * V_83 , unsigned V_84 )
{
int V_68 ;
const char * V_82 = NULL ;
if ( V_136 < 1 || V_136 > 2 )
return - V_69 ;
if ( V_136 > 1 ) {
V_82 = F_39 ( V_137 [ 1 ] , V_16 ) ;
if ( ! V_82 )
return - V_71 ;
}
V_68 = F_55 ( F_92 ( V_62 ) , V_82 , V_83 , V_84 ) ;
F_19 ( V_82 ) ;
return V_68 ;
}
static int F_96 ( struct V_61 * V_62 ,
unsigned V_136 , char * * V_137 , bool V_129 ,
char * V_83 , unsigned V_84 )
{
int V_75 ;
char V_138 ;
unsigned long V_123 = 0 , V_128 = V_147 ;
if ( V_136 != 2 && V_136 != 4 )
return - V_69 ;
if ( sscanf ( V_137 [ 1 ] , L_23 , & V_75 , & V_138 ) != 1 || V_75 < 0 )
return - V_69 ;
if ( V_136 > 3 ) {
if ( strcmp ( V_137 [ 2 ] , L_16 ) &&
sscanf ( V_137 [ 2 ] , L_24 , & V_123 , & V_138 ) != 1 )
return - V_69 ;
if ( strcmp ( V_137 [ 3 ] , L_16 ) &&
sscanf ( V_137 [ 3 ] , L_24 , & V_128 , & V_138 ) != 1 )
return - V_69 ;
}
return F_82 ( F_92 ( V_62 ) , V_75 , V_123 , V_128 , V_129 ,
V_83 , V_84 ) ;
}
static int F_97 ( struct V_61 * V_62 ,
unsigned V_136 , char * * V_137 )
{
int V_75 ;
char V_138 ;
if ( V_136 != 3 )
return - V_69 ;
if ( sscanf ( V_137 [ 1 ] , L_23 , & V_75 , & V_138 ) != 1 || V_75 < 0 )
return - V_69 ;
return F_83 ( F_92 ( V_62 ) , V_75 , V_137 [ 2 ] ) ;
}
int F_98 ( struct V_61 * V_62 , unsigned V_136 , char * * V_137 ,
char * V_83 , unsigned V_84 )
{
int V_68 ;
if ( ! strcasecmp ( V_137 [ 0 ] , L_25 ) )
V_68 = F_86 ( V_62 , V_136 , V_137 , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_137 [ 0 ] , L_26 ) )
V_68 = F_93 ( V_62 , V_136 , V_137 ) ;
else if ( ! strcasecmp ( V_137 [ 0 ] , L_27 ) )
V_68 = F_94 ( V_62 , V_136 , V_137 ) ;
else if ( ! strcasecmp ( V_137 [ 0 ] , L_28 ) )
V_68 = F_95 ( V_62 , V_136 , V_137 , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_137 [ 0 ] , L_29 ) )
V_68 = F_96 ( V_62 , V_136 , V_137 , false , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_137 [ 0 ] , L_30 ) )
V_68 = F_96 ( V_62 , V_136 , V_137 , true , V_83 , V_84 ) ;
else if ( ! strcasecmp ( V_137 [ 0 ] , L_31 ) )
V_68 = F_97 ( V_62 , V_136 , V_137 ) ;
else
return 2 ;
if ( V_68 == - V_69 )
F_99 ( L_32 , V_137 [ 0 ] ) ;
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
F_11 ( L_33 , V_3 ) ;
}
