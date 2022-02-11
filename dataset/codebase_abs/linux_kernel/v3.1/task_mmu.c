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
L_11 ,
V_9 << ( V_19 - 10 ) ,
( V_10 - V_4 -> V_21 ) << ( V_19 - 10 ) ,
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
F_5 ( V_2 , L_12 , V_31 , ' ' ) ;
}
static void F_9 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
if ( V_35 && V_35 != V_33 -> V_36 ) {
struct V_3 * V_4 = V_35 -> V_37 ;
F_10 ( & V_4 -> V_38 ) ;
F_11 ( V_4 ) ;
}
}
static void * F_12 ( struct V_1 * V_2 , T_1 * V_39 )
{
struct V_32 * V_33 = V_2 -> V_40 ;
unsigned long V_41 = V_2 -> V_42 ;
struct V_3 * V_4 ;
struct V_34 * V_35 , * V_36 = NULL ;
T_1 V_43 = * V_39 ;
V_33 -> V_44 = NULL ;
V_33 -> V_36 = NULL ;
if ( V_41 == - 1UL )
return NULL ;
V_33 -> V_44 = F_13 ( V_33 -> V_45 , V_46 ) ;
if ( ! V_33 -> V_44 )
return F_14 ( - V_47 ) ;
V_4 = F_15 ( V_33 -> V_44 ) ;
if ( ! V_4 || F_16 ( V_4 ) )
return V_4 ;
F_17 ( & V_4 -> V_38 ) ;
V_36 = F_18 ( V_33 -> V_44 -> V_4 ) ;
V_33 -> V_36 = V_36 ;
V_35 = F_19 ( V_4 , V_41 ) ;
if ( V_41 && V_35 ) {
V_35 = V_35 -> V_48 ;
goto V_49;
}
V_35 = NULL ;
if ( ( unsigned long ) V_43 < V_4 -> V_50 ) {
V_35 = V_4 -> V_51 ;
while ( V_43 -- && V_35 )
V_35 = V_35 -> V_48 ;
goto V_49;
}
if ( V_43 != V_4 -> V_50 )
V_36 = NULL ;
V_49:
if ( V_35 )
return V_35 ;
V_2 -> V_42 = ( V_36 != NULL ) ? 0 : - 1UL ;
F_10 ( & V_4 -> V_38 ) ;
F_11 ( V_4 ) ;
return V_36 ;
}
static void * F_20 ( struct V_1 * V_2 , void * V_52 , T_1 * V_39 )
{
struct V_32 * V_33 = V_2 -> V_40 ;
struct V_34 * V_35 = V_52 ;
struct V_34 * V_36 = V_33 -> V_36 ;
( * V_39 ) ++ ;
if ( V_35 && ( V_35 != V_36 ) && V_35 -> V_48 )
return V_35 -> V_48 ;
F_9 ( V_33 , V_35 ) ;
return ( V_35 != V_36 ) ? V_36 : NULL ;
}
static void F_21 ( struct V_1 * V_2 , void * V_52 )
{
struct V_32 * V_33 = V_2 -> V_40 ;
struct V_34 * V_35 = V_52 ;
if ( ! F_16 ( V_35 ) )
F_9 ( V_33 , V_35 ) ;
if ( V_33 -> V_44 )
F_22 ( V_33 -> V_44 ) ;
}
static int F_23 ( struct V_53 * V_53 , struct V_54 * V_54 ,
const struct V_55 * V_56 )
{
struct V_32 * V_33 ;
int V_57 = - V_58 ;
V_33 = F_24 ( sizeof( * V_33 ) , V_59 ) ;
if ( V_33 ) {
V_33 -> V_45 = F_25 ( V_53 ) ;
V_57 = F_26 ( V_54 , V_56 ) ;
if ( ! V_57 ) {
struct V_1 * V_2 = V_54 -> V_60 ;
V_2 -> V_40 = V_33 ;
} else {
F_27 ( V_33 ) ;
}
}
return V_57 ;
}
static void F_28 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_3 * V_4 = V_35 -> V_37 ;
struct V_54 * V_54 = V_35 -> V_61 ;
T_2 V_62 = V_35 -> V_63 ;
unsigned long V_64 = 0 ;
unsigned long long V_65 = 0 ;
unsigned long V_66 , V_67 ;
T_3 V_68 = 0 ;
int V_31 ;
if ( V_54 ) {
struct V_53 * V_53 = V_35 -> V_61 -> V_69 . V_70 -> V_71 ;
V_68 = V_53 -> V_72 -> V_73 ;
V_64 = V_53 -> V_74 ;
V_65 = ( ( T_1 ) V_35 -> V_75 ) << V_19 ;
}
V_66 = V_35 -> V_76 ;
if ( F_29 ( V_35 , V_66 ) )
V_66 += V_26 ;
V_67 = V_35 -> V_77 ;
if ( F_30 ( V_35 , V_67 ) )
V_67 -= V_26 ;
F_5 ( V_2 , L_13 ,
V_66 ,
V_67 ,
V_62 & V_78 ? 'r' : '-' ,
V_62 & V_79 ? 'w' : '-' ,
V_62 & V_80 ? 'x' : '-' ,
V_62 & V_81 ? 's' : 'p' ,
V_65 ,
F_31 ( V_68 ) , F_32 ( V_68 ) , V_64 , & V_31 ) ;
if ( V_54 ) {
F_8 ( V_2 , V_31 ) ;
F_33 ( V_2 , & V_54 -> V_69 , L_14 ) ;
} else {
const char * V_82 = F_34 ( V_35 ) ;
if ( ! V_82 ) {
if ( V_4 ) {
if ( V_35 -> V_76 <= V_4 -> V_83 &&
V_35 -> V_77 >= V_4 -> V_84 ) {
V_82 = L_15 ;
} else if ( V_35 -> V_76 <= V_4 -> V_85 &&
V_35 -> V_77 >= V_4 -> V_85 ) {
V_82 = L_16 ;
}
} else {
V_82 = L_17 ;
}
}
if ( V_82 ) {
F_8 ( V_2 , V_31 ) ;
F_35 ( V_2 , V_82 ) ;
}
}
F_36 ( V_2 , '\n' ) ;
}
static int F_37 ( struct V_1 * V_2 , void * V_52 )
{
struct V_34 * V_35 = V_52 ;
struct V_32 * V_33 = V_2 -> V_40 ;
struct V_86 * V_44 = V_33 -> V_44 ;
F_28 ( V_2 , V_35 ) ;
if ( V_2 -> V_87 < V_2 -> V_88 )
V_2 -> V_42 = ( V_35 != F_18 ( V_44 -> V_4 ) )
? V_35 -> V_76 : 0 ;
return 0 ;
}
static int F_38 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
return F_23 ( V_53 , V_54 , & V_89 ) ;
}
static void F_39 ( V_24 V_90 , unsigned long V_91 ,
unsigned long V_92 , struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_40 ;
struct V_34 * V_35 = V_96 -> V_35 ;
struct V_97 * V_97 ;
int V_98 ;
if ( F_40 ( V_90 ) ) {
V_96 -> V_8 += V_92 ;
return;
}
if ( ! F_41 ( V_90 ) )
return;
V_97 = F_42 ( V_35 , V_91 , V_90 ) ;
if ( ! V_97 )
return;
if ( F_43 ( V_97 ) )
V_96 -> V_99 += V_92 ;
V_96 -> V_28 += V_92 ;
if ( F_44 ( V_90 ) || F_45 ( V_97 ) )
V_96 -> V_100 += V_92 ;
V_98 = F_46 ( V_97 ) ;
if ( V_98 >= 2 ) {
if ( F_47 ( V_90 ) || F_48 ( V_97 ) )
V_96 -> V_101 += V_92 ;
else
V_96 -> V_102 += V_92 ;
V_96 -> V_103 += ( V_92 << V_104 ) / V_98 ;
} else {
if ( F_47 ( V_90 ) || F_48 ( V_97 ) )
V_96 -> V_105 += V_92 ;
else
V_96 -> V_106 += V_92 ;
V_96 -> V_103 += ( V_92 << V_104 ) ;
}
}
static int F_49 ( T_4 * V_107 , unsigned long V_91 , unsigned long V_67 ,
struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_40 ;
struct V_34 * V_35 = V_96 -> V_35 ;
V_24 * V_108 ;
T_5 * V_109 ;
F_50 ( & V_94 -> V_4 -> V_110 ) ;
if ( F_51 ( * V_107 ) ) {
if ( F_52 ( * V_107 ) ) {
F_53 ( & V_94 -> V_4 -> V_110 ) ;
F_54 ( V_35 -> V_111 , V_107 ) ;
} else {
F_39 ( * ( V_24 * ) V_107 , V_91 ,
V_112 , V_94 ) ;
F_53 ( & V_94 -> V_4 -> V_110 ) ;
V_96 -> V_113 += V_112 ;
return 0 ;
}
} else {
F_53 ( & V_94 -> V_4 -> V_110 ) ;
}
V_108 = F_55 ( V_35 -> V_37 , V_107 , V_91 , & V_109 ) ;
for (; V_91 != V_67 ; V_108 ++ , V_91 += V_26 )
F_39 ( * V_108 , V_91 , V_26 , V_94 ) ;
F_56 ( V_108 - 1 , V_109 ) ;
F_57 () ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , void * V_52 )
{
struct V_32 * V_33 = V_2 -> V_40 ;
struct V_86 * V_44 = V_33 -> V_44 ;
struct V_34 * V_35 = V_52 ;
struct V_95 V_96 ;
struct V_93 V_114 = {
. V_115 = F_49 ,
. V_4 = V_35 -> V_37 ,
. V_40 = & V_96 ,
} ;
memset ( & V_96 , 0 , sizeof V_96 ) ;
V_96 . V_35 = V_35 ;
if ( V_35 -> V_37 && ! F_59 ( V_35 ) )
F_60 ( V_35 -> V_76 , V_35 -> V_77 , & V_114 ) ;
F_28 ( V_2 , V_35 ) ;
F_5 ( V_2 ,
L_18
L_19
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
L_31 ,
( V_35 -> V_77 - V_35 -> V_76 ) >> 10 ,
V_96 . V_28 >> 10 ,
( unsigned long ) ( V_96 . V_103 >> ( 10 + V_104 ) ) ,
V_96 . V_102 >> 10 ,
V_96 . V_101 >> 10 ,
V_96 . V_106 >> 10 ,
V_96 . V_105 >> 10 ,
V_96 . V_100 >> 10 ,
V_96 . V_99 >> 10 ,
V_96 . V_113 >> 10 ,
V_96 . V_8 >> 10 ,
F_61 ( V_35 ) >> 10 ,
F_62 ( V_35 ) >> 10 ,
( V_35 -> V_63 & V_116 ) ?
( unsigned long ) ( V_96 . V_103 >> ( 10 + V_104 ) ) : 0 ) ;
if ( V_2 -> V_87 < V_2 -> V_88 )
V_2 -> V_42 = ( V_35 != F_18 ( V_44 -> V_4 ) )
? V_35 -> V_76 : 0 ;
return 0 ;
}
static int F_63 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
return F_23 ( V_53 , V_54 , & V_117 ) ;
}
static int F_64 ( T_4 * V_107 , unsigned long V_91 ,
unsigned long V_67 , struct V_93 * V_94 )
{
struct V_34 * V_35 = V_94 -> V_40 ;
V_24 * V_108 , V_90 ;
T_5 * V_109 ;
struct V_97 * V_97 ;
F_65 ( V_94 -> V_4 , V_107 ) ;
V_108 = F_55 ( V_35 -> V_37 , V_107 , V_91 , & V_109 ) ;
for (; V_91 != V_67 ; V_108 ++ , V_91 += V_26 ) {
V_90 = * V_108 ;
if ( ! F_41 ( V_90 ) )
continue;
V_97 = F_42 ( V_35 , V_91 , V_90 ) ;
if ( ! V_97 )
continue;
F_66 ( V_35 , V_91 , V_108 ) ;
F_67 ( V_97 ) ;
}
F_56 ( V_108 - 1 , V_109 ) ;
F_57 () ;
return 0 ;
}
static T_6 F_68 ( struct V_54 * V_54 , const char T_7 * V_118 ,
T_8 V_87 , T_1 * V_119 )
{
struct V_86 * V_44 ;
char V_120 [ V_121 ] ;
struct V_3 * V_4 ;
struct V_34 * V_35 ;
int type ;
int V_122 ;
memset ( V_120 , 0 , sizeof( V_120 ) ) ;
if ( V_87 > sizeof( V_120 ) - 1 )
V_87 = sizeof( V_120 ) - 1 ;
if ( F_69 ( V_120 , V_118 , V_87 ) )
return - V_123 ;
V_122 = F_70 ( F_71 ( V_120 ) , 10 , & type ) ;
if ( V_122 < 0 )
return V_122 ;
if ( type < V_124 || type > V_125 )
return - V_126 ;
V_44 = F_72 ( V_54 -> V_69 . V_70 -> V_71 ) ;
if ( ! V_44 )
return - V_47 ;
V_4 = F_73 ( V_44 ) ;
if ( V_4 ) {
struct V_93 V_127 = {
. V_115 = F_64 ,
. V_4 = V_4 ,
} ;
F_17 ( & V_4 -> V_38 ) ;
for ( V_35 = V_4 -> V_51 ; V_35 ; V_35 = V_35 -> V_48 ) {
V_127 . V_40 = V_35 ;
if ( F_59 ( V_35 ) )
continue;
if ( type == V_128 && V_35 -> V_61 )
continue;
if ( type == V_125 && ! V_35 -> V_61 )
continue;
F_60 ( V_35 -> V_76 , V_35 -> V_77 ,
& V_127 ) ;
}
F_74 ( V_4 ) ;
F_10 ( & V_4 -> V_38 ) ;
F_11 ( V_4 ) ;
}
F_22 ( V_44 ) ;
return V_87 ;
}
static int F_75 ( unsigned long V_91 , T_9 V_129 ,
struct V_130 * V_131 )
{
V_131 -> V_120 [ V_131 -> V_39 ++ ] = V_129 ;
if ( V_131 -> V_39 >= V_131 -> V_31 )
return V_132 ;
return 0 ;
}
static int F_76 ( unsigned long V_66 , unsigned long V_67 ,
struct V_93 * V_94 )
{
struct V_130 * V_131 = V_94 -> V_40 ;
unsigned long V_91 ;
int V_133 = 0 ;
for ( V_91 = V_66 ; V_91 < V_67 ; V_91 += V_26 ) {
V_133 = F_75 ( V_91 , V_134 , V_131 ) ;
if ( V_133 )
break;
}
return V_133 ;
}
static T_9 F_77 ( V_24 V_108 )
{
T_10 V_135 = F_78 ( V_108 ) ;
return F_79 ( V_135 ) | ( F_80 ( V_135 ) << V_136 ) ;
}
static T_9 F_81 ( V_24 V_108 )
{
T_9 V_137 = 0 ;
if ( F_40 ( V_108 ) )
V_137 = F_82 ( F_77 ( V_108 ) )
| F_83 ( V_19 ) | V_138 ;
else if ( F_41 ( V_108 ) )
V_137 = F_82 ( F_84 ( V_108 ) )
| F_83 ( V_19 ) | V_139 ;
return V_137 ;
}
static int F_85 ( T_4 * V_107 , unsigned long V_91 , unsigned long V_67 ,
struct V_93 * V_94 )
{
struct V_34 * V_35 ;
struct V_130 * V_131 = V_94 -> V_40 ;
V_24 * V_108 ;
int V_133 = 0 ;
F_65 ( V_94 -> V_4 , V_107 ) ;
V_35 = F_19 ( V_94 -> V_4 , V_91 ) ;
for (; V_91 != V_67 ; V_91 += V_26 ) {
T_9 V_129 = V_134 ;
if ( V_35 && ( V_91 >= V_35 -> V_77 ) )
V_35 = F_19 ( V_94 -> V_4 , V_91 ) ;
if ( V_35 && ( V_35 -> V_76 <= V_91 ) &&
! F_59 ( V_35 ) ) {
V_108 = F_86 ( V_107 , V_91 ) ;
V_129 = F_81 ( * V_108 ) ;
F_87 ( V_108 ) ;
}
V_133 = F_75 ( V_91 , V_129 , V_131 ) ;
if ( V_133 )
return V_133 ;
}
F_57 () ;
return V_133 ;
}
static T_9 F_88 ( V_24 V_108 , int V_140 )
{
T_9 V_137 = 0 ;
if ( F_41 ( V_108 ) )
V_137 = F_82 ( F_84 ( V_108 ) + V_140 )
| F_83 ( V_19 ) | V_139 ;
return V_137 ;
}
static int F_89 ( V_24 * V_108 , unsigned long V_141 ,
unsigned long V_91 , unsigned long V_67 ,
struct V_93 * V_94 )
{
struct V_130 * V_131 = V_94 -> V_40 ;
int V_133 = 0 ;
T_9 V_129 ;
for (; V_91 != V_67 ; V_91 += V_26 ) {
int V_140 = ( V_91 & ~ V_141 ) >> V_19 ;
V_129 = F_88 ( * V_108 , V_140 ) ;
V_133 = F_75 ( V_91 , V_129 , V_131 ) ;
if ( V_133 )
return V_133 ;
}
F_57 () ;
return V_133 ;
}
static T_6 F_90 ( struct V_54 * V_54 , char T_7 * V_118 ,
T_8 V_87 , T_1 * V_119 )
{
struct V_86 * V_44 = F_72 ( V_54 -> V_69 . V_70 -> V_71 ) ;
struct V_3 * V_4 ;
struct V_130 V_131 ;
int V_57 = - V_47 ;
struct V_93 V_142 = {} ;
unsigned long V_143 ;
unsigned long V_144 ;
unsigned long V_145 ;
unsigned long V_146 ;
int V_147 = 0 ;
if ( ! V_44 )
goto V_49;
V_57 = - V_126 ;
if ( ( * V_119 % V_148 ) || ( V_87 % V_148 ) )
goto V_149;
V_57 = 0 ;
if ( ! V_87 )
goto V_149;
V_131 . V_31 = V_148 * ( V_150 >> V_19 ) ;
V_131 . V_120 = F_91 ( V_131 . V_31 , V_151 ) ;
V_57 = - V_58 ;
if ( ! V_131 . V_120 )
goto V_149;
V_4 = F_15 ( V_44 ) ;
V_57 = F_92 ( V_4 ) ;
if ( ! V_4 || F_16 ( V_4 ) )
goto V_152;
V_142 . V_115 = F_85 ;
V_142 . V_153 = F_76 ;
#ifdef F_93
V_142 . V_154 = F_89 ;
#endif
V_142 . V_4 = V_4 ;
V_142 . V_40 = & V_131 ;
V_143 = * V_119 ;
V_144 = V_143 / V_148 ;
V_145 = V_144 << V_19 ;
V_146 = F_94 ( V_44 ) ;
if ( V_144 > F_94 ( V_44 ) >> V_19 )
V_145 = V_146 ;
V_57 = 0 ;
while ( V_87 && ( V_145 < V_146 ) ) {
int V_31 ;
unsigned long V_67 ;
V_131 . V_39 = 0 ;
V_67 = ( V_145 + V_150 ) & V_155 ;
if ( V_67 < V_145 || V_67 > V_146 )
V_67 = V_146 ;
F_17 ( & V_4 -> V_38 ) ;
V_57 = F_60 ( V_145 , V_67 , & V_142 ) ;
F_10 ( & V_4 -> V_38 ) ;
V_145 = V_67 ;
V_31 = F_95 ( V_87 , V_148 * V_131 . V_39 ) ;
if ( F_96 ( V_118 , V_131 . V_120 , V_31 ) ) {
V_57 = - V_123 ;
goto V_156;
}
V_147 += V_31 ;
V_118 += V_31 ;
V_87 -= V_31 ;
}
* V_119 += V_147 ;
if ( ! V_57 || V_57 == V_132 )
V_57 = V_147 ;
V_156:
F_11 ( V_4 ) ;
V_152:
F_27 ( V_131 . V_120 ) ;
V_149:
F_22 ( V_44 ) ;
V_49:
return V_57 ;
}
static void F_97 ( struct V_97 * V_97 , struct V_157 * V_158 , int F_47 ,
unsigned long V_159 )
{
int V_87 = F_46 ( V_97 ) ;
V_158 -> V_160 += V_159 ;
if ( F_47 || F_48 ( V_97 ) )
V_158 -> V_161 += V_159 ;
if ( F_98 ( V_97 ) )
V_158 -> V_162 += V_159 ;
if ( F_99 ( V_97 ) || F_100 ( V_97 ) )
V_158 -> V_163 += V_159 ;
if ( F_101 ( V_97 ) )
V_158 -> V_164 += V_159 ;
if ( F_43 ( V_97 ) )
V_158 -> V_165 += V_159 ;
if ( V_87 > V_158 -> V_166 )
V_158 -> V_166 = V_87 ;
V_158 -> V_167 [ F_102 ( V_97 ) ] += V_159 ;
}
static struct V_97 * F_103 ( V_24 V_108 , struct V_34 * V_35 ,
unsigned long V_91 )
{
struct V_97 * V_97 ;
int V_168 ;
if ( ! F_41 ( V_108 ) )
return NULL ;
V_97 = F_42 ( V_35 , V_91 , V_108 ) ;
if ( ! V_97 )
return NULL ;
if ( F_104 ( V_97 ) )
return NULL ;
V_168 = F_102 ( V_97 ) ;
if ( ! F_105 ( V_168 , V_169 [ V_170 ] ) )
return NULL ;
return V_97 ;
}
static int F_106 ( T_4 * V_107 , unsigned long V_91 ,
unsigned long V_67 , struct V_93 * V_94 )
{
struct V_157 * V_158 ;
T_5 * V_109 ;
V_24 * V_171 ;
V_24 * V_108 ;
V_158 = V_94 -> V_40 ;
F_50 ( & V_94 -> V_4 -> V_110 ) ;
if ( F_51 ( * V_107 ) ) {
if ( F_52 ( * V_107 ) ) {
F_53 ( & V_94 -> V_4 -> V_110 ) ;
F_54 ( V_158 -> V_35 -> V_111 , V_107 ) ;
} else {
V_24 V_172 = * ( V_24 * ) V_107 ;
struct V_97 * V_97 ;
V_97 = F_103 ( V_172 , V_158 -> V_35 , V_91 ) ;
if ( V_97 )
F_97 ( V_97 , V_158 , F_47 ( V_172 ) ,
V_112 / V_26 ) ;
F_53 ( & V_94 -> V_4 -> V_110 ) ;
return 0 ;
}
} else {
F_53 ( & V_94 -> V_4 -> V_110 ) ;
}
V_171 = V_108 = F_55 ( V_94 -> V_4 , V_107 , V_91 , & V_109 ) ;
do {
struct V_97 * V_97 = F_103 ( * V_108 , V_158 -> V_35 , V_91 ) ;
if ( ! V_97 )
continue;
F_97 ( V_97 , V_158 , F_47 ( * V_108 ) , 1 ) ;
} while ( V_108 ++ , V_91 += V_26 , V_91 != V_67 );
F_56 ( V_171 , V_109 ) ;
return 0 ;
}
static int F_107 ( V_24 * V_108 , unsigned long V_141 ,
unsigned long V_91 , unsigned long V_67 , struct V_93 * V_94 )
{
struct V_157 * V_158 ;
struct V_97 * V_97 ;
if ( F_108 ( * V_108 ) )
return 0 ;
V_97 = F_109 ( * V_108 ) ;
if ( ! V_97 )
return 0 ;
V_158 = V_94 -> V_40 ;
F_97 ( V_97 , V_158 , F_47 ( * V_108 ) , 1 ) ;
return 0 ;
}
static int F_107 ( V_24 * V_108 , unsigned long V_141 ,
unsigned long V_91 , unsigned long V_67 , struct V_93 * V_94 )
{
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , void * V_52 )
{
struct V_173 * V_174 = V_2 -> V_40 ;
struct V_32 * V_175 = & V_174 -> V_176 ;
struct V_34 * V_35 = V_52 ;
struct V_157 * V_158 = & V_174 -> V_158 ;
struct V_54 * V_54 = V_35 -> V_61 ;
struct V_3 * V_4 = V_35 -> V_37 ;
struct V_93 V_94 = {} ;
struct V_177 * V_178 ;
int V_179 ;
char V_120 [ 50 ] ;
if ( ! V_4 )
return 0 ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
V_158 -> V_35 = V_35 ;
V_94 . V_154 = F_107 ;
V_94 . V_115 = F_106 ;
V_94 . V_40 = V_158 ;
V_94 . V_4 = V_4 ;
V_178 = F_111 ( V_175 -> V_44 , V_35 , V_35 -> V_76 ) ;
F_112 ( V_120 , sizeof( V_120 ) , V_178 , 0 ) ;
F_113 ( V_178 ) ;
F_5 ( V_2 , L_32 , V_35 -> V_76 , V_120 ) ;
if ( V_54 ) {
F_5 ( V_2 , L_33 ) ;
F_33 ( V_2 , & V_54 -> V_69 , L_34 ) ;
} else if ( V_35 -> V_76 <= V_4 -> V_83 && V_35 -> V_77 >= V_4 -> V_84 ) {
F_5 ( V_2 , L_35 ) ;
} else if ( V_35 -> V_76 <= V_4 -> V_85 &&
V_35 -> V_77 >= V_4 -> V_85 ) {
F_5 ( V_2 , L_36 ) ;
}
F_60 ( V_35 -> V_76 , V_35 -> V_77 , & V_94 ) ;
if ( ! V_158 -> V_160 )
goto V_49;
if ( V_158 -> V_165 )
F_5 ( V_2 , L_37 , V_158 -> V_165 ) ;
if ( V_158 -> V_161 )
F_5 ( V_2 , L_38 , V_158 -> V_161 ) ;
if ( V_158 -> V_160 != V_158 -> V_165 && V_158 -> V_160 != V_158 -> V_161 )
F_5 ( V_2 , L_39 , V_158 -> V_160 ) ;
if ( V_158 -> V_166 > 1 )
F_5 ( V_2 , L_40 , V_158 -> V_166 ) ;
if ( V_158 -> V_162 )
F_5 ( V_2 , L_41 , V_158 -> V_162 ) ;
if ( V_158 -> V_163 < V_158 -> V_160 && ! F_59 ( V_35 ) )
F_5 ( V_2 , L_42 , V_158 -> V_163 ) ;
if ( V_158 -> V_164 )
F_5 ( V_2 , L_43 , V_158 -> V_164 ) ;
F_114 (n, N_HIGH_MEMORY)
if ( V_158 -> V_167 [ V_179 ] )
F_5 ( V_2 , L_44 , V_179 , V_158 -> V_167 [ V_179 ] ) ;
V_49:
F_36 ( V_2 , '\n' ) ;
if ( V_2 -> V_87 < V_2 -> V_88 )
V_2 -> V_42 = ( V_35 != V_175 -> V_36 ) ? V_35 -> V_76 : 0 ;
return 0 ;
}
static int F_115 ( struct V_53 * V_53 , struct V_54 * V_54 )
{
struct V_173 * V_33 ;
int V_57 = - V_58 ;
V_33 = F_24 ( sizeof( * V_33 ) , V_59 ) ;
if ( V_33 ) {
V_33 -> V_176 . V_45 = F_25 ( V_53 ) ;
V_57 = F_26 ( V_54 , & V_180 ) ;
if ( ! V_57 ) {
struct V_1 * V_2 = V_54 -> V_60 ;
V_2 -> V_40 = V_33 ;
} else {
F_27 ( V_33 ) ;
}
}
return V_57 ;
}
