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
if ( F_4 ( F_5 ( V_5 ) -> V_6 ) )
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
static unsigned long F_6 ( struct V_7 * V_7 )
{
int V_8 ;
V_8 = F_7 ( V_7 , V_9 ) +
F_7 ( V_7 , V_10 ) ;
if ( F_8 () > 0 )
V_8 += F_7 ( V_7 , V_11 ) +
F_7 ( V_7 , V_12 ) ;
return V_8 ;
}
bool F_9 ( struct V_7 * V_7 )
{
return F_7 ( V_7 , V_13 ) <
F_6 ( V_7 ) * 6 ;
}
static unsigned long F_10 ( struct V_14 * V_14 , enum V_15 V_16 )
{
if ( ! F_11 () )
return F_12 ( V_14 , V_16 ) ;
return F_7 ( F_13 ( V_14 ) , V_17 + V_16 ) ;
}
int F_14 ( struct V_18 * V_18 )
{
T_1 V_19 = sizeof( * V_18 -> V_20 ) ;
if ( V_21 == 1 )
V_18 -> V_22 &= ~ V_23 ;
if ( V_18 -> V_22 & V_23 )
V_19 *= V_21 ;
V_18 -> V_20 = F_15 ( V_19 , V_24 ) ;
if ( ! V_18 -> V_20 )
return - V_25 ;
F_16 ( & V_26 ) ;
F_17 ( & V_18 -> V_27 , & V_28 ) ;
F_18 ( & V_26 ) ;
return 0 ;
}
void F_19 ( struct V_18 * V_18 )
{
F_16 ( & V_26 ) ;
F_20 ( & V_18 -> V_27 ) ;
F_18 ( & V_26 ) ;
F_21 ( V_18 -> V_20 ) ;
}
static unsigned long F_22 ( struct V_29 * V_30 ,
struct V_18 * V_18 ,
unsigned long V_31 ,
unsigned long V_32 )
{
unsigned long V_33 = 0 ;
unsigned long long V_34 ;
long V_35 ;
long V_36 ;
long V_8 ;
long V_37 ;
int V_38 = V_30 -> V_38 ;
long V_39 = V_18 -> V_40 ? V_18 -> V_40
: V_41 ;
V_36 = V_18 -> V_42 ( V_18 , V_30 ) ;
if ( V_36 == 0 )
return 0 ;
V_8 = F_23 ( & V_18 -> V_20 [ V_38 ] , 0 ) ;
V_35 = V_8 ;
V_34 = ( 4 * V_31 ) / V_18 -> V_43 ;
V_34 *= V_36 ;
F_24 ( V_34 , V_32 + 1 ) ;
V_35 += V_34 ;
if ( V_35 < 0 ) {
F_25 ( L_1 ,
V_18 -> V_44 , V_35 ) ;
V_35 = V_36 ;
}
if ( V_34 < V_36 / 4 )
V_35 = F_26 ( V_35 , V_36 / 2 ) ;
if ( V_35 > V_36 * 2 )
V_35 = V_36 * 2 ;
F_27 ( V_18 , V_30 , V_8 ,
V_31 , V_32 ,
V_36 , V_34 , V_35 ) ;
while ( V_35 >= V_39 ||
V_35 >= V_36 ) {
unsigned long V_45 ;
unsigned long V_46 = F_26 ( V_39 , V_35 ) ;
V_30 -> V_46 = V_46 ;
V_45 = V_18 -> V_44 ( V_18 , V_30 ) ;
if ( V_45 == V_47 )
break;
V_33 += V_45 ;
F_28 ( V_48 , V_46 ) ;
V_35 -= V_46 ;
F_29 () ;
}
if ( V_35 > 0 )
V_37 = F_30 ( V_35 ,
& V_18 -> V_20 [ V_38 ] ) ;
else
V_37 = F_31 ( & V_18 -> V_20 [ V_38 ] ) ;
F_32 ( V_18 , V_38 , V_33 , V_8 , V_37 , V_35 ) ;
return V_33 ;
}
static unsigned long F_33 ( T_2 V_49 , int V_38 ,
struct V_4 * V_5 ,
unsigned long V_31 ,
unsigned long V_32 )
{
struct V_18 * V_18 ;
unsigned long V_33 = 0 ;
if ( V_5 && ! F_34 ( V_5 ) )
return 0 ;
if ( V_31 == 0 )
V_31 = V_50 ;
if ( ! F_35 ( & V_26 ) ) {
V_33 = 1 ;
goto V_51;
}
F_36 (shrinker, &shrinker_list, list) {
struct V_29 V_2 = {
. V_49 = V_49 ,
. V_38 = V_38 ,
. V_5 = V_5 ,
} ;
if ( V_5 && ! ( V_18 -> V_22 & V_52 ) )
continue;
if ( ! ( V_18 -> V_22 & V_23 ) )
V_2 . V_38 = 0 ;
V_33 += F_22 ( & V_2 , V_18 , V_31 , V_32 ) ;
}
F_37 ( & V_26 ) ;
V_51:
F_29 () ;
return V_33 ;
}
void F_38 ( int V_38 )
{
unsigned long V_33 ;
do {
struct V_4 * V_5 = NULL ;
V_33 = 0 ;
do {
V_33 += F_33 ( V_24 , V_38 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_39 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_33 > 10 );
}
void F_40 ( void )
{
int V_38 ;
F_41 (nid)
F_38 ( V_38 ) ;
}
static inline int F_42 ( struct V_53 * V_53 )
{
return F_43 ( V_53 ) - F_44 ( V_53 ) == 2 ;
}
static int F_45 ( struct V_54 * V_54 , struct V_1 * V_2 )
{
if ( V_55 -> V_22 & V_56 )
return 1 ;
if ( ! F_46 ( V_54 ) )
return 1 ;
if ( F_47 ( V_54 ) == V_55 -> V_57 )
return 1 ;
return 0 ;
}
static void F_48 ( struct V_58 * V_59 ,
struct V_53 * V_53 , int error )
{
F_49 ( V_53 ) ;
if ( F_50 ( V_53 ) == V_59 )
F_51 ( V_59 , error ) ;
F_52 ( V_53 ) ;
}
static T_3 F_53 ( struct V_53 * V_53 , struct V_58 * V_59 ,
struct V_1 * V_2 )
{
if ( ! F_42 ( V_53 ) )
return V_60 ;
if ( ! V_59 ) {
if ( F_44 ( V_53 ) ) {
if ( F_54 ( V_53 ) ) {
F_55 ( V_53 ) ;
F_56 ( L_2 , V_61 ) ;
return V_62 ;
}
}
return V_60 ;
}
if ( V_59 -> V_63 -> V_64 == NULL )
return V_65 ;
if ( ! F_45 ( V_59 -> V_66 , V_2 ) )
return V_60 ;
if ( F_57 ( V_53 ) ) {
int V_67 ;
struct V_68 V_69 = {
. V_70 = V_71 ,
. V_72 = V_50 ,
. V_73 = 0 ,
. V_74 = V_75 ,
. V_76 = 1 ,
} ;
F_58 ( V_53 ) ;
V_67 = V_59 -> V_63 -> V_64 ( V_53 , & V_69 ) ;
if ( V_67 < 0 )
F_48 ( V_59 , V_53 , V_67 ) ;
if ( V_67 == V_77 ) {
F_59 ( V_53 ) ;
return V_65 ;
}
if ( ! F_60 ( V_53 ) ) {
F_59 ( V_53 ) ;
}
F_61 ( V_53 , F_62 ( V_53 ) ) ;
F_63 ( V_53 , V_78 ) ;
return V_79 ;
}
return V_62 ;
}
static int F_64 ( struct V_58 * V_59 , struct V_53 * V_53 ,
bool V_80 )
{
unsigned long V_22 ;
struct V_4 * V_5 ;
F_65 ( ! F_66 ( V_53 ) ) ;
F_65 ( V_59 != F_50 ( V_53 ) ) ;
V_5 = F_67 ( V_53 ) ;
F_68 ( & V_59 -> V_81 , V_22 ) ;
if ( ! F_69 ( V_53 , 2 ) )
goto V_82;
if ( F_70 ( F_71 ( V_53 ) ) ) {
F_72 ( V_53 , 2 ) ;
goto V_82;
}
if ( F_73 ( V_53 ) ) {
T_4 V_83 = { . V_84 = F_74 (page) } ;
F_75 ( V_53 , V_83 ) ;
F_76 ( V_53 ) ;
F_77 ( & V_59 -> V_81 , V_22 ) ;
F_78 ( V_5 ) ;
F_79 ( V_83 ) ;
} else {
void (* F_80)( struct V_53 * );
void * V_85 = NULL ;
F_80 = V_59 -> V_63 -> F_80 ;
if ( V_80 && F_81 ( V_53 ) &&
! F_82 ( V_59 ) )
V_85 = F_83 ( V_59 , V_53 ) ;
F_84 ( V_53 , V_85 , V_5 ) ;
F_77 ( & V_59 -> V_81 , V_22 ) ;
F_78 ( V_5 ) ;
if ( F_80 != NULL )
F_80 ( V_53 ) ;
}
return 1 ;
V_82:
F_77 ( & V_59 -> V_81 , V_22 ) ;
F_78 ( V_5 ) ;
return 0 ;
}
int F_85 ( struct V_58 * V_59 , struct V_53 * V_53 )
{
if ( F_64 ( V_59 , V_53 , false ) ) {
F_72 ( V_53 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_86 ( struct V_53 * V_53 )
{
bool V_86 ;
int V_87 = F_87 ( V_53 ) ;
F_88 ( F_89 ( V_53 ) , V_53 ) ;
V_88:
F_90 ( V_53 ) ;
if ( F_91 ( V_53 ) ) {
V_86 = false ;
F_92 ( V_53 ) ;
} else {
V_86 = true ;
F_93 ( V_53 ) ;
F_94 () ;
}
if ( V_86 && F_91 ( V_53 ) ) {
if ( ! F_95 ( V_53 ) ) {
F_96 ( V_53 ) ;
goto V_88;
}
}
if ( V_87 && ! V_86 )
F_97 ( V_89 ) ;
else if ( ! V_87 && V_86 )
F_97 ( V_90 ) ;
F_96 ( V_53 ) ;
}
static enum V_91 F_98 ( struct V_53 * V_53 ,
struct V_1 * V_2 )
{
int V_92 , V_93 ;
unsigned long V_94 ;
V_92 = F_99 ( V_53 , 1 , V_2 -> V_3 ,
& V_94 ) ;
V_93 = F_100 ( V_53 ) ;
if ( V_94 & V_95 )
return V_96 ;
if ( V_92 ) {
if ( F_101 ( V_53 ) )
return V_97 ;
F_102 ( V_53 ) ;
if ( V_93 || V_92 > 1 )
return V_97 ;
if ( V_94 & V_98 )
return V_97 ;
return V_99 ;
}
if ( V_93 && ! F_101 ( V_53 ) )
return V_100 ;
return V_96 ;
}
static void F_103 ( struct V_53 * V_53 ,
bool * V_101 , bool * V_102 )
{
struct V_58 * V_59 ;
if ( ! F_81 ( V_53 ) ) {
* V_101 = false ;
* V_102 = false ;
return;
}
* V_101 = F_71 ( V_53 ) ;
* V_102 = F_60 ( V_53 ) ;
if ( ! F_44 ( V_53 ) )
return;
V_59 = F_50 ( V_53 ) ;
if ( V_59 && V_59 -> V_63 -> V_103 )
V_59 -> V_63 -> V_103 ( V_53 , V_101 , V_102 ) ;
}
static unsigned long F_104 ( struct V_104 * V_105 ,
struct V_7 * V_7 ,
struct V_1 * V_2 ,
enum V_106 V_106 ,
unsigned long * V_107 ,
unsigned long * V_108 ,
unsigned long * V_109 ,
unsigned long * V_110 ,
unsigned long * V_111 ,
bool V_112 )
{
F_105 ( V_113 ) ;
F_105 ( V_114 ) ;
int V_115 = 0 ;
unsigned long V_116 = 0 ;
unsigned long V_117 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
unsigned long V_121 = 0 ;
F_29 () ;
while ( ! F_106 ( V_105 ) ) {
struct V_58 * V_59 ;
struct V_53 * V_53 ;
int V_122 ;
enum V_91 V_123 = V_100 ;
bool V_101 , V_102 ;
F_29 () ;
V_53 = F_107 ( V_105 ) ;
F_20 ( & V_53 -> V_16 ) ;
if ( ! F_108 ( V_53 ) )
goto V_124;
F_88 ( F_109 ( V_53 ) , V_53 ) ;
F_88 ( F_110 ( V_53 ) != V_7 , V_53 ) ;
V_2 -> V_31 ++ ;
if ( F_70 ( ! F_91 ( V_53 ) ) )
goto V_125;
if ( ! V_2 -> V_126 && F_111 ( V_53 ) )
goto V_127;
if ( F_111 ( V_53 ) || F_73 ( V_53 ) )
V_2 -> V_31 ++ ;
V_122 = ( V_2 -> V_49 & V_128 ) ||
( F_73 ( V_53 ) && ( V_2 -> V_49 & V_129 ) ) ;
F_103 ( V_53 , & V_101 , & V_102 ) ;
if ( V_101 || V_102 )
V_117 ++ ;
if ( V_101 && ! V_102 )
V_116 ++ ;
V_59 = F_50 ( V_53 ) ;
if ( ( ( V_101 || V_102 ) && V_59 &&
F_46 ( V_59 -> V_66 ) ) ||
( V_102 && F_112 ( V_53 ) ) )
V_118 ++ ;
if ( F_60 ( V_53 ) ) {
if ( F_113 () &&
F_112 ( V_53 ) &&
F_114 ( V_130 , & V_7 -> V_22 ) ) {
V_121 ++ ;
goto V_127;
} else if ( F_2 ( V_2 ) ||
! F_112 ( V_53 ) || ! V_122 ) {
F_58 ( V_53 ) ;
V_120 ++ ;
goto V_127;
} else {
F_115 ( V_53 ) ;
}
}
if ( ! V_112 )
V_123 = F_98 ( V_53 , V_2 ) ;
switch ( V_123 ) {
case V_97 :
goto V_131;
case V_99 :
goto V_127;
case V_96 :
case V_100 :
;
}
if ( F_116 ( V_53 ) && ! F_73 ( V_53 ) ) {
if ( ! ( V_2 -> V_49 & V_129 ) )
goto V_127;
if ( ! F_117 ( V_53 , V_105 ) )
goto V_131;
V_122 = 1 ;
V_59 = F_50 ( V_53 ) ;
}
if ( F_111 ( V_53 ) && V_59 ) {
switch ( F_118 ( V_53 , V_106 ) ) {
case V_132 :
goto V_131;
case V_133 :
goto V_127;
case V_134 :
goto V_125;
case V_135 :
;
}
}
if ( F_71 ( V_53 ) ) {
if ( F_81 ( V_53 ) &&
( ! F_113 () ||
! F_114 ( V_136 , & V_7 -> V_22 ) ) ) {
F_63 ( V_53 , V_137 ) ;
F_58 ( V_53 ) ;
goto V_127;
}
if ( V_123 == V_100 )
goto V_127;
if ( ! V_122 )
goto V_127;
if ( ! V_2 -> V_138 )
goto V_127;
switch ( F_53 ( V_53 , V_59 , V_2 ) ) {
case V_60 :
goto V_127;
case V_65 :
goto V_131;
case V_79 :
if ( F_60 ( V_53 ) )
goto V_124;
if ( F_71 ( V_53 ) )
goto V_124;
if ( ! F_108 ( V_53 ) )
goto V_124;
if ( F_71 ( V_53 ) || F_60 ( V_53 ) )
goto V_127;
V_59 = F_50 ( V_53 ) ;
case V_62 :
;
}
}
if ( F_44 ( V_53 ) ) {
if ( ! F_119 ( V_53 , V_2 -> V_49 ) )
goto V_131;
if ( ! V_59 && F_43 ( V_53 ) == 1 ) {
F_52 ( V_53 ) ;
if ( F_120 ( V_53 ) )
goto V_139;
else {
V_119 ++ ;
continue;
}
}
}
if ( ! V_59 || ! F_64 ( V_59 , V_53 , true ) )
goto V_127;
F_121 ( V_53 ) ;
V_139:
V_119 ++ ;
F_122 ( & V_53 -> V_16 , & V_114 ) ;
continue;
V_125:
if ( F_73 ( V_53 ) )
F_123 ( V_53 ) ;
F_52 ( V_53 ) ;
F_86 ( V_53 ) ;
continue;
V_131:
if ( F_73 ( V_53 ) && F_124 () )
F_123 ( V_53 ) ;
F_88 ( F_109 ( V_53 ) , V_53 ) ;
F_125 ( V_53 ) ;
V_115 ++ ;
V_127:
F_52 ( V_53 ) ;
V_124:
F_122 ( & V_53 -> V_16 , & V_113 ) ;
F_88 ( F_89 ( V_53 ) || F_87 ( V_53 ) , V_53 ) ;
}
F_126 ( & V_114 ) ;
F_127 ( & V_114 , true ) ;
F_128 ( & V_113 , V_105 ) ;
F_28 ( V_140 , V_115 ) ;
* V_107 += V_117 ;
* V_109 += V_118 ;
* V_108 += V_116 ;
* V_110 += V_120 ;
* V_111 += V_121 ;
return V_119 ;
}
unsigned long F_129 ( struct V_7 * V_7 ,
struct V_104 * V_105 )
{
struct V_1 V_2 = {
. V_49 = V_24 ,
. V_141 = V_142 ,
. V_126 = 1 ,
} ;
unsigned long V_45 , V_143 , V_144 , V_145 , V_146 , V_147 ;
struct V_53 * V_53 , * V_148 ;
F_105 ( V_149 ) ;
F_130 (page, next, page_list, lru) {
if ( F_81 ( V_53 ) && ! F_71 ( V_53 ) &&
! F_131 ( V_53 ) ) {
F_132 ( V_53 ) ;
F_133 ( & V_53 -> V_16 , & V_149 ) ;
}
}
V_45 = F_104 ( & V_149 , V_7 , & V_2 ,
V_150 | V_151 ,
& V_143 , & V_144 , & V_145 , & V_146 , & V_147 , true ) ;
F_128 ( & V_149 , V_105 ) ;
F_134 ( V_7 , V_152 , - V_45 ) ;
return V_45 ;
}
int F_135 ( struct V_53 * V_53 , T_5 V_153 )
{
int V_45 = - V_154 ;
if ( ! F_89 ( V_53 ) )
return V_45 ;
if ( F_87 ( V_53 ) && ! ( V_153 & V_155 ) )
return V_45 ;
V_45 = - V_156 ;
if ( V_153 & ( V_157 | V_158 ) ) {
if ( F_60 ( V_53 ) )
return V_45 ;
if ( F_71 ( V_53 ) ) {
struct V_58 * V_59 ;
if ( V_153 & V_157 )
return V_45 ;
V_59 = F_50 ( V_53 ) ;
if ( V_59 && ! V_59 -> V_63 -> V_159 )
return V_45 ;
}
}
if ( ( V_153 & V_160 ) && F_111 ( V_53 ) )
return V_45 ;
if ( F_136 ( F_137 ( V_53 ) ) ) {
F_138 ( V_53 ) ;
V_45 = 0 ;
}
return V_45 ;
}
static unsigned long F_139 ( unsigned long V_46 ,
struct V_14 * V_14 , struct V_104 * V_161 ,
unsigned long * V_31 , struct V_1 * V_2 ,
T_5 V_153 , enum V_15 V_16 )
{
struct V_104 * V_162 = & V_14 -> V_163 [ V_16 ] ;
unsigned long V_164 = 0 ;
unsigned long V_165 ;
for ( V_165 = 0 ; V_165 < V_46 && ! F_106 ( V_162 ) ; V_165 ++ ) {
struct V_53 * V_53 ;
int V_166 ;
V_53 = F_107 ( V_162 ) ;
F_140 ( V_53 , V_162 , V_22 ) ;
F_88 ( ! F_89 ( V_53 ) , V_53 ) ;
switch ( F_135 ( V_53 , V_153 ) ) {
case 0 :
V_166 = F_141 ( V_53 ) ;
F_142 ( V_14 , V_16 , - V_166 ) ;
F_133 ( & V_53 -> V_16 , V_161 ) ;
V_164 += V_166 ;
break;
case - V_156 :
F_133 ( & V_53 -> V_16 , V_162 ) ;
continue;
default:
F_143 () ;
}
}
* V_31 = V_165 ;
F_144 ( V_2 -> V_167 , V_46 , V_165 ,
V_164 , V_153 , F_145 ( V_16 ) ) ;
return V_164 ;
}
int F_95 ( struct V_53 * V_53 )
{
int V_45 = - V_156 ;
F_88 ( ! F_43 ( V_53 ) , V_53 ) ;
if ( F_89 ( V_53 ) ) {
struct V_7 * V_7 = F_110 ( V_53 ) ;
struct V_14 * V_14 ;
F_146 ( & V_7 -> V_168 ) ;
V_14 = F_147 ( V_53 , V_7 ) ;
if ( F_89 ( V_53 ) ) {
int V_16 = F_148 ( V_53 ) ;
F_149 ( V_53 ) ;
F_138 ( V_53 ) ;
F_150 ( V_53 , V_14 , V_16 ) ;
V_45 = 0 ;
}
F_151 ( & V_7 -> V_168 ) ;
}
return V_45 ;
}
static int F_152 ( struct V_7 * V_7 , int V_169 ,
struct V_1 * V_2 )
{
unsigned long V_170 , V_171 ;
if ( F_113 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_169 ) {
V_170 = F_7 ( V_7 , V_10 ) ;
V_171 = F_7 ( V_7 , V_152 ) ;
} else {
V_170 = F_7 ( V_7 , V_12 ) ;
V_171 = F_7 ( V_7 , V_172 ) ;
}
if ( ( V_2 -> V_49 & V_173 ) == V_173 )
V_170 >>= 3 ;
return V_171 > V_170 ;
}
static T_6 void
F_153 ( struct V_14 * V_14 , struct V_104 * V_105 )
{
struct V_174 * V_175 = & V_14 -> V_175 ;
struct V_7 * V_7 = F_13 ( V_14 ) ;
F_105 ( V_176 ) ;
while ( ! F_106 ( V_105 ) ) {
struct V_53 * V_53 = F_107 ( V_105 ) ;
int V_16 ;
F_88 ( F_89 ( V_53 ) , V_53 ) ;
F_20 ( & V_53 -> V_16 ) ;
if ( F_70 ( ! F_91 ( V_53 ) ) ) {
F_151 ( & V_7 -> V_168 ) ;
F_86 ( V_53 ) ;
F_146 ( & V_7 -> V_168 ) ;
continue;
}
V_14 = F_147 ( V_53 , V_7 ) ;
F_154 ( V_53 ) ;
V_16 = F_148 ( V_53 ) ;
F_155 ( V_53 , V_14 , V_16 ) ;
if ( F_156 ( V_16 ) ) {
int V_169 = F_145 ( V_16 ) ;
int V_177 = F_141 ( V_53 ) ;
V_175 -> V_178 [ V_169 ] += V_177 ;
}
if ( F_120 ( V_53 ) ) {
F_157 ( V_53 ) ;
F_158 ( V_53 ) ;
F_150 ( V_53 , V_14 , V_16 ) ;
if ( F_70 ( F_159 ( V_53 ) ) ) {
F_151 ( & V_7 -> V_168 ) ;
F_160 ( V_53 ) ;
( * F_161 ( V_53 ) ) ( V_53 ) ;
F_146 ( & V_7 -> V_168 ) ;
} else
F_122 ( & V_53 -> V_16 , & V_176 ) ;
}
}
F_128 ( & V_176 , V_105 ) ;
}
static int F_162 ( void )
{
return ! ( V_55 -> V_22 & V_179 ) ||
V_55 -> V_57 == NULL ||
F_163 ( V_55 -> V_57 ) ;
}
static T_6 unsigned long
F_164 ( unsigned long V_46 , struct V_14 * V_14 ,
struct V_1 * V_2 , enum V_15 V_16 )
{
F_105 ( V_105 ) ;
unsigned long V_31 ;
unsigned long V_119 = 0 ;
unsigned long V_164 ;
unsigned long V_117 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_116 = 0 ;
unsigned long V_120 = 0 ;
unsigned long V_121 = 0 ;
T_5 V_180 = 0 ;
int V_169 = F_145 ( V_16 ) ;
struct V_7 * V_7 = F_13 ( V_14 ) ;
struct V_174 * V_175 = & V_14 -> V_175 ;
while ( F_70 ( F_152 ( V_7 , V_169 , V_2 ) ) ) {
F_165 ( V_181 , V_182 / 10 ) ;
if ( F_166 ( V_55 ) )
return V_50 ;
}
F_167 () ;
if ( ! V_2 -> V_126 )
V_180 |= V_160 ;
if ( ! V_2 -> V_138 )
V_180 |= V_157 ;
F_146 ( & V_7 -> V_168 ) ;
V_164 = F_139 ( V_46 , V_14 , & V_105 ,
& V_31 , V_2 , V_180 , V_16 ) ;
F_168 ( V_7 , V_17 + V_16 , - V_164 ) ;
F_168 ( V_7 , V_172 + V_169 , V_164 ) ;
if ( F_1 ( V_2 ) ) {
F_168 ( V_7 , V_13 , V_31 ) ;
if ( F_113 () )
F_169 ( V_183 , V_7 , V_31 ) ;
else
F_169 ( V_184 , V_7 , V_31 ) ;
}
F_151 ( & V_7 -> V_168 ) ;
if ( V_164 == 0 )
return 0 ;
V_119 = F_104 ( & V_105 , V_7 , V_2 , V_150 ,
& V_117 , & V_116 , & V_118 ,
& V_120 , & V_121 ,
false ) ;
F_146 ( & V_7 -> V_168 ) ;
V_175 -> V_185 [ V_169 ] += V_164 ;
if ( F_1 ( V_2 ) ) {
if ( F_113 () )
F_169 ( V_186 , V_7 ,
V_119 ) ;
else
F_169 ( V_187 , V_7 ,
V_119 ) ;
}
F_153 ( V_14 , & V_105 ) ;
F_168 ( V_7 , V_172 + V_169 , - V_164 ) ;
F_151 ( & V_7 -> V_168 ) ;
F_126 ( & V_105 ) ;
F_127 ( & V_105 , true ) ;
if ( V_120 && V_120 == V_164 )
F_170 ( V_130 , & V_7 -> V_22 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_117 && V_117 == V_118 )
F_170 ( V_188 , & V_7 -> V_22 ) ;
if ( V_116 == V_164 )
F_170 ( V_136 , & V_7 -> V_22 ) ;
if ( V_121 && F_162 () )
F_165 ( V_181 , V_182 / 10 ) ;
}
if ( ! V_2 -> V_189 && ! F_113 () &&
F_162 () )
F_171 ( V_7 , V_181 , V_182 / 10 ) ;
F_172 ( V_7 -> V_190 -> V_191 ,
F_173 ( V_7 ) ,
V_31 , V_119 ,
V_2 -> V_141 ,
F_174 ( V_169 ) ) ;
return V_119 ;
}
static void F_175 ( struct V_14 * V_14 ,
struct V_104 * V_27 ,
struct V_104 * V_176 ,
enum V_15 V_16 )
{
struct V_7 * V_7 = F_13 ( V_14 ) ;
unsigned long V_192 = 0 ;
struct V_53 * V_53 ;
int V_166 ;
while ( ! F_106 ( V_27 ) ) {
V_53 = F_107 ( V_27 ) ;
V_14 = F_147 ( V_53 , V_7 ) ;
F_88 ( F_89 ( V_53 ) , V_53 ) ;
F_154 ( V_53 ) ;
V_166 = F_141 ( V_53 ) ;
F_142 ( V_14 , V_16 , V_166 ) ;
F_133 ( & V_53 -> V_16 , & V_14 -> V_163 [ V_16 ] ) ;
V_192 += V_166 ;
if ( F_120 ( V_53 ) ) {
F_157 ( V_53 ) ;
F_158 ( V_53 ) ;
F_150 ( V_53 , V_14 , V_16 ) ;
if ( F_70 ( F_159 ( V_53 ) ) ) {
F_151 ( & V_7 -> V_168 ) ;
F_160 ( V_53 ) ;
( * F_161 ( V_53 ) ) ( V_53 ) ;
F_146 ( & V_7 -> V_168 ) ;
} else
F_122 ( & V_53 -> V_16 , V_176 ) ;
}
}
F_168 ( V_7 , V_17 + V_16 , V_192 ) ;
if ( ! F_156 ( V_16 ) )
F_176 ( V_193 , V_192 ) ;
}
static void F_177 ( unsigned long V_46 ,
struct V_14 * V_14 ,
struct V_1 * V_2 ,
enum V_15 V_16 )
{
unsigned long V_164 ;
unsigned long V_31 ;
unsigned long V_94 ;
F_105 ( V_194 ) ;
F_105 ( V_195 ) ;
F_105 ( V_196 ) ;
struct V_53 * V_53 ;
struct V_174 * V_175 = & V_14 -> V_175 ;
unsigned long V_197 = 0 ;
T_5 V_180 = 0 ;
int V_169 = F_145 ( V_16 ) ;
struct V_7 * V_7 = F_13 ( V_14 ) ;
F_167 () ;
if ( ! V_2 -> V_126 )
V_180 |= V_160 ;
if ( ! V_2 -> V_138 )
V_180 |= V_157 ;
F_146 ( & V_7 -> V_168 ) ;
V_164 = F_139 ( V_46 , V_14 , & V_194 ,
& V_31 , V_2 , V_180 , V_16 ) ;
if ( F_1 ( V_2 ) )
F_168 ( V_7 , V_13 , V_31 ) ;
V_175 -> V_185 [ V_169 ] += V_164 ;
F_169 ( V_198 , V_7 , V_31 ) ;
F_168 ( V_7 , V_17 + V_16 , - V_164 ) ;
F_168 ( V_7 , V_172 + V_169 , V_164 ) ;
F_151 ( & V_7 -> V_168 ) ;
while ( ! F_106 ( & V_194 ) ) {
F_29 () ;
V_53 = F_107 ( & V_194 ) ;
F_20 ( & V_53 -> V_16 ) ;
if ( F_70 ( ! F_91 ( V_53 ) ) ) {
F_86 ( V_53 ) ;
continue;
}
if ( F_70 ( V_199 ) ) {
if ( F_44 ( V_53 ) && F_108 ( V_53 ) ) {
if ( F_44 ( V_53 ) )
F_119 ( V_53 , 0 ) ;
F_52 ( V_53 ) ;
}
}
if ( F_99 ( V_53 , 0 , V_2 -> V_3 ,
& V_94 ) ) {
V_197 += F_141 ( V_53 ) ;
if ( ( V_94 & V_98 ) && F_81 ( V_53 ) ) {
F_122 ( & V_53 -> V_16 , & V_195 ) ;
continue;
}
}
F_132 ( V_53 ) ;
F_122 ( & V_53 -> V_16 , & V_196 ) ;
}
F_146 ( & V_7 -> V_168 ) ;
V_175 -> V_178 [ V_169 ] += V_197 ;
F_175 ( V_14 , & V_195 , & V_194 , V_16 ) ;
F_175 ( V_14 , & V_196 , & V_194 , V_16 - V_200 ) ;
F_168 ( V_7 , V_172 + V_169 , - V_164 ) ;
F_151 ( & V_7 -> V_168 ) ;
F_126 ( & V_194 ) ;
F_127 ( & V_194 , true ) ;
}
static int F_178 ( struct V_7 * V_7 )
{
unsigned long V_201 , V_170 ;
V_201 = F_7 ( V_7 , V_11 ) ;
V_170 = F_7 ( V_7 , V_12 ) ;
if ( V_170 * V_7 -> V_202 < V_201 )
return 1 ;
return 0 ;
}
static int F_179 ( struct V_14 * V_14 )
{
if ( ! V_203 )
return 0 ;
if ( ! F_11 () )
return F_180 ( V_14 ) ;
return F_178 ( F_13 ( V_14 ) ) ;
}
static inline int F_179 ( struct V_14 * V_14 )
{
return 0 ;
}
static int F_181 ( struct V_14 * V_14 )
{
unsigned long V_170 ;
unsigned long V_201 ;
V_170 = F_10 ( V_14 , V_204 ) ;
V_201 = F_10 ( V_14 , V_205 ) ;
return V_201 > V_170 ;
}
static int F_182 ( struct V_14 * V_14 , enum V_15 V_16 )
{
if ( F_145 ( V_16 ) )
return F_181 ( V_14 ) ;
else
return F_179 ( V_14 ) ;
}
static unsigned long F_183 ( enum V_15 V_16 , unsigned long V_46 ,
struct V_14 * V_14 , struct V_1 * V_2 )
{
if ( F_156 ( V_16 ) ) {
if ( F_182 ( V_14 , V_16 ) )
F_177 ( V_46 , V_14 , V_2 , V_16 ) ;
return 0 ;
}
return F_164 ( V_46 , V_14 , V_2 , V_16 ) ;
}
static void F_184 ( struct V_14 * V_14 , int V_206 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_207 )
{
struct V_174 * V_175 = & V_14 -> V_175 ;
T_7 V_208 [ 2 ] ;
T_7 V_209 = 0 ;
struct V_7 * V_7 = F_13 ( V_14 ) ;
unsigned long V_210 , V_211 ;
enum V_212 V_212 ;
unsigned long V_213 , V_169 ;
bool V_214 = false ;
unsigned long V_215 , V_216 ;
enum V_15 V_16 ;
bool V_217 ;
int V_218 ;
if ( F_113 () ) {
if ( ! F_9 ( V_7 ) )
V_214 = true ;
if ( ! F_185 ( V_14 ) )
V_214 = true ;
}
if ( ! F_1 ( V_2 ) )
V_214 = true ;
if ( ! V_2 -> V_219 || ( F_8 () <= 0 ) ) {
V_212 = V_220 ;
goto V_51;
}
if ( ! F_1 ( V_2 ) && ! V_206 ) {
V_212 = V_220 ;
goto V_51;
}
if ( ! V_2 -> V_141 && V_206 ) {
V_212 = V_221 ;
goto V_51;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_222 ;
unsigned long V_223 ;
V_223 = F_7 ( V_7 , V_224 ) ;
V_222 = F_7 ( V_7 , V_9 ) +
F_7 ( V_7 , V_10 ) ;
if ( F_70 ( V_222 + V_223 <= F_186 ( V_7 ) ) ) {
V_212 = V_225 ;
goto V_51;
}
}
if ( ! F_181 ( V_14 ) ) {
V_212 = V_220 ;
goto V_51;
}
V_212 = V_226 ;
V_210 = V_206 ;
V_211 = 200 - V_210 ;
V_213 = F_10 ( V_14 , V_227 ) +
F_10 ( V_14 , V_228 ) ;
V_169 = F_10 ( V_14 , V_205 ) +
F_10 ( V_14 , V_204 ) ;
F_146 ( & V_7 -> V_168 ) ;
if ( F_70 ( V_175 -> V_185 [ 0 ] > V_213 / 4 ) ) {
V_175 -> V_185 [ 0 ] /= 2 ;
V_175 -> V_178 [ 0 ] /= 2 ;
}
if ( F_70 ( V_175 -> V_185 [ 1 ] > V_169 / 4 ) ) {
V_175 -> V_185 [ 1 ] /= 2 ;
V_175 -> V_178 [ 1 ] /= 2 ;
}
V_215 = V_210 * ( V_175 -> V_185 [ 0 ] + 1 ) ;
V_215 /= V_175 -> V_178 [ 0 ] + 1 ;
V_216 = V_211 * ( V_175 -> V_185 [ 1 ] + 1 ) ;
V_216 /= V_175 -> V_178 [ 1 ] + 1 ;
F_151 ( & V_7 -> V_168 ) ;
V_208 [ 0 ] = V_215 ;
V_208 [ 1 ] = V_216 ;
V_209 = V_215 + V_216 + 1 ;
V_51:
V_217 = false ;
for ( V_218 = 0 ; ! V_217 && V_218 < 2 ; V_218 ++ ) {
* V_207 = 0 ;
F_187 (lru) {
int V_169 = F_145 ( V_16 ) ;
unsigned long V_19 ;
unsigned long V_165 ;
V_19 = F_10 ( V_14 , V_16 ) ;
V_165 = V_19 >> V_2 -> V_141 ;
if ( ! V_165 && V_218 && V_214 )
V_165 = F_26 ( V_19 , V_50 ) ;
switch ( V_212 ) {
case V_221 :
break;
case V_226 :
V_165 = F_188 ( V_165 * V_208 [ V_169 ] ,
V_209 ) ;
break;
case V_220 :
case V_225 :
if ( ( V_212 == V_220 ) != V_169 ) {
V_19 = 0 ;
V_165 = 0 ;
}
break;
default:
F_143 () ;
}
* V_207 += V_19 ;
V_8 [ V_16 ] = V_165 ;
V_217 |= ! ! V_165 ;
}
}
}
static void F_189 ( struct V_14 * V_14 , int V_206 ,
struct V_1 * V_2 , unsigned long * V_207 )
{
unsigned long V_8 [ V_229 ] ;
unsigned long V_230 [ V_229 ] ;
unsigned long V_46 ;
enum V_15 V_16 ;
unsigned long V_119 = 0 ;
unsigned long V_231 = V_2 -> V_231 ;
struct V_232 V_233 ;
bool V_234 ;
F_184 ( V_14 , V_206 , V_2 , V_8 , V_207 ) ;
memcpy ( V_230 , V_8 , sizeof( V_8 ) ) ;
V_234 = ( F_1 ( V_2 ) && ! F_113 () &&
V_2 -> V_141 == V_142 ) ;
F_190 ( & V_233 ) ;
while ( V_8 [ V_228 ] || V_8 [ V_205 ] ||
V_8 [ V_204 ] ) {
unsigned long V_235 , V_236 , V_237 ;
unsigned long V_31 ;
F_187 (lru) {
if ( V_8 [ V_16 ] ) {
V_46 = F_26 ( V_8 [ V_16 ] , V_50 ) ;
V_8 [ V_16 ] -= V_46 ;
V_119 += F_183 ( V_16 , V_46 ,
V_14 , V_2 ) ;
}
}
if ( V_119 < V_231 || V_234 )
continue;
V_236 = V_8 [ V_204 ] + V_8 [ V_205 ] ;
V_235 = V_8 [ V_228 ] + V_8 [ V_227 ] ;
if ( ! V_236 || ! V_235 )
break;
if ( V_236 > V_235 ) {
unsigned long V_238 = V_230 [ V_228 ] +
V_230 [ V_227 ] + 1 ;
V_16 = V_239 ;
V_237 = V_235 * 100 / V_238 ;
} else {
unsigned long V_238 = V_230 [ V_204 ] +
V_230 [ V_205 ] + 1 ;
V_16 = V_240 ;
V_237 = V_236 * 100 / V_238 ;
}
V_8 [ V_16 ] = 0 ;
V_8 [ V_16 + V_200 ] = 0 ;
V_16 = ( V_16 == V_240 ) ? V_239 : V_240 ;
V_31 = V_230 [ V_16 ] - V_8 [ V_16 ] ;
V_8 [ V_16 ] = V_230 [ V_16 ] * ( 100 - V_237 ) / 100 ;
V_8 [ V_16 ] -= F_26 ( V_8 [ V_16 ] , V_31 ) ;
V_16 += V_200 ;
V_31 = V_230 [ V_16 ] - V_8 [ V_16 ] ;
V_8 [ V_16 ] = V_230 [ V_16 ] * ( 100 - V_237 ) / 100 ;
V_8 [ V_16 ] -= F_26 ( V_8 [ V_16 ] , V_31 ) ;
V_234 = true ;
}
F_191 ( & V_233 ) ;
V_2 -> V_119 += V_119 ;
if ( F_179 ( V_14 ) )
F_177 ( V_50 , V_14 ,
V_2 , V_227 ) ;
F_192 ( V_2 -> V_49 ) ;
}
static bool F_193 ( struct V_1 * V_2 )
{
if ( F_194 ( V_241 ) && V_2 -> V_167 &&
( V_2 -> V_167 > V_242 ||
V_2 -> V_141 < V_142 - 2 ) )
return true ;
return false ;
}
static inline bool F_195 ( struct V_7 * V_7 ,
unsigned long V_119 ,
unsigned long V_31 ,
struct V_1 * V_2 )
{
unsigned long V_243 ;
unsigned long V_244 ;
if ( ! F_193 ( V_2 ) )
return false ;
if ( V_2 -> V_49 & V_245 ) {
if ( ! V_119 && ! V_31 )
return false ;
} else {
if ( ! V_119 )
return false ;
}
V_243 = ( 2UL << V_2 -> V_167 ) ;
V_244 = F_7 ( V_7 , V_10 ) ;
if ( F_8 () > 0 )
V_244 += F_7 ( V_7 , V_12 ) ;
if ( V_2 -> V_119 < V_243 &&
V_244 > V_243 )
return true ;
switch ( F_196 ( V_7 , V_2 -> V_167 , 0 , 0 ) ) {
case V_246 :
case V_247 :
return false ;
default:
return true ;
}
}
static bool F_197 ( struct V_7 * V_7 , struct V_1 * V_2 ,
bool V_248 )
{
struct V_249 * V_249 = V_55 -> V_249 ;
unsigned long V_119 , V_31 ;
bool V_250 = false ;
do {
struct V_4 * V_251 = V_2 -> V_3 ;
struct V_252 V_253 = {
. V_7 = V_7 ,
. V_141 = V_2 -> V_141 ,
} ;
unsigned long V_254 = 0 ;
struct V_4 * V_5 ;
V_119 = V_2 -> V_119 ;
V_31 = V_2 -> V_31 ;
V_5 = F_39 ( V_251 , NULL , & V_253 ) ;
do {
unsigned long V_207 ;
unsigned long V_255 ;
struct V_14 * V_14 ;
int V_206 ;
if ( F_198 ( V_251 , V_5 ) ) {
if ( ! V_2 -> V_256 )
continue;
F_199 ( V_5 , V_257 , 1 ) ;
}
V_14 = F_200 ( V_7 , V_5 ) ;
V_206 = F_201 ( V_5 ) ;
V_255 = V_2 -> V_31 ;
F_189 ( V_14 , V_206 , V_2 , & V_207 ) ;
V_254 += V_207 ;
if ( V_5 && V_248 )
F_33 ( V_2 -> V_49 , F_202 ( V_7 ) ,
V_5 , V_2 -> V_31 - V_255 ,
V_207 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_119 >= V_2 -> V_231 ) {
F_203 ( V_251 , V_5 ) ;
break;
}
} while ( ( V_5 = F_39 ( V_251 , V_5 , & V_253 ) ) );
if ( F_1 ( V_2 ) && V_248 )
F_33 ( V_2 -> V_49 , F_202 ( V_7 ) , NULL ,
V_2 -> V_31 - V_31 ,
V_254 ) ;
if ( V_249 ) {
V_2 -> V_119 += V_249 -> V_258 ;
V_249 -> V_258 = 0 ;
}
F_204 ( V_2 -> V_49 , V_2 -> V_3 ,
V_2 -> V_31 - V_31 ,
V_2 -> V_119 - V_119 ) ;
if ( V_2 -> V_119 - V_119 )
V_250 = true ;
} while ( F_195 ( V_7 , V_2 -> V_119 - V_119 ,
V_2 -> V_31 - V_31 , V_2 ) );
return V_250 ;
}
static inline bool F_205 ( struct V_7 * V_7 , int V_167 )
{
unsigned long V_259 , V_260 ;
bool V_261 ;
V_259 = F_26 ( F_206 ( V_7 ) , F_207 (
V_7 -> V_262 , V_263 ) ) ;
V_260 = F_186 ( V_7 ) + V_259 + ( 2UL << V_167 ) ;
V_261 = F_208 ( V_7 , 0 , V_260 , 0 , 0 ) ;
if ( F_209 ( V_7 , V_167 ) )
return V_261 ;
if ( F_196 ( V_7 , V_167 , 0 , 0 ) == V_264 )
return false ;
return V_261 ;
}
static bool F_210 ( struct V_265 * V_265 , struct V_1 * V_2 )
{
struct V_266 * V_267 ;
struct V_7 * V_7 ;
unsigned long V_268 ;
unsigned long V_269 ;
T_2 V_270 ;
enum V_271 V_272 = F_211 ( V_2 -> V_49 ) ;
bool V_250 = false ;
V_270 = V_2 -> V_49 ;
if ( V_199 )
V_2 -> V_49 |= V_273 ;
F_212 (zone, z, zonelist,
requested_highidx, sc->nodemask) {
enum V_271 V_274 ;
if ( ! F_213 ( V_7 ) )
continue;
V_274 = V_272 ;
while ( ! F_213 ( V_7 -> V_190 -> V_275 +
V_274 ) )
V_274 -- ;
if ( F_1 ( V_2 ) ) {
if ( ! F_214 ( V_7 ,
V_24 | V_276 ) )
continue;
if ( V_2 -> V_141 != V_142 &&
! F_9 ( V_7 ) )
continue;
if ( F_194 ( V_241 ) &&
V_2 -> V_167 > V_242 &&
F_215 ( V_267 ) <= V_272 &&
F_205 ( V_7 , V_2 -> V_167 ) ) {
V_2 -> F_205 = true ;
continue;
}
V_269 = 0 ;
V_268 = F_216 ( V_7 ,
V_2 -> V_167 , V_2 -> V_49 ,
& V_269 ) ;
V_2 -> V_119 += V_268 ;
V_2 -> V_31 += V_269 ;
if ( V_268 )
V_250 = true ;
}
if ( F_197 ( V_7 , V_2 , F_173 ( V_7 ) == V_274 ) )
V_250 = true ;
if ( F_1 ( V_2 ) &&
! V_250 && F_9 ( V_7 ) )
V_250 = true ;
}
V_2 -> V_49 = V_270 ;
return V_250 ;
}
static unsigned long F_217 ( struct V_265 * V_265 ,
struct V_1 * V_2 )
{
int V_277 = V_2 -> V_141 ;
unsigned long V_278 = 0 ;
unsigned long V_279 ;
bool V_280 ;
V_281:
F_218 () ;
if ( F_1 ( V_2 ) )
F_97 ( V_282 ) ;
do {
F_219 ( V_2 -> V_49 , V_2 -> V_3 ,
V_2 -> V_141 ) ;
V_2 -> V_31 = 0 ;
V_280 = F_210 ( V_265 , V_2 ) ;
V_278 += V_2 -> V_31 ;
if ( V_2 -> V_119 >= V_2 -> V_231 )
break;
if ( V_2 -> F_205 )
break;
if ( V_2 -> V_141 < V_142 - 2 )
V_2 -> V_138 = 1 ;
V_279 = V_2 -> V_231 + V_2 -> V_231 / 2 ;
if ( V_278 > V_279 ) {
F_220 ( V_283 ? 0 : V_278 ,
V_284 ) ;
V_2 -> V_138 = 1 ;
}
} while ( -- V_2 -> V_141 >= 0 );
F_221 () ;
if ( V_2 -> V_119 )
return V_2 -> V_119 ;
if ( V_2 -> F_205 )
return 1 ;
if ( ! V_2 -> V_256 ) {
V_2 -> V_141 = V_277 ;
V_2 -> V_256 = 1 ;
goto V_281;
}
if ( V_280 )
return 1 ;
return 0 ;
}
static bool F_222 ( T_8 * V_285 )
{
struct V_7 * V_7 ;
unsigned long V_286 = 0 ;
unsigned long V_114 = 0 ;
int V_287 ;
bool V_288 ;
for ( V_287 = 0 ; V_287 <= V_289 ; V_287 ++ ) {
V_7 = & V_285 -> V_275 [ V_287 ] ;
if ( ! F_213 ( V_7 ) ||
F_6 ( V_7 ) == 0 )
continue;
V_286 += F_223 ( V_7 ) ;
V_114 += F_7 ( V_7 , V_224 ) ;
}
if ( ! V_286 )
return true ;
V_288 = V_114 > V_286 / 2 ;
if ( ! V_288 && F_224 ( & V_285 -> V_290 ) ) {
V_285 -> V_274 = F_26 ( V_285 -> V_274 ,
(enum V_271 ) V_289 ) ;
F_225 ( & V_285 -> V_290 ) ;
}
return V_288 ;
}
static bool F_226 ( T_2 V_49 , struct V_265 * V_265 ,
T_9 * V_291 )
{
struct V_266 * V_267 ;
struct V_7 * V_7 ;
T_8 * V_285 = NULL ;
if ( V_55 -> V_22 & V_292 )
goto V_51;
if ( F_166 ( V_55 ) )
goto V_51;
F_212 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_173 ( V_7 ) > V_289 )
continue;
V_285 = V_7 -> V_190 ;
if ( F_222 ( V_285 ) )
goto V_51;
break;
}
if ( ! V_285 )
goto V_51;
F_97 ( V_293 ) ;
if ( ! ( V_49 & V_128 ) ) {
F_227 ( V_285 -> V_294 ,
F_222 ( V_285 ) , V_182 ) ;
goto V_295;
}
F_228 ( V_7 -> V_190 -> V_294 ,
F_222 ( V_285 ) ) ;
V_295:
if ( F_166 ( V_55 ) )
return true ;
V_51:
return false ;
}
unsigned long F_229 ( struct V_265 * V_265 , int V_167 ,
T_2 V_49 , T_9 * V_291 )
{
unsigned long V_119 ;
struct V_1 V_2 = {
. V_231 = V_50 ,
. V_49 = ( V_49 = F_230 ( V_49 ) ) ,
. V_167 = V_167 ,
. V_291 = V_291 ,
. V_141 = V_142 ,
. V_138 = ! V_283 ,
. V_126 = 1 ,
. V_219 = 1 ,
} ;
if ( F_226 ( V_49 , V_265 , V_291 ) )
return 1 ;
F_231 ( V_167 ,
V_2 . V_138 ,
V_49 ) ;
V_119 = F_217 ( V_265 , & V_2 ) ;
F_232 ( V_119 ) ;
return V_119 ;
}
unsigned long F_233 ( struct V_4 * V_5 ,
T_2 V_49 , bool V_296 ,
struct V_7 * V_7 ,
unsigned long * V_31 )
{
struct V_1 V_2 = {
. V_231 = V_50 ,
. V_3 = V_5 ,
. V_138 = ! V_283 ,
. V_126 = 1 ,
. V_219 = ! V_296 ,
} ;
struct V_14 * V_14 = F_200 ( V_7 , V_5 ) ;
int V_206 = F_201 ( V_5 ) ;
unsigned long V_207 ;
V_2 . V_49 = ( V_49 & V_297 ) |
( V_298 & ~ V_297 ) ;
F_234 ( V_2 . V_167 ,
V_2 . V_138 ,
V_2 . V_49 ) ;
F_189 ( V_14 , V_206 , & V_2 , & V_207 ) ;
F_235 ( V_2 . V_119 ) ;
* V_31 = V_2 . V_31 ;
return V_2 . V_119 ;
}
unsigned long F_236 ( struct V_4 * V_5 ,
unsigned long V_166 ,
T_2 V_49 ,
bool V_219 )
{
struct V_265 * V_265 ;
unsigned long V_119 ;
int V_38 ;
struct V_1 V_2 = {
. V_231 = F_237 ( V_166 , V_50 ) ,
. V_49 = ( V_49 & V_297 ) |
( V_298 & ~ V_297 ) ,
. V_3 = V_5 ,
. V_141 = V_142 ,
. V_138 = ! V_283 ,
. V_126 = 1 ,
. V_219 = V_219 ,
} ;
V_38 = F_238 ( V_5 ) ;
V_265 = F_239 ( V_38 ) -> V_299 ;
F_240 ( 0 ,
V_2 . V_138 ,
V_2 . V_49 ) ;
V_119 = F_217 ( V_265 , & V_2 ) ;
F_241 ( V_119 ) ;
return V_119 ;
}
static void F_242 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_203 )
return;
V_5 = F_39 ( NULL , NULL , NULL ) ;
do {
struct V_14 * V_14 = F_200 ( V_7 , V_5 ) ;
if ( F_179 ( V_14 ) )
F_177 ( V_50 , V_14 ,
V_2 , V_227 ) ;
V_5 = F_39 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_243 ( struct V_7 * V_7 , int V_167 ,
unsigned long V_259 , int V_274 )
{
if ( ! F_208 ( V_7 , V_167 , F_186 ( V_7 ) +
V_259 , V_274 , 0 ) )
return false ;
if ( F_194 ( V_241 ) && V_167 && F_196 ( V_7 ,
V_167 , 0 , V_274 ) == V_264 )
return false ;
return true ;
}
static bool F_244 ( T_8 * V_285 , int V_167 , int V_274 )
{
unsigned long V_262 = 0 ;
unsigned long V_300 = 0 ;
int V_287 ;
for ( V_287 = 0 ; V_287 <= V_274 ; V_287 ++ ) {
struct V_7 * V_7 = V_285 -> V_275 + V_287 ;
if ( ! F_213 ( V_7 ) )
continue;
V_262 += V_7 -> V_262 ;
if ( ! F_9 ( V_7 ) ) {
V_300 += V_7 -> V_262 ;
continue;
}
if ( F_243 ( V_7 , V_167 , 0 , V_287 ) )
V_300 += V_7 -> V_262 ;
else if ( ! V_167 )
return false ;
}
if ( V_167 )
return V_300 >= ( V_262 >> 2 ) ;
else
return true ;
}
static bool F_245 ( T_8 * V_285 , int V_167 , long V_301 ,
int V_274 )
{
if ( V_301 )
return false ;
if ( F_224 ( & V_285 -> V_294 ) )
F_246 ( & V_285 -> V_294 ) ;
return F_244 ( V_285 , V_167 , V_274 ) ;
}
static bool F_247 ( struct V_7 * V_7 ,
int V_274 ,
struct V_1 * V_2 ,
unsigned long * V_302 )
{
int V_303 = V_2 -> V_167 ;
unsigned long V_259 ;
bool V_304 ;
V_2 -> V_231 = F_237 ( V_50 , F_186 ( V_7 ) ) ;
if ( F_194 ( V_241 ) && V_2 -> V_167 &&
F_196 ( V_7 , V_2 -> V_167 , 0 , V_274 )
!= V_264 )
V_303 = 0 ;
V_259 = F_26 ( F_206 ( V_7 ) , F_207 (
V_7 -> V_262 , V_263 ) ) ;
V_304 = ( V_199 && F_248 ( V_7 ) ) ;
if ( ! V_304 && F_243 ( V_7 , V_303 ,
V_259 , V_274 ) )
return true ;
F_197 ( V_7 , V_2 , F_173 ( V_7 ) == V_274 ) ;
* V_302 += V_2 -> V_231 ;
F_249 ( V_130 , & V_7 -> V_22 ) ;
if ( F_9 ( V_7 ) &&
F_243 ( V_7 , V_303 , 0 , V_274 ) ) {
F_249 ( V_188 , & V_7 -> V_22 ) ;
F_249 ( V_136 , & V_7 -> V_22 ) ;
}
return V_2 -> V_31 >= V_2 -> V_231 ;
}
static unsigned long F_250 ( T_8 * V_285 , int V_167 ,
int * V_274 )
{
int V_287 ;
int V_305 = 0 ;
unsigned long V_268 ;
unsigned long V_269 ;
struct V_1 V_2 = {
. V_49 = V_24 ,
. V_167 = V_167 ,
. V_141 = V_142 ,
. V_138 = ! V_283 ,
. V_126 = 1 ,
. V_219 = 1 ,
} ;
F_97 ( V_306 ) ;
do {
unsigned long V_302 = 0 ;
bool V_307 = true ;
bool V_308 = ( V_167 > 0 ) ;
V_2 . V_119 = 0 ;
for ( V_287 = V_285 -> V_309 - 1 ; V_287 >= 0 ; V_287 -- ) {
struct V_7 * V_7 = V_285 -> V_275 + V_287 ;
if ( ! F_213 ( V_7 ) )
continue;
if ( V_2 . V_141 != V_142 &&
! F_9 ( V_7 ) )
continue;
F_242 ( V_7 , & V_2 ) ;
if ( V_199 && F_251 ( V_287 ) ) {
V_305 = V_287 ;
break;
}
if ( ! F_243 ( V_7 , V_167 , 0 , 0 ) ) {
V_305 = V_287 ;
break;
} else {
F_249 ( V_188 , & V_7 -> V_22 ) ;
F_249 ( V_136 , & V_7 -> V_22 ) ;
}
}
if ( V_287 < 0 )
goto V_51;
for ( V_287 = 0 ; V_287 <= V_305 ; V_287 ++ ) {
struct V_7 * V_7 = V_285 -> V_275 + V_287 ;
if ( ! F_213 ( V_7 ) )
continue;
if ( V_308 &&
F_252 ( V_7 , V_167 ,
F_206 ( V_7 ) ,
* V_274 , 0 ) )
V_308 = false ;
}
if ( V_2 . V_141 < V_142 - 2 )
V_2 . V_138 = 1 ;
for ( V_287 = 0 ; V_287 <= V_305 ; V_287 ++ ) {
struct V_7 * V_7 = V_285 -> V_275 + V_287 ;
if ( ! F_213 ( V_7 ) )
continue;
if ( V_2 . V_141 != V_142 &&
! F_9 ( V_7 ) )
continue;
V_2 . V_31 = 0 ;
V_269 = 0 ;
V_268 = F_216 ( V_7 ,
V_167 , V_2 . V_49 ,
& V_269 ) ;
V_2 . V_119 += V_268 ;
if ( F_247 ( V_7 , V_305 ,
& V_2 , & V_302 ) )
V_307 = false ;
}
if ( F_224 ( & V_285 -> V_294 ) &&
F_222 ( V_285 ) )
F_246 ( & V_285 -> V_294 ) ;
if ( V_167 && V_2 . V_119 >= 2UL << V_167 )
V_167 = V_2 . V_167 = 0 ;
if ( F_253 () || F_254 () )
break;
if ( V_308 && V_2 . V_119 > V_302 )
F_255 ( V_285 , V_167 ) ;
if ( V_307 || ! V_2 . V_119 )
V_2 . V_141 -- ;
} while ( V_2 . V_141 >= 1 &&
! F_244 ( V_285 , V_167 , * V_274 ) );
V_51:
* V_274 = V_305 ;
return V_167 ;
}
static void F_256 ( T_8 * V_285 , int V_167 , int V_274 )
{
long V_301 = 0 ;
F_257 ( V_310 ) ;
if ( F_258 ( V_55 ) || F_254 () )
return;
F_259 ( & V_285 -> V_290 , & V_310 , V_311 ) ;
if ( F_245 ( V_285 , V_167 , V_301 , V_274 ) ) {
V_301 = F_260 ( V_182 / 10 ) ;
F_261 ( & V_285 -> V_290 , & V_310 ) ;
F_259 ( & V_285 -> V_290 , & V_310 , V_311 ) ;
}
if ( F_245 ( V_285 , V_167 , V_301 , V_274 ) ) {
F_262 ( V_285 -> V_191 ) ;
F_263 ( V_285 , V_312 ) ;
F_264 ( V_285 ) ;
if ( ! F_254 () )
F_265 () ;
F_263 ( V_285 , V_313 ) ;
} else {
if ( V_301 )
F_97 ( V_314 ) ;
else
F_97 ( V_315 ) ;
}
F_261 ( & V_285 -> V_290 , & V_310 ) ;
}
static int F_266 ( void * V_316 )
{
unsigned long V_167 , V_317 ;
unsigned V_318 ;
int V_274 , V_319 ;
int V_320 ;
T_8 * V_285 = ( T_8 * ) V_316 ;
struct V_321 * V_322 = V_55 ;
struct V_249 V_249 = {
. V_258 = 0 ,
} ;
const struct V_323 * V_323 = F_267 ( V_285 -> V_191 ) ;
F_268 ( V_24 ) ;
if ( ! F_269 ( V_323 ) )
F_270 ( V_322 , V_323 ) ;
V_55 -> V_249 = & V_249 ;
V_322 -> V_22 |= V_324 | V_56 | V_325 ;
F_271 () ;
V_167 = V_317 = 0 ;
V_318 = 0 ;
V_274 = V_319 = V_285 -> V_309 - 1 ;
V_320 = V_274 ;
for ( ; ; ) {
bool V_45 ;
if ( V_320 >= V_319 &&
V_318 == V_317 ) {
V_317 = V_285 -> V_326 ;
V_319 = V_285 -> V_274 ;
V_285 -> V_326 = 0 ;
V_285 -> V_274 = V_285 -> V_309 - 1 ;
}
if ( V_167 < V_317 || V_274 > V_319 ) {
V_167 = V_317 ;
V_274 = V_319 ;
} else {
F_256 ( V_285 , V_318 ,
V_320 ) ;
V_167 = V_285 -> V_326 ;
V_274 = V_285 -> V_274 ;
V_317 = V_167 ;
V_319 = V_274 ;
V_285 -> V_326 = 0 ;
V_285 -> V_274 = V_285 -> V_309 - 1 ;
}
V_45 = F_253 () ;
if ( F_254 () )
break;
if ( ! V_45 ) {
F_272 ( V_285 -> V_191 , V_167 ) ;
V_320 = V_274 ;
V_318 = F_250 ( V_285 , V_167 ,
& V_320 ) ;
}
}
V_322 -> V_22 &= ~ ( V_324 | V_56 | V_325 ) ;
V_55 -> V_249 = NULL ;
F_273 () ;
return 0 ;
}
void F_274 ( struct V_7 * V_7 , int V_167 , enum V_271 V_274 )
{
T_8 * V_285 ;
if ( ! F_213 ( V_7 ) )
return;
if ( ! F_214 ( V_7 , V_24 | V_276 ) )
return;
V_285 = V_7 -> V_190 ;
if ( V_285 -> V_326 < V_167 ) {
V_285 -> V_326 = V_167 ;
V_285 -> V_274 = F_26 ( V_285 -> V_274 , V_274 ) ;
}
if ( ! F_224 ( & V_285 -> V_290 ) )
return;
if ( F_243 ( V_7 , V_167 , 0 , 0 ) )
return;
F_275 ( V_285 -> V_191 , F_173 ( V_7 ) , V_167 ) ;
F_225 ( & V_285 -> V_290 ) ;
}
unsigned long F_276 ( unsigned long V_231 )
{
struct V_249 V_249 ;
struct V_1 V_2 = {
. V_231 = V_231 ,
. V_49 = V_298 ,
. V_141 = V_142 ,
. V_138 = 1 ,
. V_126 = 1 ,
. V_219 = 1 ,
. V_189 = 1 ,
} ;
struct V_265 * V_265 = F_277 ( F_278 () , V_2 . V_49 ) ;
struct V_321 * V_316 = V_55 ;
unsigned long V_119 ;
V_316 -> V_22 |= V_324 ;
F_268 ( V_2 . V_49 ) ;
V_249 . V_258 = 0 ;
V_316 -> V_249 = & V_249 ;
V_119 = F_217 ( V_265 , & V_2 ) ;
V_316 -> V_249 = NULL ;
F_273 () ;
V_316 -> V_22 &= ~ V_324 ;
return V_119 ;
}
static int F_279 ( struct V_327 * V_328 , unsigned long V_329 ,
void * V_330 )
{
int V_38 ;
if ( V_329 == V_331 || V_329 == V_332 ) {
F_280 (nid, N_MEMORY) {
T_8 * V_285 = F_239 ( V_38 ) ;
const struct V_323 * V_333 ;
V_333 = F_267 ( V_285 -> V_191 ) ;
if ( F_281 ( V_334 , V_333 ) < V_335 )
F_270 ( V_285 -> F_266 , V_333 ) ;
}
}
return V_336 ;
}
int F_282 ( int V_38 )
{
T_8 * V_285 = F_239 ( V_38 ) ;
int V_45 = 0 ;
if ( V_285 -> F_266 )
return 0 ;
V_285 -> F_266 = F_283 ( F_266 , V_285 , L_3 , V_38 ) ;
if ( F_284 ( V_285 -> F_266 ) ) {
F_65 ( V_337 == V_338 ) ;
F_25 ( L_4 , V_38 ) ;
V_45 = F_285 ( V_285 -> F_266 ) ;
V_285 -> F_266 = NULL ;
}
return V_45 ;
}
void F_286 ( int V_38 )
{
struct V_321 * F_266 = F_239 ( V_38 ) -> F_266 ;
if ( F_266 ) {
F_287 ( F_266 ) ;
F_239 ( V_38 ) -> F_266 = NULL ;
}
}
static int T_10 F_288 ( void )
{
int V_38 ;
F_289 () ;
F_280 (nid, N_MEMORY)
F_282 ( V_38 ) ;
F_290 ( F_279 , 0 ) ;
return 0 ;
}
static inline unsigned long F_291 ( struct V_7 * V_7 )
{
unsigned long V_339 = F_7 ( V_7 , V_340 ) ;
unsigned long V_341 = F_7 ( V_7 , V_10 ) +
F_7 ( V_7 , V_9 ) ;
return ( V_341 > V_339 ) ? ( V_341 - V_339 ) : 0 ;
}
static long F_292 ( struct V_7 * V_7 )
{
long V_342 ;
long V_34 = 0 ;
if ( V_343 & V_344 )
V_342 = F_7 ( V_7 , V_345 ) ;
else
V_342 = F_291 ( V_7 ) ;
if ( ! ( V_343 & V_346 ) )
V_34 += F_7 ( V_7 , V_347 ) ;
if ( F_70 ( V_34 > V_342 ) )
V_34 = V_342 ;
return V_342 - V_34 ;
}
static int F_293 ( struct V_7 * V_7 , T_2 V_49 , unsigned int V_167 )
{
const unsigned long V_166 = 1 << V_167 ;
struct V_321 * V_316 = V_55 ;
struct V_249 V_249 ;
struct V_1 V_2 = {
. V_231 = F_237 ( V_166 , V_50 ) ,
. V_49 = ( V_49 = F_230 ( V_49 ) ) ,
. V_167 = V_167 ,
. V_141 = V_348 ,
. V_138 = ! ! ( V_343 & V_346 ) ,
. V_126 = ! ! ( V_343 & V_344 ) ,
. V_219 = 1 ,
} ;
F_29 () ;
V_316 -> V_22 |= V_324 | V_56 ;
F_268 ( V_49 ) ;
V_249 . V_258 = 0 ;
V_316 -> V_249 = & V_249 ;
if ( F_292 ( V_7 ) > V_7 -> V_349 ) {
do {
F_197 ( V_7 , & V_2 , true ) ;
} while ( V_2 . V_119 < V_166 && -- V_2 . V_141 >= 0 );
}
V_316 -> V_249 = NULL ;
V_55 -> V_22 &= ~ ( V_324 | V_56 ) ;
F_273 () ;
return V_2 . V_119 >= V_166 ;
}
int F_294 ( struct V_7 * V_7 , T_2 V_49 , unsigned int V_167 )
{
int V_191 ;
int V_45 ;
if ( F_292 ( V_7 ) <= V_7 -> V_349 &&
F_7 ( V_7 , V_350 ) <= V_7 -> V_351 )
return V_352 ;
if ( ! F_9 ( V_7 ) )
return V_352 ;
if ( ! ( V_49 & V_353 ) || ( V_55 -> V_22 & V_324 ) )
return V_354 ;
V_191 = F_202 ( V_7 ) ;
if ( F_295 ( V_191 , V_355 ) && V_191 != F_278 () )
return V_354 ;
if ( F_296 ( V_356 , & V_7 -> V_22 ) )
return V_354 ;
V_45 = F_293 ( V_7 , V_49 , V_167 ) ;
F_249 ( V_356 , & V_7 -> V_22 ) ;
if ( ! V_45 )
F_97 ( V_357 ) ;
return V_45 ;
}
int F_91 ( struct V_53 * V_53 )
{
return ! F_297 ( F_50 ( V_53 ) ) && ! F_298 ( V_53 ) ;
}
void F_299 ( struct V_53 * * V_358 , int V_166 )
{
struct V_14 * V_14 ;
struct V_7 * V_7 = NULL ;
int V_359 = 0 ;
int V_360 = 0 ;
int V_287 ;
for ( V_287 = 0 ; V_287 < V_166 ; V_287 ++ ) {
struct V_53 * V_53 = V_358 [ V_287 ] ;
struct V_7 * V_361 ;
V_359 ++ ;
V_361 = F_110 ( V_53 ) ;
if ( V_361 != V_7 ) {
if ( V_7 )
F_151 ( & V_7 -> V_168 ) ;
V_7 = V_361 ;
F_146 ( & V_7 -> V_168 ) ;
}
V_14 = F_147 ( V_53 , V_7 ) ;
if ( ! F_89 ( V_53 ) || ! F_87 ( V_53 ) )
continue;
if ( F_91 ( V_53 ) ) {
enum V_15 V_16 = F_300 ( V_53 ) ;
F_88 ( F_109 ( V_53 ) , V_53 ) ;
F_90 ( V_53 ) ;
F_150 ( V_53 , V_14 , V_362 ) ;
F_155 ( V_53 , V_14 , V_16 ) ;
V_360 ++ ;
}
}
if ( V_7 ) {
F_176 ( V_89 , V_360 ) ;
F_176 ( V_363 , V_359 ) ;
F_151 ( & V_7 -> V_168 ) ;
}
}
