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
if ( V_103 || F_68 ( V_102 ) || F_69 ( V_102 ) )
V_101 -> V_107 += V_46 ;
V_105 = F_70 ( V_102 ) ;
if ( V_105 >= 2 ) {
T_5 V_108 ;
if ( V_104 || F_71 ( V_102 ) )
V_101 -> V_109 += V_46 ;
else
V_101 -> V_110 += V_46 ;
V_108 = ( T_5 ) V_46 << V_111 ;
F_72 ( V_108 , V_105 ) ;
V_101 -> V_112 += V_108 ;
} else {
if ( V_104 || F_71 ( V_102 ) )
V_101 -> V_113 += V_46 ;
else
V_101 -> V_114 += V_46 ;
V_101 -> V_112 += ( T_5 ) V_46 << V_111 ;
}
}
static void F_73 ( V_24 * V_115 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_100 * V_101 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_102 * V_102 = NULL ;
if ( F_74 ( * V_115 ) ) {
V_102 = F_75 ( V_42 , V_116 , * V_115 ) ;
} else if ( F_76 ( * V_115 ) ) {
T_6 V_119 = F_77 ( * V_115 ) ;
if ( ! F_78 ( V_119 ) ) {
int V_105 ;
V_101 -> V_8 += V_30 ;
V_105 = F_79 ( V_119 ) ;
if ( V_105 >= 2 ) {
T_5 V_108 = ( T_5 ) V_30 << V_111 ;
F_72 ( V_108 , V_105 ) ;
V_101 -> V_120 += V_108 ;
} else {
V_101 -> V_120 += ( T_5 ) V_30 << V_111 ;
}
} else if ( F_80 ( V_119 ) )
V_102 = F_81 ( V_119 ) ;
}
if ( ! V_102 )
return;
F_66 ( V_101 , V_102 , V_30 , F_82 ( * V_115 ) , F_83 ( * V_115 ) ) ;
}
static void F_84 ( V_27 * V_121 , unsigned long V_116 ,
struct V_117 * V_118 )
{
struct V_100 * V_101 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_102 * V_102 ;
V_102 = F_85 ( V_42 , V_116 , V_121 , V_122 ) ;
if ( F_31 ( V_102 ) )
return;
V_101 -> V_123 += V_124 ;
F_66 ( V_101 , V_102 , V_124 ,
F_86 ( * V_121 ) , F_87 ( * V_121 ) ) ;
}
static void F_84 ( V_27 * V_121 , unsigned long V_116 ,
struct V_117 * V_118 )
{
}
static int F_88 ( V_27 * V_121 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 = V_118 -> V_42 ;
V_24 * V_115 ;
T_7 * V_125 ;
if ( F_89 ( V_121 , V_42 , & V_125 ) == 1 ) {
F_84 ( V_121 , V_116 , V_118 ) ;
F_90 ( V_125 ) ;
return 0 ;
}
if ( F_91 ( V_121 ) )
return 0 ;
V_115 = F_92 ( V_42 -> V_74 , V_121 , V_116 , & V_125 ) ;
for (; V_116 != V_81 ; V_115 ++ , V_116 += V_30 )
F_73 ( V_115 , V_116 , V_118 ) ;
F_93 ( V_115 - 1 , V_125 ) ;
F_94 () ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
static const char V_126 [ V_127 ] [ 2 ] = {
[ 0 ... ( V_127 - 1 ) ] = L_20 ,
[ F_96 ( V_88 ) ] = L_21 ,
[ F_96 ( V_89 ) ] = L_22 ,
[ F_96 ( V_90 ) ] = L_23 ,
[ F_96 ( V_128 ) ] = L_24 ,
[ F_96 ( V_129 ) ] = L_25 ,
[ F_96 ( V_130 ) ] = L_26 ,
[ F_96 ( V_131 ) ] = L_27 ,
[ F_96 ( V_91 ) ] = L_28 ,
[ F_96 ( V_132 ) ] = L_29 ,
[ F_96 ( V_133 ) ] = L_30 ,
[ F_96 ( V_134 ) ] = L_31 ,
#ifdef F_97
[ F_96 ( V_135 ) ] = L_32 ,
#endif
[ F_96 ( V_136 ) ] = L_33 ,
[ F_96 ( V_137 ) ] = L_34 ,
[ F_96 ( V_138 ) ] = L_35 ,
[ F_96 ( V_139 ) ] = L_36 ,
[ F_96 ( V_140 ) ] = L_37 ,
[ F_96 ( V_141 ) ] = L_38 ,
[ F_96 ( V_142 ) ] = L_39 ,
[ F_96 ( V_143 ) ] = L_40 ,
[ F_96 ( V_144 ) ] = L_41 ,
[ F_96 ( V_145 ) ] = L_42 ,
[ F_96 ( V_146 ) ] = L_43 ,
#ifdef F_98
[ F_96 ( V_147 ) ] = L_44 ,
#endif
[ F_96 ( V_148 ) ] = L_45 ,
[ F_96 ( V_149 ) ] = L_46 ,
[ F_96 ( V_150 ) ] = L_47 ,
[ F_96 ( V_151 ) ] = L_48 ,
[ F_96 ( V_152 ) ] = L_49 ,
[ F_96 ( V_153 ) ] = L_50 ,
} ;
T_8 V_154 ;
F_59 ( V_2 , L_51 ) ;
for ( V_154 = 0 ; V_154 < V_127 ; V_154 ++ ) {
if ( V_42 -> V_77 & ( 1UL << V_154 ) ) {
F_7 ( V_2 , L_52 ,
V_126 [ V_154 ] [ 0 ] , V_126 [ V_154 ] [ 1 ] ) ;
}
}
F_60 ( V_2 , '\n' ) ;
}
static int F_99 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
struct V_41 * V_42 = V_58 ;
struct V_100 V_101 ;
struct V_117 V_155 = {
. V_156 = F_88 ,
. V_4 = V_42 -> V_74 ,
. V_48 = & V_101 ,
} ;
memset ( & V_101 , 0 , sizeof V_101 ) ;
F_100 ( V_42 , & V_155 ) ;
F_49 ( V_2 , V_42 , V_69 ) ;
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
L_67 ,
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
V_101 . V_8 >> 10 ,
( unsigned long ) ( V_101 . V_120 >> ( 10 + V_111 ) ) ,
F_101 ( V_42 ) >> 10 ,
F_102 ( V_42 ) >> 10 ,
( V_42 -> V_77 & V_136 ) ?
( unsigned long ) ( V_101 . V_112 >> ( 10 + V_111 ) ) : 0 ) ;
F_95 ( V_2 , V_42 ) ;
F_21 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , void * V_58 )
{
return F_99 ( V_2 , V_58 , 1 ) ;
}
static int F_104 ( struct V_1 * V_2 , void * V_58 )
{
return F_99 ( V_2 , V_58 , 0 ) ;
}
static int F_105 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_41 ( V_53 , V_60 , & V_157 ) ;
}
static int F_106 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_41 ( V_53 , V_60 , & V_158 ) ;
}
static inline void F_107 ( struct V_41 * V_42 ,
unsigned long V_116 , V_24 * V_115 )
{
V_24 V_159 = * V_115 ;
if ( F_74 ( V_159 ) ) {
V_159 = F_108 ( V_159 ) ;
V_159 = F_109 ( V_159 , V_160 ) ;
} else if ( F_76 ( V_159 ) ) {
V_159 = F_110 ( V_159 ) ;
}
F_111 ( V_42 -> V_74 , V_116 , V_115 , V_159 ) ;
}
static inline void F_112 ( struct V_41 * V_42 ,
unsigned long V_116 , V_27 * V_161 )
{
V_27 V_121 = * V_161 ;
V_121 = F_113 ( V_121 ) ;
V_121 = F_114 ( V_121 , V_160 ) ;
if ( V_42 -> V_77 & V_147 )
V_42 -> V_77 &= ~ V_147 ;
F_115 ( V_42 -> V_74 , V_116 , V_161 , V_121 ) ;
}
static inline void F_107 ( struct V_41 * V_42 ,
unsigned long V_116 , V_24 * V_115 )
{
}
static inline void F_112 ( struct V_41 * V_42 ,
unsigned long V_116 , V_27 * V_161 )
{
}
static int F_116 ( V_27 * V_121 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_162 * V_163 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
V_24 * V_115 , V_159 ;
T_7 * V_125 ;
struct V_102 * V_102 ;
if ( F_89 ( V_121 , V_42 , & V_125 ) == 1 ) {
if ( V_163 -> type == V_164 ) {
F_112 ( V_42 , V_116 , V_121 ) ;
goto V_165;
}
V_102 = F_117 ( * V_121 ) ;
F_118 ( V_42 , V_116 , V_121 ) ;
F_119 ( V_102 ) ;
F_120 ( V_102 ) ;
V_165:
F_90 ( V_125 ) ;
return 0 ;
}
if ( F_91 ( V_121 ) )
return 0 ;
V_115 = F_92 ( V_42 -> V_74 , V_121 , V_116 , & V_125 ) ;
for (; V_116 != V_81 ; V_115 ++ , V_116 += V_30 ) {
V_159 = * V_115 ;
if ( V_163 -> type == V_164 ) {
F_107 ( V_42 , V_116 , V_115 ) ;
continue;
}
if ( ! F_74 ( V_159 ) )
continue;
V_102 = F_75 ( V_42 , V_116 , V_159 ) ;
if ( ! V_102 )
continue;
F_121 ( V_42 , V_116 , V_115 ) ;
F_119 ( V_102 ) ;
F_120 ( V_102 ) ;
}
F_93 ( V_115 - 1 , V_125 ) ;
F_94 () ;
return 0 ;
}
static int F_122 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_162 * V_163 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
if ( V_42 -> V_77 & V_133 )
return 1 ;
if ( V_163 -> type == V_166 && V_42 -> V_75 )
return 1 ;
if ( V_163 -> type == V_167 && ! V_42 -> V_75 )
return 1 ;
return 0 ;
}
static T_9 F_123 ( struct V_60 * V_60 , const char T_10 * V_168 ,
T_8 V_45 , T_1 * V_50 )
{
struct V_37 * V_38 ;
char V_169 [ V_170 ] ;
struct V_3 * V_4 ;
struct V_41 * V_42 ;
enum V_171 type ;
int V_172 ;
int V_173 ;
memset ( V_169 , 0 , sizeof( V_169 ) ) ;
if ( V_45 > sizeof( V_169 ) - 1 )
V_45 = sizeof( V_169 ) - 1 ;
if ( F_124 ( V_169 , V_168 , V_45 ) )
return - V_174 ;
V_173 = F_125 ( F_126 ( V_169 ) , 10 , & V_172 ) ;
if ( V_173 < 0 )
return V_173 ;
type = (enum V_171 ) V_172 ;
if ( type < V_175 || type >= V_176 )
return - V_177 ;
V_38 = F_23 ( F_50 ( V_60 ) ) ;
if ( ! V_38 )
return - V_54 ;
V_4 = F_127 ( V_38 ) ;
if ( V_4 ) {
struct V_162 V_163 = {
. type = type ,
} ;
struct V_117 V_178 = {
. V_156 = F_116 ,
. V_179 = F_122 ,
. V_4 = V_4 ,
. V_48 = & V_163 ,
} ;
if ( type == V_180 ) {
F_128 ( & V_4 -> V_40 ) ;
F_129 ( V_4 ) ;
F_130 ( & V_4 -> V_40 ) ;
goto V_181;
}
F_26 ( & V_4 -> V_40 ) ;
if ( type == V_164 ) {
for ( V_42 = V_4 -> V_57 ; V_42 ; V_42 = V_42 -> V_44 ) {
if ( ! ( V_42 -> V_77 & V_147 ) )
continue;
F_18 ( & V_4 -> V_40 ) ;
F_128 ( & V_4 -> V_40 ) ;
for ( V_42 = V_4 -> V_57 ; V_42 ; V_42 = V_42 -> V_44 ) {
V_42 -> V_77 &= ~ V_147 ;
F_131 ( V_42 ) ;
}
F_132 ( & V_4 -> V_40 ) ;
break;
}
F_133 ( V_4 , 0 , - 1 ) ;
}
F_134 ( 0 , ~ 0UL , & V_178 ) ;
if ( type == V_164 )
F_135 ( V_4 , 0 , - 1 ) ;
F_136 ( V_4 ) ;
F_18 ( & V_4 -> V_40 ) ;
V_181:
F_19 ( V_4 ) ;
}
F_32 ( V_38 ) ;
return V_45 ;
}
static inline T_11 F_137 ( T_5 V_182 , T_5 V_76 )
{
return ( T_11 ) { . V_183 = ( V_182 & V_184 ) | V_76 } ;
}
static int F_138 ( unsigned long V_116 , T_11 * V_183 ,
struct V_185 * V_186 )
{
V_186 -> V_169 [ V_186 -> V_52 ++ ] = * V_183 ;
if ( V_186 -> V_52 >= V_186 -> V_187 )
return V_188 ;
return 0 ;
}
static int F_139 ( unsigned long V_80 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_185 * V_186 = V_118 -> V_48 ;
unsigned long V_116 = V_80 ;
int V_66 = 0 ;
while ( V_116 < V_81 ) {
struct V_41 * V_42 = F_28 ( V_118 -> V_4 , V_116 ) ;
T_11 V_183 = F_137 ( 0 , 0 ) ;
unsigned long V_189 ;
if ( V_42 )
V_189 = F_140 ( V_81 , V_42 -> V_49 ) ;
else
V_189 = V_81 ;
for (; V_116 < V_189 ; V_116 += V_30 ) {
V_66 = F_138 ( V_116 , & V_183 , V_186 ) ;
if ( V_66 )
goto V_165;
}
if ( ! V_42 )
break;
if ( V_42 -> V_77 & V_147 )
V_183 = F_137 ( 0 , V_190 ) ;
for (; V_116 < F_140 ( V_81 , V_42 -> V_87 ) ; V_116 += V_30 ) {
V_66 = F_138 ( V_116 , & V_183 , V_186 ) ;
if ( V_66 )
goto V_165;
}
}
V_165:
return V_66 ;
}
static T_11 F_141 ( struct V_185 * V_186 ,
struct V_41 * V_42 , unsigned long V_116 , V_24 V_115 )
{
T_5 V_182 = 0 , V_76 = 0 ;
struct V_102 * V_102 = NULL ;
if ( F_74 ( V_115 ) ) {
if ( V_186 -> V_191 )
V_182 = F_142 ( V_115 ) ;
V_76 |= V_192 ;
V_102 = F_75 ( V_42 , V_116 , V_115 ) ;
if ( F_143 ( V_115 ) )
V_76 |= V_190 ;
} else if ( F_76 ( V_115 ) ) {
T_6 V_193 ;
if ( F_144 ( V_115 ) )
V_76 |= V_190 ;
V_193 = F_77 ( V_115 ) ;
V_182 = F_145 ( V_193 ) |
( F_146 ( V_193 ) << V_194 ) ;
V_76 |= V_195 ;
if ( F_80 ( V_193 ) )
V_102 = F_81 ( V_193 ) ;
}
if ( V_102 && ! F_67 ( V_102 ) )
V_76 |= V_196 ;
if ( V_102 && F_70 ( V_102 ) == 1 )
V_76 |= V_197 ;
if ( V_42 -> V_77 & V_147 )
V_76 |= V_190 ;
return F_137 ( V_182 , V_76 ) ;
}
static int F_147 ( V_27 * V_161 , unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_41 * V_42 = V_118 -> V_42 ;
struct V_185 * V_186 = V_118 -> V_48 ;
T_7 * V_125 ;
V_24 * V_115 , * V_198 ;
int V_66 = 0 ;
#ifdef F_148
if ( F_89 ( V_161 , V_42 , & V_125 ) == 1 ) {
T_5 V_76 = 0 , V_182 = 0 ;
V_27 V_121 = * V_161 ;
if ( ( V_42 -> V_77 & V_147 ) || F_149 ( V_121 ) )
V_76 |= V_190 ;
if ( F_150 ( V_121 ) ) {
struct V_102 * V_102 = F_117 ( V_121 ) ;
if ( F_70 ( V_102 ) == 1 )
V_76 |= V_197 ;
V_76 |= V_192 ;
if ( V_186 -> V_191 )
V_182 = F_151 ( V_121 ) +
( ( V_116 & ~ V_199 ) >> V_21 ) ;
}
for (; V_116 != V_81 ; V_116 += V_30 ) {
T_11 V_183 = F_137 ( V_182 , V_76 ) ;
V_66 = F_138 ( V_116 , & V_183 , V_186 ) ;
if ( V_66 )
break;
if ( V_186 -> V_191 && ( V_76 & V_192 ) )
V_182 ++ ;
}
F_90 ( V_125 ) ;
return V_66 ;
}
if ( F_91 ( V_161 ) )
return 0 ;
#endif
V_198 = V_115 = F_92 ( V_118 -> V_4 , V_161 , V_116 , & V_125 ) ;
for (; V_116 < V_81 ; V_115 ++ , V_116 += V_30 ) {
T_11 V_183 ;
V_183 = F_141 ( V_186 , V_42 , V_116 , * V_115 ) ;
V_66 = F_138 ( V_116 , & V_183 , V_186 ) ;
if ( V_66 )
break;
}
F_93 ( V_198 , V_125 ) ;
F_94 () ;
return V_66 ;
}
static int F_152 ( V_24 * V_200 , unsigned long V_201 ,
unsigned long V_116 , unsigned long V_81 ,
struct V_117 * V_118 )
{
struct V_185 * V_186 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
T_5 V_76 = 0 , V_182 = 0 ;
int V_66 = 0 ;
V_24 V_115 ;
if ( V_42 -> V_77 & V_147 )
V_76 |= V_190 ;
V_115 = F_153 ( V_200 ) ;
if ( F_74 ( V_115 ) ) {
struct V_102 * V_102 = F_154 ( V_115 ) ;
if ( ! F_67 ( V_102 ) )
V_76 |= V_196 ;
if ( F_70 ( V_102 ) == 1 )
V_76 |= V_197 ;
V_76 |= V_192 ;
if ( V_186 -> V_191 )
V_182 = F_142 ( V_115 ) +
( ( V_116 & ~ V_201 ) >> V_21 ) ;
}
for (; V_116 != V_81 ; V_116 += V_30 ) {
T_11 V_183 = F_137 ( V_182 , V_76 ) ;
V_66 = F_138 ( V_116 , & V_183 , V_186 ) ;
if ( V_66 )
return V_66 ;
if ( V_186 -> V_191 && ( V_76 & V_192 ) )
V_182 ++ ;
}
F_94 () ;
return V_66 ;
}
static T_9 F_155 ( struct V_60 * V_60 , char T_10 * V_168 ,
T_8 V_45 , T_1 * V_50 )
{
struct V_3 * V_4 = V_60 -> V_68 ;
struct V_185 V_186 ;
struct V_117 V_202 = {} ;
unsigned long V_203 ;
unsigned long V_204 ;
unsigned long V_205 ;
unsigned long V_206 ;
int V_70 = 0 , V_207 = 0 ;
if ( ! V_4 || ! F_25 ( & V_4 -> V_55 ) )
goto V_165;
V_70 = - V_177 ;
if ( ( * V_50 % V_208 ) || ( V_45 % V_208 ) )
goto V_181;
V_70 = 0 ;
if ( ! V_45 )
goto V_181;
V_186 . V_191 = F_156 ( V_60 , & V_209 , V_210 ) ;
V_186 . V_187 = ( V_211 >> V_21 ) ;
V_186 . V_169 = F_157 ( V_186 . V_187 * V_208 , V_212 ) ;
V_70 = - V_64 ;
if ( ! V_186 . V_169 )
goto V_181;
V_202 . V_156 = F_147 ;
V_202 . V_213 = F_139 ;
#ifdef F_158
V_202 . V_214 = F_152 ;
#endif
V_202 . V_4 = V_4 ;
V_202 . V_48 = & V_186 ;
V_203 = * V_50 ;
V_204 = V_203 / V_208 ;
V_205 = V_204 << V_21 ;
V_206 = V_4 -> V_215 ;
if ( V_204 > V_4 -> V_215 >> V_21 )
V_205 = V_206 ;
V_70 = 0 ;
while ( V_45 && ( V_205 < V_206 ) ) {
int V_187 ;
unsigned long V_81 ;
V_186 . V_52 = 0 ;
V_81 = ( V_205 + V_211 ) & V_216 ;
if ( V_81 < V_205 || V_81 > V_206 )
V_81 = V_206 ;
F_26 ( & V_4 -> V_40 ) ;
V_70 = F_134 ( V_205 , V_81 , & V_202 ) ;
F_18 ( & V_4 -> V_40 ) ;
V_205 = V_81 ;
V_187 = F_140 ( V_45 , V_208 * V_186 . V_52 ) ;
if ( F_159 ( V_168 , V_186 . V_169 , V_187 ) ) {
V_70 = - V_174 ;
goto V_217;
}
V_207 += V_187 ;
V_168 += V_187 ;
V_45 -= V_187 ;
}
* V_50 += V_207 ;
if ( ! V_70 || V_70 == V_188 )
V_70 = V_207 ;
V_217:
F_160 ( V_186 . V_169 ) ;
V_181:
F_19 ( V_4 ) ;
V_165:
return V_70 ;
}
static int F_161 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
struct V_3 * V_4 ;
V_4 = F_35 ( V_53 , V_65 ) ;
if ( F_36 ( V_4 ) )
return F_37 ( V_4 ) ;
V_60 -> V_68 = V_4 ;
return 0 ;
}
static int F_162 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
struct V_3 * V_4 = V_60 -> V_68 ;
if ( V_4 )
F_40 ( V_4 ) ;
return 0 ;
}
static void F_163 ( struct V_102 * V_102 , struct V_218 * V_219 , int F_83 ,
unsigned long V_220 )
{
int V_45 = F_70 ( V_102 ) ;
V_219 -> V_221 += V_220 ;
if ( F_83 || F_71 ( V_102 ) )
V_219 -> V_104 += V_220 ;
if ( F_164 ( V_102 ) )
V_219 -> V_222 += V_220 ;
if ( F_165 ( V_102 ) || F_166 ( V_102 ) )
V_219 -> V_223 += V_220 ;
if ( F_167 ( V_102 ) )
V_219 -> V_224 += V_220 ;
if ( F_67 ( V_102 ) )
V_219 -> V_225 += V_220 ;
if ( V_45 > V_219 -> V_226 )
V_219 -> V_226 = V_45 ;
V_219 -> V_227 [ F_168 ( V_102 ) ] += V_220 ;
}
static struct V_102 * F_169 ( V_24 V_115 , struct V_41 * V_42 ,
unsigned long V_116 )
{
struct V_102 * V_102 ;
int V_228 ;
if ( ! F_74 ( V_115 ) )
return NULL ;
V_102 = F_75 ( V_42 , V_116 , V_115 ) ;
if ( ! V_102 )
return NULL ;
if ( F_170 ( V_102 ) )
return NULL ;
V_228 = F_168 ( V_102 ) ;
if ( ! F_171 ( V_228 , V_229 [ V_230 ] ) )
return NULL ;
return V_102 ;
}
static int F_172 ( V_27 * V_121 , unsigned long V_116 ,
unsigned long V_81 , struct V_117 * V_118 )
{
struct V_218 * V_219 = V_118 -> V_48 ;
struct V_41 * V_42 = V_118 -> V_42 ;
T_7 * V_125 ;
V_24 * V_198 ;
V_24 * V_115 ;
if ( F_89 ( V_121 , V_42 , & V_125 ) == 1 ) {
V_24 V_231 = * ( V_24 * ) V_121 ;
struct V_102 * V_102 ;
V_102 = F_169 ( V_231 , V_42 , V_116 ) ;
if ( V_102 )
F_163 ( V_102 , V_219 , F_83 ( V_231 ) ,
V_124 / V_30 ) ;
F_90 ( V_125 ) ;
return 0 ;
}
if ( F_91 ( V_121 ) )
return 0 ;
V_198 = V_115 = F_92 ( V_118 -> V_4 , V_121 , V_116 , & V_125 ) ;
do {
struct V_102 * V_102 = F_169 ( * V_115 , V_42 , V_116 ) ;
if ( ! V_102 )
continue;
F_163 ( V_102 , V_219 , F_83 ( * V_115 ) , 1 ) ;
} while ( V_115 ++ , V_116 += V_30 , V_116 != V_81 );
F_93 ( V_198 , V_125 ) ;
return 0 ;
}
static int F_173 ( V_24 * V_115 , unsigned long V_201 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
struct V_218 * V_219 ;
struct V_102 * V_102 ;
if ( ! F_74 ( * V_115 ) )
return 0 ;
V_102 = F_154 ( * V_115 ) ;
if ( ! V_102 )
return 0 ;
V_219 = V_118 -> V_48 ;
F_163 ( V_102 , V_219 , F_83 ( * V_115 ) , 1 ) ;
return 0 ;
}
static int F_173 ( V_24 * V_115 , unsigned long V_201 ,
unsigned long V_116 , unsigned long V_81 , struct V_117 * V_118 )
{
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , void * V_58 , int V_69 )
{
struct V_232 * V_233 = V_2 -> V_48 ;
struct V_35 * V_234 = & V_233 -> V_235 ;
struct V_41 * V_42 = V_58 ;
struct V_218 * V_219 = & V_233 -> V_219 ;
struct V_60 * V_60 = V_42 -> V_75 ;
struct V_3 * V_4 = V_42 -> V_74 ;
struct V_117 V_118 = {
. V_214 = F_173 ,
. V_156 = F_172 ,
. V_48 = V_219 ,
. V_4 = V_4 ,
} ;
struct V_236 * V_237 ;
char V_169 [ 64 ] ;
int V_228 ;
if ( ! V_4 )
return 0 ;
memset ( V_219 , 0 , sizeof( * V_219 ) ) ;
V_237 = F_175 ( V_42 , V_42 -> V_49 ) ;
if ( V_237 ) {
F_176 ( V_169 , sizeof( V_169 ) , V_237 ) ;
F_177 ( V_237 ) ;
} else {
F_176 ( V_169 , sizeof( V_169 ) , V_234 -> V_39 ) ;
}
F_7 ( V_2 , L_68 , V_42 -> V_49 , V_169 ) ;
if ( V_60 ) {
F_59 ( V_2 , L_69 ) ;
F_57 ( V_2 , V_60 , L_70 ) ;
} else if ( V_42 -> V_49 <= V_4 -> V_95 && V_42 -> V_87 >= V_4 -> V_96 ) {
F_59 ( V_2 , L_71 ) ;
} else {
T_2 V_94 = F_42 ( V_234 , V_42 , V_69 ) ;
if ( V_94 != 0 ) {
if ( ! V_69 || ( V_42 -> V_49 <= V_4 -> V_97 &&
V_42 -> V_87 >= V_4 -> V_97 ) )
F_59 ( V_2 , L_72 ) ;
else
F_7 ( V_2 , L_73 , V_94 ) ;
}
}
if ( F_178 ( V_42 ) )
F_59 ( V_2 , L_74 ) ;
F_100 ( V_42 , & V_118 ) ;
if ( ! V_219 -> V_221 )
goto V_165;
if ( V_219 -> V_225 )
F_7 ( V_2 , L_75 , V_219 -> V_225 ) ;
if ( V_219 -> V_104 )
F_7 ( V_2 , L_76 , V_219 -> V_104 ) ;
if ( V_219 -> V_221 != V_219 -> V_225 && V_219 -> V_221 != V_219 -> V_104 )
F_7 ( V_2 , L_77 , V_219 -> V_221 ) ;
if ( V_219 -> V_226 > 1 )
F_7 ( V_2 , L_78 , V_219 -> V_226 ) ;
if ( V_219 -> V_222 )
F_7 ( V_2 , L_79 , V_219 -> V_222 ) ;
if ( V_219 -> V_223 < V_219 -> V_221 && ! F_178 ( V_42 ) )
F_7 ( V_2 , L_80 , V_219 -> V_223 ) ;
if ( V_219 -> V_224 )
F_7 ( V_2 , L_81 , V_219 -> V_224 ) ;
F_179 (nid, N_MEMORY)
if ( V_219 -> V_227 [ V_228 ] )
F_7 ( V_2 , L_82 , V_228 , V_219 -> V_227 [ V_228 ] ) ;
F_7 ( V_2 , L_83 , F_101 ( V_42 ) >> 10 ) ;
V_165:
F_60 ( V_2 , '\n' ) ;
F_21 ( V_2 , V_42 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , void * V_58 )
{
return F_174 ( V_2 , V_58 , 1 ) ;
}
static int F_181 ( struct V_1 * V_2 , void * V_58 )
{
return F_174 ( V_2 , V_58 , 0 ) ;
}
static int F_182 ( struct V_53 * V_53 , struct V_60 * V_60 ,
const struct V_61 * V_62 )
{
return F_33 ( V_53 , V_60 , V_62 ,
sizeof( struct V_232 ) ) ;
}
static int F_183 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_182 ( V_53 , V_60 , & V_238 ) ;
}
static int F_184 ( struct V_53 * V_53 , struct V_60 * V_60 )
{
return F_182 ( V_53 , V_60 , & V_239 ) ;
}
