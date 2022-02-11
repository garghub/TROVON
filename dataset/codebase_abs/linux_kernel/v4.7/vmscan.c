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
unsigned long F_5 ( struct V_7 * V_7 )
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
V_55 = F_106 ( V_168 ) ;
F_141 ( V_55 , V_168 , V_23 ) ;
F_87 ( ! F_88 ( V_55 ) , V_55 ) ;
switch ( F_136 ( V_55 , V_159 ) ) {
case 0 :
V_170 += F_142 ( V_55 ) ;
F_134 ( & V_55 -> V_18 , V_167 ) ;
break;
case - V_162 :
F_134 ( & V_55 -> V_18 , V_168 ) ;
continue;
default:
F_143 () ;
}
}
* V_33 = V_171 ;
F_144 ( V_2 -> V_172 , V_48 , V_171 ,
V_170 , V_159 , F_145 ( V_18 ) ) ;
return V_170 ;
}
int F_94 ( struct V_55 * V_55 )
{
int V_47 = - V_162 ;
F_87 ( ! F_44 ( V_55 ) , V_55 ) ;
F_146 ( F_147 ( V_55 ) , L_3 ) ;
if ( F_88 ( V_55 ) ) {
struct V_7 * V_7 = F_109 ( V_55 ) ;
struct V_16 * V_16 ;
F_148 ( & V_7 -> V_173 ) ;
V_16 = F_149 ( V_55 , V_7 ) ;
if ( F_88 ( V_55 ) ) {
int V_18 = F_150 ( V_55 ) ;
F_151 ( V_55 ) ;
F_139 ( V_55 ) ;
F_152 ( V_55 , V_16 , V_18 ) ;
V_47 = 0 ;
}
F_153 ( & V_7 -> V_173 ) ;
}
return V_47 ;
}
static int F_154 ( struct V_7 * V_7 , int V_174 ,
struct V_1 * V_2 )
{
unsigned long V_175 , V_176 ;
if ( F_112 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_174 ) {
V_175 = F_12 ( V_7 , V_10 ) ;
V_176 = F_12 ( V_7 , V_11 ) ;
} else {
V_175 = F_12 ( V_7 , V_13 ) ;
V_176 = F_12 ( V_7 , V_14 ) ;
}
if ( ( V_2 -> V_51 & ( V_133 | V_132 ) ) == ( V_133 | V_132 ) )
V_175 >>= 3 ;
return V_176 > V_175 ;
}
static T_6 void
F_155 ( struct V_16 * V_16 , struct V_106 * V_107 )
{
struct V_177 * V_178 = & V_16 -> V_178 ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
F_104 ( V_179 ) ;
while ( ! F_105 ( V_107 ) ) {
struct V_55 * V_55 = F_106 ( V_107 ) ;
int V_18 ;
F_87 ( F_88 ( V_55 ) , V_55 ) ;
F_20 ( & V_55 -> V_18 ) ;
if ( F_69 ( ! F_90 ( V_55 ) ) ) {
F_153 ( & V_7 -> V_173 ) ;
F_85 ( V_55 ) ;
F_148 ( & V_7 -> V_173 ) ;
continue;
}
V_16 = F_149 ( V_55 , V_7 ) ;
F_156 ( V_55 ) ;
V_18 = F_150 ( V_55 ) ;
F_157 ( V_55 , V_16 , V_18 ) ;
if ( F_158 ( V_18 ) ) {
int V_174 = F_145 ( V_18 ) ;
int V_180 = F_142 ( V_55 ) ;
V_178 -> V_181 [ V_174 ] += V_180 ;
}
if ( F_120 ( V_55 ) ) {
F_159 ( V_55 ) ;
F_160 ( V_55 ) ;
F_152 ( V_55 , V_16 , V_18 ) ;
if ( F_69 ( F_161 ( V_55 ) ) ) {
F_153 ( & V_7 -> V_173 ) ;
F_162 ( V_55 ) ;
( * F_163 ( V_55 ) ) ( V_55 ) ;
F_148 ( & V_7 -> V_173 ) ;
} else
F_122 ( & V_55 -> V_18 , & V_179 ) ;
}
}
F_129 ( & V_179 , V_107 ) ;
}
static int F_164 ( void )
{
return ! ( V_57 -> V_23 & V_182 ) ||
V_57 -> V_59 == NULL ||
F_165 ( V_57 -> V_59 ) ;
}
static T_6 unsigned long
F_166 ( unsigned long V_48 , struct V_16 * V_16 ,
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
T_5 V_183 = 0 ;
int V_174 = F_145 ( V_18 ) ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
struct V_177 * V_178 = & V_16 -> V_178 ;
while ( F_69 ( F_154 ( V_7 , V_174 , V_2 ) ) ) {
F_167 ( V_184 , V_185 / 10 ) ;
if ( F_168 ( V_57 ) )
return V_52 ;
}
F_169 () ;
if ( ! V_2 -> V_130 )
V_183 |= V_166 ;
if ( ! V_2 -> V_144 )
V_183 |= V_163 ;
F_148 ( & V_7 -> V_173 ) ;
V_170 = F_140 ( V_48 , V_16 , & V_107 ,
& V_33 , V_2 , V_183 , V_18 ) ;
F_170 ( V_16 , V_18 , - V_170 ) ;
F_171 ( V_7 , V_14 + V_174 , V_170 ) ;
V_178 -> V_186 [ V_174 ] += V_170 ;
if ( F_1 ( V_2 ) ) {
F_171 ( V_7 , V_15 , V_33 ) ;
if ( F_112 () )
F_172 ( V_187 , V_7 , V_33 ) ;
else
F_172 ( V_188 , V_7 , V_33 ) ;
}
F_153 ( & V_7 -> V_173 ) ;
if ( V_170 == 0 )
return 0 ;
V_121 = F_103 ( & V_107 , V_7 , V_2 , V_157 ,
& V_119 , & V_118 , & V_120 ,
& V_122 , & V_123 ,
false ) ;
F_148 ( & V_7 -> V_173 ) ;
if ( F_1 ( V_2 ) ) {
if ( F_112 () )
F_172 ( V_189 , V_7 ,
V_121 ) ;
else
F_172 ( V_190 , V_7 ,
V_121 ) ;
}
F_155 ( V_16 , & V_107 ) ;
F_171 ( V_7 , V_14 + V_174 , - V_170 ) ;
F_153 ( & V_7 -> V_173 ) ;
F_126 ( & V_107 ) ;
F_128 ( & V_107 , true ) ;
if ( V_122 && V_122 == V_170 )
F_173 ( V_134 , & V_7 -> V_23 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_119 && V_119 == V_120 )
F_173 ( V_191 , & V_7 -> V_23 ) ;
if ( V_118 == V_170 )
F_173 ( V_142 , & V_7 -> V_23 ) ;
if ( V_123 && F_164 () )
F_167 ( V_184 , V_185 / 10 ) ;
}
if ( ! V_2 -> V_192 && ! F_112 () &&
F_164 () )
F_174 ( V_7 , V_184 , V_185 / 10 ) ;
F_175 ( V_7 , V_33 , V_121 ,
V_2 -> V_148 , V_174 ) ;
return V_121 ;
}
static void F_176 ( struct V_16 * V_16 ,
struct V_106 * V_29 ,
struct V_106 * V_179 ,
enum V_17 V_18 )
{
struct V_7 * V_7 = F_13 ( V_16 ) ;
unsigned long V_193 = 0 ;
struct V_55 * V_55 ;
int V_194 ;
while ( ! F_105 ( V_29 ) ) {
V_55 = F_106 ( V_29 ) ;
V_16 = F_149 ( V_55 , V_7 ) ;
F_87 ( F_88 ( V_55 ) , V_55 ) ;
F_156 ( V_55 ) ;
V_194 = F_142 ( V_55 ) ;
F_170 ( V_16 , V_18 , V_194 ) ;
F_134 ( & V_55 -> V_18 , & V_16 -> V_169 [ V_18 ] ) ;
V_193 += V_194 ;
if ( F_120 ( V_55 ) ) {
F_159 ( V_55 ) ;
F_160 ( V_55 ) ;
F_152 ( V_55 , V_16 , V_18 ) ;
if ( F_69 ( F_161 ( V_55 ) ) ) {
F_153 ( & V_7 -> V_173 ) ;
F_162 ( V_55 ) ;
( * F_163 ( V_55 ) ) ( V_55 ) ;
F_148 ( & V_7 -> V_173 ) ;
} else
F_122 ( & V_55 -> V_18 , V_179 ) ;
}
}
if ( ! F_158 ( V_18 ) )
F_177 ( V_195 , V_193 ) ;
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
struct V_177 * V_178 = & V_16 -> V_178 ;
unsigned long V_199 = 0 ;
T_5 V_183 = 0 ;
int V_174 = F_145 ( V_18 ) ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
F_169 () ;
if ( ! V_2 -> V_130 )
V_183 |= V_166 ;
if ( ! V_2 -> V_144 )
V_183 |= V_163 ;
F_148 ( & V_7 -> V_173 ) ;
V_170 = F_140 ( V_48 , V_16 , & V_196 ,
& V_33 , V_2 , V_183 , V_18 ) ;
F_170 ( V_16 , V_18 , - V_170 ) ;
F_171 ( V_7 , V_14 + V_174 , V_170 ) ;
V_178 -> V_186 [ V_174 ] += V_170 ;
if ( F_1 ( V_2 ) )
F_171 ( V_7 , V_15 , V_33 ) ;
F_172 ( V_200 , V_7 , V_33 ) ;
F_153 ( & V_7 -> V_173 ) ;
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
F_148 ( & V_7 -> V_173 ) ;
V_178 -> V_181 [ V_174 ] += V_199 ;
F_176 ( V_16 , & V_197 , & V_196 , V_18 ) ;
F_176 ( V_16 , & V_198 , & V_196 , V_18 - V_202 ) ;
F_171 ( V_7 , V_14 + V_174 , - V_170 ) ;
F_153 ( & V_7 -> V_173 ) ;
F_126 ( & V_196 ) ;
F_128 ( & V_196 , true ) ;
}
static bool F_179 ( struct V_16 * V_16 , bool V_174 )
{
unsigned long V_203 ;
unsigned long V_175 ;
unsigned long V_204 ;
unsigned long V_205 ;
if ( ! V_174 && ! V_206 )
return false ;
V_175 = F_9 ( V_16 , V_174 * V_207 ) ;
V_204 = F_9 ( V_16 , V_174 * V_207 + V_202 ) ;
V_205 = ( V_175 + V_204 ) >> ( 30 - V_208 ) ;
if ( V_205 )
V_203 = F_180 ( 10 * V_205 ) ;
else
V_203 = 1 ;
return V_175 * V_203 < V_204 ;
}
static unsigned long F_181 ( enum V_17 V_18 , unsigned long V_48 ,
struct V_16 * V_16 , struct V_1 * V_2 )
{
if ( F_158 ( V_18 ) ) {
if ( F_179 ( V_16 , F_145 ( V_18 ) ) )
F_178 ( V_48 , V_16 , V_2 , V_18 ) ;
return 0 ;
}
return F_166 ( V_48 , V_16 , V_2 , V_18 ) ;
}
static void F_182 ( struct V_16 * V_16 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_209 )
{
int V_210 = F_183 ( V_5 ) ;
struct V_177 * V_178 = & V_16 -> V_178 ;
T_7 V_211 [ 2 ] ;
T_7 V_212 = 0 ;
struct V_7 * V_7 = F_13 ( V_16 ) ;
unsigned long V_213 , V_214 ;
enum V_215 V_215 ;
unsigned long V_216 , V_174 ;
bool V_217 = false ;
unsigned long V_218 , V_219 ;
enum V_17 V_18 ;
bool V_220 ;
int V_221 ;
if ( F_112 () ) {
if ( ! F_8 ( V_7 ) )
V_217 = true ;
if ( ! F_35 ( V_5 ) )
V_217 = true ;
}
if ( ! F_1 ( V_2 ) )
V_217 = true ;
if ( ! V_2 -> V_222 || F_184 ( V_5 ) <= 0 ) {
V_215 = V_223 ;
goto V_53;
}
if ( ! F_1 ( V_2 ) && ! V_210 ) {
V_215 = V_223 ;
goto V_53;
}
if ( ! V_2 -> V_148 && V_210 ) {
V_215 = V_224 ;
goto V_53;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_225 ;
unsigned long V_226 ;
V_226 = F_12 ( V_7 , V_227 ) ;
V_225 = F_12 ( V_7 , V_9 ) +
F_12 ( V_7 , V_10 ) ;
if ( F_69 ( V_225 + V_226 <= F_185 ( V_7 ) ) ) {
V_215 = V_228 ;
goto V_53;
}
}
if ( ! F_179 ( V_16 , true ) &&
F_9 ( V_16 , V_229 ) >> V_2 -> V_148 ) {
V_215 = V_223 ;
goto V_53;
}
V_215 = V_230 ;
V_213 = V_210 ;
V_214 = 200 - V_213 ;
V_216 = F_9 ( V_16 , V_231 ) +
F_9 ( V_16 , V_232 ) ;
V_174 = F_9 ( V_16 , V_233 ) +
F_9 ( V_16 , V_229 ) ;
F_148 ( & V_7 -> V_173 ) ;
if ( F_69 ( V_178 -> V_186 [ 0 ] > V_216 / 4 ) ) {
V_178 -> V_186 [ 0 ] /= 2 ;
V_178 -> V_181 [ 0 ] /= 2 ;
}
if ( F_69 ( V_178 -> V_186 [ 1 ] > V_174 / 4 ) ) {
V_178 -> V_186 [ 1 ] /= 2 ;
V_178 -> V_181 [ 1 ] /= 2 ;
}
V_218 = V_213 * ( V_178 -> V_186 [ 0 ] + 1 ) ;
V_218 /= V_178 -> V_181 [ 0 ] + 1 ;
V_219 = V_214 * ( V_178 -> V_186 [ 1 ] + 1 ) ;
V_219 /= V_178 -> V_181 [ 1 ] + 1 ;
F_153 ( & V_7 -> V_173 ) ;
V_211 [ 0 ] = V_218 ;
V_211 [ 1 ] = V_219 ;
V_212 = V_218 + V_219 + 1 ;
V_53:
V_220 = false ;
for ( V_221 = 0 ; ! V_220 && V_221 < 2 ; V_221 ++ ) {
* V_209 = 0 ;
F_186 (lru) {
int V_174 = F_145 ( V_18 ) ;
unsigned long V_21 ;
unsigned long V_171 ;
V_21 = F_9 ( V_16 , V_18 ) ;
V_171 = V_21 >> V_2 -> V_148 ;
if ( ! V_171 && V_221 && V_217 )
V_171 = F_26 ( V_21 , V_52 ) ;
switch ( V_215 ) {
case V_224 :
break;
case V_230 :
V_171 = F_187 ( V_171 * V_211 [ V_174 ] ,
V_212 ) ;
break;
case V_223 :
case V_228 :
if ( ( V_215 == V_223 ) != V_174 ) {
V_21 = 0 ;
V_171 = 0 ;
}
break;
default:
F_143 () ;
}
* V_209 += V_21 ;
V_8 [ V_18 ] = V_171 ;
V_220 |= ! ! V_171 ;
}
}
}
static void F_188 ( void )
{
V_57 -> V_234 . V_235 = false ;
}
static inline void F_188 ( void )
{
}
static void F_189 ( struct V_7 * V_7 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long * V_209 )
{
struct V_16 * V_16 = F_190 ( V_7 , V_5 ) ;
unsigned long V_8 [ V_236 ] ;
unsigned long V_237 [ V_236 ] ;
unsigned long V_48 ;
enum V_17 V_18 ;
unsigned long V_121 = 0 ;
unsigned long V_238 = V_2 -> V_238 ;
struct V_239 V_240 ;
bool V_241 ;
F_182 ( V_16 , V_5 , V_2 , V_8 , V_209 ) ;
memcpy ( V_237 , V_8 , sizeof( V_8 ) ) ;
V_241 = ( F_1 ( V_2 ) && ! F_112 () &&
V_2 -> V_148 == V_149 ) ;
F_188 () ;
F_191 ( & V_240 ) ;
while ( V_8 [ V_232 ] || V_8 [ V_233 ] ||
V_8 [ V_229 ] ) {
unsigned long V_242 , V_243 , V_244 ;
unsigned long V_33 ;
F_186 (lru) {
if ( V_8 [ V_18 ] ) {
V_48 = F_26 ( V_8 [ V_18 ] , V_52 ) ;
V_8 [ V_18 ] -= V_48 ;
V_121 += F_181 ( V_18 , V_48 ,
V_16 , V_2 ) ;
}
}
if ( V_121 < V_238 || V_241 )
continue;
V_243 = V_8 [ V_229 ] + V_8 [ V_233 ] ;
V_242 = V_8 [ V_232 ] + V_8 [ V_231 ] ;
if ( ! V_243 || ! V_242 )
break;
if ( V_243 > V_242 ) {
unsigned long V_245 = V_237 [ V_232 ] +
V_237 [ V_231 ] + 1 ;
V_18 = V_246 ;
V_244 = V_242 * 100 / V_245 ;
} else {
unsigned long V_245 = V_237 [ V_229 ] +
V_237 [ V_233 ] + 1 ;
V_18 = V_207 ;
V_244 = V_243 * 100 / V_245 ;
}
V_8 [ V_18 ] = 0 ;
V_8 [ V_18 + V_202 ] = 0 ;
V_18 = ( V_18 == V_207 ) ? V_246 : V_207 ;
V_33 = V_237 [ V_18 ] - V_8 [ V_18 ] ;
V_8 [ V_18 ] = V_237 [ V_18 ] * ( 100 - V_244 ) / 100 ;
V_8 [ V_18 ] -= F_26 ( V_8 [ V_18 ] , V_33 ) ;
V_18 += V_202 ;
V_33 = V_237 [ V_18 ] - V_8 [ V_18 ] ;
V_8 [ V_18 ] = V_237 [ V_18 ] * ( 100 - V_244 ) / 100 ;
V_8 [ V_18 ] -= F_26 ( V_8 [ V_18 ] , V_33 ) ;
V_241 = true ;
}
F_192 ( & V_240 ) ;
V_2 -> V_121 += V_121 ;
if ( F_179 ( V_16 , false ) )
F_178 ( V_52 , V_16 ,
V_2 , V_231 ) ;
F_193 ( V_2 -> V_51 ) ;
}
static bool F_194 ( struct V_1 * V_2 )
{
if ( F_195 ( V_247 ) && V_2 -> V_172 &&
( V_2 -> V_172 > V_248 ||
V_2 -> V_148 < V_149 - 2 ) )
return true ;
return false ;
}
static inline bool F_196 ( struct V_7 * V_7 ,
unsigned long V_121 ,
unsigned long V_33 ,
struct V_1 * V_2 )
{
unsigned long V_249 ;
unsigned long V_250 ;
if ( ! F_194 ( V_2 ) )
return false ;
if ( V_2 -> V_51 & V_251 ) {
if ( ! V_121 && ! V_33 )
return false ;
} else {
if ( ! V_121 )
return false ;
}
V_249 = ( 2UL << V_2 -> V_172 ) ;
V_250 = F_12 ( V_7 , V_10 ) ;
if ( F_7 () > 0 )
V_250 += F_12 ( V_7 , V_13 ) ;
if ( V_2 -> V_121 < V_249 &&
V_250 > V_249 )
return true ;
switch ( F_197 ( V_7 , V_2 -> V_172 , 0 , 0 ) ) {
case V_252 :
case V_253 :
return false ;
default:
return true ;
}
}
static bool F_198 ( struct V_7 * V_7 , struct V_1 * V_2 ,
bool V_254 )
{
struct V_255 * V_255 = V_57 -> V_255 ;
unsigned long V_121 , V_33 ;
bool V_256 = false ;
do {
struct V_4 * V_257 = V_2 -> V_3 ;
struct V_258 V_259 = {
. V_7 = V_7 ,
. V_148 = V_2 -> V_148 ,
} ;
unsigned long V_260 = 0 ;
struct V_4 * V_5 ;
V_121 = V_2 -> V_121 ;
V_33 = V_2 -> V_33 ;
V_5 = F_40 ( V_257 , NULL , & V_259 ) ;
do {
unsigned long V_209 ;
unsigned long V_82 ;
unsigned long V_261 ;
if ( F_199 ( V_257 , V_5 ) ) {
if ( ! V_2 -> V_262 )
continue;
F_200 ( V_5 , V_263 , 1 ) ;
}
V_82 = V_2 -> V_121 ;
V_261 = V_2 -> V_33 ;
F_189 ( V_7 , V_5 , V_2 , & V_209 ) ;
V_260 += V_209 ;
if ( V_5 && V_254 )
F_33 ( V_2 -> V_51 , F_201 ( V_7 ) ,
V_5 , V_2 -> V_33 - V_261 ,
V_209 ) ;
F_202 ( V_2 -> V_51 , V_5 , false ,
V_2 -> V_33 - V_261 ,
V_2 -> V_121 - V_82 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_121 >= V_2 -> V_238 ) {
F_203 ( V_257 , V_5 ) ;
break;
}
} while ( ( V_5 = F_40 ( V_257 , V_5 , & V_259 ) ) );
if ( F_1 ( V_2 ) && V_254 )
F_33 ( V_2 -> V_51 , F_201 ( V_7 ) , NULL ,
V_2 -> V_33 - V_33 ,
V_260 ) ;
if ( V_255 ) {
V_2 -> V_121 += V_255 -> V_264 ;
V_255 -> V_264 = 0 ;
}
F_202 ( V_2 -> V_51 , V_2 -> V_3 , true ,
V_2 -> V_33 - V_33 ,
V_2 -> V_121 - V_121 ) ;
if ( V_2 -> V_121 - V_121 )
V_256 = true ;
} while ( F_196 ( V_7 , V_2 -> V_121 - V_121 ,
V_2 -> V_33 - V_33 , V_2 ) );
return V_256 ;
}
static inline bool F_204 ( struct V_7 * V_7 , int V_172 , int V_265 )
{
unsigned long V_266 , V_267 ;
bool V_268 ;
V_266 = F_26 ( F_205 ( V_7 ) , F_206 (
V_7 -> V_269 , V_270 ) ) ;
V_267 = F_185 ( V_7 ) + V_266 + ( 2UL << V_172 ) ;
V_268 = F_207 ( V_7 , 0 , V_267 , V_265 ) ;
if ( F_208 ( V_7 , V_172 ) )
return V_268 ;
if ( F_197 ( V_7 , V_172 , 0 , V_265 ) == V_271 )
return false ;
return V_268 ;
}
static void F_209 ( struct V_272 * V_272 , struct V_1 * V_2 )
{
struct V_273 * V_274 ;
struct V_7 * V_7 ;
unsigned long V_275 ;
unsigned long V_276 ;
T_2 V_277 ;
enum V_278 V_279 = F_210 ( V_2 -> V_51 ) ;
V_277 = V_2 -> V_51 ;
if ( V_201 )
V_2 -> V_51 |= V_280 ;
F_211 (zone, z, zonelist,
gfp_zone(sc->gfp_mask), sc->nodemask) {
enum V_278 V_265 ;
if ( ! F_212 ( V_7 ) )
continue;
V_265 = V_279 ;
while ( ! F_212 ( V_7 -> V_281 -> V_282 +
V_265 ) )
V_265 -- ;
if ( F_1 ( V_2 ) ) {
if ( ! F_213 ( V_7 ,
V_26 | V_283 ) )
continue;
if ( V_2 -> V_148 != V_149 &&
! F_8 ( V_7 ) )
continue;
if ( F_195 ( V_247 ) &&
V_2 -> V_172 > V_248 &&
F_214 ( V_274 ) <= V_279 &&
F_204 ( V_7 , V_2 -> V_172 , V_279 ) ) {
V_2 -> F_204 = true ;
continue;
}
V_276 = 0 ;
V_275 = F_215 ( V_7 ,
V_2 -> V_172 , V_2 -> V_51 ,
& V_276 ) ;
V_2 -> V_121 += V_275 ;
V_2 -> V_33 += V_276 ;
}
F_198 ( V_7 , V_2 , F_216 ( V_7 ) == V_265 ) ;
}
V_2 -> V_51 = V_277 ;
}
static unsigned long F_217 ( struct V_272 * V_272 ,
struct V_1 * V_2 )
{
int V_284 = V_2 -> V_148 ;
unsigned long V_285 = 0 ;
unsigned long V_286 ;
V_287:
F_218 () ;
if ( F_1 ( V_2 ) )
F_96 ( V_288 ) ;
do {
F_219 ( V_2 -> V_51 , V_2 -> V_3 ,
V_2 -> V_148 ) ;
V_2 -> V_33 = 0 ;
F_209 ( V_272 , V_2 ) ;
V_285 += V_2 -> V_33 ;
if ( V_2 -> V_121 >= V_2 -> V_238 )
break;
if ( V_2 -> F_204 )
break;
if ( V_2 -> V_148 < V_149 - 2 )
V_2 -> V_144 = 1 ;
V_286 = V_2 -> V_238 + V_2 -> V_238 / 2 ;
if ( V_285 > V_286 ) {
F_220 ( V_289 ? 0 : V_285 ,
V_290 ) ;
V_2 -> V_144 = 1 ;
}
} while ( -- V_2 -> V_148 >= 0 );
F_221 () ;
if ( V_2 -> V_121 )
return V_2 -> V_121 ;
if ( V_2 -> F_204 )
return 1 ;
if ( ! V_2 -> V_262 ) {
V_2 -> V_148 = V_284 ;
V_2 -> V_262 = 1 ;
goto V_287;
}
return 0 ;
}
static bool F_222 ( T_8 * V_291 )
{
struct V_7 * V_7 ;
unsigned long V_292 = 0 ;
unsigned long V_116 = 0 ;
int V_293 ;
bool V_294 ;
for ( V_293 = 0 ; V_293 <= V_295 ; V_293 ++ ) {
V_7 = & V_291 -> V_282 [ V_293 ] ;
if ( ! F_212 ( V_7 ) ||
F_5 ( V_7 ) == 0 )
continue;
V_292 += F_223 ( V_7 ) ;
V_116 += F_12 ( V_7 , V_227 ) ;
}
if ( ! V_292 )
return true ;
V_294 = V_116 > V_292 / 2 ;
if ( ! V_294 && F_224 ( & V_291 -> V_296 ) ) {
V_291 -> V_265 = F_26 ( V_291 -> V_265 ,
(enum V_278 ) V_295 ) ;
F_225 ( & V_291 -> V_296 ) ;
}
return V_294 ;
}
static bool F_226 ( T_2 V_51 , struct V_272 * V_272 ,
T_9 * V_297 )
{
struct V_273 * V_274 ;
struct V_7 * V_7 ;
T_8 * V_291 = NULL ;
if ( V_57 -> V_23 & V_298 )
goto V_53;
if ( F_168 ( V_57 ) )
goto V_53;
F_211 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_216 ( V_7 ) > V_295 )
continue;
V_291 = V_7 -> V_281 ;
if ( F_222 ( V_291 ) )
goto V_53;
break;
}
if ( ! V_291 )
goto V_53;
F_96 ( V_299 ) ;
if ( ! ( V_51 & V_132 ) ) {
F_227 ( V_291 -> V_300 ,
F_222 ( V_291 ) , V_185 ) ;
goto V_301;
}
F_228 ( V_7 -> V_281 -> V_300 ,
F_222 ( V_291 ) ) ;
V_301:
if ( F_168 ( V_57 ) )
return true ;
V_53:
return false ;
}
unsigned long F_229 ( struct V_272 * V_272 , int V_172 ,
T_2 V_51 , T_9 * V_297 )
{
unsigned long V_121 ;
struct V_1 V_2 = {
. V_238 = V_52 ,
. V_51 = ( V_51 = F_230 ( V_51 ) ) ,
. V_172 = V_172 ,
. V_297 = V_297 ,
. V_148 = V_149 ,
. V_144 = ! V_289 ,
. V_130 = 1 ,
. V_222 = 1 ,
} ;
if ( F_226 ( V_51 , V_272 , V_297 ) )
return 1 ;
F_231 ( V_172 ,
V_2 . V_144 ,
V_51 ) ;
V_121 = F_217 ( V_272 , & V_2 ) ;
F_232 ( V_121 ) ;
return V_121 ;
}
unsigned long F_233 ( struct V_4 * V_5 ,
T_2 V_51 , bool V_302 ,
struct V_7 * V_7 ,
unsigned long * V_33 )
{
struct V_1 V_2 = {
. V_238 = V_52 ,
. V_3 = V_5 ,
. V_144 = ! V_289 ,
. V_130 = 1 ,
. V_222 = ! V_302 ,
} ;
unsigned long V_209 ;
V_2 . V_51 = ( V_51 & V_303 ) |
( V_304 & ~ V_303 ) ;
F_234 ( V_2 . V_172 ,
V_2 . V_144 ,
V_2 . V_51 ) ;
F_189 ( V_7 , V_5 , & V_2 , & V_209 ) ;
F_235 ( V_2 . V_121 ) ;
* V_33 = V_2 . V_33 ;
return V_2 . V_121 ;
}
unsigned long F_236 ( struct V_4 * V_5 ,
unsigned long V_194 ,
T_2 V_51 ,
bool V_222 )
{
struct V_272 * V_272 ;
unsigned long V_121 ;
int V_40 ;
struct V_1 V_2 = {
. V_238 = F_237 ( V_194 , V_52 ) ,
. V_51 = ( V_51 & V_303 ) |
( V_304 & ~ V_303 ) ,
. V_3 = V_5 ,
. V_148 = V_149 ,
. V_144 = ! V_289 ,
. V_130 = 1 ,
. V_222 = V_222 ,
} ;
V_40 = F_238 ( V_5 ) ;
V_272 = F_239 ( V_40 ) -> V_305 ;
F_240 ( 0 ,
V_2 . V_144 ,
V_2 . V_51 ) ;
V_121 = F_217 ( V_272 , & V_2 ) ;
F_241 ( V_121 ) ;
return V_121 ;
}
static void F_242 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_206 )
return;
V_5 = F_40 ( NULL , NULL , NULL ) ;
do {
struct V_16 * V_16 = F_190 ( V_7 , V_5 ) ;
if ( F_179 ( V_16 , false ) )
F_178 ( V_52 , V_16 ,
V_2 , V_231 ) ;
V_5 = F_40 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_243 ( struct V_7 * V_7 , int V_172 , bool V_306 ,
unsigned long V_266 , int V_265 )
{
unsigned long V_307 = F_185 ( V_7 ) + V_266 ;
if ( F_195 ( V_247 ) && ! V_306 ) {
V_307 += ( 1UL << V_172 ) ;
V_172 = 0 ;
}
return F_207 ( V_7 , V_172 , V_307 , V_265 ) ;
}
static bool F_244 ( T_8 * V_291 , int V_172 , int V_265 )
{
unsigned long V_269 = 0 ;
unsigned long V_308 = 0 ;
int V_293 ;
for ( V_293 = 0 ; V_293 <= V_265 ; V_293 ++ ) {
struct V_7 * V_7 = V_291 -> V_282 + V_293 ;
if ( ! F_212 ( V_7 ) )
continue;
V_269 += V_7 -> V_269 ;
if ( ! F_8 ( V_7 ) ) {
V_308 += V_7 -> V_269 ;
continue;
}
if ( F_243 ( V_7 , V_172 , false , 0 , V_293 ) )
V_308 += V_7 -> V_269 ;
else if ( ! V_172 )
return false ;
}
if ( V_172 )
return V_308 >= ( V_269 >> 2 ) ;
else
return true ;
}
static bool F_245 ( T_8 * V_291 , int V_172 , long V_309 ,
int V_265 )
{
if ( V_309 )
return false ;
if ( F_224 ( & V_291 -> V_300 ) )
F_246 ( & V_291 -> V_300 ) ;
return F_244 ( V_291 , V_172 , V_265 ) ;
}
static bool F_247 ( struct V_7 * V_7 ,
int V_265 ,
struct V_1 * V_2 )
{
unsigned long V_266 ;
bool V_310 ;
V_2 -> V_238 = F_237 ( V_52 , F_185 ( V_7 ) ) ;
V_266 = F_26 ( F_205 ( V_7 ) , F_206 (
V_7 -> V_269 , V_270 ) ) ;
V_310 = ( V_201 && F_248 ( V_7 ) ) ;
if ( ! V_310 && F_243 ( V_7 , V_2 -> V_172 , false ,
V_266 , V_265 ) )
return true ;
F_198 ( V_7 , V_2 , F_216 ( V_7 ) == V_265 ) ;
F_249 ( V_134 , & V_7 -> V_23 ) ;
if ( F_8 ( V_7 ) &&
F_243 ( V_7 , V_2 -> V_172 , false , 0 , V_265 ) ) {
F_249 ( V_191 , & V_7 -> V_23 ) ;
F_249 ( V_142 , & V_7 -> V_23 ) ;
}
return V_2 -> V_33 >= V_2 -> V_238 ;
}
static int F_250 ( T_8 * V_291 , int V_172 , int V_265 )
{
int V_293 ;
int V_311 = 0 ;
unsigned long V_275 ;
unsigned long V_276 ;
struct V_1 V_2 = {
. V_51 = V_26 ,
. V_172 = V_172 ,
. V_148 = V_149 ,
. V_144 = ! V_289 ,
. V_130 = 1 ,
. V_222 = 1 ,
} ;
F_96 ( V_312 ) ;
do {
bool V_313 = true ;
V_2 . V_121 = 0 ;
for ( V_293 = V_291 -> V_314 - 1 ; V_293 >= 0 ; V_293 -- ) {
struct V_7 * V_7 = V_291 -> V_282 + V_293 ;
if ( ! F_212 ( V_7 ) )
continue;
if ( V_2 . V_148 != V_149 &&
! F_8 ( V_7 ) )
continue;
F_242 ( V_7 , & V_2 ) ;
if ( V_201 && F_251 ( V_293 ) ) {
V_311 = V_293 ;
break;
}
if ( ! F_243 ( V_7 , V_172 , false , 0 , 0 ) ) {
V_311 = V_293 ;
break;
} else {
F_249 ( V_191 , & V_7 -> V_23 ) ;
F_249 ( V_142 , & V_7 -> V_23 ) ;
}
}
if ( V_293 < 0 )
goto V_53;
if ( V_2 . V_148 < V_149 - 2 )
V_2 . V_144 = 1 ;
for ( V_293 = 0 ; V_293 <= V_311 ; V_293 ++ ) {
struct V_7 * V_7 = V_291 -> V_282 + V_293 ;
if ( ! F_212 ( V_7 ) )
continue;
if ( V_2 . V_148 != V_149 &&
! F_8 ( V_7 ) )
continue;
V_2 . V_33 = 0 ;
V_276 = 0 ;
V_275 = F_215 ( V_7 ,
V_172 , V_2 . V_51 ,
& V_276 ) ;
V_2 . V_121 += V_275 ;
if ( F_247 ( V_7 , V_311 , & V_2 ) )
V_313 = false ;
}
if ( F_224 ( & V_291 -> V_300 ) &&
F_222 ( V_291 ) )
F_246 ( & V_291 -> V_300 ) ;
if ( F_252 () || F_253 () )
break;
if ( V_313 || ! V_2 . V_121 )
V_2 . V_148 -- ;
} while ( V_2 . V_148 >= 1 &&
! F_244 ( V_291 , V_172 , V_265 ) );
V_53:
return V_311 ;
}
static void F_254 ( T_8 * V_291 , int V_172 ,
int V_265 , int V_315 )
{
long V_309 = 0 ;
F_255 ( V_316 ) ;
if ( F_256 ( V_57 ) || F_253 () )
return;
F_257 ( & V_291 -> V_296 , & V_316 , V_317 ) ;
if ( F_245 ( V_291 , V_172 , V_309 ,
V_315 ) ) {
F_258 ( V_291 ) ;
F_259 ( V_291 , V_172 , V_265 ) ;
V_309 = F_260 ( V_185 / 10 ) ;
F_261 ( & V_291 -> V_296 , & V_316 ) ;
F_257 ( & V_291 -> V_296 , & V_316 , V_317 ) ;
}
if ( F_245 ( V_291 , V_172 , V_309 ,
V_315 ) ) {
F_262 ( V_291 -> V_318 ) ;
F_263 ( V_291 , V_319 ) ;
if ( ! F_253 () )
F_264 () ;
F_263 ( V_291 , V_320 ) ;
} else {
if ( V_309 )
F_96 ( V_321 ) ;
else
F_96 ( V_322 ) ;
}
F_261 ( & V_291 -> V_296 , & V_316 ) ;
}
static int F_265 ( void * V_323 )
{
unsigned long V_172 , V_324 ;
int V_265 , V_325 ;
int V_315 ;
T_8 * V_291 = ( T_8 * ) V_323 ;
struct V_326 * V_327 = V_57 ;
struct V_255 V_255 = {
. V_264 = 0 ,
} ;
const struct V_328 * V_328 = F_266 ( V_291 -> V_318 ) ;
F_267 ( V_26 ) ;
if ( ! F_268 ( V_328 ) )
F_269 ( V_327 , V_328 ) ;
V_57 -> V_255 = & V_255 ;
V_327 -> V_23 |= V_329 | V_58 | V_330 ;
F_270 () ;
V_172 = V_324 = 0 ;
V_265 = V_325 = V_291 -> V_314 - 1 ;
V_315 = V_265 ;
for ( ; ; ) {
bool V_47 ;
V_324 = V_291 -> V_331 ;
V_325 = V_291 -> V_265 ;
V_291 -> V_331 = 0 ;
V_291 -> V_265 = V_291 -> V_314 - 1 ;
if ( V_172 < V_324 || V_265 > V_325 ) {
V_172 = V_324 ;
V_265 = V_325 ;
} else {
F_254 ( V_291 , V_172 , V_265 ,
V_315 ) ;
V_172 = V_291 -> V_331 ;
V_265 = V_291 -> V_265 ;
V_324 = V_172 ;
V_325 = V_265 ;
V_291 -> V_331 = 0 ;
V_291 -> V_265 = V_291 -> V_314 - 1 ;
}
V_47 = F_252 () ;
if ( F_253 () )
break;
if ( ! V_47 ) {
F_271 ( V_291 -> V_318 , V_172 ) ;
V_315 = F_250 ( V_291 , V_172 ,
V_265 ) ;
}
}
V_327 -> V_23 &= ~ ( V_329 | V_58 | V_330 ) ;
V_57 -> V_255 = NULL ;
F_272 () ;
return 0 ;
}
void F_273 ( struct V_7 * V_7 , int V_172 , enum V_278 V_265 )
{
T_8 * V_291 ;
if ( ! F_212 ( V_7 ) )
return;
if ( ! F_213 ( V_7 , V_26 | V_283 ) )
return;
V_291 = V_7 -> V_281 ;
if ( V_291 -> V_331 < V_172 ) {
V_291 -> V_331 = V_172 ;
V_291 -> V_265 = F_26 ( V_291 -> V_265 , V_265 ) ;
}
if ( ! F_224 ( & V_291 -> V_296 ) )
return;
if ( F_243 ( V_7 , V_172 , true , 0 , 0 ) )
return;
F_274 ( V_291 -> V_318 , F_216 ( V_7 ) , V_172 ) ;
F_225 ( & V_291 -> V_296 ) ;
}
unsigned long F_275 ( unsigned long V_238 )
{
struct V_255 V_255 ;
struct V_1 V_2 = {
. V_238 = V_238 ,
. V_51 = V_304 ,
. V_148 = V_149 ,
. V_144 = 1 ,
. V_130 = 1 ,
. V_222 = 1 ,
. V_192 = 1 ,
} ;
struct V_272 * V_272 = F_276 ( F_277 () , V_2 . V_51 ) ;
struct V_326 * V_323 = V_57 ;
unsigned long V_121 ;
V_323 -> V_23 |= V_329 ;
F_267 ( V_2 . V_51 ) ;
V_255 . V_264 = 0 ;
V_323 -> V_255 = & V_255 ;
V_121 = F_217 ( V_272 , & V_2 ) ;
V_323 -> V_255 = NULL ;
F_272 () ;
V_323 -> V_23 &= ~ V_329 ;
return V_121 ;
}
static int F_278 ( struct V_332 * V_333 , unsigned long V_334 ,
void * V_335 )
{
int V_40 ;
if ( V_334 == V_336 || V_334 == V_337 ) {
F_279 (nid, N_MEMORY) {
T_8 * V_291 = F_239 ( V_40 ) ;
const struct V_328 * V_338 ;
V_338 = F_266 ( V_291 -> V_318 ) ;
if ( F_280 ( V_339 , V_338 ) < V_340 )
F_269 ( V_291 -> F_265 , V_338 ) ;
}
}
return V_341 ;
}
int F_281 ( int V_40 )
{
T_8 * V_291 = F_239 ( V_40 ) ;
int V_47 = 0 ;
if ( V_291 -> F_265 )
return 0 ;
V_291 -> F_265 = F_282 ( F_265 , V_291 , L_4 , V_40 ) ;
if ( F_283 ( V_291 -> F_265 ) ) {
F_65 ( V_342 == V_343 ) ;
F_25 ( L_5 , V_40 ) ;
V_47 = F_284 ( V_291 -> F_265 ) ;
V_291 -> F_265 = NULL ;
}
return V_47 ;
}
void F_285 ( int V_40 )
{
struct V_326 * F_265 = F_239 ( V_40 ) -> F_265 ;
if ( F_265 ) {
F_286 ( F_265 ) ;
F_239 ( V_40 ) -> F_265 = NULL ;
}
}
static int T_10 F_287 ( void )
{
int V_40 ;
F_288 () ;
F_279 (nid, N_MEMORY)
F_281 ( V_40 ) ;
F_289 ( F_278 , 0 ) ;
return 0 ;
}
static inline unsigned long F_290 ( struct V_7 * V_7 )
{
unsigned long V_344 = F_12 ( V_7 , V_345 ) ;
unsigned long V_346 = F_12 ( V_7 , V_10 ) +
F_12 ( V_7 , V_9 ) ;
return ( V_346 > V_344 ) ? ( V_346 - V_344 ) : 0 ;
}
static unsigned long F_291 ( struct V_7 * V_7 )
{
unsigned long V_347 ;
unsigned long V_36 = 0 ;
if ( V_348 & V_349 )
V_347 = F_12 ( V_7 , V_350 ) ;
else
V_347 = F_290 ( V_7 ) ;
if ( ! ( V_348 & V_351 ) )
V_36 += F_12 ( V_7 , V_352 ) ;
if ( F_69 ( V_36 > V_347 ) )
V_36 = V_347 ;
return V_347 - V_36 ;
}
static int F_292 ( struct V_7 * V_7 , T_2 V_51 , unsigned int V_172 )
{
const unsigned long V_194 = 1 << V_172 ;
struct V_326 * V_323 = V_57 ;
struct V_255 V_255 ;
struct V_1 V_2 = {
. V_238 = F_237 ( V_194 , V_52 ) ,
. V_51 = ( V_51 = F_230 ( V_51 ) ) ,
. V_172 = V_172 ,
. V_148 = V_353 ,
. V_144 = ! ! ( V_348 & V_351 ) ,
. V_130 = ! ! ( V_348 & V_349 ) ,
. V_222 = 1 ,
} ;
F_29 () ;
V_323 -> V_23 |= V_329 | V_58 ;
F_267 ( V_51 ) ;
V_255 . V_264 = 0 ;
V_323 -> V_255 = & V_255 ;
if ( F_291 ( V_7 ) > V_7 -> V_354 ) {
do {
F_198 ( V_7 , & V_2 , true ) ;
} while ( V_2 . V_121 < V_194 && -- V_2 . V_148 >= 0 );
}
V_323 -> V_255 = NULL ;
V_57 -> V_23 &= ~ ( V_329 | V_58 ) ;
F_272 () ;
return V_2 . V_121 >= V_194 ;
}
int F_293 ( struct V_7 * V_7 , T_2 V_51 , unsigned int V_172 )
{
int V_318 ;
int V_47 ;
if ( F_291 ( V_7 ) <= V_7 -> V_354 &&
F_12 ( V_7 , V_355 ) <= V_7 -> V_356 )
return V_357 ;
if ( ! F_8 ( V_7 ) )
return V_357 ;
if ( ! F_294 ( V_51 ) || ( V_57 -> V_23 & V_329 ) )
return V_358 ;
V_318 = F_201 ( V_7 ) ;
if ( F_295 ( V_318 , V_359 ) && V_318 != F_277 () )
return V_358 ;
if ( F_296 ( V_360 , & V_7 -> V_23 ) )
return V_358 ;
V_47 = F_292 ( V_7 , V_51 , V_172 ) ;
F_249 ( V_360 , & V_7 -> V_23 ) ;
if ( ! V_47 )
F_96 ( V_361 ) ;
return V_47 ;
}
int F_90 ( struct V_55 * V_55 )
{
return ! F_297 ( F_51 ( V_55 ) ) && ! F_298 ( V_55 ) ;
}
void F_299 ( struct V_55 * * V_362 , int V_194 )
{
struct V_16 * V_16 ;
struct V_7 * V_7 = NULL ;
int V_363 = 0 ;
int V_364 = 0 ;
int V_293 ;
for ( V_293 = 0 ; V_293 < V_194 ; V_293 ++ ) {
struct V_55 * V_55 = V_362 [ V_293 ] ;
struct V_7 * V_365 ;
V_363 ++ ;
V_365 = F_109 ( V_55 ) ;
if ( V_365 != V_7 ) {
if ( V_7 )
F_153 ( & V_7 -> V_173 ) ;
V_7 = V_365 ;
F_148 ( & V_7 -> V_173 ) ;
}
V_16 = F_149 ( V_55 , V_7 ) ;
if ( ! F_88 ( V_55 ) || ! F_86 ( V_55 ) )
continue;
if ( F_90 ( V_55 ) ) {
enum V_17 V_18 = F_300 ( V_55 ) ;
F_87 ( F_108 ( V_55 ) , V_55 ) ;
F_89 ( V_55 ) ;
F_152 ( V_55 , V_16 , V_366 ) ;
F_157 ( V_55 , V_16 , V_18 ) ;
V_364 ++ ;
}
}
if ( V_7 ) {
F_177 ( V_91 , V_364 ) ;
F_177 ( V_367 , V_363 ) ;
F_153 ( & V_7 -> V_173 ) ;
}
}
