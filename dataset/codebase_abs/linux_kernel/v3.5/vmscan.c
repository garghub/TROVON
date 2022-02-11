static bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return true ;
}
static unsigned long F_2 ( struct V_4 * V_4 , enum V_5 V_6 )
{
if ( ! F_3 () )
return F_4 ( V_4 , V_6 ) ;
return F_5 ( F_6 ( V_4 ) , V_7 + V_6 ) ;
}
void F_7 ( struct V_8 * V_8 )
{
F_8 ( & V_8 -> V_9 , 0 ) ;
F_9 ( & V_10 ) ;
F_10 ( & V_8 -> V_11 , & V_12 ) ;
F_11 ( & V_10 ) ;
}
void F_12 ( struct V_8 * V_8 )
{
F_9 ( & V_10 ) ;
F_13 ( & V_8 -> V_11 ) ;
F_11 ( & V_10 ) ;
}
static inline int F_14 ( struct V_8 * V_8 ,
struct V_13 * V_2 ,
unsigned long V_14 )
{
V_2 -> V_14 = V_14 ;
return (* V_8 -> V_15 )( V_8 , V_2 ) ;
}
unsigned long F_15 ( struct V_13 * V_15 ,
unsigned long V_16 ,
unsigned long V_17 )
{
struct V_8 * V_8 ;
unsigned long V_18 = 0 ;
if ( V_16 == 0 )
V_16 = V_19 ;
if ( ! F_16 ( & V_10 ) ) {
V_18 = 1 ;
goto V_20;
}
F_17 (shrinker, &shrinker_list, list) {
unsigned long long V_21 ;
long V_22 ;
long V_23 ;
int V_24 = 0 ;
long V_25 ;
long V_26 ;
long V_27 = V_8 -> V_28 ? V_8 -> V_28
: V_29 ;
V_23 = F_14 ( V_8 , V_15 , 0 ) ;
if ( V_23 <= 0 )
continue;
V_25 = F_18 ( & V_8 -> V_9 , 0 ) ;
V_22 = V_25 ;
V_21 = ( 4 * V_16 ) / V_8 -> V_30 ;
V_21 *= V_23 ;
F_19 ( V_21 , V_17 + 1 ) ;
V_22 += V_21 ;
if ( V_22 < 0 ) {
F_20 ( V_31 L_1
L_2 ,
V_8 -> V_15 , V_22 ) ;
V_22 = V_23 ;
}
if ( V_21 < V_23 / 4 )
V_22 = F_21 ( V_22 , V_23 / 2 ) ;
if ( V_22 > V_23 * 2 )
V_22 = V_23 * 2 ;
F_22 ( V_8 , V_15 , V_25 ,
V_16 , V_17 ,
V_23 , V_21 , V_22 ) ;
while ( V_22 >= V_27 ) {
int V_32 ;
V_32 = F_14 ( V_8 , V_15 , 0 ) ;
V_24 = F_14 ( V_8 , V_15 ,
V_27 ) ;
if ( V_24 == - 1 )
break;
if ( V_24 < V_32 )
V_18 += V_32 - V_24 ;
F_23 ( V_33 , V_27 ) ;
V_22 -= V_27 ;
F_24 () ;
}
if ( V_22 > 0 )
V_26 = F_25 ( V_22 ,
& V_8 -> V_9 ) ;
else
V_26 = F_26 ( & V_8 -> V_9 ) ;
F_27 ( V_8 , V_24 , V_25 , V_26 ) ;
}
F_28 ( & V_10 ) ;
V_20:
F_24 () ;
return V_18 ;
}
static inline int F_29 ( struct V_34 * V_34 )
{
return F_30 ( V_34 ) - F_31 ( V_34 ) == 2 ;
}
static int F_32 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
if ( V_37 -> V_38 & V_39 )
return 1 ;
if ( ! F_33 ( V_36 ) )
return 1 ;
if ( V_36 == V_37 -> V_35 )
return 1 ;
return 0 ;
}
static void F_34 ( struct V_40 * V_41 ,
struct V_34 * V_34 , int error )
{
F_35 ( V_34 ) ;
if ( F_36 ( V_34 ) == V_41 )
F_37 ( V_41 , error ) ;
F_38 ( V_34 ) ;
}
static T_1 F_39 ( struct V_34 * V_34 , struct V_40 * V_41 ,
struct V_1 * V_2 )
{
if ( ! F_29 ( V_34 ) )
return V_42 ;
if ( ! V_41 ) {
if ( F_31 ( V_34 ) ) {
if ( F_40 ( V_34 ) ) {
F_41 ( V_34 ) ;
F_20 ( L_3 , V_43 ) ;
return V_44 ;
}
}
return V_42 ;
}
if ( V_41 -> V_45 -> V_46 == NULL )
return V_47 ;
if ( ! F_32 ( V_41 -> V_35 , V_2 ) )
return V_42 ;
if ( F_42 ( V_34 ) ) {
int V_48 ;
struct V_49 V_50 = {
. V_51 = V_52 ,
. V_53 = V_19 ,
. V_54 = 0 ,
. V_55 = V_56 ,
. V_57 = 1 ,
} ;
F_43 ( V_34 ) ;
V_48 = V_41 -> V_45 -> V_46 ( V_34 , & V_50 ) ;
if ( V_48 < 0 )
F_34 ( V_41 , V_34 , V_48 ) ;
if ( V_48 == V_58 ) {
F_44 ( V_34 ) ;
return V_47 ;
}
if ( ! F_45 ( V_34 ) ) {
F_44 ( V_34 ) ;
}
F_46 ( V_34 , F_47 ( V_34 ) ) ;
F_48 ( V_34 , V_59 ) ;
return V_60 ;
}
return V_44 ;
}
static int F_49 ( struct V_40 * V_41 , struct V_34 * V_34 )
{
F_50 ( ! F_51 ( V_34 ) ) ;
F_50 ( V_41 != F_36 ( V_34 ) ) ;
F_52 ( & V_41 -> V_61 ) ;
if ( ! F_53 ( V_34 , 2 ) )
goto V_62;
if ( F_54 ( F_55 ( V_34 ) ) ) {
F_56 ( V_34 , 2 ) ;
goto V_62;
}
if ( F_57 ( V_34 ) ) {
T_2 V_63 = { . V_64 = F_58 (page) } ;
F_59 ( V_34 ) ;
F_60 ( & V_41 -> V_61 ) ;
F_61 ( V_63 , V_34 ) ;
} else {
void (* F_62)( struct V_34 * );
F_62 = V_41 -> V_45 -> F_62 ;
F_63 ( V_34 ) ;
F_60 ( & V_41 -> V_61 ) ;
F_64 ( V_34 ) ;
if ( F_62 != NULL )
F_62 ( V_34 ) ;
}
return 1 ;
V_62:
F_60 ( & V_41 -> V_61 ) ;
return 0 ;
}
int F_65 ( struct V_40 * V_41 , struct V_34 * V_34 )
{
if ( F_49 ( V_41 , V_34 ) ) {
F_56 ( V_34 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_66 ( struct V_34 * V_34 )
{
int V_6 ;
int V_65 = ! ! F_67 ( V_34 ) ;
int V_66 = F_68 ( V_34 ) ;
F_69 ( F_70 ( V_34 ) ) ;
V_67:
F_71 ( V_34 ) ;
if ( F_72 ( V_34 , NULL ) ) {
V_6 = V_65 + F_73 ( V_34 ) ;
F_74 ( V_34 , V_6 ) ;
} else {
V_6 = V_68 ;
F_75 ( V_34 ) ;
F_76 () ;
}
if ( V_6 == V_68 && F_72 ( V_34 , NULL ) ) {
if ( ! F_77 ( V_34 ) ) {
F_78 ( V_34 ) ;
goto V_67;
}
}
if ( V_66 && V_6 != V_68 )
F_79 ( V_69 ) ;
else if ( ! V_66 && V_6 == V_68 )
F_79 ( V_70 ) ;
F_78 ( V_34 ) ;
}
static enum V_71 F_80 ( struct V_34 * V_34 ,
struct V_1 * V_2 )
{
int V_72 , V_73 ;
unsigned long V_74 ;
V_72 = F_81 ( V_34 , 1 , V_2 -> V_3 ,
& V_74 ) ;
V_73 = F_82 ( V_34 ) ;
if ( V_74 & V_75 )
return V_76 ;
if ( V_72 ) {
if ( F_83 ( V_34 ) )
return V_77 ;
F_84 ( V_34 ) ;
if ( V_73 || V_72 > 1 )
return V_77 ;
if ( V_74 & V_78 )
return V_77 ;
return V_79 ;
}
if ( V_73 && ! F_83 ( V_34 ) )
return V_80 ;
return V_76 ;
}
static unsigned long F_85 ( struct V_81 * V_82 ,
struct V_83 * V_83 ,
struct V_1 * V_2 ,
unsigned long * V_84 ,
unsigned long * V_85 )
{
F_86 ( V_86 ) ;
F_86 ( V_87 ) ;
int V_88 = 0 ;
unsigned long V_89 = 0 ;
unsigned long V_90 = 0 ;
unsigned long V_91 = 0 ;
unsigned long V_92 = 0 ;
F_24 () ;
while ( ! F_87 ( V_82 ) ) {
enum V_71 V_93 ;
struct V_40 * V_41 ;
struct V_34 * V_34 ;
int V_94 ;
F_24 () ;
V_34 = F_88 ( V_82 ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( ! F_89 ( V_34 ) )
goto V_95;
F_69 ( F_90 ( V_34 ) ) ;
F_69 ( F_91 ( V_34 ) != V_83 ) ;
V_2 -> V_96 ++ ;
if ( F_54 ( ! F_72 ( V_34 , NULL ) ) )
goto V_97;
if ( ! V_2 -> V_98 && F_92 ( V_34 ) )
goto V_99;
if ( F_92 ( V_34 ) || F_57 ( V_34 ) )
V_2 -> V_96 ++ ;
V_94 = ( V_2 -> V_100 & V_101 ) ||
( F_57 ( V_34 ) && ( V_2 -> V_100 & V_102 ) ) ;
if ( F_45 ( V_34 ) ) {
V_92 ++ ;
F_38 ( V_34 ) ;
goto V_95;
}
V_93 = F_80 ( V_34 , V_2 ) ;
switch ( V_93 ) {
case V_77 :
goto V_103;
case V_79 :
goto V_99;
case V_76 :
case V_80 :
;
}
if ( F_93 ( V_34 ) && ! F_57 ( V_34 ) ) {
if ( ! ( V_2 -> V_100 & V_102 ) )
goto V_99;
if ( ! F_94 ( V_34 ) )
goto V_103;
V_94 = 1 ;
}
V_41 = F_36 ( V_34 ) ;
if ( F_92 ( V_34 ) && V_41 ) {
switch ( F_95 ( V_34 , V_104 ) ) {
case V_105 :
goto V_103;
case V_106 :
goto V_99;
case V_107 :
goto V_97;
case V_108 :
;
}
}
if ( F_55 ( V_34 ) ) {
V_89 ++ ;
if ( F_96 ( V_34 ) &&
( ! F_97 () ||
V_2 -> V_109 >= V_110 - 2 ) ) {
F_48 ( V_34 , V_111 ) ;
F_43 ( V_34 ) ;
goto V_99;
}
if ( V_93 == V_80 )
goto V_99;
if ( ! V_94 )
goto V_99;
if ( ! V_2 -> V_112 )
goto V_99;
switch ( F_39 ( V_34 , V_41 , V_2 ) ) {
case V_42 :
V_90 ++ ;
goto V_99;
case V_47 :
goto V_103;
case V_60 :
if ( F_45 ( V_34 ) )
goto V_95;
if ( F_55 ( V_34 ) )
goto V_95;
if ( ! F_89 ( V_34 ) )
goto V_95;
if ( F_55 ( V_34 ) || F_45 ( V_34 ) )
goto V_99;
V_41 = F_36 ( V_34 ) ;
case V_44 :
;
}
}
if ( F_31 ( V_34 ) ) {
if ( ! F_98 ( V_34 , V_2 -> V_100 ) )
goto V_103;
if ( ! V_41 && F_30 ( V_34 ) == 1 ) {
F_38 ( V_34 ) ;
if ( F_99 ( V_34 ) )
goto V_113;
else {
V_91 ++ ;
continue;
}
}
}
if ( ! V_41 || ! F_49 ( V_41 , V_34 ) )
goto V_99;
F_100 ( V_34 ) ;
V_113:
V_91 ++ ;
F_101 ( & V_34 -> V_6 , & V_87 ) ;
continue;
V_97:
if ( F_57 ( V_34 ) )
F_102 ( V_34 ) ;
F_38 ( V_34 ) ;
F_66 ( V_34 ) ;
continue;
V_103:
if ( F_57 ( V_34 ) && F_103 () )
F_102 ( V_34 ) ;
F_69 ( F_90 ( V_34 ) ) ;
F_104 ( V_34 ) ;
V_88 ++ ;
V_99:
F_38 ( V_34 ) ;
V_95:
F_101 ( & V_34 -> V_6 , & V_86 ) ;
F_69 ( F_70 ( V_34 ) || F_68 ( V_34 ) ) ;
}
if ( V_89 && V_89 == V_90 && F_1 ( V_2 ) )
F_105 ( V_83 , V_114 ) ;
F_106 ( & V_87 , 1 ) ;
F_107 ( & V_86 , V_82 ) ;
F_23 ( V_115 , V_88 ) ;
* V_84 += V_89 ;
* V_85 += V_92 ;
return V_91 ;
}
int F_108 ( struct V_34 * V_34 , T_3 V_116 )
{
int V_18 = - V_117 ;
if ( ! F_70 ( V_34 ) )
return V_18 ;
if ( F_68 ( V_34 ) )
return V_18 ;
V_18 = - V_118 ;
if ( V_116 & ( V_119 | V_120 ) ) {
if ( F_45 ( V_34 ) )
return V_18 ;
if ( F_55 ( V_34 ) ) {
struct V_40 * V_41 ;
if ( V_116 & V_119 )
return V_18 ;
V_41 = F_36 ( V_34 ) ;
if ( V_41 && ! V_41 -> V_45 -> V_121 )
return V_18 ;
}
}
if ( ( V_116 & V_122 ) && F_92 ( V_34 ) )
return V_18 ;
if ( F_109 ( F_110 ( V_34 ) ) ) {
F_111 ( V_34 ) ;
V_18 = 0 ;
}
return V_18 ;
}
static unsigned long F_112 ( unsigned long V_14 ,
struct V_4 * V_4 , struct V_81 * V_123 ,
unsigned long * V_96 , struct V_1 * V_2 ,
T_3 V_116 , enum V_5 V_6 )
{
struct V_81 * V_124 = & V_4 -> V_125 [ V_6 ] ;
unsigned long V_126 = 0 ;
unsigned long V_127 ;
for ( V_127 = 0 ; V_127 < V_14 && ! F_87 ( V_124 ) ; V_127 ++ ) {
struct V_34 * V_34 ;
int V_128 ;
V_34 = F_88 ( V_124 ) ;
F_113 ( V_34 , V_124 , V_38 ) ;
F_69 ( ! F_70 ( V_34 ) ) ;
switch ( F_108 ( V_34 , V_116 ) ) {
case 0 :
V_128 = F_114 ( V_34 ) ;
F_115 ( V_4 , V_6 , - V_128 ) ;
F_116 ( & V_34 -> V_6 , V_123 ) ;
V_126 += V_128 ;
break;
case - V_118 :
F_116 ( & V_34 -> V_6 , V_124 ) ;
continue;
default:
F_117 () ;
}
}
* V_96 = V_127 ;
F_118 ( V_2 -> V_129 , V_14 , V_127 ,
V_126 , V_116 , F_119 ( V_6 ) ) ;
return V_126 ;
}
int F_77 ( struct V_34 * V_34 )
{
int V_18 = - V_118 ;
F_69 ( ! F_30 ( V_34 ) ) ;
if ( F_70 ( V_34 ) ) {
struct V_83 * V_83 = F_91 ( V_34 ) ;
struct V_4 * V_4 ;
F_52 ( & V_83 -> V_130 ) ;
V_4 = F_120 ( V_34 , V_83 ) ;
if ( F_70 ( V_34 ) ) {
int V_6 = F_121 ( V_34 ) ;
F_122 ( V_34 ) ;
F_111 ( V_34 ) ;
F_123 ( V_34 , V_4 , V_6 ) ;
V_18 = 0 ;
}
F_60 ( & V_83 -> V_130 ) ;
}
return V_18 ;
}
static int F_124 ( struct V_83 * V_83 , int V_131 ,
struct V_1 * V_2 )
{
unsigned long V_132 , V_133 ;
if ( F_97 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_131 ) {
V_132 = F_5 ( V_83 , V_134 ) ;
V_133 = F_5 ( V_83 , V_135 ) ;
} else {
V_132 = F_5 ( V_83 , V_136 ) ;
V_133 = F_5 ( V_83 , V_137 ) ;
}
return V_133 > V_132 ;
}
static T_4 void
F_125 ( struct V_4 * V_4 , struct V_81 * V_82 )
{
struct V_138 * V_139 = & V_4 -> V_139 ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
F_86 ( V_140 ) ;
while ( ! F_87 ( V_82 ) ) {
struct V_34 * V_34 = F_88 ( V_82 ) ;
int V_6 ;
F_69 ( F_70 ( V_34 ) ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( F_54 ( ! F_72 ( V_34 , NULL ) ) ) {
F_60 ( & V_83 -> V_130 ) ;
F_66 ( V_34 ) ;
F_52 ( & V_83 -> V_130 ) ;
continue;
}
V_4 = F_120 ( V_34 , V_83 ) ;
F_126 ( V_34 ) ;
V_6 = F_121 ( V_34 ) ;
F_127 ( V_34 , V_4 , V_6 ) ;
if ( F_128 ( V_6 ) ) {
int V_131 = F_119 ( V_6 ) ;
int V_141 = F_114 ( V_34 ) ;
V_139 -> V_142 [ V_131 ] += V_141 ;
}
if ( F_99 ( V_34 ) ) {
F_129 ( V_34 ) ;
F_130 ( V_34 ) ;
F_123 ( V_34 , V_4 , V_6 ) ;
if ( F_54 ( F_131 ( V_34 ) ) ) {
F_60 ( & V_83 -> V_130 ) ;
( * F_132 ( V_34 ) ) ( V_34 ) ;
F_52 ( & V_83 -> V_130 ) ;
} else
F_101 ( & V_34 -> V_6 , & V_140 ) ;
}
}
F_107 ( & V_140 , V_82 ) ;
}
static T_4 unsigned long
F_133 ( unsigned long V_14 , struct V_4 * V_4 ,
struct V_1 * V_2 , enum V_5 V_6 )
{
F_86 ( V_82 ) ;
unsigned long V_96 ;
unsigned long V_91 = 0 ;
unsigned long V_126 ;
unsigned long V_89 = 0 ;
unsigned long V_92 = 0 ;
T_3 V_143 = 0 ;
int V_131 = F_119 ( V_6 ) ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
struct V_138 * V_139 = & V_4 -> V_139 ;
while ( F_54 ( F_124 ( V_83 , V_131 , V_2 ) ) ) {
F_134 ( V_144 , V_145 / 10 ) ;
if ( F_135 ( V_37 ) )
return V_19 ;
}
F_136 () ;
if ( ! V_2 -> V_98 )
V_143 |= V_122 ;
if ( ! V_2 -> V_112 )
V_143 |= V_119 ;
F_52 ( & V_83 -> V_130 ) ;
V_126 = F_112 ( V_14 , V_4 , & V_82 ,
& V_96 , V_2 , V_143 , V_6 ) ;
F_137 ( V_83 , V_7 + V_6 , - V_126 ) ;
F_137 ( V_83 , V_137 + V_131 , V_126 ) ;
if ( F_1 ( V_2 ) ) {
V_83 -> V_146 += V_96 ;
if ( F_97 () )
F_138 ( V_147 , V_83 , V_96 ) ;
else
F_138 ( V_148 , V_83 , V_96 ) ;
}
F_60 ( & V_83 -> V_130 ) ;
if ( V_126 == 0 )
return 0 ;
V_91 = F_85 ( & V_82 , V_83 , V_2 ,
& V_89 , & V_92 ) ;
F_52 ( & V_83 -> V_130 ) ;
V_139 -> V_149 [ V_131 ] += V_126 ;
if ( F_1 ( V_2 ) ) {
if ( F_97 () )
F_138 ( V_150 , V_83 ,
V_91 ) ;
else
F_138 ( V_151 , V_83 ,
V_91 ) ;
}
F_125 ( V_4 , & V_82 ) ;
F_137 ( V_83 , V_137 + V_131 , - V_126 ) ;
F_60 ( & V_83 -> V_130 ) ;
F_106 ( & V_82 , 1 ) ;
if ( V_92 && V_92 >=
( V_126 >> ( V_110 - V_2 -> V_109 ) ) )
F_139 ( V_83 , V_144 , V_145 / 10 ) ;
F_140 ( V_83 -> V_152 -> V_153 ,
F_141 ( V_83 ) ,
V_96 , V_91 ,
V_2 -> V_109 ,
F_142 ( V_131 ) ) ;
return V_91 ;
}
static void F_143 ( struct V_4 * V_4 ,
struct V_81 * V_11 ,
struct V_81 * V_140 ,
enum V_5 V_6 )
{
struct V_83 * V_83 = F_6 ( V_4 ) ;
unsigned long V_154 = 0 ;
struct V_34 * V_34 ;
int V_128 ;
while ( ! F_87 ( V_11 ) ) {
V_34 = F_88 ( V_11 ) ;
V_4 = F_120 ( V_34 , V_83 ) ;
F_69 ( F_70 ( V_34 ) ) ;
F_126 ( V_34 ) ;
V_128 = F_114 ( V_34 ) ;
F_115 ( V_4 , V_6 , V_128 ) ;
F_116 ( & V_34 -> V_6 , & V_4 -> V_125 [ V_6 ] ) ;
V_154 += V_128 ;
if ( F_99 ( V_34 ) ) {
F_129 ( V_34 ) ;
F_130 ( V_34 ) ;
F_123 ( V_34 , V_4 , V_6 ) ;
if ( F_54 ( F_131 ( V_34 ) ) ) {
F_60 ( & V_83 -> V_130 ) ;
( * F_132 ( V_34 ) ) ( V_34 ) ;
F_52 ( & V_83 -> V_130 ) ;
} else
F_101 ( & V_34 -> V_6 , V_140 ) ;
}
}
F_137 ( V_83 , V_7 + V_6 , V_154 ) ;
if ( ! F_128 ( V_6 ) )
F_144 ( V_155 , V_154 ) ;
}
static void F_145 ( unsigned long V_14 ,
struct V_4 * V_4 ,
struct V_1 * V_2 ,
enum V_5 V_6 )
{
unsigned long V_126 ;
unsigned long V_96 ;
unsigned long V_74 ;
F_86 ( V_156 ) ;
F_86 ( V_157 ) ;
F_86 ( V_158 ) ;
struct V_34 * V_34 ;
struct V_138 * V_139 = & V_4 -> V_139 ;
unsigned long V_159 = 0 ;
T_3 V_143 = 0 ;
int V_131 = F_119 ( V_6 ) ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
F_136 () ;
if ( ! V_2 -> V_98 )
V_143 |= V_122 ;
if ( ! V_2 -> V_112 )
V_143 |= V_119 ;
F_52 ( & V_83 -> V_130 ) ;
V_126 = F_112 ( V_14 , V_4 , & V_156 ,
& V_96 , V_2 , V_143 , V_6 ) ;
if ( F_1 ( V_2 ) )
V_83 -> V_146 += V_96 ;
V_139 -> V_149 [ V_131 ] += V_126 ;
F_138 ( V_160 , V_83 , V_96 ) ;
F_137 ( V_83 , V_7 + V_6 , - V_126 ) ;
F_137 ( V_83 , V_137 + V_131 , V_126 ) ;
F_60 ( & V_83 -> V_130 ) ;
while ( ! F_87 ( & V_156 ) ) {
F_24 () ;
V_34 = F_88 ( & V_156 ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( F_54 ( ! F_72 ( V_34 , NULL ) ) ) {
F_66 ( V_34 ) ;
continue;
}
if ( F_54 ( V_161 ) ) {
if ( F_31 ( V_34 ) && F_89 ( V_34 ) ) {
if ( F_31 ( V_34 ) )
F_98 ( V_34 , 0 ) ;
F_38 ( V_34 ) ;
}
}
if ( F_81 ( V_34 , 0 , V_2 -> V_3 ,
& V_74 ) ) {
V_159 += F_114 ( V_34 ) ;
if ( ( V_74 & V_78 ) && F_96 ( V_34 ) ) {
F_101 ( & V_34 -> V_6 , & V_157 ) ;
continue;
}
}
F_146 ( V_34 ) ;
F_101 ( & V_34 -> V_6 , & V_158 ) ;
}
F_52 ( & V_83 -> V_130 ) ;
V_139 -> V_142 [ V_131 ] += V_159 ;
F_143 ( V_4 , & V_157 , & V_156 , V_6 ) ;
F_143 ( V_4 , & V_158 , & V_156 , V_6 - V_162 ) ;
F_137 ( V_83 , V_137 + V_131 , - V_126 ) ;
F_60 ( & V_83 -> V_130 ) ;
F_106 ( & V_156 , 1 ) ;
}
static int F_147 ( struct V_83 * V_83 )
{
unsigned long V_65 , V_132 ;
V_65 = F_5 ( V_83 , V_163 ) ;
V_132 = F_5 ( V_83 , V_136 ) ;
if ( V_132 * V_83 -> V_164 < V_65 )
return 1 ;
return 0 ;
}
static int F_148 ( struct V_4 * V_4 )
{
if ( ! V_165 )
return 0 ;
if ( ! F_3 () )
return F_149 ( V_4 ) ;
return F_147 ( F_6 ( V_4 ) ) ;
}
static inline int F_148 ( struct V_4 * V_4 )
{
return 0 ;
}
static int F_150 ( struct V_83 * V_83 )
{
unsigned long V_65 , V_132 ;
V_65 = F_5 ( V_83 , V_166 ) ;
V_132 = F_5 ( V_83 , V_134 ) ;
return ( V_65 > V_132 ) ;
}
static int F_151 ( struct V_4 * V_4 )
{
if ( ! F_3 () )
return F_152 ( V_4 ) ;
return F_150 ( F_6 ( V_4 ) ) ;
}
static int F_153 ( struct V_4 * V_4 , enum V_5 V_6 )
{
if ( F_119 ( V_6 ) )
return F_151 ( V_4 ) ;
else
return F_148 ( V_4 ) ;
}
static unsigned long F_154 ( enum V_5 V_6 , unsigned long V_14 ,
struct V_4 * V_4 , struct V_1 * V_2 )
{
if ( F_128 ( V_6 ) ) {
if ( F_153 ( V_4 , V_6 ) )
F_145 ( V_14 , V_4 , V_2 , V_6 ) ;
return 0 ;
}
return F_133 ( V_14 , V_4 , V_2 , V_6 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_167 ;
return F_156 ( V_2 -> V_3 ) ;
}
static void F_157 ( struct V_4 * V_4 , struct V_1 * V_2 ,
unsigned long * V_25 )
{
unsigned long V_168 , V_131 , free ;
unsigned long V_169 , V_170 ;
unsigned long V_171 , V_172 ;
struct V_138 * V_139 = & V_4 -> V_139 ;
T_5 V_173 [ 2 ] , V_174 ;
enum V_5 V_6 ;
int V_175 = 0 ;
bool V_176 = false ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
if ( F_97 () && V_83 -> V_177 )
V_176 = true ;
if ( ! F_1 ( V_2 ) )
V_176 = true ;
if ( ! V_2 -> V_178 || ( V_179 <= 0 ) ) {
V_175 = 1 ;
V_173 [ 0 ] = 0 ;
V_173 [ 1 ] = 1 ;
V_174 = 1 ;
goto V_20;
}
V_168 = F_2 ( V_4 , V_180 ) +
F_2 ( V_4 , V_181 ) ;
V_131 = F_2 ( V_4 , V_182 ) +
F_2 ( V_4 , V_183 ) ;
if ( F_1 ( V_2 ) ) {
free = F_5 ( V_83 , V_184 ) ;
if ( F_54 ( V_131 + free <= F_158 ( V_83 ) ) ) {
V_173 [ 0 ] = 1 ;
V_173 [ 1 ] = 0 ;
V_174 = 1 ;
goto V_20;
}
}
V_169 = F_155 ( V_2 ) ;
V_170 = 200 - V_169 ;
F_52 ( & V_83 -> V_130 ) ;
if ( F_54 ( V_139 -> V_149 [ 0 ] > V_168 / 4 ) ) {
V_139 -> V_149 [ 0 ] /= 2 ;
V_139 -> V_142 [ 0 ] /= 2 ;
}
if ( F_54 ( V_139 -> V_149 [ 1 ] > V_131 / 4 ) ) {
V_139 -> V_149 [ 1 ] /= 2 ;
V_139 -> V_142 [ 1 ] /= 2 ;
}
V_171 = V_169 * ( V_139 -> V_149 [ 0 ] + 1 ) ;
V_171 /= V_139 -> V_142 [ 0 ] + 1 ;
V_172 = V_170 * ( V_139 -> V_149 [ 1 ] + 1 ) ;
V_172 /= V_139 -> V_142 [ 1 ] + 1 ;
F_60 ( & V_83 -> V_130 ) ;
V_173 [ 0 ] = V_171 ;
V_173 [ 1 ] = V_172 ;
V_174 = V_171 + V_172 + 1 ;
V_20:
F_159 (lru) {
int V_131 = F_119 ( V_6 ) ;
unsigned long V_127 ;
V_127 = F_2 ( V_4 , V_6 ) ;
if ( V_2 -> V_109 || V_175 || ! F_155 ( V_2 ) ) {
V_127 >>= V_2 -> V_109 ;
if ( ! V_127 && V_176 )
V_127 = V_19 ;
V_127 = F_160 ( V_127 * V_173 [ V_131 ] , V_174 ) ;
}
V_25 [ V_6 ] = V_127 ;
}
}
static bool F_161 ( struct V_1 * V_2 )
{
if ( V_185 && V_2 -> V_129 &&
( V_2 -> V_129 > V_186 ||
V_2 -> V_109 < V_110 - 2 ) )
return true ;
return false ;
}
static inline bool F_162 ( struct V_4 * V_4 ,
unsigned long V_91 ,
unsigned long V_96 ,
struct V_1 * V_2 )
{
unsigned long V_187 ;
unsigned long V_188 ;
if ( ! F_161 ( V_2 ) )
return false ;
if ( V_2 -> V_100 & V_189 ) {
if ( ! V_91 && ! V_96 )
return false ;
} else {
if ( ! V_91 )
return false ;
}
V_187 = ( 2UL << V_2 -> V_129 ) ;
V_188 = F_2 ( V_4 , V_183 ) ;
if ( V_179 > 0 )
V_188 += F_2 ( V_4 , V_181 ) ;
if ( V_2 -> V_91 < V_187 &&
V_188 > V_187 )
return true ;
switch ( F_163 ( F_6 ( V_4 ) , V_2 -> V_129 ) ) {
case V_190 :
case V_191 :
return false ;
default:
return true ;
}
}
static void F_164 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_25 [ V_192 ] ;
unsigned long V_14 ;
enum V_5 V_6 ;
unsigned long V_91 , V_96 ;
unsigned long V_193 = V_2 -> V_193 ;
struct V_194 V_195 ;
V_196:
V_91 = 0 ;
V_96 = V_2 -> V_96 ;
F_157 ( V_4 , V_2 , V_25 ) ;
F_165 ( & V_195 ) ;
while ( V_25 [ V_181 ] || V_25 [ V_182 ] ||
V_25 [ V_183 ] ) {
F_159 (lru) {
if ( V_25 [ V_6 ] ) {
V_14 = F_166 (unsigned long,
nr[lru], SWAP_CLUSTER_MAX) ;
V_25 [ V_6 ] -= V_14 ;
V_91 += F_154 ( V_6 , V_14 ,
V_4 , V_2 ) ;
}
}
if ( V_91 >= V_193 &&
V_2 -> V_109 < V_110 )
break;
}
F_167 ( & V_195 ) ;
V_2 -> V_91 += V_91 ;
if ( F_148 ( V_4 ) )
F_145 ( V_19 , V_4 ,
V_2 , V_180 ) ;
if ( F_162 ( V_4 , V_91 ,
V_2 -> V_96 - V_96 , V_2 ) )
goto V_196;
F_168 ( V_2 -> V_100 ) ;
}
static void F_169 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
struct V_197 * V_198 = V_2 -> V_3 ;
struct V_199 V_200 = {
. V_83 = V_83 ,
. V_109 = V_2 -> V_109 ,
} ;
struct V_197 * V_201 ;
V_201 = F_170 ( V_198 , NULL , & V_200 ) ;
do {
struct V_4 * V_4 = F_171 ( V_83 , V_201 ) ;
F_164 ( V_4 , V_2 ) ;
if ( ! F_1 ( V_2 ) ) {
F_172 ( V_198 , V_201 ) ;
break;
}
V_201 = F_170 ( V_198 , V_201 , & V_200 ) ;
} while ( V_201 );
}
static inline bool F_173 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
unsigned long V_202 , V_203 ;
bool V_204 ;
if ( V_2 -> V_129 <= V_186 )
return false ;
V_202 = F_21 ( F_174 ( V_83 ) ,
( V_83 -> V_205 + V_206 - 1 ) /
V_206 ) ;
V_203 = F_158 ( V_83 ) + V_202 + ( 2UL << V_2 -> V_129 ) ;
V_204 = F_175 ( V_83 , 0 , V_203 , 0 , 0 ) ;
if ( F_176 ( V_83 , V_2 -> V_129 ) )
return V_204 ;
if ( ! F_163 ( V_83 , V_2 -> V_129 ) )
return false ;
return V_204 ;
}
static bool F_177 ( struct V_207 * V_207 , struct V_1 * V_2 )
{
struct V_208 * V_209 ;
struct V_83 * V_83 ;
unsigned long V_210 ;
unsigned long V_211 ;
bool V_212 = false ;
if ( V_161 )
V_2 -> V_100 |= V_213 ;
F_178 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_179 ( V_83 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_180 ( V_83 , V_214 ) )
continue;
if ( V_83 -> V_177 &&
V_2 -> V_109 != V_110 )
continue;
if ( V_185 ) {
if ( F_173 ( V_83 , V_2 ) ) {
V_212 = true ;
continue;
}
}
V_211 = 0 ;
V_210 = F_181 ( V_83 ,
V_2 -> V_129 , V_2 -> V_100 ,
& V_211 ) ;
V_2 -> V_91 += V_210 ;
V_2 -> V_96 += V_211 ;
}
F_169 ( V_83 , V_2 ) ;
}
return V_212 ;
}
static bool F_182 ( struct V_83 * V_83 )
{
return V_83 -> V_146 < F_183 ( V_83 ) * 6 ;
}
static bool V_177 ( struct V_207 * V_207 ,
struct V_1 * V_2 )
{
struct V_208 * V_209 ;
struct V_83 * V_83 ;
F_178 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_179 ( V_83 ) )
continue;
if ( ! F_180 ( V_83 , V_214 ) )
continue;
if ( ! V_83 -> V_177 )
return false ;
}
return true ;
}
static unsigned long F_184 ( struct V_207 * V_207 ,
struct V_1 * V_2 ,
struct V_13 * V_15 )
{
unsigned long V_215 = 0 ;
struct V_216 * V_216 = V_37 -> V_216 ;
struct V_208 * V_209 ;
struct V_83 * V_83 ;
unsigned long V_217 ;
bool V_212 ;
F_185 () ;
if ( F_1 ( V_2 ) )
F_79 ( V_218 ) ;
do {
V_2 -> V_96 = 0 ;
V_212 = F_177 ( V_207 , V_2 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_17 = 0 ;
F_186 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_180 ( V_83 , V_214 ) )
continue;
V_17 += F_183 ( V_83 ) ;
}
F_15 ( V_15 , V_2 -> V_96 , V_17 ) ;
if ( V_216 ) {
V_2 -> V_91 += V_216 -> V_219 ;
V_216 -> V_219 = 0 ;
}
}
V_215 += V_2 -> V_96 ;
if ( V_2 -> V_91 >= V_2 -> V_193 )
goto V_20;
V_217 = V_2 -> V_193 + V_2 -> V_193 / 2 ;
if ( V_215 > V_217 ) {
F_187 ( V_220 ? 0 : V_215 ,
V_221 ) ;
V_2 -> V_112 = 1 ;
}
if ( ! V_2 -> V_222 && V_2 -> V_96 &&
V_2 -> V_109 < V_110 - 2 ) {
struct V_83 * V_223 ;
F_188 ( V_207 , F_189 ( V_2 -> V_100 ) ,
& V_224 ,
& V_223 ) ;
F_139 ( V_223 , V_144 , V_145 / 10 ) ;
}
} while ( -- V_2 -> V_109 >= 0 );
V_20:
F_190 () ;
if ( V_2 -> V_91 )
return V_2 -> V_91 ;
if ( V_225 )
return 0 ;
if ( V_212 )
return 1 ;
if ( F_1 ( V_2 ) && ! V_177 ( V_207 , V_2 ) )
return 1 ;
return 0 ;
}
unsigned long F_191 ( struct V_207 * V_207 , int V_129 ,
T_6 V_100 , T_7 * V_226 )
{
unsigned long V_91 ;
struct V_1 V_2 = {
. V_100 = V_100 ,
. V_112 = ! V_220 ,
. V_193 = V_19 ,
. V_98 = 1 ,
. V_178 = 1 ,
. V_129 = V_129 ,
. V_109 = V_110 ,
. V_3 = NULL ,
. V_226 = V_226 ,
} ;
struct V_13 V_15 = {
. V_100 = V_2 . V_100 ,
} ;
F_192 ( V_129 ,
V_2 . V_112 ,
V_100 ) ;
V_91 = F_184 ( V_207 , & V_2 , & V_15 ) ;
F_193 ( V_91 ) ;
return V_91 ;
}
unsigned long F_194 ( struct V_197 * V_201 ,
T_6 V_100 , bool V_175 ,
struct V_83 * V_83 ,
unsigned long * V_96 )
{
struct V_1 V_2 = {
. V_96 = 0 ,
. V_193 = V_19 ,
. V_112 = ! V_220 ,
. V_98 = 1 ,
. V_178 = ! V_175 ,
. V_129 = 0 ,
. V_109 = 0 ,
. V_3 = V_201 ,
} ;
struct V_4 * V_4 = F_171 ( V_83 , V_201 ) ;
V_2 . V_100 = ( V_100 & V_227 ) |
( V_228 & ~ V_227 ) ;
F_195 ( V_2 . V_129 ,
V_2 . V_112 ,
V_2 . V_100 ) ;
F_164 ( V_4 , & V_2 ) ;
F_196 ( V_2 . V_91 ) ;
* V_96 = V_2 . V_96 ;
return V_2 . V_91 ;
}
unsigned long F_197 ( struct V_197 * V_201 ,
T_6 V_100 ,
bool V_175 )
{
struct V_207 * V_207 ;
unsigned long V_91 ;
int V_229 ;
struct V_1 V_2 = {
. V_112 = ! V_220 ,
. V_98 = 1 ,
. V_178 = ! V_175 ,
. V_193 = V_19 ,
. V_129 = 0 ,
. V_109 = V_110 ,
. V_3 = V_201 ,
. V_226 = NULL ,
. V_100 = ( V_100 & V_227 ) |
( V_228 & ~ V_227 ) ,
} ;
struct V_13 V_15 = {
. V_100 = V_2 . V_100 ,
} ;
V_229 = F_198 ( V_201 ) ;
V_207 = F_199 ( V_229 ) -> V_230 ;
F_200 ( 0 ,
V_2 . V_112 ,
V_2 . V_100 ) ;
V_91 = F_184 ( V_207 , & V_2 , & V_15 ) ;
F_201 ( V_91 ) ;
return V_91 ;
}
static void F_202 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
struct V_197 * V_201 ;
if ( ! V_165 )
return;
V_201 = F_170 ( NULL , NULL , NULL ) ;
do {
struct V_4 * V_4 = F_171 ( V_83 , V_201 ) ;
if ( F_148 ( V_4 ) )
F_145 ( V_19 , V_4 ,
V_2 , V_180 ) ;
V_201 = F_170 ( NULL , V_201 , NULL ) ;
} while ( V_201 );
}
static bool F_203 ( T_8 * V_231 , unsigned long V_232 ,
int V_233 )
{
unsigned long V_205 = 0 ;
int V_234 ;
for ( V_234 = 0 ; V_234 <= V_233 ; V_234 ++ )
V_205 += V_231 -> V_235 [ V_234 ] . V_205 ;
return V_232 >= ( V_205 >> 2 ) ;
}
static bool F_204 ( T_8 * V_231 , int V_129 , long V_236 ,
int V_233 )
{
int V_234 ;
unsigned long V_237 = 0 ;
bool V_238 = true ;
if ( V_236 )
return true ;
for ( V_234 = 0 ; V_234 <= V_233 ; V_234 ++ ) {
struct V_83 * V_83 = V_231 -> V_235 + V_234 ;
if ( ! F_179 ( V_83 ) )
continue;
if ( V_83 -> V_177 ) {
V_237 += V_83 -> V_205 ;
continue;
}
if ( ! F_175 ( V_83 , V_129 , F_158 ( V_83 ) ,
V_234 , 0 ) )
V_238 = false ;
else
V_237 += V_83 -> V_205 ;
}
if ( V_129 )
return ! F_203 ( V_231 , V_237 , V_233 ) ;
else
return ! V_238 ;
}
static unsigned long F_205 ( T_8 * V_231 , int V_129 ,
int * V_233 )
{
int V_238 ;
unsigned long V_237 ;
int V_234 ;
int V_239 = 0 ;
unsigned long V_215 ;
struct V_216 * V_216 = V_37 -> V_216 ;
unsigned long V_210 ;
unsigned long V_211 ;
struct V_1 V_2 = {
. V_100 = V_214 ,
. V_98 = 1 ,
. V_178 = 1 ,
. V_193 = V_240 ,
. V_129 = V_129 ,
. V_3 = NULL ,
} ;
struct V_13 V_15 = {
. V_100 = V_2 . V_100 ,
} ;
V_241:
V_215 = 0 ;
V_2 . V_109 = V_110 ;
V_2 . V_91 = 0 ;
V_2 . V_112 = ! V_220 ;
F_79 ( V_242 ) ;
do {
unsigned long V_17 = 0 ;
int V_243 = 0 ;
V_238 = 1 ;
V_237 = 0 ;
for ( V_234 = V_231 -> V_244 - 1 ; V_234 >= 0 ; V_234 -- ) {
struct V_83 * V_83 = V_231 -> V_235 + V_234 ;
if ( ! F_179 ( V_83 ) )
continue;
if ( V_83 -> V_177 &&
V_2 . V_109 != V_110 )
continue;
F_202 ( V_83 , & V_2 ) ;
if ( V_161 && F_206 ( V_234 ) ) {
V_239 = V_234 ;
break;
}
if ( ! F_175 ( V_83 , V_129 ,
F_158 ( V_83 ) , 0 , 0 ) ) {
V_239 = V_234 ;
break;
} else {
F_207 ( V_83 , V_114 ) ;
}
}
if ( V_234 < 0 )
goto V_20;
for ( V_234 = 0 ; V_234 <= V_239 ; V_234 ++ ) {
struct V_83 * V_83 = V_231 -> V_235 + V_234 ;
V_17 += F_183 ( V_83 ) ;
}
for ( V_234 = 0 ; V_234 <= V_239 ; V_234 ++ ) {
struct V_83 * V_83 = V_231 -> V_235 + V_234 ;
int V_245 , V_246 ;
unsigned long V_202 ;
if ( ! F_179 ( V_83 ) )
continue;
if ( V_83 -> V_177 &&
V_2 . V_109 != V_110 )
continue;
V_2 . V_96 = 0 ;
V_211 = 0 ;
V_210 = F_181 ( V_83 ,
V_129 , V_2 . V_100 ,
& V_211 ) ;
V_2 . V_91 += V_210 ;
V_215 += V_211 ;
V_202 = F_21 ( F_174 ( V_83 ) ,
( V_83 -> V_205 +
V_206 - 1 ) /
V_206 ) ;
V_246 = V_129 ;
if ( V_185 && V_129 &&
F_163 ( V_83 , V_129 ) !=
V_247 )
V_246 = 0 ;
if ( ( V_161 && F_206 ( V_234 ) ) ||
! F_175 ( V_83 , V_246 ,
F_158 ( V_83 ) + V_202 ,
V_239 , 0 ) ) {
F_169 ( V_83 , & V_2 ) ;
V_216 -> V_219 = 0 ;
V_245 = F_15 ( & V_15 , V_2 . V_96 , V_17 ) ;
V_2 . V_91 += V_216 -> V_219 ;
V_215 += V_2 . V_96 ;
if ( V_245 == 0 && ! F_182 ( V_83 ) )
V_83 -> V_177 = 1 ;
}
if ( V_215 > V_19 * 2 &&
V_215 > V_2 . V_91 + V_2 . V_91 / 2 )
V_2 . V_112 = 1 ;
if ( V_83 -> V_177 ) {
if ( V_239 && V_239 == V_234 )
V_239 -- ;
continue;
}
if ( ! F_175 ( V_83 , V_246 ,
F_158 ( V_83 ) , V_239 , 0 ) ) {
V_238 = 0 ;
if ( ! F_175 ( V_83 , V_129 ,
F_208 ( V_83 ) , V_239 , 0 ) )
V_243 = 1 ;
} else {
F_207 ( V_83 , V_114 ) ;
if ( V_234 <= * V_233 )
V_237 += V_83 -> V_205 ;
}
}
if ( V_238 || ( V_129 && F_203 ( V_231 , V_237 , * V_233 ) ) )
break;
if ( V_215 && ( V_2 . V_109 < V_110 - 2 ) ) {
if ( V_243 )
F_79 ( V_248 ) ;
else
F_134 ( V_144 , V_145 / 10 ) ;
}
if ( V_2 . V_91 >= V_19 )
break;
} while ( -- V_2 . V_109 >= 0 );
V_20:
if ( ! ( V_238 || ( V_129 && F_203 ( V_231 , V_237 , * V_233 ) ) ) ) {
F_24 () ;
F_209 () ;
if ( V_2 . V_91 < V_19 )
V_129 = V_2 . V_129 = 0 ;
goto V_241;
}
if ( V_129 ) {
int V_249 = 1 ;
for ( V_234 = 0 ; V_234 <= V_239 ; V_234 ++ ) {
struct V_83 * V_83 = V_231 -> V_235 + V_234 ;
if ( ! F_179 ( V_83 ) )
continue;
if ( V_83 -> V_177 &&
V_2 . V_109 != V_110 )
continue;
if ( V_185 &&
F_163 ( V_83 , V_129 ) == V_247 )
goto V_241;
if ( ! F_210 ( V_83 , 0 ,
F_158 ( V_83 ) , 0 , 0 ) ) {
V_129 = V_2 . V_129 = 0 ;
goto V_241;
}
if ( F_210 ( V_83 , V_129 ,
F_174 ( V_83 ) , * V_233 , 0 ) )
V_249 = 0 ;
F_207 ( V_83 , V_114 ) ;
}
if ( V_249 )
F_211 ( V_231 , V_129 ) ;
}
* V_233 = V_239 ;
return V_129 ;
}
static void F_212 ( T_8 * V_231 , int V_129 , int V_233 )
{
long V_236 = 0 ;
F_213 ( V_250 ) ;
if ( F_214 ( V_37 ) || F_215 () )
return;
F_216 ( & V_231 -> V_251 , & V_250 , V_252 ) ;
if ( ! F_204 ( V_231 , V_129 , V_236 , V_233 ) ) {
V_236 = F_217 ( V_145 / 10 ) ;
F_218 ( & V_231 -> V_251 , & V_250 ) ;
F_216 ( & V_231 -> V_251 , & V_250 , V_252 ) ;
}
if ( ! F_204 ( V_231 , V_129 , V_236 , V_233 ) ) {
F_219 ( V_231 -> V_153 ) ;
F_220 ( V_231 , V_253 ) ;
if ( ! F_215 () )
F_221 () ;
F_220 ( V_231 , V_254 ) ;
} else {
if ( V_236 )
F_79 ( V_255 ) ;
else
F_79 ( V_256 ) ;
}
F_218 ( & V_231 -> V_251 , & V_250 ) ;
}
static int F_222 ( void * V_257 )
{
unsigned long V_129 , V_258 ;
unsigned V_259 ;
int V_233 , V_260 ;
int V_261 ;
T_8 * V_231 = ( T_8 * ) V_257 ;
struct V_262 * V_263 = V_37 ;
struct V_216 V_216 = {
. V_219 = 0 ,
} ;
const struct V_264 * V_264 = F_223 ( V_231 -> V_153 ) ;
F_224 ( V_214 ) ;
if ( ! F_225 ( V_264 ) )
F_226 ( V_263 , V_264 ) ;
V_37 -> V_216 = & V_216 ;
V_263 -> V_38 |= V_265 | V_39 | V_266 ;
F_227 () ;
V_129 = V_258 = 0 ;
V_259 = 0 ;
V_233 = V_260 = V_231 -> V_244 - 1 ;
V_261 = V_233 ;
for ( ; ; ) {
int V_18 ;
if ( V_261 >= V_260 &&
V_259 == V_258 ) {
V_258 = V_231 -> V_267 ;
V_260 = V_231 -> V_233 ;
V_231 -> V_267 = 0 ;
V_231 -> V_233 = V_231 -> V_244 - 1 ;
}
if ( V_129 < V_258 || V_233 > V_260 ) {
V_129 = V_258 ;
V_233 = V_260 ;
} else {
F_212 ( V_231 , V_259 ,
V_261 ) ;
V_129 = V_231 -> V_267 ;
V_233 = V_231 -> V_233 ;
V_258 = V_129 ;
V_260 = V_233 ;
V_231 -> V_267 = 0 ;
V_231 -> V_233 = V_231 -> V_244 - 1 ;
}
V_18 = F_209 () ;
if ( F_215 () )
break;
if ( ! V_18 ) {
F_228 ( V_231 -> V_153 , V_129 ) ;
V_261 = V_233 ;
V_259 = F_205 ( V_231 , V_129 ,
& V_261 ) ;
}
}
return 0 ;
}
void F_229 ( struct V_83 * V_83 , int V_129 , enum V_268 V_233 )
{
T_8 * V_231 ;
if ( ! F_179 ( V_83 ) )
return;
if ( ! F_180 ( V_83 , V_214 ) )
return;
V_231 = V_83 -> V_152 ;
if ( V_231 -> V_267 < V_129 ) {
V_231 -> V_267 = V_129 ;
V_231 -> V_233 = F_21 ( V_231 -> V_233 , V_233 ) ;
}
if ( ! F_230 ( & V_231 -> V_251 ) )
return;
if ( F_175 ( V_83 , V_129 , F_174 ( V_83 ) , 0 , 0 ) )
return;
F_231 ( V_231 -> V_153 , F_141 ( V_83 ) , V_129 ) ;
F_232 ( & V_231 -> V_251 ) ;
}
unsigned long F_233 ( void )
{
int V_25 ;
V_25 = F_234 ( V_166 ) +
F_234 ( V_134 ) ;
if ( V_179 > 0 )
V_25 += F_234 ( V_163 ) +
F_234 ( V_136 ) ;
return V_25 ;
}
unsigned long F_183 ( struct V_83 * V_83 )
{
int V_25 ;
V_25 = F_5 ( V_83 , V_166 ) +
F_5 ( V_83 , V_134 ) ;
if ( V_179 > 0 )
V_25 += F_5 ( V_83 , V_163 ) +
F_5 ( V_83 , V_136 ) ;
return V_25 ;
}
unsigned long F_235 ( unsigned long V_193 )
{
struct V_216 V_216 ;
struct V_1 V_2 = {
. V_100 = V_228 ,
. V_178 = 1 ,
. V_98 = 1 ,
. V_112 = 1 ,
. V_193 = V_193 ,
. V_222 = 1 ,
. V_129 = 0 ,
. V_109 = V_110 ,
} ;
struct V_13 V_15 = {
. V_100 = V_2 . V_100 ,
} ;
struct V_207 * V_207 = F_236 ( F_237 () , V_2 . V_100 ) ;
struct V_262 * V_257 = V_37 ;
unsigned long V_91 ;
V_257 -> V_38 |= V_265 ;
F_224 ( V_2 . V_100 ) ;
V_216 . V_219 = 0 ;
V_257 -> V_216 = & V_216 ;
V_91 = F_184 ( V_207 , & V_2 , & V_15 ) ;
V_257 -> V_216 = NULL ;
F_238 () ;
V_257 -> V_38 &= ~ V_265 ;
return V_91 ;
}
static int T_9 F_239 ( struct V_269 * V_270 ,
unsigned long V_271 , void * V_272 )
{
int V_229 ;
if ( V_271 == V_273 || V_271 == V_274 ) {
F_240 (nid, N_HIGH_MEMORY) {
T_8 * V_231 = F_199 ( V_229 ) ;
const struct V_264 * V_275 ;
V_275 = F_223 ( V_231 -> V_153 ) ;
if ( F_241 ( V_276 , V_275 ) < V_277 )
F_226 ( V_231 -> F_222 , V_275 ) ;
}
}
return V_278 ;
}
int F_242 ( int V_229 )
{
T_8 * V_231 = F_199 ( V_229 ) ;
int V_18 = 0 ;
if ( V_231 -> F_222 )
return 0 ;
V_231 -> F_222 = F_243 ( F_222 , V_231 , L_4 , V_229 ) ;
if ( F_244 ( V_231 -> F_222 ) ) {
F_50 ( V_279 == V_280 ) ;
F_20 ( L_5 , V_229 ) ;
V_18 = - 1 ;
}
return V_18 ;
}
void F_245 ( int V_229 )
{
struct V_262 * F_222 = F_199 ( V_229 ) -> F_222 ;
if ( F_222 ) {
F_246 ( F_222 ) ;
F_199 ( V_229 ) -> F_222 = NULL ;
}
}
static int T_10 F_247 ( void )
{
int V_229 ;
F_248 () ;
F_240 (nid, N_HIGH_MEMORY)
F_242 ( V_229 ) ;
F_249 ( F_239 , 0 ) ;
return 0 ;
}
static inline unsigned long F_250 ( struct V_83 * V_83 )
{
unsigned long V_281 = F_5 ( V_83 , V_282 ) ;
unsigned long V_283 = F_5 ( V_83 , V_134 ) +
F_5 ( V_83 , V_166 ) ;
return ( V_283 > V_281 ) ? ( V_283 - V_281 ) : 0 ;
}
static long F_251 ( struct V_83 * V_83 )
{
long V_284 ;
long V_21 = 0 ;
if ( V_285 & V_286 )
V_284 = F_5 ( V_83 , V_287 ) ;
else
V_284 = F_250 ( V_83 ) ;
if ( ! ( V_285 & V_288 ) )
V_21 += F_5 ( V_83 , V_289 ) ;
if ( F_54 ( V_21 > V_284 ) )
V_21 = V_284 ;
return V_284 - V_21 ;
}
static int F_252 ( struct V_83 * V_83 , T_6 V_100 , unsigned int V_129 )
{
const unsigned long V_128 = 1 << V_129 ;
struct V_262 * V_257 = V_37 ;
struct V_216 V_216 ;
struct V_1 V_2 = {
. V_112 = ! ! ( V_285 & V_288 ) ,
. V_98 = ! ! ( V_285 & V_286 ) ,
. V_178 = 1 ,
. V_193 = F_253 (unsigned long, nr_pages,
SWAP_CLUSTER_MAX) ,
. V_100 = V_100 ,
. V_129 = V_129 ,
. V_109 = V_290 ,
} ;
struct V_13 V_15 = {
. V_100 = V_2 . V_100 ,
} ;
unsigned long V_291 , V_292 ;
F_24 () ;
V_257 -> V_38 |= V_265 | V_39 ;
F_224 ( V_100 ) ;
V_216 . V_219 = 0 ;
V_257 -> V_216 = & V_216 ;
if ( F_251 ( V_83 ) > V_83 -> V_293 ) {
do {
F_169 ( V_83 , & V_2 ) ;
} while ( V_2 . V_91 < V_128 && -- V_2 . V_109 >= 0 );
}
V_291 = F_5 ( V_83 , V_294 ) ;
if ( V_291 > V_83 -> V_295 ) {
for (; ; ) {
unsigned long V_17 = F_183 ( V_83 ) ;
if ( ! F_15 ( & V_15 , V_2 . V_96 , V_17 ) )
break;
V_292 = F_5 ( V_83 ,
V_294 ) ;
if ( V_292 + V_128 <= V_291 )
break;
}
V_292 = F_5 ( V_83 , V_294 ) ;
if ( V_292 < V_291 )
V_2 . V_91 += V_291 - V_292 ;
}
V_257 -> V_216 = NULL ;
V_37 -> V_38 &= ~ ( V_265 | V_39 ) ;
F_238 () ;
return V_2 . V_91 >= V_128 ;
}
int F_254 ( struct V_83 * V_83 , T_6 V_100 , unsigned int V_129 )
{
int V_153 ;
int V_18 ;
if ( F_251 ( V_83 ) <= V_83 -> V_293 &&
F_5 ( V_83 , V_294 ) <= V_83 -> V_295 )
return V_296 ;
if ( V_83 -> V_177 )
return V_296 ;
if ( ! ( V_100 & V_297 ) || ( V_37 -> V_38 & V_265 ) )
return V_298 ;
V_153 = F_255 ( V_83 ) ;
if ( F_256 ( V_153 , V_299 ) && V_153 != F_237 () )
return V_298 ;
if ( F_257 ( V_83 , V_300 ) )
return V_298 ;
V_18 = F_252 ( V_83 , V_100 , V_129 ) ;
F_207 ( V_83 , V_300 ) ;
if ( ! V_18 )
F_79 ( V_301 ) ;
return V_18 ;
}
int F_72 ( struct V_34 * V_34 , struct V_302 * V_303 )
{
if ( F_258 ( F_36 ( V_34 ) ) )
return 0 ;
if ( F_259 ( V_34 ) || ( V_303 && F_260 ( V_303 , V_34 ) ) )
return 0 ;
return 1 ;
}
void F_261 ( struct V_34 * * V_304 , int V_128 )
{
struct V_4 * V_4 ;
struct V_83 * V_83 = NULL ;
int V_305 = 0 ;
int V_306 = 0 ;
int V_234 ;
for ( V_234 = 0 ; V_234 < V_128 ; V_234 ++ ) {
struct V_34 * V_34 = V_304 [ V_234 ] ;
struct V_83 * V_307 ;
V_305 ++ ;
V_307 = F_91 ( V_34 ) ;
if ( V_307 != V_83 ) {
if ( V_83 )
F_60 ( & V_83 -> V_130 ) ;
V_83 = V_307 ;
F_52 ( & V_83 -> V_130 ) ;
}
V_4 = F_120 ( V_34 , V_83 ) ;
if ( ! F_70 ( V_34 ) || ! F_68 ( V_34 ) )
continue;
if ( F_72 ( V_34 , NULL ) ) {
enum V_5 V_6 = F_73 ( V_34 ) ;
F_69 ( F_90 ( V_34 ) ) ;
F_71 ( V_34 ) ;
F_123 ( V_34 , V_4 , V_68 ) ;
F_127 ( V_34 , V_4 , V_6 ) ;
V_306 ++ ;
}
}
if ( V_83 ) {
F_144 ( V_69 , V_306 ) ;
F_144 ( V_308 , V_305 ) ;
F_60 ( & V_83 -> V_130 ) ;
}
}
static void F_262 ( void )
{
F_263 ( V_309
L_6
L_7
L_8 ,
V_37 -> V_310 ) ;
}
int F_264 ( struct V_311 * V_312 , int V_313 ,
void T_11 * V_314 ,
T_12 * V_315 , T_13 * V_316 )
{
F_262 () ;
F_265 ( V_312 , V_313 , V_314 , V_315 , V_316 ) ;
V_317 = 0 ;
return 0 ;
}
static T_14 F_266 ( struct V_318 * V_319 ,
struct V_320 * V_321 ,
char * V_322 )
{
F_262 () ;
return sprintf ( V_322 , L_9 ) ;
}
static T_14 F_267 ( struct V_318 * V_319 ,
struct V_320 * V_321 ,
const char * V_322 , T_12 V_323 )
{
F_262 () ;
return 1 ;
}
int F_268 ( struct V_324 * V_324 )
{
return F_269 ( & V_324 -> V_319 , & V_325 ) ;
}
void F_270 ( struct V_324 * V_324 )
{
F_271 ( & V_324 -> V_319 , & V_325 ) ;
}
