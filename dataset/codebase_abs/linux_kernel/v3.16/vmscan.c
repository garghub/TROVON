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
F_66 ( V_49 ) ;
F_67 ( & V_55 -> V_76 ) ;
F_68 ( V_78 , V_49 ) ;
} else {
void (* F_69)( struct V_49 * );
void * V_80 = NULL ;
F_69 = V_55 -> V_59 -> F_69 ;
if ( V_75 && F_70 ( V_49 ) &&
! F_71 ( V_55 ) )
V_80 = F_72 ( V_55 , V_49 ) ;
F_73 ( V_49 , V_80 ) ;
F_67 ( & V_55 -> V_76 ) ;
F_74 ( V_49 ) ;
if ( F_69 != NULL )
F_69 ( V_49 ) ;
}
return 1 ;
V_77:
F_67 ( & V_55 -> V_76 ) ;
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
if ( ! F_70 ( V_49 ) ) {
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
F_96 () ;
while ( ! F_97 ( V_100 ) ) {
struct V_54 * V_55 ;
struct V_49 * V_49 ;
int V_117 ;
enum V_86 V_118 = V_95 ;
bool V_96 , V_97 ;
F_25 () ;
V_49 = F_98 ( V_100 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( ! F_99 ( V_49 ) )
goto V_119;
F_78 ( F_100 ( V_49 ) , V_49 ) ;
F_78 ( F_101 ( V_49 ) != V_4 , V_49 ) ;
V_2 -> V_120 ++ ;
if ( F_61 ( ! F_81 ( V_49 ) ) )
goto V_121;
if ( ! V_2 -> V_122 && F_102 ( V_49 ) )
goto V_123;
if ( F_102 ( V_49 ) || F_64 ( V_49 ) )
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
( V_97 && F_103 ( V_49 ) ) )
V_113 ++ ;
if ( F_52 ( V_49 ) ) {
if ( F_104 () &&
F_103 ( V_49 ) &&
F_105 ( V_4 ) ) {
V_116 ++ ;
goto V_123;
} else if ( F_1 ( V_2 ) ||
! F_103 ( V_49 ) || ! ( V_2 -> V_124 & V_126 ) ) {
F_50 ( V_49 ) ;
V_115 ++ ;
goto V_123;
} else {
F_106 ( V_49 ) ;
}
}
if ( ! V_107 )
V_118 = F_88 ( V_49 , V_2 ) ;
switch ( V_118 ) {
case V_92 :
goto V_127;
case V_94 :
goto V_123;
case V_91 :
case V_95 :
;
}
if ( F_107 ( V_49 ) && ! F_64 ( V_49 ) ) {
if ( ! ( V_2 -> V_124 & V_126 ) )
goto V_123;
if ( ! F_108 ( V_49 , V_100 ) )
goto V_127;
V_117 = 1 ;
V_55 = F_42 ( V_49 ) ;
}
if ( F_102 ( V_49 ) && V_55 ) {
switch ( F_109 ( V_49 , V_101 ) ) {
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
if ( F_62 ( V_49 ) ) {
if ( F_70 ( V_49 ) &&
( ! F_104 () ||
! F_110 ( V_4 ) ) ) {
F_55 ( V_49 , V_132 ) ;
F_50 ( V_49 ) ;
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
if ( F_52 ( V_49 ) )
goto V_119;
if ( F_62 ( V_49 ) )
goto V_119;
if ( ! F_99 ( V_49 ) )
goto V_119;
if ( F_62 ( V_49 ) || F_52 ( V_49 ) )
goto V_123;
V_55 = F_42 ( V_49 ) ;
case V_58 :
;
}
}
if ( F_37 ( V_49 ) ) {
if ( ! F_111 ( V_49 , V_2 -> V_124 ) )
goto V_127;
if ( ! V_55 && F_36 ( V_49 ) == 1 ) {
F_44 ( V_49 ) ;
if ( F_112 ( V_49 ) )
goto V_134;
else {
V_114 ++ ;
continue;
}
}
}
if ( ! V_55 || ! F_56 ( V_55 , V_49 , true ) )
goto V_123;
F_113 ( V_49 ) ;
V_134:
V_114 ++ ;
F_114 ( & V_49 -> V_13 , & V_109 ) ;
continue;
V_121:
if ( F_64 ( V_49 ) )
F_115 ( V_49 ) ;
F_44 ( V_49 ) ;
F_76 ( V_49 ) ;
continue;
V_127:
if ( F_64 ( V_49 ) && F_116 () )
F_115 ( V_49 ) ;
F_78 ( F_100 ( V_49 ) , V_49 ) ;
F_117 ( V_49 ) ;
V_110 ++ ;
V_123:
F_44 ( V_49 ) ;
V_119:
F_114 ( & V_49 -> V_13 , & V_108 ) ;
F_78 ( F_79 ( V_49 ) || F_77 ( V_49 ) , V_49 ) ;
}
F_118 ( & V_109 , true ) ;
F_119 ( & V_108 , V_100 ) ;
F_24 ( V_135 , V_110 ) ;
F_120 () ;
* V_102 += V_112 ;
* V_104 += V_113 ;
* V_103 += V_111 ;
* V_105 += V_115 ;
* V_106 += V_116 ;
return V_114 ;
}
unsigned long F_121 ( struct V_4 * V_4 ,
struct V_99 * V_100 )
{
struct V_1 V_2 = {
. V_124 = V_21 ,
. V_136 = V_137 ,
. V_122 = 1 ,
} ;
unsigned long V_43 , V_138 , V_139 , V_140 , V_141 , V_142 ;
struct V_49 * V_49 , * V_143 ;
F_95 ( V_144 ) ;
F_122 (page, next, page_list, lru) {
if ( F_70 ( V_49 ) && ! F_62 ( V_49 ) &&
! F_123 ( V_49 ) ) {
F_124 ( V_49 ) ;
F_125 ( & V_49 -> V_13 , & V_144 ) ;
}
}
V_43 = F_94 ( & V_144 , V_4 , & V_2 ,
V_145 | V_146 ,
& V_138 , & V_139 , & V_140 , & V_141 , & V_142 , true ) ;
F_119 ( & V_144 , V_100 ) ;
F_126 ( V_4 , V_147 , - V_43 ) ;
return V_43 ;
}
int F_127 ( struct V_49 * V_49 , T_4 V_148 )
{
int V_43 = - V_149 ;
if ( ! F_79 ( V_49 ) )
return V_43 ;
if ( F_77 ( V_49 ) && ! ( V_148 & V_150 ) )
return V_43 ;
V_43 = - V_151 ;
if ( V_148 & ( V_152 | V_153 ) ) {
if ( F_52 ( V_49 ) )
return V_43 ;
if ( F_62 ( V_49 ) ) {
struct V_54 * V_55 ;
if ( V_148 & V_152 )
return V_43 ;
V_55 = F_42 ( V_49 ) ;
if ( V_55 && ! V_55 -> V_59 -> V_154 )
return V_43 ;
}
}
if ( ( V_148 & V_155 ) && F_102 ( V_49 ) )
return V_43 ;
if ( F_128 ( F_129 ( V_49 ) ) ) {
F_130 ( V_49 ) ;
V_43 = 0 ;
}
return V_43 ;
}
static unsigned long F_131 ( unsigned long V_44 ,
struct V_11 * V_11 , struct V_99 * V_156 ,
unsigned long * V_120 , struct V_1 * V_2 ,
T_4 V_148 , enum V_12 V_13 )
{
struct V_99 * V_157 = & V_11 -> V_158 [ V_13 ] ;
unsigned long V_159 = 0 ;
unsigned long V_160 ;
for ( V_160 = 0 ; V_160 < V_44 && ! F_97 ( V_157 ) ; V_160 ++ ) {
struct V_49 * V_49 ;
int V_161 ;
V_49 = F_98 ( V_157 ) ;
F_132 ( V_49 , V_157 , V_19 ) ;
F_78 ( ! F_79 ( V_49 ) , V_49 ) ;
switch ( F_127 ( V_49 , V_148 ) ) {
case 0 :
V_161 = F_133 ( V_49 ) ;
F_134 ( V_11 , V_13 , - V_161 ) ;
F_125 ( & V_49 -> V_13 , V_156 ) ;
V_159 += V_161 ;
break;
case - V_151 :
F_125 ( & V_49 -> V_13 , V_157 ) ;
continue;
default:
F_135 () ;
}
}
* V_120 = V_160 ;
F_136 ( V_2 -> V_162 , V_44 , V_160 ,
V_159 , V_148 , F_137 ( V_13 ) ) ;
return V_159 ;
}
int F_85 ( struct V_49 * V_49 )
{
int V_43 = - V_151 ;
F_78 ( ! F_36 ( V_49 ) , V_49 ) ;
if ( F_79 ( V_49 ) ) {
struct V_4 * V_4 = F_101 ( V_49 ) ;
struct V_11 * V_11 ;
F_59 ( & V_4 -> V_163 ) ;
V_11 = F_138 ( V_49 , V_4 ) ;
if ( F_79 ( V_49 ) ) {
int V_13 = F_139 ( V_49 ) ;
F_140 ( V_49 ) ;
F_130 ( V_49 ) ;
F_141 ( V_49 , V_11 , V_13 ) ;
V_43 = 0 ;
}
F_67 ( & V_4 -> V_163 ) ;
}
return V_43 ;
}
static int F_142 ( struct V_4 * V_4 , int V_164 ,
struct V_1 * V_2 )
{
unsigned long V_165 , V_166 ;
if ( F_104 () )
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
F_143 ( struct V_11 * V_11 , struct V_99 * V_100 )
{
struct V_169 * V_170 = & V_11 -> V_170 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_95 ( V_171 ) ;
while ( ! F_97 ( V_100 ) ) {
struct V_49 * V_49 = F_98 ( V_100 ) ;
int V_13 ;
F_78 ( F_79 ( V_49 ) , V_49 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_61 ( ! F_81 ( V_49 ) ) ) {
F_67 ( & V_4 -> V_163 ) ;
F_76 ( V_49 ) ;
F_59 ( & V_4 -> V_163 ) ;
continue;
}
V_11 = F_138 ( V_49 , V_4 ) ;
F_144 ( V_49 ) ;
V_13 = F_139 ( V_49 ) ;
F_145 ( V_49 , V_11 , V_13 ) ;
if ( F_146 ( V_13 ) ) {
int V_164 = F_137 ( V_13 ) ;
int V_172 = F_133 ( V_49 ) ;
V_170 -> V_173 [ V_164 ] += V_172 ;
}
if ( F_112 ( V_49 ) ) {
F_147 ( V_49 ) ;
F_148 ( V_49 ) ;
F_141 ( V_49 , V_11 , V_13 ) ;
if ( F_61 ( F_149 ( V_49 ) ) ) {
F_67 ( & V_4 -> V_163 ) ;
( * F_150 ( V_49 ) ) ( V_49 ) ;
F_59 ( & V_4 -> V_163 ) ;
} else
F_114 ( & V_49 -> V_13 , & V_171 ) ;
}
}
F_119 ( & V_171 , V_100 ) ;
}
static int F_151 ( void )
{
return ! ( V_52 -> V_19 & V_174 ) ||
V_52 -> V_50 == NULL ||
F_39 ( V_52 -> V_50 ) ;
}
static T_5 unsigned long
F_152 ( unsigned long V_44 , struct V_11 * V_11 ,
struct V_1 * V_2 , enum V_12 V_13 )
{
F_95 ( V_100 ) ;
unsigned long V_120 ;
unsigned long V_114 = 0 ;
unsigned long V_159 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
T_4 V_175 = 0 ;
int V_164 = F_137 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
struct V_169 * V_170 = & V_11 -> V_170 ;
while ( F_61 ( F_142 ( V_4 , V_164 , V_2 ) ) ) {
F_153 ( V_176 , V_177 / 10 ) ;
if ( F_154 ( V_52 ) )
return V_47 ;
}
F_155 () ;
if ( ! V_2 -> V_122 )
V_175 |= V_155 ;
if ( ! V_2 -> V_133 )
V_175 |= V_152 ;
F_59 ( & V_4 -> V_163 ) ;
V_159 = F_131 ( V_44 , V_11 , & V_100 ,
& V_120 , V_2 , V_175 , V_13 ) ;
F_156 ( V_4 , V_14 + V_13 , - V_159 ) ;
F_156 ( V_4 , V_167 + V_164 , V_159 ) ;
if ( F_1 ( V_2 ) ) {
V_4 -> V_10 += V_120 ;
if ( F_104 () )
F_157 ( V_178 , V_4 , V_120 ) ;
else
F_157 ( V_179 , V_4 , V_120 ) ;
}
F_67 ( & V_4 -> V_163 ) ;
if ( V_159 == 0 )
return 0 ;
V_114 = F_94 ( & V_100 , V_4 , V_2 , V_145 ,
& V_112 , & V_111 , & V_113 ,
& V_115 , & V_116 ,
false ) ;
F_59 ( & V_4 -> V_163 ) ;
V_170 -> V_180 [ V_164 ] += V_159 ;
if ( F_1 ( V_2 ) ) {
if ( F_104 () )
F_157 ( V_181 , V_4 ,
V_114 ) ;
else
F_157 ( V_182 , V_4 ,
V_114 ) ;
}
F_143 ( V_11 , & V_100 ) ;
F_156 ( V_4 , V_167 + V_164 , - V_159 ) ;
F_67 ( & V_4 -> V_163 ) ;
F_118 ( & V_100 , true ) ;
if ( V_115 && V_115 == V_159 )
F_158 ( V_4 , V_183 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_112 && V_112 == V_113 )
F_158 ( V_4 , V_184 ) ;
if ( V_111 == V_159 )
F_158 ( V_4 , V_185 ) ;
if ( V_116 && F_151 () )
F_153 ( V_176 , V_177 / 10 ) ;
}
if ( ! V_2 -> V_186 && ! F_104 () &&
F_151 () )
F_159 ( V_4 , V_176 , V_177 / 10 ) ;
F_160 ( V_4 -> V_187 -> V_188 ,
F_161 ( V_4 ) ,
V_120 , V_114 ,
V_2 -> V_136 ,
F_162 ( V_164 ) ) ;
return V_114 ;
}
static void F_163 ( struct V_11 * V_11 ,
struct V_99 * V_24 ,
struct V_99 * V_171 ,
enum V_12 V_13 )
{
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_189 = 0 ;
struct V_49 * V_49 ;
int V_161 ;
while ( ! F_97 ( V_24 ) ) {
V_49 = F_98 ( V_24 ) ;
V_11 = F_138 ( V_49 , V_4 ) ;
F_78 ( F_79 ( V_49 ) , V_49 ) ;
F_144 ( V_49 ) ;
V_161 = F_133 ( V_49 ) ;
F_134 ( V_11 , V_13 , V_161 ) ;
F_125 ( & V_49 -> V_13 , & V_11 -> V_158 [ V_13 ] ) ;
V_189 += V_161 ;
if ( F_112 ( V_49 ) ) {
F_147 ( V_49 ) ;
F_148 ( V_49 ) ;
F_141 ( V_49 , V_11 , V_13 ) ;
if ( F_61 ( F_149 ( V_49 ) ) ) {
F_67 ( & V_4 -> V_163 ) ;
( * F_150 ( V_49 ) ) ( V_49 ) ;
F_59 ( & V_4 -> V_163 ) ;
} else
F_114 ( & V_49 -> V_13 , V_171 ) ;
}
}
F_156 ( V_4 , V_14 + V_13 , V_189 ) ;
if ( ! F_146 ( V_13 ) )
F_164 ( V_190 , V_189 ) ;
}
static void F_165 ( unsigned long V_44 ,
struct V_11 * V_11 ,
struct V_1 * V_2 ,
enum V_12 V_13 )
{
unsigned long V_159 ;
unsigned long V_120 ;
unsigned long V_89 ;
F_95 ( V_191 ) ;
F_95 ( V_192 ) ;
F_95 ( V_193 ) ;
struct V_49 * V_49 ;
struct V_169 * V_170 = & V_11 -> V_170 ;
unsigned long V_194 = 0 ;
T_4 V_175 = 0 ;
int V_164 = F_137 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_155 () ;
if ( ! V_2 -> V_122 )
V_175 |= V_155 ;
if ( ! V_2 -> V_133 )
V_175 |= V_152 ;
F_59 ( & V_4 -> V_163 ) ;
V_159 = F_131 ( V_44 , V_11 , & V_191 ,
& V_120 , V_2 , V_175 , V_13 ) ;
if ( F_1 ( V_2 ) )
V_4 -> V_10 += V_120 ;
V_170 -> V_180 [ V_164 ] += V_159 ;
F_157 ( V_195 , V_4 , V_120 ) ;
F_156 ( V_4 , V_14 + V_13 , - V_159 ) ;
F_156 ( V_4 , V_167 + V_164 , V_159 ) ;
F_67 ( & V_4 -> V_163 ) ;
while ( ! F_97 ( & V_191 ) ) {
F_25 () ;
V_49 = F_98 ( & V_191 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_61 ( ! F_81 ( V_49 ) ) ) {
F_76 ( V_49 ) ;
continue;
}
if ( F_61 ( V_196 ) ) {
if ( F_37 ( V_49 ) && F_99 ( V_49 ) ) {
if ( F_37 ( V_49 ) )
F_111 ( V_49 , 0 ) ;
F_44 ( V_49 ) ;
}
}
if ( F_89 ( V_49 , 0 , V_2 -> V_3 ,
& V_89 ) ) {
V_194 += F_133 ( V_49 ) ;
if ( ( V_89 & V_93 ) && F_70 ( V_49 ) ) {
F_114 ( & V_49 -> V_13 , & V_192 ) ;
continue;
}
}
F_124 ( V_49 ) ;
F_114 ( & V_49 -> V_13 , & V_193 ) ;
}
F_59 ( & V_4 -> V_163 ) ;
V_170 -> V_173 [ V_164 ] += V_194 ;
F_163 ( V_11 , & V_192 , & V_191 , V_13 ) ;
F_163 ( V_11 , & V_193 , & V_191 , V_13 - V_197 ) ;
F_156 ( V_4 , V_167 + V_164 , - V_159 ) ;
F_67 ( & V_4 -> V_163 ) ;
F_118 ( & V_191 , true ) ;
}
static int F_166 ( struct V_4 * V_4 )
{
unsigned long V_198 , V_165 ;
V_198 = F_3 ( V_4 , V_8 ) ;
V_165 = F_3 ( V_4 , V_9 ) ;
if ( V_165 * V_4 -> V_199 < V_198 )
return 1 ;
return 0 ;
}
static int F_167 ( struct V_11 * V_11 )
{
if ( ! V_200 )
return 0 ;
if ( ! F_7 () )
return F_168 ( V_11 ) ;
return F_166 ( F_9 ( V_11 ) ) ;
}
static inline int F_167 ( struct V_11 * V_11 )
{
return 0 ;
}
static int F_169 ( struct V_11 * V_11 )
{
unsigned long V_165 ;
unsigned long V_198 ;
V_165 = F_6 ( V_11 , V_201 ) ;
V_198 = F_6 ( V_11 , V_202 ) ;
return V_198 > V_165 ;
}
static int F_170 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( F_137 ( V_13 ) )
return F_169 ( V_11 ) ;
else
return F_167 ( V_11 ) ;
}
static unsigned long F_171 ( enum V_12 V_13 , unsigned long V_44 ,
struct V_11 * V_11 , struct V_1 * V_2 )
{
if ( F_146 ( V_13 ) ) {
if ( F_170 ( V_11 , V_13 ) )
F_165 ( V_44 , V_11 , V_2 , V_13 ) ;
return 0 ;
}
return F_152 ( V_44 , V_11 , V_2 , V_13 ) ;
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
bool V_212 ;
int V_213 ;
if ( F_104 () && ! F_5 ( V_4 ) )
V_209 = true ;
if ( ! F_1 ( V_2 ) )
V_209 = true ;
if ( ! V_2 -> V_214 || ( F_4 () <= 0 ) ) {
V_207 = V_215 ;
goto V_48;
}
if ( ! F_1 ( V_2 ) && ! V_2 -> V_216 ) {
V_207 = V_215 ;
goto V_48;
}
if ( ! V_2 -> V_136 && V_2 -> V_216 ) {
V_207 = V_217 ;
goto V_48;
}
V_208 = F_6 ( V_11 , V_218 ) +
F_6 ( V_11 , V_219 ) ;
V_164 = F_6 ( V_11 , V_202 ) +
F_6 ( V_11 , V_201 ) ;
if ( F_1 ( V_2 ) ) {
unsigned long free = F_3 ( V_4 , V_220 ) ;
if ( F_61 ( V_164 + free <= F_173 ( V_4 ) ) ) {
V_207 = V_221 ;
goto V_48;
}
}
if ( ! F_169 ( V_11 ) ) {
V_207 = V_215 ;
goto V_48;
}
V_207 = V_222 ;
V_205 = V_2 -> V_216 ;
V_206 = 200 - V_205 ;
F_59 ( & V_4 -> V_163 ) ;
if ( F_61 ( V_170 -> V_180 [ 0 ] > V_208 / 4 ) ) {
V_170 -> V_180 [ 0 ] /= 2 ;
V_170 -> V_173 [ 0 ] /= 2 ;
}
if ( F_61 ( V_170 -> V_180 [ 1 ] > V_164 / 4 ) ) {
V_170 -> V_180 [ 1 ] /= 2 ;
V_170 -> V_173 [ 1 ] /= 2 ;
}
V_210 = V_205 * ( V_170 -> V_180 [ 0 ] + 1 ) ;
V_210 /= V_170 -> V_173 [ 0 ] + 1 ;
V_211 = V_206 * ( V_170 -> V_180 [ 1 ] + 1 ) ;
V_211 /= V_170 -> V_173 [ 1 ] + 1 ;
F_67 ( & V_4 -> V_163 ) ;
V_203 [ 0 ] = V_210 ;
V_203 [ 1 ] = V_211 ;
V_204 = V_210 + V_211 + 1 ;
V_48:
V_212 = false ;
for ( V_213 = 0 ; ! V_212 && V_213 < 2 ; V_213 ++ ) {
F_174 (lru) {
int V_164 = F_137 ( V_13 ) ;
unsigned long V_16 ;
unsigned long V_160 ;
V_16 = F_6 ( V_11 , V_13 ) ;
V_160 = V_16 >> V_2 -> V_136 ;
if ( ! V_160 && V_213 && V_209 )
V_160 = F_22 ( V_16 , V_47 ) ;
switch ( V_207 ) {
case V_217 :
break;
case V_222 :
V_160 = F_175 ( V_160 * V_203 [ V_164 ] ,
V_204 ) ;
break;
case V_215 :
case V_221 :
if ( ( V_207 == V_215 ) != V_164 )
V_160 = 0 ;
break;
default:
F_135 () ;
}
V_5 [ V_13 ] = V_160 ;
V_212 |= ! ! V_160 ;
}
}
}
static void F_176 ( struct V_11 * V_11 , struct V_1 * V_2 )
{
unsigned long V_5 [ V_223 ] ;
unsigned long V_224 [ V_223 ] ;
unsigned long V_44 ;
enum V_12 V_13 ;
unsigned long V_114 = 0 ;
unsigned long V_225 = V_2 -> V_225 ;
struct V_226 V_227 ;
bool V_228 ;
F_172 ( V_11 , V_2 , V_5 ) ;
memcpy ( V_224 , V_5 , sizeof( V_5 ) ) ;
V_228 = ( F_1 ( V_2 ) && ! F_104 () &&
V_2 -> V_136 == V_137 ) ;
F_177 ( & V_227 ) ;
while ( V_5 [ V_219 ] || V_5 [ V_202 ] ||
V_5 [ V_201 ] ) {
unsigned long V_229 , V_230 , V_231 ;
unsigned long V_120 ;
F_174 (lru) {
if ( V_5 [ V_13 ] ) {
V_44 = F_22 ( V_5 [ V_13 ] , V_47 ) ;
V_5 [ V_13 ] -= V_44 ;
V_114 += F_171 ( V_13 , V_44 ,
V_11 , V_2 ) ;
}
}
if ( V_114 < V_225 || V_228 )
continue;
V_230 = V_5 [ V_201 ] + V_5 [ V_202 ] ;
V_229 = V_5 [ V_219 ] + V_5 [ V_218 ] ;
if ( ! V_230 || ! V_229 )
break;
if ( V_230 > V_229 ) {
unsigned long V_232 = V_224 [ V_219 ] +
V_224 [ V_218 ] + 1 ;
V_13 = V_233 ;
V_231 = V_229 * 100 / V_232 ;
} else {
unsigned long V_232 = V_224 [ V_201 ] +
V_224 [ V_202 ] + 1 ;
V_13 = V_234 ;
V_231 = V_230 * 100 / V_232 ;
}
V_5 [ V_13 ] = 0 ;
V_5 [ V_13 + V_197 ] = 0 ;
V_13 = ( V_13 == V_234 ) ? V_233 : V_234 ;
V_120 = V_224 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_224 [ V_13 ] * ( 100 - V_231 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_120 ) ;
V_13 += V_197 ;
V_120 = V_224 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_224 [ V_13 ] * ( 100 - V_231 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_120 ) ;
V_228 = true ;
}
F_178 ( & V_227 ) ;
V_2 -> V_114 += V_114 ;
if ( F_167 ( V_11 ) )
F_165 ( V_47 , V_11 ,
V_2 , V_218 ) ;
F_179 ( V_2 -> V_124 ) ;
}
static bool F_180 ( struct V_1 * V_2 )
{
if ( F_181 ( V_235 ) && V_2 -> V_162 &&
( V_2 -> V_162 > V_236 ||
V_2 -> V_136 < V_137 - 2 ) )
return true ;
return false ;
}
static inline bool F_182 ( struct V_4 * V_4 ,
unsigned long V_114 ,
unsigned long V_120 ,
struct V_1 * V_2 )
{
unsigned long V_237 ;
unsigned long V_238 ;
if ( ! F_180 ( V_2 ) )
return false ;
if ( V_2 -> V_124 & V_239 ) {
if ( ! V_114 && ! V_120 )
return false ;
} else {
if ( ! V_114 )
return false ;
}
V_237 = ( 2UL << V_2 -> V_162 ) ;
V_238 = F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_238 += F_3 ( V_4 , V_9 ) ;
if ( V_2 -> V_114 < V_237 &&
V_238 > V_237 )
return true ;
switch ( F_183 ( V_4 , V_2 -> V_162 ) ) {
case V_240 :
case V_241 :
return false ;
default:
return true ;
}
}
static void F_184 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_114 , V_120 ;
do {
struct V_242 * V_243 = V_2 -> V_3 ;
struct V_244 V_245 = {
. V_4 = V_4 ,
. V_136 = V_2 -> V_136 ,
} ;
struct V_242 * V_246 ;
V_114 = V_2 -> V_114 ;
V_120 = V_2 -> V_120 ;
V_246 = F_185 ( V_243 , NULL , & V_245 ) ;
do {
struct V_11 * V_11 ;
V_11 = F_186 ( V_4 , V_246 ) ;
V_2 -> V_216 = F_187 ( V_246 ) ;
F_176 ( V_11 , V_2 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_114 >= V_2 -> V_225 ) {
F_188 ( V_243 , V_246 ) ;
break;
}
V_246 = F_185 ( V_243 , V_246 , & V_245 ) ;
} while ( V_246 );
F_189 ( V_2 -> V_124 , V_2 -> V_3 ,
V_2 -> V_120 - V_120 ,
V_2 -> V_114 - V_114 ) ;
} while ( F_182 ( V_4 , V_2 -> V_114 - V_114 ,
V_2 -> V_120 - V_120 , V_2 ) );
}
static inline bool F_190 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
unsigned long V_247 , V_248 ;
bool V_249 ;
if ( V_2 -> V_162 <= V_236 )
return false ;
V_247 = F_22 ( F_191 ( V_4 ) , F_192 (
V_4 -> V_250 , V_251 ) ) ;
V_248 = F_173 ( V_4 ) + V_247 + ( 2UL << V_2 -> V_162 ) ;
V_249 = F_193 ( V_4 , 0 , V_248 , 0 , 0 ) ;
if ( F_194 ( V_4 , V_2 -> V_162 ) )
return V_249 ;
if ( ! F_183 ( V_4 , V_2 -> V_162 ) )
return false ;
return V_249 ;
}
static bool F_195 ( struct V_252 * V_252 , struct V_1 * V_2 )
{
struct V_253 * V_254 ;
struct V_4 * V_4 ;
unsigned long V_255 ;
unsigned long V_256 ;
unsigned long V_29 = 0 ;
bool V_257 = false ;
struct V_258 * V_258 = V_52 -> V_258 ;
T_7 V_259 ;
struct V_26 V_260 = {
. V_124 = V_2 -> V_124 ,
} ;
enum V_261 V_262 = F_196 ( V_2 -> V_124 ) ;
V_259 = V_2 -> V_124 ;
if ( V_196 )
V_2 -> V_124 |= V_263 ;
F_197 ( V_260 . V_264 ) ;
F_198 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_199 ( V_4 ) )
continue;
if ( F_1 ( V_2 ) ) {
if ( ! F_200 ( V_4 , V_21 ) )
continue;
V_29 += F_2 ( V_4 ) ;
F_201 ( F_202 ( V_4 ) , V_260 . V_264 ) ;
if ( V_2 -> V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
if ( F_181 ( V_235 ) ) {
if ( ( F_203 ( V_254 ) <= V_262 )
&& F_190 ( V_4 , V_2 ) ) {
V_257 = true ;
continue;
}
}
V_256 = 0 ;
V_255 = F_204 ( V_4 ,
V_2 -> V_162 , V_2 -> V_124 ,
& V_256 ) ;
V_2 -> V_114 += V_255 ;
V_2 -> V_120 += V_256 ;
}
F_184 ( V_4 , V_2 ) ;
}
if ( F_1 ( V_2 ) ) {
F_29 ( & V_260 , V_2 -> V_120 , V_29 ) ;
if ( V_258 ) {
V_2 -> V_114 += V_258 -> V_265 ;
V_258 -> V_265 = 0 ;
}
}
V_2 -> V_124 = V_259 ;
return V_257 ;
}
static bool F_205 ( struct V_252 * V_252 ,
struct V_1 * V_2 )
{
struct V_253 * V_254 ;
struct V_4 * V_4 ;
F_198 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
if ( ! F_199 ( V_4 ) )
continue;
if ( ! F_200 ( V_4 , V_21 ) )
continue;
if ( F_5 ( V_4 ) )
return false ;
}
return true ;
}
static unsigned long F_206 ( struct V_252 * V_252 ,
struct V_1 * V_2 )
{
unsigned long V_266 = 0 ;
unsigned long V_267 ;
bool V_257 ;
F_207 () ;
if ( F_1 ( V_2 ) )
F_87 ( V_268 ) ;
do {
F_208 ( V_2 -> V_124 , V_2 -> V_3 ,
V_2 -> V_136 ) ;
V_2 -> V_120 = 0 ;
V_257 = F_195 ( V_252 , V_2 ) ;
V_266 += V_2 -> V_120 ;
if ( V_2 -> V_114 >= V_2 -> V_225 )
goto V_48;
if ( V_2 -> V_136 < V_137 - 2 )
V_2 -> V_133 = 1 ;
V_267 = V_2 -> V_225 + V_2 -> V_225 / 2 ;
if ( V_266 > V_267 ) {
F_209 ( V_269 ? 0 : V_266 ,
V_270 ) ;
V_2 -> V_133 = 1 ;
}
} while ( -- V_2 -> V_136 >= 0 && ! V_257 );
V_48:
F_210 () ;
if ( V_2 -> V_114 )
return V_2 -> V_114 ;
if ( V_271 )
return 0 ;
if ( V_257 )
return 1 ;
if ( F_1 ( V_2 ) && ! F_205 ( V_252 , V_2 ) )
return 1 ;
return 0 ;
}
static bool F_211 ( T_8 * V_272 )
{
struct V_4 * V_4 ;
unsigned long V_273 = 0 ;
unsigned long V_109 = 0 ;
int V_274 ;
bool V_275 ;
for ( V_274 = 0 ; V_274 <= V_276 ; V_274 ++ ) {
V_4 = & V_272 -> V_277 [ V_274 ] ;
if ( ! F_199 ( V_4 ) )
continue;
V_273 += F_212 ( V_4 ) ;
V_109 += F_3 ( V_4 , V_220 ) ;
}
if ( ! V_273 )
return true ;
V_275 = V_109 > V_273 / 2 ;
if ( ! V_275 && F_213 ( & V_272 -> V_278 ) ) {
V_272 -> V_279 = F_22 ( V_272 -> V_279 ,
(enum V_261 ) V_276 ) ;
F_214 ( & V_272 -> V_278 ) ;
}
return V_275 ;
}
static bool F_215 ( T_7 V_124 , struct V_252 * V_252 ,
T_9 * V_280 )
{
struct V_253 * V_254 ;
struct V_4 * V_4 ;
T_8 * V_272 = NULL ;
if ( V_52 -> V_19 & V_281 )
goto V_48;
if ( F_154 ( V_52 ) )
goto V_48;
F_198 (zone, z, zonelist,
gfp_mask, nodemask) {
if ( F_161 ( V_4 ) > V_276 )
continue;
V_272 = V_4 -> V_187 ;
if ( F_211 ( V_272 ) )
goto V_48;
break;
}
if ( ! V_272 )
goto V_48;
F_87 ( V_282 ) ;
if ( ! ( V_124 & V_125 ) ) {
F_216 ( V_272 -> V_283 ,
F_211 ( V_272 ) , V_177 ) ;
goto V_284;
}
F_217 ( V_4 -> V_187 -> V_283 ,
F_211 ( V_272 ) ) ;
V_284:
if ( F_154 ( V_52 ) )
return true ;
V_48:
return false ;
}
unsigned long F_218 ( struct V_252 * V_252 , int V_162 ,
T_7 V_124 , T_9 * V_280 )
{
unsigned long V_114 ;
struct V_1 V_2 = {
. V_124 = ( V_124 = F_219 ( V_124 ) ) ,
. V_133 = ! V_269 ,
. V_225 = V_47 ,
. V_122 = 1 ,
. V_214 = 1 ,
. V_162 = V_162 ,
. V_136 = V_137 ,
. V_3 = NULL ,
. V_280 = V_280 ,
} ;
if ( F_215 ( V_124 , V_252 , V_280 ) )
return 1 ;
F_220 ( V_162 ,
V_2 . V_133 ,
V_124 ) ;
V_114 = F_206 ( V_252 , & V_2 ) ;
F_221 ( V_114 ) ;
return V_114 ;
}
unsigned long F_222 ( struct V_242 * V_246 ,
T_7 V_124 , bool V_285 ,
struct V_4 * V_4 ,
unsigned long * V_120 )
{
struct V_1 V_2 = {
. V_120 = 0 ,
. V_225 = V_47 ,
. V_133 = ! V_269 ,
. V_122 = 1 ,
. V_214 = ! V_285 ,
. V_162 = 0 ,
. V_136 = 0 ,
. V_216 = F_187 ( V_246 ) ,
. V_3 = V_246 ,
} ;
struct V_11 * V_11 = F_186 ( V_4 , V_246 ) ;
V_2 . V_124 = ( V_124 & V_286 ) |
( V_287 & ~ V_286 ) ;
F_223 ( V_2 . V_162 ,
V_2 . V_133 ,
V_2 . V_124 ) ;
F_176 ( V_11 , & V_2 ) ;
F_224 ( V_2 . V_114 ) ;
* V_120 = V_2 . V_120 ;
return V_2 . V_114 ;
}
unsigned long F_225 ( struct V_242 * V_246 ,
T_7 V_124 ,
bool V_285 )
{
struct V_252 * V_252 ;
unsigned long V_114 ;
int V_35 ;
struct V_1 V_2 = {
. V_133 = ! V_269 ,
. V_122 = 1 ,
. V_214 = ! V_285 ,
. V_225 = V_47 ,
. V_162 = 0 ,
. V_136 = V_137 ,
. V_3 = V_246 ,
. V_280 = NULL ,
. V_124 = ( V_124 & V_286 ) |
( V_287 & ~ V_286 ) ,
} ;
V_35 = F_226 ( V_246 ) ;
V_252 = F_227 ( V_35 ) -> V_288 ;
F_228 ( 0 ,
V_2 . V_133 ,
V_2 . V_124 ) ;
V_114 = F_206 ( V_252 , & V_2 ) ;
F_229 ( V_114 ) ;
return V_114 ;
}
static void F_230 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_242 * V_246 ;
if ( ! V_200 )
return;
V_246 = F_185 ( NULL , NULL , NULL ) ;
do {
struct V_11 * V_11 = F_186 ( V_4 , V_246 ) ;
if ( F_167 ( V_11 ) )
F_165 ( V_47 , V_11 ,
V_2 , V_218 ) ;
V_246 = F_185 ( NULL , V_246 , NULL ) ;
} while ( V_246 );
}
static bool F_231 ( struct V_4 * V_4 , int V_162 ,
unsigned long V_247 , int V_279 )
{
if ( ! F_193 ( V_4 , V_162 , F_173 ( V_4 ) +
V_247 , V_279 , 0 ) )
return false ;
if ( F_181 ( V_235 ) && V_162 &&
! F_183 ( V_4 , V_162 ) )
return false ;
return true ;
}
static bool F_232 ( T_8 * V_272 , int V_162 , int V_279 )
{
unsigned long V_250 = 0 ;
unsigned long V_289 = 0 ;
int V_274 ;
for ( V_274 = 0 ; V_274 <= V_279 ; V_274 ++ ) {
struct V_4 * V_4 = V_272 -> V_277 + V_274 ;
if ( ! F_199 ( V_4 ) )
continue;
V_250 += V_4 -> V_250 ;
if ( ! F_5 ( V_4 ) ) {
V_289 += V_4 -> V_250 ;
continue;
}
if ( F_231 ( V_4 , V_162 , 0 , V_274 ) )
V_289 += V_4 -> V_250 ;
else if ( ! V_162 )
return false ;
}
if ( V_162 )
return V_289 >= ( V_250 >> 2 ) ;
else
return true ;
}
static bool F_233 ( T_8 * V_272 , int V_162 , long V_290 ,
int V_279 )
{
if ( V_290 )
return false ;
if ( F_213 ( & V_272 -> V_283 ) ) {
F_234 ( & V_272 -> V_283 ) ;
return false ;
}
return F_232 ( V_272 , V_162 , V_279 ) ;
}
static bool F_235 ( struct V_4 * V_4 ,
int V_279 ,
struct V_1 * V_2 ,
unsigned long V_29 ,
unsigned long * V_291 )
{
int V_292 = V_2 -> V_162 ;
unsigned long V_247 ;
struct V_258 * V_258 = V_52 -> V_258 ;
struct V_26 V_260 = {
. V_124 = V_2 -> V_124 ,
} ;
bool V_293 ;
V_2 -> V_225 = F_236 ( V_47 , F_173 ( V_4 ) ) ;
if ( F_181 ( V_235 ) && V_2 -> V_162 &&
F_183 ( V_4 , V_2 -> V_162 ) !=
V_294 )
V_292 = 0 ;
V_247 = F_22 ( F_191 ( V_4 ) , F_192 (
V_4 -> V_250 , V_251 ) ) ;
V_293 = ( V_196 && F_237 ( V_4 ) ) ;
if ( ! V_293 && F_231 ( V_4 , V_292 ,
V_247 , V_279 ) )
return true ;
F_184 ( V_4 , V_2 ) ;
F_197 ( V_260 . V_264 ) ;
F_201 ( F_202 ( V_4 ) , V_260 . V_264 ) ;
V_258 -> V_265 = 0 ;
F_29 ( & V_260 , V_2 -> V_120 , V_29 ) ;
V_2 -> V_114 += V_258 -> V_265 ;
* V_291 += V_2 -> V_225 ;
F_238 ( V_4 , V_183 ) ;
if ( F_5 ( V_4 ) &&
F_231 ( V_4 , V_292 , 0 , V_279 ) ) {
F_238 ( V_4 , V_184 ) ;
F_238 ( V_4 , V_185 ) ;
}
return V_2 -> V_120 >= V_2 -> V_225 ;
}
static unsigned long F_239 ( T_8 * V_272 , int V_162 ,
int * V_279 )
{
int V_274 ;
int V_295 = 0 ;
unsigned long V_255 ;
unsigned long V_256 ;
struct V_1 V_2 = {
. V_124 = V_21 ,
. V_136 = V_137 ,
. V_122 = 1 ,
. V_214 = 1 ,
. V_133 = ! V_269 ,
. V_162 = V_162 ,
. V_3 = NULL ,
} ;
F_87 ( V_296 ) ;
do {
unsigned long V_29 = 0 ;
unsigned long V_291 = 0 ;
bool V_297 = true ;
bool V_298 = ( V_162 > 0 ) ;
V_2 . V_114 = 0 ;
for ( V_274 = V_272 -> V_299 - 1 ; V_274 >= 0 ; V_274 -- ) {
struct V_4 * V_4 = V_272 -> V_277 + V_274 ;
if ( ! F_199 ( V_4 ) )
continue;
if ( V_2 . V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
F_230 ( V_4 , & V_2 ) ;
if ( V_196 && F_240 ( V_274 ) ) {
V_295 = V_274 ;
break;
}
if ( ! F_231 ( V_4 , V_162 , 0 , 0 ) ) {
V_295 = V_274 ;
break;
} else {
F_238 ( V_4 , V_184 ) ;
F_238 ( V_4 , V_185 ) ;
}
}
if ( V_274 < 0 )
goto V_48;
for ( V_274 = 0 ; V_274 <= V_295 ; V_274 ++ ) {
struct V_4 * V_4 = V_272 -> V_277 + V_274 ;
if ( ! F_199 ( V_4 ) )
continue;
V_29 += F_2 ( V_4 ) ;
if ( V_298 &&
F_241 ( V_4 , V_162 ,
F_191 ( V_4 ) ,
* V_279 , 0 ) )
V_298 = false ;
}
if ( V_2 . V_136 < V_137 - 2 )
V_2 . V_133 = 1 ;
for ( V_274 = 0 ; V_274 <= V_295 ; V_274 ++ ) {
struct V_4 * V_4 = V_272 -> V_277 + V_274 ;
if ( ! F_199 ( V_4 ) )
continue;
if ( V_2 . V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
V_2 . V_120 = 0 ;
V_256 = 0 ;
V_255 = F_204 ( V_4 ,
V_162 , V_2 . V_124 ,
& V_256 ) ;
V_2 . V_114 += V_255 ;
if ( F_235 ( V_4 , V_295 , & V_2 ,
V_29 , & V_291 ) )
V_297 = false ;
}
if ( F_213 ( & V_272 -> V_283 ) &&
F_211 ( V_272 ) )
F_234 ( & V_272 -> V_283 ) ;
if ( V_162 && V_2 . V_114 >= 2UL << V_162 )
V_162 = V_2 . V_162 = 0 ;
if ( F_242 () || F_243 () )
break;
if ( V_298 && V_2 . V_114 > V_291 )
F_244 ( V_272 , V_162 ) ;
if ( V_297 || ! V_2 . V_114 )
V_2 . V_136 -- ;
} while ( V_2 . V_136 >= 1 &&
! F_232 ( V_272 , V_162 , * V_279 ) );
V_48:
* V_279 = V_295 ;
return V_162 ;
}
static void F_245 ( T_8 * V_272 , int V_162 , int V_279 )
{
long V_290 = 0 ;
F_246 ( V_300 ) ;
if ( F_247 ( V_52 ) || F_243 () )
return;
F_248 ( & V_272 -> V_278 , & V_300 , V_301 ) ;
if ( F_233 ( V_272 , V_162 , V_290 , V_279 ) ) {
V_290 = F_249 ( V_177 / 10 ) ;
F_250 ( & V_272 -> V_278 , & V_300 ) ;
F_248 ( & V_272 -> V_278 , & V_300 , V_301 ) ;
}
if ( F_233 ( V_272 , V_162 , V_290 , V_279 ) ) {
F_251 ( V_272 -> V_188 ) ;
F_252 ( V_272 , V_302 ) ;
F_253 ( V_272 ) ;
if ( ! F_243 () )
F_254 () ;
F_252 ( V_272 , V_303 ) ;
} else {
if ( V_290 )
F_87 ( V_304 ) ;
else
F_87 ( V_305 ) ;
}
F_250 ( & V_272 -> V_278 , & V_300 ) ;
}
static int F_255 ( void * V_306 )
{
unsigned long V_162 , V_307 ;
unsigned V_308 ;
int V_279 , V_309 ;
int V_310 ;
T_8 * V_272 = ( T_8 * ) V_306 ;
struct V_311 * V_312 = V_52 ;
struct V_258 V_258 = {
. V_265 = 0 ,
} ;
const struct V_313 * V_313 = F_256 ( V_272 -> V_188 ) ;
F_257 ( V_21 ) ;
if ( ! F_258 ( V_313 ) )
F_259 ( V_312 , V_313 ) ;
V_52 -> V_258 = & V_258 ;
V_312 -> V_19 |= V_314 | V_53 | V_315 ;
F_260 () ;
V_162 = V_307 = 0 ;
V_308 = 0 ;
V_279 = V_309 = V_272 -> V_299 - 1 ;
V_310 = V_279 ;
for ( ; ; ) {
bool V_43 ;
if ( V_310 >= V_309 &&
V_308 == V_307 ) {
V_307 = V_272 -> V_316 ;
V_309 = V_272 -> V_279 ;
V_272 -> V_316 = 0 ;
V_272 -> V_279 = V_272 -> V_299 - 1 ;
}
if ( V_162 < V_307 || V_279 > V_309 ) {
V_162 = V_307 ;
V_279 = V_309 ;
} else {
F_245 ( V_272 , V_308 ,
V_310 ) ;
V_162 = V_272 -> V_316 ;
V_279 = V_272 -> V_279 ;
V_307 = V_162 ;
V_309 = V_279 ;
V_272 -> V_316 = 0 ;
V_272 -> V_279 = V_272 -> V_299 - 1 ;
}
V_43 = F_242 () ;
if ( F_243 () )
break;
if ( ! V_43 ) {
F_261 ( V_272 -> V_188 , V_162 ) ;
V_310 = V_279 ;
V_308 = F_239 ( V_272 , V_162 ,
& V_310 ) ;
}
}
V_312 -> V_19 &= ~ ( V_314 | V_53 | V_315 ) ;
V_52 -> V_258 = NULL ;
F_262 () ;
return 0 ;
}
void F_263 ( struct V_4 * V_4 , int V_162 , enum V_261 V_279 )
{
T_8 * V_272 ;
if ( ! F_199 ( V_4 ) )
return;
if ( ! F_200 ( V_4 , V_21 ) )
return;
V_272 = V_4 -> V_187 ;
if ( V_272 -> V_316 < V_162 ) {
V_272 -> V_316 = V_162 ;
V_272 -> V_279 = F_22 ( V_272 -> V_279 , V_279 ) ;
}
if ( ! F_213 ( & V_272 -> V_278 ) )
return;
if ( F_231 ( V_4 , V_162 , 0 , 0 ) )
return;
F_264 ( V_272 -> V_188 , F_161 ( V_4 ) , V_162 ) ;
F_214 ( & V_272 -> V_278 ) ;
}
unsigned long F_265 ( unsigned long V_225 )
{
struct V_258 V_258 ;
struct V_1 V_2 = {
. V_124 = V_287 ,
. V_214 = 1 ,
. V_122 = 1 ,
. V_133 = 1 ,
. V_225 = V_225 ,
. V_186 = 1 ,
. V_162 = 0 ,
. V_136 = V_137 ,
} ;
struct V_252 * V_252 = F_266 ( F_267 () , V_2 . V_124 ) ;
struct V_311 * V_306 = V_52 ;
unsigned long V_114 ;
V_306 -> V_19 |= V_314 ;
F_257 ( V_2 . V_124 ) ;
V_258 . V_265 = 0 ;
V_306 -> V_258 = & V_258 ;
V_114 = F_206 ( V_252 , & V_2 ) ;
V_306 -> V_258 = NULL ;
F_262 () ;
V_306 -> V_19 &= ~ V_314 ;
return V_114 ;
}
static int F_268 ( struct V_317 * V_318 , unsigned long V_319 ,
void * V_320 )
{
int V_35 ;
if ( V_319 == V_321 || V_319 == V_322 ) {
F_269 (nid, N_MEMORY) {
T_8 * V_272 = F_227 ( V_35 ) ;
const struct V_313 * V_323 ;
V_323 = F_256 ( V_272 -> V_188 ) ;
if ( F_270 ( V_324 , V_323 ) < V_325 )
F_259 ( V_272 -> F_255 , V_323 ) ;
}
}
return V_326 ;
}
int F_271 ( int V_35 )
{
T_8 * V_272 = F_227 ( V_35 ) ;
int V_43 = 0 ;
if ( V_272 -> F_255 )
return 0 ;
V_272 -> F_255 = F_272 ( F_255 , V_272 , L_3 , V_35 ) ;
if ( F_273 ( V_272 -> F_255 ) ) {
F_57 ( V_327 == V_328 ) ;
F_274 ( L_4 , V_35 ) ;
V_43 = F_275 ( V_272 -> F_255 ) ;
V_272 -> F_255 = NULL ;
}
return V_43 ;
}
void F_276 ( int V_35 )
{
struct V_311 * F_255 = F_227 ( V_35 ) -> F_255 ;
if ( F_255 ) {
F_277 ( F_255 ) ;
F_227 ( V_35 ) -> F_255 = NULL ;
}
}
static int T_10 F_278 ( void )
{
int V_35 ;
F_279 () ;
F_269 (nid, N_MEMORY)
F_271 ( V_35 ) ;
F_280 ( F_268 , 0 ) ;
return 0 ;
}
static inline unsigned long F_281 ( struct V_4 * V_4 )
{
unsigned long V_329 = F_3 ( V_4 , V_330 ) ;
unsigned long V_331 = F_3 ( V_4 , V_7 ) +
F_3 ( V_4 , V_6 ) ;
return ( V_331 > V_329 ) ? ( V_331 - V_329 ) : 0 ;
}
static long F_282 ( struct V_4 * V_4 )
{
long V_332 ;
long V_31 = 0 ;
if ( V_333 & V_334 )
V_332 = F_3 ( V_4 , V_335 ) ;
else
V_332 = F_281 ( V_4 ) ;
if ( ! ( V_333 & V_336 ) )
V_31 += F_3 ( V_4 , V_337 ) ;
if ( F_61 ( V_31 > V_332 ) )
V_31 = V_332 ;
return V_332 - V_31 ;
}
static int F_283 ( struct V_4 * V_4 , T_7 V_124 , unsigned int V_162 )
{
const unsigned long V_161 = 1 << V_162 ;
struct V_311 * V_306 = V_52 ;
struct V_258 V_258 ;
struct V_1 V_2 = {
. V_133 = ! ! ( V_333 & V_336 ) ,
. V_122 = ! ! ( V_333 & V_334 ) ,
. V_214 = 1 ,
. V_225 = F_236 ( V_161 , V_47 ) ,
. V_124 = ( V_124 = F_219 ( V_124 ) ) ,
. V_162 = V_162 ,
. V_136 = V_338 ,
} ;
struct V_26 V_260 = {
. V_124 = V_2 . V_124 ,
} ;
unsigned long V_339 , V_340 ;
F_25 () ;
V_306 -> V_19 |= V_314 | V_53 ;
F_257 ( V_124 ) ;
V_258 . V_265 = 0 ;
V_306 -> V_258 = & V_258 ;
if ( F_282 ( V_4 ) > V_4 -> V_341 ) {
do {
F_184 ( V_4 , & V_2 ) ;
} while ( V_2 . V_114 < V_161 && -- V_2 . V_136 >= 0 );
}
V_339 = F_3 ( V_4 , V_342 ) ;
if ( V_339 > V_4 -> V_343 ) {
F_197 ( V_260 . V_264 ) ;
F_201 ( F_202 ( V_4 ) , V_260 . V_264 ) ;
for (; ; ) {
unsigned long V_29 = F_2 ( V_4 ) ;
if ( ! F_29 ( & V_260 , V_2 . V_120 , V_29 ) )
break;
V_340 = F_3 ( V_4 ,
V_342 ) ;
if ( V_340 + V_161 <= V_339 )
break;
}
V_340 = F_3 ( V_4 , V_342 ) ;
if ( V_340 < V_339 )
V_2 . V_114 += V_339 - V_340 ;
}
V_306 -> V_258 = NULL ;
V_52 -> V_19 &= ~ ( V_314 | V_53 ) ;
F_262 () ;
return V_2 . V_114 >= V_161 ;
}
int F_284 ( struct V_4 * V_4 , T_7 V_124 , unsigned int V_162 )
{
int V_188 ;
int V_43 ;
if ( F_282 ( V_4 ) <= V_4 -> V_341 &&
F_3 ( V_4 , V_342 ) <= V_4 -> V_343 )
return V_344 ;
if ( ! F_5 ( V_4 ) )
return V_344 ;
if ( ! ( V_124 & V_345 ) || ( V_52 -> V_19 & V_314 ) )
return V_346 ;
V_188 = F_202 ( V_4 ) ;
if ( F_285 ( V_188 , V_347 ) && V_188 != F_267 () )
return V_346 ;
if ( F_286 ( V_4 , V_348 ) )
return V_346 ;
V_43 = F_283 ( V_4 , V_124 , V_162 ) ;
F_238 ( V_4 , V_348 ) ;
if ( ! V_43 )
F_87 ( V_349 ) ;
return V_43 ;
}
int F_81 ( struct V_49 * V_49 )
{
return ! F_287 ( F_42 ( V_49 ) ) && ! F_288 ( V_49 ) ;
}
void F_289 ( struct V_49 * * V_350 , int V_161 )
{
struct V_11 * V_11 ;
struct V_4 * V_4 = NULL ;
int V_351 = 0 ;
int V_352 = 0 ;
int V_274 ;
for ( V_274 = 0 ; V_274 < V_161 ; V_274 ++ ) {
struct V_49 * V_49 = V_350 [ V_274 ] ;
struct V_4 * V_353 ;
V_351 ++ ;
V_353 = F_101 ( V_49 ) ;
if ( V_353 != V_4 ) {
if ( V_4 )
F_67 ( & V_4 -> V_163 ) ;
V_4 = V_353 ;
F_59 ( & V_4 -> V_163 ) ;
}
V_11 = F_138 ( V_49 , V_4 ) ;
if ( ! F_79 ( V_49 ) || ! F_77 ( V_49 ) )
continue;
if ( F_81 ( V_49 ) ) {
enum V_12 V_13 = F_290 ( V_49 ) ;
F_78 ( F_100 ( V_49 ) , V_49 ) ;
F_80 ( V_49 ) ;
F_141 ( V_49 , V_11 , V_354 ) ;
F_145 ( V_49 , V_11 , V_13 ) ;
V_352 ++ ;
}
}
if ( V_4 ) {
F_164 ( V_84 , V_352 ) ;
F_164 ( V_355 , V_351 ) ;
F_67 ( & V_4 -> V_163 ) ;
}
}
static void F_291 ( void )
{
F_292 ( V_356
L_5
L_6
L_7 ,
V_52 -> V_357 ) ;
}
int F_293 ( struct V_358 * V_359 , int V_360 ,
void T_11 * V_361 ,
T_1 * V_362 , T_12 * V_363 )
{
F_291 () ;
F_294 ( V_359 , V_360 , V_361 , V_362 , V_363 ) ;
V_364 = 0 ;
return 0 ;
}
static T_13 F_295 ( struct V_365 * V_366 ,
struct V_367 * V_368 ,
char * V_369 )
{
F_291 () ;
return sprintf ( V_369 , L_8 ) ;
}
static T_13 F_296 ( struct V_365 * V_366 ,
struct V_367 * V_368 ,
const char * V_369 , T_1 V_370 )
{
F_291 () ;
return 1 ;
}
int F_297 ( struct V_371 * V_371 )
{
return F_298 ( & V_371 -> V_366 , & V_372 ) ;
}
void F_299 ( struct V_371 * V_371 )
{
F_300 ( & V_371 -> V_366 , & V_372 ) ;
}
