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
static unsigned long F_18 ( struct V_26 * V_27 ,
struct V_15 * V_15 ,
unsigned long V_28 ,
unsigned long V_29 )
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
F_21 ( L_1 ,
V_15 -> V_41 , V_32 ) ;
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
unsigned long V_42 ;
unsigned long V_43 = F_22 ( V_36 , V_32 ) ;
V_27 -> V_43 = V_43 ;
V_42 = V_15 -> V_41 ( V_15 , V_27 ) ;
if ( V_42 == V_44 )
break;
V_30 += V_42 ;
F_24 ( V_45 , V_43 ) ;
V_32 -= V_43 ;
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
unsigned long F_29 ( T_2 V_46 , int V_35 ,
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
struct V_26 V_2 = {
. V_46 = V_46 ,
. V_35 = V_35 ,
} ;
if ( ! ( V_15 -> V_19 & V_20 ) )
V_2 . V_35 = 0 ;
V_30 += F_18 ( & V_2 , V_15 , V_28 , V_29 ) ;
}
F_32 ( & V_23 ) ;
V_48:
F_25 () ;
return V_30 ;
}
static inline int F_33 ( struct V_49 * V_49 )
{
return F_34 ( V_49 ) - F_35 ( V_49 ) == 2 ;
}
static int F_36 ( struct V_50 * V_51 ,
struct V_1 * V_2 )
{
if ( V_52 -> V_19 & V_53 )
return 1 ;
if ( ! F_37 ( V_51 ) )
return 1 ;
if ( V_51 == V_52 -> V_50 )
return 1 ;
return 0 ;
}
static void F_38 ( struct V_54 * V_55 ,
struct V_49 * V_49 , int error )
{
F_39 ( V_49 ) ;
if ( F_40 ( V_49 ) == V_55 )
F_41 ( V_55 , error ) ;
F_42 ( V_49 ) ;
}
static T_3 F_43 ( struct V_49 * V_49 , struct V_54 * V_55 ,
struct V_1 * V_2 )
{
if ( ! F_33 ( V_49 ) )
return V_56 ;
if ( ! V_55 ) {
if ( F_35 ( V_49 ) ) {
if ( F_44 ( V_49 ) ) {
F_45 ( V_49 ) ;
F_46 ( L_2 , V_57 ) ;
return V_58 ;
}
}
return V_56 ;
}
if ( V_55 -> V_59 -> V_60 == NULL )
return V_61 ;
if ( ! F_36 ( V_55 -> V_50 , V_2 ) )
return V_56 ;
if ( F_47 ( V_49 ) ) {
int V_62 ;
struct V_63 V_64 = {
. V_65 = V_66 ,
. V_67 = V_47 ,
. V_68 = 0 ,
. V_69 = V_70 ,
. V_71 = 1 ,
} ;
F_48 ( V_49 ) ;
V_62 = V_55 -> V_59 -> V_60 ( V_49 , & V_64 ) ;
if ( V_62 < 0 )
F_38 ( V_55 , V_49 , V_62 ) ;
if ( V_62 == V_72 ) {
F_49 ( V_49 ) ;
return V_61 ;
}
if ( ! F_50 ( V_49 ) ) {
F_49 ( V_49 ) ;
}
F_51 ( V_49 , F_52 ( V_49 ) ) ;
F_53 ( V_49 , V_73 ) ;
return V_74 ;
}
return V_58 ;
}
static int F_54 ( struct V_54 * V_55 , struct V_49 * V_49 ,
bool V_75 )
{
F_55 ( ! F_56 ( V_49 ) ) ;
F_55 ( V_55 != F_40 ( V_49 ) ) ;
F_57 ( & V_55 -> V_76 ) ;
if ( ! F_58 ( V_49 , 2 ) )
goto V_77;
if ( F_59 ( F_60 ( V_49 ) ) ) {
F_61 ( V_49 , 2 ) ;
goto V_77;
}
if ( F_62 ( V_49 ) ) {
T_4 V_78 = { . V_79 = F_63 (page) } ;
F_64 ( V_49 , V_78 ) ;
F_65 ( V_49 ) ;
F_66 ( & V_55 -> V_76 ) ;
F_67 ( V_78 ) ;
} else {
void (* F_68)( struct V_49 * );
void * V_80 = NULL ;
F_68 = V_55 -> V_59 -> F_68 ;
if ( V_75 && F_69 ( V_49 ) &&
! F_70 ( V_55 ) )
V_80 = F_71 ( V_55 , V_49 ) ;
F_72 ( V_49 , V_80 ) ;
F_66 ( & V_55 -> V_76 ) ;
if ( F_68 != NULL )
F_68 ( V_49 ) ;
}
return 1 ;
V_77:
F_66 ( & V_55 -> V_76 ) ;
return 0 ;
}
int F_73 ( struct V_54 * V_55 , struct V_49 * V_49 )
{
if ( F_54 ( V_55 , V_49 , false ) ) {
F_61 ( V_49 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_74 ( struct V_49 * V_49 )
{
bool V_81 ;
int V_82 = F_75 ( V_49 ) ;
F_76 ( F_77 ( V_49 ) , V_49 ) ;
V_83:
F_78 ( V_49 ) ;
if ( F_79 ( V_49 ) ) {
V_81 = false ;
F_80 ( V_49 ) ;
} else {
V_81 = true ;
F_81 ( V_49 ) ;
F_82 () ;
}
if ( V_81 && F_79 ( V_49 ) ) {
if ( ! F_83 ( V_49 ) ) {
F_84 ( V_49 ) ;
goto V_83;
}
}
if ( V_82 && ! V_81 )
F_85 ( V_84 ) ;
else if ( ! V_82 && V_81 )
F_85 ( V_85 ) ;
F_84 ( V_49 ) ;
}
static enum V_86 F_86 ( struct V_49 * V_49 ,
struct V_1 * V_2 )
{
int V_87 , V_88 ;
unsigned long V_89 ;
V_87 = F_87 ( V_49 , 1 , V_2 -> V_3 ,
& V_89 ) ;
V_88 = F_88 ( V_49 ) ;
if ( V_89 & V_90 )
return V_91 ;
if ( V_87 ) {
if ( F_89 ( V_49 ) )
return V_92 ;
F_90 ( V_49 ) ;
if ( V_88 || V_87 > 1 )
return V_92 ;
if ( V_89 & V_93 )
return V_92 ;
return V_94 ;
}
if ( V_88 && ! F_89 ( V_49 ) )
return V_95 ;
return V_91 ;
}
static void F_91 ( struct V_49 * V_49 ,
bool * V_96 , bool * V_97 )
{
struct V_54 * V_55 ;
if ( ! F_69 ( V_49 ) ) {
* V_96 = false ;
* V_97 = false ;
return;
}
* V_96 = F_60 ( V_49 ) ;
* V_97 = F_50 ( V_49 ) ;
if ( ! F_35 ( V_49 ) )
return;
V_55 = F_40 ( V_49 ) ;
if ( V_55 && V_55 -> V_59 -> V_98 )
V_55 -> V_59 -> V_98 ( V_49 , V_96 , V_97 ) ;
}
static unsigned long F_92 ( struct V_99 * V_100 ,
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
F_93 ( V_108 ) ;
F_93 ( V_109 ) ;
int V_110 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_114 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
F_25 () ;
while ( ! F_94 ( V_100 ) ) {
struct V_54 * V_55 ;
struct V_49 * V_49 ;
int V_117 ;
enum V_86 V_118 = V_95 ;
bool V_96 , V_97 ;
F_25 () ;
V_49 = F_95 ( V_100 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( ! F_96 ( V_49 ) )
goto V_119;
F_76 ( F_97 ( V_49 ) , V_49 ) ;
F_76 ( F_98 ( V_49 ) != V_4 , V_49 ) ;
V_2 -> V_28 ++ ;
if ( F_59 ( ! F_79 ( V_49 ) ) )
goto V_120;
if ( ! V_2 -> V_121 && F_99 ( V_49 ) )
goto V_122;
if ( F_99 ( V_49 ) || F_62 ( V_49 ) )
V_2 -> V_28 ++ ;
V_117 = ( V_2 -> V_46 & V_123 ) ||
( F_62 ( V_49 ) && ( V_2 -> V_46 & V_124 ) ) ;
F_91 ( V_49 , & V_96 , & V_97 ) ;
if ( V_96 || V_97 )
V_112 ++ ;
if ( V_96 && ! V_97 )
V_111 ++ ;
V_55 = F_40 ( V_49 ) ;
if ( ( ( V_96 || V_97 ) && V_55 &&
F_37 ( V_55 -> V_50 ) ) ||
( V_97 && F_100 ( V_49 ) ) )
V_113 ++ ;
if ( F_50 ( V_49 ) ) {
if ( F_101 () &&
F_100 ( V_49 ) &&
F_102 ( V_125 , & V_4 -> V_19 ) ) {
V_116 ++ ;
goto V_122;
} else if ( F_1 ( V_2 ) ||
! F_100 ( V_49 ) || ! ( V_2 -> V_46 & V_124 ) ) {
F_48 ( V_49 ) ;
V_115 ++ ;
goto V_122;
} else {
F_103 ( V_49 ) ;
}
}
if ( ! V_107 )
V_118 = F_86 ( V_49 , V_2 ) ;
switch ( V_118 ) {
case V_92 :
goto V_126;
case V_94 :
goto V_122;
case V_91 :
case V_95 :
;
}
if ( F_104 ( V_49 ) && ! F_62 ( V_49 ) ) {
if ( ! ( V_2 -> V_46 & V_124 ) )
goto V_122;
if ( ! F_105 ( V_49 , V_100 ) )
goto V_126;
V_117 = 1 ;
V_55 = F_40 ( V_49 ) ;
}
if ( F_99 ( V_49 ) && V_55 ) {
switch ( F_106 ( V_49 , V_101 ) ) {
case V_127 :
goto V_126;
case V_128 :
goto V_122;
case V_129 :
goto V_120;
case V_130 :
;
}
}
if ( F_60 ( V_49 ) ) {
if ( F_69 ( V_49 ) &&
( ! F_101 () ||
! F_102 ( V_131 , & V_4 -> V_19 ) ) ) {
F_53 ( V_49 , V_132 ) ;
F_48 ( V_49 ) ;
goto V_122;
}
if ( V_118 == V_95 )
goto V_122;
if ( ! V_117 )
goto V_122;
if ( ! V_2 -> V_133 )
goto V_122;
switch ( F_43 ( V_49 , V_55 , V_2 ) ) {
case V_56 :
goto V_122;
case V_61 :
goto V_126;
case V_74 :
if ( F_50 ( V_49 ) )
goto V_119;
if ( F_60 ( V_49 ) )
goto V_119;
if ( ! F_96 ( V_49 ) )
goto V_119;
if ( F_60 ( V_49 ) || F_50 ( V_49 ) )
goto V_122;
V_55 = F_40 ( V_49 ) ;
case V_58 :
;
}
}
if ( F_35 ( V_49 ) ) {
if ( ! F_107 ( V_49 , V_2 -> V_46 ) )
goto V_126;
if ( ! V_55 && F_34 ( V_49 ) == 1 ) {
F_42 ( V_49 ) ;
if ( F_108 ( V_49 ) )
goto V_134;
else {
V_114 ++ ;
continue;
}
}
}
if ( ! V_55 || ! F_54 ( V_55 , V_49 , true ) )
goto V_122;
F_109 ( V_49 ) ;
V_134:
V_114 ++ ;
F_110 ( & V_49 -> V_13 , & V_109 ) ;
continue;
V_120:
if ( F_62 ( V_49 ) )
F_111 ( V_49 ) ;
F_42 ( V_49 ) ;
F_74 ( V_49 ) ;
continue;
V_126:
if ( F_62 ( V_49 ) && F_112 () )
F_111 ( V_49 ) ;
F_76 ( F_97 ( V_49 ) , V_49 ) ;
F_113 ( V_49 ) ;
V_110 ++ ;
V_122:
F_42 ( V_49 ) ;
V_119:
F_110 ( & V_49 -> V_13 , & V_108 ) ;
F_76 ( F_77 ( V_49 ) || F_75 ( V_49 ) , V_49 ) ;
}
F_114 ( & V_109 ) ;
F_115 ( & V_109 , true ) ;
F_116 ( & V_108 , V_100 ) ;
F_24 ( V_135 , V_110 ) ;
* V_102 += V_112 ;
* V_104 += V_113 ;
* V_103 += V_111 ;
* V_105 += V_115 ;
* V_106 += V_116 ;
return V_114 ;
}
unsigned long F_117 ( struct V_4 * V_4 ,
struct V_99 * V_100 )
{
struct V_1 V_2 = {
. V_46 = V_21 ,
. V_136 = V_137 ,
. V_121 = 1 ,
} ;
unsigned long V_42 , V_138 , V_139 , V_140 , V_141 , V_142 ;
struct V_49 * V_49 , * V_143 ;
F_93 ( V_144 ) ;
F_118 (page, next, page_list, lru) {
if ( F_69 ( V_49 ) && ! F_60 ( V_49 ) &&
! F_119 ( V_49 ) ) {
F_120 ( V_49 ) ;
F_121 ( & V_49 -> V_13 , & V_144 ) ;
}
}
V_42 = F_92 ( & V_144 , V_4 , & V_2 ,
V_145 | V_146 ,
& V_138 , & V_139 , & V_140 , & V_141 , & V_142 , true ) ;
F_116 ( & V_144 , V_100 ) ;
F_122 ( V_4 , V_147 , - V_42 ) ;
return V_42 ;
}
int F_123 ( struct V_49 * V_49 , T_5 V_148 )
{
int V_42 = - V_149 ;
if ( ! F_77 ( V_49 ) )
return V_42 ;
if ( F_75 ( V_49 ) && ! ( V_148 & V_150 ) )
return V_42 ;
V_42 = - V_151 ;
if ( V_148 & ( V_152 | V_153 ) ) {
if ( F_50 ( V_49 ) )
return V_42 ;
if ( F_60 ( V_49 ) ) {
struct V_54 * V_55 ;
if ( V_148 & V_152 )
return V_42 ;
V_55 = F_40 ( V_49 ) ;
if ( V_55 && ! V_55 -> V_59 -> V_154 )
return V_42 ;
}
}
if ( ( V_148 & V_155 ) && F_99 ( V_49 ) )
return V_42 ;
if ( F_124 ( F_125 ( V_49 ) ) ) {
F_126 ( V_49 ) ;
V_42 = 0 ;
}
return V_42 ;
}
static unsigned long F_127 ( unsigned long V_43 ,
struct V_11 * V_11 , struct V_99 * V_156 ,
unsigned long * V_28 , struct V_1 * V_2 ,
T_5 V_148 , enum V_12 V_13 )
{
struct V_99 * V_157 = & V_11 -> V_158 [ V_13 ] ;
unsigned long V_159 = 0 ;
unsigned long V_160 ;
for ( V_160 = 0 ; V_160 < V_43 && ! F_94 ( V_157 ) ; V_160 ++ ) {
struct V_49 * V_49 ;
int V_161 ;
V_49 = F_95 ( V_157 ) ;
F_128 ( V_49 , V_157 , V_19 ) ;
F_76 ( ! F_77 ( V_49 ) , V_49 ) ;
switch ( F_123 ( V_49 , V_148 ) ) {
case 0 :
V_161 = F_129 ( V_49 ) ;
F_130 ( V_11 , V_13 , - V_161 ) ;
F_121 ( & V_49 -> V_13 , V_156 ) ;
V_159 += V_161 ;
break;
case - V_151 :
F_121 ( & V_49 -> V_13 , V_157 ) ;
continue;
default:
F_131 () ;
}
}
* V_28 = V_160 ;
F_132 ( V_2 -> V_162 , V_43 , V_160 ,
V_159 , V_148 , F_133 ( V_13 ) ) ;
return V_159 ;
}
int F_83 ( struct V_49 * V_49 )
{
int V_42 = - V_151 ;
F_76 ( ! F_34 ( V_49 ) , V_49 ) ;
if ( F_77 ( V_49 ) ) {
struct V_4 * V_4 = F_98 ( V_49 ) ;
struct V_11 * V_11 ;
F_57 ( & V_4 -> V_163 ) ;
V_11 = F_134 ( V_49 , V_4 ) ;
if ( F_77 ( V_49 ) ) {
int V_13 = F_135 ( V_49 ) ;
F_136 ( V_49 ) ;
F_126 ( V_49 ) ;
F_137 ( V_49 , V_11 , V_13 ) ;
V_42 = 0 ;
}
F_66 ( & V_4 -> V_163 ) ;
}
return V_42 ;
}
static int F_138 ( struct V_4 * V_4 , int V_164 ,
struct V_1 * V_2 )
{
unsigned long V_165 , V_166 ;
if ( F_101 () )
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
if ( ( V_2 -> V_46 & V_168 ) == V_168 )
V_165 >>= 3 ;
return V_166 > V_165 ;
}
static T_6 void
F_139 ( struct V_11 * V_11 , struct V_99 * V_100 )
{
struct V_169 * V_170 = & V_11 -> V_170 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_93 ( V_171 ) ;
while ( ! F_94 ( V_100 ) ) {
struct V_49 * V_49 = F_95 ( V_100 ) ;
int V_13 ;
F_76 ( F_77 ( V_49 ) , V_49 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_59 ( ! F_79 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_163 ) ;
F_74 ( V_49 ) ;
F_57 ( & V_4 -> V_163 ) ;
continue;
}
V_11 = F_134 ( V_49 , V_4 ) ;
F_140 ( V_49 ) ;
V_13 = F_135 ( V_49 ) ;
F_141 ( V_49 , V_11 , V_13 ) ;
if ( F_142 ( V_13 ) ) {
int V_164 = F_133 ( V_13 ) ;
int V_172 = F_129 ( V_49 ) ;
V_170 -> V_173 [ V_164 ] += V_172 ;
}
if ( F_108 ( V_49 ) ) {
F_143 ( V_49 ) ;
F_144 ( V_49 ) ;
F_137 ( V_49 , V_11 , V_13 ) ;
if ( F_59 ( F_145 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_163 ) ;
F_146 ( V_49 ) ;
( * F_147 ( V_49 ) ) ( V_49 ) ;
F_57 ( & V_4 -> V_163 ) ;
} else
F_110 ( & V_49 -> V_13 , & V_171 ) ;
}
}
F_116 ( & V_171 , V_100 ) ;
}
static int F_148 ( void )
{
return ! ( V_52 -> V_19 & V_174 ) ||
V_52 -> V_50 == NULL ||
F_37 ( V_52 -> V_50 ) ;
}
static T_6 unsigned long
F_149 ( unsigned long V_43 , struct V_11 * V_11 ,
struct V_1 * V_2 , enum V_12 V_13 )
{
F_93 ( V_100 ) ;
unsigned long V_28 ;
unsigned long V_114 = 0 ;
unsigned long V_159 ;
unsigned long V_112 = 0 ;
unsigned long V_113 = 0 ;
unsigned long V_111 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
T_5 V_175 = 0 ;
int V_164 = F_133 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
struct V_169 * V_170 = & V_11 -> V_170 ;
while ( F_59 ( F_138 ( V_4 , V_164 , V_2 ) ) ) {
F_150 ( V_176 , V_177 / 10 ) ;
if ( F_151 ( V_52 ) )
return V_47 ;
}
F_152 () ;
if ( ! V_2 -> V_121 )
V_175 |= V_155 ;
if ( ! V_2 -> V_133 )
V_175 |= V_152 ;
F_57 ( & V_4 -> V_163 ) ;
V_159 = F_127 ( V_43 , V_11 , & V_100 ,
& V_28 , V_2 , V_175 , V_13 ) ;
F_153 ( V_4 , V_14 + V_13 , - V_159 ) ;
F_153 ( V_4 , V_167 + V_164 , V_159 ) ;
if ( F_1 ( V_2 ) ) {
F_153 ( V_4 , V_10 , V_28 ) ;
if ( F_101 () )
F_154 ( V_178 , V_4 , V_28 ) ;
else
F_154 ( V_179 , V_4 , V_28 ) ;
}
F_66 ( & V_4 -> V_163 ) ;
if ( V_159 == 0 )
return 0 ;
V_114 = F_92 ( & V_100 , V_4 , V_2 , V_145 ,
& V_112 , & V_111 , & V_113 ,
& V_115 , & V_116 ,
false ) ;
F_57 ( & V_4 -> V_163 ) ;
V_170 -> V_180 [ V_164 ] += V_159 ;
if ( F_1 ( V_2 ) ) {
if ( F_101 () )
F_154 ( V_181 , V_4 ,
V_114 ) ;
else
F_154 ( V_182 , V_4 ,
V_114 ) ;
}
F_139 ( V_11 , & V_100 ) ;
F_153 ( V_4 , V_167 + V_164 , - V_159 ) ;
F_66 ( & V_4 -> V_163 ) ;
F_114 ( & V_100 ) ;
F_115 ( & V_100 , true ) ;
if ( V_115 && V_115 == V_159 )
F_155 ( V_125 , & V_4 -> V_19 ) ;
if ( F_1 ( V_2 ) ) {
if ( V_112 && V_112 == V_113 )
F_155 ( V_183 , & V_4 -> V_19 ) ;
if ( V_111 == V_159 )
F_155 ( V_131 , & V_4 -> V_19 ) ;
if ( V_116 && F_148 () )
F_150 ( V_176 , V_177 / 10 ) ;
}
if ( ! V_2 -> V_184 && ! F_101 () &&
F_148 () )
F_156 ( V_4 , V_176 , V_177 / 10 ) ;
F_157 ( V_4 -> V_185 -> V_186 ,
F_158 ( V_4 ) ,
V_28 , V_114 ,
V_2 -> V_136 ,
F_159 ( V_164 ) ) ;
return V_114 ;
}
static void F_160 ( struct V_11 * V_11 ,
struct V_99 * V_24 ,
struct V_99 * V_171 ,
enum V_12 V_13 )
{
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_187 = 0 ;
struct V_49 * V_49 ;
int V_161 ;
while ( ! F_94 ( V_24 ) ) {
V_49 = F_95 ( V_24 ) ;
V_11 = F_134 ( V_49 , V_4 ) ;
F_76 ( F_77 ( V_49 ) , V_49 ) ;
F_140 ( V_49 ) ;
V_161 = F_129 ( V_49 ) ;
F_130 ( V_11 , V_13 , V_161 ) ;
F_121 ( & V_49 -> V_13 , & V_11 -> V_158 [ V_13 ] ) ;
V_187 += V_161 ;
if ( F_108 ( V_49 ) ) {
F_143 ( V_49 ) ;
F_144 ( V_49 ) ;
F_137 ( V_49 , V_11 , V_13 ) ;
if ( F_59 ( F_145 ( V_49 ) ) ) {
F_66 ( & V_4 -> V_163 ) ;
F_146 ( V_49 ) ;
( * F_147 ( V_49 ) ) ( V_49 ) ;
F_57 ( & V_4 -> V_163 ) ;
} else
F_110 ( & V_49 -> V_13 , V_171 ) ;
}
}
F_153 ( V_4 , V_14 + V_13 , V_187 ) ;
if ( ! F_142 ( V_13 ) )
F_161 ( V_188 , V_187 ) ;
}
static void F_162 ( unsigned long V_43 ,
struct V_11 * V_11 ,
struct V_1 * V_2 ,
enum V_12 V_13 )
{
unsigned long V_159 ;
unsigned long V_28 ;
unsigned long V_89 ;
F_93 ( V_189 ) ;
F_93 ( V_190 ) ;
F_93 ( V_191 ) ;
struct V_49 * V_49 ;
struct V_169 * V_170 = & V_11 -> V_170 ;
unsigned long V_192 = 0 ;
T_5 V_175 = 0 ;
int V_164 = F_133 ( V_13 ) ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
F_152 () ;
if ( ! V_2 -> V_121 )
V_175 |= V_155 ;
if ( ! V_2 -> V_133 )
V_175 |= V_152 ;
F_57 ( & V_4 -> V_163 ) ;
V_159 = F_127 ( V_43 , V_11 , & V_189 ,
& V_28 , V_2 , V_175 , V_13 ) ;
if ( F_1 ( V_2 ) )
F_153 ( V_4 , V_10 , V_28 ) ;
V_170 -> V_180 [ V_164 ] += V_159 ;
F_154 ( V_193 , V_4 , V_28 ) ;
F_153 ( V_4 , V_14 + V_13 , - V_159 ) ;
F_153 ( V_4 , V_167 + V_164 , V_159 ) ;
F_66 ( & V_4 -> V_163 ) ;
while ( ! F_94 ( & V_189 ) ) {
F_25 () ;
V_49 = F_95 ( & V_189 ) ;
F_16 ( & V_49 -> V_13 ) ;
if ( F_59 ( ! F_79 ( V_49 ) ) ) {
F_74 ( V_49 ) ;
continue;
}
if ( F_59 ( V_194 ) ) {
if ( F_35 ( V_49 ) && F_96 ( V_49 ) ) {
if ( F_35 ( V_49 ) )
F_107 ( V_49 , 0 ) ;
F_42 ( V_49 ) ;
}
}
if ( F_87 ( V_49 , 0 , V_2 -> V_3 ,
& V_89 ) ) {
V_192 += F_129 ( V_49 ) ;
if ( ( V_89 & V_93 ) && F_69 ( V_49 ) ) {
F_110 ( & V_49 -> V_13 , & V_190 ) ;
continue;
}
}
F_120 ( V_49 ) ;
F_110 ( & V_49 -> V_13 , & V_191 ) ;
}
F_57 ( & V_4 -> V_163 ) ;
V_170 -> V_173 [ V_164 ] += V_192 ;
F_160 ( V_11 , & V_190 , & V_189 , V_13 ) ;
F_160 ( V_11 , & V_191 , & V_189 , V_13 - V_195 ) ;
F_153 ( V_4 , V_167 + V_164 , - V_159 ) ;
F_66 ( & V_4 -> V_163 ) ;
F_114 ( & V_189 ) ;
F_115 ( & V_189 , true ) ;
}
static int F_163 ( struct V_4 * V_4 )
{
unsigned long V_196 , V_165 ;
V_196 = F_3 ( V_4 , V_8 ) ;
V_165 = F_3 ( V_4 , V_9 ) ;
if ( V_165 * V_4 -> V_197 < V_196 )
return 1 ;
return 0 ;
}
static int F_164 ( struct V_11 * V_11 )
{
if ( ! V_198 )
return 0 ;
if ( ! F_7 () )
return F_165 ( V_11 ) ;
return F_163 ( F_9 ( V_11 ) ) ;
}
static inline int F_164 ( struct V_11 * V_11 )
{
return 0 ;
}
static int F_166 ( struct V_11 * V_11 )
{
unsigned long V_165 ;
unsigned long V_196 ;
V_165 = F_6 ( V_11 , V_199 ) ;
V_196 = F_6 ( V_11 , V_200 ) ;
return V_196 > V_165 ;
}
static int F_167 ( struct V_11 * V_11 , enum V_12 V_13 )
{
if ( F_133 ( V_13 ) )
return F_166 ( V_11 ) ;
else
return F_164 ( V_11 ) ;
}
static unsigned long F_168 ( enum V_12 V_13 , unsigned long V_43 ,
struct V_11 * V_11 , struct V_1 * V_2 )
{
if ( F_142 ( V_13 ) ) {
if ( F_167 ( V_11 , V_13 ) )
F_162 ( V_43 , V_11 , V_2 , V_13 ) ;
return 0 ;
}
return F_149 ( V_43 , V_11 , V_2 , V_13 ) ;
}
static void F_169 ( struct V_11 * V_11 , int V_201 ,
struct V_1 * V_2 , unsigned long * V_5 ,
unsigned long * V_202 )
{
struct V_169 * V_170 = & V_11 -> V_170 ;
T_7 V_203 [ 2 ] ;
T_7 V_204 = 0 ;
struct V_4 * V_4 = F_9 ( V_11 ) ;
unsigned long V_205 , V_206 ;
enum V_207 V_207 ;
unsigned long V_208 , V_164 ;
bool V_209 = false ;
unsigned long V_210 , V_211 ;
enum V_12 V_13 ;
bool V_212 ;
int V_213 ;
if ( F_101 () && ! F_5 ( V_4 ) )
V_209 = true ;
if ( ! F_1 ( V_2 ) )
V_209 = true ;
if ( ! V_2 -> V_214 || ( F_4 () <= 0 ) ) {
V_207 = V_215 ;
goto V_48;
}
if ( ! F_1 ( V_2 ) && ! V_201 ) {
V_207 = V_215 ;
goto V_48;
}
if ( ! V_2 -> V_136 && V_201 ) {
V_207 = V_216 ;
goto V_48;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_217 ;
unsigned long V_218 ;
V_218 = F_3 ( V_4 , V_219 ) ;
V_217 = F_3 ( V_4 , V_6 ) +
F_3 ( V_4 , V_7 ) ;
if ( F_59 ( V_217 + V_218 <= F_170 ( V_4 ) ) ) {
V_207 = V_220 ;
goto V_48;
}
}
if ( ! F_166 ( V_11 ) ) {
V_207 = V_215 ;
goto V_48;
}
V_207 = V_221 ;
V_205 = V_201 ;
V_206 = 200 - V_205 ;
V_208 = F_6 ( V_11 , V_222 ) +
F_6 ( V_11 , V_223 ) ;
V_164 = F_6 ( V_11 , V_200 ) +
F_6 ( V_11 , V_199 ) ;
F_57 ( & V_4 -> V_163 ) ;
if ( F_59 ( V_170 -> V_180 [ 0 ] > V_208 / 4 ) ) {
V_170 -> V_180 [ 0 ] /= 2 ;
V_170 -> V_173 [ 0 ] /= 2 ;
}
if ( F_59 ( V_170 -> V_180 [ 1 ] > V_164 / 4 ) ) {
V_170 -> V_180 [ 1 ] /= 2 ;
V_170 -> V_173 [ 1 ] /= 2 ;
}
V_210 = V_205 * ( V_170 -> V_180 [ 0 ] + 1 ) ;
V_210 /= V_170 -> V_173 [ 0 ] + 1 ;
V_211 = V_206 * ( V_170 -> V_180 [ 1 ] + 1 ) ;
V_211 /= V_170 -> V_173 [ 1 ] + 1 ;
F_66 ( & V_4 -> V_163 ) ;
V_203 [ 0 ] = V_210 ;
V_203 [ 1 ] = V_211 ;
V_204 = V_210 + V_211 + 1 ;
V_48:
V_212 = false ;
for ( V_213 = 0 ; ! V_212 && V_213 < 2 ; V_213 ++ ) {
* V_202 = 0 ;
F_171 (lru) {
int V_164 = F_133 ( V_13 ) ;
unsigned long V_16 ;
unsigned long V_160 ;
V_16 = F_6 ( V_11 , V_13 ) ;
V_160 = V_16 >> V_2 -> V_136 ;
if ( ! V_160 && V_213 && V_209 )
V_160 = F_22 ( V_16 , V_47 ) ;
switch ( V_207 ) {
case V_216 :
break;
case V_221 :
V_160 = F_172 ( V_160 * V_203 [ V_164 ] ,
V_204 ) ;
break;
case V_215 :
case V_220 :
if ( ( V_207 == V_215 ) != V_164 ) {
V_16 = 0 ;
V_160 = 0 ;
}
break;
default:
F_131 () ;
}
* V_202 += V_16 ;
V_5 [ V_13 ] = V_160 ;
V_212 |= ! ! V_160 ;
}
}
}
static void F_173 ( struct V_11 * V_11 , int V_201 ,
struct V_1 * V_2 , unsigned long * V_202 )
{
unsigned long V_5 [ V_224 ] ;
unsigned long V_225 [ V_224 ] ;
unsigned long V_43 ;
enum V_12 V_13 ;
unsigned long V_114 = 0 ;
unsigned long V_226 = V_2 -> V_226 ;
struct V_227 V_228 ;
bool V_229 ;
F_169 ( V_11 , V_201 , V_2 , V_5 , V_202 ) ;
memcpy ( V_225 , V_5 , sizeof( V_5 ) ) ;
V_229 = ( F_1 ( V_2 ) && ! F_101 () &&
V_2 -> V_136 == V_137 ) ;
F_174 ( & V_228 ) ;
while ( V_5 [ V_223 ] || V_5 [ V_200 ] ||
V_5 [ V_199 ] ) {
unsigned long V_230 , V_231 , V_232 ;
unsigned long V_28 ;
F_171 (lru) {
if ( V_5 [ V_13 ] ) {
V_43 = F_22 ( V_5 [ V_13 ] , V_47 ) ;
V_5 [ V_13 ] -= V_43 ;
V_114 += F_168 ( V_13 , V_43 ,
V_11 , V_2 ) ;
}
}
if ( V_114 < V_226 || V_229 )
continue;
V_231 = V_5 [ V_199 ] + V_5 [ V_200 ] ;
V_230 = V_5 [ V_223 ] + V_5 [ V_222 ] ;
if ( ! V_231 || ! V_230 )
break;
if ( V_231 > V_230 ) {
unsigned long V_233 = V_225 [ V_223 ] +
V_225 [ V_222 ] + 1 ;
V_13 = V_234 ;
V_232 = V_230 * 100 / V_233 ;
} else {
unsigned long V_233 = V_225 [ V_199 ] +
V_225 [ V_200 ] + 1 ;
V_13 = V_235 ;
V_232 = V_231 * 100 / V_233 ;
}
V_5 [ V_13 ] = 0 ;
V_5 [ V_13 + V_195 ] = 0 ;
V_13 = ( V_13 == V_235 ) ? V_234 : V_235 ;
V_28 = V_225 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_225 [ V_13 ] * ( 100 - V_232 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_28 ) ;
V_13 += V_195 ;
V_28 = V_225 [ V_13 ] - V_5 [ V_13 ] ;
V_5 [ V_13 ] = V_225 [ V_13 ] * ( 100 - V_232 ) / 100 ;
V_5 [ V_13 ] -= F_22 ( V_5 [ V_13 ] , V_28 ) ;
V_229 = true ;
}
F_175 ( & V_228 ) ;
V_2 -> V_114 += V_114 ;
if ( F_164 ( V_11 ) )
F_162 ( V_47 , V_11 ,
V_2 , V_222 ) ;
F_176 ( V_2 -> V_46 ) ;
}
static bool F_177 ( struct V_1 * V_2 )
{
if ( F_178 ( V_236 ) && V_2 -> V_162 &&
( V_2 -> V_162 > V_237 ||
V_2 -> V_136 < V_137 - 2 ) )
return true ;
return false ;
}
static inline bool F_179 ( struct V_4 * V_4 ,
unsigned long V_114 ,
unsigned long V_28 ,
struct V_1 * V_2 )
{
unsigned long V_238 ;
unsigned long V_239 ;
if ( ! F_177 ( V_2 ) )
return false ;
if ( V_2 -> V_46 & V_240 ) {
if ( ! V_114 && ! V_28 )
return false ;
} else {
if ( ! V_114 )
return false ;
}
V_238 = ( 2UL << V_2 -> V_162 ) ;
V_239 = F_3 ( V_4 , V_7 ) ;
if ( F_4 () > 0 )
V_239 += F_3 ( V_4 , V_9 ) ;
if ( V_2 -> V_114 < V_238 &&
V_239 > V_238 )
return true ;
switch ( F_180 ( V_4 , V_2 -> V_162 , 0 , 0 ) ) {
case V_241 :
case V_242 :
return false ;
default:
return true ;
}
}
static bool F_181 ( struct V_4 * V_4 , struct V_1 * V_2 ,
bool V_243 )
{
unsigned long V_114 , V_28 ;
bool V_244 = false ;
do {
struct V_245 * V_246 = V_2 -> V_3 ;
struct V_247 V_248 = {
. V_4 = V_4 ,
. V_136 = V_2 -> V_136 ,
} ;
unsigned long V_249 = 0 ;
struct V_245 * V_250 ;
V_114 = V_2 -> V_114 ;
V_28 = V_2 -> V_28 ;
V_250 = F_182 ( V_246 , NULL , & V_248 ) ;
do {
unsigned long V_202 ;
struct V_11 * V_11 ;
int V_201 ;
V_11 = F_183 ( V_4 , V_250 ) ;
V_201 = F_184 ( V_250 ) ;
F_173 ( V_11 , V_201 , V_2 , & V_202 ) ;
V_249 += V_202 ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_114 >= V_2 -> V_226 ) {
F_185 ( V_246 , V_250 ) ;
break;
}
V_250 = F_182 ( V_246 , V_250 , & V_248 ) ;
} while ( V_250 );
if ( F_1 ( V_2 ) && V_243 ) {
struct V_251 * V_251 ;
F_29 ( V_2 -> V_46 , F_186 ( V_4 ) ,
V_2 -> V_28 - V_28 ,
V_249 ) ;
V_251 = V_52 -> V_251 ;
if ( V_251 ) {
V_2 -> V_114 +=
V_251 -> V_252 ;
V_251 -> V_252 = 0 ;
}
}
F_187 ( V_2 -> V_46 , V_2 -> V_3 ,
V_2 -> V_28 - V_28 ,
V_2 -> V_114 - V_114 ) ;
if ( V_2 -> V_114 - V_114 )
V_244 = true ;
} while ( F_179 ( V_4 , V_2 -> V_114 - V_114 ,
V_2 -> V_28 - V_28 , V_2 ) );
return V_244 ;
}
static inline bool F_188 ( struct V_4 * V_4 , int V_162 )
{
unsigned long V_253 , V_254 ;
bool V_255 ;
V_253 = F_22 ( F_189 ( V_4 ) , F_190 (
V_4 -> V_256 , V_257 ) ) ;
V_254 = F_170 ( V_4 ) + V_253 + ( 2UL << V_162 ) ;
V_255 = F_191 ( V_4 , 0 , V_254 , 0 , 0 ) ;
if ( F_192 ( V_4 , V_162 ) )
return V_255 ;
if ( F_180 ( V_4 , V_162 , 0 , 0 ) == V_258 )
return false ;
return V_255 ;
}
static bool F_193 ( struct V_259 * V_259 , struct V_1 * V_2 )
{
struct V_260 * V_261 ;
struct V_4 * V_4 ;
unsigned long V_262 ;
unsigned long V_263 ;
T_2 V_264 ;
enum V_265 V_266 = F_194 ( V_2 -> V_46 ) ;
bool V_244 = false ;
V_264 = V_2 -> V_46 ;
if ( V_194 )
V_2 -> V_46 |= V_267 ;
F_195 (zone, z, zonelist,
requested_highidx, sc->nodemask) {
enum V_265 V_268 ;
if ( ! F_196 ( V_4 ) )
continue;
V_268 = V_266 ;
while ( ! F_196 ( V_4 -> V_185 -> V_269 +
V_268 ) )
V_268 -- ;
if ( F_1 ( V_2 ) ) {
if ( ! F_197 ( V_4 ,
V_21 | V_270 ) )
continue;
if ( V_2 -> V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
if ( F_178 ( V_236 ) &&
V_2 -> V_162 > V_237 &&
F_198 ( V_261 ) <= V_266 &&
F_188 ( V_4 , V_2 -> V_162 ) ) {
V_2 -> F_188 = true ;
continue;
}
V_263 = 0 ;
V_262 = F_199 ( V_4 ,
V_2 -> V_162 , V_2 -> V_46 ,
& V_263 ) ;
V_2 -> V_114 += V_262 ;
V_2 -> V_28 += V_263 ;
if ( V_262 )
V_244 = true ;
}
if ( F_181 ( V_4 , V_2 , F_158 ( V_4 ) == V_268 ) )
V_244 = true ;
if ( F_1 ( V_2 ) &&
! V_244 && F_5 ( V_4 ) )
V_244 = true ;
}
V_2 -> V_46 = V_264 ;
return V_244 ;
}
static unsigned long F_200 ( struct V_259 * V_259 ,
struct V_1 * V_2 )
{
unsigned long V_271 = 0 ;
unsigned long V_272 ;
bool V_273 ;
F_201 () ;
if ( F_1 ( V_2 ) )
F_85 ( V_274 ) ;
do {
F_202 ( V_2 -> V_46 , V_2 -> V_3 ,
V_2 -> V_136 ) ;
V_2 -> V_28 = 0 ;
V_273 = F_193 ( V_259 , V_2 ) ;
V_271 += V_2 -> V_28 ;
if ( V_2 -> V_114 >= V_2 -> V_226 )
break;
if ( V_2 -> F_188 )
break;
if ( V_2 -> V_136 < V_137 - 2 )
V_2 -> V_133 = 1 ;
V_272 = V_2 -> V_226 + V_2 -> V_226 / 2 ;
if ( V_271 > V_272 ) {
F_203 ( V_275 ? 0 : V_271 ,
V_276 ) ;
V_2 -> V_133 = 1 ;
}
} while ( -- V_2 -> V_136 >= 0 );
F_204 () ;
if ( V_2 -> V_114 )
return V_2 -> V_114 ;
if ( V_2 -> F_188 )
return 1 ;
if ( V_273 )
return 1 ;
return 0 ;
}
static bool F_205 ( T_8 * V_277 )
{
struct V_4 * V_4 ;
unsigned long V_278 = 0 ;
unsigned long V_109 = 0 ;
int V_279 ;
bool V_280 ;
for ( V_279 = 0 ; V_279 <= V_281 ; V_279 ++ ) {
V_4 = & V_277 -> V_269 [ V_279 ] ;
if ( ! F_196 ( V_4 ) )
continue;
V_278 += F_206 ( V_4 ) ;
V_109 += F_3 ( V_4 , V_219 ) ;
}
if ( ! V_278 )
return true ;
V_280 = V_109 > V_278 / 2 ;
if ( ! V_280 && F_207 ( & V_277 -> V_282 ) ) {
V_277 -> V_268 = F_22 ( V_277 -> V_268 ,
(enum V_265 ) V_281 ) ;
F_208 ( & V_277 -> V_282 ) ;
}
return V_280 ;
}
static bool F_209 ( T_2 V_46 , struct V_259 * V_259 ,
T_9 * V_283 )
{
struct V_260 * V_261 ;
struct V_4 * V_4 ;
T_8 * V_277 = NULL ;
if ( V_52 -> V_19 & V_284 )
goto V_48;
if ( F_151 ( V_52 ) )
goto V_48;
F_195 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_158 ( V_4 ) > V_281 )
continue;
V_277 = V_4 -> V_185 ;
if ( F_205 ( V_277 ) )
goto V_48;
break;
}
if ( ! V_277 )
goto V_48;
F_85 ( V_285 ) ;
if ( ! ( V_46 & V_123 ) ) {
F_210 ( V_277 -> V_286 ,
F_205 ( V_277 ) , V_177 ) ;
goto V_287;
}
F_211 ( V_4 -> V_185 -> V_286 ,
F_205 ( V_277 ) ) ;
V_287:
if ( F_151 ( V_52 ) )
return true ;
V_48:
return false ;
}
unsigned long F_212 ( struct V_259 * V_259 , int V_162 ,
T_2 V_46 , T_9 * V_283 )
{
unsigned long V_114 ;
struct V_1 V_2 = {
. V_226 = V_47 ,
. V_46 = ( V_46 = F_213 ( V_46 ) ) ,
. V_162 = V_162 ,
. V_283 = V_283 ,
. V_136 = V_137 ,
. V_133 = ! V_275 ,
. V_121 = 1 ,
. V_214 = 1 ,
} ;
if ( F_209 ( V_46 , V_259 , V_283 ) )
return 1 ;
F_214 ( V_162 ,
V_2 . V_133 ,
V_46 ) ;
V_114 = F_200 ( V_259 , & V_2 ) ;
F_215 ( V_114 ) ;
return V_114 ;
}
unsigned long F_216 ( struct V_245 * V_250 ,
T_2 V_46 , bool V_288 ,
struct V_4 * V_4 ,
unsigned long * V_28 )
{
struct V_1 V_2 = {
. V_226 = V_47 ,
. V_3 = V_250 ,
. V_133 = ! V_275 ,
. V_121 = 1 ,
. V_214 = ! V_288 ,
} ;
struct V_11 * V_11 = F_183 ( V_4 , V_250 ) ;
int V_201 = F_184 ( V_250 ) ;
unsigned long V_202 ;
V_2 . V_46 = ( V_46 & V_289 ) |
( V_290 & ~ V_289 ) ;
F_217 ( V_2 . V_162 ,
V_2 . V_133 ,
V_2 . V_46 ) ;
F_173 ( V_11 , V_201 , & V_2 , & V_202 ) ;
F_218 ( V_2 . V_114 ) ;
* V_28 = V_2 . V_28 ;
return V_2 . V_114 ;
}
unsigned long F_219 ( struct V_245 * V_250 ,
unsigned long V_161 ,
T_2 V_46 ,
bool V_214 )
{
struct V_259 * V_259 ;
unsigned long V_114 ;
int V_35 ;
struct V_1 V_2 = {
. V_226 = F_220 ( V_161 , V_47 ) ,
. V_46 = ( V_46 & V_289 ) |
( V_290 & ~ V_289 ) ,
. V_3 = V_250 ,
. V_136 = V_137 ,
. V_133 = ! V_275 ,
. V_121 = 1 ,
. V_214 = V_214 ,
} ;
V_35 = F_221 ( V_250 ) ;
V_259 = F_222 ( V_35 ) -> V_291 ;
F_223 ( 0 ,
V_2 . V_133 ,
V_2 . V_46 ) ;
V_114 = F_200 ( V_259 , & V_2 ) ;
F_224 ( V_114 ) ;
return V_114 ;
}
static void F_225 ( struct V_4 * V_4 , struct V_1 * V_2 )
{
struct V_245 * V_250 ;
if ( ! V_198 )
return;
V_250 = F_182 ( NULL , NULL , NULL ) ;
do {
struct V_11 * V_11 = F_183 ( V_4 , V_250 ) ;
if ( F_164 ( V_11 ) )
F_162 ( V_47 , V_11 ,
V_2 , V_222 ) ;
V_250 = F_182 ( NULL , V_250 , NULL ) ;
} while ( V_250 );
}
static bool F_226 ( struct V_4 * V_4 , int V_162 ,
unsigned long V_253 , int V_268 )
{
if ( ! F_191 ( V_4 , V_162 , F_170 ( V_4 ) +
V_253 , V_268 , 0 ) )
return false ;
if ( F_178 ( V_236 ) && V_162 && F_180 ( V_4 ,
V_162 , 0 , V_268 ) == V_258 )
return false ;
return true ;
}
static bool F_227 ( T_8 * V_277 , int V_162 , int V_268 )
{
unsigned long V_256 = 0 ;
unsigned long V_292 = 0 ;
int V_279 ;
for ( V_279 = 0 ; V_279 <= V_268 ; V_279 ++ ) {
struct V_4 * V_4 = V_277 -> V_269 + V_279 ;
if ( ! F_196 ( V_4 ) )
continue;
V_256 += V_4 -> V_256 ;
if ( ! F_5 ( V_4 ) ) {
V_292 += V_4 -> V_256 ;
continue;
}
if ( F_226 ( V_4 , V_162 , 0 , V_279 ) )
V_292 += V_4 -> V_256 ;
else if ( ! V_162 )
return false ;
}
if ( V_162 )
return V_292 >= ( V_256 >> 2 ) ;
else
return true ;
}
static bool F_228 ( T_8 * V_277 , int V_162 , long V_293 ,
int V_268 )
{
if ( V_293 )
return false ;
if ( F_207 ( & V_277 -> V_286 ) )
F_229 ( & V_277 -> V_286 ) ;
return F_227 ( V_277 , V_162 , V_268 ) ;
}
static bool F_230 ( struct V_4 * V_4 ,
int V_268 ,
struct V_1 * V_2 ,
unsigned long * V_294 )
{
int V_295 = V_2 -> V_162 ;
unsigned long V_253 ;
bool V_296 ;
V_2 -> V_226 = F_220 ( V_47 , F_170 ( V_4 ) ) ;
if ( F_178 ( V_236 ) && V_2 -> V_162 &&
F_180 ( V_4 , V_2 -> V_162 , 0 , V_268 )
!= V_258 )
V_295 = 0 ;
V_253 = F_22 ( F_189 ( V_4 ) , F_190 (
V_4 -> V_256 , V_257 ) ) ;
V_296 = ( V_194 && F_231 ( V_4 ) ) ;
if ( ! V_296 && F_226 ( V_4 , V_295 ,
V_253 , V_268 ) )
return true ;
F_181 ( V_4 , V_2 , F_158 ( V_4 ) == V_268 ) ;
* V_294 += V_2 -> V_226 ;
F_232 ( V_125 , & V_4 -> V_19 ) ;
if ( F_5 ( V_4 ) &&
F_226 ( V_4 , V_295 , 0 , V_268 ) ) {
F_232 ( V_183 , & V_4 -> V_19 ) ;
F_232 ( V_131 , & V_4 -> V_19 ) ;
}
return V_2 -> V_28 >= V_2 -> V_226 ;
}
static unsigned long F_233 ( T_8 * V_277 , int V_162 ,
int * V_268 )
{
int V_279 ;
int V_297 = 0 ;
unsigned long V_262 ;
unsigned long V_263 ;
struct V_1 V_2 = {
. V_46 = V_21 ,
. V_162 = V_162 ,
. V_136 = V_137 ,
. V_133 = ! V_275 ,
. V_121 = 1 ,
. V_214 = 1 ,
} ;
F_85 ( V_298 ) ;
do {
unsigned long V_294 = 0 ;
bool V_299 = true ;
bool V_300 = ( V_162 > 0 ) ;
V_2 . V_114 = 0 ;
for ( V_279 = V_277 -> V_301 - 1 ; V_279 >= 0 ; V_279 -- ) {
struct V_4 * V_4 = V_277 -> V_269 + V_279 ;
if ( ! F_196 ( V_4 ) )
continue;
if ( V_2 . V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
F_225 ( V_4 , & V_2 ) ;
if ( V_194 && F_234 ( V_279 ) ) {
V_297 = V_279 ;
break;
}
if ( ! F_226 ( V_4 , V_162 , 0 , 0 ) ) {
V_297 = V_279 ;
break;
} else {
F_232 ( V_183 , & V_4 -> V_19 ) ;
F_232 ( V_131 , & V_4 -> V_19 ) ;
}
}
if ( V_279 < 0 )
goto V_48;
for ( V_279 = 0 ; V_279 <= V_297 ; V_279 ++ ) {
struct V_4 * V_4 = V_277 -> V_269 + V_279 ;
if ( ! F_196 ( V_4 ) )
continue;
if ( V_300 &&
F_235 ( V_4 , V_162 ,
F_189 ( V_4 ) ,
* V_268 , 0 ) )
V_300 = false ;
}
if ( V_2 . V_136 < V_137 - 2 )
V_2 . V_133 = 1 ;
for ( V_279 = 0 ; V_279 <= V_297 ; V_279 ++ ) {
struct V_4 * V_4 = V_277 -> V_269 + V_279 ;
if ( ! F_196 ( V_4 ) )
continue;
if ( V_2 . V_136 != V_137 &&
! F_5 ( V_4 ) )
continue;
V_2 . V_28 = 0 ;
V_263 = 0 ;
V_262 = F_199 ( V_4 ,
V_162 , V_2 . V_46 ,
& V_263 ) ;
V_2 . V_114 += V_262 ;
if ( F_230 ( V_4 , V_297 ,
& V_2 , & V_294 ) )
V_299 = false ;
}
if ( F_207 ( & V_277 -> V_286 ) &&
F_205 ( V_277 ) )
F_236 ( & V_277 -> V_286 ) ;
if ( V_162 && V_2 . V_114 >= 2UL << V_162 )
V_162 = V_2 . V_162 = 0 ;
if ( F_237 () || F_238 () )
break;
if ( V_300 && V_2 . V_114 > V_294 )
F_239 ( V_277 , V_162 ) ;
if ( V_299 || ! V_2 . V_114 )
V_2 . V_136 -- ;
} while ( V_2 . V_136 >= 1 &&
! F_227 ( V_277 , V_162 , * V_268 ) );
V_48:
* V_268 = V_297 ;
return V_162 ;
}
static void F_240 ( T_8 * V_277 , int V_162 , int V_268 )
{
long V_293 = 0 ;
F_241 ( V_302 ) ;
if ( F_242 ( V_52 ) || F_238 () )
return;
F_243 ( & V_277 -> V_282 , & V_302 , V_303 ) ;
if ( F_228 ( V_277 , V_162 , V_293 , V_268 ) ) {
V_293 = F_244 ( V_177 / 10 ) ;
F_245 ( & V_277 -> V_282 , & V_302 ) ;
F_243 ( & V_277 -> V_282 , & V_302 , V_303 ) ;
}
if ( F_228 ( V_277 , V_162 , V_293 , V_268 ) ) {
F_246 ( V_277 -> V_186 ) ;
F_247 ( V_277 , V_304 ) ;
F_248 ( V_277 ) ;
if ( ! F_238 () )
F_249 () ;
F_247 ( V_277 , V_305 ) ;
} else {
if ( V_293 )
F_85 ( V_306 ) ;
else
F_85 ( V_307 ) ;
}
F_245 ( & V_277 -> V_282 , & V_302 ) ;
}
static int F_250 ( void * V_308 )
{
unsigned long V_162 , V_309 ;
unsigned V_310 ;
int V_268 , V_311 ;
int V_312 ;
T_8 * V_277 = ( T_8 * ) V_308 ;
struct V_313 * V_314 = V_52 ;
struct V_251 V_251 = {
. V_252 = 0 ,
} ;
const struct V_315 * V_315 = F_251 ( V_277 -> V_186 ) ;
F_252 ( V_21 ) ;
if ( ! F_253 ( V_315 ) )
F_254 ( V_314 , V_315 ) ;
V_52 -> V_251 = & V_251 ;
V_314 -> V_19 |= V_316 | V_53 | V_317 ;
F_255 () ;
V_162 = V_309 = 0 ;
V_310 = 0 ;
V_268 = V_311 = V_277 -> V_301 - 1 ;
V_312 = V_268 ;
for ( ; ; ) {
bool V_42 ;
if ( V_312 >= V_311 &&
V_310 == V_309 ) {
V_309 = V_277 -> V_318 ;
V_311 = V_277 -> V_268 ;
V_277 -> V_318 = 0 ;
V_277 -> V_268 = V_277 -> V_301 - 1 ;
}
if ( V_162 < V_309 || V_268 > V_311 ) {
V_162 = V_309 ;
V_268 = V_311 ;
} else {
F_240 ( V_277 , V_310 ,
V_312 ) ;
V_162 = V_277 -> V_318 ;
V_268 = V_277 -> V_268 ;
V_309 = V_162 ;
V_311 = V_268 ;
V_277 -> V_318 = 0 ;
V_277 -> V_268 = V_277 -> V_301 - 1 ;
}
V_42 = F_237 () ;
if ( F_238 () )
break;
if ( ! V_42 ) {
F_256 ( V_277 -> V_186 , V_162 ) ;
V_312 = V_268 ;
V_310 = F_233 ( V_277 , V_162 ,
& V_312 ) ;
}
}
V_314 -> V_19 &= ~ ( V_316 | V_53 | V_317 ) ;
V_52 -> V_251 = NULL ;
F_257 () ;
return 0 ;
}
void F_258 ( struct V_4 * V_4 , int V_162 , enum V_265 V_268 )
{
T_8 * V_277 ;
if ( ! F_196 ( V_4 ) )
return;
if ( ! F_197 ( V_4 , V_21 | V_270 ) )
return;
V_277 = V_4 -> V_185 ;
if ( V_277 -> V_318 < V_162 ) {
V_277 -> V_318 = V_162 ;
V_277 -> V_268 = F_22 ( V_277 -> V_268 , V_268 ) ;
}
if ( ! F_207 ( & V_277 -> V_282 ) )
return;
if ( F_226 ( V_4 , V_162 , 0 , 0 ) )
return;
F_259 ( V_277 -> V_186 , F_158 ( V_4 ) , V_162 ) ;
F_208 ( & V_277 -> V_282 ) ;
}
unsigned long F_260 ( unsigned long V_226 )
{
struct V_251 V_251 ;
struct V_1 V_2 = {
. V_226 = V_226 ,
. V_46 = V_290 ,
. V_136 = V_137 ,
. V_133 = 1 ,
. V_121 = 1 ,
. V_214 = 1 ,
. V_184 = 1 ,
} ;
struct V_259 * V_259 = F_261 ( F_262 () , V_2 . V_46 ) ;
struct V_313 * V_308 = V_52 ;
unsigned long V_114 ;
V_308 -> V_19 |= V_316 ;
F_252 ( V_2 . V_46 ) ;
V_251 . V_252 = 0 ;
V_308 -> V_251 = & V_251 ;
V_114 = F_200 ( V_259 , & V_2 ) ;
V_308 -> V_251 = NULL ;
F_257 () ;
V_308 -> V_19 &= ~ V_316 ;
return V_114 ;
}
static int F_263 ( struct V_319 * V_320 , unsigned long V_321 ,
void * V_322 )
{
int V_35 ;
if ( V_321 == V_323 || V_321 == V_324 ) {
F_264 (nid, N_MEMORY) {
T_8 * V_277 = F_222 ( V_35 ) ;
const struct V_315 * V_325 ;
V_325 = F_251 ( V_277 -> V_186 ) ;
if ( F_265 ( V_326 , V_325 ) < V_327 )
F_254 ( V_277 -> F_250 , V_325 ) ;
}
}
return V_328 ;
}
int F_266 ( int V_35 )
{
T_8 * V_277 = F_222 ( V_35 ) ;
int V_42 = 0 ;
if ( V_277 -> F_250 )
return 0 ;
V_277 -> F_250 = F_267 ( F_250 , V_277 , L_3 , V_35 ) ;
if ( F_268 ( V_277 -> F_250 ) ) {
F_55 ( V_329 == V_330 ) ;
F_21 ( L_4 , V_35 ) ;
V_42 = F_269 ( V_277 -> F_250 ) ;
V_277 -> F_250 = NULL ;
}
return V_42 ;
}
void F_270 ( int V_35 )
{
struct V_313 * F_250 = F_222 ( V_35 ) -> F_250 ;
if ( F_250 ) {
F_271 ( F_250 ) ;
F_222 ( V_35 ) -> F_250 = NULL ;
}
}
static int T_10 F_272 ( void )
{
int V_35 ;
F_273 () ;
F_264 (nid, N_MEMORY)
F_266 ( V_35 ) ;
F_274 ( F_263 , 0 ) ;
return 0 ;
}
static inline unsigned long F_275 ( struct V_4 * V_4 )
{
unsigned long V_331 = F_3 ( V_4 , V_332 ) ;
unsigned long V_333 = F_3 ( V_4 , V_7 ) +
F_3 ( V_4 , V_6 ) ;
return ( V_333 > V_331 ) ? ( V_333 - V_331 ) : 0 ;
}
static long F_276 ( struct V_4 * V_4 )
{
long V_334 ;
long V_31 = 0 ;
if ( V_335 & V_336 )
V_334 = F_3 ( V_4 , V_337 ) ;
else
V_334 = F_275 ( V_4 ) ;
if ( ! ( V_335 & V_338 ) )
V_31 += F_3 ( V_4 , V_339 ) ;
if ( F_59 ( V_31 > V_334 ) )
V_31 = V_334 ;
return V_334 - V_31 ;
}
static int F_277 ( struct V_4 * V_4 , T_2 V_46 , unsigned int V_162 )
{
const unsigned long V_161 = 1 << V_162 ;
struct V_313 * V_308 = V_52 ;
struct V_251 V_251 ;
struct V_1 V_2 = {
. V_226 = F_220 ( V_161 , V_47 ) ,
. V_46 = ( V_46 = F_213 ( V_46 ) ) ,
. V_162 = V_162 ,
. V_136 = V_340 ,
. V_133 = ! ! ( V_335 & V_338 ) ,
. V_121 = ! ! ( V_335 & V_336 ) ,
. V_214 = 1 ,
} ;
F_25 () ;
V_308 -> V_19 |= V_316 | V_53 ;
F_252 ( V_46 ) ;
V_251 . V_252 = 0 ;
V_308 -> V_251 = & V_251 ;
if ( F_276 ( V_4 ) > V_4 -> V_341 ) {
do {
F_181 ( V_4 , & V_2 , true ) ;
} while ( V_2 . V_114 < V_161 && -- V_2 . V_136 >= 0 );
}
V_308 -> V_251 = NULL ;
V_52 -> V_19 &= ~ ( V_316 | V_53 ) ;
F_257 () ;
return V_2 . V_114 >= V_161 ;
}
int F_278 ( struct V_4 * V_4 , T_2 V_46 , unsigned int V_162 )
{
int V_186 ;
int V_42 ;
if ( F_276 ( V_4 ) <= V_4 -> V_341 &&
F_3 ( V_4 , V_342 ) <= V_4 -> V_343 )
return V_344 ;
if ( ! F_5 ( V_4 ) )
return V_344 ;
if ( ! ( V_46 & V_345 ) || ( V_52 -> V_19 & V_316 ) )
return V_346 ;
V_186 = F_186 ( V_4 ) ;
if ( F_279 ( V_186 , V_347 ) && V_186 != F_262 () )
return V_346 ;
if ( F_280 ( V_348 , & V_4 -> V_19 ) )
return V_346 ;
V_42 = F_277 ( V_4 , V_46 , V_162 ) ;
F_232 ( V_348 , & V_4 -> V_19 ) ;
if ( ! V_42 )
F_85 ( V_349 ) ;
return V_42 ;
}
int F_79 ( struct V_49 * V_49 )
{
return ! F_281 ( F_40 ( V_49 ) ) && ! F_282 ( V_49 ) ;
}
void F_283 ( struct V_49 * * V_350 , int V_161 )
{
struct V_11 * V_11 ;
struct V_4 * V_4 = NULL ;
int V_351 = 0 ;
int V_352 = 0 ;
int V_279 ;
for ( V_279 = 0 ; V_279 < V_161 ; V_279 ++ ) {
struct V_49 * V_49 = V_350 [ V_279 ] ;
struct V_4 * V_353 ;
V_351 ++ ;
V_353 = F_98 ( V_49 ) ;
if ( V_353 != V_4 ) {
if ( V_4 )
F_66 ( & V_4 -> V_163 ) ;
V_4 = V_353 ;
F_57 ( & V_4 -> V_163 ) ;
}
V_11 = F_134 ( V_49 , V_4 ) ;
if ( ! F_77 ( V_49 ) || ! F_75 ( V_49 ) )
continue;
if ( F_79 ( V_49 ) ) {
enum V_12 V_13 = F_284 ( V_49 ) ;
F_76 ( F_97 ( V_49 ) , V_49 ) ;
F_78 ( V_49 ) ;
F_137 ( V_49 , V_11 , V_354 ) ;
F_141 ( V_49 , V_11 , V_13 ) ;
V_352 ++ ;
}
}
if ( V_4 ) {
F_161 ( V_84 , V_352 ) ;
F_161 ( V_355 , V_351 ) ;
F_66 ( & V_4 -> V_163 ) ;
}
}
