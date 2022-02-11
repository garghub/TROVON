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
static void F_65 ( V_24 V_97 , unsigned long V_98 ,
unsigned long V_99 , struct V_100 * V_101 )
{
struct V_102 * V_103 = V_101 -> V_44 ;
struct V_37 * V_38 = V_103 -> V_38 ;
T_5 V_75 = F_66 ( V_38 , V_98 ) ;
struct V_104 * V_104 = NULL ;
int V_105 ;
if ( F_67 ( V_97 ) ) {
V_104 = F_68 ( V_38 , V_98 , V_97 ) ;
} else if ( F_69 ( V_97 ) ) {
T_6 V_106 = F_70 ( V_97 ) ;
if ( ! F_71 ( V_106 ) )
V_103 -> V_8 += V_99 ;
else if ( F_72 ( V_106 ) )
V_104 = F_73 ( V_106 ) ;
} else if ( F_74 ( V_97 ) ) {
if ( F_75 ( V_97 ) != V_75 )
V_103 -> V_107 += V_99 ;
}
if ( ! V_104 )
return;
if ( F_76 ( V_104 ) )
V_103 -> V_108 += V_99 ;
if ( V_104 -> V_109 != V_75 )
V_103 -> V_107 += V_99 ;
V_103 -> V_28 += V_99 ;
if ( F_77 ( V_97 ) || F_78 ( V_104 ) )
V_103 -> V_110 += V_99 ;
V_105 = F_79 ( V_104 ) ;
if ( V_105 >= 2 ) {
if ( F_80 ( V_97 ) || F_81 ( V_104 ) )
V_103 -> V_111 += V_99 ;
else
V_103 -> V_112 += V_99 ;
V_103 -> V_113 += ( V_99 << V_114 ) / V_105 ;
} else {
if ( F_80 ( V_97 ) || F_81 ( V_104 ) )
V_103 -> V_115 += V_99 ;
else
V_103 -> V_116 += V_99 ;
V_103 -> V_113 += ( V_99 << V_114 ) ;
}
}
static int F_82 ( T_7 * V_117 , unsigned long V_98 , unsigned long V_77 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 = V_101 -> V_44 ;
struct V_37 * V_38 = V_103 -> V_38 ;
V_24 * V_118 ;
T_8 * V_119 ;
if ( F_83 ( V_117 , V_38 , & V_119 ) == 1 ) {
F_65 ( * ( V_24 * ) V_117 , V_98 , V_120 , V_101 ) ;
F_84 ( V_119 ) ;
V_103 -> V_121 += V_120 ;
return 0 ;
}
if ( F_85 ( V_117 ) )
return 0 ;
V_118 = F_86 ( V_38 -> V_70 , V_117 , V_98 , & V_119 ) ;
for (; V_98 != V_77 ; V_118 ++ , V_98 += V_26 )
F_65 ( * V_118 , V_98 , V_26 , V_101 ) ;
F_87 ( V_118 - 1 , V_119 ) ;
F_88 () ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
static const char V_122 [ V_123 ] [ 2 ] = {
[ 0 ... ( V_123 - 1 ) ] = L_19 ,
[ F_90 ( V_84 ) ] = L_20 ,
[ F_90 ( V_85 ) ] = L_21 ,
[ F_90 ( V_86 ) ] = L_22 ,
[ F_90 ( V_124 ) ] = L_23 ,
[ F_90 ( V_125 ) ] = L_24 ,
[ F_90 ( V_126 ) ] = L_25 ,
[ F_90 ( V_127 ) ] = L_26 ,
[ F_90 ( V_87 ) ] = L_27 ,
[ F_90 ( V_128 ) ] = L_28 ,
[ F_90 ( V_129 ) ] = L_29 ,
[ F_90 ( V_130 ) ] = L_30 ,
[ F_90 ( V_131 ) ] = L_31 ,
[ F_90 ( V_132 ) ] = L_32 ,
[ F_90 ( V_133 ) ] = L_33 ,
[ F_90 ( V_134 ) ] = L_34 ,
[ F_90 ( V_135 ) ] = L_35 ,
[ F_90 ( V_136 ) ] = L_36 ,
[ F_90 ( V_137 ) ] = L_37 ,
[ F_90 ( V_138 ) ] = L_38 ,
[ F_90 ( V_139 ) ] = L_39 ,
[ F_90 ( V_140 ) ] = L_40 ,
[ F_90 ( V_141 ) ] = L_41 ,
[ F_90 ( V_142 ) ] = L_42 ,
#ifdef F_91
[ F_90 ( V_143 ) ] = L_43 ,
#endif
[ F_90 ( V_144 ) ] = L_44 ,
[ F_90 ( V_145 ) ] = L_45 ,
[ F_90 ( V_146 ) ] = L_46 ,
[ F_90 ( V_147 ) ] = L_47 ,
} ;
T_9 V_148 ;
F_58 ( V_2 , L_48 ) ;
for ( V_148 = 0 ; V_148 < V_123 ; V_148 ++ ) {
if ( V_38 -> V_73 & ( 1UL << V_148 ) ) {
F_5 ( V_2 , L_49 ,
V_122 [ V_148 ] [ 0 ] , V_122 [ V_148 ] [ 1 ] ) ;
}
}
F_59 ( V_2 , '\n' ) ;
}
static int F_92 ( struct V_1 * V_2 , void * V_54 , int V_65 )
{
struct V_37 * V_38 = V_54 ;
struct V_102 V_103 ;
struct V_100 V_149 = {
. V_150 = F_82 ,
. V_4 = V_38 -> V_70 ,
. V_44 = & V_103 ,
} ;
memset ( & V_103 , 0 , sizeof V_103 ) ;
V_103 . V_38 = V_38 ;
if ( V_38 -> V_70 && ! F_93 ( V_38 ) )
F_94 ( V_38 -> V_45 , V_38 -> V_83 , & V_149 ) ;
F_48 ( V_2 , V_38 , V_65 ) ;
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
( V_38 -> V_83 - V_38 -> V_45 ) >> 10 ,
V_103 . V_28 >> 10 ,
( unsigned long ) ( V_103 . V_113 >> ( 10 + V_114 ) ) ,
V_103 . V_112 >> 10 ,
V_103 . V_111 >> 10 ,
V_103 . V_116 >> 10 ,
V_103 . V_115 >> 10 ,
V_103 . V_110 >> 10 ,
V_103 . V_108 >> 10 ,
V_103 . V_121 >> 10 ,
V_103 . V_8 >> 10 ,
F_95 ( V_38 ) >> 10 ,
F_96 ( V_38 ) >> 10 ,
( V_38 -> V_73 & V_131 ) ?
( unsigned long ) ( V_103 . V_113 >> ( 10 + V_114 ) ) : 0 ) ;
if ( V_38 -> V_73 & V_140 )
F_5 ( V_2 , L_64 ,
V_103 . V_107 >> 10 ) ;
F_89 ( V_2 , V_38 ) ;
F_20 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , void * V_54 )
{
return F_92 ( V_2 , V_54 , 1 ) ;
}
static int F_98 ( struct V_1 * V_2 , void * V_54 )
{
return F_92 ( V_2 , V_54 , 0 ) ;
}
static int F_99 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_40 ( V_49 , V_56 , & V_151 ) ;
}
static int F_100 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_40 ( V_49 , V_56 , & V_152 ) ;
}
static inline void F_101 ( struct V_37 * V_38 ,
unsigned long V_98 , V_24 * V_118 )
{
#ifdef F_91
V_24 V_97 = * V_118 ;
if ( F_67 ( V_97 ) ) {
V_97 = F_102 ( V_97 ) ;
V_97 = F_103 ( V_97 , V_153 ) ;
} else if ( F_69 ( V_97 ) ) {
V_97 = F_104 ( V_97 ) ;
} else if ( F_74 ( V_97 ) ) {
V_97 = F_105 ( V_97 ) ;
}
F_106 ( V_38 -> V_70 , V_98 , V_118 , V_97 ) ;
#endif
}
static int F_107 ( T_7 * V_117 , unsigned long V_98 ,
unsigned long V_77 , struct V_100 * V_101 )
{
struct V_154 * V_155 = V_101 -> V_44 ;
struct V_37 * V_38 = V_155 -> V_38 ;
V_24 * V_118 , V_97 ;
T_8 * V_119 ;
struct V_104 * V_104 ;
F_108 ( V_38 , V_98 , V_117 ) ;
if ( F_85 ( V_117 ) )
return 0 ;
V_118 = F_86 ( V_38 -> V_70 , V_117 , V_98 , & V_119 ) ;
for (; V_98 != V_77 ; V_118 ++ , V_98 += V_26 ) {
V_97 = * V_118 ;
if ( V_155 -> type == V_156 ) {
F_101 ( V_38 , V_98 , V_118 ) ;
continue;
}
if ( ! F_67 ( V_97 ) )
continue;
V_104 = F_68 ( V_38 , V_98 , V_97 ) ;
if ( ! V_104 )
continue;
F_109 ( V_38 , V_98 , V_118 ) ;
F_110 ( V_104 ) ;
}
F_87 ( V_118 - 1 , V_119 ) ;
F_88 () ;
return 0 ;
}
static T_10 F_111 ( struct V_56 * V_56 , const char T_11 * V_157 ,
T_9 V_41 , T_1 * V_46 )
{
struct V_33 * V_34 ;
char V_158 [ V_159 ] ;
struct V_3 * V_4 ;
struct V_37 * V_38 ;
enum V_160 type ;
int V_161 ;
int V_162 ;
memset ( V_158 , 0 , sizeof( V_158 ) ) ;
if ( V_41 > sizeof( V_158 ) - 1 )
V_41 = sizeof( V_158 ) - 1 ;
if ( F_112 ( V_158 , V_157 , V_41 ) )
return - V_163 ;
V_162 = F_113 ( F_114 ( V_158 ) , 10 , & V_161 ) ;
if ( V_162 < 0 )
return V_162 ;
type = (enum V_160 ) V_161 ;
if ( type < V_164 || type >= V_165 )
return - V_166 ;
if ( type == V_156 ) {
V_167 = true ;
F_115 ( L_65
L_66
L_67 ) ;
}
V_34 = F_22 ( F_49 ( V_56 ) ) ;
if ( ! V_34 )
return - V_50 ;
V_4 = F_116 ( V_34 ) ;
if ( V_4 ) {
struct V_154 V_155 = {
. type = type ,
} ;
struct V_100 V_168 = {
. V_150 = F_107 ,
. V_4 = V_4 ,
. V_44 = & V_155 ,
} ;
F_25 ( & V_4 -> V_36 ) ;
if ( type == V_156 ) {
for ( V_38 = V_4 -> V_53 ; V_38 ; V_38 = V_38 -> V_40 ) {
if ( ! ( V_38 -> V_73 & V_143 ) )
continue;
F_17 ( & V_4 -> V_36 ) ;
F_117 ( & V_4 -> V_36 ) ;
for ( V_38 = V_4 -> V_53 ; V_38 ; V_38 = V_38 -> V_40 ) {
V_38 -> V_73 &= ~ V_143 ;
F_118 ( V_38 ) ;
}
F_119 ( & V_4 -> V_36 ) ;
break;
}
F_120 ( V_4 , 0 , - 1 ) ;
}
for ( V_38 = V_4 -> V_53 ; V_38 ; V_38 = V_38 -> V_40 ) {
V_155 . V_38 = V_38 ;
if ( F_93 ( V_38 ) )
continue;
if ( type == V_169 && V_38 -> V_71 )
continue;
if ( type == V_170 && ! V_38 -> V_71 )
continue;
F_94 ( V_38 -> V_45 , V_38 -> V_83 ,
& V_168 ) ;
}
if ( type == V_156 )
F_121 ( V_4 , 0 , - 1 ) ;
F_122 ( V_4 ) ;
F_17 ( & V_4 -> V_36 ) ;
F_18 ( V_4 ) ;
}
F_31 ( V_34 ) ;
return V_41 ;
}
static inline T_12 F_123 ( T_13 V_171 )
{
return ( T_12 ) { . V_172 = V_171 } ;
}
static int F_124 ( unsigned long V_98 , T_12 * V_172 ,
struct V_173 * V_174 )
{
V_174 -> V_158 [ V_174 -> V_48 ++ ] = * V_172 ;
if ( V_174 -> V_48 >= V_174 -> V_175 )
return V_176 ;
return 0 ;
}
static int F_125 ( unsigned long V_76 , unsigned long V_77 ,
struct V_100 * V_101 )
{
struct V_173 * V_174 = V_101 -> V_44 ;
unsigned long V_98 = V_76 ;
int V_62 = 0 ;
while ( V_98 < V_77 ) {
struct V_37 * V_38 = F_27 ( V_101 -> V_4 , V_98 ) ;
T_12 V_172 = F_123 ( F_126 ( V_174 -> V_177 ) ) ;
unsigned long V_178 ;
if ( V_38 )
V_178 = F_127 ( V_77 , V_38 -> V_45 ) ;
else
V_178 = V_77 ;
for (; V_98 < V_178 ; V_98 += V_26 ) {
V_62 = F_124 ( V_98 , & V_172 , V_174 ) ;
if ( V_62 )
goto V_179;
}
if ( ! V_38 )
break;
if ( V_38 -> V_73 & V_143 )
V_172 . V_172 |= F_128 ( V_174 -> V_177 , V_180 ) ;
for (; V_98 < F_127 ( V_77 , V_38 -> V_83 ) ; V_98 += V_26 ) {
V_62 = F_124 ( V_98 , & V_172 , V_174 ) ;
if ( V_62 )
goto V_179;
}
}
V_179:
return V_62 ;
}
static void F_129 ( T_12 * V_172 , struct V_173 * V_174 ,
struct V_37 * V_38 , unsigned long V_98 , V_24 V_118 )
{
T_13 V_181 , V_72 ;
struct V_104 * V_104 = NULL ;
int V_182 = 0 ;
if ( F_67 ( V_118 ) ) {
V_181 = F_130 ( V_118 ) ;
V_72 = V_183 ;
V_104 = F_68 ( V_38 , V_98 , V_118 ) ;
if ( F_131 ( V_118 ) )
V_182 |= V_180 ;
} else if ( F_69 ( V_118 ) ) {
T_6 V_184 ;
if ( F_132 ( V_118 ) )
V_182 |= V_180 ;
V_184 = F_70 ( V_118 ) ;
V_181 = F_133 ( V_184 ) |
( F_134 ( V_184 ) << V_185 ) ;
V_72 = V_186 ;
if ( F_72 ( V_184 ) )
V_104 = F_73 ( V_184 ) ;
} else {
if ( V_38 -> V_73 & V_143 )
V_182 |= V_180 ;
* V_172 = F_123 ( F_126 ( V_174 -> V_177 ) | F_128 ( V_174 -> V_177 , V_182 ) ) ;
return;
}
if ( V_104 && ! F_76 ( V_104 ) )
V_72 |= V_187 ;
if ( ( V_38 -> V_73 & V_143 ) )
V_182 |= V_180 ;
* V_172 = F_123 ( F_135 ( V_181 ) | F_128 ( V_174 -> V_177 , V_182 ) | V_72 ) ;
}
static void F_136 ( T_12 * V_172 , struct V_173 * V_174 ,
T_7 V_117 , int V_188 , int V_189 )
{
if ( F_137 ( V_117 ) )
* V_172 = F_123 ( F_135 ( F_138 ( V_117 ) + V_188 )
| F_128 ( V_174 -> V_177 , V_189 ) | V_183 ) ;
else
* V_172 = F_123 ( F_126 ( V_174 -> V_177 ) | F_128 ( V_174 -> V_177 , V_189 ) ) ;
}
static inline void F_136 ( T_12 * V_172 , struct V_173 * V_174 ,
T_7 V_117 , int V_188 , int V_189 )
{
}
static int F_139 ( T_7 * V_117 , unsigned long V_98 , unsigned long V_77 ,
struct V_100 * V_101 )
{
struct V_37 * V_38 ;
struct V_173 * V_174 = V_101 -> V_44 ;
T_8 * V_119 ;
V_24 * V_118 ;
int V_62 = 0 ;
V_38 = F_27 ( V_101 -> V_4 , V_98 ) ;
if ( V_38 && F_83 ( V_117 , V_38 , & V_119 ) == 1 ) {
int V_189 ;
if ( ( V_38 -> V_73 & V_143 ) || F_140 ( * V_117 ) )
V_189 = V_180 ;
else
V_189 = 0 ;
for (; V_98 != V_77 ; V_98 += V_26 ) {
unsigned long V_188 ;
T_12 V_172 ;
V_188 = ( V_98 & ~ V_190 ) >>
V_19 ;
F_136 ( & V_172 , V_174 , * V_117 , V_188 , V_189 ) ;
V_62 = F_124 ( V_98 , & V_172 , V_174 ) ;
if ( V_62 )
break;
}
F_84 ( V_119 ) ;
return V_62 ;
}
if ( F_85 ( V_117 ) )
return 0 ;
while ( 1 ) {
unsigned long V_178 ;
if ( V_38 )
V_178 = F_127 ( V_77 , V_38 -> V_45 ) ;
else
V_178 = V_77 ;
for (; V_98 < V_178 ; V_98 += V_26 ) {
T_12 V_172 = F_123 ( F_126 ( V_174 -> V_177 ) ) ;
V_62 = F_124 ( V_98 , & V_172 , V_174 ) ;
if ( V_62 )
return V_62 ;
}
if ( ! V_38 || V_38 -> V_45 >= V_77 )
break;
F_141 ( F_93 ( V_38 ) ) ;
for (; V_98 < F_127 ( V_77 , V_38 -> V_83 ) ; V_98 += V_26 ) {
T_12 V_172 ;
V_118 = F_142 ( V_117 , V_98 ) ;
F_129 ( & V_172 , V_174 , V_38 , V_98 , * V_118 ) ;
F_143 ( V_118 ) ;
V_62 = F_124 ( V_98 , & V_172 , V_174 ) ;
if ( V_62 )
return V_62 ;
}
if ( V_98 == V_77 )
break;
V_38 = F_27 ( V_101 -> V_4 , V_98 ) ;
}
F_88 () ;
return V_62 ;
}
static void F_144 ( T_12 * V_172 , struct V_173 * V_174 ,
V_24 V_118 , int V_188 , int V_182 )
{
if ( F_67 ( V_118 ) )
* V_172 = F_123 ( F_135 ( F_130 ( V_118 ) + V_188 ) |
F_128 ( V_174 -> V_177 , V_182 ) |
V_183 ) ;
else
* V_172 = F_123 ( F_126 ( V_174 -> V_177 ) |
F_128 ( V_174 -> V_177 , V_182 ) ) ;
}
static int F_145 ( V_24 * V_118 , unsigned long V_191 ,
unsigned long V_98 , unsigned long V_77 ,
struct V_100 * V_101 )
{
struct V_173 * V_174 = V_101 -> V_44 ;
struct V_37 * V_38 ;
int V_62 = 0 ;
int V_182 ;
T_12 V_172 ;
V_38 = F_27 ( V_101 -> V_4 , V_98 ) ;
F_146 ( ! V_38 ) ;
if ( V_38 && ( V_38 -> V_73 & V_143 ) )
V_182 = V_180 ;
else
V_182 = 0 ;
for (; V_98 != V_77 ; V_98 += V_26 ) {
int V_188 = ( V_98 & ~ V_191 ) >> V_19 ;
F_144 ( & V_172 , V_174 , * V_118 , V_188 , V_182 ) ;
V_62 = F_124 ( V_98 , & V_172 , V_174 ) ;
if ( V_62 )
return V_62 ;
}
F_88 () ;
return V_62 ;
}
static T_10 F_147 ( struct V_56 * V_56 , char T_11 * V_157 ,
T_9 V_41 , T_1 * V_46 )
{
struct V_33 * V_34 = F_22 ( F_49 ( V_56 ) ) ;
struct V_3 * V_4 ;
struct V_173 V_174 ;
int V_66 = - V_50 ;
struct V_100 V_192 = {} ;
unsigned long V_193 ;
unsigned long V_194 ;
unsigned long V_195 ;
unsigned long V_196 ;
int V_197 = 0 ;
if ( ! V_34 )
goto V_179;
V_66 = - V_166 ;
if ( ( * V_46 % V_198 ) || ( V_41 % V_198 ) )
goto V_199;
V_66 = 0 ;
if ( ! V_41 )
goto V_199;
V_174 . V_177 = V_167 ;
V_174 . V_175 = ( V_200 >> V_19 ) ;
V_174 . V_158 = F_148 ( V_174 . V_175 * V_198 , V_201 ) ;
V_66 = - V_60 ;
if ( ! V_174 . V_158 )
goto V_199;
V_4 = F_149 ( V_34 , V_61 ) ;
V_66 = F_36 ( V_4 ) ;
if ( ! V_4 || F_35 ( V_4 ) )
goto V_202;
V_192 . V_150 = F_139 ;
V_192 . V_203 = F_125 ;
#ifdef F_150
V_192 . V_204 = F_145 ;
#endif
V_192 . V_4 = V_4 ;
V_192 . V_44 = & V_174 ;
V_193 = * V_46 ;
V_194 = V_193 / V_198 ;
V_195 = V_194 << V_19 ;
V_196 = F_151 ( V_34 ) ;
if ( V_194 > F_151 ( V_34 ) >> V_19 )
V_195 = V_196 ;
V_66 = 0 ;
while ( V_41 && ( V_195 < V_196 ) ) {
int V_175 ;
unsigned long V_77 ;
V_174 . V_48 = 0 ;
V_77 = ( V_195 + V_200 ) & V_190 ;
if ( V_77 < V_195 || V_77 > V_196 )
V_77 = V_196 ;
F_25 ( & V_4 -> V_36 ) ;
V_66 = F_94 ( V_195 , V_77 , & V_192 ) ;
F_17 ( & V_4 -> V_36 ) ;
V_195 = V_77 ;
V_175 = F_127 ( V_41 , V_198 * V_174 . V_48 ) ;
if ( F_152 ( V_157 , V_174 . V_158 , V_175 ) ) {
V_66 = - V_163 ;
goto V_205;
}
V_197 += V_175 ;
V_157 += V_175 ;
V_41 -= V_175 ;
}
* V_46 += V_197 ;
if ( ! V_66 || V_66 == V_176 )
V_66 = V_197 ;
V_205:
F_18 ( V_4 ) ;
V_202:
F_153 ( V_174 . V_158 ) ;
V_199:
F_31 ( V_34 ) ;
V_179:
return V_66 ;
}
static int F_154 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
F_115 ( L_68
L_69
L_70 ) ;
return 0 ;
}
static void F_155 ( struct V_104 * V_104 , struct V_206 * V_207 , int F_80 ,
unsigned long V_208 )
{
int V_41 = F_79 ( V_104 ) ;
V_207 -> V_209 += V_208 ;
if ( F_80 || F_81 ( V_104 ) )
V_207 -> V_210 += V_208 ;
if ( F_156 ( V_104 ) )
V_207 -> V_211 += V_208 ;
if ( F_157 ( V_104 ) || F_158 ( V_104 ) )
V_207 -> V_212 += V_208 ;
if ( F_159 ( V_104 ) )
V_207 -> V_213 += V_208 ;
if ( F_76 ( V_104 ) )
V_207 -> V_214 += V_208 ;
if ( V_41 > V_207 -> V_215 )
V_207 -> V_215 = V_41 ;
V_207 -> V_216 [ F_160 ( V_104 ) ] += V_208 ;
}
static struct V_104 * F_161 ( V_24 V_118 , struct V_37 * V_38 ,
unsigned long V_98 )
{
struct V_104 * V_104 ;
int V_217 ;
if ( ! F_67 ( V_118 ) )
return NULL ;
V_104 = F_68 ( V_38 , V_98 , V_118 ) ;
if ( ! V_104 )
return NULL ;
if ( F_162 ( V_104 ) )
return NULL ;
V_217 = F_160 ( V_104 ) ;
if ( ! F_163 ( V_217 , V_218 [ V_219 ] ) )
return NULL ;
return V_104 ;
}
static int F_164 ( T_7 * V_117 , unsigned long V_98 ,
unsigned long V_77 , struct V_100 * V_101 )
{
struct V_206 * V_207 ;
T_8 * V_119 ;
V_24 * V_220 ;
V_24 * V_118 ;
V_207 = V_101 -> V_44 ;
if ( F_83 ( V_117 , V_207 -> V_38 , & V_119 ) == 1 ) {
V_24 V_221 = * ( V_24 * ) V_117 ;
struct V_104 * V_104 ;
V_104 = F_161 ( V_221 , V_207 -> V_38 , V_98 ) ;
if ( V_104 )
F_155 ( V_104 , V_207 , F_80 ( V_221 ) ,
V_120 / V_26 ) ;
F_84 ( V_119 ) ;
return 0 ;
}
if ( F_85 ( V_117 ) )
return 0 ;
V_220 = V_118 = F_86 ( V_101 -> V_4 , V_117 , V_98 , & V_119 ) ;
do {
struct V_104 * V_104 = F_161 ( * V_118 , V_207 -> V_38 , V_98 ) ;
if ( ! V_104 )
continue;
F_155 ( V_104 , V_207 , F_80 ( * V_118 ) , 1 ) ;
} while ( V_118 ++ , V_98 += V_26 , V_98 != V_77 );
F_87 ( V_220 , V_119 ) ;
return 0 ;
}
static int F_165 ( V_24 * V_118 , unsigned long V_191 ,
unsigned long V_98 , unsigned long V_77 , struct V_100 * V_101 )
{
struct V_206 * V_207 ;
struct V_104 * V_104 ;
if ( ! F_67 ( * V_118 ) )
return 0 ;
V_104 = F_166 ( * V_118 ) ;
if ( ! V_104 )
return 0 ;
V_207 = V_101 -> V_44 ;
F_155 ( V_104 , V_207 , F_80 ( * V_118 ) , 1 ) ;
return 0 ;
}
static int F_165 ( V_24 * V_118 , unsigned long V_191 ,
unsigned long V_98 , unsigned long V_77 , struct V_100 * V_101 )
{
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , void * V_54 , int V_65 )
{
struct V_222 * V_223 = V_2 -> V_44 ;
struct V_31 * V_224 = & V_223 -> V_225 ;
struct V_37 * V_38 = V_54 ;
struct V_206 * V_207 = & V_223 -> V_207 ;
struct V_56 * V_56 = V_38 -> V_71 ;
struct V_3 * V_4 = V_38 -> V_70 ;
struct V_100 V_101 = {} ;
struct V_226 * V_227 ;
char V_158 [ 64 ] ;
int V_217 ;
if ( ! V_4 )
return 0 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
V_207 -> V_38 = V_38 ;
V_101 . V_204 = F_165 ;
V_101 . V_150 = F_164 ;
V_101 . V_44 = V_207 ;
V_101 . V_4 = V_4 ;
V_227 = F_168 ( V_38 , V_38 -> V_45 ) ;
if ( V_227 ) {
F_169 ( V_158 , sizeof( V_158 ) , V_227 ) ;
F_170 ( V_227 ) ;
} else {
F_169 ( V_158 , sizeof( V_158 ) , V_224 -> V_35 ) ;
}
F_5 ( V_2 , L_71 , V_38 -> V_45 , V_158 ) ;
if ( V_56 ) {
F_58 ( V_2 , L_72 ) ;
F_56 ( V_2 , & V_56 -> V_88 , L_73 ) ;
} else if ( V_38 -> V_45 <= V_4 -> V_92 && V_38 -> V_83 >= V_4 -> V_93 ) {
F_58 ( V_2 , L_74 ) ;
} else {
T_2 V_91 = F_41 ( V_224 , V_38 , V_65 ) ;
if ( V_91 != 0 ) {
if ( ! V_65 || ( V_38 -> V_45 <= V_4 -> V_94 &&
V_38 -> V_83 >= V_4 -> V_94 ) )
F_58 ( V_2 , L_75 ) ;
else
F_5 ( V_2 , L_76 , V_91 ) ;
}
}
if ( F_93 ( V_38 ) )
F_58 ( V_2 , L_77 ) ;
F_94 ( V_38 -> V_45 , V_38 -> V_83 , & V_101 ) ;
if ( ! V_207 -> V_209 )
goto V_179;
if ( V_207 -> V_214 )
F_5 ( V_2 , L_78 , V_207 -> V_214 ) ;
if ( V_207 -> V_210 )
F_5 ( V_2 , L_79 , V_207 -> V_210 ) ;
if ( V_207 -> V_209 != V_207 -> V_214 && V_207 -> V_209 != V_207 -> V_210 )
F_5 ( V_2 , L_80 , V_207 -> V_209 ) ;
if ( V_207 -> V_215 > 1 )
F_5 ( V_2 , L_81 , V_207 -> V_215 ) ;
if ( V_207 -> V_211 )
F_5 ( V_2 , L_82 , V_207 -> V_211 ) ;
if ( V_207 -> V_212 < V_207 -> V_209 && ! F_93 ( V_38 ) )
F_5 ( V_2 , L_83 , V_207 -> V_212 ) ;
if ( V_207 -> V_213 )
F_5 ( V_2 , L_84 , V_207 -> V_213 ) ;
F_171 (nid, N_MEMORY)
if ( V_207 -> V_216 [ V_217 ] )
F_5 ( V_2 , L_85 , V_217 , V_207 -> V_216 [ V_217 ] ) ;
V_179:
F_59 ( V_2 , '\n' ) ;
F_20 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , void * V_54 )
{
return F_167 ( V_2 , V_54 , 1 ) ;
}
static int F_173 ( struct V_1 * V_2 , void * V_54 )
{
return F_167 ( V_2 , V_54 , 0 ) ;
}
static int F_174 ( struct V_49 * V_49 , struct V_56 * V_56 ,
const struct V_57 * V_58 )
{
return F_32 ( V_49 , V_56 , V_58 ,
sizeof( struct V_222 ) ) ;
}
static int F_175 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_174 ( V_49 , V_56 , & V_228 ) ;
}
static int F_176 ( struct V_49 * V_49 , struct V_56 * V_56 )
{
return F_174 ( V_49 , V_56 , & V_229 ) ;
}
