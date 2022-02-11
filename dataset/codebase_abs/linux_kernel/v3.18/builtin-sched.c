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
char V_67 [ V_68 ] ;
int V_69 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
V_66 . type = V_70 ;
V_66 . V_71 = V_72 ;
V_69 = F_26 ( & V_66 , 0 , - 1 , - 1 ,
F_27 () ) ;
if ( V_69 < 0 )
F_28 ( L_6
L_7 , V_69 ,
F_29 ( V_73 , V_67 , sizeof( V_67 ) ) ) ;
return V_69 ;
}
static T_1 F_30 ( int V_69 )
{
T_1 V_74 ;
int V_55 ;
V_55 = F_31 ( V_69 , & V_74 , sizeof( V_74 ) ) ;
F_11 ( V_55 != sizeof( V_74 ) ) ;
return V_74 ;
}
static void * F_32 ( void * V_75 )
{
struct V_76 * V_77 = V_75 ;
struct V_18 * V_78 = V_77 -> V_19 ;
struct V_6 * V_7 = V_77 -> V_7 ;
T_1 V_79 , V_80 ;
unsigned long V_14 , V_55 ;
char V_81 [ 22 ] ;
int V_69 ;
F_33 ( & V_77 ) ;
sprintf ( V_81 , L_8 , V_78 -> V_44 ) ;
F_34 ( V_82 , V_81 ) ;
V_69 = F_25 () ;
if ( V_69 < 0 )
return NULL ;
V_83:
V_55 = F_22 ( & V_78 -> V_84 ) ;
F_11 ( V_55 ) ;
V_55 = F_35 ( & V_7 -> V_85 ) ;
F_11 ( V_55 ) ;
V_55 = F_36 ( & V_7 -> V_85 ) ;
F_11 ( V_55 ) ;
V_79 = F_30 ( V_69 ) ;
for ( V_14 = 0 ; V_14 < V_78 -> V_23 ; V_14 ++ ) {
V_78 -> V_28 = V_14 ;
F_20 ( V_7 , V_78 -> V_26 [ V_14 ] ) ;
}
V_80 = F_30 ( V_69 ) ;
V_78 -> V_86 = V_80 - V_79 ;
V_55 = F_22 ( & V_78 -> V_87 ) ;
F_11 ( V_55 ) ;
V_55 = F_35 ( & V_7 -> V_88 ) ;
F_11 ( V_55 ) ;
V_55 = F_36 ( & V_7 -> V_88 ) ;
F_11 ( V_55 ) ;
goto V_83;
}
static void F_37 ( struct V_6 * V_7 )
{
struct V_18 * V_19 ;
T_4 V_66 ;
unsigned long V_14 ;
int V_60 ;
V_60 = F_38 ( & V_66 ) ;
F_11 ( V_60 ) ;
V_60 = F_39 ( & V_66 ,
( T_2 ) F_40 ( 16 * 1024 , V_89 ) ) ;
F_11 ( V_60 ) ;
V_60 = F_35 ( & V_7 -> V_85 ) ;
F_11 ( V_60 ) ;
V_60 = F_35 ( & V_7 -> V_88 ) ;
F_11 ( V_60 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
struct V_76 * V_77 = malloc ( sizeof( * V_77 ) ) ;
F_11 ( V_77 == NULL ) ;
V_77 -> V_19 = V_19 = V_7 -> V_48 [ V_14 ] ;
V_77 -> V_7 = V_7 ;
F_15 ( & V_19 -> V_90 , 0 , 0 ) ;
F_15 ( & V_19 -> V_84 , 0 , 0 ) ;
F_15 ( & V_19 -> V_87 , 0 , 0 ) ;
V_19 -> V_28 = 0 ;
V_60 = F_41 ( & V_19 -> V_91 , & V_66 , F_32 , V_77 ) ;
F_11 ( V_60 ) ;
}
}
static void F_42 ( struct V_6 * V_7 )
{
T_1 V_79 , V_80 ;
struct V_18 * V_19 ;
unsigned long V_14 , V_55 ;
V_7 -> V_92 = F_1 () ;
V_7 -> V_86 = 0 ;
F_36 ( & V_7 -> V_88 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
V_55 = F_21 ( & V_19 -> V_84 ) ;
F_11 ( V_55 ) ;
F_15 ( & V_19 -> V_84 , 0 , 0 ) ;
}
V_55 = F_35 ( & V_7 -> V_88 ) ;
F_11 ( V_55 ) ;
V_79 = F_23 () ;
F_36 ( & V_7 -> V_85 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
V_55 = F_21 ( & V_19 -> V_87 ) ;
F_11 ( V_55 ) ;
F_15 ( & V_19 -> V_87 , 0 , 0 ) ;
V_7 -> V_86 += V_19 -> V_86 ;
V_19 -> V_86 = 0 ;
}
V_80 = F_23 () ;
if ( ! V_7 -> V_93 )
V_7 -> V_93 = V_7 -> V_86 ;
V_7 -> V_93 = ( V_7 -> V_93 * 9 + V_7 -> V_86 ) / 10 ;
V_7 -> V_94 = V_80 - V_79 ;
if ( ! V_7 -> V_95 )
V_7 -> V_95 = V_7 -> V_94 ;
V_7 -> V_95 = ( V_7 -> V_95 * 9 +
V_7 -> V_94 ) / 10 ;
V_55 = F_35 ( & V_7 -> V_85 ) ;
F_11 ( V_55 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_47 ; V_14 ++ ) {
V_19 = V_7 -> V_48 [ V_14 ] ;
F_15 ( & V_19 -> V_90 , 0 , 0 ) ;
V_19 -> V_28 = 0 ;
}
}
static void F_43 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 , V_12 , V_96 , V_97 ;
V_9 = F_1 () ;
F_42 ( V_7 ) ;
V_10 = F_1 () ;
V_12 = V_10 - V_9 ;
V_7 -> V_98 += V_12 ;
V_7 -> V_99 ++ ;
V_96 = V_7 -> V_98 / V_7 -> V_99 ;
if ( V_12 < V_96 )
V_97 = V_96 - V_12 ;
else
V_97 = V_12 - V_96 ;
V_7 -> V_100 += V_97 ;
if ( ! V_7 -> V_101 )
V_7 -> V_101 = V_12 ;
V_7 -> V_101 = ( V_7 -> V_101 * 9 + V_12 ) / 10 ;
printf ( L_9 , V_7 -> V_99 , ( double ) V_12 / 1000000.0 ) ;
printf ( L_10 , ( double ) V_7 -> V_101 / 1e6 ) ;
printf ( L_11 ,
( double ) V_7 -> V_86 / 1e6 , ( double ) V_7 -> V_93 / 1e6 ) ;
#if 0
printf(" [%0.2f / %0.2f]",
(double)sched->parent_cpu_usage/1e6,
(double)sched->runavg_parent_cpu_usage/1e6);
#endif
printf ( L_12 ) ;
if ( V_7 -> V_102 )
printf ( L_13 , V_7 -> V_102 ) ;
V_7 -> V_102 = 0 ;
}
static void F_44 ( struct V_6 * V_7 )
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
F_45 ( struct V_6 * V_7 ,
struct V_103 * V_104 , struct V_105 * V_106 ,
struct V_107 * V_107 V_41 )
{
const char * V_44 = F_46 ( V_104 , V_106 , L_16 ) ;
const T_5 V_43 = F_47 ( V_104 , V_106 , L_17 ) ;
struct V_18 * V_108 , * V_32 ;
if ( V_50 ) {
printf ( L_18 , V_104 ) ;
printf ( L_19 , V_106 -> V_109 , V_44 , V_43 ) ;
}
V_108 = F_17 ( V_7 , V_106 -> V_109 , L_20 ) ;
V_32 = F_17 ( V_7 , V_43 , V_44 ) ;
F_14 ( V_7 , V_108 , V_106 -> time , V_32 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 V_41 )
{
const char * V_110 = F_46 ( V_104 , V_106 , L_21 ) ,
* V_111 = F_46 ( V_104 , V_106 , L_22 ) ;
const T_5 V_112 = F_47 ( V_104 , V_106 , L_23 ) ,
V_113 = F_47 ( V_104 , V_106 , L_24 ) ;
const T_1 V_114 = F_47 ( V_104 , V_106 , L_25 ) ;
struct V_18 * V_115 , V_41 * V_116 ;
T_1 V_117 , V_20 = V_106 -> time ;
int V_118 = V_106 -> V_118 ;
T_6 V_12 ;
if ( V_50 )
printf ( L_26 , V_104 ) ;
if ( V_118 >= V_119 || V_118 < 0 )
return 0 ;
V_117 = V_7 -> V_120 [ V_118 ] ;
if ( V_117 )
V_12 = V_20 - V_117 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_28 ( L_27 V_15 L_28 , V_12 ) ;
return - 1 ;
}
F_49 ( L_29 V_15 L_30 ,
V_110 , V_112 , V_111 , V_113 , V_12 ) ;
V_115 = F_17 ( V_7 , V_112 , V_110 ) ;
V_116 = F_17 ( V_7 , V_113 , V_111 ) ;
V_7 -> V_120 [ V_118 ] = V_20 ;
F_13 ( V_7 , V_115 , V_20 , V_12 ) ;
F_16 ( V_7 , V_115 , V_20 , V_114 ) ;
return 0 ;
}
static int F_50 ( struct V_6 * V_7 ,
union V_121 * V_21 ,
struct V_107 * V_107 )
{
struct V_91 * V_122 , * V_123 ;
V_122 = F_51 ( V_107 , V_21 -> V_124 . V_43 ,
V_21 -> V_124 . V_109 ) ;
V_123 = F_51 ( V_107 , V_21 -> V_124 . V_125 ,
V_21 -> V_124 . V_126 ) ;
if ( V_122 == NULL || V_123 == NULL ) {
F_49 ( L_31 ,
V_122 , V_123 ) ;
return 0 ;
}
if ( V_50 ) {
printf ( L_32 ) ;
printf ( L_33 , F_52 ( V_123 ) , V_123 -> V_109 ) ;
printf ( L_34 , F_52 ( V_122 ) , V_122 -> V_109 ) ;
}
F_17 ( V_7 , V_123 -> V_109 , F_52 ( V_123 ) ) ;
F_17 ( V_7 , V_122 -> V_109 , F_52 ( V_122 ) ) ;
return 0 ;
}
static int
F_53 ( struct V_127 * V_128 , struct V_129 * V_130 , struct V_129 * V_131 )
{
struct V_132 * V_133 ;
int V_55 = 0 ;
F_11 ( F_54 ( V_128 ) ) ;
F_55 (sort, list, list) {
V_55 = V_133 -> V_134 ( V_130 , V_131 ) ;
if ( V_55 )
return V_55 ;
}
return V_55 ;
}
static struct V_129 *
F_56 ( struct V_135 * V_136 , struct V_91 * V_91 ,
struct V_127 * V_137 )
{
struct V_138 * V_139 = V_136 -> V_138 ;
struct V_129 V_140 = { . V_91 = V_91 } ;
while ( V_139 ) {
struct V_129 * V_26 ;
int V_134 ;
V_26 = F_57 ( V_139 , struct V_129 , V_139 ) ;
V_134 = F_53 ( V_137 , & V_140 , V_26 ) ;
if ( V_134 > 0 )
V_139 = V_139 -> V_141 ;
else if ( V_134 < 0 )
V_139 = V_139 -> V_142 ;
else {
F_11 ( V_91 != V_26 -> V_91 ) ;
return V_26 ;
}
}
return NULL ;
}
static void
F_58 ( struct V_135 * V_136 , struct V_129 * V_143 ,
struct V_127 * V_137 )
{
struct V_138 * * V_144 = & ( V_136 -> V_138 ) , * V_123 = NULL ;
while ( * V_144 ) {
struct V_129 * V_145 ;
int V_134 ;
V_145 = F_57 ( * V_144 , struct V_129 , V_139 ) ;
V_123 = * V_144 ;
V_134 = F_53 ( V_137 , V_143 , V_145 ) ;
if ( V_134 > 0 )
V_144 = & ( ( * V_144 ) -> V_141 ) ;
else
V_144 = & ( ( * V_144 ) -> V_142 ) ;
}
F_59 ( & V_143 -> V_139 , V_123 , V_144 ) ;
F_60 ( & V_143 -> V_139 , V_136 ) ;
}
static int F_61 ( struct V_6 * V_7 , struct V_91 * V_91 )
{
struct V_129 * V_26 = F_10 ( sizeof( * V_26 ) ) ;
if ( ! V_26 ) {
F_28 ( L_35 , V_146 ) ;
return - 1 ;
}
V_26 -> V_91 = V_91 ;
F_62 ( & V_26 -> V_147 ) ;
F_58 ( & V_7 -> V_148 , V_26 , & V_7 -> V_149 ) ;
return 0 ;
}
static char F_63 ( T_1 V_114 )
{
const char * V_150 = V_151 ;
return V_150 [ V_114 ] ;
}
static int
F_64 ( struct V_129 * V_26 ,
char V_152 ,
T_1 V_20 )
{
struct V_153 * V_54 = F_10 ( sizeof( * V_54 ) ) ;
if ( ! V_54 ) {
F_28 ( L_36 , V_146 ) ;
return - 1 ;
}
V_54 -> V_154 = V_20 ;
if ( V_152 == 'R' ) {
V_54 -> V_155 = V_156 ;
V_54 -> V_157 = V_54 -> V_154 ;
}
F_65 ( & V_54 -> V_128 , & V_26 -> V_147 ) ;
return 0 ;
}
static void
F_66 ( struct V_129 * V_26 , T_1 V_12 ,
T_1 V_20 V_41 )
{
struct V_153 * V_54 ;
F_11 ( F_54 ( & V_26 -> V_147 ) ) ;
V_54 = F_67 ( V_26 -> V_147 . V_115 , struct V_153 , V_128 ) ;
V_54 -> V_74 += V_12 ;
V_26 -> V_158 += V_12 ;
}
static void
F_68 ( struct V_129 * V_26 , T_1 V_20 )
{
struct V_153 * V_54 ;
T_1 V_12 ;
if ( F_54 ( & V_26 -> V_147 ) )
return;
V_54 = F_67 ( V_26 -> V_147 . V_115 , struct V_153 , V_128 ) ;
if ( V_54 -> V_155 != V_156 )
return;
if ( V_20 < V_54 -> V_157 ) {
V_54 -> V_155 = V_159 ;
return;
}
V_54 -> V_155 = V_160 ;
V_54 -> V_161 = V_20 ;
V_12 = V_54 -> V_161 - V_54 -> V_157 ;
V_26 -> V_162 += V_12 ;
if ( V_12 > V_26 -> V_163 ) {
V_26 -> V_163 = V_12 ;
V_26 -> V_164 = V_20 ;
}
V_26 -> V_165 ++ ;
}
static int F_69 ( struct V_6 * V_7 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
const T_5 V_112 = F_47 ( V_104 , V_106 , L_23 ) ,
V_113 = F_47 ( V_104 , V_106 , L_24 ) ;
const T_1 V_114 = F_47 ( V_104 , V_106 , L_25 ) ;
struct V_129 * V_166 , * V_167 ;
struct V_91 * V_168 , * V_169 ;
T_1 V_117 , V_20 = V_106 -> time ;
int V_118 = V_106 -> V_118 ;
T_6 V_12 ;
F_11 ( V_118 >= V_119 || V_118 < 0 ) ;
V_117 = V_7 -> V_120 [ V_118 ] ;
V_7 -> V_120 [ V_118 ] = V_20 ;
if ( V_117 )
V_12 = V_20 - V_117 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_28 ( L_27 V_15 L_28 , V_12 ) ;
return - 1 ;
}
V_168 = F_51 ( V_107 , - 1 , V_112 ) ;
V_169 = F_51 ( V_107 , - 1 , V_113 ) ;
V_166 = F_56 ( & V_7 -> V_148 , V_168 , & V_7 -> V_149 ) ;
if ( ! V_166 ) {
if ( F_61 ( V_7 , V_168 ) )
return - 1 ;
V_166 = F_56 ( & V_7 -> V_148 , V_168 , & V_7 -> V_149 ) ;
if ( ! V_166 ) {
F_28 ( L_37 ) ;
return - 1 ;
}
}
if ( F_64 ( V_166 , F_63 ( V_114 ) , V_20 ) )
return - 1 ;
V_167 = F_56 ( & V_7 -> V_148 , V_169 , & V_7 -> V_149 ) ;
if ( ! V_167 ) {
if ( F_61 ( V_7 , V_169 ) )
return - 1 ;
V_167 = F_56 ( & V_7 -> V_148 , V_169 , & V_7 -> V_149 ) ;
if ( ! V_167 ) {
F_28 ( L_38 ) ;
return - 1 ;
}
if ( F_64 ( V_167 , 'R' , V_20 ) )
return - 1 ;
}
F_68 ( V_167 , V_20 ) ;
return 0 ;
}
static int F_70 ( struct V_6 * V_7 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
const T_5 V_43 = F_47 ( V_104 , V_106 , L_17 ) ;
const T_1 V_74 = F_47 ( V_104 , V_106 , L_39 ) ;
struct V_91 * V_91 = F_51 ( V_107 , - 1 , V_43 ) ;
struct V_129 * V_26 = F_56 ( & V_7 -> V_148 , V_91 , & V_7 -> V_149 ) ;
T_1 V_20 = V_106 -> time ;
int V_118 = V_106 -> V_118 ;
F_11 ( V_118 >= V_119 || V_118 < 0 ) ;
if ( ! V_26 ) {
if ( F_61 ( V_7 , V_91 ) )
return - 1 ;
V_26 = F_56 ( & V_7 -> V_148 , V_91 , & V_7 -> V_149 ) ;
if ( ! V_26 ) {
F_28 ( L_38 ) ;
return - 1 ;
}
if ( F_64 ( V_26 , 'R' , V_20 ) )
return - 1 ;
}
F_66 ( V_26 , V_74 , V_20 ) ;
return 0 ;
}
static int F_71 ( struct V_6 * V_7 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
const T_5 V_43 = F_47 ( V_104 , V_106 , L_17 ) ;
struct V_129 * V_26 ;
struct V_153 * V_54 ;
struct V_91 * V_32 ;
T_1 V_20 = V_106 -> time ;
V_32 = F_51 ( V_107 , - 1 , V_43 ) ;
V_26 = F_56 ( & V_7 -> V_148 , V_32 , & V_7 -> V_149 ) ;
if ( ! V_26 ) {
if ( F_61 ( V_7 , V_32 ) )
return - 1 ;
V_26 = F_56 ( & V_7 -> V_148 , V_32 , & V_7 -> V_149 ) ;
if ( ! V_26 ) {
F_28 ( L_40 ) ;
return - 1 ;
}
if ( F_64 ( V_26 , 'S' , V_20 ) )
return - 1 ;
}
F_11 ( F_54 ( & V_26 -> V_147 ) ) ;
V_54 = F_67 ( V_26 -> V_147 . V_115 , struct V_153 , V_128 ) ;
if ( V_7 -> V_170 == - 1 && V_54 -> V_155 != V_171 )
return 0 ;
V_7 -> V_172 ++ ;
if ( V_54 -> V_154 > V_20 ) {
V_7 -> V_173 ++ ;
return 0 ;
}
V_54 -> V_155 = V_156 ;
V_54 -> V_157 = V_20 ;
return 0 ;
}
static int F_72 ( struct V_6 * V_7 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
const T_5 V_43 = F_47 ( V_104 , V_106 , L_17 ) ;
T_1 V_20 = V_106 -> time ;
struct V_129 * V_26 ;
struct V_153 * V_54 ;
struct V_91 * V_174 ;
if ( V_7 -> V_170 == - 1 )
return 0 ;
V_174 = F_51 ( V_107 , - 1 , V_43 ) ;
V_26 = F_56 ( & V_7 -> V_148 , V_174 , & V_7 -> V_149 ) ;
if ( ! V_26 ) {
if ( F_61 ( V_7 , V_174 ) )
return - 1 ;
F_17 ( V_7 , V_174 -> V_109 , F_52 ( V_174 ) ) ;
V_26 = F_56 ( & V_7 -> V_148 , V_174 , & V_7 -> V_149 ) ;
if ( ! V_26 ) {
F_28 ( L_41 ) ;
return - 1 ;
}
if ( F_64 ( V_26 , 'R' , V_20 ) )
return - 1 ;
}
F_11 ( F_54 ( & V_26 -> V_147 ) ) ;
V_54 = F_67 ( V_26 -> V_147 . V_115 , struct V_153 , V_128 ) ;
V_54 -> V_161 = V_54 -> V_154 = V_54 -> V_157 = V_20 ;
V_7 -> V_172 ++ ;
if ( V_54 -> V_154 > V_20 )
V_7 -> V_173 ++ ;
return 0 ;
}
static void F_73 ( struct V_6 * V_7 , struct V_129 * V_147 )
{
int V_14 ;
int V_55 ;
T_1 V_175 ;
if ( ! V_147 -> V_165 )
return;
if ( ! strcmp ( F_52 ( V_147 -> V_91 ) , L_42 ) )
return;
V_7 -> V_176 += V_147 -> V_158 ;
V_7 -> V_177 += V_147 -> V_165 ;
V_55 = printf ( L_43 , F_52 ( V_147 -> V_91 ) , V_147 -> V_91 -> V_109 ) ;
for ( V_14 = 0 ; V_14 < 24 - V_55 ; V_14 ++ )
printf ( L_44 ) ;
V_175 = V_147 -> V_162 / V_147 -> V_165 ;
printf ( L_45 V_15 L_46 ,
( double ) V_147 -> V_158 / 1e6 ,
V_147 -> V_165 , ( double ) V_175 / 1e6 ,
( double ) V_147 -> V_163 / 1e6 ,
( double ) V_147 -> V_164 / 1e9 ) ;
}
static int F_74 ( struct V_129 * V_130 , struct V_129 * V_131 )
{
if ( V_130 -> V_91 -> V_109 < V_131 -> V_91 -> V_109 )
return - 1 ;
if ( V_130 -> V_91 -> V_109 > V_131 -> V_91 -> V_109 )
return 1 ;
return 0 ;
}
static int F_75 ( struct V_129 * V_130 , struct V_129 * V_131 )
{
T_1 V_178 , V_179 ;
if ( ! V_130 -> V_165 )
return - 1 ;
if ( ! V_131 -> V_165 )
return 1 ;
V_178 = V_130 -> V_162 / V_130 -> V_165 ;
V_179 = V_131 -> V_162 / V_131 -> V_165 ;
if ( V_178 < V_179 )
return - 1 ;
if ( V_178 > V_179 )
return 1 ;
return 0 ;
}
static int F_76 ( struct V_129 * V_130 , struct V_129 * V_131 )
{
if ( V_130 -> V_163 < V_131 -> V_163 )
return - 1 ;
if ( V_130 -> V_163 > V_131 -> V_163 )
return 1 ;
return 0 ;
}
static int F_77 ( struct V_129 * V_130 , struct V_129 * V_131 )
{
if ( V_130 -> V_165 < V_131 -> V_165 )
return - 1 ;
if ( V_130 -> V_165 > V_131 -> V_165 )
return 1 ;
return 0 ;
}
static int F_78 ( struct V_129 * V_130 , struct V_129 * V_131 )
{
if ( V_130 -> V_158 < V_131 -> V_158 )
return - 1 ;
if ( V_130 -> V_158 > V_131 -> V_158 )
return 1 ;
return 0 ;
}
static int F_79 ( const char * V_180 , struct V_127 * V_128 )
{
T_2 V_14 ;
static struct V_132 V_181 = {
. V_182 = L_47 ,
. V_134 = F_75 ,
} ;
static struct V_132 V_183 = {
. V_182 = L_48 ,
. V_134 = F_76 ,
} ;
static struct V_132 V_184 = {
. V_182 = L_17 ,
. V_134 = F_74 ,
} ;
static struct V_132 V_185 = {
. V_182 = L_39 ,
. V_134 = F_78 ,
} ;
static struct V_132 V_186 = {
. V_182 = L_49 ,
. V_134 = F_77 ,
} ;
struct V_132 * V_187 [] = {
& V_184 ,
& V_181 ,
& V_183 ,
& V_186 ,
& V_185 ,
} ;
for ( V_14 = 0 ; V_14 < F_80 ( V_187 ) ; V_14 ++ ) {
if ( ! strcmp ( V_187 [ V_14 ] -> V_182 , V_180 ) ) {
F_65 ( & V_187 [ V_14 ] -> V_128 , V_128 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_81 ( struct V_6 * V_7 )
{
struct V_138 * V_139 ;
for (; ; ) {
struct V_129 * V_143 ;
V_139 = F_82 ( & V_7 -> V_148 ) ;
if ( ! V_139 )
break;
F_83 ( V_139 , & V_7 -> V_148 ) ;
V_143 = F_84 ( V_139 , struct V_129 , V_139 ) ;
F_58 ( & V_7 -> V_188 , V_143 , & V_7 -> V_137 ) ;
}
}
static int F_85 ( struct V_189 * V_190 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
struct V_6 * V_7 = F_57 ( V_190 , struct V_6 , V_190 ) ;
if ( V_7 -> V_191 -> V_192 )
return V_7 -> V_191 -> V_192 ( V_7 , V_104 , V_106 , V_107 ) ;
return 0 ;
}
static int F_86 ( struct V_6 * V_7 , struct V_103 * V_104 ,
struct V_105 * V_106 , struct V_107 * V_107 )
{
const T_5 V_113 = F_47 ( V_104 , V_106 , L_24 ) ;
struct V_91 * V_169 ;
int V_193 ;
T_1 V_117 , V_20 = V_106 -> time ;
T_6 V_12 ;
int V_118 , V_194 = V_106 -> V_118 ;
F_11 ( V_194 >= V_119 || V_194 < 0 ) ;
if ( V_194 > V_7 -> V_195 )
V_7 -> V_195 = V_194 ;
V_117 = V_7 -> V_120 [ V_194 ] ;
V_7 -> V_120 [ V_194 ] = V_20 ;
if ( V_117 )
V_12 = V_20 - V_117 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_28 ( L_27 V_15 L_28 , V_12 ) ;
return - 1 ;
}
V_169 = F_51 ( V_107 , - 1 , V_113 ) ;
V_7 -> V_196 [ V_194 ] = V_169 ;
printf ( L_50 ) ;
V_193 = 0 ;
if ( ! V_169 -> V_197 [ 0 ] ) {
if ( ! strcmp ( F_52 ( V_169 ) , L_42 ) ) {
V_169 -> V_197 [ 0 ] = '.' ;
V_169 -> V_197 [ 1 ] = ' ' ;
} else {
V_169 -> V_197 [ 0 ] = V_7 -> V_198 ;
V_169 -> V_197 [ 1 ] = V_7 -> V_199 ;
if ( V_7 -> V_198 < 'Z' ) {
V_7 -> V_198 ++ ;
} else {
V_7 -> V_198 = 'A' ;
if ( V_7 -> V_199 < '9' )
V_7 -> V_199 ++ ;
else
V_7 -> V_199 = '0' ;
}
}
V_193 = 1 ;
}
for ( V_118 = 0 ; V_118 <= V_7 -> V_195 ; V_118 ++ ) {
if ( V_118 != V_194 )
printf ( L_44 ) ;
else
printf ( L_51 ) ;
if ( V_7 -> V_196 [ V_118 ] )
printf ( L_52 , V_7 -> V_196 [ V_118 ] -> V_197 ) ;
else
printf ( L_53 ) ;
}
printf ( L_54 , ( double ) V_20 / 1e9 ) ;
if ( V_193 ) {
printf ( L_55 ,
V_169 -> V_197 , F_52 ( V_169 ) , V_169 -> V_109 ) ;
} else {
printf ( L_12 ) ;
}
return 0 ;
}
static int F_87 ( struct V_189 * V_190 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
struct V_6 * V_7 = F_57 ( V_190 , struct V_6 , V_190 ) ;
int V_194 = V_106 -> V_118 , V_60 = 0 ;
T_5 V_112 = F_47 ( V_104 , V_106 , L_23 ) ,
V_113 = F_47 ( V_104 , V_106 , L_24 ) ;
if ( V_7 -> V_200 [ V_194 ] != ( T_5 ) - 1 ) {
if ( V_7 -> V_200 [ V_194 ] != V_112 )
V_7 -> V_201 ++ ;
}
if ( V_7 -> V_191 -> V_202 )
V_60 = V_7 -> V_191 -> V_202 ( V_7 , V_104 , V_106 , V_107 ) ;
V_7 -> V_200 [ V_194 ] = V_113 ;
return V_60 ;
}
static int F_88 ( struct V_189 * V_190 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
struct V_6 * V_7 = F_57 ( V_190 , struct V_6 , V_190 ) ;
if ( V_7 -> V_191 -> V_203 )
return V_7 -> V_191 -> V_203 ( V_7 , V_104 , V_106 , V_107 ) ;
return 0 ;
}
static int F_89 ( struct V_189 * V_190 ,
union V_121 * V_21 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
struct V_6 * V_7 = F_57 ( V_190 , struct V_6 , V_190 ) ;
F_90 ( V_190 , V_21 , V_106 , V_107 ) ;
if ( V_7 -> V_191 -> V_204 )
return V_7 -> V_191 -> V_204 ( V_7 , V_21 , V_107 ) ;
return 0 ;
}
static int F_91 ( struct V_189 * V_190 ,
struct V_103 * V_104 ,
struct V_105 * V_106 ,
struct V_107 * V_107 )
{
struct V_6 * V_7 = F_57 ( V_190 , struct V_6 , V_190 ) ;
if ( V_7 -> V_191 -> V_205 )
return V_7 -> V_191 -> V_205 ( V_7 , V_104 , V_106 , V_107 ) ;
return 0 ;
}
static int F_92 ( struct V_189 * V_190 V_41 ,
union V_121 * V_21 V_41 ,
struct V_105 * V_106 ,
struct V_103 * V_104 ,
struct V_107 * V_107 )
{
int V_60 = 0 ;
if ( V_104 -> V_206 != NULL ) {
T_7 V_207 = V_104 -> V_206 ;
V_60 = V_207 ( V_190 , V_104 , V_106 , V_107 ) ;
}
return V_60 ;
}
static int F_93 ( struct V_6 * V_7 ,
struct V_208 * * V_209 )
{
const struct V_210 V_211 [] = {
{ L_56 , F_87 , } ,
{ L_57 , F_88 , } ,
{ L_58 , F_85 , } ,
{ L_59 , F_85 , } ,
{ L_60 , F_91 , } ,
} ;
struct V_208 * V_212 ;
struct V_213 V_214 = {
. V_215 = V_216 ,
. V_217 = V_218 ,
} ;
V_212 = F_94 ( & V_214 , false , & V_7 -> V_190 ) ;
if ( V_212 == NULL ) {
F_49 ( L_61 ) ;
return - 1 ;
}
F_95 ( & V_212 -> V_219 . V_220 ) ;
if ( F_96 ( V_212 , V_211 ) )
goto V_221;
if ( F_97 ( V_212 , L_62 ) ) {
int V_60 = F_98 ( V_212 , & V_7 -> V_190 ) ;
if ( V_60 ) {
F_28 ( L_63 , V_60 ) ;
goto V_221;
}
V_7 -> V_23 = V_212 -> V_222 . V_23 [ 0 ] ;
V_7 -> V_223 = V_212 -> V_222 . V_224 ;
V_7 -> V_225 = V_212 -> V_222 . V_23 [ V_226 ] ;
}
if ( V_209 )
* V_209 = V_212 ;
else
F_99 ( V_212 ) ;
return 0 ;
V_221:
F_99 ( V_212 ) ;
return - 1 ;
}
static void F_100 ( struct V_6 * V_7 )
{
if ( V_7 -> V_173 && V_7 -> V_172 ) {
printf ( L_64 ,
( double ) V_7 -> V_173 / ( double ) V_7 -> V_172 * 100.0 ,
V_7 -> V_173 , V_7 -> V_172 ) ;
}
if ( V_7 -> V_223 && V_7 -> V_23 ) {
printf ( L_65 ,
( double ) V_7 -> V_223 / ( double ) V_7 -> V_23 * 100.0 ,
V_7 -> V_223 , V_7 -> V_23 , V_7 -> V_225 ) ;
}
if ( V_7 -> V_201 && V_7 -> V_172 ) {
printf ( L_66 ,
( double ) V_7 -> V_201 / ( double ) V_7 -> V_172 * 100.0 ,
V_7 -> V_201 , V_7 -> V_172 ) ;
if ( V_7 -> V_223 )
printf ( L_67 ) ;
printf ( L_12 ) ;
}
}
static int F_101 ( struct V_6 * V_7 )
{
struct V_138 * V_116 ;
struct V_208 * V_212 ;
F_102 () ;
if ( F_93 ( V_7 , & V_212 ) )
return - 1 ;
F_81 ( V_7 ) ;
printf ( L_68 ) ;
printf ( L_69 ) ;
printf ( L_70 ) ;
V_116 = F_82 ( & V_7 -> V_188 ) ;
while ( V_116 ) {
struct V_129 * V_147 ;
V_147 = F_84 ( V_116 , struct V_129 , V_139 ) ;
F_73 ( V_7 , V_147 ) ;
V_116 = F_103 ( V_116 ) ;
}
printf ( L_70 ) ;
printf ( L_71 V_15 L_72 ,
( double ) V_7 -> V_176 / 1e6 , V_7 -> V_177 ) ;
printf ( L_73 ) ;
F_100 ( V_7 ) ;
printf ( L_12 ) ;
F_99 ( V_212 ) ;
return 0 ;
}
static int F_104 ( struct V_6 * V_7 )
{
V_7 -> V_195 = F_105 ( V_227 ) ;
F_102 () ;
if ( F_93 ( V_7 , NULL ) )
return - 1 ;
F_100 ( V_7 ) ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_6 ( V_7 ) ;
F_8 ( V_7 ) ;
F_44 ( V_7 ) ;
if ( F_93 ( V_7 , NULL ) )
return - 1 ;
printf ( L_74 , V_7 -> V_31 ) ;
printf ( L_75 , V_7 -> V_42 ) ;
printf ( L_76 , V_7 -> V_40 ) ;
if ( V_7 -> V_36 )
printf ( L_77 , V_7 -> V_36 ) ;
if ( V_7 -> V_38 )
printf ( L_78 , V_7 -> V_38 ) ;
if ( V_7 -> V_30 )
printf ( L_79 ,
V_7 -> V_30 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
F_37 ( V_7 ) ;
printf ( L_80 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_228 ; V_14 ++ )
F_43 ( V_7 ) ;
return 0 ;
}
static void F_107 ( struct V_6 * V_7 , const struct V_229 * V_230 ,
const char * const V_231 [] )
{
char * V_232 , * V_180 , * V_150 = F_108 ( V_7 -> V_233 ) ;
for ( V_180 = strtok_r ( V_150 , L_81 , & V_232 ) ;
V_180 ; V_180 = strtok_r ( NULL , L_81 , & V_232 ) ) {
if ( F_79 ( V_180 , & V_7 -> V_137 ) < 0 ) {
error ( L_82 , V_180 ) ;
F_109 ( V_231 , V_230 ) ;
}
}
free ( V_150 ) ;
F_79 ( L_17 , & V_7 -> V_149 ) ;
}
static int F_110 ( int V_234 , const char * * V_235 )
{
unsigned int V_236 , V_14 , V_53 ;
const char * * V_237 ;
const char * const V_238 [] = {
L_83 ,
L_84 ,
L_85 ,
L_86 , L_87 ,
L_88 , L_89 ,
L_90 , L_56 ,
L_90 , L_91 ,
L_90 , L_92 ,
L_90 , L_93 ,
L_90 , L_57 ,
L_90 , L_94 ,
L_90 , L_58 ,
L_90 , L_59 ,
L_90 , L_60 ,
} ;
V_236 = F_80 ( V_238 ) + V_234 - 1 ;
V_237 = calloc ( V_236 + 1 , sizeof( char * ) ) ;
if ( V_237 == NULL )
return - V_239 ;
for ( V_14 = 0 ; V_14 < F_80 ( V_238 ) ; V_14 ++ )
V_237 [ V_14 ] = F_108 ( V_238 [ V_14 ] ) ;
for ( V_53 = 1 ; V_53 < ( unsigned int ) V_234 ; V_53 ++ , V_14 ++ )
V_237 [ V_14 ] = V_235 [ V_53 ] ;
F_11 ( V_14 != V_236 ) ;
return F_111 ( V_14 , V_237 , NULL ) ;
}
int F_112 ( int V_234 , const char * * V_235 , const char * T_8 V_41 )
{
const char V_240 [] = L_95 ;
struct V_6 V_7 = {
. V_190 = {
. V_106 = F_92 ,
. V_44 = V_241 ,
. V_242 = V_243 ,
. V_124 = F_89 ,
. V_244 = true ,
} ,
. V_149 = F_113 ( V_7 . V_149 ) ,
. V_137 = F_113 ( V_7 . V_137 ) ,
. V_85 = V_245 ,
. V_88 = V_245 ,
. V_233 = V_240 ,
. V_228 = 10 ,
. V_170 = - 1 ,
. V_198 = 'A' ,
. V_199 = '0' ,
} ;
const struct V_229 V_246 [] = {
F_114 ( 's' , L_96 , & V_7 . V_233 , L_97 ,
L_98 ) ,
F_115 ( 'v' , L_99 , & V_50 ,
L_100 ) ,
F_116 ( 'C' , L_101 , & V_7 . V_170 ,
L_102 ) ,
F_117 ( 'D' , L_103 , & V_247 ,
L_104 ) ,
F_118 ()
} ;
const struct V_229 V_248 [] = {
F_119 ( 'r' , L_105 , & V_7 . V_228 ,
L_106 ) ,
F_115 ( 'v' , L_99 , & V_50 ,
L_100 ) ,
F_117 ( 'D' , L_103 , & V_247 ,
L_104 ) ,
F_118 ()
} ;
const struct V_229 V_249 [] = {
F_114 ( 'i' , L_107 , & V_216 , L_108 ,
L_109 ) ,
F_115 ( 'v' , L_99 , & V_50 ,
L_100 ) ,
F_117 ( 'D' , L_103 , & V_247 ,
L_104 ) ,
F_118 ()
} ;
const char * const V_250 [] = {
L_110 ,
NULL
} ;
const char * const V_251 [] = {
L_111 ,
NULL
} ;
const char * const V_252 [] = { L_83 , L_112 , L_113 ,
L_114 , L_115 , NULL } ;
const char * V_253 [] = {
NULL ,
NULL
} ;
struct V_254 V_255 = {
. V_192 = F_71 ,
. V_202 = F_69 ,
. V_203 = F_70 ,
. V_205 = F_72 ,
} ;
struct V_254 V_256 = {
. V_202 = F_86 ,
} ;
struct V_254 V_257 = {
. V_192 = F_45 ,
. V_202 = F_48 ,
. V_204 = F_50 ,
} ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_80 ( V_7 . V_200 ) ; V_14 ++ )
V_7 . V_200 [ V_14 ] = - 1 ;
V_234 = F_120 ( V_234 , V_235 , V_249 , V_252 ,
V_253 , V_258 ) ;
if ( ! V_234 )
F_109 ( V_253 , V_249 ) ;
if ( ! strcmp ( V_235 [ 0 ] , L_115 ) )
return F_121 ( V_234 , V_235 , T_8 ) ;
if ( ! strncmp ( V_235 [ 0 ] , L_116 , 3 ) ) {
return F_110 ( V_234 , V_235 ) ;
} else if ( ! strncmp ( V_235 [ 0 ] , L_117 , 3 ) ) {
V_7 . V_191 = & V_255 ;
if ( V_234 > 1 ) {
V_234 = F_122 ( V_234 , V_235 , V_246 , V_250 , 0 ) ;
if ( V_234 )
F_109 ( V_250 , V_246 ) ;
}
F_107 ( & V_7 , V_246 , V_250 ) ;
return F_101 ( & V_7 ) ;
} else if ( ! strcmp ( V_235 [ 0 ] , L_113 ) ) {
V_7 . V_191 = & V_256 ;
F_107 ( & V_7 , V_246 , V_250 ) ;
return F_104 ( & V_7 ) ;
} else if ( ! strncmp ( V_235 [ 0 ] , L_118 , 3 ) ) {
V_7 . V_191 = & V_257 ;
if ( V_234 ) {
V_234 = F_122 ( V_234 , V_235 , V_248 , V_251 , 0 ) ;
if ( V_234 )
F_109 ( V_251 , V_248 ) ;
}
return F_106 ( & V_7 ) ;
} else {
F_109 ( V_253 , V_249 ) ;
}
return 0 ;
}
