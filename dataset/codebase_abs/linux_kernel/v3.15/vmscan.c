static bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return true ;
}
static unsigned long F_2 ( struct V_4 * V_4 )
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
while ( V_32 >= V_36 ||
V_32 >= V_33 ) {
unsigned long V_43 ;
unsigned long V_44 = F_22 ( V_36 , V_32 ) ;
V_27 -> V_44 = V_44 ;
V_43 = V_15 -> V_42 ( V_15 , V_27 ) ;
if ( V_43 == V_45 )
break;
V_30 += V_43 ;
F_24 ( V_46 , V_44 ) ;
V_32 -= V_44 ;
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
if ( ! ( V_15 -> V_19 & V_20 ) ) {
V_27 -> V_35 = 0 ;
V_30 += F_18 ( V_27 , V_15 ,
V_28 , V_29 ) ;
continue;
}
F_32 (shrinkctl->nid, shrinkctl->nodes_to_scan) {
if ( F_33 ( V_27 -> V_35 ) )
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
static int F_55 ( struct V_54 * V_55 , struct V_49 * V_49 ,
bool V_75 )
{
F_56 ( ! F_57 ( V_49 ) ) ;
F_56 ( V_55 != F_42 ( V_49 ) ) ;
F_58 ( & V_55 -> V_76 ) ;
if ( ! F_59 ( V_49 , 2 ) )
goto V_77;
if ( F_60 ( F_61 ( V_49 ) ) ) {
F_62 ( V_49 , 2 ) ;
goto V_77;
}
if ( F_63 ( V_49 ) ) {
T_3 V_78 = { . V_79 = F_64 (page) } ;
F_65 ( V_49 ) ;
F_66 ( & V_55 -> V_76 ) ;
F_67 ( V_78 , V_49 ) ;
} else {
void (* F_68)( struct V_49 * );
void * V_80 = NULL ;
F_68 = V_55 -> V_59 -> F_68 ;
if ( V_75 && F_69 ( V_49 ) &&
! F_70 ( V_55 ) )
V_80 = F_71 ( V_55 , V_49 ) ;
F_72 ( V_49 , V_80 ) ;
F_66 ( & V_55 -> V_76 ) ;
F_73 ( V_49 ) ;
if ( F_68 != NULL )
F_68 ( V_49 ) ;
}
return 1 ;
V_77:
F_66 ( & V_55 -> V_76 ) ;
return 0 ;
}
int F_74 ( struct V_54 * V_55 , struct V_49 * V_49 )
{
if ( F_55 ( V_55 , V_49 , false ) ) {
F_62 ( V_49 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_75 ( struct V_49 * V_49 )
{
bool V_81 ;
int V_82 = F_76 ( V_49 ) ;
F_77 ( F_78 ( V_49 ) , V_49 ) ;
V_83:
F_79 ( V_49 ) ;
if ( F_80 ( V_49 ) ) {
V_81 = false ;
F_81 ( V_49 ) ;
} else {
V_81 = true ;
F_82 ( V_49 ) ;
F_83 () ;
}
if ( V_81 && F_80 ( V_49 ) ) {
if ( ! F_84 ( V_49 ) ) {
F_85 ( V_49 ) ;
goto V_83;
}
}
if ( V_82 && ! V_81 )
F_86 ( V_84 ) ;
else if ( ! V_82 && V_81 )
F_86 ( V_85 ) ;
F_85 ( V_49 ) ;
}
static enum V_86 F_87 ( struct V_49 * V_49 ,
struct V_1 * V_2 )
{
int V_87 , V_88 ;
unsigned long V_89 ;
V_87 = F_88 ( V_49 , 1 , V_2 -> V_3 ,
& V_89 ) ;
V_88 = F_89 ( V_49 ) ;
if ( V_89 & V_90 )
return V_91 ;
if ( V_87 ) {
if ( F_90 ( V_49 ) )
return V_92 ;
F_91 ( V_49 ) ;
if ( V_88 || V_87 > 1 )
return V_92 ;
if ( V_89 & V_93 )
return V_92 ;
return V_94 ;
}
if ( V_88 && ! F_90 ( V_49 ) )
return V_95 ;
return V_91 ;
}
static void F_92 ( struct V_49 * V_49 ,
bool * V_96 , bool * V_97 )
{
struct V_54 * V_55 ;
if ( ! F_69 ( V_49 ) ) {
* V_96 = false ;
* V_97 = false ;
return;
}
* V_96 = F_61 ( V_49 ) ;
* V_97 = F_51 ( V_49 ) ;
if ( ! F_37 ( V_49 ) )
return;
V_55 = F_42 ( V_49 ) ;
if ( V_55 && V_55 -> V_59 -> V_98 )
V_55 -> V_59 -> V_98 ( V_49 , V_96 , V_97 ) ;
}
static unsigned long F_93 ( struct V_99 * V_100 ,
struct V_4 * V_4 ,
struct V_1 * V_2 ,
enum V_101 V_101 ,
unsigned long * V_102 ,
unsigned long * V_103 ,
unsigned long * V_104 ,
unsigned long * V_105 ,
unsigned long * V_106 ,
bool V_107 )
{
F_94 ( V_108 ) ;
F_94 ( V_109 ) ;
int V_110 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_114 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
F_25 () ;
F_95 () ;
while ( ! F_96 ( V_100 ) ) {
struct V_54 * V_55 ;
struct V_49 * V_49 ;
int V_117 ;
enum V_86 V_118 = V_95 ;
bool V_96 , V_97 ;
F_25 () ;
V_49 = F_97 ( V_100 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( ! F_98 ( V_49 ) )
goto V_119;
F_77 ( F_99 ( V_49 ) , V_49 ) ;
F_77 ( F_100 ( V_49 ) != V_4 , V_49 ) ;
V_2 -> V_120 ++ ;
if ( F_60 ( ! F_80 ( V_49 ) ) )
goto V_121;
if ( ! V_2 -> V_122 && F_101 ( V_49 ) )
goto V_123;
if ( F_101 ( V_49 ) || F_63 ( V_49 ) )
V_2 -> V_120 ++ ;
V_117 = ( V_2 -> V_124 & V_125 ) ||
( F_63 ( V_49 ) && ( V_2 -> V_124 & V_126 ) ) ;
F_92 ( V_49 , & V_96 , & V_97 ) ;
if ( V_96 || V_97 )
V_112 ++ ;
if ( V_96 && ! V_97 )
V_111 ++ ;
V_55 = F_42 ( V_49 ) ;
if ( ( V_55 && F_39 ( V_55 -> V_50 ) ) ||
( V_97 && F_102 ( V_49 ) ) )
V_113 ++ ;
if ( F_51 ( V_49 ) ) {
if ( F_103 () &&
F_102 ( V_49 ) &&
F_104 ( V_4 ) ) {
V_116 ++ ;
goto V_123;
} else if ( F_1 ( V_2 ) ||
! F_102 ( V_49 ) || ! ( V_2 -> V_124 & V_126 ) ) {
F_49 ( V_49 ) ;
V_115 ++ ;
goto V_123;
} else {
F_105 ( V_49 ) ;
}
}
if ( ! V_107 )
V_118 = F_87 ( V_49 , V_2 ) ;
switch ( V_118 ) {
case V_92 :
goto V_127;
case V_94 :
goto V_123;
case V_91 :
case V_95 :
;
}
if ( F_106 ( V_49 ) && ! F_63 ( V_49 ) ) {
if ( ! ( V_2 -> V_124 & V_126 ) )
goto V_123;
if ( ! F_107 ( V_49 , V_100 ) )
goto V_127;
V_117 = 1 ;
V_55 = F_42 ( V_49 ) ;
}
if ( F_101 ( V_49 ) && V_55 ) {
switch ( F_108 ( V_49 , V_101 ) ) {
case V_128 :
goto V_127;
case V_129 :
goto V_123;
case V_130 :
goto V_121;
case V_131 :
;
}
}
if ( F_61 ( V_49 ) ) {
if ( F_69 ( V_49 ) &&
( ! F_103 () ||
! F_109 ( V_4 ) ) ) {
F_54 ( V_49 , V_132 ) ;
F_49 ( V_49 ) ;
goto V_123;
}
if ( V_118 == V_95 )
goto V_123;
if ( ! V_117 )
goto V_123;
if ( ! V_2 -> V_133 )
goto V_123;
switch ( F_45 ( V_49 , V_55 , V_2 ) ) {
case V_56 :
goto V_123;
case V_61 :
goto V_127;
case V_74 :
if ( F_51 ( V_49 ) )
goto V_119;
if ( F_61 ( V_49 ) )
goto V_119;
if ( ! F_98 ( V_49 ) )
goto V_119;
if ( F_61 ( V_49 ) || F_51 ( V_49 ) )
goto V_123;
V_55 = F_42 ( V_49 ) ;
case V_58 :
;
}
}
if ( F_37 ( V_49 ) ) {
if ( ! F_110 ( V_49 , V_2 -> V_124 ) )
goto V_127;
if ( ! V_55 && F_36 ( V_49 ) == 1 ) {
F_44 ( V_49 ) ;
if ( F_111 ( V_49 ) )
goto V_134;
else {
V_114 ++ ;
continue;
}
}
}
if ( ! V_55 || ! F_55 ( V_55 , V_49 , true ) )
goto V_123;
F_112 ( V_49 ) ;
V_134:
V_114 ++ ;
F_113 ( & V_49 -> V_13 , & V_109 ) ;
continue;
V_121:
if ( F_63 ( V_49 ) )
F_114 ( V_49 ) ;
F_44 ( V_49 ) ;
F_75 ( V_49 ) ;
continue;
V_127:
if ( F_63 ( V_49 ) && F_115 () )
F_114 ( V_49 ) ;
F_77 ( F_99 ( V_49 ) , V_49 ) ;
F_116 ( V_49 ) ;
V_110 ++ ;
V_123:
F_44 ( V_49 ) ;
V_119:
F_113 ( & V_49 -> V_13 , & V_108 ) ;
F_77 ( F_78 ( V_49 ) || F_76 ( V_49 ) , V_49 ) ;
}
F_117 ( & V_109 , 1 ) ;
F_118 ( & V_108 , V_100 ) ;
F_24 ( V_135 , V_110 ) ;
F_119 () ;
* V_102 += V_112 ;
* V_104 += V_113 ;
* V_103 += V_111 ;
* V_105 += V_115 ;
* V_106 += V_116 ;
return V_114 ;
}
unsigned long F_120 ( struct V_4 * V_4 ,
struct V_99 * V_100 )
{
struct V_1 V_2 = {
. V_124 = V_21 ,
. V_136 = V_137 ,
. V_122 = 1 ,
} ;
unsigned long V_43 , V_138 , V_139 , V_140 , V_141 , V_142 ;
struct V_49 * V_49 , * V_143 ;
F_94 ( V_144 ) ;
F_121 (page, next, page_list, lru) {
if ( F_69 ( V_49 ) && ! F_61 ( V_49 ) &&
! F_122 ( V_49 ) ) {
F_123 ( V_49 ) ;
F_124 ( & V_49 -> V_13 , & V_144 ) ;
}
}
V_43 = F_93 ( & V_144 , V_4 , & V_2 ,
V_145 | V_146 ,
& V_138 , & V_139 , & V_140 , & V_141 , & V_142 , true ) ;
F_118 ( & V_144 , V_100 ) ;
F_125 ( V_4 , V_147 , - V_43 ) ;
return V_43 ;
}
int F_126 ( struct V_49 * V_49 , T_4 V_148 )
{
int V_43 = - V_149 ;
if ( ! F_78 ( V_49 ) )
return V_43 ;
if ( F_76 ( V_49 ) && ! ( V_148 & V_150 ) )
return V_43 ;
V_43 = - V_151 ;
if ( V_148 & ( V_152 | V_153 ) ) {
if ( F_51 ( V_49 ) )
return V_43 ;
if ( F_61 ( V_49 ) ) {
struct V_54 * V_55 ;
if ( V_148 & V_152 )
return V_43 ;
V_55 = F_42 ( V_49 ) ;
if ( V_55 && ! V_55 -> V_59 -> V_154 )
return V_43 ;
}
}
if ( ( V_148 & V_155 ) && F_101 ( V_49 ) )
return V_43 ;
if ( F_127 ( F_128 ( V_49 ) ) ) {
F_129 ( V_49 ) ;
V_43 = 0 ;
}
return V_43 ;
}
static unsigned long F_130 ( unsigned long V_44 ,
struct V_11 * V_11 , struct V_99 * V_156 ,
unsigned long * V_120 , struct V_1 * V_2 ,
T_4 V_148 , enum V_12 V_13 )
{
struct V_99 * V_157 = & V_11 -> V_158 [ V_13 ] ;
unsigned long V_159 = 0 ;
unsigned long V_160 ;
for ( V_160 = 0 ; V_160 < V_44 && ! F_96 ( V_157 ) ; V_160 ++ ) {
struct V_49 * V_49 ;
int V_161 ;
V_49 = F_97 ( V_157 ) ;
F_131 ( V_49 , V_157 , V_19 ) ;
F_77 ( ! F_78 ( V_49 ) , V_49 ) ;
switch ( F_126 ( V_49 , V_148 ) ) {
case 0 :
V_161 = F_132 ( V_49 ) ;
F_133 ( V_11 , V_13 , - V_161 ) ;
F_124 ( & V_49 -> V_13 , V_156 ) ;
V_159 += V_161 ;
break;
case - V_151 :
F_124 ( & V_49 -> V_13 , V_157 ) ;
continue;
default:
F_134 () ;
}
}
* V_120 = V_160 ;
F_135 ( V_2 -> V_162 , V_44 , V_160 ,
V_159 , V_148 , F_136 ( V_13 ) ) ;
return V_159 ;
}
int F_84 ( struct V_49 * V_49 )
{
int V_43 = - V_151 ;
F_77 ( ! F_36 ( V_49 ) , V_49 ) ;
if ( F_78 ( V_49 ) ) {
struct V_4 * V_4 = F_100 ( V_49 ) ;
struct V_11 * V_11 ;
F_58 ( & V_4 -> V_163 ) ;
V_11 = F_137 ( V_49 , V_4 ) ;
if ( F_78 ( V_49 ) ) {
int V_13 = F_138 ( V_49 ) ;
F_139 ( V_49 ) ;
F_129 ( V_49 ) ;
F_140 ( V_49 , V_11 , V_13 ) ;
V_43 = 0 ;
}
F_66 ( & V_4 -> V_163 ) ;
}
return V_43 ;
}
static int F_141 ( struct V_4 * V_4 , int V_164 ,
struct V_1 * V_2 )
{
unsigned long V_165 , V_166 ;
if ( F_103 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_164 ) {
V_165 = F_3 ( V_4 , V_7 ) ;
V_166 = F_3 ( V_4 , V_147 ) ;
} else {
V_165 = F_3 ( V_4 , V_9 ) ;
V_166 = F_3 ( V_4 , V_167 ) ;
}
if ( ( V_2 -> V_124 & V_168 ) == V_168 )
V_165 >>= 3 ;
return V_166 > V_165 ;
}
static T_5 void
F_142 ( struct V_11 * V_11 , struct V_99 * V_100 )
{
struct V_169 * V_170 = & V_11 -> V_170 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_94 ( V_171 ) ;
while ( ! F_96 ( V_100 ) ) {
struct V_49 * V_49 = F_97 ( V_100 ) ;
int V_13 ;
F_77 ( F_78 ( V_49 ) , V_49 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_60 ( ! F_80 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_163 ) ;
F_75 ( V_49 ) ;
F_58 ( & V_4 -> V_163 ) ;
continue;
}
V_11 = F_137 ( V_49 , V_4 ) ;
F_143 ( V_49 ) ;
V_13 = F_138 ( V_49 ) ;
F_144 ( V_49 , V_11 , V_13 ) ;
if ( F_145 ( V_13 ) ) {
int V_164 = F_136 ( V_13 ) ;
int V_172 = F_132 ( V_49 ) ;
V_170 -> V_173 [ V_164 ] += V_172 ;
}
if ( F_111 ( V_49 ) ) {
F_146 ( V_49 ) ;
F_147 ( V_49 ) ;
F_140 ( V_49 , V_11 , V_13 ) ;
if ( F_60 ( F_148 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_163 ) ;
( * F_149 ( V_49 ) ) ( V_49 ) ;
F_58 ( & V_4 -> V_163 ) ;
} else
F_113 ( & V_49 -> V_13 , & V_171 ) ;
}
}
F_118 ( & V_171 , V_100 ) ;
}
static T_5 unsigned long
F_150 ( unsigned long V_44 , struct V_11 * V_11 ,
struct V_1 * V_2 , enum V_12 V_13 )
{
F_94 ( V_100 ) ;
unsigned long V_120 ;
unsigned long V_114 = 0 ;
unsigned long V_159 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
T_4 V_174 = 0 ;
int V_164 = F_136 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
struct V_169 * V_170 = & V_11 -> V_170 ;
while ( F_60 ( F_141 ( V_4 , V_164 , V_2 ) ) ) {
F_151 ( V_175 , V_176 / 10 ) ;
if ( F_152 ( V_52 ) )
return V_47 ;
}
F_153 () ;
if ( ! V_2 -> V_122 )
V_174 |= V_155 ;
if ( ! V_2 -> V_133 )
V_174 |= V_152 ;
F_58 ( & V_4 -> V_163 ) ;
V_159 = F_130 ( V_44 , V_11 , & V_100 ,
& V_120 , V_2 , V_174 , V_13 ) ;
F_154 ( V_4 , V_14 + V_13 , - V_159 ) ;
F_154 ( V_4 , V_167 + V_164 , V_159 ) ;
if ( F_1 ( V_2 ) ) {
V_4 -> V_10 += V_120 ;
if ( F_103 () )
F_155 ( V_177 , V_4 , V_120 ) ;
else
F_155 ( V_178 , V_4 , V_120 ) ;
}
F_66 ( & V_4 -> V_163 ) ;
if ( V_159 == 0 )
return 0 ;
V_114 = F_93 ( & V_100 , V_4 , V_2 , V_145 ,
& V_112 , & V_111 , & V_113 ,
& V_115 , & V_116 ,
false ) ;
F_58 ( & V_4 -> V_163 ) ;
V_170 -> V_179 [ V_164 ] += V_159 ;
if ( F_1 ( V_2 ) ) {
if ( F_103 () )
F_155 ( V_180 , V_4 ,
V_114 ) ;
else
F_155 ( V_181 , V_4 ,
V_114 ) ;
}
F_142 ( V_11 , & V_100 ) ;
F_154 ( V_4 , V_167 + V_164 , - V_159 ) ;
F_66 ( & V_4 -> V_163 ) ;
F_117 ( & V_100 , 1 ) ;
if ( V_115 && V_115 == V_159 )
F_156 ( V_4 , V_182 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_112 && V_112 == V_113 )
F_156 ( V_4 , V_183 ) ;
if ( V_111 == V_159 )
F_156 ( V_4 , V_184 ) ;
if ( V_111 == V_159 || V_116 )
F_151 ( V_175 , V_176 / 10 ) ;
}
if ( ! V_2 -> V_185 && ! F_103 () )
F_157 ( V_4 , V_175 , V_176 / 10 ) ;
F_158 ( V_4 -> V_186 -> V_187 ,
F_159 ( V_4 ) ,
V_120 , V_114 ,
V_2 -> V_136 ,
F_160 ( V_164 ) ) ;
return V_114 ;
}
static void F_161 ( struct V_11 * V_11 ,
struct V_99 * V_24 ,
struct V_99 * V_171 ,
enum V_12 V_13 )
{
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_188 = 0 ;
struct V_49 * V_49 ;
int V_161 ;
while ( ! F_96 ( V_24 ) ) {
V_49 = F_97 ( V_24 ) ;
V_11 = F_137 ( V_49 , V_4 ) ;
F_77 ( F_78 ( V_49 ) , V_49 ) ;
F_143 ( V_49 ) ;
V_161 = F_132 ( V_49 ) ;
F_133 ( V_11 , V_13 , V_161 ) ;
F_124 ( & V_49 -> V_13 , & V_11 -> V_158 [ V_13 ] ) ;
V_188 += V_161 ;
if ( F_111 ( V_49 ) ) {
F_146 ( V_49 ) ;
F_147 ( V_49 ) ;
F_140 ( V_49 , V_11 , V_13 ) ;
if ( F_60 ( F_148 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_163 ) ;
( * F_149 ( V_49 ) ) ( V_49 ) ;
F_58 ( & V_4 -> V_163 ) ;
} else
F_113 ( & V_49 -> V_13 , V_171 ) ;
}
}
F_154 ( V_4 , V_14 + V_13 , V_188 ) ;
if ( ! F_145 ( V_13 ) )
F_162 ( V_189 , V_188 ) ;
}
static void F_163 ( unsigned long V_44 ,
struct V_11 * V_11 ,
struct V_1 * V_2 ,
enum V_12 V_13 )
{
unsigned long V_159 ;
unsigned long V_120 ;
unsigned long V_89 ;
F_94 ( V_190 ) ;
F_94 ( V_191 ) ;
F_94 ( V_192 ) ;
struct V_49 * V_49 ;
struct V_169 * V_170 = & V_11 -> V_170 ;
unsigned long V_193 = 0 ;
T_4 V_174 = 0 ;
int V_164 = F_136 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_153 () ;
if ( ! V_2 -> V_122 )
V_174 |= V_155 ;
if ( ! V_2 -> V_133 )
V_174 |= V_152 ;
F_58 ( & V_4 -> V_163 ) ;
V_159 = F_130 ( V_44 , V_11 , & V_190 ,
& V_120 , V_2 , V_174 , V_13 ) ;
if ( F_1 ( V_2 ) )
V_4 -> V_10 += V_120 ;
V_170 -> V_179 [ V_164 ] += V_159 ;
F_155 ( V_194 , V_4 , V_120 ) ;
F_154 ( V_4 , V_14 + V_13 , - V_159 ) ;
F_154 ( V_4 , V_167 + V_164 , V_159 ) ;
F_66 ( & V_4 -> V_163 ) ;
while ( ! F_96 ( & V_190 ) ) {
F_25 () ;
V_49 = F_97 ( & V_190 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_60 ( ! F_80 ( V_49 ) ) ) {
F_75 ( V_49 ) ;
continue;
}
if ( F_60 ( V_195 ) ) {
if ( F_37 ( V_49 ) && F_98 ( V_49 ) ) {
if ( F_37 ( V_49 ) )
F_110 ( V_49 , 0 ) ;
F_44 ( V_49 ) ;
}
}
if ( F_88 ( V_49 , 0 , V_2 -> V_3 ,
& V_89 ) ) {
V_193 += F_132 ( V_49 ) ;
if ( ( V_89 & V_93 ) && F_69 ( V_49 ) ) {
F_113 ( & V_49 -> V_13 , & V_191 ) ;
continue;
}
}
F_123 ( V_49 ) ;
F_113 ( & V_49 -> V_13 , & V_192 ) ;
}
F_58 ( & V_4 -> V_163 ) ;
V_170 -> V_173 [ V_164 ] += V_193 ;
F_161 ( V_11 , & V_191 , & V_190 , V_13 ) ;
F_161 ( V_11 , & V_192 , & V_190 , V_13 - V_196 ) ;
F_154 ( V_4 , V_167 + V_164 , - V_159 ) ;
F_66 ( & V_4 -> V_163 ) ;
F_117 ( & V_190 , 1 ) ;
}
static int F_164 ( struct V_4 * V_4 )
{
unsigned long V_197 , V_165 ;
V_197 = F_3 ( V_4 , V_8 ) ;
V_165 = F_3 ( V_4 , V_9 ) ;
if ( V_165 * V_4 -> V_198 < V_197 )
return 1 ;
return 0 ;
}
static int F_165 ( struct V_11 * V_11 )
{
if ( ! V_199 )
return 0 ;
if ( ! F_7 () )
return F_166 ( V_11 ) ;
return F_164 ( F_9 ( V_11 ) ) ;
}
static inline int F_165 ( struct V_11 * V_11 )
{
return 0 ;
}
static int F_167 ( struct V_11 * V_11 )
{
unsigned long V_165 ;
unsigned long V_197 ;
V_165 = F_6 ( V_11 , V_200 ) ;
V_197 = F_6 ( V_11 , V_201 ) ;
return V_197 > V_165 ;
}
static int F_168 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( F_136 ( V_13 ) )
return F_167 ( V_11 ) ;
else
return F_165 ( V_11 ) ;
}
static unsigned long F_169 ( enum V_12 V_13 , unsigned long V_44 ,
struct V_11 * V_11 , struct V_1 * V_2 )
{
if ( F_145 ( V_13 ) ) {
if ( F_168 ( V_11 , V_13 ) )
F_163 ( V_44 , V_11 , V_2 , V_13 ) ;
return 0 ;
}
return F_150 ( V_44 , V_11 , V_2 , V_13 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) )
return V_202 ;
return F_171 ( V_2 -> V_3 ) ;
}
static void F_172 ( struct V_11 * V_11 , struct V_1 * V_2 ,
unsigned long * V_5 )
{
struct V_169 * V_170 = & V_11 -> V_170 ;
T_6 V_203 [ 2 ] ;
T_6 V_204 = 0 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_205 , V_206 ;
enum V_207 V_207 ;
unsigned long V_208 , V_164 ;
bool V_209 = false ;
unsigned long V_210 , V_211 ;
enum V_12 V_13 ;
if ( F_103 () && ! F_5 ( V_4 ) )
V_209 = true ;
if ( ! F_1 ( V_2 ) )
V_209 = true ;
if ( ! V_2 -> V_212 || ( F_4 () <= 0 ) ) {
V_207 = V_213 ;
goto V_48;
}
if ( ! F_1 ( V_2 ) && ! F_170 ( V_2 ) ) {
V_207 = V_213 ;
goto V_48;
}
if ( ! V_2 -> V_136 && F_170 ( V_2 ) ) {
V_207 = V_214 ;
goto V_48;
}
V_208 = F_6 ( V_11 , V_215 ) +
F_6 ( V_11 , V_216 ) ;
V_164 = F_6 ( V_11 , V_201 ) +
F_6 ( V_11 , V_200 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long free = F_3 ( V_4 , V_217 ) ;
if ( F_60 ( V_164 + free <= F_173 ( V_4 ) ) ) {
V_207 = V_218 ;
goto V_48;
}
}
if ( ! F_167 ( V_11 ) ) {
V_207 = V_213 ;
goto V_48;
}
V_207 = V_219 ;
V_205 = F_170 ( V_2 ) ;
V_206 = 200 - V_205 ;
F_58 ( & V_4 -> V_163 ) ;
if ( F_60 ( V_170 -> V_179 [ 0 ] > V_208 / 4 ) ) {
V_170 -> V_179 [ 0 ] /= 2 ;
V_170 -> V_173 [ 0 ] /= 2 ;
}
if ( F_60 ( V_170 -> V_179 [ 1 ] > V_164 / 4 ) ) {
V_170 -> V_179 [ 1 ] /= 2 ;
V_170 -> V_173 [ 1 ] /= 2 ;
}
V_210 = V_205 * ( V_170 -> V_179 [ 0 ] + 1 ) ;
V_210 /= V_170 -> V_173 [ 0 ] + 1 ;
V_211 = V_206 * ( V_170 -> V_179 [ 1 ] + 1 ) ;
V_211 /= V_170 -> V_173 [ 1 ] + 1 ;
F_66 ( & V_4 -> V_163 ) ;
V_203 [ 0 ] = V_210 ;
V_203 [ 1 ] = V_211 ;
V_204 = V_210 + V_211 + 1 ;
V_48:
F_174 (lru) {
int V_164 = F_136 ( V_13 ) ;
unsigned long V_16 ;
unsigned long V_160 ;
V_16 = F_6 ( V_11 , V_13 ) ;
V_160 = V_16 >> V_2 -> V_136 ;
if ( ! V_160 && V_209 )
V_160 = F_22 ( V_16 , V_47 ) ;
switch ( V_207 ) {
case V_214 :
break;
case V_219 :
V_160 = F_175 ( V_160 * V_203 [ V_164 ] , V_204 ) ;
break;
case V_213 :
case V_218 :
if ( ( V_207 == V_213 ) != V_164 )
V_160 = 0 ;
break;
default:
F_134 () ;
}
V_5 [ V_13 ] = V_160 ;
}
}
static void F_176 ( struct V_11 * V_11 , struct V_1 * V_2 )
{
unsigned long V_5 [ V_220 ] ;
unsigned long V_221 [ V_220 ] ;
unsigned long V_44 ;
enum V_12 V_13 ;
unsigned long V_114 = 0 ;
unsigned long V_222 = V_2 -> V_222 ;
struct V_223 V_224 ;
bool V_225 = false ;
F_172 ( V_11 , V_2 , V_5 ) ;
memcpy ( V_221 , V_5 , sizeof( V_5 ) ) ;
F_177 ( & V_224 ) ;
while ( V_5 [ V_216 ] || V_5 [ V_201 ] ||
V_5 [ V_200 ] ) {
unsigned long V_226 , V_227 , V_228 ;
unsigned long V_120 ;
F_174 (lru) {
if ( V_5 [ V_13 ] ) {
V_44 = F_22 ( V_5 [ V_13 ] , V_47 ) ;
V_5 [ V_13 ] -= V_44 ;
V_114 += F_169 ( V_13 , V_44 ,
V_11 , V_2 ) ;
}
}
if ( V_114 < V_222 || V_225 )
continue;
if ( F_1 ( V_2 ) && ! F_103 () )
break;
V_227 = V_5 [ V_200 ] + V_5 [ V_201 ] ;
V_226 = V_5 [ V_216 ] + V_5 [ V_215 ] ;
if ( V_227 > V_226 ) {
unsigned long V_229 = V_221 [ V_216 ] +
V_221 [ V_215 ] + 1 ;
V_13 = V_230 ;
V_228 = V_226 * 100 / V_229 ;
} else {
unsigned long V_229 = V_221 [ V_200 ] +
V_221 [ V_201 ] + 1 ;
V_13 = V_231 ;
V_228 = V_227 * 100 / V_229 ;
}
V_5 [ V_13 ] = 0 ;
V_5 [ V_13 + V_196 ] = 0 ;
V_13 = ( V_13 == V_231 ) ? V_230 : V_231 ;
V_120 = V_221 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_221 [ V_13 ] * ( 100 - V_228 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_120 ) ;
V_13 += V_196 ;
V_120 = V_221 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_221 [ V_13 ] * ( 100 - V_228 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_120 ) ;
V_225 = true ;
}
F_178 ( & V_224 ) ;
V_2 -> V_114 += V_114 ;
if ( F_165 ( V_11 ) )
F_163 ( V_47 , V_11 ,
V_2 , V_215 ) ;
F_179 ( V_2 -> V_124 ) ;
}
static bool F_180 ( struct V_1 * V_2 )
{
if ( F_181 ( V_232 ) && V_2 -> V_162 &&
( V_2 -> V_162 > V_233 ||
V_2 -> V_136 < V_137 - 2 ) )
return true ;
return false ;
}
static inline bool F_182 ( struct V_4 * V_4 ,
unsigned long V_114 ,
unsigned long V_120 ,
struct V_1 * V_2 )
{
unsigned long V_234 ;
unsigned long V_235 ;
if ( ! F_180 ( V_2 ) )
return false ;
if ( V_2 -> V_124 & V_236 ) {
if ( ! V_114 && ! V_120 )
return false ;
} else {
if ( ! V_114 )
return false ;
}
V_234 = ( 2UL << V_2 -> V_162 ) ;
V_235 = F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_235 += F_3 ( V_4 , V_9 ) ;
if ( V_2 -> V_114 < V_234 &&
V_235 > V_234 )
return true ;
switch ( F_183 ( V_4 , V_2 -> V_162 ) ) {
case V_237 :
case V_238 :
return false ;
default:
return true ;
}
}
static void F_184 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_114 , V_120 ;
do {
struct V_239 * V_240 = V_2 -> V_3 ;
struct V_241 V_242 = {
. V_4 = V_4 ,
. V_136 = V_2 -> V_136 ,
} ;
struct V_239 * V_243 ;
V_114 = V_2 -> V_114 ;
V_120 = V_2 -> V_120 ;
V_243 = F_185 ( V_240 , NULL , & V_242 ) ;
do {
struct V_11 * V_11 ;
V_11 = F_186 ( V_4 , V_243 ) ;
F_176 ( V_11 , V_2 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_114 >= V_2 -> V_222 ) {
F_187 ( V_240 , V_243 ) ;
break;
}
V_243 = F_185 ( V_240 , V_243 , & V_242 ) ;
} while ( V_243 );
F_188 ( V_2 -> V_124 , V_2 -> V_3 ,
V_2 -> V_120 - V_120 ,
V_2 -> V_114 - V_114 ) ;
} while ( F_182 ( V_4 , V_2 -> V_114 - V_114 ,
V_2 -> V_120 - V_120 , V_2 ) );
}
static inline bool F_189 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_244 , V_245 ;
bool V_246 ;
if ( V_2 -> V_162 <= V_233 )
return false ;
V_244 = F_22 ( F_190 ( V_4 ) ,
( V_4 -> V_247 + V_248 - 1 ) /
V_248 ) ;
V_245 = F_173 ( V_4 ) + V_244 + ( 2UL << V_2 -> V_162 ) ;
V_246 = F_191 ( V_4 , 0 , V_245 , 0 , 0 ) ;
if ( F_192 ( V_4 , V_2 -> V_162 ) )
return V_246 ;
if ( ! F_183 ( V_4 , V_2 -> V_162 ) )
return false ;
return V_246 ;
}
static bool F_193 ( struct V_249 * V_249 , struct V_1 * V_2 )
{
struct V_250 * V_251 ;
struct V_4 * V_4 ;
unsigned long V_252 ;
unsigned long V_253 ;
unsigned long V_29 = 0 ;
bool V_254 = false ;
struct V_255 * V_255 = V_52 -> V_255 ;
T_7 V_256 ;
struct V_26 V_257 = {
. V_124 = V_2 -> V_124 ,
} ;
enum V_258 V_259 = F_194 ( V_2 -> V_124 ) ;
V_256 = V_2 -> V_124 ;
if ( V_195 )
V_2 -> V_124 |= V_260 ;
F_195 ( V_257 . V_261 ) ;
F_196 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_197 ( V_4 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_198 ( V_4 , V_21 ) )
continue;
V_29 += F_2 ( V_4 ) ;
F_199 ( F_200 ( V_4 ) , V_257 . V_261 ) ;
if ( V_2 -> V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
if ( F_181 ( V_232 ) ) {
if ( ( F_201 ( V_251 ) <= V_259 )
&& F_189 ( V_4 , V_2 ) ) {
V_254 = true ;
continue;
}
}
V_253 = 0 ;
V_252 = F_202 ( V_4 ,
V_2 -> V_162 , V_2 -> V_124 ,
& V_253 ) ;
V_2 -> V_114 += V_252 ;
V_2 -> V_120 += V_253 ;
}
F_184 ( V_4 , V_2 ) ;
}
if ( F_1 ( V_2 ) ) {
F_29 ( & V_257 , V_2 -> V_120 , V_29 ) ;
if ( V_255 ) {
V_2 -> V_114 += V_255 -> V_262 ;
V_255 -> V_262 = 0 ;
}
}
V_2 -> V_124 = V_256 ;
return V_254 ;
}
static bool F_203 ( struct V_249 * V_249 ,
struct V_1 * V_2 )
{
struct V_250 * V_251 ;
struct V_4 * V_4 ;
F_196 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_197 ( V_4 ) )
continue;
if ( ! F_198 ( V_4 , V_21 ) )
continue;
if ( F_5 ( V_4 ) )
return false ;
}
return true ;
}
static unsigned long F_204 ( struct V_249 * V_249 ,
struct V_1 * V_2 )
{
unsigned long V_263 = 0 ;
unsigned long V_264 ;
bool V_254 ;
F_205 () ;
if ( F_1 ( V_2 ) )
F_86 ( V_265 ) ;
do {
F_206 ( V_2 -> V_124 , V_2 -> V_3 ,
V_2 -> V_136 ) ;
V_2 -> V_120 = 0 ;
V_254 = F_193 ( V_249 , V_2 ) ;
V_263 += V_2 -> V_120 ;
if ( V_2 -> V_114 >= V_2 -> V_222 )
goto V_48;
if ( V_2 -> V_136 < V_137 - 2 )
V_2 -> V_133 = 1 ;
V_264 = V_2 -> V_222 + V_2 -> V_222 / 2 ;
if ( V_263 > V_264 ) {
F_207 ( V_266 ? 0 : V_263 ,
V_267 ) ;
V_2 -> V_133 = 1 ;
}
} while ( -- V_2 -> V_136 >= 0 && ! V_254 );
V_48:
F_208 () ;
if ( V_2 -> V_114 )
return V_2 -> V_114 ;
if ( V_268 )
return 0 ;
if ( V_254 )
return 1 ;
if ( F_1 ( V_2 ) && ! F_203 ( V_249 , V_2 ) )
return 1 ;
return 0 ;
}
static bool F_209 ( T_8 * V_269 )
{
struct V_4 * V_4 ;
unsigned long V_270 = 0 ;
unsigned long V_109 = 0 ;
int V_271 ;
bool V_272 ;
for ( V_271 = 0 ; V_271 <= V_273 ; V_271 ++ ) {
V_4 = & V_269 -> V_274 [ V_271 ] ;
V_270 += F_210 ( V_4 ) ;
V_109 += F_3 ( V_4 , V_217 ) ;
}
V_272 = V_109 > V_270 / 2 ;
if ( ! V_272 && F_211 ( & V_269 -> V_275 ) ) {
V_269 -> V_276 = F_22 ( V_269 -> V_276 ,
(enum V_258 ) V_273 ) ;
F_212 ( & V_269 -> V_275 ) ;
}
return V_272 ;
}
static bool F_213 ( T_7 V_124 , struct V_249 * V_249 ,
T_9 * V_277 )
{
struct V_4 * V_4 ;
int V_278 = F_194 ( V_124 ) ;
T_8 * V_269 ;
if ( V_52 -> V_19 & V_279 )
goto V_48;
if ( F_152 ( V_52 ) )
goto V_48;
F_214 ( V_249 , V_278 , NULL , & V_4 ) ;
V_269 = V_4 -> V_186 ;
if ( F_209 ( V_269 ) )
goto V_48;
F_86 ( V_280 ) ;
if ( ! ( V_124 & V_125 ) ) {
F_215 ( V_269 -> V_281 ,
F_209 ( V_269 ) , V_176 ) ;
goto V_282;
}
F_216 ( V_4 -> V_186 -> V_281 ,
F_209 ( V_269 ) ) ;
V_282:
if ( F_152 ( V_52 ) )
return true ;
V_48:
return false ;
}
unsigned long F_217 ( struct V_249 * V_249 , int V_162 ,
T_7 V_124 , T_9 * V_277 )
{
unsigned long V_114 ;
struct V_1 V_2 = {
. V_124 = ( V_124 = F_218 ( V_124 ) ) ,
. V_133 = ! V_266 ,
. V_222 = V_47 ,
. V_122 = 1 ,
. V_212 = 1 ,
. V_162 = V_162 ,
. V_136 = V_137 ,
. V_3 = NULL ,
. V_277 = V_277 ,
} ;
if ( F_213 ( V_124 , V_249 , V_277 ) )
return 1 ;
F_219 ( V_162 ,
V_2 . V_133 ,
V_124 ) ;
V_114 = F_204 ( V_249 , & V_2 ) ;
F_220 ( V_114 ) ;
return V_114 ;
}
unsigned long F_221 ( struct V_239 * V_243 ,
T_7 V_124 , bool V_283 ,
struct V_4 * V_4 ,
unsigned long * V_120 )
{
struct V_1 V_2 = {
. V_120 = 0 ,
. V_222 = V_47 ,
. V_133 = ! V_266 ,
. V_122 = 1 ,
. V_212 = ! V_283 ,
. V_162 = 0 ,
. V_136 = 0 ,
. V_3 = V_243 ,
} ;
struct V_11 * V_11 = F_186 ( V_4 , V_243 ) ;
V_2 . V_124 = ( V_124 & V_284 ) |
( V_285 & ~ V_284 ) ;
F_222 ( V_2 . V_162 ,
V_2 . V_133 ,
V_2 . V_124 ) ;
F_176 ( V_11 , & V_2 ) ;
F_223 ( V_2 . V_114 ) ;
* V_120 = V_2 . V_120 ;
return V_2 . V_114 ;
}
unsigned long F_224 ( struct V_239 * V_243 ,
T_7 V_124 ,
bool V_283 )
{
struct V_249 * V_249 ;
unsigned long V_114 ;
int V_35 ;
struct V_1 V_2 = {
. V_133 = ! V_266 ,
. V_122 = 1 ,
. V_212 = ! V_283 ,
. V_222 = V_47 ,
. V_162 = 0 ,
. V_136 = V_137 ,
. V_3 = V_243 ,
. V_277 = NULL ,
. V_124 = ( V_124 & V_284 ) |
( V_285 & ~ V_284 ) ,
} ;
V_35 = F_225 ( V_243 ) ;
V_249 = F_226 ( V_35 ) -> V_286 ;
F_227 ( 0 ,
V_2 . V_133 ,
V_2 . V_124 ) ;
V_114 = F_204 ( V_249 , & V_2 ) ;
F_228 ( V_114 ) ;
return V_114 ;
}
static void F_229 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_239 * V_243 ;
if ( ! V_199 )
return;
V_243 = F_185 ( NULL , NULL , NULL ) ;
do {
struct V_11 * V_11 = F_186 ( V_4 , V_243 ) ;
if ( F_165 ( V_11 ) )
F_163 ( V_47 , V_11 ,
V_2 , V_215 ) ;
V_243 = F_185 ( NULL , V_243 , NULL ) ;
} while ( V_243 );
}
static bool F_230 ( struct V_4 * V_4 , int V_162 ,
unsigned long V_244 , int V_276 )
{
if ( ! F_191 ( V_4 , V_162 , F_173 ( V_4 ) +
V_244 , V_276 , 0 ) )
return false ;
if ( F_181 ( V_232 ) && V_162 &&
! F_183 ( V_4 , V_162 ) )
return false ;
return true ;
}
static bool F_231 ( T_8 * V_269 , int V_162 , int V_276 )
{
unsigned long V_247 = 0 ;
unsigned long V_287 = 0 ;
int V_271 ;
for ( V_271 = 0 ; V_271 <= V_276 ; V_271 ++ ) {
struct V_4 * V_4 = V_269 -> V_274 + V_271 ;
if ( ! F_197 ( V_4 ) )
continue;
V_247 += V_4 -> V_247 ;
if ( ! F_5 ( V_4 ) ) {
V_287 += V_4 -> V_247 ;
continue;
}
if ( F_230 ( V_4 , V_162 , 0 , V_271 ) )
V_287 += V_4 -> V_247 ;
else if ( ! V_162 )
return false ;
}
if ( V_162 )
return V_287 >= ( V_247 >> 2 ) ;
else
return true ;
}
static bool F_232 ( T_8 * V_269 , int V_162 , long V_288 ,
int V_276 )
{
if ( V_288 )
return false ;
if ( F_211 ( & V_269 -> V_281 ) ) {
F_233 ( & V_269 -> V_281 ) ;
return false ;
}
return F_231 ( V_269 , V_162 , V_276 ) ;
}
static bool F_234 ( struct V_4 * V_4 ,
int V_276 ,
struct V_1 * V_2 ,
unsigned long V_29 ,
unsigned long * V_289 )
{
int V_290 = V_2 -> V_162 ;
unsigned long V_244 ;
struct V_255 * V_255 = V_52 -> V_255 ;
struct V_26 V_257 = {
. V_124 = V_2 -> V_124 ,
} ;
bool V_291 ;
V_2 -> V_222 = F_235 ( V_47 , F_173 ( V_4 ) ) ;
if ( F_181 ( V_232 ) && V_2 -> V_162 &&
F_183 ( V_4 , V_2 -> V_162 ) !=
V_292 )
V_290 = 0 ;
V_244 = F_22 ( F_190 ( V_4 ) ,
( V_4 -> V_247 + V_248 - 1 ) /
V_248 ) ;
V_291 = ( V_195 && F_236 ( V_4 ) ) ;
if ( ! V_291 && F_230 ( V_4 , V_290 ,
V_244 , V_276 ) )
return true ;
F_184 ( V_4 , V_2 ) ;
F_195 ( V_257 . V_261 ) ;
F_199 ( F_200 ( V_4 ) , V_257 . V_261 ) ;
V_255 -> V_262 = 0 ;
F_29 ( & V_257 , V_2 -> V_120 , V_29 ) ;
V_2 -> V_114 += V_255 -> V_262 ;
* V_289 += V_2 -> V_222 ;
F_237 ( V_4 , V_182 ) ;
if ( F_5 ( V_4 ) &&
F_230 ( V_4 , V_290 , 0 , V_276 ) ) {
F_237 ( V_4 , V_183 ) ;
F_237 ( V_4 , V_184 ) ;
}
return V_2 -> V_120 >= V_2 -> V_222 ;
}
static unsigned long F_238 ( T_8 * V_269 , int V_162 ,
int * V_276 )
{
int V_271 ;
int V_293 = 0 ;
unsigned long V_252 ;
unsigned long V_253 ;
struct V_1 V_2 = {
. V_124 = V_21 ,
. V_136 = V_137 ,
. V_122 = 1 ,
. V_212 = 1 ,
. V_133 = ! V_266 ,
. V_162 = V_162 ,
. V_3 = NULL ,
} ;
F_86 ( V_294 ) ;
do {
unsigned long V_29 = 0 ;
unsigned long V_289 = 0 ;
bool V_295 = true ;
bool V_296 = ( V_162 > 0 ) ;
V_2 . V_114 = 0 ;
for ( V_271 = V_269 -> V_297 - 1 ; V_271 >= 0 ; V_271 -- ) {
struct V_4 * V_4 = V_269 -> V_274 + V_271 ;
if ( ! F_197 ( V_4 ) )
continue;
if ( V_2 . V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
F_229 ( V_4 , & V_2 ) ;
if ( V_195 && F_239 ( V_271 ) ) {
V_293 = V_271 ;
break;
}
if ( ! F_230 ( V_4 , V_162 , 0 , 0 ) ) {
V_293 = V_271 ;
break;
} else {
F_237 ( V_4 , V_183 ) ;
F_237 ( V_4 , V_184 ) ;
}
}
if ( V_271 < 0 )
goto V_48;
for ( V_271 = 0 ; V_271 <= V_293 ; V_271 ++ ) {
struct V_4 * V_4 = V_269 -> V_274 + V_271 ;
if ( ! F_197 ( V_4 ) )
continue;
V_29 += F_2 ( V_4 ) ;
if ( V_296 &&
F_240 ( V_4 , V_162 ,
F_190 ( V_4 ) ,
* V_276 , 0 ) )
V_296 = false ;
}
if ( V_2 . V_136 < V_137 - 2 )
V_2 . V_133 = 1 ;
for ( V_271 = 0 ; V_271 <= V_293 ; V_271 ++ ) {
struct V_4 * V_4 = V_269 -> V_274 + V_271 ;
if ( ! F_197 ( V_4 ) )
continue;
if ( V_2 . V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
V_2 . V_120 = 0 ;
V_253 = 0 ;
V_252 = F_202 ( V_4 ,
V_162 , V_2 . V_124 ,
& V_253 ) ;
V_2 . V_114 += V_252 ;
if ( F_234 ( V_4 , V_293 , & V_2 ,
V_29 , & V_289 ) )
V_295 = false ;
}
if ( F_211 ( & V_269 -> V_281 ) &&
F_209 ( V_269 ) )
F_233 ( & V_269 -> V_281 ) ;
if ( V_162 && V_2 . V_114 >= 2UL << V_162 )
V_162 = V_2 . V_162 = 0 ;
if ( F_241 () || F_242 () )
break;
if ( V_296 && V_2 . V_114 > V_289 )
F_243 ( V_269 , V_162 ) ;
if ( V_295 || ! V_2 . V_114 )
V_2 . V_136 -- ;
} while ( V_2 . V_136 >= 1 &&
! F_231 ( V_269 , V_162 , * V_276 ) );
V_48:
* V_276 = V_293 ;
return V_162 ;
}
static void F_244 ( T_8 * V_269 , int V_162 , int V_276 )
{
long V_288 = 0 ;
F_245 ( V_298 ) ;
if ( F_246 ( V_52 ) || F_242 () )
return;
F_247 ( & V_269 -> V_275 , & V_298 , V_299 ) ;
if ( F_232 ( V_269 , V_162 , V_288 , V_276 ) ) {
V_288 = F_248 ( V_176 / 10 ) ;
F_249 ( & V_269 -> V_275 , & V_298 ) ;
F_247 ( & V_269 -> V_275 , & V_298 , V_299 ) ;
}
if ( F_232 ( V_269 , V_162 , V_288 , V_276 ) ) {
F_250 ( V_269 -> V_187 ) ;
F_251 ( V_269 , V_300 ) ;
F_252 ( V_269 ) ;
if ( ! F_242 () )
F_253 () ;
F_251 ( V_269 , V_301 ) ;
} else {
if ( V_288 )
F_86 ( V_302 ) ;
else
F_86 ( V_303 ) ;
}
F_249 ( & V_269 -> V_275 , & V_298 ) ;
}
static int F_254 ( void * V_304 )
{
unsigned long V_162 , V_305 ;
unsigned V_306 ;
int V_276 , V_307 ;
int V_308 ;
T_8 * V_269 = ( T_8 * ) V_304 ;
struct V_309 * V_310 = V_52 ;
struct V_255 V_255 = {
. V_262 = 0 ,
} ;
const struct V_311 * V_311 = F_255 ( V_269 -> V_187 ) ;
F_256 ( V_21 ) ;
if ( ! F_257 ( V_311 ) )
F_258 ( V_310 , V_311 ) ;
V_52 -> V_255 = & V_255 ;
V_310 -> V_19 |= V_312 | V_53 | V_313 ;
F_259 () ;
V_162 = V_305 = 0 ;
V_306 = 0 ;
V_276 = V_307 = V_269 -> V_297 - 1 ;
V_308 = V_276 ;
for ( ; ; ) {
bool V_43 ;
if ( V_308 >= V_307 &&
V_306 == V_305 ) {
V_305 = V_269 -> V_314 ;
V_307 = V_269 -> V_276 ;
V_269 -> V_314 = 0 ;
V_269 -> V_276 = V_269 -> V_297 - 1 ;
}
if ( V_162 < V_305 || V_276 > V_307 ) {
V_162 = V_305 ;
V_276 = V_307 ;
} else {
F_244 ( V_269 , V_306 ,
V_308 ) ;
V_162 = V_269 -> V_314 ;
V_276 = V_269 -> V_276 ;
V_305 = V_162 ;
V_307 = V_276 ;
V_269 -> V_314 = 0 ;
V_269 -> V_276 = V_269 -> V_297 - 1 ;
}
V_43 = F_241 () ;
if ( F_242 () )
break;
if ( ! V_43 ) {
F_260 ( V_269 -> V_187 , V_162 ) ;
V_308 = V_276 ;
V_306 = F_238 ( V_269 , V_162 ,
& V_308 ) ;
}
}
V_52 -> V_255 = NULL ;
return 0 ;
}
void F_261 ( struct V_4 * V_4 , int V_162 , enum V_258 V_276 )
{
T_8 * V_269 ;
if ( ! F_197 ( V_4 ) )
return;
if ( ! F_198 ( V_4 , V_21 ) )
return;
V_269 = V_4 -> V_186 ;
if ( V_269 -> V_314 < V_162 ) {
V_269 -> V_314 = V_162 ;
V_269 -> V_276 = F_22 ( V_269 -> V_276 , V_276 ) ;
}
if ( ! F_211 ( & V_269 -> V_275 ) )
return;
if ( F_230 ( V_4 , V_162 , 0 , 0 ) )
return;
F_262 ( V_269 -> V_187 , F_159 ( V_4 ) , V_162 ) ;
F_212 ( & V_269 -> V_275 ) ;
}
unsigned long F_263 ( unsigned long V_222 )
{
struct V_255 V_255 ;
struct V_1 V_2 = {
. V_124 = V_285 ,
. V_212 = 1 ,
. V_122 = 1 ,
. V_133 = 1 ,
. V_222 = V_222 ,
. V_185 = 1 ,
. V_162 = 0 ,
. V_136 = V_137 ,
} ;
struct V_249 * V_249 = F_264 ( F_265 () , V_2 . V_124 ) ;
struct V_309 * V_304 = V_52 ;
unsigned long V_114 ;
V_304 -> V_19 |= V_312 ;
F_256 ( V_2 . V_124 ) ;
V_255 . V_262 = 0 ;
V_304 -> V_255 = & V_255 ;
V_114 = F_204 ( V_249 , & V_2 ) ;
V_304 -> V_255 = NULL ;
F_266 () ;
V_304 -> V_19 &= ~ V_312 ;
return V_114 ;
}
static int F_267 ( struct V_315 * V_316 , unsigned long V_317 ,
void * V_318 )
{
int V_35 ;
if ( V_317 == V_319 || V_317 == V_320 ) {
F_268 (nid, N_MEMORY) {
T_8 * V_269 = F_226 ( V_35 ) ;
const struct V_311 * V_321 ;
V_321 = F_255 ( V_269 -> V_187 ) ;
if ( F_269 ( V_322 , V_321 ) < V_323 )
F_258 ( V_269 -> F_254 , V_321 ) ;
}
}
return V_324 ;
}
int F_270 ( int V_35 )
{
T_8 * V_269 = F_226 ( V_35 ) ;
int V_43 = 0 ;
if ( V_269 -> F_254 )
return 0 ;
V_269 -> F_254 = F_271 ( F_254 , V_269 , L_3 , V_35 ) ;
if ( F_272 ( V_269 -> F_254 ) ) {
F_56 ( V_325 == V_326 ) ;
F_273 ( L_4 , V_35 ) ;
V_43 = F_274 ( V_269 -> F_254 ) ;
V_269 -> F_254 = NULL ;
}
return V_43 ;
}
void F_275 ( int V_35 )
{
struct V_309 * F_254 = F_226 ( V_35 ) -> F_254 ;
if ( F_254 ) {
F_276 ( F_254 ) ;
F_226 ( V_35 ) -> F_254 = NULL ;
}
}
static int T_10 F_277 ( void )
{
int V_35 ;
F_278 () ;
F_268 (nid, N_MEMORY)
F_270 ( V_35 ) ;
F_279 ( F_267 , 0 ) ;
return 0 ;
}
static inline unsigned long F_280 ( struct V_4 * V_4 )
{
unsigned long V_327 = F_3 ( V_4 , V_328 ) ;
unsigned long V_329 = F_3 ( V_4 , V_7 ) +
F_3 ( V_4 , V_6 ) ;
return ( V_329 > V_327 ) ? ( V_329 - V_327 ) : 0 ;
}
static long F_281 ( struct V_4 * V_4 )
{
long V_330 ;
long V_31 = 0 ;
if ( V_331 & V_332 )
V_330 = F_3 ( V_4 , V_333 ) ;
else
V_330 = F_280 ( V_4 ) ;
if ( ! ( V_331 & V_334 ) )
V_31 += F_3 ( V_4 , V_335 ) ;
if ( F_60 ( V_31 > V_330 ) )
V_31 = V_330 ;
return V_330 - V_31 ;
}
static int F_282 ( struct V_4 * V_4 , T_7 V_124 , unsigned int V_162 )
{
const unsigned long V_161 = 1 << V_162 ;
struct V_309 * V_304 = V_52 ;
struct V_255 V_255 ;
struct V_1 V_2 = {
. V_133 = ! ! ( V_331 & V_334 ) ,
. V_122 = ! ! ( V_331 & V_332 ) ,
. V_212 = 1 ,
. V_222 = F_235 ( V_161 , V_47 ) ,
. V_124 = ( V_124 = F_218 ( V_124 ) ) ,
. V_162 = V_162 ,
. V_136 = V_336 ,
} ;
struct V_26 V_257 = {
. V_124 = V_2 . V_124 ,
} ;
unsigned long V_337 , V_338 ;
F_25 () ;
V_304 -> V_19 |= V_312 | V_53 ;
F_256 ( V_124 ) ;
V_255 . V_262 = 0 ;
V_304 -> V_255 = & V_255 ;
if ( F_281 ( V_4 ) > V_4 -> V_339 ) {
do {
F_184 ( V_4 , & V_2 ) ;
} while ( V_2 . V_114 < V_161 && -- V_2 . V_136 >= 0 );
}
V_337 = F_3 ( V_4 , V_340 ) ;
if ( V_337 > V_4 -> V_341 ) {
F_195 ( V_257 . V_261 ) ;
F_199 ( F_200 ( V_4 ) , V_257 . V_261 ) ;
for (; ; ) {
unsigned long V_29 = F_2 ( V_4 ) ;
if ( ! F_29 ( & V_257 , V_2 . V_120 , V_29 ) )
break;
V_338 = F_3 ( V_4 ,
V_340 ) ;
if ( V_338 + V_161 <= V_337 )
break;
}
V_338 = F_3 ( V_4 , V_340 ) ;
if ( V_338 < V_337 )
V_2 . V_114 += V_337 - V_338 ;
}
V_304 -> V_255 = NULL ;
V_52 -> V_19 &= ~ ( V_312 | V_53 ) ;
F_266 () ;
return V_2 . V_114 >= V_161 ;
}
int F_283 ( struct V_4 * V_4 , T_7 V_124 , unsigned int V_162 )
{
int V_187 ;
int V_43 ;
if ( F_281 ( V_4 ) <= V_4 -> V_339 &&
F_3 ( V_4 , V_340 ) <= V_4 -> V_341 )
return V_342 ;
if ( ! F_5 ( V_4 ) )
return V_342 ;
if ( ! ( V_124 & V_343 ) || ( V_52 -> V_19 & V_312 ) )
return V_344 ;
V_187 = F_200 ( V_4 ) ;
if ( F_284 ( V_187 , V_345 ) && V_187 != F_265 () )
return V_344 ;
if ( F_285 ( V_4 , V_346 ) )
return V_344 ;
V_43 = F_282 ( V_4 , V_124 , V_162 ) ;
F_237 ( V_4 , V_346 ) ;
if ( ! V_43 )
F_86 ( V_347 ) ;
return V_43 ;
}
int F_80 ( struct V_49 * V_49 )
{
return ! F_286 ( F_42 ( V_49 ) ) && ! F_287 ( V_49 ) ;
}
void F_288 ( struct V_49 * * V_348 , int V_161 )
{
struct V_11 * V_11 ;
struct V_4 * V_4 = NULL ;
int V_349 = 0 ;
int V_350 = 0 ;
int V_271 ;
for ( V_271 = 0 ; V_271 < V_161 ; V_271 ++ ) {
struct V_49 * V_49 = V_348 [ V_271 ] ;
struct V_4 * V_351 ;
V_349 ++ ;
V_351 = F_100 ( V_49 ) ;
if ( V_351 != V_4 ) {
if ( V_4 )
F_66 ( & V_4 -> V_163 ) ;
V_4 = V_351 ;
F_58 ( & V_4 -> V_163 ) ;
}
V_11 = F_137 ( V_49 , V_4 ) ;
if ( ! F_78 ( V_49 ) || ! F_76 ( V_49 ) )
continue;
if ( F_80 ( V_49 ) ) {
enum V_12 V_13 = F_289 ( V_49 ) ;
F_77 ( F_99 ( V_49 ) , V_49 ) ;
F_79 ( V_49 ) ;
F_140 ( V_49 , V_11 , V_352 ) ;
F_144 ( V_49 , V_11 , V_13 ) ;
V_350 ++ ;
}
}
if ( V_4 ) {
F_162 ( V_84 , V_350 ) ;
F_162 ( V_353 , V_349 ) ;
F_66 ( & V_4 -> V_163 ) ;
}
}
static void F_290 ( void )
{
F_291 ( V_354
L_5
L_6
L_7 ,
V_52 -> V_355 ) ;
}
int F_292 ( struct V_356 * V_357 , int V_358 ,
void T_11 * V_359 ,
T_1 * V_360 , T_12 * V_361 )
{
F_290 () ;
F_293 ( V_357 , V_358 , V_359 , V_360 , V_361 ) ;
V_362 = 0 ;
return 0 ;
}
static T_13 F_294 ( struct V_363 * V_364 ,
struct V_365 * V_366 ,
char * V_367 )
{
F_290 () ;
return sprintf ( V_367 , L_8 ) ;
}
static T_13 F_295 ( struct V_363 * V_364 ,
struct V_365 * V_366 ,
const char * V_367 , T_1 V_368 )
{
F_290 () ;
return 1 ;
}
int F_296 ( struct V_369 * V_369 )
{
return F_297 ( & V_369 -> V_364 , & V_370 ) ;
}
void F_298 ( struct V_369 * V_369 )
{
F_299 ( & V_369 -> V_364 , & V_370 ) ;
}
