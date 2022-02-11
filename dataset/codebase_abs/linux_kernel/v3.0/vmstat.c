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
void F_52 ( struct V_10 * V_47 , struct V_10 * V_39 , T_4 V_41 )
{
if ( V_39 -> V_48 == V_47 -> V_48 ) {
F_29 ( V_39 , V_49 ) ;
} else {
F_29 ( V_39 , V_50 ) ;
F_29 ( V_47 , V_51 ) ;
}
if ( V_39 -> V_52 == ( ( V_41 & V_53 ) ?
V_47 -> V_52 : F_50 () ) )
F_29 ( V_39 , V_54 ) ;
else
F_29 ( V_39 , V_55 ) ;
}
static void F_53 ( struct V_10 * V_10 ,
unsigned int V_56 ,
struct V_57 * V_58 )
{
unsigned int V_59 ;
V_58 -> V_60 = 0 ;
V_58 -> V_61 = 0 ;
V_58 -> V_62 = 0 ;
for ( V_59 = 0 ; V_59 < V_63 ; V_59 ++ ) {
unsigned long V_64 ;
V_64 = V_10 -> V_65 [ V_59 ] . V_66 ;
V_58 -> V_61 += V_64 ;
V_58 -> V_60 += V_64 << V_59 ;
if ( V_59 >= V_56 )
V_58 -> V_62 += V_64 <<
( V_59 - V_56 ) ;
}
}
static int F_54 ( unsigned int V_59 , struct V_57 * V_58 )
{
unsigned long V_67 = 1UL << V_59 ;
if ( ! V_58 -> V_61 )
return 0 ;
if ( V_58 -> V_62 )
return - 1000 ;
return 1000 - F_55 ( ( 1000 + ( F_55 ( V_58 -> V_60 * 1000ULL , V_67 ) ) ) , V_58 -> V_61 ) ;
}
int F_56 ( struct V_10 * V_10 , unsigned int V_59 )
{
struct V_57 V_58 ;
F_53 ( V_10 , V_59 , & V_58 ) ;
return F_54 ( V_59 , & V_58 ) ;
}
static void * F_57 ( struct V_68 * V_69 , T_5 * V_70 )
{
T_1 * V_21 ;
T_5 V_52 = * V_70 ;
for ( V_21 = F_58 () ;
V_21 && V_52 ;
V_21 = F_59 ( V_21 ) )
-- V_52 ;
return V_21 ;
}
static void * F_60 ( struct V_68 * V_69 , void * V_71 , T_5 * V_70 )
{
T_1 * V_21 = ( T_1 * ) V_71 ;
( * V_70 ) ++ ;
return F_59 ( V_21 ) ;
}
static void F_61 ( struct V_68 * V_69 , void * V_71 )
{
}
static void F_62 ( struct V_68 * V_69 , T_1 * V_21 ,
void (* F_63)( struct V_68 * V_69 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_23 = V_21 -> V_23 ;
unsigned long V_41 ;
for ( V_10 = V_23 ; V_10 - V_23 < V_72 ; ++ V_10 ) {
if ( ! F_64 ( V_10 ) )
continue;
F_65 ( & V_10 -> V_73 , V_41 ) ;
F_63 ( V_69 , V_21 , V_10 ) ;
F_66 ( & V_10 -> V_73 , V_41 ) ;
}
}
static void F_67 ( struct V_68 * V_69 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_59 ;
F_68 ( V_69 , L_1 , V_21 -> V_74 , V_10 -> V_75 ) ;
for ( V_59 = 0 ; V_59 < V_63 ; ++ V_59 )
F_68 ( V_69 , L_2 , V_10 -> V_65 [ V_59 ] . V_66 ) ;
F_69 ( V_69 , '\n' ) ;
}
static int F_70 ( struct V_68 * V_69 , void * V_71 )
{
T_1 * V_21 = ( T_1 * ) V_71 ;
F_62 ( V_69 , V_21 , F_67 ) ;
return 0 ;
}
static void F_71 ( struct V_68 * V_69 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_59 , V_76 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
F_68 ( V_69 , L_3 ,
V_21 -> V_74 ,
V_10 -> V_75 ,
V_78 [ V_76 ] ) ;
for ( V_59 = 0 ; V_59 < V_63 ; ++ V_59 ) {
unsigned long V_79 = 0 ;
struct V_65 * V_80 ;
struct V_81 * V_82 ;
V_80 = & ( V_10 -> V_65 [ V_59 ] ) ;
F_72 (curr, &area->free_list[mtype])
V_79 ++ ;
F_68 ( V_69 , L_2 , V_79 ) ;
}
F_69 ( V_69 , '\n' ) ;
}
}
static int F_73 ( struct V_68 * V_69 , void * V_71 )
{
int V_59 ;
T_1 * V_21 = ( T_1 * ) V_71 ;
F_68 ( V_69 , L_4 , L_5 ) ;
for ( V_59 = 0 ; V_59 < V_63 ; ++ V_59 )
F_68 ( V_69 , L_6 , V_59 ) ;
F_69 ( V_69 , '\n' ) ;
F_62 ( V_69 , V_21 , F_71 ) ;
return 0 ;
}
static void F_74 ( struct V_68 * V_69 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_76 ;
unsigned long V_83 ;
unsigned long V_84 = V_10 -> V_85 ;
unsigned long V_86 = V_84 + V_10 -> V_87 ;
unsigned long V_46 [ V_77 ] = { 0 , } ;
for ( V_83 = V_84 ; V_83 < V_86 ; V_83 += V_88 ) {
struct V_35 * V_35 ;
if ( ! F_75 ( V_83 ) )
continue;
V_35 = F_76 ( V_83 ) ;
if ( ! F_77 ( V_83 , V_35 , V_10 ) )
continue;
V_76 = F_78 ( V_35 ) ;
if ( V_76 < V_77 )
V_46 [ V_76 ] ++ ;
}
F_68 ( V_69 , L_1 , V_21 -> V_74 , V_10 -> V_75 ) ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ )
F_68 ( V_69 , L_7 , V_46 [ V_76 ] ) ;
F_69 ( V_69 , '\n' ) ;
}
static int F_79 ( struct V_68 * V_69 , void * V_71 )
{
int V_76 ;
T_1 * V_21 = ( T_1 * ) V_71 ;
F_68 ( V_69 , L_8 , L_9 ) ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ )
F_68 ( V_69 , L_10 , V_78 [ V_76 ] ) ;
F_69 ( V_69 , '\n' ) ;
F_62 ( V_69 , V_21 , F_74 ) ;
return 0 ;
}
static int F_80 ( struct V_68 * V_69 , void * V_71 )
{
T_1 * V_21 = ( T_1 * ) V_71 ;
if ( ! F_81 ( V_21 -> V_74 , V_89 ) )
return 0 ;
F_68 ( V_69 , L_11 , V_90 ) ;
F_68 ( V_69 , L_12 , V_88 ) ;
F_69 ( V_69 , '\n' ) ;
F_73 ( V_69 , V_21 ) ;
F_79 ( V_69 , V_21 ) ;
return 0 ;
}
static int F_82 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_83 ( V_92 , & V_93 ) ;
}
static int F_84 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_83 ( V_92 , & V_94 ) ;
}
static void F_85 ( struct V_68 * V_69 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_3 ;
F_68 ( V_69 , L_13 , V_21 -> V_74 , V_10 -> V_75 ) ;
F_68 ( V_69 ,
L_14
L_15
L_16
L_17
L_18
L_19
L_20 ,
F_86 ( V_10 , V_95 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_20 ( V_10 ) ,
V_10 -> V_96 ,
V_10 -> V_87 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
F_68 ( V_69 , L_21 , V_97 [ V_3 ] ,
F_86 ( V_10 , V_3 ) ) ;
F_68 ( V_69 ,
L_22 ,
V_10 -> V_98 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_87 ( V_10 -> V_98 ) ; V_3 ++ )
F_68 ( V_69 , L_23 , V_10 -> V_98 [ V_3 ] ) ;
F_68 ( V_69 ,
L_24
L_25 ) ;
F_2 (i) {
struct V_27 * V_18 ;
V_18 = F_19 ( V_10 -> V_18 , V_3 ) ;
F_68 ( V_69 ,
L_26
L_27
L_28
L_29 ,
V_3 ,
V_18 -> V_28 . V_46 ,
V_18 -> V_28 . V_99 ,
V_18 -> V_28 . V_100 ) ;
#ifdef F_88
F_68 ( V_69 , L_30 ,
V_18 -> V_19 ) ;
#endif
}
F_68 ( V_69 ,
L_31
L_32
L_33 ,
V_10 -> V_101 ,
V_10 -> V_85 ,
V_10 -> V_102 ) ;
F_69 ( V_69 , '\n' ) ;
}
static int F_89 ( struct V_68 * V_69 , void * V_71 )
{
T_1 * V_21 = ( T_1 * ) V_71 ;
F_62 ( V_69 , V_21 , F_85 ) ;
return 0 ;
}
static int F_90 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_83 ( V_92 , & V_103 ) ;
}
static void * F_91 ( struct V_68 * V_69 , T_5 * V_70 )
{
unsigned long * V_33 ;
int V_3 , V_104 ;
if ( * V_70 >= F_87 ( V_97 ) )
return NULL ;
V_104 = V_43 * sizeof( unsigned long ) +
V_105 * sizeof( unsigned long ) ;
#ifdef F_92
V_104 += sizeof( struct V_5 ) ;
#endif
V_33 = F_93 ( V_104 , V_106 ) ;
V_69 -> V_107 = V_33 ;
if ( ! V_33 )
return F_94 ( - V_108 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
V_33 [ V_3 ] = F_95 ( V_3 ) ;
V_33 += V_43 ;
F_96 ( V_33 + V_109 ,
V_33 + V_110 ) ;
V_33 += V_105 ;
#ifdef F_92
F_4 ( V_33 ) ;
V_33 [ V_111 ] /= 2 ;
V_33 [ V_112 ] /= 2 ;
#endif
return ( unsigned long * ) V_69 -> V_107 + * V_70 ;
}
static void * F_97 ( struct V_68 * V_69 , void * V_71 , T_5 * V_70 )
{
( * V_70 ) ++ ;
if ( * V_70 >= F_87 ( V_97 ) )
return NULL ;
return ( unsigned long * ) V_69 -> V_107 + * V_70 ;
}
static int F_98 ( struct V_68 * V_69 , void * V_71 )
{
unsigned long * V_113 = V_71 ;
unsigned long V_114 = V_113 - ( unsigned long * ) V_69 -> V_107 ;
F_68 ( V_69 , L_34 , V_97 [ V_114 ] , * V_113 ) ;
return 0 ;
}
static void F_99 ( struct V_68 * V_69 , void * V_71 )
{
F_100 ( V_69 -> V_107 ) ;
V_69 -> V_107 = NULL ;
}
static int F_101 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_83 ( V_92 , & V_115 ) ;
}
static void F_102 ( struct V_116 * V_117 )
{
F_45 ( F_103 () ) ;
F_104 ( & F_105 ( V_118 ) ,
F_106 ( V_119 ) ) ;
}
static void T_6 F_107 ( int V_2 )
{
struct V_120 * V_121 = & F_3 ( V_118 , V_2 ) ;
F_108 ( V_121 , F_102 ) ;
F_109 ( V_2 , V_121 , F_110 ( V_122 , V_2 ) ) ;
}
static int T_6 F_111 ( struct V_123 * V_124 ,
unsigned long V_125 ,
void * V_126 )
{
long V_2 = ( long ) V_126 ;
switch ( V_125 ) {
case V_127 :
case V_128 :
F_17 () ;
F_107 ( V_2 ) ;
F_112 ( F_113 ( V_2 ) , V_129 ) ;
break;
case V_130 :
case V_131 :
F_114 ( & F_3 ( V_118 , V_2 ) ) ;
F_3 ( V_118 , V_2 ) . V_121 . V_132 = NULL ;
break;
case V_133 :
case V_134 :
F_107 ( V_2 ) ;
break;
case V_135 :
case V_136 :
F_17 () ;
break;
default:
break;
}
return V_137 ;
}
static int T_7 F_115 ( void )
{
#ifdef F_88
int V_2 ;
F_116 ( & V_138 ) ;
F_2 (cpu)
F_107 ( V_2 ) ;
#endif
#ifdef F_117
F_118 ( L_35 , V_139 , NULL , & V_140 ) ;
F_118 ( L_36 , V_139 , NULL , & V_141 ) ;
F_118 ( L_37 , V_139 , NULL , & V_142 ) ;
F_118 ( L_38 , V_139 , NULL , & V_143 ) ;
#endif
return 0 ;
}
static int F_119 ( unsigned int V_59 ,
struct V_57 * V_58 )
{
if ( V_58 -> V_60 == 0 )
return 1000 ;
return F_55 ( ( V_58 -> V_60 - ( V_58 -> V_62 << V_59 ) ) * 1000ULL , V_58 -> V_60 ) ;
}
static void F_120 ( struct V_68 * V_69 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_59 ;
int V_144 ;
struct V_57 V_58 ;
F_68 ( V_69 , L_1 ,
V_21 -> V_74 ,
V_10 -> V_75 ) ;
for ( V_59 = 0 ; V_59 < V_63 ; ++ V_59 ) {
F_53 ( V_10 , V_59 , & V_58 ) ;
V_144 = F_119 ( V_59 , & V_58 ) ;
F_68 ( V_69 , L_39 , V_144 / 1000 , V_144 % 1000 ) ;
}
F_69 ( V_69 , '\n' ) ;
}
static int F_121 ( struct V_68 * V_69 , void * V_71 )
{
T_1 * V_21 = ( T_1 * ) V_71 ;
if ( ! F_81 ( V_21 -> V_74 , V_89 ) )
return 0 ;
F_62 ( V_69 , V_21 , F_120 ) ;
return 0 ;
}
static int F_122 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_83 ( V_92 , & V_145 ) ;
}
static void F_123 ( struct V_68 * V_69 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_59 ;
int V_144 ;
struct V_57 V_58 ;
F_68 ( V_69 , L_1 ,
V_21 -> V_74 ,
V_10 -> V_75 ) ;
for ( V_59 = 0 ; V_59 < V_63 ; ++ V_59 ) {
F_53 ( V_10 , V_59 , & V_58 ) ;
V_144 = F_54 ( V_59 , & V_58 ) ;
F_68 ( V_69 , L_39 , V_144 / 1000 , V_144 % 1000 ) ;
}
F_69 ( V_69 , '\n' ) ;
}
static int F_124 ( struct V_68 * V_69 , void * V_71 )
{
T_1 * V_21 = ( T_1 * ) V_71 ;
F_62 ( V_69 , V_21 , F_123 ) ;
return 0 ;
}
static int F_125 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
return F_83 ( V_92 , & V_146 ) ;
}
static int T_7 F_126 ( void )
{
V_147 = F_127 ( L_40 , NULL ) ;
if ( ! V_147 )
return - V_108 ;
if ( ! F_128 ( L_41 , 0444 ,
V_147 , NULL , & V_148 ) )
return - V_108 ;
if ( ! F_128 ( L_42 , 0444 ,
V_147 , NULL , & V_149 ) )
return - V_108 ;
return 0 ;
}
