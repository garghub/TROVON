void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 , V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ;
unsigned long V_13 , V_14 , V_15 , V_16 ;
V_10 = F_2 ( V_4 , V_17 ) ;
V_11 = F_2 ( V_4 , V_18 ) ;
V_12 = F_2 ( V_4 , V_19 ) ;
V_13 = V_14 = V_4 -> V_14 ;
if ( V_13 < V_4 -> V_13 )
V_13 = V_4 -> V_13 ;
V_15 = V_16 = V_10 + V_11 + V_12 ;
if ( V_15 < V_4 -> V_15 )
V_15 = V_4 -> V_15 ;
V_5 = ( F_3 ( V_4 -> V_20 ) - ( V_4 -> V_21 & V_22 ) ) >> 10 ;
V_6 = ( V_4 -> V_23 << ( V_24 - 10 ) ) - V_5 ;
V_7 = F_2 ( V_4 , V_25 ) ;
V_8 = V_26 * sizeof( V_27 ) * F_4 ( & V_4 -> V_28 ) ;
V_9 = V_29 * sizeof( V_30 ) * F_5 ( V_4 ) ;
F_6 ( V_2 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ,
V_13 << ( V_24 - 10 ) ,
V_14 << ( V_24 - 10 ) ,
V_4 -> V_31 << ( V_24 - 10 ) ,
V_4 -> V_32 << ( V_24 - 10 ) ,
V_15 << ( V_24 - 10 ) ,
V_16 << ( V_24 - 10 ) ,
V_10 << ( V_24 - 10 ) ,
V_11 << ( V_24 - 10 ) ,
V_12 << ( V_24 - 10 ) ,
V_4 -> V_33 << ( V_24 - 10 ) ,
V_4 -> V_34 << ( V_24 - 10 ) , V_5 , V_6 ,
V_8 >> 10 ,
V_9 >> 10 ,
V_7 << ( V_24 - 10 ) ) ;
F_7 ( V_2 , V_4 ) ;
}
unsigned long F_8 ( struct V_3 * V_4 )
{
return V_35 * V_4 -> V_14 ;
}
unsigned long F_9 ( struct V_3 * V_4 ,
unsigned long * V_36 , unsigned long * V_5 ,
unsigned long * V_37 , unsigned long * V_38 )
{
* V_36 = F_2 ( V_4 , V_18 ) +
F_2 ( V_4 , V_19 ) ;
* V_5 = ( F_3 ( V_4 -> V_20 ) - ( V_4 -> V_21 & V_22 ) )
>> V_24 ;
* V_37 = V_4 -> V_33 + V_4 -> V_34 ;
* V_38 = * V_36 + F_2 ( V_4 , V_17 ) ;
return V_4 -> V_14 ;
}
static void F_10 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
F_11 ( V_42 ) ;
V_40 -> V_43 = F_12 ( V_42 ) ;
F_13 ( V_40 -> V_43 ) ;
F_14 ( V_42 ) ;
}
static void F_15 ( struct V_39 * V_40 )
{
F_16 ( V_40 -> V_43 ) ;
}
static void F_10 ( struct V_39 * V_40 )
{
}
static void F_15 ( struct V_39 * V_40 )
{
}
static void F_17 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = V_40 -> V_4 ;
F_15 ( V_40 ) ;
F_18 ( & V_4 -> V_44 ) ;
F_19 ( V_4 ) ;
}
static struct V_45 *
F_20 ( struct V_39 * V_40 , struct V_45 * V_46 )
{
if ( V_46 == V_40 -> V_47 )
return NULL ;
return V_46 -> V_48 ? : V_40 -> V_47 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
if ( V_2 -> V_49 < V_2 -> V_50 )
V_2 -> V_51 = F_20 ( V_2 -> V_52 , V_46 ) ? V_46 -> V_53 : - 1UL ;
}
static void * F_22 ( struct V_1 * V_2 , T_1 * V_54 )
{
struct V_39 * V_40 = V_2 -> V_52 ;
unsigned long V_55 = V_2 -> V_51 ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
unsigned int V_56 = * V_54 ;
if ( V_55 == - 1UL )
return NULL ;
V_40 -> V_42 = F_23 ( V_40 -> V_57 ) ;
if ( ! V_40 -> V_42 )
return F_24 ( - V_58 ) ;
V_4 = V_40 -> V_4 ;
if ( ! V_4 || ! F_25 ( V_4 ) )
return NULL ;
F_26 ( & V_4 -> V_44 ) ;
F_10 ( V_40 ) ;
V_40 -> V_47 = F_27 ( V_4 ) ;
if ( V_55 ) {
V_46 = F_28 ( V_4 , V_55 - 1 ) ;
if ( V_46 && V_46 -> V_59 <= V_55 )
V_46 = F_20 ( V_40 , V_46 ) ;
if ( V_46 )
return V_46 ;
}
V_2 -> V_51 = 0 ;
if ( V_56 < V_4 -> V_60 ) {
for ( V_46 = V_4 -> V_61 ; V_56 ; V_56 -- ) {
V_2 -> V_51 = V_46 -> V_59 ;
V_46 = V_46 -> V_48 ;
}
return V_46 ;
}
if ( V_56 == V_4 -> V_60 && V_40 -> V_47 )
return V_40 -> V_47 ;
F_17 ( V_40 ) ;
return NULL ;
}
static void * F_29 ( struct V_1 * V_2 , void * V_62 , T_1 * V_56 )
{
struct V_39 * V_40 = V_2 -> V_52 ;
struct V_45 * V_63 ;
( * V_56 ) ++ ;
V_63 = F_20 ( V_40 , V_62 ) ;
if ( ! V_63 )
F_17 ( V_40 ) ;
return V_63 ;
}
static void F_30 ( struct V_1 * V_2 , void * V_62 )
{
struct V_39 * V_40 = V_2 -> V_52 ;
if ( ! F_31 ( V_62 ) )
F_17 ( V_40 ) ;
if ( V_40 -> V_42 ) {
F_32 ( V_40 -> V_42 ) ;
V_40 -> V_42 = NULL ;
}
}
static int F_33 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 , int V_66 )
{
struct V_39 * V_40 = F_34 ( V_11 , V_65 , V_66 ) ;
if ( ! V_40 )
return - V_67 ;
V_40 -> V_57 = V_57 ;
V_40 -> V_4 = F_35 ( V_57 , V_68 ) ;
if ( F_36 ( V_40 -> V_4 ) ) {
int V_69 = F_37 ( V_40 -> V_4 ) ;
F_38 ( V_57 , V_11 ) ;
return V_69 ;
}
return 0 ;
}
static int F_39 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_1 * V_70 = V_11 -> V_71 ;
struct V_39 * V_40 = V_70 -> V_52 ;
if ( V_40 -> V_4 )
F_40 ( V_40 -> V_4 ) ;
F_41 ( V_40 -> V_72 ) ;
return F_38 ( V_57 , V_11 ) ;
}
static int F_42 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 )
{
return F_33 ( V_57 , V_11 , V_65 ,
sizeof( struct V_39 ) ) ;
}
static int F_43 ( struct V_45 * V_46 )
{
return V_46 -> V_59 <= V_46 -> V_73 -> V_74 &&
V_46 -> V_53 >= V_46 -> V_73 -> V_74 ;
}
static void F_44 ( struct V_1 * V_2 ,
unsigned long V_75 , unsigned long V_76 ,
T_2 V_77 , unsigned long long V_78 ,
T_3 V_79 , unsigned long V_80 )
{
F_45 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_6 ( V_2 , L_17 ,
V_75 ,
V_76 ,
V_77 & V_81 ? 'r' : '-' ,
V_77 & V_82 ? 'w' : '-' ,
V_77 & V_83 ? 'x' : '-' ,
V_77 & V_84 ? 's' : 'p' ,
V_78 ,
F_46 ( V_79 ) , F_47 ( V_79 ) , V_80 ) ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_45 * V_46 , int V_85 )
{
struct V_3 * V_4 = V_46 -> V_73 ;
struct V_11 * V_11 = V_46 -> V_86 ;
T_2 V_77 = V_46 -> V_87 ;
unsigned long V_80 = 0 ;
unsigned long long V_78 = 0 ;
unsigned long V_75 , V_76 ;
T_3 V_79 = 0 ;
const char * V_88 = NULL ;
if ( V_11 ) {
struct V_57 * V_57 = F_49 ( V_46 -> V_86 ) ;
V_79 = V_57 -> V_89 -> V_90 ;
V_80 = V_57 -> V_91 ;
V_78 = ( ( T_1 ) V_46 -> V_92 ) << V_24 ;
}
V_75 = V_46 -> V_59 ;
V_76 = V_46 -> V_53 ;
F_44 ( V_2 , V_75 , V_76 , V_77 , V_78 , V_79 , V_80 ) ;
if ( V_11 ) {
F_50 ( V_2 , ' ' ) ;
F_51 ( V_2 , V_11 , L_18 ) ;
goto V_93;
}
if ( V_46 -> V_94 && V_46 -> V_94 -> V_88 ) {
V_88 = V_46 -> V_94 -> V_88 ( V_46 ) ;
if ( V_88 )
goto V_93;
}
V_88 = F_52 ( V_46 ) ;
if ( ! V_88 ) {
if ( ! V_4 ) {
V_88 = L_19 ;
goto V_93;
}
if ( V_46 -> V_59 <= V_4 -> V_95 &&
V_46 -> V_53 >= V_4 -> V_96 ) {
V_88 = L_20 ;
goto V_93;
}
if ( F_43 ( V_46 ) )
V_88 = L_21 ;
}
V_93:
if ( V_88 ) {
F_50 ( V_2 , ' ' ) ;
F_53 ( V_2 , V_88 ) ;
}
F_54 ( V_2 , '\n' ) ;
}
static int F_55 ( struct V_1 * V_2 , void * V_62 , int V_85 )
{
F_48 ( V_2 , V_62 , V_85 ) ;
F_21 ( V_2 , V_62 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , void * V_62 )
{
return F_55 ( V_2 , V_62 , 1 ) ;
}
static int F_57 ( struct V_1 * V_2 , void * V_62 )
{
return F_55 ( V_2 , V_62 , 0 ) ;
}
static int F_58 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_42 ( V_57 , V_11 , & V_97 ) ;
}
static int F_59 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_42 ( V_57 , V_11 , & V_98 ) ;
}
static void F_60 ( struct V_99 * V_100 , struct V_101 * V_101 ,
bool V_102 , bool V_103 , bool V_104 )
{
int V_105 , V_106 = V_102 ? 1 << F_61 ( V_101 ) : 1 ;
unsigned long V_50 = V_106 * V_35 ;
if ( F_62 ( V_101 ) ) {
V_100 -> V_107 += V_50 ;
if ( ! F_63 ( V_101 ) && ! V_104 && ! F_64 ( V_101 ) )
V_100 -> V_108 += V_50 ;
}
V_100 -> V_38 += V_50 ;
if ( V_103 || F_65 ( V_101 ) || F_66 ( V_101 ) )
V_100 -> V_109 += V_50 ;
if ( F_67 ( V_101 ) == 1 ) {
if ( V_104 || F_64 ( V_101 ) )
V_100 -> V_110 += V_50 ;
else
V_100 -> V_111 += V_50 ;
V_100 -> V_112 += ( V_113 ) V_50 << V_114 ;
return;
}
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ , V_101 ++ ) {
int V_115 = F_68 ( V_101 ) ;
if ( V_115 >= 2 ) {
if ( V_104 || F_64 ( V_101 ) )
V_100 -> V_116 += V_35 ;
else
V_100 -> V_117 += V_35 ;
V_100 -> V_112 += ( V_35 << V_114 ) / V_115 ;
} else {
if ( V_104 || F_64 ( V_101 ) )
V_100 -> V_110 += V_35 ;
else
V_100 -> V_111 += V_35 ;
V_100 -> V_112 += V_35 << V_114 ;
}
}
}
static int F_69 ( unsigned long V_118 , unsigned long V_76 ,
struct V_119 * V_120 )
{
struct V_99 * V_100 = V_120 -> V_52 ;
V_100 -> V_7 += F_70 (
V_120 -> V_46 -> V_86 -> V_121 , V_118 , V_76 ) ;
return 0 ;
}
static void F_71 ( V_27 * V_122 , unsigned long V_118 ,
struct V_119 * V_120 )
{
struct V_99 * V_100 = V_120 -> V_52 ;
struct V_45 * V_46 = V_120 -> V_46 ;
struct V_101 * V_101 = NULL ;
if ( F_72 ( * V_122 ) ) {
V_101 = F_73 ( V_46 , V_118 , * V_122 ) ;
} else if ( F_74 ( * V_122 ) ) {
T_4 V_123 = F_75 ( * V_122 ) ;
if ( ! F_76 ( V_123 ) ) {
int V_115 ;
V_100 -> V_7 += V_35 ;
V_115 = F_77 ( V_123 ) ;
if ( V_115 >= 2 ) {
V_113 V_124 = ( V_113 ) V_35 << V_114 ;
F_78 ( V_124 , V_115 ) ;
V_100 -> V_125 += V_124 ;
} else {
V_100 -> V_125 += ( V_113 ) V_35 << V_114 ;
}
} else if ( F_79 ( V_123 ) )
V_101 = F_80 ( V_123 ) ;
else if ( F_81 ( V_123 ) )
V_101 = F_82 ( V_123 ) ;
} else if ( F_83 ( F_84 ( V_126 ) && V_100 -> V_127
&& F_85 ( * V_122 ) ) ) {
V_101 = F_86 ( V_46 -> V_86 -> V_121 ,
F_87 ( V_46 , V_118 ) ) ;
if ( ! V_101 )
return;
if ( F_88 ( V_101 ) )
V_100 -> V_7 += V_35 ;
else
F_89 ( V_101 ) ;
return;
}
if ( ! V_101 )
return;
F_60 ( V_100 , V_101 , false , F_90 ( * V_122 ) , F_91 ( * V_122 ) ) ;
}
static void F_92 ( V_30 * V_128 , unsigned long V_118 ,
struct V_119 * V_120 )
{
struct V_99 * V_100 = V_120 -> V_52 ;
struct V_45 * V_46 = V_120 -> V_46 ;
struct V_101 * V_101 ;
V_101 = F_93 ( V_46 , V_118 , V_128 , V_129 ) ;
if ( F_31 ( V_101 ) )
return;
if ( F_62 ( V_101 ) )
V_100 -> V_130 += V_131 ;
else if ( F_63 ( V_101 ) )
V_100 -> V_132 += V_131 ;
else if ( F_94 ( V_101 ) )
;
else
F_95 ( 1 , V_101 ) ;
F_60 ( V_100 , V_101 , true , F_96 ( * V_128 ) , F_97 ( * V_128 ) ) ;
}
static void F_92 ( V_30 * V_128 , unsigned long V_118 ,
struct V_119 * V_120 )
{
}
static int F_98 ( V_30 * V_128 , unsigned long V_118 , unsigned long V_76 ,
struct V_119 * V_120 )
{
struct V_45 * V_46 = V_120 -> V_46 ;
V_27 * V_122 ;
T_5 * V_133 ;
V_133 = F_99 ( V_128 , V_46 ) ;
if ( V_133 ) {
if ( F_100 ( * V_128 ) )
F_92 ( V_128 , V_118 , V_120 ) ;
F_101 ( V_133 ) ;
goto V_134;
}
if ( F_102 ( V_128 ) )
goto V_134;
V_122 = F_103 ( V_46 -> V_73 , V_128 , V_118 , & V_133 ) ;
for (; V_118 != V_76 ; V_122 ++ , V_118 += V_35 )
F_71 ( V_122 , V_118 , V_120 ) ;
F_104 ( V_122 - 1 , V_133 ) ;
V_134:
F_105 () ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
static const char V_135 [ V_136 ] [ 2 ] = {
[ 0 ... ( V_136 - 1 ) ] = L_22 ,
[ F_107 ( V_81 ) ] = L_23 ,
[ F_107 ( V_82 ) ] = L_24 ,
[ F_107 ( V_83 ) ] = L_25 ,
[ F_107 ( V_137 ) ] = L_26 ,
[ F_107 ( V_138 ) ] = L_27 ,
[ F_107 ( V_139 ) ] = L_28 ,
[ F_107 ( V_140 ) ] = L_29 ,
[ F_107 ( V_84 ) ] = L_30 ,
[ F_107 ( V_141 ) ] = L_31 ,
[ F_107 ( V_142 ) ] = L_32 ,
[ F_107 ( V_143 ) ] = L_33 ,
#ifdef F_108
[ F_107 ( V_144 ) ] = L_34 ,
#endif
[ F_107 ( V_145 ) ] = L_35 ,
[ F_107 ( V_146 ) ] = L_36 ,
[ F_107 ( V_147 ) ] = L_37 ,
[ F_107 ( V_148 ) ] = L_38 ,
[ F_107 ( V_149 ) ] = L_39 ,
[ F_107 ( V_150 ) ] = L_40 ,
[ F_107 ( V_151 ) ] = L_41 ,
[ F_107 ( V_152 ) ] = L_42 ,
[ F_107 ( V_153 ) ] = L_43 ,
[ F_107 ( V_154 ) ] = L_44 ,
[ F_107 ( V_155 ) ] = L_45 ,
[ F_107 ( V_156 ) ] = L_46 ,
#ifdef F_109
[ F_107 ( V_157 ) ] = L_47 ,
#endif
[ F_107 ( V_158 ) ] = L_48 ,
[ F_107 ( V_159 ) ] = L_49 ,
[ F_107 ( V_160 ) ] = L_50 ,
[ F_107 ( V_161 ) ] = L_51 ,
[ F_107 ( V_162 ) ] = L_52 ,
[ F_107 ( V_163 ) ] = L_53 ,
#ifdef F_110
[ F_107 ( V_164 ) ] = L_54 ,
[ F_107 ( V_165 ) ] = L_54 ,
[ F_107 ( V_166 ) ] = L_54 ,
[ F_107 ( V_167 ) ] = L_54 ,
#endif
} ;
T_6 V_105 ;
F_53 ( V_2 , L_55 ) ;
for ( V_105 = 0 ; V_105 < V_136 ; V_105 ++ ) {
if ( ! V_135 [ V_105 ] [ 0 ] )
continue;
if ( V_46 -> V_87 & ( 1UL << V_105 ) ) {
F_6 ( V_2 , L_56 ,
V_135 [ V_105 ] [ 0 ] , V_135 [ V_105 ] [ 1 ] ) ;
}
}
F_54 ( V_2 , '\n' ) ;
}
static int F_111 ( V_27 * V_122 , unsigned long V_168 ,
unsigned long V_118 , unsigned long V_76 ,
struct V_119 * V_120 )
{
struct V_99 * V_100 = V_120 -> V_52 ;
struct V_45 * V_46 = V_120 -> V_46 ;
struct V_101 * V_101 = NULL ;
if ( F_72 ( * V_122 ) ) {
V_101 = F_73 ( V_46 , V_118 , * V_122 ) ;
} else if ( F_74 ( * V_122 ) ) {
T_4 V_123 = F_75 ( * V_122 ) ;
if ( F_79 ( V_123 ) )
V_101 = F_80 ( V_123 ) ;
else if ( F_81 ( V_123 ) )
V_101 = F_82 ( V_123 ) ;
}
if ( V_101 ) {
int V_115 = F_68 ( V_101 ) ;
if ( V_115 >= 2 )
V_100 -> V_169 += F_112 ( F_113 ( V_46 ) ) ;
else
V_100 -> V_170 += F_112 ( F_113 ( V_46 ) ) ;
}
return 0 ;
}
void __weak F_114 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
}
static int F_115 ( struct V_1 * V_2 , void * V_62 , int V_85 )
{
struct V_39 * V_40 = V_2 -> V_52 ;
struct V_45 * V_46 = V_62 ;
struct V_99 V_171 ;
struct V_99 * V_100 ;
struct V_119 V_172 = {
. V_173 = F_98 ,
#ifdef F_116
. V_174 = F_111 ,
#endif
. V_4 = V_46 -> V_73 ,
} ;
int V_175 = 0 ;
bool V_176 ;
bool V_177 ;
if ( V_40 -> V_72 ) {
V_176 = true ;
V_100 = V_40 -> V_72 ;
if ( V_100 -> V_178 ) {
V_100 -> V_179 = V_46 -> V_59 ;
V_100 -> V_178 = false ;
}
V_177 = ! F_20 ( V_40 , V_46 ) ;
} else {
V_176 = false ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_100 = & V_171 ;
}
V_172 . V_52 = V_100 ;
#ifdef V_126
if ( V_46 -> V_86 && F_117 ( V_46 -> V_86 -> V_121 ) ) {
unsigned long V_180 = F_118 ( V_46 ) ;
if ( ! V_180 || ( V_46 -> V_87 & V_137 ) ||
! ( V_46 -> V_87 & V_82 ) ) {
V_100 -> V_7 = V_180 ;
} else {
V_100 -> V_127 = true ;
V_172 . V_181 = F_69 ;
}
}
#endif
F_119 ( V_46 , & V_172 ) ;
if ( V_46 -> V_87 & V_145 )
V_100 -> V_182 += V_100 -> V_112 ;
if ( ! V_176 ) {
F_48 ( V_2 , V_46 , V_85 ) ;
} else if ( V_177 ) {
F_44 (
V_2 , V_100 -> V_179 , V_46 -> V_53 , 0 , 0 , 0 , 0 ) ;
F_50 ( V_2 , ' ' ) ;
F_53 ( V_2 , L_57 ) ;
} else {
V_175 = V_183 ;
}
if ( ! V_176 )
F_6 ( V_2 ,
L_58
L_59
L_60 ,
( V_46 -> V_53 - V_46 -> V_59 ) >> 10 ,
F_120 ( V_46 ) >> 10 ,
F_121 ( V_46 ) >> 10 ) ;
if ( ! V_176 || V_177 )
F_6 ( V_2 ,
L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68
L_69
L_70
L_71
L_72
L_73
L_74
L_75
L_76 ,
V_100 -> V_38 >> 10 ,
( unsigned long ) ( V_100 -> V_112 >> ( 10 + V_114 ) ) ,
V_100 -> V_117 >> 10 ,
V_100 -> V_116 >> 10 ,
V_100 -> V_111 >> 10 ,
V_100 -> V_110 >> 10 ,
V_100 -> V_109 >> 10 ,
V_100 -> V_107 >> 10 ,
V_100 -> V_108 >> 10 ,
V_100 -> V_130 >> 10 ,
V_100 -> V_132 >> 10 ,
V_100 -> V_169 >> 10 ,
V_100 -> V_170 >> 10 ,
V_100 -> V_7 >> 10 ,
( unsigned long ) ( V_100 -> V_125 >> ( 10 + V_114 ) ) ,
( unsigned long ) ( V_100 -> V_112 >> ( 10 + V_114 ) ) ) ;
if ( ! V_176 ) {
F_114 ( V_2 , V_46 ) ;
F_106 ( V_2 , V_46 ) ;
}
F_21 ( V_2 , V_46 ) ;
return V_175 ;
}
static int F_122 ( struct V_1 * V_2 , void * V_62 )
{
return F_115 ( V_2 , V_62 , 1 ) ;
}
static int F_123 ( struct V_1 * V_2 , void * V_62 )
{
return F_115 ( V_2 , V_62 , 0 ) ;
}
static int F_124 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_42 ( V_57 , V_11 , & V_184 ) ;
}
static int F_125 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_1 * V_70 ;
struct V_39 * V_40 ;
int V_175 = F_42 ( V_57 , V_11 , & V_184 ) ;
if ( V_175 < 0 )
return V_175 ;
V_70 = V_11 -> V_71 ;
V_40 = V_70 -> V_52 ;
V_40 -> V_72 = F_126 ( sizeof( * V_40 -> V_72 ) , V_185 ) ;
if ( ! V_40 -> V_72 ) {
F_39 ( V_57 , V_11 ) ;
return - V_67 ;
}
V_40 -> V_72 -> V_178 = true ;
return 0 ;
}
static int F_127 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_42 ( V_57 , V_11 , & V_186 ) ;
}
static inline void F_128 ( struct V_45 * V_46 ,
unsigned long V_118 , V_27 * V_122 )
{
V_27 V_187 = * V_122 ;
if ( F_72 ( V_187 ) ) {
V_187 = F_129 ( V_46 -> V_73 , V_118 , V_122 ) ;
V_187 = F_130 ( V_187 ) ;
V_187 = F_131 ( V_187 ) ;
F_132 ( V_46 -> V_73 , V_118 , V_122 , V_187 ) ;
} else if ( F_74 ( V_187 ) ) {
V_187 = F_133 ( V_187 ) ;
F_134 ( V_46 -> V_73 , V_118 , V_122 , V_187 ) ;
}
}
static inline void F_128 ( struct V_45 * V_46 ,
unsigned long V_118 , V_27 * V_122 )
{
}
static inline void F_135 ( struct V_45 * V_46 ,
unsigned long V_118 , V_30 * V_188 )
{
V_30 V_128 = * V_188 ;
if ( F_100 ( V_128 ) ) {
F_136 ( V_46 , V_118 , V_188 ) ;
if ( F_97 ( * V_188 ) )
V_128 = F_137 ( V_128 ) ;
if ( F_96 ( * V_188 ) )
V_128 = F_138 ( V_128 ) ;
V_128 = F_139 ( V_128 ) ;
V_128 = F_140 ( V_128 ) ;
F_141 ( V_46 -> V_73 , V_118 , V_188 , V_128 ) ;
} else if ( F_79 ( F_142 ( V_128 ) ) ) {
V_128 = F_143 ( V_128 ) ;
F_141 ( V_46 -> V_73 , V_118 , V_188 , V_128 ) ;
}
}
static inline void F_135 ( struct V_45 * V_46 ,
unsigned long V_118 , V_30 * V_188 )
{
}
static int F_144 ( V_30 * V_128 , unsigned long V_118 ,
unsigned long V_76 , struct V_119 * V_120 )
{
struct V_189 * V_190 = V_120 -> V_52 ;
struct V_45 * V_46 = V_120 -> V_46 ;
V_27 * V_122 , V_187 ;
T_5 * V_133 ;
struct V_101 * V_101 ;
V_133 = F_99 ( V_128 , V_46 ) ;
if ( V_133 ) {
if ( V_190 -> type == V_191 ) {
F_135 ( V_46 , V_118 , V_128 ) ;
goto V_134;
}
if ( ! F_100 ( * V_128 ) )
goto V_134;
V_101 = F_145 ( * V_128 ) ;
F_146 ( V_46 , V_118 , V_128 ) ;
F_147 ( V_101 ) ;
F_148 ( V_101 ) ;
V_134:
F_101 ( V_133 ) ;
return 0 ;
}
if ( F_102 ( V_128 ) )
return 0 ;
V_122 = F_103 ( V_46 -> V_73 , V_128 , V_118 , & V_133 ) ;
for (; V_118 != V_76 ; V_122 ++ , V_118 += V_35 ) {
V_187 = * V_122 ;
if ( V_190 -> type == V_191 ) {
F_128 ( V_46 , V_118 , V_122 ) ;
continue;
}
if ( ! F_72 ( V_187 ) )
continue;
V_101 = F_73 ( V_46 , V_118 , V_187 ) ;
if ( ! V_101 )
continue;
F_149 ( V_46 , V_118 , V_122 ) ;
F_147 ( V_101 ) ;
F_148 ( V_101 ) ;
}
F_104 ( V_122 - 1 , V_133 ) ;
F_105 () ;
return 0 ;
}
static int F_150 ( unsigned long V_75 , unsigned long V_76 ,
struct V_119 * V_120 )
{
struct V_189 * V_190 = V_120 -> V_52 ;
struct V_45 * V_46 = V_120 -> V_46 ;
if ( V_46 -> V_87 & V_142 )
return 1 ;
if ( V_190 -> type == V_192 && V_46 -> V_86 )
return 1 ;
if ( V_190 -> type == V_193 && ! V_46 -> V_86 )
return 1 ;
return 0 ;
}
static T_7 F_151 ( struct V_11 * V_11 , const char T_8 * V_194 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_41 * V_42 ;
char V_195 [ V_196 ] ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
enum V_197 type ;
struct V_198 V_199 ;
int V_200 ;
int V_201 ;
memset ( V_195 , 0 , sizeof( V_195 ) ) ;
if ( V_49 > sizeof( V_195 ) - 1 )
V_49 = sizeof( V_195 ) - 1 ;
if ( F_152 ( V_195 , V_194 , V_49 ) )
return - V_202 ;
V_201 = F_153 ( F_154 ( V_195 ) , 10 , & V_200 ) ;
if ( V_201 < 0 )
return V_201 ;
type = (enum V_197 ) V_200 ;
if ( type < V_203 || type >= V_204 )
return - V_205 ;
V_42 = F_23 ( F_49 ( V_11 ) ) ;
if ( ! V_42 )
return - V_58 ;
V_4 = F_155 ( V_42 ) ;
if ( V_4 ) {
struct V_189 V_190 = {
. type = type ,
} ;
struct V_119 V_206 = {
. V_173 = F_144 ,
. V_207 = F_150 ,
. V_4 = V_4 ,
. V_52 = & V_190 ,
} ;
if ( type == V_208 ) {
if ( F_156 ( & V_4 -> V_44 ) ) {
V_49 = - V_209 ;
goto V_210;
}
F_157 ( V_4 ) ;
F_158 ( & V_4 -> V_44 ) ;
goto V_210;
}
F_26 ( & V_4 -> V_44 ) ;
F_159 ( & V_199 , V_4 , 0 , - 1 ) ;
if ( type == V_191 ) {
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
if ( ! ( V_46 -> V_87 & V_157 ) )
continue;
F_18 ( & V_4 -> V_44 ) ;
if ( F_156 ( & V_4 -> V_44 ) ) {
V_49 = - V_209 ;
goto V_210;
}
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
V_46 -> V_87 &= ~ V_157 ;
F_160 ( V_46 ) ;
}
F_161 ( & V_4 -> V_44 ) ;
break;
}
F_162 ( V_4 , 0 , - 1 ) ;
}
F_163 ( 0 , V_4 -> V_211 , & V_206 ) ;
if ( type == V_191 )
F_164 ( V_4 , 0 , - 1 ) ;
F_165 ( & V_199 , 0 , - 1 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_210:
F_19 ( V_4 ) ;
}
F_32 ( V_42 ) ;
return V_49 ;
}
static inline T_9 F_166 ( V_113 V_212 , V_113 V_77 )
{
return ( T_9 ) { . V_213 = ( V_212 & V_214 ) | V_77 } ;
}
static int F_167 ( unsigned long V_118 , T_9 * V_213 ,
struct V_215 * V_216 )
{
V_216 -> V_195 [ V_216 -> V_56 ++ ] = * V_213 ;
if ( V_216 -> V_56 >= V_216 -> V_217 )
return V_218 ;
return 0 ;
}
static int F_168 ( unsigned long V_75 , unsigned long V_76 ,
struct V_119 * V_120 )
{
struct V_215 * V_216 = V_120 -> V_52 ;
unsigned long V_118 = V_75 ;
int V_69 = 0 ;
while ( V_118 < V_76 ) {
struct V_45 * V_46 = F_28 ( V_120 -> V_4 , V_118 ) ;
T_9 V_213 = F_166 ( 0 , 0 ) ;
unsigned long V_219 ;
if ( V_46 )
V_219 = F_169 ( V_76 , V_46 -> V_59 ) ;
else
V_219 = V_76 ;
for (; V_118 < V_219 ; V_118 += V_35 ) {
V_69 = F_167 ( V_118 , & V_213 , V_216 ) ;
if ( V_69 )
goto V_134;
}
if ( ! V_46 )
break;
if ( V_46 -> V_87 & V_157 )
V_213 = F_166 ( 0 , V_220 ) ;
for (; V_118 < F_169 ( V_76 , V_46 -> V_53 ) ; V_118 += V_35 ) {
V_69 = F_167 ( V_118 , & V_213 , V_216 ) ;
if ( V_69 )
goto V_134;
}
}
V_134:
return V_69 ;
}
static T_9 F_170 ( struct V_215 * V_216 ,
struct V_45 * V_46 , unsigned long V_118 , V_27 V_122 )
{
V_113 V_212 = 0 , V_77 = 0 ;
struct V_101 * V_101 = NULL ;
if ( F_72 ( V_122 ) ) {
if ( V_216 -> V_221 )
V_212 = F_171 ( V_122 ) ;
V_77 |= V_222 ;
V_101 = F_172 ( V_46 , V_118 , V_122 , true ) ;
if ( F_173 ( V_122 ) )
V_77 |= V_220 ;
} else if ( F_74 ( V_122 ) ) {
T_4 V_223 ;
if ( F_174 ( V_122 ) )
V_77 |= V_220 ;
V_223 = F_75 ( V_122 ) ;
V_212 = F_175 ( V_223 ) |
( F_176 ( V_223 ) << V_224 ) ;
V_77 |= V_225 ;
if ( F_79 ( V_223 ) )
V_101 = F_80 ( V_223 ) ;
if ( F_81 ( V_223 ) )
V_101 = F_82 ( V_223 ) ;
}
if ( V_101 && ! F_62 ( V_101 ) )
V_77 |= V_226 ;
if ( V_101 && F_68 ( V_101 ) == 1 )
V_77 |= V_227 ;
if ( V_46 -> V_87 & V_157 )
V_77 |= V_220 ;
return F_166 ( V_212 , V_77 ) ;
}
static int F_177 ( V_30 * V_188 , unsigned long V_118 , unsigned long V_76 ,
struct V_119 * V_120 )
{
struct V_45 * V_46 = V_120 -> V_46 ;
struct V_215 * V_216 = V_120 -> V_52 ;
T_5 * V_133 ;
V_27 * V_122 , * V_228 ;
int V_69 = 0 ;
#ifdef F_178
V_133 = F_99 ( V_188 , V_46 ) ;
if ( V_133 ) {
V_113 V_77 = 0 , V_212 = 0 ;
V_30 V_128 = * V_188 ;
struct V_101 * V_101 = NULL ;
if ( V_46 -> V_87 & V_157 )
V_77 |= V_220 ;
if ( F_100 ( V_128 ) ) {
V_101 = F_145 ( V_128 ) ;
V_77 |= V_222 ;
if ( F_179 ( V_128 ) )
V_77 |= V_220 ;
if ( V_216 -> V_221 )
V_212 = F_180 ( V_128 ) +
( ( V_118 & ~ V_229 ) >> V_24 ) ;
}
#ifdef F_181
else if ( F_182 ( V_128 ) ) {
T_4 V_223 = F_142 ( V_128 ) ;
V_212 = F_175 ( V_223 ) |
( F_176 ( V_223 ) << V_224 ) ;
V_77 |= V_225 ;
if ( F_183 ( V_128 ) )
V_77 |= V_220 ;
F_184 ( ! F_185 ( V_128 ) ) ;
V_101 = F_80 ( V_223 ) ;
}
#endif
if ( V_101 && F_68 ( V_101 ) == 1 )
V_77 |= V_227 ;
for (; V_118 != V_76 ; V_118 += V_35 ) {
T_9 V_213 = F_166 ( V_212 , V_77 ) ;
V_69 = F_167 ( V_118 , & V_213 , V_216 ) ;
if ( V_69 )
break;
if ( V_216 -> V_221 && ( V_77 & V_222 ) )
V_212 ++ ;
}
F_101 ( V_133 ) ;
return V_69 ;
}
if ( F_102 ( V_188 ) )
return 0 ;
#endif
V_228 = V_122 = F_103 ( V_120 -> V_4 , V_188 , V_118 , & V_133 ) ;
for (; V_118 < V_76 ; V_122 ++ , V_118 += V_35 ) {
T_9 V_213 ;
V_213 = F_170 ( V_216 , V_46 , V_118 , * V_122 ) ;
V_69 = F_167 ( V_118 , & V_213 , V_216 ) ;
if ( V_69 )
break;
}
F_104 ( V_228 , V_133 ) ;
F_105 () ;
return V_69 ;
}
static int F_186 ( V_27 * V_230 , unsigned long V_168 ,
unsigned long V_118 , unsigned long V_76 ,
struct V_119 * V_120 )
{
struct V_215 * V_216 = V_120 -> V_52 ;
struct V_45 * V_46 = V_120 -> V_46 ;
V_113 V_77 = 0 , V_212 = 0 ;
int V_69 = 0 ;
V_27 V_122 ;
if ( V_46 -> V_87 & V_157 )
V_77 |= V_220 ;
V_122 = F_187 ( V_230 ) ;
if ( F_72 ( V_122 ) ) {
struct V_101 * V_101 = F_188 ( V_122 ) ;
if ( ! F_62 ( V_101 ) )
V_77 |= V_226 ;
if ( F_68 ( V_101 ) == 1 )
V_77 |= V_227 ;
V_77 |= V_222 ;
if ( V_216 -> V_221 )
V_212 = F_171 ( V_122 ) +
( ( V_118 & ~ V_168 ) >> V_24 ) ;
}
for (; V_118 != V_76 ; V_118 += V_35 ) {
T_9 V_213 = F_166 ( V_212 , V_77 ) ;
V_69 = F_167 ( V_118 , & V_213 , V_216 ) ;
if ( V_69 )
return V_69 ;
if ( V_216 -> V_221 && ( V_77 & V_222 ) )
V_212 ++ ;
}
F_105 () ;
return V_69 ;
}
static T_7 F_189 ( struct V_11 * V_11 , char T_8 * V_194 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_3 * V_4 = V_11 -> V_71 ;
struct V_215 V_216 ;
struct V_119 V_231 = {} ;
unsigned long V_232 ;
unsigned long V_233 ;
unsigned long V_234 ;
unsigned long V_235 ;
int V_175 = 0 , V_236 = 0 ;
if ( ! V_4 || ! F_25 ( V_4 ) )
goto V_134;
V_175 = - V_205 ;
if ( ( * V_54 % V_237 ) || ( V_49 % V_237 ) )
goto V_210;
V_175 = 0 ;
if ( ! V_49 )
goto V_210;
V_216 . V_221 = F_190 ( V_11 , & V_238 , V_239 ) ;
V_216 . V_217 = ( V_240 >> V_24 ) ;
V_216 . V_195 = F_191 ( V_216 . V_217 * V_237 , V_185 ) ;
V_175 = - V_67 ;
if ( ! V_216 . V_195 )
goto V_210;
V_231 . V_173 = F_177 ;
V_231 . V_181 = F_168 ;
#ifdef F_116
V_231 . V_174 = F_186 ;
#endif
V_231 . V_4 = V_4 ;
V_231 . V_52 = & V_216 ;
V_232 = * V_54 ;
V_233 = V_232 / V_237 ;
V_234 = V_233 << V_24 ;
V_235 = V_4 -> V_241 ;
if ( V_233 > V_4 -> V_241 >> V_24 )
V_234 = V_235 ;
V_175 = 0 ;
while ( V_49 && ( V_234 < V_235 ) ) {
int V_217 ;
unsigned long V_76 ;
V_216 . V_56 = 0 ;
V_76 = ( V_234 + V_240 ) & V_242 ;
if ( V_76 < V_234 || V_76 > V_235 )
V_76 = V_235 ;
F_26 ( & V_4 -> V_44 ) ;
V_175 = F_163 ( V_234 , V_76 , & V_231 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_234 = V_76 ;
V_217 = F_169 ( V_49 , V_237 * V_216 . V_56 ) ;
if ( F_192 ( V_194 , V_216 . V_195 , V_217 ) ) {
V_175 = - V_202 ;
goto V_243;
}
V_236 += V_217 ;
V_194 += V_217 ;
V_49 -= V_217 ;
}
* V_54 += V_236 ;
if ( ! V_175 || V_175 == V_218 )
V_175 = V_236 ;
V_243:
F_41 ( V_216 . V_195 ) ;
V_210:
F_19 ( V_4 ) ;
V_134:
return V_175 ;
}
static int F_193 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_57 , V_68 ) ;
if ( F_36 ( V_4 ) )
return F_37 ( V_4 ) ;
V_11 -> V_71 = V_4 ;
return 0 ;
}
static int F_194 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_71 ;
if ( V_4 )
F_40 ( V_4 ) ;
return 0 ;
}
static void F_195 ( struct V_101 * V_101 , struct V_244 * V_245 , int F_91 ,
unsigned long V_246 )
{
int V_49 = F_68 ( V_101 ) ;
V_245 -> V_247 += V_246 ;
if ( F_91 || F_64 ( V_101 ) )
V_245 -> V_104 += V_246 ;
if ( F_196 ( V_101 ) )
V_245 -> V_248 += V_246 ;
if ( F_197 ( V_101 ) || F_198 ( V_101 ) )
V_245 -> V_249 += V_246 ;
if ( F_199 ( V_101 ) )
V_245 -> V_250 += V_246 ;
if ( F_62 ( V_101 ) )
V_245 -> V_10 += V_246 ;
if ( V_49 > V_245 -> V_251 )
V_245 -> V_251 = V_49 ;
V_245 -> V_252 [ F_200 ( V_101 ) ] += V_246 ;
}
static struct V_101 * F_201 ( V_27 V_122 , struct V_45 * V_46 ,
unsigned long V_118 )
{
struct V_101 * V_101 ;
int V_253 ;
if ( ! F_72 ( V_122 ) )
return NULL ;
V_101 = F_73 ( V_46 , V_118 , V_122 ) ;
if ( ! V_101 )
return NULL ;
if ( F_202 ( V_101 ) )
return NULL ;
V_253 = F_200 ( V_101 ) ;
if ( ! F_203 ( V_253 , V_254 [ V_255 ] ) )
return NULL ;
return V_101 ;
}
static struct V_101 * F_204 ( V_30 V_128 ,
struct V_45 * V_46 ,
unsigned long V_118 )
{
struct V_101 * V_101 ;
int V_253 ;
if ( ! F_100 ( V_128 ) )
return NULL ;
V_101 = F_205 ( V_46 , V_118 , V_128 ) ;
if ( ! V_101 )
return NULL ;
if ( F_202 ( V_101 ) )
return NULL ;
V_253 = F_200 ( V_101 ) ;
if ( ! F_203 ( V_253 , V_254 [ V_255 ] ) )
return NULL ;
return V_101 ;
}
static int F_206 ( V_30 * V_128 , unsigned long V_118 ,
unsigned long V_76 , struct V_119 * V_120 )
{
struct V_244 * V_245 = V_120 -> V_52 ;
struct V_45 * V_46 = V_120 -> V_46 ;
T_5 * V_133 ;
V_27 * V_228 ;
V_27 * V_122 ;
#ifdef F_178
V_133 = F_99 ( V_128 , V_46 ) ;
if ( V_133 ) {
struct V_101 * V_101 ;
V_101 = F_204 ( * V_128 , V_46 , V_118 ) ;
if ( V_101 )
F_195 ( V_101 , V_245 , F_97 ( * V_128 ) ,
V_131 / V_35 ) ;
F_101 ( V_133 ) ;
return 0 ;
}
if ( F_102 ( V_128 ) )
return 0 ;
#endif
V_228 = V_122 = F_103 ( V_120 -> V_4 , V_128 , V_118 , & V_133 ) ;
do {
struct V_101 * V_101 = F_201 ( * V_122 , V_46 , V_118 ) ;
if ( ! V_101 )
continue;
F_195 ( V_101 , V_245 , F_91 ( * V_122 ) , 1 ) ;
} while ( V_122 ++ , V_118 += V_35 , V_118 != V_76 );
F_104 ( V_228 , V_133 ) ;
F_105 () ;
return 0 ;
}
static int F_207 ( V_27 * V_122 , unsigned long V_168 ,
unsigned long V_118 , unsigned long V_76 , struct V_119 * V_120 )
{
V_27 V_256 = F_187 ( V_122 ) ;
struct V_244 * V_245 ;
struct V_101 * V_101 ;
if ( ! F_72 ( V_256 ) )
return 0 ;
V_101 = F_188 ( V_256 ) ;
if ( ! V_101 )
return 0 ;
V_245 = V_120 -> V_52 ;
F_195 ( V_101 , V_245 , F_91 ( V_256 ) , 1 ) ;
return 0 ;
}
static int F_207 ( V_27 * V_122 , unsigned long V_168 ,
unsigned long V_118 , unsigned long V_76 , struct V_119 * V_120 )
{
return 0 ;
}
static int F_208 ( struct V_1 * V_2 , void * V_62 , int V_85 )
{
struct V_257 * V_258 = V_2 -> V_52 ;
struct V_39 * V_259 = & V_258 -> V_260 ;
struct V_45 * V_46 = V_62 ;
struct V_244 * V_245 = & V_258 -> V_245 ;
struct V_11 * V_11 = V_46 -> V_86 ;
struct V_3 * V_4 = V_46 -> V_73 ;
struct V_119 V_120 = {
. V_174 = F_207 ,
. V_173 = F_206 ,
. V_52 = V_245 ,
. V_4 = V_4 ,
} ;
struct V_261 * V_262 ;
char V_195 [ 64 ] ;
int V_253 ;
if ( ! V_4 )
return 0 ;
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_262 = F_209 ( V_46 , V_46 -> V_59 ) ;
if ( V_262 ) {
F_210 ( V_195 , sizeof( V_195 ) , V_262 ) ;
F_211 ( V_262 ) ;
} else {
F_210 ( V_195 , sizeof( V_195 ) , V_259 -> V_43 ) ;
}
F_6 ( V_2 , L_77 , V_46 -> V_59 , V_195 ) ;
if ( V_11 ) {
F_53 ( V_2 , L_78 ) ;
F_51 ( V_2 , V_11 , L_79 ) ;
} else if ( V_46 -> V_59 <= V_4 -> V_95 && V_46 -> V_53 >= V_4 -> V_96 ) {
F_53 ( V_2 , L_80 ) ;
} else if ( F_43 ( V_46 ) ) {
F_53 ( V_2 , L_81 ) ;
}
if ( F_212 ( V_46 ) )
F_53 ( V_2 , L_82 ) ;
F_119 ( V_46 , & V_120 ) ;
if ( ! V_245 -> V_247 )
goto V_134;
if ( V_245 -> V_10 )
F_6 ( V_2 , L_83 , V_245 -> V_10 ) ;
if ( V_245 -> V_104 )
F_6 ( V_2 , L_84 , V_245 -> V_104 ) ;
if ( V_245 -> V_247 != V_245 -> V_10 && V_245 -> V_247 != V_245 -> V_104 )
F_6 ( V_2 , L_85 , V_245 -> V_247 ) ;
if ( V_245 -> V_251 > 1 )
F_6 ( V_2 , L_86 , V_245 -> V_251 ) ;
if ( V_245 -> V_248 )
F_6 ( V_2 , L_87 , V_245 -> V_248 ) ;
if ( V_245 -> V_249 < V_245 -> V_247 && ! F_212 ( V_46 ) )
F_6 ( V_2 , L_88 , V_245 -> V_249 ) ;
if ( V_245 -> V_250 )
F_6 ( V_2 , L_89 , V_245 -> V_250 ) ;
F_213 (nid, N_MEMORY)
if ( V_245 -> V_252 [ V_253 ] )
F_6 ( V_2 , L_90 , V_253 , V_245 -> V_252 [ V_253 ] ) ;
F_6 ( V_2 , L_91 , F_120 ( V_46 ) >> 10 ) ;
V_134:
F_54 ( V_2 , '\n' ) ;
F_21 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_214 ( struct V_1 * V_2 , void * V_62 )
{
return F_208 ( V_2 , V_62 , 1 ) ;
}
static int F_215 ( struct V_1 * V_2 , void * V_62 )
{
return F_208 ( V_2 , V_62 , 0 ) ;
}
static int F_216 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 )
{
return F_33 ( V_57 , V_11 , V_65 ,
sizeof( struct V_257 ) ) ;
}
static int F_217 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_216 ( V_57 , V_11 , & V_263 ) ;
}
static int F_218 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_216 ( V_57 , V_11 , & V_264 ) ;
}
