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
if ( ! F_97 ( V_34 ) )
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
return V_143 > V_142 ;
}
static T_4 void
F_133 ( struct V_4 * V_4 , struct V_81 * V_82 )
{
struct V_147 * V_148 = & V_4 -> V_148 ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
F_86 ( V_149 ) ;
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
int V_150 = F_123 ( V_34 ) ;
V_148 -> V_151 [ V_141 ] += V_150 ;
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
F_104 ( & V_34 -> V_6 , & V_149 ) ;
}
}
F_110 ( & V_149 , V_82 ) ;
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
T_3 V_152 = 0 ;
int V_141 = F_127 ( V_6 ) ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
struct V_147 * V_148 = & V_4 -> V_148 ;
while ( F_54 ( F_132 ( V_83 , V_141 , V_2 ) ) ) {
F_142 ( V_153 , V_154 / 10 ) ;
if ( F_143 ( V_37 ) )
return V_19 ;
}
F_144 () ;
if ( ! V_2 -> V_100 )
V_152 |= V_132 ;
if ( ! V_2 -> V_113 )
V_152 |= V_129 ;
F_52 ( & V_83 -> V_140 ) ;
V_136 = F_121 ( V_14 , V_4 , & V_82 ,
& V_98 , V_2 , V_152 , V_6 ) ;
F_116 ( V_83 , V_7 + V_6 , - V_136 ) ;
F_116 ( V_83 , V_146 + V_141 , V_136 ) ;
if ( F_1 ( V_2 ) ) {
V_83 -> V_155 += V_98 ;
if ( F_100 () )
F_145 ( V_156 , V_83 , V_98 ) ;
else
F_145 ( V_157 , V_83 , V_98 ) ;
}
F_60 ( & V_83 -> V_140 ) ;
if ( V_136 == 0 )
return 0 ;
V_93 = F_85 ( & V_82 , V_83 , V_2 , V_122 ,
& V_91 , & V_94 , false ) ;
F_52 ( & V_83 -> V_140 ) ;
V_148 -> V_158 [ V_141 ] += V_136 ;
if ( F_1 ( V_2 ) ) {
if ( F_100 () )
F_145 ( V_159 , V_83 ,
V_93 ) ;
else
F_145 ( V_160 , V_83 ,
V_93 ) ;
}
F_133 ( V_4 , & V_82 ) ;
F_116 ( V_83 , V_146 + V_141 , - V_136 ) ;
F_60 ( & V_83 -> V_140 ) ;
F_109 ( & V_82 , 1 ) ;
if ( V_94 && V_94 >=
( V_136 >> ( V_111 - V_2 -> V_110 ) ) )
F_146 ( V_83 , V_153 , V_154 / 10 ) ;
F_147 ( V_83 -> V_161 -> V_162 ,
F_148 ( V_83 ) ,
V_98 , V_93 ,
V_2 -> V_110 ,
F_149 ( V_141 ) ) ;
return V_93 ;
}
static void F_150 ( struct V_4 * V_4 ,
struct V_81 * V_11 ,
struct V_81 * V_149 ,
enum V_5 V_6 )
{
struct V_83 * V_83 = F_6 ( V_4 ) ;
unsigned long V_163 = 0 ;
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
V_163 += V_138 ;
if ( F_102 ( V_34 ) ) {
F_137 ( V_34 ) ;
F_138 ( V_34 ) ;
F_131 ( V_34 , V_4 , V_6 ) ;
if ( F_54 ( F_139 ( V_34 ) ) ) {
F_60 ( & V_83 -> V_140 ) ;
( * F_140 ( V_34 ) ) ( V_34 ) ;
F_52 ( & V_83 -> V_140 ) ;
} else
F_104 ( & V_34 -> V_6 , V_149 ) ;
}
}
F_116 ( V_83 , V_7 + V_6 , V_163 ) ;
if ( ! F_136 ( V_6 ) )
F_151 ( V_164 , V_163 ) ;
}
static void F_152 ( unsigned long V_14 ,
struct V_4 * V_4 ,
struct V_1 * V_2 ,
enum V_5 V_6 )
{
unsigned long V_136 ;
unsigned long V_98 ;
unsigned long V_74 ;
F_86 ( V_165 ) ;
F_86 ( V_166 ) ;
F_86 ( V_167 ) ;
struct V_34 * V_34 ;
struct V_147 * V_148 = & V_4 -> V_148 ;
unsigned long V_168 = 0 ;
T_3 V_152 = 0 ;
int V_141 = F_127 ( V_6 ) ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
F_144 () ;
if ( ! V_2 -> V_100 )
V_152 |= V_132 ;
if ( ! V_2 -> V_113 )
V_152 |= V_129 ;
F_52 ( & V_83 -> V_140 ) ;
V_136 = F_121 ( V_14 , V_4 , & V_165 ,
& V_98 , V_2 , V_152 , V_6 ) ;
if ( F_1 ( V_2 ) )
V_83 -> V_155 += V_98 ;
V_148 -> V_158 [ V_141 ] += V_136 ;
F_145 ( V_169 , V_83 , V_98 ) ;
F_116 ( V_83 , V_7 + V_6 , - V_136 ) ;
F_116 ( V_83 , V_146 + V_141 , V_136 ) ;
F_60 ( & V_83 -> V_140 ) ;
while ( ! F_88 ( & V_165 ) ) {
F_24 () ;
V_34 = F_89 ( & V_165 ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( F_54 ( ! F_72 ( V_34 ) ) ) {
F_66 ( V_34 ) ;
continue;
}
if ( F_54 ( V_170 ) ) {
if ( F_31 ( V_34 ) && F_90 ( V_34 ) ) {
if ( F_31 ( V_34 ) )
F_101 ( V_34 , 0 ) ;
F_38 ( V_34 ) ;
}
}
if ( F_81 ( V_34 , 0 , V_2 -> V_3 ,
& V_74 ) ) {
V_168 += F_123 ( V_34 ) ;
if ( ( V_74 & V_78 ) && F_99 ( V_34 ) ) {
F_104 ( & V_34 -> V_6 , & V_166 ) ;
continue;
}
}
F_114 ( V_34 ) ;
F_104 ( & V_34 -> V_6 , & V_167 ) ;
}
F_52 ( & V_83 -> V_140 ) ;
V_148 -> V_151 [ V_141 ] += V_168 ;
F_150 ( V_4 , & V_166 , & V_165 , V_6 ) ;
F_150 ( V_4 , & V_167 , & V_165 , V_6 - V_171 ) ;
F_116 ( V_83 , V_146 + V_141 , - V_136 ) ;
F_60 ( & V_83 -> V_140 ) ;
F_109 ( & V_165 , 1 ) ;
}
static int F_153 ( struct V_83 * V_83 )
{
unsigned long V_65 , V_142 ;
V_65 = F_5 ( V_83 , V_172 ) ;
V_142 = F_5 ( V_83 , V_145 ) ;
if ( V_142 * V_83 -> V_173 < V_65 )
return 1 ;
return 0 ;
}
static int F_154 ( struct V_4 * V_4 )
{
if ( ! V_174 )
return 0 ;
if ( ! F_3 () )
return F_155 ( V_4 ) ;
return F_153 ( F_6 ( V_4 ) ) ;
}
static inline int F_154 ( struct V_4 * V_4 )
{
return 0 ;
}
static int F_156 ( struct V_83 * V_83 )
{
unsigned long V_65 , V_142 ;
V_65 = F_5 ( V_83 , V_175 ) ;
V_142 = F_5 ( V_83 , V_144 ) ;
return ( V_65 > V_142 ) ;
}
static int F_157 ( struct V_4 * V_4 )
{
if ( ! F_3 () )
return F_158 ( V_4 ) ;
return F_156 ( F_6 ( V_4 ) ) ;
}
static int F_159 ( struct V_4 * V_4 , enum V_5 V_6 )
{
if ( F_127 ( V_6 ) )
return F_157 ( V_4 ) ;
else
return F_154 ( V_4 ) ;
}
static unsigned long F_160 ( enum V_5 V_6 , unsigned long V_14 ,
struct V_4 * V_4 , struct V_1 * V_2 )
{
if ( F_136 ( V_6 ) ) {
if ( F_159 ( V_4 , V_6 ) )
F_152 ( V_14 , V_4 , V_2 , V_6 ) ;
return 0 ;
}
return F_141 ( V_14 , V_4 , V_2 , V_6 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_176 ;
return F_162 ( V_2 -> V_3 ) ;
}
static void F_163 ( struct V_4 * V_4 , struct V_1 * V_2 ,
unsigned long * V_25 )
{
unsigned long V_177 , V_141 , free ;
unsigned long V_178 , V_179 ;
unsigned long V_180 , V_181 ;
struct V_147 * V_148 = & V_4 -> V_148 ;
T_5 V_182 [ 2 ] , V_183 ;
enum V_5 V_6 ;
int V_184 = 0 ;
bool V_185 = false ;
struct V_83 * V_83 = F_6 ( V_4 ) ;
if ( F_100 () && V_83 -> V_186 )
V_185 = true ;
if ( ! F_1 ( V_2 ) )
V_185 = true ;
if ( ! V_2 -> V_187 || ( V_188 <= 0 ) ) {
V_184 = 1 ;
V_182 [ 0 ] = 0 ;
V_182 [ 1 ] = 1 ;
V_183 = 1 ;
goto V_20;
}
V_177 = F_2 ( V_4 , V_189 ) +
F_2 ( V_4 , V_190 ) ;
V_141 = F_2 ( V_4 , V_191 ) +
F_2 ( V_4 , V_192 ) ;
if ( F_1 ( V_2 ) ) {
free = F_5 ( V_83 , V_193 ) ;
if ( F_54 ( V_141 + free <= F_164 ( V_83 ) ) ) {
V_182 [ 0 ] = 1 ;
V_182 [ 1 ] = 0 ;
V_183 = 1 ;
goto V_20;
}
}
V_178 = F_161 ( V_2 ) ;
V_179 = 200 - V_178 ;
F_52 ( & V_83 -> V_140 ) ;
if ( F_54 ( V_148 -> V_158 [ 0 ] > V_177 / 4 ) ) {
V_148 -> V_158 [ 0 ] /= 2 ;
V_148 -> V_151 [ 0 ] /= 2 ;
}
if ( F_54 ( V_148 -> V_158 [ 1 ] > V_141 / 4 ) ) {
V_148 -> V_158 [ 1 ] /= 2 ;
V_148 -> V_151 [ 1 ] /= 2 ;
}
V_180 = V_178 * ( V_148 -> V_158 [ 0 ] + 1 ) ;
V_180 /= V_148 -> V_151 [ 0 ] + 1 ;
V_181 = V_179 * ( V_148 -> V_158 [ 1 ] + 1 ) ;
V_181 /= V_148 -> V_151 [ 1 ] + 1 ;
F_60 ( & V_83 -> V_140 ) ;
V_182 [ 0 ] = V_180 ;
V_182 [ 1 ] = V_181 ;
V_183 = V_180 + V_181 + 1 ;
V_20:
F_165 (lru) {
int V_141 = F_127 ( V_6 ) ;
unsigned long V_137 ;
V_137 = F_2 ( V_4 , V_6 ) ;
if ( V_2 -> V_110 || V_184 || ! F_161 ( V_2 ) ) {
V_137 >>= V_2 -> V_110 ;
if ( ! V_137 && V_185 )
V_137 = V_19 ;
V_137 = F_166 ( V_137 * V_182 [ V_141 ] , V_183 ) ;
}
V_25 [ V_6 ] = V_137 ;
}
}
static bool F_167 ( struct V_1 * V_2 )
{
if ( V_194 && V_2 -> V_139 &&
( V_2 -> V_139 > V_195 ||
V_2 -> V_110 < V_111 - 2 ) )
return true ;
return false ;
}
static inline bool F_168 ( struct V_4 * V_4 ,
unsigned long V_93 ,
unsigned long V_98 ,
struct V_1 * V_2 )
{
unsigned long V_196 ;
unsigned long V_197 ;
if ( ! F_167 ( V_2 ) )
return false ;
if ( V_2 -> V_102 & V_198 ) {
if ( ! V_93 && ! V_98 )
return false ;
} else {
if ( ! V_93 )
return false ;
}
V_196 = ( 2UL << V_2 -> V_139 ) ;
V_197 = F_2 ( V_4 , V_192 ) ;
if ( V_188 > 0 )
V_197 += F_2 ( V_4 , V_190 ) ;
if ( V_2 -> V_93 < V_196 &&
V_197 > V_196 )
return true ;
switch ( F_169 ( F_6 ( V_4 ) , V_2 -> V_139 ) ) {
case V_199 :
case V_200 :
return false ;
default:
return true ;
}
}
static void F_170 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_25 [ V_201 ] ;
unsigned long V_14 ;
enum V_5 V_6 ;
unsigned long V_93 , V_98 ;
unsigned long V_202 = V_2 -> V_202 ;
struct V_203 V_204 ;
V_205:
V_93 = 0 ;
V_98 = V_2 -> V_98 ;
F_163 ( V_4 , V_2 , V_25 ) ;
F_171 ( & V_204 ) ;
while ( V_25 [ V_190 ] || V_25 [ V_191 ] ||
V_25 [ V_192 ] ) {
F_165 (lru) {
if ( V_25 [ V_6 ] ) {
V_14 = F_172 (unsigned long,
nr[lru], SWAP_CLUSTER_MAX) ;
V_25 [ V_6 ] -= V_14 ;
V_93 += F_160 ( V_6 , V_14 ,
V_4 , V_2 ) ;
}
}
if ( V_93 >= V_202 &&
V_2 -> V_110 < V_111 )
break;
}
F_173 ( & V_204 ) ;
V_2 -> V_93 += V_93 ;
if ( F_154 ( V_4 ) )
F_152 ( V_19 , V_4 ,
V_2 , V_189 ) ;
if ( F_168 ( V_4 , V_93 ,
V_2 -> V_98 - V_98 , V_2 ) )
goto V_205;
F_174 ( V_2 -> V_102 ) ;
}
static void F_175 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
struct V_206 * V_207 = V_2 -> V_3 ;
struct V_208 V_209 = {
. V_83 = V_83 ,
. V_110 = V_2 -> V_110 ,
} ;
struct V_206 * V_210 ;
V_210 = F_176 ( V_207 , NULL , & V_209 ) ;
do {
struct V_4 * V_4 = F_177 ( V_83 , V_210 ) ;
F_170 ( V_4 , V_2 ) ;
if ( ! F_1 ( V_2 ) ) {
F_178 ( V_207 , V_210 ) ;
break;
}
V_210 = F_176 ( V_207 , V_210 , & V_209 ) ;
} while ( V_210 );
}
static inline bool F_179 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
unsigned long V_211 , V_212 ;
bool V_213 ;
if ( V_2 -> V_139 <= V_195 )
return false ;
V_211 = F_21 ( F_180 ( V_83 ) ,
( V_83 -> V_214 + V_215 - 1 ) /
V_215 ) ;
V_212 = F_164 ( V_83 ) + V_211 + ( 2UL << V_2 -> V_139 ) ;
V_213 = F_181 ( V_83 , 0 , V_212 , 0 , 0 ) ;
if ( F_182 ( V_83 , V_2 -> V_139 ) )
return V_213 ;
if ( ! F_169 ( V_83 , V_2 -> V_139 ) )
return false ;
return V_213 ;
}
static bool F_183 ( struct V_216 * V_216 , struct V_1 * V_2 )
{
struct V_217 * V_218 ;
struct V_83 * V_83 ;
unsigned long V_219 ;
unsigned long V_220 ;
bool V_221 = false ;
if ( V_170 )
V_2 -> V_102 |= V_222 ;
F_184 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_185 ( V_83 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_186 ( V_83 , V_117 ) )
continue;
if ( V_83 -> V_186 &&
V_2 -> V_110 != V_111 )
continue;
if ( V_194 ) {
if ( F_179 ( V_83 , V_2 ) ) {
V_221 = true ;
continue;
}
}
V_220 = 0 ;
V_219 = F_187 ( V_83 ,
V_2 -> V_139 , V_2 -> V_102 ,
& V_220 ) ;
V_2 -> V_93 += V_219 ;
V_2 -> V_98 += V_220 ;
}
F_175 ( V_83 , V_2 ) ;
}
return V_221 ;
}
static bool F_188 ( struct V_83 * V_83 )
{
return V_83 -> V_155 < F_189 ( V_83 ) * 6 ;
}
static bool V_186 ( struct V_216 * V_216 ,
struct V_1 * V_2 )
{
struct V_217 * V_218 ;
struct V_83 * V_83 ;
F_184 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_185 ( V_83 ) )
continue;
if ( ! F_186 ( V_83 , V_117 ) )
continue;
if ( ! V_83 -> V_186 )
return false ;
}
return true ;
}
static unsigned long F_190 ( struct V_216 * V_216 ,
struct V_1 * V_2 ,
struct V_13 * V_15 )
{
unsigned long V_223 = 0 ;
struct V_224 * V_224 = V_37 -> V_224 ;
struct V_217 * V_218 ;
struct V_83 * V_83 ;
unsigned long V_225 ;
bool V_221 ;
F_191 () ;
if ( F_1 ( V_2 ) )
F_79 ( V_226 ) ;
do {
V_2 -> V_98 = 0 ;
V_221 = F_183 ( V_216 , V_2 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_17 = 0 ;
F_192 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_186 ( V_83 , V_117 ) )
continue;
V_17 += F_189 ( V_83 ) ;
}
F_15 ( V_15 , V_2 -> V_98 , V_17 ) ;
if ( V_224 ) {
V_2 -> V_93 += V_224 -> V_227 ;
V_224 -> V_227 = 0 ;
}
}
V_223 += V_2 -> V_98 ;
if ( V_2 -> V_93 >= V_2 -> V_202 )
goto V_20;
V_225 = V_2 -> V_202 + V_2 -> V_202 / 2 ;
if ( V_223 > V_225 ) {
F_193 ( V_228 ? 0 : V_223 ,
V_229 ) ;
V_2 -> V_113 = 1 ;
}
if ( ! V_2 -> V_230 && V_2 -> V_98 &&
V_2 -> V_110 < V_111 - 2 ) {
struct V_83 * V_231 ;
F_194 ( V_216 , F_195 ( V_2 -> V_102 ) ,
& V_232 ,
& V_231 ) ;
F_146 ( V_231 , V_153 , V_154 / 10 ) ;
}
} while ( -- V_2 -> V_110 >= 0 );
V_20:
F_196 () ;
if ( V_2 -> V_93 )
return V_2 -> V_93 ;
if ( V_233 )
return 0 ;
if ( V_221 )
return 1 ;
if ( F_1 ( V_2 ) && ! V_186 ( V_216 , V_2 ) )
return 1 ;
return 0 ;
}
static bool F_197 ( T_6 * V_234 )
{
struct V_83 * V_83 ;
unsigned long V_235 = 0 ;
unsigned long V_89 = 0 ;
int V_236 ;
bool V_237 ;
for ( V_236 = 0 ; V_236 <= V_238 ; V_236 ++ ) {
V_83 = & V_234 -> V_239 [ V_236 ] ;
V_235 += F_198 ( V_83 ) ;
V_89 += F_5 ( V_83 , V_193 ) ;
}
V_237 = V_89 > V_235 / 2 ;
if ( ! V_237 && F_199 ( & V_234 -> V_240 ) ) {
V_234 -> V_241 = F_21 ( V_234 -> V_241 ,
(enum V_242 ) V_238 ) ;
F_200 ( & V_234 -> V_240 ) ;
}
return V_237 ;
}
static bool F_201 ( T_7 V_102 , struct V_216 * V_216 ,
T_8 * V_243 )
{
struct V_83 * V_83 ;
int V_244 = F_195 ( V_102 ) ;
T_6 * V_234 ;
if ( V_37 -> V_38 & V_245 )
goto V_20;
if ( F_143 ( V_37 ) )
goto V_20;
F_194 ( V_216 , V_244 , NULL , & V_83 ) ;
V_234 = V_83 -> V_161 ;
if ( F_197 ( V_234 ) )
goto V_20;
F_79 ( V_246 ) ;
if ( ! ( V_102 & V_103 ) ) {
F_202 ( V_234 -> V_247 ,
F_197 ( V_234 ) , V_154 ) ;
goto V_248;
}
F_203 ( V_83 -> V_161 -> V_247 ,
F_197 ( V_234 ) ) ;
V_248:
if ( F_143 ( V_37 ) )
return true ;
V_20:
return false ;
}
unsigned long F_204 ( struct V_216 * V_216 , int V_139 ,
T_7 V_102 , T_8 * V_243 )
{
unsigned long V_93 ;
struct V_1 V_2 = {
. V_102 = V_102 ,
. V_113 = ! V_228 ,
. V_202 = V_19 ,
. V_100 = 1 ,
. V_187 = 1 ,
. V_139 = V_139 ,
. V_110 = V_111 ,
. V_3 = NULL ,
. V_243 = V_243 ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
if ( F_201 ( V_102 , V_216 , V_243 ) )
return 1 ;
F_205 ( V_139 ,
V_2 . V_113 ,
V_102 ) ;
V_93 = F_190 ( V_216 , & V_2 , & V_15 ) ;
F_206 ( V_93 ) ;
return V_93 ;
}
unsigned long F_207 ( struct V_206 * V_210 ,
T_7 V_102 , bool V_184 ,
struct V_83 * V_83 ,
unsigned long * V_98 )
{
struct V_1 V_2 = {
. V_98 = 0 ,
. V_202 = V_19 ,
. V_113 = ! V_228 ,
. V_100 = 1 ,
. V_187 = ! V_184 ,
. V_139 = 0 ,
. V_110 = 0 ,
. V_3 = V_210 ,
} ;
struct V_4 * V_4 = F_177 ( V_83 , V_210 ) ;
V_2 . V_102 = ( V_102 & V_249 ) |
( V_250 & ~ V_249 ) ;
F_208 ( V_2 . V_139 ,
V_2 . V_113 ,
V_2 . V_102 ) ;
F_170 ( V_4 , & V_2 ) ;
F_209 ( V_2 . V_93 ) ;
* V_98 = V_2 . V_98 ;
return V_2 . V_93 ;
}
unsigned long F_210 ( struct V_206 * V_210 ,
T_7 V_102 ,
bool V_184 )
{
struct V_216 * V_216 ;
unsigned long V_93 ;
int V_251 ;
struct V_1 V_2 = {
. V_113 = ! V_228 ,
. V_100 = 1 ,
. V_187 = ! V_184 ,
. V_202 = V_19 ,
. V_139 = 0 ,
. V_110 = V_111 ,
. V_3 = V_210 ,
. V_243 = NULL ,
. V_102 = ( V_102 & V_249 ) |
( V_250 & ~ V_249 ) ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
V_251 = F_211 ( V_210 ) ;
V_216 = F_212 ( V_251 ) -> V_252 ;
F_213 ( 0 ,
V_2 . V_113 ,
V_2 . V_102 ) ;
V_93 = F_190 ( V_216 , & V_2 , & V_15 ) ;
F_214 ( V_93 ) ;
return V_93 ;
}
static void F_215 ( struct V_83 * V_83 , struct V_1 * V_2 )
{
struct V_206 * V_210 ;
if ( ! V_174 )
return;
V_210 = F_176 ( NULL , NULL , NULL ) ;
do {
struct V_4 * V_4 = F_177 ( V_83 , V_210 ) ;
if ( F_154 ( V_4 ) )
F_152 ( V_19 , V_4 ,
V_2 , V_189 ) ;
V_210 = F_176 ( NULL , V_210 , NULL ) ;
} while ( V_210 );
}
static bool F_216 ( struct V_83 * V_83 , int V_139 ,
unsigned long V_211 , int V_241 )
{
if ( ! F_181 ( V_83 , V_139 , F_164 ( V_83 ) +
V_211 , V_241 , 0 ) )
return false ;
if ( V_194 && V_139 && ! F_169 ( V_83 , V_139 ) )
return false ;
return true ;
}
static bool F_217 ( T_6 * V_234 , unsigned long V_253 ,
int V_241 )
{
unsigned long V_214 = 0 ;
int V_236 ;
for ( V_236 = 0 ; V_236 <= V_241 ; V_236 ++ )
V_214 += V_234 -> V_239 [ V_236 ] . V_214 ;
return V_253 >= ( V_214 >> 2 ) ;
}
static bool F_218 ( T_6 * V_234 , int V_139 , long V_254 ,
int V_241 )
{
int V_236 ;
unsigned long V_255 = 0 ;
bool V_256 = true ;
if ( V_254 )
return false ;
if ( F_199 ( & V_234 -> V_247 ) ) {
F_219 ( & V_234 -> V_247 ) ;
return false ;
}
for ( V_236 = 0 ; V_236 <= V_241 ; V_236 ++ ) {
struct V_83 * V_83 = V_234 -> V_239 + V_236 ;
if ( ! F_185 ( V_83 ) )
continue;
if ( V_83 -> V_186 ) {
V_255 += V_83 -> V_214 ;
continue;
}
if ( ! F_216 ( V_83 , V_139 , 0 , V_236 ) )
V_256 = false ;
else
V_255 += V_83 -> V_214 ;
}
if ( V_139 )
return F_217 ( V_234 , V_255 , V_241 ) ;
else
return V_256 ;
}
static unsigned long F_220 ( T_6 * V_234 , int V_139 ,
int * V_241 )
{
int V_256 ;
unsigned long V_255 ;
int V_236 ;
int V_257 = 0 ;
unsigned long V_223 ;
struct V_224 * V_224 = V_37 -> V_224 ;
unsigned long V_219 ;
unsigned long V_220 ;
struct V_1 V_2 = {
. V_102 = V_117 ,
. V_100 = 1 ,
. V_187 = 1 ,
. V_202 = V_258 ,
. V_139 = V_139 ,
. V_3 = NULL ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
V_259:
V_223 = 0 ;
V_2 . V_110 = V_111 ;
V_2 . V_93 = 0 ;
V_2 . V_113 = ! V_228 ;
F_79 ( V_260 ) ;
do {
unsigned long V_17 = 0 ;
int V_261 = 0 ;
V_256 = 1 ;
V_255 = 0 ;
for ( V_236 = V_234 -> V_262 - 1 ; V_236 >= 0 ; V_236 -- ) {
struct V_83 * V_83 = V_234 -> V_239 + V_236 ;
if ( ! F_185 ( V_83 ) )
continue;
if ( V_83 -> V_186 &&
V_2 . V_110 != V_111 )
continue;
F_215 ( V_83 , & V_2 ) ;
if ( V_170 && F_221 ( V_236 ) ) {
V_257 = V_236 ;
break;
}
if ( ! F_216 ( V_83 , V_139 , 0 , 0 ) ) {
V_257 = V_236 ;
break;
} else {
F_222 ( V_83 , V_115 ) ;
}
}
if ( V_236 < 0 )
goto V_20;
for ( V_236 = 0 ; V_236 <= V_257 ; V_236 ++ ) {
struct V_83 * V_83 = V_234 -> V_239 + V_236 ;
V_17 += F_189 ( V_83 ) ;
}
for ( V_236 = 0 ; V_236 <= V_257 ; V_236 ++ ) {
struct V_83 * V_83 = V_234 -> V_239 + V_236 ;
int V_263 , V_264 ;
unsigned long V_211 ;
if ( ! F_185 ( V_83 ) )
continue;
if ( V_83 -> V_186 &&
V_2 . V_110 != V_111 )
continue;
V_2 . V_98 = 0 ;
V_220 = 0 ;
V_219 = F_187 ( V_83 ,
V_139 , V_2 . V_102 ,
& V_220 ) ;
V_2 . V_93 += V_219 ;
V_223 += V_220 ;
V_211 = F_21 ( F_180 ( V_83 ) ,
( V_83 -> V_214 +
V_215 - 1 ) /
V_215 ) ;
V_264 = V_139 ;
if ( V_194 && V_139 &&
F_169 ( V_83 , V_139 ) !=
V_265 )
V_264 = 0 ;
if ( ( V_170 && F_221 ( V_236 ) ) ||
! F_216 ( V_83 , V_264 ,
V_211 , V_257 ) ) {
F_175 ( V_83 , & V_2 ) ;
V_224 -> V_227 = 0 ;
V_263 = F_15 ( & V_15 , V_2 . V_98 , V_17 ) ;
V_2 . V_93 += V_224 -> V_227 ;
V_223 += V_2 . V_98 ;
if ( V_263 == 0 && ! F_188 ( V_83 ) )
V_83 -> V_186 = 1 ;
}
if ( V_223 > V_19 * 2 &&
V_223 > V_2 . V_93 + V_2 . V_93 / 2 )
V_2 . V_113 = 1 ;
if ( V_83 -> V_186 ) {
if ( V_257 && V_257 == V_236 )
V_257 -- ;
continue;
}
if ( ! F_216 ( V_83 , V_264 , 0 , V_257 ) ) {
V_256 = 0 ;
if ( ! F_181 ( V_83 , V_139 ,
F_198 ( V_83 ) , V_257 , 0 ) )
V_261 = 1 ;
} else {
F_222 ( V_83 , V_115 ) ;
if ( V_236 <= * V_241 )
V_255 += V_83 -> V_214 ;
}
}
if ( F_199 ( & V_234 -> V_247 ) &&
F_197 ( V_234 ) )
F_219 ( & V_234 -> V_247 ) ;
if ( V_256 || ( V_139 && F_217 ( V_234 , V_255 , * V_241 ) ) )
break;
if ( V_223 && ( V_2 . V_110 < V_111 - 2 ) ) {
if ( V_261 )
F_79 ( V_266 ) ;
else
F_142 ( V_153 , V_154 / 10 ) ;
}
if ( V_2 . V_93 >= V_19 )
break;
} while ( -- V_2 . V_110 >= 0 );
V_20:
if ( ! ( V_256 || ( V_139 && F_217 ( V_234 , V_255 , * V_241 ) ) ) ) {
F_24 () ;
F_223 () ;
if ( V_2 . V_93 < V_19 )
V_139 = V_2 . V_139 = 0 ;
goto V_259;
}
if ( V_139 ) {
int V_267 = 1 ;
for ( V_236 = 0 ; V_236 <= V_257 ; V_236 ++ ) {
struct V_83 * V_83 = V_234 -> V_239 + V_236 ;
if ( ! F_185 ( V_83 ) )
continue;
if ( F_224 ( V_83 , V_139 ,
F_180 ( V_83 ) , * V_241 , 0 ) )
V_267 = 0 ;
}
if ( V_267 )
F_225 ( V_234 , V_139 ) ;
}
* V_241 = V_257 ;
return V_139 ;
}
static void F_226 ( T_6 * V_234 , int V_139 , int V_241 )
{
long V_254 = 0 ;
F_227 ( V_268 ) ;
if ( F_228 ( V_37 ) || F_229 () )
return;
F_230 ( & V_234 -> V_240 , & V_268 , V_269 ) ;
if ( F_218 ( V_234 , V_139 , V_254 , V_241 ) ) {
V_254 = F_231 ( V_154 / 10 ) ;
F_232 ( & V_234 -> V_240 , & V_268 ) ;
F_230 ( & V_234 -> V_240 , & V_268 , V_269 ) ;
}
if ( F_218 ( V_234 , V_139 , V_254 , V_241 ) ) {
F_233 ( V_234 -> V_162 ) ;
F_234 ( V_234 , V_270 ) ;
F_235 ( V_234 ) ;
if ( ! F_229 () )
F_236 () ;
F_234 ( V_234 , V_271 ) ;
} else {
if ( V_254 )
F_79 ( V_272 ) ;
else
F_79 ( V_273 ) ;
}
F_232 ( & V_234 -> V_240 , & V_268 ) ;
}
static int F_237 ( void * V_274 )
{
unsigned long V_139 , V_275 ;
unsigned V_276 ;
int V_241 , V_277 ;
int V_278 ;
T_6 * V_234 = ( T_6 * ) V_274 ;
struct V_279 * V_280 = V_37 ;
struct V_224 V_224 = {
. V_227 = 0 ,
} ;
const struct V_281 * V_281 = F_238 ( V_234 -> V_162 ) ;
F_239 ( V_117 ) ;
if ( ! F_240 ( V_281 ) )
F_241 ( V_280 , V_281 ) ;
V_37 -> V_224 = & V_224 ;
V_280 -> V_38 |= V_282 | V_39 | V_283 ;
F_242 () ;
V_139 = V_275 = 0 ;
V_276 = 0 ;
V_241 = V_277 = V_234 -> V_262 - 1 ;
V_278 = V_241 ;
for ( ; ; ) {
int V_18 ;
if ( V_278 >= V_277 &&
V_276 == V_275 ) {
V_275 = V_234 -> V_284 ;
V_277 = V_234 -> V_241 ;
V_234 -> V_284 = 0 ;
V_234 -> V_241 = V_234 -> V_262 - 1 ;
}
if ( V_139 < V_275 || V_241 > V_277 ) {
V_139 = V_275 ;
V_241 = V_277 ;
} else {
F_226 ( V_234 , V_276 ,
V_278 ) ;
V_139 = V_234 -> V_284 ;
V_241 = V_234 -> V_241 ;
V_275 = V_139 ;
V_277 = V_241 ;
V_234 -> V_284 = 0 ;
V_234 -> V_241 = V_234 -> V_262 - 1 ;
}
V_18 = F_223 () ;
if ( F_229 () )
break;
if ( ! V_18 ) {
F_243 ( V_234 -> V_162 , V_139 ) ;
V_278 = V_241 ;
V_276 = F_220 ( V_234 , V_139 ,
& V_278 ) ;
}
}
V_37 -> V_224 = NULL ;
return 0 ;
}
void F_244 ( struct V_83 * V_83 , int V_139 , enum V_242 V_241 )
{
T_6 * V_234 ;
if ( ! F_185 ( V_83 ) )
return;
if ( ! F_186 ( V_83 , V_117 ) )
return;
V_234 = V_83 -> V_161 ;
if ( V_234 -> V_284 < V_139 ) {
V_234 -> V_284 = V_139 ;
V_234 -> V_241 = F_21 ( V_234 -> V_241 , V_241 ) ;
}
if ( ! F_199 ( & V_234 -> V_240 ) )
return;
if ( F_181 ( V_83 , V_139 , F_180 ( V_83 ) , 0 , 0 ) )
return;
F_245 ( V_234 -> V_162 , F_148 ( V_83 ) , V_139 ) ;
F_200 ( & V_234 -> V_240 ) ;
}
unsigned long F_246 ( void )
{
int V_25 ;
V_25 = F_247 ( V_175 ) +
F_247 ( V_144 ) ;
if ( V_188 > 0 )
V_25 += F_247 ( V_172 ) +
F_247 ( V_145 ) ;
return V_25 ;
}
unsigned long F_189 ( struct V_83 * V_83 )
{
int V_25 ;
V_25 = F_5 ( V_83 , V_175 ) +
F_5 ( V_83 , V_144 ) ;
if ( V_188 > 0 )
V_25 += F_5 ( V_83 , V_172 ) +
F_5 ( V_83 , V_145 ) ;
return V_25 ;
}
unsigned long F_248 ( unsigned long V_202 )
{
struct V_224 V_224 ;
struct V_1 V_2 = {
. V_102 = V_250 ,
. V_187 = 1 ,
. V_100 = 1 ,
. V_113 = 1 ,
. V_202 = V_202 ,
. V_230 = 1 ,
. V_139 = 0 ,
. V_110 = V_111 ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
struct V_216 * V_216 = F_249 ( F_250 () , V_2 . V_102 ) ;
struct V_279 * V_274 = V_37 ;
unsigned long V_93 ;
V_274 -> V_38 |= V_282 ;
F_239 ( V_2 . V_102 ) ;
V_224 . V_227 = 0 ;
V_274 -> V_224 = & V_224 ;
V_93 = F_190 ( V_216 , & V_2 , & V_15 ) ;
V_274 -> V_224 = NULL ;
F_251 () ;
V_274 -> V_38 &= ~ V_282 ;
return V_93 ;
}
static int T_9 F_252 ( struct V_285 * V_286 ,
unsigned long V_287 , void * V_288 )
{
int V_251 ;
if ( V_287 == V_289 || V_287 == V_290 ) {
F_253 (nid, N_HIGH_MEMORY) {
T_6 * V_234 = F_212 ( V_251 ) ;
const struct V_281 * V_291 ;
V_291 = F_238 ( V_234 -> V_162 ) ;
if ( F_254 ( V_292 , V_291 ) < V_293 )
F_241 ( V_234 -> F_237 , V_291 ) ;
}
}
return V_294 ;
}
int F_255 ( int V_251 )
{
T_6 * V_234 = F_212 ( V_251 ) ;
int V_18 = 0 ;
if ( V_234 -> F_237 )
return 0 ;
V_234 -> F_237 = F_256 ( F_237 , V_234 , L_4 , V_251 ) ;
if ( F_257 ( V_234 -> F_237 ) ) {
F_50 ( V_295 == V_296 ) ;
V_234 -> F_237 = NULL ;
F_258 ( L_5 , V_251 ) ;
V_18 = F_259 ( V_234 -> F_237 ) ;
}
return V_18 ;
}
void F_260 ( int V_251 )
{
struct V_279 * F_237 = F_212 ( V_251 ) -> F_237 ;
if ( F_237 ) {
F_261 ( F_237 ) ;
F_212 ( V_251 ) -> F_237 = NULL ;
}
}
static int T_10 F_262 ( void )
{
int V_251 ;
F_263 () ;
F_253 (nid, N_HIGH_MEMORY)
F_255 ( V_251 ) ;
F_264 ( F_252 , 0 ) ;
return 0 ;
}
static inline unsigned long F_265 ( struct V_83 * V_83 )
{
unsigned long V_297 = F_5 ( V_83 , V_298 ) ;
unsigned long V_299 = F_5 ( V_83 , V_144 ) +
F_5 ( V_83 , V_175 ) ;
return ( V_299 > V_297 ) ? ( V_299 - V_297 ) : 0 ;
}
static long F_266 ( struct V_83 * V_83 )
{
long V_300 ;
long V_21 = 0 ;
if ( V_301 & V_302 )
V_300 = F_5 ( V_83 , V_303 ) ;
else
V_300 = F_265 ( V_83 ) ;
if ( ! ( V_301 & V_304 ) )
V_21 += F_5 ( V_83 , V_305 ) ;
if ( F_54 ( V_21 > V_300 ) )
V_21 = V_300 ;
return V_300 - V_21 ;
}
static int F_267 ( struct V_83 * V_83 , T_7 V_102 , unsigned int V_139 )
{
const unsigned long V_138 = 1 << V_139 ;
struct V_279 * V_274 = V_37 ;
struct V_224 V_224 ;
struct V_1 V_2 = {
. V_113 = ! ! ( V_301 & V_304 ) ,
. V_100 = ! ! ( V_301 & V_302 ) ,
. V_187 = 1 ,
. V_202 = F_268 (unsigned long, nr_pages,
SWAP_CLUSTER_MAX) ,
. V_102 = V_102 ,
. V_139 = V_139 ,
. V_110 = V_306 ,
} ;
struct V_13 V_15 = {
. V_102 = V_2 . V_102 ,
} ;
unsigned long V_307 , V_308 ;
F_24 () ;
V_274 -> V_38 |= V_282 | V_39 ;
F_239 ( V_102 ) ;
V_224 . V_227 = 0 ;
V_274 -> V_224 = & V_224 ;
if ( F_266 ( V_83 ) > V_83 -> V_309 ) {
do {
F_175 ( V_83 , & V_2 ) ;
} while ( V_2 . V_93 < V_138 && -- V_2 . V_110 >= 0 );
}
V_307 = F_5 ( V_83 , V_310 ) ;
if ( V_307 > V_83 -> V_311 ) {
for (; ; ) {
unsigned long V_17 = F_189 ( V_83 ) ;
if ( ! F_15 ( & V_15 , V_2 . V_98 , V_17 ) )
break;
V_308 = F_5 ( V_83 ,
V_310 ) ;
if ( V_308 + V_138 <= V_307 )
break;
}
V_308 = F_5 ( V_83 , V_310 ) ;
if ( V_308 < V_307 )
V_2 . V_93 += V_307 - V_308 ;
}
V_274 -> V_224 = NULL ;
V_37 -> V_38 &= ~ ( V_282 | V_39 ) ;
F_251 () ;
return V_2 . V_93 >= V_138 ;
}
int F_269 ( struct V_83 * V_83 , T_7 V_102 , unsigned int V_139 )
{
int V_162 ;
int V_18 ;
if ( F_266 ( V_83 ) <= V_83 -> V_309 &&
F_5 ( V_83 , V_310 ) <= V_83 -> V_311 )
return V_312 ;
if ( V_83 -> V_186 )
return V_312 ;
if ( ! ( V_102 & V_313 ) || ( V_37 -> V_38 & V_282 ) )
return V_314 ;
V_162 = F_270 ( V_83 ) ;
if ( F_271 ( V_162 , V_315 ) && V_162 != F_250 () )
return V_314 ;
if ( F_272 ( V_83 , V_316 ) )
return V_314 ;
V_18 = F_267 ( V_83 , V_102 , V_139 ) ;
F_222 ( V_83 , V_316 ) ;
if ( ! V_18 )
F_79 ( V_317 ) ;
return V_18 ;
}
int F_72 ( struct V_34 * V_34 )
{
return ! F_273 ( F_36 ( V_34 ) ) && ! F_274 ( V_34 ) ;
}
void F_275 ( struct V_34 * * V_318 , int V_138 )
{
struct V_4 * V_4 ;
struct V_83 * V_83 = NULL ;
int V_319 = 0 ;
int V_320 = 0 ;
int V_236 ;
for ( V_236 = 0 ; V_236 < V_138 ; V_236 ++ ) {
struct V_34 * V_34 = V_318 [ V_236 ] ;
struct V_83 * V_321 ;
V_319 ++ ;
V_321 = F_92 ( V_34 ) ;
if ( V_321 != V_83 ) {
if ( V_83 )
F_60 ( & V_83 -> V_140 ) ;
V_83 = V_321 ;
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
V_320 ++ ;
}
}
if ( V_83 ) {
F_151 ( V_69 , V_320 ) ;
F_151 ( V_322 , V_319 ) ;
F_60 ( & V_83 -> V_140 ) ;
}
}
static void F_276 ( void )
{
F_277 ( V_323
L_6
L_7
L_8 ,
V_37 -> V_324 ) ;
}
int F_278 ( struct V_325 * V_326 , int V_327 ,
void T_11 * V_328 ,
T_12 * V_329 , T_13 * V_330 )
{
F_276 () ;
F_279 ( V_326 , V_327 , V_328 , V_329 , V_330 ) ;
V_331 = 0 ;
return 0 ;
}
static T_14 F_280 ( struct V_332 * V_333 ,
struct V_334 * V_335 ,
char * V_336 )
{
F_276 () ;
return sprintf ( V_336 , L_9 ) ;
}
static T_14 F_281 ( struct V_332 * V_333 ,
struct V_334 * V_335 ,
const char * V_336 , T_12 V_337 )
{
F_276 () ;
return 1 ;
}
int F_282 ( struct V_338 * V_338 )
{
return F_283 ( & V_338 -> V_333 , & V_339 ) ;
}
void F_284 ( struct V_338 * V_338 )
{
F_285 ( & V_338 -> V_333 , & V_339 ) ;
}
