static bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static bool F_2 ( struct V_4 * V_5 )
{
return ! V_5 -> V_6 ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return true ;
}
static bool F_2 ( struct V_4 * V_5 )
{
return true ;
}
static struct V_7 * F_3 ( struct V_4 * V_5 )
{
if ( ! F_2 ( V_5 ) )
return F_4 ( V_5 -> V_6 , V_5 -> V_8 ) ;
return & V_5 -> V_8 -> V_9 ;
}
static unsigned long F_5 ( struct V_4 * V_5 ,
enum V_10 V_11 )
{
if ( ! F_2 ( V_5 ) )
return F_6 ( V_5 -> V_6 ,
F_7 ( V_5 -> V_8 ) ,
F_8 ( V_5 -> V_8 ) ,
F_9 ( V_11 ) ) ;
return F_10 ( V_5 -> V_8 , V_12 + V_11 ) ;
}
void F_11 ( struct V_13 * V_13 )
{
F_12 ( & V_13 -> V_14 , 0 ) ;
F_13 ( & V_15 ) ;
F_14 ( & V_13 -> V_16 , & V_17 ) ;
F_15 ( & V_15 ) ;
}
void F_16 ( struct V_13 * V_13 )
{
F_13 ( & V_15 ) ;
F_17 ( & V_13 -> V_16 ) ;
F_15 ( & V_15 ) ;
}
static inline int F_18 ( struct V_13 * V_13 ,
struct V_18 * V_2 ,
unsigned long V_19 )
{
V_2 -> V_19 = V_19 ;
return (* V_13 -> V_20 )( V_13 , V_2 ) ;
}
unsigned long F_19 ( struct V_18 * V_20 ,
unsigned long V_21 ,
unsigned long V_22 )
{
struct V_13 * V_13 ;
unsigned long V_23 = 0 ;
if ( V_21 == 0 )
V_21 = V_24 ;
if ( ! F_20 ( & V_15 ) ) {
V_23 = 1 ;
goto V_25;
}
F_21 (shrinker, &shrinker_list, list) {
unsigned long long V_26 ;
long V_27 ;
long V_28 ;
int V_29 = 0 ;
long V_30 ;
long V_31 ;
long V_32 = V_13 -> V_33 ? V_13 -> V_33
: V_34 ;
V_28 = F_18 ( V_13 , V_20 , 0 ) ;
if ( V_28 <= 0 )
continue;
V_30 = F_22 ( & V_13 -> V_14 , 0 ) ;
V_27 = V_30 ;
V_26 = ( 4 * V_21 ) / V_13 -> V_35 ;
V_26 *= V_28 ;
F_23 ( V_26 , V_22 + 1 ) ;
V_27 += V_26 ;
if ( V_27 < 0 ) {
F_24 ( V_36 L_1
L_2 ,
V_13 -> V_20 , V_27 ) ;
V_27 = V_28 ;
}
if ( V_26 < V_28 / 4 )
V_27 = F_25 ( V_27 , V_28 / 2 ) ;
if ( V_27 > V_28 * 2 )
V_27 = V_28 * 2 ;
F_26 ( V_13 , V_20 , V_30 ,
V_21 , V_22 ,
V_28 , V_26 , V_27 ) ;
while ( V_27 >= V_32 ) {
int V_37 ;
V_37 = F_18 ( V_13 , V_20 , 0 ) ;
V_29 = F_18 ( V_13 , V_20 ,
V_32 ) ;
if ( V_29 == - 1 )
break;
if ( V_29 < V_37 )
V_23 += V_37 - V_29 ;
F_27 ( V_38 , V_32 ) ;
V_27 -= V_32 ;
F_28 () ;
}
if ( V_27 > 0 )
V_31 = F_29 ( V_27 ,
& V_13 -> V_14 ) ;
else
V_31 = F_30 ( & V_13 -> V_14 ) ;
F_31 ( V_13 , V_29 , V_30 , V_31 ) ;
}
F_32 ( & V_15 ) ;
V_25:
F_28 () ;
return V_23 ;
}
static void F_33 ( int V_39 , struct V_1 * V_2 ,
bool V_40 )
{
T_1 V_41 = V_40 ? V_42 : V_43 ;
if ( V_44 )
V_2 -> V_45 = V_46 ;
else
V_2 -> V_45 = V_47 ;
if ( V_2 -> V_48 > V_49 )
V_2 -> V_45 |= V_41 ;
else if ( V_2 -> V_48 && V_39 < V_50 - 2 )
V_2 -> V_45 |= V_41 ;
else
V_2 -> V_45 = V_51 | V_43 ;
}
static void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_45 = V_51 | V_43 ;
}
static inline int F_35 ( struct V_52 * V_52 )
{
return F_36 ( V_52 ) - F_37 ( V_52 ) == 2 ;
}
static int F_38 ( struct V_53 * V_54 ,
struct V_1 * V_2 )
{
if ( V_55 -> V_56 & V_57 )
return 1 ;
if ( ! F_39 ( V_54 ) )
return 1 ;
if ( V_54 == V_55 -> V_53 )
return 1 ;
if ( V_2 -> V_48 > V_49 )
return 1 ;
return 0 ;
}
static void F_40 ( struct V_58 * V_59 ,
struct V_52 * V_52 , int error )
{
F_41 ( V_52 ) ;
if ( F_42 ( V_52 ) == V_59 )
F_43 ( V_59 , error ) ;
F_44 ( V_52 ) ;
}
static T_2 F_45 ( struct V_52 * V_52 , struct V_58 * V_59 ,
struct V_1 * V_2 )
{
if ( ! F_35 ( V_52 ) )
return V_60 ;
if ( ! V_59 ) {
if ( F_37 ( V_52 ) ) {
if ( F_46 ( V_52 ) ) {
F_47 ( V_52 ) ;
F_24 ( L_3 , V_61 ) ;
return V_62 ;
}
}
return V_60 ;
}
if ( V_59 -> V_63 -> V_64 == NULL )
return V_65 ;
if ( ! F_38 ( V_59 -> V_53 , V_2 ) )
return V_60 ;
if ( F_48 ( V_52 ) ) {
int V_66 ;
struct V_67 V_68 = {
. V_69 = V_70 ,
. V_71 = V_24 ,
. V_72 = 0 ,
. V_73 = V_74 ,
. V_75 = 1 ,
} ;
F_49 ( V_52 ) ;
V_66 = V_59 -> V_63 -> V_64 ( V_52 , & V_68 ) ;
if ( V_66 < 0 )
F_40 ( V_59 , V_52 , V_66 ) ;
if ( V_66 == V_76 ) {
F_50 ( V_52 ) ;
return V_65 ;
}
if ( ! F_51 ( V_52 ) ) {
F_50 ( V_52 ) ;
}
F_52 ( V_52 ,
F_53 ( V_52 , V_2 -> V_45 ) ) ;
F_54 ( V_52 , V_77 ) ;
return V_78 ;
}
return V_62 ;
}
static int F_55 ( struct V_58 * V_59 , struct V_52 * V_52 )
{
F_56 ( ! F_57 ( V_52 ) ) ;
F_56 ( V_59 != F_42 ( V_52 ) ) ;
F_58 ( & V_59 -> V_79 ) ;
if ( ! F_59 ( V_52 , 2 ) )
goto V_80;
if ( F_60 ( F_61 ( V_52 ) ) ) {
F_62 ( V_52 , 2 ) ;
goto V_80;
}
if ( F_63 ( V_52 ) ) {
T_3 V_81 = { . V_82 = F_64 (page) } ;
F_65 ( V_52 ) ;
F_66 ( & V_59 -> V_79 ) ;
F_67 ( V_81 , V_52 ) ;
} else {
void (* F_68)( struct V_52 * );
F_68 = V_59 -> V_63 -> F_68 ;
F_69 ( V_52 ) ;
F_66 ( & V_59 -> V_79 ) ;
F_70 ( V_52 ) ;
if ( F_68 != NULL )
F_68 ( V_52 ) ;
}
return 1 ;
V_80:
F_66 ( & V_59 -> V_79 ) ;
return 0 ;
}
int F_71 ( struct V_58 * V_59 , struct V_52 * V_52 )
{
if ( F_55 ( V_59 , V_52 ) ) {
F_62 ( V_52 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_72 ( struct V_52 * V_52 )
{
int V_11 ;
int V_83 = ! ! F_73 ( V_52 ) ;
int V_84 = F_74 ( V_52 ) ;
F_75 ( F_76 ( V_52 ) ) ;
V_85:
F_77 ( V_52 ) ;
if ( F_78 ( V_52 , NULL ) ) {
V_11 = V_83 + F_79 ( V_52 ) ;
F_80 ( V_52 , V_11 ) ;
} else {
V_11 = V_86 ;
F_81 ( V_52 ) ;
F_82 () ;
}
if ( V_11 == V_86 && F_78 ( V_52 , NULL ) ) {
if ( ! F_83 ( V_52 ) ) {
F_84 ( V_52 ) ;
goto V_85;
}
}
if ( V_84 && V_11 != V_86 )
F_85 ( V_87 ) ;
else if ( ! V_84 && V_11 == V_86 )
F_85 ( V_88 ) ;
F_84 ( V_52 ) ;
}
static enum V_89 F_86 ( struct V_52 * V_52 ,
struct V_4 * V_5 ,
struct V_1 * V_2 )
{
int V_90 , V_91 ;
unsigned long V_92 ;
V_90 = F_87 ( V_52 , 1 , V_5 -> V_6 , & V_92 ) ;
V_91 = F_88 ( V_52 ) ;
if ( V_2 -> V_45 & V_47 )
return V_93 ;
if ( V_92 & V_94 )
return V_93 ;
if ( V_90 ) {
if ( F_89 ( V_52 ) )
return V_95 ;
F_90 ( V_52 ) ;
if ( V_91 || V_90 > 1 )
return V_95 ;
if ( V_92 & V_96 )
return V_95 ;
return V_97 ;
}
if ( V_91 && ! F_91 ( V_52 ) )
return V_98 ;
return V_93 ;
}
static unsigned long F_92 ( struct V_99 * V_100 ,
struct V_4 * V_5 ,
struct V_1 * V_2 ,
int V_39 ,
unsigned long * V_101 ,
unsigned long * V_102 )
{
F_93 ( V_103 ) ;
F_93 ( V_104 ) ;
int V_105 = 0 ;
unsigned long V_106 = 0 ;
unsigned long V_107 = 0 ;
unsigned long V_108 = 0 ;
unsigned long V_109 = 0 ;
F_28 () ;
while ( ! F_94 ( V_100 ) ) {
enum V_89 V_110 ;
struct V_58 * V_59 ;
struct V_52 * V_52 ;
int V_111 ;
F_28 () ;
V_52 = F_95 ( V_100 ) ;
F_17 ( & V_52 -> V_11 ) ;
if ( ! F_96 ( V_52 ) )
goto V_112;
F_75 ( F_97 ( V_52 ) ) ;
F_75 ( F_98 ( V_52 ) != V_5 -> V_8 ) ;
V_2 -> V_113 ++ ;
if ( F_60 ( ! F_78 ( V_52 , NULL ) ) )
goto V_114;
if ( ! V_2 -> V_115 && F_99 ( V_52 ) )
goto V_116;
if ( F_99 ( V_52 ) || F_63 ( V_52 ) )
V_2 -> V_113 ++ ;
V_111 = ( V_2 -> V_117 & V_118 ) ||
( F_63 ( V_52 ) && ( V_2 -> V_117 & V_119 ) ) ;
if ( F_51 ( V_52 ) ) {
V_109 ++ ;
if ( ( V_2 -> V_45 & V_42 ) &&
V_111 )
F_100 ( V_52 ) ;
else {
F_44 ( V_52 ) ;
goto V_120;
}
}
V_110 = F_86 ( V_52 , V_5 , V_2 ) ;
switch ( V_110 ) {
case V_95 :
goto V_121;
case V_97 :
goto V_116;
case V_93 :
case V_98 :
;
}
if ( F_89 ( V_52 ) && ! F_63 ( V_52 ) ) {
if ( ! ( V_2 -> V_117 & V_119 ) )
goto V_116;
if ( ! F_101 ( V_52 ) )
goto V_121;
V_111 = 1 ;
}
V_59 = F_42 ( V_52 ) ;
if ( F_99 ( V_52 ) && V_59 ) {
switch ( F_102 ( V_52 , V_122 ) ) {
case V_123 :
goto V_121;
case V_124 :
goto V_116;
case V_125 :
goto V_114;
case V_126 :
;
}
}
if ( F_61 ( V_52 ) ) {
V_106 ++ ;
if ( F_103 ( V_52 ) &&
( ! F_104 () || V_39 >= V_50 - 2 ) ) {
F_54 ( V_52 , V_127 ) ;
F_49 ( V_52 ) ;
goto V_116;
}
if ( V_110 == V_98 )
goto V_116;
if ( ! V_111 )
goto V_116;
if ( ! V_2 -> V_128 )
goto V_116;
switch ( F_45 ( V_52 , V_59 , V_2 ) ) {
case V_60 :
V_107 ++ ;
goto V_116;
case V_65 :
goto V_121;
case V_78 :
if ( F_51 ( V_52 ) )
goto V_120;
if ( F_61 ( V_52 ) )
goto V_112;
if ( ! F_96 ( V_52 ) )
goto V_112;
if ( F_61 ( V_52 ) || F_51 ( V_52 ) )
goto V_116;
V_59 = F_42 ( V_52 ) ;
case V_62 :
;
}
}
if ( F_37 ( V_52 ) ) {
if ( ! F_105 ( V_52 , V_2 -> V_117 ) )
goto V_121;
if ( ! V_59 && F_36 ( V_52 ) == 1 ) {
F_44 ( V_52 ) ;
if ( F_106 ( V_52 ) )
goto V_129;
else {
V_108 ++ ;
continue;
}
}
}
if ( ! V_59 || ! F_55 ( V_59 , V_52 ) )
goto V_116;
F_107 ( V_52 ) ;
V_129:
V_108 ++ ;
F_108 ( & V_52 -> V_11 , & V_104 ) ;
continue;
V_114:
if ( F_63 ( V_52 ) )
F_109 ( V_52 ) ;
F_44 ( V_52 ) ;
F_72 ( V_52 ) ;
F_34 ( V_2 ) ;
continue;
V_121:
if ( F_63 ( V_52 ) && F_110 () )
F_109 ( V_52 ) ;
F_75 ( F_97 ( V_52 ) ) ;
F_111 ( V_52 ) ;
V_105 ++ ;
V_116:
F_44 ( V_52 ) ;
V_112:
F_34 ( V_2 ) ;
V_120:
F_108 ( & V_52 -> V_11 , & V_103 ) ;
F_75 ( F_76 ( V_52 ) || F_74 ( V_52 ) ) ;
}
if ( V_106 && V_106 == V_107 && F_1 ( V_2 ) )
F_112 ( V_5 -> V_8 , V_130 ) ;
F_113 ( & V_104 , 1 ) ;
F_114 ( & V_103 , V_100 ) ;
F_27 ( V_131 , V_105 ) ;
* V_101 += V_106 ;
* V_102 += V_109 ;
return V_108 ;
}
int F_115 ( struct V_52 * V_52 , T_4 V_132 , int V_133 )
{
bool V_134 ;
int V_23 = - V_135 ;
if ( ! F_76 ( V_52 ) )
return V_23 ;
V_134 = ( V_132 & ( V_136 | V_137 ) ) ==
( V_136 | V_137 ) ;
if ( ! V_134 && ! F_97 ( V_52 ) != ! ( V_132 & V_136 ) )
return V_23 ;
if ( ! V_134 && ! ! F_103 ( V_52 ) != V_133 )
return V_23 ;
if ( F_74 ( V_52 ) )
return V_23 ;
V_23 = - V_138 ;
if ( V_132 & ( V_139 | V_140 ) ) {
if ( F_51 ( V_52 ) )
return V_23 ;
if ( F_61 ( V_52 ) ) {
struct V_58 * V_59 ;
if ( V_132 & V_139 )
return V_23 ;
V_59 = F_42 ( V_52 ) ;
if ( V_59 && ! V_59 -> V_63 -> V_141 )
return V_23 ;
}
}
if ( ( V_132 & V_142 ) && F_99 ( V_52 ) )
return V_23 ;
if ( F_116 ( F_117 ( V_52 ) ) ) {
F_118 ( V_52 ) ;
V_23 = 0 ;
}
return V_23 ;
}
static unsigned long F_119 ( unsigned long V_19 ,
struct V_4 * V_5 , struct V_99 * V_143 ,
unsigned long * V_113 , struct V_1 * V_2 ,
T_4 V_132 , int V_83 , int V_133 )
{
struct V_144 * V_144 ;
struct V_99 * V_145 ;
unsigned long V_146 = 0 ;
unsigned long V_147 = 0 ;
unsigned long V_148 = 0 ;
unsigned long V_149 = 0 ;
unsigned long V_150 ;
int V_11 = V_151 ;
V_144 = F_120 ( V_5 -> V_8 , V_5 -> V_6 ) ;
if ( V_83 )
V_11 += V_152 ;
if ( V_133 )
V_11 += V_153 ;
V_145 = & V_144 -> V_154 [ V_11 ] ;
for ( V_150 = 0 ; V_150 < V_19 && ! F_94 ( V_145 ) ; V_150 ++ ) {
struct V_52 * V_52 ;
unsigned long V_155 ;
unsigned long V_156 ;
unsigned long V_157 ;
int V_158 ;
V_52 = F_95 ( V_145 ) ;
F_121 ( V_52 , V_145 , V_56 ) ;
F_75 ( ! F_76 ( V_52 ) ) ;
switch ( F_115 ( V_52 , V_132 , V_133 ) ) {
case 0 :
F_122 ( V_52 ) ;
F_123 ( & V_52 -> V_11 , V_143 ) ;
V_146 += F_124 ( V_52 ) ;
break;
case - V_138 :
F_123 ( & V_52 -> V_11 , V_145 ) ;
continue;
default:
F_125 () ;
}
if ( ! V_2 -> V_48 || ! ( V_2 -> V_45 & V_47 ) )
continue;
V_158 = F_126 ( V_52 ) ;
V_157 = F_127 ( V_52 ) ;
V_155 = V_157 & ~ ( ( 1 << V_2 -> V_48 ) - 1 ) ;
V_156 = V_155 + ( 1 << V_2 -> V_48 ) ;
for (; V_155 < V_156 ; V_155 ++ ) {
struct V_52 * V_159 ;
if ( F_60 ( V_155 == V_157 ) )
continue;
if ( F_60 ( ! F_128 ( V_155 ) ) )
break;
V_159 = F_129 ( V_155 ) ;
if ( F_60 ( F_126 ( V_159 ) != V_158 ) )
break;
if ( V_160 <= 0 && F_91 ( V_159 ) &&
! F_63 ( V_159 ) )
break;
if ( F_115 ( V_159 , V_132 , V_133 ) == 0 ) {
unsigned int V_161 ;
F_122 ( V_159 ) ;
F_123 ( & V_159 -> V_11 , V_143 ) ;
V_161 = F_124 ( V_159 ) ;
V_146 += V_161 ;
V_147 += V_161 ;
if ( F_61 ( V_159 ) )
V_148 += V_161 ;
V_150 ++ ;
V_155 += V_161 - 1 ;
} else {
if ( ! F_130 ( V_159 ) &&
! F_131 ( & V_159 -> V_162 ) )
continue;
break;
}
}
if ( V_155 < V_156 )
V_149 ++ ;
}
* V_113 = V_150 ;
F_132 ( V_2 -> V_48 ,
V_19 , V_150 ,
V_146 ,
V_147 , V_148 , V_149 ,
V_132 , V_133 ) ;
return V_146 ;
}
int F_83 ( struct V_52 * V_52 )
{
int V_23 = - V_138 ;
F_75 ( ! F_36 ( V_52 ) ) ;
if ( F_76 ( V_52 ) ) {
struct V_8 * V_8 = F_98 ( V_52 ) ;
F_58 ( & V_8 -> V_163 ) ;
if ( F_76 ( V_52 ) ) {
int V_11 = F_133 ( V_52 ) ;
V_23 = 0 ;
F_134 ( V_52 ) ;
F_118 ( V_52 ) ;
F_135 ( V_8 , V_52 , V_11 ) ;
}
F_66 ( & V_8 -> V_163 ) ;
}
return V_23 ;
}
static int F_136 ( struct V_8 * V_8 , int V_133 ,
struct V_1 * V_2 )
{
unsigned long V_164 , V_165 ;
if ( F_104 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_133 ) {
V_164 = F_10 ( V_8 , V_166 ) ;
V_165 = F_10 ( V_8 , V_167 ) ;
} else {
V_164 = F_10 ( V_8 , V_168 ) ;
V_165 = F_10 ( V_8 , V_169 ) ;
}
return V_165 > V_164 ;
}
static T_5 void
F_137 ( struct V_4 * V_5 ,
struct V_99 * V_100 )
{
struct V_7 * V_9 = F_3 ( V_5 ) ;
struct V_8 * V_8 = V_5 -> V_8 ;
F_93 ( V_170 ) ;
while ( ! F_94 ( V_100 ) ) {
struct V_52 * V_52 = F_95 ( V_100 ) ;
int V_11 ;
F_75 ( F_76 ( V_52 ) ) ;
F_17 ( & V_52 -> V_11 ) ;
if ( F_60 ( ! F_78 ( V_52 , NULL ) ) ) {
F_66 ( & V_8 -> V_163 ) ;
F_72 ( V_52 ) ;
F_58 ( & V_8 -> V_163 ) ;
continue;
}
F_138 ( V_52 ) ;
V_11 = F_133 ( V_52 ) ;
F_139 ( V_8 , V_52 , V_11 ) ;
if ( F_140 ( V_11 ) ) {
int V_133 = F_141 ( V_11 ) ;
int V_171 = F_124 ( V_52 ) ;
V_9 -> V_172 [ V_133 ] += V_171 ;
}
if ( F_106 ( V_52 ) ) {
F_142 ( V_52 ) ;
F_143 ( V_52 ) ;
F_135 ( V_8 , V_52 , V_11 ) ;
if ( F_60 ( F_144 ( V_52 ) ) ) {
F_66 ( & V_8 -> V_163 ) ;
( * F_145 ( V_52 ) ) ( V_52 ) ;
F_58 ( & V_8 -> V_163 ) ;
} else
F_108 ( & V_52 -> V_11 , & V_170 ) ;
}
}
F_114 ( & V_170 , V_100 ) ;
}
static T_5 void
F_146 ( struct V_4 * V_5 ,
struct V_99 * V_100 ,
unsigned long * V_173 ,
unsigned long * V_174 )
{
struct V_8 * V_8 = V_5 -> V_8 ;
unsigned int V_175 [ V_176 ] = { 0 , } ;
unsigned long V_177 = 0 ;
struct V_52 * V_52 ;
int V_11 ;
F_21 (page, page_list, lru) {
int V_171 = F_124 ( V_52 ) ;
V_11 = F_79 ( V_52 ) ;
if ( F_97 ( V_52 ) ) {
V_11 += V_152 ;
F_147 ( V_52 ) ;
V_177 += V_171 ;
}
V_175 [ V_11 ] += V_171 ;
}
F_148 () ;
F_149 ( V_178 , V_177 ) ;
F_150 ( V_8 , V_179 ,
- V_175 [ V_180 ] ) ;
F_150 ( V_8 , V_166 ,
- V_175 [ V_181 ] ) ;
F_150 ( V_8 , V_182 ,
- V_175 [ V_183 ] ) ;
F_150 ( V_8 , V_168 ,
- V_175 [ V_184 ] ) ;
* V_173 = V_175 [ V_183 ] + V_175 [ V_184 ] ;
* V_174 = V_175 [ V_180 ] + V_175 [ V_181 ] ;
F_150 ( V_8 , V_169 , * V_173 ) ;
F_150 ( V_8 , V_167 , * V_174 ) ;
F_151 () ;
}
static inline bool F_152 ( unsigned long V_146 ,
unsigned long V_185 ,
int V_39 ,
struct V_1 * V_2 )
{
int V_186 ;
if ( F_104 () )
return false ;
if ( V_2 -> V_45 & V_51 )
return false ;
if ( V_185 == V_146 )
return false ;
if ( V_2 -> V_48 > V_49 )
V_186 = V_50 ;
else
V_186 = V_50 / 3 ;
return V_39 <= V_186 ;
}
static T_5 unsigned long
F_153 ( unsigned long V_19 , struct V_4 * V_5 ,
struct V_1 * V_2 , int V_39 , int V_133 )
{
F_93 ( V_100 ) ;
unsigned long V_113 ;
unsigned long V_108 = 0 ;
unsigned long V_146 ;
unsigned long V_173 ;
unsigned long V_174 ;
unsigned long V_106 = 0 ;
unsigned long V_109 = 0 ;
T_4 V_187 = V_137 ;
struct V_8 * V_8 = V_5 -> V_8 ;
struct V_7 * V_9 = F_3 ( V_5 ) ;
while ( F_60 ( F_136 ( V_8 , V_133 , V_2 ) ) ) {
F_154 ( V_188 , V_189 / 10 ) ;
if ( F_155 ( V_55 ) )
return V_24 ;
}
F_33 ( V_39 , V_2 , false ) ;
if ( V_2 -> V_45 & V_47 )
V_187 |= V_136 ;
F_156 () ;
if ( ! V_2 -> V_115 )
V_187 |= V_142 ;
if ( ! V_2 -> V_128 )
V_187 |= V_139 ;
F_58 ( & V_8 -> V_163 ) ;
V_146 = F_119 ( V_19 , V_5 , & V_100 , & V_113 ,
V_2 , V_187 , 0 , V_133 ) ;
if ( F_1 ( V_2 ) ) {
V_8 -> V_190 += V_113 ;
if ( F_104 () )
F_157 ( V_191 , V_8 ,
V_113 ) ;
else
F_157 ( V_192 , V_8 ,
V_113 ) ;
}
F_66 ( & V_8 -> V_163 ) ;
if ( V_146 == 0 )
return 0 ;
F_146 ( V_5 , & V_100 , & V_173 , & V_174 ) ;
V_108 = F_92 ( & V_100 , V_5 , V_2 , V_39 ,
& V_106 , & V_109 ) ;
if ( F_152 ( V_146 , V_108 , V_39 , V_2 ) ) {
F_33 ( V_39 , V_2 , true ) ;
V_108 += F_92 ( & V_100 , V_5 , V_2 ,
V_39 , & V_106 , & V_109 ) ;
}
F_58 ( & V_8 -> V_163 ) ;
V_9 -> V_193 [ 0 ] += V_173 ;
V_9 -> V_193 [ 1 ] += V_174 ;
if ( F_1 ( V_2 ) ) {
if ( F_104 () )
F_157 ( V_194 , V_8 ,
V_108 ) ;
else
F_157 ( V_195 , V_8 ,
V_108 ) ;
}
F_137 ( V_5 , & V_100 ) ;
F_150 ( V_8 , V_169 , - V_173 ) ;
F_150 ( V_8 , V_167 , - V_174 ) ;
F_66 ( & V_8 -> V_163 ) ;
F_113 ( & V_100 , 1 ) ;
if ( V_109 && V_109 >= ( V_146 >> ( V_50 - V_39 ) ) )
F_158 ( V_8 , V_188 , V_189 / 10 ) ;
F_159 ( V_8 -> V_196 -> V_197 ,
F_8 ( V_8 ) ,
V_113 , V_108 ,
V_39 ,
F_160 ( V_133 , V_2 -> V_45 ) ) ;
return V_108 ;
}
static void F_161 ( struct V_8 * V_8 ,
struct V_99 * V_16 ,
struct V_99 * V_170 ,
enum V_10 V_11 )
{
unsigned long V_198 = 0 ;
struct V_52 * V_52 ;
while ( ! F_94 ( V_16 ) ) {
struct V_144 * V_144 ;
V_52 = F_95 ( V_16 ) ;
F_75 ( F_76 ( V_52 ) ) ;
F_138 ( V_52 ) ;
V_144 = F_162 ( V_8 , V_52 , V_11 ) ;
F_123 ( & V_52 -> V_11 , & V_144 -> V_154 [ V_11 ] ) ;
V_198 += F_124 ( V_52 ) ;
if ( F_106 ( V_52 ) ) {
F_142 ( V_52 ) ;
F_143 ( V_52 ) ;
F_135 ( V_8 , V_52 , V_11 ) ;
if ( F_60 ( F_144 ( V_52 ) ) ) {
F_66 ( & V_8 -> V_163 ) ;
( * F_145 ( V_52 ) ) ( V_52 ) ;
F_58 ( & V_8 -> V_163 ) ;
} else
F_108 ( & V_52 -> V_11 , V_170 ) ;
}
}
F_150 ( V_8 , V_12 + V_11 , V_198 ) ;
if ( ! F_140 ( V_11 ) )
F_149 ( V_178 , V_198 ) ;
}
static void F_163 ( unsigned long V_19 ,
struct V_4 * V_5 ,
struct V_1 * V_2 ,
int V_39 , int V_133 )
{
unsigned long V_146 ;
unsigned long V_113 ;
unsigned long V_92 ;
F_93 ( V_199 ) ;
F_93 ( V_200 ) ;
F_93 ( V_201 ) ;
struct V_52 * V_52 ;
struct V_7 * V_9 = F_3 ( V_5 ) ;
unsigned long V_202 = 0 ;
T_4 V_187 = V_136 ;
struct V_8 * V_8 = V_5 -> V_8 ;
F_156 () ;
F_34 ( V_2 ) ;
if ( ! V_2 -> V_115 )
V_187 |= V_142 ;
if ( ! V_2 -> V_128 )
V_187 |= V_139 ;
F_58 ( & V_8 -> V_163 ) ;
V_146 = F_119 ( V_19 , V_5 , & V_199 , & V_113 , V_2 ,
V_187 , 1 , V_133 ) ;
if ( F_1 ( V_2 ) )
V_8 -> V_190 += V_113 ;
V_9 -> V_193 [ V_133 ] += V_146 ;
F_157 ( V_203 , V_8 , V_113 ) ;
if ( V_133 )
F_150 ( V_8 , V_179 , - V_146 ) ;
else
F_150 ( V_8 , V_182 , - V_146 ) ;
F_150 ( V_8 , V_169 + V_133 , V_146 ) ;
F_66 ( & V_8 -> V_163 ) ;
while ( ! F_94 ( & V_199 ) ) {
F_28 () ;
V_52 = F_95 ( & V_199 ) ;
F_17 ( & V_52 -> V_11 ) ;
if ( F_60 ( ! F_78 ( V_52 , NULL ) ) ) {
F_72 ( V_52 ) ;
continue;
}
if ( F_60 ( V_204 ) ) {
if ( F_37 ( V_52 ) && F_96 ( V_52 ) ) {
if ( F_37 ( V_52 ) )
F_105 ( V_52 , 0 ) ;
F_44 ( V_52 ) ;
}
}
if ( F_87 ( V_52 , 0 , V_5 -> V_6 , & V_92 ) ) {
V_202 += F_124 ( V_52 ) ;
if ( ( V_92 & V_96 ) && F_103 ( V_52 ) ) {
F_108 ( & V_52 -> V_11 , & V_200 ) ;
continue;
}
}
F_147 ( V_52 ) ;
F_108 ( & V_52 -> V_11 , & V_201 ) ;
}
F_58 ( & V_8 -> V_163 ) ;
V_9 -> V_172 [ V_133 ] += V_202 ;
F_161 ( V_8 , & V_200 , & V_199 ,
V_152 + V_133 * V_153 ) ;
F_161 ( V_8 , & V_201 , & V_199 ,
V_151 + V_133 * V_153 ) ;
F_150 ( V_8 , V_169 + V_133 , - V_146 ) ;
F_66 ( & V_8 -> V_163 ) ;
F_113 ( & V_199 , 1 ) ;
}
static int F_164 ( struct V_8 * V_8 )
{
unsigned long V_83 , V_164 ;
V_83 = F_10 ( V_8 , V_182 ) ;
V_164 = F_10 ( V_8 , V_168 ) ;
if ( V_164 * V_8 -> V_205 < V_83 )
return 1 ;
return 0 ;
}
static int F_165 ( struct V_4 * V_5 )
{
if ( ! V_206 )
return 0 ;
if ( ! F_2 ( V_5 ) )
return F_166 ( V_5 -> V_6 ,
V_5 -> V_8 ) ;
return F_164 ( V_5 -> V_8 ) ;
}
static inline int F_165 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_167 ( struct V_8 * V_8 )
{
unsigned long V_83 , V_164 ;
V_83 = F_10 ( V_8 , V_179 ) ;
V_164 = F_10 ( V_8 , V_166 ) ;
return ( V_83 > V_164 ) ;
}
static int F_168 ( struct V_4 * V_5 )
{
if ( ! F_2 ( V_5 ) )
return F_169 ( V_5 -> V_6 ,
V_5 -> V_8 ) ;
return F_167 ( V_5 -> V_8 ) ;
}
static int F_170 ( struct V_4 * V_5 , int V_133 )
{
if ( V_133 )
return F_168 ( V_5 ) ;
else
return F_165 ( V_5 ) ;
}
static unsigned long F_171 ( enum V_10 V_11 , unsigned long V_19 ,
struct V_4 * V_5 ,
struct V_1 * V_2 , int V_39 )
{
int V_133 = F_141 ( V_11 ) ;
if ( F_140 ( V_11 ) ) {
if ( F_170 ( V_5 , V_133 ) )
F_163 ( V_19 , V_5 , V_2 , V_39 , V_133 ) ;
return 0 ;
}
return F_153 ( V_19 , V_5 , V_2 , V_39 , V_133 ) ;
}
static int F_172 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_207 ;
return F_173 ( V_5 -> V_6 ) ;
}
static void F_174 ( struct V_4 * V_5 , struct V_1 * V_2 ,
unsigned long * V_30 , int V_39 )
{
unsigned long V_208 , V_133 , free ;
unsigned long V_209 , V_210 ;
unsigned long V_211 , V_212 ;
struct V_7 * V_9 = F_3 ( V_5 ) ;
T_6 V_213 [ 2 ] , V_214 ;
enum V_10 V_11 ;
int V_215 = 0 ;
bool V_216 = false ;
if ( F_104 () && V_5 -> V_8 -> V_217 )
V_216 = true ;
if ( ! F_1 ( V_2 ) )
V_216 = true ;
if ( ! V_2 -> V_218 || ( V_160 <= 0 ) ) {
V_215 = 1 ;
V_213 [ 0 ] = 0 ;
V_213 [ 1 ] = 1 ;
V_214 = 1 ;
goto V_25;
}
V_208 = F_5 ( V_5 , V_183 ) +
F_5 ( V_5 , V_184 ) ;
V_133 = F_5 ( V_5 , V_180 ) +
F_5 ( V_5 , V_181 ) ;
if ( F_1 ( V_2 ) ) {
free = F_10 ( V_5 -> V_8 , V_219 ) ;
if ( F_60 ( V_133 + free <= F_175 ( V_5 -> V_8 ) ) ) {
V_213 [ 0 ] = 1 ;
V_213 [ 1 ] = 0 ;
V_214 = 1 ;
goto V_25;
}
}
V_209 = F_172 ( V_5 , V_2 ) ;
V_210 = 200 - F_172 ( V_5 , V_2 ) ;
F_58 ( & V_5 -> V_8 -> V_163 ) ;
if ( F_60 ( V_9 -> V_193 [ 0 ] > V_208 / 4 ) ) {
V_9 -> V_193 [ 0 ] /= 2 ;
V_9 -> V_172 [ 0 ] /= 2 ;
}
if ( F_60 ( V_9 -> V_193 [ 1 ] > V_133 / 4 ) ) {
V_9 -> V_193 [ 1 ] /= 2 ;
V_9 -> V_172 [ 1 ] /= 2 ;
}
V_211 = ( V_209 + 1 ) * ( V_9 -> V_193 [ 0 ] + 1 ) ;
V_211 /= V_9 -> V_172 [ 0 ] + 1 ;
V_212 = ( V_210 + 1 ) * ( V_9 -> V_193 [ 1 ] + 1 ) ;
V_212 /= V_9 -> V_172 [ 1 ] + 1 ;
F_66 ( & V_5 -> V_8 -> V_163 ) ;
V_213 [ 0 ] = V_211 ;
V_213 [ 1 ] = V_212 ;
V_214 = V_211 + V_212 + 1 ;
V_25:
F_176 (lru) {
int V_133 = F_141 ( V_11 ) ;
unsigned long V_150 ;
V_150 = F_5 ( V_5 , V_11 ) ;
if ( V_39 || V_215 ) {
V_150 >>= V_39 ;
if ( ! V_150 && V_216 )
V_150 = V_24 ;
V_150 = F_177 ( V_150 * V_213 [ V_133 ] , V_214 ) ;
}
V_30 [ V_11 ] = V_150 ;
}
}
static inline bool F_178 ( struct V_4 * V_5 ,
unsigned long V_108 ,
unsigned long V_113 ,
struct V_1 * V_2 )
{
unsigned long V_220 ;
unsigned long V_221 ;
if ( ! ( V_2 -> V_45 & V_46 ) )
return false ;
if ( V_2 -> V_117 & V_222 ) {
if ( ! V_108 && ! V_113 )
return false ;
} else {
if ( ! V_108 )
return false ;
}
V_220 = ( 2UL << V_2 -> V_48 ) ;
V_221 = F_5 ( V_5 , V_181 ) ;
if ( V_160 > 0 )
V_221 += F_5 ( V_5 , V_184 ) ;
if ( V_2 -> V_108 < V_220 &&
V_221 > V_220 )
return true ;
switch ( F_179 ( V_5 -> V_8 , V_2 -> V_48 ) ) {
case V_223 :
case V_224 :
return false ;
default:
return true ;
}
}
static void F_180 ( int V_39 , struct V_4 * V_5 ,
struct V_1 * V_2 )
{
unsigned long V_30 [ V_176 ] ;
unsigned long V_19 ;
enum V_10 V_11 ;
unsigned long V_108 , V_113 ;
unsigned long V_225 = V_2 -> V_225 ;
struct V_226 V_227 ;
V_228:
V_108 = 0 ;
V_113 = V_2 -> V_113 ;
F_174 ( V_5 , V_2 , V_30 , V_39 ) ;
F_181 ( & V_227 ) ;
while ( V_30 [ V_184 ] || V_30 [ V_180 ] ||
V_30 [ V_181 ] ) {
F_176 (lru) {
if ( V_30 [ V_11 ] ) {
V_19 = F_182 (unsigned long,
nr[lru], SWAP_CLUSTER_MAX) ;
V_30 [ V_11 ] -= V_19 ;
V_108 += F_171 ( V_11 , V_19 ,
V_5 , V_2 , V_39 ) ;
}
}
if ( V_108 >= V_225 && V_39 < V_50 )
break;
}
F_183 ( & V_227 ) ;
V_2 -> V_108 += V_108 ;
if ( F_165 ( V_5 ) )
F_163 ( V_24 , V_5 , V_2 , V_39 , 0 ) ;
if ( F_178 ( V_5 , V_108 ,
V_2 -> V_113 - V_113 , V_2 ) )
goto V_228;
F_184 ( V_2 -> V_117 ) ;
}
static void F_185 ( int V_39 , struct V_8 * V_8 ,
struct V_1 * V_2 )
{
struct V_6 * V_229 = V_2 -> V_3 ;
struct V_230 V_231 = {
. V_8 = V_8 ,
. V_39 = V_39 ,
} ;
struct V_6 * V_232 ;
V_232 = F_186 ( V_229 , NULL , & V_231 ) ;
do {
struct V_4 V_5 = {
. V_6 = V_232 ,
. V_8 = V_8 ,
} ;
F_180 ( V_39 , & V_5 , V_2 ) ;
if ( ! F_1 ( V_2 ) ) {
F_187 ( V_229 , V_232 ) ;
break;
}
V_232 = F_186 ( V_229 , V_232 , & V_231 ) ;
} while ( V_232 );
}
static inline bool F_188 ( struct V_8 * V_8 , struct V_1 * V_2 )
{
unsigned long V_233 , V_234 ;
bool V_235 ;
if ( V_2 -> V_48 <= V_49 )
return false ;
V_233 = F_25 ( F_189 ( V_8 ) ,
( V_8 -> V_236 + V_237 - 1 ) /
V_237 ) ;
V_234 = F_175 ( V_8 ) + V_233 + ( 2UL << V_2 -> V_48 ) ;
V_235 = F_190 ( V_8 , 0 , V_234 , 0 , 0 ) ;
if ( F_191 ( V_8 , V_2 -> V_48 ) )
return V_235 ;
if ( ! F_179 ( V_8 , V_2 -> V_48 ) )
return false ;
return V_235 ;
}
static bool F_192 ( int V_39 , struct V_238 * V_238 ,
struct V_1 * V_2 )
{
struct V_239 * V_240 ;
struct V_8 * V_8 ;
unsigned long V_241 ;
unsigned long V_242 ;
bool V_243 = false ;
if ( V_204 )
V_2 -> V_117 |= V_244 ;
F_193 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_194 ( V_8 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_195 ( V_8 , V_245 ) )
continue;
if ( V_8 -> V_217 && V_39 != V_50 )
continue;
if ( V_44 ) {
if ( F_188 ( V_8 , V_2 ) ) {
V_243 = true ;
continue;
}
}
V_242 = 0 ;
V_241 = F_196 ( V_8 ,
V_2 -> V_48 , V_2 -> V_117 ,
& V_242 ) ;
V_2 -> V_108 += V_241 ;
V_2 -> V_113 += V_242 ;
}
F_185 ( V_39 , V_8 , V_2 ) ;
}
return V_243 ;
}
static bool F_197 ( struct V_8 * V_8 )
{
return V_8 -> V_190 < F_198 ( V_8 ) * 6 ;
}
static bool V_217 ( struct V_238 * V_238 ,
struct V_1 * V_2 )
{
struct V_239 * V_240 ;
struct V_8 * V_8 ;
F_193 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_194 ( V_8 ) )
continue;
if ( ! F_195 ( V_8 , V_245 ) )
continue;
if ( ! V_8 -> V_217 )
return false ;
}
return true ;
}
static unsigned long F_199 ( struct V_238 * V_238 ,
struct V_1 * V_2 ,
struct V_18 * V_20 )
{
int V_39 ;
unsigned long V_246 = 0 ;
struct V_247 * V_247 = V_55 -> V_247 ;
struct V_239 * V_240 ;
struct V_8 * V_8 ;
unsigned long V_248 ;
bool V_243 ;
F_200 () ;
if ( F_1 ( V_2 ) )
F_85 ( V_249 ) ;
for ( V_39 = V_50 ; V_39 >= 0 ; V_39 -- ) {
V_2 -> V_113 = 0 ;
if ( ! V_39 )
F_201 ( V_2 -> V_3 ) ;
V_243 = F_192 ( V_39 , V_238 , V_2 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_22 = 0 ;
F_202 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_195 ( V_8 , V_245 ) )
continue;
V_22 += F_198 ( V_8 ) ;
}
F_19 ( V_20 , V_2 -> V_113 , V_22 ) ;
if ( V_247 ) {
V_2 -> V_108 += V_247 -> V_250 ;
V_247 -> V_250 = 0 ;
}
}
V_246 += V_2 -> V_113 ;
if ( V_2 -> V_108 >= V_2 -> V_225 )
goto V_25;
V_248 = V_2 -> V_225 + V_2 -> V_225 / 2 ;
if ( V_246 > V_248 ) {
F_203 ( V_251 ? 0 : V_246 ,
V_252 ) ;
V_2 -> V_128 = 1 ;
}
if ( ! V_2 -> V_253 && V_2 -> V_113 &&
V_39 < V_50 - 2 ) {
struct V_8 * V_254 ;
F_204 ( V_238 , F_205 ( V_2 -> V_117 ) ,
& V_255 ,
& V_254 ) ;
F_158 ( V_254 , V_188 , V_189 / 10 ) ;
}
}
V_25:
F_206 () ;
if ( V_2 -> V_108 )
return V_2 -> V_108 ;
if ( V_256 )
return 0 ;
if ( V_243 )
return 1 ;
if ( F_1 ( V_2 ) && ! V_217 ( V_238 , V_2 ) )
return 1 ;
return 0 ;
}
unsigned long F_207 ( struct V_238 * V_238 , int V_48 ,
T_7 V_117 , T_8 * V_257 )
{
unsigned long V_108 ;
struct V_1 V_2 = {
. V_117 = V_117 ,
. V_128 = ! V_251 ,
. V_225 = V_24 ,
. V_115 = 1 ,
. V_218 = 1 ,
. V_48 = V_48 ,
. V_3 = NULL ,
. V_257 = V_257 ,
} ;
struct V_18 V_20 = {
. V_117 = V_2 . V_117 ,
} ;
F_208 ( V_48 ,
V_2 . V_128 ,
V_117 ) ;
V_108 = F_199 ( V_238 , & V_2 , & V_20 ) ;
F_209 ( V_108 ) ;
return V_108 ;
}
unsigned long F_210 ( struct V_6 * V_232 ,
T_7 V_117 , bool V_215 ,
struct V_8 * V_8 ,
unsigned long * V_113 )
{
struct V_1 V_2 = {
. V_113 = 0 ,
. V_225 = V_24 ,
. V_128 = ! V_251 ,
. V_115 = 1 ,
. V_218 = ! V_215 ,
. V_48 = 0 ,
. V_3 = V_232 ,
} ;
struct V_4 V_5 = {
. V_6 = V_232 ,
. V_8 = V_8 ,
} ;
V_2 . V_117 = ( V_117 & V_258 ) |
( V_259 & ~ V_258 ) ;
F_211 ( 0 ,
V_2 . V_128 ,
V_2 . V_117 ) ;
F_180 ( 0 , & V_5 , & V_2 ) ;
F_212 ( V_2 . V_108 ) ;
* V_113 = V_2 . V_113 ;
return V_2 . V_108 ;
}
unsigned long F_213 ( struct V_6 * V_232 ,
T_7 V_117 ,
bool V_215 )
{
struct V_238 * V_238 ;
unsigned long V_108 ;
int V_260 ;
struct V_1 V_2 = {
. V_128 = ! V_251 ,
. V_115 = 1 ,
. V_218 = ! V_215 ,
. V_225 = V_24 ,
. V_48 = 0 ,
. V_3 = V_232 ,
. V_257 = NULL ,
. V_117 = ( V_117 & V_258 ) |
( V_259 & ~ V_258 ) ,
} ;
struct V_18 V_20 = {
. V_117 = V_2 . V_117 ,
} ;
V_260 = F_214 ( V_232 ) ;
V_238 = F_215 ( V_260 ) -> V_261 ;
F_216 ( 0 ,
V_2 . V_128 ,
V_2 . V_117 ) ;
V_108 = F_199 ( V_238 , & V_2 , & V_20 ) ;
F_217 ( V_108 ) ;
return V_108 ;
}
static void F_218 ( struct V_8 * V_8 , struct V_1 * V_2 ,
int V_39 )
{
struct V_6 * V_232 ;
if ( ! V_206 )
return;
V_232 = F_186 ( NULL , NULL , NULL ) ;
do {
struct V_4 V_5 = {
. V_6 = V_232 ,
. V_8 = V_8 ,
} ;
if ( F_165 ( & V_5 ) )
F_163 ( V_24 , & V_5 ,
V_2 , V_39 , 0 ) ;
V_232 = F_186 ( NULL , V_232 , NULL ) ;
} while ( V_232 );
}
static bool F_219 ( T_9 * V_262 , unsigned long V_263 ,
int V_264 )
{
unsigned long V_236 = 0 ;
int V_265 ;
for ( V_265 = 0 ; V_265 <= V_264 ; V_265 ++ )
V_236 += V_262 -> V_266 [ V_265 ] . V_236 ;
return V_263 >= ( V_236 >> 2 ) ;
}
static bool F_220 ( T_9 * V_262 , int V_48 , long V_267 ,
int V_264 )
{
int V_265 ;
unsigned long V_268 = 0 ;
bool V_269 = true ;
if ( V_267 )
return true ;
for ( V_265 = 0 ; V_265 <= V_264 ; V_265 ++ ) {
struct V_8 * V_8 = V_262 -> V_266 + V_265 ;
if ( ! F_194 ( V_8 ) )
continue;
if ( V_8 -> V_217 ) {
V_268 += V_8 -> V_236 ;
continue;
}
if ( ! F_190 ( V_8 , V_48 , F_175 ( V_8 ) ,
V_265 , 0 ) )
V_269 = false ;
else
V_268 += V_8 -> V_236 ;
}
if ( V_48 )
return ! F_219 ( V_262 , V_268 , V_264 ) ;
else
return ! V_269 ;
}
static unsigned long F_221 ( T_9 * V_262 , int V_48 ,
int * V_264 )
{
int V_269 ;
unsigned long V_268 ;
int V_39 ;
int V_265 ;
int V_270 = 0 ;
unsigned long V_246 ;
struct V_247 * V_247 = V_55 -> V_247 ;
unsigned long V_241 ;
unsigned long V_242 ;
struct V_1 V_2 = {
. V_117 = V_245 ,
. V_115 = 1 ,
. V_218 = 1 ,
. V_225 = V_271 ,
. V_48 = V_48 ,
. V_3 = NULL ,
} ;
struct V_18 V_20 = {
. V_117 = V_2 . V_117 ,
} ;
V_272:
V_246 = 0 ;
V_2 . V_108 = 0 ;
V_2 . V_128 = ! V_251 ;
F_85 ( V_273 ) ;
for ( V_39 = V_50 ; V_39 >= 0 ; V_39 -- ) {
unsigned long V_22 = 0 ;
int V_274 = 0 ;
if ( ! V_39 )
F_201 ( NULL ) ;
V_269 = 1 ;
V_268 = 0 ;
for ( V_265 = V_262 -> V_275 - 1 ; V_265 >= 0 ; V_265 -- ) {
struct V_8 * V_8 = V_262 -> V_266 + V_265 ;
if ( ! F_194 ( V_8 ) )
continue;
if ( V_8 -> V_217 && V_39 != V_50 )
continue;
F_218 ( V_8 , & V_2 , V_39 ) ;
if ( V_204 && F_222 ( V_265 ) ) {
V_270 = V_265 ;
break;
}
if ( ! F_190 ( V_8 , V_48 ,
F_175 ( V_8 ) , 0 , 0 ) ) {
V_270 = V_265 ;
break;
} else {
F_223 ( V_8 , V_130 ) ;
}
}
if ( V_265 < 0 )
goto V_25;
for ( V_265 = 0 ; V_265 <= V_270 ; V_265 ++ ) {
struct V_8 * V_8 = V_262 -> V_266 + V_265 ;
V_22 += F_198 ( V_8 ) ;
}
for ( V_265 = 0 ; V_265 <= V_270 ; V_265 ++ ) {
struct V_8 * V_8 = V_262 -> V_266 + V_265 ;
int V_276 , V_277 ;
unsigned long V_233 ;
if ( ! F_194 ( V_8 ) )
continue;
if ( V_8 -> V_217 && V_39 != V_50 )
continue;
V_2 . V_113 = 0 ;
V_242 = 0 ;
V_241 = F_196 ( V_8 ,
V_48 , V_2 . V_117 ,
& V_242 ) ;
V_2 . V_108 += V_241 ;
V_246 += V_242 ;
V_233 = F_25 ( F_189 ( V_8 ) ,
( V_8 -> V_236 +
V_237 - 1 ) /
V_237 ) ;
V_277 = V_48 ;
if ( V_44 && V_48 &&
F_179 ( V_8 , V_48 ) !=
V_278 )
V_277 = 0 ;
if ( ( V_204 && F_222 ( V_265 ) ) ||
! F_190 ( V_8 , V_277 ,
F_175 ( V_8 ) + V_233 ,
V_270 , 0 ) ) {
F_185 ( V_39 , V_8 , & V_2 ) ;
V_247 -> V_250 = 0 ;
V_276 = F_19 ( & V_20 , V_2 . V_113 , V_22 ) ;
V_2 . V_108 += V_247 -> V_250 ;
V_246 += V_2 . V_113 ;
if ( V_276 == 0 && ! F_197 ( V_8 ) )
V_8 -> V_217 = 1 ;
}
if ( V_246 > V_24 * 2 &&
V_246 > V_2 . V_108 + V_2 . V_108 / 2 )
V_2 . V_128 = 1 ;
if ( V_8 -> V_217 ) {
if ( V_270 && V_270 == V_265 )
V_270 -- ;
continue;
}
if ( ! F_190 ( V_8 , V_277 ,
F_175 ( V_8 ) , V_270 , 0 ) ) {
V_269 = 0 ;
if ( ! F_190 ( V_8 , V_48 ,
F_224 ( V_8 ) , V_270 , 0 ) )
V_274 = 1 ;
} else {
F_223 ( V_8 , V_130 ) ;
if ( V_265 <= * V_264 )
V_268 += V_8 -> V_236 ;
}
}
if ( V_269 || ( V_48 && F_219 ( V_262 , V_268 , * V_264 ) ) )
break;
if ( V_246 && ( V_39 < V_50 - 2 ) ) {
if ( V_274 )
F_85 ( V_279 ) ;
else
F_154 ( V_188 , V_189 / 10 ) ;
}
if ( V_2 . V_108 >= V_24 )
break;
}
V_25:
if ( ! ( V_269 || ( V_48 && F_219 ( V_262 , V_268 , * V_264 ) ) ) ) {
F_28 () ;
F_225 () ;
if ( V_2 . V_108 < V_24 )
V_48 = V_2 . V_48 = 0 ;
goto V_272;
}
if ( V_48 ) {
int V_280 = 1 ;
for ( V_265 = 0 ; V_265 <= V_270 ; V_265 ++ ) {
struct V_8 * V_8 = V_262 -> V_266 + V_265 ;
if ( ! F_194 ( V_8 ) )
continue;
if ( V_8 -> V_217 && V_39 != V_50 )
continue;
if ( V_44 &&
F_179 ( V_8 , V_48 ) == V_278 )
goto V_272;
if ( ! F_226 ( V_8 , 0 ,
F_175 ( V_8 ) , 0 , 0 ) ) {
V_48 = V_2 . V_48 = 0 ;
goto V_272;
}
if ( F_226 ( V_8 , V_48 ,
F_189 ( V_8 ) , * V_264 , 0 ) )
V_280 = 0 ;
F_223 ( V_8 , V_130 ) ;
}
if ( V_280 )
F_227 ( V_262 , V_48 ) ;
}
* V_264 = V_270 ;
return V_48 ;
}
static void F_228 ( T_9 * V_262 , int V_48 , int V_264 )
{
long V_267 = 0 ;
F_229 ( V_281 ) ;
if ( F_230 ( V_55 ) || F_231 () )
return;
F_232 ( & V_262 -> V_282 , & V_281 , V_283 ) ;
if ( ! F_220 ( V_262 , V_48 , V_267 , V_264 ) ) {
V_267 = F_233 ( V_189 / 10 ) ;
F_234 ( & V_262 -> V_282 , & V_281 ) ;
F_232 ( & V_262 -> V_282 , & V_281 , V_283 ) ;
}
if ( ! F_220 ( V_262 , V_48 , V_267 , V_264 ) ) {
F_235 ( V_262 -> V_197 ) ;
F_236 ( V_262 , V_284 ) ;
F_237 () ;
F_236 ( V_262 , V_285 ) ;
} else {
if ( V_267 )
F_85 ( V_286 ) ;
else
F_85 ( V_287 ) ;
}
F_234 ( & V_262 -> V_282 , & V_281 ) ;
}
static int F_238 ( void * V_288 )
{
unsigned long V_48 , V_289 ;
unsigned V_290 ;
int V_264 , V_291 ;
int V_292 ;
T_9 * V_262 = ( T_9 * ) V_288 ;
struct V_293 * V_294 = V_55 ;
struct V_247 V_247 = {
. V_250 = 0 ,
} ;
const struct V_295 * V_295 = F_239 ( V_262 -> V_197 ) ;
F_240 ( V_245 ) ;
if ( ! F_241 ( V_295 ) )
F_242 ( V_294 , V_295 ) ;
V_55 -> V_247 = & V_247 ;
V_294 -> V_56 |= V_296 | V_57 | V_297 ;
F_243 () ;
V_48 = V_289 = 0 ;
V_290 = 0 ;
V_264 = V_291 = V_262 -> V_275 - 1 ;
V_292 = V_264 ;
for ( ; ; ) {
int V_23 ;
if ( V_292 >= V_291 &&
V_290 == V_289 ) {
V_289 = V_262 -> V_298 ;
V_291 = V_262 -> V_264 ;
V_262 -> V_298 = 0 ;
V_262 -> V_264 = V_262 -> V_275 - 1 ;
}
if ( V_48 < V_289 || V_264 > V_291 ) {
V_48 = V_289 ;
V_264 = V_291 ;
} else {
F_228 ( V_262 , V_290 ,
V_292 ) ;
V_48 = V_262 -> V_298 ;
V_264 = V_262 -> V_264 ;
V_289 = V_48 ;
V_291 = V_264 ;
V_262 -> V_298 = 0 ;
V_262 -> V_264 = V_262 -> V_275 - 1 ;
}
V_23 = F_225 () ;
if ( F_231 () )
break;
if ( ! V_23 ) {
F_244 ( V_262 -> V_197 , V_48 ) ;
V_292 = V_264 ;
V_290 = F_221 ( V_262 , V_48 ,
& V_292 ) ;
}
}
return 0 ;
}
void F_245 ( struct V_8 * V_8 , int V_48 , enum V_299 V_264 )
{
T_9 * V_262 ;
if ( ! F_194 ( V_8 ) )
return;
if ( ! F_195 ( V_8 , V_245 ) )
return;
V_262 = V_8 -> V_196 ;
if ( V_262 -> V_298 < V_48 ) {
V_262 -> V_298 = V_48 ;
V_262 -> V_264 = F_25 ( V_262 -> V_264 , V_264 ) ;
}
if ( ! F_246 ( & V_262 -> V_282 ) )
return;
if ( F_190 ( V_8 , V_48 , F_189 ( V_8 ) , 0 , 0 ) )
return;
F_247 ( V_262 -> V_197 , F_8 ( V_8 ) , V_48 ) ;
F_248 ( & V_262 -> V_282 ) ;
}
unsigned long F_249 ( void )
{
int V_30 ;
V_30 = F_250 ( V_179 ) +
F_250 ( V_166 ) ;
if ( V_160 > 0 )
V_30 += F_250 ( V_182 ) +
F_250 ( V_168 ) ;
return V_30 ;
}
unsigned long F_198 ( struct V_8 * V_8 )
{
int V_30 ;
V_30 = F_10 ( V_8 , V_179 ) +
F_10 ( V_8 , V_166 ) ;
if ( V_160 > 0 )
V_30 += F_10 ( V_8 , V_182 ) +
F_10 ( V_8 , V_168 ) ;
return V_30 ;
}
unsigned long F_251 ( unsigned long V_225 )
{
struct V_247 V_247 ;
struct V_1 V_2 = {
. V_117 = V_259 ,
. V_218 = 1 ,
. V_115 = 1 ,
. V_128 = 1 ,
. V_225 = V_225 ,
. V_253 = 1 ,
. V_48 = 0 ,
} ;
struct V_18 V_20 = {
. V_117 = V_2 . V_117 ,
} ;
struct V_238 * V_238 = F_252 ( F_253 () , V_2 . V_117 ) ;
struct V_293 * V_288 = V_55 ;
unsigned long V_108 ;
V_288 -> V_56 |= V_296 ;
F_240 ( V_2 . V_117 ) ;
V_247 . V_250 = 0 ;
V_288 -> V_247 = & V_247 ;
V_108 = F_199 ( V_238 , & V_2 , & V_20 ) ;
V_288 -> V_247 = NULL ;
F_254 () ;
V_288 -> V_56 &= ~ V_296 ;
return V_108 ;
}
static int T_10 F_255 ( struct V_300 * V_301 ,
unsigned long V_302 , void * V_303 )
{
int V_260 ;
if ( V_302 == V_304 || V_302 == V_305 ) {
F_256 (nid, N_HIGH_MEMORY) {
T_9 * V_262 = F_215 ( V_260 ) ;
const struct V_295 * V_306 ;
V_306 = F_239 ( V_262 -> V_197 ) ;
if ( F_257 ( V_307 , V_306 ) < V_308 )
F_242 ( V_262 -> F_238 , V_306 ) ;
}
}
return V_309 ;
}
int F_258 ( int V_260 )
{
T_9 * V_262 = F_215 ( V_260 ) ;
int V_23 = 0 ;
if ( V_262 -> F_238 )
return 0 ;
V_262 -> F_238 = F_259 ( F_238 , V_262 , L_4 , V_260 ) ;
if ( F_260 ( V_262 -> F_238 ) ) {
F_56 ( V_310 == V_311 ) ;
F_24 ( L_5 , V_260 ) ;
V_23 = - 1 ;
}
return V_23 ;
}
void F_261 ( int V_260 )
{
struct V_293 * F_238 = F_215 ( V_260 ) -> F_238 ;
if ( F_238 )
F_262 ( F_238 ) ;
}
static int T_11 F_263 ( void )
{
int V_260 ;
F_264 () ;
F_256 (nid, N_HIGH_MEMORY)
F_258 ( V_260 ) ;
F_265 ( F_255 , 0 ) ;
return 0 ;
}
static inline unsigned long F_266 ( struct V_8 * V_8 )
{
unsigned long V_312 = F_10 ( V_8 , V_313 ) ;
unsigned long V_314 = F_10 ( V_8 , V_166 ) +
F_10 ( V_8 , V_179 ) ;
return ( V_314 > V_312 ) ? ( V_314 - V_312 ) : 0 ;
}
static long F_267 ( struct V_8 * V_8 )
{
long V_315 ;
long V_26 = 0 ;
if ( V_316 & V_317 )
V_315 = F_10 ( V_8 , V_318 ) ;
else
V_315 = F_266 ( V_8 ) ;
if ( ! ( V_316 & V_319 ) )
V_26 += F_10 ( V_8 , V_320 ) ;
if ( F_60 ( V_26 > V_315 ) )
V_26 = V_315 ;
return V_315 - V_26 ;
}
static int F_268 ( struct V_8 * V_8 , T_7 V_117 , unsigned int V_48 )
{
const unsigned long V_321 = 1 << V_48 ;
struct V_293 * V_288 = V_55 ;
struct V_247 V_247 ;
int V_39 ;
struct V_1 V_2 = {
. V_128 = ! ! ( V_316 & V_319 ) ,
. V_115 = ! ! ( V_316 & V_317 ) ,
. V_218 = 1 ,
. V_225 = F_269 (unsigned long, nr_pages,
SWAP_CLUSTER_MAX) ,
. V_117 = V_117 ,
. V_48 = V_48 ,
} ;
struct V_18 V_20 = {
. V_117 = V_2 . V_117 ,
} ;
unsigned long V_322 , V_323 ;
F_28 () ;
V_288 -> V_56 |= V_296 | V_57 ;
F_240 ( V_117 ) ;
V_247 . V_250 = 0 ;
V_288 -> V_247 = & V_247 ;
if ( F_267 ( V_8 ) > V_8 -> V_324 ) {
V_39 = V_325 ;
do {
F_185 ( V_39 , V_8 , & V_2 ) ;
V_39 -- ;
} while ( V_39 >= 0 && V_2 . V_108 < V_321 );
}
V_322 = F_10 ( V_8 , V_326 ) ;
if ( V_322 > V_8 -> V_327 ) {
for (; ; ) {
unsigned long V_22 = F_198 ( V_8 ) ;
if ( ! F_19 ( & V_20 , V_2 . V_113 , V_22 ) )
break;
V_323 = F_10 ( V_8 ,
V_326 ) ;
if ( V_323 + V_321 <= V_322 )
break;
}
V_323 = F_10 ( V_8 , V_326 ) ;
if ( V_323 < V_322 )
V_2 . V_108 += V_322 - V_323 ;
}
V_288 -> V_247 = NULL ;
V_55 -> V_56 &= ~ ( V_296 | V_57 ) ;
F_254 () ;
return V_2 . V_108 >= V_321 ;
}
int F_270 ( struct V_8 * V_8 , T_7 V_117 , unsigned int V_48 )
{
int V_197 ;
int V_23 ;
if ( F_267 ( V_8 ) <= V_8 -> V_324 &&
F_10 ( V_8 , V_326 ) <= V_8 -> V_327 )
return V_328 ;
if ( V_8 -> V_217 )
return V_328 ;
if ( ! ( V_117 & V_329 ) || ( V_55 -> V_56 & V_296 ) )
return V_330 ;
V_197 = F_7 ( V_8 ) ;
if ( F_271 ( V_197 , V_331 ) && V_197 != F_253 () )
return V_330 ;
if ( F_272 ( V_8 , V_332 ) )
return V_330 ;
V_23 = F_268 ( V_8 , V_117 , V_48 ) ;
F_223 ( V_8 , V_332 ) ;
if ( ! V_23 )
F_85 ( V_333 ) ;
return V_23 ;
}
int F_78 ( struct V_52 * V_52 , struct V_334 * V_335 )
{
if ( F_273 ( F_42 ( V_52 ) ) )
return 0 ;
if ( F_274 ( V_52 ) || ( V_335 && F_275 ( V_335 , V_52 ) ) )
return 0 ;
return 1 ;
}
void F_276 ( struct V_52 * * V_336 , int V_321 )
{
struct V_144 * V_144 ;
struct V_8 * V_8 = NULL ;
int V_337 = 0 ;
int V_338 = 0 ;
int V_265 ;
for ( V_265 = 0 ; V_265 < V_321 ; V_265 ++ ) {
struct V_52 * V_52 = V_336 [ V_265 ] ;
struct V_8 * V_339 ;
V_337 ++ ;
V_339 = F_98 ( V_52 ) ;
if ( V_339 != V_8 ) {
if ( V_8 )
F_66 ( & V_8 -> V_163 ) ;
V_8 = V_339 ;
F_58 ( & V_8 -> V_163 ) ;
}
if ( ! F_76 ( V_52 ) || ! F_74 ( V_52 ) )
continue;
if ( F_78 ( V_52 , NULL ) ) {
enum V_10 V_11 = F_79 ( V_52 ) ;
F_75 ( F_97 ( V_52 ) ) ;
F_77 ( V_52 ) ;
F_277 ( V_8 , V_340 ) ;
V_144 = F_278 ( V_8 , V_52 ,
V_86 , V_11 ) ;
F_123 ( & V_52 -> V_11 , & V_144 -> V_154 [ V_11 ] ) ;
F_279 ( V_8 , V_168 + V_11 ) ;
V_338 ++ ;
}
}
if ( V_8 ) {
F_149 ( V_87 , V_338 ) ;
F_149 ( V_341 , V_337 ) ;
F_66 ( & V_8 -> V_163 ) ;
}
}
static void F_280 ( void )
{
F_281 ( V_342
L_6
L_7
L_8 ,
V_55 -> V_343 ) ;
}
int F_282 ( struct V_344 * V_345 , int V_346 ,
void T_12 * V_347 ,
T_13 * V_348 , T_14 * V_349 )
{
F_280 () ;
F_283 ( V_345 , V_346 , V_347 , V_348 , V_349 ) ;
V_350 = 0 ;
return 0 ;
}
static T_15 F_284 ( struct V_351 * V_352 ,
struct V_353 * V_354 ,
char * V_355 )
{
F_280 () ;
return sprintf ( V_355 , L_9 ) ;
}
static T_15 F_285 ( struct V_351 * V_352 ,
struct V_353 * V_354 ,
const char * V_355 , T_13 V_175 )
{
F_280 () ;
return 1 ;
}
int F_286 ( struct V_356 * V_356 )
{
return F_287 ( & V_356 -> V_352 , & V_357 ) ;
}
void F_288 ( struct V_356 * V_356 )
{
F_289 ( & V_356 -> V_352 , & V_357 ) ;
}
