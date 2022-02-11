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
static void
F_28 ( struct V_1 * V_2 , struct V_35 * V_36 , int V_62 )
{
struct V_3 * V_4 = V_36 -> V_38 ;
struct V_55 * V_55 = V_36 -> V_63 ;
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_64 * V_45 = V_34 -> V_45 ;
T_2 V_65 = V_36 -> V_66 ;
unsigned long V_67 = 0 ;
unsigned long long V_68 = 0 ;
unsigned long V_69 , V_70 ;
T_3 V_71 = 0 ;
int V_32 ;
const char * V_72 = NULL ;
if ( V_55 ) {
struct V_54 * V_54 = V_36 -> V_63 -> V_73 . V_74 -> V_75 ;
V_71 = V_54 -> V_76 -> V_77 ;
V_67 = V_54 -> V_78 ;
V_68 = ( ( T_1 ) V_36 -> V_79 ) << V_19 ;
}
V_69 = V_36 -> V_80 ;
if ( F_29 ( V_36 , V_69 ) )
V_69 += V_27 ;
V_70 = V_36 -> V_81 ;
if ( F_30 ( V_36 , V_70 ) )
V_70 -= V_27 ;
F_5 ( V_2 , L_14 ,
V_69 ,
V_70 ,
V_65 & V_82 ? 'r' : '-' ,
V_65 & V_83 ? 'w' : '-' ,
V_65 & V_84 ? 'x' : '-' ,
V_65 & V_85 ? 's' : 'p' ,
V_68 ,
F_31 ( V_71 ) , F_32 ( V_71 ) , V_67 , & V_32 ) ;
if ( V_55 ) {
F_8 ( V_2 , V_32 ) ;
F_33 ( V_2 , & V_55 -> V_73 , L_15 ) ;
goto V_86;
}
V_72 = F_34 ( V_36 ) ;
if ( ! V_72 ) {
T_4 V_87 ;
if ( ! V_4 ) {
V_72 = L_16 ;
goto V_86;
}
if ( V_36 -> V_80 <= V_4 -> V_88 &&
V_36 -> V_81 >= V_4 -> V_89 ) {
V_72 = L_17 ;
goto V_86;
}
V_87 = F_35 ( V_45 , V_36 , V_62 ) ;
if ( V_87 != 0 ) {
if ( ! V_62 || ( V_36 -> V_80 <= V_4 -> V_90 &&
V_36 -> V_81 >= V_4 -> V_90 ) ) {
V_72 = L_18 ;
} else {
F_8 ( V_2 , V_32 ) ;
F_5 ( V_2 , L_19 , V_87 ) ;
}
}
}
V_86:
if ( V_72 ) {
F_8 ( V_2 , V_32 ) ;
F_36 ( V_2 , V_72 ) ;
}
F_37 ( V_2 , '\n' ) ;
}
static int F_38 ( struct V_1 * V_2 , void * V_53 , int V_62 )
{
struct V_35 * V_36 = V_53 ;
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_64 * V_45 = V_34 -> V_45 ;
F_28 ( V_2 , V_36 , V_62 ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
V_2 -> V_43 = ( V_36 != F_18 ( V_45 -> V_4 ) )
? V_36 -> V_80 : 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , void * V_53 )
{
return F_38 ( V_2 , V_53 , 1 ) ;
}
static int F_40 ( struct V_1 * V_2 , void * V_53 )
{
return F_38 ( V_2 , V_53 , 0 ) ;
}
static int F_41 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_23 ( V_54 , V_55 , & V_93 ) ;
}
static int F_42 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_23 ( V_54 , V_55 , & V_94 ) ;
}
static void F_43 ( V_25 V_95 , unsigned long V_96 ,
unsigned long V_97 , struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_41 ;
struct V_35 * V_36 = V_101 -> V_36 ;
struct V_102 * V_102 ;
int V_103 ;
if ( F_44 ( V_95 ) ) {
V_101 -> V_8 += V_97 ;
return;
}
if ( ! F_45 ( V_95 ) )
return;
V_102 = F_46 ( V_36 , V_96 , V_95 ) ;
if ( ! V_102 )
return;
if ( F_47 ( V_102 ) )
V_101 -> V_104 += V_97 ;
V_101 -> V_29 += V_97 ;
if ( F_48 ( V_95 ) || F_49 ( V_102 ) )
V_101 -> V_105 += V_97 ;
V_103 = F_50 ( V_102 ) ;
if ( V_103 >= 2 ) {
if ( F_51 ( V_95 ) || F_52 ( V_102 ) )
V_101 -> V_106 += V_97 ;
else
V_101 -> V_107 += V_97 ;
V_101 -> V_108 += ( V_97 << V_109 ) / V_103 ;
} else {
if ( F_51 ( V_95 ) || F_52 ( V_102 ) )
V_101 -> V_110 += V_97 ;
else
V_101 -> V_111 += V_97 ;
V_101 -> V_108 += ( V_97 << V_109 ) ;
}
}
static int F_53 ( T_5 * V_112 , unsigned long V_96 , unsigned long V_70 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = V_99 -> V_41 ;
struct V_35 * V_36 = V_101 -> V_36 ;
V_25 * V_113 ;
T_6 * V_114 ;
if ( F_54 ( V_112 , V_36 ) == 1 ) {
F_43 ( * ( V_25 * ) V_112 , V_96 , V_115 , V_99 ) ;
F_55 ( & V_99 -> V_4 -> V_116 ) ;
V_101 -> V_117 += V_115 ;
return 0 ;
}
if ( F_56 ( V_112 ) )
return 0 ;
V_113 = F_57 ( V_36 -> V_38 , V_112 , V_96 , & V_114 ) ;
for (; V_96 != V_70 ; V_113 ++ , V_96 += V_27 )
F_43 ( * V_113 , V_96 , V_27 , V_99 ) ;
F_58 ( V_113 - 1 , V_114 ) ;
F_59 () ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 , void * V_53 , int V_62 )
{
struct V_33 * V_34 = V_2 -> V_41 ;
struct V_64 * V_45 = V_34 -> V_45 ;
struct V_35 * V_36 = V_53 ;
struct V_100 V_101 ;
struct V_98 V_118 = {
. V_119 = F_53 ,
. V_4 = V_36 -> V_38 ,
. V_41 = & V_101 ,
} ;
memset ( & V_101 , 0 , sizeof V_101 ) ;
V_101 . V_36 = V_36 ;
if ( V_36 -> V_38 && ! F_61 ( V_36 ) )
F_62 ( V_36 -> V_80 , V_36 -> V_81 , & V_118 ) ;
F_28 ( V_2 , V_36 , V_62 ) ;
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
( V_36 -> V_81 - V_36 -> V_80 ) >> 10 ,
V_101 . V_29 >> 10 ,
( unsigned long ) ( V_101 . V_108 >> ( 10 + V_109 ) ) ,
V_101 . V_107 >> 10 ,
V_101 . V_106 >> 10 ,
V_101 . V_111 >> 10 ,
V_101 . V_110 >> 10 ,
V_101 . V_105 >> 10 ,
V_101 . V_104 >> 10 ,
V_101 . V_117 >> 10 ,
V_101 . V_8 >> 10 ,
F_63 ( V_36 ) >> 10 ,
F_64 ( V_36 ) >> 10 ,
( V_36 -> V_66 & V_120 ) ?
( unsigned long ) ( V_101 . V_108 >> ( 10 + V_109 ) ) : 0 ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
V_2 -> V_43 = ( V_36 != F_18 ( V_45 -> V_4 ) )
? V_36 -> V_80 : 0 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , void * V_53 )
{
return F_60 ( V_2 , V_53 , 1 ) ;
}
static int F_66 ( struct V_1 * V_2 , void * V_53 )
{
return F_60 ( V_2 , V_53 , 0 ) ;
}
static int F_67 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_23 ( V_54 , V_55 , & V_121 ) ;
}
static int F_68 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_23 ( V_54 , V_55 , & V_122 ) ;
}
static int F_69 ( T_5 * V_112 , unsigned long V_96 ,
unsigned long V_70 , struct V_98 * V_99 )
{
struct V_35 * V_36 = V_99 -> V_41 ;
V_25 * V_113 , V_95 ;
T_6 * V_114 ;
struct V_102 * V_102 ;
F_70 ( V_99 -> V_4 , V_112 ) ;
if ( F_56 ( V_112 ) )
return 0 ;
V_113 = F_57 ( V_36 -> V_38 , V_112 , V_96 , & V_114 ) ;
for (; V_96 != V_70 ; V_113 ++ , V_96 += V_27 ) {
V_95 = * V_113 ;
if ( ! F_45 ( V_95 ) )
continue;
V_102 = F_46 ( V_36 , V_96 , V_95 ) ;
if ( ! V_102 )
continue;
F_71 ( V_36 , V_96 , V_113 ) ;
F_72 ( V_102 ) ;
}
F_58 ( V_113 - 1 , V_114 ) ;
F_59 () ;
return 0 ;
}
static T_7 F_73 ( struct V_55 * V_55 , const char T_8 * V_123 ,
T_9 V_91 , T_1 * V_124 )
{
struct V_64 * V_45 ;
char V_125 [ V_126 ] ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int type ;
int V_127 ;
memset ( V_125 , 0 , sizeof( V_125 ) ) ;
if ( V_91 > sizeof( V_125 ) - 1 )
V_91 = sizeof( V_125 ) - 1 ;
if ( F_74 ( V_125 , V_123 , V_91 ) )
return - V_128 ;
V_127 = F_75 ( F_76 ( V_125 ) , 10 , & type ) ;
if ( V_127 < 0 )
return V_127 ;
if ( type < V_129 || type > V_130 )
return - V_131 ;
V_45 = F_77 ( V_55 -> V_73 . V_74 -> V_75 ) ;
if ( ! V_45 )
return - V_48 ;
V_4 = F_78 ( V_45 ) ;
if ( V_4 ) {
struct V_98 V_132 = {
. V_119 = F_69 ,
. V_4 = V_4 ,
} ;
F_17 ( & V_4 -> V_39 ) ;
for ( V_36 = V_4 -> V_52 ; V_36 ; V_36 = V_36 -> V_49 ) {
V_132 . V_41 = V_36 ;
if ( F_61 ( V_36 ) )
continue;
if ( type == V_133 && V_36 -> V_63 )
continue;
if ( type == V_130 && ! V_36 -> V_63 )
continue;
F_62 ( V_36 -> V_80 , V_36 -> V_81 ,
& V_132 ) ;
}
F_79 ( V_4 ) ;
F_10 ( & V_4 -> V_39 ) ;
F_11 ( V_4 ) ;
}
F_22 ( V_45 ) ;
return V_91 ;
}
static inline T_10 F_80 ( T_11 V_134 )
{
return ( T_10 ) { . V_135 = V_134 } ;
}
static int F_81 ( unsigned long V_96 , T_10 * V_135 ,
struct V_136 * V_137 )
{
V_137 -> V_125 [ V_137 -> V_40 ++ ] = * V_135 ;
if ( V_137 -> V_40 >= V_137 -> V_32 )
return V_138 ;
return 0 ;
}
static int F_82 ( unsigned long V_69 , unsigned long V_70 ,
struct V_98 * V_99 )
{
struct V_136 * V_137 = V_99 -> V_41 ;
unsigned long V_96 ;
int V_139 = 0 ;
T_10 V_135 = F_80 ( V_140 ) ;
for ( V_96 = V_69 ; V_96 < V_70 ; V_96 += V_27 ) {
V_139 = F_81 ( V_96 , & V_135 , V_137 ) ;
if ( V_139 )
break;
}
return V_139 ;
}
static T_11 F_83 ( V_25 V_113 )
{
T_12 V_141 = F_84 ( V_113 ) ;
return F_85 ( V_141 ) | ( F_86 ( V_141 ) << V_142 ) ;
}
static void F_87 ( T_10 * V_135 , V_25 V_113 )
{
if ( F_44 ( V_113 ) )
* V_135 = F_80 ( F_88 ( F_83 ( V_113 ) )
| F_89 ( V_19 ) | V_143 ) ;
else if ( F_45 ( V_113 ) )
* V_135 = F_80 ( F_88 ( F_90 ( V_113 ) )
| F_89 ( V_19 ) | V_144 ) ;
else
* V_135 = F_80 ( V_140 ) ;
}
static void F_91 ( T_10 * V_135 ,
T_5 V_112 , int V_145 )
{
if ( F_92 ( V_112 ) )
* V_135 = F_80 ( F_88 ( F_93 ( V_112 ) + V_145 )
| F_89 ( V_19 ) | V_144 ) ;
else
* V_135 = F_80 ( V_140 ) ;
}
static inline void F_91 ( T_10 * V_135 ,
T_5 V_112 , int V_145 )
{
}
static int F_94 ( T_5 * V_112 , unsigned long V_96 , unsigned long V_70 ,
struct V_98 * V_99 )
{
struct V_35 * V_36 ;
struct V_136 * V_137 = V_99 -> V_41 ;
V_25 * V_113 ;
int V_139 = 0 ;
T_10 V_135 = F_80 ( V_140 ) ;
V_36 = F_19 ( V_99 -> V_4 , V_96 ) ;
if ( F_54 ( V_112 , V_36 ) == 1 ) {
for (; V_96 != V_70 ; V_96 += V_27 ) {
unsigned long V_145 ;
V_145 = ( V_96 & ~ V_146 ) >>
V_19 ;
F_91 ( & V_135 , * V_112 , V_145 ) ;
V_139 = F_81 ( V_96 , & V_135 , V_137 ) ;
if ( V_139 )
break;
}
F_55 ( & V_99 -> V_4 -> V_116 ) ;
return V_139 ;
}
if ( F_56 ( V_112 ) )
return 0 ;
for (; V_96 != V_70 ; V_96 += V_27 ) {
if ( V_36 && ( V_96 >= V_36 -> V_81 ) ) {
V_36 = F_19 ( V_99 -> V_4 , V_96 ) ;
V_135 = F_80 ( V_140 ) ;
}
if ( V_36 && ( V_36 -> V_80 <= V_96 ) &&
! F_61 ( V_36 ) ) {
V_113 = F_95 ( V_112 , V_96 ) ;
F_87 ( & V_135 , * V_113 ) ;
F_96 ( V_113 ) ;
}
V_139 = F_81 ( V_96 , & V_135 , V_137 ) ;
if ( V_139 )
return V_139 ;
}
F_59 () ;
return V_139 ;
}
static void F_97 ( T_10 * V_135 ,
V_25 V_113 , int V_145 )
{
if ( F_45 ( V_113 ) )
* V_135 = F_80 ( F_88 ( F_90 ( V_113 ) + V_145 )
| F_89 ( V_19 ) | V_144 ) ;
else
* V_135 = F_80 ( V_140 ) ;
}
static int F_98 ( V_25 * V_113 , unsigned long V_147 ,
unsigned long V_96 , unsigned long V_70 ,
struct V_98 * V_99 )
{
struct V_136 * V_137 = V_99 -> V_41 ;
int V_139 = 0 ;
T_10 V_135 ;
for (; V_96 != V_70 ; V_96 += V_27 ) {
int V_145 = ( V_96 & ~ V_147 ) >> V_19 ;
F_97 ( & V_135 , * V_113 , V_145 ) ;
V_139 = F_81 ( V_96 , & V_135 , V_137 ) ;
if ( V_139 )
return V_139 ;
}
F_59 () ;
return V_139 ;
}
static T_7 F_99 ( struct V_55 * V_55 , char T_8 * V_123 ,
T_9 V_91 , T_1 * V_124 )
{
struct V_64 * V_45 = F_77 ( V_55 -> V_73 . V_74 -> V_75 ) ;
struct V_3 * V_4 ;
struct V_136 V_137 ;
int V_58 = - V_48 ;
struct V_98 V_148 = {} ;
unsigned long V_149 ;
unsigned long V_150 ;
unsigned long V_151 ;
unsigned long V_152 ;
int V_153 = 0 ;
if ( ! V_45 )
goto V_50;
V_58 = - V_131 ;
if ( ( * V_124 % V_154 ) || ( V_91 % V_154 ) )
goto V_155;
V_58 = 0 ;
if ( ! V_91 )
goto V_155;
V_137 . V_32 = V_154 * ( V_156 >> V_19 ) ;
V_137 . V_125 = F_100 ( V_137 . V_32 , V_157 ) ;
V_58 = - V_59 ;
if ( ! V_137 . V_125 )
goto V_155;
V_4 = F_15 ( V_45 ) ;
V_58 = F_101 ( V_4 ) ;
if ( ! V_4 || F_16 ( V_4 ) )
goto V_158;
V_148 . V_119 = F_94 ;
V_148 . V_159 = F_82 ;
#ifdef F_102
V_148 . V_160 = F_98 ;
#endif
V_148 . V_4 = V_4 ;
V_148 . V_41 = & V_137 ;
V_149 = * V_124 ;
V_150 = V_149 / V_154 ;
V_151 = V_150 << V_19 ;
V_152 = F_103 ( V_45 ) ;
if ( V_150 > F_103 ( V_45 ) >> V_19 )
V_151 = V_152 ;
V_58 = 0 ;
while ( V_91 && ( V_151 < V_152 ) ) {
int V_32 ;
unsigned long V_70 ;
V_137 . V_40 = 0 ;
V_70 = ( V_151 + V_156 ) & V_146 ;
if ( V_70 < V_151 || V_70 > V_152 )
V_70 = V_152 ;
F_17 ( & V_4 -> V_39 ) ;
V_58 = F_62 ( V_151 , V_70 , & V_148 ) ;
F_10 ( & V_4 -> V_39 ) ;
V_151 = V_70 ;
V_32 = F_104 ( V_91 , V_154 * V_137 . V_40 ) ;
if ( F_105 ( V_123 , V_137 . V_125 , V_32 ) ) {
V_58 = - V_128 ;
goto V_161;
}
V_153 += V_32 ;
V_123 += V_32 ;
V_91 -= V_32 ;
}
* V_124 += V_153 ;
if ( ! V_58 || V_58 == V_138 )
V_58 = V_153 ;
V_161:
F_11 ( V_4 ) ;
V_158:
F_27 ( V_137 . V_125 ) ;
V_155:
F_22 ( V_45 ) ;
V_50:
return V_58 ;
}
static void F_106 ( struct V_102 * V_102 , struct V_162 * V_163 , int F_51 ,
unsigned long V_164 )
{
int V_91 = F_50 ( V_102 ) ;
V_163 -> V_165 += V_164 ;
if ( F_51 || F_52 ( V_102 ) )
V_163 -> V_166 += V_164 ;
if ( F_107 ( V_102 ) )
V_163 -> V_167 += V_164 ;
if ( F_108 ( V_102 ) || F_109 ( V_102 ) )
V_163 -> V_168 += V_164 ;
if ( F_110 ( V_102 ) )
V_163 -> V_169 += V_164 ;
if ( F_47 ( V_102 ) )
V_163 -> V_170 += V_164 ;
if ( V_91 > V_163 -> V_171 )
V_163 -> V_171 = V_91 ;
V_163 -> V_172 [ F_111 ( V_102 ) ] += V_164 ;
}
static struct V_102 * F_112 ( V_25 V_113 , struct V_35 * V_36 ,
unsigned long V_96 )
{
struct V_102 * V_102 ;
int V_173 ;
if ( ! F_45 ( V_113 ) )
return NULL ;
V_102 = F_46 ( V_36 , V_96 , V_113 ) ;
if ( ! V_102 )
return NULL ;
if ( F_113 ( V_102 ) )
return NULL ;
V_173 = F_111 ( V_102 ) ;
if ( ! F_114 ( V_173 , V_174 [ V_175 ] ) )
return NULL ;
return V_102 ;
}
static int F_115 ( T_5 * V_112 , unsigned long V_96 ,
unsigned long V_70 , struct V_98 * V_99 )
{
struct V_162 * V_163 ;
T_6 * V_114 ;
V_25 * V_176 ;
V_25 * V_113 ;
V_163 = V_99 -> V_41 ;
if ( F_54 ( V_112 , V_163 -> V_36 ) == 1 ) {
V_25 V_177 = * ( V_25 * ) V_112 ;
struct V_102 * V_102 ;
V_102 = F_112 ( V_177 , V_163 -> V_36 , V_96 ) ;
if ( V_102 )
F_106 ( V_102 , V_163 , F_51 ( V_177 ) ,
V_115 / V_27 ) ;
F_55 ( & V_99 -> V_4 -> V_116 ) ;
return 0 ;
}
if ( F_56 ( V_112 ) )
return 0 ;
V_176 = V_113 = F_57 ( V_99 -> V_4 , V_112 , V_96 , & V_114 ) ;
do {
struct V_102 * V_102 = F_112 ( * V_113 , V_163 -> V_36 , V_96 ) ;
if ( ! V_102 )
continue;
F_106 ( V_102 , V_163 , F_51 ( * V_113 ) , 1 ) ;
} while ( V_113 ++ , V_96 += V_27 , V_96 != V_70 );
F_58 ( V_176 , V_114 ) ;
return 0 ;
}
static int F_116 ( V_25 * V_113 , unsigned long V_147 ,
unsigned long V_96 , unsigned long V_70 , struct V_98 * V_99 )
{
struct V_162 * V_163 ;
struct V_102 * V_102 ;
if ( F_117 ( * V_113 ) )
return 0 ;
V_102 = F_118 ( * V_113 ) ;
if ( ! V_102 )
return 0 ;
V_163 = V_99 -> V_41 ;
F_106 ( V_102 , V_163 , F_51 ( * V_113 ) , 1 ) ;
return 0 ;
}
static int F_116 ( V_25 * V_113 , unsigned long V_147 ,
unsigned long V_96 , unsigned long V_70 , struct V_98 * V_99 )
{
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , void * V_53 , int V_62 )
{
struct V_178 * V_179 = V_2 -> V_41 ;
struct V_33 * V_180 = & V_179 -> V_181 ;
struct V_35 * V_36 = V_53 ;
struct V_162 * V_163 = & V_179 -> V_163 ;
struct V_55 * V_55 = V_36 -> V_63 ;
struct V_3 * V_4 = V_36 -> V_38 ;
struct V_98 V_99 = {} ;
struct V_182 * V_183 ;
int V_184 ;
char V_125 [ 50 ] ;
if ( ! V_4 )
return 0 ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
V_163 -> V_36 = V_36 ;
V_99 . V_160 = F_116 ;
V_99 . V_119 = F_115 ;
V_99 . V_41 = V_163 ;
V_99 . V_4 = V_4 ;
V_183 = F_120 ( V_180 -> V_45 , V_36 , V_36 -> V_80 ) ;
F_121 ( V_125 , sizeof( V_125 ) , V_183 , 0 ) ;
F_122 ( V_183 ) ;
F_5 ( V_2 , L_34 , V_36 -> V_80 , V_125 ) ;
if ( V_55 ) {
F_5 ( V_2 , L_35 ) ;
F_33 ( V_2 , & V_55 -> V_73 , L_36 ) ;
} else if ( V_36 -> V_80 <= V_4 -> V_88 && V_36 -> V_81 >= V_4 -> V_89 ) {
F_5 ( V_2 , L_37 ) ;
} else {
T_4 V_87 = F_35 ( V_180 -> V_45 , V_36 , V_62 ) ;
if ( V_87 != 0 ) {
if ( ! V_62 || ( V_36 -> V_80 <= V_4 -> V_90 &&
V_36 -> V_81 >= V_4 -> V_90 ) )
F_5 ( V_2 , L_38 ) ;
else
F_5 ( V_2 , L_39 , V_87 ) ;
}
}
if ( F_61 ( V_36 ) )
F_5 ( V_2 , L_40 ) ;
F_62 ( V_36 -> V_80 , V_36 -> V_81 , & V_99 ) ;
if ( ! V_163 -> V_165 )
goto V_50;
if ( V_163 -> V_170 )
F_5 ( V_2 , L_41 , V_163 -> V_170 ) ;
if ( V_163 -> V_166 )
F_5 ( V_2 , L_42 , V_163 -> V_166 ) ;
if ( V_163 -> V_165 != V_163 -> V_170 && V_163 -> V_165 != V_163 -> V_166 )
F_5 ( V_2 , L_43 , V_163 -> V_165 ) ;
if ( V_163 -> V_171 > 1 )
F_5 ( V_2 , L_44 , V_163 -> V_171 ) ;
if ( V_163 -> V_167 )
F_5 ( V_2 , L_45 , V_163 -> V_167 ) ;
if ( V_163 -> V_168 < V_163 -> V_165 && ! F_61 ( V_36 ) )
F_5 ( V_2 , L_46 , V_163 -> V_168 ) ;
if ( V_163 -> V_169 )
F_5 ( V_2 , L_47 , V_163 -> V_169 ) ;
F_123 (n, N_HIGH_MEMORY)
if ( V_163 -> V_172 [ V_184 ] )
F_5 ( V_2 , L_48 , V_184 , V_163 -> V_172 [ V_184 ] ) ;
V_50:
F_37 ( V_2 , '\n' ) ;
if ( V_2 -> V_91 < V_2 -> V_92 )
V_2 -> V_43 = ( V_36 != V_180 -> V_37 ) ? V_36 -> V_80 : 0 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , void * V_53 )
{
return F_119 ( V_2 , V_53 , 1 ) ;
}
static int F_125 ( struct V_1 * V_2 , void * V_53 )
{
return F_119 ( V_2 , V_53 , 0 ) ;
}
static int F_126 ( struct V_54 * V_54 , struct V_55 * V_55 ,
const struct V_56 * V_57 )
{
struct V_178 * V_34 ;
int V_58 = - V_59 ;
V_34 = F_24 ( sizeof( * V_34 ) , V_60 ) ;
if ( V_34 ) {
V_34 -> V_181 . V_46 = F_25 ( V_54 ) ;
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
static int F_127 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_126 ( V_54 , V_55 , & V_185 ) ;
}
static int F_128 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return F_126 ( V_54 , V_55 , & V_186 ) ;
}
