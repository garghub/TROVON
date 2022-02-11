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
( V_10 - V_4 -> V_21 ) << ( V_19 - 10 ) ,
V_4 -> V_22 << ( V_19 - 10 ) ,
V_4 -> V_23 << ( V_19 - 10 ) ,
V_11 << ( V_19 - 10 ) ,
V_12 << ( V_19 - 10 ) ,
V_5 << ( V_19 - 10 ) ,
V_4 -> V_14 << ( V_19 - 10 ) , V_6 , V_7 ,
( V_24 * sizeof( V_25 ) * V_4 -> V_26 ) >> 10 ,
V_8 << ( V_19 - 10 ) ) ;
}
unsigned long F_6 ( struct V_3 * V_4 )
{
return V_27 * V_4 -> V_10 ;
}
unsigned long F_7 ( struct V_3 * V_4 ,
unsigned long * V_28 , unsigned long * V_6 ,
unsigned long * V_5 , unsigned long * V_29 )
{
* V_28 = F_4 ( V_4 , V_30 ) ;
* V_6 = ( F_3 ( V_4 -> V_15 ) - ( V_4 -> V_16 & V_17 ) )
>> V_19 ;
* V_5 = V_4 -> V_10 - V_4 -> V_13 ;
* V_29 = * V_28 + F_4 ( V_4 , V_31 ) ;
return V_4 -> V_10 ;
}
static void F_8 ( struct V_1 * V_2 , int V_32 )
{
V_32 = 25 + sizeof( void * ) * 6 - V_32 ;
if ( V_32 < 1 )
V_32 = 1 ;
F_5 ( V_2 , L_13 , V_32 , ' ' ) ;
}
static void F_9 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
if ( V_36 && V_36 != V_34 -> V_37 ) {
struct V_3 * V_4 = V_36 -> V_38 ;
F_10 ( & V_4 -> V_39 ) ;
F_11 ( V_4 ) ;
}
}
static void * F_12 ( struct V_1 * V_2 , T_1 * V_40 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
unsigned long V_42 = V_2 -> V_43 ;
struct V_3 * V_4 ;
struct V_35 * V_36 , * V_37 = NULL ;
T_1 V_44 = * V_40 ;
V_34 -> V_45 = NULL ;
V_34 -> V_37 = NULL ;
if ( V_42 == - 1UL )
return NULL ;
V_34 -> V_45 = F_13 ( V_34 -> V_46 , V_47 ) ;
if ( ! V_34 -> V_45 )
return F_14 ( - V_48 ) ;
V_4 = F_15 ( V_34 -> V_45 ) ;
if ( ! V_4 || F_16 ( V_4 ) )
return V_4 ;
F_17 ( & V_4 -> V_39 ) ;
V_37 = F_18 ( V_34 -> V_45 -> V_4 ) ;
V_34 -> V_37 = V_37 ;
V_36 = F_19 ( V_4 , V_42 ) ;
if ( V_42 && V_36 ) {
V_36 = V_36 -> V_49 ;
goto V_50;
}
V_36 = NULL ;
if ( ( unsigned long ) V_44 < V_4 -> V_51 ) {
V_36 = V_4 -> V_52 ;
while ( V_44 -- && V_36 )
V_36 = V_36 -> V_49 ;
goto V_50;
}
if ( V_44 != V_4 -> V_51 )
V_37 = NULL ;
V_50:
if ( V_36 )
return V_36 ;
V_2 -> V_43 = ( V_37 != NULL ) ? 0 : - 1UL ;
F_10 ( & V_4 -> V_39 ) ;
F_11 ( V_4 ) ;
return V_37 ;
}
static void * F_20 ( struct V_1 * V_2 , void * V_53 , T_1 * V_40 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_35 * V_36 = V_53 ;
struct V_35 * V_37 = V_34 -> V_37 ;
( * V_40 ) ++ ;
if ( V_36 && ( V_36 != V_37 ) && V_36 -> V_49 )
return V_36 -> V_49 ;
F_9 ( V_34 , V_36 ) ;
return ( V_36 != V_37 ) ? V_37 : NULL ;
}
static void F_21 ( struct V_1 * V_2 , void * V_53 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_35 * V_36 = V_53 ;
if ( ! F_16 ( V_36 ) )
F_9 ( V_34 , V_36 ) ;
if ( V_34 -> V_45 )
F_22 ( V_34 -> V_45 ) ;
}
static int F_23 ( struct V_54 * V_54 , struct V_55 * V_55 ,
const struct V_56 * V_57 )
{
struct V_33 * V_34 ;
int V_58 = - V_59 ;
V_34 = F_24 ( sizeof( * V_34 ) , V_60 ) ;
if ( V_34 ) {
V_34 -> V_46 = F_25 ( V_54 ) ;
V_58 = F_26 ( V_55 , V_57 ) ;
if ( ! V_58 ) {
struct V_1 * V_2 = V_55 -> V_61 ;
V_2 -> V_41 = V_34 ;
} else {
F_27 ( V_34 ) ;
}
}
return V_58 ;
}
static void F_28 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_3 * V_4 = V_36 -> V_38 ;
struct V_55 * V_55 = V_36 -> V_62 ;
T_2 V_63 = V_36 -> V_64 ;
unsigned long V_65 = 0 ;
unsigned long long V_66 = 0 ;
unsigned long V_67 , V_68 ;
T_3 V_69 = 0 ;
int V_32 ;
if ( V_55 ) {
struct V_54 * V_54 = V_36 -> V_62 -> V_70 . V_71 -> V_72 ;
V_69 = V_54 -> V_73 -> V_74 ;
V_65 = V_54 -> V_75 ;
V_66 = ( ( T_1 ) V_36 -> V_76 ) << V_19 ;
}
V_67 = V_36 -> V_77 ;
if ( F_29 ( V_36 , V_67 ) )
V_67 += V_27 ;
V_68 = V_36 -> V_78 ;
if ( F_30 ( V_36 , V_68 ) )
V_68 -= V_27 ;
F_5 ( V_2 , L_14 ,
V_67 ,
V_68 ,
V_63 & V_79 ? 'r' : '-' ,
V_63 & V_80 ? 'w' : '-' ,
V_63 & V_81 ? 'x' : '-' ,
V_63 & V_82 ? 's' : 'p' ,
V_66 ,
F_31 ( V_69 ) , F_32 ( V_69 ) , V_65 , & V_32 ) ;
if ( V_55 ) {
F_8 ( V_2 , V_32 ) ;
F_33 ( V_2 , & V_55 -> V_70 , L_15 ) ;
} else {
const char * V_83 = F_34 ( V_36 ) ;
if ( ! V_83 ) {
if ( V_4 ) {
if ( V_36 -> V_77 <= V_4 -> V_84 &&
V_36 -> V_78 >= V_4 -> V_85 ) {
V_83 = L_16 ;
} else if ( V_36 -> V_77 <= V_4 -> V_86 &&
V_36 -> V_78 >= V_4 -> V_86 ) {
V_83 = L_17 ;
}
} else {
V_83 = L_18 ;
}
}
if ( V_83 ) {
F_8 ( V_2 , V_32 ) ;
F_35 ( V_2 , V_83 ) ;
}
}
F_36 ( V_2 , '\n' ) ;
}
static int F_37 ( struct V_1 * V_2 , void * V_53 )
{
struct V_35 * V_36 = V_53 ;
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_87 * V_45 = V_34 -> V_45 ;
F_28 ( V_2 , V_36 ) ;
if ( V_2 -> V_88 < V_2 -> V_89 )
V_2 -> V_43 = ( V_36 != F_18 ( V_45 -> V_4 ) )
? V_36 -> V_77 : 0 ;
return 0 ;
}
static int F_38 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_23 ( V_54 , V_55 , & V_90 ) ;
}
static void F_39 ( V_25 V_91 , unsigned long V_92 ,
unsigned long V_93 , struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_41 ;
struct V_35 * V_36 = V_97 -> V_36 ;
struct V_98 * V_98 ;
int V_99 ;
if ( F_40 ( V_91 ) ) {
V_97 -> V_8 += V_93 ;
return;
}
if ( ! F_41 ( V_91 ) )
return;
V_98 = F_42 ( V_36 , V_92 , V_91 ) ;
if ( ! V_98 )
return;
if ( F_43 ( V_98 ) )
V_97 -> V_100 += V_93 ;
V_97 -> V_29 += V_93 ;
if ( F_44 ( V_91 ) || F_45 ( V_98 ) )
V_97 -> V_101 += V_93 ;
V_99 = F_46 ( V_98 ) ;
if ( V_99 >= 2 ) {
if ( F_47 ( V_91 ) || F_48 ( V_98 ) )
V_97 -> V_102 += V_93 ;
else
V_97 -> V_103 += V_93 ;
V_97 -> V_104 += ( V_93 << V_105 ) / V_99 ;
} else {
if ( F_47 ( V_91 ) || F_48 ( V_98 ) )
V_97 -> V_106 += V_93 ;
else
V_97 -> V_107 += V_93 ;
V_97 -> V_104 += ( V_93 << V_105 ) ;
}
}
static int F_49 ( T_4 * V_108 , unsigned long V_92 , unsigned long V_68 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 -> V_41 ;
struct V_35 * V_36 = V_97 -> V_36 ;
V_25 * V_109 ;
T_5 * V_110 ;
F_50 ( & V_95 -> V_4 -> V_111 ) ;
if ( F_51 ( * V_108 ) ) {
if ( F_52 ( * V_108 ) ) {
F_53 ( & V_95 -> V_4 -> V_111 ) ;
F_54 ( V_36 -> V_112 , V_108 ) ;
} else {
F_39 ( * ( V_25 * ) V_108 , V_92 ,
V_113 , V_95 ) ;
F_53 ( & V_95 -> V_4 -> V_111 ) ;
V_97 -> V_114 += V_113 ;
return 0 ;
}
} else {
F_53 ( & V_95 -> V_4 -> V_111 ) ;
}
V_109 = F_55 ( V_36 -> V_38 , V_108 , V_92 , & V_110 ) ;
for (; V_92 != V_68 ; V_109 ++ , V_92 += V_27 )
F_39 ( * V_109 , V_92 , V_27 , V_95 ) ;
F_56 ( V_109 - 1 , V_110 ) ;
F_57 () ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , void * V_53 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_87 * V_45 = V_34 -> V_45 ;
struct V_35 * V_36 = V_53 ;
struct V_96 V_97 ;
struct V_94 V_115 = {
. V_116 = F_49 ,
. V_4 = V_36 -> V_38 ,
. V_41 = & V_97 ,
} ;
memset ( & V_97 , 0 , sizeof V_97 ) ;
V_97 . V_36 = V_36 ;
if ( V_36 -> V_38 && ! F_59 ( V_36 ) )
F_60 ( V_36 -> V_77 , V_36 -> V_78 , & V_115 ) ;
F_28 ( V_2 , V_36 ) ;
F_5 ( V_2 ,
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
L_31
L_32 ,
( V_36 -> V_78 - V_36 -> V_77 ) >> 10 ,
V_97 . V_29 >> 10 ,
( unsigned long ) ( V_97 . V_104 >> ( 10 + V_105 ) ) ,
V_97 . V_103 >> 10 ,
V_97 . V_102 >> 10 ,
V_97 . V_107 >> 10 ,
V_97 . V_106 >> 10 ,
V_97 . V_101 >> 10 ,
V_97 . V_100 >> 10 ,
V_97 . V_114 >> 10 ,
V_97 . V_8 >> 10 ,
F_61 ( V_36 ) >> 10 ,
F_62 ( V_36 ) >> 10 ,
( V_36 -> V_64 & V_117 ) ?
( unsigned long ) ( V_97 . V_104 >> ( 10 + V_105 ) ) : 0 ) ;
if ( V_2 -> V_88 < V_2 -> V_89 )
V_2 -> V_43 = ( V_36 != F_18 ( V_45 -> V_4 ) )
? V_36 -> V_77 : 0 ;
return 0 ;
}
static int F_63 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_23 ( V_54 , V_55 , & V_118 ) ;
}
static int F_64 ( T_4 * V_108 , unsigned long V_92 ,
unsigned long V_68 , struct V_94 * V_95 )
{
struct V_35 * V_36 = V_95 -> V_41 ;
V_25 * V_109 , V_91 ;
T_5 * V_110 ;
struct V_98 * V_98 ;
F_65 ( V_95 -> V_4 , V_108 ) ;
V_109 = F_55 ( V_36 -> V_38 , V_108 , V_92 , & V_110 ) ;
for (; V_92 != V_68 ; V_109 ++ , V_92 += V_27 ) {
V_91 = * V_109 ;
if ( ! F_41 ( V_91 ) )
continue;
V_98 = F_42 ( V_36 , V_92 , V_91 ) ;
if ( ! V_98 )
continue;
F_66 ( V_36 , V_92 , V_109 ) ;
F_67 ( V_98 ) ;
}
F_56 ( V_109 - 1 , V_110 ) ;
F_57 () ;
return 0 ;
}
static T_6 F_68 ( struct V_55 * V_55 , const char T_7 * V_119 ,
T_8 V_88 , T_1 * V_120 )
{
struct V_87 * V_45 ;
char V_121 [ V_122 ] ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int type ;
int V_123 ;
memset ( V_121 , 0 , sizeof( V_121 ) ) ;
if ( V_88 > sizeof( V_121 ) - 1 )
V_88 = sizeof( V_121 ) - 1 ;
if ( F_69 ( V_121 , V_119 , V_88 ) )
return - V_124 ;
V_123 = F_70 ( F_71 ( V_121 ) , 10 , & type ) ;
if ( V_123 < 0 )
return V_123 ;
if ( type < V_125 || type > V_126 )
return - V_127 ;
V_45 = F_72 ( V_55 -> V_70 . V_71 -> V_72 ) ;
if ( ! V_45 )
return - V_48 ;
V_4 = F_73 ( V_45 ) ;
if ( V_4 ) {
struct V_94 V_128 = {
. V_116 = F_64 ,
. V_4 = V_4 ,
} ;
F_17 ( & V_4 -> V_39 ) ;
for ( V_36 = V_4 -> V_52 ; V_36 ; V_36 = V_36 -> V_49 ) {
V_128 . V_41 = V_36 ;
if ( F_59 ( V_36 ) )
continue;
if ( type == V_129 && V_36 -> V_62 )
continue;
if ( type == V_126 && ! V_36 -> V_62 )
continue;
F_60 ( V_36 -> V_77 , V_36 -> V_78 ,
& V_128 ) ;
}
F_74 ( V_4 ) ;
F_10 ( & V_4 -> V_39 ) ;
F_11 ( V_4 ) ;
}
F_22 ( V_45 ) ;
return V_88 ;
}
static int F_75 ( unsigned long V_92 , T_9 V_130 ,
struct V_131 * V_132 )
{
V_132 -> V_121 [ V_132 -> V_40 ++ ] = V_130 ;
if ( V_132 -> V_40 >= V_132 -> V_32 )
return V_133 ;
return 0 ;
}
static int F_76 ( unsigned long V_67 , unsigned long V_68 ,
struct V_94 * V_95 )
{
struct V_131 * V_132 = V_95 -> V_41 ;
unsigned long V_92 ;
int V_134 = 0 ;
for ( V_92 = V_67 ; V_92 < V_68 ; V_92 += V_27 ) {
V_134 = F_75 ( V_92 , V_135 , V_132 ) ;
if ( V_134 )
break;
}
return V_134 ;
}
static T_9 F_77 ( V_25 V_109 )
{
T_10 V_136 = F_78 ( V_109 ) ;
return F_79 ( V_136 ) | ( F_80 ( V_136 ) << V_137 ) ;
}
static T_9 F_81 ( V_25 V_109 )
{
T_9 V_138 = 0 ;
if ( F_40 ( V_109 ) )
V_138 = F_82 ( F_77 ( V_109 ) )
| F_83 ( V_19 ) | V_139 ;
else if ( F_41 ( V_109 ) )
V_138 = F_82 ( F_84 ( V_109 ) )
| F_83 ( V_19 ) | V_140 ;
return V_138 ;
}
static int F_85 ( T_4 * V_108 , unsigned long V_92 , unsigned long V_68 ,
struct V_94 * V_95 )
{
struct V_35 * V_36 ;
struct V_131 * V_132 = V_95 -> V_41 ;
V_25 * V_109 ;
int V_134 = 0 ;
F_65 ( V_95 -> V_4 , V_108 ) ;
V_36 = F_19 ( V_95 -> V_4 , V_92 ) ;
for (; V_92 != V_68 ; V_92 += V_27 ) {
T_9 V_130 = V_135 ;
if ( V_36 && ( V_92 >= V_36 -> V_78 ) )
V_36 = F_19 ( V_95 -> V_4 , V_92 ) ;
if ( V_36 && ( V_36 -> V_77 <= V_92 ) &&
! F_59 ( V_36 ) ) {
V_109 = F_86 ( V_108 , V_92 ) ;
V_130 = F_81 ( * V_109 ) ;
F_87 ( V_109 ) ;
}
V_134 = F_75 ( V_92 , V_130 , V_132 ) ;
if ( V_134 )
return V_134 ;
}
F_57 () ;
return V_134 ;
}
static T_9 F_88 ( V_25 V_109 , int V_141 )
{
T_9 V_138 = 0 ;
if ( F_41 ( V_109 ) )
V_138 = F_82 ( F_84 ( V_109 ) + V_141 )
| F_83 ( V_19 ) | V_140 ;
return V_138 ;
}
static int F_89 ( V_25 * V_109 , unsigned long V_142 ,
unsigned long V_92 , unsigned long V_68 ,
struct V_94 * V_95 )
{
struct V_131 * V_132 = V_95 -> V_41 ;
int V_134 = 0 ;
T_9 V_130 ;
for (; V_92 != V_68 ; V_92 += V_27 ) {
int V_141 = ( V_92 & ~ V_142 ) >> V_19 ;
V_130 = F_88 ( * V_109 , V_141 ) ;
V_134 = F_75 ( V_92 , V_130 , V_132 ) ;
if ( V_134 )
return V_134 ;
}
F_57 () ;
return V_134 ;
}
static T_6 F_90 ( struct V_55 * V_55 , char T_7 * V_119 ,
T_8 V_88 , T_1 * V_120 )
{
struct V_87 * V_45 = F_72 ( V_55 -> V_70 . V_71 -> V_72 ) ;
struct V_3 * V_4 ;
struct V_131 V_132 ;
int V_58 = - V_48 ;
struct V_94 V_143 = {} ;
unsigned long V_144 ;
unsigned long V_145 ;
unsigned long V_146 ;
unsigned long V_147 ;
int V_148 = 0 ;
if ( ! V_45 )
goto V_50;
V_58 = - V_127 ;
if ( ( * V_120 % V_149 ) || ( V_88 % V_149 ) )
goto V_150;
V_58 = 0 ;
if ( ! V_88 )
goto V_150;
V_132 . V_32 = V_149 * ( V_151 >> V_19 ) ;
V_132 . V_121 = F_91 ( V_132 . V_32 , V_152 ) ;
V_58 = - V_59 ;
if ( ! V_132 . V_121 )
goto V_150;
V_4 = F_15 ( V_45 ) ;
V_58 = F_92 ( V_4 ) ;
if ( ! V_4 || F_16 ( V_4 ) )
goto V_153;
V_143 . V_116 = F_85 ;
V_143 . V_154 = F_76 ;
#ifdef F_93
V_143 . V_155 = F_89 ;
#endif
V_143 . V_4 = V_4 ;
V_143 . V_41 = & V_132 ;
V_144 = * V_120 ;
V_145 = V_144 / V_149 ;
V_146 = V_145 << V_19 ;
V_147 = F_94 ( V_45 ) ;
if ( V_145 > F_94 ( V_45 ) >> V_19 )
V_146 = V_147 ;
V_58 = 0 ;
while ( V_88 && ( V_146 < V_147 ) ) {
int V_32 ;
unsigned long V_68 ;
V_132 . V_40 = 0 ;
V_68 = ( V_146 + V_151 ) & V_156 ;
if ( V_68 < V_146 || V_68 > V_147 )
V_68 = V_147 ;
F_17 ( & V_4 -> V_39 ) ;
V_58 = F_60 ( V_146 , V_68 , & V_143 ) ;
F_10 ( & V_4 -> V_39 ) ;
V_146 = V_68 ;
V_32 = F_95 ( V_88 , V_149 * V_132 . V_40 ) ;
if ( F_96 ( V_119 , V_132 . V_121 , V_32 ) ) {
V_58 = - V_124 ;
goto V_157;
}
V_148 += V_32 ;
V_119 += V_32 ;
V_88 -= V_32 ;
}
* V_120 += V_148 ;
if ( ! V_58 || V_58 == V_133 )
V_58 = V_148 ;
V_157:
F_11 ( V_4 ) ;
V_153:
F_27 ( V_132 . V_121 ) ;
V_150:
F_22 ( V_45 ) ;
V_50:
return V_58 ;
}
static void F_97 ( struct V_98 * V_98 , struct V_158 * V_159 , int F_47 ,
unsigned long V_160 )
{
int V_88 = F_46 ( V_98 ) ;
V_159 -> V_161 += V_160 ;
if ( F_47 || F_48 ( V_98 ) )
V_159 -> V_162 += V_160 ;
if ( F_98 ( V_98 ) )
V_159 -> V_163 += V_160 ;
if ( F_99 ( V_98 ) || F_100 ( V_98 ) )
V_159 -> V_164 += V_160 ;
if ( F_101 ( V_98 ) )
V_159 -> V_165 += V_160 ;
if ( F_43 ( V_98 ) )
V_159 -> V_166 += V_160 ;
if ( V_88 > V_159 -> V_167 )
V_159 -> V_167 = V_88 ;
V_159 -> V_168 [ F_102 ( V_98 ) ] += V_160 ;
}
static struct V_98 * F_103 ( V_25 V_109 , struct V_35 * V_36 ,
unsigned long V_92 )
{
struct V_98 * V_98 ;
int V_169 ;
if ( ! F_41 ( V_109 ) )
return NULL ;
V_98 = F_42 ( V_36 , V_92 , V_109 ) ;
if ( ! V_98 )
return NULL ;
if ( F_104 ( V_98 ) )
return NULL ;
V_169 = F_102 ( V_98 ) ;
if ( ! F_105 ( V_169 , V_170 [ V_171 ] ) )
return NULL ;
return V_98 ;
}
static int F_106 ( T_4 * V_108 , unsigned long V_92 ,
unsigned long V_68 , struct V_94 * V_95 )
{
struct V_158 * V_159 ;
T_5 * V_110 ;
V_25 * V_172 ;
V_25 * V_109 ;
V_159 = V_95 -> V_41 ;
F_50 ( & V_95 -> V_4 -> V_111 ) ;
if ( F_51 ( * V_108 ) ) {
if ( F_52 ( * V_108 ) ) {
F_53 ( & V_95 -> V_4 -> V_111 ) ;
F_54 ( V_159 -> V_36 -> V_112 , V_108 ) ;
} else {
V_25 V_173 = * ( V_25 * ) V_108 ;
struct V_98 * V_98 ;
V_98 = F_103 ( V_173 , V_159 -> V_36 , V_92 ) ;
if ( V_98 )
F_97 ( V_98 , V_159 , F_47 ( V_173 ) ,
V_113 / V_27 ) ;
F_53 ( & V_95 -> V_4 -> V_111 ) ;
return 0 ;
}
} else {
F_53 ( & V_95 -> V_4 -> V_111 ) ;
}
V_172 = V_109 = F_55 ( V_95 -> V_4 , V_108 , V_92 , & V_110 ) ;
do {
struct V_98 * V_98 = F_103 ( * V_109 , V_159 -> V_36 , V_92 ) ;
if ( ! V_98 )
continue;
F_97 ( V_98 , V_159 , F_47 ( * V_109 ) , 1 ) ;
} while ( V_109 ++ , V_92 += V_27 , V_92 != V_68 );
F_56 ( V_172 , V_110 ) ;
return 0 ;
}
static int F_107 ( V_25 * V_109 , unsigned long V_142 ,
unsigned long V_92 , unsigned long V_68 , struct V_94 * V_95 )
{
struct V_158 * V_159 ;
struct V_98 * V_98 ;
if ( F_108 ( * V_109 ) )
return 0 ;
V_98 = F_109 ( * V_109 ) ;
if ( ! V_98 )
return 0 ;
V_159 = V_95 -> V_41 ;
F_97 ( V_98 , V_159 , F_47 ( * V_109 ) , 1 ) ;
return 0 ;
}
static int F_107 ( V_25 * V_109 , unsigned long V_142 ,
unsigned long V_92 , unsigned long V_68 , struct V_94 * V_95 )
{
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , void * V_53 )
{
struct V_174 * V_175 = V_2 -> V_41 ;
struct V_33 * V_176 = & V_175 -> V_177 ;
struct V_35 * V_36 = V_53 ;
struct V_158 * V_159 = & V_175 -> V_159 ;
struct V_55 * V_55 = V_36 -> V_62 ;
struct V_3 * V_4 = V_36 -> V_38 ;
struct V_94 V_95 = {} ;
struct V_178 * V_179 ;
int V_180 ;
char V_121 [ 50 ] ;
if ( ! V_4 )
return 0 ;
memset ( V_159 , 0 , sizeof( * V_159 ) ) ;
V_159 -> V_36 = V_36 ;
V_95 . V_155 = F_107 ;
V_95 . V_116 = F_106 ;
V_95 . V_41 = V_159 ;
V_95 . V_4 = V_4 ;
V_179 = F_111 ( V_176 -> V_45 , V_36 , V_36 -> V_77 ) ;
F_112 ( V_121 , sizeof( V_121 ) , V_179 , 0 ) ;
F_113 ( V_179 ) ;
F_5 ( V_2 , L_33 , V_36 -> V_77 , V_121 ) ;
if ( V_55 ) {
F_5 ( V_2 , L_34 ) ;
F_33 ( V_2 , & V_55 -> V_70 , L_35 ) ;
} else if ( V_36 -> V_77 <= V_4 -> V_84 && V_36 -> V_78 >= V_4 -> V_85 ) {
F_5 ( V_2 , L_36 ) ;
} else if ( V_36 -> V_77 <= V_4 -> V_86 &&
V_36 -> V_78 >= V_4 -> V_86 ) {
F_5 ( V_2 , L_37 ) ;
}
if ( F_59 ( V_36 ) )
F_5 ( V_2 , L_38 ) ;
F_60 ( V_36 -> V_77 , V_36 -> V_78 , & V_95 ) ;
if ( ! V_159 -> V_161 )
goto V_50;
if ( V_159 -> V_166 )
F_5 ( V_2 , L_39 , V_159 -> V_166 ) ;
if ( V_159 -> V_162 )
F_5 ( V_2 , L_40 , V_159 -> V_162 ) ;
if ( V_159 -> V_161 != V_159 -> V_166 && V_159 -> V_161 != V_159 -> V_162 )
F_5 ( V_2 , L_41 , V_159 -> V_161 ) ;
if ( V_159 -> V_167 > 1 )
F_5 ( V_2 , L_42 , V_159 -> V_167 ) ;
if ( V_159 -> V_163 )
F_5 ( V_2 , L_43 , V_159 -> V_163 ) ;
if ( V_159 -> V_164 < V_159 -> V_161 && ! F_59 ( V_36 ) )
F_5 ( V_2 , L_44 , V_159 -> V_164 ) ;
if ( V_159 -> V_165 )
F_5 ( V_2 , L_45 , V_159 -> V_165 ) ;
F_114 (n, N_HIGH_MEMORY)
if ( V_159 -> V_168 [ V_180 ] )
F_5 ( V_2 , L_46 , V_180 , V_159 -> V_168 [ V_180 ] ) ;
V_50:
F_36 ( V_2 , '\n' ) ;
if ( V_2 -> V_88 < V_2 -> V_89 )
V_2 -> V_43 = ( V_36 != V_176 -> V_37 ) ? V_36 -> V_77 : 0 ;
return 0 ;
}
static int F_115 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
struct V_174 * V_34 ;
int V_58 = - V_59 ;
V_34 = F_24 ( sizeof( * V_34 ) , V_60 ) ;
if ( V_34 ) {
V_34 -> V_177 . V_46 = F_25 ( V_54 ) ;
V_58 = F_26 ( V_55 , & V_181 ) ;
if ( ! V_58 ) {
struct V_1 * V_2 = V_55 -> V_61 ;
V_2 -> V_41 = V_34 ;
} else {
F_27 ( V_34 ) ;
}
}
return V_58 ;
}
