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
struct V_98 * V_98 V_39 ,
struct V_99 * V_19 ,
int T_6 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
struct V_16 * V_100 , * V_30 ;
if ( V_48 ) {
printf ( L_16 , V_19 ) ;
printf ( L_17 ,
V_97 -> V_101 ,
V_97 -> V_42 ,
V_97 -> V_41 ) ;
}
V_100 = F_17 ( V_97 -> V_101 , L_18 ) ;
V_30 = F_17 ( V_97 -> V_41 , V_97 -> V_42 ) ;
F_14 ( V_100 , V_18 , V_30 ) ;
}
static void
F_43 ( struct V_102 * V_103 ,
struct V_98 * V_98 V_39 ,
struct V_99 * V_19 ,
int T_6 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_16 * V_104 , V_39 * V_105 ;
T_1 V_106 ;
T_7 V_10 ;
if ( V_48 )
printf ( L_19 , V_19 ) ;
if ( T_6 >= V_107 || T_6 < 0 )
return;
V_106 = V_108 [ T_6 ] ;
if ( V_106 )
V_10 = V_18 - V_106 ;
else
V_10 = 0 ;
if ( V_10 < 0 )
F_27 ( L_20 V_13 L_21 , V_10 ) ;
if ( V_48 ) {
printf ( L_22 V_13 L_23 ,
V_103 -> V_109 , V_103 -> V_110 ,
V_103 -> V_111 , V_103 -> V_112 ,
V_10 ) ;
}
V_104 = F_17 ( V_103 -> V_110 , V_103 -> V_109 ) ;
V_105 = F_17 ( V_103 -> V_112 , V_103 -> V_111 ) ;
V_108 [ T_6 ] = V_18 ;
F_13 ( V_104 , V_18 , V_10 ) ;
F_16 ( V_104 , V_18 , V_103 -> V_113 ) ;
}
static void
F_44 ( struct V_114 * V_115 ,
struct V_99 * V_19 ,
int T_6 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
if ( V_48 ) {
printf ( L_24 , V_19 ) ;
printf ( L_25 , V_115 -> V_116 , V_115 -> V_117 ) ;
printf ( L_26 , V_115 -> V_118 , V_115 -> V_119 ) ;
}
F_17 ( V_115 -> V_117 , V_115 -> V_116 ) ;
F_17 ( V_115 -> V_119 , V_115 -> V_118 ) ;
}
static int
F_45 ( struct V_120 * V_121 , struct V_122 * V_123 , struct V_122 * V_124 )
{
struct V_125 * V_126 ;
int V_53 = 0 ;
F_11 ( F_46 ( V_121 ) ) ;
F_47 (sort, list, list) {
V_53 = V_126 -> V_127 ( V_123 , V_124 ) ;
if ( V_53 )
return V_53 ;
}
return V_53 ;
}
static struct V_122 *
F_48 ( struct V_128 * V_129 , struct V_84 * V_84 ,
struct V_120 * V_130 )
{
struct V_131 * V_132 = V_129 -> V_131 ;
struct V_122 V_133 = { . V_84 = V_84 } ;
while ( V_132 ) {
struct V_122 * V_24 ;
int V_127 ;
V_24 = F_49 ( V_132 , struct V_122 , V_132 ) ;
V_127 = F_45 ( V_130 , & V_133 , V_24 ) ;
if ( V_127 > 0 )
V_132 = V_132 -> V_134 ;
else if ( V_127 < 0 )
V_132 = V_132 -> V_135 ;
else {
F_11 ( V_84 != V_24 -> V_84 ) ;
return V_24 ;
}
}
return NULL ;
}
static void
F_50 ( struct V_128 * V_129 , struct V_122 * V_136 ,
struct V_120 * V_130 )
{
struct V_131 * * V_137 = & ( V_129 -> V_131 ) , * V_138 = NULL ;
while ( * V_137 ) {
struct V_122 * V_139 ;
int V_127 ;
V_139 = F_49 ( * V_137 , struct V_122 , V_132 ) ;
V_138 = * V_137 ;
V_127 = F_45 ( V_130 , V_136 , V_139 ) ;
if ( V_127 > 0 )
V_137 = & ( ( * V_137 ) -> V_134 ) ;
else
V_137 = & ( ( * V_137 ) -> V_135 ) ;
}
F_51 ( & V_136 -> V_132 , V_138 , V_137 ) ;
F_52 ( & V_136 -> V_132 , V_129 ) ;
}
static void F_53 ( struct V_84 * V_84 )
{
struct V_122 * V_24 = F_10 ( sizeof( * V_24 ) ) ;
if ( ! V_24 )
F_27 ( L_27 ) ;
V_24 -> V_84 = V_84 ;
F_54 ( & V_24 -> V_140 ) ;
F_50 ( & V_141 , V_24 , & V_142 ) ;
}
static void
F_55 ( struct V_114 * V_115 V_39 ,
struct V_99 * V_19 V_39 ,
int T_6 V_39 ,
T_1 V_18 V_39 ,
struct V_84 * V_84 V_39 )
{
}
V_39
static char F_56 ( struct V_102 * V_103 )
{
const char * V_143 = V_144 ;
return V_143 [ V_103 -> V_113 ] ;
}
static void
F_57 ( struct V_122 * V_24 ,
char V_145 ,
T_1 V_18 )
{
struct V_146 * V_52 = F_10 ( sizeof( * V_52 ) ) ;
if ( ! V_52 )
F_27 ( L_28 ) ;
V_52 -> V_147 = V_18 ;
if ( V_145 == 'R' ) {
V_52 -> V_148 = V_149 ;
V_52 -> V_150 = V_52 -> V_147 ;
}
F_58 ( & V_52 -> V_121 , & V_24 -> V_140 ) ;
}
static void
F_59 ( struct V_122 * V_24 , T_1 V_10 , T_1 V_18 V_39 )
{
struct V_146 * V_52 ;
F_11 ( F_46 ( & V_24 -> V_140 ) ) ;
V_52 = F_60 ( V_24 -> V_140 . V_104 , struct V_146 , V_121 ) ;
V_52 -> V_70 += V_10 ;
V_24 -> V_151 += V_10 ;
}
static void
F_61 ( struct V_122 * V_24 , T_1 V_18 )
{
struct V_146 * V_52 ;
T_1 V_10 ;
if ( F_46 ( & V_24 -> V_140 ) )
return;
V_52 = F_60 ( V_24 -> V_140 . V_104 , struct V_146 , V_121 ) ;
if ( V_52 -> V_148 != V_149 )
return;
if ( V_18 < V_52 -> V_150 ) {
V_52 -> V_148 = V_152 ;
return;
}
V_52 -> V_148 = V_153 ;
V_52 -> V_154 = V_18 ;
V_10 = V_52 -> V_154 - V_52 -> V_150 ;
V_24 -> V_155 += V_10 ;
if ( V_10 > V_24 -> V_156 ) {
V_24 -> V_156 = V_10 ;
V_24 -> V_157 = V_18 ;
}
V_24 -> V_158 ++ ;
}
static void
F_62 ( struct V_102 * V_103 ,
struct V_98 * V_98 ,
struct V_99 * V_19 V_39 ,
int T_6 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_122 * V_159 , * V_160 ;
struct V_84 * V_161 , * V_162 ;
T_1 V_106 ;
T_7 V_10 ;
F_11 ( T_6 >= V_107 || T_6 < 0 ) ;
V_106 = V_108 [ T_6 ] ;
V_108 [ T_6 ] = V_18 ;
if ( V_106 )
V_10 = V_18 - V_106 ;
else
V_10 = 0 ;
if ( V_10 < 0 )
F_27 ( L_20 V_13 L_21 , V_10 ) ;
V_161 = F_63 ( V_98 , V_103 -> V_110 ) ;
V_162 = F_63 ( V_98 , V_103 -> V_112 ) ;
V_159 = F_48 ( & V_141 , V_161 , & V_142 ) ;
if ( ! V_159 ) {
F_53 ( V_161 ) ;
V_159 = F_48 ( & V_141 , V_161 , & V_142 ) ;
if ( ! V_159 )
F_27 ( L_29 ) ;
}
F_57 ( V_159 , F_56 ( V_103 ) , V_18 ) ;
V_160 = F_48 ( & V_141 , V_162 , & V_142 ) ;
if ( ! V_160 ) {
F_53 ( V_162 ) ;
V_160 = F_48 ( & V_141 , V_162 , & V_142 ) ;
if ( ! V_160 )
F_27 ( L_30 ) ;
F_57 ( V_160 , 'R' , V_18 ) ;
}
F_61 ( V_160 , V_18 ) ;
}
static void
F_64 ( struct V_163 * V_164 ,
struct V_98 * V_98 ,
struct V_99 * V_19 V_39 ,
int T_6 ,
T_1 V_18 ,
struct V_84 * T_8 V_39 )
{
struct V_84 * V_84 = F_63 ( V_98 , V_164 -> V_41 ) ;
struct V_122 * V_24 = F_48 ( & V_141 , V_84 , & V_142 ) ;
F_11 ( T_6 >= V_107 || T_6 < 0 ) ;
if ( ! V_24 ) {
F_53 ( V_84 ) ;
V_24 = F_48 ( & V_141 , V_84 , & V_142 ) ;
if ( ! V_24 )
F_27 ( L_30 ) ;
F_57 ( V_24 , 'R' , V_18 ) ;
}
F_59 ( V_24 , V_164 -> V_70 , V_18 ) ;
}
static void
F_65 ( struct V_96 * V_97 ,
struct V_98 * V_98 ,
struct V_99 * T_9 V_39 ,
int T_6 V_39 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_122 * V_24 ;
struct V_146 * V_52 ;
struct V_84 * V_30 ;
if ( ! V_97 -> V_165 )
return;
V_30 = F_63 ( V_98 , V_97 -> V_41 ) ;
V_24 = F_48 ( & V_141 , V_30 , & V_142 ) ;
if ( ! V_24 ) {
F_53 ( V_30 ) ;
V_24 = F_48 ( & V_141 , V_30 , & V_142 ) ;
if ( ! V_24 )
F_27 ( L_31 ) ;
F_57 ( V_24 , 'S' , V_18 ) ;
}
F_11 ( F_46 ( & V_24 -> V_140 ) ) ;
V_52 = F_60 ( V_24 -> V_140 . V_104 , struct V_146 , V_121 ) ;
if ( V_166 == - 1 && V_52 -> V_148 != V_167 )
V_168 ++ ;
V_169 ++ ;
if ( V_52 -> V_147 > V_18 ) {
V_170 ++ ;
return;
}
V_52 -> V_148 = V_149 ;
V_52 -> V_150 = V_18 ;
}
static void
F_66 ( struct V_171 * V_172 ,
struct V_98 * V_98 ,
struct V_99 * T_9 V_39 ,
int T_6 V_39 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_122 * V_24 ;
struct V_146 * V_52 ;
struct V_84 * V_173 ;
if ( V_166 == - 1 )
return;
V_173 = F_63 ( V_98 , V_172 -> V_41 ) ;
V_24 = F_48 ( & V_141 , V_173 , & V_142 ) ;
if ( ! V_24 ) {
F_53 ( V_173 ) ;
F_17 ( V_173 -> V_41 , V_173 -> V_42 ) ;
V_24 = F_48 ( & V_141 , V_173 , & V_142 ) ;
if ( ! V_24 )
F_27 ( L_32 ) ;
F_57 ( V_24 , 'R' , V_18 ) ;
}
F_11 ( F_46 ( & V_24 -> V_140 ) ) ;
V_52 = F_60 ( V_24 -> V_140 . V_104 , struct V_146 , V_121 ) ;
V_52 -> V_154 = V_52 -> V_147 = V_52 -> V_150 = V_18 ;
V_169 ++ ;
if ( V_52 -> V_147 > V_18 )
V_170 ++ ;
}
static void F_67 ( struct V_122 * V_140 )
{
int V_12 ;
int V_53 ;
T_1 V_174 ;
if ( ! V_140 -> V_158 )
return;
if ( ! strcmp ( V_140 -> V_84 -> V_42 , L_33 ) )
return;
V_175 += V_140 -> V_151 ;
V_176 += V_140 -> V_158 ;
V_53 = printf ( L_34 , V_140 -> V_84 -> V_42 , V_140 -> V_84 -> V_41 ) ;
for ( V_12 = 0 ; V_12 < 24 - V_53 ; V_12 ++ )
printf ( L_35 ) ;
V_174 = V_140 -> V_155 / V_140 -> V_158 ;
printf ( L_36 V_13 L_37 ,
( double ) V_140 -> V_151 / 1e6 ,
V_140 -> V_158 , ( double ) V_174 / 1e6 ,
( double ) V_140 -> V_156 / 1e6 ,
( double ) V_140 -> V_157 / 1e9 ) ;
}
static int F_68 ( struct V_122 * V_123 , struct V_122 * V_124 )
{
if ( V_123 -> V_84 -> V_41 < V_124 -> V_84 -> V_41 )
return - 1 ;
if ( V_123 -> V_84 -> V_41 > V_124 -> V_84 -> V_41 )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_122 * V_123 , struct V_122 * V_124 )
{
T_1 V_177 , V_178 ;
if ( ! V_123 -> V_158 )
return - 1 ;
if ( ! V_124 -> V_158 )
return 1 ;
V_177 = V_123 -> V_155 / V_123 -> V_158 ;
V_178 = V_124 -> V_155 / V_124 -> V_158 ;
if ( V_177 < V_178 )
return - 1 ;
if ( V_177 > V_178 )
return 1 ;
return 0 ;
}
static int F_70 ( struct V_122 * V_123 , struct V_122 * V_124 )
{
if ( V_123 -> V_156 < V_124 -> V_156 )
return - 1 ;
if ( V_123 -> V_156 > V_124 -> V_156 )
return 1 ;
return 0 ;
}
static int F_71 ( struct V_122 * V_123 , struct V_122 * V_124 )
{
if ( V_123 -> V_158 < V_124 -> V_158 )
return - 1 ;
if ( V_123 -> V_158 > V_124 -> V_158 )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_122 * V_123 , struct V_122 * V_124 )
{
if ( V_123 -> V_151 < V_124 -> V_151 )
return - 1 ;
if ( V_123 -> V_151 > V_124 -> V_151 )
return 1 ;
return 0 ;
}
static int F_73 ( const char * V_179 , struct V_120 * V_121 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_180 ; V_12 ++ ) {
if ( ! strcmp ( V_181 [ V_12 ] -> V_182 , V_179 ) ) {
F_58 ( & V_181 [ V_12 ] -> V_121 , V_121 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_74 ( void )
{
struct V_131 * V_132 ;
for (; ; ) {
struct V_122 * V_136 ;
V_132 = F_75 ( & V_141 ) ;
if ( ! V_132 )
break;
F_76 ( V_132 , & V_141 ) ;
V_136 = F_77 ( V_132 , struct V_122 , V_132 ) ;
F_50 ( & V_183 , V_136 , & V_130 ) ;
}
}
static void
F_78 ( struct V_184 * T_10 V_39 ,
struct V_99 * V_19 ,
struct V_185 * V_186 ,
struct V_98 * V_98 ,
struct V_84 * V_84 )
{
void * V_136 = V_186 -> V_187 ;
struct V_96 V_97 ;
F_79 ( V_97 , V_19 , V_136 ) ;
F_80 ( V_97 , V_42 , V_19 , V_136 ) ;
F_81 ( V_97 , V_41 , V_19 , V_136 ) ;
F_81 ( V_97 , V_188 , V_19 , V_136 ) ;
F_81 ( V_97 , V_165 , V_19 , V_136 ) ;
F_81 ( V_97 , T_6 , V_19 , V_136 ) ;
if ( V_189 -> V_97 )
V_189 -> V_97 ( & V_97 , V_98 , V_19 ,
V_186 -> T_6 , V_186 -> time , V_84 ) ;
}
static void
F_82 ( struct V_102 * V_103 ,
struct V_98 * V_98 ,
struct V_99 * V_19 V_39 ,
int V_190 ,
T_1 V_18 ,
struct V_84 * V_84 V_39 )
{
struct V_84 * V_161 V_39 , * V_162 ;
int V_191 ;
T_1 V_106 ;
T_7 V_10 ;
int T_6 ;
F_11 ( V_190 >= V_107 || V_190 < 0 ) ;
if ( V_190 > V_192 )
V_192 = V_190 ;
V_106 = V_108 [ V_190 ] ;
V_108 [ V_190 ] = V_18 ;
if ( V_106 )
V_10 = V_18 - V_106 ;
else
V_10 = 0 ;
if ( V_10 < 0 )
F_27 ( L_20 V_13 L_21 , V_10 ) ;
V_161 = F_63 ( V_98 , V_103 -> V_110 ) ;
V_162 = F_63 ( V_98 , V_103 -> V_112 ) ;
V_193 [ V_190 ] = V_162 ;
printf ( L_38 ) ;
V_191 = 0 ;
if ( ! V_162 -> V_194 [ 0 ] ) {
V_162 -> V_194 [ 0 ] = V_195 ;
V_162 -> V_194 [ 1 ] = V_196 ;
if ( V_195 < 'Z' ) {
V_195 ++ ;
} else {
V_195 = 'A' ;
if ( V_196 < '9' ) {
V_196 ++ ;
} else {
V_196 = '0' ;
}
}
V_191 = 1 ;
}
for ( T_6 = 0 ; T_6 <= V_192 ; T_6 ++ ) {
if ( T_6 != V_190 )
printf ( L_35 ) ;
else
printf ( L_39 ) ;
if ( V_193 [ T_6 ] ) {
if ( V_193 [ T_6 ] -> V_41 )
printf ( L_40 , V_193 [ T_6 ] -> V_194 ) ;
else
printf ( L_41 ) ;
} else
printf ( L_42 ) ;
}
printf ( L_43 , ( double ) V_18 / 1e9 ) ;
if ( V_191 ) {
printf ( L_44 ,
V_162 -> V_194 , V_162 -> V_42 , V_162 -> V_41 ) ;
} else {
printf ( L_12 ) ;
}
}
static void
F_83 ( struct V_184 * T_10 V_39 ,
struct V_99 * V_19 ,
struct V_185 * V_186 ,
struct V_98 * V_98 ,
struct V_84 * V_84 )
{
int V_190 = V_186 -> T_6 ;
void * V_136 = V_186 -> V_187 ;
struct V_102 V_103 ;
F_79 ( V_103 , V_19 , V_136 ) ;
F_80 ( V_103 , V_109 , V_19 , V_136 ) ;
F_81 ( V_103 , V_110 , V_19 , V_136 ) ;
F_81 ( V_103 , V_197 , V_19 , V_136 ) ;
F_81 ( V_103 , V_113 , V_19 , V_136 ) ;
F_80 ( V_103 , V_111 , V_19 , V_136 ) ;
F_81 ( V_103 , V_112 , V_19 , V_136 ) ;
F_81 ( V_103 , V_198 , V_19 , V_136 ) ;
if ( V_199 [ V_190 ] != ( V_200 ) - 1 ) {
if ( V_199 [ V_190 ] != V_103 . V_110 )
V_201 ++ ;
}
if ( V_189 -> V_103 )
V_189 -> V_103 ( & V_103 , V_98 , V_19 ,
V_190 , V_186 -> time , V_84 ) ;
V_199 [ V_190 ] = V_103 . V_112 ;
}
static void
F_84 ( struct V_184 * T_10 V_39 ,
struct V_99 * V_19 ,
struct V_185 * V_186 ,
struct V_98 * V_98 ,
struct V_84 * V_84 )
{
void * V_136 = V_186 -> V_187 ;
struct V_163 V_164 ;
F_80 ( V_164 , V_42 , V_19 , V_136 ) ;
F_81 ( V_164 , V_41 , V_19 , V_136 ) ;
F_81 ( V_164 , V_70 , V_19 , V_136 ) ;
F_81 ( V_164 , V_202 , V_19 , V_136 ) ;
if ( V_189 -> V_164 )
V_189 -> V_164 ( & V_164 , V_98 , V_19 ,
V_186 -> T_6 , V_186 -> time , V_84 ) ;
}
static void
F_85 ( struct V_184 * T_10 V_39 ,
struct V_99 * V_19 ,
struct V_185 * V_186 ,
struct V_98 * V_98 V_39 ,
struct V_84 * V_84 )
{
void * V_136 = V_186 -> V_187 ;
struct V_114 V_115 ;
F_79 ( V_115 , V_19 , V_136 ) ;
F_80 ( V_115 , V_116 , V_19 , V_136 ) ;
F_81 ( V_115 , V_117 , V_19 , V_136 ) ;
F_80 ( V_115 , V_118 , V_19 , V_136 ) ;
F_81 ( V_115 , V_119 , V_19 , V_136 ) ;
if ( V_189 -> V_115 )
V_189 -> V_115 ( & V_115 , V_19 ,
V_186 -> T_6 , V_186 -> time , V_84 ) ;
}
static void
F_86 ( struct V_184 * T_10 V_39 ,
struct V_99 * V_19 ,
struct V_185 * V_186 V_39 ,
struct V_98 * V_98 V_39 ,
struct V_84 * V_84 V_39 )
{
if ( V_48 )
printf ( L_45 , V_19 ) ;
}
static void
F_87 ( struct V_184 * T_10 V_39 ,
struct V_99 * V_19 ,
struct V_185 * V_186 ,
struct V_98 * V_98 ,
struct V_84 * V_84 )
{
void * V_136 = V_186 -> V_187 ;
struct V_171 V_172 ;
F_79 ( V_172 , V_19 , V_136 ) ;
F_80 ( V_172 , V_42 , V_19 , V_136 ) ;
F_81 ( V_172 , V_41 , V_19 , V_136 ) ;
F_81 ( V_172 , V_188 , V_19 , V_136 ) ;
F_81 ( V_172 , T_6 , V_19 , V_136 ) ;
if ( V_189 -> V_172 )
V_189 -> V_172 ( & V_172 , V_98 ,
V_19 , V_186 -> T_6 ,
V_186 -> time , V_84 ) ;
}
static int F_88 ( struct V_184 * T_10 ,
union V_203 * V_19 V_39 ,
struct V_185 * V_186 ,
struct V_204 * V_205 ,
struct V_98 * V_98 )
{
struct V_84 * V_84 = F_63 ( V_98 , V_186 -> V_41 ) ;
if ( V_84 == NULL ) {
F_89 ( L_46 ,
V_205 -> V_182 ) ;
return - 1 ;
}
V_205 -> V_206 . V_207 . V_208 += V_186 -> V_209 ;
F_90 ( & V_205 -> V_206 , V_210 ) ;
if ( V_205 -> V_211 . V_212 != NULL ) {
T_11 V_213 = V_205 -> V_211 . V_212 ;
if ( V_205 -> V_211 . V_136 == NULL )
V_205 -> V_211 . V_136 = F_91 ( V_205 -> V_64 . V_67 ) ;
V_213 ( T_10 , V_205 -> V_211 . V_136 , V_186 , V_98 , V_84 ) ;
}
return 0 ;
}
static void F_92 ( bool V_214 , struct V_215 * * V_216 )
{
int V_58 = - V_217 ;
const struct V_218 V_219 [] = {
{ L_47 , F_83 , } ,
{ L_48 , F_84 , } ,
{ L_49 , F_78 , } ,
{ L_50 , F_78 , } ,
{ L_51 , F_85 , } ,
{ L_52 , F_86 , } ,
{ L_53 , F_87 , } ,
} ;
struct V_215 * V_220 = F_93 ( V_221 , V_222 ,
0 , false , & V_223 ) ;
if ( V_220 == NULL )
F_27 ( L_54 ) ;
V_58 = F_94 ( V_220 -> V_224 , V_219 ) ;
assert ( V_58 == 0 ) ;
if ( F_95 ( V_220 , L_55 ) ) {
V_58 = F_96 ( V_220 , & V_223 ) ;
if ( V_58 )
F_27 ( L_56 , V_58 ) ;
V_21 = V_220 -> V_206 . V_207 . V_21 [ 0 ] ;
V_225 = V_220 -> V_206 . V_207 . V_226 ;
V_227 = V_220 -> V_206 . V_207 . V_21 [ V_228 ] ;
}
if ( V_214 )
F_97 ( V_220 ) ;
if ( V_216 )
* V_216 = V_220 ;
}
static void F_98 ( void )
{
if ( V_170 && V_169 ) {
printf ( L_57 ,
( double ) V_170 / ( double ) V_169 * 100.0 ,
V_170 , V_169 ) ;
}
if ( V_225 && V_21 ) {
printf ( L_58 ,
( double ) V_225 / ( double ) V_21 * 100.0 ,
V_225 , V_21 , V_227 ) ;
}
if ( V_168 && V_169 ) {
printf ( L_59 ,
( double ) V_168 / ( double ) V_169 * 100.0 ,
V_168 , V_169 ) ;
if ( V_225 )
printf ( L_60 ) ;
printf ( L_12 ) ;
}
if ( V_201 && V_169 ) {
printf ( L_61 ,
( double ) V_201 / ( double ) V_169 * 100.0 ,
V_201 , V_169 ) ;
if ( V_225 )
printf ( L_60 ) ;
printf ( L_12 ) ;
}
}
static void F_99 ( void )
{
struct V_131 * V_105 ;
struct V_215 * V_220 ;
F_100 () ;
F_92 ( false , & V_220 ) ;
F_74 () ;
printf ( L_62 ) ;
printf ( L_63 ) ;
printf ( L_64 ) ;
V_105 = F_75 ( & V_183 ) ;
while ( V_105 ) {
struct V_122 * V_140 ;
V_140 = F_77 ( V_105 , struct V_122 , V_132 ) ;
F_67 ( V_140 ) ;
V_105 = F_101 ( V_105 ) ;
}
printf ( L_65 ) ;
printf ( L_66 V_13 L_67 ,
( double ) V_175 / 1e6 , V_176 ) ;
printf ( L_68 ) ;
F_98 () ;
printf ( L_12 ) ;
F_97 ( V_220 ) ;
}
static void F_102 ( void )
{
V_192 = F_103 ( V_229 ) ;
F_100 () ;
F_92 ( true , NULL ) ;
F_98 () ;
}
static void F_104 ( void )
{
unsigned long V_12 ;
F_6 () ;
F_8 () ;
F_41 () ;
F_92 ( true , NULL ) ;
printf ( L_69 , V_29 ) ;
printf ( L_70 , V_40 ) ;
printf ( L_71 , V_38 ) ;
if ( V_34 )
printf ( L_72 , V_34 ) ;
if ( V_36 )
printf ( L_73 , V_36 ) ;
if ( V_28 )
printf ( L_74 ,
V_28 ) ;
F_18 () ;
F_19 () ;
F_34 () ;
printf ( L_75 ) ;
for ( V_12 = 0 ; V_12 < V_230 ; V_12 ++ )
F_40 () ;
}
static void F_105 ( void )
{
char * V_231 , * V_179 , * V_143 = F_106 ( V_232 ) ;
for ( V_179 = strtok_r ( V_143 , L_76 , & V_231 ) ;
V_179 ; V_179 = strtok_r ( NULL , L_76 , & V_231 ) ) {
if ( F_73 ( V_179 , & V_130 ) < 0 ) {
error ( L_77 , V_179 ) ;
F_107 ( V_233 , V_234 ) ;
}
}
free ( V_143 ) ;
F_73 ( L_78 , & V_142 ) ;
}
static int F_108 ( int V_235 , const char * * V_236 )
{
unsigned int V_237 , V_12 , V_51 ;
const char * * V_238 ;
V_237 = F_109 ( V_239 ) + V_235 - 1 ;
V_238 = calloc ( V_237 + 1 , sizeof( char * ) ) ;
if ( V_238 == NULL )
return - V_240 ;
for ( V_12 = 0 ; V_12 < F_109 ( V_239 ) ; V_12 ++ )
V_238 [ V_12 ] = F_106 ( V_239 [ V_12 ] ) ;
for ( V_51 = 1 ; V_51 < ( unsigned int ) V_235 ; V_51 ++ , V_12 ++ )
V_238 [ V_12 ] = V_236 [ V_51 ] ;
F_11 ( V_12 != V_237 ) ;
return F_110 ( V_12 , V_238 , NULL ) ;
}
int F_111 ( int V_235 , const char * * V_236 , const char * T_12 V_39 )
{
V_235 = F_112 ( V_235 , V_236 , V_241 , V_242 ,
V_243 ) ;
if ( ! V_235 )
F_107 ( V_242 , V_241 ) ;
if ( ! strcmp ( V_236 [ 0 ] , L_79 ) )
return F_113 ( V_235 , V_236 , T_12 ) ;
F_114 () ;
if ( ! strncmp ( V_236 [ 0 ] , L_80 , 3 ) ) {
return F_108 ( V_235 , V_236 ) ;
} else if ( ! strncmp ( V_236 [ 0 ] , L_81 , 3 ) ) {
V_189 = & V_244 ;
if ( V_235 > 1 ) {
V_235 = F_112 ( V_235 , V_236 , V_234 , V_233 , 0 ) ;
if ( V_235 )
F_107 ( V_233 , V_234 ) ;
}
F_105 () ;
F_99 () ;
} else if ( ! strcmp ( V_236 [ 0 ] , L_82 ) ) {
V_189 = & V_245 ;
F_105 () ;
F_102 () ;
} else if ( ! strncmp ( V_236 [ 0 ] , L_83 , 3 ) ) {
V_189 = & V_246 ;
if ( V_235 ) {
V_235 = F_112 ( V_235 , V_236 , V_247 , V_248 , 0 ) ;
if ( V_235 )
F_107 ( V_248 , V_247 ) ;
}
F_104 () ;
} else {
F_107 ( V_242 , V_241 ) ;
}
return 0 ;
}
