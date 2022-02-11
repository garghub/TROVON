static void F_1 ( unsigned long * V_1 )
{
int V_2 ;
int V_3 ;
memset ( V_1 , 0 , V_4 * sizeof( unsigned long ) ) ;
F_2 (cpu) {
struct V_5 * V_6 = & F_3 ( V_7 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
V_1 [ V_3 ] += V_6 -> V_8 [ V_3 ] ;
}
}
void F_4 ( unsigned long * V_1 )
{
F_5 () ;
F_1 ( V_1 ) ;
F_6 () ;
}
void F_7 ( int V_2 )
{
struct V_5 * V_9 = & F_3 ( V_7 , V_2 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 ( V_3 , V_9 -> V_8 [ V_3 ] ) ;
V_9 -> V_8 [ V_3 ] = 0 ;
}
}
int F_9 ( struct V_10 * V_10 )
{
int V_11 ;
int V_12 ;
V_12 = F_10 ( V_10 ) - F_11 ( V_10 ) ;
V_11 = F_12 ( 1 , ( int ) ( V_12 / F_13 () ) ) ;
V_11 = F_14 ( 125 , V_11 ) ;
return V_11 ;
}
int F_15 ( struct V_10 * V_10 )
{
int V_11 ;
int V_13 ;
V_13 = V_10 -> V_14 >> ( 27 - V_15 ) ;
V_11 = 2 * F_16 ( F_13 () ) * ( 1 + F_16 ( V_13 ) ) ;
V_11 = F_14 ( 125 , V_11 ) ;
return V_11 ;
}
void F_17 ( void )
{
struct V_10 * V_10 ;
int V_2 ;
int V_11 ;
F_18 (zone) {
unsigned long V_16 , V_17 ;
V_11 = F_15 ( V_10 ) ;
F_2 (cpu)
F_19 ( V_10 -> V_18 , V_2 ) -> V_19
= V_11 ;
V_17 = F_10 ( V_10 ) - F_11 ( V_10 ) ;
V_16 = F_13 () * V_11 ;
if ( V_16 > V_17 )
V_10 -> V_20 = F_20 ( V_10 ) +
V_16 ;
}
}
void F_21 ( T_1 * V_21 ,
int (* F_22)( struct V_10 * ) )
{
struct V_10 * V_10 ;
int V_2 ;
int V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_22 ; V_3 ++ ) {
V_10 = & V_21 -> V_23 [ V_3 ] ;
if ( ! V_10 -> V_20 )
continue;
V_11 = (* F_22)( V_10 ) ;
F_23 (cpu)
F_19 ( V_10 -> V_18 , V_2 ) -> V_19
= V_11 ;
}
}
void F_24 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
long V_31 ;
long V_32 ;
V_31 = V_26 + F_25 ( * V_29 ) ;
V_32 = F_25 ( V_28 -> V_19 ) ;
if ( F_26 ( V_31 > V_32 || V_31 < - V_32 ) ) {
F_27 ( V_31 , V_10 , V_25 ) ;
V_31 = 0 ;
}
F_28 ( * V_29 , V_31 ) ;
}
void F_29 ( struct V_10 * V_10 , enum V_24 V_25 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
T_3 V_33 , V_32 ;
V_33 = F_30 ( * V_29 ) ;
V_32 = F_25 ( V_28 -> V_19 ) ;
if ( F_26 ( V_33 > V_32 ) ) {
T_3 V_34 = V_32 >> 1 ;
F_27 ( V_33 + V_34 , V_10 , V_25 ) ;
F_28 ( * V_29 , - V_34 ) ;
}
}
void F_31 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_29 ( F_32 ( V_35 ) , V_25 ) ;
}
void F_33 ( struct V_10 * V_10 , enum V_24 V_25 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
T_3 V_33 , V_32 ;
V_33 = F_34 ( * V_29 ) ;
V_32 = F_25 ( V_28 -> V_19 ) ;
if ( F_26 ( V_33 < - V_32 ) ) {
T_3 V_34 = V_32 >> 1 ;
F_27 ( V_33 - V_34 , V_10 , V_25 ) ;
F_28 ( * V_29 , V_34 ) ;
}
}
void F_35 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_33 ( F_32 ( V_35 ) , V_25 ) ;
}
static inline void F_36 ( struct V_10 * V_10 ,
enum V_24 V_25 , int V_26 , int V_36 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
long V_37 , V_38 , V_32 , V_39 ;
do {
V_39 = 0 ;
V_32 = F_37 ( V_28 -> V_19 ) ;
V_37 = F_37 ( * V_29 ) ;
V_38 = V_26 + V_37 ;
if ( V_38 > V_32 || V_38 < - V_32 ) {
int V_40 = V_36 * ( V_32 >> 1 ) ;
V_39 = V_38 + V_40 ;
V_38 = - V_40 ;
}
} while ( F_38 ( * V_29 , V_37 , V_38 ) != V_37 );
if ( V_39 )
F_27 ( V_39 , V_10 , V_25 ) ;
}
void F_39 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
F_36 ( V_10 , V_25 , V_26 , 0 ) ;
}
void F_40 ( struct V_10 * V_10 , enum V_24 V_25 )
{
F_36 ( V_10 , V_25 , 1 , 1 ) ;
}
void F_41 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_36 ( F_32 ( V_35 ) , V_25 , 1 , 1 ) ;
}
void F_42 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_36 ( F_32 ( V_35 ) , V_25 , - 1 , - 1 ) ;
}
void F_39 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
unsigned long V_41 ;
F_43 ( V_41 ) ;
F_24 ( V_10 , V_25 , V_26 ) ;
F_44 ( V_41 ) ;
}
void F_40 ( struct V_10 * V_10 , enum V_24 V_25 )
{
unsigned long V_41 ;
F_43 ( V_41 ) ;
F_29 ( V_10 , V_25 ) ;
F_44 ( V_41 ) ;
}
void F_41 ( struct V_35 * V_35 , enum V_24 V_25 )
{
unsigned long V_41 ;
struct V_10 * V_10 ;
V_10 = F_32 ( V_35 ) ;
F_43 ( V_41 ) ;
F_29 ( V_10 , V_25 ) ;
F_44 ( V_41 ) ;
}
void F_42 ( struct V_35 * V_35 , enum V_24 V_25 )
{
unsigned long V_41 ;
F_43 ( V_41 ) ;
F_35 ( V_35 , V_25 ) ;
F_44 ( V_41 ) ;
}
void F_45 ( int V_2 )
{
struct V_10 * V_10 ;
int V_3 ;
int V_42 [ V_43 ] = { 0 , } ;
F_18 (zone) {
struct V_27 * V_29 ;
V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_29 -> V_30 [ V_3 ] ) {
unsigned long V_41 ;
int V_33 ;
F_43 ( V_41 ) ;
V_33 = V_29 -> V_30 [ V_3 ] ;
V_29 -> V_30 [ V_3 ] = 0 ;
F_44 ( V_41 ) ;
F_46 ( V_33 , & V_10 -> V_44 [ V_3 ] ) ;
V_42 [ V_3 ] += V_33 ;
#ifdef F_47
V_29 -> V_45 = 3 ;
#endif
}
F_48 () ;
#ifdef F_47
if ( ! V_29 -> V_45 || ! V_29 -> V_28 . V_46 )
continue;
if ( F_49 ( V_10 ) == F_50 () ) {
V_29 -> V_45 = 0 ;
continue;
}
V_29 -> V_45 -- ;
if ( V_29 -> V_45 )
continue;
if ( V_29 -> V_28 . V_46 )
F_51 ( V_10 , & V_29 -> V_28 ) ;
#endif
}
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_42 [ V_3 ] )
F_46 ( V_42 [ V_3 ] , & V_44 [ V_3 ] ) ;
}
void F_52 ( struct V_10 * V_10 , struct V_27 * V_47 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_47 -> V_30 [ V_3 ] ) {
int V_33 = V_47 -> V_30 [ V_3 ] ;
V_47 -> V_30 [ V_3 ] = 0 ;
F_46 ( V_33 , & V_10 -> V_44 [ V_3 ] ) ;
F_46 ( V_33 , & V_44 [ V_3 ] ) ;
}
}
void F_53 ( struct V_10 * V_48 , struct V_10 * V_39 , T_4 V_41 )
{
if ( V_39 -> V_49 == V_48 -> V_49 ) {
F_29 ( V_39 , V_50 ) ;
} else {
F_29 ( V_39 , V_51 ) ;
F_29 ( V_48 , V_52 ) ;
}
if ( V_39 -> V_53 == ( ( V_41 & V_54 ) ?
V_48 -> V_53 : F_50 () ) )
F_29 ( V_39 , V_55 ) ;
else
F_29 ( V_39 , V_56 ) ;
}
static void F_54 ( struct V_10 * V_10 ,
unsigned int V_57 ,
struct V_58 * V_59 )
{
unsigned int V_60 ;
V_59 -> V_61 = 0 ;
V_59 -> V_62 = 0 ;
V_59 -> V_63 = 0 ;
for ( V_60 = 0 ; V_60 < V_64 ; V_60 ++ ) {
unsigned long V_65 ;
V_65 = V_10 -> V_66 [ V_60 ] . V_67 ;
V_59 -> V_62 += V_65 ;
V_59 -> V_61 += V_65 << V_60 ;
if ( V_60 >= V_57 )
V_59 -> V_63 += V_65 <<
( V_60 - V_57 ) ;
}
}
static int F_55 ( unsigned int V_60 , struct V_58 * V_59 )
{
unsigned long V_68 = 1UL << V_60 ;
if ( ! V_59 -> V_62 )
return 0 ;
if ( V_59 -> V_63 )
return - 1000 ;
return 1000 - F_56 ( ( 1000 + ( F_56 ( V_59 -> V_61 * 1000ULL , V_68 ) ) ) , V_59 -> V_62 ) ;
}
int F_57 ( struct V_10 * V_10 , unsigned int V_60 )
{
struct V_58 V_59 ;
F_54 ( V_10 , V_60 , & V_59 ) ;
return F_55 ( V_60 , & V_59 ) ;
}
static void * F_58 ( struct V_69 * V_70 , T_5 * V_71 )
{
T_1 * V_21 ;
T_5 V_53 = * V_71 ;
for ( V_21 = F_59 () ;
V_21 && V_53 ;
V_21 = F_60 ( V_21 ) )
-- V_53 ;
return V_21 ;
}
static void * F_61 ( struct V_69 * V_70 , void * V_72 , T_5 * V_71 )
{
T_1 * V_21 = ( T_1 * ) V_72 ;
( * V_71 ) ++ ;
return F_60 ( V_21 ) ;
}
static void F_62 ( struct V_69 * V_70 , void * V_72 )
{
}
static void F_63 ( struct V_69 * V_70 , T_1 * V_21 ,
void (* F_64)( struct V_69 * V_70 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_23 = V_21 -> V_23 ;
unsigned long V_41 ;
for ( V_10 = V_23 ; V_10 - V_23 < V_73 ; ++ V_10 ) {
if ( ! F_65 ( V_10 ) )
continue;
F_66 ( & V_10 -> V_74 , V_41 ) ;
F_64 ( V_70 , V_21 , V_10 ) ;
F_67 ( & V_10 -> V_74 , V_41 ) ;
}
}
static void F_68 ( struct V_69 * V_70 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_60 ;
F_69 ( V_70 , L_1 , V_21 -> V_75 , V_10 -> V_76 ) ;
for ( V_60 = 0 ; V_60 < V_64 ; ++ V_60 )
F_69 ( V_70 , L_2 , V_10 -> V_66 [ V_60 ] . V_67 ) ;
F_70 ( V_70 , '\n' ) ;
}
static int F_71 ( struct V_69 * V_70 , void * V_72 )
{
T_1 * V_21 = ( T_1 * ) V_72 ;
F_63 ( V_70 , V_21 , F_68 ) ;
return 0 ;
}
static void F_72 ( struct V_69 * V_70 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_60 , V_77 ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ ) {
F_69 ( V_70 , L_3 ,
V_21 -> V_75 ,
V_10 -> V_76 ,
V_79 [ V_77 ] ) ;
for ( V_60 = 0 ; V_60 < V_64 ; ++ V_60 ) {
unsigned long V_80 = 0 ;
struct V_66 * V_81 ;
struct V_82 * V_83 ;
V_81 = & ( V_10 -> V_66 [ V_60 ] ) ;
F_73 (curr, &area->free_list[mtype])
V_80 ++ ;
F_69 ( V_70 , L_2 , V_80 ) ;
}
F_70 ( V_70 , '\n' ) ;
}
}
static int F_74 ( struct V_69 * V_70 , void * V_72 )
{
int V_60 ;
T_1 * V_21 = ( T_1 * ) V_72 ;
F_69 ( V_70 , L_4 , L_5 ) ;
for ( V_60 = 0 ; V_60 < V_64 ; ++ V_60 )
F_69 ( V_70 , L_6 , V_60 ) ;
F_70 ( V_70 , '\n' ) ;
F_63 ( V_70 , V_21 , F_72 ) ;
return 0 ;
}
static void F_75 ( struct V_69 * V_70 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_77 ;
unsigned long V_84 ;
unsigned long V_85 = V_10 -> V_86 ;
unsigned long V_87 = V_85 + V_10 -> V_88 ;
unsigned long V_46 [ V_78 ] = { 0 , } ;
for ( V_84 = V_85 ; V_84 < V_87 ; V_84 += V_89 ) {
struct V_35 * V_35 ;
if ( ! F_76 ( V_84 ) )
continue;
V_35 = F_77 ( V_84 ) ;
if ( ! F_78 ( V_84 , V_35 , V_10 ) )
continue;
V_77 = F_79 ( V_35 ) ;
if ( V_77 < V_78 )
V_46 [ V_77 ] ++ ;
}
F_69 ( V_70 , L_1 , V_21 -> V_75 , V_10 -> V_76 ) ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ )
F_69 ( V_70 , L_7 , V_46 [ V_77 ] ) ;
F_70 ( V_70 , '\n' ) ;
}
static int F_80 ( struct V_69 * V_70 , void * V_72 )
{
int V_77 ;
T_1 * V_21 = ( T_1 * ) V_72 ;
F_69 ( V_70 , L_8 , L_9 ) ;
for ( V_77 = 0 ; V_77 < V_78 ; V_77 ++ )
F_69 ( V_70 , L_10 , V_79 [ V_77 ] ) ;
F_70 ( V_70 , '\n' ) ;
F_63 ( V_70 , V_21 , F_75 ) ;
return 0 ;
}
static int F_81 ( struct V_69 * V_70 , void * V_72 )
{
T_1 * V_21 = ( T_1 * ) V_72 ;
if ( ! F_82 ( V_21 -> V_75 , V_90 ) )
return 0 ;
F_69 ( V_70 , L_11 , V_91 ) ;
F_69 ( V_70 , L_12 , V_89 ) ;
F_70 ( V_70 , '\n' ) ;
F_74 ( V_70 , V_21 ) ;
F_80 ( V_70 , V_21 ) ;
return 0 ;
}
static int F_83 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_84 ( V_93 , & V_94 ) ;
}
static int F_85 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_84 ( V_93 , & V_95 ) ;
}
static void F_86 ( struct V_69 * V_70 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_3 ;
F_69 ( V_70 , L_13 , V_21 -> V_75 , V_10 -> V_76 ) ;
F_69 ( V_70 ,
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
F_87 ( V_10 , V_96 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_20 ( V_10 ) ,
V_10 -> V_97 ,
V_10 -> V_88 ,
V_10 -> V_14 ,
V_10 -> V_98 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
F_69 ( V_70 , L_22 , V_99 [ V_3 ] ,
F_87 ( V_10 , V_3 ) ) ;
F_69 ( V_70 ,
L_23 ,
V_10 -> V_100 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_88 ( V_10 -> V_100 ) ; V_3 ++ )
F_69 ( V_70 , L_24 , V_10 -> V_100 [ V_3 ] ) ;
F_69 ( V_70 ,
L_25
L_26 ) ;
F_2 (i) {
struct V_27 * V_18 ;
V_18 = F_19 ( V_10 -> V_18 , V_3 ) ;
F_69 ( V_70 ,
L_27
L_28
L_29
L_30 ,
V_3 ,
V_18 -> V_28 . V_46 ,
V_18 -> V_28 . V_101 ,
V_18 -> V_28 . V_102 ) ;
#ifdef F_89
F_69 ( V_70 , L_31 ,
V_18 -> V_19 ) ;
#endif
}
F_69 ( V_70 ,
L_32
L_33
L_34 ,
V_10 -> V_103 ,
V_10 -> V_86 ,
V_10 -> V_104 ) ;
F_70 ( V_70 , '\n' ) ;
}
static int F_90 ( struct V_69 * V_70 , void * V_72 )
{
T_1 * V_21 = ( T_1 * ) V_72 ;
F_63 ( V_70 , V_21 , F_86 ) ;
return 0 ;
}
static int F_91 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_84 ( V_93 , & V_105 ) ;
}
static void * F_92 ( struct V_69 * V_70 , T_5 * V_71 )
{
unsigned long * V_33 ;
int V_3 , V_106 ;
if ( * V_71 >= F_88 ( V_99 ) )
return NULL ;
V_106 = V_43 * sizeof( unsigned long ) +
V_107 * sizeof( unsigned long ) ;
#ifdef F_93
V_106 += sizeof( struct V_5 ) ;
#endif
V_33 = F_94 ( V_106 , V_108 ) ;
V_70 -> V_109 = V_33 ;
if ( ! V_33 )
return F_95 ( - V_110 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
V_33 [ V_3 ] = F_96 ( V_3 ) ;
V_33 += V_43 ;
F_97 ( V_33 + V_111 ,
V_33 + V_112 ) ;
V_33 += V_107 ;
#ifdef F_93
F_4 ( V_33 ) ;
V_33 [ V_113 ] /= 2 ;
V_33 [ V_114 ] /= 2 ;
#endif
return ( unsigned long * ) V_70 -> V_109 + * V_71 ;
}
static void * F_98 ( struct V_69 * V_70 , void * V_72 , T_5 * V_71 )
{
( * V_71 ) ++ ;
if ( * V_71 >= F_88 ( V_99 ) )
return NULL ;
return ( unsigned long * ) V_70 -> V_109 + * V_71 ;
}
static int F_99 ( struct V_69 * V_70 , void * V_72 )
{
unsigned long * V_115 = V_72 ;
unsigned long V_116 = V_115 - ( unsigned long * ) V_70 -> V_109 ;
F_69 ( V_70 , L_35 , V_99 [ V_116 ] , * V_115 ) ;
return 0 ;
}
static void F_100 ( struct V_69 * V_70 , void * V_72 )
{
F_101 ( V_70 -> V_109 ) ;
V_70 -> V_109 = NULL ;
}
static int F_102 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_84 ( V_93 , & V_117 ) ;
}
static void F_103 ( struct V_118 * V_119 )
{
F_45 ( F_104 () ) ;
F_105 ( & F_106 ( V_120 ) ,
F_107 ( V_121 ) ) ;
}
static void T_6 F_108 ( int V_2 )
{
struct V_122 * V_123 = & F_3 ( V_120 , V_2 ) ;
F_109 ( V_123 , F_103 ) ;
F_110 ( V_2 , V_123 , F_111 ( V_124 , V_2 ) ) ;
}
static int T_6 F_112 ( struct V_125 * V_126 ,
unsigned long V_127 ,
void * V_128 )
{
long V_2 = ( long ) V_128 ;
switch ( V_127 ) {
case V_129 :
case V_130 :
F_17 () ;
F_108 ( V_2 ) ;
F_113 ( F_114 ( V_2 ) , V_131 ) ;
break;
case V_132 :
case V_133 :
F_115 ( & F_3 ( V_120 , V_2 ) ) ;
F_3 ( V_120 , V_2 ) . V_123 . V_134 = NULL ;
break;
case V_135 :
case V_136 :
F_108 ( V_2 ) ;
break;
case V_137 :
case V_138 :
F_17 () ;
break;
default:
break;
}
return V_139 ;
}
static int T_7 F_116 ( void )
{
#ifdef F_89
int V_2 ;
F_117 ( & V_140 ) ;
F_2 (cpu)
F_108 ( V_2 ) ;
#endif
#ifdef F_118
F_119 ( L_36 , V_141 , NULL , & V_142 ) ;
F_119 ( L_37 , V_141 , NULL , & V_143 ) ;
F_119 ( L_38 , V_141 , NULL , & V_144 ) ;
F_119 ( L_39 , V_141 , NULL , & V_145 ) ;
#endif
return 0 ;
}
static int F_120 ( unsigned int V_60 ,
struct V_58 * V_59 )
{
if ( V_59 -> V_61 == 0 )
return 1000 ;
return F_56 ( ( V_59 -> V_61 - ( V_59 -> V_63 << V_60 ) ) * 1000ULL , V_59 -> V_61 ) ;
}
static void F_121 ( struct V_69 * V_70 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_60 ;
int V_146 ;
struct V_58 V_59 ;
F_69 ( V_70 , L_1 ,
V_21 -> V_75 ,
V_10 -> V_76 ) ;
for ( V_60 = 0 ; V_60 < V_64 ; ++ V_60 ) {
F_54 ( V_10 , V_60 , & V_59 ) ;
V_146 = F_120 ( V_60 , & V_59 ) ;
F_69 ( V_70 , L_40 , V_146 / 1000 , V_146 % 1000 ) ;
}
F_70 ( V_70 , '\n' ) ;
}
static int F_122 ( struct V_69 * V_70 , void * V_72 )
{
T_1 * V_21 = ( T_1 * ) V_72 ;
if ( ! F_82 ( V_21 -> V_75 , V_90 ) )
return 0 ;
F_63 ( V_70 , V_21 , F_121 ) ;
return 0 ;
}
static int F_123 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_84 ( V_93 , & V_147 ) ;
}
static void F_124 ( struct V_69 * V_70 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_60 ;
int V_146 ;
struct V_58 V_59 ;
F_69 ( V_70 , L_1 ,
V_21 -> V_75 ,
V_10 -> V_76 ) ;
for ( V_60 = 0 ; V_60 < V_64 ; ++ V_60 ) {
F_54 ( V_10 , V_60 , & V_59 ) ;
V_146 = F_55 ( V_60 , & V_59 ) ;
F_69 ( V_70 , L_40 , V_146 / 1000 , V_146 % 1000 ) ;
}
F_70 ( V_70 , '\n' ) ;
}
static int F_125 ( struct V_69 * V_70 , void * V_72 )
{
T_1 * V_21 = ( T_1 * ) V_72 ;
F_63 ( V_70 , V_21 , F_124 ) ;
return 0 ;
}
static int F_126 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_84 ( V_93 , & V_148 ) ;
}
static int T_7 F_127 ( void )
{
struct V_149 * V_150 ;
V_150 = F_128 ( L_41 , NULL ) ;
if ( ! V_150 )
return - V_110 ;
if ( ! F_129 ( L_42 , 0444 ,
V_150 , NULL , & V_151 ) )
goto V_152;
if ( ! F_129 ( L_43 , 0444 ,
V_150 , NULL , & V_153 ) )
goto V_152;
return 0 ;
V_152:
F_130 ( V_150 ) ;
return - V_110 ;
}
