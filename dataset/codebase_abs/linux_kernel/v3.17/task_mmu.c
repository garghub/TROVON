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
if ( V_38 -> V_86 && V_38 -> V_86 -> V_73 ) {
V_73 = V_38 -> V_86 -> V_73 ( V_38 ) ;
if ( V_73 )
goto V_85;
}
V_73 = F_43 ( V_38 ) ;
if ( ! V_73 ) {
T_4 V_87 ;
if ( ! V_4 ) {
V_73 = L_15 ;
goto V_85;
}
if ( V_38 -> V_78 <= V_4 -> V_88 &&
V_38 -> V_79 >= V_4 -> V_89 ) {
V_73 = L_16 ;
goto V_85;
}
V_87 = F_44 ( V_34 , V_38 , V_64 ) ;
if ( V_87 != 0 ) {
if ( ! V_64 || ( V_38 -> V_78 <= V_4 -> V_90 &&
V_38 -> V_79 >= V_4 -> V_90 ) ) {
V_73 = L_17 ;
} else {
F_41 ( V_2 , ' ' ) ;
F_5 ( V_2 , L_18 , V_87 ) ;
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
if ( V_2 -> V_91 < V_2 -> V_92 )
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
return F_29 ( V_56 , V_57 , & V_93 ) ;
}
static int F_51 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_29 ( V_56 , V_57 , & V_94 ) ;
}
static void F_52 ( V_24 V_95 , unsigned long V_96 ,
unsigned long V_97 , struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_43 ;
struct V_37 * V_38 = V_101 -> V_38 ;
T_5 V_69 = F_53 ( V_38 , V_96 ) ;
struct V_102 * V_102 = NULL ;
int V_103 ;
if ( F_54 ( V_95 ) ) {
V_102 = F_55 ( V_38 , V_96 , V_95 ) ;
} else if ( F_56 ( V_95 ) ) {
T_6 V_104 = F_57 ( V_95 ) ;
if ( ! F_58 ( V_104 ) )
V_101 -> V_8 += V_97 ;
else if ( F_59 ( V_104 ) )
V_102 = F_60 ( V_104 ) ;
} else if ( F_61 ( V_95 ) ) {
if ( F_62 ( V_95 ) != V_69 )
V_101 -> V_105 += V_97 ;
}
if ( ! V_102 )
return;
if ( F_63 ( V_102 ) )
V_101 -> V_106 += V_97 ;
if ( V_102 -> V_107 != V_69 )
V_101 -> V_105 += V_97 ;
V_101 -> V_28 += V_97 ;
if ( F_64 ( V_95 ) || F_65 ( V_102 ) )
V_101 -> V_108 += V_97 ;
V_103 = F_66 ( V_102 ) ;
if ( V_103 >= 2 ) {
if ( F_67 ( V_95 ) || F_68 ( V_102 ) )
V_101 -> V_109 += V_97 ;
else
V_101 -> V_110 += V_97 ;
V_101 -> V_111 += ( V_97 << V_112 ) / V_103 ;
} else {
if ( F_67 ( V_95 ) || F_68 ( V_102 ) )
V_101 -> V_113 += V_97 ;
else
V_101 -> V_114 += V_97 ;
V_101 -> V_111 += ( V_97 << V_112 ) ;
}
}
static int F_69 ( T_7 * V_115 , unsigned long V_96 , unsigned long V_71 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_43 ;
struct V_37 * V_38 = V_101 -> V_38 ;
V_24 * V_116 ;
T_8 * V_117 ;
if ( F_70 ( V_115 , V_38 , & V_117 ) == 1 ) {
F_52 ( * ( V_24 * ) V_115 , V_96 , V_118 , V_99 ) ;
F_71 ( V_117 ) ;
V_101 -> V_119 += V_118 ;
return 0 ;
}
if ( F_72 ( V_115 ) )
return 0 ;
V_116 = F_73 ( V_38 -> V_40 , V_115 , V_96 , & V_117 ) ;
for (; V_96 != V_71 ; V_116 ++ , V_96 += V_26 )
F_52 ( * V_116 , V_96 , V_26 , V_99 ) ;
F_74 ( V_116 - 1 , V_117 ) ;
F_75 () ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
static const char V_120 [ V_121 ] [ 2 ] = {
[ 0 ... ( V_121 - 1 ) ] = L_19 ,
[ F_77 ( V_80 ) ] = L_20 ,
[ F_77 ( V_81 ) ] = L_21 ,
[ F_77 ( V_82 ) ] = L_22 ,
[ F_77 ( V_122 ) ] = L_23 ,
[ F_77 ( V_123 ) ] = L_24 ,
[ F_77 ( V_124 ) ] = L_25 ,
[ F_77 ( V_125 ) ] = L_26 ,
[ F_77 ( V_83 ) ] = L_27 ,
[ F_77 ( V_126 ) ] = L_28 ,
[ F_77 ( V_127 ) ] = L_29 ,
[ F_77 ( V_128 ) ] = L_30 ,
[ F_77 ( V_129 ) ] = L_31 ,
[ F_77 ( V_130 ) ] = L_32 ,
[ F_77 ( V_131 ) ] = L_33 ,
[ F_77 ( V_132 ) ] = L_34 ,
[ F_77 ( V_133 ) ] = L_35 ,
[ F_77 ( V_134 ) ] = L_36 ,
[ F_77 ( V_135 ) ] = L_37 ,
[ F_77 ( V_136 ) ] = L_38 ,
[ F_77 ( V_137 ) ] = L_39 ,
[ F_77 ( V_138 ) ] = L_40 ,
[ F_77 ( V_139 ) ] = L_41 ,
[ F_77 ( V_140 ) ] = L_42 ,
#ifdef F_78
[ F_77 ( V_141 ) ] = L_43 ,
#endif
[ F_77 ( V_142 ) ] = L_44 ,
[ F_77 ( V_143 ) ] = L_45 ,
[ F_77 ( V_144 ) ] = L_46 ,
[ F_77 ( V_145 ) ] = L_47 ,
} ;
T_9 V_146 ;
F_45 ( V_2 , L_48 ) ;
for ( V_146 = 0 ; V_146 < V_121 ; V_146 ++ ) {
if ( V_38 -> V_67 & ( 1UL << V_146 ) ) {
F_5 ( V_2 , L_49 ,
V_120 [ V_146 ] [ 0 ] , V_120 [ V_146 ] [ 1 ] ) ;
}
}
F_46 ( V_2 , '\n' ) ;
}
static int F_79 ( struct V_1 * V_2 , void * V_55 , int V_64 )
{
struct V_31 * V_32 = V_2 -> V_43 ;
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_37 * V_38 = V_55 ;
struct V_100 V_101 ;
struct V_98 V_147 = {
. V_148 = F_69 ,
. V_4 = V_38 -> V_40 ,
. V_43 = & V_101 ,
} ;
memset ( & V_101 , 0 , sizeof V_101 ) ;
V_101 . V_38 = V_38 ;
if ( V_38 -> V_40 && ! F_80 ( V_38 ) )
F_81 ( V_38 -> V_78 , V_38 -> V_79 , & V_147 ) ;
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
V_101 . V_28 >> 10 ,
( unsigned long ) ( V_101 . V_111 >> ( 10 + V_112 ) ) ,
V_101 . V_110 >> 10 ,
V_101 . V_109 >> 10 ,
V_101 . V_114 >> 10 ,
V_101 . V_113 >> 10 ,
V_101 . V_108 >> 10 ,
V_101 . V_106 >> 10 ,
V_101 . V_119 >> 10 ,
V_101 . V_8 >> 10 ,
F_82 ( V_38 ) >> 10 ,
F_83 ( V_38 ) >> 10 ,
( V_38 -> V_67 & V_129 ) ?
( unsigned long ) ( V_101 . V_111 >> ( 10 + V_112 ) ) : 0 ) ;
if ( V_38 -> V_67 & V_138 )
F_5 ( V_2 , L_64 ,
V_101 . V_105 >> 10 ) ;
F_76 ( V_2 , V_38 ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
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
return F_29 ( V_56 , V_57 , & V_149 ) ;
}
static int F_87 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_29 ( V_56 , V_57 , & V_150 ) ;
}
static inline void F_88 ( struct V_37 * V_38 ,
unsigned long V_96 , V_24 * V_116 )
{
#ifdef F_78
V_24 V_95 = * V_116 ;
if ( F_54 ( V_95 ) ) {
V_95 = F_89 ( V_95 ) ;
V_95 = F_90 ( V_95 , V_151 ) ;
} else if ( F_56 ( V_95 ) ) {
V_95 = F_91 ( V_95 ) ;
} else if ( F_61 ( V_95 ) ) {
V_95 = F_92 ( V_95 ) ;
}
F_93 ( V_38 -> V_40 , V_96 , V_116 , V_95 ) ;
#endif
}
static int F_94 ( T_7 * V_115 , unsigned long V_96 ,
unsigned long V_71 , struct V_98 * V_99 )
{
struct V_152 * V_153 = V_99 -> V_43 ;
struct V_37 * V_38 = V_153 -> V_38 ;
V_24 * V_116 , V_95 ;
T_8 * V_117 ;
struct V_102 * V_102 ;
F_95 ( V_38 , V_96 , V_115 ) ;
if ( F_72 ( V_115 ) )
return 0 ;
V_116 = F_73 ( V_38 -> V_40 , V_115 , V_96 , & V_117 ) ;
for (; V_96 != V_71 ; V_116 ++ , V_96 += V_26 ) {
V_95 = * V_116 ;
if ( V_153 -> type == V_154 ) {
F_88 ( V_38 , V_96 , V_116 ) ;
continue;
}
if ( ! F_54 ( V_95 ) )
continue;
V_102 = F_55 ( V_38 , V_96 , V_95 ) ;
if ( ! V_102 )
continue;
F_96 ( V_38 , V_96 , V_116 ) ;
F_97 ( V_102 ) ;
}
F_74 ( V_116 - 1 , V_117 ) ;
F_75 () ;
return 0 ;
}
static T_10 F_98 ( struct V_57 * V_57 , const char T_11 * V_155 ,
T_9 V_91 , T_1 * V_156 )
{
struct V_33 * V_34 ;
char V_157 [ V_158 ] ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
enum V_159 type ;
int V_160 ;
int V_161 ;
memset ( V_157 , 0 , sizeof( V_157 ) ) ;
if ( V_91 > sizeof( V_157 ) - 1 )
V_91 = sizeof( V_157 ) - 1 ;
if ( F_99 ( V_157 , V_155 , V_91 ) )
return - V_162 ;
V_161 = F_100 ( F_101 ( V_157 ) , 10 , & V_160 ) ;
if ( V_161 < 0 )
return V_161 ;
type = (enum V_159 ) V_160 ;
if ( type < V_163 || type >= V_164 )
return - V_165 ;
if ( type == V_154 ) {
V_166 = true ;
F_102 ( L_65
L_66
L_67 ) ;
}
V_34 = F_103 ( F_35 ( V_57 ) ) ;
if ( ! V_34 )
return - V_49 ;
V_4 = F_104 ( V_34 ) ;
if ( V_4 ) {
struct V_152 V_153 = {
. type = type ,
} ;
struct V_98 V_167 = {
. V_148 = F_94 ,
. V_4 = V_4 ,
. V_43 = & V_153 ,
} ;
F_23 ( & V_4 -> V_41 ) ;
if ( type == V_154 )
F_105 ( V_4 , 0 , - 1 ) ;
for ( V_38 = V_4 -> V_54 ; V_38 ; V_38 = V_38 -> V_51 ) {
V_153 . V_38 = V_38 ;
if ( F_80 ( V_38 ) )
continue;
if ( type == V_168 && V_38 -> V_65 )
continue;
if ( type == V_169 && ! V_38 -> V_65 )
continue;
if ( type == V_154 ) {
if ( V_38 -> V_67 & V_141 )
V_38 -> V_67 &= ~ V_141 ;
}
F_81 ( V_38 -> V_78 , V_38 -> V_79 ,
& V_167 ) ;
}
if ( type == V_154 )
F_106 ( V_4 , 0 , - 1 ) ;
F_107 ( V_4 ) ;
F_16 ( & V_4 -> V_41 ) ;
F_17 ( V_4 ) ;
}
F_28 ( V_34 ) ;
return V_91 ;
}
static inline T_12 F_108 ( T_13 V_170 )
{
return ( T_12 ) { . V_171 = V_170 } ;
}
static int F_109 ( unsigned long V_96 , T_12 * V_171 ,
struct V_172 * V_173 )
{
V_173 -> V_157 [ V_173 -> V_42 ++ ] = * V_171 ;
if ( V_173 -> V_42 >= V_173 -> V_174 )
return V_175 ;
return 0 ;
}
static int F_110 ( unsigned long V_70 , unsigned long V_71 ,
struct V_98 * V_99 )
{
struct V_172 * V_173 = V_99 -> V_43 ;
unsigned long V_96 = V_70 ;
int V_176 = 0 ;
while ( V_96 < V_71 ) {
struct V_37 * V_38 = F_25 ( V_99 -> V_4 , V_96 ) ;
T_12 V_171 = F_108 ( F_111 ( V_173 -> V_177 ) ) ;
unsigned long V_178 ;
if ( V_38 )
V_178 = F_112 ( V_71 , V_38 -> V_78 ) ;
else
V_178 = V_71 ;
for (; V_96 < V_178 ; V_96 += V_26 ) {
V_176 = F_109 ( V_96 , & V_171 , V_173 ) ;
if ( V_176 )
goto V_52;
}
if ( ! V_38 )
break;
if ( V_38 -> V_67 & V_141 )
V_171 . V_171 |= F_113 ( V_173 -> V_177 , V_179 ) ;
for (; V_96 < F_112 ( V_71 , V_38 -> V_79 ) ; V_96 += V_26 ) {
V_176 = F_109 ( V_96 , & V_171 , V_173 ) ;
if ( V_176 )
goto V_52;
}
}
V_52:
return V_176 ;
}
static void F_114 ( T_12 * V_171 , struct V_172 * V_173 ,
struct V_37 * V_38 , unsigned long V_96 , V_24 V_116 )
{
T_13 V_180 , V_66 ;
struct V_102 * V_102 = NULL ;
int V_181 = 0 ;
if ( F_54 ( V_116 ) ) {
V_180 = F_115 ( V_116 ) ;
V_66 = V_182 ;
V_102 = F_55 ( V_38 , V_96 , V_116 ) ;
if ( F_116 ( V_116 ) )
V_181 |= V_179 ;
} else if ( F_56 ( V_116 ) ) {
T_6 V_183 ;
if ( F_117 ( V_116 ) )
V_181 |= V_179 ;
V_183 = F_57 ( V_116 ) ;
V_180 = F_118 ( V_183 ) |
( F_119 ( V_183 ) << V_184 ) ;
V_66 = V_185 ;
if ( F_59 ( V_183 ) )
V_102 = F_60 ( V_183 ) ;
} else {
if ( V_38 -> V_67 & V_141 )
V_181 |= V_179 ;
* V_171 = F_108 ( F_111 ( V_173 -> V_177 ) | F_113 ( V_173 -> V_177 , V_181 ) ) ;
return;
}
if ( V_102 && ! F_63 ( V_102 ) )
V_66 |= V_186 ;
if ( ( V_38 -> V_67 & V_141 ) )
V_181 |= V_179 ;
* V_171 = F_108 ( F_120 ( V_180 ) | F_113 ( V_173 -> V_177 , V_181 ) | V_66 ) ;
}
static void F_121 ( T_12 * V_171 , struct V_172 * V_173 ,
T_7 V_115 , int V_187 , int V_188 )
{
if ( F_122 ( V_115 ) )
* V_171 = F_108 ( F_120 ( F_123 ( V_115 ) + V_187 )
| F_113 ( V_173 -> V_177 , V_188 ) | V_182 ) ;
else
* V_171 = F_108 ( F_111 ( V_173 -> V_177 ) | F_113 ( V_173 -> V_177 , V_188 ) ) ;
}
static inline void F_121 ( T_12 * V_171 , struct V_172 * V_173 ,
T_7 V_115 , int V_187 , int V_188 )
{
}
static int F_124 ( T_7 * V_115 , unsigned long V_96 , unsigned long V_71 ,
struct V_98 * V_99 )
{
struct V_37 * V_38 ;
struct V_172 * V_173 = V_99 -> V_43 ;
T_8 * V_117 ;
V_24 * V_116 ;
int V_176 = 0 ;
T_12 V_171 = F_108 ( F_111 ( V_173 -> V_177 ) ) ;
V_38 = F_25 ( V_99 -> V_4 , V_96 ) ;
if ( V_38 && F_70 ( V_115 , V_38 , & V_117 ) == 1 ) {
int V_188 ;
if ( ( V_38 -> V_67 & V_141 ) || F_125 ( * V_115 ) )
V_188 = V_179 ;
else
V_188 = 0 ;
for (; V_96 != V_71 ; V_96 += V_26 ) {
unsigned long V_187 ;
V_187 = ( V_96 & ~ V_189 ) >>
V_19 ;
F_121 ( & V_171 , V_173 , * V_115 , V_187 , V_188 ) ;
V_176 = F_109 ( V_96 , & V_171 , V_173 ) ;
if ( V_176 )
break;
}
F_71 ( V_117 ) ;
return V_176 ;
}
if ( F_72 ( V_115 ) )
return 0 ;
for (; V_96 != V_71 ; V_96 += V_26 ) {
int V_181 ;
if ( V_38 && ( V_96 >= V_38 -> V_79 ) ) {
V_38 = F_25 ( V_99 -> V_4 , V_96 ) ;
if ( V_38 && ( V_38 -> V_67 & V_141 ) )
V_181 = V_179 ;
else
V_181 = 0 ;
V_171 = F_108 ( F_111 ( V_173 -> V_177 ) | F_113 ( V_173 -> V_177 , V_181 ) ) ;
}
if ( V_38 && ( V_38 -> V_78 <= V_96 ) &&
! F_80 ( V_38 ) ) {
V_116 = F_126 ( V_115 , V_96 ) ;
F_114 ( & V_171 , V_173 , V_38 , V_96 , * V_116 ) ;
F_127 ( V_116 ) ;
}
V_176 = F_109 ( V_96 , & V_171 , V_173 ) ;
if ( V_176 )
return V_176 ;
}
F_75 () ;
return V_176 ;
}
static void F_128 ( T_12 * V_171 , struct V_172 * V_173 ,
V_24 V_116 , int V_187 , int V_181 )
{
if ( F_54 ( V_116 ) )
* V_171 = F_108 ( F_120 ( F_115 ( V_116 ) + V_187 ) |
F_113 ( V_173 -> V_177 , V_181 ) |
V_182 ) ;
else
* V_171 = F_108 ( F_111 ( V_173 -> V_177 ) |
F_113 ( V_173 -> V_177 , V_181 ) ) ;
}
static int F_129 ( V_24 * V_116 , unsigned long V_190 ,
unsigned long V_96 , unsigned long V_71 ,
struct V_98 * V_99 )
{
struct V_172 * V_173 = V_99 -> V_43 ;
struct V_37 * V_38 ;
int V_176 = 0 ;
int V_181 ;
T_12 V_171 ;
V_38 = F_25 ( V_99 -> V_4 , V_96 ) ;
F_130 ( ! V_38 ) ;
if ( V_38 && ( V_38 -> V_67 & V_141 ) )
V_181 = V_179 ;
else
V_181 = 0 ;
for (; V_96 != V_71 ; V_96 += V_26 ) {
int V_187 = ( V_96 & ~ V_190 ) >> V_19 ;
F_128 ( & V_171 , V_173 , * V_116 , V_187 , V_181 ) ;
V_176 = F_109 ( V_96 , & V_171 , V_173 ) ;
if ( V_176 )
return V_176 ;
}
F_75 () ;
return V_176 ;
}
static T_10 F_131 ( struct V_57 * V_57 , char T_11 * V_155 ,
T_9 V_91 , T_1 * V_156 )
{
struct V_33 * V_34 = F_103 ( F_35 ( V_57 ) ) ;
struct V_3 * V_4 ;
struct V_172 V_173 ;
int V_60 = - V_49 ;
struct V_98 V_191 = {} ;
unsigned long V_192 ;
unsigned long V_193 ;
unsigned long V_194 ;
unsigned long V_195 ;
int V_196 = 0 ;
if ( ! V_34 )
goto V_52;
V_60 = - V_165 ;
if ( ( * V_156 % V_197 ) || ( V_91 % V_197 ) )
goto V_198;
V_60 = 0 ;
if ( ! V_91 )
goto V_198;
V_173 . V_177 = V_166 ;
V_173 . V_174 = ( V_199 >> V_19 ) ;
V_173 . V_157 = F_132 ( V_173 . V_174 * V_197 , V_200 ) ;
V_60 = - V_61 ;
if ( ! V_173 . V_157 )
goto V_198;
V_4 = F_21 ( V_34 , V_50 ) ;
V_60 = F_133 ( V_4 ) ;
if ( ! V_4 || F_22 ( V_4 ) )
goto V_201;
V_191 . V_148 = F_124 ;
V_191 . V_202 = F_110 ;
#ifdef F_134
V_191 . V_203 = F_129 ;
#endif
V_191 . V_4 = V_4 ;
V_191 . V_43 = & V_173 ;
V_192 = * V_156 ;
V_193 = V_192 / V_197 ;
V_194 = V_193 << V_19 ;
V_195 = F_135 ( V_34 ) ;
if ( V_193 > F_135 ( V_34 ) >> V_19 )
V_194 = V_195 ;
V_60 = 0 ;
while ( V_91 && ( V_194 < V_195 ) ) {
int V_174 ;
unsigned long V_71 ;
V_173 . V_42 = 0 ;
V_71 = ( V_194 + V_199 ) & V_189 ;
if ( V_71 < V_194 || V_71 > V_195 )
V_71 = V_195 ;
F_23 ( & V_4 -> V_41 ) ;
V_60 = F_81 ( V_194 , V_71 , & V_191 ) ;
F_16 ( & V_4 -> V_41 ) ;
V_194 = V_71 ;
V_174 = F_112 ( V_91 , V_197 * V_173 . V_42 ) ;
if ( F_136 ( V_155 , V_173 . V_157 , V_174 ) ) {
V_60 = - V_162 ;
goto V_204;
}
V_196 += V_174 ;
V_155 += V_174 ;
V_91 -= V_174 ;
}
* V_156 += V_196 ;
if ( ! V_60 || V_60 == V_175 )
V_60 = V_196 ;
V_204:
F_17 ( V_4 ) ;
V_201:
F_33 ( V_173 . V_157 ) ;
V_198:
F_28 ( V_34 ) ;
V_52:
return V_60 ;
}
static int F_137 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
F_102 ( L_68
L_69
L_70 ) ;
return 0 ;
}
static void F_138 ( struct V_102 * V_102 , struct V_205 * V_206 , int F_67 ,
unsigned long V_207 )
{
int V_91 = F_66 ( V_102 ) ;
V_206 -> V_208 += V_207 ;
if ( F_67 || F_68 ( V_102 ) )
V_206 -> V_209 += V_207 ;
if ( F_139 ( V_102 ) )
V_206 -> V_210 += V_207 ;
if ( F_140 ( V_102 ) || F_141 ( V_102 ) )
V_206 -> V_211 += V_207 ;
if ( F_142 ( V_102 ) )
V_206 -> V_212 += V_207 ;
if ( F_63 ( V_102 ) )
V_206 -> V_213 += V_207 ;
if ( V_91 > V_206 -> V_214 )
V_206 -> V_214 = V_91 ;
V_206 -> V_215 [ F_143 ( V_102 ) ] += V_207 ;
}
static struct V_102 * F_144 ( V_24 V_116 , struct V_37 * V_38 ,
unsigned long V_96 )
{
struct V_102 * V_102 ;
int V_216 ;
if ( ! F_54 ( V_116 ) )
return NULL ;
V_102 = F_55 ( V_38 , V_96 , V_116 ) ;
if ( ! V_102 )
return NULL ;
if ( F_145 ( V_102 ) )
return NULL ;
V_216 = F_143 ( V_102 ) ;
if ( ! F_146 ( V_216 , V_217 [ V_218 ] ) )
return NULL ;
return V_102 ;
}
static int F_147 ( T_7 * V_115 , unsigned long V_96 ,
unsigned long V_71 , struct V_98 * V_99 )
{
struct V_205 * V_206 ;
T_8 * V_117 ;
V_24 * V_219 ;
V_24 * V_116 ;
V_206 = V_99 -> V_43 ;
if ( F_70 ( V_115 , V_206 -> V_38 , & V_117 ) == 1 ) {
V_24 V_220 = * ( V_24 * ) V_115 ;
struct V_102 * V_102 ;
V_102 = F_144 ( V_220 , V_206 -> V_38 , V_96 ) ;
if ( V_102 )
F_138 ( V_102 , V_206 , F_67 ( V_220 ) ,
V_118 / V_26 ) ;
F_71 ( V_117 ) ;
return 0 ;
}
if ( F_72 ( V_115 ) )
return 0 ;
V_219 = V_116 = F_73 ( V_99 -> V_4 , V_115 , V_96 , & V_117 ) ;
do {
struct V_102 * V_102 = F_144 ( * V_116 , V_206 -> V_38 , V_96 ) ;
if ( ! V_102 )
continue;
F_138 ( V_102 , V_206 , F_67 ( * V_116 ) , 1 ) ;
} while ( V_116 ++ , V_96 += V_26 , V_96 != V_71 );
F_74 ( V_219 , V_117 ) ;
return 0 ;
}
static int F_148 ( V_24 * V_116 , unsigned long V_190 ,
unsigned long V_96 , unsigned long V_71 , struct V_98 * V_99 )
{
struct V_205 * V_206 ;
struct V_102 * V_102 ;
if ( ! F_54 ( * V_116 ) )
return 0 ;
V_102 = F_149 ( * V_116 ) ;
if ( ! V_102 )
return 0 ;
V_206 = V_99 -> V_43 ;
F_138 ( V_102 , V_206 , F_67 ( * V_116 ) , 1 ) ;
return 0 ;
}
static int F_148 ( V_24 * V_116 , unsigned long V_190 ,
unsigned long V_96 , unsigned long V_71 , struct V_98 * V_99 )
{
return 0 ;
}
static int F_150 ( struct V_1 * V_2 , void * V_55 , int V_64 )
{
struct V_221 * V_222 = V_2 -> V_43 ;
struct V_31 * V_223 = & V_222 -> V_224 ;
struct V_37 * V_38 = V_55 ;
struct V_205 * V_206 = & V_222 -> V_206 ;
struct V_57 * V_57 = V_38 -> V_65 ;
struct V_33 * V_34 = V_223 -> V_34 ;
struct V_3 * V_4 = V_38 -> V_40 ;
struct V_98 V_99 = {} ;
struct V_36 * V_225 ;
char V_157 [ 64 ] ;
int V_216 ;
if ( ! V_4 )
return 0 ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_206 -> V_38 = V_38 ;
V_99 . V_203 = F_148 ;
V_99 . V_148 = F_147 ;
V_99 . V_43 = V_206 ;
V_99 . V_4 = V_4 ;
V_225 = F_151 ( V_34 , V_38 , V_38 -> V_78 ) ;
F_152 ( V_157 , sizeof( V_157 ) , V_225 ) ;
F_153 ( V_225 ) ;
F_5 ( V_2 , L_71 , V_38 -> V_78 , V_157 ) ;
if ( V_57 ) {
F_45 ( V_2 , L_72 ) ;
F_42 ( V_2 , & V_57 -> V_84 , L_73 ) ;
} else if ( V_38 -> V_78 <= V_4 -> V_88 && V_38 -> V_79 >= V_4 -> V_89 ) {
F_45 ( V_2 , L_74 ) ;
} else {
T_4 V_87 = F_44 ( V_34 , V_38 , V_64 ) ;
if ( V_87 != 0 ) {
if ( ! V_64 || ( V_38 -> V_78 <= V_4 -> V_90 &&
V_38 -> V_79 >= V_4 -> V_90 ) )
F_45 ( V_2 , L_75 ) ;
else
F_5 ( V_2 , L_76 , V_87 ) ;
}
}
if ( F_80 ( V_38 ) )
F_45 ( V_2 , L_77 ) ;
F_81 ( V_38 -> V_78 , V_38 -> V_79 , & V_99 ) ;
if ( ! V_206 -> V_208 )
goto V_52;
if ( V_206 -> V_213 )
F_5 ( V_2 , L_78 , V_206 -> V_213 ) ;
if ( V_206 -> V_209 )
F_5 ( V_2 , L_79 , V_206 -> V_209 ) ;
if ( V_206 -> V_208 != V_206 -> V_213 && V_206 -> V_208 != V_206 -> V_209 )
F_5 ( V_2 , L_80 , V_206 -> V_208 ) ;
if ( V_206 -> V_214 > 1 )
F_5 ( V_2 , L_81 , V_206 -> V_214 ) ;
if ( V_206 -> V_210 )
F_5 ( V_2 , L_82 , V_206 -> V_210 ) ;
if ( V_206 -> V_211 < V_206 -> V_208 && ! F_80 ( V_38 ) )
F_5 ( V_2 , L_83 , V_206 -> V_211 ) ;
if ( V_206 -> V_212 )
F_5 ( V_2 , L_84 , V_206 -> V_212 ) ;
F_154 (nid, N_MEMORY)
if ( V_206 -> V_215 [ V_216 ] )
F_5 ( V_2 , L_85 , V_216 , V_206 -> V_215 [ V_216 ] ) ;
V_52:
F_46 ( V_2 , '\n' ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
V_2 -> V_45 = ( V_38 != V_223 -> V_39 ) ? V_38 -> V_78 : 0 ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 , void * V_55 )
{
return F_150 ( V_2 , V_55 , 1 ) ;
}
static int F_156 ( struct V_1 * V_2 , void * V_55 )
{
return F_150 ( V_2 , V_55 , 0 ) ;
}
static int F_157 ( struct V_56 * V_56 , struct V_57 * V_57 ,
const struct V_58 * V_59 )
{
struct V_221 * V_32 ;
int V_60 = - V_61 ;
V_32 = F_30 ( sizeof( * V_32 ) , V_62 ) ;
if ( V_32 ) {
V_32 -> V_224 . V_47 = F_31 ( V_56 ) ;
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
static int F_158 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_157 ( V_56 , V_57 , & V_226 ) ;
}
static int F_159 ( struct V_56 * V_56 , struct V_57 * V_57 )
{
return F_157 ( V_56 , V_57 , & V_227 ) ;
}
