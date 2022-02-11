static bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_3 ;
if ( ! V_5 )
return true ;
#ifdef F_3
if ( F_4 ( V_6 ) )
return true ;
#endif
return false ;
}
static bool F_1 ( struct V_1 * V_2 )
{
return true ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return true ;
}
static unsigned long F_5 ( struct V_7 * V_7 )
{
unsigned long V_8 ;
V_8 = F_6 ( V_7 , V_9 ) +
F_6 ( V_7 , V_10 ) +
F_6 ( V_7 , V_11 ) ;
if ( F_7 () > 0 )
V_8 += F_6 ( V_7 , V_12 ) +
F_6 ( V_7 , V_13 ) +
F_6 ( V_7 , V_14 ) ;
return V_8 ;
}
bool F_8 ( struct V_7 * V_7 )
{
return F_6 ( V_7 , V_15 ) <
F_5 ( V_7 ) * 6 ;
}
unsigned long F_9 ( struct V_16 * V_16 , enum V_17 V_18 )
{
if ( ! F_10 () )
return F_11 ( V_16 , V_18 ) ;
return F_12 ( F_13 ( V_16 ) , V_19 + V_18 ) ;
}
int F_14 ( struct V_20 * V_20 )
{
T_1 V_21 = sizeof( * V_20 -> V_22 ) ;
if ( V_20 -> V_23 & V_24 )
V_21 *= V_25 ;
V_20 -> V_22 = F_15 ( V_21 , V_26 ) ;
if ( ! V_20 -> V_22 )
return - V_27 ;
F_16 ( & V_28 ) ;
F_17 ( & V_20 -> V_29 , & V_30 ) ;
F_18 ( & V_28 ) ;
return 0 ;
}
void F_19 ( struct V_20 * V_20 )
{
F_16 ( & V_28 ) ;
F_20 ( & V_20 -> V_29 ) ;
F_18 ( & V_28 ) ;
F_21 ( V_20 -> V_22 ) ;
}
static unsigned long F_22 ( struct V_31 * V_32 ,
struct V_20 * V_20 ,
unsigned long V_33 ,
unsigned long V_34 )
{
unsigned long V_35 = 0 ;
unsigned long long V_36 ;
long V_37 ;
long V_38 ;
long V_8 ;
long V_39 ;
int V_40 = V_32 -> V_40 ;
long V_41 = V_20 -> V_42 ? V_20 -> V_42
: V_43 ;
V_38 = V_20 -> V_44 ( V_20 , V_32 ) ;
if ( V_38 == 0 )
return 0 ;
V_8 = F_23 ( & V_20 -> V_22 [ V_40 ] , 0 ) ;
V_37 = V_8 ;
V_36 = ( 4 * V_33 ) / V_20 -> V_45 ;
V_36 *= V_38 ;
F_24 ( V_36 , V_34 + 1 ) ;
V_37 += V_36 ;
if ( V_37 < 0 ) {
F_25 ( L_1 ,
V_20 -> V_46 , V_37 ) ;
V_37 = V_38 ;
}
if ( V_36 < V_38 / 4 )
V_37 = F_26 ( V_37 , V_38 / 2 ) ;
if ( V_37 > V_38 * 2 )
V_37 = V_38 * 2 ;
F_27 ( V_20 , V_32 , V_8 ,
V_33 , V_34 ,
V_38 , V_36 , V_37 ) ;
while ( V_37 >= V_41 ||
V_37 >= V_38 ) {
unsigned long V_47 ;
unsigned long V_48 = F_26 ( V_41 , V_37 ) ;
V_32 -> V_48 = V_48 ;
V_47 = V_20 -> V_46 ( V_20 , V_32 ) ;
if ( V_47 == V_49 )
break;
V_35 += V_47 ;
F_28 ( V_50 , V_48 ) ;
V_37 -= V_48 ;
F_29 () ;
}
if ( V_37 > 0 )
V_39 = F_30 ( V_37 ,
& V_20 -> V_22 [ V_40 ] ) ;
else
V_39 = F_31 ( & V_20 -> V_22 [ V_40 ] ) ;
F_32 ( V_20 , V_40 , V_35 , V_8 , V_39 , V_37 ) ;
return V_35 ;
}
static unsigned long F_33 ( T_2 V_51 , int V_40 ,
struct V_4 * V_5 ,
unsigned long V_33 ,
unsigned long V_34 )
{
struct V_20 * V_20 ;
unsigned long V_35 = 0 ;
if ( V_5 && ( ! F_34 () || ! F_35 ( V_5 ) ) )
return 0 ;
if ( V_33 == 0 )
V_33 = V_52 ;
if ( ! F_36 ( & V_28 ) ) {
V_35 = 1 ;
goto V_53;
}
F_37 (shrinker, &shrinker_list, list) {
struct V_31 V_2 = {
. V_51 = V_51 ,
. V_40 = V_40 ,
. V_5 = V_5 ,
} ;
if ( F_34 () &&
! ! V_5 != ! ! ( V_20 -> V_23 & V_54 ) )
continue;
if ( ! ( V_20 -> V_23 & V_24 ) )
V_2 . V_40 = 0 ;
V_35 += F_22 ( & V_2 , V_20 , V_33 , V_34 ) ;
}
F_38 ( & V_28 ) ;
V_53:
F_29 () ;
return V_35 ;
}
void F_39 ( int V_40 )
{
unsigned long V_35 ;
do {
struct V_4 * V_5 = NULL ;
V_35 = 0 ;
do {
V_35 += F_33 ( V_26 , V_40 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_40 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_35 > 10 );
}
void F_41 ( void )
{
int V_40 ;
F_42 (nid)
F_39 ( V_40 ) ;
}
static inline int F_43 ( struct V_55 * V_55 )
{
return F_44 ( V_55 ) - F_45 ( V_55 ) == 2 ;
}
static int F_46 ( struct V_56 * V_56 , struct V_1 * V_2 )
{
if ( V_57 -> V_23 & V_58 )
return 1 ;
if ( ! F_47 ( V_56 ) )
return 1 ;
if ( F_48 ( V_56 ) == V_57 -> V_59 )
return 1 ;
return 0 ;
}
static void F_49 ( struct V_60 * V_61 ,
struct V_55 * V_55 , int error )
{
F_50 ( V_55 ) ;
if ( F_51 ( V_55 ) == V_61 )
F_52 ( V_61 , error ) ;
F_53 ( V_55 ) ;
}
static T_3 F_54 ( struct V_55 * V_55 , struct V_60 * V_61 ,
struct V_1 * V_2 )
{
if ( ! F_43 ( V_55 ) )
return V_62 ;
if ( ! V_61 ) {
if ( F_45 ( V_55 ) ) {
if ( F_55 ( V_55 ) ) {
F_56 ( V_55 ) ;
F_57 ( L_2 , V_63 ) ;
return V_64 ;
}
}
return V_62 ;
}
if ( V_61 -> V_65 -> V_66 == NULL )
return V_67 ;
if ( ! F_46 ( V_61 -> V_68 , V_2 ) )
return V_62 ;
if ( F_58 ( V_55 ) ) {
int V_69 ;
struct V_70 V_71 = {
. V_72 = V_73 ,
. V_74 = V_52 ,
. V_75 = 0 ,
. V_76 = V_77 ,
. V_78 = 1 ,
} ;
F_59 ( V_55 ) ;
V_69 = V_61 -> V_65 -> V_66 ( V_55 , & V_71 ) ;
if ( V_69 < 0 )
F_49 ( V_61 , V_55 , V_69 ) ;
if ( V_69 == V_79 ) {
F_60 ( V_55 ) ;
return V_67 ;
}
if ( ! F_61 ( V_55 ) ) {
F_60 ( V_55 ) ;
}
F_62 ( V_55 ) ;
F_63 ( V_55 , V_80 ) ;
return V_81 ;
}
return V_64 ;
}
static int F_64 ( struct V_60 * V_61 , struct V_55 * V_55 ,
bool V_82 )
{
unsigned long V_23 ;
F_65 ( ! F_66 ( V_55 ) ) ;
F_65 ( V_61 != F_51 ( V_55 ) ) ;
F_67 ( & V_61 -> V_83 , V_23 ) ;
if ( ! F_68 ( V_55 , 2 ) )
goto V_84;
if ( F_69 ( F_70 ( V_55 ) ) ) {
F_71 ( V_55 , 2 ) ;
goto V_84;
}
if ( F_72 ( V_55 ) ) {
T_4 V_85 = { . V_86 = F_73 (page) } ;
F_74 ( V_55 , V_85 ) ;
F_75 ( V_55 ) ;
F_76 ( & V_61 -> V_83 , V_23 ) ;
F_77 ( V_85 ) ;
} else {
void (* F_78)( struct V_55 * );
void * V_87 = NULL ;
F_78 = V_61 -> V_65 -> F_78 ;
if ( V_82 && F_79 ( V_55 ) &&
! F_80 ( V_61 ) && ! F_81 ( V_61 ) )
V_87 = F_82 ( V_61 , V_55 ) ;
F_83 ( V_55 , V_87 ) ;
F_76 ( & V_61 -> V_83 , V_23 ) ;
if ( F_78 != NULL )
F_78 ( V_55 ) ;
}
return 1 ;
V_84:
F_76 ( & V_61 -> V_83 , V_23 ) ;
return 0 ;
}
int F_84 ( struct V_60 * V_61 , struct V_55 * V_55 )
{
if ( F_64 ( V_61 , V_55 , false ) ) {
F_71 ( V_55 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_85 ( struct V_55 * V_55 )
{
bool V_88 ;
int V_89 = F_86 ( V_55 ) ;
F_87 ( F_88 ( V_55 ) , V_55 ) ;
V_90:
F_89 ( V_55 ) ;
if ( F_90 ( V_55 ) ) {
V_88 = false ;
F_91 ( V_55 ) ;
} else {
V_88 = true ;
F_92 ( V_55 ) ;
F_93 () ;
}
if ( V_88 && F_90 ( V_55 ) ) {
if ( ! F_94 ( V_55 ) ) {
F_95 ( V_55 ) ;
goto V_90;
}
}
if ( V_89 && ! V_88 )
F_96 ( V_91 ) ;
else if ( ! V_89 && V_88 )
F_96 ( V_92 ) ;
F_95 ( V_55 ) ;
}
static enum V_93 F_97 ( struct V_55 * V_55 ,
struct V_1 * V_2 )
{
int V_94 , V_95 ;
unsigned long V_96 ;
V_94 = F_98 ( V_55 , 1 , V_2 -> V_3 ,
& V_96 ) ;
V_95 = F_99 ( V_55 ) ;
if ( V_96 & V_97 )
return V_98 ;
if ( V_94 ) {
if ( F_100 ( V_55 ) )
return V_99 ;
F_101 ( V_55 ) ;
if ( V_95 || V_94 > 1 )
return V_99 ;
if ( V_96 & V_100 )
return V_99 ;
return V_101 ;
}
if ( V_95 && ! F_100 ( V_55 ) )
return V_102 ;
return V_98 ;
}
static void F_102 ( struct V_55 * V_55 ,
bool * V_103 , bool * V_104 )
{
struct V_60 * V_61 ;
if ( ! F_79 ( V_55 ) ) {
* V_103 = false ;
* V_104 = false ;
return;
}
* V_103 = F_70 ( V_55 ) ;
* V_104 = F_61 ( V_55 ) ;
if ( ! F_45 ( V_55 ) )
return;
V_61 = F_51 ( V_55 ) ;
if ( V_61 && V_61 -> V_65 -> V_105 )
V_61 -> V_65 -> V_105 ( V_55 , V_103 , V_104 ) ;
}
static unsigned long F_103 ( struct V_106 * V_107 ,
struct V_7 * V_7 ,
struct V_1 * V_2 ,
enum V_108 V_108 ,
unsigned long * V_109 ,
unsigned long * V_110 ,
unsigned long * V_111 ,
unsigned long * V_112 ,
unsigned long * V_113 ,
bool V_114 )
{
F_104 ( V_115 ) ;
F_104 ( V_116 ) ;
int V_117 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
unsigned long V_121 = 0 ;
unsigned long V_122 = 0 ;
unsigned long V_123 = 0 ;
F_29 () ;
while ( ! F_105 ( V_107 ) ) {
struct V_60 * V_61 ;
struct V_55 * V_55 ;
int V_124 ;
enum V_93 V_125 = V_102 ;
bool V_103 , V_104 ;
bool V_126 = false ;
int V_47 = V_127 ;
F_29 () ;
V_55 = F_106 ( V_107 ) ;
F_20 ( & V_55 -> V_18 ) ;
if ( ! F_107 ( V_55 ) )
goto V_128;
F_87 ( F_108 ( V_55 ) , V_55 ) ;
F_87 ( F_109 ( V_55 ) != V_7 , V_55 ) ;
V_2 -> V_33 ++ ;
if ( F_69 ( ! F_90 ( V_55 ) ) )
goto V_129;
if ( ! V_2 -> V_130 && F_110 ( V_55 ) )
goto V_131;
if ( F_110 ( V_55 ) || F_72 ( V_55 ) )
V_2 -> V_33 ++ ;
V_124 = ( V_2 -> V_51 & V_132 ) ||
( F_72 ( V_55 ) && ( V_2 -> V_51 & V_133 ) ) ;
F_102 ( V_55 , & V_103 , & V_104 ) ;
if ( V_103 || V_104 )
V_119 ++ ;
if ( V_103 && ! V_104 )
V_118 ++ ;
V_61 = F_51 ( V_55 ) ;
if ( ( ( V_103 || V_104 ) && V_61 &&
F_47 ( V_61 -> V_68 ) ) ||
( V_104 && F_111 ( V_55 ) ) )
V_120 ++ ;
if ( F_61 ( V_55 ) ) {
if ( F_112 () &&
F_111 ( V_55 ) &&
F_113 ( V_134 , & V_7 -> V_23 ) ) {
V_123 ++ ;
goto V_131;
} else if ( F_2 ( V_2 ) ||
! F_111 ( V_55 ) || ! V_124 ) {
F_59 ( V_55 ) ;
V_122 ++ ;
goto V_131;
} else {
F_53 ( V_55 ) ;
F_114 ( V_55 ) ;
F_17 ( & V_55 -> V_18 , V_107 ) ;
continue;
}
}
if ( ! V_114 )
V_125 = F_97 ( V_55 , V_2 ) ;
switch ( V_125 ) {
case V_99 :
goto V_135;
case V_101 :
goto V_131;
case V_98 :
case V_102 :
;
}
if ( F_115 ( V_55 ) && ! F_72 ( V_55 ) ) {
if ( ! ( V_2 -> V_51 & V_133 ) )
goto V_131;
if ( ! F_116 ( V_55 , V_107 ) )
goto V_135;
V_126 = true ;
V_124 = 1 ;
V_61 = F_51 ( V_55 ) ;
}
if ( F_110 ( V_55 ) && V_61 ) {
switch ( V_47 = F_117 ( V_55 , V_126 ?
( V_108 | V_136 | V_137 ) :
( V_108 | V_136 ) ) ) {
case V_138 :
goto V_135;
case V_139 :
goto V_131;
case V_140 :
goto V_129;
case V_141 :
goto V_126;
case V_127 :
;
}
}
if ( F_70 ( V_55 ) ) {
if ( F_79 ( V_55 ) &&
( ! F_112 () ||
! F_113 ( V_142 , & V_7 -> V_23 ) ) ) {
F_63 ( V_55 , V_143 ) ;
F_59 ( V_55 ) ;
goto V_131;
}
if ( V_125 == V_102 )
goto V_131;
if ( ! V_124 )
goto V_131;
if ( ! V_2 -> V_144 )
goto V_131;
F_118 () ;
switch ( F_54 ( V_55 , V_61 , V_2 ) ) {
case V_62 :
goto V_131;
case V_67 :
goto V_135;
case V_81 :
if ( F_61 ( V_55 ) )
goto V_128;
if ( F_70 ( V_55 ) )
goto V_128;
if ( ! F_107 ( V_55 ) )
goto V_128;
if ( F_70 ( V_55 ) || F_61 ( V_55 ) )
goto V_131;
V_61 = F_51 ( V_55 ) ;
case V_64 :
;
}
}
if ( F_45 ( V_55 ) ) {
if ( ! F_119 ( V_55 , V_2 -> V_51 ) )
goto V_135;
if ( ! V_61 && F_44 ( V_55 ) == 1 ) {
F_53 ( V_55 ) ;
if ( F_120 ( V_55 ) )
goto V_145;
else {
V_121 ++ ;
continue;
}
}
}
V_126:
if ( ! V_61 || ! F_64 ( V_61 , V_55 , true ) )
goto V_131;
F_121 ( V_55 ) ;
V_145:
if ( V_47 == V_141 )
F_96 ( V_146 ) ;
V_121 ++ ;
F_122 ( & V_55 -> V_18 , & V_116 ) ;
continue;
V_129:
if ( F_72 ( V_55 ) )
F_123 ( V_55 ) ;
F_53 ( V_55 ) ;
F_122 ( & V_55 -> V_18 , & V_115 ) ;
continue;
V_135:
if ( F_72 ( V_55 ) && F_124 ( V_55 ) )
F_123 ( V_55 ) ;
F_87 ( F_108 ( V_55 ) , V_55 ) ;
F_125 ( V_55 ) ;
V_117 ++ ;
V_131:
F_53 ( V_55 ) ;
V_128:
F_122 ( & V_55 -> V_18 , & V_115 ) ;
F_87 ( F_88 ( V_55 ) || F_86 ( V_55 ) , V_55 ) ;
}
F_126 ( & V_116 ) ;
F_127 () ;
F_128 ( & V_116 , true ) ;
F_129 ( & V_115 , V_107 ) ;
F_28 ( V_147 , V_117 ) ;
* V_109 += V_119 ;
* V_111 += V_120 ;
* V_110 += V_118 ;
* V_112 += V_122 ;
* V_113 += V_123 ;
return V_121 ;
}
unsigned long F_130 ( struct V_7 * V_7 ,
struct V_106 * V_107 )
{
struct V_1 V_2 = {
. V_51 = V_26 ,
. V_148 = V_149 ,
. V_130 = 1 ,
} ;
unsigned long V_47 , V_150 , V_151 , V_152 , V_153 , V_154 ;
struct V_55 * V_55 , * V_155 ;
F_104 ( V_156 ) ;
F_131 (page, next, page_list, lru) {
if ( F_79 ( V_55 ) && ! F_70 ( V_55 ) &&
! F_132 ( V_55 ) ) {
F_133 ( V_55 ) ;
F_134 ( & V_55 -> V_18 , & V_156 ) ;
}
}
V_47 = F_103 ( & V_156 , V_7 , & V_2 ,
V_157 | V_158 ,
& V_150 , & V_151 , & V_152 , & V_153 , & V_154 , true ) ;
F_129 ( & V_156 , V_107 ) ;
F_135 ( V_7 , V_11 , - V_47 ) ;
return V_47 ;
}
int F_136 ( struct V_55 * V_55 , T_5 V_159 )
{
int V_47 = - V_160 ;
if ( ! F_88 ( V_55 ) )
return V_47 ;
if ( F_86 ( V_55 ) && ! ( V_159 & V_161 ) )
return V_47 ;
V_47 = - V_162 ;
if ( V_159 & ( V_163 | V_164 ) ) {
if ( F_61 ( V_55 ) )
return V_47 ;
if ( F_70 ( V_55 ) ) {
struct V_60 * V_61 ;
if ( V_159 & V_163 )
return V_47 ;
V_61 = F_51 ( V_55 ) ;
if ( V_61 && ! V_61 -> V_65 -> V_165 )
return V_47 ;
}
}
if ( ( V_159 & V_166 ) && F_110 ( V_55 ) )
return V_47 ;
if ( F_137 ( F_138 ( V_55 ) ) ) {
F_139 ( V_55 ) ;
V_47 = 0 ;
}
return V_47 ;
}
static unsigned long F_140 ( unsigned long V_48 ,
struct V_16 * V_16 , struct V_106 * V_167 ,
unsigned long * V_33 , struct V_1 * V_2 ,
T_5 V_159 , enum V_17 V_18 )
{
struct V_106 * V_168 = & V_16 -> V_169 [ V_18 ] ;
unsigned long V_170 = 0 ;
unsigned long V_171 ;
for ( V_171 = 0 ; V_171 < V_48 && V_170 < V_48 &&
! F_105 ( V_168 ) ; V_171 ++ ) {
struct V_55 * V_55 ;
int V_172 ;
V_55 = F_106 ( V_168 ) ;
F_141 ( V_55 , V_168 , V_23 ) ;
F_87 ( ! F_88 ( V_55 ) , V_55 ) ;
switch ( F_136 ( V_55 , V_159 ) ) {
case 0 :
V_172 = F_142 ( V_55 ) ;
F_143 ( V_16 , V_18 , - V_172 ) ;
F_134 ( & V_55 -> V_18 , V_167 ) ;
V_170 += V_172 ;
break;
case - V_162 :
F_134 ( & V_55 -> V_18 , V_168 ) ;
continue;
default:
F_144 () ;
}
}
* V_33 = V_171 ;
F_145 ( V_2 -> V_173 , V_48 , V_171 ,
V_170 , V_159 , F_146 ( V_18 ) ) ;
return V_170 ;
}
int F_94 ( struct V_55 * V_55 )
{
int V_47 = - V_162 ;
F_87 ( ! F_44 ( V_55 ) , V_55 ) ;
F_147 ( F_148 ( V_55 ) , L_3 ) ;
if ( F_88 ( V_55 ) ) {
struct V_7 * V_7 = F_109 ( V_55 ) ;
struct V_16 * V_16 ;
F_149 ( & V_7 -> V_174 ) ;
V_16 = F_150 ( V_55 , V_7 ) ;
if ( F_88 ( V_55 ) ) {
int V_18 = F_151 ( V_55 ) ;
F_152 ( V_55 ) ;
F_139 ( V_55 ) ;
F_153 ( V_55 , V_16 , V_18 ) ;
V_47 = 0 ;
}
F_154 ( & V_7 -> V_174 ) ;
}
return V_47 ;
}
static int F_155 ( struct V_7 * V_7 , int V_175 ,
struct V_1 * V_2 )
{
unsigned long V_176 , V_177 ;
if ( F_112 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_175 ) {
V_176 = F_12 ( V_7 , V_10 ) ;
V_177 = F_12 ( V_7 , V_11 ) ;
} else {
V_176 = F_12 ( V_7 , V_13 ) ;
V_177 = F_12 ( V_7 , V_14 ) ;
}
if ( ( V_2 -> V_51 & ( V_133 | V_132 ) ) == ( V_133 | V_132 ) )
V_176 >>= 3 ;
return V_177 > V_176 ;
}
static T_6 void
F_156 ( struct V_16 * V_16 , struct V_106 * V_107 )
{
struct V_178 * V_179 = & V_16 -> V_179 ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
F_104 ( V_180 ) ;
while ( ! F_105 ( V_107 ) ) {
struct V_55 * V_55 = F_106 ( V_107 ) ;
int V_18 ;
F_87 ( F_88 ( V_55 ) , V_55 ) ;
F_20 ( & V_55 -> V_18 ) ;
if ( F_69 ( ! F_90 ( V_55 ) ) ) {
F_154 ( & V_7 -> V_174 ) ;
F_85 ( V_55 ) ;
F_149 ( & V_7 -> V_174 ) ;
continue;
}
V_16 = F_150 ( V_55 , V_7 ) ;
F_157 ( V_55 ) ;
V_18 = F_151 ( V_55 ) ;
F_158 ( V_55 , V_16 , V_18 ) ;
if ( F_159 ( V_18 ) ) {
int V_175 = F_146 ( V_18 ) ;
int V_181 = F_142 ( V_55 ) ;
V_179 -> V_182 [ V_175 ] += V_181 ;
}
if ( F_120 ( V_55 ) ) {
F_160 ( V_55 ) ;
F_161 ( V_55 ) ;
F_153 ( V_55 , V_16 , V_18 ) ;
if ( F_69 ( F_162 ( V_55 ) ) ) {
F_154 ( & V_7 -> V_174 ) ;
F_163 ( V_55 ) ;
( * F_164 ( V_55 ) ) ( V_55 ) ;
F_149 ( & V_7 -> V_174 ) ;
} else
F_122 ( & V_55 -> V_18 , & V_180 ) ;
}
}
F_129 ( & V_180 , V_107 ) ;
}
static int F_165 ( void )
{
return ! ( V_57 -> V_23 & V_183 ) ||
V_57 -> V_59 == NULL ||
F_166 ( V_57 -> V_59 ) ;
}
static T_6 unsigned long
F_167 ( unsigned long V_48 , struct V_16 * V_16 ,
struct V_1 * V_2 , enum V_17 V_18 )
{
F_104 ( V_107 ) ;
unsigned long V_33 ;
unsigned long V_121 = 0 ;
unsigned long V_170 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_122 = 0 ;
unsigned long V_123 = 0 ;
T_5 V_184 = 0 ;
int V_175 = F_146 ( V_18 ) ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
struct V_178 * V_179 = & V_16 -> V_179 ;
while ( F_69 ( F_155 ( V_7 , V_175 , V_2 ) ) ) {
F_168 ( V_185 , V_186 / 10 ) ;
if ( F_169 ( V_57 ) )
return V_52 ;
}
F_170 () ;
if ( ! V_2 -> V_130 )
V_184 |= V_166 ;
if ( ! V_2 -> V_144 )
V_184 |= V_163 ;
F_149 ( & V_7 -> V_174 ) ;
V_170 = F_140 ( V_48 , V_16 , & V_107 ,
& V_33 , V_2 , V_184 , V_18 ) ;
F_171 ( V_7 , V_19 + V_18 , - V_170 ) ;
F_171 ( V_7 , V_14 + V_175 , V_170 ) ;
if ( F_1 ( V_2 ) ) {
F_171 ( V_7 , V_15 , V_33 ) ;
if ( F_112 () )
F_172 ( V_187 , V_7 , V_33 ) ;
else
F_172 ( V_188 , V_7 , V_33 ) ;
}
F_154 ( & V_7 -> V_174 ) ;
if ( V_170 == 0 )
return 0 ;
V_121 = F_103 ( & V_107 , V_7 , V_2 , V_157 ,
& V_119 , & V_118 , & V_120 ,
& V_122 , & V_123 ,
false ) ;
F_149 ( & V_7 -> V_174 ) ;
V_179 -> V_189 [ V_175 ] += V_170 ;
if ( F_1 ( V_2 ) ) {
if ( F_112 () )
F_172 ( V_190 , V_7 ,
V_121 ) ;
else
F_172 ( V_191 , V_7 ,
V_121 ) ;
}
F_156 ( V_16 , & V_107 ) ;
F_171 ( V_7 , V_14 + V_175 , - V_170 ) ;
F_154 ( & V_7 -> V_174 ) ;
F_126 ( & V_107 ) ;
F_128 ( & V_107 , true ) ;
if ( V_122 && V_122 == V_170 )
F_173 ( V_134 , & V_7 -> V_23 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_119 && V_119 == V_120 )
F_173 ( V_192 , & V_7 -> V_23 ) ;
if ( V_118 == V_170 )
F_173 ( V_142 , & V_7 -> V_23 ) ;
if ( V_123 && F_165 () )
F_168 ( V_185 , V_186 / 10 ) ;
}
if ( ! V_2 -> V_193 && ! F_112 () &&
F_165 () )
F_174 ( V_7 , V_185 , V_186 / 10 ) ;
F_175 ( V_7 , V_33 , V_121 ,
V_2 -> V_148 , V_175 ) ;
return V_121 ;
}
static void F_176 ( struct V_16 * V_16 ,
struct V_106 * V_29 ,
struct V_106 * V_180 ,
enum V_17 V_18 )
{
struct V_7 * V_7 = F_13 ( V_16 ) ;
unsigned long V_194 = 0 ;
struct V_55 * V_55 ;
int V_172 ;
while ( ! F_105 ( V_29 ) ) {
V_55 = F_106 ( V_29 ) ;
V_16 = F_150 ( V_55 , V_7 ) ;
F_87 ( F_88 ( V_55 ) , V_55 ) ;
F_157 ( V_55 ) ;
V_172 = F_142 ( V_55 ) ;
F_143 ( V_16 , V_18 , V_172 ) ;
F_134 ( & V_55 -> V_18 , & V_16 -> V_169 [ V_18 ] ) ;
V_194 += V_172 ;
if ( F_120 ( V_55 ) ) {
F_160 ( V_55 ) ;
F_161 ( V_55 ) ;
F_153 ( V_55 , V_16 , V_18 ) ;
if ( F_69 ( F_162 ( V_55 ) ) ) {
F_154 ( & V_7 -> V_174 ) ;
F_163 ( V_55 ) ;
( * F_164 ( V_55 ) ) ( V_55 ) ;
F_149 ( & V_7 -> V_174 ) ;
} else
F_122 ( & V_55 -> V_18 , V_180 ) ;
}
}
F_171 ( V_7 , V_19 + V_18 , V_194 ) ;
if ( ! F_159 ( V_18 ) )
F_177 ( V_195 , V_194 ) ;
}
static void F_178 ( unsigned long V_48 ,
struct V_16 * V_16 ,
struct V_1 * V_2 ,
enum V_17 V_18 )
{
unsigned long V_170 ;
unsigned long V_33 ;
unsigned long V_96 ;
F_104 ( V_196 ) ;
F_104 ( V_197 ) ;
F_104 ( V_198 ) ;
struct V_55 * V_55 ;
struct V_178 * V_179 = & V_16 -> V_179 ;
unsigned long V_199 = 0 ;
T_5 V_184 = 0 ;
int V_175 = F_146 ( V_18 ) ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
F_170 () ;
if ( ! V_2 -> V_130 )
V_184 |= V_166 ;
if ( ! V_2 -> V_144 )
V_184 |= V_163 ;
F_149 ( & V_7 -> V_174 ) ;
V_170 = F_140 ( V_48 , V_16 , & V_196 ,
& V_33 , V_2 , V_184 , V_18 ) ;
if ( F_1 ( V_2 ) )
F_171 ( V_7 , V_15 , V_33 ) ;
V_179 -> V_189 [ V_175 ] += V_170 ;
F_172 ( V_200 , V_7 , V_33 ) ;
F_171 ( V_7 , V_19 + V_18 , - V_170 ) ;
F_171 ( V_7 , V_14 + V_175 , V_170 ) ;
F_154 ( & V_7 -> V_174 ) ;
while ( ! F_105 ( & V_196 ) ) {
F_29 () ;
V_55 = F_106 ( & V_196 ) ;
F_20 ( & V_55 -> V_18 ) ;
if ( F_69 ( ! F_90 ( V_55 ) ) ) {
F_85 ( V_55 ) ;
continue;
}
if ( F_69 ( V_201 ) ) {
if ( F_45 ( V_55 ) && F_107 ( V_55 ) ) {
if ( F_45 ( V_55 ) )
F_119 ( V_55 , 0 ) ;
F_53 ( V_55 ) ;
}
}
if ( F_98 ( V_55 , 0 , V_2 -> V_3 ,
& V_96 ) ) {
V_199 += F_142 ( V_55 ) ;
if ( ( V_96 & V_100 ) && F_79 ( V_55 ) ) {
F_122 ( & V_55 -> V_18 , & V_197 ) ;
continue;
}
}
F_133 ( V_55 ) ;
F_122 ( & V_55 -> V_18 , & V_198 ) ;
}
F_149 ( & V_7 -> V_174 ) ;
V_179 -> V_182 [ V_175 ] += V_199 ;
F_176 ( V_16 , & V_197 , & V_196 , V_18 ) ;
F_176 ( V_16 , & V_198 , & V_196 , V_18 - V_202 ) ;
F_171 ( V_7 , V_14 + V_175 , - V_170 ) ;
F_154 ( & V_7 -> V_174 ) ;
F_126 ( & V_196 ) ;
F_128 ( & V_196 , true ) ;
}
static bool F_179 ( struct V_7 * V_7 )
{
unsigned long V_203 , V_176 ;
V_203 = F_12 ( V_7 , V_12 ) ;
V_176 = F_12 ( V_7 , V_13 ) ;
return V_176 * V_7 -> V_204 < V_203 ;
}
static bool F_180 ( struct V_16 * V_16 )
{
if ( ! V_205 )
return false ;
if ( ! F_10 () )
return F_181 ( V_16 ) ;
return F_179 ( F_13 ( V_16 ) ) ;
}
static inline bool F_180 ( struct V_16 * V_16 )
{
return false ;
}
static bool F_182 ( struct V_16 * V_16 )
{
unsigned long V_176 ;
unsigned long V_203 ;
V_176 = F_9 ( V_16 , V_206 ) ;
V_203 = F_9 ( V_16 , V_207 ) ;
return V_203 > V_176 ;
}
static bool F_183 ( struct V_16 * V_16 , enum V_17 V_18 )
{
if ( F_146 ( V_18 ) )
return F_182 ( V_16 ) ;
else
return F_180 ( V_16 ) ;
}
static unsigned long F_184 ( enum V_17 V_18 , unsigned long V_48 ,
struct V_16 * V_16 , struct V_1 * V_2 )
{
if ( F_159 ( V_18 ) ) {
if ( F_183 ( V_16 , V_18 ) )
F_178 ( V_48 , V_16 , V_2 , V_18 ) ;
return 0 ;
}
return F_167 ( V_48 , V_16 , V_2 , V_18 ) ;
}
static void F_185 ( struct V_16 * V_16 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_208 )
{
int V_209 = F_186 ( V_5 ) ;
struct V_178 * V_179 = & V_16 -> V_179 ;
T_7 V_210 [ 2 ] ;
T_7 V_211 = 0 ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
unsigned long V_212 , V_213 ;
enum V_214 V_214 ;
unsigned long V_215 , V_175 ;
bool V_216 = false ;
unsigned long V_217 , V_218 ;
enum V_17 V_18 ;
bool V_219 ;
int V_220 ;
if ( F_112 () ) {
if ( ! F_8 ( V_7 ) )
V_216 = true ;
if ( ! F_35 ( V_5 ) )
V_216 = true ;
}
if ( ! F_1 ( V_2 ) )
V_216 = true ;
if ( ! V_2 -> V_221 || F_187 ( V_5 ) <= 0 ) {
V_214 = V_222 ;
goto V_53;
}
if ( ! F_1 ( V_2 ) && ! V_209 ) {
V_214 = V_222 ;
goto V_53;
}
if ( ! V_2 -> V_148 && V_209 ) {
V_214 = V_223 ;
goto V_53;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_224 ;
unsigned long V_225 ;
V_225 = F_12 ( V_7 , V_226 ) ;
V_224 = F_12 ( V_7 , V_9 ) +
F_12 ( V_7 , V_10 ) ;
if ( F_69 ( V_224 + V_225 <= F_188 ( V_7 ) ) ) {
V_214 = V_227 ;
goto V_53;
}
}
if ( ! F_182 ( V_16 ) &&
F_9 ( V_16 , V_206 ) >> V_2 -> V_148 ) {
V_214 = V_222 ;
goto V_53;
}
V_214 = V_228 ;
V_212 = V_209 ;
V_213 = 200 - V_212 ;
V_215 = F_9 ( V_16 , V_229 ) +
F_9 ( V_16 , V_230 ) ;
V_175 = F_9 ( V_16 , V_207 ) +
F_9 ( V_16 , V_206 ) ;
F_149 ( & V_7 -> V_174 ) ;
if ( F_69 ( V_179 -> V_189 [ 0 ] > V_215 / 4 ) ) {
V_179 -> V_189 [ 0 ] /= 2 ;
V_179 -> V_182 [ 0 ] /= 2 ;
}
if ( F_69 ( V_179 -> V_189 [ 1 ] > V_175 / 4 ) ) {
V_179 -> V_189 [ 1 ] /= 2 ;
V_179 -> V_182 [ 1 ] /= 2 ;
}
V_217 = V_212 * ( V_179 -> V_189 [ 0 ] + 1 ) ;
V_217 /= V_179 -> V_182 [ 0 ] + 1 ;
V_218 = V_213 * ( V_179 -> V_189 [ 1 ] + 1 ) ;
V_218 /= V_179 -> V_182 [ 1 ] + 1 ;
F_154 ( & V_7 -> V_174 ) ;
V_210 [ 0 ] = V_217 ;
V_210 [ 1 ] = V_218 ;
V_211 = V_217 + V_218 + 1 ;
V_53:
V_219 = false ;
for ( V_220 = 0 ; ! V_219 && V_220 < 2 ; V_220 ++ ) {
* V_208 = 0 ;
F_189 (lru) {
int V_175 = F_146 ( V_18 ) ;
unsigned long V_21 ;
unsigned long V_171 ;
V_21 = F_9 ( V_16 , V_18 ) ;
V_171 = V_21 >> V_2 -> V_148 ;
if ( ! V_171 && V_220 && V_216 )
V_171 = F_26 ( V_21 , V_52 ) ;
switch ( V_214 ) {
case V_223 :
break;
case V_228 :
V_171 = F_190 ( V_171 * V_210 [ V_175 ] ,
V_211 ) ;
break;
case V_222 :
case V_227 :
if ( ( V_214 == V_222 ) != V_175 ) {
V_21 = 0 ;
V_171 = 0 ;
}
break;
default:
F_144 () ;
}
* V_208 += V_21 ;
V_8 [ V_18 ] = V_171 ;
V_219 |= ! ! V_171 ;
}
}
}
static void F_191 ( void )
{
V_57 -> V_231 . V_232 = false ;
}
static inline void F_191 ( void )
{
}
static void F_192 ( struct V_7 * V_7 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_208 )
{
struct V_16 * V_16 = F_193 ( V_7 , V_5 ) ;
unsigned long V_8 [ V_233 ] ;
unsigned long V_234 [ V_233 ] ;
unsigned long V_48 ;
enum V_17 V_18 ;
unsigned long V_121 = 0 ;
unsigned long V_235 = V_2 -> V_235 ;
struct V_236 V_237 ;
bool V_238 ;
F_185 ( V_16 , V_5 , V_2 , V_8 , V_208 ) ;
memcpy ( V_234 , V_8 , sizeof( V_8 ) ) ;
V_238 = ( F_1 ( V_2 ) && ! F_112 () &&
V_2 -> V_148 == V_149 ) ;
F_191 () ;
F_194 ( & V_237 ) ;
while ( V_8 [ V_230 ] || V_8 [ V_207 ] ||
V_8 [ V_206 ] ) {
unsigned long V_239 , V_240 , V_241 ;
unsigned long V_33 ;
F_189 (lru) {
if ( V_8 [ V_18 ] ) {
V_48 = F_26 ( V_8 [ V_18 ] , V_52 ) ;
V_8 [ V_18 ] -= V_48 ;
V_121 += F_184 ( V_18 , V_48 ,
V_16 , V_2 ) ;
}
}
if ( V_121 < V_235 || V_238 )
continue;
V_240 = V_8 [ V_206 ] + V_8 [ V_207 ] ;
V_239 = V_8 [ V_230 ] + V_8 [ V_229 ] ;
if ( ! V_240 || ! V_239 )
break;
if ( V_240 > V_239 ) {
unsigned long V_242 = V_234 [ V_230 ] +
V_234 [ V_229 ] + 1 ;
V_18 = V_243 ;
V_241 = V_239 * 100 / V_242 ;
} else {
unsigned long V_242 = V_234 [ V_206 ] +
V_234 [ V_207 ] + 1 ;
V_18 = V_244 ;
V_241 = V_240 * 100 / V_242 ;
}
V_8 [ V_18 ] = 0 ;
V_8 [ V_18 + V_202 ] = 0 ;
V_18 = ( V_18 == V_244 ) ? V_243 : V_244 ;
V_33 = V_234 [ V_18 ] - V_8 [ V_18 ] ;
V_8 [ V_18 ] = V_234 [ V_18 ] * ( 100 - V_241 ) / 100 ;
V_8 [ V_18 ] -= F_26 ( V_8 [ V_18 ] , V_33 ) ;
V_18 += V_202 ;
V_33 = V_234 [ V_18 ] - V_8 [ V_18 ] ;
V_8 [ V_18 ] = V_234 [ V_18 ] * ( 100 - V_241 ) / 100 ;
V_8 [ V_18 ] -= F_26 ( V_8 [ V_18 ] , V_33 ) ;
V_238 = true ;
}
F_195 ( & V_237 ) ;
V_2 -> V_121 += V_121 ;
if ( F_180 ( V_16 ) )
F_178 ( V_52 , V_16 ,
V_2 , V_229 ) ;
F_196 ( V_2 -> V_51 ) ;
}
static bool F_197 ( struct V_1 * V_2 )
{
if ( F_198 ( V_245 ) && V_2 -> V_173 &&
( V_2 -> V_173 > V_246 ||
V_2 -> V_148 < V_149 - 2 ) )
return true ;
return false ;
}
static inline bool F_199 ( struct V_7 * V_7 ,
unsigned long V_121 ,
unsigned long V_33 ,
struct V_1 * V_2 )
{
unsigned long V_247 ;
unsigned long V_248 ;
if ( ! F_197 ( V_2 ) )
return false ;
if ( V_2 -> V_51 & V_249 ) {
if ( ! V_121 && ! V_33 )
return false ;
} else {
if ( ! V_121 )
return false ;
}
V_247 = ( 2UL << V_2 -> V_173 ) ;
V_248 = F_12 ( V_7 , V_10 ) ;
if ( F_7 () > 0 )
V_248 += F_12 ( V_7 , V_13 ) ;
if ( V_2 -> V_121 < V_247 &&
V_248 > V_247 )
return true ;
switch ( F_200 ( V_7 , V_2 -> V_173 , 0 , 0 ) ) {
case V_250 :
case V_251 :
return false ;
default:
return true ;
}
}
static bool F_201 ( struct V_7 * V_7 , struct V_1 * V_2 ,
bool V_252 )
{
struct V_253 * V_253 = V_57 -> V_253 ;
unsigned long V_121 , V_33 ;
bool V_254 = false ;
do {
struct V_4 * V_255 = V_2 -> V_3 ;
struct V_256 V_257 = {
. V_7 = V_7 ,
. V_148 = V_2 -> V_148 ,
} ;
unsigned long V_258 = 0 ;
struct V_4 * V_5 ;
V_121 = V_2 -> V_121 ;
V_33 = V_2 -> V_33 ;
V_5 = F_40 ( V_255 , NULL , & V_257 ) ;
do {
unsigned long V_208 ;
unsigned long V_82 ;
unsigned long V_259 ;
if ( F_202 ( V_255 , V_5 ) ) {
if ( ! V_2 -> V_260 )
continue;
F_203 ( V_5 , V_261 , 1 ) ;
}
V_82 = V_2 -> V_121 ;
V_259 = V_2 -> V_33 ;
F_192 ( V_7 , V_5 , V_2 , & V_208 ) ;
V_258 += V_208 ;
if ( V_5 && V_252 )
F_33 ( V_2 -> V_51 , F_204 ( V_7 ) ,
V_5 , V_2 -> V_33 - V_259 ,
V_208 ) ;
F_205 ( V_2 -> V_51 , V_5 , false ,
V_2 -> V_33 - V_259 ,
V_2 -> V_121 - V_82 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_121 >= V_2 -> V_235 ) {
F_206 ( V_255 , V_5 ) ;
break;
}
} while ( ( V_5 = F_40 ( V_255 , V_5 , & V_257 ) ) );
if ( F_1 ( V_2 ) && V_252 )
F_33 ( V_2 -> V_51 , F_204 ( V_7 ) , NULL ,
V_2 -> V_33 - V_33 ,
V_258 ) ;
if ( V_253 ) {
V_2 -> V_121 += V_253 -> V_262 ;
V_253 -> V_262 = 0 ;
}
F_205 ( V_2 -> V_51 , V_2 -> V_3 , true ,
V_2 -> V_33 - V_33 ,
V_2 -> V_121 - V_121 ) ;
if ( V_2 -> V_121 - V_121 )
V_254 = true ;
} while ( F_199 ( V_7 , V_2 -> V_121 - V_121 ,
V_2 -> V_33 - V_33 , V_2 ) );
return V_254 ;
}
static inline bool F_207 ( struct V_7 * V_7 , int V_173 )
{
unsigned long V_263 , V_264 ;
bool V_265 ;
V_263 = F_26 ( F_208 ( V_7 ) , F_209 (
V_7 -> V_266 , V_267 ) ) ;
V_264 = F_188 ( V_7 ) + V_263 + ( 2UL << V_173 ) ;
V_265 = F_210 ( V_7 , 0 , V_264 , 0 ) ;
if ( F_211 ( V_7 , V_173 ) )
return V_265 ;
if ( F_200 ( V_7 , V_173 , 0 , 0 ) == V_268 )
return false ;
return V_265 ;
}
static bool F_212 ( struct V_269 * V_269 , struct V_1 * V_2 )
{
struct V_270 * V_271 ;
struct V_7 * V_7 ;
unsigned long V_272 ;
unsigned long V_273 ;
T_2 V_274 ;
enum V_275 V_276 = F_213 ( V_2 -> V_51 ) ;
bool V_254 = false ;
V_274 = V_2 -> V_51 ;
if ( V_201 )
V_2 -> V_51 |= V_277 ;
F_214 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
enum V_275 V_278 ;
if ( ! F_215 ( V_7 ) )
continue;
V_278 = V_276 ;
while ( ! F_215 ( V_7 -> V_279 -> V_280 +
V_278 ) )
V_278 -- ;
if ( F_1 ( V_2 ) ) {
if ( ! F_216 ( V_7 ,
V_26 | V_281 ) )
continue;
if ( V_2 -> V_148 != V_149 &&
! F_8 ( V_7 ) )
continue;
if ( F_198 ( V_245 ) &&
V_2 -> V_173 > V_246 &&
F_217 ( V_271 ) <= V_276 &&
F_207 ( V_7 , V_2 -> V_173 ) ) {
V_2 -> F_207 = true ;
continue;
}
V_273 = 0 ;
V_272 = F_218 ( V_7 ,
V_2 -> V_173 , V_2 -> V_51 ,
& V_273 ) ;
V_2 -> V_121 += V_272 ;
V_2 -> V_33 += V_273 ;
if ( V_272 )
V_254 = true ;
}
if ( F_201 ( V_7 , V_2 , F_219 ( V_7 ) == V_278 ) )
V_254 = true ;
if ( F_1 ( V_2 ) &&
! V_254 && F_8 ( V_7 ) )
V_254 = true ;
}
V_2 -> V_51 = V_274 ;
return V_254 ;
}
static unsigned long F_220 ( struct V_269 * V_269 ,
struct V_1 * V_2 )
{
int V_282 = V_2 -> V_148 ;
unsigned long V_283 = 0 ;
unsigned long V_284 ;
bool V_285 ;
V_286:
F_221 () ;
if ( F_1 ( V_2 ) )
F_96 ( V_287 ) ;
do {
F_222 ( V_2 -> V_51 , V_2 -> V_3 ,
V_2 -> V_148 ) ;
V_2 -> V_33 = 0 ;
V_285 = F_212 ( V_269 , V_2 ) ;
V_283 += V_2 -> V_33 ;
if ( V_2 -> V_121 >= V_2 -> V_235 )
break;
if ( V_2 -> F_207 )
break;
if ( V_2 -> V_148 < V_149 - 2 )
V_2 -> V_144 = 1 ;
V_284 = V_2 -> V_235 + V_2 -> V_235 / 2 ;
if ( V_283 > V_284 ) {
F_223 ( V_288 ? 0 : V_283 ,
V_289 ) ;
V_2 -> V_144 = 1 ;
}
} while ( -- V_2 -> V_148 >= 0 );
F_224 () ;
if ( V_2 -> V_121 )
return V_2 -> V_121 ;
if ( V_2 -> F_207 )
return 1 ;
if ( ! V_2 -> V_260 ) {
V_2 -> V_148 = V_282 ;
V_2 -> V_260 = 1 ;
goto V_286;
}
if ( V_285 )
return 1 ;
return 0 ;
}
static bool F_225 ( T_8 * V_290 )
{
struct V_7 * V_7 ;
unsigned long V_291 = 0 ;
unsigned long V_116 = 0 ;
int V_292 ;
bool V_293 ;
for ( V_292 = 0 ; V_292 <= V_294 ; V_292 ++ ) {
V_7 = & V_290 -> V_280 [ V_292 ] ;
if ( ! F_215 ( V_7 ) ||
F_5 ( V_7 ) == 0 )
continue;
V_291 += F_226 ( V_7 ) ;
V_116 += F_12 ( V_7 , V_226 ) ;
}
if ( ! V_291 )
return true ;
V_293 = V_116 > V_291 / 2 ;
if ( ! V_293 && F_227 ( & V_290 -> V_295 ) ) {
V_290 -> V_278 = F_26 ( V_290 -> V_278 ,
(enum V_275 ) V_294 ) ;
F_228 ( & V_290 -> V_295 ) ;
}
return V_293 ;
}
static bool F_229 ( T_2 V_51 , struct V_269 * V_269 ,
T_9 * V_296 )
{
struct V_270 * V_271 ;
struct V_7 * V_7 ;
T_8 * V_290 = NULL ;
if ( V_57 -> V_23 & V_297 )
goto V_53;
if ( F_169 ( V_57 ) )
goto V_53;
F_214 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_219 ( V_7 ) > V_294 )
continue;
V_290 = V_7 -> V_279 ;
if ( F_225 ( V_290 ) )
goto V_53;
break;
}
if ( ! V_290 )
goto V_53;
F_96 ( V_298 ) ;
if ( ! ( V_51 & V_132 ) ) {
F_230 ( V_290 -> V_299 ,
F_225 ( V_290 ) , V_186 ) ;
goto V_300;
}
F_231 ( V_7 -> V_279 -> V_299 ,
F_225 ( V_290 ) ) ;
V_300:
if ( F_169 ( V_57 ) )
return true ;
V_53:
return false ;
}
unsigned long F_232 ( struct V_269 * V_269 , int V_173 ,
T_2 V_51 , T_9 * V_296 )
{
unsigned long V_121 ;
struct V_1 V_2 = {
. V_235 = V_52 ,
. V_51 = ( V_51 = F_233 ( V_51 ) ) ,
. V_173 = V_173 ,
. V_296 = V_296 ,
. V_148 = V_149 ,
. V_144 = ! V_288 ,
. V_130 = 1 ,
. V_221 = 1 ,
} ;
if ( F_229 ( V_51 , V_269 , V_296 ) )
return 1 ;
F_234 ( V_173 ,
V_2 . V_144 ,
V_51 ) ;
V_121 = F_220 ( V_269 , & V_2 ) ;
F_235 ( V_121 ) ;
return V_121 ;
}
unsigned long F_236 ( struct V_4 * V_5 ,
T_2 V_51 , bool V_301 ,
struct V_7 * V_7 ,
unsigned long * V_33 )
{
struct V_1 V_2 = {
. V_235 = V_52 ,
. V_3 = V_5 ,
. V_144 = ! V_288 ,
. V_130 = 1 ,
. V_221 = ! V_301 ,
} ;
unsigned long V_208 ;
V_2 . V_51 = ( V_51 & V_302 ) |
( V_303 & ~ V_302 ) ;
F_237 ( V_2 . V_173 ,
V_2 . V_144 ,
V_2 . V_51 ) ;
F_192 ( V_7 , V_5 , & V_2 , & V_208 ) ;
F_238 ( V_2 . V_121 ) ;
* V_33 = V_2 . V_33 ;
return V_2 . V_121 ;
}
unsigned long F_239 ( struct V_4 * V_5 ,
unsigned long V_172 ,
T_2 V_51 ,
bool V_221 )
{
struct V_269 * V_269 ;
unsigned long V_121 ;
int V_40 ;
struct V_1 V_2 = {
. V_235 = F_240 ( V_172 , V_52 ) ,
. V_51 = ( V_51 & V_302 ) |
( V_303 & ~ V_302 ) ,
. V_3 = V_5 ,
. V_148 = V_149 ,
. V_144 = ! V_288 ,
. V_130 = 1 ,
. V_221 = V_221 ,
} ;
V_40 = F_241 ( V_5 ) ;
V_269 = F_242 ( V_40 ) -> V_304 ;
F_243 ( 0 ,
V_2 . V_144 ,
V_2 . V_51 ) ;
V_121 = F_220 ( V_269 , & V_2 ) ;
F_244 ( V_121 ) ;
return V_121 ;
}
static void F_245 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_205 )
return;
V_5 = F_40 ( NULL , NULL , NULL ) ;
do {
struct V_16 * V_16 = F_193 ( V_7 , V_5 ) ;
if ( F_180 ( V_16 ) )
F_178 ( V_52 , V_16 ,
V_2 , V_229 ) ;
V_5 = F_40 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_246 ( struct V_7 * V_7 , int V_173 , bool V_305 ,
unsigned long V_263 , int V_278 )
{
unsigned long V_306 = F_188 ( V_7 ) + V_263 ;
if ( F_198 ( V_245 ) && ! V_305 ) {
V_306 += ( 1UL << V_173 ) ;
V_173 = 0 ;
}
return F_210 ( V_7 , V_173 , V_306 , V_278 ) ;
}
static bool F_247 ( T_8 * V_290 , int V_173 , int V_278 )
{
unsigned long V_266 = 0 ;
unsigned long V_307 = 0 ;
int V_292 ;
for ( V_292 = 0 ; V_292 <= V_278 ; V_292 ++ ) {
struct V_7 * V_7 = V_290 -> V_280 + V_292 ;
if ( ! F_215 ( V_7 ) )
continue;
V_266 += V_7 -> V_266 ;
if ( ! F_8 ( V_7 ) ) {
V_307 += V_7 -> V_266 ;
continue;
}
if ( F_246 ( V_7 , V_173 , false , 0 , V_292 ) )
V_307 += V_7 -> V_266 ;
else if ( ! V_173 )
return false ;
}
if ( V_173 )
return V_307 >= ( V_266 >> 2 ) ;
else
return true ;
}
static bool F_248 ( T_8 * V_290 , int V_173 , long V_308 ,
int V_278 )
{
if ( V_308 )
return false ;
if ( F_227 ( & V_290 -> V_299 ) )
F_249 ( & V_290 -> V_299 ) ;
return F_247 ( V_290 , V_173 , V_278 ) ;
}
static bool F_250 ( struct V_7 * V_7 ,
int V_278 ,
struct V_1 * V_2 )
{
unsigned long V_263 ;
bool V_309 ;
V_2 -> V_235 = F_240 ( V_52 , F_188 ( V_7 ) ) ;
V_263 = F_26 ( F_208 ( V_7 ) , F_209 (
V_7 -> V_266 , V_267 ) ) ;
V_309 = ( V_201 && F_251 ( V_7 ) ) ;
if ( ! V_309 && F_246 ( V_7 , V_2 -> V_173 , false ,
V_263 , V_278 ) )
return true ;
F_201 ( V_7 , V_2 , F_219 ( V_7 ) == V_278 ) ;
F_252 ( V_134 , & V_7 -> V_23 ) ;
if ( F_8 ( V_7 ) &&
F_246 ( V_7 , V_2 -> V_173 , false , 0 , V_278 ) ) {
F_252 ( V_192 , & V_7 -> V_23 ) ;
F_252 ( V_142 , & V_7 -> V_23 ) ;
}
return V_2 -> V_33 >= V_2 -> V_235 ;
}
static int F_253 ( T_8 * V_290 , int V_173 , int V_278 )
{
int V_292 ;
int V_310 = 0 ;
unsigned long V_272 ;
unsigned long V_273 ;
struct V_1 V_2 = {
. V_51 = V_26 ,
. V_173 = V_173 ,
. V_148 = V_149 ,
. V_144 = ! V_288 ,
. V_130 = 1 ,
. V_221 = 1 ,
} ;
F_96 ( V_311 ) ;
do {
bool V_312 = true ;
V_2 . V_121 = 0 ;
for ( V_292 = V_290 -> V_313 - 1 ; V_292 >= 0 ; V_292 -- ) {
struct V_7 * V_7 = V_290 -> V_280 + V_292 ;
if ( ! F_215 ( V_7 ) )
continue;
if ( V_2 . V_148 != V_149 &&
! F_8 ( V_7 ) )
continue;
F_245 ( V_7 , & V_2 ) ;
if ( V_201 && F_254 ( V_292 ) ) {
V_310 = V_292 ;
break;
}
if ( ! F_246 ( V_7 , V_173 , false , 0 , 0 ) ) {
V_310 = V_292 ;
break;
} else {
F_252 ( V_192 , & V_7 -> V_23 ) ;
F_252 ( V_142 , & V_7 -> V_23 ) ;
}
}
if ( V_292 < 0 )
goto V_53;
if ( V_2 . V_148 < V_149 - 2 )
V_2 . V_144 = 1 ;
for ( V_292 = 0 ; V_292 <= V_310 ; V_292 ++ ) {
struct V_7 * V_7 = V_290 -> V_280 + V_292 ;
if ( ! F_215 ( V_7 ) )
continue;
if ( V_2 . V_148 != V_149 &&
! F_8 ( V_7 ) )
continue;
V_2 . V_33 = 0 ;
V_273 = 0 ;
V_272 = F_218 ( V_7 ,
V_173 , V_2 . V_51 ,
& V_273 ) ;
V_2 . V_121 += V_272 ;
if ( F_250 ( V_7 , V_310 , & V_2 ) )
V_312 = false ;
}
if ( F_227 ( & V_290 -> V_299 ) &&
F_225 ( V_290 ) )
F_249 ( & V_290 -> V_299 ) ;
if ( F_255 () || F_256 () )
break;
if ( V_312 || ! V_2 . V_121 )
V_2 . V_148 -- ;
} while ( V_2 . V_148 >= 1 &&
! F_247 ( V_290 , V_173 , V_278 ) );
V_53:
return V_310 ;
}
static void F_257 ( T_8 * V_290 , int V_173 ,
int V_278 , int V_314 )
{
long V_308 = 0 ;
F_258 ( V_315 ) ;
if ( F_259 ( V_57 ) || F_256 () )
return;
F_260 ( & V_290 -> V_295 , & V_315 , V_316 ) ;
if ( F_248 ( V_290 , V_173 , V_308 ,
V_314 ) ) {
F_261 ( V_290 ) ;
F_262 ( V_290 , V_173 , V_278 ) ;
V_308 = F_263 ( V_186 / 10 ) ;
F_264 ( & V_290 -> V_295 , & V_315 ) ;
F_260 ( & V_290 -> V_295 , & V_315 , V_316 ) ;
}
if ( F_248 ( V_290 , V_173 , V_308 ,
V_314 ) ) {
F_265 ( V_290 -> V_317 ) ;
F_266 ( V_290 , V_318 ) ;
if ( ! F_256 () )
F_267 () ;
F_266 ( V_290 , V_319 ) ;
} else {
if ( V_308 )
F_96 ( V_320 ) ;
else
F_96 ( V_321 ) ;
}
F_264 ( & V_290 -> V_295 , & V_315 ) ;
}
static int F_268 ( void * V_322 )
{
unsigned long V_173 , V_323 ;
int V_278 , V_324 ;
int V_314 ;
T_8 * V_290 = ( T_8 * ) V_322 ;
struct V_325 * V_326 = V_57 ;
struct V_253 V_253 = {
. V_262 = 0 ,
} ;
const struct V_327 * V_327 = F_269 ( V_290 -> V_317 ) ;
F_270 ( V_26 ) ;
if ( ! F_271 ( V_327 ) )
F_272 ( V_326 , V_327 ) ;
V_57 -> V_253 = & V_253 ;
V_326 -> V_23 |= V_328 | V_58 | V_329 ;
F_273 () ;
V_173 = V_323 = 0 ;
V_278 = V_324 = V_290 -> V_313 - 1 ;
V_314 = V_278 ;
for ( ; ; ) {
bool V_47 ;
V_323 = V_290 -> V_330 ;
V_324 = V_290 -> V_278 ;
V_290 -> V_330 = 0 ;
V_290 -> V_278 = V_290 -> V_313 - 1 ;
if ( V_173 < V_323 || V_278 > V_324 ) {
V_173 = V_323 ;
V_278 = V_324 ;
} else {
F_257 ( V_290 , V_173 , V_278 ,
V_314 ) ;
V_173 = V_290 -> V_330 ;
V_278 = V_290 -> V_278 ;
V_323 = V_173 ;
V_324 = V_278 ;
V_290 -> V_330 = 0 ;
V_290 -> V_278 = V_290 -> V_313 - 1 ;
}
V_47 = F_255 () ;
if ( F_256 () )
break;
if ( ! V_47 ) {
F_274 ( V_290 -> V_317 , V_173 ) ;
V_314 = F_253 ( V_290 , V_173 ,
V_278 ) ;
}
}
V_326 -> V_23 &= ~ ( V_328 | V_58 | V_329 ) ;
V_57 -> V_253 = NULL ;
F_275 () ;
return 0 ;
}
void F_276 ( struct V_7 * V_7 , int V_173 , enum V_275 V_278 )
{
T_8 * V_290 ;
if ( ! F_215 ( V_7 ) )
return;
if ( ! F_216 ( V_7 , V_26 | V_281 ) )
return;
V_290 = V_7 -> V_279 ;
if ( V_290 -> V_330 < V_173 ) {
V_290 -> V_330 = V_173 ;
V_290 -> V_278 = F_26 ( V_290 -> V_278 , V_278 ) ;
}
if ( ! F_227 ( & V_290 -> V_295 ) )
return;
if ( F_246 ( V_7 , V_173 , true , 0 , 0 ) )
return;
F_277 ( V_290 -> V_317 , F_219 ( V_7 ) , V_173 ) ;
F_228 ( & V_290 -> V_295 ) ;
}
unsigned long F_278 ( unsigned long V_235 )
{
struct V_253 V_253 ;
struct V_1 V_2 = {
. V_235 = V_235 ,
. V_51 = V_303 ,
. V_148 = V_149 ,
. V_144 = 1 ,
. V_130 = 1 ,
. V_221 = 1 ,
. V_193 = 1 ,
} ;
struct V_269 * V_269 = F_279 ( F_280 () , V_2 . V_51 ) ;
struct V_325 * V_322 = V_57 ;
unsigned long V_121 ;
V_322 -> V_23 |= V_328 ;
F_270 ( V_2 . V_51 ) ;
V_253 . V_262 = 0 ;
V_322 -> V_253 = & V_253 ;
V_121 = F_220 ( V_269 , & V_2 ) ;
V_322 -> V_253 = NULL ;
F_275 () ;
V_322 -> V_23 &= ~ V_328 ;
return V_121 ;
}
static int F_281 ( struct V_331 * V_332 , unsigned long V_333 ,
void * V_334 )
{
int V_40 ;
if ( V_333 == V_335 || V_333 == V_336 ) {
F_282 (nid, N_MEMORY) {
T_8 * V_290 = F_242 ( V_40 ) ;
const struct V_327 * V_337 ;
V_337 = F_269 ( V_290 -> V_317 ) ;
if ( F_283 ( V_338 , V_337 ) < V_339 )
F_272 ( V_290 -> F_268 , V_337 ) ;
}
}
return V_340 ;
}
int F_284 ( int V_40 )
{
T_8 * V_290 = F_242 ( V_40 ) ;
int V_47 = 0 ;
if ( V_290 -> F_268 )
return 0 ;
V_290 -> F_268 = F_285 ( F_268 , V_290 , L_4 , V_40 ) ;
if ( F_286 ( V_290 -> F_268 ) ) {
F_65 ( V_341 == V_342 ) ;
F_25 ( L_5 , V_40 ) ;
V_47 = F_287 ( V_290 -> F_268 ) ;
V_290 -> F_268 = NULL ;
}
return V_47 ;
}
void F_288 ( int V_40 )
{
struct V_325 * F_268 = F_242 ( V_40 ) -> F_268 ;
if ( F_268 ) {
F_289 ( F_268 ) ;
F_242 ( V_40 ) -> F_268 = NULL ;
}
}
static int T_10 F_290 ( void )
{
int V_40 ;
F_291 () ;
F_282 (nid, N_MEMORY)
F_284 ( V_40 ) ;
F_292 ( F_281 , 0 ) ;
return 0 ;
}
static inline unsigned long F_293 ( struct V_7 * V_7 )
{
unsigned long V_343 = F_12 ( V_7 , V_344 ) ;
unsigned long V_345 = F_12 ( V_7 , V_10 ) +
F_12 ( V_7 , V_9 ) ;
return ( V_345 > V_343 ) ? ( V_345 - V_343 ) : 0 ;
}
static unsigned long F_294 ( struct V_7 * V_7 )
{
unsigned long V_346 ;
unsigned long V_36 = 0 ;
if ( V_347 & V_348 )
V_346 = F_12 ( V_7 , V_349 ) ;
else
V_346 = F_293 ( V_7 ) ;
if ( ! ( V_347 & V_350 ) )
V_36 += F_12 ( V_7 , V_351 ) ;
if ( F_69 ( V_36 > V_346 ) )
V_36 = V_346 ;
return V_346 - V_36 ;
}
static int F_295 ( struct V_7 * V_7 , T_2 V_51 , unsigned int V_173 )
{
const unsigned long V_172 = 1 << V_173 ;
struct V_325 * V_322 = V_57 ;
struct V_253 V_253 ;
struct V_1 V_2 = {
. V_235 = F_240 ( V_172 , V_52 ) ,
. V_51 = ( V_51 = F_233 ( V_51 ) ) ,
. V_173 = V_173 ,
. V_148 = V_352 ,
. V_144 = ! ! ( V_347 & V_350 ) ,
. V_130 = ! ! ( V_347 & V_348 ) ,
. V_221 = 1 ,
} ;
F_29 () ;
V_322 -> V_23 |= V_328 | V_58 ;
F_270 ( V_51 ) ;
V_253 . V_262 = 0 ;
V_322 -> V_253 = & V_253 ;
if ( F_294 ( V_7 ) > V_7 -> V_353 ) {
do {
F_201 ( V_7 , & V_2 , true ) ;
} while ( V_2 . V_121 < V_172 && -- V_2 . V_148 >= 0 );
}
V_322 -> V_253 = NULL ;
V_57 -> V_23 &= ~ ( V_328 | V_58 ) ;
F_275 () ;
return V_2 . V_121 >= V_172 ;
}
int F_296 ( struct V_7 * V_7 , T_2 V_51 , unsigned int V_173 )
{
int V_317 ;
int V_47 ;
if ( F_294 ( V_7 ) <= V_7 -> V_353 &&
F_12 ( V_7 , V_354 ) <= V_7 -> V_355 )
return V_356 ;
if ( ! F_8 ( V_7 ) )
return V_356 ;
if ( ! F_297 ( V_51 ) || ( V_57 -> V_23 & V_328 ) )
return V_357 ;
V_317 = F_204 ( V_7 ) ;
if ( F_298 ( V_317 , V_358 ) && V_317 != F_280 () )
return V_357 ;
if ( F_299 ( V_359 , & V_7 -> V_23 ) )
return V_357 ;
V_47 = F_295 ( V_7 , V_51 , V_173 ) ;
F_252 ( V_359 , & V_7 -> V_23 ) ;
if ( ! V_47 )
F_96 ( V_360 ) ;
return V_47 ;
}
int F_90 ( struct V_55 * V_55 )
{
return ! F_300 ( F_51 ( V_55 ) ) && ! F_301 ( V_55 ) ;
}
void F_302 ( struct V_55 * * V_361 , int V_172 )
{
struct V_16 * V_16 ;
struct V_7 * V_7 = NULL ;
int V_362 = 0 ;
int V_363 = 0 ;
int V_292 ;
for ( V_292 = 0 ; V_292 < V_172 ; V_292 ++ ) {
struct V_55 * V_55 = V_361 [ V_292 ] ;
struct V_7 * V_364 ;
V_362 ++ ;
V_364 = F_109 ( V_55 ) ;
if ( V_364 != V_7 ) {
if ( V_7 )
F_154 ( & V_7 -> V_174 ) ;
V_7 = V_364 ;
F_149 ( & V_7 -> V_174 ) ;
}
V_16 = F_150 ( V_55 , V_7 ) ;
if ( ! F_88 ( V_55 ) || ! F_86 ( V_55 ) )
continue;
if ( F_90 ( V_55 ) ) {
enum V_17 V_18 = F_303 ( V_55 ) ;
F_87 ( F_108 ( V_55 ) , V_55 ) ;
F_89 ( V_55 ) ;
F_153 ( V_55 , V_16 , V_365 ) ;
F_158 ( V_55 , V_16 , V_18 ) ;
V_363 ++ ;
}
}
if ( V_7 ) {
F_177 ( V_91 , V_363 ) ;
F_177 ( V_366 , V_362 ) ;
F_154 ( & V_7 -> V_174 ) ;
}
}
