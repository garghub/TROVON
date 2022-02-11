void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 , V_6 , V_7 , V_8 ;
unsigned long V_9 , V_10 , V_11 , V_12 ;
V_9 = V_10 = V_4 -> V_10 ;
if ( V_9 < V_4 -> V_9 )
V_9 = V_4 -> V_9 ;
V_11 = V_12 = F_2 ( V_4 ) ;
if ( V_11 < V_4 -> V_11 )
V_11 = V_4 -> V_11 ;
V_5 = V_4 -> V_10 - V_4 -> V_13 - V_4 -> V_14 ;
V_6 = ( F_3 ( V_4 -> V_15 ) - ( V_4 -> V_16 & V_17 ) ) >> 10 ;
V_7 = ( V_4 -> V_18 << ( V_19 - 10 ) ) - V_6 ;
V_8 = F_4 ( V_4 , V_20 ) ;
F_5 ( V_2 ,
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
L_12 ,
V_9 << ( V_19 - 10 ) ,
V_10 << ( V_19 - 10 ) ,
V_4 -> V_21 << ( V_19 - 10 ) ,
V_4 -> V_22 << ( V_19 - 10 ) ,
V_11 << ( V_19 - 10 ) ,
V_12 << ( V_19 - 10 ) ,
V_5 << ( V_19 - 10 ) ,
V_4 -> V_14 << ( V_19 - 10 ) , V_6 , V_7 ,
( V_23 * sizeof( V_24 ) *
F_6 ( & V_4 -> V_25 ) ) >> 10 ,
V_8 << ( V_19 - 10 ) ) ;
}
unsigned long F_7 ( struct V_3 * V_4 )
{
return V_26 * V_4 -> V_10 ;
}
unsigned long F_8 ( struct V_3 * V_4 ,
unsigned long * V_27 , unsigned long * V_6 ,
unsigned long * V_5 , unsigned long * V_28 )
{
* V_27 = F_4 ( V_4 , V_29 ) ;
* V_6 = ( F_3 ( V_4 -> V_15 ) - ( V_4 -> V_16 & V_17 ) )
>> V_19 ;
* V_5 = V_4 -> V_10 - V_4 -> V_13 ;
* V_28 = * V_27 + F_4 ( V_4 , V_30 ) ;
return V_4 -> V_10 ;
}
static void F_9 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_34 ;
F_10 ( V_34 ) ;
V_32 -> V_35 = F_11 ( V_34 ) ;
F_12 ( V_32 -> V_35 ) ;
F_13 ( V_34 ) ;
}
static void F_14 ( struct V_31 * V_32 )
{
F_15 ( V_32 -> V_35 ) ;
}
static void F_9 ( struct V_31 * V_32 )
{
}
static void F_14 ( struct V_31 * V_32 )
{
}
static void F_16 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = V_32 -> V_4 ;
F_14 ( V_32 ) ;
F_17 ( & V_4 -> V_36 ) ;
F_18 ( V_4 ) ;
}
static struct V_37 *
F_19 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
if ( V_38 == V_32 -> V_39 )
return NULL ;
return V_38 -> V_40 ? : V_32 -> V_39 ;
}
static void F_20 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
if ( V_2 -> V_41 < V_2 -> V_42 )
V_2 -> V_43 = F_19 ( V_2 -> V_44 , V_38 ) ? V_38 -> V_45 : - 1UL ;
}
static void * F_21 ( struct V_1 * V_2 , T_1 * V_46 )
{
struct V_31 * V_32 = V_2 -> V_44 ;
unsigned long V_47 = V_2 -> V_43 ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
unsigned int V_48 = * V_46 ;
if ( V_47 == - 1UL )
return NULL ;
V_32 -> V_34 = F_22 ( V_32 -> V_49 ) ;
if ( ! V_32 -> V_34 )
return F_23 ( - V_50 ) ;
V_4 = V_32 -> V_4 ;
if ( ! V_4 || ! F_24 ( & V_4 -> V_51 ) )
return NULL ;
F_25 ( & V_4 -> V_36 ) ;
F_9 ( V_32 ) ;
V_32 -> V_39 = F_26 ( V_4 ) ;
if ( V_47 ) {
V_38 = F_27 ( V_4 , V_47 ) ;
if ( V_38 && ( V_38 = F_19 ( V_32 , V_38 ) ) )
return V_38 ;
}
V_2 -> V_43 = 0 ;
if ( V_48 < V_4 -> V_52 ) {
for ( V_38 = V_4 -> V_53 ; V_48 ; V_48 -- ) {
V_2 -> V_43 = V_38 -> V_45 ;
V_38 = V_38 -> V_40 ;
}
return V_38 ;
}
if ( V_48 == V_4 -> V_52 && V_32 -> V_39 )
return V_32 -> V_39 ;
F_16 ( V_32 ) ;
return NULL ;
}
static void * F_28 ( struct V_1 * V_2 , void * V_54 , T_1 * V_48 )
{
struct V_31 * V_32 = V_2 -> V_44 ;
struct V_37 * V_55 ;
( * V_48 ) ++ ;
V_55 = F_19 ( V_32 , V_54 ) ;
if ( ! V_55 )
F_16 ( V_32 ) ;
return V_55 ;
}
static void F_29 ( struct V_1 * V_2 , void * V_54 )
{
struct V_31 * V_32 = V_2 -> V_44 ;
if ( ! F_30 ( V_54 ) )
F_16 ( V_32 ) ;
if ( V_32 -> V_34 ) {
F_31 ( V_32 -> V_34 ) ;
V_32 -> V_34 = NULL ;
}
}
static int F_32 ( struct V_49 * V_49 , struct V_56 * V_56 ,
const struct V_57 * V_58 , int V_59 )
{
struct V_31 * V_32 = F_33 ( V_56 , V_58 , V_59 ) ;
if ( ! V_32 )
return - V_60 ;
V_32 -> V_49 = V_49 ;
V_32 -> V_4 = F_34 ( V_49 , V_61 ) ;
if ( F_35 ( V_32 -> V_4 ) ) {
int V_62 = F_36 ( V_32 -> V_4 ) ;
F_37 ( V_49 , V_56 ) ;
return V_62 ;
}
return 0 ;
}
static int F_38 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
struct V_1 * V_63 = V_56 -> V_64 ;
struct V_31 * V_32 = V_63 -> V_44 ;
if ( V_32 -> V_4 )
F_39 ( V_32 -> V_4 ) ;
return F_37 ( V_49 , V_56 ) ;
}
static int F_40 ( struct V_49 * V_49 , struct V_56 * V_56 ,
const struct V_57 * V_58 )
{
return F_32 ( V_49 , V_56 , V_58 ,
sizeof( struct V_31 ) ) ;
}
static T_2 F_41 ( struct V_31 * V_32 ,
struct V_37 * V_38 , bool V_65 )
{
struct V_49 * V_49 = V_32 -> V_49 ;
struct V_33 * V_34 ;
T_2 V_66 = 0 ;
F_42 () ;
V_34 = F_43 ( F_44 ( V_49 ) , V_67 ) ;
if ( V_34 ) {
V_34 = F_45 ( V_34 , V_38 , V_65 ) ;
if ( V_34 )
V_66 = F_46 ( V_34 , V_49 -> V_68 -> V_69 ) ;
}
F_47 () ;
return V_66 ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_37 * V_38 , int V_65 )
{
struct V_3 * V_4 = V_38 -> V_70 ;
struct V_56 * V_56 = V_38 -> V_71 ;
struct V_31 * V_32 = V_2 -> V_44 ;
T_3 V_72 = V_38 -> V_73 ;
unsigned long V_74 = 0 ;
unsigned long long V_75 = 0 ;
unsigned long V_76 , V_77 ;
T_4 V_78 = 0 ;
const char * V_79 = NULL ;
if ( V_56 ) {
struct V_49 * V_49 = F_49 ( V_38 -> V_71 ) ;
V_78 = V_49 -> V_68 -> V_80 ;
V_74 = V_49 -> V_81 ;
V_75 = ( ( T_1 ) V_38 -> V_82 ) << V_19 ;
}
V_76 = V_38 -> V_45 ;
if ( F_50 ( V_38 , V_76 ) )
V_76 += V_26 ;
V_77 = V_38 -> V_83 ;
if ( F_51 ( V_38 , V_77 ) )
V_77 -= V_26 ;
F_52 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_5 ( V_2 , L_13 ,
V_76 ,
V_77 ,
V_72 & V_84 ? 'r' : '-' ,
V_72 & V_85 ? 'w' : '-' ,
V_72 & V_86 ? 'x' : '-' ,
V_72 & V_87 ? 's' : 'p' ,
V_75 ,
F_53 ( V_78 ) , F_54 ( V_78 ) , V_74 ) ;
if ( V_56 ) {
F_55 ( V_2 , ' ' ) ;
F_56 ( V_2 , & V_56 -> V_88 , L_14 ) ;
goto V_89;
}
if ( V_38 -> V_90 && V_38 -> V_90 -> V_79 ) {
V_79 = V_38 -> V_90 -> V_79 ( V_38 ) ;
if ( V_79 )
goto V_89;
}
V_79 = F_57 ( V_38 ) ;
if ( ! V_79 ) {
T_2 V_91 ;
if ( ! V_4 ) {
V_79 = L_15 ;
goto V_89;
}
if ( V_38 -> V_45 <= V_4 -> V_92 &&
V_38 -> V_83 >= V_4 -> V_93 ) {
V_79 = L_16 ;
goto V_89;
}
V_91 = F_41 ( V_32 , V_38 , V_65 ) ;
if ( V_91 != 0 ) {
if ( ! V_65 || ( V_38 -> V_45 <= V_4 -> V_94 &&
V_38 -> V_83 >= V_4 -> V_94 ) ) {
V_79 = L_17 ;
} else {
F_55 ( V_2 , ' ' ) ;
F_5 ( V_2 , L_18 , V_91 ) ;
}
}
}
V_89:
if ( V_79 ) {
F_55 ( V_2 , ' ' ) ;
F_58 ( V_2 , V_79 ) ;
}
F_59 ( V_2 , '\n' ) ;
}
static int F_60 ( struct V_1 * V_2 , void * V_54 , int V_65 )
{
F_48 ( V_2 , V_54 , V_65 ) ;
F_20 ( V_2 , V_54 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , void * V_54 )
{
return F_60 ( V_2 , V_54 , 1 ) ;
}
static int F_62 ( struct V_1 * V_2 , void * V_54 )
{
return F_60 ( V_2 , V_54 , 0 ) ;
}
static int F_63 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_40 ( V_49 , V_56 , & V_95 ) ;
}
static int F_64 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_40 ( V_49 , V_56 , & V_96 ) ;
}
static void F_65 ( struct V_97 * V_98 , struct V_99 * V_99 ,
unsigned long V_42 , bool V_100 , bool V_101 )
{
int V_102 ;
if ( F_66 ( V_99 ) )
V_98 -> V_103 += V_42 ;
V_98 -> V_28 += V_42 ;
if ( V_100 || F_67 ( V_99 ) )
V_98 -> V_104 += V_42 ;
V_102 = F_68 ( V_99 ) ;
if ( V_102 >= 2 ) {
T_5 V_105 ;
if ( V_101 || F_69 ( V_99 ) )
V_98 -> V_106 += V_42 ;
else
V_98 -> V_107 += V_42 ;
V_105 = ( T_5 ) V_42 << V_108 ;
F_70 ( V_105 , V_102 ) ;
V_98 -> V_109 += V_105 ;
} else {
if ( V_101 || F_69 ( V_99 ) )
V_98 -> V_110 += V_42 ;
else
V_98 -> V_111 += V_42 ;
V_98 -> V_109 += ( T_5 ) V_42 << V_108 ;
}
}
static void F_71 ( V_24 * V_112 , unsigned long V_113 ,
struct V_114 * V_115 )
{
struct V_97 * V_98 = V_115 -> V_44 ;
struct V_37 * V_38 = V_98 -> V_38 ;
T_6 V_75 = F_72 ( V_38 , V_113 ) ;
struct V_99 * V_99 = NULL ;
if ( F_73 ( * V_112 ) ) {
V_99 = F_74 ( V_38 , V_113 , * V_112 ) ;
} else if ( F_75 ( * V_112 ) ) {
T_7 V_116 = F_76 ( * V_112 ) ;
if ( ! F_77 ( V_116 ) )
V_98 -> V_8 += V_26 ;
else if ( F_78 ( V_116 ) )
V_99 = F_79 ( V_116 ) ;
} else if ( F_80 ( * V_112 ) ) {
if ( F_81 ( * V_112 ) != V_75 )
V_98 -> V_117 += V_26 ;
}
if ( ! V_99 )
return;
if ( V_99 -> V_118 != V_75 )
V_98 -> V_117 += V_26 ;
F_65 ( V_98 , V_99 , V_26 , F_82 ( * V_112 ) , F_83 ( * V_112 ) ) ;
}
static void F_84 ( T_8 * V_119 , unsigned long V_113 ,
struct V_114 * V_115 )
{
struct V_97 * V_98 = V_115 -> V_44 ;
struct V_37 * V_38 = V_98 -> V_38 ;
struct V_99 * V_99 ;
V_99 = F_85 ( V_38 , V_113 , V_119 , V_120 ) ;
if ( F_30 ( V_99 ) )
return;
V_98 -> V_121 += V_122 ;
F_65 ( V_98 , V_99 , V_122 ,
F_86 ( * V_119 ) , F_87 ( * V_119 ) ) ;
}
static void F_84 ( T_8 * V_119 , unsigned long V_113 ,
struct V_114 * V_115 )
{
}
static int F_88 ( T_8 * V_119 , unsigned long V_113 , unsigned long V_77 ,
struct V_114 * V_115 )
{
struct V_97 * V_98 = V_115 -> V_44 ;
struct V_37 * V_38 = V_98 -> V_38 ;
V_24 * V_112 ;
T_9 * V_123 ;
if ( F_89 ( V_119 , V_38 , & V_123 ) == 1 ) {
F_84 ( V_119 , V_113 , V_115 ) ;
F_90 ( V_123 ) ;
return 0 ;
}
if ( F_91 ( V_119 ) )
return 0 ;
V_112 = F_92 ( V_38 -> V_70 , V_119 , V_113 , & V_123 ) ;
for (; V_113 != V_77 ; V_112 ++ , V_113 += V_26 )
F_71 ( V_112 , V_113 , V_115 ) ;
F_93 ( V_112 - 1 , V_123 ) ;
F_94 () ;
return 0 ;
}
static void F_95 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
static const char V_124 [ V_125 ] [ 2 ] = {
[ 0 ... ( V_125 - 1 ) ] = L_19 ,
[ F_96 ( V_84 ) ] = L_20 ,
[ F_96 ( V_85 ) ] = L_21 ,
[ F_96 ( V_86 ) ] = L_22 ,
[ F_96 ( V_126 ) ] = L_23 ,
[ F_96 ( V_127 ) ] = L_24 ,
[ F_96 ( V_128 ) ] = L_25 ,
[ F_96 ( V_129 ) ] = L_26 ,
[ F_96 ( V_87 ) ] = L_27 ,
[ F_96 ( V_130 ) ] = L_28 ,
[ F_96 ( V_131 ) ] = L_29 ,
[ F_96 ( V_132 ) ] = L_30 ,
#ifdef F_97
[ F_96 ( V_133 ) ] = L_31 ,
#endif
[ F_96 ( V_134 ) ] = L_32 ,
[ F_96 ( V_135 ) ] = L_33 ,
[ F_96 ( V_136 ) ] = L_34 ,
[ F_96 ( V_137 ) ] = L_35 ,
[ F_96 ( V_138 ) ] = L_36 ,
[ F_96 ( V_139 ) ] = L_37 ,
[ F_96 ( V_140 ) ] = L_38 ,
[ F_96 ( V_141 ) ] = L_39 ,
[ F_96 ( V_142 ) ] = L_40 ,
[ F_96 ( V_143 ) ] = L_41 ,
[ F_96 ( V_144 ) ] = L_42 ,
[ F_96 ( V_145 ) ] = L_43 ,
#ifdef F_98
[ F_96 ( V_146 ) ] = L_44 ,
#endif
[ F_96 ( V_147 ) ] = L_45 ,
[ F_96 ( V_148 ) ] = L_46 ,
[ F_96 ( V_149 ) ] = L_47 ,
[ F_96 ( V_150 ) ] = L_48 ,
} ;
T_10 V_151 ;
F_58 ( V_2 , L_49 ) ;
for ( V_151 = 0 ; V_151 < V_125 ; V_151 ++ ) {
if ( V_38 -> V_73 & ( 1UL << V_151 ) ) {
F_5 ( V_2 , L_50 ,
V_124 [ V_151 ] [ 0 ] , V_124 [ V_151 ] [ 1 ] ) ;
}
}
F_59 ( V_2 , '\n' ) ;
}
static int F_99 ( struct V_1 * V_2 , void * V_54 , int V_65 )
{
struct V_37 * V_38 = V_54 ;
struct V_97 V_98 ;
struct V_114 V_152 = {
. V_153 = F_88 ,
. V_4 = V_38 -> V_70 ,
. V_44 = & V_98 ,
} ;
memset ( & V_98 , 0 , sizeof V_98 ) ;
V_98 . V_38 = V_38 ;
if ( V_38 -> V_70 && ! F_100 ( V_38 ) )
F_101 ( V_38 -> V_45 , V_38 -> V_83 , & V_152 ) ;
F_48 ( V_2 , V_38 , V_65 ) ;
F_5 ( V_2 ,
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
( V_38 -> V_83 - V_38 -> V_45 ) >> 10 ,
V_98 . V_28 >> 10 ,
( unsigned long ) ( V_98 . V_109 >> ( 10 + V_108 ) ) ,
V_98 . V_107 >> 10 ,
V_98 . V_106 >> 10 ,
V_98 . V_111 >> 10 ,
V_98 . V_110 >> 10 ,
V_98 . V_104 >> 10 ,
V_98 . V_103 >> 10 ,
V_98 . V_121 >> 10 ,
V_98 . V_8 >> 10 ,
F_102 ( V_38 ) >> 10 ,
F_103 ( V_38 ) >> 10 ,
( V_38 -> V_73 & V_134 ) ?
( unsigned long ) ( V_98 . V_109 >> ( 10 + V_108 ) ) : 0 ) ;
if ( V_38 -> V_73 & V_143 )
F_5 ( V_2 , L_65 ,
V_98 . V_117 >> 10 ) ;
F_95 ( V_2 , V_38 ) ;
F_20 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_104 ( struct V_1 * V_2 , void * V_54 )
{
return F_99 ( V_2 , V_54 , 1 ) ;
}
static int F_105 ( struct V_1 * V_2 , void * V_54 )
{
return F_99 ( V_2 , V_54 , 0 ) ;
}
static int F_106 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_40 ( V_49 , V_56 , & V_154 ) ;
}
static int F_107 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_40 ( V_49 , V_56 , & V_155 ) ;
}
static inline void F_108 ( struct V_37 * V_38 ,
unsigned long V_113 , V_24 * V_112 )
{
#ifdef F_98
V_24 V_156 = * V_112 ;
if ( F_73 ( V_156 ) ) {
V_156 = F_109 ( V_156 ) ;
V_156 = F_110 ( V_156 , V_157 ) ;
} else if ( F_75 ( V_156 ) ) {
V_156 = F_111 ( V_156 ) ;
} else if ( F_80 ( V_156 ) ) {
V_156 = F_112 ( V_156 ) ;
}
F_113 ( V_38 -> V_70 , V_113 , V_112 , V_156 ) ;
#endif
}
static int F_114 ( T_8 * V_119 , unsigned long V_113 ,
unsigned long V_77 , struct V_114 * V_115 )
{
struct V_158 * V_159 = V_115 -> V_44 ;
struct V_37 * V_38 = V_159 -> V_38 ;
V_24 * V_112 , V_156 ;
T_9 * V_123 ;
struct V_99 * V_99 ;
F_115 ( V_38 , V_113 , V_119 ) ;
if ( F_91 ( V_119 ) )
return 0 ;
V_112 = F_92 ( V_38 -> V_70 , V_119 , V_113 , & V_123 ) ;
for (; V_113 != V_77 ; V_112 ++ , V_113 += V_26 ) {
V_156 = * V_112 ;
if ( V_159 -> type == V_160 ) {
F_108 ( V_38 , V_113 , V_112 ) ;
continue;
}
if ( ! F_73 ( V_156 ) )
continue;
V_99 = F_74 ( V_38 , V_113 , V_156 ) ;
if ( ! V_99 )
continue;
F_116 ( V_38 , V_113 , V_112 ) ;
F_117 ( V_99 ) ;
}
F_93 ( V_112 - 1 , V_123 ) ;
F_94 () ;
return 0 ;
}
static T_11 F_118 ( struct V_56 * V_56 , const char T_12 * V_161 ,
T_10 V_41 , T_1 * V_46 )
{
struct V_33 * V_34 ;
char V_162 [ V_163 ] ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
enum V_164 type ;
int V_165 ;
int V_166 ;
memset ( V_162 , 0 , sizeof( V_162 ) ) ;
if ( V_41 > sizeof( V_162 ) - 1 )
V_41 = sizeof( V_162 ) - 1 ;
if ( F_119 ( V_162 , V_161 , V_41 ) )
return - V_167 ;
V_166 = F_120 ( F_121 ( V_162 ) , 10 , & V_165 ) ;
if ( V_166 < 0 )
return V_166 ;
type = (enum V_164 ) V_165 ;
if ( type < V_168 || type >= V_169 )
return - V_170 ;
if ( type == V_160 ) {
V_171 = true ;
F_122 ( L_66
L_67
L_68 ) ;
}
V_34 = F_22 ( F_49 ( V_56 ) ) ;
if ( ! V_34 )
return - V_50 ;
V_4 = F_123 ( V_34 ) ;
if ( V_4 ) {
struct V_158 V_159 = {
. type = type ,
} ;
struct V_114 V_172 = {
. V_153 = F_114 ,
. V_4 = V_4 ,
. V_44 = & V_159 ,
} ;
F_25 ( & V_4 -> V_36 ) ;
if ( type == V_160 ) {
for ( V_38 = V_4 -> V_53 ; V_38 ; V_38 = V_38 -> V_40 ) {
if ( ! ( V_38 -> V_73 & V_146 ) )
continue;
F_17 ( & V_4 -> V_36 ) ;
F_124 ( & V_4 -> V_36 ) ;
for ( V_38 = V_4 -> V_53 ; V_38 ; V_38 = V_38 -> V_40 ) {
V_38 -> V_73 &= ~ V_146 ;
F_125 ( V_38 ) ;
}
F_126 ( & V_4 -> V_36 ) ;
break;
}
F_127 ( V_4 , 0 , - 1 ) ;
}
for ( V_38 = V_4 -> V_53 ; V_38 ; V_38 = V_38 -> V_40 ) {
V_159 . V_38 = V_38 ;
if ( F_100 ( V_38 ) )
continue;
if ( type == V_173 && V_38 -> V_71 )
continue;
if ( type == V_174 && ! V_38 -> V_71 )
continue;
F_101 ( V_38 -> V_45 , V_38 -> V_83 ,
& V_172 ) ;
}
if ( type == V_160 )
F_128 ( V_4 , 0 , - 1 ) ;
F_129 ( V_4 ) ;
F_17 ( & V_4 -> V_36 ) ;
F_18 ( V_4 ) ;
}
F_31 ( V_34 ) ;
return V_41 ;
}
static inline T_13 F_130 ( T_5 V_175 )
{
return ( T_13 ) { . V_176 = V_175 } ;
}
static int F_131 ( unsigned long V_113 , T_13 * V_176 ,
struct V_177 * V_178 )
{
V_178 -> V_162 [ V_178 -> V_48 ++ ] = * V_176 ;
if ( V_178 -> V_48 >= V_178 -> V_179 )
return V_180 ;
return 0 ;
}
static int F_132 ( unsigned long V_76 , unsigned long V_77 ,
struct V_114 * V_115 )
{
struct V_177 * V_178 = V_115 -> V_44 ;
unsigned long V_113 = V_76 ;
int V_62 = 0 ;
while ( V_113 < V_77 ) {
struct V_37 * V_38 = F_27 ( V_115 -> V_4 , V_113 ) ;
T_13 V_176 = F_130 ( F_133 ( V_178 -> V_181 ) ) ;
unsigned long V_182 ;
if ( V_38 )
V_182 = F_134 ( V_77 , V_38 -> V_45 ) ;
else
V_182 = V_77 ;
for (; V_113 < V_182 ; V_113 += V_26 ) {
V_62 = F_131 ( V_113 , & V_176 , V_178 ) ;
if ( V_62 )
goto V_183;
}
if ( ! V_38 )
break;
if ( V_38 -> V_73 & V_146 )
V_176 . V_176 |= F_135 ( V_178 -> V_181 , V_184 ) ;
for (; V_113 < F_134 ( V_77 , V_38 -> V_83 ) ; V_113 += V_26 ) {
V_62 = F_131 ( V_113 , & V_176 , V_178 ) ;
if ( V_62 )
goto V_183;
}
}
V_183:
return V_62 ;
}
static void F_136 ( T_13 * V_176 , struct V_177 * V_178 ,
struct V_37 * V_38 , unsigned long V_113 , V_24 V_112 )
{
T_5 V_185 , V_72 ;
struct V_99 * V_99 = NULL ;
int V_186 = 0 ;
if ( F_73 ( V_112 ) ) {
V_185 = F_137 ( V_112 ) ;
V_72 = V_187 ;
V_99 = F_74 ( V_38 , V_113 , V_112 ) ;
if ( F_138 ( V_112 ) )
V_186 |= V_184 ;
} else if ( F_75 ( V_112 ) ) {
T_7 V_188 ;
if ( F_139 ( V_112 ) )
V_186 |= V_184 ;
V_188 = F_76 ( V_112 ) ;
V_185 = F_140 ( V_188 ) |
( F_141 ( V_188 ) << V_189 ) ;
V_72 = V_190 ;
if ( F_78 ( V_188 ) )
V_99 = F_79 ( V_188 ) ;
} else {
if ( V_38 -> V_73 & V_146 )
V_186 |= V_184 ;
* V_176 = F_130 ( F_133 ( V_178 -> V_181 ) | F_135 ( V_178 -> V_181 , V_186 ) ) ;
return;
}
if ( V_99 && ! F_66 ( V_99 ) )
V_72 |= V_191 ;
if ( ( V_38 -> V_73 & V_146 ) )
V_186 |= V_184 ;
* V_176 = F_130 ( F_142 ( V_185 ) | F_135 ( V_178 -> V_181 , V_186 ) | V_72 ) ;
}
static void F_143 ( T_13 * V_176 , struct V_177 * V_178 ,
T_8 V_119 , int V_192 , int V_193 )
{
if ( F_144 ( V_119 ) )
* V_176 = F_130 ( F_142 ( F_145 ( V_119 ) + V_192 )
| F_135 ( V_178 -> V_181 , V_193 ) | V_187 ) ;
else
* V_176 = F_130 ( F_133 ( V_178 -> V_181 ) | F_135 ( V_178 -> V_181 , V_193 ) ) ;
}
static inline void F_143 ( T_13 * V_176 , struct V_177 * V_178 ,
T_8 V_119 , int V_192 , int V_193 )
{
}
static int F_146 ( T_8 * V_119 , unsigned long V_113 , unsigned long V_77 ,
struct V_114 * V_115 )
{
struct V_37 * V_38 ;
struct V_177 * V_178 = V_115 -> V_44 ;
T_9 * V_123 ;
V_24 * V_112 ;
int V_62 = 0 ;
V_38 = F_27 ( V_115 -> V_4 , V_113 ) ;
if ( V_38 && F_89 ( V_119 , V_38 , & V_123 ) == 1 ) {
int V_193 ;
if ( ( V_38 -> V_73 & V_146 ) || F_147 ( * V_119 ) )
V_193 = V_184 ;
else
V_193 = 0 ;
for (; V_113 != V_77 ; V_113 += V_26 ) {
unsigned long V_192 ;
T_13 V_176 ;
V_192 = ( V_113 & ~ V_194 ) >>
V_19 ;
F_143 ( & V_176 , V_178 , * V_119 , V_192 , V_193 ) ;
V_62 = F_131 ( V_113 , & V_176 , V_178 ) ;
if ( V_62 )
break;
}
F_90 ( V_123 ) ;
return V_62 ;
}
if ( F_91 ( V_119 ) )
return 0 ;
while ( 1 ) {
unsigned long V_182 ;
if ( V_38 )
V_182 = F_134 ( V_77 , V_38 -> V_45 ) ;
else
V_182 = V_77 ;
for (; V_113 < V_182 ; V_113 += V_26 ) {
T_13 V_176 = F_130 ( F_133 ( V_178 -> V_181 ) ) ;
V_62 = F_131 ( V_113 , & V_176 , V_178 ) ;
if ( V_62 )
return V_62 ;
}
if ( ! V_38 || V_38 -> V_45 >= V_77 )
break;
F_148 ( F_100 ( V_38 ) ) ;
for (; V_113 < F_134 ( V_77 , V_38 -> V_83 ) ; V_113 += V_26 ) {
T_13 V_176 ;
V_112 = F_149 ( V_119 , V_113 ) ;
F_136 ( & V_176 , V_178 , V_38 , V_113 , * V_112 ) ;
F_150 ( V_112 ) ;
V_62 = F_131 ( V_113 , & V_176 , V_178 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_113 == V_77 )
break;
V_38 = F_27 ( V_115 -> V_4 , V_113 ) ;
}
F_94 () ;
return V_62 ;
}
static void F_151 ( T_13 * V_176 , struct V_177 * V_178 ,
V_24 V_112 , int V_192 , int V_186 )
{
if ( F_73 ( V_112 ) )
* V_176 = F_130 ( F_142 ( F_137 ( V_112 ) + V_192 ) |
F_135 ( V_178 -> V_181 , V_186 ) |
V_187 ) ;
else
* V_176 = F_130 ( F_133 ( V_178 -> V_181 ) |
F_135 ( V_178 -> V_181 , V_186 ) ) ;
}
static int F_152 ( V_24 * V_112 , unsigned long V_195 ,
unsigned long V_113 , unsigned long V_77 ,
struct V_114 * V_115 )
{
struct V_177 * V_178 = V_115 -> V_44 ;
struct V_37 * V_38 ;
int V_62 = 0 ;
int V_186 ;
T_13 V_176 ;
V_38 = F_27 ( V_115 -> V_4 , V_113 ) ;
F_153 ( ! V_38 ) ;
if ( V_38 && ( V_38 -> V_73 & V_146 ) )
V_186 = V_184 ;
else
V_186 = 0 ;
for (; V_113 != V_77 ; V_113 += V_26 ) {
int V_192 = ( V_113 & ~ V_195 ) >> V_19 ;
F_151 ( & V_176 , V_178 , * V_112 , V_192 , V_186 ) ;
V_62 = F_131 ( V_113 , & V_176 , V_178 ) ;
if ( V_62 )
return V_62 ;
}
F_94 () ;
return V_62 ;
}
static T_11 F_154 ( struct V_56 * V_56 , char T_12 * V_161 ,
T_10 V_41 , T_1 * V_46 )
{
struct V_33 * V_34 = F_22 ( F_49 ( V_56 ) ) ;
struct V_3 * V_4 ;
struct V_177 V_178 ;
int V_66 = - V_50 ;
struct V_114 V_196 = {} ;
unsigned long V_197 ;
unsigned long V_198 ;
unsigned long V_199 ;
unsigned long V_200 ;
int V_201 = 0 ;
if ( ! V_34 )
goto V_183;
V_66 = - V_170 ;
if ( ( * V_46 % V_202 ) || ( V_41 % V_202 ) )
goto V_203;
V_66 = 0 ;
if ( ! V_41 )
goto V_203;
V_178 . V_181 = V_171 ;
V_178 . V_179 = ( V_204 >> V_19 ) ;
V_178 . V_162 = F_155 ( V_178 . V_179 * V_202 , V_205 ) ;
V_66 = - V_60 ;
if ( ! V_178 . V_162 )
goto V_203;
V_4 = F_156 ( V_34 , V_61 ) ;
V_66 = F_36 ( V_4 ) ;
if ( ! V_4 || F_35 ( V_4 ) )
goto V_206;
V_196 . V_153 = F_146 ;
V_196 . V_207 = F_132 ;
#ifdef F_157
V_196 . V_208 = F_152 ;
#endif
V_196 . V_4 = V_4 ;
V_196 . V_44 = & V_178 ;
V_197 = * V_46 ;
V_198 = V_197 / V_202 ;
V_199 = V_198 << V_19 ;
V_200 = F_158 ( V_34 ) ;
if ( V_198 > F_158 ( V_34 ) >> V_19 )
V_199 = V_200 ;
V_66 = 0 ;
while ( V_41 && ( V_199 < V_200 ) ) {
int V_179 ;
unsigned long V_77 ;
V_178 . V_48 = 0 ;
V_77 = ( V_199 + V_204 ) & V_194 ;
if ( V_77 < V_199 || V_77 > V_200 )
V_77 = V_200 ;
F_25 ( & V_4 -> V_36 ) ;
V_66 = F_101 ( V_199 , V_77 , & V_196 ) ;
F_17 ( & V_4 -> V_36 ) ;
V_199 = V_77 ;
V_179 = F_134 ( V_41 , V_202 * V_178 . V_48 ) ;
if ( F_159 ( V_161 , V_178 . V_162 , V_179 ) ) {
V_66 = - V_167 ;
goto V_209;
}
V_201 += V_179 ;
V_161 += V_179 ;
V_41 -= V_179 ;
}
* V_46 += V_201 ;
if ( ! V_66 || V_66 == V_180 )
V_66 = V_201 ;
V_209:
F_18 ( V_4 ) ;
V_206:
F_160 ( V_178 . V_162 ) ;
V_203:
F_31 ( V_34 ) ;
V_183:
return V_66 ;
}
static int F_161 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
F_122 ( L_69
L_70
L_71 ) ;
return 0 ;
}
static void F_162 ( struct V_99 * V_99 , struct V_210 * V_211 , int F_83 ,
unsigned long V_212 )
{
int V_41 = F_68 ( V_99 ) ;
V_211 -> V_213 += V_212 ;
if ( F_83 || F_69 ( V_99 ) )
V_211 -> V_101 += V_212 ;
if ( F_163 ( V_99 ) )
V_211 -> V_214 += V_212 ;
if ( F_164 ( V_99 ) || F_165 ( V_99 ) )
V_211 -> V_215 += V_212 ;
if ( F_166 ( V_99 ) )
V_211 -> V_216 += V_212 ;
if ( F_66 ( V_99 ) )
V_211 -> V_217 += V_212 ;
if ( V_41 > V_211 -> V_218 )
V_211 -> V_218 = V_41 ;
V_211 -> V_219 [ F_167 ( V_99 ) ] += V_212 ;
}
static struct V_99 * F_168 ( V_24 V_112 , struct V_37 * V_38 ,
unsigned long V_113 )
{
struct V_99 * V_99 ;
int V_220 ;
if ( ! F_73 ( V_112 ) )
return NULL ;
V_99 = F_74 ( V_38 , V_113 , V_112 ) ;
if ( ! V_99 )
return NULL ;
if ( F_169 ( V_99 ) )
return NULL ;
V_220 = F_167 ( V_99 ) ;
if ( ! F_170 ( V_220 , V_221 [ V_222 ] ) )
return NULL ;
return V_99 ;
}
static int F_171 ( T_8 * V_119 , unsigned long V_113 ,
unsigned long V_77 , struct V_114 * V_115 )
{
struct V_210 * V_211 ;
T_9 * V_123 ;
V_24 * V_223 ;
V_24 * V_112 ;
V_211 = V_115 -> V_44 ;
if ( F_89 ( V_119 , V_211 -> V_38 , & V_123 ) == 1 ) {
V_24 V_224 = * ( V_24 * ) V_119 ;
struct V_99 * V_99 ;
V_99 = F_168 ( V_224 , V_211 -> V_38 , V_113 ) ;
if ( V_99 )
F_162 ( V_99 , V_211 , F_83 ( V_224 ) ,
V_122 / V_26 ) ;
F_90 ( V_123 ) ;
return 0 ;
}
if ( F_91 ( V_119 ) )
return 0 ;
V_223 = V_112 = F_92 ( V_115 -> V_4 , V_119 , V_113 , & V_123 ) ;
do {
struct V_99 * V_99 = F_168 ( * V_112 , V_211 -> V_38 , V_113 ) ;
if ( ! V_99 )
continue;
F_162 ( V_99 , V_211 , F_83 ( * V_112 ) , 1 ) ;
} while ( V_112 ++ , V_113 += V_26 , V_113 != V_77 );
F_93 ( V_223 , V_123 ) ;
return 0 ;
}
static int F_172 ( V_24 * V_112 , unsigned long V_195 ,
unsigned long V_113 , unsigned long V_77 , struct V_114 * V_115 )
{
struct V_210 * V_211 ;
struct V_99 * V_99 ;
if ( ! F_73 ( * V_112 ) )
return 0 ;
V_99 = F_173 ( * V_112 ) ;
if ( ! V_99 )
return 0 ;
V_211 = V_115 -> V_44 ;
F_162 ( V_99 , V_211 , F_83 ( * V_112 ) , 1 ) ;
return 0 ;
}
static int F_172 ( V_24 * V_112 , unsigned long V_195 ,
unsigned long V_113 , unsigned long V_77 , struct V_114 * V_115 )
{
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , void * V_54 , int V_65 )
{
struct V_225 * V_226 = V_2 -> V_44 ;
struct V_31 * V_227 = & V_226 -> V_228 ;
struct V_37 * V_38 = V_54 ;
struct V_210 * V_211 = & V_226 -> V_211 ;
struct V_56 * V_56 = V_38 -> V_71 ;
struct V_3 * V_4 = V_38 -> V_70 ;
struct V_114 V_115 = {} ;
struct V_229 * V_230 ;
char V_162 [ 64 ] ;
int V_220 ;
if ( ! V_4 )
return 0 ;
memset ( V_211 , 0 , sizeof( * V_211 ) ) ;
V_211 -> V_38 = V_38 ;
V_115 . V_208 = F_172 ;
V_115 . V_153 = F_171 ;
V_115 . V_44 = V_211 ;
V_115 . V_4 = V_4 ;
V_230 = F_175 ( V_38 , V_38 -> V_45 ) ;
if ( V_230 ) {
F_176 ( V_162 , sizeof( V_162 ) , V_230 ) ;
F_177 ( V_230 ) ;
} else {
F_176 ( V_162 , sizeof( V_162 ) , V_227 -> V_35 ) ;
}
F_5 ( V_2 , L_72 , V_38 -> V_45 , V_162 ) ;
if ( V_56 ) {
F_58 ( V_2 , L_73 ) ;
F_56 ( V_2 , & V_56 -> V_88 , L_74 ) ;
} else if ( V_38 -> V_45 <= V_4 -> V_92 && V_38 -> V_83 >= V_4 -> V_93 ) {
F_58 ( V_2 , L_75 ) ;
} else {
T_2 V_91 = F_41 ( V_227 , V_38 , V_65 ) ;
if ( V_91 != 0 ) {
if ( ! V_65 || ( V_38 -> V_45 <= V_4 -> V_94 &&
V_38 -> V_83 >= V_4 -> V_94 ) )
F_58 ( V_2 , L_76 ) ;
else
F_5 ( V_2 , L_77 , V_91 ) ;
}
}
if ( F_100 ( V_38 ) )
F_58 ( V_2 , L_78 ) ;
F_101 ( V_38 -> V_45 , V_38 -> V_83 , & V_115 ) ;
if ( ! V_211 -> V_213 )
goto V_183;
if ( V_211 -> V_217 )
F_5 ( V_2 , L_79 , V_211 -> V_217 ) ;
if ( V_211 -> V_101 )
F_5 ( V_2 , L_80 , V_211 -> V_101 ) ;
if ( V_211 -> V_213 != V_211 -> V_217 && V_211 -> V_213 != V_211 -> V_101 )
F_5 ( V_2 , L_81 , V_211 -> V_213 ) ;
if ( V_211 -> V_218 > 1 )
F_5 ( V_2 , L_82 , V_211 -> V_218 ) ;
if ( V_211 -> V_214 )
F_5 ( V_2 , L_83 , V_211 -> V_214 ) ;
if ( V_211 -> V_215 < V_211 -> V_213 && ! F_100 ( V_38 ) )
F_5 ( V_2 , L_84 , V_211 -> V_215 ) ;
if ( V_211 -> V_216 )
F_5 ( V_2 , L_85 , V_211 -> V_216 ) ;
F_178 (nid, N_MEMORY)
if ( V_211 -> V_219 [ V_220 ] )
F_5 ( V_2 , L_86 , V_220 , V_211 -> V_219 [ V_220 ] ) ;
V_183:
F_59 ( V_2 , '\n' ) ;
F_20 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 , void * V_54 )
{
return F_174 ( V_2 , V_54 , 1 ) ;
}
static int F_180 ( struct V_1 * V_2 , void * V_54 )
{
return F_174 ( V_2 , V_54 , 0 ) ;
}
static int F_181 ( struct V_49 * V_49 , struct V_56 * V_56 ,
const struct V_57 * V_58 )
{
return F_32 ( V_49 , V_56 , V_58 ,
sizeof( struct V_225 ) ) ;
}
static int F_182 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_181 ( V_49 , V_56 , & V_231 ) ;
}
static int F_183 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_181 ( V_49 , V_56 , & V_232 ) ;
}
