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
V_10 -> V_11 = 0 ;
F_11 ( & V_12 ) ;
F_12 ( & V_10 -> V_13 , & V_14 ) ;
F_13 ( & V_12 ) ;
}
void F_14 ( struct V_10 * V_10 )
{
F_11 ( & V_12 ) ;
F_15 ( & V_10 -> V_13 ) ;
F_13 ( & V_12 ) ;
}
static inline int F_16 ( struct V_10 * V_10 ,
struct V_15 * V_4 ,
unsigned long V_16 )
{
V_4 -> V_16 = V_16 ;
return (* V_10 -> V_17 )( V_10 , V_4 ) ;
}
unsigned long F_17 ( struct V_15 * V_17 ,
unsigned long V_18 ,
unsigned long V_19 )
{
struct V_10 * V_10 ;
unsigned long V_20 = 0 ;
if ( V_18 == 0 )
V_18 = V_21 ;
if ( ! F_18 ( & V_12 ) ) {
V_20 = 1 ;
goto V_22;
}
F_19 (shrinker, &shrinker_list, list) {
unsigned long long V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
int V_26 = 0 ;
long V_11 ;
long V_27 ;
long V_28 = V_10 -> V_29 ? V_10 -> V_29
: V_30 ;
do {
V_11 = V_10 -> V_11 ;
} while ( F_20 ( & V_10 -> V_11 , V_11 , 0 ) != V_11 );
V_24 = V_11 ;
V_25 = F_16 ( V_10 , V_17 , 0 ) ;
V_23 = ( 4 * V_18 ) / V_10 -> V_31 ;
V_23 *= V_25 ;
F_21 ( V_23 , V_19 + 1 ) ;
V_24 += V_23 ;
if ( V_24 < 0 ) {
F_22 ( V_32 L_1
L_2 ,
V_10 -> V_17 , V_24 ) ;
V_24 = V_25 ;
}
if ( V_23 < V_25 / 4 )
V_24 = F_23 ( V_24 , V_25 / 2 ) ;
if ( V_24 > V_25 * 2 )
V_24 = V_25 * 2 ;
F_24 ( V_10 , V_17 , V_11 ,
V_18 , V_19 ,
V_25 , V_23 , V_24 ) ;
while ( V_24 >= V_28 ) {
int V_33 ;
V_33 = F_16 ( V_10 , V_17 , 0 ) ;
V_26 = F_16 ( V_10 , V_17 ,
V_28 ) ;
if ( V_26 == - 1 )
break;
if ( V_26 < V_33 )
V_20 += V_33 - V_26 ;
F_25 ( V_34 , V_28 ) ;
V_24 -= V_28 ;
F_26 () ;
}
do {
V_11 = V_10 -> V_11 ;
V_27 = V_24 + V_11 ;
if ( V_24 <= 0 )
break;
} while ( F_20 ( & V_10 -> V_11 , V_11 , V_27 ) != V_11 );
F_27 ( V_10 , V_26 , V_11 , V_27 ) ;
}
F_28 ( & V_12 ) ;
V_22:
F_26 () ;
return V_20 ;
}
static void F_29 ( int V_35 , struct V_3 * V_4 ,
bool V_36 )
{
T_1 V_37 = V_36 ? V_38 : V_39 ;
if ( V_40 )
V_4 -> V_41 = V_42 ;
else
V_4 -> V_41 = V_43 ;
if ( V_4 -> V_44 > V_45 )
V_4 -> V_41 |= V_37 ;
else if ( V_4 -> V_44 && V_35 < V_46 - 2 )
V_4 -> V_41 |= V_37 ;
else
V_4 -> V_41 = V_47 | V_39 ;
}
static void F_30 ( struct V_3 * V_4 )
{
V_4 -> V_41 = V_47 | V_39 ;
}
static inline int F_31 ( struct V_48 * V_48 )
{
return F_32 ( V_48 ) - F_33 ( V_48 ) == 2 ;
}
static int F_34 ( struct V_49 * V_50 ,
struct V_3 * V_4 )
{
if ( V_51 -> V_52 & V_53 )
return 1 ;
if ( ! F_35 ( V_50 ) )
return 1 ;
if ( V_50 == V_51 -> V_49 )
return 1 ;
if ( V_4 -> V_44 > V_45 )
return 1 ;
return 0 ;
}
static void F_36 ( struct V_54 * V_55 ,
struct V_48 * V_48 , int error )
{
F_37 ( V_48 ) ;
if ( F_38 ( V_48 ) == V_55 )
F_39 ( V_55 , error ) ;
F_40 ( V_48 ) ;
}
static T_2 F_41 ( struct V_48 * V_48 , struct V_54 * V_55 ,
struct V_3 * V_4 )
{
if ( ! F_31 ( V_48 ) )
return V_56 ;
if ( ! V_55 ) {
if ( F_33 ( V_48 ) ) {
if ( F_42 ( V_48 ) ) {
F_43 ( V_48 ) ;
F_22 ( L_3 , V_57 ) ;
return V_58 ;
}
}
return V_56 ;
}
if ( V_55 -> V_59 -> V_60 == NULL )
return V_61 ;
if ( ! F_34 ( V_55 -> V_49 , V_4 ) )
return V_56 ;
if ( F_44 ( V_48 ) ) {
int V_62 ;
struct V_63 V_64 = {
. V_65 = V_66 ,
. V_67 = V_21 ,
. V_68 = 0 ,
. V_69 = V_70 ,
. V_71 = 1 ,
} ;
F_45 ( V_48 ) ;
V_62 = V_55 -> V_59 -> V_60 ( V_48 , & V_64 ) ;
if ( V_62 < 0 )
F_36 ( V_55 , V_48 , V_62 ) ;
if ( V_62 == V_72 ) {
F_46 ( V_48 ) ;
return V_61 ;
}
if ( F_47 ( V_48 ) &&
( V_4 -> V_41 & V_38 ) )
F_48 ( V_48 ) ;
if ( ! F_47 ( V_48 ) ) {
F_46 ( V_48 ) ;
}
F_49 ( V_48 ,
F_50 ( V_48 , V_4 -> V_41 ) ) ;
F_51 ( V_48 , V_73 ) ;
return V_74 ;
}
return V_58 ;
}
static int F_52 ( struct V_54 * V_55 , struct V_48 * V_48 )
{
F_53 ( ! F_54 ( V_48 ) ) ;
F_53 ( V_55 != F_38 ( V_48 ) ) ;
F_55 ( & V_55 -> V_75 ) ;
if ( ! F_56 ( V_48 , 2 ) )
goto V_76;
if ( F_57 ( F_58 ( V_48 ) ) ) {
F_59 ( V_48 , 2 ) ;
goto V_76;
}
if ( F_60 ( V_48 ) ) {
T_3 V_77 = { . V_78 = F_61 (page) } ;
F_62 ( V_48 ) ;
F_63 ( & V_55 -> V_75 ) ;
F_64 ( V_77 , V_48 ) ;
} else {
void (* F_65)( struct V_48 * );
F_65 = V_55 -> V_59 -> F_65 ;
F_66 ( V_48 ) ;
F_63 ( & V_55 -> V_75 ) ;
F_67 ( V_48 ) ;
if ( F_65 != NULL )
F_65 ( V_48 ) ;
}
return 1 ;
V_76:
F_63 ( & V_55 -> V_75 ) ;
return 0 ;
}
int F_68 ( struct V_54 * V_55 , struct V_48 * V_48 )
{
if ( F_52 ( V_55 , V_48 ) ) {
F_59 ( V_48 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_69 ( struct V_48 * V_48 )
{
int V_8 ;
int V_79 = ! ! F_70 ( V_48 ) ;
int V_80 = F_71 ( V_48 ) ;
F_72 ( F_73 ( V_48 ) ) ;
V_81:
F_74 ( V_48 ) ;
if ( F_75 ( V_48 , NULL ) ) {
V_8 = V_79 + F_76 ( V_48 ) ;
F_77 ( V_48 , V_8 ) ;
} else {
V_8 = V_82 ;
F_78 ( V_48 ) ;
F_79 () ;
}
if ( V_8 == V_82 && F_75 ( V_48 , NULL ) ) {
if ( ! F_80 ( V_48 ) ) {
F_81 ( V_48 ) ;
goto V_81;
}
}
if ( V_80 && V_8 != V_82 )
F_82 ( V_83 ) ;
else if ( ! V_80 && V_8 == V_82 )
F_82 ( V_84 ) ;
F_81 ( V_48 ) ;
}
static enum V_85 F_83 ( struct V_48 * V_48 ,
struct V_3 * V_4 )
{
int V_86 , V_87 ;
unsigned long V_88 ;
V_86 = F_84 ( V_48 , 1 , V_4 -> V_5 , & V_88 ) ;
V_87 = F_85 ( V_48 ) ;
if ( V_4 -> V_41 & V_43 )
return V_89 ;
if ( V_88 & V_90 )
return V_89 ;
if ( V_86 ) {
if ( F_86 ( V_48 ) )
return V_91 ;
F_87 ( V_48 ) ;
if ( V_87 )
return V_91 ;
return V_92 ;
}
if ( V_87 && ! F_88 ( V_48 ) )
return V_93 ;
return V_89 ;
}
static T_4 void F_89 ( struct V_94 * V_95 )
{
struct V_96 V_97 ;
struct V_48 * V_48 , * V_98 ;
F_90 ( & V_97 , 1 ) ;
F_91 (page, tmp, free_pages, lru) {
F_15 ( & V_48 -> V_8 ) ;
if ( ! F_92 ( & V_97 , V_48 ) ) {
F_93 ( & V_97 ) ;
F_94 ( & V_97 ) ;
}
}
F_95 ( & V_97 ) ;
}
static unsigned long F_96 ( struct V_94 * V_99 ,
struct V_2 * V_2 ,
struct V_3 * V_4 )
{
F_97 ( V_100 ) ;
F_97 ( V_95 ) ;
int V_101 = 0 ;
unsigned long V_102 = 0 ;
unsigned long V_103 = 0 ;
unsigned long V_104 = 0 ;
F_26 () ;
while ( ! F_98 ( V_99 ) ) {
enum V_85 V_105 ;
struct V_54 * V_55 ;
struct V_48 * V_48 ;
int V_106 ;
F_26 () ;
V_48 = F_99 ( V_99 ) ;
F_15 ( & V_48 -> V_8 ) ;
if ( ! F_100 ( V_48 ) )
goto V_107;
F_72 ( F_101 ( V_48 ) ) ;
F_72 ( F_102 ( V_48 ) != V_2 ) ;
V_4 -> V_108 ++ ;
if ( F_57 ( ! F_75 ( V_48 , NULL ) ) )
goto V_109;
if ( ! V_4 -> V_110 && F_103 ( V_48 ) )
goto V_111;
if ( F_103 ( V_48 ) || F_60 ( V_48 ) )
V_4 -> V_108 ++ ;
V_106 = ( V_4 -> V_112 & V_113 ) ||
( F_60 ( V_48 ) && ( V_4 -> V_112 & V_114 ) ) ;
if ( F_47 ( V_48 ) ) {
if ( ( V_4 -> V_41 & V_38 ) &&
V_106 )
F_48 ( V_48 ) ;
else {
F_40 ( V_48 ) ;
goto V_115;
}
}
V_105 = F_83 ( V_48 , V_4 ) ;
switch ( V_105 ) {
case V_91 :
goto V_116;
case V_92 :
goto V_111;
case V_89 :
case V_93 :
;
}
if ( F_86 ( V_48 ) && ! F_60 ( V_48 ) ) {
if ( ! ( V_4 -> V_112 & V_114 ) )
goto V_111;
if ( ! F_104 ( V_48 ) )
goto V_116;
V_106 = 1 ;
}
V_55 = F_38 ( V_48 ) ;
if ( F_103 ( V_48 ) && V_55 ) {
switch ( F_105 ( V_48 , V_117 ) ) {
case V_118 :
goto V_116;
case V_119 :
goto V_111;
case V_120 :
goto V_109;
case V_121 :
;
}
}
if ( F_58 ( V_48 ) ) {
V_102 ++ ;
if ( V_105 == V_93 )
goto V_111;
if ( ! V_106 )
goto V_111;
if ( ! V_4 -> V_122 )
goto V_111;
switch ( F_41 ( V_48 , V_55 , V_4 ) ) {
case V_56 :
V_103 ++ ;
goto V_111;
case V_61 :
goto V_116;
case V_74 :
if ( F_47 ( V_48 ) )
goto V_115;
if ( F_58 ( V_48 ) )
goto V_107;
if ( ! F_100 ( V_48 ) )
goto V_107;
if ( F_58 ( V_48 ) || F_47 ( V_48 ) )
goto V_111;
V_55 = F_38 ( V_48 ) ;
case V_58 :
;
}
}
if ( F_33 ( V_48 ) ) {
if ( ! F_106 ( V_48 , V_4 -> V_112 ) )
goto V_116;
if ( ! V_55 && F_32 ( V_48 ) == 1 ) {
F_40 ( V_48 ) ;
if ( F_107 ( V_48 ) )
goto V_123;
else {
V_104 ++ ;
continue;
}
}
}
if ( ! V_55 || ! F_52 ( V_55 , V_48 ) )
goto V_111;
F_108 ( V_48 ) ;
V_123:
V_104 ++ ;
F_109 ( & V_48 -> V_8 , & V_95 ) ;
continue;
V_109:
if ( F_60 ( V_48 ) )
F_110 ( V_48 ) ;
F_40 ( V_48 ) ;
F_69 ( V_48 ) ;
F_30 ( V_4 ) ;
continue;
V_116:
if ( F_60 ( V_48 ) && F_111 () )
F_110 ( V_48 ) ;
F_72 ( F_101 ( V_48 ) ) ;
F_112 ( V_48 ) ;
V_101 ++ ;
V_111:
F_40 ( V_48 ) ;
V_107:
F_30 ( V_4 ) ;
V_115:
F_109 ( & V_48 -> V_8 , & V_100 ) ;
F_72 ( F_73 ( V_48 ) || F_71 ( V_48 ) ) ;
}
if ( V_102 && V_102 == V_103 && F_2 ( V_4 ) )
F_113 ( V_2 , V_124 ) ;
F_89 ( & V_95 ) ;
F_114 ( & V_100 , V_99 ) ;
F_25 ( V_125 , V_101 ) ;
return V_104 ;
}
int F_115 ( struct V_48 * V_48 , int V_126 , int V_127 )
{
int V_20 = - V_128 ;
if ( ! F_73 ( V_48 ) )
return V_20 ;
if ( V_126 != V_129 && ( ! F_101 ( V_48 ) != ! V_126 ) )
return V_20 ;
if ( V_126 != V_129 && F_116 ( V_48 ) != V_127 )
return V_20 ;
if ( F_71 ( V_48 ) )
return V_20 ;
V_20 = - V_130 ;
if ( F_117 ( F_118 ( V_48 ) ) ) {
F_119 ( V_48 ) ;
V_20 = 0 ;
}
return V_20 ;
}
static unsigned long F_120 ( unsigned long V_16 ,
struct V_94 * V_131 , struct V_94 * V_132 ,
unsigned long * V_133 , int V_44 , int V_126 , int V_127 )
{
unsigned long V_134 = 0 ;
unsigned long V_135 = 0 ;
unsigned long V_136 = 0 ;
unsigned long V_137 = 0 ;
unsigned long V_138 ;
for ( V_138 = 0 ; V_138 < V_16 && ! F_98 ( V_131 ) ; V_138 ++ ) {
struct V_48 * V_48 ;
unsigned long V_139 ;
unsigned long V_140 ;
unsigned long V_141 ;
int V_142 ;
V_48 = F_99 ( V_131 ) ;
F_121 ( V_48 , V_131 , V_52 ) ;
F_72 ( ! F_73 ( V_48 ) ) ;
switch ( F_115 ( V_48 , V_126 , V_127 ) ) {
case 0 :
F_122 ( & V_48 -> V_8 , V_132 ) ;
F_123 ( V_48 ) ;
V_134 += F_124 ( V_48 ) ;
break;
case - V_130 :
F_122 ( & V_48 -> V_8 , V_131 ) ;
F_125 ( V_48 , F_126 ( V_48 ) ) ;
continue;
default:
F_127 () ;
}
if ( ! V_44 )
continue;
V_142 = F_128 ( V_48 ) ;
V_141 = F_129 ( V_48 ) ;
V_139 = V_141 & ~ ( ( 1 << V_44 ) - 1 ) ;
V_140 = V_139 + ( 1 << V_44 ) ;
for (; V_139 < V_140 ; V_139 ++ ) {
struct V_48 * V_143 ;
if ( F_57 ( V_139 == V_141 ) )
continue;
if ( F_57 ( ! F_130 ( V_139 ) ) )
break;
V_143 = F_131 ( V_139 ) ;
if ( F_57 ( F_128 ( V_143 ) != V_142 ) )
break;
if ( V_144 <= 0 && F_86 ( V_143 ) &&
! F_60 ( V_143 ) )
break;
if ( F_115 ( V_143 , V_126 , V_127 ) == 0 ) {
F_122 ( & V_143 -> V_8 , V_132 ) ;
F_123 ( V_143 ) ;
V_134 += F_124 ( V_48 ) ;
V_135 ++ ;
if ( F_58 ( V_143 ) )
V_136 ++ ;
V_138 ++ ;
} else {
if ( ! F_132 ( V_143 ) &&
! F_133 ( & V_143 -> V_145 ) )
continue;
break;
}
}
if ( V_139 < V_140 )
V_137 ++ ;
}
* V_133 = V_138 ;
F_134 ( V_44 ,
V_16 , V_138 ,
V_134 ,
V_135 , V_136 , V_137 ,
V_126 ) ;
return V_134 ;
}
static unsigned long F_135 ( unsigned long V_11 ,
struct V_94 * V_132 ,
unsigned long * V_133 , int V_44 ,
int V_126 , struct V_2 * V_146 ,
int V_79 , int V_127 )
{
int V_8 = V_147 ;
if ( V_79 )
V_8 += V_148 ;
if ( V_127 )
V_8 += V_149 ;
return F_120 ( V_11 , & V_146 -> V_8 [ V_8 ] . V_13 , V_132 , V_133 , V_44 ,
V_126 , V_127 ) ;
}
static unsigned long F_136 ( struct V_94 * V_99 ,
unsigned int * V_150 )
{
int V_151 = 0 ;
int V_8 ;
struct V_48 * V_48 ;
F_19 (page, page_list, lru) {
int V_152 = F_124 ( V_48 ) ;
V_8 = F_76 ( V_48 ) ;
if ( F_101 ( V_48 ) ) {
V_8 += V_148 ;
F_137 ( V_48 ) ;
V_151 += V_152 ;
}
if ( V_150 )
V_150 [ V_8 ] += V_152 ;
}
return V_151 ;
}
int F_80 ( struct V_48 * V_48 )
{
int V_20 = - V_130 ;
F_72 ( ! F_32 ( V_48 ) ) ;
if ( F_73 ( V_48 ) ) {
struct V_2 * V_2 = F_102 ( V_48 ) ;
F_55 ( & V_2 -> V_153 ) ;
if ( F_73 ( V_48 ) ) {
int V_8 = F_126 ( V_48 ) ;
V_20 = 0 ;
F_138 ( V_48 ) ;
F_119 ( V_48 ) ;
F_139 ( V_2 , V_48 , V_8 ) ;
}
F_63 ( & V_2 -> V_153 ) ;
}
return V_20 ;
}
static int F_140 ( struct V_2 * V_2 , int V_127 ,
struct V_3 * V_4 )
{
unsigned long V_154 , V_155 ;
if ( F_141 () )
return 0 ;
if ( ! F_2 ( V_4 ) )
return 0 ;
if ( V_127 ) {
V_154 = F_9 ( V_2 , V_156 ) ;
V_155 = F_9 ( V_2 , V_157 ) ;
} else {
V_154 = F_9 ( V_2 , V_158 ) ;
V_155 = F_9 ( V_2 , V_159 ) ;
}
return V_155 > V_154 ;
}
static T_4 void
F_142 ( struct V_2 * V_2 , struct V_3 * V_4 ,
unsigned long V_160 , unsigned long V_161 ,
struct V_94 * V_99 )
{
struct V_48 * V_48 ;
struct V_96 V_162 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
F_90 ( & V_162 , 1 ) ;
F_143 ( & V_2 -> V_153 ) ;
while ( ! F_98 ( V_99 ) ) {
int V_8 ;
V_48 = F_99 ( V_99 ) ;
F_72 ( F_73 ( V_48 ) ) ;
F_15 ( & V_48 -> V_8 ) ;
if ( F_57 ( ! F_75 ( V_48 , NULL ) ) ) {
F_63 ( & V_2 -> V_153 ) ;
F_69 ( V_48 ) ;
F_55 ( & V_2 -> V_153 ) ;
continue;
}
F_144 ( V_48 ) ;
V_8 = F_126 ( V_48 ) ;
F_145 ( V_2 , V_48 , V_8 ) ;
if ( F_146 ( V_8 ) ) {
int V_127 = F_147 ( V_8 ) ;
int V_152 = F_124 ( V_48 ) ;
V_6 -> V_163 [ V_127 ] += V_152 ;
}
if ( ! F_92 ( & V_162 , V_48 ) ) {
F_63 ( & V_2 -> V_153 ) ;
F_148 ( & V_162 ) ;
F_55 ( & V_2 -> V_153 ) ;
}
}
F_149 ( V_2 , V_159 , - V_160 ) ;
F_149 ( V_2 , V_157 , - V_161 ) ;
F_63 ( & V_2 -> V_153 ) ;
F_150 ( & V_162 ) ;
}
static T_4 void F_151 ( struct V_2 * V_2 ,
struct V_3 * V_4 ,
unsigned long * V_160 ,
unsigned long * V_161 ,
struct V_94 * V_164 )
{
unsigned long V_151 ;
unsigned int V_150 [ V_165 ] = { 0 , } ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
V_151 = F_136 ( V_164 , V_150 ) ;
F_152 ( V_166 , V_151 ) ;
F_149 ( V_2 , V_167 ,
- V_150 [ V_168 ] ) ;
F_149 ( V_2 , V_156 ,
- V_150 [ V_169 ] ) ;
F_149 ( V_2 , V_170 ,
- V_150 [ V_171 ] ) ;
F_149 ( V_2 , V_158 ,
- V_150 [ V_172 ] ) ;
* V_160 = V_150 [ V_171 ] + V_150 [ V_172 ] ;
* V_161 = V_150 [ V_168 ] + V_150 [ V_169 ] ;
F_149 ( V_2 , V_159 , * V_160 ) ;
F_149 ( V_2 , V_157 , * V_161 ) ;
V_6 -> V_173 [ 0 ] += * V_160 ;
V_6 -> V_173 [ 1 ] += * V_161 ;
}
static inline bool F_153 ( unsigned long V_134 ,
unsigned long V_174 ,
int V_35 ,
struct V_3 * V_4 )
{
int V_175 ;
if ( F_141 () )
return false ;
if ( V_4 -> V_41 & V_47 )
return false ;
if ( V_174 == V_134 )
return false ;
if ( V_4 -> V_44 > V_45 )
V_175 = V_46 ;
else
V_175 = V_46 / 3 ;
return V_35 <= V_175 ;
}
static T_4 unsigned long
F_154 ( unsigned long V_16 , struct V_2 * V_2 ,
struct V_3 * V_4 , int V_35 , int V_127 )
{
F_97 ( V_99 ) ;
unsigned long V_108 ;
unsigned long V_104 = 0 ;
unsigned long V_134 ;
unsigned long V_160 ;
unsigned long V_161 ;
while ( F_57 ( F_140 ( V_2 , V_127 , V_4 ) ) ) {
F_155 ( V_176 , V_177 / 10 ) ;
if ( F_156 ( V_51 ) )
return V_21 ;
}
F_29 ( V_35 , V_4 , false ) ;
F_157 () ;
F_55 ( & V_2 -> V_153 ) ;
if ( F_2 ( V_4 ) ) {
V_134 = F_135 ( V_16 ,
& V_99 , & V_108 , V_4 -> V_44 ,
V_4 -> V_41 & V_43 ?
V_129 : V_178 ,
V_2 , 0 , V_127 ) ;
V_2 -> V_179 += V_108 ;
if ( F_141 () )
F_158 ( V_180 , V_2 ,
V_108 ) ;
else
F_158 ( V_181 , V_2 ,
V_108 ) ;
} else {
V_134 = F_159 ( V_16 ,
& V_99 , & V_108 , V_4 -> V_44 ,
V_4 -> V_41 & V_43 ?
V_129 : V_178 ,
V_2 , V_4 -> V_5 ,
0 , V_127 ) ;
}
if ( V_134 == 0 ) {
F_63 ( & V_2 -> V_153 ) ;
return 0 ;
}
F_151 ( V_2 , V_4 , & V_160 , & V_161 , & V_99 ) ;
F_63 ( & V_2 -> V_153 ) ;
V_104 = F_96 ( & V_99 , V_2 , V_4 ) ;
if ( F_153 ( V_134 , V_104 , V_35 , V_4 ) ) {
F_29 ( V_35 , V_4 , true ) ;
V_104 += F_96 ( & V_99 , V_2 , V_4 ) ;
}
F_160 () ;
if ( F_141 () )
F_152 ( V_182 , V_104 ) ;
F_158 ( V_183 , V_2 , V_104 ) ;
F_142 ( V_2 , V_4 , V_160 , V_161 , & V_99 ) ;
F_161 ( V_2 -> V_184 -> V_185 ,
F_7 ( V_2 ) ,
V_108 , V_104 ,
V_35 ,
F_162 ( V_127 , V_4 -> V_41 ) ) ;
return V_104 ;
}
static void F_163 ( struct V_2 * V_2 ,
struct V_94 * V_13 ,
enum V_7 V_8 )
{
unsigned long V_186 = 0 ;
struct V_96 V_162 ;
struct V_48 * V_48 ;
F_90 ( & V_162 , 1 ) ;
while ( ! F_98 ( V_13 ) ) {
V_48 = F_99 ( V_13 ) ;
F_72 ( F_73 ( V_48 ) ) ;
F_144 ( V_48 ) ;
F_122 ( & V_48 -> V_8 , & V_2 -> V_8 [ V_8 ] . V_13 ) ;
F_164 ( V_48 , V_8 ) ;
V_186 += F_124 ( V_48 ) ;
if ( ! F_92 ( & V_162 , V_48 ) || F_98 ( V_13 ) ) {
F_63 ( & V_2 -> V_153 ) ;
if ( V_187 )
F_165 ( & V_162 ) ;
F_148 ( & V_162 ) ;
F_55 ( & V_2 -> V_153 ) ;
}
}
F_149 ( V_2 , V_9 + V_8 , V_186 ) ;
if ( ! F_146 ( V_8 ) )
F_152 ( V_166 , V_186 ) ;
}
static void F_166 ( unsigned long V_188 , struct V_2 * V_2 ,
struct V_3 * V_4 , int V_35 , int V_127 )
{
unsigned long V_134 ;
unsigned long V_189 ;
unsigned long V_88 ;
F_97 ( V_190 ) ;
F_97 ( V_191 ) ;
F_97 ( V_192 ) ;
struct V_48 * V_48 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
unsigned long V_193 = 0 ;
F_157 () ;
F_55 ( & V_2 -> V_153 ) ;
if ( F_2 ( V_4 ) ) {
V_134 = F_135 ( V_188 , & V_190 ,
& V_189 , V_4 -> V_44 ,
V_194 , V_2 ,
1 , V_127 ) ;
V_2 -> V_179 += V_189 ;
} else {
V_134 = F_159 ( V_188 , & V_190 ,
& V_189 , V_4 -> V_44 ,
V_194 , V_2 ,
V_4 -> V_5 , 1 , V_127 ) ;
}
V_6 -> V_173 [ V_127 ] += V_134 ;
F_158 ( V_195 , V_2 , V_189 ) ;
if ( V_127 )
F_149 ( V_2 , V_167 , - V_134 ) ;
else
F_149 ( V_2 , V_170 , - V_134 ) ;
F_149 ( V_2 , V_159 + V_127 , V_134 ) ;
F_63 ( & V_2 -> V_153 ) ;
while ( ! F_98 ( & V_190 ) ) {
F_26 () ;
V_48 = F_99 ( & V_190 ) ;
F_15 ( & V_48 -> V_8 ) ;
if ( F_57 ( ! F_75 ( V_48 , NULL ) ) ) {
F_69 ( V_48 ) ;
continue;
}
if ( F_84 ( V_48 , 0 , V_4 -> V_5 , & V_88 ) ) {
V_193 += F_124 ( V_48 ) ;
if ( ( V_88 & V_196 ) && F_116 ( V_48 ) ) {
F_109 ( & V_48 -> V_8 , & V_191 ) ;
continue;
}
}
F_137 ( V_48 ) ;
F_109 ( & V_48 -> V_8 , & V_192 ) ;
}
F_55 ( & V_2 -> V_153 ) ;
V_6 -> V_163 [ V_127 ] += V_193 ;
F_163 ( V_2 , & V_191 ,
V_148 + V_127 * V_149 ) ;
F_163 ( V_2 , & V_192 ,
V_147 + V_127 * V_149 ) ;
F_149 ( V_2 , V_159 + V_127 , - V_134 ) ;
F_63 ( & V_2 -> V_153 ) ;
}
static int F_167 ( struct V_2 * V_2 )
{
unsigned long V_79 , V_154 ;
V_79 = F_9 ( V_2 , V_170 ) ;
V_154 = F_9 ( V_2 , V_158 ) ;
if ( V_154 * V_2 -> V_197 < V_79 )
return 1 ;
return 0 ;
}
static int F_168 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
int V_198 ;
if ( ! V_199 )
return 0 ;
if ( F_2 ( V_4 ) )
V_198 = F_167 ( V_2 ) ;
else
V_198 = F_169 ( V_4 -> V_5 ) ;
return V_198 ;
}
static inline int F_168 ( struct V_2 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_170 ( struct V_2 * V_2 )
{
unsigned long V_79 , V_154 ;
V_79 = F_9 ( V_2 , V_167 ) ;
V_154 = F_9 ( V_2 , V_156 ) ;
return ( V_79 > V_154 ) ;
}
static int F_171 ( struct V_2 * V_2 , struct V_3 * V_4 )
{
int V_198 ;
if ( F_2 ( V_4 ) )
V_198 = F_170 ( V_2 ) ;
else
V_198 = F_172 ( V_4 -> V_5 ) ;
return V_198 ;
}
static int F_173 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_127 )
{
if ( V_127 )
return F_171 ( V_2 , V_4 ) ;
else
return F_168 ( V_2 , V_4 ) ;
}
static unsigned long F_174 ( enum V_7 V_8 , unsigned long V_16 ,
struct V_2 * V_2 , struct V_3 * V_4 , int V_35 )
{
int V_127 = F_147 ( V_8 ) ;
if ( F_146 ( V_8 ) ) {
if ( F_173 ( V_2 , V_4 , V_127 ) )
F_166 ( V_16 , V_2 , V_4 , V_35 , V_127 ) ;
return 0 ;
}
return F_154 ( V_16 , V_2 , V_4 , V_35 , V_127 ) ;
}
static int F_175 ( struct V_3 * V_4 )
{
if ( F_2 ( V_4 ) )
return V_200 ;
return F_176 ( V_4 -> V_5 ) ;
}
static void F_177 ( struct V_2 * V_2 , struct V_3 * V_4 ,
unsigned long * V_11 , int V_35 )
{
unsigned long V_201 , V_127 , free ;
unsigned long V_202 , V_203 ;
unsigned long V_204 , V_205 ;
struct V_1 * V_6 = F_1 ( V_2 , V_4 ) ;
T_5 V_206 [ 2 ] , V_207 ;
enum V_7 V_208 ;
int V_209 = 0 ;
bool V_210 = false ;
unsigned long V_211 [ 2 ] ;
if ( F_2 ( V_4 ) && F_141 () )
V_210 = true ;
if ( ! F_2 ( V_4 ) )
V_210 = true ;
if ( ! V_4 -> V_212 || ( V_144 <= 0 ) ) {
V_209 = 1 ;
V_206 [ 0 ] = 0 ;
V_206 [ 1 ] = 1 ;
V_207 = 1 ;
V_211 [ 0 ] = 0 ;
V_211 [ 1 ] = V_21 ;
goto V_22;
}
V_201 = F_4 ( V_2 , V_4 , V_171 ) +
F_4 ( V_2 , V_4 , V_172 ) ;
V_127 = F_4 ( V_2 , V_4 , V_168 ) +
F_4 ( V_2 , V_4 , V_169 ) ;
if ( F_2 ( V_4 ) ) {
free = F_9 ( V_2 , V_213 ) ;
if ( F_57 ( V_127 + free <= F_178 ( V_2 ) ) ) {
V_206 [ 0 ] = 1 ;
V_206 [ 1 ] = 0 ;
V_207 = 1 ;
V_211 [ 0 ] = V_21 ;
V_211 [ 1 ] = 0 ;
goto V_22;
}
}
V_202 = F_175 ( V_4 ) ;
V_203 = 200 - F_175 ( V_4 ) ;
F_55 ( & V_2 -> V_153 ) ;
if ( F_57 ( V_6 -> V_173 [ 0 ] > V_201 / 4 ) ) {
V_6 -> V_173 [ 0 ] /= 2 ;
V_6 -> V_163 [ 0 ] /= 2 ;
}
if ( F_57 ( V_6 -> V_173 [ 1 ] > V_127 / 4 ) ) {
V_6 -> V_173 [ 1 ] /= 2 ;
V_6 -> V_163 [ 1 ] /= 2 ;
}
V_204 = ( V_202 + 1 ) * ( V_6 -> V_173 [ 0 ] + 1 ) ;
V_204 /= V_6 -> V_163 [ 0 ] + 1 ;
V_205 = ( V_203 + 1 ) * ( V_6 -> V_173 [ 1 ] + 1 ) ;
V_205 /= V_6 -> V_163 [ 1 ] + 1 ;
F_63 ( & V_2 -> V_153 ) ;
V_206 [ 0 ] = V_204 ;
V_206 [ 1 ] = V_205 ;
V_207 = V_204 + V_205 + 1 ;
if ( V_210 ) {
unsigned long V_138 = V_21 ;
V_211 [ 0 ] = F_179 ( V_138 * V_204 , V_207 ) ;
V_211 [ 1 ] = F_179 ( V_138 * V_205 , V_207 ) ;
}
V_22:
F_180 (l) {
int V_127 = F_147 ( V_208 ) ;
unsigned long V_138 ;
V_138 = F_4 ( V_2 , V_4 , V_208 ) ;
if ( V_35 || V_209 ) {
V_138 >>= V_35 ;
V_138 = F_179 ( V_138 * V_206 [ V_127 ] , V_207 ) ;
}
if ( ! V_138 && V_210 )
V_138 = V_211 [ V_127 ] ;
V_11 [ V_208 ] = V_138 ;
}
}
static inline bool F_181 ( struct V_2 * V_2 ,
unsigned long V_104 ,
unsigned long V_108 ,
struct V_3 * V_4 )
{
unsigned long V_214 ;
unsigned long V_215 ;
if ( ! ( V_4 -> V_41 & V_42 ) )
return false ;
if ( V_4 -> V_112 & V_216 ) {
if ( ! V_104 && ! V_108 )
return false ;
} else {
if ( ! V_104 )
return false ;
}
V_214 = ( 2UL << V_4 -> V_44 ) ;
V_215 = F_4 ( V_2 , V_4 , V_172 ) +
F_4 ( V_2 , V_4 , V_169 ) ;
if ( V_4 -> V_104 < V_214 &&
V_215 > V_214 )
return true ;
switch ( F_182 ( V_2 , V_4 -> V_44 ) ) {
case V_217 :
case V_218 :
return false ;
default:
return true ;
}
}
static void F_183 ( int V_35 , struct V_2 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_11 [ V_165 ] ;
unsigned long V_16 ;
enum V_7 V_208 ;
unsigned long V_104 , V_108 ;
unsigned long V_219 = V_4 -> V_219 ;
V_220:
V_104 = 0 ;
V_108 = V_4 -> V_108 ;
F_177 ( V_2 , V_4 , V_11 , V_35 ) ;
while ( V_11 [ V_172 ] || V_11 [ V_168 ] ||
V_11 [ V_169 ] ) {
F_180 (l) {
if ( V_11 [ V_208 ] ) {
V_16 = F_184 (unsigned long,
nr[l], SWAP_CLUSTER_MAX) ;
V_11 [ V_208 ] -= V_16 ;
V_104 += F_174 ( V_208 , V_16 ,
V_2 , V_4 , V_35 ) ;
}
}
if ( V_104 >= V_219 && V_35 < V_46 )
break;
}
V_4 -> V_104 += V_104 ;
if ( F_168 ( V_2 , V_4 ) )
F_166 ( V_21 , V_2 , V_4 , V_35 , 0 ) ;
if ( F_181 ( V_2 , V_104 ,
V_4 -> V_108 - V_108 , V_4 ) )
goto V_220;
F_185 ( V_4 -> V_112 ) ;
}
static void F_186 ( int V_35 , struct V_221 * V_221 ,
struct V_3 * V_4 )
{
struct V_222 * V_146 ;
struct V_2 * V_2 ;
unsigned long V_223 ;
unsigned long V_224 ;
F_187 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_188 ( V_2 ) )
continue;
if ( F_2 ( V_4 ) ) {
if ( ! F_189 ( V_2 , V_225 ) )
continue;
if ( V_2 -> V_226 && V_35 != V_46 )
continue;
V_224 = 0 ;
V_223 = F_190 ( V_2 ,
V_4 -> V_44 , V_4 -> V_112 ,
& V_224 ) ;
V_4 -> V_104 += V_223 ;
V_4 -> V_108 += V_224 ;
}
F_183 ( V_35 , V_2 , V_4 ) ;
}
}
static bool F_191 ( struct V_2 * V_2 )
{
return V_2 -> V_179 < F_192 ( V_2 ) * 6 ;
}
static bool V_226 ( struct V_221 * V_221 ,
struct V_3 * V_4 )
{
struct V_222 * V_146 ;
struct V_2 * V_2 ;
F_187 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_188 ( V_2 ) )
continue;
if ( ! F_189 ( V_2 , V_225 ) )
continue;
if ( ! V_2 -> V_226 )
return false ;
}
return true ;
}
static unsigned long F_193 ( struct V_221 * V_221 ,
struct V_3 * V_4 ,
struct V_15 * V_17 )
{
int V_35 ;
unsigned long V_227 = 0 ;
struct V_228 * V_228 = V_51 -> V_228 ;
struct V_222 * V_146 ;
struct V_2 * V_2 ;
unsigned long V_229 ;
F_194 () ;
F_195 () ;
if ( F_2 ( V_4 ) )
F_82 ( V_230 ) ;
for ( V_35 = V_46 ; V_35 >= 0 ; V_35 -- ) {
V_4 -> V_108 = 0 ;
if ( ! V_35 )
F_196 ( V_4 -> V_5 ) ;
F_186 ( V_35 , V_221 , V_4 ) ;
if ( F_2 ( V_4 ) ) {
unsigned long V_19 = 0 ;
F_197 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_189 ( V_2 , V_225 ) )
continue;
V_19 += F_192 ( V_2 ) ;
}
F_17 ( V_17 , V_4 -> V_108 , V_19 ) ;
if ( V_228 ) {
V_4 -> V_104 += V_228 -> V_231 ;
V_228 -> V_231 = 0 ;
}
}
V_227 += V_4 -> V_108 ;
if ( V_4 -> V_104 >= V_4 -> V_219 )
goto V_22;
V_229 = V_4 -> V_219 + V_4 -> V_219 / 2 ;
if ( V_227 > V_229 ) {
F_198 ( V_232 ? 0 : V_227 ) ;
V_4 -> V_122 = 1 ;
}
if ( ! V_4 -> V_233 && V_4 -> V_108 &&
V_35 < V_46 - 2 ) {
struct V_2 * V_234 ;
F_199 ( V_221 , F_200 ( V_4 -> V_112 ) ,
& V_235 ,
& V_234 ) ;
F_201 ( V_234 , V_176 , V_177 / 10 ) ;
}
}
V_22:
F_202 () ;
F_203 () ;
if ( V_4 -> V_104 )
return V_4 -> V_104 ;
if ( V_236 )
return 0 ;
if ( F_2 ( V_4 ) && ! V_226 ( V_221 , V_4 ) )
return 1 ;
return 0 ;
}
unsigned long F_204 ( struct V_221 * V_221 , int V_44 ,
T_6 V_112 , T_7 * V_237 )
{
unsigned long V_104 ;
struct V_3 V_4 = {
. V_112 = V_112 ,
. V_122 = ! V_232 ,
. V_219 = V_21 ,
. V_110 = 1 ,
. V_212 = 1 ,
. V_44 = V_44 ,
. V_5 = NULL ,
. V_237 = V_237 ,
} ;
struct V_15 V_17 = {
. V_112 = V_4 . V_112 ,
} ;
F_205 ( V_44 ,
V_4 . V_122 ,
V_112 ) ;
V_104 = F_193 ( V_221 , & V_4 , & V_17 ) ;
F_206 ( V_104 ) ;
return V_104 ;
}
unsigned long F_207 ( struct V_5 * V_238 ,
T_6 V_112 , bool V_209 ,
struct V_2 * V_2 ,
unsigned long * V_108 )
{
struct V_3 V_4 = {
. V_108 = 0 ,
. V_219 = V_21 ,
. V_122 = ! V_232 ,
. V_110 = 1 ,
. V_212 = ! V_209 ,
. V_44 = 0 ,
. V_5 = V_238 ,
} ;
V_4 . V_112 = ( V_112 & V_239 ) |
( V_240 & ~ V_239 ) ;
F_208 ( 0 ,
V_4 . V_122 ,
V_4 . V_112 ) ;
F_183 ( 0 , V_2 , & V_4 ) ;
F_209 ( V_4 . V_104 ) ;
* V_108 = V_4 . V_108 ;
return V_4 . V_104 ;
}
unsigned long F_210 ( struct V_5 * V_241 ,
T_6 V_112 ,
bool V_209 )
{
struct V_221 * V_221 ;
unsigned long V_104 ;
int V_242 ;
struct V_3 V_4 = {
. V_122 = ! V_232 ,
. V_110 = 1 ,
. V_212 = ! V_209 ,
. V_219 = V_21 ,
. V_44 = 0 ,
. V_5 = V_241 ,
. V_237 = NULL ,
. V_112 = ( V_112 & V_239 ) |
( V_240 & ~ V_239 ) ,
} ;
struct V_15 V_17 = {
. V_112 = V_4 . V_112 ,
} ;
V_242 = F_211 ( V_241 ) ;
V_221 = F_212 ( V_242 ) -> V_243 ;
F_213 ( 0 ,
V_4 . V_122 ,
V_4 . V_112 ) ;
V_104 = F_193 ( V_221 , & V_4 , & V_17 ) ;
F_214 ( V_104 ) ;
return V_104 ;
}
static bool F_215 ( T_8 * V_244 , unsigned long V_245 ,
int V_246 )
{
unsigned long V_247 = 0 ;
int V_248 ;
for ( V_248 = 0 ; V_248 <= V_246 ; V_248 ++ )
V_247 += V_244 -> V_249 [ V_248 ] . V_247 ;
return V_245 >= ( V_247 >> 2 ) ;
}
static bool F_216 ( T_8 * V_244 , int V_44 , long V_250 ,
int V_246 )
{
int V_248 ;
unsigned long V_251 = 0 ;
bool V_252 = true ;
if ( V_250 )
return true ;
for ( V_248 = 0 ; V_248 <= V_246 ; V_248 ++ ) {
struct V_2 * V_2 = V_244 -> V_249 + V_248 ;
if ( ! F_188 ( V_2 ) )
continue;
if ( V_2 -> V_226 ) {
V_251 += V_2 -> V_247 ;
continue;
}
if ( ! F_217 ( V_2 , V_44 , F_178 ( V_2 ) ,
V_248 , 0 ) )
V_252 = false ;
else
V_251 += V_2 -> V_247 ;
}
if ( V_44 )
return ! F_215 ( V_244 , V_251 , V_246 ) ;
else
return ! V_252 ;
}
static unsigned long F_218 ( T_8 * V_244 , int V_44 ,
int * V_246 )
{
int V_252 ;
unsigned long V_251 ;
int V_35 ;
int V_248 ;
int V_253 = 0 ;
unsigned long V_227 ;
struct V_228 * V_228 = V_51 -> V_228 ;
unsigned long V_223 ;
unsigned long V_224 ;
struct V_3 V_4 = {
. V_112 = V_225 ,
. V_110 = 1 ,
. V_212 = 1 ,
. V_219 = V_254 ,
. V_44 = V_44 ,
. V_5 = NULL ,
} ;
struct V_15 V_17 = {
. V_112 = V_4 . V_112 ,
} ;
V_255:
V_227 = 0 ;
V_4 . V_104 = 0 ;
V_4 . V_122 = ! V_232 ;
F_82 ( V_256 ) ;
for ( V_35 = V_46 ; V_35 >= 0 ; V_35 -- ) {
unsigned long V_19 = 0 ;
int V_257 = 0 ;
if ( ! V_35 )
F_196 ( NULL ) ;
V_252 = 1 ;
V_251 = 0 ;
for ( V_248 = V_244 -> V_258 - 1 ; V_248 >= 0 ; V_248 -- ) {
struct V_2 * V_2 = V_244 -> V_249 + V_248 ;
if ( ! F_188 ( V_2 ) )
continue;
if ( V_2 -> V_226 && V_35 != V_46 )
continue;
if ( F_168 ( V_2 , & V_4 ) )
F_166 ( V_21 , V_2 ,
& V_4 , V_35 , 0 ) ;
if ( ! F_217 ( V_2 , V_44 ,
F_178 ( V_2 ) , 0 , 0 ) ) {
V_253 = V_248 ;
break;
} else {
F_219 ( V_2 , V_124 ) ;
}
}
if ( V_248 < 0 )
goto V_22;
for ( V_248 = 0 ; V_248 <= V_253 ; V_248 ++ ) {
struct V_2 * V_2 = V_244 -> V_249 + V_248 ;
V_19 += F_192 ( V_2 ) ;
}
for ( V_248 = 0 ; V_248 <= V_253 ; V_248 ++ ) {
struct V_2 * V_2 = V_244 -> V_249 + V_248 ;
int V_259 ;
unsigned long V_260 ;
if ( ! F_188 ( V_2 ) )
continue;
if ( V_2 -> V_226 && V_35 != V_46 )
continue;
V_4 . V_108 = 0 ;
V_224 = 0 ;
V_223 = F_190 ( V_2 ,
V_44 , V_4 . V_112 ,
& V_224 ) ;
V_4 . V_104 += V_223 ;
V_227 += V_224 ;
V_260 = F_23 ( F_220 ( V_2 ) ,
( V_2 -> V_247 +
V_261 - 1 ) /
V_261 ) ;
if ( ! F_217 ( V_2 , V_44 ,
F_178 ( V_2 ) + V_260 ,
V_253 , 0 ) ) {
F_183 ( V_35 , V_2 , & V_4 ) ;
V_228 -> V_231 = 0 ;
V_259 = F_17 ( & V_17 , V_4 . V_108 , V_19 ) ;
V_4 . V_104 += V_228 -> V_231 ;
V_227 += V_4 . V_108 ;
if ( V_259 == 0 && ! F_191 ( V_2 ) )
V_2 -> V_226 = 1 ;
}
if ( V_227 > V_21 * 2 &&
V_227 > V_4 . V_104 + V_4 . V_104 / 2 )
V_4 . V_122 = 1 ;
if ( V_2 -> V_226 ) {
if ( V_253 && V_253 == V_248 )
V_253 -- ;
continue;
}
if ( ! F_217 ( V_2 , V_44 ,
F_178 ( V_2 ) , V_253 , 0 ) ) {
V_252 = 0 ;
if ( ! F_217 ( V_2 , V_44 ,
F_221 ( V_2 ) , V_253 , 0 ) )
V_257 = 1 ;
} else {
F_219 ( V_2 , V_124 ) ;
if ( V_248 <= * V_246 )
V_251 += V_2 -> V_247 ;
}
}
if ( V_252 || ( V_44 && F_215 ( V_244 , V_251 , * V_246 ) ) )
break;
if ( V_227 && ( V_35 < V_46 - 2 ) ) {
if ( V_257 )
F_82 ( V_262 ) ;
else
F_155 ( V_176 , V_177 / 10 ) ;
}
if ( V_4 . V_104 >= V_21 )
break;
}
V_22:
if ( ! ( V_252 || ( V_44 && F_215 ( V_244 , V_251 , * V_246 ) ) ) ) {
F_26 () ;
F_222 () ;
if ( V_4 . V_104 < V_21 )
V_44 = V_4 . V_44 = 0 ;
goto V_255;
}
if ( V_44 ) {
for ( V_248 = 0 ; V_248 <= V_253 ; V_248 ++ ) {
struct V_2 * V_2 = V_244 -> V_249 + V_248 ;
if ( ! F_188 ( V_2 ) )
continue;
if ( V_2 -> V_226 && V_35 != V_46 )
continue;
if ( ! F_223 ( V_2 , 0 ,
F_178 ( V_2 ) , 0 , 0 ) ) {
V_44 = V_4 . V_44 = 0 ;
goto V_255;
}
F_219 ( V_2 , V_124 ) ;
}
}
* V_246 = V_253 ;
return V_44 ;
}
static void F_224 ( T_8 * V_244 , int V_44 , int V_246 )
{
long V_250 = 0 ;
F_225 ( V_263 ) ;
if ( F_226 ( V_51 ) || F_227 () )
return;
F_228 ( & V_244 -> V_264 , & V_263 , V_265 ) ;
if ( ! F_216 ( V_244 , V_44 , V_250 , V_246 ) ) {
V_250 = F_229 ( V_177 / 10 ) ;
F_230 ( & V_244 -> V_264 , & V_263 ) ;
F_228 ( & V_244 -> V_264 , & V_263 , V_265 ) ;
}
if ( ! F_216 ( V_244 , V_44 , V_250 , V_246 ) ) {
F_231 ( V_244 -> V_185 ) ;
F_232 ( V_244 , V_266 ) ;
F_233 () ;
F_232 ( V_244 , V_267 ) ;
} else {
if ( V_250 )
F_82 ( V_268 ) ;
else
F_82 ( V_269 ) ;
}
F_230 ( & V_244 -> V_264 , & V_263 ) ;
}
static int F_234 ( void * V_270 )
{
unsigned long V_44 , V_271 ;
int V_246 , V_272 ;
T_8 * V_244 = ( T_8 * ) V_270 ;
struct V_273 * V_274 = V_51 ;
struct V_228 V_228 = {
. V_231 = 0 ,
} ;
const struct V_275 * V_275 = F_235 ( V_244 -> V_185 ) ;
F_236 ( V_225 ) ;
if ( ! F_237 ( V_275 ) )
F_238 ( V_274 , V_275 ) ;
V_51 -> V_228 = & V_228 ;
V_274 -> V_52 |= V_276 | V_53 | V_277 ;
F_239 () ;
V_44 = V_271 = 0 ;
V_246 = V_272 = V_244 -> V_258 - 1 ;
for ( ; ; ) {
int V_20 ;
if ( V_246 >= V_272 && V_44 == V_271 ) {
V_271 = V_244 -> V_278 ;
V_272 = V_244 -> V_246 ;
V_244 -> V_278 = 0 ;
V_244 -> V_246 = V_244 -> V_258 - 1 ;
}
if ( V_44 < V_271 || V_246 > V_272 ) {
V_44 = V_271 ;
V_246 = V_272 ;
} else {
F_224 ( V_244 , V_44 , V_246 ) ;
V_44 = V_244 -> V_278 ;
V_246 = V_244 -> V_246 ;
V_244 -> V_278 = 0 ;
V_244 -> V_246 = V_244 -> V_258 - 1 ;
}
V_20 = F_222 () ;
if ( F_227 () )
break;
if ( ! V_20 ) {
F_240 ( V_244 -> V_185 , V_44 ) ;
V_44 = F_218 ( V_244 , V_44 , & V_246 ) ;
}
}
return 0 ;
}
void F_241 ( struct V_2 * V_2 , int V_44 , enum V_279 V_246 )
{
T_8 * V_244 ;
if ( ! F_188 ( V_2 ) )
return;
if ( ! F_189 ( V_2 , V_225 ) )
return;
V_244 = V_2 -> V_184 ;
if ( V_244 -> V_278 < V_44 ) {
V_244 -> V_278 = V_44 ;
V_244 -> V_246 = F_23 ( V_244 -> V_246 , V_246 ) ;
}
if ( ! F_242 ( & V_244 -> V_264 ) )
return;
if ( F_217 ( V_2 , V_44 , F_220 ( V_2 ) , 0 , 0 ) )
return;
F_243 ( V_244 -> V_185 , F_7 ( V_2 ) , V_44 ) ;
F_244 ( & V_244 -> V_264 ) ;
}
unsigned long F_245 ( void )
{
int V_11 ;
V_11 = F_246 ( V_167 ) +
F_246 ( V_156 ) ;
if ( V_144 > 0 )
V_11 += F_246 ( V_170 ) +
F_246 ( V_158 ) ;
return V_11 ;
}
unsigned long F_192 ( struct V_2 * V_2 )
{
int V_11 ;
V_11 = F_9 ( V_2 , V_167 ) +
F_9 ( V_2 , V_156 ) ;
if ( V_144 > 0 )
V_11 += F_9 ( V_2 , V_170 ) +
F_9 ( V_2 , V_158 ) ;
return V_11 ;
}
unsigned long F_247 ( unsigned long V_219 )
{
struct V_228 V_228 ;
struct V_3 V_4 = {
. V_112 = V_240 ,
. V_212 = 1 ,
. V_110 = 1 ,
. V_122 = 1 ,
. V_219 = V_219 ,
. V_233 = 1 ,
. V_44 = 0 ,
} ;
struct V_15 V_17 = {
. V_112 = V_4 . V_112 ,
} ;
struct V_221 * V_221 = F_248 ( F_249 () , V_4 . V_112 ) ;
struct V_273 * V_270 = V_51 ;
unsigned long V_104 ;
V_270 -> V_52 |= V_276 ;
F_236 ( V_4 . V_112 ) ;
V_228 . V_231 = 0 ;
V_270 -> V_228 = & V_228 ;
V_104 = F_193 ( V_221 , & V_4 , & V_17 ) ;
V_270 -> V_228 = NULL ;
F_250 () ;
V_270 -> V_52 &= ~ V_276 ;
return V_104 ;
}
static int T_9 F_251 ( struct V_280 * V_281 ,
unsigned long V_282 , void * V_283 )
{
int V_242 ;
if ( V_282 == V_284 || V_282 == V_285 ) {
F_252 (nid, N_HIGH_MEMORY) {
T_8 * V_244 = F_212 ( V_242 ) ;
const struct V_275 * V_286 ;
V_286 = F_235 ( V_244 -> V_185 ) ;
if ( F_253 ( V_287 , V_286 ) < V_288 )
F_238 ( V_244 -> F_234 , V_286 ) ;
}
}
return V_289 ;
}
int F_254 ( int V_242 )
{
T_8 * V_244 = F_212 ( V_242 ) ;
int V_20 = 0 ;
if ( V_244 -> F_234 )
return 0 ;
V_244 -> F_234 = F_255 ( F_234 , V_244 , L_4 , V_242 ) ;
if ( F_256 ( V_244 -> F_234 ) ) {
F_53 ( V_290 == V_291 ) ;
F_22 ( L_5 , V_242 ) ;
V_20 = - 1 ;
}
return V_20 ;
}
void F_257 ( int V_242 )
{
struct V_273 * F_234 = F_212 ( V_242 ) -> F_234 ;
if ( F_234 )
F_258 ( F_234 ) ;
}
static int T_10 F_259 ( void )
{
int V_242 ;
F_260 () ;
F_252 (nid, N_HIGH_MEMORY)
F_254 ( V_242 ) ;
F_261 ( F_251 , 0 ) ;
return 0 ;
}
static inline unsigned long F_262 ( struct V_2 * V_2 )
{
unsigned long V_292 = F_9 ( V_2 , V_293 ) ;
unsigned long V_294 = F_9 ( V_2 , V_156 ) +
F_9 ( V_2 , V_167 ) ;
return ( V_294 > V_292 ) ? ( V_294 - V_292 ) : 0 ;
}
static long F_263 ( struct V_2 * V_2 )
{
long V_295 ;
long V_23 = 0 ;
if ( V_296 & V_297 )
V_295 = F_9 ( V_2 , V_298 ) ;
else
V_295 = F_262 ( V_2 ) ;
if ( ! ( V_296 & V_299 ) )
V_23 += F_9 ( V_2 , V_300 ) ;
if ( F_57 ( V_23 > V_295 ) )
V_23 = V_295 ;
return V_295 - V_23 ;
}
static int F_264 ( struct V_2 * V_2 , T_6 V_112 , unsigned int V_44 )
{
const unsigned long V_188 = 1 << V_44 ;
struct V_273 * V_270 = V_51 ;
struct V_228 V_228 ;
int V_35 ;
struct V_3 V_4 = {
. V_122 = ! ! ( V_296 & V_299 ) ,
. V_110 = ! ! ( V_296 & V_297 ) ,
. V_212 = 1 ,
. V_219 = F_265 (unsigned long, nr_pages,
SWAP_CLUSTER_MAX) ,
. V_112 = V_112 ,
. V_44 = V_44 ,
} ;
struct V_15 V_17 = {
. V_112 = V_4 . V_112 ,
} ;
unsigned long V_301 , V_302 ;
F_26 () ;
V_270 -> V_52 |= V_276 | V_53 ;
F_236 ( V_112 ) ;
V_228 . V_231 = 0 ;
V_270 -> V_228 = & V_228 ;
if ( F_263 ( V_2 ) > V_2 -> V_303 ) {
V_35 = V_304 ;
do {
F_183 ( V_35 , V_2 , & V_4 ) ;
V_35 -- ;
} while ( V_35 >= 0 && V_4 . V_104 < V_188 );
}
V_301 = F_9 ( V_2 , V_305 ) ;
if ( V_301 > V_2 -> V_306 ) {
for (; ; ) {
unsigned long V_19 = F_192 ( V_2 ) ;
if ( ! F_17 ( & V_17 , V_4 . V_108 , V_19 ) )
break;
V_302 = F_9 ( V_2 ,
V_305 ) ;
if ( V_302 + V_188 <= V_301 )
break;
}
V_302 = F_9 ( V_2 , V_305 ) ;
if ( V_302 < V_301 )
V_4 . V_104 += V_301 - V_302 ;
}
V_270 -> V_228 = NULL ;
V_51 -> V_52 &= ~ ( V_276 | V_53 ) ;
F_250 () ;
return V_4 . V_104 >= V_188 ;
}
int F_266 ( struct V_2 * V_2 , T_6 V_112 , unsigned int V_44 )
{
int V_185 ;
int V_20 ;
if ( F_263 ( V_2 ) <= V_2 -> V_303 &&
F_9 ( V_2 , V_305 ) <= V_2 -> V_306 )
return V_307 ;
if ( V_2 -> V_226 )
return V_307 ;
if ( ! ( V_112 & V_308 ) || ( V_51 -> V_52 & V_276 ) )
return V_309 ;
V_185 = F_6 ( V_2 ) ;
if ( F_267 ( V_185 , V_310 ) && V_185 != F_249 () )
return V_309 ;
if ( F_268 ( V_2 , V_311 ) )
return V_309 ;
V_20 = F_264 ( V_2 , V_112 , V_44 ) ;
F_219 ( V_2 , V_311 ) ;
if ( ! V_20 )
F_82 ( V_312 ) ;
return V_20 ;
}
int F_75 ( struct V_48 * V_48 , struct V_313 * V_314 )
{
if ( F_269 ( F_38 ( V_48 ) ) )
return 0 ;
if ( F_270 ( V_48 ) || ( V_314 && F_271 ( V_314 , V_48 ) ) )
return 0 ;
return 1 ;
}
static void F_272 ( struct V_48 * V_48 , struct V_2 * V_2 )
{
F_72 ( F_101 ( V_48 ) ) ;
V_315:
F_74 ( V_48 ) ;
if ( F_75 ( V_48 , NULL ) ) {
enum V_7 V_208 = F_76 ( V_48 ) ;
F_273 ( V_2 , V_316 ) ;
F_122 ( & V_48 -> V_8 , & V_2 -> V_8 [ V_208 ] . V_13 ) ;
F_274 ( V_48 , V_82 , V_208 ) ;
F_275 ( V_2 , V_158 + V_208 ) ;
F_276 ( V_83 ) ;
} else {
F_277 ( V_48 ) ;
F_122 ( & V_48 -> V_8 , & V_2 -> V_8 [ V_82 ] . V_13 ) ;
F_125 ( V_48 , V_82 ) ;
if ( F_75 ( V_48 , NULL ) )
goto V_315;
}
}
void F_278 ( struct V_54 * V_55 )
{
T_11 V_317 = 0 ;
T_11 V_318 = ( F_279 ( V_55 -> V_319 ) + V_320 - 1 ) >>
V_321 ;
struct V_2 * V_2 ;
struct V_96 V_162 ;
if ( V_55 -> V_322 == 0 )
return;
F_90 ( & V_162 , 0 ) ;
while ( V_317 < V_318 &&
F_280 ( & V_162 , V_55 , V_317 , V_323 ) ) {
int V_248 ;
int V_324 = 0 ;
V_2 = NULL ;
for ( V_248 = 0 ; V_248 < F_281 ( & V_162 ) ; V_248 ++ ) {
struct V_48 * V_48 = V_162 . V_325 [ V_248 ] ;
T_11 V_326 = V_48 -> V_327 ;
struct V_2 * V_328 = F_102 ( V_48 ) ;
V_324 ++ ;
if ( V_326 > V_317 )
V_317 = V_326 ;
V_317 ++ ;
if ( V_328 != V_2 ) {
if ( V_2 )
F_63 ( & V_2 -> V_153 ) ;
V_2 = V_328 ;
F_55 ( & V_2 -> V_153 ) ;
}
if ( F_73 ( V_48 ) && F_71 ( V_48 ) )
F_272 ( V_48 , V_2 ) ;
}
if ( V_2 )
F_63 ( & V_2 -> V_153 ) ;
F_150 ( & V_162 ) ;
F_25 ( V_329 , V_324 ) ;
}
}
static void F_282 ( struct V_2 * V_2 )
{
struct V_94 * V_330 = & V_2 -> V_8 [ V_82 ] . V_13 ;
unsigned long V_138 ;
unsigned long V_16 = F_9 ( V_2 , V_316 ) ;
while ( V_16 > 0 ) {
unsigned long V_28 = F_23 ( V_16 ,
V_331 ) ;
F_55 ( & V_2 -> V_153 ) ;
for ( V_138 = 0 ; V_138 < V_28 ; V_138 ++ ) {
struct V_48 * V_48 = F_99 ( V_330 ) ;
if ( ! F_100 ( V_48 ) )
continue;
F_121 ( V_48 , V_330 , V_52 ) ;
if ( F_117 ( F_73 ( V_48 ) && F_71 ( V_48 ) ) )
F_272 ( V_48 , V_2 ) ;
F_40 ( V_48 ) ;
}
F_63 ( & V_2 -> V_153 ) ;
V_16 -= V_28 ;
}
}
static void F_283 ( void )
{
struct V_2 * V_2 ;
F_284 (zone) {
F_282 ( V_2 ) ;
}
}
int F_285 ( struct V_332 * V_333 , int V_334 ,
void T_12 * V_335 ,
T_13 * V_336 , T_14 * V_337 )
{
F_286 ( V_333 , V_334 , V_335 , V_336 , V_337 ) ;
if ( V_334 && * ( unsigned long * ) V_333 -> V_338 )
F_283 () ;
V_339 = 0 ;
return 0 ;
}
static T_15 F_287 ( struct V_340 * V_341 ,
struct V_342 * V_343 ,
char * V_344 )
{
return sprintf ( V_344 , L_6 ) ;
}
static T_15 F_288 ( struct V_340 * V_341 ,
struct V_342 * V_343 ,
const char * V_344 , T_13 V_150 )
{
struct V_2 * V_249 = F_212 ( V_341 -> V_345 ) -> V_249 ;
struct V_2 * V_2 ;
unsigned long V_62 ;
unsigned long V_346 = F_289 ( V_344 , 10 , & V_62 ) ;
if ( ! V_346 )
return 1 ;
for ( V_2 = V_249 ; V_2 - V_249 < V_347 ; ++ V_2 ) {
if ( ! F_188 ( V_2 ) )
continue;
F_282 ( V_2 ) ;
}
return 1 ;
}
int F_290 ( struct V_348 * V_348 )
{
return F_291 ( & V_348 -> V_349 , & V_350 ) ;
}
void F_292 ( struct V_348 * V_348 )
{
F_293 ( & V_348 -> V_349 , & V_350 ) ;
}
