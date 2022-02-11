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
return F_5 ( V_4 -> V_5 ,
F_6 ( V_2 ) , F_7 ( V_2 ) , F_8 ( V_8 ) ) ;
return F_9 ( V_2 , V_9 + V_8 ) ;
}
void F_10 ( struct V_10 * V_10 )
{
F_11 ( & V_10 -> V_11 , 0 ) ;
F_12 ( & V_12 ) ;
F_13 ( & V_10 -> V_13 , & V_14 ) ;
F_14 ( & V_12 ) ;
}
void F_15 ( struct V_10 * V_10 )
{
F_12 ( & V_12 ) ;
F_16 ( & V_10 -> V_13 ) ;
F_14 ( & V_12 ) ;
}
static inline int F_17 ( struct V_10 * V_10 ,
struct V_15 * V_4 ,
unsigned long V_16 )
{
V_4 -> V_16 = V_16 ;
return (* V_10 -> V_17 )( V_10 , V_4 ) ;
}
unsigned long F_18 ( struct V_15 * V_17 ,
unsigned long V_18 ,
unsigned long V_19 )
{
struct V_10 * V_10 ;
unsigned long V_20 = 0 ;
if ( V_18 == 0 )
V_18 = V_21 ;
if ( ! F_19 ( & V_12 ) ) {
V_20 = 1 ;
goto V_22;
}
F_20 (shrinker, &shrinker_list, list) {
unsigned long long V_23 ;
long V_24 ;
long V_25 ;
int V_26 = 0 ;
long V_27 ;
long V_28 ;
long V_29 = V_10 -> V_30 ? V_10 -> V_30
: V_31 ;
V_25 = F_17 ( V_10 , V_17 , 0 ) ;
if ( V_25 <= 0 )
continue;
V_27 = F_21 ( & V_10 -> V_11 , 0 ) ;
V_24 = V_27 ;
V_23 = ( 4 * V_18 ) / V_10 -> V_32 ;
V_23 *= V_25 ;
F_22 ( V_23 , V_19 + 1 ) ;
V_24 += V_23 ;
if ( V_24 < 0 ) {
F_23 ( V_33 L_1
L_2 ,
V_10 -> V_17 , V_24 ) ;
V_24 = V_25 ;
}
if ( V_23 < V_25 / 4 )
V_24 = F_24 ( V_24 , V_25 / 2 ) ;
if ( V_24 > V_25 * 2 )
V_24 = V_25 * 2 ;
F_25 ( V_10 , V_17 , V_27 ,
V_18 , V_19 ,
V_25 , V_23 , V_24 ) ;
while ( V_24 >= V_29 ) {
int V_34 ;
V_34 = F_17 ( V_10 , V_17 , 0 ) ;
V_26 = F_17 ( V_10 , V_17 ,
V_29 ) ;
if ( V_26 == - 1 )
break;
if ( V_26 < V_34 )
V_20 += V_34 - V_26 ;
F_26 ( V_35 , V_29 ) ;
V_24 -= V_29 ;
F_27 () ;
}
if ( V_24 > 0 )
V_28 = F_28 ( V_24 ,
& V_10 -> V_11 ) ;
else
V_28 = F_29 ( & V_10 -> V_11 ) ;
F_30 ( V_10 , V_26 , V_27 , V_28 ) ;
}
F_31 ( & V_12 ) ;
V_22:
F_27 () ;
return V_20 ;
}
static void F_32 ( int V_36 , struct V_3 * V_4 ,
bool V_37 )
{
T_1 V_38 = V_37 ? V_39 : V_40 ;
if ( V_41 )
V_4 -> V_42 = V_43 ;
else
V_4 -> V_42 = V_44 ;
if ( V_4 -> V_45 > V_46 )
V_4 -> V_42 |= V_38 ;
else if ( V_4 -> V_45 && V_36 < V_47 - 2 )
V_4 -> V_42 |= V_38 ;
else
V_4 -> V_42 = V_48 | V_40 ;
}
static void F_33 ( struct V_3 * V_4 )
{
V_4 -> V_42 = V_48 | V_40 ;
}
static inline int F_34 ( struct V_49 * V_49 )
{
return F_35 ( V_49 ) - F_36 ( V_49 ) == 2 ;
}
static int F_37 ( struct V_50 * V_51 ,
struct V_3 * V_4 )
{
if ( V_52 -> V_53 & V_54 )
return 1 ;
if ( ! F_38 ( V_51 ) )
return 1 ;
if ( V_51 == V_52 -> V_50 )
return 1 ;
if ( V_4 -> V_45 > V_46 )
return 1 ;
return 0 ;
}
static void F_39 ( struct V_55 * V_56 ,
struct V_49 * V_49 , int error )
{
F_40 ( V_49 ) ;
if ( F_41 ( V_49 ) == V_56 )
F_42 ( V_56 , error ) ;
F_43 ( V_49 ) ;
}
static T_2 F_44 ( struct V_49 * V_49 , struct V_55 * V_56 ,
struct V_3 * V_4 )
{
if ( ! F_34 ( V_49 ) )
return V_57 ;
if ( ! V_56 ) {
if ( F_36 ( V_49 ) ) {
if ( F_45 ( V_49 ) ) {
F_46 ( V_49 ) ;
F_23 ( L_3 , V_58 ) ;
return V_59 ;
}
}
return V_57 ;
}
if ( V_56 -> V_60 -> V_61 == NULL )
return V_62 ;
if ( ! F_37 ( V_56 -> V_50 , V_4 ) )
return V_57 ;
if ( F_47 ( V_49 ) ) {
int V_63 ;
struct V_64 V_65 = {
. V_66 = V_67 ,
. V_68 = V_21 ,
. V_69 = 0 ,
. V_70 = V_71 ,
. V_72 = 1 ,
} ;
F_48 ( V_49 ) ;
V_63 = V_56 -> V_60 -> V_61 ( V_49 , & V_65 ) ;
if ( V_63 < 0 )
F_39 ( V_56 , V_49 , V_63 ) ;
if ( V_63 == V_73 ) {
F_49 ( V_49 ) ;
return V_62 ;
}
if ( ! F_50 ( V_49 ) ) {
F_49 ( V_49 ) ;
}
F_51 ( V_49 ,
F_52 ( V_49 , V_4 -> V_42 ) ) ;
F_53 ( V_49 , V_74 ) ;
return V_75 ;
}
return V_59 ;
}
static int F_54 ( struct V_55 * V_56 , struct V_49 * V_49 )
{
F_55 ( ! F_56 ( V_49 ) ) ;
F_55 ( V_56 != F_41 ( V_49 ) ) ;
F_57 ( & V_56 -> V_76 ) ;
if ( ! F_58 ( V_49 , 2 ) )
goto V_77;
if ( F_59 ( F_60 ( V_49 ) ) ) {
F_61 ( V_49 , 2 ) ;
goto V_77;
}
if ( F_62 ( V_49 ) ) {
T_3 V_78 = { . V_79 = F_63 (page) } ;
F_64 ( V_49 ) ;
F_65 ( & V_56 -> V_76 ) ;
F_66 ( V_78 , V_49 ) ;
} else {
void (* F_67)( struct V_49 * );
F_67 = V_56 -> V_60 -> F_67 ;
F_68 ( V_49 ) ;
F_65 ( & V_56 -> V_76 ) ;
F_69 ( V_49 ) ;
if ( F_67 != NULL )
F_67 ( V_49 ) ;
}
return 1 ;
V_77:
F_65 ( & V_56 -> V_76 ) ;
return 0 ;
}
int F_70 ( struct V_55 * V_56 , struct V_49 * V_49 )
{
if ( F_54 ( V_56 , V_49 ) ) {
F_61 ( V_49 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_71 ( struct V_49 * V_49 )
{
int V_8 ;
int V_80 = ! ! F_72 ( V_49 ) ;
int V_81 = F_73 ( V_49 ) ;
F_74 ( F_75 ( V_49 ) ) ;
V_82:
F_76 ( V_49 ) ;
if ( F_77 ( V_49 , NULL ) ) {
V_8 = V_80 + F_78 ( V_49 ) ;
F_79 ( V_49 , V_8 ) ;
} else {
V_8 = V_83 ;
F_80 ( V_49 ) ;
F_81 () ;
}
if ( V_8 == V_83 && F_77 ( V_49 , NULL ) ) {
if ( ! F_82 ( V_49 ) ) {
F_83 ( V_49 ) ;
goto V_82;
}
}
if ( V_81 && V_8 != V_83 )
F_84 ( V_84 ) ;
else if ( ! V_81 && V_8 == V_83 )
F_84 ( V_85 ) ;
F_83 ( V_49 ) ;
}
static enum V_86 F_85 ( struct V_49 * V_49 ,
struct V_3 * V_4 )
{
int V_87 , V_88 ;
unsigned long V_89 ;
V_87 = F_86 ( V_49 , 1 , V_4 -> V_5 , & V_89 ) ;
V_88 = F_87 ( V_49 ) ;
if ( V_4 -> V_42 & V_44 )
return V_90 ;
if ( V_89 & V_91 )
return V_90 ;
if ( V_87 ) {
if ( F_88 ( V_49 ) )
return V_92 ;
F_89 ( V_49 ) ;
if ( V_88 )
return V_92 ;
return V_93 ;
}
if ( V_88 && ! F_90 ( V_49 ) )
return V_94 ;
return V_90 ;
}
static T_4 void F_91 ( struct V_95 * V_96 )
{
struct V_97 V_98 ;
struct V_49 * V_49 , * V_99 ;
F_92 ( & V_98 , 1 ) ;
F_93 (page, tmp, free_pages, lru) {
F_16 ( & V_49 -> V_8 ) ;
if ( ! F_94 ( & V_98 , V_49 ) ) {
F_95 ( & V_98 ) ;
F_96 ( & V_98 ) ;
}
}
F_97 ( & V_98 ) ;
}
static unsigned long F_98 ( struct V_95 * V_100 ,
struct V_2 * V_2 ,
struct V_3 * V_4 ,
int V_36 ,
unsigned long * V_101 ,
unsigned long * V_102 )
{
F_99 ( V_103 ) ;
F_99 ( V_96 ) ;
int V_104 = 0 ;
unsigned long V_105 = 0 ;
unsigned long V_106 = 0 ;
unsigned long V_107 = 0 ;
unsigned long V_108 = 0 ;
F_27 () ;
while ( ! F_100 ( V_100 ) ) {
enum V_86 V_109 ;
struct V_55 * V_56 ;
struct V_49 * V_49 ;
int V_110 ;
F_27 () ;
V_49 = F_101 ( V_100 ) ;
F_16 ( & V_49 -> V_8 ) ;
if ( ! F_102 ( V_49 ) )
goto V_111;
F_74 ( F_103 ( V_49 ) ) ;
F_74 ( F_104 ( V_49 ) != V_2 ) ;
V_4 -> V_112 ++ ;
if ( F_59 ( ! F_77 ( V_49 , NULL ) ) )
goto V_113;
if ( ! V_4 -> V_114 && F_105 ( V_49 ) )
goto V_115;
if ( F_105 ( V_49 ) || F_62 ( V_49 ) )
V_4 -> V_112 ++ ;
V_110 = ( V_4 -> V_116 & V_117 ) ||
( F_62 ( V_49 ) && ( V_4 -> V_116 & V_118 ) ) ;
if ( F_50 ( V_49 ) ) {
V_108 ++ ;
if ( ( V_4 -> V_42 & V_39 ) &&
V_110 )
F_106 ( V_49 ) ;
else {
F_43 ( V_49 ) ;
goto V_119;
}
}
V_109 = F_85 ( V_49 , V_4 ) ;
switch ( V_109 ) {
case V_92 :
goto V_120;
case V_93 :
goto V_115;
case V_90 :
case V_94 :
;
}
if ( F_88 ( V_49 ) && ! F_62 ( V_49 ) ) {
if ( ! ( V_4 -> V_116 & V_118 ) )
goto V_115;
if ( ! F_107 ( V_49 ) )
goto V_120;
V_110 = 1 ;
}
V_56 = F_41 ( V_49 ) ;
if ( F_105 ( V_49 ) && V_56 ) {
switch ( F_108 ( V_49 , V_121 ) ) {
case V_122 :
goto V_120;
case V_123 :
goto V_115;
case V_124 :
goto V_113;
case V_125 :
;
}
}
if ( F_60 ( V_49 ) ) {
V_105 ++ ;
if ( F_109 ( V_49 ) &&
( ! F_110 () || V_36 >= V_47 - 2 ) ) {
F_53 ( V_49 , V_126 ) ;
F_48 ( V_49 ) ;
goto V_115;
}
if ( V_109 == V_94 )
goto V_115;
if ( ! V_110 )
goto V_115;
if ( ! V_4 -> V_127 )
goto V_115;
switch ( F_44 ( V_49 , V_56 , V_4 ) ) {
case V_57 :
V_106 ++ ;
goto V_115;
case V_62 :
goto V_120;
case V_75 :
if ( F_50 ( V_49 ) )
goto V_119;
if ( F_60 ( V_49 ) )
goto V_111;
if ( ! F_102 ( V_49 ) )
goto V_111;
if ( F_60 ( V_49 ) || F_50 ( V_49 ) )
goto V_115;
V_56 = F_41 ( V_49 ) ;
case V_59 :
;
}
}
if ( F_36 ( V_49 ) ) {
if ( ! F_111 ( V_49 , V_4 -> V_116 ) )
goto V_120;
if ( ! V_56 && F_35 ( V_49 ) == 1 ) {
F_43 ( V_49 ) ;
if ( F_112 ( V_49 ) )
goto V_128;
else {
V_107 ++ ;
continue;
}
}
}
if ( ! V_56 || ! F_54 ( V_56 , V_49 ) )
goto V_115;
F_113 ( V_49 ) ;
V_128:
V_107 ++ ;
F_114 ( & V_49 -> V_8 , & V_96 ) ;
continue;
V_113:
if ( F_62 ( V_49 ) )
F_115 ( V_49 ) ;
F_43 ( V_49 ) ;
F_71 ( V_49 ) ;
F_33 ( V_4 ) ;
continue;
V_120:
if ( F_62 ( V_49 ) && F_116 () )
F_115 ( V_49 ) ;
F_74 ( F_103 ( V_49 ) ) ;
F_117 ( V_49 ) ;
V_104 ++ ;
V_115:
F_43 ( V_49 ) ;
V_111:
F_33 ( V_4 ) ;
V_119:
F_114 ( & V_49 -> V_8 , & V_103 ) ;
F_74 ( F_75 ( V_49 ) || F_73 ( V_49 ) ) ;
}
if ( V_105 && V_105 == V_106 && F_2 ( V_4 ) )
F_118 ( V_2 , V_129 ) ;
F_91 ( & V_96 ) ;
F_119 ( & V_103 , V_100 ) ;
F_26 ( V_130 , V_104 ) ;
* V_101 += V_105 ;
* V_102 += V_108 ;
return V_107 ;
}
int F_120 ( struct V_49 * V_49 , T_5 V_131 , int V_132 )
{
bool V_133 ;
int V_20 = - V_134 ;
if ( ! F_75 ( V_49 ) )
return V_20 ;
V_133 = ( V_131 & ( V_135 | V_136 ) ) ==
( V_135 | V_136 ) ;
if ( ! V_133 && ! F_103 ( V_49 ) != ! ( V_131 & V_135 ) )
return V_20 ;
if ( ! V_133 && ! ! F_109 ( V_49 ) != V_132 )
return V_20 ;
if ( F_73 ( V_49 ) )
return V_20 ;
V_20 = - V_137 ;
if ( ( V_131 & V_138 ) && ( F_60 ( V_49 ) || F_50 ( V_49 ) ) )
return V_20 ;
if ( ( V_131 & V_139 ) && F_105 ( V_49 ) )
return V_20 ;
if ( F_121 ( F_122 ( V_49 ) ) ) {
F_123 ( V_49 ) ;
V_20 = 0 ;
}
return V_20 ;
}
static unsigned long F_124 ( unsigned long V_16 ,
struct V_95 * V_140 , struct V_95 * V_141 ,
unsigned long * V_142 , int V_45 , T_5 V_131 ,
int V_132 )
{
unsigned long V_143 = 0 ;
unsigned long V_144 = 0 ;
unsigned long V_145 = 0 ;
unsigned long V_146 = 0 ;
unsigned long V_147 ;
for ( V_147 = 0 ; V_147 < V_16 && ! F_100 ( V_140 ) ; V_147 ++ ) {
struct V_49 * V_49 ;
unsigned long V_148 ;
unsigned long V_149 ;
unsigned long V_150 ;
int V_151 ;
V_49 = F_101 ( V_140 ) ;
F_125 ( V_49 , V_140 , V_53 ) ;
F_74 ( ! F_75 ( V_49 ) ) ;
switch ( F_120 ( V_49 , V_131 , V_132 ) ) {
case 0 :
F_126 ( & V_49 -> V_8 , V_141 ) ;
F_127 ( V_49 ) ;
V_143 += F_128 ( V_49 ) ;
break;
case - V_137 :
F_126 ( & V_49 -> V_8 , V_140 ) ;
F_129 ( V_49 , F_130 ( V_49 ) ) ;
continue;
default:
F_131 () ;
}
if ( ! V_45 )
continue;
V_151 = F_132 ( V_49 ) ;
V_150 = F_133 ( V_49 ) ;
V_148 = V_150 & ~ ( ( 1 << V_45 ) - 1 ) ;
V_149 = V_148 + ( 1 << V_45 ) ;
for (; V_148 < V_149 ; V_148 ++ ) {
struct V_49 * V_152 ;
if ( F_59 ( V_148 == V_150 ) )
continue;
if ( F_59 ( ! F_134 ( V_148 ) ) )
break;
V_152 = F_135 ( V_148 ) ;
if ( F_59 ( F_132 ( V_152 ) != V_151 ) )
break;
if ( V_153 <= 0 && F_88 ( V_152 ) &&
! F_62 ( V_152 ) )
break;
if ( F_120 ( V_152 , V_131 , V_132 ) == 0 ) {
F_126 ( & V_152 -> V_8 , V_141 ) ;
F_127 ( V_152 ) ;
V_143 += F_128 ( V_49 ) ;
V_144 ++ ;
if ( F_60 ( V_152 ) )
V_145 ++ ;
V_147 ++ ;
} else {
if ( ! F_136 ( V_152 ) &&
! F_137 ( & V_152 -> V_154 ) )
continue;
break;
}
}
if ( V_148 < V_149 )
V_146 ++ ;
}
* V_142 = V_147 ;
F_138 ( V_45 ,
V_16 , V_147 ,
V_143 ,
V_144 , V_145 , V_146 ,
V_131 ) ;
return V_143 ;
}
static unsigned long F_139 ( unsigned long V_27 ,
struct V_95 * V_141 ,
unsigned long * V_142 , int V_45 ,
T_5 V_131 ,
struct V_2 * V_155 , int V_80 , int V_132 )
{
int V_8 = V_156 ;
if ( V_80 )
V_8 += V_157 ;
if ( V_132 )
V_8 += V_158 ;
return F_124 ( V_27 , & V_155 -> V_8 [ V_8 ] . V_13 , V_141 , V_142 , V_45 ,
V_131 , V_132 ) ;
}
static unsigned long F_140 ( struct V_95 * V_100 ,
unsigned int * V_159 )
{
int V_160 = 0 ;
int V_8 ;
struct V_49 * V_49 ;
F_20 (page, page_list, lru) {
int V_161 = F_128 ( V_49 ) ;
V_8 = F_78 ( V_49 ) ;
if ( F_103 ( V_49 ) ) {
V_8 += V_157 ;
F_141 ( V_49 ) ;
V_160 += V_161 ;
}
if ( V_159 )
V_159 [ V_8 ] += V_161 ;
}
return V_160 ;
}
int F_82 ( struct V_49 * V_49 )
{
int V_20 = - V_137 ;
F_74 ( ! F_35 ( V_49 ) ) ;
if ( F_75 ( V_49 ) ) {
struct V_2 * V_2 = F_104 ( V_49 ) ;
F_57 ( & V_2 -> V_162 ) ;
if ( F_75 ( V_49 ) ) {
int V_8 = F_130 ( V_49 ) ;
V_20 = 0 ;
F_142 ( V_49 ) ;
F_123 ( V_49 ) ;
F_143 ( V_2 , V_49 , V_8 ) ;
}
F_65 ( & V_2 -> V_162 ) ;
}
return V_20 ;
}
static int F_144 ( struct V_2 * V_2 , int V_132 ,
struct V_3 * V_4 )
{
unsigned long V_163 , V_164 ;
if ( F_110 () )
return 0 ;
if ( ! F_2 ( V_4 ) )
return 0 ;
if ( V_132 ) {
V_163 = F_9 ( V_2 , V_165 ) ;
V_164 = F_9 ( V_2 , V_166 ) ;
} else {
V_163 = F_9 ( V_2 , V_167 ) ;
V_164 = F_9 ( V_2 , V_168 ) ;
}
return V_164 > V_163 ;
}
static T_4 void
F_145 ( struct V_2 * V_2 , struct V_3 * V_4 ,
unsigned long V_169 , unsigned long V_170 ,
struct V_95 * V_100 )
{
struct V_49 * V_49 ;
struct V_97 V_171 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
F_92 ( & V_171 , 1 ) ;
F_146 ( & V_2 -> V_162 ) ;
while ( ! F_100 ( V_100 ) ) {
int V_8 ;
V_49 = F_101 ( V_100 ) ;
F_74 ( F_75 ( V_49 ) ) ;
F_16 ( & V_49 -> V_8 ) ;
if ( F_59 ( ! F_77 ( V_49 , NULL ) ) ) {
F_65 ( & V_2 -> V_162 ) ;
F_71 ( V_49 ) ;
F_57 ( & V_2 -> V_162 ) ;
continue;
}
F_147 ( V_49 ) ;
V_8 = F_130 ( V_49 ) ;
F_148 ( V_2 , V_49 , V_8 ) ;
if ( F_149 ( V_8 ) ) {
int V_132 = F_150 ( V_8 ) ;
int V_161 = F_128 ( V_49 ) ;
V_6 -> V_172 [ V_132 ] += V_161 ;
}
if ( ! F_94 ( & V_171 , V_49 ) ) {
F_65 ( & V_2 -> V_162 ) ;
F_151 ( & V_171 ) ;
F_57 ( & V_2 -> V_162 ) ;
}
}
F_152 ( V_2 , V_168 , - V_169 ) ;
F_152 ( V_2 , V_166 , - V_170 ) ;
F_65 ( & V_2 -> V_162 ) ;
F_153 ( & V_171 ) ;
}
static T_4 void F_154 ( struct V_2 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_169 ,
unsigned long * V_170 ,
struct V_95 * V_173 )
{
unsigned long V_160 ;
unsigned int V_159 [ V_174 ] = { 0 , } ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
V_160 = F_140 ( V_173 , V_159 ) ;
F_155 ( V_175 , V_160 ) ;
F_152 ( V_2 , V_176 ,
- V_159 [ V_177 ] ) ;
F_152 ( V_2 , V_165 ,
- V_159 [ V_178 ] ) ;
F_152 ( V_2 , V_179 ,
- V_159 [ V_180 ] ) ;
F_152 ( V_2 , V_167 ,
- V_159 [ V_181 ] ) ;
* V_169 = V_159 [ V_180 ] + V_159 [ V_181 ] ;
* V_170 = V_159 [ V_177 ] + V_159 [ V_178 ] ;
F_152 ( V_2 , V_168 , * V_169 ) ;
F_152 ( V_2 , V_166 , * V_170 ) ;
V_6 -> V_182 [ 0 ] += * V_169 ;
V_6 -> V_182 [ 1 ] += * V_170 ;
}
static inline bool F_156 ( unsigned long V_143 ,
unsigned long V_183 ,
int V_36 ,
struct V_3 * V_4 )
{
int V_184 ;
if ( F_110 () )
return false ;
if ( V_4 -> V_42 & V_48 )
return false ;
if ( V_183 == V_143 )
return false ;
if ( V_4 -> V_45 > V_46 )
V_184 = V_47 ;
else
V_184 = V_47 / 3 ;
return V_36 <= V_184 ;
}
static T_4 unsigned long
F_157 ( unsigned long V_16 , struct V_2 * V_2 ,
struct V_3 * V_4 , int V_36 , int V_132 )
{
F_99 ( V_100 ) ;
unsigned long V_112 ;
unsigned long V_107 = 0 ;
unsigned long V_143 ;
unsigned long V_169 ;
unsigned long V_170 ;
unsigned long V_105 = 0 ;
unsigned long V_108 = 0 ;
T_5 V_42 = V_136 ;
while ( F_59 ( F_144 ( V_2 , V_132 , V_4 ) ) ) {
F_158 ( V_185 , V_186 / 10 ) ;
if ( F_159 ( V_52 ) )
return V_21 ;
}
F_32 ( V_36 , V_4 , false ) ;
if ( V_4 -> V_42 & V_44 )
V_42 |= V_135 ;
F_160 () ;
if ( ! V_4 -> V_114 )
V_42 |= V_139 ;
if ( ! V_4 -> V_127 )
V_42 |= V_138 ;
F_57 ( & V_2 -> V_162 ) ;
if ( F_2 ( V_4 ) ) {
V_143 = F_139 ( V_16 , & V_100 ,
& V_112 , V_4 -> V_45 , V_42 , V_2 , 0 , V_132 ) ;
V_2 -> V_187 += V_112 ;
if ( F_110 () )
F_161 ( V_188 , V_2 ,
V_112 ) ;
else
F_161 ( V_189 , V_2 ,
V_112 ) ;
} else {
V_143 = F_162 ( V_16 , & V_100 ,
& V_112 , V_4 -> V_45 , V_42 , V_2 ,
V_4 -> V_5 , 0 , V_132 ) ;
}
if ( V_143 == 0 ) {
F_65 ( & V_2 -> V_162 ) ;
return 0 ;
}
F_154 ( V_2 , V_4 , & V_169 , & V_170 , & V_100 ) ;
F_65 ( & V_2 -> V_162 ) ;
V_107 = F_98 ( & V_100 , V_2 , V_4 , V_36 ,
& V_105 , & V_108 ) ;
if ( F_156 ( V_143 , V_107 , V_36 , V_4 ) ) {
F_32 ( V_36 , V_4 , true ) ;
V_107 += F_98 ( & V_100 , V_2 , V_4 ,
V_36 , & V_105 , & V_108 ) ;
}
F_163 () ;
if ( F_110 () )
F_155 ( V_190 , V_107 ) ;
F_161 ( V_191 , V_2 , V_107 ) ;
F_145 ( V_2 , V_4 , V_169 , V_170 , & V_100 ) ;
if ( V_108 && V_108 >= ( V_143 >> ( V_47 - V_36 ) ) )
F_164 ( V_2 , V_185 , V_186 / 10 ) ;
F_165 ( V_2 -> V_192 -> V_193 ,
F_7 ( V_2 ) ,
V_112 , V_107 ,
V_36 ,
F_166 ( V_132 , V_4 -> V_42 ) ) ;
return V_107 ;
}
static void F_167 ( struct V_2 * V_2 ,
struct V_95 * V_13 ,
enum V_7 V_8 )
{
unsigned long V_194 = 0 ;
struct V_97 V_171 ;
struct V_49 * V_49 ;
F_92 ( & V_171 , 1 ) ;
while ( ! F_100 ( V_13 ) ) {
V_49 = F_101 ( V_13 ) ;
F_74 ( F_75 ( V_49 ) ) ;
F_147 ( V_49 ) ;
F_126 ( & V_49 -> V_8 , & V_2 -> V_8 [ V_8 ] . V_13 ) ;
F_168 ( V_49 , V_8 ) ;
V_194 += F_128 ( V_49 ) ;
if ( ! F_94 ( & V_171 , V_49 ) || F_100 ( V_13 ) ) {
F_65 ( & V_2 -> V_162 ) ;
if ( V_195 )
F_169 ( & V_171 ) ;
F_151 ( & V_171 ) ;
F_57 ( & V_2 -> V_162 ) ;
}
}
F_152 ( V_2 , V_9 + V_8 , V_194 ) ;
if ( ! F_149 ( V_8 ) )
F_155 ( V_175 , V_194 ) ;
}
static void F_170 ( unsigned long V_196 , struct V_2 * V_2 ,
struct V_3 * V_4 , int V_36 , int V_132 )
{
unsigned long V_143 ;
unsigned long V_197 ;
unsigned long V_89 ;
F_99 ( V_198 ) ;
F_99 ( V_199 ) ;
F_99 ( V_200 ) ;
struct V_49 * V_49 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
unsigned long V_201 = 0 ;
T_5 V_42 = V_135 ;
F_160 () ;
if ( ! V_4 -> V_114 )
V_42 |= V_139 ;
if ( ! V_4 -> V_127 )
V_42 |= V_138 ;
F_57 ( & V_2 -> V_162 ) ;
if ( F_2 ( V_4 ) ) {
V_143 = F_139 ( V_196 , & V_198 ,
& V_197 , V_4 -> V_45 ,
V_42 , V_2 ,
1 , V_132 ) ;
V_2 -> V_187 += V_197 ;
} else {
V_143 = F_162 ( V_196 , & V_198 ,
& V_197 , V_4 -> V_45 ,
V_42 , V_2 ,
V_4 -> V_5 , 1 , V_132 ) ;
}
V_6 -> V_182 [ V_132 ] += V_143 ;
F_161 ( V_202 , V_2 , V_197 ) ;
if ( V_132 )
F_152 ( V_2 , V_176 , - V_143 ) ;
else
F_152 ( V_2 , V_179 , - V_143 ) ;
F_152 ( V_2 , V_168 + V_132 , V_143 ) ;
F_65 ( & V_2 -> V_162 ) ;
while ( ! F_100 ( & V_198 ) ) {
F_27 () ;
V_49 = F_101 ( & V_198 ) ;
F_16 ( & V_49 -> V_8 ) ;
if ( F_59 ( ! F_77 ( V_49 , NULL ) ) ) {
F_71 ( V_49 ) ;
continue;
}
if ( F_86 ( V_49 , 0 , V_4 -> V_5 , & V_89 ) ) {
V_201 += F_128 ( V_49 ) ;
if ( ( V_89 & V_203 ) && F_109 ( V_49 ) ) {
F_114 ( & V_49 -> V_8 , & V_199 ) ;
continue;
}
}
F_141 ( V_49 ) ;
F_114 ( & V_49 -> V_8 , & V_200 ) ;
}
F_57 ( & V_2 -> V_162 ) ;
V_6 -> V_172 [ V_132 ] += V_201 ;
F_167 ( V_2 , & V_199 ,
V_157 + V_132 * V_158 ) ;
F_167 ( V_2 , & V_200 ,
V_156 + V_132 * V_158 ) ;
F_152 ( V_2 , V_168 + V_132 , - V_143 ) ;
F_65 ( & V_2 -> V_162 ) ;
}
static int F_171 ( struct V_2 * V_2 )
{
unsigned long V_80 , V_163 ;
V_80 = F_9 ( V_2 , V_179 ) ;
V_163 = F_9 ( V_2 , V_167 ) ;
if ( V_163 * V_2 -> V_204 < V_80 )
return 1 ;
return 0 ;
}
static int F_172 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
int V_205 ;
if ( ! V_206 )
return 0 ;
if ( F_2 ( V_4 ) )
V_205 = F_171 ( V_2 ) ;
else
V_205 = F_173 ( V_4 -> V_5 , V_2 ) ;
return V_205 ;
}
static inline int F_172 ( struct V_2 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_174 ( struct V_2 * V_2 )
{
unsigned long V_80 , V_163 ;
V_80 = F_9 ( V_2 , V_176 ) ;
V_163 = F_9 ( V_2 , V_165 ) ;
return ( V_80 > V_163 ) ;
}
static int F_175 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
int V_205 ;
if ( F_2 ( V_4 ) )
V_205 = F_174 ( V_2 ) ;
else
V_205 = F_176 ( V_4 -> V_5 , V_2 ) ;
return V_205 ;
}
static int F_177 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_132 )
{
if ( V_132 )
return F_175 ( V_2 , V_4 ) ;
else
return F_172 ( V_2 , V_4 ) ;
}
static unsigned long F_178 ( enum V_7 V_8 , unsigned long V_16 ,
struct V_2 * V_2 , struct V_3 * V_4 , int V_36 )
{
int V_132 = F_150 ( V_8 ) ;
if ( F_149 ( V_8 ) ) {
if ( F_177 ( V_2 , V_4 , V_132 ) )
F_170 ( V_16 , V_2 , V_4 , V_36 , V_132 ) ;
return 0 ;
}
return F_157 ( V_16 , V_2 , V_4 , V_36 , V_132 ) ;
}
static int F_179 ( struct V_3 * V_4 )
{
if ( F_2 ( V_4 ) )
return V_207 ;
return F_180 ( V_4 -> V_5 ) ;
}
static void F_181 ( struct V_2 * V_2 , struct V_3 * V_4 ,
unsigned long * V_27 , int V_36 )
{
unsigned long V_208 , V_132 , free ;
unsigned long V_209 , V_210 ;
unsigned long V_211 , V_212 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
T_6 V_213 [ 2 ] , V_214 ;
enum V_7 V_215 ;
int V_216 = 0 ;
bool V_217 = false ;
if ( F_2 ( V_4 ) && F_110 () )
V_217 = true ;
if ( ! F_2 ( V_4 ) )
V_217 = true ;
if ( ! V_4 -> V_218 || ( V_153 <= 0 ) ) {
V_216 = 1 ;
V_213 [ 0 ] = 0 ;
V_213 [ 1 ] = 1 ;
V_214 = 1 ;
goto V_22;
}
V_208 = F_4 ( V_2 , V_4 , V_180 ) +
F_4 ( V_2 , V_4 , V_181 ) ;
V_132 = F_4 ( V_2 , V_4 , V_177 ) +
F_4 ( V_2 , V_4 , V_178 ) ;
if ( F_2 ( V_4 ) ) {
free = F_9 ( V_2 , V_219 ) ;
if ( F_59 ( V_132 + free <= F_182 ( V_2 ) ) ) {
V_213 [ 0 ] = 1 ;
V_213 [ 1 ] = 0 ;
V_214 = 1 ;
goto V_22;
}
}
V_209 = F_179 ( V_4 ) ;
V_210 = 200 - F_179 ( V_4 ) ;
F_57 ( & V_2 -> V_162 ) ;
if ( F_59 ( V_6 -> V_182 [ 0 ] > V_208 / 4 ) ) {
V_6 -> V_182 [ 0 ] /= 2 ;
V_6 -> V_172 [ 0 ] /= 2 ;
}
if ( F_59 ( V_6 -> V_182 [ 1 ] > V_132 / 4 ) ) {
V_6 -> V_182 [ 1 ] /= 2 ;
V_6 -> V_172 [ 1 ] /= 2 ;
}
V_211 = ( V_209 + 1 ) * ( V_6 -> V_182 [ 0 ] + 1 ) ;
V_211 /= V_6 -> V_172 [ 0 ] + 1 ;
V_212 = ( V_210 + 1 ) * ( V_6 -> V_182 [ 1 ] + 1 ) ;
V_212 /= V_6 -> V_172 [ 1 ] + 1 ;
F_65 ( & V_2 -> V_162 ) ;
V_213 [ 0 ] = V_211 ;
V_213 [ 1 ] = V_212 ;
V_214 = V_211 + V_212 + 1 ;
V_22:
F_183 (l) {
int V_132 = F_150 ( V_215 ) ;
unsigned long V_147 ;
V_147 = F_4 ( V_2 , V_4 , V_215 ) ;
if ( V_36 || V_216 ) {
V_147 >>= V_36 ;
if ( ! V_147 && V_217 )
V_147 = V_21 ;
V_147 = F_184 ( V_147 * V_213 [ V_132 ] , V_214 ) ;
}
V_27 [ V_215 ] = V_147 ;
}
}
static inline bool F_185 ( struct V_2 * V_2 ,
unsigned long V_107 ,
unsigned long V_112 ,
struct V_3 * V_4 )
{
unsigned long V_220 ;
unsigned long V_221 ;
if ( ! ( V_4 -> V_42 & V_43 ) )
return false ;
if ( V_4 -> V_116 & V_222 ) {
if ( ! V_107 && ! V_112 )
return false ;
} else {
if ( ! V_107 )
return false ;
}
V_220 = ( 2UL << V_4 -> V_45 ) ;
V_221 = F_4 ( V_2 , V_4 , V_181 ) +
F_4 ( V_2 , V_4 , V_178 ) ;
if ( V_4 -> V_107 < V_220 &&
V_221 > V_220 )
return true ;
switch ( F_186 ( V_2 , V_4 -> V_45 ) ) {
case V_223 :
case V_224 :
return false ;
default:
return true ;
}
}
static void F_187 ( int V_36 , struct V_2 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_27 [ V_174 ] ;
unsigned long V_16 ;
enum V_7 V_215 ;
unsigned long V_107 , V_112 ;
unsigned long V_225 = V_4 -> V_225 ;
struct V_226 V_227 ;
V_228:
V_107 = 0 ;
V_112 = V_4 -> V_112 ;
F_181 ( V_2 , V_4 , V_27 , V_36 ) ;
F_188 ( & V_227 ) ;
while ( V_27 [ V_181 ] || V_27 [ V_177 ] ||
V_27 [ V_178 ] ) {
F_183 (l) {
if ( V_27 [ V_215 ] ) {
V_16 = F_189 (unsigned long,
nr[l], SWAP_CLUSTER_MAX) ;
V_27 [ V_215 ] -= V_16 ;
V_107 += F_178 ( V_215 , V_16 ,
V_2 , V_4 , V_36 ) ;
}
}
if ( V_107 >= V_225 && V_36 < V_47 )
break;
}
F_190 ( & V_227 ) ;
V_4 -> V_107 += V_107 ;
if ( F_172 ( V_2 , V_4 ) )
F_170 ( V_21 , V_2 , V_4 , V_36 , 0 ) ;
if ( F_185 ( V_2 , V_107 ,
V_4 -> V_112 - V_112 , V_4 ) )
goto V_228;
F_191 ( V_4 -> V_116 ) ;
}
static bool F_192 ( int V_36 , struct V_229 * V_229 ,
struct V_3 * V_4 )
{
struct V_230 * V_155 ;
struct V_2 * V_2 ;
unsigned long V_231 ;
unsigned long V_232 ;
bool V_233 = false ;
F_193 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_194 ( V_2 ) )
continue;
if ( F_2 ( V_4 ) ) {
if ( ! F_195 ( V_2 , V_234 ) )
continue;
if ( V_2 -> V_235 && V_36 != V_47 )
continue;
if ( V_41 ) {
if ( V_4 -> V_45 > V_46 &&
( F_186 ( V_2 , V_4 -> V_45 ) ||
F_196 ( V_2 ) ) ) {
V_233 = true ;
continue;
}
}
V_232 = 0 ;
V_231 = F_197 ( V_2 ,
V_4 -> V_45 , V_4 -> V_116 ,
& V_232 ) ;
V_4 -> V_107 += V_231 ;
V_4 -> V_112 += V_232 ;
}
F_187 ( V_36 , V_2 , V_4 ) ;
}
return V_233 ;
}
static bool F_198 ( struct V_2 * V_2 )
{
return V_2 -> V_187 < F_199 ( V_2 ) * 6 ;
}
static bool V_235 ( struct V_229 * V_229 ,
struct V_3 * V_4 )
{
struct V_230 * V_155 ;
struct V_2 * V_2 ;
F_193 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_194 ( V_2 ) )
continue;
if ( ! F_195 ( V_2 , V_234 ) )
continue;
if ( ! V_2 -> V_235 )
return false ;
}
return true ;
}
static unsigned long F_200 ( struct V_229 * V_229 ,
struct V_3 * V_4 ,
struct V_15 * V_17 )
{
int V_36 ;
unsigned long V_236 = 0 ;
struct V_237 * V_237 = V_52 -> V_237 ;
struct V_230 * V_155 ;
struct V_2 * V_2 ;
unsigned long V_238 ;
F_201 () ;
F_202 () ;
if ( F_2 ( V_4 ) )
F_84 ( V_239 ) ;
for ( V_36 = V_47 ; V_36 >= 0 ; V_36 -- ) {
V_4 -> V_112 = 0 ;
if ( ! V_36 )
F_203 ( V_4 -> V_5 ) ;
if ( F_192 ( V_36 , V_229 , V_4 ) )
break;
if ( F_2 ( V_4 ) ) {
unsigned long V_19 = 0 ;
F_204 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_195 ( V_2 , V_234 ) )
continue;
V_19 += F_199 ( V_2 ) ;
}
F_18 ( V_17 , V_4 -> V_112 , V_19 ) ;
if ( V_237 ) {
V_4 -> V_107 += V_237 -> V_240 ;
V_237 -> V_240 = 0 ;
}
}
V_236 += V_4 -> V_112 ;
if ( V_4 -> V_107 >= V_4 -> V_225 )
goto V_22;
V_238 = V_4 -> V_225 + V_4 -> V_225 / 2 ;
if ( V_236 > V_238 ) {
F_205 ( V_241 ? 0 : V_236 ,
V_242 ) ;
V_4 -> V_127 = 1 ;
}
if ( ! V_4 -> V_243 && V_4 -> V_112 &&
V_36 < V_47 - 2 ) {
struct V_2 * V_244 ;
F_206 ( V_229 , F_207 ( V_4 -> V_116 ) ,
& V_245 ,
& V_244 ) ;
F_164 ( V_244 , V_185 , V_186 / 10 ) ;
}
}
V_22:
F_208 () ;
F_209 () ;
if ( V_4 -> V_107 )
return V_4 -> V_107 ;
if ( V_246 )
return 0 ;
if ( F_2 ( V_4 ) && ! V_235 ( V_229 , V_4 ) )
return 1 ;
return 0 ;
}
unsigned long F_210 ( struct V_229 * V_229 , int V_45 ,
T_7 V_116 , T_8 * V_247 )
{
unsigned long V_107 ;
struct V_3 V_4 = {
. V_116 = V_116 ,
. V_127 = ! V_241 ,
. V_225 = V_21 ,
. V_114 = 1 ,
. V_218 = 1 ,
. V_45 = V_45 ,
. V_5 = NULL ,
. V_247 = V_247 ,
} ;
struct V_15 V_17 = {
. V_116 = V_4 . V_116 ,
} ;
F_211 ( V_45 ,
V_4 . V_127 ,
V_116 ) ;
V_107 = F_200 ( V_229 , & V_4 , & V_17 ) ;
F_212 ( V_107 ) ;
return V_107 ;
}
unsigned long F_213 ( struct V_5 * V_248 ,
T_7 V_116 , bool V_216 ,
struct V_2 * V_2 ,
unsigned long * V_112 )
{
struct V_3 V_4 = {
. V_112 = 0 ,
. V_225 = V_21 ,
. V_127 = ! V_241 ,
. V_114 = 1 ,
. V_218 = ! V_216 ,
. V_45 = 0 ,
. V_5 = V_248 ,
} ;
V_4 . V_116 = ( V_116 & V_249 ) |
( V_250 & ~ V_249 ) ;
F_214 ( 0 ,
V_4 . V_127 ,
V_4 . V_116 ) ;
F_187 ( 0 , V_2 , & V_4 ) ;
F_215 ( V_4 . V_107 ) ;
* V_112 = V_4 . V_112 ;
return V_4 . V_107 ;
}
unsigned long F_216 ( struct V_5 * V_251 ,
T_7 V_116 ,
bool V_216 )
{
struct V_229 * V_229 ;
unsigned long V_107 ;
int V_252 ;
struct V_3 V_4 = {
. V_127 = ! V_241 ,
. V_114 = 1 ,
. V_218 = ! V_216 ,
. V_225 = V_21 ,
. V_45 = 0 ,
. V_5 = V_251 ,
. V_247 = NULL ,
. V_116 = ( V_116 & V_249 ) |
( V_250 & ~ V_249 ) ,
} ;
struct V_15 V_17 = {
. V_116 = V_4 . V_116 ,
} ;
V_252 = F_217 ( V_251 ) ;
V_229 = F_218 ( V_252 ) -> V_253 ;
F_219 ( 0 ,
V_4 . V_127 ,
V_4 . V_116 ) ;
V_107 = F_200 ( V_229 , & V_4 , & V_17 ) ;
F_220 ( V_107 ) ;
return V_107 ;
}
static bool F_221 ( T_9 * V_254 , unsigned long V_255 ,
int V_256 )
{
unsigned long V_257 = 0 ;
int V_258 ;
for ( V_258 = 0 ; V_258 <= V_256 ; V_258 ++ )
V_257 += V_254 -> V_259 [ V_258 ] . V_257 ;
return V_255 >= ( V_257 >> 2 ) ;
}
static bool F_222 ( T_9 * V_254 , int V_45 , long V_260 ,
int V_256 )
{
int V_258 ;
unsigned long V_261 = 0 ;
bool V_262 = true ;
if ( V_260 )
return true ;
for ( V_258 = 0 ; V_258 <= V_256 ; V_258 ++ ) {
struct V_2 * V_2 = V_254 -> V_259 + V_258 ;
if ( ! F_194 ( V_2 ) )
continue;
if ( V_2 -> V_235 ) {
V_261 += V_2 -> V_257 ;
continue;
}
if ( ! F_223 ( V_2 , V_45 , F_182 ( V_2 ) ,
V_258 , 0 ) )
V_262 = false ;
else
V_261 += V_2 -> V_257 ;
}
if ( V_45 )
return ! F_221 ( V_254 , V_261 , V_256 ) ;
else
return ! V_262 ;
}
static unsigned long F_224 ( T_9 * V_254 , int V_45 ,
int * V_256 )
{
int V_262 ;
unsigned long V_261 ;
int V_36 ;
int V_258 ;
int V_263 = 0 ;
unsigned long V_236 ;
struct V_237 * V_237 = V_52 -> V_237 ;
unsigned long V_231 ;
unsigned long V_232 ;
struct V_3 V_4 = {
. V_116 = V_234 ,
. V_114 = 1 ,
. V_218 = 1 ,
. V_225 = V_264 ,
. V_45 = V_45 ,
. V_5 = NULL ,
} ;
struct V_15 V_17 = {
. V_116 = V_4 . V_116 ,
} ;
V_265:
V_236 = 0 ;
V_4 . V_107 = 0 ;
V_4 . V_127 = ! V_241 ;
F_84 ( V_266 ) ;
for ( V_36 = V_47 ; V_36 >= 0 ; V_36 -- ) {
unsigned long V_19 = 0 ;
int V_267 = 0 ;
if ( ! V_36 )
F_203 ( NULL ) ;
V_262 = 1 ;
V_261 = 0 ;
for ( V_258 = V_254 -> V_268 - 1 ; V_258 >= 0 ; V_258 -- ) {
struct V_2 * V_2 = V_254 -> V_259 + V_258 ;
if ( ! F_194 ( V_2 ) )
continue;
if ( V_2 -> V_235 && V_36 != V_47 )
continue;
if ( F_172 ( V_2 , & V_4 ) )
F_170 ( V_21 , V_2 ,
& V_4 , V_36 , 0 ) ;
if ( ! F_223 ( V_2 , V_45 ,
F_182 ( V_2 ) , 0 , 0 ) ) {
V_263 = V_258 ;
break;
} else {
F_225 ( V_2 , V_129 ) ;
}
}
if ( V_258 < 0 )
goto V_22;
for ( V_258 = 0 ; V_258 <= V_263 ; V_258 ++ ) {
struct V_2 * V_2 = V_254 -> V_259 + V_258 ;
V_19 += F_199 ( V_2 ) ;
}
for ( V_258 = 0 ; V_258 <= V_263 ; V_258 ++ ) {
struct V_2 * V_2 = V_254 -> V_259 + V_258 ;
int V_269 ;
unsigned long V_270 ;
if ( ! F_194 ( V_2 ) )
continue;
if ( V_2 -> V_235 && V_36 != V_47 )
continue;
V_4 . V_112 = 0 ;
V_232 = 0 ;
V_231 = F_197 ( V_2 ,
V_45 , V_4 . V_116 ,
& V_232 ) ;
V_4 . V_107 += V_231 ;
V_236 += V_232 ;
V_270 = F_24 ( F_226 ( V_2 ) ,
( V_2 -> V_257 +
V_271 - 1 ) /
V_271 ) ;
if ( ! F_223 ( V_2 , V_45 ,
F_182 ( V_2 ) + V_270 ,
V_263 , 0 ) ) {
F_187 ( V_36 , V_2 , & V_4 ) ;
V_237 -> V_240 = 0 ;
V_269 = F_18 ( & V_17 , V_4 . V_112 , V_19 ) ;
V_4 . V_107 += V_237 -> V_240 ;
V_236 += V_4 . V_112 ;
if ( V_269 == 0 && ! F_198 ( V_2 ) )
V_2 -> V_235 = 1 ;
}
if ( V_236 > V_21 * 2 &&
V_236 > V_4 . V_107 + V_4 . V_107 / 2 )
V_4 . V_127 = 1 ;
if ( V_2 -> V_235 ) {
if ( V_263 && V_263 == V_258 )
V_263 -- ;
continue;
}
if ( ! F_223 ( V_2 , V_45 ,
F_182 ( V_2 ) , V_263 , 0 ) ) {
V_262 = 0 ;
if ( ! F_223 ( V_2 , V_45 ,
F_227 ( V_2 ) , V_263 , 0 ) )
V_267 = 1 ;
} else {
F_225 ( V_2 , V_129 ) ;
if ( V_258 <= * V_256 )
V_261 += V_2 -> V_257 ;
}
}
if ( V_262 || ( V_45 && F_221 ( V_254 , V_261 , * V_256 ) ) )
break;
if ( V_236 && ( V_36 < V_47 - 2 ) ) {
if ( V_267 )
F_84 ( V_272 ) ;
else
F_158 ( V_185 , V_186 / 10 ) ;
}
if ( V_4 . V_107 >= V_21 )
break;
}
V_22:
if ( ! ( V_262 || ( V_45 && F_221 ( V_254 , V_261 , * V_256 ) ) ) ) {
F_27 () ;
F_228 () ;
if ( V_4 . V_107 < V_21 )
V_45 = V_4 . V_45 = 0 ;
goto V_265;
}
if ( V_45 ) {
for ( V_258 = 0 ; V_258 <= V_263 ; V_258 ++ ) {
struct V_2 * V_2 = V_254 -> V_259 + V_258 ;
if ( ! F_194 ( V_2 ) )
continue;
if ( V_2 -> V_235 && V_36 != V_47 )
continue;
if ( ! F_229 ( V_2 , 0 ,
F_182 ( V_2 ) , 0 , 0 ) ) {
V_45 = V_4 . V_45 = 0 ;
goto V_265;
}
F_225 ( V_2 , V_129 ) ;
if ( V_258 <= * V_256 )
V_261 += V_2 -> V_257 ;
}
}
* V_256 = V_263 ;
return V_45 ;
}
static void F_230 ( T_9 * V_254 , int V_45 , int V_256 )
{
long V_260 = 0 ;
F_231 ( V_273 ) ;
if ( F_232 ( V_52 ) || F_233 () )
return;
F_234 ( & V_254 -> V_274 , & V_273 , V_275 ) ;
if ( ! F_222 ( V_254 , V_45 , V_260 , V_256 ) ) {
V_260 = F_235 ( V_186 / 10 ) ;
F_236 ( & V_254 -> V_274 , & V_273 ) ;
F_234 ( & V_254 -> V_274 , & V_273 , V_275 ) ;
}
if ( ! F_222 ( V_254 , V_45 , V_260 , V_256 ) ) {
F_237 ( V_254 -> V_193 ) ;
F_238 ( V_254 , V_276 ) ;
F_239 () ;
F_238 ( V_254 , V_277 ) ;
} else {
if ( V_260 )
F_84 ( V_278 ) ;
else
F_84 ( V_279 ) ;
}
F_236 ( & V_254 -> V_274 , & V_273 ) ;
}
static int F_240 ( void * V_280 )
{
unsigned long V_45 , V_281 ;
unsigned V_282 ;
int V_256 , V_283 ;
int V_284 ;
T_9 * V_254 = ( T_9 * ) V_280 ;
struct V_285 * V_286 = V_52 ;
struct V_237 V_237 = {
. V_240 = 0 ,
} ;
const struct V_287 * V_287 = F_241 ( V_254 -> V_193 ) ;
F_242 ( V_234 ) ;
if ( ! F_243 ( V_287 ) )
F_244 ( V_286 , V_287 ) ;
V_52 -> V_237 = & V_237 ;
V_286 -> V_53 |= V_288 | V_54 | V_289 ;
F_245 () ;
V_45 = V_281 = 0 ;
V_282 = 0 ;
V_256 = V_283 = V_254 -> V_268 - 1 ;
V_284 = V_256 ;
for ( ; ; ) {
int V_20 ;
if ( V_284 >= V_283 &&
V_282 == V_281 ) {
V_281 = V_254 -> V_290 ;
V_283 = V_254 -> V_256 ;
V_254 -> V_290 = 0 ;
V_254 -> V_256 = V_254 -> V_268 - 1 ;
}
if ( V_45 < V_281 || V_256 > V_283 ) {
V_45 = V_281 ;
V_256 = V_283 ;
} else {
F_230 ( V_254 , V_282 ,
V_284 ) ;
V_45 = V_254 -> V_290 ;
V_256 = V_254 -> V_256 ;
V_281 = V_45 ;
V_283 = V_256 ;
V_254 -> V_290 = 0 ;
V_254 -> V_256 = V_254 -> V_268 - 1 ;
}
V_20 = F_228 () ;
if ( F_233 () )
break;
if ( ! V_20 ) {
F_246 ( V_254 -> V_193 , V_45 ) ;
V_284 = V_256 ;
V_282 = F_224 ( V_254 , V_45 ,
& V_284 ) ;
}
}
return 0 ;
}
void F_247 ( struct V_2 * V_2 , int V_45 , enum V_291 V_256 )
{
T_9 * V_254 ;
if ( ! F_194 ( V_2 ) )
return;
if ( ! F_195 ( V_2 , V_234 ) )
return;
V_254 = V_2 -> V_192 ;
if ( V_254 -> V_290 < V_45 ) {
V_254 -> V_290 = V_45 ;
V_254 -> V_256 = F_24 ( V_254 -> V_256 , V_256 ) ;
}
if ( ! F_248 ( & V_254 -> V_274 ) )
return;
if ( F_223 ( V_2 , V_45 , F_226 ( V_2 ) , 0 , 0 ) )
return;
F_249 ( V_254 -> V_193 , F_7 ( V_2 ) , V_45 ) ;
F_250 ( & V_254 -> V_274 ) ;
}
unsigned long F_251 ( void )
{
int V_27 ;
V_27 = F_252 ( V_176 ) +
F_252 ( V_165 ) ;
if ( V_153 > 0 )
V_27 += F_252 ( V_179 ) +
F_252 ( V_167 ) ;
return V_27 ;
}
unsigned long F_199 ( struct V_2 * V_2 )
{
int V_27 ;
V_27 = F_9 ( V_2 , V_176 ) +
F_9 ( V_2 , V_165 ) ;
if ( V_153 > 0 )
V_27 += F_9 ( V_2 , V_179 ) +
F_9 ( V_2 , V_167 ) ;
return V_27 ;
}
unsigned long F_253 ( unsigned long V_225 )
{
struct V_237 V_237 ;
struct V_3 V_4 = {
. V_116 = V_250 ,
. V_218 = 1 ,
. V_114 = 1 ,
. V_127 = 1 ,
. V_225 = V_225 ,
. V_243 = 1 ,
. V_45 = 0 ,
} ;
struct V_15 V_17 = {
. V_116 = V_4 . V_116 ,
} ;
struct V_229 * V_229 = F_254 ( F_255 () , V_4 . V_116 ) ;
struct V_285 * V_280 = V_52 ;
unsigned long V_107 ;
V_280 -> V_53 |= V_288 ;
F_242 ( V_4 . V_116 ) ;
V_237 . V_240 = 0 ;
V_280 -> V_237 = & V_237 ;
V_107 = F_200 ( V_229 , & V_4 , & V_17 ) ;
V_280 -> V_237 = NULL ;
F_256 () ;
V_280 -> V_53 &= ~ V_288 ;
return V_107 ;
}
static int T_10 F_257 ( struct V_292 * V_293 ,
unsigned long V_294 , void * V_295 )
{
int V_252 ;
if ( V_294 == V_296 || V_294 == V_297 ) {
F_258 (nid, N_HIGH_MEMORY) {
T_9 * V_254 = F_218 ( V_252 ) ;
const struct V_287 * V_298 ;
V_298 = F_241 ( V_254 -> V_193 ) ;
if ( F_259 ( V_299 , V_298 ) < V_300 )
F_244 ( V_254 -> F_240 , V_298 ) ;
}
}
return V_301 ;
}
int F_260 ( int V_252 )
{
T_9 * V_254 = F_218 ( V_252 ) ;
int V_20 = 0 ;
if ( V_254 -> F_240 )
return 0 ;
V_254 -> F_240 = F_261 ( F_240 , V_254 , L_4 , V_252 ) ;
if ( F_262 ( V_254 -> F_240 ) ) {
F_55 ( V_302 == V_303 ) ;
F_23 ( L_5 , V_252 ) ;
V_20 = - 1 ;
}
return V_20 ;
}
void F_263 ( int V_252 )
{
struct V_285 * F_240 = F_218 ( V_252 ) -> F_240 ;
if ( F_240 )
F_264 ( F_240 ) ;
}
static int T_11 F_265 ( void )
{
int V_252 ;
F_266 () ;
F_258 (nid, N_HIGH_MEMORY)
F_260 ( V_252 ) ;
F_267 ( F_257 , 0 ) ;
return 0 ;
}
static inline unsigned long F_268 ( struct V_2 * V_2 )
{
unsigned long V_304 = F_9 ( V_2 , V_305 ) ;
unsigned long V_306 = F_9 ( V_2 , V_165 ) +
F_9 ( V_2 , V_176 ) ;
return ( V_306 > V_304 ) ? ( V_306 - V_304 ) : 0 ;
}
static long F_269 ( struct V_2 * V_2 )
{
long V_307 ;
long V_23 = 0 ;
if ( V_308 & V_309 )
V_307 = F_9 ( V_2 , V_310 ) ;
else
V_307 = F_268 ( V_2 ) ;
if ( ! ( V_308 & V_311 ) )
V_23 += F_9 ( V_2 , V_312 ) ;
if ( F_59 ( V_23 > V_307 ) )
V_23 = V_307 ;
return V_307 - V_23 ;
}
static int F_270 ( struct V_2 * V_2 , T_7 V_116 , unsigned int V_45 )
{
const unsigned long V_196 = 1 << V_45 ;
struct V_285 * V_280 = V_52 ;
struct V_237 V_237 ;
int V_36 ;
struct V_3 V_4 = {
. V_127 = ! ! ( V_308 & V_311 ) ,
. V_114 = ! ! ( V_308 & V_309 ) ,
. V_218 = 1 ,
. V_225 = F_271 (unsigned long, nr_pages,
SWAP_CLUSTER_MAX) ,
. V_116 = V_116 ,
. V_45 = V_45 ,
} ;
struct V_15 V_17 = {
. V_116 = V_4 . V_116 ,
} ;
unsigned long V_313 , V_314 ;
F_27 () ;
V_280 -> V_53 |= V_288 | V_54 ;
F_242 ( V_116 ) ;
V_237 . V_240 = 0 ;
V_280 -> V_237 = & V_237 ;
if ( F_269 ( V_2 ) > V_2 -> V_315 ) {
V_36 = V_316 ;
do {
F_187 ( V_36 , V_2 , & V_4 ) ;
V_36 -- ;
} while ( V_36 >= 0 && V_4 . V_107 < V_196 );
}
V_313 = F_9 ( V_2 , V_317 ) ;
if ( V_313 > V_2 -> V_318 ) {
for (; ; ) {
unsigned long V_19 = F_199 ( V_2 ) ;
if ( ! F_18 ( & V_17 , V_4 . V_112 , V_19 ) )
break;
V_314 = F_9 ( V_2 ,
V_317 ) ;
if ( V_314 + V_196 <= V_313 )
break;
}
V_314 = F_9 ( V_2 , V_317 ) ;
if ( V_314 < V_313 )
V_4 . V_107 += V_313 - V_314 ;
}
V_280 -> V_237 = NULL ;
V_52 -> V_53 &= ~ ( V_288 | V_54 ) ;
F_256 () ;
return V_4 . V_107 >= V_196 ;
}
int F_272 ( struct V_2 * V_2 , T_7 V_116 , unsigned int V_45 )
{
int V_193 ;
int V_20 ;
if ( F_269 ( V_2 ) <= V_2 -> V_315 &&
F_9 ( V_2 , V_317 ) <= V_2 -> V_318 )
return V_319 ;
if ( V_2 -> V_235 )
return V_319 ;
if ( ! ( V_116 & V_320 ) || ( V_52 -> V_53 & V_288 ) )
return V_321 ;
V_193 = F_6 ( V_2 ) ;
if ( F_273 ( V_193 , V_322 ) && V_193 != F_255 () )
return V_321 ;
if ( F_274 ( V_2 , V_323 ) )
return V_321 ;
V_20 = F_270 ( V_2 , V_116 , V_45 ) ;
F_225 ( V_2 , V_323 ) ;
if ( ! V_20 )
F_84 ( V_324 ) ;
return V_20 ;
}
int F_77 ( struct V_49 * V_49 , struct V_325 * V_326 )
{
if ( F_275 ( F_41 ( V_49 ) ) )
return 0 ;
if ( F_276 ( V_49 ) || ( V_326 && F_277 ( V_326 , V_49 ) ) )
return 0 ;
return 1 ;
}
static void F_278 ( struct V_49 * V_49 , struct V_2 * V_2 )
{
F_74 ( F_103 ( V_49 ) ) ;
V_327:
F_76 ( V_49 ) ;
if ( F_77 ( V_49 , NULL ) ) {
enum V_7 V_215 = F_78 ( V_49 ) ;
F_279 ( V_2 , V_328 ) ;
F_126 ( & V_49 -> V_8 , & V_2 -> V_8 [ V_215 ] . V_13 ) ;
F_280 ( V_49 , V_83 , V_215 ) ;
F_281 ( V_2 , V_167 + V_215 ) ;
F_282 ( V_84 ) ;
} else {
F_283 ( V_49 ) ;
F_126 ( & V_49 -> V_8 , & V_2 -> V_8 [ V_83 ] . V_13 ) ;
F_129 ( V_49 , V_83 ) ;
if ( F_77 ( V_49 , NULL ) )
goto V_327;
}
}
void F_284 ( struct V_55 * V_56 )
{
T_12 V_329 = 0 ;
T_12 V_330 = ( F_285 ( V_56 -> V_331 ) + V_332 - 1 ) >>
V_333 ;
struct V_2 * V_2 ;
struct V_97 V_171 ;
if ( V_56 -> V_334 == 0 )
return;
F_92 ( & V_171 , 0 ) ;
while ( V_329 < V_330 &&
F_286 ( & V_171 , V_56 , V_329 , V_335 ) ) {
int V_258 ;
int V_336 = 0 ;
V_2 = NULL ;
for ( V_258 = 0 ; V_258 < F_287 ( & V_171 ) ; V_258 ++ ) {
struct V_49 * V_49 = V_171 . V_337 [ V_258 ] ;
T_12 V_338 = V_49 -> V_339 ;
struct V_2 * V_340 = F_104 ( V_49 ) ;
V_336 ++ ;
if ( V_338 > V_329 )
V_329 = V_338 ;
V_329 ++ ;
if ( V_340 != V_2 ) {
if ( V_2 )
F_65 ( & V_2 -> V_162 ) ;
V_2 = V_340 ;
F_57 ( & V_2 -> V_162 ) ;
}
if ( F_75 ( V_49 ) && F_73 ( V_49 ) )
F_278 ( V_49 , V_2 ) ;
}
if ( V_2 )
F_65 ( & V_2 -> V_162 ) ;
F_153 ( & V_171 ) ;
F_26 ( V_341 , V_336 ) ;
}
}
static void F_288 ( void )
{
F_289 ( V_342
L_6
L_7
L_8 ) ;
}
int F_290 ( struct V_343 * V_344 , int V_345 ,
void T_13 * V_346 ,
T_14 * V_347 , T_15 * V_348 )
{
F_288 () ;
F_291 ( V_344 , V_345 , V_346 , V_347 , V_348 ) ;
V_349 = 0 ;
return 0 ;
}
static T_16 F_292 ( struct V_350 * V_351 ,
struct V_352 * V_353 ,
char * V_354 )
{
F_288 () ;
return sprintf ( V_354 , L_9 ) ;
}
static T_16 F_293 ( struct V_350 * V_351 ,
struct V_352 * V_353 ,
const char * V_354 , T_14 V_159 )
{
F_288 () ;
return 1 ;
}
int F_294 ( struct V_355 * V_355 )
{
return F_295 ( & V_355 -> V_356 , & V_357 ) ;
}
void F_296 ( struct V_355 * V_355 )
{
F_297 ( & V_355 -> V_356 , & V_357 ) ;
}
