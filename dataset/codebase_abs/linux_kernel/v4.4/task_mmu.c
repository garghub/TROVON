void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ;
unsigned long V_11 , V_12 , V_13 , V_14 ;
V_11 = V_12 = V_4 -> V_12 ;
if ( V_11 < V_4 -> V_11 )
V_11 = V_4 -> V_11 ;
V_13 = V_14 = F_2 ( V_4 ) ;
if ( V_13 < V_4 -> V_13 )
V_13 = V_4 -> V_13 ;
V_5 = V_4 -> V_12 - V_4 -> V_15 - V_4 -> V_16 ;
V_6 = ( F_3 ( V_4 -> V_17 ) - ( V_4 -> V_18 & V_19 ) ) >> 10 ;
V_7 = ( V_4 -> V_20 << ( V_21 - 10 ) ) - V_6 ;
V_8 = F_4 ( V_4 , V_22 ) ;
V_9 = V_23 * sizeof( V_24 ) * F_5 ( & V_4 -> V_25 ) ;
V_10 = V_26 * sizeof( V_27 ) * F_6 ( V_4 ) ;
F_7 ( V_2 ,
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
L_13 ,
V_11 << ( V_21 - 10 ) ,
V_12 << ( V_21 - 10 ) ,
V_4 -> V_28 << ( V_21 - 10 ) ,
V_4 -> V_29 << ( V_21 - 10 ) ,
V_13 << ( V_21 - 10 ) ,
V_14 << ( V_21 - 10 ) ,
V_5 << ( V_21 - 10 ) ,
V_4 -> V_16 << ( V_21 - 10 ) , V_6 , V_7 ,
V_9 >> 10 ,
V_10 >> 10 ,
V_8 << ( V_21 - 10 ) ) ;
F_8 ( V_2 , V_4 ) ;
}
unsigned long F_9 ( struct V_3 * V_4 )
{
return V_30 * V_4 -> V_12 ;
}
unsigned long F_10 ( struct V_3 * V_4 ,
unsigned long * V_31 , unsigned long * V_6 ,
unsigned long * V_5 , unsigned long * V_32 )
{
* V_31 = F_4 ( V_4 , V_33 ) ;
* V_6 = ( F_3 ( V_4 -> V_17 ) - ( V_4 -> V_18 & V_19 ) )
>> V_21 ;
* V_5 = V_4 -> V_12 - V_4 -> V_15 ;
* V_32 = * V_31 + F_4 ( V_4 , V_34 ) ;
return V_4 -> V_12 ;
}
static void F_11 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
F_12 ( V_38 ) ;
V_36 -> V_39 = F_13 ( V_38 ) ;
F_14 ( V_36 -> V_39 ) ;
F_15 ( V_38 ) ;
}
static void F_16 ( struct V_35 * V_36 )
{
F_17 ( V_36 -> V_39 ) ;
}
static void F_11 ( struct V_35 * V_36 )
{
}
static void F_16 ( struct V_35 * V_36 )
{
}
static void F_18 ( struct V_35 * V_36 )
{
struct V_3 * V_4 = V_36 -> V_4 ;
F_16 ( V_36 ) ;
F_19 ( & V_4 -> V_40 ) ;
F_20 ( V_4 ) ;
}
static struct V_41 *
F_21 ( struct V_35 * V_36 , struct V_41 * V_42 )
{
if ( V_42 == V_36 -> V_43 )
return NULL ;
return V_42 -> V_44 ? : V_36 -> V_43 ;
}
static void F_22 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
if ( V_2 -> V_45 < V_2 -> V_46 )
V_2 -> V_47 = F_21 ( V_2 -> V_48 , V_42 ) ? V_42 -> V_49 : - 1UL ;
}
static void * F_23 ( struct V_1 * V_2 , T_1 * V_50 )
{
struct V_35 * V_36 = V_2 -> V_48 ;
unsigned long V_51 = V_2 -> V_47 ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
unsigned int V_52 = * V_50 ;
if ( V_51 == - 1UL )
return NULL ;
V_36 -> V_38 = F_24 ( V_36 -> V_53 ) ;
if ( ! V_36 -> V_38 )
return F_25 ( - V_54 ) ;
V_4 = V_36 -> V_4 ;
if ( ! V_4 || ! F_26 ( & V_4 -> V_55 ) )
return NULL ;
F_27 ( & V_4 -> V_40 ) ;
F_11 ( V_36 ) ;
V_36 -> V_43 = F_28 ( V_4 ) ;
if ( V_51 ) {
V_42 = F_29 ( V_4 , V_51 ) ;
if ( V_42 && ( V_42 = F_21 ( V_36 , V_42 ) ) )
return V_42 ;
}
V_2 -> V_47 = 0 ;
if ( V_52 < V_4 -> V_56 ) {
for ( V_42 = V_4 -> V_57 ; V_52 ; V_52 -- ) {
V_2 -> V_47 = V_42 -> V_49 ;
V_42 = V_42 -> V_44 ;
}
return V_42 ;
}
if ( V_52 == V_4 -> V_56 && V_36 -> V_43 )
return V_36 -> V_43 ;
F_18 ( V_36 ) ;
return NULL ;
}
static void * F_30 ( struct V_1 * V_2 , void * V_58 , T_1 * V_52 )
{
struct V_35 * V_36 = V_2 -> V_48 ;
struct V_41 * V_59 ;
( * V_52 ) ++ ;
V_59 = F_21 ( V_36 , V_58 ) ;
if ( ! V_59 )
F_18 ( V_36 ) ;
return V_59 ;
}
static void F_31 ( struct V_1 * V_2 , void * V_58 )
{
struct V_35 * V_36 = V_2 -> V_48 ;
if ( ! F_32 ( V_58 ) )
F_18 ( V_36 ) ;
if ( V_36 -> V_38 ) {
F_33 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
}
}
static int F_34 ( struct V_53 * V_53 , struct V_60 * V_60 ,
const struct V_61 * V_62 , int V_63 )
{
struct V_35 * V_36 = F_35 ( V_60 , V_62 , V_63 ) ;
if ( ! V_36 )
return - V_64 ;
V_36 -> V_53 = V_53 ;
V_36 -> V_4 = F_36 ( V_53 , V_65 ) ;
if ( F_37 ( V_36 -> V_4 ) ) {
int V_66 = F_38 ( V_36 -> V_4 ) ;
F_39 ( V_53 , V_60 ) ;
return V_66 ;
}
return 0 ;
}
static int F_40 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
struct V_1 * V_67 = V_60 -> V_68 ;
struct V_35 * V_36 = V_67 -> V_48 ;
if ( V_36 -> V_4 )
F_41 ( V_36 -> V_4 ) ;
return F_39 ( V_53 , V_60 ) ;
}
static int F_42 ( struct V_53 * V_53 , struct V_60 * V_60 ,
const struct V_61 * V_62 )
{
return F_34 ( V_53 , V_60 , V_62 ,
sizeof( struct V_35 ) ) ;
}
static T_2 F_43 ( struct V_35 * V_36 ,
struct V_41 * V_42 , bool V_69 )
{
struct V_53 * V_53 = V_36 -> V_53 ;
struct V_37 * V_38 ;
T_2 V_70 = 0 ;
F_44 () ;
V_38 = F_45 ( F_46 ( V_53 ) , V_71 ) ;
if ( V_38 ) {
V_38 = F_47 ( V_38 , V_42 , V_69 ) ;
if ( V_38 )
V_70 = F_48 ( V_38 , V_53 -> V_72 -> V_73 ) ;
}
F_49 () ;
return V_70 ;
}
static void
F_50 ( struct V_1 * V_2 , struct V_41 * V_42 , int V_69 )
{
struct V_3 * V_4 = V_42 -> V_74 ;
struct V_60 * V_60 = V_42 -> V_75 ;
struct V_35 * V_36 = V_2 -> V_48 ;
T_3 V_76 = V_42 -> V_77 ;
unsigned long V_78 = 0 ;
unsigned long long V_79 = 0 ;
unsigned long V_80 , V_81 ;
T_4 V_82 = 0 ;
const char * V_83 = NULL ;
if ( V_60 ) {
struct V_53 * V_53 = F_51 ( V_42 -> V_75 ) ;
V_82 = V_53 -> V_72 -> V_84 ;
V_78 = V_53 -> V_85 ;
V_79 = ( ( T_1 ) V_42 -> V_86 ) << V_21 ;
}
V_80 = V_42 -> V_49 ;
if ( F_52 ( V_42 , V_80 ) )
V_80 += V_30 ;
V_81 = V_42 -> V_87 ;
if ( F_53 ( V_42 , V_81 ) )
V_81 -= V_30 ;
F_54 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_7 ( V_2 , L_14 ,
V_80 ,
V_81 ,
V_76 & V_88 ? 'r' : '-' ,
V_76 & V_89 ? 'w' : '-' ,
V_76 & V_90 ? 'x' : '-' ,
V_76 & V_91 ? 's' : 'p' ,
V_79 ,
F_55 ( V_82 ) , F_56 ( V_82 ) , V_78 ) ;
if ( V_60 ) {
F_57 ( V_2 , ' ' ) ;
F_58 ( V_2 , V_60 , L_15 ) ;
goto V_92;
}
if ( V_42 -> V_93 && V_42 -> V_93 -> V_83 ) {
V_83 = V_42 -> V_93 -> V_83 ( V_42 ) ;
if ( V_83 )
goto V_92;
}
V_83 = F_59 ( V_42 ) ;
if ( ! V_83 ) {
T_2 V_94 ;
if ( ! V_4 ) {
V_83 = L_16 ;
goto V_92;
}
if ( V_42 -> V_49 <= V_4 -> V_95 &&
V_42 -> V_87 >= V_4 -> V_96 ) {
V_83 = L_17 ;
goto V_92;
}
V_94 = F_43 ( V_36 , V_42 , V_69 ) ;
if ( V_94 != 0 ) {
if ( ! V_69 || ( V_42 -> V_49 <= V_4 -> V_97 &&
V_42 -> V_87 >= V_4 -> V_97 ) ) {
V_83 = L_18 ;
} else {
F_57 ( V_2 , ' ' ) ;
F_7 ( V_2 , L_19 , V_94 ) ;
}
}
}
V_92:
if ( V_83 ) {
F_57 ( V_2 , ' ' ) ;
F_60 ( V_2 , V_83 ) ;
}
F_61 ( V_2 , '\n' ) ;
}
static int F_62 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
F_50 ( V_2 , V_58 , V_69 ) ;
F_22 ( V_2 , V_58 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 , void * V_58 )
{
return F_62 ( V_2 , V_58 , 1 ) ;
}
static int F_64 ( struct V_1 * V_2 , void * V_58 )
{
return F_62 ( V_2 , V_58 , 0 ) ;
}
static int F_65 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_42 ( V_53 , V_60 , & V_98 ) ;
}
static int F_66 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_42 ( V_53 , V_60 , & V_99 ) ;
}
static void F_67 ( struct V_100 * V_101 , struct V_102 * V_102 ,
unsigned long V_46 , bool V_103 , bool V_104 )
{
int V_105 ;
if ( F_68 ( V_102 ) )
V_101 -> V_106 += V_46 ;
V_101 -> V_32 += V_46 ;
if ( V_103 || F_69 ( V_102 ) || F_70 ( V_102 ) )
V_101 -> V_107 += V_46 ;
V_105 = F_71 ( V_102 ) ;
if ( V_105 >= 2 ) {
T_5 V_108 ;
if ( V_104 || F_72 ( V_102 ) )
V_101 -> V_109 += V_46 ;
else
V_101 -> V_110 += V_46 ;
V_108 = ( T_5 ) V_46 << V_111 ;
F_73 ( V_108 , V_105 ) ;
V_101 -> V_112 += V_108 ;
} else {
if ( V_104 || F_72 ( V_102 ) )
V_101 -> V_113 += V_46 ;
else
V_101 -> V_114 += V_46 ;
V_101 -> V_112 += ( T_5 ) V_46 << V_111 ;
}
}
static void F_74 ( V_24 * V_115 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_100 * V_101 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_102 * V_102 = NULL ;
if ( F_75 ( * V_115 ) ) {
V_102 = F_76 ( V_42 , V_116 , * V_115 ) ;
} else if ( F_77 ( * V_115 ) ) {
T_6 V_119 = F_78 ( * V_115 ) ;
if ( ! F_79 ( V_119 ) ) {
int V_105 ;
V_101 -> V_8 += V_30 ;
V_105 = F_80 ( V_119 ) ;
if ( V_105 >= 2 ) {
T_5 V_108 = ( T_5 ) V_30 << V_111 ;
F_73 ( V_108 , V_105 ) ;
V_101 -> V_120 += V_108 ;
} else {
V_101 -> V_120 += ( T_5 ) V_30 << V_111 ;
}
} else if ( F_81 ( V_119 ) )
V_102 = F_82 ( V_119 ) ;
}
if ( ! V_102 )
return;
F_67 ( V_101 , V_102 , V_30 , F_83 ( * V_115 ) , F_84 ( * V_115 ) ) ;
}
static void F_85 ( V_27 * V_121 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_100 * V_101 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_102 * V_102 ;
V_102 = F_86 ( V_42 , V_116 , V_121 , V_122 ) ;
if ( F_32 ( V_102 ) )
return;
V_101 -> V_123 += V_124 ;
F_67 ( V_101 , V_102 , V_124 ,
F_87 ( * V_121 ) , F_88 ( * V_121 ) ) ;
}
static void F_85 ( V_27 * V_121 , unsigned long V_116 ,
struct V_117 * V_118 )
{
}
static int F_89 ( V_27 * V_121 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 = V_118 -> V_42 ;
V_24 * V_115 ;
T_7 * V_125 ;
if ( F_90 ( V_121 , V_42 , & V_125 ) == 1 ) {
F_85 ( V_121 , V_116 , V_118 ) ;
F_91 ( V_125 ) ;
return 0 ;
}
if ( F_92 ( V_121 ) )
return 0 ;
V_115 = F_93 ( V_42 -> V_74 , V_121 , V_116 , & V_125 ) ;
for (; V_116 != V_81 ; V_115 ++ , V_116 += V_30 )
F_74 ( V_115 , V_116 , V_118 ) ;
F_94 ( V_115 - 1 , V_125 ) ;
F_95 () ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
static const char V_126 [ V_127 ] [ 2 ] = {
[ 0 ... ( V_127 - 1 ) ] = L_20 ,
[ F_97 ( V_88 ) ] = L_21 ,
[ F_97 ( V_89 ) ] = L_22 ,
[ F_97 ( V_90 ) ] = L_23 ,
[ F_97 ( V_128 ) ] = L_24 ,
[ F_97 ( V_129 ) ] = L_25 ,
[ F_97 ( V_130 ) ] = L_26 ,
[ F_97 ( V_131 ) ] = L_27 ,
[ F_97 ( V_91 ) ] = L_28 ,
[ F_97 ( V_132 ) ] = L_29 ,
[ F_97 ( V_133 ) ] = L_30 ,
[ F_97 ( V_134 ) ] = L_31 ,
#ifdef F_98
[ F_97 ( V_135 ) ] = L_32 ,
#endif
[ F_97 ( V_136 ) ] = L_33 ,
[ F_97 ( V_137 ) ] = L_34 ,
[ F_97 ( V_138 ) ] = L_35 ,
[ F_97 ( V_139 ) ] = L_36 ,
[ F_97 ( V_140 ) ] = L_37 ,
[ F_97 ( V_141 ) ] = L_38 ,
[ F_97 ( V_142 ) ] = L_39 ,
[ F_97 ( V_143 ) ] = L_40 ,
[ F_97 ( V_144 ) ] = L_41 ,
[ F_97 ( V_145 ) ] = L_42 ,
[ F_97 ( V_146 ) ] = L_43 ,
#ifdef F_99
[ F_97 ( V_147 ) ] = L_44 ,
#endif
[ F_97 ( V_148 ) ] = L_45 ,
[ F_97 ( V_149 ) ] = L_46 ,
[ F_97 ( V_150 ) ] = L_47 ,
[ F_97 ( V_151 ) ] = L_48 ,
[ F_97 ( V_152 ) ] = L_49 ,
[ F_97 ( V_153 ) ] = L_50 ,
} ;
T_8 V_154 ;
F_60 ( V_2 , L_51 ) ;
for ( V_154 = 0 ; V_154 < V_127 ; V_154 ++ ) {
if ( V_42 -> V_77 & ( 1UL << V_154 ) ) {
F_7 ( V_2 , L_52 ,
V_126 [ V_154 ] [ 0 ] , V_126 [ V_154 ] [ 1 ] ) ;
}
}
F_61 ( V_2 , '\n' ) ;
}
static int F_100 ( V_24 * V_115 , unsigned long V_155 ,
unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_100 * V_101 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_102 * V_102 = NULL ;
if ( F_75 ( * V_115 ) ) {
V_102 = F_76 ( V_42 , V_116 , * V_115 ) ;
} else if ( F_77 ( * V_115 ) ) {
T_6 V_119 = F_78 ( * V_115 ) ;
if ( F_81 ( V_119 ) )
V_102 = F_82 ( V_119 ) ;
}
if ( V_102 ) {
int V_105 = F_71 ( V_102 ) ;
if ( V_105 >= 2 )
V_101 -> V_156 += F_101 ( F_102 ( V_42 ) ) ;
else
V_101 -> V_157 += F_101 ( F_102 ( V_42 ) ) ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
struct V_41 * V_42 = V_58 ;
struct V_100 V_101 ;
struct V_117 V_158 = {
. V_159 = F_89 ,
#ifdef F_104
. V_160 = F_100 ,
#endif
. V_4 = V_42 -> V_74 ,
. V_48 = & V_101 ,
} ;
memset ( & V_101 , 0 , sizeof V_101 ) ;
F_105 ( V_42 , & V_158 ) ;
F_50 ( V_2 , V_42 , V_69 ) ;
F_7 ( V_2 ,
L_53
L_54
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
L_69 ,
( V_42 -> V_87 - V_42 -> V_49 ) >> 10 ,
V_101 . V_32 >> 10 ,
( unsigned long ) ( V_101 . V_112 >> ( 10 + V_111 ) ) ,
V_101 . V_110 >> 10 ,
V_101 . V_109 >> 10 ,
V_101 . V_114 >> 10 ,
V_101 . V_113 >> 10 ,
V_101 . V_107 >> 10 ,
V_101 . V_106 >> 10 ,
V_101 . V_123 >> 10 ,
V_101 . V_156 >> 10 ,
V_101 . V_157 >> 10 ,
V_101 . V_8 >> 10 ,
( unsigned long ) ( V_101 . V_120 >> ( 10 + V_111 ) ) ,
F_106 ( V_42 ) >> 10 ,
F_107 ( V_42 ) >> 10 ,
( V_42 -> V_77 & V_136 ) ?
( unsigned long ) ( V_101 . V_112 >> ( 10 + V_111 ) ) : 0 ) ;
F_96 ( V_2 , V_42 ) ;
F_22 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 , void * V_58 )
{
return F_103 ( V_2 , V_58 , 1 ) ;
}
static int F_109 ( struct V_1 * V_2 , void * V_58 )
{
return F_103 ( V_2 , V_58 , 0 ) ;
}
static int F_110 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_42 ( V_53 , V_60 , & V_161 ) ;
}
static int F_111 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_42 ( V_53 , V_60 , & V_162 ) ;
}
static inline void F_112 ( struct V_41 * V_42 ,
unsigned long V_116 , V_24 * V_115 )
{
V_24 V_163 = * V_115 ;
if ( F_75 ( V_163 ) ) {
V_163 = F_113 ( V_42 -> V_74 , V_116 , V_115 ) ;
V_163 = F_114 ( V_163 ) ;
V_163 = F_115 ( V_163 ) ;
F_116 ( V_42 -> V_74 , V_116 , V_115 , V_163 ) ;
} else if ( F_77 ( V_163 ) ) {
V_163 = F_117 ( V_163 ) ;
F_118 ( V_42 -> V_74 , V_116 , V_115 , V_163 ) ;
}
}
static inline void F_112 ( struct V_41 * V_42 ,
unsigned long V_116 , V_24 * V_115 )
{
}
static inline void F_119 ( struct V_41 * V_42 ,
unsigned long V_116 , V_27 * V_164 )
{
V_27 V_121 = F_120 ( V_42 -> V_74 , V_116 , V_164 ) ;
V_121 = F_121 ( V_121 ) ;
V_121 = F_122 ( V_121 ) ;
if ( V_42 -> V_77 & V_147 )
V_42 -> V_77 &= ~ V_147 ;
F_123 ( V_42 -> V_74 , V_116 , V_164 , V_121 ) ;
}
static inline void F_119 ( struct V_41 * V_42 ,
unsigned long V_116 , V_27 * V_164 )
{
}
static int F_124 ( V_27 * V_121 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_165 * V_166 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
V_24 * V_115 , V_163 ;
T_7 * V_125 ;
struct V_102 * V_102 ;
if ( F_90 ( V_121 , V_42 , & V_125 ) == 1 ) {
if ( V_166 -> type == V_167 ) {
F_119 ( V_42 , V_116 , V_121 ) ;
goto V_168;
}
V_102 = F_125 ( * V_121 ) ;
F_126 ( V_42 , V_116 , V_121 ) ;
F_127 ( V_102 ) ;
F_128 ( V_102 ) ;
V_168:
F_91 ( V_125 ) ;
return 0 ;
}
if ( F_92 ( V_121 ) )
return 0 ;
V_115 = F_93 ( V_42 -> V_74 , V_121 , V_116 , & V_125 ) ;
for (; V_116 != V_81 ; V_115 ++ , V_116 += V_30 ) {
V_163 = * V_115 ;
if ( V_166 -> type == V_167 ) {
F_112 ( V_42 , V_116 , V_115 ) ;
continue;
}
if ( ! F_75 ( V_163 ) )
continue;
V_102 = F_76 ( V_42 , V_116 , V_163 ) ;
if ( ! V_102 )
continue;
F_129 ( V_42 , V_116 , V_115 ) ;
F_127 ( V_102 ) ;
F_128 ( V_102 ) ;
}
F_94 ( V_115 - 1 , V_125 ) ;
F_95 () ;
return 0 ;
}
static int F_130 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_165 * V_166 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
if ( V_42 -> V_77 & V_133 )
return 1 ;
if ( V_166 -> type == V_169 && V_42 -> V_75 )
return 1 ;
if ( V_166 -> type == V_170 && ! V_42 -> V_75 )
return 1 ;
return 0 ;
}
static T_9 F_131 ( struct V_60 * V_60 , const char T_10 * V_171 ,
T_8 V_45 , T_1 * V_50 )
{
struct V_37 * V_38 ;
char V_172 [ V_173 ] ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
enum V_174 type ;
int V_175 ;
int V_176 ;
memset ( V_172 , 0 , sizeof( V_172 ) ) ;
if ( V_45 > sizeof( V_172 ) - 1 )
V_45 = sizeof( V_172 ) - 1 ;
if ( F_132 ( V_172 , V_171 , V_45 ) )
return - V_177 ;
V_176 = F_133 ( F_134 ( V_172 ) , 10 , & V_175 ) ;
if ( V_176 < 0 )
return V_176 ;
type = (enum V_174 ) V_175 ;
if ( type < V_178 || type >= V_179 )
return - V_180 ;
V_38 = F_24 ( F_51 ( V_60 ) ) ;
if ( ! V_38 )
return - V_54 ;
V_4 = F_135 ( V_38 ) ;
if ( V_4 ) {
struct V_165 V_166 = {
. type = type ,
} ;
struct V_117 V_181 = {
. V_159 = F_124 ,
. V_182 = F_130 ,
. V_4 = V_4 ,
. V_48 = & V_166 ,
} ;
if ( type == V_183 ) {
F_136 ( & V_4 -> V_40 ) ;
F_137 ( V_4 ) ;
F_138 ( & V_4 -> V_40 ) ;
goto V_184;
}
F_27 ( & V_4 -> V_40 ) ;
if ( type == V_167 ) {
for ( V_42 = V_4 -> V_57 ; V_42 ; V_42 = V_42 -> V_44 ) {
if ( ! ( V_42 -> V_77 & V_147 ) )
continue;
F_19 ( & V_4 -> V_40 ) ;
F_136 ( & V_4 -> V_40 ) ;
for ( V_42 = V_4 -> V_57 ; V_42 ; V_42 = V_42 -> V_44 ) {
V_42 -> V_77 &= ~ V_147 ;
F_139 ( V_42 ) ;
}
F_140 ( & V_4 -> V_40 ) ;
break;
}
F_141 ( V_4 , 0 , - 1 ) ;
}
F_142 ( 0 , ~ 0UL , & V_181 ) ;
if ( type == V_167 )
F_143 ( V_4 , 0 , - 1 ) ;
F_144 ( V_4 ) ;
F_19 ( & V_4 -> V_40 ) ;
V_184:
F_20 ( V_4 ) ;
}
F_33 ( V_38 ) ;
return V_45 ;
}
static inline T_11 F_145 ( T_5 V_185 , T_5 V_76 )
{
return ( T_11 ) { . V_186 = ( V_185 & V_187 ) | V_76 } ;
}
static int F_146 ( unsigned long V_116 , T_11 * V_186 ,
struct V_188 * V_189 )
{
V_189 -> V_172 [ V_189 -> V_52 ++ ] = * V_186 ;
if ( V_189 -> V_52 >= V_189 -> V_190 )
return V_191 ;
return 0 ;
}
static int F_147 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_188 * V_189 = V_118 -> V_48 ;
unsigned long V_116 = V_80 ;
int V_66 = 0 ;
while ( V_116 < V_81 ) {
struct V_41 * V_42 = F_29 ( V_118 -> V_4 , V_116 ) ;
T_11 V_186 = F_145 ( 0 , 0 ) ;
unsigned long V_192 ;
if ( V_42 )
V_192 = F_148 ( V_81 , V_42 -> V_49 ) ;
else
V_192 = V_81 ;
for (; V_116 < V_192 ; V_116 += V_30 ) {
V_66 = F_146 ( V_116 , & V_186 , V_189 ) ;
if ( V_66 )
goto V_168;
}
if ( ! V_42 )
break;
if ( V_42 -> V_77 & V_147 )
V_186 = F_145 ( 0 , V_193 ) ;
for (; V_116 < F_148 ( V_81 , V_42 -> V_87 ) ; V_116 += V_30 ) {
V_66 = F_146 ( V_116 , & V_186 , V_189 ) ;
if ( V_66 )
goto V_168;
}
}
V_168:
return V_66 ;
}
static T_11 F_149 ( struct V_188 * V_189 ,
struct V_41 * V_42 , unsigned long V_116 , V_24 V_115 )
{
T_5 V_185 = 0 , V_76 = 0 ;
struct V_102 * V_102 = NULL ;
if ( F_75 ( V_115 ) ) {
if ( V_189 -> V_194 )
V_185 = F_150 ( V_115 ) ;
V_76 |= V_195 ;
V_102 = F_76 ( V_42 , V_116 , V_115 ) ;
if ( F_151 ( V_115 ) )
V_76 |= V_193 ;
} else if ( F_77 ( V_115 ) ) {
T_6 V_196 ;
if ( F_152 ( V_115 ) )
V_76 |= V_193 ;
V_196 = F_78 ( V_115 ) ;
V_185 = F_153 ( V_196 ) |
( F_154 ( V_196 ) << V_197 ) ;
V_76 |= V_198 ;
if ( F_81 ( V_196 ) )
V_102 = F_82 ( V_196 ) ;
}
if ( V_102 && ! F_68 ( V_102 ) )
V_76 |= V_199 ;
if ( V_102 && F_71 ( V_102 ) == 1 )
V_76 |= V_200 ;
if ( V_42 -> V_77 & V_147 )
V_76 |= V_193 ;
return F_145 ( V_185 , V_76 ) ;
}
static int F_155 ( V_27 * V_164 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_188 * V_189 = V_118 -> V_48 ;
T_7 * V_125 ;
V_24 * V_115 , * V_201 ;
int V_66 = 0 ;
#ifdef F_156
if ( F_90 ( V_164 , V_42 , & V_125 ) == 1 ) {
T_5 V_76 = 0 , V_185 = 0 ;
V_27 V_121 = * V_164 ;
if ( ( V_42 -> V_77 & V_147 ) || F_157 ( V_121 ) )
V_76 |= V_193 ;
if ( F_158 ( V_121 ) ) {
struct V_102 * V_102 = F_125 ( V_121 ) ;
if ( F_71 ( V_102 ) == 1 )
V_76 |= V_200 ;
V_76 |= V_195 ;
if ( V_189 -> V_194 )
V_185 = F_159 ( V_121 ) +
( ( V_116 & ~ V_202 ) >> V_21 ) ;
}
for (; V_116 != V_81 ; V_116 += V_30 ) {
T_11 V_186 = F_145 ( V_185 , V_76 ) ;
V_66 = F_146 ( V_116 , & V_186 , V_189 ) ;
if ( V_66 )
break;
if ( V_189 -> V_194 && ( V_76 & V_195 ) )
V_185 ++ ;
}
F_91 ( V_125 ) ;
return V_66 ;
}
if ( F_92 ( V_164 ) )
return 0 ;
#endif
V_201 = V_115 = F_93 ( V_118 -> V_4 , V_164 , V_116 , & V_125 ) ;
for (; V_116 < V_81 ; V_115 ++ , V_116 += V_30 ) {
T_11 V_186 ;
V_186 = F_149 ( V_189 , V_42 , V_116 , * V_115 ) ;
V_66 = F_146 ( V_116 , & V_186 , V_189 ) ;
if ( V_66 )
break;
}
F_94 ( V_201 , V_125 ) ;
F_95 () ;
return V_66 ;
}
static int F_160 ( V_24 * V_203 , unsigned long V_155 ,
unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_188 * V_189 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
T_5 V_76 = 0 , V_185 = 0 ;
int V_66 = 0 ;
V_24 V_115 ;
if ( V_42 -> V_77 & V_147 )
V_76 |= V_193 ;
V_115 = F_161 ( V_203 ) ;
if ( F_75 ( V_115 ) ) {
struct V_102 * V_102 = F_162 ( V_115 ) ;
if ( ! F_68 ( V_102 ) )
V_76 |= V_199 ;
if ( F_71 ( V_102 ) == 1 )
V_76 |= V_200 ;
V_76 |= V_195 ;
if ( V_189 -> V_194 )
V_185 = F_150 ( V_115 ) +
( ( V_116 & ~ V_155 ) >> V_21 ) ;
}
for (; V_116 != V_81 ; V_116 += V_30 ) {
T_11 V_186 = F_145 ( V_185 , V_76 ) ;
V_66 = F_146 ( V_116 , & V_186 , V_189 ) ;
if ( V_66 )
return V_66 ;
if ( V_189 -> V_194 && ( V_76 & V_195 ) )
V_185 ++ ;
}
F_95 () ;
return V_66 ;
}
static T_9 F_163 ( struct V_60 * V_60 , char T_10 * V_171 ,
T_8 V_45 , T_1 * V_50 )
{
struct V_3 * V_4 = V_60 -> V_68 ;
struct V_188 V_189 ;
struct V_117 V_204 = {} ;
unsigned long V_205 ;
unsigned long V_206 ;
unsigned long V_207 ;
unsigned long V_208 ;
int V_70 = 0 , V_209 = 0 ;
if ( ! V_4 || ! F_26 ( & V_4 -> V_55 ) )
goto V_168;
V_70 = - V_180 ;
if ( ( * V_50 % V_210 ) || ( V_45 % V_210 ) )
goto V_184;
V_70 = 0 ;
if ( ! V_45 )
goto V_184;
V_189 . V_194 = F_164 ( V_60 , & V_211 , V_212 ) ;
V_189 . V_190 = ( V_213 >> V_21 ) ;
V_189 . V_172 = F_165 ( V_189 . V_190 * V_210 , V_214 ) ;
V_70 = - V_64 ;
if ( ! V_189 . V_172 )
goto V_184;
V_204 . V_159 = F_155 ;
V_204 . V_215 = F_147 ;
#ifdef F_104
V_204 . V_160 = F_160 ;
#endif
V_204 . V_4 = V_4 ;
V_204 . V_48 = & V_189 ;
V_205 = * V_50 ;
V_206 = V_205 / V_210 ;
V_207 = V_206 << V_21 ;
V_208 = V_4 -> V_216 ;
if ( V_206 > V_4 -> V_216 >> V_21 )
V_207 = V_208 ;
V_70 = 0 ;
while ( V_45 && ( V_207 < V_208 ) ) {
int V_190 ;
unsigned long V_81 ;
V_189 . V_52 = 0 ;
V_81 = ( V_207 + V_213 ) & V_217 ;
if ( V_81 < V_207 || V_81 > V_208 )
V_81 = V_208 ;
F_27 ( & V_4 -> V_40 ) ;
V_70 = F_142 ( V_207 , V_81 , & V_204 ) ;
F_19 ( & V_4 -> V_40 ) ;
V_207 = V_81 ;
V_190 = F_148 ( V_45 , V_210 * V_189 . V_52 ) ;
if ( F_166 ( V_171 , V_189 . V_172 , V_190 ) ) {
V_70 = - V_177 ;
goto V_218;
}
V_209 += V_190 ;
V_171 += V_190 ;
V_45 -= V_190 ;
}
* V_50 += V_209 ;
if ( ! V_70 || V_70 == V_191 )
V_70 = V_209 ;
V_218:
F_167 ( V_189 . V_172 ) ;
V_184:
F_20 ( V_4 ) ;
V_168:
return V_70 ;
}
static int F_168 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
struct V_3 * V_4 ;
V_4 = F_36 ( V_53 , V_65 ) ;
if ( F_37 ( V_4 ) )
return F_38 ( V_4 ) ;
V_60 -> V_68 = V_4 ;
return 0 ;
}
static int F_169 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_68 ;
if ( V_4 )
F_41 ( V_4 ) ;
return 0 ;
}
static void F_170 ( struct V_102 * V_102 , struct V_219 * V_220 , int F_84 ,
unsigned long V_221 )
{
int V_45 = F_71 ( V_102 ) ;
V_220 -> V_222 += V_221 ;
if ( F_84 || F_72 ( V_102 ) )
V_220 -> V_104 += V_221 ;
if ( F_171 ( V_102 ) )
V_220 -> V_223 += V_221 ;
if ( F_172 ( V_102 ) || F_173 ( V_102 ) )
V_220 -> V_224 += V_221 ;
if ( F_174 ( V_102 ) )
V_220 -> V_225 += V_221 ;
if ( F_68 ( V_102 ) )
V_220 -> V_226 += V_221 ;
if ( V_45 > V_220 -> V_227 )
V_220 -> V_227 = V_45 ;
V_220 -> V_228 [ F_175 ( V_102 ) ] += V_221 ;
}
static struct V_102 * F_176 ( V_24 V_115 , struct V_41 * V_42 ,
unsigned long V_116 )
{
struct V_102 * V_102 ;
int V_229 ;
if ( ! F_75 ( V_115 ) )
return NULL ;
V_102 = F_76 ( V_42 , V_116 , V_115 ) ;
if ( ! V_102 )
return NULL ;
if ( F_177 ( V_102 ) )
return NULL ;
V_229 = F_175 ( V_102 ) ;
if ( ! F_178 ( V_229 , V_230 [ V_231 ] ) )
return NULL ;
return V_102 ;
}
static int F_179 ( V_27 * V_121 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_219 * V_220 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
T_7 * V_125 ;
V_24 * V_201 ;
V_24 * V_115 ;
if ( F_90 ( V_121 , V_42 , & V_125 ) == 1 ) {
V_24 V_232 = * ( V_24 * ) V_121 ;
struct V_102 * V_102 ;
V_102 = F_176 ( V_232 , V_42 , V_116 ) ;
if ( V_102 )
F_170 ( V_102 , V_220 , F_84 ( V_232 ) ,
V_124 / V_30 ) ;
F_91 ( V_125 ) ;
return 0 ;
}
if ( F_92 ( V_121 ) )
return 0 ;
V_201 = V_115 = F_93 ( V_118 -> V_4 , V_121 , V_116 , & V_125 ) ;
do {
struct V_102 * V_102 = F_176 ( * V_115 , V_42 , V_116 ) ;
if ( ! V_102 )
continue;
F_170 ( V_102 , V_220 , F_84 ( * V_115 ) , 1 ) ;
} while ( V_115 ++ , V_116 += V_30 , V_116 != V_81 );
F_94 ( V_201 , V_125 ) ;
return 0 ;
}
static int F_180 ( V_24 * V_115 , unsigned long V_155 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
struct V_219 * V_220 ;
struct V_102 * V_102 ;
if ( ! F_75 ( * V_115 ) )
return 0 ;
V_102 = F_162 ( * V_115 ) ;
if ( ! V_102 )
return 0 ;
V_220 = V_118 -> V_48 ;
F_170 ( V_102 , V_220 , F_84 ( * V_115 ) , 1 ) ;
return 0 ;
}
static int F_180 ( V_24 * V_115 , unsigned long V_155 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
struct V_233 * V_234 = V_2 -> V_48 ;
struct V_35 * V_235 = & V_234 -> V_236 ;
struct V_41 * V_42 = V_58 ;
struct V_219 * V_220 = & V_234 -> V_220 ;
struct V_60 * V_60 = V_42 -> V_75 ;
struct V_3 * V_4 = V_42 -> V_74 ;
struct V_117 V_118 = {
. V_160 = F_180 ,
. V_159 = F_179 ,
. V_48 = V_220 ,
. V_4 = V_4 ,
} ;
struct V_237 * V_238 ;
char V_172 [ 64 ] ;
int V_229 ;
if ( ! V_4 )
return 0 ;
memset ( V_220 , 0 , sizeof( * V_220 ) ) ;
V_238 = F_182 ( V_42 , V_42 -> V_49 ) ;
if ( V_238 ) {
F_183 ( V_172 , sizeof( V_172 ) , V_238 ) ;
F_184 ( V_238 ) ;
} else {
F_183 ( V_172 , sizeof( V_172 ) , V_235 -> V_39 ) ;
}
F_7 ( V_2 , L_70 , V_42 -> V_49 , V_172 ) ;
if ( V_60 ) {
F_60 ( V_2 , L_71 ) ;
F_58 ( V_2 , V_60 , L_72 ) ;
} else if ( V_42 -> V_49 <= V_4 -> V_95 && V_42 -> V_87 >= V_4 -> V_96 ) {
F_60 ( V_2 , L_73 ) ;
} else {
T_2 V_94 = F_43 ( V_235 , V_42 , V_69 ) ;
if ( V_94 != 0 ) {
if ( ! V_69 || ( V_42 -> V_49 <= V_4 -> V_97 &&
V_42 -> V_87 >= V_4 -> V_97 ) )
F_60 ( V_2 , L_74 ) ;
else
F_7 ( V_2 , L_75 , V_94 ) ;
}
}
if ( F_185 ( V_42 ) )
F_60 ( V_2 , L_76 ) ;
F_105 ( V_42 , & V_118 ) ;
if ( ! V_220 -> V_222 )
goto V_168;
if ( V_220 -> V_226 )
F_7 ( V_2 , L_77 , V_220 -> V_226 ) ;
if ( V_220 -> V_104 )
F_7 ( V_2 , L_78 , V_220 -> V_104 ) ;
if ( V_220 -> V_222 != V_220 -> V_226 && V_220 -> V_222 != V_220 -> V_104 )
F_7 ( V_2 , L_79 , V_220 -> V_222 ) ;
if ( V_220 -> V_227 > 1 )
F_7 ( V_2 , L_80 , V_220 -> V_227 ) ;
if ( V_220 -> V_223 )
F_7 ( V_2 , L_81 , V_220 -> V_223 ) ;
if ( V_220 -> V_224 < V_220 -> V_222 && ! F_185 ( V_42 ) )
F_7 ( V_2 , L_82 , V_220 -> V_224 ) ;
if ( V_220 -> V_225 )
F_7 ( V_2 , L_83 , V_220 -> V_225 ) ;
F_186 (nid, N_MEMORY)
if ( V_220 -> V_228 [ V_229 ] )
F_7 ( V_2 , L_84 , V_229 , V_220 -> V_228 [ V_229 ] ) ;
F_7 ( V_2 , L_85 , F_106 ( V_42 ) >> 10 ) ;
V_168:
F_61 ( V_2 , '\n' ) ;
F_22 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 , void * V_58 )
{
return F_181 ( V_2 , V_58 , 1 ) ;
}
static int F_188 ( struct V_1 * V_2 , void * V_58 )
{
return F_181 ( V_2 , V_58 , 0 ) ;
}
static int F_189 ( struct V_53 * V_53 , struct V_60 * V_60 ,
const struct V_61 * V_62 )
{
return F_34 ( V_53 , V_60 , V_62 ,
sizeof( struct V_233 ) ) ;
}
static int F_190 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_189 ( V_53 , V_60 , & V_239 ) ;
}
static int F_191 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_189 ( V_53 , V_60 , & V_240 ) ;
}
