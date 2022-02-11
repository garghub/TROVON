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
F_31 ( & V_75 ) ;
sprintf ( V_79 , L_8 , V_76 -> V_44 ) ;
F_32 ( V_80 , V_79 ) ;
V_67 = F_25 () ;
if ( V_67 < 0 )
return NULL ;
V_81:
V_55 = F_22 ( & V_76 -> V_82 ) ;
F_11 ( V_55 ) ;
V_55 = F_33 ( & V_7 -> V_83 ) ;
F_11 ( V_55 ) ;
V_55 = F_34 ( & V_7 -> V_83 ) ;
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
V_55 = F_33 ( & V_7 -> V_86 ) ;
F_11 ( V_55 ) ;
V_55 = F_34 ( & V_7 -> V_86 ) ;
F_11 ( V_55 ) ;
goto V_81;
}
static void F_35 ( struct V_6 * V_7 )
{
struct V_18 * V_19 ;
T_4 V_66 ;
unsigned long V_14 ;
int V_60 ;
V_60 = F_36 ( & V_66 ) ;
F_11 ( V_60 ) ;
V_60 = F_37 ( & V_66 ,
( T_2 ) F_38 ( 16 * 1024 , V_87 ) ) ;
F_11 ( V_60 ) ;
V_60 = F_33 ( & V_7 -> V_83 ) ;
F_11 ( V_60 ) ;
V_60 = F_33 ( & V_7 -> V_86 ) ;
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
V_60 = F_39 ( & V_19 -> V_89 , & V_66 , F_30 , V_75 ) ;
F_11 ( V_60 ) ;
}
}
static void F_40 ( struct V_6 * V_7 )
{
T_1 V_77 , V_78 ;
struct V_18 * V_19 ;
unsigned long V_14 , V_55 ;
V_7 -> V_90 = F_1 () ;
V_7 -> V_84 = 0 ;
F_34 ( & V_7 -> V_86 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
V_55 = F_21 ( & V_19 -> V_82 ) ;
F_11 ( V_55 ) ;
F_15 ( & V_19 -> V_82 , 0 , 0 ) ;
}
V_55 = F_33 ( & V_7 -> V_86 ) ;
F_11 ( V_55 ) ;
V_77 = F_23 () ;
F_34 ( & V_7 -> V_83 ) ;
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
V_55 = F_33 ( & V_7 -> V_83 ) ;
F_11 ( V_55 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
F_15 ( & V_19 -> V_88 , 0 , 0 ) ;
V_19 -> V_28 = 0 ;
}
}
static void F_41 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 , V_12 , V_94 , V_95 ;
V_9 = F_1 () ;
F_40 ( V_7 ) ;
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
static void F_42 ( struct V_6 * V_7 )
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
F_43 ( struct V_6 * V_7 ,
struct V_101 * V_102 , struct V_103 * V_104 ,
struct V_105 * V_105 V_41 )
{
const char * V_44 = F_44 ( V_102 , V_104 , L_16 ) ;
const T_5 V_43 = F_45 ( V_102 , V_104 , L_17 ) ;
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
static int F_46 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 V_41 )
{
const char * V_108 = F_44 ( V_102 , V_104 , L_21 ) ,
* V_109 = F_44 ( V_102 , V_104 , L_22 ) ;
const T_5 V_110 = F_45 ( V_102 , V_104 , L_23 ) ,
V_111 = F_45 ( V_102 , V_104 , L_24 ) ;
const T_1 V_112 = F_45 ( V_102 , V_104 , L_25 ) ;
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
F_47 ( L_29 V_15 L_30 ,
V_108 , V_110 , V_109 , V_111 , V_12 ) ;
V_113 = F_17 ( V_7 , V_110 , V_108 ) ;
V_114 = F_17 ( V_7 , V_111 , V_109 ) ;
V_7 -> V_118 [ V_116 ] = V_20 ;
F_13 ( V_7 , V_113 , V_20 , V_12 ) ;
F_16 ( V_7 , V_113 , V_20 , V_112 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
union V_119 * V_21 ,
struct V_105 * V_105 )
{
struct V_89 * V_120 , * V_121 ;
V_120 = F_49 ( V_105 , V_21 -> V_122 . V_43 ,
V_21 -> V_122 . V_107 ) ;
V_121 = F_49 ( V_105 , V_21 -> V_122 . V_123 ,
V_21 -> V_122 . V_124 ) ;
if ( V_120 == NULL || V_121 == NULL ) {
F_47 ( L_31 ,
V_120 , V_121 ) ;
return 0 ;
}
if ( V_50 ) {
printf ( L_32 ) ;
printf ( L_33 , F_50 ( V_121 ) , V_121 -> V_107 ) ;
printf ( L_34 , F_50 ( V_120 ) , V_120 -> V_107 ) ;
}
F_17 ( V_7 , V_121 -> V_107 , F_50 ( V_121 ) ) ;
F_17 ( V_7 , V_120 -> V_107 , F_50 ( V_120 ) ) ;
return 0 ;
}
static int
F_51 ( struct V_125 * V_126 , struct V_127 * V_128 , struct V_127 * V_129 )
{
struct V_130 * V_131 ;
int V_55 = 0 ;
F_11 ( F_52 ( V_126 ) ) ;
F_53 (sort, list, list) {
V_55 = V_131 -> V_132 ( V_128 , V_129 ) ;
if ( V_55 )
return V_55 ;
}
return V_55 ;
}
static struct V_127 *
F_54 ( struct V_133 * V_134 , struct V_89 * V_89 ,
struct V_125 * V_135 )
{
struct V_136 * V_137 = V_134 -> V_136 ;
struct V_127 V_138 = { . V_89 = V_89 } ;
while ( V_137 ) {
struct V_127 * V_26 ;
int V_132 ;
V_26 = F_55 ( V_137 , struct V_127 , V_137 ) ;
V_132 = F_51 ( V_135 , & V_138 , V_26 ) ;
if ( V_132 > 0 )
V_137 = V_137 -> V_139 ;
else if ( V_132 < 0 )
V_137 = V_137 -> V_140 ;
else {
F_11 ( V_89 != V_26 -> V_89 ) ;
return V_26 ;
}
}
return NULL ;
}
static void
F_56 ( struct V_133 * V_134 , struct V_127 * V_141 ,
struct V_125 * V_135 )
{
struct V_136 * * V_142 = & ( V_134 -> V_136 ) , * V_121 = NULL ;
while ( * V_142 ) {
struct V_127 * V_143 ;
int V_132 ;
V_143 = F_55 ( * V_142 , struct V_127 , V_137 ) ;
V_121 = * V_142 ;
V_132 = F_51 ( V_135 , V_141 , V_143 ) ;
if ( V_132 > 0 )
V_142 = & ( ( * V_142 ) -> V_139 ) ;
else
V_142 = & ( ( * V_142 ) -> V_140 ) ;
}
F_57 ( & V_141 -> V_137 , V_121 , V_142 ) ;
F_58 ( & V_141 -> V_137 , V_134 ) ;
}
static int F_59 ( struct V_6 * V_7 , struct V_89 * V_89 )
{
struct V_127 * V_26 = F_10 ( sizeof( * V_26 ) ) ;
if ( ! V_26 ) {
F_27 ( L_35 , V_144 ) ;
return - 1 ;
}
V_26 -> V_89 = V_89 ;
F_60 ( & V_26 -> V_145 ) ;
F_56 ( & V_7 -> V_146 , V_26 , & V_7 -> V_147 ) ;
return 0 ;
}
static char F_61 ( T_1 V_112 )
{
const char * V_148 = V_149 ;
return V_148 [ V_112 ] ;
}
static int
F_62 ( struct V_127 * V_26 ,
char V_150 ,
T_1 V_20 )
{
struct V_151 * V_54 = F_10 ( sizeof( * V_54 ) ) ;
if ( ! V_54 ) {
F_27 ( L_36 , V_144 ) ;
return - 1 ;
}
V_54 -> V_152 = V_20 ;
if ( V_150 == 'R' ) {
V_54 -> V_153 = V_154 ;
V_54 -> V_155 = V_54 -> V_152 ;
}
F_63 ( & V_54 -> V_126 , & V_26 -> V_145 ) ;
return 0 ;
}
static void
F_64 ( struct V_127 * V_26 , T_1 V_12 ,
T_1 V_20 V_41 )
{
struct V_151 * V_54 ;
F_11 ( F_52 ( & V_26 -> V_145 ) ) ;
V_54 = F_65 ( V_26 -> V_145 . V_113 , struct V_151 , V_126 ) ;
V_54 -> V_72 += V_12 ;
V_26 -> V_156 += V_12 ;
}
static void
F_66 ( struct V_127 * V_26 , T_1 V_20 )
{
struct V_151 * V_54 ;
T_1 V_12 ;
if ( F_52 ( & V_26 -> V_145 ) )
return;
V_54 = F_65 ( V_26 -> V_145 . V_113 , struct V_151 , V_126 ) ;
if ( V_54 -> V_153 != V_154 )
return;
if ( V_20 < V_54 -> V_155 ) {
V_54 -> V_153 = V_157 ;
return;
}
V_54 -> V_153 = V_158 ;
V_54 -> V_159 = V_20 ;
V_12 = V_54 -> V_159 - V_54 -> V_155 ;
V_26 -> V_160 += V_12 ;
if ( V_12 > V_26 -> V_161 ) {
V_26 -> V_161 = V_12 ;
V_26 -> V_162 = V_20 ;
}
V_26 -> V_163 ++ ;
}
static int F_67 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_110 = F_45 ( V_102 , V_104 , L_23 ) ,
V_111 = F_45 ( V_102 , V_104 , L_24 ) ;
const T_1 V_112 = F_45 ( V_102 , V_104 , L_25 ) ;
struct V_127 * V_164 , * V_165 ;
struct V_89 * V_166 , * V_167 ;
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
V_166 = F_49 ( V_105 , 0 , V_110 ) ;
V_167 = F_49 ( V_105 , 0 , V_111 ) ;
V_164 = F_54 ( & V_7 -> V_146 , V_166 , & V_7 -> V_147 ) ;
if ( ! V_164 ) {
if ( F_59 ( V_7 , V_166 ) )
return - 1 ;
V_164 = F_54 ( & V_7 -> V_146 , V_166 , & V_7 -> V_147 ) ;
if ( ! V_164 ) {
F_27 ( L_37 ) ;
return - 1 ;
}
}
if ( F_62 ( V_164 , F_61 ( V_112 ) , V_20 ) )
return - 1 ;
V_165 = F_54 ( & V_7 -> V_146 , V_167 , & V_7 -> V_147 ) ;
if ( ! V_165 ) {
if ( F_59 ( V_7 , V_167 ) )
return - 1 ;
V_165 = F_54 ( & V_7 -> V_146 , V_167 , & V_7 -> V_147 ) ;
if ( ! V_165 ) {
F_27 ( L_38 ) ;
return - 1 ;
}
if ( F_62 ( V_165 , 'R' , V_20 ) )
return - 1 ;
}
F_66 ( V_165 , V_20 ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_43 = F_45 ( V_102 , V_104 , L_17 ) ;
const T_1 V_72 = F_45 ( V_102 , V_104 , L_39 ) ;
struct V_89 * V_89 = F_49 ( V_105 , 0 , V_43 ) ;
struct V_127 * V_26 = F_54 ( & V_7 -> V_146 , V_89 , & V_7 -> V_147 ) ;
T_1 V_20 = V_104 -> time ;
int V_116 = V_104 -> V_116 ;
F_11 ( V_116 >= V_117 || V_116 < 0 ) ;
if ( ! V_26 ) {
if ( F_59 ( V_7 , V_89 ) )
return - 1 ;
V_26 = F_54 ( & V_7 -> V_146 , V_89 , & V_7 -> V_147 ) ;
if ( ! V_26 ) {
F_27 ( L_38 ) ;
return - 1 ;
}
if ( F_62 ( V_26 , 'R' , V_20 ) )
return - 1 ;
}
F_64 ( V_26 , V_72 , V_20 ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_43 = F_45 ( V_102 , V_104 , L_17 ) ,
V_168 = F_45 ( V_102 , V_104 , L_40 ) ;
struct V_127 * V_26 ;
struct V_151 * V_54 ;
struct V_89 * V_32 ;
T_1 V_20 = V_104 -> time ;
if ( ! V_168 )
return 0 ;
V_32 = F_49 ( V_105 , 0 , V_43 ) ;
V_26 = F_54 ( & V_7 -> V_146 , V_32 , & V_7 -> V_147 ) ;
if ( ! V_26 ) {
if ( F_59 ( V_7 , V_32 ) )
return - 1 ;
V_26 = F_54 ( & V_7 -> V_146 , V_32 , & V_7 -> V_147 ) ;
if ( ! V_26 ) {
F_27 ( L_41 ) ;
return - 1 ;
}
if ( F_62 ( V_26 , 'S' , V_20 ) )
return - 1 ;
}
F_11 ( F_52 ( & V_26 -> V_145 ) ) ;
V_54 = F_65 ( V_26 -> V_145 . V_113 , struct V_151 , V_126 ) ;
if ( V_7 -> V_169 == - 1 && V_54 -> V_153 != V_170 )
V_7 -> V_171 ++ ;
V_7 -> V_172 ++ ;
if ( V_54 -> V_152 > V_20 ) {
V_7 -> V_173 ++ ;
return 0 ;
}
V_54 -> V_153 = V_154 ;
V_54 -> V_155 = V_20 ;
return 0 ;
}
static int F_70 ( struct V_6 * V_7 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
const T_5 V_43 = F_45 ( V_102 , V_104 , L_17 ) ;
T_1 V_20 = V_104 -> time ;
struct V_127 * V_26 ;
struct V_151 * V_54 ;
struct V_89 * V_174 ;
if ( V_7 -> V_169 == - 1 )
return 0 ;
V_174 = F_49 ( V_105 , 0 , V_43 ) ;
V_26 = F_54 ( & V_7 -> V_146 , V_174 , & V_7 -> V_147 ) ;
if ( ! V_26 ) {
if ( F_59 ( V_7 , V_174 ) )
return - 1 ;
F_17 ( V_7 , V_174 -> V_107 , F_50 ( V_174 ) ) ;
V_26 = F_54 ( & V_7 -> V_146 , V_174 , & V_7 -> V_147 ) ;
if ( ! V_26 ) {
F_27 ( L_42 ) ;
return - 1 ;
}
if ( F_62 ( V_26 , 'R' , V_20 ) )
return - 1 ;
}
F_11 ( F_52 ( & V_26 -> V_145 ) ) ;
V_54 = F_65 ( V_26 -> V_145 . V_113 , struct V_151 , V_126 ) ;
V_54 -> V_159 = V_54 -> V_152 = V_54 -> V_155 = V_20 ;
V_7 -> V_172 ++ ;
if ( V_54 -> V_152 > V_20 )
V_7 -> V_173 ++ ;
return 0 ;
}
static void F_71 ( struct V_6 * V_7 , struct V_127 * V_145 )
{
int V_14 ;
int V_55 ;
T_1 V_175 ;
if ( ! V_145 -> V_163 )
return;
if ( ! strcmp ( F_50 ( V_145 -> V_89 ) , L_43 ) )
return;
V_7 -> V_176 += V_145 -> V_156 ;
V_7 -> V_177 += V_145 -> V_163 ;
V_55 = printf ( L_44 , F_50 ( V_145 -> V_89 ) , V_145 -> V_89 -> V_107 ) ;
for ( V_14 = 0 ; V_14 < 24 - V_55 ; V_14 ++ )
printf ( L_45 ) ;
V_175 = V_145 -> V_160 / V_145 -> V_163 ;
printf ( L_46 V_15 L_47 ,
( double ) V_145 -> V_156 / 1e6 ,
V_145 -> V_163 , ( double ) V_175 / 1e6 ,
( double ) V_145 -> V_161 / 1e6 ,
( double ) V_145 -> V_162 / 1e9 ) ;
}
static int F_72 ( struct V_127 * V_128 , struct V_127 * V_129 )
{
if ( V_128 -> V_89 -> V_107 < V_129 -> V_89 -> V_107 )
return - 1 ;
if ( V_128 -> V_89 -> V_107 > V_129 -> V_89 -> V_107 )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_127 * V_128 , struct V_127 * V_129 )
{
T_1 V_178 , V_179 ;
if ( ! V_128 -> V_163 )
return - 1 ;
if ( ! V_129 -> V_163 )
return 1 ;
V_178 = V_128 -> V_160 / V_128 -> V_163 ;
V_179 = V_129 -> V_160 / V_129 -> V_163 ;
if ( V_178 < V_179 )
return - 1 ;
if ( V_178 > V_179 )
return 1 ;
return 0 ;
}
static int F_74 ( struct V_127 * V_128 , struct V_127 * V_129 )
{
if ( V_128 -> V_161 < V_129 -> V_161 )
return - 1 ;
if ( V_128 -> V_161 > V_129 -> V_161 )
return 1 ;
return 0 ;
}
static int F_75 ( struct V_127 * V_128 , struct V_127 * V_129 )
{
if ( V_128 -> V_163 < V_129 -> V_163 )
return - 1 ;
if ( V_128 -> V_163 > V_129 -> V_163 )
return 1 ;
return 0 ;
}
static int F_76 ( struct V_127 * V_128 , struct V_127 * V_129 )
{
if ( V_128 -> V_156 < V_129 -> V_156 )
return - 1 ;
if ( V_128 -> V_156 > V_129 -> V_156 )
return 1 ;
return 0 ;
}
static int F_77 ( const char * V_180 , struct V_125 * V_126 )
{
T_2 V_14 ;
static struct V_130 V_181 = {
. V_182 = L_48 ,
. V_132 = F_73 ,
} ;
static struct V_130 V_183 = {
. V_182 = L_49 ,
. V_132 = F_74 ,
} ;
static struct V_130 V_184 = {
. V_182 = L_17 ,
. V_132 = F_72 ,
} ;
static struct V_130 V_185 = {
. V_182 = L_39 ,
. V_132 = F_76 ,
} ;
static struct V_130 V_186 = {
. V_182 = L_50 ,
. V_132 = F_75 ,
} ;
struct V_130 * V_187 [] = {
& V_184 ,
& V_181 ,
& V_183 ,
& V_186 ,
& V_185 ,
} ;
for ( V_14 = 0 ; V_14 < F_78 ( V_187 ) ; V_14 ++ ) {
if ( ! strcmp ( V_187 [ V_14 ] -> V_182 , V_180 ) ) {
F_63 ( & V_187 [ V_14 ] -> V_126 , V_126 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_79 ( struct V_6 * V_7 )
{
struct V_136 * V_137 ;
for (; ; ) {
struct V_127 * V_141 ;
V_137 = F_80 ( & V_7 -> V_146 ) ;
if ( ! V_137 )
break;
F_81 ( V_137 , & V_7 -> V_146 ) ;
V_141 = F_82 ( V_137 , struct V_127 , V_137 ) ;
F_56 ( & V_7 -> V_188 , V_141 , & V_7 -> V_135 ) ;
}
}
static int F_83 ( struct V_189 * V_190 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_55 ( V_190 , struct V_6 , V_190 ) ;
if ( V_7 -> V_191 -> V_192 )
return V_7 -> V_191 -> V_192 ( V_7 , V_102 , V_104 , V_105 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_7 , struct V_101 * V_102 ,
struct V_103 * V_104 , struct V_105 * V_105 )
{
const T_5 V_110 = F_45 ( V_102 , V_104 , L_23 ) ,
V_111 = F_45 ( V_102 , V_104 , L_24 ) ;
struct V_89 * V_166 V_41 , * V_167 ;
int V_193 ;
T_1 V_115 , V_20 = V_104 -> time ;
T_6 V_12 ;
int V_116 , V_194 = V_104 -> V_116 ;
F_11 ( V_194 >= V_117 || V_194 < 0 ) ;
if ( V_194 > V_7 -> V_195 )
V_7 -> V_195 = V_194 ;
V_115 = V_7 -> V_118 [ V_194 ] ;
V_7 -> V_118 [ V_194 ] = V_20 ;
if ( V_115 )
V_12 = V_20 - V_115 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_27 ( L_27 V_15 L_28 , V_12 ) ;
return - 1 ;
}
V_166 = F_49 ( V_105 , 0 , V_110 ) ;
V_167 = F_49 ( V_105 , 0 , V_111 ) ;
V_7 -> V_196 [ V_194 ] = V_167 ;
printf ( L_51 ) ;
V_193 = 0 ;
if ( ! V_167 -> V_197 [ 0 ] ) {
V_167 -> V_197 [ 0 ] = V_7 -> V_198 ;
V_167 -> V_197 [ 1 ] = V_7 -> V_199 ;
if ( V_7 -> V_198 < 'Z' ) {
V_7 -> V_198 ++ ;
} else {
V_7 -> V_198 = 'A' ;
if ( V_7 -> V_199 < '9' ) {
V_7 -> V_199 ++ ;
} else {
V_7 -> V_199 = '0' ;
}
}
V_193 = 1 ;
}
for ( V_116 = 0 ; V_116 <= V_7 -> V_195 ; V_116 ++ ) {
if ( V_116 != V_194 )
printf ( L_45 ) ;
else
printf ( L_52 ) ;
if ( V_7 -> V_196 [ V_116 ] ) {
if ( V_7 -> V_196 [ V_116 ] -> V_107 )
printf ( L_53 , V_7 -> V_196 [ V_116 ] -> V_197 ) ;
else
printf ( L_54 ) ;
} else
printf ( L_55 ) ;
}
printf ( L_56 , ( double ) V_20 / 1e9 ) ;
if ( V_193 ) {
printf ( L_57 ,
V_167 -> V_197 , F_50 ( V_167 ) , V_167 -> V_107 ) ;
} else {
printf ( L_12 ) ;
}
return 0 ;
}
static int F_85 ( struct V_189 * V_190 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_55 ( V_190 , struct V_6 , V_190 ) ;
int V_194 = V_104 -> V_116 , V_60 = 0 ;
T_5 V_110 = F_45 ( V_102 , V_104 , L_23 ) ,
V_111 = F_45 ( V_102 , V_104 , L_24 ) ;
if ( V_7 -> V_200 [ V_194 ] != ( T_5 ) - 1 ) {
if ( V_7 -> V_200 [ V_194 ] != V_110 )
V_7 -> V_201 ++ ;
}
if ( V_7 -> V_191 -> V_202 )
V_60 = V_7 -> V_191 -> V_202 ( V_7 , V_102 , V_104 , V_105 ) ;
V_7 -> V_200 [ V_194 ] = V_111 ;
return V_60 ;
}
static int F_86 ( struct V_189 * V_190 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_55 ( V_190 , struct V_6 , V_190 ) ;
if ( V_7 -> V_191 -> V_203 )
return V_7 -> V_191 -> V_203 ( V_7 , V_102 , V_104 , V_105 ) ;
return 0 ;
}
static int F_87 ( struct V_189 * V_190 ,
union V_119 * V_21 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_55 ( V_190 , struct V_6 , V_190 ) ;
F_88 ( V_190 , V_21 , V_104 , V_105 ) ;
if ( V_7 -> V_191 -> V_204 )
return V_7 -> V_191 -> V_204 ( V_7 , V_21 , V_105 ) ;
return 0 ;
}
static int F_89 ( struct V_189 * V_190 ,
struct V_101 * V_102 ,
struct V_103 * V_104 ,
struct V_105 * V_105 )
{
struct V_6 * V_7 = F_55 ( V_190 , struct V_6 , V_190 ) ;
if ( V_7 -> V_191 -> V_205 )
return V_7 -> V_191 -> V_205 ( V_7 , V_102 , V_104 , V_105 ) ;
return 0 ;
}
static int F_90 ( struct V_189 * V_190 V_41 ,
union V_119 * V_21 V_41 ,
struct V_103 * V_104 ,
struct V_101 * V_102 ,
struct V_105 * V_105 )
{
int V_60 = 0 ;
V_102 -> V_206 . V_207 . V_208 += V_104 -> V_209 ;
F_91 ( & V_102 -> V_206 , V_210 ) ;
if ( V_102 -> V_211 != NULL ) {
T_7 V_212 = V_102 -> V_211 ;
V_60 = V_212 ( V_190 , V_102 , V_104 , V_105 ) ;
}
return V_60 ;
}
static int F_92 ( struct V_6 * V_7 ,
struct V_213 * * V_214 )
{
const struct V_215 V_216 [] = {
{ L_58 , F_85 , } ,
{ L_59 , F_86 , } ,
{ L_60 , F_83 , } ,
{ L_61 , F_83 , } ,
{ L_62 , F_89 , } ,
} ;
struct V_213 * V_217 ;
struct V_218 V_219 = {
. V_220 = V_221 ,
. V_222 = V_223 ,
} ;
V_217 = F_93 ( & V_219 , false , & V_7 -> V_190 ) ;
if ( V_217 == NULL ) {
F_47 ( L_63 ) ;
return - 1 ;
}
if ( F_94 ( V_217 , V_216 ) )
goto V_224;
if ( F_95 ( V_217 , L_64 ) ) {
int V_60 = F_96 ( V_217 , & V_7 -> V_190 ) ;
if ( V_60 ) {
F_27 ( L_65 , V_60 ) ;
goto V_224;
}
V_7 -> V_23 = V_217 -> V_207 . V_23 [ 0 ] ;
V_7 -> V_225 = V_217 -> V_207 . V_226 ;
V_7 -> V_227 = V_217 -> V_207 . V_23 [ V_228 ] ;
}
if ( V_214 )
* V_214 = V_217 ;
else
F_97 ( V_217 ) ;
return 0 ;
V_224:
F_97 ( V_217 ) ;
return - 1 ;
}
static void F_98 ( struct V_6 * V_7 )
{
if ( V_7 -> V_173 && V_7 -> V_172 ) {
printf ( L_66 ,
( double ) V_7 -> V_173 / ( double ) V_7 -> V_172 * 100.0 ,
V_7 -> V_173 , V_7 -> V_172 ) ;
}
if ( V_7 -> V_225 && V_7 -> V_23 ) {
printf ( L_67 ,
( double ) V_7 -> V_225 / ( double ) V_7 -> V_23 * 100.0 ,
V_7 -> V_225 , V_7 -> V_23 , V_7 -> V_227 ) ;
}
if ( V_7 -> V_171 && V_7 -> V_172 ) {
printf ( L_68 ,
( double ) V_7 -> V_171 / ( double ) V_7 -> V_172 * 100.0 ,
V_7 -> V_171 , V_7 -> V_172 ) ;
if ( V_7 -> V_225 )
printf ( L_69 ) ;
printf ( L_12 ) ;
}
if ( V_7 -> V_201 && V_7 -> V_172 ) {
printf ( L_70 ,
( double ) V_7 -> V_201 / ( double ) V_7 -> V_172 * 100.0 ,
V_7 -> V_201 , V_7 -> V_172 ) ;
if ( V_7 -> V_225 )
printf ( L_69 ) ;
printf ( L_12 ) ;
}
}
static int F_99 ( struct V_6 * V_7 )
{
struct V_136 * V_114 ;
struct V_213 * V_217 ;
F_100 () ;
if ( F_92 ( V_7 , & V_217 ) )
return - 1 ;
F_79 ( V_7 ) ;
printf ( L_71 ) ;
printf ( L_72 ) ;
printf ( L_73 ) ;
V_114 = F_80 ( & V_7 -> V_188 ) ;
while ( V_114 ) {
struct V_127 * V_145 ;
V_145 = F_82 ( V_114 , struct V_127 , V_137 ) ;
F_71 ( V_7 , V_145 ) ;
V_114 = F_101 ( V_114 ) ;
}
printf ( L_73 ) ;
printf ( L_74 V_15 L_75 ,
( double ) V_7 -> V_176 / 1e6 , V_7 -> V_177 ) ;
printf ( L_76 ) ;
F_98 ( V_7 ) ;
printf ( L_12 ) ;
F_97 ( V_217 ) ;
return 0 ;
}
static int F_102 ( struct V_6 * V_7 )
{
V_7 -> V_195 = F_103 ( V_229 ) ;
F_100 () ;
if ( F_92 ( V_7 , NULL ) )
return - 1 ;
F_98 ( V_7 ) ;
return 0 ;
}
static int F_104 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_6 ( V_7 ) ;
F_8 ( V_7 ) ;
F_42 ( V_7 ) ;
if ( F_92 ( V_7 , NULL ) )
return - 1 ;
printf ( L_77 , V_7 -> V_31 ) ;
printf ( L_78 , V_7 -> V_42 ) ;
printf ( L_79 , V_7 -> V_40 ) ;
if ( V_7 -> V_36 )
printf ( L_80 , V_7 -> V_36 ) ;
if ( V_7 -> V_38 )
printf ( L_81 , V_7 -> V_38 ) ;
if ( V_7 -> V_30 )
printf ( L_82 ,
V_7 -> V_30 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
F_35 ( V_7 ) ;
printf ( L_83 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_230 ; V_14 ++ )
F_41 ( V_7 ) ;
return 0 ;
}
static void F_105 ( struct V_6 * V_7 , const struct V_231 * V_232 ,
const char * const V_233 [] )
{
char * V_234 , * V_180 , * V_148 = F_106 ( V_7 -> V_235 ) ;
for ( V_180 = strtok_r ( V_148 , L_84 , & V_234 ) ;
V_180 ; V_180 = strtok_r ( NULL , L_84 , & V_234 ) ) {
if ( F_77 ( V_180 , & V_7 -> V_135 ) < 0 ) {
error ( L_85 , V_180 ) ;
F_107 ( V_233 , V_232 ) ;
}
}
free ( V_148 ) ;
F_77 ( L_17 , & V_7 -> V_147 ) ;
}
static int F_108 ( int V_236 , const char * * V_237 )
{
unsigned int V_238 , V_14 , V_53 ;
const char * * V_239 ;
const char * const V_240 [] = {
L_86 ,
L_87 ,
L_88 ,
L_89 , L_90 ,
L_91 , L_92 ,
L_93 , L_58 ,
L_93 , L_94 ,
L_93 , L_95 ,
L_93 , L_96 ,
L_93 , L_59 ,
L_93 , L_97 ,
L_93 , L_60 ,
L_93 , L_62 ,
} ;
V_238 = F_78 ( V_240 ) + V_236 - 1 ;
V_239 = calloc ( V_238 + 1 , sizeof( char * ) ) ;
if ( V_239 == NULL )
return - V_241 ;
for ( V_14 = 0 ; V_14 < F_78 ( V_240 ) ; V_14 ++ )
V_239 [ V_14 ] = F_106 ( V_240 [ V_14 ] ) ;
for ( V_53 = 1 ; V_53 < ( unsigned int ) V_236 ; V_53 ++ , V_14 ++ )
V_239 [ V_14 ] = V_237 [ V_53 ] ;
F_11 ( V_14 != V_238 ) ;
return F_109 ( V_14 , V_239 , NULL ) ;
}
int F_110 ( int V_236 , const char * * V_237 , const char * T_8 V_41 )
{
const char V_242 [] = L_98 ;
struct V_6 V_7 = {
. V_190 = {
. V_104 = F_90 ,
. V_44 = V_243 ,
. V_244 = V_245 ,
. V_122 = F_87 ,
. V_246 = true ,
} ,
. V_147 = F_111 ( V_7 . V_147 ) ,
. V_135 = F_111 ( V_7 . V_135 ) ,
. V_83 = V_247 ,
. V_86 = V_247 ,
. V_235 = V_242 ,
. V_230 = 10 ,
. V_169 = - 1 ,
. V_198 = 'A' ,
. V_199 = '0' ,
} ;
const struct V_231 V_248 [] = {
F_112 ( 's' , L_99 , & V_7 . V_235 , L_100 ,
L_101 ) ,
F_113 ( 'v' , L_102 , & V_50 ,
L_103 ) ,
F_114 ( 'C' , L_104 , & V_7 . V_169 ,
L_105 ) ,
F_115 ( 'D' , L_106 , & V_249 ,
L_107 ) ,
F_116 ()
} ;
const struct V_231 V_250 [] = {
F_117 ( 'r' , L_108 , & V_7 . V_230 ,
L_109 ) ,
F_113 ( 'v' , L_102 , & V_50 ,
L_103 ) ,
F_115 ( 'D' , L_106 , & V_249 ,
L_107 ) ,
F_116 ()
} ;
const struct V_231 V_251 [] = {
F_112 ( 'i' , L_110 , & V_221 , L_111 ,
L_112 ) ,
F_113 ( 'v' , L_102 , & V_50 ,
L_103 ) ,
F_115 ( 'D' , L_106 , & V_249 ,
L_107 ) ,
F_116 ()
} ;
const char * const V_252 [] = {
L_113 ,
NULL
} ;
const char * const V_253 [] = {
L_114 ,
NULL
} ;
const char * const V_254 [] = {
L_115 ,
NULL
} ;
struct V_255 V_256 = {
. V_192 = F_69 ,
. V_202 = F_67 ,
. V_203 = F_68 ,
. V_205 = F_70 ,
} ;
struct V_255 V_257 = {
. V_202 = F_84 ,
} ;
struct V_255 V_258 = {
. V_192 = F_43 ,
. V_202 = F_46 ,
. V_204 = F_48 ,
} ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_78 ( V_7 . V_200 ) ; V_14 ++ )
V_7 . V_200 [ V_14 ] = - 1 ;
V_236 = F_118 ( V_236 , V_237 , V_251 , V_254 ,
V_259 ) ;
if ( ! V_236 )
F_107 ( V_254 , V_251 ) ;
if ( ! strcmp ( V_237 [ 0 ] , L_116 ) )
return F_119 ( V_236 , V_237 , T_8 ) ;
F_120 () ;
if ( ! strncmp ( V_237 [ 0 ] , L_117 , 3 ) ) {
return F_108 ( V_236 , V_237 ) ;
} else if ( ! strncmp ( V_237 [ 0 ] , L_118 , 3 ) ) {
V_7 . V_191 = & V_256 ;
if ( V_236 > 1 ) {
V_236 = F_118 ( V_236 , V_237 , V_248 , V_252 , 0 ) ;
if ( V_236 )
F_107 ( V_252 , V_248 ) ;
}
F_105 ( & V_7 , V_248 , V_252 ) ;
return F_99 ( & V_7 ) ;
} else if ( ! strcmp ( V_237 [ 0 ] , L_119 ) ) {
V_7 . V_191 = & V_257 ;
F_105 ( & V_7 , V_248 , V_252 ) ;
return F_102 ( & V_7 ) ;
} else if ( ! strncmp ( V_237 [ 0 ] , L_120 , 3 ) ) {
V_7 . V_191 = & V_258 ;
if ( V_236 ) {
V_236 = F_118 ( V_236 , V_237 , V_250 , V_253 , 0 ) ;
if ( V_236 )
F_107 ( V_253 , V_250 ) ;
}
return F_104 ( & V_7 ) ;
} else {
F_107 ( V_254 , V_251 ) ;
}
return 0 ;
}
