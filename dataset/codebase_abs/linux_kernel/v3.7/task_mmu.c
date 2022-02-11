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
static int F_73 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_32 * V_33 = V_2 -> V_44 ;
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_38 * V_39 = V_56 ;
struct V_102 V_103 ;
struct V_100 V_123 = {
. V_124 = F_66 ,
. V_4 = V_39 -> V_41 ,
. V_44 = & V_103 ,
} ;
memset ( & V_103 , 0 , sizeof V_103 ) ;
V_103 . V_39 = V_39 ;
if ( V_39 -> V_41 && ! F_74 ( V_39 ) )
F_75 ( V_39 -> V_82 , V_39 -> V_83 , & V_123 ) ;
F_34 ( V_2 , V_39 , V_65 ) ;
F_5 ( V_2 ,
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33 ,
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
F_76 ( V_39 ) >> 10 ,
F_77 ( V_39 ) >> 10 ,
( V_39 -> V_68 & V_125 ) ?
( unsigned long ) ( V_103 . V_113 >> ( 10 + V_114 ) ) : 0 ) ;
if ( V_39 -> V_68 & V_126 )
F_5 ( V_2 , L_34 ,
V_103 . V_107 >> 10 ) ;
if ( V_2 -> V_93 < V_2 -> V_94 )
V_2 -> V_46 = ( V_39 != F_24 ( V_35 -> V_4 ) )
? V_39 -> V_82 : 0 ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 , void * V_56 )
{
return F_73 ( V_2 , V_56 , 1 ) ;
}
static int F_79 ( struct V_1 * V_2 , void * V_56 )
{
return F_73 ( V_2 , V_56 , 0 ) ;
}
static int F_80 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_127 ) ;
}
static int F_81 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_29 ( V_57 , V_58 , & V_128 ) ;
}
static int F_82 ( T_7 * V_117 , unsigned long V_98 ,
unsigned long V_72 , struct V_100 * V_101 )
{
struct V_38 * V_39 = V_101 -> V_44 ;
V_24 * V_118 , V_97 ;
T_8 * V_119 ;
struct V_104 * V_104 ;
F_83 ( V_101 -> V_4 , V_117 ) ;
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
F_84 ( V_39 , V_98 , V_118 ) ;
F_85 ( V_104 ) ;
}
F_71 ( V_118 - 1 , V_119 ) ;
F_72 () ;
return 0 ;
}
static T_9 F_86 ( struct V_58 * V_58 , const char T_10 * V_129 ,
T_11 V_93 , T_1 * V_130 )
{
struct V_34 * V_35 ;
char V_131 [ V_132 ] ;
struct V_3 * V_4 ;
struct V_38 * V_39 ;
int type ;
int V_133 ;
memset ( V_131 , 0 , sizeof( V_131 ) ) ;
if ( V_93 > sizeof( V_131 ) - 1 )
V_93 = sizeof( V_131 ) - 1 ;
if ( F_87 ( V_131 , V_129 , V_93 ) )
return - V_134 ;
V_133 = F_88 ( F_89 ( V_131 ) , 10 , & type ) ;
if ( V_133 < 0 )
return V_133 ;
if ( type < V_135 || type > V_136 )
return - V_137 ;
V_35 = F_90 ( V_58 -> V_75 . V_76 -> V_77 ) ;
if ( ! V_35 )
return - V_50 ;
V_4 = F_91 ( V_35 ) ;
if ( V_4 ) {
struct V_100 V_138 = {
. V_124 = F_82 ,
. V_4 = V_4 ,
} ;
F_23 ( & V_4 -> V_42 ) ;
for ( V_39 = V_4 -> V_55 ; V_39 ; V_39 = V_39 -> V_52 ) {
V_138 . V_44 = V_39 ;
if ( F_74 ( V_39 ) )
continue;
if ( type == V_139 && V_39 -> V_66 )
continue;
if ( type == V_136 && ! V_39 -> V_66 )
continue;
F_75 ( V_39 -> V_82 , V_39 -> V_83 ,
& V_138 ) ;
}
F_92 ( V_4 ) ;
F_16 ( & V_4 -> V_42 ) ;
F_17 ( V_4 ) ;
}
F_28 ( V_35 ) ;
return V_93 ;
}
static inline T_12 F_93 ( T_13 V_140 )
{
return ( T_12 ) { . V_141 = V_140 } ;
}
static int F_94 ( unsigned long V_98 , T_12 * V_141 ,
struct V_142 * V_143 )
{
V_143 -> V_131 [ V_143 -> V_43 ++ ] = * V_141 ;
if ( V_143 -> V_43 >= V_143 -> V_31 )
return V_144 ;
return 0 ;
}
static int F_95 ( unsigned long V_71 , unsigned long V_72 ,
struct V_100 * V_101 )
{
struct V_142 * V_143 = V_101 -> V_44 ;
unsigned long V_98 ;
int V_145 = 0 ;
T_12 V_141 = F_93 ( V_146 ) ;
for ( V_98 = V_71 ; V_98 < V_72 ; V_98 += V_26 ) {
V_145 = F_94 ( V_98 , & V_141 , V_143 ) ;
if ( V_145 )
break;
}
return V_145 ;
}
static void F_96 ( T_12 * V_141 ,
struct V_38 * V_39 , unsigned long V_98 , V_24 V_118 )
{
T_13 V_147 , V_67 ;
struct V_104 * V_104 = NULL ;
if ( F_51 ( V_118 ) ) {
V_147 = F_97 ( V_118 ) ;
V_67 = V_148 ;
V_104 = F_52 ( V_39 , V_98 , V_118 ) ;
} else if ( F_53 ( V_118 ) ) {
T_6 V_149 = F_54 ( V_118 ) ;
V_147 = F_98 ( V_149 ) |
( F_99 ( V_149 ) << V_150 ) ;
V_67 = V_151 ;
if ( F_56 ( V_149 ) )
V_104 = F_57 ( V_149 ) ;
} else {
* V_141 = F_93 ( V_146 ) ;
return;
}
if ( V_104 && ! F_60 ( V_104 ) )
V_67 |= V_152 ;
* V_141 = F_93 ( F_100 ( V_147 ) | F_101 ( V_19 ) | V_67 ) ;
}
static void F_102 ( T_12 * V_141 ,
T_7 V_117 , int V_153 )
{
if ( F_103 ( V_117 ) )
* V_141 = F_93 ( F_100 ( F_104 ( V_117 ) + V_153 )
| F_101 ( V_19 ) | V_148 ) ;
else
* V_141 = F_93 ( V_146 ) ;
}
static inline void F_102 ( T_12 * V_141 ,
T_7 V_117 , int V_153 )
{
}
static int F_105 ( T_7 * V_117 , unsigned long V_98 , unsigned long V_72 ,
struct V_100 * V_101 )
{
struct V_38 * V_39 ;
struct V_142 * V_143 = V_101 -> V_44 ;
V_24 * V_118 ;
int V_145 = 0 ;
T_12 V_141 = F_93 ( V_146 ) ;
V_39 = F_25 ( V_101 -> V_4 , V_98 ) ;
if ( V_39 && F_67 ( V_117 , V_39 ) == 1 ) {
for (; V_98 != V_72 ; V_98 += V_26 ) {
unsigned long V_153 ;
V_153 = ( V_98 & ~ V_154 ) >>
V_19 ;
F_102 ( & V_141 , * V_117 , V_153 ) ;
V_145 = F_94 ( V_98 , & V_141 , V_143 ) ;
if ( V_145 )
break;
}
F_68 ( & V_101 -> V_4 -> V_121 ) ;
return V_145 ;
}
if ( F_69 ( V_117 ) )
return 0 ;
for (; V_98 != V_72 ; V_98 += V_26 ) {
if ( V_39 && ( V_98 >= V_39 -> V_83 ) ) {
V_39 = F_25 ( V_101 -> V_4 , V_98 ) ;
V_141 = F_93 ( V_146 ) ;
}
if ( V_39 && ( V_39 -> V_82 <= V_98 ) &&
! F_74 ( V_39 ) ) {
V_118 = F_106 ( V_117 , V_98 ) ;
F_96 ( & V_141 , V_39 , V_98 , * V_118 ) ;
F_107 ( V_118 ) ;
}
V_145 = F_94 ( V_98 , & V_141 , V_143 ) ;
if ( V_145 )
return V_145 ;
}
F_72 () ;
return V_145 ;
}
static void F_108 ( T_12 * V_141 ,
V_24 V_118 , int V_153 )
{
if ( F_51 ( V_118 ) )
* V_141 = F_93 ( F_100 ( F_97 ( V_118 ) + V_153 )
| F_101 ( V_19 ) | V_148 ) ;
else
* V_141 = F_93 ( V_146 ) ;
}
static int F_109 ( V_24 * V_118 , unsigned long V_155 ,
unsigned long V_98 , unsigned long V_72 ,
struct V_100 * V_101 )
{
struct V_142 * V_143 = V_101 -> V_44 ;
int V_145 = 0 ;
T_12 V_141 ;
for (; V_98 != V_72 ; V_98 += V_26 ) {
int V_153 = ( V_98 & ~ V_155 ) >> V_19 ;
F_108 ( & V_141 , * V_118 , V_153 ) ;
V_145 = F_94 ( V_98 , & V_141 , V_143 ) ;
if ( V_145 )
return V_145 ;
}
F_72 () ;
return V_145 ;
}
static T_9 F_110 ( struct V_58 * V_58 , char T_10 * V_129 ,
T_11 V_93 , T_1 * V_130 )
{
struct V_34 * V_35 = F_90 ( V_58 -> V_75 . V_76 -> V_77 ) ;
struct V_3 * V_4 ;
struct V_142 V_143 ;
int V_61 = - V_50 ;
struct V_100 V_156 = {} ;
unsigned long V_157 ;
unsigned long V_158 ;
unsigned long V_159 ;
unsigned long V_160 ;
int V_161 = 0 ;
if ( ! V_35 )
goto V_53;
V_61 = - V_137 ;
if ( ( * V_130 % V_162 ) || ( V_93 % V_162 ) )
goto V_163;
V_61 = 0 ;
if ( ! V_93 )
goto V_163;
V_143 . V_31 = V_162 * ( V_164 >> V_19 ) ;
V_143 . V_131 = F_111 ( V_143 . V_31 , V_165 ) ;
V_61 = - V_62 ;
if ( ! V_143 . V_131 )
goto V_163;
V_4 = F_21 ( V_35 , V_51 ) ;
V_61 = F_112 ( V_4 ) ;
if ( ! V_4 || F_22 ( V_4 ) )
goto V_166;
V_156 . V_124 = F_105 ;
V_156 . V_167 = F_95 ;
#ifdef F_113
V_156 . V_168 = F_109 ;
#endif
V_156 . V_4 = V_4 ;
V_156 . V_44 = & V_143 ;
V_157 = * V_130 ;
V_158 = V_157 / V_162 ;
V_159 = V_158 << V_19 ;
V_160 = F_114 ( V_35 ) ;
if ( V_158 > F_114 ( V_35 ) >> V_19 )
V_159 = V_160 ;
V_61 = 0 ;
while ( V_93 && ( V_159 < V_160 ) ) {
int V_31 ;
unsigned long V_72 ;
V_143 . V_43 = 0 ;
V_72 = ( V_159 + V_164 ) & V_154 ;
if ( V_72 < V_159 || V_72 > V_160 )
V_72 = V_160 ;
F_23 ( & V_4 -> V_42 ) ;
V_61 = F_75 ( V_159 , V_72 , & V_156 ) ;
F_16 ( & V_4 -> V_42 ) ;
V_159 = V_72 ;
V_31 = F_115 ( V_93 , V_162 * V_143 . V_43 ) ;
if ( F_116 ( V_129 , V_143 . V_131 , V_31 ) ) {
V_61 = - V_134 ;
goto V_169;
}
V_161 += V_31 ;
V_129 += V_31 ;
V_93 -= V_31 ;
}
* V_130 += V_161 ;
if ( ! V_61 || V_61 == V_144 )
V_61 = V_161 ;
V_169:
F_17 ( V_4 ) ;
V_166:
F_33 ( V_143 . V_131 ) ;
V_163:
F_28 ( V_35 ) ;
V_53:
return V_61 ;
}
static void F_117 ( struct V_104 * V_104 , struct V_170 * V_171 , int F_64 ,
unsigned long V_172 )
{
int V_93 = F_63 ( V_104 ) ;
V_171 -> V_173 += V_172 ;
if ( F_64 || F_65 ( V_104 ) )
V_171 -> V_174 += V_172 ;
if ( F_118 ( V_104 ) )
V_171 -> V_175 += V_172 ;
if ( F_119 ( V_104 ) || F_120 ( V_104 ) )
V_171 -> V_176 += V_172 ;
if ( F_121 ( V_104 ) )
V_171 -> V_177 += V_172 ;
if ( F_60 ( V_104 ) )
V_171 -> V_178 += V_172 ;
if ( V_93 > V_171 -> V_179 )
V_171 -> V_179 = V_93 ;
V_171 -> V_180 [ F_122 ( V_104 ) ] += V_172 ;
}
static struct V_104 * F_123 ( V_24 V_118 , struct V_38 * V_39 ,
unsigned long V_98 )
{
struct V_104 * V_104 ;
int V_181 ;
if ( ! F_51 ( V_118 ) )
return NULL ;
V_104 = F_52 ( V_39 , V_98 , V_118 ) ;
if ( ! V_104 )
return NULL ;
if ( F_124 ( V_104 ) )
return NULL ;
V_181 = F_122 ( V_104 ) ;
if ( ! F_125 ( V_181 , V_182 [ V_183 ] ) )
return NULL ;
return V_104 ;
}
static int F_126 ( T_7 * V_117 , unsigned long V_98 ,
unsigned long V_72 , struct V_100 * V_101 )
{
struct V_170 * V_171 ;
T_8 * V_119 ;
V_24 * V_184 ;
V_24 * V_118 ;
V_171 = V_101 -> V_44 ;
if ( F_67 ( V_117 , V_171 -> V_39 ) == 1 ) {
V_24 V_185 = * ( V_24 * ) V_117 ;
struct V_104 * V_104 ;
V_104 = F_123 ( V_185 , V_171 -> V_39 , V_98 ) ;
if ( V_104 )
F_117 ( V_104 , V_171 , F_64 ( V_185 ) ,
V_120 / V_26 ) ;
F_68 ( & V_101 -> V_4 -> V_121 ) ;
return 0 ;
}
if ( F_69 ( V_117 ) )
return 0 ;
V_184 = V_118 = F_70 ( V_101 -> V_4 , V_117 , V_98 , & V_119 ) ;
do {
struct V_104 * V_104 = F_123 ( * V_118 , V_171 -> V_39 , V_98 ) ;
if ( ! V_104 )
continue;
F_117 ( V_104 , V_171 , F_64 ( * V_118 ) , 1 ) ;
} while ( V_118 ++ , V_98 += V_26 , V_98 != V_72 );
F_71 ( V_184 , V_119 ) ;
return 0 ;
}
static int F_127 ( V_24 * V_118 , unsigned long V_155 ,
unsigned long V_98 , unsigned long V_72 , struct V_100 * V_101 )
{
struct V_170 * V_171 ;
struct V_104 * V_104 ;
if ( F_128 ( * V_118 ) )
return 0 ;
V_104 = F_129 ( * V_118 ) ;
if ( ! V_104 )
return 0 ;
V_171 = V_101 -> V_44 ;
F_117 ( V_104 , V_171 , F_64 ( * V_118 ) , 1 ) ;
return 0 ;
}
static int F_127 ( V_24 * V_118 , unsigned long V_155 ,
unsigned long V_98 , unsigned long V_72 , struct V_100 * V_101 )
{
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , void * V_56 , int V_65 )
{
struct V_186 * V_187 = V_2 -> V_44 ;
struct V_32 * V_188 = & V_187 -> V_189 ;
struct V_38 * V_39 = V_56 ;
struct V_170 * V_171 = & V_187 -> V_171 ;
struct V_58 * V_58 = V_39 -> V_66 ;
struct V_34 * V_35 = V_188 -> V_35 ;
struct V_3 * V_4 = V_39 -> V_41 ;
struct V_100 V_101 = {} ;
struct V_37 * V_190 ;
int V_191 ;
char V_131 [ 50 ] ;
if ( ! V_4 )
return 0 ;
memset ( V_171 , 0 , sizeof( * V_171 ) ) ;
V_171 -> V_39 = V_39 ;
V_101 . V_168 = F_127 ;
V_101 . V_124 = F_126 ;
V_101 . V_44 = V_171 ;
V_101 . V_4 = V_4 ;
V_190 = F_131 ( V_35 , V_39 , V_39 -> V_82 ) ;
F_132 ( V_131 , sizeof( V_131 ) , V_190 , 0 ) ;
F_133 ( V_190 ) ;
F_5 ( V_2 , L_35 , V_39 -> V_82 , V_131 ) ;
if ( V_58 ) {
F_5 ( V_2 , L_36 ) ;
F_39 ( V_2 , & V_58 -> V_75 , L_37 ) ;
} else if ( V_39 -> V_82 <= V_4 -> V_90 && V_39 -> V_83 >= V_4 -> V_91 ) {
F_5 ( V_2 , L_38 ) ;
} else {
T_4 V_89 = F_41 ( V_35 , V_39 , V_65 ) ;
if ( V_89 != 0 ) {
if ( ! V_65 || ( V_39 -> V_82 <= V_4 -> V_92 &&
V_39 -> V_83 >= V_4 -> V_92 ) )
F_5 ( V_2 , L_39 ) ;
else
F_5 ( V_2 , L_40 , V_89 ) ;
}
}
if ( F_74 ( V_39 ) )
F_5 ( V_2 , L_41 ) ;
F_75 ( V_39 -> V_82 , V_39 -> V_83 , & V_101 ) ;
if ( ! V_171 -> V_173 )
goto V_53;
if ( V_171 -> V_178 )
F_5 ( V_2 , L_42 , V_171 -> V_178 ) ;
if ( V_171 -> V_174 )
F_5 ( V_2 , L_43 , V_171 -> V_174 ) ;
if ( V_171 -> V_173 != V_171 -> V_178 && V_171 -> V_173 != V_171 -> V_174 )
F_5 ( V_2 , L_44 , V_171 -> V_173 ) ;
if ( V_171 -> V_179 > 1 )
F_5 ( V_2 , L_45 , V_171 -> V_179 ) ;
if ( V_171 -> V_175 )
F_5 ( V_2 , L_46 , V_171 -> V_175 ) ;
if ( V_171 -> V_176 < V_171 -> V_173 && ! F_74 ( V_39 ) )
F_5 ( V_2 , L_47 , V_171 -> V_176 ) ;
if ( V_171 -> V_177 )
F_5 ( V_2 , L_48 , V_171 -> V_177 ) ;
F_134 (n, N_HIGH_MEMORY)
if ( V_171 -> V_180 [ V_191 ] )
F_5 ( V_2 , L_49 , V_191 , V_171 -> V_180 [ V_191 ] ) ;
V_53:
F_43 ( V_2 , '\n' ) ;
if ( V_2 -> V_93 < V_2 -> V_94 )
V_2 -> V_46 = ( V_39 != V_188 -> V_40 ) ? V_39 -> V_82 : 0 ;
return 0 ;
}
static int F_135 ( struct V_1 * V_2 , void * V_56 )
{
return F_130 ( V_2 , V_56 , 1 ) ;
}
static int F_136 ( struct V_1 * V_2 , void * V_56 )
{
return F_130 ( V_2 , V_56 , 0 ) ;
}
static int F_137 ( struct V_57 * V_57 , struct V_58 * V_58 ,
const struct V_59 * V_60 )
{
struct V_186 * V_33 ;
int V_61 = - V_62 ;
V_33 = F_30 ( sizeof( * V_33 ) , V_63 ) ;
if ( V_33 ) {
V_33 -> V_189 . V_48 = F_31 ( V_57 ) ;
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
static int F_138 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_137 ( V_57 , V_58 , & V_192 ) ;
}
static int F_139 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_137 ( V_57 , V_58 , & V_193 ) ;
}
