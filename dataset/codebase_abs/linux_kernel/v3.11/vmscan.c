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
int V_65 = F_67 ( V_34 ) ;
F_68 ( F_69 ( V_34 ) ) ;
V_66:
F_70 ( V_34 ) ;
if ( F_71 ( V_34 ) ) {
V_6 = F_72 ( V_34 ) ;
F_73 ( V_34 ) ;
} else {
V_6 = V_67 ;
F_74 ( V_34 ) ;
F_75 () ;
}
if ( V_6 == V_67 && F_71 ( V_34 ) ) {
if ( ! F_76 ( V_34 ) ) {
F_77 ( V_34 ) ;
goto V_66;
}
}
if ( V_65 && V_6 != V_67 )
F_78 ( V_68 ) ;
else if ( ! V_65 && V_6 == V_67 )
F_78 ( V_69 ) ;
F_77 ( V_34 ) ;
}
static enum V_70 F_79 ( struct V_34 * V_34 ,
struct V_1 * V_2 )
{
int V_71 , V_72 ;
unsigned long V_73 ;
V_71 = F_80 ( V_34 , 1 , V_2 -> V_3 ,
& V_73 ) ;
V_72 = F_81 ( V_34 ) ;
if ( V_73 & V_74 )
return V_75 ;
if ( V_71 ) {
if ( F_82 ( V_34 ) )
return V_76 ;
F_83 ( V_34 ) ;
if ( V_72 || V_71 > 1 )
return V_76 ;
if ( V_73 & V_77 )
return V_76 ;
return V_78 ;
}
if ( V_72 && ! F_82 ( V_34 ) )
return V_79 ;
return V_75 ;
}
static void F_84 ( struct V_34 * V_34 ,
bool * V_80 , bool * V_81 )
{
struct V_40 * V_41 ;
if ( ! F_85 ( V_34 ) ) {
* V_80 = false ;
* V_81 = false ;
return;
}
* V_80 = F_55 ( V_34 ) ;
* V_81 = F_45 ( V_34 ) ;
if ( ! F_31 ( V_34 ) )
return;
V_41 = F_36 ( V_34 ) ;
if ( V_41 && V_41 -> V_45 -> V_82 )
V_41 -> V_45 -> V_82 ( V_34 , V_80 , V_81 ) ;
}
static unsigned long F_86 ( struct V_83 * V_84 ,
struct V_85 * V_85 ,
struct V_1 * V_2 ,
enum V_86 V_86 ,
unsigned long * V_87 ,
unsigned long * V_88 ,
unsigned long * V_89 ,
unsigned long * V_90 ,
unsigned long * V_91 ,
bool V_92 )
{
F_87 ( V_93 ) ;
F_87 ( V_94 ) ;
int V_95 = 0 ;
unsigned long V_96 = 0 ;
unsigned long V_97 = 0 ;
unsigned long V_98 = 0 ;
unsigned long V_99 = 0 ;
unsigned long V_100 = 0 ;
unsigned long V_101 = 0 ;
F_24 () ;
F_88 () ;
while ( ! F_89 ( V_84 ) ) {
struct V_40 * V_41 ;
struct V_34 * V_34 ;
int V_102 ;
enum V_70 V_103 = V_79 ;
bool V_80 , V_81 ;
F_24 () ;
V_34 = F_90 ( V_84 ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( ! F_91 ( V_34 ) )
goto V_104;
F_68 ( F_92 ( V_34 ) ) ;
F_68 ( F_93 ( V_34 ) != V_85 ) ;
V_2 -> V_105 ++ ;
if ( F_54 ( ! F_71 ( V_34 ) ) )
goto V_106;
if ( ! V_2 -> V_107 && F_94 ( V_34 ) )
goto V_108;
if ( F_94 ( V_34 ) || F_57 ( V_34 ) )
V_2 -> V_105 ++ ;
V_102 = ( V_2 -> V_109 & V_110 ) ||
( F_57 ( V_34 ) && ( V_2 -> V_109 & V_111 ) ) ;
F_84 ( V_34 , & V_80 , & V_81 ) ;
if ( V_80 || V_81 )
V_97 ++ ;
if ( V_80 && ! V_81 )
V_96 ++ ;
V_41 = F_36 ( V_34 ) ;
if ( ( V_41 && F_33 ( V_41 -> V_35 ) ) ||
( V_81 && F_95 ( V_34 ) ) )
V_98 ++ ;
if ( F_45 ( V_34 ) ) {
if ( F_96 () &&
F_95 ( V_34 ) &&
F_97 ( V_85 ) ) {
V_101 ++ ;
goto V_108;
} else if ( F_1 ( V_2 ) ||
! F_95 ( V_34 ) || ! ( V_2 -> V_109 & V_111 ) ) {
F_43 ( V_34 ) ;
V_100 ++ ;
goto V_108;
} else {
F_98 ( V_34 ) ;
}
}
if ( ! V_92 )
V_103 = F_79 ( V_34 , V_2 ) ;
switch ( V_103 ) {
case V_76 :
goto V_112;
case V_78 :
goto V_108;
case V_75 :
case V_79 :
;
}
if ( F_99 ( V_34 ) && ! F_57 ( V_34 ) ) {
if ( ! ( V_2 -> V_109 & V_111 ) )
goto V_108;
if ( ! F_100 ( V_34 , V_84 ) )
goto V_112;
V_102 = 1 ;
V_41 = F_36 ( V_34 ) ;
}
if ( F_94 ( V_34 ) && V_41 ) {
switch ( F_101 ( V_34 , V_86 ) ) {
case V_113 :
goto V_112;
case V_114 :
goto V_108;
case V_115 :
goto V_106;
case V_116 :
;
}
}
if ( F_55 ( V_34 ) ) {
if ( F_85 ( V_34 ) &&
( ! F_96 () ||
! F_102 ( V_85 ) ) ) {
F_48 ( V_34 , V_117 ) ;
F_43 ( V_34 ) ;
goto V_108;
}
if ( V_103 == V_79 )
goto V_108;
if ( ! V_102 )
goto V_108;
if ( ! V_2 -> V_118 )
goto V_108;
switch ( F_39 ( V_34 , V_41 , V_2 ) ) {
case V_42 :
goto V_108;
case V_47 :
goto V_112;
case V_60 :
if ( F_45 ( V_34 ) )
goto V_104;
if ( F_55 ( V_34 ) )
goto V_104;
if ( ! F_91 ( V_34 ) )
goto V_104;
if ( F_55 ( V_34 ) || F_45 ( V_34 ) )
goto V_108;
V_41 = F_36 ( V_34 ) ;
case V_44 :
;
}
}
if ( F_31 ( V_34 ) ) {
if ( ! F_103 ( V_34 , V_2 -> V_109 ) )
goto V_112;
if ( ! V_41 && F_30 ( V_34 ) == 1 ) {
F_38 ( V_34 ) ;
if ( F_104 ( V_34 ) )
goto V_119;
else {
V_99 ++ ;
continue;
}
}
}
if ( ! V_41 || ! F_49 ( V_41 , V_34 ) )
goto V_108;
F_105 ( V_34 ) ;
V_119:
V_99 ++ ;
F_106 ( & V_34 -> V_6 , & V_94 ) ;
continue;
V_106:
if ( F_57 ( V_34 ) )
F_107 ( V_34 ) ;
F_38 ( V_34 ) ;
F_66 ( V_34 ) ;
continue;
V_112:
if ( F_57 ( V_34 ) && F_108 () )
F_107 ( V_34 ) ;
F_68 ( F_92 ( V_34 ) ) ;
F_109 ( V_34 ) ;
V_95 ++ ;
V_108:
F_38 ( V_34 ) ;
V_104:
F_106 ( & V_34 -> V_6 , & V_93 ) ;
F_68 ( F_69 ( V_34 ) || F_67 ( V_34 ) ) ;
}
F_110 ( & V_94 , 1 ) ;
F_111 ( & V_93 , V_84 ) ;
F_23 ( V_120 , V_95 ) ;
F_112 () ;
* V_87 += V_97 ;
* V_89 += V_98 ;
* V_88 += V_96 ;
* V_90 += V_100 ;
* V_91 += V_101 ;
return V_99 ;
}
unsigned long F_113 ( struct V_85 * V_85 ,
struct V_83 * V_84 )
{
struct V_1 V_2 = {
. V_109 = V_121 ,
. V_122 = V_123 ,
. V_107 = 1 ,
} ;
unsigned long V_18 , V_124 , V_125 , V_126 , V_127 , V_128 ;
struct V_34 * V_34 , * V_129 ;
F_87 ( V_130 ) ;
F_114 (page, next, page_list, lru) {
if ( F_85 ( V_34 ) && ! F_55 ( V_34 ) ) {
F_115 ( V_34 ) ;
F_116 ( & V_34 -> V_6 , & V_130 ) ;
}
}
V_18 = F_86 ( & V_130 , V_85 , & V_2 ,
V_131 | V_132 ,
& V_124 , & V_125 , & V_126 , & V_127 , & V_128 , true ) ;
F_111 ( & V_130 , V_84 ) ;
F_117 ( V_85 , V_133 , - V_18 ) ;
return V_18 ;
}
int F_118 ( struct V_34 * V_34 , T_3 V_134 )
{
int V_18 = - V_135 ;
if ( ! F_69 ( V_34 ) )
return V_18 ;
if ( F_67 ( V_34 ) && ! ( V_134 & V_136 ) )
return V_18 ;
V_18 = - V_137 ;
if ( V_134 & ( V_138 | V_139 ) ) {
if ( F_45 ( V_34 ) )
return V_18 ;
if ( F_55 ( V_34 ) ) {
struct V_40 * V_41 ;
if ( V_134 & V_138 )
return V_18 ;
V_41 = F_36 ( V_34 ) ;
if ( V_41 && ! V_41 -> V_45 -> V_140 )
return V_18 ;
}
}
if ( ( V_134 & V_141 ) && F_94 ( V_34 ) )
return V_18 ;
if ( F_119 ( F_120 ( V_34 ) ) ) {
F_121 ( V_34 ) ;
V_18 = 0 ;
}
return V_18 ;
}
static unsigned long F_122 ( unsigned long V_14 ,
struct V_4 * V_4 , struct V_83 * V_142 ,
unsigned long * V_105 , struct V_1 * V_2 ,
T_3 V_134 , enum V_5 V_6 )
{
struct V_83 * V_143 = & V_4 -> V_144 [ V_6 ] ;
unsigned long V_145 = 0 ;
unsigned long V_146 ;
for ( V_146 = 0 ; V_146 < V_14 && ! F_89 ( V_143 ) ; V_146 ++ ) {
struct V_34 * V_34 ;
int V_147 ;
V_34 = F_90 ( V_143 ) ;
F_123 ( V_34 , V_143 , V_38 ) ;
F_68 ( ! F_69 ( V_34 ) ) ;
switch ( F_118 ( V_34 , V_134 ) ) {
case 0 :
V_147 = F_124 ( V_34 ) ;
F_125 ( V_4 , V_6 , - V_147 ) ;
F_116 ( & V_34 -> V_6 , V_142 ) ;
V_145 += V_147 ;
break;
case - V_137 :
F_116 ( & V_34 -> V_6 , V_143 ) ;
continue;
default:
F_126 () ;
}
}
* V_105 = V_146 ;
F_127 ( V_2 -> V_148 , V_14 , V_146 ,
V_145 , V_134 , F_128 ( V_6 ) ) ;
return V_145 ;
}
int F_76 ( struct V_34 * V_34 )
{
int V_18 = - V_137 ;
F_68 ( ! F_30 ( V_34 ) ) ;
if ( F_69 ( V_34 ) ) {
struct V_85 * V_85 = F_93 ( V_34 ) ;
struct V_4 * V_4 ;
F_52 ( & V_85 -> V_149 ) ;
V_4 = F_129 ( V_34 , V_85 ) ;
if ( F_69 ( V_34 ) ) {
int V_6 = F_130 ( V_34 ) ;
F_131 ( V_34 ) ;
F_121 ( V_34 ) ;
F_132 ( V_34 , V_4 , V_6 ) ;
V_18 = 0 ;
}
F_60 ( & V_85 -> V_149 ) ;
}
return V_18 ;
}
static int F_133 ( struct V_85 * V_85 , int V_150 ,
struct V_1 * V_2 )
{
unsigned long V_151 , V_152 ;
if ( F_96 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_150 ) {
V_151 = F_5 ( V_85 , V_153 ) ;
V_152 = F_5 ( V_85 , V_133 ) ;
} else {
V_151 = F_5 ( V_85 , V_154 ) ;
V_152 = F_5 ( V_85 , V_155 ) ;
}
if ( ( V_2 -> V_109 & V_156 ) == V_156 )
V_151 >>= 3 ;
return V_152 > V_151 ;
}
static T_4 void
F_134 ( struct V_4 * V_4 , struct V_83 * V_84 )
{
struct V_157 * V_158 = & V_4 -> V_158 ;
struct V_85 * V_85 = F_6 ( V_4 ) ;
F_87 ( V_159 ) ;
while ( ! F_89 ( V_84 ) ) {
struct V_34 * V_34 = F_90 ( V_84 ) ;
int V_6 ;
F_68 ( F_69 ( V_34 ) ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( F_54 ( ! F_71 ( V_34 ) ) ) {
F_60 ( & V_85 -> V_149 ) ;
F_66 ( V_34 ) ;
F_52 ( & V_85 -> V_149 ) ;
continue;
}
V_4 = F_129 ( V_34 , V_85 ) ;
F_135 ( V_34 ) ;
V_6 = F_130 ( V_34 ) ;
F_136 ( V_34 , V_4 , V_6 ) ;
if ( F_137 ( V_6 ) ) {
int V_150 = F_128 ( V_6 ) ;
int V_160 = F_124 ( V_34 ) ;
V_158 -> V_161 [ V_150 ] += V_160 ;
}
if ( F_104 ( V_34 ) ) {
F_138 ( V_34 ) ;
F_139 ( V_34 ) ;
F_132 ( V_34 , V_4 , V_6 ) ;
if ( F_54 ( F_140 ( V_34 ) ) ) {
F_60 ( & V_85 -> V_149 ) ;
( * F_141 ( V_34 ) ) ( V_34 ) ;
F_52 ( & V_85 -> V_149 ) ;
} else
F_106 ( & V_34 -> V_6 , & V_159 ) ;
}
}
F_111 ( & V_159 , V_84 ) ;
}
static T_4 unsigned long
F_142 ( unsigned long V_14 , struct V_4 * V_4 ,
struct V_1 * V_2 , enum V_5 V_6 )
{
F_87 ( V_84 ) ;
unsigned long V_105 ;
unsigned long V_99 = 0 ;
unsigned long V_145 ;
unsigned long V_97 = 0 ;
unsigned long V_98 = 0 ;
unsigned long V_96 = 0 ;
unsigned long V_100 = 0 ;
unsigned long V_101 = 0 ;
T_3 V_162 = 0 ;
int V_150 = F_128 ( V_6 ) ;
struct V_85 * V_85 = F_6 ( V_4 ) ;
struct V_157 * V_158 = & V_4 -> V_158 ;
while ( F_54 ( F_133 ( V_85 , V_150 , V_2 ) ) ) {
F_143 ( V_163 , V_164 / 10 ) ;
if ( F_144 ( V_37 ) )
return V_19 ;
}
F_145 () ;
if ( ! V_2 -> V_107 )
V_162 |= V_141 ;
if ( ! V_2 -> V_118 )
V_162 |= V_138 ;
F_52 ( & V_85 -> V_149 ) ;
V_145 = F_122 ( V_14 , V_4 , & V_84 ,
& V_105 , V_2 , V_162 , V_6 ) ;
F_117 ( V_85 , V_7 + V_6 , - V_145 ) ;
F_117 ( V_85 , V_155 + V_150 , V_145 ) ;
if ( F_1 ( V_2 ) ) {
V_85 -> V_165 += V_105 ;
if ( F_96 () )
F_146 ( V_166 , V_85 , V_105 ) ;
else
F_146 ( V_167 , V_85 , V_105 ) ;
}
F_60 ( & V_85 -> V_149 ) ;
if ( V_145 == 0 )
return 0 ;
V_99 = F_86 ( & V_84 , V_85 , V_2 , V_131 ,
& V_97 , & V_96 , & V_98 ,
& V_100 , & V_101 ,
false ) ;
F_52 ( & V_85 -> V_149 ) ;
V_158 -> V_168 [ V_150 ] += V_145 ;
if ( F_1 ( V_2 ) ) {
if ( F_96 () )
F_146 ( V_169 , V_85 ,
V_99 ) ;
else
F_146 ( V_170 , V_85 ,
V_99 ) ;
}
F_134 ( V_4 , & V_84 ) ;
F_117 ( V_85 , V_155 + V_150 , - V_145 ) ;
F_60 ( & V_85 -> V_149 ) ;
F_110 ( & V_84 , 1 ) ;
if ( V_100 && V_100 == V_145 )
F_147 ( V_85 , V_171 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_97 && V_97 == V_98 )
F_147 ( V_85 , V_172 ) ;
if ( V_96 == V_145 )
F_147 ( V_85 , V_173 ) ;
if ( V_96 == V_145 || V_101 )
F_143 ( V_163 , V_164 / 10 ) ;
}
if ( ! V_2 -> V_174 && ! F_96 () )
F_148 ( V_85 , V_163 , V_164 / 10 ) ;
F_149 ( V_85 -> V_175 -> V_176 ,
F_150 ( V_85 ) ,
V_105 , V_99 ,
V_2 -> V_122 ,
F_151 ( V_150 ) ) ;
return V_99 ;
}
static void F_152 ( struct V_4 * V_4 ,
struct V_83 * V_11 ,
struct V_83 * V_159 ,
enum V_5 V_6 )
{
struct V_85 * V_85 = F_6 ( V_4 ) ;
unsigned long V_177 = 0 ;
struct V_34 * V_34 ;
int V_147 ;
while ( ! F_89 ( V_11 ) ) {
V_34 = F_90 ( V_11 ) ;
V_4 = F_129 ( V_34 , V_85 ) ;
F_68 ( F_69 ( V_34 ) ) ;
F_135 ( V_34 ) ;
V_147 = F_124 ( V_34 ) ;
F_125 ( V_4 , V_6 , V_147 ) ;
F_116 ( & V_34 -> V_6 , & V_4 -> V_144 [ V_6 ] ) ;
V_177 += V_147 ;
if ( F_104 ( V_34 ) ) {
F_138 ( V_34 ) ;
F_139 ( V_34 ) ;
F_132 ( V_34 , V_4 , V_6 ) ;
if ( F_54 ( F_140 ( V_34 ) ) ) {
F_60 ( & V_85 -> V_149 ) ;
( * F_141 ( V_34 ) ) ( V_34 ) ;
F_52 ( & V_85 -> V_149 ) ;
} else
F_106 ( & V_34 -> V_6 , V_159 ) ;
}
}
F_117 ( V_85 , V_7 + V_6 , V_177 ) ;
if ( ! F_137 ( V_6 ) )
F_153 ( V_178 , V_177 ) ;
}
static void F_154 ( unsigned long V_14 ,
struct V_4 * V_4 ,
struct V_1 * V_2 ,
enum V_5 V_6 )
{
unsigned long V_145 ;
unsigned long V_105 ;
unsigned long V_73 ;
F_87 ( V_179 ) ;
F_87 ( V_180 ) ;
F_87 ( V_181 ) ;
struct V_34 * V_34 ;
struct V_157 * V_158 = & V_4 -> V_158 ;
unsigned long V_182 = 0 ;
T_3 V_162 = 0 ;
int V_150 = F_128 ( V_6 ) ;
struct V_85 * V_85 = F_6 ( V_4 ) ;
F_145 () ;
if ( ! V_2 -> V_107 )
V_162 |= V_141 ;
if ( ! V_2 -> V_118 )
V_162 |= V_138 ;
F_52 ( & V_85 -> V_149 ) ;
V_145 = F_122 ( V_14 , V_4 , & V_179 ,
& V_105 , V_2 , V_162 , V_6 ) ;
if ( F_1 ( V_2 ) )
V_85 -> V_165 += V_105 ;
V_158 -> V_168 [ V_150 ] += V_145 ;
F_146 ( V_183 , V_85 , V_105 ) ;
F_117 ( V_85 , V_7 + V_6 , - V_145 ) ;
F_117 ( V_85 , V_155 + V_150 , V_145 ) ;
F_60 ( & V_85 -> V_149 ) ;
while ( ! F_89 ( & V_179 ) ) {
F_24 () ;
V_34 = F_90 ( & V_179 ) ;
F_13 ( & V_34 -> V_6 ) ;
if ( F_54 ( ! F_71 ( V_34 ) ) ) {
F_66 ( V_34 ) ;
continue;
}
if ( F_54 ( V_184 ) ) {
if ( F_31 ( V_34 ) && F_91 ( V_34 ) ) {
if ( F_31 ( V_34 ) )
F_103 ( V_34 , 0 ) ;
F_38 ( V_34 ) ;
}
}
if ( F_80 ( V_34 , 0 , V_2 -> V_3 ,
& V_73 ) ) {
V_182 += F_124 ( V_34 ) ;
if ( ( V_73 & V_77 ) && F_85 ( V_34 ) ) {
F_106 ( & V_34 -> V_6 , & V_180 ) ;
continue;
}
}
F_115 ( V_34 ) ;
F_106 ( & V_34 -> V_6 , & V_181 ) ;
}
F_52 ( & V_85 -> V_149 ) ;
V_158 -> V_161 [ V_150 ] += V_182 ;
F_152 ( V_4 , & V_180 , & V_179 , V_6 ) ;
F_152 ( V_4 , & V_181 , & V_179 , V_6 - V_185 ) ;
F_117 ( V_85 , V_155 + V_150 , - V_145 ) ;
F_60 ( & V_85 -> V_149 ) ;
F_110 ( & V_179 , 1 ) ;
}
static int F_155 ( struct V_85 * V_85 )
{
unsigned long V_186 , V_151 ;
V_186 = F_5 ( V_85 , V_187 ) ;
V_151 = F_5 ( V_85 , V_154 ) ;
if ( V_151 * V_85 -> V_188 < V_186 )
return 1 ;
return 0 ;
}
static int F_156 ( struct V_4 * V_4 )
{
if ( ! V_189 )
return 0 ;
if ( ! F_3 () )
return F_157 ( V_4 ) ;
return F_155 ( F_6 ( V_4 ) ) ;
}
static inline int F_156 ( struct V_4 * V_4 )
{
return 0 ;
}
static int F_158 ( struct V_4 * V_4 )
{
unsigned long V_151 ;
unsigned long V_186 ;
V_151 = F_2 ( V_4 , V_190 ) ;
V_186 = F_2 ( V_4 , V_191 ) ;
return V_186 > V_151 ;
}
static int F_159 ( struct V_4 * V_4 , enum V_5 V_6 )
{
if ( F_128 ( V_6 ) )
return F_158 ( V_4 ) ;
else
return F_156 ( V_4 ) ;
}
static unsigned long F_160 ( enum V_5 V_6 , unsigned long V_14 ,
struct V_4 * V_4 , struct V_1 * V_2 )
{
if ( F_137 ( V_6 ) ) {
if ( F_159 ( V_4 , V_6 ) )
F_154 ( V_14 , V_4 , V_2 , V_6 ) ;
return 0 ;
}
return F_142 ( V_14 , V_4 , V_2 , V_6 ) ;
}
static int F_161 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_192 ;
return F_162 ( V_2 -> V_3 ) ;
}
static void F_163 ( struct V_4 * V_4 , struct V_1 * V_2 ,
unsigned long * V_25 )
{
struct V_157 * V_158 = & V_4 -> V_158 ;
T_5 V_193 [ 2 ] ;
T_5 V_194 = 0 ;
struct V_85 * V_85 = F_6 ( V_4 ) ;
unsigned long V_195 , V_196 ;
enum V_197 V_197 ;
unsigned long V_198 , V_150 , free ;
bool V_199 = false ;
unsigned long V_200 , V_201 ;
enum V_5 V_6 ;
if ( F_96 () && V_85 -> V_202 )
V_199 = true ;
if ( ! F_1 ( V_2 ) )
V_199 = true ;
if ( ! V_2 -> V_203 || ( F_164 () <= 0 ) ) {
V_197 = V_204 ;
goto V_20;
}
if ( ! F_1 ( V_2 ) && ! F_161 ( V_2 ) ) {
V_197 = V_204 ;
goto V_20;
}
if ( ! V_2 -> V_122 && F_161 ( V_2 ) ) {
V_197 = V_205 ;
goto V_20;
}
V_198 = F_2 ( V_4 , V_206 ) +
F_2 ( V_4 , V_207 ) ;
V_150 = F_2 ( V_4 , V_191 ) +
F_2 ( V_4 , V_190 ) ;
if ( F_1 ( V_2 ) ) {
free = F_5 ( V_85 , V_208 ) ;
if ( F_54 ( V_150 + free <= F_165 ( V_85 ) ) ) {
V_197 = V_209 ;
goto V_20;
}
}
if ( ! F_158 ( V_4 ) ) {
V_197 = V_204 ;
goto V_20;
}
V_197 = V_210 ;
V_195 = F_161 ( V_2 ) ;
V_196 = 200 - V_195 ;
F_52 ( & V_85 -> V_149 ) ;
if ( F_54 ( V_158 -> V_168 [ 0 ] > V_198 / 4 ) ) {
V_158 -> V_168 [ 0 ] /= 2 ;
V_158 -> V_161 [ 0 ] /= 2 ;
}
if ( F_54 ( V_158 -> V_168 [ 1 ] > V_150 / 4 ) ) {
V_158 -> V_168 [ 1 ] /= 2 ;
V_158 -> V_161 [ 1 ] /= 2 ;
}
V_200 = V_195 * ( V_158 -> V_168 [ 0 ] + 1 ) ;
V_200 /= V_158 -> V_161 [ 0 ] + 1 ;
V_201 = V_196 * ( V_158 -> V_168 [ 1 ] + 1 ) ;
V_201 /= V_158 -> V_161 [ 1 ] + 1 ;
F_60 ( & V_85 -> V_149 ) ;
V_193 [ 0 ] = V_200 ;
V_193 [ 1 ] = V_201 ;
V_194 = V_200 + V_201 + 1 ;
V_20:
F_166 (lru) {
int V_150 = F_128 ( V_6 ) ;
unsigned long V_211 ;
unsigned long V_146 ;
V_211 = F_2 ( V_4 , V_6 ) ;
V_146 = V_211 >> V_2 -> V_122 ;
if ( ! V_146 && V_199 )
V_146 = F_21 ( V_211 , V_19 ) ;
switch ( V_197 ) {
case V_205 :
break;
case V_210 :
V_146 = F_167 ( V_146 * V_193 [ V_150 ] , V_194 ) ;
break;
case V_204 :
case V_209 :
if ( ( V_197 == V_204 ) != V_150 )
V_146 = 0 ;
break;
default:
F_126 () ;
}
V_25 [ V_6 ] = V_146 ;
}
}
static void F_168 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_25 [ V_212 ] ;
unsigned long V_213 [ V_212 ] ;
unsigned long V_14 ;
enum V_5 V_6 ;
unsigned long V_99 = 0 ;
unsigned long V_214 = V_2 -> V_214 ;
struct V_215 V_216 ;
bool V_217 = false ;
F_163 ( V_4 , V_2 , V_25 ) ;
memcpy ( V_213 , V_25 , sizeof( V_25 ) ) ;
F_169 ( & V_216 ) ;
while ( V_25 [ V_207 ] || V_25 [ V_191 ] ||
V_25 [ V_190 ] ) {
unsigned long V_218 , V_219 , V_220 ;
unsigned long V_105 ;
F_166 (lru) {
if ( V_25 [ V_6 ] ) {
V_14 = F_21 ( V_25 [ V_6 ] , V_19 ) ;
V_25 [ V_6 ] -= V_14 ;
V_99 += F_160 ( V_6 , V_14 ,
V_4 , V_2 ) ;
}
}
if ( V_99 < V_214 || V_217 )
continue;
if ( F_1 ( V_2 ) && ! F_96 () )
break;
V_219 = V_25 [ V_190 ] + V_25 [ V_191 ] ;
V_218 = V_25 [ V_207 ] + V_25 [ V_206 ] ;
if ( V_219 > V_218 ) {
unsigned long V_221 = V_213 [ V_207 ] +
V_213 [ V_206 ] + 1 ;
V_6 = V_222 ;
V_220 = V_218 * 100 / V_221 ;
} else {
unsigned long V_221 = V_213 [ V_190 ] +
V_213 [ V_191 ] + 1 ;
V_6 = V_223 ;
V_220 = V_219 * 100 / V_221 ;
}
V_25 [ V_6 ] = 0 ;
V_25 [ V_6 + V_185 ] = 0 ;
V_6 = ( V_6 == V_223 ) ? V_222 : V_223 ;
V_105 = V_213 [ V_6 ] - V_25 [ V_6 ] ;
V_25 [ V_6 ] = V_213 [ V_6 ] * ( 100 - V_220 ) / 100 ;
V_25 [ V_6 ] -= F_21 ( V_25 [ V_6 ] , V_105 ) ;
V_6 += V_185 ;
V_105 = V_213 [ V_6 ] - V_25 [ V_6 ] ;
V_25 [ V_6 ] = V_213 [ V_6 ] * ( 100 - V_220 ) / 100 ;
V_25 [ V_6 ] -= F_21 ( V_25 [ V_6 ] , V_105 ) ;
V_217 = true ;
}
F_170 ( & V_216 ) ;
V_2 -> V_99 += V_99 ;
if ( F_156 ( V_4 ) )
F_154 ( V_19 , V_4 ,
V_2 , V_206 ) ;
F_171 ( V_2 -> V_109 ) ;
}
static bool F_172 ( struct V_1 * V_2 )
{
if ( F_173 ( V_224 ) && V_2 -> V_148 &&
( V_2 -> V_148 > V_225 ||
V_2 -> V_122 < V_123 - 2 ) )
return true ;
return false ;
}
static inline bool F_174 ( struct V_85 * V_85 ,
unsigned long V_99 ,
unsigned long V_105 ,
struct V_1 * V_2 )
{
unsigned long V_226 ;
unsigned long V_227 ;
if ( ! F_172 ( V_2 ) )
return false ;
if ( V_2 -> V_109 & V_228 ) {
if ( ! V_99 && ! V_105 )
return false ;
} else {
if ( ! V_99 )
return false ;
}
V_226 = ( 2UL << V_2 -> V_148 ) ;
V_227 = F_5 ( V_85 , V_153 ) ;
if ( F_164 () > 0 )
V_227 += F_5 ( V_85 , V_154 ) ;
if ( V_2 -> V_99 < V_226 &&
V_227 > V_226 )
return true ;
switch ( F_175 ( V_85 , V_2 -> V_148 ) ) {
case V_229 :
case V_230 :
return false ;
default:
return true ;
}
}
static void F_176 ( struct V_85 * V_85 , struct V_1 * V_2 )
{
unsigned long V_99 , V_105 ;
do {
struct V_231 * V_232 = V_2 -> V_3 ;
struct V_233 V_234 = {
. V_85 = V_85 ,
. V_122 = V_2 -> V_122 ,
} ;
struct V_231 * V_235 ;
V_99 = V_2 -> V_99 ;
V_105 = V_2 -> V_105 ;
V_235 = F_177 ( V_232 , NULL , & V_234 ) ;
do {
struct V_4 * V_4 ;
V_4 = F_178 ( V_85 , V_235 ) ;
F_168 ( V_4 , V_2 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_99 >= V_2 -> V_214 ) {
F_179 ( V_232 , V_235 ) ;
break;
}
V_235 = F_177 ( V_232 , V_235 , & V_234 ) ;
} while ( V_235 );
F_180 ( V_2 -> V_109 , V_2 -> V_3 ,
V_2 -> V_105 - V_105 ,
V_2 -> V_99 - V_99 ) ;
} while ( F_174 ( V_85 , V_2 -> V_99 - V_99 ,
V_2 -> V_105 - V_105 , V_2 ) );
}
static inline bool F_181 ( struct V_85 * V_85 , struct V_1 * V_2 )
{
unsigned long V_236 , V_237 ;
bool V_238 ;
if ( V_2 -> V_148 <= V_225 )
return false ;
V_236 = F_21 ( F_182 ( V_85 ) ,
( V_85 -> V_239 + V_240 - 1 ) /
V_240 ) ;
V_237 = F_165 ( V_85 ) + V_236 + ( 2UL << V_2 -> V_148 ) ;
V_238 = F_183 ( V_85 , 0 , V_237 , 0 , 0 ) ;
if ( F_184 ( V_85 , V_2 -> V_148 ) )
return V_238 ;
if ( ! F_175 ( V_85 , V_2 -> V_148 ) )
return false ;
return V_238 ;
}
static bool F_185 ( struct V_241 * V_241 , struct V_1 * V_2 )
{
struct V_242 * V_243 ;
struct V_85 * V_85 ;
unsigned long V_244 ;
unsigned long V_245 ;
bool V_246 = false ;
if ( V_184 )
V_2 -> V_109 |= V_247 ;
F_186 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_187 ( V_85 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_188 ( V_85 , V_121 ) )
continue;
if ( V_85 -> V_202 &&
V_2 -> V_122 != V_123 )
continue;
if ( F_173 ( V_224 ) ) {
if ( F_181 ( V_85 , V_2 ) ) {
V_246 = true ;
continue;
}
}
V_245 = 0 ;
V_244 = F_189 ( V_85 ,
V_2 -> V_148 , V_2 -> V_109 ,
& V_245 ) ;
V_2 -> V_99 += V_244 ;
V_2 -> V_105 += V_245 ;
}
F_176 ( V_85 , V_2 ) ;
}
return V_246 ;
}
static bool F_190 ( struct V_85 * V_85 )
{
return V_85 -> V_165 < F_191 ( V_85 ) * 6 ;
}
static bool V_202 ( struct V_241 * V_241 ,
struct V_1 * V_2 )
{
struct V_242 * V_243 ;
struct V_85 * V_85 ;
F_186 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_187 ( V_85 ) )
continue;
if ( ! F_188 ( V_85 , V_121 ) )
continue;
if ( ! V_85 -> V_202 )
return false ;
}
return true ;
}
static unsigned long F_192 ( struct V_241 * V_241 ,
struct V_1 * V_2 ,
struct V_13 * V_15 )
{
unsigned long V_248 = 0 ;
struct V_249 * V_249 = V_37 -> V_249 ;
struct V_242 * V_243 ;
struct V_85 * V_85 ;
unsigned long V_250 ;
bool V_246 ;
F_193 () ;
if ( F_1 ( V_2 ) )
F_78 ( V_251 ) ;
do {
F_194 ( V_2 -> V_109 , V_2 -> V_3 ,
V_2 -> V_122 ) ;
V_2 -> V_105 = 0 ;
V_246 = F_185 ( V_241 , V_2 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_17 = 0 ;
F_195 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_188 ( V_85 , V_121 ) )
continue;
V_17 += F_191 ( V_85 ) ;
}
F_15 ( V_15 , V_2 -> V_105 , V_17 ) ;
if ( V_249 ) {
V_2 -> V_99 += V_249 -> V_252 ;
V_249 -> V_252 = 0 ;
}
}
V_248 += V_2 -> V_105 ;
if ( V_2 -> V_99 >= V_2 -> V_214 )
goto V_20;
if ( V_2 -> V_122 < V_123 - 2 )
V_2 -> V_118 = 1 ;
V_250 = V_2 -> V_214 + V_2 -> V_214 / 2 ;
if ( V_248 > V_250 ) {
F_196 ( V_253 ? 0 : V_248 ,
V_254 ) ;
V_2 -> V_118 = 1 ;
}
} while ( -- V_2 -> V_122 >= 0 && ! V_246 );
V_20:
F_197 () ;
if ( V_2 -> V_99 )
return V_2 -> V_99 ;
if ( V_255 )
return 0 ;
if ( V_246 )
return 1 ;
if ( F_1 ( V_2 ) && ! V_202 ( V_241 , V_2 ) )
return 1 ;
return 0 ;
}
static bool F_198 ( T_6 * V_256 )
{
struct V_85 * V_85 ;
unsigned long V_257 = 0 ;
unsigned long V_94 = 0 ;
int V_258 ;
bool V_259 ;
for ( V_258 = 0 ; V_258 <= V_260 ; V_258 ++ ) {
V_85 = & V_256 -> V_261 [ V_258 ] ;
V_257 += F_199 ( V_85 ) ;
V_94 += F_5 ( V_85 , V_208 ) ;
}
V_259 = V_94 > V_257 / 2 ;
if ( ! V_259 && F_200 ( & V_256 -> V_262 ) ) {
V_256 -> V_263 = F_21 ( V_256 -> V_263 ,
(enum V_264 ) V_260 ) ;
F_201 ( & V_256 -> V_262 ) ;
}
return V_259 ;
}
static bool F_202 ( T_7 V_109 , struct V_241 * V_241 ,
T_8 * V_265 )
{
struct V_85 * V_85 ;
int V_266 = F_203 ( V_109 ) ;
T_6 * V_256 ;
if ( V_37 -> V_38 & V_267 )
goto V_20;
if ( F_144 ( V_37 ) )
goto V_20;
F_204 ( V_241 , V_266 , NULL , & V_85 ) ;
V_256 = V_85 -> V_175 ;
if ( F_198 ( V_256 ) )
goto V_20;
F_78 ( V_268 ) ;
if ( ! ( V_109 & V_110 ) ) {
F_205 ( V_256 -> V_269 ,
F_198 ( V_256 ) , V_164 ) ;
goto V_270;
}
F_206 ( V_85 -> V_175 -> V_269 ,
F_198 ( V_256 ) ) ;
V_270:
if ( F_144 ( V_37 ) )
return true ;
V_20:
return false ;
}
unsigned long F_207 ( struct V_241 * V_241 , int V_148 ,
T_7 V_109 , T_8 * V_265 )
{
unsigned long V_99 ;
struct V_1 V_2 = {
. V_109 = ( V_109 = F_208 ( V_109 ) ) ,
. V_118 = ! V_253 ,
. V_214 = V_19 ,
. V_107 = 1 ,
. V_203 = 1 ,
. V_148 = V_148 ,
. V_122 = V_123 ,
. V_3 = NULL ,
. V_265 = V_265 ,
} ;
struct V_13 V_15 = {
. V_109 = V_2 . V_109 ,
} ;
if ( F_202 ( V_109 , V_241 , V_265 ) )
return 1 ;
F_209 ( V_148 ,
V_2 . V_118 ,
V_109 ) ;
V_99 = F_192 ( V_241 , & V_2 , & V_15 ) ;
F_210 ( V_99 ) ;
return V_99 ;
}
unsigned long F_211 ( struct V_231 * V_235 ,
T_7 V_109 , bool V_271 ,
struct V_85 * V_85 ,
unsigned long * V_105 )
{
struct V_1 V_2 = {
. V_105 = 0 ,
. V_214 = V_19 ,
. V_118 = ! V_253 ,
. V_107 = 1 ,
. V_203 = ! V_271 ,
. V_148 = 0 ,
. V_122 = 0 ,
. V_3 = V_235 ,
} ;
struct V_4 * V_4 = F_178 ( V_85 , V_235 ) ;
V_2 . V_109 = ( V_109 & V_272 ) |
( V_273 & ~ V_272 ) ;
F_212 ( V_2 . V_148 ,
V_2 . V_118 ,
V_2 . V_109 ) ;
F_168 ( V_4 , & V_2 ) ;
F_213 ( V_2 . V_99 ) ;
* V_105 = V_2 . V_105 ;
return V_2 . V_99 ;
}
unsigned long F_214 ( struct V_231 * V_235 ,
T_7 V_109 ,
bool V_271 )
{
struct V_241 * V_241 ;
unsigned long V_99 ;
int V_274 ;
struct V_1 V_2 = {
. V_118 = ! V_253 ,
. V_107 = 1 ,
. V_203 = ! V_271 ,
. V_214 = V_19 ,
. V_148 = 0 ,
. V_122 = V_123 ,
. V_3 = V_235 ,
. V_265 = NULL ,
. V_109 = ( V_109 & V_272 ) |
( V_273 & ~ V_272 ) ,
} ;
struct V_13 V_15 = {
. V_109 = V_2 . V_109 ,
} ;
V_274 = F_215 ( V_235 ) ;
V_241 = F_216 ( V_274 ) -> V_275 ;
F_217 ( 0 ,
V_2 . V_118 ,
V_2 . V_109 ) ;
V_99 = F_192 ( V_241 , & V_2 , & V_15 ) ;
F_218 ( V_99 ) ;
return V_99 ;
}
static void F_219 ( struct V_85 * V_85 , struct V_1 * V_2 )
{
struct V_231 * V_235 ;
if ( ! V_189 )
return;
V_235 = F_177 ( NULL , NULL , NULL ) ;
do {
struct V_4 * V_4 = F_178 ( V_85 , V_235 ) ;
if ( F_156 ( V_4 ) )
F_154 ( V_19 , V_4 ,
V_2 , V_206 ) ;
V_235 = F_177 ( NULL , V_235 , NULL ) ;
} while ( V_235 );
}
static bool F_220 ( struct V_85 * V_85 , int V_148 ,
unsigned long V_236 , int V_263 )
{
if ( ! F_183 ( V_85 , V_148 , F_165 ( V_85 ) +
V_236 , V_263 , 0 ) )
return false ;
if ( F_173 ( V_224 ) && V_148 &&
! F_175 ( V_85 , V_148 ) )
return false ;
return true ;
}
static bool F_221 ( T_6 * V_256 , int V_148 , int V_263 )
{
unsigned long V_239 = 0 ;
unsigned long V_276 = 0 ;
int V_258 ;
for ( V_258 = 0 ; V_258 <= V_263 ; V_258 ++ ) {
struct V_85 * V_85 = V_256 -> V_261 + V_258 ;
if ( ! F_187 ( V_85 ) )
continue;
V_239 += V_85 -> V_239 ;
if ( V_85 -> V_202 ) {
V_276 += V_85 -> V_239 ;
continue;
}
if ( F_220 ( V_85 , V_148 , 0 , V_258 ) )
V_276 += V_85 -> V_239 ;
else if ( ! V_148 )
return false ;
}
if ( V_148 )
return V_276 >= ( V_239 >> 2 ) ;
else
return true ;
}
static bool F_222 ( T_6 * V_256 , int V_148 , long V_277 ,
int V_263 )
{
if ( V_277 )
return false ;
if ( F_200 ( & V_256 -> V_269 ) ) {
F_223 ( & V_256 -> V_269 ) ;
return false ;
}
return F_221 ( V_256 , V_148 , V_263 ) ;
}
static bool F_224 ( struct V_85 * V_85 ,
int V_263 ,
struct V_1 * V_2 ,
unsigned long V_17 ,
unsigned long * V_278 )
{
unsigned long V_279 ;
int V_280 = V_2 -> V_148 ;
unsigned long V_236 ;
struct V_249 * V_249 = V_37 -> V_249 ;
struct V_13 V_15 = {
. V_109 = V_2 -> V_109 ,
} ;
bool V_281 ;
V_2 -> V_214 = F_225 ( V_19 , F_165 ( V_85 ) ) ;
if ( F_173 ( V_224 ) && V_2 -> V_148 &&
F_175 ( V_85 , V_2 -> V_148 ) !=
V_282 )
V_280 = 0 ;
V_236 = F_21 ( F_182 ( V_85 ) ,
( V_85 -> V_239 + V_240 - 1 ) /
V_240 ) ;
V_281 = ( V_184 && F_226 ( V_85 ) ) ;
if ( ! V_281 && F_220 ( V_85 , V_280 ,
V_236 , V_263 ) )
return true ;
F_176 ( V_85 , V_2 ) ;
V_249 -> V_252 = 0 ;
V_279 = F_15 ( & V_15 , V_2 -> V_105 , V_17 ) ;
V_2 -> V_99 += V_249 -> V_252 ;
* V_278 += V_2 -> V_214 ;
if ( V_279 == 0 && ! F_190 ( V_85 ) )
V_85 -> V_202 = 1 ;
F_227 ( V_85 , V_171 ) ;
if ( ! V_85 -> V_202 &&
F_220 ( V_85 , V_280 , 0 , V_263 ) ) {
F_227 ( V_85 , V_172 ) ;
F_227 ( V_85 , V_173 ) ;
}
return V_2 -> V_105 >= V_2 -> V_214 ;
}
static unsigned long F_228 ( T_6 * V_256 , int V_148 ,
int * V_263 )
{
int V_258 ;
int V_283 = 0 ;
unsigned long V_244 ;
unsigned long V_245 ;
struct V_1 V_2 = {
. V_109 = V_121 ,
. V_122 = V_123 ,
. V_107 = 1 ,
. V_203 = 1 ,
. V_118 = ! V_253 ,
. V_148 = V_148 ,
. V_3 = NULL ,
} ;
F_78 ( V_284 ) ;
do {
unsigned long V_17 = 0 ;
unsigned long V_278 = 0 ;
bool V_285 = true ;
bool V_286 = ( V_148 > 0 ) ;
V_2 . V_99 = 0 ;
for ( V_258 = V_256 -> V_287 - 1 ; V_258 >= 0 ; V_258 -- ) {
struct V_85 * V_85 = V_256 -> V_261 + V_258 ;
if ( ! F_187 ( V_85 ) )
continue;
if ( V_85 -> V_202 &&
V_2 . V_122 != V_123 )
continue;
F_219 ( V_85 , & V_2 ) ;
if ( V_184 && F_229 ( V_258 ) ) {
V_283 = V_258 ;
break;
}
if ( ! F_220 ( V_85 , V_148 , 0 , 0 ) ) {
V_283 = V_258 ;
break;
} else {
F_227 ( V_85 , V_172 ) ;
F_227 ( V_85 , V_173 ) ;
}
}
if ( V_258 < 0 )
goto V_20;
for ( V_258 = 0 ; V_258 <= V_283 ; V_258 ++ ) {
struct V_85 * V_85 = V_256 -> V_261 + V_258 ;
if ( ! F_187 ( V_85 ) )
continue;
V_17 += F_191 ( V_85 ) ;
if ( V_286 &&
F_230 ( V_85 , V_148 ,
F_182 ( V_85 ) ,
* V_263 , 0 ) )
V_286 = false ;
}
if ( V_2 . V_122 < V_123 - 2 )
V_2 . V_118 = 1 ;
for ( V_258 = 0 ; V_258 <= V_283 ; V_258 ++ ) {
struct V_85 * V_85 = V_256 -> V_261 + V_258 ;
if ( ! F_187 ( V_85 ) )
continue;
if ( V_85 -> V_202 &&
V_2 . V_122 != V_123 )
continue;
V_2 . V_105 = 0 ;
V_245 = 0 ;
V_244 = F_189 ( V_85 ,
V_148 , V_2 . V_109 ,
& V_245 ) ;
V_2 . V_99 += V_244 ;
if ( F_224 ( V_85 , V_283 , & V_2 ,
V_17 , & V_278 ) )
V_285 = false ;
}
if ( F_200 ( & V_256 -> V_269 ) &&
F_198 ( V_256 ) )
F_223 ( & V_256 -> V_269 ) ;
if ( V_148 && V_2 . V_99 >= 2UL << V_148 )
V_148 = V_2 . V_148 = 0 ;
if ( F_231 () || F_232 () )
break;
if ( V_286 && V_2 . V_99 > V_278 )
F_233 ( V_256 , V_148 ) ;
if ( V_285 || ! V_2 . V_99 )
V_2 . V_122 -- ;
} while ( V_2 . V_122 >= 1 &&
! F_221 ( V_256 , V_148 , * V_263 ) );
V_20:
* V_263 = V_283 ;
return V_148 ;
}
static void F_234 ( T_6 * V_256 , int V_148 , int V_263 )
{
long V_277 = 0 ;
F_235 ( V_288 ) ;
if ( F_236 ( V_37 ) || F_232 () )
return;
F_237 ( & V_256 -> V_262 , & V_288 , V_289 ) ;
if ( F_222 ( V_256 , V_148 , V_277 , V_263 ) ) {
V_277 = F_238 ( V_164 / 10 ) ;
F_239 ( & V_256 -> V_262 , & V_288 ) ;
F_237 ( & V_256 -> V_262 , & V_288 , V_289 ) ;
}
if ( F_222 ( V_256 , V_148 , V_277 , V_263 ) ) {
F_240 ( V_256 -> V_176 ) ;
F_241 ( V_256 , V_290 ) ;
F_242 ( V_256 ) ;
if ( ! F_232 () )
F_243 () ;
F_241 ( V_256 , V_291 ) ;
} else {
if ( V_277 )
F_78 ( V_292 ) ;
else
F_78 ( V_293 ) ;
}
F_239 ( & V_256 -> V_262 , & V_288 ) ;
}
static int F_244 ( void * V_294 )
{
unsigned long V_148 , V_295 ;
unsigned V_296 ;
int V_263 , V_297 ;
int V_298 ;
T_6 * V_256 = ( T_6 * ) V_294 ;
struct V_299 * V_300 = V_37 ;
struct V_249 V_249 = {
. V_252 = 0 ,
} ;
const struct V_301 * V_301 = F_245 ( V_256 -> V_176 ) ;
F_246 ( V_121 ) ;
if ( ! F_247 ( V_301 ) )
F_248 ( V_300 , V_301 ) ;
V_37 -> V_249 = & V_249 ;
V_300 -> V_38 |= V_302 | V_39 | V_303 ;
F_249 () ;
V_148 = V_295 = 0 ;
V_296 = 0 ;
V_263 = V_297 = V_256 -> V_287 - 1 ;
V_298 = V_263 ;
for ( ; ; ) {
bool V_18 ;
if ( V_298 >= V_297 &&
V_296 == V_295 ) {
V_295 = V_256 -> V_304 ;
V_297 = V_256 -> V_263 ;
V_256 -> V_304 = 0 ;
V_256 -> V_263 = V_256 -> V_287 - 1 ;
}
if ( V_148 < V_295 || V_263 > V_297 ) {
V_148 = V_295 ;
V_263 = V_297 ;
} else {
F_234 ( V_256 , V_296 ,
V_298 ) ;
V_148 = V_256 -> V_304 ;
V_263 = V_256 -> V_263 ;
V_295 = V_148 ;
V_297 = V_263 ;
V_256 -> V_304 = 0 ;
V_256 -> V_263 = V_256 -> V_287 - 1 ;
}
V_18 = F_231 () ;
if ( F_232 () )
break;
if ( ! V_18 ) {
F_250 ( V_256 -> V_176 , V_148 ) ;
V_298 = V_263 ;
V_296 = F_228 ( V_256 , V_148 ,
& V_298 ) ;
}
}
V_37 -> V_249 = NULL ;
return 0 ;
}
void F_251 ( struct V_85 * V_85 , int V_148 , enum V_264 V_263 )
{
T_6 * V_256 ;
if ( ! F_187 ( V_85 ) )
return;
if ( ! F_188 ( V_85 , V_121 ) )
return;
V_256 = V_85 -> V_175 ;
if ( V_256 -> V_304 < V_148 ) {
V_256 -> V_304 = V_148 ;
V_256 -> V_263 = F_21 ( V_256 -> V_263 , V_263 ) ;
}
if ( ! F_200 ( & V_256 -> V_262 ) )
return;
if ( F_183 ( V_85 , V_148 , F_182 ( V_85 ) , 0 , 0 ) )
return;
F_252 ( V_256 -> V_176 , F_150 ( V_85 ) , V_148 ) ;
F_201 ( & V_256 -> V_262 ) ;
}
unsigned long F_253 ( void )
{
int V_25 ;
V_25 = F_254 ( V_305 ) +
F_254 ( V_153 ) ;
if ( F_164 () > 0 )
V_25 += F_254 ( V_187 ) +
F_254 ( V_154 ) ;
return V_25 ;
}
unsigned long F_191 ( struct V_85 * V_85 )
{
int V_25 ;
V_25 = F_5 ( V_85 , V_305 ) +
F_5 ( V_85 , V_153 ) ;
if ( F_164 () > 0 )
V_25 += F_5 ( V_85 , V_187 ) +
F_5 ( V_85 , V_154 ) ;
return V_25 ;
}
unsigned long F_255 ( unsigned long V_214 )
{
struct V_249 V_249 ;
struct V_1 V_2 = {
. V_109 = V_273 ,
. V_203 = 1 ,
. V_107 = 1 ,
. V_118 = 1 ,
. V_214 = V_214 ,
. V_174 = 1 ,
. V_148 = 0 ,
. V_122 = V_123 ,
} ;
struct V_13 V_15 = {
. V_109 = V_2 . V_109 ,
} ;
struct V_241 * V_241 = F_256 ( F_257 () , V_2 . V_109 ) ;
struct V_299 * V_294 = V_37 ;
unsigned long V_99 ;
V_294 -> V_38 |= V_302 ;
F_246 ( V_2 . V_109 ) ;
V_249 . V_252 = 0 ;
V_294 -> V_249 = & V_249 ;
V_99 = F_192 ( V_241 , & V_2 , & V_15 ) ;
V_294 -> V_249 = NULL ;
F_258 () ;
V_294 -> V_38 &= ~ V_302 ;
return V_99 ;
}
static int F_259 ( struct V_306 * V_307 , unsigned long V_308 ,
void * V_309 )
{
int V_274 ;
if ( V_308 == V_310 || V_308 == V_311 ) {
F_260 (nid, N_MEMORY) {
T_6 * V_256 = F_216 ( V_274 ) ;
const struct V_301 * V_312 ;
V_312 = F_245 ( V_256 -> V_176 ) ;
if ( F_261 ( V_313 , V_312 ) < V_314 )
F_248 ( V_256 -> F_244 , V_312 ) ;
}
}
return V_315 ;
}
int F_262 ( int V_274 )
{
T_6 * V_256 = F_216 ( V_274 ) ;
int V_18 = 0 ;
if ( V_256 -> F_244 )
return 0 ;
V_256 -> F_244 = F_263 ( F_244 , V_256 , L_4 , V_274 ) ;
if ( F_264 ( V_256 -> F_244 ) ) {
F_50 ( V_316 == V_317 ) ;
F_265 ( L_5 , V_274 ) ;
V_18 = F_266 ( V_256 -> F_244 ) ;
V_256 -> F_244 = NULL ;
}
return V_18 ;
}
void F_267 ( int V_274 )
{
struct V_299 * F_244 = F_216 ( V_274 ) -> F_244 ;
if ( F_244 ) {
F_268 ( F_244 ) ;
F_216 ( V_274 ) -> F_244 = NULL ;
}
}
static int T_9 F_269 ( void )
{
int V_274 ;
F_270 () ;
F_260 (nid, N_MEMORY)
F_262 ( V_274 ) ;
F_271 ( F_259 , 0 ) ;
return 0 ;
}
static inline unsigned long F_272 ( struct V_85 * V_85 )
{
unsigned long V_318 = F_5 ( V_85 , V_319 ) ;
unsigned long V_320 = F_5 ( V_85 , V_153 ) +
F_5 ( V_85 , V_305 ) ;
return ( V_320 > V_318 ) ? ( V_320 - V_318 ) : 0 ;
}
static long F_273 ( struct V_85 * V_85 )
{
long V_321 ;
long V_21 = 0 ;
if ( V_322 & V_323 )
V_321 = F_5 ( V_85 , V_324 ) ;
else
V_321 = F_272 ( V_85 ) ;
if ( ! ( V_322 & V_325 ) )
V_21 += F_5 ( V_85 , V_326 ) ;
if ( F_54 ( V_21 > V_321 ) )
V_21 = V_321 ;
return V_321 - V_21 ;
}
static int F_274 ( struct V_85 * V_85 , T_7 V_109 , unsigned int V_148 )
{
const unsigned long V_147 = 1 << V_148 ;
struct V_299 * V_294 = V_37 ;
struct V_249 V_249 ;
struct V_1 V_2 = {
. V_118 = ! ! ( V_322 & V_325 ) ,
. V_107 = ! ! ( V_322 & V_323 ) ,
. V_203 = 1 ,
. V_214 = F_225 ( V_147 , V_19 ) ,
. V_109 = ( V_109 = F_208 ( V_109 ) ) ,
. V_148 = V_148 ,
. V_122 = V_327 ,
} ;
struct V_13 V_15 = {
. V_109 = V_2 . V_109 ,
} ;
unsigned long V_328 , V_329 ;
F_24 () ;
V_294 -> V_38 |= V_302 | V_39 ;
F_246 ( V_109 ) ;
V_249 . V_252 = 0 ;
V_294 -> V_249 = & V_249 ;
if ( F_273 ( V_85 ) > V_85 -> V_330 ) {
do {
F_176 ( V_85 , & V_2 ) ;
} while ( V_2 . V_99 < V_147 && -- V_2 . V_122 >= 0 );
}
V_328 = F_5 ( V_85 , V_331 ) ;
if ( V_328 > V_85 -> V_332 ) {
for (; ; ) {
unsigned long V_17 = F_191 ( V_85 ) ;
if ( ! F_15 ( & V_15 , V_2 . V_105 , V_17 ) )
break;
V_329 = F_5 ( V_85 ,
V_331 ) ;
if ( V_329 + V_147 <= V_328 )
break;
}
V_329 = F_5 ( V_85 , V_331 ) ;
if ( V_329 < V_328 )
V_2 . V_99 += V_328 - V_329 ;
}
V_294 -> V_249 = NULL ;
V_37 -> V_38 &= ~ ( V_302 | V_39 ) ;
F_258 () ;
return V_2 . V_99 >= V_147 ;
}
int F_275 ( struct V_85 * V_85 , T_7 V_109 , unsigned int V_148 )
{
int V_176 ;
int V_18 ;
if ( F_273 ( V_85 ) <= V_85 -> V_330 &&
F_5 ( V_85 , V_331 ) <= V_85 -> V_332 )
return V_333 ;
if ( V_85 -> V_202 )
return V_333 ;
if ( ! ( V_109 & V_334 ) || ( V_37 -> V_38 & V_302 ) )
return V_335 ;
V_176 = F_276 ( V_85 ) ;
if ( F_277 ( V_176 , V_336 ) && V_176 != F_257 () )
return V_335 ;
if ( F_278 ( V_85 , V_337 ) )
return V_335 ;
V_18 = F_274 ( V_85 , V_109 , V_148 ) ;
F_227 ( V_85 , V_337 ) ;
if ( ! V_18 )
F_78 ( V_338 ) ;
return V_18 ;
}
int F_71 ( struct V_34 * V_34 )
{
return ! F_279 ( F_36 ( V_34 ) ) && ! F_280 ( V_34 ) ;
}
void F_281 ( struct V_34 * * V_339 , int V_147 )
{
struct V_4 * V_4 ;
struct V_85 * V_85 = NULL ;
int V_340 = 0 ;
int V_341 = 0 ;
int V_258 ;
for ( V_258 = 0 ; V_258 < V_147 ; V_258 ++ ) {
struct V_34 * V_34 = V_339 [ V_258 ] ;
struct V_85 * V_342 ;
V_340 ++ ;
V_342 = F_93 ( V_34 ) ;
if ( V_342 != V_85 ) {
if ( V_85 )
F_60 ( & V_85 -> V_149 ) ;
V_85 = V_342 ;
F_52 ( & V_85 -> V_149 ) ;
}
V_4 = F_129 ( V_34 , V_85 ) ;
if ( ! F_69 ( V_34 ) || ! F_67 ( V_34 ) )
continue;
if ( F_71 ( V_34 ) ) {
enum V_5 V_6 = F_72 ( V_34 ) ;
F_68 ( F_92 ( V_34 ) ) ;
F_70 ( V_34 ) ;
F_132 ( V_34 , V_4 , V_67 ) ;
F_136 ( V_34 , V_4 , V_6 ) ;
V_341 ++ ;
}
}
if ( V_85 ) {
F_153 ( V_68 , V_341 ) ;
F_153 ( V_343 , V_340 ) ;
F_60 ( & V_85 -> V_149 ) ;
}
}
static void F_282 ( void )
{
F_283 ( V_344
L_6
L_7
L_8 ,
V_37 -> V_345 ) ;
}
int F_284 ( struct V_346 * V_347 , int V_348 ,
void T_10 * V_349 ,
T_11 * V_350 , T_12 * V_351 )
{
F_282 () ;
F_285 ( V_347 , V_348 , V_349 , V_350 , V_351 ) ;
V_352 = 0 ;
return 0 ;
}
static T_13 F_286 ( struct V_353 * V_354 ,
struct V_355 * V_356 ,
char * V_357 )
{
F_282 () ;
return sprintf ( V_357 , L_9 ) ;
}
static T_13 F_287 ( struct V_353 * V_354 ,
struct V_355 * V_356 ,
const char * V_357 , T_11 V_358 )
{
F_282 () ;
return 1 ;
}
int F_288 ( struct V_359 * V_359 )
{
return F_289 ( & V_359 -> V_354 , & V_360 ) ;
}
void F_290 ( struct V_359 * V_359 )
{
F_291 ( & V_359 -> V_354 , & V_360 ) ;
}
