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
V_32 -> V_35 = V_34 -> V_36 ;
F_11 ( V_32 -> V_35 ) ;
F_12 ( V_34 ) ;
}
static void F_13 ( struct V_31 * V_32 )
{
F_14 ( V_32 -> V_35 ) ;
}
static void F_9 ( struct V_31 * V_32 )
{
}
static void F_13 ( struct V_31 * V_32 )
{
}
static void F_15 ( struct V_31 * V_32 , struct V_37 * V_38 )
{
if ( V_38 && V_38 != V_32 -> V_39 ) {
struct V_3 * V_4 = V_38 -> V_40 ;
F_13 ( V_32 ) ;
F_16 ( & V_4 -> V_41 ) ;
F_17 ( V_4 ) ;
}
}
static void * F_18 ( struct V_1 * V_2 , T_1 * V_42 )
{
struct V_31 * V_32 = V_2 -> V_43 ;
unsigned long V_44 = V_2 -> V_45 ;
struct V_3 * V_4 ;
struct V_37 * V_38 , * V_39 = NULL ;
T_1 V_46 = * V_42 ;
V_32 -> V_34 = NULL ;
V_32 -> V_39 = NULL ;
if ( V_44 == - 1UL )
return NULL ;
V_32 -> V_34 = F_19 ( V_32 -> V_47 , V_48 ) ;
if ( ! V_32 -> V_34 )
return F_20 ( - V_49 ) ;
V_4 = F_21 ( V_32 -> V_34 , V_50 ) ;
if ( ! V_4 || F_22 ( V_4 ) )
return V_4 ;
F_23 ( & V_4 -> V_41 ) ;
V_39 = F_24 ( V_32 -> V_34 -> V_4 ) ;
V_32 -> V_39 = V_39 ;
F_9 ( V_32 ) ;
V_38 = F_25 ( V_4 , V_44 ) ;
if ( V_44 && V_38 ) {
V_38 = V_38 -> V_51 ;
goto V_52;
}
V_38 = NULL ;
if ( ( unsigned long ) V_46 < V_4 -> V_53 ) {
V_38 = V_4 -> V_54 ;
while ( V_46 -- && V_38 )
V_38 = V_38 -> V_51 ;
goto V_52;
}
if ( V_46 != V_4 -> V_53 )
V_39 = NULL ;
V_52:
if ( V_38 )
return V_38 ;
F_13 ( V_32 ) ;
V_2 -> V_45 = ( V_39 != NULL ) ? 0 : - 1UL ;
F_16 ( & V_4 -> V_41 ) ;
F_17 ( V_4 ) ;
return V_39 ;
}
static void * F_26 ( struct V_1 * V_2 , void * V_55 , T_1 * V_42 )
{
struct V_31 * V_32 = V_2 -> V_43 ;
struct V_37 * V_38 = V_55 ;
struct V_37 * V_39 = V_32 -> V_39 ;
( * V_42 ) ++ ;
if ( V_38 && ( V_38 != V_39 ) && V_38 -> V_51 )
return V_38 -> V_51 ;
F_15 ( V_32 , V_38 ) ;
return ( V_38 != V_39 ) ? V_39 : NULL ;
}
static void F_27 ( struct V_1 * V_2 , void * V_55 )
{
struct V_31 * V_32 = V_2 -> V_43 ;
struct V_37 * V_38 = V_55 ;
if ( ! F_22 ( V_38 ) )
F_15 ( V_32 , V_38 ) ;
if ( V_32 -> V_34 )
F_28 ( V_32 -> V_34 ) ;
}
static int F_29 ( struct V_56 * V_56 , struct V_57 * V_57 ,
const struct V_58 * V_59 )
{
struct V_31 * V_32 ;
int V_60 = - V_61 ;
V_32 = F_30 ( sizeof( * V_32 ) , V_62 ) ;
if ( V_32 ) {
V_32 -> V_47 = F_31 ( V_56 ) ;
V_60 = F_32 ( V_57 , V_59 ) ;
if ( ! V_60 ) {
struct V_1 * V_2 = V_57 -> V_63 ;
V_2 -> V_43 = V_32 ;
} else {
F_33 ( V_32 ) ;
}
}
return V_60 ;
}
static void
F_34 ( struct V_1 * V_2 , struct V_37 * V_38 , int V_64 )
{
struct V_3 * V_4 = V_38 -> V_40 ;
struct V_57 * V_57 = V_38 -> V_65 ;
struct V_31 * V_32 = V_2 -> V_43 ;
struct V_33 * V_34 = V_32 -> V_34 ;
T_2 V_66 = V_38 -> V_67 ;
unsigned long V_68 = 0 ;
unsigned long long V_69 = 0 ;
unsigned long V_70 , V_71 ;
T_3 V_72 = 0 ;
const char * V_73 = NULL ;
if ( V_57 ) {
struct V_56 * V_56 = F_35 ( V_38 -> V_65 ) ;
V_72 = V_56 -> V_74 -> V_75 ;
V_68 = V_56 -> V_76 ;
V_69 = ( ( T_1 ) V_38 -> V_77 ) << V_19 ;
}
V_70 = V_38 -> V_78 ;
if ( F_36 ( V_38 , V_70 ) )
V_70 += V_26 ;
V_71 = V_38 -> V_79 ;
if ( F_37 ( V_38 , V_71 ) )
V_71 -= V_26 ;
F_38 ( V_2 , 25 + sizeof( void * ) * 6 - 1 ) ;
F_5 ( V_2 , L_13 ,
V_70 ,
V_71 ,
V_66 & V_80 ? 'r' : '-' ,
V_66 & V_81 ? 'w' : '-' ,
V_66 & V_82 ? 'x' : '-' ,
V_66 & V_83 ? 's' : 'p' ,
V_69 ,
F_39 ( V_72 ) , F_40 ( V_72 ) , V_68 ) ;
if ( V_57 ) {
F_41 ( V_2 , ' ' ) ;
F_42 ( V_2 , & V_57 -> V_84 , L_14 ) ;
goto V_85;
}
V_73 = F_43 ( V_38 ) ;
if ( ! V_73 ) {
T_4 V_86 ;
if ( ! V_4 ) {
V_73 = L_15 ;
goto V_85;
}
if ( V_38 -> V_78 <= V_4 -> V_87 &&
V_38 -> V_79 >= V_4 -> V_88 ) {
V_73 = L_16 ;
goto V_85;
}
V_86 = F_44 ( V_34 , V_38 , V_64 ) ;
if ( V_86 != 0 ) {
if ( ! V_64 || ( V_38 -> V_78 <= V_4 -> V_89 &&
V_38 -> V_79 >= V_4 -> V_89 ) ) {
V_73 = L_17 ;
} else {
F_41 ( V_2 , ' ' ) ;
F_5 ( V_2 , L_18 , V_86 ) ;
}
}
}
V_85:
if ( V_73 ) {
F_41 ( V_2 , ' ' ) ;
F_45 ( V_2 , V_73 ) ;
}
F_46 ( V_2 , '\n' ) ;
}
static int F_47 ( struct V_1 * V_2 , void * V_55 , int V_64 )
{
struct V_37 * V_38 = V_55 ;
struct V_31 * V_32 = V_2 -> V_43 ;
struct V_33 * V_34 = V_32 -> V_34 ;
F_34 ( V_2 , V_38 , V_64 ) ;
if ( V_2 -> V_90 < V_2 -> V_91 )
V_2 -> V_45 = ( V_38 != F_24 ( V_34 -> V_4 ) )
? V_38 -> V_78 : 0 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , void * V_55 )
{
return F_47 ( V_2 , V_55 , 1 ) ;
}
static int F_49 ( struct V_1 * V_2 , void * V_55 )
{
return F_47 ( V_2 , V_55 , 0 ) ;
}
static int F_50 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_29 ( V_56 , V_57 , & V_92 ) ;
}
static int F_51 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_29 ( V_56 , V_57 , & V_93 ) ;
}
static void F_52 ( V_24 V_94 , unsigned long V_95 ,
unsigned long V_96 , struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_43 ;
struct V_37 * V_38 = V_100 -> V_38 ;
T_5 V_69 = F_53 ( V_38 , V_95 ) ;
struct V_101 * V_101 = NULL ;
int V_102 ;
if ( F_54 ( V_94 ) ) {
V_101 = F_55 ( V_38 , V_95 , V_94 ) ;
} else if ( F_56 ( V_94 ) ) {
T_6 V_103 = F_57 ( V_94 ) ;
if ( ! F_58 ( V_103 ) )
V_100 -> V_8 += V_96 ;
else if ( F_59 ( V_103 ) )
V_101 = F_60 ( V_103 ) ;
} else if ( F_61 ( V_94 ) ) {
if ( F_62 ( V_94 ) != V_69 )
V_100 -> V_104 += V_96 ;
}
if ( ! V_101 )
return;
if ( F_63 ( V_101 ) )
V_100 -> V_105 += V_96 ;
if ( V_101 -> V_106 != V_69 )
V_100 -> V_104 += V_96 ;
V_100 -> V_28 += V_96 ;
if ( F_64 ( V_94 ) || F_65 ( V_101 ) )
V_100 -> V_107 += V_96 ;
V_102 = F_66 ( V_101 ) ;
if ( V_102 >= 2 ) {
if ( F_67 ( V_94 ) || F_68 ( V_101 ) )
V_100 -> V_108 += V_96 ;
else
V_100 -> V_109 += V_96 ;
V_100 -> V_110 += ( V_96 << V_111 ) / V_102 ;
} else {
if ( F_67 ( V_94 ) || F_68 ( V_101 ) )
V_100 -> V_112 += V_96 ;
else
V_100 -> V_113 += V_96 ;
V_100 -> V_110 += ( V_96 << V_111 ) ;
}
}
static int F_69 ( T_7 * V_114 , unsigned long V_95 , unsigned long V_71 ,
struct V_97 * V_98 )
{
struct V_99 * V_100 = V_98 -> V_43 ;
struct V_37 * V_38 = V_100 -> V_38 ;
V_24 * V_115 ;
T_8 * V_116 ;
if ( F_70 ( V_114 , V_38 , & V_116 ) == 1 ) {
F_52 ( * ( V_24 * ) V_114 , V_95 , V_117 , V_98 ) ;
F_71 ( V_116 ) ;
V_100 -> V_118 += V_117 ;
return 0 ;
}
if ( F_72 ( V_114 ) )
return 0 ;
V_115 = F_73 ( V_38 -> V_40 , V_114 , V_95 , & V_116 ) ;
for (; V_95 != V_71 ; V_115 ++ , V_95 += V_26 )
F_52 ( * V_115 , V_95 , V_26 , V_98 ) ;
F_74 ( V_115 - 1 , V_116 ) ;
F_75 () ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
static const char V_119 [ V_120 ] [ 2 ] = {
[ 0 ... ( V_120 - 1 ) ] = L_19 ,
[ F_77 ( V_80 ) ] = L_20 ,
[ F_77 ( V_81 ) ] = L_21 ,
[ F_77 ( V_82 ) ] = L_22 ,
[ F_77 ( V_121 ) ] = L_23 ,
[ F_77 ( V_122 ) ] = L_24 ,
[ F_77 ( V_123 ) ] = L_25 ,
[ F_77 ( V_124 ) ] = L_26 ,
[ F_77 ( V_83 ) ] = L_27 ,
[ F_77 ( V_125 ) ] = L_28 ,
[ F_77 ( V_126 ) ] = L_29 ,
[ F_77 ( V_127 ) ] = L_30 ,
[ F_77 ( V_128 ) ] = L_31 ,
[ F_77 ( V_129 ) ] = L_32 ,
[ F_77 ( V_130 ) ] = L_33 ,
[ F_77 ( V_131 ) ] = L_34 ,
[ F_77 ( V_132 ) ] = L_35 ,
[ F_77 ( V_133 ) ] = L_36 ,
[ F_77 ( V_134 ) ] = L_37 ,
[ F_77 ( V_135 ) ] = L_38 ,
[ F_77 ( V_136 ) ] = L_39 ,
[ F_77 ( V_137 ) ] = L_40 ,
[ F_77 ( V_138 ) ] = L_41 ,
[ F_77 ( V_139 ) ] = L_42 ,
#ifdef F_78
[ F_77 ( V_140 ) ] = L_43 ,
#endif
[ F_77 ( V_141 ) ] = L_44 ,
[ F_77 ( V_142 ) ] = L_45 ,
[ F_77 ( V_143 ) ] = L_46 ,
[ F_77 ( V_144 ) ] = L_47 ,
} ;
T_9 V_145 ;
F_45 ( V_2 , L_48 ) ;
for ( V_145 = 0 ; V_145 < V_120 ; V_145 ++ ) {
if ( V_38 -> V_67 & ( 1UL << V_145 ) ) {
F_5 ( V_2 , L_49 ,
V_119 [ V_145 ] [ 0 ] , V_119 [ V_145 ] [ 1 ] ) ;
}
}
F_46 ( V_2 , '\n' ) ;
}
static int F_79 ( struct V_1 * V_2 , void * V_55 , int V_64 )
{
struct V_31 * V_32 = V_2 -> V_43 ;
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_37 * V_38 = V_55 ;
struct V_99 V_100 ;
struct V_97 V_146 = {
. V_147 = F_69 ,
. V_4 = V_38 -> V_40 ,
. V_43 = & V_100 ,
} ;
memset ( & V_100 , 0 , sizeof V_100 ) ;
V_100 . V_38 = V_38 ;
if ( V_38 -> V_40 && ! F_80 ( V_38 ) )
F_81 ( V_38 -> V_78 , V_38 -> V_79 , & V_146 ) ;
F_34 ( V_2 , V_38 , V_64 ) ;
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
( V_38 -> V_79 - V_38 -> V_78 ) >> 10 ,
V_100 . V_28 >> 10 ,
( unsigned long ) ( V_100 . V_110 >> ( 10 + V_111 ) ) ,
V_100 . V_109 >> 10 ,
V_100 . V_108 >> 10 ,
V_100 . V_113 >> 10 ,
V_100 . V_112 >> 10 ,
V_100 . V_107 >> 10 ,
V_100 . V_105 >> 10 ,
V_100 . V_118 >> 10 ,
V_100 . V_8 >> 10 ,
F_82 ( V_38 ) >> 10 ,
F_83 ( V_38 ) >> 10 ,
( V_38 -> V_67 & V_128 ) ?
( unsigned long ) ( V_100 . V_110 >> ( 10 + V_111 ) ) : 0 ) ;
if ( V_38 -> V_67 & V_137 )
F_5 ( V_2 , L_64 ,
V_100 . V_104 >> 10 ) ;
F_76 ( V_2 , V_38 ) ;
if ( V_2 -> V_90 < V_2 -> V_91 )
V_2 -> V_45 = ( V_38 != F_24 ( V_34 -> V_4 ) )
? V_38 -> V_78 : 0 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , void * V_55 )
{
return F_79 ( V_2 , V_55 , 1 ) ;
}
static int F_85 ( struct V_1 * V_2 , void * V_55 )
{
return F_79 ( V_2 , V_55 , 0 ) ;
}
static int F_86 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_29 ( V_56 , V_57 , & V_148 ) ;
}
static int F_87 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_29 ( V_56 , V_57 , & V_149 ) ;
}
static inline void F_88 ( struct V_37 * V_38 ,
unsigned long V_95 , V_24 * V_115 )
{
#ifdef F_78
V_24 V_94 = * V_115 ;
if ( F_54 ( V_94 ) ) {
V_94 = F_89 ( V_94 ) ;
V_94 = F_90 ( V_94 , V_150 ) ;
} else if ( F_56 ( V_94 ) ) {
V_94 = F_91 ( V_94 ) ;
} else if ( F_61 ( V_94 ) ) {
V_94 = F_92 ( V_94 ) ;
}
if ( V_38 -> V_67 & V_140 )
V_38 -> V_67 &= ~ V_140 ;
F_93 ( V_38 -> V_40 , V_95 , V_115 , V_94 ) ;
#endif
}
static int F_94 ( T_7 * V_114 , unsigned long V_95 ,
unsigned long V_71 , struct V_97 * V_98 )
{
struct V_151 * V_152 = V_98 -> V_43 ;
struct V_37 * V_38 = V_152 -> V_38 ;
V_24 * V_115 , V_94 ;
T_8 * V_116 ;
struct V_101 * V_101 ;
F_95 ( V_38 , V_95 , V_114 ) ;
if ( F_72 ( V_114 ) )
return 0 ;
V_115 = F_73 ( V_38 -> V_40 , V_114 , V_95 , & V_116 ) ;
for (; V_95 != V_71 ; V_115 ++ , V_95 += V_26 ) {
V_94 = * V_115 ;
if ( V_152 -> type == V_153 ) {
F_88 ( V_38 , V_95 , V_115 ) ;
continue;
}
if ( ! F_54 ( V_94 ) )
continue;
V_101 = F_55 ( V_38 , V_95 , V_94 ) ;
if ( ! V_101 )
continue;
F_96 ( V_38 , V_95 , V_115 ) ;
F_97 ( V_101 ) ;
}
F_74 ( V_115 - 1 , V_116 ) ;
F_75 () ;
return 0 ;
}
static T_10 F_98 ( struct V_57 * V_57 , const char T_11 * V_154 ,
T_9 V_90 , T_1 * V_155 )
{
struct V_33 * V_34 ;
char V_156 [ V_157 ] ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
enum V_158 type ;
int V_159 ;
int V_160 ;
memset ( V_156 , 0 , sizeof( V_156 ) ) ;
if ( V_90 > sizeof( V_156 ) - 1 )
V_90 = sizeof( V_156 ) - 1 ;
if ( F_99 ( V_156 , V_154 , V_90 ) )
return - V_161 ;
V_160 = F_100 ( F_101 ( V_156 ) , 10 , & V_159 ) ;
if ( V_160 < 0 )
return V_160 ;
type = (enum V_158 ) V_159 ;
if ( type < V_162 || type >= V_163 )
return - V_164 ;
if ( type == V_153 ) {
V_165 = true ;
F_102 ( L_65
L_66 ) ;
}
V_34 = F_103 ( F_35 ( V_57 ) ) ;
if ( ! V_34 )
return - V_49 ;
V_4 = F_104 ( V_34 ) ;
if ( V_4 ) {
struct V_151 V_152 = {
. type = type ,
} ;
struct V_97 V_166 = {
. V_147 = F_94 ,
. V_4 = V_4 ,
. V_43 = & V_152 ,
} ;
F_23 ( & V_4 -> V_41 ) ;
if ( type == V_153 )
F_105 ( V_4 , 0 , - 1 ) ;
for ( V_38 = V_4 -> V_54 ; V_38 ; V_38 = V_38 -> V_51 ) {
V_152 . V_38 = V_38 ;
if ( F_80 ( V_38 ) )
continue;
if ( type == V_167 && V_38 -> V_65 )
continue;
if ( type == V_168 && ! V_38 -> V_65 )
continue;
F_81 ( V_38 -> V_78 , V_38 -> V_79 ,
& V_166 ) ;
}
if ( type == V_153 )
F_106 ( V_4 , 0 , - 1 ) ;
F_107 ( V_4 ) ;
F_16 ( & V_4 -> V_41 ) ;
F_17 ( V_4 ) ;
}
F_28 ( V_34 ) ;
return V_90 ;
}
static inline T_12 F_108 ( T_13 V_169 )
{
return ( T_12 ) { . V_170 = V_169 } ;
}
static int F_109 ( unsigned long V_95 , T_12 * V_170 ,
struct V_171 * V_172 )
{
V_172 -> V_156 [ V_172 -> V_42 ++ ] = * V_170 ;
if ( V_172 -> V_42 >= V_172 -> V_173 )
return V_174 ;
return 0 ;
}
static int F_110 ( unsigned long V_70 , unsigned long V_71 ,
struct V_97 * V_98 )
{
struct V_171 * V_172 = V_98 -> V_43 ;
unsigned long V_95 ;
int V_175 = 0 ;
T_12 V_170 = F_108 ( F_111 ( V_172 -> V_176 ) ) ;
for ( V_95 = V_70 ; V_95 < V_71 ; V_95 += V_26 ) {
V_175 = F_109 ( V_95 , & V_170 , V_172 ) ;
if ( V_175 )
break;
}
return V_175 ;
}
static void F_112 ( T_12 * V_170 , struct V_171 * V_172 ,
struct V_37 * V_38 , unsigned long V_95 , V_24 V_115 )
{
T_13 V_177 , V_66 ;
struct V_101 * V_101 = NULL ;
int V_178 = 0 ;
if ( F_54 ( V_115 ) ) {
V_177 = F_113 ( V_115 ) ;
V_66 = V_179 ;
V_101 = F_55 ( V_38 , V_95 , V_115 ) ;
if ( F_114 ( V_115 ) )
V_178 |= V_180 ;
} else if ( F_56 ( V_115 ) ) {
T_6 V_181 ;
if ( F_115 ( V_115 ) )
V_178 |= V_180 ;
V_181 = F_57 ( V_115 ) ;
V_177 = F_116 ( V_181 ) |
( F_117 ( V_181 ) << V_182 ) ;
V_66 = V_183 ;
if ( F_59 ( V_181 ) )
V_101 = F_60 ( V_181 ) ;
} else {
if ( V_38 -> V_67 & V_140 )
V_178 |= V_180 ;
* V_170 = F_108 ( F_111 ( V_172 -> V_176 ) | F_118 ( V_172 -> V_176 , V_178 ) ) ;
return;
}
if ( V_101 && ! F_63 ( V_101 ) )
V_66 |= V_184 ;
if ( ( V_38 -> V_67 & V_140 ) )
V_178 |= V_180 ;
* V_170 = F_108 ( F_119 ( V_177 ) | F_118 ( V_172 -> V_176 , V_178 ) | V_66 ) ;
}
static void F_120 ( T_12 * V_170 , struct V_171 * V_172 ,
T_7 V_114 , int V_185 , int V_186 )
{
if ( F_121 ( V_114 ) )
* V_170 = F_108 ( F_119 ( F_122 ( V_114 ) + V_185 )
| F_118 ( V_172 -> V_176 , V_186 ) | V_179 ) ;
else
* V_170 = F_108 ( F_111 ( V_172 -> V_176 ) | F_118 ( V_172 -> V_176 , V_186 ) ) ;
}
static inline void F_120 ( T_12 * V_170 , struct V_171 * V_172 ,
T_7 V_114 , int V_185 , int V_186 )
{
}
static int F_123 ( T_7 * V_114 , unsigned long V_95 , unsigned long V_71 ,
struct V_97 * V_98 )
{
struct V_37 * V_38 ;
struct V_171 * V_172 = V_98 -> V_43 ;
T_8 * V_116 ;
V_24 * V_115 ;
int V_175 = 0 ;
T_12 V_170 = F_108 ( F_111 ( V_172 -> V_176 ) ) ;
V_38 = F_25 ( V_98 -> V_4 , V_95 ) ;
if ( V_38 && F_70 ( V_114 , V_38 , & V_116 ) == 1 ) {
int V_186 ;
if ( ( V_38 -> V_67 & V_140 ) || F_124 ( * V_114 ) )
V_186 = V_180 ;
else
V_186 = 0 ;
for (; V_95 != V_71 ; V_95 += V_26 ) {
unsigned long V_185 ;
V_185 = ( V_95 & ~ V_187 ) >>
V_19 ;
F_120 ( & V_170 , V_172 , * V_114 , V_185 , V_186 ) ;
V_175 = F_109 ( V_95 , & V_170 , V_172 ) ;
if ( V_175 )
break;
}
F_71 ( V_116 ) ;
return V_175 ;
}
if ( F_72 ( V_114 ) )
return 0 ;
for (; V_95 != V_71 ; V_95 += V_26 ) {
int V_178 ;
if ( V_38 && ( V_95 >= V_38 -> V_79 ) ) {
V_38 = F_25 ( V_98 -> V_4 , V_95 ) ;
if ( V_38 && ( V_38 -> V_67 & V_140 ) )
V_178 = V_180 ;
else
V_178 = 0 ;
V_170 = F_108 ( F_111 ( V_172 -> V_176 ) | F_118 ( V_172 -> V_176 , V_178 ) ) ;
}
if ( V_38 && ( V_38 -> V_78 <= V_95 ) &&
! F_80 ( V_38 ) ) {
V_115 = F_125 ( V_114 , V_95 ) ;
F_112 ( & V_170 , V_172 , V_38 , V_95 , * V_115 ) ;
F_126 ( V_115 ) ;
}
V_175 = F_109 ( V_95 , & V_170 , V_172 ) ;
if ( V_175 )
return V_175 ;
}
F_75 () ;
return V_175 ;
}
static void F_127 ( T_12 * V_170 , struct V_171 * V_172 ,
V_24 V_115 , int V_185 , int V_178 )
{
if ( F_54 ( V_115 ) )
* V_170 = F_108 ( F_119 ( F_113 ( V_115 ) + V_185 ) |
F_118 ( V_172 -> V_176 , V_178 ) |
V_179 ) ;
else
* V_170 = F_108 ( F_111 ( V_172 -> V_176 ) |
F_118 ( V_172 -> V_176 , V_178 ) ) ;
}
static int F_128 ( V_24 * V_115 , unsigned long V_188 ,
unsigned long V_95 , unsigned long V_71 ,
struct V_97 * V_98 )
{
struct V_171 * V_172 = V_98 -> V_43 ;
struct V_37 * V_38 ;
int V_175 = 0 ;
int V_178 ;
T_12 V_170 ;
V_38 = F_25 ( V_98 -> V_4 , V_95 ) ;
F_129 ( ! V_38 ) ;
if ( V_38 && ( V_38 -> V_67 & V_140 ) )
V_178 = V_180 ;
else
V_178 = 0 ;
for (; V_95 != V_71 ; V_95 += V_26 ) {
int V_185 = ( V_95 & ~ V_188 ) >> V_19 ;
F_127 ( & V_170 , V_172 , * V_115 , V_185 , V_178 ) ;
V_175 = F_109 ( V_95 , & V_170 , V_172 ) ;
if ( V_175 )
return V_175 ;
}
F_75 () ;
return V_175 ;
}
static T_10 F_130 ( struct V_57 * V_57 , char T_11 * V_154 ,
T_9 V_90 , T_1 * V_155 )
{
struct V_33 * V_34 = F_103 ( F_35 ( V_57 ) ) ;
struct V_3 * V_4 ;
struct V_171 V_172 ;
int V_60 = - V_49 ;
struct V_97 V_189 = {} ;
unsigned long V_190 ;
unsigned long V_191 ;
unsigned long V_192 ;
unsigned long V_193 ;
int V_194 = 0 ;
if ( ! V_34 )
goto V_52;
V_60 = - V_164 ;
if ( ( * V_155 % V_195 ) || ( V_90 % V_195 ) )
goto V_196;
V_60 = 0 ;
if ( ! V_90 )
goto V_196;
V_172 . V_176 = V_165 ;
V_172 . V_173 = ( V_197 >> V_19 ) ;
V_172 . V_156 = F_131 ( V_172 . V_173 * V_195 , V_198 ) ;
V_60 = - V_61 ;
if ( ! V_172 . V_156 )
goto V_196;
V_4 = F_21 ( V_34 , V_50 ) ;
V_60 = F_132 ( V_4 ) ;
if ( ! V_4 || F_22 ( V_4 ) )
goto V_199;
V_189 . V_147 = F_123 ;
V_189 . V_200 = F_110 ;
#ifdef F_133
V_189 . V_201 = F_128 ;
#endif
V_189 . V_4 = V_4 ;
V_189 . V_43 = & V_172 ;
V_190 = * V_155 ;
V_191 = V_190 / V_195 ;
V_192 = V_191 << V_19 ;
V_193 = F_134 ( V_34 ) ;
if ( V_191 > F_134 ( V_34 ) >> V_19 )
V_192 = V_193 ;
V_60 = 0 ;
while ( V_90 && ( V_192 < V_193 ) ) {
int V_173 ;
unsigned long V_71 ;
V_172 . V_42 = 0 ;
V_71 = ( V_192 + V_197 ) & V_187 ;
if ( V_71 < V_192 || V_71 > V_193 )
V_71 = V_193 ;
F_23 ( & V_4 -> V_41 ) ;
V_60 = F_81 ( V_192 , V_71 , & V_189 ) ;
F_16 ( & V_4 -> V_41 ) ;
V_192 = V_71 ;
V_173 = F_135 ( V_90 , V_195 * V_172 . V_42 ) ;
if ( F_136 ( V_154 , V_172 . V_156 , V_173 ) ) {
V_60 = - V_161 ;
goto V_202;
}
V_194 += V_173 ;
V_154 += V_173 ;
V_90 -= V_173 ;
}
* V_155 += V_194 ;
if ( ! V_60 || V_60 == V_174 )
V_60 = V_194 ;
V_202:
F_17 ( V_4 ) ;
V_199:
F_33 ( V_172 . V_156 ) ;
V_196:
F_28 ( V_34 ) ;
V_52:
return V_60 ;
}
static int F_137 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
F_102 ( L_67
L_68
L_69 ) ;
return 0 ;
}
static void F_138 ( struct V_101 * V_101 , struct V_203 * V_204 , int F_67 ,
unsigned long V_205 )
{
int V_90 = F_66 ( V_101 ) ;
V_204 -> V_206 += V_205 ;
if ( F_67 || F_68 ( V_101 ) )
V_204 -> V_207 += V_205 ;
if ( F_139 ( V_101 ) )
V_204 -> V_208 += V_205 ;
if ( F_140 ( V_101 ) || F_141 ( V_101 ) )
V_204 -> V_209 += V_205 ;
if ( F_142 ( V_101 ) )
V_204 -> V_210 += V_205 ;
if ( F_63 ( V_101 ) )
V_204 -> V_211 += V_205 ;
if ( V_90 > V_204 -> V_212 )
V_204 -> V_212 = V_90 ;
V_204 -> V_213 [ F_143 ( V_101 ) ] += V_205 ;
}
static struct V_101 * F_144 ( V_24 V_115 , struct V_37 * V_38 ,
unsigned long V_95 )
{
struct V_101 * V_101 ;
int V_214 ;
if ( ! F_54 ( V_115 ) )
return NULL ;
V_101 = F_55 ( V_38 , V_95 , V_115 ) ;
if ( ! V_101 )
return NULL ;
if ( F_145 ( V_101 ) )
return NULL ;
V_214 = F_143 ( V_101 ) ;
if ( ! F_146 ( V_214 , V_215 [ V_216 ] ) )
return NULL ;
return V_101 ;
}
static int F_147 ( T_7 * V_114 , unsigned long V_95 ,
unsigned long V_71 , struct V_97 * V_98 )
{
struct V_203 * V_204 ;
T_8 * V_116 ;
V_24 * V_217 ;
V_24 * V_115 ;
V_204 = V_98 -> V_43 ;
if ( F_70 ( V_114 , V_204 -> V_38 , & V_116 ) == 1 ) {
V_24 V_218 = * ( V_24 * ) V_114 ;
struct V_101 * V_101 ;
V_101 = F_144 ( V_218 , V_204 -> V_38 , V_95 ) ;
if ( V_101 )
F_138 ( V_101 , V_204 , F_67 ( V_218 ) ,
V_117 / V_26 ) ;
F_71 ( V_116 ) ;
return 0 ;
}
if ( F_72 ( V_114 ) )
return 0 ;
V_217 = V_115 = F_73 ( V_98 -> V_4 , V_114 , V_95 , & V_116 ) ;
do {
struct V_101 * V_101 = F_144 ( * V_115 , V_204 -> V_38 , V_95 ) ;
if ( ! V_101 )
continue;
F_138 ( V_101 , V_204 , F_67 ( * V_115 ) , 1 ) ;
} while ( V_115 ++ , V_95 += V_26 , V_95 != V_71 );
F_74 ( V_217 , V_116 ) ;
return 0 ;
}
static int F_148 ( V_24 * V_115 , unsigned long V_188 ,
unsigned long V_95 , unsigned long V_71 , struct V_97 * V_98 )
{
struct V_203 * V_204 ;
struct V_101 * V_101 ;
if ( F_149 ( * V_115 ) )
return 0 ;
V_101 = F_150 ( * V_115 ) ;
if ( ! V_101 )
return 0 ;
V_204 = V_98 -> V_43 ;
F_138 ( V_101 , V_204 , F_67 ( * V_115 ) , 1 ) ;
return 0 ;
}
static int F_148 ( V_24 * V_115 , unsigned long V_188 ,
unsigned long V_95 , unsigned long V_71 , struct V_97 * V_98 )
{
return 0 ;
}
static int F_151 ( struct V_1 * V_2 , void * V_55 , int V_64 )
{
struct V_219 * V_220 = V_2 -> V_43 ;
struct V_31 * V_221 = & V_220 -> V_222 ;
struct V_37 * V_38 = V_55 ;
struct V_203 * V_204 = & V_220 -> V_204 ;
struct V_57 * V_57 = V_38 -> V_65 ;
struct V_33 * V_34 = V_221 -> V_34 ;
struct V_3 * V_4 = V_38 -> V_40 ;
struct V_97 V_98 = {} ;
struct V_36 * V_223 ;
char V_156 [ 64 ] ;
int V_214 ;
if ( ! V_4 )
return 0 ;
memset ( V_204 , 0 , sizeof( * V_204 ) ) ;
V_204 -> V_38 = V_38 ;
V_98 . V_201 = F_148 ;
V_98 . V_147 = F_147 ;
V_98 . V_43 = V_204 ;
V_98 . V_4 = V_4 ;
V_223 = F_152 ( V_34 , V_38 , V_38 -> V_78 ) ;
F_153 ( V_156 , sizeof( V_156 ) , V_223 ) ;
F_154 ( V_223 ) ;
F_5 ( V_2 , L_70 , V_38 -> V_78 , V_156 ) ;
if ( V_57 ) {
F_5 ( V_2 , L_71 ) ;
F_42 ( V_2 , & V_57 -> V_84 , L_72 ) ;
} else if ( V_38 -> V_78 <= V_4 -> V_87 && V_38 -> V_79 >= V_4 -> V_88 ) {
F_5 ( V_2 , L_73 ) ;
} else {
T_4 V_86 = F_44 ( V_34 , V_38 , V_64 ) ;
if ( V_86 != 0 ) {
if ( ! V_64 || ( V_38 -> V_78 <= V_4 -> V_89 &&
V_38 -> V_79 >= V_4 -> V_89 ) )
F_5 ( V_2 , L_74 ) ;
else
F_5 ( V_2 , L_75 , V_86 ) ;
}
}
if ( F_80 ( V_38 ) )
F_5 ( V_2 , L_76 ) ;
F_81 ( V_38 -> V_78 , V_38 -> V_79 , & V_98 ) ;
if ( ! V_204 -> V_206 )
goto V_52;
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
if ( V_204 -> V_209 < V_204 -> V_206 && ! F_80 ( V_38 ) )
F_5 ( V_2 , L_82 , V_204 -> V_209 ) ;
if ( V_204 -> V_210 )
F_5 ( V_2 , L_83 , V_204 -> V_210 ) ;
F_155 (nid, N_MEMORY)
if ( V_204 -> V_213 [ V_214 ] )
F_5 ( V_2 , L_84 , V_214 , V_204 -> V_213 [ V_214 ] ) ;
V_52:
F_46 ( V_2 , '\n' ) ;
if ( V_2 -> V_90 < V_2 -> V_91 )
V_2 -> V_45 = ( V_38 != V_221 -> V_39 ) ? V_38 -> V_78 : 0 ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 , void * V_55 )
{
return F_151 ( V_2 , V_55 , 1 ) ;
}
static int F_157 ( struct V_1 * V_2 , void * V_55 )
{
return F_151 ( V_2 , V_55 , 0 ) ;
}
static int F_158 ( struct V_56 * V_56 , struct V_57 * V_57 ,
const struct V_58 * V_59 )
{
struct V_219 * V_32 ;
int V_60 = - V_61 ;
V_32 = F_30 ( sizeof( * V_32 ) , V_62 ) ;
if ( V_32 ) {
V_32 -> V_222 . V_47 = F_31 ( V_56 ) ;
V_60 = F_32 ( V_57 , V_59 ) ;
if ( ! V_60 ) {
struct V_1 * V_2 = V_57 -> V_63 ;
V_2 -> V_43 = V_32 ;
} else {
F_33 ( V_32 ) ;
}
}
return V_60 ;
}
static int F_159 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_158 ( V_56 , V_57 , & V_224 ) ;
}
static int F_160 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_158 ( V_56 , V_57 , & V_225 ) ;
}
