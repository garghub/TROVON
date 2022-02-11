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
printf ( L_49 V_16 L_50 ,
( double ) V_165 -> V_176 / V_118 ,
V_165 -> V_183 , ( double ) V_194 / V_118 ,
( double ) V_165 -> V_181 / V_118 ,
( double ) V_165 -> V_182 / V_5 ) ;
}
static int F_79 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_106 == V_149 -> V_106 )
return 0 ;
if ( V_148 -> V_106 -> V_126 < V_149 -> V_106 -> V_126 )
return - 1 ;
if ( V_148 -> V_106 -> V_126 > V_149 -> V_106 -> V_126 )
return 1 ;
return ( int ) ( V_148 -> V_106 - V_149 -> V_106 ) ;
}
static int F_80 ( struct V_147 * V_148 , struct V_147 * V_149 )
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
static int F_81 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_181 < V_149 -> V_181 )
return - 1 ;
if ( V_148 -> V_181 > V_149 -> V_181 )
return 1 ;
return 0 ;
}
static int F_82 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_183 < V_149 -> V_183 )
return - 1 ;
if ( V_148 -> V_183 > V_149 -> V_183 )
return 1 ;
return 0 ;
}
static int F_83 ( struct V_147 * V_148 , struct V_147 * V_149 )
{
if ( V_148 -> V_176 < V_149 -> V_176 )
return - 1 ;
if ( V_148 -> V_176 > V_149 -> V_176 )
return 1 ;
return 0 ;
}
static int F_84 ( const char * V_200 , struct V_145 * V_146 )
{
T_2 V_15 ;
static struct V_150 V_201 = {
. V_202 = L_51 ,
. V_152 = F_80 ,
} ;
static struct V_150 V_203 = {
. V_202 = L_52 ,
. V_152 = F_81 ,
} ;
static struct V_150 V_204 = {
. V_202 = L_20 ,
. V_152 = F_79 ,
} ;
static struct V_150 V_205 = {
. V_202 = L_42 ,
. V_152 = F_83 ,
} ;
static struct V_150 V_206 = {
. V_202 = L_53 ,
. V_152 = F_82 ,
} ;
struct V_150 * V_207 [] = {
& V_204 ,
& V_201 ,
& V_203 ,
& V_206 ,
& V_205 ,
} ;
for ( V_15 = 0 ; V_15 < F_85 ( V_207 ) ; V_15 ++ ) {
if ( ! strcmp ( V_207 [ V_15 ] -> V_202 , V_200 ) ) {
F_70 ( & V_207 [ V_15 ] -> V_146 , V_146 ) ;
return 0 ;
}
}
return - 1 ;
}
static void F_86 ( struct V_7 * V_8 )
{
struct V_156 * V_157 ;
struct V_153 * V_154 = & V_8 -> V_166 ;
V_98:
for (; ; ) {
struct V_147 * V_161 ;
V_157 = F_87 ( V_154 ) ;
if ( ! V_157 )
break;
F_88 ( V_157 , V_154 ) ;
V_161 = F_89 ( V_157 , struct V_147 , V_157 ) ;
F_62 ( & V_8 -> V_208 , V_161 , & V_8 -> V_155 ) ;
}
if ( V_154 == & V_8 -> V_166 ) {
V_154 = & V_8 -> V_209 ;
goto V_98;
}
}
static int F_90 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
if ( V_8 -> V_212 -> V_213 )
return V_8 -> V_212 -> V_213 ( V_8 , V_121 , V_123 , V_124 ) ;
return 0 ;
}
static bool F_91 ( struct V_106 * V_106 )
{
union V_214 V_215 = {
. V_216 = F_92 ( V_106 ) ,
} ;
return V_215 . V_217 ;
}
static struct V_106 *
F_93 ( struct V_7 * V_8 , struct V_124 * V_124 , T_7 V_44 , T_7 V_126 )
{
struct V_106 * V_106 = F_54 ( V_124 , V_44 , V_126 ) ;
union V_214 V_215 = {
. V_217 = false ,
} ;
if ( ! V_8 -> V_218 . V_219 || ! V_106 || F_92 ( V_106 ) )
return V_106 ;
if ( F_94 ( V_8 -> V_218 . V_219 , V_126 ) )
V_215 . V_217 = true ;
F_95 ( V_106 , V_215 . V_216 ) ;
return V_106 ;
}
static int F_96 ( struct V_7 * V_8 , struct V_120 * V_121 ,
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
F_11 ( V_221 >= V_136 || V_221 < 0 ) ;
if ( V_221 > V_8 -> V_225 )
V_8 -> V_225 = V_221 ;
if ( V_8 -> V_218 . V_226 ) {
V_222 = F_97 ( V_8 -> V_218 . V_227 , V_136 ) ;
if ( ! F_98 ( V_221 , V_8 -> V_218 . V_227 ) ) {
V_8 -> V_218 . V_228 [ V_222 ++ ] = V_221 ;
V_223 = true ;
}
} else
V_222 = V_8 -> V_225 ;
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
V_187 = F_93 ( V_8 , V_124 , - 1 , V_130 ) ;
if ( V_187 == NULL )
return - 1 ;
V_8 -> V_229 [ V_221 ] = F_66 ( V_187 ) ;
printf ( L_54 ) ;
V_220 = 0 ;
if ( ! V_187 -> V_230 [ 0 ] ) {
if ( ! strcmp ( F_55 ( V_187 ) , L_45 ) ) {
V_187 -> V_230 [ 0 ] = '.' ;
V_187 -> V_230 [ 1 ] = ' ' ;
} else {
V_187 -> V_230 [ 0 ] = V_8 -> V_231 ;
V_187 -> V_230 [ 1 ] = V_8 -> V_232 ;
if ( V_8 -> V_231 < 'Z' ) {
V_8 -> V_231 ++ ;
} else {
V_8 -> V_231 = 'A' ;
if ( V_8 -> V_232 < '9' )
V_8 -> V_232 ++ ;
else
V_8 -> V_232 = '0' ;
}
}
V_220 = 1 ;
}
for ( V_15 = 0 ; V_15 < V_222 ; V_15 ++ ) {
int V_135 = V_8 -> V_218 . V_226 ? V_8 -> V_218 . V_228 [ V_15 ] : V_15 ;
struct V_106 * V_229 = V_8 -> V_229 [ V_135 ] ;
const char * V_233 = V_217 ;
const char * V_234 = V_217 ;
if ( V_229 && F_91 ( V_229 ) )
V_233 = V_235 ;
if ( V_8 -> V_218 . V_236 && ! F_99 ( V_8 -> V_218 . V_236 , V_135 ) )
continue;
if ( V_8 -> V_218 . V_237 && F_99 ( V_8 -> V_218 . V_237 , V_135 ) )
V_234 = V_238 ;
if ( V_135 != V_221 )
F_100 ( stdout , V_234 , L_48 ) ;
else
F_100 ( stdout , V_234 , L_55 ) ;
if ( V_8 -> V_229 [ V_135 ] )
F_100 ( stdout , V_233 , L_56 , V_8 -> V_229 [ V_135 ] -> V_230 ) ;
else
F_100 ( stdout , V_217 , L_57 ) ;
}
if ( V_8 -> V_218 . V_236 && ! F_99 ( V_8 -> V_218 . V_236 , V_221 ) )
goto V_239;
F_100 ( stdout , V_217 , L_58 , ( double ) V_21 / V_5 ) ;
if ( V_220 ) {
const char * V_233 = V_217 ;
if ( F_91 ( V_187 ) )
V_233 = V_235 ;
F_100 ( stdout , V_233 , L_59 ,
V_187 -> V_230 , F_55 ( V_187 ) , V_187 -> V_126 ) ;
}
if ( V_8 -> V_218 . V_226 && V_223 )
F_100 ( stdout , V_217 , L_60 , V_221 ) ;
V_239:
F_100 ( stdout , V_217 , L_15 ) ;
F_56 ( V_187 ) ;
return 0 ;
}
static int F_101 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
int V_221 = V_123 -> V_135 , V_61 = 0 ;
T_5 V_129 = F_50 ( V_121 , V_123 , L_26 ) ,
V_130 = F_50 ( V_121 , V_123 , L_27 ) ;
if ( V_8 -> V_240 [ V_221 ] != ( T_5 ) - 1 ) {
if ( V_8 -> V_240 [ V_221 ] != V_129 )
V_8 -> V_241 ++ ;
}
if ( V_8 -> V_212 -> V_242 )
V_61 = V_8 -> V_212 -> V_242 ( V_8 , V_121 , V_123 , V_124 ) ;
V_8 -> V_240 [ V_221 ] = V_130 ;
return V_61 ;
}
static int F_102 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
if ( V_8 -> V_212 -> V_243 )
return V_8 -> V_212 -> V_243 ( V_8 , V_121 , V_123 , V_124 ) ;
return 0 ;
}
static int F_103 ( struct V_210 * V_211 ,
union V_138 * V_22 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
F_104 ( V_211 , V_22 , V_123 , V_124 ) ;
if ( V_8 -> V_212 -> V_244 )
return V_8 -> V_212 -> V_244 ( V_8 , V_22 , V_124 ) ;
return 0 ;
}
static int F_105 ( struct V_210 * V_211 ,
struct V_120 * V_121 ,
struct V_122 * V_123 ,
struct V_124 * V_124 )
{
struct V_7 * V_8 = F_61 ( V_211 , struct V_7 , V_211 ) ;
if ( V_8 -> V_212 -> V_245 )
return V_8 -> V_212 -> V_245 ( V_8 , V_121 , V_123 , V_124 ) ;
return 0 ;
}
static int F_106 ( struct V_210 * V_211 V_42 ,
union V_138 * V_22 V_42 ,
struct V_122 * V_123 ,
struct V_120 * V_121 ,
struct V_124 * V_124 )
{
int V_61 = 0 ;
if ( V_121 -> V_246 != NULL ) {
T_8 V_247 = V_121 -> V_246 ;
V_61 = V_247 ( V_211 , V_121 , V_123 , V_124 ) ;
}
return V_61 ;
}
static int F_107 ( struct V_7 * V_8 )
{
const struct V_248 V_249 [] = {
{ L_61 , F_101 , } ,
{ L_62 , F_102 , } ,
{ L_63 , F_90 , } ,
{ L_64 , F_90 , } ,
{ L_65 , F_105 , } ,
} ;
struct V_250 * V_251 ;
struct V_252 V_253 = {
. V_254 = V_255 ,
. V_256 = V_257 ,
. V_83 = V_8 -> V_83 ,
} ;
int V_258 = - 1 ;
V_251 = F_108 ( & V_253 , false , & V_8 -> V_211 ) ;
if ( V_251 == NULL ) {
F_52 ( L_66 ) ;
return - 1 ;
}
F_109 ( & V_251 -> V_259 . V_260 ) ;
if ( F_110 ( V_251 , V_249 ) )
goto V_261;
if ( F_111 ( V_251 , L_67 ) ) {
int V_61 = F_112 ( V_251 ) ;
if ( V_61 ) {
F_31 ( L_68 , V_61 ) ;
goto V_261;
}
V_8 -> V_24 = V_251 -> V_262 -> V_263 . V_24 [ 0 ] ;
V_8 -> V_264 = V_251 -> V_262 -> V_263 . V_265 ;
V_8 -> V_266 = V_251 -> V_262 -> V_263 . V_24 [ V_267 ] ;
}
V_258 = 0 ;
V_261:
F_113 ( V_251 ) ;
return V_258 ;
}
static void F_114 ( struct V_7 * V_8 )
{
if ( V_8 -> V_192 && V_8 -> V_191 ) {
printf ( L_69 ,
( double ) V_8 -> V_192 / ( double ) V_8 -> V_191 * 100.0 ,
V_8 -> V_192 , V_8 -> V_191 ) ;
}
if ( V_8 -> V_264 && V_8 -> V_24 ) {
printf ( L_70 ,
( double ) V_8 -> V_264 / ( double ) V_8 -> V_24 * 100.0 ,
V_8 -> V_264 , V_8 -> V_24 , V_8 -> V_266 ) ;
}
if ( V_8 -> V_241 && V_8 -> V_191 ) {
printf ( L_71 ,
( double ) V_8 -> V_241 / ( double ) V_8 -> V_191 * 100.0 ,
V_8 -> V_241 , V_8 -> V_191 ) ;
if ( V_8 -> V_264 )
printf ( L_72 ) ;
printf ( L_15 ) ;
}
}
static void F_115 ( struct V_153 * V_154 , struct V_147 * V_161 )
{
struct V_156 * * V_162 = & ( V_154 -> V_156 ) , * V_140 = NULL ;
struct V_147 * V_163 ;
const char * V_45 = F_55 ( V_161 -> V_106 ) , * V_268 ;
while ( * V_162 ) {
int V_152 ;
V_163 = F_61 ( * V_162 , struct V_147 , V_157 ) ;
V_140 = * V_162 ;
V_268 = F_55 ( V_163 -> V_106 ) ;
V_152 = strcmp ( V_45 , V_268 ) ;
if ( V_152 > 0 ) {
V_162 = & ( ( * V_162 ) -> V_159 ) ;
} else if ( V_152 < 0 ) {
V_162 = & ( ( * V_162 ) -> V_160 ) ;
} else {
V_163 -> V_197 ++ ;
V_163 -> V_176 += V_161 -> V_176 ;
V_163 -> V_183 += V_161 -> V_183 ;
V_163 -> V_180 += V_161 -> V_180 ;
F_116 ( & V_161 -> V_165 , & V_163 -> V_165 ) ;
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
static void F_117 ( struct V_7 * V_8 )
{
struct V_147 * V_161 ;
struct V_156 * V_157 ;
if ( V_8 -> V_269 )
return;
while ( ( V_157 = F_87 ( & V_8 -> V_166 ) ) ) {
F_88 ( V_157 , & V_8 -> V_166 ) ;
V_161 = F_89 ( V_157 , struct V_147 , V_157 ) ;
F_115 ( & V_8 -> V_209 , V_161 ) ;
}
}
static int F_118 ( struct V_7 * V_8 )
{
struct V_156 * V_133 ;
F_119 () ;
if ( F_107 ( V_8 ) )
return - 1 ;
F_117 ( V_8 ) ;
F_86 ( V_8 ) ;
printf ( L_73 ) ;
printf ( L_74 ) ;
printf ( L_75 ) ;
V_133 = F_87 ( & V_8 -> V_208 ) ;
while ( V_133 ) {
struct V_147 * V_165 ;
V_165 = F_89 ( V_133 , struct V_147 , V_157 ) ;
F_78 ( V_8 , V_165 ) ;
V_133 = F_120 ( V_133 ) ;
F_121 ( V_165 -> V_106 ) ;
}
printf ( L_75 ) ;
printf ( L_76 V_16 L_77 ,
( double ) V_8 -> V_195 / V_118 , V_8 -> V_196 ) ;
printf ( L_78 ) ;
F_114 ( V_8 ) ;
printf ( L_15 ) ;
return 0 ;
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_270 * V_218 ;
V_8 -> V_225 = F_123 ( V_271 ) ;
if ( V_8 -> V_218 . V_226 ) {
V_8 -> V_218 . V_228 = F_10 ( V_8 -> V_225 * sizeof( int ) ) ;
if ( ! V_8 -> V_218 . V_228 )
return - 1 ;
}
if ( ! V_8 -> V_218 . V_272 )
return 0 ;
V_218 = F_124 ( V_8 -> V_218 . V_272 ) ;
if ( ! V_218 ) {
F_31 ( L_79 , V_8 -> V_218 . V_272 ) ;
return - 1 ;
}
V_8 -> V_218 . V_236 = V_218 ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 )
{
struct V_273 * V_218 ;
if ( ! V_8 -> V_218 . V_274 )
return 0 ;
V_218 = F_126 ( V_8 -> V_218 . V_274 ) ;
if ( ! V_218 ) {
F_31 ( L_80 , V_8 -> V_218 . V_274 ) ;
return - 1 ;
}
V_8 -> V_218 . V_219 = V_218 ;
return 0 ;
}
static int F_127 ( struct V_7 * V_8 )
{
struct V_270 * V_218 ;
if ( ! V_8 -> V_218 . V_275 )
return 0 ;
V_218 = F_124 ( V_8 -> V_218 . V_275 ) ;
if ( ! V_218 ) {
F_31 ( L_80 , V_8 -> V_218 . V_275 ) ;
return - 1 ;
}
V_8 -> V_218 . V_237 = V_218 ;
return 0 ;
}
static int F_128 ( struct V_7 * V_8 )
{
if ( F_122 ( V_8 ) )
return - 1 ;
if ( F_125 ( V_8 ) )
return - 1 ;
if ( F_127 ( V_8 ) )
return - 1 ;
F_119 () ;
if ( F_107 ( V_8 ) )
return - 1 ;
F_114 ( V_8 ) ;
return 0 ;
}
static int F_129 ( struct V_7 * V_8 )
{
unsigned long V_15 ;
F_6 ( V_8 ) ;
F_8 ( V_8 ) ;
F_47 ( V_8 ) ;
if ( F_107 ( V_8 ) )
return - 1 ;
printf ( L_81 , V_8 -> V_32 ) ;
printf ( L_82 , V_8 -> V_43 ) ;
printf ( L_83 , V_8 -> V_41 ) ;
if ( V_8 -> V_37 )
printf ( L_84 , V_8 -> V_37 ) ;
if ( V_8 -> V_39 )
printf ( L_85 , V_8 -> V_39 ) ;
if ( V_8 -> V_31 )
printf ( L_86 ,
V_8 -> V_31 ) ;
F_19 ( V_8 ) ;
F_20 ( V_8 ) ;
F_40 ( V_8 ) ;
printf ( L_87 ) ;
for ( V_15 = 0 ; V_15 < V_8 -> V_109 ; V_15 ++ )
F_46 ( V_8 ) ;
return 0 ;
}
static void F_130 ( struct V_7 * V_8 , const struct V_276 * V_277 ,
const char * const V_278 [] )
{
char * V_279 , * V_200 , * V_168 = F_131 ( V_8 -> V_280 ) ;
for ( V_200 = strtok_r ( V_168 , L_88 , & V_279 ) ;
V_200 ; V_200 = strtok_r ( NULL , L_88 , & V_279 ) ) {
if ( F_84 ( V_200 , & V_8 -> V_155 ) < 0 ) {
F_132 ( V_278 , V_277 ,
L_89 , V_200 ) ;
}
}
free ( V_168 ) ;
F_84 ( L_20 , & V_8 -> V_167 ) ;
}
static int F_133 ( int V_281 , const char * * V_282 )
{
unsigned int V_283 , V_15 , V_54 ;
const char * * V_284 ;
const char * const V_285 [] = {
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
V_283 = F_85 ( V_285 ) + V_281 - 1 ;
V_284 = calloc ( V_283 + 1 , sizeof( char * ) ) ;
if ( V_284 == NULL )
return - V_286 ;
for ( V_15 = 0 ; V_15 < F_85 ( V_285 ) ; V_15 ++ )
V_284 [ V_15 ] = F_131 ( V_285 [ V_15 ] ) ;
for ( V_54 = 1 ; V_54 < ( unsigned int ) V_281 ; V_54 ++ , V_15 ++ )
V_284 [ V_15 ] = V_282 [ V_54 ] ;
F_11 ( V_15 != V_283 ) ;
return F_134 ( V_15 , V_284 , NULL ) ;
}
int F_135 ( int V_281 , const char * * V_282 , const char * T_9 V_42 )
{
const char V_287 [] = L_102 ;
struct V_7 V_8 = {
. V_211 = {
. V_123 = F_106 ,
. V_45 = V_288 ,
. V_289 = V_290 ,
. V_141 = F_103 ,
. V_291 = true ,
} ,
. V_167 = F_136 ( V_8 . V_167 ) ,
. V_155 = F_136 ( V_8 . V_155 ) ,
. V_100 = V_292 ,
. V_103 = V_292 ,
. V_280 = V_287 ,
. V_109 = 10 ,
. V_188 = - 1 ,
. V_231 = 'A' ,
. V_232 = '0' ,
. V_269 = 0 ,
} ;
const struct V_276 V_293 [] = {
F_137 ( 's' , L_103 , & V_8 . V_280 , L_104 ,
L_105 ) ,
F_138 ( 'v' , L_106 , & V_51 ,
L_107 ) ,
F_139 ( 'C' , L_108 , & V_8 . V_188 ,
L_109 ) ,
F_140 ( 'D' , L_110 , & V_294 ,
L_111 ) ,
F_140 ( 'p' , L_112 , & V_8 . V_269 ,
L_113 ) ,
F_141 ()
} ;
const struct V_276 V_295 [] = {
F_142 ( 'r' , L_114 , & V_8 . V_109 ,
L_115 ) ,
F_138 ( 'v' , L_106 , & V_51 ,
L_107 ) ,
F_140 ( 'D' , L_110 , & V_294 ,
L_111 ) ,
F_140 ( 'f' , L_116 , & V_8 . V_83 , L_117 ) ,
F_141 ()
} ;
const struct V_276 V_296 [] = {
F_137 ( 'i' , L_118 , & V_255 , L_119 ,
L_120 ) ,
F_138 ( 'v' , L_106 , & V_51 ,
L_107 ) ,
F_140 ( 'D' , L_110 , & V_294 ,
L_111 ) ,
F_141 ()
} ;
const struct V_276 V_297 [] = {
F_140 ( 0 , L_121 , & V_8 . V_218 . V_226 ,
L_122 ) ,
F_137 ( 0 , L_123 , & V_8 . V_218 . V_274 , L_112 ,
L_124 ) ,
F_137 ( 0 , L_125 , & V_8 . V_218 . V_275 , L_126 ,
L_127 ) ,
F_137 ( 0 , L_126 , & V_8 . V_218 . V_272 , L_126 ,
L_128 ) ,
F_141 ()
} ;
const char * const V_298 [] = {
L_129 ,
NULL
} ;
const char * const V_299 [] = {
L_130 ,
NULL
} ;
const char * const V_300 [] = {
L_131 ,
NULL
} ;
const char * const V_301 [] = { L_90 , L_132 , L_133 ,
L_134 , L_135 , NULL } ;
const char * V_302 [] = {
NULL ,
NULL
} ;
struct V_303 V_304 = {
. V_213 = F_76 ,
. V_242 = F_74 ,
. V_243 = F_75 ,
. V_245 = F_77 ,
} ;
struct V_303 V_305 = {
. V_242 = F_96 ,
} ;
struct V_303 V_306 = {
. V_213 = F_48 ,
. V_242 = F_51 ,
. V_244 = F_53 ,
} ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < F_85 ( V_8 . V_240 ) ; V_15 ++ )
V_8 . V_240 [ V_15 ] = - 1 ;
V_281 = F_143 ( V_281 , V_282 , V_296 , V_301 ,
V_302 , V_307 ) ;
if ( ! V_281 )
F_144 ( V_302 , V_296 ) ;
if ( ! strcmp ( V_282 [ 0 ] , L_135 ) )
return F_145 ( V_281 , V_282 , T_9 ) ;
if ( ! strncmp ( V_282 [ 0 ] , L_136 , 3 ) ) {
return F_133 ( V_281 , V_282 ) ;
} else if ( ! strncmp ( V_282 [ 0 ] , L_137 , 3 ) ) {
V_8 . V_212 = & V_304 ;
if ( V_281 > 1 ) {
V_281 = F_146 ( V_281 , V_282 , V_293 , V_298 , 0 ) ;
if ( V_281 )
F_144 ( V_298 , V_293 ) ;
}
F_130 ( & V_8 , V_293 , V_298 ) ;
return F_118 ( & V_8 ) ;
} else if ( ! strcmp ( V_282 [ 0 ] , L_133 ) ) {
if ( V_281 ) {
V_281 = F_146 ( V_281 , V_282 , V_297 , V_300 , 0 ) ;
if ( V_281 )
F_144 ( V_300 , V_297 ) ;
}
V_8 . V_212 = & V_305 ;
F_130 ( & V_8 , V_293 , V_298 ) ;
return F_128 ( & V_8 ) ;
} else if ( ! strncmp ( V_282 [ 0 ] , L_138 , 3 ) ) {
V_8 . V_212 = & V_306 ;
if ( V_281 ) {
V_281 = F_146 ( V_281 , V_282 , V_295 , V_299 , 0 ) ;
if ( V_281 )
F_144 ( V_299 , V_295 ) ;
}
return F_129 ( & V_8 ) ;
} else {
F_144 ( V_302 , V_296 ) ;
}
return 0 ;
}
