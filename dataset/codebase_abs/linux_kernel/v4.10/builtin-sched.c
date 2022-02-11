static T_1 F_1 ( void )
{
struct V_1 V_2 ;
F_2 ( V_3 , & V_2 ) ;
return V_2 . V_4 * V_5 + V_2 . V_6 ;
}
static void F_3 ( struct V_7 * V_8 , T_1 V_9 )
{
T_1 V_10 = F_1 () , V_11 ;
do {
V_11 = F_1 () ;
} while ( V_11 + V_8 -> V_12 < V_10 + V_9 );
}
static void F_4 ( T_1 V_9 )
{
struct V_1 V_2 ;
V_2 . V_6 = V_9 % 999999999 ;
V_2 . V_4 = V_9 / 999999999 ;
F_5 ( & V_2 , NULL ) ;
}
static void F_6 ( struct V_7 * V_8 )
{
T_1 V_10 , V_11 , V_13 , V_14 = V_5 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 10 ; V_15 ++ ) {
V_10 = F_1 () ;
F_3 ( V_8 , 0 ) ;
V_11 = F_1 () ;
V_13 = V_11 - V_10 ;
V_14 = F_7 ( V_14 , V_13 ) ;
}
V_8 -> V_12 = V_14 ;
printf ( L_1 V_16 L_2 , V_14 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
T_1 V_10 , V_11 , V_13 , V_14 = V_5 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 10 ; V_15 ++ ) {
V_10 = F_1 () ;
F_4 ( 10000 ) ;
V_11 = F_1 () ;
V_13 = V_11 - V_10 ;
V_14 = F_7 ( V_14 , V_13 ) ;
}
V_14 -= 10000 ;
V_8 -> V_17 = V_14 ;
printf ( L_3 V_16 L_2 , V_14 ) ;
}
static struct V_18 *
F_9 ( struct V_19 * V_20 , T_1 V_21 )
{
struct V_18 * V_22 = F_10 ( sizeof( * V_22 ) ) ;
unsigned long V_23 = V_20 -> V_24 ;
T_2 V_25 ;
V_22 -> V_21 = V_21 ;
V_22 -> V_26 = V_23 ;
V_20 -> V_24 ++ ;
V_25 = sizeof( struct V_18 * ) * V_20 -> V_24 ;
V_20 -> V_27 = realloc ( V_20 -> V_27 , V_25 ) ;
F_11 ( ! V_20 -> V_27 ) ;
V_20 -> V_27 [ V_23 ] = V_22 ;
return V_22 ;
}
static struct V_18 * F_12 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_24 )
return NULL ;
return V_20 -> V_27 [ V_20 -> V_24 - 1 ] ;
}
static void F_13 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_1 V_21 , T_1 V_28 )
{
struct V_18 * V_22 , * V_29 = F_12 ( V_20 ) ;
if ( V_29 && V_29 -> type == V_30 ) {
V_8 -> V_31 ++ ;
V_29 -> V_28 += V_28 ;
return;
}
V_22 = F_9 ( V_20 , V_21 ) ;
V_22 -> type = V_30 ;
V_22 -> V_28 = V_28 ;
V_8 -> V_32 ++ ;
}
static void F_14 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_1 V_21 , struct V_19 * V_33 )
{
struct V_18 * V_22 , * V_34 ;
V_22 = F_9 ( V_20 , V_21 ) ;
V_22 -> type = V_35 ;
V_22 -> V_33 = V_33 ;
V_34 = F_12 ( V_33 ) ;
if ( ! V_34 || V_34 -> type != V_36 ) {
V_8 -> V_37 ++ ;
return;
}
if ( V_34 -> V_38 ) {
V_8 -> V_39 ++ ;
return;
}
V_34 -> V_38 = F_10 ( sizeof( * V_34 -> V_38 ) ) ;
F_15 ( V_34 -> V_38 , 0 , 0 ) ;
V_34 -> V_40 = 1 ;
V_22 -> V_38 = V_34 -> V_38 ;
V_8 -> V_41 ++ ;
}
static void F_16 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_1 V_21 , T_1 T_3 V_42 )
{
struct V_18 * V_22 = F_9 ( V_20 , V_21 ) ;
V_22 -> type = V_36 ;
V_8 -> V_43 ++ ;
}
static struct V_19 * F_17 ( struct V_7 * V_8 ,
unsigned long V_44 , const char * V_45 )
{
struct V_19 * V_20 ;
static int V_46 ;
if ( V_8 -> V_47 == NULL ) {
if ( F_18 ( L_4 , & V_46 ) < 0 )
V_46 = V_48 ;
F_11 ( ( V_8 -> V_47 = calloc ( V_46 , sizeof( struct V_19 * ) ) ) == NULL ) ;
}
if ( V_44 >= ( unsigned long ) V_46 ) {
F_11 ( ( V_8 -> V_47 = realloc ( V_8 -> V_47 , ( V_44 + 1 ) *
sizeof( struct V_19 * ) ) ) == NULL ) ;
while ( V_44 >= ( unsigned long ) V_46 )
V_8 -> V_47 [ V_46 ++ ] = NULL ;
}
V_20 = V_8 -> V_47 [ V_44 ] ;
if ( V_20 )
return V_20 ;
V_20 = F_10 ( sizeof( * V_20 ) ) ;
V_20 -> V_44 = V_44 ;
V_20 -> V_26 = V_8 -> V_49 ;
strcpy ( V_20 -> V_45 , V_45 ) ;
F_16 ( V_8 , V_20 , 0 , 0 ) ;
V_8 -> V_47 [ V_44 ] = V_20 ;
V_8 -> V_49 ++ ;
V_8 -> V_50 = realloc ( V_8 -> V_50 , V_8 -> V_49 * sizeof( struct V_19 * ) ) ;
F_11 ( ! V_8 -> V_50 ) ;
V_8 -> V_50 [ V_20 -> V_26 ] = V_20 ;
if ( V_51 )
printf ( L_5 , V_8 -> V_49 , V_44 , V_45 ) ;
return V_20 ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
unsigned long V_15 ;
for ( V_15 = 0 ; V_15 < V_8 -> V_49 ; V_15 ++ ) {
V_20 = V_8 -> V_50 [ V_15 ] ;
printf ( L_6 ,
V_20 -> V_26 , V_20 -> V_45 , V_20 -> V_44 , V_20 -> V_24 ) ;
}
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_19 * V_52 , * V_53 ;
unsigned long V_15 , V_54 ;
for ( V_15 = 0 ; V_15 < V_8 -> V_49 ; V_15 ++ ) {
V_52 = V_8 -> V_50 [ V_15 ] ;
V_54 = V_15 + 1 ;
if ( V_54 == V_8 -> V_49 )
V_54 = 0 ;
V_53 = V_8 -> V_50 [ V_54 ] ;
F_14 ( V_8 , V_52 , 0 , V_53 ) ;
}
}
static void F_21 ( struct V_7 * V_8 ,
struct V_18 * V_55 )
{
int V_56 = 0 ;
switch ( V_55 -> type ) {
case V_30 :
F_3 ( V_8 , V_55 -> V_28 ) ;
break;
case V_36 :
if ( V_55 -> V_38 )
V_56 = F_22 ( V_55 -> V_38 ) ;
F_11 ( V_56 ) ;
break;
case V_35 :
if ( V_55 -> V_38 )
V_56 = F_23 ( V_55 -> V_38 ) ;
F_11 ( V_56 ) ;
break;
case V_57 :
break;
default:
F_11 ( 1 ) ;
}
}
static T_1 F_24 ( void )
{
struct V_58 V_59 ;
T_1 V_60 ;
int V_61 ;
V_61 = F_25 ( V_62 , & V_59 ) ;
F_11 ( V_61 ) ;
V_60 = V_59 . V_63 . V_4 * V_5 + V_59 . V_63 . V_64 * V_65 ;
V_60 += V_59 . V_66 . V_4 * V_5 + V_59 . V_66 . V_64 * V_65 ;
return V_60 ;
}
static int F_26 ( struct V_7 * V_8 , unsigned long V_67 )
{
struct V_68 V_69 ;
char V_70 [ V_71 ] , V_72 [ V_71 ] ;
int V_73 ;
struct V_74 V_75 ;
bool V_76 = false ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . type = V_77 ;
V_69 . V_78 = V_79 ;
V_80:
V_73 = F_27 ( & V_69 , 0 , - 1 , - 1 ,
F_28 () ) ;
if ( V_73 < 0 ) {
if ( V_81 == V_82 ) {
if ( V_8 -> V_83 ) {
F_11 ( F_29 ( V_84 , & V_75 ) == - 1 ) ;
V_75 . V_85 += V_8 -> V_49 - V_67 ;
if ( V_75 . V_85 > V_75 . V_86 ) {
V_75 . V_86 = V_75 . V_85 ;
V_76 = true ;
}
if ( F_30 ( V_84 , & V_75 ) == - 1 ) {
if ( V_76 && V_81 == V_87 )
strcpy ( V_72 , L_7 ) ;
} else
goto V_80;
} else
strcpy ( V_72 , L_8 ) ;
}
F_31 ( L_9
L_10 , V_73 ,
F_32 ( V_81 , V_70 , sizeof( V_70 ) ) , V_72 ) ;
exit ( V_88 ) ;
}
return V_73 ;
}
static T_1 F_33 ( int V_73 )
{
T_1 V_89 ;
int V_56 ;
V_56 = F_34 ( V_73 , & V_89 , sizeof( V_89 ) ) ;
F_11 ( V_56 != sizeof( V_89 ) ) ;
return V_89 ;
}
static void * F_35 ( void * V_90 )
{
struct V_91 * V_92 = V_90 ;
struct V_19 * V_93 = V_92 -> V_20 ;
struct V_7 * V_8 = V_92 -> V_8 ;
T_1 V_94 , V_95 ;
unsigned long V_15 , V_56 ;
char V_96 [ 22 ] ;
int V_73 = V_92 -> V_73 ;
F_36 ( & V_92 ) ;
sprintf ( V_96 , L_11 , V_93 -> V_45 ) ;
F_37 ( V_97 , V_96 ) ;
if ( V_73 < 0 )
return NULL ;
V_98:
V_56 = F_23 ( & V_93 -> V_99 ) ;
F_11 ( V_56 ) ;
V_56 = F_38 ( & V_8 -> V_100 ) ;
F_11 ( V_56 ) ;
V_56 = F_39 ( & V_8 -> V_100 ) ;
F_11 ( V_56 ) ;
V_94 = F_33 ( V_73 ) ;
for ( V_15 = 0 ; V_15 < V_93 -> V_24 ; V_15 ++ ) {
V_93 -> V_29 = V_15 ;
F_21 ( V_8 , V_93 -> V_27 [ V_15 ] ) ;
}
V_95 = F_33 ( V_73 ) ;
V_93 -> V_101 = V_95 - V_94 ;
V_56 = F_23 ( & V_93 -> V_102 ) ;
F_11 ( V_56 ) ;
V_56 = F_38 ( & V_8 -> V_103 ) ;
F_11 ( V_56 ) ;
V_56 = F_39 ( & V_8 -> V_103 ) ;
F_11 ( V_56 ) ;
goto V_98;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_19 * V_20 ;
T_4 V_69 ;
unsigned long V_15 ;
int V_61 ;
V_61 = F_41 ( & V_69 ) ;
F_11 ( V_61 ) ;
V_61 = F_42 ( & V_69 ,
( T_2 ) F_43 ( 16 * 1024 , V_104 ) ) ;
F_11 ( V_61 ) ;
V_61 = F_38 ( & V_8 -> V_100 ) ;
F_11 ( V_61 ) ;
V_61 = F_38 ( & V_8 -> V_103 ) ;
F_11 ( V_61 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_49 ; V_15 ++ ) {
struct V_91 * V_92 = malloc ( sizeof( * V_92 ) ) ;
F_11 ( V_92 == NULL ) ;
V_92 -> V_20 = V_20 = V_8 -> V_50 [ V_15 ] ;
V_92 -> V_8 = V_8 ;
V_92 -> V_73 = F_26 ( V_8 , V_15 ) ;
F_15 ( & V_20 -> V_105 , 0 , 0 ) ;
F_15 ( & V_20 -> V_99 , 0 , 0 ) ;
F_15 ( & V_20 -> V_102 , 0 , 0 ) ;
V_20 -> V_29 = 0 ;
V_61 = F_44 ( & V_20 -> V_106 , & V_69 , F_35 , V_92 ) ;
F_11 ( V_61 ) ;
}
}
static void F_45 ( struct V_7 * V_8 )
{
T_1 V_94 , V_95 ;
struct V_19 * V_20 ;
unsigned long V_15 , V_56 ;
V_8 -> V_107 = F_1 () ;
V_8 -> V_101 = 0 ;
F_39 ( & V_8 -> V_103 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_49 ; V_15 ++ ) {
V_20 = V_8 -> V_50 [ V_15 ] ;
V_56 = F_22 ( & V_20 -> V_99 ) ;
F_11 ( V_56 ) ;
F_15 ( & V_20 -> V_99 , 0 , 0 ) ;
}
V_56 = F_38 ( & V_8 -> V_103 ) ;
F_11 ( V_56 ) ;
V_94 = F_24 () ;
F_39 ( & V_8 -> V_100 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_49 ; V_15 ++ ) {
V_20 = V_8 -> V_50 [ V_15 ] ;
V_56 = F_22 ( & V_20 -> V_102 ) ;
F_11 ( V_56 ) ;
F_15 ( & V_20 -> V_102 , 0 , 0 ) ;
V_8 -> V_101 += V_20 -> V_101 ;
V_20 -> V_101 = 0 ;
}
V_95 = F_24 () ;
if ( ! V_8 -> V_108 )
V_8 -> V_108 = V_8 -> V_101 ;
V_8 -> V_108 = ( V_8 -> V_108 * ( V_8 -> V_109 - 1 ) + V_8 -> V_101 ) / V_8 -> V_109 ;
V_8 -> V_110 = V_95 - V_94 ;
if ( ! V_8 -> V_111 )
V_8 -> V_111 = V_8 -> V_110 ;
V_8 -> V_111 = ( V_8 -> V_111 * ( V_8 -> V_109 - 1 ) +
V_8 -> V_110 ) / V_8 -> V_109 ;
V_56 = F_38 ( & V_8 -> V_100 ) ;
F_11 ( V_56 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_49 ; V_15 ++ ) {
V_20 = V_8 -> V_50 [ V_15 ] ;
F_15 ( & V_20 -> V_105 , 0 , 0 ) ;
V_20 -> V_29 = 0 ;
}
}
static void F_46 ( struct V_7 * V_8 )
{
T_1 V_10 , V_11 , V_13 , V_112 , V_113 ;
V_10 = F_1 () ;
F_45 ( V_8 ) ;
V_11 = F_1 () ;
V_13 = V_11 - V_10 ;
V_8 -> V_114 += V_13 ;
V_8 -> V_115 ++ ;
V_112 = V_8 -> V_114 / V_8 -> V_115 ;
if ( V_13 < V_112 )
V_113 = V_112 - V_13 ;
else
V_113 = V_13 - V_112 ;
V_8 -> V_116 += V_113 ;
if ( ! V_8 -> V_117 )
V_8 -> V_117 = V_13 ;
V_8 -> V_117 = ( V_8 -> V_117 * ( V_8 -> V_109 - 1 ) + V_13 ) / V_8 -> V_109 ;
printf ( L_12 , V_8 -> V_115 , ( double ) V_13 / V_118 ) ;
printf ( L_13 , ( double ) V_8 -> V_117 / V_118 ) ;
printf ( L_14 ,
( double ) V_8 -> V_101 / V_118 , ( double ) V_8 -> V_108 / V_118 ) ;
#if 0
printf(" [%0.2f / %0.2f]",
(double)sched->parent_cpu_usage / NSEC_PER_MSEC,
(double)sched->runavg_parent_cpu_usage / NSEC_PER_MSEC);
#endif
printf ( L_15 ) ;
if ( V_8 -> V_119 )
printf ( L_16 , V_8 -> V_119 ) ;
V_8 -> V_119 = 0 ;
}
static void F_47 ( struct V_7 * V_8 )
{
T_1 V_10 , V_11 ;
V_10 = F_1 () ;
F_3 ( V_8 , V_118 ) ;
V_11 = F_1 () ;
printf ( L_17 V_16 L_2 , V_11 - V_10 ) ;
V_10 = F_1 () ;
F_4 ( V_118 ) ;
V_11 = F_1 () ;
printf ( L_18 V_16 L_2 , V_11 - V_10 ) ;
}
static int
F_48 ( struct V_7 * V_8 ,
struct V_120 * V_121 , struct V_122 * V_123 ,
struct V_124 * V_124 V_42 )
{
const char * V_45 = F_49 ( V_121 , V_123 , L_19 ) ;
const T_5 V_44 = F_50 ( V_121 , V_123 , L_20 ) ;
struct V_19 * V_125 , * V_33 ;
if ( V_51 ) {
printf ( L_21 , V_121 ) ;
printf ( L_22 , V_123 -> V_126 , V_45 , V_44 ) ;
}
V_125 = F_17 ( V_8 , V_123 -> V_126 , L_23 ) ;
V_33 = F_17 ( V_8 , V_44 , V_45 ) ;
F_14 ( V_8 , V_125 , V_123 -> time , V_33 ) ;
return 0 ;
}
static int F_51 ( struct V_7 * V_8 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 V_42 )
{
const char * V_127 = F_49 ( V_121 , V_123 , L_24 ) ,
* V_128 = F_49 ( V_121 , V_123 , L_25 ) ;
const T_5 V_129 = F_50 ( V_121 , V_123 , L_26 ) ,
V_130 = F_50 ( V_121 , V_123 , L_27 ) ;
const T_1 V_131 = F_50 ( V_121 , V_123 , L_28 ) ;
struct V_19 * V_132 , V_42 * V_133 ;
T_1 V_134 , V_21 = V_123 -> time ;
int V_135 = V_123 -> V_135 ;
T_6 V_13 ;
if ( V_51 )
printf ( L_29 , V_121 ) ;
if ( V_135 >= V_136 || V_135 < 0 )
return 0 ;
V_134 = V_8 -> V_137 [ V_135 ] ;
if ( V_134 )
V_13 = V_21 - V_134 ;
else
V_13 = 0 ;
if ( V_13 < 0 ) {
F_31 ( L_30 V_16 L_31 , V_13 ) ;
return - 1 ;
}
F_52 ( L_32 V_16 L_33 ,
V_127 , V_129 , V_128 , V_130 , V_13 ) ;
V_132 = F_17 ( V_8 , V_129 , V_127 ) ;
V_133 = F_17 ( V_8 , V_130 , V_128 ) ;
V_8 -> V_137 [ V_135 ] = V_21 ;
F_13 ( V_8 , V_132 , V_21 , V_13 ) ;
F_16 ( V_8 , V_132 , V_21 , V_131 ) ;
return 0 ;
}
static int F_53 ( struct V_7 * V_8 ,
union V_138 * V_22 ,
struct V_124 * V_124 )
{
struct V_106 * V_139 , * V_140 ;
V_139 = F_54 ( V_124 , V_22 -> V_141 . V_44 ,
V_22 -> V_141 . V_126 ) ;
V_140 = F_54 ( V_124 , V_22 -> V_141 . V_142 ,
V_22 -> V_141 . V_143 ) ;
if ( V_139 == NULL || V_140 == NULL ) {
F_52 ( L_34 ,
V_139 , V_140 ) ;
goto V_144;
}
if ( V_51 ) {
printf ( L_35 ) ;
printf ( L_36 , F_55 ( V_140 ) , V_140 -> V_126 ) ;
printf ( L_37 , F_55 ( V_139 ) , V_139 -> V_126 ) ;
}
F_17 ( V_8 , V_140 -> V_126 , F_55 ( V_140 ) ) ;
F_17 ( V_8 , V_139 -> V_126 , F_55 ( V_139 ) ) ;
V_144:
F_56 ( V_139 ) ;
F_56 ( V_140 ) ;
return 0 ;
}
static int
F_57 ( struct V_145 * V_146 , struct V_147 * V_148 , struct V_147 * V_149 )
{
struct V_150 * V_151 ;
int V_56 = 0 ;
F_11 ( F_58 ( V_146 ) ) ;
F_59 (sort, list, list) {
V_56 = V_151 -> V_152 ( V_148 , V_149 ) ;
if ( V_56 )
return V_56 ;
}
return V_56 ;
}
static struct V_147 *
F_60 ( struct V_153 * V_154 , struct V_106 * V_106 ,
struct V_145 * V_155 )
{
struct V_156 * V_157 = V_154 -> V_156 ;
struct V_147 V_158 = { . V_106 = V_106 } ;
while ( V_157 ) {
struct V_147 * V_27 ;
int V_152 ;
V_27 = F_61 ( V_157 , struct V_147 , V_157 ) ;
V_152 = F_57 ( V_155 , & V_158 , V_27 ) ;
if ( V_152 > 0 )
V_157 = V_157 -> V_159 ;
else if ( V_152 < 0 )
V_157 = V_157 -> V_160 ;
else {
F_11 ( V_106 != V_27 -> V_106 ) ;
return V_27 ;
}
}
return NULL ;
}
static void
F_62 ( struct V_153 * V_154 , struct V_147 * V_161 ,
struct V_145 * V_155 )
{
struct V_156 * * V_162 = & ( V_154 -> V_156 ) , * V_140 = NULL ;
while ( * V_162 ) {
struct V_147 * V_163 ;
int V_152 ;
V_163 = F_61 ( * V_162 , struct V_147 , V_157 ) ;
V_140 = * V_162 ;
V_152 = F_57 ( V_155 , V_161 , V_163 ) ;
if ( V_152 > 0 )
V_162 = & ( ( * V_162 ) -> V_159 ) ;
else
V_162 = & ( ( * V_162 ) -> V_160 ) ;
}
F_63 ( & V_161 -> V_157 , V_140 , V_162 ) ;
F_64 ( & V_161 -> V_157 , V_154 ) ;
}
static int F_65 ( struct V_7 * V_8 , struct V_106 * V_106 )
{
struct V_147 * V_27 = F_10 ( sizeof( * V_27 ) ) ;
if ( ! V_27 ) {
F_31 ( L_38 , V_164 ) ;
return - 1 ;
}
V_27 -> V_106 = F_66 ( V_106 ) ;
F_67 ( & V_27 -> V_165 ) ;
F_62 ( & V_8 -> V_166 , V_27 , & V_8 -> V_167 ) ;
return 0 ;
}
static char F_68 ( T_1 V_131 )
{
const char * V_168 = V_169 ;
return V_168 [ V_131 ] ;
}
static int
F_69 ( struct V_147 * V_27 ,
char V_170 ,
T_1 V_21 )
{
struct V_171 * V_55 = F_10 ( sizeof( * V_55 ) ) ;
if ( ! V_55 ) {
F_31 ( L_39 , V_164 ) ;
return - 1 ;
}
V_55 -> V_172 = V_21 ;
if ( V_170 == 'R' ) {
V_55 -> V_173 = V_174 ;
V_55 -> V_175 = V_55 -> V_172 ;
}
F_70 ( & V_55 -> V_146 , & V_27 -> V_165 ) ;
return 0 ;
}
static void
F_71 ( struct V_147 * V_27 , T_1 V_13 ,
T_1 V_21 V_42 )
{
struct V_171 * V_55 ;
F_11 ( F_58 ( & V_27 -> V_165 ) ) ;
V_55 = F_72 ( V_27 -> V_165 . V_132 , struct V_171 , V_146 ) ;
V_55 -> V_89 += V_13 ;
V_27 -> V_176 += V_13 ;
}
static void
F_73 ( struct V_147 * V_27 , T_1 V_21 )
{
struct V_171 * V_55 ;
T_1 V_13 ;
if ( F_58 ( & V_27 -> V_165 ) )
return;
V_55 = F_72 ( V_27 -> V_165 . V_132 , struct V_171 , V_146 ) ;
if ( V_55 -> V_173 != V_174 )
return;
if ( V_21 < V_55 -> V_175 ) {
V_55 -> V_173 = V_177 ;
return;
}
V_55 -> V_173 = V_178 ;
V_55 -> V_179 = V_21 ;
V_13 = V_55 -> V_179 - V_55 -> V_175 ;
V_27 -> V_180 += V_13 ;
if ( V_13 > V_27 -> V_181 ) {
V_27 -> V_181 = V_13 ;
V_27 -> V_182 = V_21 ;
}
V_27 -> V_183 ++ ;
}
static int F_74 ( struct V_7 * V_8 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
const T_5 V_129 = F_50 ( V_121 , V_123 , L_26 ) ,
V_130 = F_50 ( V_121 , V_123 , L_27 ) ;
const T_1 V_131 = F_50 ( V_121 , V_123 , L_28 ) ;
struct V_147 * V_184 , * V_185 ;
struct V_106 * V_186 , * V_187 ;
T_1 V_134 , V_21 = V_123 -> time ;
int V_135 = V_123 -> V_135 , V_61 = - 1 ;
T_6 V_13 ;
F_11 ( V_135 >= V_136 || V_135 < 0 ) ;
V_134 = V_8 -> V_137 [ V_135 ] ;
V_8 -> V_137 [ V_135 ] = V_21 ;
if ( V_134 )
V_13 = V_21 - V_134 ;
else
V_13 = 0 ;
if ( V_13 < 0 ) {
F_31 ( L_30 V_16 L_31 , V_13 ) ;
return - 1 ;
}
V_186 = F_54 ( V_124 , - 1 , V_129 ) ;
V_187 = F_54 ( V_124 , - 1 , V_130 ) ;
if ( V_186 == NULL || V_187 == NULL )
goto V_144;
V_184 = F_60 ( & V_8 -> V_166 , V_186 , & V_8 -> V_167 ) ;
if ( ! V_184 ) {
if ( F_65 ( V_8 , V_186 ) )
goto V_144;
V_184 = F_60 ( & V_8 -> V_166 , V_186 , & V_8 -> V_167 ) ;
if ( ! V_184 ) {
F_31 ( L_40 ) ;
goto V_144;
}
}
if ( F_69 ( V_184 , F_68 ( V_131 ) , V_21 ) )
return - 1 ;
V_185 = F_60 ( & V_8 -> V_166 , V_187 , & V_8 -> V_167 ) ;
if ( ! V_185 ) {
if ( F_65 ( V_8 , V_187 ) )
goto V_144;
V_185 = F_60 ( & V_8 -> V_166 , V_187 , & V_8 -> V_167 ) ;
if ( ! V_185 ) {
F_31 ( L_41 ) ;
goto V_144;
}
if ( F_69 ( V_185 , 'R' , V_21 ) )
goto V_144;
}
F_73 ( V_185 , V_21 ) ;
V_61 = 0 ;
V_144:
F_56 ( V_186 ) ;
F_56 ( V_187 ) ;
return V_61 ;
}
static int F_75 ( struct V_7 * V_8 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
const T_5 V_44 = F_50 ( V_121 , V_123 , L_20 ) ;
const T_1 V_89 = F_50 ( V_121 , V_123 , L_42 ) ;
struct V_106 * V_106 = F_54 ( V_124 , - 1 , V_44 ) ;
struct V_147 * V_27 = F_60 ( & V_8 -> V_166 , V_106 , & V_8 -> V_167 ) ;
T_1 V_21 = V_123 -> time ;
int V_135 = V_123 -> V_135 , V_61 = - 1 ;
if ( V_106 == NULL )
return - 1 ;
F_11 ( V_135 >= V_136 || V_135 < 0 ) ;
if ( ! V_27 ) {
if ( F_65 ( V_8 , V_106 ) )
goto V_144;
V_27 = F_60 ( & V_8 -> V_166 , V_106 , & V_8 -> V_167 ) ;
if ( ! V_27 ) {
F_31 ( L_41 ) ;
goto V_144;
}
if ( F_69 ( V_27 , 'R' , V_21 ) )
goto V_144;
}
F_71 ( V_27 , V_89 , V_21 ) ;
V_61 = 0 ;
V_144:
F_56 ( V_106 ) ;
return V_61 ;
}
static int F_76 ( struct V_7 * V_8 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
const T_5 V_44 = F_50 ( V_121 , V_123 , L_20 ) ;
struct V_147 * V_27 ;
struct V_171 * V_55 ;
struct V_106 * V_33 ;
T_1 V_21 = V_123 -> time ;
int V_61 = - 1 ;
V_33 = F_54 ( V_124 , - 1 , V_44 ) ;
if ( V_33 == NULL )
return - 1 ;
V_27 = F_60 ( & V_8 -> V_166 , V_33 , & V_8 -> V_167 ) ;
if ( ! V_27 ) {
if ( F_65 ( V_8 , V_33 ) )
goto V_144;
V_27 = F_60 ( & V_8 -> V_166 , V_33 , & V_8 -> V_167 ) ;
if ( ! V_27 ) {
F_31 ( L_43 ) ;
goto V_144;
}
if ( F_69 ( V_27 , 'S' , V_21 ) )
goto V_144;
}
F_11 ( F_58 ( & V_27 -> V_165 ) ) ;
V_55 = F_72 ( V_27 -> V_165 . V_132 , struct V_171 , V_146 ) ;
if ( V_8 -> V_188 == - 1 && V_55 -> V_173 != V_189 )
goto V_190;
V_8 -> V_191 ++ ;
if ( V_55 -> V_172 > V_21 ) {
V_8 -> V_192 ++ ;
goto V_190;
}
V_55 -> V_173 = V_174 ;
V_55 -> V_175 = V_21 ;
V_190:
V_61 = 0 ;
V_144:
F_56 ( V_33 ) ;
return V_61 ;
}
static int F_77 ( struct V_7 * V_8 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
const T_5 V_44 = F_50 ( V_121 , V_123 , L_20 ) ;
T_1 V_21 = V_123 -> time ;
struct V_147 * V_27 ;
struct V_171 * V_55 ;
struct V_106 * V_193 ;
int V_61 = - 1 ;
if ( V_8 -> V_188 == - 1 )
return 0 ;
V_193 = F_54 ( V_124 , - 1 , V_44 ) ;
if ( V_193 == NULL )
return - 1 ;
V_27 = F_60 ( & V_8 -> V_166 , V_193 , & V_8 -> V_167 ) ;
if ( ! V_27 ) {
if ( F_65 ( V_8 , V_193 ) )
goto V_144;
F_17 ( V_8 , V_193 -> V_126 , F_55 ( V_193 ) ) ;
V_27 = F_60 ( & V_8 -> V_166 , V_193 , & V_8 -> V_167 ) ;
if ( ! V_27 ) {
F_31 ( L_44 ) ;
goto V_144;
}
if ( F_69 ( V_27 , 'R' , V_21 ) )
goto V_144;
}
F_11 ( F_58 ( & V_27 -> V_165 ) ) ;
V_55 = F_72 ( V_27 -> V_165 . V_132 , struct V_171 , V_146 ) ;
V_55 -> V_179 = V_55 -> V_172 = V_55 -> V_175 = V_21 ;
V_8 -> V_191 ++ ;
if ( V_55 -> V_172 > V_21 )
V_8 -> V_192 ++ ;
V_61 = 0 ;
V_144:
F_56 ( V_193 ) ;
return V_61 ;
}
static void F_78 ( struct V_7 * V_8 , struct V_147 * V_165 )
{
int V_15 ;
int V_56 ;
T_1 V_194 ;
char V_182 [ 32 ] ;
if ( ! V_165 -> V_183 )
return;
if ( ! strcmp ( F_55 ( V_165 -> V_106 ) , L_45 ) )
return;
V_8 -> V_195 += V_165 -> V_176 ;
V_8 -> V_196 += V_165 -> V_183 ;
if ( V_165 -> V_197 > 1 )
V_56 = printf ( L_46 , F_55 ( V_165 -> V_106 ) , V_165 -> V_197 ) ;
else
V_56 = printf ( L_47 , F_55 ( V_165 -> V_106 ) , V_165 -> V_106 -> V_126 ) ;
for ( V_15 = 0 ; V_15 < 24 - V_56 ; V_15 ++ )
printf ( L_48 ) ;
V_194 = V_165 -> V_180 / V_165 -> V_183 ;
F_79 ( V_165 -> V_182 , V_182 , sizeof( V_182 ) ) ;
printf ( L_49 V_16 L_50 ,
( double ) V_165 -> V_176 / V_118 ,
V_165 -> V_183 , ( double ) V_194 / V_118 ,
( double ) V_165 -> V_181 / V_118 ,
V_182 ) ;
}
static int F_80 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_106 == V_149 -> V_106 )
return 0 ;
if ( V_148 -> V_106 -> V_126 < V_149 -> V_106 -> V_126 )
return - 1 ;
if ( V_148 -> V_106 -> V_126 > V_149 -> V_106 -> V_126 )
return 1 ;
return ( int ) ( V_148 -> V_106 - V_149 -> V_106 ) ;
}
static int F_81 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
T_1 V_198 , V_199 ;
if ( ! V_148 -> V_183 )
return - 1 ;
if ( ! V_149 -> V_183 )
return 1 ;
V_198 = V_148 -> V_180 / V_148 -> V_183 ;
V_199 = V_149 -> V_180 / V_149 -> V_183 ;
if ( V_198 < V_199 )
return - 1 ;
if ( V_198 > V_199 )
return 1 ;
return 0 ;
}
static int F_82 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_181 < V_149 -> V_181 )
return - 1 ;
if ( V_148 -> V_181 > V_149 -> V_181 )
return 1 ;
return 0 ;
}
static int F_83 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_183 < V_149 -> V_183 )
return - 1 ;
if ( V_148 -> V_183 > V_149 -> V_183 )
return 1 ;
return 0 ;
}
static int F_84 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_176 < V_149 -> V_176 )
return - 1 ;
if ( V_148 -> V_176 > V_149 -> V_176 )
return 1 ;
return 0 ;
}
static int F_85 ( const char * V_200 , struct V_145 * V_146 )
{
T_2 V_15 ;
static struct V_150 V_201 = {
. V_202 = L_51 ,
. V_152 = F_81 ,
} ;
static struct V_150 V_203 = {
. V_202 = L_52 ,
. V_152 = F_82 ,
} ;
static struct V_150 V_204 = {
. V_202 = L_20 ,
. V_152 = F_80 ,
} ;
static struct V_150 V_205 = {
. V_202 = L_42 ,
. V_152 = F_84 ,
} ;
static struct V_150 V_206 = {
. V_202 = L_53 ,
. V_152 = F_83 ,
} ;
struct V_150 * V_207 [] = {
& V_204 ,
& V_201 ,
& V_203 ,
& V_206 ,
& V_205 ,
} ;
for ( V_15 = 0 ; V_15 < F_86 ( V_207 ) ; V_15 ++ ) {
if ( ! strcmp ( V_207 [ V_15 ] -> V_202 , V_200 ) ) {
F_70 ( & V_207 [ V_15 ] -> V_146 , V_146 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_156 * V_157 ;
struct V_153 * V_154 = & V_8 -> V_166 ;
V_98:
for (; ; ) {
struct V_147 * V_161 ;
V_157 = F_88 ( V_154 ) ;
if ( ! V_157 )
break;
F_89 ( V_157 , V_154 ) ;
V_161 = F_90 ( V_157 , struct V_147 , V_157 ) ;
F_62 ( & V_8 -> V_208 , V_161 , & V_8 -> V_155 ) ;
}
if ( V_154 == & V_8 -> V_166 ) {
V_154 = & V_8 -> V_209 ;
goto V_98;
}
}
static int F_91 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
if ( V_8 -> V_212 -> V_213 )
return V_8 -> V_212 -> V_213 ( V_8 , V_121 , V_123 , V_124 ) ;
return 0 ;
}
static bool F_92 ( struct V_106 * V_106 )
{
union V_214 V_215 = {
. V_216 = F_93 ( V_106 ) ,
} ;
return V_215 . V_217 ;
}
static struct V_106 *
F_94 ( struct V_7 * V_8 , struct V_124 * V_124 , T_7 V_44 , T_7 V_126 )
{
struct V_106 * V_106 = F_54 ( V_124 , V_44 , V_126 ) ;
union V_214 V_215 = {
. V_217 = false ,
} ;
if ( ! V_8 -> V_218 . V_219 || ! V_106 || F_93 ( V_106 ) )
return V_106 ;
if ( F_95 ( V_8 -> V_218 . V_219 , V_126 ) )
V_215 . V_217 = true ;
F_96 ( V_106 , V_215 . V_216 ) ;
return V_106 ;
}
static int F_97 ( struct V_7 * V_8 , struct V_120 * V_121 ,
struct V_122 * V_123 , struct V_124 * V_124 )
{
const T_5 V_130 = F_50 ( V_121 , V_123 , L_27 ) ;
struct V_106 * V_187 ;
int V_220 ;
T_1 V_134 , V_21 = V_123 -> time ;
T_6 V_13 ;
int V_15 , V_221 = V_123 -> V_135 ;
int V_222 ;
bool V_223 = false ;
const char * V_217 = V_224 ;
char V_225 [ 32 ] ;
F_11 ( V_221 >= V_136 || V_221 < 0 ) ;
if ( V_221 > V_8 -> V_226 )
V_8 -> V_226 = V_221 ;
if ( V_8 -> V_218 . V_227 ) {
V_222 = F_98 ( V_8 -> V_218 . V_228 , V_136 ) ;
if ( ! F_99 ( V_221 , V_8 -> V_218 . V_228 ) ) {
V_8 -> V_218 . V_229 [ V_222 ++ ] = V_221 ;
V_223 = true ;
}
} else
V_222 = V_8 -> V_226 ;
V_134 = V_8 -> V_137 [ V_221 ] ;
V_8 -> V_137 [ V_221 ] = V_21 ;
if ( V_134 )
V_13 = V_21 - V_134 ;
else
V_13 = 0 ;
if ( V_13 < 0 ) {
F_31 ( L_30 V_16 L_31 , V_13 ) ;
return - 1 ;
}
V_187 = F_94 ( V_8 , V_124 , - 1 , V_130 ) ;
if ( V_187 == NULL )
return - 1 ;
V_8 -> V_230 [ V_221 ] = F_66 ( V_187 ) ;
printf ( L_54 ) ;
V_220 = 0 ;
if ( ! V_187 -> V_231 [ 0 ] ) {
if ( ! strcmp ( F_55 ( V_187 ) , L_45 ) ) {
V_187 -> V_231 [ 0 ] = '.' ;
V_187 -> V_231 [ 1 ] = ' ' ;
} else {
V_187 -> V_231 [ 0 ] = V_8 -> V_232 ;
V_187 -> V_231 [ 1 ] = V_8 -> V_233 ;
if ( V_8 -> V_232 < 'Z' ) {
V_8 -> V_232 ++ ;
} else {
V_8 -> V_232 = 'A' ;
if ( V_8 -> V_233 < '9' )
V_8 -> V_233 ++ ;
else
V_8 -> V_233 = '0' ;
}
}
V_220 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_222 ; V_15 ++ ) {
int V_135 = V_8 -> V_218 . V_227 ? V_8 -> V_218 . V_229 [ V_15 ] : V_15 ;
struct V_106 * V_230 = V_8 -> V_230 [ V_135 ] ;
const char * V_234 = V_217 ;
const char * V_235 = V_217 ;
if ( V_230 && F_92 ( V_230 ) )
V_234 = V_236 ;
if ( V_8 -> V_218 . V_237 && ! F_100 ( V_8 -> V_218 . V_237 , V_135 ) )
continue;
if ( V_8 -> V_218 . V_238 && F_100 ( V_8 -> V_218 . V_238 , V_135 ) )
V_235 = V_239 ;
if ( V_135 != V_221 )
F_101 ( stdout , V_217 , L_48 ) ;
else
F_101 ( stdout , V_235 , L_55 ) ;
if ( V_8 -> V_230 [ V_135 ] )
F_101 ( stdout , V_234 , L_56 , V_8 -> V_230 [ V_135 ] -> V_231 ) ;
else
F_101 ( stdout , V_217 , L_57 ) ;
}
if ( V_8 -> V_218 . V_237 && ! F_100 ( V_8 -> V_218 . V_237 , V_221 ) )
goto V_240;
F_79 ( V_21 , V_225 , sizeof( V_225 ) ) ;
F_101 ( stdout , V_217 , L_58 , V_225 ) ;
if ( V_220 || ( V_51 && V_187 -> V_126 ) ) {
const char * V_234 = V_217 ;
if ( F_92 ( V_187 ) )
V_234 = V_236 ;
F_101 ( stdout , V_234 , L_59 ,
V_187 -> V_231 , F_55 ( V_187 ) , V_187 -> V_126 ) ;
}
if ( V_8 -> V_218 . V_227 && V_223 )
F_101 ( stdout , V_217 , L_60 , V_221 ) ;
V_240:
F_101 ( stdout , V_217 , L_15 ) ;
F_56 ( V_187 ) ;
return 0 ;
}
static int F_102 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
int V_221 = V_123 -> V_135 , V_61 = 0 ;
T_5 V_129 = F_50 ( V_121 , V_123 , L_26 ) ,
V_130 = F_50 ( V_121 , V_123 , L_27 ) ;
if ( V_8 -> V_241 [ V_221 ] != ( T_5 ) - 1 ) {
if ( V_8 -> V_241 [ V_221 ] != V_129 )
V_8 -> V_242 ++ ;
}
if ( V_8 -> V_212 -> V_243 )
V_61 = V_8 -> V_212 -> V_243 ( V_8 , V_121 , V_123 , V_124 ) ;
V_8 -> V_241 [ V_221 ] = V_130 ;
return V_61 ;
}
static int F_103 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
if ( V_8 -> V_212 -> V_244 )
return V_8 -> V_212 -> V_244 ( V_8 , V_121 , V_123 , V_124 ) ;
return 0 ;
}
static int F_104 ( struct V_210 * V_211 ,
union V_138 * V_22 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
F_105 ( V_211 , V_22 , V_123 , V_124 ) ;
if ( V_8 -> V_212 -> V_245 )
return V_8 -> V_212 -> V_245 ( V_8 , V_22 , V_124 ) ;
return 0 ;
}
static int F_106 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
if ( V_8 -> V_212 -> V_246 )
return V_8 -> V_212 -> V_246 ( V_8 , V_121 , V_123 , V_124 ) ;
return 0 ;
}
static int F_107 ( struct V_210 * V_211 V_42 ,
union V_138 * V_22 V_42 ,
struct V_122 * V_123 ,
struct V_120 * V_121 ,
struct V_124 * V_124 )
{
int V_61 = 0 ;
if ( V_121 -> V_247 != NULL ) {
T_8 V_248 = V_121 -> V_247 ;
V_61 = V_248 ( V_211 , V_121 , V_123 , V_124 ) ;
}
return V_61 ;
}
static int F_108 ( struct V_7 * V_8 )
{
const struct V_249 V_250 [] = {
{ L_61 , F_102 , } ,
{ L_62 , F_103 , } ,
{ L_63 , F_91 , } ,
{ L_64 , F_91 , } ,
{ L_65 , F_106 , } ,
} ;
struct V_251 * V_252 ;
struct V_253 V_254 = {
. V_255 = V_256 ,
. V_257 = V_258 ,
. V_83 = V_8 -> V_83 ,
} ;
int V_259 = - 1 ;
V_252 = F_109 ( & V_254 , false , & V_8 -> V_211 ) ;
if ( V_252 == NULL ) {
F_52 ( L_66 ) ;
return - 1 ;
}
F_110 ( & V_252 -> V_260 . V_261 ) ;
if ( F_111 ( V_252 , V_250 ) )
goto V_262;
if ( F_112 ( V_252 , L_67 ) ) {
int V_61 = F_113 ( V_252 ) ;
if ( V_61 ) {
F_31 ( L_68 , V_61 ) ;
goto V_262;
}
V_8 -> V_24 = V_252 -> V_263 -> V_264 . V_24 [ 0 ] ;
V_8 -> V_265 = V_252 -> V_263 -> V_264 . V_266 ;
V_8 -> V_267 = V_252 -> V_263 -> V_264 . V_24 [ V_268 ] ;
}
V_259 = 0 ;
V_262:
F_114 ( V_252 ) ;
return V_259 ;
}
static inline void F_115 ( unsigned long long V_9 , int V_269 )
{
unsigned long V_270 ;
unsigned long V_271 ;
V_270 = V_9 / V_118 ;
V_9 -= V_270 * V_118 ;
V_271 = V_9 / V_65 ;
printf ( L_69 , V_269 , V_270 , V_271 ) ;
}
static struct V_272 * F_116 ( struct V_120 * V_121 )
{
struct V_272 * V_149 = V_121 -> V_215 ;
if ( V_149 == NULL ) {
V_149 = F_10 ( sizeof( struct V_272 ) ) ;
V_121 -> V_215 = V_149 ;
}
return V_149 ;
}
static void F_117 ( struct V_120 * V_121 ,
T_1 V_21 , T_5 V_135 )
{
struct V_272 * V_149 = F_116 ( V_121 ) ;
if ( V_149 == NULL )
return;
if ( ( V_135 >= V_149 -> V_273 ) || ( V_149 -> V_274 == NULL ) ) {
int V_15 , V_275 = F_118 ( V_135 + 1 ) ;
void * V_276 = V_149 -> V_274 ;
V_276 = realloc ( V_149 -> V_274 , V_275 * sizeof( T_1 ) ) ;
if ( ! V_276 )
return;
V_149 -> V_274 = V_276 ;
for ( V_15 = V_149 -> V_273 ; V_15 < V_275 ; ++ V_15 )
V_149 -> V_274 [ V_15 ] = ( T_1 ) 0 ;
V_149 -> V_273 = V_275 ;
}
V_149 -> V_274 [ V_135 ] = V_21 ;
}
static T_1 F_119 ( struct V_120 * V_121 , T_5 V_135 )
{
struct V_272 * V_149 = F_116 ( V_121 ) ;
if ( ( V_149 == NULL ) || ( V_149 -> V_274 == NULL ) || ( V_135 >= V_149 -> V_273 ) )
return 0 ;
return V_149 -> V_274 [ V_135 ] ;
}
static char * F_120 ( struct V_106 * V_106 )
{
static char V_168 [ 32 ] ;
const char * V_45 = F_55 ( V_106 ) ;
T_7 V_126 = V_106 -> V_126 ;
T_7 V_44 = V_106 -> V_277 ;
int V_275 ;
if ( V_44 == 0 )
V_275 = F_121 ( V_168 , sizeof( V_168 ) , L_70 , V_45 ) ;
else if ( V_126 != V_44 )
V_275 = F_121 ( V_168 , sizeof( V_168 ) , L_71 , V_45 , V_126 , V_44 ) ;
else
V_275 = F_121 ( V_168 , sizeof( V_168 ) , L_72 , V_45 , V_126 ) ;
if ( V_275 > V_278 )
V_278 = V_275 ;
return V_168 ;
}
static void F_122 ( struct V_7 * V_8 )
{
T_5 V_279 = V_8 -> V_226 + 1 ;
T_5 V_15 , V_54 ;
printf ( L_73 , L_74 , L_75 ) ;
if ( V_8 -> V_280 ) {
printf ( L_48 ) ;
for ( V_15 = 0 , V_54 = 0 ; V_15 < V_279 ; ++ V_15 ) {
printf ( L_76 , V_54 ++ ) ;
if ( V_54 > 15 )
V_54 = 0 ;
}
printf ( L_48 ) ;
}
printf ( L_77 , V_278 ,
L_78 , L_79 , L_80 , L_81 ) ;
printf ( L_15 ) ;
printf ( L_82 , L_83 , L_83 ) ;
if ( V_8 -> V_280 )
printf ( L_84 , V_279 , L_83 ) ;
printf ( L_85 , V_278 ,
L_86 , L_87 , L_87 , L_87 ) ;
printf ( L_88 , V_281 , V_281 ) ;
if ( V_8 -> V_280 )
printf ( L_89 , V_279 , V_281 ) ;
printf ( L_90 , V_278 ,
V_281 , V_281 , V_281 ,
V_281 ) ;
printf ( L_15 ) ;
}
static void F_123 ( struct V_7 * V_8 ,
struct V_122 * V_123 ,
struct V_282 * V_283 ,
struct V_106 * V_106 ,
T_1 V_284 )
{
struct V_285 * V_286 = F_93 ( V_106 ) ;
T_5 V_287 = V_8 -> V_226 + 1 ;
char V_288 [ 64 ] ;
F_79 ( V_284 , V_288 , sizeof( V_288 ) ) ;
printf ( L_91 , V_288 , V_123 -> V_135 ) ;
if ( V_8 -> V_280 ) {
T_5 V_15 ;
char V_289 ;
printf ( L_48 ) ;
for ( V_15 = 0 ; V_15 < V_287 ; ++ V_15 ) {
if ( V_15 == V_123 -> V_135 )
V_289 = ( V_106 -> V_126 == 0 ) ? 'i' : 's' ;
else
V_289 = ' ' ;
printf ( L_92 , V_289 ) ;
}
printf ( L_48 ) ;
}
printf ( L_93 , V_278 , F_120 ( V_106 ) ) ;
F_115 ( V_286 -> V_290 , 6 ) ;
F_115 ( V_286 -> V_291 , 6 ) ;
F_115 ( V_286 -> V_292 , 6 ) ;
if ( V_8 -> V_293 )
printf ( L_94 , V_278 , L_83 ) ;
if ( V_106 -> V_126 == 0 )
goto V_240;
if ( V_8 -> V_294 )
printf ( L_54 ) ;
F_124 ( V_123 , V_283 , 0 ,
V_295 | V_296 |
V_297 |
V_298 ,
& V_299 , stdout ) ;
V_240:
printf ( L_15 ) ;
}
static void F_125 ( struct V_285 * V_149 ,
T_1 V_284 , T_1 V_300 )
{
V_149 -> V_291 = 0 ;
V_149 -> V_290 = 0 ;
V_149 -> V_292 = 0 ;
if ( V_300 ) {
V_149 -> V_292 = V_284 - V_300 ;
if ( V_149 -> V_301 ) {
if ( V_149 -> V_301 > V_300 )
F_52 ( L_95 ) ;
else
V_149 -> V_291 = V_300 - V_149 -> V_301 ;
}
if ( V_149 -> V_274 > V_300 )
F_52 ( L_96 ) ;
else if ( V_149 -> V_274 )
V_149 -> V_290 = V_300 - V_149 -> V_274 ;
}
F_126 ( & V_149 -> V_302 , V_149 -> V_292 ) ;
V_149 -> V_303 += V_149 -> V_292 ;
}
static bool F_127 ( struct V_122 * V_123 ,
struct V_120 * V_121 )
{
if ( strcmp ( F_128 ( V_121 ) , L_61 ) == 0 )
return F_50 ( V_121 , V_123 , L_26 ) == 0 ;
return V_123 -> V_44 == 0 ;
}
static void F_129 ( struct V_7 * V_8 ,
struct V_122 * V_123 ,
struct V_120 * V_121 ,
struct V_124 * V_124 )
{
struct V_299 * V_304 = & V_299 ;
struct V_106 * V_106 ;
V_106 = F_54 ( V_124 , V_123 -> V_44 , V_123 -> V_44 ) ;
if ( V_106 == NULL ) {
F_52 ( L_97 , V_123 -> V_44 ) ;
return;
}
if ( ! V_305 . V_306 || V_123 -> V_307 == NULL )
return;
if ( F_130 ( V_106 , V_304 , V_121 , V_123 ,
NULL , NULL , V_8 -> V_308 + 2 ) != 0 ) {
if ( V_51 )
error ( L_98 ) ;
return;
}
F_131 ( V_304 ) ;
while ( true ) {
struct V_309 * V_157 ;
struct V_310 * V_311 ;
V_157 = F_132 ( V_304 ) ;
if ( V_157 == NULL )
break;
V_311 = V_157 -> V_311 ;
if ( V_311 && V_311 -> V_202 ) {
if ( ! strcmp ( V_311 -> V_202 , L_99 ) ||
! strcmp ( V_311 -> V_202 , L_100 ) ||
! strcmp ( V_311 -> V_202 , L_101 ) )
V_311 -> V_312 = 1 ;
}
F_133 ( V_304 ) ;
}
}
static int F_134 ( struct V_106 * V_106 )
{
struct V_313 * V_314 ;
F_135 ( V_106 , V_315 , 0 ) ;
V_314 = F_10 ( sizeof( * V_314 ) ) ;
if ( V_314 == NULL )
return - V_316 ;
F_136 ( & V_314 -> V_286 . V_302 ) ;
F_137 ( & V_314 -> V_307 ) ;
F_138 ( & V_314 -> V_304 ) ;
F_96 ( V_106 , V_314 ) ;
return 0 ;
}
static int F_139 ( int V_273 )
{
int V_15 , V_56 ;
V_317 = F_10 ( V_273 * sizeof( struct V_106 * ) ) ;
if ( ! V_317 )
return - V_316 ;
V_318 = V_273 ;
for ( V_15 = 0 ; V_15 < V_273 ; ++ V_15 ) {
V_317 [ V_15 ] = F_140 ( 0 , 0 ) ;
if ( V_317 [ V_15 ] == NULL )
return - V_316 ;
V_56 = F_134 ( V_317 [ V_15 ] ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
static void F_141 ( void )
{
int V_15 ;
if ( V_317 == NULL )
return;
for ( V_15 = 0 ; V_15 < V_318 ; ++ V_15 ) {
if ( ( V_317 [ V_15 ] ) )
F_142 ( V_317 [ V_15 ] ) ;
}
free ( V_317 ) ;
}
static struct V_106 * F_143 ( int V_135 )
{
if ( ( V_135 >= V_318 ) || ( V_317 == NULL ) ) {
int V_15 , V_54 = F_118 ( V_135 + 1 ) ;
void * V_276 ;
V_276 = realloc ( V_317 , V_54 * sizeof( struct V_106 * ) ) ;
if ( ! V_276 )
return NULL ;
V_317 = (struct V_106 * * ) V_276 ;
for ( V_15 = V_318 ; V_15 < V_54 ; ++ V_15 )
V_317 [ V_15 ] = NULL ;
V_318 = V_54 ;
}
if ( V_317 [ V_135 ] == NULL ) {
V_317 [ V_135 ] = F_140 ( 0 , 0 ) ;
if ( V_317 [ V_135 ] ) {
if ( F_134 ( V_317 [ V_135 ] ) < 0 )
return NULL ;
}
}
return V_317 [ V_135 ] ;
}
static void F_144 ( struct V_313 * V_314 ,
struct V_122 * V_123 )
{
if ( ! V_305 . V_306 || V_123 -> V_307 == NULL )
return;
F_145 ( & V_314 -> V_304 , & V_299 ) ;
}
static struct V_285 * F_146 ( struct V_106 * V_106 )
{
struct V_285 * V_149 ;
V_149 = F_10 ( sizeof( struct V_285 ) ) ;
if ( ! V_149 )
return NULL ;
F_136 ( & V_149 -> V_302 ) ;
F_96 ( V_106 , V_149 ) ;
return V_149 ;
}
static struct V_285 * F_147 ( struct V_106 * V_106 )
{
struct V_285 * V_286 ;
V_286 = F_93 ( V_106 ) ;
if ( V_286 == NULL ) {
V_286 = F_146 ( V_106 ) ;
if ( V_286 == NULL )
F_52 ( L_102 ) ;
}
return V_286 ;
}
static struct V_106 * F_148 ( struct V_7 * V_8 ,
struct V_122 * V_123 ,
struct V_124 * V_124 ,
struct V_120 * V_121 )
{
struct V_106 * V_106 ;
if ( F_127 ( V_123 , V_121 ) ) {
V_106 = F_143 ( V_123 -> V_135 ) ;
if ( V_106 == NULL )
F_31 ( L_103 , V_123 -> V_135 ) ;
} else {
V_106 = F_54 ( V_124 , V_123 -> V_44 ,
V_123 -> V_126 ? : V_123 -> V_44 ) ;
if ( V_106 == NULL ) {
F_52 ( L_104 ,
V_123 -> V_126 ) ;
}
F_129 ( V_8 , V_123 , V_121 , V_124 ) ;
if ( V_8 -> V_319 ) {
struct V_106 * V_320 ;
struct V_313 * V_314 ;
V_320 = F_143 ( V_123 -> V_135 ) ;
if ( V_320 == NULL ) {
F_31 ( L_103 , V_123 -> V_135 ) ;
return NULL ;
}
V_314 = F_93 ( V_320 ) ;
if ( V_314 == NULL )
return NULL ;
V_314 -> V_321 = V_106 ;
if ( F_50 ( V_121 , V_123 , L_27 ) == 0 )
F_144 ( V_314 , V_123 ) ;
}
}
return V_106 ;
}
static bool F_149 ( struct V_7 * V_8 ,
struct V_106 * V_106 ,
struct V_120 * V_121 ,
struct V_122 * V_123 )
{
bool V_259 = false ;
if ( F_150 ( V_106 ) ) {
V_259 = true ;
V_8 -> V_322 ++ ;
}
if ( V_8 -> V_319 ) {
if ( strcmp ( F_128 ( V_121 ) , L_61 ) )
V_259 = true ;
else if ( F_50 ( V_121 , V_123 , L_26 ) != 0 &&
F_50 ( V_121 , V_123 , L_27 ) != 0 )
V_259 = true ;
}
return V_259 ;
}
static void F_151 ( struct V_7 * V_8 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 ,
struct V_106 * V_323 )
{
struct V_106 * V_106 ;
char V_288 [ 64 ] ;
V_106 = F_54 ( V_124 , V_123 -> V_44 , V_123 -> V_126 ) ;
if ( V_106 == NULL )
return;
if ( F_149 ( V_8 , V_106 , V_121 , V_123 ) &&
F_149 ( V_8 , V_323 , V_121 , V_123 ) ) {
return;
}
F_79 ( V_123 -> time , V_288 , sizeof( V_288 ) ) ;
printf ( L_91 , V_288 , V_123 -> V_135 ) ;
if ( V_8 -> V_280 )
printf ( L_84 , V_8 -> V_226 + 1 , L_83 ) ;
printf ( L_93 , V_278 , F_120 ( V_106 ) ) ;
printf ( L_105 , L_83 , L_83 , L_83 ) ;
printf ( L_106 , F_120 ( V_323 ) ) ;
printf ( L_15 ) ;
}
static int F_152 ( struct V_210 * V_211 ,
union V_138 * V_22 V_42 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
struct V_106 * V_106 ;
struct V_285 * V_286 = NULL ;
const T_5 V_44 = F_50 ( V_121 , V_123 , L_20 ) ;
V_106 = F_54 ( V_124 , 0 , V_44 ) ;
if ( V_106 == NULL )
return - 1 ;
V_286 = F_147 ( V_106 ) ;
if ( V_286 == NULL )
return - 1 ;
if ( V_286 -> V_301 == 0 )
V_286 -> V_301 = V_123 -> time ;
if ( V_8 -> V_293 &&
! F_153 ( & V_8 -> V_324 , V_123 -> time ) )
F_151 ( V_8 , V_121 , V_123 , V_124 , V_106 ) ;
return 0 ;
}
static void F_154 ( struct V_7 * V_8 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 ,
struct V_106 * V_325 )
{
struct V_106 * V_106 ;
char V_288 [ 64 ] ;
T_5 V_287 = V_8 -> V_226 + 1 ;
T_5 V_326 , V_327 ;
if ( V_8 -> V_328 )
return;
V_287 = V_8 -> V_226 + 1 ;
V_326 = F_50 ( V_121 , V_123 , L_107 ) ;
V_327 = F_50 ( V_121 , V_123 , L_108 ) ;
V_106 = F_54 ( V_124 , V_123 -> V_44 , V_123 -> V_126 ) ;
if ( V_106 == NULL )
return;
if ( F_149 ( V_8 , V_106 , V_121 , V_123 ) &&
F_149 ( V_8 , V_325 , V_121 , V_123 ) ) {
return;
}
F_79 ( V_123 -> time , V_288 , sizeof( V_288 ) ) ;
printf ( L_91 , V_288 , V_123 -> V_135 ) ;
if ( V_8 -> V_280 ) {
T_5 V_15 ;
char V_289 ;
printf ( L_54 ) ;
for ( V_15 = 0 ; V_15 < V_287 ; ++ V_15 ) {
V_289 = ( V_15 == V_123 -> V_135 ) ? 'm' : ' ' ;
printf ( L_92 , V_289 ) ;
}
printf ( L_54 ) ;
}
printf ( L_93 , V_278 , F_120 ( V_106 ) ) ;
printf ( L_105 , L_83 , L_83 , L_83 ) ;
printf ( L_109 , F_120 ( V_325 ) ) ;
printf ( L_110 , V_326 , V_327 ) ;
printf ( L_15 ) ;
}
static int F_155 ( struct V_210 * V_211 ,
union V_138 * V_22 V_42 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
struct V_106 * V_106 ;
struct V_285 * V_286 = NULL ;
const T_5 V_44 = F_50 ( V_121 , V_123 , L_20 ) ;
V_106 = F_54 ( V_124 , 0 , V_44 ) ;
if ( V_106 == NULL )
return - 1 ;
V_286 = F_147 ( V_106 ) ;
if ( V_286 == NULL )
return - 1 ;
V_286 -> V_329 ++ ;
F_154 ( V_8 , V_121 , V_123 , V_124 , V_106 ) ;
return 0 ;
}
static int F_156 ( struct V_210 * V_211 ,
union V_138 * V_22 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
struct V_330 * V_324 = & V_8 -> V_324 ;
struct V_282 V_283 ;
struct V_106 * V_106 ;
struct V_285 * V_286 = NULL ;
T_1 V_300 , V_284 = V_123 -> time ;
int V_259 = 0 ;
if ( F_157 ( V_124 , & V_283 , V_123 ) < 0 ) {
F_31 ( L_111 ,
V_22 -> V_260 . type ) ;
V_259 = - 1 ;
goto V_240;
}
V_106 = F_148 ( V_8 , V_123 , V_124 , V_121 ) ;
if ( V_106 == NULL ) {
V_259 = - 1 ;
goto V_240;
}
if ( F_149 ( V_8 , V_106 , V_121 , V_123 ) )
goto V_240;
V_286 = F_147 ( V_106 ) ;
if ( V_286 == NULL ) {
V_259 = - 1 ;
goto V_240;
}
V_300 = F_119 ( V_121 , V_123 -> V_135 ) ;
if ( V_324 -> V_331 && V_324 -> V_331 > V_284 )
goto V_240;
if ( V_300 && V_324 -> V_331 > V_300 )
V_300 = V_324 -> V_331 ;
if ( V_324 -> V_332 ) {
if ( V_300 > V_324 -> V_332 )
goto V_240;
if ( V_284 > V_324 -> V_332 )
V_284 = V_324 -> V_332 ;
}
if ( ! V_8 -> V_319 || V_106 -> V_126 == 0 ) {
F_125 ( V_286 , V_284 , V_300 ) ;
if ( V_8 -> V_319 ) {
struct V_313 * V_314 = ( void * ) V_286 ;
struct V_285 * V_333 ;
F_11 ( V_106 -> V_126 != 0 ) ;
if ( V_314 -> V_321 == NULL )
goto V_240;
V_333 = F_147 ( V_314 -> V_321 ) ;
if ( V_333 == NULL )
goto V_240;
F_125 ( V_333 , V_284 , V_300 ) ;
V_333 -> V_292 = 0 ;
V_333 -> V_290 = 0 ;
V_333 -> V_291 = 0 ;
if ( V_314 -> V_304 . V_26 )
F_158 ( & V_314 -> V_307 , & V_314 -> V_304 , V_284 - V_300 ) ;
V_314 -> V_321 = NULL ;
}
}
if ( ! V_8 -> V_328 )
F_123 ( V_8 , V_123 , & V_283 , V_106 , V_284 ) ;
V_240:
if ( V_8 -> V_334 . V_331 == 0 && V_284 >= V_324 -> V_331 )
V_8 -> V_334 . V_331 = V_284 ;
if ( V_324 -> V_332 == 0 || V_284 <= V_324 -> V_332 )
V_8 -> V_334 . V_332 = V_284 ;
if ( V_286 ) {
V_286 -> V_274 = V_123 -> time ;
V_286 -> V_301 = 0 ;
}
F_117 ( V_121 , V_123 -> time , V_123 -> V_135 ) ;
return V_259 ;
}
static int F_159 ( struct V_210 * V_211 ,
union V_138 * V_22 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 V_42 )
{
return F_156 ( V_211 , V_22 , V_121 , V_123 , V_124 ) ;
}
static int F_160 ( struct V_210 * V_211 V_42 ,
union V_138 * V_22 ,
struct V_122 * V_123 ,
struct V_124 * V_124 V_42 )
{
char V_288 [ 64 ] ;
F_79 ( V_123 -> time , V_288 , sizeof( V_288 ) ) ;
printf ( L_112 , V_288 ) ;
printf ( L_113 V_16 L_114 , V_22 -> V_335 . V_335 , V_123 -> V_135 ) ;
return 0 ;
}
static void F_161 ( struct V_106 * V_284 ,
struct V_285 * V_149 )
{
double V_336 = F_162 ( & V_149 -> V_302 ) ;
float V_337 ;
printf ( L_115 V_16 L_48 ,
V_278 , F_120 ( V_284 ) , V_284 -> V_142 ,
( T_1 ) V_149 -> V_302 . V_275 ) ;
F_115 ( V_149 -> V_303 , 8 ) ;
V_337 = F_163 ( F_164 ( & V_149 -> V_302 ) , V_336 ) ;
F_115 ( V_149 -> V_302 . F_7 , 6 ) ;
printf ( L_48 ) ;
F_115 ( ( T_1 ) V_336 , 6 ) ;
printf ( L_48 ) ;
F_115 ( V_149 -> V_302 . F_43 , 6 ) ;
printf ( L_54 ) ;
printf ( L_116 , V_337 ) ;
printf ( L_117 V_16 , V_149 -> V_329 ) ;
printf ( L_15 ) ;
}
static int F_165 ( struct V_106 * V_284 , void * V_215 )
{
struct V_338 * V_264 = V_215 ;
struct V_285 * V_149 ;
if ( F_150 ( V_284 ) )
return 0 ;
V_149 = F_93 ( V_284 ) ;
if ( V_149 && V_149 -> V_302 . V_275 ) {
V_264 -> V_339 ++ ;
V_264 -> V_340 += V_149 -> V_302 . V_275 ;
V_264 -> V_303 += V_149 -> V_303 ;
F_161 ( V_284 , V_149 ) ;
}
return 0 ;
}
static int F_166 ( struct V_106 * V_284 , void * V_215 )
{
if ( V_284 -> V_341 )
return 0 ;
return F_165 ( V_284 , V_215 ) ;
}
static int F_167 ( struct V_106 * V_284 , void * V_215 )
{
if ( ! V_284 -> V_341 )
return 0 ;
return F_165 ( V_284 , V_215 ) ;
}
static T_2 F_168 ( T_9 * V_342 , struct V_343 * V_157 )
{
const char * V_344 = L_118 ;
struct V_345 * V_346 ;
T_2 V_56 = 0 ;
char V_347 [ 1024 ] ;
bool V_348 ;
if ( V_157 == NULL )
return 0 ;
V_56 = F_168 ( V_342 , V_157 -> V_140 ) ;
V_348 = ( V_56 == 0 ) ;
F_59 (chain, &node->val, list) {
if ( V_346 -> V_349 >= V_350 )
continue;
if ( V_346 -> V_351 . V_311 && V_346 -> V_351 . V_311 -> V_312 )
continue;
V_56 += fprintf ( V_342 , L_119 , V_348 ? L_83 : V_344 ,
F_169 ( V_346 , V_347 , sizeof( V_347 ) ,
false ) ) ;
V_348 = false ;
}
return V_56 ;
}
static T_2 F_170 ( struct V_153 * V_154 )
{
T_2 V_56 = 0 ;
T_9 * V_342 = stdout ;
struct V_343 * V_346 ;
struct V_156 * V_156 = F_88 ( V_154 ) ;
printf ( L_120 , L_121 , L_122 , L_123 ) ;
printf ( L_124 , V_281 , V_281 ,
V_281 ) ;
while ( V_156 ) {
V_346 = F_90 ( V_156 , struct V_343 , V_156 ) ;
V_156 = F_171 ( V_156 ) ;
V_56 += fprintf ( V_342 , L_54 ) ;
F_115 ( V_346 -> V_352 , 12 ) ;
V_56 += 16 ;
V_56 += fprintf ( V_342 , L_125 , V_346 -> V_353 ) ;
V_56 += F_168 ( V_342 , V_346 ) ;
V_56 += fprintf ( V_342 , L_15 ) ;
}
return V_56 ;
}
static void F_172 ( struct V_7 * V_8 ,
struct V_251 * V_252 )
{
struct V_124 * V_354 = & V_252 -> V_355 . V_356 ;
struct V_338 V_357 ;
T_1 V_339 ;
struct V_106 * V_284 ;
struct V_285 * V_149 ;
int V_15 ;
T_1 V_334 = V_8 -> V_334 . V_332 - V_8 -> V_334 . V_331 ;
memset ( & V_357 , 0 , sizeof( V_357 ) ) ;
if ( V_8 -> V_319 ) {
printf ( L_126 ) ;
printf ( L_127 , V_278 , L_19 ) ;
printf ( L_128 ) ;
} else {
printf ( L_129 ) ;
printf ( L_130 , V_278 , L_19 ) ;
printf ( L_131 ) ;
}
printf ( L_132 , V_278 , L_83 ) ;
printf ( L_133 ) ;
printf ( L_134 , V_281 ) ;
F_173 ( V_354 , F_166 , & V_357 ) ;
V_339 = V_357 . V_339 ;
if ( ! V_339 )
printf ( L_135 ) ;
printf ( L_136 ) ;
F_173 ( V_354 , F_167 , & V_357 ) ;
if ( V_339 == V_357 . V_339 )
printf ( L_137 ) ;
if ( V_8 -> V_322 && ! V_8 -> V_319 )
return;
printf ( L_138 ) ;
for ( V_15 = 0 ; V_15 < V_318 ; ++ V_15 ) {
V_284 = V_317 [ V_15 ] ;
if ( ! V_284 )
continue;
V_149 = F_93 ( V_284 ) ;
if ( V_149 && V_149 -> V_302 . V_275 ) {
V_357 . V_340 += V_149 -> V_302 . V_275 ;
printf ( L_139 , V_15 ) ;
F_115 ( V_149 -> V_303 , 6 ) ;
printf ( L_140 , 100.0 * V_149 -> V_303 / V_334 ) ;
} else
printf ( L_141 , V_15 ) ;
}
if ( V_8 -> V_319 && V_305 . V_306 ) {
V_358 . V_257 = V_359 ;
V_358 . V_360 = V_361 ;
F_174 ( & V_358 ) ;
printf ( L_142 ) ;
for ( V_15 = 0 ; V_15 < V_318 ; ++ V_15 ) {
struct V_313 * V_314 ;
V_284 = V_317 [ V_15 ] ;
if ( ! V_284 )
continue;
V_314 = F_93 ( V_284 ) ;
if ( V_314 == NULL )
continue;
V_358 . V_151 ( & V_314 -> V_362 , & V_314 -> V_307 ,
0 , & V_358 ) ;
printf ( L_143 , V_15 ) ;
F_115 ( V_314 -> V_286 . V_303 , 6 ) ;
printf ( L_144 ) ;
F_170 ( & V_314 -> V_362 ) ;
printf ( L_15 ) ;
}
}
printf ( L_15
L_145 V_16 L_15
L_146 V_16 L_15 ,
V_357 . V_339 , V_357 . V_340 ) ;
printf ( L_147 ) ;
F_115 ( V_357 . V_303 , 2 ) ;
printf ( L_15 ) ;
printf ( L_148 ) ;
F_115 ( V_334 , 2 ) ;
printf ( L_149 , V_8 -> V_226 ) ;
}
static int F_175 ( struct V_210 * V_211 ,
union V_138 * V_22 ,
struct V_122 * V_123 ,
struct V_120 * V_121 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
int V_61 = 0 ;
int V_221 = V_123 -> V_135 ;
if ( V_221 > V_8 -> V_226 )
V_8 -> V_226 = V_221 ;
if ( V_121 -> V_247 != NULL ) {
T_10 V_248 = V_121 -> V_247 ;
V_61 = V_248 ( V_211 , V_22 , V_121 , V_123 , V_124 ) ;
}
return V_61 ;
}
static int F_176 ( struct V_7 * V_8 ,
struct V_363 * V_263 )
{
struct V_120 * V_121 ;
struct V_272 * V_364 ;
F_59 (evsel, &evlist->entries, node) {
V_364 = F_116 ( V_121 ) ;
if ( V_364 == NULL ) {
F_31 ( L_150 ) ;
return - 1 ;
}
if ( V_8 -> V_294 &&
! ( V_121 -> V_69 . V_365 & V_366 ) ) {
F_177 ( L_151 ) ;
V_8 -> V_294 = 0 ;
V_305 . V_306 = 0 ;
}
}
return 0 ;
}
static int F_178 ( struct V_7 * V_8 )
{
const struct V_249 V_250 [] = {
{ L_61 , F_159 , } ,
{ L_63 , F_152 , } ,
{ L_64 , F_152 , } ,
} ;
const struct V_249 V_367 [] = {
{ L_65 , F_155 , } ,
} ;
struct V_253 V_254 = {
. V_255 = V_256 ,
. V_257 = V_258 ,
. V_83 = V_8 -> V_83 ,
} ;
struct V_251 * V_252 ;
struct V_363 * V_263 ;
int V_61 = - 1 ;
V_8 -> V_211 . V_123 = F_175 ;
V_8 -> V_211 . V_368 = V_369 ;
V_8 -> V_211 . V_45 = V_370 ;
V_8 -> V_211 . exit = V_371 ;
V_8 -> V_211 . V_141 = F_105 ;
V_8 -> V_211 . V_335 = F_160 ;
V_8 -> V_211 . V_69 = V_372 ;
V_8 -> V_211 . V_373 = V_374 ;
V_8 -> V_211 . V_375 = V_376 ;
V_8 -> V_211 . V_377 = true ;
V_8 -> V_211 . V_378 = true ;
V_305 . V_306 = V_8 -> V_294 ;
V_252 = F_109 ( & V_254 , false , & V_8 -> V_211 ) ;
if ( V_252 == NULL )
return - V_316 ;
V_263 = V_252 -> V_263 ;
F_110 ( & V_252 -> V_260 . V_261 ) ;
if ( F_179 ( & V_8 -> V_324 , V_8 -> V_379 ) != 0 ) {
F_31 ( L_152 ) ;
return - V_380 ;
}
if ( F_176 ( V_8 , V_263 ) != 0 )
goto V_240;
F_180 () ;
if ( F_111 ( V_252 , V_250 ) )
goto V_240;
if ( ! F_181 ( V_252 -> V_263 ,
L_61 ) ) {
F_31 ( L_153 ) ;
goto V_240;
}
if ( V_8 -> V_381 &&
F_111 ( V_252 , V_367 ) )
goto V_240;
V_8 -> V_226 = V_252 -> V_260 . V_261 . V_382 ;
if ( V_8 -> V_226 == 0 )
V_8 -> V_226 = 4 ;
if ( F_139 ( V_8 -> V_226 ) )
goto V_240;
if ( V_8 -> V_328 )
V_8 -> V_383 = V_8 -> V_328 ;
if ( ! V_8 -> V_328 )
F_122 ( V_8 ) ;
V_61 = F_113 ( V_252 ) ;
if ( V_61 ) {
F_31 ( L_68 , V_61 ) ;
goto V_240;
}
V_8 -> V_24 = V_263 -> V_264 . V_24 [ 0 ] ;
V_8 -> V_265 = V_263 -> V_264 . V_266 ;
V_8 -> V_267 = V_263 -> V_264 . V_24 [ V_268 ] ;
if ( V_8 -> V_383 )
F_172 ( V_8 , V_252 ) ;
V_240:
F_141 () ;
F_114 ( V_252 ) ;
return V_61 ;
}
static void F_182 ( struct V_7 * V_8 )
{
if ( V_8 -> V_192 && V_8 -> V_191 ) {
printf ( L_154 ,
( double ) V_8 -> V_192 / ( double ) V_8 -> V_191 * 100.0 ,
V_8 -> V_192 , V_8 -> V_191 ) ;
}
if ( V_8 -> V_265 && V_8 -> V_24 ) {
printf ( L_155 ,
( double ) V_8 -> V_265 / ( double ) V_8 -> V_24 * 100.0 ,
V_8 -> V_265 , V_8 -> V_24 , V_8 -> V_267 ) ;
}
if ( V_8 -> V_242 && V_8 -> V_191 ) {
printf ( L_156 ,
( double ) V_8 -> V_242 / ( double ) V_8 -> V_191 * 100.0 ,
V_8 -> V_242 , V_8 -> V_191 ) ;
if ( V_8 -> V_265 )
printf ( L_157 ) ;
printf ( L_15 ) ;
}
}
static void F_183 ( struct V_153 * V_154 , struct V_147 * V_161 )
{
struct V_156 * * V_162 = & ( V_154 -> V_156 ) , * V_140 = NULL ;
struct V_147 * V_163 ;
const char * V_45 = F_55 ( V_161 -> V_106 ) , * V_384 ;
while ( * V_162 ) {
int V_152 ;
V_163 = F_61 ( * V_162 , struct V_147 , V_157 ) ;
V_140 = * V_162 ;
V_384 = F_55 ( V_163 -> V_106 ) ;
V_152 = strcmp ( V_45 , V_384 ) ;
if ( V_152 > 0 ) {
V_162 = & ( ( * V_162 ) -> V_159 ) ;
} else if ( V_152 < 0 ) {
V_162 = & ( ( * V_162 ) -> V_160 ) ;
} else {
V_163 -> V_197 ++ ;
V_163 -> V_176 += V_161 -> V_176 ;
V_163 -> V_183 += V_161 -> V_183 ;
V_163 -> V_180 += V_161 -> V_180 ;
F_184 ( & V_161 -> V_165 , & V_163 -> V_165 ) ;
if ( V_163 -> V_181 < V_161 -> V_181 ) {
V_163 -> V_181 = V_161 -> V_181 ;
V_163 -> V_182 = V_161 -> V_182 ;
}
F_36 ( & V_161 ) ;
return;
}
}
V_161 -> V_197 ++ ;
F_63 ( & V_161 -> V_157 , V_140 , V_162 ) ;
F_64 ( & V_161 -> V_157 , V_154 ) ;
}
static void F_185 ( struct V_7 * V_8 )
{
struct V_147 * V_161 ;
struct V_156 * V_157 ;
if ( V_8 -> V_385 )
return;
while ( ( V_157 = F_88 ( & V_8 -> V_166 ) ) ) {
F_89 ( V_157 , & V_8 -> V_166 ) ;
V_161 = F_90 ( V_157 , struct V_147 , V_157 ) ;
F_183 ( & V_8 -> V_209 , V_161 ) ;
}
}
static int F_186 ( struct V_7 * V_8 )
{
struct V_156 * V_133 ;
F_180 () ;
if ( F_108 ( V_8 ) )
return - 1 ;
F_185 ( V_8 ) ;
F_87 ( V_8 ) ;
printf ( L_158 ) ;
printf ( L_159 ) ;
printf ( L_160 ) ;
V_133 = F_88 ( & V_8 -> V_208 ) ;
while ( V_133 ) {
struct V_147 * V_165 ;
V_165 = F_90 ( V_133 , struct V_147 , V_157 ) ;
F_78 ( V_8 , V_165 ) ;
V_133 = F_171 ( V_133 ) ;
F_187 ( V_165 -> V_106 ) ;
}
printf ( L_160 ) ;
printf ( L_161 V_16 L_162 ,
( double ) V_8 -> V_195 / V_118 , V_8 -> V_196 ) ;
printf ( L_163 ) ;
F_182 ( V_8 ) ;
printf ( L_15 ) ;
return 0 ;
}
static int F_188 ( struct V_7 * V_8 )
{
struct V_386 * V_218 ;
V_8 -> V_226 = F_189 ( V_387 ) ;
if ( V_8 -> V_218 . V_227 ) {
V_8 -> V_218 . V_229 = F_10 ( V_8 -> V_226 * sizeof( int ) ) ;
if ( ! V_8 -> V_218 . V_229 )
return - 1 ;
}
if ( ! V_8 -> V_218 . V_388 )
return 0 ;
V_218 = F_190 ( V_8 -> V_218 . V_388 ) ;
if ( ! V_218 ) {
F_31 ( L_164 , V_8 -> V_218 . V_388 ) ;
return - 1 ;
}
V_8 -> V_218 . V_237 = V_218 ;
return 0 ;
}
static int F_191 ( struct V_7 * V_8 )
{
struct V_389 * V_218 ;
if ( ! V_8 -> V_218 . V_390 )
return 0 ;
V_218 = F_192 ( V_8 -> V_218 . V_390 ) ;
if ( ! V_218 ) {
F_31 ( L_165 , V_8 -> V_218 . V_390 ) ;
return - 1 ;
}
V_8 -> V_218 . V_219 = V_218 ;
return 0 ;
}
static int F_193 ( struct V_7 * V_8 )
{
struct V_386 * V_218 ;
if ( ! V_8 -> V_218 . V_391 )
return 0 ;
V_218 = F_190 ( V_8 -> V_218 . V_391 ) ;
if ( ! V_218 ) {
F_31 ( L_165 , V_8 -> V_218 . V_391 ) ;
return - 1 ;
}
V_8 -> V_218 . V_238 = V_218 ;
return 0 ;
}
static int F_194 ( struct V_7 * V_8 )
{
if ( F_188 ( V_8 ) )
return - 1 ;
if ( F_191 ( V_8 ) )
return - 1 ;
if ( F_193 ( V_8 ) )
return - 1 ;
F_180 () ;
if ( F_108 ( V_8 ) )
return - 1 ;
F_182 ( V_8 ) ;
return 0 ;
}
static int F_195 ( struct V_7 * V_8 )
{
unsigned long V_15 ;
F_6 ( V_8 ) ;
F_8 ( V_8 ) ;
F_47 ( V_8 ) ;
if ( F_108 ( V_8 ) )
return - 1 ;
printf ( L_166 , V_8 -> V_32 ) ;
printf ( L_167 , V_8 -> V_43 ) ;
printf ( L_168 , V_8 -> V_41 ) ;
if ( V_8 -> V_37 )
printf ( L_169 , V_8 -> V_37 ) ;
if ( V_8 -> V_39 )
printf ( L_170 , V_8 -> V_39 ) ;
if ( V_8 -> V_31 )
printf ( L_171 ,
V_8 -> V_31 ) ;
F_19 ( V_8 ) ;
F_20 ( V_8 ) ;
F_40 ( V_8 ) ;
printf ( L_172 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_109 ; V_15 ++ )
F_46 ( V_8 ) ;
return 0 ;
}
static void F_196 ( struct V_7 * V_8 , const struct V_392 * V_393 ,
const char * const V_394 [] )
{
char * V_395 , * V_200 , * V_168 = F_197 ( V_8 -> V_396 ) ;
for ( V_200 = strtok_r ( V_168 , L_173 , & V_395 ) ;
V_200 ; V_200 = strtok_r ( NULL , L_173 , & V_395 ) ) {
if ( F_85 ( V_200 , & V_8 -> V_155 ) < 0 ) {
F_198 ( V_394 , V_393 ,
L_174 , V_200 ) ;
}
}
free ( V_168 ) ;
F_85 ( L_20 , & V_8 -> V_167 ) ;
}
static int F_199 ( int V_397 , const char * * V_398 )
{
unsigned int V_399 , V_15 , V_54 ;
const char * * V_400 ;
const char * const V_401 [] = {
L_175 ,
L_176 ,
L_177 ,
L_178 , L_179 ,
L_180 , L_181 ,
L_182 , L_61 ,
L_182 , L_183 ,
L_182 , L_184 ,
L_182 , L_185 ,
L_182 , L_62 ,
L_182 , L_186 ,
L_182 , L_63 ,
L_182 , L_64 ,
L_182 , L_65 ,
} ;
V_399 = F_86 ( V_401 ) + V_397 - 1 ;
V_400 = calloc ( V_399 + 1 , sizeof( char * ) ) ;
if ( V_400 == NULL )
return - V_316 ;
for ( V_15 = 0 ; V_15 < F_86 ( V_401 ) ; V_15 ++ )
V_400 [ V_15 ] = F_197 ( V_401 [ V_15 ] ) ;
for ( V_54 = 1 ; V_54 < ( unsigned int ) V_397 ; V_54 ++ , V_15 ++ )
V_400 [ V_15 ] = V_398 [ V_54 ] ;
F_11 ( V_15 != V_399 ) ;
return F_200 ( V_15 , V_400 , NULL ) ;
}
int F_201 ( int V_397 , const char * * V_398 , const char * T_11 V_42 )
{
const char V_402 [] = L_187 ;
struct V_7 V_8 = {
. V_211 = {
. V_123 = F_107 ,
. V_45 = V_370 ,
. V_335 = V_403 ,
. V_141 = F_104 ,
. V_377 = true ,
} ,
. V_167 = F_202 ( V_8 . V_167 ) ,
. V_155 = F_202 ( V_8 . V_155 ) ,
. V_100 = V_404 ,
. V_103 = V_404 ,
. V_396 = V_402 ,
. V_109 = 10 ,
. V_188 = - 1 ,
. V_232 = 'A' ,
. V_233 = '0' ,
. V_385 = 0 ,
. V_294 = 1 ,
. V_308 = 5 ,
} ;
const struct V_392 V_405 [] = {
F_203 ( 'i' , L_188 , & V_256 , L_189 ,
L_190 ) ,
F_204 ( 'v' , L_191 , & V_51 ,
L_192 ) ,
F_205 ( 'D' , L_193 , & V_406 ,
L_194 ) ,
F_205 ( 'f' , L_195 , & V_8 . V_83 , L_196 ) ,
F_206 ()
} ;
const struct V_392 V_407 [] = {
F_203 ( 's' , L_197 , & V_8 . V_396 , L_198 ,
L_199 ) ,
F_207 ( 'C' , L_200 , & V_8 . V_188 ,
L_201 ) ,
F_205 ( 'p' , L_202 , & V_8 . V_385 ,
L_203 ) ,
F_208 (sched_options)
} ;
const struct V_392 V_408 [] = {
F_209 ( 'r' , L_204 , & V_8 . V_109 ,
L_205 ) ,
F_208 (sched_options)
} ;
const struct V_392 V_409 [] = {
F_205 ( 0 , L_206 , & V_8 . V_218 . V_227 ,
L_207 ) ,
F_203 ( 0 , L_208 , & V_8 . V_218 . V_390 , L_202 ,
L_209 ) ,
F_203 ( 0 , L_210 , & V_8 . V_218 . V_391 , L_211 ,
L_212 ) ,
F_203 ( 0 , L_211 , & V_8 . V_218 . V_388 , L_211 ,
L_213 ) ,
F_208 (sched_options)
} ;
const struct V_392 V_410 [] = {
F_203 ( 'k' , L_214 , & V_305 . V_411 ,
L_189 , L_215 ) ,
F_203 ( 0 , L_216 , & V_305 . V_412 ,
L_189 , L_217 ) ,
F_205 ( 'g' , L_218 , & V_8 . V_294 ,
L_219 ) ,
F_209 ( 0 , L_220 , & V_8 . V_308 ,
L_221 ) ,
F_203 ( 0 , L_222 , & V_305 . V_413 , L_223 ,
L_224 ) ,
F_205 ( 's' , L_225 , & V_8 . V_328 ,
L_226 ) ,
F_205 ( 'S' , L_227 , & V_8 . V_383 ,
L_228 ) ,
F_205 ( 'w' , L_229 , & V_8 . V_293 , L_230 ) ,
F_205 ( 'M' , L_231 , & V_8 . V_381 , L_232 ) ,
F_205 ( 'V' , L_233 , & V_8 . V_280 , L_234 ) ,
F_205 ( 'I' , L_235 , & V_8 . V_319 , L_236 ) ,
F_203 ( 0 , L_74 , & V_8 . V_379 , L_237 ,
L_238 ) ,
F_208 (sched_options)
} ;
const char * const V_414 [] = {
L_239 ,
NULL
} ;
const char * const V_415 [] = {
L_240 ,
NULL
} ;
const char * const V_416 [] = {
L_241 ,
NULL
} ;
const char * const V_417 [] = {
L_242 ,
NULL
} ;
const char * const V_418 [] = { L_175 , L_243 , L_244 ,
L_245 , L_246 ,
L_247 , NULL } ;
const char * V_419 [] = {
NULL ,
NULL
} ;
struct V_420 V_421 = {
. V_213 = F_76 ,
. V_243 = F_74 ,
. V_244 = F_75 ,
. V_246 = F_77 ,
} ;
struct V_420 V_422 = {
. V_243 = F_97 ,
} ;
struct V_420 V_423 = {
. V_213 = F_48 ,
. V_243 = F_51 ,
. V_245 = F_53 ,
} ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < F_86 ( V_8 . V_241 ) ; V_15 ++ )
V_8 . V_241 [ V_15 ] = - 1 ;
V_397 = F_210 ( V_397 , V_398 , V_405 , V_418 ,
V_419 , V_424 ) ;
if ( ! V_397 )
F_211 ( V_419 , V_405 ) ;
if ( ! strcmp ( V_398 [ 0 ] , L_246 ) )
return F_212 ( V_397 , V_398 , T_11 ) ;
if ( ! strncmp ( V_398 [ 0 ] , L_248 , 3 ) ) {
return F_199 ( V_397 , V_398 ) ;
} else if ( ! strncmp ( V_398 [ 0 ] , L_249 , 3 ) ) {
V_8 . V_212 = & V_421 ;
if ( V_397 > 1 ) {
V_397 = F_213 ( V_397 , V_398 , V_407 , V_414 , 0 ) ;
if ( V_397 )
F_211 ( V_414 , V_407 ) ;
}
F_196 ( & V_8 , V_407 , V_414 ) ;
return F_186 ( & V_8 ) ;
} else if ( ! strcmp ( V_398 [ 0 ] , L_244 ) ) {
if ( V_397 ) {
V_397 = F_213 ( V_397 , V_398 , V_409 , V_416 , 0 ) ;
if ( V_397 )
F_211 ( V_416 , V_409 ) ;
}
V_8 . V_212 = & V_422 ;
F_196 ( & V_8 , V_407 , V_414 ) ;
return F_194 ( & V_8 ) ;
} else if ( ! strncmp ( V_398 [ 0 ] , L_250 , 3 ) ) {
V_8 . V_212 = & V_423 ;
if ( V_397 ) {
V_397 = F_213 ( V_397 , V_398 , V_408 , V_415 , 0 ) ;
if ( V_397 )
F_211 ( V_415 , V_408 ) ;
}
return F_195 ( & V_8 ) ;
} else if ( ! strcmp ( V_398 [ 0 ] , L_247 ) ) {
if ( V_397 ) {
V_397 = F_213 ( V_397 , V_398 , V_410 ,
V_417 , 0 ) ;
if ( V_397 )
F_211 ( V_417 , V_410 ) ;
}
if ( V_8 . V_293 && V_8 . V_328 ) {
F_31 ( L_251 ) ;
F_214 ( V_417 , V_410 , L_252 , true ) ;
F_214 ( NULL , V_410 , L_253 , true ) ;
return - V_380 ;
}
return F_178 ( & V_8 ) ;
} else {
F_211 ( V_419 , V_405 ) ;
}
return 0 ;
}
