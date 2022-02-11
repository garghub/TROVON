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
return F_3 ( V_4 , V_10 ) <
F_2 ( V_4 ) * 6 ;
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
F_28 ( V_15 , V_35 , V_30 , V_5 , V_34 , V_32 ) ;
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
F_48 ( L_2 , V_57 ) ;
return V_58 ;
}
}
return V_56 ;
}
if ( V_55 -> V_59 -> V_60 == NULL )
return V_61 ;
if ( ! F_38 ( V_55 -> V_50 , V_2 ) )
return V_56 ;
if ( F_49 ( V_49 ) ) {
int V_62 ;
struct V_63 V_64 = {
. V_65 = V_66 ,
. V_67 = V_47 ,
. V_68 = 0 ,
. V_69 = V_70 ,
. V_71 = 1 ,
} ;
F_50 ( V_49 ) ;
V_62 = V_55 -> V_59 -> V_60 ( V_49 , & V_64 ) ;
if ( V_62 < 0 )
F_40 ( V_55 , V_49 , V_62 ) ;
if ( V_62 == V_72 ) {
F_51 ( V_49 ) ;
return V_61 ;
}
if ( ! F_52 ( V_49 ) ) {
F_51 ( V_49 ) ;
}
F_53 ( V_49 , F_54 ( V_49 ) ) ;
F_55 ( V_49 , V_73 ) ;
return V_74 ;
}
return V_58 ;
}
static int F_56 ( struct V_54 * V_55 , struct V_49 * V_49 ,
bool V_75 )
{
F_57 ( ! F_58 ( V_49 ) ) ;
F_57 ( V_55 != F_42 ( V_49 ) ) ;
F_59 ( & V_55 -> V_76 ) ;
if ( ! F_60 ( V_49 , 2 ) )
goto V_77;
if ( F_61 ( F_62 ( V_49 ) ) ) {
F_63 ( V_49 , 2 ) ;
goto V_77;
}
if ( F_64 ( V_49 ) ) {
T_3 V_78 = { . V_79 = F_65 (page) } ;
F_66 ( V_49 , V_78 ) ;
F_67 ( V_49 ) ;
F_68 ( & V_55 -> V_76 ) ;
F_69 ( V_78 ) ;
} else {
void (* F_70)( struct V_49 * );
void * V_80 = NULL ;
F_70 = V_55 -> V_59 -> F_70 ;
if ( V_75 && F_71 ( V_49 ) &&
! F_72 ( V_55 ) )
V_80 = F_73 ( V_55 , V_49 ) ;
F_74 ( V_49 , V_80 ) ;
F_68 ( & V_55 -> V_76 ) ;
if ( F_70 != NULL )
F_70 ( V_49 ) ;
}
return 1 ;
V_77:
F_68 ( & V_55 -> V_76 ) ;
return 0 ;
}
int F_75 ( struct V_54 * V_55 , struct V_49 * V_49 )
{
if ( F_56 ( V_55 , V_49 , false ) ) {
F_63 ( V_49 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_76 ( struct V_49 * V_49 )
{
bool V_81 ;
int V_82 = F_77 ( V_49 ) ;
F_78 ( F_79 ( V_49 ) , V_49 ) ;
V_83:
F_80 ( V_49 ) ;
if ( F_81 ( V_49 ) ) {
V_81 = false ;
F_82 ( V_49 ) ;
} else {
V_81 = true ;
F_83 ( V_49 ) ;
F_84 () ;
}
if ( V_81 && F_81 ( V_49 ) ) {
if ( ! F_85 ( V_49 ) ) {
F_86 ( V_49 ) ;
goto V_83;
}
}
if ( V_82 && ! V_81 )
F_87 ( V_84 ) ;
else if ( ! V_82 && V_81 )
F_87 ( V_85 ) ;
F_86 ( V_49 ) ;
}
static enum V_86 F_88 ( struct V_49 * V_49 ,
struct V_1 * V_2 )
{
int V_87 , V_88 ;
unsigned long V_89 ;
V_87 = F_89 ( V_49 , 1 , V_2 -> V_3 ,
& V_89 ) ;
V_88 = F_90 ( V_49 ) ;
if ( V_89 & V_90 )
return V_91 ;
if ( V_87 ) {
if ( F_91 ( V_49 ) )
return V_92 ;
F_92 ( V_49 ) ;
if ( V_88 || V_87 > 1 )
return V_92 ;
if ( V_89 & V_93 )
return V_92 ;
return V_94 ;
}
if ( V_88 && ! F_91 ( V_49 ) )
return V_95 ;
return V_91 ;
}
static void F_93 ( struct V_49 * V_49 ,
bool * V_96 , bool * V_97 )
{
struct V_54 * V_55 ;
if ( ! F_71 ( V_49 ) ) {
* V_96 = false ;
* V_97 = false ;
return;
}
* V_96 = F_62 ( V_49 ) ;
* V_97 = F_52 ( V_49 ) ;
if ( ! F_37 ( V_49 ) )
return;
V_55 = F_42 ( V_49 ) ;
if ( V_55 && V_55 -> V_59 -> V_98 )
V_55 -> V_59 -> V_98 ( V_49 , V_96 , V_97 ) ;
}
static unsigned long F_94 ( struct V_99 * V_100 ,
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
F_95 ( V_108 ) ;
F_95 ( V_109 ) ;
int V_110 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_114 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
F_25 () ;
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
F_78 ( F_99 ( V_49 ) , V_49 ) ;
F_78 ( F_100 ( V_49 ) != V_4 , V_49 ) ;
V_2 -> V_120 ++ ;
if ( F_61 ( ! F_81 ( V_49 ) ) )
goto V_121;
if ( ! V_2 -> V_122 && F_101 ( V_49 ) )
goto V_123;
if ( F_101 ( V_49 ) || F_64 ( V_49 ) )
V_2 -> V_120 ++ ;
V_117 = ( V_2 -> V_124 & V_125 ) ||
( F_64 ( V_49 ) && ( V_2 -> V_124 & V_126 ) ) ;
F_93 ( V_49 , & V_96 , & V_97 ) ;
if ( V_96 || V_97 )
V_112 ++ ;
if ( V_96 && ! V_97 )
V_111 ++ ;
V_55 = F_42 ( V_49 ) ;
if ( ( V_55 && F_39 ( V_55 -> V_50 ) ) ||
( V_97 && F_102 ( V_49 ) ) )
V_113 ++ ;
if ( F_52 ( V_49 ) ) {
if ( F_103 () &&
F_102 ( V_49 ) &&
F_104 ( V_127 , & V_4 -> V_19 ) ) {
V_116 ++ ;
goto V_123;
} else if ( F_1 ( V_2 ) ||
! F_102 ( V_49 ) || ! ( V_2 -> V_124 & V_126 ) ) {
F_50 ( V_49 ) ;
V_115 ++ ;
goto V_123;
} else {
F_105 ( V_49 ) ;
}
}
if ( ! V_107 )
V_118 = F_88 ( V_49 , V_2 ) ;
switch ( V_118 ) {
case V_92 :
goto V_128;
case V_94 :
goto V_123;
case V_91 :
case V_95 :
;
}
if ( F_106 ( V_49 ) && ! F_64 ( V_49 ) ) {
if ( ! ( V_2 -> V_124 & V_126 ) )
goto V_123;
if ( ! F_107 ( V_49 , V_100 ) )
goto V_128;
V_117 = 1 ;
V_55 = F_42 ( V_49 ) ;
}
if ( F_101 ( V_49 ) && V_55 ) {
switch ( F_108 ( V_49 , V_101 ) ) {
case V_129 :
goto V_128;
case V_130 :
goto V_123;
case V_131 :
goto V_121;
case V_132 :
;
}
}
if ( F_62 ( V_49 ) ) {
if ( F_71 ( V_49 ) &&
( ! F_103 () ||
! F_104 ( V_133 , & V_4 -> V_19 ) ) ) {
F_55 ( V_49 , V_134 ) ;
F_50 ( V_49 ) ;
goto V_123;
}
if ( V_118 == V_95 )
goto V_123;
if ( ! V_117 )
goto V_123;
if ( ! V_2 -> V_135 )
goto V_123;
switch ( F_45 ( V_49 , V_55 , V_2 ) ) {
case V_56 :
goto V_123;
case V_61 :
goto V_128;
case V_74 :
if ( F_52 ( V_49 ) )
goto V_119;
if ( F_62 ( V_49 ) )
goto V_119;
if ( ! F_98 ( V_49 ) )
goto V_119;
if ( F_62 ( V_49 ) || F_52 ( V_49 ) )
goto V_123;
V_55 = F_42 ( V_49 ) ;
case V_58 :
;
}
}
if ( F_37 ( V_49 ) ) {
if ( ! F_109 ( V_49 , V_2 -> V_124 ) )
goto V_128;
if ( ! V_55 && F_36 ( V_49 ) == 1 ) {
F_44 ( V_49 ) ;
if ( F_110 ( V_49 ) )
goto V_136;
else {
V_114 ++ ;
continue;
}
}
}
if ( ! V_55 || ! F_56 ( V_55 , V_49 , true ) )
goto V_123;
F_111 ( V_49 ) ;
V_136:
V_114 ++ ;
F_112 ( & V_49 -> V_13 , & V_109 ) ;
continue;
V_121:
if ( F_64 ( V_49 ) )
F_113 ( V_49 ) ;
F_44 ( V_49 ) ;
F_76 ( V_49 ) ;
continue;
V_128:
if ( F_64 ( V_49 ) && F_114 () )
F_113 ( V_49 ) ;
F_78 ( F_99 ( V_49 ) , V_49 ) ;
F_115 ( V_49 ) ;
V_110 ++ ;
V_123:
F_44 ( V_49 ) ;
V_119:
F_112 ( & V_49 -> V_13 , & V_108 ) ;
F_78 ( F_79 ( V_49 ) || F_77 ( V_49 ) , V_49 ) ;
}
F_116 ( & V_109 ) ;
F_117 ( & V_109 , true ) ;
F_118 ( & V_108 , V_100 ) ;
F_24 ( V_137 , V_110 ) ;
* V_102 += V_112 ;
* V_104 += V_113 ;
* V_103 += V_111 ;
* V_105 += V_115 ;
* V_106 += V_116 ;
return V_114 ;
}
unsigned long F_119 ( struct V_4 * V_4 ,
struct V_99 * V_100 )
{
struct V_1 V_2 = {
. V_124 = V_21 ,
. V_138 = V_139 ,
. V_122 = 1 ,
} ;
unsigned long V_43 , V_140 , V_141 , V_142 , V_143 , V_144 ;
struct V_49 * V_49 , * V_145 ;
F_95 ( V_146 ) ;
F_120 (page, next, page_list, lru) {
if ( F_71 ( V_49 ) && ! F_62 ( V_49 ) &&
! F_121 ( V_49 ) ) {
F_122 ( V_49 ) ;
F_123 ( & V_49 -> V_13 , & V_146 ) ;
}
}
V_43 = F_94 ( & V_146 , V_4 , & V_2 ,
V_147 | V_148 ,
& V_140 , & V_141 , & V_142 , & V_143 , & V_144 , true ) ;
F_118 ( & V_146 , V_100 ) ;
F_124 ( V_4 , V_149 , - V_43 ) ;
return V_43 ;
}
int F_125 ( struct V_49 * V_49 , T_4 V_150 )
{
int V_43 = - V_151 ;
if ( ! F_79 ( V_49 ) )
return V_43 ;
if ( F_77 ( V_49 ) && ! ( V_150 & V_152 ) )
return V_43 ;
V_43 = - V_153 ;
if ( V_150 & ( V_154 | V_155 ) ) {
if ( F_52 ( V_49 ) )
return V_43 ;
if ( F_62 ( V_49 ) ) {
struct V_54 * V_55 ;
if ( V_150 & V_154 )
return V_43 ;
V_55 = F_42 ( V_49 ) ;
if ( V_55 && ! V_55 -> V_59 -> V_156 )
return V_43 ;
}
}
if ( ( V_150 & V_157 ) && F_101 ( V_49 ) )
return V_43 ;
if ( F_126 ( F_127 ( V_49 ) ) ) {
F_128 ( V_49 ) ;
V_43 = 0 ;
}
return V_43 ;
}
static unsigned long F_129 ( unsigned long V_44 ,
struct V_11 * V_11 , struct V_99 * V_158 ,
unsigned long * V_120 , struct V_1 * V_2 ,
T_4 V_150 , enum V_12 V_13 )
{
struct V_99 * V_159 = & V_11 -> V_160 [ V_13 ] ;
unsigned long V_161 = 0 ;
unsigned long V_162 ;
for ( V_162 = 0 ; V_162 < V_44 && ! F_96 ( V_159 ) ; V_162 ++ ) {
struct V_49 * V_49 ;
int V_163 ;
V_49 = F_97 ( V_159 ) ;
F_130 ( V_49 , V_159 , V_19 ) ;
F_78 ( ! F_79 ( V_49 ) , V_49 ) ;
switch ( F_125 ( V_49 , V_150 ) ) {
case 0 :
V_163 = F_131 ( V_49 ) ;
F_132 ( V_11 , V_13 , - V_163 ) ;
F_123 ( & V_49 -> V_13 , V_158 ) ;
V_161 += V_163 ;
break;
case - V_153 :
F_123 ( & V_49 -> V_13 , V_159 ) ;
continue;
default:
F_133 () ;
}
}
* V_120 = V_162 ;
F_134 ( V_2 -> V_164 , V_44 , V_162 ,
V_161 , V_150 , F_135 ( V_13 ) ) ;
return V_161 ;
}
int F_85 ( struct V_49 * V_49 )
{
int V_43 = - V_153 ;
F_78 ( ! F_36 ( V_49 ) , V_49 ) ;
if ( F_79 ( V_49 ) ) {
struct V_4 * V_4 = F_100 ( V_49 ) ;
struct V_11 * V_11 ;
F_59 ( & V_4 -> V_165 ) ;
V_11 = F_136 ( V_49 , V_4 ) ;
if ( F_79 ( V_49 ) ) {
int V_13 = F_137 ( V_49 ) ;
F_138 ( V_49 ) ;
F_128 ( V_49 ) ;
F_139 ( V_49 , V_11 , V_13 ) ;
V_43 = 0 ;
}
F_68 ( & V_4 -> V_165 ) ;
}
return V_43 ;
}
static int F_140 ( struct V_4 * V_4 , int V_166 ,
struct V_1 * V_2 )
{
unsigned long V_167 , V_168 ;
if ( F_103 () )
return 0 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
if ( V_166 ) {
V_167 = F_3 ( V_4 , V_7 ) ;
V_168 = F_3 ( V_4 , V_149 ) ;
} else {
V_167 = F_3 ( V_4 , V_9 ) ;
V_168 = F_3 ( V_4 , V_169 ) ;
}
if ( ( V_2 -> V_124 & V_170 ) == V_170 )
V_167 >>= 3 ;
return V_168 > V_167 ;
}
static T_5 void
F_141 ( struct V_11 * V_11 , struct V_99 * V_100 )
{
struct V_171 * V_172 = & V_11 -> V_172 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_95 ( V_173 ) ;
while ( ! F_96 ( V_100 ) ) {
struct V_49 * V_49 = F_97 ( V_100 ) ;
int V_13 ;
F_78 ( F_79 ( V_49 ) , V_49 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_61 ( ! F_81 ( V_49 ) ) ) {
F_68 ( & V_4 -> V_165 ) ;
F_76 ( V_49 ) ;
F_59 ( & V_4 -> V_165 ) ;
continue;
}
V_11 = F_136 ( V_49 , V_4 ) ;
F_142 ( V_49 ) ;
V_13 = F_137 ( V_49 ) ;
F_143 ( V_49 , V_11 , V_13 ) ;
if ( F_144 ( V_13 ) ) {
int V_166 = F_135 ( V_13 ) ;
int V_174 = F_131 ( V_49 ) ;
V_172 -> V_175 [ V_166 ] += V_174 ;
}
if ( F_110 ( V_49 ) ) {
F_145 ( V_49 ) ;
F_146 ( V_49 ) ;
F_139 ( V_49 , V_11 , V_13 ) ;
if ( F_61 ( F_147 ( V_49 ) ) ) {
F_68 ( & V_4 -> V_165 ) ;
F_148 ( V_49 ) ;
( * F_149 ( V_49 ) ) ( V_49 ) ;
F_59 ( & V_4 -> V_165 ) ;
} else
F_112 ( & V_49 -> V_13 , & V_173 ) ;
}
}
F_118 ( & V_173 , V_100 ) ;
}
static int F_150 ( void )
{
return ! ( V_52 -> V_19 & V_176 ) ||
V_52 -> V_50 == NULL ||
F_39 ( V_52 -> V_50 ) ;
}
static T_5 unsigned long
F_151 ( unsigned long V_44 , struct V_11 * V_11 ,
struct V_1 * V_2 , enum V_12 V_13 )
{
F_95 ( V_100 ) ;
unsigned long V_120 ;
unsigned long V_114 = 0 ;
unsigned long V_161 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
T_4 V_177 = 0 ;
int V_166 = F_135 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
struct V_171 * V_172 = & V_11 -> V_172 ;
while ( F_61 ( F_140 ( V_4 , V_166 , V_2 ) ) ) {
F_152 ( V_178 , V_179 / 10 ) ;
if ( F_153 ( V_52 ) )
return V_47 ;
}
F_154 () ;
if ( ! V_2 -> V_122 )
V_177 |= V_157 ;
if ( ! V_2 -> V_135 )
V_177 |= V_154 ;
F_59 ( & V_4 -> V_165 ) ;
V_161 = F_129 ( V_44 , V_11 , & V_100 ,
& V_120 , V_2 , V_177 , V_13 ) ;
F_155 ( V_4 , V_14 + V_13 , - V_161 ) ;
F_155 ( V_4 , V_169 + V_166 , V_161 ) ;
if ( F_1 ( V_2 ) ) {
F_155 ( V_4 , V_10 , V_120 ) ;
if ( F_103 () )
F_156 ( V_180 , V_4 , V_120 ) ;
else
F_156 ( V_181 , V_4 , V_120 ) ;
}
F_68 ( & V_4 -> V_165 ) ;
if ( V_161 == 0 )
return 0 ;
V_114 = F_94 ( & V_100 , V_4 , V_2 , V_147 ,
& V_112 , & V_111 , & V_113 ,
& V_115 , & V_116 ,
false ) ;
F_59 ( & V_4 -> V_165 ) ;
V_172 -> V_182 [ V_166 ] += V_161 ;
if ( F_1 ( V_2 ) ) {
if ( F_103 () )
F_156 ( V_183 , V_4 ,
V_114 ) ;
else
F_156 ( V_184 , V_4 ,
V_114 ) ;
}
F_141 ( V_11 , & V_100 ) ;
F_155 ( V_4 , V_169 + V_166 , - V_161 ) ;
F_68 ( & V_4 -> V_165 ) ;
F_116 ( & V_100 ) ;
F_117 ( & V_100 , true ) ;
if ( V_115 && V_115 == V_161 )
F_157 ( V_127 , & V_4 -> V_19 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_112 && V_112 == V_113 )
F_157 ( V_185 , & V_4 -> V_19 ) ;
if ( V_111 == V_161 )
F_157 ( V_133 , & V_4 -> V_19 ) ;
if ( V_116 && F_150 () )
F_152 ( V_178 , V_179 / 10 ) ;
}
if ( ! V_2 -> V_186 && ! F_103 () &&
F_150 () )
F_158 ( V_4 , V_178 , V_179 / 10 ) ;
F_159 ( V_4 -> V_187 -> V_188 ,
F_160 ( V_4 ) ,
V_120 , V_114 ,
V_2 -> V_138 ,
F_161 ( V_166 ) ) ;
return V_114 ;
}
static void F_162 ( struct V_11 * V_11 ,
struct V_99 * V_24 ,
struct V_99 * V_173 ,
enum V_12 V_13 )
{
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_189 = 0 ;
struct V_49 * V_49 ;
int V_163 ;
while ( ! F_96 ( V_24 ) ) {
V_49 = F_97 ( V_24 ) ;
V_11 = F_136 ( V_49 , V_4 ) ;
F_78 ( F_79 ( V_49 ) , V_49 ) ;
F_142 ( V_49 ) ;
V_163 = F_131 ( V_49 ) ;
F_132 ( V_11 , V_13 , V_163 ) ;
F_123 ( & V_49 -> V_13 , & V_11 -> V_160 [ V_13 ] ) ;
V_189 += V_163 ;
if ( F_110 ( V_49 ) ) {
F_145 ( V_49 ) ;
F_146 ( V_49 ) ;
F_139 ( V_49 , V_11 , V_13 ) ;
if ( F_61 ( F_147 ( V_49 ) ) ) {
F_68 ( & V_4 -> V_165 ) ;
F_148 ( V_49 ) ;
( * F_149 ( V_49 ) ) ( V_49 ) ;
F_59 ( & V_4 -> V_165 ) ;
} else
F_112 ( & V_49 -> V_13 , V_173 ) ;
}
}
F_155 ( V_4 , V_14 + V_13 , V_189 ) ;
if ( ! F_144 ( V_13 ) )
F_163 ( V_190 , V_189 ) ;
}
static void F_164 ( unsigned long V_44 ,
struct V_11 * V_11 ,
struct V_1 * V_2 ,
enum V_12 V_13 )
{
unsigned long V_161 ;
unsigned long V_120 ;
unsigned long V_89 ;
F_95 ( V_191 ) ;
F_95 ( V_192 ) ;
F_95 ( V_193 ) ;
struct V_49 * V_49 ;
struct V_171 * V_172 = & V_11 -> V_172 ;
unsigned long V_194 = 0 ;
T_4 V_177 = 0 ;
int V_166 = F_135 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_154 () ;
if ( ! V_2 -> V_122 )
V_177 |= V_157 ;
if ( ! V_2 -> V_135 )
V_177 |= V_154 ;
F_59 ( & V_4 -> V_165 ) ;
V_161 = F_129 ( V_44 , V_11 , & V_191 ,
& V_120 , V_2 , V_177 , V_13 ) ;
if ( F_1 ( V_2 ) )
F_155 ( V_4 , V_10 , V_120 ) ;
V_172 -> V_182 [ V_166 ] += V_161 ;
F_156 ( V_195 , V_4 , V_120 ) ;
F_155 ( V_4 , V_14 + V_13 , - V_161 ) ;
F_155 ( V_4 , V_169 + V_166 , V_161 ) ;
F_68 ( & V_4 -> V_165 ) ;
while ( ! F_96 ( & V_191 ) ) {
F_25 () ;
V_49 = F_97 ( & V_191 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_61 ( ! F_81 ( V_49 ) ) ) {
F_76 ( V_49 ) ;
continue;
}
if ( F_61 ( V_196 ) ) {
if ( F_37 ( V_49 ) && F_98 ( V_49 ) ) {
if ( F_37 ( V_49 ) )
F_109 ( V_49 , 0 ) ;
F_44 ( V_49 ) ;
}
}
if ( F_89 ( V_49 , 0 , V_2 -> V_3 ,
& V_89 ) ) {
V_194 += F_131 ( V_49 ) ;
if ( ( V_89 & V_93 ) && F_71 ( V_49 ) ) {
F_112 ( & V_49 -> V_13 , & V_192 ) ;
continue;
}
}
F_122 ( V_49 ) ;
F_112 ( & V_49 -> V_13 , & V_193 ) ;
}
F_59 ( & V_4 -> V_165 ) ;
V_172 -> V_175 [ V_166 ] += V_194 ;
F_162 ( V_11 , & V_192 , & V_191 , V_13 ) ;
F_162 ( V_11 , & V_193 , & V_191 , V_13 - V_197 ) ;
F_155 ( V_4 , V_169 + V_166 , - V_161 ) ;
F_68 ( & V_4 -> V_165 ) ;
F_116 ( & V_191 ) ;
F_117 ( & V_191 , true ) ;
}
static int F_165 ( struct V_4 * V_4 )
{
unsigned long V_198 , V_167 ;
V_198 = F_3 ( V_4 , V_8 ) ;
V_167 = F_3 ( V_4 , V_9 ) ;
if ( V_167 * V_4 -> V_199 < V_198 )
return 1 ;
return 0 ;
}
static int F_166 ( struct V_11 * V_11 )
{
if ( ! V_200 )
return 0 ;
if ( ! F_7 () )
return F_167 ( V_11 ) ;
return F_165 ( F_9 ( V_11 ) ) ;
}
static inline int F_166 ( struct V_11 * V_11 )
{
return 0 ;
}
static int F_168 ( struct V_11 * V_11 )
{
unsigned long V_167 ;
unsigned long V_198 ;
V_167 = F_6 ( V_11 , V_201 ) ;
V_198 = F_6 ( V_11 , V_202 ) ;
return V_198 > V_167 ;
}
static int F_169 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( F_135 ( V_13 ) )
return F_168 ( V_11 ) ;
else
return F_166 ( V_11 ) ;
}
static unsigned long F_170 ( enum V_12 V_13 , unsigned long V_44 ,
struct V_11 * V_11 , struct V_1 * V_2 )
{
if ( F_144 ( V_13 ) ) {
if ( F_169 ( V_11 , V_13 ) )
F_164 ( V_44 , V_11 , V_2 , V_13 ) ;
return 0 ;
}
return F_151 ( V_44 , V_11 , V_2 , V_13 ) ;
}
static void F_171 ( struct V_11 * V_11 , int V_203 ,
struct V_1 * V_2 , unsigned long * V_5 )
{
struct V_171 * V_172 = & V_11 -> V_172 ;
T_6 V_204 [ 2 ] ;
T_6 V_205 = 0 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_206 , V_207 ;
enum V_208 V_208 ;
unsigned long V_209 , V_166 ;
bool V_210 = false ;
unsigned long V_211 , V_212 ;
enum V_12 V_13 ;
bool V_213 ;
int V_214 ;
if ( F_103 () && ! F_5 ( V_4 ) )
V_210 = true ;
if ( ! F_1 ( V_2 ) )
V_210 = true ;
if ( ! V_2 -> V_215 || ( F_4 () <= 0 ) ) {
V_208 = V_216 ;
goto V_48;
}
if ( ! F_1 ( V_2 ) && ! V_203 ) {
V_208 = V_216 ;
goto V_48;
}
if ( ! V_2 -> V_138 && V_203 ) {
V_208 = V_217 ;
goto V_48;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_218 ;
unsigned long V_219 ;
V_219 = F_3 ( V_4 , V_220 ) ;
V_218 = F_3 ( V_4 , V_6 ) +
F_3 ( V_4 , V_7 ) ;
if ( F_61 ( V_218 + V_219 <= F_172 ( V_4 ) ) ) {
V_208 = V_221 ;
goto V_48;
}
}
if ( ! F_168 ( V_11 ) ) {
V_208 = V_216 ;
goto V_48;
}
V_208 = V_222 ;
V_206 = V_203 ;
V_207 = 200 - V_206 ;
V_209 = F_6 ( V_11 , V_223 ) +
F_6 ( V_11 , V_224 ) ;
V_166 = F_6 ( V_11 , V_202 ) +
F_6 ( V_11 , V_201 ) ;
F_59 ( & V_4 -> V_165 ) ;
if ( F_61 ( V_172 -> V_182 [ 0 ] > V_209 / 4 ) ) {
V_172 -> V_182 [ 0 ] /= 2 ;
V_172 -> V_175 [ 0 ] /= 2 ;
}
if ( F_61 ( V_172 -> V_182 [ 1 ] > V_166 / 4 ) ) {
V_172 -> V_182 [ 1 ] /= 2 ;
V_172 -> V_175 [ 1 ] /= 2 ;
}
V_211 = V_206 * ( V_172 -> V_182 [ 0 ] + 1 ) ;
V_211 /= V_172 -> V_175 [ 0 ] + 1 ;
V_212 = V_207 * ( V_172 -> V_182 [ 1 ] + 1 ) ;
V_212 /= V_172 -> V_175 [ 1 ] + 1 ;
F_68 ( & V_4 -> V_165 ) ;
V_204 [ 0 ] = V_211 ;
V_204 [ 1 ] = V_212 ;
V_205 = V_211 + V_212 + 1 ;
V_48:
V_213 = false ;
for ( V_214 = 0 ; ! V_213 && V_214 < 2 ; V_214 ++ ) {
F_173 (lru) {
int V_166 = F_135 ( V_13 ) ;
unsigned long V_16 ;
unsigned long V_162 ;
V_16 = F_6 ( V_11 , V_13 ) ;
V_162 = V_16 >> V_2 -> V_138 ;
if ( ! V_162 && V_214 && V_210 )
V_162 = F_22 ( V_16 , V_47 ) ;
switch ( V_208 ) {
case V_217 :
break;
case V_222 :
V_162 = F_174 ( V_162 * V_204 [ V_166 ] ,
V_205 ) ;
break;
case V_216 :
case V_221 :
if ( ( V_208 == V_216 ) != V_166 )
V_162 = 0 ;
break;
default:
F_133 () ;
}
V_5 [ V_13 ] = V_162 ;
V_213 |= ! ! V_162 ;
}
}
}
static void F_175 ( struct V_11 * V_11 , int V_203 ,
struct V_1 * V_2 )
{
unsigned long V_5 [ V_225 ] ;
unsigned long V_226 [ V_225 ] ;
unsigned long V_44 ;
enum V_12 V_13 ;
unsigned long V_114 = 0 ;
unsigned long V_227 = V_2 -> V_227 ;
struct V_228 V_229 ;
bool V_230 ;
F_171 ( V_11 , V_203 , V_2 , V_5 ) ;
memcpy ( V_226 , V_5 , sizeof( V_5 ) ) ;
V_230 = ( F_1 ( V_2 ) && ! F_103 () &&
V_2 -> V_138 == V_139 ) ;
F_176 ( & V_229 ) ;
while ( V_5 [ V_224 ] || V_5 [ V_202 ] ||
V_5 [ V_201 ] ) {
unsigned long V_231 , V_232 , V_233 ;
unsigned long V_120 ;
F_173 (lru) {
if ( V_5 [ V_13 ] ) {
V_44 = F_22 ( V_5 [ V_13 ] , V_47 ) ;
V_5 [ V_13 ] -= V_44 ;
V_114 += F_170 ( V_13 , V_44 ,
V_11 , V_2 ) ;
}
}
if ( V_114 < V_227 || V_230 )
continue;
V_232 = V_5 [ V_201 ] + V_5 [ V_202 ] ;
V_231 = V_5 [ V_224 ] + V_5 [ V_223 ] ;
if ( ! V_232 || ! V_231 )
break;
if ( V_232 > V_231 ) {
unsigned long V_234 = V_226 [ V_224 ] +
V_226 [ V_223 ] + 1 ;
V_13 = V_235 ;
V_233 = V_231 * 100 / V_234 ;
} else {
unsigned long V_234 = V_226 [ V_201 ] +
V_226 [ V_202 ] + 1 ;
V_13 = V_236 ;
V_233 = V_232 * 100 / V_234 ;
}
V_5 [ V_13 ] = 0 ;
V_5 [ V_13 + V_197 ] = 0 ;
V_13 = ( V_13 == V_236 ) ? V_235 : V_236 ;
V_120 = V_226 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_226 [ V_13 ] * ( 100 - V_233 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_120 ) ;
V_13 += V_197 ;
V_120 = V_226 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_226 [ V_13 ] * ( 100 - V_233 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_120 ) ;
V_230 = true ;
}
F_177 ( & V_229 ) ;
V_2 -> V_114 += V_114 ;
if ( F_166 ( V_11 ) )
F_164 ( V_47 , V_11 ,
V_2 , V_223 ) ;
F_178 ( V_2 -> V_124 ) ;
}
static bool F_179 ( struct V_1 * V_2 )
{
if ( F_180 ( V_237 ) && V_2 -> V_164 &&
( V_2 -> V_164 > V_238 ||
V_2 -> V_138 < V_139 - 2 ) )
return true ;
return false ;
}
static inline bool F_181 ( struct V_4 * V_4 ,
unsigned long V_114 ,
unsigned long V_120 ,
struct V_1 * V_2 )
{
unsigned long V_239 ;
unsigned long V_240 ;
if ( ! F_179 ( V_2 ) )
return false ;
if ( V_2 -> V_124 & V_241 ) {
if ( ! V_114 && ! V_120 )
return false ;
} else {
if ( ! V_114 )
return false ;
}
V_239 = ( 2UL << V_2 -> V_164 ) ;
V_240 = F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_240 += F_3 ( V_4 , V_9 ) ;
if ( V_2 -> V_114 < V_239 &&
V_240 > V_239 )
return true ;
switch ( F_182 ( V_4 , V_2 -> V_164 ) ) {
case V_242 :
case V_243 :
return false ;
default:
return true ;
}
}
static bool F_183 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_114 , V_120 ;
bool V_244 = false ;
do {
struct V_245 * V_246 = V_2 -> V_3 ;
struct V_247 V_248 = {
. V_4 = V_4 ,
. V_138 = V_2 -> V_138 ,
} ;
struct V_245 * V_249 ;
V_114 = V_2 -> V_114 ;
V_120 = V_2 -> V_120 ;
V_249 = F_184 ( V_246 , NULL , & V_248 ) ;
do {
struct V_11 * V_11 ;
int V_203 ;
V_11 = F_185 ( V_4 , V_249 ) ;
V_203 = F_186 ( V_249 ) ;
F_175 ( V_11 , V_203 , V_2 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_114 >= V_2 -> V_227 ) {
F_187 ( V_246 , V_249 ) ;
break;
}
V_249 = F_184 ( V_246 , V_249 , & V_248 ) ;
} while ( V_249 );
F_188 ( V_2 -> V_124 , V_2 -> V_3 ,
V_2 -> V_120 - V_120 ,
V_2 -> V_114 - V_114 ) ;
if ( V_2 -> V_114 - V_114 )
V_244 = true ;
} while ( F_181 ( V_4 , V_2 -> V_114 - V_114 ,
V_2 -> V_120 - V_120 , V_2 ) );
return V_244 ;
}
static inline bool F_189 ( struct V_4 * V_4 , int V_164 )
{
unsigned long V_250 , V_251 ;
bool V_252 ;
V_250 = F_22 ( F_190 ( V_4 ) , F_191 (
V_4 -> V_253 , V_254 ) ) ;
V_251 = F_172 ( V_4 ) + V_250 + ( 2UL << V_164 ) ;
V_252 = F_192 ( V_4 , 0 , V_251 , 0 , 0 ) ;
if ( F_193 ( V_4 , V_164 ) )
return V_252 ;
if ( F_182 ( V_4 , V_164 ) == V_255 )
return false ;
return V_252 ;
}
static bool F_194 ( struct V_256 * V_256 , struct V_1 * V_2 )
{
struct V_257 * V_258 ;
struct V_4 * V_4 ;
unsigned long V_259 ;
unsigned long V_260 ;
unsigned long V_29 = 0 ;
struct V_261 * V_261 = V_52 -> V_261 ;
T_7 V_262 ;
struct V_26 V_263 = {
. V_124 = V_2 -> V_124 ,
} ;
enum V_264 V_265 = F_195 ( V_2 -> V_124 ) ;
bool V_244 = false ;
V_262 = V_2 -> V_124 ;
if ( V_196 )
V_2 -> V_124 |= V_266 ;
F_196 ( V_263 . V_267 ) ;
F_197 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_198 ( V_4 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_199 ( V_4 , V_21 ) )
continue;
V_29 += F_2 ( V_4 ) ;
F_200 ( F_201 ( V_4 ) , V_263 . V_267 ) ;
if ( V_2 -> V_138 != V_139 &&
! F_5 ( V_4 ) )
continue;
if ( F_180 ( V_237 ) &&
V_2 -> V_164 > V_238 &&
F_202 ( V_258 ) <= V_265 &&
F_189 ( V_4 , V_2 -> V_164 ) ) {
V_2 -> F_189 = true ;
continue;
}
V_260 = 0 ;
V_259 = F_203 ( V_4 ,
V_2 -> V_164 , V_2 -> V_124 ,
& V_260 ) ;
V_2 -> V_114 += V_259 ;
V_2 -> V_120 += V_260 ;
if ( V_259 )
V_244 = true ;
}
if ( F_183 ( V_4 , V_2 ) )
V_244 = true ;
if ( F_1 ( V_2 ) &&
! V_244 && F_5 ( V_4 ) )
V_244 = true ;
}
if ( F_1 ( V_2 ) ) {
F_29 ( & V_263 , V_2 -> V_120 , V_29 ) ;
if ( V_261 ) {
V_2 -> V_114 += V_261 -> V_268 ;
V_261 -> V_268 = 0 ;
}
}
V_2 -> V_124 = V_262 ;
return V_244 ;
}
static unsigned long F_204 ( struct V_256 * V_256 ,
struct V_1 * V_2 )
{
unsigned long V_269 = 0 ;
unsigned long V_270 ;
bool V_271 ;
F_205 () ;
if ( F_1 ( V_2 ) )
F_87 ( V_272 ) ;
do {
F_206 ( V_2 -> V_124 , V_2 -> V_3 ,
V_2 -> V_138 ) ;
V_2 -> V_120 = 0 ;
V_271 = F_194 ( V_256 , V_2 ) ;
V_269 += V_2 -> V_120 ;
if ( V_2 -> V_114 >= V_2 -> V_227 )
break;
if ( V_2 -> F_189 )
break;
if ( V_2 -> V_138 < V_139 - 2 )
V_2 -> V_135 = 1 ;
V_270 = V_2 -> V_227 + V_2 -> V_227 / 2 ;
if ( V_269 > V_270 ) {
F_207 ( V_273 ? 0 : V_269 ,
V_274 ) ;
V_2 -> V_135 = 1 ;
}
} while ( -- V_2 -> V_138 >= 0 );
F_208 () ;
if ( V_2 -> V_114 )
return V_2 -> V_114 ;
if ( V_2 -> F_189 )
return 1 ;
if ( V_271 )
return 1 ;
return 0 ;
}
static bool F_209 ( T_8 * V_275 )
{
struct V_4 * V_4 ;
unsigned long V_276 = 0 ;
unsigned long V_109 = 0 ;
int V_277 ;
bool V_278 ;
for ( V_277 = 0 ; V_277 <= V_279 ; V_277 ++ ) {
V_4 = & V_275 -> V_280 [ V_277 ] ;
if ( ! F_198 ( V_4 ) )
continue;
V_276 += F_210 ( V_4 ) ;
V_109 += F_3 ( V_4 , V_220 ) ;
}
if ( ! V_276 )
return true ;
V_278 = V_109 > V_276 / 2 ;
if ( ! V_278 && F_211 ( & V_275 -> V_281 ) ) {
V_275 -> V_282 = F_22 ( V_275 -> V_282 ,
(enum V_264 ) V_279 ) ;
F_212 ( & V_275 -> V_281 ) ;
}
return V_278 ;
}
static bool F_213 ( T_7 V_124 , struct V_256 * V_256 ,
T_9 * V_283 )
{
struct V_257 * V_258 ;
struct V_4 * V_4 ;
T_8 * V_275 = NULL ;
if ( V_52 -> V_19 & V_284 )
goto V_48;
if ( F_153 ( V_52 ) )
goto V_48;
F_197 (zone, z, zonelist,
gfp_mask, nodemask) {
if ( F_160 ( V_4 ) > V_279 )
continue;
V_275 = V_4 -> V_187 ;
if ( F_209 ( V_275 ) )
goto V_48;
break;
}
if ( ! V_275 )
goto V_48;
F_87 ( V_285 ) ;
if ( ! ( V_124 & V_125 ) ) {
F_214 ( V_275 -> V_286 ,
F_209 ( V_275 ) , V_179 ) ;
goto V_287;
}
F_215 ( V_4 -> V_187 -> V_286 ,
F_209 ( V_275 ) ) ;
V_287:
if ( F_153 ( V_52 ) )
return true ;
V_48:
return false ;
}
unsigned long F_216 ( struct V_256 * V_256 , int V_164 ,
T_7 V_124 , T_9 * V_283 )
{
unsigned long V_114 ;
struct V_1 V_2 = {
. V_227 = V_47 ,
. V_124 = ( V_124 = F_217 ( V_124 ) ) ,
. V_164 = V_164 ,
. V_283 = V_283 ,
. V_138 = V_139 ,
. V_135 = ! V_273 ,
. V_122 = 1 ,
. V_215 = 1 ,
} ;
if ( F_213 ( V_124 , V_256 , V_283 ) )
return 1 ;
F_218 ( V_164 ,
V_2 . V_135 ,
V_124 ) ;
V_114 = F_204 ( V_256 , & V_2 ) ;
F_219 ( V_114 ) ;
return V_114 ;
}
unsigned long F_220 ( struct V_245 * V_249 ,
T_7 V_124 , bool V_288 ,
struct V_4 * V_4 ,
unsigned long * V_120 )
{
struct V_1 V_2 = {
. V_227 = V_47 ,
. V_3 = V_249 ,
. V_135 = ! V_273 ,
. V_122 = 1 ,
. V_215 = ! V_288 ,
} ;
struct V_11 * V_11 = F_185 ( V_4 , V_249 ) ;
int V_203 = F_186 ( V_249 ) ;
V_2 . V_124 = ( V_124 & V_289 ) |
( V_290 & ~ V_289 ) ;
F_221 ( V_2 . V_164 ,
V_2 . V_135 ,
V_2 . V_124 ) ;
F_175 ( V_11 , V_203 , & V_2 ) ;
F_222 ( V_2 . V_114 ) ;
* V_120 = V_2 . V_120 ;
return V_2 . V_114 ;
}
unsigned long F_223 ( struct V_245 * V_249 ,
unsigned long V_163 ,
T_7 V_124 ,
bool V_215 )
{
struct V_256 * V_256 ;
unsigned long V_114 ;
int V_35 ;
struct V_1 V_2 = {
. V_227 = F_224 ( V_163 , V_47 ) ,
. V_124 = ( V_124 & V_289 ) |
( V_290 & ~ V_289 ) ,
. V_3 = V_249 ,
. V_138 = V_139 ,
. V_135 = ! V_273 ,
. V_122 = 1 ,
. V_215 = V_215 ,
} ;
V_35 = F_225 ( V_249 ) ;
V_256 = F_226 ( V_35 ) -> V_291 ;
F_227 ( 0 ,
V_2 . V_135 ,
V_2 . V_124 ) ;
V_114 = F_204 ( V_256 , & V_2 ) ;
F_228 ( V_114 ) ;
return V_114 ;
}
static void F_229 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_245 * V_249 ;
if ( ! V_200 )
return;
V_249 = F_184 ( NULL , NULL , NULL ) ;
do {
struct V_11 * V_11 = F_185 ( V_4 , V_249 ) ;
if ( F_166 ( V_11 ) )
F_164 ( V_47 , V_11 ,
V_2 , V_223 ) ;
V_249 = F_184 ( NULL , V_249 , NULL ) ;
} while ( V_249 );
}
static bool F_230 ( struct V_4 * V_4 , int V_164 ,
unsigned long V_250 , int V_282 )
{
if ( ! F_192 ( V_4 , V_164 , F_172 ( V_4 ) +
V_250 , V_282 , 0 ) )
return false ;
if ( F_180 ( V_237 ) && V_164 &&
F_182 ( V_4 , V_164 ) == V_255 )
return false ;
return true ;
}
static bool F_231 ( T_8 * V_275 , int V_164 , int V_282 )
{
unsigned long V_253 = 0 ;
unsigned long V_292 = 0 ;
int V_277 ;
for ( V_277 = 0 ; V_277 <= V_282 ; V_277 ++ ) {
struct V_4 * V_4 = V_275 -> V_280 + V_277 ;
if ( ! F_198 ( V_4 ) )
continue;
V_253 += V_4 -> V_253 ;
if ( ! F_5 ( V_4 ) ) {
V_292 += V_4 -> V_253 ;
continue;
}
if ( F_230 ( V_4 , V_164 , 0 , V_277 ) )
V_292 += V_4 -> V_253 ;
else if ( ! V_164 )
return false ;
}
if ( V_164 )
return V_292 >= ( V_253 >> 2 ) ;
else
return true ;
}
static bool F_232 ( T_8 * V_275 , int V_164 , long V_293 ,
int V_282 )
{
if ( V_293 )
return false ;
if ( F_211 ( & V_275 -> V_286 ) ) {
F_233 ( & V_275 -> V_286 ) ;
return false ;
}
return F_231 ( V_275 , V_164 , V_282 ) ;
}
static bool F_234 ( struct V_4 * V_4 ,
int V_282 ,
struct V_1 * V_2 ,
unsigned long V_29 ,
unsigned long * V_294 )
{
int V_295 = V_2 -> V_164 ;
unsigned long V_250 ;
struct V_261 * V_261 = V_52 -> V_261 ;
struct V_26 V_263 = {
. V_124 = V_2 -> V_124 ,
} ;
bool V_296 ;
V_2 -> V_227 = F_224 ( V_47 , F_172 ( V_4 ) ) ;
if ( F_180 ( V_237 ) && V_2 -> V_164 &&
F_182 ( V_4 , V_2 -> V_164 ) !=
V_255 )
V_295 = 0 ;
V_250 = F_22 ( F_190 ( V_4 ) , F_191 (
V_4 -> V_253 , V_254 ) ) ;
V_296 = ( V_196 && F_235 ( V_4 ) ) ;
if ( ! V_296 && F_230 ( V_4 , V_295 ,
V_250 , V_282 ) )
return true ;
F_183 ( V_4 , V_2 ) ;
F_196 ( V_263 . V_267 ) ;
F_200 ( F_201 ( V_4 ) , V_263 . V_267 ) ;
V_261 -> V_268 = 0 ;
F_29 ( & V_263 , V_2 -> V_120 , V_29 ) ;
V_2 -> V_114 += V_261 -> V_268 ;
* V_294 += V_2 -> V_227 ;
F_236 ( V_127 , & V_4 -> V_19 ) ;
if ( F_5 ( V_4 ) &&
F_230 ( V_4 , V_295 , 0 , V_282 ) ) {
F_236 ( V_185 , & V_4 -> V_19 ) ;
F_236 ( V_133 , & V_4 -> V_19 ) ;
}
return V_2 -> V_120 >= V_2 -> V_227 ;
}
static unsigned long F_237 ( T_8 * V_275 , int V_164 ,
int * V_282 )
{
int V_277 ;
int V_297 = 0 ;
unsigned long V_259 ;
unsigned long V_260 ;
struct V_1 V_2 = {
. V_124 = V_21 ,
. V_164 = V_164 ,
. V_138 = V_139 ,
. V_135 = ! V_273 ,
. V_122 = 1 ,
. V_215 = 1 ,
} ;
F_87 ( V_298 ) ;
do {
unsigned long V_29 = 0 ;
unsigned long V_294 = 0 ;
bool V_299 = true ;
bool V_300 = ( V_164 > 0 ) ;
V_2 . V_114 = 0 ;
for ( V_277 = V_275 -> V_301 - 1 ; V_277 >= 0 ; V_277 -- ) {
struct V_4 * V_4 = V_275 -> V_280 + V_277 ;
if ( ! F_198 ( V_4 ) )
continue;
if ( V_2 . V_138 != V_139 &&
! F_5 ( V_4 ) )
continue;
F_229 ( V_4 , & V_2 ) ;
if ( V_196 && F_238 ( V_277 ) ) {
V_297 = V_277 ;
break;
}
if ( ! F_230 ( V_4 , V_164 , 0 , 0 ) ) {
V_297 = V_277 ;
break;
} else {
F_236 ( V_185 , & V_4 -> V_19 ) ;
F_236 ( V_133 , & V_4 -> V_19 ) ;
}
}
if ( V_277 < 0 )
goto V_48;
for ( V_277 = 0 ; V_277 <= V_297 ; V_277 ++ ) {
struct V_4 * V_4 = V_275 -> V_280 + V_277 ;
if ( ! F_198 ( V_4 ) )
continue;
V_29 += F_2 ( V_4 ) ;
if ( V_300 &&
F_239 ( V_4 , V_164 ,
F_190 ( V_4 ) ,
* V_282 , 0 ) )
V_300 = false ;
}
if ( V_2 . V_138 < V_139 - 2 )
V_2 . V_135 = 1 ;
for ( V_277 = 0 ; V_277 <= V_297 ; V_277 ++ ) {
struct V_4 * V_4 = V_275 -> V_280 + V_277 ;
if ( ! F_198 ( V_4 ) )
continue;
if ( V_2 . V_138 != V_139 &&
! F_5 ( V_4 ) )
continue;
V_2 . V_120 = 0 ;
V_260 = 0 ;
V_259 = F_203 ( V_4 ,
V_164 , V_2 . V_124 ,
& V_260 ) ;
V_2 . V_114 += V_259 ;
if ( F_234 ( V_4 , V_297 , & V_2 ,
V_29 , & V_294 ) )
V_299 = false ;
}
if ( F_211 ( & V_275 -> V_286 ) &&
F_209 ( V_275 ) )
F_233 ( & V_275 -> V_286 ) ;
if ( V_164 && V_2 . V_114 >= 2UL << V_164 )
V_164 = V_2 . V_164 = 0 ;
if ( F_240 () || F_241 () )
break;
if ( V_300 && V_2 . V_114 > V_294 )
F_242 ( V_275 , V_164 ) ;
if ( V_299 || ! V_2 . V_114 )
V_2 . V_138 -- ;
} while ( V_2 . V_138 >= 1 &&
! F_231 ( V_275 , V_164 , * V_282 ) );
V_48:
* V_282 = V_297 ;
return V_164 ;
}
static void F_243 ( T_8 * V_275 , int V_164 , int V_282 )
{
long V_293 = 0 ;
F_244 ( V_302 ) ;
if ( F_245 ( V_52 ) || F_241 () )
return;
F_246 ( & V_275 -> V_281 , & V_302 , V_303 ) ;
if ( F_232 ( V_275 , V_164 , V_293 , V_282 ) ) {
V_293 = F_247 ( V_179 / 10 ) ;
F_248 ( & V_275 -> V_281 , & V_302 ) ;
F_246 ( & V_275 -> V_281 , & V_302 , V_303 ) ;
}
if ( F_232 ( V_275 , V_164 , V_293 , V_282 ) ) {
F_249 ( V_275 -> V_188 ) ;
F_250 ( V_275 , V_304 ) ;
F_251 ( V_275 ) ;
if ( ! F_241 () )
F_252 () ;
F_250 ( V_275 , V_305 ) ;
} else {
if ( V_293 )
F_87 ( V_306 ) ;
else
F_87 ( V_307 ) ;
}
F_248 ( & V_275 -> V_281 , & V_302 ) ;
}
static int F_253 ( void * V_308 )
{
unsigned long V_164 , V_309 ;
unsigned V_310 ;
int V_282 , V_311 ;
int V_312 ;
T_8 * V_275 = ( T_8 * ) V_308 ;
struct V_313 * V_314 = V_52 ;
struct V_261 V_261 = {
. V_268 = 0 ,
} ;
const struct V_315 * V_315 = F_254 ( V_275 -> V_188 ) ;
F_255 ( V_21 ) ;
if ( ! F_256 ( V_315 ) )
F_257 ( V_314 , V_315 ) ;
V_52 -> V_261 = & V_261 ;
V_314 -> V_19 |= V_316 | V_53 | V_317 ;
F_258 () ;
V_164 = V_309 = 0 ;
V_310 = 0 ;
V_282 = V_311 = V_275 -> V_301 - 1 ;
V_312 = V_282 ;
for ( ; ; ) {
bool V_43 ;
if ( V_312 >= V_311 &&
V_310 == V_309 ) {
V_309 = V_275 -> V_318 ;
V_311 = V_275 -> V_282 ;
V_275 -> V_318 = 0 ;
V_275 -> V_282 = V_275 -> V_301 - 1 ;
}
if ( V_164 < V_309 || V_282 > V_311 ) {
V_164 = V_309 ;
V_282 = V_311 ;
} else {
F_243 ( V_275 , V_310 ,
V_312 ) ;
V_164 = V_275 -> V_318 ;
V_282 = V_275 -> V_282 ;
V_309 = V_164 ;
V_311 = V_282 ;
V_275 -> V_318 = 0 ;
V_275 -> V_282 = V_275 -> V_301 - 1 ;
}
V_43 = F_240 () ;
if ( F_241 () )
break;
if ( ! V_43 ) {
F_259 ( V_275 -> V_188 , V_164 ) ;
V_312 = V_282 ;
V_310 = F_237 ( V_275 , V_164 ,
& V_312 ) ;
}
}
V_314 -> V_19 &= ~ ( V_316 | V_53 | V_317 ) ;
V_52 -> V_261 = NULL ;
F_260 () ;
return 0 ;
}
void F_261 ( struct V_4 * V_4 , int V_164 , enum V_264 V_282 )
{
T_8 * V_275 ;
if ( ! F_198 ( V_4 ) )
return;
if ( ! F_199 ( V_4 , V_21 ) )
return;
V_275 = V_4 -> V_187 ;
if ( V_275 -> V_318 < V_164 ) {
V_275 -> V_318 = V_164 ;
V_275 -> V_282 = F_22 ( V_275 -> V_282 , V_282 ) ;
}
if ( ! F_211 ( & V_275 -> V_281 ) )
return;
if ( F_230 ( V_4 , V_164 , 0 , 0 ) )
return;
F_262 ( V_275 -> V_188 , F_160 ( V_4 ) , V_164 ) ;
F_212 ( & V_275 -> V_281 ) ;
}
unsigned long F_263 ( unsigned long V_227 )
{
struct V_261 V_261 ;
struct V_1 V_2 = {
. V_227 = V_227 ,
. V_124 = V_290 ,
. V_138 = V_139 ,
. V_135 = 1 ,
. V_122 = 1 ,
. V_215 = 1 ,
. V_186 = 1 ,
} ;
struct V_256 * V_256 = F_264 ( F_265 () , V_2 . V_124 ) ;
struct V_313 * V_308 = V_52 ;
unsigned long V_114 ;
V_308 -> V_19 |= V_316 ;
F_255 ( V_2 . V_124 ) ;
V_261 . V_268 = 0 ;
V_308 -> V_261 = & V_261 ;
V_114 = F_204 ( V_256 , & V_2 ) ;
V_308 -> V_261 = NULL ;
F_260 () ;
V_308 -> V_19 &= ~ V_316 ;
return V_114 ;
}
static int F_266 ( struct V_319 * V_320 , unsigned long V_321 ,
void * V_322 )
{
int V_35 ;
if ( V_321 == V_323 || V_321 == V_324 ) {
F_267 (nid, N_MEMORY) {
T_8 * V_275 = F_226 ( V_35 ) ;
const struct V_315 * V_325 ;
V_325 = F_254 ( V_275 -> V_188 ) ;
if ( F_268 ( V_326 , V_325 ) < V_327 )
F_257 ( V_275 -> F_253 , V_325 ) ;
}
}
return V_328 ;
}
int F_269 ( int V_35 )
{
T_8 * V_275 = F_226 ( V_35 ) ;
int V_43 = 0 ;
if ( V_275 -> F_253 )
return 0 ;
V_275 -> F_253 = F_270 ( F_253 , V_275 , L_3 , V_35 ) ;
if ( F_271 ( V_275 -> F_253 ) ) {
F_57 ( V_329 == V_330 ) ;
F_272 ( L_4 , V_35 ) ;
V_43 = F_273 ( V_275 -> F_253 ) ;
V_275 -> F_253 = NULL ;
}
return V_43 ;
}
void F_274 ( int V_35 )
{
struct V_313 * F_253 = F_226 ( V_35 ) -> F_253 ;
if ( F_253 ) {
F_275 ( F_253 ) ;
F_226 ( V_35 ) -> F_253 = NULL ;
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
unsigned long V_331 = F_3 ( V_4 , V_332 ) ;
unsigned long V_333 = F_3 ( V_4 , V_7 ) +
F_3 ( V_4 , V_6 ) ;
return ( V_333 > V_331 ) ? ( V_333 - V_331 ) : 0 ;
}
static long F_280 ( struct V_4 * V_4 )
{
long V_334 ;
long V_31 = 0 ;
if ( V_335 & V_336 )
V_334 = F_3 ( V_4 , V_337 ) ;
else
V_334 = F_279 ( V_4 ) ;
if ( ! ( V_335 & V_338 ) )
V_31 += F_3 ( V_4 , V_339 ) ;
if ( F_61 ( V_31 > V_334 ) )
V_31 = V_334 ;
return V_334 - V_31 ;
}
static int F_281 ( struct V_4 * V_4 , T_7 V_124 , unsigned int V_164 )
{
const unsigned long V_163 = 1 << V_164 ;
struct V_313 * V_308 = V_52 ;
struct V_261 V_261 ;
struct V_1 V_2 = {
. V_227 = F_224 ( V_163 , V_47 ) ,
. V_124 = ( V_124 = F_217 ( V_124 ) ) ,
. V_164 = V_164 ,
. V_138 = V_340 ,
. V_135 = ! ! ( V_335 & V_338 ) ,
. V_122 = ! ! ( V_335 & V_336 ) ,
. V_215 = 1 ,
} ;
struct V_26 V_263 = {
. V_124 = V_2 . V_124 ,
} ;
unsigned long V_341 , V_342 ;
F_25 () ;
V_308 -> V_19 |= V_316 | V_53 ;
F_255 ( V_124 ) ;
V_261 . V_268 = 0 ;
V_308 -> V_261 = & V_261 ;
if ( F_280 ( V_4 ) > V_4 -> V_343 ) {
do {
F_183 ( V_4 , & V_2 ) ;
} while ( V_2 . V_114 < V_163 && -- V_2 . V_138 >= 0 );
}
V_341 = F_3 ( V_4 , V_344 ) ;
if ( V_341 > V_4 -> V_345 ) {
F_196 ( V_263 . V_267 ) ;
F_200 ( F_201 ( V_4 ) , V_263 . V_267 ) ;
for (; ; ) {
unsigned long V_29 = F_2 ( V_4 ) ;
if ( ! F_29 ( & V_263 , V_2 . V_120 , V_29 ) )
break;
V_342 = F_3 ( V_4 ,
V_344 ) ;
if ( V_342 + V_163 <= V_341 )
break;
}
V_342 = F_3 ( V_4 , V_344 ) ;
if ( V_342 < V_341 )
V_2 . V_114 += V_341 - V_342 ;
}
V_308 -> V_261 = NULL ;
V_52 -> V_19 &= ~ ( V_316 | V_53 ) ;
F_260 () ;
return V_2 . V_114 >= V_163 ;
}
int F_282 ( struct V_4 * V_4 , T_7 V_124 , unsigned int V_164 )
{
int V_188 ;
int V_43 ;
if ( F_280 ( V_4 ) <= V_4 -> V_343 &&
F_3 ( V_4 , V_344 ) <= V_4 -> V_345 )
return V_346 ;
if ( ! F_5 ( V_4 ) )
return V_346 ;
if ( ! ( V_124 & V_347 ) || ( V_52 -> V_19 & V_316 ) )
return V_348 ;
V_188 = F_201 ( V_4 ) ;
if ( F_283 ( V_188 , V_349 ) && V_188 != F_265 () )
return V_348 ;
if ( F_284 ( V_350 , & V_4 -> V_19 ) )
return V_348 ;
V_43 = F_281 ( V_4 , V_124 , V_164 ) ;
F_236 ( V_350 , & V_4 -> V_19 ) ;
if ( ! V_43 )
F_87 ( V_351 ) ;
return V_43 ;
}
int F_81 ( struct V_49 * V_49 )
{
return ! F_285 ( F_42 ( V_49 ) ) && ! F_286 ( V_49 ) ;
}
void F_287 ( struct V_49 * * V_352 , int V_163 )
{
struct V_11 * V_11 ;
struct V_4 * V_4 = NULL ;
int V_353 = 0 ;
int V_354 = 0 ;
int V_277 ;
for ( V_277 = 0 ; V_277 < V_163 ; V_277 ++ ) {
struct V_49 * V_49 = V_352 [ V_277 ] ;
struct V_4 * V_355 ;
V_353 ++ ;
V_355 = F_100 ( V_49 ) ;
if ( V_355 != V_4 ) {
if ( V_4 )
F_68 ( & V_4 -> V_165 ) ;
V_4 = V_355 ;
F_59 ( & V_4 -> V_165 ) ;
}
V_11 = F_136 ( V_49 , V_4 ) ;
if ( ! F_79 ( V_49 ) || ! F_77 ( V_49 ) )
continue;
if ( F_81 ( V_49 ) ) {
enum V_12 V_13 = F_288 ( V_49 ) ;
F_78 ( F_99 ( V_49 ) , V_49 ) ;
F_80 ( V_49 ) ;
F_139 ( V_49 , V_11 , V_356 ) ;
F_143 ( V_49 , V_11 , V_13 ) ;
V_354 ++ ;
}
}
if ( V_4 ) {
F_163 ( V_84 , V_354 ) ;
F_163 ( V_357 , V_353 ) ;
F_68 ( & V_4 -> V_165 ) ;
}
}
