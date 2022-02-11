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
F_6 ( V_7 , V_10 ) ;
if ( F_7 () > 0 )
V_8 += F_6 ( V_7 , V_11 ) +
F_6 ( V_7 , V_12 ) ;
return V_8 ;
}
bool F_8 ( struct V_7 * V_7 )
{
return F_6 ( V_7 , V_13 ) <
F_5 ( V_7 ) * 6 ;
}
static unsigned long F_9 ( struct V_14 * V_14 , enum V_15 V_16 )
{
if ( ! F_10 () )
return F_11 ( V_14 , V_16 ) ;
return F_6 ( F_12 ( V_14 ) , V_17 + V_16 ) ;
}
int F_13 ( struct V_18 * V_18 )
{
T_1 V_19 = sizeof( * V_18 -> V_20 ) ;
if ( V_21 == 1 )
V_18 -> V_22 &= ~ V_23 ;
if ( V_18 -> V_22 & V_23 )
V_19 *= V_21 ;
V_18 -> V_20 = F_14 ( V_19 , V_24 ) ;
if ( ! V_18 -> V_20 )
return - V_25 ;
F_15 ( & V_26 ) ;
F_16 ( & V_18 -> V_27 , & V_28 ) ;
F_17 ( & V_26 ) ;
return 0 ;
}
void F_18 ( struct V_18 * V_18 )
{
F_15 ( & V_26 ) ;
F_19 ( & V_18 -> V_27 ) ;
F_17 ( & V_26 ) ;
F_20 ( V_18 -> V_20 ) ;
}
static unsigned long F_21 ( struct V_29 * V_30 ,
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
V_8 = F_22 ( & V_18 -> V_20 [ V_38 ] , 0 ) ;
V_35 = V_8 ;
V_34 = ( 4 * V_31 ) / V_18 -> V_43 ;
V_34 *= V_36 ;
F_23 ( V_34 , V_32 + 1 ) ;
V_35 += V_34 ;
if ( V_35 < 0 ) {
F_24 ( L_1 ,
V_18 -> V_44 , V_35 ) ;
V_35 = V_36 ;
}
if ( V_34 < V_36 / 4 )
V_35 = F_25 ( V_35 , V_36 / 2 ) ;
if ( V_35 > V_36 * 2 )
V_35 = V_36 * 2 ;
F_26 ( V_18 , V_30 , V_8 ,
V_31 , V_32 ,
V_36 , V_34 , V_35 ) ;
while ( V_35 >= V_39 ||
V_35 >= V_36 ) {
unsigned long V_45 ;
unsigned long V_46 = F_25 ( V_39 , V_35 ) ;
V_30 -> V_46 = V_46 ;
V_45 = V_18 -> V_44 ( V_18 , V_30 ) ;
if ( V_45 == V_47 )
break;
V_33 += V_45 ;
F_27 ( V_48 , V_46 ) ;
V_35 -= V_46 ;
F_28 () ;
}
if ( V_35 > 0 )
V_37 = F_29 ( V_35 ,
& V_18 -> V_20 [ V_38 ] ) ;
else
V_37 = F_30 ( & V_18 -> V_20 [ V_38 ] ) ;
F_31 ( V_18 , V_38 , V_33 , V_8 , V_37 , V_35 ) ;
return V_33 ;
}
static unsigned long F_32 ( T_2 V_49 , int V_38 ,
struct V_4 * V_5 ,
unsigned long V_31 ,
unsigned long V_32 )
{
struct V_18 * V_18 ;
unsigned long V_33 = 0 ;
if ( V_5 && ! F_33 ( V_5 ) )
return 0 ;
if ( V_31 == 0 )
V_31 = V_50 ;
if ( ! F_34 ( & V_26 ) ) {
V_33 = 1 ;
goto V_51;
}
F_35 (shrinker, &shrinker_list, list) {
struct V_29 V_2 = {
. V_49 = V_49 ,
. V_38 = V_38 ,
. V_5 = V_5 ,
} ;
if ( V_5 && ! ( V_18 -> V_22 & V_52 ) )
continue;
if ( ! ( V_18 -> V_22 & V_23 ) )
V_2 . V_38 = 0 ;
V_33 += F_21 ( & V_2 , V_18 , V_31 , V_32 ) ;
}
F_36 ( & V_26 ) ;
V_51:
F_28 () ;
return V_33 ;
}
void F_37 ( int V_38 )
{
unsigned long V_33 ;
do {
struct V_4 * V_5 = NULL ;
V_33 = 0 ;
do {
V_33 += F_32 ( V_24 , V_38 , V_5 ,
1000 , 1000 ) ;
} while ( ( V_5 = F_38 ( NULL , V_5 , NULL ) ) != NULL );
} while ( V_33 > 10 );
}
void F_39 ( void )
{
int V_38 ;
F_40 (nid)
F_37 ( V_38 ) ;
}
static inline int F_41 ( struct V_53 * V_53 )
{
return F_42 ( V_53 ) - F_43 ( V_53 ) == 2 ;
}
static int F_44 ( struct V_54 * V_54 , struct V_1 * V_2 )
{
if ( V_55 -> V_22 & V_56 )
return 1 ;
if ( ! F_45 ( V_54 ) )
return 1 ;
if ( F_46 ( V_54 ) == V_55 -> V_57 )
return 1 ;
return 0 ;
}
static void F_47 ( struct V_58 * V_59 ,
struct V_53 * V_53 , int error )
{
F_48 ( V_53 ) ;
if ( F_49 ( V_53 ) == V_59 )
F_50 ( V_59 , error ) ;
F_51 ( V_53 ) ;
}
static T_3 F_52 ( struct V_53 * V_53 , struct V_58 * V_59 ,
struct V_1 * V_2 )
{
if ( ! F_41 ( V_53 ) )
return V_60 ;
if ( ! V_59 ) {
if ( F_43 ( V_53 ) ) {
if ( F_53 ( V_53 ) ) {
F_54 ( V_53 ) ;
F_55 ( L_2 , V_61 ) ;
return V_62 ;
}
}
return V_60 ;
}
if ( V_59 -> V_63 -> V_64 == NULL )
return V_65 ;
if ( ! F_44 ( V_59 -> V_66 , V_2 ) )
return V_60 ;
if ( F_56 ( V_53 ) ) {
int V_67 ;
struct V_68 V_69 = {
. V_70 = V_71 ,
. V_72 = V_50 ,
. V_73 = 0 ,
. V_74 = V_75 ,
. V_76 = 1 ,
} ;
F_57 ( V_53 ) ;
V_67 = V_59 -> V_63 -> V_64 ( V_53 , & V_69 ) ;
if ( V_67 < 0 )
F_47 ( V_59 , V_53 , V_67 ) ;
if ( V_67 == V_77 ) {
F_58 ( V_53 ) ;
return V_65 ;
}
if ( ! F_59 ( V_53 ) ) {
F_58 ( V_53 ) ;
}
F_60 ( V_53 , F_61 ( V_53 ) ) ;
F_62 ( V_53 , V_78 ) ;
return V_79 ;
}
return V_62 ;
}
static int F_63 ( struct V_58 * V_59 , struct V_53 * V_53 ,
bool V_80 )
{
unsigned long V_22 ;
struct V_4 * V_5 ;
F_64 ( ! F_65 ( V_53 ) ) ;
F_64 ( V_59 != F_49 ( V_53 ) ) ;
V_5 = F_66 ( V_53 ) ;
F_67 ( & V_59 -> V_81 , V_22 ) ;
if ( ! F_68 ( V_53 , 2 ) )
goto V_82;
if ( F_69 ( F_70 ( V_53 ) ) ) {
F_71 ( V_53 , 2 ) ;
goto V_82;
}
if ( F_72 ( V_53 ) ) {
T_4 V_83 = { . V_84 = F_73 (page) } ;
F_74 ( V_53 , V_83 ) ;
F_75 ( V_53 ) ;
F_76 ( & V_59 -> V_81 , V_22 ) ;
F_77 ( V_5 ) ;
F_78 ( V_83 ) ;
} else {
void (* F_79)( struct V_53 * );
void * V_85 = NULL ;
F_79 = V_59 -> V_63 -> F_79 ;
if ( V_80 && F_80 ( V_53 ) &&
! F_81 ( V_59 ) )
V_85 = F_82 ( V_59 , V_53 ) ;
F_83 ( V_53 , V_85 , V_5 ) ;
F_76 ( & V_59 -> V_81 , V_22 ) ;
F_77 ( V_5 ) ;
if ( F_79 != NULL )
F_79 ( V_53 ) ;
}
return 1 ;
V_82:
F_76 ( & V_59 -> V_81 , V_22 ) ;
F_77 ( V_5 ) ;
return 0 ;
}
int F_84 ( struct V_58 * V_59 , struct V_53 * V_53 )
{
if ( F_63 ( V_59 , V_53 , false ) ) {
F_71 ( V_53 , 1 ) ;
return 1 ;
}
return 0 ;
}
void F_85 ( struct V_53 * V_53 )
{
bool V_86 ;
int V_87 = F_86 ( V_53 ) ;
F_87 ( F_88 ( V_53 ) , V_53 ) ;
V_88:
F_89 ( V_53 ) ;
if ( F_90 ( V_53 ) ) {
V_86 = false ;
F_91 ( V_53 ) ;
} else {
V_86 = true ;
F_92 ( V_53 ) ;
F_93 () ;
}
if ( V_86 && F_90 ( V_53 ) ) {
if ( ! F_94 ( V_53 ) ) {
F_95 ( V_53 ) ;
goto V_88;
}
}
if ( V_87 && ! V_86 )
F_96 ( V_89 ) ;
else if ( ! V_87 && V_86 )
F_96 ( V_90 ) ;
F_95 ( V_53 ) ;
}
static enum V_91 F_97 ( struct V_53 * V_53 ,
struct V_1 * V_2 )
{
int V_92 , V_93 ;
unsigned long V_94 ;
V_92 = F_98 ( V_53 , 1 , V_2 -> V_3 ,
& V_94 ) ;
V_93 = F_99 ( V_53 ) ;
if ( V_94 & V_95 )
return V_96 ;
if ( V_92 ) {
if ( F_100 ( V_53 ) )
return V_97 ;
F_101 ( V_53 ) ;
if ( V_93 || V_92 > 1 )
return V_97 ;
if ( V_94 & V_98 )
return V_97 ;
return V_99 ;
}
if ( V_93 && ! F_100 ( V_53 ) )
return V_100 ;
return V_96 ;
}
static void F_102 ( struct V_53 * V_53 ,
bool * V_101 , bool * V_102 )
{
struct V_58 * V_59 ;
if ( ! F_80 ( V_53 ) ) {
* V_101 = false ;
* V_102 = false ;
return;
}
* V_101 = F_70 ( V_53 ) ;
* V_102 = F_59 ( V_53 ) ;
if ( ! F_43 ( V_53 ) )
return;
V_59 = F_49 ( V_53 ) ;
if ( V_59 && V_59 -> V_63 -> V_103 )
V_59 -> V_63 -> V_103 ( V_53 , V_101 , V_102 ) ;
}
static unsigned long F_103 ( struct V_104 * V_105 ,
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
F_104 ( V_113 ) ;
F_104 ( V_114 ) ;
int V_115 = 0 ;
unsigned long V_116 = 0 ;
unsigned long V_117 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_119 = 0 ;
unsigned long V_120 = 0 ;
unsigned long V_121 = 0 ;
F_28 () ;
while ( ! F_105 ( V_105 ) ) {
struct V_58 * V_59 ;
struct V_53 * V_53 ;
int V_122 ;
enum V_91 V_123 = V_100 ;
bool V_101 , V_102 ;
F_28 () ;
V_53 = F_106 ( V_105 ) ;
F_19 ( & V_53 -> V_16 ) ;
if ( ! F_107 ( V_53 ) )
goto V_124;
F_87 ( F_108 ( V_53 ) , V_53 ) ;
F_87 ( F_109 ( V_53 ) != V_7 , V_53 ) ;
V_2 -> V_31 ++ ;
if ( F_69 ( ! F_90 ( V_53 ) ) )
goto V_125;
if ( ! V_2 -> V_126 && F_110 ( V_53 ) )
goto V_127;
if ( F_110 ( V_53 ) || F_72 ( V_53 ) )
V_2 -> V_31 ++ ;
V_122 = ( V_2 -> V_49 & V_128 ) ||
( F_72 ( V_53 ) && ( V_2 -> V_49 & V_129 ) ) ;
F_102 ( V_53 , & V_101 , & V_102 ) ;
if ( V_101 || V_102 )
V_117 ++ ;
if ( V_101 && ! V_102 )
V_116 ++ ;
V_59 = F_49 ( V_53 ) ;
if ( ( ( V_101 || V_102 ) && V_59 &&
F_45 ( V_59 -> V_66 ) ) ||
( V_102 && F_111 ( V_53 ) ) )
V_118 ++ ;
if ( F_59 ( V_53 ) ) {
if ( F_112 () &&
F_111 ( V_53 ) &&
F_113 ( V_130 , & V_7 -> V_22 ) ) {
V_121 ++ ;
goto V_127;
} else if ( F_2 ( V_2 ) ||
! F_111 ( V_53 ) || ! V_122 ) {
F_57 ( V_53 ) ;
V_120 ++ ;
goto V_127;
} else {
F_51 ( V_53 ) ;
F_114 ( V_53 ) ;
F_16 ( & V_53 -> V_16 , V_105 ) ;
continue;
}
}
if ( ! V_112 )
V_123 = F_97 ( V_53 , V_2 ) ;
switch ( V_123 ) {
case V_97 :
goto V_131;
case V_99 :
goto V_127;
case V_96 :
case V_100 :
;
}
if ( F_115 ( V_53 ) && ! F_72 ( V_53 ) ) {
if ( ! ( V_2 -> V_49 & V_129 ) )
goto V_127;
if ( ! F_116 ( V_53 , V_105 ) )
goto V_131;
V_122 = 1 ;
V_59 = F_49 ( V_53 ) ;
}
if ( F_110 ( V_53 ) && V_59 ) {
switch ( F_117 ( V_53 ,
V_106 | V_132 ) ) {
case V_133 :
goto V_131;
case V_134 :
goto V_127;
case V_135 :
goto V_125;
case V_136 :
;
}
}
if ( F_70 ( V_53 ) ) {
if ( F_80 ( V_53 ) &&
( ! F_112 () ||
! F_113 ( V_137 , & V_7 -> V_22 ) ) ) {
F_62 ( V_53 , V_138 ) ;
F_57 ( V_53 ) ;
goto V_127;
}
if ( V_123 == V_100 )
goto V_127;
if ( ! V_122 )
goto V_127;
if ( ! V_2 -> V_139 )
goto V_127;
F_118 () ;
switch ( F_52 ( V_53 , V_59 , V_2 ) ) {
case V_60 :
goto V_127;
case V_65 :
goto V_131;
case V_79 :
if ( F_59 ( V_53 ) )
goto V_124;
if ( F_70 ( V_53 ) )
goto V_124;
if ( ! F_107 ( V_53 ) )
goto V_124;
if ( F_70 ( V_53 ) || F_59 ( V_53 ) )
goto V_127;
V_59 = F_49 ( V_53 ) ;
case V_62 :
;
}
}
if ( F_43 ( V_53 ) ) {
if ( ! F_119 ( V_53 , V_2 -> V_49 ) )
goto V_131;
if ( ! V_59 && F_42 ( V_53 ) == 1 ) {
F_51 ( V_53 ) ;
if ( F_120 ( V_53 ) )
goto V_140;
else {
V_119 ++ ;
continue;
}
}
}
if ( ! V_59 || ! F_63 ( V_59 , V_53 , true ) )
goto V_127;
F_121 ( V_53 ) ;
V_140:
V_119 ++ ;
F_122 ( & V_53 -> V_16 , & V_114 ) ;
continue;
V_125:
if ( F_72 ( V_53 ) )
F_123 ( V_53 ) ;
F_51 ( V_53 ) ;
F_122 ( & V_53 -> V_16 , & V_113 ) ;
continue;
V_131:
if ( F_72 ( V_53 ) && F_124 () )
F_123 ( V_53 ) ;
F_87 ( F_108 ( V_53 ) , V_53 ) ;
F_125 ( V_53 ) ;
V_115 ++ ;
V_127:
F_51 ( V_53 ) ;
V_124:
F_122 ( & V_53 -> V_16 , & V_113 ) ;
F_87 ( F_88 ( V_53 ) || F_86 ( V_53 ) , V_53 ) ;
}
F_126 ( & V_114 ) ;
F_127 () ;
F_128 ( & V_114 , true ) ;
F_129 ( & V_113 , V_105 ) ;
F_27 ( V_141 , V_115 ) ;
* V_107 += V_117 ;
* V_109 += V_118 ;
* V_108 += V_116 ;
* V_110 += V_120 ;
* V_111 += V_121 ;
return V_119 ;
}
unsigned long F_130 ( struct V_7 * V_7 ,
struct V_104 * V_105 )
{
struct V_1 V_2 = {
. V_49 = V_24 ,
. V_142 = V_143 ,
. V_126 = 1 ,
} ;
unsigned long V_45 , V_144 , V_145 , V_146 , V_147 , V_148 ;
struct V_53 * V_53 , * V_149 ;
F_104 ( V_150 ) ;
F_131 (page, next, page_list, lru) {
if ( F_80 ( V_53 ) && ! F_70 ( V_53 ) &&
! F_132 ( V_53 ) ) {
F_133 ( V_53 ) ;
F_134 ( & V_53 -> V_16 , & V_150 ) ;
}
}
V_45 = F_103 ( & V_150 , V_7 , & V_2 ,
V_151 | V_152 ,
& V_144 , & V_145 , & V_146 , & V_147 , & V_148 , true ) ;
F_129 ( & V_150 , V_105 ) ;
F_135 ( V_7 , V_153 , - V_45 ) ;
return V_45 ;
}
int F_136 ( struct V_53 * V_53 , T_5 V_154 )
{
int V_45 = - V_155 ;
if ( ! F_88 ( V_53 ) )
return V_45 ;
if ( F_86 ( V_53 ) && ! ( V_154 & V_156 ) )
return V_45 ;
V_45 = - V_157 ;
if ( V_154 & ( V_158 | V_159 ) ) {
if ( F_59 ( V_53 ) )
return V_45 ;
if ( F_70 ( V_53 ) ) {
struct V_58 * V_59 ;
if ( V_154 & V_158 )
return V_45 ;
V_59 = F_49 ( V_53 ) ;
if ( V_59 && ! V_59 -> V_63 -> V_160 )
return V_45 ;
}
}
if ( ( V_154 & V_161 ) && F_110 ( V_53 ) )
return V_45 ;
if ( F_137 ( F_138 ( V_53 ) ) ) {
F_139 ( V_53 ) ;
V_45 = 0 ;
}
return V_45 ;
}
static unsigned long F_140 ( unsigned long V_46 ,
struct V_14 * V_14 , struct V_104 * V_162 ,
unsigned long * V_31 , struct V_1 * V_2 ,
T_5 V_154 , enum V_15 V_16 )
{
struct V_104 * V_163 = & V_14 -> V_164 [ V_16 ] ;
unsigned long V_165 = 0 ;
unsigned long V_166 ;
for ( V_166 = 0 ; V_166 < V_46 && V_165 < V_46 &&
! F_105 ( V_163 ) ; V_166 ++ ) {
struct V_53 * V_53 ;
int V_167 ;
V_53 = F_106 ( V_163 ) ;
F_141 ( V_53 , V_163 , V_22 ) ;
F_87 ( ! F_88 ( V_53 ) , V_53 ) ;
switch ( F_136 ( V_53 , V_154 ) ) {
case 0 :
V_167 = F_142 ( V_53 ) ;
F_143 ( V_14 , V_16 , - V_167 ) ;
F_134 ( & V_53 -> V_16 , V_162 ) ;
V_165 += V_167 ;
break;
case - V_157 :
F_134 ( & V_53 -> V_16 , V_163 ) ;
continue;
default:
F_144 () ;
}
}
* V_31 = V_166 ;
F_145 ( V_2 -> V_168 , V_46 , V_166 ,
V_165 , V_154 , F_146 ( V_16 ) ) ;
return V_165 ;
}
int F_94 ( struct V_53 * V_53 )
{
int V_45 = - V_157 ;
F_87 ( ! F_42 ( V_53 ) , V_53 ) ;
if ( F_88 ( V_53 ) ) {
struct V_7 * V_7 = F_109 ( V_53 ) ;
struct V_14 * V_14 ;
F_147 ( & V_7 -> V_169 ) ;
V_14 = F_148 ( V_53 , V_7 ) ;
if ( F_88 ( V_53 ) ) {
int V_16 = F_149 ( V_53 ) ;
F_150 ( V_53 ) ;
F_139 ( V_53 ) ;
F_151 ( V_53 , V_14 , V_16 ) ;
V_45 = 0 ;
}
F_152 ( & V_7 -> V_169 ) ;
}
return V_45 ;
}
static int F_153 ( struct V_7 * V_7 , int V_170 ,
struct V_1 * V_2 )
{
unsigned long V_171 , V_172 ;
if ( F_112 () )
return 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( V_170 ) {
V_171 = F_6 ( V_7 , V_10 ) ;
V_172 = F_6 ( V_7 , V_153 ) ;
} else {
V_171 = F_6 ( V_7 , V_12 ) ;
V_172 = F_6 ( V_7 , V_173 ) ;
}
if ( ( V_2 -> V_49 & ( V_129 | V_128 ) ) == ( V_129 | V_128 ) )
V_171 >>= 3 ;
return V_172 > V_171 ;
}
static T_6 void
F_154 ( struct V_14 * V_14 , struct V_104 * V_105 )
{
struct V_174 * V_175 = & V_14 -> V_175 ;
struct V_7 * V_7 = F_12 ( V_14 ) ;
F_104 ( V_176 ) ;
while ( ! F_105 ( V_105 ) ) {
struct V_53 * V_53 = F_106 ( V_105 ) ;
int V_16 ;
F_87 ( F_88 ( V_53 ) , V_53 ) ;
F_19 ( & V_53 -> V_16 ) ;
if ( F_69 ( ! F_90 ( V_53 ) ) ) {
F_152 ( & V_7 -> V_169 ) ;
F_85 ( V_53 ) ;
F_147 ( & V_7 -> V_169 ) ;
continue;
}
V_14 = F_148 ( V_53 , V_7 ) ;
F_155 ( V_53 ) ;
V_16 = F_149 ( V_53 ) ;
F_156 ( V_53 , V_14 , V_16 ) ;
if ( F_157 ( V_16 ) ) {
int V_170 = F_146 ( V_16 ) ;
int V_177 = F_142 ( V_53 ) ;
V_175 -> V_178 [ V_170 ] += V_177 ;
}
if ( F_120 ( V_53 ) ) {
F_158 ( V_53 ) ;
F_159 ( V_53 ) ;
F_151 ( V_53 , V_14 , V_16 ) ;
if ( F_69 ( F_160 ( V_53 ) ) ) {
F_152 ( & V_7 -> V_169 ) ;
F_161 ( V_53 ) ;
( * F_162 ( V_53 ) ) ( V_53 ) ;
F_147 ( & V_7 -> V_169 ) ;
} else
F_122 ( & V_53 -> V_16 , & V_176 ) ;
}
}
F_129 ( & V_176 , V_105 ) ;
}
static int F_163 ( void )
{
return ! ( V_55 -> V_22 & V_179 ) ||
V_55 -> V_57 == NULL ||
F_164 ( V_55 -> V_57 ) ;
}
static T_6 unsigned long
F_165 ( unsigned long V_46 , struct V_14 * V_14 ,
struct V_1 * V_2 , enum V_15 V_16 )
{
F_104 ( V_105 ) ;
unsigned long V_31 ;
unsigned long V_119 = 0 ;
unsigned long V_165 ;
unsigned long V_117 = 0 ;
unsigned long V_118 = 0 ;
unsigned long V_116 = 0 ;
unsigned long V_120 = 0 ;
unsigned long V_121 = 0 ;
T_5 V_180 = 0 ;
int V_170 = F_146 ( V_16 ) ;
struct V_7 * V_7 = F_12 ( V_14 ) ;
struct V_174 * V_175 = & V_14 -> V_175 ;
while ( F_69 ( F_153 ( V_7 , V_170 , V_2 ) ) ) {
F_166 ( V_181 , V_182 / 10 ) ;
if ( F_167 ( V_55 ) )
return V_50 ;
}
F_168 () ;
if ( ! V_2 -> V_126 )
V_180 |= V_161 ;
if ( ! V_2 -> V_139 )
V_180 |= V_158 ;
F_147 ( & V_7 -> V_169 ) ;
V_165 = F_140 ( V_46 , V_14 , & V_105 ,
& V_31 , V_2 , V_180 , V_16 ) ;
F_169 ( V_7 , V_17 + V_16 , - V_165 ) ;
F_169 ( V_7 , V_173 + V_170 , V_165 ) ;
if ( F_1 ( V_2 ) ) {
F_169 ( V_7 , V_13 , V_31 ) ;
if ( F_112 () )
F_170 ( V_183 , V_7 , V_31 ) ;
else
F_170 ( V_184 , V_7 , V_31 ) ;
}
F_152 ( & V_7 -> V_169 ) ;
if ( V_165 == 0 )
return 0 ;
V_119 = F_103 ( & V_105 , V_7 , V_2 , V_151 ,
& V_117 , & V_116 , & V_118 ,
& V_120 , & V_121 ,
false ) ;
F_147 ( & V_7 -> V_169 ) ;
V_175 -> V_185 [ V_170 ] += V_165 ;
if ( F_1 ( V_2 ) ) {
if ( F_112 () )
F_170 ( V_186 , V_7 ,
V_119 ) ;
else
F_170 ( V_187 , V_7 ,
V_119 ) ;
}
F_154 ( V_14 , & V_105 ) ;
F_169 ( V_7 , V_173 + V_170 , - V_165 ) ;
F_152 ( & V_7 -> V_169 ) ;
F_126 ( & V_105 ) ;
F_128 ( & V_105 , true ) ;
if ( V_120 && V_120 == V_165 )
F_171 ( V_130 , & V_7 -> V_22 ) ;
if ( F_2 ( V_2 ) ) {
if ( V_117 && V_117 == V_118 )
F_171 ( V_188 , & V_7 -> V_22 ) ;
if ( V_116 == V_165 )
F_171 ( V_137 , & V_7 -> V_22 ) ;
if ( V_121 && F_163 () )
F_166 ( V_181 , V_182 / 10 ) ;
}
if ( ! V_2 -> V_189 && ! F_112 () &&
F_163 () )
F_172 ( V_7 , V_181 , V_182 / 10 ) ;
F_173 ( V_7 -> V_190 -> V_191 ,
F_174 ( V_7 ) ,
V_31 , V_119 ,
V_2 -> V_142 ,
F_175 ( V_170 ) ) ;
return V_119 ;
}
static void F_176 ( struct V_14 * V_14 ,
struct V_104 * V_27 ,
struct V_104 * V_176 ,
enum V_15 V_16 )
{
struct V_7 * V_7 = F_12 ( V_14 ) ;
unsigned long V_192 = 0 ;
struct V_53 * V_53 ;
int V_167 ;
while ( ! F_105 ( V_27 ) ) {
V_53 = F_106 ( V_27 ) ;
V_14 = F_148 ( V_53 , V_7 ) ;
F_87 ( F_88 ( V_53 ) , V_53 ) ;
F_155 ( V_53 ) ;
V_167 = F_142 ( V_53 ) ;
F_143 ( V_14 , V_16 , V_167 ) ;
F_134 ( & V_53 -> V_16 , & V_14 -> V_164 [ V_16 ] ) ;
V_192 += V_167 ;
if ( F_120 ( V_53 ) ) {
F_158 ( V_53 ) ;
F_159 ( V_53 ) ;
F_151 ( V_53 , V_14 , V_16 ) ;
if ( F_69 ( F_160 ( V_53 ) ) ) {
F_152 ( & V_7 -> V_169 ) ;
F_161 ( V_53 ) ;
( * F_162 ( V_53 ) ) ( V_53 ) ;
F_147 ( & V_7 -> V_169 ) ;
} else
F_122 ( & V_53 -> V_16 , V_176 ) ;
}
}
F_169 ( V_7 , V_17 + V_16 , V_192 ) ;
if ( ! F_157 ( V_16 ) )
F_177 ( V_193 , V_192 ) ;
}
static void F_178 ( unsigned long V_46 ,
struct V_14 * V_14 ,
struct V_1 * V_2 ,
enum V_15 V_16 )
{
unsigned long V_165 ;
unsigned long V_31 ;
unsigned long V_94 ;
F_104 ( V_194 ) ;
F_104 ( V_195 ) ;
F_104 ( V_196 ) ;
struct V_53 * V_53 ;
struct V_174 * V_175 = & V_14 -> V_175 ;
unsigned long V_197 = 0 ;
T_5 V_180 = 0 ;
int V_170 = F_146 ( V_16 ) ;
struct V_7 * V_7 = F_12 ( V_14 ) ;
F_168 () ;
if ( ! V_2 -> V_126 )
V_180 |= V_161 ;
if ( ! V_2 -> V_139 )
V_180 |= V_158 ;
F_147 ( & V_7 -> V_169 ) ;
V_165 = F_140 ( V_46 , V_14 , & V_194 ,
& V_31 , V_2 , V_180 , V_16 ) ;
if ( F_1 ( V_2 ) )
F_169 ( V_7 , V_13 , V_31 ) ;
V_175 -> V_185 [ V_170 ] += V_165 ;
F_170 ( V_198 , V_7 , V_31 ) ;
F_169 ( V_7 , V_17 + V_16 , - V_165 ) ;
F_169 ( V_7 , V_173 + V_170 , V_165 ) ;
F_152 ( & V_7 -> V_169 ) ;
while ( ! F_105 ( & V_194 ) ) {
F_28 () ;
V_53 = F_106 ( & V_194 ) ;
F_19 ( & V_53 -> V_16 ) ;
if ( F_69 ( ! F_90 ( V_53 ) ) ) {
F_85 ( V_53 ) ;
continue;
}
if ( F_69 ( V_199 ) ) {
if ( F_43 ( V_53 ) && F_107 ( V_53 ) ) {
if ( F_43 ( V_53 ) )
F_119 ( V_53 , 0 ) ;
F_51 ( V_53 ) ;
}
}
if ( F_98 ( V_53 , 0 , V_2 -> V_3 ,
& V_94 ) ) {
V_197 += F_142 ( V_53 ) ;
if ( ( V_94 & V_98 ) && F_80 ( V_53 ) ) {
F_122 ( & V_53 -> V_16 , & V_195 ) ;
continue;
}
}
F_133 ( V_53 ) ;
F_122 ( & V_53 -> V_16 , & V_196 ) ;
}
F_147 ( & V_7 -> V_169 ) ;
V_175 -> V_178 [ V_170 ] += V_197 ;
F_176 ( V_14 , & V_195 , & V_194 , V_16 ) ;
F_176 ( V_14 , & V_196 , & V_194 , V_16 - V_200 ) ;
F_169 ( V_7 , V_173 + V_170 , - V_165 ) ;
F_152 ( & V_7 -> V_169 ) ;
F_126 ( & V_194 ) ;
F_128 ( & V_194 , true ) ;
}
static bool F_179 ( struct V_7 * V_7 )
{
unsigned long V_201 , V_171 ;
V_201 = F_6 ( V_7 , V_11 ) ;
V_171 = F_6 ( V_7 , V_12 ) ;
return V_171 * V_7 -> V_202 < V_201 ;
}
static bool F_180 ( struct V_14 * V_14 )
{
if ( ! V_203 )
return false ;
if ( ! F_10 () )
return F_181 ( V_14 ) ;
return F_179 ( F_12 ( V_14 ) ) ;
}
static inline bool F_180 ( struct V_14 * V_14 )
{
return false ;
}
static bool F_182 ( struct V_14 * V_14 )
{
unsigned long V_171 ;
unsigned long V_201 ;
V_171 = F_9 ( V_14 , V_204 ) ;
V_201 = F_9 ( V_14 , V_205 ) ;
return V_201 > V_171 ;
}
static bool F_183 ( struct V_14 * V_14 , enum V_15 V_16 )
{
if ( F_146 ( V_16 ) )
return F_182 ( V_14 ) ;
else
return F_180 ( V_14 ) ;
}
static unsigned long F_184 ( enum V_15 V_16 , unsigned long V_46 ,
struct V_14 * V_14 , struct V_1 * V_2 )
{
if ( F_157 ( V_16 ) ) {
if ( F_183 ( V_14 , V_16 ) )
F_178 ( V_46 , V_14 , V_2 , V_16 ) ;
return 0 ;
}
return F_165 ( V_46 , V_14 , V_2 , V_16 ) ;
}
static void F_185 ( struct V_14 * V_14 , int V_206 ,
struct V_1 * V_2 , unsigned long * V_8 ,
unsigned long * V_207 )
{
struct V_174 * V_175 = & V_14 -> V_175 ;
T_7 V_208 [ 2 ] ;
T_7 V_209 = 0 ;
struct V_7 * V_7 = F_12 ( V_14 ) ;
unsigned long V_210 , V_211 ;
enum V_212 V_212 ;
unsigned long V_213 , V_170 ;
bool V_214 = false ;
unsigned long V_215 , V_216 ;
enum V_15 V_16 ;
bool V_217 ;
int V_218 ;
if ( F_112 () ) {
if ( ! F_8 ( V_7 ) )
V_214 = true ;
if ( ! F_186 ( V_14 ) )
V_214 = true ;
}
if ( ! F_1 ( V_2 ) )
V_214 = true ;
if ( ! V_2 -> V_219 || ( F_7 () <= 0 ) ) {
V_212 = V_220 ;
goto V_51;
}
if ( ! F_1 ( V_2 ) && ! V_206 ) {
V_212 = V_220 ;
goto V_51;
}
if ( ! V_2 -> V_142 && V_206 ) {
V_212 = V_221 ;
goto V_51;
}
if ( F_1 ( V_2 ) ) {
unsigned long V_222 ;
unsigned long V_223 ;
V_223 = F_6 ( V_7 , V_224 ) ;
V_222 = F_6 ( V_7 , V_9 ) +
F_6 ( V_7 , V_10 ) ;
if ( F_69 ( V_222 + V_223 <= F_187 ( V_7 ) ) ) {
V_212 = V_225 ;
goto V_51;
}
}
if ( ! F_182 ( V_14 ) ) {
V_212 = V_220 ;
goto V_51;
}
V_212 = V_226 ;
V_210 = V_206 ;
V_211 = 200 - V_210 ;
V_213 = F_9 ( V_14 , V_227 ) +
F_9 ( V_14 , V_228 ) ;
V_170 = F_9 ( V_14 , V_205 ) +
F_9 ( V_14 , V_204 ) ;
F_147 ( & V_7 -> V_169 ) ;
if ( F_69 ( V_175 -> V_185 [ 0 ] > V_213 / 4 ) ) {
V_175 -> V_185 [ 0 ] /= 2 ;
V_175 -> V_178 [ 0 ] /= 2 ;
}
if ( F_69 ( V_175 -> V_185 [ 1 ] > V_170 / 4 ) ) {
V_175 -> V_185 [ 1 ] /= 2 ;
V_175 -> V_178 [ 1 ] /= 2 ;
}
V_215 = V_210 * ( V_175 -> V_185 [ 0 ] + 1 ) ;
V_215 /= V_175 -> V_178 [ 0 ] + 1 ;
V_216 = V_211 * ( V_175 -> V_185 [ 1 ] + 1 ) ;
V_216 /= V_175 -> V_178 [ 1 ] + 1 ;
F_152 ( & V_7 -> V_169 ) ;
V_208 [ 0 ] = V_215 ;
V_208 [ 1 ] = V_216 ;
V_209 = V_215 + V_216 + 1 ;
V_51:
V_217 = false ;
for ( V_218 = 0 ; ! V_217 && V_218 < 2 ; V_218 ++ ) {
* V_207 = 0 ;
F_188 (lru) {
int V_170 = F_146 ( V_16 ) ;
unsigned long V_19 ;
unsigned long V_166 ;
V_19 = F_9 ( V_14 , V_16 ) ;
V_166 = V_19 >> V_2 -> V_142 ;
if ( ! V_166 && V_218 && V_214 )
V_166 = F_25 ( V_19 , V_50 ) ;
switch ( V_212 ) {
case V_221 :
break;
case V_226 :
V_166 = F_189 ( V_166 * V_208 [ V_170 ] ,
V_209 ) ;
break;
case V_220 :
case V_225 :
if ( ( V_212 == V_220 ) != V_170 ) {
V_19 = 0 ;
V_166 = 0 ;
}
break;
default:
F_144 () ;
}
* V_207 += V_19 ;
V_8 [ V_16 ] = V_166 ;
V_217 |= ! ! V_166 ;
}
}
}
static void F_190 ( void )
{
V_55 -> V_229 . V_230 = false ;
}
static inline void F_190 ( void )
{
}
static void F_191 ( struct V_14 * V_14 , int V_206 ,
struct V_1 * V_2 , unsigned long * V_207 )
{
unsigned long V_8 [ V_231 ] ;
unsigned long V_232 [ V_231 ] ;
unsigned long V_46 ;
enum V_15 V_16 ;
unsigned long V_119 = 0 ;
unsigned long V_233 = V_2 -> V_233 ;
struct V_234 V_235 ;
bool V_236 ;
F_185 ( V_14 , V_206 , V_2 , V_8 , V_207 ) ;
memcpy ( V_232 , V_8 , sizeof( V_8 ) ) ;
V_236 = ( F_1 ( V_2 ) && ! F_112 () &&
V_2 -> V_142 == V_143 ) ;
F_190 () ;
F_192 ( & V_235 ) ;
while ( V_8 [ V_228 ] || V_8 [ V_205 ] ||
V_8 [ V_204 ] ) {
unsigned long V_237 , V_238 , V_239 ;
unsigned long V_31 ;
F_188 (lru) {
if ( V_8 [ V_16 ] ) {
V_46 = F_25 ( V_8 [ V_16 ] , V_50 ) ;
V_8 [ V_16 ] -= V_46 ;
V_119 += F_184 ( V_16 , V_46 ,
V_14 , V_2 ) ;
}
}
if ( V_119 < V_233 || V_236 )
continue;
V_238 = V_8 [ V_204 ] + V_8 [ V_205 ] ;
V_237 = V_8 [ V_228 ] + V_8 [ V_227 ] ;
if ( ! V_238 || ! V_237 )
break;
if ( V_238 > V_237 ) {
unsigned long V_240 = V_232 [ V_228 ] +
V_232 [ V_227 ] + 1 ;
V_16 = V_241 ;
V_239 = V_237 * 100 / V_240 ;
} else {
unsigned long V_240 = V_232 [ V_204 ] +
V_232 [ V_205 ] + 1 ;
V_16 = V_242 ;
V_239 = V_238 * 100 / V_240 ;
}
V_8 [ V_16 ] = 0 ;
V_8 [ V_16 + V_200 ] = 0 ;
V_16 = ( V_16 == V_242 ) ? V_241 : V_242 ;
V_31 = V_232 [ V_16 ] - V_8 [ V_16 ] ;
V_8 [ V_16 ] = V_232 [ V_16 ] * ( 100 - V_239 ) / 100 ;
V_8 [ V_16 ] -= F_25 ( V_8 [ V_16 ] , V_31 ) ;
V_16 += V_200 ;
V_31 = V_232 [ V_16 ] - V_8 [ V_16 ] ;
V_8 [ V_16 ] = V_232 [ V_16 ] * ( 100 - V_239 ) / 100 ;
V_8 [ V_16 ] -= F_25 ( V_8 [ V_16 ] , V_31 ) ;
V_236 = true ;
}
F_193 ( & V_235 ) ;
V_2 -> V_119 += V_119 ;
if ( F_180 ( V_14 ) )
F_178 ( V_50 , V_14 ,
V_2 , V_227 ) ;
F_194 ( V_2 -> V_49 ) ;
}
static bool F_195 ( struct V_1 * V_2 )
{
if ( F_196 ( V_243 ) && V_2 -> V_168 &&
( V_2 -> V_168 > V_244 ||
V_2 -> V_142 < V_143 - 2 ) )
return true ;
return false ;
}
static inline bool F_197 ( struct V_7 * V_7 ,
unsigned long V_119 ,
unsigned long V_31 ,
struct V_1 * V_2 )
{
unsigned long V_245 ;
unsigned long V_246 ;
if ( ! F_195 ( V_2 ) )
return false ;
if ( V_2 -> V_49 & V_247 ) {
if ( ! V_119 && ! V_31 )
return false ;
} else {
if ( ! V_119 )
return false ;
}
V_245 = ( 2UL << V_2 -> V_168 ) ;
V_246 = F_6 ( V_7 , V_10 ) ;
if ( F_7 () > 0 )
V_246 += F_6 ( V_7 , V_12 ) ;
if ( V_2 -> V_119 < V_245 &&
V_246 > V_245 )
return true ;
switch ( F_198 ( V_7 , V_2 -> V_168 , 0 , 0 ) ) {
case V_248 :
case V_249 :
return false ;
default:
return true ;
}
}
static bool F_199 ( struct V_7 * V_7 , struct V_1 * V_2 ,
bool V_250 )
{
struct V_251 * V_251 = V_55 -> V_251 ;
unsigned long V_119 , V_31 ;
bool V_252 = false ;
do {
struct V_4 * V_253 = V_2 -> V_3 ;
struct V_254 V_255 = {
. V_7 = V_7 ,
. V_142 = V_2 -> V_142 ,
} ;
unsigned long V_256 = 0 ;
struct V_4 * V_5 ;
V_119 = V_2 -> V_119 ;
V_31 = V_2 -> V_31 ;
V_5 = F_38 ( V_253 , NULL , & V_255 ) ;
do {
unsigned long V_207 ;
unsigned long V_257 ;
struct V_14 * V_14 ;
int V_206 ;
if ( F_200 ( V_253 , V_5 ) ) {
if ( ! V_2 -> V_258 )
continue;
F_201 ( V_5 , V_259 , 1 ) ;
}
V_14 = F_202 ( V_7 , V_5 ) ;
V_206 = F_203 ( V_5 ) ;
V_257 = V_2 -> V_31 ;
F_191 ( V_14 , V_206 , V_2 , & V_207 ) ;
V_256 += V_207 ;
if ( V_5 && V_250 )
F_32 ( V_2 -> V_49 , F_204 ( V_7 ) ,
V_5 , V_2 -> V_31 - V_257 ,
V_207 ) ;
if ( ! F_1 ( V_2 ) &&
V_2 -> V_119 >= V_2 -> V_233 ) {
F_205 ( V_253 , V_5 ) ;
break;
}
} while ( ( V_5 = F_38 ( V_253 , V_5 , & V_255 ) ) );
if ( F_1 ( V_2 ) && V_250 )
F_32 ( V_2 -> V_49 , F_204 ( V_7 ) , NULL ,
V_2 -> V_31 - V_31 ,
V_256 ) ;
if ( V_251 ) {
V_2 -> V_119 += V_251 -> V_260 ;
V_251 -> V_260 = 0 ;
}
F_206 ( V_2 -> V_49 , V_2 -> V_3 ,
V_2 -> V_31 - V_31 ,
V_2 -> V_119 - V_119 ) ;
if ( V_2 -> V_119 - V_119 )
V_252 = true ;
} while ( F_197 ( V_7 , V_2 -> V_119 - V_119 ,
V_2 -> V_31 - V_31 , V_2 ) );
return V_252 ;
}
static inline bool F_207 ( struct V_7 * V_7 , int V_168 )
{
unsigned long V_261 , V_262 ;
bool V_263 ;
V_261 = F_25 ( F_208 ( V_7 ) , F_209 (
V_7 -> V_264 , V_265 ) ) ;
V_262 = F_187 ( V_7 ) + V_261 + ( 2UL << V_168 ) ;
V_263 = F_210 ( V_7 , 0 , V_262 , 0 ) ;
if ( F_211 ( V_7 , V_168 ) )
return V_263 ;
if ( F_198 ( V_7 , V_168 , 0 , 0 ) == V_266 )
return false ;
return V_263 ;
}
static bool F_212 ( struct V_267 * V_267 , struct V_1 * V_2 )
{
struct V_268 * V_269 ;
struct V_7 * V_7 ;
unsigned long V_270 ;
unsigned long V_271 ;
T_2 V_272 ;
enum V_273 V_274 = F_213 ( V_2 -> V_49 ) ;
bool V_252 = false ;
V_272 = V_2 -> V_49 ;
if ( V_199 )
V_2 -> V_49 |= V_275 ;
F_214 (zone, z, zonelist,
requested_highidx, sc->nodemask) {
enum V_273 V_276 ;
if ( ! F_215 ( V_7 ) )
continue;
V_276 = V_274 ;
while ( ! F_215 ( V_7 -> V_190 -> V_277 +
V_276 ) )
V_276 -- ;
if ( F_1 ( V_2 ) ) {
if ( ! F_216 ( V_7 ,
V_24 | V_278 ) )
continue;
if ( V_2 -> V_142 != V_143 &&
! F_8 ( V_7 ) )
continue;
if ( F_196 ( V_243 ) &&
V_2 -> V_168 > V_244 &&
F_217 ( V_269 ) <= V_274 &&
F_207 ( V_7 , V_2 -> V_168 ) ) {
V_2 -> F_207 = true ;
continue;
}
V_271 = 0 ;
V_270 = F_218 ( V_7 ,
V_2 -> V_168 , V_2 -> V_49 ,
& V_271 ) ;
V_2 -> V_119 += V_270 ;
V_2 -> V_31 += V_271 ;
if ( V_270 )
V_252 = true ;
}
if ( F_199 ( V_7 , V_2 , F_174 ( V_7 ) == V_276 ) )
V_252 = true ;
if ( F_1 ( V_2 ) &&
! V_252 && F_8 ( V_7 ) )
V_252 = true ;
}
V_2 -> V_49 = V_272 ;
return V_252 ;
}
static unsigned long F_219 ( struct V_267 * V_267 ,
struct V_1 * V_2 )
{
int V_279 = V_2 -> V_142 ;
unsigned long V_280 = 0 ;
unsigned long V_281 ;
bool V_282 ;
V_283:
F_220 () ;
if ( F_1 ( V_2 ) )
F_96 ( V_284 ) ;
do {
F_221 ( V_2 -> V_49 , V_2 -> V_3 ,
V_2 -> V_142 ) ;
V_2 -> V_31 = 0 ;
V_282 = F_212 ( V_267 , V_2 ) ;
V_280 += V_2 -> V_31 ;
if ( V_2 -> V_119 >= V_2 -> V_233 )
break;
if ( V_2 -> F_207 )
break;
if ( V_2 -> V_142 < V_143 - 2 )
V_2 -> V_139 = 1 ;
V_281 = V_2 -> V_233 + V_2 -> V_233 / 2 ;
if ( V_280 > V_281 ) {
F_222 ( V_285 ? 0 : V_280 ,
V_286 ) ;
V_2 -> V_139 = 1 ;
}
} while ( -- V_2 -> V_142 >= 0 );
F_223 () ;
if ( V_2 -> V_119 )
return V_2 -> V_119 ;
if ( V_2 -> F_207 )
return 1 ;
if ( ! V_2 -> V_258 ) {
V_2 -> V_142 = V_279 ;
V_2 -> V_258 = 1 ;
goto V_283;
}
if ( V_282 )
return 1 ;
return 0 ;
}
static bool F_224 ( T_8 * V_287 )
{
struct V_7 * V_7 ;
unsigned long V_288 = 0 ;
unsigned long V_114 = 0 ;
int V_289 ;
bool V_290 ;
for ( V_289 = 0 ; V_289 <= V_291 ; V_289 ++ ) {
V_7 = & V_287 -> V_277 [ V_289 ] ;
if ( ! F_215 ( V_7 ) ||
F_5 ( V_7 ) == 0 )
continue;
V_288 += F_225 ( V_7 ) ;
V_114 += F_6 ( V_7 , V_224 ) ;
}
if ( ! V_288 )
return true ;
V_290 = V_114 > V_288 / 2 ;
if ( ! V_290 && F_226 ( & V_287 -> V_292 ) ) {
V_287 -> V_276 = F_25 ( V_287 -> V_276 ,
(enum V_273 ) V_291 ) ;
F_227 ( & V_287 -> V_292 ) ;
}
return V_290 ;
}
static bool F_228 ( T_2 V_49 , struct V_267 * V_267 ,
T_9 * V_293 )
{
struct V_268 * V_269 ;
struct V_7 * V_7 ;
T_8 * V_287 = NULL ;
if ( V_55 -> V_22 & V_294 )
goto V_51;
if ( F_167 ( V_55 ) )
goto V_51;
F_214 (zone, z, zonelist,
gfp_zone(gfp_mask), nodemask) {
if ( F_174 ( V_7 ) > V_291 )
continue;
V_287 = V_7 -> V_190 ;
if ( F_224 ( V_287 ) )
goto V_51;
break;
}
if ( ! V_287 )
goto V_51;
F_96 ( V_295 ) ;
if ( ! ( V_49 & V_128 ) ) {
F_229 ( V_287 -> V_296 ,
F_224 ( V_287 ) , V_182 ) ;
goto V_297;
}
F_230 ( V_7 -> V_190 -> V_296 ,
F_224 ( V_287 ) ) ;
V_297:
if ( F_167 ( V_55 ) )
return true ;
V_51:
return false ;
}
unsigned long F_231 ( struct V_267 * V_267 , int V_168 ,
T_2 V_49 , T_9 * V_293 )
{
unsigned long V_119 ;
struct V_1 V_2 = {
. V_233 = V_50 ,
. V_49 = ( V_49 = F_232 ( V_49 ) ) ,
. V_168 = V_168 ,
. V_293 = V_293 ,
. V_142 = V_143 ,
. V_139 = ! V_285 ,
. V_126 = 1 ,
. V_219 = 1 ,
} ;
if ( F_228 ( V_49 , V_267 , V_293 ) )
return 1 ;
F_233 ( V_168 ,
V_2 . V_139 ,
V_49 ) ;
V_119 = F_219 ( V_267 , & V_2 ) ;
F_234 ( V_119 ) ;
return V_119 ;
}
unsigned long F_235 ( struct V_4 * V_5 ,
T_2 V_49 , bool V_298 ,
struct V_7 * V_7 ,
unsigned long * V_31 )
{
struct V_1 V_2 = {
. V_233 = V_50 ,
. V_3 = V_5 ,
. V_139 = ! V_285 ,
. V_126 = 1 ,
. V_219 = ! V_298 ,
} ;
struct V_14 * V_14 = F_202 ( V_7 , V_5 ) ;
int V_206 = F_203 ( V_5 ) ;
unsigned long V_207 ;
V_2 . V_49 = ( V_49 & V_299 ) |
( V_300 & ~ V_299 ) ;
F_236 ( V_2 . V_168 ,
V_2 . V_139 ,
V_2 . V_49 ) ;
F_191 ( V_14 , V_206 , & V_2 , & V_207 ) ;
F_237 ( V_2 . V_119 ) ;
* V_31 = V_2 . V_31 ;
return V_2 . V_119 ;
}
unsigned long F_238 ( struct V_4 * V_5 ,
unsigned long V_167 ,
T_2 V_49 ,
bool V_219 )
{
struct V_267 * V_267 ;
unsigned long V_119 ;
int V_38 ;
struct V_1 V_2 = {
. V_233 = F_239 ( V_167 , V_50 ) ,
. V_49 = ( V_49 & V_299 ) |
( V_300 & ~ V_299 ) ,
. V_3 = V_5 ,
. V_142 = V_143 ,
. V_139 = ! V_285 ,
. V_126 = 1 ,
. V_219 = V_219 ,
} ;
V_38 = F_240 ( V_5 ) ;
V_267 = F_241 ( V_38 ) -> V_301 ;
F_242 ( 0 ,
V_2 . V_139 ,
V_2 . V_49 ) ;
V_119 = F_219 ( V_267 , & V_2 ) ;
F_243 ( V_119 ) ;
return V_119 ;
}
static void F_244 ( struct V_7 * V_7 , struct V_1 * V_2 )
{
struct V_4 * V_5 ;
if ( ! V_203 )
return;
V_5 = F_38 ( NULL , NULL , NULL ) ;
do {
struct V_14 * V_14 = F_202 ( V_7 , V_5 ) ;
if ( F_180 ( V_14 ) )
F_178 ( V_50 , V_14 ,
V_2 , V_227 ) ;
V_5 = F_38 ( NULL , V_5 , NULL ) ;
} while ( V_5 );
}
static bool F_245 ( struct V_7 * V_7 , int V_168 ,
unsigned long V_261 , int V_276 )
{
if ( ! F_210 ( V_7 , V_168 , F_187 ( V_7 ) +
V_261 , V_276 ) )
return false ;
if ( F_196 ( V_243 ) && V_168 && F_198 ( V_7 ,
V_168 , 0 , V_276 ) == V_266 )
return false ;
return true ;
}
static bool F_246 ( T_8 * V_287 , int V_168 , int V_276 )
{
unsigned long V_264 = 0 ;
unsigned long V_302 = 0 ;
int V_289 ;
for ( V_289 = 0 ; V_289 <= V_276 ; V_289 ++ ) {
struct V_7 * V_7 = V_287 -> V_277 + V_289 ;
if ( ! F_215 ( V_7 ) )
continue;
V_264 += V_7 -> V_264 ;
if ( ! F_8 ( V_7 ) ) {
V_302 += V_7 -> V_264 ;
continue;
}
if ( F_245 ( V_7 , V_168 , 0 , V_289 ) )
V_302 += V_7 -> V_264 ;
else if ( ! V_168 )
return false ;
}
if ( V_168 )
return V_302 >= ( V_264 >> 2 ) ;
else
return true ;
}
static bool F_247 ( T_8 * V_287 , int V_168 , long V_303 ,
int V_276 )
{
if ( V_303 )
return false ;
if ( F_226 ( & V_287 -> V_296 ) )
F_248 ( & V_287 -> V_296 ) ;
return F_246 ( V_287 , V_168 , V_276 ) ;
}
static bool F_249 ( struct V_7 * V_7 ,
int V_276 ,
struct V_1 * V_2 ,
unsigned long * V_304 )
{
int V_305 = V_2 -> V_168 ;
unsigned long V_261 ;
bool V_306 ;
V_2 -> V_233 = F_239 ( V_50 , F_187 ( V_7 ) ) ;
if ( F_196 ( V_243 ) && V_2 -> V_168 &&
F_198 ( V_7 , V_2 -> V_168 , 0 , V_276 )
!= V_266 )
V_305 = 0 ;
V_261 = F_25 ( F_208 ( V_7 ) , F_209 (
V_7 -> V_264 , V_265 ) ) ;
V_306 = ( V_199 && F_250 ( V_7 ) ) ;
if ( ! V_306 && F_245 ( V_7 , V_305 ,
V_261 , V_276 ) )
return true ;
F_199 ( V_7 , V_2 , F_174 ( V_7 ) == V_276 ) ;
* V_304 += V_2 -> V_233 ;
F_251 ( V_130 , & V_7 -> V_22 ) ;
if ( F_8 ( V_7 ) &&
F_245 ( V_7 , V_305 , 0 , V_276 ) ) {
F_251 ( V_188 , & V_7 -> V_22 ) ;
F_251 ( V_137 , & V_7 -> V_22 ) ;
}
return V_2 -> V_31 >= V_2 -> V_233 ;
}
static unsigned long F_252 ( T_8 * V_287 , int V_168 ,
int * V_276 )
{
int V_289 ;
int V_307 = 0 ;
unsigned long V_270 ;
unsigned long V_271 ;
struct V_1 V_2 = {
. V_49 = V_24 ,
. V_168 = V_168 ,
. V_142 = V_143 ,
. V_139 = ! V_285 ,
. V_126 = 1 ,
. V_219 = 1 ,
} ;
F_96 ( V_308 ) ;
do {
unsigned long V_304 = 0 ;
bool V_309 = true ;
bool V_310 = ( V_168 > 0 ) ;
V_2 . V_119 = 0 ;
for ( V_289 = V_287 -> V_311 - 1 ; V_289 >= 0 ; V_289 -- ) {
struct V_7 * V_7 = V_287 -> V_277 + V_289 ;
if ( ! F_215 ( V_7 ) )
continue;
if ( V_2 . V_142 != V_143 &&
! F_8 ( V_7 ) )
continue;
F_244 ( V_7 , & V_2 ) ;
if ( V_199 && F_253 ( V_289 ) ) {
V_307 = V_289 ;
break;
}
if ( ! F_245 ( V_7 , V_168 , 0 , 0 ) ) {
V_307 = V_289 ;
break;
} else {
F_251 ( V_188 , & V_7 -> V_22 ) ;
F_251 ( V_137 , & V_7 -> V_22 ) ;
}
}
if ( V_289 < 0 )
goto V_51;
for ( V_289 = 0 ; V_289 <= V_307 ; V_289 ++ ) {
struct V_7 * V_7 = V_287 -> V_277 + V_289 ;
if ( ! F_215 ( V_7 ) )
continue;
if ( V_310 &&
F_254 ( V_7 , V_168 ,
F_208 ( V_7 ) ,
* V_276 , 0 ) )
V_310 = false ;
}
if ( V_2 . V_142 < V_143 - 2 )
V_2 . V_139 = 1 ;
for ( V_289 = 0 ; V_289 <= V_307 ; V_289 ++ ) {
struct V_7 * V_7 = V_287 -> V_277 + V_289 ;
if ( ! F_215 ( V_7 ) )
continue;
if ( V_2 . V_142 != V_143 &&
! F_8 ( V_7 ) )
continue;
V_2 . V_31 = 0 ;
V_271 = 0 ;
V_270 = F_218 ( V_7 ,
V_168 , V_2 . V_49 ,
& V_271 ) ;
V_2 . V_119 += V_270 ;
if ( F_249 ( V_7 , V_307 ,
& V_2 , & V_304 ) )
V_309 = false ;
}
if ( F_226 ( & V_287 -> V_296 ) &&
F_224 ( V_287 ) )
F_248 ( & V_287 -> V_296 ) ;
if ( V_168 && V_2 . V_119 >= 2UL << V_168 )
V_168 = V_2 . V_168 = 0 ;
if ( F_255 () || F_256 () )
break;
if ( V_310 && V_2 . V_119 > V_304 )
F_257 ( V_287 , V_168 ) ;
if ( V_309 || ! V_2 . V_119 )
V_2 . V_142 -- ;
} while ( V_2 . V_142 >= 1 &&
! F_246 ( V_287 , V_168 , * V_276 ) );
V_51:
* V_276 = V_307 ;
return V_168 ;
}
static void F_258 ( T_8 * V_287 , int V_168 , int V_276 )
{
long V_303 = 0 ;
F_259 ( V_312 ) ;
if ( F_260 ( V_55 ) || F_256 () )
return;
F_261 ( & V_287 -> V_292 , & V_312 , V_313 ) ;
if ( F_247 ( V_287 , V_168 , V_303 , V_276 ) ) {
V_303 = F_262 ( V_182 / 10 ) ;
F_263 ( & V_287 -> V_292 , & V_312 ) ;
F_261 ( & V_287 -> V_292 , & V_312 , V_313 ) ;
}
if ( F_247 ( V_287 , V_168 , V_303 , V_276 ) ) {
F_264 ( V_287 -> V_191 ) ;
F_265 ( V_287 , V_314 ) ;
F_266 ( V_287 ) ;
if ( ! F_256 () )
F_267 () ;
F_265 ( V_287 , V_315 ) ;
} else {
if ( V_303 )
F_96 ( V_316 ) ;
else
F_96 ( V_317 ) ;
}
F_263 ( & V_287 -> V_292 , & V_312 ) ;
}
static int F_268 ( void * V_318 )
{
unsigned long V_168 , V_319 ;
unsigned V_320 ;
int V_276 , V_321 ;
int V_322 ;
T_8 * V_287 = ( T_8 * ) V_318 ;
struct V_323 * V_324 = V_55 ;
struct V_251 V_251 = {
. V_260 = 0 ,
} ;
const struct V_325 * V_325 = F_269 ( V_287 -> V_191 ) ;
F_270 ( V_24 ) ;
if ( ! F_271 ( V_325 ) )
F_272 ( V_324 , V_325 ) ;
V_55 -> V_251 = & V_251 ;
V_324 -> V_22 |= V_326 | V_56 | V_327 ;
F_273 () ;
V_168 = V_319 = 0 ;
V_320 = 0 ;
V_276 = V_321 = V_287 -> V_311 - 1 ;
V_322 = V_276 ;
for ( ; ; ) {
bool V_45 ;
if ( V_322 >= V_321 &&
V_320 == V_319 ) {
V_319 = V_287 -> V_328 ;
V_321 = V_287 -> V_276 ;
V_287 -> V_328 = 0 ;
V_287 -> V_276 = V_287 -> V_311 - 1 ;
}
if ( V_168 < V_319 || V_276 > V_321 ) {
V_168 = V_319 ;
V_276 = V_321 ;
} else {
F_258 ( V_287 , V_320 ,
V_322 ) ;
V_168 = V_287 -> V_328 ;
V_276 = V_287 -> V_276 ;
V_319 = V_168 ;
V_321 = V_276 ;
V_287 -> V_328 = 0 ;
V_287 -> V_276 = V_287 -> V_311 - 1 ;
}
V_45 = F_255 () ;
if ( F_256 () )
break;
if ( ! V_45 ) {
F_274 ( V_287 -> V_191 , V_168 ) ;
V_322 = V_276 ;
V_320 = F_252 ( V_287 , V_168 ,
& V_322 ) ;
}
}
V_324 -> V_22 &= ~ ( V_326 | V_56 | V_327 ) ;
V_55 -> V_251 = NULL ;
F_275 () ;
return 0 ;
}
void F_276 ( struct V_7 * V_7 , int V_168 , enum V_273 V_276 )
{
T_8 * V_287 ;
if ( ! F_215 ( V_7 ) )
return;
if ( ! F_216 ( V_7 , V_24 | V_278 ) )
return;
V_287 = V_7 -> V_190 ;
if ( V_287 -> V_328 < V_168 ) {
V_287 -> V_328 = V_168 ;
V_287 -> V_276 = F_25 ( V_287 -> V_276 , V_276 ) ;
}
if ( ! F_226 ( & V_287 -> V_292 ) )
return;
if ( F_245 ( V_7 , V_168 , 0 , 0 ) )
return;
F_277 ( V_287 -> V_191 , F_174 ( V_7 ) , V_168 ) ;
F_227 ( & V_287 -> V_292 ) ;
}
unsigned long F_278 ( unsigned long V_233 )
{
struct V_251 V_251 ;
struct V_1 V_2 = {
. V_233 = V_233 ,
. V_49 = V_300 ,
. V_142 = V_143 ,
. V_139 = 1 ,
. V_126 = 1 ,
. V_219 = 1 ,
. V_189 = 1 ,
} ;
struct V_267 * V_267 = F_279 ( F_280 () , V_2 . V_49 ) ;
struct V_323 * V_318 = V_55 ;
unsigned long V_119 ;
V_318 -> V_22 |= V_326 ;
F_270 ( V_2 . V_49 ) ;
V_251 . V_260 = 0 ;
V_318 -> V_251 = & V_251 ;
V_119 = F_219 ( V_267 , & V_2 ) ;
V_318 -> V_251 = NULL ;
F_275 () ;
V_318 -> V_22 &= ~ V_326 ;
return V_119 ;
}
static int F_281 ( struct V_329 * V_330 , unsigned long V_331 ,
void * V_332 )
{
int V_38 ;
if ( V_331 == V_333 || V_331 == V_334 ) {
F_282 (nid, N_MEMORY) {
T_8 * V_287 = F_241 ( V_38 ) ;
const struct V_325 * V_335 ;
V_335 = F_269 ( V_287 -> V_191 ) ;
if ( F_283 ( V_336 , V_335 ) < V_337 )
F_272 ( V_287 -> F_268 , V_335 ) ;
}
}
return V_338 ;
}
int F_284 ( int V_38 )
{
T_8 * V_287 = F_241 ( V_38 ) ;
int V_45 = 0 ;
if ( V_287 -> F_268 )
return 0 ;
V_287 -> F_268 = F_285 ( F_268 , V_287 , L_3 , V_38 ) ;
if ( F_286 ( V_287 -> F_268 ) ) {
F_64 ( V_339 == V_340 ) ;
F_24 ( L_4 , V_38 ) ;
V_45 = F_287 ( V_287 -> F_268 ) ;
V_287 -> F_268 = NULL ;
}
return V_45 ;
}
void F_288 ( int V_38 )
{
struct V_323 * F_268 = F_241 ( V_38 ) -> F_268 ;
if ( F_268 ) {
F_289 ( F_268 ) ;
F_241 ( V_38 ) -> F_268 = NULL ;
}
}
static int T_10 F_290 ( void )
{
int V_38 ;
F_291 () ;
F_282 (nid, N_MEMORY)
F_284 ( V_38 ) ;
F_292 ( F_281 , 0 ) ;
return 0 ;
}
static inline unsigned long F_293 ( struct V_7 * V_7 )
{
unsigned long V_341 = F_6 ( V_7 , V_342 ) ;
unsigned long V_343 = F_6 ( V_7 , V_10 ) +
F_6 ( V_7 , V_9 ) ;
return ( V_343 > V_341 ) ? ( V_343 - V_341 ) : 0 ;
}
static unsigned long F_294 ( struct V_7 * V_7 )
{
unsigned long V_344 ;
unsigned long V_34 = 0 ;
if ( V_345 & V_346 )
V_344 = F_6 ( V_7 , V_347 ) ;
else
V_344 = F_293 ( V_7 ) ;
if ( ! ( V_345 & V_348 ) )
V_34 += F_6 ( V_7 , V_349 ) ;
if ( F_69 ( V_34 > V_344 ) )
V_34 = V_344 ;
return V_344 - V_34 ;
}
static int F_295 ( struct V_7 * V_7 , T_2 V_49 , unsigned int V_168 )
{
const unsigned long V_167 = 1 << V_168 ;
struct V_323 * V_318 = V_55 ;
struct V_251 V_251 ;
struct V_1 V_2 = {
. V_233 = F_239 ( V_167 , V_50 ) ,
. V_49 = ( V_49 = F_232 ( V_49 ) ) ,
. V_168 = V_168 ,
. V_142 = V_350 ,
. V_139 = ! ! ( V_345 & V_348 ) ,
. V_126 = ! ! ( V_345 & V_346 ) ,
. V_219 = 1 ,
} ;
F_28 () ;
V_318 -> V_22 |= V_326 | V_56 ;
F_270 ( V_49 ) ;
V_251 . V_260 = 0 ;
V_318 -> V_251 = & V_251 ;
if ( F_294 ( V_7 ) > V_7 -> V_351 ) {
do {
F_199 ( V_7 , & V_2 , true ) ;
} while ( V_2 . V_119 < V_167 && -- V_2 . V_142 >= 0 );
}
V_318 -> V_251 = NULL ;
V_55 -> V_22 &= ~ ( V_326 | V_56 ) ;
F_275 () ;
return V_2 . V_119 >= V_167 ;
}
int F_296 ( struct V_7 * V_7 , T_2 V_49 , unsigned int V_168 )
{
int V_191 ;
int V_45 ;
if ( F_294 ( V_7 ) <= V_7 -> V_351 &&
F_6 ( V_7 , V_352 ) <= V_7 -> V_353 )
return V_354 ;
if ( ! F_8 ( V_7 ) )
return V_354 ;
if ( ! F_297 ( V_49 ) || ( V_55 -> V_22 & V_326 ) )
return V_355 ;
V_191 = F_204 ( V_7 ) ;
if ( F_298 ( V_191 , V_356 ) && V_191 != F_280 () )
return V_355 ;
if ( F_299 ( V_357 , & V_7 -> V_22 ) )
return V_355 ;
V_45 = F_295 ( V_7 , V_49 , V_168 ) ;
F_251 ( V_357 , & V_7 -> V_22 ) ;
if ( ! V_45 )
F_96 ( V_358 ) ;
return V_45 ;
}
int F_90 ( struct V_53 * V_53 )
{
return ! F_300 ( F_49 ( V_53 ) ) && ! F_301 ( V_53 ) ;
}
void F_302 ( struct V_53 * * V_359 , int V_167 )
{
struct V_14 * V_14 ;
struct V_7 * V_7 = NULL ;
int V_360 = 0 ;
int V_361 = 0 ;
int V_289 ;
for ( V_289 = 0 ; V_289 < V_167 ; V_289 ++ ) {
struct V_53 * V_53 = V_359 [ V_289 ] ;
struct V_7 * V_362 ;
V_360 ++ ;
V_362 = F_109 ( V_53 ) ;
if ( V_362 != V_7 ) {
if ( V_7 )
F_152 ( & V_7 -> V_169 ) ;
V_7 = V_362 ;
F_147 ( & V_7 -> V_169 ) ;
}
V_14 = F_148 ( V_53 , V_7 ) ;
if ( ! F_88 ( V_53 ) || ! F_86 ( V_53 ) )
continue;
if ( F_90 ( V_53 ) ) {
enum V_15 V_16 = F_303 ( V_53 ) ;
F_87 ( F_108 ( V_53 ) , V_53 ) ;
F_89 ( V_53 ) ;
F_151 ( V_53 , V_14 , V_363 ) ;
F_156 ( V_53 , V_14 , V_16 ) ;
V_361 ++ ;
}
}
if ( V_7 ) {
F_177 ( V_89 , V_361 ) ;
F_177 ( V_364 , V_360 ) ;
F_152 ( & V_7 -> V_169 ) ;
}
}
