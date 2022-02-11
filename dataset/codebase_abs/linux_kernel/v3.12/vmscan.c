static bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return true ;
}
unsigned long F_2 ( struct V_4 * V_4 )
{
int V_5 ;
V_5 = F_3 ( V_4 , V_6 ) +
F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_5 += F_3 ( V_4 , V_8 ) +
F_3 ( V_4 , V_9 ) ;
return V_5 ;
}
bool F_5 ( struct V_4 * V_4 )
{
return V_4 -> V_10 < F_2 ( V_4 ) * 6 ;
}
static unsigned long F_6 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( ! F_7 () )
return F_8 ( V_11 , V_13 ) ;
return F_3 ( F_9 ( V_11 ) , V_14 + V_13 ) ;
}
int F_10 ( struct V_15 * V_15 )
{
T_1 V_16 = sizeof( * V_15 -> V_17 ) ;
if ( V_18 == 1 )
V_15 -> V_19 &= ~ V_20 ;
if ( V_15 -> V_19 & V_20 )
V_16 *= V_18 ;
V_15 -> V_17 = F_11 ( V_16 , V_21 ) ;
if ( ! V_15 -> V_17 )
return - V_22 ;
F_12 ( & V_23 ) ;
F_13 ( & V_15 -> V_24 , & V_25 ) ;
F_14 ( & V_23 ) ;
return 0 ;
}
void F_15 ( struct V_15 * V_15 )
{
F_12 ( & V_23 ) ;
F_16 ( & V_15 -> V_24 ) ;
F_14 ( & V_23 ) ;
F_17 ( V_15 -> V_17 ) ;
}
static unsigned long
F_18 ( struct V_26 * V_27 , struct V_15 * V_15 ,
unsigned long V_28 , unsigned long V_29 )
{
unsigned long V_30 = 0 ;
unsigned long long V_31 ;
long V_32 ;
long V_33 ;
long V_5 ;
long V_34 ;
int V_35 = V_27 -> V_35 ;
long V_36 = V_15 -> V_37 ? V_15 -> V_37
: V_38 ;
V_33 = V_15 -> V_39 ( V_15 , V_27 ) ;
if ( V_33 == 0 )
return 0 ;
V_5 = F_19 ( & V_15 -> V_17 [ V_35 ] , 0 ) ;
V_32 = V_5 ;
V_31 = ( 4 * V_28 ) / V_15 -> V_40 ;
V_31 *= V_33 ;
F_20 ( V_31 , V_29 + 1 ) ;
V_32 += V_31 ;
if ( V_32 < 0 ) {
F_21 ( V_41
L_1 ,
V_15 -> V_42 , V_32 ) ;
V_32 = V_33 ;
}
if ( V_31 < V_33 / 4 )
V_32 = F_22 ( V_32 , V_33 / 2 ) ;
if ( V_32 > V_33 * 2 )
V_32 = V_33 * 2 ;
F_23 ( V_15 , V_27 , V_5 ,
V_28 , V_29 ,
V_33 , V_31 , V_32 ) ;
while ( V_32 >= V_36 ) {
unsigned long V_43 ;
V_27 -> V_44 = V_36 ;
V_43 = V_15 -> V_42 ( V_15 , V_27 ) ;
if ( V_43 == V_45 )
break;
V_30 += V_43 ;
F_24 ( V_46 , V_36 ) ;
V_32 -= V_36 ;
F_25 () ;
}
if ( V_32 > 0 )
V_34 = F_26 ( V_32 ,
& V_15 -> V_17 [ V_35 ] ) ;
else
V_34 = F_27 ( & V_15 -> V_17 [ V_35 ] ) ;
F_28 ( V_15 , V_30 , V_5 , V_34 ) ;
return V_30 ;
}
unsigned long F_29 ( struct V_26 * V_27 ,
unsigned long V_28 ,
unsigned long V_29 )
{
struct V_15 * V_15 ;
unsigned long V_30 = 0 ;
if ( V_28 == 0 )
V_28 = V_47 ;
if ( ! F_30 ( & V_23 ) ) {
V_30 = 1 ;
goto V_48;
}
F_31 (shrinker, &shrinker_list, list) {
F_32 (shrinkctl->nid, shrinkctl->nodes_to_scan) {
if ( ! F_33 ( V_27 -> V_35 ) )
continue;
if ( ! ( V_15 -> V_19 & V_20 ) &&
( V_27 -> V_35 != 0 ) )
break;
V_30 += F_18 ( V_27 , V_15 ,
V_28 , V_29 ) ;
}
}
F_34 ( & V_23 ) ;
V_48:
F_25 () ;
return V_30 ;
}
static inline int F_35 ( struct V_49 * V_49 )
{
return F_36 ( V_49 ) - F_37 ( V_49 ) == 2 ;
}
static int F_38 ( struct V_50 * V_51 ,
struct V_1 * V_2 )
{
if ( V_52 -> V_19 & V_53 )
return 1 ;
if ( ! F_39 ( V_51 ) )
return 1 ;
if ( V_51 == V_52 -> V_50 )
return 1 ;
return 0 ;
}
static void F_40 ( struct V_54 * V_55 ,
struct V_49 * V_49 , int error )
{
F_41 ( V_49 ) ;
if ( F_42 ( V_49 ) == V_55 )
F_43 ( V_55 , error ) ;
F_44 ( V_49 ) ;
}
static T_2 F_45 ( struct V_49 * V_49 , struct V_54 * V_55 ,
struct V_1 * V_2 )
{
if ( ! F_35 ( V_49 ) )
return V_56 ;
if ( ! V_55 ) {
if ( F_37 ( V_49 ) ) {
if ( F_46 ( V_49 ) ) {
F_47 ( V_49 ) ;
F_21 ( L_2 , V_57 ) ;
return V_58 ;
}
}
return V_56 ;
}
if ( V_55 -> V_59 -> V_60 == NULL )
return V_61 ;
if ( ! F_38 ( V_55 -> V_50 , V_2 ) )
return V_56 ;
if ( F_48 ( V_49 ) ) {
int V_62 ;
struct V_63 V_64 = {
. V_65 = V_66 ,
. V_67 = V_47 ,
. V_68 = 0 ,
. V_69 = V_70 ,
. V_71 = 1 ,
} ;
F_49 ( V_49 ) ;
V_62 = V_55 -> V_59 -> V_60 ( V_49 , & V_64 ) ;
if ( V_62 < 0 )
F_40 ( V_55 , V_49 , V_62 ) ;
if ( V_62 == V_72 ) {
F_50 ( V_49 ) ;
return V_61 ;
}
if ( ! F_51 ( V_49 ) ) {
F_50 ( V_49 ) ;
}
F_52 ( V_49 , F_53 ( V_49 ) ) ;
F_54 ( V_49 , V_73 ) ;
return V_74 ;
}
return V_58 ;
}
static int F_55 ( struct V_54 * V_55 , struct V_49 * V_49 )
{
F_56 ( ! F_57 ( V_49 ) ) ;
F_56 ( V_55 != F_42 ( V_49 ) ) ;
F_58 ( & V_55 -> V_75 ) ;
if ( ! F_59 ( V_49 , 2 ) )
goto V_76;
if ( F_60 ( F_61 ( V_49 ) ) ) {
F_62 ( V_49 , 2 ) ;
goto V_76;
}
if ( F_63 ( V_49 ) ) {
T_3 V_77 = { . V_78 = F_64 (page) } ;
F_65 ( V_49 ) ;
F_66 ( & V_55 -> V_75 ) ;
F_67 ( V_77 , V_49 ) ;
} else {
void (* F_68)( struct V_49 * );
F_68 = V_55 -> V_59 -> F_68 ;
F_69 ( V_49 ) ;
F_66 ( & V_55 -> V_75 ) ;
F_70 ( V_49 ) ;
if ( F_68 != NULL )
F_68 ( V_49 ) ;
}
return 1 ;
V_76:
F_66 ( & V_55 -> V_75 ) ;
return 0 ;
}
int F_71 ( struct V_54 * V_55 , struct V_49 * V_49 )
{
if ( F_55 ( V_55 , V_49 ) ) {
F_62 ( V_49 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_72 ( struct V_49 * V_49 )
{
bool V_79 ;
int V_80 = F_73 ( V_49 ) ;
F_74 ( F_75 ( V_49 ) ) ;
V_81:
F_76 ( V_49 ) ;
if ( F_77 ( V_49 ) ) {
V_79 = false ;
F_78 ( V_49 ) ;
} else {
V_79 = true ;
F_79 ( V_49 ) ;
F_80 () ;
}
if ( V_79 && F_77 ( V_49 ) ) {
if ( ! F_81 ( V_49 ) ) {
F_82 ( V_49 ) ;
goto V_81;
}
}
if ( V_80 && ! V_79 )
F_83 ( V_82 ) ;
else if ( ! V_80 && V_79 )
F_83 ( V_83 ) ;
F_82 ( V_49 ) ;
}
static enum V_84 F_84 ( struct V_49 * V_49 ,
struct V_1 * V_2 )
{
int V_85 , V_86 ;
unsigned long V_87 ;
V_85 = F_85 ( V_49 , 1 , V_2 -> V_3 ,
& V_87 ) ;
V_86 = F_86 ( V_49 ) ;
if ( V_87 & V_88 )
return V_89 ;
if ( V_85 ) {
if ( F_87 ( V_49 ) )
return V_90 ;
F_88 ( V_49 ) ;
if ( V_86 || V_85 > 1 )
return V_90 ;
if ( V_87 & V_91 )
return V_90 ;
return V_92 ;
}
if ( V_86 && ! F_87 ( V_49 ) )
return V_93 ;
return V_89 ;
}
static void F_89 ( struct V_49 * V_49 ,
bool * V_94 , bool * V_95 )
{
struct V_54 * V_55 ;
if ( ! F_90 ( V_49 ) ) {
* V_94 = false ;
* V_95 = false ;
return;
}
* V_94 = F_61 ( V_49 ) ;
* V_95 = F_51 ( V_49 ) ;
if ( ! F_37 ( V_49 ) )
return;
V_55 = F_42 ( V_49 ) ;
if ( V_55 && V_55 -> V_59 -> V_96 )
V_55 -> V_59 -> V_96 ( V_49 , V_94 , V_95 ) ;
}
static unsigned long F_91 ( struct V_97 * V_98 ,
struct V_4 * V_4 ,
struct V_1 * V_2 ,
enum V_99 V_99 ,
unsigned long * V_100 ,
unsigned long * V_101 ,
unsigned long * V_102 ,
unsigned long * V_103 ,
unsigned long * V_104 ,
bool V_105 )
{
F_92 ( V_106 ) ;
F_92 ( V_107 ) ;
int V_108 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_110 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_114 = 0 ;
F_25 () ;
F_93 () ;
while ( ! F_94 ( V_98 ) ) {
struct V_54 * V_55 ;
struct V_49 * V_49 ;
int V_115 ;
enum V_84 V_116 = V_93 ;
bool V_94 , V_95 ;
F_25 () ;
V_49 = F_95 ( V_98 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( ! F_96 ( V_49 ) )
goto V_117;
F_74 ( F_97 ( V_49 ) ) ;
F_74 ( F_98 ( V_49 ) != V_4 ) ;
V_2 -> V_118 ++ ;
if ( F_60 ( ! F_77 ( V_49 ) ) )
goto V_119;
if ( ! V_2 -> V_120 && F_99 ( V_49 ) )
goto V_121;
if ( F_99 ( V_49 ) || F_63 ( V_49 ) )
V_2 -> V_118 ++ ;
V_115 = ( V_2 -> V_122 & V_123 ) ||
( F_63 ( V_49 ) && ( V_2 -> V_122 & V_124 ) ) ;
F_89 ( V_49 , & V_94 , & V_95 ) ;
if ( V_94 || V_95 )
V_110 ++ ;
if ( V_94 && ! V_95 )
V_109 ++ ;
V_55 = F_42 ( V_49 ) ;
if ( ( V_55 && F_39 ( V_55 -> V_50 ) ) ||
( V_95 && F_100 ( V_49 ) ) )
V_111 ++ ;
if ( F_51 ( V_49 ) ) {
if ( F_101 () &&
F_100 ( V_49 ) &&
F_102 ( V_4 ) ) {
V_114 ++ ;
goto V_121;
} else if ( F_1 ( V_2 ) ||
! F_100 ( V_49 ) || ! ( V_2 -> V_122 & V_124 ) ) {
F_49 ( V_49 ) ;
V_113 ++ ;
goto V_121;
} else {
F_103 ( V_49 ) ;
}
}
if ( ! V_105 )
V_116 = F_84 ( V_49 , V_2 ) ;
switch ( V_116 ) {
case V_90 :
goto V_125;
case V_92 :
goto V_121;
case V_89 :
case V_93 :
;
}
if ( F_104 ( V_49 ) && ! F_63 ( V_49 ) ) {
if ( ! ( V_2 -> V_122 & V_124 ) )
goto V_121;
if ( ! F_105 ( V_49 , V_98 ) )
goto V_125;
V_115 = 1 ;
V_55 = F_42 ( V_49 ) ;
}
if ( F_99 ( V_49 ) && V_55 ) {
switch ( F_106 ( V_49 , V_99 ) ) {
case V_126 :
goto V_125;
case V_127 :
goto V_121;
case V_128 :
goto V_119;
case V_129 :
;
}
}
if ( F_61 ( V_49 ) ) {
if ( F_90 ( V_49 ) &&
( ! F_101 () ||
! F_107 ( V_4 ) ) ) {
F_54 ( V_49 , V_130 ) ;
F_49 ( V_49 ) ;
goto V_121;
}
if ( V_116 == V_93 )
goto V_121;
if ( ! V_115 )
goto V_121;
if ( ! V_2 -> V_131 )
goto V_121;
switch ( F_45 ( V_49 , V_55 , V_2 ) ) {
case V_56 :
goto V_121;
case V_61 :
goto V_125;
case V_74 :
if ( F_51 ( V_49 ) )
goto V_117;
if ( F_61 ( V_49 ) )
goto V_117;
if ( ! F_96 ( V_49 ) )
goto V_117;
if ( F_61 ( V_49 ) || F_51 ( V_49 ) )
goto V_121;
V_55 = F_42 ( V_49 ) ;
case V_58 :
;
}
}
if ( F_37 ( V_49 ) ) {
if ( ! F_108 ( V_49 , V_2 -> V_122 ) )
goto V_125;
if ( ! V_55 && F_36 ( V_49 ) == 1 ) {
F_44 ( V_49 ) ;
if ( F_109 ( V_49 ) )
goto V_132;
else {
V_112 ++ ;
continue;
}
}
}
if ( ! V_55 || ! F_55 ( V_55 , V_49 ) )
goto V_121;
F_110 ( V_49 ) ;
V_132:
V_112 ++ ;
F_111 ( & V_49 -> V_13 , & V_107 ) ;
continue;
V_119:
if ( F_63 ( V_49 ) )
F_112 ( V_49 ) ;
F_44 ( V_49 ) ;
F_72 ( V_49 ) ;
continue;
V_125:
if ( F_63 ( V_49 ) && F_113 () )
F_112 ( V_49 ) ;
F_74 ( F_97 ( V_49 ) ) ;
F_114 ( V_49 ) ;
V_108 ++ ;
V_121:
F_44 ( V_49 ) ;
V_117:
F_111 ( & V_49 -> V_13 , & V_106 ) ;
F_74 ( F_75 ( V_49 ) || F_73 ( V_49 ) ) ;
}
F_115 ( & V_107 , 1 ) ;
F_116 ( & V_106 , V_98 ) ;
F_24 ( V_133 , V_108 ) ;
F_117 () ;
* V_100 += V_110 ;
* V_102 += V_111 ;
* V_101 += V_109 ;
* V_103 += V_113 ;
* V_104 += V_114 ;
return V_112 ;
}
unsigned long F_118 ( struct V_4 * V_4 ,
struct V_97 * V_98 )
{
struct V_1 V_2 = {
. V_122 = V_21 ,
. V_134 = V_135 ,
. V_120 = 1 ,
} ;
unsigned long V_43 , V_136 , V_137 , V_138 , V_139 , V_140 ;
struct V_49 * V_49 , * V_141 ;
F_92 ( V_142 ) ;
F_119 (page, next, page_list, lru) {
if ( F_90 ( V_49 ) && ! F_61 ( V_49 ) &&
! F_120 ( V_49 ) ) {
F_121 ( V_49 ) ;
F_122 ( & V_49 -> V_13 , & V_142 ) ;
}
}
V_43 = F_91 ( & V_142 , V_4 , & V_2 ,
V_143 | V_144 ,
& V_136 , & V_137 , & V_138 , & V_139 , & V_140 , true ) ;
F_116 ( & V_142 , V_98 ) ;
F_123 ( V_4 , V_145 , - V_43 ) ;
return V_43 ;
}
int F_124 ( struct V_49 * V_49 , T_4 V_146 )
{
int V_43 = - V_147 ;
if ( ! F_75 ( V_49 ) )
return V_43 ;
if ( F_73 ( V_49 ) && ! ( V_146 & V_148 ) )
return V_43 ;
V_43 = - V_149 ;
if ( V_146 & ( V_150 | V_151 ) ) {
if ( F_51 ( V_49 ) )
return V_43 ;
if ( F_61 ( V_49 ) ) {
struct V_54 * V_55 ;
if ( V_146 & V_150 )
return V_43 ;
V_55 = F_42 ( V_49 ) ;
if ( V_55 && ! V_55 -> V_59 -> V_152 )
return V_43 ;
}
}
if ( ( V_146 & V_153 ) && F_99 ( V_49 ) )
return V_43 ;
if ( F_125 ( F_126 ( V_49 ) ) ) {
F_127 ( V_49 ) ;
V_43 = 0 ;
}
return V_43 ;
}
static unsigned long F_128 ( unsigned long V_44 ,
struct V_11 * V_11 , struct V_97 * V_154 ,
unsigned long * V_118 , struct V_1 * V_2 ,
T_4 V_146 , enum V_12 V_13 )
{
struct V_97 * V_155 = & V_11 -> V_156 [ V_13 ] ;
unsigned long V_157 = 0 ;
unsigned long V_158 ;
for ( V_158 = 0 ; V_158 < V_44 && ! F_94 ( V_155 ) ; V_158 ++ ) {
struct V_49 * V_49 ;
int V_159 ;
V_49 = F_95 ( V_155 ) ;
F_129 ( V_49 , V_155 , V_19 ) ;
F_74 ( ! F_75 ( V_49 ) ) ;
switch ( F_124 ( V_49 , V_146 ) ) {
case 0 :
V_159 = F_130 ( V_49 ) ;
F_131 ( V_11 , V_13 , - V_159 ) ;
F_122 ( & V_49 -> V_13 , V_154 ) ;
V_157 += V_159 ;
break;
case - V_149 :
F_122 ( & V_49 -> V_13 , V_155 ) ;
continue;
default:
F_132 () ;
}
}
* V_118 = V_158 ;
F_133 ( V_2 -> V_160 , V_44 , V_158 ,
V_157 , V_146 , F_134 ( V_13 ) ) ;
return V_157 ;
}
int F_81 ( struct V_49 * V_49 )
{
int V_43 = - V_149 ;
F_74 ( ! F_36 ( V_49 ) ) ;
if ( F_75 ( V_49 ) ) {
struct V_4 * V_4 = F_98 ( V_49 ) ;
struct V_11 * V_11 ;
F_58 ( & V_4 -> V_161 ) ;
V_11 = F_135 ( V_49 , V_4 ) ;
if ( F_75 ( V_49 ) ) {
int V_13 = F_136 ( V_49 ) ;
F_137 ( V_49 ) ;
F_127 ( V_49 ) ;
F_138 ( V_49 , V_11 , V_13 ) ;
V_43 = 0 ;
}
F_66 ( & V_4 -> V_161 ) ;
}
return V_43 ;
}
static int F_139 ( struct V_4 * V_4 , int V_162 ,
struct V_1 * V_2 )
{
unsigned long V_163 , V_164 ;
if ( F_101 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_162 ) {
V_163 = F_3 ( V_4 , V_7 ) ;
V_164 = F_3 ( V_4 , V_145 ) ;
} else {
V_163 = F_3 ( V_4 , V_9 ) ;
V_164 = F_3 ( V_4 , V_165 ) ;
}
if ( ( V_2 -> V_122 & V_166 ) == V_166 )
V_163 >>= 3 ;
return V_164 > V_163 ;
}
static T_5 void
F_140 ( struct V_11 * V_11 , struct V_97 * V_98 )
{
struct V_167 * V_168 = & V_11 -> V_168 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_92 ( V_169 ) ;
while ( ! F_94 ( V_98 ) ) {
struct V_49 * V_49 = F_95 ( V_98 ) ;
int V_13 ;
F_74 ( F_75 ( V_49 ) ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_60 ( ! F_77 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_161 ) ;
F_72 ( V_49 ) ;
F_58 ( & V_4 -> V_161 ) ;
continue;
}
V_11 = F_135 ( V_49 , V_4 ) ;
F_141 ( V_49 ) ;
V_13 = F_136 ( V_49 ) ;
F_142 ( V_49 , V_11 , V_13 ) ;
if ( F_143 ( V_13 ) ) {
int V_162 = F_134 ( V_13 ) ;
int V_170 = F_130 ( V_49 ) ;
V_168 -> V_171 [ V_162 ] += V_170 ;
}
if ( F_109 ( V_49 ) ) {
F_144 ( V_49 ) ;
F_145 ( V_49 ) ;
F_138 ( V_49 , V_11 , V_13 ) ;
if ( F_60 ( F_146 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_161 ) ;
( * F_147 ( V_49 ) ) ( V_49 ) ;
F_58 ( & V_4 -> V_161 ) ;
} else
F_111 ( & V_49 -> V_13 , & V_169 ) ;
}
}
F_116 ( & V_169 , V_98 ) ;
}
static T_5 unsigned long
F_148 ( unsigned long V_44 , struct V_11 * V_11 ,
struct V_1 * V_2 , enum V_12 V_13 )
{
F_92 ( V_98 ) ;
unsigned long V_118 ;
unsigned long V_112 = 0 ;
unsigned long V_157 ;
unsigned long V_110 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_114 = 0 ;
T_4 V_172 = 0 ;
int V_162 = F_134 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
struct V_167 * V_168 = & V_11 -> V_168 ;
while ( F_60 ( F_139 ( V_4 , V_162 , V_2 ) ) ) {
F_149 ( V_173 , V_174 / 10 ) ;
if ( F_150 ( V_52 ) )
return V_47 ;
}
F_151 () ;
if ( ! V_2 -> V_120 )
V_172 |= V_153 ;
if ( ! V_2 -> V_131 )
V_172 |= V_150 ;
F_58 ( & V_4 -> V_161 ) ;
V_157 = F_128 ( V_44 , V_11 , & V_98 ,
& V_118 , V_2 , V_172 , V_13 ) ;
F_123 ( V_4 , V_14 + V_13 , - V_157 ) ;
F_123 ( V_4 , V_165 + V_162 , V_157 ) ;
if ( F_1 ( V_2 ) ) {
V_4 -> V_10 += V_118 ;
if ( F_101 () )
F_152 ( V_175 , V_4 , V_118 ) ;
else
F_152 ( V_176 , V_4 , V_118 ) ;
}
F_66 ( & V_4 -> V_161 ) ;
if ( V_157 == 0 )
return 0 ;
V_112 = F_91 ( & V_98 , V_4 , V_2 , V_143 ,
& V_110 , & V_109 , & V_111 ,
& V_113 , & V_114 ,
false ) ;
F_58 ( & V_4 -> V_161 ) ;
V_168 -> V_177 [ V_162 ] += V_157 ;
if ( F_1 ( V_2 ) ) {
if ( F_101 () )
F_152 ( V_178 , V_4 ,
V_112 ) ;
else
F_152 ( V_179 , V_4 ,
V_112 ) ;
}
F_140 ( V_11 , & V_98 ) ;
F_123 ( V_4 , V_165 + V_162 , - V_157 ) ;
F_66 ( & V_4 -> V_161 ) ;
F_115 ( & V_98 , 1 ) ;
if ( V_113 && V_113 == V_157 )
F_153 ( V_4 , V_180 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_110 && V_110 == V_111 )
F_153 ( V_4 , V_181 ) ;
if ( V_109 == V_157 )
F_153 ( V_4 , V_182 ) ;
if ( V_109 == V_157 || V_114 )
F_149 ( V_173 , V_174 / 10 ) ;
}
if ( ! V_2 -> V_183 && ! F_101 () )
F_154 ( V_4 , V_173 , V_174 / 10 ) ;
F_155 ( V_4 -> V_184 -> V_185 ,
F_156 ( V_4 ) ,
V_118 , V_112 ,
V_2 -> V_134 ,
F_157 ( V_162 ) ) ;
return V_112 ;
}
static void F_158 ( struct V_11 * V_11 ,
struct V_97 * V_24 ,
struct V_97 * V_169 ,
enum V_12 V_13 )
{
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_186 = 0 ;
struct V_49 * V_49 ;
int V_159 ;
while ( ! F_94 ( V_24 ) ) {
V_49 = F_95 ( V_24 ) ;
V_11 = F_135 ( V_49 , V_4 ) ;
F_74 ( F_75 ( V_49 ) ) ;
F_141 ( V_49 ) ;
V_159 = F_130 ( V_49 ) ;
F_131 ( V_11 , V_13 , V_159 ) ;
F_122 ( & V_49 -> V_13 , & V_11 -> V_156 [ V_13 ] ) ;
V_186 += V_159 ;
if ( F_109 ( V_49 ) ) {
F_144 ( V_49 ) ;
F_145 ( V_49 ) ;
F_138 ( V_49 , V_11 , V_13 ) ;
if ( F_60 ( F_146 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_161 ) ;
( * F_147 ( V_49 ) ) ( V_49 ) ;
F_58 ( & V_4 -> V_161 ) ;
} else
F_111 ( & V_49 -> V_13 , V_169 ) ;
}
}
F_123 ( V_4 , V_14 + V_13 , V_186 ) ;
if ( ! F_143 ( V_13 ) )
F_159 ( V_187 , V_186 ) ;
}
static void F_160 ( unsigned long V_44 ,
struct V_11 * V_11 ,
struct V_1 * V_2 ,
enum V_12 V_13 )
{
unsigned long V_157 ;
unsigned long V_118 ;
unsigned long V_87 ;
F_92 ( V_188 ) ;
F_92 ( V_189 ) ;
F_92 ( V_190 ) ;
struct V_49 * V_49 ;
struct V_167 * V_168 = & V_11 -> V_168 ;
unsigned long V_191 = 0 ;
T_4 V_172 = 0 ;
int V_162 = F_134 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_151 () ;
if ( ! V_2 -> V_120 )
V_172 |= V_153 ;
if ( ! V_2 -> V_131 )
V_172 |= V_150 ;
F_58 ( & V_4 -> V_161 ) ;
V_157 = F_128 ( V_44 , V_11 , & V_188 ,
& V_118 , V_2 , V_172 , V_13 ) ;
if ( F_1 ( V_2 ) )
V_4 -> V_10 += V_118 ;
V_168 -> V_177 [ V_162 ] += V_157 ;
F_152 ( V_192 , V_4 , V_118 ) ;
F_123 ( V_4 , V_14 + V_13 , - V_157 ) ;
F_123 ( V_4 , V_165 + V_162 , V_157 ) ;
F_66 ( & V_4 -> V_161 ) ;
while ( ! F_94 ( & V_188 ) ) {
F_25 () ;
V_49 = F_95 ( & V_188 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_60 ( ! F_77 ( V_49 ) ) ) {
F_72 ( V_49 ) ;
continue;
}
if ( F_60 ( V_193 ) ) {
if ( F_37 ( V_49 ) && F_96 ( V_49 ) ) {
if ( F_37 ( V_49 ) )
F_108 ( V_49 , 0 ) ;
F_44 ( V_49 ) ;
}
}
if ( F_85 ( V_49 , 0 , V_2 -> V_3 ,
& V_87 ) ) {
V_191 += F_130 ( V_49 ) ;
if ( ( V_87 & V_91 ) && F_90 ( V_49 ) ) {
F_111 ( & V_49 -> V_13 , & V_189 ) ;
continue;
}
}
F_121 ( V_49 ) ;
F_111 ( & V_49 -> V_13 , & V_190 ) ;
}
F_58 ( & V_4 -> V_161 ) ;
V_168 -> V_171 [ V_162 ] += V_191 ;
F_158 ( V_11 , & V_189 , & V_188 , V_13 ) ;
F_158 ( V_11 , & V_190 , & V_188 , V_13 - V_194 ) ;
F_123 ( V_4 , V_165 + V_162 , - V_157 ) ;
F_66 ( & V_4 -> V_161 ) ;
F_115 ( & V_188 , 1 ) ;
}
static int F_161 ( struct V_4 * V_4 )
{
unsigned long V_195 , V_163 ;
V_195 = F_3 ( V_4 , V_8 ) ;
V_163 = F_3 ( V_4 , V_9 ) ;
if ( V_163 * V_4 -> V_196 < V_195 )
return 1 ;
return 0 ;
}
static int F_162 ( struct V_11 * V_11 )
{
if ( ! V_197 )
return 0 ;
if ( ! F_7 () )
return F_163 ( V_11 ) ;
return F_161 ( F_9 ( V_11 ) ) ;
}
static inline int F_162 ( struct V_11 * V_11 )
{
return 0 ;
}
static int F_164 ( struct V_11 * V_11 )
{
unsigned long V_163 ;
unsigned long V_195 ;
V_163 = F_6 ( V_11 , V_198 ) ;
V_195 = F_6 ( V_11 , V_199 ) ;
return V_195 > V_163 ;
}
static int F_165 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( F_134 ( V_13 ) )
return F_164 ( V_11 ) ;
else
return F_162 ( V_11 ) ;
}
static unsigned long F_166 ( enum V_12 V_13 , unsigned long V_44 ,
struct V_11 * V_11 , struct V_1 * V_2 )
{
if ( F_143 ( V_13 ) ) {
if ( F_165 ( V_11 , V_13 ) )
F_160 ( V_44 , V_11 , V_2 , V_13 ) ;
return 0 ;
}
return F_148 ( V_44 , V_11 , V_2 , V_13 ) ;
}
static int F_167 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_200 ;
return F_168 ( V_2 -> V_3 ) ;
}
static void F_169 ( struct V_11 * V_11 , struct V_1 * V_2 ,
unsigned long * V_5 )
{
struct V_167 * V_168 = & V_11 -> V_168 ;
T_6 V_201 [ 2 ] ;
T_6 V_202 = 0 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_203 , V_204 ;
enum V_205 V_205 ;
unsigned long V_206 , V_162 , free ;
bool V_207 = false ;
unsigned long V_208 , V_209 ;
enum V_12 V_13 ;
if ( F_101 () && ! F_5 ( V_4 ) )
V_207 = true ;
if ( ! F_1 ( V_2 ) )
V_207 = true ;
if ( ! V_2 -> V_210 || ( F_4 () <= 0 ) ) {
V_205 = V_211 ;
goto V_48;
}
if ( ! F_1 ( V_2 ) && ! F_167 ( V_2 ) ) {
V_205 = V_211 ;
goto V_48;
}
if ( ! V_2 -> V_134 && F_167 ( V_2 ) ) {
V_205 = V_212 ;
goto V_48;
}
V_206 = F_6 ( V_11 , V_213 ) +
F_6 ( V_11 , V_214 ) ;
V_162 = F_6 ( V_11 , V_199 ) +
F_6 ( V_11 , V_198 ) ;
if ( F_1 ( V_2 ) ) {
free = F_3 ( V_4 , V_215 ) ;
if ( F_60 ( V_162 + free <= F_170 ( V_4 ) ) ) {
V_205 = V_216 ;
goto V_48;
}
}
if ( ! F_164 ( V_11 ) ) {
V_205 = V_211 ;
goto V_48;
}
V_205 = V_217 ;
V_203 = F_167 ( V_2 ) ;
V_204 = 200 - V_203 ;
F_58 ( & V_4 -> V_161 ) ;
if ( F_60 ( V_168 -> V_177 [ 0 ] > V_206 / 4 ) ) {
V_168 -> V_177 [ 0 ] /= 2 ;
V_168 -> V_171 [ 0 ] /= 2 ;
}
if ( F_60 ( V_168 -> V_177 [ 1 ] > V_162 / 4 ) ) {
V_168 -> V_177 [ 1 ] /= 2 ;
V_168 -> V_171 [ 1 ] /= 2 ;
}
V_208 = V_203 * ( V_168 -> V_177 [ 0 ] + 1 ) ;
V_208 /= V_168 -> V_171 [ 0 ] + 1 ;
V_209 = V_204 * ( V_168 -> V_177 [ 1 ] + 1 ) ;
V_209 /= V_168 -> V_171 [ 1 ] + 1 ;
F_66 ( & V_4 -> V_161 ) ;
V_201 [ 0 ] = V_208 ;
V_201 [ 1 ] = V_209 ;
V_202 = V_208 + V_209 + 1 ;
V_48:
F_171 (lru) {
int V_162 = F_134 ( V_13 ) ;
unsigned long V_16 ;
unsigned long V_158 ;
V_16 = F_6 ( V_11 , V_13 ) ;
V_158 = V_16 >> V_2 -> V_134 ;
if ( ! V_158 && V_207 )
V_158 = F_22 ( V_16 , V_47 ) ;
switch ( V_205 ) {
case V_212 :
break;
case V_217 :
V_158 = F_172 ( V_158 * V_201 [ V_162 ] , V_202 ) ;
break;
case V_211 :
case V_216 :
if ( ( V_205 == V_211 ) != V_162 )
V_158 = 0 ;
break;
default:
F_132 () ;
}
V_5 [ V_13 ] = V_158 ;
}
}
static void F_173 ( struct V_11 * V_11 , struct V_1 * V_2 )
{
unsigned long V_5 [ V_218 ] ;
unsigned long V_219 [ V_218 ] ;
unsigned long V_44 ;
enum V_12 V_13 ;
unsigned long V_112 = 0 ;
unsigned long V_220 = V_2 -> V_220 ;
struct V_221 V_222 ;
bool V_223 = false ;
F_169 ( V_11 , V_2 , V_5 ) ;
memcpy ( V_219 , V_5 , sizeof( V_5 ) ) ;
F_174 ( & V_222 ) ;
while ( V_5 [ V_214 ] || V_5 [ V_199 ] ||
V_5 [ V_198 ] ) {
unsigned long V_224 , V_225 , V_226 ;
unsigned long V_118 ;
F_171 (lru) {
if ( V_5 [ V_13 ] ) {
V_44 = F_22 ( V_5 [ V_13 ] , V_47 ) ;
V_5 [ V_13 ] -= V_44 ;
V_112 += F_166 ( V_13 , V_44 ,
V_11 , V_2 ) ;
}
}
if ( V_112 < V_220 || V_223 )
continue;
if ( F_1 ( V_2 ) && ! F_101 () )
break;
V_225 = V_5 [ V_198 ] + V_5 [ V_199 ] ;
V_224 = V_5 [ V_214 ] + V_5 [ V_213 ] ;
if ( V_225 > V_224 ) {
unsigned long V_227 = V_219 [ V_214 ] +
V_219 [ V_213 ] + 1 ;
V_13 = V_228 ;
V_226 = V_224 * 100 / V_227 ;
} else {
unsigned long V_227 = V_219 [ V_198 ] +
V_219 [ V_199 ] + 1 ;
V_13 = V_229 ;
V_226 = V_225 * 100 / V_227 ;
}
V_5 [ V_13 ] = 0 ;
V_5 [ V_13 + V_194 ] = 0 ;
V_13 = ( V_13 == V_229 ) ? V_228 : V_229 ;
V_118 = V_219 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_219 [ V_13 ] * ( 100 - V_226 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_118 ) ;
V_13 += V_194 ;
V_118 = V_219 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_219 [ V_13 ] * ( 100 - V_226 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_118 ) ;
V_223 = true ;
}
F_175 ( & V_222 ) ;
V_2 -> V_112 += V_112 ;
if ( F_162 ( V_11 ) )
F_160 ( V_47 , V_11 ,
V_2 , V_213 ) ;
F_176 ( V_2 -> V_122 ) ;
}
static bool F_177 ( struct V_1 * V_2 )
{
if ( F_178 ( V_230 ) && V_2 -> V_160 &&
( V_2 -> V_160 > V_231 ||
V_2 -> V_134 < V_135 - 2 ) )
return true ;
return false ;
}
static inline bool F_179 ( struct V_4 * V_4 ,
unsigned long V_112 ,
unsigned long V_118 ,
struct V_1 * V_2 )
{
unsigned long V_232 ;
unsigned long V_233 ;
if ( ! F_177 ( V_2 ) )
return false ;
if ( V_2 -> V_122 & V_234 ) {
if ( ! V_112 && ! V_118 )
return false ;
} else {
if ( ! V_112 )
return false ;
}
V_232 = ( 2UL << V_2 -> V_160 ) ;
V_233 = F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_233 += F_3 ( V_4 , V_9 ) ;
if ( V_2 -> V_112 < V_232 &&
V_233 > V_232 )
return true ;
switch ( F_180 ( V_4 , V_2 -> V_160 ) ) {
case V_235 :
case V_236 :
return false ;
default:
return true ;
}
}
static void F_181 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_112 , V_118 ;
do {
struct V_237 * V_238 = V_2 -> V_3 ;
struct V_239 V_240 = {
. V_4 = V_4 ,
. V_134 = V_2 -> V_134 ,
} ;
struct V_237 * V_241 ;
V_112 = V_2 -> V_112 ;
V_118 = V_2 -> V_118 ;
V_241 = F_182 ( V_238 , NULL , & V_240 ) ;
do {
struct V_11 * V_11 ;
V_11 = F_183 ( V_4 , V_241 ) ;
F_173 ( V_11 , V_2 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_112 >= V_2 -> V_220 ) {
F_184 ( V_238 , V_241 ) ;
break;
}
V_241 = F_182 ( V_238 , V_241 , & V_240 ) ;
} while ( V_241 );
F_185 ( V_2 -> V_122 , V_2 -> V_3 ,
V_2 -> V_118 - V_118 ,
V_2 -> V_112 - V_112 ) ;
} while ( F_179 ( V_4 , V_2 -> V_112 - V_112 ,
V_2 -> V_118 - V_118 , V_2 ) );
}
static inline bool F_186 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_242 , V_243 ;
bool V_244 ;
if ( V_2 -> V_160 <= V_231 )
return false ;
V_242 = F_22 ( F_187 ( V_4 ) ,
( V_4 -> V_245 + V_246 - 1 ) /
V_246 ) ;
V_243 = F_170 ( V_4 ) + V_242 + ( 2UL << V_2 -> V_160 ) ;
V_244 = F_188 ( V_4 , 0 , V_243 , 0 , 0 ) ;
if ( F_189 ( V_4 , V_2 -> V_160 ) )
return V_244 ;
if ( ! F_180 ( V_4 , V_2 -> V_160 ) )
return false ;
return V_244 ;
}
static bool F_190 ( struct V_247 * V_247 , struct V_1 * V_2 )
{
struct V_248 * V_249 ;
struct V_4 * V_4 ;
unsigned long V_250 ;
unsigned long V_251 ;
bool V_252 = false ;
if ( V_193 )
V_2 -> V_122 |= V_253 ;
F_191 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_192 ( V_4 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_193 ( V_4 , V_21 ) )
continue;
if ( V_2 -> V_134 != V_135 &&
! F_5 ( V_4 ) )
continue;
if ( F_178 ( V_230 ) ) {
if ( F_186 ( V_4 , V_2 ) ) {
V_252 = true ;
continue;
}
}
V_251 = 0 ;
V_250 = F_194 ( V_4 ,
V_2 -> V_160 , V_2 -> V_122 ,
& V_251 ) ;
V_2 -> V_112 += V_250 ;
V_2 -> V_118 += V_251 ;
}
F_181 ( V_4 , V_2 ) ;
}
return V_252 ;
}
static bool F_195 ( struct V_247 * V_247 ,
struct V_1 * V_2 )
{
struct V_248 * V_249 ;
struct V_4 * V_4 ;
F_191 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_192 ( V_4 ) )
continue;
if ( ! F_193 ( V_4 , V_21 ) )
continue;
if ( F_5 ( V_4 ) )
return false ;
}
return true ;
}
static unsigned long F_196 ( struct V_247 * V_247 ,
struct V_1 * V_2 ,
struct V_26 * V_254 )
{
unsigned long V_255 = 0 ;
struct V_256 * V_256 = V_52 -> V_256 ;
struct V_248 * V_249 ;
struct V_4 * V_4 ;
unsigned long V_257 ;
bool V_252 ;
F_197 () ;
if ( F_1 ( V_2 ) )
F_83 ( V_258 ) ;
do {
F_198 ( V_2 -> V_122 , V_2 -> V_3 ,
V_2 -> V_134 ) ;
V_2 -> V_118 = 0 ;
V_252 = F_190 ( V_247 , V_2 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long V_29 = 0 ;
F_199 ( V_254 -> V_259 ) ;
F_200 (zone, z, zonelist,
gfp_zone(sc->gfp_mask)) {
if ( ! F_193 ( V_4 , V_21 ) )
continue;
V_29 += F_2 ( V_4 ) ;
F_201 ( F_202 ( V_4 ) ,
V_254 -> V_259 ) ;
}
F_29 ( V_254 , V_2 -> V_118 , V_29 ) ;
if ( V_256 ) {
V_2 -> V_112 += V_256 -> V_260 ;
V_256 -> V_260 = 0 ;
}
}
V_255 += V_2 -> V_118 ;
if ( V_2 -> V_112 >= V_2 -> V_220 )
goto V_48;
if ( V_2 -> V_134 < V_135 - 2 )
V_2 -> V_131 = 1 ;
V_257 = V_2 -> V_220 + V_2 -> V_220 / 2 ;
if ( V_255 > V_257 ) {
F_203 ( V_261 ? 0 : V_255 ,
V_262 ) ;
V_2 -> V_131 = 1 ;
}
} while ( -- V_2 -> V_134 >= 0 && ! V_252 );
V_48:
F_204 () ;
if ( V_2 -> V_112 )
return V_2 -> V_112 ;
if ( V_263 )
return 0 ;
if ( V_252 )
return 1 ;
if ( F_1 ( V_2 ) && ! F_195 ( V_247 , V_2 ) )
return 1 ;
return 0 ;
}
static bool F_205 ( T_7 * V_264 )
{
struct V_4 * V_4 ;
unsigned long V_265 = 0 ;
unsigned long V_107 = 0 ;
int V_266 ;
bool V_267 ;
for ( V_266 = 0 ; V_266 <= V_268 ; V_266 ++ ) {
V_4 = & V_264 -> V_269 [ V_266 ] ;
V_265 += F_206 ( V_4 ) ;
V_107 += F_3 ( V_4 , V_215 ) ;
}
V_267 = V_107 > V_265 / 2 ;
if ( ! V_267 && F_207 ( & V_264 -> V_270 ) ) {
V_264 -> V_271 = F_22 ( V_264 -> V_271 ,
(enum V_272 ) V_268 ) ;
F_208 ( & V_264 -> V_270 ) ;
}
return V_267 ;
}
static bool F_209 ( T_8 V_122 , struct V_247 * V_247 ,
T_9 * V_273 )
{
struct V_4 * V_4 ;
int V_274 = F_210 ( V_122 ) ;
T_7 * V_264 ;
if ( V_52 -> V_19 & V_275 )
goto V_48;
if ( F_150 ( V_52 ) )
goto V_48;
F_211 ( V_247 , V_274 , NULL , & V_4 ) ;
V_264 = V_4 -> V_184 ;
if ( F_205 ( V_264 ) )
goto V_48;
F_83 ( V_276 ) ;
if ( ! ( V_122 & V_123 ) ) {
F_212 ( V_264 -> V_277 ,
F_205 ( V_264 ) , V_174 ) ;
goto V_278;
}
F_213 ( V_4 -> V_184 -> V_277 ,
F_205 ( V_264 ) ) ;
V_278:
if ( F_150 ( V_52 ) )
return true ;
V_48:
return false ;
}
unsigned long F_214 ( struct V_247 * V_247 , int V_160 ,
T_8 V_122 , T_9 * V_273 )
{
unsigned long V_112 ;
struct V_1 V_2 = {
. V_122 = ( V_122 = F_215 ( V_122 ) ) ,
. V_131 = ! V_261 ,
. V_220 = V_47 ,
. V_120 = 1 ,
. V_210 = 1 ,
. V_160 = V_160 ,
. V_134 = V_135 ,
. V_3 = NULL ,
. V_273 = V_273 ,
} ;
struct V_26 V_254 = {
. V_122 = V_2 . V_122 ,
} ;
if ( F_209 ( V_122 , V_247 , V_273 ) )
return 1 ;
F_216 ( V_160 ,
V_2 . V_131 ,
V_122 ) ;
V_112 = F_196 ( V_247 , & V_2 , & V_254 ) ;
F_217 ( V_112 ) ;
return V_112 ;
}
unsigned long F_218 ( struct V_237 * V_241 ,
T_8 V_122 , bool V_279 ,
struct V_4 * V_4 ,
unsigned long * V_118 )
{
struct V_1 V_2 = {
. V_118 = 0 ,
. V_220 = V_47 ,
. V_131 = ! V_261 ,
. V_120 = 1 ,
. V_210 = ! V_279 ,
. V_160 = 0 ,
. V_134 = 0 ,
. V_3 = V_241 ,
} ;
struct V_11 * V_11 = F_183 ( V_4 , V_241 ) ;
V_2 . V_122 = ( V_122 & V_280 ) |
( V_281 & ~ V_280 ) ;
F_219 ( V_2 . V_160 ,
V_2 . V_131 ,
V_2 . V_122 ) ;
F_173 ( V_11 , & V_2 ) ;
F_220 ( V_2 . V_112 ) ;
* V_118 = V_2 . V_118 ;
return V_2 . V_112 ;
}
unsigned long F_221 ( struct V_237 * V_241 ,
T_8 V_122 ,
bool V_279 )
{
struct V_247 * V_247 ;
unsigned long V_112 ;
int V_35 ;
struct V_1 V_2 = {
. V_131 = ! V_261 ,
. V_120 = 1 ,
. V_210 = ! V_279 ,
. V_220 = V_47 ,
. V_160 = 0 ,
. V_134 = V_135 ,
. V_3 = V_241 ,
. V_273 = NULL ,
. V_122 = ( V_122 & V_280 ) |
( V_281 & ~ V_280 ) ,
} ;
struct V_26 V_254 = {
. V_122 = V_2 . V_122 ,
} ;
V_35 = F_222 ( V_241 ) ;
V_247 = F_223 ( V_35 ) -> V_282 ;
F_224 ( 0 ,
V_2 . V_131 ,
V_2 . V_122 ) ;
V_112 = F_196 ( V_247 , & V_2 , & V_254 ) ;
F_225 ( V_112 ) ;
return V_112 ;
}
static void F_226 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_237 * V_241 ;
if ( ! V_197 )
return;
V_241 = F_182 ( NULL , NULL , NULL ) ;
do {
struct V_11 * V_11 = F_183 ( V_4 , V_241 ) ;
if ( F_162 ( V_11 ) )
F_160 ( V_47 , V_11 ,
V_2 , V_213 ) ;
V_241 = F_182 ( NULL , V_241 , NULL ) ;
} while ( V_241 );
}
static bool F_227 ( struct V_4 * V_4 , int V_160 ,
unsigned long V_242 , int V_271 )
{
if ( ! F_188 ( V_4 , V_160 , F_170 ( V_4 ) +
V_242 , V_271 , 0 ) )
return false ;
if ( F_178 ( V_230 ) && V_160 &&
! F_180 ( V_4 , V_160 ) )
return false ;
return true ;
}
static bool F_228 ( T_7 * V_264 , int V_160 , int V_271 )
{
unsigned long V_245 = 0 ;
unsigned long V_283 = 0 ;
int V_266 ;
for ( V_266 = 0 ; V_266 <= V_271 ; V_266 ++ ) {
struct V_4 * V_4 = V_264 -> V_269 + V_266 ;
if ( ! F_192 ( V_4 ) )
continue;
V_245 += V_4 -> V_245 ;
if ( ! F_5 ( V_4 ) ) {
V_283 += V_4 -> V_245 ;
continue;
}
if ( F_227 ( V_4 , V_160 , 0 , V_266 ) )
V_283 += V_4 -> V_245 ;
else if ( ! V_160 )
return false ;
}
if ( V_160 )
return V_283 >= ( V_245 >> 2 ) ;
else
return true ;
}
static bool F_229 ( T_7 * V_264 , int V_160 , long V_284 ,
int V_271 )
{
if ( V_284 )
return false ;
if ( F_207 ( & V_264 -> V_277 ) ) {
F_230 ( & V_264 -> V_277 ) ;
return false ;
}
return F_228 ( V_264 , V_160 , V_271 ) ;
}
static bool F_231 ( struct V_4 * V_4 ,
int V_271 ,
struct V_1 * V_2 ,
unsigned long V_29 ,
unsigned long * V_285 )
{
int V_286 = V_2 -> V_160 ;
unsigned long V_242 ;
struct V_256 * V_256 = V_52 -> V_256 ;
struct V_26 V_254 = {
. V_122 = V_2 -> V_122 ,
} ;
bool V_287 ;
V_2 -> V_220 = F_232 ( V_47 , F_170 ( V_4 ) ) ;
if ( F_178 ( V_230 ) && V_2 -> V_160 &&
F_180 ( V_4 , V_2 -> V_160 ) !=
V_288 )
V_286 = 0 ;
V_242 = F_22 ( F_187 ( V_4 ) ,
( V_4 -> V_245 + V_246 - 1 ) /
V_246 ) ;
V_287 = ( V_193 && F_233 ( V_4 ) ) ;
if ( ! V_287 && F_227 ( V_4 , V_286 ,
V_242 , V_271 ) )
return true ;
F_181 ( V_4 , V_2 ) ;
F_199 ( V_254 . V_259 ) ;
F_201 ( F_202 ( V_4 ) , V_254 . V_259 ) ;
V_256 -> V_260 = 0 ;
F_29 ( & V_254 , V_2 -> V_118 , V_29 ) ;
V_2 -> V_112 += V_256 -> V_260 ;
* V_285 += V_2 -> V_220 ;
F_234 ( V_4 , V_180 ) ;
if ( F_5 ( V_4 ) &&
F_227 ( V_4 , V_286 , 0 , V_271 ) ) {
F_234 ( V_4 , V_181 ) ;
F_234 ( V_4 , V_182 ) ;
}
return V_2 -> V_118 >= V_2 -> V_220 ;
}
static unsigned long F_235 ( T_7 * V_264 , int V_160 ,
int * V_271 )
{
int V_266 ;
int V_289 = 0 ;
unsigned long V_250 ;
unsigned long V_251 ;
struct V_1 V_2 = {
. V_122 = V_21 ,
. V_134 = V_135 ,
. V_120 = 1 ,
. V_210 = 1 ,
. V_131 = ! V_261 ,
. V_160 = V_160 ,
. V_3 = NULL ,
} ;
F_83 ( V_290 ) ;
do {
unsigned long V_29 = 0 ;
unsigned long V_285 = 0 ;
bool V_291 = true ;
bool V_292 = ( V_160 > 0 ) ;
V_2 . V_112 = 0 ;
for ( V_266 = V_264 -> V_293 - 1 ; V_266 >= 0 ; V_266 -- ) {
struct V_4 * V_4 = V_264 -> V_269 + V_266 ;
if ( ! F_192 ( V_4 ) )
continue;
if ( V_2 . V_134 != V_135 &&
! F_5 ( V_4 ) )
continue;
F_226 ( V_4 , & V_2 ) ;
if ( V_193 && F_236 ( V_266 ) ) {
V_289 = V_266 ;
break;
}
if ( ! F_227 ( V_4 , V_160 , 0 , 0 ) ) {
V_289 = V_266 ;
break;
} else {
F_234 ( V_4 , V_181 ) ;
F_234 ( V_4 , V_182 ) ;
}
}
if ( V_266 < 0 )
goto V_48;
for ( V_266 = 0 ; V_266 <= V_289 ; V_266 ++ ) {
struct V_4 * V_4 = V_264 -> V_269 + V_266 ;
if ( ! F_192 ( V_4 ) )
continue;
V_29 += F_2 ( V_4 ) ;
if ( V_292 &&
F_237 ( V_4 , V_160 ,
F_187 ( V_4 ) ,
* V_271 , 0 ) )
V_292 = false ;
}
if ( V_2 . V_134 < V_135 - 2 )
V_2 . V_131 = 1 ;
for ( V_266 = 0 ; V_266 <= V_289 ; V_266 ++ ) {
struct V_4 * V_4 = V_264 -> V_269 + V_266 ;
if ( ! F_192 ( V_4 ) )
continue;
if ( V_2 . V_134 != V_135 &&
! F_5 ( V_4 ) )
continue;
V_2 . V_118 = 0 ;
V_251 = 0 ;
V_250 = F_194 ( V_4 ,
V_160 , V_2 . V_122 ,
& V_251 ) ;
V_2 . V_112 += V_250 ;
if ( F_231 ( V_4 , V_289 , & V_2 ,
V_29 , & V_285 ) )
V_291 = false ;
}
if ( F_207 ( & V_264 -> V_277 ) &&
F_205 ( V_264 ) )
F_230 ( & V_264 -> V_277 ) ;
if ( V_160 && V_2 . V_112 >= 2UL << V_160 )
V_160 = V_2 . V_160 = 0 ;
if ( F_238 () || F_239 () )
break;
if ( V_292 && V_2 . V_112 > V_285 )
F_240 ( V_264 , V_160 ) ;
if ( V_291 || ! V_2 . V_112 )
V_2 . V_134 -- ;
} while ( V_2 . V_134 >= 1 &&
! F_228 ( V_264 , V_160 , * V_271 ) );
V_48:
* V_271 = V_289 ;
return V_160 ;
}
static void F_241 ( T_7 * V_264 , int V_160 , int V_271 )
{
long V_284 = 0 ;
F_242 ( V_294 ) ;
if ( F_243 ( V_52 ) || F_239 () )
return;
F_244 ( & V_264 -> V_270 , & V_294 , V_295 ) ;
if ( F_229 ( V_264 , V_160 , V_284 , V_271 ) ) {
V_284 = F_245 ( V_174 / 10 ) ;
F_246 ( & V_264 -> V_270 , & V_294 ) ;
F_244 ( & V_264 -> V_270 , & V_294 , V_295 ) ;
}
if ( F_229 ( V_264 , V_160 , V_284 , V_271 ) ) {
F_247 ( V_264 -> V_185 ) ;
F_248 ( V_264 , V_296 ) ;
F_249 ( V_264 ) ;
if ( ! F_239 () )
F_250 () ;
F_248 ( V_264 , V_297 ) ;
} else {
if ( V_284 )
F_83 ( V_298 ) ;
else
F_83 ( V_299 ) ;
}
F_246 ( & V_264 -> V_270 , & V_294 ) ;
}
static int F_251 ( void * V_300 )
{
unsigned long V_160 , V_301 ;
unsigned V_302 ;
int V_271 , V_303 ;
int V_304 ;
T_7 * V_264 = ( T_7 * ) V_300 ;
struct V_305 * V_306 = V_52 ;
struct V_256 V_256 = {
. V_260 = 0 ,
} ;
const struct V_307 * V_307 = F_252 ( V_264 -> V_185 ) ;
F_253 ( V_21 ) ;
if ( ! F_254 ( V_307 ) )
F_255 ( V_306 , V_307 ) ;
V_52 -> V_256 = & V_256 ;
V_306 -> V_19 |= V_308 | V_53 | V_309 ;
F_256 () ;
V_160 = V_301 = 0 ;
V_302 = 0 ;
V_271 = V_303 = V_264 -> V_293 - 1 ;
V_304 = V_271 ;
for ( ; ; ) {
bool V_43 ;
if ( V_304 >= V_303 &&
V_302 == V_301 ) {
V_301 = V_264 -> V_310 ;
V_303 = V_264 -> V_271 ;
V_264 -> V_310 = 0 ;
V_264 -> V_271 = V_264 -> V_293 - 1 ;
}
if ( V_160 < V_301 || V_271 > V_303 ) {
V_160 = V_301 ;
V_271 = V_303 ;
} else {
F_241 ( V_264 , V_302 ,
V_304 ) ;
V_160 = V_264 -> V_310 ;
V_271 = V_264 -> V_271 ;
V_301 = V_160 ;
V_303 = V_271 ;
V_264 -> V_310 = 0 ;
V_264 -> V_271 = V_264 -> V_293 - 1 ;
}
V_43 = F_238 () ;
if ( F_239 () )
break;
if ( ! V_43 ) {
F_257 ( V_264 -> V_185 , V_160 ) ;
V_304 = V_271 ;
V_302 = F_235 ( V_264 , V_160 ,
& V_304 ) ;
}
}
V_52 -> V_256 = NULL ;
return 0 ;
}
void F_258 ( struct V_4 * V_4 , int V_160 , enum V_272 V_271 )
{
T_7 * V_264 ;
if ( ! F_192 ( V_4 ) )
return;
if ( ! F_193 ( V_4 , V_21 ) )
return;
V_264 = V_4 -> V_184 ;
if ( V_264 -> V_310 < V_160 ) {
V_264 -> V_310 = V_160 ;
V_264 -> V_271 = F_22 ( V_264 -> V_271 , V_271 ) ;
}
if ( ! F_207 ( & V_264 -> V_270 ) )
return;
if ( F_227 ( V_4 , V_160 , 0 , 0 ) )
return;
F_259 ( V_264 -> V_185 , F_156 ( V_4 ) , V_160 ) ;
F_208 ( & V_264 -> V_270 ) ;
}
unsigned long F_260 ( void )
{
int V_5 ;
V_5 = F_261 ( V_6 ) +
F_261 ( V_7 ) ;
if ( F_4 () > 0 )
V_5 += F_261 ( V_8 ) +
F_261 ( V_9 ) ;
return V_5 ;
}
unsigned long F_262 ( unsigned long V_220 )
{
struct V_256 V_256 ;
struct V_1 V_2 = {
. V_122 = V_281 ,
. V_210 = 1 ,
. V_120 = 1 ,
. V_131 = 1 ,
. V_220 = V_220 ,
. V_183 = 1 ,
. V_160 = 0 ,
. V_134 = V_135 ,
} ;
struct V_26 V_254 = {
. V_122 = V_2 . V_122 ,
} ;
struct V_247 * V_247 = F_263 ( F_264 () , V_2 . V_122 ) ;
struct V_305 * V_300 = V_52 ;
unsigned long V_112 ;
V_300 -> V_19 |= V_308 ;
F_253 ( V_2 . V_122 ) ;
V_256 . V_260 = 0 ;
V_300 -> V_256 = & V_256 ;
V_112 = F_196 ( V_247 , & V_2 , & V_254 ) ;
V_300 -> V_256 = NULL ;
F_265 () ;
V_300 -> V_19 &= ~ V_308 ;
return V_112 ;
}
static int F_266 ( struct V_311 * V_312 , unsigned long V_313 ,
void * V_314 )
{
int V_35 ;
if ( V_313 == V_315 || V_313 == V_316 ) {
F_267 (nid, N_MEMORY) {
T_7 * V_264 = F_223 ( V_35 ) ;
const struct V_307 * V_317 ;
V_317 = F_252 ( V_264 -> V_185 ) ;
if ( F_268 ( V_318 , V_317 ) < V_319 )
F_255 ( V_264 -> F_251 , V_317 ) ;
}
}
return V_320 ;
}
int F_269 ( int V_35 )
{
T_7 * V_264 = F_223 ( V_35 ) ;
int V_43 = 0 ;
if ( V_264 -> F_251 )
return 0 ;
V_264 -> F_251 = F_270 ( F_251 , V_264 , L_3 , V_35 ) ;
if ( F_271 ( V_264 -> F_251 ) ) {
F_56 ( V_321 == V_322 ) ;
F_272 ( L_4 , V_35 ) ;
V_43 = F_273 ( V_264 -> F_251 ) ;
V_264 -> F_251 = NULL ;
}
return V_43 ;
}
void F_274 ( int V_35 )
{
struct V_305 * F_251 = F_223 ( V_35 ) -> F_251 ;
if ( F_251 ) {
F_275 ( F_251 ) ;
F_223 ( V_35 ) -> F_251 = NULL ;
}
}
static int T_10 F_276 ( void )
{
int V_35 ;
F_277 () ;
F_267 (nid, N_MEMORY)
F_269 ( V_35 ) ;
F_278 ( F_266 , 0 ) ;
return 0 ;
}
static inline unsigned long F_279 ( struct V_4 * V_4 )
{
unsigned long V_323 = F_3 ( V_4 , V_324 ) ;
unsigned long V_325 = F_3 ( V_4 , V_7 ) +
F_3 ( V_4 , V_6 ) ;
return ( V_325 > V_323 ) ? ( V_325 - V_323 ) : 0 ;
}
static long F_280 ( struct V_4 * V_4 )
{
long V_326 ;
long V_31 = 0 ;
if ( V_327 & V_328 )
V_326 = F_3 ( V_4 , V_329 ) ;
else
V_326 = F_279 ( V_4 ) ;
if ( ! ( V_327 & V_330 ) )
V_31 += F_3 ( V_4 , V_331 ) ;
if ( F_60 ( V_31 > V_326 ) )
V_31 = V_326 ;
return V_326 - V_31 ;
}
static int F_281 ( struct V_4 * V_4 , T_8 V_122 , unsigned int V_160 )
{
const unsigned long V_159 = 1 << V_160 ;
struct V_305 * V_300 = V_52 ;
struct V_256 V_256 ;
struct V_1 V_2 = {
. V_131 = ! ! ( V_327 & V_330 ) ,
. V_120 = ! ! ( V_327 & V_328 ) ,
. V_210 = 1 ,
. V_220 = F_232 ( V_159 , V_47 ) ,
. V_122 = ( V_122 = F_215 ( V_122 ) ) ,
. V_160 = V_160 ,
. V_134 = V_332 ,
} ;
struct V_26 V_254 = {
. V_122 = V_2 . V_122 ,
} ;
unsigned long V_333 , V_334 ;
F_25 () ;
V_300 -> V_19 |= V_308 | V_53 ;
F_253 ( V_122 ) ;
V_256 . V_260 = 0 ;
V_300 -> V_256 = & V_256 ;
if ( F_280 ( V_4 ) > V_4 -> V_335 ) {
do {
F_181 ( V_4 , & V_2 ) ;
} while ( V_2 . V_112 < V_159 && -- V_2 . V_134 >= 0 );
}
V_333 = F_3 ( V_4 , V_336 ) ;
if ( V_333 > V_4 -> V_337 ) {
F_199 ( V_254 . V_259 ) ;
F_201 ( F_202 ( V_4 ) , V_254 . V_259 ) ;
for (; ; ) {
unsigned long V_29 = F_2 ( V_4 ) ;
if ( ! F_29 ( & V_254 , V_2 . V_118 , V_29 ) )
break;
V_334 = F_3 ( V_4 ,
V_336 ) ;
if ( V_334 + V_159 <= V_333 )
break;
}
V_334 = F_3 ( V_4 , V_336 ) ;
if ( V_334 < V_333 )
V_2 . V_112 += V_333 - V_334 ;
}
V_300 -> V_256 = NULL ;
V_52 -> V_19 &= ~ ( V_308 | V_53 ) ;
F_265 () ;
return V_2 . V_112 >= V_159 ;
}
int F_282 ( struct V_4 * V_4 , T_8 V_122 , unsigned int V_160 )
{
int V_185 ;
int V_43 ;
if ( F_280 ( V_4 ) <= V_4 -> V_335 &&
F_3 ( V_4 , V_336 ) <= V_4 -> V_337 )
return V_338 ;
if ( ! F_5 ( V_4 ) )
return V_338 ;
if ( ! ( V_122 & V_339 ) || ( V_52 -> V_19 & V_308 ) )
return V_340 ;
V_185 = F_202 ( V_4 ) ;
if ( F_283 ( V_185 , V_341 ) && V_185 != F_264 () )
return V_340 ;
if ( F_284 ( V_4 , V_342 ) )
return V_340 ;
V_43 = F_281 ( V_4 , V_122 , V_160 ) ;
F_234 ( V_4 , V_342 ) ;
if ( ! V_43 )
F_83 ( V_343 ) ;
return V_43 ;
}
int F_77 ( struct V_49 * V_49 )
{
return ! F_285 ( F_42 ( V_49 ) ) && ! F_286 ( V_49 ) ;
}
void F_287 ( struct V_49 * * V_344 , int V_159 )
{
struct V_11 * V_11 ;
struct V_4 * V_4 = NULL ;
int V_345 = 0 ;
int V_346 = 0 ;
int V_266 ;
for ( V_266 = 0 ; V_266 < V_159 ; V_266 ++ ) {
struct V_49 * V_49 = V_344 [ V_266 ] ;
struct V_4 * V_347 ;
V_345 ++ ;
V_347 = F_98 ( V_49 ) ;
if ( V_347 != V_4 ) {
if ( V_4 )
F_66 ( & V_4 -> V_161 ) ;
V_4 = V_347 ;
F_58 ( & V_4 -> V_161 ) ;
}
V_11 = F_135 ( V_49 , V_4 ) ;
if ( ! F_75 ( V_49 ) || ! F_73 ( V_49 ) )
continue;
if ( F_77 ( V_49 ) ) {
enum V_12 V_13 = F_288 ( V_49 ) ;
F_74 ( F_97 ( V_49 ) ) ;
F_76 ( V_49 ) ;
F_138 ( V_49 , V_11 , V_348 ) ;
F_142 ( V_49 , V_11 , V_13 ) ;
V_346 ++ ;
}
}
if ( V_4 ) {
F_159 ( V_82 , V_346 ) ;
F_159 ( V_349 , V_345 ) ;
F_66 ( & V_4 -> V_161 ) ;
}
}
static void F_289 ( void )
{
F_290 ( V_350
L_5
L_6
L_7 ,
V_52 -> V_351 ) ;
}
int F_291 ( struct V_352 * V_353 , int V_354 ,
void T_11 * V_355 ,
T_1 * V_356 , T_12 * V_357 )
{
F_289 () ;
F_292 ( V_353 , V_354 , V_355 , V_356 , V_357 ) ;
V_358 = 0 ;
return 0 ;
}
static T_13 F_293 ( struct V_359 * V_360 ,
struct V_361 * V_362 ,
char * V_363 )
{
F_289 () ;
return sprintf ( V_363 , L_8 ) ;
}
static T_13 F_294 ( struct V_359 * V_360 ,
struct V_361 * V_362 ,
const char * V_363 , T_1 V_364 )
{
F_289 () ;
return 1 ;
}
int F_295 ( struct V_365 * V_365 )
{
return F_296 ( & V_365 -> V_360 , & V_366 ) ;
}
void F_297 ( struct V_365 * V_365 )
{
F_298 ( & V_365 -> V_360 , & V_366 ) ;
}
