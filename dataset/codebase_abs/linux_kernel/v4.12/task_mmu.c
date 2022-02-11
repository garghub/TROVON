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
V_81 = V_46 -> V_53 ;
F_45 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_6 ( V_2 , L_17 ,
V_80 ,
V_81 ,
V_76 & V_88 ? 'r' : '-' ,
V_76 & V_89 ? 'w' : '-' ,
V_76 & V_90 ? 'x' : '-' ,
V_76 & V_91 ? 's' : 'p' ,
V_79 ,
F_46 ( V_82 ) , F_47 ( V_82 ) , V_78 ) ;
if ( V_11 ) {
F_48 ( V_2 , ' ' ) ;
F_49 ( V_2 , V_11 , L_18 ) ;
goto V_92;
}
if ( V_46 -> V_93 && V_46 -> V_93 -> V_83 ) {
V_83 = V_46 -> V_93 -> V_83 ( V_46 ) ;
if ( V_83 )
goto V_92;
}
V_83 = F_50 ( V_46 ) ;
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
F_48 ( V_2 , ' ' ) ;
F_51 ( V_2 , V_83 ) ;
}
F_52 ( V_2 , '\n' ) ;
}
static int F_53 ( struct V_1 * V_2 , void * V_62 , int V_74 )
{
F_43 ( V_2 , V_62 , V_74 ) ;
F_21 ( V_2 , V_62 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , void * V_62 )
{
return F_53 ( V_2 , V_62 , 1 ) ;
}
static int F_55 ( struct V_1 * V_2 , void * V_62 )
{
return F_53 ( V_2 , V_62 , 0 ) ;
}
static int F_56 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_96 ) ;
}
static int F_57 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_97 ) ;
}
static void F_58 ( struct V_98 * V_99 , struct V_100 * V_100 ,
bool V_101 , bool V_102 , bool V_103 )
{
int V_104 , V_105 = V_101 ? 1 << F_59 ( V_100 ) : 1 ;
unsigned long V_50 = V_105 * V_35 ;
if ( F_60 ( V_100 ) ) {
V_99 -> V_106 += V_50 ;
if ( ! F_61 ( V_100 ) && ! V_103 && ! F_62 ( V_100 ) )
V_99 -> V_107 += V_50 ;
}
V_99 -> V_38 += V_50 ;
if ( V_102 || F_63 ( V_100 ) || F_64 ( V_100 ) )
V_99 -> V_108 += V_50 ;
if ( F_65 ( V_100 ) == 1 ) {
if ( V_103 || F_62 ( V_100 ) )
V_99 -> V_109 += V_50 ;
else
V_99 -> V_110 += V_50 ;
V_99 -> V_111 += ( V_112 ) V_50 << V_113 ;
return;
}
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ , V_100 ++ ) {
int V_114 = F_66 ( V_100 ) ;
if ( V_114 >= 2 ) {
if ( V_103 || F_62 ( V_100 ) )
V_99 -> V_115 += V_35 ;
else
V_99 -> V_116 += V_35 ;
V_99 -> V_111 += ( V_35 << V_113 ) / V_114 ;
} else {
if ( V_103 || F_62 ( V_100 ) )
V_99 -> V_109 += V_35 ;
else
V_99 -> V_110 += V_35 ;
V_99 -> V_111 += V_35 << V_113 ;
}
}
}
static int F_67 ( unsigned long V_117 , unsigned long V_81 ,
struct V_118 * V_119 )
{
struct V_98 * V_99 = V_119 -> V_52 ;
V_99 -> V_7 += F_68 (
V_119 -> V_46 -> V_75 -> V_120 , V_117 , V_81 ) ;
return 0 ;
}
static void F_69 ( V_27 * V_121 , unsigned long V_117 ,
struct V_118 * V_119 )
{
struct V_98 * V_99 = V_119 -> V_52 ;
struct V_45 * V_46 = V_119 -> V_46 ;
struct V_100 * V_100 = NULL ;
if ( F_70 ( * V_121 ) ) {
V_100 = F_71 ( V_46 , V_117 , * V_121 ) ;
} else if ( F_72 ( * V_121 ) ) {
T_4 V_122 = F_73 ( * V_121 ) ;
if ( ! F_74 ( V_122 ) ) {
int V_114 ;
V_99 -> V_7 += V_35 ;
V_114 = F_75 ( V_122 ) ;
if ( V_114 >= 2 ) {
V_112 V_123 = ( V_112 ) V_35 << V_113 ;
F_76 ( V_123 , V_114 ) ;
V_99 -> V_124 += V_123 ;
} else {
V_99 -> V_124 += ( V_112 ) V_35 << V_113 ;
}
} else if ( F_77 ( V_122 ) )
V_100 = F_78 ( V_122 ) ;
} else if ( F_79 ( F_80 ( V_125 ) && V_99 -> V_126
&& F_81 ( * V_121 ) ) ) {
V_100 = F_82 ( V_46 -> V_75 -> V_120 ,
F_83 ( V_46 , V_117 ) ) ;
if ( ! V_100 )
return;
if ( F_84 ( V_100 ) )
V_99 -> V_7 += V_35 ;
else
F_85 ( V_100 ) ;
return;
}
if ( ! V_100 )
return;
F_58 ( V_99 , V_100 , false , F_86 ( * V_121 ) , F_87 ( * V_121 ) ) ;
}
static void F_88 ( V_30 * V_127 , unsigned long V_117 ,
struct V_118 * V_119 )
{
struct V_98 * V_99 = V_119 -> V_52 ;
struct V_45 * V_46 = V_119 -> V_46 ;
struct V_100 * V_100 ;
V_100 = F_89 ( V_46 , V_117 , V_127 , V_128 ) ;
if ( F_31 ( V_100 ) )
return;
if ( F_60 ( V_100 ) )
V_99 -> V_129 += V_130 ;
else if ( F_61 ( V_100 ) )
V_99 -> V_131 += V_130 ;
else if ( F_90 ( V_100 ) )
;
else
F_91 ( 1 , V_100 ) ;
F_58 ( V_99 , V_100 , true , F_92 ( * V_127 ) , F_93 ( * V_127 ) ) ;
}
static void F_88 ( V_30 * V_127 , unsigned long V_117 ,
struct V_118 * V_119 )
{
}
static int F_94 ( V_30 * V_127 , unsigned long V_117 , unsigned long V_81 ,
struct V_118 * V_119 )
{
struct V_45 * V_46 = V_119 -> V_46 ;
V_27 * V_121 ;
T_5 * V_132 ;
V_132 = F_95 ( V_127 , V_46 ) ;
if ( V_132 ) {
F_88 ( V_127 , V_117 , V_119 ) ;
F_96 ( V_132 ) ;
return 0 ;
}
if ( F_97 ( V_127 ) )
return 0 ;
V_121 = F_98 ( V_46 -> V_72 , V_127 , V_117 , & V_132 ) ;
for (; V_117 != V_81 ; V_121 ++ , V_117 += V_35 )
F_69 ( V_121 , V_117 , V_119 ) ;
F_99 ( V_121 - 1 , V_132 ) ;
F_100 () ;
return 0 ;
}
static void F_101 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
static const char V_133 [ V_134 ] [ 2 ] = {
[ 0 ... ( V_134 - 1 ) ] = L_22 ,
[ F_102 ( V_88 ) ] = L_23 ,
[ F_102 ( V_89 ) ] = L_24 ,
[ F_102 ( V_90 ) ] = L_25 ,
[ F_102 ( V_135 ) ] = L_26 ,
[ F_102 ( V_136 ) ] = L_27 ,
[ F_102 ( V_137 ) ] = L_28 ,
[ F_102 ( V_138 ) ] = L_29 ,
[ F_102 ( V_91 ) ] = L_30 ,
[ F_102 ( V_139 ) ] = L_31 ,
[ F_102 ( V_140 ) ] = L_32 ,
[ F_102 ( V_141 ) ] = L_33 ,
#ifdef F_103
[ F_102 ( V_142 ) ] = L_34 ,
#endif
[ F_102 ( V_143 ) ] = L_35 ,
[ F_102 ( V_144 ) ] = L_36 ,
[ F_102 ( V_145 ) ] = L_37 ,
[ F_102 ( V_146 ) ] = L_38 ,
[ F_102 ( V_147 ) ] = L_39 ,
[ F_102 ( V_148 ) ] = L_40 ,
[ F_102 ( V_149 ) ] = L_41 ,
[ F_102 ( V_150 ) ] = L_42 ,
[ F_102 ( V_151 ) ] = L_43 ,
[ F_102 ( V_152 ) ] = L_44 ,
[ F_102 ( V_153 ) ] = L_45 ,
#ifdef F_104
[ F_102 ( V_154 ) ] = L_46 ,
#endif
[ F_102 ( V_155 ) ] = L_47 ,
[ F_102 ( V_156 ) ] = L_48 ,
[ F_102 ( V_157 ) ] = L_49 ,
[ F_102 ( V_158 ) ] = L_50 ,
[ F_102 ( V_159 ) ] = L_51 ,
[ F_102 ( V_160 ) ] = L_52 ,
#ifdef F_105
[ F_102 ( V_161 ) ] = L_53 ,
[ F_102 ( V_162 ) ] = L_53 ,
[ F_102 ( V_163 ) ] = L_53 ,
[ F_102 ( V_164 ) ] = L_53 ,
#endif
} ;
T_6 V_104 ;
F_51 ( V_2 , L_54 ) ;
for ( V_104 = 0 ; V_104 < V_134 ; V_104 ++ ) {
if ( ! V_133 [ V_104 ] [ 0 ] )
continue;
if ( V_46 -> V_77 & ( 1UL << V_104 ) ) {
F_6 ( V_2 , L_55 ,
V_133 [ V_104 ] [ 0 ] , V_133 [ V_104 ] [ 1 ] ) ;
}
}
F_52 ( V_2 , '\n' ) ;
}
static int F_106 ( V_27 * V_121 , unsigned long V_165 ,
unsigned long V_117 , unsigned long V_81 ,
struct V_118 * V_119 )
{
struct V_98 * V_99 = V_119 -> V_52 ;
struct V_45 * V_46 = V_119 -> V_46 ;
struct V_100 * V_100 = NULL ;
if ( F_70 ( * V_121 ) ) {
V_100 = F_71 ( V_46 , V_117 , * V_121 ) ;
} else if ( F_72 ( * V_121 ) ) {
T_4 V_122 = F_73 ( * V_121 ) ;
if ( F_77 ( V_122 ) )
V_100 = F_78 ( V_122 ) ;
}
if ( V_100 ) {
int V_114 = F_66 ( V_100 ) ;
if ( V_114 >= 2 )
V_99 -> V_166 += F_107 ( F_108 ( V_46 ) ) ;
else
V_99 -> V_167 += F_107 ( F_108 ( V_46 ) ) ;
}
return 0 ;
}
void __weak F_109 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
}
static int F_110 ( struct V_1 * V_2 , void * V_62 , int V_74 )
{
struct V_45 * V_46 = V_62 ;
struct V_98 V_99 ;
struct V_118 V_168 = {
. V_169 = F_94 ,
#ifdef F_111
. V_170 = F_106 ,
#endif
. V_4 = V_46 -> V_72 ,
. V_52 = & V_99 ,
} ;
memset ( & V_99 , 0 , sizeof V_99 ) ;
#ifdef V_125
if ( V_46 -> V_75 && F_112 ( V_46 -> V_75 -> V_120 ) ) {
unsigned long V_171 = F_113 ( V_46 ) ;
if ( ! V_171 || ( V_46 -> V_77 & V_135 ) ||
! ( V_46 -> V_77 & V_89 ) ) {
V_99 . V_7 = V_171 ;
} else {
V_99 . V_126 = true ;
V_168 . V_172 = F_67 ;
}
}
#endif
F_114 ( V_46 , & V_168 ) ;
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
L_73
L_74 ,
( V_46 -> V_53 - V_46 -> V_59 ) >> 10 ,
V_99 . V_38 >> 10 ,
( unsigned long ) ( V_99 . V_111 >> ( 10 + V_113 ) ) ,
V_99 . V_116 >> 10 ,
V_99 . V_115 >> 10 ,
V_99 . V_110 >> 10 ,
V_99 . V_109 >> 10 ,
V_99 . V_108 >> 10 ,
V_99 . V_106 >> 10 ,
V_99 . V_107 >> 10 ,
V_99 . V_129 >> 10 ,
V_99 . V_131 >> 10 ,
V_99 . V_166 >> 10 ,
V_99 . V_167 >> 10 ,
V_99 . V_7 >> 10 ,
( unsigned long ) ( V_99 . V_124 >> ( 10 + V_113 ) ) ,
F_115 ( V_46 ) >> 10 ,
F_116 ( V_46 ) >> 10 ,
( V_46 -> V_77 & V_143 ) ?
( unsigned long ) ( V_99 . V_111 >> ( 10 + V_113 ) ) : 0 ) ;
F_109 ( V_2 , V_46 ) ;
F_101 ( V_2 , V_46 ) ;
F_21 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , void * V_62 )
{
return F_110 ( V_2 , V_62 , 1 ) ;
}
static int F_118 ( struct V_1 * V_2 , void * V_62 )
{
return F_110 ( V_2 , V_62 , 0 ) ;
}
static int F_119 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_173 ) ;
}
static int F_120 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_41 ( V_57 , V_11 , & V_174 ) ;
}
static inline void F_121 ( struct V_45 * V_46 ,
unsigned long V_117 , V_27 * V_121 )
{
V_27 V_175 = * V_121 ;
if ( F_70 ( V_175 ) ) {
V_175 = F_122 ( V_46 -> V_72 , V_117 , V_121 ) ;
V_175 = F_123 ( V_175 ) ;
V_175 = F_124 ( V_175 ) ;
F_125 ( V_46 -> V_72 , V_117 , V_121 , V_175 ) ;
} else if ( F_72 ( V_175 ) ) {
V_175 = F_126 ( V_175 ) ;
F_127 ( V_46 -> V_72 , V_117 , V_121 , V_175 ) ;
}
}
static inline void F_121 ( struct V_45 * V_46 ,
unsigned long V_117 , V_27 * V_121 )
{
}
static inline void F_128 ( struct V_45 * V_46 ,
unsigned long V_117 , V_30 * V_176 )
{
V_30 V_127 = * V_176 ;
F_129 ( V_46 , V_117 , V_176 ) ;
if ( F_93 ( * V_176 ) )
V_127 = F_130 ( V_127 ) ;
if ( F_92 ( * V_176 ) )
V_127 = F_131 ( V_127 ) ;
V_127 = F_132 ( V_127 ) ;
V_127 = F_133 ( V_127 ) ;
F_134 ( V_46 -> V_72 , V_117 , V_176 , V_127 ) ;
}
static inline void F_128 ( struct V_45 * V_46 ,
unsigned long V_117 , V_30 * V_176 )
{
}
static int F_135 ( V_30 * V_127 , unsigned long V_117 ,
unsigned long V_81 , struct V_118 * V_119 )
{
struct V_177 * V_178 = V_119 -> V_52 ;
struct V_45 * V_46 = V_119 -> V_46 ;
V_27 * V_121 , V_175 ;
T_5 * V_132 ;
struct V_100 * V_100 ;
V_132 = F_95 ( V_127 , V_46 ) ;
if ( V_132 ) {
if ( V_178 -> type == V_179 ) {
F_128 ( V_46 , V_117 , V_127 ) ;
goto V_180;
}
V_100 = F_136 ( * V_127 ) ;
F_137 ( V_46 , V_117 , V_127 ) ;
F_138 ( V_100 ) ;
F_139 ( V_100 ) ;
V_180:
F_96 ( V_132 ) ;
return 0 ;
}
if ( F_97 ( V_127 ) )
return 0 ;
V_121 = F_98 ( V_46 -> V_72 , V_127 , V_117 , & V_132 ) ;
for (; V_117 != V_81 ; V_121 ++ , V_117 += V_35 ) {
V_175 = * V_121 ;
if ( V_178 -> type == V_179 ) {
F_121 ( V_46 , V_117 , V_121 ) ;
continue;
}
if ( ! F_70 ( V_175 ) )
continue;
V_100 = F_71 ( V_46 , V_117 , V_175 ) ;
if ( ! V_100 )
continue;
F_140 ( V_46 , V_117 , V_121 ) ;
F_138 ( V_100 ) ;
F_139 ( V_100 ) ;
}
F_99 ( V_121 - 1 , V_132 ) ;
F_100 () ;
return 0 ;
}
static int F_141 ( unsigned long V_80 , unsigned long V_81 ,
struct V_118 * V_119 )
{
struct V_177 * V_178 = V_119 -> V_52 ;
struct V_45 * V_46 = V_119 -> V_46 ;
if ( V_46 -> V_77 & V_140 )
return 1 ;
if ( V_178 -> type == V_181 && V_46 -> V_75 )
return 1 ;
if ( V_178 -> type == V_182 && ! V_46 -> V_75 )
return 1 ;
return 0 ;
}
static T_7 F_142 ( struct V_11 * V_11 , const char T_8 * V_183 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_41 * V_42 ;
char V_184 [ V_185 ] ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
enum V_186 type ;
int V_187 ;
int V_188 ;
memset ( V_184 , 0 , sizeof( V_184 ) ) ;
if ( V_49 > sizeof( V_184 ) - 1 )
V_49 = sizeof( V_184 ) - 1 ;
if ( F_143 ( V_184 , V_183 , V_49 ) )
return - V_189 ;
V_188 = F_144 ( F_145 ( V_184 ) , 10 , & V_187 ) ;
if ( V_188 < 0 )
return V_188 ;
type = (enum V_186 ) V_187 ;
if ( type < V_190 || type >= V_191 )
return - V_192 ;
V_42 = F_23 ( F_44 ( V_11 ) ) ;
if ( ! V_42 )
return - V_58 ;
V_4 = F_146 ( V_42 ) ;
if ( V_4 ) {
struct V_177 V_178 = {
. type = type ,
} ;
struct V_118 V_193 = {
. V_169 = F_135 ,
. V_194 = F_141 ,
. V_4 = V_4 ,
. V_52 = & V_178 ,
} ;
if ( type == V_195 ) {
if ( F_147 ( & V_4 -> V_44 ) ) {
V_49 = - V_196 ;
goto V_197;
}
F_148 ( V_4 ) ;
F_149 ( & V_4 -> V_44 ) ;
goto V_197;
}
F_26 ( & V_4 -> V_44 ) ;
if ( type == V_179 ) {
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
if ( ! ( V_46 -> V_77 & V_154 ) )
continue;
F_18 ( & V_4 -> V_44 ) ;
if ( F_147 ( & V_4 -> V_44 ) ) {
V_49 = - V_196 ;
goto V_197;
}
for ( V_46 = V_4 -> V_61 ; V_46 ; V_46 = V_46 -> V_48 ) {
V_46 -> V_77 &= ~ V_154 ;
F_150 ( V_46 ) ;
}
F_151 ( & V_4 -> V_44 ) ;
break;
}
F_152 ( V_4 , 0 , - 1 ) ;
}
F_153 ( 0 , V_4 -> V_198 , & V_193 ) ;
if ( type == V_179 )
F_154 ( V_4 , 0 , - 1 ) ;
F_155 ( V_4 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_197:
F_19 ( V_4 ) ;
}
F_32 ( V_42 ) ;
return V_49 ;
}
static inline T_9 F_156 ( V_112 V_199 , V_112 V_76 )
{
return ( T_9 ) { . V_200 = ( V_199 & V_201 ) | V_76 } ;
}
static int F_157 ( unsigned long V_117 , T_9 * V_200 ,
struct V_202 * V_203 )
{
V_203 -> V_184 [ V_203 -> V_56 ++ ] = * V_200 ;
if ( V_203 -> V_56 >= V_203 -> V_204 )
return V_205 ;
return 0 ;
}
static int F_158 ( unsigned long V_80 , unsigned long V_81 ,
struct V_118 * V_119 )
{
struct V_202 * V_203 = V_119 -> V_52 ;
unsigned long V_117 = V_80 ;
int V_69 = 0 ;
while ( V_117 < V_81 ) {
struct V_45 * V_46 = F_28 ( V_119 -> V_4 , V_117 ) ;
T_9 V_200 = F_156 ( 0 , 0 ) ;
unsigned long V_206 ;
if ( V_46 )
V_206 = F_159 ( V_81 , V_46 -> V_59 ) ;
else
V_206 = V_81 ;
for (; V_117 < V_206 ; V_117 += V_35 ) {
V_69 = F_157 ( V_117 , & V_200 , V_203 ) ;
if ( V_69 )
goto V_180;
}
if ( ! V_46 )
break;
if ( V_46 -> V_77 & V_154 )
V_200 = F_156 ( 0 , V_207 ) ;
for (; V_117 < F_159 ( V_81 , V_46 -> V_53 ) ; V_117 += V_35 ) {
V_69 = F_157 ( V_117 , & V_200 , V_203 ) ;
if ( V_69 )
goto V_180;
}
}
V_180:
return V_69 ;
}
static T_9 F_160 ( struct V_202 * V_203 ,
struct V_45 * V_46 , unsigned long V_117 , V_27 V_121 )
{
V_112 V_199 = 0 , V_76 = 0 ;
struct V_100 * V_100 = NULL ;
if ( F_70 ( V_121 ) ) {
if ( V_203 -> V_208 )
V_199 = F_161 ( V_121 ) ;
V_76 |= V_209 ;
V_100 = F_71 ( V_46 , V_117 , V_121 ) ;
if ( F_162 ( V_121 ) )
V_76 |= V_207 ;
} else if ( F_72 ( V_121 ) ) {
T_4 V_210 ;
if ( F_163 ( V_121 ) )
V_76 |= V_207 ;
V_210 = F_73 ( V_121 ) ;
V_199 = F_164 ( V_210 ) |
( F_165 ( V_210 ) << V_211 ) ;
V_76 |= V_212 ;
if ( F_77 ( V_210 ) )
V_100 = F_78 ( V_210 ) ;
}
if ( V_100 && ! F_60 ( V_100 ) )
V_76 |= V_213 ;
if ( V_100 && F_66 ( V_100 ) == 1 )
V_76 |= V_214 ;
if ( V_46 -> V_77 & V_154 )
V_76 |= V_207 ;
return F_156 ( V_199 , V_76 ) ;
}
static int F_166 ( V_30 * V_176 , unsigned long V_117 , unsigned long V_81 ,
struct V_118 * V_119 )
{
struct V_45 * V_46 = V_119 -> V_46 ;
struct V_202 * V_203 = V_119 -> V_52 ;
T_5 * V_132 ;
V_27 * V_121 , * V_215 ;
int V_69 = 0 ;
#ifdef F_167
V_132 = F_95 ( V_176 , V_46 ) ;
if ( V_132 ) {
V_112 V_76 = 0 , V_199 = 0 ;
V_30 V_127 = * V_176 ;
if ( ( V_46 -> V_77 & V_154 ) || F_168 ( V_127 ) )
V_76 |= V_207 ;
if ( F_169 ( V_127 ) ) {
struct V_100 * V_100 = F_136 ( V_127 ) ;
if ( F_66 ( V_100 ) == 1 )
V_76 |= V_214 ;
V_76 |= V_209 ;
if ( V_203 -> V_208 )
V_199 = F_170 ( V_127 ) +
( ( V_117 & ~ V_216 ) >> V_24 ) ;
}
for (; V_117 != V_81 ; V_117 += V_35 ) {
T_9 V_200 = F_156 ( V_199 , V_76 ) ;
V_69 = F_157 ( V_117 , & V_200 , V_203 ) ;
if ( V_69 )
break;
if ( V_203 -> V_208 && ( V_76 & V_209 ) )
V_199 ++ ;
}
F_96 ( V_132 ) ;
return V_69 ;
}
if ( F_97 ( V_176 ) )
return 0 ;
#endif
V_215 = V_121 = F_98 ( V_119 -> V_4 , V_176 , V_117 , & V_132 ) ;
for (; V_117 < V_81 ; V_121 ++ , V_117 += V_35 ) {
T_9 V_200 ;
V_200 = F_160 ( V_203 , V_46 , V_117 , * V_121 ) ;
V_69 = F_157 ( V_117 , & V_200 , V_203 ) ;
if ( V_69 )
break;
}
F_99 ( V_215 , V_132 ) ;
F_100 () ;
return V_69 ;
}
static int F_171 ( V_27 * V_217 , unsigned long V_165 ,
unsigned long V_117 , unsigned long V_81 ,
struct V_118 * V_119 )
{
struct V_202 * V_203 = V_119 -> V_52 ;
struct V_45 * V_46 = V_119 -> V_46 ;
V_112 V_76 = 0 , V_199 = 0 ;
int V_69 = 0 ;
V_27 V_121 ;
if ( V_46 -> V_77 & V_154 )
V_76 |= V_207 ;
V_121 = F_172 ( V_217 ) ;
if ( F_70 ( V_121 ) ) {
struct V_100 * V_100 = F_173 ( V_121 ) ;
if ( ! F_60 ( V_100 ) )
V_76 |= V_213 ;
if ( F_66 ( V_100 ) == 1 )
V_76 |= V_214 ;
V_76 |= V_209 ;
if ( V_203 -> V_208 )
V_199 = F_161 ( V_121 ) +
( ( V_117 & ~ V_165 ) >> V_24 ) ;
}
for (; V_117 != V_81 ; V_117 += V_35 ) {
T_9 V_200 = F_156 ( V_199 , V_76 ) ;
V_69 = F_157 ( V_117 , & V_200 , V_203 ) ;
if ( V_69 )
return V_69 ;
if ( V_203 -> V_208 && ( V_76 & V_209 ) )
V_199 ++ ;
}
F_100 () ;
return V_69 ;
}
static T_7 F_174 ( struct V_11 * V_11 , char T_8 * V_183 ,
T_6 V_49 , T_1 * V_54 )
{
struct V_3 * V_4 = V_11 -> V_71 ;
struct V_202 V_203 ;
struct V_118 V_218 = {} ;
unsigned long V_219 ;
unsigned long V_220 ;
unsigned long V_221 ;
unsigned long V_222 ;
int V_223 = 0 , V_224 = 0 ;
if ( ! V_4 || ! F_25 ( V_4 ) )
goto V_180;
V_223 = - V_192 ;
if ( ( * V_54 % V_225 ) || ( V_49 % V_225 ) )
goto V_197;
V_223 = 0 ;
if ( ! V_49 )
goto V_197;
V_203 . V_208 = F_175 ( V_11 , & V_226 , V_227 ) ;
V_203 . V_204 = ( V_228 >> V_24 ) ;
V_203 . V_184 = F_176 ( V_203 . V_204 * V_225 , V_229 ) ;
V_223 = - V_67 ;
if ( ! V_203 . V_184 )
goto V_197;
V_218 . V_169 = F_166 ;
V_218 . V_172 = F_158 ;
#ifdef F_111
V_218 . V_170 = F_171 ;
#endif
V_218 . V_4 = V_4 ;
V_218 . V_52 = & V_203 ;
V_219 = * V_54 ;
V_220 = V_219 / V_225 ;
V_221 = V_220 << V_24 ;
V_222 = V_4 -> V_230 ;
if ( V_220 > V_4 -> V_230 >> V_24 )
V_221 = V_222 ;
V_223 = 0 ;
while ( V_49 && ( V_221 < V_222 ) ) {
int V_204 ;
unsigned long V_81 ;
V_203 . V_56 = 0 ;
V_81 = ( V_221 + V_228 ) & V_231 ;
if ( V_81 < V_221 || V_81 > V_222 )
V_81 = V_222 ;
F_26 ( & V_4 -> V_44 ) ;
V_223 = F_153 ( V_221 , V_81 , & V_218 ) ;
F_18 ( & V_4 -> V_44 ) ;
V_221 = V_81 ;
V_204 = F_159 ( V_49 , V_225 * V_203 . V_56 ) ;
if ( F_177 ( V_183 , V_203 . V_184 , V_204 ) ) {
V_223 = - V_189 ;
goto V_232;
}
V_224 += V_204 ;
V_183 += V_204 ;
V_49 -= V_204 ;
}
* V_54 += V_224 ;
if ( ! V_223 || V_223 == V_205 )
V_223 = V_224 ;
V_232:
F_178 ( V_203 . V_184 ) ;
V_197:
F_19 ( V_4 ) ;
V_180:
return V_223 ;
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
static void F_181 ( struct V_100 * V_100 , struct V_233 * V_234 , int F_87 ,
unsigned long V_235 )
{
int V_49 = F_66 ( V_100 ) ;
V_234 -> V_236 += V_235 ;
if ( F_87 || F_62 ( V_100 ) )
V_234 -> V_103 += V_235 ;
if ( F_182 ( V_100 ) )
V_234 -> V_237 += V_235 ;
if ( F_183 ( V_100 ) || F_184 ( V_100 ) )
V_234 -> V_238 += V_235 ;
if ( F_185 ( V_100 ) )
V_234 -> V_239 += V_235 ;
if ( F_60 ( V_100 ) )
V_234 -> V_10 += V_235 ;
if ( V_49 > V_234 -> V_240 )
V_234 -> V_240 = V_49 ;
V_234 -> V_241 [ F_186 ( V_100 ) ] += V_235 ;
}
static struct V_100 * F_187 ( V_27 V_121 , struct V_45 * V_46 ,
unsigned long V_117 )
{
struct V_100 * V_100 ;
int V_242 ;
if ( ! F_70 ( V_121 ) )
return NULL ;
V_100 = F_71 ( V_46 , V_117 , V_121 ) ;
if ( ! V_100 )
return NULL ;
if ( F_188 ( V_100 ) )
return NULL ;
V_242 = F_186 ( V_100 ) ;
if ( ! F_189 ( V_242 , V_243 [ V_244 ] ) )
return NULL ;
return V_100 ;
}
static struct V_100 * F_190 ( V_30 V_127 ,
struct V_45 * V_46 ,
unsigned long V_117 )
{
struct V_100 * V_100 ;
int V_242 ;
if ( ! F_169 ( V_127 ) )
return NULL ;
V_100 = F_191 ( V_46 , V_117 , V_127 ) ;
if ( ! V_100 )
return NULL ;
if ( F_188 ( V_100 ) )
return NULL ;
V_242 = F_186 ( V_100 ) ;
if ( ! F_189 ( V_242 , V_243 [ V_244 ] ) )
return NULL ;
return V_100 ;
}
static int F_192 ( V_30 * V_127 , unsigned long V_117 ,
unsigned long V_81 , struct V_118 * V_119 )
{
struct V_233 * V_234 = V_119 -> V_52 ;
struct V_45 * V_46 = V_119 -> V_46 ;
T_5 * V_132 ;
V_27 * V_215 ;
V_27 * V_121 ;
#ifdef F_167
V_132 = F_95 ( V_127 , V_46 ) ;
if ( V_132 ) {
struct V_100 * V_100 ;
V_100 = F_190 ( * V_127 , V_46 , V_117 ) ;
if ( V_100 )
F_181 ( V_100 , V_234 , F_93 ( * V_127 ) ,
V_130 / V_35 ) ;
F_96 ( V_132 ) ;
return 0 ;
}
if ( F_97 ( V_127 ) )
return 0 ;
#endif
V_215 = V_121 = F_98 ( V_119 -> V_4 , V_127 , V_117 , & V_132 ) ;
do {
struct V_100 * V_100 = F_187 ( * V_121 , V_46 , V_117 ) ;
if ( ! V_100 )
continue;
F_181 ( V_100 , V_234 , F_87 ( * V_121 ) , 1 ) ;
} while ( V_121 ++ , V_117 += V_35 , V_117 != V_81 );
F_99 ( V_215 , V_132 ) ;
F_100 () ;
return 0 ;
}
static int F_193 ( V_27 * V_121 , unsigned long V_165 ,
unsigned long V_117 , unsigned long V_81 , struct V_118 * V_119 )
{
V_27 V_245 = F_172 ( V_121 ) ;
struct V_233 * V_234 ;
struct V_100 * V_100 ;
if ( ! F_70 ( V_245 ) )
return 0 ;
V_100 = F_173 ( V_245 ) ;
if ( ! V_100 )
return 0 ;
V_234 = V_119 -> V_52 ;
F_181 ( V_100 , V_234 , F_87 ( V_245 ) , 1 ) ;
return 0 ;
}
static int F_193 ( V_27 * V_121 , unsigned long V_165 ,
unsigned long V_117 , unsigned long V_81 , struct V_118 * V_119 )
{
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , void * V_62 , int V_74 )
{
struct V_246 * V_247 = V_2 -> V_52 ;
struct V_39 * V_248 = & V_247 -> V_249 ;
struct V_45 * V_46 = V_62 ;
struct V_233 * V_234 = & V_247 -> V_234 ;
struct V_11 * V_11 = V_46 -> V_75 ;
struct V_3 * V_4 = V_46 -> V_72 ;
struct V_118 V_119 = {
. V_170 = F_193 ,
. V_169 = F_192 ,
. V_52 = V_234 ,
. V_4 = V_4 ,
} ;
struct V_250 * V_251 ;
char V_184 [ 64 ] ;
int V_242 ;
if ( ! V_4 )
return 0 ;
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
V_251 = F_195 ( V_46 , V_46 -> V_59 ) ;
if ( V_251 ) {
F_196 ( V_184 , sizeof( V_184 ) , V_251 ) ;
F_197 ( V_251 ) ;
} else {
F_196 ( V_184 , sizeof( V_184 ) , V_248 -> V_43 ) ;
}
F_6 ( V_2 , L_75 , V_46 -> V_59 , V_184 ) ;
if ( V_11 ) {
F_51 ( V_2 , L_76 ) ;
F_49 ( V_2 , V_11 , L_77 ) ;
} else if ( V_46 -> V_59 <= V_4 -> V_94 && V_46 -> V_53 >= V_4 -> V_95 ) {
F_51 ( V_2 , L_78 ) ;
} else if ( F_42 ( V_248 , V_46 ) ) {
F_51 ( V_2 , L_79 ) ;
}
if ( F_198 ( V_46 ) )
F_51 ( V_2 , L_80 ) ;
F_114 ( V_46 , & V_119 ) ;
if ( ! V_234 -> V_236 )
goto V_180;
if ( V_234 -> V_10 )
F_6 ( V_2 , L_81 , V_234 -> V_10 ) ;
if ( V_234 -> V_103 )
F_6 ( V_2 , L_82 , V_234 -> V_103 ) ;
if ( V_234 -> V_236 != V_234 -> V_10 && V_234 -> V_236 != V_234 -> V_103 )
F_6 ( V_2 , L_83 , V_234 -> V_236 ) ;
if ( V_234 -> V_240 > 1 )
F_6 ( V_2 , L_84 , V_234 -> V_240 ) ;
if ( V_234 -> V_237 )
F_6 ( V_2 , L_85 , V_234 -> V_237 ) ;
if ( V_234 -> V_238 < V_234 -> V_236 && ! F_198 ( V_46 ) )
F_6 ( V_2 , L_86 , V_234 -> V_238 ) ;
if ( V_234 -> V_239 )
F_6 ( V_2 , L_87 , V_234 -> V_239 ) ;
F_199 (nid, N_MEMORY)
if ( V_234 -> V_241 [ V_242 ] )
F_6 ( V_2 , L_88 , V_242 , V_234 -> V_241 [ V_242 ] ) ;
F_6 ( V_2 , L_89 , F_115 ( V_46 ) >> 10 ) ;
V_180:
F_52 ( V_2 , '\n' ) ;
F_21 ( V_2 , V_46 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_2 , void * V_62 )
{
return F_194 ( V_2 , V_62 , 1 ) ;
}
static int F_201 ( struct V_1 * V_2 , void * V_62 )
{
return F_194 ( V_2 , V_62 , 0 ) ;
}
static int F_202 ( struct V_57 * V_57 , struct V_11 * V_11 ,
const struct V_64 * V_65 )
{
return F_33 ( V_57 , V_11 , V_65 ,
sizeof( struct V_246 ) ) ;
}
static int F_203 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_202 ( V_57 , V_11 , & V_252 ) ;
}
static int F_204 ( struct V_57 * V_57 , struct V_11 * V_11 )
{
return F_202 ( V_57 , V_11 , & V_253 ) ;
}
