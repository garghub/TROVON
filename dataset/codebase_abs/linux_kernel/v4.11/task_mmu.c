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
return F_38 ( V_57 , V_11 ) ;
}
static int F_41 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 )
{
return F_33 ( V_57 , V_11 , V_65 ,
sizeof( struct V_39 ) ) ;
}
static int F_42 ( struct V_39 * V_40 ,
struct V_45 * V_46 )
{
return V_46 -> V_59 <= V_46 -> V_72 -> V_73 &&
V_46 -> V_53 >= V_46 -> V_72 -> V_73 ;
}
static void
F_43 ( struct V_1 * V_2 , struct V_45 * V_46 , int V_74 )
{
struct V_3 * V_4 = V_46 -> V_72 ;
struct V_11 * V_11 = V_46 -> V_75 ;
struct V_39 * V_40 = V_2 -> V_52 ;
T_2 V_76 = V_46 -> V_77 ;
unsigned long V_78 = 0 ;
unsigned long long V_79 = 0 ;
unsigned long V_80 , V_81 ;
T_3 V_82 = 0 ;
const char * V_83 = NULL ;
if ( V_11 ) {
struct V_57 * V_57 = F_44 ( V_46 -> V_75 ) ;
V_82 = V_57 -> V_84 -> V_85 ;
V_78 = V_57 -> V_86 ;
V_79 = ( ( T_1 ) V_46 -> V_87 ) << V_24 ;
}
V_80 = V_46 -> V_59 ;
if ( F_45 ( V_46 , V_80 ) )
V_80 += V_35 ;
V_81 = V_46 -> V_53 ;
if ( F_46 ( V_46 , V_81 ) )
V_81 -= V_35 ;
F_47 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_6 ( V_2 , L_17 ,
V_80 ,
V_81 ,
V_76 & V_88 ? 'r' : '-' ,
V_76 & V_89 ? 'w' : '-' ,
V_76 & V_90 ? 'x' : '-' ,
V_76 & V_91 ? 's' : 'p' ,
V_79 ,
F_48 ( V_82 ) , F_49 ( V_82 ) , V_78 ) ;
if ( V_11 ) {
F_50 ( V_2 , ' ' ) ;
F_51 ( V_2 , V_11 , L_18 ) ;
goto V_92;
}
if ( V_46 -> V_93 && V_46 -> V_93 -> V_83 ) {
V_83 = V_46 -> V_93 -> V_83 ( V_46 ) ;
if ( V_83 )
goto V_92;
}
V_83 = F_52 ( V_46 ) ;
if ( ! V_83 ) {
if ( ! V_4 ) {
V_83 = L_19 ;
goto V_92;
}
if ( V_46 -> V_59 <= V_4 -> V_94 &&
V_46 -> V_53 >= V_4 -> V_95 ) {
V_83 = L_20 ;
goto V_92;
}
if ( F_42 ( V_40 , V_46 ) )
V_83 = L_21 ;
}
V_92:
if ( V_83 ) {
F_50 ( V_2 , ' ' ) ;
F_53 ( V_2 , V_83 ) ;
}
F_54 ( V_2 , '\n' ) ;
}
static int F_55 ( struct V_1 * V_2 , void * V_62 , int V_74 )
{
F_43 ( V_2 , V_62 , V_74 ) ;
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
return F_41 ( V_57 , V_11 , & V_96 ) ;
}
static int F_59 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_97 ) ;
}
static void F_60 ( struct V_98 * V_99 , struct V_100 * V_100 ,
bool V_101 , bool V_102 , bool V_103 )
{
int V_104 , V_105 = V_101 ? 1 << F_61 ( V_100 ) : 1 ;
unsigned long V_50 = V_105 * V_35 ;
if ( F_62 ( V_100 ) )
V_99 -> V_106 += V_50 ;
V_99 -> V_38 += V_50 ;
if ( V_102 || F_63 ( V_100 ) || F_64 ( V_100 ) )
V_99 -> V_107 += V_50 ;
if ( F_65 ( V_100 ) == 1 ) {
if ( V_103 || F_66 ( V_100 ) )
V_99 -> V_108 += V_50 ;
else
V_99 -> V_109 += V_50 ;
V_99 -> V_110 += ( V_111 ) V_50 << V_112 ;
return;
}
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ , V_100 ++ ) {
int V_113 = F_67 ( V_100 ) ;
if ( V_113 >= 2 ) {
if ( V_103 || F_66 ( V_100 ) )
V_99 -> V_114 += V_35 ;
else
V_99 -> V_115 += V_35 ;
V_99 -> V_110 += ( V_35 << V_112 ) / V_113 ;
} else {
if ( V_103 || F_66 ( V_100 ) )
V_99 -> V_108 += V_35 ;
else
V_99 -> V_109 += V_35 ;
V_99 -> V_110 += V_35 << V_112 ;
}
}
}
static int F_68 ( unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_98 * V_99 = V_118 -> V_52 ;
V_99 -> V_7 += F_69 (
V_118 -> V_46 -> V_75 -> V_119 , V_116 , V_81 ) ;
return 0 ;
}
static void F_70 ( V_27 * V_120 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_98 * V_99 = V_118 -> V_52 ;
struct V_45 * V_46 = V_118 -> V_46 ;
struct V_100 * V_100 = NULL ;
if ( F_71 ( * V_120 ) ) {
V_100 = F_72 ( V_46 , V_116 , * V_120 ) ;
} else if ( F_73 ( * V_120 ) ) {
T_4 V_121 = F_74 ( * V_120 ) ;
if ( ! F_75 ( V_121 ) ) {
int V_113 ;
V_99 -> V_7 += V_35 ;
V_113 = F_76 ( V_121 ) ;
if ( V_113 >= 2 ) {
V_111 V_122 = ( V_111 ) V_35 << V_112 ;
F_77 ( V_122 , V_113 ) ;
V_99 -> V_123 += V_122 ;
} else {
V_99 -> V_123 += ( V_111 ) V_35 << V_112 ;
}
} else if ( F_78 ( V_121 ) )
V_100 = F_79 ( V_121 ) ;
} else if ( F_80 ( F_81 ( V_124 ) && V_99 -> V_125
&& F_82 ( * V_120 ) ) ) {
V_100 = F_83 ( V_46 -> V_75 -> V_119 ,
F_84 ( V_46 , V_116 ) ) ;
if ( ! V_100 )
return;
if ( F_85 ( V_100 ) )
V_99 -> V_7 += V_35 ;
else
F_86 ( V_100 ) ;
return;
}
if ( ! V_100 )
return;
F_60 ( V_99 , V_100 , false , F_87 ( * V_120 ) , F_88 ( * V_120 ) ) ;
}
static void F_89 ( V_30 * V_126 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_98 * V_99 = V_118 -> V_52 ;
struct V_45 * V_46 = V_118 -> V_46 ;
struct V_100 * V_100 ;
V_100 = F_90 ( V_46 , V_116 , V_126 , V_127 ) ;
if ( F_31 ( V_100 ) )
return;
if ( F_62 ( V_100 ) )
V_99 -> V_128 += V_129 ;
else if ( F_91 ( V_100 ) )
V_99 -> V_130 += V_129 ;
else if ( F_92 ( V_100 ) )
;
else
F_93 ( 1 , V_100 ) ;
F_60 ( V_99 , V_100 , true , F_94 ( * V_126 ) , F_95 ( * V_126 ) ) ;
}
static void F_89 ( V_30 * V_126 , unsigned long V_116 ,
struct V_117 * V_118 )
{
}
static int F_96 ( V_30 * V_126 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_45 * V_46 = V_118 -> V_46 ;
V_27 * V_120 ;
T_5 * V_131 ;
V_131 = F_97 ( V_126 , V_46 ) ;
if ( V_131 ) {
F_89 ( V_126 , V_116 , V_118 ) ;
F_98 ( V_131 ) ;
return 0 ;
}
if ( F_99 ( V_126 ) )
return 0 ;
V_120 = F_100 ( V_46 -> V_72 , V_126 , V_116 , & V_131 ) ;
for (; V_116 != V_81 ; V_120 ++ , V_116 += V_35 )
F_70 ( V_120 , V_116 , V_118 ) ;
F_101 ( V_120 - 1 , V_131 ) ;
F_102 () ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
static const char V_132 [ V_133 ] [ 2 ] = {
[ 0 ... ( V_133 - 1 ) ] = L_22 ,
[ F_104 ( V_88 ) ] = L_23 ,
[ F_104 ( V_89 ) ] = L_24 ,
[ F_104 ( V_90 ) ] = L_25 ,
[ F_104 ( V_134 ) ] = L_26 ,
[ F_104 ( V_135 ) ] = L_27 ,
[ F_104 ( V_136 ) ] = L_28 ,
[ F_104 ( V_137 ) ] = L_29 ,
[ F_104 ( V_91 ) ] = L_30 ,
[ F_104 ( V_138 ) ] = L_31 ,
[ F_104 ( V_139 ) ] = L_32 ,
[ F_104 ( V_140 ) ] = L_33 ,
#ifdef F_105
[ F_104 ( V_141 ) ] = L_34 ,
#endif
[ F_104 ( V_142 ) ] = L_35 ,
[ F_104 ( V_143 ) ] = L_36 ,
[ F_104 ( V_144 ) ] = L_37 ,
[ F_104 ( V_145 ) ] = L_38 ,
[ F_104 ( V_146 ) ] = L_39 ,
[ F_104 ( V_147 ) ] = L_40 ,
[ F_104 ( V_148 ) ] = L_41 ,
[ F_104 ( V_149 ) ] = L_42 ,
[ F_104 ( V_150 ) ] = L_43 ,
[ F_104 ( V_151 ) ] = L_44 ,
[ F_104 ( V_152 ) ] = L_45 ,
#ifdef F_106
[ F_104 ( V_153 ) ] = L_46 ,
#endif
[ F_104 ( V_154 ) ] = L_47 ,
[ F_104 ( V_155 ) ] = L_48 ,
[ F_104 ( V_156 ) ] = L_49 ,
[ F_104 ( V_157 ) ] = L_50 ,
[ F_104 ( V_158 ) ] = L_51 ,
[ F_104 ( V_159 ) ] = L_52 ,
#ifdef F_107
[ F_104 ( V_160 ) ] = L_53 ,
[ F_104 ( V_161 ) ] = L_53 ,
[ F_104 ( V_162 ) ] = L_53 ,
[ F_104 ( V_163 ) ] = L_53 ,
#endif
} ;
T_6 V_104 ;
F_53 ( V_2 , L_54 ) ;
for ( V_104 = 0 ; V_104 < V_133 ; V_104 ++ ) {
if ( ! V_132 [ V_104 ] [ 0 ] )
continue;
if ( V_46 -> V_77 & ( 1UL << V_104 ) ) {
F_6 ( V_2 , L_55 ,
V_132 [ V_104 ] [ 0 ] , V_132 [ V_104 ] [ 1 ] ) ;
}
}
F_54 ( V_2 , '\n' ) ;
}
static int F_108 ( V_27 * V_120 , unsigned long V_164 ,
unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_98 * V_99 = V_118 -> V_52 ;
struct V_45 * V_46 = V_118 -> V_46 ;
struct V_100 * V_100 = NULL ;
if ( F_71 ( * V_120 ) ) {
V_100 = F_72 ( V_46 , V_116 , * V_120 ) ;
} else if ( F_73 ( * V_120 ) ) {
T_4 V_121 = F_74 ( * V_120 ) ;
if ( F_78 ( V_121 ) )
V_100 = F_79 ( V_121 ) ;
}
if ( V_100 ) {
int V_113 = F_67 ( V_100 ) ;
if ( V_113 >= 2 )
V_99 -> V_165 += F_109 ( F_110 ( V_46 ) ) ;
else
V_99 -> V_166 += F_109 ( F_110 ( V_46 ) ) ;
}
return 0 ;
}
void __weak F_111 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
}
static int F_112 ( struct V_1 * V_2 , void * V_62 , int V_74 )
{
struct V_45 * V_46 = V_62 ;
struct V_98 V_99 ;
struct V_117 V_167 = {
. V_168 = F_96 ,
#ifdef F_113
. V_169 = F_108 ,
#endif
. V_4 = V_46 -> V_72 ,
. V_52 = & V_99 ,
} ;
memset ( & V_99 , 0 , sizeof V_99 ) ;
#ifdef V_124
if ( V_46 -> V_75 && F_114 ( V_46 -> V_75 -> V_119 ) ) {
unsigned long V_170 = F_115 ( V_46 ) ;
if ( ! V_170 || ( V_46 -> V_77 & V_134 ) ||
! ( V_46 -> V_77 & V_89 ) ) {
V_99 . V_7 = V_170 ;
} else {
V_99 . V_125 = true ;
V_167 . V_171 = F_68 ;
}
}
#endif
F_116 ( V_46 , & V_167 ) ;
F_43 ( V_2 , V_46 , V_74 ) ;
F_6 ( V_2 ,
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
L_71
L_72
L_73 ,
( V_46 -> V_53 - V_46 -> V_59 ) >> 10 ,
V_99 . V_38 >> 10 ,
( unsigned long ) ( V_99 . V_110 >> ( 10 + V_112 ) ) ,
V_99 . V_115 >> 10 ,
V_99 . V_114 >> 10 ,
V_99 . V_109 >> 10 ,
V_99 . V_108 >> 10 ,
V_99 . V_107 >> 10 ,
V_99 . V_106 >> 10 ,
V_99 . V_128 >> 10 ,
V_99 . V_130 >> 10 ,
V_99 . V_165 >> 10 ,
V_99 . V_166 >> 10 ,
V_99 . V_7 >> 10 ,
( unsigned long ) ( V_99 . V_123 >> ( 10 + V_112 ) ) ,
F_117 ( V_46 ) >> 10 ,
F_118 ( V_46 ) >> 10 ,
( V_46 -> V_77 & V_142 ) ?
( unsigned long ) ( V_99 . V_110 >> ( 10 + V_112 ) ) : 0 ) ;
F_111 ( V_2 , V_46 ) ;
F_103 ( V_2 , V_46 ) ;
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
return F_41 ( V_57 , V_11 , & V_172 ) ;
}
static int F_122 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_173 ) ;
}
static inline void F_123 ( struct V_45 * V_46 ,
unsigned long V_116 , V_27 * V_120 )
{
V_27 V_174 = * V_120 ;
if ( F_71 ( V_174 ) ) {
V_174 = F_124 ( V_46 -> V_72 , V_116 , V_120 ) ;
V_174 = F_125 ( V_174 ) ;
V_174 = F_126 ( V_174 ) ;
F_127 ( V_46 -> V_72 , V_116 , V_120 , V_174 ) ;
} else if ( F_73 ( V_174 ) ) {
V_174 = F_128 ( V_174 ) ;
F_129 ( V_46 -> V_72 , V_116 , V_120 , V_174 ) ;
}
}
static inline void F_123 ( struct V_45 * V_46 ,
unsigned long V_116 , V_27 * V_120 )
{
}
static inline void F_130 ( struct V_45 * V_46 ,
unsigned long V_116 , V_30 * V_175 )
{
V_30 V_126 = * V_175 ;
F_131 ( V_46 , V_116 , V_175 ) ;
if ( F_95 ( * V_175 ) )
V_126 = F_132 ( V_126 ) ;
if ( F_94 ( * V_175 ) )
V_126 = F_133 ( V_126 ) ;
V_126 = F_134 ( V_126 ) ;
V_126 = F_135 ( V_126 ) ;
F_136 ( V_46 -> V_72 , V_116 , V_175 , V_126 ) ;
}
static inline void F_130 ( struct V_45 * V_46 ,
unsigned long V_116 , V_30 * V_175 )
{
}
static int F_137 ( V_30 * V_126 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_176 * V_177 = V_118 -> V_52 ;
struct V_45 * V_46 = V_118 -> V_46 ;
V_27 * V_120 , V_174 ;
T_5 * V_131 ;
struct V_100 * V_100 ;
V_131 = F_97 ( V_126 , V_46 ) ;
if ( V_131 ) {
if ( V_177 -> type == V_178 ) {
F_130 ( V_46 , V_116 , V_126 ) ;
goto V_179;
}
V_100 = F_138 ( * V_126 ) ;
F_139 ( V_46 , V_116 , V_126 ) ;
F_140 ( V_100 ) ;
F_141 ( V_100 ) ;
V_179:
F_98 ( V_131 ) ;
return 0 ;
}
if ( F_99 ( V_126 ) )
return 0 ;
V_120 = F_100 ( V_46 -> V_72 , V_126 , V_116 , & V_131 ) ;
for (; V_116 != V_81 ; V_120 ++ , V_116 += V_35 ) {
V_174 = * V_120 ;
if ( V_177 -> type == V_178 ) {
F_123 ( V_46 , V_116 , V_120 ) ;
continue;
}
if ( ! F_71 ( V_174 ) )
continue;
V_100 = F_72 ( V_46 , V_116 , V_174 ) ;
if ( ! V_100 )
continue;
F_142 ( V_46 , V_116 , V_120 ) ;
F_140 ( V_100 ) ;
F_141 ( V_100 ) ;
}
F_101 ( V_120 - 1 , V_131 ) ;
F_102 () ;
return 0 ;
}
static int F_143 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_176 * V_177 = V_118 -> V_52 ;
struct V_45 * V_46 = V_118 -> V_46 ;
if ( V_46 -> V_77 & V_139 )
return 1 ;
if ( V_177 -> type == V_180 && V_46 -> V_75 )
return 1 ;
if ( V_177 -> type == V_181 && ! V_46 -> V_75 )
return 1 ;
return 0 ;
}
static T_7 F_144 ( struct V_11 * V_11 , const char T_8 * V_182 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_41 * V_42 ;
char V_183 [ V_184 ] ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
enum V_185 type ;
int V_186 ;
int V_187 ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
if ( V_49 > sizeof( V_183 ) - 1 )
V_49 = sizeof( V_183 ) - 1 ;
if ( F_145 ( V_183 , V_182 , V_49 ) )
return - V_188 ;
V_187 = F_146 ( F_147 ( V_183 ) , 10 , & V_186 ) ;
if ( V_187 < 0 )
return V_187 ;
type = (enum V_185 ) V_186 ;
if ( type < V_189 || type >= V_190 )
return - V_191 ;
V_42 = F_23 ( F_44 ( V_11 ) ) ;
if ( ! V_42 )
return - V_58 ;
V_4 = F_148 ( V_42 ) ;
if ( V_4 ) {
struct V_176 V_177 = {
. type = type ,
} ;
struct V_117 V_192 = {
. V_168 = F_137 ,
. V_193 = F_143 ,
. V_4 = V_4 ,
. V_52 = & V_177 ,
} ;
if ( type == V_194 ) {
if ( F_149 ( & V_4 -> V_44 ) ) {
V_49 = - V_195 ;
goto V_196;
}
F_150 ( V_4 ) ;
F_151 ( & V_4 -> V_44 ) ;
goto V_196;
}
F_26 ( & V_4 -> V_44 ) ;
if ( type == V_178 ) {
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
if ( ! ( V_46 -> V_77 & V_153 ) )
continue;
F_18 ( & V_4 -> V_44 ) ;
if ( F_149 ( & V_4 -> V_44 ) ) {
V_49 = - V_195 ;
goto V_196;
}
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
V_46 -> V_77 &= ~ V_153 ;
F_152 ( V_46 ) ;
}
F_153 ( & V_4 -> V_44 ) ;
break;
}
F_154 ( V_4 , 0 , - 1 ) ;
}
F_155 ( 0 , V_4 -> V_197 , & V_192 ) ;
if ( type == V_178 )
F_156 ( V_4 , 0 , - 1 ) ;
F_157 ( V_4 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_196:
F_19 ( V_4 ) ;
}
F_32 ( V_42 ) ;
return V_49 ;
}
static inline T_9 F_158 ( V_111 V_198 , V_111 V_76 )
{
return ( T_9 ) { . V_199 = ( V_198 & V_200 ) | V_76 } ;
}
static int F_159 ( unsigned long V_116 , T_9 * V_199 ,
struct V_201 * V_202 )
{
V_202 -> V_183 [ V_202 -> V_56 ++ ] = * V_199 ;
if ( V_202 -> V_56 >= V_202 -> V_203 )
return V_204 ;
return 0 ;
}
static int F_160 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_201 * V_202 = V_118 -> V_52 ;
unsigned long V_116 = V_80 ;
int V_69 = 0 ;
while ( V_116 < V_81 ) {
struct V_45 * V_46 = F_28 ( V_118 -> V_4 , V_116 ) ;
T_9 V_199 = F_158 ( 0 , 0 ) ;
unsigned long V_205 ;
if ( V_46 )
V_205 = F_161 ( V_81 , V_46 -> V_59 ) ;
else
V_205 = V_81 ;
for (; V_116 < V_205 ; V_116 += V_35 ) {
V_69 = F_159 ( V_116 , & V_199 , V_202 ) ;
if ( V_69 )
goto V_179;
}
if ( ! V_46 )
break;
if ( V_46 -> V_77 & V_153 )
V_199 = F_158 ( 0 , V_206 ) ;
for (; V_116 < F_161 ( V_81 , V_46 -> V_53 ) ; V_116 += V_35 ) {
V_69 = F_159 ( V_116 , & V_199 , V_202 ) ;
if ( V_69 )
goto V_179;
}
}
V_179:
return V_69 ;
}
static T_9 F_162 ( struct V_201 * V_202 ,
struct V_45 * V_46 , unsigned long V_116 , V_27 V_120 )
{
V_111 V_198 = 0 , V_76 = 0 ;
struct V_100 * V_100 = NULL ;
if ( F_71 ( V_120 ) ) {
if ( V_202 -> V_207 )
V_198 = F_163 ( V_120 ) ;
V_76 |= V_208 ;
V_100 = F_72 ( V_46 , V_116 , V_120 ) ;
if ( F_164 ( V_120 ) )
V_76 |= V_206 ;
} else if ( F_73 ( V_120 ) ) {
T_4 V_209 ;
if ( F_165 ( V_120 ) )
V_76 |= V_206 ;
V_209 = F_74 ( V_120 ) ;
V_198 = F_166 ( V_209 ) |
( F_167 ( V_209 ) << V_210 ) ;
V_76 |= V_211 ;
if ( F_78 ( V_209 ) )
V_100 = F_79 ( V_209 ) ;
}
if ( V_100 && ! F_62 ( V_100 ) )
V_76 |= V_212 ;
if ( V_100 && F_67 ( V_100 ) == 1 )
V_76 |= V_213 ;
if ( V_46 -> V_77 & V_153 )
V_76 |= V_206 ;
return F_158 ( V_198 , V_76 ) ;
}
static int F_168 ( V_30 * V_175 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_45 * V_46 = V_118 -> V_46 ;
struct V_201 * V_202 = V_118 -> V_52 ;
T_5 * V_131 ;
V_27 * V_120 , * V_214 ;
int V_69 = 0 ;
#ifdef F_169
V_131 = F_97 ( V_175 , V_46 ) ;
if ( V_131 ) {
V_111 V_76 = 0 , V_198 = 0 ;
V_30 V_126 = * V_175 ;
if ( ( V_46 -> V_77 & V_153 ) || F_170 ( V_126 ) )
V_76 |= V_206 ;
if ( F_171 ( V_126 ) ) {
struct V_100 * V_100 = F_138 ( V_126 ) ;
if ( F_67 ( V_100 ) == 1 )
V_76 |= V_213 ;
V_76 |= V_208 ;
if ( V_202 -> V_207 )
V_198 = F_172 ( V_126 ) +
( ( V_116 & ~ V_215 ) >> V_24 ) ;
}
for (; V_116 != V_81 ; V_116 += V_35 ) {
T_9 V_199 = F_158 ( V_198 , V_76 ) ;
V_69 = F_159 ( V_116 , & V_199 , V_202 ) ;
if ( V_69 )
break;
if ( V_202 -> V_207 && ( V_76 & V_208 ) )
V_198 ++ ;
}
F_98 ( V_131 ) ;
return V_69 ;
}
if ( F_99 ( V_175 ) )
return 0 ;
#endif
V_214 = V_120 = F_100 ( V_118 -> V_4 , V_175 , V_116 , & V_131 ) ;
for (; V_116 < V_81 ; V_120 ++ , V_116 += V_35 ) {
T_9 V_199 ;
V_199 = F_162 ( V_202 , V_46 , V_116 , * V_120 ) ;
V_69 = F_159 ( V_116 , & V_199 , V_202 ) ;
if ( V_69 )
break;
}
F_101 ( V_214 , V_131 ) ;
F_102 () ;
return V_69 ;
}
static int F_173 ( V_27 * V_216 , unsigned long V_164 ,
unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_201 * V_202 = V_118 -> V_52 ;
struct V_45 * V_46 = V_118 -> V_46 ;
V_111 V_76 = 0 , V_198 = 0 ;
int V_69 = 0 ;
V_27 V_120 ;
if ( V_46 -> V_77 & V_153 )
V_76 |= V_206 ;
V_120 = F_174 ( V_216 ) ;
if ( F_71 ( V_120 ) ) {
struct V_100 * V_100 = F_175 ( V_120 ) ;
if ( ! F_62 ( V_100 ) )
V_76 |= V_212 ;
if ( F_67 ( V_100 ) == 1 )
V_76 |= V_213 ;
V_76 |= V_208 ;
if ( V_202 -> V_207 )
V_198 = F_163 ( V_120 ) +
( ( V_116 & ~ V_164 ) >> V_24 ) ;
}
for (; V_116 != V_81 ; V_116 += V_35 ) {
T_9 V_199 = F_158 ( V_198 , V_76 ) ;
V_69 = F_159 ( V_116 , & V_199 , V_202 ) ;
if ( V_69 )
return V_69 ;
if ( V_202 -> V_207 && ( V_76 & V_208 ) )
V_198 ++ ;
}
F_102 () ;
return V_69 ;
}
static T_7 F_176 ( struct V_11 * V_11 , char T_8 * V_182 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_3 * V_4 = V_11 -> V_71 ;
struct V_201 V_202 ;
struct V_117 V_217 = {} ;
unsigned long V_218 ;
unsigned long V_219 ;
unsigned long V_220 ;
unsigned long V_221 ;
int V_222 = 0 , V_223 = 0 ;
if ( ! V_4 || ! F_25 ( V_4 ) )
goto V_179;
V_222 = - V_191 ;
if ( ( * V_54 % V_224 ) || ( V_49 % V_224 ) )
goto V_196;
V_222 = 0 ;
if ( ! V_49 )
goto V_196;
V_202 . V_207 = F_177 ( V_11 , & V_225 , V_226 ) ;
V_202 . V_203 = ( V_227 >> V_24 ) ;
V_202 . V_183 = F_178 ( V_202 . V_203 * V_224 , V_228 ) ;
V_222 = - V_67 ;
if ( ! V_202 . V_183 )
goto V_196;
V_217 . V_168 = F_168 ;
V_217 . V_171 = F_160 ;
#ifdef F_113
V_217 . V_169 = F_173 ;
#endif
V_217 . V_4 = V_4 ;
V_217 . V_52 = & V_202 ;
V_218 = * V_54 ;
V_219 = V_218 / V_224 ;
V_220 = V_219 << V_24 ;
V_221 = V_4 -> V_229 ;
if ( V_219 > V_4 -> V_229 >> V_24 )
V_220 = V_221 ;
V_222 = 0 ;
while ( V_49 && ( V_220 < V_221 ) ) {
int V_203 ;
unsigned long V_81 ;
V_202 . V_56 = 0 ;
V_81 = ( V_220 + V_227 ) & V_230 ;
if ( V_81 < V_220 || V_81 > V_221 )
V_81 = V_221 ;
F_26 ( & V_4 -> V_44 ) ;
V_222 = F_155 ( V_220 , V_81 , & V_217 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_220 = V_81 ;
V_203 = F_161 ( V_49 , V_224 * V_202 . V_56 ) ;
if ( F_179 ( V_182 , V_202 . V_183 , V_203 ) ) {
V_222 = - V_188 ;
goto V_231;
}
V_223 += V_203 ;
V_182 += V_203 ;
V_49 -= V_203 ;
}
* V_54 += V_223 ;
if ( ! V_222 || V_222 == V_204 )
V_222 = V_223 ;
V_231:
F_180 ( V_202 . V_183 ) ;
V_196:
F_19 ( V_4 ) ;
V_179:
return V_222 ;
}
static int F_181 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_57 , V_68 ) ;
if ( F_36 ( V_4 ) )
return F_37 ( V_4 ) ;
V_11 -> V_71 = V_4 ;
return 0 ;
}
static int F_182 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_71 ;
if ( V_4 )
F_40 ( V_4 ) ;
return 0 ;
}
static void F_183 ( struct V_100 * V_100 , struct V_232 * V_233 , int F_88 ,
unsigned long V_234 )
{
int V_49 = F_67 ( V_100 ) ;
V_233 -> V_235 += V_234 ;
if ( F_88 || F_66 ( V_100 ) )
V_233 -> V_103 += V_234 ;
if ( F_184 ( V_100 ) )
V_233 -> V_236 += V_234 ;
if ( F_185 ( V_100 ) || F_186 ( V_100 ) )
V_233 -> V_237 += V_234 ;
if ( F_187 ( V_100 ) )
V_233 -> V_238 += V_234 ;
if ( F_62 ( V_100 ) )
V_233 -> V_10 += V_234 ;
if ( V_49 > V_233 -> V_239 )
V_233 -> V_239 = V_49 ;
V_233 -> V_240 [ F_188 ( V_100 ) ] += V_234 ;
}
static struct V_100 * F_189 ( V_27 V_120 , struct V_45 * V_46 ,
unsigned long V_116 )
{
struct V_100 * V_100 ;
int V_241 ;
if ( ! F_71 ( V_120 ) )
return NULL ;
V_100 = F_72 ( V_46 , V_116 , V_120 ) ;
if ( ! V_100 )
return NULL ;
if ( F_190 ( V_100 ) )
return NULL ;
V_241 = F_188 ( V_100 ) ;
if ( ! F_191 ( V_241 , V_242 [ V_243 ] ) )
return NULL ;
return V_100 ;
}
static struct V_100 * F_192 ( V_30 V_126 ,
struct V_45 * V_46 ,
unsigned long V_116 )
{
struct V_100 * V_100 ;
int V_241 ;
if ( ! F_171 ( V_126 ) )
return NULL ;
V_100 = F_193 ( V_46 , V_116 , V_126 ) ;
if ( ! V_100 )
return NULL ;
if ( F_190 ( V_100 ) )
return NULL ;
V_241 = F_188 ( V_100 ) ;
if ( ! F_191 ( V_241 , V_242 [ V_243 ] ) )
return NULL ;
return V_100 ;
}
static int F_194 ( V_30 * V_126 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_232 * V_233 = V_118 -> V_52 ;
struct V_45 * V_46 = V_118 -> V_46 ;
T_5 * V_131 ;
V_27 * V_214 ;
V_27 * V_120 ;
#ifdef F_169
V_131 = F_97 ( V_126 , V_46 ) ;
if ( V_131 ) {
struct V_100 * V_100 ;
V_100 = F_192 ( * V_126 , V_46 , V_116 ) ;
if ( V_100 )
F_183 ( V_100 , V_233 , F_95 ( * V_126 ) ,
V_129 / V_35 ) ;
F_98 ( V_131 ) ;
return 0 ;
}
if ( F_99 ( V_126 ) )
return 0 ;
#endif
V_214 = V_120 = F_100 ( V_118 -> V_4 , V_126 , V_116 , & V_131 ) ;
do {
struct V_100 * V_100 = F_189 ( * V_120 , V_46 , V_116 ) ;
if ( ! V_100 )
continue;
F_183 ( V_100 , V_233 , F_88 ( * V_120 ) , 1 ) ;
} while ( V_120 ++ , V_116 += V_35 , V_116 != V_81 );
F_101 ( V_214 , V_131 ) ;
F_102 () ;
return 0 ;
}
static int F_195 ( V_27 * V_120 , unsigned long V_164 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
V_27 V_244 = F_174 ( V_120 ) ;
struct V_232 * V_233 ;
struct V_100 * V_100 ;
if ( ! F_71 ( V_244 ) )
return 0 ;
V_100 = F_175 ( V_244 ) ;
if ( ! V_100 )
return 0 ;
V_233 = V_118 -> V_52 ;
F_183 ( V_100 , V_233 , F_88 ( V_244 ) , 1 ) ;
return 0 ;
}
static int F_195 ( V_27 * V_120 , unsigned long V_164 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
return 0 ;
}
static int F_196 ( struct V_1 * V_2 , void * V_62 , int V_74 )
{
struct V_245 * V_246 = V_2 -> V_52 ;
struct V_39 * V_247 = & V_246 -> V_248 ;
struct V_45 * V_46 = V_62 ;
struct V_232 * V_233 = & V_246 -> V_233 ;
struct V_11 * V_11 = V_46 -> V_75 ;
struct V_3 * V_4 = V_46 -> V_72 ;
struct V_117 V_118 = {
. V_169 = F_195 ,
. V_168 = F_194 ,
. V_52 = V_233 ,
. V_4 = V_4 ,
} ;
struct V_249 * V_250 ;
char V_183 [ 64 ] ;
int V_241 ;
if ( ! V_4 )
return 0 ;
memset ( V_233 , 0 , sizeof( * V_233 ) ) ;
V_250 = F_197 ( V_46 , V_46 -> V_59 ) ;
if ( V_250 ) {
F_198 ( V_183 , sizeof( V_183 ) , V_250 ) ;
F_199 ( V_250 ) ;
} else {
F_198 ( V_183 , sizeof( V_183 ) , V_247 -> V_43 ) ;
}
F_6 ( V_2 , L_74 , V_46 -> V_59 , V_183 ) ;
if ( V_11 ) {
F_53 ( V_2 , L_75 ) ;
F_51 ( V_2 , V_11 , L_76 ) ;
} else if ( V_46 -> V_59 <= V_4 -> V_94 && V_46 -> V_53 >= V_4 -> V_95 ) {
F_53 ( V_2 , L_77 ) ;
} else if ( F_42 ( V_247 , V_46 ) ) {
F_53 ( V_2 , L_78 ) ;
}
if ( F_200 ( V_46 ) )
F_53 ( V_2 , L_79 ) ;
F_116 ( V_46 , & V_118 ) ;
if ( ! V_233 -> V_235 )
goto V_179;
if ( V_233 -> V_10 )
F_6 ( V_2 , L_80 , V_233 -> V_10 ) ;
if ( V_233 -> V_103 )
F_6 ( V_2 , L_81 , V_233 -> V_103 ) ;
if ( V_233 -> V_235 != V_233 -> V_10 && V_233 -> V_235 != V_233 -> V_103 )
F_6 ( V_2 , L_82 , V_233 -> V_235 ) ;
if ( V_233 -> V_239 > 1 )
F_6 ( V_2 , L_83 , V_233 -> V_239 ) ;
if ( V_233 -> V_236 )
F_6 ( V_2 , L_84 , V_233 -> V_236 ) ;
if ( V_233 -> V_237 < V_233 -> V_235 && ! F_200 ( V_46 ) )
F_6 ( V_2 , L_85 , V_233 -> V_237 ) ;
if ( V_233 -> V_238 )
F_6 ( V_2 , L_86 , V_233 -> V_238 ) ;
F_201 (nid, N_MEMORY)
if ( V_233 -> V_240 [ V_241 ] )
F_6 ( V_2 , L_87 , V_241 , V_233 -> V_240 [ V_241 ] ) ;
F_6 ( V_2 , L_88 , F_117 ( V_46 ) >> 10 ) ;
V_179:
F_54 ( V_2 , '\n' ) ;
F_21 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_2 , void * V_62 )
{
return F_196 ( V_2 , V_62 , 1 ) ;
}
static int F_203 ( struct V_1 * V_2 , void * V_62 )
{
return F_196 ( V_2 , V_62 , 0 ) ;
}
static int F_204 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 )
{
return F_33 ( V_57 , V_11 , V_65 ,
sizeof( struct V_245 ) ) ;
}
static int F_205 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_204 ( V_57 , V_11 , & V_251 ) ;
}
static int F_206 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_204 ( V_57 , V_11 , & V_252 ) ;
}
