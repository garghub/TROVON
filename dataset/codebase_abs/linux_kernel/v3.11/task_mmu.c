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
( V_23 * sizeof( V_24 ) * V_4 -> V_25 ) >> 10 ,
V_8 << ( V_19 - 10 ) ) ;
}
unsigned long F_6 ( struct V_3 * V_4 )
{
return V_26 * V_4 -> V_10 ;
}
unsigned long F_7 ( struct V_3 * V_4 ,
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
static void F_8 ( struct V_1 * V_2 , int V_31 )
{
V_31 = 25 + sizeof( void * ) * 6 - V_31 ;
if ( V_31 < 1 )
V_31 = 1 ;
F_5 ( V_2 , L_13 , V_31 , ' ' ) ;
}
static void F_9 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = V_33 -> V_35 ;
F_10 ( V_35 ) ;
V_33 -> V_36 = V_35 -> V_37 ;
F_11 ( V_33 -> V_36 ) ;
F_12 ( V_35 ) ;
}
static void F_13 ( struct V_32 * V_33 )
{
F_14 ( V_33 -> V_36 ) ;
}
static void F_9 ( struct V_32 * V_33 )
{
}
static void F_13 ( struct V_32 * V_33 )
{
}
static void F_15 ( struct V_32 * V_33 , struct V_38 * V_39 )
{
if ( V_39 && V_39 != V_33 -> V_40 ) {
struct V_3 * V_4 = V_39 -> V_41 ;
F_13 ( V_33 ) ;
F_16 ( & V_4 -> V_42 ) ;
F_17 ( V_4 ) ;
}
}
static void * F_18 ( struct V_1 * V_2 , T_1 * V_43 )
{
struct V_32 * V_33 = V_2 -> V_44 ;
unsigned long V_45 = V_2 -> V_46 ;
struct V_3 * V_4 ;
struct V_38 * V_39 , * V_40 = NULL ;
T_1 V_47 = * V_43 ;
V_33 -> V_35 = NULL ;
V_33 -> V_40 = NULL ;
if ( V_45 == - 1UL )
return NULL ;
V_33 -> V_35 = F_19 ( V_33 -> V_48 , V_49 ) ;
if ( ! V_33 -> V_35 )
return F_20 ( - V_50 ) ;
V_4 = F_21 ( V_33 -> V_35 , V_51 ) ;
if ( ! V_4 || F_22 ( V_4 ) )
return V_4 ;
F_23 ( & V_4 -> V_42 ) ;
V_40 = F_24 ( V_33 -> V_35 -> V_4 ) ;
V_33 -> V_40 = V_40 ;
F_9 ( V_33 ) ;
V_39 = F_25 ( V_4 , V_45 ) ;
if ( V_45 && V_39 ) {
V_39 = V_39 -> V_52 ;
goto V_53;
}
V_39 = NULL ;
if ( ( unsigned long ) V_47 < V_4 -> V_54 ) {
V_39 = V_4 -> V_55 ;
while ( V_47 -- && V_39 )
V_39 = V_39 -> V_52 ;
goto V_53;
}
if ( V_47 != V_4 -> V_54 )
V_40 = NULL ;
V_53:
if ( V_39 )
return V_39 ;
F_13 ( V_33 ) ;
V_2 -> V_46 = ( V_40 != NULL ) ? 0 : - 1UL ;
F_16 ( & V_4 -> V_42 ) ;
F_17 ( V_4 ) ;
return V_40 ;
}
static void * F_26 ( struct V_1 * V_2 , void * V_56 , T_1 * V_43 )
{
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_38 * V_39 = V_56 ;
struct V_38 * V_40 = V_33 -> V_40 ;
( * V_43 ) ++ ;
if ( V_39 && ( V_39 != V_40 ) && V_39 -> V_52 )
return V_39 -> V_52 ;
F_15 ( V_33 , V_39 ) ;
return ( V_39 != V_40 ) ? V_40 : NULL ;
}
static void F_27 ( struct V_1 * V_2 , void * V_56 )
{
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_38 * V_39 = V_56 ;
if ( ! F_22 ( V_39 ) )
F_15 ( V_33 , V_39 ) ;
if ( V_33 -> V_35 )
F_28 ( V_33 -> V_35 ) ;
}
static int F_29 ( struct V_57 * V_57 , struct V_58 * V_58 ,
const struct V_59 * V_60 )
{
struct V_32 * V_33 ;
int V_61 = - V_62 ;
V_33 = F_30 ( sizeof( * V_33 ) , V_63 ) ;
if ( V_33 ) {
V_33 -> V_48 = F_31 ( V_57 ) ;
V_61 = F_32 ( V_58 , V_60 ) ;
if ( ! V_61 ) {
struct V_1 * V_2 = V_58 -> V_64 ;
V_2 -> V_44 = V_33 ;
} else {
F_33 ( V_33 ) ;
}
}
return V_61 ;
}
static void
F_34 ( struct V_1 * V_2 , struct V_38 * V_39 , int V_65 )
{
struct V_3 * V_4 = V_39 -> V_41 ;
struct V_58 * V_58 = V_39 -> V_66 ;
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_34 * V_35 = V_33 -> V_35 ;
T_2 V_67 = V_39 -> V_68 ;
unsigned long V_69 = 0 ;
unsigned long long V_70 = 0 ;
unsigned long V_71 , V_72 ;
T_3 V_73 = 0 ;
int V_31 ;
const char * V_74 = NULL ;
if ( V_58 ) {
struct V_57 * V_57 = F_35 ( V_39 -> V_66 ) ;
V_73 = V_57 -> V_75 -> V_76 ;
V_69 = V_57 -> V_77 ;
V_70 = ( ( T_1 ) V_39 -> V_78 ) << V_19 ;
}
V_71 = V_39 -> V_79 ;
if ( F_36 ( V_39 , V_71 ) )
V_71 += V_26 ;
V_72 = V_39 -> V_80 ;
if ( F_37 ( V_39 , V_72 ) )
V_72 -= V_26 ;
F_5 ( V_2 , L_14 ,
V_71 ,
V_72 ,
V_67 & V_81 ? 'r' : '-' ,
V_67 & V_82 ? 'w' : '-' ,
V_67 & V_83 ? 'x' : '-' ,
V_67 & V_84 ? 's' : 'p' ,
V_70 ,
F_38 ( V_73 ) , F_39 ( V_73 ) , V_69 , & V_31 ) ;
if ( V_58 ) {
F_8 ( V_2 , V_31 ) ;
F_40 ( V_2 , & V_58 -> V_85 , L_15 ) ;
goto V_86;
}
V_74 = F_41 ( V_39 ) ;
if ( ! V_74 ) {
T_4 V_87 ;
if ( ! V_4 ) {
V_74 = L_16 ;
goto V_86;
}
if ( V_39 -> V_79 <= V_4 -> V_88 &&
V_39 -> V_80 >= V_4 -> V_89 ) {
V_74 = L_17 ;
goto V_86;
}
V_87 = F_42 ( V_35 , V_39 , V_65 ) ;
if ( V_87 != 0 ) {
if ( ! V_65 || ( V_39 -> V_79 <= V_4 -> V_90 &&
V_39 -> V_80 >= V_4 -> V_90 ) ) {
V_74 = L_18 ;
} else {
F_8 ( V_2 , V_31 ) ;
F_5 ( V_2 , L_19 , V_87 ) ;
}
}
}
V_86:
if ( V_74 ) {
F_8 ( V_2 , V_31 ) ;
F_43 ( V_2 , V_74 ) ;
}
F_44 ( V_2 , '\n' ) ;
}
static int F_45 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_38 * V_39 = V_56 ;
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_34 * V_35 = V_33 -> V_35 ;
F_34 ( V_2 , V_39 , V_65 ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
V_2 -> V_46 = ( V_39 != F_24 ( V_35 -> V_4 ) )
? V_39 -> V_79 : 0 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , void * V_56 )
{
return F_45 ( V_2 , V_56 , 1 ) ;
}
static int F_47 ( struct V_1 * V_2 , void * V_56 )
{
return F_45 ( V_2 , V_56 , 0 ) ;
}
static int F_48 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_93 ) ;
}
static int F_49 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_94 ) ;
}
static void F_50 ( V_24 V_95 , unsigned long V_96 ,
unsigned long V_97 , struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_44 ;
struct V_38 * V_39 = V_101 -> V_39 ;
T_5 V_70 = F_51 ( V_39 , V_96 ) ;
struct V_102 * V_102 = NULL ;
int V_103 ;
if ( F_52 ( V_95 ) ) {
V_102 = F_53 ( V_39 , V_96 , V_95 ) ;
} else if ( F_54 ( V_95 ) ) {
T_6 V_104 = F_55 ( V_95 ) ;
if ( ! F_56 ( V_104 ) )
V_101 -> V_8 += V_97 ;
else if ( F_57 ( V_104 ) )
V_102 = F_58 ( V_104 ) ;
} else if ( F_59 ( V_95 ) ) {
if ( F_60 ( V_95 ) != V_70 )
V_101 -> V_105 += V_97 ;
}
if ( ! V_102 )
return;
if ( F_61 ( V_102 ) )
V_101 -> V_106 += V_97 ;
if ( V_102 -> V_107 != V_70 )
V_101 -> V_105 += V_97 ;
V_101 -> V_28 += V_97 ;
if ( F_62 ( V_95 ) || F_63 ( V_102 ) )
V_101 -> V_108 += V_97 ;
V_103 = F_64 ( V_102 ) ;
if ( V_103 >= 2 ) {
if ( F_65 ( V_95 ) || F_66 ( V_102 ) )
V_101 -> V_109 += V_97 ;
else
V_101 -> V_110 += V_97 ;
V_101 -> V_111 += ( V_97 << V_112 ) / V_103 ;
} else {
if ( F_65 ( V_95 ) || F_66 ( V_102 ) )
V_101 -> V_113 += V_97 ;
else
V_101 -> V_114 += V_97 ;
V_101 -> V_111 += ( V_97 << V_112 ) ;
}
}
static int F_67 ( T_7 * V_115 , unsigned long V_96 , unsigned long V_72 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_44 ;
struct V_38 * V_39 = V_101 -> V_39 ;
V_24 * V_116 ;
T_8 * V_117 ;
if ( F_68 ( V_115 , V_39 ) == 1 ) {
F_50 ( * ( V_24 * ) V_115 , V_96 , V_118 , V_99 ) ;
F_69 ( & V_99 -> V_4 -> V_119 ) ;
V_101 -> V_120 += V_118 ;
return 0 ;
}
if ( F_70 ( V_115 ) )
return 0 ;
V_116 = F_71 ( V_39 -> V_41 , V_115 , V_96 , & V_117 ) ;
for (; V_96 != V_72 ; V_116 ++ , V_96 += V_26 )
F_50 ( * V_116 , V_96 , V_26 , V_99 ) ;
F_72 ( V_116 - 1 , V_117 ) ;
F_73 () ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
static const char V_121 [ V_122 ] [ 2 ] = {
[ 0 ... ( V_122 - 1 ) ] = L_20 ,
[ F_75 ( V_81 ) ] = L_21 ,
[ F_75 ( V_82 ) ] = L_22 ,
[ F_75 ( V_83 ) ] = L_23 ,
[ F_75 ( V_123 ) ] = L_24 ,
[ F_75 ( V_124 ) ] = L_25 ,
[ F_75 ( V_125 ) ] = L_26 ,
[ F_75 ( V_126 ) ] = L_27 ,
[ F_75 ( V_84 ) ] = L_28 ,
[ F_75 ( V_127 ) ] = L_29 ,
[ F_75 ( V_128 ) ] = L_30 ,
[ F_75 ( V_129 ) ] = L_31 ,
[ F_75 ( V_130 ) ] = L_32 ,
[ F_75 ( V_131 ) ] = L_33 ,
[ F_75 ( V_132 ) ] = L_34 ,
[ F_75 ( V_133 ) ] = L_35 ,
[ F_75 ( V_134 ) ] = L_36 ,
[ F_75 ( V_135 ) ] = L_37 ,
[ F_75 ( V_136 ) ] = L_38 ,
[ F_75 ( V_137 ) ] = L_39 ,
[ F_75 ( V_138 ) ] = L_40 ,
[ F_75 ( V_139 ) ] = L_41 ,
[ F_75 ( V_140 ) ] = L_42 ,
[ F_75 ( V_141 ) ] = L_43 ,
[ F_75 ( V_142 ) ] = L_44 ,
[ F_75 ( V_143 ) ] = L_45 ,
[ F_75 ( V_144 ) ] = L_46 ,
[ F_75 ( V_145 ) ] = L_47 ,
} ;
T_9 V_146 ;
F_43 ( V_2 , L_48 ) ;
for ( V_146 = 0 ; V_146 < V_122 ; V_146 ++ ) {
if ( V_39 -> V_68 & ( 1UL << V_146 ) ) {
F_5 ( V_2 , L_49 ,
V_121 [ V_146 ] [ 0 ] , V_121 [ V_146 ] [ 1 ] ) ;
}
}
F_44 ( V_2 , '\n' ) ;
}
static int F_76 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_38 * V_39 = V_56 ;
struct V_100 V_101 ;
struct V_98 V_147 = {
. V_148 = F_67 ,
. V_4 = V_39 -> V_41 ,
. V_44 = & V_101 ,
} ;
memset ( & V_101 , 0 , sizeof V_101 ) ;
V_101 . V_39 = V_39 ;
if ( V_39 -> V_41 && ! F_77 ( V_39 ) )
F_78 ( V_39 -> V_79 , V_39 -> V_80 , & V_147 ) ;
F_34 ( V_2 , V_39 , V_65 ) ;
F_5 ( V_2 ,
L_50
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
L_63 ,
( V_39 -> V_80 - V_39 -> V_79 ) >> 10 ,
V_101 . V_28 >> 10 ,
( unsigned long ) ( V_101 . V_111 >> ( 10 + V_112 ) ) ,
V_101 . V_110 >> 10 ,
V_101 . V_109 >> 10 ,
V_101 . V_114 >> 10 ,
V_101 . V_113 >> 10 ,
V_101 . V_108 >> 10 ,
V_101 . V_106 >> 10 ,
V_101 . V_120 >> 10 ,
V_101 . V_8 >> 10 ,
F_79 ( V_39 ) >> 10 ,
F_80 ( V_39 ) >> 10 ,
( V_39 -> V_68 & V_130 ) ?
( unsigned long ) ( V_101 . V_111 >> ( 10 + V_112 ) ) : 0 ) ;
if ( V_39 -> V_68 & V_139 )
F_5 ( V_2 , L_64 ,
V_101 . V_105 >> 10 ) ;
F_74 ( V_2 , V_39 ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
V_2 -> V_46 = ( V_39 != F_24 ( V_35 -> V_4 ) )
? V_39 -> V_79 : 0 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_56 )
{
return F_76 ( V_2 , V_56 , 1 ) ;
}
static int F_82 ( struct V_1 * V_2 , void * V_56 )
{
return F_76 ( V_2 , V_56 , 0 ) ;
}
static int F_83 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_149 ) ;
}
static int F_84 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_150 ) ;
}
static inline void F_85 ( struct V_38 * V_39 ,
unsigned long V_96 , V_24 * V_116 )
{
#ifdef F_86
V_24 V_95 = * V_116 ;
if ( F_52 ( V_95 ) ) {
V_95 = F_87 ( V_95 ) ;
V_95 = F_88 ( V_95 , V_151 ) ;
} else if ( F_54 ( V_95 ) ) {
V_95 = F_89 ( V_95 ) ;
} else if ( F_59 ( V_95 ) ) {
V_95 = F_90 ( V_95 ) ;
}
F_91 ( V_39 -> V_41 , V_96 , V_116 , V_95 ) ;
#endif
}
static int F_92 ( T_7 * V_115 , unsigned long V_96 ,
unsigned long V_72 , struct V_98 * V_99 )
{
struct V_152 * V_153 = V_99 -> V_44 ;
struct V_38 * V_39 = V_153 -> V_39 ;
V_24 * V_116 , V_95 ;
T_8 * V_117 ;
struct V_102 * V_102 ;
F_93 ( V_39 , V_96 , V_115 ) ;
if ( F_70 ( V_115 ) )
return 0 ;
V_116 = F_71 ( V_39 -> V_41 , V_115 , V_96 , & V_117 ) ;
for (; V_96 != V_72 ; V_116 ++ , V_96 += V_26 ) {
V_95 = * V_116 ;
if ( V_153 -> type == V_154 ) {
F_85 ( V_39 , V_96 , V_116 ) ;
continue;
}
if ( ! F_52 ( V_95 ) )
continue;
V_102 = F_53 ( V_39 , V_96 , V_95 ) ;
if ( ! V_102 )
continue;
F_94 ( V_39 , V_96 , V_116 ) ;
F_95 ( V_102 ) ;
}
F_72 ( V_116 - 1 , V_117 ) ;
F_73 () ;
return 0 ;
}
static T_10 F_96 ( struct V_58 * V_58 , const char T_11 * V_155 ,
T_9 V_91 , T_1 * V_156 )
{
struct V_34 * V_35 ;
char V_157 [ V_158 ] ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
enum V_159 type ;
int V_160 ;
int V_161 ;
memset ( V_157 , 0 , sizeof( V_157 ) ) ;
if ( V_91 > sizeof( V_157 ) - 1 )
V_91 = sizeof( V_157 ) - 1 ;
if ( F_97 ( V_157 , V_155 , V_91 ) )
return - V_162 ;
V_161 = F_98 ( F_99 ( V_157 ) , 10 , & V_160 ) ;
if ( V_161 < 0 )
return V_161 ;
type = (enum V_159 ) V_160 ;
if ( type < V_163 || type >= V_164 )
return - V_165 ;
if ( type == V_154 ) {
V_166 = true ;
F_100 ( L_65
L_66 ) ;
}
V_35 = F_101 ( F_35 ( V_58 ) ) ;
if ( ! V_35 )
return - V_50 ;
V_4 = F_102 ( V_35 ) ;
if ( V_4 ) {
struct V_152 V_153 = {
. type = type ,
} ;
struct V_98 V_167 = {
. V_148 = F_92 ,
. V_4 = V_4 ,
. V_44 = & V_153 ,
} ;
F_23 ( & V_4 -> V_42 ) ;
if ( type == V_154 )
F_103 ( V_4 , 0 , - 1 ) ;
for ( V_39 = V_4 -> V_55 ; V_39 ; V_39 = V_39 -> V_52 ) {
V_153 . V_39 = V_39 ;
if ( F_77 ( V_39 ) )
continue;
if ( type == V_168 && V_39 -> V_66 )
continue;
if ( type == V_169 && ! V_39 -> V_66 )
continue;
F_78 ( V_39 -> V_79 , V_39 -> V_80 ,
& V_167 ) ;
}
if ( type == V_154 )
F_104 ( V_4 , 0 , - 1 ) ;
F_105 ( V_4 ) ;
F_16 ( & V_4 -> V_42 ) ;
F_17 ( V_4 ) ;
}
F_28 ( V_35 ) ;
return V_91 ;
}
static inline T_12 F_106 ( T_13 V_170 )
{
return ( T_12 ) { . V_171 = V_170 } ;
}
static int F_107 ( unsigned long V_96 , T_12 * V_171 ,
struct V_172 * V_173 )
{
V_173 -> V_157 [ V_173 -> V_43 ++ ] = * V_171 ;
if ( V_173 -> V_43 >= V_173 -> V_31 )
return V_174 ;
return 0 ;
}
static int F_108 ( unsigned long V_71 , unsigned long V_72 ,
struct V_98 * V_99 )
{
struct V_172 * V_173 = V_99 -> V_44 ;
unsigned long V_96 ;
int V_175 = 0 ;
T_12 V_171 = F_106 ( F_109 ( V_173 -> V_176 ) ) ;
for ( V_96 = V_71 ; V_96 < V_72 ; V_96 += V_26 ) {
V_175 = F_107 ( V_96 , & V_171 , V_173 ) ;
if ( V_175 )
break;
}
return V_175 ;
}
static void F_110 ( T_12 * V_171 , struct V_172 * V_173 ,
struct V_38 * V_39 , unsigned long V_96 , V_24 V_116 )
{
T_13 V_177 , V_67 ;
struct V_102 * V_102 = NULL ;
int V_178 = 0 ;
if ( F_52 ( V_116 ) ) {
V_177 = F_111 ( V_116 ) ;
V_67 = V_179 ;
V_102 = F_53 ( V_39 , V_96 , V_116 ) ;
} else if ( F_54 ( V_116 ) ) {
T_6 V_180 ;
if ( F_112 ( V_116 ) )
V_178 |= V_181 ;
V_180 = F_55 ( V_116 ) ;
V_177 = F_113 ( V_180 ) |
( F_114 ( V_180 ) << V_182 ) ;
V_67 = V_183 ;
if ( F_57 ( V_180 ) )
V_102 = F_58 ( V_180 ) ;
} else {
* V_171 = F_106 ( F_109 ( V_173 -> V_176 ) ) ;
return;
}
if ( V_102 && ! F_61 ( V_102 ) )
V_67 |= V_184 ;
if ( F_115 ( V_116 ) )
V_178 |= V_181 ;
* V_171 = F_106 ( F_116 ( V_177 ) | F_117 ( V_173 -> V_176 , V_178 ) | V_67 ) ;
}
static void F_118 ( T_12 * V_171 , struct V_172 * V_173 ,
T_7 V_115 , int V_185 , int V_186 )
{
if ( F_119 ( V_115 ) )
* V_171 = F_106 ( F_116 ( F_120 ( V_115 ) + V_185 )
| F_117 ( V_173 -> V_176 , V_186 ) | V_179 ) ;
else
* V_171 = F_106 ( F_109 ( V_173 -> V_176 ) ) ;
}
static inline void F_118 ( T_12 * V_171 , struct V_172 * V_173 ,
T_7 V_115 , int V_185 , int V_186 )
{
}
static int F_121 ( T_7 * V_115 , unsigned long V_96 , unsigned long V_72 ,
struct V_98 * V_99 )
{
struct V_38 * V_39 ;
struct V_172 * V_173 = V_99 -> V_44 ;
V_24 * V_116 ;
int V_175 = 0 ;
T_12 V_171 = F_106 ( F_109 ( V_173 -> V_176 ) ) ;
V_39 = F_25 ( V_99 -> V_4 , V_96 ) ;
if ( V_39 && F_68 ( V_115 , V_39 ) == 1 ) {
int V_186 ;
V_186 = ( F_122 ( * V_115 ) ? V_181 : 0 ) ;
for (; V_96 != V_72 ; V_96 += V_26 ) {
unsigned long V_185 ;
V_185 = ( V_96 & ~ V_187 ) >>
V_19 ;
F_118 ( & V_171 , V_173 , * V_115 , V_185 , V_186 ) ;
V_175 = F_107 ( V_96 , & V_171 , V_173 ) ;
if ( V_175 )
break;
}
F_69 ( & V_99 -> V_4 -> V_119 ) ;
return V_175 ;
}
if ( F_70 ( V_115 ) )
return 0 ;
for (; V_96 != V_72 ; V_96 += V_26 ) {
if ( V_39 && ( V_96 >= V_39 -> V_80 ) ) {
V_39 = F_25 ( V_99 -> V_4 , V_96 ) ;
V_171 = F_106 ( F_109 ( V_173 -> V_176 ) ) ;
}
if ( V_39 && ( V_39 -> V_79 <= V_96 ) &&
! F_77 ( V_39 ) ) {
V_116 = F_123 ( V_115 , V_96 ) ;
F_110 ( & V_171 , V_173 , V_39 , V_96 , * V_116 ) ;
F_124 ( V_116 ) ;
}
V_175 = F_107 ( V_96 , & V_171 , V_173 ) ;
if ( V_175 )
return V_175 ;
}
F_73 () ;
return V_175 ;
}
static void F_125 ( T_12 * V_171 , struct V_172 * V_173 ,
V_24 V_116 , int V_185 )
{
if ( F_52 ( V_116 ) )
* V_171 = F_106 ( F_116 ( F_111 ( V_116 ) + V_185 )
| F_117 ( V_173 -> V_176 , 0 ) | V_179 ) ;
else
* V_171 = F_106 ( F_109 ( V_173 -> V_176 ) ) ;
}
static int F_126 ( V_24 * V_116 , unsigned long V_188 ,
unsigned long V_96 , unsigned long V_72 ,
struct V_98 * V_99 )
{
struct V_172 * V_173 = V_99 -> V_44 ;
int V_175 = 0 ;
T_12 V_171 ;
for (; V_96 != V_72 ; V_96 += V_26 ) {
int V_185 = ( V_96 & ~ V_188 ) >> V_19 ;
F_125 ( & V_171 , V_173 , * V_116 , V_185 ) ;
V_175 = F_107 ( V_96 , & V_171 , V_173 ) ;
if ( V_175 )
return V_175 ;
}
F_73 () ;
return V_175 ;
}
static T_10 F_127 ( struct V_58 * V_58 , char T_11 * V_155 ,
T_9 V_91 , T_1 * V_156 )
{
struct V_34 * V_35 = F_101 ( F_35 ( V_58 ) ) ;
struct V_3 * V_4 ;
struct V_172 V_173 ;
int V_61 = - V_50 ;
struct V_98 V_189 = {} ;
unsigned long V_190 ;
unsigned long V_191 ;
unsigned long V_192 ;
unsigned long V_193 ;
int V_194 = 0 ;
if ( ! V_35 )
goto V_53;
V_61 = - V_165 ;
if ( ( * V_156 % V_195 ) || ( V_91 % V_195 ) )
goto V_196;
V_61 = 0 ;
if ( ! V_91 )
goto V_196;
V_173 . V_176 = V_166 ;
V_173 . V_31 = ( V_197 >> V_19 ) ;
V_173 . V_157 = F_128 ( V_173 . V_31 * V_195 , V_198 ) ;
V_61 = - V_62 ;
if ( ! V_173 . V_157 )
goto V_196;
V_4 = F_21 ( V_35 , V_51 ) ;
V_61 = F_129 ( V_4 ) ;
if ( ! V_4 || F_22 ( V_4 ) )
goto V_199;
V_189 . V_148 = F_121 ;
V_189 . V_200 = F_108 ;
#ifdef F_130
V_189 . V_201 = F_126 ;
#endif
V_189 . V_4 = V_4 ;
V_189 . V_44 = & V_173 ;
V_190 = * V_156 ;
V_191 = V_190 / V_195 ;
V_192 = V_191 << V_19 ;
V_193 = F_131 ( V_35 ) ;
if ( V_191 > F_131 ( V_35 ) >> V_19 )
V_192 = V_193 ;
V_61 = 0 ;
while ( V_91 && ( V_192 < V_193 ) ) {
int V_31 ;
unsigned long V_72 ;
V_173 . V_43 = 0 ;
V_72 = ( V_192 + V_197 ) & V_187 ;
if ( V_72 < V_192 || V_72 > V_193 )
V_72 = V_193 ;
F_23 ( & V_4 -> V_42 ) ;
V_61 = F_78 ( V_192 , V_72 , & V_189 ) ;
F_16 ( & V_4 -> V_42 ) ;
V_192 = V_72 ;
V_31 = F_132 ( V_91 , V_195 * V_173 . V_43 ) ;
if ( F_133 ( V_155 , V_173 . V_157 , V_31 ) ) {
V_61 = - V_162 ;
goto V_202;
}
V_194 += V_31 ;
V_155 += V_31 ;
V_91 -= V_31 ;
}
* V_156 += V_194 ;
if ( ! V_61 || V_61 == V_174 )
V_61 = V_194 ;
V_202:
F_17 ( V_4 ) ;
V_199:
F_33 ( V_173 . V_157 ) ;
V_196:
F_28 ( V_35 ) ;
V_53:
return V_61 ;
}
static int F_134 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
F_100 ( L_67
L_68
L_69 ) ;
return 0 ;
}
static void F_135 ( struct V_102 * V_102 , struct V_203 * V_204 , int F_65 ,
unsigned long V_205 )
{
int V_91 = F_64 ( V_102 ) ;
V_204 -> V_206 += V_205 ;
if ( F_65 || F_66 ( V_102 ) )
V_204 -> V_207 += V_205 ;
if ( F_136 ( V_102 ) )
V_204 -> V_208 += V_205 ;
if ( F_137 ( V_102 ) || F_138 ( V_102 ) )
V_204 -> V_209 += V_205 ;
if ( F_139 ( V_102 ) )
V_204 -> V_210 += V_205 ;
if ( F_61 ( V_102 ) )
V_204 -> V_211 += V_205 ;
if ( V_91 > V_204 -> V_212 )
V_204 -> V_212 = V_91 ;
V_204 -> V_213 [ F_140 ( V_102 ) ] += V_205 ;
}
static struct V_102 * F_141 ( V_24 V_116 , struct V_38 * V_39 ,
unsigned long V_96 )
{
struct V_102 * V_102 ;
int V_214 ;
if ( ! F_52 ( V_116 ) )
return NULL ;
V_102 = F_53 ( V_39 , V_96 , V_116 ) ;
if ( ! V_102 )
return NULL ;
if ( F_142 ( V_102 ) )
return NULL ;
V_214 = F_140 ( V_102 ) ;
if ( ! F_143 ( V_214 , V_215 [ V_216 ] ) )
return NULL ;
return V_102 ;
}
static int F_144 ( T_7 * V_115 , unsigned long V_96 ,
unsigned long V_72 , struct V_98 * V_99 )
{
struct V_203 * V_204 ;
T_8 * V_117 ;
V_24 * V_217 ;
V_24 * V_116 ;
V_204 = V_99 -> V_44 ;
if ( F_68 ( V_115 , V_204 -> V_39 ) == 1 ) {
V_24 V_218 = * ( V_24 * ) V_115 ;
struct V_102 * V_102 ;
V_102 = F_141 ( V_218 , V_204 -> V_39 , V_96 ) ;
if ( V_102 )
F_135 ( V_102 , V_204 , F_65 ( V_218 ) ,
V_118 / V_26 ) ;
F_69 ( & V_99 -> V_4 -> V_119 ) ;
return 0 ;
}
if ( F_70 ( V_115 ) )
return 0 ;
V_217 = V_116 = F_71 ( V_99 -> V_4 , V_115 , V_96 , & V_117 ) ;
do {
struct V_102 * V_102 = F_141 ( * V_116 , V_204 -> V_39 , V_96 ) ;
if ( ! V_102 )
continue;
F_135 ( V_102 , V_204 , F_65 ( * V_116 ) , 1 ) ;
} while ( V_116 ++ , V_96 += V_26 , V_96 != V_72 );
F_72 ( V_217 , V_117 ) ;
return 0 ;
}
static int F_145 ( V_24 * V_116 , unsigned long V_188 ,
unsigned long V_96 , unsigned long V_72 , struct V_98 * V_99 )
{
struct V_203 * V_204 ;
struct V_102 * V_102 ;
if ( F_146 ( * V_116 ) )
return 0 ;
V_102 = F_147 ( * V_116 ) ;
if ( ! V_102 )
return 0 ;
V_204 = V_99 -> V_44 ;
F_135 ( V_102 , V_204 , F_65 ( * V_116 ) , 1 ) ;
return 0 ;
}
static int F_145 ( V_24 * V_116 , unsigned long V_188 ,
unsigned long V_96 , unsigned long V_72 , struct V_98 * V_99 )
{
return 0 ;
}
static int F_148 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_219 * V_220 = V_2 -> V_44 ;
struct V_32 * V_221 = & V_220 -> V_222 ;
struct V_38 * V_39 = V_56 ;
struct V_203 * V_204 = & V_220 -> V_204 ;
struct V_58 * V_58 = V_39 -> V_66 ;
struct V_34 * V_35 = V_221 -> V_35 ;
struct V_3 * V_4 = V_39 -> V_41 ;
struct V_98 V_99 = {} ;
struct V_37 * V_223 ;
int V_224 ;
char V_157 [ 50 ] ;
if ( ! V_4 )
return 0 ;
memset ( V_204 , 0 , sizeof( * V_204 ) ) ;
V_204 -> V_39 = V_39 ;
V_99 . V_201 = F_145 ;
V_99 . V_148 = F_144 ;
V_99 . V_44 = V_204 ;
V_99 . V_4 = V_4 ;
V_223 = F_149 ( V_35 , V_39 , V_39 -> V_79 ) ;
F_150 ( V_157 , sizeof( V_157 ) , V_223 ) ;
F_151 ( V_223 ) ;
F_5 ( V_2 , L_70 , V_39 -> V_79 , V_157 ) ;
if ( V_58 ) {
F_5 ( V_2 , L_71 ) ;
F_40 ( V_2 , & V_58 -> V_85 , L_72 ) ;
} else if ( V_39 -> V_79 <= V_4 -> V_88 && V_39 -> V_80 >= V_4 -> V_89 ) {
F_5 ( V_2 , L_73 ) ;
} else {
T_4 V_87 = F_42 ( V_35 , V_39 , V_65 ) ;
if ( V_87 != 0 ) {
if ( ! V_65 || ( V_39 -> V_79 <= V_4 -> V_90 &&
V_39 -> V_80 >= V_4 -> V_90 ) )
F_5 ( V_2 , L_74 ) ;
else
F_5 ( V_2 , L_75 , V_87 ) ;
}
}
if ( F_77 ( V_39 ) )
F_5 ( V_2 , L_76 ) ;
F_78 ( V_39 -> V_79 , V_39 -> V_80 , & V_99 ) ;
if ( ! V_204 -> V_206 )
goto V_53;
if ( V_204 -> V_211 )
F_5 ( V_2 , L_77 , V_204 -> V_211 ) ;
if ( V_204 -> V_207 )
F_5 ( V_2 , L_78 , V_204 -> V_207 ) ;
if ( V_204 -> V_206 != V_204 -> V_211 && V_204 -> V_206 != V_204 -> V_207 )
F_5 ( V_2 , L_79 , V_204 -> V_206 ) ;
if ( V_204 -> V_212 > 1 )
F_5 ( V_2 , L_80 , V_204 -> V_212 ) ;
if ( V_204 -> V_208 )
F_5 ( V_2 , L_81 , V_204 -> V_208 ) ;
if ( V_204 -> V_209 < V_204 -> V_206 && ! F_77 ( V_39 ) )
F_5 ( V_2 , L_82 , V_204 -> V_209 ) ;
if ( V_204 -> V_210 )
F_5 ( V_2 , L_83 , V_204 -> V_210 ) ;
F_152 (n, N_MEMORY)
if ( V_204 -> V_213 [ V_224 ] )
F_5 ( V_2 , L_84 , V_224 , V_204 -> V_213 [ V_224 ] ) ;
V_53:
F_44 ( V_2 , '\n' ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
V_2 -> V_46 = ( V_39 != V_221 -> V_40 ) ? V_39 -> V_79 : 0 ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 , void * V_56 )
{
return F_148 ( V_2 , V_56 , 1 ) ;
}
static int F_154 ( struct V_1 * V_2 , void * V_56 )
{
return F_148 ( V_2 , V_56 , 0 ) ;
}
static int F_155 ( struct V_57 * V_57 , struct V_58 * V_58 ,
const struct V_59 * V_60 )
{
struct V_219 * V_33 ;
int V_61 = - V_62 ;
V_33 = F_30 ( sizeof( * V_33 ) , V_63 ) ;
if ( V_33 ) {
V_33 -> V_222 . V_48 = F_31 ( V_57 ) ;
V_61 = F_32 ( V_58 , V_60 ) ;
if ( ! V_61 ) {
struct V_1 * V_2 = V_58 -> V_64 ;
V_2 -> V_44 = V_33 ;
} else {
F_33 ( V_33 ) ;
}
}
return V_61 ;
}
static int F_156 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_155 ( V_57 , V_58 , & V_225 ) ;
}
static int F_157 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_155 ( V_57 , V_58 , & V_226 ) ;
}
