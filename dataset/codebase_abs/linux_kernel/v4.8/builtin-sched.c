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
static int V_45 ;
if ( V_7 -> V_46 == NULL ) {
if ( F_18 ( L_4 , & V_45 ) < 0 )
V_45 = V_47 ;
F_11 ( ( V_7 -> V_46 = calloc ( V_45 , sizeof( struct V_18 * ) ) ) == NULL ) ;
}
if ( V_43 >= ( unsigned long ) V_45 ) {
F_11 ( ( V_7 -> V_46 = realloc ( V_7 -> V_46 , ( V_43 + 1 ) *
sizeof( struct V_18 * ) ) ) == NULL ) ;
while ( V_43 >= ( unsigned long ) V_45 )
V_7 -> V_46 [ V_45 ++ ] = NULL ;
}
V_19 = V_7 -> V_46 [ V_43 ] ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( sizeof( * V_19 ) ) ;
V_19 -> V_43 = V_43 ;
V_19 -> V_25 = V_7 -> V_48 ;
strcpy ( V_19 -> V_44 , V_44 ) ;
F_16 ( V_7 , V_19 , 0 , 0 ) ;
V_7 -> V_46 [ V_43 ] = V_19 ;
V_7 -> V_48 ++ ;
V_7 -> V_49 = realloc ( V_7 -> V_49 , V_7 -> V_48 * sizeof( struct V_18 * ) ) ;
F_11 ( ! V_7 -> V_49 ) ;
V_7 -> V_49 [ V_19 -> V_25 ] = V_19 ;
if ( V_50 )
printf ( L_5 , V_7 -> V_48 , V_43 , V_44 ) ;
return V_19 ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_18 * V_19 ;
unsigned long V_14 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_48 ; V_14 ++ ) {
V_19 = V_7 -> V_49 [ V_14 ] ;
printf ( L_6 ,
V_19 -> V_25 , V_19 -> V_44 , V_19 -> V_43 , V_19 -> V_23 ) ;
}
}
static void F_20 ( struct V_6 * V_7 )
{
struct V_18 * V_51 , * V_52 ;
unsigned long V_14 , V_53 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_48 ; V_14 ++ ) {
V_51 = V_7 -> V_49 [ V_14 ] ;
V_53 = V_14 + 1 ;
if ( V_53 == V_7 -> V_48 )
V_53 = 0 ;
V_52 = V_7 -> V_49 [ V_53 ] ;
F_14 ( V_7 , V_51 , 0 , V_52 ) ;
}
}
static void F_21 ( struct V_6 * V_7 ,
struct V_17 * V_54 )
{
int V_55 = 0 ;
switch ( V_54 -> type ) {
case V_29 :
F_3 ( V_7 , V_54 -> V_27 ) ;
break;
case V_35 :
if ( V_54 -> V_37 )
V_55 = F_22 ( V_54 -> V_37 ) ;
F_11 ( V_55 ) ;
break;
case V_34 :
if ( V_54 -> V_37 )
V_55 = F_23 ( V_54 -> V_37 ) ;
F_11 ( V_55 ) ;
break;
case V_56 :
break;
default:
F_11 ( 1 ) ;
}
}
static T_1 F_24 ( void )
{
struct V_57 V_58 ;
T_1 V_59 ;
int V_60 ;
V_60 = F_25 ( V_61 , & V_58 ) ;
F_11 ( V_60 ) ;
V_59 = V_58 . V_62 . V_4 * 1e9 + V_58 . V_62 . V_63 * 1e3 ;
V_59 += V_58 . V_64 . V_4 * 1e9 + V_58 . V_64 . V_63 * 1e3 ;
return V_59 ;
}
static int F_26 ( struct V_6 * V_7 , unsigned long V_65 )
{
struct V_66 V_67 ;
char V_68 [ V_69 ] , V_70 [ V_69 ] ;
int V_71 ;
struct V_72 V_73 ;
bool V_74 = false ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
V_67 . type = V_75 ;
V_67 . V_76 = V_77 ;
V_78:
V_71 = F_27 ( & V_67 , 0 , - 1 , - 1 ,
F_28 () ) ;
if ( V_71 < 0 ) {
if ( V_79 == V_80 ) {
if ( V_7 -> V_81 ) {
F_11 ( F_29 ( V_82 , & V_73 ) == - 1 ) ;
V_73 . V_83 += V_7 -> V_48 - V_65 ;
if ( V_73 . V_83 > V_73 . V_84 ) {
V_73 . V_84 = V_73 . V_83 ;
V_74 = true ;
}
if ( F_30 ( V_82 , & V_73 ) == - 1 ) {
if ( V_74 && V_79 == V_85 )
strcpy ( V_70 , L_7 ) ;
} else
goto V_78;
} else
strcpy ( V_70 , L_8 ) ;
}
F_31 ( L_9
L_10 , V_71 ,
F_32 ( V_79 , V_68 , sizeof( V_68 ) ) , V_70 ) ;
exit ( V_86 ) ;
}
return V_71 ;
}
static T_1 F_33 ( int V_71 )
{
T_1 V_87 ;
int V_55 ;
V_55 = F_34 ( V_71 , & V_87 , sizeof( V_87 ) ) ;
F_11 ( V_55 != sizeof( V_87 ) ) ;
return V_87 ;
}
static void * F_35 ( void * V_88 )
{
struct V_89 * V_90 = V_88 ;
struct V_18 * V_91 = V_90 -> V_19 ;
struct V_6 * V_7 = V_90 -> V_7 ;
T_1 V_92 , V_93 ;
unsigned long V_14 , V_55 ;
char V_94 [ 22 ] ;
int V_71 = V_90 -> V_71 ;
F_36 ( & V_90 ) ;
sprintf ( V_94 , L_11 , V_91 -> V_44 ) ;
F_37 ( V_95 , V_94 ) ;
if ( V_71 < 0 )
return NULL ;
V_96:
V_55 = F_23 ( & V_91 -> V_97 ) ;
F_11 ( V_55 ) ;
V_55 = F_38 ( & V_7 -> V_98 ) ;
F_11 ( V_55 ) ;
V_55 = F_39 ( & V_7 -> V_98 ) ;
F_11 ( V_55 ) ;
V_92 = F_33 ( V_71 ) ;
for ( V_14 = 0 ; V_14 < V_91 -> V_23 ; V_14 ++ ) {
V_91 -> V_28 = V_14 ;
F_21 ( V_7 , V_91 -> V_26 [ V_14 ] ) ;
}
V_93 = F_33 ( V_71 ) ;
V_91 -> V_99 = V_93 - V_92 ;
V_55 = F_23 ( & V_91 -> V_100 ) ;
F_11 ( V_55 ) ;
V_55 = F_38 ( & V_7 -> V_101 ) ;
F_11 ( V_55 ) ;
V_55 = F_39 ( & V_7 -> V_101 ) ;
F_11 ( V_55 ) ;
goto V_96;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_18 * V_19 ;
T_4 V_67 ;
unsigned long V_14 ;
int V_60 ;
V_60 = F_41 ( & V_67 ) ;
F_11 ( V_60 ) ;
V_60 = F_42 ( & V_67 ,
( T_2 ) F_43 ( 16 * 1024 , V_102 ) ) ;
F_11 ( V_60 ) ;
V_60 = F_38 ( & V_7 -> V_98 ) ;
F_11 ( V_60 ) ;
V_60 = F_38 ( & V_7 -> V_101 ) ;
F_11 ( V_60 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_48 ; V_14 ++ ) {
struct V_89 * V_90 = malloc ( sizeof( * V_90 ) ) ;
F_11 ( V_90 == NULL ) ;
V_90 -> V_19 = V_19 = V_7 -> V_49 [ V_14 ] ;
V_90 -> V_7 = V_7 ;
V_90 -> V_71 = F_26 ( V_7 , V_14 ) ;
F_15 ( & V_19 -> V_103 , 0 , 0 ) ;
F_15 ( & V_19 -> V_97 , 0 , 0 ) ;
F_15 ( & V_19 -> V_100 , 0 , 0 ) ;
V_19 -> V_28 = 0 ;
V_60 = F_44 ( & V_19 -> V_104 , & V_67 , F_35 , V_90 ) ;
F_11 ( V_60 ) ;
}
}
static void F_45 ( struct V_6 * V_7 )
{
T_1 V_92 , V_93 ;
struct V_18 * V_19 ;
unsigned long V_14 , V_55 ;
V_7 -> V_105 = F_1 () ;
V_7 -> V_99 = 0 ;
F_39 ( & V_7 -> V_101 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_48 ; V_14 ++ ) {
V_19 = V_7 -> V_49 [ V_14 ] ;
V_55 = F_22 ( & V_19 -> V_97 ) ;
F_11 ( V_55 ) ;
F_15 ( & V_19 -> V_97 , 0 , 0 ) ;
}
V_55 = F_38 ( & V_7 -> V_101 ) ;
F_11 ( V_55 ) ;
V_92 = F_24 () ;
F_39 ( & V_7 -> V_98 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_48 ; V_14 ++ ) {
V_19 = V_7 -> V_49 [ V_14 ] ;
V_55 = F_22 ( & V_19 -> V_100 ) ;
F_11 ( V_55 ) ;
F_15 ( & V_19 -> V_100 , 0 , 0 ) ;
V_7 -> V_99 += V_19 -> V_99 ;
V_19 -> V_99 = 0 ;
}
V_93 = F_24 () ;
if ( ! V_7 -> V_106 )
V_7 -> V_106 = V_7 -> V_99 ;
V_7 -> V_106 = ( V_7 -> V_106 * ( V_7 -> V_107 - 1 ) + V_7 -> V_99 ) / V_7 -> V_107 ;
V_7 -> V_108 = V_93 - V_92 ;
if ( ! V_7 -> V_109 )
V_7 -> V_109 = V_7 -> V_108 ;
V_7 -> V_109 = ( V_7 -> V_109 * ( V_7 -> V_107 - 1 ) +
V_7 -> V_108 ) / V_7 -> V_107 ;
V_55 = F_38 ( & V_7 -> V_98 ) ;
F_11 ( V_55 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_48 ; V_14 ++ ) {
V_19 = V_7 -> V_49 [ V_14 ] ;
F_15 ( & V_19 -> V_103 , 0 , 0 ) ;
V_19 -> V_28 = 0 ;
}
}
static void F_46 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 , V_12 , V_110 , V_111 ;
V_9 = F_1 () ;
F_45 ( V_7 ) ;
V_10 = F_1 () ;
V_12 = V_10 - V_9 ;
V_7 -> V_112 += V_12 ;
V_7 -> V_113 ++ ;
V_110 = V_7 -> V_112 / V_7 -> V_113 ;
if ( V_12 < V_110 )
V_111 = V_110 - V_12 ;
else
V_111 = V_12 - V_110 ;
V_7 -> V_114 += V_111 ;
if ( ! V_7 -> V_115 )
V_7 -> V_115 = V_12 ;
V_7 -> V_115 = ( V_7 -> V_115 * ( V_7 -> V_107 - 1 ) + V_12 ) / V_7 -> V_107 ;
printf ( L_12 , V_7 -> V_113 , ( double ) V_12 / 1000000.0 ) ;
printf ( L_13 , ( double ) V_7 -> V_115 / 1e6 ) ;
printf ( L_14 ,
( double ) V_7 -> V_99 / 1e6 , ( double ) V_7 -> V_106 / 1e6 ) ;
#if 0
printf(" [%0.2f / %0.2f]",
(double)sched->parent_cpu_usage/1e6,
(double)sched->runavg_parent_cpu_usage/1e6);
#endif
printf ( L_15 ) ;
if ( V_7 -> V_116 )
printf ( L_16 , V_7 -> V_116 ) ;
V_7 -> V_116 = 0 ;
}
static void F_47 ( struct V_6 * V_7 )
{
T_1 V_9 , V_10 ;
V_9 = F_1 () ;
F_3 ( V_7 , 1e6 ) ;
V_10 = F_1 () ;
printf ( L_17 V_15 L_2 , V_10 - V_9 ) ;
V_9 = F_1 () ;
F_4 ( 1e6 ) ;
V_10 = F_1 () ;
printf ( L_18 V_15 L_2 , V_10 - V_9 ) ;
}
static int
F_48 ( struct V_6 * V_7 ,
struct V_117 * V_118 , struct V_119 * V_120 ,
struct V_121 * V_121 V_41 )
{
const char * V_44 = F_49 ( V_118 , V_120 , L_19 ) ;
const T_5 V_43 = F_50 ( V_118 , V_120 , L_20 ) ;
struct V_18 * V_122 , * V_32 ;
if ( V_50 ) {
printf ( L_21 , V_118 ) ;
printf ( L_22 , V_120 -> V_123 , V_44 , V_43 ) ;
}
V_122 = F_17 ( V_7 , V_120 -> V_123 , L_23 ) ;
V_32 = F_17 ( V_7 , V_43 , V_44 ) ;
F_14 ( V_7 , V_122 , V_120 -> time , V_32 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 V_41 )
{
const char * V_124 = F_49 ( V_118 , V_120 , L_24 ) ,
* V_125 = F_49 ( V_118 , V_120 , L_25 ) ;
const T_5 V_126 = F_50 ( V_118 , V_120 , L_26 ) ,
V_127 = F_50 ( V_118 , V_120 , L_27 ) ;
const T_1 V_128 = F_50 ( V_118 , V_120 , L_28 ) ;
struct V_18 * V_129 , V_41 * V_130 ;
T_1 V_131 , V_20 = V_120 -> time ;
int V_132 = V_120 -> V_132 ;
T_6 V_12 ;
if ( V_50 )
printf ( L_29 , V_118 ) ;
if ( V_132 >= V_133 || V_132 < 0 )
return 0 ;
V_131 = V_7 -> V_134 [ V_132 ] ;
if ( V_131 )
V_12 = V_20 - V_131 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_31 ( L_30 V_15 L_31 , V_12 ) ;
return - 1 ;
}
F_52 ( L_32 V_15 L_33 ,
V_124 , V_126 , V_125 , V_127 , V_12 ) ;
V_129 = F_17 ( V_7 , V_126 , V_124 ) ;
V_130 = F_17 ( V_7 , V_127 , V_125 ) ;
V_7 -> V_134 [ V_132 ] = V_20 ;
F_13 ( V_7 , V_129 , V_20 , V_12 ) ;
F_16 ( V_7 , V_129 , V_20 , V_128 ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 ,
union V_135 * V_21 ,
struct V_121 * V_121 )
{
struct V_104 * V_136 , * V_137 ;
V_136 = F_54 ( V_121 , V_21 -> V_138 . V_43 ,
V_21 -> V_138 . V_123 ) ;
V_137 = F_54 ( V_121 , V_21 -> V_138 . V_139 ,
V_21 -> V_138 . V_140 ) ;
if ( V_136 == NULL || V_137 == NULL ) {
F_52 ( L_34 ,
V_136 , V_137 ) ;
goto V_141;
}
if ( V_50 ) {
printf ( L_35 ) ;
printf ( L_36 , F_55 ( V_137 ) , V_137 -> V_123 ) ;
printf ( L_37 , F_55 ( V_136 ) , V_136 -> V_123 ) ;
}
F_17 ( V_7 , V_137 -> V_123 , F_55 ( V_137 ) ) ;
F_17 ( V_7 , V_136 -> V_123 , F_55 ( V_136 ) ) ;
V_141:
F_56 ( V_136 ) ;
F_56 ( V_137 ) ;
return 0 ;
}
static int
F_57 ( struct V_142 * V_143 , struct V_144 * V_145 , struct V_144 * V_146 )
{
struct V_147 * V_148 ;
int V_55 = 0 ;
F_11 ( F_58 ( V_143 ) ) ;
F_59 (sort, list, list) {
V_55 = V_148 -> V_149 ( V_145 , V_146 ) ;
if ( V_55 )
return V_55 ;
}
return V_55 ;
}
static struct V_144 *
F_60 ( struct V_150 * V_151 , struct V_104 * V_104 ,
struct V_142 * V_152 )
{
struct V_153 * V_154 = V_151 -> V_153 ;
struct V_144 V_155 = { . V_104 = V_104 } ;
while ( V_154 ) {
struct V_144 * V_26 ;
int V_149 ;
V_26 = F_61 ( V_154 , struct V_144 , V_154 ) ;
V_149 = F_57 ( V_152 , & V_155 , V_26 ) ;
if ( V_149 > 0 )
V_154 = V_154 -> V_156 ;
else if ( V_149 < 0 )
V_154 = V_154 -> V_157 ;
else {
F_11 ( V_104 != V_26 -> V_104 ) ;
return V_26 ;
}
}
return NULL ;
}
static void
F_62 ( struct V_150 * V_151 , struct V_144 * V_158 ,
struct V_142 * V_152 )
{
struct V_153 * * V_159 = & ( V_151 -> V_153 ) , * V_137 = NULL ;
while ( * V_159 ) {
struct V_144 * V_160 ;
int V_149 ;
V_160 = F_61 ( * V_159 , struct V_144 , V_154 ) ;
V_137 = * V_159 ;
V_149 = F_57 ( V_152 , V_158 , V_160 ) ;
if ( V_149 > 0 )
V_159 = & ( ( * V_159 ) -> V_156 ) ;
else
V_159 = & ( ( * V_159 ) -> V_157 ) ;
}
F_63 ( & V_158 -> V_154 , V_137 , V_159 ) ;
F_64 ( & V_158 -> V_154 , V_151 ) ;
}
static int F_65 ( struct V_6 * V_7 , struct V_104 * V_104 )
{
struct V_144 * V_26 = F_10 ( sizeof( * V_26 ) ) ;
if ( ! V_26 ) {
F_31 ( L_38 , V_161 ) ;
return - 1 ;
}
V_26 -> V_104 = F_66 ( V_104 ) ;
F_67 ( & V_26 -> V_162 ) ;
F_62 ( & V_7 -> V_163 , V_26 , & V_7 -> V_164 ) ;
return 0 ;
}
static char F_68 ( T_1 V_128 )
{
const char * V_165 = V_166 ;
return V_165 [ V_128 ] ;
}
static int
F_69 ( struct V_144 * V_26 ,
char V_167 ,
T_1 V_20 )
{
struct V_168 * V_54 = F_10 ( sizeof( * V_54 ) ) ;
if ( ! V_54 ) {
F_31 ( L_39 , V_161 ) ;
return - 1 ;
}
V_54 -> V_169 = V_20 ;
if ( V_167 == 'R' ) {
V_54 -> V_170 = V_171 ;
V_54 -> V_172 = V_54 -> V_169 ;
}
F_70 ( & V_54 -> V_143 , & V_26 -> V_162 ) ;
return 0 ;
}
static void
F_71 ( struct V_144 * V_26 , T_1 V_12 ,
T_1 V_20 V_41 )
{
struct V_168 * V_54 ;
F_11 ( F_58 ( & V_26 -> V_162 ) ) ;
V_54 = F_72 ( V_26 -> V_162 . V_129 , struct V_168 , V_143 ) ;
V_54 -> V_87 += V_12 ;
V_26 -> V_173 += V_12 ;
}
static void
F_73 ( struct V_144 * V_26 , T_1 V_20 )
{
struct V_168 * V_54 ;
T_1 V_12 ;
if ( F_58 ( & V_26 -> V_162 ) )
return;
V_54 = F_72 ( V_26 -> V_162 . V_129 , struct V_168 , V_143 ) ;
if ( V_54 -> V_170 != V_171 )
return;
if ( V_20 < V_54 -> V_172 ) {
V_54 -> V_170 = V_174 ;
return;
}
V_54 -> V_170 = V_175 ;
V_54 -> V_176 = V_20 ;
V_12 = V_54 -> V_176 - V_54 -> V_172 ;
V_26 -> V_177 += V_12 ;
if ( V_12 > V_26 -> V_178 ) {
V_26 -> V_178 = V_12 ;
V_26 -> V_179 = V_20 ;
}
V_26 -> V_180 ++ ;
}
static int F_74 ( struct V_6 * V_7 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
const T_5 V_126 = F_50 ( V_118 , V_120 , L_26 ) ,
V_127 = F_50 ( V_118 , V_120 , L_27 ) ;
const T_1 V_128 = F_50 ( V_118 , V_120 , L_28 ) ;
struct V_144 * V_181 , * V_182 ;
struct V_104 * V_183 , * V_184 ;
T_1 V_131 , V_20 = V_120 -> time ;
int V_132 = V_120 -> V_132 , V_60 = - 1 ;
T_6 V_12 ;
F_11 ( V_132 >= V_133 || V_132 < 0 ) ;
V_131 = V_7 -> V_134 [ V_132 ] ;
V_7 -> V_134 [ V_132 ] = V_20 ;
if ( V_131 )
V_12 = V_20 - V_131 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_31 ( L_30 V_15 L_31 , V_12 ) ;
return - 1 ;
}
V_183 = F_54 ( V_121 , - 1 , V_126 ) ;
V_184 = F_54 ( V_121 , - 1 , V_127 ) ;
if ( V_183 == NULL || V_184 == NULL )
goto V_141;
V_181 = F_60 ( & V_7 -> V_163 , V_183 , & V_7 -> V_164 ) ;
if ( ! V_181 ) {
if ( F_65 ( V_7 , V_183 ) )
goto V_141;
V_181 = F_60 ( & V_7 -> V_163 , V_183 , & V_7 -> V_164 ) ;
if ( ! V_181 ) {
F_31 ( L_40 ) ;
goto V_141;
}
}
if ( F_69 ( V_181 , F_68 ( V_128 ) , V_20 ) )
return - 1 ;
V_182 = F_60 ( & V_7 -> V_163 , V_184 , & V_7 -> V_164 ) ;
if ( ! V_182 ) {
if ( F_65 ( V_7 , V_184 ) )
goto V_141;
V_182 = F_60 ( & V_7 -> V_163 , V_184 , & V_7 -> V_164 ) ;
if ( ! V_182 ) {
F_31 ( L_41 ) ;
goto V_141;
}
if ( F_69 ( V_182 , 'R' , V_20 ) )
goto V_141;
}
F_73 ( V_182 , V_20 ) ;
V_60 = 0 ;
V_141:
F_56 ( V_183 ) ;
F_56 ( V_184 ) ;
return V_60 ;
}
static int F_75 ( struct V_6 * V_7 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
const T_5 V_43 = F_50 ( V_118 , V_120 , L_20 ) ;
const T_1 V_87 = F_50 ( V_118 , V_120 , L_42 ) ;
struct V_104 * V_104 = F_54 ( V_121 , - 1 , V_43 ) ;
struct V_144 * V_26 = F_60 ( & V_7 -> V_163 , V_104 , & V_7 -> V_164 ) ;
T_1 V_20 = V_120 -> time ;
int V_132 = V_120 -> V_132 , V_60 = - 1 ;
if ( V_104 == NULL )
return - 1 ;
F_11 ( V_132 >= V_133 || V_132 < 0 ) ;
if ( ! V_26 ) {
if ( F_65 ( V_7 , V_104 ) )
goto V_141;
V_26 = F_60 ( & V_7 -> V_163 , V_104 , & V_7 -> V_164 ) ;
if ( ! V_26 ) {
F_31 ( L_41 ) ;
goto V_141;
}
if ( F_69 ( V_26 , 'R' , V_20 ) )
goto V_141;
}
F_71 ( V_26 , V_87 , V_20 ) ;
V_60 = 0 ;
V_141:
F_56 ( V_104 ) ;
return V_60 ;
}
static int F_76 ( struct V_6 * V_7 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
const T_5 V_43 = F_50 ( V_118 , V_120 , L_20 ) ;
struct V_144 * V_26 ;
struct V_168 * V_54 ;
struct V_104 * V_32 ;
T_1 V_20 = V_120 -> time ;
int V_60 = - 1 ;
V_32 = F_54 ( V_121 , - 1 , V_43 ) ;
if ( V_32 == NULL )
return - 1 ;
V_26 = F_60 ( & V_7 -> V_163 , V_32 , & V_7 -> V_164 ) ;
if ( ! V_26 ) {
if ( F_65 ( V_7 , V_32 ) )
goto V_141;
V_26 = F_60 ( & V_7 -> V_163 , V_32 , & V_7 -> V_164 ) ;
if ( ! V_26 ) {
F_31 ( L_43 ) ;
goto V_141;
}
if ( F_69 ( V_26 , 'S' , V_20 ) )
goto V_141;
}
F_11 ( F_58 ( & V_26 -> V_162 ) ) ;
V_54 = F_72 ( V_26 -> V_162 . V_129 , struct V_168 , V_143 ) ;
if ( V_7 -> V_185 == - 1 && V_54 -> V_170 != V_186 )
goto V_187;
V_7 -> V_188 ++ ;
if ( V_54 -> V_169 > V_20 ) {
V_7 -> V_189 ++ ;
goto V_187;
}
V_54 -> V_170 = V_171 ;
V_54 -> V_172 = V_20 ;
V_187:
V_60 = 0 ;
V_141:
F_56 ( V_32 ) ;
return V_60 ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
const T_5 V_43 = F_50 ( V_118 , V_120 , L_20 ) ;
T_1 V_20 = V_120 -> time ;
struct V_144 * V_26 ;
struct V_168 * V_54 ;
struct V_104 * V_190 ;
int V_60 = - 1 ;
if ( V_7 -> V_185 == - 1 )
return 0 ;
V_190 = F_54 ( V_121 , - 1 , V_43 ) ;
if ( V_190 == NULL )
return - 1 ;
V_26 = F_60 ( & V_7 -> V_163 , V_190 , & V_7 -> V_164 ) ;
if ( ! V_26 ) {
if ( F_65 ( V_7 , V_190 ) )
goto V_141;
F_17 ( V_7 , V_190 -> V_123 , F_55 ( V_190 ) ) ;
V_26 = F_60 ( & V_7 -> V_163 , V_190 , & V_7 -> V_164 ) ;
if ( ! V_26 ) {
F_31 ( L_44 ) ;
goto V_141;
}
if ( F_69 ( V_26 , 'R' , V_20 ) )
goto V_141;
}
F_11 ( F_58 ( & V_26 -> V_162 ) ) ;
V_54 = F_72 ( V_26 -> V_162 . V_129 , struct V_168 , V_143 ) ;
V_54 -> V_176 = V_54 -> V_169 = V_54 -> V_172 = V_20 ;
V_7 -> V_188 ++ ;
if ( V_54 -> V_169 > V_20 )
V_7 -> V_189 ++ ;
V_60 = 0 ;
V_141:
F_56 ( V_190 ) ;
return V_60 ;
}
static void F_78 ( struct V_6 * V_7 , struct V_144 * V_162 )
{
int V_14 ;
int V_55 ;
T_1 V_191 ;
if ( ! V_162 -> V_180 )
return;
if ( ! strcmp ( F_55 ( V_162 -> V_104 ) , L_45 ) )
return;
V_7 -> V_192 += V_162 -> V_173 ;
V_7 -> V_193 += V_162 -> V_180 ;
if ( V_162 -> V_194 > 1 )
V_55 = printf ( L_46 , F_55 ( V_162 -> V_104 ) , V_162 -> V_194 ) ;
else
V_55 = printf ( L_47 , F_55 ( V_162 -> V_104 ) , V_162 -> V_104 -> V_123 ) ;
for ( V_14 = 0 ; V_14 < 24 - V_55 ; V_14 ++ )
printf ( L_48 ) ;
V_191 = V_162 -> V_177 / V_162 -> V_180 ;
printf ( L_49 V_15 L_50 ,
( double ) V_162 -> V_173 / 1e6 ,
V_162 -> V_180 , ( double ) V_191 / 1e6 ,
( double ) V_162 -> V_178 / 1e6 ,
( double ) V_162 -> V_179 / 1e9 ) ;
}
static int F_79 ( struct V_144 * V_145 , struct V_144 * V_146 )
{
if ( V_145 -> V_104 == V_146 -> V_104 )
return 0 ;
if ( V_145 -> V_104 -> V_123 < V_146 -> V_104 -> V_123 )
return - 1 ;
if ( V_145 -> V_104 -> V_123 > V_146 -> V_104 -> V_123 )
return 1 ;
return ( int ) ( V_145 -> V_104 - V_146 -> V_104 ) ;
}
static int F_80 ( struct V_144 * V_145 , struct V_144 * V_146 )
{
T_1 V_195 , V_196 ;
if ( ! V_145 -> V_180 )
return - 1 ;
if ( ! V_146 -> V_180 )
return 1 ;
V_195 = V_145 -> V_177 / V_145 -> V_180 ;
V_196 = V_146 -> V_177 / V_146 -> V_180 ;
if ( V_195 < V_196 )
return - 1 ;
if ( V_195 > V_196 )
return 1 ;
return 0 ;
}
static int F_81 ( struct V_144 * V_145 , struct V_144 * V_146 )
{
if ( V_145 -> V_178 < V_146 -> V_178 )
return - 1 ;
if ( V_145 -> V_178 > V_146 -> V_178 )
return 1 ;
return 0 ;
}
static int F_82 ( struct V_144 * V_145 , struct V_144 * V_146 )
{
if ( V_145 -> V_180 < V_146 -> V_180 )
return - 1 ;
if ( V_145 -> V_180 > V_146 -> V_180 )
return 1 ;
return 0 ;
}
static int F_83 ( struct V_144 * V_145 , struct V_144 * V_146 )
{
if ( V_145 -> V_173 < V_146 -> V_173 )
return - 1 ;
if ( V_145 -> V_173 > V_146 -> V_173 )
return 1 ;
return 0 ;
}
static int F_84 ( const char * V_197 , struct V_142 * V_143 )
{
T_2 V_14 ;
static struct V_147 V_198 = {
. V_199 = L_51 ,
. V_149 = F_80 ,
} ;
static struct V_147 V_200 = {
. V_199 = L_52 ,
. V_149 = F_81 ,
} ;
static struct V_147 V_201 = {
. V_199 = L_20 ,
. V_149 = F_79 ,
} ;
static struct V_147 V_202 = {
. V_199 = L_42 ,
. V_149 = F_83 ,
} ;
static struct V_147 V_203 = {
. V_199 = L_53 ,
. V_149 = F_82 ,
} ;
struct V_147 * V_204 [] = {
& V_201 ,
& V_198 ,
& V_200 ,
& V_203 ,
& V_202 ,
} ;
for ( V_14 = 0 ; V_14 < F_85 ( V_204 ) ; V_14 ++ ) {
if ( ! strcmp ( V_204 [ V_14 ] -> V_199 , V_197 ) ) {
F_70 ( & V_204 [ V_14 ] -> V_143 , V_143 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_86 ( struct V_6 * V_7 )
{
struct V_153 * V_154 ;
struct V_150 * V_151 = & V_7 -> V_163 ;
V_96:
for (; ; ) {
struct V_144 * V_158 ;
V_154 = F_87 ( V_151 ) ;
if ( ! V_154 )
break;
F_88 ( V_154 , V_151 ) ;
V_158 = F_89 ( V_154 , struct V_144 , V_154 ) ;
F_62 ( & V_7 -> V_205 , V_158 , & V_7 -> V_152 ) ;
}
if ( V_151 == & V_7 -> V_163 ) {
V_151 = & V_7 -> V_206 ;
goto V_96;
}
}
static int F_90 ( struct V_207 * V_208 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
struct V_6 * V_7 = F_61 ( V_208 , struct V_6 , V_208 ) ;
if ( V_7 -> V_209 -> V_210 )
return V_7 -> V_209 -> V_210 ( V_7 , V_118 , V_120 , V_121 ) ;
return 0 ;
}
static bool F_91 ( struct V_104 * V_104 )
{
union V_211 V_212 = {
. V_213 = F_92 ( V_104 ) ,
} ;
return V_212 . V_214 ;
}
static struct V_104 *
F_93 ( struct V_6 * V_7 , struct V_121 * V_121 , T_7 V_43 , T_7 V_123 )
{
struct V_104 * V_104 = F_54 ( V_121 , V_43 , V_123 ) ;
union V_211 V_212 = {
. V_214 = false ,
} ;
if ( ! V_7 -> V_215 . V_216 || ! V_104 || F_92 ( V_104 ) )
return V_104 ;
if ( F_94 ( V_7 -> V_215 . V_216 , V_123 ) )
V_212 . V_214 = true ;
F_95 ( V_104 , V_212 . V_213 ) ;
return V_104 ;
}
static int F_96 ( struct V_6 * V_7 , struct V_117 * V_118 ,
struct V_119 * V_120 , struct V_121 * V_121 )
{
const T_5 V_127 = F_50 ( V_118 , V_120 , L_27 ) ;
struct V_104 * V_184 ;
int V_217 ;
T_1 V_131 , V_20 = V_120 -> time ;
T_6 V_12 ;
int V_14 , V_218 = V_120 -> V_132 ;
int V_219 ;
bool V_220 = false ;
const char * V_214 = V_221 ;
F_11 ( V_218 >= V_133 || V_218 < 0 ) ;
if ( V_218 > V_7 -> V_222 )
V_7 -> V_222 = V_218 ;
if ( V_7 -> V_215 . V_223 ) {
V_219 = F_97 ( V_7 -> V_215 . V_224 , V_133 ) ;
if ( ! F_98 ( V_218 , V_7 -> V_215 . V_224 ) ) {
V_7 -> V_215 . V_225 [ V_219 ++ ] = V_218 ;
V_220 = true ;
}
} else
V_219 = V_7 -> V_222 ;
V_131 = V_7 -> V_134 [ V_218 ] ;
V_7 -> V_134 [ V_218 ] = V_20 ;
if ( V_131 )
V_12 = V_20 - V_131 ;
else
V_12 = 0 ;
if ( V_12 < 0 ) {
F_31 ( L_30 V_15 L_31 , V_12 ) ;
return - 1 ;
}
V_184 = F_93 ( V_7 , V_121 , - 1 , V_127 ) ;
if ( V_184 == NULL )
return - 1 ;
V_7 -> V_226 [ V_218 ] = F_66 ( V_184 ) ;
printf ( L_54 ) ;
V_217 = 0 ;
if ( ! V_184 -> V_227 [ 0 ] ) {
if ( ! strcmp ( F_55 ( V_184 ) , L_45 ) ) {
V_184 -> V_227 [ 0 ] = '.' ;
V_184 -> V_227 [ 1 ] = ' ' ;
} else {
V_184 -> V_227 [ 0 ] = V_7 -> V_228 ;
V_184 -> V_227 [ 1 ] = V_7 -> V_229 ;
if ( V_7 -> V_228 < 'Z' ) {
V_7 -> V_228 ++ ;
} else {
V_7 -> V_228 = 'A' ;
if ( V_7 -> V_229 < '9' )
V_7 -> V_229 ++ ;
else
V_7 -> V_229 = '0' ;
}
}
V_217 = 1 ;
}
for ( V_14 = 0 ; V_14 < V_219 ; V_14 ++ ) {
int V_132 = V_7 -> V_215 . V_223 ? V_7 -> V_215 . V_225 [ V_14 ] : V_14 ;
struct V_104 * V_226 = V_7 -> V_226 [ V_132 ] ;
const char * V_230 = V_214 ;
const char * V_231 = V_214 ;
if ( V_226 && F_91 ( V_226 ) )
V_230 = V_232 ;
if ( V_7 -> V_215 . V_233 && ! F_99 ( V_7 -> V_215 . V_233 , V_132 ) )
continue;
if ( V_7 -> V_215 . V_234 && F_99 ( V_7 -> V_215 . V_234 , V_132 ) )
V_231 = V_235 ;
if ( V_132 != V_218 )
F_100 ( stdout , V_231 , L_48 ) ;
else
F_100 ( stdout , V_231 , L_55 ) ;
if ( V_7 -> V_226 [ V_132 ] )
F_100 ( stdout , V_230 , L_56 , V_7 -> V_226 [ V_132 ] -> V_227 ) ;
else
F_100 ( stdout , V_214 , L_57 ) ;
}
if ( V_7 -> V_215 . V_233 && ! F_99 ( V_7 -> V_215 . V_233 , V_218 ) )
goto V_236;
F_100 ( stdout , V_214 , L_58 , ( double ) V_20 / 1e9 ) ;
if ( V_217 ) {
const char * V_230 = V_214 ;
if ( F_91 ( V_184 ) )
V_230 = V_232 ;
F_100 ( stdout , V_230 , L_59 ,
V_184 -> V_227 , F_55 ( V_184 ) , V_184 -> V_123 ) ;
}
if ( V_7 -> V_215 . V_223 && V_220 )
F_100 ( stdout , V_214 , L_60 , V_218 ) ;
V_236:
F_100 ( stdout , V_214 , L_15 ) ;
F_56 ( V_184 ) ;
return 0 ;
}
static int F_101 ( struct V_207 * V_208 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
struct V_6 * V_7 = F_61 ( V_208 , struct V_6 , V_208 ) ;
int V_218 = V_120 -> V_132 , V_60 = 0 ;
T_5 V_126 = F_50 ( V_118 , V_120 , L_26 ) ,
V_127 = F_50 ( V_118 , V_120 , L_27 ) ;
if ( V_7 -> V_237 [ V_218 ] != ( T_5 ) - 1 ) {
if ( V_7 -> V_237 [ V_218 ] != V_126 )
V_7 -> V_238 ++ ;
}
if ( V_7 -> V_209 -> V_239 )
V_60 = V_7 -> V_209 -> V_239 ( V_7 , V_118 , V_120 , V_121 ) ;
V_7 -> V_237 [ V_218 ] = V_127 ;
return V_60 ;
}
static int F_102 ( struct V_207 * V_208 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
struct V_6 * V_7 = F_61 ( V_208 , struct V_6 , V_208 ) ;
if ( V_7 -> V_209 -> V_240 )
return V_7 -> V_209 -> V_240 ( V_7 , V_118 , V_120 , V_121 ) ;
return 0 ;
}
static int F_103 ( struct V_207 * V_208 ,
union V_135 * V_21 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
struct V_6 * V_7 = F_61 ( V_208 , struct V_6 , V_208 ) ;
F_104 ( V_208 , V_21 , V_120 , V_121 ) ;
if ( V_7 -> V_209 -> V_241 )
return V_7 -> V_209 -> V_241 ( V_7 , V_21 , V_121 ) ;
return 0 ;
}
static int F_105 ( struct V_207 * V_208 ,
struct V_117 * V_118 ,
struct V_119 * V_120 ,
struct V_121 * V_121 )
{
struct V_6 * V_7 = F_61 ( V_208 , struct V_6 , V_208 ) ;
if ( V_7 -> V_209 -> V_242 )
return V_7 -> V_209 -> V_242 ( V_7 , V_118 , V_120 , V_121 ) ;
return 0 ;
}
static int F_106 ( struct V_207 * V_208 V_41 ,
union V_135 * V_21 V_41 ,
struct V_119 * V_120 ,
struct V_117 * V_118 ,
struct V_121 * V_121 )
{
int V_60 = 0 ;
if ( V_118 -> V_243 != NULL ) {
T_8 V_244 = V_118 -> V_243 ;
V_60 = V_244 ( V_208 , V_118 , V_120 , V_121 ) ;
}
return V_60 ;
}
static int F_107 ( struct V_6 * V_7 )
{
const struct V_245 V_246 [] = {
{ L_61 , F_101 , } ,
{ L_62 , F_102 , } ,
{ L_63 , F_90 , } ,
{ L_64 , F_90 , } ,
{ L_65 , F_105 , } ,
} ;
struct V_247 * V_248 ;
struct V_249 V_250 = {
. V_251 = V_252 ,
. V_253 = V_254 ,
. V_81 = V_7 -> V_81 ,
} ;
int V_255 = - 1 ;
V_248 = F_108 ( & V_250 , false , & V_7 -> V_208 ) ;
if ( V_248 == NULL ) {
F_52 ( L_66 ) ;
return - 1 ;
}
F_109 ( & V_248 -> V_256 . V_257 ) ;
if ( F_110 ( V_248 , V_246 ) )
goto V_258;
if ( F_111 ( V_248 , L_67 ) ) {
int V_60 = F_112 ( V_248 ) ;
if ( V_60 ) {
F_31 ( L_68 , V_60 ) ;
goto V_258;
}
V_7 -> V_23 = V_248 -> V_259 -> V_260 . V_23 [ 0 ] ;
V_7 -> V_261 = V_248 -> V_259 -> V_260 . V_262 ;
V_7 -> V_263 = V_248 -> V_259 -> V_260 . V_23 [ V_264 ] ;
}
V_255 = 0 ;
V_258:
F_113 ( V_248 ) ;
return V_255 ;
}
static void F_114 ( struct V_6 * V_7 )
{
if ( V_7 -> V_189 && V_7 -> V_188 ) {
printf ( L_69 ,
( double ) V_7 -> V_189 / ( double ) V_7 -> V_188 * 100.0 ,
V_7 -> V_189 , V_7 -> V_188 ) ;
}
if ( V_7 -> V_261 && V_7 -> V_23 ) {
printf ( L_70 ,
( double ) V_7 -> V_261 / ( double ) V_7 -> V_23 * 100.0 ,
V_7 -> V_261 , V_7 -> V_23 , V_7 -> V_263 ) ;
}
if ( V_7 -> V_238 && V_7 -> V_188 ) {
printf ( L_71 ,
( double ) V_7 -> V_238 / ( double ) V_7 -> V_188 * 100.0 ,
V_7 -> V_238 , V_7 -> V_188 ) ;
if ( V_7 -> V_261 )
printf ( L_72 ) ;
printf ( L_15 ) ;
}
}
static void F_115 ( struct V_150 * V_151 , struct V_144 * V_158 )
{
struct V_153 * * V_159 = & ( V_151 -> V_153 ) , * V_137 = NULL ;
struct V_144 * V_160 ;
const char * V_44 = F_55 ( V_158 -> V_104 ) , * V_265 ;
while ( * V_159 ) {
int V_149 ;
V_160 = F_61 ( * V_159 , struct V_144 , V_154 ) ;
V_137 = * V_159 ;
V_265 = F_55 ( V_160 -> V_104 ) ;
V_149 = strcmp ( V_44 , V_265 ) ;
if ( V_149 > 0 ) {
V_159 = & ( ( * V_159 ) -> V_156 ) ;
} else if ( V_149 < 0 ) {
V_159 = & ( ( * V_159 ) -> V_157 ) ;
} else {
V_160 -> V_194 ++ ;
V_160 -> V_173 += V_158 -> V_173 ;
V_160 -> V_180 += V_158 -> V_180 ;
V_160 -> V_177 += V_158 -> V_177 ;
F_116 ( & V_158 -> V_162 , & V_160 -> V_162 ) ;
if ( V_160 -> V_178 < V_158 -> V_178 ) {
V_160 -> V_178 = V_158 -> V_178 ;
V_160 -> V_179 = V_158 -> V_179 ;
}
F_36 ( & V_158 ) ;
return;
}
}
V_158 -> V_194 ++ ;
F_63 ( & V_158 -> V_154 , V_137 , V_159 ) ;
F_64 ( & V_158 -> V_154 , V_151 ) ;
}
static void F_117 ( struct V_6 * V_7 )
{
struct V_144 * V_158 ;
struct V_153 * V_154 ;
if ( V_7 -> V_266 )
return;
while ( ( V_154 = F_87 ( & V_7 -> V_163 ) ) ) {
F_88 ( V_154 , & V_7 -> V_163 ) ;
V_158 = F_89 ( V_154 , struct V_144 , V_154 ) ;
F_115 ( & V_7 -> V_206 , V_158 ) ;
}
}
static int F_118 ( struct V_6 * V_7 )
{
struct V_153 * V_130 ;
F_119 () ;
if ( F_107 ( V_7 ) )
return - 1 ;
F_117 ( V_7 ) ;
F_86 ( V_7 ) ;
printf ( L_73 ) ;
printf ( L_74 ) ;
printf ( L_75 ) ;
V_130 = F_87 ( & V_7 -> V_205 ) ;
while ( V_130 ) {
struct V_144 * V_162 ;
V_162 = F_89 ( V_130 , struct V_144 , V_154 ) ;
F_78 ( V_7 , V_162 ) ;
V_130 = F_120 ( V_130 ) ;
F_121 ( V_162 -> V_104 ) ;
}
printf ( L_75 ) ;
printf ( L_76 V_15 L_77 ,
( double ) V_7 -> V_192 / 1e6 , V_7 -> V_193 ) ;
printf ( L_78 ) ;
F_114 ( V_7 ) ;
printf ( L_15 ) ;
return 0 ;
}
static int F_122 ( struct V_6 * V_7 )
{
struct V_267 * V_215 ;
V_7 -> V_222 = F_123 ( V_268 ) ;
if ( V_7 -> V_215 . V_223 ) {
V_7 -> V_215 . V_225 = F_10 ( V_7 -> V_222 * sizeof( int ) ) ;
if ( ! V_7 -> V_215 . V_225 )
return - 1 ;
}
if ( ! V_7 -> V_215 . V_269 )
return 0 ;
V_215 = F_124 ( V_7 -> V_215 . V_269 ) ;
if ( ! V_215 ) {
F_31 ( L_79 , V_7 -> V_215 . V_269 ) ;
return - 1 ;
}
V_7 -> V_215 . V_233 = V_215 ;
return 0 ;
}
static int F_125 ( struct V_6 * V_7 )
{
struct V_270 * V_215 ;
if ( ! V_7 -> V_215 . V_271 )
return 0 ;
V_215 = F_126 ( V_7 -> V_215 . V_271 ) ;
if ( ! V_215 ) {
F_31 ( L_80 , V_7 -> V_215 . V_271 ) ;
return - 1 ;
}
V_7 -> V_215 . V_216 = V_215 ;
return 0 ;
}
static int F_127 ( struct V_6 * V_7 )
{
struct V_267 * V_215 ;
if ( ! V_7 -> V_215 . V_272 )
return 0 ;
V_215 = F_124 ( V_7 -> V_215 . V_272 ) ;
if ( ! V_215 ) {
F_31 ( L_80 , V_7 -> V_215 . V_272 ) ;
return - 1 ;
}
V_7 -> V_215 . V_234 = V_215 ;
return 0 ;
}
static int F_128 ( struct V_6 * V_7 )
{
if ( F_122 ( V_7 ) )
return - 1 ;
if ( F_125 ( V_7 ) )
return - 1 ;
if ( F_127 ( V_7 ) )
return - 1 ;
F_119 () ;
if ( F_107 ( V_7 ) )
return - 1 ;
F_114 ( V_7 ) ;
return 0 ;
}
static int F_129 ( struct V_6 * V_7 )
{
unsigned long V_14 ;
F_6 ( V_7 ) ;
F_8 ( V_7 ) ;
F_47 ( V_7 ) ;
if ( F_107 ( V_7 ) )
return - 1 ;
printf ( L_81 , V_7 -> V_31 ) ;
printf ( L_82 , V_7 -> V_42 ) ;
printf ( L_83 , V_7 -> V_40 ) ;
if ( V_7 -> V_36 )
printf ( L_84 , V_7 -> V_36 ) ;
if ( V_7 -> V_38 )
printf ( L_85 , V_7 -> V_38 ) ;
if ( V_7 -> V_30 )
printf ( L_86 ,
V_7 -> V_30 ) ;
F_19 ( V_7 ) ;
F_20 ( V_7 ) ;
F_40 ( V_7 ) ;
printf ( L_87 ) ;
for ( V_14 = 0 ; V_14 < V_7 -> V_107 ; V_14 ++ )
F_46 ( V_7 ) ;
return 0 ;
}
static void F_130 ( struct V_6 * V_7 , const struct V_273 * V_274 ,
const char * const V_275 [] )
{
char * V_276 , * V_197 , * V_165 = F_131 ( V_7 -> V_277 ) ;
for ( V_197 = strtok_r ( V_165 , L_88 , & V_276 ) ;
V_197 ; V_197 = strtok_r ( NULL , L_88 , & V_276 ) ) {
if ( F_84 ( V_197 , & V_7 -> V_152 ) < 0 ) {
F_132 ( V_275 , V_274 ,
L_89 , V_197 ) ;
}
}
free ( V_165 ) ;
F_84 ( L_20 , & V_7 -> V_164 ) ;
}
static int F_133 ( int V_278 , const char * * V_279 )
{
unsigned int V_280 , V_14 , V_53 ;
const char * * V_281 ;
const char * const V_282 [] = {
L_90 ,
L_91 ,
L_92 ,
L_93 , L_94 ,
L_95 , L_96 ,
L_97 , L_61 ,
L_97 , L_98 ,
L_97 , L_99 ,
L_97 , L_100 ,
L_97 , L_62 ,
L_97 , L_101 ,
L_97 , L_63 ,
L_97 , L_64 ,
L_97 , L_65 ,
} ;
V_280 = F_85 ( V_282 ) + V_278 - 1 ;
V_281 = calloc ( V_280 + 1 , sizeof( char * ) ) ;
if ( V_281 == NULL )
return - V_283 ;
for ( V_14 = 0 ; V_14 < F_85 ( V_282 ) ; V_14 ++ )
V_281 [ V_14 ] = F_131 ( V_282 [ V_14 ] ) ;
for ( V_53 = 1 ; V_53 < ( unsigned int ) V_278 ; V_53 ++ , V_14 ++ )
V_281 [ V_14 ] = V_279 [ V_53 ] ;
F_11 ( V_14 != V_280 ) ;
return F_134 ( V_14 , V_281 , NULL ) ;
}
int F_135 ( int V_278 , const char * * V_279 , const char * T_9 V_41 )
{
const char V_284 [] = L_102 ;
struct V_6 V_7 = {
. V_208 = {
. V_120 = F_106 ,
. V_44 = V_285 ,
. V_286 = V_287 ,
. V_138 = F_103 ,
. V_288 = true ,
} ,
. V_164 = F_136 ( V_7 . V_164 ) ,
. V_152 = F_136 ( V_7 . V_152 ) ,
. V_98 = V_289 ,
. V_101 = V_289 ,
. V_277 = V_284 ,
. V_107 = 10 ,
. V_185 = - 1 ,
. V_228 = 'A' ,
. V_229 = '0' ,
. V_266 = 0 ,
} ;
const struct V_273 V_290 [] = {
F_137 ( 's' , L_103 , & V_7 . V_277 , L_104 ,
L_105 ) ,
F_138 ( 'v' , L_106 , & V_50 ,
L_107 ) ,
F_139 ( 'C' , L_108 , & V_7 . V_185 ,
L_109 ) ,
F_140 ( 'D' , L_110 , & V_291 ,
L_111 ) ,
F_140 ( 'p' , L_112 , & V_7 . V_266 ,
L_113 ) ,
F_141 ()
} ;
const struct V_273 V_292 [] = {
F_142 ( 'r' , L_114 , & V_7 . V_107 ,
L_115 ) ,
F_138 ( 'v' , L_106 , & V_50 ,
L_107 ) ,
F_140 ( 'D' , L_110 , & V_291 ,
L_111 ) ,
F_140 ( 'f' , L_116 , & V_7 . V_81 , L_117 ) ,
F_141 ()
} ;
const struct V_273 V_293 [] = {
F_137 ( 'i' , L_118 , & V_252 , L_119 ,
L_120 ) ,
F_138 ( 'v' , L_106 , & V_50 ,
L_107 ) ,
F_140 ( 'D' , L_110 , & V_291 ,
L_111 ) ,
F_141 ()
} ;
const struct V_273 V_294 [] = {
F_140 ( 0 , L_121 , & V_7 . V_215 . V_223 ,
L_122 ) ,
F_137 ( 0 , L_123 , & V_7 . V_215 . V_271 , L_112 ,
L_124 ) ,
F_137 ( 0 , L_125 , & V_7 . V_215 . V_272 , L_126 ,
L_127 ) ,
F_137 ( 0 , L_126 , & V_7 . V_215 . V_269 , L_126 ,
L_128 ) ,
F_141 ()
} ;
const char * const V_295 [] = {
L_129 ,
NULL
} ;
const char * const V_296 [] = {
L_130 ,
NULL
} ;
const char * const V_297 [] = {
L_131 ,
NULL
} ;
const char * const V_298 [] = { L_90 , L_132 , L_133 ,
L_134 , L_135 , NULL } ;
const char * V_299 [] = {
NULL ,
NULL
} ;
struct V_300 V_301 = {
. V_210 = F_76 ,
. V_239 = F_74 ,
. V_240 = F_75 ,
. V_242 = F_77 ,
} ;
struct V_300 V_302 = {
. V_239 = F_96 ,
} ;
struct V_300 V_303 = {
. V_210 = F_48 ,
. V_239 = F_51 ,
. V_241 = F_53 ,
} ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < F_85 ( V_7 . V_237 ) ; V_14 ++ )
V_7 . V_237 [ V_14 ] = - 1 ;
V_278 = F_143 ( V_278 , V_279 , V_293 , V_298 ,
V_299 , V_304 ) ;
if ( ! V_278 )
F_144 ( V_299 , V_293 ) ;
if ( ! strcmp ( V_279 [ 0 ] , L_135 ) )
return F_145 ( V_278 , V_279 , T_9 ) ;
if ( ! strncmp ( V_279 [ 0 ] , L_136 , 3 ) ) {
return F_133 ( V_278 , V_279 ) ;
} else if ( ! strncmp ( V_279 [ 0 ] , L_137 , 3 ) ) {
V_7 . V_209 = & V_301 ;
if ( V_278 > 1 ) {
V_278 = F_146 ( V_278 , V_279 , V_290 , V_295 , 0 ) ;
if ( V_278 )
F_144 ( V_295 , V_290 ) ;
}
F_130 ( & V_7 , V_290 , V_295 ) ;
return F_118 ( & V_7 ) ;
} else if ( ! strcmp ( V_279 [ 0 ] , L_133 ) ) {
if ( V_278 ) {
V_278 = F_146 ( V_278 , V_279 , V_294 , V_297 , 0 ) ;
if ( V_278 )
F_144 ( V_297 , V_294 ) ;
}
V_7 . V_209 = & V_302 ;
F_130 ( & V_7 , V_290 , V_295 ) ;
return F_128 ( & V_7 ) ;
} else if ( ! strncmp ( V_279 [ 0 ] , L_138 , 3 ) ) {
V_7 . V_209 = & V_303 ;
if ( V_278 ) {
V_278 = F_146 ( V_278 , V_279 , V_292 , V_296 , 0 ) ;
if ( V_278 )
F_144 ( V_296 , V_292 ) ;
}
return F_129 ( & V_7 ) ;
} else {
F_144 ( V_299 , V_293 ) ;
}
return 0 ;
}
