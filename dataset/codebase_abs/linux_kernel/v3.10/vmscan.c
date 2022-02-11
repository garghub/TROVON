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
if ( F_72 ( V_34 ) ) {
V_6 = V_65 + F_73 ( V_34 ) ;
F_74 ( V_34 , V_6 ) ;
} else {
V_6 = V_68 ;
F_75 ( V_34 ) ;
F_76 () ;
}
if ( V_6 == V_68 && F_72 ( V_34 ) ) {
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
enum V_84 V_84 ,
unsigned long * V_85 ,
unsigned long * V_86 ,
bool V_87 )
{
F_86 ( V_88 ) ;
F_86 ( V_89 ) ;
int V_90 = 0 ;
unsigned long V_91 = 0 ;
unsigned long V_92 = 0 ;
unsigned long V_93 = 0 ;
unsigned long V_94 = 0 ;
F_24 () ;
F_87 () ;
while ( ! F_88 ( V_82 ) ) {
struct V_40 * V_41 ;
struct V_34 * V_34 ;
int V_95 ;
enum V_71 V_96 = V_80 ;
F_24 () ;
V_34 = F_89 ( V_82 ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( ! F_90 ( V_34 ) )
goto V_97;
F_69 ( F_91 ( V_34 ) ) ;
F_69 ( F_92 ( V_34 ) != V_83 ) ;
V_2 -> V_98 ++ ;
if ( F_54 ( ! F_72 ( V_34 ) ) )
goto V_99;
if ( ! V_2 -> V_100 && F_93 ( V_34 ) )
goto V_101;
if ( F_93 ( V_34 ) || F_57 ( V_34 ) )
V_2 -> V_98 ++ ;
V_95 = ( V_2 -> V_102 & V_103 ) ||
( F_57 ( V_34 ) && ( V_2 -> V_102 & V_104 ) ) ;
if ( F_45 ( V_34 ) ) {
if ( F_1 ( V_2 ) ||
! F_94 ( V_34 ) || ! ( V_2 -> V_102 & V_104 ) ) {
F_43 ( V_34 ) ;
V_94 ++ ;
goto V_101;
}
F_95 ( V_34 ) ;
}
if ( ! V_87 )
V_96 = F_80 ( V_34 , V_2 ) ;
switch ( V_96 ) {
case V_77 :
goto V_105;
case V_79 :
goto V_101;
case V_76 :
case V_80 :
;
}
if ( F_96 ( V_34 ) && ! F_57 ( V_34 ) ) {
if ( ! ( V_2 -> V_102 & V_104 ) )
goto V_101;
if ( ! F_97 ( V_34 , V_82 ) )
goto V_105;
V_95 = 1 ;
}
V_41 = F_36 ( V_34 ) ;
if ( F_93 ( V_34 ) && V_41 ) {
switch ( F_98 ( V_34 , V_84 ) ) {
case V_106 :
goto V_105;
case V_107 :
goto V_101;
case V_108 :
goto V_99;
case V_109 :
;
}
}
if ( F_55 ( V_34 ) ) {
V_91 ++ ;
if ( F_99 ( V_34 ) &&
( ! F_100 () ||
V_2 -> V_110 >= V_111 - 2 ) ) {
F_48 ( V_34 , V_112 ) ;
F_43 ( V_34 ) ;
goto V_101;
}
if ( V_96 == V_80 )
goto V_101;
if ( ! V_95 )
goto V_101;
if ( ! V_2 -> V_113 )
goto V_101;
switch ( F_39 ( V_34 , V_41 , V_2 ) ) {
case V_42 :
V_92 ++ ;
goto V_101;
case V_47 :
goto V_105;
case V_60 :
if ( F_45 ( V_34 ) )
goto V_97;
if ( F_55 ( V_34 ) )
goto V_97;
if ( ! F_90 ( V_34 ) )
goto V_97;
if ( F_55 ( V_34 ) || F_45 ( V_34 ) )
goto V_101;
V_41 = F_36 ( V_34 ) ;
case V_44 :
;
}
}
if ( F_31 ( V_34 ) ) {
if ( ! F_101 ( V_34 , V_2 -> V_102 ) )
goto V_105;
if ( ! V_41 && F_30 ( V_34 ) == 1 ) {
F_38 ( V_34 ) ;
if ( F_102 ( V_34 ) )
goto V_114;
else {
V_93 ++ ;
continue;
}
}
}
if ( ! V_41 || ! F_49 ( V_41 , V_34 ) )
goto V_101;
F_103 ( V_34 ) ;
V_114:
V_93 ++ ;
F_104 ( & V_34 -> V_6 , & V_89 ) ;
continue;
V_99:
if ( F_57 ( V_34 ) )
F_105 ( V_34 ) ;
F_38 ( V_34 ) ;
F_66 ( V_34 ) ;
continue;
V_105:
if ( F_57 ( V_34 ) && F_106 () )
F_105 ( V_34 ) ;
F_69 ( F_91 ( V_34 ) ) ;
F_107 ( V_34 ) ;
V_90 ++ ;
V_101:
F_38 ( V_34 ) ;
V_97:
F_104 ( & V_34 -> V_6 , & V_88 ) ;
F_69 ( F_70 ( V_34 ) || F_68 ( V_34 ) ) ;
}
if ( V_91 && V_91 == V_92 && F_1 ( V_2 ) )
F_108 ( V_83 , V_115 ) ;
F_109 ( & V_89 , 1 ) ;
F_110 ( & V_88 , V_82 ) ;
F_23 ( V_116 , V_90 ) ;
F_111 () ;
* V_85 += V_91 ;
* V_86 += V_94 ;
return V_93 ;
}
unsigned long F_112 ( struct V_83 * V_83 ,
struct V_81 * V_82 )
{
struct V_1 V_2 = {
. V_102 = V_117 ,
. V_110 = V_111 ,
. V_100 = 1 ,
} ;
unsigned long V_18 , V_118 , V_119 ;
struct V_34 * V_34 , * V_120 ;
F_86 ( V_121 ) ;
F_113 (page, next, page_list, lru) {
if ( F_99 ( V_34 ) && ! F_55 ( V_34 ) ) {
F_114 ( V_34 ) ;
F_115 ( & V_34 -> V_6 , & V_121 ) ;
}
}
V_18 = F_85 ( & V_121 , V_83 , & V_2 ,
V_122 | V_123 ,
& V_118 , & V_119 , true ) ;
F_110 ( & V_121 , V_82 ) ;
F_116 ( V_83 , V_124 , - V_18 ) ;
return V_18 ;
}
int F_117 ( struct V_34 * V_34 , T_3 V_125 )
{
int V_18 = - V_126 ;
if ( ! F_70 ( V_34 ) )
return V_18 ;
if ( F_68 ( V_34 ) && ! ( V_125 & V_127 ) )
return V_18 ;
V_18 = - V_128 ;
if ( V_125 & ( V_129 | V_130 ) ) {
if ( F_45 ( V_34 ) )
return V_18 ;
if ( F_55 ( V_34 ) ) {
struct V_40 * V_41 ;
if ( V_125 & V_129 )
return V_18 ;
V_41 = F_36 ( V_34 ) ;
if ( V_41 && ! V_41 -> V_45 -> V_131 )
return V_18 ;
}
}
if ( ( V_125 & V_132 ) && F_93 ( V_34 ) )
return V_18 ;
if ( F_118 ( F_119 ( V_34 ) ) ) {
F_120 ( V_34 ) ;
V_18 = 0 ;
}
return V_18 ;
}
static unsigned long F_121 ( unsigned long V_14 ,
struct V_4 * V_4 , struct V_81 * V_133 ,
unsigned long * V_98 , struct V_1 * V_2 ,
T_3 V_125 , enum V_5 V_6 )
{
struct V_81 * V_134 = & V_4 -> V_135 [ V_6 ] ;
unsigned long V_136 = 0 ;
unsigned long V_137 ;
for ( V_137 = 0 ; V_137 < V_14 && ! F_88 ( V_134 ) ; V_137 ++ ) {
struct V_34 * V_34 ;
int V_138 ;
V_34 = F_89 ( V_134 ) ;
F_122 ( V_34 , V_134 , V_38 ) ;
F_69 ( ! F_70 ( V_34 ) ) ;
switch ( F_117 ( V_34 , V_125 ) ) {
case 0 :
V_138 = F_123 ( V_34 ) ;
F_124 ( V_4 , V_6 , - V_138 ) ;
F_115 ( & V_34 -> V_6 , V_133 ) ;
V_136 += V_138 ;
break;
case - V_128 :
F_115 ( & V_34 -> V_6 , V_134 ) ;
continue;
default:
F_125 () ;
}
}
* V_98 = V_137 ;
F_126 ( V_2 -> V_139 , V_14 , V_137 ,
V_136 , V_125 , F_127 ( V_6 ) ) ;
return V_136 ;
}
int F_77 ( struct V_34 * V_34 )
{
int V_18 = - V_128 ;
F_69 ( ! F_30 ( V_34 ) ) ;
if ( F_70 ( V_34 ) ) {
struct V_83 * V_83 = F_92 ( V_34 ) ;
struct V_4 * V_4 ;
F_52 ( & V_83 -> V_140 ) ;
V_4 = F_128 ( V_34 , V_83 ) ;
if ( F_70 ( V_34 ) ) {
int V_6 = F_129 ( V_34 ) ;
F_130 ( V_34 ) ;
F_120 ( V_34 ) ;
F_131 ( V_34 , V_4 , V_6 ) ;
V_18 = 0 ;
}
F_60 ( & V_83 -> V_140 ) ;
}
return V_18 ;
}
static int F_132 ( struct V_83 * V_83 , int V_141 ,
struct V_1 * V_2 )
{
unsigned long V_142 , V_143 ;
if ( F_100 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_141 ) {
V_142 = F_5 ( V_83 , V_144 ) ;
V_143 = F_5 ( V_83 , V_124 ) ;
} else {
V_142 = F_5 ( V_83 , V_145 ) ;
V_143 = F_5 ( V_83 , V_146 ) ;
}
if ( ( V_2 -> V_102 & V_147 ) == V_147 )
V_142 >>= 3 ;
return V_143 > V_142 ;
}
static T_4 void
F_133 ( struct V_4 * V_4 , struct V_81 * V_82 )
{
struct V_148 * V_149 = & V_4 -> V_149 ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
F_86 ( V_150 ) ;
while ( ! F_88 ( V_82 ) ) {
struct V_34 * V_34 = F_89 ( V_82 ) ;
int V_6 ;
F_69 ( F_70 ( V_34 ) ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( F_54 ( ! F_72 ( V_34 ) ) ) {
F_60 ( & V_83 -> V_140 ) ;
F_66 ( V_34 ) ;
F_52 ( & V_83 -> V_140 ) ;
continue;
}
V_4 = F_128 ( V_34 , V_83 ) ;
F_134 ( V_34 ) ;
V_6 = F_129 ( V_34 ) ;
F_135 ( V_34 , V_4 , V_6 ) ;
if ( F_136 ( V_6 ) ) {
int V_141 = F_127 ( V_6 ) ;
int V_151 = F_123 ( V_34 ) ;
V_149 -> V_152 [ V_141 ] += V_151 ;
}
if ( F_102 ( V_34 ) ) {
F_137 ( V_34 ) ;
F_138 ( V_34 ) ;
F_131 ( V_34 , V_4 , V_6 ) ;
if ( F_54 ( F_139 ( V_34 ) ) ) {
F_60 ( & V_83 -> V_140 ) ;
( * F_140 ( V_34 ) ) ( V_34 ) ;
F_52 ( & V_83 -> V_140 ) ;
} else
F_104 ( & V_34 -> V_6 , & V_150 ) ;
}
}
F_110 ( & V_150 , V_82 ) ;
}
static T_4 unsigned long
F_141 ( unsigned long V_14 , struct V_4 * V_4 ,
struct V_1 * V_2 , enum V_5 V_6 )
{
F_86 ( V_82 ) ;
unsigned long V_98 ;
unsigned long V_93 = 0 ;
unsigned long V_136 ;
unsigned long V_91 = 0 ;
unsigned long V_94 = 0 ;
T_3 V_153 = 0 ;
int V_141 = F_127 ( V_6 ) ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
struct V_148 * V_149 = & V_4 -> V_149 ;
while ( F_54 ( F_132 ( V_83 , V_141 , V_2 ) ) ) {
F_142 ( V_154 , V_155 / 10 ) ;
if ( F_143 ( V_37 ) )
return V_19 ;
}
F_144 () ;
if ( ! V_2 -> V_100 )
V_153 |= V_132 ;
if ( ! V_2 -> V_113 )
V_153 |= V_129 ;
F_52 ( & V_83 -> V_140 ) ;
V_136 = F_121 ( V_14 , V_4 , & V_82 ,
& V_98 , V_2 , V_153 , V_6 ) ;
F_116 ( V_83 , V_7 + V_6 , - V_136 ) ;
F_116 ( V_83 , V_146 + V_141 , V_136 ) ;
if ( F_1 ( V_2 ) ) {
V_83 -> V_156 += V_98 ;
if ( F_100 () )
F_145 ( V_157 , V_83 , V_98 ) ;
else
F_145 ( V_158 , V_83 , V_98 ) ;
}
F_60 ( & V_83 -> V_140 ) ;
if ( V_136 == 0 )
return 0 ;
V_93 = F_85 ( & V_82 , V_83 , V_2 , V_122 ,
& V_91 , & V_94 , false ) ;
F_52 ( & V_83 -> V_140 ) ;
V_149 -> V_159 [ V_141 ] += V_136 ;
if ( F_1 ( V_2 ) ) {
if ( F_100 () )
F_145 ( V_160 , V_83 ,
V_93 ) ;
else
F_145 ( V_161 , V_83 ,
V_93 ) ;
}
F_133 ( V_4 , & V_82 ) ;
F_116 ( V_83 , V_146 + V_141 , - V_136 ) ;
F_60 ( & V_83 -> V_140 ) ;
F_109 ( & V_82 , 1 ) ;
if ( V_94 && V_94 >=
( V_136 >> ( V_111 - V_2 -> V_110 ) ) )
F_146 ( V_83 , V_154 , V_155 / 10 ) ;
F_147 ( V_83 -> V_162 -> V_163 ,
F_148 ( V_83 ) ,
V_98 , V_93 ,
V_2 -> V_110 ,
F_149 ( V_141 ) ) ;
return V_93 ;
}
static void F_150 ( struct V_4 * V_4 ,
struct V_81 * V_11 ,
struct V_81 * V_150 ,
enum V_5 V_6 )
{
struct V_83 * V_83 = F_6 ( V_4 ) ;
unsigned long V_164 = 0 ;
struct V_34 * V_34 ;
int V_138 ;
while ( ! F_88 ( V_11 ) ) {
V_34 = F_89 ( V_11 ) ;
V_4 = F_128 ( V_34 , V_83 ) ;
F_69 ( F_70 ( V_34 ) ) ;
F_134 ( V_34 ) ;
V_138 = F_123 ( V_34 ) ;
F_124 ( V_4 , V_6 , V_138 ) ;
F_115 ( & V_34 -> V_6 , & V_4 -> V_135 [ V_6 ] ) ;
V_164 += V_138 ;
if ( F_102 ( V_34 ) ) {
F_137 ( V_34 ) ;
F_138 ( V_34 ) ;
F_131 ( V_34 , V_4 , V_6 ) ;
if ( F_54 ( F_139 ( V_34 ) ) ) {
F_60 ( & V_83 -> V_140 ) ;
( * F_140 ( V_34 ) ) ( V_34 ) ;
F_52 ( & V_83 -> V_140 ) ;
} else
F_104 ( & V_34 -> V_6 , V_150 ) ;
}
}
F_116 ( V_83 , V_7 + V_6 , V_164 ) ;
if ( ! F_136 ( V_6 ) )
F_151 ( V_165 , V_164 ) ;
}
static void F_152 ( unsigned long V_14 ,
struct V_4 * V_4 ,
struct V_1 * V_2 ,
enum V_5 V_6 )
{
unsigned long V_136 ;
unsigned long V_98 ;
unsigned long V_74 ;
F_86 ( V_166 ) ;
F_86 ( V_167 ) ;
F_86 ( V_168 ) ;
struct V_34 * V_34 ;
struct V_148 * V_149 = & V_4 -> V_149 ;
unsigned long V_169 = 0 ;
T_3 V_153 = 0 ;
int V_141 = F_127 ( V_6 ) ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
F_144 () ;
if ( ! V_2 -> V_100 )
V_153 |= V_132 ;
if ( ! V_2 -> V_113 )
V_153 |= V_129 ;
F_52 ( & V_83 -> V_140 ) ;
V_136 = F_121 ( V_14 , V_4 , & V_166 ,
& V_98 , V_2 , V_153 , V_6 ) ;
if ( F_1 ( V_2 ) )
V_83 -> V_156 += V_98 ;
V_149 -> V_159 [ V_141 ] += V_136 ;
F_145 ( V_170 , V_83 , V_98 ) ;
F_116 ( V_83 , V_7 + V_6 , - V_136 ) ;
F_116 ( V_83 , V_146 + V_141 , V_136 ) ;
F_60 ( & V_83 -> V_140 ) ;
while ( ! F_88 ( & V_166 ) ) {
F_24 () ;
V_34 = F_89 ( & V_166 ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( F_54 ( ! F_72 ( V_34 ) ) ) {
F_66 ( V_34 ) ;
continue;
}
if ( F_54 ( V_171 ) ) {
if ( F_31 ( V_34 ) && F_90 ( V_34 ) ) {
if ( F_31 ( V_34 ) )
F_101 ( V_34 , 0 ) ;
F_38 ( V_34 ) ;
}
}
if ( F_81 ( V_34 , 0 , V_2 -> V_3 ,
& V_74 ) ) {
V_169 += F_123 ( V_34 ) ;
if ( ( V_74 & V_78 ) && F_99 ( V_34 ) ) {
F_104 ( & V_34 -> V_6 , & V_167 ) ;
continue;
}
}
F_114 ( V_34 ) ;
F_104 ( & V_34 -> V_6 , & V_168 ) ;
}
F_52 ( & V_83 -> V_140 ) ;
V_149 -> V_152 [ V_141 ] += V_169 ;
F_150 ( V_4 , & V_167 , & V_166 , V_6 ) ;
F_150 ( V_4 , & V_168 , & V_166 , V_6 - V_172 ) ;
F_116 ( V_83 , V_146 + V_141 , - V_136 ) ;
F_60 ( & V_83 -> V_140 ) ;
F_109 ( & V_166 , 1 ) ;
}
static int F_153 ( struct V_83 * V_83 )
{
unsigned long V_65 , V_142 ;
V_65 = F_5 ( V_83 , V_173 ) ;
V_142 = F_5 ( V_83 , V_145 ) ;
if ( V_142 * V_83 -> V_174 < V_65 )
return 1 ;
return 0 ;
}
static int F_154 ( struct V_4 * V_4 )
{
if ( ! V_175 )
return 0 ;
if ( ! F_3 () )
return F_155 ( V_4 ) ;
return F_153 ( F_6 ( V_4 ) ) ;
}
static inline int F_154 ( struct V_4 * V_4 )
{
return 0 ;
}
static int F_156 ( struct V_4 * V_4 )
{
unsigned long V_142 ;
unsigned long V_65 ;
V_142 = F_2 ( V_4 , V_176 ) ;
V_65 = F_2 ( V_4 , V_177 ) ;
return V_65 > V_142 ;
}
static int F_157 ( struct V_4 * V_4 , enum V_5 V_6 )
{
if ( F_127 ( V_6 ) )
return F_156 ( V_4 ) ;
else
return F_154 ( V_4 ) ;
}
static unsigned long F_158 ( enum V_5 V_6 , unsigned long V_14 ,
struct V_4 * V_4 , struct V_1 * V_2 )
{
if ( F_136 ( V_6 ) ) {
if ( F_157 ( V_4 , V_6 ) )
F_152 ( V_14 , V_4 , V_2 , V_6 ) ;
return 0 ;
}
return F_141 ( V_14 , V_4 , V_2 , V_6 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_178 ;
return F_160 ( V_2 -> V_3 ) ;
}
static void F_161 ( struct V_4 * V_4 , struct V_1 * V_2 ,
unsigned long * V_25 )
{
struct V_148 * V_149 = & V_4 -> V_149 ;
T_5 V_179 [ 2 ] ;
T_5 V_180 = 0 ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
unsigned long V_181 , V_182 ;
enum V_183 V_183 ;
unsigned long V_184 , V_141 , free ;
bool V_185 = false ;
unsigned long V_186 , V_187 ;
enum V_5 V_6 ;
if ( F_100 () && V_83 -> V_188 )
V_185 = true ;
if ( ! F_1 ( V_2 ) )
V_185 = true ;
if ( ! V_2 -> V_189 || ( F_162 () <= 0 ) ) {
V_183 = V_190 ;
goto V_20;
}
if ( ! F_1 ( V_2 ) && ! F_159 ( V_2 ) ) {
V_183 = V_190 ;
goto V_20;
}
if ( ! V_2 -> V_110 && F_159 ( V_2 ) ) {
V_183 = V_191 ;
goto V_20;
}
V_184 = F_2 ( V_4 , V_192 ) +
F_2 ( V_4 , V_193 ) ;
V_141 = F_2 ( V_4 , V_177 ) +
F_2 ( V_4 , V_176 ) ;
if ( F_1 ( V_2 ) ) {
free = F_5 ( V_83 , V_194 ) ;
if ( F_54 ( V_141 + free <= F_163 ( V_83 ) ) ) {
V_183 = V_195 ;
goto V_20;
}
}
if ( ! F_156 ( V_4 ) ) {
V_183 = V_190 ;
goto V_20;
}
V_183 = V_196 ;
V_181 = F_159 ( V_2 ) ;
V_182 = 200 - V_181 ;
F_52 ( & V_83 -> V_140 ) ;
if ( F_54 ( V_149 -> V_159 [ 0 ] > V_184 / 4 ) ) {
V_149 -> V_159 [ 0 ] /= 2 ;
V_149 -> V_152 [ 0 ] /= 2 ;
}
if ( F_54 ( V_149 -> V_159 [ 1 ] > V_141 / 4 ) ) {
V_149 -> V_159 [ 1 ] /= 2 ;
V_149 -> V_152 [ 1 ] /= 2 ;
}
V_186 = V_181 * ( V_149 -> V_159 [ 0 ] + 1 ) ;
V_186 /= V_149 -> V_152 [ 0 ] + 1 ;
V_187 = V_182 * ( V_149 -> V_159 [ 1 ] + 1 ) ;
V_187 /= V_149 -> V_152 [ 1 ] + 1 ;
F_60 ( & V_83 -> V_140 ) ;
V_179 [ 0 ] = V_186 ;
V_179 [ 1 ] = V_187 ;
V_180 = V_186 + V_187 + 1 ;
V_20:
F_164 (lru) {
int V_141 = F_127 ( V_6 ) ;
unsigned long V_197 ;
unsigned long V_137 ;
V_197 = F_2 ( V_4 , V_6 ) ;
V_137 = V_197 >> V_2 -> V_110 ;
if ( ! V_137 && V_185 )
V_137 = F_21 ( V_197 , V_19 ) ;
switch ( V_183 ) {
case V_191 :
break;
case V_196 :
V_137 = F_165 ( V_137 * V_179 [ V_141 ] , V_180 ) ;
break;
case V_190 :
case V_195 :
if ( ( V_183 == V_190 ) != V_141 )
V_137 = 0 ;
break;
default:
F_125 () ;
}
V_25 [ V_6 ] = V_137 ;
}
}
static void F_166 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_25 [ V_198 ] ;
unsigned long V_14 ;
enum V_5 V_6 ;
unsigned long V_93 = 0 ;
unsigned long V_199 = V_2 -> V_199 ;
struct V_200 V_201 ;
F_161 ( V_4 , V_2 , V_25 ) ;
F_167 ( & V_201 ) ;
while ( V_25 [ V_193 ] || V_25 [ V_177 ] ||
V_25 [ V_176 ] ) {
F_164 (lru) {
if ( V_25 [ V_6 ] ) {
V_14 = F_21 ( V_25 [ V_6 ] , V_19 ) ;
V_25 [ V_6 ] -= V_14 ;
V_93 += F_158 ( V_6 , V_14 ,
V_4 , V_2 ) ;
}
}
if ( V_93 >= V_199 &&
V_2 -> V_110 < V_111 )
break;
}
F_168 ( & V_201 ) ;
V_2 -> V_93 += V_93 ;
if ( F_154 ( V_4 ) )
F_152 ( V_19 , V_4 ,
V_2 , V_192 ) ;
F_169 ( V_2 -> V_102 ) ;
}
static bool F_170 ( struct V_1 * V_2 )
{
if ( F_171 ( V_202 ) && V_2 -> V_139 &&
( V_2 -> V_139 > V_203 ||
V_2 -> V_110 < V_111 - 2 ) )
return true ;
return false ;
}
static inline bool F_172 ( struct V_83 * V_83 ,
unsigned long V_93 ,
unsigned long V_98 ,
struct V_1 * V_2 )
{
unsigned long V_204 ;
unsigned long V_205 ;
if ( ! F_170 ( V_2 ) )
return false ;
if ( V_2 -> V_102 & V_206 ) {
if ( ! V_93 && ! V_98 )
return false ;
} else {
if ( ! V_93 )
return false ;
}
V_204 = ( 2UL << V_2 -> V_139 ) ;
V_205 = F_5 ( V_83 , V_144 ) ;
if ( F_162 () > 0 )
V_205 += F_5 ( V_83 , V_145 ) ;
if ( V_2 -> V_93 < V_204 &&
V_205 > V_204 )
return true ;
switch ( F_173 ( V_83 , V_2 -> V_139 ) ) {
case V_207 :
case V_208 :
return false ;
default:
return true ;
}
}
static void F_174 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
unsigned long V_93 , V_98 ;
do {
struct V_209 * V_210 = V_2 -> V_3 ;
struct V_211 V_212 = {
. V_83 = V_83 ,
. V_110 = V_2 -> V_110 ,
} ;
struct V_209 * V_213 ;
V_93 = V_2 -> V_93 ;
V_98 = V_2 -> V_98 ;
V_213 = F_175 ( V_210 , NULL , & V_212 ) ;
do {
struct V_4 * V_4 ;
V_4 = F_176 ( V_83 , V_213 ) ;
F_166 ( V_4 , V_2 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_93 >= V_2 -> V_199 ) {
F_177 ( V_210 , V_213 ) ;
break;
}
V_213 = F_175 ( V_210 , V_213 , & V_212 ) ;
} while ( V_213 );
F_178 ( V_2 -> V_102 , V_2 -> V_3 ,
V_2 -> V_98 - V_98 ,
V_2 -> V_93 - V_93 ) ;
} while ( F_172 ( V_83 , V_2 -> V_93 - V_93 ,
V_2 -> V_98 - V_98 , V_2 ) );
}
static inline bool F_179 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
unsigned long V_214 , V_215 ;
bool V_216 ;
if ( V_2 -> V_139 <= V_203 )
return false ;
V_214 = F_21 ( F_180 ( V_83 ) ,
( V_83 -> V_217 + V_218 - 1 ) /
V_218 ) ;
V_215 = F_163 ( V_83 ) + V_214 + ( 2UL << V_2 -> V_139 ) ;
V_216 = F_181 ( V_83 , 0 , V_215 , 0 , 0 ) ;
if ( F_182 ( V_83 , V_2 -> V_139 ) )
return V_216 ;
if ( ! F_173 ( V_83 , V_2 -> V_139 ) )
return false ;
return V_216 ;
}
static bool F_183 ( struct V_219 * V_219 , struct V_1 * V_2 )
{
struct V_220 * V_221 ;
struct V_83 * V_83 ;
unsigned long V_222 ;
unsigned long V_223 ;
bool V_224 = false ;
if ( V_171 )
V_2 -> V_102 |= V_225 ;
F_184 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_185 ( V_83 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_186 ( V_83 , V_117 ) )
continue;
if ( V_83 -> V_188 &&
V_2 -> V_110 != V_111 )
continue;
if ( F_171 ( V_202 ) ) {
if ( F_179 ( V_83 , V_2 ) ) {
V_224 = true ;
continue;
}
}
V_223 = 0 ;
V_222 = F_187 ( V_83 ,
V_2 -> V_139 , V_2 -> V_102 ,
& V_223 ) ;
V_2 -> V_93 += V_222 ;
V_2 -> V_98 += V_223 ;
}
F_174 ( V_83 , V_2 ) ;
}
return V_224 ;
}
static bool F_188 ( struct V_83 * V_83 )
{
return V_83 -> V_156 < F_189 ( V_83 ) * 6 ;
}
static bool V_188 ( struct V_219 * V_219 ,
struct V_1 * V_2 )
{
struct V_220 * V_221 ;
struct V_83 * V_83 ;
F_184 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_185 ( V_83 ) )
continue;
if ( ! F_186 ( V_83 , V_117 ) )
continue;
if ( ! V_83 -> V_188 )
return false ;
}
return true ;
}
static unsigned long F_190 ( struct V_219 * V_219 ,
struct V_1 * V_2 ,
struct V_13 * V_15 )
{
unsigned long V_226 = 0 ;
struct V_227 * V_227 = V_37 -> V_227 ;
struct V_220 * V_221 ;
struct V_83 * V_83 ;
unsigned long V_228 ;
bool V_224 ;
F_191 () ;
if ( F_1 ( V_2 ) )
F_79 ( V_229 ) ;
do {
F_192 ( V_2 -> V_102 , V_2 -> V_3 ,
V_2 -> V_110 ) ;
V_2 -> V_98 = 0 ;
V_224 = F_183 ( V_219 , V_2 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_17 = 0 ;
F_193 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_186 ( V_83 , V_117 ) )
continue;
V_17 += F_189 ( V_83 ) ;
}
F_15 ( V_15 , V_2 -> V_98 , V_17 ) ;
if ( V_227 ) {
V_2 -> V_93 += V_227 -> V_230 ;
V_227 -> V_230 = 0 ;
}
}
V_226 += V_2 -> V_98 ;
if ( V_2 -> V_93 >= V_2 -> V_199 )
goto V_20;
if ( V_2 -> V_110 < V_111 - 2 )
V_2 -> V_113 = 1 ;
V_228 = V_2 -> V_199 + V_2 -> V_199 / 2 ;
if ( V_226 > V_228 ) {
F_194 ( V_231 ? 0 : V_226 ,
V_232 ) ;
V_2 -> V_113 = 1 ;
}
if ( ! V_2 -> V_233 && V_2 -> V_98 &&
V_2 -> V_110 < V_111 - 2 ) {
struct V_83 * V_234 ;
F_195 ( V_219 , F_196 ( V_2 -> V_102 ) ,
& V_235 ,
& V_234 ) ;
F_146 ( V_234 , V_154 , V_155 / 10 ) ;
}
} while ( -- V_2 -> V_110 >= 0 );
V_20:
F_197 () ;
if ( V_2 -> V_93 )
return V_2 -> V_93 ;
if ( V_236 )
return 0 ;
if ( V_224 )
return 1 ;
if ( F_1 ( V_2 ) && ! V_188 ( V_219 , V_2 ) )
return 1 ;
return 0 ;
}
static bool F_198 ( T_6 * V_237 )
{
struct V_83 * V_83 ;
unsigned long V_238 = 0 ;
unsigned long V_89 = 0 ;
int V_239 ;
bool V_240 ;
for ( V_239 = 0 ; V_239 <= V_241 ; V_239 ++ ) {
V_83 = & V_237 -> V_242 [ V_239 ] ;
V_238 += F_199 ( V_83 ) ;
V_89 += F_5 ( V_83 , V_194 ) ;
}
V_240 = V_89 > V_238 / 2 ;
if ( ! V_240 && F_200 ( & V_237 -> V_243 ) ) {
V_237 -> V_244 = F_21 ( V_237 -> V_244 ,
(enum V_245 ) V_241 ) ;
F_201 ( & V_237 -> V_243 ) ;
}
return V_240 ;
}
static bool F_202 ( T_7 V_102 , struct V_219 * V_219 ,
T_8 * V_246 )
{
struct V_83 * V_83 ;
int V_247 = F_196 ( V_102 ) ;
T_6 * V_237 ;
if ( V_37 -> V_38 & V_248 )
goto V_20;
if ( F_143 ( V_37 ) )
goto V_20;
F_195 ( V_219 , V_247 , NULL , & V_83 ) ;
V_237 = V_83 -> V_162 ;
if ( F_198 ( V_237 ) )
goto V_20;
F_79 ( V_249 ) ;
if ( ! ( V_102 & V_103 ) ) {
F_203 ( V_237 -> V_250 ,
F_198 ( V_237 ) , V_155 ) ;
goto V_251;
}
F_204 ( V_83 -> V_162 -> V_250 ,
F_198 ( V_237 ) ) ;
V_251:
if ( F_143 ( V_37 ) )
return true ;
V_20:
return false ;
}
unsigned long F_205 ( struct V_219 * V_219 , int V_139 ,
T_7 V_102 , T_8 * V_246 )
{
unsigned long V_93 ;
struct V_1 V_2 = {
. V_102 = ( V_102 = F_206 ( V_102 ) ) ,
. V_113 = ! V_231 ,
. V_199 = V_19 ,
. V_100 = 1 ,
. V_189 = 1 ,
. V_139 = V_139 ,
. V_110 = V_111 ,
. V_3 = NULL ,
. V_246 = V_246 ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
if ( F_202 ( V_102 , V_219 , V_246 ) )
return 1 ;
F_207 ( V_139 ,
V_2 . V_113 ,
V_102 ) ;
V_93 = F_190 ( V_219 , & V_2 , & V_15 ) ;
F_208 ( V_93 ) ;
return V_93 ;
}
unsigned long F_209 ( struct V_209 * V_213 ,
T_7 V_102 , bool V_252 ,
struct V_83 * V_83 ,
unsigned long * V_98 )
{
struct V_1 V_2 = {
. V_98 = 0 ,
. V_199 = V_19 ,
. V_113 = ! V_231 ,
. V_100 = 1 ,
. V_189 = ! V_252 ,
. V_139 = 0 ,
. V_110 = 0 ,
. V_3 = V_213 ,
} ;
struct V_4 * V_4 = F_176 ( V_83 , V_213 ) ;
V_2 . V_102 = ( V_102 & V_253 ) |
( V_254 & ~ V_253 ) ;
F_210 ( V_2 . V_139 ,
V_2 . V_113 ,
V_2 . V_102 ) ;
F_166 ( V_4 , & V_2 ) ;
F_211 ( V_2 . V_93 ) ;
* V_98 = V_2 . V_98 ;
return V_2 . V_93 ;
}
unsigned long F_212 ( struct V_209 * V_213 ,
T_7 V_102 ,
bool V_252 )
{
struct V_219 * V_219 ;
unsigned long V_93 ;
int V_255 ;
struct V_1 V_2 = {
. V_113 = ! V_231 ,
. V_100 = 1 ,
. V_189 = ! V_252 ,
. V_199 = V_19 ,
. V_139 = 0 ,
. V_110 = V_111 ,
. V_3 = V_213 ,
. V_246 = NULL ,
. V_102 = ( V_102 & V_253 ) |
( V_254 & ~ V_253 ) ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
V_255 = F_213 ( V_213 ) ;
V_219 = F_214 ( V_255 ) -> V_256 ;
F_215 ( 0 ,
V_2 . V_113 ,
V_2 . V_102 ) ;
V_93 = F_190 ( V_219 , & V_2 , & V_15 ) ;
F_216 ( V_93 ) ;
return V_93 ;
}
static void F_217 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
struct V_209 * V_213 ;
if ( ! V_175 )
return;
V_213 = F_175 ( NULL , NULL , NULL ) ;
do {
struct V_4 * V_4 = F_176 ( V_83 , V_213 ) ;
if ( F_154 ( V_4 ) )
F_152 ( V_19 , V_4 ,
V_2 , V_192 ) ;
V_213 = F_175 ( NULL , V_213 , NULL ) ;
} while ( V_213 );
}
static bool F_218 ( struct V_83 * V_83 , int V_139 ,
unsigned long V_214 , int V_244 )
{
if ( ! F_181 ( V_83 , V_139 , F_163 ( V_83 ) +
V_214 , V_244 , 0 ) )
return false ;
if ( F_171 ( V_202 ) && V_139 &&
! F_173 ( V_83 , V_139 ) )
return false ;
return true ;
}
static bool F_219 ( T_6 * V_237 , int V_139 , int V_244 )
{
unsigned long V_217 = 0 ;
unsigned long V_257 = 0 ;
int V_239 ;
for ( V_239 = 0 ; V_239 <= V_244 ; V_239 ++ ) {
struct V_83 * V_83 = V_237 -> V_242 + V_239 ;
if ( ! F_185 ( V_83 ) )
continue;
V_217 += V_83 -> V_217 ;
if ( V_83 -> V_188 ) {
V_257 += V_83 -> V_217 ;
continue;
}
if ( F_218 ( V_83 , V_139 , 0 , V_239 ) )
V_257 += V_83 -> V_217 ;
else if ( ! V_139 )
return false ;
}
if ( V_139 )
return V_257 >= ( V_217 >> 2 ) ;
else
return true ;
}
static bool F_220 ( T_6 * V_237 , int V_139 , long V_258 ,
int V_244 )
{
if ( V_258 )
return false ;
if ( F_200 ( & V_237 -> V_250 ) ) {
F_221 ( & V_237 -> V_250 ) ;
return false ;
}
return F_219 ( V_237 , V_139 , V_244 ) ;
}
static unsigned long F_222 ( T_6 * V_237 , int V_139 ,
int * V_244 )
{
bool V_259 = false ;
int V_239 ;
int V_260 = 0 ;
struct V_227 * V_227 = V_37 -> V_227 ;
unsigned long V_222 ;
unsigned long V_223 ;
struct V_1 V_2 = {
. V_102 = V_117 ,
. V_100 = 1 ,
. V_189 = 1 ,
. V_199 = V_261 ,
. V_139 = V_139 ,
. V_3 = NULL ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
V_262:
V_2 . V_110 = V_111 ;
V_2 . V_93 = 0 ;
V_2 . V_113 = ! V_231 ;
F_79 ( V_263 ) ;
do {
unsigned long V_17 = 0 ;
for ( V_239 = V_237 -> V_264 - 1 ; V_239 >= 0 ; V_239 -- ) {
struct V_83 * V_83 = V_237 -> V_242 + V_239 ;
if ( ! F_185 ( V_83 ) )
continue;
if ( V_83 -> V_188 &&
V_2 . V_110 != V_111 )
continue;
F_217 ( V_83 , & V_2 ) ;
if ( V_171 && F_223 ( V_239 ) ) {
V_260 = V_239 ;
break;
}
if ( ! F_218 ( V_83 , V_139 , 0 , 0 ) ) {
V_260 = V_239 ;
break;
} else {
F_224 ( V_83 , V_115 ) ;
}
}
if ( V_239 < 0 ) {
V_259 = true ;
goto V_20;
}
for ( V_239 = 0 ; V_239 <= V_260 ; V_239 ++ ) {
struct V_83 * V_83 = V_237 -> V_242 + V_239 ;
V_17 += F_189 ( V_83 ) ;
}
for ( V_239 = 0 ; V_239 <= V_260 ; V_239 ++ ) {
struct V_83 * V_83 = V_237 -> V_242 + V_239 ;
int V_265 , V_266 ;
unsigned long V_214 ;
if ( ! F_185 ( V_83 ) )
continue;
if ( V_83 -> V_188 &&
V_2 . V_110 != V_111 )
continue;
V_2 . V_98 = 0 ;
V_223 = 0 ;
V_222 = F_187 ( V_83 ,
V_139 , V_2 . V_102 ,
& V_223 ) ;
V_2 . V_93 += V_222 ;
V_214 = F_21 ( F_180 ( V_83 ) ,
( V_83 -> V_217 +
V_218 - 1 ) /
V_218 ) ;
V_266 = V_139 ;
if ( F_171 ( V_202 ) && V_139 &&
F_173 ( V_83 , V_139 ) !=
V_267 )
V_266 = 0 ;
if ( ( V_171 && F_223 ( V_239 ) ) ||
! F_218 ( V_83 , V_266 ,
V_214 , V_260 ) ) {
F_174 ( V_83 , & V_2 ) ;
V_227 -> V_230 = 0 ;
V_265 = F_15 ( & V_15 , V_2 . V_98 , V_17 ) ;
V_2 . V_93 += V_227 -> V_230 ;
if ( V_265 == 0 && ! F_188 ( V_83 ) )
V_83 -> V_188 = 1 ;
}
if ( V_2 . V_110 < V_111 - 2 )
V_2 . V_113 = 1 ;
if ( V_83 -> V_188 ) {
if ( V_260 && V_260 == V_239 )
V_260 -- ;
continue;
}
if ( F_218 ( V_83 , V_266 , 0 , V_260 ) )
F_224 ( V_83 , V_115 ) ;
}
if ( F_200 ( & V_237 -> V_250 ) &&
F_198 ( V_237 ) )
F_221 ( & V_237 -> V_250 ) ;
if ( F_219 ( V_237 , V_139 , * V_244 ) ) {
V_259 = true ;
break;
}
if ( V_2 . V_93 >= V_19 )
break;
} while ( -- V_2 . V_110 >= 0 );
V_20:
if ( ! V_259 ) {
F_24 () ;
F_225 () ;
if ( V_2 . V_93 < V_19 )
V_139 = V_2 . V_139 = 0 ;
goto V_262;
}
if ( V_139 ) {
int V_268 = 1 ;
for ( V_239 = 0 ; V_239 <= V_260 ; V_239 ++ ) {
struct V_83 * V_83 = V_237 -> V_242 + V_239 ;
if ( ! F_185 ( V_83 ) )
continue;
if ( F_226 ( V_83 , V_139 ,
F_180 ( V_83 ) , * V_244 , 0 ) )
V_268 = 0 ;
}
if ( V_268 )
F_227 ( V_237 , V_139 ) ;
}
* V_244 = V_260 ;
return V_139 ;
}
static void F_228 ( T_6 * V_237 , int V_139 , int V_244 )
{
long V_258 = 0 ;
F_229 ( V_269 ) ;
if ( F_230 ( V_37 ) || F_231 () )
return;
F_232 ( & V_237 -> V_243 , & V_269 , V_270 ) ;
if ( F_220 ( V_237 , V_139 , V_258 , V_244 ) ) {
V_258 = F_233 ( V_155 / 10 ) ;
F_234 ( & V_237 -> V_243 , & V_269 ) ;
F_232 ( & V_237 -> V_243 , & V_269 , V_270 ) ;
}
if ( F_220 ( V_237 , V_139 , V_258 , V_244 ) ) {
F_235 ( V_237 -> V_163 ) ;
F_236 ( V_237 , V_271 ) ;
F_237 ( V_237 ) ;
if ( ! F_231 () )
F_238 () ;
F_236 ( V_237 , V_272 ) ;
} else {
if ( V_258 )
F_79 ( V_273 ) ;
else
F_79 ( V_274 ) ;
}
F_234 ( & V_237 -> V_243 , & V_269 ) ;
}
static int F_239 ( void * V_275 )
{
unsigned long V_139 , V_276 ;
unsigned V_277 ;
int V_244 , V_278 ;
int V_279 ;
T_6 * V_237 = ( T_6 * ) V_275 ;
struct V_280 * V_281 = V_37 ;
struct V_227 V_227 = {
. V_230 = 0 ,
} ;
const struct V_282 * V_282 = F_240 ( V_237 -> V_163 ) ;
F_241 ( V_117 ) ;
if ( ! F_242 ( V_282 ) )
F_243 ( V_281 , V_282 ) ;
V_37 -> V_227 = & V_227 ;
V_281 -> V_38 |= V_283 | V_39 | V_284 ;
F_244 () ;
V_139 = V_276 = 0 ;
V_277 = 0 ;
V_244 = V_278 = V_237 -> V_264 - 1 ;
V_279 = V_244 ;
for ( ; ; ) {
bool V_18 ;
if ( V_279 >= V_278 &&
V_277 == V_276 ) {
V_276 = V_237 -> V_285 ;
V_278 = V_237 -> V_244 ;
V_237 -> V_285 = 0 ;
V_237 -> V_244 = V_237 -> V_264 - 1 ;
}
if ( V_139 < V_276 || V_244 > V_278 ) {
V_139 = V_276 ;
V_244 = V_278 ;
} else {
F_228 ( V_237 , V_277 ,
V_279 ) ;
V_139 = V_237 -> V_285 ;
V_244 = V_237 -> V_244 ;
V_276 = V_139 ;
V_278 = V_244 ;
V_237 -> V_285 = 0 ;
V_237 -> V_244 = V_237 -> V_264 - 1 ;
}
V_18 = F_225 () ;
if ( F_231 () )
break;
if ( ! V_18 ) {
F_245 ( V_237 -> V_163 , V_139 ) ;
V_279 = V_244 ;
V_277 = F_222 ( V_237 , V_139 ,
& V_279 ) ;
}
}
V_37 -> V_227 = NULL ;
return 0 ;
}
void F_246 ( struct V_83 * V_83 , int V_139 , enum V_245 V_244 )
{
T_6 * V_237 ;
if ( ! F_185 ( V_83 ) )
return;
if ( ! F_186 ( V_83 , V_117 ) )
return;
V_237 = V_83 -> V_162 ;
if ( V_237 -> V_285 < V_139 ) {
V_237 -> V_285 = V_139 ;
V_237 -> V_244 = F_21 ( V_237 -> V_244 , V_244 ) ;
}
if ( ! F_200 ( & V_237 -> V_243 ) )
return;
if ( F_181 ( V_83 , V_139 , F_180 ( V_83 ) , 0 , 0 ) )
return;
F_247 ( V_237 -> V_163 , F_148 ( V_83 ) , V_139 ) ;
F_201 ( & V_237 -> V_243 ) ;
}
unsigned long F_248 ( void )
{
int V_25 ;
V_25 = F_249 ( V_286 ) +
F_249 ( V_144 ) ;
if ( F_162 () > 0 )
V_25 += F_249 ( V_173 ) +
F_249 ( V_145 ) ;
return V_25 ;
}
unsigned long F_189 ( struct V_83 * V_83 )
{
int V_25 ;
V_25 = F_5 ( V_83 , V_286 ) +
F_5 ( V_83 , V_144 ) ;
if ( F_162 () > 0 )
V_25 += F_5 ( V_83 , V_173 ) +
F_5 ( V_83 , V_145 ) ;
return V_25 ;
}
unsigned long F_250 ( unsigned long V_199 )
{
struct V_227 V_227 ;
struct V_1 V_2 = {
. V_102 = V_254 ,
. V_189 = 1 ,
. V_100 = 1 ,
. V_113 = 1 ,
. V_199 = V_199 ,
. V_233 = 1 ,
. V_139 = 0 ,
. V_110 = V_111 ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
struct V_219 * V_219 = F_251 ( F_252 () , V_2 . V_102 ) ;
struct V_280 * V_275 = V_37 ;
unsigned long V_93 ;
V_275 -> V_38 |= V_283 ;
F_241 ( V_2 . V_102 ) ;
V_227 . V_230 = 0 ;
V_275 -> V_227 = & V_227 ;
V_93 = F_190 ( V_219 , & V_2 , & V_15 ) ;
V_275 -> V_227 = NULL ;
F_253 () ;
V_275 -> V_38 &= ~ V_283 ;
return V_93 ;
}
static int F_254 ( struct V_287 * V_288 , unsigned long V_289 ,
void * V_290 )
{
int V_255 ;
if ( V_289 == V_291 || V_289 == V_292 ) {
F_255 (nid, N_MEMORY) {
T_6 * V_237 = F_214 ( V_255 ) ;
const struct V_282 * V_293 ;
V_293 = F_240 ( V_237 -> V_163 ) ;
if ( F_256 ( V_294 , V_293 ) < V_295 )
F_243 ( V_237 -> F_239 , V_293 ) ;
}
}
return V_296 ;
}
int F_257 ( int V_255 )
{
T_6 * V_237 = F_214 ( V_255 ) ;
int V_18 = 0 ;
if ( V_237 -> F_239 )
return 0 ;
V_237 -> F_239 = F_258 ( F_239 , V_237 , L_4 , V_255 ) ;
if ( F_259 ( V_237 -> F_239 ) ) {
F_50 ( V_297 == V_298 ) ;
F_260 ( L_5 , V_255 ) ;
V_18 = F_261 ( V_237 -> F_239 ) ;
V_237 -> F_239 = NULL ;
}
return V_18 ;
}
void F_262 ( int V_255 )
{
struct V_280 * F_239 = F_214 ( V_255 ) -> F_239 ;
if ( F_239 ) {
F_263 ( F_239 ) ;
F_214 ( V_255 ) -> F_239 = NULL ;
}
}
static int T_9 F_264 ( void )
{
int V_255 ;
F_265 () ;
F_255 (nid, N_MEMORY)
F_257 ( V_255 ) ;
F_266 ( F_254 , 0 ) ;
return 0 ;
}
static inline unsigned long F_267 ( struct V_83 * V_83 )
{
unsigned long V_299 = F_5 ( V_83 , V_300 ) ;
unsigned long V_301 = F_5 ( V_83 , V_144 ) +
F_5 ( V_83 , V_286 ) ;
return ( V_301 > V_299 ) ? ( V_301 - V_299 ) : 0 ;
}
static long F_268 ( struct V_83 * V_83 )
{
long V_302 ;
long V_21 = 0 ;
if ( V_303 & V_304 )
V_302 = F_5 ( V_83 , V_305 ) ;
else
V_302 = F_267 ( V_83 ) ;
if ( ! ( V_303 & V_306 ) )
V_21 += F_5 ( V_83 , V_307 ) ;
if ( F_54 ( V_21 > V_302 ) )
V_21 = V_302 ;
return V_302 - V_21 ;
}
static int F_269 ( struct V_83 * V_83 , T_7 V_102 , unsigned int V_139 )
{
const unsigned long V_138 = 1 << V_139 ;
struct V_280 * V_275 = V_37 ;
struct V_227 V_227 ;
struct V_1 V_2 = {
. V_113 = ! ! ( V_303 & V_306 ) ,
. V_100 = ! ! ( V_303 & V_304 ) ,
. V_189 = 1 ,
. V_199 = F_270 ( V_138 , V_19 ) ,
. V_102 = ( V_102 = F_206 ( V_102 ) ) ,
. V_139 = V_139 ,
. V_110 = V_308 ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
unsigned long V_309 , V_310 ;
F_24 () ;
V_275 -> V_38 |= V_283 | V_39 ;
F_241 ( V_102 ) ;
V_227 . V_230 = 0 ;
V_275 -> V_227 = & V_227 ;
if ( F_268 ( V_83 ) > V_83 -> V_311 ) {
do {
F_174 ( V_83 , & V_2 ) ;
} while ( V_2 . V_93 < V_138 && -- V_2 . V_110 >= 0 );
}
V_309 = F_5 ( V_83 , V_312 ) ;
if ( V_309 > V_83 -> V_313 ) {
for (; ; ) {
unsigned long V_17 = F_189 ( V_83 ) ;
if ( ! F_15 ( & V_15 , V_2 . V_98 , V_17 ) )
break;
V_310 = F_5 ( V_83 ,
V_312 ) ;
if ( V_310 + V_138 <= V_309 )
break;
}
V_310 = F_5 ( V_83 , V_312 ) ;
if ( V_310 < V_309 )
V_2 . V_93 += V_309 - V_310 ;
}
V_275 -> V_227 = NULL ;
V_37 -> V_38 &= ~ ( V_283 | V_39 ) ;
F_253 () ;
return V_2 . V_93 >= V_138 ;
}
int F_271 ( struct V_83 * V_83 , T_7 V_102 , unsigned int V_139 )
{
int V_163 ;
int V_18 ;
if ( F_268 ( V_83 ) <= V_83 -> V_311 &&
F_5 ( V_83 , V_312 ) <= V_83 -> V_313 )
return V_314 ;
if ( V_83 -> V_188 )
return V_314 ;
if ( ! ( V_102 & V_315 ) || ( V_37 -> V_38 & V_283 ) )
return V_316 ;
V_163 = F_272 ( V_83 ) ;
if ( F_273 ( V_163 , V_317 ) && V_163 != F_252 () )
return V_316 ;
if ( F_274 ( V_83 , V_318 ) )
return V_316 ;
V_18 = F_269 ( V_83 , V_102 , V_139 ) ;
F_224 ( V_83 , V_318 ) ;
if ( ! V_18 )
F_79 ( V_319 ) ;
return V_18 ;
}
int F_72 ( struct V_34 * V_34 )
{
return ! F_275 ( F_36 ( V_34 ) ) && ! F_276 ( V_34 ) ;
}
void F_277 ( struct V_34 * * V_320 , int V_138 )
{
struct V_4 * V_4 ;
struct V_83 * V_83 = NULL ;
int V_321 = 0 ;
int V_322 = 0 ;
int V_239 ;
for ( V_239 = 0 ; V_239 < V_138 ; V_239 ++ ) {
struct V_34 * V_34 = V_320 [ V_239 ] ;
struct V_83 * V_323 ;
V_321 ++ ;
V_323 = F_92 ( V_34 ) ;
if ( V_323 != V_83 ) {
if ( V_83 )
F_60 ( & V_83 -> V_140 ) ;
V_83 = V_323 ;
F_52 ( & V_83 -> V_140 ) ;
}
V_4 = F_128 ( V_34 , V_83 ) ;
if ( ! F_70 ( V_34 ) || ! F_68 ( V_34 ) )
continue;
if ( F_72 ( V_34 ) ) {
enum V_5 V_6 = F_73 ( V_34 ) ;
F_69 ( F_91 ( V_34 ) ) ;
F_71 ( V_34 ) ;
F_131 ( V_34 , V_4 , V_68 ) ;
F_135 ( V_34 , V_4 , V_6 ) ;
V_322 ++ ;
}
}
if ( V_83 ) {
F_151 ( V_69 , V_322 ) ;
F_151 ( V_324 , V_321 ) ;
F_60 ( & V_83 -> V_140 ) ;
}
}
static void F_278 ( void )
{
F_279 ( V_325
L_6
L_7
L_8 ,
V_37 -> V_326 ) ;
}
int F_280 ( struct V_327 * V_328 , int V_329 ,
void T_10 * V_330 ,
T_11 * V_331 , T_12 * V_332 )
{
F_278 () ;
F_281 ( V_328 , V_329 , V_330 , V_331 , V_332 ) ;
V_333 = 0 ;
return 0 ;
}
static T_13 F_282 ( struct V_334 * V_335 ,
struct V_336 * V_337 ,
char * V_338 )
{
F_278 () ;
return sprintf ( V_338 , L_9 ) ;
}
static T_13 F_283 ( struct V_334 * V_335 ,
struct V_336 * V_337 ,
const char * V_338 , T_11 V_339 )
{
F_278 () ;
return 1 ;
}
int F_284 ( struct V_340 * V_340 )
{
return F_285 ( & V_340 -> V_335 , & V_341 ) ;
}
void F_286 ( struct V_340 * V_340 )
{
F_287 ( & V_340 -> V_335 , & V_341 ) ;
}
