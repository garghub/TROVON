static T_1 F_1 ( void )
{
struct V_1 V_2 ;
F_2 ( V_3 , & V_2 ) ;
return V_2 . V_4 * 1000000000ULL + V_2 . V_5 ;
}
static void F_3 ( T_1 V_6 )
{
T_1 V_7 = F_1 () , V_8 ;
do {
V_8 = F_1 () ;
} while ( V_8 + V_9 < V_7 + V_6 );
}
static void F_4 ( T_1 V_6 )
{
struct V_1 V_2 ;
V_2 . V_5 = V_6 % 999999999 ;
V_2 . V_4 = V_6 / 999999999 ;
F_5 ( & V_2 , NULL ) ;
}
static void F_6 ( void )
{
T_1 V_7 , V_8 , V_10 , V_11 = 1000000000ULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_7 = F_1 () ;
F_3 ( 0 ) ;
V_8 = F_1 () ;
V_10 = V_8 - V_7 ;
V_11 = F_7 ( V_11 , V_10 ) ;
}
V_9 = V_11 ;
printf ( L_1 V_13 L_2 , V_11 ) ;
}
static void F_8 ( void )
{
T_1 V_7 , V_8 , V_10 , V_11 = 1000000000ULL ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 10 ; V_12 ++ ) {
V_7 = F_1 () ;
F_4 ( 10000 ) ;
V_8 = F_1 () ;
V_10 = V_8 - V_7 ;
V_11 = F_7 ( V_11 , V_10 ) ;
}
V_11 -= 10000 ;
V_14 = V_11 ;
printf ( L_3 V_13 L_2 , V_11 ) ;
}
static struct V_15 *
F_9 ( struct V_16 * V_17 , T_1 V_18 )
{
struct V_15 * V_19 = F_10 ( sizeof( * V_19 ) ) ;
unsigned long V_20 = V_17 -> V_21 ;
T_2 V_22 ;
V_19 -> V_18 = V_18 ;
V_19 -> V_23 = V_20 ;
V_17 -> V_21 ++ ;
V_22 = sizeof( struct V_15 * ) * V_17 -> V_21 ;
V_17 -> V_24 = realloc ( V_17 -> V_24 , V_22 ) ;
F_11 ( ! V_17 -> V_24 ) ;
V_17 -> V_24 [ V_20 ] = V_19 ;
return V_19 ;
}
static struct V_15 * F_12 ( struct V_16 * V_17 )
{
if ( ! V_17 -> V_21 )
return NULL ;
return V_17 -> V_24 [ V_17 -> V_21 - 1 ] ;
}
static void
F_13 ( struct V_16 * V_17 , T_1 V_18 , T_1 V_25 )
{
struct V_15 * V_19 , * V_26 = F_12 ( V_17 ) ;
if ( V_26 && V_26 -> type == V_27 ) {
V_28 ++ ;
V_26 -> V_25 += V_25 ;
return;
}
V_19 = F_9 ( V_17 , V_18 ) ;
V_19 -> type = V_27 ;
V_19 -> V_25 = V_25 ;
V_29 ++ ;
}
static void
F_14 ( struct V_16 * V_17 , T_1 V_18 ,
struct V_16 * V_30 )
{
struct V_15 * V_19 , * V_31 ;
V_19 = F_9 ( V_17 , V_18 ) ;
V_19 -> type = V_32 ;
V_19 -> V_30 = V_30 ;
V_31 = F_12 ( V_30 ) ;
if ( ! V_31 || V_31 -> type != V_33 ) {
V_34 ++ ;
return;
}
if ( V_31 -> V_35 ) {
V_36 ++ ;
return;
}
V_31 -> V_35 = F_10 ( sizeof( * V_31 -> V_35 ) ) ;
F_15 ( V_31 -> V_35 , 0 , 0 ) ;
V_31 -> V_37 = 1 ;
V_19 -> V_35 = V_31 -> V_35 ;
V_38 ++ ;
}
static void
F_16 ( struct V_16 * V_17 , T_1 V_18 ,
T_1 T_3 V_39 )
{
struct V_15 * V_19 = F_9 ( V_17 , V_18 ) ;
V_19 -> type = V_33 ;
V_40 ++ ;
}
static struct V_16 * F_17 ( unsigned long V_41 , const char * V_42 )
{
struct V_16 * V_17 ;
F_11 ( V_41 >= V_43 ) ;
V_17 = V_44 [ V_41 ] ;
if ( V_17 )
return V_17 ;
V_17 = F_10 ( sizeof( * V_17 ) ) ;
V_17 -> V_41 = V_41 ;
V_17 -> V_23 = V_45 ;
strcpy ( V_17 -> V_42 , V_42 ) ;
F_16 ( V_17 , 0 , 0 ) ;
V_44 [ V_41 ] = V_17 ;
V_45 ++ ;
V_46 = realloc ( V_46 , V_45 * sizeof( struct V_47 * ) ) ;
F_11 ( ! V_46 ) ;
V_46 [ V_17 -> V_23 ] = V_17 ;
if ( V_48 )
printf ( L_4 , V_45 , V_41 , V_42 ) ;
return V_17 ;
}
static void F_18 ( void )
{
struct V_16 * V_17 ;
unsigned long V_12 ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_17 = V_46 [ V_12 ] ;
printf ( L_5 ,
V_17 -> V_23 , V_17 -> V_42 , V_17 -> V_41 , V_17 -> V_21 ) ;
}
}
static void F_19 ( void )
{
struct V_16 * V_49 , * V_50 ;
unsigned long V_12 , V_51 ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_49 = V_46 [ V_12 ] ;
V_51 = V_12 + 1 ;
if ( V_51 == V_45 )
V_51 = 0 ;
V_50 = V_46 [ V_51 ] ;
F_14 ( V_49 , 0 , V_50 ) ;
}
}
static void
F_20 ( struct V_16 * T_4 V_39 , struct V_15 * V_52 )
{
int V_53 = 0 ;
switch ( V_52 -> type ) {
case V_27 :
F_3 ( V_52 -> V_25 ) ;
break;
case V_33 :
if ( V_52 -> V_35 )
V_53 = F_21 ( V_52 -> V_35 ) ;
F_11 ( V_53 ) ;
break;
case V_32 :
if ( V_52 -> V_35 )
V_53 = F_22 ( V_52 -> V_35 ) ;
F_11 ( V_53 ) ;
break;
case V_54 :
break;
default:
F_11 ( 1 ) ;
}
}
static T_1 F_23 ( void )
{
struct V_55 V_56 ;
T_1 V_57 ;
int V_58 ;
V_58 = F_24 ( V_59 , & V_56 ) ;
F_11 ( V_58 ) ;
V_57 = V_56 . V_60 . V_4 * 1e9 + V_56 . V_60 . V_61 * 1e3 ;
V_57 += V_56 . V_62 . V_4 * 1e9 + V_56 . V_62 . V_61 * 1e3 ;
return V_57 ;
}
static int F_25 ( void )
{
struct V_63 V_64 ;
int V_65 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_64 . type = V_66 ;
V_64 . V_67 = V_68 ;
V_65 = F_26 ( & V_64 , 0 , - 1 , - 1 , 0 ) ;
if ( V_65 < 0 )
F_27 ( L_6
L_7 , V_65 , strerror ( V_69 ) ) ;
return V_65 ;
}
static T_1 F_28 ( int V_65 )
{
T_1 V_70 ;
int V_53 ;
V_53 = F_29 ( V_65 , & V_70 , sizeof( V_70 ) ) ;
F_11 ( V_53 != sizeof( V_70 ) ) ;
return V_70 ;
}
static void * F_30 ( void * V_71 )
{
struct V_16 * T_4 = V_71 ;
T_1 V_72 , V_73 ;
unsigned long V_12 , V_53 ;
char V_74 [ 22 ] ;
int V_65 ;
sprintf ( V_74 , L_8 , T_4 -> V_42 ) ;
F_31 ( V_75 , V_74 ) ;
V_65 = F_25 () ;
V_76:
V_53 = F_22 ( & T_4 -> V_77 ) ;
F_11 ( V_53 ) ;
V_53 = F_32 ( & V_78 ) ;
F_11 ( V_53 ) ;
V_53 = F_33 ( & V_78 ) ;
F_11 ( V_53 ) ;
V_72 = F_28 ( V_65 ) ;
for ( V_12 = 0 ; V_12 < T_4 -> V_21 ; V_12 ++ ) {
T_4 -> V_26 = V_12 ;
F_20 ( T_4 , T_4 -> V_24 [ V_12 ] ) ;
}
V_73 = F_28 ( V_65 ) ;
T_4 -> V_79 = V_73 - V_72 ;
V_53 = F_22 ( & T_4 -> V_80 ) ;
F_11 ( V_53 ) ;
V_53 = F_32 ( & V_81 ) ;
F_11 ( V_53 ) ;
V_53 = F_33 ( & V_81 ) ;
F_11 ( V_53 ) ;
goto V_76;
}
static void F_34 ( void )
{
struct V_16 * V_17 ;
T_5 V_64 ;
unsigned long V_12 ;
int V_58 ;
V_58 = F_35 ( & V_64 ) ;
F_11 ( V_58 ) ;
V_58 = F_36 ( & V_64 ,
( T_2 ) F_37 ( 16 * 1024 , V_82 ) ) ;
F_11 ( V_58 ) ;
V_58 = F_32 ( & V_78 ) ;
F_11 ( V_58 ) ;
V_58 = F_32 ( & V_81 ) ;
F_11 ( V_58 ) ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_17 = V_46 [ V_12 ] ;
F_15 ( & V_17 -> V_83 , 0 , 0 ) ;
F_15 ( & V_17 -> V_77 , 0 , 0 ) ;
F_15 ( & V_17 -> V_80 , 0 , 0 ) ;
V_17 -> V_26 = 0 ;
V_58 = F_38 ( & V_17 -> V_84 , & V_64 , F_30 , V_17 ) ;
F_11 ( V_58 ) ;
}
}
static void F_39 ( void )
{
T_1 V_72 , V_73 ;
struct V_16 * V_17 ;
unsigned long V_12 , V_53 ;
V_85 = F_1 () ;
V_79 = 0 ;
F_33 ( & V_81 ) ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_17 = V_46 [ V_12 ] ;
V_53 = F_21 ( & V_17 -> V_77 ) ;
F_11 ( V_53 ) ;
F_15 ( & V_17 -> V_77 , 0 , 0 ) ;
}
V_53 = F_32 ( & V_81 ) ;
F_11 ( V_53 ) ;
V_72 = F_23 () ;
F_33 ( & V_78 ) ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_17 = V_46 [ V_12 ] ;
V_53 = F_21 ( & V_17 -> V_80 ) ;
F_11 ( V_53 ) ;
F_15 ( & V_17 -> V_80 , 0 , 0 ) ;
V_79 += V_17 -> V_79 ;
V_17 -> V_79 = 0 ;
}
V_73 = F_23 () ;
if ( ! V_86 )
V_86 = V_79 ;
V_86 = ( V_86 * 9 + V_79 ) / 10 ;
V_87 = V_73 - V_72 ;
if ( ! V_88 )
V_88 = V_87 ;
V_88 = ( V_88 * 9 +
V_87 ) / 10 ;
V_53 = F_32 ( & V_78 ) ;
F_11 ( V_53 ) ;
for ( V_12 = 0 ; V_12 < V_45 ; V_12 ++ ) {
V_17 = V_46 [ V_12 ] ;
F_15 ( & V_17 -> V_83 , 0 , 0 ) ;
V_17 -> V_26 = 0 ;
}
}
static void F_40 ( void )
{
T_1 V_7 , V_8 , V_10 , V_89 , V_90 ;
V_7 = F_1 () ;
F_39 () ;
V_8 = F_1 () ;
V_10 = V_8 - V_7 ;
V_91 += V_10 ;
V_92 ++ ;
V_89 = V_91 / V_92 ;
if ( V_10 < V_89 )
V_90 = V_89 - V_10 ;
else
V_90 = V_10 - V_89 ;
V_93 += V_90 ;
if ( ! V_94 )
V_94 = V_10 ;
V_94 = ( V_94 * 9 + V_10 ) / 10 ;
printf ( L_9 ,
V_92 , ( double ) V_10 / 1000000.0 ) ;
printf ( L_10 ,
( double ) V_94 / 1e6 ) ;
printf ( L_11 ,
( double ) V_79 / 1e6 , ( double ) V_86 / 1e6 ) ;
#if 0
printf(" [%0.2f / %0.2f]",
(double)parent_cpu_usage/1e6,
(double)runavg_parent_cpu_usage/1e6);
#endif
printf ( L_12 ) ;
if ( V_95 )
printf ( L_13 , V_95 ) ;
V_95 = 0 ;
}
static void F_41 ( void )
{
T_1 V_7 , V_8 ;
V_7 = F_1 () ;
F_3 ( 1e6 ) ;
V_8 = F_1 () ;
printf ( L_14 V_13 L_2 , V_8 - V_7 ) ;
V_7 = F_1 () ;
F_4 ( 1e6 ) ;
V_8 = F_1 () ;
printf ( L_15 V_13 L_2 , V_8 - V_7 ) ;
}
static void
F_42 ( struct V_96 * V_97 ,
struct V_98 * T_6 V_39 ,
struct V_19 * V_19 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
struct V_16 * V_99 , * V_30 ;
if ( V_48 ) {
printf ( L_16 , V_19 ) ;
printf ( L_17 ,
V_97 -> V_100 ,
V_97 -> V_42 ,
V_97 -> V_41 ) ;
}
V_99 = F_17 ( V_97 -> V_100 , L_18 ) ;
V_30 = F_17 ( V_97 -> V_41 , V_97 -> V_42 ) ;
F_14 ( V_99 , V_18 , V_30 ) ;
}
static void
F_43 ( struct V_101 * V_102 ,
struct V_98 * T_6 V_39 ,
struct V_19 * V_19 ,
int T_7 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_16 * V_103 , V_39 * V_104 ;
T_1 V_105 ;
T_8 V_10 ;
if ( V_48 )
printf ( L_19 , V_19 ) ;
if ( T_7 >= V_106 || T_7 < 0 )
return;
V_105 = V_107 [ T_7 ] ;
if ( V_105 )
V_10 = V_18 - V_105 ;
else
V_10 = 0 ;
if ( V_10 < 0 )
F_27 ( L_20 V_13 L_21 , V_10 ) ;
if ( V_48 ) {
printf ( L_22 V_13 L_23 ,
V_102 -> V_108 , V_102 -> V_109 ,
V_102 -> V_110 , V_102 -> V_111 ,
V_10 ) ;
}
V_103 = F_17 ( V_102 -> V_109 , V_102 -> V_108 ) ;
V_104 = F_17 ( V_102 -> V_111 , V_102 -> V_110 ) ;
V_107 [ T_7 ] = V_18 ;
F_13 ( V_103 , V_18 , V_10 ) ;
F_16 ( V_103 , V_18 , V_102 -> V_112 ) ;
}
static void
F_44 ( struct V_113 * V_114 ,
struct V_19 * V_19 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
if ( V_48 ) {
printf ( L_24 , V_19 ) ;
printf ( L_25 , V_114 -> V_115 , V_114 -> V_116 ) ;
printf ( L_26 , V_114 -> V_117 , V_114 -> V_118 ) ;
}
F_17 ( V_114 -> V_116 , V_114 -> V_115 ) ;
F_17 ( V_114 -> V_118 , V_114 -> V_117 ) ;
}
static int
F_45 ( struct V_119 * V_120 , struct V_121 * V_122 , struct V_121 * V_123 )
{
struct V_124 * V_125 ;
int V_53 = 0 ;
F_11 ( F_46 ( V_120 ) ) ;
F_47 (sort, list, list) {
V_53 = V_125 -> V_126 ( V_122 , V_123 ) ;
if ( V_53 )
return V_53 ;
}
return V_53 ;
}
static struct V_121 *
F_48 ( struct V_127 * V_128 , struct V_84 * V_84 ,
struct V_119 * V_129 )
{
struct V_130 * V_131 = V_128 -> V_130 ;
struct V_121 V_132 = { . V_84 = V_84 } ;
while ( V_131 ) {
struct V_121 * V_24 ;
int V_126 ;
V_24 = F_49 ( V_131 , struct V_121 , V_131 ) ;
V_126 = F_45 ( V_129 , & V_132 , V_24 ) ;
if ( V_126 > 0 )
V_131 = V_131 -> V_133 ;
else if ( V_126 < 0 )
V_131 = V_131 -> V_134 ;
else {
F_11 ( V_84 != V_24 -> V_84 ) ;
return V_24 ;
}
}
return NULL ;
}
static void
F_50 ( struct V_127 * V_128 , struct V_121 * V_135 ,
struct V_119 * V_129 )
{
struct V_130 * * V_136 = & ( V_128 -> V_130 ) , * V_137 = NULL ;
while ( * V_136 ) {
struct V_121 * V_138 ;
int V_126 ;
V_138 = F_49 ( * V_136 , struct V_121 , V_131 ) ;
V_137 = * V_136 ;
V_126 = F_45 ( V_129 , V_135 , V_138 ) ;
if ( V_126 > 0 )
V_136 = & ( ( * V_136 ) -> V_133 ) ;
else
V_136 = & ( ( * V_136 ) -> V_134 ) ;
}
F_51 ( & V_135 -> V_131 , V_137 , V_136 ) ;
F_52 ( & V_135 -> V_131 , V_128 ) ;
}
static void F_53 ( struct V_84 * V_84 )
{
struct V_121 * V_24 = F_10 ( sizeof( * V_24 ) ) ;
if ( ! V_24 )
F_27 ( L_27 ) ;
V_24 -> V_84 = V_84 ;
F_54 ( & V_24 -> V_139 ) ;
F_50 ( & V_140 , V_24 , & V_141 ) ;
}
static void
F_55 ( struct V_113 * V_114 V_39 ,
struct V_19 * V_19 V_39 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
}
V_39
static char F_56 ( struct V_101 * V_102 )
{
const char * V_142 = V_143 ;
return V_142 [ V_102 -> V_112 ] ;
}
static void
F_57 ( struct V_121 * V_24 ,
char V_144 ,
T_1 V_18 )
{
struct V_145 * V_52 = F_10 ( sizeof( * V_52 ) ) ;
if ( ! V_52 )
F_27 ( L_28 ) ;
V_52 -> V_146 = V_18 ;
if ( V_144 == 'R' ) {
V_52 -> V_147 = V_148 ;
V_52 -> V_149 = V_52 -> V_146 ;
}
F_58 ( & V_52 -> V_120 , & V_24 -> V_139 ) ;
}
static void
F_59 ( struct V_121 * V_24 , T_1 V_10 , T_1 V_18 V_39 )
{
struct V_145 * V_52 ;
F_11 ( F_46 ( & V_24 -> V_139 ) ) ;
V_52 = F_60 ( V_24 -> V_139 . V_103 , struct V_145 , V_120 ) ;
V_52 -> V_70 += V_10 ;
V_24 -> V_150 += V_10 ;
}
static void
F_61 ( struct V_121 * V_24 , T_1 V_18 )
{
struct V_145 * V_52 ;
T_1 V_10 ;
if ( F_46 ( & V_24 -> V_139 ) )
return;
V_52 = F_60 ( V_24 -> V_139 . V_103 , struct V_145 , V_120 ) ;
if ( V_52 -> V_147 != V_148 )
return;
if ( V_18 < V_52 -> V_149 ) {
V_52 -> V_147 = V_151 ;
return;
}
V_52 -> V_147 = V_152 ;
V_52 -> V_153 = V_18 ;
V_10 = V_52 -> V_153 - V_52 -> V_149 ;
V_24 -> V_154 += V_10 ;
if ( V_10 > V_24 -> V_155 ) {
V_24 -> V_155 = V_10 ;
V_24 -> V_156 = V_18 ;
}
V_24 -> V_157 ++ ;
}
static void
F_62 ( struct V_101 * V_102 ,
struct V_98 * T_6 ,
struct V_19 * V_19 V_39 ,
int T_7 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_121 * V_158 , * V_159 ;
struct V_84 * V_160 , * V_161 ;
T_1 V_105 ;
T_8 V_10 ;
F_11 ( T_7 >= V_106 || T_7 < 0 ) ;
V_105 = V_107 [ T_7 ] ;
V_107 [ T_7 ] = V_18 ;
if ( V_105 )
V_10 = V_18 - V_105 ;
else
V_10 = 0 ;
if ( V_10 < 0 )
F_27 ( L_20 V_13 L_21 , V_10 ) ;
V_160 = F_63 ( T_6 , V_102 -> V_109 ) ;
V_161 = F_63 ( T_6 , V_102 -> V_111 ) ;
V_158 = F_48 ( & V_140 , V_160 , & V_141 ) ;
if ( ! V_158 ) {
F_53 ( V_160 ) ;
V_158 = F_48 ( & V_140 , V_160 , & V_141 ) ;
if ( ! V_158 )
F_27 ( L_29 ) ;
}
F_57 ( V_158 , F_56 ( V_102 ) , V_18 ) ;
V_159 = F_48 ( & V_140 , V_161 , & V_141 ) ;
if ( ! V_159 ) {
F_53 ( V_161 ) ;
V_159 = F_48 ( & V_140 , V_161 , & V_141 ) ;
if ( ! V_159 )
F_27 ( L_30 ) ;
F_57 ( V_159 , 'R' , V_18 ) ;
}
F_61 ( V_159 , V_18 ) ;
}
static void
F_64 ( struct V_162 * V_163 ,
struct V_98 * T_6 ,
struct V_19 * V_19 V_39 ,
int T_7 ,
T_1 V_18 ,
struct V_84 * T_9 V_39 )
{
struct V_84 * V_84 = F_63 ( T_6 , V_163 -> V_41 ) ;
struct V_121 * V_24 = F_48 ( & V_140 , V_84 , & V_141 ) ;
F_11 ( T_7 >= V_106 || T_7 < 0 ) ;
if ( ! V_24 ) {
F_53 ( V_84 ) ;
V_24 = F_48 ( & V_140 , V_84 , & V_141 ) ;
if ( ! V_24 )
F_27 ( L_30 ) ;
F_57 ( V_24 , 'R' , V_18 ) ;
}
F_59 ( V_24 , V_163 -> V_70 , V_18 ) ;
}
static void
F_65 ( struct V_96 * V_97 ,
struct V_98 * T_6 ,
struct V_19 * T_10 V_39 ,
int T_7 V_39 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_121 * V_24 ;
struct V_145 * V_52 ;
struct V_84 * V_30 ;
if ( ! V_97 -> V_164 )
return;
V_30 = F_63 ( T_6 , V_97 -> V_41 ) ;
V_24 = F_48 ( & V_140 , V_30 , & V_141 ) ;
if ( ! V_24 ) {
F_53 ( V_30 ) ;
V_24 = F_48 ( & V_140 , V_30 , & V_141 ) ;
if ( ! V_24 )
F_27 ( L_31 ) ;
F_57 ( V_24 , 'S' , V_18 ) ;
}
F_11 ( F_46 ( & V_24 -> V_139 ) ) ;
V_52 = F_60 ( V_24 -> V_139 . V_103 , struct V_145 , V_120 ) ;
if ( V_165 == - 1 && V_52 -> V_147 != V_166 )
V_167 ++ ;
V_168 ++ ;
if ( V_52 -> V_146 > V_18 ) {
V_169 ++ ;
return;
}
V_52 -> V_147 = V_148 ;
V_52 -> V_149 = V_18 ;
}
static void
F_66 ( struct V_170 * V_171 ,
struct V_98 * T_6 ,
struct V_19 * T_10 V_39 ,
int T_7 V_39 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_121 * V_24 ;
struct V_145 * V_52 ;
struct V_84 * V_172 ;
if ( V_165 == - 1 )
return;
V_172 = F_63 ( T_6 , V_171 -> V_41 ) ;
V_24 = F_48 ( & V_140 , V_172 , & V_141 ) ;
if ( ! V_24 ) {
F_53 ( V_172 ) ;
F_17 ( V_172 -> V_41 , V_172 -> V_42 ) ;
V_24 = F_48 ( & V_140 , V_172 , & V_141 ) ;
if ( ! V_24 )
F_27 ( L_32 ) ;
F_57 ( V_24 , 'R' , V_18 ) ;
}
F_11 ( F_46 ( & V_24 -> V_139 ) ) ;
V_52 = F_60 ( V_24 -> V_139 . V_103 , struct V_145 , V_120 ) ;
V_52 -> V_153 = V_52 -> V_146 = V_52 -> V_149 = V_18 ;
V_168 ++ ;
if ( V_52 -> V_146 > V_18 )
V_169 ++ ;
}
static void F_67 ( struct V_121 * V_139 )
{
int V_12 ;
int V_53 ;
T_1 V_173 ;
if ( ! V_139 -> V_157 )
return;
if ( ! strcmp ( V_139 -> V_84 -> V_42 , L_33 ) )
return;
V_174 += V_139 -> V_150 ;
V_175 += V_139 -> V_157 ;
V_53 = printf ( L_34 , V_139 -> V_84 -> V_42 , V_139 -> V_84 -> V_41 ) ;
for ( V_12 = 0 ; V_12 < 24 - V_53 ; V_12 ++ )
printf ( L_35 ) ;
V_173 = V_139 -> V_154 / V_139 -> V_157 ;
printf ( L_36 V_13 L_37 ,
( double ) V_139 -> V_150 / 1e6 ,
V_139 -> V_157 , ( double ) V_173 / 1e6 ,
( double ) V_139 -> V_155 / 1e6 ,
( double ) V_139 -> V_156 / 1e9 ) ;
}
static int F_68 ( struct V_121 * V_122 , struct V_121 * V_123 )
{
if ( V_122 -> V_84 -> V_41 < V_123 -> V_84 -> V_41 )
return - 1 ;
if ( V_122 -> V_84 -> V_41 > V_123 -> V_84 -> V_41 )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_121 * V_122 , struct V_121 * V_123 )
{
T_1 V_176 , V_177 ;
if ( ! V_122 -> V_157 )
return - 1 ;
if ( ! V_123 -> V_157 )
return 1 ;
V_176 = V_122 -> V_154 / V_122 -> V_157 ;
V_177 = V_123 -> V_154 / V_123 -> V_157 ;
if ( V_176 < V_177 )
return - 1 ;
if ( V_176 > V_177 )
return 1 ;
return 0 ;
}
static int F_70 ( struct V_121 * V_122 , struct V_121 * V_123 )
{
if ( V_122 -> V_155 < V_123 -> V_155 )
return - 1 ;
if ( V_122 -> V_155 > V_123 -> V_155 )
return 1 ;
return 0 ;
}
static int F_71 ( struct V_121 * V_122 , struct V_121 * V_123 )
{
if ( V_122 -> V_157 < V_123 -> V_157 )
return - 1 ;
if ( V_122 -> V_157 > V_123 -> V_157 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_121 * V_122 , struct V_121 * V_123 )
{
if ( V_122 -> V_150 < V_123 -> V_150 )
return - 1 ;
if ( V_122 -> V_150 > V_123 -> V_150 )
return 1 ;
return 0 ;
}
static int F_73 ( const char * V_178 , struct V_119 * V_120 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_179 ; V_12 ++ ) {
if ( ! strcmp ( V_180 [ V_12 ] -> V_181 , V_178 ) ) {
F_58 ( & V_180 [ V_12 ] -> V_120 , V_120 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_74 ( void )
{
struct V_130 * V_131 ;
for (; ; ) {
struct V_121 * V_135 ;
V_131 = F_75 ( & V_140 ) ;
if ( ! V_131 )
break;
F_76 ( V_131 , & V_140 ) ;
V_135 = F_77 ( V_131 , struct V_121 , V_131 ) ;
F_50 ( & V_182 , V_135 , & V_129 ) ;
}
}
static void
F_78 ( void * V_135 , struct V_98 * T_6 ,
struct V_19 * V_19 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
struct V_96 V_97 ;
F_79 ( V_97 , V_19 , V_135 ) ;
F_80 ( V_97 , V_42 , V_19 , V_135 ) ;
F_81 ( V_97 , V_41 , V_19 , V_135 ) ;
F_81 ( V_97 , V_183 , V_19 , V_135 ) ;
F_81 ( V_97 , V_164 , V_19 , V_135 ) ;
F_81 ( V_97 , T_7 , V_19 , V_135 ) ;
if ( V_184 -> V_97 )
V_184 -> V_97 ( & V_97 , T_6 , V_19 ,
T_7 , V_18 , V_84 ) ;
}
static void
F_82 ( struct V_101 * V_102 ,
struct V_98 * T_6 ,
struct V_19 * V_19 V_39 ,
int V_185 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_84 * V_160 V_39 , * V_161 ;
int V_186 ;
T_1 V_105 ;
T_8 V_10 ;
int T_7 ;
F_11 ( V_185 >= V_106 || V_185 < 0 ) ;
if ( V_185 > V_187 )
V_187 = V_185 ;
V_105 = V_107 [ V_185 ] ;
V_107 [ V_185 ] = V_18 ;
if ( V_105 )
V_10 = V_18 - V_105 ;
else
V_10 = 0 ;
if ( V_10 < 0 )
F_27 ( L_20 V_13 L_21 , V_10 ) ;
V_160 = F_63 ( T_6 , V_102 -> V_109 ) ;
V_161 = F_63 ( T_6 , V_102 -> V_111 ) ;
V_188 [ V_185 ] = V_161 ;
printf ( L_38 ) ;
V_186 = 0 ;
if ( ! V_161 -> V_189 [ 0 ] ) {
V_161 -> V_189 [ 0 ] = V_190 ;
V_161 -> V_189 [ 1 ] = V_191 ;
if ( V_190 < 'Z' ) {
V_190 ++ ;
} else {
V_190 = 'A' ;
if ( V_191 < '9' ) {
V_191 ++ ;
} else {
V_191 = '0' ;
}
}
V_186 = 1 ;
}
for ( T_7 = 0 ; T_7 <= V_187 ; T_7 ++ ) {
if ( T_7 != V_185 )
printf ( L_35 ) ;
else
printf ( L_39 ) ;
if ( V_188 [ T_7 ] ) {
if ( V_188 [ T_7 ] -> V_41 )
printf ( L_40 , V_188 [ T_7 ] -> V_189 ) ;
else
printf ( L_41 ) ;
} else
printf ( L_42 ) ;
}
printf ( L_43 , ( double ) V_18 / 1e9 ) ;
if ( V_186 ) {
printf ( L_44 ,
V_161 -> V_189 , V_161 -> V_42 , V_161 -> V_41 ) ;
} else {
printf ( L_12 ) ;
}
}
static void
F_83 ( void * V_135 , struct V_98 * T_6 ,
struct V_19 * V_19 ,
int V_185 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
struct V_101 V_102 ;
F_79 ( V_102 , V_19 , V_135 ) ;
F_80 ( V_102 , V_108 , V_19 , V_135 ) ;
F_81 ( V_102 , V_109 , V_19 , V_135 ) ;
F_81 ( V_102 , V_192 , V_19 , V_135 ) ;
F_81 ( V_102 , V_112 , V_19 , V_135 ) ;
F_80 ( V_102 , V_110 , V_19 , V_135 ) ;
F_81 ( V_102 , V_111 , V_19 , V_135 ) ;
F_81 ( V_102 , V_193 , V_19 , V_135 ) ;
if ( V_194 [ V_185 ] != ( V_195 ) - 1 ) {
if ( V_194 [ V_185 ] != V_102 . V_109 )
V_196 ++ ;
}
if ( V_184 -> V_102 )
V_184 -> V_102 ( & V_102 , T_6 , V_19 ,
V_185 , V_18 , V_84 ) ;
V_194 [ V_185 ] = V_102 . V_111 ;
}
static void
F_84 ( void * V_135 , struct V_98 * T_6 ,
struct V_19 * V_19 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
struct V_162 V_163 ;
F_80 ( V_163 , V_42 , V_19 , V_135 ) ;
F_81 ( V_163 , V_41 , V_19 , V_135 ) ;
F_81 ( V_163 , V_70 , V_19 , V_135 ) ;
F_81 ( V_163 , V_197 , V_19 , V_135 ) ;
if ( V_184 -> V_163 )
V_184 -> V_163 ( & V_163 , T_6 , V_19 , T_7 , V_18 , V_84 ) ;
}
static void
F_85 ( void * V_135 ,
struct V_19 * V_19 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
struct V_113 V_114 ;
F_79 ( V_114 , V_19 , V_135 ) ;
F_80 ( V_114 , V_115 , V_19 , V_135 ) ;
F_81 ( V_114 , V_116 , V_19 , V_135 ) ;
F_80 ( V_114 , V_117 , V_19 , V_135 ) ;
F_81 ( V_114 , V_118 , V_19 , V_135 ) ;
if ( V_184 -> V_114 )
V_184 -> V_114 ( & V_114 , V_19 ,
T_7 , V_18 , V_84 ) ;
}
static void
F_86 ( struct V_19 * V_19 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
if ( V_48 )
printf ( L_45 , V_19 ) ;
}
static void
F_87 ( void * V_135 , struct V_98 * T_6 ,
struct V_19 * V_19 ,
int T_7 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
struct V_170 V_171 ;
F_79 ( V_171 , V_19 , V_135 ) ;
F_80 ( V_171 , V_42 , V_19 , V_135 ) ;
F_81 ( V_171 , V_41 , V_19 , V_135 ) ;
F_81 ( V_171 , V_183 , V_19 , V_135 ) ;
F_81 ( V_171 , T_7 , V_19 , V_135 ) ;
if ( V_184 -> V_171 )
V_184 -> V_171 ( & V_171 , T_6 ,
V_19 , T_7 , V_18 , V_84 ) ;
}
static void F_88 ( union V_198 * T_11 V_39 ,
struct V_98 * T_6 , void * V_135 , int T_7 ,
T_1 V_18 , struct V_84 * V_84 )
{
struct V_19 * V_19 ;
int type ;
type = F_89 ( V_135 ) ;
V_19 = F_90 ( type ) ;
if ( ! strcmp ( V_19 -> V_181 , L_46 ) )
F_83 ( V_135 , T_6 , V_19 , T_7 , V_18 , V_84 ) ;
if ( ! strcmp ( V_19 -> V_181 , L_47 ) )
F_84 ( V_135 , T_6 , V_19 , T_7 , V_18 , V_84 ) ;
if ( ! strcmp ( V_19 -> V_181 , L_48 ) )
F_78 ( V_135 , T_6 , V_19 , T_7 , V_18 , V_84 ) ;
if ( ! strcmp ( V_19 -> V_181 , L_49 ) )
F_78 ( V_135 , T_6 , V_19 , T_7 , V_18 , V_84 ) ;
if ( ! strcmp ( V_19 -> V_181 , L_50 ) )
F_85 ( V_135 , V_19 , T_7 , V_18 , V_84 ) ;
if ( ! strcmp ( V_19 -> V_181 , L_51 ) )
F_86 ( V_19 , T_7 , V_18 , V_84 ) ;
if ( ! strcmp ( V_19 -> V_181 , L_52 ) )
F_87 ( V_135 , T_6 , V_19 , T_7 , V_18 , V_84 ) ;
}
static int F_91 ( union V_198 * V_19 ,
struct V_199 * V_200 ,
struct V_201 * T_12 V_39 ,
struct V_98 * T_6 )
{
struct V_84 * V_84 ;
if ( ! ( T_6 -> V_202 & V_203 ) )
return 0 ;
V_84 = F_63 ( T_6 , V_200 -> V_41 ) ;
if ( V_84 == NULL ) {
F_92 ( L_53 ,
V_19 -> V_204 . type ) ;
return - 1 ;
}
F_93 ( L_54 , V_84 -> V_42 , V_84 -> V_41 ) ;
if ( V_165 != - 1 && V_165 != ( int ) V_200 -> T_7 )
return 0 ;
F_88 ( V_19 , T_6 , V_200 -> V_205 , V_200 -> T_7 ,
V_200 -> time , V_84 ) ;
return 0 ;
}
static void F_94 ( bool V_206 , struct V_98 * * V_207 )
{
int V_58 = - V_208 ;
struct V_98 * T_6 = F_95 ( V_209 , V_210 ,
0 , false , & V_211 ) ;
if ( T_6 == NULL )
F_27 ( L_55 ) ;
if ( F_96 ( T_6 , L_56 ) ) {
V_58 = F_97 ( T_6 , & V_211 ) ;
if ( V_58 )
F_27 ( L_57 , V_58 ) ;
V_21 = T_6 -> V_212 . V_213 . V_21 [ 0 ] ;
V_214 = T_6 -> V_212 . V_213 . V_215 ;
V_216 = T_6 -> V_212 . V_213 . V_21 [ V_217 ] ;
}
if ( V_206 )
F_98 ( T_6 ) ;
if ( V_207 )
* V_207 = T_6 ;
}
static void F_99 ( void )
{
if ( V_169 && V_168 ) {
printf ( L_58 ,
( double ) V_169 / ( double ) V_168 * 100.0 ,
V_169 , V_168 ) ;
}
if ( V_214 && V_21 ) {
printf ( L_59 ,
( double ) V_214 / ( double ) V_21 * 100.0 ,
V_214 , V_21 , V_216 ) ;
}
if ( V_167 && V_168 ) {
printf ( L_60 ,
( double ) V_167 / ( double ) V_168 * 100.0 ,
V_167 , V_168 ) ;
if ( V_214 )
printf ( L_61 ) ;
printf ( L_12 ) ;
}
if ( V_196 && V_168 ) {
printf ( L_62 ,
( double ) V_196 / ( double ) V_168 * 100.0 ,
V_196 , V_168 ) ;
if ( V_214 )
printf ( L_61 ) ;
printf ( L_12 ) ;
}
}
static void F_100 ( void )
{
struct V_130 * V_104 ;
struct V_98 * T_6 ;
F_101 () ;
F_94 ( false , & T_6 ) ;
F_74 () ;
printf ( L_63 ) ;
printf ( L_64 ) ;
printf ( L_65 ) ;
V_104 = F_75 ( & V_182 ) ;
while ( V_104 ) {
struct V_121 * V_139 ;
V_139 = F_77 ( V_104 , struct V_121 , V_131 ) ;
F_67 ( V_139 ) ;
V_104 = F_102 ( V_104 ) ;
}
printf ( L_66 ) ;
printf ( L_67 V_13 L_68 ,
( double ) V_174 / 1e6 , V_175 ) ;
printf ( L_69 ) ;
F_99 () ;
printf ( L_12 ) ;
F_98 ( T_6 ) ;
}
static void F_103 ( void )
{
V_187 = F_104 ( V_218 ) ;
F_101 () ;
F_94 ( true , NULL ) ;
F_99 () ;
}
static void F_105 ( void )
{
unsigned long V_12 ;
F_6 () ;
F_8 () ;
F_41 () ;
F_94 ( true , NULL ) ;
printf ( L_70 , V_29 ) ;
printf ( L_71 , V_40 ) ;
printf ( L_72 , V_38 ) ;
if ( V_34 )
printf ( L_73 , V_34 ) ;
if ( V_36 )
printf ( L_74 , V_36 ) ;
if ( V_28 )
printf ( L_75 ,
V_28 ) ;
F_18 () ;
F_19 () ;
F_34 () ;
printf ( L_76 ) ;
for ( V_12 = 0 ; V_12 < V_219 ; V_12 ++ )
F_40 () ;
}
static void F_106 ( void )
{
char * V_220 , * V_178 , * V_142 = F_107 ( V_221 ) ;
for ( V_178 = strtok_r ( V_142 , L_77 , & V_220 ) ;
V_178 ; V_178 = strtok_r ( NULL , L_77 , & V_220 ) ) {
if ( F_73 ( V_178 , & V_129 ) < 0 ) {
error ( L_78 , V_178 ) ;
F_108 ( V_222 , V_223 ) ;
}
}
free ( V_142 ) ;
F_73 ( L_79 , & V_141 ) ;
}
static int F_109 ( int V_224 , const char * * V_225 )
{
unsigned int V_226 , V_12 , V_51 ;
const char * * V_227 ;
V_226 = F_110 ( V_228 ) + V_224 - 1 ;
V_227 = calloc ( V_226 + 1 , sizeof( char * ) ) ;
if ( V_227 == NULL )
return - V_229 ;
for ( V_12 = 0 ; V_12 < F_110 ( V_228 ) ; V_12 ++ )
V_227 [ V_12 ] = F_107 ( V_228 [ V_12 ] ) ;
for ( V_51 = 1 ; V_51 < ( unsigned int ) V_224 ; V_51 ++ , V_12 ++ )
V_227 [ V_12 ] = V_225 [ V_51 ] ;
F_11 ( V_12 != V_226 ) ;
return F_111 ( V_12 , V_227 , NULL ) ;
}
int F_112 ( int V_224 , const char * * V_225 , const char * T_13 V_39 )
{
V_224 = F_113 ( V_224 , V_225 , V_230 , V_231 ,
V_232 ) ;
if ( ! V_224 )
F_108 ( V_231 , V_230 ) ;
if ( ! strcmp ( V_225 [ 0 ] , L_80 ) )
return F_114 ( V_224 , V_225 , T_13 ) ;
F_115 () ;
if ( ! strncmp ( V_225 [ 0 ] , L_81 , 3 ) ) {
return F_109 ( V_224 , V_225 ) ;
} else if ( ! strncmp ( V_225 [ 0 ] , L_82 , 3 ) ) {
V_184 = & V_233 ;
if ( V_224 > 1 ) {
V_224 = F_113 ( V_224 , V_225 , V_223 , V_222 , 0 ) ;
if ( V_224 )
F_108 ( V_222 , V_223 ) ;
}
F_106 () ;
F_100 () ;
} else if ( ! strcmp ( V_225 [ 0 ] , L_83 ) ) {
V_184 = & V_234 ;
F_106 () ;
F_103 () ;
} else if ( ! strncmp ( V_225 [ 0 ] , L_84 , 3 ) ) {
V_184 = & V_235 ;
if ( V_224 ) {
V_224 = F_113 ( V_224 , V_225 , V_236 , V_237 , 0 ) ;
if ( V_224 )
F_108 ( V_237 , V_236 ) ;
}
F_105 () ;
} else {
F_108 ( V_231 , V_230 ) ;
}
return 0 ;
}
