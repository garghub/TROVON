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
V_4 = F_15 ( V_34 -> V_45 , V_49 ) ;
if ( ! V_4 || F_16 ( V_4 ) )
return V_4 ;
F_17 ( & V_4 -> V_39 ) ;
V_37 = F_18 ( V_34 -> V_45 -> V_4 ) ;
V_34 -> V_37 = V_37 ;
V_36 = F_19 ( V_4 , V_42 ) ;
if ( V_42 && V_36 ) {
V_36 = V_36 -> V_50 ;
goto V_51;
}
V_36 = NULL ;
if ( ( unsigned long ) V_44 < V_4 -> V_52 ) {
V_36 = V_4 -> V_53 ;
while ( V_44 -- && V_36 )
V_36 = V_36 -> V_50 ;
goto V_51;
}
if ( V_44 != V_4 -> V_52 )
V_37 = NULL ;
V_51:
if ( V_36 )
return V_36 ;
V_2 -> V_43 = ( V_37 != NULL ) ? 0 : - 1UL ;
F_10 ( & V_4 -> V_39 ) ;
F_11 ( V_4 ) ;
return V_37 ;
}
static void * F_20 ( struct V_1 * V_2 , void * V_54 , T_1 * V_40 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_35 * V_36 = V_54 ;
struct V_35 * V_37 = V_34 -> V_37 ;
( * V_40 ) ++ ;
if ( V_36 && ( V_36 != V_37 ) && V_36 -> V_50 )
return V_36 -> V_50 ;
F_9 ( V_34 , V_36 ) ;
return ( V_36 != V_37 ) ? V_37 : NULL ;
}
static void F_21 ( struct V_1 * V_2 , void * V_54 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_35 * V_36 = V_54 ;
if ( ! F_16 ( V_36 ) )
F_9 ( V_34 , V_36 ) ;
if ( V_34 -> V_45 )
F_22 ( V_34 -> V_45 ) ;
}
static int F_23 ( struct V_55 * V_55 , struct V_56 * V_56 ,
const struct V_57 * V_58 )
{
struct V_33 * V_34 ;
int V_59 = - V_60 ;
V_34 = F_24 ( sizeof( * V_34 ) , V_61 ) ;
if ( V_34 ) {
V_34 -> V_46 = F_25 ( V_55 ) ;
V_59 = F_26 ( V_56 , V_58 ) ;
if ( ! V_59 ) {
struct V_1 * V_2 = V_56 -> V_62 ;
V_2 -> V_41 = V_34 ;
} else {
F_27 ( V_34 ) ;
}
}
return V_59 ;
}
static void
F_28 ( struct V_1 * V_2 , struct V_35 * V_36 , int V_63 )
{
struct V_3 * V_4 = V_36 -> V_38 ;
struct V_56 * V_56 = V_36 -> V_64 ;
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_65 * V_45 = V_34 -> V_45 ;
T_2 V_66 = V_36 -> V_67 ;
unsigned long V_68 = 0 ;
unsigned long long V_69 = 0 ;
unsigned long V_70 , V_71 ;
T_3 V_72 = 0 ;
int V_32 ;
const char * V_73 = NULL ;
if ( V_56 ) {
struct V_55 * V_55 = V_36 -> V_64 -> V_74 . V_75 -> V_76 ;
V_72 = V_55 -> V_77 -> V_78 ;
V_68 = V_55 -> V_79 ;
V_69 = ( ( T_1 ) V_36 -> V_80 ) << V_19 ;
}
V_70 = V_36 -> V_81 ;
if ( F_29 ( V_36 , V_70 ) )
V_70 += V_27 ;
V_71 = V_36 -> V_82 ;
if ( F_30 ( V_36 , V_71 ) )
V_71 -= V_27 ;
F_5 ( V_2 , L_14 ,
V_70 ,
V_71 ,
V_66 & V_83 ? 'r' : '-' ,
V_66 & V_84 ? 'w' : '-' ,
V_66 & V_85 ? 'x' : '-' ,
V_66 & V_86 ? 's' : 'p' ,
V_69 ,
F_31 ( V_72 ) , F_32 ( V_72 ) , V_68 , & V_32 ) ;
if ( V_56 ) {
F_8 ( V_2 , V_32 ) ;
F_33 ( V_2 , & V_56 -> V_74 , L_15 ) ;
goto V_87;
}
V_73 = F_34 ( V_36 ) ;
if ( ! V_73 ) {
T_4 V_88 ;
if ( ! V_4 ) {
V_73 = L_16 ;
goto V_87;
}
if ( V_36 -> V_81 <= V_4 -> V_89 &&
V_36 -> V_82 >= V_4 -> V_90 ) {
V_73 = L_17 ;
goto V_87;
}
V_88 = F_35 ( V_45 , V_36 , V_63 ) ;
if ( V_88 != 0 ) {
if ( ! V_63 || ( V_36 -> V_81 <= V_4 -> V_91 &&
V_36 -> V_82 >= V_4 -> V_91 ) ) {
V_73 = L_18 ;
} else {
F_8 ( V_2 , V_32 ) ;
F_5 ( V_2 , L_19 , V_88 ) ;
}
}
}
V_87:
if ( V_73 ) {
F_8 ( V_2 , V_32 ) ;
F_36 ( V_2 , V_73 ) ;
}
F_37 ( V_2 , '\n' ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_54 , int V_63 )
{
struct V_35 * V_36 = V_54 ;
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_65 * V_45 = V_34 -> V_45 ;
F_28 ( V_2 , V_36 , V_63 ) ;
if ( V_2 -> V_92 < V_2 -> V_93 )
V_2 -> V_43 = ( V_36 != F_18 ( V_45 -> V_4 ) )
? V_36 -> V_81 : 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , void * V_54 )
{
return F_38 ( V_2 , V_54 , 1 ) ;
}
static int F_40 ( struct V_1 * V_2 , void * V_54 )
{
return F_38 ( V_2 , V_54 , 0 ) ;
}
static int F_41 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_23 ( V_55 , V_56 , & V_94 ) ;
}
static int F_42 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_23 ( V_55 , V_56 , & V_95 ) ;
}
static void F_43 ( V_25 V_96 , unsigned long V_97 ,
unsigned long V_98 , struct V_99 * V_100 )
{
struct V_101 * V_102 = V_100 -> V_41 ;
struct V_35 * V_36 = V_102 -> V_36 ;
T_5 V_69 = F_44 ( V_36 , V_97 ) ;
struct V_103 * V_103 = NULL ;
int V_104 ;
if ( F_45 ( V_96 ) ) {
V_103 = F_46 ( V_36 , V_97 , V_96 ) ;
} else if ( F_47 ( V_96 ) ) {
T_6 V_105 = F_48 ( V_96 ) ;
if ( ! F_49 ( V_105 ) )
V_102 -> V_8 += V_98 ;
else if ( F_50 ( V_105 ) )
V_103 = F_51 ( V_105 ) ;
} else if ( F_52 ( V_96 ) ) {
if ( F_53 ( V_96 ) != V_69 )
V_102 -> V_106 += V_98 ;
}
if ( ! V_103 )
return;
if ( F_54 ( V_103 ) )
V_102 -> V_107 += V_98 ;
if ( V_103 -> V_108 != V_69 )
V_102 -> V_106 += V_98 ;
V_102 -> V_29 += V_98 ;
if ( F_55 ( V_96 ) || F_56 ( V_103 ) )
V_102 -> V_109 += V_98 ;
V_104 = F_57 ( V_103 ) ;
if ( V_104 >= 2 ) {
if ( F_58 ( V_96 ) || F_59 ( V_103 ) )
V_102 -> V_110 += V_98 ;
else
V_102 -> V_111 += V_98 ;
V_102 -> V_112 += ( V_98 << V_113 ) / V_104 ;
} else {
if ( F_58 ( V_96 ) || F_59 ( V_103 ) )
V_102 -> V_114 += V_98 ;
else
V_102 -> V_115 += V_98 ;
V_102 -> V_112 += ( V_98 << V_113 ) ;
}
}
static int F_60 ( T_7 * V_116 , unsigned long V_97 , unsigned long V_71 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 = V_100 -> V_41 ;
struct V_35 * V_36 = V_102 -> V_36 ;
V_25 * V_117 ;
T_8 * V_118 ;
if ( F_61 ( V_116 , V_36 ) == 1 ) {
F_43 ( * ( V_25 * ) V_116 , V_97 , V_119 , V_100 ) ;
F_62 ( & V_100 -> V_4 -> V_120 ) ;
V_102 -> V_121 += V_119 ;
return 0 ;
}
if ( F_63 ( V_116 ) )
return 0 ;
V_117 = F_64 ( V_36 -> V_38 , V_116 , V_97 , & V_118 ) ;
for (; V_97 != V_71 ; V_117 ++ , V_97 += V_27 )
F_43 ( * V_117 , V_97 , V_27 , V_100 ) ;
F_65 ( V_117 - 1 , V_118 ) ;
F_66 () ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , void * V_54 , int V_63 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_65 * V_45 = V_34 -> V_45 ;
struct V_35 * V_36 = V_54 ;
struct V_101 V_102 ;
struct V_99 V_122 = {
. V_123 = F_60 ,
. V_4 = V_36 -> V_38 ,
. V_41 = & V_102 ,
} ;
memset ( & V_102 , 0 , sizeof V_102 ) ;
V_102 . V_36 = V_36 ;
if ( V_36 -> V_38 && ! F_68 ( V_36 ) )
F_69 ( V_36 -> V_81 , V_36 -> V_82 , & V_122 ) ;
F_28 ( V_2 , V_36 , V_63 ) ;
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
( V_36 -> V_82 - V_36 -> V_81 ) >> 10 ,
V_102 . V_29 >> 10 ,
( unsigned long ) ( V_102 . V_112 >> ( 10 + V_113 ) ) ,
V_102 . V_111 >> 10 ,
V_102 . V_110 >> 10 ,
V_102 . V_115 >> 10 ,
V_102 . V_114 >> 10 ,
V_102 . V_109 >> 10 ,
V_102 . V_107 >> 10 ,
V_102 . V_121 >> 10 ,
V_102 . V_8 >> 10 ,
F_70 ( V_36 ) >> 10 ,
F_71 ( V_36 ) >> 10 ,
( V_36 -> V_67 & V_124 ) ?
( unsigned long ) ( V_102 . V_112 >> ( 10 + V_113 ) ) : 0 ) ;
if ( V_36 -> V_67 & V_125 )
F_5 ( V_2 , L_34 ,
V_102 . V_106 >> 10 ) ;
if ( V_2 -> V_92 < V_2 -> V_93 )
V_2 -> V_43 = ( V_36 != F_18 ( V_45 -> V_4 ) )
? V_36 -> V_81 : 0 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , void * V_54 )
{
return F_67 ( V_2 , V_54 , 1 ) ;
}
static int F_73 ( struct V_1 * V_2 , void * V_54 )
{
return F_67 ( V_2 , V_54 , 0 ) ;
}
static int F_74 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_23 ( V_55 , V_56 , & V_126 ) ;
}
static int F_75 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_23 ( V_55 , V_56 , & V_127 ) ;
}
static int F_76 ( T_7 * V_116 , unsigned long V_97 ,
unsigned long V_71 , struct V_99 * V_100 )
{
struct V_35 * V_36 = V_100 -> V_41 ;
V_25 * V_117 , V_96 ;
T_8 * V_118 ;
struct V_103 * V_103 ;
F_77 ( V_100 -> V_4 , V_116 ) ;
if ( F_63 ( V_116 ) )
return 0 ;
V_117 = F_64 ( V_36 -> V_38 , V_116 , V_97 , & V_118 ) ;
for (; V_97 != V_71 ; V_117 ++ , V_97 += V_27 ) {
V_96 = * V_117 ;
if ( ! F_45 ( V_96 ) )
continue;
V_103 = F_46 ( V_36 , V_97 , V_96 ) ;
if ( ! V_103 )
continue;
F_78 ( V_36 , V_97 , V_117 ) ;
F_79 ( V_103 ) ;
}
F_65 ( V_117 - 1 , V_118 ) ;
F_66 () ;
return 0 ;
}
static T_9 F_80 ( struct V_56 * V_56 , const char T_10 * V_128 ,
T_11 V_92 , T_1 * V_129 )
{
struct V_65 * V_45 ;
char V_130 [ V_131 ] ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int type ;
int V_132 ;
memset ( V_130 , 0 , sizeof( V_130 ) ) ;
if ( V_92 > sizeof( V_130 ) - 1 )
V_92 = sizeof( V_130 ) - 1 ;
if ( F_81 ( V_130 , V_128 , V_92 ) )
return - V_133 ;
V_132 = F_82 ( F_83 ( V_130 ) , 10 , & type ) ;
if ( V_132 < 0 )
return V_132 ;
if ( type < V_134 || type > V_135 )
return - V_136 ;
V_45 = F_84 ( V_56 -> V_74 . V_75 -> V_76 ) ;
if ( ! V_45 )
return - V_48 ;
V_4 = F_85 ( V_45 ) ;
if ( V_4 ) {
struct V_99 V_137 = {
. V_123 = F_76 ,
. V_4 = V_4 ,
} ;
F_17 ( & V_4 -> V_39 ) ;
for ( V_36 = V_4 -> V_53 ; V_36 ; V_36 = V_36 -> V_50 ) {
V_137 . V_41 = V_36 ;
if ( F_68 ( V_36 ) )
continue;
if ( type == V_138 && V_36 -> V_64 )
continue;
if ( type == V_135 && ! V_36 -> V_64 )
continue;
F_69 ( V_36 -> V_81 , V_36 -> V_82 ,
& V_137 ) ;
}
F_86 ( V_4 ) ;
F_10 ( & V_4 -> V_39 ) ;
F_11 ( V_4 ) ;
}
F_22 ( V_45 ) ;
return V_92 ;
}
static inline T_12 F_87 ( T_13 V_139 )
{
return ( T_12 ) { . V_140 = V_139 } ;
}
static int F_88 ( unsigned long V_97 , T_12 * V_140 ,
struct V_141 * V_142 )
{
V_142 -> V_130 [ V_142 -> V_40 ++ ] = * V_140 ;
if ( V_142 -> V_40 >= V_142 -> V_32 )
return V_143 ;
return 0 ;
}
static int F_89 ( unsigned long V_70 , unsigned long V_71 ,
struct V_99 * V_100 )
{
struct V_141 * V_142 = V_100 -> V_41 ;
unsigned long V_97 ;
int V_144 = 0 ;
T_12 V_140 = F_87 ( V_145 ) ;
for ( V_97 = V_70 ; V_97 < V_71 ; V_97 += V_27 ) {
V_144 = F_88 ( V_97 , & V_140 , V_142 ) ;
if ( V_144 )
break;
}
return V_144 ;
}
static void F_90 ( T_12 * V_140 ,
struct V_35 * V_36 , unsigned long V_97 , V_25 V_117 )
{
T_13 V_146 , V_66 ;
struct V_103 * V_103 = NULL ;
if ( F_45 ( V_117 ) ) {
V_146 = F_91 ( V_117 ) ;
V_66 = V_147 ;
V_103 = F_46 ( V_36 , V_97 , V_117 ) ;
} else if ( F_47 ( V_117 ) ) {
T_6 V_148 = F_48 ( V_117 ) ;
V_146 = F_92 ( V_148 ) |
( F_93 ( V_148 ) << V_149 ) ;
V_66 = V_150 ;
if ( F_50 ( V_148 ) )
V_103 = F_51 ( V_148 ) ;
} else {
* V_140 = F_87 ( V_145 ) ;
return;
}
if ( V_103 && ! F_54 ( V_103 ) )
V_66 |= V_151 ;
* V_140 = F_87 ( F_94 ( V_146 ) | F_95 ( V_19 ) | V_66 ) ;
}
static void F_96 ( T_12 * V_140 ,
T_7 V_116 , int V_152 )
{
if ( F_97 ( V_116 ) )
* V_140 = F_87 ( F_94 ( F_98 ( V_116 ) + V_152 )
| F_95 ( V_19 ) | V_147 ) ;
else
* V_140 = F_87 ( V_145 ) ;
}
static inline void F_96 ( T_12 * V_140 ,
T_7 V_116 , int V_152 )
{
}
static int F_99 ( T_7 * V_116 , unsigned long V_97 , unsigned long V_71 ,
struct V_99 * V_100 )
{
struct V_35 * V_36 ;
struct V_141 * V_142 = V_100 -> V_41 ;
V_25 * V_117 ;
int V_144 = 0 ;
T_12 V_140 = F_87 ( V_145 ) ;
V_36 = F_19 ( V_100 -> V_4 , V_97 ) ;
if ( V_36 && F_61 ( V_116 , V_36 ) == 1 ) {
for (; V_97 != V_71 ; V_97 += V_27 ) {
unsigned long V_152 ;
V_152 = ( V_97 & ~ V_153 ) >>
V_19 ;
F_96 ( & V_140 , * V_116 , V_152 ) ;
V_144 = F_88 ( V_97 , & V_140 , V_142 ) ;
if ( V_144 )
break;
}
F_62 ( & V_100 -> V_4 -> V_120 ) ;
return V_144 ;
}
if ( F_63 ( V_116 ) )
return 0 ;
for (; V_97 != V_71 ; V_97 += V_27 ) {
if ( V_36 && ( V_97 >= V_36 -> V_82 ) ) {
V_36 = F_19 ( V_100 -> V_4 , V_97 ) ;
V_140 = F_87 ( V_145 ) ;
}
if ( V_36 && ( V_36 -> V_81 <= V_97 ) &&
! F_68 ( V_36 ) ) {
V_117 = F_100 ( V_116 , V_97 ) ;
F_90 ( & V_140 , V_36 , V_97 , * V_117 ) ;
F_101 ( V_117 ) ;
}
V_144 = F_88 ( V_97 , & V_140 , V_142 ) ;
if ( V_144 )
return V_144 ;
}
F_66 () ;
return V_144 ;
}
static void F_102 ( T_12 * V_140 ,
V_25 V_117 , int V_152 )
{
if ( F_45 ( V_117 ) )
* V_140 = F_87 ( F_94 ( F_91 ( V_117 ) + V_152 )
| F_95 ( V_19 ) | V_147 ) ;
else
* V_140 = F_87 ( V_145 ) ;
}
static int F_103 ( V_25 * V_117 , unsigned long V_154 ,
unsigned long V_97 , unsigned long V_71 ,
struct V_99 * V_100 )
{
struct V_141 * V_142 = V_100 -> V_41 ;
int V_144 = 0 ;
T_12 V_140 ;
for (; V_97 != V_71 ; V_97 += V_27 ) {
int V_152 = ( V_97 & ~ V_154 ) >> V_19 ;
F_102 ( & V_140 , * V_117 , V_152 ) ;
V_144 = F_88 ( V_97 , & V_140 , V_142 ) ;
if ( V_144 )
return V_144 ;
}
F_66 () ;
return V_144 ;
}
static T_9 F_104 ( struct V_56 * V_56 , char T_10 * V_128 ,
T_11 V_92 , T_1 * V_129 )
{
struct V_65 * V_45 = F_84 ( V_56 -> V_74 . V_75 -> V_76 ) ;
struct V_3 * V_4 ;
struct V_141 V_142 ;
int V_59 = - V_48 ;
struct V_99 V_155 = {} ;
unsigned long V_156 ;
unsigned long V_157 ;
unsigned long V_158 ;
unsigned long V_159 ;
int V_160 = 0 ;
if ( ! V_45 )
goto V_51;
V_59 = - V_136 ;
if ( ( * V_129 % V_161 ) || ( V_92 % V_161 ) )
goto V_162;
V_59 = 0 ;
if ( ! V_92 )
goto V_162;
V_142 . V_32 = V_161 * ( V_163 >> V_19 ) ;
V_142 . V_130 = F_105 ( V_142 . V_32 , V_164 ) ;
V_59 = - V_60 ;
if ( ! V_142 . V_130 )
goto V_162;
V_4 = F_15 ( V_45 , V_49 ) ;
V_59 = F_106 ( V_4 ) ;
if ( ! V_4 || F_16 ( V_4 ) )
goto V_165;
V_155 . V_123 = F_99 ;
V_155 . V_166 = F_89 ;
#ifdef F_107
V_155 . V_167 = F_103 ;
#endif
V_155 . V_4 = V_4 ;
V_155 . V_41 = & V_142 ;
V_156 = * V_129 ;
V_157 = V_156 / V_161 ;
V_158 = V_157 << V_19 ;
V_159 = F_108 ( V_45 ) ;
if ( V_157 > F_108 ( V_45 ) >> V_19 )
V_158 = V_159 ;
V_59 = 0 ;
while ( V_92 && ( V_158 < V_159 ) ) {
int V_32 ;
unsigned long V_71 ;
V_142 . V_40 = 0 ;
V_71 = ( V_158 + V_163 ) & V_153 ;
if ( V_71 < V_158 || V_71 > V_159 )
V_71 = V_159 ;
F_17 ( & V_4 -> V_39 ) ;
V_59 = F_69 ( V_158 , V_71 , & V_155 ) ;
F_10 ( & V_4 -> V_39 ) ;
V_158 = V_71 ;
V_32 = F_109 ( V_92 , V_161 * V_142 . V_40 ) ;
if ( F_110 ( V_128 , V_142 . V_130 , V_32 ) ) {
V_59 = - V_133 ;
goto V_168;
}
V_160 += V_32 ;
V_128 += V_32 ;
V_92 -= V_32 ;
}
* V_129 += V_160 ;
if ( ! V_59 || V_59 == V_143 )
V_59 = V_160 ;
V_168:
F_11 ( V_4 ) ;
V_165:
F_27 ( V_142 . V_130 ) ;
V_162:
F_22 ( V_45 ) ;
V_51:
return V_59 ;
}
static void F_111 ( struct V_103 * V_103 , struct V_169 * V_170 , int F_58 ,
unsigned long V_171 )
{
int V_92 = F_57 ( V_103 ) ;
V_170 -> V_172 += V_171 ;
if ( F_58 || F_59 ( V_103 ) )
V_170 -> V_173 += V_171 ;
if ( F_112 ( V_103 ) )
V_170 -> V_174 += V_171 ;
if ( F_113 ( V_103 ) || F_114 ( V_103 ) )
V_170 -> V_175 += V_171 ;
if ( F_115 ( V_103 ) )
V_170 -> V_176 += V_171 ;
if ( F_54 ( V_103 ) )
V_170 -> V_177 += V_171 ;
if ( V_92 > V_170 -> V_178 )
V_170 -> V_178 = V_92 ;
V_170 -> V_179 [ F_116 ( V_103 ) ] += V_171 ;
}
static struct V_103 * F_117 ( V_25 V_117 , struct V_35 * V_36 ,
unsigned long V_97 )
{
struct V_103 * V_103 ;
int V_180 ;
if ( ! F_45 ( V_117 ) )
return NULL ;
V_103 = F_46 ( V_36 , V_97 , V_117 ) ;
if ( ! V_103 )
return NULL ;
if ( F_118 ( V_103 ) )
return NULL ;
V_180 = F_116 ( V_103 ) ;
if ( ! F_119 ( V_180 , V_181 [ V_182 ] ) )
return NULL ;
return V_103 ;
}
static int F_120 ( T_7 * V_116 , unsigned long V_97 ,
unsigned long V_71 , struct V_99 * V_100 )
{
struct V_169 * V_170 ;
T_8 * V_118 ;
V_25 * V_183 ;
V_25 * V_117 ;
V_170 = V_100 -> V_41 ;
if ( F_61 ( V_116 , V_170 -> V_36 ) == 1 ) {
V_25 V_184 = * ( V_25 * ) V_116 ;
struct V_103 * V_103 ;
V_103 = F_117 ( V_184 , V_170 -> V_36 , V_97 ) ;
if ( V_103 )
F_111 ( V_103 , V_170 , F_58 ( V_184 ) ,
V_119 / V_27 ) ;
F_62 ( & V_100 -> V_4 -> V_120 ) ;
return 0 ;
}
if ( F_63 ( V_116 ) )
return 0 ;
V_183 = V_117 = F_64 ( V_100 -> V_4 , V_116 , V_97 , & V_118 ) ;
do {
struct V_103 * V_103 = F_117 ( * V_117 , V_170 -> V_36 , V_97 ) ;
if ( ! V_103 )
continue;
F_111 ( V_103 , V_170 , F_58 ( * V_117 ) , 1 ) ;
} while ( V_117 ++ , V_97 += V_27 , V_97 != V_71 );
F_65 ( V_183 , V_118 ) ;
return 0 ;
}
static int F_121 ( V_25 * V_117 , unsigned long V_154 ,
unsigned long V_97 , unsigned long V_71 , struct V_99 * V_100 )
{
struct V_169 * V_170 ;
struct V_103 * V_103 ;
if ( F_122 ( * V_117 ) )
return 0 ;
V_103 = F_123 ( * V_117 ) ;
if ( ! V_103 )
return 0 ;
V_170 = V_100 -> V_41 ;
F_111 ( V_103 , V_170 , F_58 ( * V_117 ) , 1 ) ;
return 0 ;
}
static int F_121 ( V_25 * V_117 , unsigned long V_154 ,
unsigned long V_97 , unsigned long V_71 , struct V_99 * V_100 )
{
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , void * V_54 , int V_63 )
{
struct V_185 * V_186 = V_2 -> V_41 ;
struct V_33 * V_187 = & V_186 -> V_188 ;
struct V_35 * V_36 = V_54 ;
struct V_169 * V_170 = & V_186 -> V_170 ;
struct V_56 * V_56 = V_36 -> V_64 ;
struct V_3 * V_4 = V_36 -> V_38 ;
struct V_99 V_100 = {} ;
struct V_189 * V_190 ;
int V_191 ;
char V_130 [ 50 ] ;
if ( ! V_4 )
return 0 ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_170 -> V_36 = V_36 ;
V_100 . V_167 = F_121 ;
V_100 . V_123 = F_120 ;
V_100 . V_41 = V_170 ;
V_100 . V_4 = V_4 ;
V_190 = F_125 ( V_187 -> V_45 , V_36 , V_36 -> V_81 ) ;
F_126 ( V_130 , sizeof( V_130 ) , V_190 , 0 ) ;
F_127 ( V_190 ) ;
F_5 ( V_2 , L_35 , V_36 -> V_81 , V_130 ) ;
if ( V_56 ) {
F_5 ( V_2 , L_36 ) ;
F_33 ( V_2 , & V_56 -> V_74 , L_37 ) ;
} else if ( V_36 -> V_81 <= V_4 -> V_89 && V_36 -> V_82 >= V_4 -> V_90 ) {
F_5 ( V_2 , L_38 ) ;
} else {
T_4 V_88 = F_35 ( V_187 -> V_45 , V_36 , V_63 ) ;
if ( V_88 != 0 ) {
if ( ! V_63 || ( V_36 -> V_81 <= V_4 -> V_91 &&
V_36 -> V_82 >= V_4 -> V_91 ) )
F_5 ( V_2 , L_39 ) ;
else
F_5 ( V_2 , L_40 , V_88 ) ;
}
}
if ( F_68 ( V_36 ) )
F_5 ( V_2 , L_41 ) ;
F_69 ( V_36 -> V_81 , V_36 -> V_82 , & V_100 ) ;
if ( ! V_170 -> V_172 )
goto V_51;
if ( V_170 -> V_177 )
F_5 ( V_2 , L_42 , V_170 -> V_177 ) ;
if ( V_170 -> V_173 )
F_5 ( V_2 , L_43 , V_170 -> V_173 ) ;
if ( V_170 -> V_172 != V_170 -> V_177 && V_170 -> V_172 != V_170 -> V_173 )
F_5 ( V_2 , L_44 , V_170 -> V_172 ) ;
if ( V_170 -> V_178 > 1 )
F_5 ( V_2 , L_45 , V_170 -> V_178 ) ;
if ( V_170 -> V_174 )
F_5 ( V_2 , L_46 , V_170 -> V_174 ) ;
if ( V_170 -> V_175 < V_170 -> V_172 && ! F_68 ( V_36 ) )
F_5 ( V_2 , L_47 , V_170 -> V_175 ) ;
if ( V_170 -> V_176 )
F_5 ( V_2 , L_48 , V_170 -> V_176 ) ;
F_128 (n, N_HIGH_MEMORY)
if ( V_170 -> V_179 [ V_191 ] )
F_5 ( V_2 , L_49 , V_191 , V_170 -> V_179 [ V_191 ] ) ;
V_51:
F_37 ( V_2 , '\n' ) ;
if ( V_2 -> V_92 < V_2 -> V_93 )
V_2 -> V_43 = ( V_36 != V_187 -> V_37 ) ? V_36 -> V_81 : 0 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , void * V_54 )
{
return F_124 ( V_2 , V_54 , 1 ) ;
}
static int F_130 ( struct V_1 * V_2 , void * V_54 )
{
return F_124 ( V_2 , V_54 , 0 ) ;
}
static int F_131 ( struct V_55 * V_55 , struct V_56 * V_56 ,
const struct V_57 * V_58 )
{
struct V_185 * V_34 ;
int V_59 = - V_60 ;
V_34 = F_24 ( sizeof( * V_34 ) , V_61 ) ;
if ( V_34 ) {
V_34 -> V_188 . V_46 = F_25 ( V_55 ) ;
V_59 = F_26 ( V_56 , V_58 ) ;
if ( ! V_59 ) {
struct V_1 * V_2 = V_56 -> V_62 ;
V_2 -> V_41 = V_34 ;
} else {
F_27 ( V_34 ) ;
}
}
return V_59 ;
}
static int F_132 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_131 ( V_55 , V_56 , & V_192 ) ;
}
static int F_133 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
return F_131 ( V_55 , V_56 , & V_193 ) ;
}
