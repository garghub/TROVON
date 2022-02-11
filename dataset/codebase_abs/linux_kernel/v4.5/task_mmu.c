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
if ( ! V_4 || ! F_25 ( & V_4 -> V_59 ) )
return NULL ;
F_26 ( & V_4 -> V_44 ) ;
F_10 ( V_40 ) ;
V_40 -> V_47 = F_27 ( V_4 ) ;
if ( V_55 ) {
V_46 = F_28 ( V_4 , V_55 ) ;
if ( V_46 && ( V_46 = F_20 ( V_40 , V_46 ) ) )
return V_46 ;
}
V_2 -> V_51 = 0 ;
if ( V_56 < V_4 -> V_60 ) {
for ( V_46 = V_4 -> V_61 ; V_56 ; V_56 -- ) {
V_2 -> V_51 = V_46 -> V_53 ;
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
return F_38 ( V_57 , V_11 ) ;
}
static int F_41 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 )
{
return F_33 ( V_57 , V_11 , V_65 ,
sizeof( struct V_39 ) ) ;
}
static int F_42 ( struct V_39 * V_40 ,
struct V_45 * V_46 , int V_72 )
{
int V_73 = 0 ;
if ( V_72 ) {
V_73 = V_46 -> V_53 <= V_46 -> V_74 -> V_75 &&
V_46 -> V_76 >= V_46 -> V_74 -> V_75 ;
} else {
struct V_57 * V_57 = V_40 -> V_57 ;
struct V_41 * V_42 ;
F_43 () ;
V_42 = F_44 ( F_45 ( V_57 ) , V_77 ) ;
if ( V_42 )
V_73 = F_46 ( V_46 , V_42 ) ;
F_47 () ;
}
return V_73 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_45 * V_46 , int V_72 )
{
struct V_3 * V_4 = V_46 -> V_74 ;
struct V_11 * V_11 = V_46 -> V_78 ;
struct V_39 * V_40 = V_2 -> V_52 ;
T_2 V_79 = V_46 -> V_80 ;
unsigned long V_81 = 0 ;
unsigned long long V_82 = 0 ;
unsigned long V_83 , V_84 ;
T_3 V_85 = 0 ;
const char * V_86 = NULL ;
if ( V_11 ) {
struct V_57 * V_57 = F_49 ( V_46 -> V_78 ) ;
V_85 = V_57 -> V_87 -> V_88 ;
V_81 = V_57 -> V_89 ;
V_82 = ( ( T_1 ) V_46 -> V_90 ) << V_24 ;
}
V_83 = V_46 -> V_53 ;
if ( F_50 ( V_46 , V_83 ) )
V_83 += V_35 ;
V_84 = V_46 -> V_76 ;
if ( F_51 ( V_46 , V_84 ) )
V_84 -= V_35 ;
F_52 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_6 ( V_2 , L_17 ,
V_83 ,
V_84 ,
V_79 & V_91 ? 'r' : '-' ,
V_79 & V_92 ? 'w' : '-' ,
V_79 & V_93 ? 'x' : '-' ,
V_79 & V_94 ? 's' : 'p' ,
V_82 ,
F_53 ( V_85 ) , F_54 ( V_85 ) , V_81 ) ;
if ( V_11 ) {
F_55 ( V_2 , ' ' ) ;
F_56 ( V_2 , V_11 , L_18 ) ;
goto V_95;
}
if ( V_46 -> V_96 && V_46 -> V_96 -> V_86 ) {
V_86 = V_46 -> V_96 -> V_86 ( V_46 ) ;
if ( V_86 )
goto V_95;
}
V_86 = F_57 ( V_46 ) ;
if ( ! V_86 ) {
if ( ! V_4 ) {
V_86 = L_19 ;
goto V_95;
}
if ( V_46 -> V_53 <= V_4 -> V_97 &&
V_46 -> V_76 >= V_4 -> V_98 ) {
V_86 = L_20 ;
goto V_95;
}
if ( F_42 ( V_40 , V_46 , V_72 ) )
V_86 = L_21 ;
}
V_95:
if ( V_86 ) {
F_55 ( V_2 , ' ' ) ;
F_58 ( V_2 , V_86 ) ;
}
F_59 ( V_2 , '\n' ) ;
}
static int F_60 ( struct V_1 * V_2 , void * V_62 , int V_72 )
{
F_48 ( V_2 , V_62 , V_72 ) ;
F_21 ( V_2 , V_62 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_62 )
{
return F_60 ( V_2 , V_62 , 1 ) ;
}
static int F_62 ( struct V_1 * V_2 , void * V_62 )
{
return F_60 ( V_2 , V_62 , 0 ) ;
}
static int F_63 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_99 ) ;
}
static int F_64 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_100 ) ;
}
static void F_65 ( struct V_101 * V_102 , struct V_103 * V_103 ,
bool V_104 , bool V_105 , bool V_106 )
{
int V_107 , V_108 = V_104 ? 1 << F_66 ( V_103 ) : 1 ;
unsigned long V_50 = V_108 * V_35 ;
if ( F_67 ( V_103 ) )
V_102 -> V_109 += V_50 ;
V_102 -> V_38 += V_50 ;
if ( V_105 || F_68 ( V_103 ) || F_69 ( V_103 ) )
V_102 -> V_110 += V_50 ;
if ( F_70 ( V_103 ) == 1 ) {
if ( V_106 || F_71 ( V_103 ) )
V_102 -> V_111 += V_50 ;
else
V_102 -> V_112 += V_50 ;
V_102 -> V_113 += ( V_114 ) V_50 << V_115 ;
return;
}
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ , V_103 ++ ) {
int V_116 = F_72 ( V_103 ) ;
if ( V_116 >= 2 ) {
if ( V_106 || F_71 ( V_103 ) )
V_102 -> V_117 += V_35 ;
else
V_102 -> V_118 += V_35 ;
V_102 -> V_113 += ( V_35 << V_115 ) / V_116 ;
} else {
if ( V_106 || F_71 ( V_103 ) )
V_102 -> V_111 += V_35 ;
else
V_102 -> V_112 += V_35 ;
V_102 -> V_113 += V_35 << V_115 ;
}
}
}
static int F_73 ( unsigned long V_119 , unsigned long V_84 ,
struct V_120 * V_121 )
{
struct V_101 * V_102 = V_121 -> V_52 ;
V_102 -> V_7 += F_74 (
V_121 -> V_46 -> V_78 -> V_122 , V_119 , V_84 ) ;
return 0 ;
}
static void F_75 ( V_27 * V_123 , unsigned long V_119 ,
struct V_120 * V_121 )
{
struct V_101 * V_102 = V_121 -> V_52 ;
struct V_45 * V_46 = V_121 -> V_46 ;
struct V_103 * V_103 = NULL ;
if ( F_76 ( * V_123 ) ) {
V_103 = F_77 ( V_46 , V_119 , * V_123 ) ;
} else if ( F_78 ( * V_123 ) ) {
T_4 V_124 = F_79 ( * V_123 ) ;
if ( ! F_80 ( V_124 ) ) {
int V_116 ;
V_102 -> V_7 += V_35 ;
V_116 = F_81 ( V_124 ) ;
if ( V_116 >= 2 ) {
V_114 V_125 = ( V_114 ) V_35 << V_115 ;
F_82 ( V_125 , V_116 ) ;
V_102 -> V_126 += V_125 ;
} else {
V_102 -> V_126 += ( V_114 ) V_35 << V_115 ;
}
} else if ( F_83 ( V_124 ) )
V_103 = F_84 ( V_124 ) ;
} else if ( F_85 ( F_86 ( V_127 ) && V_102 -> V_128
&& F_87 ( * V_123 ) ) ) {
V_103 = F_88 ( V_46 -> V_78 -> V_122 ,
F_89 ( V_46 , V_119 ) ) ;
if ( ! V_103 )
return;
if ( F_90 ( V_103 ) )
V_102 -> V_7 += V_35 ;
else
F_91 ( V_103 ) ;
return;
}
if ( ! V_103 )
return;
F_65 ( V_102 , V_103 , false , F_92 ( * V_123 ) , F_93 ( * V_123 ) ) ;
}
static void F_94 ( V_30 * V_129 , unsigned long V_119 ,
struct V_120 * V_121 )
{
struct V_101 * V_102 = V_121 -> V_52 ;
struct V_45 * V_46 = V_121 -> V_46 ;
struct V_103 * V_103 ;
V_103 = F_95 ( V_46 , V_119 , V_129 , V_130 ) ;
if ( F_31 ( V_103 ) )
return;
V_102 -> V_131 += V_132 ;
F_65 ( V_102 , V_103 , true , F_96 ( * V_129 ) , F_97 ( * V_129 ) ) ;
}
static void F_94 ( V_30 * V_129 , unsigned long V_119 ,
struct V_120 * V_121 )
{
}
static int F_98 ( V_30 * V_129 , unsigned long V_119 , unsigned long V_84 ,
struct V_120 * V_121 )
{
struct V_45 * V_46 = V_121 -> V_46 ;
V_27 * V_123 ;
T_5 * V_133 ;
V_133 = F_99 ( V_129 , V_46 ) ;
if ( V_133 ) {
F_94 ( V_129 , V_119 , V_121 ) ;
F_100 ( V_133 ) ;
return 0 ;
}
if ( F_101 ( V_129 ) )
return 0 ;
V_123 = F_102 ( V_46 -> V_74 , V_129 , V_119 , & V_133 ) ;
for (; V_119 != V_84 ; V_123 ++ , V_119 += V_35 )
F_75 ( V_123 , V_119 , V_121 ) ;
F_103 ( V_123 - 1 , V_133 ) ;
F_104 () ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
static const char V_134 [ V_135 ] [ 2 ] = {
[ 0 ... ( V_135 - 1 ) ] = L_22 ,
[ F_106 ( V_91 ) ] = L_23 ,
[ F_106 ( V_92 ) ] = L_24 ,
[ F_106 ( V_93 ) ] = L_25 ,
[ F_106 ( V_136 ) ] = L_26 ,
[ F_106 ( V_137 ) ] = L_27 ,
[ F_106 ( V_138 ) ] = L_28 ,
[ F_106 ( V_139 ) ] = L_29 ,
[ F_106 ( V_94 ) ] = L_30 ,
[ F_106 ( V_140 ) ] = L_31 ,
[ F_106 ( V_141 ) ] = L_32 ,
[ F_106 ( V_142 ) ] = L_33 ,
#ifdef F_107
[ F_106 ( V_143 ) ] = L_34 ,
#endif
[ F_106 ( V_144 ) ] = L_35 ,
[ F_106 ( V_145 ) ] = L_36 ,
[ F_106 ( V_146 ) ] = L_37 ,
[ F_106 ( V_147 ) ] = L_38 ,
[ F_106 ( V_148 ) ] = L_39 ,
[ F_106 ( V_149 ) ] = L_40 ,
[ F_106 ( V_150 ) ] = L_41 ,
[ F_106 ( V_151 ) ] = L_42 ,
[ F_106 ( V_152 ) ] = L_43 ,
[ F_106 ( V_153 ) ] = L_44 ,
[ F_106 ( V_154 ) ] = L_45 ,
#ifdef F_108
[ F_106 ( V_155 ) ] = L_46 ,
#endif
[ F_106 ( V_156 ) ] = L_47 ,
[ F_106 ( V_157 ) ] = L_48 ,
[ F_106 ( V_158 ) ] = L_49 ,
[ F_106 ( V_159 ) ] = L_50 ,
[ F_106 ( V_160 ) ] = L_51 ,
[ F_106 ( V_161 ) ] = L_52 ,
} ;
T_6 V_107 ;
F_58 ( V_2 , L_53 ) ;
for ( V_107 = 0 ; V_107 < V_135 ; V_107 ++ ) {
if ( V_46 -> V_80 & ( 1UL << V_107 ) ) {
F_6 ( V_2 , L_54 ,
V_134 [ V_107 ] [ 0 ] , V_134 [ V_107 ] [ 1 ] ) ;
}
}
F_59 ( V_2 , '\n' ) ;
}
static int F_109 ( V_27 * V_123 , unsigned long V_162 ,
unsigned long V_119 , unsigned long V_84 ,
struct V_120 * V_121 )
{
struct V_101 * V_102 = V_121 -> V_52 ;
struct V_45 * V_46 = V_121 -> V_46 ;
struct V_103 * V_103 = NULL ;
if ( F_76 ( * V_123 ) ) {
V_103 = F_77 ( V_46 , V_119 , * V_123 ) ;
} else if ( F_78 ( * V_123 ) ) {
T_4 V_124 = F_79 ( * V_123 ) ;
if ( F_83 ( V_124 ) )
V_103 = F_84 ( V_124 ) ;
}
if ( V_103 ) {
int V_116 = F_72 ( V_103 ) ;
if ( V_116 >= 2 )
V_102 -> V_163 += F_110 ( F_111 ( V_46 ) ) ;
else
V_102 -> V_164 += F_110 ( F_111 ( V_46 ) ) ;
}
return 0 ;
}
static int F_112 ( struct V_1 * V_2 , void * V_62 , int V_72 )
{
struct V_45 * V_46 = V_62 ;
struct V_101 V_102 ;
struct V_120 V_165 = {
. V_166 = F_98 ,
#ifdef F_113
. V_167 = F_109 ,
#endif
. V_4 = V_46 -> V_74 ,
. V_52 = & V_102 ,
} ;
memset ( & V_102 , 0 , sizeof V_102 ) ;
#ifdef V_127
if ( V_46 -> V_78 && F_114 ( V_46 -> V_78 -> V_122 ) ) {
unsigned long V_168 = F_115 ( V_46 ) ;
if ( ! V_168 || ( V_46 -> V_80 & V_136 ) ||
! ( V_46 -> V_80 & V_92 ) ) {
V_102 . V_7 = V_168 ;
} else {
V_102 . V_128 = true ;
V_165 . V_169 = F_73 ;
}
}
#endif
F_116 ( V_46 , & V_165 ) ;
F_48 ( V_2 , V_46 , V_72 ) ;
F_6 ( V_2 ,
L_55
L_56
L_57
L_58
L_59
L_60
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
L_71 ,
( V_46 -> V_76 - V_46 -> V_53 ) >> 10 ,
V_102 . V_38 >> 10 ,
( unsigned long ) ( V_102 . V_113 >> ( 10 + V_115 ) ) ,
V_102 . V_118 >> 10 ,
V_102 . V_117 >> 10 ,
V_102 . V_112 >> 10 ,
V_102 . V_111 >> 10 ,
V_102 . V_110 >> 10 ,
V_102 . V_109 >> 10 ,
V_102 . V_131 >> 10 ,
V_102 . V_163 >> 10 ,
V_102 . V_164 >> 10 ,
V_102 . V_7 >> 10 ,
( unsigned long ) ( V_102 . V_126 >> ( 10 + V_115 ) ) ,
F_117 ( V_46 ) >> 10 ,
F_118 ( V_46 ) >> 10 ,
( V_46 -> V_80 & V_144 ) ?
( unsigned long ) ( V_102 . V_113 >> ( 10 + V_115 ) ) : 0 ) ;
F_105 ( V_2 , V_46 ) ;
F_21 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , void * V_62 )
{
return F_112 ( V_2 , V_62 , 1 ) ;
}
static int F_120 ( struct V_1 * V_2 , void * V_62 )
{
return F_112 ( V_2 , V_62 , 0 ) ;
}
static int F_121 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_170 ) ;
}
static int F_122 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_171 ) ;
}
static inline void F_123 ( struct V_45 * V_46 ,
unsigned long V_119 , V_27 * V_123 )
{
V_27 V_172 = * V_123 ;
if ( F_76 ( V_172 ) ) {
V_172 = F_124 ( V_46 -> V_74 , V_119 , V_123 ) ;
V_172 = F_125 ( V_172 ) ;
V_172 = F_126 ( V_172 ) ;
F_127 ( V_46 -> V_74 , V_119 , V_123 , V_172 ) ;
} else if ( F_78 ( V_172 ) ) {
V_172 = F_128 ( V_172 ) ;
F_129 ( V_46 -> V_74 , V_119 , V_123 , V_172 ) ;
}
}
static inline void F_123 ( struct V_45 * V_46 ,
unsigned long V_119 , V_27 * V_123 )
{
}
static inline void F_130 ( struct V_45 * V_46 ,
unsigned long V_119 , V_30 * V_173 )
{
V_30 V_129 = F_131 ( V_46 -> V_74 , V_119 , V_173 ) ;
V_129 = F_132 ( V_129 ) ;
V_129 = F_133 ( V_129 ) ;
F_134 ( V_46 -> V_74 , V_119 , V_173 , V_129 ) ;
}
static inline void F_130 ( struct V_45 * V_46 ,
unsigned long V_119 , V_30 * V_173 )
{
}
static int F_135 ( V_30 * V_129 , unsigned long V_119 ,
unsigned long V_84 , struct V_120 * V_121 )
{
struct V_174 * V_175 = V_121 -> V_52 ;
struct V_45 * V_46 = V_121 -> V_46 ;
V_27 * V_123 , V_172 ;
T_5 * V_133 ;
struct V_103 * V_103 ;
V_133 = F_99 ( V_129 , V_46 ) ;
if ( V_133 ) {
if ( V_175 -> type == V_176 ) {
F_130 ( V_46 , V_119 , V_129 ) ;
goto V_177;
}
V_103 = F_136 ( * V_129 ) ;
F_137 ( V_46 , V_119 , V_129 ) ;
F_138 ( V_103 ) ;
F_139 ( V_103 ) ;
V_177:
F_100 ( V_133 ) ;
return 0 ;
}
if ( F_101 ( V_129 ) )
return 0 ;
V_123 = F_102 ( V_46 -> V_74 , V_129 , V_119 , & V_133 ) ;
for (; V_119 != V_84 ; V_123 ++ , V_119 += V_35 ) {
V_172 = * V_123 ;
if ( V_175 -> type == V_176 ) {
F_123 ( V_46 , V_119 , V_123 ) ;
continue;
}
if ( ! F_76 ( V_172 ) )
continue;
V_103 = F_77 ( V_46 , V_119 , V_172 ) ;
if ( ! V_103 )
continue;
F_140 ( V_46 , V_119 , V_123 ) ;
F_138 ( V_103 ) ;
F_139 ( V_103 ) ;
}
F_103 ( V_123 - 1 , V_133 ) ;
F_104 () ;
return 0 ;
}
static int F_141 ( unsigned long V_83 , unsigned long V_84 ,
struct V_120 * V_121 )
{
struct V_174 * V_175 = V_121 -> V_52 ;
struct V_45 * V_46 = V_121 -> V_46 ;
if ( V_46 -> V_80 & V_141 )
return 1 ;
if ( V_175 -> type == V_178 && V_46 -> V_78 )
return 1 ;
if ( V_175 -> type == V_179 && ! V_46 -> V_78 )
return 1 ;
return 0 ;
}
static T_7 F_142 ( struct V_11 * V_11 , const char T_8 * V_180 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_41 * V_42 ;
char V_181 [ V_182 ] ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
enum V_183 type ;
int V_184 ;
int V_185 ;
memset ( V_181 , 0 , sizeof( V_181 ) ) ;
if ( V_49 > sizeof( V_181 ) - 1 )
V_49 = sizeof( V_181 ) - 1 ;
if ( F_143 ( V_181 , V_180 , V_49 ) )
return - V_186 ;
V_185 = F_144 ( F_145 ( V_181 ) , 10 , & V_184 ) ;
if ( V_185 < 0 )
return V_185 ;
type = (enum V_183 ) V_184 ;
if ( type < V_187 || type >= V_188 )
return - V_189 ;
V_42 = F_23 ( F_49 ( V_11 ) ) ;
if ( ! V_42 )
return - V_58 ;
V_4 = F_146 ( V_42 ) ;
if ( V_4 ) {
struct V_174 V_175 = {
. type = type ,
} ;
struct V_120 V_190 = {
. V_166 = F_135 ,
. V_191 = F_141 ,
. V_4 = V_4 ,
. V_52 = & V_175 ,
} ;
if ( type == V_192 ) {
F_147 ( & V_4 -> V_44 ) ;
F_148 ( V_4 ) ;
F_149 ( & V_4 -> V_44 ) ;
goto V_193;
}
F_26 ( & V_4 -> V_44 ) ;
if ( type == V_176 ) {
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
if ( ! ( V_46 -> V_80 & V_155 ) )
continue;
F_18 ( & V_4 -> V_44 ) ;
F_147 ( & V_4 -> V_44 ) ;
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
V_46 -> V_80 &= ~ V_155 ;
F_150 ( V_46 ) ;
}
F_151 ( & V_4 -> V_44 ) ;
break;
}
F_152 ( V_4 , 0 , - 1 ) ;
}
F_153 ( 0 , ~ 0UL , & V_190 ) ;
if ( type == V_176 )
F_154 ( V_4 , 0 , - 1 ) ;
F_155 ( V_4 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_193:
F_19 ( V_4 ) ;
}
F_32 ( V_42 ) ;
return V_49 ;
}
static inline T_9 F_156 ( V_114 V_194 , V_114 V_79 )
{
return ( T_9 ) { . V_195 = ( V_194 & V_196 ) | V_79 } ;
}
static int F_157 ( unsigned long V_119 , T_9 * V_195 ,
struct V_197 * V_198 )
{
V_198 -> V_181 [ V_198 -> V_56 ++ ] = * V_195 ;
if ( V_198 -> V_56 >= V_198 -> V_199 )
return V_200 ;
return 0 ;
}
static int F_158 ( unsigned long V_83 , unsigned long V_84 ,
struct V_120 * V_121 )
{
struct V_197 * V_198 = V_121 -> V_52 ;
unsigned long V_119 = V_83 ;
int V_69 = 0 ;
while ( V_119 < V_84 ) {
struct V_45 * V_46 = F_28 ( V_121 -> V_4 , V_119 ) ;
T_9 V_195 = F_156 ( 0 , 0 ) ;
unsigned long V_201 ;
if ( V_46 )
V_201 = F_159 ( V_84 , V_46 -> V_53 ) ;
else
V_201 = V_84 ;
for (; V_119 < V_201 ; V_119 += V_35 ) {
V_69 = F_157 ( V_119 , & V_195 , V_198 ) ;
if ( V_69 )
goto V_177;
}
if ( ! V_46 )
break;
if ( V_46 -> V_80 & V_155 )
V_195 = F_156 ( 0 , V_202 ) ;
for (; V_119 < F_159 ( V_84 , V_46 -> V_76 ) ; V_119 += V_35 ) {
V_69 = F_157 ( V_119 , & V_195 , V_198 ) ;
if ( V_69 )
goto V_177;
}
}
V_177:
return V_69 ;
}
static T_9 F_160 ( struct V_197 * V_198 ,
struct V_45 * V_46 , unsigned long V_119 , V_27 V_123 )
{
V_114 V_194 = 0 , V_79 = 0 ;
struct V_103 * V_103 = NULL ;
if ( F_76 ( V_123 ) ) {
if ( V_198 -> V_203 )
V_194 = F_161 ( V_123 ) ;
V_79 |= V_204 ;
V_103 = F_77 ( V_46 , V_119 , V_123 ) ;
if ( F_162 ( V_123 ) )
V_79 |= V_202 ;
} else if ( F_78 ( V_123 ) ) {
T_4 V_205 ;
if ( F_163 ( V_123 ) )
V_79 |= V_202 ;
V_205 = F_79 ( V_123 ) ;
V_194 = F_164 ( V_205 ) |
( F_165 ( V_205 ) << V_206 ) ;
V_79 |= V_207 ;
if ( F_83 ( V_205 ) )
V_103 = F_84 ( V_205 ) ;
}
if ( V_103 && ! F_67 ( V_103 ) )
V_79 |= V_208 ;
if ( V_103 && F_72 ( V_103 ) == 1 )
V_79 |= V_209 ;
if ( V_46 -> V_80 & V_155 )
V_79 |= V_202 ;
return F_156 ( V_194 , V_79 ) ;
}
static int F_166 ( V_30 * V_173 , unsigned long V_119 , unsigned long V_84 ,
struct V_120 * V_121 )
{
struct V_45 * V_46 = V_121 -> V_46 ;
struct V_197 * V_198 = V_121 -> V_52 ;
T_5 * V_133 ;
V_27 * V_123 , * V_210 ;
int V_69 = 0 ;
#ifdef F_167
V_133 = F_99 ( V_173 , V_46 ) ;
if ( V_133 ) {
V_114 V_79 = 0 , V_194 = 0 ;
V_30 V_129 = * V_173 ;
if ( ( V_46 -> V_80 & V_155 ) || F_168 ( V_129 ) )
V_79 |= V_202 ;
if ( F_169 ( V_129 ) ) {
struct V_103 * V_103 = F_136 ( V_129 ) ;
if ( F_72 ( V_103 ) == 1 )
V_79 |= V_209 ;
V_79 |= V_204 ;
if ( V_198 -> V_203 )
V_194 = F_170 ( V_129 ) +
( ( V_119 & ~ V_211 ) >> V_24 ) ;
}
for (; V_119 != V_84 ; V_119 += V_35 ) {
T_9 V_195 = F_156 ( V_194 , V_79 ) ;
V_69 = F_157 ( V_119 , & V_195 , V_198 ) ;
if ( V_69 )
break;
if ( V_198 -> V_203 && ( V_79 & V_204 ) )
V_194 ++ ;
}
F_100 ( V_133 ) ;
return V_69 ;
}
if ( F_101 ( V_173 ) )
return 0 ;
#endif
V_210 = V_123 = F_102 ( V_121 -> V_4 , V_173 , V_119 , & V_133 ) ;
for (; V_119 < V_84 ; V_123 ++ , V_119 += V_35 ) {
T_9 V_195 ;
V_195 = F_160 ( V_198 , V_46 , V_119 , * V_123 ) ;
V_69 = F_157 ( V_119 , & V_195 , V_198 ) ;
if ( V_69 )
break;
}
F_103 ( V_210 , V_133 ) ;
F_104 () ;
return V_69 ;
}
static int F_171 ( V_27 * V_212 , unsigned long V_162 ,
unsigned long V_119 , unsigned long V_84 ,
struct V_120 * V_121 )
{
struct V_197 * V_198 = V_121 -> V_52 ;
struct V_45 * V_46 = V_121 -> V_46 ;
V_114 V_79 = 0 , V_194 = 0 ;
int V_69 = 0 ;
V_27 V_123 ;
if ( V_46 -> V_80 & V_155 )
V_79 |= V_202 ;
V_123 = F_172 ( V_212 ) ;
if ( F_76 ( V_123 ) ) {
struct V_103 * V_103 = F_173 ( V_123 ) ;
if ( ! F_67 ( V_103 ) )
V_79 |= V_208 ;
if ( F_72 ( V_103 ) == 1 )
V_79 |= V_209 ;
V_79 |= V_204 ;
if ( V_198 -> V_203 )
V_194 = F_161 ( V_123 ) +
( ( V_119 & ~ V_162 ) >> V_24 ) ;
}
for (; V_119 != V_84 ; V_119 += V_35 ) {
T_9 V_195 = F_156 ( V_194 , V_79 ) ;
V_69 = F_157 ( V_119 , & V_195 , V_198 ) ;
if ( V_69 )
return V_69 ;
if ( V_198 -> V_203 && ( V_79 & V_204 ) )
V_194 ++ ;
}
F_104 () ;
return V_69 ;
}
static T_7 F_174 ( struct V_11 * V_11 , char T_8 * V_180 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_3 * V_4 = V_11 -> V_71 ;
struct V_197 V_198 ;
struct V_120 V_213 = {} ;
unsigned long V_214 ;
unsigned long V_215 ;
unsigned long V_216 ;
unsigned long V_217 ;
int V_218 = 0 , V_219 = 0 ;
if ( ! V_4 || ! F_25 ( & V_4 -> V_59 ) )
goto V_177;
V_218 = - V_189 ;
if ( ( * V_54 % V_220 ) || ( V_49 % V_220 ) )
goto V_193;
V_218 = 0 ;
if ( ! V_49 )
goto V_193;
V_198 . V_203 = F_175 ( V_11 , & V_221 , V_222 ) ;
V_198 . V_199 = ( V_223 >> V_24 ) ;
V_198 . V_181 = F_176 ( V_198 . V_199 * V_220 , V_224 ) ;
V_218 = - V_67 ;
if ( ! V_198 . V_181 )
goto V_193;
V_213 . V_166 = F_166 ;
V_213 . V_169 = F_158 ;
#ifdef F_113
V_213 . V_167 = F_171 ;
#endif
V_213 . V_4 = V_4 ;
V_213 . V_52 = & V_198 ;
V_214 = * V_54 ;
V_215 = V_214 / V_220 ;
V_216 = V_215 << V_24 ;
V_217 = V_4 -> V_225 ;
if ( V_215 > V_4 -> V_225 >> V_24 )
V_216 = V_217 ;
V_218 = 0 ;
while ( V_49 && ( V_216 < V_217 ) ) {
int V_199 ;
unsigned long V_84 ;
V_198 . V_56 = 0 ;
V_84 = ( V_216 + V_223 ) & V_226 ;
if ( V_84 < V_216 || V_84 > V_217 )
V_84 = V_217 ;
F_26 ( & V_4 -> V_44 ) ;
V_218 = F_153 ( V_216 , V_84 , & V_213 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_216 = V_84 ;
V_199 = F_159 ( V_49 , V_220 * V_198 . V_56 ) ;
if ( F_177 ( V_180 , V_198 . V_181 , V_199 ) ) {
V_218 = - V_186 ;
goto V_227;
}
V_219 += V_199 ;
V_180 += V_199 ;
V_49 -= V_199 ;
}
* V_54 += V_219 ;
if ( ! V_218 || V_218 == V_200 )
V_218 = V_219 ;
V_227:
F_178 ( V_198 . V_181 ) ;
V_193:
F_19 ( V_4 ) ;
V_177:
return V_218 ;
}
static int F_179 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_57 , V_68 ) ;
if ( F_36 ( V_4 ) )
return F_37 ( V_4 ) ;
V_11 -> V_71 = V_4 ;
return 0 ;
}
static int F_180 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_71 ;
if ( V_4 )
F_40 ( V_4 ) ;
return 0 ;
}
static void F_181 ( struct V_103 * V_103 , struct V_228 * V_229 , int F_93 ,
unsigned long V_230 )
{
int V_49 = F_72 ( V_103 ) ;
V_229 -> V_231 += V_230 ;
if ( F_93 || F_71 ( V_103 ) )
V_229 -> V_106 += V_230 ;
if ( F_182 ( V_103 ) )
V_229 -> V_232 += V_230 ;
if ( F_183 ( V_103 ) || F_184 ( V_103 ) )
V_229 -> V_233 += V_230 ;
if ( F_185 ( V_103 ) )
V_229 -> V_234 += V_230 ;
if ( F_67 ( V_103 ) )
V_229 -> V_10 += V_230 ;
if ( V_49 > V_229 -> V_235 )
V_229 -> V_235 = V_49 ;
V_229 -> V_236 [ F_186 ( V_103 ) ] += V_230 ;
}
static struct V_103 * F_187 ( V_27 V_123 , struct V_45 * V_46 ,
unsigned long V_119 )
{
struct V_103 * V_103 ;
int V_237 ;
if ( ! F_76 ( V_123 ) )
return NULL ;
V_103 = F_77 ( V_46 , V_119 , V_123 ) ;
if ( ! V_103 )
return NULL ;
if ( F_188 ( V_103 ) )
return NULL ;
V_237 = F_186 ( V_103 ) ;
if ( ! F_189 ( V_237 , V_238 [ V_239 ] ) )
return NULL ;
return V_103 ;
}
static int F_190 ( V_30 * V_129 , unsigned long V_119 ,
unsigned long V_84 , struct V_120 * V_121 )
{
struct V_228 * V_229 = V_121 -> V_52 ;
struct V_45 * V_46 = V_121 -> V_46 ;
T_5 * V_133 ;
V_27 * V_210 ;
V_27 * V_123 ;
V_133 = F_99 ( V_129 , V_46 ) ;
if ( V_133 ) {
V_27 V_240 = * ( V_27 * ) V_129 ;
struct V_103 * V_103 ;
V_103 = F_187 ( V_240 , V_46 , V_119 ) ;
if ( V_103 )
F_181 ( V_103 , V_229 , F_93 ( V_240 ) ,
V_132 / V_35 ) ;
F_100 ( V_133 ) ;
return 0 ;
}
if ( F_101 ( V_129 ) )
return 0 ;
V_210 = V_123 = F_102 ( V_121 -> V_4 , V_129 , V_119 , & V_133 ) ;
do {
struct V_103 * V_103 = F_187 ( * V_123 , V_46 , V_119 ) ;
if ( ! V_103 )
continue;
F_181 ( V_103 , V_229 , F_93 ( * V_123 ) , 1 ) ;
} while ( V_123 ++ , V_119 += V_35 , V_119 != V_84 );
F_103 ( V_210 , V_133 ) ;
return 0 ;
}
static int F_191 ( V_27 * V_123 , unsigned long V_162 ,
unsigned long V_119 , unsigned long V_84 , struct V_120 * V_121 )
{
V_27 V_240 = F_172 ( V_123 ) ;
struct V_228 * V_229 ;
struct V_103 * V_103 ;
if ( ! F_76 ( V_240 ) )
return 0 ;
V_103 = F_173 ( V_240 ) ;
if ( ! V_103 )
return 0 ;
V_229 = V_121 -> V_52 ;
F_181 ( V_103 , V_229 , F_93 ( V_240 ) , 1 ) ;
return 0 ;
}
static int F_191 ( V_27 * V_123 , unsigned long V_162 ,
unsigned long V_119 , unsigned long V_84 , struct V_120 * V_121 )
{
return 0 ;
}
static int F_192 ( struct V_1 * V_2 , void * V_62 , int V_72 )
{
struct V_241 * V_242 = V_2 -> V_52 ;
struct V_39 * V_243 = & V_242 -> V_244 ;
struct V_45 * V_46 = V_62 ;
struct V_228 * V_229 = & V_242 -> V_229 ;
struct V_11 * V_11 = V_46 -> V_78 ;
struct V_3 * V_4 = V_46 -> V_74 ;
struct V_120 V_121 = {
. V_167 = F_191 ,
. V_166 = F_190 ,
. V_52 = V_229 ,
. V_4 = V_4 ,
} ;
struct V_245 * V_246 ;
char V_181 [ 64 ] ;
int V_237 ;
if ( ! V_4 )
return 0 ;
memset ( V_229 , 0 , sizeof( * V_229 ) ) ;
V_246 = F_193 ( V_46 , V_46 -> V_53 ) ;
if ( V_246 ) {
F_194 ( V_181 , sizeof( V_181 ) , V_246 ) ;
F_195 ( V_246 ) ;
} else {
F_194 ( V_181 , sizeof( V_181 ) , V_243 -> V_43 ) ;
}
F_6 ( V_2 , L_72 , V_46 -> V_53 , V_181 ) ;
if ( V_11 ) {
F_58 ( V_2 , L_73 ) ;
F_56 ( V_2 , V_11 , L_74 ) ;
} else if ( V_46 -> V_53 <= V_4 -> V_97 && V_46 -> V_76 >= V_4 -> V_98 ) {
F_58 ( V_2 , L_75 ) ;
} else if ( F_42 ( V_243 , V_46 , V_72 ) ) {
F_58 ( V_2 , L_76 ) ;
}
if ( F_196 ( V_46 ) )
F_58 ( V_2 , L_77 ) ;
F_116 ( V_46 , & V_121 ) ;
if ( ! V_229 -> V_231 )
goto V_177;
if ( V_229 -> V_10 )
F_6 ( V_2 , L_78 , V_229 -> V_10 ) ;
if ( V_229 -> V_106 )
F_6 ( V_2 , L_79 , V_229 -> V_106 ) ;
if ( V_229 -> V_231 != V_229 -> V_10 && V_229 -> V_231 != V_229 -> V_106 )
F_6 ( V_2 , L_80 , V_229 -> V_231 ) ;
if ( V_229 -> V_235 > 1 )
F_6 ( V_2 , L_81 , V_229 -> V_235 ) ;
if ( V_229 -> V_232 )
F_6 ( V_2 , L_82 , V_229 -> V_232 ) ;
if ( V_229 -> V_233 < V_229 -> V_231 && ! F_196 ( V_46 ) )
F_6 ( V_2 , L_83 , V_229 -> V_233 ) ;
if ( V_229 -> V_234 )
F_6 ( V_2 , L_84 , V_229 -> V_234 ) ;
F_197 (nid, N_MEMORY)
if ( V_229 -> V_236 [ V_237 ] )
F_6 ( V_2 , L_85 , V_237 , V_229 -> V_236 [ V_237 ] ) ;
F_6 ( V_2 , L_86 , F_117 ( V_46 ) >> 10 ) ;
V_177:
F_59 ( V_2 , '\n' ) ;
F_21 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_2 , void * V_62 )
{
return F_192 ( V_2 , V_62 , 1 ) ;
}
static int F_199 ( struct V_1 * V_2 , void * V_62 )
{
return F_192 ( V_2 , V_62 , 0 ) ;
}
static int F_200 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 )
{
return F_33 ( V_57 , V_11 , V_65 ,
sizeof( struct V_241 ) ) ;
}
static int F_201 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_200 ( V_57 , V_11 , & V_247 ) ;
}
static int F_202 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_200 ( V_57 , V_11 , & V_248 ) ;
}
