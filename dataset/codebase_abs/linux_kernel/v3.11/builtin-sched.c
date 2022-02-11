static T_1 F_1 ( void )
{
struct V_1 V_2 ;
F_2 ( V_3 , & V_2 ) ;
return V_2 . V_4 * 1000000000ULL + V_2 . V_5 ;
}
static void F_3 ( struct V_6 * V_7 , T_1 V_8 )
{
T_1 V_9 = F_1 () , V_10 ;
do {
V_10 = F_1 () ;
} while ( V_10 + V_7 -> V_11 < V_9 + V_8 );
}
static void F_4 ( T_1 V_8 )
{
struct V_1 V_2 ;
V_2 . V_5 = V_8 % 999999999 ;
V_2 . V_4 = V_8 / 999999999 ;
F_5 ( & V_2 , NULL ) ;
}
static void F_6 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 , V_12 , V_13 = 1000000000ULL ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 10 ; V_14 ++ ) {
V_9 = F_1 () ;
F_3 ( V_7 , 0 ) ;
V_10 = F_1 () ;
V_12 = V_10 - V_9 ;
V_13 = F_7 ( V_13 , V_12 ) ;
}
V_7 -> V_11 = V_13 ;
printf ( L_1 V_15 L_2 , V_13 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 , V_12 , V_13 = 1000000000ULL ;
int V_14 ;
for ( V_14 = 0 ; V_14 < 10 ; V_14 ++ ) {
V_9 = F_1 () ;
F_4 ( 10000 ) ;
V_10 = F_1 () ;
V_12 = V_10 - V_9 ;
V_13 = F_7 ( V_13 , V_12 ) ;
}
V_13 -= 10000 ;
V_7 -> V_16 = V_13 ;
printf ( L_3 V_15 L_2 , V_13 ) ;
}
static struct V_17 *
F_9 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_17 * V_21 = F_10 ( sizeof( * V_21 ) ) ;
unsigned long V_22 = V_19 -> V_23 ;
T_2 V_24 ;
V_21 -> V_20 = V_20 ;
V_21 -> V_25 = V_22 ;
V_19 -> V_23 ++ ;
V_24 = sizeof( struct V_17 * ) * V_19 -> V_23 ;
V_19 -> V_26 = realloc ( V_19 -> V_26 , V_24 ) ;
F_11 ( ! V_19 -> V_26 ) ;
V_19 -> V_26 [ V_22 ] = V_21 ;
return V_21 ;
}
static struct V_17 * F_12 ( struct V_18 * V_19 )
{
if ( ! V_19 -> V_23 )
return NULL ;
return V_19 -> V_26 [ V_19 -> V_23 - 1 ] ;
}
static void F_13 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_1 V_20 , T_1 V_27 )
{
struct V_17 * V_21 , * V_28 = F_12 ( V_19 ) ;
if ( V_28 && V_28 -> type == V_29 ) {
V_7 -> V_30 ++ ;
V_28 -> V_27 += V_27 ;
return;
}
V_21 = F_9 ( V_19 , V_20 ) ;
V_21 -> type = V_29 ;
V_21 -> V_27 = V_27 ;
V_7 -> V_31 ++ ;
}
static void F_14 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_1 V_20 , struct V_18 * V_32 )
{
struct V_17 * V_21 , * V_33 ;
V_21 = F_9 ( V_19 , V_20 ) ;
V_21 -> type = V_34 ;
V_21 -> V_32 = V_32 ;
V_33 = F_12 ( V_32 ) ;
if ( ! V_33 || V_33 -> type != V_35 ) {
V_7 -> V_36 ++ ;
return;
}
if ( V_33 -> V_37 ) {
V_7 -> V_38 ++ ;
return;
}
V_33 -> V_37 = F_10 ( sizeof( * V_33 -> V_37 ) ) ;
F_15 ( V_33 -> V_37 , 0 , 0 ) ;
V_33 -> V_39 = 1 ;
V_21 -> V_37 = V_33 -> V_37 ;
V_7 -> V_40 ++ ;
}
static void F_16 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_1 V_20 , T_1 T_3 V_41 )
{
struct V_17 * V_21 = F_9 ( V_19 , V_20 ) ;
V_21 -> type = V_35 ;
V_7 -> V_42 ++ ;
}
static struct V_18 * F_17 ( struct V_6 * V_7 ,
unsigned long V_43 , const char * V_44 )
{
struct V_18 * V_19 ;
F_11 ( V_43 >= V_45 ) ;
V_19 = V_7 -> V_46 [ V_43 ] ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( sizeof( * V_19 ) ) ;
V_19 -> V_43 = V_43 ;
V_19 -> V_25 = V_7 -> V_47 ;
strcpy ( V_19 -> V_44 , V_44 ) ;
F_16 ( V_7 , V_19 , 0 , 0 ) ;
V_7 -> V_46 [ V_43 ] = V_19 ;
V_7 -> V_47 ++ ;
V_7 -> V_48 = realloc ( V_7 -> V_48 , V_7 -> V_47 * sizeof( struct V_49 * ) ) ;
F_11 ( ! V_7 -> V_48 ) ;
V_7 -> V_48 [ V_19 -> V_25 ] = V_19 ;
if ( V_50 )
printf ( L_4 , V_7 -> V_47 , V_43 , V_44 ) ;
return V_19 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_18 * V_19 ;
unsigned long V_14 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
printf ( L_5 ,
V_19 -> V_25 , V_19 -> V_44 , V_19 -> V_43 , V_19 -> V_23 ) ;
}
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_18 * V_51 , * V_52 ;
unsigned long V_14 , V_53 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_51 = V_7 -> V_48 [ V_14 ] ;
V_53 = V_14 + 1 ;
if ( V_53 == V_7 -> V_47 )
V_53 = 0 ;
V_52 = V_7 -> V_48 [ V_53 ] ;
F_14 ( V_7 , V_51 , 0 , V_52 ) ;
}
}
static void F_20 ( struct V_6 * V_7 ,
struct V_17 * V_54 )
{
int V_55 = 0 ;
switch ( V_54 -> type ) {
case V_29 :
F_3 ( V_7 , V_54 -> V_27 ) ;
break;
case V_35 :
if ( V_54 -> V_37 )
V_55 = F_21 ( V_54 -> V_37 ) ;
F_11 ( V_55 ) ;
break;
case V_34 :
if ( V_54 -> V_37 )
V_55 = F_22 ( V_54 -> V_37 ) ;
F_11 ( V_55 ) ;
break;
case V_56 :
break;
default:
F_11 ( 1 ) ;
}
}
static T_1 F_23 ( void )
{
struct V_57 V_58 ;
T_1 V_59 ;
int V_60 ;
V_60 = F_24 ( V_61 , & V_58 ) ;
F_11 ( V_60 ) ;
V_59 = V_58 . V_62 . V_4 * 1e9 + V_58 . V_62 . V_63 * 1e3 ;
V_59 += V_58 . V_64 . V_4 * 1e9 + V_58 . V_64 . V_63 * 1e3 ;
return V_59 ;
}
static int F_25 ( void )
{
struct V_65 V_66 ;
int V_67 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . type = V_68 ;
V_66 . V_69 = V_70 ;
V_67 = F_26 ( & V_66 , 0 , - 1 , - 1 , 0 ) ;
if ( V_67 < 0 )
F_27 ( L_6
L_7 , V_67 , strerror ( V_71 ) ) ;
return V_67 ;
}
static T_1 F_28 ( int V_67 )
{
T_1 V_72 ;
int V_55 ;
V_55 = F_29 ( V_67 , & V_72 , sizeof( V_72 ) ) ;
F_11 ( V_55 != sizeof( V_72 ) ) ;
return V_72 ;
}
static void * F_30 ( void * V_73 )
{
struct V_74 * V_75 = V_73 ;
struct V_18 * V_76 = V_75 -> V_19 ;
struct V_6 * V_7 = V_75 -> V_7 ;
T_1 V_77 , V_78 ;
unsigned long V_14 , V_55 ;
char V_79 [ 22 ] ;
int V_67 ;
free ( V_75 ) ;
sprintf ( V_79 , L_8 , V_76 -> V_44 ) ;
F_31 ( V_80 , V_79 ) ;
V_67 = F_25 () ;
if ( V_67 < 0 )
return NULL ;
V_81:
V_55 = F_22 ( & V_76 -> V_82 ) ;
F_11 ( V_55 ) ;
V_55 = F_32 ( & V_7 -> V_83 ) ;
F_11 ( V_55 ) ;
V_55 = F_33 ( & V_7 -> V_83 ) ;
F_11 ( V_55 ) ;
V_77 = F_28 ( V_67 ) ;
for ( V_14 = 0 ; V_14 < V_76 -> V_23 ; V_14 ++ ) {
V_76 -> V_28 = V_14 ;
F_20 ( V_7 , V_76 -> V_26 [ V_14 ] ) ;
}
V_78 = F_28 ( V_67 ) ;
V_76 -> V_84 = V_78 - V_77 ;
V_55 = F_22 ( & V_76 -> V_85 ) ;
F_11 ( V_55 ) ;
V_55 = F_32 ( & V_7 -> V_86 ) ;
F_11 ( V_55 ) ;
V_55 = F_33 ( & V_7 -> V_86 ) ;
F_11 ( V_55 ) ;
goto V_81;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_18 * V_19 ;
T_4 V_66 ;
unsigned long V_14 ;
int V_60 ;
V_60 = F_35 ( & V_66 ) ;
F_11 ( V_60 ) ;
V_60 = F_36 ( & V_66 ,
( T_2 ) F_37 ( 16 * 1024 , V_87 ) ) ;
F_11 ( V_60 ) ;
V_60 = F_32 ( & V_7 -> V_83 ) ;
F_11 ( V_60 ) ;
V_60 = F_32 ( & V_7 -> V_86 ) ;
F_11 ( V_60 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
struct V_74 * V_75 = malloc ( sizeof( * V_75 ) ) ;
F_11 ( V_75 == NULL ) ;
V_75 -> V_19 = V_19 = V_7 -> V_48 [ V_14 ] ;
V_75 -> V_7 = V_7 ;
F_15 ( & V_19 -> V_88 , 0 , 0 ) ;
F_15 ( & V_19 -> V_82 , 0 , 0 ) ;
F_15 ( & V_19 -> V_85 , 0 , 0 ) ;
V_19 -> V_28 = 0 ;
V_60 = F_38 ( & V_19 -> V_89 , & V_66 , F_30 , V_75 ) ;
F_11 ( V_60 ) ;
}
}
static void F_39 ( struct V_6 * V_7 )
{
T_1 V_77 , V_78 ;
struct V_18 * V_19 ;
unsigned long V_14 , V_55 ;
V_7 -> V_90 = F_1 () ;
V_7 -> V_84 = 0 ;
F_33 ( & V_7 -> V_86 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
V_55 = F_21 ( & V_19 -> V_82 ) ;
F_11 ( V_55 ) ;
F_15 ( & V_19 -> V_82 , 0 , 0 ) ;
}
V_55 = F_32 ( & V_7 -> V_86 ) ;
F_11 ( V_55 ) ;
V_77 = F_23 () ;
F_33 ( & V_7 -> V_83 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
V_55 = F_21 ( & V_19 -> V_85 ) ;
F_11 ( V_55 ) ;
F_15 ( & V_19 -> V_85 , 0 , 0 ) ;
V_7 -> V_84 += V_19 -> V_84 ;
V_19 -> V_84 = 0 ;
}
V_78 = F_23 () ;
if ( ! V_7 -> V_91 )
V_7 -> V_91 = V_7 -> V_84 ;
V_7 -> V_91 = ( V_7 -> V_91 * 9 + V_7 -> V_84 ) / 10 ;
V_7 -> V_92 = V_78 - V_77 ;
if ( ! V_7 -> V_93 )
V_7 -> V_93 = V_7 -> V_92 ;
V_7 -> V_93 = ( V_7 -> V_93 * 9 +
V_7 -> V_92 ) / 10 ;
V_55 = F_32 ( & V_7 -> V_83 ) ;
F_11 ( V_55 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
F_15 ( & V_19 -> V_88 , 0 , 0 ) ;
V_19 -> V_28 = 0 ;
}
}
static void F_40 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 , V_12 , V_94 , V_95 ;
V_9 = F_1 () ;
F_39 ( V_7 ) ;
V_10 = F_1 () ;
V_12 = V_10 - V_9 ;
V_7 -> V_96 += V_12 ;
V_7 -> V_97 ++ ;
V_94 = V_7 -> V_96 / V_7 -> V_97 ;
if ( V_12 < V_94 )
V_95 = V_94 - V_12 ;
else
V_95 = V_12 - V_94 ;
V_7 -> V_98 += V_95 ;
if ( ! V_7 -> V_99 )
V_7 -> V_99 = V_12 ;
V_7 -> V_99 = ( V_7 -> V_99 * 9 + V_12 ) / 10 ;
printf ( L_9 , V_7 -> V_97 , ( double ) V_12 / 1000000.0 ) ;
printf ( L_10 , ( double ) V_7 -> V_99 / 1e6 ) ;
printf ( L_11 ,
( double ) V_7 -> V_84 / 1e6 , ( double ) V_7 -> V_91 / 1e6 ) ;
#if 0
printf(" [%0.2f / %0.2f]",
(double)sched->parent_cpu_usage/1e6,
(double)sched->runavg_parent_cpu_usage/1e6);
#endif
printf ( L_12 ) ;
if ( V_7 -> V_100 )
printf ( L_13 , V_7 -> V_100 ) ;
V_7 -> V_100 = 0 ;
}
static void F_41 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 ;
V_9 = F_1 () ;
F_3 ( V_7 , 1e6 ) ;
V_10 = F_1 () ;
printf ( L_14 V_15 L_2 , V_10 - V_9 ) ;
V_9 = F_1 () ;
F_4 ( 1e6 ) ;
V_10 = F_1 () ;
printf ( L_15 V_15 L_2 , V_10 - V_9 ) ;
}
static int
F_42 ( struct V_6 * V_7 ,
struct V_101 * V_102 , struct V_103 * V_104 ,
struct V_105 * V_105 V_41 )
{
const char * V_44 = F_43 ( V_102 , V_104 , L_16 ) ;
const T_5 V_43 = F_44 ( V_102 , V_104 , L_17 ) ;
struct V_18 * V_106 , * V_32 ;
if ( V_50 ) {
printf ( L_18 , V_102 ) ;
printf ( L_19 , V_104 -> V_107 , V_44 , V_43 ) ;
}
V_106 = F_17 ( V_7 , V_104 -> V_107 , L_20 ) ;
V_32 = F_17 ( V_7 , V_43 , V_44 ) ;
F_14 ( V_7 , V_106 , V_104 -> time , V_32 ) ;
return 0 ;
}
static int F_45 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 V_41 )
{
const char * V_108 = F_43 ( V_102 , V_104 , L_21 ) ,
* V_109 = F_43 ( V_102 , V_104 , L_22 ) ;
const T_5 V_110 = F_44 ( V_102 , V_104 , L_23 ) ,
V_111 = F_44 ( V_102 , V_104 , L_24 ) ;
const T_1 V_112 = F_44 ( V_102 , V_104 , L_25 ) ;
struct V_18 * V_113 , V_41 * V_114 ;
T_1 V_115 , V_20 = V_104 -> time ;
int V_116 = V_104 -> V_116 ;
T_6 V_12 ;
if ( V_50 )
printf ( L_26 , V_102 ) ;
if ( V_116 >= V_117 || V_116 < 0 )
return 0 ;
V_115 = V_7 -> V_118 [ V_116 ] ;
if ( V_115 )
V_12 = V_20 - V_115 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_27 ( L_27 V_15 L_28 , V_12 ) ;
return - 1 ;
}
F_46 ( L_29 V_15 L_30 ,
V_108 , V_110 , V_109 , V_111 , V_12 ) ;
V_113 = F_17 ( V_7 , V_110 , V_108 ) ;
V_114 = F_17 ( V_7 , V_111 , V_109 ) ;
V_7 -> V_118 [ V_116 ] = V_20 ;
F_13 ( V_7 , V_113 , V_20 , V_12 ) ;
F_16 ( V_7 , V_113 , V_20 , V_112 ) ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 , struct V_101 * V_102 ,
struct V_103 * V_104 )
{
const char * V_119 = F_43 ( V_102 , V_104 , L_31 ) ,
* V_120 = F_43 ( V_102 , V_104 , L_32 ) ;
const T_5 V_121 = F_44 ( V_102 , V_104 , L_33 ) ,
V_122 = F_44 ( V_102 , V_104 , L_34 ) ;
if ( V_50 ) {
printf ( L_35 , V_102 ) ;
printf ( L_36 , V_119 , V_121 ) ;
printf ( L_37 , V_120 , V_122 ) ;
}
F_17 ( V_7 , V_121 , V_119 ) ;
F_17 ( V_7 , V_122 , V_120 ) ;
return 0 ;
}
static int
F_48 ( struct V_123 * V_124 , struct V_125 * V_126 , struct V_125 * V_127 )
{
struct V_128 * V_129 ;
int V_55 = 0 ;
F_11 ( F_49 ( V_124 ) ) ;
F_50 (sort, list, list) {
V_55 = V_129 -> V_130 ( V_126 , V_127 ) ;
if ( V_55 )
return V_55 ;
}
return V_55 ;
}
static struct V_125 *
F_51 ( struct V_131 * V_132 , struct V_89 * V_89 ,
struct V_123 * V_133 )
{
struct V_134 * V_135 = V_132 -> V_134 ;
struct V_125 V_136 = { . V_89 = V_89 } ;
while ( V_135 ) {
struct V_125 * V_26 ;
int V_130 ;
V_26 = F_52 ( V_135 , struct V_125 , V_135 ) ;
V_130 = F_48 ( V_133 , & V_136 , V_26 ) ;
if ( V_130 > 0 )
V_135 = V_135 -> V_137 ;
else if ( V_130 < 0 )
V_135 = V_135 -> V_138 ;
else {
F_11 ( V_89 != V_26 -> V_89 ) ;
return V_26 ;
}
}
return NULL ;
}
static void
F_53 ( struct V_131 * V_132 , struct V_125 * V_139 ,
struct V_123 * V_133 )
{
struct V_134 * * V_140 = & ( V_132 -> V_134 ) , * V_141 = NULL ;
while ( * V_140 ) {
struct V_125 * V_142 ;
int V_130 ;
V_142 = F_52 ( * V_140 , struct V_125 , V_135 ) ;
V_141 = * V_140 ;
V_130 = F_48 ( V_133 , V_139 , V_142 ) ;
if ( V_130 > 0 )
V_140 = & ( ( * V_140 ) -> V_137 ) ;
else
V_140 = & ( ( * V_140 ) -> V_138 ) ;
}
F_54 ( & V_139 -> V_135 , V_141 , V_140 ) ;
F_55 ( & V_139 -> V_135 , V_132 ) ;
}
static int F_56 ( struct V_6 * V_7 , struct V_89 * V_89 )
{
struct V_125 * V_26 = F_10 ( sizeof( * V_26 ) ) ;
if ( ! V_26 ) {
F_27 ( L_38 , V_143 ) ;
return - 1 ;
}
V_26 -> V_89 = V_89 ;
F_57 ( & V_26 -> V_144 ) ;
F_53 ( & V_7 -> V_145 , V_26 , & V_7 -> V_146 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 V_41 ,
struct V_101 * V_102 V_41 ,
struct V_103 * V_104 V_41 )
{
return 0 ;
}
static char F_59 ( T_1 V_112 )
{
const char * V_147 = V_148 ;
return V_147 [ V_112 ] ;
}
static int
F_60 ( struct V_125 * V_26 ,
char V_149 ,
T_1 V_20 )
{
struct V_150 * V_54 = F_10 ( sizeof( * V_54 ) ) ;
if ( ! V_54 ) {
F_27 ( L_39 , V_143 ) ;
return - 1 ;
}
V_54 -> V_151 = V_20 ;
if ( V_149 == 'R' ) {
V_54 -> V_152 = V_153 ;
V_54 -> V_154 = V_54 -> V_151 ;
}
F_61 ( & V_54 -> V_124 , & V_26 -> V_144 ) ;
return 0 ;
}
static void
F_62 ( struct V_125 * V_26 , T_1 V_12 ,
T_1 V_20 V_41 )
{
struct V_150 * V_54 ;
F_11 ( F_49 ( & V_26 -> V_144 ) ) ;
V_54 = F_63 ( V_26 -> V_144 . V_113 , struct V_150 , V_124 ) ;
V_54 -> V_72 += V_12 ;
V_26 -> V_155 += V_12 ;
}
static void
F_64 ( struct V_125 * V_26 , T_1 V_20 )
{
struct V_150 * V_54 ;
T_1 V_12 ;
if ( F_49 ( & V_26 -> V_144 ) )
return;
V_54 = F_63 ( V_26 -> V_144 . V_113 , struct V_150 , V_124 ) ;
if ( V_54 -> V_152 != V_153 )
return;
if ( V_20 < V_54 -> V_154 ) {
V_54 -> V_152 = V_156 ;
return;
}
V_54 -> V_152 = V_157 ;
V_54 -> V_158 = V_20 ;
V_12 = V_54 -> V_158 - V_54 -> V_154 ;
V_26 -> V_159 += V_12 ;
if ( V_12 > V_26 -> V_160 ) {
V_26 -> V_160 = V_12 ;
V_26 -> V_161 = V_20 ;
}
V_26 -> V_162 ++ ;
}
static int F_65 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_110 = F_44 ( V_102 , V_104 , L_23 ) ,
V_111 = F_44 ( V_102 , V_104 , L_24 ) ;
const T_1 V_112 = F_44 ( V_102 , V_104 , L_25 ) ;
struct V_125 * V_163 , * V_164 ;
struct V_89 * V_165 , * V_166 ;
T_1 V_115 , V_20 = V_104 -> time ;
int V_116 = V_104 -> V_116 ;
T_6 V_12 ;
F_11 ( V_116 >= V_117 || V_116 < 0 ) ;
V_115 = V_7 -> V_118 [ V_116 ] ;
V_7 -> V_118 [ V_116 ] = V_20 ;
if ( V_115 )
V_12 = V_20 - V_115 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_27 ( L_27 V_15 L_28 , V_12 ) ;
return - 1 ;
}
V_165 = F_66 ( V_105 , V_110 ) ;
V_166 = F_66 ( V_105 , V_111 ) ;
V_163 = F_51 ( & V_7 -> V_145 , V_165 , & V_7 -> V_146 ) ;
if ( ! V_163 ) {
if ( F_56 ( V_7 , V_165 ) )
return - 1 ;
V_163 = F_51 ( & V_7 -> V_145 , V_165 , & V_7 -> V_146 ) ;
if ( ! V_163 ) {
F_27 ( L_40 ) ;
return - 1 ;
}
}
if ( F_60 ( V_163 , F_59 ( V_112 ) , V_20 ) )
return - 1 ;
V_164 = F_51 ( & V_7 -> V_145 , V_166 , & V_7 -> V_146 ) ;
if ( ! V_164 ) {
if ( F_56 ( V_7 , V_166 ) )
return - 1 ;
V_164 = F_51 ( & V_7 -> V_145 , V_166 , & V_7 -> V_146 ) ;
if ( ! V_164 ) {
F_27 ( L_41 ) ;
return - 1 ;
}
if ( F_60 ( V_164 , 'R' , V_20 ) )
return - 1 ;
}
F_64 ( V_164 , V_20 ) ;
return 0 ;
}
static int F_67 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_43 = F_44 ( V_102 , V_104 , L_17 ) ;
const T_1 V_72 = F_44 ( V_102 , V_104 , L_42 ) ;
struct V_89 * V_89 = F_66 ( V_105 , V_43 ) ;
struct V_125 * V_26 = F_51 ( & V_7 -> V_145 , V_89 , & V_7 -> V_146 ) ;
T_1 V_20 = V_104 -> time ;
int V_116 = V_104 -> V_116 ;
F_11 ( V_116 >= V_117 || V_116 < 0 ) ;
if ( ! V_26 ) {
if ( F_56 ( V_7 , V_89 ) )
return - 1 ;
V_26 = F_51 ( & V_7 -> V_145 , V_89 , & V_7 -> V_146 ) ;
if ( ! V_26 ) {
F_27 ( L_41 ) ;
return - 1 ;
}
if ( F_60 ( V_26 , 'R' , V_20 ) )
return - 1 ;
}
F_62 ( V_26 , V_72 , V_20 ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_43 = F_44 ( V_102 , V_104 , L_17 ) ,
V_167 = F_44 ( V_102 , V_104 , L_43 ) ;
struct V_125 * V_26 ;
struct V_150 * V_54 ;
struct V_89 * V_32 ;
T_1 V_20 = V_104 -> time ;
if ( ! V_167 )
return 0 ;
V_32 = F_66 ( V_105 , V_43 ) ;
V_26 = F_51 ( & V_7 -> V_145 , V_32 , & V_7 -> V_146 ) ;
if ( ! V_26 ) {
if ( F_56 ( V_7 , V_32 ) )
return - 1 ;
V_26 = F_51 ( & V_7 -> V_145 , V_32 , & V_7 -> V_146 ) ;
if ( ! V_26 ) {
F_27 ( L_44 ) ;
return - 1 ;
}
if ( F_60 ( V_26 , 'S' , V_20 ) )
return - 1 ;
}
F_11 ( F_49 ( & V_26 -> V_144 ) ) ;
V_54 = F_63 ( V_26 -> V_144 . V_113 , struct V_150 , V_124 ) ;
if ( V_7 -> V_168 == - 1 && V_54 -> V_152 != V_169 )
V_7 -> V_170 ++ ;
V_7 -> V_171 ++ ;
if ( V_54 -> V_151 > V_20 ) {
V_7 -> V_172 ++ ;
return 0 ;
}
V_54 -> V_152 = V_153 ;
V_54 -> V_154 = V_20 ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_43 = F_44 ( V_102 , V_104 , L_17 ) ;
T_1 V_20 = V_104 -> time ;
struct V_125 * V_26 ;
struct V_150 * V_54 ;
struct V_89 * V_173 ;
if ( V_7 -> V_168 == - 1 )
return 0 ;
V_173 = F_66 ( V_105 , V_43 ) ;
V_26 = F_51 ( & V_7 -> V_145 , V_173 , & V_7 -> V_146 ) ;
if ( ! V_26 ) {
if ( F_56 ( V_7 , V_173 ) )
return - 1 ;
F_17 ( V_7 , V_173 -> V_43 , V_173 -> V_44 ) ;
V_26 = F_51 ( & V_7 -> V_145 , V_173 , & V_7 -> V_146 ) ;
if ( ! V_26 ) {
F_27 ( L_45 ) ;
return - 1 ;
}
if ( F_60 ( V_26 , 'R' , V_20 ) )
return - 1 ;
}
F_11 ( F_49 ( & V_26 -> V_144 ) ) ;
V_54 = F_63 ( V_26 -> V_144 . V_113 , struct V_150 , V_124 ) ;
V_54 -> V_158 = V_54 -> V_151 = V_54 -> V_154 = V_20 ;
V_7 -> V_171 ++ ;
if ( V_54 -> V_151 > V_20 )
V_7 -> V_172 ++ ;
return 0 ;
}
static void F_70 ( struct V_6 * V_7 , struct V_125 * V_144 )
{
int V_14 ;
int V_55 ;
T_1 V_174 ;
if ( ! V_144 -> V_162 )
return;
if ( ! strcmp ( V_144 -> V_89 -> V_44 , L_46 ) )
return;
V_7 -> V_175 += V_144 -> V_155 ;
V_7 -> V_176 += V_144 -> V_162 ;
V_55 = printf ( L_47 , V_144 -> V_89 -> V_44 , V_144 -> V_89 -> V_43 ) ;
for ( V_14 = 0 ; V_14 < 24 - V_55 ; V_14 ++ )
printf ( L_48 ) ;
V_174 = V_144 -> V_159 / V_144 -> V_162 ;
printf ( L_49 V_15 L_50 ,
( double ) V_144 -> V_155 / 1e6 ,
V_144 -> V_162 , ( double ) V_174 / 1e6 ,
( double ) V_144 -> V_160 / 1e6 ,
( double ) V_144 -> V_161 / 1e9 ) ;
}
static int F_71 ( struct V_125 * V_126 , struct V_125 * V_127 )
{
if ( V_126 -> V_89 -> V_43 < V_127 -> V_89 -> V_43 )
return - 1 ;
if ( V_126 -> V_89 -> V_43 > V_127 -> V_89 -> V_43 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_125 * V_126 , struct V_125 * V_127 )
{
T_1 V_177 , V_178 ;
if ( ! V_126 -> V_162 )
return - 1 ;
if ( ! V_127 -> V_162 )
return 1 ;
V_177 = V_126 -> V_159 / V_126 -> V_162 ;
V_178 = V_127 -> V_159 / V_127 -> V_162 ;
if ( V_177 < V_178 )
return - 1 ;
if ( V_177 > V_178 )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_125 * V_126 , struct V_125 * V_127 )
{
if ( V_126 -> V_160 < V_127 -> V_160 )
return - 1 ;
if ( V_126 -> V_160 > V_127 -> V_160 )
return 1 ;
return 0 ;
}
static int F_74 ( struct V_125 * V_126 , struct V_125 * V_127 )
{
if ( V_126 -> V_162 < V_127 -> V_162 )
return - 1 ;
if ( V_126 -> V_162 > V_127 -> V_162 )
return 1 ;
return 0 ;
}
static int F_75 ( struct V_125 * V_126 , struct V_125 * V_127 )
{
if ( V_126 -> V_155 < V_127 -> V_155 )
return - 1 ;
if ( V_126 -> V_155 > V_127 -> V_155 )
return 1 ;
return 0 ;
}
static int F_76 ( const char * V_179 , struct V_123 * V_124 )
{
T_2 V_14 ;
static struct V_128 V_180 = {
. V_181 = L_51 ,
. V_130 = F_72 ,
} ;
static struct V_128 V_182 = {
. V_181 = L_52 ,
. V_130 = F_73 ,
} ;
static struct V_128 V_183 = {
. V_181 = L_17 ,
. V_130 = F_71 ,
} ;
static struct V_128 V_184 = {
. V_181 = L_42 ,
. V_130 = F_75 ,
} ;
static struct V_128 V_185 = {
. V_181 = L_53 ,
. V_130 = F_74 ,
} ;
struct V_128 * V_186 [] = {
& V_183 ,
& V_180 ,
& V_182 ,
& V_185 ,
& V_184 ,
} ;
for ( V_14 = 0 ; V_14 < F_77 ( V_186 ) ; V_14 ++ ) {
if ( ! strcmp ( V_186 [ V_14 ] -> V_181 , V_179 ) ) {
F_61 ( & V_186 [ V_14 ] -> V_124 , V_124 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_78 ( struct V_6 * V_7 )
{
struct V_134 * V_135 ;
for (; ; ) {
struct V_125 * V_139 ;
V_135 = F_79 ( & V_7 -> V_145 ) ;
if ( ! V_135 )
break;
F_80 ( V_135 , & V_7 -> V_145 ) ;
V_139 = F_81 ( V_135 , struct V_125 , V_135 ) ;
F_53 ( & V_7 -> V_187 , V_139 , & V_7 -> V_133 ) ;
}
}
static int F_82 ( struct V_188 * V_189 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_52 ( V_189 , struct V_6 , V_189 ) ;
if ( V_7 -> V_190 -> V_191 )
return V_7 -> V_190 -> V_191 ( V_7 , V_102 , V_104 , V_105 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_7 , struct V_101 * V_102 ,
struct V_103 * V_104 , struct V_105 * V_105 )
{
const T_5 V_110 = F_44 ( V_102 , V_104 , L_23 ) ,
V_111 = F_44 ( V_102 , V_104 , L_24 ) ;
struct V_89 * V_165 V_41 , * V_166 ;
int V_192 ;
T_1 V_115 , V_20 = V_104 -> time ;
T_6 V_12 ;
int V_116 , V_193 = V_104 -> V_116 ;
F_11 ( V_193 >= V_117 || V_193 < 0 ) ;
if ( V_193 > V_7 -> V_194 )
V_7 -> V_194 = V_193 ;
V_115 = V_7 -> V_118 [ V_193 ] ;
V_7 -> V_118 [ V_193 ] = V_20 ;
if ( V_115 )
V_12 = V_20 - V_115 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_27 ( L_27 V_15 L_28 , V_12 ) ;
return - 1 ;
}
V_165 = F_66 ( V_105 , V_110 ) ;
V_166 = F_66 ( V_105 , V_111 ) ;
V_7 -> V_195 [ V_193 ] = V_166 ;
printf ( L_54 ) ;
V_192 = 0 ;
if ( ! V_166 -> V_196 [ 0 ] ) {
V_166 -> V_196 [ 0 ] = V_7 -> V_197 ;
V_166 -> V_196 [ 1 ] = V_7 -> V_198 ;
if ( V_7 -> V_197 < 'Z' ) {
V_7 -> V_197 ++ ;
} else {
V_7 -> V_197 = 'A' ;
if ( V_7 -> V_198 < '9' ) {
V_7 -> V_198 ++ ;
} else {
V_7 -> V_198 = '0' ;
}
}
V_192 = 1 ;
}
for ( V_116 = 0 ; V_116 <= V_7 -> V_194 ; V_116 ++ ) {
if ( V_116 != V_193 )
printf ( L_48 ) ;
else
printf ( L_55 ) ;
if ( V_7 -> V_195 [ V_116 ] ) {
if ( V_7 -> V_195 [ V_116 ] -> V_43 )
printf ( L_56 , V_7 -> V_195 [ V_116 ] -> V_196 ) ;
else
printf ( L_57 ) ;
} else
printf ( L_58 ) ;
}
printf ( L_59 , ( double ) V_20 / 1e9 ) ;
if ( V_192 ) {
printf ( L_60 ,
V_166 -> V_196 , V_166 -> V_44 , V_166 -> V_43 ) ;
} else {
printf ( L_12 ) ;
}
return 0 ;
}
static int F_84 ( struct V_188 * V_189 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_52 ( V_189 , struct V_6 , V_189 ) ;
int V_193 = V_104 -> V_116 , V_60 = 0 ;
T_5 V_110 = F_44 ( V_102 , V_104 , L_23 ) ,
V_111 = F_44 ( V_102 , V_104 , L_24 ) ;
if ( V_7 -> V_199 [ V_193 ] != ( T_5 ) - 1 ) {
if ( V_7 -> V_199 [ V_193 ] != V_110 )
V_7 -> V_200 ++ ;
}
if ( V_7 -> V_190 -> V_201 )
V_60 = V_7 -> V_190 -> V_201 ( V_7 , V_102 , V_104 , V_105 ) ;
V_7 -> V_199 [ V_193 ] = V_111 ;
return V_60 ;
}
static int F_85 ( struct V_188 * V_189 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_52 ( V_189 , struct V_6 , V_189 ) ;
if ( V_7 -> V_190 -> V_202 )
return V_7 -> V_190 -> V_202 ( V_7 , V_102 , V_104 , V_105 ) ;
return 0 ;
}
static int F_86 ( struct V_188 * V_189 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 V_41 )
{
struct V_6 * V_7 = F_52 ( V_189 , struct V_6 , V_189 ) ;
if ( V_7 -> V_190 -> V_203 )
return V_7 -> V_190 -> V_203 ( V_7 , V_102 , V_104 ) ;
return 0 ;
}
static int F_87 ( struct V_188 * V_189 V_41 ,
struct V_101 * V_102 ,
struct V_103 * V_104 V_41 ,
struct V_105 * V_105 V_41 )
{
F_46 ( L_61 , V_102 ) ;
return 0 ;
}
static int F_88 ( struct V_188 * V_189 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_52 ( V_189 , struct V_6 , V_189 ) ;
if ( V_7 -> V_190 -> V_204 )
return V_7 -> V_190 -> V_204 ( V_7 , V_102 , V_104 , V_105 ) ;
return 0 ;
}
static int F_89 ( struct V_188 * V_189 V_41 ,
union V_205 * V_21 V_41 ,
struct V_103 * V_104 ,
struct V_101 * V_102 ,
struct V_105 * V_105 )
{
struct V_89 * V_89 = F_66 ( V_105 , V_104 -> V_107 ) ;
int V_60 = 0 ;
if ( V_89 == NULL ) {
F_46 ( L_62 ,
F_90 ( V_102 ) ) ;
return - 1 ;
}
V_102 -> V_206 . V_207 . V_208 += V_104 -> V_209 ;
F_91 ( & V_102 -> V_206 , V_210 ) ;
if ( V_102 -> V_211 . V_212 != NULL ) {
T_7 V_213 = V_102 -> V_211 . V_212 ;
V_60 = V_213 ( V_189 , V_102 , V_104 , V_105 ) ;
}
return V_60 ;
}
static int F_92 ( struct V_6 * V_7 , bool V_214 ,
struct V_215 * * V_216 )
{
const struct V_217 V_218 [] = {
{ L_63 , F_84 , } ,
{ L_64 , F_85 , } ,
{ L_65 , F_82 , } ,
{ L_66 , F_82 , } ,
{ L_67 , F_86 , } ,
{ L_68 , F_87 , } ,
{ L_69 , F_88 , } ,
} ;
struct V_215 * V_219 ;
V_219 = F_93 ( V_220 , V_221 , 0 , false , & V_7 -> V_189 ) ;
if ( V_219 == NULL ) {
F_46 ( L_70 ) ;
return - 1 ;
}
if ( F_94 ( V_219 , V_218 ) )
goto V_222;
if ( F_95 ( V_219 , L_71 ) ) {
int V_60 = F_96 ( V_219 , & V_7 -> V_189 ) ;
if ( V_60 ) {
F_27 ( L_72 , V_60 ) ;
goto V_222;
}
V_7 -> V_23 = V_219 -> V_207 . V_23 [ 0 ] ;
V_7 -> V_223 = V_219 -> V_207 . V_224 ;
V_7 -> V_225 = V_219 -> V_207 . V_23 [ V_226 ] ;
}
if ( V_214 )
F_97 ( V_219 ) ;
if ( V_216 )
* V_216 = V_219 ;
return 0 ;
V_222:
F_97 ( V_219 ) ;
return - 1 ;
}
static void F_98 ( struct V_6 * V_7 )
{
if ( V_7 -> V_172 && V_7 -> V_171 ) {
printf ( L_73 ,
( double ) V_7 -> V_172 / ( double ) V_7 -> V_171 * 100.0 ,
V_7 -> V_172 , V_7 -> V_171 ) ;
}
if ( V_7 -> V_223 && V_7 -> V_23 ) {
printf ( L_74 ,
( double ) V_7 -> V_223 / ( double ) V_7 -> V_23 * 100.0 ,
V_7 -> V_223 , V_7 -> V_23 , V_7 -> V_225 ) ;
}
if ( V_7 -> V_170 && V_7 -> V_171 ) {
printf ( L_75 ,
( double ) V_7 -> V_170 / ( double ) V_7 -> V_171 * 100.0 ,
V_7 -> V_170 , V_7 -> V_171 ) ;
if ( V_7 -> V_223 )
printf ( L_76 ) ;
printf ( L_12 ) ;
}
if ( V_7 -> V_200 && V_7 -> V_171 ) {
printf ( L_77 ,
( double ) V_7 -> V_200 / ( double ) V_7 -> V_171 * 100.0 ,
V_7 -> V_200 , V_7 -> V_171 ) ;
if ( V_7 -> V_223 )
printf ( L_76 ) ;
printf ( L_12 ) ;
}
}
static int F_99 ( struct V_6 * V_7 )
{
struct V_134 * V_114 ;
struct V_215 * V_219 ;
F_100 () ;
if ( F_92 ( V_7 , false , & V_219 ) )
return - 1 ;
F_78 ( V_7 ) ;
printf ( L_78 ) ;
printf ( L_79 ) ;
printf ( L_80 ) ;
V_114 = F_79 ( & V_7 -> V_187 ) ;
while ( V_114 ) {
struct V_125 * V_144 ;
V_144 = F_81 ( V_114 , struct V_125 , V_135 ) ;
F_70 ( V_7 , V_144 ) ;
V_114 = F_101 ( V_114 ) ;
}
printf ( L_81 ) ;
printf ( L_82 V_15 L_83 ,
( double ) V_7 -> V_175 / 1e6 , V_7 -> V_176 ) ;
printf ( L_84 ) ;
F_98 ( V_7 ) ;
printf ( L_12 ) ;
F_97 ( V_219 ) ;
return 0 ;
}
static int F_102 ( struct V_6 * V_7 )
{
V_7 -> V_194 = F_103 ( V_227 ) ;
F_100 () ;
if ( F_92 ( V_7 , true , NULL ) )
return - 1 ;
F_98 ( V_7 ) ;
return 0 ;
}
static int F_104 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_6 ( V_7 ) ;
F_8 ( V_7 ) ;
F_41 ( V_7 ) ;
if ( F_92 ( V_7 , true , NULL ) )
return - 1 ;
printf ( L_85 , V_7 -> V_31 ) ;
printf ( L_86 , V_7 -> V_42 ) ;
printf ( L_87 , V_7 -> V_40 ) ;
if ( V_7 -> V_36 )
printf ( L_88 , V_7 -> V_36 ) ;
if ( V_7 -> V_38 )
printf ( L_89 , V_7 -> V_38 ) ;
if ( V_7 -> V_30 )
printf ( L_90 ,
V_7 -> V_30 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
F_34 ( V_7 ) ;
printf ( L_91 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_228 ; V_14 ++ )
F_40 ( V_7 ) ;
return 0 ;
}
static void F_105 ( struct V_6 * V_7 , const struct V_229 * V_230 ,
const char * const V_231 [] )
{
char * V_232 , * V_179 , * V_147 = F_106 ( V_7 -> V_233 ) ;
for ( V_179 = strtok_r ( V_147 , L_92 , & V_232 ) ;
V_179 ; V_179 = strtok_r ( NULL , L_92 , & V_232 ) ) {
if ( F_76 ( V_179 , & V_7 -> V_133 ) < 0 ) {
error ( L_93 , V_179 ) ;
F_107 ( V_231 , V_230 ) ;
}
}
free ( V_147 ) ;
F_76 ( L_17 , & V_7 -> V_146 ) ;
}
static int F_108 ( int V_234 , const char * * V_235 )
{
unsigned int V_236 , V_14 , V_53 ;
const char * * V_237 ;
const char * const V_238 [] = {
L_94 ,
L_95 ,
L_96 ,
L_97 , L_98 ,
L_99 , L_100 ,
L_101 , L_63 ,
L_101 , L_102 ,
L_101 , L_103 ,
L_101 , L_104 ,
L_101 , L_64 ,
L_101 , L_68 ,
L_101 , L_67 ,
L_101 , L_65 ,
L_101 , L_69 ,
} ;
V_236 = F_77 ( V_238 ) + V_234 - 1 ;
V_237 = calloc ( V_236 + 1 , sizeof( char * ) ) ;
if ( V_237 == NULL )
return - V_239 ;
for ( V_14 = 0 ; V_14 < F_77 ( V_238 ) ; V_14 ++ )
V_237 [ V_14 ] = F_106 ( V_238 [ V_14 ] ) ;
for ( V_53 = 1 ; V_53 < ( unsigned int ) V_234 ; V_53 ++ , V_14 ++ )
V_237 [ V_14 ] = V_235 [ V_53 ] ;
F_11 ( V_14 != V_236 ) ;
return F_109 ( V_14 , V_237 , NULL ) ;
}
int F_110 ( int V_234 , const char * * V_235 , const char * T_8 V_41 )
{
const char V_240 [] = L_105 ;
struct V_6 V_7 = {
. V_189 = {
. V_104 = F_89 ,
. V_44 = V_241 ,
. V_242 = V_243 ,
. V_244 = V_245 ,
. V_246 = true ,
} ,
. V_146 = F_111 ( V_7 . V_146 ) ,
. V_133 = F_111 ( V_7 . V_133 ) ,
. V_83 = V_247 ,
. V_86 = V_247 ,
. V_199 = { [ 0 ... V_117 - 1 ] = - 1 } ,
. V_233 = V_240 ,
. V_228 = 10 ,
. V_168 = - 1 ,
. V_197 = 'A' ,
. V_198 = '0' ,
} ;
const struct V_229 V_248 [] = {
F_112 ( 's' , L_106 , & V_7 . V_233 , L_107 ,
L_108 ) ,
F_113 ( 'v' , L_109 , & V_50 ,
L_110 ) ,
F_114 ( 'C' , L_111 , & V_7 . V_168 ,
L_112 ) ,
F_115 ( 'D' , L_113 , & V_249 ,
L_114 ) ,
F_116 ()
} ;
const struct V_229 V_250 [] = {
F_117 ( 'r' , L_115 , & V_7 . V_228 ,
L_116 ) ,
F_113 ( 'v' , L_109 , & V_50 ,
L_110 ) ,
F_115 ( 'D' , L_113 , & V_249 ,
L_114 ) ,
F_116 ()
} ;
const struct V_229 V_251 [] = {
F_112 ( 'i' , L_117 , & V_220 , L_118 ,
L_119 ) ,
F_113 ( 'v' , L_109 , & V_50 ,
L_110 ) ,
F_115 ( 'D' , L_113 , & V_249 ,
L_114 ) ,
F_116 ()
} ;
const char * const V_252 [] = {
L_120 ,
NULL
} ;
const char * const V_253 [] = {
L_121 ,
NULL
} ;
const char * const V_254 [] = {
L_122 ,
NULL
} ;
struct V_255 V_256 = {
. V_191 = F_68 ,
. V_201 = F_65 ,
. V_202 = F_67 ,
. V_203 = F_58 ,
. V_204 = F_69 ,
} ;
struct V_255 V_257 = {
. V_201 = F_83 ,
} ;
struct V_255 V_258 = {
. V_191 = F_42 ,
. V_201 = F_45 ,
. V_203 = F_47 ,
} ;
V_234 = F_118 ( V_234 , V_235 , V_251 , V_254 ,
V_259 ) ;
if ( ! V_234 )
F_107 ( V_254 , V_251 ) ;
if ( ! strcmp ( V_235 [ 0 ] , L_123 ) )
return F_119 ( V_234 , V_235 , T_8 ) ;
F_120 () ;
if ( ! strncmp ( V_235 [ 0 ] , L_124 , 3 ) ) {
return F_108 ( V_234 , V_235 ) ;
} else if ( ! strncmp ( V_235 [ 0 ] , L_125 , 3 ) ) {
V_7 . V_190 = & V_256 ;
if ( V_234 > 1 ) {
V_234 = F_118 ( V_234 , V_235 , V_248 , V_252 , 0 ) ;
if ( V_234 )
F_107 ( V_252 , V_248 ) ;
}
F_105 ( & V_7 , V_248 , V_252 ) ;
return F_99 ( & V_7 ) ;
} else if ( ! strcmp ( V_235 [ 0 ] , L_126 ) ) {
V_7 . V_190 = & V_257 ;
F_105 ( & V_7 , V_248 , V_252 ) ;
return F_102 ( & V_7 ) ;
} else if ( ! strncmp ( V_235 [ 0 ] , L_127 , 3 ) ) {
V_7 . V_190 = & V_258 ;
if ( V_234 ) {
V_234 = F_118 ( V_234 , V_235 , V_250 , V_253 , 0 ) ;
if ( V_234 )
F_107 ( V_253 , V_250 ) ;
}
return F_104 ( & V_7 ) ;
} else {
F_107 ( V_254 , V_251 ) ;
}
return 0 ;
}
