static struct V_1 * F_1 ( struct V_2 * V_2 ,
struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 ) )
return F_3 ( V_4 -> V_5 , V_2 ) ;
return & V_2 -> V_6 ;
}
static unsigned long F_4 ( struct V_2 * V_2 ,
struct V_3 * V_4 , enum V_7 V_8 )
{
if ( ! F_2 ( V_4 ) )
return F_5 ( V_4 -> V_5 , V_2 , V_8 ) ;
return F_6 ( V_2 , V_9 + V_8 ) ;
}
void F_7 ( struct V_10 * V_10 )
{
V_10 -> V_11 = 0 ;
F_8 ( & V_12 ) ;
F_9 ( & V_10 -> V_13 , & V_14 ) ;
F_10 ( & V_12 ) ;
}
void F_11 ( struct V_10 * V_10 )
{
F_8 ( & V_12 ) ;
F_12 ( & V_10 -> V_13 ) ;
F_10 ( & V_12 ) ;
}
static inline int F_13 ( struct V_10 * V_10 ,
struct V_15 * V_4 ,
unsigned long V_16 )
{
V_4 -> V_16 = V_16 ;
return (* V_10 -> V_17 )( V_10 , V_4 ) ;
}
unsigned long F_14 ( struct V_15 * V_17 ,
unsigned long V_18 ,
unsigned long V_19 )
{
struct V_10 * V_10 ;
unsigned long V_20 = 0 ;
if ( V_18 == 0 )
V_18 = V_21 ;
if ( ! F_15 ( & V_12 ) ) {
V_20 = 1 ;
goto V_22;
}
F_16 (shrinker, &shrinker_list, list) {
unsigned long long V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
V_25 = F_13 ( V_10 , V_17 , 0 ) ;
V_23 = ( 4 * V_18 ) / V_10 -> V_26 ;
V_23 *= V_25 ;
F_17 ( V_23 , V_19 + 1 ) ;
V_10 -> V_11 += V_23 ;
if ( V_10 -> V_11 < 0 ) {
F_18 ( V_27 L_1
L_2 ,
V_10 -> V_17 , V_10 -> V_11 ) ;
V_10 -> V_11 = V_25 ;
}
if ( V_10 -> V_11 > V_25 * 2 )
V_10 -> V_11 = V_25 * 2 ;
V_24 = V_10 -> V_11 ;
V_10 -> V_11 = 0 ;
while ( V_24 >= V_28 ) {
long V_29 = V_28 ;
int V_30 ;
int V_31 ;
V_31 = F_13 ( V_10 , V_17 , 0 ) ;
V_30 = F_13 ( V_10 , V_17 ,
V_29 ) ;
if ( V_30 == - 1 )
break;
if ( V_30 < V_31 )
V_20 += V_31 - V_30 ;
F_19 ( V_32 , V_29 ) ;
V_24 -= V_29 ;
F_20 () ;
}
V_10 -> V_11 += V_24 ;
}
F_21 ( & V_12 ) ;
V_22:
F_20 () ;
return V_20 ;
}
static void F_22 ( int V_33 , struct V_3 * V_4 ,
bool V_34 )
{
T_1 V_35 = V_34 ? V_36 : V_37 ;
if ( V_38 )
V_4 -> V_39 = V_40 ;
else
V_4 -> V_39 = V_41 ;
if ( V_4 -> V_42 > V_43 )
V_4 -> V_39 |= V_35 ;
else if ( V_4 -> V_42 && V_33 < V_44 - 2 )
V_4 -> V_39 |= V_35 ;
else
V_4 -> V_39 = V_45 | V_37 ;
}
static void F_23 ( struct V_3 * V_4 )
{
V_4 -> V_39 = V_45 | V_37 ;
}
static inline int F_24 ( struct V_46 * V_46 )
{
return F_25 ( V_46 ) - F_26 ( V_46 ) == 2 ;
}
static int F_27 ( struct V_47 * V_48 ,
struct V_3 * V_4 )
{
if ( V_49 -> V_50 & V_51 )
return 1 ;
if ( ! F_28 ( V_48 ) )
return 1 ;
if ( V_48 == V_49 -> V_47 )
return 1 ;
if ( V_4 -> V_42 > V_43 )
return 1 ;
return 0 ;
}
static void F_29 ( struct V_52 * V_53 ,
struct V_46 * V_46 , int error )
{
F_30 ( V_46 ) ;
if ( F_31 ( V_46 ) == V_53 )
F_32 ( V_53 , error ) ;
F_33 ( V_46 ) ;
}
static T_2 F_34 ( struct V_46 * V_46 , struct V_52 * V_53 ,
struct V_3 * V_4 )
{
if ( ! F_24 ( V_46 ) )
return V_54 ;
if ( ! V_53 ) {
if ( F_26 ( V_46 ) ) {
if ( F_35 ( V_46 ) ) {
F_36 ( V_46 ) ;
F_18 ( L_3 , V_55 ) ;
return V_56 ;
}
}
return V_54 ;
}
if ( V_53 -> V_57 -> V_58 == NULL )
return V_59 ;
if ( ! F_27 ( V_53 -> V_47 , V_4 ) )
return V_54 ;
if ( F_37 ( V_46 ) ) {
int V_60 ;
struct V_61 V_62 = {
. V_63 = V_64 ,
. V_65 = V_21 ,
. V_66 = 0 ,
. V_67 = V_68 ,
. V_69 = 1 ,
} ;
F_38 ( V_46 ) ;
V_60 = V_53 -> V_57 -> V_58 ( V_46 , & V_62 ) ;
if ( V_60 < 0 )
F_29 ( V_53 , V_46 , V_60 ) ;
if ( V_60 == V_70 ) {
F_39 ( V_46 ) ;
return V_59 ;
}
if ( F_40 ( V_46 ) &&
( V_4 -> V_39 & V_36 ) )
F_41 ( V_46 ) ;
if ( ! F_40 ( V_46 ) ) {
F_39 ( V_46 ) ;
}
F_42 ( V_46 ,
F_43 ( V_46 , V_4 -> V_39 ) ) ;
F_44 ( V_46 , V_71 ) ;
return V_72 ;
}
return V_56 ;
}
static int F_45 ( struct V_52 * V_53 , struct V_46 * V_46 )
{
F_46 ( ! F_47 ( V_46 ) ) ;
F_46 ( V_53 != F_31 ( V_46 ) ) ;
F_48 ( & V_53 -> V_73 ) ;
if ( ! F_49 ( V_46 , 2 ) )
goto V_74;
if ( F_50 ( F_51 ( V_46 ) ) ) {
F_52 ( V_46 , 2 ) ;
goto V_74;
}
if ( F_53 ( V_46 ) ) {
T_3 V_75 = { . V_76 = F_54 (page) } ;
F_55 ( V_46 ) ;
F_56 ( & V_53 -> V_73 ) ;
F_57 ( V_75 , V_46 ) ;
} else {
void (* F_58)( struct V_46 * );
F_58 = V_53 -> V_57 -> F_58 ;
F_59 ( V_46 ) ;
F_56 ( & V_53 -> V_73 ) ;
F_60 ( V_46 ) ;
if ( F_58 != NULL )
F_58 ( V_46 ) ;
}
return 1 ;
V_74:
F_56 ( & V_53 -> V_73 ) ;
return 0 ;
}
int F_61 ( struct V_52 * V_53 , struct V_46 * V_46 )
{
if ( F_45 ( V_53 , V_46 ) ) {
F_52 ( V_46 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_62 ( struct V_46 * V_46 )
{
int V_8 ;
int V_77 = ! ! F_63 ( V_46 ) ;
int V_78 = F_64 ( V_46 ) ;
F_65 ( F_66 ( V_46 ) ) ;
V_79:
F_67 ( V_46 ) ;
if ( F_68 ( V_46 , NULL ) ) {
V_8 = V_77 + F_69 ( V_46 ) ;
F_70 ( V_46 , V_8 ) ;
} else {
V_8 = V_80 ;
F_71 ( V_46 ) ;
F_72 () ;
}
if ( V_8 == V_80 && F_68 ( V_46 , NULL ) ) {
if ( ! F_73 ( V_46 ) ) {
F_74 ( V_46 ) ;
goto V_79;
}
}
if ( V_78 && V_8 != V_80 )
F_75 ( V_81 ) ;
else if ( ! V_78 && V_8 == V_80 )
F_75 ( V_82 ) ;
F_74 ( V_46 ) ;
}
static enum V_83 F_76 ( struct V_46 * V_46 ,
struct V_3 * V_4 )
{
int V_84 , V_85 ;
unsigned long V_86 ;
V_84 = F_77 ( V_46 , 1 , V_4 -> V_5 , & V_86 ) ;
V_85 = F_78 ( V_46 ) ;
if ( V_4 -> V_39 & V_41 )
return V_87 ;
if ( V_86 & V_88 )
return V_87 ;
if ( V_84 ) {
if ( F_79 ( V_46 ) )
return V_89 ;
F_80 ( V_46 ) ;
if ( V_85 )
return V_89 ;
return V_90 ;
}
if ( V_85 && ! F_81 ( V_46 ) )
return V_91 ;
return V_87 ;
}
static T_4 void F_82 ( struct V_92 * V_93 )
{
struct V_94 V_95 ;
struct V_46 * V_46 , * V_96 ;
F_83 ( & V_95 , 1 ) ;
F_84 (page, tmp, free_pages, lru) {
F_12 ( & V_46 -> V_8 ) ;
if ( ! F_85 ( & V_95 , V_46 ) ) {
F_86 ( & V_95 ) ;
F_87 ( & V_95 ) ;
}
}
F_88 ( & V_95 ) ;
}
static unsigned long F_89 ( struct V_92 * V_97 ,
struct V_2 * V_2 ,
struct V_3 * V_4 )
{
F_90 ( V_98 ) ;
F_90 ( V_93 ) ;
int V_99 = 0 ;
unsigned long V_100 = 0 ;
unsigned long V_101 = 0 ;
unsigned long V_102 = 0 ;
F_20 () ;
while ( ! F_91 ( V_97 ) ) {
enum V_83 V_103 ;
struct V_52 * V_53 ;
struct V_46 * V_46 ;
int V_104 ;
F_20 () ;
V_46 = F_92 ( V_97 ) ;
F_12 ( & V_46 -> V_8 ) ;
if ( ! F_93 ( V_46 ) )
goto V_105;
F_65 ( F_94 ( V_46 ) ) ;
F_65 ( F_95 ( V_46 ) != V_2 ) ;
V_4 -> V_106 ++ ;
if ( F_50 ( ! F_68 ( V_46 , NULL ) ) )
goto V_107;
if ( ! V_4 -> V_108 && F_96 ( V_46 ) )
goto V_109;
if ( F_96 ( V_46 ) || F_53 ( V_46 ) )
V_4 -> V_106 ++ ;
V_104 = ( V_4 -> V_110 & V_111 ) ||
( F_53 ( V_46 ) && ( V_4 -> V_110 & V_112 ) ) ;
if ( F_40 ( V_46 ) ) {
if ( ( V_4 -> V_39 & V_36 ) &&
V_104 )
F_41 ( V_46 ) ;
else {
F_33 ( V_46 ) ;
goto V_113;
}
}
V_103 = F_76 ( V_46 , V_4 ) ;
switch ( V_103 ) {
case V_89 :
goto V_114;
case V_90 :
goto V_109;
case V_87 :
case V_91 :
;
}
if ( F_79 ( V_46 ) && ! F_53 ( V_46 ) ) {
if ( ! ( V_4 -> V_110 & V_112 ) )
goto V_109;
if ( ! F_97 ( V_46 ) )
goto V_114;
V_104 = 1 ;
}
V_53 = F_31 ( V_46 ) ;
if ( F_96 ( V_46 ) && V_53 ) {
switch ( F_98 ( V_46 , V_115 ) ) {
case V_116 :
goto V_114;
case V_117 :
goto V_109;
case V_118 :
goto V_107;
case V_119 :
;
}
}
if ( F_51 ( V_46 ) ) {
V_100 ++ ;
if ( V_103 == V_91 )
goto V_109;
if ( ! V_104 )
goto V_109;
if ( ! V_4 -> V_120 )
goto V_109;
switch ( F_34 ( V_46 , V_53 , V_4 ) ) {
case V_54 :
V_101 ++ ;
goto V_109;
case V_59 :
goto V_114;
case V_72 :
if ( F_40 ( V_46 ) )
goto V_113;
if ( F_51 ( V_46 ) )
goto V_105;
if ( ! F_93 ( V_46 ) )
goto V_105;
if ( F_51 ( V_46 ) || F_40 ( V_46 ) )
goto V_109;
V_53 = F_31 ( V_46 ) ;
case V_56 :
;
}
}
if ( F_26 ( V_46 ) ) {
if ( ! F_99 ( V_46 , V_4 -> V_110 ) )
goto V_114;
if ( ! V_53 && F_25 ( V_46 ) == 1 ) {
F_33 ( V_46 ) ;
if ( F_100 ( V_46 ) )
goto V_121;
else {
V_102 ++ ;
continue;
}
}
}
if ( ! V_53 || ! F_45 ( V_53 , V_46 ) )
goto V_109;
F_101 ( V_46 ) ;
V_121:
V_102 ++ ;
F_102 ( & V_46 -> V_8 , & V_93 ) ;
continue;
V_107:
if ( F_53 ( V_46 ) )
F_103 ( V_46 ) ;
F_33 ( V_46 ) ;
F_62 ( V_46 ) ;
F_23 ( V_4 ) ;
continue;
V_114:
if ( F_53 ( V_46 ) && F_104 () )
F_103 ( V_46 ) ;
F_65 ( F_94 ( V_46 ) ) ;
F_105 ( V_46 ) ;
V_99 ++ ;
V_109:
F_33 ( V_46 ) ;
V_105:
F_23 ( V_4 ) ;
V_113:
F_102 ( & V_46 -> V_8 , & V_98 ) ;
F_65 ( F_66 ( V_46 ) || F_64 ( V_46 ) ) ;
}
if ( V_100 && V_100 == V_101 && F_2 ( V_4 ) )
F_106 ( V_2 , V_122 ) ;
F_82 ( & V_93 ) ;
F_107 ( & V_98 , V_97 ) ;
F_19 ( V_123 , V_99 ) ;
return V_102 ;
}
int F_108 ( struct V_46 * V_46 , int V_124 , int V_125 )
{
int V_20 = - V_126 ;
if ( ! F_66 ( V_46 ) )
return V_20 ;
if ( V_124 != V_127 && ( ! F_94 ( V_46 ) != ! V_124 ) )
return V_20 ;
if ( V_124 != V_127 && F_109 ( V_46 ) != V_125 )
return V_20 ;
if ( F_64 ( V_46 ) )
return V_20 ;
V_20 = - V_128 ;
if ( F_110 ( F_111 ( V_46 ) ) ) {
F_112 ( V_46 ) ;
V_20 = 0 ;
}
return V_20 ;
}
static unsigned long F_113 ( unsigned long V_16 ,
struct V_92 * V_129 , struct V_92 * V_130 ,
unsigned long * V_131 , int V_42 , int V_124 , int V_125 )
{
unsigned long V_132 = 0 ;
unsigned long V_133 = 0 ;
unsigned long V_134 = 0 ;
unsigned long V_135 = 0 ;
unsigned long V_136 ;
for ( V_136 = 0 ; V_136 < V_16 && ! F_91 ( V_129 ) ; V_136 ++ ) {
struct V_46 * V_46 ;
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 ;
int V_140 ;
V_46 = F_92 ( V_129 ) ;
F_114 ( V_46 , V_129 , V_50 ) ;
F_65 ( ! F_66 ( V_46 ) ) ;
switch ( F_108 ( V_46 , V_124 , V_125 ) ) {
case 0 :
F_115 ( & V_46 -> V_8 , V_130 ) ;
F_116 ( V_46 ) ;
V_132 += F_117 ( V_46 ) ;
break;
case - V_128 :
F_115 ( & V_46 -> V_8 , V_129 ) ;
F_118 ( V_46 , F_119 ( V_46 ) ) ;
continue;
default:
F_120 () ;
}
if ( ! V_42 )
continue;
V_140 = F_121 ( V_46 ) ;
V_139 = F_122 ( V_46 ) ;
V_137 = V_139 & ~ ( ( 1 << V_42 ) - 1 ) ;
V_138 = V_137 + ( 1 << V_42 ) ;
for (; V_137 < V_138 ; V_137 ++ ) {
struct V_46 * V_141 ;
if ( F_50 ( V_137 == V_139 ) )
continue;
if ( F_50 ( ! F_123 ( V_137 ) ) )
break;
V_141 = F_124 ( V_137 ) ;
if ( F_50 ( F_121 ( V_141 ) != V_140 ) )
break;
if ( V_142 <= 0 && F_79 ( V_141 ) &&
! F_53 ( V_141 ) )
break;
if ( F_108 ( V_141 , V_124 , V_125 ) == 0 ) {
F_115 ( & V_141 -> V_8 , V_130 ) ;
F_116 ( V_141 ) ;
V_132 += F_117 ( V_46 ) ;
V_133 ++ ;
if ( F_51 ( V_141 ) )
V_134 ++ ;
V_136 ++ ;
} else {
if ( ! F_125 ( V_141 ) &&
! F_126 ( & V_141 -> V_143 ) )
continue;
break;
}
}
if ( V_137 < V_138 )
V_135 ++ ;
}
* V_131 = V_136 ;
F_127 ( V_42 ,
V_16 , V_136 ,
V_132 ,
V_133 , V_134 , V_135 ,
V_124 ) ;
return V_132 ;
}
static unsigned long F_128 ( unsigned long V_11 ,
struct V_92 * V_130 ,
unsigned long * V_131 , int V_42 ,
int V_124 , struct V_2 * V_144 ,
int V_77 , int V_125 )
{
int V_8 = V_145 ;
if ( V_77 )
V_8 += V_146 ;
if ( V_125 )
V_8 += V_147 ;
return F_113 ( V_11 , & V_144 -> V_8 [ V_8 ] . V_13 , V_130 , V_131 , V_42 ,
V_124 , V_125 ) ;
}
static unsigned long F_129 ( struct V_92 * V_97 ,
unsigned int * V_148 )
{
int V_149 = 0 ;
int V_8 ;
struct V_46 * V_46 ;
F_16 (page, page_list, lru) {
int V_150 = F_117 ( V_46 ) ;
V_8 = F_69 ( V_46 ) ;
if ( F_94 ( V_46 ) ) {
V_8 += V_146 ;
F_130 ( V_46 ) ;
V_149 += V_150 ;
}
if ( V_148 )
V_148 [ V_8 ] += V_150 ;
}
return V_149 ;
}
int F_73 ( struct V_46 * V_46 )
{
int V_20 = - V_128 ;
F_65 ( ! F_25 ( V_46 ) ) ;
if ( F_66 ( V_46 ) ) {
struct V_2 * V_2 = F_95 ( V_46 ) ;
F_48 ( & V_2 -> V_151 ) ;
if ( F_66 ( V_46 ) ) {
int V_8 = F_119 ( V_46 ) ;
V_20 = 0 ;
F_131 ( V_46 ) ;
F_112 ( V_46 ) ;
F_132 ( V_2 , V_46 , V_8 ) ;
}
F_56 ( & V_2 -> V_151 ) ;
}
return V_20 ;
}
static int F_133 ( struct V_2 * V_2 , int V_125 ,
struct V_3 * V_4 )
{
unsigned long V_152 , V_153 ;
if ( F_134 () )
return 0 ;
if ( ! F_2 ( V_4 ) )
return 0 ;
if ( V_125 ) {
V_152 = F_6 ( V_2 , V_154 ) ;
V_153 = F_6 ( V_2 , V_155 ) ;
} else {
V_152 = F_6 ( V_2 , V_156 ) ;
V_153 = F_6 ( V_2 , V_157 ) ;
}
return V_153 > V_152 ;
}
static T_4 void
F_135 ( struct V_2 * V_2 , struct V_3 * V_4 ,
unsigned long V_158 , unsigned long V_159 ,
struct V_92 * V_97 )
{
struct V_46 * V_46 ;
struct V_94 V_160 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
F_83 ( & V_160 , 1 ) ;
F_136 ( & V_2 -> V_151 ) ;
while ( ! F_91 ( V_97 ) ) {
int V_8 ;
V_46 = F_92 ( V_97 ) ;
F_65 ( F_66 ( V_46 ) ) ;
F_12 ( & V_46 -> V_8 ) ;
if ( F_50 ( ! F_68 ( V_46 , NULL ) ) ) {
F_56 ( & V_2 -> V_151 ) ;
F_62 ( V_46 ) ;
F_48 ( & V_2 -> V_151 ) ;
continue;
}
F_137 ( V_46 ) ;
V_8 = F_119 ( V_46 ) ;
F_138 ( V_2 , V_46 , V_8 ) ;
if ( F_139 ( V_8 ) ) {
int V_125 = F_140 ( V_8 ) ;
int V_150 = F_117 ( V_46 ) ;
V_6 -> V_161 [ V_125 ] += V_150 ;
}
if ( ! F_85 ( & V_160 , V_46 ) ) {
F_56 ( & V_2 -> V_151 ) ;
F_141 ( & V_160 ) ;
F_48 ( & V_2 -> V_151 ) ;
}
}
F_142 ( V_2 , V_157 , - V_158 ) ;
F_142 ( V_2 , V_155 , - V_159 ) ;
F_56 ( & V_2 -> V_151 ) ;
F_143 ( & V_160 ) ;
}
static T_4 void F_144 ( struct V_2 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_158 ,
unsigned long * V_159 ,
struct V_92 * V_162 )
{
unsigned long V_149 ;
unsigned int V_148 [ V_163 ] = { 0 , } ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
V_149 = F_129 ( V_162 , V_148 ) ;
F_145 ( V_164 , V_149 ) ;
F_142 ( V_2 , V_165 ,
- V_148 [ V_166 ] ) ;
F_142 ( V_2 , V_154 ,
- V_148 [ V_167 ] ) ;
F_142 ( V_2 , V_168 ,
- V_148 [ V_169 ] ) ;
F_142 ( V_2 , V_156 ,
- V_148 [ V_170 ] ) ;
* V_158 = V_148 [ V_169 ] + V_148 [ V_170 ] ;
* V_159 = V_148 [ V_166 ] + V_148 [ V_167 ] ;
F_142 ( V_2 , V_157 , * V_158 ) ;
F_142 ( V_2 , V_155 , * V_159 ) ;
V_6 -> V_171 [ 0 ] += * V_158 ;
V_6 -> V_171 [ 1 ] += * V_159 ;
}
static inline bool F_146 ( unsigned long V_132 ,
unsigned long V_172 ,
int V_33 ,
struct V_3 * V_4 )
{
int V_173 ;
if ( F_134 () )
return false ;
if ( V_4 -> V_39 & V_45 )
return false ;
if ( V_172 == V_132 )
return false ;
if ( V_4 -> V_42 > V_43 )
V_173 = V_44 ;
else
V_173 = V_44 / 3 ;
return V_33 <= V_173 ;
}
static T_4 unsigned long
F_147 ( unsigned long V_16 , struct V_2 * V_2 ,
struct V_3 * V_4 , int V_33 , int V_125 )
{
F_90 ( V_97 ) ;
unsigned long V_106 ;
unsigned long V_102 = 0 ;
unsigned long V_132 ;
unsigned long V_158 ;
unsigned long V_159 ;
while ( F_50 ( F_133 ( V_2 , V_125 , V_4 ) ) ) {
F_148 ( V_174 , V_175 / 10 ) ;
if ( F_149 ( V_49 ) )
return V_21 ;
}
F_22 ( V_33 , V_4 , false ) ;
F_150 () ;
F_48 ( & V_2 -> V_151 ) ;
if ( F_2 ( V_4 ) ) {
V_132 = F_128 ( V_16 ,
& V_97 , & V_106 , V_4 -> V_42 ,
V_4 -> V_39 & V_41 ?
V_127 : V_176 ,
V_2 , 0 , V_125 ) ;
V_2 -> V_177 += V_106 ;
if ( F_134 () )
F_151 ( V_178 , V_2 ,
V_106 ) ;
else
F_151 ( V_179 , V_2 ,
V_106 ) ;
} else {
V_132 = F_152 ( V_16 ,
& V_97 , & V_106 , V_4 -> V_42 ,
V_4 -> V_39 & V_41 ?
V_127 : V_176 ,
V_2 , V_4 -> V_5 ,
0 , V_125 ) ;
}
if ( V_132 == 0 ) {
F_56 ( & V_2 -> V_151 ) ;
return 0 ;
}
F_144 ( V_2 , V_4 , & V_158 , & V_159 , & V_97 ) ;
F_56 ( & V_2 -> V_151 ) ;
V_102 = F_89 ( & V_97 , V_2 , V_4 ) ;
if ( F_146 ( V_132 , V_102 , V_33 , V_4 ) ) {
F_22 ( V_33 , V_4 , true ) ;
V_102 += F_89 ( & V_97 , V_2 , V_4 ) ;
}
F_153 () ;
if ( F_134 () )
F_145 ( V_180 , V_102 ) ;
F_151 ( V_181 , V_2 , V_102 ) ;
F_135 ( V_2 , V_4 , V_158 , V_159 , & V_97 ) ;
F_154 ( V_2 -> V_182 -> V_183 ,
F_155 ( V_2 ) ,
V_106 , V_102 ,
V_33 ,
F_156 ( V_125 , V_4 -> V_39 ) ) ;
return V_102 ;
}
static void F_157 ( struct V_2 * V_2 ,
struct V_92 * V_13 ,
enum V_7 V_8 )
{
unsigned long V_184 = 0 ;
struct V_94 V_160 ;
struct V_46 * V_46 ;
F_83 ( & V_160 , 1 ) ;
while ( ! F_91 ( V_13 ) ) {
V_46 = F_92 ( V_13 ) ;
F_65 ( F_66 ( V_46 ) ) ;
F_137 ( V_46 ) ;
F_115 ( & V_46 -> V_8 , & V_2 -> V_8 [ V_8 ] . V_13 ) ;
F_158 ( V_46 , V_8 ) ;
V_184 += F_117 ( V_46 ) ;
if ( ! F_85 ( & V_160 , V_46 ) || F_91 ( V_13 ) ) {
F_56 ( & V_2 -> V_151 ) ;
if ( V_185 )
F_159 ( & V_160 ) ;
F_141 ( & V_160 ) ;
F_48 ( & V_2 -> V_151 ) ;
}
}
F_142 ( V_2 , V_9 + V_8 , V_184 ) ;
if ( ! F_139 ( V_8 ) )
F_145 ( V_164 , V_184 ) ;
}
static void F_160 ( unsigned long V_186 , struct V_2 * V_2 ,
struct V_3 * V_4 , int V_33 , int V_125 )
{
unsigned long V_132 ;
unsigned long V_187 ;
unsigned long V_86 ;
F_90 ( V_188 ) ;
F_90 ( V_189 ) ;
F_90 ( V_190 ) ;
struct V_46 * V_46 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
unsigned long V_191 = 0 ;
F_150 () ;
F_48 ( & V_2 -> V_151 ) ;
if ( F_2 ( V_4 ) ) {
V_132 = F_128 ( V_186 , & V_188 ,
& V_187 , V_4 -> V_42 ,
V_192 , V_2 ,
1 , V_125 ) ;
V_2 -> V_177 += V_187 ;
} else {
V_132 = F_152 ( V_186 , & V_188 ,
& V_187 , V_4 -> V_42 ,
V_192 , V_2 ,
V_4 -> V_5 , 1 , V_125 ) ;
}
V_6 -> V_171 [ V_125 ] += V_132 ;
F_151 ( V_193 , V_2 , V_187 ) ;
if ( V_125 )
F_142 ( V_2 , V_165 , - V_132 ) ;
else
F_142 ( V_2 , V_168 , - V_132 ) ;
F_142 ( V_2 , V_157 + V_125 , V_132 ) ;
F_56 ( & V_2 -> V_151 ) ;
while ( ! F_91 ( & V_188 ) ) {
F_20 () ;
V_46 = F_92 ( & V_188 ) ;
F_12 ( & V_46 -> V_8 ) ;
if ( F_50 ( ! F_68 ( V_46 , NULL ) ) ) {
F_62 ( V_46 ) ;
continue;
}
if ( F_77 ( V_46 , 0 , V_4 -> V_5 , & V_86 ) ) {
V_191 += F_117 ( V_46 ) ;
if ( ( V_86 & V_194 ) && F_109 ( V_46 ) ) {
F_102 ( & V_46 -> V_8 , & V_189 ) ;
continue;
}
}
F_130 ( V_46 ) ;
F_102 ( & V_46 -> V_8 , & V_190 ) ;
}
F_48 ( & V_2 -> V_151 ) ;
V_6 -> V_161 [ V_125 ] += V_191 ;
F_157 ( V_2 , & V_189 ,
V_146 + V_125 * V_147 ) ;
F_157 ( V_2 , & V_190 ,
V_145 + V_125 * V_147 ) ;
F_142 ( V_2 , V_157 + V_125 , - V_132 ) ;
F_56 ( & V_2 -> V_151 ) ;
}
static int F_161 ( struct V_2 * V_2 )
{
unsigned long V_77 , V_152 ;
V_77 = F_6 ( V_2 , V_168 ) ;
V_152 = F_6 ( V_2 , V_156 ) ;
if ( V_152 * V_2 -> V_195 < V_77 )
return 1 ;
return 0 ;
}
static int F_162 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
int V_196 ;
if ( ! V_197 )
return 0 ;
if ( F_2 ( V_4 ) )
V_196 = F_161 ( V_2 ) ;
else
V_196 = F_163 ( V_4 -> V_5 ) ;
return V_196 ;
}
static inline int F_162 ( struct V_2 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_164 ( struct V_2 * V_2 )
{
unsigned long V_77 , V_152 ;
V_77 = F_6 ( V_2 , V_165 ) ;
V_152 = F_6 ( V_2 , V_154 ) ;
return ( V_77 > V_152 ) ;
}
static int F_165 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
int V_196 ;
if ( F_2 ( V_4 ) )
V_196 = F_164 ( V_2 ) ;
else
V_196 = F_166 ( V_4 -> V_5 ) ;
return V_196 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_125 )
{
if ( V_125 )
return F_165 ( V_2 , V_4 ) ;
else
return F_162 ( V_2 , V_4 ) ;
}
static unsigned long F_168 ( enum V_7 V_8 , unsigned long V_16 ,
struct V_2 * V_2 , struct V_3 * V_4 , int V_33 )
{
int V_125 = F_140 ( V_8 ) ;
if ( F_139 ( V_8 ) ) {
if ( F_167 ( V_2 , V_4 , V_125 ) )
F_160 ( V_16 , V_2 , V_4 , V_33 , V_125 ) ;
return 0 ;
}
return F_147 ( V_16 , V_2 , V_4 , V_33 , V_125 ) ;
}
static void F_169 ( struct V_2 * V_2 , struct V_3 * V_4 ,
unsigned long * V_11 , int V_33 )
{
unsigned long V_198 , V_125 , free ;
unsigned long V_199 , V_200 ;
unsigned long V_201 , V_202 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
T_5 V_203 [ 2 ] , V_204 ;
enum V_7 V_205 ;
int V_206 = 0 ;
int V_207 = 0 ;
V_198 = F_4 ( V_2 , V_4 , V_169 ) +
F_4 ( V_2 , V_4 , V_170 ) ;
V_125 = F_4 ( V_2 , V_4 , V_166 ) +
F_4 ( V_2 , V_4 , V_167 ) ;
if ( ( ( V_198 + V_125 ) >> V_33 ) < V_21 ) {
if ( F_2 ( V_4 ) && F_134 () )
V_207 = 1 ;
if ( ! F_2 ( V_4 ) )
V_207 = 1 ;
}
if ( ! V_4 -> V_208 || ( V_142 <= 0 ) ) {
V_206 = 1 ;
V_203 [ 0 ] = 0 ;
V_203 [ 1 ] = 1 ;
V_204 = 1 ;
goto V_22;
}
if ( F_2 ( V_4 ) ) {
free = F_6 ( V_2 , V_209 ) ;
if ( F_50 ( V_125 + free <= F_170 ( V_2 ) ) ) {
V_203 [ 0 ] = 1 ;
V_203 [ 1 ] = 0 ;
V_204 = 1 ;
goto V_22;
}
}
V_199 = V_4 -> V_210 ;
V_200 = 200 - V_4 -> V_210 ;
F_48 ( & V_2 -> V_151 ) ;
if ( F_50 ( V_6 -> V_171 [ 0 ] > V_198 / 4 ) ) {
V_6 -> V_171 [ 0 ] /= 2 ;
V_6 -> V_161 [ 0 ] /= 2 ;
}
if ( F_50 ( V_6 -> V_171 [ 1 ] > V_125 / 4 ) ) {
V_6 -> V_171 [ 1 ] /= 2 ;
V_6 -> V_161 [ 1 ] /= 2 ;
}
V_201 = ( V_199 + 1 ) * ( V_6 -> V_171 [ 0 ] + 1 ) ;
V_201 /= V_6 -> V_161 [ 0 ] + 1 ;
V_202 = ( V_200 + 1 ) * ( V_6 -> V_171 [ 1 ] + 1 ) ;
V_202 /= V_6 -> V_161 [ 1 ] + 1 ;
F_56 ( & V_2 -> V_151 ) ;
V_203 [ 0 ] = V_201 ;
V_203 [ 1 ] = V_202 ;
V_204 = V_201 + V_202 + 1 ;
V_22:
F_171 (l) {
int V_125 = F_140 ( V_205 ) ;
unsigned long V_136 ;
V_136 = F_4 ( V_2 , V_4 , V_205 ) ;
if ( V_33 || V_206 ) {
V_136 >>= V_33 ;
V_136 = F_172 ( V_136 * V_203 [ V_125 ] , V_204 ) ;
}
if ( ! V_136 && V_207 ) {
if ( V_125 )
V_136 = V_21 ;
else if ( ! V_206 )
V_136 = V_21 ;
}
V_11 [ V_205 ] = V_136 ;
}
}
static inline bool F_173 ( struct V_2 * V_2 ,
unsigned long V_102 ,
unsigned long V_106 ,
struct V_3 * V_4 )
{
unsigned long V_211 ;
unsigned long V_212 ;
if ( ! ( V_4 -> V_39 & V_40 ) )
return false ;
if ( V_4 -> V_110 & V_213 ) {
if ( ! V_102 && ! V_106 )
return false ;
} else {
if ( ! V_102 )
return false ;
}
V_211 = ( 2UL << V_4 -> V_42 ) ;
V_212 = F_4 ( V_2 , V_4 , V_170 ) +
F_4 ( V_2 , V_4 , V_167 ) ;
if ( V_4 -> V_102 < V_211 &&
V_212 > V_211 )
return true ;
switch ( F_174 ( V_2 , V_4 -> V_42 ) ) {
case V_214 :
case V_215 :
return false ;
default:
return true ;
}
}
static void F_175 ( int V_33 , struct V_2 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_11 [ V_163 ] ;
unsigned long V_16 ;
enum V_7 V_205 ;
unsigned long V_102 , V_106 ;
unsigned long V_216 = V_4 -> V_216 ;
V_217:
V_102 = 0 ;
V_106 = V_4 -> V_106 ;
F_169 ( V_2 , V_4 , V_11 , V_33 ) ;
while ( V_11 [ V_170 ] || V_11 [ V_166 ] ||
V_11 [ V_167 ] ) {
F_171 (l) {
if ( V_11 [ V_205 ] ) {
V_16 = F_176 (unsigned long,
nr[l], SWAP_CLUSTER_MAX) ;
V_11 [ V_205 ] -= V_16 ;
V_102 += F_168 ( V_205 , V_16 ,
V_2 , V_4 , V_33 ) ;
}
}
if ( V_102 >= V_216 && V_33 < V_44 )
break;
}
V_4 -> V_102 += V_102 ;
if ( F_162 ( V_2 , V_4 ) )
F_160 ( V_21 , V_2 , V_4 , V_33 , 0 ) ;
if ( F_173 ( V_2 , V_102 ,
V_4 -> V_106 - V_106 , V_4 ) )
goto V_217;
F_177 ( V_4 -> V_110 ) ;
}
static void F_178 ( int V_33 , struct V_218 * V_218 ,
struct V_3 * V_4 )
{
struct V_219 * V_144 ;
struct V_2 * V_2 ;
unsigned long V_220 ;
unsigned long V_221 ;
F_179 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_180 ( V_2 ) )
continue;
if ( F_2 ( V_4 ) ) {
if ( ! F_181 ( V_2 , V_222 ) )
continue;
if ( V_2 -> V_223 && V_33 != V_44 )
continue;
V_221 = 0 ;
V_220 = F_182 ( V_2 ,
V_4 -> V_42 , V_4 -> V_110 ,
& V_221 ) ;
V_4 -> V_102 += V_220 ;
V_4 -> V_106 += V_221 ;
}
F_175 ( V_33 , V_2 , V_4 ) ;
}
}
static bool F_183 ( struct V_2 * V_2 )
{
return V_2 -> V_177 < F_184 ( V_2 ) * 6 ;
}
static bool V_223 ( struct V_218 * V_218 ,
struct V_3 * V_4 )
{
struct V_219 * V_144 ;
struct V_2 * V_2 ;
F_179 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_180 ( V_2 ) )
continue;
if ( ! F_181 ( V_2 , V_222 ) )
continue;
if ( ! V_2 -> V_223 )
return false ;
}
return true ;
}
static unsigned long F_185 ( struct V_218 * V_218 ,
struct V_3 * V_4 ,
struct V_15 * V_17 )
{
int V_33 ;
unsigned long V_224 = 0 ;
struct V_225 * V_225 = V_49 -> V_225 ;
struct V_219 * V_144 ;
struct V_2 * V_2 ;
unsigned long V_226 ;
F_186 () ;
F_187 () ;
if ( F_2 ( V_4 ) )
F_75 ( V_227 ) ;
for ( V_33 = V_44 ; V_33 >= 0 ; V_33 -- ) {
V_4 -> V_106 = 0 ;
if ( ! V_33 )
F_188 ( V_4 -> V_5 ) ;
F_178 ( V_33 , V_218 , V_4 ) ;
if ( F_2 ( V_4 ) ) {
unsigned long V_19 = 0 ;
F_189 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_181 ( V_2 , V_222 ) )
continue;
V_19 += F_184 ( V_2 ) ;
}
F_14 ( V_17 , V_4 -> V_106 , V_19 ) ;
if ( V_225 ) {
V_4 -> V_102 += V_225 -> V_228 ;
V_225 -> V_228 = 0 ;
}
}
V_224 += V_4 -> V_106 ;
if ( V_4 -> V_102 >= V_4 -> V_216 )
goto V_22;
V_226 = V_4 -> V_216 + V_4 -> V_216 / 2 ;
if ( V_224 > V_226 ) {
F_190 ( V_229 ? 0 : V_224 ) ;
V_4 -> V_120 = 1 ;
}
if ( ! V_4 -> V_230 && V_4 -> V_106 &&
V_33 < V_44 - 2 ) {
struct V_2 * V_231 ;
F_191 ( V_218 , F_192 ( V_4 -> V_110 ) ,
& V_232 ,
& V_231 ) ;
F_193 ( V_231 , V_174 , V_175 / 10 ) ;
}
}
V_22:
F_194 () ;
F_195 () ;
if ( V_4 -> V_102 )
return V_4 -> V_102 ;
if ( V_233 )
return 0 ;
if ( F_2 ( V_4 ) && ! V_223 ( V_218 , V_4 ) )
return 1 ;
return 0 ;
}
unsigned long F_196 ( struct V_218 * V_218 , int V_42 ,
T_6 V_110 , T_7 * V_234 )
{
unsigned long V_102 ;
struct V_3 V_4 = {
. V_110 = V_110 ,
. V_120 = ! V_229 ,
. V_216 = V_21 ,
. V_108 = 1 ,
. V_208 = 1 ,
. V_210 = V_235 ,
. V_42 = V_42 ,
. V_5 = NULL ,
. V_234 = V_234 ,
} ;
struct V_15 V_17 = {
. V_110 = V_4 . V_110 ,
} ;
F_197 ( V_42 ,
V_4 . V_120 ,
V_110 ) ;
V_102 = F_185 ( V_218 , & V_4 , & V_17 ) ;
F_198 ( V_102 ) ;
return V_102 ;
}
unsigned long F_199 ( struct V_5 * V_236 ,
T_6 V_110 , bool V_206 ,
unsigned int V_210 ,
struct V_2 * V_2 ,
unsigned long * V_106 )
{
struct V_3 V_4 = {
. V_106 = 0 ,
. V_216 = V_21 ,
. V_120 = ! V_229 ,
. V_108 = 1 ,
. V_208 = ! V_206 ,
. V_210 = V_210 ,
. V_42 = 0 ,
. V_5 = V_236 ,
} ;
V_4 . V_110 = ( V_110 & V_237 ) |
( V_238 & ~ V_237 ) ;
F_200 ( 0 ,
V_4 . V_120 ,
V_4 . V_110 ) ;
F_175 ( 0 , V_2 , & V_4 ) ;
F_201 ( V_4 . V_102 ) ;
* V_106 = V_4 . V_106 ;
return V_4 . V_102 ;
}
unsigned long F_202 ( struct V_5 * V_239 ,
T_6 V_110 ,
bool V_206 ,
unsigned int V_210 )
{
struct V_218 * V_218 ;
unsigned long V_102 ;
int V_240 ;
struct V_3 V_4 = {
. V_120 = ! V_229 ,
. V_108 = 1 ,
. V_208 = ! V_206 ,
. V_216 = V_21 ,
. V_210 = V_210 ,
. V_42 = 0 ,
. V_5 = V_239 ,
. V_234 = NULL ,
. V_110 = ( V_110 & V_237 ) |
( V_238 & ~ V_237 ) ,
} ;
struct V_15 V_17 = {
. V_110 = V_4 . V_110 ,
} ;
V_240 = F_203 ( V_239 ) ;
V_218 = F_204 ( V_240 ) -> V_241 ;
F_205 ( 0 ,
V_4 . V_120 ,
V_4 . V_110 ) ;
V_102 = F_185 ( V_218 , & V_4 , & V_17 ) ;
F_206 ( V_102 ) ;
return V_102 ;
}
static bool F_207 ( T_8 * V_242 , unsigned long V_243 ,
int V_244 )
{
unsigned long V_245 = 0 ;
int V_246 ;
for ( V_246 = 0 ; V_246 <= V_244 ; V_246 ++ )
V_245 += V_242 -> V_247 [ V_246 ] . V_245 ;
return V_243 >= ( V_245 >> 2 ) ;
}
static bool F_208 ( T_8 * V_242 , int V_42 , long V_248 ,
int V_244 )
{
int V_246 ;
unsigned long V_249 = 0 ;
bool V_250 = true ;
if ( V_248 )
return true ;
for ( V_246 = 0 ; V_246 <= V_244 ; V_246 ++ ) {
struct V_2 * V_2 = V_242 -> V_247 + V_246 ;
if ( ! F_180 ( V_2 ) )
continue;
if ( V_2 -> V_223 ) {
V_249 += V_2 -> V_245 ;
continue;
}
if ( ! F_209 ( V_2 , V_42 , F_170 ( V_2 ) ,
V_246 , 0 ) )
V_250 = false ;
else
V_249 += V_2 -> V_245 ;
}
if ( V_42 )
return ! F_207 ( V_242 , V_249 , V_244 ) ;
else
return ! V_250 ;
}
static unsigned long F_210 ( T_8 * V_242 , int V_42 ,
int * V_244 )
{
int V_250 ;
unsigned long V_249 ;
int V_33 ;
int V_246 ;
int V_251 = 0 ;
unsigned long V_224 ;
struct V_225 * V_225 = V_49 -> V_225 ;
unsigned long V_220 ;
unsigned long V_221 ;
struct V_3 V_4 = {
. V_110 = V_222 ,
. V_108 = 1 ,
. V_208 = 1 ,
. V_216 = V_252 ,
. V_210 = V_235 ,
. V_42 = V_42 ,
. V_5 = NULL ,
} ;
struct V_15 V_17 = {
. V_110 = V_4 . V_110 ,
} ;
V_253:
V_224 = 0 ;
V_4 . V_102 = 0 ;
V_4 . V_120 = ! V_229 ;
F_75 ( V_254 ) ;
for ( V_33 = V_44 ; V_33 >= 0 ; V_33 -- ) {
unsigned long V_19 = 0 ;
int V_255 = 0 ;
if ( ! V_33 )
F_188 ( NULL ) ;
V_250 = 1 ;
V_249 = 0 ;
for ( V_246 = V_242 -> V_256 - 1 ; V_246 >= 0 ; V_246 -- ) {
struct V_2 * V_2 = V_242 -> V_247 + V_246 ;
if ( ! F_180 ( V_2 ) )
continue;
if ( V_2 -> V_223 && V_33 != V_44 )
continue;
if ( F_162 ( V_2 , & V_4 ) )
F_160 ( V_21 , V_2 ,
& V_4 , V_33 , 0 ) ;
if ( ! F_209 ( V_2 , V_42 ,
F_170 ( V_2 ) , 0 , 0 ) ) {
V_251 = V_246 ;
break;
}
}
if ( V_246 < 0 )
goto V_22;
for ( V_246 = 0 ; V_246 <= V_251 ; V_246 ++ ) {
struct V_2 * V_2 = V_242 -> V_247 + V_246 ;
V_19 += F_184 ( V_2 ) ;
}
for ( V_246 = 0 ; V_246 <= V_251 ; V_246 ++ ) {
struct V_2 * V_2 = V_242 -> V_247 + V_246 ;
int V_257 ;
unsigned long V_258 ;
if ( ! F_180 ( V_2 ) )
continue;
if ( V_2 -> V_223 && V_33 != V_44 )
continue;
V_4 . V_106 = 0 ;
V_221 = 0 ;
V_220 = F_182 ( V_2 ,
V_42 , V_4 . V_110 ,
& V_221 ) ;
V_4 . V_102 += V_220 ;
V_224 += V_221 ;
V_258 = F_211 ( F_212 ( V_2 ) ,
( V_2 -> V_245 +
V_259 - 1 ) /
V_259 ) ;
if ( ! F_209 ( V_2 , V_42 ,
F_170 ( V_2 ) + V_258 ,
V_251 , 0 ) ) {
F_175 ( V_33 , V_2 , & V_4 ) ;
V_225 -> V_228 = 0 ;
V_257 = F_14 ( & V_17 , V_4 . V_106 , V_19 ) ;
V_4 . V_102 += V_225 -> V_228 ;
V_224 += V_4 . V_106 ;
if ( V_257 == 0 && ! F_183 ( V_2 ) )
V_2 -> V_223 = 1 ;
}
if ( V_224 > V_21 * 2 &&
V_224 > V_4 . V_102 + V_4 . V_102 / 2 )
V_4 . V_120 = 1 ;
if ( V_2 -> V_223 ) {
if ( V_251 && V_251 == V_246 )
V_251 -- ;
continue;
}
if ( ! F_209 ( V_2 , V_42 ,
F_170 ( V_2 ) , V_251 , 0 ) ) {
V_250 = 0 ;
if ( ! F_209 ( V_2 , V_42 ,
F_213 ( V_2 ) , V_251 , 0 ) )
V_255 = 1 ;
} else {
F_214 ( V_2 , V_122 ) ;
if ( V_246 <= * V_244 )
V_249 += V_2 -> V_245 ;
}
}
if ( V_250 || ( V_42 && F_207 ( V_242 , V_249 , * V_244 ) ) )
break;
if ( V_224 && ( V_33 < V_44 - 2 ) ) {
if ( V_255 )
F_75 ( V_260 ) ;
else
F_148 ( V_174 , V_175 / 10 ) ;
}
if ( V_4 . V_102 >= V_21 )
break;
}
V_22:
if ( ! ( V_250 || ( V_42 && F_207 ( V_242 , V_249 , * V_244 ) ) ) ) {
F_20 () ;
F_215 () ;
if ( V_4 . V_102 < V_21 )
V_42 = V_4 . V_42 = 0 ;
goto V_253;
}
if ( V_42 ) {
for ( V_246 = 0 ; V_246 <= V_251 ; V_246 ++ ) {
struct V_2 * V_2 = V_242 -> V_247 + V_246 ;
if ( ! F_180 ( V_2 ) )
continue;
if ( V_2 -> V_223 && V_33 != V_44 )
continue;
if ( ! F_216 ( V_2 , 0 ,
F_170 ( V_2 ) , 0 , 0 ) ) {
V_42 = V_4 . V_42 = 0 ;
goto V_253;
}
F_214 ( V_2 , V_122 ) ;
}
}
* V_244 = V_251 ;
return V_42 ;
}
static void F_217 ( T_8 * V_242 , int V_42 , int V_244 )
{
long V_248 = 0 ;
F_218 ( V_261 ) ;
if ( F_219 ( V_49 ) || F_220 () )
return;
F_221 ( & V_242 -> V_262 , & V_261 , V_263 ) ;
if ( ! F_208 ( V_242 , V_42 , V_248 , V_244 ) ) {
V_248 = F_222 ( V_175 / 10 ) ;
F_223 ( & V_242 -> V_262 , & V_261 ) ;
F_221 ( & V_242 -> V_262 , & V_261 , V_263 ) ;
}
if ( ! F_208 ( V_242 , V_42 , V_248 , V_244 ) ) {
F_224 ( V_242 -> V_183 ) ;
F_225 ( V_242 , V_264 ) ;
F_226 () ;
F_225 ( V_242 , V_265 ) ;
} else {
if ( V_248 )
F_75 ( V_266 ) ;
else
F_75 ( V_267 ) ;
}
F_223 ( & V_242 -> V_262 , & V_261 ) ;
}
static int F_227 ( void * V_268 )
{
unsigned long V_42 , V_269 ;
int V_244 , V_270 ;
T_8 * V_242 = ( T_8 * ) V_268 ;
struct V_271 * V_272 = V_49 ;
struct V_225 V_225 = {
. V_228 = 0 ,
} ;
const struct V_273 * V_273 = F_228 ( V_242 -> V_183 ) ;
F_229 ( V_222 ) ;
if ( ! F_230 ( V_273 ) )
F_231 ( V_272 , V_273 ) ;
V_49 -> V_225 = & V_225 ;
V_272 -> V_50 |= V_274 | V_51 | V_275 ;
F_232 () ;
V_42 = V_269 = 0 ;
V_244 = V_270 = V_242 -> V_256 - 1 ;
for ( ; ; ) {
int V_20 ;
if ( V_244 >= V_270 && V_42 == V_269 ) {
V_269 = V_242 -> V_276 ;
V_270 = V_242 -> V_244 ;
V_242 -> V_276 = 0 ;
V_242 -> V_244 = V_242 -> V_256 - 1 ;
}
if ( V_42 < V_269 || V_244 > V_270 ) {
V_42 = V_269 ;
V_244 = V_270 ;
} else {
F_217 ( V_242 , V_42 , V_244 ) ;
V_42 = V_242 -> V_276 ;
V_244 = V_242 -> V_244 ;
V_242 -> V_276 = 0 ;
V_242 -> V_244 = V_242 -> V_256 - 1 ;
}
V_20 = F_215 () ;
if ( F_220 () )
break;
if ( ! V_20 ) {
F_233 ( V_242 -> V_183 , V_42 ) ;
V_42 = F_210 ( V_242 , V_42 , & V_244 ) ;
}
}
return 0 ;
}
void F_234 ( struct V_2 * V_2 , int V_42 , enum V_277 V_244 )
{
T_8 * V_242 ;
if ( ! F_180 ( V_2 ) )
return;
if ( ! F_181 ( V_2 , V_222 ) )
return;
V_242 = V_2 -> V_182 ;
if ( V_242 -> V_276 < V_42 ) {
V_242 -> V_276 = V_42 ;
V_242 -> V_244 = F_211 ( V_242 -> V_244 , V_244 ) ;
}
if ( ! F_235 ( & V_242 -> V_262 ) )
return;
if ( F_209 ( V_2 , V_42 , F_212 ( V_2 ) , 0 , 0 ) )
return;
F_236 ( V_242 -> V_183 , F_155 ( V_2 ) , V_42 ) ;
F_237 ( & V_242 -> V_262 ) ;
}
unsigned long F_238 ( void )
{
int V_11 ;
V_11 = F_239 ( V_165 ) +
F_239 ( V_154 ) ;
if ( V_142 > 0 )
V_11 += F_239 ( V_168 ) +
F_239 ( V_156 ) ;
return V_11 ;
}
unsigned long F_184 ( struct V_2 * V_2 )
{
int V_11 ;
V_11 = F_6 ( V_2 , V_165 ) +
F_6 ( V_2 , V_154 ) ;
if ( V_142 > 0 )
V_11 += F_6 ( V_2 , V_168 ) +
F_6 ( V_2 , V_156 ) ;
return V_11 ;
}
unsigned long F_240 ( unsigned long V_216 )
{
struct V_225 V_225 ;
struct V_3 V_4 = {
. V_110 = V_238 ,
. V_208 = 1 ,
. V_108 = 1 ,
. V_120 = 1 ,
. V_216 = V_216 ,
. V_230 = 1 ,
. V_210 = V_235 ,
. V_42 = 0 ,
} ;
struct V_15 V_17 = {
. V_110 = V_4 . V_110 ,
} ;
struct V_218 * V_218 = F_241 ( F_242 () , V_4 . V_110 ) ;
struct V_271 * V_268 = V_49 ;
unsigned long V_102 ;
V_268 -> V_50 |= V_274 ;
F_229 ( V_4 . V_110 ) ;
V_225 . V_228 = 0 ;
V_268 -> V_225 = & V_225 ;
V_102 = F_185 ( V_218 , & V_4 , & V_17 ) ;
V_268 -> V_225 = NULL ;
F_243 () ;
V_268 -> V_50 &= ~ V_274 ;
return V_102 ;
}
static int T_9 F_244 ( struct V_278 * V_279 ,
unsigned long V_280 , void * V_281 )
{
int V_240 ;
if ( V_280 == V_282 || V_280 == V_283 ) {
F_245 (nid, N_HIGH_MEMORY) {
T_8 * V_242 = F_204 ( V_240 ) ;
const struct V_273 * V_284 ;
V_284 = F_228 ( V_242 -> V_183 ) ;
if ( F_246 ( V_285 , V_284 ) < V_286 )
F_231 ( V_242 -> F_227 , V_284 ) ;
}
}
return V_287 ;
}
int F_247 ( int V_240 )
{
T_8 * V_242 = F_204 ( V_240 ) ;
int V_20 = 0 ;
if ( V_242 -> F_227 )
return 0 ;
V_242 -> F_227 = F_248 ( F_227 , V_242 , L_4 , V_240 ) ;
if ( F_249 ( V_242 -> F_227 ) ) {
F_46 ( V_288 == V_289 ) ;
F_18 ( L_5 , V_240 ) ;
V_20 = - 1 ;
}
return V_20 ;
}
void F_250 ( int V_240 )
{
struct V_271 * F_227 = F_204 ( V_240 ) -> F_227 ;
if ( F_227 )
F_251 ( F_227 ) ;
}
static int T_10 F_252 ( void )
{
int V_240 ;
F_253 () ;
F_245 (nid, N_HIGH_MEMORY)
F_247 ( V_240 ) ;
F_254 ( F_244 , 0 ) ;
return 0 ;
}
static inline unsigned long F_255 ( struct V_2 * V_2 )
{
unsigned long V_290 = F_6 ( V_2 , V_291 ) ;
unsigned long V_292 = F_6 ( V_2 , V_154 ) +
F_6 ( V_2 , V_165 ) ;
return ( V_292 > V_290 ) ? ( V_292 - V_290 ) : 0 ;
}
static long F_256 ( struct V_2 * V_2 )
{
long V_293 ;
long V_23 = 0 ;
if ( V_294 & V_295 )
V_293 = F_6 ( V_2 , V_296 ) ;
else
V_293 = F_255 ( V_2 ) ;
if ( ! ( V_294 & V_297 ) )
V_23 += F_6 ( V_2 , V_298 ) ;
if ( F_50 ( V_23 > V_293 ) )
V_23 = V_293 ;
return V_293 - V_23 ;
}
static int F_257 ( struct V_2 * V_2 , T_6 V_110 , unsigned int V_42 )
{
const unsigned long V_186 = 1 << V_42 ;
struct V_271 * V_268 = V_49 ;
struct V_225 V_225 ;
int V_33 ;
struct V_3 V_4 = {
. V_120 = ! ! ( V_294 & V_297 ) ,
. V_108 = ! ! ( V_294 & V_295 ) ,
. V_208 = 1 ,
. V_216 = F_258 (unsigned long, nr_pages,
SWAP_CLUSTER_MAX) ,
. V_110 = V_110 ,
. V_210 = V_235 ,
. V_42 = V_42 ,
} ;
struct V_15 V_17 = {
. V_110 = V_4 . V_110 ,
} ;
unsigned long V_299 , V_300 ;
F_20 () ;
V_268 -> V_50 |= V_274 | V_51 ;
F_229 ( V_110 ) ;
V_225 . V_228 = 0 ;
V_268 -> V_225 = & V_225 ;
if ( F_256 ( V_2 ) > V_2 -> V_301 ) {
V_33 = V_302 ;
do {
F_175 ( V_33 , V_2 , & V_4 ) ;
V_33 -- ;
} while ( V_33 >= 0 && V_4 . V_102 < V_186 );
}
V_299 = F_6 ( V_2 , V_303 ) ;
if ( V_299 > V_2 -> V_304 ) {
for (; ; ) {
unsigned long V_19 = F_184 ( V_2 ) ;
if ( ! F_14 ( & V_17 , V_4 . V_106 , V_19 ) )
break;
V_300 = F_6 ( V_2 ,
V_303 ) ;
if ( V_300 + V_186 <= V_299 )
break;
}
V_300 = F_6 ( V_2 , V_303 ) ;
if ( V_300 < V_299 )
V_4 . V_102 += V_299 - V_300 ;
}
V_268 -> V_225 = NULL ;
V_49 -> V_50 &= ~ ( V_274 | V_51 ) ;
F_243 () ;
return V_4 . V_102 >= V_186 ;
}
int F_259 ( struct V_2 * V_2 , T_6 V_110 , unsigned int V_42 )
{
int V_183 ;
int V_20 ;
if ( F_256 ( V_2 ) <= V_2 -> V_301 &&
F_6 ( V_2 , V_303 ) <= V_2 -> V_304 )
return V_305 ;
if ( V_2 -> V_223 )
return V_305 ;
if ( ! ( V_110 & V_306 ) || ( V_49 -> V_50 & V_274 ) )
return V_307 ;
V_183 = F_260 ( V_2 ) ;
if ( F_261 ( V_183 , V_308 ) && V_183 != F_242 () )
return V_307 ;
if ( F_262 ( V_2 , V_309 ) )
return V_307 ;
V_20 = F_257 ( V_2 , V_110 , V_42 ) ;
F_214 ( V_2 , V_309 ) ;
if ( ! V_20 )
F_75 ( V_310 ) ;
return V_20 ;
}
int F_68 ( struct V_46 * V_46 , struct V_311 * V_312 )
{
if ( F_263 ( F_31 ( V_46 ) ) )
return 0 ;
if ( F_264 ( V_46 ) || ( V_312 && F_265 ( V_312 , V_46 ) ) )
return 0 ;
return 1 ;
}
static void F_266 ( struct V_46 * V_46 , struct V_2 * V_2 )
{
F_65 ( F_94 ( V_46 ) ) ;
V_313:
F_67 ( V_46 ) ;
if ( F_68 ( V_46 , NULL ) ) {
enum V_7 V_205 = F_69 ( V_46 ) ;
F_267 ( V_2 , V_314 ) ;
F_115 ( & V_46 -> V_8 , & V_2 -> V_8 [ V_205 ] . V_13 ) ;
F_268 ( V_46 , V_80 , V_205 ) ;
F_269 ( V_2 , V_156 + V_205 ) ;
F_270 ( V_81 ) ;
} else {
F_271 ( V_46 ) ;
F_115 ( & V_46 -> V_8 , & V_2 -> V_8 [ V_80 ] . V_13 ) ;
F_118 ( V_46 , V_80 ) ;
if ( F_68 ( V_46 , NULL ) )
goto V_313;
}
}
void F_272 ( struct V_52 * V_53 )
{
T_11 V_315 = 0 ;
T_11 V_316 = ( F_273 ( V_53 -> V_317 ) + V_318 - 1 ) >>
V_319 ;
struct V_2 * V_2 ;
struct V_94 V_160 ;
if ( V_53 -> V_320 == 0 )
return;
F_83 ( & V_160 , 0 ) ;
while ( V_315 < V_316 &&
F_274 ( & V_160 , V_53 , V_315 , V_321 ) ) {
int V_246 ;
int V_322 = 0 ;
V_2 = NULL ;
for ( V_246 = 0 ; V_246 < F_275 ( & V_160 ) ; V_246 ++ ) {
struct V_46 * V_46 = V_160 . V_323 [ V_246 ] ;
T_11 V_324 = V_46 -> V_325 ;
struct V_2 * V_326 = F_95 ( V_46 ) ;
V_322 ++ ;
if ( V_324 > V_315 )
V_315 = V_324 ;
V_315 ++ ;
if ( V_326 != V_2 ) {
if ( V_2 )
F_56 ( & V_2 -> V_151 ) ;
V_2 = V_326 ;
F_48 ( & V_2 -> V_151 ) ;
}
if ( F_66 ( V_46 ) && F_64 ( V_46 ) )
F_266 ( V_46 , V_2 ) ;
}
if ( V_2 )
F_56 ( & V_2 -> V_151 ) ;
F_143 ( & V_160 ) ;
F_19 ( V_327 , V_322 ) ;
}
}
static void F_276 ( struct V_2 * V_2 )
{
struct V_92 * V_328 = & V_2 -> V_8 [ V_80 ] . V_13 ;
unsigned long V_136 ;
unsigned long V_16 = F_6 ( V_2 , V_314 ) ;
while ( V_16 > 0 ) {
unsigned long V_329 = F_211 ( V_16 ,
V_330 ) ;
F_48 ( & V_2 -> V_151 ) ;
for ( V_136 = 0 ; V_136 < V_329 ; V_136 ++ ) {
struct V_46 * V_46 = F_92 ( V_328 ) ;
if ( ! F_93 ( V_46 ) )
continue;
F_114 ( V_46 , V_328 , V_50 ) ;
if ( F_110 ( F_66 ( V_46 ) && F_64 ( V_46 ) ) )
F_266 ( V_46 , V_2 ) ;
F_33 ( V_46 ) ;
}
F_56 ( & V_2 -> V_151 ) ;
V_16 -= V_329 ;
}
}
static void F_277 ( void )
{
struct V_2 * V_2 ;
F_278 (zone) {
F_276 ( V_2 ) ;
}
}
int F_279 ( struct V_331 * V_332 , int V_333 ,
void T_12 * V_334 ,
T_13 * V_335 , T_14 * V_336 )
{
F_280 ( V_332 , V_333 , V_334 , V_335 , V_336 ) ;
if ( V_333 && * ( unsigned long * ) V_332 -> V_337 )
F_277 () ;
V_338 = 0 ;
return 0 ;
}
static T_15 F_281 ( struct V_339 * V_340 ,
struct V_341 * V_342 ,
char * V_343 )
{
return sprintf ( V_343 , L_6 ) ;
}
static T_15 F_282 ( struct V_339 * V_340 ,
struct V_341 * V_342 ,
const char * V_343 , T_13 V_148 )
{
struct V_2 * V_247 = F_204 ( V_340 -> V_344 ) -> V_247 ;
struct V_2 * V_2 ;
unsigned long V_60 ;
unsigned long V_345 = F_283 ( V_343 , 10 , & V_60 ) ;
if ( ! V_345 )
return 1 ;
for ( V_2 = V_247 ; V_2 - V_247 < V_346 ; ++ V_2 ) {
if ( ! F_180 ( V_2 ) )
continue;
F_276 ( V_2 ) ;
}
return 1 ;
}
int F_284 ( struct V_347 * V_347 )
{
return F_285 ( & V_347 -> V_348 , & V_349 ) ;
}
void F_286 ( struct V_347 * V_347 )
{
F_287 ( & V_347 -> V_348 , & V_349 ) ;
}
