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
}
unsigned long F_8 ( struct V_3 * V_4 )
{
return V_30 * V_4 -> V_12 ;
}
unsigned long F_9 ( struct V_3 * V_4 ,
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
static void F_10 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
F_11 ( V_38 ) ;
V_36 -> V_39 = F_12 ( V_38 ) ;
F_13 ( V_36 -> V_39 ) ;
F_14 ( V_38 ) ;
}
static void F_15 ( struct V_35 * V_36 )
{
F_16 ( V_36 -> V_39 ) ;
}
static void F_10 ( struct V_35 * V_36 )
{
}
static void F_15 ( struct V_35 * V_36 )
{
}
static void F_17 ( struct V_35 * V_36 )
{
struct V_3 * V_4 = V_36 -> V_4 ;
F_15 ( V_36 ) ;
F_18 ( & V_4 -> V_40 ) ;
F_19 ( V_4 ) ;
}
static struct V_41 *
F_20 ( struct V_35 * V_36 , struct V_41 * V_42 )
{
if ( V_42 == V_36 -> V_43 )
return NULL ;
return V_42 -> V_44 ? : V_36 -> V_43 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
if ( V_2 -> V_45 < V_2 -> V_46 )
V_2 -> V_47 = F_20 ( V_2 -> V_48 , V_42 ) ? V_42 -> V_49 : - 1UL ;
}
static void * F_22 ( struct V_1 * V_2 , T_1 * V_50 )
{
struct V_35 * V_36 = V_2 -> V_48 ;
unsigned long V_51 = V_2 -> V_47 ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
unsigned int V_52 = * V_50 ;
if ( V_51 == - 1UL )
return NULL ;
V_36 -> V_38 = F_23 ( V_36 -> V_53 ) ;
if ( ! V_36 -> V_38 )
return F_24 ( - V_54 ) ;
V_4 = V_36 -> V_4 ;
if ( ! V_4 || ! F_25 ( & V_4 -> V_55 ) )
return NULL ;
F_26 ( & V_4 -> V_40 ) ;
F_10 ( V_36 ) ;
V_36 -> V_43 = F_27 ( V_4 ) ;
if ( V_51 ) {
V_42 = F_28 ( V_4 , V_51 ) ;
if ( V_42 && ( V_42 = F_20 ( V_36 , V_42 ) ) )
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
F_17 ( V_36 ) ;
return NULL ;
}
static void * F_29 ( struct V_1 * V_2 , void * V_58 , T_1 * V_52 )
{
struct V_35 * V_36 = V_2 -> V_48 ;
struct V_41 * V_59 ;
( * V_52 ) ++ ;
V_59 = F_20 ( V_36 , V_58 ) ;
if ( ! V_59 )
F_17 ( V_36 ) ;
return V_59 ;
}
static void F_30 ( struct V_1 * V_2 , void * V_58 )
{
struct V_35 * V_36 = V_2 -> V_48 ;
if ( ! F_31 ( V_58 ) )
F_17 ( V_36 ) ;
if ( V_36 -> V_38 ) {
F_32 ( V_36 -> V_38 ) ;
V_36 -> V_38 = NULL ;
}
}
static int F_33 ( struct V_53 * V_53 , struct V_60 * V_60 ,
const struct V_61 * V_62 , int V_63 )
{
struct V_35 * V_36 = F_34 ( V_60 , V_62 , V_63 ) ;
if ( ! V_36 )
return - V_64 ;
V_36 -> V_53 = V_53 ;
V_36 -> V_4 = F_35 ( V_53 , V_65 ) ;
if ( F_36 ( V_36 -> V_4 ) ) {
int V_66 = F_37 ( V_36 -> V_4 ) ;
F_38 ( V_53 , V_60 ) ;
return V_66 ;
}
return 0 ;
}
static int F_39 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
struct V_1 * V_67 = V_60 -> V_68 ;
struct V_35 * V_36 = V_67 -> V_48 ;
if ( V_36 -> V_4 )
F_40 ( V_36 -> V_4 ) ;
return F_38 ( V_53 , V_60 ) ;
}
static int F_41 ( struct V_53 * V_53 , struct V_60 * V_60 ,
const struct V_61 * V_62 )
{
return F_33 ( V_53 , V_60 , V_62 ,
sizeof( struct V_35 ) ) ;
}
static T_2 F_42 ( struct V_35 * V_36 ,
struct V_41 * V_42 , bool V_69 )
{
struct V_53 * V_53 = V_36 -> V_53 ;
struct V_37 * V_38 ;
T_2 V_70 = 0 ;
F_43 () ;
V_38 = F_44 ( F_45 ( V_53 ) , V_71 ) ;
if ( V_38 ) {
V_38 = F_46 ( V_38 , V_42 , V_69 ) ;
if ( V_38 )
V_70 = F_47 ( V_38 , V_53 -> V_72 -> V_73 ) ;
}
F_48 () ;
return V_70 ;
}
static void
F_49 ( struct V_1 * V_2 , struct V_41 * V_42 , int V_69 )
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
struct V_53 * V_53 = F_50 ( V_42 -> V_75 ) ;
V_82 = V_53 -> V_72 -> V_84 ;
V_78 = V_53 -> V_85 ;
V_79 = ( ( T_1 ) V_42 -> V_86 ) << V_21 ;
}
V_80 = V_42 -> V_49 ;
if ( F_51 ( V_42 , V_80 ) )
V_80 += V_30 ;
V_81 = V_42 -> V_87 ;
if ( F_52 ( V_42 , V_81 ) )
V_81 -= V_30 ;
F_53 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_7 ( V_2 , L_14 ,
V_80 ,
V_81 ,
V_76 & V_88 ? 'r' : '-' ,
V_76 & V_89 ? 'w' : '-' ,
V_76 & V_90 ? 'x' : '-' ,
V_76 & V_91 ? 's' : 'p' ,
V_79 ,
F_54 ( V_82 ) , F_55 ( V_82 ) , V_78 ) ;
if ( V_60 ) {
F_56 ( V_2 , ' ' ) ;
F_57 ( V_2 , V_60 , L_15 ) ;
goto V_92;
}
if ( V_42 -> V_93 && V_42 -> V_93 -> V_83 ) {
V_83 = V_42 -> V_93 -> V_83 ( V_42 ) ;
if ( V_83 )
goto V_92;
}
V_83 = F_58 ( V_42 ) ;
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
V_94 = F_42 ( V_36 , V_42 , V_69 ) ;
if ( V_94 != 0 ) {
if ( ! V_69 || ( V_42 -> V_49 <= V_4 -> V_97 &&
V_42 -> V_87 >= V_4 -> V_97 ) ) {
V_83 = L_18 ;
} else {
F_56 ( V_2 , ' ' ) ;
F_7 ( V_2 , L_19 , V_94 ) ;
}
}
}
V_92:
if ( V_83 ) {
F_56 ( V_2 , ' ' ) ;
F_59 ( V_2 , V_83 ) ;
}
F_60 ( V_2 , '\n' ) ;
}
static int F_61 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
F_49 ( V_2 , V_58 , V_69 ) ;
F_21 ( V_2 , V_58 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , void * V_58 )
{
return F_61 ( V_2 , V_58 , 1 ) ;
}
static int F_63 ( struct V_1 * V_2 , void * V_58 )
{
return F_61 ( V_2 , V_58 , 0 ) ;
}
static int F_64 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_41 ( V_53 , V_60 , & V_98 ) ;
}
static int F_65 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_41 ( V_53 , V_60 , & V_99 ) ;
}
static void F_66 ( struct V_100 * V_101 , struct V_102 * V_102 ,
unsigned long V_46 , bool V_103 , bool V_104 )
{
int V_105 ;
if ( F_67 ( V_102 ) )
V_101 -> V_106 += V_46 ;
V_101 -> V_32 += V_46 ;
if ( V_103 || F_68 ( V_102 ) )
V_101 -> V_107 += V_46 ;
V_105 = F_69 ( V_102 ) ;
if ( V_105 >= 2 ) {
T_5 V_108 ;
if ( V_104 || F_70 ( V_102 ) )
V_101 -> V_109 += V_46 ;
else
V_101 -> V_110 += V_46 ;
V_108 = ( T_5 ) V_46 << V_111 ;
F_71 ( V_108 , V_105 ) ;
V_101 -> V_112 += V_108 ;
} else {
if ( V_104 || F_70 ( V_102 ) )
V_101 -> V_113 += V_46 ;
else
V_101 -> V_114 += V_46 ;
V_101 -> V_112 += ( T_5 ) V_46 << V_111 ;
}
}
static void F_72 ( V_24 * V_115 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_100 * V_101 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_102 * V_102 = NULL ;
if ( F_73 ( * V_115 ) ) {
V_102 = F_74 ( V_42 , V_116 , * V_115 ) ;
} else if ( F_75 ( * V_115 ) ) {
T_6 V_119 = F_76 ( * V_115 ) ;
if ( ! F_77 ( V_119 ) )
V_101 -> V_8 += V_30 ;
else if ( F_78 ( V_119 ) )
V_102 = F_79 ( V_119 ) ;
}
if ( ! V_102 )
return;
F_66 ( V_101 , V_102 , V_30 , F_80 ( * V_115 ) , F_81 ( * V_115 ) ) ;
}
static void F_82 ( V_27 * V_120 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_100 * V_101 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_102 * V_102 ;
V_102 = F_83 ( V_42 , V_116 , V_120 , V_121 ) ;
if ( F_31 ( V_102 ) )
return;
V_101 -> V_122 += V_123 ;
F_66 ( V_101 , V_102 , V_123 ,
F_84 ( * V_120 ) , F_85 ( * V_120 ) ) ;
}
static void F_82 ( V_27 * V_120 , unsigned long V_116 ,
struct V_117 * V_118 )
{
}
static int F_86 ( V_27 * V_120 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 = V_118 -> V_42 ;
V_24 * V_115 ;
T_7 * V_124 ;
if ( F_87 ( V_120 , V_42 , & V_124 ) == 1 ) {
F_82 ( V_120 , V_116 , V_118 ) ;
F_88 ( V_124 ) ;
return 0 ;
}
if ( F_89 ( V_120 ) )
return 0 ;
V_115 = F_90 ( V_42 -> V_74 , V_120 , V_116 , & V_124 ) ;
for (; V_116 != V_81 ; V_115 ++ , V_116 += V_30 )
F_72 ( V_115 , V_116 , V_118 ) ;
F_91 ( V_115 - 1 , V_124 ) ;
F_92 () ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
static const char V_125 [ V_126 ] [ 2 ] = {
[ 0 ... ( V_126 - 1 ) ] = L_20 ,
[ F_94 ( V_88 ) ] = L_21 ,
[ F_94 ( V_89 ) ] = L_22 ,
[ F_94 ( V_90 ) ] = L_23 ,
[ F_94 ( V_127 ) ] = L_24 ,
[ F_94 ( V_128 ) ] = L_25 ,
[ F_94 ( V_129 ) ] = L_26 ,
[ F_94 ( V_130 ) ] = L_27 ,
[ F_94 ( V_91 ) ] = L_28 ,
[ F_94 ( V_131 ) ] = L_29 ,
[ F_94 ( V_132 ) ] = L_30 ,
[ F_94 ( V_133 ) ] = L_31 ,
#ifdef F_95
[ F_94 ( V_134 ) ] = L_32 ,
#endif
[ F_94 ( V_135 ) ] = L_33 ,
[ F_94 ( V_136 ) ] = L_34 ,
[ F_94 ( V_137 ) ] = L_35 ,
[ F_94 ( V_138 ) ] = L_36 ,
[ F_94 ( V_139 ) ] = L_37 ,
[ F_94 ( V_140 ) ] = L_38 ,
[ F_94 ( V_141 ) ] = L_39 ,
[ F_94 ( V_142 ) ] = L_40 ,
[ F_94 ( V_143 ) ] = L_41 ,
[ F_94 ( V_144 ) ] = L_42 ,
[ F_94 ( V_145 ) ] = L_43 ,
#ifdef F_96
[ F_94 ( V_146 ) ] = L_44 ,
#endif
[ F_94 ( V_147 ) ] = L_45 ,
[ F_94 ( V_148 ) ] = L_46 ,
[ F_94 ( V_149 ) ] = L_47 ,
[ F_94 ( V_150 ) ] = L_48 ,
} ;
T_8 V_151 ;
F_59 ( V_2 , L_49 ) ;
for ( V_151 = 0 ; V_151 < V_126 ; V_151 ++ ) {
if ( V_42 -> V_77 & ( 1UL << V_151 ) ) {
F_7 ( V_2 , L_50 ,
V_125 [ V_151 ] [ 0 ] , V_125 [ V_151 ] [ 1 ] ) ;
}
}
F_60 ( V_2 , '\n' ) ;
}
static int F_97 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
struct V_41 * V_42 = V_58 ;
struct V_100 V_101 ;
struct V_117 V_152 = {
. V_153 = F_86 ,
. V_4 = V_42 -> V_74 ,
. V_48 = & V_101 ,
} ;
memset ( & V_101 , 0 , sizeof V_101 ) ;
F_98 ( V_42 , & V_152 ) ;
F_49 ( V_2 , V_42 , V_69 ) ;
F_7 ( V_2 ,
L_51
L_52
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
L_64 ,
( V_42 -> V_87 - V_42 -> V_49 ) >> 10 ,
V_101 . V_32 >> 10 ,
( unsigned long ) ( V_101 . V_112 >> ( 10 + V_111 ) ) ,
V_101 . V_110 >> 10 ,
V_101 . V_109 >> 10 ,
V_101 . V_114 >> 10 ,
V_101 . V_113 >> 10 ,
V_101 . V_107 >> 10 ,
V_101 . V_106 >> 10 ,
V_101 . V_122 >> 10 ,
V_101 . V_8 >> 10 ,
F_99 ( V_42 ) >> 10 ,
F_100 ( V_42 ) >> 10 ,
( V_42 -> V_77 & V_135 ) ?
( unsigned long ) ( V_101 . V_112 >> ( 10 + V_111 ) ) : 0 ) ;
F_93 ( V_2 , V_42 ) ;
F_21 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 , void * V_58 )
{
return F_97 ( V_2 , V_58 , 1 ) ;
}
static int F_102 ( struct V_1 * V_2 , void * V_58 )
{
return F_97 ( V_2 , V_58 , 0 ) ;
}
static int F_103 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_41 ( V_53 , V_60 , & V_154 ) ;
}
static int F_104 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_41 ( V_53 , V_60 , & V_155 ) ;
}
static inline void F_105 ( struct V_41 * V_42 ,
unsigned long V_116 , V_24 * V_115 )
{
V_24 V_156 = * V_115 ;
if ( F_73 ( V_156 ) ) {
V_156 = F_106 ( V_156 ) ;
V_156 = F_107 ( V_156 , V_157 ) ;
} else if ( F_75 ( V_156 ) ) {
V_156 = F_108 ( V_156 ) ;
}
F_109 ( V_42 -> V_74 , V_116 , V_115 , V_156 ) ;
}
static inline void F_110 ( struct V_41 * V_42 ,
unsigned long V_116 , V_27 * V_158 )
{
V_27 V_120 = * V_158 ;
V_120 = F_111 ( V_120 ) ;
V_120 = F_112 ( V_120 , V_157 ) ;
if ( V_42 -> V_77 & V_146 )
V_42 -> V_77 &= ~ V_146 ;
F_113 ( V_42 -> V_74 , V_116 , V_158 , V_120 ) ;
}
static inline void F_105 ( struct V_41 * V_42 ,
unsigned long V_116 , V_24 * V_115 )
{
}
static inline void F_110 ( struct V_41 * V_42 ,
unsigned long V_116 , V_27 * V_158 )
{
}
static int F_114 ( V_27 * V_120 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_159 * V_160 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
V_24 * V_115 , V_156 ;
T_7 * V_124 ;
struct V_102 * V_102 ;
if ( F_87 ( V_120 , V_42 , & V_124 ) == 1 ) {
if ( V_160 -> type == V_161 ) {
F_110 ( V_42 , V_116 , V_120 ) ;
goto V_162;
}
V_102 = F_115 ( * V_120 ) ;
F_116 ( V_42 , V_116 , V_120 ) ;
F_117 ( V_102 ) ;
V_162:
F_88 ( V_124 ) ;
return 0 ;
}
if ( F_89 ( V_120 ) )
return 0 ;
V_115 = F_90 ( V_42 -> V_74 , V_120 , V_116 , & V_124 ) ;
for (; V_116 != V_81 ; V_115 ++ , V_116 += V_30 ) {
V_156 = * V_115 ;
if ( V_160 -> type == V_161 ) {
F_105 ( V_42 , V_116 , V_115 ) ;
continue;
}
if ( ! F_73 ( V_156 ) )
continue;
V_102 = F_74 ( V_42 , V_116 , V_156 ) ;
if ( ! V_102 )
continue;
F_118 ( V_42 , V_116 , V_115 ) ;
F_117 ( V_102 ) ;
}
F_91 ( V_115 - 1 , V_124 ) ;
F_92 () ;
return 0 ;
}
static int F_119 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_159 * V_160 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
if ( V_42 -> V_77 & V_132 )
return 1 ;
if ( V_160 -> type == V_163 && V_42 -> V_75 )
return 1 ;
if ( V_160 -> type == V_164 && ! V_42 -> V_75 )
return 1 ;
return 0 ;
}
static T_9 F_120 ( struct V_60 * V_60 , const char T_10 * V_165 ,
T_8 V_45 , T_1 * V_50 )
{
struct V_37 * V_38 ;
char V_166 [ V_167 ] ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
enum V_168 type ;
int V_169 ;
int V_170 ;
memset ( V_166 , 0 , sizeof( V_166 ) ) ;
if ( V_45 > sizeof( V_166 ) - 1 )
V_45 = sizeof( V_166 ) - 1 ;
if ( F_121 ( V_166 , V_165 , V_45 ) )
return - V_171 ;
V_170 = F_122 ( F_123 ( V_166 ) , 10 , & V_169 ) ;
if ( V_170 < 0 )
return V_170 ;
type = (enum V_168 ) V_169 ;
if ( type < V_172 || type >= V_173 )
return - V_174 ;
if ( type == V_161 ) {
V_175 = true ;
F_124 ( L_65
L_66
L_67 ) ;
}
V_38 = F_23 ( F_50 ( V_60 ) ) ;
if ( ! V_38 )
return - V_54 ;
V_4 = F_125 ( V_38 ) ;
if ( V_4 ) {
struct V_159 V_160 = {
. type = type ,
} ;
struct V_117 V_176 = {
. V_153 = F_114 ,
. V_177 = F_119 ,
. V_4 = V_4 ,
. V_48 = & V_160 ,
} ;
if ( type == V_178 ) {
F_126 ( & V_4 -> V_40 ) ;
F_127 ( V_4 ) ;
F_128 ( & V_4 -> V_40 ) ;
goto V_179;
}
F_26 ( & V_4 -> V_40 ) ;
if ( type == V_161 ) {
for ( V_42 = V_4 -> V_57 ; V_42 ; V_42 = V_42 -> V_44 ) {
if ( ! ( V_42 -> V_77 & V_146 ) )
continue;
F_18 ( & V_4 -> V_40 ) ;
F_126 ( & V_4 -> V_40 ) ;
for ( V_42 = V_4 -> V_57 ; V_42 ; V_42 = V_42 -> V_44 ) {
V_42 -> V_77 &= ~ V_146 ;
F_129 ( V_42 ) ;
}
F_130 ( & V_4 -> V_40 ) ;
break;
}
F_131 ( V_4 , 0 , - 1 ) ;
}
F_132 ( 0 , ~ 0UL , & V_176 ) ;
if ( type == V_161 )
F_133 ( V_4 , 0 , - 1 ) ;
F_134 ( V_4 ) ;
F_18 ( & V_4 -> V_40 ) ;
V_179:
F_19 ( V_4 ) ;
}
F_32 ( V_38 ) ;
return V_45 ;
}
static inline T_11 F_135 ( T_5 V_180 )
{
return ( T_11 ) { . V_181 = V_180 } ;
}
static int F_136 ( unsigned long V_116 , T_11 * V_181 ,
struct V_182 * V_183 )
{
V_183 -> V_166 [ V_183 -> V_52 ++ ] = * V_181 ;
if ( V_183 -> V_52 >= V_183 -> V_184 )
return V_185 ;
return 0 ;
}
static int F_137 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_182 * V_183 = V_118 -> V_48 ;
unsigned long V_116 = V_80 ;
int V_66 = 0 ;
while ( V_116 < V_81 ) {
struct V_41 * V_42 = F_28 ( V_118 -> V_4 , V_116 ) ;
T_11 V_181 = F_135 ( F_138 ( V_183 -> V_186 ) ) ;
unsigned long V_187 ;
if ( V_42 )
V_187 = F_139 ( V_81 , V_42 -> V_49 ) ;
else
V_187 = V_81 ;
for (; V_116 < V_187 ; V_116 += V_30 ) {
V_66 = F_136 ( V_116 , & V_181 , V_183 ) ;
if ( V_66 )
goto V_162;
}
if ( ! V_42 )
break;
if ( V_42 -> V_77 & V_146 )
V_181 . V_181 |= F_140 ( V_183 -> V_186 , V_188 ) ;
for (; V_116 < F_139 ( V_81 , V_42 -> V_87 ) ; V_116 += V_30 ) {
V_66 = F_136 ( V_116 , & V_181 , V_183 ) ;
if ( V_66 )
goto V_162;
}
}
V_162:
return V_66 ;
}
static void F_141 ( T_11 * V_181 , struct V_182 * V_183 ,
struct V_41 * V_42 , unsigned long V_116 , V_24 V_115 )
{
T_5 V_189 , V_76 ;
struct V_102 * V_102 = NULL ;
int V_190 = 0 ;
if ( F_73 ( V_115 ) ) {
V_189 = F_142 ( V_115 ) ;
V_76 = V_191 ;
V_102 = F_74 ( V_42 , V_116 , V_115 ) ;
if ( F_143 ( V_115 ) )
V_190 |= V_188 ;
} else if ( F_75 ( V_115 ) ) {
T_6 V_192 ;
if ( F_144 ( V_115 ) )
V_190 |= V_188 ;
V_192 = F_76 ( V_115 ) ;
V_189 = F_145 ( V_192 ) |
( F_146 ( V_192 ) << V_193 ) ;
V_76 = V_194 ;
if ( F_78 ( V_192 ) )
V_102 = F_79 ( V_192 ) ;
} else {
if ( V_42 -> V_77 & V_146 )
V_190 |= V_188 ;
* V_181 = F_135 ( F_138 ( V_183 -> V_186 ) | F_140 ( V_183 -> V_186 , V_190 ) ) ;
return;
}
if ( V_102 && ! F_67 ( V_102 ) )
V_76 |= V_195 ;
if ( ( V_42 -> V_77 & V_146 ) )
V_190 |= V_188 ;
* V_181 = F_135 ( F_147 ( V_189 ) | F_140 ( V_183 -> V_186 , V_190 ) | V_76 ) ;
}
static void F_148 ( T_11 * V_181 , struct V_182 * V_183 ,
V_27 V_120 , int V_196 , int V_197 )
{
if ( F_149 ( V_120 ) )
* V_181 = F_135 ( F_147 ( F_150 ( V_120 ) + V_196 )
| F_140 ( V_183 -> V_186 , V_197 ) | V_191 ) ;
else
* V_181 = F_135 ( F_138 ( V_183 -> V_186 ) | F_140 ( V_183 -> V_186 , V_197 ) ) ;
}
static inline void F_148 ( T_11 * V_181 , struct V_182 * V_183 ,
V_27 V_120 , int V_196 , int V_197 )
{
}
static int F_151 ( V_27 * V_120 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_182 * V_183 = V_118 -> V_48 ;
T_7 * V_124 ;
V_24 * V_115 , * V_198 ;
int V_66 = 0 ;
if ( F_87 ( V_120 , V_42 , & V_124 ) == 1 ) {
int V_197 ;
if ( ( V_42 -> V_77 & V_146 ) || F_152 ( * V_120 ) )
V_197 = V_188 ;
else
V_197 = 0 ;
for (; V_116 != V_81 ; V_116 += V_30 ) {
unsigned long V_196 ;
T_11 V_181 ;
V_196 = ( V_116 & ~ V_199 ) >>
V_21 ;
F_148 ( & V_181 , V_183 , * V_120 , V_196 , V_197 ) ;
V_66 = F_136 ( V_116 , & V_181 , V_183 ) ;
if ( V_66 )
break;
}
F_88 ( V_124 ) ;
return V_66 ;
}
if ( F_89 ( V_120 ) )
return 0 ;
V_198 = V_115 = F_90 ( V_118 -> V_4 , V_120 , V_116 , & V_124 ) ;
for (; V_116 < V_81 ; V_115 ++ , V_116 += V_30 ) {
T_11 V_181 ;
F_141 ( & V_181 , V_183 , V_42 , V_116 , * V_115 ) ;
V_66 = F_136 ( V_116 , & V_181 , V_183 ) ;
if ( V_66 )
break;
}
F_91 ( V_198 , V_124 ) ;
F_92 () ;
return V_66 ;
}
static void F_153 ( T_11 * V_181 , struct V_182 * V_183 ,
V_24 V_115 , int V_196 , int V_190 )
{
if ( F_73 ( V_115 ) )
* V_181 = F_135 ( F_147 ( F_142 ( V_115 ) + V_196 ) |
F_140 ( V_183 -> V_186 , V_190 ) |
V_191 ) ;
else
* V_181 = F_135 ( F_138 ( V_183 -> V_186 ) |
F_140 ( V_183 -> V_186 , V_190 ) ) ;
}
static int F_154 ( V_24 * V_115 , unsigned long V_200 ,
unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_182 * V_183 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
int V_66 = 0 ;
int V_190 ;
T_11 V_181 ;
if ( V_42 -> V_77 & V_146 )
V_190 = V_188 ;
else
V_190 = 0 ;
for (; V_116 != V_81 ; V_116 += V_30 ) {
int V_196 = ( V_116 & ~ V_200 ) >> V_21 ;
F_153 ( & V_181 , V_183 , * V_115 , V_196 , V_190 ) ;
V_66 = F_136 ( V_116 , & V_181 , V_183 ) ;
if ( V_66 )
return V_66 ;
}
F_92 () ;
return V_66 ;
}
static T_9 F_155 ( struct V_60 * V_60 , char T_10 * V_165 ,
T_8 V_45 , T_1 * V_50 )
{
struct V_37 * V_38 = F_23 ( F_50 ( V_60 ) ) ;
struct V_3 * V_4 ;
struct V_182 V_183 ;
int V_70 = - V_54 ;
struct V_117 V_201 = {} ;
unsigned long V_202 ;
unsigned long V_203 ;
unsigned long V_204 ;
unsigned long V_205 ;
int V_206 = 0 ;
if ( ! V_38 )
goto V_162;
V_70 = - V_174 ;
if ( ( * V_50 % V_207 ) || ( V_45 % V_207 ) )
goto V_208;
V_70 = 0 ;
if ( ! V_45 )
goto V_208;
V_183 . V_186 = V_175 ;
V_183 . V_184 = ( V_209 >> V_21 ) ;
V_183 . V_166 = F_156 ( V_183 . V_184 * V_207 , V_210 ) ;
V_70 = - V_64 ;
if ( ! V_183 . V_166 )
goto V_208;
V_4 = F_157 ( V_38 , V_65 ) ;
V_70 = F_37 ( V_4 ) ;
if ( ! V_4 || F_36 ( V_4 ) )
goto V_211;
V_201 . V_153 = F_151 ;
V_201 . V_212 = F_137 ;
#ifdef F_158
V_201 . V_213 = F_154 ;
#endif
V_201 . V_4 = V_4 ;
V_201 . V_48 = & V_183 ;
V_202 = * V_50 ;
V_203 = V_202 / V_207 ;
V_204 = V_203 << V_21 ;
V_205 = F_159 ( V_38 ) ;
if ( V_203 > F_159 ( V_38 ) >> V_21 )
V_204 = V_205 ;
V_70 = 0 ;
while ( V_45 && ( V_204 < V_205 ) ) {
int V_184 ;
unsigned long V_81 ;
V_183 . V_52 = 0 ;
V_81 = ( V_204 + V_209 ) & V_199 ;
if ( V_81 < V_204 || V_81 > V_205 )
V_81 = V_205 ;
F_26 ( & V_4 -> V_40 ) ;
V_70 = F_132 ( V_204 , V_81 , & V_201 ) ;
F_18 ( & V_4 -> V_40 ) ;
V_204 = V_81 ;
V_184 = F_139 ( V_45 , V_207 * V_183 . V_52 ) ;
if ( F_160 ( V_165 , V_183 . V_166 , V_184 ) ) {
V_70 = - V_171 ;
goto V_179;
}
V_206 += V_184 ;
V_165 += V_184 ;
V_45 -= V_184 ;
}
* V_50 += V_206 ;
if ( ! V_70 || V_70 == V_185 )
V_70 = V_206 ;
V_179:
F_19 ( V_4 ) ;
V_211:
F_161 ( V_183 . V_166 ) ;
V_208:
F_32 ( V_38 ) ;
V_162:
return V_70 ;
}
static int F_162 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
if ( ! F_163 ( V_214 ) )
return - V_215 ;
F_124 ( L_68
L_69
L_70 ) ;
return 0 ;
}
static void F_164 ( struct V_102 * V_102 , struct V_216 * V_217 , int F_81 ,
unsigned long V_218 )
{
int V_45 = F_69 ( V_102 ) ;
V_217 -> V_219 += V_218 ;
if ( F_81 || F_70 ( V_102 ) )
V_217 -> V_104 += V_218 ;
if ( F_165 ( V_102 ) )
V_217 -> V_220 += V_218 ;
if ( F_166 ( V_102 ) || F_167 ( V_102 ) )
V_217 -> V_221 += V_218 ;
if ( F_168 ( V_102 ) )
V_217 -> V_222 += V_218 ;
if ( F_67 ( V_102 ) )
V_217 -> V_223 += V_218 ;
if ( V_45 > V_217 -> V_224 )
V_217 -> V_224 = V_45 ;
V_217 -> V_225 [ F_169 ( V_102 ) ] += V_218 ;
}
static struct V_102 * F_170 ( V_24 V_115 , struct V_41 * V_42 ,
unsigned long V_116 )
{
struct V_102 * V_102 ;
int V_226 ;
if ( ! F_73 ( V_115 ) )
return NULL ;
V_102 = F_74 ( V_42 , V_116 , V_115 ) ;
if ( ! V_102 )
return NULL ;
if ( F_171 ( V_102 ) )
return NULL ;
V_226 = F_169 ( V_102 ) ;
if ( ! F_172 ( V_226 , V_227 [ V_228 ] ) )
return NULL ;
return V_102 ;
}
static int F_173 ( V_27 * V_120 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_216 * V_217 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
T_7 * V_124 ;
V_24 * V_198 ;
V_24 * V_115 ;
if ( F_87 ( V_120 , V_42 , & V_124 ) == 1 ) {
V_24 V_229 = * ( V_24 * ) V_120 ;
struct V_102 * V_102 ;
V_102 = F_170 ( V_229 , V_42 , V_116 ) ;
if ( V_102 )
F_164 ( V_102 , V_217 , F_81 ( V_229 ) ,
V_123 / V_30 ) ;
F_88 ( V_124 ) ;
return 0 ;
}
if ( F_89 ( V_120 ) )
return 0 ;
V_198 = V_115 = F_90 ( V_118 -> V_4 , V_120 , V_116 , & V_124 ) ;
do {
struct V_102 * V_102 = F_170 ( * V_115 , V_42 , V_116 ) ;
if ( ! V_102 )
continue;
F_164 ( V_102 , V_217 , F_81 ( * V_115 ) , 1 ) ;
} while ( V_115 ++ , V_116 += V_30 , V_116 != V_81 );
F_91 ( V_198 , V_124 ) ;
return 0 ;
}
static int F_174 ( V_24 * V_115 , unsigned long V_200 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
struct V_216 * V_217 ;
struct V_102 * V_102 ;
if ( ! F_73 ( * V_115 ) )
return 0 ;
V_102 = F_175 ( * V_115 ) ;
if ( ! V_102 )
return 0 ;
V_217 = V_118 -> V_48 ;
F_164 ( V_102 , V_217 , F_81 ( * V_115 ) , 1 ) ;
return 0 ;
}
static int F_174 ( V_24 * V_115 , unsigned long V_200 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
return 0 ;
}
static int F_176 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
struct V_230 * V_231 = V_2 -> V_48 ;
struct V_35 * V_232 = & V_231 -> V_233 ;
struct V_41 * V_42 = V_58 ;
struct V_216 * V_217 = & V_231 -> V_217 ;
struct V_60 * V_60 = V_42 -> V_75 ;
struct V_3 * V_4 = V_42 -> V_74 ;
struct V_117 V_118 = {
. V_213 = F_174 ,
. V_153 = F_173 ,
. V_48 = V_217 ,
. V_4 = V_4 ,
} ;
struct V_234 * V_235 ;
char V_166 [ 64 ] ;
int V_226 ;
if ( ! V_4 )
return 0 ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_235 = F_177 ( V_42 , V_42 -> V_49 ) ;
if ( V_235 ) {
F_178 ( V_166 , sizeof( V_166 ) , V_235 ) ;
F_179 ( V_235 ) ;
} else {
F_178 ( V_166 , sizeof( V_166 ) , V_232 -> V_39 ) ;
}
F_7 ( V_2 , L_71 , V_42 -> V_49 , V_166 ) ;
if ( V_60 ) {
F_59 ( V_2 , L_72 ) ;
F_57 ( V_2 , V_60 , L_73 ) ;
} else if ( V_42 -> V_49 <= V_4 -> V_95 && V_42 -> V_87 >= V_4 -> V_96 ) {
F_59 ( V_2 , L_74 ) ;
} else {
T_2 V_94 = F_42 ( V_232 , V_42 , V_69 ) ;
if ( V_94 != 0 ) {
if ( ! V_69 || ( V_42 -> V_49 <= V_4 -> V_97 &&
V_42 -> V_87 >= V_4 -> V_97 ) )
F_59 ( V_2 , L_75 ) ;
else
F_7 ( V_2 , L_76 , V_94 ) ;
}
}
if ( F_180 ( V_42 ) )
F_59 ( V_2 , L_77 ) ;
F_98 ( V_42 , & V_118 ) ;
if ( ! V_217 -> V_219 )
goto V_162;
if ( V_217 -> V_223 )
F_7 ( V_2 , L_78 , V_217 -> V_223 ) ;
if ( V_217 -> V_104 )
F_7 ( V_2 , L_79 , V_217 -> V_104 ) ;
if ( V_217 -> V_219 != V_217 -> V_223 && V_217 -> V_219 != V_217 -> V_104 )
F_7 ( V_2 , L_80 , V_217 -> V_219 ) ;
if ( V_217 -> V_224 > 1 )
F_7 ( V_2 , L_81 , V_217 -> V_224 ) ;
if ( V_217 -> V_220 )
F_7 ( V_2 , L_82 , V_217 -> V_220 ) ;
if ( V_217 -> V_221 < V_217 -> V_219 && ! F_180 ( V_42 ) )
F_7 ( V_2 , L_83 , V_217 -> V_221 ) ;
if ( V_217 -> V_222 )
F_7 ( V_2 , L_84 , V_217 -> V_222 ) ;
F_181 (nid, N_MEMORY)
if ( V_217 -> V_225 [ V_226 ] )
F_7 ( V_2 , L_85 , V_226 , V_217 -> V_225 [ V_226 ] ) ;
F_7 ( V_2 , L_86 , F_99 ( V_42 ) >> 10 ) ;
V_162:
F_60 ( V_2 , '\n' ) ;
F_21 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 , void * V_58 )
{
return F_176 ( V_2 , V_58 , 1 ) ;
}
static int F_183 ( struct V_1 * V_2 , void * V_58 )
{
return F_176 ( V_2 , V_58 , 0 ) ;
}
static int F_184 ( struct V_53 * V_53 , struct V_60 * V_60 ,
const struct V_61 * V_62 )
{
return F_33 ( V_53 , V_60 , V_62 ,
sizeof( struct V_230 ) ) ;
}
static int F_185 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_184 ( V_53 , V_60 , & V_236 ) ;
}
static int F_186 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_184 ( V_53 , V_60 , & V_237 ) ;
}
