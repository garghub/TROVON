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
struct V_57 * V_57 = V_39 -> V_66 -> V_75 . V_76 -> V_77 ;
V_73 = V_57 -> V_78 -> V_79 ;
V_69 = V_57 -> V_80 ;
V_70 = ( ( T_1 ) V_39 -> V_81 ) << V_19 ;
}
V_71 = V_39 -> V_82 ;
if ( F_35 ( V_39 , V_71 ) )
V_71 += V_26 ;
V_72 = V_39 -> V_83 ;
if ( F_36 ( V_39 , V_72 ) )
V_72 -= V_26 ;
F_5 ( V_2 , L_14 ,
V_71 ,
V_72 ,
V_67 & V_84 ? 'r' : '-' ,
V_67 & V_85 ? 'w' : '-' ,
V_67 & V_86 ? 'x' : '-' ,
V_67 & V_87 ? 's' : 'p' ,
V_70 ,
F_37 ( V_73 ) , F_38 ( V_73 ) , V_69 , & V_31 ) ;
if ( V_58 ) {
F_8 ( V_2 , V_31 ) ;
F_39 ( V_2 , & V_58 -> V_75 , L_15 ) ;
goto V_88;
}
V_74 = F_40 ( V_39 ) ;
if ( ! V_74 ) {
T_4 V_89 ;
if ( ! V_4 ) {
V_74 = L_16 ;
goto V_88;
}
if ( V_39 -> V_82 <= V_4 -> V_90 &&
V_39 -> V_83 >= V_4 -> V_91 ) {
V_74 = L_17 ;
goto V_88;
}
V_89 = F_41 ( V_35 , V_39 , V_65 ) ;
if ( V_89 != 0 ) {
if ( ! V_65 || ( V_39 -> V_82 <= V_4 -> V_92 &&
V_39 -> V_83 >= V_4 -> V_92 ) ) {
V_74 = L_18 ;
} else {
F_8 ( V_2 , V_31 ) ;
F_5 ( V_2 , L_19 , V_89 ) ;
}
}
}
V_88:
if ( V_74 ) {
F_8 ( V_2 , V_31 ) ;
F_42 ( V_2 , V_74 ) ;
}
F_43 ( V_2 , '\n' ) ;
}
static int F_44 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_38 * V_39 = V_56 ;
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_34 * V_35 = V_33 -> V_35 ;
F_34 ( V_2 , V_39 , V_65 ) ;
if ( V_2 -> V_93 < V_2 -> V_94 )
V_2 -> V_46 = ( V_39 != F_24 ( V_35 -> V_4 ) )
? V_39 -> V_82 : 0 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , void * V_56 )
{
return F_44 ( V_2 , V_56 , 1 ) ;
}
static int F_46 ( struct V_1 * V_2 , void * V_56 )
{
return F_44 ( V_2 , V_56 , 0 ) ;
}
static int F_47 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_95 ) ;
}
static int F_48 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_96 ) ;
}
static void F_49 ( V_24 V_97 , unsigned long V_98 ,
unsigned long V_99 , struct V_100 * V_101 )
{
struct V_102 * V_103 = V_101 -> V_44 ;
struct V_38 * V_39 = V_103 -> V_39 ;
T_5 V_70 = F_50 ( V_39 , V_98 ) ;
struct V_104 * V_104 = NULL ;
int V_105 ;
if ( F_51 ( V_97 ) ) {
V_104 = F_52 ( V_39 , V_98 , V_97 ) ;
} else if ( F_53 ( V_97 ) ) {
T_6 V_106 = F_54 ( V_97 ) ;
if ( ! F_55 ( V_106 ) )
V_103 -> V_8 += V_99 ;
else if ( F_56 ( V_106 ) )
V_104 = F_57 ( V_106 ) ;
} else if ( F_58 ( V_97 ) ) {
if ( F_59 ( V_97 ) != V_70 )
V_103 -> V_107 += V_99 ;
}
if ( ! V_104 )
return;
if ( F_60 ( V_104 ) )
V_103 -> V_108 += V_99 ;
if ( V_104 -> V_109 != V_70 )
V_103 -> V_107 += V_99 ;
V_103 -> V_28 += V_99 ;
if ( F_61 ( V_97 ) || F_62 ( V_104 ) )
V_103 -> V_110 += V_99 ;
V_105 = F_63 ( V_104 ) ;
if ( V_105 >= 2 ) {
if ( F_64 ( V_97 ) || F_65 ( V_104 ) )
V_103 -> V_111 += V_99 ;
else
V_103 -> V_112 += V_99 ;
V_103 -> V_113 += ( V_99 << V_114 ) / V_105 ;
} else {
if ( F_64 ( V_97 ) || F_65 ( V_104 ) )
V_103 -> V_115 += V_99 ;
else
V_103 -> V_116 += V_99 ;
V_103 -> V_113 += ( V_99 << V_114 ) ;
}
}
static int F_66 ( T_7 * V_117 , unsigned long V_98 , unsigned long V_72 ,
struct V_100 * V_101 )
{
struct V_102 * V_103 = V_101 -> V_44 ;
struct V_38 * V_39 = V_103 -> V_39 ;
V_24 * V_118 ;
T_8 * V_119 ;
if ( F_67 ( V_117 , V_39 ) == 1 ) {
F_49 ( * ( V_24 * ) V_117 , V_98 , V_120 , V_101 ) ;
F_68 ( & V_101 -> V_4 -> V_121 ) ;
V_103 -> V_122 += V_120 ;
return 0 ;
}
if ( F_69 ( V_117 ) )
return 0 ;
V_118 = F_70 ( V_39 -> V_41 , V_117 , V_98 , & V_119 ) ;
for (; V_98 != V_72 ; V_118 ++ , V_98 += V_26 )
F_49 ( * V_118 , V_98 , V_26 , V_101 ) ;
F_71 ( V_118 - 1 , V_119 ) ;
F_72 () ;
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
static const char V_123 [ V_124 ] [ 2 ] = {
[ 0 ... ( V_124 - 1 ) ] = L_20 ,
[ F_74 ( V_84 ) ] = L_21 ,
[ F_74 ( V_85 ) ] = L_22 ,
[ F_74 ( V_86 ) ] = L_23 ,
[ F_74 ( V_125 ) ] = L_24 ,
[ F_74 ( V_126 ) ] = L_25 ,
[ F_74 ( V_127 ) ] = L_26 ,
[ F_74 ( V_128 ) ] = L_27 ,
[ F_74 ( V_87 ) ] = L_28 ,
[ F_74 ( V_129 ) ] = L_29 ,
[ F_74 ( V_130 ) ] = L_30 ,
[ F_74 ( V_131 ) ] = L_31 ,
[ F_74 ( V_132 ) ] = L_32 ,
[ F_74 ( V_133 ) ] = L_33 ,
[ F_74 ( V_134 ) ] = L_34 ,
[ F_74 ( V_135 ) ] = L_35 ,
[ F_74 ( V_136 ) ] = L_36 ,
[ F_74 ( V_137 ) ] = L_37 ,
[ F_74 ( V_138 ) ] = L_38 ,
[ F_74 ( V_139 ) ] = L_39 ,
[ F_74 ( V_140 ) ] = L_40 ,
[ F_74 ( V_141 ) ] = L_41 ,
[ F_74 ( V_142 ) ] = L_42 ,
[ F_74 ( V_143 ) ] = L_43 ,
[ F_74 ( V_144 ) ] = L_44 ,
[ F_74 ( V_145 ) ] = L_45 ,
[ F_74 ( V_146 ) ] = L_46 ,
[ F_74 ( V_147 ) ] = L_47 ,
} ;
T_9 V_148 ;
F_42 ( V_2 , L_48 ) ;
for ( V_148 = 0 ; V_148 < V_124 ; V_148 ++ ) {
if ( V_39 -> V_68 & ( 1UL << V_148 ) ) {
F_5 ( V_2 , L_49 ,
V_123 [ V_148 ] [ 0 ] , V_123 [ V_148 ] [ 1 ] ) ;
}
}
F_43 ( V_2 , '\n' ) ;
}
static int F_75 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_38 * V_39 = V_56 ;
struct V_102 V_103 ;
struct V_100 V_149 = {
. V_150 = F_66 ,
. V_4 = V_39 -> V_41 ,
. V_44 = & V_103 ,
} ;
memset ( & V_103 , 0 , sizeof V_103 ) ;
V_103 . V_39 = V_39 ;
if ( V_39 -> V_41 && ! F_76 ( V_39 ) )
F_77 ( V_39 -> V_82 , V_39 -> V_83 , & V_149 ) ;
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
( V_39 -> V_83 - V_39 -> V_82 ) >> 10 ,
V_103 . V_28 >> 10 ,
( unsigned long ) ( V_103 . V_113 >> ( 10 + V_114 ) ) ,
V_103 . V_112 >> 10 ,
V_103 . V_111 >> 10 ,
V_103 . V_116 >> 10 ,
V_103 . V_115 >> 10 ,
V_103 . V_110 >> 10 ,
V_103 . V_108 >> 10 ,
V_103 . V_122 >> 10 ,
V_103 . V_8 >> 10 ,
F_78 ( V_39 ) >> 10 ,
F_79 ( V_39 ) >> 10 ,
( V_39 -> V_68 & V_132 ) ?
( unsigned long ) ( V_103 . V_113 >> ( 10 + V_114 ) ) : 0 ) ;
if ( V_39 -> V_68 & V_141 )
F_5 ( V_2 , L_64 ,
V_103 . V_107 >> 10 ) ;
F_73 ( V_2 , V_39 ) ;
if ( V_2 -> V_93 < V_2 -> V_94 )
V_2 -> V_46 = ( V_39 != F_24 ( V_35 -> V_4 ) )
? V_39 -> V_82 : 0 ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , void * V_56 )
{
return F_75 ( V_2 , V_56 , 1 ) ;
}
static int F_81 ( struct V_1 * V_2 , void * V_56 )
{
return F_75 ( V_2 , V_56 , 0 ) ;
}
static int F_82 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_151 ) ;
}
static int F_83 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_152 ) ;
}
static int F_84 ( T_7 * V_117 , unsigned long V_98 ,
unsigned long V_72 , struct V_100 * V_101 )
{
struct V_38 * V_39 = V_101 -> V_44 ;
V_24 * V_118 , V_97 ;
T_8 * V_119 ;
struct V_104 * V_104 ;
F_85 ( V_39 , V_98 , V_117 ) ;
if ( F_69 ( V_117 ) )
return 0 ;
V_118 = F_70 ( V_39 -> V_41 , V_117 , V_98 , & V_119 ) ;
for (; V_98 != V_72 ; V_118 ++ , V_98 += V_26 ) {
V_97 = * V_118 ;
if ( ! F_51 ( V_97 ) )
continue;
V_104 = F_52 ( V_39 , V_98 , V_97 ) ;
if ( ! V_104 )
continue;
F_86 ( V_39 , V_98 , V_118 ) ;
F_87 ( V_104 ) ;
}
F_71 ( V_118 - 1 , V_119 ) ;
F_72 () ;
return 0 ;
}
static T_10 F_88 ( struct V_58 * V_58 , const char T_11 * V_153 ,
T_9 V_93 , T_1 * V_154 )
{
struct V_34 * V_35 ;
char V_155 [ V_156 ] ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
int type ;
int V_157 ;
memset ( V_155 , 0 , sizeof( V_155 ) ) ;
if ( V_93 > sizeof( V_155 ) - 1 )
V_93 = sizeof( V_155 ) - 1 ;
if ( F_89 ( V_155 , V_153 , V_93 ) )
return - V_158 ;
V_157 = F_90 ( F_91 ( V_155 ) , 10 , & type ) ;
if ( V_157 < 0 )
return V_157 ;
if ( type < V_159 || type > V_160 )
return - V_161 ;
V_35 = F_92 ( V_58 -> V_75 . V_76 -> V_77 ) ;
if ( ! V_35 )
return - V_50 ;
V_4 = F_93 ( V_35 ) ;
if ( V_4 ) {
struct V_100 V_162 = {
. V_150 = F_84 ,
. V_4 = V_4 ,
} ;
F_23 ( & V_4 -> V_42 ) ;
for ( V_39 = V_4 -> V_55 ; V_39 ; V_39 = V_39 -> V_52 ) {
V_162 . V_44 = V_39 ;
if ( F_76 ( V_39 ) )
continue;
if ( type == V_163 && V_39 -> V_66 )
continue;
if ( type == V_160 && ! V_39 -> V_66 )
continue;
F_77 ( V_39 -> V_82 , V_39 -> V_83 ,
& V_162 ) ;
}
F_94 ( V_4 ) ;
F_16 ( & V_4 -> V_42 ) ;
F_17 ( V_4 ) ;
}
F_28 ( V_35 ) ;
return V_93 ;
}
static inline T_12 F_95 ( T_13 V_164 )
{
return ( T_12 ) { . V_165 = V_164 } ;
}
static int F_96 ( unsigned long V_98 , T_12 * V_165 ,
struct V_166 * V_167 )
{
V_167 -> V_155 [ V_167 -> V_43 ++ ] = * V_165 ;
if ( V_167 -> V_43 >= V_167 -> V_31 )
return V_168 ;
return 0 ;
}
static int F_97 ( unsigned long V_71 , unsigned long V_72 ,
struct V_100 * V_101 )
{
struct V_166 * V_167 = V_101 -> V_44 ;
unsigned long V_98 ;
int V_169 = 0 ;
T_12 V_165 = F_95 ( V_170 ) ;
for ( V_98 = V_71 ; V_98 < V_72 ; V_98 += V_26 ) {
V_169 = F_96 ( V_98 , & V_165 , V_167 ) ;
if ( V_169 )
break;
}
return V_169 ;
}
static void F_98 ( T_12 * V_165 ,
struct V_38 * V_39 , unsigned long V_98 , V_24 V_118 )
{
T_13 V_171 , V_67 ;
struct V_104 * V_104 = NULL ;
if ( F_51 ( V_118 ) ) {
V_171 = F_99 ( V_118 ) ;
V_67 = V_172 ;
V_104 = F_52 ( V_39 , V_98 , V_118 ) ;
} else if ( F_53 ( V_118 ) ) {
T_6 V_173 = F_54 ( V_118 ) ;
V_171 = F_100 ( V_173 ) |
( F_101 ( V_173 ) << V_174 ) ;
V_67 = V_175 ;
if ( F_56 ( V_173 ) )
V_104 = F_57 ( V_173 ) ;
} else {
* V_165 = F_95 ( V_170 ) ;
return;
}
if ( V_104 && ! F_60 ( V_104 ) )
V_67 |= V_176 ;
* V_165 = F_95 ( F_102 ( V_171 ) | F_103 ( V_19 ) | V_67 ) ;
}
static void F_104 ( T_12 * V_165 ,
T_7 V_117 , int V_177 )
{
if ( F_105 ( V_117 ) )
* V_165 = F_95 ( F_102 ( F_106 ( V_117 ) + V_177 )
| F_103 ( V_19 ) | V_172 ) ;
else
* V_165 = F_95 ( V_170 ) ;
}
static inline void F_104 ( T_12 * V_165 ,
T_7 V_117 , int V_177 )
{
}
static int F_107 ( T_7 * V_117 , unsigned long V_98 , unsigned long V_72 ,
struct V_100 * V_101 )
{
struct V_38 * V_39 ;
struct V_166 * V_167 = V_101 -> V_44 ;
V_24 * V_118 ;
int V_169 = 0 ;
T_12 V_165 = F_95 ( V_170 ) ;
V_39 = F_25 ( V_101 -> V_4 , V_98 ) ;
if ( V_39 && F_67 ( V_117 , V_39 ) == 1 ) {
for (; V_98 != V_72 ; V_98 += V_26 ) {
unsigned long V_177 ;
V_177 = ( V_98 & ~ V_178 ) >>
V_19 ;
F_104 ( & V_165 , * V_117 , V_177 ) ;
V_169 = F_96 ( V_98 , & V_165 , V_167 ) ;
if ( V_169 )
break;
}
F_68 ( & V_101 -> V_4 -> V_121 ) ;
return V_169 ;
}
if ( F_69 ( V_117 ) )
return 0 ;
for (; V_98 != V_72 ; V_98 += V_26 ) {
if ( V_39 && ( V_98 >= V_39 -> V_83 ) ) {
V_39 = F_25 ( V_101 -> V_4 , V_98 ) ;
V_165 = F_95 ( V_170 ) ;
}
if ( V_39 && ( V_39 -> V_82 <= V_98 ) &&
! F_76 ( V_39 ) ) {
V_118 = F_108 ( V_117 , V_98 ) ;
F_98 ( & V_165 , V_39 , V_98 , * V_118 ) ;
F_109 ( V_118 ) ;
}
V_169 = F_96 ( V_98 , & V_165 , V_167 ) ;
if ( V_169 )
return V_169 ;
}
F_72 () ;
return V_169 ;
}
static void F_110 ( T_12 * V_165 ,
V_24 V_118 , int V_177 )
{
if ( F_51 ( V_118 ) )
* V_165 = F_95 ( F_102 ( F_99 ( V_118 ) + V_177 )
| F_103 ( V_19 ) | V_172 ) ;
else
* V_165 = F_95 ( V_170 ) ;
}
static int F_111 ( V_24 * V_118 , unsigned long V_179 ,
unsigned long V_98 , unsigned long V_72 ,
struct V_100 * V_101 )
{
struct V_166 * V_167 = V_101 -> V_44 ;
int V_169 = 0 ;
T_12 V_165 ;
for (; V_98 != V_72 ; V_98 += V_26 ) {
int V_177 = ( V_98 & ~ V_179 ) >> V_19 ;
F_110 ( & V_165 , * V_118 , V_177 ) ;
V_169 = F_96 ( V_98 , & V_165 , V_167 ) ;
if ( V_169 )
return V_169 ;
}
F_72 () ;
return V_169 ;
}
static T_10 F_112 ( struct V_58 * V_58 , char T_11 * V_153 ,
T_9 V_93 , T_1 * V_154 )
{
struct V_34 * V_35 = F_92 ( V_58 -> V_75 . V_76 -> V_77 ) ;
struct V_3 * V_4 ;
struct V_166 V_167 ;
int V_61 = - V_50 ;
struct V_100 V_180 = {} ;
unsigned long V_181 ;
unsigned long V_182 ;
unsigned long V_183 ;
unsigned long V_184 ;
int V_185 = 0 ;
if ( ! V_35 )
goto V_53;
V_61 = - V_161 ;
if ( ( * V_154 % V_186 ) || ( V_93 % V_186 ) )
goto V_187;
V_61 = 0 ;
if ( ! V_93 )
goto V_187;
V_167 . V_31 = V_186 * ( V_188 >> V_19 ) ;
V_167 . V_155 = F_113 ( V_167 . V_31 , V_189 ) ;
V_61 = - V_62 ;
if ( ! V_167 . V_155 )
goto V_187;
V_4 = F_21 ( V_35 , V_51 ) ;
V_61 = F_114 ( V_4 ) ;
if ( ! V_4 || F_22 ( V_4 ) )
goto V_190;
V_180 . V_150 = F_107 ;
V_180 . V_191 = F_97 ;
#ifdef F_115
V_180 . V_192 = F_111 ;
#endif
V_180 . V_4 = V_4 ;
V_180 . V_44 = & V_167 ;
V_181 = * V_154 ;
V_182 = V_181 / V_186 ;
V_183 = V_182 << V_19 ;
V_184 = F_116 ( V_35 ) ;
if ( V_182 > F_116 ( V_35 ) >> V_19 )
V_183 = V_184 ;
V_61 = 0 ;
while ( V_93 && ( V_183 < V_184 ) ) {
int V_31 ;
unsigned long V_72 ;
V_167 . V_43 = 0 ;
V_72 = ( V_183 + V_188 ) & V_178 ;
if ( V_72 < V_183 || V_72 > V_184 )
V_72 = V_184 ;
F_23 ( & V_4 -> V_42 ) ;
V_61 = F_77 ( V_183 , V_72 , & V_180 ) ;
F_16 ( & V_4 -> V_42 ) ;
V_183 = V_72 ;
V_31 = F_117 ( V_93 , V_186 * V_167 . V_43 ) ;
if ( F_118 ( V_153 , V_167 . V_155 , V_31 ) ) {
V_61 = - V_158 ;
goto V_193;
}
V_185 += V_31 ;
V_153 += V_31 ;
V_93 -= V_31 ;
}
* V_154 += V_185 ;
if ( ! V_61 || V_61 == V_168 )
V_61 = V_185 ;
V_193:
F_17 ( V_4 ) ;
V_190:
F_33 ( V_167 . V_155 ) ;
V_187:
F_28 ( V_35 ) ;
V_53:
return V_61 ;
}
static void F_119 ( struct V_104 * V_104 , struct V_194 * V_195 , int F_64 ,
unsigned long V_196 )
{
int V_93 = F_63 ( V_104 ) ;
V_195 -> V_197 += V_196 ;
if ( F_64 || F_65 ( V_104 ) )
V_195 -> V_198 += V_196 ;
if ( F_120 ( V_104 ) )
V_195 -> V_199 += V_196 ;
if ( F_121 ( V_104 ) || F_122 ( V_104 ) )
V_195 -> V_200 += V_196 ;
if ( F_123 ( V_104 ) )
V_195 -> V_201 += V_196 ;
if ( F_60 ( V_104 ) )
V_195 -> V_202 += V_196 ;
if ( V_93 > V_195 -> V_203 )
V_195 -> V_203 = V_93 ;
V_195 -> V_204 [ F_124 ( V_104 ) ] += V_196 ;
}
static struct V_104 * F_125 ( V_24 V_118 , struct V_38 * V_39 ,
unsigned long V_98 )
{
struct V_104 * V_104 ;
int V_205 ;
if ( ! F_51 ( V_118 ) )
return NULL ;
V_104 = F_52 ( V_39 , V_98 , V_118 ) ;
if ( ! V_104 )
return NULL ;
if ( F_126 ( V_104 ) )
return NULL ;
V_205 = F_124 ( V_104 ) ;
if ( ! F_127 ( V_205 , V_206 [ V_207 ] ) )
return NULL ;
return V_104 ;
}
static int F_128 ( T_7 * V_117 , unsigned long V_98 ,
unsigned long V_72 , struct V_100 * V_101 )
{
struct V_194 * V_195 ;
T_8 * V_119 ;
V_24 * V_208 ;
V_24 * V_118 ;
V_195 = V_101 -> V_44 ;
if ( F_67 ( V_117 , V_195 -> V_39 ) == 1 ) {
V_24 V_209 = * ( V_24 * ) V_117 ;
struct V_104 * V_104 ;
V_104 = F_125 ( V_209 , V_195 -> V_39 , V_98 ) ;
if ( V_104 )
F_119 ( V_104 , V_195 , F_64 ( V_209 ) ,
V_120 / V_26 ) ;
F_68 ( & V_101 -> V_4 -> V_121 ) ;
return 0 ;
}
if ( F_69 ( V_117 ) )
return 0 ;
V_208 = V_118 = F_70 ( V_101 -> V_4 , V_117 , V_98 , & V_119 ) ;
do {
struct V_104 * V_104 = F_125 ( * V_118 , V_195 -> V_39 , V_98 ) ;
if ( ! V_104 )
continue;
F_119 ( V_104 , V_195 , F_64 ( * V_118 ) , 1 ) ;
} while ( V_118 ++ , V_98 += V_26 , V_98 != V_72 );
F_71 ( V_208 , V_119 ) ;
return 0 ;
}
static int F_129 ( V_24 * V_118 , unsigned long V_179 ,
unsigned long V_98 , unsigned long V_72 , struct V_100 * V_101 )
{
struct V_194 * V_195 ;
struct V_104 * V_104 ;
if ( F_130 ( * V_118 ) )
return 0 ;
V_104 = F_131 ( * V_118 ) ;
if ( ! V_104 )
return 0 ;
V_195 = V_101 -> V_44 ;
F_119 ( V_104 , V_195 , F_64 ( * V_118 ) , 1 ) ;
return 0 ;
}
static int F_129 ( V_24 * V_118 , unsigned long V_179 ,
unsigned long V_98 , unsigned long V_72 , struct V_100 * V_101 )
{
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_210 * V_211 = V_2 -> V_44 ;
struct V_32 * V_212 = & V_211 -> V_213 ;
struct V_38 * V_39 = V_56 ;
struct V_194 * V_195 = & V_211 -> V_195 ;
struct V_58 * V_58 = V_39 -> V_66 ;
struct V_34 * V_35 = V_212 -> V_35 ;
struct V_3 * V_4 = V_39 -> V_41 ;
struct V_100 V_101 = {} ;
struct V_37 * V_214 ;
int V_215 ;
char V_155 [ 50 ] ;
if ( ! V_4 )
return 0 ;
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
V_195 -> V_39 = V_39 ;
V_101 . V_192 = F_129 ;
V_101 . V_150 = F_128 ;
V_101 . V_44 = V_195 ;
V_101 . V_4 = V_4 ;
V_214 = F_133 ( V_35 , V_39 , V_39 -> V_82 ) ;
F_134 ( V_155 , sizeof( V_155 ) , V_214 ) ;
F_135 ( V_214 ) ;
F_5 ( V_2 , L_65 , V_39 -> V_82 , V_155 ) ;
if ( V_58 ) {
F_5 ( V_2 , L_66 ) ;
F_39 ( V_2 , & V_58 -> V_75 , L_67 ) ;
} else if ( V_39 -> V_82 <= V_4 -> V_90 && V_39 -> V_83 >= V_4 -> V_91 ) {
F_5 ( V_2 , L_68 ) ;
} else {
T_4 V_89 = F_41 ( V_35 , V_39 , V_65 ) ;
if ( V_89 != 0 ) {
if ( ! V_65 || ( V_39 -> V_82 <= V_4 -> V_92 &&
V_39 -> V_83 >= V_4 -> V_92 ) )
F_5 ( V_2 , L_69 ) ;
else
F_5 ( V_2 , L_70 , V_89 ) ;
}
}
if ( F_76 ( V_39 ) )
F_5 ( V_2 , L_71 ) ;
F_77 ( V_39 -> V_82 , V_39 -> V_83 , & V_101 ) ;
if ( ! V_195 -> V_197 )
goto V_53;
if ( V_195 -> V_202 )
F_5 ( V_2 , L_72 , V_195 -> V_202 ) ;
if ( V_195 -> V_198 )
F_5 ( V_2 , L_73 , V_195 -> V_198 ) ;
if ( V_195 -> V_197 != V_195 -> V_202 && V_195 -> V_197 != V_195 -> V_198 )
F_5 ( V_2 , L_74 , V_195 -> V_197 ) ;
if ( V_195 -> V_203 > 1 )
F_5 ( V_2 , L_75 , V_195 -> V_203 ) ;
if ( V_195 -> V_199 )
F_5 ( V_2 , L_76 , V_195 -> V_199 ) ;
if ( V_195 -> V_200 < V_195 -> V_197 && ! F_76 ( V_39 ) )
F_5 ( V_2 , L_77 , V_195 -> V_200 ) ;
if ( V_195 -> V_201 )
F_5 ( V_2 , L_78 , V_195 -> V_201 ) ;
F_136 (n, N_MEMORY)
if ( V_195 -> V_204 [ V_215 ] )
F_5 ( V_2 , L_79 , V_215 , V_195 -> V_204 [ V_215 ] ) ;
V_53:
F_43 ( V_2 , '\n' ) ;
if ( V_2 -> V_93 < V_2 -> V_94 )
V_2 -> V_46 = ( V_39 != V_212 -> V_40 ) ? V_39 -> V_82 : 0 ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , void * V_56 )
{
return F_132 ( V_2 , V_56 , 1 ) ;
}
static int F_138 ( struct V_1 * V_2 , void * V_56 )
{
return F_132 ( V_2 , V_56 , 0 ) ;
}
static int F_139 ( struct V_57 * V_57 , struct V_58 * V_58 ,
const struct V_59 * V_60 )
{
struct V_210 * V_33 ;
int V_61 = - V_62 ;
V_33 = F_30 ( sizeof( * V_33 ) , V_63 ) ;
if ( V_33 ) {
V_33 -> V_213 . V_48 = F_31 ( V_57 ) ;
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
static int F_140 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_139 ( V_57 , V_58 , & V_216 ) ;
}
static int F_141 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_139 ( V_57 , V_58 , & V_217 ) ;
}
